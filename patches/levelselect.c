#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/sf64math.h"
#include "../lib/sf64decomp/include/fox_map.h"
#include "../lib/sf64decomp/include/context.h"
#include "../lib/sf64decomp/include/PR/os_cont.h"
#include "patches.h"

extern PlanetId sPlanetList[15];
extern PlanetId sCurrentPlanetId;
extern OSContPad gControllerPress[4];
extern s32 gBombCount[4];
extern bool sLevelStartState;
extern s32 D_menu_801CD968;
extern s32 sMapState;
extern s32 sMapSubState;
extern f32 sMapCamAtX;
extern f32 sMapCamAtY;
extern f32 sMapCamAtZ;
extern f32 sMapCamEyeX;
extern f32 sMapCamEyeY;
extern f32 sMapCamEyeZ;
extern f32 D_menu_801CDA0C;
extern f32 D_menu_801CDA18;
extern f32 D_menu_801CDA14;
extern f32 D_menu_801CDA10;
extern f32 D_menu_801CDA1C;

void Map_LevelStart_AudioSpecSetup(LevelId level);
void Map_CurrentLevel_Setup(void);
void Map_PositionCursor(void);
void Map_PlayLevel(void);
void Map_SetCamRot(f32, f32, f32, f32*, f32*, f32*, f32, f32, f32);
void Map_PositionPlanets(void);
void Map_PlanetOrderZpos(void);
void Map_Fade_Update(void);
void Map_Prologue_Update(void);
void Map_LylatCard_Update(void);
void Map_Idle_Update(void);
void Map_ZoomPlanet_Update(void);
void Map_LevelStart_Update(void);
void Map_ZoomPlanetPath_Update(void);
void Map_PathChange_Update(void);
void Map_GameOver_Update(void);

PlanetId sPlanetArray[][3] = {
    { PLANET_CORNERIA, PLANET_CORNERIA, PLANET_CORNERIA }, { PLANET_METEO, PLANET_METEO, PLANET_SECTOR_Y },
    { PLANET_FORTUNA, PLANET_KATINA, PLANET_AQUAS },       { PLANET_SECTOR_X, PLANET_SOLAR, PLANET_ZONESS },
    { PLANET_TITANIA, PLANET_MACBETH, PLANET_SECTOR_Z },   { PLANET_BOLSE, PLANET_BOLSE, PLANET_AREA_6 },
    { PLANET_VENOM, PLANET_VENOM, SAVE_SLOT_VENOM_2 },
};

