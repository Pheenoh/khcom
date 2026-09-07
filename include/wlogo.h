#ifndef GUARD_WLOGO_H
#define GUARD_WLOGO_H

#include "types.h"
#include "taskpool.h"
#include "intr.h"
#include "main.h"
#include "anim.h"

#define REG_VCOUNT (*(vu16*)0x04000006)
#define REG_BGHOFS(n) (*(vu16*)(0x04000010 + (n) * 4))
typedef struct WlogoPal {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} WlogoPal;

typedef struct WlogoTtEffStep {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04;
    u8 unk_05[0x3];
    s16 unk_08;
    s16 unk_0A;
    u8 unk_0C;
    u8 unk_0D[0x3];
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x2];
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    u8 unk_1C[0x2];
    s16 unk_1E;
} WlogoTtEffStep;

typedef struct BosTmWork {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x02];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u8 unk_2A[0x02];
    s32 unk_2C;
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
    u8 unk_3A;
    u8 unk_3B;
    s32 unk_3C;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u8 unk_46[0x02];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    struct BosTmWork* unk_60;
} BosTmWork;

typedef BosTmWork WlogoTtEffSrc;

typedef struct WlogoTtEffTop {
    WlogoTtEffSrc* unk_000;
    u8 unk_004[0x10];
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    u8 unk_020[0x108];
    u8 unk_128;
    u8 unk_129[0x7];
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    u8 unk_13C[0x108];
    u8 unk_244;
    u8 unk_245[0x7];
    s32 unk_24C;
    s32 unk_250;
    s32 unk_254;
    u8 unk_258[0x104];
    s32 unk_35C;
    u8 unk_360[0x8];
    s32 unk_368;
    s32 unk_36C;
    s32 unk_370;
    u8 unk_374[0x104];
    s32 unk_478;
    u8 unk_47C[0x0E];
    s16 unk_48A;
    s16 unk_48C;
} WlogoTtEffTop;

typedef struct WlogoTtEff {
    u8 unk_000[0x4];
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x24];
    u64 unk_034;
    u8 unk_03C[0x60];
    u16 unk_09C;
    u16 unk_09E;
    u16 unk_0A0;
    u8 unk_0A2[0x86];
    u8 unk_128;
    u8 unk_129[0x359];
    s16 unk_482;
    s16 unk_484;
} WlogoTtEff;

typedef struct WlogoTtWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u16 unk_004;
    u8 unk_006;
    u8 unk_007;
    void* unk_008;
    void* unk_00C;
    void* unk_010;
    void* unk_014;
    void* unk_018;
    WlogoPal* palette;
    void* unk_020;
    void* unk_024;
    void* unk_028;
    void* unk_02C;
    void* unk_030;
    void* unk_034;
    void* unk_038;
    u8 unk_03C[0x4];
    AnimState anim[6];
    u8 unk_0D0[0x1C];
    u16 unk_0EC;
    u8 unk_0EE[0x12];
    s8 unk_100[0x8];
    s32 unk_108;
    s32 unk_10C;
    s32 unk_110;
    TaskPool unk_114;
} WlogoTtWork;

typedef struct WlogoBksObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_00C[0x18];
    s16 unk_024;
    s16 unk_026;
    s8 unk_028;
    s8 unk_029;
    u8 unk_02A[0x2];
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    s32 unk_03C;
    s32 unk_040;
    u8 unk_044;
    u8 unk_045;
    s16 unk_046;
    u16 unk_048;
    u8 unk_04A[0x2];
} WlogoBksObjWork;

typedef struct WlogoBksWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u16 unk_004;
    u8 unk_006;
    u8 unk_007;
    u16 unk_008;
    u8 unk_00A;
    u8 unk_00B;
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s8 unk_030;
    u8 unk_031;
    u16 unk_032;
    u16 unk_034;
    u8 unk_036;
    u8 unk_037;
    u16 unk_038;
    u8 unk_03A[0x2];
    TaskPool unk_03C;
} WlogoBksWork;

typedef struct WlogoTtObjArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} WlogoTtObjArg;

typedef struct WlogoTtObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    u16 unk_02C;
    u16 unk_02E;
} WlogoTtObjWork;

typedef struct WlogoTtLineWork {
    s16 unk_000;
    s16 unk_002;
    s8 unk_004;
    u8 unk_005[0x3];
    TaskPool unk_008;
} WlogoTtLineWork;

typedef struct WlogoPooWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u8 unk_004;
    u8 unk_005;
    u16 unk_006;
    u8 unk_008;
    u8 unk_009[0x3];
} WlogoPooWork;

