#include "macros.h"
#include "room.h"

void task_room_name_0(RoomNameWork* work, s32 arg) {
    work->unk_00 = LoadObjTiles(gUnk_0993AF64, 0x800);
    work->unk_04 = LoadObjPalette(gUnk_099910C4, 0x20);
    work->unk_08 = gUnk_09EF8DA4;
    work->unk_30 = arg;
    work->unk_0C = 0x5C00;
    work->unk_10 = 0x8A00;
    work->unk_14 = 0x7800;
    work->unk_18 = 0x8A00;
    work->unk_20 = 0x400;
    work->unk_24 = 0x19;
    work->unk_2A = 0;
    work->unk_2C = 0;
    work->unk_28 = 0;
    work->unk_1C = 0x19;
    func_08065ACC(work->unk_3C, 0x24);
    work->unk_38 = _08066468(1);
    work->unk_34 = func_08065B6C(gUnk_09EF7048[work->unk_30], work->unk_3C);
}

u8 task_room_name_1(RoomNameWork* work) {
    if (gUnk_02039BA0->unk_70 & 0x42000) {
        return 0;
    }

    switch (work->unk_28) {
    case 0:
        work->unk_2A++;
        if (work->unk_2A > 0x27) {
            work->unk_2A = 0;
            work->unk_28++;
        }
        break;
    case 1:
        work->unk_2A++;
        if (work->unk_2A > 1) {
            work->unk_2A = 0;
            work->unk_10 -= 0x99;
            work->unk_1C += 0x19;
            if (work->unk_1C > 0xFF) {
                work->unk_1C = 0x100;
                work->unk_28++;
            }
        }
        break;
    case 2:
        work->unk_2A++;
        if (work->unk_2A > 0xB3) {
            work->unk_2A = 0;
            work->unk_28++;
        }
        break;
    case 3:
        work->unk_2A++;
        if (work->unk_2A > 1) {
            work->unk_2A = 0;
            work->unk_10 += 0x99;
            work->unk_1C -= 0x19;
            if (work->unk_1C <= 0x19) {
                work->unk_1C = 0x19;
                return 0;
            }
        }
        break;
    }
    return 1;
}

void task_room_name_2(RoomNameWork* work) {
    s32 affine;

    if (work->unk_28 != 0) {
        affine = AllocObjAffine(0, 0x100, work->unk_1C, 0);
        DrawSprite(work->unk_14 >> 8, work->unk_18 >> 8, work->unk_08, work->unk_00, work->unk_04, affine, 0, 0x3C);
        func_080664D8(work->unk_0C >> 8, work->unk_10 >> 8, work->unk_3C, work->unk_38, 0x32, work->unk_34);
    }
}

void task_room_name_3(RoomNameWork* work) {
    ReleaseObjTiles(work->unk_00);
    func_08065AE0(work->unk_3C, 0x24);
    ReleaseObjPalette(work->unk_04);
    ReleaseObjPalette(work->unk_38);
}

u16 func_080F7DD8(s32 a) {
    u16 i;

    if (a == 0x100) {
        return 0x20;
    }
    i = 0;

    if (a >= gUnk_0999204C[0]) {
        do {
            i++;
            if (i > 0x3F) {
                break;
            }
        } while (a >= gUnk_0999204C[i]);
    }
    return i;
}

s32 func_080F7E0C(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    s32 tmp;
    s32 q;
    u16 t;

    dx = x1 - x0;
    dy = y1 - y0;

    if (dx >= 0) {
        q = 0;

        if (dy < 0) {
            q = 3;
            tmp = dx;
            dx = -dy;
            dy = tmp;
        }
    } else if (dy >= 0) {
        q = 1;
        tmp = dx;
        dx = dy;
        dy = -tmp;
    } else {
        q = 2;
        dx = -dx;
        dy = -dy;
    }

    if (dy > dx) {
        if (dy == 0) {
            return 0;
        }
        dx <<= 8;
        t = 0x40 - func_080F7DD8(dx / dy);
    } else {
        if (dx == 0) {
            return 0;
        }
        dy <<= 8;
        t = func_080F7DD8(dy / dx);
    }
    return (t + (q << 6) + 0x40) & 0xFF;
}

