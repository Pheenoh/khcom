#ifndef GUARD_MODE_VSBATTLE_H
#define GUARD_MODE_VSBATTLE_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct VsActor {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
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
    u64 unk_34;
    u8 unk_3C[0x04];
    u32 unk_40;
    u8 unk_44[0x04];
    u32 unk_48;
    u32 unk_4C;
    u8 unk_50[0x4C];
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

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C;
    u8 unk_00D;
    u8 unk_00E[0x02];
    u16 unk_010;
    u8 unk_012[0x1A6];
    u32 unk_1B8;
} UnkStruct_02039BB0;

typedef struct VsBattleWork {
    u8 unk_000[0x24];
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
    u8 unk_0AC[0x40];
    u16 unk_0EC;
    u8 unk_0EE;
    u8 unk_0EF;
    u8 unk_0F0[0x30];
    s16 unk_120;
    u8 unk_122[0xA2];
    u16 unk_1C4;
    u16 unk_1C6;
    u8 unk_1C8[0x08];
} VsBattleWork;

typedef struct EmyDef {
    void* unk_00;
    void* unk_04;
    u32 unk_08;
    u8 unk_0C[0x06];
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
    void* unk_000;
    void* unk_004;
    void* unk_008;
    void* unk_00C;
    AnimState unk_010;
    TaskPool unk_028;
    VsActor unk_03C;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    u16 unk_156;
    u16 unk_158;
    u8 unk_15A;
    u8 unk_15B;
    EmyDef* unk_15C;
    u8 unk_160;
    u8 unk_161;
    u16 unk_162;
    u32 unk_164;
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
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    AnimState unk_10;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    void* unk_38;
} HumSub;

typedef struct HumWork {
    void* unk_000;
    void* unk_004;
    void* unk_008;
    HumSub* unk_00C;
    HumSub* unk_010;
    AnimState unk_014;
    TaskPool unk_02C;
    VsActor unk_040;
    u16 unk_150;
    u16 unk_152;
    u32 unk_154;
    u32 unk_158;
    u32 unk_15C;
    u32 unk_160;
    u32 unk_164;
    s32 unk_168;
    s32 unk_16C;
    u32 unk_170;
    u16 unk_174;
    u16 unk_176;
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    u32 unk_180;
    u32 unk_184;
} HumWork;

typedef struct HumSubDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} HumSubDef;

typedef struct HumDef {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u32 unk_08;
    u32 unk_0C;
} HumDef;

extern VsBattleWork* gUnk_02039B84;
extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern u8 gUnk_02039B98;
extern VsBattleWork* gUnk_02039B9C;
extern UnkStruct_02039BB0 gUnk_02039BB0;
extern u32 gUnk_02039828;
extern CharaLinkData gUnk_0203AA10;
extern CharaLinkData gUnk_0203AAC0;
extern s16 gUnk_08121400[];
extern u8 gUnk_08F69BC4[];
extern u16 gUnk_09EDA4EC[];
extern TaskDesc gUnk_09EDAE40;
extern TaskDesc gUnk_09EDAE70;
extern TaskDesc gUnk_09EDAE88;
extern TaskDesc gUnk_09EDB3F8;

void* EwramAlloc(u32 size);
void EwramFree(void* p);
void SeedRandom(u32 seed);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void SetBgOverflow(s32 bg, u8 on);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
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
void func_08004F08(void);
void func_0800592C(s32* value, s32 target, u16 steps);
void func_08005B64(void* a);
void func_08006120(s32 a, s32 b);
void func_08010CC8(void);
void func_0801071C(void);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0801227C(void);
void func_080125A4(void);
void func_08012798(s32 a, u16 b);
void func_08012810(void);
void func_08012824(void);
void func_08019068(void* a, void* b, s32 c, s32 d, void* e);
void func_0801A920(s16 a, s16 b, s16 c, s16 d);
s32 func_0801ADAC(void* a);
void func_0801AF08(void* p);
u16 func_0801AF1C(s32 a);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void func_0801B7D8(void* p);
void func_0801C068(void);
void func_0801C104(void);
void func_0801C2DC(void* a, s32 b);
u8 func_0801CA00(void* a);

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
void func_0800E5CC(HumSub* sub);

#endif
