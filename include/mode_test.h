#ifndef GUARD_MODE_TEST_H
#define GUARD_MODE_TEST_H

#include "types.h"
#include "anim.h"
#include "gba/syscall.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

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

typedef struct UnkStruct_02034A1C {
    u16 unk_00[61];
    u8 unk_7A;
    u8 unk_7B;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E[6];
} UnkStruct_02034A1C;

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
void EnableBg(s32 bg);
void LoadPalette(void* src, void* dst, s32 size);

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
u8 func_0805F8F0(u8 a);
void func_0805F904(void);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_0805FA8C(u8 bg, u16 b, u16 c);
void func_0805FB78(s32 a);
void func_0805FB84(u8 x, u8 y, u32 c, u8 v);
void func_0805FC04(u8 x, u8 y, u32 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u32 c, const char* s);
void func_08060598(void);
void func_0806098C(void);
void func_080609A0(void);

extern void* gUnk_02034A08;
extern void* gUnk_02034A0C;
extern s32 gUnk_02034A10;
extern u8 gUnk_02034A18;
extern UnkStruct_02034A1C* gUnk_02034A1C;
extern u8 gUnk_02034A20;
extern u8 gUnk_02034A21;
extern s32 gUnk_02034A24;
extern s32 gUnk_02034A28;
extern void* gUnk_02034A2C;
extern UnkStruct_02039BA0* gUnk_02039BA0;
extern UnkStruct_02039DC4* gUnk_02039DC4;
extern void* gUnk_09EE14D4[];
extern u8 gUnk_08B24DAA[];
extern u8 gUnk_08F69BA4[];

#endif /* GUARD_MODE_TEST_H */
