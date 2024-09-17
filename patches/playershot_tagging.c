#include "patches.h"

#define SHOT_ID 0x1000

extern Vec3f sShotViewPos;
extern f32 D_800C9BD8[10];
extern u8 D_800C9C00[4];
extern u8 D_800C9C04[4];
extern u8 D_800C9C08[4];
extern Gfx D_10231A0[];
extern Gfx D_versus_301AD60[];
extern Gfx D_versus_301AEF0[];
extern Gfx D_landmaster_3006940[];
extern Gfx aOrbDL[];
extern Gfx aStarDL[];
extern Gfx D_1031EC0[];
extern Gfx D_GREAT_FOX_E00DFB0[];
extern Gfx D_AQ_600DB80[];

void PlayerShot_Draw(PlayerShot* shot);
void PlayerShot_DrawLaser(PlayerShot* shot);

RECOMP_PATCH void PlayerShot_DrawShot(PlayerShot* shot) {
    Vec3f sp11C = { 0.0f, 0.0f, 0.0f };
    s32 pad[4];
    f32 var_fv1;
    s32 isDrawn = false;

    Matrix_Translate(gGfxMatrix, shot->obj.pos.x, shot->obj.pos.y, shot->obj.pos.z + gPathProgress, MTXF_APPLY);
    Matrix_MultVec3f(gGfxMatrix, &sp11C, &sShotViewPos);

    if ((sShotViewPos.z < 0.0f) && (sShotViewPos.z > -10000.0f)) {
        var_fv1 = fabsf(sShotViewPos.x); // probably fake. The use of temps was likely different
        if (var_fv1 < (fabsf(sShotViewPos.z * 0.5f) + 500.0f)) {
            if (fabsf(sShotViewPos.y) < (fabsf(sShotViewPos.z * 0.5f) + 500.0f)) {
                isDrawn = true;
            }
        }
    }

    if (!isDrawn) {
        if ((shot->obj.id != PLAYERSHOT_BOMB) && (shot->timer < 10) && !gVersusMode) {
            Object_Kill(&shot->obj, shot->sfxSource);
        }
    } else {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, shot->index + SHOT_ID, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);
        if ((shot->obj.id == PLAYERSHOT_TANK) || (shot->obj.id == PLAYERSHOT_ON_FOOT) ||
            (shot->obj.id == PLAYERSHOT_7)) {
            shot->obj.rot.y = RAD_TO_DEG(-gPlayer[gPlayerNum].camYaw);
            shot->obj.rot.x = RAD_TO_DEG(gPlayer[gPlayerNum].camPitch);
        }
        if (shot->obj.id != PLAYERSHOT_2) {
            Matrix_RotateY(gGfxMatrix, shot->obj.rot.y * M_DTOR, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, shot->obj.rot.x * M_DTOR, MTXF_APPLY);
            Matrix_RotateZ(gGfxMatrix, shot->obj.rot.z * M_DTOR, MTXF_APPLY);
            if ((shot->obj.id == PLAYERSHOT_BOMB) && (shot->unk_5C == 0)) {
                Matrix_RotateZ(gGfxMatrix, shot->vec_2C.z * M_DTOR, MTXF_APPLY);
                Matrix_RotateY(gGfxMatrix, shot->vec_2C.y * M_DTOR, MTXF_APPLY);
                Matrix_RotateX(gGfxMatrix, shot->vec_2C.x * M_DTOR, MTXF_APPLY);
            }
        }

        Matrix_Translate(gGfxMatrix, 0.f, 0.f, D_800C9BD8[shot->obj.id], MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);

        switch (shot->obj.id) {
            case PLAYERSHOT_SINGLE_LASER:
            case PLAYERSHOT_TWIN_LASER:

                PlayerShot_DrawLaser(shot);

                break;
            case PLAYERSHOT_BOMB:
                if (shot->unk_5C == 0) {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
                    gSPDisplayList(gMasterDisp++, D_10231A0);
                    Matrix_Pop(&gGfxMatrix);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, shot->obj.pos.x, shot->obj.pos.y, shot->obj.pos.z + gPathProgress,
                                     MTXF_APPLY);
                    Matrix_RotateY(gGfxMatrix, -gPlayer[gPlayerNum].camYaw, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, gPlayer[gPlayerNum].camPitch, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 40.0f * M_DTOR, MTXF_APPLY);
                    if (((gGameFrameCount % 2) == 0)) {
                        Matrix_Scale(gGfxMatrix, 1.7f, 1.7f, 1.7f, MTXF_APPLY);
                    } else {
                        Matrix_Scale(gGfxMatrix, 1.2f, 1.2f, 1.2f, MTXF_APPLY);
                    }
                    RCP_SetupDL(&gMasterDisp, SETUPDL_49);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
                    if (gVersusMode) {
                        switch (shot->sourceId) {
                            case 0:
                                gDPSetEnvColor(gMasterDisp++, 255, 255, 32, 128);
                                break;
                            case 1:
                                gDPSetEnvColor(gMasterDisp++, 255, 32, 32, 128);
                                break;
                            case 2:
                                gDPSetEnvColor(gMasterDisp++, 32, 255, 32, 128);
                                break;
                            case 3:
                                gDPSetEnvColor(gMasterDisp++, 32, 32, 255, 128);
                                break;
                        }
                    } else {
                        gDPSetEnvColor(gMasterDisp++, 0, 128, 255, 255);
                    }
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aOrbDL);
                } else {
                    Matrix_Scale(gGfxMatrix, shot->scale, shot->scale, shot->scale, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    if (gVersusMode) {
                        RCP_SetupDL_49();
                        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, shot->unk_58);
                        switch (shot->sourceId) {
                            case 0:
                                gDPSetEnvColor(gMasterDisp++, 255, 255, 32, shot->unk_58);
                                break;
                            case 1:
                                gDPSetEnvColor(gMasterDisp++, 255, 32, 32, shot->unk_58);
                                break;
                            case 2:
                                gDPSetEnvColor(gMasterDisp++, 32, 255, 32, shot->unk_58);
                                break;
                            case 3:
                                gDPSetEnvColor(gMasterDisp++, 32, 32, 255, shot->unk_58);
                                break;
                        }
                    } else {
                        RCP_SetupDL_64_2();
                        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, shot->unk_58);
                    }
                    gSPDisplayList(gMasterDisp++, D_1031EC0);
                }
                break;
            case PLAYERSHOT_TANK:
                gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                RCP_SetupDL_40();
                if (gVersusMode) {
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
                    gDPSetEnvColor(gMasterDisp++, D_800C9C00[shot->sourceId], D_800C9C04[shot->sourceId],
                                   D_800C9C08[shot->sourceId], 255);
                    RCP_SetupDL(&gMasterDisp, SETUPDL_49);
                    if (gLaserStrength[shot->sourceId] != LASERS_SINGLE) {
                        Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 48.0f * M_DTOR, MTXF_APPLY);
                        Matrix_Push(&gGfxMatrix);
                        Matrix_Translate(gGfxMatrix, 0.f, 50.0f, 0.0f, MTXF_APPLY);
                        Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 70.0f * M_DTOR, MTXF_APPLY);
                        Matrix_Scale(gGfxMatrix, 2.0f, 2.0f, 2.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);
                        gSPDisplayList(gMasterDisp++, D_versus_301AD60);
                        Matrix_Pop(&gGfxMatrix);
                        Matrix_Translate(gGfxMatrix, 0.0f, -50.0f, 0.0f, MTXF_APPLY);
                        Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 70.0f * M_DTOR, MTXF_APPLY);
                        Matrix_Scale(gGfxMatrix, 2.0f, 2.0f, 2.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);
                        gSPDisplayList(gMasterDisp++, D_versus_301AD60);
                    } else {
                        if (((gGameFrameCount % 2) == 0)) {
                            var_fv1 = M_PI;
                        } else {
                            var_fv1 = 0.0f;
                        }
                        Matrix_RotateY(gGfxMatrix, var_fv1, MTXF_APPLY);
                        Matrix_RotateZ(gGfxMatrix, 30.0f * M_DTOR, MTXF_APPLY);
                        Matrix_Scale(gGfxMatrix, 2.0f, 2.0f, 2.0f, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);
                        gSPDisplayList(gMasterDisp++, D_versus_301AD60);
                    }
                } else {
                    if (((gGameFrameCount % 2) == 0)) {
                        var_fv1 = M_PI;
                    } else {
                        var_fv1 = 0.0f;
                    }
                    Matrix_RotateY(gGfxMatrix, var_fv1, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, 30.0f * M_DTOR, MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, 1.0f, 0.65f, 1.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    RCP_SetupDL_68();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
                    gDPSetEnvColor(gMasterDisp++, 0, 255, 0, 0);
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                    gSPDisplayList(gMasterDisp++, D_landmaster_3006940);
                }
                break;
            case PLAYERSHOT_ON_FOOT:
            case PLAYERSHOT_7:
                Matrix_Scale(gGfxMatrix, shot->scale, shot->scale, shot->scale, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                RCP_SetupDL(&gMasterDisp, SETUPDL_49);
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
                gDPSetEnvColor(gMasterDisp++, D_800C9C00[shot->sourceId], D_800C9C04[shot->sourceId],
                               D_800C9C08[shot->sourceId], 255);
                if (gLaserStrength[shot->sourceId] != LASERS_SINGLE) {
                    Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 48.0f * M_DTOR, MTXF_APPLY);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, 0.f, 40.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_versus_301AEF0);
                    Matrix_Pop(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, 0.f, -40.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_versus_301AEF0);
                } else {
                    gSPDisplayList(gMasterDisp++, D_versus_301AEF0);
                }
                break;
            case PLAYERSHOT_LOCK_ON:
                Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                if (gCurrentLevel == LEVEL_AQUAS) {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_60);
                    gSPDisplayList(gMasterDisp++, D_AQ_600DB80);
                    Matrix_Pop(&gGfxMatrix);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, shot->obj.pos.x, gGroundHeight, shot->obj.pos.z + gPathProgress,
                                     MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, shot->vec_2C.x, shot->vec_2C.y, shot->vec_2C.z, MTXF_APPLY);
                    RCP_SetupDL(&gMasterDisp, SETUPDL_49);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 32, 32, 0, shot->unk_58);
                    gDPSetEnvColor(gMasterDisp++, 32, 16, 16, shot->unk_58);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aOrbDL);
                } else if (shot->unk_5C == 0) {
                    if (shot->scale > 1.5f) {
                        break;
                    }
                    Matrix_Pop(&gGfxMatrix);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, shot->obj.pos.x, shot->obj.pos.y, shot->obj.pos.z + gPathProgress,
                                     MTXF_APPLY);
                    Matrix_RotateY(gGfxMatrix, -gPlayer[gPlayerNum].camYaw, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, gPlayer[gPlayerNum].camPitch, MTXF_APPLY);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Scale(gGfxMatrix, 20.0f, 20.0f, 20.0f, MTXF_APPLY);
                    RCP_SetupDL(&gMasterDisp, SETUPDL_49);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
                    if (gVersusMode) {
                        switch (shot->sourceId) {
                            case 0:
                                gDPSetEnvColor(gMasterDisp++, 255, 255, 32, 255);
                                break;
                            case 1:
                                gDPSetEnvColor(gMasterDisp++, 255, 32, 32, 255);
                                break;
                            case 2:
                                gDPSetEnvColor(gMasterDisp++, 32, 255, 32, 255);
                                break;
                            case 3:
                                gDPSetEnvColor(gMasterDisp++, 32, 32, 255, 255);
                                break;
                        }
                    } else {
                        gDPSetEnvColor(gMasterDisp++, 0, 255, 0, 255);
                    }
                    Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 53.0f * M_DTOR, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aStarDL);
                    Matrix_RotateZ(gGfxMatrix, gGameFrameCount * -53.0f * 2.0f * M_DTOR, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aStarDL);
                    Matrix_Pop(&gGfxMatrix);
                    if (((gGameFrameCount % 2) == 0)) {
                        Matrix_Scale(gGfxMatrix, 1.7f, 1.7f, 1.7f, MTXF_APPLY);
                    } else {
                        Matrix_Scale(gGfxMatrix, 1.3f, 1.3f, 1.3f, MTXF_APPLY);
                    }
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aOrbDL);
                } else {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
                    gSPDisplayList(gMasterDisp++, D_10231A0);
                    Matrix_Pop(&gGfxMatrix);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, shot->obj.pos.x, shot->obj.pos.y, shot->obj.pos.z + gPathProgress,
                                     MTXF_APPLY);
                    Matrix_RotateY(gGfxMatrix, -gPlayer[gPlayerNum].camYaw, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, gPlayer[gPlayerNum].camPitch, MTXF_APPLY);
                    if (((gGameFrameCount % 2) == 0)) {
                        Matrix_Scale(gGfxMatrix, 1.2f, 1.2f, 1.2f, MTXF_APPLY);
                    } else {
                        Matrix_Scale(gGfxMatrix, 1.5f, 1.5f, 1.5f, MTXF_APPLY);
                    }
                    RCP_SetupDL(&gMasterDisp, SETUPDL_49);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 0, 255);
                    gDPSetEnvColor(gMasterDisp++, 255, 128, 128, 255);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aOrbDL);
                }
                break;
            case PLAYERSHOT_GFOX_LASER:
                Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 3.0f, 3.0f, 20.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                RCP_SetupDL_40();
                gSPDisplayList(gMasterDisp++, D_GREAT_FOX_E00DFB0);
                break;
        }
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}
