#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "patches.h"
#include "debug.h"
#include "i3.h"
#include "i5.h"
#include "i6.h"

#define __sinf __sinf_recomp

extern bool sDrawCockpit;
extern u8 sPlayersVisible[];
extern f32 sReticleScales[4];
extern f32 D_i3_801C41B8[30];
extern s32 D_i3_801C4190[10];

void Display_CsLevelCompleteHandleCamera(Player* player);
void Display_Player_Update(Player* player, s32 reflectY);
void Display_PlayerFeatures(Player* player);
void Display_ArwingWingTrail_Draw(Player* player);
void Display_ArwingWingTrail_Update(Player* player);
void Display_PlayerShadow_Update(Player* player);
void Display_ActorMarks(void);
void Display_LockOnIndicator(void);
void Display_CockpitGlass(void);
void Display_Reticle(Player* player);
void Display_LandmasterMuzzleFlash(Player* player);
void Display_OnFootMuzzleFlash(Player* player);
void Display_DrawHelpAlert(void);
#if DEBUG_SPAWNER == 1
void Spawner(void);
#endif
#if DEBUG_BOSS_KILLER == 1
void KillBoss(void);
#endif

RECOMP_PATCH void Display_Update(void) {
    s32 i;
    Vec3f tempVec;
    Vec3f playerCamUp;
    Vec3f playerPos;
    s32 pad;
    Player* player;
    Player* camPlayer = &gPlayer[gPlayerNum];

    sDrawCockpit = false;

// @recomp remove 511 hit count cap, hated by generations
#if 0
    // 511 hit count cap
    if (gHitCount > 511) {
        gHitCount = 511;
    }
#endif

    Matrix_Push(&gGfxMatrix);

    if ((gCurrentLevel == LEVEL_AQUAS) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE)) {
        Math_SmoothStepToF(&gCamDistortion, 0.01f, 0.2f, 0.002f, 0.0f);
    } else {
        Math_SmoothStepToF(&gCamDistortion, 0.0f, 0.2f, 0.002f, 0.0f);
    }

    Matrix_RotateZ(gGfxMatrix, gGameFrameCount * 10.0f * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.0f + gCamDistortion, 1.0f - gCamDistortion, 1.0f, MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix, -(f32) gGameFrameCount * 10.0f * M_DTOR, MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 1.0f + gCamDistortion, 1.0f - gCamDistortion, 1.0f, MTXF_APPLY);
    Matrix_Push(&gGfxMatrix);
    Camera_SetupLights(camPlayer);
    Lights_SetOneLight(&gMasterDisp, gLight1x, gLight1y, gLight1z, gLight1R, gLight1G, gLight1B, gAmbientR, gAmbientG,
                       gAmbientB);

    if (gLevelMode == LEVELMODE_ON_RAILS) {
        Matrix_RotateY(gCalcMatrix, camPlayer->yRot_114 * M_DTOR, MTXF_NEW);
        Matrix_RotateX(gCalcMatrix, camPlayer->xRot_120 * M_DTOR, MTXF_APPLY);

        tempVec.x = camPlayer->cam.eye.x - camPlayer->pos.x;
        tempVec.y = camPlayer->cam.eye.y - camPlayer->pos.y;
        tempVec.z = camPlayer->cam.eye.z - (camPlayer->trueZpos + camPlayer->zPath);
        Matrix_MultVec3f(gCalcMatrix, &tempVec, &gPlayCamEye);
        gPlayCamEye.x += camPlayer->pos.x;
        gPlayCamEye.y += camPlayer->pos.y;
        gPlayCamEye.z += camPlayer->trueZpos + camPlayer->zPath;

        tempVec.x = camPlayer->cam.at.x - camPlayer->pos.x;
        tempVec.y = camPlayer->cam.at.y - camPlayer->pos.y;
        tempVec.z = camPlayer->cam.at.z - (camPlayer->trueZpos + camPlayer->zPath);
        Matrix_MultVec3f(gCalcMatrix, &tempVec, &gPlayCamAt);
        gPlayCamAt.x += camPlayer->pos.x;
        gPlayCamAt.y += camPlayer->pos.y;
        gPlayCamAt.z += camPlayer->trueZpos + camPlayer->zPath;

        if (camPlayer->alternateView && (camPlayer->boostSpeed > 5.0f)) {
            gPlayCamAt.x += SIN_DEG(gGameFrameCount * 150.0f) * camPlayer->boostSpeed * 0.2f;
        }
    } else if (camPlayer->state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE) {
        Display_CsLevelCompleteHandleCamera(camPlayer);
    } else {
        gPlayCamEye.x = camPlayer->cam.eye.x;
        gPlayCamEye.y = camPlayer->cam.eye.y;
        gPlayCamEye.z = camPlayer->cam.eye.z;
        gPlayCamAt.x = camPlayer->cam.at.x;
        gPlayCamAt.y = camPlayer->cam.at.y;
        gPlayCamAt.z = camPlayer->cam.at.z;
    }

    camPlayer->camYaw = -Math_Atan2F(gPlayCamEye.x - gPlayCamAt.x, gPlayCamEye.z - gPlayCamAt.z);
    camPlayer->camPitch = -Math_Atan2F(gPlayCamEye.y - gPlayCamAt.y,
                                       sqrtf(SQ(gPlayCamEye.z - gPlayCamAt.z) + SQ(gPlayCamEye.x - gPlayCamAt.x)));
    Matrix_RotateY(gCalcMatrix, -camPlayer->camYaw, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, camPlayer->camPitch, MTXF_APPLY);
    Matrix_RotateZ(gCalcMatrix, -camPlayer->camRoll * M_DTOR, MTXF_APPLY);
    tempVec.x = 0.0f;
    tempVec.y = 100.0f;
    tempVec.z = 0.0f;
    Matrix_MultVec3f(gCalcMatrix, &tempVec, &playerCamUp);

    if (gStarCount != 0) {
        gStarfieldRoll = DEG_TO_RAD(gPlayer[0].camRoll);
        Camera_SetStarfieldPos(gPlayCamEye.x, gPlayCamEye.y, gPlayCamEye.z, gPlayCamAt.x, gPlayCamAt.y, gPlayCamAt.z);
        Background_DrawStarfield();
    }

    Background_DrawBackdrop();
    Background_DrawSun();
    Matrix_Push(&gGfxMatrix);
    Matrix_LookAt(gGfxMatrix, gPlayCamEye.x, gPlayCamEye.y, gPlayCamEye.z, gPlayCamAt.x, gPlayCamAt.y, gPlayCamAt.z,
                  playerCamUp.x, playerCamUp.y, playerCamUp.z, MTXF_APPLY);

    if ((gLevelType == LEVELTYPE_PLANET) || (gCurrentLevel == LEVEL_BOLSE)) {
        if ((gCurrentLevel == LEVEL_TITANIA) &&
            ((gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_INTRO) || (gPlayer[0].unk_19C != 0))) {
            Matrix_Push(&gGfxMatrix);
            Matrix_Translate(gGfxMatrix, 0.0f, gCameraShakeY, 0.0f, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            Ground_801B58AC(&gMasterDisp, gPathGroundScroll);
            gPathGroundScroll = 0.0f;
            Matrix_Pop(&gGfxMatrix);
        } else if (gGroundSurface != SURFACE_WATER) {
            D_bg_8015F964 = false;
            Background_DrawGround();
        }
    }

    Lights_SetOneLight(&gMasterDisp, gLight2x, gLight2y, gLight2z, gLight2R, gLight2G, gLight2B, gAmbientR, gAmbientG,
                       gAmbientB);

    for (i = 0, player = &gPlayer[0]; i < gCamCount; i++, player++) {
        playerPos.x = player->pos.x;
        playerPos.y = player->pos.y;
        playerPos.z = player->trueZpos;
        Display_SetSecondLight(&playerPos);
        Display_Player_Update(player, 0);
        Display_SetupPlayerSfxPos(player);
    }

    if ((gGroundSurface == SURFACE_WATER) && (gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_INTRO)) {
        Lights_SetOneLight(&gMasterDisp, gLight2x, -1 * gLight2y, gLight2z, gLight2R, gLight2G, gLight2B, gAmbientR,
                           gAmbientG, gAmbientB);
        Matrix_Push(&gGfxMatrix);
        Matrix_Scale(gGfxMatrix, 1.0f, -1.0f, 1.0f, MTXF_APPLY);
        for (i = 0, player = &gPlayer[0]; i < gCamCount; i++, player++) {
            playerPos.x = player->pos.x;
            playerPos.y = player->pos.y;
            playerPos.z = player->trueZpos;
            Display_Player_Update(player, 1);
        }
        Matrix_Pop(&gGfxMatrix);
    }

    Lights_SetOneLight(&gMasterDisp, gLight1x, gLight1y, gLight1z, gLight1R, gLight1G, gLight1B, gAmbientR, gAmbientG,
                       gAmbientB);
    Object_Draw(1);
    TexturedLine_Draw();
    gReflectY = 1;
    PlayerShot_DrawAll();

    if ((gGroundSurface == SURFACE_WATER) && (gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_INTRO)) {
        Matrix_Push(&gGfxMatrix);
        Matrix_Scale(gGfxMatrix, 1.0f, -1.0f, 1.0f, MTXF_APPLY);
        gReflectY = -1;
        PlayerShot_DrawAll();
        Matrix_Pop(&gGfxMatrix);
    }

    gReflectY = -1;

    if ((gGroundSurface == SURFACE_WATER) && (gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_INTRO)) {
        Matrix_Push(&gGfxMatrix);
        Matrix_Scale(gGfxMatrix, 1.0f, -1.0f, 1.0f, MTXF_APPLY);
        for (i = 0, player = &gPlayer[0]; i < gCamCount; i++, player++) {
            if (sPlayersVisible[i]) {
                Display_PlayerFeatures(player);
                Display_ArwingWingTrail_Update(player);
            }
            Matrix_Pop(&gGfxMatrix);
        }
    }

    if (gCurrentLevel == LEVEL_AQUAS) {
        Effect_Draw(0);
    }

    if ((gGroundSurface == SURFACE_WATER) || (gAqDrawMode != 0)) {
        D_bg_8015F964 = true;
        Effect_Draw(1);
        Background_DrawGround();
    }

    if ((gCurrentLevel != LEVEL_AQUAS) &&
        (((gCurrentLevel != LEVEL_CORNERIA) && (gCurrentLevel != LEVEL_VENOM_ANDROSS)) ||
         ((gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_COMPLETE) &&
          (gPlayer[0].state_1C8 != PLAYERSTATE_1C8_LEVEL_INTRO)))) {
        Effect_Draw(0);
    }

    gReflectY = 1;

    for (i = 0, player = &gPlayer[0]; i < gCamCount; i++, player++) {
        if (sPlayersVisible[i]) {
            Display_PlayerShadow_Update(player);
            Display_PlayerFeatures(player);
            Display_ArwingWingTrail_Update(player);
        }
    }

    if ((gCurrentLevel == LEVEL_AQUAS) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE)) {
        Aquas_801AA20C();
    }

    if (((gCurrentLevel == LEVEL_CORNERIA) || (gCurrentLevel == LEVEL_VENOM_ANDROSS)) &&
        ((gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE) ||
         (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_INTRO))) {
        Effect_Draw(0);
    }

    BonusText_DrawAll();
    Matrix_Pop(&gGfxMatrix);
    Display_ActorMarks();
    Display_LockOnIndicator();

    if (sDrawCockpit) {
        Display_CockpitGlass();
    }

    for (i = 0, player = &gPlayer[0]; i < gCamCount; i++, player++) {
        if (sPlayersVisible[i]) {
            if (gShowReticles[i]) {
                Display_Reticle(player);
            }
            if (player->form == FORM_LANDMASTER) {
                Display_LandmasterMuzzleFlash(player);
            } else if (player->form == FORM_ON_FOOT) {
                Display_OnFootMuzzleFlash(player);
            }
        }
    }

    if ((gLevelMode == LEVELMODE_TURRET) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_ACTIVE)) {
        Turret_Draw(gPlayer);
    }

    Background_DrawLensFlare();

    if ((gCamCount != 1) &&
        ((camPlayer->state_1C8 == PLAYERSTATE_1C8_ACTIVE) || (camPlayer->state_1C8 == PLAYERSTATE_1C8_U_TURN))) {
        HUD_Draw();
        HUD_EdgeArrows_Update();
    }
    Matrix_Pop(&gGfxMatrix);
    Display_DrawHelpAlert();
    sPlayersVisible[gPlayerNum] = false;
    Matrix_Pop(&gGfxMatrix);

