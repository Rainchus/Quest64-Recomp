#include "patches.h"

#define MEM_ARRAY_ALLOCATE(arr, count) ((arr) = Memory_Allocate((count) * sizeof(*(arr))))

#if 1 // NEW STARFIELD TESTING

// Define constants for starfield multipliers
#define STARFIELD_WIDTH_MULTIPLIER 1.0f
#define STARFIELD_HEIGHT_MULTIPLIER 1.0f

// Declare global variables for screen dimensions
float gCurrentScreenWidth = 320.0f * 3;  // Default width
float gCurrentScreenHeight = 240.0f * 3; // Default height

// Function to set the current screen dimensions
void SetCurrentScreenDimensions(float width, float height) {
    gCurrentScreenWidth = width;
    gCurrentScreenHeight = height;
}

// Function to get the current screen width
float GetCurrentScreenWidth() {
    return gCurrentScreenWidth;
}

// Function to get the current screen height
float GetCurrentScreenHeight() {
    return gCurrentScreenHeight;
}

// Custom floating-point modulo function (replaces fmodf)
float FloatMod(float a, float b) {
    float result = a - ((int) (a / b)) * b;
    if (result < 0.0f) {
        result += b;
    }
    return result;
}

// Call this function to initialize the starfield
void InitializeStarfield(void) {
    // Set the desired screen dimensions (modify as needed)
    SetCurrentScreenDimensions(320.0f, 240.0f); // Example: 1280x720 resolution

    // Set up the starfield
    Play_SetupStarfield();
}

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

    // Get current screen dimensions
    float currentScreenWidth = GetCurrentScreenWidth();
    float currentScreenHeight = GetCurrentScreenHeight();
    float starfieldWidth = STARFIELD_WIDTH_MULTIPLIER * currentScreenWidth;
    float starfieldHeight = STARFIELD_HEIGHT_MULTIPLIER * currentScreenHeight;

    // Graphics pipeline setup
    gDPPipeSync(gMasterDisp++);
    gDPSetCycleType(gMasterDisp++, G_CYC_FILL);
    gDPSetCombineMode(gMasterDisp++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gMasterDisp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    starCount = gStarCount;

    if (starCount != 0) {
        // Wrapping logic for starfield positions
        if (gStarfieldX >= starfieldWidth) {
            gStarfieldX -= starfieldWidth;
        }
        if (gStarfieldY >= starfieldHeight) {
            gStarfieldY -= starfieldHeight;
        }
        if (gStarfieldX < 0.0f) {
            gStarfieldX += starfieldWidth;
        }
        if (gStarfieldY < 0.0f) {
            gStarfieldY += starfieldHeight;
        }
        xField = gStarfieldX;
        yField = gStarfieldY;

        xStar = gStarOffsetsX;
        yStar = gStarOffsetsY;
        color = gStarFillColors;

        if (gGameState != GSTATE_PLAY) {
            starCount = 1000;
        }

        starCount = starCount * 3; // multiplying has no effect for aditional stars for some reason.

        zCos = __cosf(gStarfieldRoll);
        zSin = __sinf(gStarfieldRoll);
        for (i = 0; i < starCount; i++, yStar++, xStar++, color++) {
            // Adjust star positions with field offsets
            bx = *xStar + xField;
            by = *yStar + yField;

            // Wrapping logic for individual stars along X-axis
            if (bx >= starfieldWidth) {
                bx -= starfieldWidth;
            }
            if (bx < 0.0f) {
                bx += starfieldWidth;
            }

            // Wrapping logic for individual stars along Y-axis
            if (by >= starfieldHeight) {
                by -= starfieldHeight;
            }
            if (by < 0.0f) {
                by += starfieldHeight;
            }

            // Center the positions
            bx -= starfieldWidth / 2.0f;
            by -= starfieldHeight / 2.0f;

            // Apply rotation
            vx = (zCos * bx) + (zSin * by) + currentScreenWidth / 2.0f;
            vy = (-zSin * bx) + (zCos * by) + currentScreenHeight / 2.0f;

            // Check if the star is within the visible screen area
            if ((vx >= 0) && (vx < currentScreenWidth) && (vy >= 0) && (vy < currentScreenHeight)) {
                gDPPipeSync(gMasterDisp++);
                gDPSetFillColor(gMasterDisp++, *color);
                // gDPFillRectangle(gMasterDisp++, vx, vy, vx, vy);
                gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, -SCREEN_WIDTH * 4,
                                -SCREEN_HEIGHT * 4, -SCREEN_WIDTH * 4, -SCREEN_HEIGHT * 4);
                gDPFillRectangle(gMasterDisp++, vx, vy, vx, vy);
                gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
            }
        }
    }
    gDPPipeSync(gMasterDisp++);
    gDPSetColorDither(gMasterDisp++, G_CD_MAGICSQ);
}

