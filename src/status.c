#include "macros.h"
#include "status.h"

static StatusWork* gStatusWork;
static u8 gUnk_02034F00;
static s16 gUnk_02034F02;
static StatusStocklistWork* gStatusStocklistWork;
static BoogieWork* gBoogieWork;

s32 gUnk_0203C550;
#include "gba/keys.h"

void task_status_0(StatusWork* work) {
    gStatusWork = work;
    work->unk_14 = 0;
    gUnk_02034F00 = 0;
    work->unk_1A = 0;
    work->unk_1C = 0;
    TaskPoolInit(&work->pool, 9);
    TaskCreate(work, &gTaskDescStatusFriend, 0);
    TaskCreate(work, &gTaskDescStatusSora, 0);

    if (!(gGameState.flags & 8)) {
        TaskCreate(work, &gTaskDescStatusTab, &work->unk_14);
        TaskCreate(work, &gTaskDescStatusDeckname, &gUnk_02034F00);
    }
    TaskCreate(work, &gTaskDescStatusStocklist, &work->unk_14);
    TaskCreate(work, &gTaskDescStatusScrollcursor, &work->unk_1C);
    TaskCreate(work, &gTaskDescStatusMeswindow, &gUnk_02034F00);

    if (func_080D82D4() == 0) {
        work->unk_1A = ~work->unk_14;
    } else {
        work->unk_1A = 0;
    }
    TaskCreate(work, &gTaskDescStatusCursor, &work->unk_1A);
    gUnk_02034F02 = work->unk_1A + work->unk_1C;
}

#ifndef VERSION_EU
void func_080D764C(StatusWork* work) {
    u16 keys;

    keys = GetKeysRepeat() & DPAD_UP;
    if (keys != 0) {
        if (work->unk_1A > 0) {
            work->unk_1A--;
            m4aSongNumStart(121);
        } else if (work->unk_1C > 0) {
            work->unk_1C--;
            func_080D83F4();
            m4aSongNumStart(121);
        } else if (work->unk_1A == 0) {
            if (!(gGameState.flags & 8)) {
                work->unk_1A = ~work->unk_14;
                m4aSongNumStart(121);
                gUnk_02034F00 = 0;
            }
        }
    } else if (GetKeysRepeat() & DPAD_DOWN) {
        if (work->unk_1A < func_080D82D4() - 1) {
            if (work->unk_1A >= 0) {
                work->unk_1A++;
                m4aSongNumStart(121);
            } else if (func_080D82D4() != 0) {
                work->unk_1A = 0;
                m4aSongNumStart(121);
            } else {
                m4aSongNumStart(105);
            }
        } else if (work->unk_1C < func_080D8308()) {
            work->unk_1C++;
            func_080D8374();
            m4aSongNumStart(121);
        }
    } else if ((GetKeysRepeat() & DPAD_LEFT) && !(gGameState.flags & 8)) {
        if (work->unk_14 != 0) {
            work->unk_14--;

            if (work->unk_1A < 0 || func_080D82D4() == 0) {
                work->unk_1A = ~work->unk_14;
                gUnk_02034F00 = 0;
            } else {
                work->unk_1A = 0;
            }
            work->unk_1C = 0;
            func_080D8474(0);
            m4aSongNumStart(101);
        }
    } else if ((GetKeysRepeat() & DPAD_RIGHT) && !(gGameState.flags & 8)) {
        if (work->unk_14 <= 2) {
            work->unk_14++;

            if (work->unk_1A < 0 || func_080D82D4() == 0) {
                work->unk_1A = ~work->unk_14;
                gUnk_02034F00 = 0;
            } else {
                work->unk_1A = 0;
            }
            work->unk_1C = 0;
            func_080D8474(0);
            m4aSongNumStart(101);
        }
    } else if (GetKeysPressed() & 4) {
        if (work->unk_1A >= 0) {
            work->unk_1A = ~work->unk_14;
            work->unk_1C = 0;
            func_080D8474(0);
            m4aSongNumStart(121);
        }
    } else if ((GetKeysPressed() & 1) && func_080D8340() && gUnk_02034F00 == 0 && work->unk_1A >= 0) {
        gUnk_02034F00 = 1;
        m4aSongNumStart(102);
    } else if (gUnk_02034F00 != 0) {
        if ((GetKeysPressed() & 2) || !func_080D8340()) {
            gUnk_02034F00 = 0;
            m4aSongNumStart(104);
        }
    }
}
#else
INCLUDE_ASM("status/func_080D764C.s");
#endif

u8 task_status_1(StatusWork* work) {
    if (func_080D7B94()) {
        func_080D764C(work);
    }
    gUnk_02034F02 = work->unk_1A + work->unk_1C;
    TaskPoolUpdate(&work->pool);
    return 1;
}

void task_status_2(StatusWork* work) {
    TaskPoolDraw(&work->pool);
}

void task_status_3(StatusWork* work) {
    TaskPoolDestroy(&work->pool);
}

