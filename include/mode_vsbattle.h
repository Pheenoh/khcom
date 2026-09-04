#ifndef GUARD_MODE_VSBATTLE_H
#define GUARD_MODE_VSBATTLE_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct VsActorSub {
    u8 unk_00[0x30];
    u16 unk_30;
} VsActorSub;

typedef struct VsActor {
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
    s16 unk_20;
    u8 unk_22[0x02];
    s32 unk_24;
    u8 unk_28[0x04];
    s16 unk_2C;
    s16 unk_2E;
    u8 unk_30[0x04];
    u64 flags;
    u8 unk_3C[0x04];
    u32 unk_40;
    u8 unk_44[0x04];
    u32 unk_48;
    u32 unk_4C;
    u8 unk_50[0x1C];
    u8 unk_6C;
    u8 unk_6D[0x0B];
    s32 unk_78;
    s32 unk_7C;
    u8 unk_80[0x10];
    VsActorSub* unk_90;
    u8 unk_94[0x08];
    u16 unk_9C;
    u8 unk_9E[0x04];
    u16 unk_A2;
    u8 unk_A4[0x04];
    s32 unk_A8;
    s32 unk_AC;
    u8 unk_B0;
    u8 unk_B1;
    u16 unk_B2;
    u32 unk_B4;
    u32 unk_B8;
    u8 unk_BC[0x12];
    s16 unk_CE;
    s16 unk_D0;
    u16 unk_D2;
    u8 unk_D4[0x10];
    void* unk_E4;
    u32 unk_E8;
    u16 unk_EC;
    u16 unk_EE;
    u8 unk_F0[0x0C];
    s32 unk_FC;
    s32 unk_100;
    u32 unk_104;
    s32 unk_108;
    s32 unk_10C;
} VsActor;

typedef struct CharaLinkData {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} CharaLinkData;

typedef struct VsTaskArg {
    s32 unk_00;
    u32 unk_04 : 8;
} VsTaskArg;

typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
    u8 world;
    u8 unk_00D;
    u8 unk_00E[0x02];
    u16 unk_010;
    u8 unk_012[0x1A6];
    u32 unk_1B8;
} GameState;

typedef struct BtlWork {
    u8 unk_000[0x10];
    s32 unk_010;
    s32 unk_014;
    u8 unk_018[0x0C];
    s32 unk_024;
    u8 unk_028[0x04];
    TaskPool unk_02C;
    TaskPool unk_040;
    u8 unk_054[0x14];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    s16 unk_072;
    s16 unk_074;
    u16 unk_076;
    VsActor* unk_078;
    VsActor* unk_07C;
    u8 unk_080[0x28];
    VsActor* unk_0A8;
    u8 unk_0AC[0x07];
    u8 unk_0B3;
    u8 unk_0B4[0x26];
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2[0x0A];
    u16 unk_0EC;
    u8 unk_0EE;
    u8 unk_0EF;
    u8 unk_0F0[0x30];
    s16 unk_120;
    u8 unk_122[0x0A];
    s32 unk_12C;
    u8 unk_130[0x94];
    u16 unk_1C4;
    u16 unk_1C6;
    u8 unk_1C8[0x08];
} BtlWork;

typedef struct EmyDef {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u32 unk_1C;
} EmyDef;

typedef struct EmyObj {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} EmyObj;

typedef struct EmyWork {
    void* tiles;
    void* unk_004;
    void* unk_008;
    void* gfx;
    AnimState anim;
    TaskPool unk_028;
    VsActor unk_03C;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    s16 unk_156;
    u16 unk_158;
    u8 unk_15A;
    u8 unk_15B;
    EmyDef* unk_15C;
    u8 angle;
    u8 unk_161;
    u16 unk_162;
    s32 unk_164;
    s32 unk_168;
    u32 unk_16C;
    s32 unk_170;
    s32 unk_174;
    s32 unk_178;
    s32 unk_17C;
    s32 unk_180;
} EmyWork;

typedef struct HumSub {
    void* unk_00;
    void* tiles;
    void* palette;
    void* unk_0C;
    AnimState anim;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    void* gfx;
} HumSub;

typedef struct HumWork {
    void* unk_000;
    void* tiles;
    void* palette;
    HumSub* unk_00C;
    HumSub* unk_010;
    AnimState anim;
    TaskPool unk_02C;
    VsActor unk_040;
    s16 unk_150;
    s16 unk_152;
    u32 unk_154;
    u32 unk_158;
    u32 unk_15C;
    u32 unk_160;
    s32 unk_164;
    s32 unk_168;
    s32 unk_16C;
    u32 unk_170;
    s16 unk_174;
    u16 unk_176;
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    void* gfx;
    u32 unk_184;
} HumWork;

typedef struct HumSubDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} HumSubDef;

typedef struct PrizeCardArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x14];
} PrizeCardArg;

typedef struct HumDef {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u32 unk_08;
    u32 unk_0C;
} HumDef;

