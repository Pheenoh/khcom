#ifndef GUARD_BOS7_H
#define GUARD_BOS7_H

#include "types.h"
#include "key.h"
#include "taskpool.h"
#include "anim.h"

typedef struct LstAnimSet {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} LstAnimSet;

typedef struct LstObj {
    u8 unk_00[0x4];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x1C];
    s16 unk_2C;
    u8 unk_2E[0xE2];
} LstObj;

typedef struct LstState {
    s16 unk_000;
    s16 unk_002;
    u16 unk_004;
    s16 unk_006;
    s16 unk_008;
    s16 unk_00A;
    s16 unk_00C;
    s16 unk_00E;
    s16 unk_010;
    s16 unk_012;
    s16 unk_014;
    u16 unk_016;
    u16 unk_018;
    u8 unk_01A;
    u8 unk_01B;
    u16* unk_01C;
    u16* unk_020;
    s32 unk_024;
    s32 unk_028;
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    s32 unk_038;
    s32 unk_03C;
    s32 unk_040;
    s32 unk_044;
    s32 unk_048;
    s32 unk_04C;
    s32 unk_050;
    s32 unk_054;
    s32 unk_058;
    s32 unk_05C;
    s32 unk_060;
    s32 unk_064;
    u32 unk_068;
    u32 unk_06C;
    u32 unk_070;
    u32 unk_074;
    u32 unk_078;
    u32 anim;
    u8 unk_080[0x14];
    u32 unk_094;
    u32 unk_098;
    u32 unk_09C;
    LstObj unk_0A0;
    u32 unk_1B0;
    u8 unk_1B4[0x10];
    void* unk_1C4;
    void* unk_1C8;
    void* unk_1CC;
} LstState;

typedef struct LstWork {
    void* unk_00;
    LstState* unk_04;
} LstWork;

typedef struct LstLsrTask {
    void* unk_00;
    struct LstLsrWork* unk_04;
} LstLsrTask;

typedef struct LstEdgWork {
    s16 unk_000;
    s16 unk_002;
    s16 unk_004;
    s16 unk_006;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    u32 anim;
    u8 unk_030[0x14];
    u32 tiles;
    u32 palette;
} LstEdgWork;

typedef struct LstCtrWork {
    s32 unk_000;
    s16 unk_004;
    s16 unk_006;
    s16 unk_008;
    s16 unk_00A;
    s16 unk_00C;
    s16 unk_00E;
    u8 unk_010;
    u8 unk_011;
    s16 unk_012;
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    s32 unk_038;
    s32 unk_03C;
    s32 unk_040;
    u32 anim;
    u8 unk_048[0x14];
    u32 tiles;
    u32 palette;
    u8 unk_064[0x124];
} LstCtrWork;

typedef struct LstFldWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    u16 unk_020;
    u16 unk_022;
    u16 unk_024[0x50];
    u16 unk_0C4[0x340];
    u16 unk_744[0x4A0];
    u16 unk_1084[2][160];
} LstFldWork;

typedef LstState LstBitWork;

typedef struct LstLsrWork {
    s16 unk_000;
    u8 unk_002;
    u8 unk_003;
    s32 unk_004;
    u16* unk_008;
    u16* unk_00C;
    s16 unk_010;
    s16 unk_012;
    s16 unk_014;
    u8 unk_016[0x0E];
    s32 unk_024;
    s32 unk_028;
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    s32 unk_038;
    u32 tiles;
    u32 palette;
    u32 anim;
    u8 unk_048[0x14];
} LstLsrWork;

typedef struct LstPtlWork {
    s16 unk_000;
    s16 unk_002;
    s16 unk_004;
    s16 unk_006;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u32 anim;
    u8 unk_01C[0x14];
    u32 tiles;
    u32 palette;
} LstPtlWork;

typedef struct LstFalWork {
    s32 unk_000;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_010;
    s32 unk_014;
    s32 unk_018;
    u16* unk_01C;
    u32 tiles;
    u32 palette;
    u32 anim;
    u8 unk_02C[0x14];
} LstFalWork;

typedef struct LstSnpWork {
    u8 unk_000;
    u8 unk_001[0x3];
    s32 x;
    s32 y;
    s32 z;
    s32 unk_010;
    s32 unk_014;
    u32 tiles;
    u32 palette;
    u32 anim;
    u8 unk_024[0x14];
} LstSnpWork;

