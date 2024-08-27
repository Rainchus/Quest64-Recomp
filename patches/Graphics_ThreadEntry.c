#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#define osSendMesg osSendMesg_recomp
#define osViSwapBuffer osViSwapBuffer_recomp
#define osRecvMesg osRecvMesg_recomp

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/PR/os_message.h"
#include "../lib/sf64decomp/include/sf64thread.h"
#include "../lib/sf64decomp/include/gfx.h"
#include "../lib/sf64decomp/include/sys.h"
#include "../lib/sf64decomp/include/sf64audio_external.h"
#include "../lib/rt64/include/rt64_extended_gbi.h"
#include "misc_funcs.h"

extern OSMesgQueue gControllerMesgQueue;
extern OSContPad gControllerPress[4];
extern FrameBuffer gFrameBuffers[3];

void Graphics_InitializeTask(u32 frameCount);
void Graphics_SetTask(void);
void Main_SetVIMode(void);
int recomp_printf(const char* fmt, ...);

// FPS fix
RECOMP_PATCH void Graphics_ThreadEntry(void *arg0)
{
    u8 i;
    u8 visPerFrame;
    u8 validVIsPerFrame;

    Game_Initialize();
    osSendMesg(&gSerialThreadMesgQueue, (OSMesg)SI_READ_CONTROLLER, OS_MESG_NOBLOCK);
    Graphics_InitializeTask(gSysFrameCount);
    {
        gSPSegment(gUnkDisp1++, 0, 0);
        gEXEnable(gMasterDisp++); // @recomp
        gSPDisplayList(gMasterDisp++, gGfxPool->unkDL1);
        Game_Update();
        gSPEndDisplayList(gUnkDisp1++);
        gSPEndDisplayList(gUnkDisp2++);
        gSPDisplayList(gMasterDisp++, gGfxPool->unkDL2);

        gDPFullSync(gMasterDisp++);
        gSPEndDisplayList(gMasterDisp++);
    }
    Graphics_SetTask();
    while (true)
    {
        gSysFrameCount++;
        Graphics_InitializeTask(gSysFrameCount);
        MQ_WAIT_FOR_MESG(&gControllerMesgQueue, NULL);
        osSendMesg(&gSerialThreadMesgQueue, (OSMesg)SI_RUMBLE, OS_MESG_NOBLOCK);
        Controller_UpdateInput();
        osSendMesg(&gSerialThreadMesgQueue, (OSMesg)SI_READ_CONTROLLER, OS_MESG_NOBLOCK);
        if (gControllerPress[3].button & U_JPAD)
        {
            Main_SetVIMode();
        }

        {
            gEXEnable(gMasterDisp++); // @recomp
            gSPSegment(gUnkDisp1++, 0, 0);
            gSPDisplayList(gMasterDisp++, gGfxPool->unkDL1);
            Game_Update();
            if (gStartNMI == 1)
            {
                Graphics_NMIWipe();
            }
            gSPEndDisplayList(gUnkDisp1++);
            gSPEndDisplayList(gUnkDisp2++);
            gSPDisplayList(gMasterDisp++, gGfxPool->unkDL2);

            visPerFrame = MIN(gVIsPerFrame, 4);  // @recomp
            validVIsPerFrame = MAX(visPerFrame, gGfxVImesgQueue.validCount + 1);  // @recomp
            gEXSetRefreshRate(gMasterDisp++, 60 / validVIsPerFrame);  // @recomp

            gDPFullSync(gMasterDisp++);
            gSPEndDisplayList(gMasterDisp++);
        }

        MQ_WAIT_FOR_MESG(&gGfxTaskMesgQueue, NULL);

        Graphics_SetTask();

        if (!gFillScreen)
        {
            osViSwapBuffer(&gFrameBuffers[(gSysFrameCount - 1) % 3]);
        }

        Fault_SetFrameBuffer(&gFrameBuffers[(gSysFrameCount - 1) % 3], SCREEN_WIDTH, 16);

        visPerFrame = MIN(gVIsPerFrame, 4);
        validVIsPerFrame = MAX(visPerFrame, gGfxVImesgQueue.validCount + 1);

        for (i = 0; i < validVIsPerFrame; i += 1)
        { // Can't be ++
            MQ_WAIT_FOR_MESG(&gGfxVImesgQueue, NULL);
        }

        Audio_Update();
    }
}