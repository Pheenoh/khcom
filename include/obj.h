#ifndef GUARD_OBJ_H
#define GUARD_OBJ_H

#include "types.h"

typedef struct ObjPalette {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} ObjPalette;

typedef struct PaletteSlot {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x20];
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x02];
} PaletteSlot;

#endif
