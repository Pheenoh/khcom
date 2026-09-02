#ifndef GUARD_UNK_0806180C_H
#define GUARD_UNK_0806180C_H

#include "types.h"
#include "text_types.h"
#include "malloc.h"
#include "taskpool.h"


#define NULL ((void*)0)

typedef struct Ent0806E9BC {
    u8 unk_00[0x14];
    u16 unk_14;
    u8 unk_16[2];
    u32 unk_18;
    void* unk_1C;
    void (*unk_20)(void*);
} Ent0806E9BC;

typedef struct Work0806180C {
    Ent0806E9BC* unk_000;
    void* unk_004;
    void* unk_008;
    u8 unk_00C[4];
    TaskPool unk_010;
    u8 unk_024[2];
    u8 unk_026;
    u8 unk_027;
    u8 unk_028[4];
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    u8 unk_038[6];
    u16 unk_03E;
    u8 unk_040[0x148];
    s32 unk_188;
    s32 unk_18C;
    s32 unk_190;
    s32 unk_194;
    s32 unk_198;
    s32 unk_19C;
    u32 unk_1A0;
    u8 unk_1A4[4];
    u8 unk_1A8;
    u8 unk_1A9;
    u8 unk_1AA;
    u8 unk_1AB;
    u8 unk_1AC[6];
    u8 unk_1B2;
} Work0806180C;

typedef struct Work08073E34 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
} Work08073E34;

typedef struct TextCtx {
    u8 unk_00[0x48];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    u8 unk_60[8];
    s16 unk_68;
    s16 unk_6A;
    u16 unk_6C;
} TextCtx;

typedef struct Actor0806180C {
    u8 unk_00[0x24];
    u16 unk_24;
    u8 unk_26[6];
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
} Actor0806180C;

typedef struct Obj0806180C {
    u8 unk_00[0x10];
    u8 unk_10;
    u8 unk_11[3];
    u32 unk_14;
    u8 unk_18[8];
} Obj0806180C;

typedef struct Work08074DC4 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A[2];
    Obj0806180C* unk_0C;
    u16 unk_10;
} Work08074DC4;

typedef struct Handle0806180C {
    u8 unk_00[6];
    u16 unk_06;
} Handle0806180C;

typedef struct Ent080658B8 {
    s32 unk_00;
    s32 unk_04;
    void* unk_08;
    Handle0806180C* unk_0C;
    Handle0806180C* unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16[2];
} Ent080658B8;

typedef struct Work08075010 {
    u8 unk_00[0x16];
    u16 unk_16;
    u8 unk_18[2];
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C[160];
} Work08075010;

typedef struct AnimEntry0806180C {
    u8 unk_00[4];
    u8 unk_04;
    u8 unk_05[3];
} AnimEntry0806180C;

typedef struct AnimSet0806180C {
    u8 unk_00;
    u8 unk_01[3];
    AnimEntry0806180C* unk_04;
} AnimSet0806180C;

extern TextCtx* gUnk_02039DC8;
extern u16 gUnk_09033C8C[];
extern u16 gBldCnt;
extern vu16 gBldAlpha;
extern AnimSet0806180C* gUnk_09EE3FB4[];
extern Ent080658B8* gUnk_02034A84;
extern Ent080658B8* gUnk_02034A88;
extern u8 gUnk_02034A90;
extern u8 gUnk_09614718[];
extern u8 gUnk_09614738[];
extern u8 gUnk_09614758[];
extern void* gUnk_09EEB204;
extern s16 gSineTable[];
extern s16 gUnk_09033D50[];
extern s16 gUnk_09033E76[];
extern u8 gUnk_090D4180[];
extern u8 gUnk_08F69BE4[];

