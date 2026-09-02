#include "macros.h"
#include "mode_sio2.h"
#include "gba/keys.h"

void mode_sio_dbg_flg_0(s32 arg) {
    s32 i;

    func_08004DB0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08128304, 0x20, 0x0F);
    gUnk_02034CF4 = 0;
    func_0805FCB0(8, 0x24, 2, gUnk_0961A9C8);
    gUnk_02034CF5 = 5;
    func_0805FCB0(0x0C, 0x12, 2, gUnk_0961A9CC);

    for (i = 0; i < gUnk_02034CF5; i++) {
        func_0805FCB0(0x14, i * 9 + 0x24, 2, gUnk_09EF34F0[i]);
    }

    gUnk_0203C3C8 = 50;
    gUnk_0203C3CC = 500;
    gUnk_0203C3D0 = 500;
    gUnk_0203C3C4 = 0;
    gUnk_0203C3D4 = 0;
    func_0805FC04(0x64, 0x24, 2, gUnk_0203C3C8);
    func_0805FC04(0x64, 0x2D, 2, gUnk_0203C3CC);
    func_0805FC04(0x64, 0x36, 2, gUnk_0203C3D0);
    func_0805FCB0(0x64, 0x3F, 2, gUnk_09EF3504[gUnk_0203C3C4]);
    func_0805FCB0(0x64, 0x48, 2, gUnk_09EF3504[gUnk_0203C3D4]);
}

void mode_sio_dbg_flg_1(void) {
    u8 prev;

    prev = gUnk_02034CF4;

    if (GetKeysRepeat() & DPAD_UP) {
        gUnk_02034CF4--;
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        gUnk_02034CF4++;
    }

    if (prev != gUnk_02034CF4) {
        if (gUnk_02034CF4 < 0) {
            gUnk_02034CF4 = gUnk_02034CF5 - 1;
        } else if (gUnk_02034CF4 >= gUnk_02034CF5) {
            gUnk_02034CF4 = 0;
        }

        func_0805FCB0(8, (prev + 4) * 9, 2, gUnk_0961A9E8);
        func_0805FCB0(8, (gUnk_02034CF4 + 4) * 9, 2, gUnk_0961A9C8);
    }

    switch (gUnk_02034CF4) {
    case 0:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3C8 > 1) {
                gUnk_0203C3C8--;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3C8 <= 98) {
                gUnk_0203C3C8++;
            }
        }
        func_0805FC04(0x64, 0x24, 2, gUnk_0203C3C8);
        break;
    case 1:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3CC > 5) {
                gUnk_0203C3CC -= 5;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3CC <= 994) {
                gUnk_0203C3CC += 5;
            }
        }
        func_0805FC04(0x64, 0x2D, 2, gUnk_0203C3CC);
        break;
    case 2:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3D0 > 5) {
                gUnk_0203C3D0 -= 5;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3D0 <= 994) {
                gUnk_0203C3D0 += 5;
            }
        }
        func_0805FC04(0x64, 0x36, 2, gUnk_0203C3D0);
        break;
    case 3:
        break;
    case 4:
        break;
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        gUnk_0203A9E4 = 1;
        func_08085CB0();
        ModeRequest(&gUnk_09EF1308, 0);
    } else {
        func_080605A4(0);
        func_08060598();
    }
}

void mode_sio_dbg_flg_2(void) {
    func_080609A0();
}

void func_080C7350(void) {
    gUnk_0203AAC0.unk_04 = gUnk_0203C3C8;
    gUnk_0203AAC0.unk_02 = gUnk_0203C3CC;
}

void func_080C736C(void) {
    gUnk_02034CFC = 0;
    gUnk_02034D00 = 0;
    gUnk_02034D04 = 0;
    gUnk_02034D08 = 0;
    gUnk_02034D0C = 0;
    gUnk_02034D10 = 0;
}

void func_080C73A4(u16 r, u16 g, u16 b) {
    func_08005778(r, g, b);
    gUnk_02034CF8 = (b << 10) | (g << 5) | r;
}

