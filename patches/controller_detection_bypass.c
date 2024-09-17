#include "patches.h"

extern unsigned char gControllerPlugged[4];
extern SaveFile gSaveFile;

// Controller detection bypass
RECOMP_PATCH int Title_CheckControllers(void) {
    int ret = -1;
    int i;

    // save hack
    for (i = 0; i < 16; i++) {
        gSaveFile.save.data.planet[i].expertClear = 1;
        gSaveFile.save.data.planet[i].normalClear = 1;
        gSaveFile.save.data.planet[i].played = 1;
        gSaveFile.save.data.planet[i].normalMedal = 1;
        gSaveFile.save.data.planet[i].expertMedal = 1;
    }
    Save_Write();

    gControllerPlugged[0] = 1;

    for (i = 0; i < 4; i++) {
        if (gControllerPlugged[i] == 1) {
            ret = i;
            break;
        }
    }

    return ret;
}