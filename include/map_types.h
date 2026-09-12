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

typedef struct UnkStruct_0203C7AC {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11[0x03];
    s32 unk_14;
    u8 unk_18;
    u8 unk_19[0x03];
    s32 unk_1C;
    u8 unk_20;
    u8 unk_21[0x03];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x14];
} UnkStruct_0203C7AC;

typedef struct UnkStruct_080DFB8C {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
    u16* unk_14;
    u16* unk_18;
    u16* unk_1C;
} UnkStruct_080DFB8C;

typedef struct UnkStruct_080DEDD8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
} UnkStruct_080DEDD8;

typedef struct UnkStruct_080DEE18 {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D[0x03];
} UnkStruct_080DEE18;

typedef struct UnkStruct_0203C590 {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08[4][4];
    u8 unk_18[0x04];
    UnkStruct_080DEE18 unk_1C[32];
} UnkStruct_0203C590;

#endif
