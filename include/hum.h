#ifndef GUARD_HUM_H
#define GUARD_HUM_H

#include "types.h"
#include "text_types.h"
#include "jiminy_types.h"
#include "save_types.h"
#include "key.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
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
    u8 unk_36[0x06];
} HumSub;

typedef struct VixenSub {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x02];
    s32 unk_04;
    s32 unk_08;
} VixenSub;
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
    void* tiles;
    void* palette;
    HumSub* unk_00C;
    void* unk_010;
    AnimState anim;
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
    u32 gfx;
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
    void* tiles;
    u8* palette;
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
    u16 unk_14;
    u16 unk_16;
    void* unk_18;
    u8 unk_1C[0x04];
} VixenNdlArgs;

typedef struct VixenNdlWork {
    void* unk_00;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
} VixenNdlWork;

typedef struct VixenFrzWork {
    void* unk_00;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_2C;
    s16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
} VixenFrzWork;

typedef struct VixenIceWork {
    u32 unk_00;
    void* tiles;
    void* palette;
    AnimState anim;
    VixenSub* unk_24;
    u8 unk_28[0x5C];
    s16 unk_84;
    u16 unk_86;
    u16 unk_88;
    u8 unk_8A[0x02];
    s32 unk_8C;
    s32 unk_90;
} VixenIceWork;

typedef struct LexTmh0Work {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D[0x03];
    s32 unk_30;
    s16 unk_34;
    u8 unk_36[0x02];
} LexTmh0Work;

typedef struct LexTmhWork {
    void* unk_00;
    void* unk_04;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D;
    u16 unk_2E;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    void* unk_40;
    void* unk_44;
    u8 unk_48;
    u8 unk_49;
    s16 unk_4A;
} LexTmhWork;

typedef struct RikuSpawn {
    s32 x;
    s32 y;
    s32 z;
    u16 unk_0C;
    u16 unk_0E;
    AnimState anim;
    u32 unk_28;
    s32 unk_2C;
} RikuSpawn;

typedef struct MahluxiaFlwWork {
    s32 unk_00;
    void* tiles;
    void* palette;
    AnimState anim;
    u8 unk_24[0x04];
    s32 unk_28;
    s32 unk_2C;
    s32 x;
    s32 y;
    s32 z;
} MahluxiaFlwWork;

typedef struct MahluxiaWork {
    HumWork base;
    HumSub unk_188;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 unk_1CA;
    u8 unk_1CC[0x04];
    u16 unk_1D0;
    u8 unk_1D2[0x06];
    s16 unk_1D8;
    u8 unk_1DA[0x02];
    RikuSpawn unk_1DC[9];
    u8 unk_38C[0x04];
    TaskPool unk_390;
} MahluxiaWork;

typedef struct LaxeneKnfWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
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

typedef struct HadesSub {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
} HadesSub;

typedef struct HadesWork {
    HumWork base;
    HumSub unk_188;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 unk_1CA;
    u8 unk_1CC[0x08];
    void* unk_1D4;
    void* unk_1D8;
    void* unk_1DC;
    AnimState unk_1E0;
    AnimState unk_1F8;
    AnimState unk_210;
    void* palette;
    HadesSub unk_22C[2];
    s32 unk_27C;
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

typedef struct VixenFrgDef {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
} VixenFrgDef;

typedef struct VixenFrgSub {
    void* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} VixenFrgSub;

typedef struct VixenFrgWork {
    u8 unk_00[0x30];
    void* unk_30;
    void* palette;
    s16 unk_38;
    u16 unk_3A;
    VixenFrgSub unk_3C[15];
    u8 unk_21C;
    u8 unk_21D[0x03];
} VixenFrgWork;

typedef struct RikuWork {
    HumWork base;
    HumSub unk_188;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 unk_1CA;
    s16 unk_1CC;
    u16 unk_1CE;
    RikuSpawn unk_1D0[9];
    u8 unk_380[0x04];
} RikuWork;

typedef struct HookBombWork {
    void* unk_00;
    void* unk_04;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D[0x03];
    s32 unk_30;
    u8 unk_34;
    u8 unk_35[0x03];
    s32 unk_38;
    u16 unk_3C;
    u16 unk_3E;
    void* unk_40;
    void* unk_44;
    u8 unk_48;
    u8 unk_49;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    s32 unk_50;
} HookBombWork;

typedef struct LexRockSub {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x10];
} LexRockSub;

typedef struct LexRockWork {
    void* unk_00[12];
    void* unk_30;
    AnimState anim[12];
    s32 x;
    s32 y;
    s32 z;
    u8 unk_160;
    u8 unk_161;
    u16 unk_162;
    u16 unk_164;
    u16 unk_166;
    u8 unk_168[0x04];
    LexRockSub unk_16C[11];
    u8 unk_2A0[0x18];
    void* tiles;
    void* palette;
    u8 unk_2C0;
    u8 unk_2C1[0x03];
} LexRockWork;

