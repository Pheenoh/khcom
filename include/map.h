#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "types.h"
#include "malloc.h"
#include "fld_types.h"

typedef struct UnkStruct_080DFB8C {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
    u16* unk_14;
    u16* unk_18;
    u16* unk_1C;
} UnkStruct_080DFB8C;

typedef struct UnkStruct_080DFF1C {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
} UnkStruct_080DFF1C;

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14[0x04];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x30];
    u8 unk_58[0x10];
    s32 unk_68;
    s16 unk_6C;
    u16 unk_6E;
    u32 unk_70;
    u16 unk_74;
    u16 unk_76;
    u8 unk_78[0x14];
    u8 unk_8C[0x14];
    u8 unk_A0[0x14];
    u8 unk_B4[0x14];
    u8 unk_C8[0x14];
    s32 unk_DC;
    s32 unk_E0;
    u8 unk_E4[0x04];
} UnkStruct_02039BA0;

typedef struct UnkStruct_0203C7AC {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11[0x03];
    s32 unk_14;
    u8 unk_18;
    u8 unk_19[0x03];
    s32 unk_1C;
    u8 unk_20;
    u8 unk_21[0x03];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x14];
} UnkStruct_0203C7AC;

typedef struct UnkStruct_02034F20 {
    u16 unk_00;
    u16 unk_02;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09[0x0B];
    s32 unk_14;
} UnkStruct_02034F20;

typedef struct UnkStruct_02034F24 {
    u8 unk_00[0x08];
} UnkStruct_02034F24;

typedef struct UnkStruct_02034F34 {
    u8 unk_00[0x18];
    u16* unk_18;
    u16* unk_1C;
    u16* unk_20;
} UnkStruct_02034F34;

typedef struct UnkStruct_02034F80 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_02034F80;

typedef struct UnkStruct_02034F7C {
    u8 unk_00;
    u8 unk_01[0x03];
    UnkStruct_02034F80* unk_04;
} UnkStruct_02034F7C;

typedef struct UnkStruct_02034F84 {
    u8 unk_00;
    u8 unk_01;
} UnkStruct_02034F84;

typedef struct UnkStruct_02039D6C {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
} UnkStruct_02039D6C;

typedef struct UnkStruct_0203C590 {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08[0x10];
    u8 unk_18[0x04];
    u8 unk_1C[0x200];
} UnkStruct_0203C590;

typedef struct UnkStruct_02039D34 {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_02039D34;

typedef struct UnkStruct_02039BB0Tail {
    UnkStruct_02039D34 unk_00[0x0D];
} UnkStruct_02039BB0Tail;

typedef struct UnkStruct_02039BF0 {
    u8 unk_00[0x1C];
    u8 unk_1C[0x1C];
} UnkStruct_02039BF0;

typedef struct GameState {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 flags;
    u8 world;
    u8 unk_0D;
    u8 floor;
    u8 unk_0F;
    u8 unk_10[0x04];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    u8 unk_20[0x04];
    u8 unk_24;
    u8 unk_25[0x1B];
    UnkStruct_02039BF0 unk_40[3];
    u8 unk_E8[0x92];
    u16 unk_17A;
    u16 unk_17C;
    u16 unk_17E;
    u8 unk_180[0x04];
    UnkStruct_02039BB0Tail unk_184;
    u32 unk_1B8;
} GameState;

typedef struct UnkStruct_080E92B8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x02];
    u8 unk_04[0x21C];
    UnkStruct_02039BB0Tail unk_220;
} UnkStruct_080E92B8;

typedef struct UnkStruct_09EF8370 {
    u8 unk_00[0x2C];
    void* unk_2C;
    u8 unk_30[0x04];
    u16 unk_34;
} UnkStruct_09EF8370;

typedef struct UnkStruct_0984BB9C {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
    u8 unk_0D[0x03];
} UnkStruct_0984BB9C;

