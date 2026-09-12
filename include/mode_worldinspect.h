#ifndef GUARD_MODE_WORLDINSPECT_H
#define GUARD_MODE_WORLDINSPECT_H

#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "text_types.h"
#include "main.h"
#include "key.h"

typedef struct UnkStruct_09EF9488 {
    u8 unk_00[0x14];
    void* unk_14;
} UnkStruct_09EF9488;

extern UnkStruct_09EF9488 gUnk_09EF9488[];
extern u8 gUnk_09A329DC[];
extern u8 gUnk_02035618[];
extern u8 gUnk_020356E0[];

void func_08065AE0(TextSlot* p, s32 n);
u16 func_08065B6C(u16* a, TextSlot* b);
void func_080FF8CC(void);
void UpdatePlayTime(void);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_080E052C(u8 a);
void func_080FF330(void);
void func_080FF794(void);

#endif /* GUARD_MODE_WORLDINSPECT_H */