u8 func_080D7890(void) {
    return gUnk_02034F00;
}

s16 func_080D789C(void) {
    return gUnk_02034F02;
}

s16 func_080D78A8(void) {
    return gStatusWork->unk_1C;
}

void func_080D78B8(StatusBarWork* work) {
    work->unk_24 = 1;

    if (gUnk_0203C550 == 0) {
        gUnk_0203C550 = 4;
    } else {
        gUnk_0203C550 = 3;
    }

    if (work->unk_08 == 0) {
        work->unk_08 = 16;
    }
    LoadBgMap(3, gUnk_09848198, 0x500);
    work->unk_10 = -0x800;
    work->unk_18 = 0xA000;
    work->unk_20 = -0x8000;
}

#ifndef VERSION_EU
void task_status_bar_0(StatusBarWork* work) {
    work->tiles = LoadObjTiles(gUnk_097A18EC, 0x2E0);
    work->palette = LoadObjPalette(gUnk_0984B1B8, 0x20);
    work->unk_08 = 16;
    gUnk_0203C550 = 0;
    work->unk_0C = -0x800;
    work->unk_14 = 0xA000;
    work->unk_1C = -0x8000;
    work->unk_10 = 0;
    work->unk_18 = 0x9800;
    work->unk_20 = 0;
    work->unk_24 = 0;
    work->unk_25 = 0;
}
#else
INCLUDE_ASM("status/task_status_bar_0.s");
#endif

u8 task_status_bar_1(StatusBarWork* work) {
    switch (gUnk_0203C550) {
    case 0:
        ApproachValue(&work->unk_0C, work->unk_10, work->unk_08);
        ApproachValue(&work->unk_14, work->unk_18, work->unk_08);
        work->unk_08--;
        if (work->unk_08 == 0) {
            work->unk_08 = 16;
            gUnk_0203C550 = 1;
        }
        break;
    case 1:
        ApproachValue(&work->unk_1C, work->unk_20, work->unk_08);
        work->unk_08--;
        if (work->unk_08 == 0) {
            LoadBgMap(3, gUnk_09848698, 0x500);
            gUnk_0203C550 = 2;
        }
        break;
    case 3:
        ApproachValue(&work->unk_1C, work->unk_20, work->unk_08);
        work->unk_08--;
        if (work->unk_08 == 0) {
            work->unk_08 = 16;
            gUnk_0203C550 = 4;
        }
        break;
    case 4:
        if (!func_08006314() && work->unk_25 == 0) {
            func_08006184(0, 16);
            work->unk_25 = 1;
        }
        ApproachValue(&work->unk_0C, work->unk_10, work->unk_08);
        ApproachValue(&work->unk_14, work->unk_18, work->unk_08);
        work->unk_08--;
        if (work->unk_08 == 0) {
            return 0;
        }
        break;
    case 2:
        if (work->unk_24 == 0) {
            if (GetKeysPressed() & 8) {
                m4aSongNumStart(0x68);
                func_08006184(0, 16);
                func_080D7568(0);
                gUnk_0203C550 = 5;
            } else if (GetKeysPressed() & 2) {
                if (!func_080D7890()) {
                    m4aSongNumStart(0x68);
                    func_080D78B8(work);
                    func_080D7568(1);
                }
            }
        }
        break;
    case 5:
        if (!func_08006314()) {
            return 0;
        }
        break;
    }
    return 1;
}

#ifndef VERSION_EU
void task_status_bar_2(StatusBarWork* work) {
    DrawSprite(work->unk_1C >> 8, 0, gUnk_097A18CC, work->tiles, work->palette, 0, 0xC00, 29);

    if (gUnk_0203C550 != 2) {
        DrawSprite(128, work->unk_0C >> 8, gUnk_097A1864, work->tiles, work->palette, 0, 0xC00, 30);
        DrawSprite(128, work->unk_14 >> 8, gUnk_097A1898, work->tiles, work->palette, 0, 0xC00, 31);
    }
}
#else
INCLUDE_ASM("status/task_status_bar_2.s");
#endif

void task_status_bar_3(StatusBarWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

u8 func_080D7B94(void) {
    if (gUnk_0203C550 == 2) {
        return 1;
    }
    return 0;
}

#ifndef VERSION_EU
void task_status_tab_0(StatusTabWork* work, s32* arg) {
    work->unk_18 = arg;
    work->unk_00 = AllocObjTiles(func_08003524(gUnk_09EF6920, 4), gUnk_097A24A6);
    work->unk_08 = LoadObjPalette(gUnk_0984B218, 0x20);
    work->unk_10 = gUnk_09EF6920[*work->unk_18];
    work->unk_04 = AllocObjTiles(func_08003524(gUnk_09EF6934, 4), gUnk_097A28DA);
    work->unk_0C = LoadObjPalette(gUnk_0984B238, 0x20);
    work->unk_14 = gUnk_09EF6934[*work->unk_18];
}
#else
INCLUDE_ASM("status/task_status_tab_0.s");
#endif

#ifndef VERSION_EU
u8 task_status_tab_1(StatusTabWork* work) {
    work->unk_10 = gUnk_09EF6920[*work->unk_18];
    work->unk_14 = gUnk_09EF6934[*work->unk_18];
    return 1;
}
#else
INCLUDE_ASM("status/task_status_tab_1.s");
#endif

void task_status_tab_2(StatusTabWork* work) {
    DrawSprite(0, 16, work->unk_10, work->unk_00, work->unk_08, 0, 0x800, 10);
    DrawSprite(0, 16, work->unk_14, work->unk_04, work->unk_0C, 0, 0x800, 11);
}

void task_status_tab_3(StatusTabWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_08);
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_0C);
}

