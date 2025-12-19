#include "patches.h"

extern s32 D_i4_801A0530;
extern s32 D_BO_801A03DC;
extern f32 D_i3_801C2768[14];

void Bolse_8018BD60(ActorEvent* this);
void Bolse_SpawnEnemies(ActorEvent* this, s32 count);
void Solar_801A0DF8(f32 xPos, f32 zPos, f32 yRot, s32 index, f32 yPos);
void Solar_801A7750(void);
void Audio_FadeOutAll(u8 fadeoutTime);

void* memcpy2(void* dest, const void* src, size_t n) {
    unsigned char* su1 = (unsigned char*) dest;
    const unsigned char* su2 = (const unsigned char*) src;

    while (n > 0) {
        *su1 = *su2;
        su1++;
        su2++;
        n--;
    }

    return dest;
}

// @recomp: Fix Pigma's voice line being cut out
RECOMP_PATCH void Bolse_UpdateEventHandler(ActorEvent* this) {
    s32 i = 0;
    Player* player = &gPlayer[0];
    s32 pad;
    Actor* actor = NULL;

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
                if ((gPlayer[0].state == PLAYERSTATE_ACTIVE) || (gPlayer[0].state == PLAYERSTATE_U_TURN)) {
                    gPlayer[0].state = PLAYERSTATE_LEVEL_COMPLETE;
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
                gPlayer[0].state = PLAYERSTATE_STANDBY;
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
                    player->state = PLAYERSTATE_ACTIVE;
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
                player->state = PLAYERSTATE_ACTIVE;
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
                player->state = PLAYERSTATE_ACTIVE;
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

RECOMP_PATCH void Solar_LevelComplete(Player* player) {
    s32 i;
    f32 sp78;
    f32 sp74;
    f32 dx;
    f32 dz;
    Vec3f sp60;
    Vec3f sp54;
    SoVulkain* boss = &gBosses[0];

    switch (player->csState) {
        case 0:
            gCsFrameCount = 0;
            player->camRoll = player->aerobaticPitch = 0.0f;
            player->baseSpeed = 40.0f;

            player->arwing.upperRightFlapYrot = player->arwing.upperLeftFlapYrot = player->arwing.bottomRightFlapYrot =
                player->arwing.bottomLeftFlapYrot = player->zRotBarrelRoll = player->zRotBank = player->boostSpeed =
                    0.0f;
            player->draw = true;

            gCsCamEyeX = player->cam.eye.x;
            gCsCamEyeY = player->cam.eye.y;
            gCsCamEyeZ = player->cam.eye.z;

            gCsCamAtX = player->cam.at.x;
            gCsCamAtY = player->cam.at.y;
            gCsCamAtZ = player->cam.at.z;

            for (i = 10; i < ARRAY_COUNT(gActors); i++) {
                if (gActors[i].animFrame == 0) {
                    Object_Kill(&gActors[i].obj, gActors[i].sfxSource);
                }
            }

            Object_Kill(&gActors[2].obj, gActors[2].sfxSource);
            Object_Kill(&gActors[3].obj, gActors[3].sfxSource);
            Object_Kill(&gActors[4].obj, gActors[4].sfxSource);

            player->csState = 1;

            D_ctx_80177A48[0] = 0.1f;
            if (Rand_ZeroOne() > 0.5f) {
                D_ctx_80177A48[9] = -1.0f;
            } else {
                D_ctx_80177A48[9] = 1.0f;
            }
            break;

        case 1:
            gPathTexScroll += 30.0f;

            Math_SmoothStepToF(&player->rot.x, 0.0f, 0.1f, 5.0f, 0.0f);
            Math_SmoothStepToF(&player->pos.y, 200.0f, 0.05f, 10.0f, 0.0f);

            dx = player->pos.x - boss->obj.pos.x;
            dz = (player->pos.z - boss->obj.pos.z) * 0.05f;
            sp78 = Math_RadToDeg(-Math_Atan2F(dx, dz));

            Math_SmoothStepToF(&gCsCamEyeY, 300.0f, 1.0f, 20.0f, 0.0f);
            Math_SmoothStepToF(&gCsCamAtY, 290.0f, 1.0f, 20.0f, 0.0f);

            sp74 = Math_SmoothStepToAngle(&player->rot.y, sp78, 0.5f, 2.0f, 0.0001f) * 30.0f;

            if (gCsFrameCount >= 14) {
                Math_SmoothStepToAngle(&player->rot.z, sp74, 0.1f, 5.0f, 0.0001f);
                gCsCamAtX = 0.0f;
                gCsCamEyeX = 0.0f;
            } else if (sp74 < 0.0f) {
                player->rot.z -= 30.0f;
            } else {
                player->rot.z += 30.0f;
            }

            if (gCsFrameCount >= 200) {
                player->rot.x += 1.0f;
                player->rot.y += 1.0f;
                player->rot.z += 1.0f;
            }

            if (gCsFrameCount >= 230) {
                gFillScreenAlphaTarget = 255;
                gFillScreenRed = gFillScreenBlue = gFillScreenGreen = 255;
            }

            if (gCsFrameCount == 230) {
                SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 50);
                SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 50);
            }

            if (gCsFrameCount == 400) {
                player->csState++;
                Play_ClearObjectData();
                Audio_StopPlayerNoise(0);
                Audio_KillSfxBySource(player->sfxSource);
                gFillScreenAlpha = 250;
                player->csTimer = 20;
                player->baseSpeed = 0.0f;
                player->rot.x = 0.0f;
                player->rot.y = 0.0f;
                player->rot.z = 0.0f;
            }
            break;

        case 2:
            gPathTexScroll += 60.0f;
            if (player->csTimer == 0) {
                player->pos.x = 0.0f;
                player->pos.y = 200.0f;
                player->pos.z = -(gPathProgress - 500.0f);
                player->csState++;
                player->arwing.drawFace = true;

                Audio_StartPlayerNoise(0);

                AUDIO_PLAY_BGM(NA_BGM_COURSE_CLEAR);

                gDrawGround = true;

                Play_ClearObjectData();

                D_ctx_80177A48[1] = 0.0f;
                D_ctx_80177A48[2] = 0.0f;

                player->cam.eye.x = 0.0f;
                player->cam.eye.y = player->pos.y + 80.0f;
                player->cam.eye.z = player->pos.z + gPathProgress - 4000.0f;

                gCsCamEyeZ = player->pos.z + gPathProgress - 4900.0f;

                player->cam.at.x = gCsCamAtX = 0.0f;
                player->cam.at.y = gCsCamAtY = 200.0f;
                player->cam.at.z = gCsCamAtZ = player->pos.z + gPathProgress;

                D_ctx_80177A48[0] = 0.0f;
                Object_Kill(&gActors[4].obj, gActors[4].sfxSource);
                Object_Kill(&gActors[5].obj, gActors[5].sfxSource);
            }
            break;

        case 3:
            gPathTexScroll += 60.0f;
            gFillScreenAlphaTarget = 0;
            gFillScreenAlphaStep = 4;

            if (gMsgCharIsPrinting) {
                player->arwing.teamFaceXrot = (s32) (gGameFrameCount & 2) * 2.5f;
            }

            switch (gCsFrameCount) {
                case 450:
                    Solar_801A0DF8(-1200.0f, -(gPathProgress + 2500.0f), 90.0f, 2, 1.0f);
                    break;

                case 545:
                    Solar_801A0DF8(1400.0f, -(gPathProgress + 3250.0f), -90.0f, 3, 1.0f);
                    break;

                case 550:
                    Object_Kill(&gActors[4].obj, gActors[4].sfxSource);
                    break;

                case 645:
                    Object_Kill(&gActors[5].obj, gActors[5].sfxSource);
                    break;

                case 700:
                    player->csState++;
                    Solar_801A7750();
                    D_i3_801C2768[3] = 1000.0f;
                    break;
            }

            if ((gCsFrameCount >= 520) && (gCsFrameCount < 605)) {
                Math_SmoothStepToF(&player->pos.x, 400.0f, 0.1f, 10.0f, 0.1f);
            }
            if ((gCsFrameCount >= 520) && (gCsFrameCount < 570)) {
                Math_SmoothStepToAngle(&player->rot.z, -30.0f, 0.1f, 5.0f, 0.1f);
            }
            if ((gCsFrameCount >= 570) && (gCsFrameCount < 605)) {
                Math_SmoothStepToAngle(&player->rot.z, 0.0f, 0.1f, 5.0f, 0.1f);
            }
            if ((gCsFrameCount >= 605) && (gCsFrameCount < 620)) {
                player->rot.z += 30.0f;
            }
            if ((gCsFrameCount >= 620) && (gCsFrameCount < 640)) {
                Math_SmoothStepToAngle(&player->rot.z, 45.0f, 0.1f, 5.0f, 0.0f);
            }
            if (gCsFrameCount >= 640) {
                Math_SmoothStepToAngle(&player->rot.z, 0.0f, 0.3f, 7.0f, 0.0f);
            }
            if (gCsFrameCount >= 585) {
                Math_SmoothStepToF(&player->pos.x, 0.0f, 0.2f, 9.0f, 0);
            }
            if (gCsFrameCount >= 600) {
                Math_SmoothStepToF(&player->pos.y, 950.0f, 0.1f, 10.0f, 0.0001f);
            }

            Math_SmoothStepToF(&player->pos.z, -(gPathProgress + 4350.0f), 1.0f, 20.0f, 0.0001f);

            if (gCsFrameCount >= 620) {
                Math_SmoothStepToF(&player->cam.eye.x, 0.0f, 1.0f, 10.0f, 0);
                Math_SmoothStepToF(&player->cam.eye.y, player->pos.y + 52.0f, 1.0f, 16.0f, 0.0f);
                Math_SmoothStepToF(&player->cam.eye.z, (player->pos.z + gPathProgress) - 50.0f, 1.0f, 21.5f, 0.0f);
            }
            player->cam.at.x = gCsCamAtX = player->pos.x;
            player->cam.at.y = gCsCamAtY = player->pos.y;
            player->cam.at.z = gCsCamAtZ = player->pos.z + gPathProgress;
            break;

        case 4:
            gPathTexScroll += 60.0f;

            gFillScreenAlphaTarget = 0;
            gFillScreenAlphaStep = 4;

            D_ctx_80177A48[1] += D_ctx_80177A48[2] * 0.8f;

            Matrix_RotateY(gCalcMatrix, D_ctx_80177A48[1] * M_DTOR, MTXF_NEW);

            sp60.x = 0.0f;
            sp60.y = 0.0f;
            sp60.z = -700.0f;

            Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp60, &sp54);

            if (gCsFrameCount < 1440) {
                gCsCamEyeX = sp54.x;
                gCsCamEyeY = D_i3_801C2768[3] + sp54.y;
                gCsCamEyeZ = player->pos.z + gPathProgress + sp54.z;
                gCsCamAtX = 0.0f;
                gCsCamAtY = player->pos.y + 75.0f;
                Math_SmoothStepToF(&D_i3_801C2768[3], 500.0f, 0.1f, 1.0f, 0.0001f);
                gCsCamAtZ = player->pos.z + gPathProgress + 200.0f;

                if (gCsFrameCount >= 1400) {
                    gCsCamAtZ -= (gCsFrameCount * 8) - 11200;
                }
            } else {
                Math_SmoothStepToF(&gCsCamEyeX, 0.0f, 0.1f, 1.0f, 0.0001f);
                gCsCamAtX = 0.0f;
                gCsCamAtY = player->pos.y + 75.0f;
                gCsCamAtZ = player->pos.z + gPathProgress + 200.0f - ((gCsFrameCount * 8) - 11200);
            }

            if (gCsFrameCount > 1460) {
                player->baseSpeed += 2.0f;
                player->rot.x += 0.2f;
                Math_SmoothStepToF(&D_ctx_80177A48[2], 0.0f, 1.0f, 0.001f, 0);
                player->unk_190 = 2.0f;
            } else {
                Math_SmoothStepToF(&D_ctx_80177A48[2], 0.23f, 1.0f, 0.001f, 0.0f);
                Math_SmoothStepToF(&D_ctx_80177A48[0], 0.5f, 0.1f, 0.0005f, 0.0f);
            }

            if (gCsFrameCount == 1560) {
                Play_ClearObjectData();
            }

            if (gCsFrameCount > 1530) {
                gFillScreenAlphaTarget = 255;
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 0;
                gFillScreenAlphaStep = 8;
                if (gFillScreenAlpha == 255) {
                    Audio_StopPlayerNoise(0);
                    Audio_FadeOutAll(10);
                    player->state = PLAYERSTATE_NEXT;
                    player->csTimer = 0;
                    gFadeoutType = 4;
                    gLeveLClearStatus[LEVEL_SOLAR] = Play_CheckMedalStatus(100) + 1;
                }
            }
            break;
    }

    switch (gCsFrameCount) {
        case 440:
            gLevelClearScreenTimer = 100;
            break;

        case 640:
            Radio_PlayMessage(gMsg_ID_20010, RCID_FOX);
            break;

        case 728:
            switch (gTeamShields[TEAM_ID_SLIPPY]) {
                case 0:
                    Radio_PlayMessage(gMsg_ID_20345, RCID_ROB64);
                    break;
                case -1:
                    Radio_PlayMessage(gMsg_ID_20339, RCID_ROB64);
                    break;
                default:
                    Cutscene_AllAircraftReport(TEAM_ID_SLIPPY);
                    break;
            }
            break;

        case 875:
            switch (gTeamShields[TEAM_ID_PEPPY]) {
                case 0:
                    Radio_PlayMessage(gMsg_ID_20344, RCID_ROB64);
                    break;
                case -1:
                    Radio_PlayMessage(gMsg_ID_20338, RCID_ROB64);
                    break;
                default:
                    Cutscene_AllAircraftReport(TEAM_ID_PEPPY);
                    break;
            }
            break;

        case 1021:
            switch (gTeamShields[TEAM_ID_FALCO]) {
                case 0:
                    Radio_PlayMessage(gMsg_ID_20343, RCID_ROB64);
                    break;
                case -1:
                    Radio_PlayMessage(gMsg_ID_20337, RCID_ROB64);
                    break;
                default:
                    Cutscene_AllAircraftReport(TEAM_ID_FALCO);
                    break;
            }
            break;

        case 1186:
            gShowLevelClearStatusScreen = true;
            break;

        case 1386:
            gShowLevelClearStatusScreen = false;
            break;

        case 1460:
            AUDIO_PLAY_SFX(NA_SE_ARWING_BOOST, player->sfxSource, 0);
            player->unk_190 = player->unk_194 = 5.0f;
            break;

        case 1400:
            if (gTeamShields[TEAM_ID_PEPPY] > 0) {
                gActors[0].state = 2;
            }
            break;

        case 1500:
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 50);
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 50);
            break;

        case 1420:
            if (gTeamShields[TEAM_ID_SLIPPY] > 0) {
                gActors[1].state = 2;
            }
            break;

        case 1440:
            if (gTeamShields[TEAM_ID_FALCO] > 0) {
                gActors[2].state = 2;
            }
            break;
    }
    Matrix_RotateY(gCalcMatrix, (player->yRot_114 + player->rot.y + 180.0f) * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, -((player->xRot_120 + player->rot.x) * M_DTOR), MTXF_APPLY);

    sp60.x = 0.0f;
    sp60.y = 0.0f;
    sp60.z = player->baseSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp60, &sp54);

    player->vel.x = sp54.x;
    player->vel.z = sp54.z;
    player->vel.y = sp54.y;

    player->pos.x += player->vel.x;
    player->pos.y += player->vel.y;
    player->pos.z += player->vel.z;

    player->trueZpos = player->pos.z;
    player->bankAngle = player->rot.z;

    Math_SmoothStepToF(&player->cam.eye.x, gCsCamEyeX, D_ctx_80177A48[0], 50000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.eye.y, gCsCamEyeY, D_ctx_80177A48[0], 50000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, D_ctx_80177A48[0], 50000.0f, 0.0f);

    Math_SmoothStepToF(&player->cam.at.x, gCsCamAtX, D_ctx_80177A48[0], 50000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.y, gCsCamAtY, D_ctx_80177A48[0], 50000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.z, gCsCamAtZ, D_ctx_80177A48[0], 50000.0f, 0.0f);
    player->bobPhase += 10.0f;
    player->yBob = -SIN_DEG(player->bobPhase) * 0.3f;
    player->rockPhase += 8.0f;
    player->rockAngle = SIN_DEG(player->rockPhase);
}

