#include "display.h"
#include "battle.h"
#include "btl_effect.h"

BgFx* gBgFx;

void func_08012674(void) {
    if (gBtlWork->flags & 4) {
        SetBgPriority(gBgFx->unk_00, 0);
    } else {
        SetBgPriority(gBgFx->unk_00, 1);
    }
    SetBgBlend(gBgFx->unk_00, 16, 16);
    gBgFx->unk_1C = 0x100;
    gBgFx->unk_20 = 0x100;
    gBgFx->unk_24 = 0;
    gBgFx->update = 0;
    gBgFx->unk_08 = 0;
    gBgFx->z = 0;
    gBgFx->flags = 2;
    gBgFx->unk_4C = 0;
}

u8 func_080126E4(u8 a) {
    if (BgAnimIsStopped()) {
        gBgFx->unk_38 = a;
        return 0;
    }

    if (gBgFx->unk_38 < a) {
        return 1;
    }
    gBgFx->unk_38 = a;
    return 0;
}

void func_08012728(s16 a) {
    u16 b;
    u16 c;
    BgAnimGetFrameState(&b, &c);

    if (BgAnimGetDuration(BgAnimGetCurrent()) - b * c <= a) {
        gBgFx->flags &= ~2;
        gBgFx->unk_38 = 2;

        if (gBgFx->flags & 8) {
            gBgFx->flags &= ~8;
            FadeToOriginal(0, 8);
        }
    }
}

void BgFxInit(u16 a, u16 bg) {
    s32 i;
    gBgFx = EwramAlloc(0x50);

    for (i = 10; i < 16; i++) {
        FadeSetPaletteExcluded(i, 1);
    }

    if (a == 0) {
        BgAnimInit(bg, 0xC000, 0);
    } else {
        BgAnimInit(bg, 0x8000, 0x80);
    }
    SetBgBlend(bg, 16, 16);
    gBgFx->update = 0;
    gBgFx->unk_38 = 0xFF;
    gBgFx->unk_00 = bg;
    func_08012674();
    gBgFx->flags = 0;
}

void BgFxFree(void) {
    EwramFree(gBgFx);
}

void BgFxUpdate(void) {
    if (gBtlWork->flags & 0x400000) {
        gBtlWork->flags &= ~0x400000;
        gBgFx->flags &= 0xFFFD;
        gBgFx->update = 0;
        BgAnimStop();
        SetBgBlend(gBgFx->unk_00, 16, 16);
    }

    if (gBgFx->update != 0) {
        gBgFx->update();

        if (!(gBtlWork->flags & 4)) {
            gBtlWork->unk_0D0 = gBgFx->y;

            if (gBgFx->flags & 0x10) {
                SetBgPriority(gBgFx->unk_00, 0);
            } else if (gBgFx->flags & 0x20) {
                SetBgPriority(gBgFx->unk_00, 1);
                gBtlWork->unk_0D8 = 0xFF00;
            } else {
                gBtlWork->unk_0D8 = 8;
            }
        }
    }
    BgAnimUpdate();
}

u8 func_080128EC(void) {
    if (gBgFx->flags & 2) {
        return 1;
    }
    return 0;
}

void func_08012908(void) {
    s16 sx;
    s16 sy;

    if (BgAnimIsStopped()) {
        SetBgBlend(gBgFx->unk_00, 16, 16);
        gBgFx->update = 0;
        gBgFx->flags &= ~2;

        if (gBgFx->flags & 8) {
            FadeToOriginal(0, 8);
        }
        return;
    }

    if (gBtlWork->flags & 0x4000) {
        if (gBtlWork->flags & 0x20000000) {
            if (gBtlWork->flags & 2) {
                if (gBtlWork->unk_0B2 < func_080ABED0()) {
                    func_08012728(gBgFx->unk_4C);
                }
            }
        } else if (gUnk_02039B9C->flags & 2) {
            if (gUnk_02039B9C->unk_0B2 < func_080ABED0()) {
                func_08012728(gBgFx->unk_4C);
            }
        }
    } else if (gBtlWork->flags & 2) {
        if (gBtlWork->unk_0B2 < func_080ABED0()) {
            func_08012728(gBgFx->unk_4C);
        }
    }

    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimSetPosition(sx, sy);

    if (gBgFx->flags & 4) {
        BgAnimSetTransform(gBgFx->unk_24 + gBtlWork->unk_018, gBgFx->unk_1C, gBgFx->unk_20);
    } else {
        s32 a = gBgFx->unk_1C * gBtlWork->unk_024 >> 8;
        s32 b = gBgFx->unk_20 * gBtlWork->unk_024 >> 8;

        BgAnimSetTransform(gBgFx->unk_24 + gBtlWork->unk_018, a, b);
    }
}
void func_08012AAC(u16 a, s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_4C = 20;
    gBgFx->x = x;
    gBgFx->y = y;

    switch (a) {
    case 0:
        gBgFx->z = z - 0x1400;
        break;
    case 1:
        gBgFx->z = z;
        break;
    case 2:
        gBgFx->z = z - 0x1000;
        break;
    }
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);

    switch (a) {
    case 0:
        BgAnimStart(&gUnk_09EDA558, sx, sy);
        m4aSongNumStart(SONG_EF_CAREL00);
        break;
    case 1:
        BgAnimStart(&gUnk_09EDA840, sx, sy);
        m4aSongNumStart(SONG_EF_CAREL01);
        break;
    case 2:
        BgAnimStart(&gUnk_09EDA828, sx, sy);
        m4aSongNumStart(SONG_EF_CAREL02);
        break;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
    gBgFx->update = func_08012908;
}

void func_08012BCC(void) {
    SetBlendAlpha(16, 16 - gBgFx->unk_08);

    if (gBgFx->unk_08 > 15) {
        BgAnimStop();
    } else {
        gBgFx->unk_08++;
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

    if (gBgFx->unk_08 > 0) {
        if (a > 7) {
            ang = gBgFx->unk_24;

            if (gBgFx->flags & 1) {
                ApproachAngle(&ang, GetAngle(gBgFx->x, gBgFx->y,
                                             gBgFx->unk_28, gBgFx->unk_2C) + 64, 5);
            } else {
                ApproachAngle(&ang, GetAngle(gBgFx->x, gBgFx->y,
                                             gBgFx->unk_28, gBgFx->unk_2C) - 64, 5);
            }

            gBgFx->unk_24 = ang;
            ApproachValue(&gBgFx->x, gBgFx->unk_28, gBgFx->unk_08);
            ApproachValue(&gBgFx->y, gBgFx->unk_2C, gBgFx->unk_08);
            ApproachValue(&gBgFx->z, gBgFx->unk_30, gBgFx->unk_08);

            if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y,
                              gBgFx->z, 8, 8, 16)) {
                gBgFx->unk_08 = -1;
            } else {
                gBgFx->unk_08--;
            }
        } else if (a > 2) {
            if (gBgFx->flags & 1) {
                dx = ((7 - a) << 8) * 7;
            } else {
                s32 t = 7 - a;
                t *= 256;
                dx = t * -7;
            }

            if (func_08011F78(gBgFx->unk_48, gBgFx->x + dx,
                              gBgFx->y, gBgFx->z, 8, 8, 16)) {
                gBgFx->unk_08 = -1;
            }
        }
    }

    if (gBgFx->unk_08 == 0) {
        gBgFx->update = func_08012BCC;
    } else if (gBgFx->unk_08 == -1) {
        gBgFx->unk_24 = 0;
        gBgFx->unk_1C = 0x100;
        gBgFx->unk_20 = 0x100;
        gBgFx->x += dx;
        gBgFx->unk_4C = 20;
        WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y,
                      gBgFx->z);

        switch (gBgFx->unk_26) {
        case 0:
            BgAnimStart(&gUnk_09EDA5B8, sx, sy);
            m4aSongNumStart(SONG_EF_FIRE01);
            break;
        case 1:
            BgAnimStart(&gUnk_09EDA5E8, sx, sy);
            m4aSongNumStart(SONG_EF_FIRE02);
            break;
        case 2:
            BgAnimStart(&gUnk_09EDA858, sx, sy);
            m4aSongNumStart(SONG_EF_FIRE03);
            break;
        default:
            BgAnimStart(&gUnk_09EDA870, sx, sy);
            m4aSongNumStart(SONG_EF_FIRE03);
            break;
        }

        gBgFx->unk_08 = -2;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);

    if (a == 3) {
        BgAnimStart(&gUnk_09EDA588, sx, sy);
    } else {
        BgAnimStart(&gUnk_09EDA570, sx, sy);
    }

    if ((gBtlWork->flags & 0x4000) == 0 && (gBtlWork->flags & 0x40)) {
        m4aSongNumStart(SONG_EF_MON_FIRE);
    } else {
        m4aSongNumStart(SONG_EF_FIRE00);
    }
    BgAnimSetLoopStartFrame(8);
    gBgFx->update = func_08012C08;
    gBgFx->unk_28 = p;
    gBgFx->unk_2C = q;
    gBgFx->unk_30 = r;
    gBgFx->unk_08 = 15;
    gBgFx->unk_26 = a;
    gBgFx->unk_48 = w;

    if (f) {
        gBgFx->flags |= 1;
        gBgFx->unk_1C = -0x100;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08012F74(s32 x, s32 y, s32 z, u8 f, s32 unused, s32 w, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA570, sx, sy);
    m4aSongNumStart(SONG_EF_MON_FIRE);
    BgAnimSetLoopStartFrame(8);
    gBgFx->update = func_08012C08;
    gBgFx->unk_28 = gBtlWork->actor->x;
    gBgFx->unk_2C = gBtlWork->actor->y;
    gBgFx->unk_30 = gBtlWork->actor->z;
    gBgFx->unk_08 = a;
    gBgFx->unk_26 = 1;
    gBgFx->unk_48 = w;

    if (f) {
        gBgFx->flags |= 1;
        gBgFx->unk_1C = -0x180;
    } else {
        gBgFx->unk_1C = 0x180;
    }
    gBgFx->unk_20 = 0x180;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
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

    if (gBgFx->unk_08 > 0) {
        if (a > 7) {
            angle = gBgFx->unk_24;

            if (gBgFx->flags & 1) {
                ApproachAngle(&angle,
                    GetAngle(gBgFx->x, gBgFx->y, gBgFx->unk_28,
                        gBgFx->unk_2C) + 64,
                    5);
            } else {
                ApproachAngle(&angle,
                    GetAngle(gBgFx->x, gBgFx->y, gBgFx->unk_28,
                        gBgFx->unk_2C) - 64,
                    5);
            }
            gBgFx->unk_24 = angle;
            ApproachValue(&gBgFx->x, gBgFx->unk_28, gBgFx->unk_08);
            ApproachValue(&gBgFx->y, gBgFx->unk_2C, gBgFx->unk_08);
            ApproachValue(&gBgFx->z, gBgFx->unk_30, gBgFx->unk_08);

            if (func_08011E3C(gBgFx->x, gBgFx->y, gBgFx->z, 8, 16, 16)) {
                gBgFx->unk_08 = -1;
            } else {
                gBgFx->unk_08--;
            }
        } else if (a > 2) {
            if (gBgFx->flags & 1) {
                dx = ((7 - a) << 8) * 7;
            } else {
                s32 t = 7 - a;
                t *= 256;
                dx = t * -7;
            }

            if (func_08011E3C(gBgFx->x + dx, gBgFx->y, gBgFx->z, 8, 16, 16)) {
                gBgFx->unk_08 = -1;
            }
        }
    }

    if (gBgFx->unk_08 == 0) {
        gBgFx->unk_08 = -1;
    } else if (gBgFx->unk_08 == -1) {
        gBgFx->unk_24 = 0;
        gBgFx->unk_1C = 0x100;
        gBgFx->unk_20 = 0x100;
        gBgFx->x += dx;
        gBgFx->unk_4C = 20;
        WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);

        switch (gBgFx->unk_26) {
        case 0:
            BgAnimStart(&gUnk_09EDA708, sx, sy);
            m4aSongNumStart(SONG_EF_BURIZA01);
            break;
        case 1:
            BgAnimStart(&gUnk_09EDA738, sx, sy);
            m4aSongNumStart(SONG_EF_BURIZA02);
            break;
        case 2:
        default:
            BgAnimStart(&gUnk_09EDA750, sx, sy);
            m4aSongNumStart(SONG_EF_BURIZA03);
            break;
        }
        gBgFx->unk_08 = -2;
    }

    if (gBgFx->unk_08 == -2) {
        switch (gBgFx->unk_26) {
        case 0:
            if (gBgFx->unk_0A == 20) {
                func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y,
                    gBgFx->z, 18, 18, 18);
            }
            break;
        case 1:
            if (gBgFx->unk_0A == 35) {
                func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y,
                    gBgFx->z, 24, 24, 30);
            }
            break;
        case 2:
        default:
            if (gBgFx->unk_0A == 50) {
                func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y,
                    gBgFx->z, 48, 48, 52);
            }
            break;
        }
        gBgFx->unk_0A++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA6D8, sx, sy);

    if ((gBtlWork->flags & 0x4000) == 0 && (gBtlWork->flags & 0x40)) {
        m4aSongNumStart(SONG_EF_MON_BURIZA);
    } else {
        m4aSongNumStart(SONG_EF_BURIZA00);
    }
    BgAnimSetLoopStartFrame(8);
    gBgFx->update = func_08013070;
    gBgFx->unk_28 = p;
    gBgFx->unk_2C = q;
    gBgFx->unk_30 = r;
    gBgFx->unk_08 = 15;
    gBgFx->unk_26 = a;
    gBgFx->unk_48 = w;
    gBgFx->unk_0A = 0;

    if (f) {
        gBgFx->unk_1C = -0x100;
        gBgFx->flags |= 1;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_08013420(void) {
    gBgFx->unk_1C += gBgFx->unk_28;
    gBgFx->unk_20 += gBgFx->unk_2C;
    gBgFx->unk_24 += 3;
    func_08012908();

    if (gBgFx->unk_08 > 5) {
        s16 t = gBgFx->unk_08 - 5;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            BgAnimStop();
        }
    }
    gBgFx->unk_08++;
}