void task_status_sora_0(StatusSoraWork* work) {
    if (gGameState.flags & 8) {
        work->tiles = AllocObjTiles(0x800, 0);
        work->palette = LoadObjPalette(gUnk_09618118, 0x20);
        func_08002A10(work->tiles, gUnk_0891ED26);
        AnimInit(&work->anim, (s32)gUnk_09EDF38C, (s32)gUnk_09EDF374);
    } else {
        work->tiles = AllocObjTiles(0x500, 0);
        work->palette = LoadObjPalette(gUnk_08F683A4, 0x20);
        func_08002A10(work->tiles, gUnk_088E33C2);
        AnimInit(&work->anim, (s32)gUnk_09EDEE14, (s32)gUnk_09EDEE08);
    }
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_status_sora_1(StatusSoraWork* work) {
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_status_sora_2(StatusSoraWork* work) {
    s16 x;
    s16 y;

    if (gGameState.flags & 8) {
        x = 160;
        y = 65;
    } else {
        x = 140;
        y = 56;
    }
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, 0x800, 12);
}

void task_status_sora_3(StatusSoraWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_status_deckname_0(StatusDecknameWork* work, u8* arg) {
    func_08065ACC(work, 10);
    work->unk_58 = arg;
    work->unk_54 = func_08065B6C(func_080857BC(GetActiveDeckIndex()), work);
    work->palette = LoadObjPalette(gUnk_0984B1D8, 0x20);
}

u8 task_status_deckname_1(StatusDecknameWork* work) {
    return 1;
}

void task_status_deckname_2(StatusDecknameWork* work) {
    if (*work->unk_58 == 0) {
        func_080664D8(144, 142, work, work->palette, 4, work->unk_54);
    }
}

void task_status_deckname_3(StatusDecknameWork* work) {
    func_08065AE0(work, 10);
    ReleaseObjPalette(work->palette);
}

void task_status_cursor_0(StatusCursorWork* work, s16* arg) {
    work->unk_48 = arg;
    work->unk_00 = AllocObjTiles(func_08003524(gUnk_09EF68F0, 5), gUnk_097A1C54);
    work->unk_08 = LoadObjPalette(gUnk_0984B1D8, 0x20);
    AnimInit(&work->anim[0], (s32)gUnk_09EF6904, (s32)gUnk_09EF68F0);
    AnimStart(&work->anim[0], 0, 1);
    work->gfx[0] = AnimGetGfx(&work->anim[0]);
    work->unk_04 = AllocObjTiles(func_08003524(gUnk_09EF6908, 4), gUnk_097A2394);
    work->unk_0C = LoadObjPalette(gUnk_0984B1F8, 0x20);
    AnimInit(&work->anim[1], (s32)gUnk_09EF691C, (s32)gUnk_09EF6908);
    AnimStart(&work->anim[1], 0, 1);
    work->gfx[1] = AnimGetGfx(&work->anim[1]);
    work->unk_4C = *work->unk_48;
    if (work->unk_4C < 0) {
        work->unk_58 = gUnk_096FDD8C[~work->unk_4C];
        work->unk_5C = work->unk_58;
        work->unk_50 = 0x1000;
        work->unk_54 = 0x1000;
    } else {
        work->unk_58 = 0x1800;
        work->unk_5C = 0x1800;
        work->unk_50 = *work->unk_48 * 3072 + 0x2400;
        work->unk_54 = work->unk_50;
    }
    work->unk_4E = 0;
}

u8 task_status_cursor_1(StatusCursorWork* work) {
    s32 i;

    if (work->unk_4C != *work->unk_48) {
        work->unk_4C = *work->unk_48;
        work->unk_4E = 4;

        if (work->unk_4C < 0) {
            work->unk_5C = gUnk_096FDD8C[~work->unk_4C];
            work->unk_54 = 0x1000;
        } else {
            work->unk_5C = 0x1800;
            work->unk_54 = *work->unk_48 * 3072 + 0x2400;
        }
    }
    func_0805F1C0(&work->unk_50, work->unk_54);
    func_0805F1C0(&work->unk_58, work->unk_5C);

    for (i = 0; i < 2; i++) {
        work->gfx[i] = AnimUpdate(&work->anim[i]);
    }
    return 1;
}

void task_status_cursor_2(StatusCursorWork* work) {
    if (func_08006314() == 0) {
        if (!(gGameState.flags & 8) || func_080D8340()) {
            DrawSprite(work->unk_58 >> 8, (work->unk_50 >> 8) - 16, work->gfx[1], work->unk_04, work->unk_0C, 0, 0, 0);

            if (work->unk_4C >= 0) {
                DrawSprite(1, (work->unk_50 >> 8) + 3, work->gfx[0], work->unk_00, work->unk_08, 0, 0, 1);
            }
        }
    }
}

void task_status_cursor_3(StatusCursorWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_08);
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_0C);
}

