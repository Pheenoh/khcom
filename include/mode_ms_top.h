#ifndef GUARD_MODE_MS_TOP_H
#define GUARD_MODE_MS_TOP_H

#include "types.h"
#include "anim.h"
#include "mode.h"

typedef struct WarpGfx {
    u16 x;
    s16 y;
    void* palette;
    u16 paletteSize;
    u8 unk_0A[0x02];
    void* tiles;
    u16 tilesSize;
    u8 unk_12[0x02];
    AnimHeader** anims;
    void** gfxTable;
    u16 animId;
    u8 unk_1E[0x02];
} WarpGfx;

typedef struct WarpDef {
    Mode* mode;
    void* unk_04;
    u16 unk_08;
    u16 x;
    s16 y;
    u16 animId;
    u16 x2;
    s16 y2;
    u16 flags;
    u16 x3;
    s16 y3;
    u8 unk_1A[0x02];
    WarpGfx gfx[2];
} WarpDef;

#endif
