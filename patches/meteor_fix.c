#include "patches.h"

extern Vec3f D_i2_801955C4;

void Meteo_LevelStart_SetupTeam(ActorCutscene* this, s32 teamIdx);
void Meteo_8018CAD8(void);
void Meteo_8018CA10(MeMeteor2* this, ActorCutscene* actorCs, f32 x, f32 y, f32 z);
void Meteo_Effect346_Spawn(ActorEvent* this);

PosRot sMeteorGroup1[10] = {
    {
        // Meteor Number: 10000005
        // Pos:
        { -751.610779, 895.229431, -14118.559570 },
        // Rot:
        { 246.692810, 252.189011, 0.0f },
    },
    {
        // Meteor Number: 10000006
        // Pos:
        { -1496.616821, -237.345093, -13889.714844 },
        // Rot:
        { 240.222717, 204.470245, 0.0f },
    },
    {
        // Meteor Number: 10000007
        // Pos:
        { -2340.733887, 671.444031, -13942.265625 },
        // Rot:
        { 224.260315, 213.531525, 0.0f },
    },
    {
        // Meteor Number: 10000008
        // Pos:
        { -872.569824, 515.999390, -13978.042969 },
        // Rot:
        { 353.063599, 196.916153, 0.0f },
    },
    {
        // Meteor Number: 10000009
        // Pos:
        { -1244.159180, -568.048401, -13831.064453 },
        // Rot:
        { 197.289780, 116.560478, 0.0f },
    },
    {
        // Meteor Number: 1000000a
        // Pos:
        { -1766.432739, 71.170959, -13912.819336 },
        // Rot:
        { 276.255524, 353.187103, 0.0f },
    },
    {
        // Meteor Number: 1000000b
        // Pos:
        { -1174.724609, -202.646606, -14182.970703 },
        // Rot:
        { 92.375626, 72.047653, 0.0f },
    },
    {
        // Meteor Number: 1000000c
        // Pos:
        { -2022.511963, -378.516357, -14139.068359 },
        // Rot:
        { 224.973175, 315.608368, 0.0f },
    },
    {
        // Meteor Number: 1000000d
        // Pos:
        { -1707.861450, 1120.328125, -13761.345703 },
        // Rot:
        { 298.162506, 235.397705, 0.0f },
    },
    {
        // Meteor Number: 1000000e
        // Pos:
        { -1883.771973, -502.502319, -14215.611328 },
        // Rot:
        { 178.305359, 92.261642, 0.0f },
    },
};

PosRot sMeteorGroup2[5] = {
    {
        // Meteor Number: 20000004
        // Pos:
        { 182.362061, 170.138458, -7205.532715 },
        // Rot:
        { 231.369064, 257.044342, 0.0f },
    },
    {
        // Meteor Number: 20000005
        // Pos:
        { 335.380554, -309.073853, -7308.596680 },
        // Rot:
        { 324.552704, 51.662823, 0.0f },
    },
    {
        // Meteor Number: 20000006
        // Pos:
        { -1299.856689, 1078.993408, -7368.679688 },
        // Rot:
        { 130.723480, 213.801590, 0.0f },
    },
    {
        // Meteor Number: 20000007
        // Pos:
        { 196.442139, 312.897308, -7504.875000 },
        // Rot:
        { 68.665321, 15.956697, 0.0f },
    },
    {
        // Meteor Number: 20000008
        // Pos:
        { -1016.868591, 662.603943, -7195.014648 },
        // Rot:
        { 152.309296, 240.838593, 0.0f },
    },
};

void Meteo_SpawnMeteorsGroup1(MeMeteor2* this, ActorCutscene* actorCs, s32 index) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_ME_METEOR_2;

    this->obj.pos.x = sMeteorGroup1[index - 5].pos.x;
    this->obj.pos.y = sMeteorGroup1[index - 5].pos.y;
    this->obj.pos.z = sMeteorGroup1[index - 5].pos.z;

    this->obj.rot.y = sMeteorGroup1[index - 5].rot.y;
    this->obj.rot.x = sMeteorGroup1[index - 5].rot.x;

