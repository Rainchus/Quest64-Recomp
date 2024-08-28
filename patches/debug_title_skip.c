#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#if 0

#include "debug.h"
#include "PR/ultratypes.h"
#include "context.h"
#include "sf64thread.h"
#include "sf64dma.h"
#include "sf64save.h"

RECOMP_PATCH void Game_Initialize(void)
{
    Memory_FreeAll();
    Rand_Init();
    Rand_SetSeed(1, 29000, 9876);
    gGameState = GSTATE_BOOT;
#ifdef DEBUG_BOOT_STATE
    gNextGameState = GSTATE_INIT;
    if (Save_Read() != 0)
    {
        gSaveFile.save = gDefaultSave;
        gSaveFile.backup = gDefaultSave;
        Save_Write();
    }
#endif
    gNextGameStateTimer = 0;
    gBgColor = 0;
    gBlurAlpha = 255;
    gFovY = 45.0f;
    gProjectNear = 10.0f;
    gProjectFar = 12800.0f;
    gNextVsViewScale = gVsViewScale = 0.0f;
    gSceneId = SCENE_LOGO;
    gSceneSetup = 0;
    Load_InitDmaAndMsg();
    gGameStandby = true;
}
#endif
