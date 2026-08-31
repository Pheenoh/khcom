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

#endif /* GUARD_BOS6_H */