void func_080F7E84(RoomEntry* e) {
    e->unk_120 += 0x4C;
    e->unk_00C += e->unk_120;
    if (e->unk_00C > 0) {
        if (e->unk_120 > 0x500) {
            m4aSongNumStart(0x26A);
        }
        e->unk_00C = 0;
        e->unk_120 = -e->unk_120 / 2;
    }

    if (e->unk_164 > 0) {
        e->unk_004 += e->unk_164;
        e->unk_164 -= 0x11;
        if (e->unk_164 < 0) {
            e->unk_164 = 0;
        }
    } else if (e->unk_164 < 0) {
        e->unk_004 += e->unk_164;
        e->unk_164 += 0x11;
        if (e->unk_164 > 0) {
            e->unk_164 = 0;
        }
    }

    if (e->unk_168 > 0) {
        e->unk_008 += e->unk_168 / 2;
        e->unk_168 -= 0x11;
        if (e->unk_168 < 0) {
            e->unk_168 = 0;
        }
    } else if (e->unk_168 < 0) {
        e->unk_008 += e->unk_168 / 2;
        e->unk_168 += 0x11;
        if (e->unk_168 > 0) {
            e->unk_168 = 0;
        }
    }
    func_0801A8A4(&e->unk_004, &e->unk_008, -0x18, -0x0C);
}

void func_080F7F54(RoomWork* work, s32 state) {
    if (work->unk_004 != 11 && work->unk_000 != 11) {
        work->unk_004 = state;
        work->unk_00E |= 1;
    }
}

s32 func_080F7F70(RoomWork* work, s16 i) {
    s32 v;

    v = gUnk_09991F54[i].unk_04;

    if (work->unk_018 != 0) {
        v = -v;
    }
    return v;
}

s32 func_080F7F94(RoomWork* work, s16 i) {
    return gUnk_09991F54[i].unk_08;
}

s32 func_080F7FAC(RoomWork* work, s16 i) {
    return func_080F7F70(work, i) + gUnk_02039B84->unk_0CC;
}

s32 func_080F7FC8(RoomWork* work, s16 i) {
    return func_080F7F94(work, i) + gUnk_02039B84->unk_0D0;
}

s32 func_080F7FE4(RoomWork* work, s16 i) {
    return gUnk_09991F54[i].unk_0C + gUnk_02039B84->unk_0D4;
}

void func_080F800C(RoomWork* work, s32 i) {
    RoomEntry* e;
    s32 v;

    e = &work->entries[i];

    if (work->unk_018 == 0) {
        e->unk_034 |= 4;
    } else {
        e->unk_034 &= ~4;
    }
    e->unk_140 = func_080F7F70(work, i);
    e->unk_144 = func_080F7F94(work, i);
    e->unk_124 = func_080F7FAC(work, i);
    e->unk_128 = func_080F7FC8(work, i);
    e->unk_12C = func_080F7FE4(work, i);
    v = gUnk_09991F54[i].unk_10;

    if (work->unk_018 != 0) {
        v = -v;
    }
    e->unk_15E = v;
    e->unk_160 = gUnk_09991F54[i].unk_12;
}

void func_080F80C0(RoomWork* work) {
    s32 flip;
    u32 i;

    flip = 0;

    if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
        flip = 1;
    }

    if (work->unk_018 != flip) {
        work->unk_018 = flip;

        for (i = 0; i <= 5; i++) {
            func_080F800C(work, i);
        }
    }
}

