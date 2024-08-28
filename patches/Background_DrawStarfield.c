#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define __sinf __sinf_recomp
#define __cosf __cosf_recomp
#if 0
#include "PR/ultratypes.h"
#include "context.h"
#include "PR/gbi.h"

extern f32 __sinf(f32);
extern f32 __cosf(f32);

RECOMP_PATCH void Background_DrawStarfield(void) {
    f32 by;
    f32 bx;
    s16 vy;
    s16 vx;
    s32 i;
    s32 starCount;
    f32 zCos;
    f32 zSin;
    f32 xField;
    f32 yField;
    f32* xStar;
    f32* yStar;
    u32* color;

    gDPPipeSync(gMasterDisp++);
    gDPSetCycleType(gMasterDisp++, G_CYC_FILL);
    gDPSetCombineMode(gMasterDisp++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gMasterDisp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    starCount = gStarCount;
    if (starCount != 0) {
        if (gStarfieldX >= 1.5f * SCREEN_WIDTH) {
            gStarfieldX -= 1.5f * SCREEN_WIDTH;
        }
        if (gStarfieldY >= 1.5f * SCREEN_HEIGHT) {
            gStarfieldY -= 1.5f * SCREEN_HEIGHT;
        }
        if (gStarfieldX < 0.0f) {
            gStarfieldX += 1.5f * SCREEN_WIDTH;
        }
        if (gStarfieldY < 0.0f) {
            gStarfieldY += 1.5f * SCREEN_HEIGHT;
        }
        xField = gStarfieldX;
        yField = gStarfieldY;

        xStar = gStarOffsetsX;
        yStar = gStarOffsetsY;
        color = gStarFillColors;

        if (gGameState != GSTATE_PLAY) {
            starCount = 1000;
        }
        
        zCos = __cosf(gStarfieldRoll);
        zSin = __sinf(gStarfieldRoll);

        for (i = 0; i < starCount; i++, yStar++, xStar++, color++) {
            bx = *xStar + xField;
            by = *yStar + yField;
            if (bx >= 1.25f * SCREEN_WIDTH) {
                bx -= 1.5f * SCREEN_WIDTH;
            }
            bx -= SCREEN_WIDTH / 2.0f;

            if (by >= 1.25f * SCREEN_HEIGHT) {
                by -= 1.5f * SCREEN_HEIGHT;
            }
            by -= SCREEN_HEIGHT / 2.0f;

            vx = (zCos * bx) + (zSin * by) + SCREEN_WIDTH / 2.0f;
            vy = (-zSin * bx) + (zCos * by) + SCREEN_HEIGHT / 2.0f;
            if ((vx >= 0) && (vx < SCREEN_WIDTH) && (vy > 0) && (vy < SCREEN_HEIGHT)) {
                gDPPipeSync(gMasterDisp++);
                gDPSetFillColor(gMasterDisp++, *color);
                gDPFillRectangle(gMasterDisp++, vx, vy, vx, vy);
            }
        }
    }
    gDPPipeSync(gMasterDisp++);
    gDPSetColorDither(gMasterDisp++, G_CD_MAGICSQ);
}
#endif