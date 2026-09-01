#ifndef GUARD_MODE_COPYRIGHT2_H
#define GUARD_MODE_COPYRIGHT2_H

#include "types.h"
#include "mode.h"
typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C[0x26];
    s16 unk_032;
    u8 unk_034[0xC4];
    s16 unk_0F8;
    s16 unk_0FA;
    s16 unk_0FC;
    s16 unk_0FE;
    s32 unk_100;
    s32 unk_104;
    u8 unk_108;
    u8 unk_109[0x6B];
    s32 unk_174;
    u8 unk_178[0x08];
    u16 unk_180;
} UnkStruct_02039BB0;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern u16 gUnk_02034EDC;
extern u8 gUnk_097E05B8[];
extern u8 gUnk_0984AC38[];
extern u8 gUnk_09841F98[];
extern u8 gUnk_09801C98[];
extern Mode gUnk_09EF4E50;

void func_080010CC(Mode* mode, s32 arg);
void func_08004DB0(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void* GetBgCharBase(s32 bg);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void SetBgPriority(s32 bg, u16 priority);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);

void mode_copyright2_0(s32 arg);
void mode_copyright2_1(void);
void mode_copyright2_2(void);
u8* func_080D728C(u8* dst, s32 value, u16 digits);
void func_080D733C(void);

#endif /* GUARD_MODE_COPYRIGHT2_H */
