#include "patches.h"

// Debug Bosses
#if 0
extern ObjectInit aMeWarpZoneLevelObjects[];
extern ObjectInit aSxWarpZoneLevelObjects[];
extern ObjectInit aVe1AndBossLevelObjects[];
extern ObjectInit aVe1BetaLevelObjects[];

    ObjectInit aSxLevelObjects_Boss[] = { { 100.0f, 4000, 0, 1103, { 0, 0, 0 }, OBJ_BOSS_SX_SPYBORG } };
    ObjectInit aTiLevelObjects_Boss[] = { { 300.0f, -1000, 0, 0, { 0, 0, 0 }, OBJ_BOSS_TI_GORAS } };
    ObjectInit bossaqInit[] = { { 100.6f, -4035, 0, 0, { 0, 0, 0 }, OBJ_BOSS_AQ_BACOON } };
    ObjectInit aSoLevelObjects_Boss[] = { { 100.0f, 0, 0, 0, { 0, 0, 0 }, OBJ_BOSS_SO_VULKAIN } };
    ObjectInit aA6LevelObjects_Boss[] = { { 100.0f, -10000, 0, 0, { 0, 0, 0 }, OBJ_BOSS_A6_GORGON } };

void func_enmy_80061A4C(void);

RECOMP_PATCH void Object_LoadLevelObjects(void) {
    ObjectInit* objInit;
    f32 xMax;
    f32 xMin;
    f32 yMax;
    f32 yMin;
    s32 i;
    s32 j;

    if ((gCurrentLevel == LEVEL_METEO) && (gLevelPhase == 1)) {
        gLevelObjects = SEGMENTED_TO_VIRTUAL(aMeWarpZoneLevelObjects);
    } else if ((gCurrentLevel == LEVEL_SECTOR_X) && (gLevelPhase == 1)) {
        gLevelObjects = SEGMENTED_TO_VIRTUAL(aSxWarpZoneLevelObjects);
    } else if ((gCurrentLevel == LEVEL_VENOM_ANDROSS) && (gLevelPhase == 1)) {
        gLevelObjects = SEGMENTED_TO_VIRTUAL(aVe1AndBossLevelObjects);
    } else if ((gCurrentLevel == LEVEL_VENOM_1) && (gLevelPhase == 1)) {
        gLevelObjects = SEGMENTED_TO_VIRTUAL(aVe1BetaLevelObjects);
    } else {
        gLevelObjects = SEGMENTED_TO_VIRTUAL(gLevelObjectInits[gCurrentLevel]);
    }

    if (gGroundClipMode == 0) {
        for (j = 0; j < gDrawSmallRocks; j++) {
            if (gCurrentLevel == LEVEL_AQUAS) {
                func_enmy_80061B68();
            } else {
                func_enmy_80061A4C();
            }
        }
    }

    if (gCurrentLevel == LEVEL_METEO) {
        yMax = xMax = 10000.0f;
        yMin = xMin = -10000.0f;
    } else if (gCurrentLevel == LEVEL_SECTOR_Y) {
        yMax = xMax = 6000.0f;
        yMin = xMin = -6000.0f;
    } else if (gCurrentLevel == LEVEL_VENOM_1) {
        yMax = xMax = 3500.0f;
        yMin = xMin = -3500.0f;
    } else {
        yMax = xMax = 4000.0f;
        yMin = xMin = -4000.0f;
    }

    if ((gPlayer[0].pathChangeTimer != 0) && (gPlayer[0].pathChangeYaw < 0.0f)) {
        xMax = 10000.0f;
    }
    if ((gPlayer[0].pathChangeTimer != 0) && (gPlayer[0].pathChangeYaw > 0.0f)) {
        xMin = -10000.0f;
    }

    gLastPathChange = 0;

gLevelObjects[0].id = OBJ_BOSS_SX_SPYBORG;
// Level Boss Tester
#if 0
    switch (gCurrentLevel) {
        case LEVEL_AQUAS:
            gLevelObjects = bossaqInit;
            break;

        case LEVEL_TITANIA:
            gLevelObjects = aTiLevelObjects_Boss;
            break;

        case LEVEL_SECTOR_X:
        gLevelObjects[0].id = OBJ_BOSS_SX_SPYBORG;

            // gLevelObjects = aSxLevelObjects_Boss;
            break;

        case LEVEL_SOLAR:
            gLevelObjects = aSoLevelObjects_Boss;
            break;
        case LEVEL_AREA_6:
            gLevelObjects = aA6LevelObjects_Boss;
            break;
    }
#endif

    for (i = 0, objInit = &gLevelObjects[gObjectLoadIndex]; i < 10000; i++, gObjectLoadIndex++, objInit++) {
        if (objInit->id <= OBJ_INVALID) {
            break;
        }
        if ((gPathProgress <= objInit->zPos1) && (objInit->zPos1 <= gPathProgress + 200.0f)) {
            if ((gCurrentLevel == LEVEL_VENOM_1) && (objInit->id >= ACTOR_EVENT_ID)) {
                if (((objInit->rot.y < 180.0f) && (objInit->xPos < gPlayer[0].xPath)) ||
                    ((objInit->rot.y > 180.0f) && (gPlayer[0].xPath < objInit->xPos))) {
                    Object_Load(objInit, xMax, xMin, yMax, yMin);
                }
            } else {
                Object_Load(objInit, xMax, xMin, yMax, yMin);
            }
        } else {
            break;
        }
    }
}
#endif

// Area6_A6Gorgon_Update
#if 0

typedef enum {
    /*  0 */ A6_SWK_0,
    /*  1 */ A6_SWK_1,
    /*  2 */ A6_SWK_2,
    /*  3 */ A6_SWK_3,
    /*  4 */ A6_SWK_4,
    /*  5 */ A6_SWK_5,
    /*  6 */ A6_SWK_6,
    /*  7 */ A6_SWK_7,
    /*  8 */ A6_SWK_8,
    /*  9 */ A6_SWK_9,
    /* 10 */ A6_SWK_10,
    /* 11 */ A6_SWK_11,
    /* 12 */ A6_SWK_12,
    /* 13 */ A6_SWK_13,
    /* 14 */ A6_SWK_14,
    /* 15 */ A6_SWK_15,
    /* 16 */ A6_SWK_16,
    /* 17 */ A6_SWK_17,
    /* 18 */ A6_SWK_18,
    /* 19 */ A6_SWK_19,
    /* 20 */ A6_SWK_20,
    /* 21 */ A6_SWK_21,
    /* 22 */ A6_SWK_22,
    /* 23 */ A6_SWK_23,
    /* 24 */ A6_SWK_24,
    /* 25 */ A6_SWK_25,
    /* 26 */ A6_SWK_26,
    /* 27 */ A6_SWK_27,
    /* 28 */ A6_SWK_28,
    /* 29 */ A6_SWK_29,
    /* 30 */ A6_SWK_30,
    /* 31 */ A6_SWK_31,
    /* 32 */ A6_SWK_32,
    /* 33 */ A6_SWK_33,
    /* 34 */ A6_SWK_34,
    /* 35 */ A6_SWK_35,
    /* 36 */ A6_SWK_36,
    /* 37 */ A6_SWK_37,
    /* 38 */ A6_SWK_38,
    /* 39 */ A6_SWK_39,
    /* 40 */ A6_SWK_MAX,
} A6Gorgonswork;

