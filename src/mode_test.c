#include "macros.h"
#include "mode_test.h"
#include "gba/keys.h"

void mode_test_0(void) {
    gUnk_02034A10 = 0;
    gUnk_02034A08 = LoadObjTiles(gUnk_08B24DAA, 0x7C0);
    gUnk_02034A0C = LoadObjPalette(gUnk_08F69BA4, 0x20);
}

void mode_test_1(void) {
    if (GetKeysRepeat() & DPAD_LEFT) {
        gUnk_02034A10--;
    } else if (GetKeysRepeat() & DPAD_RIGHT) {
        gUnk_02034A10++;
    }

    if (gUnk_02034A10 < 0) {
        gUnk_02034A10 = 0;
    }

    if (gUnk_02034A10 > 13) {
        gUnk_02034A10 = 13;
    }

    DrawSprite(120, 80, gUnk_09EE14D4[gUnk_02034A10], gUnk_02034A08, gUnk_02034A0C, 0, 0, 0);
}

void mode_test_2(void) {
    ReleaseObjTiles(gUnk_02034A08);
    ReleaseObjPalette(gUnk_02034A0C);
}

void func_0805F1C0(s32* p, s32 v) {
    *p += (v - *p) >> 1;
}

INCLUDE_ASM("mode_test/task_lockon_0.s");
INCLUDE_ASM("mode_test/task_lockon_1.s");
INCLUDE_ASM("mode_test/task_lockon_2.s");
INCLUDE_ASM("mode_test/task_lockon_3.s");

s32 func_0805F588(s32 a, s32 b) {
    return (u16)Sqrt(a * a + b * b);
}

s32 func_0805F5A4(s32* x, s32* y) {
    s32 d = func_0805F588(*x, *y);

    if (d > 0) {
        *x = (*x << 8) / d;
        *y = (*y << 8) / d;
    }

    return d;
}

INCLUDE_ASM("mode_test/func_0805F5D8.s");

void func_0805F66C(LockonWork* w) {
    s8 i;

    if ((gUnk_02039BA0->unk_70 & 2) == 0) {
        w->unk_2D = -1;

        for (i = 0; i < 8; i++) {
            w->unk_0C[i] = 0;
        }

        w->unk_2C = 0;
    }
}

INCLUDE_ASM("mode_test/func_0805F6B4.s");

void func_0805F728(s32* x, s32* y) {
    if (gUnk_02039DC4 != 0) {
        *x = (gUnk_02039DC4->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        *y = (gUnk_02039DC4->unk_04 >> 8) + (gUnk_02039DC4->unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 24;
    } else {
        *x = 0;
        *y = 0;
    }
}

void func_0805F770(void) {
    s32 a;
    s32 b;
    void* charBase = GetBgCharBase(0);
    void* screenBase = GetBgScreenBase(0);

    a = 0;
    CpuFastSet(&a, charBase, 0x01001500);
    b = 0;
    CpuFastSet(&b, screenBase, 0x01000140);
}

void func_0805F7B0(s32 a) {
    gUnk_02034A24 = a;
}

void func_0805F7BC(void) {
    func_0805F770();
}

void func_0805F7C8(u8 a) {
    gUnk_02034A2C = (u8*)GetBgCharBase(0) + (a << 12);
}

INCLUDE_ASM("mode_test/func_0805F7E8.s");
INCLUDE_ASM("mode_test/func_0805F8F0.s");
INCLUDE_ASM("mode_test/func_0805F904.s");
INCLUDE_ASM("mode_test/func_0805F93C.s");
INCLUDE_ASM("mode_test/func_0805FA60.s");
INCLUDE_ASM("mode_test/func_0805FA8C.s");
INCLUDE_ASM("mode_test/func_0805FB78.s");
INCLUDE_ASM("mode_test/func_0805FB84.s");
INCLUDE_ASM("mode_test/func_0805FC04.s");
INCLUDE_ASM("mode_test/func_0805FCB0.s");
INCLUDE_ASM("mode_test/func_08060470.s");

void func_08060598(void) {
    gUnk_02034A20 = 0;
}

INCLUDE_ASM("mode_test/func_080605A4.s");

void func_0806098C(void) {
    EwramFree(gUnk_02034A1C);
}

void func_080609A0(void) {
    func_0806098C();
}

INCLUDE_ASM("mode_test/func_080609AC.s");
INCLUDE_ASM("mode_test/func_08060A2C.s");
INCLUDE_ASM("mode_test/func_08060A74.s");
INCLUDE_ASM("mode_test/func_08060AD8.s");
INCLUDE_ASM("mode_test/func_08060BAC.s");
INCLUDE_ASM("mode_test/func_08060BBC.s");
INCLUDE_ASM("mode_test/func_08060C18.s");
INCLUDE_ASM("mode_test/func_08060E64.s");
INCLUDE_ASM("mode_test/func_08060EA0.s");
INCLUDE_ASM("mode_test/func_08060ED8.s");
INCLUDE_ASM("mode_test/func_08060F1C.s");
INCLUDE_ASM("mode_test/func_08060F64.s");
INCLUDE_ASM("mode_test/func_08060F74.s");
INCLUDE_ASM("mode_test/func_0806119C.s");
INCLUDE_ASM("mode_test/func_08061248.s");
INCLUDE_ASM("mode_test/func_080617E8.s");
