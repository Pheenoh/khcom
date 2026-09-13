#ifndef GUARD_EVENT_BACKGROUND_TYPES_H
#define GUARD_EVENT_BACKGROUND_TYPES_H

#include "types.h"

struct EventMapObjectDef;

typedef struct EventBackgroundDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    const void** unk_0C;
    const void** unk_10;
    const void** unk_14;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25[3];
    struct EventMapObjectDef* unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[2];
} EventBackgroundDef;

#endif
