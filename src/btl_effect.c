#include "display.h"
#include "macros.h"
#include "battle.h"
#include "btl_effect.h"

BgFx* gUnk_02034928;

void func_08012674(void) {
    if (gBtlWork->unk_068 & 4) {
        SetBgPriority(gUnk_02034928->unk_00, 0);
    } else {
        SetBgPriority(gUnk_02034928->unk_00, 1);
    }
    SetBgBlend(gUnk_02034928->unk_00, 16, 16);
    gUnk_02034928->unk_1C = 0x100;
    gUnk_02034928->unk_20 = 0x100;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_04 = 0;
    gUnk_02034928->unk_08 = 0;
    gUnk_02034928->unk_18 = 0;
    gUnk_02034928->unk_34 = 2;
    gUnk_02034928->unk_4C = 0;
}

u8 func_080126E4(u8 a) {
    if (BgAnimIsStopped()) {
        gUnk_02034928->unk_38 = a;
        return 0;
    }

    if (gUnk_02034928->unk_38 < a) {
        return 1;
    }
    gUnk_02034928->unk_38 = a;
    return 0;
}

void func_08012728(s16 a) {
    u16 b;
    u16 c;
    BgAnimGetFrameState(&b, &c);

    if (BgAnimGetDuration(BgAnimGetCurrent()) - b * c <= a) {
        gUnk_02034928->unk_34 &= ~2;
        gUnk_02034928->unk_38 = 2;

        if (gUnk_02034928->unk_34 & 8) {
            gUnk_02034928->unk_34 &= ~8;
            FadeToOriginal(0, 8);
        }
    }
}

void func_08012798(u16 a, u16 bg) {
    s32 i;
    gUnk_02034928 = EwramAlloc(0x50);

    for (i = 10; i < 16; i++) {
        FadeSetPaletteExcluded(i, 1);
    }

    if (a == 0) {
        func_080065FC(bg, 0xC000, 0);
    } else {
        func_080065FC(bg, 0x8000, 0x80);
    }
    SetBgBlend(bg, 16, 16);
    gUnk_02034928->unk_04 = 0;
    gUnk_02034928->unk_38 = 0xFF;
    gUnk_02034928->unk_00 = bg;
    func_08012674();
    gUnk_02034928->unk_34 = 0;
}

void func_08012810(void) {
    EwramFree(gUnk_02034928);
}

void func_08012824(void) {
    if (gBtlWork->unk_068 & 0x400000) {
        gBtlWork->unk_068 &= ~0x400000;
        gUnk_02034928->unk_34 &= 0xFFFD;
        gUnk_02034928->unk_04 = 0;
        BgAnimStop();
        SetBgBlend(gUnk_02034928->unk_00, 16, 16);
    }

    if (gUnk_02034928->unk_04 != 0) {
        gUnk_02034928->unk_04();

        if (!(gBtlWork->unk_068 & 4)) {
            gBtlWork->unk_0D0 = gUnk_02034928->unk_14;

            if (gUnk_02034928->unk_34 & 0x10) {
                SetBgPriority(gUnk_02034928->unk_00, 0);
            } else if (gUnk_02034928->unk_34 & 0x20) {
                SetBgPriority(gUnk_02034928->unk_00, 1);
                gBtlWork->unk_0D8 = 0xFF00;
            } else {
                gBtlWork->unk_0D8 = 8;
            }
        }
    }
    func_08006954();
}

u8 func_080128EC(void) {
    if (gUnk_02034928->unk_34 & 2) {
        return 1;
    }
    return 0;
}

void func_08012908(void) {
    s16 sx;
    s16 sy;

    if (BgAnimIsStopped()) {
        SetBgBlend(gUnk_02034928->unk_00, 16, 16);
        gUnk_02034928->unk_04 = 0;
        gUnk_02034928->unk_34 &= ~2;

        if (gUnk_02034928->unk_34 & 8) {
            FadeToOriginal(0, 8);
        }
        return;
    }

    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            if (gBtlWork->unk_068 & 2) {
                if (gBtlWork->unk_0B2 < func_080ABED0()) {
                    func_08012728(gUnk_02034928->unk_4C);
                }
            }
        } else if (gUnk_02039B9C->unk_068 & 2) {
            if (gUnk_02039B9C->unk_0B2 < func_080ABED0()) {
                func_08012728(gUnk_02034928->unk_4C);
            }
        }
    } else if (gBtlWork->unk_068 & 2) {
        if (gBtlWork->unk_0B2 < func_080ABED0()) {
            func_08012728(gUnk_02034928->unk_4C);
        }
    }

    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_080066F4(sx, sy);

    if (gUnk_02034928->unk_34 & 4) {
        func_0800675C(gUnk_02034928->unk_24 + gBtlWork->unk_018, gUnk_02034928->unk_1C, gUnk_02034928->unk_20);
    } else {
        s32 a = gUnk_02034928->unk_1C * gBtlWork->unk_024 >> 8;
        s32 b = gUnk_02034928->unk_20 * gBtlWork->unk_024 >> 8;

        func_0800675C(gUnk_02034928->unk_24 + gBtlWork->unk_018, a, b);
    }
}
void func_08012AAC(u16 a, s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_4C = 20;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;

    switch (a) {
    case 0:
        gUnk_02034928->unk_18 = z - 0x1400;
        break;
    case 1:
        gUnk_02034928->unk_18 = z;
        break;
    case 2:
        gUnk_02034928->unk_18 = z - 0x1000;
        break;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);

    switch (a) {
    case 0:
        func_08006778(gUnk_09EDA558, sx, sy);
        m4aSongNumStart(0x204);
        break;
    case 1:
        func_08006778(gUnk_09EDA840, sx, sy);
        m4aSongNumStart(0x205);
        break;
    case 2:
        func_08006778(gUnk_09EDA828, sx, sy);
        m4aSongNumStart(0x206);
        break;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
    gUnk_02034928->unk_04 = func_08012908;
}

void func_08012BCC(void) {
    SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

    if (gUnk_02034928->unk_08 > 15) {
        BgAnimStop();
    } else {
        gUnk_02034928->unk_08++;
    }
    func_08012908();
}

void func_08012C08(void) {
    u16 a;
    u16 b;
    u16 ang;
    s16 sx;
    s16 sy;
    s32 dx;

    BgAnimGetFrameState(&a, &b);
    dx = 0;

    if (gUnk_02034928->unk_08 > 0) {
        if (a > 7) {
            ang = gUnk_02034928->unk_24;

            if (gUnk_02034928->unk_34 & 1) {
                ApproachAngle(&ang, GetAngle(gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                                             gUnk_02034928->unk_28, gUnk_02034928->unk_2C) + 64, 5);
            } else {
                ApproachAngle(&ang, GetAngle(gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                                             gUnk_02034928->unk_28, gUnk_02034928->unk_2C) - 64, 5);
            }

            gUnk_02034928->unk_24 = ang;
            ApproachValue(&gUnk_02034928->unk_10, gUnk_02034928->unk_28, gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_14, gUnk_02034928->unk_2C, gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_18, gUnk_02034928->unk_30, gUnk_02034928->unk_08);

            if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                              gUnk_02034928->unk_18, 8, 8, 16)) {
                gUnk_02034928->unk_08 = -1;
            } else {
                gUnk_02034928->unk_08--;
            }
        } else if (a > 2) {
            if (gUnk_02034928->unk_34 & 1) {
                dx = ((7 - a) << 8) * 7;
            } else {
                s32 t = 7 - a;
                t *= 256;
                dx = t * -7;
            }

            if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 + dx,
                              gUnk_02034928->unk_14, gUnk_02034928->unk_18, 8, 8, 16)) {
                gUnk_02034928->unk_08 = -1;
            }
        }
    }

    if (gUnk_02034928->unk_08 == 0) {
        gUnk_02034928->unk_04 = func_08012BCC;
    } else if (gUnk_02034928->unk_08 == -1) {
        gUnk_02034928->unk_24 = 0;
        gUnk_02034928->unk_1C = 0x100;
        gUnk_02034928->unk_20 = 0x100;
        gUnk_02034928->unk_10 += dx;
        gUnk_02034928->unk_4C = 20;
        WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                      gUnk_02034928->unk_18);

        switch (gUnk_02034928->unk_26) {
        case 0:
            func_08006778(gUnk_09EDA5B8, sx, sy);
            m4aSongNumStart(0x1F9);
            break;
        case 1:
            func_08006778(gUnk_09EDA5E8, sx, sy);
            m4aSongNumStart(0x1FA);
            break;
        case 2:
            func_08006778(gUnk_09EDA858, sx, sy);
            m4aSongNumStart(0x1FB);
            break;
        default:
            func_08006778(gUnk_09EDA870, sx, sy);
            m4aSongNumStart(0x1FB);
            break;
        }

        gUnk_02034928->unk_08 = -2;
    }

    func_08012908();
}
void func_08012E44(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);

    if (a == 3) {
        func_08006778(gUnk_09EDA570 + 0x18, sx, sy);
    } else {
        func_08006778(gUnk_09EDA570, sx, sy);
    }

    if ((gBtlWork->unk_068 & 0x4000) == 0 && (gBtlWork->unk_068 & 0x40)) {
        m4aSongNumStart(0x23D);
    } else {
        m4aSongNumStart(0x1F8);
    }
    BgAnimSetLoopStartFrame(8);
    gUnk_02034928->unk_04 = func_08012C08;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_08 = 15;
    gUnk_02034928->unk_26 = a;
    gUnk_02034928->unk_48 = w;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08012F74(s32 x, s32 y, s32 z, u8 f, s32 unused, s32 w, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA570, sx, sy);
    m4aSongNumStart(0x23D);
    BgAnimSetLoopStartFrame(8);
    gUnk_02034928->unk_04 = func_08012C08;
    gUnk_02034928->unk_28 = gBtlWork->unk_07C->unk_004;
    gUnk_02034928->unk_2C = gBtlWork->unk_07C->unk_008;
    gUnk_02034928->unk_30 = gBtlWork->unk_07C->unk_00C;
    gUnk_02034928->unk_08 = a;
    gUnk_02034928->unk_26 = 1;
    gUnk_02034928->unk_48 = w;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x180;
    } else {
        gUnk_02034928->unk_1C = 0x180;
    }
    gUnk_02034928->unk_20 = 0x180;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08013070(void) {
    u16 a;
    u16 b;
    u16 angle;
    s16 sx;
    s16 sy;
    s32 dx;

    BgAnimGetFrameState(&a, &b);
    dx = 0;

    if (gUnk_02034928->unk_08 > 0) {
        if (a > 7) {
            angle = gUnk_02034928->unk_24;

            if (gUnk_02034928->unk_34 & 1) {
                ApproachAngle(&angle,
                    GetAngle(gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_28,
                        gUnk_02034928->unk_2C) + 64,
                    5);
            } else {
                ApproachAngle(&angle,
                    GetAngle(gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_28,
                        gUnk_02034928->unk_2C) - 64,
                    5);
            }
            gUnk_02034928->unk_24 = angle;
            ApproachValue(&gUnk_02034928->unk_10, gUnk_02034928->unk_28, gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_14, gUnk_02034928->unk_2C, gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_18, gUnk_02034928->unk_30, gUnk_02034928->unk_08);

            if (func_08011E3C(gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 8, 16, 16)) {
                gUnk_02034928->unk_08 = -1;
            } else {
                gUnk_02034928->unk_08--;
            }
        } else if (a > 2) {
            if (gUnk_02034928->unk_34 & 1) {
                dx = ((7 - a) << 8) * 7;
            } else {
                s32 t = 7 - a;
                t *= 256;
                dx = t * -7;
            }

            if (func_08011E3C(gUnk_02034928->unk_10 + dx, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 8, 16, 16)) {
                gUnk_02034928->unk_08 = -1;
            }
        }
    }

    if (gUnk_02034928->unk_08 == 0) {
        gUnk_02034928->unk_08 = -1;
    } else if (gUnk_02034928->unk_08 == -1) {
        gUnk_02034928->unk_24 = 0;
        gUnk_02034928->unk_1C = 0x100;
        gUnk_02034928->unk_20 = 0x100;
        gUnk_02034928->unk_10 += dx;
        gUnk_02034928->unk_4C = 20;
        WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);

        switch (gUnk_02034928->unk_26) {
        case 0:
            func_08006778(gUnk_09EDA6F0 + 0x18, sx, sy);
            m4aSongNumStart(0x1FD);
            break;
        case 1:
            func_08006778(gUnk_09EDA720 + 0x18, sx, sy);
            m4aSongNumStart(0x1FE);
            break;
        case 2:
        default:
            func_08006778(gUnk_09EDA720 + 0x30, sx, sy);
            m4aSongNumStart(0x1FF);
            break;
        }
        gUnk_02034928->unk_08 = -2;
    }

    if (gUnk_02034928->unk_08 == -2) {
        switch (gUnk_02034928->unk_26) {
        case 0:
            if (gUnk_02034928->unk_0A == 20) {
                func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                    gUnk_02034928->unk_18, 18, 18, 18);
            }
            break;
        case 1:
            if (gUnk_02034928->unk_0A == 35) {
                func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                    gUnk_02034928->unk_18, 24, 24, 30);
            }
            break;
        case 2:
        default:
            if (gUnk_02034928->unk_0A == 50) {
                func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                    gUnk_02034928->unk_18, 48, 48, 52);
            }
            break;
        }
        gUnk_02034928->unk_0A++;
    }
    func_08012908();
}
void func_08013308(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA6D8, sx, sy);

    if ((gBtlWork->unk_068 & 0x4000) == 0 && (gBtlWork->unk_068 & 0x40)) {
        m4aSongNumStart(0x23E);
    } else {
        m4aSongNumStart(0x1FC);
    }
    BgAnimSetLoopStartFrame(8);
    gUnk_02034928->unk_04 = func_08013070;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_08 = 15;
    gUnk_02034928->unk_26 = a;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_0A = 0;

    if (f) {
        gUnk_02034928->unk_1C = -0x100;
        gUnk_02034928->unk_34 |= 1;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_08013420(void) {
    gUnk_02034928->unk_1C += gUnk_02034928->unk_28;
    gUnk_02034928->unk_20 += gUnk_02034928->unk_2C;
    gUnk_02034928->unk_24 += 3;
    func_08012908();

    if (gUnk_02034928->unk_08 > 5) {
        s16 t = gUnk_02034928->unk_08 - 5;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            BgAnimStop();
        }
    }
    gUnk_02034928->unk_08++;
}

