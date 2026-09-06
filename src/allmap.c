#include "macros.h"
#include "allmap.h"
#include "gba/keys.h"

s32 gUnk_02034E84;
s32 gUnk_02034E88;
s32 gUnk_02034E8C;
s32 gUnk_02034E90;

void task_allmap_room_0(AllmapRoomWork* work, AllmapRoomArg* arg) {
    void* pal;

    work->unk_08C = arg->unk_00;
    work->unk_08E = arg->unk_02;
    work->unk_090 = -arg->unk_02 << 8;
    work->unk_094 = arg->unk_02 << 8;
    work->unk_098 = arg->unk_04;
    work->unk_09C = arg->unk_06;
    work->unk_09A = func_080D35B0(work);

    if (work->unk_09C == 0) {
        work->tiles = LoadObjTiles(gUnk_0976B340, 0x2400);
        work->unk_008 = 0;
    } else {
        work->tiles = AllocObjTiles(func_08003524(gUnk_09EF6424, 17), gUnk_0976B340);
        work->unk_008 = gUnk_09EF6424[work->unk_09A];
    }

    if (work->unk_09C == 0 && work->unk_098 == gUnk_0203C590[6]) {
        pal = gUnk_0984A138;
    } else {
        pal = gUnk_0984A0F8 + func_080D37BC(work->unk_098);
    }
    work->palette = LoadObjPalette(pal, 32);
}

s32 task_allmap_room_1(void) {
    return 1;
}

void task_allmap_room_2(AllmapRoomWork* work) {
    s32 i;
    s16 x;
    s16 y;
    u16 g;
    u16 h;

    if (work->unk_09C == 0) {
        x = work->unk_08C * 24 - gUnk_0203C540;
        y = work->unk_08E * 24 - gUnk_0203C53C;
        g = 0x800;
        h = -4100 - work->unk_08E * 4;
    } else {
        if ((gUnk_02039BA0->unk_70 & 0x40000) != 0) {
            return;
        }
        x = work->unk_08C;
        y = work->unk_08E;
        g = 0;
        h = 80;
    }

    if (x < -32 || x > 240) {
        return;
    }

    if (y < -32) {
        return;
    }

    if (y > 160) {
        return;
    }

    if (work->unk_008 != 0) {
        DrawSprite(x, y, work->unk_008, work->tiles, work->palette, 0, g, h);
    }

    for (i = 0; i < 4; i++) {
        if (work->gfx[i] != 0) {
            work->gfx[i] = AnimUpdate(&work->anim[i]);
            DrawSprite(x, y, work->gfx[i], work->unk_00C[i], work->palette, 0, g, i - 4 + h);
        }
    }
}

void task_allmap_room_3(AllmapRoomWork* work) {
    s32 i;

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);

    for (i = 0; i < 4; i++) {
        if (work->unk_00C[i] != 0) {
            ReleaseObjTiles(work->unk_00C[i]);
        }
    }
}

Task* func_080D3A20(TaskPool* pool) {
    AllmapRoomArg arg;

    arg.unk_00 = 208;
    arg.unk_02 = 0;
    arg.unk_04 = gUnk_0203C590[6];
    arg.unk_06 = 1;
    return TaskCreate(pool, &gTaskDescAllmapRoom, &arg);
}

u8 func_080D3A70(u8 a, u8 b) {
    if (func_080DF51C(a) != 0) {
        if (func_080D5944(a, 8) != 0) {
            return 0;
        }
    }

    if (func_080D5944(a, 2) != 0) {
        return func_080D3564(a, b);
    }
    return 0;
}

