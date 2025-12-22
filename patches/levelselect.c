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
extern s32 sPrologueTexIdx;
extern f32 sPrologueTextXpos;
extern f32 sPrologueTextYpos;
extern f32 sPrologueNextTexAlpha;
extern f32 sPrologueCurrentTexAlpha;
extern f32 sPrologueTextScrollSpeed;
extern s32 sPrologueTexIdx;
extern s32 sMapTimer3;
extern s32 D_menu_801CD970;
extern s32 D_menu_801CD97C;
extern Planet sPlanets[PLANET_MAX];
extern s32 D_menu_801CEFD4;
extern s32 D_menu_801CEFDC;
extern s32 D_menu_801CD94C;
extern s32 D_menu_801CEFD0;
extern s32 D_menu_801CF010;
extern s32 D_menu_801CF014;
extern MissionStatus sPrevMissionStatus;

void Map_SetState_ZoomPlanet(void);
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
void Audio_ClearVoice(void);
void Audio_PlayVoiceWithoutBGM(u32);

bool gBackToMap = false;

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

    if (timer > 0) {
        timer--;
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

#if DEBUG_LEVEL_SELECT == 1
RECOMP_PATCH void Map_Prologue_Update(void) {
    PlanetId planetId;
    static f32 D_menu_801B6934[] = {
        99.0f, 24, -90.0f, -150.0f, -208.0f, -276.0f,
    };

    switch (sMapSubState) {
        case 100:
            break;

        case 0:
            sPrologueTexIdx = 0;
            sPrologueTextXpos = 30.0f;
            sPrologueTextYpos = 230.0f;
            sPrologueCurrentTexAlpha = 0;
            sPrologueNextTexAlpha = 0;
            sPrologueTextScrollSpeed = 0.29f;
            gStarCount = 800;
            sMapTimer3 = 5;
            sMapSubState++;
            break;

        case 1:
            if ((sMapTimer3 == 0) && (gFillScreenAlpha == 0)) {
                if ((s32) sPrologueTextYpos == 205) {
                    Audio_PlayVoiceWithoutBGM(1000);
                }

                if (sPrologueTextYpos > -355.0f) {
                    sPrologueTextYpos -= sPrologueTextScrollSpeed;
                }

                if ((sPrologueTextYpos < 200.0f) && (sPrologueCurrentTexAlpha != 255)) {
                    sPrologueCurrentTexAlpha += 8;
                    if (sPrologueCurrentTexAlpha > 255) {
                        sPrologueCurrentTexAlpha = 255;
                    }
                }

                if (sPrologueTextYpos < D_menu_801B6934[sPrologueTexIdx]) {
                    sPrologueNextTexAlpha += 8;
                    if (sPrologueNextTexAlpha > 255) {
                        sPrologueNextTexAlpha = 255;
                    }
                }

                if (sPrologueTextYpos <= -355.0f) {
                    sMapSubState++;
                }
            }
            break;

        case 2:
            sPrologueCurrentTexAlpha -= 16;
            if (sPrologueCurrentTexAlpha < 0) {
                sPrologueCurrentTexAlpha = 0;
                sMapSubState++;
                sMapTimer3 = 20;
            }
            break;

        case 3:
            if (sMapTimer3 == 0) {
                sMapSubState = 0;
                sMapState = MAP_LYLAT_CARD;
            }
            break;
    }

    // @recomp: "|| gBackToMap" and "gBackToMap = false;"
    // Skip prologue if we're coming back from a level.
    if (gControllerPress[gMainController].button & START_BUTTON || gBackToMap) { // @recomp
        gBackToMap = false;                                                      // @recomp
        AUDIO_PLAY_BGM(NA_BGM_MAP);
        AUDIO_PLAY_SFX(NA_SE_MAP_MOVE_STOP, gDefaultSfxSource, 4);

        for (planetId = 0; planetId < PLANET_MAX; planetId++) {
            if ((planetId == PLANET_SECTOR_Z) || (planetId == PLANET_SECTOR_X) || (planetId == PLANET_SECTOR_Y)) {
                sPlanets[planetId].alpha = 144;
            } else {
                sPlanets[planetId].alpha = 255;
            }
            D_menu_801CD900[planetId] = 255;
        }

        D_menu_801CD970 = 255;

        Audio_ClearVoice();

        D_menu_801CD974 = 1;
        D_menu_801CD97C = 1;
        sMapSubState = 0;
        sMapState = MAP_IDLE;
    }
}
#endif

#if DEBUG_LEVEL_SELECT == 1
RECOMP_PATCH void Map_Idle_Update(void) {
    s32 i;
    bool movingCamera;
    bool movingCameraStick;
    u8 var_a1 = 0;
    u8 var_a2 = 0;
    u8 var_a0;
    f32 stickX;
    f32 stickY;

    movingCameraStick = false;
    movingCamera = false;

    if (gControllerPress[gMainController].button & A_BUTTON) {
#if DEBUG_LEVEL_SELECT == 1
        goto loadLevel;
#endif
        if ((gLastGameState == GSTATE_PLAY) && (sPrevMissionStatus != MISSION_COMPLETE) && !D_menu_801CEFD0) {
            Audio_PlayMapMenuSfx(1);
            D_menu_801CEFC4 = 1;
            D_menu_801CEFD4 = 0;
            D_menu_801CEFDC = 0;
            sMapState = MAP_PATH_CHANGE;
            D_menu_801CD94C = 0;
        } else {
#if DEBUG_LEVEL_SELECT == 1
        loadLevel:
#endif
            for (i = 0; i < TEAM_ID_MAX; i++) {
                D_ctx_80177C58[i] = gTeamShields[i];
            }
            Map_SetState_ZoomPlanet();
        }
        return;
    }

    if (gControllerPress[gMainController].button & START_BUTTON) {
        if ((sMapState == MAP_IDLE) && (gLastGameState == GSTATE_PLAY)) {
            if (D_menu_801CEFD0) {
                AUDIO_PLAY_SFX(NA_SE_ERROR, gDefaultSfxSource, 4);
            } else {
                Audio_PlayMapMenuSfx(1);
                D_menu_801CEFC4 = 1;
                D_menu_801CEFD4 = 0;
                D_menu_801CEFDC = 0;
                sMapState = MAP_PATH_CHANGE;
                D_menu_801CD94C = 0;
            }
            return;
        }
    }

    stickX = gControllerPress[gMainController].stick_x;
    stickY = gControllerPress[gMainController].stick_y;

    if (stickY != 0.0f) {
        if (D_menu_801CDA0C - (stickY * 0.05f) < -80.0f) {
            D_menu_801CDA0C = -80.0f;
            stickY = 0.0f;
        } else if (D_menu_801CDA0C - (stickY * 0.05f) > 80.0f) {
            D_menu_801CDA0C = 80.0f;
            stickY = 0.0f;
        } else {
            D_menu_801CDA0C -= stickY * 0.05f;
            movingCameraStick = true;
            var_a1 = (s32) fabsf(((stickY * 0.05f) / 0.27f));
        }
    }

    if (stickX != 0.0f) {
        D_menu_801CDA10 += stickX * 0.05f;
        var_a2 = (s32) fabsf((stickX * 0.05f) / 0.27f);
        movingCameraStick = true;
    }

    if (D_menu_801CF014 == 1) {
        var_a0 = var_a1;
        if (var_a1 < var_a2) {
            var_a0 = var_a2;
        }
        Audio_SetSfxMapModulation(var_a0);
    }

    if ((D_menu_801CF014 == 0) && (movingCameraStick == true)) {
        Audio_PlaySfxModulated(gDefaultSfxSource, NA_SE_MAP_ROLL);
        D_menu_801CF014 = 1;
    }

    if ((D_menu_801CF014 == 1) && (movingCameraStick == false) && (stickY == 0.0f) && (stickX == 0.0f)) {
        var_a1 = 0;
        var_a2 = 0;
        Audio_KillSfxById(NA_SE_MAP_ROLL);
        D_menu_801CF014 = 0;
    }

    if (gControllerHold[gMainController].button & R_TRIG) {
        if ((D_menu_801CDA14 - 20.0f) > 2475.0f) {
            D_menu_801CDA14 -= 20.0f;
            movingCamera = true;
        }
    }

    if (gControllerHold[gMainController].button & Z_TRIG) {
        if ((D_menu_801CDA14 + 20.0f) < 7695.0f) {
            D_menu_801CDA14 += 20.0f;
            movingCamera = true;
        }
    }

    if (gControllerHold[gMainController].button & U_CBUTTONS) {
        if ((sMapCamAtY - 10.0f) >= -1200.0f) {
            sMapCamAtY -= 10.0f;
            movingCamera = true;
        }
    }

    if (gControllerHold[gMainController].button & D_CBUTTONS) {
        if ((sMapCamAtY + 10.0f) <= 1200.0f) {
            sMapCamAtY += 10.0f;
            movingCamera = true;
        }
    }

    if (gControllerHold[gMainController].button & L_CBUTTONS) {
        if ((sMapCamAtX + 10.0f) <= 1200.0f) {
            sMapCamAtX += 10.0f;
            movingCamera = true;
        }
    }

    if (gControllerHold[gMainController].button & R_CBUTTONS) {
        if ((sMapCamAtX - 10.0f) >= -1200.0f) {
            sMapCamAtX -= 10.0f;
            movingCamera = true;
        }
    }

    if ((D_menu_801CF010 == 0) && (movingCamera == true)) {
        AUDIO_PLAY_SFX(NA_SE_MAP_MOVE, gDefaultSfxSource, 4);
        D_menu_801CF010 = 1;
    }

    if ((D_menu_801CF010 == 1) && (movingCamera == false)) {
        Audio_KillSfxById(NA_SE_MAP_MOVE);
        D_menu_801CF010 = 0;
    }
}
#endif