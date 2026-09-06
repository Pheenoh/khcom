#include "poo.h"
#include "macros.h"

PooWork* gPooWork;
u32 gUnk_02034DAC;
PooSpawnArgs gUnk_02034DB0;
u32 gUnk_02034DC4;
PooPos gUnk_02034DC8;
s32 gUnk_02034DD8;
s32 gUnk_02034DDC;
u8 gUnk_02034DE0;
u8 gUnk_02034DE1;
s32 gUnk_02034DE4;
PooSoraWork* gPooSoraWork;
u16 gUnk_02034DEC;
s32 gUnk_02034DF0;
s32 gUnk_02034DF4;
ListNode gUnk_02034DF8;
PooPos gUnk_02034E08;
u16 gUnk_02034E18;
u32 gUnk_02034E1C;
PooCamera* gUnk_02034E20;
u16 gUnk_02034E24;
u16 gUnk_02034E26;
u16 gUnk_02034E28;
u32 gUnk_02034E2C;
PooBeeAfterEventWork* gPooBeeAfterEventWork;
u16 gUnk_02034E34;
u16 gUnk_02034E36;
u16 gUnk_02034E38;
u16 gUnk_02034E3A;

void task_poo_pooh_0(PooWork* w) {
    PooShadowArgs args;

    gPooWork = w;
    w->unk_CC = 0;
    func_080D2CD0(&gUnk_0203C3E4, &gUnk_0203C3E0);
    w->unk_D0 = 0;
    w->unk_D4 = 0;
    gUnk_0203C3F0 = 0;
    w->unk_DC = 0;
    w->unk_F8 = 0;
    w->unk_38 = 45;
    w->unk_3A = 45;
    w->unk_3B = w->unk_38;
    func_080C7CC8(w);
    w->unk_3C = 0;
    w->unk_24 = 0;
    w->unk_26 = 0xFFFF;
    func_080D2CA8(&w->unk_28, &gUnk_02034DAC);
    w->unk_28.unk_0C = 0;
    w->unk_40 = w->unk_28.unk_00;
    w->unk_44 = w->unk_28.unk_04;
    gUnk_0203C3EC = &w->unk_28;
    w->tiles = AllocObjTiles((u16)(gUnk_096FC010.unk_04 * 32), 0);
    w->palette = LoadObjPalette(gUnk_096FC010.unk_00, 32);
    AnimInit(w->unk_0C, 0, 0);
    func_080C84E0(w, gUnk_02034DAC);
    w->unk_FA = 0;
    func_080C7FEC(w, gUnk_02034DAC);
    w->gfx = AnimGetGfx(w->unk_0C);
    func_080122AC(w->unk_4C, 9, gUnk_096FC010.unk_08, gUnk_096FC010.unk_06);
    func_08012324(w->unk_4C, w->unk_28.unk_00, w->unk_28.unk_04, w->unk_28.unk_08);
    TaskPoolInit(&w->unk_B0, 10);
    args.unk_00 = &w->unk_28;
    args.unk_04 = (PooShadowInfo*)&w->unk_E0;
    TaskCreate(&w->unk_B0, &gTaskDescPooShadowdodai, &args);
    w->unk_C4 = 0;
    w->unk_C8 = 0;
    w->unk_EC = func_080C8B38((PooAim*)w->unk_4C, &w->unk_28, &w->unk_E8);
}

u8 func_080C871C(PooWork* w) {
    if (gUnk_0203C3F0 == 1) {
        func_080C84E0(w, 16);
        w->unk_28.unk_00 = gUnk_0203C3DC;
        w->unk_28.unk_04 = gUnk_0203C3E8;
    } else if (gUnk_0203C3F0 == 2) {
        w->unk_28.unk_00 = gUnk_0203C3DC;
        w->unk_28.unk_04 = gUnk_0203C3E8;
        func_080C84E0(w, 38);
    } else if (gUnk_0203C3F0 == 7) {
        w->unk_28.unk_00 = gUnk_0203C3DC;
        w->unk_28.unk_04 = gUnk_0203C3E8;
        func_080C84E0(w, 39);
    } else if (gUnk_0203C3F0 == 8) {
        w->unk_38 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, gUnk_0203C3DC, gUnk_0203C3E8);
        w->unk_3A = w->unk_38;
        w->unk_3B = w->unk_38;
        func_080C84E0(w, 20);
    } else if (gUnk_0203C3F0 == 11) {
        w->unk_38 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, gUnk_0203C3DC, gUnk_0203C3E8);
        w->unk_3A = w->unk_38;
        w->unk_3B = w->unk_38;
        w->unk_F6 = 0;
        func_080C84E0(w, 21);
    } else if (gUnk_0203C3F0 == 3) {
        func_080C84E0(w, 32);
    } else if (gUnk_0203C3F0 == 4 || gUnk_0203C3F0 == 6) {
        func_080C84E0(w, 0);
    } else if (gUnk_0203C3F0 == 5) {
        func_080C84E0(w, 10);
    } else if (gUnk_0203C3F0 == 9) {
        func_080C84E0(w, 12);
    } else if (gUnk_0203C3F0 == 10) {
        func_080C84E0(w, 11);
    } else if (gUnk_0203C3F0 == 12) {
        gUnk_0203C3F0 = 0;
        return 0;
    } else {
        func_080C84E0(w, 10);
    }

    gUnk_0203C3F0 = 0;
    return 1;
}

u8 func_080C887C(PooWork* w, PooNode* n) {
    if (func_08012660(w->unk_4C, 1) != 0) {
        if (func_080CFF30() == 0) {
            func_080C84E0(w, 10);
            return 1;
        }
    }

    if (gUnk_0203C3F0 != 0) {
        return func_080C871C(w);
    }
    return 0;
}

void func_080C88C4(PooWork* w, PooNode* n) {
    if (n != 0) {
        if (func_080CBA4C() != 0) {
            if (w->unk_DC != 0 || w->unk_D0 == gUnk_0203C410) {
                w->unk_F8++;

                if (w->unk_F8 > 10) {
                    w->unk_DC = 0;
                    w->unk_F8 = 0;
                    func_080C84E0(w, 29);
                }
                return;
            }
            w->unk_DC = 90;
        }

        if (w->unk_DC != 0) {
            w->unk_DC--;
            n = gUnk_0203C410;
        }

        if (w->unk_D0 != n && w->unk_D4 <= 59) {
            w->unk_3A = w->unk_38;
            w->unk_3B = w->unk_38;
            w->unk_39 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, ((PooPos*)n->unk_08)->unk_00, ((PooPos*)n->unk_08)->unk_04);
            w->unk_40 = w->unk_28.unk_00;
            w->unk_44 = w->unk_28.unk_04;
            func_080C84E0(w, 9);
        } else {
            w->unk_D0 = n;
            w->unk_D4 = 0;
            w->unk_40 = ((PooPos*)w->unk_D0->unk_08)->unk_00;
            w->unk_44 = ((PooPos*)w->unk_D0->unk_08)->unk_04;
            func_080C84E0(w, 3);
        }
    } else {
        w->unk_40 = w->unk_28.unk_00;
        w->unk_44 = w->unk_28.unk_04;
        func_080C84E0(w, 23);
    }
}

void func_080C89B4(PooWork* w, PooSpot* b, u16 c) {
    u16 f;
    s32 v;
    s32 i;

    f = AnimGetFrame(w->unk_0C) + 1;

    if (w->unk_78 == 0) {
        i = w->unk_A8 * c + f;
        v = b[i].unk_00;

        if (w->unk_24 != 0) {
            v = -v;
        }
        w->unk_28.unk_00 += v;
        v = b[i].unk_04;
        w->unk_28.unk_04 += v;
    }
    w->unk_28.unk_08 += b[w->unk_A8 * c + f].unk_08;
}

void func_080C8A28(PooWork* w) {
    func_080C89B4(w, gUnk_096FC05C, 11);
}

void func_080C8A3C(PooWork* w) {
    func_080C89B4(w, gUnk_096FC2F0, 0x10);
}

s32 func_080C8A50(PooWork* w) {
    PooPoint t[4];
    u32 i;

    memcpy(t, gUnk_096FC6B0, sizeof(t));

    for (i = 0; i < 4; i++) {
        if (w->unk_90 == t[i].unk_00 && w->unk_94 == t[i].unk_04) {
            break;
        }
    }
    return i;
}

void func_080C8AB8(PooWork* w) {
    w->unk_F4 = 0;
    w->unk_F0 = func_080C8A50(w);
}

u32 func_080C8AD4(u32 a) {
    a++;
    if (a > 3) {
        a = 0;
    }
    return a;
}

void func_080C8AE0(PooWork* w) {
    s32 t;

    t = func_080C8A50(w);
    if (t == func_080C8AD4(w->unk_F0)) {
        w->unk_F0 = t;
        w->unk_F4++;
        if (w->unk_F4 > 3) {
            if (func_080D2D50(1) == 0) {
#ifdef VERSION_EU
                func_080C7B84(0x8B);
#else
                func_080C7B84(0x8D);
#endif
                func_080D2D3C(1);
                func_0800FDD0(0x52);
            }
        }
    } else {
        func_080C8AB8(w);
    }
}

s32 func_080C8B38(PooAim* w, PooPos* p, u8* c) {
    s32 v;

    if ((w->unk_2E & 1) != 0) {
        if (p->unk_0C < w->unk_40) {
            v = p->unk_0C;
        } else {
            v = w->unk_40;
        }
        *c = 1;
    } else {
        *c = 0;
        v = p->unk_0C;
    }
    return v;
}

void func_080C8B60(PooMover* w, s32 b, u8 c) {
    s32 a;

    w->unk_3C += 6;
    if (w->unk_3C > b) {
        w->unk_3C = b;
    }

    if (c != 0) {
        a = GetAngle(w->unk_28, w->unk_2C, w->unk_40, w->unk_44);
        w->unk_38 = a;
        w->unk_3A = a;
        w->unk_3B = w->unk_38;
    }
    w->unk_28 += gSineTable[w->unk_38] * w->unk_3C >> 8;
    w->unk_2C += -gSineTable[w->unk_38 + 0x40] * w->unk_3C >> 8;
}

u8 func_080C8BD4(void) {
    s16 x;
    s16 y;

    x = (gUnk_0203C3EC->unk_00 >> 8) - gUnk_0203C40C;
    y = (gUnk_0203C3EC->unk_04 >> 8) + (gUnk_0203C3EC->unk_08 >> 8) - gUnk_0203C3F8;
    if (x < gUnk_096FC010.unk_08 * 2 || 240 - gUnk_096FC010.unk_08 * 2 < x || y < gUnk_096FC010.unk_06 * 2 || y > 152) {
        return 1;
    }
    return 0;
}

void func_080C8C40(PooWork* w, PooNode* n) {
    u16 a0;
    u16 a1;
    u16 a2;
    u16 v;
    u16 c;
    s32 b;

    switch (gUnk_02034DAC) {
    case 3:
        if (AnimGetGfxIndex((AnimState*)w->unk_0C) == 8 && gUnk_0203C3EC->unk_04 > 0x1BD00 && (GetKeysPressed() & 1) != 0) {
            v = 128;

            if (func_080D1738() != 0) {
                v = 2;
            }

            if (GetRandom() % v == 0) {
                func_080C84E0(w, 17);
            }
            break;
        }
        b = 0x4C;

        if (func_080CBA74() != 0 && w->unk_D0 == n && n == gUnk_0203C410) {
            b = 152;
            w->unk_3C = 152;
        } else if (w->unk_3C > 82) {
            b = w->unk_3C - 6;
        }
        func_080C8B60((PooMover*)w, b, 1);

        if (func_080C887C(w, n) != 0) {
            w->unk_3C = 0;
        } else {
            func_080C88C4(w, n);
        }
        break;
    case 10:
        if (w->unk_78 != 0) {
            if (func_08012660(w->unk_4C, 1) != 0) {
                break;
            }

            if (func_080CBA4C() == 0) {
                break;
            }
            w->unk_28.unk_00 += w->unk_84;
            w->unk_28.unk_04 += w->unk_88;
            w->unk_D0 = 0;
            func_080C88C4(w, n);
            break;
        }

        if (func_080C8404(&w->unk_28, &gUnk_0203C420) > 0x1B00) {
            func_080C84E0(w, 0);
        }
        break;
    case 12:
        a0 = w->unk_3A;
        w->unk_39 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, 0x8DE00, 0x45C00);
        ApproachAngle(&a0, w->unk_39, 4);
        w->unk_3A = a0;
        w->unk_D4++;

        if (func_080D0E3C() == 0) {
            break;
        }
        func_080C84E0(w, 15);
        w->unk_38 = 64;
        w->unk_3A = 64;
        w->unk_3B = w->unk_38;
        break;
    case 15:
        w->unk_28.unk_08 += w->unk_48;
        w->unk_48 += 71;

        if (w->unk_28.unk_08 < 0) {
            break;
        }
        w->unk_28.unk_08 = 0;
        func_080C84E0(w, 5);
        w->unk_3C = 228;
        break;
    case 5:
        w->unk_40 = 0x87F00;
        w->unk_44 = 0x4B700;
        func_080C8B60((PooMover*)w, 456, 1);

        if (func_080C83C4(w->unk_40 >> 8, w->unk_44 >> 8, w->unk_28.unk_00 >> 8, w->unk_28.unk_04 >> 8) == 0) {
            break;
        }
        func_080C84E0(w, 6);
        break;
    case 6:
        w->unk_40 = 0x75D00;
        w->unk_44 = 0x49E00;
        func_080C8B60((PooMover*)w, 456, 1);

        if (func_080C83C4(w->unk_40 >> 8, w->unk_44 >> 8, w->unk_28.unk_00 >> 8, w->unk_28.unk_04 >> 8) == 0) {
            break;
        }
        func_080C84E0(w, 14);
        func_0802F1E8();
        m4aSongNumStart(372);
        break;
    case 0:
        if (w->unk_28.unk_08 < 0) {
            func_080C84E0(w, 1);
            break;
        }
        func_080C88C4(w, n);

        if (gUnk_02034DAC != 0) {
            break;
        }

        if (w->unk_D0 == 0) {
            break;
        }
        c = func_080CCB80(&w->unk_D0->unk_00);

        if (c <= 1) {
            break;
        }
        c >>= 1;
        func_080CCB84(&w->unk_D0->unk_00, c);
        break;
    case 29:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 30);
        break;
    case 30:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (w->unk_DA <= 1) {
            w->unk_DA++;
            AnimReset((AnimState*)w->unk_0C);
            break;
        }

        if (func_08005AC4((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (AnimGetFrame((AnimState*)w->unk_0C) != 0) {
            break;
        }
        func_080C84E0(w, 31);
        break;
    case 31:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 9);
        break;
    case 9:
        if (w->unk_D4 <= 59) {
            a1 = w->unk_3A;
            w->unk_39 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, ((s32*)n->unk_08)[0], ((s32*)n->unk_08)[1]);
            ApproachAngle(&a1, w->unk_39, 4);
            w->unk_3A = a1;
            w->unk_D4++;
        } else {
            func_080C88C4(w, n);
        }
        break;
    case 16:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (w->unk_28.unk_00 == 0x4A700 && w->unk_28.unk_04 == 0x28E00 && func_080D2D50(5) == 0) {
            func_080C84E0(w, 37);
            TaskCreate(&w->unk_B0, &gTaskDescPooRoo, &w->unk_28);
            break;
        }
        func_080C84E0(w, 36);
        break;
    case 37:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 38);
        w->unk_28.unk_08 -= 0x1700;
        func_080CA0B4();
        break;
    case 36:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 38);
        break;
    case 38:
        if (w->unk_AC <= 59) {
            w->unk_28.unk_08 -= 204;
        } else if (w->unk_AC <= 79) {
            w->unk_28.unk_08 -= 204;
        } else {
            w->unk_28.unk_08 += 204;
        }

        if (w->unk_AC > 60) {
            w->unk_28.unk_00 += 128;
            w->unk_28.unk_04 += 64;
        }
        w->unk_AC++;

        if (w->unk_AC > 80 && w->unk_28.unk_08 >= -0x800 && IsTaskActive(w->unk_C4) != 0) {
            func_08000DE8(&w->unk_B0, w->unk_C4);
            TaskCreate(&w->unk_B0, &gTaskDescPooFreeballoon, &w->unk_28);
            gUnk_0203C3F0 = 0;
        }

        if (w->unk_28.unk_08 < 0) {
            break;
        }
        w->unk_28.unk_08 = 0;

        if (func_08012660(w->unk_4C, 1) != 0) {
            func_080C84E0(w, 0);
            break;
        }

        if (gUnk_0203C3F0 == 0) {
            func_080C84E0(w, 0);
            break;
        }
        func_080C871C(w);
        break;
    case 39:
        w->unk_28.unk_08 -= 204;

        if (w->unk_28.unk_08 > -0xD500) {
            break;
        }

        if (IsTaskActive(w->unk_C4) != 0) {
            func_08000DE8(&w->unk_B0, w->unk_C4);
        }
        func_080C84E0(w, 22);
        break;
    case 22:
        if (w->unk_28.unk_08 < -0x1000) {
            w->unk_28.unk_08 += 204;
            break;
        }

        if (func_080D2D50(3) == 0) {
#ifdef VERSION_EU
            func_080C7B84(135);
#else
            func_080C7B84(137);
#endif
            func_080D2D3C(3);
            func_0800FDD0(79);
        } else {
#ifdef VERSION_EU
            func_080C7B84(136);
#else
            func_080C7B84(138);
#endif
        }
        break;
    case 17:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            if (w->unk_DA > 40) {
                func_080C84E0(w, 18);
                func_080C8A3C(w);
                w->unk_28.unk_08 = 0;
            }
            w->unk_DA++;
            break;
        }

        if (func_08005AC4((AnimState*)w->unk_0C) != 0) {
            func_080C8A28(w);
        }
        w->unk_DA = 0;
        break;
    case 18:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 0);
            break;
        }

        if (func_08005AC4((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C8A3C(w);
        break;
    case 21:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (w->unk_A8 == 0) {
            if (w->unk_24 != 0) {
                w->unk_38 = 19;
            } else {
                w->unk_38 = 224;
            }
        } else {
            if (w->unk_24 != 0) {
                w->unk_38 = 83;
            } else {
                w->unk_38 = 147;
            }
        }
        w->unk_3A = w->unk_38;
        w->unk_3B = w->unk_38;
        w->unk_FB = w->unk_38;
        func_080C84E0(w, 2);
        w->unk_48 = 0;
        w->unk_28.unk_08 = -0xD00;

        if (w->unk_24 == 0) {
            w->unk_28.unk_00 -= 0x900;
        } else {
            w->unk_28.unk_00 += 0x900;
        }

        if (w->unk_F6 == 0) {
            func_080D0084((u32*)&w->unk_28.unk_00, (u32*)&w->unk_28.unk_04, 1);
            break;
        }

        while ((u8)func_080CFEA0(&w->unk_28) != 0) {
            w->unk_28.unk_00 += gSineTable[w->unk_38] * 2;
            w->unk_28.unk_04 -= gSineTable[w->unk_38 + 0x40] * 2;
        }
        break;
    case 2:
        w->unk_28.unk_08 += w->unk_48;
        w->unk_48 += 17;

        if (w->unk_28.unk_08 < 0) {
            break;
        }
        w->unk_28.unk_08 = 0;

        if (w->unk_F6 == 0) {
            func_080C84E0(w, 13);
            break;
        }
        func_080C84E0(w, 0);
        gUnk_0203C3F0 = 0;
        break;
    case 13:
        if (func_080CBA4C() == 0) {
            break;
        }

        if ((u8)func_080CFE34(&gUnk_0203C420.unk_00) != 0) {
            break;
        }
        w->unk_38 = w->unk_FB + 128;
        w->unk_3A = w->unk_38;
        w->unk_3B = w->unk_38;
        func_080C84E0(w, 21);
        w->unk_F6 = 1;
        break;
    case 20:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 8);
        func_080C8AB8(w);
        w->unk_28.unk_08 -= 0xE00;
        w->unk_3A = w->unk_38;
        w->unk_3B = w->unk_38;

        if (w->unk_24 == 0) {
            w->unk_28.unk_00 -= 0x900;
        } else {
            w->unk_28.unk_00 += 0x900;
        }
        break;
    case 8:
        w->unk_E8 = 1;

        if (func_080CBA4C() == 0) {
            break;
        }

        if (func_080C8BD4() != 0) {
            break;
        }
        func_080C84E0(w, 7);
        break;
    case 11:
        if (w->unk_DA <= 179) {
            a2 = w->unk_3A;
            w->unk_39 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, 0x8DE00, 0x45C00);
            ApproachAngle(&a2, w->unk_39, 4);
            w->unk_3A = a2;
            w->unk_DA++;
        } else {
            w->unk_38 += 128;
            w->unk_3A = w->unk_38;
            w->unk_3B = w->unk_38;
            func_080C84E0(w, 4);
        }
        break;
    case 4:
        if (w->unk_DA > 119) {
            func_080C84E0(w, 0);
            break;
        }
        w->unk_DA++;
        func_080C8B60((PooMover*)w, 76, 0);
        break;
    case 7:
        if (w->unk_E8 != 0) {
            w->unk_40 = gUnk_0203C420.unk_00.unk_00;
            w->unk_44 = gUnk_0203C420.unk_00.unk_04;
            func_080C8B60((PooMover*)w, 76, 1);
            break;
        }
        w->unk_40 = gUnk_0203C420.unk_00.unk_00;
        w->unk_44 = gUnk_0203C420.unk_00.unk_04;
        w->unk_38 = GetAngle(w->unk_28.unk_00, w->unk_28.unk_04, w->unk_40, w->unk_44);
        w->unk_48 = -0x130;
        w->unk_3C = 237;
        func_080C84E0(w, 19);
        break;
    case 19:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0 && w->unk_E8 != 0 && w->unk_28.unk_08 < -0x100) {
            func_080C84E0(w, 8);
            func_080C8AE0(w);
            break;
        }

        if (AnimGetFrame((AnimState*)w->unk_0C) == 2 && w->unk_16 == 0) {
            m4aSongNumStart(960);
        }

        if ((AnimGetFrame((AnimState*)w->unk_0C) > 1 && AnimGetFrame((AnimState*)w->unk_0C) <= 4) ||
            (AnimGetFrame((AnimState*)w->unk_0C) > 4 && w->unk_E8 == 0 && w->unk_28.unk_08 < w->unk_EC)) {
            w->unk_28.unk_00 += gSineTable[w->unk_38] * w->unk_3C >> 8;
            w->unk_28.unk_04 += -gSineTable[w->unk_38 + 0x40] * w->unk_3C >> 8;
        }

        if (AnimGetFrame((AnimState*)w->unk_0C) <= 1) {
            break;
        }
    case 1:
        w->unk_28.unk_08 += w->unk_48;
        w->unk_48 += 17;

        if (w->unk_28.unk_08 >= w->unk_EC) {
            w->unk_28.unk_08 = w->unk_EC;
        }

        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 0);
        }
        break;
    case 23:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 24);
        break;
    case 24:
        if (w->unk_DA <= 119) {
            w->unk_DA++;

            if (func_080CBA4C() == 0) {
                break;
            }

            if (func_080C8BD4() != 0) {
                break;
            }

            if (gUnk_0203C3E4 != 0) {
                func_080C84E0(w, 28);
            }
        } else {
            func_080C84E0(w, 25);
        }
        break;
    case 25:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 26);
        w->unk_D8 = gUnk_0203C3E0 * 1800 / 1851;
        break;
    case 26:
        if (func_080CBA4C() != 0 && func_080C8BD4() == 0 && gUnk_0203C3E4 != 0) {
            func_080C84E0(w, 27);

            if (IsTaskActive((Task*)w->unk_C8) == 0) {
                break;
            }
            func_08000DE8(&w->unk_B0, (Task*)w->unk_C8);
            break;
        }

        if (IsTaskActive((Task*)w->unk_C8) == 0) {
            w->unk_C8 = (s32)TaskCreate(&w->unk_B0, &gTaskDescPooZzz, &w->unk_24);
        }

        if (gUnk_0203C3E4 == 0) {
            w->unk_D8++;

            if (w->unk_D8 > 1800) {
                gUnk_0203C3E4++;
                gUnk_0203C3E0 = 1851;
                w->unk_D8 = 0;
            }

            if (gUnk_0203C3E4 > 3) {
                gUnk_0203C3E4 = 3;
            }
        }
        break;
    case 27:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 28);
        }
        break;
    case 28:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 0);
        }
        break;
    case 32:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (gUnk_0203C3E4 == 1) {
            func_080C84E0(w, 33);
        } else if (gUnk_0203C3E4 == 2) {
            func_080C84E0(w, 34);
        } else {
            func_080C84E0(w, 35);
        }
        break;
    case 33:
    case 34:
    case 35:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 28);
        w->unk_28.unk_00 -= 0x400;
        w->unk_28.unk_04 += 0x300;
        break;
    }
}

void func_080C98B8(PooWork* w) {
    if (gUnk_02034DAC == 3) {
        if (gUnk_0203C3E4 != 0) {
            gUnk_0203C3E0--;
        }

        if (gUnk_0203C3E0 == 0) {
            if (gUnk_0203C3E4 == 0) {
                func_080C84E0(w, 0x17);
            } else {
                gUnk_0203C3E4--;
                if (gUnk_0203C3E4 == 0) {
                    func_080C84E0(w, 0x17);
                } else {
                    gUnk_0203C3E0 = 0x73B;
                }
            }
        }
    }
}

u8 func_080C9910(void) {
    s32 x;
    s32 y;

    x = (gUnk_0203C3EC->unk_00 >> 8) - gUnk_0203C40C;
    y = (gUnk_0203C3EC->unk_04 >> 8) + (gUnk_0203C3EC->unk_08 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, gUnk_096FC010.unk_06, 0, gUnk_096FC010.unk_08, gUnk_096FC010.unk_08) != 0) {
        return 1;
    }
    return 0;
}