typedef struct UnkStruct_0984BC9C {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u32 unk_0C;
    void* unk_10;
    u16 unk_14;
    u16 unk_16;
    char unk_18[0x70];
} UnkStruct_0984BC9C;

typedef struct UnkStruct_080E6034 {
    UnkStruct_080DFF1C unk_00;
    u8 unk_10;
    u8 unk_11[0x03];
    s32 unk_14;
    u8 unk_18[0x04];
    u8 unk_1C[0x14];
    UnkStruct_0984BC9C* unk_30;
    void* unk_34;
} UnkStruct_080E6034;

typedef struct UnkStruct_0203C7B0 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
} UnkStruct_0203C7B0;

typedef struct UnkStruct_080E7D80 {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x0B];
    u8 unk_15;
    u8 unk_16[0x0E];
    void* unk_24;
} UnkStruct_080E7D80;

typedef struct UnkStruct_0203C7B8 {
    u16 unk_00;
    u8 unk_02[0x02];
    UnkStruct_080DFF1C unk_04;
    UnkStruct_080E7D80* unk_14;
} UnkStruct_0203C7B8;

typedef struct UnkStruct_080DEDD8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0x04];
} UnkStruct_080DEDD8;

typedef struct UnkStruct_080DEE18 {
    u8 unk_00[0x0B];
    u8 unk_0B;
    u8 unk_0C;
} UnkStruct_080DEE18;

typedef struct UnkStruct_080E8374 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x0E];
    s16 unk_1A;
} UnkStruct_080E8374;

typedef struct UnkStruct_080E8864 {
    const u8* unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    const u8* unk_08;
    u16* unk_0C;
} UnkStruct_080E8864;

typedef struct UnkStruct_09EF70D0 {
    u8 unk_00[0x24];
    UnkStruct_080E8864* unk_24;
    UnkStruct_080E8864* unk_28;
    void* unk_2C;
    s32* unk_30;
    s32* unk_34;
    u16 unk_38;
} UnkStruct_09EF70D0;

typedef struct UnkStruct_080E8E24 {
    u8 unk_00[0x02];
    u16 unk_02;
} UnkStruct_080E8E24;

typedef struct UnkStruct_080E8F50 {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x04];
    u16 unk_14;
    u8 unk_16[0x02];
} UnkStruct_080E8F50;

typedef struct UnkStruct_080EF4BC {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x03];
} UnkStruct_080EF4BC;

typedef struct UnkStruct_080E5B90 {
    UnkStruct_0984BC9C* unk_00;
    void* unk_04;
    UnkStruct_080DFF1C unk_08;
    u8 unk_18;
    u8 unk_19[0x03];
    s32 unk_1C;
} UnkStruct_080E5B90;

typedef struct UnkStruct_080E590C {
    UnkStruct_0984BC9C* unk_00;
    u16 unk_04;
    u16 unk_06;
    UnkStruct_080DFF1C unk_08;
    s32 unk_18;
    u8 unk_1C;
    u8 unk_1D[0x03];
    u8 unk_20[0x28];
    u8 unk_48[0x2C];
    u8 unk_74;
    u8 unk_75[0x0B];
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x1C];
    u8 unk_A4[0x18];
    void* tiles;
    void* palette;
    void* gfx;
    s16 unk_C8;
    s16 unk_CA;
    void* unk_CC;
    u8 unk_D0[0x14];
    u8 unk_E4[0x14];
} UnkStruct_080E590C;

typedef struct UnkStruct_080F023C {
    u8 unk_000[0xD4];
    s32 unk_D4;
    s32 unk_D8;
    s32 unk_DC;
    u8 unk_E0[0x18];
    s32 unk_F8;
    s32 unk_FC;
} UnkStruct_080F023C;
typedef struct UnkStruct_080ECFE8 {
    u8 unk_000[0x20];
    FldRes* unk_020;
    u8 unk_024[0x14];
    FldRes* unk_038;
    FldRes* unk_03C;
    u8 unk_040[0x20];
    FldRes* unk_060;
    u8 unk_064[0x0C];
    FldRes* unk_070;
    u8 unk_074[0xE4];
    FldRes* unk_158[3];
} UnkStruct_080ECFE8;

