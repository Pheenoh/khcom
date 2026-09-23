#include "task_descriptors.h"
#include "btl.h"
#include "battle_backgrounds.h"

u8 gUnk_0203492C;
u16 gUnk_0203492E;
s32 gUnk_02034930;

const s8 gUnk_0813C7D8[32] = {
    4, 4, 4, 4, -4, -4, -4, -4, 3, 3, 3, 3, -3, -3, -3, -3, 2, 2, 2, 2, -2, -2, -2, -2, 1, 1, 1, 1, -1, -1, -1, -1,
};

const char gTaskNameBtlMap[] = "task_btl_map";

#ifdef VERSION_EU
extern u8 gUnkEu_08F7042C[];
extern u8 gUnkEu_08F7D724[];
#endif

void task_btl_map_0(BtlMapWork* work) {
    SetBgSize(gBtlWork->unk_1C6, 0x8000);

    if (gBtlWork->unk_068 & 0x800) {
        switch (gBtlWork->unk_10C) {
        case 0xB2:
        case 0xB3:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C78824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68624, 0xC0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EEF384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EEF384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 5;
            break;
        case 0xB1:
#ifdef VERSION_EU
            eu_080059D4(gBtlWork->unk_1C6, gUnk_08CBC6E4);
#else
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CBC6E4, 0x4000);
#endif
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69604, 0x120);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08F00384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08F00384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 5;
            break;
        case 0xA0:
#ifdef VERSION_EU
            eu_080059D4(gBtlWork->unk_1C6, gUnkEu_08F7042C);
#else
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CB06E4, 0x4000);
#endif
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69404, 0xC0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnkEu_08F7D724);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFD384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 0x9E:
#ifdef VERSION_EU
            eu_080059D4(gBtlWork->unk_1C6, gUnk_08CAC6E4);
#else
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CAC6E4, 0x4000);
#endif
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F692C4, 0x140);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EFC384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFC384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 9;
            break;
        case 0x9F:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C7C824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F686E4, 0xE0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF0384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF0384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 0xAC:
        case 0xAF:
#ifdef VERSION_EU
            eu_080059D4(gBtlWork->unk_1C6, gUnk_08CB86E4);
#else
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CB86E4, 0x4000);
#endif
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69544, 0xC0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EFF384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFF384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 0xA5:
#ifdef VERSION_EU
            eu_080059D4(gBtlWork->unk_1C6, gUnk_08CC06E4);
#else
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CC06E4, 0x4000);
#endif
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69724, 0x80);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08F01384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08F01384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 20;
            break;
        default:
#ifdef VERSION_EU
            eu_080059D4(gBtlWork->unk_1C6, gUnk_08CB46E4);
#else
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CB46E4, 0x4000);
#endif
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F694C4, 0x80);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EFE384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFE384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 20;
            break;
        }
    } else if (gBtlWork->unk_10C == 0x78) {
        LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C80824, 0x4000);
        LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F687C4, 0x140);
#ifdef VERSION_EU
        eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF1384);
#else
        LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF1384, 0x1000);
#endif
        gBtlWork->unk_0B3 = 10;
    } else {
        switch (gGameState.unk_00D) {
        case 1:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C84824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68904, 0xC0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF2384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF2384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 2:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C80824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F687C4, 0x140);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF1384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF1384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 3:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C90824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68B84, 0x100);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF5384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF5384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 4:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C88824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F689C4, 0xC0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF3384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF3384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 5:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C8C824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68A84, 0x100);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF4384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF4384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 7:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C94824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68C84, 0xE0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF6384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF6384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 5;
            break;
        case 8:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C98824, 0x3EC0);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68D64, 0x140);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF7384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF7384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 5;
            break;
        case 9:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C9C6E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68EA4, 0x120);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF8384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF8384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 10:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CA06E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68FC4, 0xE0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF9384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF9384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        case 11:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C78824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68624, 0xC0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EEF384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EEF384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 5;
            break;
        case 12:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CA86E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F691E4, 0xE0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EFB384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFB384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 20;
            break;
        case 13:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CA46E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F690A4, 0x140);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EFA384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFA384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 10;
            break;
        default:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C7C824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F686E4, 0xE0);
#ifdef VERSION_EU
            eu_080059F4(gBtlWork->unk_1C6, gUnk_08EF0384);
#else
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF0384, 0x1000);
#endif
            gBtlWork->unk_0B3 = 11;
            break;
        }
    }
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0x10000;
    gBtlWork->y = 0x16000;
    gBtlWork->unk_000 = 0x10000;
    gBtlWork->unk_004 = 0x16000;
    gBtlWork->x2 = 0x10000;
    gBtlWork->y2 = 0x16000;
    gBtlWork->unk_01C = 0x10000;
    gBtlWork->unk_020 = 0x16000;
    gBtlWork->unk_01A = 0;
    gBtlWork->unk_018 = 0;
    work->unk_00 = gBtlWork->unk_0DA << 8;
    work->unk_04 = gBtlWork->unk_0DC << 8;
    work->unk_08 = gBtlWork->unk_0DE << 8;
    work->unk_0C = (gBtlWork->unk_0E0 + 0x20) << 8;
    func_0802F1C8();
    SetBgAffine(gBtlWork->unk_1C6, gBtlWork->unk_018, gBtlWork->unk_024,
                gBtlWork->unk_024, gBtlWork->unk_000,
                gBtlWork->unk_004 + 0x2800);
}

