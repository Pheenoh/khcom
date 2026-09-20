#ifndef GUARD_MODE_DECK_H
#define GUARD_MODE_DECK_H

#include "mode.h"

typedef struct MenuWork {
    void* tiles;
    void* palette;
    s32 x;
    s32 y;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12[0x02];
} MenuWork;

extern Mode gUnk_09EE2704;

#endif