#ifndef VERSION_EU
void task_status_stocklist_0(StatusStocklistWork* work, s32* arg) {
    s32 i;
    StatusEntry* e;

    gStatusStocklistWork = work;
    work->unk_4C0 = arg;
    e = work->entries;

    for (i = 0; i < 4; i++) {
        func_080D8584(e);
        e++;
    }

    if (gGameState.flags & 8) {
        for (i = 66; i <= 69; i++) {
            if (func_0800FBCC(i)) {
                func_080D8590(work->entries, i);
            }
        }
    } else {
        for (i = 0; i <= 65; i++) {
            if (func_0800FBCC(i)) {
                func_080D8590(work->entries, i);
                func_080D8590(&work->entries[func_080D85A8(i)], i);
            }
        }
    }

    for (i = 0; i < 8; i++) {
        work->unk_490[i] = 0;
    }
    func_080D8474(0);
    work->unk_4B0 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->tiles = LoadObjTiles(gUnk_097A2E16, 0xC0);
    work->unk_4B8 = LoadObjPalette(gUnk_0984B278, 0x20);
    work->unk_4BC = gUnk_097A2DF8;
    work->unk_4C6 = 0;
    work->unk_4C8 = 0;
}
#else
INCLUDE_ASM("status/task_status_stocklist_0.s");
#endif

u8 task_status_stocklist_1(StatusStocklistWork* work) {
    work->unk_4C6++;
    if (work->unk_4C6 > 24) {
        work->unk_4C8 = (work->unk_4C8 == 0) ? 1 : 0;
        work->unk_4C6 = 0;
    }
    return 1;
}

void task_status_stocklist_2(StatusStocklistWork* work) {
    s32 i;
    s16 y;

    y = 36;

    for (i = 0; i < 8; i++) {
        if (work->unk_490[i] != 0) {
            if (work->unk_4C8 != 0) {
                if (func_0800FD20(func_080D855C(func_080D78A8() + i))) {
                    DrawSprite(0, y, work->unk_4BC, work->tiles, work->unk_4B8, 0, 0x800, i + 13);
                }
            }
            DrawSprite(1, y, 0, work->unk_490[i], work->unk_4B0, 0, 0x800, i + 21);
        }
        y += 12;
    }
}

void task_status_stocklist_3(StatusStocklistWork* work) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (work->unk_490[i] != 0) {
            ReleaseObjTiles(work->unk_490[i]);
        }
    }
    ReleaseObjPalette(work->unk_4B0);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->unk_4B8);
}

u16 func_080D82D4(void) {
    if (gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].count <= 7) {
        return gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].count;
    }
    return 8;
}

u16 func_080D8308(void) {
    s16 v = gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].count - 8;
    if (v <= 0) {
        return 0;
    }
    return v;
}

u8 func_080D8340(void) {
    if (gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].count == 0) {
        return 0;
    }
    return 1;
}

void func_080D8374(void) {
    s32 i;

    ReleaseObjTiles(gStatusStocklistWork->unk_490[0]);

    for (i = 0; i < 7; i++) {
        gStatusStocklistWork->unk_490[i] = gStatusStocklistWork->unk_490[i + 1];
    }
    gStatusStocklistWork->unk_4C4++;
    gStatusStocklistWork->unk_490[7] = func_080D85C0(func_080D85F8(gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].unk_000[gStatusStocklistWork->unk_4C4 + 7]));
}

void func_080D83F4(void) {
    s32 i;

    ReleaseObjTiles(gStatusStocklistWork->unk_490[7]);

    for (i = 7; i > 0; i--) {
        gStatusStocklistWork->unk_490[i] = gStatusStocklistWork->unk_490[i - 1];
    }
    gStatusStocklistWork->unk_4C4--;
    gStatusStocklistWork->unk_490[0] = func_080D85C0(func_080D85F8(gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].unk_000[gStatusStocklistWork->unk_4C4]));
}

void func_080D8474(u16 a) {
    s32 i;

    for (i = 0; i <= 7; i++) {
        if (gStatusStocklistWork->unk_490[i] != 0) {
            ReleaseObjTiles(gStatusStocklistWork->unk_490[i]);
            gStatusStocklistWork->unk_490[i] = 0;
        }
    }
    gStatusStocklistWork->unk_4C4 = a;

    for (i = 0; i < gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].count - a && i <= 7; i++) {
        gStatusStocklistWork->unk_490[i] = func_080D85C0(func_080D85F8(gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].unk_000[a + i]));
    }
}