// @recomp DEBUG SECTION:
#if DEBUG_CHEATS == 1
    if ((gGameState != GSTATE_PLAY) || (gPlayState <= PLAY_INIT)) {
        return;
    }
    gLaserStrength[0] = 2;
    gBombCount[0] = 9;
#endif

#if DEBUG_SPAWNER == 1
    Spawner();
#endif

#if DEBUG_BOSS_KILLER == 1
    KillBoss();
#endif
#if DEBUG_L_TO_ALL_RANGE == 1
    {
        Player* player = &gPlayer[0];

        if (gControllerPress[0].button & L_TRIG) {
            player->state_1C8 = PLAYERSTATE_1C8_START_360;
        }
    }
#endif
#if DEBUG_SPEED_CONTROL == 1 // baseSpeed control
    {
        Player* player = gPlayer;
        static s32 prevSpeed;
        static bool debugFreeze = false;

        if (gControllerPress[0].button & L_JPAD) {
            player->baseSpeed -= 50;
        } else if (gControllerPress[0].button & R_JPAD) {
            player->baseSpeed += 50;
        }

        if ((!debugFreeze) && (gControllerPress[0].button & D_JPAD)) {
            prevSpeed = player->baseSpeed;
            player->baseSpeed = 0;
            debugFreeze = true;
        } else if ((debugFreeze) && (gControllerPress[0].button & D_JPAD)) {
            player->baseSpeed = prevSpeed;
            debugFreeze = false;
        }
    }