void func_08013480(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gUnk_02034928->unk_1C = 76;
    gUnk_02034928->unk_20 = 76;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_28 = 25;
    gUnk_02034928->unk_2C = 25;
    func_08006778(gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08013420;
    gUnk_02034928->unk_08 = 0;
}
void func_0801350C(void) {
    s16 t = gUnk_02034928->unk_08;

    gUnk_02034928->unk_24 += 4;
    gUnk_02034928->unk_1C += gUnk_02034928->unk_28;
    gUnk_02034928->unk_20 += gUnk_02034928->unk_2C;
    SetBlendAlpha(16, 16 - t);

    if (t > 15) {
        BgAnimStop();
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}
void func_08013560(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gUnk_02034928->unk_1C = 256;
    gUnk_02034928->unk_20 = 256;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_28 = 76;
    gUnk_02034928->unk_2C = 76;
    func_08006778(gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_0801350C;
    gUnk_02034928->unk_08 = 0;
}
void func_080135EC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gUnk_02034928->unk_1C = 128;
    gUnk_02034928->unk_20 = 128;
    gUnk_02034928->unk_24 = 0;
    func_08006778(gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08013420;
    gUnk_02034928->unk_08 = 0;
}
void func_08013678(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA630, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_080136E0(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDAD38, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_08013748(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;

    if (f != 0) {
        gUnk_02034928->unk_1C = -0x100;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA648, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_080137C8(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x + 0x400;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;

    if (f != 0) {
        gUnk_02034928->unk_1C = -0x100;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA648 + 0x18, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_08013854(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA678, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_080138BC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    gUnk_02034928->unk_20 = 0x200;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA5D0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_0801392C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA720, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_08013994(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA780, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_080139FC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA930, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_08013A68(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_4C = 20;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x3000;
    WorldToScreen(&sx, &sy, x, y, z - 0x3000);
    func_08006778(gUnk_09EDA6C0, sx, sy);
    m4aSongNumStart(0x207);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08013B00(void) {
    s16 sx;
    s16 sy;
    s16 sx2;
    s16 sy2;

    if (gUnk_02034928->unk_08 == 0 && BgAnimIsStopped()) {
        SetBlendAlpha(16, 16);
        gUnk_02034928->unk_10 = gBtlWork->unk_000;
        gUnk_02034928->unk_14 = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
        gUnk_02034928->unk_18 = gUnk_02034928->unk_30;
        WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
        gUnk_02034928->unk_24 = 0;
        gUnk_02034928->unk_4C = 20;
        gUnk_02034928->unk_34 |= 4;
        gUnk_02034928->unk_1C = 512;
        gUnk_02034928->unk_20 = (sy << 8) / 40;

        if (gUnk_02034928->unk_20 < 384) {
            gUnk_02034928->unk_20 = 384;
        }

        switch (gUnk_02034928->unk_26) {
        case 0:
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 256, 256);
            func_08006778(gUnk_09EDA798, sx, sy);
            m4aSongNumStart(0x201);
            break;
        case 1:
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 256, 256, 256);
            func_08006778(gUnk_09EDA7B0, sx, sy);
            m4aSongNumStart(0x202);
            break;
        case 2:
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 256, 256, 256);
            func_08006778(gUnk_09EDA7C8, sx, sy);
            m4aSongNumStart(0x203);
            break;
        }

        gUnk_02034928->unk_08 = 1;
    } else if (gUnk_02034928->unk_08 == 1) {
        s32 t;

        WorldToScreen(&sx2, &sy2, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
        t = sy2 << 8;
        gUnk_02034928->unk_20 = t / 40;

        if (gUnk_02034928->unk_20 < 384) {
            gUnk_02034928->unk_20 = 384;
        }
    }
    func_08012908();
}
void func_08013CB4(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_30 = p;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA768, sx, sy);
    m4aSongNumStart(0x200);
    gUnk_02034928->unk_48 = q;
    gUnk_02034928->unk_04 = func_08013B00;
    gUnk_02034928->unk_26 = a;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_08013D60(void) {
    u16 a;
    BgAnimGetFrameState(&a, 0);

    if (a > 3) {
        gUnk_02034928->unk_1C += 12;
        gUnk_02034928->unk_20 += 12;
        SetBlendAlpha(gUnk_02034928->unk_08, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08 += 2;
        }
    }
    func_08012908();
}

void func_08013DB8(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    SetBgBlend(gUnk_02034928->unk_00, 0, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA7F8, sx, sy);
    BgAnimSetLoopStartFrame(4);
    m4aSongNumStart(0x209);
    gUnk_02034928->unk_04 = func_08013D60;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}
void func_08013E4C(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    SetBgBlend(gUnk_02034928->unk_00, 0, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA810, sx, sy);
    m4aSongNumStart(0x227);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}

void func_08013EDC(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA9D8, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}

void func_08013F5C(s32 x, s32 y, s32 s, u16 b, u16 c) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    SetBgBlend(gUnk_02034928->unk_00, b, c);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = -0x1000;
    WorldToScreen(&sx, &sy, x, y, -0x1000);
    func_08006778(gUnk_09EDA810, sx, sy);
    m4aSongNumStart(0x227);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}

void func_08014000(void) {
    gUnk_02034928->unk_1C += 12;
    gUnk_02034928->unk_20 += 12;
    func_08012908();
}

void func_08014020(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA600, sx, sy);
    gUnk_02034928->unk_04 = func_08014000;
    m4aSongNumStart(0x22C);
    gUnk_02034928->unk_34 |= 0x10;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080140C0(s32* a, s32* b, s32* c) {
    *a = gUnk_02034928->unk_10;
    *b = gUnk_02034928->unk_14;
    *c = gUnk_02034928->unk_18;
}

void func_080140E0(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA8E8, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801416C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA888, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_080141D4(void) {
    BtlObj* p = gUnk_02034928->unk_44;
    gUnk_02034928->unk_10 = p->unk_004;
    gUnk_02034928->unk_14 = p->unk_008;
    gUnk_02034928->unk_18 = p->unk_00C - 0x800;
    func_08012908();
}

void func_080141FC(BtlObj* p) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_44 = p;
    gUnk_02034928->unk_10 = p->unk_004;
    gUnk_02034928->unk_14 = p->unk_008;
    gUnk_02034928->unk_18 = p->unk_00C - 0x800;
    gUnk_02034928->unk_1C = 0x133;
    gUnk_02034928->unk_20 = 0x133;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA768, sx, sy);
    BgAnimSetLoopStartFrame(4);
    gUnk_02034928->unk_04 = func_080141D4;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08014294(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 > 30) {
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        gUnk_02034928->unk_3C += 64;
        gUnk_02034928->unk_18 += gUnk_02034928->unk_3C;

        if (gUnk_02034928->unk_18 > 0) {
            gUnk_02034928->unk_18 = 0;
            gUnk_02034928->unk_26 = 2;
            gUnk_02034928->unk_08 = 30;
        }

        gUnk_02034928->unk_10 += (gUnk_02034928->unk_28 - gUnk_02034928->unk_10) >> 5;
        gUnk_02034928->unk_24 += 4;
        break;
    case 2:
        ApproachValue(&gUnk_02034928->unk_1C, 3, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_20, 3, gUnk_02034928->unk_08);
        gUnk_02034928->unk_08--;

        if (gUnk_02034928->unk_08 <= 0) {
            BgAnimStop();
            gUnk_02034928->unk_04 = 0;
        }
        break;
    }

    func_08011F78(256, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 32);
    func_08012908();
}
void func_0801435C(s32 x, s32 y, s32 z, s32 w, s32 v) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_28 = w;
    gUnk_02034928->unk_3C = v;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 0x299;
    gUnk_02034928->unk_20 = 0x299;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA768, sx, sy);
    BgAnimSetLoopStartFrame(4);
    gUnk_02034928->unk_04 = func_08014294;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_0801440C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        ApproachValue(&gUnk_02034928->unk_1C, gUnk_02034928->unk_28, gUnk_02034928->unk_0A);
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
        ApproachValue(&gUnk_02034928->unk_3C, 0x1000, gUnk_02034928->unk_0A);
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_36 != 0) {
            gUnk_02034928->unk_26 = 2;
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_0A = 16;
        }
        break;
    case 2:
        ApproachValue(&gUnk_02034928->unk_3C, 0, gUnk_02034928->unk_0A);
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 3;
            BgAnimStop();
        }
        break;
    }

    gUnk_02034928->unk_24 += gUnk_02034928->unk_0C;
    func_08012908();
}
void func_080144D8(s32 x, s32 y, s32 z, s32 w, u16 a, u16 b) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = w;
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_28 = w;
    gUnk_02034928->unk_3C = 0;
    gUnk_02034928->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAAE0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_0801440C;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_0C = b;
}
void func_08014588(s32 x, s32 y, s32 z, s32 w, s32 paramA, s32 paramB) {
    u16 a = paramA;
    u16 b = paramB;
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = w;
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_28 = w;
    gUnk_02034928->unk_3C = 0;
    gUnk_02034928->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA38, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_0801440C;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_0C = b;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08014654(void) {
    u16 t;
    s16 u;
    gUnk_02034928->unk_1C += 25;
    gUnk_02034928->unk_20 += 25;
    func_08012908();
    t = gUnk_02034928->unk_08;

    if (gUnk_02034928->unk_08 > 3) {
        u = t - 3;
        SetBlendAlpha(16, 16 - u);

        if (u > 15) {
            BgAnimStop();
        }
    }
    gUnk_02034928->unk_08++;
}
void func_080146A8(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, 0);
    gUnk_02034928->unk_1C = 512;
    gUnk_02034928->unk_20 = 768;
    gUnk_02034928->unk_24 = 0;
    func_08006778(gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08014654;
    gUnk_02034928->unk_08 = 0;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801475C(s32 a, s32 b, s32 c) {
    gUnk_02034928->unk_10 += a;
    gUnk_02034928->unk_14 += b;
    gUnk_02034928->unk_18 += c;
}

void func_08014780(s32 a, s32 b, s32 c) {
    gUnk_02034928->unk_10 = a;
    gUnk_02034928->unk_14 = b;
    gUnk_02034928->unk_18 = c;
}

void func_08014790(u8 bit) {
    gUnk_02034928->unk_36 |= 1 << bit;
}

void func_080147A8(s32 a, s32 b, s32 c) {
    gUnk_02034928->unk_28 = a;
    gUnk_02034928->unk_2C = b;
    gUnk_02034928->unk_30 = c;
}

void func_080147B8(u8 a) {
    gUnk_02034928->unk_24 = a;
}

void func_080147C8(s32 a, s32 b) {
    gUnk_02034928->unk_1C = a;
    gUnk_02034928->unk_20 = b;
}

void func_080147D8(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBgBlend(gUnk_02034928->unk_00, 5, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA900, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014850(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
#ifdef VERSION_EU
        if (gUnk_02034928->unk_08 == 20) {
#else
        if (gUnk_02034928->unk_08 == 21) {
#endif
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 48);
        }
        break;
    case 1:
#ifdef VERSION_EU
        if (gUnk_02034928->unk_08 == 20) {
#else
        if (gUnk_02034928->unk_08 == 25) {
#endif
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 24, 24, 48);
        }
        break;
    case 2:
        if (gUnk_02034928->unk_08 == 33) {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 48);
        }
        break;
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080148E0(u16 a, s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_4C = 20;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_26 = a;
    WorldToScreen(&sx, &sy, x, y, 0);

    switch (a) {
    case 0:
        func_08006778(gUnk_09EDA8A0, sx, sy);
        m4aSongNumStart(0x25C);
        break;
    case 1:
        func_08006778(gUnk_09EDA8B8, sx, sy);
        m4aSongNumStart(0x25D);
        break;
    case 2:
    default:
        func_08006778(gUnk_09EDA8D0, sx, sy);
        m4aSongNumStart(0x25E);
        break;
    }
    gUnk_02034928->unk_04 = func_08014850;
}

void func_080149BC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA948, sx, sy);
    BgAnimSetLoopStartFrame(8);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014A34(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA960, sx, sy);
    BgAnimSetLoopStartFrame(7);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014AAC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    m4aSongNumStart(0x20E);
    func_08006778(gUnk_09EDAA50, sx, sy);
    BgAnimSetLoopStartFrame(4);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014B30(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA7E0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}
void func_08014BA8(void) {
    s16 sx;
    s16 sy;
    s16 t;
    u8 r;

    t = gUnk_02034928->unk_08 % 8;

    if (t <= 3) {
        SetBlendAlpha(t, 16);
    } else {
        SetBlendAlpha(8 - t, 16);
    }

    if (gUnk_02034928->unk_0A == 0 && BgAnimIsStopped()) {
        gUnk_02034928->unk_10 = gUnk_02034928->unk_28;
        gUnk_02034928->unk_14 = gUnk_02034928->unk_2C;
        gUnk_02034928->unk_18 = gUnk_02034928->unk_30;
        WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_10, gUnk_02034928->unk_18);
        gUnk_02034928->unk_24 = 0;
        gUnk_02034928->unk_4C = 20;

        switch (gUnk_02034928->unk_26) {
        case 0:
            gUnk_02034928->unk_28 = 128;
            gUnk_02034928->unk_2C = 128;
            func_08006778(gUnk_09EDA990, sx, sy);
            break;
        case 1:
            gUnk_02034928->unk_28 = 256;
            gUnk_02034928->unk_2C = 256;
            func_08006778(gUnk_09EDA990, sx, sy);
            break;
        case 2:
        default:
            gUnk_02034928->unk_28 = 512;
            gUnk_02034928->unk_2C = 512;
            func_08006778(gUnk_09EDA990, sx, sy);
            break;
        }

        if (gUnk_02034928->unk_34 & 1) {
            gUnk_02034928->unk_28 = -gUnk_02034928->unk_28;
        }

        m4aSongNumStart(0x233);
        gUnk_02034928->unk_0A++;
    } else if (gUnk_02034928->unk_0A == 1) {
        if (gUnk_02034928->unk_08 <= 29) {
            ApproachValue(&gUnk_02034928->unk_1C, gUnk_02034928->unk_28, 30 - gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_20, gUnk_02034928->unk_2C, 30 - gUnk_02034928->unk_08);
        }

        if (gUnk_02034928->unk_08 == 35) {
            switch (gUnk_02034928->unk_26) {
            case 0:
                r = func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 24, 12, 256);
                break;
            case 1:
                r = func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 40, 20, 256);
                break;
            case 2:
            default:
                r = func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 80, 40, 256);
                break;
            }

            if (r) {
                m4aSongNumStart(0x234);
            }
        }

        gUnk_02034928->unk_08++;
    }
    func_08012908();
}

void func_08014D78(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(2, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_48 = w;

    if (f != 0) {
        gUnk_02034928->unk_1C = -gUnk_02034928->unk_1C;
        gUnk_02034928->unk_34 |= 1;
    }
    gUnk_02034928->unk_0A = 0;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA978, sx, sy);
    m4aSongNumStart(0x232);
    gUnk_02034928->unk_26 = a;
    gUnk_02034928->unk_04 = func_08014BA8;
}

void func_08014E38(void) {
    s16 t = gUnk_02034928->unk_08 % 8;
    if (t <= 3) {
        SetBlendAlpha(t, 16);
    } else {
        SetBlendAlpha(8 - t, 16);
    }

    if (gUnk_02034928->unk_08 == 0x23) {
        if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 40, 20, 256)) {
            m4aSongNumStart(0x234);
        }
    }
    func_08012908();
    gUnk_02034928->unk_08++;
}

