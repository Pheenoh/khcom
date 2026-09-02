#ifndef GUARD_SAVE_TYPES_H
#define GUARD_SAVE_TYPES_H

#include "types.h"

typedef struct SaveCommon {
    u32 flags;
    u8 unk_04[0x88];
    u16 unk_8C;
    u16 unk_8E;
    u8 unk_90;
    u8 unk_91;
    u8 unk_92[0x02];
    u32 unk_94;
} SaveCommon;

typedef struct SaveFileSummary {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
} SaveFileSummary;

#endif
