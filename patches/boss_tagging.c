#include "patches.h"

extern Gfx D_VE2_600C2D0[];
extern Gfx D_VE2_600C560[];
extern Limb* aVe2AndBrainSkel[];
extern Gfx aKaFLBaseDL[];
extern Gfx aKaFLBaseDestroyedDL[];

void Meteo_MeCrusherEngineGlow_Draw(s32 scale);
bool Andross_AndBrain_OverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);

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
        Animation_DrawSkeleton(0, aVe2AndBrainSkel, this->vwork, Andross_AndBrain_OverrideLimbDraw, NULL, this, &gIdentityMatrix);
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
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + i + 0x01000000, G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
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

#if 1
RECOMP_PATCH void Meteo_MeCrusher_Draw(MeCrusher* this) {
    s32 i;
    f32 var_fs0;
    f32 var_fs1;
    s32 pad;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aMeCrusherDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    RCP_SetupDL_64();
    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

    for (i = 0; i < 6; i++) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + i + 1, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);

        if ((this->fwork[i + 3] != 0) && (this->fwork[11] == 0.0f)) {
            var_fs1 = 2.0f * this->fwork[3 + i];
            Matrix_Push(&gGfxMatrix);

            switch (i) {
                case 0:
                    Matrix_Translate(gGfxMatrix, 746.0f, 741.0f, 680.0f, MTXF_APPLY);
                    break;

                case 1:
                    Matrix_Translate(gGfxMatrix, -746.0f, 741.0f, 680.0f, MTXF_APPLY);
                    break;

                case 2:
                    Matrix_Translate(gGfxMatrix, -746.0f, -741.0f, 680.0f, MTXF_APPLY);
                    break;

                case 3:
                    Matrix_Translate(gGfxMatrix, 746.0f, -741.0f, 680.0f, MTXF_APPLY);
                    break;

                case 4:
                    Matrix_Translate(gGfxMatrix, 1283.0f, 0.0f, -340.0f, MTXF_APPLY);
                    break;

                case 5:
                    Matrix_Translate(gGfxMatrix, -1283.0f, 0.0f, -340.0f, MTXF_APPLY);
                    break;
            }

            if (i < 4) {
                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 32, 32, 128);
                Matrix_Scale(gGfxMatrix, var_fs1, var_fs1, var_fs1, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                gSPDisplayList(gMasterDisp++, aBlueSphereDL);
            } else {
                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 128);
                Matrix_Scale(gGfxMatrix, var_fs1 * 6.0f, var_fs1 * 6.0f, var_fs1 * 6.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                gSPDisplayList(gMasterDisp++, aBlueSphereDL);
            }
            Matrix_Pop(&gGfxMatrix);
        }
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }

    for (i = 0; i < 7; i++) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + i + 7, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);

        if (this->swork[2 + i] != 0) {
            gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, this->swork[19], 255);

            if ((this->swork[9 + i] % 2) != 0) {
                gDPSetPrimColor(gMasterDisp++, 0, 0, 80, 0, 0, 255);
            }

            Matrix_Push(&gGfxMatrix);

            if (i == 4) {
                Matrix_Translate(gGfxMatrix, 0.0f, 0, 300.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_PI / 4, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, this->fwork[21], this->fwork[21], 1.0f, MTXF_APPLY);
            }

            if (i == 5) {
                Matrix_Translate(gGfxMatrix, 0.0f, 330.0f, -1022.0f, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, this->fwork[22] * 3.2f, 2.0f * this->fwork[22], 1.0f, MTXF_APPLY);
            }

            if (i == 6) {
                Matrix_Translate(gGfxMatrix, 0.0f, -330.0f, -1022.0f, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, this->fwork[23] * 3.2f, 2.0f * this->fwork[23], 1.0f, MTXF_APPLY);
            }

            if (i < 4) {
                Matrix_RotateZ(gGfxMatrix, M_DTOR * 90.0f * i, MTXF_APPLY);
                Matrix_Translate(gGfxMatrix, 0.0f, 200.0f, 500.0f, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, this->fwork[17 + i], this->fwork[17 + i], 1.0f, MTXF_APPLY);
            }

            Matrix_SetGfxMtx(&gMasterDisp);

            if (i < 4) {
                gSPDisplayList(gMasterDisp++, D_ME_6024AD0);
            } else {
                gSPDisplayList(gMasterDisp++, D_ME_60236F0);
            }
            Matrix_Pop(&gGfxMatrix);
        }
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }

    gDPSetPrimColor(gMasterDisp++, 0, 0, 160, 255, 160, 128);

    for (i = 0; i < 4; i++) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + i + 11, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);

        if (this->fwork[11] != 0) {
            var_fs1 = this->fwork[11];
            if (this->fwork[11] > 15.0f) {
                var_fs1 = 15.0f;
            }

            Matrix_Push(&gGfxMatrix);
            switch (i) {
                case 0:
                    Matrix_Translate(gGfxMatrix, 746.0f, 741.0f, 680.0f, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, -M_PI / 4, MTXF_APPLY);
                    break;

                case 1:
                    Matrix_Translate(gGfxMatrix, -746.0f, 741.0f, 680.0f, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, M_PI / 4, MTXF_APPLY);
                    break;

                case 2:
                    Matrix_Translate(gGfxMatrix, -746.0f, -741.0f, 680.0f, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, 3 * M_PI / 4, MTXF_APPLY);
                    break;

                case 3:
                    Matrix_Translate(gGfxMatrix, 746.0f, -741.0f, 680.0f, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, -3 * M_PI / 4, MTXF_APPLY);
                    break;
            }

            Matrix_SetGfxMtx(&gMasterDisp);
            Matrix_Push(&gGfxMatrix);

            if ((gGameFrameCount % 2) != 0) {
                Matrix_Scale(gGfxMatrix, var_fs1 * 2.5f, var_fs1 * 2.5f, var_fs1 * 2.5f, MTXF_APPLY);
            } else {
                Matrix_Scale(gGfxMatrix, var_fs1 * 3.0f, var_fs1 * 3.0f, var_fs1 * 3.0f, MTXF_APPLY);
            }

            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, aBlueSphereDL);
            Matrix_Pop(&gGfxMatrix);
            Matrix_RotateX(gGfxMatrix, -M_PI / 6, MTXF_APPLY);

            if ((gGameFrameCount % 2) != 0) {
                Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
            }
            Matrix_Scale(gGfxMatrix, 2.0f, 2.0f * var_fs1, 2.0f, MTXF_APPLY);
            Matrix_Translate(gGfxMatrix, 0.0f, -20.0f, 0.0f, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_102F5E0);
            Matrix_Pop(&gGfxMatrix);
        }
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + 15, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (this->fwork[11] > 15.0f) {
        var_fs1 = this->fwork[11] - 15.0f;
        gDPSetPrimColor(gMasterDisp++, 0, 0, 160, 255, 160, 255);
        Matrix_Push(&gGfxMatrix);
        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, 1300.0f, MTXF_APPLY);
        if ((gGameFrameCount % 2) != 0) {
            Matrix_Scale(gGfxMatrix, var_fs1 * 0.8f, var_fs1 * 0.8f, var_fs1 * 0.8f, MTXF_APPLY);
        } else {
            Matrix_Scale(gGfxMatrix, var_fs1, var_fs1, var_fs1, MTXF_APPLY);
        }
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, aBlueSphereDL);
        Matrix_Pop(&gGfxMatrix);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    if ((this->state == 9) || (this->state == 10)) {
        var_fs1 = this->fwork[15];
        for (i = 0; i < 10; i++) {
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + i + 16, G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);

            var_fs1 += 0.3f;
            var_fs0 = var_fs1;
            if (var_fs1 <= 7.0f) {
                if (var_fs1 < 1.0f) {
                    var_fs0 = 1.0f;
                }

                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, D_i2_80195554[i]);
                Matrix_Push(&gGfxMatrix);

                Matrix_Translate(gGfxMatrix, 700.0f, 0.0f, -(1235.0f - ((var_fs0 - 1.0f) * 89.2f)), MTXF_APPLY);

                if ((gGameFrameCount % 2) != 0) {
                    Matrix_Scale(gGfxMatrix, var_fs0, var_fs0, var_fs0, MTXF_APPLY);
                } else {
                    Matrix_Scale(gGfxMatrix, var_fs0 * 1.1f, var_fs0 * 1.1f, var_fs0 * 1.1f, MTXF_APPLY);
                }

                Matrix_SetGfxMtx(&gMasterDisp);
                gSPDisplayList(gMasterDisp++, D_ME_6023810);
                Matrix_Pop(&gGfxMatrix);
                Matrix_Push(&gGfxMatrix);
                Matrix_Translate(gGfxMatrix, -700.0f, 0.0f, -(1235.0f - ((var_fs0 - 1.0f) * 89.2f)), MTXF_APPLY);

                if ((gGameFrameCount % 2) != 0) {
                    Matrix_Scale(gGfxMatrix, var_fs0, var_fs0, var_fs0, MTXF_APPLY);
                } else {
                    Matrix_Scale(gGfxMatrix, var_fs0 * 1.1f, var_fs0 * 1.1f, var_fs0 * 1.1f, MTXF_APPLY);
                }

                Matrix_SetGfxMtx(&gMasterDisp);
                gSPDisplayList(gMasterDisp++, D_ME_6023810);
                Matrix_Pop(&gGfxMatrix);
            }

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
        }
    }

    if (this->swork[0] > 0) {
        Matrix_Push(&gGfxMatrix);
        Matrix_Translate(gGfxMatrix, 0.0f, 650.0f, 600.0f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + 30, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        Meteo_MeCrusherEngineGlow_Draw(this->swork[0] - 1);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

        Matrix_Pop(&gGfxMatrix);
    }

    if (this->swork[1] > 0) {
        Matrix_Push(&gGfxMatrix);
        Matrix_Translate(gGfxMatrix, 0.0f, -650.0f, 600.0f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this) + 31, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        Meteo_MeCrusherEngineGlow_Draw(this->swork[1] - 1);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

        Matrix_Pop(&gGfxMatrix);
    }

    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
}
#endif