#endif
#if DEBUG_NO_COLLISION == 1
    gPlayer->mercyTimer = 1000;
#endif
}

RECOMP_PATCH void Display_Reticle(Player* player) {
    Vec3f* translate;
    s32 i;

    if ((gPlayerNum == player->num) && ((player->form == FORM_ARWING) || (player->form == FORM_LANDMASTER)) &&
        player->draw &&
        (((gGameState == GSTATE_PLAY) && (player->state_1C8 == PLAYERSTATE_1C8_ACTIVE)) ||
         (gGameState == GSTATE_MENU))) {
        for (i = 0; i < 2; i++) {
            translate = &D_display_801613E0[i];
            Matrix_Push(&gGfxMatrix);

            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_RETICLE + i, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

            Matrix_Translate(gGfxMatrix, translate->x, translate->y, translate->z, MTXF_APPLY);

            if (gChargeTimers[player->num] >= 20) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_63);
                if (i == 1) {
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                    gDPSetEnvColor(gMasterDisp++, 255, 0, 0, 255);
                    Math_SmoothStepToF(&sReticleScales[player->num], 2.0f, 1.0f, 0.4f, 0.0f);
                } else {
                    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 0, 255);
                    gDPSetEnvColor(gMasterDisp++, 255, 255, 0, 255);
                }
            } else {
                RCP_SetupDL_36();
            }

            if (i == 1) {
                Matrix_Scale(gGfxMatrix, sReticleScales[player->num], sReticleScales[player->num], 1.0f, MTXF_APPLY);
                Math_SmoothStepToF(&sReticleScales[player->num], 1.0f, 1.0f, 0.2f, 0.0f);
            }
            Matrix_Scale(gGfxMatrix, 4.0f, 4.0f, 4.0f, MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_1024F60);

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

            Matrix_Pop(&gGfxMatrix);
        }
    }
}