u8 task_poo_pooh_1(PooWork* w) {
    PooNode* n;

    w->unk_EC = func_080C8B38((PooAim*)w->unk_4C, &w->unk_28, &w->unk_E8);

    if (func_080C8BD4() != 0) {
        n = 0;
    } else {
        n = func_080CCC98();
    }
    w->unk_FA = 0;
    func_080C8C40(w, n);
    func_080C98B8(w);
    func_080C7FEC(w, gUnk_02034DAC);
    w->gfx = AnimUpdate(w->unk_0C);

    if (gUnk_02034DAC == 3 || gUnk_02034DAC == 7) {
        if (w->unk_16 == 0) {
            switch (AnimGetFrame(w->unk_0C)) {
            case 9:
                m4aSongNumStart(0x39E);
                break;
            case 3:
                m4aSongNumStart(0x39F);
                break;
            }
        }
    }
    func_08012324(w->unk_4C, w->unk_28.unk_00, w->unk_28.unk_04, w->unk_28.unk_08);
    TaskPoolUpdate(&w->unk_B0);
    return 1;
}

void task_poo_pooh_2(PooWork* w) {
    s16 x;
    s16 y;
    s32 f;
    u16 p;

    x = (w->unk_28.unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_28.unk_04 >> 8) + (w->unk_28.unk_08 >> 8) - gUnk_0203C3F8;
    if (w->unk_24 != 0) {
        f = 0x801;
    } else {
        f = 0x800;
    }

    if (gUnk_02034DAC == 20 && w->unk_A8 == 1) {
        if (AnimGetFrame(w->unk_0C) <= 4) {
            p = -0x1003 - ((gUnk_0203C3E8 - 0x500) >> 8) * 4;
            w->unk_E4 = 0;
        } else {
            p = -0x1005 - ((gUnk_0203C3E8 - 0x500) >> 8) * 4;
            w->unk_E0 = 0;
        }
    } else if (func_080C9DAC() != 0) {
        p = func_080D06C8() - 4;
        w->unk_E0 = p + 1;
        w->unk_E4 = 0;
    } else if ((u8)func_080D0210(gUnk_0203C3EC->unk_00, gUnk_0203C3EC->unk_04) != 0) {
        if (gUnk_02034DAC == 21 && w->unk_A8 == 1 && w->unk_F6 != 0) {
            p = func_080D06BC() - 3;
        } else if ((u8)func_080D0210(gUnk_0203C3EC->unk_00, gUnk_0203C3EC->unk_04) == 83 || (u8)func_080D0210(gUnk_0203C3EC->unk_00, gUnk_0203C3EC->unk_04) == 173) {
            if (gUnk_0203C3EC->unk_04 < gUnk_0203C420.unk_00.unk_04) {
                p = func_080D06C8() + 5;
            } else {
                p = func_080D06C8() + 1;
            }
        } else {
            if (gUnk_0203C3EC->unk_04 < gUnk_0203C420.unk_00.unk_04) {
                p = func_080D06BC() - 2;
            } else {
                p = func_080D06BC() - 6;
            }
        }
        w->unk_E0 = p + 1;
        w->unk_E4 = 0;
    } else if (w->unk_E8 != 0) {
        p = -0x1008 - (w->unk_94 >> 8) * 4;

        if (w->unk_28.unk_04 >= gUnk_0203C420.unk_00.unk_04) {
            p -= 2;
        } else {
            p += 2;
        }

        if (w->unk_98 <= *(s32*)&w->unk_4C[0x10] || ((s32*)w->unk_9C)[4] == 0x400) {
            if (w->unk_8C != 0) {
                w->unk_E0 = 0;
            } else {
                w->unk_E0 = p + 1;
            }
            w->unk_E4 = 0;
        } else {
            w->unk_E4 = w->unk_8C;
            w->unk_E0 = p + 1;
        }
    } else {
        p = -0x1004 - (w->unk_28.unk_04 >> 8) * 4;
        w->unk_E4 = 0;

        if (w->unk_E4 != w->unk_28.unk_0C) {
            w->unk_E0 = 0;
        } else {
            w->unk_E0 = 0xFFF0;
        }
    }

    if (w->unk_FA != 0) {
        w->unk_E0 = 0;
    }
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, f, p);
    TaskPoolDraw(&w->unk_B0);
}

void task_poo_pooh_3(PooWork* w) {
    if (gUnk_02034DAC == 22) {
        gUnk_02034DAC = 0;
        w->unk_28.unk_08 = 0;
        w->unk_28.unk_04 += 0x2000;
    } else if (gUnk_02034DAC == 14) {
        gUnk_02034DAC = 0;
        w->unk_28.unk_00 = 0x7F700;
        w->unk_28.unk_04 = 0x47E00;
        w->unk_28.unk_08 = 0;
    }
    func_080D2C8C(&w->unk_28, gUnk_02034DAC);
    func_080D2CC4(gUnk_0203C3E4, gUnk_0203C3E0);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    func_08012304(w->unk_4C);
    TaskPoolDestroy(&w->unk_B0);
}

u8 func_080C9D48(void) {
    if (gUnk_02034DAC == 22) {
        return 1;
    }
    return 0;
}

u8 func_080C9D5C(void) {
    if (gUnk_02034DAC == 39) {
        return 1;
    }
    return 0;
}

u8 func_080C9D70(void) {
    if (gUnk_02034DAC == 3) {
        return 1;
    }
    return 0;
}

u8 func_080C9D84(void) {
    if (gUnk_02034DAC == 14) {
        return 1;
    }
    return 0;
}

u8 func_080C9D98(void) {
    if (gUnk_02034DAC == 13) {
        return 1;
    }
    return 0;
}

u8 func_080C9DAC(void) {
    PooWork* w;

    if (gUnk_02034DAC == 13) {
        return 1;
    }

    if (gUnk_02034DAC == 2) {
        if (gPooWork->unk_F6 != 0) {
            return 0;
        }
        return 1;
    }

    if (gUnk_02034DAC != 21) {
        return 0;
    }

    w = gPooWork;
    if (w->unk_F6 != 0) {
        if (w->unk_A8 != 1) {
            return 1;
        }

        if (AnimGetFrame(w->unk_0C) > 4) {
            return 0;
        }
        return 1;
    }

    if (w->unk_A8 == 0) {
        return 0;
    }

    if (AnimGetFrame(w->unk_0C) <= 4) {
        return 0;
    }
    return 1;
}

u8 func_080C9E28(void) {
    if (func_080CA67C(gUnk_0203C3EC) == 2) {
        return 1;
    }
    return 0;
}

u16 func_080C9E4C(void) {
    if (gUnk_02034DAC == 0x21) {
        return 0;
    }

    if (gUnk_02034DAC == 0x22) {
        return 1;
    }

    if (gUnk_02034DAC == 0x23) {
        return 2;
    }
    return 3;
}

u8 func_080C9E70(void) {
    if (gUnk_02034DAC == 12) {
        return 1;
    }
    return 0;
}

void func_080C9E84(void* pool) {
    u32 i;

    for (i = 0; i < 12; i++) {
        func_080CD550(pool, gUnk_096FCAF4[i].unk_08, gUnk_096FCAF4[i].unk_00, gUnk_096FCAF4[i].unk_04);
    }
}

u16 func_080C9EAC(void* pool, u16 b) {
    u32 i;

    for (i = 0; i < 80; i++) {
        func_080D1990(pool, gUnk_096FCB84[i].unk_08, gUnk_096FCB84[i].unk_00, gUnk_096FCB84[i].unk_04, b);
        b++;
    }
    return b;
}

u16 func_080C9EFC(void* pool, u16 b) {
    u32 i;

    for (i = 0; i < 85; i++) {
        gUnk_02034DC8.unk_00 = gUnk_096FC6F8[i].unk_00;
        gUnk_02034DC8.unk_04 = gUnk_096FC6F8[i].unk_04;
        gUnk_02034DC8.unk_08 = 0;

        if (gUnk_096FC6F8[i].unk_08 == &gTaskDescPooTanpopo || gUnk_096FC6F8[i].unk_08 == &gTaskDescPooLeaf) {
            gUnk_02034DB0.unk_00 = gUnk_02034DC8;
            gUnk_02034DB0.unk_10 = b;
            TaskCreate(pool, gUnk_096FC6F8[i].unk_08, &gUnk_02034DB0);
            b++;
        } else {
            TaskCreate(pool, gUnk_096FC6F8[i].unk_08, &gUnk_02034DC8);
        }
    }
    return b;
}

void func_080C9FA8(s32 a, s32 b) {
    gUnk_0203C404 = a;
    gUnk_0203C400 = b;
}

void func_080C9FBC(void) {
    s32 y;

    if (gUnk_02034DE0 != 0) {
        return;
    }

    if (gUnk_02034DE1 != 0) {
        func_080C9FA8(gUnk_0203C3EC->unk_00, gUnk_0203C3EC->unk_04 + gUnk_0203C3EC->unk_08);
    }
    y = gUnk_0203C3EC->unk_04 + gUnk_0203C3EC->unk_08;

    if ((gUnk_0203C404 - gUnk_0203C3EC->unk_00 >= 0 ? gUnk_0203C404 - gUnk_0203C3EC->unk_00 < 0xF000
                                                    : gUnk_0203C3EC->unk_00 - gUnk_0203C404 < 0xF000) &&
        (gUnk_0203C400 - y >= 0 ? gUnk_0203C400 - y < 0xA000 : y - gUnk_0203C400 < 0xA000)) {
        gUnk_0203C3FC = (gUnk_0203C404 + gUnk_0203C3EC->unk_00) / 2;
        gUnk_0203C408 = (gUnk_0203C400 + y) / 2;
    } else {
        gUnk_0203C3FC = gUnk_0203C404;
        gUnk_0203C408 = gUnk_0203C400;
    }
}

void func_080CA09C(void) {
    gUnk_02034DE0 = 1;
}

void func_080CA0A8(void) {
    gUnk_02034DE0 = 0;
}

void func_080CA0B4(void) {
    gUnk_02034DE1 = 1;
}

void func_080CA0C0(void) {
    gUnk_02034DE1 = 0;
}

void task_poo_map_0(PooMapWork* w) {
    PooPos p;
    s32 n;

    func_080CA0A8();
    func_080CA0C0();
    func_080D2CA8(&p, &n);
    gUnk_0203C3EC = &p;
    func_080C9FBC();
    gUnk_02034DE4 = gUnk_0203C408;
    gUnk_0203C40C = (gUnk_0203C3FC >> 8) - 120;
    gUnk_0203C3F8 = (gUnk_0203C408 >> 8) - 80;
    gUnk_02039BA0->unk_00 = gUnk_0203C40C << 8;
    gUnk_02039BA0->unk_04 = gUnk_0203C3F8 << 8;
    w->unk_00 = gUnk_096FC6E0.unk_16;
    w->unk_01 = gUnk_096FC6E0.unk_17;
    TaskPoolInit(&w->unk_04, 178);
    func_080C9EAC(&w->unk_04, func_080C9EFC(&w->unk_04, 0));
    func_080C9E84(&w->unk_04);
    TaskCreate(&w->unk_04, &gTaskDescPooMapanime, 0);
    LoadBgTiles(3, gUnk_096FC6E0.unk_00, gUnk_096FC6E0.unk_04);
    LoadBgTiles(2, gUnk_096FC6E0.unk_10, gUnk_096FC6E0.unk_14);
    LoadBgPalette(3, gUnk_096FC6E0.unk_08, gUnk_096FC6E0.unk_0C);
    func_0800516C(3, gUnk_09EF4208, w->unk_00, w->unk_01);
    func_080051C4(3, gUnk_0203C40C, gUnk_0203C3F8);
    func_080CA35C();
    func_0800516C(1, gUnk_09EF4448, w->unk_00, w->unk_01);
    func_080051C4(1, gUnk_0203C40C, gUnk_0203C3F8);
    func_0800516C(2, gUnk_09EF4688, w->unk_00, w->unk_01);
    func_080051C4(2, gUnk_0203C40C, gUnk_0203C3F8);
    func_0802F1C8();
}

u8 task_poo_map_1(PooMapWork* w) {
    func_080C9FBC();
    func_080CA270(w);
    func_08005244(3, gUnk_0203C40C, gUnk_0203C3F8);
    func_08005244(1, gUnk_0203C40C, gUnk_0203C3F8);
    func_08005244(2, gUnk_0203C40C, gUnk_0203C3F8);
    TaskPoolUpdate(&w->unk_04);
    return 1;
}

void task_poo_map_2(PooMapWork* w) {
    TaskPoolDraw(&w->unk_04);
}

void task_poo_map_3(PooMapWork* w) {
    TaskPoolDestroy(&w->unk_04);
}

void func_080CA270(PooMapWork* w) {
    s32 tx;
    s32 ty;

    func_0802F208();
    tx = gUnk_0203C3FC - 0x7800;
    ty = gUnk_0203C408 - 0x5000;

    if (ty < 0) {
        ty = 0;
    }

    if (gUnk_0203C3FC + 0x7800 > 0xEDF00) {
        tx = 0xDEF00;
    }

    if (ty + 0xA000 > 0x83000) {
        ty = 0x79000;
    }
    tx = (tx - (gUnk_0203C40C << 8)) >> 3;
    ty = (ty - (gUnk_0203C3F8 << 8)) >> 3;

    if (tx > 0x300) {
        tx = 0x300;
    } else if (tx < -0x300) {
        tx = -0x300;
    }

    if (ty > 0x300) {
        ty = 0x300;
    } else if (ty < -0x300) {
        ty = -0x300;
    }

    if (abs(tx) <= 50) {
        tx = 0;
    }

    if (abs(ty) <= 50) {
        ty = 0;
    }
    gUnk_0203C40C += tx >> 8;
    gUnk_0203C3F8 += ty >> 8;
    gUnk_0203C3F8 += func_0802F268() >> 8;
    gUnk_02039BA0->unk_00 = gUnk_0203C40C << 8;
    gUnk_02039BA0->unk_04 = gUnk_0203C3F8 << 8;
}

void func_080CA35C(void) {
    gUnk_0203C3F4 = 0;
}

void func_080CA368(void) {
}

u16 func_080CA36C(u16 x, u16 y) {
    u16** t;
    u32 bx;
    u32 by;
    u32 tx;
    u32 ty;

    t = gUnk_09EF4208;
    bx = x >> 8;
    by = y >> 8;
    tx = (x >> 3) & 0x1F;
    ty = (y >> 3) & 0x1F;
    return t[by * 16 + bx][ty * 32 + tx];
}

u8 func_080CA3A0(PooPos* p) {
    u32 v;

    v = func_080CA36C(p->unk_00 >> 8, p->unk_04 >> 8) & 0x3FF;
    if ((u16)(v - 1) <= 8) {
        return 0;
    }

    if ((u16)(v - 0x20) <= 9) {
        return 0;
    }

    if ((u16)(v - 0x40) <= 9) {
        return 0;
    }

    if ((u16)(v - 0x1E0) > 0x5F) {
        return 1;
    }
    return 0;
}

u8 func_080CA3FC(PooActor* p, s32 x, s32 y, s32* ox, s32* oy) {
    PooPos t;
    s32 s;
    s32 c;
    s32 m;
    s32 v;
    u8 a;

    if (func_080CA3A0(&p->unk_00) != 0) {
        a = p->unk_14 + 0x40;
        s = gSineTable[a];
        c = -gSineTable[a + 0x40];
        t.unk_00 = s * 4 + x;
        t.unk_04 = c * 4 + y;
        t.unk_08 = p->unk_00.unk_08;
        t.unk_0C = p->unk_00.unk_0C;
        m = p->unk_10;

        if (m > 0x200) {
            m = 0x200;
        }

        if (func_080CA3A0(&t) == 0) {
            *ox = s * m >> 8;
            *oy = c * m >> 8;
            return 1;
        } else {
            a = p->unk_14 - 0x40;
            s = gSineTable[a];
            c = -gSineTable[a + 0x40];
            t.unk_00 = s * 4 + x;
            t.unk_04 = c * 4 + y;

            if (func_080CA3A0(&t) == 0) {
                *ox = s * m >> 8;
                *oy = c * m >> 8;
                return 1;
            } else {
                v = 0;
                *ox = v;
                *oy = v;
                return 1;
            }
        }
    }
    return 0;
}

u8 func_080CA4E8(s16 x, s16 y, s16 h, s16 vy, s16 w, s16 vx, s32* ox, s32* oy) {
    s32 t;
    s32 r;

    r = 0;
    *oy = 0;
    *ox = 0;
    t = x + vx;
    if (t >= 0) {
        t = x - w;
        if (t > 0xF0) {
            t -= 0xF0;
            *ox = t << 8;
            r = 1;
        }
    } else {
        *ox = t << 8;
        r = 1;
    }
    t = y + vy;
    if (t >= 0) {
        t = y - h;
        if (t > 0xA0) {
            t -= 0xA0;
            *oy = t << 8;
            r = 1;
        }
    } else {
        *oy = t << 8;
        r = 1;
    }
    return r;
}

u8 func_080CA560(PooPos* p, s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080CA3FC((PooActor*)p, x, y, &gUnk_02034DD8, &gUnk_02034DDC) != 0) {
        p->unk_00 = x + gUnk_02034DD8;
        p->unk_04 = y + gUnk_02034DDC;
    }
    sx = (x >> 8) - gUnk_0203C40C;
    sy = (y >> 8) - gUnk_0203C3F8;

    if (func_080CA4E8(sx, sy, 48, 0, 18, 18, &gUnk_02034DD8, &gUnk_02034DDC) == 0) {
        sx = (p->unk_00 >> 8) - gUnk_0203C40C;
        sy = (p->unk_04 >> 8) - gUnk_0203C3F8;

        if (func_080CA4E8(sx, sy, 48, 0, 18, 18, &gUnk_02034DD8, &gUnk_02034DDC) != 0) {
            p->unk_00 -= gUnk_02034DD8;
            p->unk_04 -= gUnk_02034DDC;
        }
    } else {
        p->unk_00 = x;
        p->unk_04 = y;
    }
    return 1;
}

u8 func_080CA648(PooPos* p) {
    if ((func_080CA36C(p->unk_00 >> 8, p->unk_04 >> 8) & 0x3FF) > 0x3BA) {
        return 1;
    }
    return 0;
}

u16 func_080CA67C(PooPos* p) {
    if (func_080CA648(p) != 0) {
        if (p->unk_04 <= 0x1FFFF) {
            return 1;
        }
        return 2;
    }
    return 0;
}

void func_080CA6A8(s32 a, s32 b) {
    gUnk_0203C3FC += a;
    gUnk_0203C408 += b;
    if (gUnk_02034DE4 < gUnk_0203C408) {
        gUnk_0203C408 = gUnk_02034DE4;
    }
    gUnk_0203C40C = (gUnk_0203C3FC >> 8) - 120;
    gUnk_0203C3F8 = (gUnk_0203C408 >> 8) - 80;
    gUnk_02039BA0->unk_00 = gUnk_0203C40C << 8;
    gUnk_02039BA0->unk_04 = gUnk_0203C3F8 << 8;
    func_08005244(3, gUnk_0203C40C, gUnk_0203C3F8);
    func_08005244(1, gUnk_0203C40C, gUnk_0203C3F8);
    func_08005244(2, gUnk_0203C40C, gUnk_0203C3F8);
}

void func_080CA724(PooSoraWork* w) {
    if ((GetKeysHeld() & 0x20) != 0 && (GetKeysHeld() & 0x80) != 0) {
        w->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x40) != 0 && (GetKeysHeld() & 0x20) != 0) {
        w->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x40) != 0 && (GetKeysHeld() & 0x10) != 0) {
        w->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x10) != 0 && (GetKeysHeld() & 0x80) != 0) {
        w->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x80) != 0 && GetKeyReleaseTime(0x20) <= 4) {
        w->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x80) != 0 && GetKeyReleaseTime(0x10) <= 4) {
        w->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x40) != 0 && GetKeyReleaseTime(0x20) <= 4) {
        w->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x40) != 0 && GetKeyReleaseTime(0x10) <= 4) {
        w->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x20) != 0 && GetKeyReleaseTime(0x40) <= 4) {
        w->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x20) != 0 && GetKeyReleaseTime(0x80) <= 4) {
        w->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x10) != 0 && GetKeyReleaseTime(0x40) <= 4) {
        w->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x10) != 0 && GetKeyReleaseTime(0x80) <= 4) {
        w->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x80) != 0) {
        w->unk_14 = 0x80;
    } else if ((GetKeysHeld() & 0x40) != 0) {
        w->unk_14 = 0;
    } else if ((GetKeysHeld() & 0x20) != 0) {
        w->unk_14 = 0xC0;
    } else if ((GetKeysHeld() & 0x10) != 0) {
        w->unk_14 = 0x40;
    }
}

u8 func_080CA8D4(PooSoraWork* w, PooPos* p) {
    if (w->unk_64 != 0 && func_08012660(w->unk_38, 5) == 0 && func_08012660(w->unk_38, 3) == 0 && func_08012660(w->unk_38, 5) == 0 && func_08012660(w->unk_38, 11) == 0) {
        if (func_080CFF30() != 0) {
            p->unk_00 += w->unk_70;
            p->unk_04 += w->unk_74;
            func_080CFF58((u32*)&p->unk_00, (u32*)&p->unk_04, 1);
        } else {
            p->unk_00 += w->unk_70;
            p->unk_04 += w->unk_74;
        }
        return 1;
    }
    return 0;
}

u8 func_080CA960(PooPos* p) {
    u8 a;

    a = GetAngle(p->unk_00, p->unk_04, gUnk_0203C3EC->unk_00, gUnk_0203C3EC->unk_04);

    switch (((a + 16) & 0xFF) >> 5) {
    case 1:
        return 0x2D;
    case 2:
        return 0x40;
    case 3:
        return 0x53;
    case 4:
        return 0x80;
    case 5:
        return 0xAD;
    case 6:
        return 0xC0;
    case 7:
        return 0xD3;
    case 0:
    default:
        return 0;
    }
}

void func_080CA9DC(PooSoraWork* w) {
    u8 old;

    old = w->unk_14;
    func_080CA724(w);

    if (old != w->unk_14) {
        if (abs((s8)GetAngleDiff(old, w->unk_14)) > 100) {
            w->unk_10 = 0;
        } else {
            w->unk_10 >>= 1;
        }
    }
}

s32 func_080CAA14(PooSoraWork* w) {
    PooPos* p;
    s32 v;

    p = &gUnk_0203C420.unk_00;

    if ((w->unk_66 & 1) != 0) {
        if (p->unk_0C < w->unk_78) {
            v = p->unk_0C;
        } else {
            v = w->unk_78;
        }
        w->unk_AC = 1;
    } else {
        w->unk_AC = 0;
        v = p->unk_0C;
    }
    return v;
}

void func_080CAA50(PooSoraWork* w, s32 b, u16 c) {
    const PooAnimDesc* e;
    s32 d;

    switch (gUnk_0203C420.unk_14) {
    case 0x2D:
        d = 4;
        w->unk_A0 |= 2;
        break;
    case 0x40:
        d = 3;
        w->unk_A0 |= 2;
        break;
    case 0x53:
        d = 2;
        w->unk_A0 |= 2;
        break;
    case 0x80:
        d = 1;
        w->unk_A0 &= ~2;
        break;
    case 0xAD:
        d = 2;
        w->unk_A0 &= ~2;
        break;
    case 0xC0:
        d = 3;
        w->unk_A0 &= ~2;
        break;
    case 0xD3:
        d = 4;
        w->unk_A0 &= ~2;
        break;
    case 0x00:
    default:
        d = 0;
        w->unk_A0 &= ~2;
        break;
    }

    if (w->unk_A4 == b) {
        c |= 4;
    }
    w->unk_A4 = b;
    e = &gUnk_096FCF54[b][d];
    func_08005974(w->unk_08, (u8)e->unk_0C, c, e->unk_04, e->unk_00);
    func_08002A10(w->tiles, e->unk_08);
}

void func_080CAB24(PooActor* p) {
    s32 x;
    s32 y;

    switch (p->unk_14) {
    case 0x2D:
    case 0xD3:
        x = p->unk_00.unk_00 + gSineTable[p->unk_14] * 12;
        y = p->unk_00.unk_04 + -gSineTable[p->unk_14 + 0x40] * 12;
        break;
    case 0x40:
    case 0xC0:
        x = p->unk_00.unk_00 + gSineTable[p->unk_14] * 27;
        y = p->unk_00.unk_04 + -gSineTable[p->unk_14 + 0x40] * 27;
        break;
    case 0x00:
    case 0x53:
    case 0x80:
    case 0xAD:
    default:
        x = p->unk_00.unk_00 + gSineTable[p->unk_14] * 20;
        y = p->unk_00.unk_04 + -gSineTable[p->unk_14 + 0x40] * 20;
        break;
    }
    func_080C7684(x, y, p->unk_00.unk_08 - 0x800);
}

void task_poo_sora_0(PooSoraWork* w) {
    PooActor* a = &gUnk_0203C420;

    gUnk_0203C414 = w->unk_38;
    gUnk_0203C410 = &w->unk_B0;
    gPooSoraWork = w;
    w->tiles = AllocObjTiles(0xA00, 0);
    w->palette = LoadObjPalette(gUnk_08F683A4, 32);
    a->unk_1A = 16;
    w->unk_AC = 0;
    w->unk_98 = 0;
    w->unk_A0 = 0;
    w->unk_A4 = 12;
    a->unk_32 = 0;
    a->unk_30 = 0;
    func_080D2D24(&a->unk_00);
    a->unk_14 = 0xAD;
    a->unk_00.unk_0C = 0;
    a->unk_10 = 0;
    func_080C9FA8(a->unk_00.unk_00, a->unk_00.unk_04 + a->unk_00.unk_08);
    AnimInit((AnimState*)w->unk_08, 0, 0);
    func_080CAA50(w, 0, 1);
    w->gfx = AnimGetGfx((AnimState*)w->unk_08);
    w->unk_A8 = gUnk_096FCF54[11];
    TaskPoolInit(&w->unk_24, 2);
    gUnk_02039BA0 = EwramAlloc(0xE8);
    TaskCreate(&w->unk_24, &gTaskDescFldShadow, a);
    func_080CCB90(&w->unk_B0, 1, a);
    func_080122AC(w->unk_38, 1, 18, 48);
    func_08012324(w->unk_38, a->unk_00.unk_00, a->unk_00.unk_04, a->unk_00.unk_08);
}

