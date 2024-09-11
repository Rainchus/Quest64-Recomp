
#include "patches.h"
#include "rt64_extended_gbi.h"
#include "sfx.h"

#if 1 // enable/disable all patches

#if 1 // Hud_PlayerShieldGauge_Draw

extern f32 D_801617A8;
extern f32 D_801617AC;
extern s32 D_800D1EB4;
extern s32 D_800D1EB8;
extern s32 D_800D1EBC;

void func_hud_800856C0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_hud_80085618(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_hud_800855C4(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_hud_8008566C(f32 x, f32 y, f32 arg2, f32 arg3);
void func_hud_80085740(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

RECOMP_PATCH void func_hud_8008B5B0(f32 x, f32 y) {

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, 0, 0, 0, 0);

    RCP_SetupDL(&gMasterDisp, SETUPDL_75);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
    func_hud_800856C0(x + 8.0f, y + 2.0f, D_801617A8, 1.0f, D_801617AC);
    // White Outiline
    RCP_SetupDL(&gMasterDisp, SETUPDL_76);
    gDPSetPrimColor(gMasterDisp++, 0, 0, D_800D1EB4, D_800D1EB8, D_800D1EBC, 255);
    func_hud_80085618(x, y, 1.0f, 1.0f);
    func_hud_800855C4(x + 7.0f + (D_801617A8 * 6.0f * 8.0f), y, 1.0f, 1.0f);
    func_hud_8008566C(x + 7.0f, y, D_801617A8 * 6.0f, 1.0f);

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
}
#endif

#if 1 // Hud_Hitpoints_Draw

extern u8 aLargeText_0[];
extern u8 aLargeText_1[];
extern u8 aLargeText_2[];
extern u8 aLargeText_3[];
extern u8 aLargeText_4[];
extern u8 aLargeText_5[];
extern u8 aLargeText_6[];
extern u8 aLargeText_7[];
extern u8 aLargeText_8[];
extern u8 aLargeText_9[];

RECOMP_PATCH void func_hud_80094D20(f32 x, f32 y) {
    u8* D_800D24DC[] = { aLargeText_0, aLargeText_1, aLargeText_2, aLargeText_3, aLargeText_4,
                         aLargeText_5, aLargeText_6, aLargeText_7, aLargeText_8, aLargeText_9 };
    s32 D_800D2504[] = { 100, 10, 1 };
    bool boolTemp;
    s32 i;
    s32 j;
    s32 temp;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    f32 x1;
    f32 y1;
    f32 xScale;

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, 0, 0, 0, 0);

    if (gHitCount > gDisplayedHitCount) {
        temp3 = gDisplayedHitCount + 1;
        temp4 = gDisplayedHitCount;
    } else {
        temp3 = gHitCount;
        temp4 = gDisplayedHitCount;
    }

    boolTemp = false;
    i = 1000;
    temp3 %= i;
    temp4 %= i;

    for (i /= 10, j = 0; i != 1; i /= 10, j++) {
        xScale = 1.0f;
        x1 = x;
        y1 = y + 3.0f;

        temp = temp3 / i;
        temp2 = temp4 / i;

        if ((temp != 0) || (boolTemp == true)) {
            if (temp != temp2) {
                D_hud_80161720[j] += 0.4f;
                if (D_hud_80161720[j] <= 0.9f) {
                    xScale = D_hud_80161720[j];
                    x1 += 8.0f * xScale;
                    xScale = 1.0f - xScale;
                }

                if ((D_hud_80161720[j] > 0.9f) && (D_hud_80161720[j] < 1.1f)) {
                    xScale = 0.0f;
                }

                if (D_hud_80161720[j] >= 2.0f) {
                    temp2++;
                    if (temp2 >= 10) {
                        temp2 = 0;
                    }
                    D_hud_80161720[j] = 0.0f;
                }

                if ((D_hud_80161720[j] < 2.0f) && (D_hud_80161720[j] >= 1.1f)) {
                    temp2++;
                    if (temp2 >= 10) {
                        temp2 = 0;
                    }
                    xScale = 2.0f - D_hud_80161720[j];
                    x1 += 8.0f * xScale;
                    xScale = 1.0f - xScale;
                }
                temp = temp2;
            }

            if (xScale != 0.0f) {
                TextureRect_IA8(&gMasterDisp, D_800D24DC[temp], 16, 15, x1, y1, xScale, 1.0f);
            }
            boolTemp = true;
        }

        if (!boolTemp && (xScale != 0.0f)) {
            TextureRect_IA8(&gMasterDisp, D_800D24DC[0], 16, 15, x1, y1, xScale, 1.0f);
        }

        x += 13.0f;
        temp3 %= i;
        temp4 %= i;
    }

    xScale = 1.0f;
    x1 = x;
    y1 = y + 3.0f;

    if (temp3 != temp4) {
        D_hud_80161720[j] += 0.4f;
        if (D_hud_80161720[j] <= 0.9f) {
            xScale = D_hud_80161720[j];
            x1 += 8.0f * xScale;
            xScale = 1.0f - xScale;
        }

        if ((D_hud_80161720[j] > 0.9f) && (D_hud_80161720[j] < 1.1f)) {
            xScale = 0.0f;
        }

        if (D_hud_80161720[j] >= 2.0f) {
            temp4++;
            if (temp4 >= 10) {
                temp4 = 0;
            }
            D_hud_80161720[j] = 0.0f;
        }

        if ((D_hud_80161720[j] < 2.0f) && (D_hud_80161720[j] >= 1.1f)) {
            temp4++;
            if (temp4 >= 10) {
                temp4 = 0;
            }
            xScale = 2.0f - D_hud_80161720[j];
            x1 += 8.0f * xScale;
            xScale = 1.0f - xScale;
        }
        temp3 = temp4;
    }

    if (xScale != 0.0f) {
        TextureRect_IA8(&gMasterDisp, D_800D24DC[temp3], 16, 15, x1, y1, xScale, 1.0f);
    }

    if ((gHitCount != gDisplayedHitCount) && (D_hud_80161720[0] == 0.0f) && (D_hud_80161720[1] == 0.0f) &&
        (D_hud_80161720[2] == 0.0f)) {
        gDisplayedHitCount++;

        if ((gDisplayedHitCount == 4) || (gDisplayedHitCount == 9) || (gDisplayedHitCount == 14) ||
            (gDisplayedHitCount == 19) || (gDisplayedHitCount == 24) || (gDisplayedHitCount == 29)) {
            gDropHitCountItem = gDisplayedHitCount;
        }
    }

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
}
#endif

#if 1 // Hud_GoldRings_Draw
extern Gfx D_101C170[];
extern Gfx D_101C000[];
extern Gfx D_101BE90[];
extern Gfx D_101BD20[];
extern Gfx D_101BBB0[];
extern Gfx D_101BA40[];
extern Gfx D_101B8D0[];
extern Gfx D_101B760[];
extern Gfx D_101B5F0[];
extern Gfx D_101B480[];
extern Gfx D_101B310[];
extern Gfx D_101B1A0[];
extern f32 D_801618B0[20];
extern s32 D_80161900[20];
extern s32 D_80161860[20];
extern Gfx D_1012110[];
extern Gfx D_101C2E0[];

static f32 tempx = 0;
static f32 tempy = 0;

RECOMP_PATCH void func_hud_80085944(void) {
    Gfx* D_800D1A94[] = { D_101C170, D_101C000, D_101BE90, D_101BD20, D_101BBB0, D_101BA40,
                          D_101B8D0, D_101B760, D_101B5F0, D_101B480, D_101B310, D_101B1A0 };
    s32 i;
    s32 j;
    f32 D_800D1AC4[] = { 0.0f, -30.0f, -26.0f, -22.0f, -18.0f };
    f32 D_800D1AD8[] = { 0.0f, 28.0f, 28.0f, 28.0f, 28.0f };
    f32 scale;
    f32 x;
    f32 y;
    s32 temp;

// @recomp debug
#if 0 // Enable Controller for moving rings
 if (gControllerHold[0].button&U_JPAD){
     tempy += 1.00f;
 }else if(gControllerHold[0].button&D_JPAD){
     tempy -= 1.00f;
 }if(gControllerHold[0].button&R_JPAD){
     tempx += 1.00f;
 }else if(gControllerHold[0].button&L_JPAD){
     tempx -= 1.00f;
 }
#endif

    Game_InitFullViewport();
    gEXViewport(gMasterDisp++, G_EX_ORIGIN_LEFT, gViewport); // Force the viewport update

    D_801618B0[6] += 0.7f;
    if (D_801618B0[6] >= 12.0f) {
        D_801618B0[6] = 0.0f;
    }

    if (D_80161900[4]) {
        D_80161900[4]--;
    }

    for (i = 0; i < 4; i++) {
        if (D_80161900[i]) {
            D_80161900[i]--;
        }
    }

    if ((D_80161900[4] == 0) && (gGoldRingCount[0] > gGoldRingCount[1])) {
        gGoldRingCount[1] += 1; // can't be ++

        if ((i = gGoldRingCount[1] % 3) == 0) {
            i = 3;
        }

        i--;

        D_80161860[1 + i] = 1;
        D_80161900[0 + i] = 14;
        D_801618B0[2 + i] = 0.0f;

        if (i == 2) {
            D_80161900[4] = 28;
        }

        if (gGoldRingCount[1] == 3) {
            D_80161900[4] += 28;
        }
    }

    for (i = 0; i < 3; i++) {
        switch (D_80161860[i + 1]) {
            case 0: // transparent gold rings
                RCP_SetupDL(&gMasterDisp, SETUPDL_62);
                Matrix_Push(&gGfxMatrix);

                x = D_800D1AC4[i + 1] + tempx;
                y = D_800D1AD8[i + 1] + tempy;

                scale = 0.28f;

                if (gFovYMode == 2) {
                    x -= 7.00f;
                    y += 7.00f;
                    scale += 0.06f;
                }

                Matrix_Translate(gGfxMatrix, x, y, -100.0f, MTXF_NEW);
                Matrix_Scale(gGfxMatrix, scale, scale, scale, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);

                gDPSetPrimColor(gMasterDisp++, 0, 0, 180, 180, 0, 50);
                gSPDisplayList(gMasterDisp++, D_1012110);

                Matrix_Pop(&gGfxMatrix);

                break;

            case 1:
            case 2:
                if (D_80161900[i]) {
                    if (D_80161900[i + 0] >= 7) {
                        D_801618B0[i + 2] += 0.15f;
                    } else {
                        D_801618B0[i + 2] -= 0.15f;
                    }

                    RCP_SetupDL(&gMasterDisp, SETUPDL_62);
                    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);

                    Matrix_Push(&gGfxMatrix);
                    Matrix_Translate(gGfxMatrix, D_800D1AC4[i + 1], D_800D1AD8[i + 1], -100.0f, MTXF_NEW);
                    Matrix_RotateZ(gGfxMatrix, M_DTOR * D_801618B0[0], MTXF_APPLY);
                    Matrix_Scale(gGfxMatrix, D_801618B0[i + 2], D_801618B0[i + 2], D_801618B0[i + 2], MTXF_APPLY);

                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_101C2E0);
                    Matrix_Pop(&gGfxMatrix);
                }

                if (D_80161900[i] < 7) {
                    if (D_80161860[i + 1] == 2) {
                        RCP_SetupDL(&gMasterDisp, SETUPDL_62);
                    } else {
                        RCP_SetupDL(&gMasterDisp, SETUPDL_36);
                    }

                    Matrix_Push(&gGfxMatrix);

                    x = D_800D1AC4[i + 1];
                    y = D_800D1AD8[i + 1];
                    scale = 0.28f;

                    if (gFovYMode == 2) {
                        x -= 7.00f;
                        y += 7.00f;
                        scale += 0.06f;
                    }

                    Matrix_Translate(gGfxMatrix, x, y, -100.0f, MTXF_NEW);
                    Matrix_Scale(gGfxMatrix, scale, scale, scale, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);

                    if (D_80161860[i + 1] == 2) {
                        gDPSetPrimColor(gMasterDisp++, 0, 0, 180, 180, 0, 50);
                        gSPDisplayList(gMasterDisp++, D_1012110);
                    } else {
                        temp = D_801618B0[6];
                        gSPDisplayList(gMasterDisp++, D_800D1A94[temp]);
                    }
                    Matrix_Pop(&gGfxMatrix);
                }
                break;

            default:
                break;
        }
    }

    if ((gGoldRingCount[1] && ((gGoldRingCount[1] % 3) == 0)) && (D_80161900[4] == 1)) {
        for (j = 0; j < 4; j++) {
            if (D_80161860[j + 1] == 1) {
                D_80161860[j + 1] = 2;
                D_80161900[j + 0] = 14;
                D_801618B0[j + 2] = 0.0f;
                D_80161900[4] = 28;
            } else {
                D_80161860[j + 1] = 0;
                D_80161900[j + 0] = 14;
                D_801618B0[j + 2] = 0.0f;
            }
        }
    }
    D_801618B0[0] += 35.0f;
    D_801618B0[1] += 10.0f;

    gEXViewport(gMasterDisp++, G_EX_ORIGIN_NONE, gViewport);
}
#endif

