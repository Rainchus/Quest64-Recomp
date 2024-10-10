
#include "patches.h"
#include "sf64audio_external.h"

#if 1 // Global scope

#if 0
extern f32 segataSanshiro;
#endif

#if 1 // Background_DrawBackdrop
RECOMP_PATCH void Background_DrawBackdrop(void) {
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    s32 i;
    u8 levelType;
    s32 levelId;

    if (gDrawBackdrop == 0) {
        return;
    }

    levelType = gLevelType;
    if ((gCurrentLevel == LEVEL_VERSUS) && (gVersusStage == VS_STAGE_SECTOR_Z)) {
        levelType = LEVELTYPE_PLANET;
    }
    if (gCurrentLevel == LEVEL_TRAINING) {
        levelType = LEVELTYPE_SPACE;
    }
    levelId = gCurrentLevel;

    Matrix_Push(&gGfxMatrix);

    if (gFovYMode == 2) {
        Matrix_Scale(gGfxMatrix, 1.2f, 1.2f, 1.0f, MTXF_APPLY);
    }

    switch (levelType) {
        case LEVELTYPE_PLANET:
            RCP_SetupDL(&gMasterDisp, SETUPDL_17);
            switch (levelId) {
                case LEVEL_FORTUNA:
                case LEVEL_KATINA:
                case LEVEL_VENOM_2:
                case LEVEL_VERSUS:
                    sp134 = (gPlayer[gPlayerNum].camPitch * -6000.0f) - (gPlayer[gPlayerNum].cam.eye.y * 0.4f);
                    sp13C = Math_ModF(Math_RadToDeg(gPlayer[gPlayerNum].camYaw) * (-7280.0f / 360.0f) * 5.0f, 7280.0f);
                    Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);

                    // Start by translating the matrix to the far left position
                    Matrix_Translate(gGfxMatrix, sp13C - 14560.0f, -2000.0f + sp134, -6000.0f, MTXF_APPLY);

                    if (gCurrentLevel == LEVEL_FORTUNA) {
                        Matrix_Translate(gGfxMatrix, 0.0f, -2000.0f, 0, MTXF_APPLY);
                    } else if (gCurrentLevel == LEVEL_KATINA) {
                        Matrix_Translate(gGfxMatrix, 0.0f, -2500.0f, 0, MTXF_APPLY);
                    }

                    Matrix_SetGfxMtx(&gMasterDisp);

                    // Render the textures across the screen (left to right)
                    for (int i = 0; i < 6; i++) {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposed(gMasterDisp++, TAG_BACKGROUND, G_EX_PUSH, G_MTX_MODELVIEW,
                                                 G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO,
                                                 G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                                 G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_AUTO,
                                                 G_EX_EDIT_ALLOW);

                        switch (gCurrentLevel) {
                            case LEVEL_VERSUS:
                                if (gVersusStage == VS_STAGE_CORNERIA) {
                                    gSPDisplayList(gMasterDisp++, D_versus_302D4D0);
                                } else if (gVersusStage == VS_STAGE_KATINA) {
                                    gSPDisplayList(gMasterDisp++, D_versus_30146B0);
                                } else {
                                    gSPDisplayList(gMasterDisp++, D_versus_3011E40);
                                }
                                break;
                            case LEVEL_FORTUNA:
                                gSPDisplayList(gMasterDisp++, D_FO_600D9F0);
                                break;
                            case LEVEL_KATINA:
                                gSPDisplayList(gMasterDisp++, D_KA_600F1D0);
                                break;
                            case LEVEL_VENOM_2:
                                gSPDisplayList(gMasterDisp++, D_VE2_600F670);
                                break;
                        }

                        // Translate to the next position (move right by 7280.0f each time)
                        Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);

                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    }
                    break;

                case LEVEL_CORNERIA:
                case LEVEL_VENOM_1: {
                    // Calculate vertical and horizontal offsets
                    f32 sp134 = (gPlayer[gPlayerNum].camPitch * -6000.0f) - (gPlayer[gPlayerNum].cam.eye.y * 0.6f);
                    f32 sp13C =
                        Math_ModF(Math_RadToDeg(gPlayer[gPlayerNum].camYaw) * (-7280.0f / 360.0f) * 5.0f, 7280.0f);

                    // Apply camera roll and translate matrix to the starting position (far left)
                    Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                    Matrix_Translate(gGfxMatrix, sp13C - 14560.0f, -2000.0f + sp134, -6000.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    // Render the textures across a wider range to cover the screen
                    for (int i = 0; i < 10; i++) {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposed(gMasterDisp++, TAG_BACKGROUND, G_EX_PUSH, G_MTX_MODELVIEW,
                                                 G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO,
                                                 G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                                 G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_AUTO,
                                                 G_EX_EDIT_ALLOW);

                        switch ((s32) gCurrentLevel) {
                            case LEVEL_CORNERIA:
                                gSPDisplayList(gMasterDisp++, D_CO_60059F0);
                                break;
                            case LEVEL_VENOM_1:
                                gSPDisplayList(gMasterDisp++, D_VE1_60046F0);
                                break;
                        }

                        // Translate to the next position (move right by 7280.0f each time)
                        Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);

                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    }

                    break;
                }

                case LEVEL_VENOM_ANDROSS: // WIP
                    if (gDrawBackdrop != 6) {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposed(gMasterDisp++, TAG_BACKGROUND, G_EX_PUSH, G_MTX_MODELVIEW,
                                                 G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO,
                                                 G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                                 G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_AUTO,
                                                 G_EX_EDIT_ALLOW);
                        if ((gDrawBackdrop == 2) || (gDrawBackdrop == 7)) {
                            Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                            Matrix_Translate(gGfxMatrix, 0.0f, -4000.0f, -7000.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_600F670);
                        } else if ((gDrawBackdrop == 3) || (gDrawBackdrop == 4)) {
                            RCP_SetupDL(&gMasterDisp, SETUPDL_62);

                            if (gDrawBackdrop == 4) {
                                if ((gGameFrameCount & 8) == 0) {
                                    Math_SmoothStepToF(&gAndrossUnkBrightness, 0.0f, 1.0f, 30.0f, 0);
                                } else {
                                    Math_SmoothStepToF(&gAndrossUnkBrightness, 120.0f, 1.0f, 30.0f, 0);
                                }
                            } else {
                                gAndrossUnkBrightness = 255.0f;
                            }

                            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, (s32) gAndrossUnkBrightness,
                                            (s32) gAndrossUnkBrightness, (s32) gAndrossUnkAlpha);

                            sp134 = (gPlayer[gPlayerNum].camPitch * -6000.0f) - (gPlayer[gPlayerNum].cam.eye.y * 0.4f);
                            sp13C = Math_ModF(Math_RadToDeg(gPlayer[gPlayerNum].camYaw) * (-7280.0f / 360.0f) * 5.0f,
                                              7280.0f);

                            // Leftmost DL (-2x translation)
                            Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                            Matrix_Translate(gGfxMatrix, sp13C - 2 * 7280.0f, -2000.0f + sp134, -6000.0f, MTXF_APPLY);
                            Matrix_Translate(gGfxMatrix, 0.0f, -2500.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_60038E0);

                            // Left DL (-1x translation)
                            Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_60038E0);

                            // Middle DL (original)
                            Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_60038E0);

                            // Right DL (+1x translation)
                            Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_60038E0);

                            // Rightmost DL (+2x translation)
                            Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_60038E0);
                        } else {
                            RCP_SetupDL(&gMasterDisp, SETUPDL_62);
                            if (gDrawBackdrop == 5) {
                                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 64);
                            } else {
                                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 0, 255, 128, (s32) gAndrossUnkAlpha);
                            }
                            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -290.0f, MTXF_APPLY);
                            Matrix_Push(&gGfxMatrix);
                            Matrix_Scale(gGfxMatrix, 11.0f, 11.0f, 1.0f, MTXF_APPLY);
                            Matrix_RotateZ(gGfxMatrix, (gPlayer[0].camRoll + (gGameFrameCount * 1.5f)) * M_DTOR,
                                           MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_ANDROSS_C039208);
                            Matrix_Pop(&gGfxMatrix);
                            if (gDrawBackdrop != 5) {
                                Matrix_Push(&gGfxMatrix);
                                Matrix_Scale(gGfxMatrix, 10.0f, 10.0f, 1.0f, MTXF_APPLY);
                                Matrix_RotateZ(gGfxMatrix, (gPlayer[0].camRoll + (gGameFrameCount * -1.3f)) * M_DTOR,
                                               MTXF_APPLY);
                                Matrix_SetGfxMtx(&gMasterDisp);
                                gSPDisplayList(gMasterDisp++, D_ANDROSS_C039208);
                                Matrix_Pop(&gGfxMatrix);
                            }
                        }
                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    }
                    break;

                case LEVEL_AQUAS:
                    if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) {
                        sp13C = Math_RadToDeg(gPlayer[gPlayerNum].camYaw) - gPlayer[gPlayerNum].yRot_114;
                        sp134 = (gPlayer[gPlayerNum].camPitch * -7000.0f) - (gPlayer[gPlayerNum].cam.eye.y * 0.6f);
                        sp13C = Math_ModF(sp13C * -40.44444f * 2.0f, 7280.0f); // close to 7280.0f / 180.0f
                        RCP_SetupDL_17();
                        Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                        Matrix_Scale(gGfxMatrix, 1.5f, 1.0f, 1.0f, MTXF_APPLY);

                        // Start by translating the matrix to the far left position
                        Matrix_Translate(gGfxMatrix, sp13C - 14560.0f, sp134, -7000.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);

                        // Render the textures across the screen (left to right)
                        for (int i = 0; i < 5; i++) {
                            // @recomp Tag the transform.
                            gEXMatrixGroupDecomposed(gMasterDisp++, TAG_BACKGROUND, G_EX_PUSH, G_MTX_MODELVIEW,
                                                     G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO,
                                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_AUTO,
                                                     G_EX_EDIT_ALLOW);

                            if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) {
                                gSPDisplayList(gMasterDisp++, D_AQ_601AFF0);
                            } else {
                                gSPDisplayList(gMasterDisp++, D_AQ_601C080);
                            }

                            // Translate to the next position (move right by 7280.0f each time)
                            Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);

                            // @recomp Pop the transform id.
                            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                        }
                        Matrix_Pop(&gGfxMatrix);
                    }
                    break;

                case LEVEL_SOLAR:
                case LEVEL_ZONESS:
                case LEVEL_MACBETH:
                case LEVEL_TITANIA:
                    sp12C = Math_RadToDeg(gPlayer[gPlayerNum].camYaw) - gPlayer[gPlayerNum].yRot_114;
                    sp134 = (gPlayer[gPlayerNum].camPitch * -7000.0f) - (gPlayer[gPlayerNum].cam.eye.y * 0.6f);
                    sp13C = sp12C * -40.44444f * 2.0f; // close to 7280.0f / 180.0f

                    if ((gCurrentLevel == LEVEL_TITANIA) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) &&
                        (gPlayer[0].csState < 3)) {
                        D_bg_8015F968 += __sinf(gPlayer[0].camYaw) * 20.0f;
                        sp13C += D_bg_8015F968;
                    }
                    if ((gCurrentLevel == LEVEL_SOLAR) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) &&
                        (gPlayer[0].csState >= 2) && (gPlayer[0].cam.eye.z <= -1900.0f)) {
                        D_bg_8015F968 = __sinf(gPlayer[0].camPitch) * 7000.0f;
                        sp134 -= fabsf(D_bg_8015F968);
                    }

                    sp13C = Math_ModF(sp13C, 7280.0f);
                    RCP_SetupDL_17();
                    Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, 1.5f, 1.0f, 1.0f, MTXF_APPLY);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposed(gMasterDisp++, TAG_BACKGROUND, G_EX_PUSH, G_MTX_MODELVIEW,
                                             G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO,
                                             G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                             G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_AUTO,
                                             G_EX_EDIT_ALLOW);

                    if ((gCurrentLevel == LEVEL_TITANIA) || (gCurrentLevel == LEVEL_ZONESS)) {
                        Matrix_Translate(gGfxMatrix, sp13C - 14560.0f, -3000.0f + sp134, -7000.0f, MTXF_APPLY);
                    } else if (gCurrentLevel == LEVEL_SOLAR) {
                        Matrix_Translate(gGfxMatrix, sp13C - 14560.0f, -3500.0f + sp134, -7000.0f, MTXF_APPLY);
                    } else if (gCurrentLevel == LEVEL_MACBETH) {
                        Matrix_Translate(gGfxMatrix, sp13C - 14560.0f, -4000.0f + sp134, -7000.0f, MTXF_APPLY);
                    }
                    Matrix_SetGfxMtx(&gMasterDisp);

                    // Render the textures across a wider range to cover the screen
                    for (int i = 0; i < 5; i++) {

                        if (gCurrentLevel == LEVEL_TITANIA) {
                            gSPDisplayList(gMasterDisp++, D_TI_6000A80);
                        } else if (gCurrentLevel == LEVEL_MACBETH) {
                            gSPDisplayList(gMasterDisp++, D_MA_6019220);
                        } else if (gCurrentLevel == LEVEL_ZONESS) {
                            gSPDisplayList(gMasterDisp++, D_ZO_6013480);
                        } else if (gCurrentLevel == LEVEL_SOLAR) {
                            gSPDisplayList(gMasterDisp++, D_SO_601E150);
                        }

                        // Move the matrix to the right by 7280.0f each time to draw the next texture
                        Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);

                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                        Matrix_SetGfxMtx(&gMasterDisp);
                    }
                    break;
            }
            break;

        case LEVELTYPE_SPACE: // WIP Needed (space levels have textures that wrap around the screen)
            if (gPlayer[0].state_1C8 != PLAYERSTATE_1C8_ENTER_WARP_ZONE) {
                Matrix_Push(&gGfxMatrix);
                sp12C = Math_RadToDeg(gPlayer[0].camYaw);
                sp130 = Math_RadToDeg(gPlayer[0].camPitch);
                if (((sp12C < 45.0f) || (sp12C > 315.0f)) && ((sp130 < 40.0f) || (sp130 > 325.0f))) {
                    RCP_SetupDL_36();
                    sp138 = gStarfieldX;
                    sp134 = gStarfieldY;
                    if (((gCurrentLevel == LEVEL_SECTOR_X) || (gCurrentLevel == LEVEL_METEO)) && (gLevelPhase == 1)) {
                        levelId = LEVEL_WARP_ZONE;
                    }

                    if (levelId == LEVEL_SECTOR_X) {
                        sp138 = Math_ModF(sp138 + 60.0f, 480.0f);
                        sp134 = Math_ModF(sp134 + 360.0f - 40.0f, 360.0f);
                    } else if (levelId == LEVEL_TRAINING) {
                        sp138 = Math_ModF(sp138 - 30.0f, 480.0f);
                        sp134 = Math_ModF(sp134 + 360.0f - 40.0f, 360.0f);
                    } else if ((levelId == LEVEL_SECTOR_Y) && (gLevelMode == LEVELMODE_ON_RAILS)) {
                        sp138 = Math_ModF(sp138 + 480.0f - 60.0f, 480.0f);
                        sp134 = Math_ModF(sp134, 360.0f);
                    } else if (levelId == LEVEL_FORTUNA) {
                        sp138 = Math_ModF(sp138 - 34.5f, 480.0f);
                        sp134 = Math_ModF(sp134 + 19.0f, 360.0f);
                    } else if (levelId == LEVEL_BOLSE) {
                        if ((gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_COMPLETE) || (gPlayer[0].csState < 10)) {
                            sp134 = Math_ModF(sp134 + 360.0f - 100.0f, 360.0f);
                        }
                    } else {
                        sp138 = Math_ModF(sp138, 480.0f);
                        sp134 = Math_ModF(sp134, 360.0f);
                    }

                    if ((sp12C < 180.0f) && (sp138 > 380.0f)) {
                        sp138 = -(480.0f - sp138);
                    }
                    if ((sp130 > 180.0f) && (sp134 > 280.0f)) {
                        sp134 = -(360.0f - sp134);
                    }

                    Matrix_RotateZ(gGfxMatrix, gStarfieldRoll, MTXF_APPLY);

                    switch (levelId) {
                        case LEVEL_WARP_ZONE:
                            if ((s32) gWarpZoneBgAlpha != 0) {
                                RCP_SetupDL_62();
                                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, (s32) gWarpZoneBgAlpha);
                                Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                                Matrix_Scale(gGfxMatrix, 1.7f, 1.7f, 1.0f, MTXF_APPLY);
                                Matrix_Push(&gGfxMatrix);
                                Matrix_RotateZ(gGfxMatrix, -(f32) gGameFrameCount * 10.0f * M_DTOR, MTXF_APPLY);
                                Matrix_Scale(gGfxMatrix, 1.07f, 0.93f, 1.0f, MTXF_APPLY);
                                Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 10.0f * M_DTOR, MTXF_APPLY);
                                Matrix_Scale(gGfxMatrix, 1.07f, 0.93f, 1.0f, MTXF_APPLY);
                                Matrix_SetGfxMtx(&gMasterDisp);
                                gSPDisplayList(gMasterDisp++, D_WZ_7001540);
                                Matrix_Pop(&gGfxMatrix);
                            }
                            break;

                        case LEVEL_METEO:
                            if ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE) && (gCsFrameCount > 260)) {
                                Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f) - 30.0f, -290.0f,
                                                 MTXF_APPLY);
                                Matrix_Scale(gGfxMatrix, 0.5f, 0.5f, 1.0f, MTXF_APPLY);
                                Matrix_SetGfxMtx(&gMasterDisp);
                                gSPDisplayList(gMasterDisp++, D_ME_600DDF0);
                            } else if (gPathProgress > 185668.0f) {
                                Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f) - 130.0f, -290.0f,
                                                 MTXF_APPLY);
                                Matrix_Scale(gGfxMatrix, 0.4f, 0.4f, 1.0f, MTXF_APPLY);
                                Matrix_SetGfxMtx(&gMasterDisp);
                                gSPDisplayList(gMasterDisp++, D_ME_600DDF0);
                            }
                            break;

                        case LEVEL_SECTOR_X:
                            if (gSceneSetup == 0) {
                                Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                                Matrix_Scale(gGfxMatrix, 3.0f, 3.0f, 1.0f, MTXF_APPLY);
                                Matrix_SetGfxMtx(&gMasterDisp);
                                RCP_SetupDL_62();
                                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 192);
                                gSPDisplayList(gMasterDisp++, D_SX_6029890);
                            }
                            break;

                        case LEVEL_TRAINING:
                            Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                            Matrix_Scale(gGfxMatrix, 0.2f, 0.2f, 1.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            RCP_SetupDL_62();
                            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
                            gSPDisplayList(gMasterDisp++, D_TR_6003760);
                            break;

                        case LEVEL_AREA_6:
                        case LEVEL_UNK_4:
                            sp128 = (gPathProgress * 0.00004f) + 0.5f;
                            if (sp128 > 3.5f) {
                                sp128 = 3.5f;
                            }
                            if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE) {
                                sp128 = D_bg_8015F984;
                                if (sp128 > 3.5f) {
                                    sp128 = 3.5f;
                                }
                            }
                            Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                            Matrix_Scale(gGfxMatrix, sp128 * 0.75, sp128 * 0.75f, 1.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_A6_601BB40);
                            break;

                        case LEVEL_FORTUNA:
                            sp128 = 1.5f;
                            if ((gCsFrameCount > 400) && (gMissionStatus == MISSION_COMPLETE)) {
                                sp128 = 0.75f;
                            }
                            Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                            Matrix_Scale(gGfxMatrix, sp128, sp128, sp128, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_FO_600B4B0);
                            break;

                        case LEVEL_BOLSE:
                            sp128 = 1.0f;
                            if ((gCsFrameCount > 500) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE)) {
                                sp128 = 1.3f;
                            }
                            Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                            Matrix_Scale(gGfxMatrix, sp128, sp128, sp128, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_BO_600D190);
                            break;

                        case LEVEL_SECTOR_Z:
                            Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                            Matrix_Scale(gGfxMatrix, 0.5f, 0.5f, 0.5f, MTXF_APPLY);
                            Matrix_RotateX(gGfxMatrix, M_PI / 2, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, aSzBackgroundDL);
                            break;

                        case LEVEL_SECTOR_Y:
                            Matrix_Translate(gGfxMatrix, sp138 - 120.0f, -(sp134 - 120.0f), -290.0f, MTXF_APPLY);
                            Matrix_Scale(gGfxMatrix, 0.4f, 0.4f, 1.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            RCP_SetupDL_62();
                            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 192);
                            gSPDisplayList(gMasterDisp++, D_SY_6001840);
                            break;
                    }
                }
                Matrix_Pop(&gGfxMatrix);
            }

            if (gStarWarpDistortion > 0.0f) {
                f32* xStar = gStarOffsetsX;
                f32* yStar = gStarOffsetsY;
                f32 zRot;

                RCP_SetupDL_14();
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 128, 128, 255, 255);

                zRot = 0.0f;
                for (i = 0; i < 300 * 3; i++, xStar++, yStar++) {
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposed(gMasterDisp++, (TAG_STARFIELD | 0x01000000) + i, G_EX_PUSH,
                                             G_MTX_MODELVIEW, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO,
                                             G_EX_COMPONENT_AUTO, G_EX_COMPONENT_INTERPOLATE,
                                             G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                             G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_AUTO, G_EX_EDIT_ALLOW);

                    *xStar = RAND_FLOAT_SEEDED(480.0f * 3.0f) - 80.0f;
                    *yStar = RAND_FLOAT_SEEDED(360.0f * 3.0f) - 60.0f;
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, (*xStar - 160.0f - 480.0f) * 10.0f, (*yStar - 120.0f - 20.0f) * 10.0f,
                                     -5000.0f, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, zRot, MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, 10.0f, 1.0f, -gStarWarpDistortion, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_edisplay_800CFD80);
                    Matrix_Pop(&gGfxMatrix);
                    zRot += M_PI / 4;
                    
                    // Pop the transform id
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                }
            }
            break;
    }
    Matrix_Pop(&gGfxMatrix);
}
#endif

