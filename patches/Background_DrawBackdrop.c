// TODO: This patch doesn't work at all, the background doesn't get drawn even though the function is the same straight from the decomp
#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#if 0
#define __sinf __sinf_recomp

#include "PR/ultratypes.h"
#include "PR/gbi.h"
#include "gfx.h"
#include "sf64math.h"
#include "context.h"
#include "patches.h"

extern u8 gDrawBackdrop;
extern Gfx D_versus_302D4D0[];
extern Gfx D_CO_60059F0[];
extern Gfx D_versus_30146B0[];
extern Gfx D_versus_3011E40[];
extern Gfx D_FO_600D9F0[];
extern Gfx D_KA_600F1D0[];
extern Gfx D_VE2_600F670[];
extern Gfx D_VE1_60046F0[];
extern Gfx D_AQ_601C080[];
extern Gfx D_AQ_601AFF0[];
extern Gfx D_VE2_60038E0[];
extern Gfx D_ANDROSS_C039208[];
extern Gfx D_ZO_6013480[];
extern Gfx D_TI_6000A80[];
extern Gfx D_MA_6019220[];
extern Gfx D_SO_601E150[];
extern Gfx D_WZ_7001540[];
extern Gfx D_ME_600DDF0[];
extern Gfx D_SX_6029890[];
extern Gfx D_TR_6003760[];
extern Gfx D_A6_601BB40[];
extern Gfx D_FO_600B4B0[];
extern Gfx D_BO_600D190[];
extern Gfx D_SY_6001840[];
extern Gfx D_edisplay_800CFD80[];
extern f32 gAndrossUnkBrightness;
extern f32 gAndrossUnkAlpha;
extern f32 D_bg_8015F968;
extern f32 gWarpZoneBgAlpha;
extern f32 D_bg_8015F984;
extern Gfx aSzBackgroundDL[];
extern f32 __sinf(f32);

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
                    Matrix_Translate(gGfxMatrix, sp13C, -2000.0f + sp134, -6000.0f, MTXF_APPLY);

                    if (gCurrentLevel == LEVEL_FORTUNA) {
                        Matrix_Translate(gGfxMatrix, 0.0f, -2000.0f, 0, MTXF_APPLY);
                    } else if (gCurrentLevel == LEVEL_KATINA) {
                        Matrix_Translate(gGfxMatrix, 0.0f, -2500.0f, 0, MTXF_APPLY);
                    }
                    Matrix_SetGfxMtx(&gMasterDisp);

                    switch ((s32)gCurrentLevel) {
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
                    Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    switch ((s32)gCurrentLevel) {
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
                    break;

                case LEVEL_CORNERIA:
                case LEVEL_VENOM_1:
                    sp134 = (gPlayer[gPlayerNum].camPitch * -6000.0f) - (gPlayer[gPlayerNum].cam.eye.y * 0.6f);
                    sp13C = Math_ModF(Math_RadToDeg(gPlayer[gPlayerNum].camYaw) * (-7280.0f / 360.0f) * 5.0f, 7280.0f);
                    Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                    Matrix_Translate(gGfxMatrix, sp13C, -2000.0f + sp134, -6000.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    switch ((s32)gCurrentLevel) {
                        case LEVEL_CORNERIA:
                            gSPDisplayList(gMasterDisp++, D_CO_60059F0);
                            break;
                        case LEVEL_VENOM_1:
                            gSPDisplayList(gMasterDisp++, D_VE1_60046F0);
                            break;
                    }

                    Matrix_Translate(gGfxMatrix, 7280.0f, 0.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    switch ((s32)gCurrentLevel) {
                        case LEVEL_CORNERIA:
                            gSPDisplayList(gMasterDisp++, D_CO_60059F0);
                            break;
                        case LEVEL_VENOM_1:
                            gSPDisplayList(gMasterDisp++, D_VE1_60046F0);
                            break;
                    }
                    break;

                case LEVEL_VENOM_ANDROSS:
                    if (gDrawBackdrop != 6) {
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
                            Matrix_RotateZ(gGfxMatrix, gPlayer[gPlayerNum].camRoll * M_DTOR, MTXF_APPLY);
                            Matrix_Translate(gGfxMatrix, sp13C, -2000.0f + sp134, -6000.0f, MTXF_APPLY);
                            Matrix_Translate(gGfxMatrix, 0.0f, -2500.0f, 0.0f, MTXF_APPLY);
                            Matrix_SetGfxMtx(&gMasterDisp);
                            gSPDisplayList(gMasterDisp++, D_VE2_60038E0);
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
                        Matrix_Push(&gGfxMatrix);
                        Matrix_Translate(gGfxMatrix, sp13C, sp134, -7000.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);

                        if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) {
                            gSPDisplayList(gMasterDisp++, D_AQ_601AFF0);
                        } else {
                            gSPDisplayList(gMasterDisp++, D_AQ_601C080);
                        }

                        if (sp13C < 0) {
                            sp13C = 1.0f;
                        } else {
                            sp13C = -1.0f;
                        }
                        Matrix_Translate(gGfxMatrix, 7280.0f * sp13C, 0.0f, 0.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);
                        if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) {
                            gSPDisplayList(gMasterDisp++, D_AQ_601AFF0);

                        } else {
                            gSPDisplayList(gMasterDisp++, D_AQ_601C080);
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

                    if ((gCurrentLevel == LEVEL_TITANIA) || (gCurrentLevel == LEVEL_ZONESS)) {
                        Matrix_Translate(gGfxMatrix, sp13C, -3000.0f + sp134, -7000.0f, MTXF_APPLY);
                    } else if (gCurrentLevel == LEVEL_SOLAR) {
                        Matrix_Translate(gGfxMatrix, sp13C, -3500.0f + sp134, -7000.0f, MTXF_APPLY);
                    } else if (gCurrentLevel == LEVEL_MACBETH) {
                        Matrix_Translate(gGfxMatrix, sp13C, -4000.0f + sp134, -7000.0f, MTXF_APPLY);
                    }
                    Matrix_SetGfxMtx(&gMasterDisp);

                    if (gCurrentLevel == LEVEL_TITANIA) {
                        gSPDisplayList(gMasterDisp++, D_TI_6000A80);
                    } else if (gCurrentLevel == LEVEL_MACBETH) {
                        gSPDisplayList(gMasterDisp++, D_MA_6019220);
                    } else if (gCurrentLevel == LEVEL_ZONESS) {
                        gSPDisplayList(gMasterDisp++, D_ZO_6013480);
                    } else if (gCurrentLevel == LEVEL_SOLAR) {
                        gSPDisplayList(gMasterDisp++, D_SO_601E150);
                    }
                    if (sp13C < 0) {
                        sp13C = 1.0f;
                    } else {
                        sp13C = -1.0f;
                    }
                    Matrix_Translate(gGfxMatrix, 7280.0f * sp13C, 0.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    if (gCurrentLevel == LEVEL_TITANIA) {
                        gSPDisplayList(gMasterDisp++, D_TI_6000A80);
                    } else if (gCurrentLevel == LEVEL_MACBETH) {
                        gSPDisplayList(gMasterDisp++, D_MA_6019220);
                    } else if (gCurrentLevel == LEVEL_ZONESS) {
                        gSPDisplayList(gMasterDisp++, D_ZO_6013480);
                    } else if (gCurrentLevel == LEVEL_SOLAR) {
                        gSPDisplayList(gMasterDisp++, D_SO_601E150);
                    }
                    break;
            }
            break;

        case LEVELTYPE_SPACE:
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
                for (i = 0; i < 300; i++, xStar++, yStar++) {
                    *xStar = RAND_FLOAT_SEEDED(480.0f) - 80.0f;
                    *yStar = RAND_FLOAT_SEEDED(360.0f) - 60.0f;
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, (*xStar - 160.0f) * 10.0f, (*yStar - 120.0f) * 10.0f, -5000.0f,
                                     MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, zRot, MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, 10.0f, 1.0f, -gStarWarpDistortion, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_edisplay_800CFD80);
                    Matrix_Pop(&gGfxMatrix);
                    zRot += M_PI / 4;
                }
            }
            break;
    }
    Matrix_Pop(&gGfxMatrix);
}
#endif