void func_08013480(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gBgFx->unk_1C = 76;
    gBgFx->unk_20 = 76;
    gBgFx->unk_24 = 0;
    gBgFx->unk_28 = 25;
    gBgFx->unk_2C = 25;
    BgAnimStart(&gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08013420;
    gBgFx->unk_08 = 0;
}
void func_0801350C(void) {
    s16 t = gBgFx->unk_08;

    gBgFx->unk_24 += 4;
    gBgFx->unk_1C += gBgFx->unk_28;
    gBgFx->unk_20 += gBgFx->unk_2C;
    SetBlendAlpha(16, 16 - t);

    if (t > 15) {
        BgAnimStop();
    }
    gBgFx->unk_08++;
    func_08012908();
}
void func_08013560(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gBgFx->unk_1C = 256;
    gBgFx->unk_20 = 256;
    gBgFx->unk_24 = 0;
    gBgFx->unk_28 = 76;
    gBgFx->unk_2C = 76;
    BgAnimStart(&gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_0801350C;
    gBgFx->unk_08 = 0;
}
void func_080135EC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gBgFx->unk_1C = 128;
    gBgFx->unk_20 = 128;
    gBgFx->unk_24 = 0;
    BgAnimStart(&gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08013420;
    gBgFx->unk_08 = 0;
}
void func_08013678(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDA630, sx, sy);
    gBgFx->update = func_08012908;
}
void func_080136E0(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDAD38, sx, sy);
    gBgFx->update = func_08012908;
}

void func_08013748(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;

    if (f != 0) {
        gBgFx->unk_1C = -0x100;
    }
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDA648, sx, sy);
    gBgFx->update = func_08012908;
}

void func_080137C8(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x + 0x400;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;

    if (f != 0) {
        gBgFx->unk_1C = -0x100;
    }
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDA660, sx, sy);
    gBgFx->update = func_08012908;
}
void func_08013854(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDA678, sx, sy);
    gBgFx->update = func_08012908;
}
void func_080138BC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    gBgFx->unk_20 = 0x200;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDA5D0, sx, sy);
    gBgFx->update = func_08012908;
}
void func_0801392C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDA720, sx, sy);
    gBgFx->update = func_08012908;
}

void func_08013994(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDA780, sx, sy);
    gBgFx->update = func_08012908;
}

void func_080139FC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA930, sx, sy);
    gBgFx->update = func_08012908;
}

void func_08013A68(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_4C = 20;
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x3000;
    WorldToScreen(&sx, &sy, x, y, z - 0x3000);
    BgAnimStart(&gUnk_09EDA6C0, sx, sy);
    m4aSongNumStart(SONG_EF_POSION);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08013B00(void) {
    s16 sx;
    s16 sy;
    s16 sx2;
    s16 sy2;

    if (gBgFx->unk_08 == 0 && BgAnimIsStopped()) {
        SetBlendAlpha(16, 16);
        gBgFx->x = gBtlWork->unk_000;
        gBgFx->y = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
        gBgFx->z = gBgFx->unk_30;
        WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
        gBgFx->unk_24 = 0;
        gBgFx->unk_4C = 20;
        gBgFx->flags |= 4;
        gBgFx->unk_1C = 512;
        gBgFx->unk_20 = (sy << 8) / 40;

        if (gBgFx->unk_20 < 384) {
            gBgFx->unk_20 = 384;
        }

        switch (gBgFx->unk_26) {
        case 0:
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 32, 256, 256);
            BgAnimStart(&gUnk_09EDA798, sx, sy);
            m4aSongNumStart(SONG_EF_THUND01);
            break;
        case 1:
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 256, 256, 256);
            BgAnimStart(&gUnk_09EDA7B0, sx, sy);
            m4aSongNumStart(SONG_EF_THUND02);
            break;
        case 2:
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 256, 256, 256);
            BgAnimStart(&gUnk_09EDA7C8, sx, sy);
            m4aSongNumStart(SONG_EF_THUND03);
            break;
        }

        gBgFx->unk_08 = 1;
    } else if (gBgFx->unk_08 == 1) {
        s32 t;

        WorldToScreen(&sx2, &sy2, gBgFx->x, gBgFx->y, gBgFx->z);
        t = sy2 << 8;
        gBgFx->unk_20 = t / 40;

        if (gBgFx->unk_20 < 384) {
            gBgFx->unk_20 = 384;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_30 = p;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA768, sx, sy);
    m4aSongNumStart(SONG_EF_THUND00);
    gBgFx->unk_48 = q;
    gBgFx->update = func_08013B00;
    gBgFx->unk_26 = a;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_08013D60(void) {
    u16 a;
    BgAnimGetFrameState(&a, 0);

    if (a > 3) {
        gBgFx->unk_1C += 12;
        gBgFx->unk_20 += 12;
        SetBlendAlpha(gBgFx->unk_08, 16 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08 += 2;
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
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    SetBgBlend(gBgFx->unk_00, 0, 16);
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA7F8, sx, sy);
    BgAnimSetLoopStartFrame(4);
    m4aSongNumStart(SONG_EF_MON_DEATH);
    gBgFx->update = func_08013D60;
    gBgFx->unk_2C = 0;
    gBgFx->unk_08 = 0;
}
void func_08013E4C(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    SetBgBlend(gBgFx->unk_00, 0, 16);
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA810, sx, sy);
    m4aSongNumStart(SONG_BTL_DARKDEAD);
    gBgFx->update = func_08012908;
    gBgFx->unk_2C = 0;
    gBgFx->unk_08 = 0;
}

void func_08013EDC(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA9D8, sx, sy);
    gBgFx->update = func_08012908;
    gBgFx->unk_2C = 0;
    gBgFx->unk_08 = 0;
}

void func_08013F5C(s32 x, s32 y, s32 s, u16 b, u16 c) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    SetBgBlend(gBgFx->unk_00, b, c);
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = -0x1000;
    WorldToScreen(&sx, &sy, x, y, -0x1000);
    BgAnimStart(&gUnk_09EDA810, sx, sy);
    m4aSongNumStart(SONG_BTL_DARKDEAD);
    gBgFx->update = func_08012908;
    gBgFx->unk_2C = 0;
    gBgFx->unk_08 = 0;
}

void func_08014000(void) {
    gBgFx->unk_1C += 12;
    gBgFx->unk_20 += 12;
    func_08012908();
}

void func_08014020(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA600, sx, sy);
    gBgFx->update = func_08014000;
    m4aSongNumStart(SONG_EF_TARU_BOMB);
    gBgFx->flags |= 0x10;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void BgFxGetPosition(s32* a, s32* b, s32* c) {
    *a = gBgFx->x;
    *b = gBgFx->y;
    *c = gBgFx->z;
}

