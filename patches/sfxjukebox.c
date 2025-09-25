
#include "patches.h"
#include "fox_map.h"
#include "sf64audio_provisional.h"

#if DEBUG_SFX_JUKEBOX == 1

extern s32 sSpectrumAnalyzerMode;
extern bool sMusicPlaying;
extern bool sMainMenuFromCancel;
extern s32 sMenuEntryState;
extern s32 sMainMenuState;

static s32 showJukebox = 0;
static u32 prevSfx = NA_SE_NONE;
static u32 sfx = NA_SE_NONE;
static s32 sfxId = 0;
static u32 sfxBank = SFX_BANK_PLAYER;
static u32 sfxRange = 0;
static s32 sfxImport = 0;
static int holdTimer = 0;
static u8 sfxFlag = 0;
static u8 sfxFlags[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
static char* flagNames[] = { "F18", "F19", "F20", "F21", "F22", "F23", "STT", "F25", "F26", "SFX" };
static u8 bankSizes[] = { 0x33, 0x85, 0x9C, 0x9C, 0x37 };
static u32 sfxEditMode = 9;
static u32 srcEditMode = 0;
static u32 editMode = 0;
static s32 srcVec[3] = { 0, 0, 0 };
static f32 sfxSource[3] = { 0.0f, 0.0f, 0.0f };
static OSContPad* contPress;
static OSContPad* contHold;

void Jukebox_SelectFlag(u8* flag) {
    if (contPress->button & (U_CBUTTONS | D_CBUTTONS | R_CBUTTONS | L_CBUTTONS)) {
        *flag ^= 1;
    }
}

void Jukebox_SelectWrap(u32* option, s32 range) {
    if (contPress->button & (U_CBUTTONS | R_CBUTTONS)) {
        (*option)++;
    } else if (contPress->button & (D_CBUTTONS | L_CBUTTONS)) {
        (*option)--;
    }
    *option = (*option + range) % range;
}

void Jukebox_SelectClamp(s32* option, s32 range, s32 skip) {
    if (contHold->button & (U_CBUTTONS | D_CBUTTONS)) {
        holdTimer++;
    } else {
        holdTimer = 0;
    }

    if (((contHold->button & U_CBUTTONS) && (holdTimer > 15)) || (contPress->button & U_CBUTTONS)) {
        (*option)++;
    } else if (((contHold->button & D_CBUTTONS) && (holdTimer > 15)) || (contPress->button & D_CBUTTONS)) {
        (*option)--;
    } else if (contPress->button & L_CBUTTONS) {
        *option -= skip;
    } else if (contPress->button & R_CBUTTONS) {
        *option += skip;
    }
    if (*option < 0) {
        *option = 0;
    } else if (*option >= range) {
        *option = range - 1;
    }
}

void Jukebox_UpdateSource(void) {
    if (contPress->button & L_JPAD) {
        srcEditMode--;
    } else if (contPress->button & R_JPAD) {
        srcEditMode++;
    }
    srcEditMode = (srcEditMode + 3) % 3;

    if (contHold->button & (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS)) {
        holdTimer++;
    } else {
        holdTimer = 0;
    }

    if (((contHold->button & U_CBUTTONS) && (holdTimer > 15)) || (contPress->button & U_CBUTTONS)) {
        sfxSource[srcEditMode] += 100.0f;
    } else if (((contHold->button & D_CBUTTONS) && (holdTimer > 15)) || (contPress->button & D_CBUTTONS)) {
        sfxSource[srcEditMode] -= 100.0f;
    } else if (((contHold->button & R_CBUTTONS) && (holdTimer > 15)) || (contPress->button & R_CBUTTONS)) {
        sfxSource[srcEditMode] += 10.0f;
    } else if (((contHold->button & L_CBUTTONS) && (holdTimer > 15)) || (contPress->button & L_CBUTTONS)) {
        sfxSource[srcEditMode] -= 10.0f;
    }
}

void Jukebox_UpdateSfx(void) {
    s32 i;
    u16 flags = 0;

    if (contPress->button & L_JPAD) {
        sfxEditMode--;
    } else if (contPress->button & R_JPAD) {
        sfxEditMode++;
    }
    sfxEditMode = (sfxEditMode + 13) % 13;
    switch (sfxEditMode) {
        case 9:
            Jukebox_SelectWrap(&sfxBank, 5);
            break;
        case 10:
            Jukebox_SelectClamp(&sfxId, bankSizes[sfxBank], 0x10);
            break;
        case 11:
            Jukebox_SelectFlag(&sfxFlag);
            break;
        case 12:
            Jukebox_SelectWrap(&sfxRange, 4);
            break;
        case 8:
            Jukebox_SelectClamp(&sfxImport, 0x100, 0x10);
            break;
        default:
            if ((sfxEditMode >= 0) && (sfxEditMode < 8)) {
                Jukebox_SelectFlag(&sfxFlags[sfxEditMode]);
            }
            break;
    }
    for (i = 0; i < 8; i++) {
        flags |= sfxFlags[i] << (i + (i > 5));
    }
    sfx = SFX_PACK(sfxBank, sfxId, sfxRange, sfxImport, (sfxFlag << 27) | (flags << 18));
}

s32 sfxModeX[] = { 95, 104, 113, 122, 131, 140, 149, 158, 180, 0, 22, 43, 60 };
s32 srcModeX[] = { 45, 135, 225 };

void Jukebox_Update(void) {
    s32 i;

    contPress = &gControllerPress[gMainController];
    contHold = &gControllerHold[gMainController];

    if (contPress->button & U_JPAD) {
        editMode--;
    } else if (contPress->button & D_JPAD) {
        editMode++;
    }
    editMode %= 2;
    switch (editMode) {
        case 0:
            Jukebox_UpdateSfx();
            break;
        case 1:
            Jukebox_UpdateSource();
            break;
    }

    if (prevSfx != sfx) {
        AUDIO_PLAY_SFX(NA_SE_CURSOR, gDefaultSfxSource, 4);
        prevSfx = sfx;
    }

    if (contPress->button & A_BUTTON) {
        SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 1);
        SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 1);
        AUDIO_PLAY_SFX(sfx, sfxSource, 4);
        sMusicPlaying = true;
    }

    if (contPress->button & B_BUTTON) {
        if (!sMusicPlaying) {
            AUDIO_PLAY_SFX(NA_SE_ARWING_CANCEL, gDefaultSfxSource, 4);
            AUDIO_PLAY_BGM(NA_BGM_SELECT);
            gDrawMode = DRAW_NONE;
            sMenuEntryState = 1000;
            sMainMenuState = 0;
            sMainMenuFromCancel = 1;
            return;
        } else {
            AUDIO_PLAY_SFX(NA_SE_CANCEL, gDefaultSfxSource, 4);
            Audio_KillSfxBySource(sfxSource);
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 1);
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 1);
            sMusicPlaying = false;
        }
    }

    // Spectrum Analyzer mode selector
    if (contPress->button & Z_TRIG) {
        sSpectrumAnalyzerMode++;
        if (sSpectrumAnalyzerMode > 2) {
            sSpectrumAnalyzerMode = 0;
        }
    }

    /* Draw */

    RCP_SetupDL(&gMasterDisp, SETUPDL_83);
    gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 0, 255);

    Graphics_Printf("SFX ID: %08X", sfx);
    Graphics_DisplaySmallText(20, 50, 1.0f, 1.0f, gGfxPrintBuffer);
    Graphics_DisplaySmallText(20, 80, 1.0f, 1.0f, "B ID  X R S    FLAG   IMP");
    Graphics_Printf("%d %02X %d %d %d %d%d%d%d%d%d%d%d %02X", sfxBank, sfxId, sfxFlag, sfxRange, 1, sfxFlags[0],
                    sfxFlags[1], sfxFlags[2], sfxFlags[3], sfxFlags[4], sfxFlags[5], sfxFlags[6], sfxFlags[7],
                    sfxImport);
    Graphics_DisplaySmallText(20, 70, 1.0f, 1.0f, gGfxPrintBuffer);

    // Graphics_DisplaySmallText(80, 50, 1.0f, 1.0f, hexString);
    for (i = 0; i < 3; i++) {
        Graphics_Printf("%5.0f", sfxSource[i]);
        Graphics_DisplaySmallText(20 + 90 * i, 100, 1.0f, 1.0f, gGfxPrintBuffer);
    }
    Graphics_DisplaySmallText(45, 110, 1.0f, 1.0f, "X");
    Graphics_DisplaySmallText(135, 110, 1.0f, 1.0f, "Y");
    Graphics_DisplaySmallText(225, 110, 1.0f, 1.0f, "Z");
    switch (editMode) {
        case 0:
            Graphics_DisplaySmallText(20 + sfxModeX[sfxEditMode], 60, 1.0f, 1.0f, "V");
            break;
        case 1:
            Graphics_DisplaySmallText(45 + 90 * srcEditMode, 90, 1.0f, 1.0f, "V");
            break;
    }
}

