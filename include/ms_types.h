#ifndef GUARD_MS_TYPES_H
#define GUARD_MS_TYPES_H

#include "types.h"

typedef struct MapCardInventoryEntry {
    u16 cardType;
    u16 cardIndex;
    u16 category;
    s16 countsByValue[10];
    u16 unk_1A;
} MapCardInventoryEntry;

typedef struct MapCardCategoryDef {
    u16 leftCategory;
    u16 rightCategory;
    s16 displayIndex;
    u16 unk_06;
} MapCardCategoryDef;

typedef struct MsShopHosiArg {
    s16 x;
    s16 y;
    void* palette;
    u8 unk_08;
    u8 unk_09[0x3];
    s32 unk_0C;
} MsShopHosiArg;


#endif
