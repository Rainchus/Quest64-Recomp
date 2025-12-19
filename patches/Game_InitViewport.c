#include "patches.h"

void Game_InitFullViewport(void);

#if 1

RECOMP_PATCH void Game_InitViewport(Gfx** dList, u8 camCount, u8 camIndex) {
    static s16 ulx = 0;
    static s16 lrx = 0;

// test code
#if 0
    OSContPad* cont = &gControllerPress[0];
    static s16 vtrans = 0;

    if (cont->button & D_JPAD) {
        ulx -= 10;
    }
    if (cont->button & U_JPAD) {
        ulx += 10;
    }
    if (cont->button & L_JPAD) {
        vtrans -= 10;
    }
    if (cont->button & R_JPAD) {
        vtrans += 10;
    }
#endif

    switch (camCount) {
        case 4:
            switch (camIndex) {
                case 0:
                    gViewport->vp.vscale[0] =
                        (SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2) * recomp_get_target_aspect_ratio(4.0f / 3.0f);
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] =
                        ((SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2) * -recomp_get_target_aspect_ratio(4.0f / 3.0f));
                    gViewport->vp.vtrans[1] = (SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2);
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;

                    ulx = (gViewport->vp.vtrans[0] - gViewport->vp.vscale[0]) / 4;
                    lrx = (gViewport->vp.vtrans[0] + gViewport->vp.vscale[0]) / 4;

#if 1
                    gEXMatrixGroup(gMasterDisp++, 0xFFFFAAAA, G_EX_INTERPOLATE_SIMPLE, G_EX_NOPUSH, G_MTX_PROJECTION,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                   G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP);

                    gEXSetScissor((*dList)++, G_SC_NON_INTERLACE, G_EX_ORIGIN_CENTER, G_EX_ORIGIN_CENTER, ulx, 0, lrx,
                                  SCREEN_HEIGHT / 2);
                    gEXViewport((*dList)++, G_EX_ORIGIN_CENTER, gViewport++);
#else
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0, 0, 0);
#endif
                    break;

                case 1:
                    gViewport->vp.vscale[0] =
                        (SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2) * recomp_get_target_aspect_ratio(4.0f / 3.0f);
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] =
                        (SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2) * recomp_get_target_aspect_ratio(4.0f / 3.0f);
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;

                    ulx = (gViewport->vp.vtrans[0] - gViewport->vp.vscale[0]) / 4;
                    lrx = (gViewport->vp.vtrans[0] + gViewport->vp.vscale[0]) / 4;

#if 1
                    gEXMatrixGroup(gMasterDisp++, 0xFFFFAAAB, G_EX_INTERPOLATE_SIMPLE, G_EX_NOPUSH, G_MTX_PROJECTION,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                   G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP);

                    gEXSetScissor((*dList)++, G_SC_NON_INTERLACE, G_EX_ORIGIN_CENTER, G_EX_ORIGIN_CENTER, ulx, 0, lrx,
                                  SCREEN_HEIGHT / 2);
                    gEXViewport((*dList)++, G_EX_ORIGIN_CENTER, gViewport++);
#else
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0, 0, 0);
#endif
                    break;

                case 2:
                    gViewport->vp.vscale[0] =
                        (SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2) * recomp_get_target_aspect_ratio(4.0f / 3.0f);
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] =
                        ((SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2) * -recomp_get_target_aspect_ratio(4.0f / 3.0f));
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * gVsViewScale * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;

                    ulx = (gViewport->vp.vtrans[0] - gViewport->vp.vscale[0]) / 4;
                    lrx = (gViewport->vp.vtrans[0] + gViewport->vp.vscale[0]) / 4;
#if 1
                    gEXMatrixGroup(gMasterDisp++, 0xFFFFAAAC, G_EX_INTERPOLATE_SIMPLE, G_EX_NOPUSH, G_MTX_PROJECTION,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                   G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP);

                    gEXSetScissor((*dList)++, G_SC_NON_INTERLACE, G_EX_ORIGIN_CENTER, G_EX_ORIGIN_CENTER, ulx,
                                  SCREEN_HEIGHT / 2, lrx, SCREEN_HEIGHT);
                    gEXViewport((*dList)++, G_EX_ORIGIN_CENTER, gViewport++);