// Patches

typedef struct {
    s32 unk_0;
    s32 unk_4;
} StickInput;

extern s32 D_menu_801B931C;
extern StickInput D_menu_801B9290;

bool Option_Input_Sound_X(f32 *arg0, f32 arg1, f32 arg2, StickInput *arg3);

// Expert Sound Options
RECOMP_PATCH void Option_ExpertSound_Update(void) {
    s32 pad;
    f32 sp28 = D_menu_801B931C;

    if (gControllerPress[gMainController].button & L_TRIG) {
        showJukebox ^= 1;
    }
    if (showJukebox) {
        Jukebox_Update();
        return;
    }

    if (Option_Input_Sound_X(&sp28, 0.0f, 49.0f, &D_menu_801B9290) != 0) {
        AUDIO_PLAY_SFX(NA_SE_CURSOR, gDefaultSfxSource, 4);
        D_menu_801B931C = sp28;
    }

    if (gControllerPress[gMainController].button & A_BUTTON) {
        Audio_PlaySoundTestTrack(D_menu_801B931C);
        sMusicPlaying = true;
    }

    if (gControllerPress[gMainController].button & B_BUTTON) {
        if (!sMusicPlaying) {
            AUDIO_PLAY_SFX(NA_SE_ARWING_CANCEL, gDefaultSfxSource, 4);
            AUDIO_PLAY_BGM(NA_BGM_SELECT);
            gDrawMode = DRAW_NONE;
            sMenuEntryState = 1000;
            sMainMenuState = 0;
            sMainMenuFromCancel = true;
        } else {
            AUDIO_PLAY_SFX(NA_SE_CANCEL, gDefaultSfxSource, 4);
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 1);
            SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 1);
            sMusicPlaying = false;
        }
    }

    // Spectrum Analyzer mode selector
    if (gControllerPress[gMainController].button & R_CBUTTONS) {
        sSpectrumAnalyzerMode++;
        if (sSpectrumAnalyzerMode > 2) {
            sSpectrumAnalyzerMode = 0;
        }
    }
}

