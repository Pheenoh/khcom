#include "unk_0802f1c8.h"

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
            gUnk_02039B84->unk_018 = 0;
        }
    }
}

s32 func_0802F268(void) {
    return gUnk_02034930;
}

void func_0802F274(s32 a, s32 b) {
    gUnk_02039B84->unk_010 = a;
    gUnk_02039B84->unk_014 = b;
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
    gUnk_02039B84->unk_010 = x;
    gUnk_02039B84->unk_014 = y + c;
}

s32 task_btl_map_1(BtlMapWork* work) {
    s32 dx;
    s32 dy;

    func_0802F208();

    if (gUnk_02039B84->unk_01A > 0) {
        func_0800592C(&gUnk_02039B84->unk_024, gUnk_02039B84->unk_028, gUnk_02039B84->unk_01A);
        func_0800592C(&gUnk_02039B84->unk_008, gUnk_02039B84->unk_01C, gUnk_02039B84->unk_01A);
        func_0800592C(&gUnk_02039B84->unk_00C, gUnk_02039B84->unk_020, gUnk_02039B84->unk_01A);

        if (gUnk_02039B84->unk_028 == 0x100) {
            func_0800592C(&work->unk_00, gUnk_02039B84->unk_0DA << 8, gUnk_02039B84->unk_01A);
            func_0800592C(&work->unk_04, gUnk_02039B84->unk_0DC << 8, gUnk_02039B84->unk_01A);
            func_0800592C(&work->unk_08, gUnk_02039B84->unk_0DE << 8, gUnk_02039B84->unk_01A);
            func_0800592C(&work->unk_0C, (gUnk_02039B84->unk_0E0 + 0x20) << 8, gUnk_02039B84->unk_01A);
        } else if (gUnk_02039B84->unk_028 > 0x100) {
            func_0800592C(&work->unk_00, 0x3000, gUnk_02039B84->unk_01A);
            func_0800592C(&work->unk_04, 0x1D000, gUnk_02039B84->unk_01A);
            func_0800592C(&work->unk_08, 0x9000, gUnk_02039B84->unk_01A);
            func_0800592C(&work->unk_0C, 0x1E800, gUnk_02039B84->unk_01A);
        }
        gUnk_02039B84->unk_01A--;
    } else if (gUnk_02039B84->unk_024 == 0x100) {
        dx = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
        dy = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;

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
        gUnk_02039B84->unk_008 += dx;
        gUnk_02039B84->unk_00C += dy;
    }
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;

    if (gUnk_0203492C != 0) {
        gUnk_02039B84->unk_018 = (gUnk_02034930 >> 8) / 3;
    }

    if (gUnk_02039B84->unk_000 - 0x7800 < work->unk_00) {
        gUnk_02039B84->unk_000 = work->unk_00 + 0x7800;
    } else if (gUnk_02039B84->unk_000 + 0x7800 > work->unk_04) {
        gUnk_02039B84->unk_000 = work->unk_04 - 0x7800;
    }

    if (gUnk_02039B84->unk_004 - 0x5000 < 0x9000) {
        gUnk_02039B84->unk_004 = 0xE000;
    } else if (gUnk_02039B84->unk_004 + 0x5000 > work->unk_0C) {
        gUnk_02039B84->unk_004 = work->unk_0C - 0x5000;
    }
    func_08005690(gUnk_02039B84->unk_1C6, gUnk_02039B84->unk_018, gUnk_02039B84->unk_024,
                  gUnk_02039B84->unk_024, gUnk_02039B84->unk_000,
                  gUnk_02039B84->unk_004 + 0x2800);
    return 1;
}