void func_080140E0(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA8E8, sx, sy);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_0801416C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    BgAnimStart(&gUnk_09EDA888, sx, sy);
    gBgFx->update = func_08012908;
}

void func_080141D4(void) {
    BtlObj* p = gBgFx->actor;
    gBgFx->x = p->x;
    gBgFx->y = p->y;
    gBgFx->z = p->z - 0x800;
    func_08012908();
}

void func_080141FC(BtlObj* p) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->actor = p;
    gBgFx->x = p->x;
    gBgFx->y = p->y;
    gBgFx->z = p->z - 0x800;
    gBgFx->unk_1C = 0x133;
    gBgFx->unk_20 = 0x133;
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDA768, sx, sy);
    BgAnimSetLoopStartFrame(4);
    gBgFx->update = func_080141D4;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08014294(void) {
    switch (gBgFx->unk_26) {
    case 0:
        if (gBgFx->unk_08 > 30) {
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        gBgFx->unk_3C += 64;
        gBgFx->z += gBgFx->unk_3C;

        if (gBgFx->z > 0) {
            gBgFx->z = 0;
            gBgFx->unk_26 = 2;
            gBgFx->unk_08 = 30;
        }

        gBgFx->x += (gBgFx->unk_28 - gBgFx->x) >> 5;
        gBgFx->unk_24 += 4;
        break;
    case 2:
        ApproachValue(&gBgFx->unk_1C, 3, gBgFx->unk_08);
        ApproachValue(&gBgFx->unk_20, 3, gBgFx->unk_08);
        gBgFx->unk_08--;

        if (gBgFx->unk_08 <= 0) {
            BgAnimStop();
            gBgFx->update = 0;
        }
        break;
    }

    func_08011F78(256, gBgFx->x, gBgFx->y, gBgFx->z, 32, 32, 32);
    func_08012908();
}
void func_0801435C(s32 x, s32 y, s32 z, s32 w, s32 v) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_28 = w;
    gBgFx->unk_3C = v;
    gBgFx->unk_26 = 0;
    gBgFx->unk_1C = 0x299;
    gBgFx->unk_20 = 0x299;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA768, sx, sy);
    BgAnimSetLoopStartFrame(4);
    gBgFx->update = func_08014294;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_0801440C(void) {
    switch (gBgFx->unk_26) {
    case 0:
        ApproachValue(&gBgFx->unk_1C, gBgFx->unk_28, gBgFx->unk_0A);
        gBgFx->unk_20 = gBgFx->unk_1C;
        ApproachValue(&gBgFx->unk_3C, 0x1000, gBgFx->unk_0A);
        SetBlendAlpha(16, gBgFx->unk_3C >> 8);
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        }
        break;
    case 1:
        if (gBgFx->unk_36 != 0) {
            gBgFx->unk_26 = 2;
            gBgFx->unk_08 = 0;
            gBgFx->unk_0A = 16;
        }
        break;
    case 2:
        ApproachValue(&gBgFx->unk_3C, 0, gBgFx->unk_0A);
        SetBlendAlpha(16, gBgFx->unk_3C >> 8);
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 3;
            BgAnimStop();
        }
        break;
    }

    gBgFx->unk_24 += gBgFx->unk_0C;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_26 = 0;
    gBgFx->unk_1C = w;
    gBgFx->unk_20 = w;
    gBgFx->unk_28 = w;
    gBgFx->unk_3C = 0;
    gBgFx->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAAE0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_0801440C;
    gBgFx->unk_0A = a;
    gBgFx->unk_0C = b;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_26 = 0;
    gBgFx->unk_1C = w;
    gBgFx->unk_20 = w;
    gBgFx->unk_28 = w;
    gBgFx->unk_3C = 0;
    gBgFx->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAA38, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_0801440C;
    gBgFx->unk_0A = a;
    gBgFx->unk_0C = b;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08014654(void) {
    u16 t;
    s16 u;
    gBgFx->unk_1C += 25;
    gBgFx->unk_20 += 25;
    func_08012908();
    t = gBgFx->unk_08;

    if (gBgFx->unk_08 > 3) {
        u = t - 3;
        SetBlendAlpha(16, 16 - u);

        if (u > 15) {
            BgAnimStop();
        }
    }
    gBgFx->unk_08++;
}
void func_080146A8(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, 0);
    gBgFx->unk_1C = 512;
    gBgFx->unk_20 = 768;
    gBgFx->unk_24 = 0;
    BgAnimStart(&gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08014654;
    gBgFx->unk_08 = 0;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void BgFxAddPosition(s32 a, s32 b, s32 c) {
    gBgFx->x += a;
    gBgFx->y += b;
    gBgFx->z += c;
}

void BgFxSetPosition(s32 a, s32 b, s32 c) {
    gBgFx->x = a;
    gBgFx->y = b;
    gBgFx->z = c;
}

void func_08014790(u8 bit) {
    gBgFx->unk_36 |= 1 << bit;
}

void func_080147A8(s32 a, s32 b, s32 c) {
    gBgFx->unk_28 = a;
    gBgFx->unk_2C = b;
    gBgFx->unk_30 = c;
}

void func_080147B8(u8 a) {
    gBgFx->unk_24 = a;
}

void func_080147C8(s32 a, s32 b) {
    gBgFx->unk_1C = a;
    gBgFx->unk_20 = b;
}

void func_080147D8(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBgBlend(gBgFx->unk_00, 5, 16);
    gBgFx->x = x;
    gBgFx->y = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    BgAnimStart(&gUnk_09EDA900, sx, sy);
    gBgFx->update = func_08012908;
    gBgFx->flags |= 0x10;
}

void func_08014850(void) {
    switch (gBgFx->unk_26) {
    case 0:
#ifdef VERSION_EU
        if (gBgFx->unk_08 == 20) {
#else
        if (gBgFx->unk_08 == 21) {
#endif
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 16, 16, 48);
        }
        break;
    case 1:
#ifdef VERSION_EU
        if (gBgFx->unk_08 == 20) {
#else
        if (gBgFx->unk_08 == 25) {
#endif
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 24, 24, 48);
        }
        break;
    case 2:
        if (gBgFx->unk_08 == 33) {
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 32, 32, 48);
        }
        break;
    }
    gBgFx->unk_08++;
    func_08012908();
}

void func_080148E0(u16 a, s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_4C = 20;
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    gBgFx->unk_26 = a;
    WorldToScreen(&sx, &sy, x, y, 0);

    switch (a) {
    case 0:
        BgAnimStart(&gUnk_09EDA8A0, sx, sy);
        m4aSongNumStart(SONG_EF_STOP00);
        break;
    case 1:
        BgAnimStart(&gUnk_09EDA8B8, sx, sy);
        m4aSongNumStart(SONG_EF_STOP01);
        break;
    case 2:
    default:
        BgAnimStart(&gUnk_09EDA8D0, sx, sy);
        m4aSongNumStart(SONG_EF_STOP02);
        break;
    }
    gBgFx->update = func_08014850;
}

void func_080149BC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    BgAnimStart(&gUnk_09EDA948, sx, sy);
    BgAnimSetLoopStartFrame(8);
    gBgFx->update = func_08012908;
    gBgFx->flags |= 0x10;
}

void func_08014A34(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    BgAnimStart(&gUnk_09EDA960, sx, sy);
    BgAnimSetLoopStartFrame(7);
    gBgFx->update = func_08012908;
    gBgFx->flags |= 0x10;
}

void func_08014AAC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    m4aSongNumStart(SONG_BTL_GF_LOOP);
    BgAnimStart(&gUnk_09EDAA50, sx, sy);
    BgAnimSetLoopStartFrame(4);
    gBgFx->update = func_08012908;
    gBgFx->flags |= 0x10;
}

void func_08014B30(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    BgAnimStart(&gUnk_09EDA7E0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08012908;
    gBgFx->flags |= 0x10;
}
void func_08014BA8(void) {
    s16 sx;
    s16 sy;
    s16 t;
    u8 r;

    t = gBgFx->unk_08 % 8;

    if (t <= 3) {
        SetBlendAlpha(t, 16);
    } else {
        SetBlendAlpha(8 - t, 16);
    }

    if (gBgFx->unk_0A == 0 && BgAnimIsStopped()) {
        gBgFx->x = gBgFx->unk_28;
        gBgFx->y = gBgFx->unk_2C;
        gBgFx->z = gBgFx->unk_30;
        WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->x, gBgFx->z);
        gBgFx->unk_24 = 0;
        gBgFx->unk_4C = 20;

        switch (gBgFx->unk_26) {
        case 0:
            gBgFx->unk_28 = 128;
            gBgFx->unk_2C = 128;
            BgAnimStart(&gUnk_09EDA990, sx, sy);
            break;
        case 1:
            gBgFx->unk_28 = 256;
            gBgFx->unk_2C = 256;
            BgAnimStart(&gUnk_09EDA990, sx, sy);
            break;
        case 2:
        default:
            gBgFx->unk_28 = 512;
            gBgFx->unk_2C = 512;
            BgAnimStart(&gUnk_09EDA990, sx, sy);
            break;
        }

        if (gBgFx->flags & 1) {
            gBgFx->unk_28 = -gBgFx->unk_28;
        }

        m4aSongNumStart(SONG_EF_GRABI01);
        gBgFx->unk_0A++;
    } else if (gBgFx->unk_0A == 1) {
        if (gBgFx->unk_08 <= 29) {
            ApproachValue(&gBgFx->unk_1C, gBgFx->unk_28, 30 - gBgFx->unk_08);
            ApproachValue(&gBgFx->unk_20, gBgFx->unk_2C, 30 - gBgFx->unk_08);
        }

        if (gBgFx->unk_08 == 35) {
            switch (gBgFx->unk_26) {
            case 0:
                r = func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 24, 12, 256);
                break;
            case 1:
                r = func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 40, 20, 256);
                break;
            case 2:
            default:
                r = func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 80, 40, 256);
                break;
            }

            if (r) {
                m4aSongNumStart(SONG_EF_GRABI02);
            }
        }

        gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_28 = p;
    gBgFx->unk_2C = q;
    gBgFx->unk_30 = r;
    gBgFx->unk_48 = w;

    if (f != 0) {
        gBgFx->unk_1C = -gBgFx->unk_1C;
        gBgFx->flags |= 1;
    }
    gBgFx->unk_0A = 0;
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDA978, sx, sy);
    m4aSongNumStart(SONG_EF_GRABI00);
    gBgFx->unk_26 = a;
    gBgFx->update = func_08014BA8;
}

