#ifndef GUARD_JIMINY_TYPES_H
#define GUARD_JIMINY_TYPES_H

#include "types.h"
#include "anim.h"
#include "obj.h"
#include "text_types.h"

#ifdef VERSION_US
typedef u16 JiminyTextChar;
#else
typedef u8 JiminyTextChar;
#endif

#ifdef VERSION_EU
typedef LocalizedText JiminyLocalizedName;

typedef struct JiminyLocalizedText {
    JiminyTextChar** lines[5];
    u16 lineCounts[5];
    u16 padding;
} JiminyLocalizedText;

typedef char JiminyLocalizedName_size[(sizeof(JiminyLocalizedName) == 20) ? 1 : -1];
typedef char JiminyLocalizedText_size[(sizeof(JiminyLocalizedText) == 32) ? 1 : -1];
#endif

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
    void* map;
    void* names;
    s16 count;
    s16 parent;
    u16* children;
    u16* flags;
    s32 detail;
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
    s32 x3;
    s32 y3;
    s32 y4;
    s32 x4;
    s32 y5;
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
    AnimState anim;
    AnimState anim2;
    u16 unk_CAC;
    s16 unk_CAE;
    s16 unk_CB0;
    s16 unk_CB2;
    u16** unk_CB4;
    u16* unk_CB8;
    u16* unk_CBC;
    s16 unk_CC0;
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    u8 unk_CCA[0x02];
    JiminyDetail* unk_CCC;
    u16 unk_CD0;
    s16 unk_CD2;
    s16 unk_CD4;
    s16 unk_CD6;
    JiminyPair unk_CD8[21];
    s32 unk_D2C;
    u32 unk_D30;
    s32 unk_D34;
    s32 unk_D38;
    u16 unk_D3C;
    u16 unk_D3E;
#ifdef VERSION_EU
    u16* unk_D40[100];
#endif
} JiminyWork;

#endif
