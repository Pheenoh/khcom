#ifndef GUARD_MODE_TEST_H
#define GUARD_MODE_TEST_H

#include "types.h"
#include "anim.h"
#include "gba/syscall.h"

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x68];
    u32 unk_70;
} UnkStruct_02039BA0;

typedef struct UnkStruct_02039DC4 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkStruct_02039DC4;

typedef struct LockonWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s32 unk_0C[8];
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
    u8 unk_30;
    u8 unk_31[3];
    AnimState unk_34;
    u8 unk_4C;
    u8 unk_4D[3];
} LockonWork;

void* EwramAlloc(s32 size);
void EwramFree(void* p);
u16 GetKeysRepeat(void);
void* LoadObjTiles(void* a, s32 b);
void ReleaseObjTiles(void* a);
void* AllocObjTiles(s32 a, s32 b);
void func_08002A10(void* a, void* b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(void* a);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* AnimGetGfx(AnimState* a);
u32 Sqrt(u32 a);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);

void mode_test_0(void);
void mode_test_1(void);
void mode_test_2(void);
void func_0805F1C0(s32* p, s32 v);
s32 func_0805F588(s32 a, s32 b);
s32 func_0805F5A4(s32* x, s32* y);
void func_0805F66C(LockonWork* w);
void func_0805F728(s32* x, s32* y);
void func_0805F770(void);
void func_0805F7B0(s32 a);
void func_0805F7BC(void);
void func_0805F7C8(u8 a);
void func_08060598(void);
void func_0806098C(void);
void func_080609A0(void);

extern void* gUnk_02034A08;
extern void* gUnk_02034A0C;
extern s32 gUnk_02034A10;
extern void* gUnk_02034A1C;
extern u8 gUnk_02034A20;
extern s32 gUnk_02034A24;
extern void* gUnk_02034A2C;
extern UnkStruct_02039BA0* gUnk_02039BA0;
extern UnkStruct_02039DC4* gUnk_02039DC4;
extern void* gUnk_09EE14D4[];
extern u8 gUnk_08B24DAA[];
extern u8 gUnk_08F69BA4[];

#endif /* GUARD_MODE_TEST_H */