void func_08014E38(void) {
    s16 t = gBgFx->unk_08 % 8;
    if (t <= 3) {
        SetBlendAlpha(t, 16);
    } else {
        SetBlendAlpha(8 - t, 16);
    }

    if (gBgFx->unk_08 == 0x23) {
        if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 40, 20, 256)) {
            m4aSongNumStart(SONG_EF_GRABI02);
        }
    }
    func_08012908();
    gBgFx->unk_08++;
}

void func_08014EC0(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(2, 16);
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    gBgFx->unk_0A = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA990, sx, sy);
    m4aSongNumStart(SONG_EF_GRABI01);
    gBgFx->update = func_08014E38;
}

void func_08014F4C(void) {
    gBgFx->unk_1C += 0x80;
    gBgFx->unk_20 += 0x80;
    gBgFx->unk_24 += 3;

    if (gBgFx->flags & 1) {
        gBgFx->x += -0x300;
    } else {
        gBgFx->x += 0x300;
    }
    func_08012908();
    SetBlendAlpha(16, 8 - gBgFx->unk_0A);

    if (gBgFx->unk_0A > 7) {
        BgAnimStop();
    }

    if (gBgFx->unk_08 % 5 == 0) {
        gBgFx->unk_0A++;
    }
    gBgFx->unk_08++;
}

void func_08014FDC(s32 x, s32 y, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y - 0x1000;
    SetBlendAlpha(16, 8);

    if (f) {
        gBgFx->flags |= 1;
    }
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, 0);
    gBgFx->unk_1C = 128;
    gBgFx->unk_20 = 128;
    gBgFx->unk_24 = 0;
    gBgFx->unk_0A = 0;
    BgAnimStart(&gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08014F4C;
    gBgFx->unk_08 = 0;
    gBgFx->flags |= 0x10;
}

void func_0801508C(void) {
    if (gBgFx->unk_08 > 19) {
        gBgFx->unk_0A = (gBgFx->unk_08 - 20) / 2;
        SetBlendAlpha(16, 16 - gBgFx->unk_0A);

        if (gBgFx->unk_0A > 15) {
            BgAnimStop();
        }
    }
    gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = 0x100;
    gBgFx->unk_20 = 0x100;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA9C0, sx, sy);
    gBgFx->update = func_0801508C;
    m4aSongNumStart(SONG_EF_BFG_GASS);

    if (f == 0) {
        gBgFx->flags |= 1;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
    BgAnimSetLoopStartFrame(3);
}

