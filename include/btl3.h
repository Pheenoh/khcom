#ifndef GUARD_BTL3_H
#define GUARD_BTL3_H

#include "types.h"
#include "anim.h"
typedef struct UnkStruct_02039B84 {
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
    s16 unk_02C;
    s16 unk_02E;
    u32 unk_030;
    u64 unk_034;
    u8 unk_03C[0x0C];
    u32 unk_048;
    u32 unk_04C;
    u32 unk_050;
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
    struct UnkStruct_02039B84* unk_078;
    struct UnkStruct_02039B84* unk_07C;
    u8 unk_080[0x1C];
    u16 unk_09C;
    u16 unk_09E;
    u16 unk_0A0;
    s16 unk_0A2;
    u8 unk_0A4;
    u8 unk_0A5[0x03];
    u32 unk_0A8;
    u32 unk_0AC;
    u16 unk_0B0;
    u8 unk_0B2;
    u8 unk_0B3;
    u8 unk_0B4;
    u8 unk_0B5[0x03];
    u32 unk_0B8;
    u8 unk_0BC[0x10];
    u16 unk_0CC;
    u16 unk_0CE;
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
    u8 unk_100[0x14];
    void* unk_114;
    u32 unk_118;
    u32 unk_11C;
    u16 unk_120;
    u8 unk_122[0xAE];
} UnkStruct_02039B84;

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 flags;
    u8 unk_00C[0x1AC];
    u32 unk_1B8;
} UnkStruct_02039BB0;

typedef struct BtlFormStep {
    void* unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} BtlFormStep;

typedef struct BtlFormEntry {
    s16 unk_00;
    u8 unk_02[0x02];
    BtlFormStep* unk_04;
    u16 unk_08;
} BtlFormEntry;

typedef struct BtlFormList {
    s16 unk_00;
    u8 unk_02[0x02];
    BtlFormEntry** unk_04;
    s16 unk_08;
    u8 unk_0A[0x02];
} BtlFormList;

typedef struct BtlFormWork {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x02];
    BtlFormList* unk_08;
    BtlFormEntry* unk_0C;
    s16 unk_10;
    u8 unk_12[0x02];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    u16 unk_20;
    u16 unk_22;
    s16 unk_24;
    u8 unk_26[0x02];
} BtlFormWork;

typedef struct BtlVec {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} BtlVec;

typedef struct BtlBornWork {
    BtlVec unk_00;
    void* unk_0C;
    u16 unk_10;
    u16 unk_12;
} BtlBornWork;

typedef struct BtlBornArgs {
    void* unk_00;
    BtlVec unk_04;
    u16 unk_10;
    u16 unk_12;
} BtlBornArgs;

typedef struct BtlRaidWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s16 unk_38;
    s16 unk_3A;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E[0x02];
    u32 unk_40;
    s32 unk_44;
    u16 unk_48;
    u8 unk_4A[0x02];
    s32 unk_4C;
    s32 unk_50;
    s16 unk_54;
    u16 unk_56;
    u16 unk_58;
    u16 unk_5A;
    UnkStruct_02039B84* unk_5C;
    void* unk_60;
    void* unk_64;
    u16 unk_68;
    u8 unk_6A[0x02];
} BtlRaidWork;

typedef struct BtlRaidArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x06];
    s16 unk_12;
    s16 unk_14;
    u8 unk_16[0x06];
    u16 unk_1C;
    u8 unk_1E[0x02];
} BtlRaidArgs;

typedef struct BtlBadStatusWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    UnkStruct_02039B84* unk_24;
    u32 unk_28;
    void* unk_2C;
} BtlBadStatusWork;

typedef struct BtlAiWork {
    u8 unk_000[0x44];
    s32 unk_044;
    u8 unk_048[0x11B];
    u8 unk_163;
    u8 unk_164[0x08];
    s16 unk_16C;
} BtlAiWork;

extern UnkStruct_02039B84* gUnk_02039B84;
extern UnkStruct_02039B84* gUnk_02039B9C;
extern UnkStruct_02039BB0 gUnk_02039BB0;

extern s16 gSineTable[];
extern u8 gUnk_08901C8A[];
extern u8 gUnk_08B22CBC[];
extern u8 gUnk_08B22CE4[];
extern u8 gUnk_0813E8F4[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_096FAC64[];
extern u8 gUnk_09EDF124[];
extern u8 gUnk_09EDF154[];

u16 GetRandom(void);
void m4aSongNumStart(u16 song);
void TaskCreate(void* pool, void* desc, void* arg);
UnkStruct_02039B84* func_08000C8C(void* node);
UnkStruct_02039B84* func_08000CD4(void* node);
void* AllocObjTiles(s32 a, s32 b);
void* LoadObjTiles(void* src, s32 size);
void ReleaseObjTiles(void* a);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjPalette(void* a);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
u8 func_08003A98(u16 a);
u8 func_08003B24(s32 a);
void ApproachValue(void* a, s32 b, u16 c);
void ApproachAngle(void* a, u8 b, s32 c);
u16 func_08005B34(AnimState* a);
void AnimInit(AnimState* a, s32 b, s32 c);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
void func_08005974(AnimState* a, u16 b, u16 c, void* d, void* e);
void func_08002A10(void* a, void* b);
void func_08006B4C(void);
u8 IsSongPlaying(u16 song);
u8 func_08011E3C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
u8 func_080128EC(void);
void func_08013EDC(s32 a, s32 b, s32 c, s32 d);
void func_08014780(s32 a, s32 b, s32 c);
void func_08014EC0(s32 a, s32 b, s32 c, s32 d);
void func_080155BC(s32 a, s32 b, s32 c, s32 d);
void func_08017260(s32 a, s32 b, s32 c, s32 d);
void func_080172F8(s32 a, s32 b, s32 c, s32 d);
void func_08019068(void* a, AnimState* b, s32 c, s32 d, void* e);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void func_08019A30(void);
u32 func_0801A8A4(void* a, void* b, s32 c, s32 d);
u16 func_0801AF1C(s32 a);
void func_0801BDDC(void* a, s32 b, s32 c, s32 d);
s32 GetAngle(s32 a, s32 b, s32 c, s32 d);
void func_0802F284(s32 a, s32 b, s32 c);
u16 func_0803FDC8(BtlFormEntry* entry);

void task_btl_form_0(BtlFormWork* work, BtlFormList* list);
u8 task_btl_form_1(BtlFormWork* work);
void task_btl_form_3(void);
void task_btl_born_0(BtlBornWork* work, BtlBornArgs* args);
u8 task_btl_born_1(BtlBornWork* work);
void func_08040150(BtlRaidWork* work, s32* outX, s32* outY, s32* outZ);
void task_btl_raid_0(BtlRaidWork* work, BtlRaidArgs* args);
UnkStruct_02039B84* func_08040458(BtlRaidWork* work);
u8 task_btl_raid_1(BtlRaidWork* work);
void task_btl_raid_2(BtlRaidWork* work);
void task_btl_raid_3(BtlRaidWork* work);
void task_btl_badstatus_0(BtlBadStatusWork* work, UnkStruct_02039B84* obj);
u8 task_btl_badstatus_1(BtlBadStatusWork* work);
void task_btl_badstatus_2(BtlBadStatusWork* work);
void task_btl_badstatus_3(BtlBadStatusWork* work);
UnkStruct_02039B84* func_08040C8C(BtlAiWork* work);
UnkStruct_02039B84* func_08040D54(BtlAiWork* work);

#endif /* GUARD_BTL3_H */
