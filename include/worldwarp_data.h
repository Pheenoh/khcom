#ifndef GUARD_WORLDWARP_DATA_H
#define GUARD_WORLDWARP_DATA_H

#include "types.h"
#include "mode.h"
#include "world_types.h"

typedef struct WarpIcon {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12[0x02];
} WarpIcon;

typedef struct WarpRect {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} WarpRect;

typedef struct WarpGfx {
    u16 unk_00;
    s16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x02];
    void* unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
} WarpGfx;

typedef struct WarpDef {
    Mode* unk_00;
    void* unk_04;
    u16 unk_08;
    u16 unk_0A;
    s16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    s16 unk_12;
    u16 unk_14;
    u16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x02];
    WarpGfx unk_1C[2];
} WarpDef;

extern WarpRect gUnk_099930E8[];
extern const WarpDef gUnk_09993118[];
extern WarpIcon gUnk_09EF9384[];
extern WorldSelectDef gUnk_09EF9488[];

#endif