RECOMP_PATCH void Display_LockOnIndicator(void) {
    s32 i;
    s32 j;
    f32 var_fs0;

    for (i = 0; i < gCamCount; i++) {
        if (gLockOnTargetViewPos[i].z < 0.0f) {
            var_fs0 = VEC3F_MAG(&gLockOnTargetViewPos[i]);
            if (var_fs0 < 20000.0f) {
                var_fs0 *= 0.0015f;
                if (var_fs0 > 100.0f) {
                    var_fs0 = 100.0f;
                }
                if (var_fs0 < 1.2f) {
                    var_fs0 = 1.2f;
                }

                Matrix_Push(&gGfxMatrix);

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_RETICLE + 2 + i, G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);

                Matrix_Translate(gGfxMatrix, gLockOnTargetViewPos[i].x, gLockOnTargetViewPos[i].y,
                                 gLockOnTargetViewPos[i].z, MTXF_APPLY);
                if ((gPlayState != PLAY_PAUSE) && (i == gPlayerNum)) {
                    Math_SmoothStepToF(&D_display_801615A8[i], 0.0f, 0.5f, 20.0f, 0);
                    Math_SmoothStepToF(&D_display_801615B8[i], 1.0, 0.5f, 0.2f, 0);
                }
                var_fs0 *= D_display_801615B8[i];
                Matrix_Scale(gGfxMatrix, var_fs0 * 1.5f, var_fs0 * 1.5f, 1.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, D_display_801615A8[i] * M_DTOR, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);
                RCP_SetupDL(&gMasterDisp, SETUPDL_67);
                gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
                gDPSetEnvColor(gMasterDisp++, 255, 0, 0, 255);
                gSPDisplayList(gMasterDisp++, D_1024F60);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

                Matrix_Pop(&gGfxMatrix);
            }
        }
    }

    for (j = 0; j < gCamCount; j++) {
        gLockOnTargetViewPos[j].x = gLockOnTargetViewPos[j].y = 0.f;
        gLockOnTargetViewPos[j].z = 100.0f;
    }
}