typedef struct UnkStruct_080ECA88 {
    u8 unk_00[0x44];
    void* unk_44;
    u8 unk_48[0x04];
    void* unk_4C;
    u8 unk_50[0x04];
    void* unk_54;
    void* unk_58;
    u8 unk_5C[0x04];
    void* unk_60;
    void* unk_64;
} UnkStruct_080ECA88;

typedef struct UnkStruct_080ED06C {
    FldRes* unk_000;
    u8 unk_004[0x134];
    FldRes* unk_138;
    u8 unk_13C[0x04];
    FldRes* unk_140;
} UnkStruct_080ED06C;

typedef struct UnkStruct_080EE50C {
    u8 unk_000[0x14];
    FldRes* unk_014;
    u8 unk_018[0x1C];
    FldRes* unk_034;
    u8 unk_038[0x08];
    FldRes* unk_040;
    u8 unk_044[0x14C];
    FldRes* unk_190;
} UnkStruct_080EE50C;

typedef struct UnkStruct_080EE580 {
    FldRes* unk_000;
    u8 unk_004[0x164];
    FldRes* unk_168;
    u8 unk_16C[0x14];
    FldRes* unk_180;
    u8 unk_184[0x04];
    FldRes* unk_188;
} UnkStruct_080EE580;

extern UnkStruct_02039BA0* gUnk_02039BA0;
extern GameState gGameState;
extern UnkStruct_02039D6C gUnk_02039D6C[];
extern UnkStruct_0203C7AC* gUnk_0203C7AC;
extern UnkStruct_0203C7B0 gUnk_0203C7B0;
extern UnkStruct_0203C7B8* gUnk_0203C7B8;
extern u16 gBldCnt;
extern vu16 gDispCnt;
extern u32 gFrameCounter;
extern UnkStruct_0203C590 gUnk_0203C590;
extern UnkStruct_02034F84 gUnk_0203C598[];
extern void* gMPlayInfo_BGM;
extern const UnkStruct_0203C7B0 gUnk_0984D1F4[];
extern UnkStruct_09EF70D0* gUnk_09EF70D0[];
extern UnkStruct_09EF8370* gUnk_09EF8370[];
extern UnkStruct_0984BC9C* gUnk_09EF83F8[];
extern UnkStruct_080E7D80 gUnk_0984C1CC;
extern UnkStruct_080E7D80 gUnk_0984C204;
extern u8 gTaskDescMapGmkJump[];
extern u8 gTaskDescMapGmkDmy[];
extern UnkStruct_02034F7C gUnk_0984CECC[];
extern const u8 gUnk_0984B8F8[];
extern const u8 gUnk_0984B905[];
extern u8 gUnk_0984B860[][8];
extern const u8 gUnk_0984D134[][8];
extern const u8 gUnk_0984D314[][4];
extern const u8 gUnk_0984D32C[][4];
extern const u8 gUnk_0984D3F8[][4];
extern const u16 gUnk_09858238[];
extern const u8 gUnk_09961A64[][320];
extern const u8 gUnk_09962BE4[][320];
extern const u8 gUnk_09963D64[][320];
extern const u8 gUnk_09964EE4[][320];
extern const u8 gUnk_099581A4[];
extern const u8 gUnk_09966064[];
extern s16 gSineTable[];
extern void* gModeBattle;
extern void* gModeRikuBtlTutorial;
extern void* gModeRikuBtlTutorial;
extern void* gTaskDescLockon;
extern void* gTaskDescWLogo;
extern void* gModePooh;
extern void* gModeAllmap;
extern const u8 gUnk_09EF6A34[];
extern const u8 gUnk_09EF6A42[];
extern u8 (*gUnk_09EF6A50[])(UnkStruct_080DFF1C*);
extern void* gModeMapChk;
extern void* gModeMapDbg;
extern const u8 gUnk_09EF6AB0[];
extern void* gModeMapFld;
extern void* gModeWorldselect;
extern void* gModeMapFix;
extern void* gTaskDescMapRnd;
extern void* gTaskDescFldSora;
extern void* gTaskDescFldRiku;
extern void* gTaskDescMapFix;
extern void* gTaskDescMapMenu;
extern void* gTaskDescMapAnm;
extern void* gTaskDescMapDbg;
extern void* gTaskDescMapGmkTutorial;
extern void* gTaskDescMapDmg;
extern void* gTaskDescMapFloor;
extern void* gTaskDescMapTutorial;
extern void* gTaskDescMapPrize;
extern void* gTaskDescMapPrzCard;
extern void* gTaskDescMapSpark;
extern void* gTaskDescMapDonald;
extern void* gTaskDescMapGoofy;
extern void* gTaskDescMapNamine;
extern void* gTaskDescMapNiseriku;
extern void* gTaskDescMapMickey;