#if 1

ArwingInfoRecomp gActorTeamArwing_recomp = { 0 };

RECOMP_PATCH void ActorTeamArwing_Draw(ActorTeamArwing* this) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };
    Vec3f dest;

    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    if ((/* ((fabsf(dest.z) < 3000.0f) && (fabsf(dest.x) < 3000.0f) && !gBossActive)  || */
         (gPlayer[0].state == PLAYERSTATE_STANDBY) || (gCurrentLevel == LEVEL_VENOM_ANDROSS) ||
         (gCurrentLevel == LEVEL_VENOM_2) || (gPlayer[0].state == PLAYERSTATE_LEVEL_COMPLETE)) &&
        (gCurrentLevel != LEVEL_MACBETH) && (gCurrentLevel != LEVEL_TITANIA)) {
        if (this->obj.id == OBJ_ACTOR_CUTSCENE) {
            if (((gCurrentLevel == LEVEL_VENOM_2) && (gPlayer[0].state == PLAYERSTATE_LEVEL_COMPLETE) &&
                 (this->index == 10)) ||
                ((gPlayer[0].state == PLAYERSTATE_LEVEL_COMPLETE) && (gPlayer[0].csState >= 100) &&
                 (gCurrentLevel == LEVEL_KATINA) && (this->index == 1)) ||
                ((gCurrentLevel == LEVEL_SECTOR_Y) && (gPlayer[0].state == PLAYERSTATE_STANDBY) &&
                 (this->state == 5))) {
                gActorTeamArwing_recomp.rightWingState = gPlayer[0].arwing.rightWingState;
                gActorTeamArwing_recomp.leftWingState = gPlayer[0].arwing.leftWingState;
            } else {
                gActorTeamArwing_recomp.rightWingState = gActorTeamArwing_recomp.leftWingState = WINGSTATE_INTACT;
            }
        } else {
            gActorTeamArwing_recomp.rightWingState = gActorTeamArwing_recomp.leftWingState = WINGSTATE_INTACT;
        }

        gActorTeamArwing_recomp.upperRightFlapYrot = this->fwork[15];
        gActorTeamArwing_recomp.upperLeftFlapYrot = this->fwork[16];
        gActorTeamArwing_recomp.bottomRightFlapYrot = this->fwork[26];
        gActorTeamArwing_recomp.bottomLeftFlapYrot = this->fwork[27];
        gActorTeamArwing_recomp.laserGunsYpos = gActorTeamArwing_recomp.laserGunsXpos =
            gActorTeamArwing_recomp.wingsXrot = gActorTeamArwing_recomp.wingsYrot =
                gActorTeamArwing_recomp.cockpitGlassXrot = gActorTeamArwing_recomp.wingsZrot = 0.0f;
        gActorTeamArwing_recomp.unk_28 = this->fwork[17];
        gActorTeamArwing_recomp.drawFace = this->iwork[14];
        gActorTeamArwing_recomp.teamFaceXrot = this->fwork[20];
        gActorTeamArwing_recomp.teamFaceYrot = this->fwork[19];

        // @recomp: store the actor address so we can use it later for matrix tagging
        gActorTeamArwing_recomp.actorPtr = this;

        if (gLevelType == LEVELTYPE_SPACE) {
            gActorTeamArwing_recomp.upperRightFlapYrot = gActorTeamArwing_recomp.bottomRightFlapYrot =
                gActorTeamArwing_recomp.upperLeftFlapYrot = gActorTeamArwing_recomp.bottomLeftFlapYrot = 0.0f;
        }
        // @recomp: pass custom gActorTeamArwing_recomp which contains an extra member with the actor address
        // We use that address to tag different team arwings inside the Animation_DrawSkeleton and Animation_DrawLimb
        // functions.
        Display_Arwing_Skel((ArwingInfo*) &gActorTeamArwing_recomp);
    } else if (gLevelType == LEVELTYPE_PLANET) {
        gSPDisplayList(gMasterDisp++, aPlanetArwingAllRangeDL);
    } else if (gPlayer[0].wingPosition == 2) {
        gSPDisplayList(gMasterDisp++, aSpaceArwingAllRangeDL);
    } else {
        gSPDisplayList(gMasterDisp++, aSpaceArwingOnRailsDL);
    }
    Actor_DrawEngineAndContrails(this);
}
#endif

