#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/gfx.h"
#include "../lib/sf64decomp/include/PR/mbi.h"
#include "../lib/sf64decomp/include/PR/gbi.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240
#define SCREEN_MARGIN 0 // @recomp

extern FrameBuffer* gFrameBuffer;
extern FrameBuffer gZBuffer;

extern u8 gBlurAlpha;
extern u16 gBgColor;
extern Gfx gRcpInitDL[];

RECOMP_PATCH void Game_InitMasterDL(Gfx** dList) {
    gSPDisplayList((*dList)++, gRcpInitDL);
    gDPSetScissor((*dList)++, G_SC_NON_INTERLACE, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH - SCREEN_MARGIN,
                  SCREEN_HEIGHT - SCREEN_MARGIN);
    gDPSetDepthImage((*dList)++, &gZBuffer);
    gDPSetColorImage((*dList)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, &gZBuffer);
    gDPSetFillColor((*dList)++, FILL_COLOR(GPACK_ZDZ(G_MAXFBZ, 0)));
    gDPFillRectangle((*dList)++, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH - SCREEN_MARGIN - 1,
                     SCREEN_HEIGHT - SCREEN_MARGIN - 1);
    gDPSetColorImage((*dList)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, gFrameBuffer);

    if (gBlurAlpha < 255) {
        gDPPipeSync((*dList)++);
        gDPSetCycleType((*dList)++, G_CYC_1CYCLE);
        gDPSetCombineMode((*dList)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetRenderMode((*dList)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor((*dList)++, 0x00, 0x00, RGBA16_RED(gBgColor) * 8, RGBA16_GRN(gBgColor) * 8,
                        RGBA16_BLU(gBgColor) * 8, gBlurAlpha);
    } else {
        gDPSetFillColor((*dList)++, FILL_COLOR(gBgColor | 1));
    }
    gDPFillRectangle((*dList)++, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH - SCREEN_MARGIN - 1,
                     SCREEN_HEIGHT - SCREEN_MARGIN);
    gDPPipeSync((*dList)++);
    gDPSetColorDither((*dList)++, G_CD_MAGICSQ);
}


