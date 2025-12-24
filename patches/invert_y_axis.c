#include "patches.h"

void Player_WingEffects(Player* player);
void func_tank_80043280(u16* text0, u16* text1, f32 zRot);
void func_tank_80043B18(Player* player);
void Aquas_Bubble_Spawn(f32 xPos, f32 yPos, f32 zPos, f32 scale2, s32 unk4E);
void Aquas_801A8E30(void);
void Aquas_801A99D4(Player* player);
void Aquas_801AA4BC(Player* player);

extern s32 sTankActiveBurnerCount;
extern f32 D_800C9F20;
extern f32 D_i3_801C41B8[30];
extern s32 D_i3_801C4190[10];
extern f32 D_i3_801BFB60;

// Arwing

RECOMP_PATCH void Player_MoveArwing360(Player* player) {
    f32 sp7C;
    f32 sp78;
    f32 scale;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;
    f32 temp;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    Vec3f sp4C;
    Vec3f sp40;

    gPlayerTurnRate = 2.3f;
    gPlayerTurnStickMod = 0.68f;

    sp7C = -gInputPress->stick_x;
    sp78 = gInputPress->stick_y * INVERT_Y_AXIS_COND_RES;

    Math_SmoothStepToAngle(&player->aerobaticPitch, 0.0f, 0.1f, 5.0f, 0.01f);
    Matrix_RotateZ(gCalcMatrix, -player->zRotBank * M_DTOR, MTXF_NEW);

    sp4C.x = sp7C * 0.75f;
    sp4C.y = sp78 * 0.75f;
    sp4C.z = 0.0f;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp4C, &sp40);

    sp60 = sp40.y;
    sp5C = sp58 = 0.0f;

    if (sp40.x < -5.0f) {
        sp5C = -sp40.x;
    }
    if (sp40.x > 5.0f) {
        sp58 = sp40.x;
    }

    Math_SmoothStepToF(&player->arwing.unk_28, 0.0f, 0.1f, 100.0f, 0.0f);
    Math_SmoothStepToF(&player->arwing.upperRightFlapYrot, -sp60 + sp5C, 0.1f, 100.0f, 0.0f);
    Math_SmoothStepToF(&player->arwing.bottomRightFlapYrot, -sp60 - sp5C, 0.1f, 100.0f, 0.0f);
    Math_SmoothStepToF(&player->arwing.upperLeftFlapYrot, -sp60 + sp58, 0.1f, 100.0f, 0.0f);
    Math_SmoothStepToF(&player->arwing.bottomLeftFlapYrot, -sp60 - sp58, 0.1f, 100.0f, 0.0f);

    scale = 0.1f;
    if ((player->zRotBank > 10.0f) && (sp7C > 0)) {
        gPlayerTurnRate *= 2.0f;
        scale = 0.2f;
    }

    if ((player->zRotBank < -10.0f) && (sp7C < 0)) {
        gPlayerTurnRate *= 2.0f;
        scale = 0.2f;
    }

    Math_SmoothStepToF(&player->rot.y, sp7C * gPlayerTurnStickMod, scale, gPlayerTurnRate, 0.03f);

    scale = 0.03f;
    if ((player->zRotBank > 10.0f) && (sp7C > 0)) {
        scale = 0.05f;
    }
    if ((player->zRotBank < -10.0f) && (sp7C < 0)) {
        scale = 0.05f;
    }

    Math_SmoothStepToF(&player->yRotVel_11C, player->rot.y * scale, 0.1f, 0.8f, 0.05f);

    player->yRot_114 += player->yRotVel_11C;
    if (player->yRot_114 >= 360.0f) {
        player->yRot_114 -= 360.0f;
    }
    if (player->yRot_114 < 0.0f) {
        player->yRot_114 += 360.0f;
    }

    gPlayerTurnRate = 2.3f;
    var_fa1 = 0.1f;
    temp = -sp78 * gPlayerTurnStickMod;

    if ((temp <= 0.0f) && (player->pos.y < (gGroundHeight + 50.0f))) {
        gPlayerTurnRate *= 2.0f;
        temp = 0.0f;
        var_fa1 = 0.2f;
    }

    Math_SmoothStepToF(&player->rot.x, temp, var_fa1, gPlayerTurnRate, 0.03f);

    var_fv1 = 1.5f;
    if (player->pos.y < (gGroundHeight + 70.0f)) {
        var_fv1 = 0.8f;
    }

    if (!((gInputHold->button & R_TRIG) && (gInputHold->button & Z_TRIG)) &&
        !(!(gInputHold->button & R_TRIG) && !(gInputHold->button & Z_TRIG))) {
        var_fv1 = 0.1f;
    }

    var_fv0 = 4.0f;
    if (sp7C == 0) {
        var_fv0 = 1.0f;
    }

    Math_SmoothStepToF(&player->rot.z, sp7C * 0.6f * var_fv1, 0.1f, var_fv0, 0.03f);

    player->bankAngle = player->rot.z + player->zRotBank + player->zRotBarrelRoll;

    Matrix_RotateY(gCalcMatrix, (player->yRot_114 + player->rot.y + 180.0f) * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, -((player->xRot_120 + player->rot.x + player->aerobaticPitch) * M_DTOR), MTXF_APPLY);

    sp4C.x = 0.0f;
    sp4C.y = 0.0f;

    if (player->arwing.rightWingState <= WINGSTATE_BROKEN) {
        sp4C.x -= 2.5f;
        sp4C.y -= 2.5f;
    }
    if (player->arwing.leftWingState <= WINGSTATE_BROKEN) {
        sp4C.x += 2.5f;
        sp4C.y -= 2.5f;
    }
    sp4C.z = player->baseSpeed + player->boostSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp4C, &sp40);

    player->vel.x = sp40.x;
    player->vel.z = sp40.z;
    player->vel.y = sp40.y;

    player->pos.x += player->vel.x;
    player->pos.y += player->vel.y;

    if ((player->pathHeight < player->pos.y) && (player->vel.y >= 0.0f)) {
        Math_SmoothStepToF(&player->pos.y, player->pathHeight, 0.1f, fabsf(player->vel.y * 1.5f) + 5.0f, 0.0f);
    }

    if ((player->pos.y < player->pathFloor) && (player->vel.y <= 0.0f)) {
        if (player->pathFloor >= 0.0f) {
            player->pos.y = player->pathFloor;
        } else {
            Math_SmoothStepToF(&player->pos.y, player->pathFloor, 0.1f, fabsf(player->vel.y * 1.5f) + 5.0f, 0.0f);
        }
    }

    player->pos.z += player->vel.z;

    if (player->pathHeight - 100.0f < player->pos.y) {
        player->flags_228 = PFLAG_228_3;
    }

    if (player->pos.y < -(player->pathHeight - 100.0f)) {
        player->flags_228 = PFLAG_228_2;
    }

    Player_CheckBounds360(player);
    player->trueZpos = player->pos.z;
    Player_WingEffects(player);
    Player_DamageEffects(player);
}

