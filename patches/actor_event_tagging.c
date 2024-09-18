#include "patches.h"

typedef struct {
    /* 0x00 */ Gfx* dList;
    /* 0x04 */ f32* hitbox;
    /* 0x08 */ f32 scale;
    /* 0x0C */ f32 cullDistance;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u8 info_unk_16;
    /* 0x15 */ u8 info_unk_14;
    /* 0x16 */ u8 sfx;
    /* 0x17 */ u8 info_unk_19;
    /* 0x18 */ f32 targetOffset;
    /* 0x1C */ u8 bonus;
} EventActorInfo; // size = 0x20

extern Gfx aActorSuppliesDL[];
extern Vec3f D_enmy_800CFEC4[6];
extern Vec3f D_enmy_800CFF0C[6];
extern EventActorInfo sEventActorInfo[108];
extern Gfx D_ENMY_PLANET_40018A0[];
extern Gfx D_ENMY_SPACE_4007870[];
extern Gfx aA6NinjinMissileDL[];
extern Gfx aA6RocketDL[];
extern Gfx aA6SpaceMineDL[];
extern Gfx aMeRockGull1DL[];
extern Gfx aMeRockGull2DL[];
extern Gfx aMeRockGull3DL[];
extern Gfx aMeFlipBot1DL[];
extern Gfx aMeFlipBot2DL[];
extern Gfx aVe1PillarDL[];
extern Gfx aMaLaserTurretDL[];
extern Gfx aWzSxEnemy1DL[];
extern Gfx aAqShellDL[];
extern Gfx aAqStarfishDL[];
extern Gfx aKattShipDL[];
extern Gfx aBillShipDL[];
extern Gfx aVe1BlockerDL[];
extern Gfx aSxLaserDL[];
extern Gfx aSxLaserDestroyedDL[];
extern Gfx aA6UmbraStationDL[];
extern Animation aSoGoreAnim;
extern Animation aKillerBeeAnim;
extern Animation aTripodAnim;
extern Animation aAqOysterAnim;
extern Animation aZoSarumarinePeriscopeAnim;
extern Animation aCruiserGunAnim;
extern Animation aTiBomberAnim;
extern Animation aFirebirdAnim;
extern Limb* aKillerBeeSkel[7];
extern Limb* aAqOysterSkel[];
extern Limb* aZoSarumarinePeriscopeSkel[];
extern Limb* aTiBomberSkel[];
extern Limb* aCruiserGunSkel[];
extern Limb* aFirebirdSkel[];
extern Limb* aTripodSkel[];
extern Limb* aSoGoreSkel[];
extern u16 D_VE1_9003890[];
extern u16 D_VE1_9003DF0[];
extern u16 D_VE1_9003330[];

void ActorEvent_SxWarpGate_Draw(ActorEvent* this);
void SectorY_SyRobot_Draw(Actor*);
void Andross_Gate_Draw(Actor*);
void Zoness_ZoBird_Draw(ZoBird* this);
bool ActorEvent_OverrideLimbDraw1(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);

