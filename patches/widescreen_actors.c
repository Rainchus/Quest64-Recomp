#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "patches.h"

extern Vec3f sViewPos;
extern bool sDrewActor;
extern Vec3f gLockOnTargetViewPos[];
extern Matrix D_edisplay_801615F0;
extern Vec3f D_edisplay_801615D0;
extern Gfx D_VE2_6007650[];

void func_edisplay_8005D1F0(Object* obj, s32 drawType);
void Object_SetCullDirection(s32 arg0);
void func_edisplay_8005D008(Object* obj, s32 drawType);

RECOMP_PATCH void Actor_DrawAllRange(Actor* this) {
    s32 playerNum;
    Vec3f srcViewPos = { 0.0f, 0.0f, 0.0f };
    f32 var_fa1;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;

    sDrewActor = false;

    if (this->info.drawType == 2) {
        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, gPathProgress, MTXF_APPLY);
        Matrix_Translate(gCalcMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z, MTXF_NEW);
        Matrix_Push(&gGfxMatrix);
        Matrix_Mult(gGfxMatrix, gCalcMatrix, MTXF_APPLY);
        Matrix_MultVec3f(gGfxMatrix, &srcViewPos, &sViewPos);
        Matrix_Pop(&gGfxMatrix);

        var_fv0 = 0.0f;
        var_fv1 = -12000.0f;
        if ((this->obj.id == OBJ_ACTOR_ALLRANGE) && (this->aiType >= AI360_GREAT_FOX)) {
            var_fv0 = 1000.0f;
            var_fv1 = -25000.0f;
        }

        // @recomp draw no matter what
        if (1/*(var_fv0 > sViewPos.z) && (sViewPos.z > var_fv1)*/) {
            if (1/*fabsf(sViewPos.x) < (fabsf(sViewPos.z * 0.5f) + 500.0f)*/) {
                if (1/*fabsf(sViewPos.y) < (fabsf(sViewPos.z * 0.5f) + 500.0f)*/) {
                    Matrix_RotateY(gCalcMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                    Matrix_RotateX(gCalcMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
                    Matrix_RotateZ(gCalcMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);
                    this->info.draw(&this->obj);
                    sDrewActor = true;
                    if ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE) && (this->obj.id == OBJ_ACTOR_ALLRANGE) &&
                        (this->aiType == AI360_MISSILE)) {
                        gTeamArrowsViewPos[0] = sViewPos;
                    }
                }
            }
        }
    } else {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z, MTXF_APPLY);
        Matrix_MultVec3f(gGfxMatrix, &srcViewPos, &sViewPos);

        if ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) ||
            (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_STANDBY) ||
            ((this->obj.id == OBJ_ACTOR_ALLRANGE) && (this->aiType >= AI360_GREAT_FOX)) ||
            ((this->obj.id == OBJ_ACTOR_CUTSCENE) && (this->info.bonus != 0))) {
            var_ft5 = var_fv0 = 3000.0f;
            var_fv1 = -29000.0f;
            var_fa1 = 0.7f;
        } else {
            var_ft5 = 500.0f;
            var_fv0 = 0.0f;
            var_fv1 = -20000.0f;
            var_fa1 = 0.5f;
        }

        // @recomp draw no matter what
        if (1/*(var_fv0 > sViewPos.z) && (sViewPos.z > var_fv1)*/) {
            if (1/*fabsf(sViewPos.x) < (fabsf(sViewPos.z * var_fa1) + var_ft5)*/) {
                if (1/*fabsf(sViewPos.y) < (fabsf(sViewPos.z * var_fa1) + var_ft5)*/) {
                    if (this->info.draw != NULL) {
                        Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                        Matrix_RotateX(gGfxMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
                        Matrix_RotateZ(gGfxMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);
                        this->info.draw(&this->obj);
                        sDrewActor = true;
                        if ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE) &&
                            (((this->obj.id == OBJ_ACTOR_ALLRANGE) &&
                              ((this->aiType <= AI360_PEPPY) || (this->aiType == AI360_KATT) ||
                               (this->aiType == AI360_BILL))) ||
                             (this->obj.id == OBJ_ACTOR_TEAM_BOSS))) {
                            gTeamArrowsViewPos[this->aiType] = sViewPos;
                        }
                    }
                }
            }
        }
    }

    if (!sDrewActor) {
        this->lockOnTimers[gPlayerNum] = 0;
        if ((this->obj.id == OBJ_ACTOR_DEBRIS) || (this->obj.id == OBJ_ACTOR_AND_BRAIN_WASTE)) {
            Object_Kill(&this->obj, this->sfxSource);
        }
    }

    for (playerNum = 0; playerNum < gCamCount; playerNum++) {
        if (this->lockOnTimers[playerNum] != 0) {
            gLockOnTargetViewPos[playerNum] = sViewPos;
            gLockOnTargetViewPos[playerNum].y += this->info.targetOffset;
            if ((playerNum == gPlayerNum) && (gLockOnTargetViewPos[playerNum].z > -300.0f)) {
                this->lockOnTimers[playerNum] = 0;
            }
        }
    }

    Object_SetSfxSourceToView(this->sfxSource, &sViewPos);
    this->iwork[24] = sDrewActor;
}

