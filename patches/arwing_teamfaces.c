#include "patches.h"

// @recomp: Improvement: set team arwing faces for level complete CS.

typedef enum ActorCSTeamFace {
    /* 0 */ FACE_NONE,
    /* 1 */ FACE_FOX,
    /* 2 */ FACE_FALCO,
    /* 3 */ FACE_SLIPPY,
    /* 4 */ FACE_PEPPY
} ActorCSTeamFace;

// PROBLEM: character face rotation is wrong outside of cutscenes
#if 0
RECOMP_PATCH void ActorAllRange_SpawnTeam(void) {
    ActorAllRange* actor;
    s32 i;
    s32 maxActors = 4;

    for (i = 0, actor = &gActors[0]; i < maxActors; i++, actor++) {
        if ((i > 0) && (gTeamShields[i] <= 0)) {
            continue;
        }

        Actor_Initialize(actor);
        actor->obj.status = OBJ_ACTIVE;
        actor->obj.id = OBJ_ACTOR_ALLRANGE;
        Object_SetInfo(&actor->info, actor->obj.id);

        if (i == 0) {
            actor->aiType = AI360_EVENT_HANDLER;
        } else {
            actor->obj.pos.x = sTeamSpawnPos[i].x;
            actor->obj.pos.y = sTeamSpawnPos[i].y;
            actor->obj.pos.z = sTeamSpawnPos[i].z;
            actor->aiType = sTeamAi[i];

            if (gCurrentLevel == LEVEL_KATINA) {
                actor->aiIndex = sTeamSpawnTargetsKA[i];
            } else {
                actor->aiIndex = sTeamSpawnTargets[i];
            }

            actor->state = 2;
            actor->rot_0F4.y = 180.0f;

            if (actor->aiIndex <= -1) {
                actor->state = 3;
            }

            actor->health = 50;

            if ((gLevelType == LEVELTYPE_PLANET) || (gCurrentLevel == LEVEL_BOLSE)) {
                actor->drawShadow = true;
            }

            actor->iwork[11] = 1;

            if (actor->aiType <= AI360_PEPPY) {
                AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, actor->sfxSource, 4);
                actor->info.hitbox = SEGMENTED_TO_VIRTUAL(gTeamHitbox);
                actor->info.targetOffset = 0.0f;
                actor->info.bonus = 0;

                // @recomp set team faces
                actor->iwork[14] = i + 1;
            } else {
                AUDIO_PLAY_SFX(NA_SE_EN_ENGINE_01, actor->sfxSource, 4);
            }
        }
    }
}
#endif

RECOMP_PATCH void SectorZ_CsLevelCompleteTeamInit(ActorCutscene* this, s32 index) {
    f32 direction;

    direction = 1.0f;
    if (!gGreatFoxIntact) {
        direction = -1.0f;
    }

    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = sCsTeamXpos[index] * direction;
    this->obj.pos.y = sCsTeamYpos[index];
    this->obj.pos.z = sCsTeamZpos[index];

    this->fwork[0] = gPlayer[0].baseSpeed;
    this->rot_0F4.y = gPlayer[0].rot.y;

    Object_SetInfo(&this->info, this->obj.id);

    if (index < 3) {
        this->iwork[11] = 1;
        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);

        // @recomp set team faces
        this->iwork[14] = index + 2;
    } else {
        this->animFrame = ACTOR_CS_GREAT_FOX;
        this->fwork[0] = 20.0f;
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_ENGINE, this->sfxSource, 0);
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_BURNER, this->sfxSource, 0);
    }
}

