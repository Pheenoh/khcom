#ifndef GUARD_SIO_TYPES_H
#define GUARD_SIO_TYPES_H

#include "types.h"

typedef struct SioWork {
    u8 unk_00;
    u8 unk_01;
    u8 playerId;
    u8 playerCount;
    u16 recv[4];
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u16 unk_16;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    u16 sendBuf[4][32];
    u8 sendReadIdx;
    u8 sendCount;
    u8 unk_11E;
    u8 unk_11F;
    u16 recvBuf[2][4][32];
    u8 recvReadIdx;
    u8 recvCount;
} SioWork;

typedef char SioWork_size[(sizeof(SioWork) == 0x324) ? 1 : -1];

#endif
