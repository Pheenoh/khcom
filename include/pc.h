#ifndef GUARD_PC_H
#define GUARD_PC_H

#include "types.h"
#include "game.h"

typedef struct PcAcdDmgWork {
    s16 unk_00;
    s16 unk_02;
    UnkStruct_02039B84* unk_04;
    u8 unk_08;
    u8 unk_09[0x3];
} PcAcdDmgWork;

typedef struct PcCharaWork {
    u8 unk_000[0x40];
    u8 unk_040[0x110];
    u16 unk_150;
    u8 unk_152[0xA];
    s32 unk_15C;
    s32 unk_160;
    u8 unk_164[0xC];
    s32 unk_170;
    u8 unk_174[0x14];
    s32 unk_188;
    u16 unk_18C;
    u16 unk_18E;
    u16 unk_190;
    u8 unk_192[0x2];
} PcCharaWork;

void task_pc_acddmg_0(PcAcdDmgWork* work, UnkStruct_02039B84* obj);
s32 task_pc_acddmg_1(PcAcdDmgWork* work);
void func_08049E70(PcCharaWork* work, s16 a, s32 b);
void func_08049EE4(PcCharaWork* work, s32 a, s32 b);
void func_08049F24(PcCharaWork* work, s32 a, s32 b);
s32 func_08049F50(PcCharaWork* work);

s32 GetRandom(void);
void func_0800F368(void* work, u16 a);
u8 func_0800F504(void* work, u16 a, u16 b, u16 c);
void func_0801C700(void* obj, s32* a, s32* b, s32* c);

#endif /* GUARD_PC_H */