typedef struct WlogoPooObjStep {
    s16 unk_00;
    u8 unk_02[0x2];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} WlogoPooObjStep;

typedef struct WlogoPooObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    s32 unk_038;
    u16 unk_03C;
    u16 unk_03E;
    u8 unk_040;
    u8 unk_041;
    u8 unk_042;
    u8 unk_043;
} WlogoPooObjWork;

typedef struct WlogoTvtWork {
    void* tiles;
    void* palette;
    s16 x;
    s16 y;
    void* gfx;
    AnimState anim;
    u8 unk_028;
    u8 unk_029;
    u16 unk_02A;
    u8 unk_02C;
    u8 unk_02D;
    u16 unk_02E;
    u8 unk_030;
    u8 unk_031[0x3];
} WlogoTvtWork;

typedef struct WlogoAgrEntry {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06;
    u8 unk_07;
    u16 unk_08;
    u16 unk_0A;
    u8 unk_0C;
    u8 unk_0D[0x3];
} WlogoAgrEntry;

typedef struct WlogoAgrSmokeWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 unk_02C;
    u8 unk_030;
    u8 unk_031;
    u16 unk_032;
    u16 unk_034;
    u8 unk_036[0x2];
} WlogoAgrSmokeWork;

typedef struct WlogoAgrFlashWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s16 x;
    s16 y;
    u8 unk_028;
    u8 unk_029[0x3];
} WlogoAgrFlashWork;

typedef struct WlogoAgrWork {
    void* tiles;
    void* palette;
    void* gfx;
    s16 x;
    s16 y;
    u8 unk_010;
    u8 unk_011;
    s16 unk_012;
    s16 unk_014;
    u8 unk_016;
    u8 unk_017;
} WlogoAgrWork;

typedef struct WlogoDilWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_00C;
    u8 unk_00D;
    u16 unk_00E;
    u8 unk_010;
    u8 unk_011;
    s16 x;
    s16 y;
    u8 unk_016;
    u8 unk_017;
} WlogoDilWork;

typedef struct WlogoColWork {
    void* tiles;
    void* palette;
    s16 x;
    s16 y;
    void* gfx;
    AnimState anim;
    u8 unk_028;
    u8 unk_029;
    u16 unk_02A;
    u8 unk_02C;
    u8 unk_02D;
    u16 unk_02E;
    u8 unk_030;
    u8 unk_031;
    u8 unk_032[0x2];
} WlogoColWork;

typedef struct WlogoHlwWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u8 unk_004;
    u8 unk_005[0x3];
} WlogoHlwWork;

typedef struct WlogoNvlObjArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} WlogoNvlObjArg;

typedef struct WlogoNvlMovWork {
    s32 x;
    s32 y;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019;
    u16 unk_01A;
    u16 unk_01C;
    u16 unk_01E;
    u8 unk_020;
    u8 unk_021[0x3];
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    u8 unk_048;
    u8 unk_049;
    u8 unk_04A[0x2];
} WlogoNvlMovWork;

typedef struct WlogoNvlObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    u8 unk_02C;
    u8 unk_02D[0x3];
} WlogoNvlObjWork;

typedef struct WlogoNvlWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    s8 unk_004;
    u8 unk_005;
    u16 unk_006;
    u16 unk_008;
    u8 unk_00A;
    u8 unk_00B;
} WlogoNvlWork;

typedef struct WlogoAtlWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u8 unk_004;
    u8 unk_005;
    u16 unk_006;
    u8 unk_008;
    u8 unk_009;
    u16 unk_00A;
} WlogoAtlWork;

typedef struct WlogoWonEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
} WlogoWonEntry;

typedef struct WlogoWonWork {
    void* tiles;
    void* palette;
    u16 unk_008;
    u8 unk_00A;
    u8 unk_00B;
    s32 x[10];
    s32 y[10];
    s32 unk_05C[10];
    void* unk_084[10];
    u16 unk_0AC[10];
    u8 unk_0C0[10];
    u16 unk_0CA[10];
    u16 unk_0DE[10];
    u8 unk_0F2;
    u8 unk_0F3;
    u8 unk_0F4[0x14];
} WlogoWonWork;

typedef struct WlogoHwtObjA {
    s32 x;
    s32 y;
    s32 unk_08;
    u8 unk_0C;
    u8 unk_0D[0x3];
} WlogoHwtObjA;

