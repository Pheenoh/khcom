#ifndef GUARD_OBJ_H
#define GUARD_OBJ_H

#include "types.h"
#include "listpool.h"


typedef struct PaletteSlot {
    void* src;
    void* dst;
    u8 buffer[0x20];
    u8 excluded;
    u8 dirty;
    u8 unk_2A[0x02];
} PaletteSlot;

typedef struct ObjTiles {
    void* src;
    u16 refCount;
    u16 index;
    u16 count;
    u16 unk_0A;
    ListNode node;
    u32 sprite;
    u8 allocated;
    u8 unk_25[0x03];
    u32 type;
    struct ObjTiles* self;
} ObjTiles;

typedef struct ObjPalette {
    void* src;
    u16 refCount;
    u16 index;
    u16 count;
    u16 unk_0A;
    ListNode node;
    u32 unk_20;
    struct ObjPalette* self;
} ObjPalette;

#endif
