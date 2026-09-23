#ifndef GUARD_ROOM_DATA_H
#define GUARD_ROOM_DATA_H

#include "types.h"
#include "anim.h"
#include "battle_actor_types.h"
#include "boss_background_types.h"

typedef struct RoomTableEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 x2;
    u16 y2;
    void* owner;
    AnimHeader** anims;
    void** gfxTable;
    u16 spriteCount;
    u16 unk_22;
} RoomTableEntry;

extern const EmyKind gUnk_09991F44;
extern const RoomTableEntry gRoomTableEntries[];
extern const BosMapConfig gUnk_0999202C;
extern const s32 gUnk_0999204C[];

#endif
