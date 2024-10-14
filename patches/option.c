#include "patches.h"

// @recomp: Fix ranking display fade bars positions
RECOMP_PATCH void Option_80197914(void) {
    Vec3f* vec1;
    Vec3f* vec2;
    s32 i;

    RCP_SetupDL(&gMasterDisp, SETUPDL_0);

    for (i = 0, vec1 = D_menu_801AF100, vec2 = D_menu_801AF118; i < 2; i++, vec1++, vec2++) {
        Matrix_Push(&gGfxMatrix);
        Matrix_Translate(gGfxMatrix, vec1->x, vec1->y, -500.0f, MTXF_APPLY);
        
        // @recomp: Increase the scale by 2.5f to compensate for missing borders
        Matrix_Scale(gGfxMatrix, vec2->x * 4, vec2->y + 2.5f, 1.0f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, D_menu_801AEF30);
        Matrix_Pop(&gGfxMatrix);
    }
}