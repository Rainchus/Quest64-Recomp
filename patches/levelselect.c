#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/sf64math.h"
#include "../lib/sf64decomp/include/fox_map.h"
#include "../lib/sf64decomp/include/context.h"
#include "../lib/sf64decomp/include/PR/os_cont.h"

extern PlanetId sPlanetList[15];
extern PlanetId sCurrentPlanetId;
extern OSContPad gControllerPress[4];
extern s32 gBombCount[4];
extern s32 D_menu_801B8280;
extern s32 D_menu_801CD968;
extern s32 D_menu_801CD944;
extern s32 D_menu_801CD948;

void Map_801A61B4(LevelId level);
void Map_801A6368(void);
void Map_801A914C(void);
void Map_801A6628(void);

PlanetId sPlanetArray[][3] = {
    {PLANET_CORNERIA, PLANET_CORNERIA, PLANET_CORNERIA},
    {PLANET_METEO, PLANET_METEO, PLANET_SECTOR_Y},
    {PLANET_FORTUNA, PLANET_KATINA, PLANET_AQUAS},
    {PLANET_SECTOR_X, PLANET_SOLAR, PLANET_ZONESS},
    {PLANET_TITANIA, PLANET_MACBETH, PLANET_SECTOR_Z},
    {PLANET_BOLSE, PLANET_BOLSE, PLANET_AREA_6},
    {PLANET_VENOM, PLANET_VENOM, SAVE_SLOT_VENOM_2},
};

char *sLevelSelectPlanetNames[] = {
    "METEO",
    "AREA 6",
    "BOLSE",
    "SECTOR Z",
    "SECTOR X",
    "SECTOR Y",
    "KATINA",
    "MACBETH",
    "ZONESS",
    "CORNERIA",
    "TITANIA",
    "AQUAS",
    "FORTUNA",
    "VENOM 1",
    "SOLAR",
    "VENOM 2",
};

void RCP_SetupDL(Gfx** gfxP, s16 i);

void Map_LevelSelect(void)
{
        static int mission = 0;
        gLaserStrength[0] = 2;
        gBombCount[0] = 9;


        if (gControllerPress[0].button & L_JPAD)
        {
            mission--;
            if (mission <= 0) mission = 0;
            sCurrentPlanetId = mission;
        }
        else if (gControllerPress[0].button & R_JPAD)
        {
            mission++;
            if (mission >= 15) mission = 15;
            sCurrentPlanetId = mission;
        }


}