typedef struct WlogoHwtObjB {
    s16 unk_00;
    u8 unk_02[0x2];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x3];
} WlogoHwtObjB;

typedef struct WlogoHwtObjWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    s32 unk_038;
    u16 unk_03C;
    u16 unk_03E;
    u8 unk_040;
    u8 unk_041[0x3];
    s32 unk_044;
    u8 unk_048[0x2];
    u8 unk_04A;
    u8 unk_04B;
} WlogoHwtObjWork;

typedef struct WlogoHwtWork {
    u16 unk_000;
    u16 unk_002;
    u8 unk_004;
    u8 unk_005;
    u8 unk_006[0x2];
} WlogoHwtWork;

typedef struct WlogoMonsWork {
    void* tiles;
    WlogoPal* palette;
    s16 x;
    s16 y;
    void* gfx;
    AnimState anim;
    u16 unk_028;
    u16 unk_02A;
    u8 unk_02C;
    u8 unk_02D;
    u8 unk_02E;
    u8 unk_02F;
} WlogoMonsWork;
typedef struct WlogoCollider {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x0C];
    s32 unk_1C;
} WlogoCollider;

typedef struct WlogoBtlWork {
    u8 unk_000[0x40];
    TaskPool unk_040;
    u8 unk_054[0x14];
    u64 unk_068;
    u8 unk_070[0x0C];
    WlogoCollider* unk_07C;
    u8 unk_080[0x4C];
    s32 unk_0CC;
    s32 unk_0D0;
    s32 unk_0D4;
    s16 unk_0D8;
} WlogoBtlWork;

typedef struct WlogoObjParam {
    u32 tiles;
    u16 unk_04;
    u8 unk_06[0x02];
    u32 palette;
    u16 unk_0C;
    u8 unk_0E[0x02];
    s32 x;
    s32 y;
    s32 z;
    void (*unk_1C)(void);
    void* unk_20;
} WlogoObjParam;

typedef struct WlogoBtlObj {
    u8 unk_000[0x2C];
    s16 unk_02C;
    u8 unk_02E[0x06];
    u64 unk_034;
} WlogoBtlObj;

typedef struct BosTmShared {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
} BosTmShared;