void func_080F80FC(RoomWork* work, u32 i, s32 c) {
    RoomEntry* e;
    void* p;

    e = &work->entries[i];
    e->unk_1A0 = i;
    e->unk_13C = 0;
    e->unk_158 = GetRandom();
    e->unk_11C = 0;
    e->unk_120 = 0;
    e->unk_112 = 0;
    e->unk_15A = 0;
    e->unk_15C = 0;
    e->unk_164 = e->unk_168 = 0;
    func_080F800C(work, i);
    e->unk_130 = 0;
    e->unk_134 = 0;
    e->unk_138 = 0;
    e->unk_1A4 = 0;

    if (c != 0) {
        if (i != 1) {
            e->unk_124 -= (GetRandom() & 0x1F) << 8;
            e->unk_128 -= (GetRandom() & 0x1F) << 8;
        }
        e->unk_12C -= 0xA000;
    }
    func_0801B37C(e, gUnk_09991F44, e->unk_124, e->unk_128, e->unk_12C);
    func_0801C7FC(e, gUnk_09991F44[0], gUnk_09991F54[i].unk_00);
    e->unk_0A0 = 0x10;

    if (i == 0) {
        e->unk_034 |= 0x400;
    } else {
        e->unk_034 |= 0x1000;
    }
    e->unk_034 |= 4;

    switch (i) {
    case 4:
    case 5:
        e->unk_15A |= 1;
        break;
    }
    TaskPoolInit(&e->unk_16C, 1);
    TaskCreate(&e->unk_16C, gTaskDescBtlShadow, e);
    p = gUnk_09991F54[i].unk_1C;
    e->unk_198 = AllocObjTiles(func_08003524(p, gUnk_09991F54[i].unk_20), gUnk_09991F54[i].unk_14);
    AnimInit(&e->unk_180, gUnk_09991F54[i].unk_18, p);
    AnimStart(&e->unk_180, 0, 1);
    e->unk_19C = AnimGetGfx(&e->unk_180);

    if (i == 0) {
        work->unk_A28 = AllocObjTiles(func_08003524(gUnk_09EF9728, 4), gUnk_099999AC);
        AnimInit(&work->unk_A10, gUnk_09EF9738, gUnk_09EF9728);
        AnimStart(&work->unk_A10, 0, 1);
        work->unk_A2C = AnimGetGfx(&work->unk_A10);
    }
    func_080122AC(&e->unk_040, 8, 8, 0x10);
}

void func_080F8374(RoomEntry* e) {
    if (!(e->unk_15A & 0x10)) {
        func_08012304(&e->unk_040);
        ReleaseObjTiles(e->unk_198);
        func_0801B7D8(e);
        TaskPoolDestroy(&e->unk_16C);
        e->unk_15A |= 0x10;
    }
}

void func_080F83BC(void) {
    func_080F8374(&gUnk_02034FE8->entries[1]);
    func_080F8374(&gUnk_02034FE8->entries[0]);
}

#ifdef NON_MATCHING
void func_080F83E0(RoomWork* work, RoomEntry* e) {
    s32 f;
    s32 g;
    void* pal;
    u16 sx;
    u16 sy;
    s32 v;
    RoomEntry* q;

    if (e->unk_15A & 0x10) {
        return;
    }
    f = func_08002C28(e->unk_112, 1);
    q = e;
    g = func_0801AF1C(e->unk_008);

    if (work->unk_018 == 1) {
        g |= 1;
    }

    if (func_0801CA00(e)) {
        pal = work->unk_A34;
    } else {
        pal = work->unk_A30;
    }
    WorldToScreen(&sx, &sy, q->unk_004, q->unk_008, q->unk_00C);
    v = q->unk_008 >> 8;
    DrawSprite(e->unk_15E + sx, e->unk_160 + sy, e->unk_19C, e->unk_198, pal, f, g, 0xFFFFEFFC - (v << 2));

    if (e->unk_1A0 == 0 && work->unk_000 != 7 && work->unk_000 != 8 && work->unk_000 != 9) {
        DrawSprite(e->unk_15E + sx, e->unk_160 + sy, work->unk_A2C, work->unk_A28, pal, f, g,
                   0xFFFFEFFC - ((q->unk_008 >> 8) << 2));
    }
    TaskPoolDraw(&e->unk_16C);
}
#else
INCLUDE_ASM("room/func_080F83E0.s");
#endif

INCLUDE_ASM("room/func_080F854C.s");

