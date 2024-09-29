#include "patches.h"

#if 0

RECOMP_PATCH void Title_CorneriaExplosions_Draw(void) {
    f32 scale;
    s32 i;

    for (i = 0; i < sMaxExplosions; i++) {
        switch (D_menu_801B7CA0[i]) {
            case 0:
                D_menu_801B7C48[i] += 0.15f;
                if (D_menu_801B7C48[i] >= D_menu_801B7C70[i]) {
                    D_menu_801B7C48[i] = D_menu_801B7C70[i];
                    D_menu_801B7CA0[i] = 10;
                }
                break;

            case 10:
                D_menu_801B7D18[i]--;
                if (D_menu_801B7D18[i] <= 0) {
                    D_menu_801B7CA0[i] = 1;
                }
                break;

            case 1:
                D_menu_801B7CC8[i] -= 16;
                if (D_menu_801B7CC8[i] < 0) {
                    D_menu_801B7CC8[i] = 0;
                }
                D_menu_801B7CF0[i] -= 16;
                if (D_menu_801B7CF0[i] < 0) {
                    D_menu_801B7CF0[i] = 0;
                }
                if (D_menu_801B7CC8[i] == 0 && D_menu_801B7CF0[i] == 0) {
                    D_menu_801B7CA0[i] = 255;
                }
                break;

            case 255:
                D_menu_801B7BF8[i] = 10.0f + RAND_FLOAT(10.0f);
                D_menu_801B7C20[i] = -10.0f + RAND_FLOAT(-60.0f);
                D_menu_801B7C48[i] = 0.0f;
                D_menu_801B7C70[i] = 0.1f + RAND_FLOAT(0.3f);
                D_menu_801B7D18[i] = 5 + RAND_INT(5.0f);
                D_menu_801B7CC8[i] = 255;
                D_menu_801B7CF0[i] = 128;
                D_menu_801B7CA0[i] = 0;
                break;
        }
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_49);

    for (i = 0; i < sMaxExplosions; i++) {
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 200, 200, D_menu_801B7CC8[i]);
        gDPSetEnvColor(gMasterDisp++, 255, 0, 0, D_menu_801B7CF0[i]);

        scale = D_menu_801B7C48[i] / sTitleCorneria.scale;

        Matrix_Push(&gGfxMatrix);

        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, 5.0f, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, D_menu_801B7C20[i] * M_DTOR, MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 0.0f, D_menu_801B7BF8[i], 0.0f, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, scale, scale, scale, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);

        gSPDisplayList(gMasterDisp++, aTitleArwingEngineGlowDL);

        Matrix_Pop(&gGfxMatrix);
    }
}

#endif