#if 1 // Play_InitLevel

void Macbeth_InitLevel(void);
void Titania_80188F30(void);
void Aquas_InitLevel(void);

#define MEM_ARRAY_ALLOCATE(arr, count) ((arr) = Memory_Allocate((count) * sizeof(*(arr))))

RECOMP_PATCH void Play_InitLevel(void) {
    Vtx* mesh;
    u8* ptr;
    s32 i;
    f32* fptr;

    switch (gCurrentLevel) {
        case LEVEL_TRAINING:
            AUDIO_SET_SPEC(SFXCHAN_0, AUDIOSPEC_28);
            gTeamLowHealthMsgTimer = -1;
            break;
        case LEVEL_VENOM_1:
            AUDIO_SET_SPEC(SFXCHAN_0, AUDIOSPEC_6);
            break;
        case LEVEL_VENOM_2:
            AUDIO_SET_SPEC(SFXCHAN_0, AUDIOSPEC_6);
            break;
        case LEVEL_VENOM_ANDROSS:
            AUDIO_SET_SPEC(SFXCHAN_0, AUDIOSPEC_15);
            Audio_SetEnvSfxReverb(0);
            gTeamLowHealthMsgTimer = -1;
            break;
    }

    gUseDynaFloor = 0;

    switch (gCurrentLevel) {
        case LEVEL_SECTOR_Z:
            gGreatFoxIntact = true;
            break;

        case LEVEL_METEO:
        case LEVEL_SECTOR_X:
            if (gLevelPhase == 1) {
                gFogRed = 178;
                gFogGreen = 190;
                gFogBlue = 90;
                gLight1R = 200;
                gLight1G = 200;
                gLight1B = 120;
                gAmbientR = 0;
                gAmbientG = 50;
                gAmbientB = 100;
            }
            break;

        case LEVEL_VENOM_ANDROSS:
            gDrawGround = false;
            gDrawBackdrop = 6;
            D_Andross_801A7F58 = D_Andross_801A7F60 = D_Andross_801A7F68 = D_Andross_801A7F70 = D_Andross_801A7F78 =
                0.0f;
            break;

        case LEVEL_AQUAS:
            gVIsPerFrame = 3;
            D_bg_8015F970 = 1600.0f;
            D_AQ_801C4188 = 128.0f;
            Aquas_InitLevel();
            break;

        case LEVEL_TITANIA:
            Titania_80188F30();
            gTeamShields[TEAM_ID_SLIPPY] = -2;
            break;

        case LEVEL_MACBETH:
            Macbeth_InitLevel();
            break;

        case LEVEL_ZONESS:
            MEM_ARRAY_ALLOCATE(gZoDodoraPosRots, 200);
            ptr = (u8*) gZoDodoraPosRots;
            for (i = 0; i < 200 * (s32) sizeof(*gZoDodoraPosRots); i++, ptr++) {
                *ptr = 0;
            }
            gZoDodoraWaypointCount = 0;
            /* fallthrough */
        case LEVEL_SOLAR:
            gUseDynaFloor = true;
            gGroundHeight = -20000.0f;
            fptr = MEM_ARRAY_ALLOCATE(D_ctx_801782CC, 17 * 17);
            for (i = 0; i < 17 * 17; i++, fptr++) {
                *fptr = 0.0f;
            }
            fptr = MEM_ARRAY_ALLOCATE(D_ctx_801782D4, 17 * 17);
            for (i = 0; i < 17 * 17; i++, fptr++) {
                *fptr = 0.0f;
            }
            fptr = MEM_ARRAY_ALLOCATE(D_ctx_801782DC, 17 * 17);
            for (i = 0; i < 17 * 17; i++, fptr++) {
                *fptr = 0.0f;
            }
            fptr = MEM_ARRAY_ALLOCATE(D_ctx_801782E4, 17 * 17);
            for (i = 0; i < 17 * 17; i++, fptr++) {
                *fptr = 0.0f;
            }
            fptr = MEM_ARRAY_ALLOCATE(D_ctx_801782EC, 17 * 17);
            for (i = 0; i < 17 * 17; i++, fptr++) {
                *fptr = 0.0f;
            }

            switch (gCurrentLevel) {
                case LEVEL_SOLAR:
                    mesh = SEGMENTED_TO_VIRTUAL(D_SO_6001C50);
                    break;
                case LEVEL_ZONESS:
                    mesh = SEGMENTED_TO_VIRTUAL(D_ZO_6009ED0);
                    break;
            }

            for (i = 0; i < 17 * 17; i++, mesh++) {
                if (mesh->v.ob[0] == 800 * 2) {
                    mesh->v.ob[0] = 1400 * 2;
                }
                if (mesh->v.ob[0] == -800 * 2) {
                    mesh->v.ob[0] = -1400 * 2;
                }
                if (mesh->v.ob[2] == -800 * 2) {
                    mesh->v.ob[2] = -1400 * 2;
                }
            }

            switch (gCurrentLevel) {
                case LEVEL_SOLAR:
                    mesh = SEGMENTED_TO_VIRTUAL(D_SO_6004500);
                    break;
                case LEVEL_ZONESS:
                    mesh = SEGMENTED_TO_VIRTUAL(D_ZO_600C780);
                    break;
            }

            for (i = 0; i < 17 * 17; i++, mesh++) {
                if (mesh->v.ob[0] == 800 * 2) {
                    mesh->v.ob[0] = 1400 * 2;
                }
                if (mesh->v.ob[0] == -800 * 2) {
                    mesh->v.ob[0] = -1400 * 2;
                }
                if (mesh->v.ob[2] == -800 * 2) {
                    mesh->v.ob[2] = -1400 * 2;
                }
            }
            break;
    }
}
#endif

#endif // Global Scope