RECOMP_PATCH void Meteo_MeCrusherShield_Draw(MeCrusherShield* this) {
    s32 i;

    if ((this->timer_054 % 2) != 0) {
        RCP_SetupDL_27();
        gDPSetPrimColor(gMasterDisp++, 0, 0, 0, 255, 0, 255);
    }

    Matrix_RotateZ(gGfxMatrix, (M_PI / 4), MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, D_ME_60240B0);
    RCP_SetupDL_64();

    for (i = 1; i < 4; i++) {
        if (this->swork[0] != 0) {
            gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, this->swork[0]);
            Matrix_Push(&gGfxMatrix);
            Matrix_RotateZ(gGfxMatrix, M_DTOR * 90.0f * i, MTXF_APPLY);
            Matrix_Translate(gGfxMatrix, 0.0f, 156.0f, 930.0f, MTXF_APPLY);

            if ((gGameFrameCount % 2) != 0) {
                Matrix_Scale(gGfxMatrix, 6.0f, 9.0f, 5.0f, MTXF_APPLY);
            } else {
                Matrix_Scale(gGfxMatrix, 4.0f, 7.0f, 5.0f, MTXF_APPLY);
            }

            Matrix_RotateZ(gGfxMatrix, 1.5707964f, MTXF_APPLY); // (M_PI / 2) does not match
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_ME_60263F0);
            Matrix_Pop(&gGfxMatrix);
        }
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