RECOMP_PATCH void ActorEvent_Draw(ActorEvent* this) {
    s32 pad2[3];
    Vec3f frameTable[30];
    f32 sp40;
    s16 savedState;
    s32 pad;

    if (this->timer_0C6 && (this->eventType != EVID_MA_RAILROAD_CART) && (this->eventType != EVID_SY_LASER_TURRET) &&
        (this->eventType != EVID_SY_SHIP_WINDOWS)) {
        if ((this->eventType != EVID_ME_METEOR_1) && (this->eventType != EVID_ME_METEOR_2) &&
            (this->eventType != EVID_ME_METEOR_4) && (this->eventType != EVID_ME_METEOR_5) &&
            (this->eventType != EVID_AQ_OYSTER) && (this->eventType != EVID_MA_BOULDER) && (this->scale > 0.5f) &&
            (this->timer_0C6 >= 9) && ((this->timer_0C6 & 3) == 0) && (gPlayState != PLAY_PAUSE)) {
            Effect_Effect390_Spawn(this->obj.pos.x, this->obj.pos.y, this->obj.pos.z, this->vel.x, this->vel.y,
                                   this->vel.z, this->scale * 0.07f, 3);
        }

        if ((this->eventType != EVID_A6_NINJIN_MISSILE) && (this->eventType != EVID_VENOM_FIGHTER_3) &&
            (this->eventType != EVID_ZO_BIRD) && (this->eventType != EVID_AQ_OYSTER) &&
            (this->eventType != EVID_SX_LASER) && (this->eventType != EVID_SY_ROBOT_4) &&
            (this->eventType != EVID_ME_METEOR_1) && (this->eventType != EVID_SY_SHIP_WINDOWS) &&
            (this->eventType != EVID_SX_WATCH_POST) && (this->scale > 0.5f)) {
            sp40 = SIN_DEG(this->timer_0C6 * 400.0f) * this->timer_0C6;
            Matrix_RotateY(gGfxMatrix, M_DTOR * sp40, MTXF_APPLY);
            Matrix_RotateX(gGfxMatrix, M_DTOR * sp40, MTXF_APPLY);
            Matrix_RotateZ(gGfxMatrix, M_DTOR * sp40, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
        }
    }

    if ((this->obj.status == OBJ_DYING) && (this->timer_0BE != 0)) {
        RCP_SetupDL_27();
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
    }

    if ((this->eventType == EVID_SX_SPACE_MINE) || (this->eventType == EVID_SY_ROBOT_SPRITE_SIDE) ||
        (this->eventType == EVID_SY_ROBOT_SPRITE_FRONT)) {
        RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    } else if ((this->eventType == EVID_MA_LASER_TURRET) || (this->eventType == EVID_MA_RAILROAD_CART) ||
               ((this->eventType == EVID_FIREBIRD) && (gCurrentLevel == LEVEL_SOLAR))) {
        if ((this->timer_0C6 % 2) == 0) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_57);
        } else {
            RCP_SetupDL(&gMasterDisp, SETUPDL_61);
        }
    }

    switch (this->eventType) {
        case EVID_WZ_PILLAR_1:
        case EVID_WZ_PILLAR_2:
        case EVID_WZ_METEOR_1:
        case EVID_WZ_METEOR_2:
        case EVID_WZ_GATE:
            RCP_SetupDL(&gMasterDisp, SETUPDL_34);
            gDPSetTextureFilter(gMasterDisp++, G_TF_POINT);
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, (s32) this->fwork[15], (s32) this->fwork[16],
                            (s32) this->fwork[17], 255);
            gSPDisplayList(gMasterDisp++, sEventActorInfo[this->eventType].dList);
            gDPSetTextureFilter(gMasterDisp++, G_TF_BILERP);
            break;

        default:
            if ((this->eventType < EVID_200) && (sEventActorInfo[this->eventType].dList != NULL)) {
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT_COMMON + this->index, G_EX_PUSH,
                                               G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                gSPDisplayList(gMasterDisp++, sEventActorInfo[this->eventType].dList);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }

            switch (this->eventType) {
                case EVID_TI_GREAT_FOX:
                    Cutscene_DrawGreatFox();
                    break;

                case EVID_VENOM_FIGHTER_1:
                    this->iwork[11] = 1;
                    Actor_DrawEngineAndContrails(this);
                    break;

                case EVID_ME_SLIPPY:
                    this->fwork[15] -= this->fwork[15] * 0.1f;
                    this->fwork[26] -= this->fwork[26] * 0.1f;
                    this->fwork[16] -= this->fwork[16] * 0.1f;
                    this->fwork[27] -= this->fwork[27] * 0.1f;

                    if (this->obj.rot.z > 0.0f) {
                        this->fwork[15] += (this->obj.rot.z * 0.7f - this->fwork[15]) * 0.2f;
                        this->fwork[26] += (-this->obj.rot.z * 0.7f - this->fwork[26]) * 0.2f;
                    }

                    if (this->obj.rot.z < 0.0f) {
                        this->fwork[16] += (-this->obj.rot.z * 0.7f - this->fwork[16]) * 0.2f;
                        this->fwork[27] += (this->obj.rot.z * 0.7f - this->fwork[27]) * 0.2f;
                    }
                    ActorTeamArwing_Draw(this);
                    break;

                case EVID_TEAMMATE:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    if (gLevelType == LEVELTYPE_PLANET) {
                        gSPDisplayList(gMasterDisp++, D_ENMY_PLANET_40018A0);
                    } else {
                        gSPDisplayList(gMasterDisp++, D_ENMY_SPACE_4007870);
                    }

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                    Actor_DrawEngineAndContrails(this);
                    break;

                case EVID_GRANGA_FIGHTER_2:
                    this->iwork[11] = 1;
                    Actor_DrawEngineAndContrails(this);
                    break;

                case EVID_FIREBIRD:
                    if (gCurrentLevel == LEVEL_SOLAR) {
                        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                        Animation_GetFrameData(&aSoGoreAnim, this->animFrame, frameTable);
                        Animation_DrawSkeleton(1, aSoGoreSkel, frameTable, NULL, NULL, this, &gIdentityMatrix);
                        gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                    } else {
                        Animation_GetFrameData(&aFirebirdAnim, this->animFrame, frameTable);
                        Animation_DrawSkeleton(1, aFirebirdSkel, frameTable, NULL, NULL, this, &gIdentityMatrix);
                    }
                    break;

                case EVID_CORNERIAN_FIGHTER:
                    this->iwork[11] = 1;
                    Actor_DrawEngineAndContrails(this);
                    break;

                case EVID_TRIPOD:
                    Matrix_Translate(gGfxMatrix, 0.0f, -30.0f, 0.0f, MTXF_APPLY);
                    Animation_GetFrameData(&aTripodAnim, this->animFrame, frameTable);
                    Animation_DrawSkeleton(1, aTripodSkel, frameTable, NULL, NULL, this, &gIdentityMatrix);
                    break;

                case EVID_SX_SPY_EYE:
                    if (this->fwork[0] > 0.1f) {
                        this->iwork[11] = 1;
                        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -30.0f, MTXF_APPLY);
                        Matrix_Scale(gGfxMatrix, 2.5f, 2.5f, 2.5f, MTXF_APPLY);
                        Actor_DrawEngineGlow(this, EG_GREEN);
                    }
                    break;

                case EVID_SX_CANINE:
                    if (this->fwork[0] > 0.1f) {
                        this->iwork[11] = 1;
                        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -30.0f, MTXF_APPLY);
                        Matrix_Scale(gGfxMatrix, 2.5f, 2.5f, 2.5f, MTXF_APPLY);
                        Actor_DrawEngineGlow(this, EG_GREEN);
                    }
                    break;

                case EVID_SPACE_MINE:
                    RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aA6SpaceMineDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_A6_NINJIN_MISSILE:
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aA6NinjinMissileDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -30.0f, MTXF_APPLY);
                    this->iwork[11] = 1;
                    Actor_DrawEngineGlow(this, EG_GREEN);
                    break;

                case EVID_A6_ROCKET:
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aA6RocketDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -30.0f, MTXF_APPLY);
                    this->iwork[11] = 1;
                    Actor_DrawEngineGlow(this, EG_GREEN);
                    break;

                case EVID_SX_LASER:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    if (this->timer_0C2 != 0) {
                        if (((this->timer_0C2 & 3) == 0) && (gPlayState != PLAY_PAUSE)) {
                            func_effect_8007D0E0(RAND_FLOAT_CENTERED(200.0f) + this->obj.pos.x,
                                                 RAND_FLOAT_CENTERED(200.0f) + this->obj.pos.y,
                                                 RAND_FLOAT_CENTERED(200.0f) + this->obj.pos.z,
                                                 RAND_FLOAT(1.5f) + 2.5f);
                        }
                        RCP_SetupDL(&gMasterDisp, SETUPDL_57);
                        gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                        gSPDisplayList(gMasterDisp++, aSxLaserDestroyedDL);
                    } else {
                        gSPDisplayList(gMasterDisp++, aSxLaserDL);
                    }

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_A6_UMBRA_STATION:
                    Matrix_RotateX(gGfxMatrix, M_PI / 2, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aA6UmbraStationDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_CRUISER_GUN:
                    Animation_GetFrameData(&aCruiserGunAnim, this->animFrame, frameTable);
                    Matrix_RotateY(gGfxMatrix, M_PI, MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, 1.5f, 1.5f, 1.5f, MTXF_APPLY);
                    Animation_DrawSkeleton(1, aCruiserGunSkel, frameTable, ActorEvent_OverrideLimbDraw1, NULL, this,
                                           &gIdentityMatrix);
                    Math_SmoothStepToF(&this->fwork[16], 0.0f, 0.3f, 2.0f, 0.0001f);
                    break;

                case EVID_TI_BOMBER:
                    Animation_GetFrameData(&aTiBomberAnim, this->animFrame, frameTable);
                    frameTable[2].z += this->fwork[15];
                    Animation_DrawSkeleton(1, aTiBomberSkel, frameTable, NULL, NULL, this, &gIdentityMatrix);
                    break;

                case EVID_SX_WARP_GATE:
                    ActorEvent_SxWarpGate_Draw(this);
                    break;

                case EVID_SY_ROBOT_1:
                case EVID_SY_ROBOT_2:
                case EVID_SY_ROBOT_3:
                    SectorY_SyRobot_Draw(this);
                    break;

                case EVID_SARUMARINE_PERISCOPE:
                    Animation_GetFrameData(&aZoSarumarinePeriscopeAnim, this->animFrame, frameTable);
                    frameTable[2].z -= this->fwork[15];
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
                    Matrix_Scale(gGfxMatrix, 2.6f, 2.6f, 2.6f, MTXF_APPLY);
                    Animation_DrawSkeleton(1, aZoSarumarinePeriscopeSkel, frameTable, NULL, NULL, this,
                                           &gIdentityMatrix);
                    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                    break;

                case EVID_ME_ROCK_GULL:
                    Matrix_Push(&gGfxMatrix);
                    Matrix_RotateX(gGfxMatrix, this->rot_0F4.x * M_DTOR, MTXF_APPLY);
                    Matrix_RotateY(gGfxMatrix, this->rot_0F4.y * M_DTOR, MTXF_APPLY);
                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, 0.0f, this->fwork[15], 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aMeRockGull1DL);
                    Matrix_Pop(&gGfxMatrix);
                    gSPDisplayList(gMasterDisp++, aMeRockGull2DL);
                    Matrix_Translate(gGfxMatrix, 0.0f, -this->fwork[15], 0.0f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, aMeRockGull3DL);
                    Matrix_Pop(&gGfxMatrix);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_ME_FLIP_BOT:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aMeFlipBot1DL);
                    RCP_SetupDL(&gMasterDisp, SETUPDL_53);
                    gSPDisplayList(gMasterDisp++, aMeFlipBot2DL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_SUPPLY_CRATE:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    ActorSupplies_Draw(this);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_ZO_BIRD:
                    savedState = this->state;
                    this->state = 2;
                    Zoness_ZoBird_Draw(this);
                    this->state = savedState;
                    break;

                case EVID_VE1_PILLAR:
                    Matrix_Scale(gGfxMatrix, 0.6f, 0.6f, 0.6f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aVe1PillarDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_VE1_BLOCKER:
                    if (this->fwork[15] > 0.001f) {
                        Matrix_Scale(gGfxMatrix, this->fwork[15], this->fwork[15], this->fwork[15], MTXF_APPLY);
                        Matrix_SetGfxMtx(&gMasterDisp);

                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                       G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                        Texture_BlendRGBA16(this->fwork[16], 16 * 11, D_VE1_9003890, D_VE1_9003DF0, D_VE1_9003330);
                        gSPDisplayList(gMasterDisp++, aVe1BlockerDL);

                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    }
                    break;

                case EVID_MA_LASER_TURRET:
                    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aMaLaserTurretDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
                    break;

                case EVID_AQ_OYSTER:
                    Matrix_Scale(gGfxMatrix, 3.0f, 3.0f, 3.0f, MTXF_APPLY);
                    Animation_GetFrameData(&aAqOysterAnim, this->animFrame, frameTable);
                    Animation_DrawSkeleton(1, aAqOysterSkel, frameTable, NULL, NULL, this, &gIdentityMatrix);
                    break;

                case EVID_BILL:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aBillShipDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                    Actor_DrawEngineAndContrails(this);
                    break;

                case EVID_KATT:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aKattShipDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                    Actor_DrawEngineAndContrails(this);
                    break;

                case EVID_AQ_STARFISH:
                    RCP_SetupDL(&gMasterDisp, SETUPDL_22);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, this->work_046, this->work_046, this->work_046, 255);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aAqStarfishDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_AQ_SHELL:
                    RCP_SetupDL(&gMasterDisp, SETUPDL_21);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aAqShellDL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_ANDROSS_GATE:
                case EVID_ANDROSS_GATE_2:
                    Andross_Gate_Draw(this); // Skeleton
                    break;

                case EVID_SX_WARP_ENMY:
                    RCP_SetupDL(&gMasterDisp, SETUPDL_35);
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 0, 0, 0, 143);
                    gDPSetEnvColor(gMasterDisp++, 0, 0, 0, 0);

                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR_EVENT + this->index, G_EX_PUSH,
                                                   G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

                    gSPDisplayList(gMasterDisp++, aWzSxEnemy1DL);

                    // @recomp Pop the transform id.
                    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                    break;

                case EVID_KILLER_BEE:
                    Animation_GetFrameData(&aKillerBeeAnim, this->animFrame, frameTable);
                    Animation_DrawSkeleton(1, aKillerBeeSkel, frameTable, NULL, NULL, this, &gIdentityMatrix);
                    break;

                case EVID_FFF:
                    this->timer_0C2 = 10;
                    break;
            }

            if ((gReflectY > 0) && ((this->iwork[12] >= TEAM_ID_FALCO) && (this->iwork[12] < TEAM_ID_MAX))) {
                Vec3f src = { 0.0f, 0.0f, 0.0f };

                if ((this->iwork[12] == TEAM_ID_KATT) || (this->iwork[12] == TEAM_ID_BILL)) {
                    Matrix_MultVec3f(gGfxMatrix, &src, &gTeamArrowsViewPos[this->iwork[12] + 4]);
                } else {
                    Matrix_MultVec3f(gGfxMatrix, &src, &gTeamArrowsViewPos[this->iwork[12]]);
                }
            }
            break;
    }
}