#ifndef GUARD_UNK_0802F1C8_H
#define GUARD_UNK_0802F1C8_H

#include "types.h"

typedef struct BtlMapB84 {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019;
    s16 unk_01A;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    u8 unk_02C[0xAE];
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2[0xE4];
    u16 unk_1C6;
    u8 unk_1C8[0x8];
} BtlMapB84;

typedef struct BtlMapWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} BtlMapWork;

extern BtlMapB84* gUnk_02039B84;
extern const s8 gUnk_0813C7D8[];

void func_0800592C(s32* p, s32 target, u16 steps);
void func_08005690(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

void func_0802F1C8(void);
void func_0802F1E8(void);
void func_0802F208(void);
s32 func_0802F268(void);
void func_0802F274(s32 a, s32 b);
void func_0802F284(s32 a, s32 b, s32 c);
s32 task_btl_map_1(BtlMapWork* work);

#endif /* GUARD_UNK_0802F1C8_H */