typedef struct Collider {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 radius[0x24];
    u64 unk_34;
} Collider;

typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    u8 unk_008[0x10];
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
    u8 unk_0E2[0x0D];
    u8 unk_0EF;
    u8 unk_0F0[0x1C];
    s32 unk_10C;
    u8 unk_110[0x04];
    void* unk_114;
    u8 unk_118[0x14];
    s32 unk_12C;
    s32 unk_130;
    s32 unk_134;
} BtlWork;

typedef struct JiminyEntry {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16* unk_0C;
    u16* unk_10;
    void* unk_14;
} JiminyEntry;

typedef struct JiminyCell {
    s32 unk_00;
    s32 unk_04;
} JiminyCell;

typedef struct JiminyLine {
    JiminyCell unk_000[48];
} JiminyLine;

typedef struct JiminyWork {
    s32 unk_000;
    void* unk_004;
    void* unk_008;
    void* unk_00C;
    void* unk_010;
    void* unk_014;
    void* unk_018;
    void* unk_01C;
    void* unk_020;
    void* unk_024;
    void* unk_028;
    void* unk_02C;
    void* unk_030;
    void* unk_034;
    void* unk_038;
    void* unk_03C;
    void* unk_040;
    void* unk_044;
    s16 unk_048;
    s16 unk_04A;
    s32 unk_04C;
    s32 unk_050;
    s32 unk_054;
    s32 unk_058;
    s32 unk_05C;
    JiminyLine unk_060[8];
    u8 unk_C60[8];
    u8 unk_C68[8];
    u8 unk_C70;
    u8 unk_C71;
    s16 unk_C72;
    s16 unk_C74;
    s16 unk_C76;
    s16 unk_C78;
    u8 unk_C7A[0x02];
    AnimState unk_C7C;
    AnimState unk_C94;
    u16 unk_CAC;
    s16 unk_CAE;
    s16 unk_CB0;
    s16 unk_CB2;
    u16** unk_CB4;
    u16* unk_CB8;
    u16* unk_CBC;
    s16 unk_CC0;
    s16 unk_CC2;
    s16 unk_CC4;
    s16 unk_CC6;
    s16 unk_CC8;
    u8 unk_CCA[0x02];
    void* unk_CCC;
    u16 unk_CD0;
    s16 unk_CD2;
    s16 unk_CD4;
    u16 unk_CD6;
    JiminyPair unk_CD8[21];
    s32 unk_D2C;
    u8 unk_D30[0x04];
    void* unk_D34;
    s32 unk_D38;
    u16 unk_D3C;
    u16 unk_D3E;
} JiminyWork;

typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
    u8 world;
    u8 unk_00D;
    u8 floor;
    u8 unk_00F;
    u8 unk_010[0x22];
    u16 hp;
    u8 unk_034[0xC4];
    u8 unk_0F8[0x10];
    u8 level;
    u8 unk_109[0x03];
    u64 unk_10C;
    u64 unk_114;
    u8 unk_11C[0x64];
    u16 unk_180;
    u8 unk_182[0x3A];
    SaveFileSummary fileSummaries[4];
    u32 playTime;
} GameState;

#define SAVE_OK 2

typedef struct SaveHeaderData {
    u16 flags;
    u16 unk_02;
    SaveFileSummary files[4];
} SaveHeaderData;

typedef struct SaveFileLarge {
    SaveCommon common;
    u8 unk_098[0x254];
    u8 unk_2EC[0xB80];
    u8 unk_E6C[0x04];
    u8 unk_E70[0x44];
    u8 unk_EB4[0x44];
} SaveFileLarge;

typedef struct SaveFileSmall {
    SaveCommon common;
    u8 unk_098[0x254];
    u8 unk_2EC[0x110];
} SaveFileSmall;

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
    void* tiles;
    void* palette;
    TaskPool unk_220;
    u8 unk_234[0x04];
} AxcelWork;

typedef struct AxcelPtcWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
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
extern u8 gTaskDescHumLaxeneKnf[];
extern u8 gUnk_08C3724C[];
extern u8 gUnk_09EE2298[];
extern u8 gUnk_09EE22B0[];
extern u8 gUnk_09617F18[];
extern u8 gUnk_0813F214[];
extern u8 gUnk_0813FD58[];
extern u8 gUnk_0813FDA8[];
extern u16 gBldCnt;
extern BtlWork* gBtlWork;
extern GameState gGameState;
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
extern u8 gTaskDescHumAxcelPtc[];
extern u8 gTaskDescHumVixenIce[];
extern u8 gUnk_09EE1F90[];
extern u8 gUnk_09EE1FC0[];
extern u8 gUnk_0813F450[];
extern u8 gUnk_0813F448[];
extern u8 gUnk_0813F368[];
extern u8 gUnk_0813F35C[];
extern u8 gUnk_08C1E78C[];
extern VixenFrgDef gUnk_0813FA00[];
extern void* gUnk_09EE218C[];
extern u8 gUnk_0813F324[];
extern u8 gUnk_0813F31C[];
extern u8 gUnk_08BAFB62[];
extern u8 gUnk_09EE1B78[];
extern u8 gUnk_09EE1B38[];
extern u8 gUnk_08F6DC44[];
extern u8 gUnk_08B59E52[];
extern u8 gUnk_09EE17AC[];
extern u8 gUnk_09EE1798[];
extern u8 gUnk_08B5A854[];
extern u8 gUnk_08B5A85E[];
extern u8 gUnk_08B22CE4[];
extern u8 gUnk_08B22CBC[];
extern u8 gUnk_0813FD24[];
extern u8 gUnk_0813FD40[];
extern u8 gUnk_0813FBBC[];
extern u8 gTaskDescHumMahluxiaFlw[];
extern JiminyWork* gJiminyWork;
extern void* gUnk_09EDE3FC[];
extern JiminyEntry gUnk_08155554[];
extern u8 gUnk_02039CB8;
extern u32 gUnk_02039D8C;

