#ifndef GUARD_UNK_080FB000_H
#define GUARD_UNK_080FB000_H

#include "types.h"
#include "taskpool.h"

typedef struct AnimState {
    void** unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    void* unk_14;
} AnimState;

typedef struct GaEntryWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x30];
    u8 unk_040[0x2C];
    u8 unk_06C;
    u8 unk_06D[0xB];
    s32 unk_078;
    s32 unk_07C;
    u8 unk_080[0x92];
    u8 unk_112;
    u8 unk_113[0x9];
    u32 unk_11C;
    u8 unk_120[0x4];
    s32 unk_124;
    s32 unk_128;
    s32 unk_12C;
    u8 unk_130[0xC];
    s32 unk_13C;
    u8 unk_140[0x18];
    u8 unk_158;
    u8 unk_159;
    u16 unk_15A;
    s16 unk_15C;
    u8 unk_15E[0xE];
    TaskPool unk_16C;
    AnimState unk_180;
    void* unk_198;
    void* gfx;
    u32 unk_1A0;
    u8 unk_1A4;
    u8 unk_1A5;
    s16 unk_1A6;
} GaEntryWork;

typedef struct GaWork {
    s32 unk_000;
    s32 unk_004;
    u8 unk_008[0x10];
    s32 unk_018;
    u8 unk_01C[0x4];
    GaEntryWork entries[6];
    AnimState unk_A10;
    u8 tiles[0x4];
    void* gfx;
    u8 unk_A30[0x1C];
    s32 unk_A4C;
    u16 unk_A50;
    u8 unk_A52;
    u8 unk_A53;
} GaWork;

typedef struct BtlWork {
    u8 unk_000[0x7C];
    s32* unk_07C;
    u8 unk_080[0x4C];
    s32 unk_0CC;
} BtlWork;

extern BtlWork* gBtlWork;
extern s16 gSineTable[];

u16 GetRandom(void);
void* AnimUpdate(AnimState* a);
void TaskPoolUpdate(TaskPool* a);
void ApproachAngle(u16* a, s32 b, s32 c);
void func_08012324(void* a, s32 x, s32 y, s32 z);
u8 func_080128EC(void);
void func_08013DB8(s32 a, s32 b, s32 c, s32 d);
s32 func_0801ADAC(GaEntryWork* e);
void func_0801AF08(void* a);
void func_0801AF4C(GaEntryWork* e);
void _0801C1F8(s32 a, s32 b, s32 c, s32 d);
void func_0801C2DC(void* a, s32 b);
void func_080F7E84(GaEntryWork* e);
void func_080F7F54(GaWork* work, s32 state);
void func_080F8374(GaEntryWork* e);

void func_080FB000(GaWork* work, GaEntryWork* e);

#endif /* GUARD_UNK_080FB000_H */
