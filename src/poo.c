#include "poo.h"
#include "macros.h"

INCLUDE_ASM("poo/task_poo_pooh_0.s");

INCLUDE_ASM("poo/func_080C871C.s");

INCLUDE_ASM("poo/func_080C88C4.s");

INCLUDE_ASM("poo/func_080C89B4.s");

void func_080C8A3C(void* a) {
    func_080C89B4(a, gUnk_096FC2F0, 0x10);
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

INCLUDE_ASM("poo/func_080C8AB8.s");

#ifdef NON_MATCHING
s32 func_080C8B38(PooAim* w, PooPos* p, u8* c) {
    s32 v;
    s32 f;

    f = 1;
    if ((w->unk_2E & f) != 0) {
        v = w->unk_40;
        if (p->unk_0C < v) {
            v = p->unk_0C;
        }
        *c = f;
    } else {
        *c = 0;
        v = p->unk_0C;
    }
    return v;
}
#else
INCLUDE_ASM("poo/func_080C8B38.s");
#endif

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
    w->unk_28 += gUnk_08121400[w->unk_38] * w->unk_3C >> 8;
    w->unk_2C += -gUnk_08121400[w->unk_38 + 0x40] * w->unk_3C >> 8;
}

INCLUDE_ASM("poo/func_080C8BD4.s");

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

INCLUDE_ASM("poo/task_poo_pooh_1.s");

INCLUDE_ASM("poo/task_poo_pooh_2.s");

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
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
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

INCLUDE_ASM("poo/func_080C9DAC.s");

u8 func_080C9E28(void) {
    if (func_080CA67C(gUnk_0203C3EC) == 2) {
        return 1;
    }
    return 0;
}