#else
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0, 0, 0);
#endif
                    break;

                case 3:
                    gViewport->vp.vscale[0] =
                        (SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2) * recomp_get_target_aspect_ratio(4.0f / 3.0f);
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] =
                        (SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2) * recomp_get_target_aspect_ratio(4.0f / 3.0f);
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * gVsViewScale * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;

                    ulx = (gViewport->vp.vtrans[0] - gViewport->vp.vscale[0]) / 4;
                    lrx = (gViewport->vp.vtrans[0] + gViewport->vp.vscale[0]) / 4;

#if 1
                    gEXMatrixGroup(gMasterDisp++, 0xFFFFAAAC, G_EX_INTERPOLATE_SIMPLE, G_EX_NOPUSH, G_MTX_PROJECTION,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                   G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP);

                    gEXSetScissor((*dList)++, G_SC_NON_INTERLACE, G_EX_ORIGIN_CENTER, G_EX_ORIGIN_CENTER, ulx,
                                  SCREEN_HEIGHT / 2, lrx, SCREEN_HEIGHT);
                    gEXViewport((*dList)++, G_EX_ORIGIN_CENTER, gViewport++);
#else
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0, 0, 0);
#endif
                    break;

                default:
                    Game_InitFullViewport();
                    break;
            }

// Test code
#if 0
            recomp_printf("gViewport->vp.vtrans[0] : %d\n", gViewport->vp.vtrans[0]);
            recomp_printf("gViewport->vp.vscale[0] : %d\n", gViewport->vp.vscale[0]);

            recomp_printf("ulx : %d lrx : %d uly : %d lry : %d\n", ulx, lrx, uly, lry);
            recomp_printf("vtrans : %d\n", vtrans);
#endif
            break;

        case 1:
        default:
            Game_InitFullViewport();
            gSPViewport((*dList)++, gViewport++);
            break;
    }
    // gSPViewport((*dList)++, gViewport++);
}
#endif

#if 0
extern s32 sVsSavedBombCount[4];
extern s32 sVsBombCountFlashTimer[4];
extern f32 D_800D21A4;
extern f32 D_800D21A0;
void HUD_VS_BombIcon_Draw(f32 xPos, f32 yPos, f32 xScale, f32 yScale);

RECOMP_PATCH void HUD_VS_BombCount_Draw(void) {
    s32 bombIconXpos[] = { 146, 165, 146, 165 };
    s32 bombIconYpos[] = { 94, 94, 137, 137 };

    gBombCount[0] = 4;

    if (gBombCount[gPlayerNum] != sVsSavedBombCount[gPlayerNum]) {
        sVsSavedBombCount[gPlayerNum] = gBombCount[gPlayerNum];
        if (gBombCount[gPlayerNum] == 0) {
            sVsBombCountFlashTimer[gPlayerNum] = 0;
        } else {
            sVsBombCountFlashTimer[gPlayerNum] = 30;
        }
    }

    if (sVsBombCountFlashTimer[gPlayerNum] != 0) {
        sVsBombCountFlashTimer[gPlayerNum]--;
    }

    if (((sVsBombCountFlashTimer[gPlayerNum] & 2) != 0) ||
        ((sVsBombCountFlashTimer[gPlayerNum] == 0) && (gBombCount[gPlayerNum] != 0))) {
        RCP_SetupDL_78();
        if (gBombCount[gPlayerNum] >= 2) {
            if (Math_SmoothStepToF(&D_800D21A4, D_800D21A0, 0.4f, 100.0f, 0.1f) == 0.0f) {
                if (D_800D21A0 == 255.0f) {
                    D_800D21A0 = 96.0f;
                } else {
                    D_800D21A0 = 255.0f;
                }
            }
        } else {
            D_800D21A4 = 255.0f;
        }
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, D_800D21A4);

        f32 xPos = bombIconXpos[gPlayerNum];// * -recomp_get_target_aspect_ratio(4.0f/3.0f);

        HUD_VS_BombIcon_Draw(xPos, bombIconYpos[gPlayerNum], 1.0f, 1.0f);
    }
}
#endif