u8 func_080CAD08(PooSoraWork* w, u8* t) {
    PooActor* a = &gUnk_0203C420;
    PooPos p;
    s32 z;
    s32 sx;
    s32 sy;
    u16 k;
    u16 v;

    z = func_080CAA14(w);
    sx = a->unk_00.unk_00;
    sy = a->unk_00.unk_04;
    func_080CA9DC((PooSoraWork*)a);

    switch (w->unk_94) {
    case 7:
        if (w->unk_98 == 0) {
            func_080CAA50(w, 10, 0);
        }
        a->unk_00.unk_00 += gSineTable[a->unk_14] * a->unk_10 >> 8;
        a->unk_00.unk_04 += -gSineTable[a->unk_14 + 0x40] * a->unk_10 >> 8;

        if (AnimGetFrame((AnimState*)w->unk_08) > 3) {
            a->unk_00.unk_08 += w->unk_9C;
            w->unk_9C += 66;

            if (a->unk_00.unk_08 > z) {
                a->unk_00.unk_08 = z;
                w->unk_9C = 0;
            }
        } else {
            w->unk_9C = 0;
        }
        a->unk_10 -= 38;

        if (a->unk_10 < 0) {
            a->unk_10 = 0;
        }

        switch (AnimGetFrame((AnimState*)w->unk_08)) {
        case 3:
        case 4:
            func_080CAB24(a);
            break;
        }

        if (AnimIsFinished((AnimState*)w->unk_08) != 0) {
            if (w->unk_9C < 0) {
                w->unk_94 = 3;
            } else {
                w->unk_94 = 4;
            }
        } else {
            w->unk_98++;
        }
        break;
    case 2:
        if (w->unk_98 == 0) {
            func_080CAA50(w, 3, 0);
            a->unk_10 >>= 1;
        }
        a->unk_00.unk_00 += gSineTable[a->unk_14] * a->unk_10 >> 8;
        a->unk_00.unk_04 += -gSineTable[a->unk_14 + 0x40] * a->unk_10 >> 8;

        if (w->unk_98 > 3) {
            if (GetRandom() % 2 != 0) {
                m4aSongNumStart(0x71);
            } else {
                m4aSongNumStart(0x72);
            }
            w->unk_94 = 3;
            w->unk_9C = -0x533;
            a->unk_10 <<= 1;
            w->unk_98 = 0;
        } else {
            w->unk_98++;
        }
        break;
    case 3:
        if ((GetKeysHeld() & 0xF0) != 0) {
            a->unk_10 += 17;

            if (a->unk_10 > 0x200) {
                a->unk_10 = 0x200;
            }
        } else {
            a->unk_10 -= 38;

            if (a->unk_10 < 0) {
                a->unk_10 = 0;
            }
        }

        if (w->unk_9C > -0x200) {
            func_080CAA50(w, 5, 0);
        } else {
            func_080CAA50(w, 4, 0);
        }
        a->unk_00.unk_00 += gSineTable[a->unk_14] * a->unk_10 >> 8;
        a->unk_00.unk_04 += -gSineTable[a->unk_14 + 0x40] * a->unk_10 >> 8;
        a->unk_00.unk_08 += w->unk_9C;
        w->unk_9C += 66;

        if (w->unk_9C < 0) {
            if ((GetKeysHeld() & 2) == 0) {
                w->unk_9C += 64;
            }
        }

        if ((GetKeysPressed() & 1) != 0) {
            w->unk_98 = 0;
            w->unk_94 = 7;
        } else if (w->unk_9C > 0) {
            w->unk_98 = 0;
            w->unk_94 = 4;
        } else {
            w->unk_98++;
        }
        break;
    case 4:
        if ((GetKeysHeld() & 0xF0) != 0) {
            a->unk_10 += 17;

            if (a->unk_10 > 0x200) {
                a->unk_10 = 0x200;
            }
        } else {
            a->unk_10 -= 38;

            if (a->unk_10 < 0) {
                a->unk_10 = 0;
            }
        }

        if (w->unk_9C < 0x200) {
            func_080CAA50(w, 5, 0);
        } else {
            func_080CAA50(w, 6, 0);
        }
        a->unk_00.unk_00 += gSineTable[a->unk_14] * a->unk_10 >> 8;
        a->unk_00.unk_04 += -gSineTable[a->unk_14 + 0x40] * a->unk_10 >> 8;
        a->unk_00.unk_08 += w->unk_9C;
        w->unk_9C += 66;

        if ((GetKeysPressed() & 1) != 0) {
            w->unk_98 = 0;
            w->unk_94 = 7;
        } else if (a->unk_00.unk_08 > z) {
            a->unk_00.unk_08 = z;
            w->unk_9C = 0;

            if (w->unk_94 != 5) {
                w->unk_94 = 5;
                w->unk_98 = 0;
            }
        }
        break;
    case 5:
        if (w->unk_98 == 0) {
            func_080CAA50(w, 7, 0);
            m4aSongNumStart(((const u16*)w->unk_A8)[3]);
        }
        a->unk_10 = 0;
        k = GetKeysPressed() & 2;

        if (k != 0) {
            w->unk_98 = 0;
            w->unk_94 = 2;
        } else if (w->unk_98 > 6) {
            w->unk_94 = 0;
            w->unk_98 = 0;
            SetTaskUpdate(t, (u32)task_poo_sora_1);
        } else {
            w->unk_98++;
        }
        break;
    }

    if (func_080CA8D4(w, &a->unk_00) != 0) {
        a->unk_10 = a->unk_10 * 230 >> 8;
    }
    func_080CA560(&a->unk_00, sx, sy);

    if ((u8)func_080CFE34(&a->unk_00) != 0) {
        if (a->unk_00.unk_08 > -0xA00) {
            p.unk_00 = sx;
            p.unk_04 = sy;

            if ((u8)func_080CFE34(&p) == 0) {
                a->unk_00.unk_00 = sx;
                a->unk_00.unk_04 = sy;
                a->unk_10 = 0;
            } else if (w->unk_9C >= 0) {
                a->unk_10 = 0;
                v = (-a->unk_00.unk_08 >> 8) + 1;
                func_080CFF58((u32*)&a->unk_00, (u32*)&a->unk_00.unk_04, v);
            }
        }
    }
    func_08012324(w->unk_38, a->unk_00.unk_00, a->unk_00.unk_04, a->unk_00.unk_08);
    func_080C9FA8(a->unk_00.unk_00, a->unk_00.unk_04 + a->unk_00.unk_08);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->unk_24);
    return 1;
}

u8 func_080CB1BC(PooSoraWork* w, u8* t) {
    PooActor* a = &gUnk_0203C420;
    s32 sx;
    s32 sy;

    sx = a->unk_00.unk_00;
    sy = a->unk_00.unk_04;

    if (w->unk_94 == 6) {
        if (w->unk_98 == 0) {
            func_080CAA50(w, 9, 0);
            a->unk_10 = 0;
            m4aSongNumStart(0x73);
        }

        if (((AnimState*)w->unk_08)->timer == 0) {
            switch (a->unk_14) {
            case 0xAD:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 -= 0x500;
                    a->unk_00.unk_04 += 0x400;
                    break;
                case 1:
                    a->unk_00.unk_00 -= 0x200;
                    break;
                case 2:
                    a->unk_00.unk_00 -= 0x300;
                    break;
                }
                break;
            case 0x53:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 += 0x500;
                    a->unk_00.unk_04 += 0x400;
                    break;
                case 1:
                    a->unk_00.unk_00 += 0x200;
                    break;
                case 2:
                    a->unk_00.unk_00 += 0x300;
                    break;
                }
                break;
            case 0xD3:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 -= 0x500;
                    a->unk_00.unk_04 -= 0x200;
                    break;
                case 1:
                    a->unk_00.unk_00 -= 0x500;
                    break;
                case 2:
                    a->unk_00.unk_00 -= 0x200;
                    break;
                }
                break;
            case 0x2D:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 += 0x500;
                    a->unk_00.unk_04 -= 0x200;
                    break;
                case 1:
                    a->unk_00.unk_00 += 0x500;
                    break;
                case 2:
                    a->unk_00.unk_00 += 0x200;
                    break;
                }
                break;
            case 0x80:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 -= 0x300;
                    a->unk_00.unk_04 += 0x400;
                    break;
                case 1:
                    a->unk_00.unk_00 += 0x100;
                    a->unk_00.unk_04 += 0x100;
                    break;
                case 2:
                    a->unk_00.unk_04 += 0x200;
                    break;
                case 3:
                    a->unk_00.unk_04 += 0x100;
                    break;
                }
                break;
            case 0x40:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 += 0x700;
                    a->unk_00.unk_04 += 0x100;
                    break;
                case 1:
                    a->unk_00.unk_00 += 0x300;
                    break;
                case 2:
                    a->unk_00.unk_00 += 0x200;
                    break;
                }
                break;
            case 0xC0:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_00 -= 0x700;
                    a->unk_00.unk_04 += 0x100;
                    break;
                case 1:
                    a->unk_00.unk_00 -= 0x300;
                    break;
                case 2:
                    a->unk_00.unk_00 -= 0x200;
                    break;
                }
                break;
            case 0:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->unk_00.unk_04 -= 0x400;
                    break;
                case 1:
                    a->unk_00.unk_04 -= 0x400;
                    break;
                case 2:
                    a->unk_00.unk_00 -= 0x100;
                    a->unk_00.unk_04 += 0x100;
                    break;
                case 3:
                    a->unk_00.unk_04 -= 0x100;
                    break;
                }
                break;
            }
        }

        if (w->unk_98 > 14) {
            func_080CAB24(a);
        }

        if (AnimIsFinished((AnimState*)w->unk_08) != 0) {
            switch (a->unk_14) {
            case 0xAD:
                a->unk_00.unk_00 -= 0x200;
                a->unk_00.unk_04 += 0x200;
                break;
            case 0x53:
                a->unk_00.unk_00 += 0x200;
                a->unk_00.unk_04 += 0x200;
                break;
            case 0xD3:
            case 0x2D:
                a->unk_00.unk_04 -= 0x400;
                break;
            case 0x80:
                a->unk_00.unk_04 += 0x200;
                break;
            case 0:
                a->unk_00.unk_04 -= 0x200;
                break;
            }
            func_080CAA50(w, 0, 0);
            w->unk_94 = 0;
            SetTaskUpdate(t, (u32)task_poo_sora_1);
        } else {
            w->unk_98++;
        }
    }
    func_080CA8D4(w, &a->unk_00);
    func_080CA560(&a->unk_00, sx, sy);

    if ((u8)func_080CFE34(&a->unk_00) != 0) {
        a->unk_00.unk_00 = sx;
        a->unk_00.unk_04 = sy;
        a->unk_10 = 0;
    }
    func_08012324(w->unk_38, a->unk_00.unk_00, a->unk_00.unk_04, a->unk_00.unk_08);
    func_080C9FA8(a->unk_00.unk_00, a->unk_00.unk_04 + a->unk_00.unk_08);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->unk_24);
    return 1;
}

#ifdef NON_MATCHING
u8 func_080CB5A8(PooSoraWork* w, u8* t) {
    s32 x;
    s32 y;

    x = gUnk_0203C420.unk_00.unk_00;
    y = gUnk_0203C420.unk_00.unk_04;

    if (w->unk_94 == 8) {
        if (w->unk_98 == 0) {
            func_080CAA50(w, 8, 1);
            gUnk_0203C420.unk_00.unk_0C = 0;
        }

        if (w->unk_98 > 29) {
            if ((GetKeysHeld() & 0x100) != 0) {
                w->unk_98 = 0;
            } else {
                w->unk_98 = 0;
                w->unk_94 = 0;
                SetTaskUpdate(t, (u32)task_poo_sora_1);
            }
        } else {
            w->unk_98++;
        }
    }
    func_080CA8D4(w, &gUnk_0203C420.unk_00);
    func_080CA560(&gUnk_0203C420.unk_00, x, y);

    if (func_080CFE34(&gUnk_0203C420.unk_00) != 0) {
        gUnk_0203C420.unk_00.unk_00 = x;
        gUnk_0203C420.unk_00.unk_04 = y;
        gUnk_0203C420.unk_00.unk_0C = 0;
    }
    func_08012324(w->unk_38, gUnk_0203C420.unk_00.unk_00, gUnk_0203C420.unk_00.unk_04, gUnk_0203C420.unk_00.unk_08);
    func_080C9FA8(gUnk_0203C420.unk_00.unk_00, gUnk_0203C420.unk_00.unk_04 + gUnk_0203C420.unk_00.unk_08);
    w->gfx = AnimUpdate(w->unk_08);
    TaskPoolUpdate(&w->unk_24);
    return 1;
}
#else
INCLUDE_ASM("poo/func_080CB5A8.s");
#endif

u8 task_poo_sora_1(PooSoraWork* w, u8* t) {
    PooActor* a = &gUnk_0203C420;
    s32 z;
    s32 sx;
    s32 sy;
    u16 v;

    z = func_080CAA14(w);
    sx = a->unk_00.unk_00;
    sy = a->unk_00.unk_04;

    if (w->unk_94 <= 1) {
        func_080CA9DC((PooSoraWork*)a);

        if ((GetKeysHeld() & 0xF0) != 0) {
            a->unk_10 += 128;
            func_080CAA50(w, 2, 1);

            if (a->unk_10 > 0x266) {
                a->unk_10 = 0x266;
            }

            if (((AnimState*)w->unk_08)->timer == 0) {
                switch (((AnimState*)w->unk_08)->frame) {
                case 3:
                    m4aSongNumStart(((const u16*)w->unk_A8)[0]);
                    break;
                case 7:
                    m4aSongNumStart(((const u16*)w->unk_A8)[1]);
                    break;
                }
            }
        } else {
            func_080CAA50(w, 0, 1);
            a->unk_10 -= 128;

            if (a->unk_10 < 0) {
                a->unk_10 = 0;
            }
        }
        a->unk_00.unk_00 += gSineTable[a->unk_14] * a->unk_10 >> 8;
        a->unk_00.unk_04 += -gSineTable[a->unk_14 + 0x40] * a->unk_10 >> 8;

        if ((GetKeysPressed() & 2) != 0) {
            w->unk_98 = 0;
            w->unk_94 = 2;
            SetTaskUpdate(t, (u32)func_080CAD08);
            m4aSongNumStart(((const u16*)w->unk_A8)[2]);
        } else if ((GetKeysPressed() & 1) != 0) {
            func_080CAB24(a);
            gUnk_0203C3D8 = 0;
            v = func_080D2EB8();

#ifdef VERSION_EU
            if (v != 179) {
#else
            if (v != 180) {
#endif
                func_080C7BCC(v);
            } else {
                w->unk_98 = 0;
                w->unk_94 = 6;
                SetTaskUpdate(t, (u32)func_080CB1BC);
            }
        } else if ((GetKeysPressed() & 0x100) != 0) {
            w->unk_98 = 0;
            w->unk_94 = 8;
            SetTaskUpdate(t, (u32)func_080CB5A8);
            a->unk_14 = func_080CA960(&a->unk_00);
        }
    } else if (AnimIsFinished((AnimState*)w->unk_08) != 0) {
        w->unk_94 = 0;
    }

    if (func_080CBAB0(&a->unk_00) != 0) {
        a->unk_10 = 0;
    }

    if (func_080CA8D4(w, &a->unk_00) != 0) {
        a->unk_10 = a->unk_10 * 230 >> 8;
    }
    func_080CA560(&a->unk_00, sx, sy);

    if ((u8)func_080CFE34(&a->unk_00) != 0) {
        a->unk_00.unk_00 = sx;
        a->unk_00.unk_04 = sy;
        a->unk_10 = 0;
    }

    if (z != a->unk_00.unk_08) {
        a->unk_10 >>= 2;
        w->unk_9C = 0;
        w->unk_98 = 0;
        w->unk_94 = 4;
        SetTaskUpdate(t, (u32)func_080CAD08);
    }
    func_08012324(w->unk_38, a->unk_00.unk_00, a->unk_00.unk_04, a->unk_00.unk_08);
    func_080C9FA8(a->unk_00.unk_00, a->unk_00.unk_04 + a->unk_00.unk_08);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->unk_24);
    return 1;
}

#ifdef NON_MATCHING
void task_poo_sora_2(PooSoraWork* w) {
    PooActor* a = &gUnk_0203C420;
    s32 prio;
    s32 c;
    s16 x;
    s16 y;

    c = w->unk_A0 & 2;
    prio = 0x800;

    if (c != 0) {
        prio = 0x801;
    }

    if (w->unk_AC != 0) {
        s32 z;

        gUnk_02034DEC = z = -0x1008 - (w->unk_80 >> 8) * 4;

        if (w->unk_84 <= w->unk_48 || w->unk_88[4] == 0x400) {
            if (w->unk_78 != 0) {
                a->unk_3A = 0;
            } else {
                a->unk_3A = z + 1;
            }
            a->unk_3C = 0;
        } else {
            a->unk_3C = w->unk_78;
            a->unk_3A = z + 1;
        }
    } else {
        s32 z;

        gUnk_02034DEC = z = -0x1008 - (a->unk_00.unk_04 >> 8) * 4;
        a->unk_3C = 0;

        if (a->unk_00.unk_0C != w->unk_AC) {
            a->unk_3A = 0;
        } else {
            a->unk_3A = z + 1;
        }
    }
    x = (a->unk_00.unk_00 >> 8) - gUnk_0203C40C;
    y = (a->unk_00.unk_04 >> 8) + (a->unk_00.unk_08 >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, prio, gUnk_02034DEC - 1);
    TaskPoolDraw(&w->unk_24);
}
#else
INCLUDE_ASM("poo/task_poo_sora_2.s");
#endif

void task_poo_sora_3(PooSoraWork* w) {
    func_080D2D0C(&gUnk_0203C420.unk_00);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    func_08012304(w->unk_38);
    TaskPoolDestroy(&w->unk_24);
    EwramFree(gUnk_02039BA0);
    func_080CCBD4(&w->unk_B0);
}

u8 func_080CBA4C(void) {
    if (gPooSoraWork->unk_94 == 8 && gPooSoraWork->unk_98 == 0) {
        return 1;
    }
    return 0;
}

u8 func_080CBA74(void) {
    if (gPooSoraWork->unk_94 == 8) {
        return 1;
    }
    return 0;
}

u8 func_080CBA8C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (func_080D2D50(i) == 0) {
            return 0;
        }
    }
    return 1;
}

u16 func_080CBAB0(PooPos* p) {
    u16 r;

    r = func_080CA67C(p);
    func_080D2D80(3);

    if (r == 1) {
        func_080C7BCC(0xFFFE);
    } else if (r == 2) {
        func_0800FDD0(13);

        if (func_080C9910() == 0) {
            func_080D2D6C(3);

            if (func_080CBA8C() != 0) {
                if (func_080D2D94(1) != 0) {
#ifdef VERSION_EU
                    func_080C7B84(0x91);
#else
                    func_080C7B84(0x93);
#endif
                } else if (func_080D2D94(0) == 0) {
                    func_080D2D6C(0);
                    func_080D2D6C(1);
                    func_0800FDD0(77);
#ifdef VERSION_EU
                    func_080C7B84(0x8D);
#else
                    func_080C7B84(0x8F);
#endif
                } else {
                    func_080D2D6C(1);
                    func_0800FDD0(77);
#ifdef VERSION_EU
                    func_080C7B84(0x8F);
#else
                    func_080C7B84(0x91);
#endif
                }
            } else if (func_080D2D94(0) == 0) {
                func_080D2D6C(0);
                func_0800FDD0(77);
#ifdef VERSION_EU
                func_080C7B84(0x8E);
#else
                func_080C7B84(0x90);
#endif
            } else {
#ifdef VERSION_EU
                func_080C7B84(0x90);
#else
                func_080C7B84(0x92);
#endif
            }
        } else {
            func_080C7BCC(0xFFFD);
        }
    }
    return r;
}

u16 func_080CBB7C(void) {
    return gUnk_02034DEC - 1;
}

void task_poo_trap_0(PooTrapWork* w, PooPos* p) {
    w->unk_0C = p->unk_00;
    w->unk_10 = p->unk_04;
    w->unk_14 = 0;
    w->tiles = LoadObjTiles(gUnk_0972BD8C, 0x100);
    w->palette = LoadObjPalette(gUnk_09849AB8, 0x20);
    w->unk_08 = gUnk_0972BD78;
    func_08012324(w->unk_1C, w->unk_0C, w->unk_10, w->unk_14);
    w->unk_8C = 0;
}

u8 task_poo_trap_1(PooTrapWork* w) {
    if (w->unk_8C != 0) {
        if (func_08012660(w->unk_1C, 9) != 0) {
            gUnk_0203C3DC = w->unk_0C;
            gUnk_0203C3E8 = w->unk_10;
            gUnk_0203C3F0 = 1;
        }
    }
    return 1;
}

void task_poo_trap_2(PooTrapWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_0C >> 8) - gUnk_0203C40C;
    y = (w->unk_10 >> 8) - gUnk_0203C3F8;
    if (x < -16 || x > 256 || y < -16 || y > 176) {
        if (w->unk_8C != 0) {
            func_08012304(w->unk_1C);
            w->unk_8C = 0;
        }
    } else {
        if (w->unk_8C == 0) {
            func_080122AC(w->unk_1C, 10, 8, 16);
            w->unk_8C = 1;
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, 0xFFEF);
    }
}

void task_poo_trap_3(PooTrapWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);

    if (w->unk_8C != 0) {
        func_08012304(w->unk_1C);
    }
}

void task_poo_pitAndButterfly_0(PooTrapWork* w, PooPos* p) {
    task_poo_trap_0(w, p);
    TaskPoolInit(&w->unk_78, 1);
    TaskCreate(&w->unk_78, &gTaskDescPooButterfly, &w->unk_0C);
    func_080CCB90(&w->unk_90, 0xE10, &w->unk_0C);
}

u8 task_poo_pitAndButterfly_1(PooTrapWork* w) {
    task_poo_trap_1(w);

    if (w->unk_8C != 0) {
        if (func_08012660(w->unk_1C, 9) != 0) {
            func_080CCB84(&w->unk_90.unk_00, 0);
        }
    }
    return 1;
}

void task_poo_pitAndButterfly_2(PooTrapWork* w) {
    task_poo_trap_2(w);

    if (w->unk_8C != 0) {
        TaskPoolUpdate(&w->unk_78);
        TaskPoolDraw(&w->unk_78);
    }
}

void task_poo_pitAndButterfly_3(PooTrapWork* w) {
    task_poo_trap_3(w);
    TaskPoolDestroy(&w->unk_78);
    func_080CCBD4(&w->unk_90);
}

void task_poo_balloon_0(PooBalloonObjWork* w, PooPos* p) {
    w->unk_24 = p;

    if (p->unk_00 == 0x3FD00 && p->unk_04 == 0x21B00) {
        w->tiles = AllocObjTiles(func_08003524(gUnk_09EF5E38, 3), gUnk_0974B4D8);
        w->palette = LoadObjPalette(gUnk_09849C98, 0x20);
        AnimInit(w->anim, gUnk_09EF5E44, gUnk_09EF5E38);
        AnimStart(w->anim, 0, 1);
    } else {
        w->tiles = AllocObjTiles(func_08003524(gUnk_09EF5AD0, 4), gUnk_09732FB6);
        w->palette = LoadObjPalette(gUnk_09849B78, 0x20);
        AnimInit(w->anim, gUnk_09EF5AE0, gUnk_09EF5AD0);
        AnimStart(w->anim, 0, 1);
    }
    w->gfx = AnimGetGfx(w->anim);
}

u8 task_poo_balloon_1(void* w) {
    return 1;
}

void task_poo_balloon_2(PooBalloonObjWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24->unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_24->unk_04 >> 8) + (w->unk_24->unk_08 >> 8) - gUnk_0203C3F8;
    if (x >= -16 && x <= 256 && y >= -16 && y <= 176) {
        w->gfx = AnimUpdate(w->anim);
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_24->unk_04 >> 8) * 4);
    }
}

void task_poo_balloon_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_shadow_0(TaskPool* w, void* arg) {
    PooBalloonArgs args;

    args.unk_00 = arg;
    args.unk_08 = 0xA6;
    TaskPoolInit(w, 1);
    TaskCreate(w, &gTaskDescPooShadowscale, &args);
}

u8 task_poo_shadow_1(TaskPool* w) {
    TaskPoolUpdate(w);
    return 1;
}

void task_poo_shadow_2(TaskPool* w) {
    TaskPoolDraw(w);
}

void task_poo_shadow_3(TaskPool* w) {
    TaskPoolDestroy(w);
}

void task_poo_shadowdodai_0(PooShadowWork* w, PooShadowArgs* a) {
    w->unk_14 = a->unk_00;
    w->unk_18 = a->unk_04;
    w->unk_00 = w->unk_14->unk_00;
    w->unk_04 = w->unk_14->unk_04;
    w->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->anim, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimUpdate(w->anim);
}

u8 task_poo_shadowdodai_1(PooShadowWork* w) {
    w->unk_00 = w->unk_14->unk_00;
    w->unk_04 = w->unk_14->unk_04;
    return 1;
}

void task_poo_shadowdodai_2(PooShadowWork* w) {
    s32 s;
    s32 aff;
    s32 h;
    s16 x;
    s16 y;

    if (w->unk_18->unk_00 != 0) {
        h = w->unk_18->unk_04;
        if (w->unk_14->unk_08 >= h) {
            s = 0xA6;
        } else {
            s = 0xA6 - (h - w->unk_14->unk_08) / 128;
            if (s <= 0x18) {
                s = 0x19;
            }
        }
        aff = AllocObjAffine(0, s, s, 0);
        x = (w->unk_00 >> 8) - gUnk_0203C40C;
        y = (w->unk_04 >> 8) + (h >> 8) - gUnk_0203C3F8;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, aff, 0x800, w->unk_18->unk_00);
    }
}

