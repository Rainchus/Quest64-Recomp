#include "patches.h"


u16 next_actor_transform = 0;

void ActorAllRange_DrawBarrelRoll(ActorAllRange* this);
void ActorAllRange_DrawShield(ActorAllRange* this);
bool ActorAllRange_MissileOverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
bool Macbeth_MaTrainCar1_OverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
bool Macbeth_MaLocomotive_OverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
bool Macbeth_MaRailroadSwitch_OverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
void Macbeth_MaLocomotive_PostLimbDraw(s32 limbIndex, Vec3f* rot, void* thisx);
bool Macbeth_801A0B00(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
bool Macbeth_801A0B20(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
bool Macbeth_801A0A74(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
bool Aquas_AqAnglerFish_OverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);
void Aquas_AqAnglerFish_PostLimbDraw(s32 limbIndex, Vec3f* rot, void* thisx);
void Aquas_AqStoneColumn_PostLimbDraw(s32 limbIndex, Vec3f* rot, void* thisx);
void Aquas_801ADF7C(f32 xPos, f32 yPos, f32 zPos, f32 xRot, f32 yRot, f32 zRot, u8 type, s32 flag, f32 scale,
                    s32 index);
void Zoness_ZoDodora_Draw(Actor* this);
void Object_SetMatrix(Object* obj, s32 drawType);
void func_edisplay_8005D3CC(Object* obj, f32 xRot, f32 yRot, f32 zRot, s32 drawType);

RECOMP_PATCH void Display_Landmaster(Player* player) {
    f32 sp64;
    Vec3f sp58;
    Vec3f sp4C = { 0.0f, 0.0f, 90.0f };
    Vec3f sp40 = { 0.0f, 40.0f, -70.0f };

    Matrix_Push(&gGfxMatrix);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_VEHICLE + gPlayerNum, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);

    if (!gVersusMode) {
        gSPDisplayList(gMasterDisp++, aLandmasterModelDL);
    } else {
        gSPDisplayList(gMasterDisp++, aVsLandmasterModelDL);
    }

    Matrix_MultVec3f(gGfxMatrix, &sp40, &D_display_80161518[player->num]);
    Matrix_Translate(gGfxMatrix, 0.0f, 51.0f, -10.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, -player->unk_180 * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, player->unk_17C * M_DTOR, MTXF_APPLY);

    if (gPlayerNum == player->num) {
        sp64 = 0.0f;
        if (gChargeTimers[player->num] >= 20) {
            sp64 = (s32) (gGameFrameCount % 8U) * 80.0f;
        }
        sp58.x = 0.0f;
        sp58.y = 0.0f;
        sp58.z = 1200.0f;
        Matrix_MultVec3f(gGfxMatrix, &sp58, &D_display_801613E0[0]);
        sp58.z = 2400.0f + sp64;
        Matrix_MultVec3f(gGfxMatrix, &sp58, &D_display_801613E0[1]);
    }

    Matrix_SetGfxMtx(&gMasterDisp);

    if (!gVersusMode) {
        if (player->unk_1A0 != 0) {
            RCP_SetupDL_64();
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 64, 255, 64, 255);
        }
        gSPDisplayList(gMasterDisp++, aLandmasterCanonDL);
    } else {
        gSPDisplayList(gMasterDisp++, aVsLandmasterCanonDL);
    }

    Matrix_MultVec3f(gGfxMatrix, &sp4C, &D_display_80161548[player->num]);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix);
}

RECOMP_PATCH void Zoness_ZoSpikeBall_Draw(ZoSpikeBall* this) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs0_2;
    f32 temp_fs1_2;
    f32 temp_fs0_4;
    f32 var_fs5 = 90.0f;
    s32 i;
    f32 sp94;
    s32 var_s4;

    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);

    if ((gBosses[0].state != 6) && (gBosses[0].state != 7)) {
        RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

        temp_fa0 = sZoFwork[65] - this->obj.pos.x;
        temp_fs0 = sZoFwork[66] - this->obj.pos.y;
        temp_fa1 = sZoFwork[67] - this->obj.pos.z;

        temp_fs3 = sqrtf(SQ(temp_fa0) + SQ(temp_fs0) + SQ(temp_fa1));
        temp_fs4 = Math_Atan2F(temp_fa0, temp_fa1);
        temp_fs0_2 = -Math_Atan2F(temp_fs0, sqrtf(SQ(temp_fa0) + SQ(temp_fa1)));
        var_s4 = temp_fs3 / 70.0f;
        if (var_s4 > 50) {
            var_s4 = 50;
        }
        if (var_s4 < 0) {
            var_s4 = 0;
        }
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + gPathProgress, MTXF_APPLY);
        Matrix_RotateY(gGfxMatrix, temp_fs4, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, temp_fs0_2, MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, 0.0f, MTXF_APPLY);

        sp94 = (180.0f / var_s4) + 1.0f;

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + 1, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
        for (i = 0; i < var_s4; i++) {
            temp_fs1_2 = SIN_DEG(i * sp94) * this->fwork[5];
            temp_fs0_4 = COS_DEG(i * sp94) * this->fwork[5] * -0.25f;
            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, this->fwork[1], MTXF_APPLY);
            Matrix_Push(&gGfxMatrix);
            Matrix_Translate(gGfxMatrix, 0.0f, temp_fs1_2, 0.0f, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_DTOR * temp_fs0_4, MTXF_APPLY);
            Matrix_Push(&gGfxMatrix);
            Matrix_RotateZ(gGfxMatrix, M_DTOR * var_fs5, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_PI / 2, MTXF_APPLY);
            Matrix_Scale(gGfxMatrix, 1.5f, 1.5f, 1.5f, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_ZO_6018660);
            Matrix_Pop(&gGfxMatrix);
            Matrix_Pop(&gGfxMatrix);
            var_fs5 += 90.0f;
        }
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + 51, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + gPathProgress, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 2.6f, 2.6f, 2.6f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    RCP_SetupDL(&gMasterDisp, SETUPDL_70);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
    gSPDisplayList(gMasterDisp++, D_ZO_6004380);
    Matrix_RotateY(gGfxMatrix, sZoFwork[19] * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, this->fwork[2] * M_DTOR, MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix, this->fwork[3] * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    RCP_SetupDL_55();
    gSPDisplayList(gMasterDisp++, D_ZO_601BCC0);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Aquas_BlueMarine_Draw(Player* player) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_VEHICLE + gPlayerNum, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);

    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -40.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aBlueMarineBodyDL);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, -4.5f, 1.2f, MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix, player->unk_178 * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aBlueMarinePropellerDL);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, 2.0f, 40.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, -player->unk_180 * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aBlueMarineBackRudderDL);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, -19.0f, -3.6f, 1.2f, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, player->unk_17C * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aBlueMarineLeftRudderDL);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 19.0f, -3.6f, 1.2f, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, player->unk_17C * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aBlueMarineRightRudderDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix);
}

RECOMP_PATCH void Display_ActorMarks(void) {
    s32 i;
    f32 var_fs0;

    if ((gGameFrameCount & 4) == 0) {
        RCP_SetupDL_40();

        for (i = 0; i < ARRAY_COUNT(gTeamArrowsViewPos); i++) {
            if (gTeamArrowsViewPos[i].z < 0.0f) {
                var_fs0 = (VEC3F_MAG(&gTeamArrowsViewPos[i])) * 0.0015f;
                if (var_fs0 > 100.0f) {
                    var_fs0 = 100.0f;
                } else if (var_fs0 < 1.0f) {
                    var_fs0 = 1.0f;
                }

                Matrix_Push(&gGfxMatrix);
                Matrix_Translate(gGfxMatrix, gTeamArrowsViewPos[i].x, gTeamArrowsViewPos[i].y, gTeamArrowsViewPos[i].z,
                                 MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, var_fs0 * 0.25f, var_fs0 * 0.25f, 1.0f, MTXF_APPLY);

                if ((i == 0) && (gCurrentLevel == LEVEL_SECTOR_Z)) {
                    Matrix_Scale(gGfxMatrix, 2.0f, 2.0f, 1.0f, MTXF_APPLY);
                }

                Matrix_Translate(gGfxMatrix, 0.0f, 150.0f, 0.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                gDPSetTextureFilter(gMasterDisp++, G_TF_POINT);

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_TEAM_ARROW + i, G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);

                if ((i == 0) && (gCurrentLevel == LEVEL_SECTOR_Z)) {
                    gSPDisplayList(gMasterDisp++, aSzMissileMark);
                } else {
                    gSPDisplayList(gMasterDisp++, sTeammateMarkDLs[i]);
                }

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                Matrix_Pop(&gGfxMatrix);
            }
            gTeamArrowsViewPos[i].x = gTeamArrowsViewPos[i].y = 0;
            gTeamArrowsViewPos[i].z = 100.0f;
        }
        gDPSetTextureFilter(gMasterDisp++, G_TF_BILERP);
    }
}