RECOMP_PATCH void Player_MoveArwingOnRails(Player* player) {
    f32 stickX;
    f32 stickY;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;
    f32 sp84;
    s32 pad;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    Vec3f sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;

    gPlayerTurnRate = 2.3f;
    gPlayerTurnStickMod = 0.68f;

    if ((gInputPress->stick_x != 0) || (gInputPress->stick_y != 0)) {
        gPlayerTurnStickMod = 0.68f; //! FAKE ?
    }

    stickX = -gInputPress->stick_x;
    stickY = +gInputPress->stick_y * INVERT_Y_AXIS_COND_RES;

    Math_SmoothStepToAngle(&player->aerobaticPitch, 0.0f, 0.1f, 5.0f, 0.01f);

    if (player->alternateView) {
        Matrix_RotateZ(gCalcMatrix, player->zRotBank * M_DTOR, MTXF_NEW);

        sp68.z = 0.0f;
        sp68.x = stickX;
        sp68.y = stickY;

        Matrix_MultVec3f(gCalcMatrix, &sp68, &sp5C);

        stickX = sp5C.x;
        stickY = sp5C.y;
    } else {
        Matrix_RotateZ(gCalcMatrix, (-player->zRotBank) * M_DTOR, MTXF_NEW);

        sp68.z = 0.0f;
        sp68.x = stickX * 0.75f;
        sp68.y = stickY * 0.75f;

        Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp68, &sp5C);

        sp7C = sp5C.y;
        sp78 = (sp74 = 0.0f);

        if (sp5C.x < -5.0f) {
            sp78 = -sp5C.x;
        }
        if (sp5C.x > 5.0f) {
            sp74 = sp5C.x;
        }
        Math_SmoothStepToF(&player->arwing.unk_28, 0.0f, 0.1f, 100.0f, 0.0f);
        Math_SmoothStepToF(&player->arwing.upperRightFlapYrot, (-sp7C) + sp78, 0.1f, 100.0f, 0.0f);
        Math_SmoothStepToF(&player->arwing.bottomRightFlapYrot, (-sp7C) - sp78, 0.1f, 100.0f, 0.0f);
        Math_SmoothStepToF(&player->arwing.upperLeftFlapYrot, (-sp7C) + sp74, 0.1f, 100.0f, 0.0f);
        Math_SmoothStepToF(&player->arwing.bottomLeftFlapYrot, (-sp7C) - sp74, 0.1f, 100.0f, 0.0f);
    }

    sp84 = 0.1f;
    if ((player->zRotBank > 10.0f) && (stickX > 0)) {
        sp84 = 0.2f;
        gPlayerTurnRate *= 2.0f;
    }
    if ((player->zRotBank < -10.0f) && (stickX < 0)) {
        sp84 = 0.2f;
        gPlayerTurnRate *= 2.0f;
    }
    if (player->rollState != 0) {
        sp84 = 0.2f;
        gPlayerTurnRate = 6.8999996f; // 690.0f * 0.01f
    }

    Math_SmoothStepToF(&player->rot.y, stickX * gPlayerTurnStickMod, sp84, gPlayerTurnRate, 0.03f);

    gPlayerTurnRate = 2.3f;
    sp84 = 0.1f;
    var_fa1 = -stickY * gPlayerTurnStickMod;

    if ((var_fa1 <= 0.0f) && (player->pos.y < (gGroundHeight + 50.0f))) {
        var_fa1 = 0.0f;
        sp84 = 0.2f;
        gPlayerTurnRate *= 2.0f;
    }

    Math_SmoothStepToF(&player->rot.x, var_fa1, sp84, gPlayerTurnRate, 0.03f);

    var_fv1 = 1.0f;
    if (player->pos.y < (gGroundHeight + 70.0f)) {
        var_fv1 = 0.8f;
    }

    if (!((gInputHold->button & R_TRIG) && (gInputHold->button & Z_TRIG)) &&
        !(!(gInputHold->button & R_TRIG) && !(gInputHold->button & Z_TRIG))) {
        var_fv1 = 0.1f;
    }

    var_fv0 = 4.0f;
    if (stickX == 0) {
        var_fv0 = 1.0f;
    }

    Math_SmoothStepToF(&player->rot.z, (stickX * 0.6f) * var_fv1, 0.1f, var_fv0, 0.03f);
    Matrix_RotateY(gCalcMatrix, (player->rot.y + 180.0f) * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, -((player->rot.x + player->aerobaticPitch) * M_DTOR), MTXF_APPLY);

    sp68.x = 0.0f;
    sp68.y = 0.0f;
    sp68.z = player->baseSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp68, &sp44);

    sp44.x *= 1.4f;
    sp44.y *= 1.4f;

    Matrix_RotateY(gCalcMatrix, player->yRot_114 * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, player->xRot_120 * M_DTOR, MTXF_APPLY);
    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp44, &sp5C);

    sp68.x = 0.0f;
    sp68.y = 0.0f;
    sp68.z = -player->boostSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp68, &sp50);

    player->vel.x = (sp5C.x + sp50.x) * player->unk_150;
    player->vel.y = (sp5C.y + sp50.y) * player->unk_150;
    player->vel.z = sp5C.z + sp50.z;

    if (gCurrentLevel == LEVEL_VENOM_ANDROSS) {
        player->vel.z += D_Andross_801A7F58;
    }
    sp68.x = 0.0f;
    sp68.y = 0.0f;
    sp68.z = -player->boostSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp68, &sp50);

    if (player->arwing.rightWingState <= WINGSTATE_BROKEN) {
        player->vel.x += 2.5f;
        player->vel.y -= 2.5f;
    }
    if (player->arwing.leftWingState <= WINGSTATE_BROKEN) {
        player->vel.x -= 2.5f;
        player->vel.y -= 2.5f;
    }

    if (player->pos.x > (player->xPath + (player->pathWidth - 100.0f))) {
        player->flags_228 = PFLAG_228_0;
    }
    if (player->pos.x < (player->xPath - (player->pathWidth - 100.0f))) {
        player->flags_228 = PFLAG_228_1;
    }
    if (player->pos.y > (player->yPath + (player->pathHeight - 100.0f))) {
        player->flags_228 = PFLAG_228_3;
    }
    if (player->pos.y < (player->yPath - (player->pathHeight - 100.0f))) {
        player->flags_228 = PFLAG_228_2;
    }

    player->pos.x += player->vel.x;

    if (player->pos.x > (player->pathWidth + player->xPath)) {
        player->pos.x = player->pathWidth + player->xPath;
        player->vel.x = 0.0f;
        player->knockback.x = 0.0f;
    }
    if (player->pos.x < (player->xPath - player->pathWidth)) {
        player->pos.x = player->xPath - player->pathWidth;
        player->vel.x = 0.0f;
        player->knockback.x = 0.0f;
    }

    player->pos.y += player->vel.y;

    if (player->pos.y > (player->pathHeight + player->yPath)) {
        player->pos.y = player->pathHeight + player->yPath;
        player->vel.y = 0.0f;
        player->knockback.y = 0.0f;
    }
    if (player->pos.y < (player->pathFloor + player->yPath)) {
        player->pos.y = player->pathFloor + player->yPath;
        player->vel.y = 0.0f;
        player->knockback.y = 0.0f;
    }

    player->pos.z += player->vel.z;

    Player_WingEffects(player);
}

