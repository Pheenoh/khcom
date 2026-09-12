#ifndef GUARD_FIELD_STATE_H
#define GUARD_FIELD_STATE_H

#include "types.h"
#include "fld_types.h"

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14[0x04];
    FldActor unk_18;
    void* unk_68;
    s16 unk_6C;
    u16 unk_6E;
    u32 unk_70;
    u16 unk_74;
    u16 unk_76;
    u8 unk_78[0x14];
    u8 unk_8C[0x14];
    u8 unk_A0[0x14];
    u8 unk_B4[0x14];
    u8 unk_C8[0x14];
    s32 unk_DC;
    s32 unk_E0;
    u8 unk_E4;
    u8 unk_E5[0x03];
} UnkStruct_02039BA0;

typedef char FieldState_size[(sizeof(UnkStruct_02039BA0) == 0xE8) ? 1 : -1];

extern UnkStruct_02039BA0* gUnk_02039BA0;

#endif