// For Granga
RECOMP_PATCH void Corneria_CsLevelComplete1_TeamSetup(ActorCutscene* this, s32 index) {
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    Player* player = &gPlayer[0];

    Matrix_RotateY(gCalcMatrix, player->rot.y * M_DTOR, MTXF_NEW);
    sp5C.x = D_i1_80199AE4[index];
    sp5C.y = D_i1_80199AF0[index];
    sp5C.z = D_i1_80199AFC[index];

    sp44.x = D_i1_80199B08[index];
    sp44.y = D_i1_80199B14[index];
    sp44.z = D_i1_80199B20[index];

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp5C, &sp50);
    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp44, &sp38);

    Actor_Initialize(this);

    this->obj.pos.x = player->pos.x + sp50.x;
    this->obj.pos.y = player->pos.y + sp50.y;
    this->obj.pos.z = player->pos.z + sp50.z;

    this->fwork[0] = sp38.x;
    this->fwork[1] = sp38.y;
    this->fwork[2] = sp38.z;

    this->fwork[7] = RAND_FLOAT(360.0f);
    this->fwork[8] = RAND_FLOAT(360.0f);

    this->vel.x = player->vel.x;
    this->vel.y = player->vel.y;
    this->vel.z = player->vel.z;

    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;
    this->obj.rot.z = D_i1_80199B2C[index];

    Object_SetInfo(&this->info, this->obj.id);

    this->iwork[11] = 1;

    // @recomp set team faces
    this->iwork[14] = index + 2;
    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

// @recomp: For carrier Level complete, this is team setup
RECOMP_PATCH void func_demo_8004A700(ActorCutscene* this, s32 index) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = gPlayer[0].pos.x;
    this->obj.pos.y = gPlayer[0].pos.y - 1000.0f;
    this->obj.pos.z = gPlayer[0].pos.z;

    this->fwork[0] = D_demo_800CA050[index];
    this->fwork[1] = D_demo_800CA05C[index];
    this->fwork[2] = D_demo_800CA068[index];

    this->fwork[3] = 4.0f;
    this->fwork[7] = RAND_FLOAT(100.0f);
    this->fwork[8] = RAND_FLOAT(100.0f);
    this->obj.rot.z = D_demo_800CA074[index];
    this->iwork[11] = 1;
    Object_SetInfo(&this->info, this->obj.id);

    // @recomp set team faces
    this->iwork[14] = index + 2;
    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

// @recomp: for Sector Y, this is level complete team and other actor cutscene setup
RECOMP_PATCH void SectorY_8019EB80(void) {
    ActorCutscene* actor = &gActors[0];
    s32 i;
    s32 actorCount;

    if (gHitCount >= 100) {
        actorCount = 9; // Teammates + Cornerian ships
    } else {
        actorCount = 2; // Teammates only
    }

    Rand_SetSeed(1, 29100, 9786);

    for (i = 0; i <= actorCount; i++, actor++) {
        if (((i == 0) && (gTeamShields[TEAM_ID_PEPPY] <= 0.0f)) ||
            ((i == 1) && (gTeamShields[TEAM_ID_SLIPPY] <= 0.0f)) ||
            ((i == 2) && (gTeamShields[TEAM_ID_FALCO] <= 0.0f))) {
            continue;
        }
        Actor_Initialize(actor);
        actor->obj.status = OBJ_INIT;
        actor->obj.id = OBJ_ACTOR_CUTSCENE;

        actor->obj.pos.x = (D_i6_801A69FC[i].x * 0.5f) + gPlayer[0].pos.x + RAND_FLOAT_CENTERED_SEEDED(2000.0f);
        actor->obj.pos.y = D_i6_801A69FC[i].y + gPlayer[0].pos.y + RAND_FLOAT_SEEDED(1000.0f);
        actor->obj.pos.z = D_i6_801A69FC[i].z + gPlayer[0].pos.z + RAND_FLOAT_SEEDED(1000.0f);

        actor->rot_0F4.z = RAND_FLOAT_CENTERED_SEEDED(200.0f);

        actor->vwork[0].x = (D_i6_801A69FC[i].x * 0.5f) + gPlayer[0].pos.x;
        actor->vwork[0].y = D_i6_801A69FC[i].y + gPlayer[0].pos.y;
        actor->vwork[0].z = D_i6_801A69FC[i].z + gPlayer[0].pos.z;

        actor->state = 1;
        Object_SetInfo(&actor->info, actor->obj.id);

        if (i >= 3) {
            actor->animFrame = ACTOR_CS_SY_SHIP_1_SHRINK;
            actor->rot_0F4.z = 0.0f;
        }
        if (i >= 7) {
            actor->animFrame = ACTOR_CS_SY_SHIP_2;
            actor->scale = 0.125f;
        }
        actor->iwork[11] = 1;

        // @recomp: Setup team faces
        if ((i >= 0) && (i <= 2)) {
            actor->iwork[14] = i + 2;
        }

        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, actor->sfxSource, 4);
    }
}