typedef enum {
    /*  0 */ A6_FWK_0,
    /*  1 */ A6_FWK_1,
    /*  2 */ A6_FWK_2,
    /*  3 */ A6_FWK_3,
    /*  4 */ A6_FWK_4,
    /*  5 */ A6_FWK_5,
    /*  6 */ A6_FWK_6,
    /*  7 */ A6_FWK_7,
    /*  8 */ A6_FWK_8,
    /*  9 */ A6_FWK_9,
    /* 10 */ A6_FWK_10,
    /* 11 */ A6_FWK_11,
    /* 12 */ A6_FWK_12,
    /* 13 */ A6_FWK_13,
    /* 14 */ A6_FWK_14,
    /* 15 */ A6_FWK_15,
    /* 16 */ A6_FWK_16,
    /* 17 */ A6_FWK_17,
    /* 18 */ A6_FWK_18,
    /* 19 */ A6_FWK_19,
    /* 20 */ A6_FWK_20,
    /* 21 */ A6_FWK_21,
    /* 22 */ A6_FWK_22,
    /* 23 */ A6_FWK_23,
    /* 24 */ A6_FWK_24,
    /* 25 */ A6_FWK_25,
    /* 26 */ A6_FWK_26,
    /* 27 */ A6_FWK_27,
    /* 28 */ A6_FWK_28,
    /* 29 */ A6_FWK_29,
    /* 30 */ A6_FWK_30,
    /* 31 */ A6_FWK_31,
    /* 32 */ A6_FWK_32,
    /* 33 */ A6_FWK_33,
    /* 34 */ A6_FWK_34,
    /* 35 */ A6_FWK_35,
    /* 36 */ A6_FWK_36,
    /* 37 */ A6_FWK_37,
    /* 38 */ A6_FWK_38,
    /* 39 */ A6_FWK_39,
    /* 40 */ A6_FWK_40,
    /* 41 */ A6_FWK_41,
    /* 42 */ A6_FWK_42,
    /* 43 */ A6_FWK_43,
    /* 44 */ A6_FWK_44,
    /* 45 */ A6_FWK_45,
    /* 46 */ A6_FWK_46,
    /* 47 */ A6_FWK_47,
    /* 48 */ A6_FWK_48,
    /* 49 */ A6_FWK_49,
    /* 50 */ A6_FWK_MAX,
} A6Gorgonfwork;

typedef enum {
    /*  0 */ A6_VWK_0,
    /*  1 */ A6_VWK_1,
    /*  2 */ A6_VWK_2,
    /*  3 */ A6_VWK_3,
    /*  4 */ A6_VWK_4,
    /*  5 */ A6_VWK_5,
    /*  6 */ A6_VWK_6,
    /*  7 */ A6_VWK_7,
    /*  8 */ A6_VWK_8,
    /*  9 */ A6_VWK_9,
    /* 10 */ A6_VWK_10,
    /* 11 */ A6_VWK_11,
    /* 12 */ A6_VWK_12,
    /* 13 */ A6_VWK_13,
    /* 14 */ A6_VWK_14,
    /* 15 */ A6_VWK_15,
    /* 16 */ A6_VWK_16,
    /* 17 */ A6_VWK_17,
    /* 18 */ A6_VWK_18,
    /* 19 */ A6_VWK_19,
    /* 20 */ A6_VWK_20,
    /* 21 */ A6_VWK_21,
    /* 22 */ A6_VWK_22,
    /* 23 */ A6_VWK_23,
    /* 24 */ A6_VWK_24,
    /* 25 */ A6_VWK_25,
    /* 26 */ A6_VWK_26,
    /* 27 */ A6_VWK_27,
    /* 28 */ A6_VWK_28,
    /* 29 */ A6_VWK_29,
    /* 30 */ A6_VWK_30,
    /* 31 */ A6_VWK_31,
    /* 32 */ A6_VWK_32,
    /* 33 */ A6_VWK_33,
    /* 34 */ A6_VWK_34,
    /* 35 */ A6_VWK_35,
    /* 36 */ A6_VWK_36,
    /* 37 */ A6_VWK_37,
    /* 38 */ A6_VWK_38,
    /* 39 */ A6_VWK_39,
    /* 40 */ A6_VWK_40,
    /* 41 */ A6_VWK_41,
    /* 42 */ A6_VWK_42,
    /* 43 */ A6_VWK_43,
    /* 44 */ A6_VWK_44,
    /* 45 */ A6_VWK_45,
    /* 46 */ A6_VWK_46,
    /* 47 */ A6_VWK_47,
    /* 48 */ A6_VWK_48,
    /* 49 */ A6_VWK_49,
    /* 50 */ A6_VWK_MAX,
} A6Gorgonvwork;

typedef enum {
    /*  0 */ A6_BSS_0,
    /*  1 */ A6_BSS_1,
    /*  2 */ A6_BSS_2_0,
    /*  3 */ A6_BSS_2_1,
    /*  4 */ A6_BSS_2_2,
    /*  5 */ A6_BSS_5,
    /*  6 */ A6_BSS_6,
    /*  7 */ A6_BSS_7,
    /*  8 */ A6_BSS_8,
    /*  9 */ A6_BSS_9,
    /* 10 */ A6_BSS_10,
    /* 11 */ A6_BSS_11,
    /* 12 */ A6_BSS_12_0,
    /* 13 */ A6_BSS_12_1,
    /* 14 */ A6_BSS_12_2,
    /* 15 */ A6_BSS_15,
    /* 16 */ A6_BSS_16,
    /* 17 */ A6_BSS_17,
    /* 18 */ A6_BSS_18,
    /* 19 */ A6_BSS_19,
    /* 20 */ A6_BSS_20,
    /* 21 */ A6_BSS_21,
    /* 22 */ A6_BSS_22,
    /* 23 */ A6_BSS_23,
    /* 24 */ A6_BSS_24,
    /* 25 */ A6_BSS_25,
    /* 26 */ A6_BSS_26,
    /* 27 */ A6_BSS_27,
    /* 28 */ A6_BSS_28,
    /* 29 */ A6_BSS_29,
    /* 30 */ A6_BSS_30,
    /* 31 */ A6_BSS_31,
    /* 32 */ A6_BSS_32,
    /* 33 */ A6_BSS_33,
    /* 34 */ A6_BSS_34,
    /* 35 */ A6_BSS_35,
    /* 36 */ A6_BSS_36,
    /* 37 */ A6_BSS_37,
    /* 38 */ A6_BSS_38,
    /* 39 */ A6_BSS_39,
    /* 40 */ A6_BSS_MAX,
} A6Gorgonbsswork;
extern Vec3f D_i3_801BECE0;
extern Vec3f D_i3_801BECEC;
extern Vec3f D_i3_801BECF8;
extern Vec3f D_i3_801BED04;
extern Vec3f D_i3_801BED10;
extern Vec3f D_i3_801BED1C;
extern Vec3f D_i3_801BED28;
extern Vec3f D_i3_801BED34;
extern s32 D_i3_801C2250[A6_BSS_MAX];

typedef struct {
    /* 0x00 */ f32 r[3];
    /* 0x0C */ f32 g[3];
    /* 0x18 */ f32 b[3];
    /* 0x24 */ f32 unk_24;
    /* 0x30 */ f32 unk_28[3];
    /* 0x3C */ f32 unk_34;
} UnkStruct_1C22F0;

