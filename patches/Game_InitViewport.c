#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/PR/gbi.h"
#include "../lib/sf64decomp/include/sf64thread.h"
#include "../lib/sf64decomp/include/sys.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240
#define SCREEN_MARGIN 0

void Game_InitFullViewport(void);

/*

TODO: This function crashes the Recompiler.

RECOMP_PATCH void Game_InitViewport(Gfx** dList, u8 camCount, u8 camIndex) {
    switch (camCount) {
        case 4:
            switch (camIndex) {
                case 0:
                    gViewport->vp.vscale[0] = SCREEN_WIDTH * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[1] = SCREEN_HEIGHT * (gVsViewScale - 1.0f) * 2;
                    gViewport->vp.vscale[2] = G_MAXZ / 2;
                    gViewport->vp.vscale[3] = 0;
                    gViewport->vp.vtrans[0] = SCREEN_WIDTH * (2.0f - gVsViewScale) * 2;
                    gViewport->vp.vtrans[1] = SCREEN_HEIGHT * (2.0f - gVsViewScale) * 2;
                    gViewport->vp.vtrans[2] = G_MAXZ / 2;
                    gViewport->vp.vtrans[3] = 0;
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH / 2,
                                  SCREEN_HEIGHT / 2);
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
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, SCREEN_WIDTH / 2, SCREEN_MARGIN,
                                  SCREEN_WIDTH - SCREEN_MARGIN, SCREEN_HEIGHT / 2);
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
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, SCREEN_MARGIN, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2,
                                  SCREEN_HEIGHT - SCREEN_MARGIN);
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
                    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
                                  SCREEN_WIDTH - SCREEN_MARGIN, SCREEN_HEIGHT - SCREEN_MARGIN);
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
    gSPViewport((*dList)++, gViewport++);
}

*/