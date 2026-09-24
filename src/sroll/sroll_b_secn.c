#include "sroll.h"
#include "sprites_staff_roll.h"

static s32 Square(s32 x) {
    return x * x;
}

void task_sroll_b_secn_0(SrollBSecnWork* w, SrollBSecnArg* a) {
    u32 i;

    w->unk_00 = 0;
    w->unk_04 = a->unk_04;
    w->unk_08 = a->unk_08;
    w->unk_0C = a->unk_0C;
    w->unk_10 = a->unk_10;

    if (a->unk_00 < 0) {
#ifdef VERSION_JP
        w->tiles = LoadObjTiles(gUnk_09C87A10, 590 * 32);
#else
        w->tiles = LoadObjTiles(gUnk_09C87A10, 606 * 32);
#endif
        w->palette = LoadObjPalette(gUnk_09D6CF34, 32);
        AnimInit(&w->anim, gUnk_09EFB834, gUnk_09EFB828);
        AnimStart(&w->anim, 0, 0);
        AnimInit(&w->anim2, gUnk_09EFB834, gUnk_09EFB828);
        AnimStart(&w->anim2, 0, 0);
    } else {
        w->tiles = LoadObjTiles(gUnk_09A54374[a->unk_00][0], *(u16*)&gUnk_09A54374[a->unk_00][1]);
        w->palette = LoadObjPalette(gUnk_09D6BE74, 256);
        AnimInit(&w->anim, gUnk_09A54374[a->unk_00][2], gUnk_09A54374[a->unk_00][3]);
        AnimStart(&w->anim, 0, 0);
        AnimInit(&w->anim2, gUnk_09A54374[a->unk_00][2], gUnk_09A54374[a->unk_00][3]);
        AnimStart(&w->anim2, 1, 0);
    }

    for (i = 0; i < 8; i++) {
        FadeSetPaletteExcluded((w->palette->index + i) % 16 + 16, 1);
    }
}

u8 task_sroll_b_secn_1(SrollBSecnWork* w) {
    u8 r;
    s16 y;

    r = 1;
    y = (w->unk_08 >> 8) - (*w->unk_0C >> 8);
    if (y <= -32) {
        r = 0;
    }

    if (y <= 159) {
        ApproachValueHalfSteps(&w->unk_04, 0x7800, 20);

        if (abs(w->unk_04 - 0x7800) <= 255) {
            w->unk_04 = 0x7800;
        }

        if (w->unk_04 == 0x7800) {
            AnimUpdate(&w->anim);
            AnimUpdate(&w->anim2);
        }
    }
    w->unk_00++;
    return r;
}

void task_sroll_b_secn_2(SrollBSecnWork* w) {
    u16 y;

    y = (w->unk_08 >> 8) - (*w->unk_0C >> 8);
    DrawSprite(120, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0, 0xEF0);
    DrawSprite(120, y, AnimGetGfx(&w->anim2), w->tiles, w->palette, 0, 0, 0xEE0);
}