void _08065994(void);
u16 func_080659BC(u8 v, TextSlot* out);
void func_08065A30(void** p, u8 n);
void func_08065A44(void** p, u8 n);
u16 func_08065A70(u8 v, TextSlot* out);
u16 func_080660C0(u8* s, TextSlot* p);
void _08073E6C(Work08073E34* p);
void func_08073E74(Work08073E34* p);
void func_08074CF8(void);
void func_08074CFC(void);
void func_08065ACC(TextSlot* p, s32 n);
void func_08065AE0(TextSlot* p, s32 n);
s16 func_08065B08(TextSlot* p, u8 n);
s32 func_08065B54(u16* p);
u16 func_08065B6C(u16* a, TextSlot* b);
s32 func_08065B7C(u16* a, TextSlot* b);
void* func_080668F0(void);
void* func_08066904(void);
void func_08066918(void* a, void* b);
void func_08002488(s16 x, s16 y, void* a, void* b, void* c, u16 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void* _08066468(s32 a);
void func_080062F4(u16 a, s32 b);
void m4aSongNumStart(u16 id);
void func_08076110(s32 song, s16 x, s16 y);
u8 func_0809D280(u8* s);
u16 func_0806692C(u8* s, u16* out);
u16 func_08066AF8(s32 v, u16* out);
void func_0801CD74(void* a, u16 b);
void TaskPoolUpdate(TaskPool* a);
void func_08000F8C(void* a, void* b);
u8 _0806E9DC(Work0806180C* p, void* a);
void func_0801CE00(void* a, u16 b);
void* memcpy(void* dst, const void* src, unsigned long n);
u8 func_0806E184(Work0806180C* p, void* a);
u8 func_0806FA84(Work0806180C* p, void* a);
u8 func_0806FDB0(Work0806180C* p, void* a);
u8 func_0806FC28(Work0806180C* p, void* a);
u8 func_0806FAB8(Work0806180C* p, void* a);
u8 func_0806E570(Work0806180C* p);
void func_0806E7A8(Work0806180C* p);
void func_08070AD4(Work0806180C* p);
u8 func_0806EA28(Work0806180C* p, void* a);
u8 func_0806EB94(Work0806180C* p, void* a);
u8 func_0806EBE0(Work0806180C* p, void* a);
u8 func_0806ECE0(Work0806180C* p, void* a);
u8 func_0806ED2C(Work0806180C* p, void* a);
u8 func_0806EE20(Work0806180C* p, void* a);
u8 func_0806EE6C(Work0806180C* p, void* a);
u8 func_0806EF40(void* work, void* a);
u8 func_0806F02C(Work0806180C* p, void* a);
u8 func_0806F114(void* work, void* a);
u8 func_0806F204(Work0806180C* p, void* a);
u8 func_0806F2EC(void* work, void* a);
u8 func_0806F3A8(Work0806180C* p, void* a);
u8 func_0806F47C(void* work, void* a);
u8 func_0806F53C(Work0806180C* p, void* a);
u8 func_0806F610(Work0806180C* p, void* a);
u8 func_0806F64C(Work0806180C* p, void* a);
u8 func_0806F734(Work0806180C* p, void* a);
u8 func_0806F770(Work0806180C* p, void* a);
u8 func_0806F858(Work0806180C* p, void* a);
u8 func_0806F898(Work0806180C* p, void* a);
void func_08065940(void);
void func_080658B8(u8 n);
void func_0806C34C(void);
void func_0806E9BC(Work0806180C* p);
void func_08073E34(Work08073E34* p, u8 a, u8 b, u8 c);
void func_080746D8(void);
void func_08072918(Actor0806180C* a, u8 kind, u8 flag);
void func_08072A64(Actor0806180C* a, u8 kind, u8 flag);
u16 func_0806BA74(s32 mode, s32 flag);
void func_0806BA0C(s16 v, u8* out);
void func_0806C2C0(u8 n);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_08074D00(Work08074DC4* p);
void func_08074D14(Work08074DC4* a);
u8 func_08074E40(Work08074DC4* p);
void func_08074D98(Work08074DC4* a);
u8 func_08074E88(Work08074DC4* p, u8 v);
void func_08075010(Work08075010* p);
s16 func_08075064(u8 a);
void func_08074DC4(Work08074DC4* a);

s32 abs(s32 a);
s8 GetAngleDiff(u8 a, u8 b);
void func_0806FE90(Work0806180C* p);
void func_08070008(Work0806180C* p);

void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);

#endif /* GUARD_UNK_0806180C_H */