#if 1 // HUD_DrawBossHealth

extern f32 D_801616BC;
extern f32 D_801616C0;
extern u8 D_1011A40[];
extern u16 D_1011AB0[];
extern u8 D_1002040[];
extern u8 D_10129C0[];
extern u16 D_1013090[];
extern f32 D_801616C4;
extern f32 D_801616C8;

void HUD_DrawBossHealth(void) {
    f32 sp3C;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp4;
    f32 temp5;
    f32 temp6;
    f32 temp7;
    f32 var_fv0;

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, 0, 0, 0, 0);

    if ((gShowBossHealth == 1) && (gTeamShields[TEAM_ID_SLIPPY] > 0)) {
        if ((gBossHealthBar >= 0) && (D_801616BC == -1.0f)) {
            AUDIO_PLAY_SFX(NA_SE_BOSS_GAUGE_OPEN, gDefaultSfxSource, 4);
            D_801616BC = 255.0f;
        }

        Math_SmoothStepToF(&D_801616C0, 25.0f, 0.3f, 4.0f, 4.0f);

        sp3C = D_801616C0;
        temp1 = 52.0f;
        temp2 = sp3C + 5.0f;
        temp3 = temp1 + 3.0f;
        temp4 = sp3C + 6.0f;
        temp5 = temp1 + 10.0f;

        RCP_SetupDL(&gMasterDisp, SETUPDL_78);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
        TextureRect_CI4(&gMasterDisp, D_1011A40, D_1011AB0, 32, 7, temp2, temp3, 1.0f, 1.0f);

        RCP_SetupDL(&gMasterDisp, SETUPDL_76);
        TextureRect_IA8(&gMasterDisp, D_1002040, 40, 12, sp3C, temp1, 1.0f, 1.0f);

        if (sp3C >= 25.0f) {
            Math_SmoothStepToF(&D_801616C4, 0.88f, 0.3f, 0.2f, 0.1f);
        }

        if ((D_801616C4 >= 0.1f) && (sp3C >= 25.0f)) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_78);
            gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
            TextureRect_CI8(&gMasterDisp, D_10129C0, D_1013090, 16, 109, temp4, temp5, 1.0f, D_801616C4);
        }

        RCP_SetupDL(&gMasterDisp, SETUPDL_76);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 0, 0, 0, 255);

        if (D_801616BC > 0.0f) {
            var_fv0 = (D_801616BC - gBossHealthBar) * (2.76f / D_801616BC);
            if (var_fv0 > 2.76f) {
                var_fv0 = 2.76f;
            }
            if (var_fv0 < 0.00f) {
                var_fv0 = 0.00f;
            }
            Math_SmoothStepToF(&D_801616C8, var_fv0, 0.2f, 1000.0f, 0.01f);
        } else {
            D_801616C8 = 2.76f;
        }

        if (D_801616C4 >= 0.88f) {
            temp6 = sp3C + 8.0f;
            temp7 = 101.0f - ((2200.0f / 69.0f) * D_801616C8) + temp1;
            if (D_801616C8 > 0.0f) {
                TextureRect_RGBA16(&gMasterDisp, D_Tex_800D99F8, 32, 32, temp6, temp7, 0.2f, D_801616C8);
            }
        }
    } else {
        D_801616C0 = 0.0f;
        D_801616C4 = 0.0f;
        D_801616C8 = 0.0f;
        D_801616BC = -1.0f;
    }

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
}
#endif

