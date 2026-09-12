#ifndef GUARD_MAP_TYPES_H
#define GUARD_MAP_TYPES_H

#include "types.h"

typedef struct UnkStruct_080DFF1C {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
} UnkStruct_080DFF1C;

typedef struct UnkStruct_02034F80 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_02034F80;

typedef struct UnkStruct_02034F7C {
    u8 unk_00;
    u8 unk_01[0x03];
    UnkStruct_02034F80* unk_04;
} UnkStruct_02034F7C;

typedef struct UnkStruct_080DFB7C {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
} UnkStruct_080DFB7C;

#endif