#if 0
    recomp_printf("{ // Meteor Number: %x \n", index);
    recomp_printf(" // Pos: \n");
    recomp_printf("    { %f, ", this->obj.pos.x);
    recomp_printf(" %f, ", this->obj.pos.y);
    recomp_printf(" %f }, \n", this->obj.pos.z);
    recomp_printf(" // Rot: \n");
    recomp_printf("    {");
    recomp_printf(" %f, ", this->obj.rot.x);
    recomp_printf(" %f, ", this->obj.rot.y);
    recomp_printf(" 0.0f ");
    recomp_printf("},\n");
    recomp_printf("}, \n");
#endif

    this->timer_0C2 = 10000;
    this->vel.z = 30.0f;
    Object_SetInfo(&this->info, this->obj.id);
}

void Meteo_SpawnMeteorsGroup2(MeMeteor2* this, ActorCutscene* actorCs, s32 index) {
    Actor_Initialize(this);
    this->obj.status = OBJ_INIT;
    this->obj.id = OBJ_ACTOR_ME_METEOR_2;

    this->obj.pos.x = sMeteorGroup2[index - 4].pos.x;
    this->obj.pos.y = sMeteorGroup2[index - 4].pos.y;
    this->obj.pos.z = sMeteorGroup2[index - 4].pos.z;

    this->obj.rot.y = sMeteorGroup2[index - 4].rot.y;
    this->obj.rot.x = sMeteorGroup2[index - 4].rot.x;

#if 0
    recomp_printf("{ // Meteor Number: %x \n", index);
    recomp_printf(" // Pos: \n");
    recomp_printf("    { %f, ", this->obj.pos.x);
    recomp_printf(" %f, ", this->obj.pos.y);
    recomp_printf(" %f }, \n", this->obj.pos.z);
    recomp_printf(" // Rot: \n");
    recomp_printf("    {");
    recomp_printf(" %f, ", this->obj.rot.x);
    recomp_printf(" %f, ", this->obj.rot.y);
    recomp_printf(" 0.0f ");
    recomp_printf("},\n");
    recomp_printf("}, \n");
#endif

    this->timer_0C2 = 10000;
    this->vel.z = 30.0f;
    Object_SetInfo(&this->info, this->obj.id);
}

