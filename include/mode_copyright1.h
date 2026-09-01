#ifndef GUARD_MODE_COPYRIGHT1_H
#define GUARD_MODE_COPYRIGHT1_H

#include "types.h"
#include "save.h"
#include "mode.h"
extern u8 gUnk_02034ED4;
extern u16 gUnk_02034ED6;
extern u8 gUnk_02034ED8;
extern u8 gUnk_09801DD8[];
extern u8 gUnk_0984B298[];
extern u8 gUnk_09849098[];
extern u8 gUnk_097DB5F8[];
extern u8 gUnk_0984AA38[];
extern u8 gUnk_09841798[];
extern Mode gUnk_09EF6AF0;
extern Mode gUnk_09EF4EC0;
extern Mode gUnk_09EF4ED0;

int SaveRepairHeader(void);
void func_080010CC(Mode* mode, s32 arg);
void func_08004DB0(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgPriority(s32 bg, u16 priority);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void m4aSongNumStart(u16 id);

void mode_copyright1_0(s32 arg);
void mode_copyright1_1(void);
void mode_copyright1_2(void);

#endif /* GUARD_MODE_COPYRIGHT1_H */
