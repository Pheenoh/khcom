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
    u32 unk_20;
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
void eu_0805E9F0(MonsgageWork* work);
s32 eu_0805EA44(MonsgageWork* work);
void eu_0805EC60(MonsgageWork* work);
void eu_0805ECE4(MonsgageWork* work);
#endif


extern u8 gUnk_08B2556C[];
extern u8 gUnk_08B2557C[];
extern u8 gUnk_08B25586[];
extern u8 gUnk_08B25590[];
extern u8 gUnk_08B2559A[];
extern u8 gUnk_08B255B4[];
#ifdef VERSION_EU
extern u8 gUnkEu_08B4FBC0[];
#endif

#endif /* GUARD_MONSGAGE_H */
