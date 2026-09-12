#ifndef GUARD_BTL3_H
#define GUARD_BTL3_H

#include "m4a_song.h"
#include "obj_api.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "game_state.h"
#include "taskpool.h"
#include "anim.h"
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
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
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
    u16 angle;
    u16 unk_5A;
    BtlObj* unk_5C;
    void* tiles;
    void* palette2;
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
    void* tiles;
    void* palette;
    void* palette2;
    AnimState anim;
    BtlObj* unk_24;
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

u8 CanAllocObjPalette(s32 a);
void func_08006B4C(void);
u8 IsSongPlaying(u16 song);
u8 func_08011E3C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_08013EDC(s32 a, s32 b, s32 c, s32 d);
void func_08014EC0(s32 a, s32 b, s32 c, s32 d);
void func_080155BC(s32 a, s32 b, s32 c, s32 d);
void func_08017260(s32 a, s32 b, s32 c, s32 d);
void func_080172F8(s32 a, s32 b, s32 c, s32 d);
void func_0801BDDC(void* a, s32 b, s32 c, s32 d);
void func_0802F284(s32 a, s32 b, s32 c);
u16 func_0803FDC8(BtlFormEntry* entry);

void task_btl_form_0(BtlFormWork* work, BtlFormList* list);
u8 task_btl_form_1(BtlFormWork* work);
void task_btl_form_3(void);
void task_btl_born_0(BtlBornWork* work, BtlBornArgs* args);
u8 task_btl_born_1(BtlBornWork* work);
void func_08040150(BtlRaidWork* work, s32* outX, s32* outY, s32* outZ);
void task_btl_raid_0(BtlRaidWork* work, BtlRaidArgs* args);
BtlObj* func_08040458(BtlRaidWork* work);
u8 task_btl_raid_1(BtlRaidWork* work);
void task_btl_raid_2(BtlRaidWork* work);
void task_btl_raid_3(BtlRaidWork* work);
void task_btl_badstatus_0(BtlBadStatusWork* work, BtlObj* obj);
u8 task_btl_badstatus_1(BtlBadStatusWork* work);
void task_btl_badstatus_2(BtlBadStatusWork* work);
void task_btl_badstatus_3(BtlBadStatusWork* work);
BtlObj* func_08040C8C(BtlAiWork* work);
BtlObj* func_08040D54(BtlAiWork* work);

#endif /* GUARD_BTL3_H */
