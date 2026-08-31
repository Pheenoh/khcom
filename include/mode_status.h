#ifndef GUARD_MODE_STATUS_H
#define GUARD_MODE_STATUS_H

#include "types.h"
#include "main.h"

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
extern TaskPool gUnk_02034EE0;
extern Task* gUnk_02034EF4;
extern u8 gUnk_02034EF8;
extern u8 gUnk_097FFB98[];
extern u8 gUnk_0984B118[];
extern u8 gUnk_09848198[];
extern u8 gUnk_09847C98[];
extern u8 gUnk_09847798[];
extern u8 gUnk_09848B98[];
extern TaskDesc gUnk_09EF4F08;
extern TaskDesc gUnk_09EF4EF0;

void func_08004D74(void);
void func_08004DB0(void);
void func_0800501C(s32 a);
void SetupBg(s32 a, s32 b, s32 c, s32 d);
void LoadBgTiles(s32 a, void* b, u16 c);
void LoadBgPalette(s32 a, void* b, u16 c);
void LoadBgMap(s32 a, void* b, u16 c);
void SetBgPriority(s32 a, s32 b);
void func_08006120(s32 a, u16 b);
u8 func_08000F48(Task* t);
u8 func_08006314(void);
void func_0801CC80(void);
void func_080D733C(void);
void func_080E052C(u8 a);

void mode_status_0(void);
void mode_status_1(void);
void mode_status_2(void);
void func_080D7568(u8 a);

#endif /* GUARD_MODE_STATUS_H */
