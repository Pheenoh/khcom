#ifndef GUARD_PC_SPRITE_TYPES_H
#define GUARD_PC_SPRITE_TYPES_H

#include "types.h"

typedef struct PcSpriteDef {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} PcSpriteDef;

typedef char PcSpriteDef_size[(sizeof(PcSpriteDef) == 8) ? 1 : -1];

#endif