s32 func_080D855C(s16 a) {
    return gStatusStocklistWork->entries[*gStatusStocklistWork->unk_4C0].unk_000[a];
}

void func_080D8584(StatusEntry* e) {
    e->count = 0;
}

void func_080D8590(StatusEntry* e, s32 v) {
    e->unk_000[e->count] = v;
    e->count++;
}

s32 func_080D85A8(u32 a) {
    if (a <= 8) {
        return 1;
    }

    if (a >= 9 && a <= 46) {
        return 2;
    }
    return 3;
}

#ifndef VERSION_EU
void* func_080D85C0(u16 a) {
    UnkStruct_08F7CF18* d;
    void* t;

    d = &gUnk_08F7CF18[a];
    t = func_080038C8(d->unk_08);
    func_080038E4(t, d->unk_04[d->unk_0A], d->unk_00);
    return t;
}
#else
INCLUDE_ASM("status/func_080D85C0.s");
#endif

s32 func_080D85F8(s32 a) {
    switch (a) {
    case 1:
        return 46;
    case 5:
        return 5;
    case 6:
        return 47;
    case 4:
        return 6;
    case 7:
        return 48;
    case 8:
        return 49;
    case 0:
        return 50;
    case 2:
        return 51;
    case 3:
        return 52;
    case 39:
        return 53;
    case 38:
        return 54;
    case 42:
        return 55;
    case 41:
        return 56;
    case 70:
        return 57;
    case 27:
        return 58;
    case 28:
        return 59;
    case 29:
        return 60;
    case 23:
        return 61;
    case 24:
        return 62;
    case 25:
        return 63;
    case 26:
        return 64;
    case 34:
        return 65;
    case 46:
        return 66;
    case 58:
        return 67;
    case 71:
        return 68;
    case 44:
        return 69;
    case 32:
        return 70;
    case 31:
        return 71;
    case 35:
        return 72;
    case 50:
        return 73;
    case 56:
        return 74;
    case 30:
        return 75;
    case 33:
        return 76;
    case 43:
        return 77;
    case 40:
        return 78;
    case 36:
        return 79;
    case 37:
        return 80;
    case 45:
        return 81;
    case 9:
        return 0;
    case 11:
        return 1;
    case 13:
        return 2;
    case 15:
        return 3;
    case 17:
        return 11;
    case 19:
        return 4;
    case 21:
        return 44;
    case 10:
        return 7;
    case 12:
        return 8;
    case 14:
        return 9;
    case 16:
        return 10;
    case 18:
        return 12;
    case 20:
        return 13;
    case 22:
        return 45;
    case 47:
        return 18;
    case 52:
        return 20;
    case 53:
        return 26;
    case 51:
        return 28;
    case 55:
        return 30;
    case 49:
        return 22;
    case 48:
        return 24;
    case 57:
        return 16;
    case 59:
        return 15;
    case 60:
        return 14;
    case 61:
        return 32;
    case 62:
        return 36;
    case 63:
        return 34;
    case 64:
        return 38;
    case 65:
        return 40;
    case 66:
        return 82;
    case 67:
        return 83;
    case 68:
        return 84;
    case 54:
        return 31;
    case 69:
        return 42;
    case 72:
        return 0xFFFF;
    }
}

s16 func_080D885C(StatusScrollcursorWork* work) {
    if (func_080D8308() == 0) {
        return 40;
    }
    return *work->unk_0C * 84 / func_080D8308() + 40;
}

void task_status_scrollcursor_0(StatusScrollcursorWork* work, u16* arg) {
    work->unk_0C = arg;
    work->tiles = AllocObjTiles(func_08003524(gUnk_09EF6908, 4), gUnk_097A2394);
    work->palette = LoadObjPalette(gUnk_0984B1F8, 0x20);
    work->unk_08 = gUnk_09EF6908[4];
    work->unk_12 = func_080D885C(work);
}

u8 task_status_scrollcursor_1(StatusScrollcursorWork* work) {
    work->unk_12 = func_080D885C(work);
    return 1;
}

void task_status_scrollcursor_2(StatusScrollcursorWork* work) {
    if (func_080D8340()) {
        DrawSprite(84, work->unk_12, work->unk_08, work->tiles, work->palette, 0, 0x800, 6);
    }
}

