#ifndef GUARD_TUTORIAL_H
#define GUARD_TUTORIAL_H

#include "card_api.h"

#include "movie_text.h"
#include "eventselect_api.h"

#include "obj_api.h"
#include "btl_effect.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "anim.h"
#include "game.h"
#include "btl4_api.h"

typedef struct TutorialWork {
    u16 unk_000;
    u16 unk_002;
    u32 unk_004;
    u32 unk_008;
    s16 unk_00C;
    s16 unk_00E;
    s16 unk_010;
    u16 unk_012;
    u16 unk_014;
    u8 unk_016[0x2];
    void* tiles;
    void* palette;
    u8 unk_020[0x10];
    u16 unk_030;
    u8 unk_032[0x6];
} TutorialWork;

void task_tutorial_0(TutorialWork* work, s32 arg1);
s32 task_tutorial_1(TutorialWork* work);
void task_tutorial_2(TutorialWork* work);
void task_tutorial_3(TutorialWork* work);

extern u32 gFrameCounter;
extern s16 gSineTable[];
extern u16 gBg0Cnt;
extern u8 gUnk_08B263D2[];
extern u8 gUnk_09EE15F0[];
extern u8 gUnk_09EE15C0[];

#endif /* GUARD_TUTORIAL_H */
