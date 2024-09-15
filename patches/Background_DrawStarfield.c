#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define __sinf __sinf_recomp
#define __cosf __cosf_recomp
#define MEM_ARRAY_ALLOCATE(arr, count) ((arr) = Memory_Allocate((count) * sizeof(*(arr))))


#if 1 // Full scope

#include "PR/ultratypes.h"
#include "context.h"
#include "PR/gbi.h"
#include "rt64_extended_gbi.h"
#include "patches.h"

extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern f32 D_bg_8015F96C;

f32 xScale = 2.0f;  // Apply a scaling factor for X-axis expansion

#if 1 // Background_DrawStarfield

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


    // Set up the scissor area for clipping the rendering

    gDPPipeSync(gMasterDisp++);
    gDPSetCycleType(gMasterDisp++, G_CYC_FILL);
    gDPSetCombineMode(gMasterDisp++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gMasterDisp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    
    starCount = gStarCount;
    if (starCount != 0) {
        if (gStarfieldX >= 480) {
            gStarfieldX -= 480;
        }
        if (gStarfieldY >= 360) {
            gStarfieldY -= 360;
        }
        if (gStarfieldX < 0.0f) {
            gStarfieldX += 480;
        }
        if (gStarfieldY < 0.0f) {
            gStarfieldY += 360;
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
            bx = (*xStar + xField) * xScale;
            by = *yStar + yField;

            if (bx >= 400 * xScale) {
                bx -= 480 * xScale;
            }
            bx -= 160 * xScale;

            if (by >= 300) {
                by -= 360;
            }
            by -= 120;

            vx = (zCos * bx) + (zSin * by) + 160;
            vy = (-zSin * bx) + (zCos * by) + 120;

            // Star rendering logic remains the same
            if ((vx >= 0) && (vx < 320 * xScale) && (vy > 0) && (vy < 240)) {
                gDPPipeSync(gMasterDisp++);
                gDPSetFillColor(gMasterDisp++, *color);
                gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, -SCREEN_WIDTH * xScale, 0, -SCREEN_WIDTH* xScale, 0);
                gDPFillRectangle(gMasterDisp++, vx, vy, vx, vy);
                gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
            }
        }
    }
    gDPPipeSync(gMasterDisp++);
    gDPSetColorDither(gMasterDisp++, G_CD_MAGICSQ);
    
}

#endif

#if 1 // Camera_SetStarfieldPos

RECOMP_PATCH void Camera_SetStarfieldPos(f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt) {
    f32 sp34;
    f32 sp30;
    f32 pitch;
    f32 yaw;
    f32 tempf;
    f32 sp20;

    yaw = -Math_Atan2F(xEye - xAt, zEye - zAt);
    tempf = sqrtf(SQ(zEye - zAt) + SQ(xEye - xAt));
    pitch = -Math_Atan2F(yEye - yAt, tempf);
    if (yaw >= M_PI / 2) {
        yaw -= M_PI;
    }
    if (yaw <= -M_PI / 2) {
        yaw += M_PI;
    }

    tempf = 0.0f;
    if (gCurrentLevel == LEVEL_UNK_15) {
        tempf = gPlayer[0].cam.eye.y * 0.03f;
    }

    sp30 = (-pitch * (-8.0f / 3.0f * M_RTOD) * 2.0f) + 3000.0f + gStarfieldScrollY + tempf;
    sp34 = (yaw * (-8.0f / 3.0f * M_RTOD) * 2.0f) + (3000.0f + gStarfieldScrollX) / xScale;
    sp20 = gStarfieldX;

    gStarfieldX = Math_ModF(sp34, SCREEN_WIDTH * 1.5f);
    gStarfieldY = Math_ModF(sp30, SCREEN_HEIGHT * 1.5f);

    if ((gGameState == GSTATE_PLAY) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) &&
        (gCurrentLevel == LEVEL_METEO)) {
        if (fabsf(gStarfieldX - sp20) < 50.0f) {
            D_bg_8015F96C = 0.0f;
            if (fabsf(gStarfieldX - sp20) > 3.0f) {
                D_bg_8015F96C = fabsf(gStarfieldX - sp20 - 3.0f) * 0.5f;
            }
        }
    }
}
#endif

#if 1 // Play_GenerateStarfield

RECOMP_PATCH void Play_GenerateStarfield(void) {
    u32 i;


MEM_ARRAY_ALLOCATE(gStarOffsetsX, 1000);
MEM_ARRAY_ALLOCATE(gStarOffsetsY, 1000);   
MEM_ARRAY_ALLOCATE(gStarFillColors, 1000);

    Rand_SetSeed(1, 29000, 9876);

   for (i = 0; i < 1000; i++) {
        gStarOffsetsX[i] = RAND_FLOAT_SEEDED(480.0f) - 80.0f;
        gStarOffsetsY[i] = RAND_FLOAT_SEEDED(360.0f) - 60.0f;
        gStarFillColors[i] = FILL_COLOR(gStarColors[i % ARRAY_COUNT(gStarColors)]);
    }
}
#endif

