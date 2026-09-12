#ifndef GUARD_JIMINY_TYPES_H
#define GUARD_JIMINY_TYPES_H

#include "types.h"
#include "anim.h"
#include "obj.h"
#include "text_types.h"

typedef struct JiminyPair {
    u16 unk_00;
    u16 unk_02;
} JiminyPair;

typedef struct JiminyDetail {
    void* name;
    void* text;
#ifndef VERSION_EU
    s16 lineCount;
    u16 padding;
#endif
    void* sprite;
    void* palette;
    void* tiles;
    void* sprite2;
    void* palette2;
    void* tiles2;
    void* bgMap;
    void* bgPalette;
    void* bgTiles;
    s16 paletteSize;
    u16 tileSize;
    s16 x;
    s16 y;
} JiminyDetail;

typedef struct JiminyLine {
    TextSlot unk_000[48];
} JiminyLine;

typedef struct JiminyEntry {
    void* unk_00;
    void* unk_04;
    s16 unk_08;
    s16 unk_0A;
    u16* unk_0C;
    u16* unk_10;
    void* unk_14;
} JiminyEntry;

typedef struct JiminyWork {
    s32 unk_000;
    void* tiles;
    ObjPalette* palette;
    void* tiles2;
    ObjPalette* palette2;
    ObjPalette* palette3;
    void* tiles3;
    ObjPalette* palette4;
    void* tiles4;
    ObjPalette* palette5;
    void* tiles5;
    ObjPalette* palette6;
    void* tiles6;
    ObjPalette* palette7;
    void* tiles7;
    ObjPalette* palette8;
    void* tiles8;
    ObjPalette* palette9;
    s16 unk_048;
    s16 unk_04A;
    s32 unk_04C;
    s32 unk_050;
    s32 unk_054;
    s32 unk_058;
    s32 unk_05C;
    JiminyLine unk_060[8];
    u8 unk_C60[8];
    u8 unk_C68[8];
    u8 unk_C70;
    u8 unk_C71;
    s16 unk_C72;
    s16 unk_C74;
    s16 unk_C76;
    s16 unk_C78;
    u8 unk_C7A[0x02];
    AnimState unk_C7C;
    AnimState unk_C94;
    u16 unk_CAC;
    s16 unk_CAE;
    s16 unk_CB0;
    s16 unk_CB2;
    u16** unk_CB4;
    u16* unk_CB8;
    u16* unk_CBC;
    s16 unk_CC0;
    s16 unk_CC2;
    s16 unk_CC4;
    s16 unk_CC6;
    s16 unk_CC8;
    u8 unk_CCA[0x02];
    JiminyDetail* unk_CCC;
    u16 unk_CD0;
    s16 unk_CD2;
    s16 unk_CD4;
    s16 unk_CD6;
    JiminyPair unk_CD8[21];
    s32 unk_D2C;
    u32 unk_D30;
    void* unk_D34;
    s32 unk_D38;
    u16 unk_D3C;
    u16 unk_D3E;
#ifdef VERSION_EU
    u16* unk_D40[100];
#endif
} JiminyWork;

#endif
