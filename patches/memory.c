#include "patches.h"

extern s32* sMemoryPtr;

s32 roccoMemoryBuffer[0x2200 + 0x5DC0 /* extra for new starfield */];

RECOMP_PATCH void Memory_FreeAll(void) {
    sMemoryPtr = roccoMemoryBuffer;
}