#ifndef GUARD_ROOM_H
#define GUARD_ROOM_H

#include "chara_api.h"
#include "m4a_song.h"
#include "text.h"
#include "obj_api.h"
#include "btl_collision.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "anim.h"
#include "text_types.h"
#include "taskpool.h"
#include "room_api.h"
#include "btl_api.h"

typedef struct RoomNameWork {
    void* tiles;
    void* palette;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    u8 unk_29;
    u16 unk_2A;
    u16 unk_2C;
    u8 unk_2E[0x2];
    s32 unk_30;
    u8 unk_34;
    u8 unk_35[0x3];
    void* unk_38;
    u8 unk_3C[0x120];
} RoomNameWork;

typedef struct UnkStruct_02039BA0 {
    u8 unk_00[0x70];
    u32 unk_70;
} UnkStruct_02039BA0;

extern UnkStruct_02039BA0* gUnk_02039BA0;

extern s16 gSineTable[];
extern s32 gUnk_0999204C[];
extern u8 gUnk_0993AF64[];
extern u8 gUnk_099910C4[];
extern void* gUnk_09EF8DA4;
extern void* gUnk_09EF7048[];

typedef struct GaEntryWork {
    s32 unk_000;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_010[0x24];
    u64 unk_034;
    u8 unk_03C[0x04];
    u8 unk_040[0x60];
    u16 unk_0A0;
    u8 unk_0A2[0x70];
    u8 unk_112;
    u8 unk_113;
    u16 unk_114;
    u8 unk_116[0x02];
    s32 unk_118;
    s32 unk_11C;
    s32 unk_120;
    s32 unk_124;
    s32 unk_128;
    s32 unk_12C;
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    s32 unk_13C;
    s32 unk_140;
    s32 unk_144;
    s32 unk_148;
    s32 unk_14C;
    s32 unk_150;
    s32 unk_154;
    u8 unk_158;
    u8 unk_159;
    u16 unk_15A;
    u16 unk_15C;
    u16 unk_15E;
    u16 unk_160;
    u8 unk_162[0x02];
    s32 unk_164;
    s32 unk_168;
    TaskPool unk_16C;
    AnimState anim;
    void* tiles;
    void* gfx;
    u32 unk_1A0;
    u8 unk_1A4;
    u8 unk_1A5[0x03];
} GaEntryWork;

typedef struct GaWork {
    s32 unk_000;
    s32 unk_004;
    u32 unk_008;
    u16 unk_00C;
    u16 unk_00E;
    s16 unk_010;
    s16 unk_012;
    s16 unk_014;
    u8 unk_016[0x02];
    s32 unk_018;
    u8 unk_01C;
    u8 unk_01D[0x03];
    GaEntryWork entries[6];
    AnimState anim;
    void* unk_A28;
    void* gfx;
    void* unk_A30;
    void* unk_A34;
    s32 unk_A38;
    s32 unk_A3C;
    s32 unk_A40;
    s32 unk_A44;
    s32 unk_A48;
    s32 unk_A4C;
    u16 unk_A50;
    u8 unk_A52;
    u8 unk_A53;
} GaWork;

typedef struct RoomTableEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    u16 unk_20;
    u16 unk_22;
} RoomTableEntry;

extern GaWork* gGaWork;
extern s32 gUnk_09991F44[];
extern RoomTableEntry gUnk_09991F54[];
extern u8 gTaskDescBtlShadow[];
extern u8 gUnk_09EF9728[];
extern u8 gUnk_099999AC[];
extern u8 gUnk_09EF9738[];

typedef struct RoomObjResource {
    void* unk_00;
    u16 refCount;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u8 unk_0C[0x10];
    u8 unk_1C[0x04];
    u32 unk_20;
} RoomObjResource;

typedef struct CharaObjParam {
    u32 unk_00;
    u16 unk_04;
    u8 unk_06[0x02];
    u32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
    u32 unk_10;
    u16 unk_14;
    u8 unk_16[0x02];
    u32 unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
    u32 unk_20;
    u16 unk_24;
    u8 unk_26[0x02];
    u32 unk_28;
    u16 unk_2C;
    u8 unk_2E[0x02];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u16 unk_44;
} CharaObjParam;

s32 func_080F7F70(GaWork* work, s16 i);
s32 func_080F7F94(GaWork* work, s16 i);
s32 func_080F7FAC(GaWork* work, s16 i);
s32 func_080F7FC8(GaWork* work, s16 i);
s32 func_080F7FE4(GaWork* work, s16 i);
void func_080F800C(GaWork* work, s32 i);
void func_080F80C0(GaWork* work);
void func_080F83BC(void);

u16 func_080F7DD8(s32 a);

void task_room_name_0(RoomNameWork* work, s32 arg);
u8 task_room_name_1(RoomNameWork* work);
void task_room_name_2(RoomNameWork* work);
void task_room_name_3(RoomNameWork* work);

#endif /* GUARD_ROOM_H */