// Landmaster

RECOMP_PATCH void func_tank_80045678(Player* player) {
    static u8 D_800C9F3C = 0;
    f32 temp;
    f32 pad;

    player->gravity = 3.0f;
    if (!(gInputHold->button & Z_TRIG)) {
        Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_TANK_GO_UP);
        Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_TANK_SLIDE);
    }
    if ((gInputHold->button & Z_TRIG) && !player->boostCooldown) {
        sTankActiveBurnerCount++;
        if (D_800C9F20 == 0.0f) {
            AUDIO_PLAY_SFX(NA_SE_TANK_BURNER_HALF, player->sfxSource, 0);
        }
        player->unk_188 = 0.0f;
        player->zRotBank += 4.0f;
        if (player->zRotBank > 50.0f) {
            player->zRotBank = 50.0f;
        }
        Math_SmoothStepToF(&player->unk_170, 1.0f, 1.0f, 0.4f, 0.0f);
        D_800C9F20 += 1.0f;
    } else {
        if (player->zRotBank > 0) {
            player->unk_188 += 1.5f;
            player->zRotBank -= player->unk_188;
            if (player->zRotBank <= 0.0f) {
                player->zRotBank = 0.0f;
                if (player->unk_188 > 3.0f) {
                    player->unk_188 *= -0.4f;
                    player->zRotBank -= player->unk_188;
                }
            }
        }
        D_800C9F20 = 0.0f;
    }
    if (!(gInputHold->button & R_TRIG)) {
        Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_TANK_GO_UP);
        Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_TANK_SLIDE);
    }
    if ((gInputHold->button & R_TRIG) && !player->boostCooldown) {
        sTankActiveBurnerCount++;
        if (player->unk_2C0 == 0.0f) {
            AUDIO_PLAY_SFX(NA_SE_TANK_BURNER_HALF, player->sfxSource, 0);
        }
        player->unk_188 = 0.0f;
        player->zRotBank -= 4.0f;
        if (player->zRotBank < -50.0f) {
            player->zRotBank = -50.0f;
        }
        Math_SmoothStepToF(&player->unk_16C, 1.0f, 1.0f, 0.4f, 0.0f);
        player->unk_2C0 += 1.0f;
    } else {
        if (player->zRotBank < 0.0f) {
            player->unk_188 += 1.5f;
            player->zRotBank += player->unk_188;
            if (player->zRotBank >= 0.0f) {
                player->zRotBank = 0.0f;
                if (player->unk_188 > 3.0f) {
                    player->unk_188 *= -0.4f;
                    player->zRotBank += player->unk_188;
                }
            }
        }
        player->unk_2C0 = 0.0f;
    }
    Math_SmoothStepToF(&player->boostSpeed, 0.0f, 0.1f, 1.0f, 0);
    if ((player->unk_16C > 0.2f) && (player->unk_170 > 0.2f) && (player->radioDamageTimer == 0)) {
        if (D_800C9F3C == 0) {
            D_800C9F3C = 1;
            Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_TANK_SLIDE);
            Audio_KillSfxBySourceAndId(player->sfxSource, NA_SE_TANK_BURNER_HALF);
            AUDIO_PLAY_SFX(NA_SE_TANK_GO_UP, player->sfxSource, 0);
        }
        player->zRotBank += ((__cosf(gGameFrameCount * M_DTOR * 8.0f) * 10.0f) - player->zRotBank) * 0.1f;
        temp = -gInputPress->stick_y * INVERT_Y_AXIS_COND_RES;
        Math_SmoothStepToF(&player->rot.x, temp * 0.3f, 0.05f, 5.0f, 0.00001f);
        Math_SmoothStepToF(&player->boostSpeed, 15.0f, 0.5f, 5.0f, 0.0f);
        Math_SmoothStepToF(&player->rot.z, 0.0f, 0.1f, 5.0f, 0.00001f);
        player->gravity = -0.4f;
        player->pathHeight += player->vel.y;

        if (player->pathHeight > 300.0f) {
            player->gravity = 0.0f;
            Math_SmoothStepToF(&player->vel.y, 0.0f, 0.1f, 2.0f, 0);
        }
        if ((gCamCount == 1) && ((gGameFrameCount % 2) == 0)) {
            Effect_Effect359_Spawn(RAND_FLOAT_CENTERED(20.0f) + player->pos.x, player->groundPos.y + 10.0f,
                                   player->trueZpos - 10.0f, RAND_FLOAT(2.0f) + 3.5f, 255, 16, 1);
        }
    } else {
        D_800C9F3C = 0;
        if ((gCamCount == 1) && ((gGameFrameCount % 4) == 0) && (player->rollState == 0)) {
            if ((player->unk_16C > 0.2f) && (player->radioDamageTimer == 0)) {
                Effect_Effect359_Spawn(RAND_FLOAT_CENTERED(10.0f) + (player->pos.x - 57.0f),
                                       player->groundPos.y + 10.0f, player->trueZpos - 10.0f, RAND_FLOAT(1.0f) + 1.5f,
                                       255, 15, 0);
            }
            if ((player->unk_170 > 0.2f) && (player->radioDamageTimer == 0)) {
                Effect_Effect359_Spawn(RAND_FLOAT_CENTERED(10.0f) + (player->pos.x + 57.0f),
                                       player->groundPos.y + 10.0f, player->trueZpos - 10.0f, RAND_FLOAT(1.0f) + 1.5f,
                                       255, 15, 0);
            }
        }
    }
}