#if 0
extern f32 D_i1_80199AE4[3];
extern f32 D_i1_80199AF0[3];
extern f32 D_i1_80199AFC[3];
extern f32 D_i1_80199B08[3];
extern f32 D_i1_80199B14[3];
extern f32 D_i1_80199B20[3];
extern f32 D_i1_80199B2C[3];

RECOMP_PATCH void Corneria_CsLevelComplete1_TeamSetup(ActorCutscene* this, s32 index) {
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    Player* player = &gPlayer[0];

    Matrix_RotateY(gCalcMatrix, player->rot.y * M_DTOR, MTXF_NEW);
    sp5C.x = D_i1_80199AE4[index];
    sp5C.y = D_i1_80199AF0[index];
    sp5C.z = D_i1_80199AFC[index];

    sp44.x = D_i1_80199B08[index];
    sp44.y = D_i1_80199B14[index];
    sp44.z = D_i1_80199B20[index];

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp5C, &sp50);
    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp44, &sp38);

    Actor_Initialize(this);

    this->obj.pos.x = player->pos.x + sp50.x;
    this->obj.pos.y = player->pos.y + sp50.y;
    this->obj.pos.z = player->pos.z + sp50.z;

    this->fwork[0] = sp38.x;
    this->fwork[1] = sp38.y;
    this->fwork[2] = sp38.z;

    this->fwork[7] = RAND_FLOAT(360.0f);
    this->fwork[8] = RAND_FLOAT(360.0f);

    this->vel.x = player->vel.x;
    this->vel.y = player->vel.y;
    this->vel.z = player->vel.z;

    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;
    this->obj.rot.z = D_i1_80199B2C[index];


    Object_SetInfo(&this->info, this->obj.id);

    this->iwork[11] = 1;
    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
    this->iwork[14] = 3;
}
#endif