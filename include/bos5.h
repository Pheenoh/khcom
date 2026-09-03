#ifndef GUARD_BOS5_H
#define GUARD_BOS5_H

#include "types.h"
#include "taskpool.h"
#include "anim.h"

typedef struct MdB84 {
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
    s32* unk_07C;
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
    u8 unk_0EC[0x02];
    u8 unk_0EE;
    u8 unk_0EF;
    u32 unk_0F0;
    u32 unk_0F4;
    u16 unk_0F8;
    u8 unk_0FA;
    u8 unk_0FB;
    u32 unk_0FC;
    u8 unk_100[0xC8];
    s16 unk_1C8;
    u8 unk_1CA[0x06];
} MdB84;

extern MdB84* gUnk_02039B84;

void* LoadObjTiles(void* a, s32 b);
void ReleaseObjTiles(void* a);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(void* a);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
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
void TaskPoolDestroy(void* a);
void DisableBg(s32 bg);
void func_08012304(void* a);
void func_0801B7D8(void* a);


typedef struct GaEntryDesc {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u8 unk_0C[0x4];
    void* unk_10;
} GaEntryDesc;

typedef struct GaEntryPos {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
} GaEntryPos;

typedef struct GaEntry {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x12];
    GaEntryDesc unk_1C[2];
    GaEntryPos unk_44[1];
} GaEntry;

typedef struct MdAnimFrame {
    u16 unk_00;
    u16 unk_02;
} MdAnimFrame;

typedef struct MdAnimDef {
    MdAnimFrame* unk_00;
    u16 unk_04;
    u16 unk_06;
} MdAnimDef;

extern MdAnimDef gUnk_09992E24[];

typedef struct MdAnim {
    u16 unk_00;
    u16 unk_02;
    MdAnimFrame* unk_04;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    u16 unk_0E;
} MdAnim;

typedef struct MdSub {
    u32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x1C];
    s16 unk_02C;
    s16 unk_02E;
    u8 unk_030[0x4];
    u64 unk_034;
    u8 unk_03C[0x4];
    u8 unk_040[0xD0];
} MdSub;

typedef struct MdHahenWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u32 unk_020;
    u16 unk_024;
    u8 unk_026[0x2];
} MdHahenWork;

typedef struct MdDaiTarget {
    u16 unk_00;
} MdDaiTarget;

typedef struct MdDaiWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s16 unk_010;
    u8 unk_012[0x2];
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u8 unk_020[0x58];
    MdDaiTarget* unk_078;
    s16 unk_07C;
    u16 unk_07E;
    void* unk_080;
} MdDaiWork;

typedef struct MdFireTarget {
    u16 unk_00;
} MdFireTarget;

typedef struct MdFireWork {
    u32 unk_000;
    s16 unk_004;
    s16 unk_006;
    s16 unk_008;
    u8 unk_00A[0x2];
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    AnimState unk_018;
    u32 unk_030;
    s16 unk_034;
    u8 unk_036[0x2];
    MdSub unk_038;
    s32 unk_148;
    s32 unk_14C;
    s32 unk_150;
    s32 unk_154;
    s32 unk_158;
    s16 unk_15C;
    s16 unk_15E;
    s16 unk_160;
    u8 unk_162;
    u8 unk_163;
    u32 unk_164;
    u32 unk_168;
    MdFireTarget* unk_16C;
} MdFireWork;

typedef struct MdFireArg {
    void* unk_00;
    s16 unk_04;
    u16 unk_06;
    s32 unk_08;
} MdFireArg;

typedef struct MdFirePoint {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
} MdFirePoint;

typedef struct MdFireDef {
    MdFirePoint* unk_00;
    s16 unk_04;
    u16 unk_06;
} MdFireDef;

typedef struct GaEntryWork {
    u8 unk_000[0x180];
    AnimState unk_180;
    u8 unk_198[0x10];
} GaEntryWork;

typedef struct GaWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u8 unk_00C[0x2];
    u16 unk_00E;
    u16 unk_010;
    u16 unk_012;
    u16 unk_014;
    u8 unk_016[0x2];
    u32 unk_018;
    u8 unk_01C;
    u8 unk_01D[0x3];
    GaEntryWork entries[6];
    u8 unk_A10[0x18];
    u32 unk_A28;
    u8 unk_A2C[0x4];
    u8* unk_A30;
    u8* unk_A34;
    u8 unk_A38[0x14];
    u32 unk_A4C;
    s16 unk_A50;
    u8 unk_A52;
    u8 unk_A53;
} GaWork;

typedef struct MdModel {
    u16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
} MdModel;

