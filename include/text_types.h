#ifndef GUARD_TEXT_TYPES_H
#define GUARD_TEXT_TYPES_H

#include "types.h"

#ifdef VERSION_US
typedef u16 TextChar;
#else
typedef u8 TextChar;
#endif

typedef struct LocalizedText {
    u8* strings[5];
} LocalizedText;

typedef struct TextSlot {
    void* tiles;
    u8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07;
} TextSlot;

#endif
