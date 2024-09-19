#include "patches.h"

extern Gfx D_VE2_600C2D0[];
extern Gfx D_VE2_600C560[];
extern Limb* D_VE2_600C0A4[];
extern Gfx aKaFLBaseDL[];
extern Gfx aKaFLBaseDestroyedDL[];

bool Andross_8018B47C(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);

RECOMP_PATCH void Andross_AndBrain_Draw(AndBrain* this) {
    s32 j;
    s32 i;
    f32 temp;
    s32 pad;
    Vec3f spAC;
    Vec3f spA0;

    if (this->state != 21) {
        Matrix_RotateZ(gGfxMatrix, -(f32) gGameFrameCount * 20.0f * M_DTOR, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, this->fwork[23] + 1.0f, 1.0f - this->fwork[23], 1.0f, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 20.0f * M_DTOR, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, this->fwork[23] + 1.0f, 1.0f - this->fwork[23], 1.0f, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
        Animation_DrawSkeleton(0, D_VE2_600C0A4, this->vwork, Andross_8018B47C, NULL, this, &gIdentityMatrix);
        if (this->fwork[21] >= 254) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_54);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 64, 64, 255);
        } else {
            RCP_SetupDL(&gMasterDisp, SETUPDL_70);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 64, 64, (s32) this->fwork[21]);
        }
        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
        Matrix_Translate(gGfxMatrix, 0.0f, -16.0f, 0.0f, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, 0.3f, 0.6f, 0.3f, MTXF_APPLY);

        for (i = 0; i < 30; i++) {
            Matrix_Push(&gGfxMatrix);
            Matrix_RotateY(gCalcMatrix, i * 50.0f * M_DTOR, 0U);
            spAC.x = 0.0f;
            spAC.y = 0.0f;
            spAC.z = i * 0.8f;
            Matrix_MultVec3f(gCalcMatrix, &spAC, &spA0);
            Matrix_Translate(gGfxMatrix, spA0.x, 10.0f, spA0.z, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, M_DTOR * -this->obj.rot.y - gPlayer[0].camYaw, MTXF_APPLY);

            for (j = 0; j < 10; j++) {
                Matrix_Translate(gGfxMatrix, 0.0f, -10.0f, 0.0f, MTXF_APPLY);
                temp = SIN_DEG((s32) this->fwork[19] * (i * 10 + j) + (gGameFrameCount * 5)) * this->fwork[10];
                Matrix_RotateZ(gGfxMatrix, (this->fwork[18] + temp) * M_DTOR, MTXF_APPLY);
                Matrix_RotateX(gGfxMatrix, this->fwork[17] * M_DTOR, MTXF_APPLY);
                Matrix_Push(&gGfxMatrix);
                Matrix_Translate(gGfxMatrix, 0.0f, -5.0f, 0.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + i, G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);
                if (j == 9) {
                    gSPDisplayList(gMasterDisp++, D_VE2_600C2D0);
                } else {
                    gSPDisplayList(gMasterDisp++, D_VE2_600C560);
                }

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                Matrix_Pop(&gGfxMatrix);
            }
            Matrix_Pop(&gGfxMatrix);
        }
    }
}

RECOMP_PATCH void Katina_KaFrontlineBase_Draw(KaFrontlineBase* this) {
    gSPFogPosition(gMasterDisp++, gFogNear, 1002);
    Matrix_Translate(gGfxMatrix, 0.0f, 20.0f, 0.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    if (this->state == 0) {
        gSPDisplayList(gMasterDisp++, aKaFLBaseDL);
    } else {
        RCP_SetupDL(&gMasterDisp, SETUPDL_57);
        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
        gSPDisplayList(gMasterDisp++, aKaFLBaseDestroyedDL);
    }
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}