extern UnkStruct_1C22F0 D_i3_801C22F0;
extern f32 D_i3_801BECB0[4][3];

#define A6_HITBOX_COUNT ((s32) (bossA6)->info.hitbox[0])
#define A6_HIT_0(bossA6) ((Hitbox*) ((bossA6)->info.hitbox + 1))
#define A6_HIT_1(bossA6, index) ((Hitbox*) ((f32*) (A6_HIT_0(bossA6) + 1) + 6 * (index)))
#define A6_HIT_1_2(bossA6, index) ((Hitbox*) (A6_HIT_0(bossA6) + 1 + (index)))
#define A6_HIT_4(bossA6, index) ((Hitbox*) ((f32*) (A6_HIT_1(bossA6, 0) + 3) + 6 * (index)))

#define A6_HIT_7_1(bossA6, index) ((TiltHitbox*) ((f32*) (A6_HIT_4(bossA6, 0) + 3) + 10 * (index)))

#define A6_HIT_7_2(bossA6) ((Hitbox*) (A6_HIT_4(bossA6, 0) + 3))
#define A6_HIT_8_2(bossA6, index) ((TiltHitbox*) ((f32*) (A6_HIT_7_2(bossA6) + 1) + 10 * (index)))
#define A6_HIT_11_2(bossA6, index) ((TiltHitbox*) ((f32*) (A6_HIT_8_2(bossA6) + 3) + 10 * (index)))
#define A6_HIT_14_2(bossA6) ((TiltHitbox*) (A6_HIT_11_2(bossA6) + 3))
extern f32 D_A6_6028578[];
extern f32 aA6GorgonHitbox[];
extern f32 D_i3_801BF454[16];
extern f32 D_i3_801BF1F0[12];
extern f32 D_i3_801BF280[12];
extern f32 D_i3_801BF2B0[12];
extern f32 D_i3_801BF220[12];
extern f32 D_i3_801BF2E0[12];
extern f32 D_i3_801BF250[12];
void Area6_8018B9BC(A6Gorgon* this);
void Area6_8018A2C4(A6Gorgon* this);
void Area6_8018A1B0(A6Gorgon* this, s32 arg1);
void Area6_8018A464(A6Gorgon* this, s32 arg1);
void Area6_ActorMissileSeekPlayer_Spawn(f32 xPos, f32 yPos, f32 zPos, f32 fwork6, f32 xRot, f32 yRot, s32 timer0BC,
                                        s32 unk0B4);
void Area6_Effect395_Spawn(void);

