#ifndef GUARD_ROOM_DATA_H
#define GUARD_ROOM_DATA_H

#include "types.h"
#include "anim.h"
#include "battle_actor_types.h"

typedef struct RoomTableEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    void* unk_14;
    AnimHeader** unk_18;
    void** unk_1C;
    u16 unk_20;
    u16 unk_22;
} RoomTableEntry;

extern EmyKind gUnk_09991F44;
extern RoomTableEntry gUnk_09991F54[];
extern s32 gUnk_0999204C[];

#endif
