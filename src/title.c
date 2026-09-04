#include "macros.h"
#include "title.h"
#include "gba/keys.h"

u8 gUnk_02034ED0;

void task_title_logo_0(TitleLogoWork* work) {
    func_080D62A8(work);
}

u8 task_title_logo_1(TitleLogoWork* work) {
    if (func_080D6280() && gUnk_02034ECC == 0) {
        work->unk_48 -= 76;
        work->unk_4C += 6;
        if (work->unk_4C > 255) {
            work->unk_4C = 0x100;
            work->unk_48 = 0;
            gUnk_02034ECC = 1;
        }
    }
    return 1;
}

#ifndef VERSION_JP
void task_title_logo_2(TitleLogoWork* work) {
    s32 i;
    s32 affine;
    s16 x;
    s16 y;

    for (i = 0; i < 6; i++) {
        if (i == 1 && !(gGameState.flags & 0x200)) {
            continue;
        }

        if (gGameState.flags & 0x200) {
            x = 0xA4;
        } else {
            x = 0x50;
        }
        y = 70;

        if (i == 0) {
            x++;
        }

        if (i == 1) {
            if (work->unk_4C == 0) {
                continue;
            }
            affine = AllocObjAffine(0, 0x100, work->unk_4C, 0);

            if (gGameState.flags & 0x200) {
                y = 86;
                x--;
            } else {
                y = 87;
            }
        } else {
            affine = 0;
        }
        DrawSprite(x, y, work->unk_00[i].unk_08, work->unk_00[i].unk_00, work->unk_00[i].unk_04, affine, 0, i + 20);
    }
}
#else
INCLUDE_ASM("title/task_title_logo_2.s");
#endif

void task_title_logo_3(TitleLogoWork* work) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ReleaseObjTiles(work->unk_00[i].unk_00);
        ReleaseObjPalette(work->unk_00[i].unk_04);
    }
}

void func_080D6548(u8* src, u16* dst, u16 size) {
    while (size != 0) {
        *dst = src[0] + (src[2] << 8);
        dst++;
        src += 4;
        size -= 4;
    }
}

u8 func_080D6574(void) {
    return gUnk_02034ECC;
}

#ifndef VERSION_EU
void task_title_obj_0(TitleObjWork* work) {
    s32 t;

    t = (gGameState.flags & 0x200) ? 0x20 : 0;
    work->unk_00[0].unk_00 = LoadObjTiles(gUnk_09771060, 0x3C0);
    work->unk_00[0].unk_04 = LoadObjPalette(gUnk_0984A718, 0x20);
    work->unk_00[0].unk_08 = gUnk_09EF65E0[0];

    if (gGameState.flags & 0x200) {
        work->unk_00[0].unk_10 = 0xBA00;
        work->unk_00[0].unk_0C = 0x76;
    } else {
        work->unk_00[0].unk_10 = 0x3D00;
        work->unk_00[0].unk_0C = 0x77;
    }
    work->unk_00[1].unk_00 = LoadObjTiles(gUnk_09771666, 0x700);
    work->unk_00[1].unk_04 = LoadObjPalette(&gUnk_0984A778[t], 0x20);
    work->unk_00[1].unk_10 = -0x7800;
    work->unk_00[1].unk_14 = 0x7C00;
    work->unk_00[1].unk_0C = 0xA0;
    AnimInit(&work->anim, gUnk_09EF6604, gUnk_09EF65F0);
    AnimStart(&work->anim, 0, 1);
    work->unk_00[1].unk_08 = AnimGetGfx(&work->anim);
    work->unk_00[2].unk_00 = LoadObjTiles(gUnk_0977143A, 0x100);
    work->unk_00[2].unk_04 = LoadObjPalette(&gUnk_0984A778[t], 0x20);
    work->unk_00[2].unk_08 = gUnk_09EF65E8[0];
    work->unk_00[2].unk_10 = 0x15800;
    work->unk_00[2].unk_14 = 0xB800;
    work->unk_00[2].unk_0C = 0x91;
    work->unk_60 = 30;
    gUnk_02034ED0 = 0;
    work->unk_62 = 0;
}
#else
INCLUDE_ASM("title/task_title_obj_0.s");
#endif