void task_poo_shadowdodai_3(PooShadowWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_shadowscale_0(PooScaleWork* w, PooShadowArgs* a) {
    w->unk_10 = a->unk_00;
    w->unk_00 = w->unk_10->unk_00;
    w->unk_04 = w->unk_10->unk_04;
    w->unk_2C = a->unk_08;
    w->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->anim, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimUpdate(w->anim);
}

u8 task_poo_shadowscale_1(PooScaleWork* w) {
    w->unk_00 = w->unk_10->unk_00;
    w->unk_04 = w->unk_10->unk_04;
    return 1;
}

void task_poo_shadowscale_2(PooScaleWork* w) {
    s32 s;
    s32 affine;
    u16 x;
    u16 y;

    if (w->unk_10->unk_08 >= 0) {
        s = w->unk_2C;
    } else {
        s = w->unk_2C + w->unk_10->unk_08 / 128;
        if (s <= 0x18) {
            s = 0x19;
        }
    }
    affine = AllocObjAffine(0, s, s, 0);
    x = (w->unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_04 >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, affine, 0x800, 0xFFF0);
}

void task_poo_shadowscale_3(PooScaleWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void func_080CC178(void* pool, void* a, s32 b) {
    PooBalloonArgs args;

    args.unk_00 = a;
    args.unk_08 = b;
    TaskCreate(pool, &gTaskDescPooShadowscale, &args);
}

void task_poo_freeballoon_0(PooFreeBalloonWork* w, PooPos* p) {
    w->unk_24 = *p;
    w->unk_6C = *p;
    w->unk_34 = *p;
    w->unk_7C = *p;
    w->unk_94 = p;
    w->unk_00 = AllocObjTiles(func_08003524(gUnk_09EF5AA0, 4), gUnk_09732272);
    w->unk_04 = LoadObjPalette(gUnk_09849B38, 0x20);
    AnimInit(w->unk_0C, gUnk_09EF5AB4, gUnk_09EF5AA0);
    AnimStart(w->unk_0C, 0, 1);
    w->unk_08 = AnimGetGfx(w->unk_0C);
    w->unk_48 = AllocObjTiles(func_08003524(gUnk_09EF5AB8, 4), gUnk_0973291E);
    w->unk_4C = LoadObjPalette(gUnk_09849B58, 0x20);
    AnimInit(w->unk_54, gUnk_09EF5ACC, gUnk_09EF5AB8);
    AnimStart(w->unk_54, 0, 1);
    w->unk_50 = AnimGetGfx(w->unk_54);
    w->unk_90 = 0;
}

u8 func_080CC284(s16 x, s16 y) {
    if (x < -64 || x > 304) {
        return 0;
    }

    if (y < -64) {
        return 0;
    }

    if (y <= 224) {
        return 1;
    }
    return 0;
}

u8 task_poo_freeballoon_1(PooFreeBalloonWork* w) {
    u16 t;

    w->unk_90++;

    if (w->unk_90 > 5) {
        t = w->unk_90 - 5;
        w->unk_6C.unk_00 = w->unk_7C.unk_00 - t * 256;
        w->unk_6C.unk_04 = w->unk_7C.unk_04 - ((t * t) << 8) / 32;
    } else {
        w->unk_6C = *w->unk_94;
        w->unk_7C = *w->unk_94;
    }
    w->unk_24.unk_00 = w->unk_34.unk_00 + w->unk_90 * 256;
    w->unk_24.unk_04 = w->unk_34.unk_04 - ((w->unk_90 * w->unk_90) << 8) / 32;
    w->unk_8C = (w->unk_6C.unk_00 >> 8) - gUnk_0203C40C;
    w->unk_8E = (w->unk_6C.unk_04 >> 8) + (w->unk_6C.unk_08 >> 8) - gUnk_0203C3F8;
    w->unk_44 = (w->unk_24.unk_00 >> 8) - gUnk_0203C40C;
    w->unk_46 = (w->unk_24.unk_04 >> 8) + (w->unk_24.unk_08 >> 8) - gUnk_0203C3F8;

    if (func_080CC284(w->unk_8C, w->unk_8E) != 0) {
        w->unk_50 = AnimUpdate(w->unk_54);
    } else {
        w->unk_50 = 0;
    }

    if (func_080CC284(w->unk_44, w->unk_46) != 0) {
        w->unk_08 = AnimUpdate(w->unk_0C);
    } else {
        w->unk_08 = 0;
    }

    if (w->unk_08 == 0 && w->unk_50 == 0) {
        return 0;
    }
    return 1;
}

void task_poo_freeballoon_2(PooFreeBalloonWork* w) {
    if (w->unk_50 != 0) {
        DrawSprite(w->unk_8C, w->unk_8E, w->unk_50, w->unk_48, w->unk_4C, 0, 0x800, -0x1004 - (w->unk_6C.unk_04 >> 8) * 4);
    }

    if (w->unk_08 != 0) {
        DrawSprite(w->unk_44, w->unk_46, w->unk_08, w->unk_00, w->unk_04, 0, 0x800, -0x1004 - (w->unk_24.unk_04 >> 8) * 4);
    }
}

void task_poo_freeballoon_3(PooFreeBalloonWork* w) {
    ReleaseObjTiles(w->unk_48);
    ReleaseObjPalette(w->unk_4C);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
}

s32 func_080CC488(u16 x) {
    s32 v;
    u32 a;
    u8 c;

    a = x;
    v = 3 - gUnk_0203C3E4;

    if (gUnk_0203C3E0 <= 0x1CD) {
        c = (a / 20) & 1;
        if (c != 0) {
            if (v <= 2) {
                v++;
            }
        }
    }
    return v;
}

void task_poo_gauge_0(PooGaugeWork* w) {
    w->unk_12 = 0;
    w->tiles = AllocObjTiles(func_08003524(gUnk_09EF5B2C, 4), gUnk_097356F4);
    w->palette = LoadObjPalette(gUnk_09849B98, 0x20);
    w->unk_0C = gUnk_09849B98;
    w->unk_08 = gUnk_09EF5B2C[func_080CC488(w->unk_12)];
    w->unk_10 = 0;
}

u8 task_poo_gauge_1(PooGaugeWork* w) {
    w->unk_12++;
    w->unk_08 = gUnk_09EF5B2C[func_080CC488(w->unk_12)];

    if (gUnk_0203C3E4 <= 1 && gUnk_0203C3E0 <= 0x1CD) {
        w->unk_10 = 1;
    } else {
        w->unk_10 = 0;
    }

    if (w->unk_10 != 0) {
        if (w->unk_0C != gUnk_09849BB8) {
            LoadObjPaletteBank(w->palette->unk_06, gUnk_09849BB8);
            w->unk_0C = gUnk_09849BB8;
        }
    }

    if (w->unk_10 == 0) {
        if (w->unk_0C != gUnk_09849B98) {
            LoadObjPaletteBank(w->palette->unk_06, gUnk_09849B98);
            w->unk_0C = gUnk_09849B98;
        }
    }
    return 1;
}

void task_poo_gauge_2(PooObjWork3* w) {
    DrawSprite(0xDC, 0x18, w->unk_08, w->unk_00, w->unk_04, 0, 0x400, 0);
}

void task_poo_gauge_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_trapballoon_0(PooBalloonWork* w, PooPos* p) {
    w->unk_24 = *p;
    w->unk_24.unk_08 = 0;
    w->unk_24.unk_0C = 0;
    w->unk_CC = func_08003524(gUnk_09EF5AD0, 4);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF5AE0, gUnk_09EF5AD0);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_B0, 3);
    w->unk_C4 = TaskCreate(&w->unk_B0, &gTaskDescPooShadow, &w->unk_24);
    w->unk_C8 = 0;
    w->unk_CE = GetRandom();
    func_08012324(w->unk_34, w->unk_24.unk_00, w->unk_24.unk_04, w->unk_24.unk_08);
}

u8 task_poo_trapballoon_1(PooBalloonWork* w) {
    PooPos t;

    if (w->palette == 0) {
        return 1;
    }

    if (IsTaskActive((Task*)w->unk_C8) != 0) {
        return 1;
    }

    if (IsTaskActive(w->unk_C4) == 0 && IsTaskActive((Task*)w->unk_C8) == 0) {
        return 0;
    }

    if (func_08012660(w->unk_34, 9) != 0 && func_080C9D70() != 0) {
        gUnk_0203C3DC = w->unk_24.unk_00;
        gUnk_0203C3E8 = w->unk_24.unk_04;
        gUnk_0203C3F0 = 2;
        func_080CCB84(&w->unk_90, 0);
        return 0;
    }

    if (gUnk_0203C3D8 == 0) {
        if (func_08012660(w->unk_34, 9) == 0) {
            return 1;
        }

        if (func_080C9D70() != 0) {
            return 1;
        }
    }

    if (func_080C76B0(w->unk_34) == 0) {
        return 1;
    }
    t = w->unk_24;
    t.unk_08 -= 0x1000;
    TaskCreate(&w->unk_B0, &gTaskDescPooSpark, &t);
    func_080CCB84(&w->unk_90, 0);
    func_08012614(w->unk_34, 1);
    func_08000DE8(&w->unk_B0, w->unk_C4);
    w->unk_24.unk_00 -= 0x800;
    w->unk_24.unk_04 += 0x1000;
    w->unk_C8 = (s32)TaskCreate(&w->unk_B0, &gTaskDescPooFreeballoon, &w->unk_24);
    m4aSongNumStart(0x147);
    return 1;
}

void task_poo_trapballoon_2(PooBalloonWork* w) {
    s32 d;
    s16 x;
    s16 y;

    if (IsTaskActive((Task*)w->unk_C8) != 0) {
        TaskPoolUpdate(&w->unk_B0);
        TaskPoolDraw(&w->unk_B0);
    } else {
        w->gfx = AnimUpdate(w->anim);
        w->unk_CE += 2;
        d = gSineTable[w->unk_CE & 0xFF] * 2;
        x = ((w->unk_24.unk_00 - 0x800) >> 8) - gUnk_0203C40C;
        d += 0x1200;
        y = ((w->unk_24.unk_04 + d) >> 8) + (w->unk_24.unk_08 >> 8) - gUnk_0203C3F8;

        if (func_080035CC(x, y, 64, 8, 24, 24) != 0) {
            if (w->palette != 0) {
                ReleaseObjTiles(w->tiles);
                ReleaseObjPalette(w->palette);
                w->palette = 0;
                func_08012304(w->unk_34);
                func_080CCBD4(&w->unk_90);
            }
        } else {
            if (w->palette == 0) {
                w->tiles = AllocObjTiles(w->unk_CC, gUnk_09732FB6);
                w->palette = LoadObjPalette(gUnk_09849B78, 0x20);
                func_080122AC(w->unk_34, 10, 8, 16);
                func_080CCB90(&w->unk_90, 0x400, &w->unk_24);
            }
            DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_24.unk_04 >> 8) * 4);
            TaskPoolUpdate(&w->unk_B0);
            TaskPoolDraw(&w->unk_B0);
        }
    }
}

void task_poo_trapballoon_3(PooBalloonWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_34);
        func_080CCBD4(&w->unk_90);
    }
    TaskPoolDestroy(&w->unk_B0);
}

void task_poo_owlballoon_0(PooOwlBalloonWork* w, PooPos* p) {
    w->unk_24 = *p;
    w->unk_24.unk_08 = 0;
    w->unk_24.unk_0C = 0;
    w->unk_C8 = func_08003524(gUnk_09EF5E38, 3);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF5E44, gUnk_09EF5E38);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_B0, 2);
    w->unk_C4 = TaskCreate(&w->unk_B0, &gTaskDescPooShadow, &w->unk_24);
    func_08012324(w->unk_34, w->unk_24.unk_00, w->unk_24.unk_04, w->unk_24.unk_08);
    func_080CCB90(&w->unk_90, 0x240, &w->unk_24);
}

u8 task_poo_owlballoon_1(PooOwlBalloonWork* w) {
    if (w->palette != 0 && func_08012660(w->unk_34, 9) != 0 && func_080C9D70() != 0) {
        gUnk_0203C3DC = w->unk_24.unk_00;
        gUnk_0203C3E8 = w->unk_24.unk_04;
        gUnk_0203C3F0 = 7;
        func_080CCB84(&w->unk_90.unk_00, 0);
        m4aSongNumStart(0x181);
        return 0;
    }
    return 1;
}

void task_poo_owlballoon_2(PooOwlBalloonWork* w) {
    s16 x;
    s16 y;

    w->gfx = AnimUpdate(w->anim);
    x = ((w->unk_24.unk_00 - 0x800) >> 8) - gUnk_0203C40C;
    y = ((w->unk_24.unk_04 + 0x1000) >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 64, 8, 24, 24) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_34);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_C8, gUnk_0974B4D8);
            w->palette = LoadObjPalette(gUnk_09849C98, 0x20);
            func_080122AC(w->unk_34, 10, 8, 16);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1003 - (w->unk_24.unk_04 >> 8) * 4);
        TaskPoolUpdate(&w->unk_B0);
        TaskPoolDraw(&w->unk_B0);
    }
}

void task_poo_owlballoon_3(PooOwlBalloonWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_34);
    }
    TaskPoolDestroy(&w->unk_B0);
    func_080CCBD4(&w->unk_90);
}

u16 func_080CCB80(u16* p) {
    return *p;
}

void func_080CCB84(u16* p, u16 v) {
    *p = v;
}

u16 func_080CCB88(u16* p) {
    return p[1];
}

void func_080CCB8C(u16* p, u16 v) {
    p[1] = v;
}

void func_080CCB90(PooNode* n, u16 v, void* p) {
    func_080CCB84(&n->unk_00, v);
    func_080CCB8C(&n->unk_00, v);
    n->unk_08 = p;
    n->unk_04 = 0;
    func_08000D20(&n->unk_0C, &gUnk_02034DF8, n);
    func_08000D28(&n->unk_0C, &gUnk_02034DF8);
}

void func_080CCBD4(PooNode* p) {
    func_08000D90(&p->unk_0C, &gUnk_02034DF8);
}

void func_080CCBE8(void) {
    ListPoolInit(&gUnk_02034DF8);
}

s32 func_080CCBF8(PooNode* n) {
    PooPos* q;
    PooPos* p;
    u16 dx;
    u16 dy;
    u16 r;
    s32 d;

    q = gUnk_0203C3EC;
    p = n->unk_08;
    dx = (q->unk_00 - p->unk_00) >> 8;
    dy = (q->unk_04 - p->unk_04) >> 8;
    r = func_080CCB80(&n->unk_00);

    if ((s16)dx * (s16)dx > 0x3840 && (s16)dy * (s16)dy > 0x1900) {
        return 0;
    }

    d = (s16)dx * (s16)dx + (s16)dy * (s16)dy;
    if (d == 0) {
        return r << 8;
    }

    if (r != 0 && (r << 8) / (d << 8) == 0) {
        return 1;
    }
    return (r << 8) / (((s16)dx * (s16)dx + (s16)dy * (s16)dy) << 8);
}

PooNode* func_080CCC98(void) {
    PooNode* best;
    PooNode* n;

    best = (PooNode*)ListPoolFirst(&gUnk_02034DF8);
    n = best;
    gUnk_02034DF0 = 0;

    while (n != 0) {
        gUnk_02034DF4 = func_080CCBF8(n);
        if (gUnk_02034DF4 > gUnk_02034DF0) {
            gUnk_02034DF0 = gUnk_02034DF4;
            best = n;
        }
        n = (PooNode*)ListPoolNext(&n->unk_0C);
    }

    if (gUnk_02034DF0 == 0 && best == (PooNode*)ListPoolFirst(&gUnk_02034DF8)) {
        return 0;
    }
    return best;
}

void task_poo_honey_0(PooHoneyWork* w, PooPos* p) {
    w->unk_24.unk_00 = p->unk_00;
    w->unk_24.unk_04 = p->unk_04;
    w->unk_24.unk_08 = 0;
    w->palette = 0;
    w->unk_20 = func_08003524(gUnk_09EF5AE4, 14);
    AnimInit(w->anim, gUnk_09EF5B1C, gUnk_09EF5AE4);
    AnimStart(w->anim, 3, 1);
    func_08012324(w->unk_74, w->unk_24.unk_00, w->unk_24.unk_04, w->unk_24.unk_08);
    w->unk_34 = w->unk_24;
    w->unk_34.unk_00 += 0xB00;
    w->unk_34.unk_04 -= 0xA00;
    w->unk_54 = w->unk_34;
    w->unk_54.unk_00 -= 0x100;
    w->unk_54.unk_04 -= 0x100;
    w->unk_64 = w->unk_34;
    w->unk_64.unk_00 += 0x100;
    w->unk_64.unk_04 += 0x100;
    TaskPoolInit(&w->unk_F4, 1);
    func_080CC178(&w->unk_F4, &w->unk_24, 0xCC);
    w->unk_F0 = 0;
    w->unk_108 = 0;
}

u8 task_poo_honey_1(PooHoneyWork* w) {
    switch (w->unk_F0) {
    case 0:
        if (w->unk_54.unk_00 <= gUnk_0203C3EC->unk_00 && gUnk_0203C3EC->unk_00 <= w->unk_64.unk_00 && w->unk_54.unk_04 <= gUnk_0203C3EC->unk_04 && gUnk_0203C3EC->unk_04 <= w->unk_64.unk_04) {
            gUnk_0203C3F0 = 3;
            func_080CCB84(&w->unk_D0.unk_00, 0);
            w->unk_F0++;
        }
        break;
    case 1:
        if (func_080C9E4C() <= 2) {
            AnimStart(w->anim, func_080C9E4C(), 0);
            AnimUpdate(w->anim);
            w->unk_F0++;
        }
        break;
    case 2:
        AnimUpdate(w->anim);

        if (AnimIsFinished(w->anim) != 0) {
            return 0;
        }

        switch (AnimGetGfxIndex(w->anim)) {
        case 1:
            w->unk_24 = *gUnk_0203C3EC;
            w->unk_24.unk_00 -= 0xB00;
            w->unk_24.unk_04 += 0xA00;
            w->unk_24.unk_08 = 0;
            w->unk_44 = w->unk_24;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            w->unk_24.unk_00 = w->unk_44.unk_00 + 0x200;
            w->unk_24.unk_04 = w->unk_44.unk_04;
            w->unk_24.unk_08 = w->unk_44.unk_08 - 0x200;
            break;
        case 7:
            w->unk_24.unk_00 = w->unk_44.unk_00 - 0x200;
            w->unk_24.unk_04 = w->unk_44.unk_04 - 0x500;
            w->unk_24.unk_08 = w->unk_44.unk_08 - 0xB00;
            break;
        case 8:
            gUnk_0203C3E4 = 3;
            gUnk_0203C3E0 = 0x73B;
            w->unk_24.unk_00 = w->unk_44.unk_00 + 0xA00;
            w->unk_24.unk_04 = w->unk_44.unk_04 - 0x900;
            w->unk_24.unk_08 = w->unk_44.unk_08 - 0x1000;
            break;
        case 9:
            w->unk_24.unk_00 = w->unk_44.unk_00 + 0x200;
            w->unk_24.unk_04 = w->unk_44.unk_04;
            w->unk_24.unk_08 = w->unk_44.unk_08 - 0x300;
            break;
        case 10:
            w->unk_24.unk_00 = w->unk_44.unk_00 + 0x200;
            w->unk_24.unk_04 = w->unk_44.unk_04;
            w->unk_24.unk_08 = w->unk_44.unk_08 - 0x100;
            break;
        case 11:
        case 12:
        case 13:
            w->unk_24.unk_00 = w->unk_44.unk_00;
            w->unk_24.unk_04 = w->unk_44.unk_04;
            w->unk_24.unk_08 = w->unk_44.unk_08;
            w->unk_108++;
            break;
        case 0:
        default:
            break;
        }
        break;
    default:
        break;
    }
    return 1;
}

void task_poo_honey_2(PooHoneyWork* w) {
    s16 x;
    s16 y;

    if (w->unk_108 > 29 && (w->unk_108 & 1) != 0) {
        return;
    }

    x = (w->unk_24.unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_24.unk_04 >> 8) + (w->unk_24.unk_08 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 24, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_74);
            func_080CCBD4(&w->unk_D0);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_20, gUnk_097339E8);
            w->palette = LoadObjPalette(gUnk_09849B98, 0x20);
            func_080122AC(w->unk_74, 10, 8, 16);
            func_080CCB90(&w->unk_D0, 0x1FA4, &w->unk_34);
        }
        DrawSprite(x, y, AnimGetGfx(w->anim), w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_24.unk_04 >> 8) * 4);
        TaskPoolUpdate(&w->unk_F4);
        TaskPoolDraw(&w->unk_F4);
    }
}

void task_poo_honey_3(PooHoneyWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_74);
        func_080CCBD4(&w->unk_D0);
    }
    TaskPoolDestroy(&w->unk_F4);
}

void task_poo_mapanime_0(PooMapAnimeWork* w) {
    func_080DDDDC(&w->unk_00[0], gUnk_096FD3E8);
    func_080DDDDC(&w->unk_00[1], gUnk_096FD400);
}

u8 task_poo_mapanime_1(PooMapAnimeWork* w) {
    u8 r;
    u32 i;

    r = 0;

    for (i = 0; i < 2; i++) {
        r = func_080DDDEC(&w->unk_00[i], w->unk_00[i].unk_08, r);
    }
    return 1;
}

void task_poo_mapanime_2(void* w) {
}

void task_poo_mapanime_3(void* w) {
}

s32 func_080CD198(void) {
    switch (GetRandom() % 40 / 10) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 4;
    }
    return 6;
}

s32 func_080CD1DC(u32 a) {
    if (a == 0) {
        return 1;
    }

    if (a <= 2) {
        return 3;
    }

    if (a <= 4) {
        return 5;
    }
    return 7;
}

s32 func_080CD1F8(u32 a) {
    if (a == 0) {
        return 32;
    }

    if (a <= 2) {
        return 24;
    }

    if (a <= 4) {
        return 16;
    }
    return 9;
}

void task_poo_pile_0(PooPileWork* w, PooPileArgs* a) {
    w->unk_24 = a->unk_00;
    w->unk_28 = a->unk_04;
    w->unk_2C = 0;
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF5C8C, gUnk_09EF5C6C);

    if (a->unk_10 == 8) {
        w->unk_B0 = func_080CD198();
    } else {
        w->unk_B0 = a->unk_10;
    }
    AnimStart(w->anim, w->unk_B0, 0);
    w->gfx = AnimGetGfx(w->anim);
    func_08012324(w->unk_34, w->unk_24, w->unk_28, w->unk_2C);
    w->unk_CC = 0;
    TaskPoolInit(&w->unk_B4, 1);
    w->unk_C8 = 0;
}

u8 task_poo_pile_1(PooPileWork* w) {
    PooPos t;

    if (w->unk_B0 == 7) {
        return 1;
    }

    if (w->unk_CC == 0) {
        return 1;
    }

    if (func_08012660(w->unk_34, 9) != 0) {
        gUnk_0203C3F0 = 5;
    }

    if (gUnk_0203C3D8 == 0) {
        return 1;
    }

    if (func_080C76B0(w->unk_34) == 0) {
        return 1;
    }

    if (AnimIsFinished(w->anim) == 0) {
        return 1;
    }
    t = *(PooPos*)&w->unk_24;
    t.unk_08 -= (u16)func_080CD1F8(w->unk_B0) * 256;

    if (IsTaskActive((Task*)w->unk_C8) != 0) {
        func_08000DE8(&w->unk_B4, (Task*)w->unk_C8);
    }
    w->unk_C8 = (s32)TaskCreate(&w->unk_B4, &gTaskDescPooSpark, &t);
    w->unk_B0 = func_080CD1DC(w->unk_B0);
    AnimStart(w->anim, w->unk_B0, 0);
    m4aSongNumStart(0x146);

    if (w->unk_B0 == 7) {
        func_08012304(w->unk_34);
        w->unk_CC = 0;
        func_080CCBD4(&w->unk_90);
    } else {
        ColliderSetHeight(w->unk_34, (u16)func_080CD1F8(w->unk_B0));
    }
    return 1;
}

void task_poo_pile_2(PooPileWork* w) {
    u16 z;
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (x < -16 || x > 256 || y < -36 || y > 196) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }

        if (w->unk_CC != 0) {
            func_08012304(w->unk_34);
            func_080CCBD4(&w->unk_90);
            w->unk_CC = 0;
        }
        TaskPoolUpdate(&w->unk_B4);
        TaskPoolDraw(&w->unk_B4);
    } else {
        w->gfx = AnimUpdate(w->anim);

        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_09742CC2, 0x300);
            w->palette = LoadObjPalette(gUnk_09849BF8, 0x20);
        }

        if (w->unk_B0 != 7) {
            z = -0x1004 - (w->unk_28 >> 8) * 4;

            if (w->unk_CC == 0) {
                func_080122AC(w->unk_34, 7, 4, (u16)func_080CD1F8(w->unk_B0));
                func_080CCB90(&w->unk_90, 0x240, &w->unk_24);
                w->unk_CC = 1;
            }
        } else {
            z = 0xFFF1;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, z);
        TaskPoolUpdate(&w->unk_B4);
        TaskPoolDraw(&w->unk_B4);
    }
}

void task_poo_pile_3(PooPileWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_CC != 0) {
        func_08012304(w->unk_34);
        func_080CCBD4(&w->unk_90);
    }
    TaskPoolDestroy(&w->unk_B4);
}

void func_080CD550(void* pool, u16 b, void* c, void* d) {
    s32 t[6];
    PooStumpArgs args;

    memcpy(t, gUnk_096FD43C, sizeof(t));
    args.unk_00 = c;
    args.unk_04 = d;
    args.unk_10 = t[b];
    TaskCreate(pool, &gTaskDescPooPile, &args);
}

void task_poo_tigerstump_0(PooStumpWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04 + 0x800;
    w->unk_2C = 0;
    w->palette = 0;
    w->unk_08 = gUnk_097561D4;
    func_08012324(w->unk_34, w->unk_24, w->unk_28, 0);
}

u8 task_poo_tigerstump_1(PooStumpWork* w) {
    if (w->palette != 0) {
        if (func_08012660(w->unk_34, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_tigerstump_2(PooStumpWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = ((w->unk_28 - 0x800) >> 8) - gUnk_0203C3F8;
    if (x < -96 || x > 336 || y < -64 || y > 224) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_34);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_097561E8, 0x400);
            w->palette = LoadObjPalette(gUnk_09849D38, 0x20);
            func_080122AC(w->unk_34, 7, 15, 24);
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, -0x1004 - ((w->unk_28 - 0x700) >> 8) * 4);
    }
}

void task_poo_tigerstump_3(PooStumpWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_34);
    }
}

void task_poo_poohstump_0(PooStumpWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04;
    w->unk_2C = 0;
    w->palette = 0;
    w->unk_08 = gUnk_09755F34;
    func_08012324(w->unk_34, w->unk_24, w->unk_28, 0);
}