void func_080C73D8(void) {
    u16 amt;
    u16 r;
    u16 g;
    u16 b;

    if (gUnk_02034CFC != gUnk_02034D04) {
        amt = gUnk_02034CFC >> 8;
        r = gUnk_02034CF8 & 31;
        g = (gUnk_02034CF8 >> 5) & 31;
        b = (gUnk_02034CF8 >> 10) & 31;

        switch (gUnk_02034D0C) {
        case 0:
            r -= amt;
            g -= amt;
            b -= amt;
            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b < 0) {
                b = 0;
            }
            break;
        case 1:
            if ((s16)r < amt) {
                r = amt;
            }

            if ((s16)g < amt) {
                g = amt;
            }

            if ((s16)b < amt) {
                b = amt;
            }
            break;
        case 3:
            r = amt + r;
            g -= amt;
            b -= amt;
            if ((s16)r > 31) {
                r = 31;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b < 0) {
                b = 0;
            }
            break;
        case 5:
            r -= amt;
            g = amt + g;
            b -= amt;
            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g > 31) {
                g = 31;
            }

            if ((s16)b < 0) {
                b = 0;
            }
            break;
        case 4:
            r -= amt;
            g -= amt;
            b = amt + b;
            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b > 31) {
                b = 31;
            }
            break;
        default:
            r = amt + r;
            g = amt + g;
            b = amt + b;
            if ((s16)r > 31) {
                r = 31;
            }

            if ((s16)g > 31) {
                g = 31;
            }

            if ((s16)b > 31) {
                b = 31;
            }
            break;
        }
        func_08005778(r, g, b);
    }

    if (gUnk_02034D08 != 0) {
        gUnk_02034D04 = gUnk_02034CFC;
        ApproachValue(&gUnk_02034CFC, gUnk_02034D00, gUnk_02034D08);
        gUnk_02034D08--;
    } else {
        gUnk_02034D10 = 0;
    }
}

void func_080C7568(u32 a, u16 b) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = b;
    gUnk_02034CFC = 0x1F00;
    gUnk_02034D00 = 0;
    gUnk_02034D04 = 0;
    gUnk_02034D0C = a;
}

void func_080C75A4(u32 a, u16 b) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = b;
    gUnk_02034CFC = 0;
    gUnk_02034D00 = 0x1F00;
    gUnk_02034D04 = 0;
    gUnk_02034D0C = a;
}

void func_080C75E0(u32 a, u16 b) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = b;
    gUnk_02034D00 = 0;
    gUnk_02034D0C = a;
}

void func_080C7608(u32 a, u16 b, u16 c) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = c;
    gUnk_02034D00 = b << 8;
    gUnk_02034D0C = a;
}

u8 func_080C7638(void) {
    return gUnk_02034D10;
}

void func_080C7644(u32 a, u16 b, u16 c) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = c;
    gUnk_02034CFC = b << 8;
    gUnk_02034D04 = 0;
    gUnk_02034D00 = 0;
    gUnk_02034D0C = a;
}

void func_080C7684(s32 a, s32 b, s32 c) {
    gUnk_0203C3D8 = 1;
    gUnk_02034D9C = a;
    gUnk_02034DA0 = b * 2;
    gUnk_02034DA4 = c;
}

u8 func_080C76B0(PoohNear* p) {
    s32 lim;
    s32 dx;
    s32 dy;
    s32 dz;

    lim = p->unk_10 + 0x1400;
    dx = gUnk_02034D9C - p->unk_04;
    if (dx < 0) {
        dx = p->unk_04 - gUnk_02034D9C;
    }
    dy = gUnk_02034DA0 - p->unk_08;
    if (dy < 0) {
        dy = p->unk_08 - gUnk_02034DA0;
    }
    dz = gUnk_02034DA4 - p->unk_0C;
    if (dx < lim && dy < lim && dz <= 0x1FFF && -dz < p->unk_14) {
        return 1;
    }
    return 0;
}

void func_080C7714(void) {
    PoohPos p;

    p.unk_00 = 0x13000;
    p.unk_04 = 0xE800;
    p.unk_08 = 0;
    func_080D2D0C(&p);
    p.unk_00 = 0x11000;
    p.unk_04 = 0xF800;
    p.unk_08 = 0;
    func_080D2C8C(&p, 0);
}

