#ifndef GUARD_PC_H
#define GUARD_PC_H

#include "pc_tasks.h"

#include "types.h"
#include "battle_actor.h"
#include "engine_math.h"
#include "game.h"
#include "pc_api.h"

typedef struct PcAcdDmgWork {
    s16 unk_00;
    s16 unk_02;
    BtlObj* unk_04;
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

void func_08049E70(PcCharaWork* work, s16 a, s32 b);

#endif /* GUARD_PC_H */
