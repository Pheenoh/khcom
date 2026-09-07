#include "macros.h"
#include "title.h"
#include "gba/keys.h"

#ifdef VERSION_EU
extern u32 gLanguage;
extern void* gUnkEu_09F801D4[];
extern void* gUnkEu_09F80200[];
extern void* gUnkEu_09F80214[];
extern void* gUnkEu_09F81A80[];
extern void* gUnkEu_09F81A9C[];
extern void* gUnkEu_09F81AF0[];
extern void* gUnkEu_09F81AD4[];
extern void* gUnkEu_09F81AB8[];
extern void* gUnkEu_09F81B0C[];
extern u8 gUnkEu_0974E3CC[];
extern u8 gUnkEu_0974EC7C[];
extern u8 gUnkEu_0975038C[];
extern u8 gUnkEu_0974FBDC[];
extern u8 gUnkEu_0974F42C[];
extern u8 gUnkEu_097462F2[];
extern u8 gUnkEu_09746CA4[];
extern u8 gUnkEu_097483B4[];
extern u8 gUnkEu_09747C04[];
extern u8 gUnkEu_09747454[];
extern u8 gUnkEu_09748BA6[];
extern u8 gUnkEu_0974A284[];
extern u8 gUnkEu_0974D47A[];
extern u8 gUnkEu_0974C504[];
extern u8 gUnkEu_0974B306[];
extern u8 gUnkEu_0973F058[];
extern u8 gUnkEu_09741E9A[];
extern u8 gUnkEu_09742A74[];
extern u8 gUnkEu_0974507E[];
extern u8 gUnkEu_097445AC[];
extern u8 gUnkEu_09743812[];
extern u8 gUnkEu_09745B92[];
extern u8 gUnkEu_09F81A04[];
extern TaskDesc gUnkEu_09F80228;
extern u8 gUnkEu_09750AF8[];
extern u8 gUnkEu_09750EE4[];
extern u8 gUnkEu_09751ADE[];
extern u8 gUnkEu_097516F8[];
extern u8 gUnkEu_097512CA[];
extern void* gUnkEu_09F81C54[];
extern void* gUnkEu_09F81C5C[];
extern void* gUnkEu_09F81C74[];
extern void* gUnkEu_09F81C6C[];
extern void* gUnkEu_09F81C64[];
extern u8 gUnkEu_0973F402[];
extern u8 gUnkEu_0973FC6A[];
extern u8 gUnkEu_097415E8[];
extern u8 gUnkEu_09740D62[];
extern u8 gUnkEu_09740536[];
extern u8 gUnkEu_09F81A1C[];
extern u8 gUnkEu_09F81A08[];
extern u8 gUnkEu_09F81A34[];
extern u8 gUnkEu_09F81A20[];
extern u8 gUnkEu_09F81A7C[];
extern u8 gUnkEu_09F81A68[];
extern u8 gUnkEu_09F81A64[];
extern u8 gUnkEu_09F81A50[];
extern u8 gUnkEu_09F81A4C[];
extern u8 gUnkEu_09F81A38[];
extern u8 gUnkEu_0973EEFE[];
#endif

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

void task_title_logo_2(TitleLogoWork* work) {
    s32 i;
    s32 affine;
    s16 x;
    s16 y;

    for (i = 0; i < 6; i++) {
#ifndef VERSION_JP
        if (i == 1 && !(gGameState.flags & 0x200)) {
            continue;
        }
#endif

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
        DrawSprite(x, y, work->unk_00[i].gfx, work->unk_00[i].tiles, work->unk_00[i].palette, affine, 0, i + 20);
    }
}

void task_title_logo_3(TitleLogoWork* work) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ReleaseObjTiles(work->unk_00[i].tiles);
        ReleaseObjPalette(work->unk_00[i].palette);
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