RECOMP_PATCH void Meteo_LevelStart(Player* player) {
    u8 sp8F;
    s32 i;
    Actor* falco = &gActors[0];
    Actor* slippy = &gActors[1];
    Actor* peppy = &gActors[2];
    Actor* greatFox = &gActors[3];
    f32 x;
    f32 y;
    f32 z;
    f32 sp68;
    f32 sp64;
    Vec3f sp58;
    Vec3f sp4C;

    gFillScreenAlphaStep = 4;

    PRINTF("Demo_Time %d\n", gCsFrameCount);

    switch (player->csState) {
        case 0:
            gCsFrameCount = 0;

            if (gTeamShields[TEAM_ID_FALCO] > 0) {
                Meteo_LevelStart_SetupTeam(falco, 0);
            }
            if (gTeamShields[TEAM_ID_SLIPPY] > 0) {
                Meteo_LevelStart_SetupTeam(slippy, 1);
            }
            if (gTeamShields[TEAM_ID_PEPPY] > 0) {
                Meteo_LevelStart_SetupTeam(peppy, 2);
            }

            Meteo_LevelStart_SetupTeam(greatFox, 3);
            Meteo_8018CAD8();

            for (i = 5; i < 15; i++) {
                Meteo_SpawnMeteorsGroup1(&gActors[i], greatFox, i);
            }

            D_ctx_80177A48[1] = -13000.0f;
            D_ctx_80177A48[2] = -13000.0f;
            D_ctx_80177A48[4] = -22000.0f;

            player->cam.eye.x = gCsCamEyeX = player->pos.x + 100.0f;
            player->cam.eye.y = gCsCamEyeY = player->pos.y;
            player->cam.eye.z = gCsCamEyeZ = D_ctx_80177A48[1] + player->trueZpos;

            player->cam.at.x = gCsCamAtX = D_ctx_80177A48[2] + player->pos.x;
            player->cam.at.y = gCsCamAtY = player->pos.y;
            player->cam.at.z = gCsCamAtZ = D_ctx_80177A48[4] + player->trueZpos;

            player->csState = 1;

            D_ctx_80177A48[3] = 1.0f;

        case 1:
            greatFox->vel.z = 4.0f;
            gCsCamEyeX = player->pos.x + 100.0f;
            gCsCamEyeY = player->pos.y;
            gCsCamEyeZ = D_ctx_80177A48[1] + player->trueZpos;
            gCsCamAtX = D_ctx_80177A48[2] + player->pos.x;
            gCsCamAtY = player->pos.y + 20.0f;
            gCsCamAtZ = D_ctx_80177A48[4] + player->trueZpos;
            Math_SmoothStepToF(&D_ctx_80177A48[1], 8000.0f, 0.05f, 20.0f, 0);
            Math_SmoothStepToF(&D_ctx_80177A48[2], 0.0f, 0.05f, 25.0f, 0);
            Math_SmoothStepToF(&D_ctx_80177A48[4], 0.0f, 0.05f, 200.0f, 0);
            Math_SmoothStepToF(&player->rot.z, 0.0f, 0.05f, 0.3f, 0);

            D_ctx_80177A48[0] = 0.1f;
            if (gCsFrameCount == 680) {
                greatFox->state = 10;
            }
            if (gCsFrameCount == 720) {
                falco->state = 11;
            }
            if (gCsFrameCount == 750) {
                peppy->state = 12;
            }
            if (gCsFrameCount == 780) {
                slippy->state = 13;
            }
            if (gCsFrameCount > 810) {
                player->csState = 2;
                D_ctx_80177A48[0] = 0.0f;
                player->csTimer = 40;
            }

            sp8F = false;
            if (gCsFrameCount == 190) {
                player->csEventTimer = 5;
                player->meTargetIndex = 10;
                sp8F = true;
            }
            if (gCsFrameCount == 230) {
                player->csEventTimer = 3;
                player->meTargetIndex = 6;
                sp8F = true;
            }
            if (gCsFrameCount == 240) {
                player->csEventTimer = 3;
                player->meTargetIndex = 11;
                sp8F = true;
            }
            if (gCsFrameCount == 270) {
                player->csEventTimer = 2;
                player->meTargetIndex = 12;
                sp8F = true;
            }
            if (gCsFrameCount == 600) {
                Meteo_8018CA10(&gActors[16], greatFox, 100.0f, 500.0f, 1500.0f);
                Meteo_8018CA10(&gActors[17], greatFox, 300.0f, 400.0f, 2000.0f);
            }
            if (gCsFrameCount == 660) {
                for (i = 4; i < 15; i++) {
                    gActors[i].obj.status = OBJ_FREE;
                }

                greatFox->obj.pos.x += 1000.0f;
                greatFox->obj.pos.z += 4000.0f;

                for (i = 4; i < 9; i++) {
                    Meteo_SpawnMeteorsGroup2(&gActors[i], greatFox, i);
                }

                greatFox->obj.pos.x -= 1000.0f;
                greatFox->obj.pos.z -= 4000.0f;

                Meteo_8018CA10(&gActors[13], greatFox, 1500.0f, 200.0f, 100.0f);
                Meteo_8018CA10(&gActors[14], greatFox, 1200.0f, -200.0f, -500.0f);
                Meteo_8018CA10(&gActors[15], greatFox, 2000.0f, -100.0f, -1000.0f);

                gActors[50].obj.status = gActors[16].obj.status = gActors[17].obj.status = OBJ_FREE;
            }

            if (gCsFrameCount > 660) {
                player->arwing.drawFace = false;
            }

            if (gCsFrameCount == 340) {
                func_effect_8007D2C8(gActors[8].obj.pos.x, gActors[8].obj.pos.y, gActors[8].obj.pos.z, 10.0f);
                gActors[8].obj.status = OBJ_FREE;
                Meteo_Effect346_Spawn(&gActors[8]);
            }

            if (player->csEventTimer != 0) {
                if (sp8F != 0) {
                    sp58 = D_i2_801955C4;
                    D_ctx_80177A48[3] *= -1.0f;
                    x = gActors[player->meTargetIndex].obj.pos.x - (greatFox->obj.pos.x + (D_ctx_80177A48[3] * 74.0f));
                    y = gActors[player->meTargetIndex].obj.pos.y - (greatFox->obj.pos.y - 232.0f);
                    z = gActors[player->meTargetIndex].obj.pos.z - (greatFox->obj.pos.z - 1190.0f);

                    sp64 = Math_RadToDeg(Math_Atan2F(x, z));
                    x = sqrtf(SQ(x) + SQ(z));
                    sp68 = Math_RadToDeg(-Math_Atan2F(y, x));

                    Matrix_RotateY(gCalcMatrix, M_DTOR * sp64, MTXF_NEW);
                    Matrix_RotateX(gCalcMatrix, M_DTOR * sp68, MTXF_APPLY);
                    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp58, &sp4C);

                    Actor_SpawnGreatFoxLaser(100, greatFox->obj.pos.x + (D_ctx_80177A48[3] * 74.0f) + (sp4C.x * 0.6f),
                                             greatFox->obj.pos.y - 232.0f + (sp4C.y * 0.8f),
                                             greatFox->obj.pos.z - 1190.0f + (sp4C.z * 0.8f), sp4C.x, sp4C.y, sp4C.z,
                                             sp68, sp64, 0.0f);
                }
                if (player->csEventTimer == 1) {
                    func_effect_8007D2C8(gActors[player->meTargetIndex].obj.pos.x,
                                         gActors[player->meTargetIndex].obj.pos.y,
                                         gActors[player->meTargetIndex].obj.pos.z, 10.0f);
                    gActors[player->meTargetIndex].obj.status = OBJ_FREE;
                    Meteo_Effect346_Spawn(&gActors[player->meTargetIndex]);
                    Object_Kill(&gPlayerShots[0].obj, gPlayerShots[0].sfxSource);
                }
            }
            break;

        case 2:
            gCsCamEyeX = player->pos.x;
            gCsCamEyeY = (player->pos.y * player->unk_148) + 50.0f;
            gCsCamEyeZ = 400.0f;
            gCsCamAtX = player->pos.x;
            gCsCamAtY = (player->pos.y * player->unk_148) + 20.0f;
            gCsCamAtZ = player->trueZpos;

            Math_SmoothStepToF(D_ctx_80177A48, 1.0f, 1.0f, 0.01f, 0.0f);

            if (player->csTimer == 0) {
                AUDIO_PLAY_BGM(gBgmSeqId);
                gLevelStartStatusScreenTimer = 80;
                player->state_1C8 = PLAYERSTATE_1C8_ACTIVE;
                player->csState = 0;
                player->csTimer = 0;
                player->csEventTimer = 0;
                player->cam.eye.x = player->pos.x;
                player->cam.eye.y = (player->pos.y * player->unk_148) + 50.0f;
                player->cam.eye.z = 400.0f;
                player->cam.at.x = player->pos.x;
                player->cam.at.y = (player->pos.y * player->unk_148) + 20.0f;
                player->cam.at.z = player->trueZpos;

                for (i = 0; i < 4; i++) {
                    Object_Kill(&gActors[i].obj, gActors[i].sfxSource);
                }

                gLoadLevelObjects = 1;
                break;
            }
    }

    switch (gCsFrameCount) {
        case 500:
            if ((gTeamShields[TEAM_ID_SLIPPY] > 0) && (gTeamShields[TEAM_ID_PEPPY] > 0)) {
                Radio_PlayMessage(gMsg_ID_3005, RCID_SLIPPY);
            }
            break;

        case 600:
            if ((gTeamShields[TEAM_ID_SLIPPY] > 0) && (gTeamShields[TEAM_ID_PEPPY] > 0)) {
                Radio_PlayMessage(gMsg_ID_3010, RCID_PEPPY);
            }
            break;

        case 700:
            Radio_PlayMessage(gMsg_ID_3015, RCID_FOX);
            break;
    }

    Math_SmoothStepToF(&player->cam.eye.x, gCsCamEyeX, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.eye.y, gCsCamEyeY, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.x, gCsCamAtX, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.y, gCsCamAtY, D_ctx_80177A48[0], 20000.0f, 0.0f);
    Math_SmoothStepToF(&player->cam.at.z, gCsCamAtZ, D_ctx_80177A48[0], 20000.0f, 0.0f);
}