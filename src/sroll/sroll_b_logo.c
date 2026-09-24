#include "sroll.h"
#include "sprites_staff_roll.h"

static s32 Square(s32 x) {
    return x * x;
}

void task_sroll_b_logo_0(SrollBLogoWork* w, SrollBLogoArg* a) {
    AnimState* anim;
    u32 i;

    w->x = a->x;
    w->y = a->y;
    w->unk_08 = a->unk_08;
    w->unk_0C = a->unk_0C;
#ifdef VERSION_EU
    w->palette = LoadObjPalette(gUnk_09D6BE34, 64);
    w->tiles = LoadObjTiles(gUnk_09C5CC7C, 94 * 32);
#else
    w->tiles = LoadObjTiles(gUnk_09C5CC7C, 94 * 32);
    w->palette = LoadObjPalette(gUnk_09D6BE34, 64);
#endif
    anim = &w->anim;
    AnimInit(anim, gUnk_09EFAF6C, gUnk_09EFAF60);
    AnimStart(anim, a->animId, 0);

    for (i = 0; i < 2; i++) {
        FadeSetPaletteExcluded((w->palette->index + i) % 16 + 16, 1);
    }
}

u8 task_sroll_b_logo_1(SrollBLogoWork* w) {
    u8 r;

    r = 1;

    if ((s16)((w->y >> 8) - (*w->unk_08 >> 8)) <= -32) {
        r = 0;
    }
    AnimUpdate(&w->anim);
    return r;
}

void task_sroll_b_logo_2(SrollBLogoWork* w) {
    u16 y;

    y = (w->y >> 8) - (*w->unk_08 >> 8);
    DrawSprite(w->x >> 8, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0, 0xFF0);
}

void task_sroll_b_logo_3(SrollBLogoWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

TaskDesc gTaskDescSrollBLogo = {
    "task_sroll_b_logo",
    (TaskInitFunc)task_sroll_b_logo_0,
    (TaskUpdateFunc)task_sroll_b_logo_1,
    (TaskFunc)task_sroll_b_logo_2,
    (TaskFunc)task_sroll_b_logo_3,
    0x30,
};
