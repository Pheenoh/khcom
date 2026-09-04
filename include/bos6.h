#ifndef GUARD_BOS6_H
#define GUARD_BOS6_H

#include "types.h"
#include "taskpool.h"
#include "anim.h"

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
    u8 unk_02C[0x08];
    u64 unk_034;
    u8 unk_03C[0x0C];
    u32 unk_048;
    u32 unk_04C;
    void* unk_050;
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
    u32 unk_078;
    u32 unk_07C;
    u8 unk_080[0x20];
    u32 unk_0A0;
    u8 unk_0A4;
    u8 unk_0A5[0x03];
    u32 unk_0A8;
    u32 unk_0AC;
    u16 unk_0B0;
    u8 unk_0B2;
    u8 unk_0B3;
    u8 unk_0B4;
    u8 unk_0B5[0x17];
    s32 unk_0CC;
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
    u8 unk_100[0x30];
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    u8 unk_13C[0x8C];
    s16 unk_1C8;
    u8 unk_1CA;
    u8 unk_1CB[0x05];
} BtlWork;

extern BtlWork* gBtlWork;

void* LoadObjTiles(void* a, s32 b);
void ReleaseObjTiles(void* a);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(void* a);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void func_0800516C(s32 a, void* b, s32 c, s32 d);
void func_08005244(s32 a, u16 b, u16 c);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
u16 func_0801AF1C(s32 a);
void func_0802F1C8(void);
void func_0802F208(void);
s32 func_0802F268(void);
void TaskPoolDraw(TaskPool* a);
void TaskPoolDestroy(TaskPool* a);
void DisableBg(s32 bg);
void func_08012304(void* a);
void func_0801B7D8(void* a);

typedef struct PcPos {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x24];
    u64 unk_34;
    u8 unk_3C[0x4];
    u8 unk_40[0x5C];
    u16 unk_9C;
} PcPos;

typedef struct PcWork {
    s16 unk_000;
    s16 unk_002;
    s16 unk_004;
    s16 unk_006;
    s16 unk_008;
    u16 unk_00A;
    u16 unk_00C;
    u8 unk_00E[0x2];
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019[0x3];
    s32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u16 unk_030;
    u8 unk_032[0x2];
    u16 unk_034;
    u8 unk_036[0xA];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u32 unk_050;
    u32 unk_054;
    u32 unk_058;
    u32 unk_05C;
    u32 unk_060;
    u8 unk_064[0x1C];
    s16 unk_080;
    s16 unk_082;
    u8 unk_084[0x4];
    u64 unk_088;
    u8 unk_090[0x4];
    u32 unk_094;
    u8 unk_098[0xCC];
    u32 unk_164;
    u32 unk_168;
    u32 unk_16C;
    s32 unk_170;
    u8 unk_174[0x24];
    u64 unk_198;
    u8 unk_1A0[0xD4];
    u32 unk_274;
    u8 unk_278[0x58];
    void** unk_2D0;
    void* unk_2D4[4];
    u32 unk_2E4;
    s16 unk_2E8;
    u8 unk_2EA;
    u8 unk_2EB;
    u8 unk_2EC;
    u8 unk_2ED;
    u8 unk_2EE[0x2];
    s32 unk_2F0;
    s32 unk_2F4;
    u8 unk_2F8[0x1C24];
} PcWork;

typedef struct PcAcdWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019[0x3];
    struct PcFltWork* unk_01C;
    AnimState unk_020;
} PcAcdWork;

typedef struct PcFltWork {
    u16 unk_000;
    s16 unk_002;
    u8 unk_004;
    u8 unk_005;
    u8 unk_006;
    u8 unk_007;
    u16 unk_008;
    u8 unk_00A[0x2];
    u32 unk_00C;
    u32 unk_010;
    u16 unk_014;
    u16 unk_016;
    s16 unk_018;
    u8 unk_01A[0x2];
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    s32 unk_028;
    s32 unk_02C;
    s32 unk_030;
    u32 unk_034;
    u32 unk_038;
    PcPos* unk_03C;
    u32 unk_040;
    u8 unk_044[0x58];
    AnimState unk_09C;
} PcFltWork;

typedef struct PcFldWork {
    u32 unk_000;
    u8 unk_004[0x4];
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u8 unk_014[0x58];
} PcFldWork;

typedef struct LstTask {
    void* unk_00;
    void* unk_04;
} LstTask;

