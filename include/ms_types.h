#ifndef GUARD_MS_TYPES_H
#define GUARD_MS_TYPES_H

#include "types.h"

typedef struct UnkStruct_0810718C {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    s16 unk_06[10];
    u16 unk_1A;
} UnkStruct_0810718C;

typedef struct UnkStruct_09EF9618 {
    u16 unk_00;
    u16 unk_02;
    s16 unk_04;
    u16 unk_06;
} UnkStruct_09EF9618;

typedef struct MsShopHosiArg {
    s16 x;
    s16 y;
    void* palette;
    u8 unk_08;
    u8 unk_09[0x3];
    s32 unk_0C;
} MsShopHosiArg;

typedef struct MsCardDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x2];
    u8 unk_20;
    u8 unk_21[0x7];
    u16 unk_28;
    u8 unk_2A;
    u8 unk_2B[0x9];
} MsCardDef;

#endif
