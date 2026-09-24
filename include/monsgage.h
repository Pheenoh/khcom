#ifndef GUARD_MONSGAGE_H
#define GUARD_MONSGAGE_H

#include "types.h"

typedef struct MonsgageWork {
    void* tiles;
    void* tiles2;
    void* palette;
    s32 unk_0C;
    s32 unk_10;
    void* gfx;
    void* gfx2;
    s16 unk_1C;
    u8 unk_1E[0x2];
    u32 state;
    u8 unk_24;
    u8 unk_25[0x3];
} MonsgageWork;

void task_monsgage_0(MonsgageWork* work);
s32 task_monsgage_1(MonsgageWork* work);
void task_monsgage_2(MonsgageWork* work);
void task_monsgage_3(MonsgageWork* work);

#ifdef VERSION_EU
void* eu_0805E924(const void* strings);
void* eu_0805E968(void* text);
s32 eu_0805E9AC(void* text);
#endif

#endif /* GUARD_MONSGAGE_H */