u8 task_title_obj_1(TitleObjWork* work) {
    if (func_080D6294()) {
        if (work->unk_62 != 0) {
            work->unk_62--;
        } else if (work->unk_60 != 0) {
            ApproachValue(&work->unk_00[1].unk_10, work->unk_00[1].unk_14, work->unk_60);
            ApproachValue(&work->unk_00[2].unk_10, work->unk_00[2].unk_14, work->unk_60);
            work->unk_60--;
            if (work->unk_60 == 0) {
                gUnk_02034ED0 = 1;
            }
        }
    }
    return 1;
}

#ifdef VERSION_JP
#define TITLE_OBJ_DRAW_COUNT 3
#else
#define TITLE_OBJ_DRAW_COUNT 2
#endif

void task_title_obj_2(TitleObjWork* work) {
    s32 i;

    work->unk_00[1].unk_08 = AnimUpdate(&work->anim);

    for (i = 0; i < TITLE_OBJ_DRAW_COUNT; i++) {
        DrawSprite(work->unk_00[i].unk_10 >> 8, work->unk_00[i].unk_0C, work->unk_00[i].unk_08,
                   work->unk_00[i].unk_00, work->unk_00[i].unk_04, 0, 0, i);
    }
}

void task_title_obj_3(TitleObjWork* work) {
    s32 i;

    for (i = 0; i < 3; i++) {
        ReleaseObjTiles(work->unk_00[i].unk_00);
        ReleaseObjPalette(work->unk_00[i].unk_04);
    }
}

u8 func_080D6790(void) {
    return gUnk_02034ED0;
}

#ifdef VERSION_US
void task_title_menu_0(TitleMenuWork* work, s16* arg) {
    s32 t;
    u8* pal;
    u8* pal2;

    t = (gGameState.flags & 0x200) ? 0x20 : 0;
    work->unk_44 = arg;

    if (arg[0] == 0) {
        if (gGameState.flags & 0x20) {
            work->unk_5C = 4;
            arg[0] = 4;
        } else {
            work->unk_5C = 1;
        }
    } else if (arg[0] == 3) {
        work->unk_5C = 2;
    } else if (gGameState.flags & 0x20) {
        work->unk_5C = 3;
    } else {
        work->unk_5C = 0;
    }
    work->tiles = LoadObjTiles(gUnk_09773E1A, 0x1600);
    work->palette = LoadObjPalette(gUnk_0984A7F8, 0x20);
    func_080D5978(work->palette->unk_06 + 16, gUnk_0984A7F8, 0x20);
    work->unk_08[0] = LoadObjTiles(gUnk_09771DC0, 0x280);
    work->unk_08[1] = LoadObjTiles(gUnk_097720F2, 0xB20);
    work->unk_08[2] = LoadObjTiles(gUnk_09772CC6, 0x700);
    pal = &gUnk_0984A778[t];
    work->unk_14[0] = LoadObjPalette(pal, 0x20);
    work->unk_14[1] = LoadObjPalette(pal, 0x20);
    pal2 = &gUnk_0984A7B8[t];
    work->unk_14[2] = LoadObjPalette(pal2, 0x20);
    func_080D5978(work->unk_14[0]->unk_06 + 16, pal, 0x20);
    func_080D5978(work->unk_14[2]->unk_06 + 16, pal2, 0x20);
    AnimInit(&work->anim, gUnk_09EF661C, gUnk_09EF6608);
    AnimStart(&work->anim, 0, 1);
    work->unk_20[0] = AnimGetGfx(&work->anim);
    work->unk_20[1] = gUnk_09EF6620[work->unk_44[0]];
    work->unk_20[2] = gUnk_09EF663C[work->unk_44[0]];
    TaskPoolInit(&work->unk_48, 1);
    TaskCreate(&work->unk_48, &gTaskDescTitleLumichange, 0);
}
#else
INCLUDE_ASM("title/task_title_menu_0.s");
#endif

