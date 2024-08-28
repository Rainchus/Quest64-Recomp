#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "PR/ultratypes.h"
#include "PR/os_eeprom.h"
#include "sf64thread.h"
#include "sf64save.h"
#include "macros.h"

#define osEepromWrite osEepromWrite_recomp
#define osEepromRead osEepromRead_recomp

// On hold until memcpy and __udivdi3 issues are sorted

#if 0

s32 Save_WriteBlock(s32 arg0, u8* arg1);
s32 Save_ReadBlock(s32 arg0, u8* arg1);
s32 osEepromWrite(OSMesgQueue* mq, u8 address, u8* buffer);
s32 osEepromRead(OSMesgQueue* mq, u8 address, u8* buffer);

 RECOMP_PATCH s32 Save_ReadBlock(s32 arg0, u8* arg1) {
    if (osEepromRead(&gSerialEventQueue, arg0, arg1)) {
        PRINTF("ＥＥＰＲＯＭ インターフェース回路反応なし (ＲＥＡＤ)\n");
        return -1;
    } else {
        PRINTF("EEPROM READ  %02X: %02X %02X %02X %02X %02X %02X %02X %02X\n");
        return 0;
    }
}

RECOMP_PATCH s32 Save_WriteBlock(s32 arg0, u8* arg1) {
    if (osEepromWrite(&gSerialEventQueue, arg0, arg1)) {
        PRINTF("ＥＥＰＲＯＭ インターフェース回路反応なし (ＷＲＩＴＥ)\n");
        return -1;
    } else {
        Timer_Wait(MSEC_TO_CYCLES(15));
        PRINTF("EEPROM WRITE %02X: %02X %02X %02X %02X %02X %02X %02X %02X\n");
        return 0;
    }
}

RECOMP_PATCH s32 Save_WriteEeprom(SaveFile* arg0) {
    s32 var_a2;
    s32 i;
    s32 j;

    if (osEepromProbe(&gSerialEventQueue) != 2) { // @recomp
        PRINTF("ＥＥＰＲＯＭ が ありません\n");
        return -1;
    }

    for (i = 0; i < EEPROM_MAXBLOCKS; i++) {
        var_a2 = 0;
        for (j = 0; j < EEPROM_BLOCK_SIZE; j++) {
            if (((char*) &sPrevSaveData)[EEPROM_BLOCK_SIZE * i + j] != ((char*) arg0)[EEPROM_BLOCK_SIZE * i + j]) {
                ((char*) &sPrevSaveData)[EEPROM_BLOCK_SIZE * i + j] = ((char*) arg0)[EEPROM_BLOCK_SIZE * i + j];
                var_a2 = 1;
            }
        }
        if ((var_a2 == 1) && Save_WriteBlock(i, &((u8*) arg0)[EEPROM_BLOCK_SIZE * i])) {
            return -1;
        }
    }
    return 0;
}

RECOMP_PATCH s32 Save_ReadEeprom(SaveFile* arg0) {
    s32 i;

    if (osEepromProbe(&gSerialEventQueue) != 2) { // @recomp
        PRINTF("ＥＥＰＲＯＭ が ありません\n");
        return -1;
    }
    for (i = 0; i < EEPROM_MAXBLOCKS; i++) {
        if (Save_ReadBlock(i, &((u8*) arg0)[EEPROM_BLOCK_SIZE * i]) != 0) {
            return -1;
        }
    }
    sPrevSaveData = *arg0;
    return 0;
}
#endif