typedef struct LstSub {
    u8 unk_000;
    u8 unk_001;
    u8 unk_002;
    u8 unk_003;
    s16 unk_004;
    s16 unk_006;
    s16 unk_008;
    s16 unk_00A;
    s16 unk_00C;
    u8 unk_00E[0x2];
    u32 unk_010;
    u8 unk_014[0x4];
    u8 unk_018[0x4];
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    u8 unk_028[0x24];
    u64 unk_04C;
    u8 unk_054[0xD4];
    AnimState unk_128;
} LstSub;

typedef struct BosLstWork {
    u8 unk_000;
    u8 unk_001;
    u8 unk_002;
    u8 unk_003;
    s16 unk_004;
    s16 unk_006;
    s16 unk_008;
    s16 unk_00A;
    s16 unk_00C;
    s16 unk_00E;
    s16 unk_010;
    s16 unk_012;
    u16 unk_014;
    u16 unk_016;
    s16 unk_018;
    s16 unk_01A;
    u8 unk_01C;
    u8 unk_01D;
    s16 unk_01E;
    u16 unk_020;
    u16 unk_022;
    u16 unk_024;
    s16 unk_026;
    u32 unk_028;
    AnimState unk_02C;
    s32 unk_044;
    s32 unk_048;
    s32 unk_04C;
    s32 unk_050;
    s32 unk_054;
    s32 unk_058;
    s32 unk_05C;
    s32 unk_060;
    s32 unk_064;
    s16 unk_068;
    s16 unk_06A;
    u16 unk_06C;
    s16 unk_06E;
    u16 unk_070;
    s16 unk_072;
    u16 unk_074;
    u16 unk_076;
    u16 unk_078;
    s16 unk_07A;
    s32 unk_07C;
    s16 unk_080;
    s16 unk_082;
    s32 unk_084;
    s32 unk_088;
    s16 unk_08C;
    s16 unk_08E;
    s32 unk_090;
    s32 unk_094;
    s32 unk_098;
    s32 unk_09C;
    s32 unk_0A0;
    s32 unk_0A4;
    s16 unk_0A8;
    s16 unk_0AA;
    s16 unk_0AC;
    u8 unk_0AE[0x2];
    s32 unk_0B0;
    s32 unk_0B4;
    s32 unk_0B8;
    s16 unk_0BC;
    s16 unk_0BE;
    s16 unk_0C0;
    u16 unk_0C2;
    s32 unk_0C4;
    u8 unk_0C8[0xC];
    u8 unk_0D4;
    u8 unk_0D5;
    s16 unk_0D6;
    u8 unk_0D8[0x4];
    s32 unk_0DC;
    u32 unk_0E0;
    u16 unk_0E4;
    u16 unk_0E6;
    u32 unk_0E8;
    u32 unk_0EC;
    u32 unk_0F0;
    u8 unk_0F4[0x1C];
    s16 unk_110;
    s16 unk_112;
    u32 unk_114;
    u64 unk_118;
    u32 unk_120;
    u32 unk_124;
    u8 unk_128[0xCC];
    LstSub unk_1F4[2];
    u8 unk_474[0x5C];
    u32 unk_4D0;
    u8 unk_4D4[0x58];
    u8 unk_52C[8][0x5C];
    void* unk_80C;
    LstTask* unk_810[0x20];
    u32 unk_890;
    u8 unk_894[0x10];
    u8 unk_8A4[0x280];
    u8 unk_B24[0x24];
    u8 unk_B48[0x55C];
} BosLstWork;

void LoadPalette(void* src, void* dst, s32 size);

extern u8 gUnk_09D69374[];
extern u8 gUnk_05000080[];

void func_0810A018(void* a);
void func_0810A498(void* a);
void func_0801BCD4(void* a);


s32 func_0810B49C(void);
void func_0810B4A8(u8* p);
void func_0810B51C(u8* p);
void func_0810BF24(u8** p, u8 v);
void func_0810C2C4(u8** p);
void func_0810C2CC(BosLstWork* work, u16 a, u16 b);
void func_0810C2E0(BosLstWork* work);
void task_bos_pc_2(PcWork* work);
void task_bos_pc_acd_3(PcAcdWork* work);
void task_bos_pc_flt_3(PcFltWork* work);
void task_bos_pc_fld_3(PcFldWork* work);
void func_0810B4F4(u8* p);
s32 func_0810B7D8(s32 x);
s32 func_0810B7E0(s32 x);
s32 func_0810BF14(s32 x);
s32 func_0810BF1C(s32 x);
s32 func_0810C2B4(s32 x);
s32 func_0810C2BC(s32 x);