RECOMP_PATCH void Area6_A6Gorgon_Update(A6Gorgon* this) {
    s32 i;
    s32 pad;
    s32 var_s0;
    s32 sp128;
    s32 spf124;
    f32 sp120;
    f32 dx_11C;
    f32 dy_118;
    f32 dz_114;
    f32 pitch_110;
    f32 yaw_10C;
    f32 temp2;
    f32 sp104;
    Vec3f spC8[8];
    Vec3f sp98;
    Vec3f sp8C;
    Effect* effect;

    gBossFrameCount++;

    if ((this->state < 6) || ((this->state >= 8) && (this->state < 12))) {
        this->obj.rot.y = RAD_TO_DEG(Math_Atan2F(gPlayer[0].cam.eye.x - this->obj.pos.x,
                                                 gPlayer[0].cam.eye.z - (this->obj.pos.z + gPathProgress)));
        this->obj.rot.x = RAD_TO_DEG(-Math_Atan2F(gPlayer[0].cam.eye.y - this->obj.pos.y,
                                                  sqrtf(SQ(gPlayer[0].cam.eye.z - (this->obj.pos.z + gPathProgress)) +
                                                        SQ(gPlayer[0].cam.eye.x - this->obj.pos.x))));
    }

    Matrix_RotateY(gCalcMatrix, this->obj.rot.y * M_DTOR, MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, this->obj.rot.x * M_DTOR, MTXF_APPLY);
    Matrix_RotateZ(gCalcMatrix, this->obj.rot.z * M_DTOR, MTXF_APPLY);

    if ((this->dmgType != DMG_NONE) && (this->health > 0)) {
        this->dmgType = DMG_NONE;

        if (this->fwork[A6_FWK_0] > 5.0f) {
            if ((this->dmgPart == 0) && (this->swork[A6_SWK_25] == 0) && (this->fwork[A6_FWK_29] < 30.0f)) {
                this->timer_05C = 15;
                this->health -= this->damage;

                if (this->health < 390) {
                    AUDIO_PLAY_SFX(NA_SE_EN_KNOCK_DOWN, this->sfxSource, 4);
                } else {
                    AUDIO_PLAY_SFX(NA_SE_OB_DAMAGE_M, this->sfxSource, 4);
                }

                if (this->health <= 0) {
                    this->health = 0;
                    Boss_AwardBonus(this);
                    Radio_PlayMessage(gMsg_ID_15252, RCID_SLIPPY);

                    gTeamLowHealthMsgTimer = -1;

                    gArea6BackdropScale = (gPathProgress * 0.00004f) + 0.5f;

                    AUDIO_PLAY_SFX(NA_SE_EN_DOWN_IMPACT, this->sfxSource, 4);

                    gShowBossHealth = false;

                    SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 40);
                    SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 40);

                    this->fwork[A6_FWK_5] = 5.0f;
                    this->fwork[A6_FWK_3] = -20000.0f;
                    this->fwork[A6_FWK_1] = 170.0f;
                    this->vel.z = -20.0f;

                    Matrix_MultVec3f(gCalcMatrix, &D_i3_801BECE0, &spC8[0]);
                    Matrix_MultVec3f(gCalcMatrix, &D_i3_801BECEC, &spC8[1]);
                    Matrix_MultVec3f(gCalcMatrix, &D_i3_801BECF8, &spC8[2]);

                    for (i = 0; i < 3; i++) {
                        Effect_FireSmoke1_Spawn4(spC8[i].x + this->obj.pos.x, spC8[i].y + this->obj.pos.y,
                                                 spC8[i].z + this->obj.pos.z, 10.0f);
                    }

                    this->timer_052 = 170;

                    D_i3_801C2250[A6_BSS_2_0] = D_i3_801C2250[A6_BSS_2_1] = D_i3_801C2250[A6_BSS_2_2] =
                        this->swork[A6_SWK_33 + 0] = this->swork[A6_SWK_33 + 1] = this->swork[A6_SWK_33 + 2] = 0;

                    gScreenFlashTimer = 4;

                    this->state = 11;

                    AUDIO_PLAY_SFX(NA_SE_EN_EXPLOSION_L, this->sfxSource, 4);
                    AUDIO_PLAY_SFX(NA_SE_EXPLOSION_DEMO5, this->sfxSource, 4);
                }
            }

            if (((this->dmgPart == 4) || (this->dmgPart == 5) || (this->dmgPart == 6)) &&
                (this->swork[A6_SWK_25] != 0)) {
                Area6_8018B9BC(this);
            }
        }

        if ((this->dmgPart == 1) || (this->dmgPart == 2) || (this->dmgPart == 3)) {
            Area6_8018A2C4(this);
        }
        if (this->dmgPart >= 7) {
            AUDIO_PLAY_SFX(NA_SE_EN_REFLECT, this->sfxSource, 4);
        }
    }

    for (i = 0; i < 3; i++) {
        var_s0 = (this->swork[A6_SWK_15 + i] / 10) - 1;
        if (var_s0 < 0) {
            var_s0 = 0;
        }
        Math_SmoothStepToF(&D_i3_801C22F0.r[i], D_i3_801BECB0[var_s0][0], 1.0f, 10.0f, 0);
        Math_SmoothStepToF(&D_i3_801C22F0.g[i], D_i3_801BECB0[var_s0][1], 1.0f, 10.0f, 0);
        Math_SmoothStepToF(&D_i3_801C22F0.b[i], D_i3_801BECB0[var_s0][2], 1.0f, 10.0f, 0);
    }

    if ((this->swork[A6_SWK_15 + 0] == 0) && (this->swork[A6_SWK_15 + 1] == 0) && (this->swork[A6_SWK_15 + 2] == 0) &&
        (this->fwork[A6_FWK_0] != 0) && !(gGameFrameCount % 2U)) {
        Effect_Effect390_Spawn(this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + 200.0f, this->vel.x, this->vel.y,
                               this->vel.z, 0.3f, 1);
    }

    sp120 = 0.5f;
    if (gBosses[0].swork[A6_SWK_25] == 1) {
        sp120 = 2.0f;
    }

    if (D_i3_801C2250[A6_BSS_10] != 0) {
        D_i3_801C22F0.unk_34 += sp120;
        if (D_i3_801C22F0.unk_34 > 360.0f) {
            D_i3_801C22F0.unk_34 -= 360.0f;
        }
    } else {
        D_i3_801C22F0.unk_34 -= sp120;
        if (D_i3_801C22F0.unk_34 < 0.0f) {
            D_i3_801C22F0.unk_34 += 360.0f;
        }
    }

    if ((this->state >= 3) && (this->state < 5) && (this->fwork[A6_FWK_28] == 0.0f)) {
        Math_SmoothStepToAngle(&this->fwork[A6_FWK_9], this->fwork[A6_FWK_32], 0.05f, 0.02f, 0.00001f);
        Math_SmoothStepToAngle(&this->obj.rot.z, this->fwork[A6_FWK_8], 0.05f, this->fwork[A6_FWK_9], 0.00001f);
        if (this->swork[A6_SWK_25] >= 2) {
            if (!(gGameFrameCount % 64U) && (Rand_ZeroOne() < 0.5f)) {
                this->fwork[A6_FWK_6] = RAND_FLOAT_CENTERED(500.0f) + gPlayer[0].cam.eye.x;
            }
            if (!(gGameFrameCount % 64U) && (Rand_ZeroOne() < 0.5f)) {
                this->fwork[A6_FWK_7] = RAND_FLOAT_CENTERED(500.0f) + gPlayer[0].cam.eye.y;
            }
        } else {
            if (!(gGameFrameCount % 32U) && (Rand_ZeroOne() < 0.7f)) {
                this->fwork[A6_FWK_6] = RAND_FLOAT_CENTERED(1000.0f) + gPlayer[0].cam.eye.x;
                this->fwork[A6_FWK_30] = 0.0f;
            }
            if (!(gGameFrameCount % 32U) && (Rand_ZeroOne() < 0.7f)) {
                this->fwork[A6_FWK_7] = RAND_FLOAT_CENTERED(1000.0f) + gPlayer[0].cam.eye.y;
                this->fwork[A6_FWK_31] = 0.0f;
            }
        }
    }

    if (this->state != 0) {
        Math_SmoothStepToF(&this->fwork[A6_FWK_4], this->fwork[A6_FWK_5], 0.1f, 2.0f, 0.00001f);
        Math_SmoothStepToF(&this->obj.pos.z, gPlayer[0].cam.eye.z - gPathProgress + this->fwork[A6_FWK_3], 0.1f,
                           this->fwork[A6_FWK_4], 0.00001f);
        if (this->state < 5) {
            sp120 = 2.0f;
            if (this->swork[A6_SWK_25] == 1) {
                sp120 = 50.0f;
            }
            Math_SmoothStepToF(&this->fwork[A6_FWK_30], sp120, 0.1f, 1.0f, 0.00001f);
            Math_SmoothStepToF(&this->fwork[A6_FWK_31], sp120, 0.1f, 1.0f, 0.00001f);
            Math_SmoothStepToF(&this->obj.pos.x, this->fwork[A6_FWK_6], 0.2f, this->fwork[A6_FWK_30], 0.00001f);
            Math_SmoothStepToF(&this->obj.pos.y, this->fwork[A6_FWK_7], 0.2f, this->fwork[A6_FWK_31], 0.00001f);
        }
        Math_SmoothStepToAngle(&this->fwork[A6_FWK_0], this->fwork[A6_FWK_1], 0.2f, this->fwork[A6_FWK_2], 0.00001f);
    }

    Math_SmoothStepToF(&this->fwork[A6_FWK_10 + 0], this->fwork[A6_FWK_13 + 0], 0.1f, this->fwork[A6_FWK_16 + 0],
                       0.0001f);
    Math_SmoothStepToF(&this->fwork[A6_FWK_10 + 1], this->fwork[A6_FWK_13 + 1], 0.1f, this->fwork[A6_FWK_16 + 1],
                       0.0001f);
    Math_SmoothStepToF(&this->fwork[A6_FWK_10 + 2], this->fwork[A6_FWK_13 + 2], 0.1f, this->fwork[A6_FWK_16 + 2],
                       0.0001f);
    Math_SmoothStepToF(&this->fwork[A6_FWK_19 + 0], this->fwork[A6_FWK_22 + 0], 0.1f, 10.0f, 0.00001f);
    Math_SmoothStepToF(&this->fwork[A6_FWK_19 + 1], this->fwork[A6_FWK_22 + 1], 0.1f, 10.0f, 0.00001f);
    Math_SmoothStepToF(&this->fwork[A6_FWK_19 + 2], this->fwork[A6_FWK_22 + 2], 0.1f, 10.0f, 0.00001f);

    if (this->state > 10) {
        this->obj.rot.z += this->fwork[A6_FWK_28];
        this->obj.rot.z = Math_ModF(this->obj.rot.z, 360.0f);

        Math_SmoothStepToF(&this->fwork[A6_FWK_28], 5.0f, 0.1f, 0.2f, 0.0001f);

        for (i = 0; i < 10; i++) {
            func_effect_80079618(this->obj.pos.x + RAND_FLOAT_CENTERED(500.0f),
                                 this->obj.pos.y + RAND_FLOAT_CENTERED(500.0f),
                                 this->obj.pos.z + RAND_FLOAT_CENTERED(100.0f), RAND_FLOAT(4.0f) + 1.0f);
        }

        if (this->timer_05C == 0) {
            this->timer_05C = 15;
        }
        if (((gGameFrameCount % 2) == 0)) {
            Matrix_MultVec3f(gCalcMatrix, &D_i3_801BED04, &spC8[3]);
            Matrix_MultVec3f(gCalcMatrix, &D_i3_801BED10, &spC8[4]);
            Matrix_MultVec3f(gCalcMatrix, &D_i3_801BED1C, &spC8[5]);
            Matrix_MultVec3f(gCalcMatrix, &D_i3_801BED28, &spC8[6]);
            Matrix_MultVec3f(gCalcMatrix, &D_i3_801BED34, &spC8[7]);

            for (i = 3; i < 8; i++) {
                var_s0 = RAND_FLOAT_CENTERED(300.0f);
                if (i == 3) {
                    var_s0 = RAND_FLOAT_CENTERED(100.0f);
                }
                Effect_FireSmoke1_Spawn4(this->obj.pos.x + var_s0 + spC8[i].x, this->obj.pos.y + var_s0 + spC8[i].y,
                                         this->obj.pos.z + spC8[i].z, 10.0f);
            }
        }

        if (!(gGameFrameCount % 32U)) {
            Effect_Effect390_Spawn(this->obj.pos.x, this->obj.pos.y, this->obj.pos.z + 300.0f, this->vel.x, this->vel.y,
                                   this->vel.z, 0.5f, 70);
        }
    }

    if ((gGameFrameCount % 16U) == 0) {
        dz_114 = fabsf(this->fwork[A6_FWK_3] / -1700.0f);
        if (dz_114 < 1.0f) {
            dz_114 = 1.0f;
        }
        if (dz_114 > 3.0f) {
            dz_114 = 3.0f;
        }

        for (i = 0; i < 3; i++) {
            sp120 = dz_114;
            if (this->swork[A6_SWK_18 + i] != 0) {
                sp120 = 1.0f;
            }
            A6_HIT_1_2(this, i)->z.size = 195.0f * sp120;
            A6_HIT_1_2(this, i)->y.size = 147.0f * sp120;
            A6_HIT_1_2(this, i)->x.size = 153.0f * sp120;
        }
    }

    switch (this->state) {
        case 0:
            this->info.hitbox[0] = 0;

            dx_11C = gPlayer[0].pos.x - this->obj.pos.x;
            dy_118 = gPlayer[0].pos.y - this->obj.pos.y;
            dz_114 = gPlayer[0].pos.z - 700.0f - this->obj.pos.z;

            sp104 = 10.0f;

            if ((this->timer_050 != 0) && (this->timer_050 < 200)) {
                dx_11C = gPlayer[0].cam.eye.x - this->obj.pos.x;
                dy_118 = gPlayer[0].cam.eye.y - this->obj.pos.y;
                dz_114 = gPlayer[0].cam.eye.z - gPathProgress + this->fwork[A6_FWK_3] - this->obj.pos.z;
                sp104 = 100.0f;
            }

            yaw_10C = Math_Atan2F(dx_11C, dz_114);
            yaw_10C = Math_RadToDeg(yaw_10C);

            pitch_110 = Math_Atan2F(dy_118, sqrtf(SQ(dx_11C) + SQ(dz_114)));
            pitch_110 = Math_RadToDeg(-pitch_110);

            Math_SmoothStepToAngle(&this->orient.y, yaw_10C, 1.0f, sp104, 0.00001f);
            Math_SmoothStepToAngle(&this->orient.x, pitch_110, 1.0f, sp104, 0.00001f);
            Matrix_RotateY(gCalcMatrix, this->orient.y * M_DTOR, MTXF_NEW);
            Matrix_RotateX(gCalcMatrix, this->orient.x * M_DTOR, MTXF_APPLY);

            sp98.x = sp98.y = 0.0f;
            sp98.z = 30.0f;

            Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp98, &sp8C);

            this->vel.x = sp8C.x;
            this->vel.y = sp8C.y;

            sp98.x = sp98.y = 0.0f;
            sp98.z = 60.0f;

            Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp98, &sp8C);

            this->vel.z = sp8C.z;
            this->fwork[A6_FWK_33] += 30.0f;

            if (this->timer_050 == 0) {
                Math_SmoothStepToF(&D_i3_801C22F0.unk_24, 0.0f, 0.1f, 1.0f, 0);
                if (D_i3_801C22F0.unk_24 < 1.0f) {
                    D_i3_801C22F0.unk_24 = 0.0f;

                    Audio_KillSfxBySource(this->sfxSource);

                    AUDIO_PLAY_SFX(NA_SE_EN_SHIELD_ROLL_STOP, this->sfxSource, 4);

                    this->timer_050 = 20;
                    this->obj.pos.z = gPlayer[0].cam.eye.z - gPathProgress + this->fwork[A6_FWK_3];
                    this->fwork[A6_FWK_6] = this->obj.pos.x = gPlayer[0].cam.eye.x;
                    this->fwork[A6_FWK_7] = this->obj.pos.y = gPlayer[0].cam.eye.y;
                    this->state = 2;
                    this->vel.x = 0.0f;
                    this->vel.y = 0.0f;
                    this->vel.z = -40.0f;

                    AUDIO_PLAY_SFX(NA_SE_EN_WARP_OUT, this->sfxSource, 4);
                }
            }
            break;

        case 1:
            Math_SmoothStepToF(D_ctx_801779A8, 10.0f, 1.0f, 5.0f, 0.0f);
            this->info.hitbox[0] = 0;
            Math_SmoothStepToAngle(&this->obj.rot.z, 0.0f, 1.0f, 10.0f, 0.0001f);

            if (this->obj.rot.z < 1.0f) {
                if (D_i3_801C2250[A6_BSS_27] == 0) {
                    AUDIO_PLAY_SFX(NA_SE_EN_WARP_IN, this->sfxSource, 4);
                    D_i3_801C2250[A6_BSS_27] = 1;
                }
                this->obj.rot.z = 0.0f;
                Math_SmoothStepToF(&D_i3_801C22F0.unk_24, 0.0f, 0.1f, 5.0f, 0.0f);
                Math_SmoothStepToF(&this->fwork[A6_FWK_34], 2.0f, 0.1f, 0.1f, 0.0f);
                Math_SmoothStepToF(&this->fwork[A6_FWK_35], 1.2f, 0.1f, 0.1f, 0.0f);

                if (D_i3_801C22F0.unk_24 < 1.0f) {
                    this->fwork[A6_FWK_6] = RAND_FLOAT_CENTERED(1000.0f) + gPlayer[0].cam.eye.x;
                    this->fwork[A6_FWK_7] = RAND_FLOAT_CENTERED(1000.0f) + gPlayer[0].cam.eye.y;
                    this->fwork[A6_FWK_3] = -3700.0f + RAND_FLOAT_CENTERED(3000.0f);
                    this->fwork[A6_FWK_34] = 2.0f;
                    this->fwork[A6_FWK_35] = 1.2f;

                    if ((this->swork[A6_SWK_37] == 0) && (this->swork[A6_SWK_33 + 0] == 0) &&
                        (this->swork[A6_SWK_33 + 1] == 0) && (this->swork[A6_SWK_33 + 2] == 0) &&
                        (this->swork[A6_SWK_27 + 0] == 0) && (this->swork[A6_SWK_27 + 1] == 0) &&
                        (this->swork[A6_SWK_27 + 2] == 0)) {
                        this->swork[A6_SWK_37] = 1;
                    }

                    if (this->swork[A6_SWK_37] != 0) {
                        this->swork[A6_SWK_18 + 0] = this->swork[A6_SWK_18 + 1] = this->swork[A6_SWK_18 + 2] = 3;
                        this->fwork[A6_FWK_3] = -1700.0f;
                        if ((this->swork[A6_SWK_25] != 1) && (D_i3_801C2250[A6_BSS_0] != 2)) {
                            this->fwork[A6_FWK_3] = RAND_FLOAT_CENTERED(1000.0f) + -3700.0f;
                        }
                        this->obj.pos.z = gPlayer[0].cam.eye.z - gPathProgress + this->fwork[A6_FWK_3];
                        this->fwork[A6_FWK_6] = this->obj.pos.x = gPlayer[0].cam.eye.x;
                        this->fwork[A6_FWK_7] = this->obj.pos.y = gPlayer[0].cam.eye.y;
                    }

                    D_i3_801C22F0.unk_24 = 0.0f;

                    this->timer_050 = 50;
                    this->state = 2;

                    D_i3_801C2250[A6_BSS_8] = 0;

                    AUDIO_PLAY_SFX(NA_SE_EN_WARP_OUT, this->sfxSource, 4);
                }
            }
            break;

        case 2:
            Math_SmoothStepToF(D_ctx_801779A8, 10.0f, 1.0f, 5.0f, 0.0f);
            if (this->timer_050 == 10) {
                gFillScreenRed = gFillScreenGreen = gFillScreenBlue = 255;
                gFillScreenAlpha = gFillScreenAlphaTarget = 255;
                gFillScreenAlphaTarget = 0;
                gFillScreenAlphaStep = 25;
                gCameraShake = 50;
            }

            if (this->timer_050 == 0) {
                if (D_i3_801C2250[A6_BSS_8] == 0) {
                    D_i3_801C2250[A6_BSS_8] = 1;
                    gFillScreenRed = gFillScreenGreen = gFillScreenBlue = gFillScreenAlpha = 0;
                }

                Math_SmoothStepToF(&D_i3_801C22F0.unk_24, 255.0f, 0.1f, 10.0f, 0.0f);
                Math_SmoothStepToF(&this->fwork[A6_FWK_34], 1.0f, 0.1f, 0.1f, 0.0f);
                Math_SmoothStepToF(&this->fwork[A6_FWK_35], 1.0f, 0.1f, 0.1f, 0.0f);

                if (D_i3_801C22F0.unk_24 > 254.0f) {
                    D_i3_801C22F0.unk_24 = 255.0f;
                    this->info.hitbox[0] = 10;
                    this->fwork[A6_FWK_34] = this->fwork[A6_FWK_35] = 1.0f;

                    switch (this->swork[A6_SWK_38]) {
                        case 0:
                            this->timer_050 = 100;
                            break;
                        case 1:
                            this->timer_050 = 1399;
                            break;
                    }

                    this->swork[A6_SWK_38] = 0;
                    D_i3_801C2250[A6_BSS_28] = 1;

                    this->state = 4;

                    if (this->swork[A6_SWK_37] != 0) {
                        this->timer_050 = 30;
                        this->swork[A6_SWK_37] = 0;
                        this->fwork[A6_FWK_8] = this->fwork[A6_FWK_9] = 0.0f;
                        if (this->swork[A6_SWK_36] < 2) {
                            this->swork[A6_SWK_36]++;
                        }
                        this->state = 3;
                    }

                    if (D_i3_801C2250[A6_BSS_6] != 0) {
                        if (D_i3_801C2250[A6_BSS_0] != 2) {
                            D_i3_801C2250[A6_BSS_0] = 1;
                        } else {
                            D_i3_801C2250[A6_BSS_0] = 0;
                        }
                    }

                    if ((D_i3_801C2250[A6_BSS_6] == 0) || (D_i3_801C2250[A6_BSS_0] == 0)) {
                        this->fwork[A6_FWK_1] = 90.0f;
                        this->fwork[A6_FWK_2] = 2.0f;
                        AUDIO_PLAY_SFX(NA_SE_EN_COVER_OPEN, this->sfxSource, 4);
                        this->info.hitbox = SEGMENTED_TO_VIRTUAL(D_A6_6028578);
                        D_i3_801C2250[A6_BSS_7] = 0;
                    }
                }
            }
            break;

        case 3:
            if (this->timer_050 == 1) {
                Audio_KillSfxBySource(this->sfxSource);
                if (D_i3_801C2250[A6_BSS_7] == 0) {
                    AUDIO_PLAY_SFX(NA_SE_EN_ENERGY_BALL, this->sfxSource, 4);
                    D_i3_801C2250[A6_BSS_7] = 1;
                }
            }

            if (D_i3_801C2250[A6_BSS_0] != 0) {
                if (this->swork[A6_SWK_25] == 1) {
                    this->timer_052 = 30;
                    this->state = 5;
                    this->fwork[A6_FWK_1] = 90.0f;
                    this->fwork[A6_FWK_2] = 2.0f;
                    this->fwork[A6_FWK_37] = 300.0f;
                } else {
                    this->timer_052 = 30;
                    this->state = 8;
                }
            } else {
                if ((this->swork[A6_SWK_36] == 3) && (D_i3_801C2250[A6_BSS_29] == 0)) {
                    Radio_PlayMessage(gMsg_ID_7084, RCID_PEPPY);
                    this->swork[A6_SWK_36] = 4;
                    D_i3_801C2250[A6_BSS_29]++;
                    D_i3_801C2250[A6_BSS_29] &= 1;
                }

                if ((this->swork[A6_SWK_30 + 0] != 0) && (this->swork[A6_SWK_30 + 1] != 0) &&
                    (this->swork[A6_SWK_30 + 2] != 0)) {
                    this->timer_050 = 1500;
                    this->fwork[A6_FWK_1] = 0.0f;
                    D_i3_801C2250[A6_BSS_28] = 0;
                    this->state = 4;
                    this->fwork[A6_FWK_2] = 1.0f;
                    this->info.hitbox = SEGMENTED_TO_VIRTUAL(aA6GorgonHitbox);
                    D_i3_801C2250[A6_BSS_6] = 1;
                    Audio_KillSfxBySource(this->sfxSource);
                    AUDIO_PLAY_SFX(NA_SE_EN_COVER_CLOSE, this->sfxSource, 4);
                    this->swork[A6_SWK_30 + 0] = this->swork[A6_SWK_30 + 1] = this->swork[A6_SWK_30 + 2] = 0;
                } else if (this->swork[A6_SWK_30 + 0] == 0) {
                    Area6_8018A1B0(this, 0);
                } else if (this->swork[A6_SWK_30 + 1] == 0) {
                    Area6_8018A1B0(this, 1);
                } else if (this->swork[A6_SWK_30 + 2] == 0) {
                    Area6_8018A1B0(this, 2);
                }
            }
            break;

        case 4:
            if (this->timer_050 == 1400) {
                this->swork[A6_SWK_15 + 0] = this->swork[A6_SWK_15 + 1] = this->swork[A6_SWK_15 + 2] = 40;
                if (this->swork[A6_SWK_25] == 0) {
                    this->swork[A6_SWK_25] = 1;
                }
                this->fwork[A6_FWK_3] = RAND_FLOAT_CENTERED(1000.0f) + -3700.0f;
                if (D_i3_801C2250[A6_BSS_28] == 0) {
                    AUDIO_PLAY_SFX(NA_SE_EN_COVER_MOVE_STOP, this->sfxSource, 4);
                }
            }

            Math_SmoothStepToF(&this->fwork[A6_FWK_29], 255.0f, 1.0f, 10.0f, 0.0001f);

            if ((this->swork[A6_SWK_36] == 2) && (this->fwork[A6_FWK_0] == 0.0f) && (D_i3_801C2250[A6_BSS_30] == 0)) {
                Radio_PlayMessage(gMsg_ID_7083, RCID_PEPPY);
                this->swork[A6_SWK_36] = 3;
                D_i3_801C2250[A6_BSS_30]++;
                D_i3_801C2250[A6_BSS_30] &= 1;
            }

            if (!(gGameFrameCount % 64U)) {
                this->fwork[A6_FWK_8] = RAND_FLOAT(360.0f);
                this->fwork[A6_FWK_9] = 0.0f;
            }

            if ((this->timer_050 == 0) || ((this->swork[A6_SWK_33 + 0] == 0) && (this->swork[A6_SWK_33 + 1] == 0) &&
                                           (this->swork[A6_SWK_33 + 2] == 0) && (this->swork[A6_SWK_27 + 0] == 0) &&
                                           (this->swork[A6_SWK_27 + 1] == 0) && (this->swork[A6_SWK_27 + 2] == 0))) {
                this->swork[A6_SWK_37] = 1;

                if (D_i3_801C2250[A6_BSS_6] != 0) {
                    this->state = 1;
                    D_i3_801C2250[A6_BSS_27] = 0;
                } else {
                    this->fwork[A6_FWK_1] = 90.0f;
                    this->timer_050 = 30;
                    this->fwork[A6_FWK_8] = this->fwork[A6_FWK_9] = 0;
                    this->fwork[A6_FWK_2] = 2.0f;

                    AUDIO_PLAY_SFX(NA_SE_EN_COVER_OPEN, this->sfxSource, 4);

                    this->info.hitbox = SEGMENTED_TO_VIRTUAL(D_A6_6028578);

                    D_i3_801C2250[A6_BSS_7] = this->swork[A6_SWK_37] = 0;

                    this->state = 3;

                    if (D_i3_801C2250[A6_BSS_6] == 0) {
                        AUDIO_PLAY_BGM(NA_BGM_BOSS_A6);
                    }
                }
            } else if (this->swork[A6_SWK_38] != 0) {
                this->timer_052 = 30;
                this->state = 9;
                this->fwork[A6_FWK_28] = 0.0f;
                D_i3_801C2250[A6_BSS_24] = 0;
                D_i3_801C2250[A6_BSS_27] = 0;
                this->timer_050 = 0;
                this->timer_054 = 0;
                D_i3_801C2250[A6_BSS_34] = 1;
            }
            break;

        case 5:
            if (this->timer_050 == 1) {
                Area6_Effect395_Spawn();
                AUDIO_PLAY_SFX(NA_SE_EN_A6BOSS_CHARGE, this->sfxSource, 4);
                D_i3_801C2250[A6_BSS_33] = 120;
            }

            if (D_i3_801C2250[A6_BSS_33] != 0) {
                D_i3_801C2250[A6_BSS_33]--;
            }

            if (D_i3_801C2250[A6_BSS_33] == 15) {
                if (D_i3_801C2250[A6_BSS_32] == 0) {
                    if (gTeamShields[TEAM_ID_FALCO] > 0) {
                        Radio_PlayMessage(gMsg_ID_20315, RCID_FALCO);
                    } else if (gTeamShields[TEAM_ID_SLIPPY] > 0) {
                        Radio_PlayMessage(gMsg_ID_20316, RCID_SLIPPY);
                    } else if (gTeamShields[TEAM_ID_PEPPY] > 0) {
                        Radio_PlayMessage(gMsg_ID_20317, RCID_PEPPY);
                    }
                }
                D_i3_801C2250[A6_BSS_32]++;
                D_i3_801C2250[A6_BSS_32] &= 1;
            }
            break;

        case 6:
            this->obj.pos.z -= this->fwork[A6_FWK_37];

            Math_SmoothStepToF(&this->fwork[A6_FWK_37], 0.0f, 1.0f, 10.0f, 0.00001f);
            Math_SmoothStepToF(&this->fwork[A6_FWK_3], -6000.0f, 10.0f, 100.0f, 0.00001f);

            var_s0 = D_i3_801C2250[A6_BSS_9] * 4;

            Math_SmoothStepToF(&D_i3_801C22F0.unk_28[0], D_i3_801BF454[var_s0], 0.5f, 100.0f, 0.00001f);
            Math_SmoothStepToF(&D_i3_801C22F0.unk_28[2], D_i3_801BF454[var_s0 + 1], 0.5f, 100.0f, 0.00001f);
            Math_SmoothStepToF(&D_i3_801C22F0.unk_28[1], D_i3_801BF454[var_s0 + 2], 0.5f, 100.0f, 0.00001f);

            if (((gGameFrameCount % 16) == 0)) {
                D_i3_801C2250[A6_BSS_9]++;
                D_i3_801C2250[A6_BSS_9] &= 3;
            }

            if (this->timer_050 + 30 * 60 * 10 == 0) {
                this->fwork[A6_FWK_1] = 0.0f;
                this->state = 7;
            }
            break;

        case 7:
            effect = &gEffects[this->swork[A6_SWK_39]];

            Math_SmoothStepToF(&D_i3_801C22F0.unk_28[0], 255.0f, 1.0f, 100.0f, 0.00001f);
            Math_SmoothStepToF(&D_i3_801C22F0.unk_28[2], 255.0f, 1.0f, 100.0f, 0.00001f);
            Math_SmoothStepToF(&D_i3_801C22F0.unk_28[1], 255.0f, 1.0f, 100.0f, 0.00001f);

            if (this->fwork[A6_FWK_0] < 10.0f) {
                effect->orient.y = 5.0f - ((10.0f - this->fwork[A6_FWK_0]) * 0.3f);
                effect->orient.x = 5.0f - ((10.0f - this->fwork[A6_FWK_0]) * 0.3f);
            }

            if (this->fwork[A6_FWK_0] < 1.0f) {
                Math_SmoothStepToF(&effect->orient.x, 0.0f, 0.1f, 1.0f, 0.00001f);
                Math_SmoothStepToF(&effect->orient.y, 0.0f, 0.1f, 1.0f, 0.00001f);
                Math_SmoothStepToF(&effect->orient.z, 0.0f, 1.0f, 2.0f, 0.00001f);

                if (effect->orient.z < 0.2f) {
                    D_i3_801C2250[A6_BSS_0] = 2;
                    this->swork[A6_SWK_37] = 1;
                    this->timer_050 = 20;
                    D_i3_801C22F0.unk_28[0] = D_i3_801C22F0.unk_28[2] = D_i3_801C22F0.unk_28[1] = 255.0f;
                    this->state = 1;
                    D_i3_801C2250[A6_BSS_27] = 0;
                    Object_Kill(&effect->obj, effect->sfxSource);
                }
            }
            break;

        case 8:
            if (this->timer_052 == 0) {
                D_i3_801C2250[A6_BSS_24] = 0;
                this->timer_052 = 300;
                this->timer_054 = 0;
                this->state = 9;
                AUDIO_PLAY_SFX(NA_SE_EN_SHIELD_ROLL_LEVEL, this->sfxSource, 4);
            }
            break;

        case 9:
            if (this->timer_052 == 0) {
                Audio_KillSfxBySource(this->sfxSource);
                AUDIO_PLAY_SFX(NA_SE_EN_SHIELD_ROLL_STOP, this->sfxSource, 4);
                this->timer_054 = 0;
                this->state = 10;
            } else {
                if (D_i3_801C2250[A6_BSS_34] == 0) {
                    this->obj.rot.z += this->fwork[A6_FWK_28];
                    this->obj.rot.z = Math_ModF(this->obj.rot.z, 360.0f);
                    Math_SmoothStepToF(&this->fwork[A6_FWK_28], 20.0f, 0.1f, 0.5f, 0.0001f);
                }
                if (this->timer_054 == 0) {
                    this->timer_054 = 10;

                    if (D_i3_801C2250[A6_BSS_34] == 0) {
                        this->timer_054 = 30;
                    }

                    sp128 = 6;
                    if (this->swork[A6_SWK_25] == 2) {
                        sp128 = 12;
                    }

                    for (var_s0 = 0; var_s0 < sp128; var_s0++) {
                        Matrix_RotateZ(gCalcMatrix, (360.0f / sp128) * M_DTOR, MTXF_APPLY);

                        sp98.x = 0.0f;
                        sp98.y = 400.0f;
                        sp98.z = 0.0f;

                        Matrix_MultVec3fNoTranslate(gCalcMatrix, &sp98, &sp8C);

                        yaw_10C = Math_Atan2F(sp8C.x, sp8C.z);
                        yaw_10C = Math_RadToDeg(yaw_10C);

                        pitch_110 = Math_Atan2F(sp8C.y, sqrtf(SQ(sp8C.x) + SQ(sp8C.z)));
                        pitch_110 = Math_RadToDeg(-pitch_110);

                        spf124 = D_i3_801C2250[A6_BSS_12_0 + var_s0] - 1;
                        if (spf124 < 0) {
                            spf124 = 0;
                        }

                        if ((gActors[spf124].obj.status == OBJ_FREE) ||
                            (gActors[spf124].obj.id != OBJ_ACTOR_MISSILE_SEEK_PLAYER) ||
                            (D_i3_801C2250[A6_BSS_24] == 0)) {
                            D_i3_801C2250[A6_BSS_12_0 + var_s0] = 0;

                            spf124 = 0;

                            if (this->swork[A6_SWK_25] == 1) {
                                spf124 = 1;
                            }

                            Area6_ActorMissileSeekPlayer_Spawn(this->obj.pos.x + sp8C.x, this->obj.pos.y + sp8C.y,
                                                               this->obj.pos.z + sp8C.z, 25.0f, pitch_110, yaw_10C, 10,
                                                               spf124);

                            D_i3_801C2250[A6_BSS_12_0 + var_s0] = D_i3_801C2250[A6_BSS_11];
                        }
                    }
                    D_i3_801C2250[A6_BSS_24] = 1;
                }
            }
            break;

        case 10:
            if (D_i3_801C2250[A6_BSS_34] == 0) {
                this->obj.rot.z += this->fwork[A6_FWK_28];
                this->obj.rot.z = Math_ModF(this->obj.rot.z, 360.0f);
                Math_SmoothStepToF(&this->fwork[A6_FWK_28], 0.0f, 0.1f, 0.5f, 0.0001f);
            }

            if (this->fwork[A6_FWK_28] <= 0.1f) {
                if (D_i3_801C2250[A6_BSS_34] == 0) {
                    this->fwork[A6_FWK_28] = 0.0f;
                    D_i3_801C2250[A6_BSS_0] = 2;
                    this->swork[A6_SWK_37] = 1;
                }
                this->timer_050 = 20;
                D_i3_801C2250[A6_BSS_27] = 0;
                D_i3_801C2250[A6_BSS_34] = 0;
                this->state = 1;
            }
            break;

        case 11:
            if ((this->timer_052 == 160) &&
                ((gPlayer[0].state == PLAYERSTATE_ACTIVE) || (gPlayer[0].state == PLAYERSTATE_U_TURN))) {
                gPlayer[0].state = PLAYERSTATE_LEVEL_COMPLETE;
                gPlayer[0].csState = 0;
            }

            if (this->timer_052 < 50) {
                D_ctx_801779A8[0] = 50.0f;
            } else {
                D_ctx_801779A8[0] = 20.0f;
            }

            if (this->timer_052 == 0) {
                gShowBossHealth = false;
                Object_Kill(&this->obj, this->sfxSource);
            }
            break;
    }

    Area6_8018A464(this, 0);
    Area6_8018A464(this, 1);
    Area6_8018A464(this, 2);

    for (i = 0; i < 5; i++) {
        if (!(gGameFrameCount % 4U)) {
            D_i3_801BF280[i] = RAND_FLOAT_CENTERED(10.0f);
            D_i3_801BF2B0[i] = RAND_FLOAT_CENTERED(10.0f);
            D_i3_801BF2E0[i] = RAND_FLOAT_CENTERED(10.0f);
        }
        Math_SmoothStepToF(&D_i3_801BF1F0[i], D_i3_801BF280[i], 1.0f, 5.0f, 0.001f);
        Math_SmoothStepToF(&D_i3_801BF220[i], D_i3_801BF2B0[i], 1.0f, 5.0f, 0.001f);
        Math_SmoothStepToF(&D_i3_801BF250[i], D_i3_801BF2E0[i], 1.0f, 5.0f, 0.001f);
    }

    A6_HIT_4(this, 0)->z.offset = this->vwork[A6_VWK_4].z;
    A6_HIT_4(this, 0)->y.offset = this->vwork[A6_VWK_4].y;
    A6_HIT_4(this, 0)->x.offset = this->vwork[A6_VWK_4].x;
    A6_HIT_4(this, 1)->z.offset = this->vwork[A6_VWK_5].z;
    A6_HIT_4(this, 1)->y.offset = this->vwork[A6_VWK_5].y;
    A6_HIT_4(this, 1)->x.offset = this->vwork[A6_VWK_5].x;
    A6_HIT_4(this, 2)->z.offset = this->vwork[A6_VWK_6].z;
    A6_HIT_4(this, 2)->y.offset = this->vwork[A6_VWK_6].y;
    A6_HIT_4(this, 2)->x.offset = this->vwork[A6_VWK_6].x;

    if (gBossFrameCount == 600) {
        Radio_PlayMessage(gMsg_ID_2225, RCID_SLIPPY);
    }
    if (gBossFrameCount == 756) {
        gShowBossHealth = true;
    }
    if (gBossFrameCount > 756) {
        gBossHealthBar = (this->health / 780.0f) * 255.0f;
    }

    for (i = 0; i < 15; i++) {
        if (this->swork[A6_SWK_0 + i] != 0) {
            this->swork[A6_SWK_0 + i]--;
        }
    }

    if (this->fwork[A6_FWK_0] > 20.0f) {
        for (i = 0; i < 3; i++) {
            if (this->swork[A6_SWK_0 + i] == 0) {
                this->swork[A6_SWK_0 + i] = 5;
            }
        }
    }

    if (D_i3_801C2250[A6_BSS_5] != 0) {
        D_i3_801C2250[A6_BSS_5]--;
    }
    if (D_i3_801C2250[A6_BSS_25] != 0) {
        D_i3_801C2250[A6_BSS_25]--;
    }
}
#endif