void func_080C774C(void) {
    PoohPos p;

    p.unk_00 = 0xB5400;
    p.unk_04 = 0x5DE00;
    p.unk_08 = 0;
    func_080D2D0C(&p);
    if (func_080D2D94(3)) {
        p.unk_00 = 0xB3400;
        p.unk_04 = 0x5EE00;
        p.unk_08 = 0;
        func_080D2C8C(&p, 0);
    }
}

void mode_pooh_0(s32 arg) {
    s32 i;

    gUnk_02039BB0.unk_0C = 13;

    if (arg == 0) {
        func_080D2BE0();
        func_080C7714();
    } else if (arg == 2) {
        func_080D2BE0();
        func_080C774C();
    }

    m4aSongNumStart(0x22);
    m4aSongNumStart(0x95);
    func_08004DB0();
    SetupBg(3, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 2, 30, 0);
    SetupBg(0, 3, 31, 14);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    func_0801227C();
    func_080CCBE8();
    func_080D2E98();

    TaskPoolInit(&gUnk_02034D18, 32);

    for (i = 0; i < 12; i++) {
        gUnk_02034D50[i] = 0;
    }

    TaskCreate(&gUnk_02034D18, &gUnk_09EF48C8, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4A48, 0);

    if (!func_080D2D50(2)) {
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4B50, 0);
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4BE0, 0);
    } else {
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4BF8, 0);
    }

    TaskCreate(&gUnk_02034D18, &gUnk_09EF4A60, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4B68, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4A78, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4B98, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4BB0, 0);

    if (!func_080D2D50(4)) {
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4A90, 0);
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4C28, 0);
    } else {
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4D80, 0);
        TaskCreate(&gUnk_02034D18, &gUnk_09EF4D98, 0);
    }

    TaskCreate(&gUnk_02034D18, &gUnk_09EF4B80, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4AA8, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4AF0, 0);

    if (func_080D2D50(5)) {
        if (!func_080D2D50(1)) {
            TaskCreate(&gUnk_02034D18, &gUnk_09EF4AD8, 0);
        } else {
            TaskCreate(&gUnk_02034D18, &gUnk_09EF4AC0, 0);
        }
    }

    TaskCreate(&gUnk_02034D18, &gUnk_09EF41F0, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF41D8, 0);
    TaskCreate(&gUnk_02034D18, &gUnk_09EF4988, 0);

    TaskPoolInit(&gUnk_02034D80, 1);

    if (func_080D2D94(2)) {
        gUnk_02034D94 = 0;
    } else {
        gUnk_02034D94 = TaskCreate(&gUnk_02034D80, &gUnk_09EF161C, 0);
        func_080D2D6C(2);
    }

    TaskPoolInit(&gUnk_02034D30, 1);
    func_080C736C();
    func_080C73A4(6, 31, 31);
    func_08006120(0, 16);
    func_080C7568(0, 16);
    gUnk_02034D44 = 0;
    gUnk_02034D4C = 180;
}

void mode_pooh_1(void) {
    UpdatePlayTime();
    func_080C7CB0(0);

    if (gUnk_02034D44 != 0 && !func_08006314()) {
        if (gUnk_02034D48 == 197) {
            func_080DF814();
        } else {
            func_0806180C(gUnk_02034D48);
        }
        return;
    }

    if (func_08006314() == 0) {
        gUnk_0203C3D8 = 0;
        if (func_08000F48(gUnk_02034D94)) {
            TaskPoolUpdate(&gUnk_02034D80);
        } else if (func_080A42C8() == 0) {
            if (gUnk_02034D4C == 0xFFFE) {
                if (func_080A42D4()) {
                    func_080C7B84(197);
                } else {
                    gUnk_02034D4C = 180;
                }
            } else if (gUnk_02034D4C == 0xFFFD) {
                if (func_080A42D4()) {
                    func_080C7B84(148);
                } else {
                    gUnk_02034D4C = 180;
                }
            } else {
                TaskPoolUpdate(&gUnk_02034D18);
            }
        } else {
            TaskPoolUpdate(&gUnk_02034D30);
        }
    }

    TaskPoolDraw(&gUnk_02034D80);
    TaskPoolDraw(&gUnk_02034D30);
    TaskPoolDraw(&gUnk_02034D18);
    func_080125A4();
    func_080C73D8();
}