#define KA_ACTOR_LOW_POLY (23)
#define KA_ACTOR_IWORK_8 (8)
#define EG_RED (0)

extern Gfx aKaEnemyDL[];
extern Gfx aKaCornerianFighterDL[];

// @recomp: disable LOD on Katina enemies
RECOMP_PATCH void Katina_EnemyDraw(ActorAllRange* this) {
    s32 pad3[3];
    f32 angle;
    Vec3f D_i4_8019F4A8 = { 0.0f, 0.0f, 0.0f };
    Vec3f pad[30];

    // @recomp: never use low poly
    this->iwork[KA_ACTOR_LOW_POLY] = false;

    if ((this->iwork[KA_ACTOR_IWORK_8] != 0) && (this->aiType < AI360_GREAT_FOX)) {
        angle = SIN_DEG(this->iwork[KA_ACTOR_IWORK_8] * 400.0f) * this->iwork[KA_ACTOR_IWORK_8];
        Matrix_RotateY(gGfxMatrix, M_DTOR * angle, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, M_DTOR * angle, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, M_DTOR * angle, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_29);

    if ((this->timer_0C6 % 2) == 0) {
        gSPFogPosition(gMasterDisp++, gFogNear, 1005);
    }

    switch (this->animFrame) {
        case 0:
            gSPDisplayList(gMasterDisp++, aKaEnemyDL);
            break;

        case 1:
            gSPDisplayList(gMasterDisp++, aKaCornerianFighterDL);
            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
            Actor_DrawEngineGlow(this, EG_RED);
            break;
    }
}

extern u8 gMeMoraPartIdx[16];
extern f32 gMeMoraScale[16];
extern s16 D_800CFF94[16];

void MeMora_DrawParts(MeMora* this, f32 xTrans, f32 yTrans, f32 zTrans, f32 xRot, f32 yRot, f32 zRot, u8 partIdx,
                      f32 scale, bool colorFlicker);
// SYMTODO
#if 1
RECOMP_PATCH void MeMora_Draw(MeMora* this) {
    s16 i;
    s16 j;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposed(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_COMPONENT_AUTO,
                             G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_INTERPOLATE,
                             G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE,
                             G_EX_ORDER_LINEAR, G_EX_EDIT_ALLOW);

    for (i = this->work_04A; i < ARRAY_COUNT(D_800CFF94); i++) {
        j = (D_800CFF94[i] + this->counter_04E) % 100;
        MeMora_DrawParts(this, gMeMoraXpos[this->work_046][j], gMeMoraYpos[this->work_046][j],
                         gMeMoraZpos[this->work_046][j], gMeMoraXrot[this->work_046][j], gMeMoraYrot[this->work_046][j],
                         gMeMoraZrot[this->work_046][j], gMeMoraPartIdx[i], gMeMoraScale[i], this->timer_0C6 % 2U);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}
#endif

#if 0
RECOMP_PATCH void MeMora_DrawParts(MeMora* this, f32 xTrans, f32 yTrans, f32 zTrans, f32 xRot, f32 yRot, f32 zRot,
                                   u8 partIdx, f32 scale, bool colorFlicker) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };

    Matrix_Push(&gGfxMatrix);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + partIdx, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);
    Matrix_Translate(gGfxMatrix, xTrans, yTrans, zTrans + gPathProgress, MTXF_APPLY);

    if (partIdx != 1) {
        Matrix_RotateY(gGfxMatrix, M_DTOR * yRot, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, M_DTOR * xRot, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, M_DTOR * zRot, MTXF_APPLY);
    }

    Matrix_Scale(gGfxMatrix, scale, scale, 1.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);

    if (partIdx != 1) {
        RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
        if ((partIdx == 0) && (this->lockOnTimers[TEAM_ID_FOX] != 0)) {
            src.y += this->info.targetOffset;
            Matrix_MultVec3f(gGfxMatrix, &src, &gLockOnTargetViewPos[TEAM_ID_FOX]);
            if (gLockOnTargetViewPos[TEAM_ID_FOX].z > -500.0f) {
                this->lockOnTimers[TEAM_ID_FOX] = 0;
            }
        }
    } else {
        RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    }

    if (colorFlicker) {
        RCP_SetupDL_64();
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
    }

    gSPDisplayList(gMasterDisp++, gMemoraPartDL[partIdx]);
    Matrix_Pop(&gGfxMatrix);
    RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}
#endif

#if 0 // global

RECOMP_PATCH void Display_ArwingWingTrail_Draw(Player* player) {
    f32 sp5C = 70.0f;
    f32 sp58 = -18.0f;
    f32 sp54;
    f32 sp50;
    f32 yRot;

    if (player->wingPosition == 2) {
        sp5C = 108.0f;
        sp58 = -22.0f;
    }

    if (player->contrailScale != 0.0f) {
        sp54 = 0.0f;
        if ((gGameFrameCount % 2) != 0) {
            sp54 = 180.0f;
        }

        yRot = player->rot.y;
        if (yRot > 90.0f) {
            yRot -= 180.0f;
        }

        yRot *= 0.25f;
        sp50 = player->rot.x * 0.25f;

        if (player->state == PLAYERSTATE_LEVEL_COMPLETE) {
            yRot = 0.0f;
            sp50 = 0.0f;
        }

        RCP_SetupDL_64();
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 100);

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_PLAYER_TRAIL, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        if (player->arwing.leftWingState == WINGSTATE_INTACT) {
            Matrix_Push(&gGfxMatrix);
            Matrix_Translate(gGfxMatrix, sp5C, sp58, -100.0f, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_DTOR * sp50, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, -(M_DTOR * yRot), MTXF_APPLY);
            Matrix_Scale(gGfxMatrix, player->contrailScale, 1.0f, 50.0f, MTXF_APPLY);
            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -17.5f, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_PI / 2, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, M_DTOR * sp54, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, aBallDL);
            Matrix_Pop(&gGfxMatrix);
        }

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_PLAYER_TRAIL + 1, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);

        if (player->arwing.rightWingState == WINGSTATE_INTACT) {
            Matrix_Push(&gGfxMatrix);
            Matrix_Translate(gGfxMatrix, -sp5C, sp58, -100.0f, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_DTOR * sp50, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, -(M_DTOR * yRot), MTXF_APPLY);
            Matrix_Scale(gGfxMatrix, player->contrailScale, 1.0f, 50.0f, MTXF_APPLY);
            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -17.5f, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_PI / 2, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, M_DTOR * sp54, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, aBallDL);
            Matrix_Pop(&gGfxMatrix);
        }

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

#if 0
RECOMP_PATCH void Actor_DrawOnRails(Actor* this) {
    Vec3f sp34 = { 0.0f, 0.0f, 0.0f };

    if (this->info.draw != NULL) {
        switch (this->obj.id) {
            case OBJ_ACTOR_ME_MORA:
                MeMora_Draw(this);
                return;
            case OBJ_ACTOR_ZO_DODORA:
                Zoness_ZoDodora_Draw(this);
                return;
        }

        if ((this->obj.id == OBJ_ACTOR_EVENT) && (this->eventType == EVID_200)) {
            MeMora_Draw(this);
        } else {
            if (this->info.unk_19 != 0) {
                this->obj.pos.y += gCameraShakeY;
                Object_SetMatrix(&this->obj, this->info.drawType);
                this->obj.pos.y -= gCameraShakeY;
            } else if ((this->obj.id == OBJ_ACTOR_EVENT) && (this->eventType != EVID_A6_UMBRA_STATION)) {
                func_edisplay_8005D3CC(&this->obj, this->vwork[29].x, this->vwork[29].y,
                                       this->vwork[29].z + this->orient.z, this->info.drawType);
            } else {
                Object_SetMatrix(&this->obj, this->info.drawType);
            }

            if (this->info.drawType == 0) {
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);

                gSPDisplayList(gMasterDisp++, this->info.dList);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                Object_UpdateSfxSource(this->sfxSource);
            } else {
                this->info.draw(&this->obj);
                Object_UpdateSfxSource(this->sfxSource);
                if (((this->obj.id == OBJ_ACTOR_TEAM_BOSS) ||
                     ((this->obj.id == OBJ_ACTOR_SX_SLIPPY) && (this->animFrame > 0))) &&
                    (gReflectY > 0)) {
                    Matrix_MultVec3f(gGfxMatrix, &sp34, &gTeamArrowsViewPos[this->aiType]);
                }
            }

            if ((this->lockOnTimers[TEAM_ID_FOX] != 0) && (gReflectY > 0)) {
                sp34.y += this->info.targetOffset;
                Matrix_MultVec3f(gGfxMatrix, &sp34, &gLockOnTargetViewPos[TEAM_ID_FOX]);
                if (gLockOnTargetViewPos[TEAM_ID_FOX].z > -200.0f) {
                    this->lockOnTimers[TEAM_ID_FOX] = 0;
                }
            }
        }
    }
}
#endif