void task_title_obj_0(TitleObjWork* work) {
    s32 t;

    t = (gGameState.flags & 0x200) ? 0x20 : 0;
#ifdef VERSION_EU
    work->unk_00[0].palette = LoadObjPalette(gUnk_0984A718, 0x20);
    switch (gLanguage) {
    case 0:
        work->unk_00[0].tiles = LoadObjTiles(gUnkEu_09750AF8, 0x3C0);
        work->unk_00[0].gfx = gUnkEu_09F81C54[0];
        break;
    case 1:
        work->unk_00[0].tiles = LoadObjTiles(gUnkEu_09750EE4, 0x3C0);
        work->unk_00[0].gfx = gUnkEu_09F81C5C[0];
        break;
    case 2:
        work->unk_00[0].tiles = LoadObjTiles(gUnkEu_09751ADE, 0x400);
        work->unk_00[0].gfx = gUnkEu_09F81C74[0];
        break;
    case 3:
        work->unk_00[0].tiles = LoadObjTiles(gUnkEu_097516F8, 0x3C0);
        work->unk_00[0].gfx = gUnkEu_09F81C6C[0];
        break;
    case 4:
        work->unk_00[0].tiles = LoadObjTiles(gUnkEu_097512CA, 0x400);
        work->unk_00[0].gfx = gUnkEu_09F81C64[0];
        break;
    case 5:
    case 6:
        break;
    }

    if (gGameState.flags & 0x200) {
        if (gLanguage == 4 || gLanguage == 2) {
            work->unk_00[0].unk_10 = 0xB500;
        } else {
            work->unk_00[0].unk_10 = 0xBA00;
        }
        work->unk_00[0].unk_0C = 0x76;
    } else {
        work->unk_00[0].unk_10 = 0x3D00;
        work->unk_00[0].unk_0C = 0x77;
    }
    switch (gLanguage) {
    case 0:
        work->unk_00[1].tiles = LoadObjTiles(gUnkEu_0973F402, 0x700);
        break;
    case 1:
        work->unk_00[1].tiles = LoadObjTiles(gUnkEu_0973FC6A, 0x7A0);
        break;
    case 2:
        work->unk_00[1].tiles = LoadObjTiles(gUnkEu_097415E8, 0x800);
        break;
    case 3:
        work->unk_00[1].tiles = LoadObjTiles(gUnkEu_09740D62, 0x700);
        break;
    case 4:
        work->unk_00[1].tiles = LoadObjTiles(gUnkEu_09740536, 0x700);
        break;
    case 5:
    case 6:
        break;
    }
    work->unk_00[1].palette = LoadObjPalette(&gUnk_0984A778[t], 0x20);
    work->unk_00[1].unk_10 = -0x7800;
    work->unk_00[1].unk_14 = 0x7C00;
    work->unk_00[1].unk_0C = 0xA0;
    switch (gLanguage) {
    case 0:
        AnimInit(&work->anim, gUnkEu_09F81A1C, gUnkEu_09F81A08);
        break;
    case 1:
        AnimInit(&work->anim, gUnkEu_09F81A34, gUnkEu_09F81A20);
        break;
    case 2:
        AnimInit(&work->anim, gUnkEu_09F81A7C, gUnkEu_09F81A68);
        break;
    case 3:
        AnimInit(&work->anim, gUnkEu_09F81A64, gUnkEu_09F81A50);
        break;
    case 4:
        AnimInit(&work->anim, gUnkEu_09F81A4C, gUnkEu_09F81A38);
        break;
    case 5:
    case 6:
        break;
    }
    AnimStart(&work->anim, 0, 1);
    work->unk_00[1].gfx = AnimGetGfx(&work->anim);
    work->unk_00[2].tiles = LoadObjTiles(gUnkEu_0973EEFE, 0x100);
    work->unk_00[2].palette = LoadObjPalette(&gUnk_0984A778[t], 0x20);
    work->unk_00[2].gfx = gUnk_09EF65E0[0];
#else
    work->unk_00[0].tiles = LoadObjTiles(gUnk_09771060, 0x3C0);
    work->unk_00[0].palette = LoadObjPalette(gUnk_0984A718, 0x20);
    work->unk_00[0].gfx = gUnk_09EF65E0[0];

    if (gGameState.flags & 0x200) {
        work->unk_00[0].unk_10 = 0xBA00;
        work->unk_00[0].unk_0C = 0x76;
    } else {
        work->unk_00[0].unk_10 = 0x3D00;
        work->unk_00[0].unk_0C = 0x77;
    }
    work->unk_00[1].tiles = LoadObjTiles(gUnk_09771666, 0x700);
    work->unk_00[1].palette = LoadObjPalette(&gUnk_0984A778[t], 0x20);
    work->unk_00[1].unk_10 = -0x7800;
    work->unk_00[1].unk_14 = 0x7C00;
    work->unk_00[1].unk_0C = 0xA0;
    AnimInit(&work->anim, gUnk_09EF6604, gUnk_09EF65F0);
    AnimStart(&work->anim, 0, 1);
    work->unk_00[1].gfx = AnimGetGfx(&work->anim);
    work->unk_00[2].tiles = LoadObjTiles(gUnk_0977143A, 0x100);
    work->unk_00[2].palette = LoadObjPalette(&gUnk_0984A778[t], 0x20);
    work->unk_00[2].gfx = gUnk_09EF65E8[0];
#endif
    work->unk_00[2].unk_10 = 0x15800;
    work->unk_00[2].unk_14 = 0xB800;
    work->unk_00[2].unk_0C = 0x91;
    work->unk_60 = 30;
    gUnk_02034ED0 = 0;
    work->unk_62 = 0;
}

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

    work->unk_00[1].gfx = AnimUpdate(&work->anim);

    for (i = 0; i < TITLE_OBJ_DRAW_COUNT; i++) {
        DrawSprite(work->unk_00[i].unk_10 >> 8, work->unk_00[i].unk_0C, work->unk_00[i].gfx,
                   work->unk_00[i].tiles, work->unk_00[i].palette, 0, 0, i);
    }
}