u8 func_080C9E4C(void) {
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

INCLUDE_ASM("poo/func_080C9EFC.s");

void func_080C9FA8(s32 a, s32 b) {
    gUnk_0203C404 = a;
    gUnk_0203C400 = b;
}

INCLUDE_ASM("poo/func_080C9FBC.s");

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

INCLUDE_ASM("poo/task_poo_map_0.s");

u8 task_poo_map_1(PooMapWork* w) {
    func_080C9FBC(w);
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

INCLUDE_ASM("poo/func_080CA270.s");

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

#ifdef NON_MATCHING
u8 func_080CA3A0(PooPos* p) {
    u16 v;

    v = func_080CA36C(p->unk_00 >> 8, p->unk_04 >> 8) & 0x3FF;
    if (v >= 1 && v <= 9) {
        return 0;
    }
    if (v >= 0x20 && v <= 0x29) {
        return 0;
    }
    if (v >= 0x40 && v <= 0x49) {
        return 0;
    }
    if (v < 0x1E0 || v > 0x23F) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("poo/func_080CA3A0.s");
#endif

INCLUDE_ASM("poo/func_080CA3FC.s");

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

INCLUDE_ASM("poo/func_080CA560.s");

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

INCLUDE_ASM("poo/func_080CA6A8.s");

INCLUDE_ASM("poo/func_080CA724.s");

INCLUDE_ASM("poo/func_080CA8D4.s");

void func_080CA9DC(PooSoraWork* w) {
    u8 old;

    old = w->unk_14;
    func_080CA724(w);
    if (old != w->unk_14) {
        if (abs((s8)func_08005824(old, w->unk_14)) > 100) {
            w->unk_10 = 0;
        } else {
            w->unk_10 >>= 1;
        }
    }
}

#ifdef NON_MATCHING
s32 func_080CAA14(PooSoraWork* w) {
    s32 v;
    s32 f;

    f = 1;
    if ((w->unk_66 & f) != 0) {
        v = w->unk_78;
        if (gUnk_0203C420.unk_0C < v) {
            v = gUnk_0203C420.unk_0C;
        }
        w->unk_AC = f;
    } else {
        w->unk_AC = 0;
        v = gUnk_0203C420.unk_0C;
    }
    return v;
}
#else
INCLUDE_ASM("poo/func_080CAA14.s");
#endif

INCLUDE_ASM("poo/func_080CAA50.s");

INCLUDE_ASM("poo/func_080CAB24.s");

INCLUDE_ASM("poo/task_poo_sora_0.s");

INCLUDE_ASM("poo/task_poo_sora_1.s");

INCLUDE_ASM("poo/task_poo_sora_2.s");

void task_poo_sora_3(PooSoraWork* w) {
    func_080D2D0C(&gUnk_0203C420);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
    func_08012304(w->unk_38);
    TaskPoolDestroy(&w->unk_24);
    EwramFree(gUnk_02039BA0);
    func_080CCBD4(&w->unk_B0);
}

u8 func_080CBA4C(void) {
    if (gUnk_02034DE8->unk_94 == 8 && gUnk_02034DE8->unk_98 == 0) {
        return 1;
    }
    return 0;
}

u8 func_080CBA74(void) {
    if (gUnk_02034DE8->unk_94 == 8) {
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

INCLUDE_ASM("poo/func_080CBAB0.s");

u16 func_080CBB7C(void) {
    return gUnk_02034DEC - 1;
}

void task_poo_trap_0(PooTrapWork* w, PooPos* p) {
    w->unk_0C = p->unk_00;
    w->unk_10 = p->unk_04;
    w->unk_14 = 0;
    w->unk_00 = LoadObjTiles(gUnk_0972BD8C, 0x100);
    w->unk_04 = LoadObjPalette(gUnk_09849AB8, 0x20);
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

INCLUDE_ASM("poo/task_poo_trap_2.s");

INCLUDE_ASM("poo/task_poo_trap_3.s");

INCLUDE_ASM("poo/task_poo_balloon_0.s");

u8 task_poo_balloon_1(void* w) {
    return 1;
}

INCLUDE_ASM("poo/task_poo_balloon_2.s");

void task_poo_balloon_3(PooObjWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
}

void task_poo_shadow_0(TaskPool* w, void* arg) {
    PooBalloonArgs args;

    args.unk_00 = arg;
    args.unk_08 = 0xA6;
    TaskPoolInit(w, 1);
    TaskCreate(w, &gUnk_09EF4958, &args);
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
    w->unk_08 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_0C = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->unk_1C, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(w->unk_1C, 0, 1);
    w->unk_10 = AnimUpdate(w->unk_1C);
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
        DrawSprite(x, y, w->unk_10, w->unk_08, w->unk_0C, aff, 0x800, w->unk_18->unk_00);
    }
}

void task_poo_shadowdodai_3(PooShadowWork* w) {
    ReleaseObjTiles(w->unk_08);
    ReleaseObjPalette(w->unk_0C);
}

void task_poo_shadowscale_0(PooScaleWork* w, PooShadowArgs* a) {
    w->unk_10 = a->unk_00;
    w->unk_00 = w->unk_10->unk_00;
    w->unk_04 = w->unk_10->unk_04;
    w->unk_2C = a->unk_08;
    w->unk_08 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_0C = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->unk_14, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(w->unk_14, 0, 1);
    w->unk_30 = AnimUpdate(w->unk_14);
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
    DrawSprite(x, y, w->unk_30, w->unk_08, w->unk_0C, affine, 0x800, 0xFFF0);
}

void task_poo_shadowscale_3(PooScaleWork* w) {
    ReleaseObjTiles(w->unk_08);
    ReleaseObjPalette(w->unk_0C);
}

void func_080CC178(void* pool, void* a, s32 b) {
    PooBalloonArgs args;

    args.unk_00 = a;
    args.unk_08 = b;
    TaskCreate(pool, &gUnk_09EF4958, &args);
}

INCLUDE_ASM("poo/task_poo_freeballoon_0.s");

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

INCLUDE_ASM("poo/task_poo_freeballoon_1.s");

INCLUDE_ASM("poo/task_poo_freeballoon_2.s");

void task_poo_freeballoon_3(PooFreeBalloonWork* w) {
    ReleaseObjTiles(w->unk_48);
    ReleaseObjPalette(w->unk_4C);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
}

#ifdef NON_MATCHING
s32 func_080CC488(u16 x) {
    s32 v;
    u32 a;

    a = x;
    v = 3 - gUnk_0203C3E4;
    if (gUnk_0203C3E0 <= 0x1CD) {
        if ((a / 20) % 2 != 0) {
            if (v <= 2) {
                v++;
            }
        }
    }
    return v;
}
#else
INCLUDE_ASM("poo/func_080CC488.s");
#endif

void task_poo_gauge_0(PooGaugeWork* w) {
    w->unk_12 = 0;
    w->unk_00 = AllocObjTiles(func_08003524(gUnk_09EF5B2C, 4), gUnk_097356F4);
    w->unk_04 = LoadObjPalette(gUnk_09849B98, 0x20);
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
            LoadObjPaletteBank(w->unk_04->unk_06, gUnk_09849BB8);
            w->unk_0C = gUnk_09849BB8;
        }
    }
    if (w->unk_10 == 0) {
        if (w->unk_0C != gUnk_09849B98) {
            LoadObjPaletteBank(w->unk_04->unk_06, gUnk_09849B98);
            w->unk_0C = gUnk_09849B98;
        }
    }
    return 1;
}

void task_poo_gauge_2(PooObjWork3* w) {
    DrawSprite(0xDC, 0x18, w->unk_08, w->unk_00, w->unk_04, 0, 0x400, 0);
}

void task_poo_gauge_3(PooObjWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
}

INCLUDE_ASM("poo/task_poo_trapballoon_0.s");

INCLUDE_ASM("poo/task_poo_trapballoon_1.s");

INCLUDE_ASM("poo/task_poo_trapballoon_2.s");

void task_poo_trapballoon_3(PooBalloonWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_34);
        func_080CCBD4(&w->unk_90);
    }
    TaskPoolDestroy(&w->unk_B0);
}

INCLUDE_ASM("poo/task_poo_owlballoon_0.s");

u8 task_poo_owlballoon_1(PooBalloonWork* w) {
    if (w->unk_04 != 0 && func_08012660(w->unk_34, 9) != 0 && func_080C9D70() != 0) {
        gUnk_0203C3DC = w->unk_24;
        gUnk_0203C3E8 = w->unk_28;
        gUnk_0203C3F0 = 7;
        func_080CCB84(&w->unk_90.unk_00, 0);
        m4aSongNumStart(0x181);
        return 0;
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_owlballoon_2.s");

void task_poo_owlballoon_3(PooBalloonWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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
    func_08000BA4(&gUnk_02034DF8);
}

INCLUDE_ASM("poo/func_080CCBF8.s");

PooNode* func_080CCC98(void) {
    PooNode* best;
    PooNode* n;

    best = (PooNode*)func_08000C8C(&gUnk_02034DF8.head);
    n = best;
    gUnk_02034DF0 = 0;
    while (n != 0) {
        gUnk_02034DF4 = func_080CCBF8(n);
        if (gUnk_02034DF4 > gUnk_02034DF0) {
            gUnk_02034DF0 = gUnk_02034DF4;
            best = n;
        }
        n = (PooNode*)func_08000CD4(&n->unk_0C);
    }
    if (gUnk_02034DF0 == 0 && best == (PooNode*)func_08000C8C(&gUnk_02034DF8.head)) {
        return 0;
    }
    return best;
}

INCLUDE_ASM("poo/task_poo_honey_0.s");

INCLUDE_ASM("poo/task_poo_honey_1.s");

INCLUDE_ASM("poo/task_poo_honey_2.s");

void task_poo_honey_3(PooHoneyWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_74);
        func_080CCBD4(&w->unk_D0);
    }
    TaskPoolDestroy(&w->unk_F4);
}

void task_poo_mapanime_0(PooMapAnimeWork* w) {
    func_080DDDDC(&w->unk_00[0], gUnk_096FD3E8);
    func_080DDDDC(&w->unk_00[1], gUnk_096FD400);
}

#ifdef NON_MATCHING
u8 task_poo_mapanime_1(PooMapAnimeWork* w) {
    u8 r;
    u32 i;

    r = 0;
    for (i = 0; i < 2; i++) {
        r = func_080DDDEC(&w->unk_00[i], w->unk_00[i].unk_08);
    }
    return 1;
}
#else
INCLUDE_ASM("poo/task_poo_mapanime_1.s");
#endif

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

INCLUDE_ASM("poo/task_poo_pile_0.s");

INCLUDE_ASM("poo/task_poo_pile_1.s");

INCLUDE_ASM("poo/task_poo_pile_2.s");

void task_poo_pile_3(PooPileWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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
    TaskCreate(pool, &gUnk_09EF4A00, &args);
}

void task_poo_tigerstump_0(PooStumpWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04 + 0x800;
    w->unk_2C = 0;
    w->unk_04 = 0;
    w->unk_08 = gUnk_097561D4;
    func_08012324(w->unk_34, w->unk_24, w->unk_28, 0);
}

u8 task_poo_tigerstump_1(PooStumpWork* w) {
    if (w->unk_04 != 0) {
        if (func_08012660(w->unk_34, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_tigerstump_2.s");

void task_poo_tigerstump_3(PooStumpWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_34);
    }
}

void task_poo_poohstump_0(PooStumpWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04;
    w->unk_2C = 0;
    w->unk_04 = 0;
    w->unk_08 = gUnk_09755F34;
    func_08012324(w->unk_34, w->unk_24, w->unk_28, 0);
}

u8 task_poo_poohstump_1(PooStumpWork* w) {
    if (w->unk_04 != 0) {
        if (func_08012660(w->unk_34, 9) != 0) {
            gUnk_0203C3DC = w->unk_24;
            gUnk_0203C3E8 = w->unk_28;
            gUnk_0203C3F0 = 8;
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_poohstump_2.s");

void task_poo_poohstump_3(PooStumpWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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

INCLUDE_ASM("poo/task_poo_piglet_0.s");

INCLUDE_ASM("poo/task_poo_piglet_1.s");

INCLUDE_ASM("poo/task_poo_piglet_2.s");

void task_poo_piglet_3(PooPigletWork* w) {
    ReleaseObjTiles(w->unk_00);
    if (w->unk_04 != 0) {
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_38);
    }
    TaskPoolDestroy(&w->unk_94);
}

INCLUDE_ASM("poo/task_poo_eeyore_0.s");

INCLUDE_ASM("poo/task_poo_eeyore_1.s");

INCLUDE_ASM("poo/task_poo_eeyore_2.s");

void task_poo_eeyore_3(PooEeyoreWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
    }
    if (w->unk_AC != 0) {
        func_08012304(w->unk_34);
    }
    TaskPoolDestroy(&w->unk_90);
}

INCLUDE_ASM("poo/task_poo_owl_0.s");

INCLUDE_ASM("poo/task_poo_owl_1.s");

INCLUDE_ASM("poo/task_poo_owl_2.s");

void task_poo_owl_3(PooOwlWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
    }
    TaskPoolDestroy(&w->unk_34);
}

void func_080CE2C4(PooRabbitWork* w, s32 b, u16 c) {
    if (w->unk_A8 != b) {
        w->unk_A8 = b;
        func_08005974(w->unk_0C, gUnk_096FD50C[b].unk_0C, c, gUnk_096FD50C[b].unk_00, gUnk_096FD50C[b].unk_04);
        func_08002A10(w->unk_00, gUnk_096FD50C[b].unk_08);
    }
}

INCLUDE_ASM("poo/task_poo_rabbit_0.s");

INCLUDE_ASM("poo/task_poo_rabbit_1.s");

INCLUDE_ASM("poo/task_poo_rabbit_2.s");

void task_poo_rabbit_3(PooRabbitWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_4C);
    }
    TaskPoolDestroy(&w->unk_38);
}

void func_080CE710(PooTiggerWork* w, u16 b) {
    s32 a;

    func_08005B64(w->unk_0C);
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
        AnimStart(w->unk_0C, a, b);
    }
}

INCLUDE_ASM("poo/func_080CE77C.s");

#ifdef NON_MATCHING
void func_080CE818(PooTiggerWork* w) {
    s32 t[8];

    memcpy(t, gUnk_096FD61C, sizeof(t));
    w->unk_BC = ((PooAnimData**)gUnk_096FD59C[w->unk_26].unk_00)[gUnk_096FD59C[w->unk_26].unk_0C]->unk_08[w->unk_BE].unk_00;
    w->unk_B0 = t[w->unk_BE] - 0x1800;
    w->unk_BE++;
}
#else
INCLUDE_ASM("poo/func_080CE818.s");
#endif

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

INCLUDE_ASM("poo/func_080CE8B4.s");

INCLUDE_ASM("poo/func_080CE960.s");

INCLUDE_ASM("poo/task_poo_tiggerroo_1.s");

INCLUDE_ASM("poo/task_poo_tiggerroo_2.s");

void task_poo_tiggerroo_3(PooTiggerWork* w) {
    if (w->unk_00 != 0) {
        ReleaseObjTiles(w->unk_00);
    }
    if (w->unk_04 != 0) {
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_38);
    }
    TaskPoolDestroy(&w->unk_94);
}