void* memcpy(void* dst, const void* src, unsigned long n);
void func_08000DE8(void* a, void* b);
void ListPoolInit(void* pool);
void ListPoolAddFree(void* a, void* pool, void* b);
void* ListPoolActivate(void* node, void* pool);
void* ListPoolFirst(void* pool);
void* ListPoolNext(void* node);
void* ListPoolFirstFree(void* pool);
u16 GetRandom(void);
u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
s16 GetAngleDiff(u8 a, u8 b);
s32 abs(s32 x);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void SetBgScroll(s32 a, u16 b, u16 c);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void* TaskCreate(void* pool, void* desc, void* arg);
void TaskPoolInit(void* pool, s32 count);
void TaskPoolUpdate(void* pool);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void func_08012304(void* a);
void TaskPoolDestroy(void* pool);
void TaskPoolDraw(void* pool);
void* AnimUpdate(void* a);
void m4aMPlayVolumeControl(void* a, u16 b, u16 c);
void m4aSongNumStart(u16 id);
u16 CountCardsById(u16 cardId);
void ModeRequest(void* mode, s32 arg);
s32 func_08003C9C(s32 a);
void func_080038E4(void* a, void* b, void* c);
void func_080045AC(void* a, void* b, u8 c, u8 d, s32 e);
void func_080062F4(u16 a, s32 b);
u8 func_08005AC4(void* a);
void func_08012614(void* a, s32 b);
u8 func_08012660(void* a, s32 b);
u8 func_080840E4(void);
u8 func_080A42C8(s32 a);
s32 func_080DF548(s32 a);
void func_080DF6D0(UnkStruct_0203C7AC* p, u8 a);
u8 func_080DF750(void);
void func_080DF9A8(void);
void func_080DF9C4(void);
void func_080DFAA8(void);
void func_080DF244(void);
UnkStruct_080DEDD8* func_080DEDD8(s32 a);
UnkStruct_080DEE18* func_080DEE18(u8 a);
u8 func_080DFBDC(UnkStruct_080DFF1C* p);
UnkStruct_080DFB8C* func_080DFB8C(s32 x, s32 y);
UnkStruct_080DFB8C* func_080E08BC(s16 x, s16 y);
void func_080E0960(UnkStruct_080DFB8C* p, s32 n);
void sub_080E0B00(UnkStruct_080DFB8C* p, s32 n);
void func_080E2668(UnkStruct_02034F20* p, u8 a);
void func_080E4EB0(void* a, void* b, void* c, s16 d, s16 e);
void func_080E507C(void* a, void* b, void* c, s16 d, s16 e);
u8 func_080E524C(UnkStruct_080DFF1C* a, s32* b);
void func_080E5354(UnkStruct_080DFF1C* a, s32* b);
void func_080E56B4(void* a);
s32 func_080E55A4(s16 x, s16 y);
void func_080E5B90(UnkStruct_080E5B90* p, UnkStruct_0984BC9C* q);
u8 func_080E59D8(UnkStruct_080E5B90* w);
u8 func_080E5AC8(UnkStruct_080E5B90* w);
void func_080E5C00(UnkStruct_080E5B90* w, u8 a, u8 b);
void func_080E5EAC(UnkStruct_080E590C* p);
u8* func_080E8644(void* a, u16 b, u16 c);
void* func_080E8668(u8 a);
u8 func_080E8374(UnkStruct_080E8374* p);
u16 func_080E83C4(void);
void func_080E83DC(s32 a, s32 b, s32 c);
void func_080E55E4(const u8* src);
void func_080E5800(void);
void func_080E8864(UnkStruct_080E8864* p);
u8 func_080E87EC(s16 x, s16 y, const u8* p);
void func_080E8724(s16 x, s16 y, const u8* p, u16* base);
void func_080E893C(s16 x, s16 y, const u8* p, u16* base);
void func_080E8A24(UnkStruct_080E8864* p);
u8 func_080E86C8(UnkStruct_080DFB8C* p, s32 x, s32 y);
UnkStruct_080E8E24* func_080E8E74(u8 a);
void func_080EAB20(u8 a, u8 b, u8 c);
void func_080EABB8(u8 a, u16 v);
void func_080EAC60(u8 a, s32 b);