void func_0801519C(void) {
    switch (gBgFx->unk_26) {
    case 0:
        SetBlendAlpha(16, gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        if (gBgFx->unk_08 > gBgFx->unk_0A) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    gBgFx->unk_26 = 0;
    gBgFx->unk_0A = 30;
    BgAnimStart(&gUnk_09EDA9F0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_0801519C;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_080152DC(void) {
    switch (gBgFx->unk_26) {
    case 0:
        if (gBgFx->unk_08 > 30) {
            FadeStartOut(2, 60);
            FadeLock();
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        if (FadeIsActive() == 0) {
            BgAnimStop();
            FadeStartIn(2, 120);
            FadeLock();
            gBgFx->update = 0;
            gBgFx->flags &= ~2;
        }
        break;
    }
    BgAnimSetTransform(0, gBgFx->unk_1C, gBgFx->unk_20);
    gBgFx->unk_1C += 20;
    gBgFx->unk_20 += 20;
}

void func_0801536C(void) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_26 = 0;
    gBgFx->unk_1C = 0x19;
    gBgFx->unk_20 = 0x19;
    BgAnimStart(&gUnk_09EDAA20, 0x78, 0x50);
    BgAnimSetLoopStartFrame(0);
    m4aSongNumStart(SONG_EF_DBOSS_DEAD);
    gBgFx->update = func_080152DC;
    gBgFx->flags |= 0x10;
}

void func_080153C8(void) {
    s16 t;
    s16 u;

    switch (gBgFx->unk_26) {
    case 0:
        t = gBgFx->unk_08;
        SetBlendAlpha(16, t);
        ApproachValueHalfSteps(&gBgFx->unk_1C, 0x100, 17 - t);
        gBgFx->unk_20 = gBgFx->unk_1C;

        if (t > 15) {
            gBgFx->unk_08 = gBgFx->unk_0A;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        ApproachValue(&gBgFx->x, gBgFx->unk_28, gBgFx->unk_08);
        ApproachValue(&gBgFx->y, gBgFx->unk_2C, gBgFx->unk_08);
        ApproachValue(&gBgFx->z, gBgFx->unk_30, gBgFx->unk_08);
        ApproachValue(&gBgFx->unk_1C, gBgFx->unk_3C, gBgFx->unk_08);
        gBgFx->unk_20 = gBgFx->unk_1C;
        u = (gBgFx->unk_1C * 3) >> 6;

        if (gBgFx->unk_08 <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, u, u, u)) {
            m4aSongNumStart(SONG_BTL_AN_WAVEHIT);
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08--;
        }
        break;
    case 2:
        t = gBgFx->unk_08;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_1C += 7;
            gBgFx->unk_20 += 7;
            gBgFx->z -= gBgFx->unk_1C;
            gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_28 = p;
    gBgFx->unk_2C = q;
    gBgFx->unk_30 = r;
    gBgFx->unk_0A = a;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAA08, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->unk_1C = 25;
    gBgFx->unk_20 = 25;
    gBgFx->update = func_080153C8;
    gBgFx->unk_26 = 0;
    gBgFx->unk_48 = s;
    gBgFx->unk_3C = t;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_080155BC(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    s32 t;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    t = sy << 8;
    gBgFx->unk_1C = 384;
    gBgFx->unk_20 = t / 40;
    if (gBgFx->unk_20 < 384) {
        gBgFx->unk_20 = 384;
    }
    BgAnimStart(&gUnk_09EDA798, sx, sy);
    m4aSongNumStart(SONG_EF_THUND01);
    func_08011F78(w, gBgFx->x, gBgFx->y, gBgFx->z, 16, 16, 256);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08015698(void) {
    s16 sx;
    s16 sy;
    s16 sx2;
    s16 sy2;

    if (gBgFx->unk_08 == 0 && BgAnimIsStopped()) {
        SetBlendAlpha(16, 16);
        gBgFx->x = gBgFx->unk_28;
        gBgFx->y = gBgFx->unk_2C;
        gBgFx->z = gBgFx->unk_30;
        WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
        gBgFx->unk_24 = 0;
        gBgFx->unk_1C = 384;
        gBgFx->unk_20 = (sy << 8) / 40;

        if (gBgFx->unk_20 < 384) {
            gBgFx->unk_20 = 384;
        }

        gBgFx->flags |= 4;

        switch (gBgFx->unk_26) {
        case 0:
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 16, 16, 256);
            BgAnimStart(&gUnk_09EDA798, sx, sy);
            m4aSongNumStart(SONG_EF_THUND01);
            break;
        case 1:
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 40, 40, 256);
            BgAnimStart(&gUnk_09EDA7B0, sx, sy);
            m4aSongNumStart(SONG_EF_THUND02);
            break;
        case 2:
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 64, 64, 256);
            BgAnimStart(&gUnk_09EDA7C8, sx, sy);
            m4aSongNumStart(SONG_EF_THUND03);
            break;
        }

        gBgFx->unk_08 = 1;
    } else if (gBgFx->unk_08 == 1) {
        s32 t;

        WorldToScreen(&sx2, &sy2, gBgFx->x, gBgFx->y, gBgFx->z);
        t = sy2 << 8;
        gBgFx->unk_20 = t / 40;

        if (gBgFx->unk_20 < 384) {
            gBgFx->unk_20 = 384;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_28 = p;
    gBgFx->unk_2C = q;
    gBgFx->unk_30 = r;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA768, sx, sy);
    m4aSongNumStart(SONG_EF_THUND00);
    gBgFx->unk_48 = s;
    gBgFx->update = func_08015698;
    gBgFx->unk_26 = a;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_080158E8(void) {
    s32 t;
    u16 v;

    switch (gBgFx->unk_26) {
    case 0:
        if (gBgFx->unk_08 == 0) {
            gBgFx->unk_0A = 40;
        }
        ApproachValue(&gBgFx->unk_3C, 0x1000, gBgFx->unk_0A);
        ApproachValue(&gBgFx->unk_1C, gBgFx->unk_28, gBgFx->unk_0A);
        ApproachValue(&gBgFx->unk_20, 0x100, gBgFx->unk_0A);
        ApproachValue(&gBgFx->unk_40, 0, gBgFx->unk_0A);
        gBgFx->unk_24 = gBgFx->unk_40 >> 8;
        t = gBgFx->unk_1C;

        if (t < 0) {
            t = -t;
        }
        t *= 44;

        if (gBgFx->flags & 1) {
            func_08011F78(gBgFx->unk_48, gBgFx->x + t, gBgFx->y,
                gBgFx->z, t << 8 >> 16, 24, 24);
        } else {
            func_08011F78(gBgFx->unk_48, gBgFx->x - t, gBgFx->y,
                gBgFx->z, t << 8 >> 16, 24, 24);
        }
        SetBlendAlpha(16, gBgFx->unk_3C >> 8);

        if (--gBgFx->unk_0A <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        v = gBgFx->unk_08;

        if (gBgFx->unk_08 > 50) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
            break;
        }
        t = gBgFx->unk_1C;

        if (t < 0) {
            t = -t;
        }
        t *= 44;

        if (gBgFx->flags & 1) {
            gBgFx->unk_40 = -gSineTable[(v * 4) & 0xFF] * 6;
            func_08011F78(gBgFx->unk_48, gBgFx->x + t, gBgFx->y,
                gBgFx->z, t << 8 >> 16, 24, 24);
        } else {
            gBgFx->unk_40 = gSineTable[(v * 4) & 0xFF] * 6;
            func_08011F78(gBgFx->unk_48, gBgFx->x - t, gBgFx->y,
                gBgFx->z, t << 8 >> 16, 24, 24);
        }
        gBgFx->unk_24 = gBgFx->unk_40 >> 8;
        gBgFx->unk_08++;
        break;
    case 2:
        if (gBgFx->unk_08 == 0) {
            gBgFx->unk_0A = 20;
        }
        ApproachValue(&gBgFx->unk_3C, 0, gBgFx->unk_0A);
        ApproachValue(&gBgFx->unk_20, 128, gBgFx->unk_0A);

        if (gBgFx->flags & 1) {
            ApproachValue(&gBgFx->unk_1C, -128, gBgFx->unk_0A);
            ApproachValue(&gBgFx->unk_40, 0x800, gBgFx->unk_0A);
        } else {
            ApproachValue(&gBgFx->unk_1C, 128, gBgFx->unk_0A);
            ApproachValue(&gBgFx->unk_40, -0x800, gBgFx->unk_0A);
        }
        gBgFx->unk_24 = gBgFx->unk_40 >> 8;
        SetBlendAlpha(16, gBgFx->unk_3C >> 8);

        if (--gBgFx->unk_0A <= 0) {
            BgAnimStop();
            gBgFx->unk_26 = 99;
        } else {
            gBgFx->unk_08++;
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
        gBgFx->flags |= 1;
    }

    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->unk_20 = 25;

    switch (a) {
    case 0:
        gBgFx->unk_28 = 256;
        break;
    case 1:
        gBgFx->unk_28 = 384;
        break;
    case 2:
        gBgFx->unk_28 = 512;
        break;
    }

    if (gBgFx->flags & 1) {
        gBgFx->unk_1C = -25;
        gBgFx->unk_40 = 2048;
        gBgFx->unk_28 = -gBgFx->unk_28;
    } else {
        gBgFx->unk_1C = 25;
        gBgFx->unk_40 = -2048;
    }

    gBgFx->unk_26 = 0;
    gBgFx->unk_3C = 0;
    BgAnimStart(&gUnk_09EDAA68, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_080158E8;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08015C80(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->unk_1C = 76;
    gBgFx->unk_20 = 76;
    gBgFx->unk_28 = 12;
    gBgFx->unk_2C = 12;
    BgAnimStart(&gUnk_09EDA618, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08013420;
}
void func_08015D04(void) {
    if (gBgFx->unk_08 <= 16) {
        SetBlendAlpha(16, gBgFx->unk_08);
        gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = 0x100;
    gBgFx->unk_20 = 0x100;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->flags |= 0x20;
    SetBlendAlpha(16, 0);
    gBgFx->unk_26 = 0;
    BgAnimStart(&gUnk_09EDAA80, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08015D04;
}
void func_08015DC8(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->unk_1C = 0x200;
    gBgFx->unk_20 = 0x200;
    BgAnimSetLoopStartFrame(7);
    BgAnimStart(&gUnk_09EDAA98, sx, sy);
    gBgFx->update = func_08012908;
}

void func_08015E3C(void) {
    switch (gBgFx->unk_26) {
    case 0: {
        u16 t = gBgFx->unk_08;

        if ((s16)t <= 64) {
            SetBlendAlpha(16, (s16)t >> 2);
            gBgFx->unk_08++;
        } else {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26++;
        }
        gBgFx->unk_1C += 25;
        gBgFx->unk_20 += 25;
        break;
    }
    case 1: {
        u16 t;

        gBgFx->unk_1C += 0x100;
        gBgFx->unk_20 += 0x100;
        t = gBgFx->unk_08;

        if ((s16)t > 32) {
            func_08011F78(87, gBgFx->x, gBgFx->y, 0, 0x100, 0x100, 0x100);
            func_08019050(1, 0x100, gBtlWork->x2, gBtlWork->y2);
            FadeStartIn(2, 60);
            gBgFx->unk_08 = 0;
            gBgFx->unk_26++;
        } else {
            gBgFx->unk_08 = t + 1;
        }
        break;
    }
    case 2: {
        u16 t = gBgFx->unk_08;

        if ((s16)t <= 15) {
            SetBlendAlpha(16, 16 - t);
            gBgFx->unk_08++;
        } else {
            BgAnimStop();
        }
        break;
    }
    }
    gBgFx->unk_24++;
    func_08012908();
}
void func_08015F3C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    SetBlendAlpha(16, 0);
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    gBgFx->unk_1C = 0x300;
    gBgFx->unk_20 = 0x300;
    BgAnimStart(&gUnk_09EDAAB0, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->unk_08 = 8;
    gBgFx->unk_26 = 0;
    gBgFx->flags |= 0x10;
    gBgFx->update = func_08015E3C;
    FadeStartOut(2, 40);
    func_08019050(80, 204, x, y + z + 0x2000);
}

void func_08015FF4(void) {
    if (gBgFx->unk_08 > 0) {
        ApproachValueHalfSteps(&gBgFx->unk_1C, 0x100, gBgFx->unk_08);
        ApproachValueHalfSteps(&gBgFx->unk_20, 0x100, gBgFx->unk_08);
        gBgFx->unk_08--;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->unk_1C = 0x19;
    gBgFx->unk_20 = 0x19;
    m4aSongNumStart(SONG_EF_RAGNA01);
    BgAnimStart(&gUnk_09EDAAC8, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->unk_08 = 0x23;
    gBgFx->update = func_08015FF4;
}

void func_080160C0(void) {
    u16 k;
    u16 v;
    s16 t;

    BgAnimGetFrameState(&k, &v);

    switch (k) {
    case 4:
        func_08011F78(91, gBgFx->x + gBgFx->unk_1C * 40, gBgFx->y, gBgFx->z, 32, 32, 50);
        break;
    case 5:
        if (v == 0) {
            gBgFx->unk_26 = 1;
        }
        break;
    case 6:
        if (v == 0) {
            gBgFx->unk_26 = 2;
        }
        break;
    }

    switch (gBgFx->unk_26) {
    case 1:
        gBgFx->unk_3C += 51;

        if (gBgFx->flags & 1) {
            gBgFx->x -= gBgFx->unk_3C;
        } else {
            gBgFx->x += gBgFx->unk_3C;
        }
        break;
    case 2:
        gBgFx->unk_3C += 51;

        if (gBgFx->flags & 1) {
            gBgFx->x -= gBgFx->unk_3C;
            gBgFx->unk_1C -= 51;
        } else {
            gBgFx->x += gBgFx->unk_3C;
            gBgFx->unk_1C += 51;
        }
        func_08011F78(91, gBgFx->x + gBgFx->unk_1C * 40, gBgFx->y, gBgFx->z, 32, 32, 50);

        if (gBgFx->unk_08 > 20) {
            t = 36 - gBgFx->unk_08;
            SetBlendAlpha(16, t);

            if (t <= 0) {
                BgAnimStop();
            }
        }
        gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gBgFx->unk_26 = 0;

    if (f) {
        gBgFx->flags |= 1;
        gBgFx->unk_1C = -0x100;
    }
    gBgFx->unk_3C = 0;
    m4aSongNumStart(SONG_EF_RAGNA02);
    BgAnimStart(&gUnk_09EDAAF8, sx, sy);
    BgAnimSetLoopStartFrame(6);
    gBgFx->update = func_080160C0;
}

void func_080162A8(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAA20, sx, sy);
    gBgFx->unk_1C = w;
    gBgFx->unk_20 = w;
    gBgFx->update = func_08012BCC;
}

BtlObj* func_08016320(void) {
    if (gBtlWork->flags & 0x4000) {
        if (gBtlWork->flags & 0x20000000) {
            return gBtlWork->actor;
        }
        return gUnk_02039B9C->actor;
    }

    if (gBtlWork->actor2 != 0) {
        return gBtlWork->actor2;
    }
    return ListPoolFirst(&gBtlWork->pool);
}

void func_08016374(s16 a) {
    BtlObj* o;

    if (gBtlWork->flags & 0x4000) {
        if (GetRandom() % 5) {
            if (gBtlWork->flags & 0x20000000) {
                func_08019190(gBtlWork->actor, 2);
            } else {
                func_08019190(gUnk_02039B9C->actor, 2);
            }
        } else {
            o = gUnk_02039B9C->actor;
            o->unk_02C = a;

            if (a > o->unk_02E) {
                o->unk_02C = o->unk_02E;
            }
            o = gBtlWork->actor;
            o->unk_02C = a;

            if (a > o->unk_02E) {
                o->unk_02C = o->unk_02E;
            }
        }
    } else {
        o = ListPoolFirst(&gBtlWork->pool);

        while (o != 0) {
            if (o->flags & 0x40000000) {
                func_08019190(o, 0);
            } else {
                o->unk_02C = a;

                if (a > o->unk_02E) {
                    o->unk_02C = o->unk_02E;
                }
            }
            o = ListPoolNext(&o->node);
        }
    }
}
void func_08016468(void) {
    BtlObj* o;

    switch (gBgFx->unk_26) {
    case 0:
        gBgFx->unk_1C = (gSineTable[((u16)gBgFx->unk_08 * 4) & 0xFF] >> 3) + 89;

        if (gBgFx->unk_0A > 0) {
            ApproachValueHalfSteps(&gBgFx->z, gBgFx->unk_30 - 0x2000, gBgFx->unk_0A);
            gBgFx->unk_0A--;
        } else {
            gBgFx->unk_26 = 1;
            gBgFx->unk_0A = 60;
        }
        break;
    case 1:
        gBgFx->unk_1C = (gSineTable[((u16)gBgFx->unk_08 * 4) & 0xFF] >> 3) + 89;
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_26 = 2;
            gBgFx->unk_0A = 50;
        }
        break;
    case 2:
        gBgFx->unk_1C = (gSineTable[((u16)gBgFx->unk_08 * 4) & 0xFF] >> 3) + 89;
        o = func_08016320();

        if (o != 0) {
            ApproachValueHalfSteps(&gBgFx->x, o->x, gBgFx->unk_0A);
            ApproachValueHalfSteps(&gBgFx->y, o->y, gBgFx->unk_0A);
            ApproachValueHalfSteps(&gBgFx->z, o->z - (o->unk_0A2 << 8), gBgFx->unk_0A);
        }
        gBgFx->unk_0A--;

        if (o != 0) {
            if (gBgFx->unk_0A > 0) {
                break;
            }
            func_08016374(o->unk_02C);
        }
        gBgFx->unk_26 = 3;
        m4aSongNumStart(SONG_EF_SYNC2);
        gBgFx->unk_0A = 16;
        break;
    case 3:
        gBgFx->unk_1C += 166;
        gBgFx->unk_20 = gBgFx->unk_1C;
        SetBlendAlpha(16, gBgFx->unk_0A);
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            BgAnimStop();
        }
        break;
    }
    gBgFx->unk_20 = gBgFx->unk_1C;
    gBgFx->unk_08++;
    func_08012908();
}
void func_080165DC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_30 = z;
    gBgFx->unk_26 = 0;
    gBgFx->unk_0A = 50;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAA20, sx, sy);
    gBgFx->unk_1C = 89;
    gBgFx->unk_20 = 89;
    gBgFx->update = func_08016468;
    m4aSongNumStart(SONG_EF_SYNC1);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08016684(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAB70, sx, sy);
    gBgFx->unk_1C = 0x200;
    gBgFx->unk_20 = 0x200;
    gBgFx->update = func_08012908;
}

void func_080166F8(void) {
    gBgFx->unk_1C += gBgFx->unk_28;
    gBgFx->unk_20 += gBgFx->unk_2C;
    func_08012908();

    if (gBgFx->unk_08 > 5) {
        s16 t = gBgFx->unk_08 - 5;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            BgAnimStop();
        }
    }
    gBgFx->unk_08++;
}

void func_08016750(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAA20, sx, sy);
    gBgFx->unk_1C = 38;
    gBgFx->unk_20 = 256;
    gBgFx->unk_28 = 7;
    gBgFx->unk_2C = 153;

    if (f) {
        gBgFx->unk_24 += 40;
    } else {
        gBgFx->unk_24 -= 40;
    }
    gBgFx->update = func_080166F8;
}
void func_080167F8(void) {
    switch (gBgFx->unk_26) {
    case 0:
        SetBlendAlpha(16, (gBgFx->unk_08 >> 1) + 8);
        ApproachValueHalfSteps(&gBgFx->unk_1C, gBgFx->unk_28, 17 - gBgFx->unk_08);
        ApproachValueHalfSteps(&gBgFx->unk_20, gBgFx->unk_2C, 17 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        if (gBgFx->unk_08 > gBgFx->unk_0A) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_0A = a;
    gBgFx->unk_26 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAB10, sx, sy);

    if (f) {
        gBgFx->unk_28 = w;
        gBgFx->unk_1C = 76;
    } else {
        gBgFx->unk_28 = -w;
        gBgFx->unk_1C = -76;
    }
    gBgFx->unk_2C = w;
    gBgFx->unk_20 = 76;
    m4aSongNumStart(SONG_EF_UR_BEEM);
    gBgFx->update = func_080167F8;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_080169A0(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_26 = 0;
    gBgFx->unk_0A = 45;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAB40, sx, sy);

    if (f) {
        gBgFx->unk_1C = -0x100;
    } else {
        gBgFx->unk_1C = 0x100;
    }
    gBgFx->unk_20 = 0x100;
    gBgFx->update = func_0801519C;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_08016A64(void) {
    if (gBgFx->flags & 1) {
        gBgFx->x += 0x700;
    } else {
        gBgFx->x += -0x700;
    }

    if (gBgFx->x < (gBtlWork->unk_0DA - 0x40) << 8 || gBgFx->x > (gBtlWork->unk_0DC + 0x40) << 8) {
        BgAnimStop();
    } else if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 16, 16, 48)) {
        m4aSongNumStart(SONG_BTL_AN_WAVEHIT);
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAB58, sx, sy);

    if (f) {
        gBgFx->unk_1C = 0x100;
    } else {
        gBgFx->unk_1C = -0x100;
        gBgFx->flags |= 1;
    }
    gBgFx->unk_20 = 0x100;
    m4aSongNumStart(SONG_EF_AN_WAVE);
    gBgFx->update = func_08016A64;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08016BCC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    BgAnimStart(&gUnk_09EDA888, sx, sy);
    gBgFx->unk_1C = 0x900;
    gBgFx->unk_20 = 0x900;
    gBgFx->update = func_08012908;
}
void func_08016C40(s32 x, s32 y, s32 z, s32 w, u8 f, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_0A = a;
    gBgFx->unk_26 = 0;
    gBgFx->unk_24 = f;
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDAB28, sx, sy);
    gBgFx->unk_20 = w;
    gBgFx->update = func_0801519C;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
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

    if (gBgFx->unk_08 > 0) {
        if (a > 7) {
            ang = gBgFx->unk_24;

            if (gBgFx->flags & 1) {
                ApproachAngle(&ang, GetAngle(gBgFx->x, gBgFx->y,
                                             gBgFx->unk_28, gBgFx->unk_2C) + 64, 5);
            } else {
                ApproachAngle(&ang, GetAngle(gBgFx->x, gBgFx->y,
                                             gBgFx->unk_28, gBgFx->unk_2C) - 64, 5);
            }

            gBgFx->unk_24 = ang;
            ApproachValue(&gBgFx->x, gBgFx->unk_28, gBgFx->unk_08);
            ApproachValue(&gBgFx->y, gBgFx->unk_2C, gBgFx->unk_08);
            ApproachValue(&gBgFx->z, gBgFx->unk_30, gBgFx->unk_08);

            if (func_08011E3C(gBgFx->x, gBgFx->y, gBgFx->z,
                              8, 8, 16)) {
                gBgFx->unk_08 = -1;
            } else {
                gBgFx->unk_08--;
            }
        } else if (a > 2) {
            if (gBgFx->flags & 1) {
                dx = ((7 - a) << 8) * 7;
            } else {
                s32 t = 7 - a;
                t *= 256;
                dx = t * -7;
            }

            if (func_08011E3C(gBgFx->x + dx, gBgFx->y,
                              gBgFx->z, 8, 8, 16)) {
                gBgFx->unk_08 = -1;
            }
        }
    }

    switch (gBgFx->unk_08) {
    case 0:
        gBgFx->update = func_08012BCC;
        break;
    case -1:
        m4aSongNumStart(SONG_EF_DRHEET);
        SetBlendAlpha(16, 11);
        gBgFx->unk_24 = 0;
        gBgFx->unk_1C = 0x500;
        gBgFx->unk_20 = 0x500;
        gBgFx->x += dx;
        gBgFx->unk_4C = 20;
        WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y,
                      gBgFx->z);
        BgAnimStart(&gUnk_09EDA600, sx, sy);
        m4aSongNumStart(SONG_EF_FIRE03);
        gBgFx->unk_08 = -2;
        gBgFx->unk_0A = 0;
        break;
    case -2:
        if (gBgFx->unk_0A == 7) {
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y,
                          gBgFx->z, 256, 256, 256);
        }

        gBgFx->unk_1C += 51;
        gBgFx->unk_20 += 51;
        gBgFx->unk_0A++;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA570, sx, sy);
    m4aSongNumStart(SONG_EF_DRHEET);
    BgAnimSetLoopStartFrame(8);
    gBgFx->update = func_08016D00;
    gBgFx->unk_28 = p;
    gBgFx->unk_2C = q;
    gBgFx->unk_30 = r;
    gBgFx->unk_08 = 15;
    gBgFx->unk_26 = 3;
    gBgFx->unk_48 = w;

    if (f) {
        gBgFx->flags |= 1;
        gBgFx->unk_1C = -0x100;
    }
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08017008(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_1C = 0x180;
    gBgFx->unk_20 = 0x180;
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA858, sx, sy);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_0801709C(void) {
    switch (gBgFx->unk_26) {
    case 0:
        SetBlendAlpha(16, gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        if (gBgFx->unk_08 > gBgFx->unk_0A) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            BgAnimStop();
            gBgFx->update = 0;
            gBgFx->flags &= ~2;
        } else {
            gBgFx->unk_08++;
        }
        break;
    }
}
void func_08017138(u16 a) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_0A = a;
    gBgFx->unk_26 = 0;
    BgAnimStart(&gUnk_09EDABD0, 120, 80);
    gBgFx->update = func_0801709C;
    BgAnimSetLoopStartFrame(0);
    gBgFx->flags |= 0x10;
}
void func_0801718C(void) {
    u16 t;
    s32 w;
    t = (gSineTable[(gBgFx->unk_0C / 3) & 0xFF] * 10240) >> 16;
    w = ((abs(gSineTable[(u8)gBgFx->unk_0C]) >> 1) + 0x100) * 0x133 >> 8;
    BgAnimSetTransform(t + 15, 0x133, w);
    func_0801709C();
    gBgFx->unk_0C++;
}
void func_080171FC(u16 a) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->unk_0A = a;
    gBgFx->unk_0C = 0;
    gBgFx->unk_26 = 0;
    BgAnimStart(&gUnk_09EDABE8, 120, 80);
    BgAnimSetTransform(10, 0x133, 0x133);
    gBgFx->update = func_0801718C;
    BgAnimSetLoopStartFrame(0);
    gBgFx->flags |= 0x10;
}

void func_08017260(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA5A0, sx, sy);
    gBgFx->update = func_08012908;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_080172F8(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDA6F0, sx, sy);
    gBgFx->update = func_08012908;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08017390(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAB88, sx, sy);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
}
void func_08017410(void) {
    if (gBgFx->unk_0C > 0) {
        ApproachValueHalfSteps(&gBgFx->unk_1C, 0x200, gBgFx->unk_0C);
        gBgFx->unk_0C--;
    }

    if (gBgFx->unk_0E > 0) {
        ApproachValue(&gBgFx->unk_20, 0x180, gBgFx->unk_0E);
        gBgFx->unk_0E--;
    }

    switch (gBgFx->unk_26) {
    case 0: {
        u16 t;

        SetBlendAlpha(16, gBgFx->unk_08);
        t = gBgFx->unk_08;

        if ((s16)t > 15) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08 = t + 1;
        }
        break;
    }
    case 1: {
        u16 t;

        func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 32, 16, 256);
        t = gBgFx->unk_08;

        if ((s16)t > gBgFx->unk_0A) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08 = t + 1;
        }
        break;
    }
    case 2: {
        u16 a = gBgFx->unk_08;
        u16 t;

        SetBlendAlpha(16, 16 - ((s16)a >> 1));
        ApproachValue(&gBgFx->unk_1C, 10, 33 - gBgFx->unk_08);
        t = gBgFx->unk_08;

        if ((s16)t > 31) {
            BgAnimStop();
        } else {
            gBgFx->unk_08 = t + 1;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_0A = 120;
    gBgFx->unk_0C = 60;
    gBgFx->unk_0E = 20;
    gBgFx->unk_26 = 0;
    gBgFx->unk_48 = w;
    gBgFx->unk_1C = 10;
    gBgFx->unk_20 = 10;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAC00, sx, sy);
    gBgFx->update = func_08017410;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_080175BC(BtlObj* a, BtlObj* b, u8 c, u8 d) {
    s32 h;
    s32 dx;
    s32 dy;
    s32 t;
    s32 nx;
    s32 ny;

    if (d) {
        b->angle = GetAngle(a->x, a->y, b->x, b->y);
        b->unk_0A8 = 0;
    }
    dx = b->x - gBgFx->x;

    if (dx >= 0 ? dx <= 0x4FFF : gBgFx->x - b->x <= 0x4FFF) {
        dy = b->y - gBgFx->y;

        if (dy >= 0 ? dy <= 0x27FF : gBgFx->y - b->y <= 0x27FF) {
            if (gBgFx->flags & 1) {
                h = b->unk_0A8 - ((gBgFx->x - b->x) >> 1);
            } else {
                h = b->unk_0A8 + ((gBgFx->x - b->x) >> 1);
            }

            if (h > 0) {
                h = 0;
            }
            t = -(h >> 9);
            nx = gBgFx->x + gSineTable[(b->angle + c) & 0xFF] * (s16)t;
            ny = gBgFx->y + -gSineTable[((b->angle + c) & 0xFF) + 64] * ((s16)t >> 1);

            if (b->x < nx) {
                b->flags &= ~4;
            } else {
                b->flags |= 4;
            }
            b->x += (nx - b->x) >> 3;
            b->y += (ny - b->y) >> 3;
            b->z += (h - b->z) >> 2;
            b->unk_0A8 -= 110;
        }
    }
}

void func_08017728(u8 a, u8 b) {
    BtlObj* p;
    BtlObj* o;

    if (gBtlWork->flags & 0x4000) {
        if (gBtlWork->flags & 0x20000000) {
            p = gBtlWork->actor;
            o = gUnk_02039B9C->actor;
        } else {
            p = gUnk_02039B9C->actor;
            o = gBtlWork->actor;
        }

        func_080175BC(p, o, a, b);
    } else {
        p = gBtlWork->actor;
        o = ListPoolFirst(&gBtlWork->pool);

        while (o != 0) {
            if (!(o->flags & 0x40000000) && o->unk_000 != 31) {
                func_080175BC(p, o, a, b);
            }

            o = ListPoolNext(&o->node);
        }
    }
}
void func_080177EC(void) {
    u16 alpha;
    s16 v;
    u32 u;

    switch (gBgFx->unk_26) {
    case 0:
        v = 17 - gBgFx->unk_08;

        if (gBgFx->flags & 1) {
            ApproachValueHalfSteps(&gBgFx->unk_1C, -0x100, v);
        } else {
            ApproachValueHalfSteps(&gBgFx->unk_1C, 0x100, v);
        }

        ApproachValueHalfSteps(&gBgFx->unk_20, 0x100, v);
        SetBlendAlpha(16, gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        u = (u16)gBgFx->unk_08;
        gBgFx->unk_20 = abs(gSineTable[(u8)gBgFx->unk_08] >> 1) + 0x100;

        if (gBgFx->flags & 1) {
            if ((u16)u == 0) {
                func_08017728(-u * 8, 1);
            } else {
                func_08017728(-u * 8, 0);
            }
        } else {
            if ((u16)u == 0) {
                func_08017728(u * 8, 1);
            } else {
                func_08017728(u * 8, 0);
            }
        }

        if (gBgFx->unk_08 > gBgFx->unk_0A) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y,
                          gBgFx->z, 40, 20, 256);
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 2:
        alpha = 16;
        v = gBgFx->unk_08;
        u = v;
        alpha -= u;
        SetBlendAlpha(16, alpha);

        if (gBgFx->flags & 1) {
            ApproachValue(&gBgFx->unk_1C, -10, 17 - u);
        } else {
            ApproachValue(&gBgFx->unk_1C, 10, 17 - u);
        }

        ApproachValue(&gBgFx->unk_20, 768, 17 - v);

        if (v > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
        }
        break;
    }

    if (gBgFx->flags & 1) {
        gBgFx->x -= 102;
    } else {
        gBgFx->x += 102;
    }

    gBgFx->unk_3C = 0;
    func_0801C6D4(&gBgFx->x, &gBgFx->y, &gBgFx->z,
                  &gBgFx->unk_3C);
    ClampBattlePosition(&gBgFx->x, &gBgFx->y, -16, 0);
    func_08012908();
}
void func_080179F8(s32 x, s32 y, s32 z, s32 w, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_0A = 220;
    gBgFx->unk_0C = 0;
    gBgFx->unk_26 = 0;
    gBgFx->unk_48 = w;
    gBgFx->unk_20 = 10;

    if (f) {
        gBgFx->unk_1C = -10;
        gBgFx->flags |= 1;
    } else {
        gBgFx->unk_1C = 10;
    }
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAC18, sx, sy);
    gBgFx->update = func_080177EC;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08017AC0(void) {
    s16 v;
    s16 w;

    switch (gBgFx->unk_26) {
    case 0:
        gBgFx->unk_1C += 0x80;

        if (gBgFx->unk_08 > 60) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        v = gBgFx->unk_08;
        SetBlendAlpha(16, v + 8);

        if (v > 7) {
#ifdef VERSION_EU
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y + 0x1000, 0, 0x100, 0x100, 0x100);
#else
            func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y + 0x1000, 0, 0x100, 0x100, 8);
#endif
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 2:
        w = gBgFx->unk_08 >> 2;
        SetBlendAlpha(16, 16 - w);

        if (w > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
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
    gBgFx->x = x;
    gBgFx->y = gBtlWork->unk_0DE << 8;
    gBgFx->z = 0;
    gBgFx->unk_48 = w;
    gBgFx->unk_1C = 10;
    gBgFx->unk_20 = -((gBtlWork->unk_0E0 - gBtlWork->unk_0DE) << 8) / 96;
    WorldToScreen(&sx, &sy, x, gBgFx->y, 0);
    BgAnimStart(&gUnk_09EDAC00, sx, sy);
    gBgFx->flags |= 0x20;
    gBgFx->unk_26 = 0;
    SetBlendAlpha(16, 8);
    gBgFx->update = func_08017AC0;
    BgAnimSetLoopStartFrame(0);
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08017C54(void) {
    switch (gBgFx->unk_26) {
    case 0:
        ApproachValue(&gBgFx->x, gBgFx->unk_28, gBgFx->unk_0A);

        if (gBgFx->flags & 1) {
            ApproachValue(&gBgFx->unk_1C, -256, gBgFx->unk_0A);
        } else {
            ApproachValue(&gBgFx->unk_1C, 256, gBgFx->unk_0A);
        }

        gBgFx->unk_20 = abs(gBgFx->unk_1C);
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_26 = 1;
            gBgFx->unk_0A = 16;
        }
        break;
    case 1:
        if (gBgFx->flags & 1) {
            if (func_08011F78(gBgFx->unk_48, gBgFx->x - 0x1000, gBgFx->y + 0x2000, 0, 20, 32, 64) || func_08011F78(gBgFx->unk_48, gBgFx->x + 0x1000, gBgFx->y - 0x2000, 0, 20, 32, 64)) {
                gBgFx->unk_26 = 2;
                m4aSongNumStart(SONG_EF_FIRE01);
            }
        } else if (func_08011F78(gBgFx->unk_48, gBgFx->x - 0x1000, gBgFx->y - 0x2000, 0, 20, 32, 64)) {
            gBgFx->unk_26 = 2;
            m4aSongNumStart(SONG_EF_FIRE01);
        } else if (func_08011F78(gBgFx->unk_48, gBgFx->x + 0x1000, gBgFx->y + 0x2000, 0, 20, 32, 64)) {
            gBgFx->unk_26 = 2;
            m4aSongNumStart(SONG_EF_FIRE01);
        }

        if (gBgFx->flags & 1) {
            if (gBtlWork->actor->x < gBgFx->x) {
                gBgFx->unk_26 = 2;
            }
        } else {
            if (gBtlWork->actor->x > gBgFx->x) {
                gBgFx->unk_26 = 2;
            }
        }
        break;
    case 2:
        SetBlendAlpha(16, gBgFx->unk_0A);

        if (gBgFx->unk_0A <= 0) {
            BgAnimStop();
        } else {
            gBgFx->unk_0A--;
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
    gBgFx->unk_26 = 0;
    gBgFx->x = x;
    gBgFx->y = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
    gBgFx->z = 0;
    gBgFx->unk_48 = w;
    gBgFx->unk_0A = 20;
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, 0);
    BgAnimStart(&gUnk_09EDAC60, sx, sy);

    if (f) {
        gBgFx->unk_1C = 10;
        gBgFx->unk_28 = x - 0x3700;
    } else {
        gBgFx->unk_1C = -10;
        gBgFx->unk_28 = x + 0x3700;
        gBgFx->flags |= 1;
    }
    gBgFx->unk_20 = 10;
    gBgFx->flags |= 0x20;
    gBgFx->update = func_08017C54;
    BgAnimSetLoopStartFrame(0);
}

void func_08017EF4(void) {
    u16 k;
    u16 t;
    ApproachValue(&gBgFx->unk_1C, 0x300, gBgFx->unk_0A);
    gBgFx->unk_20 = gBgFx->unk_1C;
    gBgFx->unk_0A--;
    BgAnimGetFrameState(&k, 0);

    if (k <= 4) {
        t = (gBgFx->unk_1C * 5) >> 5;
        if (func_08011F78(0x13D, gBgFx->x, gBgFx->y, gBgFx->z, (s16)t, (s16)t >> 1, 1)) {
            m4aSongNumStart(SONG_BTL_MARL_GROUNDHIT);
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAC78, sx, sy);
    gBgFx->unk_1C = 0x80;
    gBgFx->unk_20 = 0x80;
    gBgFx->unk_0A = BgAnimGetDuration(BgAnimGetCurrent());
    gBgFx->flags |= 0x20;
    gBgFx->update = func_08017EF4;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_0801801C(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAC90, sx, sy);
    gBgFx->unk_1C = 0x80;
    gBgFx->unk_20 = 0x80;
    gBgFx->unk_0A = BgAnimGetDuration(BgAnimGetCurrent());
    gBgFx->flags |= 0x20;
    gBgFx->update = func_08017EF4;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_080180C8(void) {
    switch (gBgFx->unk_26) {
    case 0:
        if (gBgFx->unk_08 > 50) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        gBgFx->unk_08 = 0;
        gBgFx->unk_26 = 2;

        if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 0x100, 0x100, 0x100)) {
            m4aSongNumStart(SONG_BTL_ETC_HIT05);
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
        }
        break;
    }
    gBgFx->unk_28 += 30;
    gBgFx->unk_24 += gBgFx->unk_28 >> 8;
    gBgFx->unk_1C += 10;
    gBgFx->unk_20 = gBgFx->unk_1C;
    func_08012908();
}
void func_08018184(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDACC0, sx, sy);
    gBgFx->unk_26 = 0;
    gBgFx->unk_1C = 5;
    gBgFx->unk_20 = 5;
    gBgFx->unk_28 = 256;
    gBgFx->flags |= 0x10;
    m4aSongNumStart(SONG_EF_MARL_HANABIRA);
    gBgFx->update = func_080180C8;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08018240(void) {
    if ((s16)gBtlWork->unk_072 != 0) {
        func_08012908();
        return;
    }

    if (gBgFx->flags & 1) {
        gBgFx->unk_24 += 3;
    } else {
        gBgFx->unk_24 -= 3;
    }
    gBgFx->x = gBgFx->unk_28 + ((gSineTable[gBgFx->unk_24] * gBgFx->unk_3C) >> 8);
    gBgFx->z = gBgFx->unk_30 + ((-gSineTable[gBgFx->unk_24 + 64] * gBgFx->unk_3C) >> 8);

    if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, 10, 5, 72)) {
        m4aSongNumStart(SONG_BTL_MARL_EFEHIT);
    }

    switch (gBgFx->unk_26) {
    case 0:
        SetBlendAlpha(16, (u16)gBgFx->unk_08 * 2);

        if (gBgFx->unk_08 > 7) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        if (gBgFx->unk_08 > 30) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 2;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - (u16)gBgFx->unk_08 * 2);

        if (gBgFx->unk_08 > 7) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
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
    gBgFx->unk_48 = v;

    if (w > 0) {
        gBgFx->unk_1C = -0x180;
        gBgFx->flags |= 1;
        x -= 0x4000;
        w += 0x4000;
    } else {
        gBgFx->unk_1C = 0x180;
        x += 0x4000;
        w -= 0x4000;
    }
    gBgFx->unk_28 = x;
    gBgFx->unk_30 = z;
    d = abs(w);
    gBgFx->unk_3C = d;
    gBgFx->x = x + ((gSineTable[0] * d) >> 8);
    gBgFx->z = z + ((-gSineTable[64] * d) >> 8);
    gBgFx->y = y;
    gBgFx->unk_20 = 0x180;
    SetBlendAlpha(16, 0);
    m4aSongNumStart(SONG_EF_MARL_KAMAEF);
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDACD8, sx, sy);
    gBgFx->unk_26 = 0;
    gBgFx->update = func_08018240;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_0801848C(void) {
    s16 t = gBgFx->unk_08 >> 1;
    SetBlendAlpha(16, 16 - t);

    if (t > 15) {
        BgAnimStop();
    }
    gBgFx->unk_08++;
    func_08012908();
}

void func_080184C4(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_24 = f;
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    BgAnimStart(&gUnk_09EDACA8, sx, sy);
    gBgFx->flags |= 0x20;
    gBgFx->update = func_0801848C;
}
void func_0801853C(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDACF0, sx, sy);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_080185D0(void) {
    s32 x;
    s32 y;
    s32 z;
    s16 r;
    u8 ang;
    BtlObj* o;

    switch (gBgFx->unk_26) {
    case 0:
        if (gBgFx->flags & 1) {
            ApproachValueHalfSteps(&gBgFx->unk_1C, -204, gBgFx->unk_0A);
        } else {
            ApproachValueHalfSteps(&gBgFx->unk_1C, 204, gBgFx->unk_0A);
        }
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_08++;
        }
        break;
    case 1:
        SetBlendAlpha(16, 16 - gBgFx->unk_08);

        if (gBgFx->unk_08 > 15) {
            BgAnimStop();
        } else {
            gBgFx->unk_08++;
        }
        break;
    }
    r = (abs(gBgFx->unk_1C) * 5) >> 4;

    if (gBgFx->flags & 1) {
        ang = gBgFx->unk_24 + 192;
    } else {
        ang = gBgFx->unk_24 + 64;
    }
    x = gBgFx->x + gSineTable[ang] * r;
    z = gBgFx->z + -gSineTable[ang + 64] * r;
    y = gBgFx->y;
    func_08011F78(gBgFx->unk_48, x, y, z, 32, 16, 16);
    o = gBtlWork->actor;

    if (o->flags & 0x2000) {
        o->x += (x - o->x) >> 2;
        o->y += (y - o->y) >> 2;
        o->z += (z - o->z) >> 1;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_26 = 0;
    gBgFx->unk_0A = 80;
    gBgFx->unk_48 = v;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAD08, sx, sy);

    if (f) {
        gBgFx->flags |= 1;
        gBgFx->unk_24 = 248;
    } else {
        gBgFx->unk_24 = 8;
    }

    if (gBgFx->flags & 1) {
        if (gBgFx->x < gBtlWork->actor->x) {
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_1C = -(((gBgFx->x - gBtlWork->actor->x) << 8) / 19200);
        }
    } else {
        if (gBgFx->x > gBtlWork->actor->x) {
            gBgFx->unk_26 = 1;
        } else {
            gBgFx->unk_1C = ((gBtlWork->actor->x - gBgFx->x) << 8) / 19200;
        }
    }
    BgAnimSetLoopStartFrame(3);
    gBgFx->update = func_080185D0;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_0801884C(void) {
    s16 t;

    switch (gBgFx->unk_26) {
    case 0:
        gBgFx->unk_1C += 2;
        gBgFx->unk_20 += 2;
        break;
    case 1:
        gBgFx->unk_1C += 5;
        gBgFx->unk_20 += 5;
        break;
    case 2:
        gBgFx->unk_1C += 10;
        gBgFx->unk_20 += 10;
        break;
    }

    if (gBgFx->unk_08 == 10) {
        t = (gBgFx->unk_1C * 3) >> 4;
        if (func_08011F78(gBgFx->unk_48, gBgFx->x, gBgFx->y, gBgFx->z, t, t, 100)) {
            m4aSongNumStart(SONG_EF_DS_ANKOKUPUNCH);
        }
    }
    gBgFx->unk_08++;
    func_08012908();
}

void func_080188E4(u16 a, s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_48 = w;
    gBgFx->unk_26 = a;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAD20, sx, sy);
    gBgFx->update = func_0801884C;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}

void func_08018970(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAD50, sx, sy);
    gBgFx->update = func_08012908;
}
void func_080189DC(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAD68, sx, sy);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08018A70(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = -s;
    gBgFx->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAD68, sx, sy);
    gBgFx->update = func_08012908;
    FadeToAmount(0, gBtlWork->unk_0B3, 8);
    gBgFx->flags |= 8;
}
void func_08018B04(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_1C = s;
    gBgFx->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAD80, sx, sy);
    gBgFx->update = func_08012908;
}
void func_08018B78(void) {
    switch (gBgFx->unk_26) {
    case 0:
        ApproachValue(&gBgFx->unk_3C, 0xA00, gBgFx->unk_0A);
        ApproachValueHalfSteps(&gBgFx->unk_1C, 460, gBgFx->unk_0A);
        ApproachValueHalfSteps(&gBgFx->unk_20, 512, gBgFx->unk_0A);
        SetBlendAlpha(16, gBgFx->unk_3C >> 8);
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 1;
        }
        break;
    case 1:
        gBgFx->unk_26 = 2;
        gBgFx->unk_08 = 0;
        gBgFx->unk_0A = 25;
        break;
    case 2:
        ApproachValue(&gBgFx->unk_3C, 0, gBgFx->unk_0A);
        SetBlendAlpha(16, gBgFx->unk_3C >> 8);
        gBgFx->unk_0A--;

        if (gBgFx->unk_0A <= 0) {
            gBgFx->unk_08 = 0;
            gBgFx->unk_26 = 3;
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
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    gBgFx->unk_26 = 0;
    gBgFx->unk_1C = 10;
    gBgFx->unk_20 = 10;
    gBgFx->unk_3C = 0;
    gBgFx->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDAA38, sx, sy);
    BgAnimSetLoopStartFrame(0);
    gBgFx->update = func_08018B78;
    gBgFx->unk_0A = 43;
}
void func_08018CC4(void) {
    if (gBgFx->unk_08 > 10) {
        switch (gBgFx->unk_26) {
        case 0:
            func_08011F78(11, gBgFx->x - 0x6000, gBgFx->y - 0x1000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x, gBgFx->y + 0x2000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x7000, gBgFx->y - 0x1000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x3000, gBgFx->y + 0x2000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x3000, gBgFx->y + 0x2800, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x6000, gBgFx->y + 0x6000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x800, gBgFx->y + 0x7800, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x3000, gBgFx->y + 0x2800, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x6800, gBgFx->y + 0x6800, gBgFx->z,
                14, 14, 14);
            break;
        case 1:
            func_08011F78(11, gBgFx->x + 0x6000, gBgFx->y - 0x1000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x, gBgFx->y + 0x2000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x7000, gBgFx->y - 0x1000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x3000, gBgFx->y + 0x2000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x3000, gBgFx->y + 0x2800, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x + 0x6000, gBgFx->y + 0x6000, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x800, gBgFx->y + 0x7800, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x3000, gBgFx->y + 0x2800, gBgFx->z,
                14, 14, 14);
            func_08011F78(11, gBgFx->x - 0x6800, gBgFx->y + 0x6800, gBgFx->z,
                14, 14, 14);
            break;
        }
    }
    gBgFx->unk_08++;
    func_08012908();
}
void func_08018F28(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    m4aSongNumStart(SONG_SND_705);
    WorldToScreen(&sx, &sy, gBgFx->x, gBgFx->y, gBgFx->z);
    gBgFx->unk_26 = GetRandom() % 2;
    switch (gBgFx->unk_26) {
    case 0:
        BgAnimStart(&gUnk_09EDAD98, sx, sy);
        break;
    case 1:
        BgAnimStart(&gUnk_09EDAD98, sx, sy);
        gBgFx->flags |= 1;
        gBgFx->unk_1C = -0x100;
        break;
    }
    gBgFx->update = func_08018CC4;
}
void func_08018FE4(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gBgFx->x = x;
    gBgFx->y = y;
    gBgFx->z = z;
    WorldToScreen(&sx, &sy, x, y, z);
    BgAnimStart(&gUnk_09EDADB0, sx, sy);
    gBgFx->update = func_08012908;
}
