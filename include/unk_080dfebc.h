#ifndef GUARD_UNK_080DFEBC_H
#define GUARD_UNK_080DFEBC_H

#include "types.h"

typedef struct UnkStruct_080DFB8C {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
} UnkStruct_080DFB8C;

typedef struct UnkStruct_080DFF1C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} UnkStruct_080DFF1C;

typedef struct UnkStruct_02039BA0 {
    u8 unk_00[0x10];
    u16 unk_10;
    u16 unk_12;
} UnkStruct_02039BA0;

extern UnkStruct_02039BA0* gUnk_02039BA0;

UnkStruct_080DFB8C* func_080DFB8C(s32 x, s32 y);
u8 func_080E86C8(UnkStruct_080DFB8C* p, s32 x, s32 y);
s32 func_080DFEBC(s32 x, s32 y, s32 z);
s32 func_080DFF1C(UnkStruct_080DFF1C* p);
s32 func_080DFF30(UnkStruct_080DFF1C* p);
void func_080DFF4C(UnkStruct_080DFF1C* p);
void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b);
s32 func_080E0010(s32 x);
s32 func_080E0044(s32 y);

#endif /* GUARD_UNK_080DFEBC_H */