extern f32 D_menu_801B9298[32];
extern Gfx D_menu_801AEC30[3];
extern Gfx D_menu_801AEC88[3];
extern Gfx D_menu_801AECE0[3];
extern u8 *D_menu_801AECF8[10];

void Option_DrawMenuLabel(void);
void Option_AcceptCancel_Draw(void);

RECOMP_PATCH void Option_ExpertSound_Draw(void) {
    u8* temp_v0_4;
    f32 var_fs0;
    f32 var_fv1;
    s32 i;
    f32 r;
    f32 g;
    f32 b;
    static f32 D_menu_801AF004 = -125.0f;
    static f32 D_menu_801AF008 = 0.0f;
    static f32 D_menu_801AF00C = 2.0f;
    static f32 D_menu_801AF010 = 8.0f;
    static f32 D_menu_801AF014[4] = { 30.0f, 30.0f, 28.0f, 288.0f };
    static f32 D_menu_801AF024[4] = { 125.0f, 197.0f, 125.0f, 125.0f };
    static f32 D_menu_801AF034[4] = { 32.3f, 32.3f, 0.2f, 0.2f };
    static f32 D_menu_801AF044[4] = { 0.2f, 0.2f, 9.2f, 9.2f };
    static f32 D_menu_801AF054 = 255.0f;
    static f32 D_menu_801AF058 = 100.0f;
    static f32 D_menu_801AF05C = 255.0f;
    static f32 D_menu_801AF060 = 100.0f;
    static f32 D_menu_801AF064 = 255.0f;
    static f32 D_menu_801AF068 = 100.0f;
    static Gfx* D_menu_801AF06C[] = {
        D_menu_801AEC30,
        D_menu_801AEC88,
        D_menu_801AECE0,
    };
    static f32 D_menu_801AF078[] = { -73.0f, -13.0f, -43.0f };

    Option_DrawMenuLabel();

    if (!showJukebox) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_83);

        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);

        Lib_TextureRect_IA8(&gMasterDisp, D_OPT_80079F0, 128, 14, 49.0f, 81.0f, 1.0f, 1.0f);

        Lib_TextureRect_IA8(&gMasterDisp, D_menu_801AECF8[D_menu_801B931C / 10], 16, 15, 230.0f, 82.0f, 1.0f, 1.0f);

        Lib_TextureRect_IA8(&gMasterDisp, D_menu_801AECF8[D_menu_801B931C % 10], 16, 15, 244.0f, 82.0f, 1.0f, 1.0f);
    }

    Option_AcceptCancel_Draw();

    RCP_SetupDL(&gMasterDisp, SETUPDL_76);

    gDPSetPrimColor(gMasterDisp++, 0, 0, 50, 50, 200, 255);

    for (i = 0; i < 4; i++) {
        Lib_TextureRect_RGBA16(&gMasterDisp, aMapWhiteSquareTex, 8, 8, D_menu_801AF014[i], D_menu_801AF024[i],
                               D_menu_801AF034[i], D_menu_801AF044[i]);
    }

    if (sMusicPlaying) {
        temp_v0_4 = Audio_UpdateFrequencyAnalysis();
        var_fv1 = 60.0f;

        if (sSpectrumAnalyzerMode == 2) {
            var_fv1 = 30.0f;
        }

        for (i = 0; i < ARRAY_COUNT(D_menu_801B9298); i++) {
            if ((sSpectrumAnalyzerMode == 0) || (sSpectrumAnalyzerMode == 2)) {
                D_menu_801B9298[i] = (var_fv1 / 255.0f) * temp_v0_4[i];
            } else {
                D_menu_801B9298[i] = var_fv1 - ((var_fv1 / 255.0f) * temp_v0_4[i]);
            }
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(D_menu_801B9298); i++) {
            Math_SmoothStepToF(&D_menu_801B9298[i], 0.0f, 0.2f, 100.0f, 0.1f);
        }
    }

    Lib_InitOrtho(&gMasterDisp);

    RCP_SetupDL(&gMasterDisp, SETUPDL_5);

    Matrix_Push(&gGfxMatrix);
    Matrix_LookAt(gGfxMatrix, 0.0f, 0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);

    for (var_fs0 = D_menu_801AF004, i = 0; i < ARRAY_COUNT(D_menu_801B9298); i++, var_fs0 += D_menu_801AF010) {
        r = D_menu_801AF054 + ((D_menu_801AF060 - D_menu_801AF054) / 31.0f) * i;
        g = D_menu_801AF058 + ((D_menu_801AF064 - D_menu_801AF058) / 31.0f) * i;
        b = D_menu_801AF05C + ((D_menu_801AF068 - D_menu_801AF05C) / 31.0f) * i;

        gDPSetPrimColor(gMasterDisp++, 0, 0, (s32) r, (s32) g, (s32) b, 255);

        Matrix_Push(&gGfxMatrix);
        Matrix_Translate(gGfxMatrix, var_fs0, D_menu_801AF078[sSpectrumAnalyzerMode], D_menu_801AF008, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, D_menu_801AF00C, D_menu_801B9298[i], 1.0f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);

        gSPDisplayList(gMasterDisp++, D_menu_801AF06C[sSpectrumAnalyzerMode]);

        Matrix_Pop(&gGfxMatrix);
    }

    Matrix_Pop(&gGfxMatrix);
    Lib_InitPerspective(&gMasterDisp);
}
#endif
