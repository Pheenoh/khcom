#ifndef GUARD_BTL_H
#define GUARD_BTL_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "fld_types.h"
struct BtlWork;

typedef struct UnkStruct_0801AF08 {
    u32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x1C];
    u16 unk_2C;
    u16 unk_2E;
    u8 unk_30[0x4];
    u64 unk_34;
    u8 unk_3C[0x4];
    u32 unk_40;
    u8 unk_44[0x28];
    u16 unk_6C;
    u16 unk_6E;
    u16 unk_70;
    u16 unk_72;
    u8 unk_74[0x34];
    s32 unk_A8;
    s32 unk_AC;
    u8 unk_B0;
    u8 unk_B1[0x33];
    struct BtlWork* unk_E4;
} UnkStruct_0801AF08;
typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019;
    s16 unk_01A;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    s16 unk_02C;
    s16 unk_02E;
    u32 unk_030;
    u64 unk_034;
    u8 unk_03C[0x2C];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    u16 unk_072;
    u16 unk_074;
    u16 unk_076;
    struct BtlWork* unk_078;
    struct BtlWork* unk_07C;
    ListNode unk_080;
    ListNode unk_090;
    u16 unk_0A0;
    s16 unk_0A2;
    s16 unk_0A4;
    u16 unk_0A6;
    struct BtlWork* unk_0A8;
    void* unk_0AC;
    u8 unk_0B0[0x03];
    u8 unk_0B3;
    u8 unk_0B4;
    u8 unk_0B5[0x03];
    u32 unk_0B8;
    u8 unk_0BC[0x14];
    s32 unk_0D0;
    u8 unk_0D4[0x04];
    s16 unk_0D8;
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2;
    u8 unk_0E3;
    u16 unk_0E4;
    u8 unk_0E6[0x02];
    s32 unk_0E8;
    u8 unk_0EC[0x02];
    u8 unk_0EE;
    u8 unk_0EF;
    u8 unk_0F0[0x4];
    s32 unk_0F4;
    u8 unk_0F8[0x2];
    u8 unk_0FA;
    u8 unk_0FB;
    s32 unk_0FC;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10C;
    void* unk_110;
    u8 unk_114[0x14];
    u8 (*unk_128)(s32 a);
    s32 unk_12C;
    u8 unk_130[0x0C];
    u8 unk_13C[0x88];
    u16 unk_1C4;
    u16 unk_1C6;
    s16 unk_1C8;
    u8 unk_1CA[0x6];
} BtlWork;

typedef struct BtlSetup {
    u8 unk_000[0x8];
    u32 flags;
    u8 unk_00C[0x26];
    u16 hp;
    u8 unk_034[0xC4];
    u16 maxHp;
    u8 unk_0FA[0x116];
} BtlSetup;

typedef struct BtlDrawInfo {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    AnimState unk_10;
    void* unk_28;
    s32 unk_2C;
} BtlDrawInfo;

typedef struct BtlLockonWork {
    void* unk_000;
    void* unk_004;
    AnimState unk_008;
    void* unk_020;
    s16 unk_024;
    u8 unk_026[0x02];
} BtlLockonWork;

typedef struct BtlAreaWork {
    void* unk_000;
    void* unk_004;
    u8 unk_008;
    u8 unk_009;
    s16 unk_00A;
} BtlAreaWork;

typedef struct BtlSoraWork {
    void* unk_000;
    void* unk_004;
    u32 unk_008;
    AnimState unk_00C;
    u32 unk_024;
    u8 unk_028[0x10];
    u32 unk_038;
    u32 unk_03C;
    UnkStruct_0801AF08 unk_040;
    u8 unk_128[0x4];
    u16 unk_12C;
    u8 unk_12E[0x1A];
    s32 unk_148;
    s32 unk_14C;
    s32 unk_150;
    u16 unk_154;
    u16 unk_156;
    u16 unk_158;
    u16 unk_15A;
    s32 unk_15C;
    u8 unk_160;
    u8 unk_161;
    u8 unk_162[0x2];
    void* unk_164;
    void* unk_168;
    void* unk_16C;
    u8 unk_170[0x2];
    u8 unk_172;
    u8 unk_173[0x1];
    u16 unk_174;
    u8 unk_176[0x2];
    u16 unk_178;
    u8 unk_17A[0xA];
    u16* unk_184;
    u32 unk_188;
    u8 unk_18C[0x4];
    u8 unk_190;
    u8 unk_191[0xB];
    u32 unk_19C;
    u32 unk_1A0;
    u8 unk_1A4[0x4];
    u16 unk_1A8;
    u8 unk_1AA[0x2];
} BtlSoraWork;