typedef struct LstFldArg {
    void* unk_00;
    u16 unk_04;
    void* unk_08;
    u16 unk_0C;
} LstFldArg;

typedef struct LstBitArg {
    s32 unk_00;
    s32 unk_04;
    u16* unk_08;
    u16* unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} LstBitArg;

typedef struct LstBitSubArg {
    s32 unk_00;
    u16* unk_04;
    u16* unk_08;
} LstBitSubArg;

typedef struct LstCtrArg {
    s32 unk_00;
    u16 unk_04;
    u16 unk_06;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} LstCtrArg;

typedef struct LstEdgArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} LstEdgArg;

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct GameState {
    u8 unk_000[0x8];
    u32 flags;
} GameState;

typedef struct LstPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} LstPos;

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
    u8 unk_02C[0x14];
    u8 unk_040[0x28];
    u64 unk_068;
    u8 unk_070[0xC];
    LstPos* unk_07C;
    u8 unk_080[0x4C];
    s32 unk_0CC;
    s32 unk_0D0;
    s32 unk_0D4;
    u8 unk_0D8[0x2];
    s16 unk_0DA;
    s16 unk_0DC;
    u8 unk_0DE[0x2];
    s16 unk_0E0;
} BtlWork;

typedef struct LstLsrArg {
    s32 unk_00;
    u16* unk_04;
    u16* unk_08;
} LstLsrArg;

typedef struct LstFalArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10;
    u8 unk_11;
    s16 unk_12;
    u16* unk_14;
} LstFalArg;

typedef struct LstPtlArg {
    u16 unk_00;
    s32 unk_04;
    s32 unk_08;
} LstPtlArg;

typedef struct LstSnpArg {
    s32 x;
    s32 y;
    s32 z;
    s16 unk_0C;
} LstSnpArg;

typedef struct EvtObj {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    u16 flags;
    u16 unk_16;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
} EvtObj;

typedef struct StaffRollLabelArg {
    u16 unk_00;
    u16 unk_02;
    s32 unk_04;
    s32 unk_08;
} StaffRollLabelArg;

typedef struct StaffRollScene {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
    u16 unk_14;
    u16 unk_16;
    void* unk_18;
    u16 unk_1C;
    u16 unk_1E;
    void* unk_20;
    u16 unk_24;
    u16 unk_26;
    s32 unk_28;
    s32 unk_2C;
    u16 unk_30;
    u16 unk_32;
} StaffRollScene;

typedef struct StaffRollTaskArg {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} StaffRollTaskArg;

typedef struct StaffRollLogoArg {
    s32 unk_00;
    s32 unk_04;
    s32* unk_08;
    s32* unk_0C;
    u16 unk_10;
} StaffRollLogoArg;

typedef struct StaffRollSecnArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32* unk_0C;
    s32* unk_10;
} StaffRollSecnArg;

typedef struct StaffRollWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u16 unk_004;
    u16 unk_006;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018[0x60];
    s32 unk_078;
    s32 unk_07C;
    s32 unk_080;
    s32 unk_084;
    s32 unk_088;
    s32 unk_08C;
    s32 unk_090;
    s32 unk_094;
    s32 unk_098;
    StaffRollScene* unk_09C;
    u8 unk_0A0;
    u8 unk_0A1[0x3];
    s32 unk_0A4;
    s32 unk_0A8;
    s32 unk_0AC;
    s32 unk_0B0;
    s32 unk_0B4;
    s32 unk_0B8;
    s32 unk_0BC;
    s32 unk_0C0;
    s32 unk_0C4;
    s32 unk_0C8;
    s32* unk_0CC;
    s32 unk_0D0;
    s32 unk_0D4;
    s32 unk_0D8;
    s32 unk_0DC;
    s32 unk_0E0;
    s32 unk_0E4;
    s32 unk_0E8;
    s32 unk_0EC;
    s32 unk_0F0;
    s32 unk_0F4;
    u32 palette;
    u8 unk_0FC[0x14];
    u8 unk_110[0x14];
    s32 unk_124[6];
    u8 unk_13C[0x84];
    u8 unk_1C0[0x258];
} StaffRollWork;