extern s32 gUnk_0203AB38;
extern WlogoBtlWork* gBtlWork;
extern s16 gUnk_0203AB3C;
extern s16 gUnk_0203AB40;
extern s16 gUnk_0203AB44;
extern s16 gUnk_0203AB48;
extern BosTmShared gUnk_0203AB50;
extern TaskDesc gTaskDescBosTmBody;
extern TaskDesc gTaskDescBosTmFoot;
extern TaskDesc gTaskDescBosTmArm;
extern TaskDesc gTaskDescBosTmTbl;
extern TaskDesc gTaskDescBosMap;
extern u8 gUnk_09619C68[];
extern vu16 gIntrCheck;
extern WlogoHwtObjA gUnk_096194D0[];
extern WlogoHwtObjB gUnk_09619530[][6];
extern WlogoHwtObjB gUnk_096198D4[];
extern WlogoPooObjStep gUnk_09619A04[][5];
extern u8 gUnk_09619C94[];
extern u8 gUnk_0961AA92[];
extern u8 gUnk_0961B072[];
extern u8 gUnk_0961C062[];
extern u16 gUnk_0961C792[];
extern u8 gUnk_0961C7F4[];
extern u8 gUnk_0961DC0E[];
extern u8 gUnk_0961FA28[];
extern u8 gUnk_09620B0E[];
extern u8 gUnk_096249F4[];
extern u8 gUnk_09624F72[];
extern u8 gUnk_0962848A[];
extern u8 gUnk_09628DC0[];
extern u8 gUnk_096300C4[];
extern u8 gUnk_09630CC4[];
extern u8 gUnk_096324C4[];
extern u8 gUnk_09633144[];
extern u8 gUnk_09633D64[];
extern u8 gUnk_09634664[];
extern u8 gUnk_09638664[];
extern u8 gUnk_09638C84[];
extern u8 gUnk_0963CC84[];
extern u8 gUnk_0963DCE4[];
extern u8 gUnk_096424E4[];
extern u8 gUnk_09642CE4[];
extern u8 gUnk_096438E4[];
extern u8 gUnk_096444E4[];
extern u8 gUnk_09645C84[];
extern u8 gUnk_09646884[];
extern u8 gUnk_096474A4[];
extern u8 gUnk_09648484[];
extern u8 gUnk_09648EA4[];
extern u8 gUnk_0964A104[];
extern u8 gUnk_096B6464[];
extern u8 gUnk_096B6C64[];
extern u8 gUnk_096B7464[];
extern u8 gUnk_096B7C64[];
extern u8 gUnk_096B8464[];
extern u8 gUnk_096B8C64[];
extern u8 gUnk_096B9464[];
extern u8 gUnk_096B9C64[];
extern u8 gUnk_096BA464[];
extern u8 gUnk_096BAC64[];
extern u8 gUnk_096BB464[];
extern u8 gUnk_096BBC64[];
extern u8 gUnk_096BC464[];
extern u8 gUnk_096BCC64[];
extern u8 gUnk_096BD464[];
extern u8 gUnk_096BDC64[];
extern u8 gUnk_096BE464[];
extern u8 gUnk_096BEC64[];
extern u8 gUnk_096BF464[];
extern u8 gUnk_096FAC84[];
extern u8 gUnk_096FACA4[];
extern u8 gUnk_096FACC4[];
extern u8 gUnk_096FAD64[];
extern u8 gUnk_096FAD84[];
extern u8 gUnk_096FADA4[];
extern u8 gUnk_096FADC4[];
extern u8 gUnk_096FADE4[];
extern u8 gUnk_096FAE04[];
extern u8 gUnk_096FAE24[];
extern u8 gUnk_096FAE44[];
extern u8 gUnk_096FAE64[];
extern u8 gUnk_096FAE84[];
extern u8 gUnk_096FAEA4[];
extern u8 gUnk_096FAFA4[];
extern u8 gUnk_096FB084[];
extern u8 gUnk_096FB0A4[];
extern u8 gUnk_096FB0C4[];
extern TaskDesc gTaskDescWlogoHwtObj;
extern WlogoWonEntry gUnk_09EF167C[];
extern WlogoWonEntry gUnk_09EF1744[];
extern s32 gUnk_09EF180C[];
extern TaskDesc gTaskDescWlogoNvlMov;
extern TaskDesc gTaskDescWlogoNvlObj;
extern WlogoAgrEntry gUnk_09EF191C[];
extern TaskDesc gTaskDescWlogoAgrSmoke;
extern TaskDesc gTaskDescWlogoAgrFlash0;
extern TaskDesc gTaskDescWlogoAgrFlash1;
extern u8 gUnk_09EF1AEC[];
extern TaskDesc gTaskDescWlogoPooObj;
extern s32 gUnk_09EF1B08[];
extern TaskDesc gTaskDescWlogoTtObj;
extern s16 gUnk_09EF1B68[][3];
extern TaskDesc gTaskDescWlogoTtLine;
extern s8 gUnk_09EF1C48[];
extern s8 gUnk_09EF1C50[];
extern u8 gUnk_09EF1C70[];
extern s16 gUnk_09EF1C7E[][2];
extern s16 gUnk_09EF1CB6[][2];
extern s16 gUnk_09EF1CEE[];
extern u16 gUnk_09EF1D0A[];
extern TaskDesc gTaskDescWlogoBksObj;
extern u8 gUnk_09EF1D58[];
extern WlogoTtEffStep gUnk_09EF1E14[];
extern u8 gUnk_09EF351C[];
extern u8 gUnk_09EF3544[];
extern u8 gUnk_09EF3548[];
extern u8 gUnk_09EF356C[];
extern u8 gUnk_09EF3574[];
extern u8 gUnk_09EF35A4[];
extern u8 gUnk_09EF35B8[];
extern u8 gUnk_09EF3610[];
extern void* gUnk_09EF3614[];
extern u8 gUnk_09EF36AC[];
extern void* gUnk_09EF36D0[];
extern u8 gUnk_09EF36D8[];
extern u8 gUnk_09EF3730[];
extern u8 gUnk_09EF3734[];
extern u8 gUnk_09EF376C[];
extern u8 gUnk_09EF377C[];
extern u8 gUnk_09EF37DC[];
extern void* gUnk_09EF37F4[];
extern u8 gUnk_09EF3804[];
extern void* gUnk_09EF380C[];
extern u8 gUnk_09EF3850[];
extern void* gUnk_09EF3924[];
extern s32 gUnk_09EF3960[];
extern s32 gUnk_09EF397C[];