typedef struct BtlRikuWork {
    void* unk_000;
    void* unk_004;
    ObjPalette* unk_008;
    u32 unk_00C;
    AnimState unk_010;
    u32 unk_028;
    u16 unk_02C;
    u8 unk_02E[0xE];
    u32 unk_03C;
    u32 unk_040;
    UnkStruct_0801AF08 unk_044;
    u32 unk_12C;
    u16 unk_130;
    u16 unk_132;
    u8 unk_134[0x18];
    s32 unk_14C;
    s32 unk_150;
    s32 unk_154;
    u16 unk_158;
    u16 unk_15A;
    u16 unk_15C;
    u16 unk_15E;
    s32 unk_160;
    u8 unk_164;
    u8 unk_165;
    u8 unk_166[0x2];
    void* unk_168;
    void* unk_16C;
    void* unk_170;
    u8 unk_174[0x4];
    u8 unk_178;
    u8 unk_179;
    u16 unk_17A;
    u8 unk_17C[0x2];
    u16 unk_17E;
    u8 unk_180[0x8];
    u16* unk_188;
    u32 unk_18C;
    u8 unk_190[0xC];
    u32 unk_19C;
    u32 unk_1A0;
    u8 unk_1A4[0x4];
    u16 unk_1A8;
    u8 unk_1AA[0x2];
    void* unk_1AC;
    u8 unk_1B0[0xC];
    u16 unk_1BC;
    u8 unk_1BE[0x2];
    u32 unk_1C0;
    u8 unk_1C4[0x2C];
    u32 unk_1F0;
    u8 unk_1F4[0x28];
    u32 unk_21C;
    u8 unk_220[0x30];
    u32 unk_250;
    u8 unk_254[0x8C];
    u32 unk_2E0;
    u8 unk_2E4[0x90];
} BtlRikuWork;

extern u8 gUnk_0813C1D4[];
extern u8 gUnk_0813C6E8[];
extern u8 gUnk_0813C704[];
extern u8 gUnk_0813C720[];
extern u8 gUnk_0813C73C[];
extern u8 gUnk_0813C758[];
extern u8 gUnk_0813C774[];
extern u8 gUnk_0813C790[];
extern u8 gUnk_0813C7AC[];
extern u8 gUnk_0813C1EC[];
extern u8 gUnk_0813C204[];
extern u8 gUnk_0813C21C[];
extern u8 gUnk_0813C234[];
extern u8 gUnk_0813C24C[];
extern u8 gUnk_0813C264[];
extern u8 gUnk_0813C27C[];

extern FldAnimDef gUnk_0813BA2C[];
extern FldAnimDef gUnk_0813BEFC[][5];
extern FldAnimDef gUnk_0813C2AC[];
extern FldAnimDef gUnk_0813C4DC[][5];

extern u16 gBldCnt;

extern BtlSetup gUnk_02039BB0;

extern BtlWork* gUnk_02039B84;
extern BtlWork* gUnk_02039B9C;

extern s16 gSineTable[];

extern u8 gUnk_08B1D8BC[];
extern u8 gUnk_08B1EA00[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_096FAC64[];
extern u8 gUnk_09618118[];
extern u8 gUnk_09EE10EC[];
extern u8 gUnk_09EE10F8[];
extern u8 gUnk_08F69BA4[];

void AnimInit(AnimState* a, void* b, void* c);
void func_08002A10(void* a, void* b);
void LoadObjPaletteBank(u16 bank, void* src);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void SetBlendAlpha(u16 a, u16 b);
u8 func_080128EC(void);
u16 func_0801AF1C(s32 a);
void func_08005974(AnimState* a, u8 b, u16 c, void* d, void* e);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void func_0801D288(void);
u16 GetRandom(void);
void m4aSongNumStart(u16 id);
void m4aSongNumStop(u16 id);
void func_08012304(void* a);
void TaskPoolDestroy(TaskPool* a);
BtlWork* func_08000C8C(void* node);
BtlWork* func_08000CD4(void* node);
void func_080140C0(s32* a, s32* b, s32* c);
void func_0801AF08(void* p);
void func_0802F284(s32 a, s32 b, s32 c);

void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(void* p);

typedef struct BtlMapWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} BtlMapWork;

extern const s8 gUnk_0813C7D8[];
void func_0800592C(s32* p, s32 target, u16 steps);
void func_08005690(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_0802F1C8(void);
void func_0802F1E8(void);
void func_0802F208(void);
s32 func_0802F268(void);
void func_0802F274(s32 a, s32 b);
void func_0802F284(s32 a, s32 b, s32 c);
s32 task_btl_map_1(BtlMapWork* work);

#endif /* GUARD_BTL_H */
