#include "macros.h"
#include "tutorial.h"

void task_tutorial_0(TutorialWork* work, s32 arg1) {
    gUnk_0300750C = 0;
    func_08005074(0, 2, 28, 14);
    func_080054EC(0, 0, 0);
    work->unk_000 = 0;
    work->unk_00C = 0;
    work->unk_004 = 0;
    work->unk_00E = 120;
    work->unk_008 = arg1 == 0 ? 5 : 0x2B;
    gUnk_02039B84->unk_068 |= 0x1000000000ULL;
    gUnk_02039B84->unk_068 |= 0x100000000000ULL;
    gUnk_02039B84->unk_068 |= 0x200000000000ULL;
    gUnk_02039B84->unk_068 |= 0x2000000000ULL;
    gUnk_02039B84->unk_068 |= 0x4000000000ULL;
    gUnk_02039B84->unk_068 |= 0x8000000000ULL;
    gUnk_02039B84->unk_068 |= 0x4000000000000ULL;
    gUnk_02039B84->unk_068 |= 0x10000000000ULL;
    work->unk_018 = func_080028F8(0x100, gUnk_08B263D2);
    work->unk_01C = func_08002A14(gUnk_08F69BA4, 32);
    func_08005968(work->unk_020, gUnk_09EE15F0, gUnk_09EE15C0);
    func_080059A4(work->unk_020, 0, 1);
    func_08006578(2);
}