RECOMP_PATCH void Meteo_LevelComplete_SetupTeam(ActorCutscene* this, s32 teamIdx) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = sMeLevelCompleteTeamSetupPos[teamIdx].x + gPlayer[0].pos.x;
    this->obj.pos.y = sMeLevelCompleteTeamSetupPos[teamIdx].y + gPlayer[0].pos.y;
    this->obj.pos.z = sMeLevelCompleteTeamSetupPos[teamIdx].z + gPlayer[0].trueZpos;

    this->rot_0F4.y = 0.0f;
    this->rot_0F4.z = sMeLevelCompleteTeamSetupModel[teamIdx];

    Object_SetInfo(&this->info, this->obj.id);

    if (teamIdx == 3) {
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_ENGINE, this->sfxSource, 0);
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_BURNER, this->sfxSource, 0);
        this->animFrame = ACTOR_CS_GREAT_FOX;
    } else {
        this->iwork[11] = 1;
        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);

        // @recomp: Setup team faces
        this->iwork[14] = teamIdx + 2;
    }
}

RECOMP_PATCH void Meteo_LevelStart_SetupTeam(ActorCutscene* this, s32 teamIdx) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = sMeLevelStartTeamSetupXpos[teamIdx] + gPlayer[0].pos.x;
    this->obj.pos.y = sMeLevelStartTeamSetupYpos[teamIdx] + gPlayer[0].pos.y;
    this->obj.pos.z = sMeLevelStartTeamSetupZpos[teamIdx] + gPlayer[0].trueZpos;

    this->animFrame = sMeLevelStartTeamSetupModel[teamIdx];
    this->obj.rot.y = 180.0f;
    Object_SetInfo(&this->info, this->obj.id);
    this->info.cullDistance = 200.0f;

    if (this->animFrame == 0) {
        this->iwork[11] = 1;
        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);

        // @recomp: Setup team faces
        this->iwork[14] = teamIdx + 2;
        return;
    }

    AUDIO_PLAY_SFX(NA_SE_GREATFOX_ENGINE, this->sfxSource, 0);
    AUDIO_PLAY_SFX(NA_SE_GREATFOX_BURNER, this->sfxSource, 0);
}

RECOMP_PATCH void Katina_SFTeam_LevelComplete_Update(void) {
    s32 i;
    s32 numActors;
    ActorCutscene* actor = &gActors[0];

    Rand_SetSeed(1, 29100, 9786);

    if (gMissionStatus != MISSION_COMPLETE) {
        numActors = 20 - 1;
    } else {
        numActors = 3 - 1;
    }

    for (i = 0; i <= numActors; i++, actor++) {
        if ((D_i4_8019F2F0[i] >= gKaAllyKillCount) && ((i >= 3) || (gTeamShields[i + 1] > 0))) {
            Actor_Initialize(actor);
            actor->obj.status = OBJ_INIT;
            actor->obj.id = OBJ_ACTOR_CUTSCENE;

            actor->obj.pos.x =
                (sCsLevelCompleteActorPos[i].x * 0.5f) + gPlayer[0].pos.x + RAND_FLOAT_CENTERED_SEEDED(2000.0f);
            actor->obj.pos.y = (sCsLevelCompleteActorPos[i].y + gPlayer[0].pos.y) - RAND_FLOAT_SEEDED(1000.0f);
            actor->obj.pos.z = (sCsLevelCompleteActorPos[i].z + gPlayer[0].pos.z) + RAND_FLOAT_SEEDED(1000.0f);

            actor->rot_0F4.z = RAND_FLOAT_CENTERED_SEEDED(200.0f);

            actor->vwork[0].x = (sCsLevelCompleteActorPos[i].x * 0.5f) + gPlayer[0].pos.x;
            actor->vwork[0].y = sCsLevelCompleteActorPos[i].y + gPlayer[0].pos.y;
            actor->vwork[0].z = sCsLevelCompleteActorPos[i].z + gPlayer[0].pos.z;

            actor->state = 1;

            if (i >= 3) {
                actor->animFrame = ACTOR_CS_CORNERIAN_FIGHTER;
            }

            // @recomp: Setup team faces
            if ((i >= 0) && (i <= 2)) {
                actor->iwork[14] = i + 2;
            }

            Object_SetInfo(&actor->info, actor->obj.id);

            actor->iwork[11] = 1;

            AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, actor->sfxSource, 4);
        }
    }
}