RECOMP_PATCH void Boss_Draw(Boss* this, s32 arg1) {
    f32 var_fa1;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    f32 sp3C;
    Vec3f origin = { 0.0f, 0.0f, 0.0f };

    if (this->info.unk_19 != 0) {
        this->obj.pos.y += this->yOffset + gCameraShakeY;
        func_edisplay_8005D1F0(&this->obj, this->info.drawType);
        this->obj.pos.y -= this->yOffset + gCameraShakeY;
    } else {
        func_edisplay_8005D1F0(&this->obj, this->info.drawType);
    }

    Matrix_MultVec3f(&D_edisplay_801615F0, &origin, &D_edisplay_801615D0);
    Object_SetSfxSourceToView(this->sfxSource, &D_edisplay_801615D0);

    if ((this->obj.id == OBJ_BOSS_KA_SAUCERER) || (this->obj.id == OBJ_BOSS_KA_FLBASE)) {
        var_fa1 = 6000.0f;
        var_fv0 = 6000.0f;
        var_ft5 = 0.9f;
        var_fv1 = -20000.0f;
    } else if (this->obj.id == OBJ_BOSS_SZ_GREAT_FOX) {
        var_fv1 = -25000.0f;
        var_ft5 = 0.7f;
        var_fa1 = 3000.0f;
        var_fv0 = 2000.0f;
    } else {
        var_ft5 = 0.5f;
        var_fa1 = 2000.0f;
        var_fv0 = 1000.0f;
        var_fv1 = -15000.0f;
    }

    sp3C = -1.0f;
    // @recomp draw no matter what
    if (1/*(D_edisplay_801615D0.z < var_fv0) && (var_fv1 < D_edisplay_801615D0.z)*/) {
        if (1/*fabsf(D_edisplay_801615D0.x) < (fabsf(D_edisplay_801615D0.z * var_ft5) + var_fa1)*/) {
            if (1/*fabsf(D_edisplay_801615D0.y) < (fabsf(D_edisplay_801615D0.z * var_ft5) + var_fa1)*/) {
                sp3C = 1.0f;
                if (this->obj.id != OBJ_BOSS_BO_BASE) {
                    if (this->obj.id != OBJ_BOSS_KA_SAUCERER) {
                        Display_SetSecondLight(&this->obj.pos);
                    }
                    if (this->info.drawType != 2) {
                        Matrix_SetGfxMtx(&gMasterDisp);
                    }
                    if (arg1 < 0) {
                        Object_ApplyWaterDistortion();
                    }
                    this->info.draw(&this->obj);
                }
            }
        }
    }
    D_edisplay_801615D0.y = sp3C;

    if (this->obj.id == OBJ_BOSS_BO_BASE) {
        this->vwork[30] = D_edisplay_801615D0;
        Display_SetSecondLight(&this->obj.pos);
        Matrix_SetGfxMtx(&gMasterDisp);
        this->info.draw(&this->obj);
    }
}