u8 task_poo_poohstump_1(PooStumpWork* w) {
    if (w->palette != 0) {
        if (func_08012660(w->unk_34, 9) != 0) {
            gUnk_0203C3DC = w->unk_24;
            gUnk_0203C3E8 = w->unk_28;
            gUnk_0203C3F0 = 8;
        }
    }
    return 1;
}

void task_poo_poohstump_2(PooStumpWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (x < -80 || x > 320 || y < -24 || y > 184) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_34);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_09755F54, 0x280);
            w->palette = LoadObjPalette(gUnk_09849D38, 0x20);
            func_080122AC(w->unk_34, 7, 7, 14);
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, -0x1004 - ((w->unk_28 - 0x500) >> 8) * 4);
    }
}

void task_poo_poohstump_3(PooStumpWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_34);
    }
}

void func_080CD854(PooAnimWork* w, s32 b, u16 c) {
    if (w->unk_26 != b) {
        w->unk_26 = b;
        func_08005974(w->unk_0C, gUnk_096FD47C[b].unk_0C, c, gUnk_096FD47C[b].unk_00, gUnk_096FD47C[b].unk_04);
        func_08002A10(w->unk_00, gUnk_096FD47C[b].unk_08);
    }
}

void task_poo_piglet_0(PooPigletWork* w) {
    u16 m;
    u16 n;
    u8 i;

    w->unk_28 = 0x2A500;
    w->unk_2C = 0x21100;
    w->unk_30 = 0;
    w->unk_A8 = 0;
    w->unk_AC = 0;
    w->palette = 0;
    m = 0;

    for (i = 0; i < 4; i++) {
        n = func_08003524(gUnk_096FD4BC[i].unk_00, gUnk_096FD4BC[i].unk_04);

        if (m < n) {
            m = n;
        }
    }
    w->tiles = AllocObjTiles(m, 0);
    AnimInit(w->anim, 0, 0);
    w->unk_26 = 4;
    func_080CD854((PooAnimWork*)w, 0, 1);
    w->unk_24 = 0;
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_94, 1);
    TaskCreate(&w->unk_94, &gTaskDescPooShadow, &w->unk_28);

    if (func_080D2D50(0) != 0) {
        w->unk_B4 = func_080D2E28(w->unk_38, 0x36);
        func_080D2E70(w->unk_B4, 0);
    }
}

u8 task_poo_piglet_1(PooPigletWork* w) {
    if (w->palette != 0 && w->unk_38[0x2C] != 0) {
        if (func_08012660(w->unk_38, 9) == 0) {
            return 1;
        }

        if (func_080D2D50(0) != 0) {
            return 1;
        }
        gUnk_0203C3DC = w->unk_28;
        gUnk_0203C3E8 = w->unk_2C;
        gUnk_0203C3F0 = 4;
#ifdef VERSION_EU
        func_080C7B84(134);
#else
        func_080C7B84(136);
#endif
        func_080D2D3C(0);
        func_0800FDD0(78);
    }

    switch (w->unk_A8) {
    case 0:
        func_080CD854((PooAnimWork*)w, 0, 1);
        w->unk_24 = 0;

        if (w->unk_AC > 209) {
            w->unk_A8 = 1;
            w->unk_B0 = 0;
        } else {
            w->unk_AC++;
        }
        break;
    case 1:
        func_080CD854((PooAnimWork*)w, 3, 1);
        w->unk_24 = 1;
        w->unk_B0 += 0x600;

        if (w->unk_B0 > 128) {
            w->unk_B0 = 128;
        }
        w->unk_28 += gSineTable[0x20] * w->unk_B0 >> 8;
        w->unk_2C += -gSineTable[0x60] * w->unk_B0 >> 8;

        if (w->unk_28 > 0x2C8FF) {
            w->unk_A8 = 2;
            w->unk_AC = 0;
        }
        break;
    case 2:
        func_080CD854((PooAnimWork*)w, 1, 1);
        w->unk_24 = 1;

        if (w->unk_AC > 39) {
            w->unk_A8 = 3;
            w->unk_AC = 0;
        } else {
            w->unk_AC++;
        }
        break;
    case 3:
        func_080CD854((PooAnimWork*)w, 0, 1);
        w->unk_24 = 1;

        if (w->unk_AC > 29) {
            w->unk_A8 = 4;
            w->unk_AC = 0;
        } else {
            w->unk_AC++;
        }
        break;
    case 4:
        func_080CD854((PooAnimWork*)w, 1, 1);
        w->unk_24 = 1;

        if (w->unk_AC > 29) {
            w->unk_A8 = 5;
            w->unk_AC = 0;
        } else {
            w->unk_AC++;
        }
        break;
    case 5:
        func_080CD854((PooAnimWork*)w, 0, 1);
        w->unk_24 = 1;

        if (w->unk_AC <= 59) {
            w->unk_AC++;
        } else {
            w->unk_A8 = 6;
            w->unk_B0 = 0;
        }
        break;
    case 6:
        func_080CD854((PooAnimWork*)w, 2, 1);
        w->unk_24 = 0;
        w->unk_B0 += 0x600;

        if (w->unk_B0 > 128) {
            w->unk_B0 = 128;
        }
        w->unk_28 += gSineTable[0xA0] * w->unk_B0 >> 8;
        w->unk_2C += -gSineTable[0xE0] * w->unk_B0 >> 8;

        if (w->unk_28 <= 0x2A500) {
            w->unk_28 = 0x2A500;
            w->unk_2C = 0x21100;
            w->unk_A8 = 0;
            w->unk_AC = 0;
        }
        break;
    default:
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_piglet_2(PooPigletWork* w) {
    s32 pr;
    s16 x;
    s16 y;

    x = (w->unk_28 >> 8) - gUnk_0203C40C;
    y = (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 24, 8, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            func_08012304(w->unk_38);
            func_080D2E70(w->unk_B4, 0);
            w->palette = 0;
        }
    } else {
        TaskPoolUpdate(&w->unk_94);
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849C18, 0x20);
            if (func_080D2D50(0) != 0) {
                func_080122AC(w->unk_38, 10, 4, 16);
            } else {
                func_080122AC(w->unk_38, 10, 16, 16);
            }
            func_080D2E70(w->unk_B4, 1);
        }
        func_08012324(w->unk_38, w->unk_28, w->unk_2C, w->unk_30);
        pr = w->unk_24 != 0 ? 0x801 : 0x800;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, -0x1004 - (w->unk_2C >> 8) * 4);
        TaskPoolDraw(&w->unk_94);
    }
}

void task_poo_piglet_3(PooPigletWork* w) {
    ReleaseObjTiles(w->tiles);

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_38);
    }
    TaskPoolDestroy(&w->unk_94);
}

void task_poo_eeyore_0(PooEeyoreWork* w) {
    w->unk_24 = 0x82700;
    w->unk_28 = 0x47E00;
    w->unk_2C = 0;
    w->unk_30 = 0;
    w->unk_A8 = func_08003524(gUnk_09EF5D68, 0x10);
    w->tiles = 0;
    w->palette = 0;

    if (func_080D2D50(2) != 0) {
        w->unk_A4 = 0;
    } else {
        w->unk_A4 = 4;
    }
    AnimInit(w->anim, gUnk_09EF5DA8, gUnk_09EF5D68);
    AnimStart(w->anim, w->unk_A4, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_90, 1);
    TaskCreate(&w->unk_90, &gTaskDescPooShadow, &w->unk_24);
    func_080122AC(w->unk_34, 10, 16, 16);
    func_08012324(w->unk_34, w->unk_24, w->unk_28, w->unk_2C);
    w->unk_AC = 1;

    if (func_080D2D50(2) == 0) {
        w->unk_AE = func_080D2E28(w->unk_34, 0x38);
    } else {
        w->unk_AE = func_080D2E28(w->unk_34, 0x39);
    }
    func_080D2E70(w->unk_AE, 1);
    w->unk_AA = 0;
}

u8 task_poo_eeyore_1(PooEeyoreWork* w) {
    if (w->unk_AC != 0) {
        if (func_08012660(w->unk_34, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }

    if (func_080CFA70() != 0 && w->unk_A4 == 4) {
        w->unk_A4 = 5;
        AnimStart(w->anim, 5, 1);
        w->unk_AA = 180;
    }

    if (w->unk_AA != 0) {
        ApproachValue((u32*)&w->unk_24, 0x80B00, w->unk_AA);
        ApproachValue((u32*)&w->unk_28, 0x48C00, w->unk_AA);
        func_080C9FA8(w->unk_24, w->unk_28 + w->unk_2C);
        w->unk_AA--;
        if (w->unk_AA == 0) {
#ifdef VERSION_EU
            func_080C7B84(0x8A);
#else
            func_080C7B84(0x8C);
#endif
            func_080D2D3C(2);
            func_0800FDD0(0x51);
            w->unk_A4 = 1;
            AnimStart(w->anim, 1, 1);
        }
    }
    return 1;
}

void task_poo_eeyore_2(PooEeyoreWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 24, 10, 24, 24) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ReleaseObjTiles(w->tiles);
        }
        p = &w->unk_AC;
        if (*p != 0) {
            func_08012304(w->unk_34);
            func_080D2E70(w->unk_AE, 0);
            *p = 0;
        }
    } else {
        p = &w->unk_AC;
        if (*p == 0) {
            func_080122AC(w->unk_34, 10, 16, 16);
            func_080D2E70(w->unk_AE, 1);
            *p = 1;
        }
        func_08012324(w->unk_34, w->unk_24, w->unk_28, w->unk_2C);
        w->gfx = AnimUpdate(w->anim);
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849C58, 0x20);
            w->tiles = AllocObjTiles(w->unk_A8, gUnk_097448BA);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_28 >> 8) * 4);
        TaskPoolUpdate(&w->unk_90);
        TaskPoolDraw(&w->unk_90);
    }
}

void task_poo_eeyore_3(PooEeyoreWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_AC != 0) {
        func_08012304(w->unk_34);
    }
    TaskPoolDestroy(&w->unk_90);
}

void task_poo_owl_0(PooOwlWork* w) {
    w->unk_24.unk_00 = 0x41500;
    w->unk_24.unk_04 = 0x20700;
    w->unk_24.unk_08 = -0x3000;
    w->unk_24.unk_0C = 0;
    w->unk_4C = func_08003524(gUnk_09EF5DC4, 18);
    w->palette = 0;
    w->gfx = gUnk_09746EDC;
    AnimInit(w->unk_0C, gUnk_09EF5E24, gUnk_09EF5DC4);
    w->unk_48 = 0;
    w->unk_49 = 0;
    gUnk_02034E08.unk_00 = 0x3FD00;
    gUnk_02034E08.unk_04 = 0x21B00;
    TaskPoolInit(&w->unk_34, 1);
    TaskCreate(&w->unk_34, &gTaskDescPooOwlballoon, &gUnk_02034E08);
}

u8 task_poo_owl_1(PooOwlWork* w) {
    if (func_080C9D5C() != 0) {
        func_080C9FA8(gUnk_0203C3EC->unk_00, gUnk_0203C3EC->unk_04 + gUnk_0203C3EC->unk_08);

        if (gUnk_0203C3EC->unk_08 <= -0x3800) {
            func_080CA09C();
        }

        if (func_080C9910() != 0) {
            if (w->unk_48 == 0) {
                w->unk_48 = 1;
                AnimStart(w->unk_0C, 1, 0);
                w->unk_4A = 60;
                m4aSongNumStart(0x15F);
            }

            if (AnimGetFrame(w->unk_0C) > 3) {
                if (w->unk_4A != 0) {
                    func_0800592C(&w->unk_24.unk_08, -0x9000, w->unk_4A);
                    w->unk_4A--;
                    w->unk_24.unk_00 -= 204;
                } else {
                    w->unk_24.unk_08 -= 0x100;
                }
            }
            w->gfx = AnimUpdate(w->unk_0C);
        }
    }

    if (func_080C9D48() != 0) {
        if (w->unk_49 == 0) {
            w->unk_49 = 1;
            AnimStart(w->unk_0C, 4, 1);
        }

        if (AnimGetFrame(w->unk_0C) == 0 && w->unk_16 == 0) {
            m4aSongNumStart(0x158);
        }
        w->unk_24 = *gUnk_0203C3EC;
        w->gfx = AnimUpdate(w->unk_0C);
    }
    TaskPoolUpdate(&w->unk_34);
    return 1;
}

void task_poo_owl_2(PooOwlWork* w) {
    s16 x;
    s16 y;

    TaskPoolDraw(&w->unk_34);
    x = (w->unk_24.unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_24.unk_04 >> 8) + (w->unk_24.unk_08 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 24, 8, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_4C, gUnk_097471E2);
            w->palette = LoadObjPalette(gUnk_09849C78, 0x20);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - ((w->unk_24.unk_04 + w->unk_24.unk_08) >> 8) * 4);
    }
}

void task_poo_owl_3(PooOwlWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
    TaskPoolDestroy(&w->unk_34);
}

void func_080CE2C4(PooRabbitWork* w, s32 b, u16 c) {
    if (w->unk_A8 != b) {
        w->unk_A8 = b;
        func_08005974(w->anim, gUnk_096FD50C[b].unk_0C, c, gUnk_096FD50C[b].unk_00, gUnk_096FD50C[b].unk_04);
        func_08002A10(w->tiles, gUnk_096FD50C[b].unk_08);
    }
}

void task_poo_rabbit_0(PooRabbitWork* w) {
    u16 m;
    u16 n;
    u8 i;

    w->unk_28 = 0x1B700;
    w->unk_2C = 0x16E00;
    w->unk_30 = 0;
    w->unk_34 = 0;
    w->palette = 0;
    m = 0;

    for (i = 0; i < 2; i++) {
        n = func_08003524(gUnk_096FD57C[i].unk_00, gUnk_096FD57C[i].unk_04);

        if (m < n) {
            m = n;
        }
    }
    w->tiles = AllocObjTiles(m, 0);
    AnimInit(w->anim, 0, 0);
    w->unk_A8 = 7;
    func_080CE2C4(w, 1, 0);
    w->unk_24 = 0;
    w->unk_AC = 0;
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_38, 1);
    func_080CC178(&w->unk_38, &w->unk_28, 0x100);
    func_08012324(w->unk_4C, w->unk_28, w->unk_2C, w->unk_30);
    w->unk_AE = func_080D2E28(w->unk_4C, 0x3B);
    func_080D2E70(w->unk_AE, 0);
}

u8 task_poo_rabbit_1(PooRabbitWork* w) {
    switch (w->unk_A8) {
    case 1:
        if (AnimIsFinished(w->anim) != 0) {
            w->unk_AC++;

            if (w->unk_AC <= 3) {
                AnimReset(w->anim);
            } else {
                func_080CE2C4(w, 4, 1);
                w->unk_24 = 1;
                w->unk_AC = 312;
            }
        }
        break;
    case 4:
        if (w->palette != 0 && w->unk_4C[0x2C] != 0 && func_08012660(w->unk_4C, 9) != 0) {
            func_080CE2C4(w, 6, 0);
            w->unk_B0 = 20;
        } else {
            ApproachValue(&w->unk_28, 0x23000, w->unk_AC);
            ApproachValue(&w->unk_2C, 0x12400, w->unk_AC);
            w->unk_AC--;

            if (w->unk_AC == 0) {
                func_080CE2C4(w, 5, 0);
                w->unk_24 = 1;
            }
        }
        break;
    case 5:
        if (AnimIsFinished(w->anim) != 0) {
            func_080CE2C4(w, 2, 1);
            w->unk_24 = 0;
            w->unk_AC = 260;
        }
        break;
    case 2:
        if (w->palette != 0 && w->unk_4C[0x2C] != 0 && func_08012660(w->unk_4C, 9) != 0) {
            w->unk_B0 = 20;
            func_080CE2C4(w, 0, 0);
        } else {
            ApproachValue(&w->unk_28, 0x1B700, w->unk_AC);
            ApproachValue(&w->unk_2C, 0x16E00, w->unk_AC);
            w->unk_AC--;

            if (w->unk_AC == 0) {
                func_080CE2C4(w, 1, 0);
                w->unk_24 = 0;
                w->unk_AC = 0;
            }
        }
        break;
    case 6:
        if (w->unk_B0 == 0) {
            if (w->palette != 0 && func_08012660(w->unk_4C, 9) == 0) {
                func_080CE2C4(w, 4, 1);
            }
        } else {
            w->unk_B0--;
        }
        break;
    case 0:
        if (w->unk_B0 != 0) {
            w->unk_B0--;
        } else if (w->palette != 0 && func_08012660(w->unk_4C, 9) == 0) {
            func_080CE2C4(w, 2, 1);
        }
        break;
    default:
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_rabbit_2(PooRabbitWork* w) {
    TaskPool* pool;
    s32 pr;
    s16 x;
    s16 y;

    x = (w->unk_28 >> 8) - gUnk_0203C40C;
    y = (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 48, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            func_08012304(w->unk_4C);
            func_080D2E70(w->unk_AE, 0);
            w->palette = 0;
        }
    } else {
        pool = &w->unk_38;
        TaskPoolUpdate(pool);
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849CB8, 0x40);
            func_080122AC(w->unk_4C, 10, 4, 48);
            func_080D2E70(w->unk_AE, 1);
        }
        func_08012324(w->unk_4C, w->unk_28, w->unk_2C, w->unk_30);
        pr = w->unk_24 != 0 ? 0x801 : 0x800;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, -0x1004 - (w->unk_2C >> 8) * 4);
        TaskPoolDraw(pool);
    }
}

void task_poo_rabbit_3(PooRabbitWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_4C);
    }
    TaskPoolDestroy(&w->unk_38);
}

void func_080CE710(PooTiggerWork* w, u16 b) {
    s32 a;

    AnimReset(w->anim);

    if (w->unk_C0 == 2) {
        switch (w->unk_B8) {
        case 0xAD:
            a = 2;
            w->unk_24 = 0;
            break;
        case 0x53:
            a = 2;
            w->unk_24 = 1;
            break;
        case 0xD3:
            a = 3;
            w->unk_24 = 0;
            break;
        case 0x00:
        default:
            a = 3;
            w->unk_24 = 1;
            break;
        }
    } else {
        a = 0;
    }

    if (w->unk_26 != a) {
        w->unk_26 = a;
        AnimStart(w->anim, a, b);
    }
}

void func_080CE77C(PooTiggerWork* w, u16 b) {
    u16 r;

    AnimReset(w->anim);

    if (w->unk_C0 == 0) {
        r = 0;
    } else if (w->unk_C0 == 1) {
        r = 1;
    } else if (w->unk_C0 == 2) {
        switch (w->unk_B8) {
        case 0xAD:
            r = 2;
            w->unk_24 = 0;
            break;
        case 0x53:
            r = 2;
            w->unk_24 = 1;
            break;
        case 0xD3:
            r = 3;
            w->unk_24 = 0;
            break;
        case 0x2D:
        default:
            r = 3;
            w->unk_24 = 1;
            break;
        }
    } else {
        r = 0;
    }

    if (w->unk_26 != r) {
        w->unk_26 = r;
        func_08005974(w->anim, gUnk_096FD59C[r].unk_0C, b, gUnk_096FD59C[r].unk_00, gUnk_096FD59C[r].unk_04);
        func_08002A10(w->tiles, gUnk_096FD59C[r].unk_08);
    }
}

void func_080CE818(PooTiggerWork* w) {
    PooAnimData* d;
    s32 t[8];

    memcpy(t, gUnk_096FD61C, sizeof(t));
    d = ((PooAnimData**)gUnk_096FD59C[w->unk_26].unk_00)[gUnk_096FD59C[w->unk_26].unk_0C];
    w->unk_BC = (&d->unk_08[w->unk_BE])->unk_00;
    w->unk_B0 = t[w->unk_BE] - 0x1800;
    w->unk_BE++;
}

u16 func_080CE880(PooAnimWork* w) {
    PooAnimData* d;
    u16 t;
    s32 i;

    d = ((PooAnimData**)gUnk_096FD59C[w->unk_26].unk_00)[gUnk_096FD59C[w->unk_26].unk_0C];
    t = 0;

    for (i = 0; i < d->unk_04; i++) {
        t += d->unk_08[i].unk_00;
    }
    return t;
}

void func_080CE8B4(PooTiggerWork* w) {
    w->unk_BA = func_080CE880(w);

    if (w->unk_B8 == 0xAD) {
        w->unk_28 = gUnk_096FD5FC[0];
        w->unk_2C = gUnk_096FD5FC[1];
        w->unk_A8 = gUnk_096FD5FC[2];
        w->unk_AC = gUnk_096FD5FC[3];
    } else if (w->unk_B8 == 0x53) {
        w->unk_28 = gUnk_096FD5FC[2];
        w->unk_2C = gUnk_096FD5FC[3];
        w->unk_A8 = gUnk_096FD5FC[4];
        w->unk_AC = gUnk_096FD5FC[5];
    } else if (w->unk_B8 == 0x2D) {
        w->unk_28 = gUnk_096FD5FC[4];
        w->unk_2C = gUnk_096FD5FC[5];
        w->unk_A8 = gUnk_096FD5FC[6];
        w->unk_AC = gUnk_096FD5FC[7];
    } else {
        w->unk_28 = gUnk_096FD5FC[6];
        w->unk_2C = gUnk_096FD5FC[7];
        w->unk_A8 = gUnk_096FD5FC[0];
        w->unk_AC = gUnk_096FD5FC[1];
    }
    w->unk_30 = -0x1800;
    w->unk_BE = 0;
    func_080CE818(w);
}

void func_080CE960(s32 x, s32 y, s32 z, u8 c) {
    s16 sx;
    s16 sy;

    sx = (x >> 8) - gUnk_0203C40C;
    sy = (y >> 8) + (z >> 8) - gUnk_0203C3F8;
    if (func_080035CC(sx, sy, 120, 8, 24, 24) == 0) {
        if (c != 0) {
            m4aSongNumStart(0x3C1);
        } else {
            m4aSongNumStart(0x3B9);
        }
    }
}

void task_poo_tigger_0(PooTiggerWork* w) {
    PooTiggerArgs args;
    u16 m;
    u16 t;
    u8 i;

    w->unk_C0 = 2;
    w->unk_B8 = 0xAD;
    w->unk_D1 = 1;
    w->palette = 0;
    m = 0;

    for (i = 0; i < 4; i++) {
        t = func_08003524(gUnk_096FD5DC[i].unk_00, gUnk_096FD5DC[i].unk_04);
        if (m < t) {
            m = t;
        }
    }
    w->tiles = AllocObjTiles(m, 0);
    AnimInit(w->anim, 0, 0);
    w->unk_26 = 4;
    func_080CE77C(w, 0);
    func_080CE8B4(w);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_94, 1);
    args.unk_00 = &w->unk_28;
    args.unk_04 = &w->unk_C8;
    TaskCreate(&w->unk_94, &gTaskDescPooShadowdodai, &args);
    func_08012324(w->unk_38, w->unk_28, w->unk_2C, w->unk_30);
}

u8 task_poo_tiggerroo_1(PooTiggerWork* w) {
    func_080C8B38((PooAim*)w->unk_38, (PooPos*)&w->unk_28, &w->unk_D0);

    if (w->unk_C0 == 2) {
        if (w->unk_BA > 0) {
            func_0800592C(&w->unk_28, w->unk_A8, w->unk_BA);
            func_0800592C(&w->unk_2C, w->unk_AC, w->unk_BA);
            w->unk_BA--;
            ApproachValue((u32*)&w->unk_30, w->unk_B0, w->unk_BC);
            w->unk_BC--;

            if (w->unk_BC == 0) {
                func_080CE818(w);
            }
        } else {
            switch (w->unk_B8) {
            case 0xAD:
                w->unk_B8 = 0x53;
                break;
            case 0x53:
                w->unk_B8 = 0x2D;
                break;
            case 0x2D:
                w->unk_B8 = 0xD3;
                break;
            case 0xD3:
                w->unk_B8 = 0xAD;
                break;
            }

            if (w->unk_D1 != 0) {
                func_080CE77C(w, 0);
            } else {
                func_080CE710(w, 0);
            }
            func_080CE8B4(w);
            func_080CE960(w->unk_28, w->unk_2C, w->unk_30, w->unk_D1);
        }
    }
    w->gfx = AnimUpdate(w->anim);
    TaskPoolUpdate(&w->unk_94);
    return 1;
}

void task_poo_tiggerroo_2(PooTiggerWork* w) {
    u16 z;
    s32 pr;
    s32 d;
    s16 x;
    s16 y;

    x = (w->unk_28 >> 8) - gUnk_0203C40C;
    y = (w->unk_2C >> 8) + (w->unk_30 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 56, 8, 24, 24) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_38);

            if (w->unk_D1 == 0) {
                if (w->tiles != 0) {
                    ReleaseObjTiles(w->tiles);
                    w->tiles = 0;
                }
            }
        }
    } else {
        if (w->palette == 0) {
            if (w->unk_D1 != 0) {
                w->palette = LoadObjPalette(gUnk_09849BD8, 0x20);
                func_080122AC(w->unk_38, 4, 8, 8);
            } else {
                w->palette = LoadObjPalette(gUnk_09849CF8, 0x20);
                w->tiles = AllocObjTiles(w->unk_D2, gUnk_09753154);
                func_080122AC(w->unk_38, 4, 8, 8);
            }
        }
        func_08012324(w->unk_38, w->unk_28, w->unk_2C, w->unk_30);
        pr = w->unk_24 != 0 ? 0x801 : 0x800;
        d = w->unk_D0;

        if (d != 0) {
            z = -0x1008 - (w->unk_80 >> 8) * 4;

            if (w->unk_2C >= gUnk_0203C420.unk_00.unk_04) {
                z -= 2;
            } else {
                z += 2;
            }

            if (w->unk_84 <= w->unk_48) {
                w->unk_CC = 0;
                w->unk_C8 = 0;
            } else {
                w->unk_CC = w->unk_78;
                w->unk_C8 = z + 1;
            }
        } else {
            z = -0x1004 - (w->unk_2C >> 8) * 4;
            w->unk_CC = d;

            if (d != w->unk_34) {
                w->unk_C8 = 0;
            } else {
                w->unk_C8 = z + 1;
            }
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, z);
        TaskPoolDraw(&w->unk_94);
    }
}