void func_0802F1C8(void) {
    gUnk_0203492C = 0;
    gUnk_0203492E = 0;
    gUnk_02034930 = 0;
}

void func_0802F1E8(void) {
    gUnk_0203492C = 1;
    gUnk_0203492E = 0;
    gUnk_02034930 = 0;
}

void func_0802F208(void) {
    if (gUnk_0203492C != 0) {
        gUnk_02034930 += ((gUnk_0813C7D8[(s16)gUnk_0203492E] << 12) - gUnk_02034930) >> 3;
        gUnk_0203492E++;
        if (gUnk_0203492E > 0x1F) {
            gUnk_0203492C = 0;
            gUnk_02034930 = 0;
            gBtlWork->unk_018 = 0;
        }
    }
}

s32 func_0802F268(void) {
    return gUnk_02034930;
}

void func_0802F274(s32 a, s32 b) {
    gBtlWork->x2 = a;
    gBtlWork->y2 = b;
}

void func_0802F284(s32 a, s32 b, s32 c) {
    s32 x = (a + 0x10000) >> 1;
    s32 y = (b + 0x14400) >> 1;

    if (a - x > 0x3000) {
        x = a - 0x3000;
    } else if (x - a > 0x3000) {
        x = a + 0x3000;
    }

    if (b - y > 0x3000) {
        y = b - 0x3000;
    } else if (y - b > 0x3000) {
        y = b + 0x3000;
    }
    gBtlWork->x2 = x;
    gBtlWork->y2 = y + c;
}

s32 task_btl_map_1(BtlMapWork* work) {
    s32 dx;
    s32 dy;

    func_0802F208();

    if (gBtlWork->unk_01A > 0) {
        ApproachValueHalfSteps(&gBtlWork->unk_024, gBtlWork->unk_028, gBtlWork->unk_01A);
        ApproachValueHalfSteps(&gBtlWork->x, gBtlWork->unk_01C, gBtlWork->unk_01A);
        ApproachValueHalfSteps(&gBtlWork->y, gBtlWork->unk_020, gBtlWork->unk_01A);

        if (gBtlWork->unk_028 == 0x100) {
            ApproachValueHalfSteps(&work->unk_00, gBtlWork->unk_0DA << 8, gBtlWork->unk_01A);
            ApproachValueHalfSteps(&work->unk_04, gBtlWork->unk_0DC << 8, gBtlWork->unk_01A);
            ApproachValueHalfSteps(&work->unk_08, gBtlWork->unk_0DE << 8, gBtlWork->unk_01A);
            ApproachValueHalfSteps(&work->unk_0C, (gBtlWork->unk_0E0 + 0x20) << 8, gBtlWork->unk_01A);
        } else if (gBtlWork->unk_028 > 0x100) {
            ApproachValueHalfSteps(&work->unk_00, 0x3000, gBtlWork->unk_01A);
            ApproachValueHalfSteps(&work->unk_04, 0x1D000, gBtlWork->unk_01A);
            ApproachValueHalfSteps(&work->unk_08, 0x9000, gBtlWork->unk_01A);
            ApproachValueHalfSteps(&work->unk_0C, 0x1E800, gBtlWork->unk_01A);
        }
        gBtlWork->unk_01A--;
    } else if (gBtlWork->unk_024 == 0x100) {
        dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
        dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

        if (dx > 0x400) {
            dx = 0x400;
        } else if (dx < -0x400) {
            dx = -0x400;
        }

        if (dy > 0x400) {
            dy = 0x400;
        } else if (dy < -0x400) {
            dy = -0x400;
        }
        gBtlWork->x += dx;
        gBtlWork->y += dy;
    }
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gUnk_0203492C != 0) {
        gBtlWork->unk_018 = (gUnk_02034930 >> 8) / 3;
    }

    if (gBtlWork->unk_000 - 0x7800 < work->unk_00) {
        gBtlWork->unk_000 = work->unk_00 + 0x7800;
    } else if (gBtlWork->unk_000 + 0x7800 > work->unk_04) {
        gBtlWork->unk_000 = work->unk_04 - 0x7800;
    }

    if (gBtlWork->unk_004 - 0x5000 < 0x9000) {
        gBtlWork->unk_004 = 0xE000;
    } else if (gBtlWork->unk_004 + 0x5000 > work->unk_0C) {
        gBtlWork->unk_004 = work->unk_0C - 0x5000;
    }
    SetBgAffine(gBtlWork->unk_1C6, gBtlWork->unk_018, gBtlWork->unk_024,
                  gBtlWork->unk_024, gBtlWork->unk_000,
                  gBtlWork->unk_004 + 0x2800);
    return 1;
}

TaskDesc gTaskDescBtlMap = { gTaskNameBtlMap, task_btl_map_0, task_btl_map_1, 0, 0, 0x10 };