extern BtlWork* gBtlWork;
extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern u8 gUnk_02039B98;
extern BtlWork* gUnk_02039B9C;
extern GameState gGameState;
extern u32 gSioPlayerId;
extern CharaLinkData gUnk_0203AA10;
extern CharaLinkData gUnk_0203AAC0;
extern s16 gSineTable[];
extern u8 gUnk_08F69BC4[];
extern u16 gUnk_09EDA4EC[];
extern TaskDesc gTaskDescBtlSora;
extern TaskDesc gTaskDescBtlMap;
extern TaskDesc gTaskDescBtlShadow;
extern TaskDesc gTaskDescBtlBadstatus;

void* EwramAlloc(u32 size);
void EwramFree(void* p);
void SeedRandom(u32 seed);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void SetBgOverflow(s32 bg, u8 on);
void TaskPoolInit(TaskPool* a, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* a);
void TaskPoolDestroy(TaskPool* pool);
void* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
void AnimInit(void* a, void* b, void* c);
void* AnimUpdate(void* a);
void* AnimGetGfx(void* a);
void* AllocObjTiles(u16 size, void* src);
void ReleaseObjTiles(void* p);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjPalette(void* p);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void WorldToScreen(s16* x, s16* y, s32 a, s32 b, s32 c);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void m4aSongNumStart(u16 id);
u8 AnimIsFinished(AnimState* a);
void ApproachValue(s32* value, s32 target, u16 steps);
u16 GetRandom(void);
void SetBgMode2(void);
void func_080063A8(void);
void func_08006238(s32 a, s32 b, s32 c);
u8 func_08006314(void);
void func_0800F5A4(HumWork* work, s32 b, s32 c, s32 d, s32 e);
void func_0800592C(s32* value, s32 target, u16 steps);
void AnimReset(void* a);
void func_08006120(s32 a, s32 b);
void func_08010CC8(void);
void func_0801071C(void);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0801227C(void);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void func_08012614(void* a, s32 b);
u8 func_080128EC(void);
void func_08013A68(s32 a, s32 b, s32 c);
void func_08014A34(s32 x, s32 y);
void func_08014AAC(s32 x, s32 y);
void func_0801536C(void);
void func_080125A4(void);
void func_08012798(s32 a, u16 b);
void func_08012810(void);
void func_08012824(void);
void func_08019050(s32 a, s32 b, s32 c, s32 d);
void func_08019068(void* a, void* b, s32 c, s32 d, void* e);
void func_08019190(VsActor* a, s32 b);
u32 func_0801A8A4(s32* px, s32* py, s16 rx, s16 ry);
void func_0801A920(s16 a, s16 b, s16 c, s16 d);
s32 func_0801ADAC(void* a);
void func_0801AF08(void* p);
void func_0801AF4C(VsActor* a);
u16 func_0801AF1C(s32 a);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void func_0801B7D8(void* p);
void func_0801B008(void);
void func_0801B918(VsActor* a);
void func_0801C068(void);
void func_0801C104(void);
void func_0801C700(VsActor* actor, s32* a, s32* b, s32* c);
void func_0801BBF0(VsActor* a);
void func_0801BCD4(void* a);
void func_0801BCF8(VsActor* a);
void func_0801B994(VsActor* a);
void func_0801C830(VsActor* a);
u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
u8 func_08005AC4(AnimState* a);
void func_08006B4C(void);
u8 func_08006B74(void);
void SetBlendAlpha(u16 a, u16 b);
void func_08013DB8(s32 a, s32 b, s32 c);
void func_08013E4C(s32 a, s32 b, s32 c);
extern vu32 gFrameCounter;
extern u16 gBldCnt;
void func_0801C2DC(void* a, s32 b);
u8 func_0801CA00(void* a);
void func_0802F284(s32 a, s32 b, s32 c);
void func_0807E1A0(void);
void func_0807E1AC(void);
void func_0807E1B8(void);
void func_0807E1C4(void);
void func_0807E1D0(void);
void func_0807E1DC(void);
void func_0807E1E8(void);
u8 func_0807E29C(void);
void func_0807E2F4(void);
void func_08096DC4(TaskPool* pool, void* arg);

void mode_vsbattle_0(u32 mode);
void mode_vsbattle_1(void);
void mode_vsbattle_2(void);
void func_0800C6B0(void);
void func_0800C6B4(void);
void func_0800C6B8(void);
void func_0800C778(EmyWork* work, EmyDef* def, EmyObj* obj);
s16 func_0800C980(EmyWork* work, s16 a, s16 b, s16 c, s32 d, s16 e, u16 f, s16 g, s16 h, u16 i);
void func_0800CB4C(EmyWork* work);
void func_0800CB78(EmyWork* work);
u8 _0800CBDC(EmyWork* work);
void func_0800CD40(EmyWork* work);
void func_0800DF30(EmyWork* work);
void func_0800E0D0(EmyWork* work);
void func_0800E168(HumWork* work, HumDef* def);
void func_0800E314(HumWork* work, HumSub* sub, HumSubDef* def);
void func_0800E364(HumSub* sub);
void func_0800E380(HumWork* work);
void func_0800E3D0(HumWork* work);
s32 _0800E434(HumWork* work);
s32 _0800CDF0(EmyWork* work);
void func_0800E5CC(HumSub* sub);
s32 func_0800E5F0(HumWork* work);

#endif
