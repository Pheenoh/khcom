#ifndef GUARD_MODE_WORLDINSPECT_H
#define GUARD_MODE_WORLDINSPECT_H

#include "types.h"
#include "main.h"

typedef struct UnkStruct_09EF9488 {
    u8 unk_00[0x14];
    void* unk_14;
} UnkStruct_09EF9488;

extern UnkStruct_09EF9488 gUnk_09EF9488[];
extern u8 gUnk_0203511A;
extern void* gUnk_0203511C;
extern void* gUnk_02035120;
extern void* gUnk_02035124;
extern void* gUnk_02035128;
extern void* gUnk_02035148;
extern void* gUnk_0203514C;
extern void* gUnk_02035168[];
extern void* gUnk_02035198[];
extern u8 gUnk_020351F8[];
extern u8 gUnk_020352C0[];
extern s16 gUnk_020354C0;
extern void* gUnk_020354D4;
extern s16 gUnk_02035118;
extern s32 gUnk_020354C8[];
extern s32 gUnk_020354D0;
extern s16 gUnk_020354C2;
extern u8 gUnk_020354E0;
extern u8 gUnk_09A329DC[];
extern u8 gUnk_02035618[];
extern u8 gUnk_020356E0[];

void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void func_08065AE0(void* a, s32 b);
u16 func_08065B6C(void* a, void* b);
void func_080FF8CC(void);
void func_0801CC80(void);
void func_080058FC(s32* value, s32 target, u16 steps);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_080E052C(u8 a);
void func_080FF330(void);
void func_080FF794(void);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);

#endif /* GUARD_MODE_WORLDINSPECT_H */