s32 func_0810B348(s32 x);
s32 func_0810B368(s32 x);
s32 func_0810FE84(s32 x);
s32 func_0810FE8C(s32 x);
void func_0810B370(u8** p, u8 v);

void func_08109EF8(void* work, s32 a);
s32 func_08109F20(void* work);
u8 func_0801BCA8(void* a);
u16 AnimGetGfxIndex(void* a);
s32 func_0810B350(void** p);
u8 func_0810B800(void** p);
u8 func_0810B824(void** p);
void func_0810B7E8(void** p, s32* a, s32* b, s32* c);

void func_0810C2F8(BosLstWork* work);
s16 func_0810C630(BosLstWork* work);
u8 func_0810D364(BosLstWork* work);
void func_0810D3A8(BosLstWork* work);
void func_0810D478(BosLstWork* work);
u8 func_08110918(LstTask* t);
u16 func_0811095C(LstTask* t, s16 a);
void func_08110984(LstTask* t);
void func_081109A8(LstTask* t);
void func_08000DE8(void* pool, LstTask* t);

extern u16 gUnk_09A4CABE[];
extern s16 gUnk_09A4CAC4[];

void func_0810B3E4(void);
void func_0810B40C(s16 a);
void func_0810B434(void);
extern s8* gUnk_09EF9E04[];
void func_0810B4B4(u8* p);

void AnimChange(AnimState* a, u16 animId, u16 flags);
u8 AnimIsFinished(AnimState* a);
void AnimReset(AnimState* a);

void func_0810B930(PcFltWork* work);
void func_0810B9A8(PcFltWork* work);
void func_0810BA14(PcFltWork* work);

void func_08012324(void* a, s32 x, s32 y, s32 z);
void ColliderSetHeight(void* a, u16 b);
void func_08012614(void* a, s32 b);

void func_0810B8F8(PcFltWork* work);
void func_0810B95C(PcFltWork* work);
void func_0810B9DC(PcFltWork* work);
void func_0810BA3C(PcFltWork* work);
void func_0810BA74(PcFltWork* work);
void func_0810BCD4(PcFltWork* work);

typedef struct UnkStruct_09A4CEDC {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
} UnkStruct_09A4CEDC;

extern const UnkStruct_09A4CEDC gUnk_09A4CEDC[];

typedef struct UnkStruct_080038C8 {
    u8* unk_00;
    u8 unk_04[0x02];
    u16 unk_06;
    u16 unk_08;
} UnkStruct_080038C8;

extern u8 gUnk_09CC4E54[];
extern u8 gUnk_09D693D4[];
extern u8 gUnk_09D69434[];
extern u8 gUnk_05000220[];

void func_0801B7D8(void* a);
void func_0810A4C4(PcWork* work);
void func_0801AF08(void* a);
u8 func_081109B8(LstTask* t, u8 a);
void func_0810C494(BosLstWork* work, u16 a, u16 b, u8 c);

void func_0810B378(void** p, u8 a);
u8 func_0810E950(BosLstWork* work);
u8 func_0810E984(BosLstWork* work);
void func_0810D4B0(BosLstWork* work);

s32 abs(s32 x);
s32 func_08003C9C(s32 x);
u8 func_08110938(LstTask* t);
u8 func_0810A424(PcWork* work);

s32 func_0810CC14(s32 a, s32 b, s32 c, s32 d, s32 e);
u8 func_0810AE74(PcWork* work, s32 arg);
u8 func_0810D304(BosLstWork* work, s32 idx);

typedef struct GameState {
    u8 unk_000[0x8];
    u32 flags;
} GameState;

extern GameState gGameState;
extern s32 gUnk_09A4D154[];

u16 GetRandom(void);
void _0801C1F8(s32 a, s32 b, s32 c, s32 d);
void func_0801BCD4(void* a);

u8 func_0810AED4(PcWork* work, s32 arg);
void func_0810C754(BosLstWork* work);
void func_0810C7C4(BosLstWork* work);
void func_0810CC68(BosLstWork* work);

s32 func_0810D70C(BosLstWork* work);

void AnimUpdate(AnimState* a);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void ColliderSetRadius(void* a, u16 b);
void func_08110994(LstTask* t, s16 a);

u8 func_0810D3E0(BosLstWork* work, s32 idx, s16 a);
u8 task_bos_pc_flt_1(PcFltWork* work);
void func_0810BAE4(PcFltWork* work);

extern u8 gUnk_09A4D14C[];
extern u8 gUnk_09C4B012[];
extern u8 gUnk_09EFAD3C[];
extern u8 gUnk_09EFABB0[];
extern u8 gUnk_09C51CBC[];
extern u8 gUnk_09EFADBC[];
extern u8 gUnk_09EFAD74[];