extern s16 gSineTable[];
extern u16 gUnk_09A4FE64[][2];
extern StaffRollScene gUnk_09A538D8[];
extern StaffRollScene gUnk_09A53D50[];
extern u8 gUnk_09A4D234[];
extern s32 gUnk_09A4FC20[];
extern u8 gUnk_09A4F2B4[];
extern s32 gUnk_09A4FDDC[];
extern s32 gUnk_09A4FDE8[];
extern u8 gUnk_09A4FD4C[];
extern s32 gUnk_09A4FD5C[];
extern u32 gUnk_09A4FEA8[][5];
extern u8 gUnk_09CD1074[];
extern u8 gUnk_09CD0C34[];
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_09C5C4E2[];
extern u8 gUnk_09C5C704[];
extern u8 gUnk_09CD0334[];
extern u8 gUnk_09CD0E34[];
extern u8 gUnk_097CF758[];
extern u8 gUnk_0983FB98[];
extern u8 gUnk_0984A618[];
extern u8 gUnk_09D09674[];
extern u8 gUnk_09D4B274[];
extern u8 gUnk_09D4BA74[];
extern u8 gUnk_09D4C274[];
extern u8 gUnk_09D4CA74[];
extern u8 gUnk_09D4D274[];
extern u8 gUnk_09D10874[];
extern u8 gUnk_09D15C34[];
extern u8 gUnk_09D1AFF4[];
extern u8 gUnk_09D203B4[];
extern u8 gUnk_09D25774[];
extern u8 gUnk_09D2B334[];
extern u8 gUnk_09D65274[];
extern u8 gUnk_09D66274[];
extern u8 gUnk_09D66A74[];
extern u8 gUnk_09D67274[];
extern u8 gUnk_09D67A74[];
extern u8 gUnk_09D68274[];
extern u8 gUnk_09D68A74[];
extern u8 gUnk_09D694F4[];
extern u8 gUnk_09D69594[];
extern u8 gUnk_09D6BF74[];
extern u8 gUnk_09D6C174[];
extern u8 gUnk_09D6C374[];
extern u8 gUnk_09D6C574[];
extern u8 gUnk_09D6C774[];
extern u8 gUnk_09D6C974[];
extern u8 gUnk_09D6CB74[];
extern LstAnimSet gUnk_09EF9EA4[];
extern u8 gTaskDescBosLstLsr[];
extern u8 gTaskDescBosLstFal[];
extern u8 gTaskDescSrollAName[];
extern u8 gTaskDescSrollBChar[];
extern u8 gTaskDescSrollBCrtn[];
extern u8 gTaskDescSrollCChar[];
extern u8 gUnk_09EFAEF8[];
extern u8 gUnk_09EFAF24[];
extern u8 gUnk_09EFAF50[];
extern u8 gUnk_09EFAF1C[];
extern void* gUnk_09EFBEC4[];
extern u8 gUnk_09EFBF18[];
extern u8 gUnk_09EFBF40[];
extern u8 gUnk_09EFBF64[];
extern u8 gUnk_09EFBFC4[];
extern u8 gUnk_09EFBF54[];
extern u8 gUnk_09EFBF5C[];
extern u8 gUnk_09EFBF60[];

extern BtlWork* gBtlWork;

extern GameState gGameState;
extern u8 gUnk_09D6BE74[];

extern u16 gBldCnt;
extern u16 gBldAlpha;
extern u16 gBldY;
extern u8* gUnk_09EF9F54[];
extern u8* gUnk_09EFA9C0;
extern u8* gUnk_09EFA9BC;
extern s32* gUnk_09EFA934[];
extern s32* gUnk_09EFA978[];
extern u8 gUnk_09A541C8[];
extern u8 gUnk_09D6BE14[];
extern u8 gTaskDescSrollBLogo[];
extern u8 gTaskDescSrollBSecn[];
extern vu16 gDispCnt;
extern u16 gWin0H;
extern u16 gWin0V;
extern u16 gWinIn;
extern u16 gWinOut;

