#ifndef GUARD_EMY_H
#define GUARD_EMY_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019;
    u16 unk_01A;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    s16 unk_02C;
    s16 unk_02E;
    u32 unk_030;
    u64 unk_034;
    u8 unk_03C[0x0C];
    u32 unk_048;
    u32 unk_04C;
    u32 unk_050;
    u32 unk_054;
    u32 unk_058;
    u32 unk_05C;
    u8 unk_060[0x08];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    u16 unk_072;
    u16 unk_074;
    u16 unk_076;
    struct BtlWork* unk_078;
    struct BtlWork* unk_07C;
    u8 unk_080[0x1C];
    u16 unk_09C;
    u16 unk_09E;
    u16 unk_0A0;
    s16 unk_0A2;
    u8 unk_0A4;
    u8 unk_0A5[0x03];
    u32 unk_0A8;
    u32 unk_0AC;
    u16 unk_0B0;
    u8 unk_0B2;
    u8 unk_0B3;
    u8 unk_0B4;
    u8 unk_0B5[0x03];
    u32 unk_0B8;
    u8 unk_0BC[0x10];
    u16 unk_0CC;
    u16 unk_0CE;
    u32 unk_0D0;
    u32 unk_0D4;
    u16 unk_0D8;
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2;
    u8 unk_0E3;
    u16 unk_0E4;
    u8 unk_0E6[0x02];
    u32 unk_0E8;
    s16 unk_0EC;
    u8 unk_0EE;
    u8 unk_0EF;
    u32 unk_0F0;
    u32 unk_0F4;
    u16 unk_0F8;
    u8 unk_0FA;
    u8 unk_0FB;
    u32 unk_0FC;
    u8 unk_100[0x14];
    void* unk_114;
    u32 unk_118;
    u32 unk_11C;
    u16 unk_120;
    u8 unk_122[0x16];
    s32 unk_138;
    u8 unk_13C[0x8C];
} BtlWork;

typedef struct EmyActor {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u16 unk_20;
    u8 unk_22[0x02];
    s32 unk_24;
    u8 unk_28[0x04];
    s16 hp;
    s16 maxHp;
    u8 unk_30[0x04];
    u64 flags;
    u8 unk_3C[0x04];
    u32 unk_40;
    u8 unk_44[0x04];
    u32 unk_48;
    u32 unk_4C;
    u8 unk_50[0x4C];
    u16 unk_9C;
    u8 unk_9E[0x04];
    u16 unk_A2;
    u8 unk_A4[0x14];
    u32 unk_B8;
    u8 unk_BC[0x12];
    s16 unk_CE;
    s16 unk_D0;
    u16 unk_D2;
    u8 unk_D4[0x3C];
} EmyActor;

typedef struct EmyDef {
    void* unk_00;
    void* unk_04;
} EmyDef;

typedef struct EmySpawn {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    u16 unk_14;
    u8 unk_16[0x0A];
} EmySpawn;

typedef struct EmyWork {
    void* tiles;
    void* unk_004;
    void* unk_008;
    void* gfx;
    u32 anim;
    u8 unk_014[0x02];
    u16 unk_016;
    u8 unk_018[0x02];
    u16 unk_01A;
    u8 unk_01C[0x02];
    u16 unk_01E;
    u32 unk_020;
    u8 unk_024[0x04];
    TaskPool unk_028;
    EmyActor unk_03C;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    u16 unk_156;
    u16 unk_158;
    u8 unk_15A;
    u8 unk_15B;
    EmyDef* unk_15C;
    u8 angle;
    u8 unk_161;
    u16 unk_162;
    u8 unk_164[0x04];
    s32 unk_168;
    u32 unk_16C;
    u8 unk_170[0x0C];
    s32 unk_17C;
    s32 unk_180;
} EmyWork;

typedef struct Emy03Work {
    EmyWork base;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
} Emy03Work;

typedef struct Emy04Work {
    EmyWork base;
    u8 unk_184;
    u8 unk_185;
    s16 unk_186;
} Emy04Work;

typedef struct Emy06Work {
    EmyWork base;
    s32 unk_184;
} Emy06Work;

typedef struct Emy07Work {
    EmyWork base;
    u16 unk_184;
    u8 unk_186;
    u8 unk_187;
} Emy07Work;

