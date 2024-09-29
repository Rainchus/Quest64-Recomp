#include "patches.h"

#if 1

#if 1 // Hangar Widescreen fix
void Title_GreatFoxDeckPlatform_Draw(void);

s32 offset_value = -800;

RECOMP_PATCH void Title_GreatFoxDeck_Draw(void) {
    Lights_SetOneLight(&gMasterDisp, D_menu_801B82E0, D_menu_801B82E4, D_menu_801B82E8, 0, 0, 0, gAmbientR, gAmbientG,
                       gAmbientB);
    RCP_SetupDL(&gMasterDisp, SETUPDL_23);

    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, D_menu_801B9048, D_menu_801B904C, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 0.4f, 0.4f, 0.4f, MTXF_APPLY);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_GREATFOXDECK, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_SetGfxMtx(&gMasterDisp);

    // Draw original display list
    gSPDisplayList(gMasterDisp++, aTitleGreatFoxDeckDL);

    // Apply scaling for mirroring
    Matrix_Push(&gGfxMatrix);                                // Push current matrix state
    Matrix_Scale(gGfxMatrix, -1.0f, 1.0f, 1.0f, MTXF_APPLY); // Mirror the display list horizontally
    Matrix_Translate(gGfxMatrix, offset_value, 0.0f, 0.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aTitleGreatFoxDeckDL); // Draw mirrored display list
    Matrix_Pop(&gGfxMatrix);                             // Restore original matrix state

    if (D_menu_801B7BE4 != 0) {
        Title_GreatFoxDeckPlatform_Draw();
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix); // Restore original transformation
}
#endif

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

#endif