#if 0
RECOMP_PATCH void ActorAllRange_Draw(ActorAllRange* this) {
    f32 sp38;
    s32 pad[3];
    Vec3f sp1E4 = { 0.0f, 0.0f, 0.0f };
    Vec3f jointTable[30];
    f32 pad2;

    if (this->aiType != AI360_EVENT_HANDLER) {
        if ((this->iwork[8] != 0) && (this->aiType < AI360_GREAT_FOX)) {
            pad2 = SIN_DEG(this->iwork[8] * 400.0f);
            sp38 = this->iwork[8] * pad2;
            Matrix_RotateY(gGfxMatrix, M_DTOR * sp38, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_DTOR * sp38, MTXF_APPLY);
            Matrix_RotateZ(gGfxMatrix, M_DTOR * sp38, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
        }

        if ((this->timer_0C6 % 2) == 0) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_29);
            gSPFogPosition(gMasterDisp++, gFogNear, 1005);
        }

        switch (this->aiType) {
            case AI360_FOX:
            case AI360_FALCO:
            case AI360_SLIPPY:
            case AI360_PEPPY:
                Matrix_Push(&gGfxMatrix);
                ActorTeamArwing_Draw(this);
                Matrix_Pop(&gGfxMatrix);
                ActorAllRange_DrawBarrelRoll(this);
                break;

            case AI360_WOLF:
            case AI360_LEON:
            case AI360_PIGMA:
            case AI360_ANDREW:
                if (gCurrentLevel == LEVEL_VENOM_2) {
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    gSPDisplayList(gMasterDisp++, aStarWolfUpgradedShipDL);
                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, 30.0f, 0.0f, -60.0f, MTXF_APPLY);
                    Actor_DrawEngineGlow(this, EG_GREEN);
                    Matrix_Pop(&gGfxMatrix);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, -30.0f, 0.0f, -60.0f, MTXF_APPLY);
                    Actor_DrawEngineGlow(this, EG_GREEN);
                    Matrix_Pop(&gGfxMatrix);
                    ActorAllRange_DrawBarrelRoll(this);
                    ActorAllRange_DrawShield(this);
                } else {
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    gSPDisplayList(gMasterDisp++, aStarWolfStandardShipDL);
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    if (gCurrentLevel == LEVEL_BOLSE) {
                        Actor_DrawEngineGlow(this, EG_ORANGE);
                    } else {
                        Actor_DrawEngineGlow(this, EG_GREEN);
                    }
                }
                break;

            case AI360_KATT:
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);
                gSPDisplayList(gMasterDisp++, aKattShipDL);
                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                Actor_DrawEngineAndContrails(this);
                break;

            case AI360_BILL:
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);
                gSPDisplayList(gMasterDisp++, aBillShipDL);
                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                Actor_DrawEngineAndContrails(this);
                break;

            case AI360_GREAT_FOX:
                Display_SetSecondLight(&this->obj.pos);
                this->animFrame = 1;
                ActorCutscene_Draw(this);
                break;

            case AI360_MISSILE:
                Animation_GetFrameData(&aSzMissileAnim, 0, jointTable);
                Animation_DrawSkeleton(3, aSzMissileSkel, jointTable, ActorAllRange_MissileOverrideLimbDraw, NULL, this,
                                       gCalcMatrix);
                Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -400.0f, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, this->fwork[29], this->fwork[29], this->fwork[29], MTXF_APPLY);
                Actor_DrawEngineGlow(this, EG_ORANGE);
                break;

            default:
                if (gCurrentLevel == LEVEL_FORTUNA) {
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, 60.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    gSPDisplayList(gMasterDisp++, D_FO_6006BE0);
                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -100.0f, MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, 1.5f, 1.5f, 1.5f, MTXF_APPLY);
                    Actor_DrawEngineGlow(this, EG_GREEN);
                } else if (gCurrentLevel == LEVEL_KATINA) {
                    switch (this->animFrame) {
                        case 0:
                            // @recomp Tag the transform.
                            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                           G_EX_EDIT_ALLOW);
                            gSPDisplayList(gMasterDisp++, aKaEnemyLowPolyDL);
                            // @recomp Pop the transform id.
                            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                            break;
                        case 1:
                            // @recomp Tag the transform.
                            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                           G_EX_EDIT_ALLOW);
                            gSPDisplayList(gMasterDisp++, aKaCornerianFighterDL);
                            // @recomp Pop the transform id.
                            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                            Actor_DrawEngineGlow(this, EG_RED);
                            break;
                        case 3:
                            // @recomp Tag the transform.
                            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                           G_EX_EDIT_ALLOW);
                            gSPDisplayList(gMasterDisp++, aKaEnemyDL);
                            // @recomp Pop the transform id.
                            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, 30.0f, MTXF_APPLY);
                            ActorAllRange_DrawShield(this);
                            break;
                    }
                } else if (gCurrentLevel == LEVEL_SECTOR_Z) {
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    gSPDisplayList(gMasterDisp++, aSzInvaderIIIDL);
                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                    Actor_DrawEngineGlow(this, EG_GREEN);
                } else if (gCurrentLevel == LEVEL_BOLSE) {
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    gSPDisplayList(gMasterDisp++, D_BO_6008770);
                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                    Actor_DrawEngineGlow(this, EG_GREEN);
                    Matrix_Pop(&gGfxMatrix);
                    ActorAllRange_DrawShield(this);
                } else if (gCurrentLevel == LEVEL_VENOM_ANDROSS) {
                    Animation_GetFrameData(&D_VE2_600C200, this->work_04A, this->vwork);
                    Matrix_Scale(gGfxMatrix, 10.0f, 10.0f, 10.0f, MTXF_APPLY);
                    Animation_DrawSkeleton(0, D_VE2_600C2AC, this->vwork, NULL, NULL, this, &gIdentityMatrix);
                } else if (gCurrentLevel == LEVEL_VERSUS) {
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    gSPDisplayList(gMasterDisp++, D_versus_3015740);
                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                } else if (gCurrentLevel == LEVEL_TRAINING) {
                    if (this->aiIndex == AI360_FOX) {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                       G_EX_EDIT_ALLOW);
                        gSPDisplayList(gMasterDisp++, aStarWolfStandardShipDL);
                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                        Actor_DrawEngineGlow(this, EG_ORANGE);
                    } else {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                       G_EX_EDIT_ALLOW);
                        gSPDisplayList(gMasterDisp++, aVenomFighter1DL);
                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                        Actor_DrawEngineGlow(this, EG_GREEN);
                    }
                }
                break;
        }
    }
}
#endif