typedef struct {
    /* 0x00 */ f32 r[3];
    /* 0x0C */ f32 g[3];
    /* 0x18 */ f32 b[3];
    /* 0x24 */ f32 unk_24;
    /* 0x30 */ f32 unk_28[3];
    /* 0x3C */ f32 unk_34;
} UnkStruct_1C22F0;

extern UnkStruct_1C22F0 D_i3_801C22F0;

RECOMP_PATCH void Area6_8018BCD4(Vec3f* arg0, f32 arg1, f32 arg2, Vec3f* arg3, s32 arg4, f32 arg5, s32 arg6, f32 arg7) {
    s32 i;
    Vec3f sp90 = { 0.0f, 0.0f, 0.0f };

    if (D_i3_801C22F0.unk_24 != 0.0f) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_23);
        if (D_i3_801C22F0.unk_24 != 255.0f) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_71);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, (s32) D_i3_801C22F0.unk_24);
        } else if (arg4 != 0) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_27);
            if (arg7 < 18.0f) {
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 255, 255);
            } else {
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 0, 255);
            }
        }

        Matrix_Push(&gGfxMatrix);
        Matrix_Push(&gCalcMatrix);
        Matrix_Copy(gCalcMatrix, &gIdentityMatrix);
        Matrix_RotateZ(gCalcMatrix, M_DTOR * arg1, MTXF_APPLY);
        Matrix_Translate(gCalcMatrix, 0.0f, 100.0f, -223.0f, MTXF_APPLY);
        Matrix_RotateX(gCalcMatrix, M_DTOR * arg2, MTXF_APPLY);

        for (i = 0; i < arg6; i++) {
            Matrix_Push(&gGfxMatrix);
            Matrix_Push(&gCalcMatrix);

            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS_GORGON(arg0) | ((i << 16) & 0x00FF0000), G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);

            if (i == 11) {
                Matrix_Scale(gCalcMatrix, 1.5f, 1.5f, 1.5f, MTXF_APPLY);
                Matrix_Mult(gGfxMatrix, gCalcMatrix, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                gSPDisplayList(gMasterDisp++, D_A6_600F1F0);
                Matrix_MultVec3f(gCalcMatrix, &sp90, arg3);
            } else {
                Matrix_Scale(gCalcMatrix, 2.0f, 2.0f, 2.0f, MTXF_APPLY);
                Matrix_Mult(gGfxMatrix, gCalcMatrix, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);

                gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                gSPDisplayList(gMasterDisp++, D_A6_6015EE0);

                if (arg6 != 12) {
                    Matrix_MultVec3f(gCalcMatrix, &sp90, arg3);
                }
            }
            Matrix_Pop(&gGfxMatrix);
            Matrix_Pop(&gCalcMatrix);
            Matrix_RotateY(gCalcMatrix, arg0[i].y * M_DTOR, MTXF_APPLY);
            Matrix_RotateX(gCalcMatrix, arg0[i].x * M_DTOR, MTXF_APPLY);
            Matrix_Translate(gCalcMatrix, 0.0f, 0.0f, arg5, MTXF_APPLY);

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
        }

        Matrix_Pop(&gGfxMatrix);
    }
}

