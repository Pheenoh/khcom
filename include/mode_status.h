#ifndef GUARD_MODE_STATUS_H
#define GUARD_MODE_STATUS_H

#include "types.h"
#include "main.h"

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 flags;
    u8 unk_00C[0x26];
    s16 hp;
    u8 unk_034[0xC4];
    s16 maxHp;
    s16 cp;
    s16 dp;
    s16 ap;
    s32 exp;
    s32 nextExp;
    u8 level;
    u8 unk_109[0x6B];
    s32 mooglePoints;
    u8 unk_178[0x08];
    u16 unk_180;
} UnkStruct_02039BB0;

extern UnkStruct_02039BB0 gUnk_02039BB0;
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
void DisableBg(s32 bg);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgPriority(s32 bg, u16 priority);
void func_08006120(s32 a, u16 b);
u8 func_08000F48(Task* t);
u8 func_08006314(void);
void UpdatePlayTime(void);
void func_080D733C(void);
void func_080E052C(u8 a);

void mode_status_0(void);
void mode_status_1(void);
void mode_status_2(void);
void func_080D7568(u8 a);

#endif /* GUARD_MODE_STATUS_H */