void mode_pooh_2(void) {
    TaskPoolDestroy(&gUnk_02034D18);
    TaskPoolDestroy(&gUnk_02034D30);
    TaskPoolDestroy(&gUnk_02034D80);
    func_080D2E84();
    m4aSongNumStop(0x95);
}

void func_080C7B84(u32 a) {
    s32 i;

    if (gUnk_02034D44 == 0) {
        gUnk_02034D48 = a;
        for (i = 0; i <= 31; i++) {
            func_080062F4(i, 0);
        }
        func_08006184(0, 16);
        func_080C75A4(0, 16);
        gUnk_02034D44 = 1;
    }
}

void func_080C7BCC(u16 a) {
    gUnk_02034D4C = a;
    if (a == 0xFFFD || a == 0xFFFE) {
        a = 0x45;
    }
    func_080A411C(&gUnk_02034D30, 0, a);
}

u16 func_080C7BF8(u8 kind, u8 count, s32 x, s32 y, s32 z) {
    PoohPrizeArgs args;
    u16 made;
    s32 i;
    s32 j;

    args.unk_04 = x;
    args.unk_08 = y;
    args.unk_0C = z;
    args.unk_14 = kind;
    made = 0;
    j = 0;

    for (i = 0; i < count; i++) {
        for (; j < 12; j++) {
            if (!func_08000F48(gUnk_02034D50[j])) {
                gUnk_02034D50[j] = TaskCreate(&gUnk_02034D18, &gUnk_09EF4C58, &args);
                made++;
                break;
            }
        }
    }
    return made;
}

u16 func_080C7C80(void) {
    u16 n;
    s32 i;

    n = 0;
    for (i = 0; i < 12; i++) {
        if (func_08000F48(gUnk_02034D50[i])) {
            n++;
        }
    }
    return n;
}

void func_080C7CB0(u8 a) {
    gUnk_02034D98 = a;
}

u8 func_080C7CBC(void) {
    return gUnk_02034D98;
}

void func_080C7CC8(PoohWork* w) {
    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 1:
        w->unk_A8 = 4;
        w->unk_24 = 0;
        break;
    case 2:
        w->unk_A8 = 3;
        w->unk_24 = 0;
        break;
    case 3:
        w->unk_A8 = 2;
        w->unk_24 = 0;
        break;
    case 4:
        w->unk_A8 = 1;
        w->unk_24 = 0;
        break;
    case 5:
        w->unk_A8 = 2;
        w->unk_24 = 1;
        break;
    case 6:
        w->unk_A8 = 3;
        w->unk_24 = 1;
        break;
    case 7:
        w->unk_A8 = 4;
        w->unk_24 = 1;
        break;
    case 0:
    default:
        w->unk_A8 = 0;
        w->unk_24 = 0;
        break;
    }
}

void func_080C7D60(PoohWork* w) {
    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 1:
        w->unk_A8 = 4;
        w->unk_24 = 1;
        break;
    case 2:
        w->unk_A8 = 3;
        w->unk_24 = 1;
        break;
    case 3:
        w->unk_A8 = 2;
        w->unk_24 = 1;
        break;
    case 4:
        w->unk_A8 = 1;
        w->unk_24 = 0;
        break;
    case 5:
        w->unk_A8 = 2;
        w->unk_24 = 0;
        break;
    case 6:
        w->unk_A8 = 3;
        w->unk_24 = 0;
        break;
    case 7:
        w->unk_A8 = 4;
        w->unk_24 = 0;
        break;
    case 0:
    default:
        w->unk_A8 = 0;
        w->unk_24 = 0;
        break;
    }
}

void func_080C7DF8(PoohWork* w) {
    w->unk_24 = 0;

    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 0:
        w->unk_A8 = 0;
        break;
    case 1:
        w->unk_A8 = 4;
        break;
    case 2:
        w->unk_A8 = 3;
        break;
    case 3:
        w->unk_A8 = 2;
        break;
    case 4:
        w->unk_A8 = 1;
        break;
    case 5:
        w->unk_A8 = 5;
        break;
    case 6:
        w->unk_A8 = 6;
        break;
    case 7:
        w->unk_A8 = 7;
        break;
    default:
        w->unk_A8 = 0;
        break;
    }
}

