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
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST);

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
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST);

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
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST);

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
                                   G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE, G_EX_ASPECT_ADJUST);

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