RECOMP_PATCH void Katina_SFTeamFleeUpdate(ActorCutscene* this, s32 idx) {
    Actor_Initialize(this);

    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = D_i4_8019F29C[idx + 1];
    this->obj.pos.y = D_i4_8019F2AC[idx + 1];
    this->obj.pos.z = D_i4_8019F2BC[idx + 1];

    this->rot_0F4.y = D_i4_8019F2CC[idx + 1];

    this->fwork[1] = D_i4_8019F2DC[idx + 1];
    this->fwork[0] = 40.0f;

    Object_SetInfo(&this->info, this->obj.id);

    this->iwork[11] = 1;

    // @recomp: Setup team faces
    this->iwork[14] = idx + 1;

    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

RECOMP_PATCH void Katina_SFTeamMissionAccomUpdate(ActorCutscene* this, s32 idx) {
    Actor_Initialize(this);

    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = D_i4_8019F260[idx + 1] + gPlayer[0].pos.x;
    this->obj.pos.y = D_i4_8019F26C[idx + 1] + gPlayer[0].pos.y;
    this->obj.pos.z = D_i4_8019F278[idx + 1] + gPlayer[0].pos.z;

    this->rot_0F4.y = D_i4_8019F284[idx + 1];

    this->fwork[1] = D_i4_8019F290[idx + 1];
    this->fwork[0] = 40.0f;

    Object_SetInfo(&this->info, this->obj.id);

    this->iwork[11] = 1;

    // @recomp: Setup team faces
    this->iwork[14] = idx + 1;

    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

RECOMP_PATCH void Fortuna_LevelComplete_CsSpawnTeam(ActorCutscene* this, s32 actorIdx) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = sLevelCompleteCsActorInitPosX[actorIdx] + gPlayer[0].pos.x;
    this->obj.pos.y = sLevelCompleteCsActorInitPosY[actorIdx] + gPlayer[0].pos.y;
    this->obj.pos.z = sLevelCompleteCsActorInitPosZ[actorIdx] + gPlayer[0].trueZpos;

    this->vel.z = gPlayer[0].baseSpeed;

    Object_SetInfo(&this->info, this->obj.id);

    if (actorIdx < 3) {
        this->iwork[11] = 1;
        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);

        // @recomp: Setup team faces
        this->iwork[14] = actorIdx + 2;
    } else {
        this->obj.pos.z = -9500.0f;
        this->animFrame = ACTOR_CS_GREAT_FOX;
        this->vel.z = 22.0f;
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_ENGINE, this->sfxSource, 0);
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_BURNER, this->sfxSource, 0);
    }
}

RECOMP_PATCH void Bolse_8018EAEC(ActorCutscene* this, s32 index) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;
    this->obj.pos.x = D_i4_8019EFDC[index] + gPlayer[0].pos.x;
    this->obj.pos.y = D_i4_8019EFE8[index] + gPlayer[0].pos.y;
    this->obj.pos.z = D_i4_8019EFF4[index] + gPlayer[0].pos.z;
    this->animFrame = D_i4_8019F000[index];
    this->obj.rot.y = 180.0f;
    this->vel.z = -gPlayer[0].baseSpeed;
    this->rot_0F4.z = D_i4_8019F00C[index];
    this->rot_0F4.y = D_i4_8019F018[index];
    Object_SetInfo(&this->info, this->obj.id);
    this->iwork[11] = 1;

    // @recomp: Setup team faces
    this->iwork[14] = index + 2;

    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