u8 func_080F8958(RoomWork* work) {
    s32 d;
    s32 dx;
    s32 dy;

    if (work->unk_00E & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
    case 0:
        work->unk_010 = 15;
        break;
    case 1:
        if (gUnk_02039B84->unk_0A0 == 0) {
            break;
        }
        work->unk_010--;
        if (work->unk_010 > 0) {
            break;
        }
        dx = gUnk_02039B84->unk_07C[1] - gUnk_02039B84->unk_0CC;
        dx = (dx * dx) >> 8;
        dy = gUnk_02039B84->unk_07C[2] - gUnk_02039B84->unk_0D0;
        dy = (dy * dy) >> 8;
        d = (dx + dy) >> 8;
        if (d <= 0xE0F) {
            if (work->unk_A4C == 0) {
                if (GetRandom() % 3 != 0) {
                    func_080F7F54(work, 1);
                    func_0801BCD4(&work->entries[0]);
                } else {
                    func_080F7F54(work, 2);
                }
            } else {
                if (GetRandom() % 3 != 0) {
                    func_080F7F54(work, 2);
                } else {
                    func_080F7F54(work, 1);
                    func_0801BCD4(&work->entries[0]);
                }
            }
        } else if (d <= 0x270F) {
            if (work->unk_A4C == 0) {
                if (GetRandom() & 1) {
                    func_080F7F54(work, 1);
                    func_0801BCD4(&work->entries[0]);
                } else {
                    func_080F7F54(work, 2);
                }
            } else {
                if (GetRandom() & 1) {
                    func_080F7F54(work, 2);
                } else {
                    func_080F7F54(work, 1);
                    func_0801BCD4(&work->entries[0]);
                }
            }
        } else {
            if (work->unk_A4C == 0) {
                if (GetRandom() % 3 != 0) {
                    func_080F7F54(work, 2);
                } else {
                    func_080F7F54(work, 1);
                    func_0801BCD4(&work->entries[0]);
                }
            } else {
                if (GetRandom() % 3 != 0) {
                    func_080F7F54(work, 1);
                    func_0801BCD4(&work->entries[0]);
                } else {
                    func_080F7F54(work, 2);
                }
            }
        }
        break;
    case 2:
        break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_00E &= 0xFFFE;
    }
    return 1;
}

INCLUDE_ASM("room/func_080F8AC8.s");
INCLUDE_ASM("room/func_080F8F9C.s");

#ifdef NON_MATCHING
u8 func_080F9744(RoomWork* work) {
    RoomEntry* e;
    u32 i;
    s32 t;

    if (work->unk_00E & 1) {
        work->unk_008 = 2;
    }

    for (i = 0; i <= 5; i++) {
        e = &work->entries[i];

        switch (work->unk_008) {
        case 0:
            switch (e->unk_1A0) {
            case 0:
                work->unk_010 = 0;
                work->unk_00C = 0;
                break;
            case 2:
            case 3:
                e->unk_15A |= 1;
                break;
            }
            break;
        case 1:
            switch (work->unk_00C) {
            case 0:
                if (e->unk_1A0 == 3) {
                    t = e->unk_124;
                    e->unk_124 = work->unk_018 == 0 ? t + 0x80 : t - 0x80;
                    work->unk_010++;
                    if (work->unk_010 > 30) {
                        work->unk_010 = 0;
                        work->unk_00C = 1;
                    }
                } else {
                    func_080F800C(work, i);
                }
                break;
            case 1:
                if (e->unk_1A0 == 3) {
                    t = e->unk_124;
                    e->unk_124 = work->unk_018 == 0 ? t - 0x300 : t + 0x300;
                    e->unk_128 += 0x133;

                    if (!(e->unk_15A & 4)) {
                        if (func_08011F78(0xE3, e->unk_004, e->unk_008, e->unk_00C, 0x10, 0x10, 0x20)) {
                            m4aSongNumStart(0x25A);
                        }
                    }
                    work->unk_010++;
                    if (work->unk_010 > 15) {
                        work->unk_010 = 0;
                        work->unk_00C = 2;
                    }
                } else {
                    func_080F800C(work, i);
                }
                break;
            case 2:
                if (e->unk_1A0 == 2) {
                    t = e->unk_124;
                    e->unk_124 = work->unk_018 == 0 ? t + 0x80 : t - 0x80;
                    work->unk_010++;
                    if (work->unk_010 > 30) {
                        work->unk_010 = 0;
                        work->unk_00C = 3;
                    }
                } else {
                    func_080F800C(work, i);
                }
                break;
            case 3:
                if (e->unk_1A0 == 2) {
                    t = e->unk_124;
                    e->unk_124 = work->unk_018 == 0 ? t - 0x300 : t + 0x300;
                    e->unk_128 -= 0x133;

                    if (!(e->unk_15A & 4)) {
                        if (func_08011F78(0xE3, e->unk_004, e->unk_008, e->unk_00C, 0x10, 0x10, 0x20)) {
                            m4aSongNumStart(0x25A);
                        }
                    }
                    work->unk_010++;
                    if (work->unk_010 > 15) {
                        func_080F7F54(work, 1);
                    }
                } else {
                    func_080F800C(work, i);
                }
                break;
            }
            break;
        case 2:
            switch (e->unk_1A0) {
            case 0:
                func_0801AF08(e);
                break;
            case 2:
            case 3:
                e->unk_15A &= 0xFFFE;
                break;
            }
            func_080F800C(work, i);
            break;
        }
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_00E &= 0xFFFE;
    }
    return 1;
}
#else
INCLUDE_ASM("room/func_080F9744.s");
#endif