void func_08002A10(u32 a, void* b);
void func_08005974(AnimState* a, u16 b, u16 c, void* d, void* e);

void func_0810CE1C(BosLstWork* work);
void func_0810C57C(BosLstWork* work, s16 a);

extern void* gUnk_09EFBEB8;

u16 func_0801AF1C(s32 a);
void task_bos_pc_fld_2(PcFldWork* work);

typedef struct PcStep {
    u8 unk_00;
    u8 unk_01[0x3];
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u16 unk_0A;
} PcStep;

extern u8 gUnk_09C489E4[];
extern u8 gUnk_09EFABA4[];
extern u8 gUnk_09EFAB68[];

void* AllocObjTiles(s32 a, void* b);
void AnimInit(AnimState* a, void* b, void* c);
void func_080062F4(u16 a, s32 b);
typedef struct PcAnim {
    u8 unk_00[0x4];
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A[0x2];
    u16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x2];
    u16 unk_1C;
    u8 unk_1E[0x6];
} PcAnim;

typedef struct PcShot {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u8 unk_0A[0x2];
    s32 unk_0C;
} PcShot;

extern const PcShot gUnk_09A4C9F8[];

PcAnim* func_08109EB0(PcWork* work);
void func_080147D8(s32 x, s32 y);
void func_080154F4(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s, u16 a, s32 t);
u8 func_0801C1C0(s32 a);
void func_0810A454(PcWork* work);
u8 func_0810A9CC(PcWork* work, s32 arg);
u8 task_bos_pc_1(PcWork* work, s32 arg);
void task_bos_pc_0(PcWork* work, s32 arg);
void func_0810A444(PcWork* work);
void func_0810A4CC(PcWork* work, u16 a, s32 b, s32 c, s32 d, u8 e);
void func_0810A51C(PcWork* work, TaskPool* pool);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void func_0801BDD4(void* a, void* b);
void func_0801BCC0(s32 a, s32 b, s32 c);
void func_0801C298(u8 a, u8 b);
void LoadBgMap(s32 bg, void* src, u16 size);

extern u8 gTaskDescBosPcFld[];
extern u8 gUnk_09A3DF0C[];
extern u8 gUnk_09A3DEFC[];
extern u8 gUnk_09D34A74[];
extern u8 gUnk_09CB84B4[];
extern u8 gUnk_09C448D2[];
extern u8 gUnk_08F69BC4[];
extern u8 gTaskDescBosLstFld[];
extern u8 gUnk_09A4CF6C[];
extern u8 gUnk_09A4CF5C[];
extern u8 gUnk_09C53724[];
extern u8 gUnk_09C58590[];
extern u8 gUnk_09D69594[];
extern u8 gUnk_09D4DA74[];
extern u8 gUnk_09D4B274[];

void task_bos_lst_0(BosLstWork* work, void* pool);
u16 func_08003524(void* a, s32 b);
void func_0801C7FC(void* a, s32 b, s32 c);
void TaskPoolInit(TaskPool* a, s32 count);
void func_0800592C(s32* value, s32 target, u16 steps);
void func_0810FF6C(void* p, s32 a);
void func_0801836C(s32 a, s32 b, s32 c, s32 d, s32 e);
void TaskPoolUpdate(TaskPool* pool);
u8 task_bos_lst_1(BosLstWork* work);

typedef struct LstAnimDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    u8 unk_08[0x4];
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x2];
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u8 unk_1C[0x2];
    s16 unk_1E;
    s16 unk_20;
    s16 unk_22;
    s16 unk_24;
    s16 unk_26;
    s16 unk_28;
    u8 unk_2A[0x2];
} LstAnimDef;

extern void* gUnk_09A4D194[][2];
extern u8 gUnk_09D69454[];

void task_bos_lst_2(BosLstWork* work);
void TaskPoolDraw(TaskPool* a);
u8 func_0801CA00(void* a);
void SetBgScroll(s32 a, u16 b, u16 c);
void DisableBg(s32 bg);
void LoadBgTiles(s32 bg, void* src, u16 size);
void CpuFastSet(void* src, void* dst, s32 ctrl);
u8 func_0810EBA0(BosLstWork* work);
void func_0810FF64(void* p, s32 a);
void func_08014A34(s32 a, s32 b);
void func_08006238(s32 a, s32 b, s32 c);
void func_08006184(s32 a, u16 b);
void func_08006120(s32 a, u16 b);
void func_080063A8(void);

