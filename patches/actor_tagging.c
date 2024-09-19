#include "patches.h"

u16 next_actor_transform = 0;

extern Limb* D_arwing_3016610[19];
extern Animation D_arwing_3015AF4;
extern Animation D_arwing_3015C28;
extern s32 D_display_800CA22C;
extern Gfx* sExpertFaceDL[4];
extern Gfx* sFaceDL[4];
extern Gfx D_arwing_30194E0[];
extern Gfx D_arwing_30183D0[];
extern Gfx aStarWolfUpgradedShipDL[];
extern Gfx aStarWolfStandardShipDL[];
extern Gfx aKattShipDL[];
extern Gfx aBillShipDL[];
extern Gfx aVenomFighter1DL[];
extern Gfx D_FO_6006BE0[];
extern Gfx aKaEnemyLowPolyDL[];
extern Gfx aSzInvaderIIIDL[];
extern Gfx aKaCornerianFighterDL[];
extern Gfx D_versus_3015740[];
extern Gfx D_BO_6008770[];
extern Gfx aKaEnemyDL[];
extern Animation aSzMissileAnim;
extern Animation D_VE2_600C200;
extern Limb* aSzMissileSkel[];
extern Limb* D_VE2_600C2AC[];

void ActorAllRange_DrawBarrelRoll(ActorAllRange* this);
void ActorAllRange_DrawShield(ActorAllRange* this);
bool Display_ArwingWingsOverrideLimbDraw(s32 limbIndex, Gfx** gfxPtr, Vec3f* pos, Vec3f* rot, void* wingData);
bool ActorAllRange_MissileOverrideLimbDraw(s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3f* rot, void* thisx);

u32 create_scenery360_transform_id(void) {
    u32 ret = next_actor_transform;
    next_actor_transform++;

    return ret;
}

/*
RECOMP_PATCH void Scenery360_Initialize(Scenery360* scenery360) {
    s32 i;
    u8* ptr = (u8*) scenery360;

    for (i = 0; i < sizeof(Scenery360); i++, ptr++) {
        *ptr = 0;
    }
    // @recomp Pick a transform ID for this actor and encode it into struct padding
    u32 cur_transform_id = create_scenery360_transform_id();
    scenery360IdByte0(scenery360) = (cur_transform_id >>  0) & 0xFF;
    scenery360IdByte0(scenery360) = (cur_transform_id >>  8) & 0xFF;
}
*/

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
                            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH,
                                                           G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
                            gSPDisplayList(gMasterDisp++, aKaEnemyLowPolyDL);
                            // @recomp Pop the transform id.
                            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                            break;
                        case 1:
                            // @recomp Tag the transform.
                            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH,
                                                           G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
                            gSPDisplayList(gMasterDisp++, aKaCornerianFighterDL);
                            // @recomp Pop the transform id.
                            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                            Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                            Actor_DrawEngineGlow(this, EG_RED);
                            break;
                        case 3:
                            // @recomp Tag the transform.
                            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH,
                                                           G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
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
                        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH,
                                                       G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
                        gSPDisplayList(gMasterDisp++, aStarWolfStandardShipDL);
                        // @recomp Pop the transform id.
                        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
                        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
                        Actor_DrawEngineGlow(this, EG_ORANGE);
                    } else {
                        // @recomp Tag the transform.
                        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH,
                                                       G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
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

#define KA_ACTOR_LOW_POLY (23)
#define KA_ACTOR_IWORK_8 (8)
#define EG_RED (0)

extern Gfx aKaEnemyDL[];
extern Gfx aKaCornerianFighterDL[];

// @recomp Tag & disable LOD on Katina enemies
RECOMP_PATCH void Katina_EnemyDraw(ActorAllRange* this) {
    s32 pad3[3];
    f32 angle;
    Vec3f D_i4_8019F4A8 = { 0.0f, 0.0f, 0.0f };
    Vec3f pad[30];

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
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);
            gSPDisplayList(gMasterDisp++, aKaEnemyDL);
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
    }
}

RECOMP_PATCH void Display_ArwingWings(ArwingInfo* arwing) {
    Vec3f frameTable[30];
    s32 drawFace;

    Matrix_Push(&gGfxMatrix);

    arwing->laserGunsXpos = 0.0f;
    if (arwing->laserGunsYpos < -7.0f) {
        arwing->laserGunsXpos = (-arwing->laserGunsYpos - 7.0f) * 2.5f;
    }

    if (gGameState == GSTATE_PLAY) {
        Animation_DrawSkeleton(1, D_arwing_3016610, gPlayer[0].jointTable, Display_ArwingWingsOverrideLimbDraw, NULL,
                               arwing, &gIdentityMatrix);
    } else {
        if (gGameState == GSTATE_MENU) {
            Animation_GetFrameData(&D_arwing_3015AF4, 0, frameTable);
        } else {
            Animation_GetFrameData(&D_arwing_3015C28, 0, frameTable);
        }
        Animation_DrawSkeleton(1, D_arwing_3016610, frameTable, Display_ArwingWingsOverrideLimbDraw, NULL, arwing,
                               &gIdentityMatrix);
    }

    D_display_800CA22C = false;

    drawFace = arwing->drawFace;
    if (D_display_800CA220 != 0) {
        drawFace = true;
    }

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_FACE + drawFace, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (drawFace != 0) {
        Matrix_Push(&gGfxMatrix);
        Matrix_Translate(gGfxMatrix, 0.0f, 6.4f, -16.5f, MTXF_APPLY);
        Matrix_RotateY(gGfxMatrix, arwing->teamFaceYrot * M_DTOR, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, arwing->teamFaceXrot * M_DTOR, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, 1.0f / 70.925f, 1.0f / 70.925f, 1.0f / 70.925f, MTXF_APPLY);

        if (gGameState == GSTATE_ENDING) {
            Matrix_Scale(gGfxMatrix, 0.95f, 0.95f, 0.95f, MTXF_APPLY);
        }

        Matrix_SetGfxMtx(&gMasterDisp);

        if (gExpertMode) {
            gSPDisplayList(gMasterDisp++, sExpertFaceDL[drawFace - 1]);
        } else {
            gSPDisplayList(gMasterDisp++, sFaceDL[drawFace - 1]);
        }
        Matrix_Pop(&gGfxMatrix);
    }

    Matrix_Translate(gGfxMatrix, 0.0f, 17.2f, -25.8f, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, arwing->cockpitGlassXrot * M_DTOR, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    RCP_SetupDL_64_2();

    if ((gGameState == GSTATE_PLAY) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO) &&
        (gCurrentLevel == LEVEL_CORNERIA)) {
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 120);
        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
        gSPDisplayList(gMasterDisp++, D_arwing_30194E0);
        RCP_SetupDL_46();
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 100);
        gSPDisplayList(gMasterDisp++, D_arwing_30183D0);
    } else {
        RCP_SetupDL_46();
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 140);
        gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
        gSPDisplayList(gMasterDisp++, D_arwing_30194E0);
    }

    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
    Matrix_Pop(&gGfxMatrix);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}