void func_080C7E98(PoohWork* w) {
    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 0:
    case 1:
        w->unk_A8 = 0;
        w->unk_24 = 1;
        break;
    case 2:
        w->unk_A8 = 1;
        w->unk_24 = 1;
        break;
    case 3:
        w->unk_A8 = 1;
        w->unk_24 = 1;
        break;
    case 4:
    case 5:
    case 6:
        w->unk_A8 = 1;
        w->unk_24 = 0;
        break;
    case 7:
    default:
        w->unk_A8 = 0;
        w->unk_24 = 0;
        break;
    }
}

void func_080C7F18(PoohWork* w) {
    if (w->unk_38 <= 99) {
        w->unk_A8 = 3;
        w->unk_24 = 1;
    } else if (w->unk_38 <= 156) {
        w->unk_A8 = 1;
        w->unk_24 = 0;
    } else {
        w->unk_A8 = 3;
        w->unk_24 = 0;
    }
}

u8 func_080C7F4C(u8 a) {
    switch (((a + 16) & 0xFF) >> 5) {
    case 1:
    case 2:
    case 3:
        return 1;
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
        return 0;
    }
    return 0;
}

u8 func_080C7F94(PoohWork* w) {
    u8 tbl[8][8];
    u32 row;
    u32 col;

    memcpy(tbl, gUnk_096FC01C, sizeof(tbl));
    row = (u32)((w->unk_38 + 16) & 0xFF) >> 5;
    col = (u32)((w->unk_3A + 16) & 0xFF) >> 5;
    if ((s8)tbl[row][col] == 3) {
        return w->unk_3B;
    }
    return tbl[row][col] + 2;
}

void func_080C7FEC(PoohWork* w, u32 anim) {
    PoohAnim* e;
    s32 flags;

    flags = 0;
    func_08012650(w->unk_4C, gUnk_096FC010.unk_08);

    if (w->unk_26 == anim) {
        flags = 4;
    }
    w->unk_26 = anim;

    switch (anim) {
    case 3:
    case 4:
    case 7:
        flags |= 1;
        func_080C7DF8(w);
        e = &gUnk_09EF3D88[w->unk_A8];
        break;
    case 5:
    case 6:
        flags |= 1;
        func_080C7F18(w);
        e = &gUnk_09EF3FF8[w->unk_A8];
        break;
    case 16:
        func_080C7DF8(w);
        e = &gUnk_09EF3E08[w->unk_A8];
        break;
    case 17:
        func_080C7D60(w);
        e = &gUnk_09EF3CE8[w->unk_A8];
        break;
    case 18:
        func_080C7D60(w);
        e = &gUnk_09EF3D38[w->unk_A8];
        break;
    case 19:
        func_080C7E98(w);
        e = &gUnk_09EF3EC8[w->unk_A8];
        break;
    case 20:
        w->unk_FA = 1;
        func_080C7E98(w);
        e = &gUnk_09EF3EE8[w->unk_A8];
        break;
    case 21:
        w->unk_FA = 1;
        func_080C7E98(w);
        if (func_080D2D50(6) != 0 || w->unk_F6 != 0 || (w->unk_A8 == 5 && w->unk_24 == 0)) {
            e = &gUnk_09EF3EE8[w->unk_A8];
        } else {
            e = &gUnk_09EF3F08[w->unk_A8];
        }
        break;
    case 36:
        w->unk_24 = 0;
        e = gUnk_09EF3E88;
        break;
    case 37:
        w->unk_24 = 0;
        e = gUnk_09EF3E98;
        break;
    case 23:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F28;
        w->unk_FA = 1;
        break;
    case 32:
        w->unk_24 = 0;
        e = gUnk_09EF3F88;
        w->unk_FA = 1;
        break;
    case 33:
        w->unk_24 = 0;
        e = gUnk_09EF3FC8;
        break;
    case 34:
        w->unk_24 = 0;
        e = gUnk_09EF3FD8;
        break;
    case 35:
        w->unk_24 = 0;
        e = gUnk_09EF3FE8;
        break;
    case 24:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F38;
        w->unk_FA = 1;
        break;
    case 25:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F48;
        w->unk_FA = 1;
        break;
    case 26:
        func_08012650(w->unk_4C, 14);
        flags |= 1;
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F58;
        w->unk_FA = 1;
        break;
    case 27:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F68;
        w->unk_FA = 1;
        break;
    case 28:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F78;
        w->unk_FA = 1;
        break;
    case 29:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3F98;
        break;
    case 30:
        flags |= 1;
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3FA8;
        break;
    case 31:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = gUnk_09EF3FB8;
        break;
    case 38:
    case 39:
        flags |= 1;
        w->unk_24 = 0;
        e = gUnk_09EF3EA8;
        break;
    case 22:
        flags |= 1;
        w->unk_24 = 0;
        e = gUnk_09EF3EB8;
        break;
    case 0:
    case 1:
    case 2:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        flags |= 1;
        func_080C7CC8(w);
        w->unk_3B = func_080C7F94(w);
        e = &gUnk_09EF4048[w->unk_A8][func_080C7F94(w)];
        break;
    default:
        flags |= 1;
        func_080C7CC8(w);
        e = &gUnk_09EF3C98[w->unk_A8];
        break;
    }

    func_08005974(&w->unk_0C, e->unk_0C, flags, e->unk_04, e->unk_00);
    func_08002A10(w->unk_00, e->unk_08);
}