s32 task_tutorial_1(TutorialWork* work) {
    switch (work->unk_004) {
    case 0:
        if (work->unk_00C > work->unk_00E) {
            work->unk_004 = work->unk_008;
            work->unk_00C = 0;
        } else {
            work->unk_00C++;
        }
        break;
    case 1:
        gUnk_02039B84->unk_072 = 8;
        if (work->unk_00C > 20) {
            work->unk_004 = 2;
            work->unk_00C = 0;
        } else {
            work->unk_00C++;
        }
        break;
    case 2:
        gUnk_02039B84->unk_072 = 8;
        if (work->unk_00C == 0) {
            if (func_080128EC() != 0) {
                break;
            }
            func_0805DA64(work->unk_002);
            work->unk_00C++;
            break;
        }
        if (func_080A42C8() != 0) {
            break;
        }
        func_0805DAB4();
        work->unk_004 = work->unk_008;
        work->unk_00C = 0;
        break;
    case 3:
        gUnk_02039B84->unk_072 = 8;
        if (work->unk_00C > 20) {
            work->unk_004 = 4;
            work->unk_00C = 0;
        } else {
            work->unk_00C++;
        }
        break;
    case 4:
        gUnk_02039B84->unk_072 = 8;
        if (func_080128EC() != 0) {
            break;
        }
        func_0805DA98(work->unk_002);
        work->unk_004 = work->unk_008;
        work->unk_00C = 0;
        break;
    case 5:
        func_0805DACC(work, 0x48, 6);
        break;
    case 6:
        if (work->unk_00C == 0) {
            func_0809B644(gUnk_02039B84->unk_02C, 320, 0x181, 0, 1);
        }
        if (work->unk_00C > 120) {
            work->unk_004 = 7;
            work->unk_00C = 0;
        } else {
            work->unk_00C++;
        }
        break;
    case 7:
        func_0805DACC(work, 0x49, 9);
        break;
    case 9:
        func_0805DADC(work, 0x4A, 10);
        break;
    case 10:
        if (work->unk_00C == 0) {
            gUnk_02039B84->unk_068 &= ~0x1000000000ULL;
        }
        if (!(gUnk_02039B84->unk_068 & 0x20000000000ULL)) {
            work->unk_00C++;
            break;
        }
        func_0805DAEC();
        gUnk_02039B84->unk_068 &= ~0x20000000000ULL;
        work->unk_004 = 11;
        work->unk_00C = 0;
        break;
    case 11:
        if (work->unk_00C > 20) {
            func_08076324();
            func_0805DAF8(work, 30, 12);
        } else {
            work->unk_00C++;
        }
        break;
    case 12:
        func_0805DACC(work, 0x4B, 13);
        break;
    case 13:
        func_0805DADC(work, 0x4C, 14);
        break;
    case 14:
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x2000000000ULL;
        }
        if (!(gUnk_02039B84->unk_068 & 0x20000000)) {
            work->unk_00C++;
            break;
        }
        func_0805DAEC();
        gUnk_02039B84->unk_068 |= 0x2000000000ULL;
        work->unk_004 = 15;
        work->unk_00C = 0;
        break;
    case 15:
        if (gUnk_02039B84->unk_068 & 0x20000000) {
            break;
        }
        func_0805DACC(work, 0x4D, 16);
        break;
    case 16:
        func_0805DACC(work, 0x4E, 17);
        break;
    case 17:
        func_0805DADC(work, 0x4F, 18);
        break;
    case 18:
        if (work->unk_00C == 0) {
            gUnk_02039B84->unk_068 &= ~0x200000000000ULL;
            gUnk_02039B84->unk_068 &= ~0x100000000000ULL;
        }
        if (!(gUnk_02039B84->unk_068 & 0x40000000000ULL)) {
            work->unk_00C++;
            break;
        }
        if (!(gUnk_02039B84->unk_068 & 0x80000000000ULL)) {
            work->unk_00C++;
            break;
        }
        func_0805DAEC();
        gUnk_02039B84->unk_068 &= ~0x40000000000ULL;
        gUnk_02039B84->unk_068 &= ~0x80000000000ULL;
        func_0805DAF8(work, 15, 19);
        break;
    case 19:
        func_0805DACC(work, 0x50, 20);
        break;
    case 20:
        func_0805DADC(work, 0x51, 21);
        break;
    case 21:
        if (work->unk_00C == 0) {
            work->unk_00E = 0;
            work->unk_000 &= ~2;
        }
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x2000000000ULL;
        }
        if (work->unk_000 & 2) {
            if (!(gUnk_02039B84->unk_068 & 0x20000000)) {
                if (work->unk_00E == 0) {
                    func_0805DAEC();
                }
                work->unk_000 &= ~2;
                work->unk_00E++;
            }
        } else if (gUnk_02039B84->unk_068 & 0x20000000) {
            work->unk_000 |= 2;
        }
        if (work->unk_00E <= 2) {
            work->unk_00C++;
            break;
        }
        gUnk_02039B84->unk_068 |= 0x2000000000ULL;
        func_0805DAF8(work, 30, 22);
        break;
    case 22:
        func_0805DACC(work, 0x52, 23);
        break;
    case 23:
        func_0805DACC(work, 0x53, 25);
        break;
    case 25:
        func_0805DB04(work, 14, 90, 0);
        func_0805DACC(work, 0x54, 26);
        break;
    case 26:
        if (work->unk_00C == 0) {
            func_0805DB28(work);
        }
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x2000000000ULL;
        }
        if (gUnk_02039B84->unk_068 & 0x20000000) {
            work->unk_00C++;
            break;
        }
        if (func_080763D0() == 0) {
            work->unk_00C++;
            break;
        }
        gUnk_02039B84->unk_068 |= 0x2000000000ULL;
        func_0805DAF8(work, 60, 27);
        break;
    case 27:
        func_0805DB04(work, 14, 90, 0);
        func_0805DACC(work, 0x55, 29);
        break;
    case 29:
        func_0805DACC(work, 0x56, 30);
        break;
    case 30:
        func_0805DB28(work);
        func_0805DADC(work, 0x57, 31);
        break;
    case 31:
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x2000000000ULL;
        }
        if (gUnk_02039B84->unk_068 & 0x80000000) {
            work->unk_00C++;
            break;
        }
        if (func_080763D0() != 0) {
            work->unk_00C++;
            break;
        }
        func_0805DAEC();
        gUnk_02039B84->unk_068 |= 0x2000000000ULL;
        func_0805DAF8(work, 30, 32);
        break;
    case 32:
        func_0805DACC(work, 0x58, 33);
        break;
    case 33:
        func_0805DACC(work, 0x59, 34);
        break;
    case 34:
        func_0805DADC(work, 0x5A, 35);
        break;
    case 35:
        if (work->unk_00C == 0) {
            work->unk_00E = 0;
            work->unk_010 = 0;
            gUnk_02039B84->unk_068 &= ~0x4000000000ULL;
        }
        if (work->unk_010 <= 0) {
            if (func_08001390() & 0x300) {
                work->unk_010 = 10;
                work->unk_00E++;
            }
        } else {
            work->unk_010--;
        }
        if (work->unk_00E <= 6) {
            work->unk_00C++;
            break;
        }
        work->unk_00C = 0;
        work->unk_004 = 36;
        gUnk_02039B84->unk_068 |= 0x4000000000ULL;
        func_0805DAEC();
        break;
    case 36:
        func_0805DACC(work, 0x5B, 37);
        break;
    case 37:
        func_0805DACC(work, 0x5C, 38);
        break;
    case 38:
        func_0805DADC(work, 0x5D, 39);
        break;
    case 39:
        if (work->unk_00C == 0) {
            work->unk_00E = 0;
            gUnk_02039B84->unk_068 &= ~0x10000000000ULL;
        }
        if (func_08001390() & 4) {
            work->unk_00E++;
        }
        if (work->unk_00E <= 1) {
            work->unk_00C++;
            break;
        }
        func_0805DAEC();
        work->unk_00C = 0;
        work->unk_004 = 40;
        gUnk_02039B84->unk_068 |= 0x10000000000ULL;
        gUnk_02039B84->unk_068 |= 0x4000000000ULL;
        break;
    case 40:
        func_0805DACC(work, 0x5E, 41);
        break;
    case 41:
        func_0805DAF8(work, 0x50, 42);
        break;
    case 43:
        func_0805DAF8(work, 30, 44);
        break;
    case 44:
        func_0805DB04(work, 48, 144, 1);
        func_0805DACC(work, 0x72, 45);
        break;
    case 45:
        if (work->unk_00C == 0) {
            func_0805DB28(work);
            work->unk_000 &= ~2;
            work->unk_00E = 0;
            gUnk_02039B84->unk_068 &= ~0x1000000000ULL;
            gUnk_02039B84->unk_068 &= ~0x100000000000ULL;
            gUnk_02039B84->unk_068 &= ~0x200000000000ULL;
            gUnk_02039B84->unk_068 |= 0x100000ULL;
            gUnk_02039B84->unk_068 |= 0x20000000000ULL;
        }
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x2000000000ULL;
        }
        if (work->unk_000 & 2) {
            if (!(gUnk_02039B84->unk_068 & 0x20000000)) {
                work->unk_000 &= ~2;
                work->unk_00E++;
            }
        } else if (gUnk_02039B84->unk_068 & 0x20000000) {
            work->unk_000 |= 2;
        }
        if (work->unk_00E <= 6) {
            work->unk_00C++;
            break;
        }
        work->unk_00C = 0;
        work->unk_004 = 46;
        gUnk_02039B84->unk_068 |= 0x2000000000ULL;
        gUnk_02039B84->unk_068 &= ~0x100000ULL;
        gUnk_02039B84->unk_068 &= ~0x20000000000ULL;
        break;
    case 46:
        if (work->unk_00C > 30) {
            work->unk_00C = 0;
            work->unk_004 = 47;
        } else {
            work->unk_00C++;
        }
        break;
    case 47:
        if (gUnk_02039B84->unk_068 & 0x20000000) {
            break;
        }
        if (gUnk_02039B84->unk_068 & 0x40) {
            break;
        }
        func_0805DACC(work, 0x73, 48);
        break;
    case 48:
        func_0805DACC(work, 0x74, 49);
        break;
    case 49:
        func_0805DACC(work, 0x75, 50);
        break;
    case 50:
        func_0805DACC(work, 0x76, 51);
        break;
    case 51:
        func_0805DACC(work, 0x77, 52);
        break;
    case 52:
        func_0805DACC(work, 0x78, 53);
        break;
    case 53:
        func_0805DACC(work, 0x79, 54);
        break;
    case 54:
        func_0805DACC(work, 0x7A, 55);
        break;
    case 55:
        func_0805DACC(work, 0x7B, 56);
        break;
    case 56:
        func_0805DADC(work, 0x7C, 57);
        break;
    case 57:
        if (work->unk_00C == 0) {
            work->unk_00E = 0;
        }
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x8000000000ULL;
        }
        if (work->unk_00E == 0 && func_0807B3E0() != 0) {
            func_0805DAEC();
            work->unk_00E++;
        }
        if (func_0807B3E0() <= 2) {
            work->unk_00C++;
            break;
        }
        gUnk_02039B84->unk_068 |= 0x8000000000ULL;
        work->unk_00C = 0;
        work->unk_004 = 58;
        break;
    case 58:
        func_0805DACC(work, 0x7D, 59);
        break;
    case 59:
        func_0805DADC(work, 0x7E, 60);
        break;
    case 60:
        if (work->unk_00C == 0) {
            gUnk_02039B84->unk_068 |= 0x20000000000ULL;
            work->unk_000 &= ~2;
            work->unk_00E = 0;
        }
        if (work->unk_00C == 10) {
            gUnk_02039B84->unk_068 &= ~0x4000000000000ULL;
        }
        if (work->unk_000 & 2) {
            if (!(gUnk_02039B84->unk_068 & 0x20000000)) {
                work->unk_000 &= ~2;
                work->unk_00E++;
            }
        } else if (gUnk_02039B84->unk_068 & 0x20000000) {
            work->unk_000 |= 2;
            if (work->unk_00E == 0) {
                func_0805DAEC();
            }
        }
        if (work->unk_00E > 0) {
            gUnk_02039B84->unk_068 |= 0x4000000000000ULL;
            gUnk_02039B84->unk_068 &= ~0x20000000000ULL;
            func_0805DAF8(work, 30, 61);
        } else {
            work->unk_00C++;
        }
        break;
    case 61:
        func_0805DACC(work, 0x7F, 62);
        break;
    case 62:
        func_0805DACC(work, 0x80, 63);
        break;
    case 63:
        func_0805DAF8(work, 0x50, 64);
        break;
    case 42:
    case 64:
        gUnk_02039B84->unk_068 |= 0x200000000ULL;
        break;
    }
    return 1;
}