void task_title_obj_3(TitleObjWork* work) {
    s32 i;

    for (i = 0; i < 3; i++) {
        ReleaseObjTiles(work->unk_00[i].tiles);
        ReleaseObjPalette(work->unk_00[i].palette);
    }
}

u8 func_080D6790(void) {
    return gUnk_02034ED0;
}

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
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        work->tiles = LoadObjTiles(gUnkEu_09748BA6, 0x1600);
        break;
    case 1:
        work->tiles = LoadObjTiles(gUnkEu_0974A284, 0xFA0);
        break;
    case 2:
        work->tiles = LoadObjTiles(gUnkEu_0974D47A, 0xEE0);
        break;
    case 3:
        work->tiles = LoadObjTiles(gUnkEu_0974C504, 0xEA0);
        break;
    case 4:
        work->tiles = LoadObjTiles(gUnkEu_0974B306, 0x1120);
        break;
    case 5:
    case 6:
        break;
    }
#else
#ifdef VERSION_JP
    work->tiles = LoadObjTiles(gUnk_09773E1A, 0x2C00);
#else
    work->tiles = LoadObjTiles(gUnk_09773E1A, 0x1600);
#endif
#endif
    work->palette = LoadObjPalette(gUnk_0984A7F8, 0x20);
    func_080D5978(work->palette->unk_06 + 16, gUnk_0984A7F8, 0x20);
#ifdef VERSION_EU
    work->unk_08[0] = LoadObjTiles(gUnkEu_0973F058, 0x280);
    switch (gLanguage) {
    case 0:
        work->unk_08[1] = LoadObjTiles(gUnkEu_09741E9A, 0xB20);
        break;
    case 1:
        work->unk_08[1] = LoadObjTiles(gUnkEu_09742A74, 0xCE0);
        break;
    case 2:
        work->unk_08[1] = LoadObjTiles(gUnkEu_0974507E, 0xA60);
        break;
    case 3:
        work->unk_08[1] = LoadObjTiles(gUnkEu_097445AC, 0xA20);
        break;
    case 4:
        work->unk_08[1] = LoadObjTiles(gUnkEu_09743812, 0xCE0);
        break;
    case 5:
    case 6:
        break;
    }
    work->unk_08[2] = LoadObjTiles(gUnkEu_09745B92, 0x700);
#else
    work->unk_08[0] = LoadObjTiles(gUnk_09771DC0, 0x280);
    work->unk_08[1] = LoadObjTiles(gUnk_097720F2, 0xB20);
#ifdef VERSION_JP
    work->unk_08[2] = LoadObjTiles(gUnk_09772CC6, 0xE00);