#if 0

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

RECOMP_PATCH void FoBase_Draw(Boss* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPDisplayList(gMasterDisp++, aFoBaseDL2);
    RCP_SetupDL_34(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
    gDPSetTextureFilter(gMasterDisp++, G_TF_POINT);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 0, (s32) this->fwork[1], (s32) this->fwork[2], 255);
    gSPDisplayList(gMasterDisp++, aFoBaseDL1);
    gDPSetTextureFilter(gMasterDisp++, G_TF_BILERP);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Bolse_BoBase_Draw(BoBase* this) {
    s32 i;
    s32 alpha;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);

    if (this->vwork[30].y >= 0.0f) {
        gSPDisplayList(gMasterDisp++, D_BO_6002020);
    }

    if ((gGameFrameCount % 2) != 0) {
        alpha = 128;
    } else {
        alpha = 30;
    }

    for (i = 0; i < 6; i++) {
        if (D_i4_801A0488[i].unk_18 == 0) {
            continue;
        }
        Matrix_Push(&gGfxMatrix);
        RCP_SetupDL(&gMasterDisp, SETUPDL_49);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, alpha);
        gDPSetEnvColor(gMasterDisp++, 255, 56, 56, alpha);
        Matrix_Translate(gGfxMatrix, D_i4_801A0488[i].unk_0C, D_i4_801A0488[i].unk_10, D_i4_801A0488[i].unk_14,
                         MTXF_APPLY);
        Matrix_RotateY(gGfxMatrix, D_i4_801A0488[i].unk_04 * M_DTOR, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, D_i4_801A0488[i].unk_00 * M_DTOR, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, M_PI / 2, MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 1.0f, 1.0f, D_i4_801A0488[i].unk_08 * 200.0f, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, 1.0f, 1.0f, D_i4_801A0488[i].unk_08, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, D_BO_600BF30);
        Matrix_Pop(&gGfxMatrix);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Bolse_BoBaseShield_Draw(BoBaseShield* this) {
    s32 alpha;

    Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);

    alpha = this->fwork[0];
    if (alpha != 0) {
        if ((gGameFrameCount % 2) == 0) {
            alpha *= 1.7f;
        }
        RCP_SetupDL(&gMasterDisp, SETUPDL_41);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, alpha);
        Matrix_Scale(gGfxMatrix, 1.2f, 0.55f, 1.2f, MTXF_APPLY);

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_BOSS(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, aBoBaseShieldDL);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

#endif