#ifndef GUARD_OBJ_H
#define GUARD_OBJ_H

#include "types.h"
#include "listpool.h"


typedef struct PaletteSlot {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x20];
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x02];
} PaletteSlot;

typedef struct ObjTiles {
    void* unk_00;
    u16 refCount;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    ListNode unk_0C;
    u32 unk_20;
    u8 unk_24;
    u8 unk_25[0x03];
    u32 unk_28;
    struct ObjTiles* self;
} ObjTiles;

typedef struct ObjPalette {
    void* unk_00;
    u16 refCount;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    ListNode unk_0C;
    u32 unk_20;
    struct ObjPalette* self;
} ObjPalette;

#endif