typedef struct MdSlot {
    s16 unk_00;
    u8 unk_02[0x6];
    u8 unk_08;
    u8 unk_09[0x3];
    void* unk_0C;
    void* unk_10;
    void* unk_14;
} MdSlot;

extern MdModel gUnk_09992F70[];
extern MdSlot gUnk_02034FF8[];
extern u8 gUnk_09A3CDDC[];
extern u8 gUnk_099EDE7C[];
extern u8 gUnk_099A8914[];

u8 func_080D2DD8(void);

typedef struct MdGfx {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u16 unk_12;
} MdGfx;

typedef struct MdWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u16 unk_00C;
    u16 unk_00E;
    u32 unk_010[1];
    u16 unk_014;
    s16 unk_016;
    u16 unk_018;
    s16 unk_01A;
    u8 unk_01C;
    u8 unk_01D[0x3];
    u8* unk_020;
    u8* unk_024;
    void* unk_028;
    TaskPool unk_02C;
    TaskPool unk_040;
    TaskPool unk_054;
    MdSub sub[1];
    u16 unk_178;
    u16 unk_17A;
    MdGfx unk_17C[2];
    MdAnim unk_1A4;
    u16 unk_1B4;
    u8 unk_1B6[0x2];
} MdWork;


u16 GetRandom(void);
void ApproachValue(void* a, s32 b, u16 c);
void* AnimUpdate(void* a);

extern s16 gSineTable[];
extern u8 gUnk_09A3C9BC[];
extern u8 gUnk_09999ED0[];
extern u32 gUnk_09EF9740[];

void func_080FCC14(MdFireWork* work);
u8 func_080FCCB4(MdFireWork* work);
void func_08012324();
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_08012614(void* a, s32 b);
void func_080F83E0(void* a, void* b);
void func_080F8374(void* a);

extern u8 gUnk_09992114[];
extern GaEntry gUnk_09992108[];

s32 task_bos_md_hahen_1(MdHahenWork* work);
void task_bos_md_hahen_2(MdHahenWork* work);
void task_bos_md_dai_0(MdDaiWork* work, s32* src);
void task_bos_md_hahen_0(MdHahenWork* work, s32* src);
u8 task_bos_md_fire_1(MdFireWork* work);
void task_bos_md_fire_2(MdFireWork* work);
void task_bos_md_3(MdWork* work);
void func_080FD9B8(s16 model, s16 slot);
void func_080FDA28(s16 model, s16 slot);
s16 func_080FDA98(s16 model, s16 slot);
extern u32 gFrameCounter;

void task_bos_ga_2(GaWork* work);
void task_bos_ga_3(GaWork* work);
void task_bos_md_hahen_3(MdHahenWork* work);
void task_bos_md_fire_3(MdFireWork* work);
void task_bos_md_dai_3(MdDaiWork* work);
void func_080FB8E8(MdWork* work, u16 index);
void func_080FB908(MdWork* work, u16 index);

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x8];
    u32 unk_008;
    u8 unk_00C[0x16E];
    u16 unk_17A;
    u8 unk_17C[0x4];
    u16 unk_180;
} UnkStruct_02039BB0;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern u8 gUnk_09A02EFC[];
extern u8 gUnk_09A020FC[];
extern s16 gUnk_020350FA;

u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
void* GetBgCharBase(s32 bg);
u8 RequestDma3Copy(void* src, void* dst, u16 size);

typedef struct MdMapData {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    u32 unk_10;
} MdMapData;

typedef struct MdMapWork {
    u32 unk_00;
} MdMapWork;