#if 1 // Hud_LivesCount2_Draw (player)

extern u8 D_arwing_3000000[];
extern u8 D_blue_marine_3000000[];
extern u8 D_landmaster_3000000[];
extern u16 D_arwing_3000080[];
extern u16 D_blue_marine_3000080[];
extern u16 D_landmaster_3000080[];
extern u8 D_1011ED0[];
extern u16 D_1011F08[];

RECOMP_PATCH void func_hud_80087530(f32 x, f32 y, s32 number) {
    u8* D_800D1D00[] = { D_arwing_3000000, D_blue_marine_3000000, D_landmaster_3000000 };
    u16* D_800D1D0C[] = { D_arwing_3000080, D_blue_marine_3000080, D_landmaster_3000080 };
    Player* player = &gPlayer[0];
    f32 x0;
    f32 x1;
    f32 x2;
    f32 y0;
    f32 y1;
    f32 y2;
    s32 var_v1;
    s32 i;
    s32 form;
    ;
    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, G_EX_ORIGIN_RIGHT, -(SCREEN_WIDTH) * 4, 0, -(SCREEN_WIDTH) * 4,
                    0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, -SCREEN_WIDTH * 4, SCREEN_HEIGHT * 4);

    RCP_SetupDL(&gMasterDisp, SETUPDL_78);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);

    form = FORM_ARWING;

    switch (player->form) {
        case FORM_ARWING:
            form = FORM_ARWING;
            break;

        case FORM_LANDMASTER:
            form = FORM_LANDMASTER;
            break;

        case FORM_BLUE_MARINE:
            form = FORM_BLUE_MARINE;
            break;

        default:
            break;
    }

    x0 = x;
    y0 = y;
    x1 = x0 + 16.0f;
    y1 = y0 + 9.0f;
    x2 = x1 + 11.0f;
    y2 = y1 - 1.0f;

    if (number < 0) {
        number = 0;
    }
    if (number > 99) {
        number = 99;
    }

    var_v1 = 10;
    for (i = 1; var_v1 <= number; i++) {
        var_v1 *= 10;
    }
    x2 += (2 - i) * 4;

    TextureRect_CI4(&gMasterDisp, D_800D1D00[form], D_800D1D0C[form], 16, 16, x0, y0, 1.0f, 1.0f);
    TextureRect_CI4(&gMasterDisp, D_1011ED0, D_1011F08, 16, 7, x1, y1, 1.0f, 1.0f);

    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 0, 255);
    Graphics_DisplayHUDNumber(x2, y2, number);

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_NONE, 0, 0);
}
#endif

