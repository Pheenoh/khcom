#ifndef GUARD_EVENT_BACKGROUND_TYPES_H
#define GUARD_EVENT_BACKGROUND_TYPES_H

#include "types.h"

struct EventMapObjectDef;

typedef struct EventBackgroundDef {
    void* tiles;
    void* tiles2;
    void* palette;
    const void** maps;
    const void** maps2;
    const void** maps3;
    u16 tilesSize;
    u16 tilesSize2;
    u16 paletteSize;
    u8 mapWidth;
    u8 mapHeight;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25[3];
    struct EventMapObjectDef* mapObjects;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[2];
} EventBackgroundDef;

#endif