#ifdef NON_MATCHING
u8 func_080D3AB8(u8 a, u8 b) {
    if (func_080DF51C(a) != 0) {
        if (func_080D5944(a, 8) != 0) {
            return 0;
        }
    }

    if (func_080D5944(a, 2) != 0) {
        if (func_080D3564(a, b) != 0) {
            return func_080D358C(a, b) == 0;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("allmap/func_080D3AB8.s");
#endif

void task_allmap_cursor_0(AllmapCursorWork* work, AllmapCursorPos* arg) {
    work->unk_30 = *arg;
    work->unk_24 = work->unk_30.unk_00 * 24 + 16 - gUnk_0203C540;
    work->unk_26 = work->unk_30.unk_02 * 24 + 11 - gUnk_0203C53C;
    work->unk_28 = -work->unk_26 << 8;
    work->unk_2C = work->unk_26 << 8;
    work->unk_34 = work->unk_3C = work->unk_24 << 8;
    work->unk_38 = work->unk_40 = work->unk_26 << 8;
    work->tiles = LoadObjTiles(gUnk_0976D7C0, 0xC0);
    work->palette = LoadObjPalette(gUnk_0984A1D8, 32);
    AnimInit(&work->anim, gUnk_09EF64C4, gUnk_09EF64B4);
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
    work->unk_44 = 0;
}

s32 task_allmap_cursor_1(AllmapCursorWork* work) {
    s32 x;
    s32 y;

    if (gUnk_0203C4E0 == 2) {
        if (gUnk_0203C508 > 6) {
            ApproachValue(&work->unk_28, work->unk_2C, gUnk_0203C508 - 7);
        } else if (gUnk_0203C508 > 3) {
            func_0800592C(&work->unk_28, work->unk_2C - 0x800, gUnk_0203C508 - 3);
        } else {
            func_0800592C(&work->unk_28, work->unk_2C, gUnk_0203C508);
        }
    }

    if (gUnk_0203C4E0 != 3) {
        work->gfx = gUnk_09EF64B4[0];
        return 1;
    }
    work->gfx = AnimUpdate(&work->anim);
    x = (work->unk_30.unk_00 * 24 + 16 - gUnk_0203C540) << 8;
    y = (work->unk_30.unk_02 * 24 + 11 - gUnk_0203C53C) << 8;
    if (x != work->unk_34 || y != work->unk_38) {
        work->unk_34 = x;
        work->unk_38 = y;
        work->unk_44 = 4;
    }

    if (work->unk_44 != 0) {
        ApproachValue(&work->unk_3C, work->unk_34, work->unk_44);
        ApproachValue(&work->unk_40, work->unk_38, work->unk_44);
        work->unk_44--;
    }
    return 1;
}

void task_allmap_cursor_2(AllmapCursorWork* work) {
    s16 x;
    s16 y;

    if (func_080D4D1C() != 0) {
        return;
    }

    if (gUnk_0203C4E0 != 3) {
        x = work->unk_24;
        y = work->unk_28 >> 8;
    } else {
        x = work->unk_3C >> 8;
        y = work->unk_40 >> 8;
    }
    DrawSprite(x - 15, y - 22, work->gfx, work->tiles, work->palette, 0, 0, 49);
}

void task_allmap_cursor_3(AllmapCursorWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

s16 func_080D3D40(u16 a) {
    u8* base;
    u8* p;
    s16 v;
    s16 q;
    u8* dst;

    v = 120 - a;

    if (v < 0) {
        v = 0;
    }
    q = v / 8;
    base = GetBgScreenBase(2);
    dst = base + 28;
    p = gUnk_0983B7B4 - q * 2;
    RequestDma3Copy(p, dst, 32);
    dst = base + 92;
    p += 64;
    RequestDma3Copy(p, dst, 32);
    dst = base + 156;
    p += 64;
    RequestDma3Copy(p, dst, 32);
    return v - v % 8 / 2;
}
s32 func_080D3DCC(u8 a) {
    switch (func_080987C0(a)) {
    case 1:
        return 64;
    case 2:
        return 96;
    case 4:
        return 0;
    case 0:
    case 3:
    default:
        return 32;
    }
}

void task_allmap_roomname_0(AllmapRoomnameWork* work, u8* arg) {
    u16 pal;

#ifdef VERSION_EU
    func_08065ACC(work, 36);
#else
    func_08065ACC(work, 24);
#endif
    work->unk_0CC = func_08065B6C(func_08093C18(arg[0]), work);
    pal = func_080D3DCC(arg[0]);
    work->palette = LoadObjPalette(gUnk_0984A1F8 + pal, 32);
    LoadPalette(gUnk_0984A078 + pal, gUnk_05000160, 32);
    work->unk_0CE = func_080D3D40(func_08065B08(work, work->unk_0CC));
}

s32 task_allmap_roomname_1(void) {
    return 1;
}

void task_allmap_roomname_2(AllmapRoomnameWork* work) {
    func_080664D8(work->unk_0CE + 117, 3, work, work->palette, 50, work->unk_0CC);
}

void task_allmap_roomname_3(AllmapRoomnameWork* work) {
#ifdef VERSION_EU
    func_08065AE0(work, 36);
#else
    func_08065AE0(work, 24);
#endif
    ReleaseObjPalette(work->palette);
}

void func_080D3ED0(void) {
    u8* base;
    u8* p;
    u8* dst;

    base = GetBgScreenBase(2);
    dst = base + 28;
    p = gUnk_08125E24;
    RequestDma3Copy(p, dst, 32);
    dst = base + 92;
    p += 64;
    RequestDma3Copy(p, dst, 32);
    dst = base + 156;
    p += 64;
    RequestDma3Copy(p, dst, 32);
}

void func_080D3F10(AllmapBarWork* work) {
    work->unk_2C = 1;

    if (work->unk_28 == 0) {
        work->unk_28 = 4;
    } else {
        work->unk_28 = 3;
    }

    if (work->unk_0C == 0) {
        work->unk_0C = 16;
    }
    LoadBgMap(3, gUnk_0983AD98, 0x500);
    work->unk_14 = -0x800;
    work->unk_1C = 0xA000;
    work->unk_24 = -0x8000;
}

void task_allmap_bar_0(AllmapBarWork* work) {
    gStockMesDispWork = work;
#ifdef VERSION_EU
    work->unk_00 = LoadObjTiles(gUnk_0976D8A6, 0xDC0);
#else
    work->unk_00 = LoadObjTiles(gUnk_0976D8A6, 0x2C0);
#endif
    work->unk_04 = LoadObjTiles(gUnk_0976DBDA, 0xC0);
    work->palette = LoadObjPalette(gUnk_0984A1D8, 32);
    work->unk_0C = 16;
    work->unk_28 = 0;
    work->unk_10 = -0x800;
    work->unk_18 = 0xA000;
    work->unk_20 = -0x8000;
    work->unk_14 = 0;
    work->unk_1C = 0x9800;
    work->unk_24 = 0;
    work->unk_2C = 0;
    work->unk_2D = 0;
}

void func_080D3FD4(AllmapBarWork* work) {
    func_08006184(0, 16);
    func_080063A8();
}

#ifndef VERSION_EU
s32 task_allmap_bar_1(AllmapBarWork* work) {
    s32 i;

    switch (work->unk_28) {
    case 0:
        ApproachValue(&work->unk_10, work->unk_14, work->unk_0C);
        ApproachValue(&work->unk_18, work->unk_1C, work->unk_0C);
        work->unk_0C--;
        if (work->unk_0C == 0) {
            work->unk_0C = 16;
            work->unk_28 = 1;
        }
        break;
    case 1:
        ApproachValue(&work->unk_20, work->unk_24, work->unk_0C);
        work->unk_0C--;
        if (work->unk_0C == 0) {
            LoadBgMap(3, gUnk_0983B298, 0x500);
            work->unk_28 = 2;
            gUnk_0203C4E0 = 2;
        }
        break;
    case 3:
        ApproachValue(&work->unk_20, work->unk_24, work->unk_0C);
        work->unk_0C--;
        if (work->unk_0C == 0) {
            work->unk_0C = 16;
            work->unk_28 = 4;
        }
        break;
    case 4:
        if (func_08006314() == 0 && work->unk_2D == 0) {
            for (i = 0; i < 32; i++) {
                func_080062F4(i, 0);
            }
            func_080D3FD4(work);
            work->unk_2D = 1;
        }
        ApproachValue(&work->unk_10, work->unk_14, work->unk_0C);
        ApproachValue(&work->unk_18, work->unk_1C, work->unk_0C);
        work->unk_0C--;
        if (work->unk_0C == 0) {
            gUnk_0203C4E0 = 0;
            return 0;
        }
        break;
    case 2:
        if (work->unk_2C != 0) {
            break;
        }

        if (gUnk_0203C4E0 != 3) {
            break;
        }

        if ((GetKeysPressed() & 8) != 0) {
            m4aSongNumStart(104);
            func_080D3FD4(work);
            gUnk_0203C4E0 = 0;
            func_080D3ED0();
            func_080D352C(0);
            return 0;
        }

        if ((GetKeysPressed() & 2) != 0 && func_080D4D1C() == 0) {
            m4aSongNumStart(104);
            func_080D3F10(work);
            gUnk_0203C4E0 = 1;
            func_080D3ED0();
            func_080D352C(1);
        }
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("allmap/task_allmap_bar_1.s");
#endif

#ifndef VERSION_EU
void task_allmap_bar_2(AllmapBarWork* work) {
    if (work->unk_28 == 2) {
        return;
    }
    DrawSprite(work->unk_20 >> 8, 0, gUnk_0976D880, work->unk_00, work->palette, 0, 0xC00, 1000);
    DrawSprite(128, work->unk_10 >> 8, gUnk_0976DB68, work->unk_04, work->palette, 0, 0xC00, 1001);
    DrawSprite(128, work->unk_18 >> 8, gUnk_0976DB9C, work->unk_04, work->palette, 0, 0xC00, 1002);
}
#else
INCLUDE_ASM("allmap/task_allmap_bar_2.s");
#endif

void task_allmap_bar_3(AllmapBarWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->palette);
}

u8 func_080D422C(AllmapCursorPos a) {
    AllmapCursorPos p;
    s32 i;
    u8 r;
    u8 v;

    for (i = 0; i < 4; i++) {
        p.unk_00 = a.unk_00 + gUnk_096FDC30[i][0];
        p.unk_02 = a.unk_02 + gUnk_096FDC30[i][1];
        r = func_080D5494(p);
        if (r != 255) {
            if (func_080DF51C(func_080D5494(a)) == 2) {
                v = func_080D3AB8(r, gUnk_096FDC40[i][0]);
            } else {
                v = func_080D3A70(r, gUnk_096FDC40[i][0]);
            }

            if (v != 0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_080D42D4(AllmapDoorinfoWork* work) {
    s32 i;
    AllmapCursorPos pos;
    u8 room;
    u8 n;

    work->unk_114 = 0;

    for (i = 0; i < 4; i++) {
        pos.unk_00 = work->unk_000.unk_00 + gUnk_096FDC30[i][0];
        pos.unk_02 = work->unk_000.unk_02 + gUnk_096FDC30[i][1];
        room = func_080D5494(pos);

        if (room != 0xFF && func_080D3A70(room, gUnk_096FDC40[i][0])) {
            n = func_080DF548(room) + 1;

            if (n == 10) {
                n = 0;
            }

            work->unk_01C[i].unk_00 = func_080986FC(n);
            work->unk_01C[i].unk_0C = LoadObjPalette(gUnk_09618D38, 32);
            work->unk_01C[i].unk_18 = 0;
            work->unk_01C[i].unk_04 = LoadObjTiles(gUnk_0905E3BA, 0x600);
            work->unk_01C[i].unk_10 = LoadObjPalette(gUnk_09618D38, 32);
            work->unk_01C[i].unk_1C = gUnk_09EE97F4[0];
            func_080062F4(work->unk_01C[i].unk_0C->unk_06 + 16, 1);
            func_080062F4(work->unk_01C[i].unk_10->unk_06 + 16, 1);
            work->unk_008[i] = gUnk_09EF64E8[i];
            work->unk_114++;
        } else {
            work->unk_008[i] = 0;
        }
    }

    if (work->unk_114 != 0) {
        work->unk_018 = LoadObjTiles(gUnk_0976DD62, 0x80);
        work->palette = LoadObjPalette(gUnk_0984A1D8, 32);
        func_080062F4(((AllmapPal*)work->palette)->unk_06 + 16, 1);
        work->unk_0F0 = LoadObjTiles(gUnk_0976B340, 0x2400);
        work->unk_0F8 = gUnk_09EF6424[0];
        func_0800388C(work->unk_0F4, 15, gUnk_0984A0F8, 32);
        func_080062F4(((AllmapPal*)work->unk_0F4)->unk_06 + 16, 1);
    }
}

s32 func_080D44A0(u16 a, s32 b) {
    s16 tbl[4][4];

    memcpy(tbl, gUnk_096FDC50, sizeof(tbl));
    return tbl[a - 1][b] << 8;
}

void func_080D44D4(AllmapDoorinfoWork* work) {
    s32 i;
    AllmapCursorPos pos;
    u8 room;
    AllmapDoorEntry* e;

    for (i = 0; i < 4; i++) {
        pos.unk_00 = work->unk_000.unk_00 + gUnk_096FDC30[i][0];
        pos.unk_02 = work->unk_000.unk_02 + gUnk_096FDC30[i][1];
        room = func_080D5494(pos);

        if (room != 0xFF && func_080D3AB8(room, gUnk_096FDC40[i][0])) {
            break;
        }
    }

    if (i == 4) {
        work->unk_114 = 0;
    } else {
        func_080E8C84(work->unk_004, gUnk_096FDC40[i][0]);
        work->unk_114 = func_080E8D00();
    }

    for (i = 0; i < work->unk_114; i++) {
        e = &work->unk_01C[i];
        func_08098014(e, func_080E8D1C(i));
        func_08098598(func_080D44A0(work->unk_114, i), 0x6800, e);

        if (work->unk_01C[i].unk_0C != 0) {
            func_080062F4(work->unk_01C[i].unk_0C->unk_06 + 16, 1);
        }

        if (work->unk_01C[i].unk_10 != 0) {
            func_080062F4(work->unk_01C[i].unk_10->unk_06 + 16, 1);
        }

        if (work->unk_01C[i].unk_14 != 0) {
            func_080062F4(work->unk_01C[i].unk_14->unk_06 + 16, 1);
        }
    }

    work->unk_0F0 = LoadObjTiles(gUnk_0976B340, 0x2400);

    if (func_080DF51C(work->unk_004) == 1 || func_080DF51C(work->unk_004) == 4) {
        work->unk_0F8 = gUnk_09EF6424[1];
        func_0800388C(work->unk_0F4, 15, gUnk_0984A118, 32);
    } else {
        work->unk_0F8 = gUnk_09EF6424[0];
        func_0800388C(work->unk_0F4, 15, gUnk_0984A0F8, 32);
    }

    func_080062F4(((AllmapPal*)work->unk_0F4)->unk_06 + 16, 1);
}

void task_allmap_doorinfo_0(AllmapDoorinfoWork* work, AllmapCursorPos* arg) {
    s32 i;

    for (i = 0; i < 32; i++) {
        func_080062F4(i, 0);
    }
    work->unk_0F4 = EwramAlloc(40);
    work->unk_000 = *arg;
    work->unk_004 = func_080D5494(*arg);
    work->unk_0FC = work->unk_000.unk_00 * 24 - gUnk_0203C540;
    work->unk_0FE = work->unk_000.unk_02 * 24 - gUnk_0203C53C;
    work->unk_10C = 0x6800;

    if (func_080DF51C(work->unk_004) == 1 || func_080DF51C(work->unk_004) == 4 || func_080DF51C(work->unk_004) == 2) {
        work->unk_110 = 0x2100;
        func_080D44D4(work);
    } else {
        work->unk_110 = 0x4200;
        func_080D42D4(work);
    }
    work->unk_100 = 8;
    work->unk_104 = work->unk_0FC << 8;
    work->unk_108 = work->unk_0FE << 8;
    work->unk_116 = 0;
    func_08006238(0, 14, 8);
}

s32 task_allmap_doorinfo_1(AllmapDoorinfoWork* work) {
    if ((GetKeysPressed() & 2) != 0 && work->unk_116 == 0) {
        work->unk_116 = 1;
        m4aSongNumStart(104);
        work->unk_100 = 8 - work->unk_100;
        work->unk_10C = work->unk_0FC << 8;
        work->unk_110 = work->unk_0FE << 8;
        func_080061E8(0, 8);
    }

    if (work->unk_100 != 0) {
        ApproachValue(&work->unk_104, work->unk_10C, work->unk_100);
        ApproachValue(&work->unk_108, work->unk_110, work->unk_100);
        work->unk_100--;
    }

    if (work->unk_116 != 0 && work->unk_100 == 0) {
        return 0;
    }
    return 1;
}

void func_080D484C(AllmapDoorinfoWork* work) {
    s32 i;

    if (gUnk_0203C4E0 == 0) {
        return;
    }

    for (i = 0; i < 4; i++) {
        if (work->unk_008[i] != 0 && work->unk_100 == 0) {
            DrawSprite(work->unk_104 >> 8, work->unk_108 >> 8, work->unk_008[i], work->unk_018, work->palette, 0, 0, i + 51);
            gUnk_02034E84 = gUnk_096FDC10[i][0];
            gUnk_02034E88 = gUnk_096FDC10[i][1];
            DrawSprite(gUnk_02034E84 + (work->unk_104 >> 8), gUnk_02034E88 + (work->unk_108 >> 8), work->unk_01C[i].unk_18, work->unk_01C[i].unk_00, work->unk_01C[i].unk_0C, 0, 0, i + 40);
            DrawSprite((work->unk_104 >> 8) + gUnk_02034E84, (work->unk_108 >> 8) + gUnk_02034E88, work->unk_01C[i].unk_1C, work->unk_01C[i].unk_04, work->unk_01C[i].unk_10, 0, 0, i + 30);
        }
    }
    DrawSprite(work->unk_104 >> 8, work->unk_108 >> 8, work->unk_0F8, work->unk_0F0, work->unk_0F4, 0, 0, 20);
}

void func_080D49EC(AllmapDoorinfoWork* work) {
    s32 i;

    if (work->unk_100 == 0) {
        for (i = 0; i < work->unk_114; i++) {
            func_08098670(&work->unk_01C[i], 0);
        }
    }
    DrawSprite(work->unk_104 >> 8, work->unk_108 >> 8, work->unk_0F8, work->unk_0F0, work->unk_0F4, 0, 0, 20);
}

void task_allmap_doorinfo_2(AllmapDoorinfoWork* work) {
    if (func_080DF51C(work->unk_004) == 1 || func_080DF51C(work->unk_004) == 4 || func_080DF51C(work->unk_004) == 2) {
        func_080D49EC(work);
    } else {
        func_080D484C(work);
    }
}

void task_allmap_doorinfo_3(AllmapDoorinfoWork* work) {
    s32 i;

    if (work->unk_116 == 0) {
        func_080061E8(0, 8);
    }
    ReleaseObjTiles(work->unk_0F0);

    if (func_080DF51C(work->unk_004) == 1 || func_080DF51C(work->unk_004) == 4 || func_080DF51C(work->unk_004) == 2) {
        for (i = 0; i < work->unk_114; i++) {
            func_08098778(&work->unk_01C[i]);
        }
    } else {
        ReleaseObjTiles(work->unk_018);
        ReleaseObjPalette(work->palette);

        for (i = 0; i < 4; i++) {
            if (work->unk_008[i] != 0) {
                ReleaseObjTiles(work->unk_01C[i].unk_00);
                ReleaseObjPalette(work->unk_01C[i].unk_0C);
                ReleaseObjTiles(work->unk_01C[i].unk_04);
                ReleaseObjPalette(work->unk_01C[i].unk_10);
            }
        }
    }

    for (i = 0; i < 32; i++) {
        func_080062F4(i, 1);
    }
    func_080062F4(10, 0);
    EwramFree(work->unk_0F4);
}

void task_allmap_pusha_0(AllmapPushaWork* work, AllmapCursorWork* arg) {
    gStockMesDispWork = work;
    work->unk_0C = arg;
    work->unk_2C = arg->unk_30.unk_00 * 24 - gUnk_0203C540;
    work->unk_2E = arg->unk_30.unk_02 * 24 - gUnk_0203C53C;
    work->tiles = LoadObjTiles(gUnk_0976DCB0, 0x80);
    work->palette = LoadObjPalette(gUnk_0984A1D8, 32);
    work->unk_08 = gUnk_0976DC9C;
    work->unk_10 = 0;
    TaskPoolInit(&work->unk_14, 1);
    work->unk_28 = 0;
}

s32 task_allmap_pusha_1(AllmapPushaWork* work) {
    if (func_080D4D1C() == 0 && (GetKeysPressed() & 1) != 0) {
        m4aSongNumStart(102);
        work->unk_28 = TaskCreate(&work->unk_14, &gTaskDescAllmapDoorinfo, &work->unk_0C->unk_30);
    }
    work->unk_12 = gSineTable[(u8)work->unk_10] >> 8;
    work->unk_10 += 16;
    TaskPoolUpdate(&work->unk_14);
    return 1;
}

void task_allmap_pusha_2(AllmapPushaWork* work) {
    if (func_080D4D1C() != 0) {
        TaskPoolDraw(&work->unk_14);
    } else {
        work->unk_2C = work->unk_0C->unk_30.unk_00 * 24 - gUnk_0203C540;
        work->unk_2E = work->unk_0C->unk_30.unk_02 * 24 - gUnk_0203C53C;
        DrawSprite(work->unk_2C, work->unk_2E - work->unk_12 + 2, work->unk_08, work->tiles, work->palette, 0, 0, 48);
    }
}

void task_allmap_pusha_3(AllmapPushaWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_14);
    func_080D4D44();
}

u8 func_080D4D1C(void) {
    if (gStockMesDispWork == 0 || IsTaskActive(((AllmapPushaWork*)gStockMesDispWork)->unk_28) == 0) {
        return 0;
    }
    return 1;
}

void func_080D4D44(void) {
    gStockMesDispWork = 0;
}

void func_080D4D50(s16 a, s16 b, s32 c, u8 d) {
    AllmapCursorPos p;
    u16* map;
    s16 x8;
    s16 y8;
    s32 i;
    s32 j;
    u8 room;
    u16 tile;
    s16 ofs;

    if ((a & 1) != 0) {
        map = gUnk_0203C530;
    } else {
        map = gUnk_0203C504;
    }
    x8 = (a * 24 - gUnk_0203C4B4->unk_AC) / 8;
    y8 = (b * 24 - gUnk_0203C4B4->unk_AE) / 8;
    p.unk_00 = a;
    p.unk_02 = b;
    room = func_080D5494(p);
    tile = c * 16;

    if (func_080D5944(room, 8) != 0 || func_080D5944(room, 2) != 0 || func_080D422C(p) != 0) {
        if (d != 0) {
            tile += 0x2000;
        } else if (c == 1) {
            tile += 0x1000;
        } else if (c == 17) {
            tile += 0xF000;
        }
    } else if (c == 1 || c == 17) {
        tile += 0xF000;
    } else {
        tile += 0xE000;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ofs = (y8 + i) / 32 * 2048 + (y8 + i) % 32 * 32 + (x8 + j) / 32 * 1024 + (x8 + j) % 32;
            map[ofs] = tile;
            tile++;
        }
    }
}
void func_080D4EBC(void) {
    s32 i;
    s32 j;
    AllmapCursorPos arg;
    AllmapRoomWork* w;
    AllmapRoomWork* c;

    gUnk_0203C4B4 = EwramAlloc(0xC4);
    gUnk_0203C4B4->unk_C0 = 0xFF;
    gUnk_0203C4B4->unk_BC = 0x400;
    gUnk_0203C538 = gUnk_0203C590[6];
    TaskPoolInit(&gUnk_0203C4B4->unk_00, 35);
    gUnk_0203C4B4->unk_9C = i = 0;
    gUnk_0203C4B4->unk_98 = 0;

    for (; i < 32; i++) {
        gUnk_0203C4B4->unk_14[i] = 0;
    }

    gUnk_0203C4B4->unk_B4 = gUnk_0203C4B4->unk_B6 = 32;
    gUnk_0203C4B4->unk_B8 = gUnk_0203C4B4->unk_BA = 32;
    func_080D576C(0, 32, 32);
    gUnk_0203C4B4->unk_A0 = 0;
    gUnk_0203C4B4->unk_A2 = 0;
    func_080D58AC(gUnk_0203C4B4->unk_B4, gUnk_0203C4B4->unk_B6, gUnk_0203C4B4->unk_B8, gUnk_0203C4B4->unk_BA);
    gUnk_0203C4B4->unk_A4 = (gUnk_0203C4B4->unk_A2 + 160) << 8;
    gUnk_0203C4B4->unk_A8 = gUnk_0203C4B4->unk_A2 << 8;
    gUnk_0203C540 = gUnk_0203C4B4->unk_AC + gUnk_0203C4B4->unk_A0;
    gUnk_0203C53C = gUnk_0203C4B4->unk_AE + gUnk_0203C4B4->unk_A2;
    gUnk_02034E8C = (gUnk_0203C4B4->unk_AC + gUnk_0203C4B4->unk_A0) << 8;
    gUnk_02034E90 = (gUnk_0203C4B4->unk_AE + gUnk_0203C4B4->unk_A2) << 8;

    for (j = 0; j < 32; j++) {
        if (IsTaskActive(gUnk_0203C4B4->unk_14[j])) {
            w = gUnk_0203C4B4->unk_14[j]->work;
            func_080D4D50(w->unk_08C, w->unk_08E, w->unk_09A, j == gUnk_0203C538);
        }
    }

    func_080051C4(0, gUnk_0203C4B4->unk_A0 - gUnk_0203C4B4->unk_AC % 8, gUnk_0203C4B4->unk_A2 - gUnk_0203C4B4->unk_AE % 8);
    func_080051C4(1, gUnk_0203C4B4->unk_A0 - gUnk_0203C4B4->unk_AC % 8, gUnk_0203C4B4->unk_A2 - gUnk_0203C4B4->unk_AE % 8);
    c = gUnk_0203C4B4->unk_14[gUnk_0203C538]->work;
    arg.unk_00 = c->unk_08C;
    arg.unk_02 = c->unk_08E;
    gUnk_0203C4B4->unk_94 = TaskCreate(gUnk_0203C4B4, &gTaskDescAllmapCursor, &arg);
    func_080D53F8();
}
#ifdef NON_MATCHING
void func_080D510C(UnkStruct_0203C4B4* s) {
    s32 tx;
    s32 ty;
    s32 dx;
    s32 dy;
    s32 px;
    s32 py;

    tx = (s->unk_AC + s->unk_A0) << 8;
    ty = (s->unk_AE + s->unk_A2) << 8;
    dx = (tx - gUnk_02034E8C) >> 3;
    dy = (ty - gUnk_02034E90) >> 3;

    if (dx > 0x800) {
        dx = 0x800;
    } else if (dx < -0x800) {
        dx = -0x800;
    }

    if (dy > 0x800) {
        dy = 0x800;
    } else if (dy < -0x800) {
        dy = -0x800;
    }
    px = gUnk_02034E8C;
    py = gUnk_02034E90;
    gUnk_02034E8C += dx;
    gUnk_02034E90 += dy;

    if (abs(px - gUnk_02034E8C) <= 7) {
        gUnk_02034E8C = tx;
    }

    if (abs(py - gUnk_02034E90) <= 7) {
        gUnk_02034E90 = ty;
    }
    gUnk_0203C540 = gUnk_02034E8C >> 8;
    gUnk_0203C53C = gUnk_02034E90 >> 8;
}
#else
INCLUDE_ASM("allmap/func_080D510C.s");
#endif
void func_080D51D8(void) {
    s16 x;
    s16 y;

    if (func_08006314() == 0 && gUnk_0203C4E0 == 3) {
        func_080D55E4();
    }

    if (gUnk_0203C4E0 == 2) {
        if (gUnk_0203C534 > 6) {
            ApproachValue(&gUnk_0203C4B4->unk_A4, gUnk_0203C4B4->unk_A8 - 0x200, gUnk_0203C534 - 7);
        } else if (gUnk_0203C534 & 1) {
            ApproachValue(&gUnk_0203C4B4->unk_A4, gUnk_0203C4B4->unk_A8, 1);
        } else {
            ApproachValue(&gUnk_0203C4B4->unk_A4, gUnk_0203C4B4->unk_A8 - 0x200, 1);
        }

        gUnk_0203C4B4->unk_A2 = gUnk_0203C4B4->unk_A4 >> 8;
    }

    if (gUnk_0203C4E0 == 3) {
        func_080D510C(gUnk_0203C4B4);
    } else {
        gUnk_0203C540 = gUnk_0203C4B4->unk_AC + gUnk_0203C4B4->unk_A0;
        gUnk_0203C53C = gUnk_0203C4B4->unk_AE + gUnk_0203C4B4->unk_A2;
        gUnk_02034E8C = (gUnk_0203C4B4->unk_AC + gUnk_0203C4B4->unk_A0) << 8;
        gUnk_02034E90 = (gUnk_0203C4B4->unk_AE + gUnk_0203C4B4->unk_A2) << 8;
    }

    x = gUnk_0203C540 - gUnk_0203C4B4->unk_AC;
    y = gUnk_0203C53C - gUnk_0203C4B4->unk_AE;
    func_08005244(0, x - gUnk_0203C4B4->unk_AC % 8, y - gUnk_0203C4B4->unk_AE % 8);
    func_08005244(1, x - gUnk_0203C4B4->unk_AC % 8, y - gUnk_0203C4B4->unk_AE % 8);
    TaskPoolUpdate(&gUnk_0203C4B4->unk_00);
    TaskPoolDraw(&gUnk_0203C4B4->unk_00);
}

void func_080D53A8(void) {
    TaskPoolDestroy(&gUnk_0203C4B4->unk_00);
    EwramFree(gUnk_0203C4B4);
}

u16 func_080D53C4(void) {
    if ((GetKeysHeld() & R_BUTTON) != 0) {
        return gUnk_0203C4B4->unk_BC >> 7;
    }
    return gUnk_0203C4B4->unk_BC >> 8;
}

void func_080D53F8(void) {
    AllmapRoomWork* w;
    AllmapCursorWork* c;
    s32 base;
    u8 i;

    base = (gUnk_0203C4B4->unk_BA * 24 - gUnk_0203C53C) << 9;

    for (i = 0; i < 32; i++) {
        if (IsTaskActive(gUnk_0203C4B4->unk_14[i]) != 0) {
            w = gUnk_0203C4B4->unk_14[i]->work;
            w->unk_094 = (w->unk_08E * 24 - gUnk_0203C53C) << 8;
            w->unk_090 = w->unk_094 - base;
        }
    }

    if (IsTaskActive(gUnk_0203C4B4->unk_94) != 0) {
        c = gUnk_0203C4B4->unk_94->work;
        c->unk_28 = c->unk_2C - base;
    }
}

s32 func_080D5494(AllmapCursorPos a) {
    AllmapRoomWork* w;
    u8 i;

    for (i = 0; i < 32; i++) {
        if (IsTaskActive(gUnk_0203C4B4->unk_14[i]) != 0) {
            w = gUnk_0203C4B4->unk_14[i]->work;
            if (a.unk_00 == w->unk_08C && a.unk_02 == w->unk_08E) {
                return i;
            }
        }
    }
    return 255;
}

void func_080D54FC(void) {
    AllmapRoomWork* w;

    w = gUnk_0203C4B4->unk_14[gUnk_0203C538]->work;
    gUnk_0203C4B4->unk_A2 = w->unk_08E * 24 - gUnk_0203C4B4->unk_AE - 69;
    if (gUnk_0203C4B4->unk_A2 < 0 || gUnk_0203C4B4->unk_B2 <= 159) {
        gUnk_0203C4B4->unk_A2 = 0;
    } else if (gUnk_0203C4B4->unk_A2 > gUnk_0203C4B4->unk_B2 - 160) {
        gUnk_0203C4B4->unk_A2 = gUnk_0203C4B4->unk_B2 - 160;
    }

    if ((s16)(w->unk_08E * 24 - gUnk_0203C4B4->unk_AE) <= 15) {
        gUnk_0203C4B4->unk_A2 -= 16;
    }
    gUnk_0203C4B4->unk_A0 = w->unk_08C * 24 - gUnk_0203C4B4->unk_AC - 104;
    if (gUnk_0203C4B4->unk_A0 < 0 || gUnk_0203C4B4->unk_B0 <= 239) {
        gUnk_0203C4B4->unk_A0 = 0;
    } else if (gUnk_0203C4B4->unk_A0 > gUnk_0203C4B4->unk_B0 - 240) {
        gUnk_0203C4B4->unk_A0 = gUnk_0203C4B4->unk_B0 - 240;
    }
}

void func_080D55E4(void) {
    AllmapCursorWork* c;
    AllmapCursorPos p;
    u8* d;
    u8 moved;
    u8 r;

    moved = 0;
    c = gUnk_0203C4B4->unk_94->work;
    p = c->unk_30;

    switch (GetKeysRepeat()) {
    case 64:
        p.unk_00++;
        p.unk_02--;
        moved = 1;
        break;
    case 16:
        p.unk_00++;
        p.unk_02++;
        moved = 1;
        break;
    case 32:
        p.unk_00--;
        p.unk_02--;
        moved = 1;
        break;
    case 128:
        p.unk_00--;
        p.unk_02++;
        moved = 1;
        break;
    }
    r = func_080D5494(p);
    if (r == 255) {
        return;
    }
    c->unk_30 = p;

    if (gUnk_0203C4B4->unk_C0 == r) {
        return;
    }
    gUnk_0203C4B4->unk_C0 = r;
    gUnk_0203C538 = r;

    if (moved != 0) {
        m4aSongNumStart(101);
        func_080D54FC();
    }

    if (IsTaskActive(gUnk_0203C4B4->unk_98) != 0) {
        func_08000DE8(gUnk_0203C4B4, gUnk_0203C4B4->unk_98);
    }
    d = func_080DEE18(r);
    if (d[8] != 26 && (func_080D5944(r, 2) != 0 || func_080D5944(r, 8) != 0)) {
        gUnk_0203C4B4->unk_98 = TaskCreate(gUnk_0203C4B4, &gTaskDescAllmapRoomname, d + 8);
    } else {
        gUnk_0203C4B4->unk_98 = 0;
        func_080D3ED0();
    }

    if (IsTaskActive(gUnk_0203C4B4->unk_9C) != 0) {
        func_08000DE8(gUnk_0203C4B4, gUnk_0203C4B4->unk_9C);
    }

    if (func_080D422C(c->unk_30) != 0) {
        gUnk_0203C4B4->unk_9C = TaskCreate(gUnk_0203C4B4, &gTaskDescAllmapPusha, c);
    }
}

#ifdef NON_MATCHING
void func_080D576C(u8 a, u16 b, u16 c) {
    AllmapRoomArg arg;
    u8* d;

    d = func_080DED98(a);

    if (IsTaskActive(gUnk_0203C4B4->unk_14[a]) != 0) {
        return;
    }

    if (gUnk_0203C4B4->unk_B6 < b) {
        gUnk_0203C4B4->unk_B6 = b;
    }

    if (gUnk_0203C4B4->unk_B4 > b) {
        gUnk_0203C4B4->unk_B4 = b;
    }

    if (gUnk_0203C4B4->unk_BA < c) {
        gUnk_0203C4B4->unk_BA = c;
    }

    if (gUnk_0203C4B4->unk_B8 > c) {
        gUnk_0203C4B4->unk_B8 = c;
    }
    arg.unk_00 = b;
    arg.unk_02 = c;
    arg.unk_04 = a;
    arg.unk_06 = 0;
    gUnk_0203C4B4->unk_14[a] = TaskCreate(gUnk_0203C4B4, &gTaskDescAllmapRoom, &arg);

    if ((u8)(d[0] + 3) > 2) {
        func_080D576C(d[0], b + 1, c - 1);
    }

    if ((u8)(d[1] + 3) > 2) {
        func_080D576C(d[1], b - 1, c + 1);
    }

    if ((u8)(d[2] + 3) > 2) {
        func_080D576C(d[2], b + 1, c + 1);
    }

    if ((u8)(d[3] + 3) > 2) {
        func_080D576C(d[3], b - 1, c - 1);
    }
}
#else
INCLUDE_ASM("allmap/func_080D576C.s");
#endif

void func_080D58AC(u16 a, u16 b, u16 c, u16 d) {
    u16 dx;
    u16 dy;

    gUnk_0203C4B4->unk_B2 = (d - c) * 24 + 32;
    if (gUnk_0203C4B4->unk_B2 <= 159) {
        dy = (160 - gUnk_0203C4B4->unk_B2) / 2;
    } else {
        dy = 0;
    }
    gUnk_0203C4B4->unk_B0 = (b - a) * 24 + 32;
    if (gUnk_0203C4B4->unk_B0 <= 239) {
        dx = (240 - gUnk_0203C4B4->unk_B0) / 2;
    } else {
        dx = 0;
    }
    gUnk_0203C4B4->unk_AC = a * 24 - dx;
    gUnk_0203C4B4->unk_AE = c * 24 - dy;
    func_080D54FC();
}

u8 func_080D5944(u8 a, u16 b) {
    return *func_080DEE18(a) & b;
}

void* func_080D5960(u8 a) {
    return gUnk_0203C4B4->unk_14[a]->work;
}

void func_080D5978(u16 a, void* b, u16 c) {
    RequestDma3Copy(b, gUnk_02034EC4 + a * 32, c);
}

void func_080D5998(void) {
    LoadPalette(gUnk_02034EC4, (void*)0x05000000, 0x400);
}

void func_080D59B4(void) {
    if (gUnk_02034ECA != 0) {
        ModeRequest(&gModeTitle, 0);
        return;
    }

    switch (gUnk_02034EC2) {
    case 3:
        SaveLoadSystem();
        SaveClearSystem();
        func_080E04EC();
        return;
    case 1:
        ModeRequest(&gModeMenuLoad, 0);
        return;
    case 2:
        func_080AEB94();
        ModeRequest(&gModeSioBattle, 0);
        return;
    case 4:
        func_0801CD20();
        ModeRequest(&gModeMenuNew, 0);
        return;
    case 5:
        func_0801CCB4();
        ModeRequest(&gModeMenuNew, 0);
        return;
    case 0:
    default:
        ModeRequest(&gModeMenuNew, 0);
        return;
    }
}

void func_080D5A4C(u16 a) {
    if ((gGameState.flags & 0x200) != 0) {
        LoadBgPalette(1, gUnk_0984A818, 0x200);
        func_080D5978(0, gUnk_0984A818, 0x200);
    } else {
        LoadBgPalette(1, gUnk_0984A418, 0x200);
        func_080D5978(0, gUnk_0984A418, 0x200);
    }
    EnableBg(0);
    DisableBg(1);
    DisableBg(2);

    if (IsTaskActive(gTitleLogoTask) == 0) {
        gTitleLogoTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleLogo, 0);
    }

    if (IsTaskActive(gTitleObjTask) == 0) {
        gTitleObjTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleObj, 0);
    }
    func_08006120(2, a);
}

#ifndef VERSION_EU
void func_080D5B04(void) {
    LoadBgMap(0, gUnk_0983F398, 0x800);
    SetBgBlend(0, 5, 16);
    EnableBg(1);
    m4aSongNumStart(6);
}
#else
INCLUDE_ASM("allmap/func_080D5B04.s");
#endif

void func_080D5B30(void) {
    m4aMPlayFadeOut(gMPlayTable[gSongTable[6].ms].info, 5);
    func_08006184(0, 90);
    func_080C75A4(0, 90);
    gUnk_02034E98 = 9;
}