void Map_LevelSelect(void) {
    static s32 mission = 0;
    static s32 difficulty = 0;
    static char* sLevelSelectPlanetNames[] = {
        "METEO",  "AREA 6",   "BOLSE",   "SECTOR Z", "SECTOR X", "SECTOR Y", "KATINA", "MACBETH",
        "ZONESS", "CORNERIA", "TITANIA", "AQUAS",    "FORTUNA",  "VENOM 1",  "SOLAR",  "VENOM 2",
    };
    static s32 startOption = 0;
    static s32 timer = 30;
    static s32 startLevel = 0;

    timer--;

    // static f32 zStart = 0.0f;
    // f32 zInc;
    s32 nextPlanetId;
    OSContPad* contPress = &gControllerPress[gMainController];

    if (contPress->button & L_JPAD) {
        mission--;
        if (mission < 0) {
            mission = 6;
        }
    } else if (contPress->button & R_JPAD) {
        mission++;
        if (mission > 6) {
            mission = 0;
        }
    } else if ((contPress->button & U_JPAD) && (mission != 0)) {
        difficulty++;
        if (difficulty > 2) {
            difficulty = 0;
        }
        if ((difficulty == 1) && ((mission == 1) || (mission == 5) || (mission == 6))) {
            difficulty = 2;
        }
    } else if ((contPress->button & D_JPAD) && (mission != 0)) {
        difficulty--;
        if ((difficulty != 2) && ((mission == 1) || (mission == 5) || (mission == 6))) {
            difficulty--;
        }
        if (difficulty < 0) {
            difficulty = 2;
        }
    }

    nextPlanetId =
        (sPlanetArray[mission][difficulty] == SAVE_SLOT_VENOM_2) ? PLANET_VENOM : sPlanetArray[mission][difficulty];
    if (sCurrentPlanetId != nextPlanetId) {
        sCurrentPlanetId = nextPlanetId;
        startOption = 0;
        Map_CurrentLevel_Setup();
        Map_PositionCursor();
    }
    if (contPress->button & L_TRIG) {
        startOption ^= 1;
    }

    int y = 225;

    /* Draw */
    if ((sCurrentPlanetId >= 0) && (sCurrentPlanetId < PLANET_MAX)) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_83);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 0, 255);

        Graphics_DisplaySmallText(20, y, 1.0f, 1.0f, "PLANET:");
        Graphics_DisplaySmallText(80, y, 1.0f, 1.0f, sLevelSelectPlanetNames[sPlanetArray[mission][difficulty]]);

        if (startOption) {
            if ((sCurrentPlanetId == PLANET_SECTOR_X) || (sCurrentPlanetId == PLANET_METEO)) {
                Graphics_DisplaySmallText(80 + 60 + 10, y, 1.0f, 1.0f, "WARP ZONE");
            } else if (sCurrentPlanetId == PLANET_VENOM) {
                Graphics_DisplaySmallText(80 + 60 + 3, y, 1.0f, 1.0f, "ANDROSS");
            } else if (sCurrentPlanetId == PLANET_AREA_6) {
                Graphics_DisplaySmallText(80 + 60 - 3, y, 1.0f, 1.0f, "BETA SB");
            }
        }
    }

    if (gControllerPress[0].button & A_BUTTON) {
        timer = 15;
        startLevel = 1;
    }

    // Bypass briefing
    #if DEBUG_SKIP_BRIEFING
    if ((timer == 0) && (startLevel == 1)) {
        if ((sMapState == 2) && (sMapSubState > 0)) {
            if (sCurrentPlanetId == PLANET_VENOM) {
                if (startOption) {
                    gCurrentLevel = LEVEL_VENOM_ANDROSS;
                } else if (sPlanetArray[mission][difficulty] == SAVE_SLOT_VENOM_2) {
                    gCurrentLevel = LEVEL_VENOM_2;
                }
            } else if ((sCurrentPlanetId == PLANET_AREA_6) && startOption) {
                gCurrentLevel = LEVEL_UNK_4;
            }
            Map_LevelStart_AudioSpecSetup(gCurrentLevel);
            sLevelStartState = 0;
            D_menu_801CD968 = 0;
            Map_PlayLevel();
            if (startOption && ((gCurrentLevel == LEVEL_METEO) || (gCurrentLevel == LEVEL_SECTOR_X) ||
                                (sPlanetArray[mission][difficulty] == SAVE_SLOT_VENOM_2))) {
                gLevelPhase = 1;
            }
        }
    }
    #endif
}

RECOMP_PATCH void Map_Update(void) {

    Map_PositionPlanets();
    Map_PlanetOrderZpos();
    Map_Fade_Update();

    switch (sMapState) {
        case 0:
            Map_Prologue_Update();
            gStarfieldScrollX += 0.09f;
            break;

        case 1:
            Map_LylatCard_Update();
            D_menu_801CDA1C += 0.03f;
            break;

        case 3:
            Map_Idle_Update();
            D_menu_801CDA1C += 0.03f;
            break;

        case 2:
            Map_ZoomPlanet_Update();
            break;

        case 4:
            Map_LevelStart_Update();
            break;

        case 5:
            Map_ZoomPlanetPath_Update();
            break;

        case 6:
            Map_PathChange_Update();
            break;

        case 7:
            Map_GameOver_Update();
            break;

        default:
            break;
    }

    if ((sMapState == 0) || (sMapState == 1) || (sMapState == 7) || (sMapState == 3)) {
        Map_SetCamRot(sMapCamAtX, sMapCamAtY, sMapCamAtZ, &sMapCamEyeX, &sMapCamEyeY, &sMapCamEyeZ, D_menu_801CDA14,
                      D_menu_801CDA0C + D_menu_801CDA18, D_menu_801CDA10 + D_menu_801CDA1C);
        Camera_SetStarfieldPos(sMapCamEyeX, sMapCamEyeY, sMapCamEyeZ, sMapCamAtX, sMapCamAtY, sMapCamAtZ);
    }
    gGameFrameCount++;

#if DEBUG_LEVEL_SELECT == 1
    if ((sMapState == MAP_IDLE) || (sMapState == MAP_ZOOM_PLANET)) {
        Map_LevelSelect();
    }
#endif
}
