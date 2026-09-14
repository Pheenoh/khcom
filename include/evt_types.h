#ifndef GUARD_EVT_TYPES_H
#define GUARD_EVT_TYPES_H

#include "types.h"

typedef struct EvtObjRes {
    u16 unk_00;
    u8 unk_02[0x06];
    void* unk_08;
} EvtObjRes;

typedef struct EvtAnimDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
} EvtAnimDef;

typedef struct EvtObjAnim {
    EvtAnimDef* unk_00;
    u8 unk_04[0x08];
    u16 unk_0C;
    u16 unk_0E;
} EvtObjAnim;

typedef struct EvtObjResTable {
    EvtObjRes unk_00;
    u8 unk_0C[0x04];
} EvtObjResTable;

typedef char EvtAnimDef_size[(sizeof(EvtAnimDef) == 12) ? 1 : -1];
typedef char EvtObjAnim_size[(sizeof(EvtObjAnim) == 16) ? 1 : -1];
typedef char EvtObjResTable_size[(sizeof(EvtObjResTable) == 16) ? 1 : -1];


typedef struct Ent08074EC8 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} Ent08074EC8;

typedef struct EventState {
    Ent08074EC8* unk_00[17];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 x;
    s32 y;
    s32 unk_60;
    u32 unk_64;
    s16 unk_68;
    s16 unk_6A;
    u16 unk_6C;
    u16 unk_6E;
    u16 unk_70;
    u8 unk_72[2];
    s32 unk_74;
    u8 unk_78;
    u8 unk_79;
    u8 unk_7A;
    u8 unk_7B;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E;
    u8 unk_7F;
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
    u8 unk_84;
    u8 unk_85;
    u8 unk_86;
    u8 unk_87;
    u8 unk_88;
    u8 unk_89;
    u8 unk_8A;
    u8 unk_8B;
} EventState;

#endif
