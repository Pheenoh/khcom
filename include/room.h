#include "room_data.h"
#include "map_text_data.h"
#include "map_ui_data.h"
#ifndef GUARD_ROOM_H
#define GUARD_ROOM_H

#include "registration_data.h"

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
#include "btl_api.h"

typedef struct RoomNameWork {
    void* tiles;
    void* palette;
    void* gfx;
    s32 x2;
    s32 y2;
    s32 x;
    s32 y;
    s32 scaleY;
    s32 unk_20;
    s32 unk_24;
    u8 state;
    u8 unk_29;
    u16 timer;
    u16 unk_2C;
    u8 unk_2E[0x2];
    s32 unk_30;
    u8 unk_34;
    u8 unk_35[0x3];
    void* palette2;
    u8 unk_3C[0x120];
} RoomNameWork;

extern u8 gUnk_099910C4[];

void task_room_name_0(RoomNameWork* work, s32 arg);
u8 task_room_name_1(RoomNameWork* work);
void task_room_name_2(RoomNameWork* work);
void task_room_name_3(RoomNameWork* work);

#endif /* GUARD_ROOM_H */