void func_0801AF08(void* a);
s32 func_0801ADAC(MdSub* e);
void _0801C1F8(s32 a, s32 b, s32 c, s32 d);
void func_0801C2DC(void* a, s32 b);
void func_0801C298(u8 a, u8 b);
void func_08083900(u8 a);
void func_0801BCC0(s32 a, s32 b, s32 c);
void func_080F80FC(GaWork* work, u32 i, s32 c);
void* TaskCreate(void* pool, void* desc, void* arg);
void task_bos_ga_0(GaWork* work, s32 arg);
s32 task_bos_md_dai_1(MdDaiWork* work);
void task_bos_md_fire_0(MdFireWork* work, MdFireArg* arg);
void func_080FCF78(MdFireWork* work);
u8 func_080F7E0C(s32 a, s32 b, s32 c, s32 d);
u8 func_08012660(void* a, s32 b);
extern s16 gSineTable[];
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void AnimInit(AnimState* a, void* b, void* c);
extern MdFireDef gUnk_09992EF8[];
extern u8 gUnk_09992F28[];
extern u8 gUnk_09A3C99C[];
extern u8 gUnk_099E367C[];
extern u8 gUnk_09EF9BC0[];
extern u8 gUnk_09EF9BB0[];
extern u8 gUnk_09EF8EDC[];
void task_bos_md_dai_2(MdDaiWork* work);
extern u8 gUnk_09999E0C[];
extern u8 gUnk_09999E1C[];
void func_08012658(void* a, u16 b);
void m4aSongNumStart(u16 n);
extern u8 gUnk_09EF8F0C[];
u8 task_bos_ga_1(GaWork* work);
void func_080FB000(GaWork* work, GaEntryWork* p);
void func_080F7F54(GaWork* work, s32 b);
u8 func_0801C1C0(s32 a);
u8 AnimIsFinished(AnimState* a);
void AnimStart(AnimState* a, s32 b, s32 c);
u8 func_080F854C(GaWork* work);
u8 func_080F8958(GaWork* work);
u8 func_080F8AC8(GaWork* work);
u8 func_080F8F9C(GaWork* work);
u8 func_080F9744(GaWork* work);
u8 func_080F99C0(GaWork* work);
u8 func_080F9C2C(GaWork* work);
u8 func_080F9EDC(GaWork* work);
u8 func_080FA2B4(GaWork* work);
u8 func_080FA644(GaWork* work);
u8 func_080FAA18(GaWork* work);
u8 func_080FABE4(GaWork* work);
extern GaWork* gUnk_02034FE8;
extern u8 gUnk_09EDB338[];
extern u8 gUnk_0999202C[];
extern u8 gUnk_09A3C89C[];
void func_080FB930(MdWork* work, u16 id);
void func_080038E4(void* a, void* b);
void func_080FB8DC(MdWork* work, s32 state);
void func_080FBA14(MdWork* work, s16 id);
u8 func_080FBA9C(MdWork* work);
u8 func_080FBAB8(MdWork* work);
u8 func_080FBC4C(MdWork* work);
u8 func_080FBDD4(MdWork* work);
u8 func_080FBFA8(MdWork* work);
s32 task_bos_md_1(MdWork* work);
void task_bos_md_0(MdWork* work, void* arg);
void func_080FE854(void);
void func_080FF794(void);
void func_080FF330(void);
void func_080066F4(s16 x, s16 y);
void func_08006954(void);
extern u8 gUnk_0999CB90[];
extern u8 gUnk_0999C394[];
extern u8 gUnk_0999C3C8[];
extern void* gUnk_09EF9770[];
void mode_worldselect_1(void);
void UpdatePlayTime(void);
u8 func_080A411C(TaskPool* a, s32 b, u16 c);
u8 func_080A42C8(void);
u8 func_08006B74(void);
void func_080063A8(void);
void func_080E04EC(void);
void func_080DFA18(u8 a);
void func_0806180C(u16 a);
void func_080938F8(u16 a);
void func_080DFA3C(void);
void func_080FDC04(void);
void func_080FE47C(void);
extern s16 gUnk_020350EC;
extern u8 gUnk_09A315DC[];
extern u8 gUnk_09A31FDC[];
void mode_worldselect_0(void);
void func_08001F98(void);
void func_08006120(s32 a, u16 b);
void* EwramAlloc(s32 size);
void func_080065FC(s32 a, s32 b, s32 c);
void func_08006778(void* a, s32 x, s32 y);
void func_08006B34(u16 a);
extern s16 gUnk_02034FF0;
extern s32 gUnk_0203508C;
extern s16 gUnk_02035090;
extern s16 gUnk_02035092;
extern u16 gUnk_02039D30;
extern s16 gUnk_02035070[];
extern u8 gUnk_020350B4;
extern s16 gUnk_020350B6;
extern s16 gUnk_020350B8;
extern s16 gUnk_020350BA;
extern s16 gUnk_020350C0;
extern s16 gUnk_020350C2;
extern s32 gUnk_020350C8[];
extern s32 gUnk_020350D0;
extern u8 gUnk_020350EE;
extern u8 gUnk_020350EF;
extern u8 gUnk_020350F0;
extern TaskPool gUnk_020350D8;
extern u8 gUnk_09A3C9DC[];
extern u8 gUnk_099F1E7C[];
extern u8 gUnk_09A310DC[];
extern u8 gUnk_09A31ADC[];
extern u8 gUnk_09EDABA0[];
extern u8 gUnk_09A3CC5C[];
extern u8 gUnk_0999B052[];
extern u8 gUnk_09A3CC7C[];
extern u8 gUnk_0999CBB6[];
extern u8 gUnk_0999C410[];
void func_080FF8CC(void);
void func_0805F1C0(s32* p, s32 v);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
extern s32 gUnk_020354D0;
extern s32 gUnk_020354C8[];
extern s32 gUnk_020354D8;
extern s32 gUnk_020354DC;
extern void* gUnk_02035120;
extern void* gUnk_02035124;
extern void* gUnk_02035128;
extern void* gUnk_02035148;
extern void* gUnk_0203514C;
extern void* gUnk_020351C8[];
extern void* gUnk_02035198[];
extern AnimState gUnk_02035130;
extern AnimState gUnk_02035150;
extern u8 gUnk_020351F8[];
extern u8 gUnk_020352C0[];
extern u8 gUnk_0203511A;
extern u8 gUnk_0999CF38[];
extern u8 gUnk_0999CF54[];
extern u8 gUnk_0999CF88[];
void EnableBg(s32 a);
extern void* gUnk_020354B8[];
extern u8 gUnk_020354A0;
extern u16 gUnk_020354C2;
extern u8 gUnk_020352B8;
extern u8 gUnk_09A3CC3C[];
extern u8 gUnk_0999A394[];
extern u8 gUnk_0999A350[];