void func_08014EC0(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(2, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_0A = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA990, sx, sy);
    m4aSongNumStart(0x233);
    gUnk_02034928->unk_04 = func_08014E38;
}

void func_08014F4C(void) {
    gUnk_02034928->unk_1C += 0x80;
    gUnk_02034928->unk_20 += 0x80;
    gUnk_02034928->unk_24 += 3;

    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_10 += -0x300;
    } else {
        gUnk_02034928->unk_10 += 0x300;
    }
    func_08012908();
    SetBlendAlpha(16, 8 - gUnk_02034928->unk_0A);

    if (gUnk_02034928->unk_0A > 7) {
        BgAnimStop();
    }

    if (gUnk_02034928->unk_08 % 5 == 0) {
        gUnk_02034928->unk_0A++;
    }
    gUnk_02034928->unk_08++;
}

void func_08014FDC(s32 x, s32 y, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y - 0x1000;
    SetBlendAlpha(16, 8);

    if (f) {
        gUnk_02034928->unk_34 |= 1;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, 0);
    gUnk_02034928->unk_1C = 128;
    gUnk_02034928->unk_20 = 128;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_0A = 0;
    func_08006778(gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08014F4C;
    gUnk_02034928->unk_08 = 0;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_0801508C(void) {
    if (gUnk_02034928->unk_08 > 19) {
        gUnk_02034928->unk_0A = (gUnk_02034928->unk_08 - 20) / 2;
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_0A);

        if (gUnk_02034928->unk_0A > 15) {
            BgAnimStop();
        }
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080150D8(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = 0x100;
    gUnk_02034928->unk_20 = 0x100;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA9C0, sx, sy);
    gUnk_02034928->unk_04 = func_0801508C;
    m4aSongNumStart(0x262);

    if (f == 0) {
        gUnk_02034928->unk_34 |= 1;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
    BgAnimSetLoopStartFrame(3);
}

void func_0801519C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}

void func_08015228(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 30;
    func_08006778(gUnk_09EDA9F0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_0801519C;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080152DC(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 > 30) {
            FadeStartOut(2, 60);
            FadeLock();
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (FadeIsActive() == 0) {
            BgAnimStop();
            FadeStartIn(2, 120);
            FadeLock();
            gUnk_02034928->unk_04 = 0;
            gUnk_02034928->unk_34 &= ~2;
        }
        break;
    }
    func_0800675C(0, gUnk_02034928->unk_1C, gUnk_02034928->unk_20);
    gUnk_02034928->unk_1C += 20;
    gUnk_02034928->unk_20 += 20;
}

void func_0801536C(void) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 0x19;
    gUnk_02034928->unk_20 = 0x19;
    func_08006778(gUnk_09EDAA20, 0x78, 0x50);
    BgAnimSetLoopStartFrame(0);
    m4aSongNumStart(0x27B);
    gUnk_02034928->unk_04 = func_080152DC;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_080153C8(void) {
    s16 t;
    s16 u;

    switch (gUnk_02034928->unk_26) {
    case 0:
        t = gUnk_02034928->unk_08;
        SetBlendAlpha(16, t);
        ApproachValueHalfSteps(&gUnk_02034928->unk_1C, 0x100, 17 - t);
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;

        if (t > 15) {
            gUnk_02034928->unk_08 = gUnk_02034928->unk_0A;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        ApproachValue(&gUnk_02034928->unk_10, gUnk_02034928->unk_28, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_14, gUnk_02034928->unk_2C, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_18, gUnk_02034928->unk_30, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_1C, gUnk_02034928->unk_3C, gUnk_02034928->unk_08);
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
        u = (gUnk_02034928->unk_1C * 3) >> 6;

        if (gUnk_02034928->unk_08 <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, u, u, u)) {
            m4aSongNumStart(0x27F);
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08--;
        }
        break;
    case 2:
        t = gUnk_02034928->unk_08;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_1C += 7;
            gUnk_02034928->unk_20 += 7;
            gUnk_02034928->unk_18 -= gUnk_02034928->unk_1C;
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_080154F4(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s, u16 a, s32 t) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_0A = a;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA08, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_1C = 25;
    gUnk_02034928->unk_20 = 25;
    gUnk_02034928->unk_04 = func_080153C8;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_48 = s;
    gUnk_02034928->unk_3C = t;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080155BC(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    s32 t;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    t = sy << 8;
    gUnk_02034928->unk_1C = 384;
    gUnk_02034928->unk_20 = t / 40;
    if (gUnk_02034928->unk_20 < 384) {
        gUnk_02034928->unk_20 = 384;
    }
    func_08006778(gUnk_09EDA798, sx, sy);
    m4aSongNumStart(0x201);
    func_08011F78(w, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 256);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08015698(void) {
    s16 sx;
    s16 sy;
    s16 sx2;
    s16 sy2;

    if (gUnk_02034928->unk_08 == 0 && BgAnimIsStopped()) {
        SetBlendAlpha(16, 16);
        gUnk_02034928->unk_10 = gUnk_02034928->unk_28;
        gUnk_02034928->unk_14 = gUnk_02034928->unk_2C;
        gUnk_02034928->unk_18 = gUnk_02034928->unk_30;
        WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
        gUnk_02034928->unk_24 = 0;
        gUnk_02034928->unk_1C = 384;
        gUnk_02034928->unk_20 = (sy << 8) / 40;

        if (gUnk_02034928->unk_20 < 384) {
            gUnk_02034928->unk_20 = 384;
        }

        gUnk_02034928->unk_34 |= 4;

        switch (gUnk_02034928->unk_26) {
        case 0:
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 256);
            func_08006778(gUnk_09EDA798, sx, sy);
            m4aSongNumStart(0x201);
            break;
        case 1:
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 40, 40, 256);
            func_08006778(gUnk_09EDA7B0, sx, sy);
            m4aSongNumStart(0x202);
            break;
        case 2:
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 64, 64, 256);
            func_08006778(gUnk_09EDA7C8, sx, sy);
            m4aSongNumStart(0x203);
            break;
        }

        gUnk_02034928->unk_08 = 1;
    } else if (gUnk_02034928->unk_08 == 1) {
        s32 t;

        WorldToScreen(&sx2, &sy2, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
        t = sy2 << 8;
        gUnk_02034928->unk_20 = t / 40;

        if (gUnk_02034928->unk_20 < 384) {
            gUnk_02034928->unk_20 = 384;
        }
    }
    func_08012908();
}
void func_08015834(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA768, sx, sy);
    m4aSongNumStart(0x200);
    gUnk_02034928->unk_48 = s;
    gUnk_02034928->unk_04 = func_08015698;
    gUnk_02034928->unk_26 = a;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080158E8(void) {
    s32 t;
    u16 v;

    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 == 0) {
            gUnk_02034928->unk_0A = 40;
        }
        ApproachValue(&gUnk_02034928->unk_3C, 0x1000, gUnk_02034928->unk_0A);
        ApproachValue(&gUnk_02034928->unk_1C, gUnk_02034928->unk_28, gUnk_02034928->unk_0A);
        ApproachValue(&gUnk_02034928->unk_20, 0x100, gUnk_02034928->unk_0A);
        ApproachValue(&gUnk_02034928->unk_40, 0, gUnk_02034928->unk_0A);
        gUnk_02034928->unk_24 = gUnk_02034928->unk_40 >> 8;
        t = gUnk_02034928->unk_1C;

        if (t < 0) {
            t = -t;
        }
        t *= 44;

        if (gUnk_02034928->unk_34 & 1) {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 + t, gUnk_02034928->unk_14,
                gUnk_02034928->unk_18, t << 8 >> 16, 24, 24);
        } else {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 - t, gUnk_02034928->unk_14,
                gUnk_02034928->unk_18, t << 8 >> 16, 24, 24);
        }
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);

        if (--gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        v = gUnk_02034928->unk_08;

        if (gUnk_02034928->unk_08 > 50) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
            break;
        }
        t = gUnk_02034928->unk_1C;

        if (t < 0) {
            t = -t;
        }
        t *= 44;

        if (gUnk_02034928->unk_34 & 1) {
            gUnk_02034928->unk_40 = -gSineTable[(v * 4) & 0xFF] * 6;
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 + t, gUnk_02034928->unk_14,
                gUnk_02034928->unk_18, t << 8 >> 16, 24, 24);
        } else {
            gUnk_02034928->unk_40 = gSineTable[(v * 4) & 0xFF] * 6;
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 - t, gUnk_02034928->unk_14,
                gUnk_02034928->unk_18, t << 8 >> 16, 24, 24);
        }
        gUnk_02034928->unk_24 = gUnk_02034928->unk_40 >> 8;
        gUnk_02034928->unk_08++;
        break;
    case 2:
        if (gUnk_02034928->unk_08 == 0) {
            gUnk_02034928->unk_0A = 20;
        }
        ApproachValue(&gUnk_02034928->unk_3C, 0, gUnk_02034928->unk_0A);
        ApproachValue(&gUnk_02034928->unk_20, 128, gUnk_02034928->unk_0A);

        if (gUnk_02034928->unk_34 & 1) {
            ApproachValue(&gUnk_02034928->unk_1C, -128, gUnk_02034928->unk_0A);
            ApproachValue(&gUnk_02034928->unk_40, 0x800, gUnk_02034928->unk_0A);
        } else {
            ApproachValue(&gUnk_02034928->unk_1C, 128, gUnk_02034928->unk_0A);
            ApproachValue(&gUnk_02034928->unk_40, -0x800, gUnk_02034928->unk_0A);
        }
        gUnk_02034928->unk_24 = gUnk_02034928->unk_40 >> 8;
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);

        if (--gUnk_02034928->unk_0A <= 0) {
            BgAnimStop();
            gUnk_02034928->unk_26 = 99;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }

    func_08012908();
}
void func_08015B50(u16 a, s32 x, s32 y, s32 z, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);

    if (f) {
        gUnk_02034928->unk_34 |= 1;
    }

    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_20 = 25;

    switch (a) {
    case 0:
        gUnk_02034928->unk_28 = 256;
        break;
    case 1:
        gUnk_02034928->unk_28 = 384;
        break;
    case 2:
        gUnk_02034928->unk_28 = 512;
        break;
    }

    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_1C = -25;
        gUnk_02034928->unk_40 = 2048;
        gUnk_02034928->unk_28 = -gUnk_02034928->unk_28;
    } else {
        gUnk_02034928->unk_1C = 25;
        gUnk_02034928->unk_40 = -2048;
    }

    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_3C = 0;
    func_08006778(gUnk_09EDAA68, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_080158E8;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08015C80(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_1C = 76;
    gUnk_02034928->unk_20 = 76;
    gUnk_02034928->unk_28 = 12;
    gUnk_02034928->unk_2C = 12;
    func_08006778(gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08013420;
}
void func_08015D04(void) {
    if (gUnk_02034928->unk_08 <= 16) {
        SetBlendAlpha(16, gUnk_02034928->unk_08);
        gUnk_02034928->unk_08++;
    }
    func_08012908();
}
void func_08015D30(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = 0x100;
    gUnk_02034928->unk_20 = 0x100;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_34 |= 0x20;
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_26 = 0;
    func_08006778(gUnk_09EDAA80, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08015D04;
}
void func_08015DC8(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_1C = 0x200;
    gUnk_02034928->unk_20 = 0x200;
    BgAnimSetLoopStartFrame(7);
    func_08006778(gUnk_09EDAA98, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_08015E3C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0: {
        u16 t = gUnk_02034928->unk_08;

        if ((s16)t <= 64) {
            SetBlendAlpha(16, (s16)t >> 2);
            gUnk_02034928->unk_08++;
        } else {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26++;
        }
        gUnk_02034928->unk_1C += 25;
        gUnk_02034928->unk_20 += 25;
        break;
    }
    case 1: {
        u16 t;

        gUnk_02034928->unk_1C += 0x100;
        gUnk_02034928->unk_20 += 0x100;
        t = gUnk_02034928->unk_08;

        if ((s16)t > 32) {
            func_08011F78(87, gUnk_02034928->unk_10, gUnk_02034928->unk_14, 0, 0x100, 0x100, 0x100);
            func_08019050(1, 0x100, gBtlWork->unk_010, gBtlWork->unk_014);
            FadeStartIn(2, 60);
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26++;
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    case 2: {
        u16 t = gUnk_02034928->unk_08;

        if ((s16)t <= 15) {
            SetBlendAlpha(16, 16 - t);
            gUnk_02034928->unk_08++;
        } else {
            BgAnimStop();
        }
        break;
    }
    }
    gUnk_02034928->unk_24++;
    func_08012908();
}
void func_08015F3C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    SetBlendAlpha(16, 0);
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    gUnk_02034928->unk_1C = 0x300;
    gUnk_02034928->unk_20 = 0x300;
    func_08006778(gUnk_09EDAAB0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_08 = 8;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_34 |= 0x10;
    gUnk_02034928->unk_04 = func_08015E3C;
    FadeStartOut(2, 40);
    func_08019050(80, 204, x, y + z + 0x2000);
}

void func_08015FF4(void) {
    if (gUnk_02034928->unk_08 > 0) {
        ApproachValueHalfSteps(&gUnk_02034928->unk_1C, 0x100, gUnk_02034928->unk_08);
        ApproachValueHalfSteps(&gUnk_02034928->unk_20, 0x100, gUnk_02034928->unk_08);
        gUnk_02034928->unk_08--;
    }
    func_08012908();
}

void func_08016038(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_1C = 0x19;
    gUnk_02034928->unk_20 = 0x19;
    m4aSongNumStart(0x27C);
    func_08006778(gUnk_09EDAAC8, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_08 = 0x23;
    gUnk_02034928->unk_04 = func_08015FF4;
}

void func_080160C0(void) {
    u16 k;
    u16 v;
    s16 t;

    BgAnimGetFrameState(&k, &v);

    switch (k) {
    case 4:
        func_08011F78(91, gUnk_02034928->unk_10 + gUnk_02034928->unk_1C * 40, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 50);
        break;
    case 5:
        if (v == 0) {
            gUnk_02034928->unk_26 = 1;
        }
        break;
    case 6:
        if (v == 0) {
            gUnk_02034928->unk_26 = 2;
        }
        break;
    }

    switch (gUnk_02034928->unk_26) {
    case 1:
        gUnk_02034928->unk_3C += 51;

        if (gUnk_02034928->unk_34 & 1) {
            gUnk_02034928->unk_10 -= gUnk_02034928->unk_3C;
        } else {
            gUnk_02034928->unk_10 += gUnk_02034928->unk_3C;
        }
        break;
    case 2:
        gUnk_02034928->unk_3C += 51;

        if (gUnk_02034928->unk_34 & 1) {
            gUnk_02034928->unk_10 -= gUnk_02034928->unk_3C;
            gUnk_02034928->unk_1C -= 51;
        } else {
            gUnk_02034928->unk_10 += gUnk_02034928->unk_3C;
            gUnk_02034928->unk_1C += 51;
        }
        func_08011F78(91, gUnk_02034928->unk_10 + gUnk_02034928->unk_1C * 40, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 50);

        if (gUnk_02034928->unk_08 > 20) {
            t = 36 - gUnk_02034928->unk_08;
            SetBlendAlpha(16, t);

            if (t <= 0) {
                BgAnimStop();
            }
        }
        gUnk_02034928->unk_08++;
        break;
    }
    func_08012908();
}
void func_080161F8(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_26 = 0;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
    }
    gUnk_02034928->unk_3C = 0;
    m4aSongNumStart(0x27D);
    func_08006778(&gUnk_09EDAAC8[0x30], sx, sy);
    BgAnimSetLoopStartFrame(6);
    gUnk_02034928->unk_04 = func_080160C0;
}

void func_080162A8(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA20, sx, sy);
    gUnk_02034928->unk_1C = w;
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_04 = func_08012BCC;
}

BtlObj* func_08016320(void) {
    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            return gBtlWork->unk_07C;
        }
        return gUnk_02039B9C->unk_07C;
    }

    if (gBtlWork->unk_078 != 0) {
        return gBtlWork->unk_078;
    }
    return ListPoolFirst(&gBtlWork->unk_080);
}

void func_08016374(s16 a) {
    BtlObj* o;

    if (gBtlWork->unk_068 & 0x4000) {
        if (GetRandom() % 5) {
            if (gBtlWork->unk_068 & 0x20000000) {
                func_08019190(gBtlWork->unk_07C, 2);
            } else {
                func_08019190(gUnk_02039B9C->unk_07C, 2);
            }
        } else {
            o = gUnk_02039B9C->unk_07C;
            o->unk_02C = a;

            if (a > o->unk_02E) {
                o->unk_02C = o->unk_02E;
            }
            o = gBtlWork->unk_07C;
            o->unk_02C = a;

            if (a > o->unk_02E) {
                o->unk_02C = o->unk_02E;
            }
        }
    } else {
        o = ListPoolFirst(&gBtlWork->unk_080);

        while (o != 0) {
            if (o->unk_034 & 0x40000000) {
                func_08019190(o, 0);
            } else {
                o->unk_02C = a;

                if (a > o->unk_02E) {
                    o->unk_02C = o->unk_02E;
                }
            }
            o = ListPoolNext(&o->unk_0B8);
        }
    }
}
void func_08016468(void) {
    BtlObj* o;

    switch (gUnk_02034928->unk_26) {
    case 0:
        gUnk_02034928->unk_1C = (gSineTable[((u16)gUnk_02034928->unk_08 * 4) & 0xFF] >> 3) + 89;

        if (gUnk_02034928->unk_0A > 0) {
            ApproachValueHalfSteps(&gUnk_02034928->unk_18, gUnk_02034928->unk_30 - 0x2000, gUnk_02034928->unk_0A);
            gUnk_02034928->unk_0A--;
        } else {
            gUnk_02034928->unk_26 = 1;
            gUnk_02034928->unk_0A = 60;
        }
        break;
    case 1:
        gUnk_02034928->unk_1C = (gSineTable[((u16)gUnk_02034928->unk_08 * 4) & 0xFF] >> 3) + 89;
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_26 = 2;
            gUnk_02034928->unk_0A = 50;
        }
        break;
    case 2:
        gUnk_02034928->unk_1C = (gSineTable[((u16)gUnk_02034928->unk_08 * 4) & 0xFF] >> 3) + 89;
        o = func_08016320();

        if (o != 0) {
            ApproachValueHalfSteps(&gUnk_02034928->unk_10, o->unk_004, gUnk_02034928->unk_0A);
            ApproachValueHalfSteps(&gUnk_02034928->unk_14, o->unk_008, gUnk_02034928->unk_0A);
            ApproachValueHalfSteps(&gUnk_02034928->unk_18, o->unk_00C - (o->unk_0A2 << 8), gUnk_02034928->unk_0A);
        }
        gUnk_02034928->unk_0A--;

        if (o != 0) {
            if (gUnk_02034928->unk_0A > 0) {
                break;
            }
            func_08016374(o->unk_02C);
        }
        gUnk_02034928->unk_26 = 3;
        m4aSongNumStart(0x298);
        gUnk_02034928->unk_0A = 16;
        break;
    case 3:
        gUnk_02034928->unk_1C += 166;
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
        SetBlendAlpha(16, gUnk_02034928->unk_0A);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            BgAnimStop();
        }
        break;
    }
    gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
    gUnk_02034928->unk_08++;
    func_08012908();
}
void func_080165DC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_30 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 50;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA20, sx, sy);
    gUnk_02034928->unk_1C = 89;
    gUnk_02034928->unk_20 = 89;
    gUnk_02034928->unk_04 = func_08016468;
    m4aSongNumStart(0x297);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08016684(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB70, sx, sy);
    gUnk_02034928->unk_1C = 0x200;
    gUnk_02034928->unk_20 = 0x200;
    gUnk_02034928->unk_04 = func_08012908;
}