#else
    work->unk_08[2] = LoadObjTiles(gUnk_09772CC6, 0x700);
#endif
#endif
    pal = &gUnk_0984A778[t];
    work->unk_14[0] = LoadObjPalette(pal, 0x20);
    work->unk_14[1] = LoadObjPalette(pal, 0x20);
    pal2 = &gUnk_0984A7B8[t];
    work->unk_14[2] = LoadObjPalette(pal2, 0x20);
    func_080D5978(work->unk_14[0]->unk_06 + 16, pal, 0x20);
    func_080D5978(work->unk_14[2]->unk_06 + 16, pal2, 0x20);
#ifdef VERSION_EU
    AnimInit(&work->anim, gUnkEu_09F81A04, gUnk_09EF65E8);
#else
    AnimInit(&work->anim, gUnk_09EF661C, gUnk_09EF6608);
#endif
    AnimStart(&work->anim, 0, 1);
    work->unk_20[0] = AnimGetGfx(&work->anim);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        work->unk_20[1] = gUnkEu_09F81A80[work->unk_44[0]];
        break;
    case 1:
        work->unk_20[1] = gUnkEu_09F81A9C[work->unk_44[0]];
        break;
    case 2:
        work->unk_20[1] = gUnkEu_09F81AF0[work->unk_44[0]];
        break;
    case 3:
        work->unk_20[1] = gUnkEu_09F81AD4[work->unk_44[0]];
        break;
    case 4:
        work->unk_20[1] = gUnkEu_09F81AB8[work->unk_44[0]];
        break;
    case 5:
    case 6:
        break;
    }
    work->unk_20[2] = gUnkEu_09F81B0C[work->unk_44[0]];
#else
    work->unk_20[1] = gUnk_09EF6620[work->unk_44[0]];
    work->unk_20[2] = gUnk_09EF663C[work->unk_44[0]];
#endif
    TaskPoolInit(&work->unk_48, 1);
#ifdef VERSION_EU
    TaskCreate(&work->unk_48, &gUnkEu_09F80228, 0);
#else
    TaskCreate(&work->unk_48, &gTaskDescTitleLumichange, 0);
#endif
}

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
#ifdef VERSION_EU
        void** spr = (void**)gUnkEu_09F801D4[gLanguage];

        DrawSprite(work->unk_60, y, spr[i], work->tiles, work->palette, 0, 0x400, i + 100);
#else
        DrawSprite(work->unk_60, y, gUnk_09EF6668[i], work->tiles, work->palette, 0, 0x400, i + 100);
#endif
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

void func_080D6B7C(TitleMenuWork* work) {
    s32 i;
    s16 y;

    y = 16;

    for (i = 0; i < 4; i++) {
#ifdef VERSION_EU
        void** spr = (void**)gUnkEu_09F801D4[gLanguage];

        DrawSprite(work->unk_60, y, spr[gUnk_096FDCC8[i]], work->tiles, work->palette, 0, 0x400, i + 100);
#else
        DrawSprite(work->unk_60, y, gUnk_09EF6668[gUnk_096FDCC8[i]], work->tiles, work->palette, 0, 0x400, i + 100);
#endif
        y += 24;
    }
    y = func_080D6908(work->unk_44[0]) * 24 + 16;

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}

void func_080D6C54(TitleMenuWork* work) {
    s32 i;
    s16 y;

    y = 48;

    for (i = 0; i < 2; i++) {
#ifdef VERSION_EU
        void** spr = (void**)gUnkEu_09F801D4[gLanguage];

        DrawSprite(work->unk_60, y, spr[gUnk_096FDCC8[i]], work->tiles, work->palette, 0, 0x400, i + 100);
#else
        DrawSprite(work->unk_60, y, gUnk_09EF6668[gUnk_096FDCC8[i]], work->tiles, work->palette, 0, 0x400, i + 100);
#endif
        y += 24;
    }
    y = func_080D6908(work->unk_44[0]) * 24 + 48;

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}

