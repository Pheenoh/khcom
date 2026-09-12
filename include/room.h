#ifndef GUARD_ROOM_H
#define GUARD_ROOM_H

#include "ga_types.h"

#include "field_state.h"

#include "chara_types.h"

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



extern s16 gSineTable[];
extern s32 gUnk_0999204C[];
extern u8 gUnk_0993AF64[];
extern u8 gUnk_099910C4[];
extern void* gUnk_09EF8DA4;
extern void* gUnk_09EF7048[];



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