s16 func_080D6908(s16 a) {
    s16 i;

    for (i = 0; i <= 3; i++) {
        if (a == gUnk_096FDCC8[i]) {
            break;
        }
    }

    if (i > 3) {
        i = 0;
    }
    return i;
}

void func_080D6944(s16* p) {
    s16 max;
    u16 keys;

    max = (gGameState.flags & 0x20) ? 2 : 1;
    keys = GetKeysPressed() & DPAD_UP;
    if (keys != 0) {
        m4aSongNumStart(0x65);
        (*p)--;

        if (*p < 0) {
            *p = max;
        }
    } else if (GetKeysPressed() & DPAD_DOWN) {
        m4aSongNumStart(0x65);
        *p = *p + 1;
        if (*p > max) {
            *p = 0;
        }
    }
}

void func_080D69AC(s16* p, s16 count) {
    s16 i;

    if (GetKeysPressed() & DPAD_UP) {
        m4aSongNumStart(0x65);
        i = func_080D6908(*p);
        i--;
        if (i < 0) {
            i = count;
        }
    } else if (GetKeysPressed() & DPAD_DOWN) {
        m4aSongNumStart(0x65);
        i = func_080D6908(*p);
        i++;
        if (i > count) {
            i = 0;
        }
    } else {
        return;
    }
    *p = gUnk_096FDCC8[i];
}

u8 task_title_menu_1(TitleMenuWork* work) {
    if (work->unk_5C == 0) {
        func_080D6944(work->unk_44);
    } else if (work->unk_5C == 3) {
        func_080D69AC(work->unk_44, 3);
    } else if (work->unk_5C == 4) {
        func_080D69AC(work->unk_44, 1);
    }
    TaskPoolUpdate(&work->unk_48);
    return 1;
}

#ifndef VERSION_EU
void func_080D6A64(TitleMenuWork* work) {
    s32 i;
    s32 t;
    s16 y;
    s16 count;

    y = 32;
    t = gGameState.flags & 0x20;
    count = 3;

    if (t == 0) {
        count = 2;
        y = 48;
    }

    for (i = 0; i < count; i++) {
        DrawSprite(work->unk_60, y, gUnk_09EF6668[i], work->tiles, work->palette, 0, 0x400, i + 100);
        y += 24;
    }

    if (gGameState.flags & 0x20) {
        y = work->unk_44[0] * 24 + 32;
    } else {
        y = work->unk_44[0] * 24 + 48;
    }

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}
#else
INCLUDE_ASM("title/func_080D6A64.s");
#endif

#ifndef VERSION_EU
void func_080D6B7C(TitleMenuWork* work) {
    s32 i;
    s16 y;

    y = 16;

    for (i = 0; i < 4; i++) {
        DrawSprite(work->unk_60, y, gUnk_09EF6668[gUnk_096FDCC8[i]], work->tiles, work->palette, 0, 0x400, i + 100);
        y += 24;
    }
    y = func_080D6908(work->unk_44[0]) * 24 + 16;

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}
#else
INCLUDE_ASM("title/func_080D6B7C.s");
#endif

#ifndef VERSION_EU
void func_080D6C54(TitleMenuWork* work) {
    s32 i;
    s16 y;

    y = 48;

    for (i = 0; i < 2; i++) {
        DrawSprite(work->unk_60, y, gUnk_09EF6668[gUnk_096FDCC8[i]], work->tiles, work->palette, 0, 0x400, i + 100);
        y += 24;
    }
    y = func_080D6908(work->unk_44[0]) * 24 + 48;

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}
#else
INCLUDE_ASM("title/func_080D6C54.s");
#endif

