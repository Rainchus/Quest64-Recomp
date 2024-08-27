#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#define MODS_LEVEL_SELECT 1

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/PR/gbi.h"
#include "../lib/sf64decomp/include/context.h"
#include "../lib/sf64decomp/include/sf64math.h"
#include "../lib/sf64decomp/include/fox_map.h"
#include "../lib/sf64decomp/include/PR/os_cont.h"

RECOMP_PATCH bool Map_801A62FC(PlanetId planet) {
    u32 planetSaveSlot;
    s32 ret = true;

    switch ((int)planet) {
        case PLANET_METEO:
        case PLANET_AREA_6:
        case PLANET_BOLSE:
        case PLANET_SECTOR_Z:
        case PLANET_SECTOR_X:
        case PLANET_SECTOR_Y:
        case PLANET_KATINA:
        case PLANET_MACBETH:
        case PLANET_ZONESS:
        case PLANET_CORNERIA:
        case PLANET_TITANIA:
        case PLANET_AQUAS:
        case PLANET_FORTUNA:
            planetSaveSlot = planet;
            break;

        case PLANET_SOLAR:
            planetSaveSlot = SAVE_SLOT_SOLAR;
            break;
    }

#if MODS_LEVEL_SELECT == 1
    if (gMissionNumber == 6) {
        return false;
    }
#endif

    if (gSaveFile.save.data.planet[planetSaveSlot].played & 1) {
        ret = false;
    }

    return ret;
}