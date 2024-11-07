#include "patches.h"
#include "sf64audio_provisional.h"
#include "audioseq_cmd.h"
#include "audiothread_cmd.h"
#include "sound.h"

extern ActiveSequence sActiveSequences[4];

void Audio_SetSequenceFade(u8 seqPlayId, u8 fadeModId, u8 fadeMod, u8 fadeTime);
s32 Audio_SeqCmdValueNotQueued(s32 cmdVal, s32 cmdMask);
void Audio_ProcessSeqCmd(u32 seqCmd);

bool is_bgm_player(u8 player_index) {
    return player_index == SEQ_PLAYER_BGM || player_index == SEQ_PLAYER_SFX;
}

RECOMP_PATCH void Audio_UpdateActiveSequences(void) {
    u8 seqPlayId;
    u8 i;
    u8 tempoTimer;
    u8 channelId;
    u16 tempoTarget;
    u16 prevTempo;
    u16 seqId;
    u8 tempoOp;
    u8 setupSeqPlayId;
    u8 val1;
    u8 setupOp;
    u8 val2;
    u8 temp2;
    s32 temp;
    u32 cmd;
    f32 fadeMod;
    u32 out;
    s32 pad1;
    s32 pad2;

    for (seqPlayId = 0; seqPlayId < SEQ_PLAYER_MAX; seqPlayId++) {
        if (sActiveSequences[seqPlayId].isWaitingForFonts) {
            switch ((s32) AudioThread_GetAsyncLoadStatus(&out)) {
                case SEQ_PLAYER_BGM + 1:
                case SEQ_PLAYER_FANFARE + 1:
                case SEQ_PLAYER_SFX + 1:
                case SEQ_PLAYER_VOICE + 1:
                    sActiveSequences[seqPlayId].isWaitingForFonts = false;
                    Audio_ProcessSeqCmd(sActiveSequences[seqPlayId].startSeqCmd);
                    break;
            }
        }
        if (sActiveSequences[seqPlayId].mainVolume.fadeActive) {
            fadeMod = 1.0f;
            for (i = 0; i < 3; i++) {
                fadeMod *= sActiveSequences[seqPlayId].mainVolume.fadeMod[i] / 127.0f;
            }
            SEQCMD_SET_SEQPLAYER_VOLUME(seqPlayId, sActiveSequences[seqPlayId].mainVolume.fadeTimer,
                                        (u8) (fadeMod * 127.0f));
            sActiveSequences[seqPlayId].mainVolume.fadeActive = false;
        }
        if (sActiveSequences[seqPlayId].mainVolume.timer != 0) {
            sActiveSequences[seqPlayId].mainVolume.timer--;
            if (sActiveSequences[seqPlayId].mainVolume.timer != 0) {
                sActiveSequences[seqPlayId].mainVolume.mod -= sActiveSequences[seqPlayId].mainVolume.step;
            } else {
                sActiveSequences[seqPlayId].mainVolume.mod = sActiveSequences[seqPlayId].mainVolume.target;
            }
        }

        // @recomp Send a volume scale command regardless of whether volTimer is active and scale it for background music players.
        f32 cur_volume = sActiveSequences[seqPlayId].mainVolume.mod;
        if (is_bgm_player(seqPlayId)) {
            cur_volume *= recomp_get_bgm_volume();
        }
        AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE((u32) seqPlayId, cur_volume);

        if (sActiveSequences[seqPlayId].tempoCmd != 0) {
            cmd = sActiveSequences[seqPlayId].tempoCmd;
            temp = cmd & 0xFFF;
            temp2 = (cmd & 0xFF0000) >> 0xF;
            tempoTimer = temp2;
            tempoTarget = temp;

            if (temp2 == 0) {
                tempoTimer = temp2 + 1;
            }
            if (gSeqPlayers[seqPlayId].enabled) {
                prevTempo = gSeqPlayers[seqPlayId].tempo / 48;
                tempoOp = ((cmd & 0xF000) >> 0xC);

                switch (tempoOp) {
                    case SEQCMD_SUB_OP_TEMPO_SPEED_UP:
                        tempoTarget = tempoTarget + prevTempo;
                        break;
                    case SEQCMD_SUB_OP_TEMPO_SLOW_DOWN:
                        if (tempoTarget < prevTempo) {
                            tempoTarget = prevTempo - tempoTarget;
                        }
                        break;
                    case SEQCMD_SUB_OP_TEMPO_SCALE:
                        tempoTarget = prevTempo * (tempoTarget / 100.0f);
                        break;
                    case SEQCMD_SUB_OP_TEMPO_RESET:
                        if (sActiveSequences[seqPlayId].tempoOriginal != 0) {
                            tempoTarget = sActiveSequences[seqPlayId].tempoOriginal;
                        } else {
                            tempoTarget = prevTempo;
                        }
                        break;
                }
                if (tempoTarget > 300) {
                    tempoTarget = 300;
                }
                if (!sActiveSequences[seqPlayId].tempoOriginal) {
                    sActiveSequences[seqPlayId].tempoOriginal = prevTempo;
                }
                sActiveSequences[seqPlayId].tempo.target = tempoTarget;
                sActiveSequences[seqPlayId].tempo.value = (s32) gSeqPlayers[seqPlayId].tempo / 48;

                sActiveSequences[seqPlayId].tempo.step =
                    (sActiveSequences[seqPlayId].tempo.value - sActiveSequences[seqPlayId].tempo.target) / tempoTimer;
                sActiveSequences[seqPlayId].tempo.timer = tempoTimer;
                sActiveSequences[seqPlayId].tempoCmd = 0;
            }
        }
        if (sActiveSequences[seqPlayId].tempo.timer != 0) {
            sActiveSequences[seqPlayId].tempo.timer--;
            if (sActiveSequences[seqPlayId].tempo.timer != 0) {
                sActiveSequences[seqPlayId].tempo.value -= sActiveSequences[seqPlayId].tempo.step;
            } else {
                sActiveSequences[seqPlayId].tempo.value = sActiveSequences[seqPlayId].tempo.target;
            }
            AUDIOCMD_SEQPLAYER_SET_TEMPO((u32) seqPlayId, (s32) sActiveSequences[seqPlayId].tempo.value);
        }
        if (sActiveSequences[seqPlayId].volChannelFlags != 0) {
            for (channelId = 0; channelId < 16; channelId++) {
                if (sActiveSequences[seqPlayId].channelMod[channelId].volume.timer != 0) {
                    sActiveSequences[seqPlayId].channelMod[channelId].volume.timer--;
                    if (sActiveSequences[seqPlayId].channelMod[channelId].volume.timer) {
                        sActiveSequences[seqPlayId].channelMod[channelId].volume.value -=
                            sActiveSequences[seqPlayId].channelMod[channelId].volume.step;
                    } else {
                        sActiveSequences[seqPlayId].channelMod[channelId].volume.value =
                            sActiveSequences[seqPlayId].channelMod[channelId].volume.target;
                        sActiveSequences[seqPlayId].volChannelFlags ^= 1 << channelId;
                    }
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE((u32) seqPlayId, (u32) channelId,
                                                   sActiveSequences[seqPlayId].channelMod[channelId].volume.value);
                }
            }
        }
        if (sActiveSequences[seqPlayId].freqModChannelFlags != 0) {
            for (channelId = 0; channelId < 16; channelId++) {
                if (sActiveSequences[seqPlayId].channelMod[channelId].freq.timer != 0) {
                    sActiveSequences[seqPlayId].channelMod[channelId].freq.timer--;
                    if (sActiveSequences[seqPlayId].channelMod[channelId].freq.timer != 0) {
                        sActiveSequences[seqPlayId].channelMod[channelId].freq.value -=
                            sActiveSequences[seqPlayId].channelMod[channelId].freq.step;
                    } else {
                        sActiveSequences[seqPlayId].channelMod[channelId].freq.value =
                            sActiveSequences[seqPlayId].channelMod[channelId].freq.target;
                        sActiveSequences[seqPlayId].freqModChannelFlags ^= 1 << channelId;
                    }
                    AUDIOCMD_CHANNEL_SET_FREQ_SCALE((u32) seqPlayId, (u32) channelId,
                                                    sActiveSequences[seqPlayId].channelMod[channelId].freq.value);
                }
            }
        }
        if (sActiveSequences[seqPlayId].setupCmdNum == 0) {
            continue;
        }
        if (!Audio_SeqCmdValueNotQueued(SEQCMD_OP_RESET_AUDIO_HEAP << 28, SEQCMD_OP_MASK)) {
            sActiveSequences[seqPlayId].setupCmdNum = 0;
            break;
        }
        if (sActiveSequences[seqPlayId].setupCmdTimer != 0) {
            sActiveSequences[seqPlayId].setupCmdTimer--;
        } else if (!gSeqPlayers[seqPlayId].enabled) {
            for (i = 0; i < sActiveSequences[seqPlayId].setupCmdNum; i++) {
                setupOp = (sActiveSequences[seqPlayId].setupCmd[i] & 0xF00000) >> 20;

                setupSeqPlayId = (sActiveSequences[seqPlayId].setupCmd[i] & 0xF0000) >> 16;
                val2 = (sActiveSequences[seqPlayId].setupCmd[i] & 0xFF00) >> 8;
                val1 = sActiveSequences[seqPlayId].setupCmd[i] & 0xFF;
                switch (setupOp) {
                    case SEQCMD_SUB_OP_SETUP_RESTORE_SEQPLAYER_VOLUME:
                        Audio_SetSequenceFade(setupSeqPlayId, 1, 127, val2);
                        break;
                    case SEQCMD_SUB_OP_SETUP_SEQ_UNQUEUE:
                        SEQCMD_UNQUEUE_SEQUENCE(seqPlayId, 0, sActiveSequences[seqPlayId].seqId);
                        break;
                    case SEQCMD_SUB_OP_SETUP_RESTART_SEQ:
                        SEQCMD_PLAY_SEQUENCE(setupSeqPlayId, 1, 0, sActiveSequences[setupSeqPlayId].seqId);
                        sActiveSequences[setupSeqPlayId].mainVolume.fadeActive = true;
                        sActiveSequences[setupSeqPlayId].mainVolume.fadeMod[1] = 127;
                        break;
                    case SEQCMD_SUB_OP_SETUP_TEMPO_SCALE:
                        SEQCMD_SCALE_TEMPO(setupSeqPlayId, val2, val1);
                        break;
                    case SEQCMD_SUB_OP_SETUP_TEMPO_RESET:
                        SEQCMD_RESET_TEMPO(setupSeqPlayId, val1);
                        break;
                    case SEQCMD_SUB_OP_SETUP_PLAY_SEQ:
                        seqId = sActiveSequences[seqPlayId].setupCmd[i] & 0xFFFF;
                        SEQCMD_PLAY_SEQUENCE(setupSeqPlayId, sActiveSequences[setupSeqPlayId].setupFadeTimer, 0, seqId);
                        Audio_SetSequenceFade(setupSeqPlayId, 1, 127, 0);
                        sActiveSequences[setupSeqPlayId].setupFadeTimer = 0;
                        break;
                    case SEQCMD_SUB_OP_SETUP_SET_FADE_TIMER:
                        sActiveSequences[seqPlayId].setupFadeTimer = val2;
                        break;
                }
            }
            sActiveSequences[seqPlayId].setupCmdNum = 0;
        }
    }
}