INCLUDE_ASM("poo/task_poo_tiggerroo_0.s");

INCLUDE_ASM("poo/task_poo_roo_0.s");

INCLUDE_ASM("poo/task_poo_roo_1.s");

#ifdef NON_MATCHING
void task_poo_roo_2(PooRooWork* w) {
    s16 x;
    s16 y;
    s32 t;
    s32 pr;

    x = (w->unk_28 >> 8) - gUnk_0203C40C;
    t = w->unk_2C >> 8;
    y = t + (w->unk_30 >> 8) - gUnk_0203C3F8;
    pr = 0x800;
    if (w->unk_24 != 0) {
        pr++;
    }
    DrawSprite(x, y, w->unk_08, w->unk_00, w->unk_04, 0, pr, -0x1006 - t * 4);
    if (w->unk_B4 != 0) {
        TaskPoolDraw(&w->unk_98);
    }
}
#else
INCLUDE_ASM("poo/task_poo_roo_2.s");
#endif

void task_poo_roo_3(PooRooWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
    func_08012304(w->unk_3C);
    TaskPoolDestroy(&w->unk_98);
}

u8 func_080CF114(void) {
    return func_08005AC4((u8*)gUnk_0203C460 + 0x0C);
}

u8 func_080CF12C(void) {
    return AnimIsFinished((u8*)gUnk_0203C460 + 0x0C);
}

