#include "libultra_internal.h"

extern u64 osClockRate;
extern u8 D_80365D20;
extern u8 _osContNumControllers;
extern OSTimer D_80365D28;
extern OSMesgQueue _osContMesgQueue;
extern OSMesg _osContMesgBuff[4];
// exactly the same as osEepromLongRead except for osEepromWrite call

s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes) {
    s32 result = 0;
    if (address > 0x40) {
        return -1;
    }

    while (nbytes > 0) {
        result = osEepromWrite(mq, address, buffer);
        if (result != 0) {
            return result;
        }
        nbytes -= 8;
        address += 1;
        buffer += 8;
        osSetTimer(&D_80365D28, 12000 * osClockRate / 1000000, 0, &_osContMesgQueue, _osContMesgBuff);
        osRecvMesg(&_osContMesgQueue, NULL, OS_MESG_BLOCK);
    }

    return result;
}

s32 osEepromLongWriteDirty(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes) {
    s32 result = 0;
    result = osEepromWrite(mq, address, buffer);
    if (result != 0) {
        return result;
    }

    return result;
}