RECOMP_PATCH void Bolse_8018F83C(Actor* this, s32 index) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;
    this->obj.pos.x = D_i4_8019F06C[index] + gPlayer[0].pos.x;
    this->obj.pos.y = D_i4_8019F078[index] + gPlayer[0].pos.y;
    this->obj.pos.z = D_i4_8019F084[index] + gPlayer[0].pos.z;
    this->obj.rot.y = 180.0f;
    this->obj.rot.z = D_i4_8019F090[index];
    this->vel.z = -gPlayer[0].baseSpeed;
    Object_SetInfo(&this->info, this->obj.id);
    this->iwork[11] = 1;

    // @recomp: Setup team faces
    this->iwork[14] = index + 2;

    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

// Also valid for Zoness
RECOMP_PATCH void Solar_801A7750(void) {
    ActorCutscene* actor = &gActors[0];
    s32 i;

    Rand_SetSeed(1, 29100, 9786);

    for (i = 0; i < 3; i++, actor++) {
        if ((i == 0) && (gTeamShields[TEAM_ID_PEPPY] <= 0.0f)) {
            continue;
        }
        if ((i == 1) && (gTeamShields[TEAM_ID_SLIPPY] <= 0.0f)) {
            continue;
        }
        if ((i == 2) && (gTeamShields[TEAM_ID_FALCO] <= 0.0f)) {
            continue;
        }

        Actor_Initialize(actor);
        actor->obj.status = OBJ_INIT;
        actor->obj.id = OBJ_ACTOR_CUTSCENE;

        actor->obj.pos.x = D_i3_801BFB30[i].x / 2.0f + gPlayer[0].pos.x;
        actor->obj.pos.y = D_i3_801BFB30[i].y + gPlayer[0].pos.y;
        actor->obj.pos.z = D_i3_801BFB30[i].z + gPlayer[0].pos.z;
        actor->state = 1;
        Object_SetInfo(&actor->info, actor->obj.id);
        actor->iwork[11] = 1;

        // @recomp: Setup team faces
        actor->iwork[14] = i + 2;

        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, actor->sfxSource, 4);
    }
}

// Area6 level start team setup
RECOMP_PATCH void Area6_8018D804(ActorCutscene* this, s32 teamIdx) {
    Vec3f sp2C[3] = {
        { -200.0f, 0.0f, -500.0f },
        { 200.0f, 30.0f, -600.0f },
        { 50.0f, -90.0f, -700.0f },
    };
    Player* player = &gPlayer[0];

    Actor_Initialize(this);
    this->obj.status = OBJ_ACTIVE;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = sp2C[teamIdx].x + player->pos.x;
    this->obj.pos.y = sp2C[teamIdx].y + player->pos.y;
    this->obj.pos.z = sp2C[teamIdx].z + player->pos.z;

    this->state = 5;
    this->iwork[11] = 1;
    this->fwork[0] = 0.0f;
    Object_SetInfo(&this->info, this->obj.id);

    // @recomp: Setup team faces
    this->iwork[14] = teamIdx + 2;

    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
}

// Area6 level complete team setup
RECOMP_PATCH void Area6_8018EC38(ActorCutscene* this, s32 teamIdx) {
    Vec3f sp2C[3] = {
        { -150.0f, 40.0f, 75.0f },
        { 150.0f, 40.0f, 150.0f },
        { 38.0f, 88.0f, 225.0f },
    };
    Player* player = &gPlayer[0];

    if (gTeamShields[teamIdx + 1] > 0) {
        Actor_Initialize(this);
        this->obj.status = OBJ_ACTIVE;
        this->obj.id = OBJ_ACTOR_CUTSCENE;

        this->obj.pos.x = sp2C[teamIdx].x + player->pos.x;
        this->obj.pos.y = sp2C[teamIdx].y + player->pos.y;
        this->obj.pos.z = sp2C[teamIdx].z + player->pos.z;

        this->state = 100;

        this->iwork[11] = 1;
        this->fwork[0] = 0.0f;

        // @recomp: Setup team faces (original code was omitting Peppy)
        // if (teamIdx + 1 != 3) {
        this->iwork[14] = teamIdx + 2;
        // }

        Object_SetInfo(&this->info, this->obj.id);

        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
    }
}