void func_0800E168(HumWork* work, void* def);
void func_0800E380(HumWork* work);
void func_0800EFE8(HumWork* work);
void TaskPoolInit(TaskPool* a, s32 count);
void TaskPoolDraw(TaskPool* a);
void TaskPoolUpdate(TaskPool* a);
void* TaskCreate(TaskPool* pool, void* desc, void* arg);
void TaskPoolDestroy(TaskPool* a);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(u8* p);
void PushPaletteEffect(s32 a);
void PopPaletteEffect(void);
void func_0801C298(u8 a, u8 b);
void func_08012304(void* p);
u8 AnimIsFinished(AnimState* a);
void* AnimUpdate(AnimState* a);
void func_0800E314(HumWork* work, HumSub* sub, void* def);
void AnimInit(AnimState* a, s32 b, s32 c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
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
void ApproachValue(s32* value, s32 target, u16 steps);
u8 func_080035CC(s16 a, s16 b, s32 c, s32 d, s32 e, s32 f);
void func_0801C700(void* a, s32* b, s32* c, s32* d);
void func_0801A8A4(s32* a, s32* b, s32 c, s32 d);
void func_0800380C(void* work, u16 a, void* b, s32 c);
void func_08013994(s32 a, s32 b, s32 c);
u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
void func_080062F4(u16 a, s32 b);
void ColliderSetRadius(void* a, u16 b);
void func_08012324(void* a, s32 x, s32 y, s32 z);
u16 func_08006390(void);
u16 _08006338(void);
void SetBackdropColor(u16 r, u16 g, u16 b);
void func_08057E90(RikuWork* work, RikuSpawn* p);
void func_08057E2C(RikuWork* work, RikuSpawn* dst);
void func_0800F368(void* p, u16 n);
u8 func_0800F504(void* p, u16 a, u16 b, u16 c);
void LoadObjPaletteBank(u16 bank, void* src);
void func_0801AF08(HumActor* act);
s32 _0800E434(void* work);
s32 func_0800E5F0(HumWork* work);
u8 func_080128EC(void);
void SetBlendAlpha(u16 a, u16 b);
void func_08002A10(void* a, u32 b);
void* AnimGetGfx(AnimState* a);
u16 AnimGetFrame(AnimState* a);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void m4aSongNumStart(u16 n);
void m4aSongNumStop(u16 n);
s32 __modsi3(s32 a, s32 b);
void* memcpy(void* dst, const void* src, unsigned long n);
void func_080E92B8(void* p);
void func_080A324C(void* p);
void func_080A3370(void* p);
void func_080C700C(u16* out);
void func_080DDEB0(s32 a);
void func_0810962C(void* p);
void func_080E92F8(void* p);
void func_080A32DC(u8* p);
void func_080A3398(void* p);
void func_080C7024(u16* in);
void func_080DDEBC(s32 a);
void func_08109638(void* p);
void func_08065AE0(TextSlot* p, s32 n);
void func_0805F1C0(s32* p, s32 v);
u16 func_0805A55C(u16* p);
void func_0805A638(s32 a, u16** b);
void func_0805A484(void);
void func_0805A4D8(s16 a, s16 b, s16 c);
void func_0805A7D0(void);
void func_0805A514(s16 a, s16 b, s16 c);
u8 func_08006314(void);
void AnimChange(AnimState* a, u16 id, u16 flags);
u16 GetKeysRepeat(void);
void func_0805A698(s16 a, s16 b, u16** d, u16* c, u16* e, s16 f, s16 g, s16 h);
u16 func_08065B6C(u16* a, TextSlot* b);
u8 func_0800FF70(u16 a);
u8 func_0800FF00(u16 a);
s32 func_0805A574(s32 idx);
s32 SaveRepairHeader(void);
s32 SaveRepairFileLarge(u16 file);
s32 SaveRepairFileSmall(u16 file);

#endif /* GUARD_HUM_H */
