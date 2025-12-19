#define RECOMP_EXPORT __attribute__((section(".recomp_export")))
#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define RECOMP_FORCE_PATCH __attribute__((section(".recomp_force_patch")))

#include "patches.h"
#include "misc_funcs.h"

typedef struct {
    /* 0x0 */ void* start;
    /* 0x4 */ void* end;
} SegmentOffset; // size = 0x8

typedef struct {
    /* 0x0 */ void* vRomAddress;
    /* 0x4 */ SegmentOffset pRom;
    /* 0xC */ signed long compFlag;
} DmaEntry; // size = 0x10;

extern DmaEntry gDmaTable[];
extern unsigned char sFillTimer;
extern unsigned char gGameStandby;

void Load_RomFile(void* vRomAddress, void* dest, signed long size);
void Lib_DmaRead(void* src, void* dst, signed long size);
void Mio0_Decompress(void* header, unsigned char* dst);
void Lib_FillScreen(unsigned char setFill);
typedef unsigned long uintptr_t;

#define SEGMENT_SIZE(segment) ((signed long) ((uintptr_t) (segment).end - (uintptr_t) (segment).start))

FrameBuffer gCompressionBuffer[3];

RECOMP_PATCH void Load_RomFile(void* vRomAddress, void* dest, signed long size) {
    long i;
    // @recomp Load the overlay in the recomp runtime.
    recomp_load_overlays((u32) vRomAddress, dest, size);

    for (i = 0; gDmaTable[i].pRom.end != 0; i++) {
        if (gDmaTable[i].vRomAddress == vRomAddress) {
            if (gDmaTable[i].compFlag == 0) {
                Lib_DmaRead(gDmaTable[i].pRom.start, dest, size);
            } else {
                Lib_FillScreen(1);
                sFillTimer = 3;
                gGameStandby = 1;
                Lib_DmaRead(gDmaTable[i].pRom.start, gCompressionBuffer, SEGMENT_SIZE(gDmaTable[i].pRom));
                Mio0_Decompress(gCompressionBuffer, dest);
            }
            break;
        }
    }
};

RECOMP_DECLARE_EVENT(recomp_on_init());

#if 1
void Audio_ThreadEntry(void *arg0);
void Graphics_ThreadEntry(void *arg0);
void Timer_ThreadEntry(void *arg0);
void SerialInterface_ThreadEntry(void *arg0);
void Main_InitMesgQueues(void);
void Main_GetNewTasks(void);
void Main_HandleRSP(void);
void Main_HandleRDP(void);
void Main_StartNextTask(void);

extern OSThread gAudioThread;           // 8013B1F0
extern u8 gAudioThreadStack[0x1000];    // 800DDAA0
extern OSThread gGraphicsThread;        // 800DEAA0
extern u8 gGraphicsThreadStack[0x1000]; // 800DEC50
extern OSThread gTimerThread;           // 800DFC50
extern u8 gTimerThreadStack[0x1000];    // 800DFE00
extern OSThread gSerialThread;          // 800E0E00
extern u8 gSerialThreadStack[0x1000];   // 800E0FB0

#define osCreateThread osCreateThread_recomp
#define osStartThread osStartThread_recomp

extern void osCreateThread(OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
extern void osStartThread(OSThread* t);

RECOMP_PATCH void Main_ThreadEntry(void* arg0) {
    OSMesg osMesg;
    u8 mesg;

    // @recomp_event recomp_on_init(): Allow mods to initialize themselves once.
    recomp_on_init();

    osCreateThread(&gAudioThread, THREAD_ID_AUDIO, Audio_ThreadEntry, arg0,
                   gAudioThreadStack + sizeof(gAudioThreadStack), 80);
    osStartThread(&gAudioThread);
    osCreateThread(&gGraphicsThread, THREAD_ID_GRAPHICS, Graphics_ThreadEntry, arg0,
                   gGraphicsThreadStack + sizeof(gGraphicsThreadStack), 40);
    osStartThread(&gGraphicsThread);
    osCreateThread(&gTimerThread, THREAD_ID_TIMER, Timer_ThreadEntry, arg0,
                   gTimerThreadStack + sizeof(gTimerThreadStack), 60);
    osStartThread(&gTimerThread);
    osCreateThread(&gSerialThread, THREAD_ID_SERIAL, SerialInterface_ThreadEntry, arg0,
                   gSerialThreadStack + sizeof(gSerialThreadStack), 20);
    osStartThread(&gSerialThread);

    Main_InitMesgQueues();

    while (true) {
        MQ_WAIT_FOR_MESG(&gMainThreadMesgQueue, &osMesg);
        mesg = (u32) osMesg;

        switch (mesg) {
            case EVENT_MESG_VI:
                osSendMesg(&gAudioVImesgQueue, (OSMesg) EVENT_MESG_VI, OS_MESG_NOBLOCK);
                osSendMesg(&gGfxVImesgQueue, (OSMesg) EVENT_MESG_VI, OS_MESG_NOBLOCK);
                Main_GetNewTasks();
                break;
            case EVENT_MESG_SP:
                Main_HandleRSP();
                break;
            case EVENT_MESG_DP:
                Main_HandleRDP();
                break;
            case EVENT_MESG_PRENMI:
                gStartNMI = 1;
                break;
        }
        if (gStopTasks == 0) {
            Main_StartNextTask();
        }
    }
}
#endif
