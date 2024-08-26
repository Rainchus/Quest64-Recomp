#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/gfx.h"
#include "../lib/sf64decomp/include/context.h"

typedef struct AssetInfo {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ Vec3f unk_30;
    /* 0x3C */ Vec3f unk_3C;
    /* 0x48 */ Vec3f unk_48;
    /* 0x54 */ Vec3f unk_54;
    /* 0x60 */ Color_RGBA32 fog;
    /* 0x64 */ s16 fogNear;
    /* 0x66 */ s16 fogFar;
    /* 0x68 */ Color_RGBA32 env;
    /* 0x6C */ Color_RGBA32 prim;
    /* 0x70 */ u8 unk_70;
    /* 0x71 */ u8 unk_71;
} AssetInfo; // size = 0x72

RECOMP_PATCH void Ending_8018D398(u32 arg0, AssetInfo* asset) {
    u8 alpha = 255;

    if ((asset->unk_0C + asset->fogNear) > arg0) {
        alpha = (arg0 - asset->unk_0C) * 255 / asset->fogNear;
    }

    if ((asset->unk_0C + asset->unk_10 - asset->fogFar) < arg0) {
        alpha = (asset->unk_0C + asset->unk_10 - arg0) * 255 / asset->fogFar;
    }

    gFillScreenRed = gFillScreenGreen = gFillScreenBlue = gFillScreenAlpha = gFillScreenAlphaTarget =
        gFillScreenAlphaStep = 0;

    Graphics_FillRectangle(&gMasterDisp, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH - SCREEN_MARGIN,
                           SCREEN_HEIGHT - SCREEN_MARGIN, asset->prim.r, asset->prim.g, asset->prim.b, alpha);
}