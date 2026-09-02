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
    u16 unk_20;
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
    u8 unk_B1[0x07];
    u32 unk_B8;
    u8 unk_BC[0x12];
    s16 unk_CE;
    s16 unk_D0;
    u16 unk_D2;
    u8 unk_D4[0x34];
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
} UnkStruct_02039BB0;

typedef struct VsBattleWork {
    u8 unk_000[0x2C];
    TaskPool unk_02C;
    TaskPool unk_040;
    u8 unk_054[0x14];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    s16 unk_072;
    s16 unk_074;
    u8 unk_076[0x02];
    VsActor* unk_078;
    VsActor* unk_07C;
    u8 unk_080[0x28];
    u32 unk_0A8;
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
} EmyDef;

typedef struct EmyWork {
    void* unk_000;
    void* unk_004;
    void* unk_008;
    void* unk_00C;
    u32 unk_010;
    u8 unk_014[0x02];
    u16 unk_016;
    u8 unk_018[0x02];
    u16 unk_01A;
    u8 unk_01C[0x02];
    u16 unk_01E;
    u32 unk_020;
    u8 unk_024[0x04];
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
    u8 unk_164[0x04];
    s32 unk_168;
    u32 unk_16C;
    u8 unk_170[0x0C];
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
    s16 unk_174;
    u16 unk_176;
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    u32 unk_180;
    u32 unk_184;
} HumWork;

typedef struct HumDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} HumDef;

void ReleaseObjTiles(void* p);
void ReleaseObjPalette(void* p);
void* AnimUpdate(void* a);
void AnimInit(void* a, void* b, void* c);
void* AllocObjTiles(u16 size, void* src);
void* LoadObjPalette(void* src, s32 size);

void func_0801AF08(void* p);
void func_0801B7D8(void* p);
void TaskPoolDestroy(TaskPool* pool);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
void func_08010CC8(void);
void func_0801071C(void);
void func_0801C068(void);
void func_08004F08(void);
void func_0801227C(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void SetBgOverflow(s32 bg, u8 on);
void TaskPoolInit(TaskPool* pool, s32 count);
void* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
void func_08012798(s32 a, u16 b);
void func_0801A920(s16 a, s16 b, s16 c, s16 d);
void func_08006120(s32 a, s32 b);
void SeedRandom(u32 seed);
void* EwramAlloc(u32 size);
void func_08012810(void);
void func_0801C104(void);
void EwramFree(void* p);
void m4aSongNumStart(u16 id);
void func_08012824(void);
void func_080125A4(void);

extern VsBattleWork* gUnk_02039B84;
extern void* gUnk_02039B9C;
extern u32 gUnk_02039828;
extern CharaLinkData gUnk_0203AA10;
extern CharaLinkData gUnk_0203AAC0;
extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern u8 gUnk_02039B98;
extern TaskDesc gUnk_09EDAE40;
extern TaskDesc gUnk_09EDAE70;
extern UnkStruct_02039BB0 gUnk_02039BB0;

extern s16 gUnk_08121400[];

void func_0800CB4C(EmyWork* work);
void func_0800CB78(EmyWork* work);
void mode_vsbattle_0(u32 mode);
void mode_vsbattle_1(void);
void mode_vsbattle_2(void);
void func_0800C6B0(void);
void func_0800C6B4(void);
void func_0800C6B8(void);
void func_0800E364(HumSub* sub);
void func_0800E380(HumWork* work);
void func_0800E3D0(HumWork* work);
void func_0800E314(HumWork* work, HumSub* sub, HumDef* def);
void func_0800E5CC(HumSub* sub);

#endif