RECOMP_PATCH void Scenery360_Draw(Scenery360* this) {
    Vec3f sp54 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp48;
    f32 sp44 = 1000.0f;
    f32 sp40 = -12000.0f;
    f32 sp3C = 2000.0f;
    f32 sp38 = 0.5f;

    if (this->obj.id == OBJ_SCENERY_UNK_156) {
        sp44 = 4000.0f;
        sp40 = -13000.0f;
        sp3C = 4500.0f;
    } else if (gCurrentLevel == LEVEL_VENOM_ANDROSS) {
        sp40 = -20000.0f;
        sp38 = 0.4f;
    } else if (this->obj.id == OBJ_SCENERY_VS_KA_FLBASE) {
        sp44 = 6000.0f;
        sp40 = -20000.0f;
        sp3C = 6000.0f;
        sp38 = 0.9f;
    }

    if ((gLevelType == LEVELTYPE_PLANET) || (gCurrentLevel == LEVEL_BOLSE)) {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y + gCameraShakeY, this->obj.pos.z, MTXF_APPLY);
    } else {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z, MTXF_APPLY);
    }

    Matrix_MultVec3f(gGfxMatrix, &sp54, &sp48);

    // @recomp draw no matter what
    if (1/*(sp48.z < sp44) && (sp40 < sp48.z)*/) {
        if (1/*fabsf(sp48.y) < (fabsf(sp48.z * sp38) + sp3C)*/) {
            if (1/*fabsf(sp48.x) < (fabsf(sp48.z * sp38) + sp3C)*/) {
                Display_SetSecondLight(&this->obj.pos);
                if (this->obj.id == OBJ_SCENERY_AND_PASSAGE) {
                    Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);
                    Matrix_RotateY(gGfxMatrix, M_PI / 2, MTXF_APPLY);
                    Matrix_Translate(gGfxMatrix, -551.0f, 0.0f, 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_VE2_6007650);
                } else {
                    Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, this->info.dList);
                }
            }
        }
    }
}

RECOMP_PATCH void Scenery_Draw(Scenery* this, s32 arg1) {
    this->obj.pos.y += gCameraShakeY;
    func_edisplay_8005D008(&this->obj, this->info.drawType);
    this->obj.pos.y -= gCameraShakeY;

    if (this->info.drawType == 0) {
        if ((this->obj.id == OBJ_SCENERY_CO_TOWER) || (this->obj.id == OBJ_SCENERY_CO_ROCKWALL) ||
            (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_4) || (this->obj.id == OBJ_SCENERY_VE1_WALL_3)) {
            RCP_SetupDL_57(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK); // @recomp Not sure if i should disable this

            if (arg1 < 0) {
                Object_ApplyWaterDistortion();
            }

            gSPDisplayList(gMasterDisp++, this->info.dList);
            RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
        } else {
            if (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_3) {
                if (arg1 < 0) {
                    return; // weird control flow
                }
                RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            }

            Object_SetCullDirection(arg1);

            if (arg1 < 0) {
                Object_ApplyWaterDistortion();
            }

            gSPDisplayList(gMasterDisp++, this->info.dList);

            if (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_3) {
                RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            }
        }
    } else if (this->info.draw != NULL) {
        Object_SetCullDirection(arg1);
        this->info.draw(&this->obj);
    }
}

// @recomp Not sure if i should disable this
RECOMP_PATCH void Object_SetCullDirection(s32 arg0) {
    if (arg0 < 0) {
        gSPSetGeometryMode(gMasterDisp++, G_CULL_FRONT);
        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
    }
}