void task_poo_roo_footmark_0(PooFootmarkWork* w) {
    w->unk_0C = 0x4A700;
    w->unk_10 = 0x28E00;
    w->unk_14 = 0;
    w->unk_00 = LoadObjTiles(gUnk_09755A34, 0x500);
    w->unk_04 = 0;
    if (func_080D2D50(5) == 0) {
        w->unk_08 = gUnk_097559F4;
    } else {
        w->unk_08 = gUnk_09755A04;
    }
}

u8 task_poo_roo_footmark_1(void* w) {
    return 1;
}

INCLUDE_ASM("poo/task_poo_roo_footmark_2.s");

void task_poo_roo_footmark_3(PooFootmarkWork* w) {
    ReleaseObjTiles(w->unk_00);
    if (w->unk_04 != 0) {
        ReleaseObjPalette(w->unk_04);
        func_080CCBD4(&w->unk_1C);
    }
}

INCLUDE_ASM("poo/task_poo_leaf_0.s");

u8 task_poo_leaf_1(PooLeafWork* w) {
    if (w->unk_04 != 0 && (w->unk_62 & 2) != 0 && w->unk_90 == 0) {
        w->unk_90 = 1;
        func_08005B64(w->unk_0C);
        m4aSongNumStart(0xE0);
        if (func_080D2C1C(w->unk_94) == 0) {
            if (func_080C7BF8(2, 3, w->unk_24 + 0x1C00, w->unk_28 + 0x2000, w->unk_2C) != 0) {
                func_080D2BF8(w->unk_94);
            }
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_leaf_2.s");

void task_poo_leaf_3(PooLeafWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_34);
    }
}

INCLUDE_ASM("poo/task_poo_tanpopo_0.s");

INCLUDE_ASM("poo/task_poo_tanpopo_1.s");

INCLUDE_ASM("poo/task_poo_tanpopo_2.s");

void task_poo_tanpopo_3(PooTanpopoWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjPalette(w->unk_04);
        ReleaseObjTiles(w->unk_00);
        ReleaseObjTiles(w->unk_24);
        func_08012304(w->unk_54);
    }
}

