

#include "n64sys.h"

SaveFile gSaveIOBuffer;
SaveFile sPrevSaveData;

s32 Save_ReadBlock(s32 arg0, u8* arg1) {
    if (osEepromRead(&gSerialEventQueue, arg0, arg1)) {
        PRINTF("ＥＥＰＲＯＭ インターフェース回路反応なし (ＲＥＡＤ)\n");
        return -1;
    } else {
        PRINTF("EEPROM READ  %02X: %02X %02X %02X %02X %02X %02X %02X %02X\n");
        return 0;
    }
}

s32 Save_WriteBlock(s32 arg0, u8* arg1) {
    if (osEepromWrite(&gSerialEventQueue, arg0, arg1)) {
        PRINTF("ＥＥＰＲＯＭ インターフェース回路反応なし (ＷＲＩＴＥ)\n");
        return -1;
    } else {
        Timer_Wait(MSEC_TO_CYCLES(15));
        PRINTF("EEPROM WRITE %02X: %02X %02X %02X %02X %02X %02X %02X %02X\n");
        return 0;
    }
}
s32 osFullEepromWrite(OSMesgQueue* mq, unsigned char* buffer);

s32 Save_WriteEeprom(SaveFile* arg0) {
//    s32 var_a2;
//    s32 i;
//    s32 j;

    if (osEepromProbe(&gSerialEventQueue) != 1) {
        PRINTF("ＥＥＰＲＯＭ が ありません\n");
        return -1;
    }
#if 0
    var_a2 = 0;
    for (i = 0; i < EEPROM_MAXBLOCKS; i++) {
        for (j = 0; j < EEPROM_BLOCK_SIZE; j++) {
            if (((char*) &sPrevSaveData)[EEPROM_BLOCK_SIZE * i + j] != ((char*) arg0)[EEPROM_BLOCK_SIZE * i + j]) {
                ((char*) &sPrevSaveData)[EEPROM_BLOCK_SIZE * i + j] = ((char*) arg0)[EEPROM_BLOCK_SIZE * i + j];
                var_a2 = 1;
                goto skiptherest;
            }
        }
    }
skiptherest:
    if (var_a2) {
        if (osFullEepromWrite(&gSerialEventQueue, arg0)) {
            return -1;
        }
    }
#endif
    if (osFullEepromWrite(&gSerialEventQueue, arg0)) {
        return -1;
    }
    return 0;
}

s32 osFullEepromRead(OSMesgQueue* mq, u8* buffer);

s32 Save_ReadEeprom(SaveFile* arg0) {
//    s32 i;

    if (osEepromProbe(&gSerialEventQueue) != 1) {
        PRINTF("ＥＥＰＲＯＭ が ありません\n");
        return -1;
    }
    if (osFullEepromRead(&gSerialEventQueue, arg0)) {
        return -1;
    }
    sPrevSaveData = *arg0;
    return 0;
}
