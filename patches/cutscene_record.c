/**
 * Used to reproduce recordings made from real N64 hardware
 * to accurately play cutscenes at the correct speed.
 * These recordings adjust gVisPerFrame during runtime to produce
 * the same behaviour as the original game.
 */

#include "patches.h"
#include "functions.h"
#include "i1.h"
#include "i2.h"
#include "i3.h"
#include "i4.h"
#include "i5.h"
#include "i6.h"

void Cutscene_WarpZoneComplete(Player* player);
void Cutscene_FortunaComplete(Player* player);
void Cutscene_CoComplete2(Player* player);

typedef struct Record {
    u8 vis;
    u16 frame;
} Record;

// Carrier destroy cutscene timings recorded from a real N64
Record gCarrierCutsceneRecord[] = {
    { 2, 0 },
    { 3, 2 },
    { 4, 16 },
    { 3, 50 },
    { 4, 58 },
    { 5, 67 },
    { 4, 68 },
    { 5, 71 },
    { 4, 73 },
    { 5, 74 },
    { 4, 106 },
    { 3, 146 },
    { 2, 194 },
};

// Granga destroy cutscene timings recorded from a real N64
Record gGrangaCutsceneRecord[] = {
    { 2, 0 },
    { 3, 1 },
    { 2, 5 },
    { 3, 7 },
    { 2, 52 },
    { 3, 78 },
    { 4, 103 },
    { 3, 125 },
    { 2, 153 },
    { 3, 155 },
    { 2, 157 },
    { 3, 158 },
    { 2, 160 },
};

// MeCrusher destroy cutscene timings recorded from a real N64
Record gMeCrusherCutsceneRecord[] = {
    { 2, 0 },
    { 3, 200 },
    { 2, 224 },
};

// Train cutscene timings recorded from a real N64
Record gMacbethCutsceneRecord[] = {
    // Train breaking barriers
    { 2, 0 },
    { 3, 2 },
    { 2, 31 },
    { 3, 400 },
    { 2, 418 },
    { 3, 433 },
    { 4, 435 },
    { 3, 444 },
    { 2, 509 },

    // Not worth it and very noticeable
    // { 3, 559 },
    // { 2, 581 },
    // { 3, 587 },

    // Explosions
    { 2, 589 },
    { 3, 714 },
    { 4, 821 },
    { 5, 849 },
    { 2, 942 },
};

// SyRobot destroy cutscene timings recorded from a real N64
Record gSyRobotCutsceneRecord[] = {
    { 2, 0 },
    { 3, 129 },
    { 2, 230 },
};

void UpdateVisPerFrameFromRecording(Record* record, s32 maxFrames) {
    int i;

    if (gCsFrameCount > record[maxFrames - 1].frame) {
        return;
    }

    for (i = 0; i < maxFrames; i++) {
        if (gCsFrameCount == record[i].frame) {
            gVIsPerFrame = record[i].vis;
        }
    }
}

RECOMP_PATCH void Cutscene_LevelComplete(Player* player) {
    s32 sp24;
    s32 sp20;
    s32 btn;

    gCsFrameCount++;

    switch (player->form) {
        case FORM_ARWING:
            if ((gCurrentLevel == LEVEL_VENOM_ANDROSS) || ((gCurrentLevel == LEVEL_VENOM_2) && (gLevelPhase == 1))) {
                Andross_LevelComplete(player);
            } else if (gCurrentLevel == LEVEL_SECTOR_X) {
                if (gLevelPhase == 0) {
                    SectorX_LevelComplete(player);
                } else {
                    Cutscene_WarpZoneComplete(player);
                }
            } else if (gCurrentLevel == LEVEL_AREA_6) {
                Area6_LevelComplete(player);
            } else if (gCurrentLevel == LEVEL_FORTUNA) {
                Cutscene_FortunaComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_BOLSE) {
                Bolse_LevelComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_SECTOR_Z) {
                SectorZ_LevelComplete(player);
            } else if (gCurrentLevel == LEVEL_KATINA) {
                Katina_LevelComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_SECTOR_Y) {
                // @recomp: Update VisPerFrame with N64 Recording
                UpdateVisPerFrameFromRecording(gSyRobotCutsceneRecord, ARRAY_COUNT(gSyRobotCutsceneRecord));
                SectorY_LevelComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_SOLAR) {
                Solar_LevelComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_ZONESS) {
                Zoness_LevelComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_VENOM_2) {
                Venom2_LevelComplete(player);
                Player_FloorCheck(player);
            } else if (gCurrentLevel == LEVEL_METEO) {
                if (gLevelPhase == 0) {
                    // @recomp: Update VisPerFrame with N64 Recording
                    UpdateVisPerFrameFromRecording(gMeCrusherCutsceneRecord, ARRAY_COUNT(gMeCrusherCutsceneRecord));
                    Meteo_LevelComplete(player);
                } else {
                    Cutscene_WarpZoneComplete(player);
                }
            } else if ((gCurrentLevel == LEVEL_CORNERIA) && (gLevelMode == LEVELMODE_ALL_RANGE)) {
                // @recomp: Update VisPerFrame with N64 Recording
                UpdateVisPerFrameFromRecording(gGrangaCutsceneRecord, ARRAY_COUNT(gGrangaCutsceneRecord));
                Corneria_LevelComplete1(player);
                Player_FloorCheck(player);
            } else {
                if (gCsFrameCount == 170) {
                    AUDIO_PLAY_BGM(NA_BGM_COURSE_CLEAR);
                }
                // @recomp: Update VisPerFrame with N64 Recording
                UpdateVisPerFrameFromRecording(gCarrierCutsceneRecord, ARRAY_COUNT(gCarrierCutsceneRecord));
                Cutscene_CoComplete2(player);
                Player_FloorCheck(player);
            }
            Player_UpdateArwingRoll(player);
            break;

        case FORM_LANDMASTER:
            sp20 = gInputPress->button;
            sp24 = gInputHold->button;
            gInputPress->button = 0;
            btn = gInputPress->button;
            gInputHold->button = gInputPress->button;
            gInputPress->stick_y = btn;
            gInputPress->stick_x = btn;

            if (gCurrentLevel == LEVEL_TITANIA) {
                Titania_LevelComplete(player);
            } else if (gMissionStatus != MISSION_COMPLETE) {
                // @recomp: Update VisPerFrame with N64 Recording
                UpdateVisPerFrameFromRecording(gMacbethCutsceneRecord, ARRAY_COUNT(gMacbethCutsceneRecord));
                Macbeth_LevelComplete2(player);
            } else {
                Macbeth_LevelComplete1(player);
            }

            func_tank_80046358(player);
            gInputPress->button = sp20;
            gInputHold->button = sp24;
            break;

        case FORM_BLUE_MARINE:
            if (gCurrentLevel == LEVEL_AQUAS) {
                Aquas_CsLevelComplete(player);
            }
            break;
    }
}