void task_sroll_b_secn_3(SrollBSecnWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

void* const gUnk_09A54374[][4] = {
#if defined(VERSION_US)
    { gUnk_09C5D922, (void*)(27 * 32), gUnkUs_09EFAF98, gUnkUs_09EFAF78 },
    { gUnk_09C5DD46, (void*)(24 * 32), gUnkUs_09EFAFC0, gUnkUs_09EFAFA0 },
    { gUnk_09C5E15E, (void*)(37 * 32), gUnkUs_09EFAFE8, gUnkUs_09EFAFC8 },
    { gUnk_09C5E6E6, (void*)(27 * 32), gUnkUs_09EFB010, gUnkUs_09EFAFF0 },
    { gUnk_09C5EB5E, (void*)(39 * 32), gUnkUs_09EFB038, gUnkUs_09EFB018 },
    { gUnk_09C5F12C, (void*)(35 * 32), gUnkUs_09EFB060, gUnkUs_09EFB040 },
    { gUnk_09C5F678, (void*)(41 * 32), gUnkUs_09EFB088, gUnkUs_09EFB068 },
    { gUnk_09C5FC54, (void*)(21 * 32), gUnkUs_09EFB0B0, gUnkUs_09EFB090 },
    { gUnk_09C6000A, (void*)(39 * 32), gUnkUs_09EFB0D8, gUnkUs_09EFB0B8 },
    { gUnk_09C60662, (void*)(61 * 32), gUnkUs_09EFB100, gUnkUs_09EFB0E0 },
    { gUnk_09C60F20, (void*)(47 * 32), gUnkUs_09EFB128, gUnkUs_09EFB108 },
    { gUnk_09C61676, (void*)(61 * 32), gUnkUs_09EFB150, gUnkUs_09EFB130 },
    { gUnk_09C6259C, (void*)(50 * 32), gUnkUs_09EFB1A0, gUnkUs_09EFB180 },
    { gUnk_09C62CC8, (void*)(35 * 32), gUnkUs_09EFB1C8, gUnkUs_09EFB1A8 },
    { gUnk_09C63244, (void*)(47 * 32), gUnkUs_09EFB1F0, gUnkUs_09EFB1D0 },
    { gUnk_09C853DA, (void*)(79 * 32), gUnkUs_09EFB780, gUnkUs_09EFB760 },
    { gUnk_09C85EDE, (void*)(48 * 32), gUnkUs_09EFB7A8, gUnkUs_09EFB788 },
    { gUnk_09C865FC, (void*)(44 * 32), gUnkUs_09EFB7D0, gUnkUs_09EFB7B0 },
    { gUnk_09C86C68, (void*)(41 * 32), gUnkUs_09EFB7F8, gUnkUs_09EFB7D8 },
    { gUnk_09C872D4, (void*)(50 * 32), gUnkUs_09EFB820, gUnkUs_09EFB800 },
#elif defined(VERSION_JP)
    { gUnkJp_09C36046, (void*)(27 * 32), gUnkJp_09ED24A4, gUnkJp_09ED2484 },
    { gUnkJp_09C3646A, (void*)(24 * 32), gUnkJp_09ED24CC, gUnkJp_09ED24AC },
    { gUnkJp_09C36882, (void*)(37 * 32), gUnkJp_09ED24F4, gUnkJp_09ED24D4 },
    { gUnkJp_09C36E0A, (void*)(27 * 32), gUnkJp_09ED251C, gUnkJp_09ED24FC },
    { gUnkJp_09C37282, (void*)(39 * 32), gUnkJp_09ED2544, gUnkJp_09ED2524 },
    { gUnkJp_09C37850, (void*)(35 * 32), gUnkJp_09ED256C, gUnkJp_09ED254C },
    { gUnkJp_09C37D9C, (void*)(41 * 32), gUnkJp_09ED2594, gUnkJp_09ED2574 },
    { gUnkJp_09C38378, (void*)(21 * 32), gUnkJp_09ED25BC, gUnkJp_09ED259C },
    { gUnkJp_09C3872E, (void*)(39 * 32), gUnkJp_09ED25E4, gUnkJp_09ED25C4 },
    { gUnkJp_09C38D86, (void*)(61 * 32), gUnkJp_09ED260C, gUnkJp_09ED25EC },
    { gUnkJp_09C39644, (void*)(47 * 32), gUnkJp_09ED2634, gUnkJp_09ED2614 },
    { gUnkJp_09C39D9A, (void*)(61 * 32), gUnkJp_09ED265C, gUnkJp_09ED263C },
    { gUnkJp_09C3A652, (void*)(41 * 32), gUnkJp_09ED2684, gUnkJp_09ED2664 },
    { gUnkJp_09C3ACC0, (void*)(50 * 32), gUnkJp_09ED26AC, gUnkJp_09ED268C },
    { gUnkJp_09C3B3EC, (void*)(35 * 32), gUnkJp_09ED26D4, gUnkJp_09ED26B4 },
    { gUnkJp_09C3B968, (void*)(47 * 32), gUnkJp_09ED26FC, gUnkJp_09ED26DC },
    { gUnkJp_09C5DC00, (void*)(57 * 32), gUnkJp_09ED2C8C, gUnkJp_09ED2C6C },
    { gUnkJp_09C5E4D2, (void*)(83 * 32), gUnkJp_09ED2CB4, gUnkJp_09ED2C94 },
    { gUnkJp_09C5F020, (void*)(41 * 32), gUnkJp_09ED2CDC, gUnkJp_09ED2CBC },
    { gUnkJp_09C5F6C2, (void*)(71 * 32), gUnkJp_09ED2D04, gUnkJp_09ED2CE4 },
    { gUnkJp_09C6012C, (void*)(77 * 32), gUnkJp_09ED2D2C, gUnkJp_09ED2D0C },
    { gUnkJp_09C60C7E, (void*)(79 * 32), gUnkJp_09ED2D54, gUnkJp_09ED2D34 },
    { gUnkJp_09C6174C, (void*)(41 * 32), gUnkJp_09ED2D7C, gUnkJp_09ED2D5C },
    { gUnkJp_09C61DB8, (void*)(50 * 32), gUnkJp_09ED2DA4, gUnkJp_09ED2D84 },
#else
    { gUnkEu_09CBAA32, (void*)(27 * 32), gUnkEu_09F86CCC, gUnkEu_09F86CAC },
    { gUnkEu_09CBAE56, (void*)(24 * 32), gUnkEu_09F86CF4, gUnkEu_09F86CD4 },
    { gUnkEu_09CBB26E, (void*)(37 * 32), gUnkEu_09F86D1C, gUnkEu_09F86CFC },
    { gUnkEu_09CBB7F6, (void*)(27 * 32), gUnkEu_09F86D44, gUnkEu_09F86D24 },
    { gUnkEu_09CBBC6E, (void*)(39 * 32), gUnkEu_09F86D6C, gUnkEu_09F86D4C },
    { gUnkEu_09CBC23C, (void*)(35 * 32), gUnkEu_09F86D94, gUnkEu_09F86D74 },
    { gUnkEu_09CBC788, (void*)(41 * 32), gUnkEu_09F86DBC, gUnkEu_09F86D9C },
    { gUnkEu_09CBCD64, (void*)(21 * 32), gUnkEu_09F86DE4, gUnkEu_09F86DC4 },
    { gUnkEu_09CBD11A, (void*)(39 * 32), gUnkEu_09F86E0C, gUnkEu_09F86DEC },
    { gUnkEu_09CBD772, (void*)(61 * 32), gUnkEu_09F86E34, gUnkEu_09F86E14 },
    { gUnkEu_09CBE030, (void*)(47 * 32), gUnkEu_09F86E5C, gUnkEu_09F86E3C },
    { gUnkEu_09CE57D2, (void*)(61 * 32), gUnkEu_09F87594, gUnkEu_09F87574 },
    { gUnkEu_09CBE786, (void*)(61 * 32), gUnkEu_09F86E84, gUnkEu_09F86E64 },
    { gUnkEu_09CBF6AC, (void*)(50 * 32), gUnkEu_09F86ED4, gUnkEu_09F86EB4 },
    { gUnkEu_09CBFDD8, (void*)(35 * 32), gUnkEu_09F86EFC, gUnkEu_09F86EDC },
    { gUnkEu_09CC0354, (void*)(47 * 32), gUnkEu_09F86F24, gUnkEu_09F86F04 },
    { gUnkEu_09CE3122, (void*)(79 * 32), gUnkEu_09F874CC, gUnkEu_09F874AC },
    { gUnkEu_09CE3C26, (void*)(48 * 32), gUnkEu_09F874F4, gUnkEu_09F874D4 },
    { gUnkEu_09CE4344, (void*)(44 * 32), gUnkEu_09F8751C, gUnkEu_09F874FC },
    { gUnkEu_09CE49B0, (void*)(41 * 32), gUnkEu_09F87544, gUnkEu_09F87524 },
    { gUnkEu_09CE501C, (void*)(50 * 32), gUnkEu_09F8756C, gUnkEu_09F8754C },
#endif
};

TaskDesc gTaskDescSrollBSecn = {
    "task_sroll_b_secn",
    (TaskInitFunc)task_sroll_b_secn_0,
    (TaskUpdateFunc)task_sroll_b_secn_1,
    (TaskFunc)task_sroll_b_secn_2,
    (TaskFunc)task_sroll_b_secn_3,
    0x4C,
};