void task_poo_ti_board_0(PooBoardWork* w, PooPos* p) {
    w->unk_0C = p->unk_00;
    w->unk_10 = p->unk_04;
    w->unk_14 = 0;
    w->unk_00 = LoadObjTiles(gUnk_097565FC, 0x200);
    w->unk_04 = 0;
    w->unk_08 = gUnk_097565E8;
    func_08012324(w->unk_1C, w->unk_0C, w->unk_10, w->unk_14);
}

u8 task_poo_ti_board_1(PooBoardWork* w) {
    if (w->unk_04 != 0) {
        if (func_08012660(w->unk_1C, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_ti_board_2.s");

void task_poo_ti_board_3(PooBoardWork* w) {
    ReleaseObjTiles(w->unk_00);
    if (w->unk_04 != 0) {
        ReleaseObjPalette(w->unk_04);
        func_08012304(w->unk_1C);
    }
}

void task_poo_eeyoretail_0(PooEeyoreTailWork* w) {
    w->unk_0C = 0x7CD00;
    w->unk_10 = 0x49E00;
    w->unk_14 = -0x2000;
    w->unk_18 = 0;
    w->unk_1C = func_08003524(gUnk_09EF5D68, 0x10);
    w->unk_04 = 0;
    w->unk_08 = gUnk_09744842;
    TaskPoolInit(&w->unk_24, 1);
    func_080CC178(&w->unk_24, &w->unk_0C, 0x66);
    gUnk_02034E18 = 0x1E;
    w->unk_20 = -w->unk_14;
}

u8 task_poo_eeyoretail_1(PooEeyoreTailWork* w) {
    if (func_080C9D84() != 0) {
        if (gUnk_02034E18 != 0) {
            func_080058FC(&w->unk_0C, 0x7FD00, gUnk_02034E18);
            func_080058FC(&w->unk_10, 0x49300, gUnk_02034E18);
            func_080058FC(&w->unk_20, 0, gUnk_02034E18);
            w->unk_14 = -w->unk_20;
            gUnk_02034E18--;
            func_080C9FA8(w->unk_0C, w->unk_10 + w->unk_14);
        }
        TaskPoolUpdate(&w->unk_24);
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_eeyoretail_2.s");

void task_poo_eeyoretail_3(PooEeyoreTailWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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
    w->unk_04 = 0;
    w->unk_08 = gUnk_097567FC;
    func_08012324(w->unk_38, w->unk_24, w->unk_28, 0);
    w->unk_9C = 0;
    gUnk_02034E1C = 0;
    w->unk_98 = 0;
    w->unk_96 = 0;
}

INCLUDE_ASM("poo/task_poo_honeycomb_1.s");

INCLUDE_ASM("poo/task_poo_honeycomb_2.s");

void task_poo_honeycomb_3(PooHoneycombWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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
    w->unk_04 = 0;
    w->unk_08 = gUnk_09756C50;
    func_08012324(w->unk_38, w->unk_24, w->unk_28, w->unk_2C);
}

u8 task_poo_vegetable_1(PooVegetableWork* w) {
    if (w->unk_04 != 0) {
        if (func_08012660(w->unk_38, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_vegetable_2.s");

void task_poo_vegetable_3(PooVegetableWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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
    if (gUnk_0203C420.unk_08 < 0) {
        return 0;
    }
    return func_080CFE34(&gUnk_0203C420);
}

u8 func_080CFF30(void) {
    if (gUnk_0203C420.unk_08 < -0x2000) {
        return 0;
    }
    return func_080CFE34(&gUnk_0203C420);
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
    func_080058FC(a, d + gUnk_02034E20->unk_1C.unk_00, c);
    func_080058FC(b, e + gUnk_02034E20->unk_1C.unk_04, c);
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

INCLUDE_ASM("poo/func_080D0050.s");

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

INCLUDE_ASM("poo/task_poo_wagon_1.s");

INCLUDE_ASM("poo/task_poo_wagon_2.s");

void task_poo_wagon_3(PooWagonWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjTiles(w->unk_0C);
        ReleaseObjTiles(w->unk_14);
        ReleaseObjPalette(w->unk_04);
    }
}

u16 func_080D06BC(void) {
    return gUnk_02034E24;
}

u16 func_080D06C8(void) {
    return gUnk_02034E26;
}

INCLUDE_ASM("poo/task_poo_wagonwheel_0.s");

u8 task_poo_wagonwheel_1(PooWheelWork* w) {
    if (w->unk_36 == 2 && func_080D2D50(6) != 0) {
        w->unk_36 = 3;
        AnimStart(w->unk_0C, 3, 1);
    }
    if (w->unk_36 == 3) {
        w->unk_08 = AnimUpdate(w->unk_0C);
        if (w->unk_38 <= 0x4FF) {
            w->unk_38 += 6;
        }
        w->unk_28 += w->unk_38;
        w->unk_24 += w->unk_38;
        if (w->unk_24 > w->unk_3C + 0x4800) {
            w->unk_24 = w->unk_3C + 0x4800;
        }
    }
    if (w->unk_40 != 0 && w->unk_04 == 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_wagonwheel_2.s");

void task_poo_wagonwheel_3(PooWheelWork* w) {
    if (func_080D2D50(6) != 0) {
        func_080D2CE0(w->unk_24 >> 8, w->unk_28 >> 8);
    }
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
    }
}

void task_poo_spark_0(PooSparkWork* w, PooPos* p) {
    w->unk_00 = *p;
    w->unk_28 = AllocObjTiles(0x200, gUnk_098A4B68);
    w->unk_2C = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->unk_10, gUnk_09EF8CC0, gUnk_09EF8CA0);
    AnimStart(w->unk_10, 0, 1);
}

u8 task_poo_spark_1(PooSparkWork* w) {
    AnimUpdate(w->unk_10);
    if (AnimIsFinished(w->unk_10) != 0) {
        return 0;
    }
    return 1;
}

void task_poo_spark_2(PooSparkWork* w) {
    u16 x;
    u16 y;

    x = (w->unk_00.unk_00 >> 8) - gUnk_0203C40C;
    y = (w->unk_00.unk_04 >> 8) + (w->unk_00.unk_08 >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, AnimGetGfx(w->unk_10), w->unk_28, w->unk_2C, 0, 0x400, 0x50);
}

void task_poo_spark_3(PooSparkWork* w) {
    ReleaseObjTiles(w->unk_28);
    ReleaseObjPalette(w->unk_2C);
}

INCLUDE_ASM("poo/task_poo_bee_0.s");

INCLUDE_ASM("poo/task_poo_bee_1.s");

INCLUDE_ASM("poo/task_poo_bee_2.s");

INCLUDE_ASM("poo/task_poo_bee_3.s");

u8 func_080D1050(void) {
    if (func_080D2D50(2) != 0) {
        if (gUnk_02034E30->unk_08 != 0) {
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

INCLUDE_ASM("poo/task_poo_cabbage_0.s");

INCLUDE_ASM("poo/task_poo_cabbage_1.s");

INCLUDE_ASM("poo/task_poo_cabbage_2.s");

void task_poo_cabbage_3(PooCabbageWork* w) {
    if (w->unk_04 != 0) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjPalette(w->unk_04);
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
        TaskCreate(&w->unk_00, &gUnk_09EF4C10, 0);
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

INCLUDE_ASM("poo/func_080D172C.s");

INCLUDE_ASM("poo/func_080D1990.s");

INCLUDE_ASM("poo/task_poo_prize_0.s");

u8 task_poo_prize_1(PooPrizeWork* w) {
    if (w->unk_7C != 0) {
        w->unk_7C(w);
        if (w->unk_7C != 0) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("poo/task_poo_prize_2.s");

void task_poo_prize_3(PooPrizeWork* w) {
    ReleaseObjTiles(w->unk_6C);
    ReleaseObjPalette(w->unk_70);
    func_08012304(w->unk_10);
}

void task_poo_zzz_0(PooZzzWork* w, u8* arg) {
    w->unk_24 = gUnk_0203C3EC;
    w->unk_00 = AllocObjTiles(0x100, gUnk_097257D8);
    w->unk_04 = LoadObjPalette(gUnk_09849A98, 0x20);
    AnimInit(w->unk_0C, gUnk_09EF5904, gUnk_09EF5844);
    if (*arg != 0) {
        AnimStart(w->unk_0C, 8, 1);
    } else {
        AnimStart(w->unk_0C, 7, 1);
    }
    w->unk_08 = AnimGetGfx(w->unk_0C);
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
        g = AnimUpdate(w->unk_0C);
        w->unk_08 = g;
        DrawSprite(x, y, g, w->unk_00, w->unk_04, 0, 0x400, 0x0B);
    }
}

void task_poo_zzz_3(PooZzzWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
}

INCLUDE_ASM("poo/func_080D1FB8.s");

void func_080D2034(PooBflyPart* p) {
    const PooZzzDesc* d;

    func_080D1FB8(p);
    d = &gUnk_09EF4C88[p->unk_4C];
    func_08005974(p->unk_08, d->unk_0C, 1, d->unk_04, d->unk_00);
    func_08002A10(p->unk_00, d->unk_08);
}

void func_080D206C(PooBflyPart* p) {
    if ((s8)p->unk_48 >= 0) {
        p->unk_40 = p->unk_38;
        p->unk_44 = p->unk_3C;
    } else {
        p->unk_40 = p->unk_30;
        p->unk_44 = p->unk_34;
    }
    p->unk_00 = AllocObjTiles(0x40, 0);
    AnimInit(p->unk_08, 0, 0);
    func_080D2034(p);
    p->unk_04 = AnimGetGfx(p->unk_08);
}

INCLUDE_ASM("poo/task_poo_butterfly_0.s");

void func_080D2190(PooBflyPart* p) {
    if (p->unk_52 != 0) {
        func_080058FC(&p->unk_20, p->unk_40, p->unk_52);
        func_080058FC(&p->unk_24, p->unk_44, p->unk_52);
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
    p->unk_04 = AnimUpdate(p->unk_08);
}

u8 task_poo_butterfly_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[0]);
    func_080D2190(&w->unk_00[1]);
    return 1;
}

INCLUDE_ASM("poo/func_080D220C.s");

void task_poo_butterfly_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[0], w->unk_D0);
    func_080D220C(&w->unk_00[1], w->unk_D0);
}

void task_poo_butterfly_3(PooButterflyWork* w) {
    ReleaseObjTiles(w->unk_00[0].unk_00);
    ReleaseObjTiles(w->unk_00[1].unk_00);
    ReleaseObjPalette(w->unk_D0);
}

u8 func_080D22F4(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[1]);
    return 1;
}

void func_080D2304(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[1], w->unk_D0);
}

u8 func_080D2318(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[0]);
    return 1;
}

void func_080D2324(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[0], w->unk_D0);
}

void task_poo_mapbee_0(PooMapBeeWork* w, PooPos* p) {
    w->unk_24 = p->unk_00;
    w->unk_28 = p->unk_04;
    w->unk_2C = 0;
    w->unk_00 = AllocObjTiles(func_08003524(gUnk_09EF6158, 1), gUnk_097606E8);
    w->unk_04 = LoadObjPalette(gUnk_09849E38, 0x20);
    AnimInit(w->unk_0C, gUnk_09EF6200, gUnk_09EF6158);
    AnimStart(w->unk_0C, 0, 0);
    w->unk_08 = AnimGetGfx(w->unk_0C);
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
            if (AnimIsFinished(w->unk_0C) != 0) {
                AnimStart(w->unk_0C, 1, 1);
                w->unk_36 = 1;
            }
            break;
        case 1:
            w->unk_2C -= 0xCC;
            break;
    }
    w->unk_08 = AnimUpdate(w->unk_0C);
    return 1;
}

INCLUDE_ASM("poo/task_poo_mapbee_2.s");

void task_poo_mapbee_3(PooObjWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
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
            if (func_08000F48(w->unk_94) == 0 && w->unk_99 != 0) {
                w->unk_99 = 0;
                w->unk_94 = TaskCreate(&w->unk_80, &gUnk_09EF4D20, &w->unk_10);
            }
        } else {
            w->unk_99 = 1;
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_mapbeeborn_2.s");

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
    w->unk_00 = AllocObjTiles(0x40, gUnk_09760986);
    w->unk_04 = LoadObjPalette(gUnk_09849E58, 0x20);
    AnimInit(w->unk_0C, gUnk_09EF6298, gUnk_09EF6208);
    AnimStart(w->unk_0C, 0, 0);
    w->unk_08 = AnimGetGfx(w->unk_0C);
    w->unk_34 = 1;
}

u8 task_poo_mapbutterfly_1(PooMapButterflyWork* w) {
    if (w->unk_34 == 0) {
        return 0;
    }
    w->unk_2C -= 0x80;
    w->unk_08 = AnimUpdate(w->unk_0C);
    return 1;
}

INCLUDE_ASM("poo/task_poo_mapbutterfly_2.s");

void task_poo_mapbutterfly_3(PooObjWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
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
            if (func_08000F48(w->unk_94) == 0 && w->unk_99 != 0) {
                w->unk_99 = 0;
                w->unk_94 = TaskCreate(&w->unk_80, &gUnk_09EF4D50, &w->unk_10);
            }
        } else {
            w->unk_99 = 1;
        }
    }
    return 1;
}

INCLUDE_ASM("poo/task_poo_mapbutterflyborn_2.s");

INCLUDE_ASM("poo/task_poo_mapbutterflyborn_3.s");

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
    return 0xB4;
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
    RequestDma3Copy(gUnk_096FDA8C[gUnk_02039BB0.unk_0C].unk_00, (u8*)GetBgScreenBase(2) + 0x200, 0x300);
    RequestDma3Copy(gUnk_096FDA8C[gUnk_02039BB0.unk_0C].unk_04, (u8*)GetBgCharBase(2) + 0x2000, 0x2000);
    LoadPalette(gUnk_096FDA8C[gUnk_02039BB0.unk_0C].unk_08, (void*)0x05000140, 0x20);
}

void func_080D313C(void) {
    u8* src;
    void* dst;

    dst = (u8*)GetBgCharBase(2) + 0x20;
    if ((gUnk_02039BB0.unk_08 & 8) != 0) {
        src = &gUnk_097B8258[gUnk_02039BB0.unk_0E * 0x140];
    } else {
        src = &gUnk_097B7218[gUnk_02039BB0.unk_0E * 0x140];
    }
    RequestDma3Copy(src, dst, 0x140);
    dst = (u8*)GetBgScreenBase(2) + 0x480;
    src = gUnk_0983BC18;
    RequestDma3Copy(src, dst, 10);
    dst = (u8*)GetBgScreenBase(2) + 0x4C0;
    src += 0x40;
    RequestDma3Copy(src, dst, 10);
}