void task_poo_tiggerroo_3(PooTiggerWork* w) {
    if (w->tiles != 0) {
        ReleaseObjTiles(w->tiles);
    }

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_38);
    }
    TaskPoolDestroy(&w->unk_94);
}

void task_poo_tiggerroo_0(PooTiggerWork* w) {
    PooTiggerArgs args;

    w->unk_C0 = 2;
    w->unk_B8 = 0x2D;
    w->unk_D1 = 0;
    w->palette = 0;
    w->tiles = 0;
    w->unk_D2 = func_08003524(gUnk_09EF5EF8, 18);
    AnimInit(w->anim, gUnk_09EF5FA0, gUnk_09EF5EF8);
    w->unk_26 = 4;
    func_080CE710(w, 0);
    func_080CE8B4(w);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_94, 1);
    args.unk_00 = &w->unk_28;
    args.unk_04 = &w->unk_C8;
    TaskCreate(&w->unk_94, &gTaskDescPooShadowdodai, &args);
    func_08012324(w->unk_38, w->unk_28, w->unk_2C, w->unk_30);
}

void task_poo_roo_0(PooRooWork* w, PooPos* p) {
    gStockMesDispWork = w;
    w->unk_38 = p;
    w->tiles = AllocObjTiles(func_08003524(gUnk_09EF5EF8, 8), gUnk_09753154);
    w->palette = LoadObjPalette(gUnk_09849CF8, 0x20);
    AnimInit(w->anim, gUnk_09EF5FA0, gUnk_09EF5EF8);

    if (func_080D2D50(5) != 0) {
        w->unk_28.unk_00 = 0x95F00;
        w->unk_28.unk_04 = 0x4EE00;
        w->unk_28.unk_08 = 0;
        AnimStart(w->anim, 0, 0);
        w->unk_24 = 0;
        w->unk_B4 = 3;
    } else {
        w->unk_28 = *w->unk_38;
        AnimStart(w->anim, 4, 0);
        w->unk_24 = 0;
        w->unk_B4 = 0;
    }
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_98, 1);
    TaskCreate(&w->unk_98, &gTaskDescPooShadow, &w->unk_28);
    func_080122AC(w->unk_3C, 10, 4, 32);
    func_08012324(w->unk_3C, w->unk_28.unk_00, w->unk_28.unk_04, w->unk_28.unk_08);

    if (func_080D2D50(5) != 0) {
        w->unk_B8 = func_080D2E28(w->unk_3C, 58);
    }
}

u8 task_poo_roo_1(PooRooWork* w) {
    s32 t;

    switch (w->unk_B4) {
    case 0:
        if (AnimIsFinished(w->anim) != 0) {
            AnimStart(w->anim, 5, 0);
            w->unk_B4 = 1;
            w->unk_28 = *w->unk_38;
            w->unk_28.unk_00 -= 0x600;
            w->unk_28.unk_08 += 0x1F00;
        }
        break;
    case 1:
        w->unk_B0 = w->unk_28.unk_08;
        w->unk_28 = *w->unk_38;
        w->unk_28.unk_00 -= 0x600;
        t = w->unk_28.unk_08 + 0x1F00;
        w->unk_28.unk_08 = t;

        if (w->unk_B0 - t < 0 && t >= -0x2100) {
            AnimStart(w->anim, 6, 0);
            w->unk_B4 = 2;
            w->unk_AC = 0;
        }
        break;
    case 2:
        w->unk_28.unk_08 += w->unk_AC;
        w->unk_AC += 7;

        if (w->unk_28.unk_08 >= 0) {
            w->unk_28.unk_08 = 0;
        } else {
            w->unk_28.unk_00 -= 0x40;
            w->unk_28.unk_04 += 0x40;
        }

        if (w->unk_38->unk_08 >= 0) {
#ifdef VERSION_EU
            func_080C7B84(0x89);
#else
            func_080C7B84(0x8B);
#endif
            func_080D2D3C(5);
            func_0800FDD0(80);
        }
        break;
    case 3:
        if (func_08012660(w->unk_3C, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    func_08012324(w->unk_3C, w->unk_28.unk_00, w->unk_28.unk_04, w->unk_28.unk_08);
    TaskPoolUpdate(&w->unk_98);
    return 1;
}

void task_poo_roo_2(PooRooWork* w) {
    s16 x;
    s16 y;
    s32 pr;
    s32 t;

    x = (w->unk_28.unk_00 >> 8) - gUnk_0203C40C;
    t = w->unk_28.unk_04 >> 8;
    y = t + (w->unk_28.unk_08 >> 8) - gUnk_0203C3F8;
    pr = w->unk_24 != 0 ? 0x801 : 0x800;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, -0x1006 - t * 4);

    if (w->unk_B4 != 0) {
        TaskPoolDraw(&w->unk_98);
    }
}

void task_poo_roo_3(PooRooWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    func_08012304(w->unk_3C);
    TaskPoolDestroy(&w->unk_98);
}

u8 func_080CF114(void) {
    return func_08005AC4((u8*)gStockMesDispWork + 0x0C);
}

u8 func_080CF12C(void) {
    return AnimIsFinished((u8*)gStockMesDispWork + 0x0C);
}

void task_poo_roo_footmark_0(PooFootmarkWork* w) {
    w->unk_0C = 0x4A700;
    w->unk_10 = 0x28E00;
    w->unk_14 = 0;
    w->tiles = LoadObjTiles(gUnk_09755A34, 0x500);
    w->palette = 0;

    if (func_080D2D50(5) == 0) {
        w->unk_08 = gUnk_097559F4;
    } else {
        w->unk_08 = gUnk_09755A04;
    }
}

u8 task_poo_roo_footmark_1(void* w) {
    return 1;
}

void task_poo_roo_footmark_2(PooFootmarkWork* w) {
    PooNode* n;
    s16 x;
    s16 y;

    x = (w->unk_0C >> 8) - gUnk_0203C40C;
    y = (w->unk_10 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 0, 48, 0, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            func_080CCBD4(&w->unk_1C);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D18, 0x20);
            n = &w->unk_1C;
            func_080CCB90(n, 0x240, &w->unk_0C);
            if (func_080D2D50(5) != 0) {
                func_080CCB84(&n->unk_00, 0);
            }
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, 0xFFF1);
    }
}

void task_poo_roo_footmark_3(PooFootmarkWork* w) {
    ReleaseObjTiles(w->tiles);

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        func_080CCBD4(&w->unk_1C);
    }
}

void task_poo_leaf_0(PooLeafWork* w, PooLeafArgs* a) {
    w->unk_24 = a->unk_00;
    w->unk_28 = a->unk_04;
    w->unk_2C = 0;
    w->unk_94 = a->unk_10;
    w->unk_92 = func_08003524(gUnk_09EF610C, 5);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF612C, gUnk_09EF610C);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    func_08012324(w->unk_34, w->unk_24 + 0x1C00, w->unk_28 + 0x1000, w->unk_2C);
    w->unk_90 = 0;
}

u8 task_poo_leaf_1(PooLeafWork* w) {
    if (w->palette != 0 && (w->unk_62 & 2) != 0 && w->unk_90 == 0) {
        w->unk_90 = 1;
        AnimReset(w->anim);
        m4aSongNumStart(0xE0);

        if (func_080D2C1C(w->unk_94) == 0) {
            if (func_080C7BF8(2, 3, w->unk_24 + 0x1C00, w->unk_28 + 0x2000, w->unk_2C) != 0) {
                func_080D2BF8(w->unk_94);
            }
        }
    }
    return 1;
}

void task_poo_leaf_2(PooLeafWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 0, 32, 0, 56) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_34);
            w->unk_90 = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_92, gUnk_0975C3E2);
            w->palette = LoadObjPalette(gUnk_09849DF8, 0x20);
            func_080122AC(w->unk_34, 6, 28, 0);
        }
        p = &w->unk_90;
        if (*p != 0) {
            w->gfx = AnimUpdate(w->anim);

            if (AnimIsFinished(w->anim) == 0) {
                DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, 0xFFF1);
            } else if ((w->unk_62 & 2) == 0) {
                *p = 0;
            }
        }
    }
}

void task_poo_leaf_3(PooLeafWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_34);
    }
}

void task_poo_tanpopo_0(PooTanpopoWork* w, PooLeafArgs* a) {
    w->unk_44 = a->unk_00;
    w->unk_48 = a->unk_04;
    w->unk_4C = 0;
    w->unk_B6 = a->unk_10;
    w->unk_B2 = func_08003524(gUnk_09EF6130, 2);
    w->unk_B4 = func_08003524(gUnk_09EF613C, 6);
    w->palette = 0;
    AnimInit(w->unk_0C, gUnk_09EF6138, gUnk_09EF6130);
    AnimStart(w->unk_0C, 0, 0);
    w->unk_08 = AnimGetGfx(w->unk_0C);
    AnimInit(w->unk_2C, gUnk_09EF6154, gUnk_09EF613C);
    AnimStart(w->unk_2C, 0, 0);
    w->unk_28 = AnimGetGfx(w->unk_2C);
    func_08012324(w->unk_54, w->unk_44 + 0x1800, w->unk_48 + 0x1000, w->unk_4C);
    w->unk_B0 = 0;
}

u8 task_poo_tanpopo_1(PooTanpopoWork* w) {
    if (w->palette != 0 && (w->unk_82 & 2) != 0 && w->unk_B0 == 0) {
        w->unk_B0 = 1;
        AnimReset(w->unk_0C);
        AnimReset(w->unk_2C);

        if (func_080D2C1C(w->unk_B6) == 0) {
            if (func_080C7BF8(2, 1, w->unk_44 + 0x1800, w->unk_48 + 0x2000, w->unk_4C) != 0) {
                func_080D2BF8(w->unk_B6);
            }
        }
    }
    return 1;
}

void task_poo_tanpopo_2(PooTanpopoWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = (w->unk_44 >> 8) - gUnk_0203C40C;
    y = (w->unk_48 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 0, 32, 0, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->unk_00);
            ReleaseObjTiles(w->unk_24);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_54);
            w->unk_B0 = 0;
        }
    } else {
        if (w->palette == 0) {
            w->unk_00 = LoadObjTiles(gUnk_0975E40E, 0x800);
            w->unk_24 = LoadObjTiles(gUnk_0975EC8E, 0x1800);
            w->palette = LoadObjPalette(gUnk_09849E18, 0x20);
            func_080122AC(w->unk_54, 6, 24, 0);
        }
        p = &w->unk_B0;
        if (*p != 0) {
            w->unk_08 = AnimUpdate(w->unk_0C);
            w->unk_28 = AnimUpdate(w->unk_2C);
            DrawSprite(x, y, w->unk_08, w->unk_00, w->palette, 0, 0x800, 0xFFF1);

            if (AnimIsFinished(w->unk_2C) == 0) {
                DrawSprite(x, y, w->unk_28, w->unk_24, w->palette, 0, 0x800, 100);
            } else if ((w->unk_82 & 2) == 0) {
                *p = 0;
            }
        }
    }
}

void task_poo_tanpopo_3(PooTanpopoWork* w) {
    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ReleaseObjTiles(w->unk_00);
        ReleaseObjTiles(w->unk_24);
        func_08012304(w->unk_54);
    }
}

void task_poo_ti_board_0(PooBoardWork* w, PooPos* p) {
    w->unk_0C = p->unk_00;
    w->unk_10 = p->unk_04;
    w->unk_14 = 0;
    w->tiles = LoadObjTiles(gUnk_097565FC, 0x200);
    w->palette = 0;
    w->unk_08 = gUnk_097565E8;
    func_08012324(w->unk_1C, w->unk_0C, w->unk_10, w->unk_14);
}

u8 task_poo_ti_board_1(PooBoardWork* w) {
    if (w->palette != 0) {
        if (func_08012660(w->unk_1C, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_ti_board_2(PooBoardWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_0C >> 8) - gUnk_0203C40C;
    y = (w->unk_10 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 16, 1, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_1C);
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D58, 0x20);
            func_080122AC(w->unk_1C, 7, 8, 16);
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_10 >> 8) * 4);
    }
}

void task_poo_ti_board_3(PooBoardWork* w) {
    ReleaseObjTiles(w->tiles);

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_1C);
    }
}

void task_poo_eeyoretail_0(PooEeyoreTailWork* w) {
    w->unk_0C = 0x7CD00;
    w->unk_10 = 0x49E00;
    w->unk_14 = -0x2000;
    w->unk_18 = 0;
    w->unk_1C = func_08003524(gUnk_09EF5D68, 0x10);
    w->palette = 0;
    w->unk_08 = gUnk_09744842;
    TaskPoolInit(&w->unk_24, 1);
    func_080CC178(&w->unk_24, &w->unk_0C, 0x66);
    gUnk_02034E18 = 0x1E;
    w->unk_20 = -w->unk_14;
}

u8 task_poo_eeyoretail_1(PooEeyoreTailWork* w) {
    if (func_080C9D84() != 0) {
        if (gUnk_02034E18 != 0) {
            ApproachValue(&w->unk_0C, 0x7FD00, gUnk_02034E18);
            ApproachValue(&w->unk_10, 0x49300, gUnk_02034E18);
            ApproachValue(&w->unk_20, 0, gUnk_02034E18);
            w->unk_14 = -w->unk_20;
            gUnk_02034E18--;
            func_080C9FA8(w->unk_0C, w->unk_10 + w->unk_14);
        }
        TaskPoolUpdate(&w->unk_24);
    }
    return 1;
}

void task_poo_eeyoretail_2(PooEeyoreTailWork* w) {
    s16 x;
    s16 y;
    s32 pr;
    s32 z;

    x = ((s32)w->unk_0C >> 8) - gUnk_0203C40C;
    y = ((s32)w->unk_10 >> 8) + (w->unk_14 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 8, 8, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_1C, gUnk_097448BA);
            w->palette = LoadObjPalette(gUnk_09849C58, 0x20);
        }
        if (func_080CFA70() != 0) {
            pr = 0x800;
            z = 0xFFEF;
        } else {
            pr = 0x400;
            z = 10;
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, pr, z);
        if (func_080C9D84() != 0) {
            TaskPoolDraw(&w->unk_24);
        }
    }
}

void task_poo_eeyoretail_3(PooEeyoreTailWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
    TaskPoolDestroy(&w->unk_24);
}

u8 func_080CFA70(void) {
    if (gUnk_02034E18 == 0) {
        return 1;
    }
    return 0;
}

void task_poo_honeycomb_0(PooHoneycombWork* w) {
    w->unk_24 = 0x8DE00;
    w->unk_28 = 0x46600;
    w->unk_2C = -0xA00;
    w->unk_30 = 0;
    w->unk_34 = func_08003524(gUnk_09EF5FF0, 1);
    w->palette = 0;
    w->unk_08 = gUnk_097567FC;
    func_08012324(w->unk_38, w->unk_24, w->unk_28, 0);
    w->unk_9C = 0;
    gUnk_02034E1C = 0;
    w->unk_98 = 0;
    w->unk_96 = 0;
}

u8 task_poo_honeycomb_1(PooHoneycombWork* w) {
    u8 c;

    if (w->unk_9C != 0) {
        switch (gUnk_02034E1C) {
        case 2:
            break;
        case 0:
            if (func_08012660(w->unk_38, 9) != 0) {
                c = func_080D2D50(2);
                if (c == 0) {
                    gUnk_0203C3F0 = 9;

                    if (func_080C9E70() != 0) {
                        gUnk_02034E1C = 1;
                        w->unk_94 = c;
                    }
                } else {
                    gUnk_0203C3F0 = 10;
                }
            }
            break;
        case 1:
            w->unk_98 = gSineTable[(u8)w->unk_96];
            w->unk_96 += 16;
            w->unk_94++;
            if (w->unk_94 > 60) {
                w->unk_98 = 0;
                gUnk_02034E1C = 2;
                m4aSongNumStart(0x173);
            }
            break;
        }
    }
    return 1;
}

void task_poo_honeycomb_2(PooHoneycombWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = ((w->unk_24 + w->unk_98) >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 16, 16, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ReleaseObjTiles(w->tiles);
            w->palette = 0;
        }
        p = &w->unk_9C;
        if (*p != 0) {
            func_08012304(w->unk_38);
            *p = 0;
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D78, 0x20);
            w->tiles = AllocObjTiles(w->unk_34, gUnk_09756810);
        }
        p = &w->unk_9C;
        if (*p == 0) {
            func_080122AC(w->unk_38, 6, 64, 0);
            *p = 1;
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0xC00, 0xFFF0);
    }
}

void task_poo_honeycomb_3(PooHoneycombWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_9C != 0) {
        func_08012304(w->unk_38);
    }
}

u8 func_080CFCC0(void) {
    if (gUnk_02034E1C == 2) {
        return 1;
    }
    return 0;
}

void task_poo_vegetable_0(PooVegetableWork* w) {
    w->unk_24 = 0x1AC00;
    w->unk_28 = 0x18000;
    w->unk_2C = 0;
    w->unk_30 = 0;
    w->unk_34 = func_08003524(gUnk_09EF602C, 1);
    w->palette = 0;
    w->unk_08 = gUnk_09756C50;
    func_08012324(w->unk_38, w->unk_24, w->unk_28, w->unk_2C);
}

u8 task_poo_vegetable_1(PooVegetableWork* w) {
    if (w->palette != 0) {
        if (func_08012660(w->unk_38, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_vegetable_2(PooVegetableWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 32, 40, 48, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            func_08012304(w->unk_38);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_34, gUnk_09756E28);
            w->palette = LoadObjPalette(gUnk_09849DB8, 0x20);
            func_080122AC(w->unk_38, 7, 0x26, 12);
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_28 >> 8) * 4);
    }
}

void task_poo_vegetable_3(PooVegetableWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_38);
    }
}

s32 func_080CFE34(PooPos* p) {
    s32 k;
    s32 x;
    s32 y;

    k = 0x2500;

    if (func_080D2D50(6) != 0) {
        k = 0x2100;
    }
    x = p->unk_00 - gUnk_02034E20->unk_1C.unk_00;
    y = p->unk_04 - gUnk_02034E20->unk_1C.unk_04;
    if (y + x < -0x1A00) {
        return 0;
    }

    if (y - x / 2 > k - 0xB80) {
        return 0;
    }

    if (y + x > k + 0x1700) {
        return 0;
    }

    if (y - x / 2 < -0x1180) {
        return 0;
    }
    return 1;
}

s32 func_080CFEA0(PooPos* p) {
    s32 k;
    s32 x;
    s32 y;

    k = 0x2500;

    if (func_080D2D50(6) != 0) {
        k = 0x2100;
    }
    x = p->unk_00 - gUnk_02034E20->unk_1C.unk_00;
    y = p->unk_04 - gUnk_02034E20->unk_1C.unk_04;
    if (y + x < -0x1A00) {
        return 0;
    }

    if (y - x / 2 > k - 0xB80) {
        return 0;
    }

    if (y + x > 0x3100) {
        return 0;
    }

    if (y - x / 2 < -0x1180) {
        return 0;
    }
    return 1;
}

u8 func_080CFF0C(void) {
    if (gUnk_0203C420.unk_00.unk_08 < 0) {
        return 0;
    }
    return func_080CFE34(&gUnk_0203C420.unk_00);
}

u8 func_080CFF30(void) {
    if (gUnk_0203C420.unk_00.unk_08 < -0x2000) {
        return 0;
    }
    return func_080CFE34(&gUnk_0203C420.unk_00);
}

void func_080CFF58(u32* a, u32* b, u16 c) {
    s32 d;
    s32 e;

    d = *a - gUnk_02034E20->unk_1C.unk_00;
    if (d < -0x600) {
        d = -0x600;
    } else if (d > 0xA00) {
        d = 0xA00;
    }
    e = d / 2 - 0x300;
    ApproachValue(a, d + gUnk_02034E20->unk_1C.unk_00, c);
    ApproachValue(b, e + gUnk_02034E20->unk_1C.unk_04, c);
}

void func_080CFFC0(s32* a, s32* b) {
    s32 t;
    s32 y;

    t = *a;
    y = *b;
    t -= 0x4600;
    *a = (t - y * 2) / 5;
    *b = -0x2300 - *a * 2;
}

void func_080CFFF0(s32* a, s32* b) {
    s32 t;
    s32 y;

    t = *a;
    y = *b;
    t += 0x5000;
    *a = (t - y * 2) / 5;
    *b = 0x2800 - *a * 2;
}

void func_080D001C(s32* a, s32* b) {
    s32 t;
    s32 y;

    t = *a;
    y = *b;
    *a = (y * 2 + t * 4 + 0xF00) / 5;
    *b = *a / 2 - 0x800;
}

void func_080D0050(s32* a, s32* b) {
    s32 x;
    s32 y;

    x = *a;
    y = *b;
    *a = (y * 2 + x * 4 - 1280) / 5;
    *b = *a / 2 + 768;
}

void func_080D0084(u32* a, u32* b, u16 c) {
    s32 x;
    s32 y;

    x = *a - gUnk_02034E20->unk_1C.unk_00;
    y = *b - gUnk_02034E20->unk_1C.unk_04;

    if (x < -0xB00 && y < -0xD00) {
        func_080CFFC0(&x, &y);

        if (y < -0xD00) {
            func_080D001C(&x, &y);
        } else if (y > -0xD00) {
            func_080D0050(&x, &y);
        }
    } else if (x > 0xF00 && y > 0x600) {
        func_080CFFF0(&x, &y);

        if (y < 0x600) {
            func_080D001C(&x, &y);
        } else if (y > 0xA00) {
            func_080D0050(&x, &y);
        }
    } else if (-x / 2 + y > 0) {
        func_080D0050(&x, &y);

        if (x < -0x1700) {
            func_080CFFC0(&x, &y);
        } else if (x > 0xF00) {
            func_080CFFF0(&x, &y);
        }
    } else {
        func_080D001C(&x, &y);

        if (x < -0xB00) {
            func_080CFFC0(&x, &y);
        } else if (x > 0x1800) {
            func_080CFFF0(&x, &y);
        }
    }
    ApproachValue(a, x + gUnk_02034E20->unk_1C.unk_00, c);
    ApproachValue(b, y + gUnk_02034E20->unk_1C.unk_04, c);
}

s32 func_080D01BC(s32 x, s32 y) {
    s32 dx;
    s32 dy;

    dx = x - gUnk_02034E20->unk_1C.unk_00;
    dy = y - gUnk_02034E20->unk_1C.unk_04;
    if (dx < -0xB00 && dy < -0xD00) {
        return 0x53;
    }

    if (dx > 0xF00 && dy > 0x600) {
        return 0xD3;
    }

    if (-dx / 2 + dy > 0) {
        return 0x2D;
    }
    return 0xAD;
}

s32 func_080D0210(s32 a, s32 b) {
    s32 x;
    s32 y;

    x = a - gUnk_02034E20->unk_1C.unk_00;
    y = b - gUnk_02034E20->unk_1C.unk_04;
    if (x < -0x3D00 || x > 0x4300 || y < -0x1F00 || y > 0x3800) {
        return 0;
    }

    if (x < -0x1100 && y <= 0x2FF) {
        return 0x53;
    }

    if (x > 0x1700 && y > 0x500) {
        return 0xD3;
    }

    if (-x / 2 + y > 0) {
        return 0x2D;
    }
    return 0xAD;
}

void task_poo_wagon_0(PooCamera* w) {
    gUnk_02034E20 = w;
    w->unk_1C.unk_00 = 0x2AE00;
    w->unk_1C.unk_04 = 0x17700;
    w->unk_1C.unk_08 = 0;
    w->unk_1C.unk_0C = 0;
    w->unk_2C = w->unk_1C;

    if (func_080D2D50(6) != 0) {
        w->unk_1C.unk_04 += 0xC00;
    }
    w->unk_04 = 0;
    w->unk_08 = gUnk_09758C04;
    w->unk_10 = gUnk_09758B70;
    w->unk_18 = gUnk_09758C20;
    w->unk_3C = 0;
    w->unk_3E = 0;
    w->unk_40 = 0;
}

u8 task_poo_wagon_1(PooCamera* w) {
    u8 c;
    s32 t;
    s32 d;

    if (func_080CFF0C() != 0) {
        if (w->unk_1C.unk_04 == w->unk_2C.unk_04) {
            w->unk_1C.unk_04 += 0x100;
            gUnk_0203C420.unk_00.unk_04 += 0x100;

            if (w->unk_3C != 0) {
                gUnk_0203C3EC->unk_04 += 0x100;
            }
        }
    } else if (func_080D2D50(6) == 0) {
        if (w->unk_1C.unk_04 != w->unk_2C.unk_04) {
            w->unk_1C.unk_04 -= 0x100;
            gUnk_0203C420.unk_00.unk_04 -= 0x100;

            if (w->unk_3C != 0) {
                gUnk_0203C3EC->unk_04 -= 0x100;
            }
        }
    }

    c = func_080CFEA0(gUnk_0203C3EC);

    if (c != 0) {
        if (w->unk_3C == 0) {
            gUnk_0203C3DC = w->unk_1C.unk_00;
            gUnk_0203C3E8 = w->unk_1C.unk_04;
            gUnk_0203C3F0 = 11;
            w->unk_3C = 1;
        }
    } else {
        w->unk_3C = 0;
    }

    if (func_080CFF0C() != 0 && func_080C9D98() != 0 && func_080D2D50(6) == 0) {
        w->unk_3E++;

        if (w->unk_3E > 100) {
            if (w->unk_1C.unk_04 != w->unk_2C.unk_04 + 0xC00) {
                t = w->unk_1C.unk_04 - 0xC00;
                d = w->unk_2C.unk_04 - t;
                w->unk_1C.unk_04 += d;
                gUnk_0203C420.unk_00.unk_04 += d;
                gUnk_0203C3EC->unk_04 += d;
                func_080D2D3C(6);
                m4aSongNumStart(0x90);
                w->unk_3E = 0;
            }
        }
    } else {
        w->unk_3E = 0;
    }
    return 1;
}