typedef struct Emy08Work {
    EmyWork base;
    void* palette;
    void* unk_188;
    u16 unk_18C;
} Emy08Work;

typedef struct Emy16Work {
    EmyWork base;
    void* unk_184;
    void* unk_188;
    TaskPool unk_18C;
    u8 unk_1A0;
} Emy16Work;

typedef struct Emy16bWork {
    void* tiles;
    void* palette;
    u8 unk_008[0x18];
    s32 x;
    s32 y;
    s32 z;
    u8 unk_02C;
    u8 unk_02D[0x03];
    s32 unk_030;
    s32 unk_034;
    u32 unk_038;
    s16 unk_03C;
    u8 unk_03E[0x02];
    u32 unk_040;
    u8 unk_044[0x28];
    u8 unk_06C;
    u8 unk_06D[0x2F];
    u8 unk_09C;
    u8 unk_09D;
    u8 unk_09E[0x02];
} Emy16bWork;

typedef struct Emy16pWork {
    void* tiles;
    void* palette;
    u8 unk_008[0x18];
    s32 x;
    s32 y;
    s32 z;
    u8 unk_02C;
    u8 unk_02D[0x03];
    s32 unk_030;
} Emy16pWork;

typedef struct Emy19Work {
    EmyWork base;
    u32 unk_184;
} Emy19Work;

typedef struct Emy21Work {
    EmyWork base;
    u32 unk_184;
} Emy21Work;

typedef struct Emy22Work {
    EmyWork base;
    u8 unk_184;
} Emy22Work;

typedef struct Emy23Work {
    EmyWork base;
    s32 unk_184;
} Emy23Work;

typedef struct Emy29Work {
    EmyWork base;
    s16 unk_184;
    s16 unk_186;
} Emy29Work;

typedef struct Emy31Work {
    EmyWork base;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
    u32 unk_190;
} Emy31Work;

typedef struct Emy37Work {
    EmyWork base;
    u8 unk_184;
    u8 unk_185[0x03];
    u32 unk_188;
    u16 unk_18C;
} Emy37Work;

typedef struct Emy39Work {
    EmyWork base;
    s32 unk_184;
} Emy39Work;

typedef struct Emy41Work {
    EmyWork base;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
} Emy41Work;

typedef struct Emy81Work {
    EmyWork base;
    u32 unk_184;
    u8 unk_188[0x0C];
} Emy81Work;

typedef struct Emy82Work {
    EmyWork base;
    u16 unk_184;
} Emy82Work;

typedef struct Emy83Work {
    EmyWork base;
    void* unk_184;
    TaskPool unk_188;
    s32 unk_19C;
    s32 unk_1A0;
    s16 unk_1A4;
} Emy83Work;

typedef struct Emy83bWork {
    void* tiles;
    void* palette;
    u8 unk_008[0x0A];
    u16 unk_012;
    u8 unk_014[0x0C];
    s32 x;
    s32 y;
    s32 z;
    u32 unk_02C;
    s16 unk_030;
    u8 unk_032[0x02];
    u32 unk_034;
    u8 unk_038[0x58];
} Emy83bWork;

typedef struct Emy83sWork {
    void* tiles;
    void* palette;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    u16 unk_020;
    s16 unk_022;
} Emy83sWork;

void TaskPoolInit(TaskPool* a, s32 count);
void TaskPoolDraw(TaskPool* a);
void TaskPoolUpdate(TaskPool* a);
void* TaskCreate(TaskPool* pool, void* desc, void* arg);
u8 IsTaskActiveNamed(void* task, void* name);
void TaskPoolDestroy(TaskPool* a);
void func_0800C778(EmyWork* work, void* def, void* obj);
void func_0800DF30(EmyWork* work);
void func_0800E0D0(EmyWork* work);
u16 GetRandom(void);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(u8* p);
void func_08012304(void* p);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void* AllocObjTiles(s32 size, void* src);
void AnimInit(void* a, void* b, void* c);
void AnimStart(void* a, u16 animId, u16 flags);
void AnimChange(void* a, u16 animId, u16 flags);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_0800592C(s32* value, s32 target, u16 steps);
void* AnimGetGfx(void* a);
void* AnimUpdate(AnimState* a);
void WorldToScreen(s16* x, s16* y, s32 a, s32 b, s32 c);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
u16 func_0801AF1C(s32 a);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
s32 func_0801A8A4(void* a, void* b, s32 c, s32 d);
void m4aSongNumStart(u16 n);
void func_08012614(void* a, s32 b);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);