#if 1 // Boost Bar

extern f32 D_800D19AC[];

RECOMP_PATCH void func_hud_8008D4F0(f32 arg0, f32 arg1) {
    f32 D_800D2108[] = {
        110.0f, 270.0f, 110.0f, 270.0f, 0.0f,
    };
    f32 D_800D211C[] = {
        16.0f, 16.0f, 136.0f, 136.0f, 0.0f,
    };
    f32 temp_fv0;
    f32 temp2;
    f32 temp_fs0;
    f32 sp68;
    f32 temp;
    f32 sp60;
    s32 temp_t9;
    s32 var_v1;

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, G_EX_ORIGIN_RIGHT, -(SCREEN_WIDTH) * 4, 0, -(SCREEN_WIDTH) * 4,
                    0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, -(SCREEN_WIDTH) * 4, 0);

    if (gVersusMode) {
        temp = 2.0f;
        sp60 = 1.0f;
        var_v1 = gPlayerNum;
        sp68 = 24.0f;
    } else {
        temp = 2.0f;
        sp60 = 2.0f;
        sp68 = 40.0f;
        var_v1 = 4;
        D_800D2108[var_v1] = arg0;
        D_800D211C[var_v1] = arg1;
    }

    temp_fs0 = gPlayer[gPlayerNum].boostMeter * (1.0f / 90.0f);

    temp_fv0 = 1.0f - temp_fs0;
    temp2 = sp68 * temp_fs0;

    if (!gPlayer[gPlayerNum].boostCooldown) {
        Math_SmoothStepToF(&D_800D19AC[var_v1], 255.0f, 0.4f, 100.0f, 0.01f);
    } else {
        Math_SmoothStepToF(&D_800D19AC[var_v1], 100.0f, 0.4f, 100.0f, 0.01f);
    }

    temp_t9 = D_800D19AC[var_v1];

    RCP_SetupDL(&gMasterDisp, SETUPDL_78);

    gDPSetPrimColor(gMasterDisp++, 0, 0, temp_t9, temp_t9, temp_t9, 255);

    if (temp_fv0 > 0.01f) {
        func_hud_80085890(D_800D2108[var_v1] + temp + temp2, D_800D211C[var_v1] + sp60, temp_fv0, 1.0f);
    }
    if (temp_fs0 > 0.01f) {
        func_hud_800857DC(D_800D2108[var_v1] + temp + 1.0f, D_800D211C[var_v1] + sp60, temp_fs0, 1.0f);
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_76);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
    func_hud_80085740(D_800D2108[var_v1], D_800D211C[var_v1], 1.0f, 1.0f);

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_NONE, 0, 0);
}
#endif

