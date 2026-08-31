#include "macros.h"
#include "mode_copyright2.h"

void mode_copyright2_0(s32 arg) {
    func_08004DB0();
    func_08005074(0, 0, 0x1F, 0);
    func_080055C8(0, 3);
    func_080050B8(0, gUnk_097E05B8, 0x4FC0);
    func_080050DC(0, gUnk_0984AC38, 0x200);
    func_0800510C(0, gUnk_09841F98, 0x800);

    if (arg == 0) {
        func_08006120(0, 0x43);
    } else {
        func_08006120(1, 0x43);
    }

    gUnk_02034EDC = 60;
}

void mode_copyright2_1(void) {
    if (!func_08006314()) {
        if (gUnk_02034EDC != 0) {
            if (--gUnk_02034EDC == 0) {
                func_08006184(0, 0x43);
            }
        } else {
            func_080010CC(&gUnk_09EF4E50, 0);
        }
    }
}

void mode_copyright2_2(void) {
}

u8* func_080D728C(u8* dst, s32 value, u16 digits) {
    u16 buf[6];
    s32 scale;
    s32 i;

    if (digits > 6) {
        digits = 6;
    }

    scale = 1;

    for (i = 0; i < digits; i++) {
        scale *= 10;
    }

    if (value > scale - 1) {
        value = scale - 1;
    } else if (value < 0) {
        value = 0;
    }

    for (i = 0; i < digits; i++) {
        buf[i] = (value % scale) / (scale / 10);
        scale /= 10;
    }

    for (i = 0; i < digits; i++) {
        func_080043B4(&gUnk_09801C98[buf[i] * 32], dst, 32);
        dst += 32;
    }

    return dst;
}

void func_080D733C(void) {
    u8* p;

    p = func_08005130(2) + 0x40;
    p = func_080D728C(p, gUnk_02039BB0.unk_108, 2);
    p = func_080D728C(p, gUnk_02039BB0.unk_032, 3);
    p = func_080D728C(p, gUnk_02039BB0.unk_0F8, 3);

    if (gUnk_02039BB0.unk_008 & 8) {
        p += 0x80;
    } else {
        p = func_080D728C(p, gUnk_02039BB0.unk_0FA, 4);
    }

    p = func_080D728C(p, gUnk_02039BB0.unk_100, 6);
    p = func_080D728C(p, gUnk_02039BB0.unk_104, 6);

    if (gUnk_02039BB0.unk_008 & 8) {
        p += 0xC0;
        p = func_080D728C(p, gUnk_02039BB0.unk_0FE, 2);
        func_080D728C(p, gUnk_02039BB0.unk_0FC, 3);
    } else {
        p += 0x20;
        func_080D728C(p, gUnk_02039BB0.unk_174, 5);
    }
}
