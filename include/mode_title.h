#ifndef GUARD_MODE_TITLE_H
#define GUARD_MODE_TITLE_H

#include "types.h"
#include "title_types.h"
#include "intr.h"
#include "main.h"

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_IE (*(vu16*)0x04000200)
#define REG_IME (*(vu16*)0x04000208)

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
} UnkStruct_02039BB0;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern u16 gBldCnt;
extern u16 gBldAlpha;
extern s32 gUnk_0203C544;
extern s32 gUnk_0203C548;
extern s32 gUnk_0203C54C;
extern u8 gUnk_09840798[];
extern u8 gUnk_0983E398[];
extern u8 gUnk_097D3658[];
extern u8 gUnk_09840F98[];
extern u8 gUnk_097C77B8[];
extern u8 gUnk_0983EB98[];
extern u8 gUnk_097CF758[];
extern u8 gUnk_0984A618[];
extern u8 gUnk_0983FB98[];
extern u8 gUnk_0976E9F4[];
extern u8 gUnk_09776076[];
extern u8 gUnk_0976EC54[];
extern u8 gUnk_0976ED5A[];
extern u8 gUnk_0976F0F6[];
extern u8 gUnk_0976F1F0[];
extern u8 gUnk_0976FD96[];
extern u8 gUnk_0984AA18[];
extern u8 gUnk_0984A6D8[];
extern u8 gUnk_0984A6B8[];
extern u8 gUnk_0984A6F8[];
extern u8 gUnk_0984A718[];
extern u8 gUnk_0984A738[];
extern TaskDesc gUnk_09EF4E60;
extern TaskDesc gUnk_09EF4E78;
extern TaskDesc gUnk_09EF4E90;
extern void* gUnk_09EF659C;
extern void* gUnk_09EF669C;
extern void* gUnk_09EF65A4;
extern void* gUnk_09EF65AC;
extern void* gUnk_09EF65B4;
extern void* gUnk_09EF65BC;
extern void* gUnk_09EF65C4;

void func_0801CB44(void);
s32 SaveLoadHeader(void);
void func_08093BB4(void);
void func_08093C04(void);
void func_08004E64(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void DisableBg(s32 bg);
void func_080C736C(void);
void func_080C73A4(s32 a, s32 b, s32 c);
void SetBgSize(s32 a, s32 b);
void func_08005690(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_08006120(s32 a, s32 b);
void m4aSongNumStart(u16 id);
u8 func_08006314(void);
void func_080C73D8(void);
void func_080D5A4C(s32 a);
void func_080D5B04(void);
void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void ApproachValue(s32* value, s32 target, u16 steps);
void EnableBg(s32 a);
void func_080C75A4(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
void func_08000DE8(TaskPool* pool, Task* t);
u8 func_080D6790(void);
void func_080D5B30(void);
void func_080D59B4(void);
s32 SaveRepairSystem(void);
s32 SaveRepairFileLarge(u16 file);
s32 SaveRepairFileSmall(u16 file);

#endif /* GUARD_MODE_TITLE_H */