#if 1 // Hud_BombCounter_Draw

void func_hud_8008DCB0(f32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_hud_8008DD78(f32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern s32 D_800D19F8;
extern s32 D_800D19F4;
extern f32 D_800D19F0;
extern s32 D_80161770;
extern s32 D_80161774;
extern s32 D_80161778;
extern s32 D_8016177C;
extern s32 D_80161780;
extern s32 D_80161784;
extern s32 D_8016177C;
extern u8 D_10116B0[];
extern u16 D_1011730[];
extern u8 D_blue_marine_3000090[];
extern u16 D_blue_marine_3000120[];

RECOMP_PATCH void func_hud_8008EA14(f32 x, f32 y) {
    s32 i;
    s32 sp68;
    f32 temp_fv0;
    f32 temp;

    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, G_EX_ORIGIN_RIGHT, -(SCREEN_WIDTH) * 4, 0, -(SCREEN_WIDTH) * 4,
                    0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, -(SCREEN_WIDTH) * 4, 0);

    if (gBombCount[gPlayerNum] > 9) {
        gBombCount[gPlayerNum] = 9;
    }

    switch (D_800D19F8) {
        case 0:
            D_800D19F4 = gBombCount[gPlayerNum];
            sp68 = 0;
            D_800D19F8 = 1;
            D_80161770 = D_80161774 = D_80161778 = 255.0f;
            D_8016177C = D_80161780 = D_80161784 = 255.0f;
            break;

        case 1:
            temp_fv0 = gBombCount[gPlayerNum] - D_800D19F4;
            if (temp_fv0 > 0.0f) {
                D_800D19F4++;
                if (D_800D19F4 > 5) {
                    sp68 = 0;
                    break;
                }
                if (D_800D19F4 == 5) {
                    D_800D19F0 = 0.0f;
                    sp68 = 4;
                    D_800D19F8 = 6;
                    break;
                } else {
                    D_800D19F0 = 0.0f;
                    sp68 = 3;
                    D_800D19F8 = 5;
                }
                break;
            }

            if (temp_fv0 < 0.0f) {
                D_800D19F8 = 2;
            }
            sp68 = 0;
            break;

        case 2:
            D_800D19F4--;
            sp68 = 0;
            D_800D19F8 = 1;
            if (D_800D19F4 <= 3) {
                D_800D19F0 = 0.0f;
                sp68 = 2;
                D_800D19F8 = 4;
                break;
            }

            if (D_800D19F4 == 4) {
                D_800D19F0 = 0.0f;
                sp68 = 1;
                D_800D19F8 = 3;
                break;
            }
            break;

        case 3:
            sp68 = 1;
            if (Math_SmoothStepToF(&D_800D19F0, 10.0f, 0.3f, 10.0f, 0.1f) == 0.0f) {
                D_800D19F8 = 1;
                D_800D19F0 = 10.0f;
                sp68 = 1;
            }
            break;

        case 4:
            sp68 = 2;
            if (Math_SmoothStepToF(&D_800D19F0, 10.0f, 0.3f, 10.0f, 0.1f) == 0.0f) {
                D_800D19F8 = 1;
                D_800D19F0 = 10.0f;
                sp68 = 2;
            }
            break;

        case 5:
            sp68 = 3;
            if (Math_SmoothStepToF(&D_800D19F0, 20.0f + ((D_800D19F4 - 1) * 10), 0.3f, 10.0f, 0.001f) == 0.0f) {
                D_800D19F8 = 1;
                D_800D19F0 = 20.0f + ((D_800D19F4 - 1) * 10);
                sp68 = 3;
            }
            break;

        case 6:
            sp68 = 4;
            if (Math_SmoothStepToF(&D_800D19F0, 10.0f, 0.3f, 10.0f, 0.1f) == 0.0f) {
                D_800D19F8 = 7;
                D_800D19F0 = 0.0f;
                sp68 = 5;
            }
            break;

        case 7:
            sp68 = 5;
            if (0.0f == Math_SmoothStepToF(&D_800D19F0, 12.0f, 0.3f, 10.0f, 5.0f)) {
                D_800D19F8 = 1;
                D_800D19F0 = 0.0f;
                sp68 = 0;
            }
            break;

        default:
            break;
    }

    if (gPlayerShots[15].obj.status == SHOT_FREE) {
        D_80161770 = D_80161774 = D_80161778 = 255.0f;
        D_8016177C = D_80161780 = 255.0f;
        D_80161784 = 0.0f;
    } else {
        D_80161770 = 100.0f;
        D_80161774 = D_80161778 = 0.0f;
        D_8016177C = D_80161780 = 40.0f;
        D_80161784 = 0.0f;
    }

    RCP_SetupDL_78();
    gDPSetPrimColor(gMasterDisp++, 0, 0, (s32) D_80161770, (s32) D_80161774, (s32) D_80161778, D_hud_80161708);

    if (gCurrentLevel == LEVEL_AQUAS) {
        sp68 = 6;
    }

    switch (sp68) {
        case 0:
            if (D_800D19F4 >= 5) {
                TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x, y, 1.0f, 1.0f);
                func_hud_8008DCB0(x + 14.0f, y + 2.0f, D_8016177C, D_80161780, D_80161784);
                func_hud_8008DD78(x + 29.0f, y + 1.0f, D_800D19F4, D_8016177C, D_80161780, D_80161784);
            } else {
                for (i = (D_800D19F4 - 1); i >= 0; i--) {
                    TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (30.0f - (i * 10)), y, 1.0f, 1.0f);
                }
            }
            break;

        case 1:
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (D_800D19F0 * 3.0f), y, 1.0f, 1.0f);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (D_800D19F0 * 2.0f), y, 1.0f, 1.0f);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (D_800D19F0 * 1.0f), y, 1.0f, 1.0f);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (D_800D19F0 * 0.0f), y, 1.0f, 1.0f);
            break;

        case 2:
            for (i = D_800D19F4; i >= 0; i--) {
                if (i == 0) {
                    temp = D_800D19F0 * 4.0f;
                } else {
                    temp = D_800D19F0;
                }
                TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (30.0f - (i * 10)) + temp, y, 1.0f,
                                1.0f);
            }
            break;

        case 3:
            for (i = (D_800D19F4 - 2); i >= 0; i--) {
                TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + (30.0f - (i * 10)), y, 1.0f, 1.0f);
            }
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + 50.0f - D_800D19F0, y, 1.0f, 1.0f);
            break;

        case 4:
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + 30.0f - (D_800D19F0 * 3.0f), y, 1.0f, 1.0f);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + 20.0f - (D_800D19F0 * 2.0f), y, 1.0f, 1.0f);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x + 10.0f - (D_800D19F0 * 1.0f), y, 1.0f, 1.0f);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x, y, 1.0f, 1.0f);
            break;

        case 5:
            func_hud_8008DCB0(x + D_800D19F0, y + 2.0f, D_8016177C, D_80161780, D_80161784);
            func_hud_8008DD78(x + 15.0f + D_800D19F0, y + 1.0f, D_800D19F4, D_8016177C, D_80161780, D_80161784);
            TextureRect_CI4(&gMasterDisp, D_10116B0, D_1011730, 16, 16, x, y, 1.0f, 1.0f);
            break;

        case 6:
            RCP_SetupDL(&gMasterDisp, SETUPDL_78);
            gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
            TextureRect_CI4(&gMasterDisp, D_blue_marine_3000090, D_blue_marine_3000120, 32, 9, x + 1.0f, y, 1.0f, 1.0f);
            break;
    }
    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_NONE, 0, 0);
}
#endif