void func_080166F8(void) {
    gUnk_02034928->unk_1C += gUnk_02034928->unk_28;
    gUnk_02034928->unk_20 += gUnk_02034928->unk_2C;
    func_08012908();

    if (gUnk_02034928->unk_08 > 5) {
        s16 t = gUnk_02034928->unk_08 - 5;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            BgAnimStop();
        }
    }
    gUnk_02034928->unk_08++;
}

void func_08016750(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA20, sx, sy);
    gUnk_02034928->unk_1C = 38;
    gUnk_02034928->unk_20 = 256;
    gUnk_02034928->unk_28 = 7;
    gUnk_02034928->unk_2C = 153;

    if (f) {
        gUnk_02034928->unk_24 += 40;
    } else {
        gUnk_02034928->unk_24 -= 40;
    }
    gUnk_02034928->unk_04 = func_080166F8;
}
void func_080167F8(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, (gUnk_02034928->unk_08 >> 1) + 8);
        ApproachValueHalfSteps(&gUnk_02034928->unk_1C, gUnk_02034928->unk_28, 17 - gUnk_02034928->unk_08);
        ApproachValueHalfSteps(&gUnk_02034928->unk_20, gUnk_02034928->unk_2C, 17 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_080168B8(s32 x, s32 y, s32 z, u8 f, s32 w, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_26 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB10, sx, sy);

    if (f) {
        gUnk_02034928->unk_28 = w;
        gUnk_02034928->unk_1C = 76;
    } else {
        gUnk_02034928->unk_28 = -w;
        gUnk_02034928->unk_1C = -76;
    }
    gUnk_02034928->unk_2C = w;
    gUnk_02034928->unk_20 = 76;
    m4aSongNumStart(0x282);
    gUnk_02034928->unk_04 = func_080167F8;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080169A0(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 45;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB40, sx, sy);

    if (f) {
        gUnk_02034928->unk_1C = -0x100;
    } else {
        gUnk_02034928->unk_1C = 0x100;
    }
    gUnk_02034928->unk_20 = 0x100;
    gUnk_02034928->unk_04 = func_0801519C;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_08016A64(void) {
    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_10 += 0x700;
    } else {
        gUnk_02034928->unk_10 += -0x700;
    }

    if (gUnk_02034928->unk_10 < (gBtlWork->unk_0DA - 0x40) << 8 || gUnk_02034928->unk_10 > (gBtlWork->unk_0DC + 0x40) << 8) {
        BgAnimStop();
    } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 48)) {
        m4aSongNumStart(0x27F);
    }
    func_08012908();
}