s32 func_080DFEBC(s32 x, s32 y, s32 z);
s32 func_080DFF1C(UnkStruct_080DFF1C* p);
s32 func_080DFF30(UnkStruct_080DFF1C* p);
void func_080DFF4C(UnkStruct_080DFF1C* p);
void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b);
s32 func_080DFF94(s32 x, s32 y, s32 z);
void func_080DFFEC(UnkStruct_080DFF1C* p);
s32 func_080E0010(s32 x);
s32 func_080E0044(s32 y);
void func_080E0078(void);
void func_080E0558(void);
void func_080E062C(void);
void func_080E0298(s32 x, s32 y);
void func_080E02A8(s32 dx, s32 dy);
void func_080E02C0(s32 x, s32 y, s32 z);
u8 func_080E02E0(UnkStruct_080DFF1C* p, s16 a, s16 b);
u8 func_080E0378(void);
s32 func_080E0390(void);
s32 func_080E03C0(s32 a);
void func_080E0418(void);
void func_080E04EC(void);
void func_080E052C(u8 a);
void func_080E05E4(void);
void func_080E0780(void);
void func_080E0820(void);
u8 func_08006314(void);
void func_0801CB0C(void);
void UpdatePlayTime(void);
u8 IsTaskActive(void* t);
void* func_080D3A20(void* pool);
void func_08006184(s32 a, u16 b);
void func_080063A8(void);
void func_080125A4(void);
u16 GetKeysPressed(void);
void func_080DF730(u8 a, u8 b);
void func_080DF814(void);
void func_080DF828(void);
void func_0806180C(u16 a);
u16 GetKeysHeld(void);
void func_080DFA3C(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void func_080104F4(void);
void func_080DEF20(void);
void SetBgMode0(void);
void SetBackdropColor(u16 r, u16 g, u16 b);
void func_0801227C(void);
void func_0801CB00(void);
void SeedRandom(u32 a);
void m4aSongNumStartOrContinue(u16 n);
void func_08006120(s32 a, u16 b);
void func_08006494(u16 a, u16 b);
void SetBlendAlpha(u16 a, u16 b);
u8 func_08006314(void);
void func_0801CB0C(void);
void func_080E0878(void);
void func_080E0900(UnkStruct_080DFB8C* p, s32 a, s32 b);
u8 func_080E0920(UnkStruct_080DFF1C* p, u16 a);
u8 func_080E0938(u8 a);
void func_080E09B4(UnkStruct_080DFB8C* p, u8 n, u8 v);
void func_080E0A38(UnkStruct_080DFB8C* p);
void func_080E0A70(UnkStruct_080DFB8C* p, s32 n);
void func_080E0B98(UnkStruct_080DFB8C* p, s32 n, u8 v);
void func_080E0BF4(s16 x, s16 y, s32 a, s32 b);
u8 func_080E1CE0(s16 x, s16 y, u8 n);
s16 func_080E1194(u8 a, u8 b, s16 c);
void func_080E1C64(s16 x, s16 y, u8 n);
s32 func_080E1CA8(s16 x, s16 y);
u8 func_080E2BA0(u8 a);
s32 func_080E2B08(void);
void func_080E2BF8(u8 a);
void func_080E2C2C(u8 a);
s32 func_080E2E24(s16 a, s16 b, s16 c);
s32 func_080E2E9C(s16 a, s16 b, s16 c);
s32 func_080E2F14(s16 x, s16 y);
s32 func_080E2F48(s16 a, s16 b, s16 c, u8 d);
s32 func_080E2F98(s16 a, s16 b, s16 c, u8 d);
s32 func_080E300C(u8 d, s16 x, s16 y);
void func_080E3060(u8 i, s16 a, s16 b, s16 c);
void func_080E4FF0(void* p, s16 a, s16 b);
void func_080E51C0(void* p, s16 a, s16 b);
UnkStruct_080DFB8C* func_080E548C(s16 a, s16 b);
UnkStruct_02034F20* func_080E54A0(u8 a);
u8* func_080E54B8(u8 a);
void* func_080E5504(void);
void func_080E5510(u8 a);
u16 func_080E5564(void);
UnkStruct_02034F24* func_080E5590(u8 a);
s32 func_080E58F8(s16 a, s16 b);
void func_080E590C(UnkStruct_080E5B90* p);
void func_080E5938(UnkStruct_080E5B90* p);
s32 func_080E5968(UnkStruct_080E5B90* p);
void func_080E5CD4(UnkStruct_080E590C* p);
void func_080E5D6C(UnkStruct_080E590C* p, u8 n, u16 a);
void func_080E5DEC(UnkStruct_080E590C* p);
u8 func_080E5E44(void);
void func_080E5F50(UnkStruct_080E590C* p);
s32 func_080E5FB4(UnkStruct_080E590C* p);
void func_080E6034(UnkStruct_080E590C* p);
void func_080E607C(void);
void func_080E6100(void);
void func_080E6178(void);
void func_080E6264(void);
UnkStruct_080DFB8C* func_080E67D4(s32 x, s32 y);
u8 func_080E68A4(s16 x, s16 y, u8 n);
s32 func_080E68E4(s16 x, s16 y, u8 w, u8 h, u8 n);
s32 func_080E6968(s16 a, s16 b, u8 c);
s32 func_080E6A80(s16 x, s16 y, u16 n);
void func_080E657C(UnkStruct_080E590C* p);
s32 func_080E6804(s16 x, s16 y);
void func_080E6998(s16 x, s16 y, u8 w, u8 h);
s16 func_080E6A14(s16 x, s16 y);
u8 func_080E7D64(UnkStruct_080DFF1C* a, u8 b);
s32 func_080E7D80(void* a);
s32 func_080E7DB8(u8 flag, void* a);
void func_080E7DF8(void);
void func_080E7E3C(void);
void func_080E7FCC(void);
void func_080E8058(void);
void func_080E80E0(void);
void func_080E826C(void);
void func_080E853C(void);
void func_080E8594(void);
void func_080E84DC(UnkStruct_080DFF1C* p);
void func_080E8624(void);
void func_080E891C(UnkStruct_080E8864* p);
u8 func_080E89E4(s16 x, s16 y, const u8* p);
void func_080E8AC8(UnkStruct_080E8864* p);
void func_080E8AE8(void);
s32 func_080E8C38(u8 a, u8 b);
s32 func_080E8C84(u8 a, u8 b);
u8 func_080E8D00(void);
UnkStruct_02034F80* func_080E8D1C(u8 a);
s32 func_080E8E24(UnkStruct_080E8E24* p);
u8 func_080E8F0C(void);
s32 func_080E8F50(UnkStruct_080E8E24* a, u8 b, s32 c, s32 d, s32 e);
u8 func_080E8FB8(u8 a, s32 b, s32 c, s32 d);
void func_080E9338(s32 a);
void func_080E9344(s32 a);
void func_080E9034(u8 a, u8 b, s32 c, s32 d, s32 e);
void func_080E92B8(UnkStruct_080E92B8* p);
void func_080E92F8(UnkStruct_080E92B8* p);
void func_080E935C(void);
void func_080E93FC(void);
void func_080E9508(void);
void func_080E9550(void);
void func_080E95C4(void);
void func_080E95E8(void);
void func_080E963C(void);
void Mode_MapDbg_0(void);
void Mode_MapDbg_1(void);
void Mode_MapDbg_2(void);
void func_080E98B0(void);
void func_080E9A00(void);
void func_080E9A28(void);
void func_080E9AF0(void);
void func_080E9B7C(void);
void func_080E9CBC(void);
void func_080E9D94(void);
void func_080E9E04(void);
void func_080E9E28(void);
void func_080E9E94(void);
void func_080E9F30(void);
void Mode_MapFld_0(void);
void Mode_MapFld_1(void);
void Mode_MapFld_2(void);
UnkStruct_09EF8370* func_080EA20C(void);
void func_080EA2AC(void);
u8 func_080EA400(void);
u8 func_080EA45C(void);
void func_080EA498(void);
void func_080EA5A8(void);
void func_080EA5CC(void);
void func_080EA694(void);
void func_080EA730(void);
void func_080EA78C(void);
void func_080EA7FC(void);
void Mode_MapFix_0(void);
void func_080EA7D8(void);
void Mode_MapFix_1(void);
void Mode_MapFix_2(void);
void func_080E9D94(void);
void func_080E988C(s32 a);
void func_080E9898(s32 a);
void func_080EA1E8(s32 a);
void func_080EA1F4(s32 a);
s32 func_080EAD3C(u8 i);
void func_080EB818(u8 a, u8 b, u8 c);
void func_080ED0B8(FldRes* p, u8 a, u16 v);
void func_080ECA88(UnkStruct_080ECA88* p);
void func_080ECFE8(UnkStruct_080ECFE8* p, u8 a);
void func_080ED06C(UnkStruct_080ED06C* p, u8 a);
void func_080EE50C(UnkStruct_080EE50C* p, u8 a);
void func_080EE580(UnkStruct_080EE580* p, u8 a);
void func_080EE5E0(u8 a);
void func_080EE62C(u16 v);
void func_080EE6AC(u32 t);
s32 func_080EF3A0(UnkStruct_080E590C* p);
void func_080EF404(UnkStruct_080E590C* p, s32 b, s32 c);
void func_080EF478(UnkStruct_080E590C* p, s32 b, s32 c);
s32 func_080EF4BC(UnkStruct_080E590C* p);
void func_080EF84C(UnkStruct_080E590C* p);
s32 func_080F023C(UnkStruct_080F023C* p, s32 lim);
void func_080F0708(UnkStruct_080F023C* p, u8 flag);
void func_080F3D58(UnkStruct_080DFF1C* p);
s32 func_080F7488(UnkStruct_080DFF1C* p, s32 lim);

#endif /* GUARD_MAP_H */