#if 0 // HUD_EdgeArrows_Draw *perspective

void Matrix_RotateZ(Matrix* mtx, f32 angle, u8 mode);

extern Gfx D_1024990[];

#define LEFT_SIDE_INDEX 0  // Index for the left arrow
#define RIGHT_SIDE_INDEX 1 // Index for the right arrow

RECOMP_PATCH void func_hud_8008C6F4(s32 idx, s32 arg1) {
    static const f32 D_800D1EF8[] = { 0.0f, 0.0f, -9.0f, 9.0f, 10.0f, 10.0f, 10.0f, 10.0f, 0.0f, 0.0f, -8.0f, 8.0f };
    static const f32 D_800D1F28[] = { -7.0f, 7.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 8.0f, -8.0f, 0.0f, 0.0f };
    static const f32 D_800D1F58[] = { -22.0f, -22.0f, -22.0f, -22.0f, -28.0f, -28.0f, -28.0f, -28.0f, -28.0f, -28.0f, -28.0f, -28.0f};
    static const f32 D_800D1F88[] = { 0.0f, 0.0f, 0.0f, 0.0f, 495.0f, 405.0f, 585.0f, 675.0f, 0.0f, 0.0f, 0.0f, 0.0f };
    static const f32 D_800D1FB8[] = { 180.0f, 0.0f, 270.0f, 90.0f, 270.0f, 270.0f, 270.0f, 270.0f, 0.0f, 180.0f, 90.0f, 270.0f };
    static const f32 D_800D1FE8[] = { 0.0f, 0.0f, 2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, 0.0f, 0.0f, 2.0f, -2.0f };
    static const f32 D_800D2018[] = { 2.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -2.0f, 2.0f, 0.0f, 0.0f };

    // Initialize the viewport and set the scissor box
    //Game_InitFullViewport();
    //gEXSetScissor(gMasterDisp++, G_SC_NON_INTERLACE, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    Matrix_Push(&gGfxMatrix);

    // Apply camera roll if in alternate view
    if (gPlayer[0].alternateView) {
        Matrix_RotateZ(gGfxMatrix, M_DTOR * gPlayer[0].camRoll, MTXF_APPLY);
    }

    // Rotate the matrix based on pre-defined angles
    if (D_800D1F88[idx]) {
        Matrix_RotateZ(gGfxMatrix, M_DTOR * D_800D1F88[idx], MTXF_APPLY);
    }

    // Determine if the arrow should be aligned left, right, or neither
    if (idx == LEFT_SIDE_INDEX) {
        // Align the viewport to the left
        gEXViewport(gMasterDisp++, G_EX_ORIGIN_LEFT, gViewport);
    } else if (idx == RIGHT_SIDE_INDEX) {
        // Align the viewport to the right
        gEXViewport(gMasterDisp++, G_EX_ORIGIN_RIGHT, gViewport);
    } else {
        // Default alignment (e.g., for up or down arrows)
        gEXViewport(gMasterDisp++, G_EX_ORIGIN_NONE, gViewport);
    }

    // Apply translation with or without the `arg1` offset
    if (arg1 != 0) {
        Matrix_Translate(gGfxMatrix, D_800D1EF8[idx] + D_800D1FE8[idx], D_800D1F28[idx] + D_800D2018[idx], D_800D1F58[idx], MTXF_APPLY);
    } else {
        Matrix_Translate(gGfxMatrix, D_800D1EF8[idx], D_800D1F28[idx], D_800D1F58[idx], MTXF_APPLY);
    }

    // Apply rotation and scaling
    Matrix_RotateZ(gGfxMatrix, M_DTOR * D_800D1FB8[idx], MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, 0.026f, 0.026f, 0.026f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);

    // Render the arrow
    RCP_SetupDL(&gMasterDisp, SETUPDL_62);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 150);
    gSPDisplayList(gMasterDisp++, D_1024990);

    // Restore matrix stack
    Matrix_Pop(&gGfxMatrix);

    // Reset the viewport and scissor box after rendering the arrow
    gEXViewport(gMasterDisp++, G_EX_ORIGIN_NONE, gViewport);
    gEXSetScissor(gMasterDisp++, G_SC_NON_INTERLACE, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
#endif

#if 1 // Radar

void func_hud_8008DC34(void);
void func_hud_8008A4DC(void);

RECOMP_PATCH void func_hud_8008E5E8(void) {
    Game_InitFullViewport();
    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, G_EX_ORIGIN_RIGHT, -(SCREEN_WIDTH) * 4, 0, -(SCREEN_WIDTH) * 4,
                    0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_RIGHT, -SCREEN_WIDTH * 4, 0);
    gSPViewport(gMasterDisp++, gViewport);

    if (gVersusMode) {
        func_hud_8008DC34();
    }
    func_hud_8008A4DC();

    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_NONE, SCREEN_WIDTH, SCREEN_HEIGHT);
    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
}
#endif

#endif
