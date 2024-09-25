#include "patches.h"

extern s32 D_i4_801A0530;
extern s32 D_BO_801A03DC;

void Bolse_8018BD60(ActorEvent* this);
void Bolse_SpawnEnemies(ActorEvent* this, s32 count);

// @recomp: Fix Pigma's voice line being cut out
RECOMP_PATCH void Bolse_UpdateEventHandler(ActorEvent* this) {
    s32 i;
    Player* player = &gPlayer[0];
    s32 pad;
    Actor* actor;

    gBolseDynamicGround = true;
    D_i4_801A0530++;

    switch (this->state) {
        case 0:
            gAllRangeSpawnEvent = 500000;
            gAllRangeEventTimer = 0;
            gStarWolfMsgTimer = 0;
            this->state = 2;

            if (gAllRangeCheckpoint == 0) {
                gBosses[0].fwork[1] = 0.3f;
                D_BO_801A03DC = 6;
            } else {
                gAllRangeCheckpoint = 1;
                gHitCount = gSavedHitCount;
                gBosses[1].state = 2;
                gAllRangeEventTimer = 3000;
                this->iwork[1] = gHitCount;
            }

            for (i = 0; i < 6; i++) {
                gStarWolfTeamAlive[i] = gSavedStarWolfTeamAlive[i];
            }

        case 2:
            Bolse_8018BD60(this);

            switch (gAllRangeEventTimer) {
                case 300:
                    Radio_PlayMessage(gMsg_ID_11020, RCID_PEPPY);
                    break;
                case 600:
                    Radio_PlayMessage(gMsg_ID_11030, RCID_FALCO);
                    break;
                case 900:
                    Radio_PlayMessage(gMsg_ID_11040, RCID_SLIPPY);
                    break;
                case 1500:
                    Radio_PlayMessage(gMsg_ID_11210, RCID_SLIPPY);
                    break;
                case 1800:
                    Radio_PlayMessage(gMsg_ID_11220, RCID_FALCO);
                    break;
                case 2300:
                    Radio_PlayMessage(gMsg_ID_11240, RCID_SLIPPY);
                    break;
                case 2500:
                    Radio_PlayMessage(gMsg_ID_11230, RCID_PEPPY);
                    break;
            }

            if ((D_i4_801A0530 < 9600) && ((D_i4_801A0530 & 0x400) != 0)) {
                Bolse_SpawnEnemies(this, 8);
            }

            if (gBosses[2].state == 10) {
                SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 1);
                SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 1);
                if ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE) ||
                    (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_U_TURN)) {
                    gPlayer[0].state_1C8 = PLAYERSTATE_1C8_LEVEL_COMPLETE;
                    gPlayer[0].csTimer = 30;
                    gPlayer[0].csState = 0;
                    gPlayer[0].unk_000 = 0.0f;
                }
                AllRange_ClearRadio();
                this->state = 6;
                AUDIO_PLAY_SFX(NA_SE_EN_ANDROSS_EXPLOSION, this->sfxSource, 0);
                AUDIO_PLAY_SFX(NA_SE_EN_DOWN_IMPACT, this->sfxSource, 4);
                gScreenFlashTimer = 8;

                for (actor = &gActors[10], i = 0; i < 20; i++, actor++) {
                    if (actor->obj.status == OBJ_ACTIVE) {
                        actor->obj.status = OBJ_DYING;
                        actor->timer_0BC = 30;
                    }
                }
            }

            if ((gBosses[1].state == 2) && (gBosses[1].obj.status == OBJ_ACTIVE)) {
                this->iwork[1] = gHitCount;
                this->state = 10;
                this->timer_0BC = 150;
                gPlayer[0].state_1C8 = PLAYERSTATE_1C8_STANDBY;
                AUDIO_PLAY_BGM(NA_BGM_BOSS_BO);
                AllRange_ClearRadio();
                gPlayer[0].cam.eye.x = 400.0f;
                gPlayer[0].cam.eye.y = 50.0f;
                gPlayer[0].cam.eye.z = 3000.0f;
                gPlayer[0].cam.at.x = 0.0f;
                gPlayer[0].cam.at.y = 0.0f;
                gPlayer[0].cam.at.z = 0.0f;
                for (i = 10; i < 30; i++) {
                    Object_Kill(&gActors[i].obj, gActors[i].sfxSource);
                }
            } else if ((gAllRangeCheckpoint == 1) && (((gHitCount - this->iwork[1]) >= 5) || (D_i4_801A0530 == 4000))) {
                gAllRangeCheckpoint = 2;
                this->iwork[1] = gHitCount;
                if ((gStarWolfTeamAlive[0] != 0) || (gStarWolfTeamAlive[1] != 0) || (gStarWolfTeamAlive[2] != 0) ||
                    (gStarWolfTeamAlive[3] != 0)) {
                    gAllRangeSpawnEvent = gAllRangeEventTimer + 120;
                    gStarWolfMsgTimer = 1000;
                }
            }
            break;

        case 3:
            gBolseDynamicGround = false;

            for (i = 0; i < 4; i++) {
                if (gStarWolfTeamAlive[i] != 0) {
                    actor = &gActors[i + 4];
                    break;
                }
                if (i == 3) {
                    this->state = 2;
                    player->state_1C8 = PLAYERSTATE_1C8_ACTIVE;
                    return;
                }
            }

            player->cam.eye.x += actor->vel.x * 0.23f;
            player->cam.eye.y += actor->vel.y * 0.23f;
            player->cam.eye.z += actor->vel.z * 0.23f;

            Math_SmoothStepToF(&player->cam.at.x, actor->obj.pos.x, 1.0f, 20000.0f, 0.0f);
            Math_SmoothStepToF(&player->cam.at.y, actor->obj.pos.y, 1.0f, 20000.0f, 0.0f);
            Math_SmoothStepToF(&player->cam.at.z, actor->obj.pos.z, 1.0f, 20000.0f, 0.0f);
            Math_SmoothStepToF(&player->camRoll, 0.0f, 0.1f, 0.2f, 0);

            if ((gControllerPress->button & START_BUTTON) || ((gAllRangeSpawnEvent + 300) == gAllRangeEventTimer)) {
                this->state = 2;
                player->state_1C8 = PLAYERSTATE_1C8_ACTIVE;
                Camera_Update360(player, true);
                player->unk_014 = 0.0f;
                D_hud_80161708 = 0;
            }
            gPauseEnabled = false;
            break;

        case 10:
            if (gBosses[1].obj.status != 0) {
                if (fabsf(Math_SmoothStepToF(&gBosses[1].scale, 0.0f, 1.0f, 0.05f, 0.001f)) < 0.05f) {
                    Object_Kill(&gBosses[1].obj, gBosses[i].sfxSource);
                    gLight1R = 100;
                    gLight1G = 100;
                    gLight1B = 80;
                    gAmbientR = 0;
                    gAmbientG = 15;
                    gAmbientB = 30;
                }
            }

            gBosses[0].fwork[1] = 0.0f;

            gBosses[0].obj.rot.y = gBosses[0].fwork[1];

            player->cam.eye.x -= 6.0f;
            player->cam.eye.z -= 12.0f;
            player->cam.at.y += 8.0f;

            gPlayer[0].cam.eye.y += 2.0f;

            Math_SmoothStepToF(&player->camRoll, 0.0f, 1.0f, 1000.0f, 0);

            if (this->timer_0BC == 130) {
                Radio_PlayMessage(gMsg_ID_11060, RCID_FALCO);
                gAllRangeCheckpoint = 1;
                gSavedHitCount = gHitCount;
                for (i = TEAM_ID_FALCO; i <= TEAM_ID_PEPPY; i++) {
                    gSavedTeamShields[i] = gTeamShields[i];
                }
            }

            if ((this->timer_0BC % 8) == 0) {
                Bolse_SpawnEnemies(this, 15);
            }

            if (!this->timer_0BC) {
                gAllRangeEventTimer = 3000;
                this->state = 2;
                player->state_1C8 = PLAYERSTATE_1C8_ACTIVE;
                Camera_Update360(player, true);
                player->unk_014 = 0.0f;
                Audio_KillSfxBySource(gBosses[1].sfxSource);
                this->iwork[1] = gHitCount;
            }
            break;

        case 6:
            gActors[AI360_FALCO].aiIndex = 0;
            gActors[AI360_FALCO].state = 2;
            gActors[AI360_SLIPPY].aiIndex = 0;
            gActors[AI360_SLIPPY].state = 2;
            gActors[AI360_PEPPY].aiIndex = 0;
            gActors[AI360_PEPPY].state = 2;
            gActors[AI360_WOLF].aiIndex = gActors[AI360_LEON].aiIndex = gActors[AI360_PIGMA].aiIndex =
                gActors[AI360_ANDREW].aiIndex = -1;
            break;
    }

    if (gStarWolfMsgTimer != 0) {
        gStarWolfMsgTimer--;
        switch (gStarWolfMsgTimer) {
            case 860:
                if (gStarWolfTeamAlive[0] != 0) {
                    Radio_PlayMessage(gMsg_ID_11100, RCID_WOLF);
                }
                break;

            case 760:
                if (gStarWolfTeamAlive[1] != 0) {
                    Radio_PlayMessage(gMsg_ID_11110, RCID_LEON);
                }
                break;

            case 670:
                if (gStarWolfTeamAlive[2] != 0) {
                    Radio_PlayMessage(gMsg_ID_11120, RCID_PIGMA);
                }
                break;
            // @recomp: Fix voice line being cut out
            case 540: // Original value: 550
                if (gStarWolfTeamAlive[3] != 0) {
                    Radio_PlayMessage(gMsg_ID_11130, RCID_ANDREW);
                }
                break;

            case 390:
                if (gLeveLClearStatus[LEVEL_FORTUNA] == 0) {
                    Radio_PlayMessage(gMsg_ID_9285, RCID_FOX);
                } else {
                    Radio_PlayMessage(gMsg_ID_11241, RCID_FOX);
                }
                break;
        }
    }
}