typedef struct UnkStruct_02039DC8 {
    u8 unk_00[0x68];
    s16 unk_68;
    s16 unk_6A;
} UnkStruct_02039DC8;

extern UnkStruct_02039DC8* gUnk_02039DC8;
u16 AnimGetId(AnimState* a);
void task_bos_pc_acd_2(PcAcdWork* work);

extern u16 gUnk_09A4D0EC[];
extern LstAnimDef gUnk_09A4CF8C[];
PcStep* func_08109ECC(PcWork* work);

void func_0810A850(PcWork* work);
void task_bos_pc_acd_0(PcAcdWork* work, void* arg);
u8 task_bos_pc_acd_1(PcAcdWork* work);
void task_bos_lst_3(BosLstWork* work);

typedef struct PcFltInit {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    PcPos* unk_10;
} PcFltInit;

extern u8 gUnk_09CB8F54[];
extern u8 gUnk_09EFBBEC[];
extern u8 gUnk_09EFBBBC[];

void* AnimGetGfx(AnimState* a);
void func_080122AC(void* a, s32 b, s32 c, s32 d);

void task_bos_pc_flt_0(PcFltWork* work, PcFltInit* arg);
void task_bos_pc_flt_2(PcFltWork* work);

typedef struct FldInit {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    u8 unk_10[0x4];
} FldInit;

void task_bos_pc_fld_0(PcFldWork* work, FldInit* arg);

u8 task_bos_pc_fld_1(PcFldWork* work);

u8 func_0810C65C(BosLstWork* work, u16 a);
u8 func_0810DB40(BosLstWork* work);
void func_0810FF50(void* p, s32 a, s16 b);
void func_0810CD00(BosLstWork* work);
void func_0810CEC8(BosLstWork* work);
void func_0810D4F8(BosLstWork* work);
void func_0810D77C(BosLstWork* work);

u8 func_0810EF94(BosLstWork* work);
u8 func_0810E844(BosLstWork* work);
u8 func_0810DC28(BosLstWork* work);
u8 func_0810DE04(BosLstWork* work);
u8 func_0810E210(BosLstWork* work);
u8 func_0810E32C(BosLstWork* work);
u8 func_0810E524(BosLstWork* work);
u8 func_0810E73C(BosLstWork* work);

extern const s16 gSineTable[];

u8 func_0810A914(PcWork* work, s32 arg);
void func_0810B844(PcFltWork* work);

void m4aSongNumStart(u16 id);
u8 func_080128EC(void);
void func_08018184(s32 a, s32 b, s32 c, s32 d);

s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
u8 func_0810C32C(BosLstWork* work, s32 a);

void func_0801AF4C(void* a);
void func_0801C2DC(void* a, s32 b);
void func_0801B918(void* a);
void func_0801B008(void);
void func_08096DC4(void* a, void* b);
u8 func_0810AF44(PcWork* work, s32 arg);

typedef struct LstSpawn {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10;
    u8 unk_11;
    s16 unk_12;
    void* unk_14;
} LstSpawn;

extern u8 gTaskDescBosLstFal[];
void* TaskCreate(void* pool, void* desc, void* arg);
void func_08017F70(s32 a, s32 b, s32 c, s32 d);

u8 func_0810ACB8(PcWork* work, s32 arg);

extern const s16 gUnk_09A4CCDC[];
extern const s16 gUnk_09A4CADC[];

typedef struct LstSpawn2 {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} LstSpawn2;

extern u8 gTaskDescBosLstCtr[];

void func_08018A70(s32 a, s32 b, s32 c, s32 d);
void func_080189DC(s32 a, s32 b, s32 c, s32 d);
u8 func_08111F4C(LstTask* t);

typedef struct LstSpawn3 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x6];
    s16 unk_12;
    u8 unk_14[0xC];
} LstSpawn3;

typedef struct LstSpawn4 {
    s32 unk_00;
    s32 unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} LstSpawn4;

extern u8 gTaskDescBosLstBit[];

typedef struct LstSpawn5 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    u8 unk_0E[0x2];
} LstSpawn5;

extern u8 gUnk_09EFAE1C[];
extern u8 gUnk_09EFADC4[];
extern u8 gUnk_09EFAEAC[];
extern u8 gUnk_09EFAE54[];
extern u8 gTaskDescBosLstSnp[];

s32 func_0801ADAC(void* a);
void func_0810F064(BosLstWork* work, LstSub* p);

extern u8 gTaskDescBtlPop[];
u8 func_0810E99C(BosLstWork* work);

#endif /* GUARD_BOS6_H */
