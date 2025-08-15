#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/PR/gbi.h"
#include "../lib/sf64decomp/include/sf64thread.h"
#include "../lib/sf64decomp/include/sys.h"
#include "rt64_extended_gbi.h"
#include "patches.h"
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_MARGIN 0

void Game_InitFullViewport(void);

#if 1

// TODO: This function crashes the Recompiler.

RECOMP_PATCH void Game_InitViewport(Gfx** dList, u8 camCount, u8 camIndex) {
    OSContPad* cont = &gControllerPress[0];
    static s16 ulx = 0;
    static s16 lrx = 0;
    static s16 vtrans = 0;

    if (cont->button & L_JPAD) {
        ulx -= 10;
    }
    if (cont->button & R_JPAD) {
        ulx += 10;
    }
    if (cont->button & D_JPAD) {
        vtrans -= 10;
    }
    if (cont->button & U_JPAD) {
        vtrans += 10;
    }

    switch (camCount) {
        case 4:
            switch (camIndex) {
                case 0:
                    gViewport->vp.vscale[0] = SCREEN_WIDTH * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] = vtrans;
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;
                    ulx = gViewport->vp.vtrans[0] - gViewport->vp.vscale[0];
                    ulx /=2;
                    lrx = gViewport->vp.vtrans[0] + gViewport->vp.vscale[0];
                    lrx /=2;
                    recomp_printf("ulx : %d\n", ulx);
                    recomp_printf("vtrans : %d\n", vtrans);
                    // gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH / 2,
                    //                SCREEN_HEIGHT / 2);
                    gEXSetScissor((*dList)++, G_SC_NON_INTERLACE, G_EX_ORIGIN_CENTER, G_EX_ORIGIN_CENTER, ulx, 0, lrx,
                                  SCREEN_HEIGHT / 2);
                    gEXViewport((*dList)++, G_EX_ORIGIN_CENTER, gViewport++);
                    break;
                case 1:
                    gViewport->vp.vscale[0] = SCREEN_WIDTH * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] = SCREEN_WIDTH * gVsViewScale * 2;
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0,
                                  0, 0);
                    break;
                case 2:
                    gViewport->vp.vscale[0] = SCREEN_WIDTH * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] = SCREEN_WIDTH * (2.0f - gVsViewScale) * 2;
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * gVsViewScale * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0,
                                  0, 0);
                    break;
                case 3:
                    gViewport->vp.vscale[0] = SCREEN_WIDTH * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] = SCREEN_WIDTH * gVsViewScale * 2;
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * gVsViewScale * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, 0, 0,
                                  0, 0);
                    break;
                default:
                    Game_InitFullViewport();
                    break;
            }
            break;
        case 1:
        default:
            Game_InitFullViewport();
            break;
    }
    // gSPViewport((*dList)++, gViewport++);
}
#endif
