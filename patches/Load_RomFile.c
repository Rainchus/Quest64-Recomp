#define RECOMP_EXPORT __attribute__((section(".recomp_export")))
#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define RECOMP_FORCE_PATCH __attribute__((section(".recomp_force_patch")))

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#include "misc_funcs.h"

typedef union {
    unsigned short data[SCREEN_HEIGHT * SCREEN_WIDTH];
    unsigned short array[SCREEN_HEIGHT][SCREEN_WIDTH];
} FrameBuffer;

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
extern FrameBuffer gFrameBuffers[];

void Load_RomFile(void* vRomAddress, void* dest, signed long size);
void Lib_DmaRead(void* src, void* dst, signed long size);
void Mio0_Decompress(void* header, unsigned char* dst);
void Lib_FillScreen(unsigned char setFill);
typedef unsigned long uintptr_t;

#define SEGMENT_SIZE(segment) ((signed long) ((uintptr_t) (segment).end - (uintptr_t) (segment).start))

RECOMP_PATCH void Load_RomFile(void* vRomAddress, void* dest, signed long size) {
    long i;
    // @recomp Load the overlay in the recomp runtime.
    recomp_load_overlays((u32)vRomAddress, dest, size);

    for (i = 0; gDmaTable[i].pRom.end != 0; i++) {
        if (gDmaTable[i].vRomAddress == vRomAddress) {
            if (gDmaTable[i].compFlag == 0) {
                Lib_DmaRead(gDmaTable[i].pRom.start, dest, size);
            } else {
                Lib_FillScreen(1);
                sFillTimer = 3;
                gGameStandby = 1;
                Lib_DmaRead(gDmaTable[i].pRom.start, gFrameBuffers, SEGMENT_SIZE(gDmaTable[i].pRom));
                Mio0_Decompress(gFrameBuffers, dest);
            }
            break;
        }
    }
};