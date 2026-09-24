#ifndef GUARD_POO_DATA_H
#define GUARD_POO_DATA_H

#include "types.h"
#include "anim.h"

typedef struct PooPoint {
    s32 unk_00;
    s32 unk_04;
} PooPoint;

typedef struct PooSpot {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} PooSpot;

typedef struct PooMapBgDesc {
    void* tiles;
    u16 tilesSize;
    u16 unk_06;
    void* palette;
    u16 paletteSize;
    u16 unk_0E;
    void* tiles2;
    u16 tilesSize2;
    u8 mapWidth;
    u8 mapHeight;
} PooMapBgDesc;

extern const PooSpot gUnk_096FC05C[];
extern const PooSpot gUnk_096FC2F0[];
extern const PooPoint gUnk_096FC6B0[];
extern const PooMapBgDesc gPooMapBgDesc;
extern const PooSpot gUnk_096FD778[];

#endif
