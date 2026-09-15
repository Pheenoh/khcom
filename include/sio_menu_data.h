#ifndef GUARD_SIO_MENU_DATA_H
#define GUARD_SIO_MENU_DATA_H

#include "types.h"

typedef struct SioWorldEntry {
    void* tiles;
    u16 tilesSize;
    u16 unk_06;
    void* map;
    u16 mapSize;
    u16 unk_0E;
    void* palette;
    u16 paletteSize;
    u16 unk_16;
    void* text;
    u8 world;
    u8 unk_1D;
    u16 textX;
} SioWorldEntry;

typedef struct SioChgCardPos {
    s16 unk_00;
    s16 unk_02;
    s8 unk_04;
    s8 unk_05;
    s8 unk_06;
    s8 unk_07;
    s8 unk_08;
    u8 unk_09[3];
} SioChgCardPos;

extern SioWorldEntry gUnk_09EF1318[];
extern s8 gUnk_09EF14B8[];
extern u16 gUnk_09EF14C4[];
extern SioChgCardPos gUnk_09EF150C[];
extern u8* gWorldNames[];
extern u8 gUnk_09EF15FC[];

#endif
