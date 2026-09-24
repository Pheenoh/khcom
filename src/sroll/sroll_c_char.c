#include "sroll.h"
#include "sprites_staff_roll.h"

static s32 Square(s32 x) {
    return x * x;
}

void task_sroll_c_char_0(SrollCCharWork* w, s32 kind) {
    AnimState* p;
    s32 i;

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
#endif
    if (kind == 0) {
#ifdef VERSION_JP
        w->tiles = LoadObjTiles(gUnk_09C8D47A, 200 * 16);
#else
        w->tiles = LoadObjTiles(gUnk_09C8D47A, 154 * 32);
#endif
        w->palette = LoadObjPalette(gUnk_09D6CF54, 224);

        for (i = 0, p = w->anim; i <= 4; i++) {
            AnimInit(p, gUnk_09EFB9B8, gUnk_09EFB840);
            AnimStart(p, i, 0);
            p++;
        }
    } else {
#ifdef VERSION_JP
        w->tiles = LoadObjTiles(gUnk_09C8F1FA, 200 * 16);
#else
        w->tiles = LoadObjTiles(gUnk_09C8F1FA, 146 * 32);
#endif
        w->palette = LoadObjPalette(gUnk_09D6D034, 224);

        for (i = 0, p = w->anim; i <= 4; i++) {
            AnimInit(p, gUnk_09EFBAD4, gUnk_09EFB9CC);
            AnimStart(p, i, 0);
            p++;
        }
    }
#ifdef VERSION_EU
        break;
    case 1:
        if (kind == 0) {
            w->tiles = LoadObjTiles(gUnkEu_09CEF9E8, 168 * 32);
            w->palette = LoadObjPalette(gUnk_09D6CF54, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F879D4, gUnkEu_09F8785C);
                AnimStart(p, i, 0);
                p++;
            }
        } else {
            w->tiles = LoadObjTiles(gUnkEu_09CF1B7E, 158 * 32);
            w->palette = LoadObjPalette(gUnk_09D6D034, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F87AF0, gUnkEu_09F879E8);
                AnimStart(p, i, 0);
                p++;
            }
        }
        break;
    case 4:
        if (kind == 0) {
            w->tiles = LoadObjTiles(gUnkEu_09CF3FEE, 167 * 32);
            w->palette = LoadObjPalette(gUnk_09D6CF54, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F87C7C, gUnkEu_09F87B04);
                AnimStart(p, i, 0);
                p++;
            }
        } else {
            w->tiles = LoadObjTiles(gUnkEu_09CF6334, 186 * 32);
            w->palette = LoadObjPalette(gUnk_09D6D034, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F87D98, gUnkEu_09F87C90);
                AnimStart(p, i, 0);
                p++;
            }
        }
        break;
    case 3:
        if (kind == 0) {
            w->tiles = LoadObjTiles(gUnkEu_09CF86A2, 142 * 32);
            w->palette = LoadObjPalette(gUnk_09D6CF54, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F87F24, gUnkEu_09F87DAC);
                AnimStart(p, i, 0);
                p++;
            }
        } else {
            w->tiles = LoadObjTiles(gUnkEu_09CFA56C, 162 * 32);
            w->palette = LoadObjPalette(gUnk_09D6D034, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F88040, gUnkEu_09F87F38);
                AnimStart(p, i, 0);
                p++;
            }
        }
        break;
    case 2:
    default:
        if (kind == 0) {
            w->tiles = LoadObjTiles(gUnkEu_09CFCB38, 188 * 32);
            w->palette = LoadObjPalette(gUnk_09D6CF54, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F881CC, gUnkEu_09F88054);
                AnimStart(p, i, 0);
                p++;
            }
        } else {
            w->tiles = LoadObjTiles(gUnkEu_09CFEFA8, 190 * 32);
            w->palette = LoadObjPalette(gUnk_09D6D034, 224);

            for (i = 0, p = w->anim; i <= 4; i++) {
                AnimInit(p, gUnkEu_09F882E8, gUnkEu_09F881E0);
                AnimStart(p, i, 0);
                p++;
            }
        }
        break;
    }
#endif
}

u8 task_sroll_c_char_1(SrollCCharWork* w) {
    AnimState* p;
    s32 i;

    p = w->anim;

    for (i = 4; i >= 0; i--) {
        AnimUpdate(p);
        p++;
    }
    return 1;
}

void task_sroll_c_char_2(SrollCCharWork* w) {
    AnimState* p;
    s32 i;
    u16 flags;

    flags = 0;
    p = w->anim;

    for (i = 4; i >= 0; i--) {
        DrawSprite(120, 80, AnimGetGfx(p), w->tiles, w->palette, 0, flags, 0xFF0);
        p++;
    }
}

void task_sroll_c_char_3(SrollCCharWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

TaskDesc gTaskDescSrollCChar = {
    "task_sroll_c_char",
    (TaskInitFunc)task_sroll_c_char_0,
    (TaskUpdateFunc)task_sroll_c_char_1,
    (TaskFunc)task_sroll_c_char_2,
    (TaskFunc)task_sroll_c_char_3,
    0x98,
};
