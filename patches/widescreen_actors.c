#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "patches.h"

#if 1 // full scope

#define TEAM_HEAD_XROT (19)
#define TEAM_HEAD_YROT (20)

extern Vec3f sViewPos;
extern bool sDrewActor;
extern Vec3f gLockOnTargetViewPos[];
extern Matrix D_edisplay_801615F0;
extern Vec3f D_edisplay_801615D0;
extern Gfx D_VE2_6007650[];

void func_edisplay_8005D1F0(Object* obj, s32 drawType);
void Object_SetCullDirection(s32 arg0);
void func_edisplay_8005D008(Object* obj, s32 drawType);
void Corneria_SpawnClouds(void);
void Corneria_CsTeamSetup(ActorCutscene* this, s32 teamIdx);

// for draw distance tests
#if 0
extern int gXoffsetBounds;
extern int gYoffsetBounds;
extern int gBackZdist;
extern int gFrontZdist;
#endif

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
    if ((gCurrentLevel != LEVEL_KATINA) &&
        (gCurrentLevel != LEVEL_SECTOR_Y)) { // Excepting Katina because of KaSaucerer's bug
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

#if 1
// @recomp: Fix Falco's positioning to account for widescreen.
RECOMP_PATCH void Corneria_LevelStart(Player* player) {
    s32 i;
    ActorCutscene* falco = &gActors[0];
    ActorCutscene* slippy = &gActors[1];
    ActorCutscene* peppy = &gActors[2];
    f32 sp44;
    f32 sp40;
    f32 x;
    f32 y;
    f32 z;
    f32 sp30;
    f32 sp2C;

    // Corneria_SpawnTerrainBumps(); // This function call was probably around here.

    PRINTF("Enms[1].obj.mode %d\n", gActors[1].obj.status);

    if (gCsFrameCount < 815) {
        x = player->pos.x;
        y = player->pos.y + 15.0f;
        z = player->trueZpos - 20.0f;
    } else {
        if (gCsFrameCount < 1009) {
            x = falco->obj.pos.x;
            y = falco->obj.pos.y + 15.0f;
            z = falco->obj.pos.z - 20.0f;
        } else if (gCsFrameCount < 1198) {
            x = peppy->obj.pos.x;
            y = peppy->obj.pos.y + 15.0f;
            z = peppy->obj.pos.z - 20.0f;
        } else {
            x = slippy->obj.pos.x;
            y = slippy->obj.pos.y + 15.0f;
            z = slippy->obj.pos.z - 20.0f;
        }
    }

    sp2C = -Math_Atan2F(player->cam.eye.x - x, player->cam.eye.z - z);
    sp30 = -Math_Atan2F(player->cam.eye.y - y, sqrtf(SQ(player->cam.eye.z - z) + SQ(player->cam.eye.x - x)));

    sp44 = Math_RadToDeg(sp2C) - D_ctx_80177A48[4];
    sp40 = Math_RadToDeg(sp30) - D_ctx_80177A48[5];

    if (sp44 > 180.0f) {
        sp44 -= 360.0f;
    }
    if (sp44 < -180.0f) {
        sp44 += 360.0f;
    }
    if (sp40 > 180.0f) {
        sp40 -= 360.0f;
    }
    if (sp40 < -180.0f) {
        sp40 += 360.0f;
    }

    D_ctx_80177A48[6] += fabsf(sp44);
    D_ctx_80177A48[7] += fabsf(sp40);

    // Cloud reflexions on Arwing windshields
    if (sp2C >= 0.0f) {
        Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 2);
        Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 2);
    } else {
        Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 3);
        Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 3);
    }

    for (i = 0; (i < 40) && (D_ctx_80177A48[6] >= 0.2f); i++, D_ctx_80177A48[6] -= 0.2f) {
        if (sp44 >= 0) {
            Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 2);
        } else {
            Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 3);
        }
    }

    for (i = 0; (i < 40) && (D_ctx_80177A48[7] >= 0.3f); i++, D_ctx_80177A48[7] -= 0.3f) {
        if (sp40 >= 0) {
            Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 0);
        } else {
            Lib_Texture_Scroll(aWindshieldClouldReflextionTex, 64, 32, 1);
        }
    }

    D_ctx_80177A48[4] = Math_RadToDeg(sp2C);
    D_ctx_80177A48[5] = Math_RadToDeg(sp30);

    player->flags_228 = 0;

    D_ctx_80177950 = -1.0f;
    if ((Math_RadToDeg(gPlayer[0].camYaw) < 90.0f) || (Math_RadToDeg(gPlayer[0].camYaw) > 270.0f)) {
        D_ctx_80177950 = 1.0f;
    }

    player->vel.z = 0.0f;
    player->pos.z = player->pos.z;
    player->trueZpos = player->pos.z + player->camDist;
    player->bobPhase += 10.0f;
    player->yBob = -SIN_DEG(player->bobPhase) * 0.5f;
    player->rockPhase += 3.0f;
    player->rockAngle = SIN_DEG(player->rockPhase) * 1.5f;

    Corneria_SpawnClouds();

    player->arwing.teamFaceXrot = 0;

    switch (player->csState) {
        case 0: // LevelStart initialization
            gCsFrameCount = 0;
            player->csState = 1;
            player->csTimer = 600;
            player->pos.y = 6000.0f;
            player->pos.x = 0.1f;

            Corneria_CsTeamSetup(falco, 0);
            Corneria_CsTeamSetup(slippy, 1);
            Corneria_CsTeamSetup(peppy, 2);

            falco->iwork[14] = 2;
            slippy->iwork[14] = 3;
            peppy->iwork[14] = 4;

            player->cam.eye.x = gCsCamEyeX = player->pos.x - 400.0f;
            gPlayer[0].cam.eye.y = gCsCamEyeY = player->pos.y + 600.0f;
            player->cam.eye.z = gCsCamEyeZ = player->trueZpos + 2000.0f;

            player->cam.at.x = gCsCamAtX = player->pos.x;
            player->cam.at.y = gCsCamAtY = player->pos.y;
            player->cam.at.z = gCsCamAtZ = player->trueZpos + 300.0f;

            D_ctx_80177A48[0] = 0;
            D_ctx_80177A48[1] = D_ctx_80177A48[2] = 0;

            gFillScreenAlphaTarget = 255;
            gFillScreenAlpha = 255;
            gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 255;
            break;

        case 1: // cs phase: camera focus on fox (open the wings!)
            if (player->csTimer < 550) {
                gFillScreenAlphaTarget = 0;
                gFillScreenAlphaStep = 3;
                Math_SmoothStepToF(&D_ctx_80177A48[0], 0.01f, 1.0f, 0.0005f, 0.0f);
            }

            gCsCamEyeX = player->pos.x - 150.0f;
            gCsCamEyeY = player->pos.y - 70.0f;
            gCsCamEyeZ = player->trueZpos + 150.0f;

            gCsCamAtX = player->pos.x;
            gCsCamAtY = player->pos.y;
            gCsCamAtZ = player->trueZpos;

            if (player->csTimer == 0) {
                player->csState = 2;
                player->csTimer = 130;
                D_ctx_80177A48[0] = 0.0f;
            }

            if (player->csTimer == 315) {
                player->pos.x = 0.0f;
            }

            if (player->csTimer == 270) {
                gHideRadio = false;
                Radio_PlayMessage(gMsg_ID_2005, RCID_FOX);
            }

            if (player->csTimer == 180) {
                AUDIO_PLAY_SFX(NA_SE_WING_OPEN, player->sfxSource, 0);
            }

            if (player->csTimer == 120) {
                AUDIO_PLAY_SFX(NA_SE_WING_OPEN_END, player->sfxSource, 0);
            }

            if ((player->csTimer < 190) && (player->csTimer > 150)) {
                Math_SmoothStepToF(&player->arwing.wingsZrot, 2.0f, 0.2f, 0.5f, 0.0f);
            }

            if (player->csTimer < 150) {
                player->wingPosition = 0;
            }

            if ((player->csTimer < 120) && ((player->csTimer % 16) == 0)) {
                D_ctx_80177A48[1] = RAND_FLOAT_CENTERED(60.0f);
                D_ctx_80177A48[2] = RAND_FLOAT_CENTERED(60.0f);
            }

            if (player->csTimer == 0) {
                D_ctx_80177A48[1] = 0.0f;
                D_ctx_80177A48[2] = D_ctx_80177A48[1];
            }
            break;

        case 2: // camera goes to the side of Fox.
            Math_SmoothStepToF(&D_ctx_80177A48[0], 0.1f, 1.0f, 0.001f, 0.0f);

            gCsCamEyeX = player->pos.x - 50.0f;
            gCsCamEyeY = player->pos.y + 10.0f;
            gCsCamEyeZ = player->trueZpos - 10.0f;

            gCsCamAtX = player->pos.x;
            gCsCamAtY = player->pos.y + 10.0f;
            gCsCamAtZ = player->trueZpos + 10.0f;

            if (player->csTimer == 20) {
                Radio_PlayMessage(gMsg_ID_2010, RCID_FOX);
            }

            if (player->csTimer == 0) {
                player->csState = 3;
                player->csTimer = 180;
                player->unk_004 = 0.0f;
                falco->state = 0;
                peppy->state = 0;
                slippy->state = 0;
                falco->obj.pos.y = player->pos.y + 80.0f;
                // @recomp: adjust Falco's position so he appears from further right
                falco->obj.pos.z += 3.0f * 100.0f;
            }

            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                player->arwing.teamFaceXrot = 5.0f;
            }
            break;

        case 3: // Falco appears on scene from behind
            
            // @recomp: adjust Falco's maxStep so he flies faster in compensation for the previous change
            if (fabsf(Math_SmoothStepToF(&falco->obj.pos.z, player->pos.z + 100.0f, 0.05f, 3.0f * 5.0f, 0.0f)) < 1.0f) {
                player->csState = 4;
                D_ctx_80177A48[0] = 0.0f;
                player->csTimer = 190;
            }

            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                player->arwing.teamFaceXrot = 5.0f;
            }

            gCsCamEyeY = player->pos.y + 10.0f;
            gCsCamAtY = player->pos.y + 10.0f;
            break;

        case 4:
            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                player->arwing.teamFaceXrot = 5.0f;
            }

            Math_SmoothStepToF(&D_ctx_80177A48[0], 0.1f, 1.0f, 0.001f, 0.0f);

            // Focus camera on Falco.
            gCsCamEyeX = falco->obj.pos.x - 50.0f;
            gCsCamEyeY = falco->obj.pos.y + 10.0f;
            gCsCamEyeZ = falco->obj.pos.z - 10.0f;

            gCsCamAtX = falco->obj.pos.x;
            gCsCamAtY = falco->obj.pos.y + 10.0f;
            gCsCamAtZ = falco->obj.pos.z + 10.0f;

            if (player->csTimer == 0) {
                player->csState = 5;
                player->csTimer = 5;
            }

            if (player->csTimer == 80) {
                Radio_PlayMessage(gMsg_ID_2020, RCID_FALCO);
            }

            // Falco looks towards the camera.
            if (player->csTimer < 100) {
                Math_SmoothStepToF(&falco->fwork[TEAM_HEAD_XROT], 50.0f, 0.1f, 3.0f, 0.01f);
            }

            // Falco's head rocks back and forth as he speaks.
            falco->fwork[TEAM_HEAD_YROT] = 0.0f;
            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                falco->fwork[TEAM_HEAD_YROT] = 5.0f;
            }
            break;

        case 5:
            // Falco's head rotates back.
            Math_SmoothStepToF(&falco->fwork[TEAM_HEAD_XROT], 0.0f, 0.1f, 3.0f, 0.01f);

            if (player->csTimer == 0) {
                player->csState = 6;
                D_ctx_80177A48[0] = 0.0f;
                player->csTimer = 190;
            }

            // Camera moves towards Peppy.
            gCsCamEyeY = falco->obj.pos.y + 10.0f;
            gCsCamAtY = falco->obj.pos.y + 10.0f;
            break;

        case 6:
            // Falco's head rotates back.
            Math_SmoothStepToF(&falco->fwork[TEAM_HEAD_XROT], 0.0f, 0.1f, 3.0f, 0.01f);
            Math_SmoothStepToF(&D_ctx_80177A48[0], 0.1f, 1.0f, 0.001f, 0.0f);

            D_ctx_80177A48[3] -= 0.5f;

            // Focus camera on Peppy
            gCsCamEyeX = peppy->obj.pos.x + 100.0f + D_ctx_80177A48[3];
            gCsCamEyeY = peppy->obj.pos.y + 10.0f;
            gCsCamEyeZ = peppy->obj.pos.z - 70.0f;

            gCsCamAtX = peppy->obj.pos.x + 20.0f + (D_ctx_80177A48[3] * 0.5f);
            gCsCamAtY = peppy->obj.pos.y + 10.0f;
            gCsCamAtZ = peppy->obj.pos.z + 10.0f;

            if (player->csTimer == 0) {
                player->csState = 7;
                player->csTimer = 190;
                D_ctx_80177A48[0] = 0.0f;
                falco->obj.pos.y = player->pos.y;
                falco->obj.pos.z = player->trueZpos + 240.0f;
            }

            if (player->csTimer == 80) {
                Radio_PlayMessage(gMsg_ID_2030, RCID_PEPPY);
            }

            // Peppy's head rocks back and forth as he speaks.
            peppy->fwork[TEAM_HEAD_YROT] = 0.0f;
            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                peppy->fwork[TEAM_HEAD_YROT] = 5.0f;
            }
            break;

        case 7:
            Math_SmoothStepToF(&D_ctx_80177A48[0], 0.1f, 1.0f, 0.001f, 0.0f);

            // Focus camera on Slippy.
            gCsCamEyeX = slippy->obj.pos.x + 20.0f;
            gCsCamEyeY = slippy->obj.pos.y + 10.0f;
            gCsCamEyeZ = slippy->obj.pos.z - 50.0f;

            gCsCamAtX = slippy->obj.pos.x + 10.0f;
            gCsCamAtY = slippy->obj.pos.y + 10.0f;
            gCsCamAtZ = slippy->obj.pos.z + 10.0f;

            if (player->csTimer == 0) {
                player->csState = 8;
                D_ctx_80177A48[0] = 0.0f;
                player->csTimer = 300;
                D_ctx_80177A48[8] = 50.0f;
                D_ctx_80177A48[3] = 0.0f;
            }

            if (player->csTimer == 80) {
                Radio_PlayMessage(gMsg_ID_2040, RCID_SLIPPY);
                player->pos.x = 0.1f;
            }

            if (player->csTimer < 100) {
                Math_SmoothStepToF(&slippy->fwork[TEAM_HEAD_XROT], -20.0f, 0.1f, 3.0f, 0.01f);
            }

            // Slippy's head rocks back and forth as he speaks.
            slippy->fwork[TEAM_HEAD_YROT] = 0.0f;
            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                slippy->fwork[TEAM_HEAD_YROT] = 5.0f;
            }
            break;

        case 8:
            Math_SmoothStepToF(&D_ctx_80177A48[0], 0.1f, 1.0f, 0.001f, 0.0f);

            if (player->csTimer < 150) {
                D_ctx_80177A48[3] += player->unk_004;
                Math_SmoothStepToF(&player->unk_004, 2.0f, 1.0f, 0.2f, 0.0f);
            }

            // Focus camera on Fox.
            gCsCamEyeX = player->pos.x;
            gCsCamEyeZ = (player->trueZpos - 600.0f) + D_ctx_80177A48[3];
            gCsCamEyeY = player->pos.y + D_ctx_80177A48[8];

            gCsCamAtX = player->pos.x;
            gCsCamAtY = player->pos.y + 20.0f;
            gCsCamAtZ = player->trueZpos + 100.0f;

            if (player->csTimer < 100) {
                Math_SmoothStepToF(&D_ctx_80177A48[8], 10.0f, 0.1f, 0.7f, 0.0f);
            }

            if (player->csTimer == 200) {
                Radio_PlayMessage(gMsg_ID_2050, RCID_FOX);
            }

            // Fox's head rotates back and forth as he speaks.
            player->arwing.teamFaceXrot = 0.0f;
            if (gMsgCharIsPrinting && ((gGameFrameCount & 2) != 0)) {
                player->arwing.teamFaceXrot = 5.0f;
            }

            if (player->csTimer == 80) {
                falco->fwork[29] = 5.0f;
            }

            if (player->csTimer == 60) {
                slippy->fwork[29] = 5.0f;
            }

            if (player->csTimer == 40) {
                peppy->fwork[29] = 5.0f;
            }

            if ((player->csTimer > 70) && (player->csTimer < 80)) {
                falco->iwork[11] = 2;
            }

            if ((player->csTimer > 50) && (player->csTimer < 60)) {
                slippy->iwork[11] = 2;
            }

            if ((player->csTimer > 30) && (player->csTimer < 40)) {
                peppy->iwork[11] = 2;
            }

            if (player->csTimer == 70) {
                falco->state = 1;
                Play_PlaySfxFirstPlayer(player->sfxSource, NA_SE_ARWING_BOOST);
            }

            if (player->csTimer == 50) {
                slippy->state = 2;
                Play_PlaySfxFirstPlayer(player->sfxSource, NA_SE_ARWING_BOOST);
            }

            if (player->csTimer == 30) {
                peppy->state = 3;
                Play_PlaySfxFirstPlayer(player->sfxSource, NA_SE_ARWING_BOOST);
            }

            if (player->csTimer == 0) {
                player->csState = 9;
                Play_PlaySfxFirstPlayer(player->sfxSource, NA_SE_ARWING_BOOST);
                player->csTimer = 3;
                player->unk_194 = 5.0f;
                player->unk_190 = 5.0f;
            }
            break;

        case 9:
            gCsCamEyeX = player->pos.x;
            gCsCamEyeY = player->pos.y;
            gCsCamEyeZ = player->trueZpos + 1000.0f;

            gCsCamAtX = player->pos.x;
            gCsCamAtY = player->pos.y;
            gCsCamAtZ = player->trueZpos + 1100.0f;

            D_ctx_80177A48[0] = 0.03f;

            player->unk_190 = 2.0f;

            if (player->csTimer == 0) {
                gFillScreenAlphaTarget = 255;
                gFillScreenAlphaStep = 48;
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 255;
            }

            if (gFillScreenAlpha == 255) {
                AUDIO_PLAY_BGM(gBgmSeqId);

                Object_Kill(&falco->obj, falco->sfxSource);
                Object_Kill(&slippy->obj, slippy->sfxSource);
                Object_Kill(&peppy->obj, peppy->sfxSource);

                gLevelStartStatusScreenTimer = 80;

                player->pos.y = 350.0f;
                player->cam.eye.x = player->pos.x;
                player->cam.eye.y = (player->pos.y * player->unk_148) + 50.0f;
                player->cam.eye.z = 30.0f;
                player->state_1C8 = PLAYERSTATE_1C8_ACTIVE;
                player->csState = 0;
                player->cam.at.x = player->pos.x;
                player->cam.at.y = (player->pos.y * player->unk_148) + 20.0f;
                player->cam.at.z = player->trueZpos;

                D_ctx_80177950 = 1.0f;

                gPlayerGlareAlphas[0] = gPlayerGlareAlphas[1] = gPlayerGlareAlphas[2] = gPlayerGlareAlphas[3] = 0;
                gLoadLevelObjects = 1;
                gFillScreenAlphaTarget = 0;
                player->csTimer = 15;
            }
            break;

        case 10:
            break;
    }

    Math_SmoothStepToF(&player->cam.eye.x, gCsCamEyeX, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.eye.y, player->yBob + gCsCamEyeY, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, D_ctx_80177A48[0], 20000.0f, 0.0f);

    Math_SmoothStepToF(&player->cam.at.x, gCsCamAtX, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.y, gCsCamAtY - player->yBob, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.z, gCsCamAtZ, D_ctx_80177A48[0], 20000.0f, 0.0f);

    Math_SmoothStepToF(&player->arwing.upperRightFlapYrot, D_ctx_80177A48[1], 0.2f, 1.0f, 0.0f);
    Math_SmoothStepToF(&player->arwing.upperLeftFlapYrot, D_ctx_80177A48[2], 0.2f, 1.0f, 0.0f);

    player->arwing.bottomRightFlapYrot = player->arwing.upperRightFlapYrot;
    player->arwing.bottomLeftFlapYrot = player->arwing.upperLeftFlapYrot;

    player->cam.eye.y -= 3.0f;
    player->cam.at.y -= 3.0f;
    player->pos.y -= 3.0f;

    falco->vwork[20].y -= 3.0f;
    falco->obj.pos.y -= 3.0f;
    peppy->vwork[20].y -= 3.0f;
    peppy->obj.pos.y -= 3.0f;
    slippy->vwork[20].y -= 3.0f;
    slippy->obj.pos.y -= 3.0f;
}
#endif

#endif // full scope
