#ifndef GUARD_WORLDWARP_DATA_H
#define GUARD_WORLDWARP_DATA_H

#include "types.h"
#include "anim.h"
#include "mode.h"
#include "world_types.h"

typedef struct WarpIcon {
    s16 up;
    s16 down;
    s16 left;
    s16 right;
    s16 x;
    s16 y;
    s16 rect;
    s16 x2;
    s16 y2;
    u8 unk_12[0x02];
} WarpIcon;

typedef struct WarpRect {
    s16 width;
    s16 height;
    s16 x;
    s16 y;
} WarpRect;

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
    WarpGfx unk_1C[2];
} WarpDef;

extern WarpRect gUnk_099930E8[];
extern const WarpDef gUnk_09993118[];
extern WarpIcon gUnk_09EF9384[];
extern WorldSelectDef gUnk_09EF9488[];

#endif