extern BtlWork* gBtlWork;
u8 _0800CBDC(EmyWork* work);
u8 _0800CDF0(EmyWork* work);
void func_08019068(void* a, void* b, s32 c, s32 d, void* e);
s16 func_0800C980(EmyWork* work, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
void func_0801B994(EmyActor* a);
void func_080141FC(EmyActor* a);
void func_08019190(EmyActor* a, s32 b);
void func_08012AAC(s32 a, s32 b, s32 c, s32 d);
void func_08012E44(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
EmyActor* ListPoolFirst(void* node);
EmyActor* ListPoolNext(void* node);
void func_08006B4C(void);
u8 func_08006B74(void);
void func_0802F1E8(void);
void func_08013480(s32 a, s32 b, s32 c);
u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
u8 func_0801CA00(EmyActor* a);
u16 AnimGetFrame(void* a);
u16 AnimGetGfxIndex(void* a);
void func_0801BCF8(EmyActor* a);
u8 func_08011E3C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
u8 func_080128EC(void);
u8 AnimIsFinished(void* a);
void func_0800CB4C(EmyWork* work);
void func_08015834(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
void func_0801C700(EmyActor* a, s32* b, s32* c, s32 d);

extern s16 gSineTable[];
extern u8 gUnk_08A20BCE[];
extern u8 gUnk_08A23630[];
extern u8 gUnk_08B1D828[];
extern u8 gUnk_08B1D832[];
extern u8 gUnk_08B1D846[];
extern u8 gUnk_08B1B854[];
extern u8 gUnk_08F698C4[];
extern u8 gUnk_08F699C4[];
extern u8 gUnk_08F69B84[];
extern void* gTaskDescEmy16B;
extern void* gTaskDescEmy16P;
extern void* gTaskDescEmy83B;
extern void* gTaskDescEmy83S;
extern u8 gUnk_09EE04AC[];
extern u8 gUnk_09EE04E0[];
extern u8 gUnk_09EE04F4[];
extern u8 gUnk_09EE04B4[];
extern u8 gUnk_09EE1090[];
extern u8 gUnk_09EE10A4[];
extern u8 gUnk_0813D3CC[];
extern u8 gUnk_0813D434[];
extern u8 gUnk_0813D454[];
extern u8 gUnk_0813D4DC[];
extern u8 gUnk_0813D544[];
extern u8 gUnk_0813D564[];
extern u8 gUnk_0813D5CC[];
extern u8 gUnk_0813D5DC[];
extern u8 gUnk_0813D644[];
extern u8 gUnk_0813D664[];
extern u8 gUnk_0813D73C[];
extern u8 gUnk_0813D804[];
extern u8 gUnk_0813D86C[];
extern u8 gUnk_0813D88C[];
extern u8 gUnk_0813D8F4[];
extern u8 gUnk_0813D944[];
extern u8 gUnk_0813D9AC[];
extern u8 gUnk_0813D9CC[];
extern u8 gUnk_0813DA94[];
extern u8 gUnk_0813DB4C[];
extern u8 gUnk_0813DBF4[];
extern u8 gUnk_0813DC7C[];
extern u8 gUnk_0813DCE4[];
extern u8 gUnk_0813DD04[];
extern u8 gUnk_0813DD6C[];
extern u8 gUnk_0813DD8C[];
extern u8 gUnk_0813DDF4[];
extern u8 gUnk_0813DE14[];
extern u8 gUnk_0813DE7C[];
extern u8 gUnk_0813DE9C[];
extern u8 gUnk_0813DF44[];
extern u8 gUnk_0813DFAC[];
extern u8 gUnk_0813DFCC[];
extern u8 gUnk_0813E0B4[];
extern u8 gUnk_0813E14C[];
extern u8 gUnk_0813E264[];
extern u8 gUnk_0813E2CC[];
extern u8 gUnk_0813E2EC[];
extern u8 gUnk_0813E354[];
extern u8 gUnk_0813E374[];
extern u8 gUnk_0813E3DC[];
extern u8 gUnk_0813E3FC[];
extern u8 gUnk_0813E464[];
extern u8 gUnk_0813E484[];
extern u8 gUnk_0813E53C[];
extern u8 gUnk_0813E604[];
extern u8 gUnk_0813E6AC[];
extern u8 gUnk_0813E734[];
extern u8 gUnk_0813E66C[];
extern u8 gUnk_0813E744[];
extern u8 gUnk_0813E7B4[];
extern u8 gUnk_0813E7C4[];
extern u8 gUnk_0813E834[];

void task_emy_00_0(EmyWork* work, void* obj);
void task_emy_00_2(EmyWork* work);
void task_emy_00_3(EmyWork* work);
void task_emy_01_0(EmyWork* work, void* obj);
u8 task_emy_01_1(EmyWork* work);
void task_emy_01_2(EmyWork* work);
void task_emy_01_3(EmyWork* work);
void task_emy_02_0(EmyWork* work, void* obj);
void task_emy_02_2(EmyWork* work);
void task_emy_02_3(EmyWork* work);
void task_emy_03_0(EmyWork* work, void* obj);
u8 task_emy_03_1(Emy03Work* work);
void task_emy_03_2(EmyWork* work);
void task_emy_03_3(EmyWork* work);
void task_emy_04_0(Emy04Work* work, void* obj);
u8 task_emy_04_1(Emy04Work* work);
void task_emy_04_2(EmyWork* work);
void task_emy_04_3(EmyWork* work);
void task_emy_06_0(EmyWork* work, void* obj);
u8 task_emy_06_1(Emy06Work* work);
void task_emy_06_2(EmyWork* work);
void task_emy_06_3(EmyWork* work);
void task_emy_07_0(Emy07Work* work, void* obj);
void task_emy_07_2(EmyWork* work);
void task_emy_07_3(EmyWork* work);
void task_emy_08_0(Emy08Work* work, void* obj);
void task_emy_08_2(Emy08Work* work);
void task_emy_08_3(Emy08Work* work);
void task_emy_14_0(EmyWork* work, void* obj);
u8 task_emy_14_1(EmyWork* work);
void task_emy_14_2(EmyWork* work);
void task_emy_14_3(EmyWork* work);
void task_emy_15_0(EmyWork* work, void* obj);
u8 task_emy_15_1(EmyWork* work);
void task_emy_15_2(EmyWork* work);
void task_emy_15_3(EmyWork* work);
void task_emy_16_0(Emy16Work* work, void* obj);
u8 task_emy_16_1(Emy16Work* work);
void task_emy_16_2(Emy16Work* work);
void task_emy_16_3(Emy16Work* work);
void task_emy_16_b_0(Emy16bWork* work, EmySpawn* spawn);
u8 task_emy_16_b_1(Emy16bWork* work);
void task_emy_16_b_2(Emy16bWork* work);
void task_emy_16_b_3(Emy16bWork* work);
void task_emy_16_p_0(Emy16pWork* work, EmySpawn* spawn);
u8 task_emy_16_p_1(Emy16pWork* work);
void task_emy_16_p_2(Emy16pWork* work);
void task_emy_16_p_3(Emy16pWork* work);
void task_emy_18_0(EmyWork* work, void* obj);
void task_emy_18_2(EmyWork* work);
void task_emy_18_3(EmyWork* work);
void task_emy_19_0(EmyWork* work, void* obj);
void task_emy_19_2(EmyWork* work);
void task_emy_19_3(EmyWork* work);
void task_emy_21_0(Emy21Work* work, void* obj);
void task_emy_21_2(EmyWork* work);
void task_emy_21_3(EmyWork* work);
void task_emy_22_0(Emy22Work* work, void* obj);
void task_emy_22_2(EmyWork* work);
void task_emy_22_3(EmyWork* work);
void task_emy_23_0(EmyWork* work, void* obj);
u8 task_emy_23_1(Emy23Work* work);
void task_emy_23_2(EmyWork* work);
void task_emy_23_3(EmyWork* work);
void task_emy_25_0(EmyWork* work, void* obj);
u8 task_emy_25_1(EmyWork* work);
void task_emy_25_2(EmyWork* work);
void task_emy_25_3(EmyWork* work);
void task_emy_26_0(EmyWork* work, void* obj);
u8 task_emy_26_1(EmyWork* work);
void task_emy_26_2(EmyWork* work);
void task_emy_26_3(EmyWork* work);
void task_emy_27_0(EmyWork* work, void* obj);
u8 task_emy_27_1(EmyWork* work);
void task_emy_27_2(EmyWork* work);
void task_emy_27_3(EmyWork* work);
void task_emy_28_0(EmyWork* work, void* obj);
void task_emy_28_2(EmyWork* work);
void task_emy_28_3(EmyWork* work);
void task_emy_29_0(Emy29Work* work, void* obj);
void func_0803B468(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz);
u8 task_emy_29_1(Emy29Work* work);
void task_emy_29_2(EmyWork* work);
void task_emy_29_3(EmyWork* work);
void task_emy_30_0(EmyWork* work, void* obj);
void task_emy_30_2(EmyWork* work);
void task_emy_30_3(EmyWork* work);
void task_emy_31_0(EmyWork* work, void* obj);
void task_emy_31_2(EmyWork* work);
void task_emy_31_3(EmyWork* work);
void task_emy_37_0(Emy37Work* work, void* obj);
void task_emy_37_2(Emy37Work* work);
void task_emy_37_3(EmyWork* work);
void task_emy_38_0(EmyWork* work, void* obj);
u8 task_emy_38_1(EmyWork* work);
void task_emy_38_2(EmyWork* work);
void task_emy_38_3(EmyWork* work);
void task_emy_39_0(EmyWork* work, void* obj);
u8 task_emy_39_1(Emy39Work* work);
void task_emy_39_2(EmyWork* work);
void task_emy_39_3(EmyWork* work);
void task_emy_41_0(EmyWork* work, void* obj);
u8 task_emy_41_1(Emy41Work* work);
void task_emy_41_2(EmyWork* work);
void task_emy_41_3(EmyWork* work);
void task_emy_44_0(EmyWork* work, void* obj);
u8 task_emy_44_1(EmyWork* work);
void task_emy_44_2(EmyWork* work);
void task_emy_44_3(EmyWork* work);
void task_emy_81_0(EmyWork* work, void* obj);
void task_emy_81_2(EmyWork* work);
void task_emy_81_3(EmyWork* work);
void task_emy_82_0(Emy82Work* work, void* obj);
u8 func_0803DD44(EmyWork* work);
void task_emy_82_2(EmyWork* work);
void task_emy_82_3(EmyWork* work);
void task_emy_83_0(Emy83Work* work, void* obj);
u8 task_emy_83_1(Emy83Work* work);
void task_emy_83_2(Emy83Work* work);
void task_emy_83_3(Emy83Work* work);
void task_emy_83_b_0(Emy83bWork* work, EmySpawn* spawn);
u8 task_emy_83_b_1(Emy83bWork* work);
void task_emy_83_b_2(Emy83bWork* work);
void task_emy_83_b_3(Emy83bWork* work);
void task_emy_83_s_0(Emy83sWork* work, EmySpawn* spawn);
u8 task_emy_83_s_1(Emy83sWork* work);
void task_emy_83_s_2(Emy83sWork* work);
void task_emy_83_s_3(Emy83sWork* work);
void task_emy_trump_h_0(EmyWork* work, void* obj);
u8 task_emy_trump_h_1(EmyWork* work);
void task_emy_trump_h_2(EmyWork* work);
void task_emy_trump_h_3(EmyWork* work);
void task_emy_trump_s_0(EmyWork* work, void* obj);
u8 task_emy_trump_s_1(EmyWork* work);
void task_emy_trump_s_2(EmyWork* work);
void task_emy_trump_s_3(EmyWork* work);
void task_emy_test_0(EmyWork* work, void* obj);
u8 task_emy_test_1(EmyWork* work);
void task_emy_test_2(EmyWork* work);
void task_emy_test_3(EmyWork* work);

#endif /* GUARD_EMY_H */
