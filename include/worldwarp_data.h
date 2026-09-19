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

extern WarpRect gUnk_099930E8[];
extern WarpIcon gUnk_09EF9384[];
extern WorldSelectDef gUnk_09EF9488[];

#endif