u8 func_080F99C0(RoomWork* work) {
    RoomEntry* e;
    u32 i;
    s32 t;

    if (work->unk_00E & 1) {
        work->unk_008 = 2;
    }

    for (i = 0; i <= 5; i++) {
        e = &work->entries[i];

        switch (work->unk_008) {
        case 0:
            switch (e->unk_1A0) {
            case 0:
                work->unk_00C = 0;
                work->unk_010 = 0;
                work->unk_A48 = 0x1E00;
                break;
            case 2:
                e->unk_1A4 = 0x80;
                AnimStart(&e->unk_180, 1, 1);
                break;
            case 3:
                e->unk_1A4 = work->unk_018 == 0 ? 0xC0 : 0x40;
                AnimStart(&e->unk_180, 1, 1);
                break;
            }
            break;
        case 1:
            switch (work->unk_00C) {
            case 0:
                switch (e->unk_1A0) {
                case 0:
                    work->unk_010++;
                    if (work->unk_010 > 31) {
                        work->unk_010 = 0;
                        work->unk_00C = 1;
                    }
                    break;
                case 2:
                    t = e->unk_1A4;
                    e->unk_1A4 = work->unk_018 == 0 ? t - 1 : t + 1;
                    e->unk_124 = (gSineTable[e->unk_1A4] * work->unk_A48 >> 8) + work->entries[0].unk_124;
                    e->unk_128 = (-gSineTable[e->unk_1A4 + 0x40] * work->unk_A48 >> 8) + work->entries[0].unk_128;
                    break;
                case 3:
                    t = e->unk_1A4;
                    e->unk_1A4 = work->unk_018 == 0 ? t + 1 : t - 1;
                    e->unk_124 = (gSineTable[e->unk_1A4] * work->unk_A48 >> 8) + work->entries[0].unk_124;
                    e->unk_128 = (-gSineTable[e->unk_1A4 + 0x40] * work->unk_A48 >> 8) + work->entries[0].unk_128;
                    break;
                default:
                    func_080F800C(work, i);
                    break;
                }
                break;
            case 1:
                switch (e->unk_1A0) {
                case 0:
                    work->unk_A48 += 0x59;
                    work->unk_010++;
                    if (work->unk_010 > 0x7F) {
                        func_080F7F54(work, 1);
                    }
                    break;
                case 2:
                case 3:
                    e->unk_1A4 = e->unk_1A4 + 4;

                    if (!(e->unk_15A & 4)) {
                        if (func_08011F78(0xE4, e->unk_004, e->unk_008, e->unk_00C, 0x10, 0x10, 0x20)) {
                            m4aSongNumStart(0x25A);
                        }
                    }
                    e->unk_124 = (gSineTable[e->unk_1A4] * work->unk_A48 >> 8) + work->entries[0].unk_124;
                    e->unk_128 = (-gSineTable[e->unk_1A4 + 0x40] * work->unk_A48 >> 8) + work->entries[0].unk_128;
                    break;
                default:
                    func_080F800C(work, i);
                    break;
                }
                break;
            }
            break;
        case 2:
            switch (e->unk_1A0) {
            case 0:
                func_0801AF08(e);
                break;
            case 2:
            case 3:
                AnimStart(&e->unk_180, 0, 1);
                break;
            }
            func_080F800C(work, i);
            break;
        }
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_00E &= 0xFFFE;
    }
    return 1;
}