RECOMP_PATCH void Play_GenerateStarfield(void) {
    u32 i;
    float currentScreenWidth = GetCurrentScreenWidth();
    float currentScreenHeight = GetCurrentScreenHeight();
    float starfieldWidth = STARFIELD_WIDTH_MULTIPLIER * currentScreenWidth;
    float starfieldHeight = STARFIELD_HEIGHT_MULTIPLIER * currentScreenHeight;

    MEM_ARRAY_ALLOCATE(gStarOffsetsX, 3000);
    MEM_ARRAY_ALLOCATE(gStarOffsetsY, 3000);
    MEM_ARRAY_ALLOCATE(gStarFillColors, 3000);

    Rand_SetSeed(1, 29000, 9876);

    for (i = 0; i < 3000; i++) {
        gStarOffsetsX[i] = RAND_FLOAT_SEEDED(starfieldWidth);
        gStarOffsetsY[i] = RAND_FLOAT_SEEDED(starfieldHeight);
        gStarFillColors[i] = FILL_COLOR(gStarColors[i % ARRAY_COUNT(gStarColors)]);
    }
}

RECOMP_PATCH void Camera_SetStarfieldPos(f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt) {
    f32 sp34;
    f32 sp30;
    f32 pitch;
    f32 yaw;
    f32 tempf;
    f32 sp20;

    // Get current screen dimensions
    float currentScreenWidth = GetCurrentScreenWidth();
    float currentScreenHeight = GetCurrentScreenHeight();
    float starfieldWidth = STARFIELD_WIDTH_MULTIPLIER * currentScreenWidth;
    float starfieldHeight = STARFIELD_HEIGHT_MULTIPLIER * currentScreenHeight;

    yaw = -Math_Atan2F(xEye - xAt, zEye - zAt);
    tempf = sqrtf(SQ(zEye - zAt) + SQ(xEye - xAt));
    pitch = -Math_Atan2F(yEye - yAt, tempf);

    // Adjust yaw to stay within the range [-π/2, π/2]
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

    // Calculate new starfield positions
    sp30 = (-pitch * (-8.0f / 3.0f * M_RTOD) * 2.0f) + 3000.0f + gStarfieldScrollY + tempf;
    sp34 = (yaw * (-8.0f / 3.0f * M_RTOD) * 2.0f) + 3000.0f + gStarfieldScrollX;
    sp20 = gStarfieldX;

    // Wrap the starfield positions within the starfield dimensions
    gStarfieldX = FloatMod(sp34, starfieldWidth);
    gStarfieldY = FloatMod(sp30, starfieldHeight);

    // Special case handling for specific game state and level
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

RECOMP_PATCH void Play_SetupStarfield(void) {
    // Get current screen dimensions
    float currentScreenWidth = GetCurrentScreenWidth();
    float currentScreenHeight = GetCurrentScreenHeight();
    float baseAspectRatio = 4.0f / 3.0f; // Original aspect ratio
    float baseScreenWidth = gCurrentScreenHeight * baseAspectRatio;
    float baseArea = baseScreenWidth * gCurrentScreenHeight;
    float currentArea = currentScreenWidth * currentScreenHeight;
    float areaRatio = currentArea / baseArea;

    Play_GenerateStarfield();
    gGroundHeight = -25000.0f;

    // Base star count adjusted for screen area
    gStarCount = (s32) (600 * areaRatio);
    if (gStarCount > 1000) {
        gStarCount = 1000; // Cap the star count to 1000
    }

    // Adjust star count based on the current level
    if (gCurrentLevel == LEVEL_AREA_6) {
        gStarCount = (s32) (300 * areaRatio);
        if (gStarCount > 1000) {
            gStarCount = 1000;
        }
    }
    if (gCurrentLevel == LEVEL_UNK_15) {
        gStarCount = (s32) (400 * areaRatio);
        if (gStarCount > 1000) {
            gStarCount = 1000;
        }
    }
    if (gGameState != GSTATE_PLAY) {
        gStarCount = (s32) (800 * areaRatio);
        if (gStarCount > 1000) {
            gStarCount = 1000;
        }
    }
    if (gCurrentLevel == LEVEL_FORTUNA) {
        gStarCount = (s32) (500 * areaRatio);
        if (gStarCount > 1000) {
            gStarCount = 1000;
        }
    }
    if (gVersusMode) {
        gStarCount = 0; // No stars in versus mode
    }
    if (gCurrentLevel == LEVEL_BOLSE) {
        gStarCount = (s32) (300 * areaRatio);
        if (gStarCount > 1000) {
            gStarCount = 1000;
        }
        gGroundHeight = -0.0f;
    }
    if (gCurrentLevel == LEVEL_TRAINING) {
        gStarCount = (s32) (800 * areaRatio);
        if (gStarCount > 1000) {
            gStarCount = 1000;
        }
        gGroundHeight = -0.0f;
    }

    // Initialize starfield position with dynamic screen dimensions
    gStarfieldX = currentScreenWidth;
    gStarfieldY = currentScreenHeight;
}

#if 1                                                                   // Background_DrawPartialStarfield
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

#endif // End of NEW STARFIELD TESTING block