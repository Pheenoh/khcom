#include "sroll.h"
#include "sprites_evt.h"
#include "sprites_smn.h"

static s32 Square(s32 x) {
    return x * x;
}

static inline s32 GetSrollCurtainOffset(void) {
    return (GetRandom() % 9) * 256 - 0x400;
}

void task_sroll_b_crtn_0(SrollBCrtnWork* w, SrollBCrtnArg* a) {
    AnimState* anim;
    s32 t;

    w->timer = 0;
    w->unk_04 = a->unk_00;
    switch (w->unk_04) {
    case 0:
    case 1:
    case 5:
        w->x = a->x;
        w->y = a->y + 0xFFFFE000;
        w->tiles = AllocObjTiles(128, gFEventTiles);
        w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
        anim = &w->anim;
        AnimInit(anim, gFEventAnims, gFEventFrames);
        AnimStart(anim, w->unk_04, 0);
        break;
    case 3:
        w->x = a->x;
        w->y = a->y + 0xFFFFD000;
        w->tiles = AllocObjTiles(128, gFEventTiles);
        w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
        anim = &w->anim;
        AnimInit(anim, gFEventAnims, gFEventFrames);
        AnimStart(anim, 0, 0);
        break;
    case 2:
        t = GetSrollCurtainOffset();
        w->x = a->x + t;
        t = GetSrollCurtainOffset();
        w->y = a->y + t;
        w->tiles = AllocObjTiles(128, gUnk_088A5D7A);
        w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
        anim = &w->anim;
        AnimInit(anim, gUnk_09EDE7E4, gUnk_09EDE7B4);
        AnimStart(anim, w->unk_04, 0);
        break;
    }
    FadeSetPaletteExcluded((w->palette->index & 15) + 16, 0);
}

u8 task_sroll_b_crtn_1(SrollBCrtnWork* w) {
    u8 r;

    r = 1;
    AnimUpdate(&w->anim);
    w->timer++;

    switch (w->unk_04) {
    case 1:
        if (w->timer > 120) {
            r = 0;
        }
        break;
    case 2:
        w->y += 0x100;

        if (w->timer > 20) {
            r = 0;
        }
        break;
    case 5:
        if (w->timer == 12) {
            AnimStart(&w->anim, 6, 1);
        }
    case 0:
    case 3:
        if (w->timer > 50) {
            r = 0;
        }
        break;
    }
    return r;
}

void task_sroll_b_crtn_2(SrollBCrtnWork* w) {
    DrawSprite(w->x >> 8, w->y >> 8, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x400,
               0xFE0);
}

void task_sroll_b_crtn_3(SrollBCrtnWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

TaskDesc gTaskDescSrollBCrtn = {
    "task_sroll_b_crtn",
    (TaskInitFunc)task_sroll_b_crtn_0,
    (TaskUpdateFunc)task_sroll_b_crtn_1,
    (TaskFunc)task_sroll_b_crtn_2,
    (TaskFunc)task_sroll_b_crtn_3,
    0x30,
};