RECOMP_PATCH void MeMolarRock_Draw(MeMolarRock* this) {
    Matrix_Scale(gGfxMatrix, 1.0f, 1.0f, 1.0f, MTXF_APPLY);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aMeMolarRockDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void MeMeteor2_Draw(MeMeteor2* this) {
    RCP_SetupDL_29(this->work_046, gFogGreen, gFogBlue, gFogAlpha, this->work_048, gFogFar);
    Matrix_Scale(gGfxMatrix, 0.5f, 0.5f, 0.5f, MTXF_APPLY);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aMeMeteor1DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void MeLaserCannon1_Draw(MeLaserCannon1* this) {
    RCP_SetupDL_29(this->work_046, gFogGreen, gFogBlue, gFogAlpha, this->work_048, gFogFar);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aMeLaserCannon1DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void CoRadar_Draw(CoRadar* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (this->timer_0BC != 0) {
        RCP_SetupDL_27();
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
    }
    gSPDisplayList(gMasterDisp++, aCoRadarDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Meteo_MeMeteorShower1_Draw(MeMeteorShower1* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPDisplayList(gMasterDisp++, aMeMeteorShower1DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Meteo_MeMeteorShower2_Draw(MeMeteorShower2* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPDisplayList(gMasterDisp++, aMeMeteorShower2DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Meteo_MeMeteorShower3_Draw(MeMeteorShower3* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPDisplayList(gMasterDisp++, aMeMeteorShower3DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void ActorDebris_Draw(ActorDebris* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    switch (this->state) {
        case 0:
            Matrix_Translate(gGfxMatrix, 18.0f, 15.0f, -15.0f, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, aAwLeftWingDL);
            break;

        case 1:
            Matrix_Translate(gGfxMatrix, -18.0f, 15.0f, -15.0f, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, aAwRightWingDL);
            break;

        case 2:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, aAwFlap1DL);
            break;

        case 3:
            gSPDisplayList(gMasterDisp++, aAwLaserGun1DL);
            break;

        case 4:
            Graphics_SetScaleMtx(this->scale);
            if ((this->index % 2) != 0) {
                gSPDisplayList(gMasterDisp++, D_10194C0);
            } else {
                gSPDisplayList(gMasterDisp++, D_1024290);
            }
            break;

        case 39:
            gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFAC4[this->work_048]);
            break;

        case 40:
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
            switch (this->work_048) {
                case 0:
                    break;
                case 1:
                    RCP_SetupDL(&gMasterDisp, SETUPDL_61);
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                    break;
                case 2:
                    RCP_SetupDL(&gMasterDisp, SETUPDL_57);
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                    break;
                case 3:
                    RCP_SetupDL(&gMasterDisp, SETUPDL_33);
                    break;
            }

            if (gCurrentLevel != LEVEL_SOLAR) {
                gSPDisplayList(gMasterDisp++, D_TI_801B769C[this->work_046]);
            } else {
                if (gBosses[0].fwork[3] < 4800.0f) {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_30);
                    gDPSetFogColor(gMasterDisp++, 64, 32, 32, gFogAlpha);
                    gSPFogPosition(gMasterDisp++, gFogNear, gFogFar);
                } else {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_30);
                    gDPSetFogColor(gMasterDisp++, 16, 16, 16, gFogAlpha);
                    gSPFogPosition(gMasterDisp++, gFogNear, gFogFar);
                }
                Graphics_SetScaleMtx(this->scale);
                gSPDisplayList(gMasterDisp++, D_edisplay_800CFB40[this->work_046]);
            }
            break;

        case 41:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFADC[this->work_048]);
            break;

        case 42:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFB08[this->work_048]);
            break;

        case 43:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFB14[this->work_048]);
            break;

        case 44:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFB28[this->work_048]);
            break;

        case 45:
            gSPDisplayList(gMasterDisp++, aPlanetArwingAllRangeDL);
            break;

        case 46:
            if ((this->work_048 == 2) || (this->work_048 == 3) || (this->work_048 == 4)) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_33);
            }
            gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
            gSPDisplayList(gMasterDisp++, D_TI_801B7584[this->work_048]);
            break;

        case 47:
            gSPDisplayList(gMasterDisp++, D_TI_801B7608[this->work_048]);
            break;

        case 48:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFB64[this->work_048]);
            break;

        case 49:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFB88[this->work_048]);
            break;

        case 50:
            Graphics_SetScaleMtx(0.7f);

            if (this->iwork[1] == 1) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_30);
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
            } else if (this->iwork[1] == 2) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_30);
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                Graphics_SetScaleMtx(0.7f);
            }

            switch (this->iwork[0]) {
                case 0:
                    gSPDisplayList(gMasterDisp++, D_VE1_90234D0);
                    break;
                case 1:
                    gSPDisplayList(gMasterDisp++, D_VE1_9023290);
                    break;
                case 2:
                    gSPDisplayList(gMasterDisp++, D_VE1_900D180);
                    break;
                case 3:
                    gSPDisplayList(gMasterDisp++, D_VE1_9010FD0);
                    break;
            }

            if (this->iwork[1] != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_29);
                Graphics_SetScaleMtx(0.7f);
            }
            break;

        case 51:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFBA8[this->work_048]);
            break;

        case 52:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFBE4[this->work_048]);
            break;

        case 53:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFC0C[this->work_048]);
            break;

        case 54:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFC40[this->work_048]);
            break;

        case 55:
            Graphics_SetScaleMtx(this->scale);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFC50[this->work_048]);
            break;

        case 56:
            Graphics_SetScaleMtx(this->scale);
            RCP_SetupDL(&gMasterDisp, SETUPDL_41);
            Matrix_SetGfxMtx(&gMasterDisp);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 191, 255, 223, 255);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFC64[this->work_048]);
            break;

        case 58:
            Graphics_SetScaleMtx(this->scale);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_AQ_60148B0);
            break;

        case 59:
            Graphics_SetScaleMtx(this->scale);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_edisplay_800CFC7C[this->work_048]);
            break;

        case 70:
            gSPDisplayList(gMasterDisp++, aActorSuppliesDL);
            break;

        case 57:
            gSPDisplayList(gMasterDisp++, D_VE1_8019A008[this->work_048]);
            break;

        default:
            if (this->state >= 10) {
                if (this->state == 36) {
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                }
                gSPDisplayList(gMasterDisp++, D_edisplay_800CFA54[this->state - 10]);
            }
            break;
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void ActorMissileSeek_Draw(Actor* missile) {
    f32 scale;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(missile), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    switch (missile->eventType) {
        case 0:
            gSPDisplayList(gMasterDisp++, D_1028230);
            break;

        case 1:
            if (gCurrentLevel == LEVEL_AREA_6) {
                gSPDisplayList(gMasterDisp++, aAttacker3DL);
            } else {
                gSPDisplayList(gMasterDisp++, aGrangaFighter2DL);
            }
            break;
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    scale = 2.0f;
    if ((gGameFrameCount % 2) != 0) {
        scale = 1.7f;
    }

    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
    missile->iwork[11] = 1;
    Matrix_Scale(gGfxMatrix, scale, scale, scale, MTXF_APPLY);
    Actor_DrawEngineGlow(missile, EG_GREEN);
}

RECOMP_PATCH void CoMoleMissile_Draw(CoMoleMissile* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (this->animFrame != 0) {
        gSPDisplayList(gMasterDisp++, CoMoleMissileDL);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

// This actor is unused, but if anybody wants to use it in a patch, it better be tagged.
RECOMP_PATCH void MeteoBall_Draw(MeteoBall* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPDisplayList(gMasterDisp++, aMeMeteoBallDL);
    RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Macbeth_MaBoulder_Draw(MaBoulder* this) {
    if (this->state < 2) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        if (this->scale != 1.0f) {
            Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
        }
        gSPDisplayList(gMasterDisp++, aMaBoulderDL);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

RECOMP_PATCH void Macbeth_MaHorizontalLockBar_Draw(MaHorizontalLockBar* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aMaHorizontalLockBarDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Macbeth_MaVerticalLockBar_Draw(MaVerticalLockBar* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aMaVerticalLockBarDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Macbeth_MaBarrier_Draw(MaBarrier* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_57);
    if ((this->timer_0C6 % 2) != 0) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_58);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
    }
    gSPDisplayList(gMasterDisp++, aMaBarrierDL);
    RCP_SetupDL(&gMasterDisp, SETUPDL_29);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Macbeth_MaBombDrop_Draw(MaBombDrop* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    switch (this->state) {
        case 0:
            Graphics_SetScaleMtx(this->scale);
            RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            gSPDisplayList(gMasterDisp++, D_ENMY_PLANET_4008CE0);
            RCP_SetupDL(&gMasterDisp, SETUPDL_64);
            break;

        case 1:
            Matrix_Scale(gGfxMatrix, this->fwork[0], this->scale, 2.5f, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            RCP_SetupDL_40();
            gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
            gSPDisplayList(gMasterDisp++, D_ENMY_PLANET_4008F70);
            RCP_SetupDL(&gMasterDisp, SETUPDL_64);
            break;
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Macbeth_MaSpear_Draw(MaSpear* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (this->state < 2) {
        Graphics_SetScaleMtx(this->scale);
        if (this->iwork[0] >= 128) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_67);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, this->iwork[0]);
            gDPSetEnvColor(gMasterDisp++, 255, 48, 0, this->iwork[0]);
            Matrix_Scale(gGfxMatrix, 1.0f, this->fwork[2], 1.0f, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_MA_6013060);
            RCP_SetupDL(&gMasterDisp, SETUPDL_67);
            Matrix_Scale(gGfxMatrix, 1.0f, this->fwork[2], 1.0f, MTXF_APPLY);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 53, 53, 53, 255 - this->iwork[0]);
            gDPSetEnvColor(gMasterDisp++, 0, 0, 0, this->iwork[0]);
        } else {
            RCP_SetupDL(&gMasterDisp, SETUPDL_23);
            if ((this->iwork[7] % 2) != 0) {
                RCP_SetupDL_27();
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
            }
            if (this->iwork[7] > 0) {
                this->iwork[7]--;
            }
        }
        gSPDisplayList(gMasterDisp++, aMaSpearDL);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Macbeth_MaShockBox_Draw(MaShockBox* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aMaShockBoxDL);
    Matrix_Scale(gGfxMatrix, this->fwork[0], this->fwork[2], 1.0f, MTXF_APPLY);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, -10.0f, 0.0f, MTXF_APPLY);
    RCP_SetupDL(&gMasterDisp, SETUPDL_67);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 111, 175, 64, this->fwork[1]);
    gDPSetEnvColor(gMasterDisp++, 255, 255, 208, this->fwork[1]);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aMaShockBoxLightDL);
    Matrix_Pop(&gGfxMatrix);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Titania_TiDelphor_Draw(TiDelphor* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aTiDelphorDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Titania_TiDelphorHead_Draw(Actor* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, D_TI1_7008930);
    if ((this->timer_0C6 % 2) == 0) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_34);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 220, 220, 220, 255);
    } else {
        RCP_SetupDL(&gMasterDisp, SETUPDL_22);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 0, 0, 0, 255);
    }
    gSPDisplayList(gMasterDisp++, D_TI1_7009510);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoBall_Draw(ZoBall* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_70);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
    Matrix_Scale(gGfxMatrix, 2.6f, 2.6f, 2.6f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aZoBallDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoMine_Draw(ZoMine* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Scale(gGfxMatrix, 2.0f, 2.0f, 2.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_ZO_6025E60);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoCraneMagnet_Draw(ZoCraneMagnet* this) {
    f32 var_fv0;
    s32 i;
    s32 j;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Scale(gGfxMatrix, 2.0f, 2.0f, 2.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    RCP_SetupDL_57(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPDisplayList(gMasterDisp++, D_ZO_601C590);
    RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

    if (((this->state == 1) && (gBosses[0].timer_052 != 0)) || (this->state == 0)) {
        Matrix_RotateY(gGfxMatrix, gGameFrameCount * M_DTOR, MTXF_APPLY);
    }

    var_fv0 = sZoFwork[61] + -1.0f * this->fwork[0] - this->obj.pos.y;

    for (i = 1; var_fv0 >= 0.0f; i++) {
        var_fv0 -= 117.0f;
    }

    if (i > 30) {
        i = 30;
    }
    if ((i <= 0) || (this->fwork[0] == 0)) {
        i = 1;
    }

    for (j = 0; j < i; j++) {
        Matrix_Translate(gGfxMatrix, 0.0f, 30.0f, 0.0f, MTXF_APPLY);
        Matrix_RotateY(gGfxMatrix, M_PI / 2, MTXF_APPLY);
        Matrix_Push(&gGfxMatrix);
        Matrix_Scale(gGfxMatrix, 0.75f, 0.75f, 0.75f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, D_ZO_6018660);
        Matrix_Pop(&gGfxMatrix);
    }
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoTanker_Draw(ZoTanker* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, D_ZO_6006360);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoRadarBuoy_Draw(ZoRadarBuoy* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aZoRadarBuoyDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoSupplyCrane_Draw(ZoSupplyCrane* this) {
    f32 var_fv1;
    s32 i;
    s32 var_s1;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Push(&gGfxMatrix);
    Matrix_RotateZ(gGfxMatrix, this->fwork[0] * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_ZO_601A340);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, -320.0f, 0.0f, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.0f, 1.3, 1.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_ZO_6013330);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_RotateZ(gGfxMatrix, M_PI / 2, MTXF_APPLY);
    Matrix_Translate(gGfxMatrix, -110.0f, 0.0f, 0.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_ZO_601D680);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, this->fwork[1], this->fwork[2], 0.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->fwork[4] * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 0.75f, 0.75f, 0.75f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_ZO_601C590);
    RCP_SetupDL_57(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    Matrix_RotateY(gGfxMatrix, gGameFrameCount * M_DTOR, MTXF_APPLY);

    var_fv1 = (fabsf(this->fwork[3]) * 1.3f) + 50.0f;
    for (var_s1 = 0; var_fv1 > 0.0f; var_s1++) {
        var_fv1 -= 9.3f;
    }

    if (var_s1 > 50) {
        var_s1 = 50;
    }
    if (var_s1 <= 0) {
        var_s1 = 1;
    }

    for (i = 0; i < var_s1; i++) {
        Matrix_Translate(gGfxMatrix, 0.0f, 9.3f, 0.0f, MTXF_APPLY);
        Matrix_RotateY(gGfxMatrix, M_PI / 2, MTXF_APPLY);
        Matrix_Push(&gGfxMatrix);
        Matrix_Scale(gGfxMatrix, 0.5f, 0.5f, 0.5f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, D_ZO_6018660);
        Matrix_Pop(&gGfxMatrix);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Zoness_ZoSearchLight_Draw(ZoSearchLight* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_72);

    if (this->iwork[0] != 0) {
        Matrix_Translate(gGfxMatrix, 0.0f, this->fwork[0], 0.0f, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, (this->fwork[4] + this->obj.rot.z) * M_DTOR, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, this->fwork[1], this->fwork[2], this->fwork[3], MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        if (gMissedZoSearchlight) {
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 191, 43, 255);
            gDPSetEnvColor(gMasterDisp++, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
            gDPSetEnvColor(gMasterDisp++, 255, 255, 127, 255);
        }
    } else if (gMissedZoSearchlight) {
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 191, 43, 50);
        gDPSetEnvColor(gMasterDisp++, 255, 0, 0, 255);
    } else {
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 50);
        gDPSetEnvColor(gMasterDisp++, 255, 255, 127, 255);
    }

    gSPDisplayList(gMasterDisp++, D_ZO_60181E0);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Aquas_AqPearl_Draw(AqPearl* this) {
    if (this->timer_0BC == 0) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        Graphics_SetScaleMtx(0.8f);
        RCP_SetupDL(&gMasterDisp, SETUPDL_61);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, this->iwork[1], this->iwork[2], this->iwork[3], 255);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, aAqPearlDL);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

RECOMP_PATCH void Aquas_AqBoulder_Draw(AqBoulder* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aAqBoulderDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void SectorZ_SpaceJunkDraw(SzSpaceJunk* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aSzSpaceJunk2DL);
    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
    RCP_SetupDL(&gMasterDisp, SETUPDL_57);
    gSPDisplayList(gMasterDisp++, aSzSpaceJunk4DL);
    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

// Actors OBJ_ACTOR_SO_ROCK_1 to OBJ_ACTOR_SO_ROCK_3
RECOMP_PATCH void Solar_SoRock_Draw(SoRock1* this) {
    if (this->state != 0) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        Matrix_Push(&gGfxMatrix);
        Matrix_RotateY(gGfxMatrix, this->orient.y * M_DTOR, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, this->orient.x * M_DTOR, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);

        switch (this->obj.id) {
            case OBJ_ACTOR_SO_ROCK_1:
                gSPDisplayList(gMasterDisp++, aSoRock1DL);
                break;

            case OBJ_ACTOR_SO_ROCK_2:
                if ((gGameFrameCount % 2) == 0) {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_41);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 0, 255);
                }
                gSPDisplayList(gMasterDisp++, aSoRock2DL);
                break;

            case OBJ_ACTOR_SO_ROCK_3:
                gSPDisplayList(gMasterDisp++, aSoRock3DL);
                break;
        }

        Matrix_Pop(&gGfxMatrix);
        Graphics_SetScaleMtx(this->scale * 3.5f);
        RCP_SetupDL(&gMasterDisp, SETUPDL_64);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 128, 128, 160);
        gSPDisplayList(gMasterDisp++, D_i3_801BF92C[this->animFrame]);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

RECOMP_PATCH void Venom1_Ve1Pillar2_Draw(Ve1Pillar2* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Scale(gGfxMatrix, 1.0f, 0.5f, 1.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aVe1Pillar3DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Andross_AndLaserEmitter_Draw(AndLaserEmitter* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aAndLaserEmitterDL);

    if (this->timer_0BC != 0) {
        f32 scale = 2.5f;
        u8 alpha = 16;

        if ((gGameFrameCount % 2) != 0) {
            alpha = 64;
            scale *= 1.2f;
        }
        Matrix_Scale(gGfxMatrix, scale, scale, scale, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, M_PI / 2, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        RCP_SetupDL(&gMasterDisp, SETUPDL_67);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, alpha);
        gDPSetEnvColor(gMasterDisp++, 255, 128, 128, alpha);
        gSPDisplayList(gMasterDisp++, aOrbDL);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Andross_AndBrainWaste_Draw(AndBrainWaste* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_61);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
    Matrix_RotateZ(gGfxMatrix, this->orient.z * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.1f, 0.9f, 1.0f, MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix, -this->orient.z * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.1f, 0.9f, 1.0f, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 3.0f, 3.0f, 1.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aAndBrainWasteDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Titania_TiBomb_Draw(TiBomb* this) {
    s32 index;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_30);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
    Matrix_Scale(gGfxMatrix, 1.5f, 1.5f, 1.5f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aTi1Bomb1DL);
    RCP_SetupDL(&gMasterDisp, SETUPDL_34);
    index = this->iwork[0];
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, D_i5_801B75E4[0][index], D_i5_801B75E4[1][index],
                    D_i5_801B75E4[2][index], 255);
    gSPDisplayList(gMasterDisp++, aTi1Bomb2DL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Titania_TiBoulder_Draw(TiBoulder* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (this->scale != 1.0f) {
        Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
    }
    gSPDisplayList(gMasterDisp++, aTiBoulderDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

// Actors 205, 206, 208, 209, 210, 211, 212, 213
#define TAG_TRAIN (0)

RECOMP_PATCH void Macbeth_Train_Draw(Actor* this) {
    Vec3f frameTable[50];
    s32 id;

    if (gPlayer[0].state == PLAYERSTATE_ACTIVE) {
        if (((gPlayer[0].trueZpos - this->obj.pos.z) > 7000.0f) ||
            ((gPlayer[0].trueZpos - this->obj.pos.z) < -1000.0f)) {
            return;
        }
    } else {
        if (((gPlayer[0].trueZpos - this->obj.pos.z) > 7000.0f) ||
            ((gPlayer[0].trueZpos - this->obj.pos.z) < -5000.0f)) {
            return;
        }
    }

    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, this->fwork[25], this->fwork[8] + 25.0f, 0.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->fwork[26] * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, this->fwork[29] * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);

    if ((this->obj.id != OBJ_ACTOR_MA_TRAIN_CAR_1) && (this->obj.id != OBJ_ACTOR_MA_LOCOMOTIVE)) {
        if (((gPlayer[0].trueZpos - this->obj.pos.z) > 3000.0f) && (D_i5_801BE310 != this->iwork[5])) {
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 0), G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);

            gSPDisplayList(gMasterDisp++, D_MA_6027BF0);
            gSPDisplayList(gMasterDisp++, D_MA_601BE90);

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
        } else {
            Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
            Animation_GetFrameData(&D_MA_602EA0C, 0, frameTable);
            Animation_DrawSkeleton(1, D_MA_602EBB8, frameTable, Macbeth_801A0A74, NULL, this, &gIdentityMatrix);
        }
    }

    switch (this->obj.id) {
        case OBJ_ACTOR_MA_TRAIN_CAR_6:
            if (this->iwork[13] == 0) {
                if ((this->iwork[7] % 2) != 0) {
                    RCP_SetupDL_27();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                }
                if (this->iwork[7] > 0) {
                    this->iwork[7]--;
                }
                Animation_GetFrameData(&D_MA_6027320, 0, frameTable);
                Animation_DrawSkeleton(1, D_MA_602742C, frameTable, Macbeth_801A0B20, NULL, this, &gIdentityMatrix);
            }
            break;

        case OBJ_ACTOR_MA_TRAIN_CAR_4:
            if (this->iwork[13] == 0) {
                Animation_GetFrameData(&D_MA_6027A04, 0, frameTable);
                Animation_DrawSkeleton(1, D_MA_6027AF0, frameTable, Macbeth_801A0B00, NULL, this, &gIdentityMatrix);

                Matrix_Translate(gGfxMatrix, 0.0f, 205.0f, 0.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, this->fwork[4] * M_DTOR, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 1), G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                if ((this->iwork[7] % 2) != 0) {
                    RCP_SetupDL_27();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                }
                if (this->iwork[7] > 0) {
                    this->iwork[7]--;
                }

                if (this->iwork[3] >= 3) {
                    gSPDisplayList(gMasterDisp++, D_MA_6027EB0);
                } else {
                    gSPDisplayList(gMasterDisp++, D_MA_60288A0);
                }

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
            break;

        case OBJ_ACTOR_MA_TRAIN_CAR_3:
            if (this->iwork[17] != 2) {
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 2), G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                Matrix_Translate(gGfxMatrix, 0.0f, 5.0f, 0.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                if ((this->iwork[8] % 2) != 0) {
                    RCP_SetupDL_27();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                }
                if (this->iwork[8] > 0) {
                    this->iwork[8]--;
                }
                gSPDisplayList(gMasterDisp++, D_MA_6029890);
                RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
            break;

        case OBJ_ACTOR_MA_TRAIN_CAR_5:
            if (this->iwork[17] != 2) {
                Matrix_Translate(gGfxMatrix, 0.0f, -15.0f, 0.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);

                if ((this->iwork[8] % 2) != 0) {
                    RCP_SetupDL_27();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                }
                if (this->iwork[8] > 0) {
                    this->iwork[8]--;
                }

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 3), G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                if (this->iwork[17] == 0) {
                    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                    gSPDisplayList(gMasterDisp++, D_MA_6004440);
                } else {
                    RCP_SetupDL(&gMasterDisp, SETUPDL_57);
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                    gSPDisplayList(gMasterDisp++, D_MA_6022200);
                    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
                }

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            }
            break;

        case OBJ_ACTOR_MA_TRAIN_CAR_7:
            if (this->iwork[13] < 2) {
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 4), G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                Matrix_Translate(gGfxMatrix, 0.0f, -5.0f, 0.0f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                RCP_SetupDL(&gMasterDisp, SETUPDL_57);
                if ((this->iwork[7] % 2) != 0) {
                    RCP_SetupDL_27();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                }
                if (this->iwork[7] > 0) {
                    this->iwork[7]--;
                }
                gSPDisplayList(gMasterDisp++, D_MA_6024670);
                RCP_SetupDL(&gMasterDisp, SETUPDL_29);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
            break;

        case OBJ_ACTOR_MA_TRAIN_CAR_2:
            if (this->iwork[13] < 2) {
                if ((this->iwork[7] % 2) != 0) {
                    RCP_SetupDL_27();
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                }
                if (this->iwork[7] > 0) {
                    this->iwork[7]--;
                }

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 5), G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
                if (this->iwork[13] == 0) {
                    Matrix_Translate(gGfxMatrix, 0.0f, -5.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_MA_60269E0);
                } else {
                    Matrix_Translate(gGfxMatrix, 0.0f, -5.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_MA_6017720);
                }

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                gDPSetTextureFilter(gMasterDisp++, G_TF_BILERP);
            }
            break;

        case OBJ_ACTOR_MA_TRAIN_CAR_1:
            Animation_GetFrameData(&D_MA_601EAB0, 0, frameTable);
            Animation_DrawSkeleton(1, D_MA_601EBBC, frameTable, Macbeth_MaTrainCar1_OverrideLimbDraw, NULL, this,
                                   &gIdentityMatrix);
            break;

        case OBJ_ACTOR_MA_LOCOMOTIVE:
            Matrix_Translate(gGfxMatrix, this->fwork[3], 0.0f, 0.0f, MTXF_APPLY);

            if (D_i5_801BE320[21] == 0) {
                Animation_GetFrameData(&D_MA_6010220, 0, frameTable);
            } else if (D_i5_801BE320[21] == 1) {
                Animation_GetFrameData(&D_MA_600FEC4, D_i5_801BE320[22], frameTable);
            } else {
                Animation_GetFrameData(&D_MA_6010144, D_i5_801BE320[22], frameTable);
            }

            Animation_DrawSkeleton(1, D_MA_601042C, frameTable, Macbeth_MaLocomotive_OverrideLimbDraw,
                                   Macbeth_MaLocomotive_PostLimbDraw, this, &gIdentityMatrix);

            if (gPlayer[0].state == PLAYERSTATE_LEVEL_COMPLETE) {
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 6), G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                RCP_SetupDL(&gMasterDisp, SETUPDL_29);
                gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
                gSPDisplayList(gMasterDisp++, D_MA_6003370);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
            break;
    }

    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, this->fwork[21], this->fwork[6] + 65.0f, -420.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->fwork[22] * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, this->fwork[27] * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 7), G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);

    if ((gPlayer[0].trueZpos - this->obj.pos.z) > 3000.0f) {
        gSPDisplayList(gMasterDisp++, D_MA_6027D40);
    } else if (this->vel.z > -2.0f) {
        gSPDisplayList(gMasterDisp++, D_MA_60227F0);
    } else {
        gSPDisplayList(gMasterDisp++, D_MA_60239D0);
    }

    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, this->fwork[23], this->fwork[7] + 65.0f, 420.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->fwork[24] * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, this->fwork[28] * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    RCP_SetupDL(&gMasterDisp, SETUPDL_29);

    if ((gPlayer[0].trueZpos - this->obj.pos.z) > 3000.0f) {
        gSPDisplayList(gMasterDisp++, D_MA_6027D40);
    } else if (this->vel.z > -2.0f) {
        gSPDisplayList(gMasterDisp++, D_MA_60227F0);
    } else {
        gSPDisplayList(gMasterDisp++, D_MA_60239D0);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix);

    id = this->obj.id;
    if ((id == OBJ_ACTOR_MA_TRAIN_CAR_3) || (id == OBJ_ACTOR_MA_TRAIN_CAR_5)) {
        if (this->iwork[13] != 2) {
            Matrix_Push(&gGfxMatrix);
            Matrix_Translate(gGfxMatrix, this->fwork[21], this->fwork[6] + 10.0f, -420.0f, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, this->fwork[26] * M_DTOR, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, this->fwork[29] * M_DTOR, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);

            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 8), G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);

            if ((this->iwork[7] % 2) != 0) {
                RCP_SetupDL_27();
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
            }
            if (this->iwork[7] > 0) {
                this->iwork[7]--;
            }

            if (this->iwork[13] == 0) {
                gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                gSPDisplayList(gMasterDisp++, D_MA_6004440);
            } else {
                RCP_SetupDL(&gMasterDisp, SETUPDL_57);
                gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                gSPDisplayList(gMasterDisp++, D_MA_6022200);
                RCP_SetupDL(&gMasterDisp, SETUPDL_29);
            }

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

            RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            Matrix_Pop(&gGfxMatrix);
        }

        if (this->iwork[21] != 2) {
            Matrix_Push(&gGfxMatrix);
            Matrix_Translate(gGfxMatrix, this->fwork[23], this->fwork[7] + 10.0f, 420.0f, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, this->fwork[26] * M_DTOR, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, this->fwork[29] * M_DTOR, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);

            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + (TAG_TRAIN + 9), G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);

            if ((this->iwork[9] % 2) != 0) {
                RCP_SetupDL_27();
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
            }
            if (this->iwork[9] > 0) {
                this->iwork[9]--;
            }

            if (this->iwork[21] == 0) {
                gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                gSPDisplayList(gMasterDisp++, D_MA_6004440);
            } else {
                RCP_SetupDL(&gMasterDisp, SETUPDL_57);
                gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                gSPDisplayList(gMasterDisp++, D_MA_6022200);
                RCP_SetupDL(&gMasterDisp, SETUPDL_29);
            }
            RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

            Matrix_Pop(&gGfxMatrix);
        }
    }
}

RECOMP_PATCH void Macbeth_MaRailroadSwitch_Draw(MaRailroadSwitch* this) {
    Vec3f frameTable[50];

    Matrix_Push(&gGfxMatrix);
    Animation_GetFrameData(&D_MA_602FEB4, 0, frameTable);
    Animation_DrawSkeleton(1, D_MA_602FFA0, frameTable, Macbeth_MaRailroadSwitch_OverrideLimbDraw, NULL, this,
                           &gIdentityMatrix);
    Matrix_Pop(&gGfxMatrix);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, this->fwork[2] + 204.0f, 0.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->fwork[1] * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_MA_602FFC0);
    Matrix_Pop(&gGfxMatrix);
    RCP_SetupDL(&gMasterDisp, SETUPDL_34);
    gDPSetTextureFilter(gMasterDisp++, G_TF_POINT);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, this->fwork[0], 0, 0, 255);
    Matrix_Push(&gGfxMatrix);
    Matrix_Translate(gGfxMatrix, 0.0f, this->fwork[2] + 204.0f, 0.0f, MTXF_APPLY);
    Matrix_RotateY(gGfxMatrix, this->fwork[1] * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, D_MA_602F380);
    gDPSetTextureFilter(gMasterDisp++, G_TF_BILERP);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix);
}