void task_status_scrollcursor_3(StatusScrollcursorWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_status_meswindow_0(StatusMeswindowWork* work, u8* arg) {
    work->unk_1C = arg;
    work->unk_18 = 72;
    TaskPoolInit(&work->pool, 2);
    work->unk_14 = 0;
    work->unk_20 = 0;
}

u8 task_status_meswindow_1(StatusMeswindowWork* work) {
    s32 v;
    s16 idx;

    if (*work->unk_1C != 0) {
        idx = func_080D789C();
        if (idx >= 0) {
            v = func_080D855C(func_080D789C());
            if (work->unk_18 != v) {
                work->unk_18 = v;

                if (work->unk_14 != 0) {
                    work->unk_20 = func_080D8F04(work->unk_14);
                    func_08000DE8(&work->pool, work->unk_14);
                }
                work->unk_14 = func_080D8EB4(work, func_080D85F8(work->unk_18), work->unk_20, 88, 98);
                func_0800FD68(work->unk_18);
            }
            TaskPoolUpdate(&work->pool);
        }
    }
    return 1;
}

void task_status_meswindow_2(StatusMeswindowWork* work) {
    if (*work->unk_1C == 0) {
        DisableBg(0);
    } else {
        EnableBg(0);
        TaskPoolDraw(&work->pool);
    }
}

void task_status_meswindow_3(StatusMeswindowWork* work) {
    TaskPoolDestroy(&work->pool);
}

void task_status_message_0(StatusMessageWork* work, StatusMessageParam* arg) {
    func_08065ACC(work, 100);
    work->unk_328 = *arg;
    work->unk_320 = func_08065B6C(work->unk_328.unk_00, work);
    work->palette = LoadObjPalette(gUnk_0984B1B8, 0x20);
}

u8 task_status_message_1(StatusMessageWork* work) {
    return 1;
}

void task_status_message_2(StatusMessageWork* work) {
    func_080664D8(work->unk_328.unk_04, work->unk_328.unk_06, work, work->palette, 3, work->unk_320);
}

void task_status_message_3(StatusMessageWork* work) {
    func_08065AE0(work, 100);
    ReleaseObjPalette(work->palette);
}

s32 func_080D8AA4(void* pool, s16 x, s16 y, void* p) {
    StatusMessageParam param;

    param.unk_04 = x;
    param.unk_06 = y;
    param.unk_00 = p;
    TaskCreate(pool, &gTaskDescStatusMessage, &param);
}

void task_status_friend_0(StatusFriendWork* work) {
    work->unk_24 = func_080D8B84(work->unk_00, work->unk_0C, work->unk_18);
}

u8 task_status_friend_1(StatusFriendWork* work) {
    return 1;
}

void task_status_friend_2(StatusFriendWork* work) {
    s32 i;
    s16 x;

    x = (gGameState.flags & 8) ? 216 : 186;

    for (i = 0; i < work->unk_24; i++) {
        DrawSprite(x, 45, work->unk_18[i], work->unk_00[i], work->unk_0C[i], 0, 0x800, i + 7);
        x += 20;
    }
}

void task_status_friend_3(StatusFriendWork* work) {
    s32 i;

    for (i = 0; i < work->unk_24; i++) {
        ReleaseObjTiles(work->unk_00[i]);
        ReleaseObjPalette(work->unk_0C[i]);
    }
}

#ifdef NON_MATCHING
u16 func_080D8B84(void** a, void** b, void** c) {
    StatusFriendTable t;
    StatusCardDef* d;
    StatusFriendEntry* e;
    u16 n;
    u16 i;
    u16 lim;

    t = gUnk_096FDE24;

    if (gGameState.flags & 8) {
        lim = 1;
    } else {
        lim = 3;
    }
    n = 0;

    for (i = 0; i <= 7; i++) {
        e = &t.unk_00[i];
        if (gUnk_02039D2C & e->unk_00) {
            d = &gCardDefs[e->unk_02];
            a[n] = LoadObjTiles(d->unk_14, 0x100);
            b[n] = LoadObjPalette(d->unk_18, 0x20);
            c[n] = d->unk_10;
            n++;
            if (n >= lim) {
                break;
            }
        }
    }
    return n;
}
#else
INCLUDE_ASM("status/func_080D8B84.s");
#endif

void stock_mes_disp_0(StockMesDispWork* work, StockMesDispParam* arg) {
    gStockMesDispWork = (u8*)work;
    *(StockMesDispParam*)&work->unk_3C = *arg;
    work->unk_44 = func_080A235C(work->unk_42);

    if (work->unk_40 >= work->unk_44 - 1) {
        work->unk_40 = work->unk_44 - 1;
    }
    work->unk_00 = func_080D85C0(work->unk_42);
    work->unk_04 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    TaskPoolInit(&work->unk_24, 1);
    work->unk_38 = (void*)func_080D8AA4(&work->unk_24, work->unk_3C + 6, work->unk_3E + 16,
                                        func_080A2334(work->unk_42, work->unk_40));
    work->unk_08 = AllocObjTiles(func_08003524(gUnk_09EF6948, 2), gUnk_097A2CF6);
    work->unk_10 = LoadObjPalette(gUnk_0984B258, 0x20);
    work->unk_18 = gUnk_09EF6948[0];
    work->unk_0C = AllocObjTiles(func_08003524(gUnk_09EF6948, 2), gUnk_097A2CF6);
    work->unk_14 = LoadObjPalette(gUnk_0984B258, 0x20);
    work->unk_1C = gUnk_09EF6948[1];
    work->unk_20 = 0;
}
u8 stock_mes_disp_1(StockMesDispWork* work) {
    u8 changed = 0;

    if (GetKeysPressed() & R_BUTTON) {
        if (work->unk_40 < work->unk_44 - 1) {
            work->unk_40++;
            changed = 1;
        }
    } else if (GetKeysPressed() & L_BUTTON) {
        if (work->unk_40 != 0) {
            work->unk_40--;
            changed = 1;
        }
    }

    if (changed) {
        m4aSongNumStart(0x67);
        func_08000DE8(&work->unk_24, work->unk_38);
        work->unk_38 = (void*)func_080D8AA4(&work->unk_24, work->unk_3C + 6, work->unk_3E + 16, func_080A2334(work->unk_42, work->unk_40));
    }

    TaskPoolUpdate(&work->unk_24);
    return 1;
}

void stock_mes_disp_2(StockMesDispWork* work) {
    DrawSprite(work->unk_3C + 14, work->unk_3E - 4, 0, work->unk_00, work->unk_04, 0, 0, 5);

    if (work->unk_40 != 0) {
        DrawSprite(work->unk_3C - (work->unk_20 / 8) % 4, work->unk_3E, work->unk_18, work->unk_08, work->unk_10, 0, 0, 2);
    }

    if (work->unk_40 < work->unk_44 - 1) {
        DrawSprite(work->unk_3C + ((work->unk_20 / 8) % 4 + 136), work->unk_3E, work->unk_1C, work->unk_0C, work->unk_14, 0, 0, 3);
    }
    TaskPoolDraw(&work->unk_24);
    work->unk_20++;
}

void stock_mes_disp_3(StockMesDispWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
    ReleaseObjTiles(work->unk_08);
    ReleaseObjPalette(work->unk_10);
    ReleaseObjTiles(work->unk_0C);
    ReleaseObjPalette(work->unk_14);
    TaskPoolDestroy(&work->unk_24);
}

void* func_080D8EB4(void* pool, u16 b, u8 c, u16 d, s32 e) {
    StatusMesParam p;

    p.unk_04_16 = b;
    p.unk_04_00 = c;
    p.unk_00_00 = d;
    p.unk_00_16 = e;
    return TaskCreate(pool, &gTaskDescStockMesDisp, &p);
}

u8 func_080D8F04(void* a) {
    return gStockMesDispWork[0x40];
}

void func_080D8F14(BoogieWork* work) {
    if (gUnk_0203C560 <= 2) {
        gUnk_0203C56C = 0;
        gUnk_0203C570 = 0;

        if (gUnk_0203C558 == 0) {
            work->unk_000 = 8;
            work->unk_164 = TaskCreate(&work->unk_02C, &gTaskDescBosBoogieDisk, &work->unk_040);
        } else if (gUnk_0203C558 == 1) {
            work->unk_000 = 6;
            work->unk_004 = 0;
            func_0801BDDC(18, 0xA000, 0x24000, 0);
            func_0801BDDC(18, 0x15000, 0x24000, 0);
        } else if (gUnk_0203C558 == 2) {
            work->unk_000 = 6;
            work->unk_004 = 0;
            func_0801BDDC(17, 0xA000, 0x24000, 0);
            func_0801BDDC(17, 0x15000, 0x24000, 0);
        } else if (gUnk_0203C558 == 3) {
            work->unk_000 = 8;
            work->unk_164 = TaskCreate(&work->unk_02C, &gTaskDescBosBoogieKnifereader, 0);
        } else if (gUnk_0203C558 == 4) {
            work->unk_000 = 6;
            work->unk_004 = 0;
            func_0801BDDC(15, 0xA000, 0x24000, 0);
            func_0801BDDC(15, 0x15000, 0x24000, 0);
        } else {
            work->unk_000 = 8;
            work->unk_164 = TaskCreate(&work->unk_02C, &gTaskDescBosBoogieKaihuku, work);
        }
    }
}

void func_080D900C(BoogieWork* work, s32 a, u16 b) {
    if (work->unk_15C != a) {
        work->unk_15C = a;
        func_08005974(&work->anim, gUnk_096FDE54[a].unk_0C, b, gUnk_096FDE54[a].unk_00, gUnk_096FDE54[a].unk_04);
        func_08002A10(work->tiles, gUnk_096FDE54[a].unk_08);
    }
}

u8 func_080D9058(s32* a, s32* b) {
    u8 r;

    r = 0;

    if (*a < 0xA000) {
        *a = 0xA000;
        r = 1;
    }

    if (*a > 0x15000) {
        *a = 0x15000;
        r = 1;
    }

    if (*b < 0x22800) {
        *b = 0x22800;
        r = 1;
    }

    if (*b > 0x22800) {
        *b = 0x22800;
        r = 1;
    }
    return r;
}

void task_bos_boogie_0(BoogieWork* work) {
    u8 i;
    u16 sz;
    u16 t;

    gBoogieWork = work;
    TaskCreate(&gBtlWork->unk_40, &gTaskDescBosBoogieMap, gUnk_096FDF24);
    work->unk_000 = 0;
    work->unk_004 = 0;
    gUnk_0203C564 = 0;
    gUnk_0203C568 = 0;
    gUnk_0203C554 = 0;
    work->unk_174 = 0;
    gUnk_0203C55C = &work->unk_040;
    gUnk_0203C560 = 0;
    func_0801A920(128, 368, 576, 632);
    func_0801B37C(&work->unk_040, gUnk_096FDF14, 0x15000, 0x22800, -0x2000);
    work->unk_040.unk_10 = -0x2000;
    work->unk_040.unk_34 |= 4;
    func_0801C2DC(&work->unk_040, 1);
    work->unk_150 = 0;
    work->unk_154 = 0;
    work->unk_158 = 0;
    work->unk_00C = LoadObjPalette(gUnk_0984AF78, 0x20);
    work->unk_010 = LoadObjPalette(gUnk_08F69BC4, 0x20);
    sz = 0;

    for (i = 0; i <= 5; i++) {
        t = func_08003524(gUnk_096FDEE4[i].unk_00, gUnk_096FDEE4[i].unk_04);
        if (sz < t) {
            sz = t;
        }
    }
    work->tiles = AllocObjTiles(sz, 0);
    AnimInit(&work->anim, 0, 0);
    work->unk_15C = 9;
    func_080D900C(work, 0, 1);
    TaskPoolInit(&work->unk_02C, 7);
    TaskCreate(&work->unk_02C, &gTaskDescBosShadow, &work->unk_040);
    TaskCreate(&work->unk_02C, &gTaskDescBosBoogieMapanime, 0);
    TaskCreate(&work->unk_02C, &gTaskDescBosBoogieSaku, work);
    work->unk_160 = 0;
    work->unk_164 = 0;
    work->unk_168 = 0;
    work->unk_16C = 0;
    gBtlWork->unk_CC = work->unk_040.x;
    gBtlWork->unk_D0 = work->unk_040.y;
    gBtlWork->unk_D4 = work->unk_040.z;
}

INCLUDE_ASM("status/task_bos_boogie_1.s");

void task_bos_boogie_2(BoogieWork* work) {
    UnkStruct_0203C55C* a;
    u16 f;
    void* pal;
    s16 x;
    s16 y;

    a = &work->unk_040;
    f = func_0801AF1C(a->y);

    if (!(a->unk_34 & 4)) {
        f |= 1;
    }

    if (func_0801CA00(a) && work->unk_000 != 4) {
        pal = work->unk_010;
    } else {
        pal = work->unk_00C;
    }
    WorldToScreen(&x, &y, a->x, a->y, a->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, 0, f, -4100 - (a->y >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_3(BoogieWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->unk_00C);
    ReleaseObjPalette(work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

void func_080D9A14(void) {
    UnkStruct_0203C55C* t;

    t = (UnkStruct_0203C55C*)ListPoolFirst(&gBtlWork->unk_80);
    while (t != 0) {
        if (t->unk_00 != 39) {
            t->unk_34 |= 0x40;
            t->unk_24 = 0;
        }
        t = (UnkStruct_0203C55C*)ListPoolNext(&t->unk_B8);
    }
}

void func_080D9A58(void) {
    func_080D9A14();
    gUnk_0203C568 = 0;

    if (gUnk_0203C560 <= 2) {
        gUnk_0203C560 = 3;
        gUnk_0203C554 += 540;
    }
}

s32 func_080D9A90(void) {
    if (IsTaskActive((Task*)gBoogieWork->unk_160) != 0) {
        return *(s32*)((Task*)gBoogieWork->unk_160)->work;
    }
    return 11;
}

u8 func_080D9AC4(s32* a, s32* b, s16 c, u16 d) {
    u8 r;

    r = 0;

    if (*a < (128 - c) << 8) {
        *a = (128 - c) << 8;
        r = 1;
    }

    if (*a > (c + 368) << 8) {
        *a = (c + 368) << 8;
        r = 1;
    }

    if (*b < (576 - (s16)d) << 8) {
        *b = (576 - (s16)d) << 8;
        r = 1;
    }

    if (*b > ((s16)d + 632) << 8) {
        *b = ((s16)d + 632) << 8;
        r = 1;
    }
    return r;
}

u8 func_080D9B28(BoogieWork* work) {
    if (work->unk_000 == 3) {
        if (work->unk_16C->unk_00 == 9) {
            if (AnimGetFrame(&work->unk_16C->anim) <= 2) {
                if (!AnimIsFinished(&work->unk_16C->anim)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void func_080D9B6C(BoogieWork* work) {
    if (work->unk_160 <= 255) {
        work->unk_160 += 8;
    }

    if (work->unk_15C <= 255) {
        work->unk_15C += 8;
    }
}
