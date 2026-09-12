#ifndef GUARD_CONTINUE_TYPES_H
#define GUARD_CONTINUE_TYPES_H

#include "types.h"
#include "anim.h"

typedef struct ContinueWork {
    void* tiles;
    void* palette;
    void* tiles2;
    void* palette2;
    void* tiles3;
    void* palette3;
    void* gfx;
    void* gfx2;
    AnimState unk_20;
    AnimState unk_38;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    s32 unk_60;
    u8 unk_64;
    u8 unk_65;
    u16 unk_66;
    u8 unk_68[2];
    u8 unk_6A;
    s8 unk_6B;
} ContinueWork;

#endif