RECOMP_PATCH void Aquas_AqAnglerFish_Draw(AqAnglerFish* this) {
    Vec3f frameTable[30];

    Matrix_Push(&gCalcMatrix);
    Matrix_Push(&gGfxMatrix);
    Matrix_Scale(gCalcMatrix, this->scale, this->scale, this->scale, MTXF_APPLY);
    Animation_GetFrameData(&aAqAnglerFishAnim, this->animFrame, frameTable);
    Animation_DrawSkeleton(3, aAqAnglerFishSkel, frameTable, Aquas_AqAnglerFish_OverrideLimbDraw,
                           Aquas_AqAnglerFish_PostLimbDraw, this, gCalcMatrix);
    Matrix_Pop(&gGfxMatrix);
    Matrix_Pop(&gCalcMatrix);
    Matrix_Push(&gGfxMatrix);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    Matrix_Translate(gGfxMatrix, this->fwork[8], this->fwork[9], this->fwork[10], MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, this->fwork[5], this->fwork[6], this->fwork[7], MTXF_APPLY);
    RCP_SetupDL(&gMasterDisp, SETUPDL_49);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, (s32) this->iwork[12]);
    gDPSetEnvColor(gMasterDisp++, 127, 127, 0, (s32) this->iwork[12]);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aOrbDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix);
}

