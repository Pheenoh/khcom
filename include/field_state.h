#ifndef GUARD_FIELD_STATE_H
#define GUARD_FIELD_STATE_H

#include "types.h"
#include "fld_types.h"

typedef struct FieldState {
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14[0x04];
    FldActor actor;
    void* unk_68;
    s16 unk_6C;
    u16 unk_6E;
    u32 flags;
    u16 unk_74;
    u16 unk_76;
    u8 tasks[0x14];
    u8 tasks2[0x14];
    u8 tasks3[0x14];
    u8 tasks4[0x14];
    u8 tasks5[0x14];
    s32 unk_DC;
    s32 unk_E0;
    u8 unk_E4;
    u8 unk_E5[0x03];
} FieldState;

typedef char FieldState_size[(sizeof(FieldState) == 0xE8) ? 1 : -1];

extern FieldState* gUnk_02039BA0;

#endif