void task_poo_wagon_2(PooCamera* w) {
    s32 t;
    s16 x;
    s16 y;
    u16 n;
    u16 p;
    s32 d;
    s32 k;

    d = 0;

    if (w->unk_3E != 0) {
        t = gSineTable[(u8)w->unk_40];
        w->unk_40 += 16;
    } else {
        t = 0;
    }
    x = ((w->unk_1C.unk_00 + t) >> 8) - gUnk_0203C40C;
    y = (w->unk_1C.unk_04 >> 8) + (w->unk_1C.unk_08 >> 8) - gUnk_0203C3F8;

    if (func_080035CC(x, y, 32, 40, 48, 48) != 0) {
        if (w->unk_04 != 0) {
            ReleaseObjTiles(w->unk_00);
            ReleaseObjTiles(w->unk_0C);
            ReleaseObjTiles(w->unk_14);
            ReleaseObjPalette(w->unk_04);
            w->unk_04 = 0;
        }
        return;
    }

    if (w->unk_04 == 0) {
        w->unk_00 = AllocObjTiles(0x560, gUnk_09758C94);
        w->unk_0C = AllocObjTiles(0x4C0, gUnk_09758C94);
        w->unk_14 = AllocObjTiles(160, gUnk_09758C94);
        w->unk_04 = LoadObjPalette(gUnk_09849DD8, 32);
    }
    n = func_080CBB7C();

    if (func_080CFF30() != 0) {
        gUnk_02034E26 = n + 3;
        gUnk_02034E24 = n - 1;

        if (func_080C9DAC() != 0) {
            if (gUnk_0203C420.unk_00.unk_04 >= gUnk_0203C3EC->unk_04) {
                gUnk_02034E26 += 6;
            } else {
                gUnk_02034E24 += 0xFFFC;
            }
        }
    } else {
        d = (u8)func_080D0210(gUnk_0203C420.unk_00.unk_00, gUnk_0203C420.unk_00.unk_04);

        if (d == 0) {
            k = w->unk_1C.unk_04 + 0x300;
            gUnk_02034E26 = -0x1004 - (k >> 8) * 4;
            gUnk_02034E24 = -0x1009 - (k >> 8) * 4;
        } else if (d == 83 || d == 173) {
            gUnk_02034E26 = n - 3;
            gUnk_02034E24 = n - 8;
        } else {
            gUnk_02034E24 = n + 4;
            gUnk_02034E26 = n + 9;
        }
    }
    DrawSprite(x, y, w->unk_08, w->unk_00, w->unk_04, 0, 0x800, gUnk_02034E26);
    DrawSprite(x, y, w->unk_10, w->unk_0C, w->unk_04, 0, 0x800, gUnk_02034E24);
    p = -0x1002 - ((w->unk_1C.unk_04 - 0xE00) >> 8) * 4;

    if (func_080CFF30() == 0 && n > p && (d == 83 || d == 173)) {
        p = n - 1;
    }
    DrawSprite(x, y, w->unk_18, w->unk_14, w->unk_04, 0, 0x800, p);
}

void task_poo_wagon_3(PooWagonWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjTiles(w->unk_0C);
        ReleaseObjTiles(w->unk_14);
        ReleaseObjPalette(w->palette);
    }
}

u16 func_080D06BC(void) {
    return gUnk_02034E24;
}

u16 func_080D06C8(void) {
    return gUnk_02034E26;
}

void task_poo_wagonwheel_0(PooWheelWork* w) {
    s16 x;
    s16 y;

    if (func_080D2D50(6) == 0) {
        w->unk_24 = 0x2A800;
        w->unk_28 = 0x18D00;
        w->unk_36 = 2;
        w->gfx = gUnk_09758B9C;
    } else {
        func_080D2CF4(&x, &y);
        w->unk_24 = x << 8;
        w->unk_28 = y << 8;
        w->unk_36 = 4;
        w->gfx = gUnk_09758BF4;
    }
    w->unk_3C = w->unk_24;
    w->unk_2C = 0;
    w->unk_30 = 0;
    w->unk_34 = 0x180;
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF60AC, gUnk_09EF6078);
    AnimStart(w->anim, w->unk_36, 1);
    w->unk_38 = 0;
    w->unk_40 = 0;
}

u8 task_poo_wagonwheel_1(PooWheelWork* w) {
    if (w->unk_36 == 2 && func_080D2D50(6) != 0) {
        w->unk_36 = 3;
        AnimStart(w->anim, 3, 1);
    }

    if (w->unk_36 == 3) {
        w->gfx = AnimUpdate(w->anim);

        if (w->unk_38 <= 0x4FF) {
            w->unk_38 += 6;
        }
        w->unk_28 += w->unk_38;
        w->unk_24 += w->unk_38;
        if (w->unk_24 > w->unk_3C + 0x4800) {
            w->unk_24 = w->unk_3C + 0x4800;
        }
    }

    if (w->unk_40 != 0 && w->palette == 0) {
        return 0;
    }
    return 1;
}

void task_poo_wagonwheel_2(PooWheelWork* w) {
    u16* p;
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 32, 0, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;

            if (w->unk_36 == 3) {
                w->unk_36 = 4;
                w->gfx = gUnk_09758BF4;
            }
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_34, gUnk_09758C94);
            w->palette = LoadObjPalette(gUnk_09849DD8, 0x20);
        }

        if (func_080D2D50(6) == 0) {
            p = &gUnk_02034E28;
            *p = func_080D06BC() - 1;
        } else {
            gUnk_02034E28 = -0x1004 - (w->unk_28 >> 8) * 4;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, gUnk_02034E28);
    }
}

void task_poo_wagonwheel_3(PooWheelWork* w) {
    if (func_080D2D50(6) != 0) {
        func_080D2CE0(w->unk_24 >> 8, w->unk_28 >> 8);
    }

    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
}

void task_poo_spark_0(PooSparkWork* w, PooPos* p) {
    w->unk_00 = *p;
    w->tiles = AllocObjTiles(0x200, gUnk_098A4B68);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->anim, gUnk_09EF8CC0, gUnk_09EF8CA0);
    AnimStart(w->anim, 0, 1);
}

u8 task_poo_spark_1(PooSparkWork* w) {
    AnimUpdate(w->anim);

    if (AnimIsFinished(w->anim) != 0) {
        return 0;
    }
    return 1;
}

void task_poo_spark_2(PooSparkWork* w) {
    u16 x;
    u16 y;

    x = (w->unk_00.unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_00.unk_04 >> 8) + (w->unk_00.unk_08 >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, AnimGetGfx(w->anim), w->tiles, w->palette, 0, 0x400, 0x50);
}

void task_poo_spark_3(PooSparkWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_bee_0(PooBeeWork* w) {
    void* a;
    void* b;
    s32 i;

    w->unk_A4 = 0x8DE00;
    w->unk_A8 = 0x46600;
    w->unk_AC = -0xA00;
    w->unk_B0 = 0;
    i = 0;
    a = gUnk_09EF6024;
    b = gUnk_09EF5FF8;

    for (; i < 4; i++) {
        w->unk_24[i].unk_00 = -0x500;
        w->unk_24[i].unk_04 = 0x500;
        w->unk_24[i].unk_10 = gUnk_096FD730[i].unk_00;
        w->unk_24[i].unk_14 = gUnk_096FD730[i].unk_04;
    }
    AnimInit(w->anim, a, b);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    w->palette = 0;
    gUnk_02034E2C = 0;
    w->unk_C6 = 8;
    w->unk_C8 = 1;
}

u8 task_poo_bee_1(PooBeeWork* w) {
    s32 i;

    if (func_080CFCC0() != 0) {
        if (w->unk_C8 != 0) {
            w->unk_C8 = 0;

            for (i = 0; i < 4; i++) {
                w->unk_24[i].unk_00 = w->unk_A4 - 0x500;
                w->unk_24[i].unk_04 = w->unk_A8 + 0x500;
                w->unk_24[i].unk_08 = w->unk_AC;
                w->unk_24[i].unk_10 = 0x2000 + gUnk_0203C3EC->unk_00 + gUnk_096FD730[i].unk_00;
                w->unk_24[i].unk_14 = -0x2000 + gUnk_0203C3EC->unk_04 + gUnk_096FD730[i].unk_04;
            }
        }

        if (gUnk_02034E2C <= 3) {
            ApproachValue(&w->unk_24[gUnk_02034E2C].unk_00, w->unk_24[gUnk_02034E2C].unk_10, w->unk_C6);
            ApproachValue(&w->unk_24[gUnk_02034E2C].unk_04, w->unk_24[gUnk_02034E2C].unk_14, w->unk_C6);
            w->unk_C6--;

            if (w->unk_C6 == 0) {
                w->unk_C6 = 8;
                gUnk_02034E2C++;

                if (gUnk_02034E2C > 3) {
                    w->unk_A4 = gUnk_0203C3EC->unk_00 + 0x2000;
                    w->unk_A8 = gUnk_0203C3EC->unk_04 - 0x2000;
                    w->unk_B4 = w->unk_B8 = 0;
                }
            }
            func_080C9FA8(w->unk_A4, w->unk_A8 + w->unk_AC);
        } else {
            w->unk_B4 = w->unk_A4 - (gUnk_0203C3EC->unk_00 + 0x2000);
            w->unk_B8 = w->unk_A8 - (gUnk_0203C3EC->unk_04 - 0x2000);
            w->unk_A4 -= w->unk_B4;
            w->unk_A8 -= w->unk_B8;

            for (i = 0; i < 4; i++) {
                w->unk_24[i].unk_00 -= w->unk_B4;
                w->unk_24[i].unk_04 -= w->unk_B8;
            }

            if (func_080C9D84() == 0) {
                func_080C9FA8(w->unk_A4, w->unk_A8 + w->unk_AC);
            }
        }
        w->gfx = AnimUpdate(w->anim);
    }
    return 1;
}

void task_poo_bee_2(PooBeeWork* w) {
    s32 x;
    s32 y;
    s32 u;
    s32 v;
    s32 i;

    if (func_080CFCC0() == 0) {
        return;
    }
    x = (w->unk_A4 >> 8) - gUnk_0203C40C;
    y = (w->unk_A8 >> 8) + (w->unk_AC >> 8) - gUnk_0203C3F8;

    if (func_080035CC(x, y, 19, 17, 46, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ReleaseObjTiles(w->tiles);
            w->palette = 0;
        }
        return;
    }

    if (w->palette == 0) {
        w->palette = LoadObjPalette(gUnk_09849D98, 32);
        w->tiles = LoadObjTiles(gUnk_09756ACE, 0x180);
    }

    for (i = 0; i < gUnk_02034E2C + 1 && i <= 3; i++) {
        u = (w->unk_24[i].unk_00 >> 8) - gUnk_0203C40C;
        v = (w->unk_24[i].unk_04 >> 8) + (w->unk_24[i].unk_08 >> 8) - gUnk_0203C3F8;
        DrawSprite(u, v, w->gfx, w->tiles, w->palette, 0, 0x800, i - ((w->unk_A8 >> 8) * 4 + 0x1003));
    }
}

void task_poo_bee_3(PooObjWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
}

u8 func_080D0E3C(void) {
    if (gUnk_02034E2C <= 3) {
        return 0;
    }
    return 1;
}

void task_poo_beeAfterEvent_0(PooBeeAfterEventWork* w) {
    gPooBeeAfterEventWork = w;
    w->unk_44 = 0x8DE00;
    w->unk_48 = 0x46600;
    w->unk_4C = -0xA00;
    w->unk_50 = 0;
    AnimInit(w->unk_14, gUnk_09EF6024, gUnk_09EF5FF8);
    AnimStart(w->unk_14, 1, 1);
    w->unk_0C = AnimGetGfx(w->unk_14);
    AnimInit(w->unk_2C, gUnk_09EF6024, gUnk_09EF5FF8);
    AnimStart(w->unk_2C, 0, 1);
    w->unk_10 = AnimGetGfx(w->unk_2C);
    w->palette = 0;
}

u8 task_poo_beeAfterEvent_1(PooBeeAfterEventWork* w) {
    w->unk_0C = AnimUpdate(w->unk_14);
    w->unk_10 = AnimUpdate(w->unk_2C);
    return 1;
}

void task_poo_beeAfterEvent_2(PooBeeAfterEventWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_44 >> 8) - gUnk_0203C40C;
    y = (w->unk_48 >> 8) + (w->unk_4C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 19, 17, 46, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ReleaseObjTiles(w->unk_00);
            ReleaseObjTiles(w->unk_04);
            w->palette = 0;

            if (func_080C7CBC() == 0) {
                m4aSongNumStop(0x182);
            }
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D98, 0x20);
            w->unk_00 = LoadObjTiles(gUnk_09756ACE, 0x180);
            w->unk_04 = LoadObjTiles(gUnk_09756ACE, 0x180);
            m4aSongNumStart(0x182);
        }
        DrawSprite(x, y, w->unk_0C, w->unk_00, w->palette, 0, 0x800, -0x1002 - (w->unk_48 >> 8) * 4);
        DrawSprite(x - 5, y + 5, w->unk_10, w->unk_04, w->palette, 0, 0x800, -0x1003 - (w->unk_48 >> 8) * 4);
    }
}

void task_poo_beeAfterEvent_3(PooBeeAfterEventWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjTiles(w->unk_04);
        ReleaseObjPalette(w->palette);
    }
}

u8 func_080D1050(void) {
    if (func_080D2D50(2) != 0) {
        if (gPooBeeAfterEventWork->palette != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080D1078(PooSpot* p) {
    PooSpot t[18];
    u16 i;

    memcpy(t, gUnk_096FD778, sizeof(t));
    i = func_080D1710();
    if (i > 13) {
        i += GetRandom() % 4;
    }
    p->unk_00 = t[i].unk_00 + 0xAB300;
    p->unk_04 = t[i].unk_04 + 0x57100;
    p->unk_08 = t[i].unk_08;
}

void task_poo_cabbage_0(PooCabbageWork* w) {
    u16 r;

    w->unk_24 = 0x98300;
    w->unk_28 = 0x4D100;
    w->unk_2C = 0;
    w->unk_C4 = 0x4CC;
    r = GetRandom();
    w->unk_C8 = (r & 15) + 88;
    w->unk_C0 = 0x1CC;
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF6060, gUnk_09EF602C);
    w->unk_A4 = 2;
    AnimStart(w->anim, 2, 1);
    w->gfx = AnimGetGfx(w->anim);
    func_080122AC(w->unk_44, 10, 8, 16);
    func_08012324(w->unk_44, w->unk_24, w->unk_28, w->unk_2C);
    w->unk_D0 = 1;
    TaskPoolInit(&w->unk_A8, 2);
    func_080CC178(&w->unk_A8, &w->unk_24, 0x80);
    w->unk_BC = 0;
    w->unk_CE = 0;
    w->unk_D1 = 0;
    w->unk_D2 = 1;
}

u8 task_poo_cabbage_1(PooCabbageWork* w) {
    u16 t[15];
    u16 sx;
    s16 sy;
    s32 v;

    memcpy(t, gUnk_096FD850, 30);
    w->unk_CE++;

    switch (w->unk_A4) {
    case 2:
        if (gUnk_0203C3D8 != 0 && func_080C76B0(w->unk_44) != 0) {
            if (IsTaskActive(w->unk_BC) != 0) {
                func_08000DE8(&w->unk_A8, w->unk_BC);
            }
            w->unk_BC = TaskCreate(&w->unk_A8, &gTaskDescPooSpark, &w->unk_24);
            w->unk_A4 = 3;
            AnimStart(w->anim, 3, 0);
            m4aSongNumStart(222);
            w->unk_CA = 30;
            w->unk_CC = 20;
            w->unk_A0 = -0x2000;
            func_080D1078((PooSpot*)&w->unk_34);
            w->unk_D4 = func_080D1710();
            func_080D16FC();

            if (w->unk_D0 != 0) {
                func_08012304(w->unk_44);
                w->unk_D0 = 0;
            }
        } else {
            w->unk_24 += gSineTable[w->unk_C8] * w->unk_C0 >> 8;
            w->unk_28 += -gSineTable[w->unk_C8 + 0x40] * w->unk_C0 >> 8;
            w->unk_C4 += 51;
            w->unk_2C += w->unk_C4;

            if (w->unk_2C > 0) {
                w->unk_2C = 0;
                w->unk_C4 = -(w->unk_C4 * 179 >> 8);
            }

            if (w->unk_D1 != 0) {
                v = (w->unk_24 >> 8) - gUnk_0203C40C;
                sy = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
                sx = v;

                if ((u16)(sx + 16) > 272 || sy < -36 || sy > 196) {
                    return 0;
                }
            }
        }
        break;
    case 3:
        if (w->unk_CC != 0) {
            ApproachValue(&w->unk_2C, w->unk_3C + w->unk_A0, w->unk_CC);
            w->unk_CC--;

            if (w->unk_CC == 0 && w->unk_A0 < 0) {
                w->unk_CC = 10;
                w->unk_A0 = 0;
            }
        }
        ApproachValue(&w->unk_24, w->unk_34, w->unk_CA);
        ApproachValue(&w->unk_28, w->unk_38, w->unk_CA);
        w->unk_CA--;

        if (w->unk_CA == 0) {
            w->unk_A4 = 4;
            AnimStart(w->anim, 4, 0);
        }
        break;
    case 4:
        if (func_080D2D50(4) == 0 && w->unk_D4 == 13) {
#ifdef VERSION_EU
            func_080C7B84(140);
#else
            func_080C7B84(142);
#endif
            func_080D2D3C(4);
            func_0800FDD0(83);
        }

        if (AnimIsFinished(w->anim) != 0) {
            w->unk_A4 = 1;
            AnimStart(w->anim, 1, 0);
            func_080D171C();
            w->unk_D2 = 0;

            if (w->unk_D4 == 5) {
                w->unk_24 = 0xAB300;
                w->unk_28 = 0x57100;
                w->unk_2C = 0;
                w->gfx = gUnk_09756D86;
            } else if (w->unk_D4 == 8) {
                w->unk_24 = 0xAB300;
                w->unk_28 = 0x57100;
                w->unk_2C = 0;
                w->gfx = gUnk_09756D90;
            } else {
                w->gfx = gUnk_09756C78;
            }
        }
        break;
    case 1:
        if (t[w->unk_D4] < func_080D172C()) {
            return 0;
        }
        break;
    }
    return 1;
}

void task_poo_cabbage_2(PooCabbageWork* w) {
    u16 t[5];
    u16 z;
    s16 x;
    s16 y;

    memcpy(t, gUnk_096FD86E, sizeof(t));
    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;

    if (x < -16 || x > 256 || y < -36 || y > 196) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_09756E28, 0x1D20);
            w->palette = LoadObjPalette(gUnk_09849DB8, 32);
        }

        if (w->unk_D2 != 0) {
            w->gfx = AnimUpdate(w->anim);
        }
        w->unk_D1 = 1;

        if (w->unk_D0 != 0) {
            func_08012324(w->unk_44, w->unk_24, w->unk_28, w->unk_2C);
        }

        if (w->unk_D4 < 9 || w->unk_D4 > 13) {
            z = -0x1004 - (w->unk_28 >> 8) * 4;
        } else {
            z = 0xDA38 - t[w->unk_D4 - 9];
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, z);

        if (w->unk_A4 != 4 && w->unk_A4 != 1) {
            TaskPoolUpdate(&w->unk_A8);
            TaskPoolDraw(&w->unk_A8);
        }
    }
}

void task_poo_cabbage_3(PooCabbageWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_D0 != 0) {
        func_08012304(w->unk_44);
    }
    TaskPoolDestroy(&w->unk_A8);
}

void task_poo_cabbageborn_0(PooCabbageBornWork* w) {
    TaskPoolInit(&w->unk_00, 0x20);
    w->unk_14 = 0;
    w->unk_16 = 0;
    gUnk_02034E34 = 0;
    gUnk_02034E36 = 0;
}

u8 func_080D1650(void) {
    if (func_080D2D50(6) != 0 && func_080C9910() == 0 && gUnk_0203C40C > 0x9EB && gUnk_0203C40C <= 0xA8A && gUnk_0203C3F8 <= 0x548 && gUnk_0203C3F8 > 0x4F9) {
        return 1;
    }
    return 0;
}

u8 task_poo_cabbageborn_1(PooCabbageBornWork* w) {
    if (func_080D1650() != 0 && w->unk_16 == 0) {
        TaskCreate(&w->unk_00, &gTaskDescPooCabbage, 0);
        w->unk_16 = 40;
    }

    if (w->unk_16 != 0) {
        w->unk_16--;
    }
    TaskPoolUpdate(&w->unk_00);
    return 1;
}

void task_poo_cabbageborn_2(TaskPool* w) {
    TaskPoolDraw(w);
}

void task_poo_cabbageborn_3(TaskPool* w) {
    TaskPoolDestroy(w);
}

void func_080D16FC(void) {
    if (gUnk_02034E34 <= 13) {
        gUnk_02034E34++;
    }
}

u16 func_080D1710(void) {
    return gUnk_02034E34;
}

void func_080D171C(void) {
    gUnk_02034E36++;
}

u16 func_080D172C(void) {
    return gUnk_02034E36;
}

u8 func_080D1738(void) {
    if (func_080D2D50(4) == 0) {
        if (func_080D2D50(6) != 0) {
            if (gUnk_0203C3F8 > 0x4F9) {
                return 1;
            }
        }
    }
    return 0;
}

void task_poo_mapobjhit_0(PooMapObjHitWork* w, PooMapObjHitArgs* a) {
    w->unk_24 = a->unk_00;
    w->unk_28 = a->unk_04;
    w->unk_2C = 0;
    w->unk_98 = a->unk_14;
    w->unk_9C = a->unk_18;
    w->unk_34 = a->unk_10;
    w->unk_3A = func_08003524(w->unk_34->unk_0C, w->unk_34->unk_04);
    w->palette = 0;
    AnimInit(w->anim, w->unk_34->unk_08, w->unk_34->unk_0C);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    w->unk_4C = 0x1000;
    w->unk_50 = 0x1800;
    func_08012324(w->unk_3C, w->unk_24 + 0x1000, w->unk_28 + 0xC00, w->unk_2C);
    w->unk_38 = 0;
}

u8 task_poo_mapobjhit_1(PooMapObjHitWork* w) {
    func_080D2F10(0);

    if (gUnk_0203C3D8 != 0) {
        if (func_080C76B0(w->unk_3C) != 0) {
            if (w->unk_38 == 0) {
                w->unk_38 = 1;
                AnimReset(w->anim);

                if (func_080D2C1C(w->unk_9C) == 0) {
                    if (func_080C7BF8(2, 1, w->unk_24 + 0x1000, w->unk_28 + 0x1800, w->unk_2C) != 0) {
                        func_080D2BF8(w->unk_9C);
                    }
                }

                if (w->unk_98 == 4) {
                    m4aSongNumStart(0x146);
                } else {
                    m4aSongNumStart(0xE0);
                }
            }
        }
    }

    if (w->unk_38 != 0) {
        w->gfx = AnimUpdate(w->anim);

        if (AnimIsFinished(w->anim) != 0) {
            w->unk_38 = 0;
        }
    }
    return 1;
}

void task_poo_mapobjhit_2(PooMapObjHitWork* w) {
    s16 x;
    s16 y;
    s32 pr;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (w->unk_38 == 0 || func_080035CC(x, y, 0, 24, 0, 32) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_3A, w->unk_34->unk_00);
            w->palette = LoadObjPalette(w->unk_34->unk_10, 0x20);
        }
        pr = 0x800;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, 0xFFF1);
        func_080D2F10(1);
    }
}

void task_poo_mapobjhit_3(PooObjWork* w) {
    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ReleaseObjTiles(w->tiles);
    }
}

void func_080D1990(void* pool, u32 a, s32 x, s32 y, u16 e) {
    PooMapObjHitArgs args;

    args.unk_00 = x;
    args.unk_04 = y;
    args.unk_10 = &gUnk_096FD8A4[a];
    args.unk_14 = a;
    args.unk_18 = e;
    TaskCreate(pool, &gTaskDescPooMapobjhit, &args);
}

void func_080D19C4(PooPrizeWork* w) {
    u8 v;

    w->unk_84 += 56;
    w->unk_08 += w->unk_84;
    w->unk_00 += gSineTable[w->unk_8C] * w->unk_88 >> 8;
    w->unk_04 += -gSineTable[w->unk_8C + 0x40] * w->unk_88 >> 8;

    if (func_080CA3A0((PooPos*)w) != 0) {
        w->unk_8C = (u8)(w->unk_8C + 100) + GetRandom() % 57;
    } else {
        w->unk_0C = 0;
    }

    if (w->unk_08 > w->unk_0C) {
        w->unk_08 = w->unk_0C;
        w->unk_84 = -(w->unk_84 * 179 >> 8);
        w->unk_88 = w->unk_88 * 212 >> 8;
    }

    if (w->unk_10[0x2C] != 0 && func_08012660(w->unk_10, 1) != 0) {
        switch (w->unk_80) {
        case 2:
        case 3:
            m4aSongNumStart(107);
            gGameState.unk_174 += w->unk_94;

            if (gGameState.unk_174 > 99999) {
                gGameState.unk_174 = 99999;
            }
            break;
        case 0:
        case 1:
        default:
            m4aSongNumStart(107);
            gGameState.unk_32 += w->unk_94;

            if (gGameState.unk_32 > (s16)gGameState.unk_F8) {
                gGameState.unk_32 = gGameState.unk_F8;
            }
            break;
        }

        w->unk_7C = func_080D1B94;
        w->unk_82 = 0;
        w->unk_8C = GetAngle(gUnk_0203C420.unk_00.unk_00, gUnk_0203C420.unk_00.unk_04, w->unk_00, w->unk_04);
        w->unk_97 = 1;
        w->unk_96 = 1;
        w->unk_8D = GetRandom() % 6 + 5;
        func_08012614(w->unk_10, 1);
    } else {
        func_08012324(w->unk_10, w->unk_00, w->unk_04, w->unk_08);

        if (w->unk_82 == 20) {
            func_08012614(w->unk_10, 0);
        }

        if (w->unk_82 > 420) {
            v = 0;

            if (w->unk_96 == 0) {
                v = 1;
            }
            w->unk_96 = v;
        }

        if (w->unk_82++ > 480) {
            w->unk_7C = 0;
        }
    }
}

