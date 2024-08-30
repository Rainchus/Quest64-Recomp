#if 0

#include "patches.h"

#include "rt64_extended_gbi.h"

void func_hud_800856C0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_hud_80085618(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_hud_800855C4(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_hud_8008566C(f32 x, f32 y, f32 arg2, f32 arg3);

// This moves elements towards the screen edges when increased
s32 margin_reduction = 0;

RECOMP_PATCH void func_hud_80086110(f32 arg0, f32 arg1, s32 arg2) {
    f32 temp = 0.82f;
    s32 pad;

    // gEXEnable(gMasterDisp++);
    // gEXSetScissorAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_RIGHT, 0, -margin_reduction, -SCREEN_WIDTH,
    //                    margin_reduction, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    // gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, -margin_reduction * 4,
    //                     -margin_reduction * 4, -margin_reduction * 4, -margin_reduction * 4);
    RCP_SetupDL(&gMasterDisp, SETUPDL_75);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);

    if (arg2 != 0) {
        func_hud_800856C0((8.0f * temp) + arg0, arg1 + 2.0f, temp, 1.0f, arg2 / 255.0f);
    }

    if ((arg2 <= 0) && (arg2 != -2) &&
        ((gPlayState == PLAY_PAUSE) || (gShowLevelClearStatusScreen == 1) || (gLevelStartStatusScreenTimer != 0))) {
        // gEXEnable(gMasterDisp++);
        // gEXSetScissorAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_RIGHT, 0, -margin_reduction, -SCREEN_WIDTH,
        //                    margin_reduction, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        // gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, -margin_reduction * 4,
        //                 -margin_reduction * 4, -margin_reduction * 4, -margin_reduction * 4);
        RCP_SetupDL(&gMasterDisp, SETUPDL_76);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 0, 255);
        if ((arg2 == 0) && (gPlayer[0].state_1C8 == PLAYERSTATE_1C8_LEVEL_COMPLETE)) {
            Graphics_DisplaySmallText(arg0 + (8.0f * temp) + 4.0f, arg1 + 2.0f, 1.0f, 1.0f, " OK ");
        } else {
            Graphics_DisplaySmallText(arg0 + (8.0f * temp) + 4.0f, arg1 + 2.0f, 1.0f, 1.0f, "DOWN");
        }
    }

    // gEXEnable(gMasterDisp++);
    // gEXSetScissorAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_RIGHT, 0, -margin_reduction, -SCREEN_WIDTH,
    //                    margin_reduction, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    // gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, -margin_reduction * 4,
    //                     -margin_reduction * 4, -margin_reduction * 4, -margin_reduction * 4);
    RCP_SetupDL(&gMasterDisp, SETUPDL_76);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
    func_hud_80085618(arg0, arg1, temp, 1.0f);
    func_hud_800855C4(arg0 + (7.0f * temp) + (temp * 6.0f) * 8.0f, arg1, 1.0f, 1.0f);
    func_hud_8008566C(arg0 + (7.0f * temp), arg1, temp * 6.0f, 1.0f);
}

extern f32 D_801617A8;
extern f32 D_801617AC;
extern s32 D_800D1EB4;
extern s32 D_800D1EB8;
extern s32 D_800D1EBC;


RECOMP_PATCH void func_hud_8008B5B0(f32 x, f32 y) {
    gEXEnable(gMasterDisp++);
    gEXSetScissor(gMasterDisp++, G_SC_NON_INTERLACE, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_RIGHT, 0, 0, 0, SCREEN_HEIGHT);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, -margin_reduction * 4, -margin_reduction * 4);
    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, -margin_reduction * 4, -margin_reduction * 4,
                    -margin_reduction * 4, -margin_reduction * 4);
    RCP_SetupDL(&gMasterDisp, SETUPDL_75);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
    func_hud_800856C0(x + 8.0f, y + 2.0f, D_801617A8, 1.0f, D_801617AC);
    RCP_SetupDL(&gMasterDisp, SETUPDL_76);
    gDPSetPrimColor(gMasterDisp++, 0, 0, D_800D1EB4, D_800D1EB8, D_800D1EBC, 255);
    func_hud_80085618(x, y, 1.0f, 1.0f);
    func_hud_800855C4(x + 7.0f + (D_801617A8 * 6.0f * 8.0f), y, 1.0f, 1.0f);
    func_hud_8008566C(x + 7.0f, y, D_801617A8 * 6.0f, 1.0f);
    gEXSetRectAlign(gMasterDisp++, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
    gEXSetViewportAlign(gMasterDisp++, G_EX_ORIGIN_NONE, 0, 0);
    gDPSetScissor((gMasterDisp)++, G_SC_NON_INTERLACE, SCREEN_MARGIN, SCREEN_MARGIN, SCREEN_WIDTH - SCREEN_MARGIN,
                  SCREEN_HEIGHT - SCREEN_MARGIN);
}

#endif
