#include "patches.h"

void Audio_SetAudioSpec(u8 unused, u16 specParam);
void Andross_Team_Setup(s32 actorIndex);
void Andross_AndPassage_Setup(AndPassage* this, f32 xPos, f32 yPos, f32 zPos, s32 arg4);
void Andross_LoadLevelObjects(void);
void Andross_ArwingEscape_Setup(s32 actorIdx);
void Audio_FadeOutAll(u8 fadeoutTime);

RECOMP_PATCH void Andross_LevelComplete(Player* player) {
    s32 i;
    s32 sp90;
    f32 sp8C;
    Boss* boss = &gBosses[0];
    f32 sp84;
    f32 sp80;
    Vec3f sp74;
    Vec3f sp68;
    s32 rnd;

    Math_SmoothStepToF(D_ctx_80177A48, 1.0f, 1.0f, 0.01f, 0.0f);

    player->arwing.upperRightFlapYrot = player->arwing.bottomRightFlapYrot = player->arwing.upperLeftFlapYrot =
        player->arwing.bottomLeftFlapYrot = 0.0f;

    switch (player->csState) {
        case 0:
            gCsFrameCount = 0;
            player->arwing.drawFace = true;
            D_ctx_80177A48[0] = 0.0f;
            if (player->aerobaticPitch > 180.0f) {
                player->aerobaticPitch -= 360.0f;
            }
            player->csState++;
            player->csTimer = 50;
            player->vel.z = -40.0f;
            /* fallthrough */
        case 1:
            Math_SmoothStepToF(&player->zRotBank, 0.0f, 0.1f, 15.0f, 0.0f);
            Math_SmoothStepToF(&boss->vel.z, -40.0f, 1.0f, 1.0f, 0.0f);
            Math_SmoothStepToF(&player->rot.y, 0.0f, 0.1f, 10.0f, 0.0f);
            Math_SmoothStepToF(&player->vel.x, 0.0f, 1.0f, 3.0f, 0.0f);
            Math_SmoothStepToF(&player->vel.y, 0.0f, 1.0f, 3.0f, 0.0f);
            Math_SmoothStepToF(&player->cam.eye.x, player->pos.x, 0.1f, 15.0f, 0.0f);
            Math_SmoothStepToF(&player->cam.eye.y, player->pos.y + 30.0f, 0.1f, 15.0f, 0.0f);

            if (player->csTimer == 0) {
                player->pos.y += SIN_DEG(player->rot.x) * 15.0f;
                Math_SmoothStepToF(&player->rot.x, 180.0f, 0.1f, 5.0f, 0.0f);
                Math_SmoothStepToF(&player->vel.z, 40.0f, 1.0f, 2.0f, 0.0f);
            } else {
                Math_SmoothStepToF(&player->camDist, 0.0f, 1.0f, 5.0f, 0.0f);
                Math_SmoothStepToF(&player->rot.x, 0.0f, 0.1f, 10.0f, 0.0f);
            }
            player->cam.eye.z += player->vel.z * 0.5f;

            switch (gCsFrameCount) {
                case 80:
                    Effect_Effect383_Spawn(boss->obj.pos.x, boss->obj.pos.y, boss->obj.pos.z, 40.0f);
                    Effect_TimedSfx_Spawn(&boss->obj.pos, NA_SE_EN_EXPLOSION_L);
                    /* fallthrough */
                case 85:
                case 90:
                    Effect_Effect384_Spawn(boss->obj.pos.x, boss->obj.pos.y, boss->obj.pos.z, 250.0f, 6);
                    break;

                case 86:
                    Object_Kill(&boss->obj, boss->sfxSource);
                    gDrawBackdrop = 0;
                    break;

                case 111:
                    player->csState = 2;
                    AUDIO_PLAY_SFX(NA_SE_ARWING_BOOST, player->sfxSource, 0);
                    player->unk_190 = player->unk_194 = 7.0f;
                    D_ctx_80177A48[0] = 0.0f;
                    D_ctx_80177A48[1] = 0.0f;
                    D_ctx_80177A48[2] = 0.5f;
                    D_ctx_80177A48[3] = 1000.0f;
                    D_ctx_80177A48[4] = D_ctx_80177A48[5] = D_ctx_80177A48[6] = D_ctx_80177A48[7] = 0.0f;
                    D_ctx_80177A48[8] = 1.5f;
                    gCsFrameCount = 0;
                    break;
            }
            gCsCamAtX = gBosses[0].obj.pos.x;
            gCsCamAtY = gBosses[0].obj.pos.y;
            gCsCamAtZ = gBosses[0].obj.pos.z + gPathProgress;
            Math_SmoothStepToF(&player->camRoll, 0.0f, 0.1f, 3.0f, 0.0f);
            break;

        case 2:
            player->unk_190 = D_ctx_80177A48[8];
            sp90 = 0;
            sp68.x = RAND_FLOAT_CENTERED(150.0f);
            sp68.y = RAND_FLOAT_CENTERED(150.0f);
            sp68.z = 0.0f;

            if (gCsFrameCount == 50) {
                AUDIO_PLAY_SFX(NA_SE_OB_ROUTE_EXPLOSION0, player->sfxSource, 0);
                Audio_SetEnvSfxReverb(0);
            }
            if (gCsFrameCount > 40) {
                sp90 = 1;
            }
            if (gCsFrameCount < 30) {
                Math_SmoothStepToF(&D_ctx_80177A48[2], 0.5f, 1.0f, 0.05f, 0.0f);
            } else if (gCsFrameCount <= 150) {
                Math_SmoothStepToF(&D_ctx_80177A48[1], 300.0f, 0.1f, D_ctx_80177A48[5], 0.0f);
                Math_SmoothStepToF(&D_ctx_80177A48[2], 0.95f, 1.0f, 0.05f, 0.0f);
                Math_SmoothStepToF(&D_ctx_80177A48[3], 300.0f, 0.1f, 5.0f, 0.0f);
                if (gCsFrameCount == 150) {
                    D_ctx_80177A48[5] = 0.0f;
                }
            } else {
                Math_SmoothStepToF(&D_ctx_80177A48[1], 0.0f, 0.1f, D_ctx_80177A48[5], 0.0f);
                Math_SmoothStepToF(&D_ctx_80177A48[2], 0.85f, 1.0f, 0.01f, 0.0f);
                Math_SmoothStepToF(&D_ctx_80177A48[3], 200.0f, 0.1f, 5.0f, 0.0f);
                D_ctx_80177A48[4] += 4.5f;
                gDrawBackdrop = 2;
                Matrix_RotateZ(gCalcMatrix, 2.0f * RAND_FLOAT(M_PI), MTXF_NEW);
                sp74.x = RAND_FLOAT(50.0f) + 120.0f;
                sp74.y = 0.0f;
                sp74.z = 0.0f;
                Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp74, &sp68);
            }

            Math_SmoothStepToF(&D_ctx_80177A48[5], 3.0f, 1.0f, 0.05f, 0.0f);
            player->cam.eye.z += player->vel.z * D_ctx_80177A48[2];

            if (gCsFrameCount > 230) {
                player->camDist -= 7.0f;
            }
            if (gCsFrameCount > 230) {
                Math_SmoothStepToF(&D_ctx_80177A48[7], 3.0f, 1.0f, 0.1f, 0.0f);
                player->camRoll -= D_ctx_80177A48[7];
            }

            for (i = 0; i < sp90; i++) {
                Effect_FireSmoke1_SpawnMoving(player->pos.x + sp68.x, player->pos.y + sp68.y,
                                              player->pos.z - (D_ctx_80177A48[3] + D_ctx_80177A48[4]), 0.0f, 0.0f,
                                              50.0f, RAND_FLOAT(2.5f) + 2.5f);
            }

            Math_SmoothStepToF(&player->cam.eye.x, D_ctx_80177A48[1] + player->pos.x, 0.1f, 15.0f, 0.0f);
            Math_SmoothStepToF(&player->cam.eye.y, player->pos.y + 30.0f, 0.1f, 15.0f, 0.0f);
            Math_SmoothStepToF(&player->rot.z, -180.0f, 0.02f, D_ctx_80177A48[6], 0.0f);
            Math_SmoothStepToF(&D_ctx_80177A48[6], 3.0f, 1.0f, 0.05f, 0.0f);

            gCsCamAtX = player->pos.x;
            gCsCamAtY = player->pos.y;
            gCsCamAtZ = player->trueZpos + gPathProgress;

            if (gCsFrameCount > 200) {
                player->contrailScale += 0.03f;
                if (player->contrailScale > 0.6f) {
                    player->contrailScale = 0.6f;
                }
                Math_SmoothStepToF(&player->camRoll, 3.0f, 0.5f, 0.1f, 0.0f);
                Math_SmoothStepToF(D_ctx_801779A8, 70.0f, 1.0f, 2.0f, 0.0f);
            }

            switch (gCsFrameCount) {
                case 60:
                    for (i = 0; i < ARRAY_COUNT(gEffects); i++) {
                        if ((gEffects[i].obj.id == OBJ_EFFECT_383) && (gEffects[i].obj.status == OBJ_ACTIVE)) {
                            Object_Kill(&gEffects[i].obj, gEffects[i].sfxSource);
                            break;
                        }
                    }
                    break;

                case 25:
                    for (i = 0; i < 12; i++) {
                        Andross_AndPassage_Setup(&gScenery[i], player->pos.x, player->pos.y,
                                                 player->cam.eye.z - gPathProgress + (2195.0f * i), i);
                    }
                    break;

                case 150:
                    AUDIO_PLAY_SFX(NA_SE_WARP_HOLE, gDefaultSfxSource, 0);
                    break;

                case 340:
                    Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_OB_ROUTE_EXPLOSION0);
                    Audio_SetEnvSfxReverb(0);
                    gVenomHardClear = 0;
                    gBlurAlpha = 255;
                    gCurrentLevel = LEVEL_VENOM_2;
                    gLevelPhase = 1;
                    gLevelMode = LEVELMODE_ALL_RANGE;
                    player->csState = 3;
                    player->zPath = gPathProgress = 0.0f;
                    gDrawBackdrop = gDrawGround = true;
                    player->cam.eye.x = 1200.0f;
                    player->cam.eye.z = 1200.0f;
                    player->cam.eye.y = 1800.0f;
                    gCsCamAtX = 0.0f;
                    gCsCamAtY = 620.0f;
                    gCsCamAtZ = 0.0f;
                    player->camRoll = 0.0f;
                    player->draw = false;
                    D_ctx_80177A48[0] = 1.0f;
                    Play_ClearObjectData();

                    gScenery360 = Memory_Allocate(200 * sizeof(Scenery360));
                    for (i = 0; i < 200; i++) {
                        gScenery360[i].obj.status = OBJ_FREE;
                    }

                    Andross_LoadLevelObjects();
                    D_ctx_8017782C = true;
                    Play_InitEnvironment();
                    gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 0;
                    gFillScreenAlpha = gFillScreenAlphaTarget = 255;
                    player->csTimer = 2;
                    gCsFrameCount = 0;
                    D_ctx_80177A48[1] = 0.0f;
                    break;
            }
            break;

        case 3:
            if (player->csTimer == 0) {
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 0;
                gFillScreenAlpha = gFillScreenAlphaTarget = 0;
            } else {
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 0;
                gFillScreenAlpha = gFillScreenAlphaTarget = 255;
            }

            if ((gCsFrameCount == 20) && (gVenomHardClear != 0)) {
                Andross_ArwingEscape_Setup(1);
            }
            if (gCsFrameCount == 40) {
                Andross_ArwingEscape_Setup(10);
                AUDIO_PLAY_SFX(NA_SE_EN_STAR_EXPLOSION, boss->sfxSource, 4);
                gCameraShake = 30;
                gSceneSetup = 1;
                gControllerRumbleTimers[0] = 30;
            }
            if (gCsFrameCount > 40) {
                for (i = 0; i < 3; i++) {
                    Effect_FireSmoke1_SpawnMoving(
                        boss->obj.pos.x + RAND_FLOAT_CENTERED(150.0f), boss->obj.pos.y + 500.0f,
                        boss->obj.pos.z + RAND_FLOAT_CENTERED(150.0f), RAND_FLOAT_CENTERED(10.0f), 60.0f,
                        RAND_FLOAT_CENTERED(10.0f), RAND_FLOAT(5.5f) + 5.5f);
                }
                Math_SmoothStepToF(&gCsCamAtY, gActors[10].obj.pos.y, 1.0f, D_ctx_80177A48[1], 0.0f);
                Math_SmoothStepToF(&D_ctx_80177A48[1], 1000.0f, 1.0f, 5.0f, 0.0f);
            } else {
                Math_SmoothStepToF(&player->cam.eye.z, 1640.0f, 0.05f, 50.0f, 0.0f);
                Math_SmoothStepToF(&player->cam.eye.y, 110.0f, 0.05f, 50.0f, 0.0f);
                Math_SmoothStepToF(&player->cam.eye.x, 0.0f, 0.05f, 50.0f, 0.0f);
                Math_SmoothStepToF(&gCsCamAtY, 630.0f, 0.05f, 50.0f, 0.0f);
            }

            if (gCsFrameCount == 70) {
                AUDIO_PLAY_BGM(NA_BGM_ALL_CLEAR);
            }
            if (gCsFrameCount == 150) {
                player->csState++;
                D_ctx_80177A48[0] = 1.0f;
                D_ctx_80177A48[1] = 1000.0f;
                D_ctx_80177A48[2] = 0;
                D_ctx_80177A48[3] = 1.0f;
                gActors[10].obj.pos.y = 1500.0f;
                gActors[10].orient.z = 180.0f;
                gDrawBackdrop = 0;
                gFogFar = 1030;
                sAndLightR = gLight1R;
                sAndLightG = gLight1G;
                sAndLightB = gLight1B;
                sAndAmbientR = gAmbientR;
                sAndAmbientG = gAmbientG;
                sAndAmbientB = gAmbientB;
                gEnvLightyRot = -50.0f;
                gMissionStatus = MISSION_ACCOMPLISHED;
                for (i = 0; i < 200; i++) {
                    gScenery360[i].obj.status = OBJ_FREE;
                }
            }
            break;

        case 4:
            player->camRoll += D_ctx_80177A48[3];

            if (gCsFrameCount > 190) {
                Math_SmoothStepToF(&D_ctx_80177A48[3], 0.3f, 0.05f, 0.02f, 0.0f);
            }
            if (gCsFrameCount > 205) {
                Math_SmoothStepToF(&sAndLightR, 130.0f, 1.0f, 10.0f, 0.0f);
                Math_SmoothStepToF(&sAndLightG, 160.0f, 1.0f, 10.0f, 0.0f);
                Math_SmoothStepToF(&sAndLightB, 80.0f, 1.0f, 10.0f, 0.0f);
                Math_SmoothStepToF(&sAndAmbientR, 10.0f, 1.0f, 5.0f, 0.0f);
                Math_SmoothStepToF(&sAndAmbientG, 10.0f, 1.0f, 5.0f, 0.0f);
                Math_SmoothStepToF(&sAndAmbientB, 10.0f, 1.0f, 5.0f, 0.0f);
            }
            gLight1R = sAndLightR;
            gLight1G = sAndLightG;
            gLight1B = sAndLightB;

            gAmbientR = sAndAmbientR;
            gAmbientG = sAndAmbientG;
            gAmbientB = sAndAmbientB;

            Math_SmoothStepToF(&D_ctx_80177A48[1], -5000.0f, 0.05f, 15.0f, 0.0f);

            player->cam.eye.x = gActors[10].obj.pos.x + 50.0f;
            player->cam.eye.y = gActors[10].obj.pos.y + D_ctx_80177A48[1];
            player->cam.eye.z = gActors[10].obj.pos.z;

            gCsCamAtX = gActors[10].obj.pos.x;
            gCsCamAtY = gActors[10].obj.pos.y + 50.0f;
            gCsCamAtZ = gActors[10].obj.pos.z;

            if (((gGameFrameCount % 4) == 0) && (gCsFrameCount < 215)) {
                Effect_FireSmoke1_SpawnMoving(boss->obj.pos.x + RAND_FLOAT_CENTERED(350.0f), boss->obj.pos.y + 500.0f,
                                              boss->obj.pos.z + RAND_FLOAT_CENTERED(350.0f), RAND_FLOAT_CENTERED(10.0f),
                                              60.0f, RAND_FLOAT_CENTERED(10.0f), RAND_FLOAT(5.5f) + 15.5f);
            }
            sp80 = RAND_FLOAT(40.0f);
            for (i = 0; i < 36; i += 4) {
                sp8C = __sinf((i * 10.0f * M_DTOR) + sp80) * D_ctx_80177A48[2];
                sp84 = __cosf((i * 10.0f * M_DTOR) + sp80) * D_ctx_80177A48[2];
                Effect_FireSmoke1_SpawnMoving(sp8C, 300.0f, sp84, 0.0f, 0.0f, 0.0f, RAND_FLOAT(5.5f) + 15.5f);
            }

            Math_SmoothStepToF(&D_ctx_80177A48[2], 10000.0f, 0.05f, 20.0f, 0.0f);

            if (gCsFrameCount == 220) {
                Andross_Team_Setup(0);
                if (gTeamShields[TEAM_ID_FALCO] > 0) {
                    Andross_Team_Setup(1);
                }
                if (gTeamShields[TEAM_ID_SLIPPY] > 0) {
                    Andross_Team_Setup(2);
                }
                if (gTeamShields[TEAM_ID_PEPPY] > 0) {
                    Andross_Team_Setup(3);
                }
            }

            if (gCsFrameCount == 190) {
                Play_GenerateStarfield();
                gStarCount = 1000;
                player->wingPosition = 0;
            }
            if (gCsFrameCount == 360) {
                gCsFrameCount = 340;
                player->csState++;
                D_ctx_80177A48[0] = 1.0f;
                D_ctx_80177A48[1] = 0.0f;
                D_ctx_80177A48[2] = 0.0f;
                D_ctx_80177A48[3] = 0.0f;
                D_ctx_80177A48[4] = 0.0f;
                player->cam.eye.x = gCsCamEyeX = 100.0f;
                player->cam.eye.y = gCsCamEyeY = 14800.0f;
                player->cam.eye.z = gCsCamEyeZ = -1500.0f;
                gCsCamAtX = 0.0f;
                gCsCamAtY = 15000.0f;
                gCsCamAtZ = 0;
                player->camRoll = 0.0f;
                gActors[10].state = 101;
                gActors[10].fwork[0] = 0.0f;
                gActors[10].obj.pos.y = 14500.0f;
                gActors[10].orient.z = 70.0f;
                gActors[10].orient.x = gActors[10].orient.y = 0.0f;
                gFillScreenAlpha = gFillScreenAlphaTarget = 255;
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 0;
                player->csTimer = 3;
                gStarCount = 500;
            }
            if (gCsFrameCount == 250) {
                gLevelClearScreenTimer = 100;
            }
            break;

        case 5:
            if (player->csTimer == 1) {
                gFillScreenAlpha = gFillScreenAlphaTarget = 0;
            }

            if (gVenomHardClear != 0) {
                if (gCsFrameCount >= 1000) {
                    gCsCamAtX += D_ctx_80177A48[4] * 0.15f;
                    gCsCamEyeZ += D_ctx_80177A48[4];
                    Math_SmoothStepToF(&D_ctx_80177A48[4], 20.0f, 1.0f, 0.1f, 0.0f);
                } else {
                    gCsCamEyeZ = gActors[10].obj.pos.z - 20.0f;
                }
                if ((gCsFrameCount >= 920) && (gTeamShields[TEAM_ID_PEPPY] > 0)) {
                    if (gCsFrameCount == 920) {
                        player->csTimer = 25;
                    }
                    gActors[10].fwork[19] = SIN_DEG(player->csTimer * 40.0f) * 5.0f;
                } else {
                    if (gCsFrameCount < 850) {
                        switch (gCsFrameCount) {
                            case 600:
                                D_ctx_80177A48[2] = 80.0f;
                                D_ctx_80177A48[3] = -45.0f;
                                break;
                            case 650:
                                D_ctx_80177A48[2] = 0.0f;
                                break;
                            case 680:
                                D_ctx_80177A48[2] = 45.0f;
                                D_ctx_80177A48[3] = -20.0f;
                                break;
                            case 750:
                                D_ctx_80177A48[2] = 90.0f;
                                D_ctx_80177A48[3] = -30.0f;
                                break;
                            case 780:
                                D_ctx_80177A48[2] = 30.0f;
                                D_ctx_80177A48[3] = -45.0f;
                                break;
                            case 830:
                                D_ctx_80177A48[2] = -20.0f;
                                D_ctx_80177A48[3] = -25.0f;
                                break;
                            default:
                                // D_ctx_80177A48[2] = 0.0f;
                                break;
                        }
                    }
                    if (gCsFrameCount > 880) {
                        Math_SmoothStepToF(&gActors[10].fwork[19], 0.0f, 0.2f, 2.0f, 0.0f);
                        Math_SmoothStepToF(&gActors[10].fwork[20], 0.0f, 0.2f, 2.0f, 0.0f);
                    } else {
                        Math_SmoothStepToF(&gActors[10].fwork[19], D_ctx_80177A48[2], 0.2f, 2.0f, 0.0f);
                        Math_SmoothStepToF(&gActors[10].fwork[20], D_ctx_80177A48[3], 0.2f, 2.0f, 0.0f);
                    }
                }
                D_ctx_80177A48[0] = 0.01f;
                Math_SmoothStepToF(&D_ctx_80177A48[1], 10.0f, 1.0f, 0.1f, 0.0f);
                Math_SmoothStepToF(&player->cam.eye.x, gActors[10].obj.pos.x - 50.0f, D_ctx_80177A48[0],
                                   D_ctx_80177A48[1], 0);
                Math_SmoothStepToF(&player->cam.eye.y, gActors[10].obj.pos.y + 10.0f, D_ctx_80177A48[0],
                                   D_ctx_80177A48[1], 0);
                Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, D_ctx_80177A48[0], D_ctx_80177A48[1], 0);
                gCsCamAtY = SIN_DEG(gGameFrameCount * 5.5f) + 15000.0f;
            } else {
                gCsCamEyeX -= 1.0f;
                gCsCamEyeY += 0.3f;
                gCsCamEyeZ += 4.0f;
                gCsCamAtY = (SIN_DEG(gGameFrameCount * 1.5f) * 10.0f) + 15000.0f;
                Math_SmoothStepToF(&player->cam.eye.x, gCsCamEyeX, D_ctx_80177A48[0], 50000.0f, 0);
                Math_SmoothStepToF(&player->cam.eye.y, gCsCamEyeY, D_ctx_80177A48[0], 50000.0f, 0);
                Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, D_ctx_80177A48[0], 50000.0f, 0);
            }

            if (gVenomHardClear != 0) {
                switch (gCsFrameCount) {
                    case 400:
                        Radio_PlayMessage(gMsg_ID_19400, RCID_PEPPY);
                        break;
                    case 500:
                        Radio_PlayMessage(gMsg_ID_19410, RCID_SLIPPY);
                        break;
                    case 600:
                        Radio_PlayMessage(gMsg_ID_19420, RCID_FALCO);
                        break;
                    case 800:
                        Radio_PlayMessage(gMsg_ID_19430, RCID_PEPPY);
                        break;
                    case 900:
                        if (gTeamShields[TEAM_ID_PEPPY] > 0) {
                            Radio_PlayMessage(gMsg_ID_19440, RCID_FOX);
                        }
                        break;
                    case 1050:
                        gShowLevelClearStatusScreen = true;
                        break;
                    case 1250:
                        gShowLevelClearStatusScreen = false;
                        break;
                }
                // Shooting Star. James? Is that you?
                if (gCsFrameCount > 1300) {
                    // @recomp: Reposition and tweak shooting star for extended starfield
                    rnd = RAND_INT(100.0f);
                    gStarFillColors[1155] = FILL_COLOR(gStarColors[rnd % 16U]);
                    gStarOffsetsX[1155] += 1.0f * 2.0f;
                    gStarOffsetsY[1155] += 0.5f * 2.0f;
                }

            } else {
                switch (gCsFrameCount) {
                    case 400:
                        Radio_PlayMessage(gMsg_ID_8300, RCID_PEPPY);
                        break;
                    case 500:
                        Radio_PlayMessage(gMsg_ID_8310, RCID_SLIPPY);
                        break;
                    case 600:
                        Radio_PlayMessage(gMsg_ID_8320, RCID_FALCO);
                        gCsFrameCount += 230;
                        break;
                    case 1050:
                        gShowLevelClearStatusScreen = true;
                        break;
                    case 1250:
                        gShowLevelClearStatusScreen = false;
                        break;
                }
            }
            if (gCsFrameCount == 1400) {
                Audio_FadeOutAll(40);
            }
            if (gCsFrameCount > 1400) {
                gFillScreenAlphaStep = 4;
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 0;
                gFillScreenAlphaTarget = 255;
                if (gFillScreenAlpha == 255) {
                    gNextGameState = GSTATE_ENDING;
                    
                    //! @bug This references a variable in another overlay, causing undefined behavior.
                    //! In US v1.1, that address contains the store instruction for player->vel.y = vel.y; in
                    //! Venom2_LevelStart. Setting this to nop is harmless, as the overlay will be unloaded next frame.

                    // D_ending_80196D00 = 0; // bug
                    gLeveLClearStatus[LEVEL_VENOM_ANDROSS] = Play_CheckMedalStatus(200) + 1;
                    Audio_SetAudioSpec(0, ((0) << 8) | (27));
                }
            }
            break;

        case 100:
            gPlayerGlareAlphas[0] -= 4;
            if (gPlayerGlareAlphas[0] > 255) {
                gPlayerGlareAlphas[0] = 0;
            }
            Matrix_RotateY(gCalcMatrix, (player->yRot_114 + player->rot.y + 180.0f) * M_DTOR, MTXF_NEW);
            Matrix_RotateX(gCalcMatrix, -((player->xRot_120 + player->rot.x + player->aerobaticPitch) * M_DTOR),
                           MTXF_APPLY);

            sp74.x = 0.0f;
            sp74.y = 0.0f;
            sp74.z = player->baseSpeed;

            Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp74, &sp68);

            player->vel.x = sp68.x;
            player->vel.z = sp68.z;
            player->vel.y = sp68.y;

            if (player->csTimer == 0) {
                player->state = PLAYERSTATE_ACTIVE;
                player->unk_014 = 0.2f;
                player->unk_018 = 0.0f;
                player->unk_01C = 0.05f;
                gDrawBackdrop = 6;
                gProjectFar = 12800.0f;
            }

            D_ctx_80177A48[0] = 1.0f;
            gCsCamAtX = (2.0f * SIN_DEG(gGameFrameCount * 40.0f)) + player->pos.x;
            gCsCamAtY = (2.0f * SIN_DEG(gGameFrameCount * 30.0f)) + player->pos.y;
            gCsCamAtZ = (2.0f * SIN_DEG(gGameFrameCount * 50.0f)) + player->pos.z;
            sp74.x = 0.0f;
            sp74.y = 0.0f;
            sp74.z = D_ctx_80177A48[5];
            Math_SmoothStepToF(&D_ctx_80177A48[5], -400.0f, 0.05f, 5.0f, 0.0f);
            Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp74, &sp68);
            gCsCamEyeX = player->pos.x + sp68.x;
            gCsCamEyeY = player->pos.y + sp68.y;
            gCsCamEyeZ = player->pos.z + sp68.z;
            Math_SmoothStepToF(&player->cam.eye.x, gCsCamEyeX, D_ctx_80177A48[0], 50000.0f, 0);
            Math_SmoothStepToF(&player->cam.eye.y, gCsCamEyeY, D_ctx_80177A48[0], 50000.0f, 0);
            Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, D_ctx_80177A48[0], 50000.0f, 0);
            Math_SmoothStepToF(&player->zRotBank, 0.0f, 0.1f, 0.7f, 0.0f);
            Math_SmoothStepToF(&player->camRoll, 0.0f, 0.1f, 0.4f, 0.0f);
            break;
    }
    player->pos.x += player->vel.x;
    player->pos.y += player->vel.y;
    player->pos.z += player->vel.z;
    player->trueZpos = player->pos.z + player->camDist;
    player->bankAngle = player->rot.z + player->zRotBank + player->zRotBarrelRoll;
    Math_SmoothStepToF(&player->zRotBarrelRoll, 0.0f, 0.1f, 15.0f, 0.0f);
    Math_SmoothStepToAngle(&player->aerobaticPitch, 0.0f, 0.1f, 20.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.x, gCsCamAtX, D_ctx_80177A48[0], 50000.0f, 0);
    Math_SmoothStepToF(&player->cam.at.y, gCsCamAtY, D_ctx_80177A48[0], 50000.0f, 0);
    Math_SmoothStepToF(&player->cam.at.z, gCsCamAtZ, D_ctx_80177A48[0], 50000.0f, 0);
}