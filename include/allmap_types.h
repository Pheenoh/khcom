#ifndef GUARD_ALLMAP_TYPES_H
#define GUARD_ALLMAP_TYPES_H

#include "types.h"
#include "anim.h"

typedef struct AllmapRoomWork {
    void* tiles;
    void* palette;
    void* unk_008;
    void* unk_00C[4];
    void* gfx[4];
    AnimState anim[4];
    s16 unk_08C;
    s16 unk_08E;
    s32 unk_090;
    s32 unk_094;
    u8 unk_098;
    u8 unk_099;
    u16 unk_09A;
    u16 unk_09C;
    u8 unk_09E[0x02];
} AllmapRoomWork;

#endif
