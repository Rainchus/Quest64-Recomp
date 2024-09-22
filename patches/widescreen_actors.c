#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "patches.h"

#if 1 // full scope

extern Vec3f sViewPos;
extern bool sDrewActor;
extern Vec3f gLockOnTargetViewPos[];
extern Matrix D_edisplay_801615F0;
extern Vec3f D_edisplay_801615D0;
extern Gfx D_VE2_6007650[];

void func_edisplay_8005D1F0(Object* obj, s32 drawType);
void Object_SetCullDirection(s32 arg0);
void func_edisplay_8005D008(Object* obj, s32 drawType);

#if 1
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
        goto render;

        if ((var_fv0 > sViewPos.z) && (sViewPos.z > var_fv1)) {
            if (fabsf(sViewPos.x) < (fabsf(sViewPos.z * 0.5f) + 500.0f)) {
                if (fabsf(sViewPos.y) < (fabsf(sViewPos.z * 0.5f) + 500.0f)) {
                render:
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
        goto render2;

        if ((var_fv0 > sViewPos.z) && (sViewPos.z > var_fv1)) {
            if (fabsf(sViewPos.x) < (fabsf(sViewPos.z * var_fa1) + var_ft5)) {
                if (fabsf(sViewPos.y) < (fabsf(sViewPos.z * var_fa1) + var_ft5)) {
                render2:
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
#endif

/**
 * Problems:
 * Causing KaSaucerer not to spawn in Katina. Provisional patch: Except katina in the patch
 */
#if 1
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
    if (gCurrentLevel != LEVEL_KATINA) { // Excepting Katina because of KaSaucerer's bug
        goto render;
    }

    if ((D_edisplay_801615D0.z < var_fv0) && (var_fv1 < D_edisplay_801615D0.z)) {
        if (fabsf(D_edisplay_801615D0.x) < (fabsf(D_edisplay_801615D0.z * var_ft5) + var_fa1)) {
            if (fabsf(D_edisplay_801615D0.y) < (fabsf(D_edisplay_801615D0.z * var_ft5) + var_fa1)) {
            render:
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
#endif

/**
 * Problems:
 * Causing crash in Sector Y Boss, omitting that level for now.
 */
#if 1
RECOMP_PATCH void Scenery360_Draw(Scenery360* this) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };
    Vec3f dest;

    f32 behindZdist = 1000.0f;
    f32 frontZdist = -12000.0f;
    f32 xyOffsetBounds = 2000.0f + 1000.0f;
    f32 xyObjDistBoundMod = 0.5f;

    if (this->obj.id == OBJ_SCENERY_SY_SHOGUN_SHIP) {
        behindZdist = 4000.0f;
        frontZdist = -13000.0f;
        xyOffsetBounds = 4500.0f;
    } else if (gCurrentLevel == LEVEL_VENOM_ANDROSS) {
        frontZdist = -20000.0f;
        xyObjDistBoundMod = 0.4f;
    } else if (this->obj.id == OBJ_SCENERY_VS_KA_FLBASE) {
        behindZdist = 6000.0f;
        frontZdist = -20000.0f;
        xyOffsetBounds = 6000.0f;
        xyObjDistBoundMod = 0.9f;
    }

    if ((gLevelType == LEVELTYPE_PLANET) || (gCurrentLevel == LEVEL_BOLSE)) {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y + gCameraShakeY, this->obj.pos.z, MTXF_APPLY);
    } else {
        Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z, MTXF_APPLY);
    }

    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    if (gCurrentLevel == LEVEL_SECTOR_Z) {
        behindZdist = 6000.0f;
        frontZdist = -20000.0f * 2;
        xyOffsetBounds = 6000.0f * 2;
        xyObjDistBoundMod = 0.9f;
        goto check;
    }

    if ((gCurrentLevel != LEVEL_SECTOR_Y) && (gCurrentLevel != LEVEL_VENOM_ANDROSS)) {
        goto render;
    }

check:
    if ((dest.z < behindZdist) && (frontZdist < dest.z)) {
        if (fabsf(dest.y) < (fabsf(dest.z * xyObjDistBoundMod) + xyOffsetBounds)) {
            if (fabsf(dest.x) < (fabsf(dest.z * xyObjDistBoundMod) + xyOffsetBounds)) {
            render:
                Display_SetSecondLight(&this->obj.pos);

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_SCENERY_360(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);

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

                    // u32 cur_transform_id = scenery360_transform_id(this);
                    gSPDisplayList(gMasterDisp++, this->info.dList);
                }

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
        }
    }
}

/*
void SectorY_8019AEC0(SyShogun*);
void SectorY_80198244(SyShogun*);
extern f32 D_SY_60342A0[];
extern f32 D_SY_6034304[];
extern Gfx aSySaruzinDL[];

RECOMP_PATCH void SectorY_SyShogun_Init(SyShogun* this) {
    gScenery360[0].info.dList = NULL; // @recomp initialize dList to NULL to avoid crash
    this->fwork[9] = 0.0f;
    this->swork[33] = 5500;
    this->timer_050 = 10;
    this->timer_058 = 0;

    D_ctx_80177A10[8] = 0;

    if (this->index == 0) {
        this->info.hitbox = SEGMENTED_TO_VIRTUAL(D_SY_60342A0);
        this->health = 150;

        this->swork[28] = 5;
        this->fwork[43] = 3.5f;
        this->fwork[45] = 40.0f;

        if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_START_360) {
            this->obj.pos.z = -28900.0f;
            gScenery360[0].obj.pos.z = -30000.0f;
        }

        this->rot_078.y = 0.0f;
        SectorY_8019AEC0(this);
    } else {
        this->fwork[34] = 2.8f;
        this->info.hitbox = SEGMENTED_TO_VIRTUAL(D_SY_6034304);
        this->health = 100;
        this->swork[28] = 0;
        this->swork[25] = 1;
        this->fwork[45] = 35.0f;

        if (this->index == 1) {
            this->rot_078.y = 15.0f;
        } else {
            this->rot_078.y = 345.0f;
        }

        this->vel.x = SIN_DEG(this->rot_078.y) * this->fwork[45] * 0.2f;
        this->vel.z = COS_DEG(this->rot_078.y) * this->fwork[45] * 0.2f;
        SectorY_80198244(this);
        this->timer_056 = 250;
    }

    if (gLevelMode == LEVELMODE_ON_RAILS) {
        if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE) {
            gPlayer[0].state_1C8 = PLAYERSTATE_1C8_START_360;
            gPlayer[0].csState = 0;
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 50);
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 50);
        }
        Object_Kill(&this->obj, this->sfxSource);
    }
}
*/
#endif

/**
 * Problems:
 * Game crash before the Titania's Boss with 50% more cullingdistance
 */
#if 1
RECOMP_PATCH void Scenery_Move(Scenery* this) {
    if (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) {
        this->obj.pos.z += this->effectVel.z;
        if ((this->info.cullDistance * 1.5f) < this->obj.pos.z) {
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

        // @recomp increase cullDistance by 50%.
        f32 recompCulldistance = 1.5f;

        if (gCurrentLevel == LEVEL_TITANIA) {
            recompCulldistance = 1.0f;
        }

        if (((this->info.cullDistance * recompCulldistance) - temp_fv0) < (this->obj.pos.z + gPathProgress)) {
            Object_Kill(&this->obj, this->sfxSource);
        }
    }
}
#endif

#if 1
RECOMP_PATCH void Item_Draw(Item* this, s32 arg1) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };
    Vec3f dest;
    u8 drawn;

    Matrix_Translate(gGfxMatrix, this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + gPathProgress, MTXF_APPLY);
    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    drawn = false;

    // @recomp draw no matter what
    goto render;

    if ((dest.z < 0.0f) && (dest.z > -12000.0f)) {
        if (fabsf(dest.x) < (fabsf(dest.z * 0.5f) + 500.0f)) {
            if (fabsf(dest.y) < (fabsf(dest.z * 0.5f) + 500.0f)) {
            render:
                if (this->info.draw != NULL) {
                    Matrix_RotateY(gGfxMatrix, this->obj.rot.y * M_DTOR, MTXF_APPLY);
                    Matrix_RotateX(gGfxMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
                    Matrix_RotateZ(gGfxMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    if (this->info.drawType == 0) {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                       G_EX_EDIT_ALLOW);
                        gSPDisplayList(gMasterDisp++, this->info.dList);
                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
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
#endif

// Causes problem with Effects still being drawn when they shouldn't (Granga's plasma beam)
#if 0
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
    goto render;

    if ((dest.z < 0.0f) && (minZ < dest.z)) {
        if (fabsf(dest.x) < (fabsf(dest.z * 0.5f) + 500.0f)) {
            if (fabsf(dest.y) < (fabsf(dest.z * 0.5f) + 500.0f)) {
            render:
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
#endif

#endif // full scope
