#include "patches.h"

extern s32* sMemoryPtr;

s32 roccoMemoryBuffer[1000000];

RECOMP_PATCH void Memory_FreeAll(void) {
    sMemoryPtr = roccoMemoryBuffer;
}