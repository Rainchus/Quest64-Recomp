#include "patches.h"

u16 next_actor_transform = 0;

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
#if 1
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

RECOMP_PATCH void ActorTeamArwing_Draw(ActorTeamArwing* this) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };
    Vec3f dest;

    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    if (((/*(fabsf(dest.z) < 3000.0f) && (fabsf(dest.x) < 3000.0f) && */!gBossActive) ||
         (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_STANDBY) || (gCurrentLevel == LEVEL_VENOM_ANDROSS) ||
         (gCurrentLevel == LEVEL_VENOM_2) || (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE)) &&
        (gCurrentLevel != LEVEL_MACBETH) && (gCurrentLevel != LEVEL_TITANIA)) {
        if (this->obj.id == OBJ_ACTOR_CUTSCENE) {
            if (((gCurrentLevel == LEVEL_VENOM_2) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE) &&
                 (this->index == 10)) ||
                ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE) && (gPlayer[0].csState >= 100) &&
                 (gCurrentLevel == LEVEL_KATINA) && (this->index == 1)) ||
                ((gCurrentLevel == LEVEL_SECTOR_Y) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_STANDBY) &&
                 (this->state == 5))) {
                gActorTeamArwing.rightWingState = gPlayer[0].arwing.rightWingState;
                gActorTeamArwing.leftWingState = gPlayer[0].arwing.leftWingState;
            } else {
                gActorTeamArwing.rightWingState = gActorTeamArwing.leftWingState = WINGSTATE_INTACT;
            }
        } else {
            gActorTeamArwing.rightWingState = gActorTeamArwing.leftWingState = WINGSTATE_INTACT;
        }

        gActorTeamArwing.upperRightFlapYrot = this->fwork[15];
        gActorTeamArwing.upperLeftFlapYrot = this->fwork[16];
        gActorTeamArwing.bottomRightFlapYrot = this->fwork[26];
        gActorTeamArwing.bottomLeftFlapYrot = this->fwork[27];
        gActorTeamArwing.laserGunsYpos = gActorTeamArwing.laserGunsXpos = gActorTeamArwing.wingsXrot =
            gActorTeamArwing.wingsYrot = gActorTeamArwing.cockpitGlassXrot = gActorTeamArwing.wingsZrot = 0.0f;
        gActorTeamArwing.unk_28 = this->fwork[17];
        gActorTeamArwing.drawFace = this->iwork[14];
        gActorTeamArwing.teamFaceXrot = this->fwork[20];
        gActorTeamArwing.teamFaceYrot = this->fwork[19];

        if (gLevelType == LEVELTYPE_SPACE) {
            gActorTeamArwing.upperRightFlapYrot = gActorTeamArwing.bottomRightFlapYrot =
                gActorTeamArwing.upperLeftFlapYrot = gActorTeamArwing.bottomLeftFlapYrot = 0.0f;
        }
        Display_ArwingWings(&gActorTeamArwing);
    } else if (gLevelType == LEVELTYPE_PLANET) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        gSPDisplayList(gMasterDisp++, D_ENMY_PLANET_40018A0);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    } else if (gPlayer[0].wingPosition == 2) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        gSPDisplayList(gMasterDisp++, D_ENMY_SPACE_4003BD0);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    } else {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

        gSPDisplayList(gMasterDisp++, D_ENMY_SPACE_4007870);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
    Actor_DrawEngineAndContrails(this);
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
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
            gSPDisplayList(gMasterDisp++, aKaEnemyDL);
            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            break;

        case 1:
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
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
        Animation_DrawSkeletonArwing(1, D_arwing_3016610, gPlayer[0].jointTable, Display_ArwingWingsOverrideLimbDraw, NULL,
                               arwing, &gIdentityMatrix);
    } else {
        if (gGameState == GSTATE_MENU) {
            Animation_GetFrameData(&D_arwing_3015AF4, 0, frameTable);
        } else {
            Animation_GetFrameData(&D_arwing_3015C28, 0, frameTable);
        }
        Animation_DrawSkeletonArwing(1, D_arwing_3016610, frameTable, Display_ArwingWingsOverrideLimbDraw, NULL, arwing,
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
            gSPDisplayList(gMasterDisp++, D_ENMY_PLANET_40018A0);
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

RECOMP_PATCH void Memora_DrawParts(MeMora* this, f32 xTrans, f32 yTrans, f32 zTrans, f32 xRot, f32 yRot, f32 zRot,
                                   u8 partIdx, f32 scale, bool colorFlicker) {
    Vec3f src = { 0.0f, 0.0f, 0.0f };

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + partIdx, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);

    Matrix_Push(&gGfxMatrix);
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
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
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
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ACTOR(this) + 50, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

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
        Matrix_RotateY(gGfxMatrix, this->rot_0F4.y * M_DTOR, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, this->rot_0F4.x * M_DTOR, MTXF_APPLY);
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
    Matrix_RotateZ(gGfxMatrix, this->rot_0F4.z * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.1f, 0.9f, 1.0f, MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix, -this->rot_0F4.z * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.1f, 0.9f, 1.0f, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 3.0f, 3.0f, 1.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    gSPDisplayList(gMasterDisp++, aAndBrainWasteDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

#endif
