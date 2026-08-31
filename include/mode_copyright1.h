#ifndef GUARD_MODE_COPYRIGHT1_H
#define GUARD_MODE_COPYRIGHT1_H

#include "types.h"
#include "save.h"

typedef struct Mode {
    const char* name;
    void (*unk_04)(s32 arg);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

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
void func_08005074(s32 a, s32 b, s32 c, s32 d);
void func_080050B8(s32 a, void* b, u16 c);
void func_080050DC(s32 a, void* b, u16 c);
void func_0800510C(s32 a, void* b, u16 c);
void func_080055C8(s32 a, s32 b);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_0811FE70(u16 id);

void mode_copyright1_0(s32 arg);
void mode_copyright1_1(void);
void mode_copyright1_2(void);

#endif /* GUARD_MODE_COPYRIGHT1_H */