RECOMP_PATCH void SectorZ_CsTeamInit(ActorCutscene* this, s32 index) {
    ActorCutscene* greatFox = &gActors[0];

    Actor_Initialize(this);
    this->obj.status = OBJ_ACTIVE;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = greatFox->obj.pos.x + sTeamCsOffsetPos[index].x;
    this->obj.pos.y = greatFox->obj.pos.y - 500.0f;
    this->obj.pos.z = greatFox->obj.pos.z + sTeamCsOffsetPos[index].z;

    this->vel.x = -gArwingSpeed;
    this->obj.rot.y = 270.0f;

    Object_SetInfo(&this->info, this->obj.id);

    // @recomp: Setup team faces
    switch (index) {
        case 0: // Slippy
            this->iwork[14] = index + 3;
            break;
        case 1: // Falco
            this->iwork[14] = index + 1;
            break;
        case 2: // Peppy
            this->iwork[14] = index + 2;
            break;
    }

    AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
    AUDIO_PLAY_SFX(NA_SE_ARWING_BOOST, this->sfxSource, 0);

    this->fwork[29] = 5.0f;
}

// Sector Y level start team setup
RECOMP_PATCH void SectorY_801A06A4(ActorCutscene* this, s32 teamIdx) {
    if (gTeamShields[1 + teamIdx] > 0) {
        Actor_Initialize(this);
        this->obj.status = OBJ_ACTIVE;
        this->obj.id = OBJ_ACTOR_CUTSCENE;

        this->obj.pos.x = gPlayer[0].pos.x + D_i6_801A6AEC[teamIdx].x;
        this->obj.pos.y = gPlayer[0].pos.y + D_i6_801A6AEC[teamIdx].y;
        this->obj.pos.z = gPlayer[0].pos.z + D_i6_801A6AEC[teamIdx].z;

        this->fwork[0] = gPlayer[0].baseSpeed;
        this->rot_0F4.y = gPlayer[0].rot.y;
        this->rot_0F4.z = gPlayer[0].rot.z;
        this->state = teamIdx + 7;
        this->iwork[11] = 1;
        Object_SetInfo(&this->info, this->obj.id);

        // @recomp: Setup team faces
        this->iwork[14] = teamIdx + 2;

        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
        AUDIO_PLAY_SFX(NA_SE_ARWING_BOOST, this->sfxSource, 0);
    }
}

// Warp zone level complete team setup
RECOMP_PATCH void func_demo_80048CC4(ActorCutscene* this, s32 index) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_CUTSCENE;

    this->obj.pos.x = D_demo_800C9F60[index].x + gPlayer[0].pos.x;
    this->obj.pos.y = D_demo_800C9F60[index].y + gPlayer[0].pos.y;
    this->obj.pos.z = D_demo_800C9F60[index].z + gPlayer[0].trueZpos;

    this->rot_0F4.y = 0.0f;
    this->rot_0F4.z = D_demo_800C9F90[index];

    Object_SetInfo(&this->info, this->obj.id);

    if (index == 3) {
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_ENGINE, this->sfxSource, 0);
        AUDIO_PLAY_SFX(NA_SE_GREATFOX_BURNER, this->sfxSource, 0);
        this->animFrame = ACTOR_CS_GREAT_FOX;
    } else {
        this->iwork[11] = 1;
        this->iwork[14] = index + 2;
        AUDIO_PLAY_SFX(NA_SE_ARWING_ENGINE_FG, this->sfxSource, 4);
    }
}