// Inside effect_tagging
// RECOMP_PATCH void func_tank_80044868

// Blue Marine

RECOMP_PATCH void Aquas_UpdateCamera(Player* player) {
    f32 stickX = +gInputPress->stick_x;
    f32 stickY = -gInputPress->stick_y * INVERT_Y_AXIS_COND_RES;
    f32 zRot;

    if (player->state != PLAYERSTATE_ACTIVE) {
        stickX = stickY = 0.0f;
    }

    Math_SmoothStepToF(&player->unk_030, stickX, 0.05f, 1.0f, 0.05f);

    if (player->pos.y < (gGroundHeight + 50.0f)) {
        Math_SmoothStepToF(&player->unk_02C, stickY * 0.3f, 0.05f, 1.0f, 0.05f);
    } else {
        Math_SmoothStepToF(&player->unk_02C, stickY, 0.05f, 2.0f, 0.05f);
    }

    gCsCamEyeX = (player->pos.x - player->xPath) * (600.0f / player->pathWidth);
    gCsCamEyeX -= player->unk_030 * 1.5f;
    gCsCamEyeX += player->xPath + D_i3_801C41B8[9];

    gCsCamEyeY = player->pos.y * (740.0f / player->pathHeight);
    gCsCamEyeY -= player->unk_02C - 50.0f;
    gCsCamEyeY += player->yPath;

    gCsCamAtX = (player->pos.x - player->xPath - D_i3_801C41B8[9]) * (600.0f / player->pathWidth);
    gCsCamAtX += player->xShake * -2.0f;
    gCsCamAtX -= player->unk_030 * 0.5f;
    gCsCamAtX += player->xPath;

    gCsCamAtY = (player->pos.y - player->yPath) * (750.0f / player->pathHeight);
    gCsCamAtY += player->xRock * 10.0f;
    gCsCamAtY -= player->unk_02C * -0.55f;
    gCsCamAtY += player->yPath + D_i3_801C41B8[10];

    if (gCsCamAtY < 20.0f) {
        gCsCamAtY = 20.0f;
    }

    gCsCamEyeZ = 240.0f;
    gCsCamAtZ = player->trueZpos + (gPathProgress - 1.0f);

    Math_SmoothStepToF(&player->cam.eye.x, gCsCamEyeX, player->unk_014, 1000.0f, 0);
    Math_SmoothStepToF(&player->cam.eye.y, gCsCamEyeY, player->unk_014, 1000.0f, 0);
    Math_SmoothStepToF(&player->cam.eye.z, gCsCamEyeZ, 0.2f, 30.0f, 0.0f);

    Math_SmoothStepToF(&player->cam.at.x, gCsCamAtX, player->unk_014, 1000.0f, 0);
    Math_SmoothStepToF(&player->cam.at.y, gCsCamAtY, player->unk_014, 1000.0f, 0);
    Math_SmoothStepToF(&player->cam.at.z, gCsCamAtZ, player->unk_014, 1000.0f, 0);

    Math_SmoothStepToF(&player->unk_014, 1.0f, 1.0f, 0.05f, 0.0f);

    zRot = -player->rot.z;

    Math_SmoothStepToF(&player->camRoll, zRot * 0.3f, 0.1f, 1.5f, 0.0f);
}