void func_08016AF4(s32 x, s32 y, s32 z, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB40 + 0x18, sx, sy);

    if (f) {
        gUnk_02034928->unk_1C = 0x100;
    } else {
        gUnk_02034928->unk_1C = -0x100;
        gUnk_02034928->unk_34 |= 1;
    }
    gUnk_02034928->unk_20 = 0x100;
    m4aSongNumStart(0x27E);
    gUnk_02034928->unk_04 = func_08016A64;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08016BCC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA888, sx, sy);
    gUnk_02034928->unk_1C = 0x900;
    gUnk_02034928->unk_20 = 0x900;
    gUnk_02034928->unk_04 = func_08012908;
}
void func_08016C40(s32 x, s32 y, s32 z, s32 w, u8 f, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_24 = f;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDAB28, sx, sy);
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_04 = func_0801519C;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08016D00(void) {
    u16 a;
    u16 b;
    u16 ang;
    s16 sx;
    s16 sy;
    s32 dx;

    BgAnimGetFrameState(&a, &b);
    dx = 0;

    if (gUnk_02034928->unk_08 > 0) {
        if (a > 7) {
            ang = gUnk_02034928->unk_24;

            if (gUnk_02034928->unk_34 & 1) {
                ApproachAngle(&ang, GetAngle(gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                                             gUnk_02034928->unk_28, gUnk_02034928->unk_2C) + 64, 5);
            } else {
                ApproachAngle(&ang, GetAngle(gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                                             gUnk_02034928->unk_28, gUnk_02034928->unk_2C) - 64, 5);
            }

            gUnk_02034928->unk_24 = ang;
            ApproachValue(&gUnk_02034928->unk_10, gUnk_02034928->unk_28, gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_14, gUnk_02034928->unk_2C, gUnk_02034928->unk_08);
            ApproachValue(&gUnk_02034928->unk_18, gUnk_02034928->unk_30, gUnk_02034928->unk_08);

            if (func_08011E3C(gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18,
                              8, 8, 16)) {
                gUnk_02034928->unk_08 = -1;
            } else {
                gUnk_02034928->unk_08--;
            }
        } else if (a > 2) {
            if (gUnk_02034928->unk_34 & 1) {
                dx = ((7 - a) << 8) * 7;
            } else {
                s32 t = 7 - a;
                t *= 256;
                dx = t * -7;
            }

            if (func_08011E3C(gUnk_02034928->unk_10 + dx, gUnk_02034928->unk_14,
                              gUnk_02034928->unk_18, 8, 8, 16)) {
                gUnk_02034928->unk_08 = -1;
            }
        }
    }

    switch (gUnk_02034928->unk_08) {
    case 0:
        gUnk_02034928->unk_04 = func_08012BCC;
        break;
    case -1:
        m4aSongNumStart(0x29D);
        SetBlendAlpha(16, 11);
        gUnk_02034928->unk_24 = 0;
        gUnk_02034928->unk_1C = 0x500;
        gUnk_02034928->unk_20 = 0x500;
        gUnk_02034928->unk_10 += dx;
        gUnk_02034928->unk_4C = 20;
        WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                      gUnk_02034928->unk_18);
        func_08006778(gUnk_09EDA600, sx, sy);
        m4aSongNumStart(0x1FB);
        gUnk_02034928->unk_08 = -2;
        gUnk_02034928->unk_0A = 0;
        break;
    case -2:
        if (gUnk_02034928->unk_0A == 7) {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                          gUnk_02034928->unk_18, 256, 256, 256);
        }

        gUnk_02034928->unk_1C += 51;
        gUnk_02034928->unk_20 += 51;
        gUnk_02034928->unk_0A++;
        break;
    }

    func_08012908();
}
void func_08016F2C(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA570, sx, sy);
    m4aSongNumStart(0x29D);
    BgAnimSetLoopStartFrame(8);
    gUnk_02034928->unk_04 = func_08016D00;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_08 = 15;
    gUnk_02034928->unk_26 = 3;
    gUnk_02034928->unk_48 = w;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017008(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = 0x180;
    gUnk_02034928->unk_20 = 0x180;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA858, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_0801709C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            BgAnimStop();
            gUnk_02034928->unk_04 = 0;
            gUnk_02034928->unk_34 &= ~2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
}
void func_08017138(u16 a) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_26 = 0;
    func_08006778(gUnk_09EDABD0, 120, 80);
    gUnk_02034928->unk_04 = func_0801709C;
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_34 |= 0x10;
}
void func_0801718C(void) {
    u16 t;
    s32 w;
    t = (gSineTable[(gUnk_02034928->unk_0C / 3) & 0xFF] * 10240) >> 16;
    w = ((abs(gSineTable[(u8)gUnk_02034928->unk_0C]) >> 1) + 0x100) * 0x133 >> 8;
    func_0800675C(t + 15, 0x133, w);
    func_0801709C();
    gUnk_02034928->unk_0C++;
}
void func_080171FC(u16 a) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_0C = 0;
    gUnk_02034928->unk_26 = 0;
    func_08006778(gUnk_09EDABE8, 120, 80);
    func_0800675C(10, 0x133, 0x133);
    gUnk_02034928->unk_04 = func_0801718C;
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08017260(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA5A0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080172F8(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA6F0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017390(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB88, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
}
void func_08017410(void) {
    if (gUnk_02034928->unk_0C > 0) {
        ApproachValueHalfSteps(&gUnk_02034928->unk_1C, 0x200, gUnk_02034928->unk_0C);
        gUnk_02034928->unk_0C--;
    }

    if (gUnk_02034928->unk_0E > 0) {
        ApproachValue(&gUnk_02034928->unk_20, 0x180, gUnk_02034928->unk_0E);
        gUnk_02034928->unk_0E--;
    }

    switch (gUnk_02034928->unk_26) {
    case 0: {
        u16 t;

        SetBlendAlpha(16, gUnk_02034928->unk_08);
        t = gUnk_02034928->unk_08;

        if ((s16)t > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    case 1: {
        u16 t;

        func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 16, 256);
        t = gUnk_02034928->unk_08;

        if ((s16)t > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    case 2: {
        u16 a = gUnk_02034928->unk_08;
        u16 t;

        SetBlendAlpha(16, 16 - ((s16)a >> 1));
        ApproachValue(&gUnk_02034928->unk_1C, 10, 33 - gUnk_02034928->unk_08);
        t = gUnk_02034928->unk_08;

        if ((s16)t > 31) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    }
    func_08012908();
}
void func_08017514(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = 120;
    gUnk_02034928->unk_0C = 60;
    gUnk_02034928->unk_0E = 20;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_1C = 10;
    gUnk_02034928->unk_20 = 10;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC00, sx, sy);
    gUnk_02034928->unk_04 = func_08017410;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080175BC(BtlObj* a, BtlObj* b, u8 c, u8 d) {
    s32 h;
    s32 dx;
    s32 dy;
    s32 t;
    s32 nx;
    s32 ny;

    if (d) {
        b->unk_0B0 = GetAngle(a->unk_004, a->unk_008, b->unk_004, b->unk_008);
        b->unk_0A8 = 0;
    }
    dx = b->unk_004 - gUnk_02034928->unk_10;

    if (dx >= 0 ? dx <= 0x4FFF : gUnk_02034928->unk_10 - b->unk_004 <= 0x4FFF) {
        dy = b->unk_008 - gUnk_02034928->unk_14;

        if (dy >= 0 ? dy <= 0x27FF : gUnk_02034928->unk_14 - b->unk_008 <= 0x27FF) {
            if (gUnk_02034928->unk_34 & 1) {
                h = b->unk_0A8 - ((gUnk_02034928->unk_10 - b->unk_004) >> 1);
            } else {
                h = b->unk_0A8 + ((gUnk_02034928->unk_10 - b->unk_004) >> 1);
            }

            if (h > 0) {
                h = 0;
            }
            t = -(h >> 9);
            nx = gUnk_02034928->unk_10 + gSineTable[(b->unk_0B0 + c) & 0xFF] * (s16)t;
            ny = gUnk_02034928->unk_14 + -gSineTable[((b->unk_0B0 + c) & 0xFF) + 64] * ((s16)t >> 1);

            if (b->unk_004 < nx) {
                b->unk_034 &= ~4;
            } else {
                b->unk_034 |= 4;
            }
            b->unk_004 += (nx - b->unk_004) >> 3;
            b->unk_008 += (ny - b->unk_008) >> 3;
            b->unk_00C += (h - b->unk_00C) >> 2;
            b->unk_0A8 -= 110;
        }
    }
}

void func_08017728(u8 a, u8 b) {
    BtlObj* p;
    BtlObj* o;

    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            p = gBtlWork->unk_07C;
            o = gUnk_02039B9C->unk_07C;
        } else {
            p = gUnk_02039B9C->unk_07C;
            o = gBtlWork->unk_07C;
        }

        func_080175BC(p, o, a, b);
    } else {
        p = gBtlWork->unk_07C;
        o = ListPoolFirst(&gBtlWork->unk_080);

        while (o != 0) {
            if (!(o->unk_034 & 0x40000000) && o->unk_000 != 31) {
                func_080175BC(p, o, a, b);
            }

            o = ListPoolNext(&o->unk_0B8);
        }
    }
}
#ifdef NON_MATCHING
void func_080177EC(void) {
    s16 v;
    u16 u;

    switch (gUnk_02034928->unk_26) {
    case 0:
        v = 17 - gUnk_02034928->unk_08;

        if (gUnk_02034928->unk_34 & 1) {
            ApproachValueHalfSteps(&gUnk_02034928->unk_1C, -0x100, v);
        } else {
            ApproachValueHalfSteps(&gUnk_02034928->unk_1C, 0x100, v);
        }

        ApproachValueHalfSteps(&gUnk_02034928->unk_20, 0x100, v);
        SetBlendAlpha(16, gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        u = gUnk_02034928->unk_08;
        gUnk_02034928->unk_20 = abs(gSineTable[(u8)gUnk_02034928->unk_08] >> 1) + 0x100;

        if (gUnk_02034928->unk_34 & 1) {
            if ((u16)gUnk_02034928->unk_08 == 0) {
                func_08017728(-u * 8, 1);
            } else {
                func_08017728(-u * 8, 0);
            }
        } else {
            if ((u16)gUnk_02034928->unk_08 == 0) {
                func_08017728(u * 8, 1);
            } else {
                func_08017728(u * 8, 0);
            }
        }

        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14,
                          gUnk_02034928->unk_18, 40, 20, 256);
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        v = gUnk_02034928->unk_08;
        SetBlendAlpha(16, 16 - v);

        if (gUnk_02034928->unk_34 & 1) {
            ApproachValue(&gUnk_02034928->unk_1C, -10, 17 - v);
        } else {
            ApproachValue(&gUnk_02034928->unk_1C, 10, 17 - v);
        }

        ApproachValue(&gUnk_02034928->unk_20, 768, 17 - v);

        if (v > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }

    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_10 -= 102;
    } else {
        gUnk_02034928->unk_10 += 102;
    }

    gUnk_02034928->unk_3C = 0;
    func_0801C6D4(&gUnk_02034928->unk_10, &gUnk_02034928->unk_14, &gUnk_02034928->unk_18,
                  &gUnk_02034928->unk_3C);
    ClampBattlePosition(&gUnk_02034928->unk_10, &gUnk_02034928->unk_14, -16, 0);
    func_08012908();
}
#else
INCLUDE_ASM("btl_effect/func_080177EC.s");
#endif
void func_080179F8(s32 x, s32 y, s32 z, s32 w, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = 220;
    gUnk_02034928->unk_0C = 0;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_20 = 10;

    if (f) {
        gUnk_02034928->unk_1C = -10;
        gUnk_02034928->unk_34 |= 1;
    } else {
        gUnk_02034928->unk_1C = 10;
    }
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC18, sx, sy);
    gUnk_02034928->unk_04 = func_080177EC;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017AC0(void) {
    s16 v;
    s16 w;

    switch (gUnk_02034928->unk_26) {
    case 0:
        gUnk_02034928->unk_1C += 0x80;

        if (gUnk_02034928->unk_08 > 60) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        v = gUnk_02034928->unk_08;
        SetBlendAlpha(16, v + 8);

        if (v > 7) {
#ifdef VERSION_EU
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14 + 0x1000, 0, 0x100, 0x100, 0x100);
#else
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14 + 0x1000, 0, 0x100, 0x100, 8);
#endif
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        w = gUnk_02034928->unk_08 >> 2;
        SetBlendAlpha(16, 16 - w);

        if (w > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_08017B74(s32 x, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = gBtlWork->unk_0DE << 8;
    gUnk_02034928->unk_18 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_1C = 10;
    gUnk_02034928->unk_20 = -((gBtlWork->unk_0E0 - gBtlWork->unk_0DE) << 8) / 96;
    WorldToScreen(&sx, &sy, x, gUnk_02034928->unk_14, 0);
    func_08006778(gUnk_09EDAC00, sx, sy);
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_26 = 0;
    SetBlendAlpha(16, 8);
    gUnk_02034928->unk_04 = func_08017AC0;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017C54(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        ApproachValue(&gUnk_02034928->unk_10, gUnk_02034928->unk_28, gUnk_02034928->unk_0A);

        if (gUnk_02034928->unk_34 & 1) {
            ApproachValue(&gUnk_02034928->unk_1C, -256, gUnk_02034928->unk_0A);
        } else {
            ApproachValue(&gUnk_02034928->unk_1C, 256, gUnk_02034928->unk_0A);
        }

        gUnk_02034928->unk_20 = abs(gUnk_02034928->unk_1C);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_26 = 1;
            gUnk_02034928->unk_0A = 16;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_34 & 1) {
            if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 - 0x1000, gUnk_02034928->unk_14 + 0x2000, 0, 20, 32, 64) || func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 + 0x1000, gUnk_02034928->unk_14 - 0x2000, 0, 20, 32, 64)) {
                gUnk_02034928->unk_26 = 2;
                m4aSongNumStart(0x1F9);
            }
        } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 - 0x1000, gUnk_02034928->unk_14 - 0x2000, 0, 20, 32, 64)) {
            gUnk_02034928->unk_26 = 2;
            m4aSongNumStart(0x1F9);
        } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10 + 0x1000, gUnk_02034928->unk_14 + 0x2000, 0, 20, 32, 64)) {
            gUnk_02034928->unk_26 = 2;
            m4aSongNumStart(0x1F9);
        }

        if (gUnk_02034928->unk_34 & 1) {
            if (gBtlWork->unk_07C->unk_004 < gUnk_02034928->unk_10) {
                gUnk_02034928->unk_26 = 2;
            }
        } else {
            if (gBtlWork->unk_07C->unk_004 > gUnk_02034928->unk_10) {
                gUnk_02034928->unk_26 = 2;
            }
        }
        break;
    case 2:
        SetBlendAlpha(16, gUnk_02034928->unk_0A);

        if (gUnk_02034928->unk_0A <= 0) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_0A--;
        }
        break;
    }
    func_08012908();
}
void func_08017E18(s32 x, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
    gUnk_02034928->unk_18 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_0A = 20;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, 0);
    func_08006778(gUnk_09EDAC60, sx, sy);

    if (f) {
        gUnk_02034928->unk_1C = 10;
        gUnk_02034928->unk_28 = x - 0x3700;
    } else {
        gUnk_02034928->unk_1C = -10;
        gUnk_02034928->unk_28 = x + 0x3700;
        gUnk_02034928->unk_34 |= 1;
    }
    gUnk_02034928->unk_20 = 10;
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_08017C54;
    BgAnimSetLoopStartFrame(0);
}