u8 func_080C83C4(u16 x, u16 y, u16 px, u16 py) {
    if (x - gUnk_096FC010.unk_08 < px && px < x + gUnk_096FC010.unk_08 &&
        y - gUnk_096FC010.unk_08 < py && py < y + gUnk_096FC010.unk_08) {
        return 1;
    }
    return 0;
}

s32 func_080C8404(PoohPos* a, PoohPos* b) {
    s32 dx;
    s32 dy;

    dx = a->unk_00 - b->unk_00;
    if (dx < 0) {
        dx = b->unk_00 - a->unk_00;
    }
    dy = a->unk_04 - b->unk_04;
    if (dy < 0) {
        dy = b->unk_04 - a->unk_04;
    }
    return dx + dy;
}

void func_080C8428(PoohWork* w, u32 b) {
    u8* pal;

    switch (b) {
    case 16:
        pal = gUnk_09849AD8;
        break;
    case 36:
    case 37:
        pal = gUnk_09849AF8;
        break;
    case 38:
    case 39:
        pal = gUnk_09849B18;
        break;
    default:
        pal = gUnk_09849A98;
        break;
    }

    if (w->unk_04->unk_00 != pal) {
        ReleaseObjPalette(w->unk_04);
        w->unk_04 = LoadObjPalette(pal, 32);
    }
}

#ifdef NON_MATCHING
void func_080C84E0(PoohWork* w, u32 b) {
    gUnk_02034DAC = b;
    if (b == 0) {
        gUnk_0203C3F0 = 0;
    }

    if (b == 38 || b == 39) {
        w->unk_AC = 0;
        if (!func_08000F48(w->unk_C4)) {
            w->unk_C4 = TaskCreate(&w->unk_B0, &gUnk_09EF4910, w->unk_28);
        }
    }

    if (b == 30 || b == 24 || b == 4 || b == 11) {
        w->unk_DA = 0;
    }

    if (b == 15) {
        w->unk_48 = -0x130;
    }

    if (b == 36 || b == 37) {
        m4aSongNumStart(0x149);
    } else if (b == 16) {
        m4aSongNumStart(164 * 2);
    } else if (b == 39 || b == 22 || (b >= 32 && b <= 35)) {
        w->unk_38 = 173;
        w->unk_3A = 173;
        w->unk_3B = w->unk_38;
    }

    if (b > 35) {
        w->unk_38 = 83;
        w->unk_3A = 83;
        w->unk_3B = w->unk_38;
    }

    func_080C8428(w, b);
}
#else
INCLUDE_ASM("mode_sio2/func_080C84E0.s");
#endif
