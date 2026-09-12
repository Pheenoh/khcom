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


#endif