#if 1 // Background_DrawPartialStarfield
RECOMP_PATCH void Background_DrawPartialStarfield(s32 yMin, s32 yMax) { // Stars that are in the Epilogue
    f32 by;
    f32 bx;
    s16 vy;
    s16 vx;
    s32 i;
    s32 var_s2;
    f32 cos;
    f32 sin;
    f32 spf68;
    f32 spf64;
    f32* sp60;
    f32* sp5C;
    u32* sp58;

    gDPPipeSync(gMasterDisp++);
    gDPSetCycleType(gMasterDisp++, G_CYC_FILL);
    gDPSetCombineMode(gMasterDisp++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gMasterDisp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

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

    spf68 = gStarfieldX;
    spf64 = gStarfieldY;

    sp60 = gStarOffsetsX;
    sp5C = gStarOffsetsY;
    sp58 = gStarFillColors;
    var_s2 = 500;

    cos = __cosf(gStarfieldRoll);
    sin = __sinf(gStarfieldRoll);
    for (i = 0; i < var_s2; i++, sp5C++, sp60++, sp58++) {
        bx = *sp60 + spf68;
        by = *sp5C + spf64;
        if (bx >= SCREEN_WIDTH * 1.25f) {
            bx -= 1.5f * SCREEN_WIDTH;
        }
        bx -= SCREEN_WIDTH / 2.0f;
        if (by >= SCREEN_HEIGHT * 1.25f) {
            by -= 1.5f * SCREEN_HEIGHT;
        }
        by -= SCREEN_HEIGHT / 2.0f;

        vx = (cos * bx) + (sin * by) + SCREEN_WIDTH / 2.0f;
        vy = (-sin * bx) + (cos * by) + SCREEN_HEIGHT / 2.0f;
        if ((vx >= 0) && (vx < SCREEN_WIDTH) && (yMin < vy) && (vy < yMax)) {
            gDPPipeSync(gMasterDisp++);
            gDPSetFillColor(gMasterDisp++, *sp58);
            gDPFillRectangle(gMasterDisp++, vx, vy, vx, vy);
        }
    }
    gDPPipeSync(gMasterDisp++);
    gDPSetColorDither(gMasterDisp++, G_CD_MAGICSQ);
}
#endif

#if 0// Background_DrawStarfield TESTING

extern void* alloc_display_list(int size);

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

    Mtx projectionMtx;  // Static allocation for the projection matrix

    // Set up the scissor area for clipping the rendering
    gDPPipeSync(gMasterDisp++);
    gDPSetCycleType(gMasterDisp++, G_CYC_FILL);
    gDPSetCombineMode(gMasterDisp++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gMasterDisp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    // Set up the orthographic projection matrix for the viewport
    guOrtho(&projectionMtx, -160, 160, -120, 120, -1000, 1000, 1.0f);
    gSPMatrix(gMasterDisp++, &projectionMtx, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

    starCount = gStarCount;
    if (starCount != 0) {
        if (gStarfieldX >= 480) {
            gStarfieldX -= 480;
        }
        if (gStarfieldY >= 360) {
            gStarfieldY -= 360;
        }
        if (gStarfieldX < 0.0f) {
            gStarfieldX += 480;
        }
        if (gStarfieldY < 0.0f) {
            gStarfieldY += 360;
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
            bx = (*xStar + xField) * xScale;
            by = *yStar + yField;

            if (bx >= 400 * xScale) {
                bx -= 480 * xScale;
            }
            bx -= 160 * xScale;

            if (by >= 300) {
                by -= 360;
            }
            by -= 120;

            vx = (zCos * bx) + (zSin * by) + 160;
            vy = (-zSin * bx) + (zCos * by) + 120;

            // Star rendering logic with ortho viewport
            if ((vx >= -160) && (vx < 160) && (vy > -120) && (vy < 120)) {
                Vtx starVtx[1];  // Use a local array (stack-allocated) for a single vertex

                starVtx[0].v.ob[0] = vx;
                starVtx[0].v.ob[1] = vy;
                starVtx[0].v.ob[2] = 0;
                starVtx[0].v.flag = 0;
                starVtx[0].v.tc[0] = 0;
                starVtx[0].v.tc[1] = 0;
                starVtx[0].v.cn[0] = (*color >> 24) & 0xFF;
                starVtx[0].v.cn[1] = (*color >> 16) & 0xFF;
                starVtx[0].v.cn[2] = (*color >> 8) & 0xFF;
                starVtx[0].v.cn[3] = *color & 0xFF;

                gSPVertex(gMasterDisp++, starVtx, 1, 0);
                gSP1Triangle(gMasterDisp++, 0, 0, 0, 0);  // Draw point
            }
        }
    }

    // End rendering
    gDPPipeSync(gMasterDisp++);
    gDPSetColorDither(gMasterDisp++, G_CD_MAGICSQ);
}

#endif

#endif
