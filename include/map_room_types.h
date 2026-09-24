#ifndef GUARD_MAP_ROOM_TYPES_H
#define GUARD_MAP_ROOM_TYPES_H

#include "types.h"

typedef struct UnkStruct_080E56B4 {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
} UnkStruct_080E56B4;

typedef struct UnkStruct_080EC760Entry {
    u16 unk_00;
    u8 unk_02[0x02];
    s32 unk_04;
    s32 unk_08;
} UnkStruct_080EC760Entry;

typedef struct UnkStruct_080E8864 {
    const u8* unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    const u8* unk_08;
    u16* unk_0C;
} UnkStruct_080E8864;

typedef struct UnkStruct_09EF70D0 {
    void* palette;
    u16 paletteSize;
    u8 unk_06[0x02];
    void* tiles;
    u16 tilesSize;
    u8 unk_0E[0x02];
    void* tiles2;
    u16 tilesSize2;
    u8 unk_16[0x02];
    u16* map3;
    u16* map2;
    u16* map;
    UnkStruct_080E8864* unk_24;
    UnkStruct_080E8864* unk_28;
    void* unk_2C;
    s32* unk_30;
    s32* unk_34;
    u16 song;
} UnkStruct_09EF70D0;

typedef struct UnkStruct_09EF8370 {
    void* palette;
    u16 paletteSize;
    u8 unk_06[0x02];
    void* tiles;
    u16 tilesSize;
    u8 unk_0E[0x02];
    void* tiles2;
    u16 tilesSize2;
    u8 unk_16[0x02];
    void* map3;
    void* map2;
    void* map;
    u8 mapWidth;
    u8 mapHeight;
    u8 unk_26[0x02];
    const u8* unk_28;
    struct UnkStruct_080E56B4* unk_2C;
    struct UnkStruct_080EC760Entry* unk_30;
    u16 song;
    u8 unk_36[0x02];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
#ifdef VERSION_EU
    u8 unk_50;
#endif
} UnkStruct_09EF8370;

#endif