void* AllocObjTiles(s32 size, void* src);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(u8* p);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void LoadObjPaletteBank(u16 bank, void* src);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void StartBgWave(void (*a)(void));
void SetBgWaveParams(s32 a, u8 b, u8 c);
void EnableBgWave(s32 a);
void HBlankIntrBgWave1(s32 a);
void StopBgWave(s32 a);
void func_0801B7D8(void* a);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void EnableBg(s32 bg);
void DisableBg(s32 bg);
void SetBgBlend(s32 a, u16 b, u16 c);
void LoadPalette(void* src, void* dst, s32 size);
void* LoadPaletteWithEffect(void* src, void* dst, u16 size);
void AnimInit(AnimState* a, s32 b, s32 c);
void ApproachValue(s32* value, s32 target, u16 steps);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void func_08005974(AnimState* a, u16 b, u16 c, void* d, void* e);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
u8 AnimIsFinished(AnimState* a);

void task_wlogo_hwt_0(WlogoHwtWork* work);
u8 task_wlogo_hwt_1(WlogoHwtWork* work);
void task_wlogo_hwt_2(WlogoHwtWork* work);
void task_wlogo_hwt_3(WlogoHwtWork* work);
void task_wlogo_hwt_obj_0(WlogoHwtObjWork* work, s32 arg);
u8 task_wlogo_hwt_obj_1(WlogoHwtObjWork* work);
void task_wlogo_hwt_obj_2(WlogoHwtObjWork* work);
void task_wlogo_hwt_obj_3(WlogoHwtObjWork* work);
void task_wlogo_tt_0(WlogoTtWork* work);
u8 task_wlogo_tt_1(WlogoTtWork* work);
void task_wlogo_tt_2(WlogoTtWork* work);
void task_wlogo_tt_3(WlogoTtWork* work);
void task_wlogo_bks_obj_0(WlogoBksObjWork* work, s32 arg);
u8 task_wlogo_bks_obj_1(WlogoBksObjWork* work);
void task_wlogo_bks_obj_2(WlogoBksObjWork* work);
void task_wlogo_bks_obj_3(WlogoBksObjWork* work);
void task_wlogo_bks_0(WlogoBksWork* work);
u8 task_wlogo_bks_1(WlogoBksWork* work);
void task_wlogo_bks_2(WlogoBksWork* work);
void task_wlogo_bks_3(WlogoBksWork* work);
void func_080B7C7C(void);
void task_wlogo_tt_obj_0(WlogoTtObjWork* work, WlogoTtObjArg* arg);
u8 task_wlogo_tt_obj_1(WlogoTtObjWork* work);
void task_wlogo_tt_obj_2(WlogoTtObjWork* work);
void task_wlogo_tt_obj_3(WlogoTtObjWork* work);
void task_wlogo_tt_line_0(WlogoTtLineWork* work);
u8 task_wlogo_tt_line_1(WlogoTtLineWork* work);
void task_wlogo_tt_line_2(WlogoTtLineWork* work);
void task_wlogo_tt_line_3(WlogoTtLineWork* work);
void task_wlogo_poo_0(WlogoPooWork* work);
u8 task_wlogo_poo_1(WlogoPooWork* work);
void task_wlogo_poo_2(WlogoPooWork* work);
void task_wlogo_poo_3(WlogoPooWork* work);
void task_wlogo_poo_obj_0(WlogoPooObjWork* work, s32 arg);
u8 task_wlogo_poo_obj_1(WlogoPooObjWork* work);
void task_wlogo_poo_obj_2(WlogoPooObjWork* work);
void task_wlogo_poo_obj_3(WlogoPooObjWork* work);
void task_wlogo_tvt_0(WlogoTvtWork* work);
u8 task_wlogo_tvt_1(WlogoTvtWork* work);
void task_wlogo_tvt_2(WlogoTvtWork* work);
void task_wlogo_tvt_3(WlogoTvtWork* work);
void task_wlogo_agr_smoke_0(WlogoAgrSmokeWork* work, WlogoAgrEntry* arg);
u8 task_wlogo_agr_smoke_1(WlogoAgrSmokeWork* work);
void task_wlogo_agr_smoke_2(WlogoAgrSmokeWork* work);
void task_wlogo_agr_smoke_3(WlogoAgrSmokeWork* work);
void task_wlogo_agr_flash0_0(WlogoAgrFlashWork* work);
u8 task_wlogo_agr_flash0_1(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash0_2(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash0_3(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash1_0(WlogoAgrFlashWork* work, WlogoAgrEntry* arg);
u8 task_wlogo_agr_flash1_1(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash1_2(WlogoAgrFlashWork* work);
void task_wlogo_agr_flash1_3(WlogoAgrFlashWork* work);
void task_wlogo_agr_0(WlogoAgrWork* work, s32 arg);
u8 task_wlogo_agr_1(WlogoAgrWork* work);
void task_wlogo_agr_2(WlogoAgrWork* work);
void task_wlogo_agr_3(WlogoAgrWork* work);
void task_wlogo_dil_0(WlogoDilWork* work);
u8 task_wlogo_dil_1(WlogoDilWork* work);
void task_wlogo_dil_2(WlogoDilWork* work);
void task_wlogo_dil_3(WlogoDilWork* work);
void task_wlogo_col_0(WlogoColWork* work);
u8 task_wlogo_col_1(WlogoColWork* work);
void task_wlogo_col_2(WlogoColWork* work);
void task_wlogo_col_3(WlogoColWork* work);
void task_wlogo_hlw_0(WlogoHlwWork* work);
u8 task_wlogo_hlw_1(WlogoHlwWork* work);
void task_wlogo_hlw_2(WlogoHlwWork* work);
void task_wlogo_hlw_3(WlogoHlwWork* work);
void task_wlogo_nvl_mov_0(WlogoNvlMovWork* work);
u8 task_wlogo_nvl_mov_1(WlogoNvlMovWork* work);
void task_wlogo_nvl_mov_2(WlogoNvlMovWork* work);
void task_wlogo_nvl_mov_3(WlogoNvlMovWork* work);
void task_wlogo_nvl_obj_0(WlogoNvlObjWork* work, WlogoNvlObjArg* arg);
u8 task_wlogo_nvl_obj_1(WlogoNvlObjWork* work);
void task_wlogo_nvl_obj_2(WlogoNvlObjWork* work);
void task_wlogo_nvl_obj_3(WlogoNvlObjWork* work);
void task_wlogo_nvl_0(WlogoNvlWork* work);
u8 task_wlogo_nvl_1(WlogoNvlWork* work);
void task_wlogo_nvl_2(WlogoNvlWork* work);
void task_wlogo_nvl_3(WlogoNvlWork* work);
void task_wlogo_atl_0(WlogoAtlWork* work);
u8 task_wlogo_atl_1(WlogoAtlWork* work);
void task_wlogo_atl_2(WlogoAtlWork* work);
void task_wlogo_atl_3(WlogoAtlWork* work);
void func_080B5444(void);
void WlogoEnableHBlank(void);
void WlogoHBlankIntr(void);
void WlogoDisableHBlank(void);
void func_080B8334(WlogoTtEff* p, s16 a, s16 b, s16 c);
void func_080B83A4(WlogoTtEff* p, s16 a, s16 b, s16 c);
void func_080B83C4(WlogoTtEff* p);
void func_080B8418(WlogoTtEffTop* p);
void func_080B895C(WlogoTtEffTop* p);
void func_080B8508(WlogoTtEffTop* p);
void func_080B8554(WlogoTtEffTop* p);
void func_080B8688(WlogoTtEffTop* p);
void func_080B87C0(WlogoTtEffTop* p, s16 a);
void func_080B83B8(void* a);
void task_wlogo_won_0(WlogoWonWork* work);
u8 task_wlogo_won_1(WlogoWonWork* work);
void task_wlogo_won_2(WlogoWonWork* work);
void task_wlogo_won_3(WlogoWonWork* work);
void task_wlogo_mons_0(WlogoMonsWork* work);
u8 task_wlogo_mons_1(WlogoMonsWork* work);
void task_wlogo_mons_2(WlogoMonsWork* work);
void task_wlogo_mons_3(WlogoMonsWork* work);

void func_08000DE8(TaskPool* a, Task* t);
void func_080C640C(WlogoObjParam* param);
u8 func_080C64A4(void);
void func_0801B008(void);
void func_080B7E68(BosTmWork* w);
void task_bos_tm_0(BosTmWork* w, BosTmShared* arg);
u8 task_bos_tm_1(BosTmWork* w);
void task_bos_tm_2(BosTmWork* w);
void task_bos_tm_3(BosTmWork* w);
void func_080B82D4(void);
void func_080B8324(WlogoTtEffTop* p);
void func_080B91A4(WlogoTtEffTop* p);
void func_080B9FC4(WlogoTtEffTop* p);
s32 func_0801ADAC(WlogoBtlObj* p);
void func_0801AF08(WlogoBtlObj* p);
void func_0801AF4C(WlogoBtlObj* p);
void _080B949C(WlogoBtlObj* a, WlogoTtEffTop* b);

#endif /* GUARD_WLOGO_H */
