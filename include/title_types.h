#ifndef GUARD_TITLE_TYPES_H
#define GUARD_TITLE_TYPES_H

#include "types.h"

typedef struct TitleSprite {
    void* tiles;
    void* palette;
    void* gfx;
} TitleSprite;

typedef struct TitleLogoWork {
    TitleSprite unk_00[6];
    s32 unk_48;
    s32 unk_4C;
    u16 unk_50;
    u16 unk_52;
} TitleLogoWork;

#endif