RECOMP_PATCH void Aquas_BlueMarineMove(Player* player) {
    Vec3f sp8C;
    Vec3f sp80;
    Vec3f sp74;
    Vec3f sp68;
    f32 stickX;
    f32 sp60;
    f32 stickY;
    f32 sp58;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv1_2;
    s32 pad;

    Aquas_801AA4BC(player);
    Aquas_801A99D4(player);
    Aquas_801A8E30();

    stickX = -gInputPress->stick_x;
    stickY = +gInputPress->stick_y * INVERT_Y_AXIS_COND_RES;

    gPlayerTurnStickMod = 0.68f;

    Math_SmoothStepToF(&player->unk_180, stickX * gPlayerTurnStickMod, 1.0f, 10.0f, 0.0001f);

    var_fa0 = fabsf(player->unk_180 * 0.5f);
    if (var_fa0 > 2.0f) {
        var_fa0 = 2.0f;
    }

    if (player->unk_180 < 0.0f) {
        if (D_i3_801C41B8[3] > player->unk_180) {
            D_i3_801C41B8[3] -= var_fa0;
        }
    } else {
        if (D_i3_801C41B8[3] < player->unk_180) {
            D_i3_801C41B8[3] += var_fa0;
        }
    }

    Math_SmoothStepToF(&D_i3_801C41B8[3], player->unk_180, 0.1f, 2.0f, 0.00001f);

    sp60 = D_i3_801C41B8[3];
    gPlayerTurnRate = 7.0f;

    if ((player->pos.x < (-player->pathWidth + player->xPath + 10.0f)) && (sp60 >= 20.0f)) {
        gPlayerTurnRate = 2.0f;
        Math_SmoothStepToF(&D_i3_801C41B8[9], 30.0f, 0.1f, 10.0f, 0.0001f);
    }
    if ((player->pos.x > (player->pathWidth + player->xPath - 10.0f)) && (sp60 <= -20.0f)) {
        gPlayerTurnRate = 2.0f;
        Math_SmoothStepToF(&D_i3_801C41B8[9], -30.0f, 0.1f, 10.0f, 0.0001f);
    }

    Math_SmoothStepToF(&player->rot.y, sp60, 0.3f, gPlayerTurnRate, 0.00001f);

    if (gPlayerTurnRate != 2.0f) {
        Math_SmoothStepToF(&D_i3_801C41B8[9], 0.0f, 0.1f, 20.0f, 0.0001f);
    }

    Math_SmoothStepToF(&player->unk_17C, stickY * gPlayerTurnStickMod, 1.0f, 7.0f, 0.0001f);

    var_fa1 = fabsf(player->unk_17C * 0.05f);
    if (var_fa1 > 2.0f) {
        var_fa1 = 2.0f;
    }

    if (player->unk_17C * -1.0f < 0.0f) {
        if (D_i3_801C41B8[4] > player->unk_17C) {
            D_i3_801C41B8[4] -= var_fa1;
        }
    } else {
        if (D_i3_801C41B8[4] < player->unk_17C) {
            D_i3_801C41B8[4] += var_fa1;
        }
    }

    Math_SmoothStepToF(&D_i3_801C41B8[4], player->unk_17C * -1.0f, 0.1f, 3.0f, 0.00001f);

    sp58 = D_i3_801C41B8[4] * 0.8f;
    gPlayerTurnRate = 10.0f;

    if (player->pos.y < (gGroundHeight + 50.0f)) {
        if (sp58 <= 0.0f) {
            sp58 = 0.0f;
            gPlayerTurnRate = 2.0f;
            if (D_i3_801C4190[7] == 0) {
                AUDIO_PLAY_SFX(NA_SE_MAR_BOUND, player->sfxSource, 0);
                D_i3_801C4190[7] = 1;
            }
        }
    } else {
        D_i3_801C4190[7] = 0;
    }

    if ((player->pathHeight - 50.0f) <= player->pos.y) {
        if (sp58 >= 0.0f) {
            Math_SmoothStepToF(&D_i3_801C41B8[10], 30.0f, 1.0f, 1.0f, 0.00001f);
        }
    } else {
        Math_SmoothStepToF(&D_i3_801C41B8[10], 0.0f, 0.1f, 1.0f, 0.00001f);
    }

    Math_SmoothStepToF(&player->rot.x, sp58, 1.0f, gPlayerTurnRate, 0.00001f);

    var_fv1_2 = 2.0f;
    if (stickX == 0.0f) {
        var_fv1_2 = 1.0f;
    }

    Math_SmoothStepToF(&player->rot.z, player->unk_180 * 0.7f, 0.08f, var_fv1_2, 0.0001f);

    player->bankAngle = player->rot.z + player->zRotBank + player->zRotBarrelRoll;

    Matrix_RotateY(gCalcMatrix, (player->yRot_114 + player->rot.y + 180.0f) * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, -((player->xRot_120 + player->rot.x + player->aerobaticPitch) * M_DTOR), MTXF_APPLY);

    sp8C.x = sp8C.y = 0.0f;
    sp8C.z = player->baseSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp8C, &sp68);

    sp68.x *= 1.4f;
    sp68.y *= 1.4f;

    Matrix_RotateY(gCalcMatrix, player->yRot_114 * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, player->xRot_120 * M_DTOR, MTXF_APPLY);

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp68, &sp80);

    sp8C.x = sp8C.y = 0.0f;
    sp8C.z = -player->boostSpeed;

    Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp8C, &sp74);

    player->vel.x = (sp80.x + sp74.x) * player->unk_150;
    player->vel.y = (sp80.y + sp74.y) * player->unk_150;
    player->vel.z = sp80.z + sp74.z;

    player->pos.x += player->vel.x;

    if (player->pos.x > player->pathWidth + player->xPath) {
        player->pos.x = player->pathWidth + player->xPath;
        player->vel.x = 0.0f;
    }
    if (player->pos.x < player->xPath - player->pathWidth) {
        player->pos.x = player->xPath - player->pathWidth;
        player->vel.x = 0.0f;
    }

    player->pos.y += player->vel.y;

    if (player->pos.y > player->pathHeight) {
        player->pos.y = player->pathHeight;
        player->vel.y = 0.0f;
    }
    if (player->pos.y < player->pathFloor) {
        player->pos.y = player->pathFloor;
        player->vel.y = 0.0f;
    }

    if (player->pos.x > (player->xPath + (player->pathWidth - 100.0f))) {
        player->flags_228 = PFLAG_228_0;
    }
    if (player->pos.x < (player->xPath - (player->pathWidth - 100.0f))) {
        player->flags_228 = PFLAG_228_1;
    }
    if (player->pos.y > (player->yPath + (player->pathHeight - 100.0f))) {
        player->flags_228 = PFLAG_228_3;
    }
    if (player->pos.y <= (gGroundHeight + 100)) {
        player->flags_228 = PFLAG_228_2;
    }

    if (D_i3_801C4190[6] != 0) {
        player->baseSpeed = 20.0f;
        Math_SmoothStepToF(&D_i3_801BFB60, -40.0f, 0.01f, 0.1f, 0.0f);
        player->vel.z += D_i3_801BFB60;
        if (player->vel.z <= 0.0f) {
            player->vel.z = 0.0f;
        }
    }

    player->pos.z += player->vel.z;
    player->trueZpos = player->pos.z;
    player->xRock = SIN_DEG(player->rockPhase * 0.7f) * 0.5f;
    player->bobPhase += 10.0f;
    player->rockPhase += 8.0f + D_i3_801C41B8[24];
    player->yBob = -SIN_DEG(player->bobPhase) * 0.5f;
    player->rockAngle = SIN_DEG(player->rockPhase) * 1.5f;

    if (player->pos.y < (gWaterLevel + 50.0f)) {
        Matrix_RotateY(gCalcMatrix, (player->rot.y + player->yRot_114) * M_DTOR, MTXF_NEW);
        Matrix_RotateX(gCalcMatrix, player->rot.x * M_DTOR, MTXF_APPLY);

        sp8C.x = sp8C.y = 0.0f;
        sp8C.z = 70.0f;

        Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp8C, &sp80);

        if (player->boostSpeed > 1.0f) {
            player->unk_178 -= 30.0f;
            Aquas_Bubble_Spawn(player->pos.x + RAND_FLOAT_CENTERED(10.0f) + sp80.x,
                               player->pos.y + RAND_FLOAT_CENTERED(10.0f) + sp80.y,
                               player->trueZpos + RAND_FLOAT_CENTERED(10.0f) + (sp80.z * -1.0f), 0.4f, 1);
        } else {
            player->unk_178 -= 10.0f;
            if ((gGameFrameCount % 8) == 0) {
                Aquas_Bubble_Spawn(player->pos.x + RAND_FLOAT_CENTERED(10.0f) + sp80.x,
                                   player->pos.y + RAND_FLOAT_CENTERED(10.0f) + sp80.y,
                                   player->trueZpos + RAND_FLOAT_CENTERED(20.0f) + sp80.z, 0.4f, 0);
            }
        }
    }
}