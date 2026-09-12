#ifndef GUARD_MODE_COPYRIGHT1_H
#define GUARD_MODE_COPYRIGHT1_H

#include "display.h"
#include "types.h"
#include "save.h"
#include "mode.h"
#include "m4a.h"
extern u8 gUnk_09801DD8[];
extern u8 gUnk_0984B298[];
extern u8 gUnk_09849098[];
extern u8 gUnk_097DB5F8[];
extern u8 gUnk_0984AA38[];
extern u8 gUnk_09841798[];
extern Mode gModeMenuMsg;
extern Mode gModeCopyright1;
extern Mode gModeCopyright2;

int SaveRepairHeader(void);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);

void mode_copyright1_0(s32 arg);
void mode_copyright1_1(void);
void mode_copyright1_2(void);

#endif /* GUARD_MODE_COPYRIGHT1_H */