void func_080D1B94(PooPrizeWork* w) {
    PooPos* g;
    const s16* t;
    s32 tx;
    s32 ty;
    s32 tz;
    s32 s;
    u8 a;

    g = &gUnk_0203C420.unk_00;
    t = gSineTable;
    a = w->unk_8C;
    tx = g->unk_00 + ((t[a] << 5) * w->unk_90 >> 8);
    s = -gSineTable[a + 0x40] * 22;
    ty = g->unk_04 + (s * w->unk_90 >> 8);
    tz = g->unk_08 - ((w->unk_82 >> 1) << 8);
    w->unk_8C = a + w->unk_8D;
    w->unk_00 += (tx - w->unk_00) >> 2;
    w->unk_04 += (ty - w->unk_04) >> 2;
    w->unk_08 += (tz - w->unk_08) >> 2;
    w->unk_0C = 0;
    w->unk_90 -= 2;

    if (w->unk_82 > 60) {
        w->unk_7C = 0;
    } else {
        w->unk_82++;
    }
}

void task_poo_prize_0(PooPrizeWork* w, PoohPrizeArgs* a) {
    w->unk_00 = a->unk_04;
    w->unk_04 = a->unk_08;
    w->unk_08 = a->unk_0C;
    w->unk_0C = 0;
    w->unk_84 = -(GetRandom() % 0x301 + 0x200);
    w->unk_88 = GetRandom() % 155 + 153;
    w->unk_8C = GetRandom();
    w->tiles = LoadObjTiles(gUnk_098A5CF4, 0x160);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_80 = a->unk_14;

    switch (w->unk_80) {
    case 3:
        w->unk_74 = gUnk_098A5CAE;
        w->unk_94 = 10;
        break;
    case 2:
        w->unk_74 = gUnk_098A5CA4;
        w->unk_94 = 4;
        break;
    case 1:
        w->unk_74 = gUnk_098A5C9A;
        w->unk_94 = 10;
        break;
    case 0:
    default:
        w->unk_74 = gUnk_098A5C90;
        w->unk_94 = 3;
        break;
    }
    w->unk_78 = gUnk_098A5CB8;
    w->unk_97 = 0;
    w->unk_96 = 1;
    w->unk_82 = 0;
    w->unk_7C = func_080D19C4;
    w->unk_90 = 0x100;
    func_080122AC(w->unk_10, 5, 16, 50);
    func_08012324(w->unk_10, w->unk_00, w->unk_04, w->unk_08);
    func_08012614(w->unk_10, 1);
}

u8 task_poo_prize_1(PooPrizeWork* w) {
    if (w->unk_7C != 0) {
        w->unk_7C(w);

        if (w->unk_7C != 0) {
            return 1;
        }
    }
    return 0;
}

void task_poo_prize_2(PooPrizeWork* w) {
    s32 aff;
    s32 s;
    s16 x;
    s16 y;

    if (w->unk_96 == 0) {
        return;
    }

    x = (w->unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_04 >> 8) + (w->unk_08 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 8, 8, 8, 8) != 0) {
        return;
    }

    s = w->unk_90;
    if (s != 256) {
        aff = AllocObjAffine(0, s, s, 0);
    } else {
        aff = 0;
    }
    DrawSprite(x, y, w->unk_74, w->tiles, w->palette, aff, 0x800, -0x1004 - (w->unk_04 >> 8) * 4);

    if (w->unk_97 == 0) {
        y = (w->unk_04 >> 8) + (w->unk_0C >> 8) - gUnk_0203C3F8;
        DrawSprite(x, y, w->unk_78, w->tiles, w->palette, aff, 0x800, 0xFFF0);
    }
}

void task_poo_prize_3(PooPrizeWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    func_08012304(w->unk_10);
}

void task_poo_zzz_0(PooZzzWork* w, u8* arg) {
    w->unk_24 = gUnk_0203C3EC;
    w->tiles = AllocObjTiles(0x100, gUnk_097257D8);
    w->palette = LoadObjPalette(gUnk_09849A98, 0x20);
    AnimInit(w->anim, gUnk_09EF5904, gUnk_09EF5844);

    if (*arg != 0) {
        AnimStart(w->anim, 8, 1);
    } else {
        AnimStart(w->anim, 7, 1);
    }
    w->gfx = AnimGetGfx(w->anim);
}

u8 task_poo_zzz_1(void* w) {
    return 1;
}

void task_poo_zzz_2(PooZzzWork* w) {
    PooPos* p;
    s16 x;
    s16 y;
    void* g;

    p = w->unk_24;
    x = (p->unk_00 >> 8) - gUnk_0203C40C;
    y = (p->unk_04 >> 8) + (p->unk_08 >> 8) - gUnk_0203C3F8;
    if (x >= -0x20 && x <= 0x110 && y >= -0x20 && y <= 0xC0) {
        g = AnimUpdate(w->anim);
        w->gfx = g;
        DrawSprite(x, y, g, w->tiles, w->palette, 0, 0x400, 0x0B);
    }
}

void task_poo_zzz_3(PooZzzWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void func_080D1FB8(PooBflyPart* p) {
    switch (((p->unk_48 + 16) & 0xFF) >> 5) {
    case 1:
        p->unk_4C = 4;
        p->unk_50 = 1;
        break;
    case 2:
        p->unk_4C = 3;
        p->unk_50 = 1;
        break;
    case 3:
        p->unk_4C = 2;
        p->unk_50 = 1;
        break;
    case 4:
        p->unk_4C = 1;
        p->unk_50 = 0;
        break;
    case 5:
        p->unk_4C = 2;
        p->unk_50 = 0;
        break;
    case 6:
        p->unk_4C = 3;
        p->unk_50 = 0;
        break;
    case 7:
        p->unk_4C = 4;
        p->unk_50 = 0;
        break;
    case 0:
    default:
        p->unk_4C = 0;
        p->unk_50 = 0;
        break;
    }
}

void func_080D2034(PooBflyPart* p) {
    const PooZzzDesc* d;

    func_080D1FB8(p);
    d = &gUnk_09EF4C88[p->unk_4C];
    func_08005974(p->anim, d->unk_0C, 1, d->unk_04, d->unk_00);
    func_08002A10(p->tiles, d->unk_08);
}

void func_080D206C(PooBflyPart* p) {
    if ((s8)p->unk_48 >= 0) {
        p->unk_40 = p->unk_38;
        p->unk_44 = p->unk_3C;
    } else {
        p->unk_40 = p->unk_30;
        p->unk_44 = p->unk_34;
    }
    p->tiles = AllocObjTiles(0x40, 0);
    AnimInit(p->anim, 0, 0);
    func_080D2034(p);
    p->gfx = AnimGetGfx(p->anim);
}

void task_poo_butterfly_0(PooButterflyWork* w, PooPos* p) {
    w->unk_D4 = p->unk_00;
    w->unk_D8 = p->unk_04;
    w->unk_DC = p->unk_08 - 0xE00;
    w->palette = LoadObjPalette(gUnk_09849C38, 0x20);
    w->unk_00[0].unk_20 = w->unk_D4 - 0x1000;
    w->unk_00[0].unk_24 = w->unk_D8;
    w->unk_00[0].unk_28 = w->unk_DC;
    w->unk_00[0].unk_30 = w->unk_D4 - 0x1000;
    w->unk_00[0].unk_34 = w->unk_D8;
    w->unk_00[0].unk_38 = w->unk_D4 + 0x600;
    w->unk_00[0].unk_3C = w->unk_D8 + 0x700;
    w->unk_00[0].unk_48 = 0x60;
    w->unk_00[0].unk_52 = 0x60;
    w->unk_00[1].unk_20 = w->unk_D4 + 0x1200;
    w->unk_00[1].unk_24 = w->unk_D8;
    w->unk_00[1].unk_28 = w->unk_DC;
    w->unk_00[1].unk_38 = w->unk_D4 + 0x1200;
    w->unk_00[1].unk_3C = w->unk_D8;
    w->unk_00[1].unk_30 = w->unk_D4 - 0x100;
    w->unk_00[1].unk_34 = w->unk_D8 - 0x700;
    w->unk_00[1].unk_48 = 0xE0;
    w->unk_00[1].unk_52 = 0x60;
    func_080D206C(&w->unk_00[0]);
    func_080D206C(&w->unk_00[1]);
}

void func_080D2190(PooBflyPart* p) {
    if (p->unk_52 != 0) {
        ApproachValue(&p->unk_20, p->unk_40, p->unk_52);
        ApproachValue(&p->unk_24, p->unk_44, p->unk_52);
        p->unk_52--;
    } else {
        p->unk_52 = 0x60;
        p->unk_48 += 0x80;
        if ((s8)p->unk_48 >= 0) {
            p->unk_40 = p->unk_38;
            p->unk_44 = p->unk_3C;
        } else {
            p->unk_40 = p->unk_30;
            p->unk_44 = p->unk_34;
        }
    }
    p->gfx = AnimUpdate(p->anim);
}

u8 task_poo_butterfly_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[0]);
    func_080D2190(&w->unk_00[1]);
    return 1;
}

u8 func_080D220C(PooBflyPart* p, void* pal) {
    s16 x;
    s16 y;
    s32 pr;

    x = (p->unk_20 >> 8) - gUnk_0203C40C;
    y = (p->unk_24 >> 8) + (p->unk_28 >> 8) - gUnk_0203C3F8;
    if (x < -8 || x > 248 || y < -8 || y > 168) {
        return 0;
    }
    pr = p->unk_50 != 0 ? 0x801 : 0x800;
    func_080D2034(p);
    DrawSprite(x, y, p->gfx, p->tiles, pal, 0, pr, -0x1004 - (p->unk_24 >> 8) * 4);
    return 1;
}

void task_poo_butterfly_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[0], w->palette);
    func_080D220C(&w->unk_00[1], w->palette);
}

void task_poo_butterfly_3(PooButterflyWork* w) {
    ReleaseObjTiles(w->unk_00[0].tiles);
    ReleaseObjTiles(w->unk_00[1].tiles);
    ReleaseObjPalette(w->palette);
}

u8 task_poo_butterflyRight_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[1]);
    return 1;
}

void task_poo_butterflyRight_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[1], w->palette);
}

u8 task_poo_butterflyLeft_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[0]);
    return 1;
}

void task_poo_butterflyLeft_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[0], w->palette);
}

void task_poo_mapbee_0(PooMapBeeWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04;
    w->unk_2C = 0;
    w->tiles = AllocObjTiles(func_08003524(gUnk_09EF6158, 1), gUnk_097606E8);
    w->palette = LoadObjPalette(gUnk_09849E38, 0x20);
    AnimInit(w->anim, gUnk_09EF6200, gUnk_09EF6158);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    w->unk_34 = 1;
    w->unk_36 = 0;
    m4aSongNumStart(0x182);
}

u8 task_poo_mapbee_1(PooMapBeeWork* w) {
    if (w->unk_34 == 0) {
        return 0;
    }

    switch (w->unk_36) {
    case 0:
        if (AnimIsFinished(w->anim) != 0) {
            AnimStart(w->anim, 1, 1);
            w->unk_36 = 1;
        }
        break;
    case 1:
        w->unk_2C -= 0xCC;
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_mapbee_2(PooMapBeeWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 8, 8, 8, 8) != 0) {
        w->unk_34 = 0;
    } else {
        func_080C7CB0(1);
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_28 >> 8) * 4);
    }
}

void task_poo_mapbee_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);

    if (func_080D1050() == 0) {
        m4aSongNumStop(0x182);
    }
}

void task_poo_mapbeeborn_0(PooMapBornWork* w, PooPos* p) {
    w->unk_10 = *p;
    w->unk_10.unk_08 = 0;
    w->unk_00 = p->unk_00 + 0x400;
    w->unk_04 = p->unk_04 + 0x1800;
    w->unk_08 = 0;
    func_08012324(w->unk_20, w->unk_00, w->unk_04, 0);
    w->unk_98 = 0;
    w->unk_7C = 0;
    w->unk_99 = 0;
    TaskPoolInit(&w->unk_80, 1);
    w->unk_94 = 0;
}

u8 task_poo_mapbeeborn_1(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        if ((w->unk_4E & 2) != 0) {
            if (IsTaskActive(w->unk_94) == 0 && w->unk_99 != 0) {
                w->unk_99 = 0;
                w->unk_94 = TaskCreate(&w->unk_80, &gTaskDescPooMapbee, &w->unk_10);
            }
        } else {
            w->unk_99 = 1;
        }
    }
    return 1;
}

void task_poo_mapbeeborn_2(PooMapBornWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_04 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 0, 24, 0, 32) != 0) {
        if (w->unk_98 != 0) {
            w->unk_98 = 0;
            func_08012304(w->unk_20);
            w->unk_99 = 0;
#ifdef VERSION_EU
            if (IsTaskActive(w->unk_94)) {
                func_08000DE8(&w->unk_80, w->unk_94);
            }
#endif
        }
    } else {
        if (w->unk_98 == 0) {
            func_080122AC(w->unk_20, 6, 28, 0);
            w->unk_98 = 1;
            w->unk_99 = 1;
        }
        TaskPoolUpdate(&w->unk_80);
        TaskPoolDraw(&w->unk_80);
    }
}

void task_poo_mapbeeborn_3(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        func_08012304(w->unk_20);
    }
    TaskPoolDestroy(&w->unk_80);
}

void task_poo_mapbutterfly_0(PooMapButterflyWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04;
    w->unk_2C = 0;
    w->tiles = AllocObjTiles(0x40, gUnk_09760986);
    w->palette = LoadObjPalette(gUnk_09849E58, 0x20);
    AnimInit(w->anim, gUnk_09EF6298, gUnk_09EF6208);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    w->unk_34 = 1;
}

u8 task_poo_mapbutterfly_1(PooMapButterflyWork* w) {
    if (w->unk_34 == 0) {
        return 0;
    }
    w->unk_2C -= 0x80;
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_mapbutterfly_2(PooMapButterflyWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 8, 8, 8, 8) != 0) {
        w->unk_34 = 0;
    } else {
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_28 >> 8) * 4);
    }
}

void task_poo_mapbutterfly_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_mapbutterflyborn_0(PooMapBornWork* w, PooPos* p) {
    w->unk_10 = *p;
    w->unk_10.unk_08 = 0;
    w->unk_00 = p->unk_00 + 0x1000;
    w->unk_04 = p->unk_04 + 0x1800;
    w->unk_08 = 0;
    func_08012324(w->unk_20, w->unk_00, w->unk_04, 0);
    w->unk_98 = 0;
    w->unk_7C = 0;
    w->unk_99 = 0;
    TaskPoolInit(&w->unk_80, 1);
    w->unk_94 = 0;
}

u8 task_poo_mapbutterflyborn_1(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        if ((w->unk_4E & 2) != 0) {
            if (IsTaskActive(w->unk_94) == 0 && w->unk_99 != 0) {
                w->unk_99 = 0;
                w->unk_94 = TaskCreate(&w->unk_80, &gTaskDescPooMapbutterfly, &w->unk_10);
            }
        } else {
            w->unk_99 = 1;
        }
    }
    return 1;
}

void task_poo_mapbutterflyborn_2(PooMapBornWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_04 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 0, 24, 0, 32) != 0) {
        if (w->unk_98 != 0) {
            w->unk_98 = 0;
            func_08012304(w->unk_20);
            w->unk_99 = 0;
        }
    } else {
        if (w->unk_98 == 0) {
            func_080122AC(w->unk_20, 6, 40, 0);
            w->unk_98 = 1;
            w->unk_99 = 1;
        }
        TaskPoolUpdate(&w->unk_80);
        TaskPoolDraw(&w->unk_80);
    }
}

void task_poo_mapbutterflyborn_3(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        func_08012304(w->unk_20);
    }
    TaskPoolDestroy(&w->unk_80);
}

void task_poo_rabbitAfterEvent_0(PooRabbitAfterEventWork* w) {
    w->unk_24 = 0xA9B00;
    w->unk_28 = 0x57200;
    w->unk_2C = 0;
    w->unk_30 = 0;
    w->palette = 0;
    w->unk_A4 = func_08003524(gUnk_09EF5EA8, 15);
    AnimInit(w->anim, gUnk_09EF5EE4, gUnk_09EF5EA8);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->unk_34, 1);
    func_080CC178(&w->unk_34, &w->unk_24, 0x100);
    func_08012324(w->unk_48, w->unk_24, w->unk_28, w->unk_2C);
    w->unk_A6 = func_080D2E28(w->unk_48, 60);
    func_080D2E70(w->unk_A6, 0);
}

u8 task_poo_rabbitAfterEvent_1(PooRabbitAfterEventWork* w) {
    if (w->palette != 0) {
        if (func_08012660(w->unk_48, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_rabbitAfterEvent_2(PooRabbitAfterEventWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 48, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            func_08012304(w->unk_48);
            func_080D2E70(w->unk_A6, 0);
            w->palette = 0;
        }
    } else {
        w->gfx = AnimUpdate(w->anim);
        TaskPoolUpdate(&w->unk_34);

        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849CB8, 0x40);
            w->tiles = AllocObjTiles(w->unk_A4, gUnk_0974FB26);
            func_080122AC(w->unk_48, 10, 4, 48);
            func_080D2E70(w->unk_A6, 1);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x801, -0x1004 - (w->unk_28 >> 8) * 4);
        TaskPoolDraw(&w->unk_34);
    }
}

void task_poo_rabbitAfterEvent_3(PooRabbitAfterEventWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        func_08012304(w->unk_48);
    }
    TaskPoolDestroy(&w->unk_34);
}

void task_poo_cabbageAfterEvent_0(PooCabbageAfterEventWork* w) {
    w->unk_0C = 0xAB300;
    w->unk_10 = 0x57100;
    w->unk_14 = 0;
    w->unk_18 = 0;
    w->palette = 0;
    w->unk_1C = func_08003524(gUnk_09EF602C, 13);
    w->unk_08 = gUnk_09756D16;
}

u8 task_poo_cabbageAfterEvent_1(PooCabbageAfterEventWork* w) {
    *(vu32*)&w->palette;
    return 1;
}

void task_poo_cabbageAfterEvent_2(PooCabbageAfterEventWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_0C >> 8) - gUnk_0203C40C;
    y = (w->unk_10 >> 8) - gUnk_0203C3F8;
    if (func_080035CC(x, y, 48, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849DB8, 0x20);
            w->tiles = AllocObjTiles(w->unk_1C, gUnk_09756E28);
        }
        DrawSprite(x, y, w->unk_08, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_10 >> 8) * 4);
    }
}

void task_poo_cabbageAfterEvent_3(PooObjWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
}

void func_080D2BE0(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gUnk_0203C470.unk_2C[i] = 0;
    }
}

void func_080D2BF8(u16 a) {
    u32 i;
    u32 s;

    i = a / 32;
    s = a % 32;
    gUnk_0203C470.unk_2C[i] |= 1 << s;
}

u8 func_080D2C1C(u16 a) {
    u32 i;
    u32 s;

    i = a / 32;
    s = a % 32;
    if ((gUnk_0203C470.unk_2C[i] & (1 << s)) != 0) {
        return 1;
    }
    return 0;
}

void func_080D2C48(void) {
    func_080D2BE0();
    gUnk_0203C470.unk_28 = 0;
    gUnk_0203C470.unk_3C = 3;
    gUnk_0203C470.unk_3E = 0x73B;
    gUnk_0203C3E4 = 3;
    gUnk_0203C3E0 = 0x73B;
}

void func_080D2C78(void) {
    gUnk_0203C470.unk_24 = 0;
    func_080D2C48();
}

void func_080D2C8C(PooPos* p, s32 b) {
    gUnk_0203C470.unk_00 = *p;
    gUnk_0203C470.unk_20 = b;
}

void func_080D2CA8(PooPos* p, s32* b) {
    *p = gUnk_0203C470.unk_00;
    *b = gUnk_0203C470.unk_20;
}

void func_080D2CC4(u16 a, u16 b) {
    gUnk_0203C470.unk_3C = a;
    gUnk_0203C470.unk_3E = b;
}

void func_080D2CD0(u16* a, u16* b) {
    *a = gUnk_0203C470.unk_3C;
    *b = gUnk_0203C470.unk_3E;
}

void func_080D2CE0(s16 a, s16 b) {
    gUnk_0203C470.unk_40 = a;
    gUnk_0203C470.unk_42 = b;
}

void func_080D2CF4(u16* a, u16* b) {
    *a = gUnk_0203C470.unk_40;
    *b = gUnk_0203C470.unk_42;
}

void func_080D2D0C(PooPos* p) {
    gUnk_0203C470.unk_10 = *p;
}

void func_080D2D24(PooPos* p) {
    *p = gUnk_0203C470.unk_10;
}

void func_080D2D3C(s32 a) {
    gUnk_0203C470.unk_28 |= 1 << a;
}

u8 func_080D2D50(s32 a) {
    if (((gUnk_0203C470.unk_28 >> a) & 1) != 0) {
        return 1;
    }
    return 0;
}

void func_080D2D6C(s32 a) {
    gUnk_0203C470.unk_24 |= 1 << a;
}

void func_080D2D80(s32 a) {
    gUnk_0203C470.unk_24 &= ~(1 << a);
}

u8 func_080D2D94(s32 a) {
    if ((gUnk_0203C470.unk_24 & (1 << a)) != 0) {
        return 1;
    }
    return 0;
}

void func_080D2DB0(void* p) {
    memcpy(p, &gUnk_0203C470, sizeof(gUnk_0203C470));
}

void func_080D2DC4(const void* p) {
    memcpy(&gUnk_0203C470, p, sizeof(gUnk_0203C470));
}

u8 func_080D2DD8(void) {
    s32 v[6];
    u32 i;
    s32 n;

    memcpy(v, gUnk_096FDA74, sizeof(v));

    if (func_080D2D94(1) != 0) {
        return 1;
    }
    n = 0;

    for (i = 0; i < 6; i++) {
        if (func_080D2D50(v[i]) != 0) {
            n++;
        }
    }

    if (n <= 4) {
        return 0;
    }
    return 1;
}

u16 func_080D2E28(void* a, u16 b) {
    if (gUnk_0203C4B4->unk_30 > 5) {
        return 0xFFFF;
    }
    gUnk_0203C4B4->unk_00[gUnk_0203C4B4->unk_30].unk_00 = a;
    gUnk_0203C4B4->unk_00[gUnk_0203C4B4->unk_30].unk_04 = b;
    gUnk_0203C4B4->unk_00[gUnk_0203C4B4->unk_30].unk_06 = 1;
    return gUnk_0203C4B4->unk_30++;
}

void func_080D2E70(u16 a, u8 b) {
    gUnk_0203C4B4->unk_00[a].unk_06 = b;
}

void func_080D2E84(void) {
    EwramFree(gUnk_0203C4B4);
}

void func_080D2E98(void) {
    gUnk_0203C4B4 = EwramAlloc(0x34);
    gUnk_0203C4B4->unk_30 = 0;
    func_080D2F10(0);
}

u16 func_080D2EB8(void) {
    s32 i;

    for (i = 0; i < gUnk_0203C4B4->unk_30; i++) {
        if (gUnk_0203C4B4->unk_00[i].unk_04 == 0x3B && gUnk_0203C4B4->unk_32 != 0) {
            continue;
        }

        if (gUnk_0203C4B4->unk_00[i].unk_06 == 0) {
            continue;
        }

        if (func_080C76B0(gUnk_0203C4B4->unk_00[i].unk_00) == 0) {
            continue;
        }
        return gUnk_0203C4B4->unk_00[i].unk_04;
    }
#ifdef VERSION_EU
    return 0xB3;
#else
    return 0xB4;
#endif
}

void func_080D2F10(u8 a) {
    gUnk_0203C4B4->unk_32 = a;
}

void func_080D2F20(void) {
    while ((REG_DISPSTAT & 2) == 0) {
    }
    REG_BG3CNT &= 0xFFFC;
    REG_BG3CNT |= 2;
    REG_BG1HOFS = 0;
}

void func_080D2F64(void) {
    u32 i;
    u16 j;
    u16 k;

    gUnk_0203C530 = EwramAlloc(0x4000);
    gUnk_0203C504 = EwramAlloc(0x4000);

    for (i = 0; i < 0x2000; i++) {
        gUnk_0203C530[i] = 0;
        gUnk_0203C504[i] = 0;
    }

    for (j = 0; j < 4; j++) {
        for (k = 0; k < 2; k++) {
            gUnk_0203C4C0[j * 2 + k] = gUnk_0203C530 + (j * 2 + k) * 0x400;
            gUnk_0203C510[j * 2 + k] = gUnk_0203C504 + (j * 2 + k) * 0x400;
        }
    }
}

void func_080D3008(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        func_080062F4(i, 1);
    }
    func_080062F4(10, 0);
    func_08006238(0, 16, 16);
}

void func_080D3034(s16 a) {
    SetBlendAlpha(a, 16 - a);
}

void func_080D3050(void) {
    PooPalStep t[9];

    memcpy(t, gUnk_096FDB40, sizeof(t));
    gUnk_02034E38++;
    if (gUnk_02034E38 < t[gUnk_02034E3A].unk_02) {
        return;
    }
    gUnk_02034E38 = 0;
    gUnk_02034E3A++;
    if (t[gUnk_02034E3A].unk_00 == 0xFF) {
        gUnk_02034E3A = 0;
    }
    LoadPalette(&gUnk_0984A138[t[gUnk_02034E3A].unk_00 * 0x20], (void*)0x05000040, 0x20);
}

void func_080D30C8(void) {
    RequestDma3Copy(gUnk_096FDA8C[gGameState.world].unk_00, (u8*)GetBgScreenBase(2) + 0x200, 0x300);
    RequestDma3Copy(gUnk_096FDA8C[gGameState.world].unk_04, (u8*)GetBgCharBase(2) + 0x2000, 0x2000);
    LoadPalette(gUnk_096FDA8C[gGameState.world].unk_08, (void*)0x05000140, 0x20);
}

#ifndef VERSION_EU
void func_080D313C(void) {
    u8* src;
    void* dst;

    dst = (u8*)GetBgCharBase(2) + 0x20;

    if ((gGameState.flags & 8) != 0) {
        src = &gUnk_097B8258[gGameState.floor * 0x140];
    } else {
        src = &gUnk_097B7218[gGameState.floor * 0x140];
    }
    RequestDma3Copy(src, dst, 0x140);
    dst = (u8*)GetBgScreenBase(2) + 0x480;
    src = gUnk_0983BC18;
    RequestDma3Copy(src, dst, 10);
    dst = (u8*)GetBgScreenBase(2) + 0x4C0;
    src += 0x40;
    RequestDma3Copy(src, dst, 10);
}
#else
INCLUDE_ASM("poo/func_080D313C.s");
#endif
