#ifndef GUARD_HUM_H
#define GUARD_HUM_H

#include "types.h"

typedef struct AnimState {
    void** unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    void* unk_14;
} AnimState;

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
    u8 unk_36[0x06];
} HumSub;

typedef struct VixenSub {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x02];
    s32 unk_04;
    s32 unk_08;
} VixenSub;

typedef struct HumListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct HumListNode* unk_08;
    u16 unk_0C;
} HumListNode;

typedef struct TaskPool {
    HumListNode head;
    void* unk_10;
} TaskPool;

typedef struct HumActor {
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
    u8 unk_A4[0x14];
    u32 unk_B8;
    u8 unk_BC[0x12];
    s16 unk_CE;
    s16 unk_D0;
    u16 unk_D2;
    u8 unk_D4[0x3C];
} HumActor;

typedef struct HumWork {
    void* unk_000;
    void* unk_004;
    void* unk_008;
    HumSub* unk_00C;
    void* unk_010;
    AnimState unk_014;
    TaskPool unk_02C;
    HumActor unk_040;
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

typedef struct CloudWork {
    HumWork base;
    u32 unk_188;
    u16 unk_18C;
    u16 unk_18E;
    u16 unk_190;
    u8 unk_192[0x02];
} CloudWork;

typedef struct HookMoonWork {
    void* unk_00;
    u8* unk_04;
    u16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
} HookMoonWork;

typedef struct VixenNdlArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x06];
    s16 unk_12;
    u8 unk_14[0x04];
    void* unk_18;
    u8 unk_1C[0x04];
} VixenNdlArgs;

typedef struct VixenNdlWork {
    void* unk_00;
    void* unk_04;
    AnimState unk_08;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
} VixenNdlWork;

typedef struct VixenFrzWork {
    void* unk_00;
    void* unk_04;
    AnimState unk_08;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
} VixenFrzWork;

typedef struct VixenIceWork {
    s32 unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    VixenSub* unk_24;
    u8 unk_28[0x64];
    s32 unk_8C;
    u8 unk_90[0x04];
} VixenIceWork;

typedef struct LexTmh0Work {
    void* unk_00;
    void* unk_04;
    AnimState unk_08;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D[0x03];
    s32 unk_30;
    s16 unk_34;
    u8 unk_36[0x02];
} LexTmh0Work;

typedef struct LexTmhWork {
    void* unk_00;
    void* unk_04;
    AnimState unk_08;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u16 unk_2E;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    void* unk_40;
    void* unk_44;
    u16 unk_48;
    u16 unk_4A;
} LexTmhWork;

typedef struct MahluxiaFlwWork {
    s32 unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    u8 unk_24[0x04];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
} MahluxiaFlwWork;

typedef struct MahluxiaWork {
    HumWork base;
    u8 unk_188[0x3C];
    s32 unk_1C4;
    u16 unk_1C8;
    u8 unk_1CA[0x1DA];
} MahluxiaWork;

typedef struct LaxeneKnfWork {
    void* unk_00;
    void* unk_04;
    AnimState unk_08;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u16 unk_2E;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
} LaxeneKnfWork;

typedef struct LaxeneWork {
    HumWork base;
    s32 unk_188;
    u16 unk_18C;
    u16 unk_18E;
    u16 unk_190;
    u16 unk_192;
    TaskPool unk_194;
} LaxeneWork;

typedef struct VixenWork {
    HumWork base;
    s32 unk_188;
    u8 unk_18C[0x16];
    u16 unk_1A2;
    TaskPool unk_1A4;
    u8 unk_1B8[0x0C];
    VixenSub unk_1C4[3];
    u8 unk_1E8[0x30];
} VixenWork;

typedef struct LexceusWork {
    HumWork base;
    u8 unk_188[0x38];
    s32 unk_1C0;
    s32 unk_1C4;
    u8 unk_1C8[0x02];
    u16 unk_1CA;
    s16 unk_1CC;
    u16 unk_1CE;
    s32 unk_1D0;
    s32 unk_1D4;
    TaskPool unk_1D8;
    s32 unk_1EC;
    s32 unk_1F0;
    s32 unk_1F4;
    u16 unk_1F8;
    u16 unk_1FA;
    s32 unk_1FC;
    u8 unk_200[0x04];
} LexceusWork;