RECOMP_PATCH void Aquas_AqStoneColumn_Draw(AqStoneColumn* this) {
    Vec3f frameTable[30];

    if (this->state != 0) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        RCP_SetupDL(&gMasterDisp, SETUPDL_55);
        switch (this->iwork[0]) {
            case 0:
                if (this->state != 0) {
                    if ((this->iwork[3] == 0) && (this->info.drawType == 2)) {
                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                        Animation_GetFrameData(&aAqStoneColumnAnim, 0, frameTable);
                        Animation_DrawSkeleton(3, aAqStoneColumnSkel, frameTable, NULL,
                                               Aquas_AqStoneColumn_PostLimbDraw, this, gCalcMatrix);
                    } else {
                        gSPDisplayList(gMasterDisp++, D_AQ_6014520);
                    }
                }
                break;
            case 1:
                gSPDisplayList(gMasterDisp++, D_AQ_60137F0);
                break;
            case 2:
                gSPDisplayList(gMasterDisp++, D_AQ_6014030);
                break;
        }

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

RECOMP_PATCH void Aquas_AqOyster_Draw(AqOyster* this) {
    Graphics_SetScaleMtx(3.0f);
    RCP_SetupDL(&gMasterDisp, SETUPDL_56);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 143, 143, 255);
    Animation_GetFrameData(&aAqOysterAnim, this->animFrame, this->vwork);
    Animation_DrawSkeleton(1, aAqOysterSkel, this->vwork, NULL, NULL, &this->index, &gIdentityMatrix);

    if (this->health != 0) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        RCP_SetupDL(&gMasterDisp, SETUPDL_55);
        Matrix_Scale(gGfxMatrix, this->fwork[0], this->fwork[1], this->fwork[2], MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 0.0f, -8.0f, 51.0f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, aAqOysterDL);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

// Bacoon Snake (OBJ_ACTOR_AQ_SANADA)
RECOMP_PATCH void Aquas_Actor255_Draw(Actor255* this) {
    s32 i;
    f32 xz;
    f32 yRot;
    f32 xRot;
    s32 index;

    Matrix_Pop(&gGfxMatrix);
    Matrix_Push(&gGfxMatrix);

    for (i = 0; i <= this->iwork[1]; i++) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + i, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        if ((this->iwork[1] != 10) && (i == 0)) {
            i = 1;
        }

        index = ((this->iwork[0] * 50) + this->counter_04E) - D_i3_801BFB64[i];

        if (index < (this->iwork[0] * 50)) {
            if (index > 0) {
                index -= this->iwork[0] * 50;
            }
            index = index + ((this->iwork[0] + 1) * 50);
        }

        D_i3_801C27C0 = &D_i3_801C27C8[index];

        xRot = D_i3_801C27C0->rot.x;
        yRot = D_i3_801C27C0->rot.y;

        if (i >= 2) {
            yRot = RAD_TO_DEG(Math_Atan2F(gPlayer[0].cam.eye.x - D_i3_801C27C0->pos.x,
                                          gPlayer[0].cam.eye.z - (D_i3_801C27C0->pos.z + gPathProgress)));
            xz = sqrtf(((gPlayer[0].cam.eye.z - (D_i3_801C27C0->pos.z + gPathProgress)) *
                        (gPlayer[0].cam.eye.z - (D_i3_801C27C0->pos.z + gPathProgress))) +
                       ((gPlayer[0].cam.eye.x - D_i3_801C27C0->pos.x) * (gPlayer[0].cam.eye.x - D_i3_801C27C0->pos.x)));
            xRot = RAD_TO_DEG(-Math_Atan2F(gPlayer[0].cam.eye.y - D_i3_801C27C0->pos.y, xz));
        }

        Aquas_801ADF7C(D_i3_801C27C0->pos.x, D_i3_801C27C0->pos.y, D_i3_801C27C0->pos.z, xRot, yRot,
                       D_i3_801C27C0->rot.z, D_i3_801BFB90[i], this->timer_0C6 % 2U, this->scale, i);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

RECOMP_PATCH void Aquas_Actor256_Draw(Actor256* this) {
    f32 var_fv0;
    u8 var_t1;
    u8 i;
    Vtx* var_t5;
    Vtx* temp_v1_2;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if ((this->timer_0C6 != 0) && (this->state == 0) && (gPlayState != PLAY_PAUSE)) {
        this->iwork[1]++;
        this->iwork[1] %= 8;
    }

    temp_v1_2 = SEGMENTED_TO_VIRTUAL(D_AQ_6019078);
    if (this->iwork[1] < 4) {
        var_t5 = SEGMENTED_TO_VIRTUAL(D_AQ_6018C78);
    } else {
        var_t5 = SEGMENTED_TO_VIRTUAL(D_AQ_6018878);
    }

    var_t1 = this->iwork[1] % 4;
    if (var_t1 >= 3) {
        var_t1 = 4 - var_t1;
    }

    var_fv0 = this->timer_0C6 / 60.0f;
    if (var_fv0 < 0.1f) {
        var_fv0 = 0.1f;
    }

    for (i = 0; i < 28; i += 1) {
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.ob[0] =
            temp_v1_2[i].n.ob[0] + (s16) ((((var_t5[i].n.ob[0] - temp_v1_2[i].n.ob[0]) * var_t1) / 2) * var_fv0);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.ob[1] =
            temp_v1_2[i].n.ob[1] + (((var_t5[i].n.ob[1] - temp_v1_2[i].n.ob[1]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.ob[2] =
            temp_v1_2[i].n.ob[2] + (((var_t5[i].n.ob[2] - temp_v1_2[i].n.ob[2]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.flag = temp_v1_2[i].n.flag;
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.tc[0] =
            temp_v1_2[i].n.tc[0] + (((var_t5[i].n.tc[0] - temp_v1_2[i].n.tc[0]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.tc[1] =
            temp_v1_2[i].n.tc[1] + (((var_t5[i].n.tc[1] - temp_v1_2[i].n.tc[1]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.n[0] =
            temp_v1_2[i].n.n[0] + (((var_t5[i].n.n[0] - temp_v1_2[i].n.n[0]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.n[1] =
            temp_v1_2[i].n.n[1] + (((var_t5[i].n.n[1] - temp_v1_2[i].n.n[1]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.n[2] =
            temp_v1_2[i].n.n[2] + (((var_t5[i].n.n[2] - temp_v1_2[i].n.n[2]) * var_t1) / 2);
        D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][i].n.a = temp_v1_2[i].n.a;
    }

    Matrix_Scale(gGfxMatrix, this->fwork[1] - 0.25f + ((1.5f - this->scale) * 0.5f), this->scale, this->fwork[1],
                 MTXF_APPLY);

    if (this->state != 0) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_32);
    } else if (gBosses[0].swork[0] == 1) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_4);
    } else if ((this->timer_0C6 % 2) == 0) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    } else {
        RCP_SetupDL(&gMasterDisp, SETUPDL_22);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
    }

    Matrix_SetGfxMtx(&gMasterDisp);

    gDPSetTextureLUT(gMasterDisp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gMasterDisp++, D_AQ_6008FC8);
    gDPLoadTextureBlock(gMasterDisp++, D_AQ_6008EC8, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMasterDisp++, D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2], 14, 0);
    gSP1Triangle(gMasterDisp++, 0, 1, 2, 0);
    gSP1Triangle(gMasterDisp++, 3, 1, 0, 0);
    gSP1Triangle(gMasterDisp++, 4, 5, 0, 0);
    gSP1Triangle(gMasterDisp++, 0, 6, 7, 0);
    gSP1Triangle(gMasterDisp++, 2, 6, 0, 0);
    gSP1Triangle(gMasterDisp++, 0, 5, 3, 0);
    gSP1Triangle(gMasterDisp++, 0, 8, 4, 0);
    gSP1Triangle(gMasterDisp++, 7, 8, 0, 0);
    gSP1Triangle(gMasterDisp++, 9, 4, 8, 0);
    gSP1Triangle(gMasterDisp++, 8, 7, 10, 0);
    gSP1Triangle(gMasterDisp++, 8, 11, 9, 0);
    gSP1Triangle(gMasterDisp++, 10, 11, 8, 0);
    gSP1Triangle(gMasterDisp++, 12, 4, 9, 0);
    gSP1Triangle(gMasterDisp++, 13, 5, 4, 0);
    gSP1Triangle(gMasterDisp++, 4, 12, 13, 0);
    gSP1Triangle(gMasterDisp++, 3, 5, 13, 0);
    gSP1Triangle(gMasterDisp++, 13, 6, 2, 0);
    gSP1Triangle(gMasterDisp++, 7, 6, 13, 0);
    gSP1Triangle(gMasterDisp++, 13, 12, 7, 0);
    gSP1Triangle(gMasterDisp++, 10, 7, 12, 0);
    gSPVertex(gMasterDisp++, &D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][1], 3, 0);
    gSPVertex(gMasterDisp++, &D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][9], 2, 3);
    gSPVertex(gMasterDisp++, &D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][12], 8, 5);
    gSP1Triangle(gMasterDisp++, 0, 2, 7, 0);
    gSP1Triangle(gMasterDisp++, 7, 2, 8, 0);
    gSP1Triangle(gMasterDisp++, 6, 8, 2, 0);
    gSP1Triangle(gMasterDisp++, 8, 1, 9, 0);
    gSP1Triangle(gMasterDisp++, 1, 8, 6, 0);
    gSP1Triangle(gMasterDisp++, 5, 10, 4, 0);
    gSP1Triangle(gMasterDisp++, 3, 10, 5, 0);
    gSP1Triangle(gMasterDisp++, 8, 12, 7, 0);
    gSP1Triangle(gMasterDisp++, 7, 11, 0, 0);
    gSP1Triangle(gMasterDisp++, 0, 11, 9, 0);
    gSP1Triangle(gMasterDisp++, 9, 1, 0, 0);
    gSP1Triangle(gMasterDisp++, 9, 12, 8, 0);
    gDPLoadTLUT_pal256(gMasterDisp++, D_AQ_6019338);
    gDPLoadTextureBlock(gMasterDisp++, D_AQ_6019238, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gMasterDisp++, &D_i3_801C3A88[this->iwork[0]][gSysFrameCount % 2][20], 8, 0);
    gSP1Triangle(gMasterDisp++, 0, 1, 2, 0);
    gSP1Triangle(gMasterDisp++, 2, 3, 0, 0);
    gSP1Triangle(gMasterDisp++, 4, 5, 6, 0);
    gSP1Triangle(gMasterDisp++, 6, 7, 4, 0);
    gDPPipeSync(gMasterDisp++);
    gDPSetTextureLUT(gMasterDisp++, G_TT_NONE);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Aquas_Actor257_Draw(Actor257* this) {
    Matrix_RotateY(gGfxMatrix, (this->obj.rot.x + this->fwork[3]) * M_DTOR, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, (this->obj.rot.y + this->fwork[4]) * M_DTOR, MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix, (this->obj.rot.z + this->fwork[5]) * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, this->fwork[0], this->fwork[1], this->fwork[2], MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);

    if ((this->timer_0C6 % 2) == 0) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_57);
    } else {
        RCP_SetupDL(&gMasterDisp, SETUPDL_61);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
    }

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    switch (this->iwork[0]) {
        case 0:
            gSPDisplayList(gMasterDisp++, D_AQ_6019E80);
            break;
        case 1:
            gSPDisplayList(gMasterDisp++, D_AQ_60194D0);
            break;
        case 2:
            gSPDisplayList(gMasterDisp++, D_AQ_6019880);
            break;
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

#endif // global scope