void AnimStart(void* a, s32 b, s32 c);
void* LoadObjTiles(void* a, s32 b);
void ReleaseObjTiles(void* a);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(u8* p);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
u16 func_0801AF1C(s32 a);
void TaskPoolDraw(TaskPool* a);
void TaskPoolDestroy(TaskPool* a);
void func_0801B7D8(void* a);
void func_0801C2DC(void* a, s32 b);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void TaskPoolInit(TaskPool* a, s32 count);
void* EwramAlloc(s32 size);
void EwramFree(void* p);
void SetBackdropColor(s32 a, s32 b, s32 c);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_08006120(s32 a, s32 b);
void func_08006184(s32 a, s32 b);
void EnableBg(s32 bg);
void DisableBg(s32 bg);
void SetBgScroll(s32 bg, s32 x, s32 y);
void SetBgColorMode(s32 bg, s32 mode);
void SetBgAffine(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_08116F08(void);
void SetBgMode0(void);
void SetBgMode1(void);
void func_08000DE8(void* pool, void* task);
void func_0801CD74(EvtObj* obj, s32 anim);
void EvtObjSetPos(EvtObj* obj, s32 a, s32 b, s32 c);
void func_0801CE00(EvtObj* obj, u16 a);
s32 func_0801CE04(void* pool, void* desc, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);
void func_081149B0(void* w, s32 v);
void func_08116E98(void);
void func_08116ECC(void);
void TaskPoolUpdate(TaskPool* pool);
void SoftReset(s32 flags);
u8 func_08112C38(StaffRollWork* w);
u8 func_08113180(StaffRollWork* w);
void SetupBg(s32 bg, s32 a, s32 b, s32 c);
void SetBgPriority(s32 bg, s32 prio);
void SetBgSize(s32 bg, s32 size);
u8 func_08006314(void);
void SpriteReset(void);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void func_0802F1C8(void);
void func_0802F208(void);
void func_0810FEDC(void);
void func_08116E8C(void);
void func_08116E60(void* p);
void func_08116E80(void);
void func_08116E00(s32 a, void* b, s32 c);
void LoadPalette(void* src, s32 dst, s32 size);
void func_0810FE94(void);
s32 func_0801ADAC(void* a);
void func_0801AF08(void* a);
void* AnimUpdate(void* a);
void AnimChange(void* a, u16 animId, u16 flags);
void* TaskCreate(void* pool, void* desc, void* arg);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
s32 abs(s32 x);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void* AllocObjTiles(s32 a, void* b);
void func_0800592C(s32* value, s32 target, u16 steps);
void AnimReset(void* a);
void* AnimGetGfx(void* a);
u16 AnimGetId(void* a);
u8 AnimIsFinished(void* a);
void AnimInit(void* a, void* b, void* c);
u16 GetRandom(void);
void m4aSongNumStart(u16 id);
s32 AllocObjAffineAngle(s32 a, s32 b);

void func_08116CEC(void);

void task_bos_lst_fld_0(LstFldWork* work, LstFldArg* arg);
u8 task_bos_lst_fld_1(LstFldWork* work);
void task_bos_lst_fld_3(LstFldWork* work);
void task_bos_lst_bit_3(LstBitWork* work);
void task_bos_lst_lsr_0(LstLsrWork* work, LstLsrArg* arg);
u8 task_bos_lst_lsr_1(LstLsrWork* work);
void task_bos_lst_lsr_2(LstLsrWork* work);
u8 func_08111678(LstLsrWork* work);
void task_bos_lst_lsr_3(LstLsrWork* work);
void task_bos_lst_ptl_0(LstPtlWork* work, LstPtlArg* arg);
u8 task_bos_lst_ptl_1(LstPtlWork* work);
void task_bos_lst_ptl_2(LstPtlWork* work);
void task_bos_lst_ptl_3(LstPtlWork* work);
void task_bos_lst_fal_0(LstFalWork* work, LstFalArg* arg);
u8 task_bos_lst_fal_1(LstFalWork* work);
void task_bos_lst_fal_2(LstFalWork* work);
void task_bos_lst_fal_3(LstFalWork* work);
void task_bos_lst_snp_0(LstSnpWork* work, LstSnpArg* arg);
u8 task_bos_lst_snp_1(LstSnpWork* work);
void task_bos_lst_snp_2(LstSnpWork* work);
void task_bos_lst_snp_3(LstSnpWork* work);
void func_08112600(StaffRollWork* w);
void task_bos_lst_fld_2(void);
void task_bos_lst_edg_0(LstEdgWork* work, LstEdgArg* arg);
u8 task_bos_lst_edg_1(LstEdgWork* work);
void task_bos_lst_edg_2(LstEdgWork* work);
void task_bos_lst_edg_3(LstEdgWork* work);
void task_bos_lst_ctr_0(LstCtrWork* work, LstCtrArg* arg);
u8 task_bos_lst_ctr_1(LstCtrWork* work);
void task_bos_lst_ctr_2(LstCtrWork* work);
void task_bos_lst_ctr_3(LstCtrWork* work);
s32 func_0811089C(s32 x);
s32 func_081108A4(s32 x);
s32 func_08112410(s32 x);
s32 func_08112418(s32 x);
s32 func_08110658(s32 x);
s32 func_08110660(s32 x);
s32 func_0811156C(s32 x);
s32 func_08111574(s32 x);
s32 func_081119F8(s32 x);
s32 func_08111A00(s32 x);
s32 func_08111BF4(s32 x);
s32 func_08111BFC(s32 x);
s32 func_08111F3C(s32 x);
s32 func_08111F44(s32 x);
s32 func_081125B4(s32 x);
s32 func_08114748(s32 x);
s32 func_08114750(s32 x);
u8 func_08110668(LstWork* work);
u8 func_08111A08(LstWork* work);
u8 func_08111F4C(LstWork* work);
u8 func_081115B4(LstWork* work);
s32 func_0811157C(s32 n);
s32 func_08111F60(s32 n);
u8* func_08112748(StaffRollWork* w);
u8 func_0811394C(StaffRollWork* w);
u8 func_08113A94(StaffRollWork* w);
u8 func_08113BB4(StaffRollWork* w);
u8 func_08113DB8(StaffRollWork* w);
u8 func_08113E94(StaffRollWork* w);
u8 func_08114048(StaffRollWork* w);
u8 func_0811411C(StaffRollWork* w);
u8 func_081141F8(StaffRollWork* w);
void mode_StaffRoll_0(void);
void func_08112768(StaffRollWork* w);
void mode_StaffRoll_1(void);
void mode_StaffRoll_2(void);
void func_081125BC(StaffRollWork* w);
u8 func_081125D8(StaffRollWork* w);
u8 func_08112C24(StaffRollWork* w);
void func_081126A8(StaffRollWork* w, u16 flags, s32 dur);
void func_081126D0(StaffRollWork* w, u16 flags, s32 dur);
void func_081126F8(StaffRollWork* w, u16 flags, s32 dur);
void func_08112720(StaffRollWork* w, u16 flags, s32 dur);
u8 func_08110938(LstWork* work);
u8 func_08110918(LstWork* work);
void func_08110984(LstWork* work);
void func_08110994(LstWork* work, u16 a);
void func_081109A8(LstWork* work);
u8 func_081108AC(LstState* work, s32 kind);
s16 func_0811095C(LstWork* work, u16 a);
u8 func_081109B8(LstWork* work, u8 a);
s32 func_08110A38(s32 a, s32 b);
s32 func_08110A98(s32 x0, s32 y0, s32 x1, s32 y1);
s32 func_08110B10(u8 a, u8 b);
void func_08110058(u16* dst, u16* src, s32 count, s32 level);
void task_bos_lst_bit_0(LstState* work, LstBitArg* arg);
u8 task_bos_lst_bit_1(LstState* work);
void task_bos_lst_bit_2(LstState* work);
void func_08110C9C(LstState* work);
void func_081115CC(LstWork* work, Vec3* a, Vec3* b, s32 c, u16 d);
void func_08111660(LstLsrTask* t);
void func_080062F4(u16 a, s32 b);
void func_0811614C(void* sw, void* init);
void func_081166F8(void* sw, s32 a, s32 b, s32 c, s32 d, s32 e);
void func_08116268(void* sw, u16 a, u16 b, u16 c, u16 d);
void func_08116BEC(void* sw, u16 x, u16 y, u8* s, u8 flush);
s32 func_08115FBC(void* sw, u8* s);
void func_081160EC(void* sw, u32 mode);

#endif /* GUARD_BOS7_H */