typedef struct HadesWork {
    HumWork base;
    u8 unk_188[0x4C];
    void* unk_1D4;
    void* unk_1D8;
    void* unk_1DC;
    u8 unk_1E0[0x48];
    void* unk_228;
    u8 unk_22C[0x54];
} HadesWork;

typedef struct LeonWork {
    HumWork base;
    u16 unk_188;
    u8 unk_18A;
    u8 unk_18B;
    u64 unk_18C;
    u64 unk_194;
} LeonWork;

typedef struct AnsemWork {
    HumWork base;
    HumSub unk_188;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 unk_1CA;
    s16 unk_1CC;
    u8 unk_1CE[0x0E];
} AnsemWork;

typedef struct VixenFrgSub {
    void* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x0C];
    u16 unk_1C;
    u16 unk_1E;
} VixenFrgSub;

typedef struct VixenFrgWork {
    u8 unk_00[0x30];
    void* unk_30;
    void* unk_34;
    u16 unk_38;
    u16 unk_3A;
    VixenFrgSub unk_3C[15];
    u8 unk_21C;
    u8 unk_21D[0x03];
} VixenFrgWork;

typedef struct RikuWork {
    HumWork base;
    u8 unk_188[0x3C];
    s32 unk_1C4;
    u16 unk_1C8;
    u8 unk_1CA[0x1BA];
} RikuWork;

typedef struct RikuSpawn {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    AnimState unk_10;
    u32 unk_28;
    s32 unk_2C;
} RikuSpawn;

typedef struct HookBombWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x38];
    void* unk_40;
    void* unk_44;
    u8 unk_48[0x0C];
} HookBombWork;

typedef struct LexRockWork {
    void* unk_00[12];
    void* unk_30;
    u8 unk_34[0x130];
    u16 unk_164;
    u8 unk_166[0x152];
    void* unk_2B8;
    void* unk_2BC;
    u8 unk_2C0[0x04];
} LexRockWork;

typedef struct Collider {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x24];
    u64 unk_34;
} Collider;

typedef struct BtlWork {
    u8 unk_000[0x18];
    u8 unk_018;
    u8 unk_019[0x0B];
    s32 unk_024;
    u8 unk_028[0x40];
    u64 unk_068;
    u8 unk_070[0x0C];
    Collider* unk_07C;
    u8 unk_080[0x5A];
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2[0x32];
    void* unk_114;
    u8 unk_118[0x18];
    s32 unk_130;
    s32 unk_134;
} BtlWork;

typedef struct BtlSetup {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C[0x100];
    u64 unk_10C;
    u64 unk_114;
} BtlSetup;

typedef struct AxcelWork {
    HumWork base;
    HumSub unk_188;
    HumSub unk_1C4;
    s32 unk_200;
    u16 unk_204;
    u16 unk_206;
    u16 unk_208;
    u16 unk_20A;
    s32 unk_20C;
    s32 unk_210;
    u8 unk_214[0x04];
    void* unk_218;
    void* unk_21C;
    TaskPool unk_220;
    u8 unk_234[0x04];
} AxcelWork;

typedef struct AxcelPtcWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
} AxcelPtcWork;

typedef struct RobeWork {
    HumWork base;
    u16 unk_188;
    u8 unk_18A[0x02];
} RobeWork;