// Blue Marine Reticle
RECOMP_PATCH void Aquas_801AA20C(void) {
    s32 i;
    f32 x;
    f32 y;

    if (gPlayer[0].draw) {
        Matrix_Push(&gGfxMatrix);
        Math_SmoothStepToF(&D_i3_801C41B8[5], 3.0f, 1.0f, 4.0f, 0.0001f);
        RCP_SetupDL(&gMasterDisp, SETUPDL_61);

        if (D_i3_801C4190[3] == 0) {
            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
            x = -10.0f;
            y = 10.0f;

            if (D_i3_801C4190[0] != 0) {
                x = y = 0.0f;
            }

            Matrix_Translate(gGfxMatrix, D_i3_801C41B8[0] + x, D_i3_801C41B8[1] + y,
                             D_i3_801C41B8[2] + gPlayer[0].zPath, MTXF_APPLY);
            Matrix_Scale(gGfxMatrix, D_i3_801C41B8[5], D_i3_801C41B8[5], D_i3_801C41B8[5], MTXF_APPLY);

            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_RETICLE + 6, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

            for (i = 0; i < 4; i++) {
                Matrix_RotateZ(gGfxMatrix, M_PI / 2, MTXF_APPLY);
                Matrix_Translate(gGfxMatrix, x, y, 0.0f, MTXF_APPLY);
                Matrix_Push(&gGfxMatrix);
                Matrix_SetGfxMtx(&gMasterDisp);
                gSPDisplayList(gMasterDisp++, D_blue_marine_3000470);
                Matrix_Pop(&gGfxMatrix);
            }

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

        } else {
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_RETICLE + 7, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

            gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 0, 0, 255);
            Matrix_Translate(gGfxMatrix, D_i3_801C41B8[0], D_i3_801C41B8[1], D_i3_801C41B8[2] + gPlayer[0].zPath,
                             MTXF_APPLY);
            Matrix_Scale(gGfxMatrix, D_i3_801C41B8[5], D_i3_801C41B8[5], D_i3_801C41B8[5], MTXF_APPLY);
            Matrix_SetGfxMtx(&gMasterDisp);
            gSPDisplayList(gMasterDisp++, D_blue_marine_3000130);

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
        }

        Matrix_Pop(&gGfxMatrix);
    }
}