#ifdef NON_MATCHING
u8 func_080F9C2C(RoomWork* work) {
    RoomEntry* e;
    u32 i;
    s32 t;

    t = 0;

    if (work->unk_00E & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
    case 0:
        for (i = 0; i <= 5; i++) {
            e = &work->entries[i];
            e->unk_15A |= 1;

            if (i == 0) {
                AnimStart(&work->unk_A10, 1, 1);
                AnimStart(&e->unk_180, 2, 1);
            }
        }
        work->unk_00C = 0;
        break;
    case 1:
        switch (work->unk_00C) {
        case 0:
            gUnk_02039B84->unk_0D4 += 0x33;
            if (gUnk_02039B84->unk_0D4 > 0x1800) {
                work->unk_00C = 1;
            }

            for (i = 0; i <= 5; i++) {
                if (i <= 3) {
                    func_080F800C(work, i);
                }
            }
            break;
        case 1:
            gUnk_02039B84->unk_0D4 = 0;
            work->unk_A38 = (gUnk_02039B84->unk_07C[1] - gUnk_02039B84->unk_0CC) / 60;
            work->unk_A3C = (gUnk_02039B84->unk_07C[2] - gUnk_02039B84->unk_0D0) / 60;
            work->unk_A40 = 0x600;
            work->unk_00C = 2;
            break;
        case 2:
            gUnk_02039B84->unk_0CC += work->unk_A38;
            gUnk_02039B84->unk_0D0 += work->unk_A3C;
            gUnk_02039B84->unk_0D4 -= work->unk_A40;
            work->unk_A40 -= 0x33;

            if (gUnk_02039B84->unk_0D4 > 0) {
                func_0802F1E8();
                m4aSongNumStart(0x25B);
                func_08011F78(0xE5, gUnk_02039B84->unk_000, gUnk_02039B84->unk_004, 0, 0x140, 0xF0, 1);
                work->unk_00C = 3;
            }

            for (i = 0; i <= 5; i++) {
                func_080F800C(work, i);
            }
            break;
        case 3:
            gUnk_02039B84->unk_0D4 = 0;
            work->unk_A40 = 0x100;
            work->unk_00C = 4;
            break;
        case 4:
            gUnk_02039B84->unk_0D4 += work->unk_A40;
            t = work->unk_A40 - 7;
            work->unk_A40 = t;

            if (gUnk_02039B84->unk_0D4 <= 0 && t < 0) {
                func_080F7F54(work, 1);
            }

            for (i = 0; i <= 5; i++) {
                if (i <= 3) {
                    func_080F800C(work, i);
                }
            }
            break;
        }
        break;
    case 2:
        gUnk_02039B84->unk_0D4 = t;

        for (i = 0; i <= 5; i++) {
            e = &work->entries[i];

            switch (i) {
            case 0:
                AnimStart(&work->unk_A10, 0, 1);
                AnimStart(&e->unk_180, 0, 1);
                func_0801AF08(e);
            default:
                e->unk_15A &= 0xFFFE;
                break;
            case 4:
            case 5:
                break;
            }
            func_080F800C(work, i);
        }
        break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_00E &= 0xFFFE;
    }
    return 1;
}
#else
INCLUDE_ASM("room/func_080F9C2C.s");
#endif

INCLUDE_ASM("room/func_080F9EDC.s");
INCLUDE_ASM("room/func_080FA2B4.s");
INCLUDE_ASM("room/func_080FA644.s");

#ifdef NON_MATCHING
u8 func_080FAA18(RoomWork* work) {
    RoomEntry* e;
    u32 i;
    s32 t;

    t = 0;

    if (work->unk_00E & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
    case 0:
        work->unk_010 = 0x12C;

        for (i = 0; i <= 5; i++) {
            e = &work->entries[i];
            if (!(e->unk_15A & 4)) {
                e->unk_120 = -gSineTable[((GetRandom() % 0x20) & 0xFF) + 0x40] * -3;
                e->unk_164 = gSineTable[(GetRandom() % 0x100) & 0xFF] * 0x233 >> 8;
                e->unk_168 = -gSineTable[((GetRandom() % 0x100) & 0xFF) + 0x40] * 0x233 >> 8;
                e->unk_11C = 1;

                if (i == 0) {
                    AnimStart(&work->unk_A10, 1, 1);
                    AnimStart(&e->unk_180, 2, 1);
                }
            }
        }
        m4aSongNumStart(0x26A);
        func_0802F1E8();
        break;
    case 1:
        work->unk_010--;
        if (work->unk_010 > 0) {
            break;
        }
        func_080F7F54(work, 1);
        break;
    case 2:
        gUnk_02039B84->unk_0D4 = t;

        for (i = 0; i <= 5; i++) {
            e = &work->entries[i];
            t = e->unk_15A & 4;
            if (t == 0) {
                if (i == 0) {
                    AnimStart(&work->unk_A10, 0, 1);
                    AnimStart(&e->unk_180, 0, 1);
                }
                e->unk_11C = t;
                func_080F800C(work, i);
            }
        }
        break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_00E &= 0xFFFE;
    }
    return 1;
}
#else
INCLUDE_ASM("room/func_080FAA18.s");
#endif

INCLUDE_ASM("room/func_080FABE4.s");