extern u8 gUnk_08BCB3D8[];
extern u8 gUnk_08EE4264[];
extern u8 gUnk_08F6DC84[];
extern u8 gUnk_09618478[];
extern u8 gUnk_08C3151E[];
extern u8 gUnk_09EE1C94[];
extern u8 gUnk_09EE1CB4[];
extern u8 gUnk_09EE2250[];
extern u8 gUnk_09EE2288[];
extern u8 gUnk_09EE26B4[];
extern u8 gUnk_09EE26CC[];
extern u8 gUnk_08BD99F4[];
extern u8 gUnk_09618458[];
extern u8 gUnk_09EE1DA4[];
extern u8 gUnk_09EE1DB4[];
extern u8 gUnk_0813F0B8[];
extern u8 gUnk_0813F1E0[];
extern u8 gUnk_0813F1E8[];
extern u8 gUnk_0813FA8C[];
extern u8 gUnk_0813FB38[];
extern u8 gUnk_08B5A872[];
extern u8 gUnk_08F6DC64[];
extern u8 gUnk_0813F480[];
extern u8 gUnk_0813F588[];
extern u8 gUnk_0813F7A8[];
extern u8 gUnk_0813F8C8[];
extern u8 gUnk_09EDB668[];
extern u8 gUnk_08C3724C[];
extern u8 gUnk_09EE2298[];
extern u8 gUnk_09EE22B0[];
extern u8 gUnk_09617F18[];
extern u8 gUnk_0813F214[];
extern u8 gUnk_0813FD58[];
extern u8 gUnk_0813FDA8[];
extern u16 gBldCnt;
extern BtlWork* gUnk_02039B84;
extern BtlSetup gUnk_02039BB0;
extern u8 gUnk_0813F91C[];
extern s16 gSineTable[];
extern u32 gFrameCounter;
extern u8 gUnk_08F6DCA4[];
extern u8 gUnk_09EE2690[];
extern u8 gUnk_09EE26B0[];
extern u8 gUnk_0813EF28[];
extern u8 gUnk_0813EDD0[];
extern u8 gUnk_0813F768[];
extern u8 gUnk_0813F760[];
extern u8 gUnk_0813F5C8[];
extern u8 gUnk_0813FDF4[];
extern u8 gUnk_0813FDD4[];
extern u8 gUnk_08B22BA8[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_08BF73C6[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09EDB698[];
extern u8 gUnk_09EDB6E0[];
extern u8 gUnk_09EE1F90[];
extern u8 gUnk_09EE1FC0[];

void func_0800E168(HumWork* work, void* def);
void func_0800E380(HumWork* work);
void func_0800EFE8(HumWork* work);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolUpdate(TaskPool* pool);
void* TaskCreate(TaskPool* pool, void* desc, void* arg);
void TaskPoolDestroy(TaskPool* pool);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(void* p);
void func_08007E68(s32 a);
void func_08007E7C(void);
void func_0801C298(u8 a, u8 b);
void func_08012304(void* p);
u8 AnimIsFinished(void* a);
void* AnimUpdate(void* a);
void func_0800E314(HumWork* work, HumSub* sub, void* def);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, s32 b, s32 c);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
u16 GetRandom(void);
u16 func_0801AF1C(s32 a);
void func_08019068(void* a, AnimState* b, s32 c, s32 d, void* e);
void func_08054100(AxcelWork* work, HumSub* sub);
void* AllocObjTiles(s32 a, void* b);
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_08012614(void* a, s32 b);
void func_080058FC(s32* p, s32 target, u16 steps);
u8 func_080035CC(s16 a, s16 b, s32 c, s32 d, s32 e, s32 f);
void func_0801C700(void* a, s32* b, s32 c, s32 d);
void func_0800F368(void* p, u16 n);
u8 func_0800F504(void* p, u16 a, u16 b, u16 c);
void LoadObjPaletteBank(u16 bank, void* src);
void func_0801AF08(HumActor* act);
s32 _0800E434(void* work);
u8 func_0800E5F0(void* work);
u8 func_080128EC(void);
void SetBlendAlpha(u16 a, u16 b);
void func_08002A10(void* a, u32 b);
void* AnimGetGfx(AnimState* a);
u16 func_08005B34(AnimState* a);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void m4aSongNumStart(u16 n);
void m4aSongNumStop(u16 n);
s32 __modsi3(s32 a, s32 b);

#endif /* GUARD_HUM_H */