void func_08017EF4(void) {
    u16 k;
    u16 t;
    ApproachValue(&gUnk_02034928->unk_1C, 0x300, gUnk_02034928->unk_0A);
    gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
    gUnk_02034928->unk_0A--;
    BgAnimGetFrameState(&k, 0);

    if (k <= 4) {
        t = (gUnk_02034928->unk_1C * 5) >> 5;
        if (func_08011F78(0x13D, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, (s16)t, (s16)t >> 1, 1)) {
            m4aSongNumStart(0x2AB);
        }
    }
    func_08012908();
}

void func_08017F70(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC78, sx, sy);
    gUnk_02034928->unk_1C = 0x80;
    gUnk_02034928->unk_20 = 0x80;
    gUnk_02034928->unk_0A = BgAnimGetDuration(BgAnimGetCurrent());
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_08017EF4;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801801C(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC90, sx, sy);
    gUnk_02034928->unk_1C = 0x80;
    gUnk_02034928->unk_20 = 0x80;
    gUnk_02034928->unk_0A = BgAnimGetDuration(BgAnimGetCurrent());
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_08017EF4;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080180C8(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 > 50) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        gUnk_02034928->unk_08 = 0;
        gUnk_02034928->unk_26 = 2;

        if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 0x100, 0x100, 0x100)) {
            m4aSongNumStart(0x2AF);
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    gUnk_02034928->unk_28 += 30;
    gUnk_02034928->unk_24 += gUnk_02034928->unk_28 >> 8;
    gUnk_02034928->unk_1C += 10;
    gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
    func_08012908();
}
void func_08018184(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDACC0, sx, sy);
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 5;
    gUnk_02034928->unk_20 = 5;
    gUnk_02034928->unk_28 = 256;
    gUnk_02034928->unk_34 |= 0x10;
    m4aSongNumStart(0x2AE);
    gUnk_02034928->unk_04 = func_080180C8;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08018240(void) {
    if ((s16)gBtlWork->unk_072 != 0) {
        func_08012908();
        return;
    }

    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_24 += 3;
    } else {
        gUnk_02034928->unk_24 -= 3;
    }
    gUnk_02034928->unk_10 = gUnk_02034928->unk_28 + ((gSineTable[gUnk_02034928->unk_24] * gUnk_02034928->unk_3C) >> 8);
    gUnk_02034928->unk_18 = gUnk_02034928->unk_30 + ((-gSineTable[gUnk_02034928->unk_24 + 64] * gUnk_02034928->unk_3C) >> 8);

    if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 10, 5, 72)) {
        m4aSongNumStart(0x2AD);
    }

    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, (u16)gUnk_02034928->unk_08 * 2);

        if (gUnk_02034928->unk_08 > 7) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > 30) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - (u16)gUnk_02034928->unk_08 * 2);

        if (gUnk_02034928->unk_08 > 7) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_0801836C(s32 x, s32 y, s32 z, s32 w, s32 v) {
    s16 sx;
    s16 sy;
    s32 d;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_48 = v;

    if (w > 0) {
        gUnk_02034928->unk_1C = -0x180;
        gUnk_02034928->unk_34 |= 1;
        x -= 0x4000;
        w += 0x4000;
    } else {
        gUnk_02034928->unk_1C = 0x180;
        x += 0x4000;
        w -= 0x4000;
    }
    gUnk_02034928->unk_28 = x;
    gUnk_02034928->unk_30 = z;
    d = abs(w);
    gUnk_02034928->unk_3C = d;
    gUnk_02034928->unk_10 = x + ((gSineTable[0] * d) >> 8);
    gUnk_02034928->unk_18 = z + ((-gSineTable[64] * d) >> 8);
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_20 = 0x180;
    SetBlendAlpha(16, 0);
    m4aSongNumStart(0x2AC);
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(&gUnk_09EDACC0[0x18], sx, sy);
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_04 = func_08018240;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801848C(void) {
    s16 t = gUnk_02034928->unk_08 >> 1;
    SetBlendAlpha(16, 16 - t);

    if (t > 15) {
        BgAnimStop();
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080184C4(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_24 = f;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDACA8, sx, sy);
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_0801848C;
}
void func_0801853C(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDACF0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080185D0(void) {
    s32 x;
    s32 y;
    s32 z;
    s16 r;
    u8 ang;
    BtlObj* o;

    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_34 & 1) {
            ApproachValueHalfSteps(&gUnk_02034928->unk_1C, -204, gUnk_02034928->unk_0A);
        } else {
            ApproachValueHalfSteps(&gUnk_02034928->unk_1C, 204, gUnk_02034928->unk_0A);
        }
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            BgAnimStop();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    r = (abs(gUnk_02034928->unk_1C) * 5) >> 4;

    if (gUnk_02034928->unk_34 & 1) {
        ang = gUnk_02034928->unk_24 + 192;
    } else {
        ang = gUnk_02034928->unk_24 + 64;
    }
    x = gUnk_02034928->unk_10 + gSineTable[ang] * r;
    z = gUnk_02034928->unk_18 + -gSineTable[ang + 64] * r;
    y = gUnk_02034928->unk_14;
    func_08011F78(gUnk_02034928->unk_48, x, y, z, 32, 16, 16);
    o = gBtlWork->unk_07C;

    if (o->unk_034 & 0x2000) {
        o->unk_004 += (x - o->unk_004) >> 2;
        o->unk_008 += (y - o->unk_008) >> 2;
        o->unk_00C += (z - o->unk_00C) >> 1;
    }
    func_08012908();
}
void func_08018724(s32 x, s32 y, s32 z, u8 f, s32 v) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 80;
    gUnk_02034928->unk_48 = v;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(&gUnk_09EDACF0[0x18], sx, sy);

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_24 = 248;
    } else {
        gUnk_02034928->unk_24 = 8;
    }

    if (gUnk_02034928->unk_34 & 1) {
        if (gUnk_02034928->unk_10 < gBtlWork->unk_07C->unk_004) {
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_1C = -(((gUnk_02034928->unk_10 - gBtlWork->unk_07C->unk_004) << 8) / 19200);
        }
    } else {
        if (gUnk_02034928->unk_10 > gBtlWork->unk_07C->unk_004) {
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_1C = ((gBtlWork->unk_07C->unk_004 - gUnk_02034928->unk_10) << 8) / 19200;
        }
    }
    BgAnimSetLoopStartFrame(3);
    gUnk_02034928->unk_04 = func_080185D0;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801884C(void) {
    s16 t;

    switch (gUnk_02034928->unk_26) {
    case 0:
        gUnk_02034928->unk_1C += 2;
        gUnk_02034928->unk_20 += 2;
        break;
    case 1:
        gUnk_02034928->unk_1C += 5;
        gUnk_02034928->unk_20 += 5;
        break;
    case 2:
        gUnk_02034928->unk_1C += 10;
        gUnk_02034928->unk_20 += 10;
        break;
    }

    if (gUnk_02034928->unk_08 == 10) {
        t = (gUnk_02034928->unk_1C * 3) >> 4;
        if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, t, t, 100)) {
            m4aSongNumStart(0x2BB);
        }
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080188E4(u16 a, s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_26 = a;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD20, sx, sy);
    gUnk_02034928->unk_04 = func_0801884C;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_08018970(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD50, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_080189DC(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD68, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08018A70(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = -s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD68, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08018B04(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD80, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_08018B78(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        ApproachValue(&gUnk_02034928->unk_3C, 0xA00, gUnk_02034928->unk_0A);
        ApproachValueHalfSteps(&gUnk_02034928->unk_1C, 460, gUnk_02034928->unk_0A);
        ApproachValueHalfSteps(&gUnk_02034928->unk_20, 512, gUnk_02034928->unk_0A);
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        }
        break;
    case 1:
        gUnk_02034928->unk_26 = 2;
        gUnk_02034928->unk_08 = 0;
        gUnk_02034928->unk_0A = 25;
        break;
    case 2:
        ApproachValue(&gUnk_02034928->unk_3C, 0, gUnk_02034928->unk_0A);
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 3;
            BgAnimStop();
        }
        break;
    }
    func_08012908();
}
void func_08018C38(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 10;
    gUnk_02034928->unk_20 = 10;
    gUnk_02034928->unk_3C = 0;
    gUnk_02034928->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA38, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gUnk_02034928->unk_04 = func_08018B78;
    gUnk_02034928->unk_0A = 43;
}
void func_08018CC4(void) {
    if (gUnk_02034928->unk_08 > 10) {
        switch (gUnk_02034928->unk_26) {
        case 0:
            func_08011F78(11, gUnk_02034928->unk_10 - 0x6000, gUnk_02034928->unk_14 - 0x1000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10, gUnk_02034928->unk_14 + 0x2000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x7000, gUnk_02034928->unk_14 - 0x1000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x3000, gUnk_02034928->unk_14 + 0x2000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x3000, gUnk_02034928->unk_14 + 0x2800, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x6000, gUnk_02034928->unk_14 + 0x6000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x800, gUnk_02034928->unk_14 + 0x7800, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x3000, gUnk_02034928->unk_14 + 0x2800, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x6800, gUnk_02034928->unk_14 + 0x6800, gUnk_02034928->unk_18,
                14, 14, 14);
            break;
        case 1:
            func_08011F78(11, gUnk_02034928->unk_10 + 0x6000, gUnk_02034928->unk_14 - 0x1000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10, gUnk_02034928->unk_14 + 0x2000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x7000, gUnk_02034928->unk_14 - 0x1000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x3000, gUnk_02034928->unk_14 + 0x2000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x3000, gUnk_02034928->unk_14 + 0x2800, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 + 0x6000, gUnk_02034928->unk_14 + 0x6000, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x800, gUnk_02034928->unk_14 + 0x7800, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x3000, gUnk_02034928->unk_14 + 0x2800, gUnk_02034928->unk_18,
                14, 14, 14);
            func_08011F78(11, gUnk_02034928->unk_10 - 0x6800, gUnk_02034928->unk_14 + 0x6800, gUnk_02034928->unk_18,
                14, 14, 14);
            break;
        }
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}
void func_08018F28(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    m4aSongNumStart(0x2C1);
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    gUnk_02034928->unk_26 = GetRandom() % 2;
    switch (gUnk_02034928->unk_26) {
    case 0:
        func_08006778(gUnk_09EDAD98, sx, sy);
        break;
    case 1:
        func_08006778(gUnk_09EDAD98, sx, sy);
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
        break;
    }
    gUnk_02034928->unk_04 = func_08018CC4;
}
void func_08018FE4(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDADB0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