void func_080D6D2C(TitleMenuWork* work) {
    s32 i;
    s16 y;

    y = 56;
#ifdef VERSION_EU
    {
        void** spr = (void**)gUnkEu_09F801D4[gLanguage];

        DrawSprite(work->unk_60, y, spr[work->unk_44[0]], work->tiles, work->palette, 0, 0x400, 100);
    }
#else
    DrawSprite(work->unk_60, y, gUnk_09EF6668[work->unk_44[0]], work->tiles, work->palette, 0, 0x400, 100);
#endif

    for (i = 0; i < 3; i++) {
        DrawSprite(work->unk_60, y, work->unk_20[i], work->unk_08[i], work->unk_14[i], 0, 0, i);
    }
}

void task_title_menu_2(TitleMenuWork* work) {
    work->unk_20[0] = AnimUpdate(&work->anim);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        work->unk_20[1] = gUnkEu_09F81A80[work->unk_44[0]];
        break;
    case 1:
        work->unk_20[1] = gUnkEu_09F81A9C[work->unk_44[0]];
        break;
    case 2:
        work->unk_20[1] = gUnkEu_09F81AF0[work->unk_44[0]];
        break;
    case 3:
        work->unk_20[1] = gUnkEu_09F81AD4[work->unk_44[0]];
        break;
    case 4:
        work->unk_20[1] = gUnkEu_09F81AB8[work->unk_44[0]];
        break;
    case 5:
    case 6:
        break;
    }
    work->unk_20[2] = gUnkEu_09F81B0C[work->unk_44[0]];
#else
    work->unk_20[1] = gUnk_09EF6620[work->unk_44[0]];
    work->unk_20[2] = gUnk_09EF663C[work->unk_44[0]];
#endif

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

void task_title_lumichange_0(TitleLumiChangeWork* work) {
    if (gGameState.flags & 0x200) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            work->tiles = LoadObjTiles(gUnkEu_0974E3CC, 0x840);
            break;
        case 1:
            work->tiles = LoadObjTiles(gUnkEu_0974EC7C, 0x740);
            break;
        case 2:
            work->tiles = LoadObjTiles(gUnkEu_0975038C, 0x740);
            break;
        case 3:
            work->tiles = LoadObjTiles(gUnkEu_0974FBDC, 0x740);
            break;
        case 4:
            work->tiles = LoadObjTiles(gUnkEu_0974F42C, 0x740);
            break;
        case 5:
        case 6:
            break;
        }
#else
        work->tiles = LoadObjTiles(gUnk_0977548C, 0x840);
#endif
        work->palette = LoadObjPalette(gUnk_0984A7D8, 0x20);
    } else {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            work->tiles = LoadObjTiles(gUnkEu_097462F2, 0x940);
            break;
        case 1:
            work->tiles = LoadObjTiles(gUnkEu_09746CA4, 0x740);
            break;
        case 2:
            work->tiles = LoadObjTiles(gUnkEu_097483B4, 0x740);
            break;
        case 3:
            work->tiles = LoadObjTiles(gUnkEu_09747C04, 0x740);
            break;
        case 4:
            work->tiles = LoadObjTiles(gUnkEu_09747454, 0x740);
            break;
        case 5:
        case 6:
            break;
        }
#else
        work->tiles = LoadObjTiles(gUnk_09773426, 0x940);
#endif
        work->palette = LoadObjPalette(gUnk_0984A7B8, 0x20);
    }
}

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

void task_title_lumichange_2(TitleLumiChangeWork* work) {
    s16 v;
    void** tbl;
    s16 x;

    v = GetPaletteEffect();
#ifdef VERSION_EU
    {
        void** a = (void**)gUnkEu_09F80200[gLanguage];
        void** b = (void**)gUnkEu_09F80214[gLanguage];

        tbl = (gGameState.flags & 0x200) ? b : a;
    }
#else
    tbl = (gGameState.flags & 0x200) ? gUnk_09EF6684 : gUnk_09EF6658;
#endif

    if (v < 0) {
        work->gfx = tbl[0];
    } else if (v == 0) {
        work->gfx = tbl[1];
    } else if (v > 0) {
        work->gfx = tbl[2];
    }
    x = (gGameState.flags & 0x200) ? 240 : 0;
    DrawSprite(x, 0x8F, work->gfx, work->tiles, work->palette, 0, 0x400, 100);
}

void task_title_lumichange_3(TitleLumiChangeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

ALIGN_ZERO(2);
