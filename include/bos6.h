#ifndef GUARD_BOS6_H
#define GUARD_BOS6_H

#include "types.h"
#include "game.h"

typedef struct PcWork {
    u16 unk_000;
    u16 unk_002;
    u16 unk_004;
    u16 unk_006;
    u16 unk_008;
    u16 unk_00A;
    u16 unk_00C;
    u8 unk_00E[0xA];
    u8 unk_018;
    u8 unk_019[0x3];
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u16 unk_030;
    u8 unk_032[0x2];
    u16 unk_034;
    u8 unk_036[0xA];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u32 unk_050;
    u32 unk_054;
    u32 unk_058;
    u32 unk_05C;
    u32 unk_060;
    u8 unk_064[0x1C];
    u16 unk_080;
    u16 unk_082;
    u8 unk_084[0x4];
    u32 unk_088;
    u32 unk_08C;
    u8 unk_090[0x4];
    u32 unk_094;
    u8 unk_098[0xCC];
    u32 unk_164;
    u32 unk_168;
    u32 unk_16C;
    u8 unk_170[0x28];
    u32 unk_198;
    u32 unk_19C;
    u8 unk_1A0[0xD4];
    u32 unk_274;
    u8 unk_278[0x58];
    u32 unk_2D0;
    u32 unk_2D4;
    u32 unk_2D8;
    u32 unk_2DC;
    u8 unk_2E0[0x4];
    u32 unk_2E4;
    u16 unk_2E8;
    u8 unk_2EA[0x6];
    u32 unk_2F0;
    u32 unk_2F4;
    u8 unk_2F8[0x1C24];
} PcWork;

typedef struct PcAcdWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u8 unk_018;
    u8 unk_019[0x3];
    u32 unk_01C;
    u32 unk_020;
    u8 unk_024[0xA];
    u16 unk_02E;
    u8 unk_030[0x8];
} PcAcdWork;

typedef struct PcFltWork {
    u16 unk_000;
    u16 unk_002;
    u8 unk_004;
    u8 unk_005;
    u8 unk_006;
    u8 unk_007;
    u16 unk_008;
    u8 unk_00A[0x2];
    u32 unk_00C;
    u32 unk_010;
    u16 unk_014;
    u16 unk_016;
    u16 unk_018;
    u8 unk_01A[0x2];
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
    u8 unk_044[0x58];
    u32 unk_09C;
    u8 unk_0A0[0x14];
} PcFltWork;

typedef struct PcFldWork {
    u32 unk_000;
    u8 unk_004[0x4];
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u8 unk_014[0x58];
} PcFldWork;

void func_08012304(void* a);
void func_080028C0(void* a);
void func_08002C10(void* a);
void func_08005BE8(void* src, void* dst, s32 size);

extern u8 gUnk_09D69374[];
extern u8 gUnk_05000080[];

void func_0810A018(void* a);
void func_0810A498(void* a);
void func_0801BCD4(void* a);

extern void* gUnk_02036010;

void* func_0810B49C(void);
void func_0810B4A8(u8* p);
void func_0810B51C(u8* p);
void func_0810BF24(u8** p, u8 v);
void func_0810C2C4(u8** p);
void func_0810C2CC(u8* p, u16 a, u16 b);
void func_0810C2E0(u8* work);
void task_bos_pc_2(PcWork* work);
void task_bos_pc_acd_3(PcAcdWork* work);
void task_bos_pc_flt_3(PcFltWork* work);
void task_bos_pc_fld_3(PcFldWork* work);
void func_0810B4F4(u8* p);
s32 func_0810B7D8(s32 x);
s32 func_0810B7E0(s32 x);
s32 func_0810BF14(s32 x);
s32 func_0810BF1C(s32 x);
s32 func_0810C2B4(s32 x);
s32 func_0810C2BC(s32 x);

#endif /* GUARD_BOS6_H */