typedef struct MdWorldNav {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    u8 unk_0C[0x8];
} MdWorldNav;

extern MdWorldNav gUnk_09EF8FAC[];
void LoadBgMap(s32 bg, void* src, u16 size);
void func_08006184(s32 a, u16 b);
extern void* gUnk_020354A8[];
extern void* gUnk_020354B0[];
extern s16 gUnk_020350F8;
extern s16 gUnk_02035100[];
extern void* gUnk_02035168[];
extern u8 gUnk_020354E0;
extern s16 gUnk_02035118;
extern u8 gUnk_09A324DC[];
extern u8 gUnk_09A3D07C[];
extern void* gUnk_0203511C;
extern s16 gUnk_020354C0;
void func_080FDB1C(s16 model, s16 n);
void mode_worldselect_2(void);
void EwramFree(void* p);
extern void* gUnk_020350BC;
extern s16 gUnk_02035090;
extern void* gUnk_020350A0[];
extern void* gUnk_02035098[];
extern void* gUnk_020350AC;
extern void* gUnk_020350A8;
extern void* gUnk_020350B0;
extern TaskPool gUnk_020350D8;
void func_080FE89C(void);
void func_08004E64(void);
extern u16 gBldCnt;
extern u16 gBldAlpha;
void func_080FE900(void);
void func_08004DB0(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
extern s16 gUnk_020350F2;
extern u16 gUnk_020350F4;
extern void* gUnk_09EF8F24[];
void* func_080038C8(u16 a);
void TaskPoolInit(void* pool, s32 count);
extern u8 gUnk_09EF8EC4[];
extern u8 gUnk_099920E8[];
extern u8 gUnk_099D42FC[];
extern u8 gUnk_099920D8[];
void TaskPoolUpdate(void* a);
extern u8 gUnk_09EF8EF4[];
void func_0801853C(s32 a, s32 b, s32 c, s32 d);
void func_0802F1E8(void);
void func_08019A30(void);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0801BCD4(MdSub* e);
void func_080FBA4C(MdWork* work);
u8 func_0801CA00(void* a);
void LoadPalette(void* src, void* dst, s32 size);
void TaskPoolDraw(void* a);
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_09A3C97C[];
void task_bos_md_2(MdWork* work);
typedef struct MdMsg {
    u32 unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x0E];
    void* unk_18;
    u16 unk_1C;
    u16 unk_1E;
    void* unk_20;
    u16 unk_24;
    u16 unk_26;
    void* unk_28;
    void* unk_2C;
    u16 unk_30;
    u16 unk_32;
} MdMsg;

extern MdMsg gUnk_09EF909C[];
extern void* gUnk_09EE9138[];
extern u8 gUnk_020351F8[];
extern u8 gUnk_020352C0[];
u8 func_08065B6C(void* a, void* b);
u8 func_080FF228(s16 id);
u8 func_080FF25C(s16 id);
void func_080FC3FC(MdWork* work);
void func_080FC360(MdWork* work);
typedef struct PrizeCardArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x14];
} PrizeCardArg;

u8 func_080FC17C(MdWork* work);
void func_0801AF4C(MdSub* e);
u8 func_08006314(void);
void func_08014AAC(s32 a, s32 b);
void func_08006238(s32 a, u8 b, s32 c);
void func_0801536C(void);
u16 func_08006390(void);
u8 func_080128EC(void);
void func_08096DC4(void* a, void* b);
void func_0801B918(MdSub* e);
void func_0801B008(void);
void func_080FC29C(MdWork* work);
void task_bos_md_map_0(MdMapWork* work, MdMapData* p);
s32 task_bos_md_map_1(MdMapWork* work);
s32 func_080FF310(void);
void func_080FF2B8(s16 index);

#endif /* GUARD_BOS5_H */