#ifndef VERSION_EU
void func_080D6D2C(TitleMenuWork* work) {
    s32 i;
    s16 y;

    y = 56;
    DrawSprite(work->unk_60, y, gUnk_09EF6668[work->unk_44[0]], work->tiles, work->palette, 0, 0x400, 100);

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}
#else
INCLUDE_ASM("title/func_080D6D2C.s");
#endif

#ifndef VERSION_EU
void task_title_menu_2(TitleMenuWork* work) {
    work->unk_20[0] = AnimUpdate(&work->anim);
    work->unk_20[1] = gUnk_09EF6620[work->unk_44[0]];
    work->unk_20[2] = gUnk_09EF663C[work->unk_44[0]];

    if (gGameState.flags & 0x200) {
        work->unk_60 = 120;
    } else {
        work->unk_60 = 0;
    }

    if (work->unk_5C == 0) {
        func_080D6A64(work);
    } else if (work->unk_5C == 3) {
        func_080D6B7C(work);
    } else if (work->unk_5C == 4) {
        func_080D6C54(work);
    } else {
        func_080D6D2C(work);
    }
    TaskPoolDraw(&work->unk_48);
}
#else
INCLUDE_ASM("title/task_title_menu_2.s");
#endif

void task_title_menu_3(TitleMenuWork* work) {
    s32 i;

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);

    for (i = 0; i < 3; i++) {
        ReleaseObjTiles(work->unk_08[i]);
        ReleaseObjPalette(work->unk_14[i]);
    }
    TaskPoolDestroy(&work->unk_48);
}

#ifndef VERSION_EU
void task_title_lumichange_0(TitleLumiChangeWork* work) {
    if (gGameState.flags & 0x200) {
        work->tiles = LoadObjTiles(gUnk_0977548C, 0x840);
        work->palette = LoadObjPalette(gUnk_0984A7D8, 0x20);
    } else {
        work->tiles = LoadObjTiles(gUnk_09773426, 0x940);
        work->palette = LoadObjPalette(gUnk_0984A7B8, 0x20);
    }
}
#else
INCLUDE_ASM("title/task_title_lumichange_0.s");
#endif

u8 task_title_lumichange_1(TitleLumiChangeWork* work) {
    s16 tbl[3];
    s16 v;
    u32 i;
    s32 j;

    v = GetPaletteEffect();
    memcpy(tbl, gUnk_096FDCE8, sizeof(tbl));

    switch (GetKeysPressed() & (L_BUTTON | R_BUTTON)) {
    case 0x100:
        for (i = 0; i < 3; i++) {
            if (v < tbl[i]) {
                v = tbl[i];
                m4aSongNumStart(0x67);
                break;
            }
        }
        break;
    case 0x200:
        for (j = 2; j > -1; j--) {
            if (v > tbl[j]) {
                v = tbl[j];
                m4aSongNumStart(0x67);
                break;
            }
        }
        break;
    }

    if (GetKeysPressed() & (L_BUTTON | R_BUTTON)) {
        SetPaletteEffect(v);
        func_080D5998();
    }
    return 1;
}

#ifndef VERSION_EU
void task_title_lumichange_2(TitleLumiChangeWork* work) {
    s16 v;
    void** tbl;
    s16 x;

    v = GetPaletteEffect();
    tbl = (gGameState.flags & 0x200) ? gUnk_09EF6684 : gUnk_09EF6658;

    if (v < 0) {
        work->unk_08 = tbl[0];
    } else if (v == 0) {
        work->unk_08 = tbl[1];
    } else if (v > 0) {
        work->unk_08 = tbl[2];
    }
    x = (gGameState.flags & 0x200) ? 240 : 0;
    DrawSprite(x, 0x8F, work->unk_08, work->tiles, work->palette, 0, 0x400, 100);
}
#else
INCLUDE_ASM("title/task_title_lumichange_2.s");
#endif

void task_title_lumichange_3(TitleLumiChangeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

ALIGN_ZERO(2);