RECOMP_PATCH void Scenery_Move(Scenery* this) {
    if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) {
        this->obj.pos.z += this->effectVel.z;
        if ((this->info.cullDistance * 1.5f)  < this->obj.pos.z) {
            Object_Kill(&this->obj, this->sfxSource);
        }
    } else if ((gLevelMode == LEVELMODE_ON_RAILS) && (gBossActive != 2)) {
        f32 temp_fv0 = fabsf(this->obj.pos.x - gPlayer[0].cam.eye.x);
        f32 var_fa0 = 500.0f;

        if ((this->obj.id == OBJ_SCENERY_CO_HIGHWAY_1) || (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_2)) {
            var_fa0 = 1000.0f;
        }
        temp_fv0 = ((temp_fv0 - var_fa0) < 0.0f) ? 0.0f : (temp_fv0 - var_fa0) * 1.7f;
        if ((fabsf(gPlayer[0].yRot_114) > 1.0f) || (gCurrentLevel == LEVEL_MACBETH)) {
            temp_fv0 = 0.0f;
        }
        temp_fv0 -= gPlayer[0].cam.eye.z;
        if (((this->info.cullDistance * 1.5f) - temp_fv0) < (this->obj.pos.z + gPathProgress)) {
            Object_Kill(&this->obj, this->sfxSource);
        }
    }
}

RECOMP_PATCH void Item_Draw(Item* this, s32 arg1) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };
    Vec3f dest;
    u8 drawn;

    Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + gPathProgress, MTXF_APPLY);
    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    drawn = false;

    // @recomp draw no matter what
    if (1/*(dest.z < 0.0f) && (dest.z > -12000.0f)*/) {
        if (1/*fabsf(dest.x) < (fabsf(dest.z * 0.5f) + 500.0f)*/) {
            if (1/*fabsf(dest.y) < (fabsf(dest.z * 0.5f) + 500.0f)*/) {
                if (this->info.draw != NULL) {
                    Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    if (this->info.drawType == 0) {
                        gSPDisplayList(gMasterDisp++, this->info.dList);
                    } else {
                        this->info.draw(&this->obj);
                    }
                }
                drawn = true;
            }
        }
    }

    Object_SetSfxSourceToView(this->sfxSource, &dest);

    if (!drawn && (gLevelMode == LEVELMODE_ALL_RANGE) && (gCamCount == 1) && (this->obj.id < OBJ_ITEM_GOLD_RING) &&
        (gCurrentLevel != LEVEL_VENOM_ANDROSS)) {
        Object_Kill(&this->obj, this->sfxSource);
    }
}

RECOMP_PATCH void Effect_DrawAllRange(Effect* this) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };
    Vec3f dest;
    f32 minZ;
    u8 drawn = false;

    if (this->info.unk_14 == -1) {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y + gCameraShakeY, this->obj.pos.z + gPathProgress,
                         MTXF_APPLY);
    } else {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + gPathProgress, MTXF_APPLY);
    }

    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    if ((gCurrentLevel == LEVEL_SECTOR_Z) || (gCurrentLevel == LEVEL_BOLSE)) {
        minZ = -20000.0f;
    } else {
        minZ = -10000.0f;
    }

    // @recomp draw no matter what
    if (1/*(dest.z < 0.0f) && (minZ < dest.z)*/) {
        if (1/*fabsf(dest.x) < (fabsf(dest.z * 0.5f) + 500.0f)*/) {
            if (1/*fabsf(dest.y) < (fabsf(dest.z * 0.5f) + 500.0f)*/) {
                if (this->info.draw != NULL) {
                    Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    this->info.draw(&this->obj);
                }
                drawn = true;
            }
        }
    }

    Object_SetSfxSourceToView(this->sfxSource, &dest);

    if (!drawn && (this->obj.id != OBJ_EFFECT_CLOUDS) && (this->obj.id != OBJ_EFFECT_TIMED_SFX) && (!gVersusMode)) {
        Object_Kill(&this->obj, this->sfxSource);
    }
}