void task_tutorial_2(TutorialWork* work) {
    void* spr;
    u16 x;
    u16 y;
    s32 s;

    if (work->unk_000 & 4) {
        spr = func_08005A64(work->unk_020);
        if (work->unk_030 == 0) {
            x = work->unk_012;
            s = gUnk_08121400[(gUnk_03007480 << 3) & 0xFF];
            y = (s >> 7) + work->unk_014;
        } else {
            s = gUnk_08121400[(gUnk_03007480 << 3) & 0xFF];
            x = (s >> 7) + work->unk_012;
            y = work->unk_014;
        }
        func_080023E0(x, y, spr, work->unk_018, work->unk_01C, 0, 0x10, 0);
    }
}

void task_tutorial_3(TutorialWork* work) {
    func_080028C0(work->unk_018);
    func_08002C10(work->unk_01C);
    func_08006578(gUnk_03007480);
}

s16 func_0805E848(u16* widths, u16 count) {
    s16 i;
    s16 total;

    total = 0;
    for (i = 0; i < count; i++) {
        total += *widths;
        widths++;
    }
    if (total / 2 > 120) {
        total = 240;
    }
    return 120 - total / 2;
}

u16 func_0805E89C(u16* str) {
    s32 n;
    u16 c;

    n = 0;
    for (;;) {
        c = *str;
        if (c == 0) {
            return n;
        }
        if (c != 0x20) {
            n++;
        }
        str++;
    }
}
