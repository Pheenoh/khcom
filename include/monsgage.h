#ifndef GUARD_MONSGAGE_H
#define GUARD_MONSGAGE_H

#include "types.h"
#include "game.h"

typedef struct MonsgageWork {
    void* unk_00;
    void* unk_04;
    void* palette;
    s32 unk_0C;
    s32 unk_10;
    void* unk_14;
    void* unk_18;
    s16 unk_1C;
    u8 unk_1E[0x2];
    u32 unk_20;
    u8 unk_24;
    u8 unk_25[0x3];
} MonsgageWork;

void task_monsgage_0(MonsgageWork* work);
s32 task_monsgage_1(MonsgageWork* work);
void task_monsgage_2(MonsgageWork* work);
void task_monsgage_3(MonsgageWork* work);

void* AllocObjTiles(s32 a, void* b);

extern u8 gUnk_08B2556C[];
extern u8 gUnk_08B2557C[];
extern u8 gUnk_08B25586[];
extern u8 gUnk_08B25590[];
extern u8 gUnk_08B2559A[];
extern u8 gUnk_08B255B4[];

#endif /* GUARD_MONSGAGE_H */
