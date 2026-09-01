#include "macros.h"
#include "btl.h"

void task_btl_lockon_0(BtlLockonWork* work) {
    work->unk_000 = LoadObjTiles(gUnk_08B1D8BC, 0x180);
    work->unk_004 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->unk_008, gUnk_09EE10F8, gUnk_09EE10EC);
    AnimStart(&work->unk_008, 0, 1);
    work->unk_020 = AnimGetGfx(&work->unk_008);
    work->unk_024 = 0;
    gUnk_02039B84->unk_078 = 0;
}

INCLUDE_ASM("btl/func_0801D288.s");

u8 task_btl_lockon_1(BtlLockonWork* work) {
    if ((gUnk_02039B84->unk_068 & 0x20000000) == 0) {
        func_0801D288();
    }
    if (gUnk_02039B84->unk_078 != 0) {
        work->unk_020 = AnimUpdate(&work->unk_008);
        if (gUnk_02039B84->unk_078->unk_034 & 0x1000000) {
            gUnk_02039B84->unk_078 = 0;
        }
    }
    if (work->unk_024 != 0) {
        work->unk_024--;
    }
    return 1;
}

void task_btl_lockon_2(BtlLockonWork* work) {
    BtlWork* e;
    s16 x;
    s16 y;

    e = gUnk_02039B84->unk_078;
    if (e != 0) {
        WorldToScreen(&x, &y, e->unk_004 + (e->unk_0A4 << 8), e->unk_008,
                      e->unk_00C - (e->unk_0A2 << 8));
        DrawSprite(x, y, work->unk_020, work->unk_000, work->unk_004, 0, 16, 16);
    }
}

void task_btl_lockon_3(BtlLockonWork* work) {
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

void task_btl_area_0(BtlAreaWork* work) {
    work->unk_008 = 0;
    work->unk_000 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_004 = LoadObjTiles(gUnk_08B1EA00, 0xE0);
    work->unk_00A = 0;
    work->unk_009 = 1;
}

u8 task_btl_area_1(BtlAreaWork* work) {
    if (work->unk_009 == 0) {
        work->unk_008 = 0;
        return 1;
    }
    if (gUnk_02039B84->unk_0B4 != 0) {
        work->unk_00A = 20;
        gUnk_02039B84->unk_0B4 = 0;
    }
    if (work->unk_00A > 0) {
        work->unk_008 = 1;
    } else {
        work->unk_008 = 0;
    }
    if (work->unk_00A > 0) {
        work->unk_00A--;
    }
    return 1;
}

INCLUDE_ASM("btl/task_btl_area_2.s");

void task_btl_area_3(BtlAreaWork* work) {
    ReleaseObjTiles(work->unk_004);
    ReleaseObjPalette(work->unk_000);
}

void func_0801DC40(BtlSoraWork* work) {
    u16 a = work->unk_15A | 0x80;
    u16 b;

    work->unk_15A = a;
    b = work->unk_040.unk_70 | 2;
    work->unk_040.unk_70 = b;
}

void func_0801DC5C(BtlSoraWork* work) {
    u16 a = work->unk_15A & 0xFF7F;
    u16 b;

    work->unk_15A = a;
    b = work->unk_040.unk_70 & 0xFFFD;
    work->unk_040.unk_70 = b;
}

u16 func_0801DC80(BtlSoraWork* work) {
    BtlWork* a;
    BtlWork* b;
    s32 d;

    a = work->unk_040.unk_E4->unk_07C;
    b = work->unk_040.unk_E4->unk_078;
    if (work->unk_040.unk_E4->unk_068 & 0x8000) {
        return 3;
    }
    if (b == 0) {
        return 0;
    }
    if (a->unk_00C - b->unk_00C > 0x2000) {
        return 2;
    }
    d = b->unk_004 - a->unk_004;
    if (d >= 0 ? d > 0x2800 : a->unk_004 - b->unk_004 > 0x2800) {
        return 1;
    }
    d = b->unk_008 - a->unk_008;
    if (d >= 0 ? d > 0xC00 : a->unk_008 - b->unk_008 > 0xC00) {
        return 4;
    }
    return 0;
}

void func_0801DD08(BtlSoraWork* work) {
    BtlWork* c;
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_172 == 0) {
        return;
    }
    c = work->unk_040.unk_E4->unk_078;
    if (c != 0) {
        if (gUnk_02039B84->unk_068 & 0x4000) {
            x = (work->unk_040.unk_04 + c->unk_004) >> 1;
            x = (work->unk_040.unk_04 + x) >> 1;
            y = work->unk_040.unk_08;
            z = work->unk_040.unk_0C;
            if (z < -0x3200) {
                z = -0x3200;
            }
        } else {
            x = (work->unk_040.unk_04 + c->unk_004) >> 1;
            y = (work->unk_040.unk_08 + c->unk_008) >> 1;
            z = (work->unk_040.unk_0C + c->unk_00C) >> 1;
        }
        func_0802F284(x, y, z);
    } else {
        func_0802F284(work->unk_040.unk_04, work->unk_040.unk_08, work->unk_040.unk_0C);
    }
}

void func_0801DD90(BtlSoraWork* work) {
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_172 != 0) {
        func_080140C0(&x, &y, &z);
        func_0802F284(x, gUnk_02039B84->unk_07C->unk_008, gUnk_02039B84->unk_07C->unk_00C);
    }
}

void func_0801DDC4(BtlSoraWork* work) {
    if (work->unk_172 != 0) {
        func_0802F284(work->unk_040.unk_04, work->unk_040.unk_08, work->unk_040.unk_0C);
    }
}

void func_0801DDE4(BtlSoraWork* work, u16 a, u16 b) {
    FldAnimDef* e;

    e = &gUnk_0813BA2C[a];
    func_08005974(&work->unk_00C, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_0801DE1C(BtlSoraWork* work, u16 a, u16 b) {
    FldAnimDef* e;
    s32 idx;

    idx = 0;
    switch (((work->unk_160 + 16) & 0xFF) >> 5) {
    case 0:
        idx = 1;
        break;
    case 4:
        idx = 0;
        break;
    case 3:
    case 5:
        idx = 2;
        break;
    case 2:
    case 6:
        idx = 3;
        break;
    case 1:
    case 7:
        idx = 4;
        break;
    }
    e = &gUnk_0813BEFC[a][idx];
    func_08005974(&work->unk_00C, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_0801DEB8(BtlSoraWork* work) {
    work->unk_000 = work->unk_040.unk_E4->unk_110;
    if (work->unk_172 != 0) {
        work->unk_004 = LoadObjPalette(gUnk_08F683A4, 0x20);
    } else {
        work->unk_004 = LoadObjPalette(gUnk_096FAC64, 0x20);
    }
}

void func_0801DEF4(BtlSoraWork* work) {
    if (work->unk_004 != 0) {
        ReleaseObjPalette(work->unk_004);
    }
    work->unk_000 = 0;
    work->unk_004 = 0;
}

void func_0801DF10(BtlSoraWork* work, u16 a) {
    UnkStruct_0801AF08* p;

    p = &work->unk_040;
    if ((a & 0x10) && (a & 0x40)) {
        work->unk_160 = 0x20;
        p->unk_34 &= ~4;
    } else if ((a & 0x10) && (a & 0x80)) {
        work->unk_160 = 0x60;
        p->unk_34 &= ~4;
    } else if ((a & 0x20) && (a & 0x80)) {
        work->unk_160 = 0xA0;
        p->unk_34 |= 4;
    } else if ((a & 0x20) && (a & 0x40)) {
        work->unk_160 = 0xE0;
        p->unk_34 |= 4;
    } else if (a & 0x40) {
        work->unk_160 = 0;
    } else if (a & 0x10) {
        work->unk_160 = 0x40;
        p->unk_34 &= ~4;
    } else if (a & 0x80) {
        work->unk_160 = 0x80;
    } else if (a & 0x20) {
        work->unk_160 = 0xC0;
        p->unk_34 |= 4;
    }
    if (a & 0xF0) {
        func_0801DE1C(work, 0, 1);
        if (work->unk_00C.unk_0A == 0) {
            switch (work->unk_00C.unk_0E) {
            case 3:
                m4aSongNumStart(work->unk_184[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_184[1]);
                break;
            }
        }
    } else {
        func_0801DDE4(work, 1, 1);
    }
    if (a & 0xF0) {
        if (p->unk_E4->unk_0F4 == 50) {
            work->unk_15C += 256;
            if (work->unk_15C > 1024) {
                work->unk_15C = 1024;
            }
        } else {
            work->unk_15C += 128;
            if (work->unk_15C > 614) {
                work->unk_15C = 614;
            }
        }
    } else {
        work->unk_15C -= 128;
        if (work->unk_15C < 0) {
            work->unk_15C = 0;
        }
    }
}

INCLUDE_ASM("btl/task_btl_sora_0.s");

void func_0801E4E4(BtlSoraWork* work, u32 a) {
    work->unk_038 = a;
    work->unk_156 = 0;
    work->unk_154 = 0;
    func_0801AF08(&work->unk_040);
}

void func_0801E508(BtlSoraWork* work, u32 a) {
    work->unk_038 = a;
    func_0801AF08(&work->unk_040);
}

void func_0801E518(BtlSoraWork* work) {
    u16 t;

    if (work->unk_038 == 16 && work->unk_161 <= 1) {
        work->unk_161++;
        work->unk_154 = 0;
        work->unk_156 = 0;
    } else {
        switch (func_0801DC80(work)) {
        case 0:
            work->unk_164 = gUnk_0813C1D4;
            work->unk_168 = gUnk_0813C1EC;
            work->unk_16C = gUnk_0813C21C;
            break;
        case 1:
            work->unk_164 = gUnk_0813C1EC;
            work->unk_168 = gUnk_0813C1D4;
            work->unk_16C = gUnk_0813C21C;
            break;
        case 2:
            work->unk_164 = gUnk_0813C24C;
            work->unk_168 = gUnk_0813C264;
            work->unk_16C = gUnk_0813C27C;
            break;
        case 3:
            work->unk_164 = gUnk_0813C234;
            work->unk_168 = gUnk_0813C24C;
            work->unk_16C = gUnk_0813C27C;
            break;
        case 4:
        default:
            work->unk_164 = gUnk_0813C204;
            work->unk_168 = gUnk_0813C1EC;
            work->unk_16C = gUnk_0813C21C;
            break;
        }
        work->unk_038 = 16;
        work->unk_156 = 0;
        work->unk_154 = 0;
        work->unk_161 = 0;
        t = work->unk_15A & 0xFFBF;
        work->unk_15A = t;
    }
    if (work->unk_040.unk_E4->unk_0F4 == 44) {
        work->unk_190 = 0;
    }
}

void func_0801E678(BtlSoraWork* work) {
    work->unk_150 = -work->unk_040.unk_AC * 3;
    work->unk_148 = ((gSineTable[work->unk_040.unk_B0] << 1) * work->unk_040.unk_A8) >> 8;
    work->unk_14C = ((-gSineTable[work->unk_040.unk_B0 + 0x40] << 1) * work->unk_040.unk_A8) >> 8;
}

BtlWork* func_0801E6DC(BtlSoraWork* work) {
    BtlWork* list[10];
    BtlWork* e;
    s16 n;

    if (work->unk_040.unk_E4->unk_078 != 0) {
        return work->unk_040.unk_E4->unk_078;
    }
    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_172 != 0) {
            e = gUnk_02039B9C->unk_07C;
        } else {
            e = gUnk_02039B84->unk_07C;
        }
        if (e->unk_02C <= 0) {
            return 0;
        }
        return e;
    }
    n = 0;
    e = func_08000C8C(&gUnk_02039B84->unk_080);
    if (e != 0) {
        list[0] = e;
        n = 1;
        do {
            e = func_08000CD4(&e->unk_0B8);
            if (e == 0) {
                break;
            }
            list[n] = e;
            n++;
        } while (n <= 9);
    }
    if (n == 0) {
        return 0;
    }
    e = list[GetRandom() % n];
    return e;
}

u16 func_0801E794(u16 a, u16 b, u16 c) {
    u16 d;

    d = b;
    if (a & b) {
        if ((a & c) == 0) {
            a &= ~b;
        }
        a |= c;
    } else if (a & c) {
        a &= ~c;
        a |= d;
    }
    return a;
}

BtlWork* func_0801E7D4(BtlSoraWork* work) {
    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_172 != 0) {
            if (gUnk_02039B84->unk_068 & 0x40) {
                return gUnk_02039B9C->unk_07C;
            }
        } else {
            if (gUnk_02039B84->unk_068 & 0x20000000) {
                return gUnk_02039B84->unk_07C;
            }
        }
    } else {
        if (gUnk_02039B84->unk_068 & 0x40) {
            return gUnk_02039B84->unk_0A8;
        }
    }
    return 0;
}

INCLUDE_ASM("btl/task_btl_sora_1.s");
INCLUDE_ASM("btl/task_btl_sora_2.s");

void task_btl_sora_3(BtlSoraWork* work) {
    UnkStruct_0801AF08* p;

    p = &work->unk_040;
    m4aSongNumStop(590);
    if (!(gUnk_02039B84->unk_068 & 0x4000)) {
        if (*(s32*)&gUnk_02039B84->unk_0A0 == 3) {
            gUnk_02039BB0.unk_032 = gUnk_02039BB0.unk_0F8;
        } else {
            gUnk_02039BB0.unk_032 = p->unk_2C;
        }
    }
    func_08012304(&p->unk_40);
    func_0801DEF4(work);
    TaskPoolDestroy(&work->unk_024);
}

void func_08027428(BtlRikuWork* work) {
    u16 a = work->unk_15E | 0x80;
    u16 b;

    work->unk_15E = a;
    b = work->unk_044.unk_70 | 2;
    work->unk_044.unk_70 = b;
}

void func_08027444(BtlRikuWork* work) {
    u16 a = work->unk_15E & 0xFF7F;
    u16 b;

    work->unk_15E = a;
    b = work->unk_044.unk_70 & 0xFFFD;
    work->unk_044.unk_70 = b;
}

u16 func_08027468(BtlRikuWork* work) {
    BtlWork* a;
    BtlWork* b;
    s32 d;

    a = work->unk_044.unk_E4->unk_07C;
    b = work->unk_044.unk_E4->unk_078;
    if (work->unk_044.unk_E4->unk_068 & 0x8000) {
        return 3;
    }
    if (b == 0) {
        return 0;
    }
    if (a->unk_00C - b->unk_00C > 0x2000) {
        return 2;
    }
    d = b->unk_004 - a->unk_004;
    if (d >= 0 ? d > 0x2800 : a->unk_004 - b->unk_004 > 0x2800) {
        return 1;
    }
    d = b->unk_008 - a->unk_008;
    if (d >= 0 ? d > 0xC00 : a->unk_008 - b->unk_008 > 0xC00) {
        return 4;
    }
    return 0;
}

void func_080274F0(BtlRikuWork* work) {
    BtlWork* c;

    if (work->unk_178 == 0) {
        return;
    }
    c = work->unk_044.unk_E4->unk_078;
    if (c != 0) {
        func_0802F284((work->unk_044.unk_04 + c->unk_004) >> 1, (work->unk_044.unk_08 + c->unk_008) >> 1,
                      (work->unk_044.unk_0C + c->unk_00C) >> 1);
    } else {
        func_0802F284(work->unk_044.unk_04, work->unk_044.unk_08, work->unk_044.unk_0C);
    }
}

void func_0802753C(BtlRikuWork* work) {
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_178 != 0) {
        func_080140C0(&x, &y, &z);
        func_0802F284(x, gUnk_02039B84->unk_07C->unk_008, gUnk_02039B84->unk_07C->unk_00C);
    }
}

void func_08027570(BtlRikuWork* work, BtlDrawInfo* out) {
    UnkStruct_0801AF08* a;

    a = &work->unk_044;
    out->unk_00 = a->unk_04;
    out->unk_04 = a->unk_08;
    out->unk_08 = a->unk_0C;
    if (a->unk_34 & 4) {
        out->unk_0C |= 1;
    } else {
        out->unk_0C &= 0xFFFE;
    }
    out->unk_10 = work->unk_010;
    out->unk_28 = *(void**)work->unk_000;
    out->unk_2C = gUnk_02039B84->unk_024;
}

void func_080275D4(BtlRikuWork* work, BtlDrawInfo* out) {
    UnkStruct_0801AF08* a;
    void* gfx;
    u16 flags;
    s32 affine;
    s32 p;
    s32 q;
    s16 x;
    s16 y;
    s32 z;
    s32 v;

    gfx = AnimGetGfx(&out->unk_10);
    a = &work->unk_044;
    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(6, 12);
        flags = 0x804;
    } else {
        flags = func_0801AF1C(a->unk_08);
    }
    if (out->unk_0C & 1) {
        p = out->unk_2C;
        q = p;
    } else {
        p = out->unk_2C;
        if (p == 256) {
            q = p;
            flags |= 1;
        } else {
            v = gUnk_02039B84->unk_024;
            q = -v;
            p = v;
        }
    }
    if (p == 256 && q == p) {
        affine = 0;
    } else if (p <= 255) {
        affine = AllocObjAffine(0, q, p, 0);
    } else {
        affine = AllocObjAffine(0, q, p, 1);
    }
    z = 0xFFF0;
    WorldToScreen(&x, &y, out->unk_00, out->unk_04, out->unk_08);
    func_08002A10(work->unk_004, out->unk_28);
    DrawSprite(x, y, gfx, work->unk_004, work->unk_008, affine, flags, z);
}

void func_080276D4(BtlRikuWork* work, u16 a, u16 b) {
    FldAnimDef* e;

    e = &gUnk_0813C2AC[a];
    func_08005974(&work->unk_010, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_0802770C(BtlRikuWork* work, u16 a, u16 b) {
    FldAnimDef* e;
    s32 idx;

    idx = 0;
    switch (((work->unk_164 + 16) & 0xFF) >> 5) {
    case 0:
        idx = 1;
        break;
    case 4:
        idx = 0;
        break;
    case 3:
    case 5:
        idx = 2;
        break;
    case 2:
    case 6:
        idx = 3;
        break;
    case 1:
    case 7:
        idx = 4;
        break;
    }
    e = &gUnk_0813C4DC[a][idx];
    func_08005974(&work->unk_010, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_080277A8(BtlRikuWork* work) {
    work->unk_000 = work->unk_044.unk_E4->unk_110;
    if (work->unk_178 != 0) {
        work->unk_008 = LoadObjPalette(work->unk_1AC, 0x20);
    } else {
        work->unk_008 = LoadObjPalette(gUnk_096FAC64, 0x20);
    }
}

void func_080277E4(BtlRikuWork* work) {
    ReleaseObjPalette(work->unk_008);
    work->unk_000 = 0;
    work->unk_008 = 0;
}

INCLUDE_ASM("btl/func_080277FC.s");

void func_08027A64(BtlRikuWork* work, u16 a) {
    UnkStruct_0801AF08* p;

    p = &work->unk_044;
    if ((a & 0x10) && (a & 0x40)) {
        work->unk_164 = 0x20;
        p->unk_34 &= ~4;
    } else if ((a & 0x10) && (a & 0x80)) {
        work->unk_164 = 0x60;
        p->unk_34 &= ~4;
    } else if ((a & 0x20) && (a & 0x80)) {
        work->unk_164 = 0xA0;
        p->unk_34 |= 4;
    } else if ((a & 0x20) && (a & 0x40)) {
        work->unk_164 = 0xE0;
        p->unk_34 |= 4;
    } else if (a & 0x40) {
        work->unk_164 = 0;
    } else if (a & 0x10) {
        work->unk_164 = 0x40;
        p->unk_34 &= ~4;
    } else if (a & 0x80) {
        work->unk_164 = 0x80;
    } else if (a & 0x20) {
        work->unk_164 = 0xC0;
        p->unk_34 |= 4;
    }
    if (a & 0xF0) {
        func_080276D4(work, 13, 1);
        if (work->unk_010.unk_0A == 0) {
            switch (work->unk_010.unk_0E) {
            case 3:
                m4aSongNumStart(work->unk_188[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_188[1]);
                break;
            }
        }
    } else {
        func_080276D4(work, 12, 1);
    }
    if (a & 0xF0) {
        if (p->unk_E4->unk_0F4 == 50) {
            work->unk_160 += 256;
            if (work->unk_160 > 768) {
                work->unk_160 = 768;
            }
        } else {
            work->unk_160 += 128;
            if (work->unk_160 > 640) {
                work->unk_160 = 640;
            }
        }
    } else {
        work->unk_160 -= 128;
        if (work->unk_160 < 0) {
            work->unk_160 = 0;
        }
    }
}

INCLUDE_ASM("btl/task_btl_riku_0.s");

void func_080280BC(BtlRikuWork* work, u32 a) {
    work->unk_03C = a;
    work->unk_15A = 0;
    work->unk_158 = 0;
    func_0801AF08(&work->unk_044);
}

void func_080280E0(BtlRikuWork* work) {
    u16 t;

    if (work->unk_03C == 9 && work->unk_165 <= 1) {
        work->unk_165++;
        work->unk_158 = 0;
        work->unk_15A = 0;
    } else {
        switch (func_08027468(work)) {
        case 0:
            work->unk_168 = gUnk_0813C6E8;
            work->unk_16C = gUnk_0813C704;
            work->unk_170 = gUnk_0813C73C;
            break;
        case 1:
            work->unk_168 = gUnk_0813C704;
            work->unk_16C = gUnk_0813C6E8;
            work->unk_170 = gUnk_0813C73C;
            break;
        case 2:
            work->unk_168 = gUnk_0813C774;
            work->unk_16C = gUnk_0813C790;
            work->unk_170 = gUnk_0813C7AC;
            break;
        case 3:
            work->unk_168 = gUnk_0813C758;
            work->unk_16C = gUnk_0813C774;
            work->unk_170 = gUnk_0813C7AC;
            break;
        case 4:
        default:
            work->unk_168 = gUnk_0813C720;
            work->unk_16C = gUnk_0813C704;
            work->unk_170 = gUnk_0813C73C;
            break;
        }
        work->unk_03C = 9;
        work->unk_15A = 0;
        work->unk_158 = 0;
        work->unk_165 = 0;
        t = work->unk_15E & 0xFFBF;
        work->unk_15E = t;
    }
}

void func_08028228(BtlRikuWork* work) {
    work->unk_154 = -work->unk_044.unk_AC * 3;
    work->unk_14C = ((gSineTable[work->unk_044.unk_B0] << 1) * work->unk_044.unk_A8) >> 8;
    work->unk_150 = ((-gSineTable[work->unk_044.unk_B0 + 0x40] << 1) * work->unk_044.unk_A8) >> 8;
}

BtlWork* func_0802828C(BtlRikuWork* work) {
    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_178 != 0) {
            if (gUnk_02039B84->unk_068 & 0x40) {
                return gUnk_02039B9C->unk_07C;
            }
        } else {
            if (gUnk_02039B84->unk_068 & 0x20000000) {
                return gUnk_02039B84->unk_07C;
            }
        }
    } else {
        if (gUnk_02039B84->unk_068 & 0x40) {
            return gUnk_02039B84->unk_0A8;
        }
    }
    return 0;
}

BtlWork* func_0802830C(void) {
    BtlWork* e;
    BtlWork* best;
    s32 d;
    s32 min;

    min = 0x10000;
    best = 0;
    e = func_08000C8C(&gUnk_02039B84->unk_080);
    while (e != 0) {
        if (!(e->unk_034 & 0x1000000)) {
            d = e->unk_00C - (e->unk_0A2 << 8);
            if (min > d) {
                best = e;
                min = d;
            }
        }
        e = func_08000CD4(&e->unk_0B8);
    }
    return best;
}

BtlWork* func_08028370(BtlRikuWork* work) {
    BtlWork* list[10];
    BtlWork* e;
    s16 n;

    if (work->unk_044.unk_E4->unk_078 != 0) {
        return work->unk_044.unk_E4->unk_078;
    }
    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_178 != 0) {
            e = gUnk_02039B9C->unk_07C;
        } else {
            e = gUnk_02039B84->unk_07C;
        }
        if (e->unk_02C <= 0) {
            return 0;
        }
        return e;
    }
    n = 0;
    e = func_08000C8C(&gUnk_02039B84->unk_080);
    if (e != 0) {
        list[0] = e;
        n = 1;
        do {
            e = func_08000CD4(&e->unk_0B8);
            if (e == 0) {
                break;
            }
            list[n] = e;
            n++;
        } while (n <= 9);
    }
    if (n == 0) {
        return 0;
    }
    e = list[GetRandom() % n];
    return e;
}

u16 func_08028428(u16 a, u16 b, u16 c) {
    u16 d;

    d = b;
    if (a & b) {
        if ((a & c) == 0) {
            a &= ~b;
        }
        a |= c;
    } else if (a & c) {
        a &= ~c;
        a |= d;
    }
    return a;
}

void func_08028468(BtlRikuWork* work) {
    if (gUnk_02039B84->unk_068 & 0x800000000000) {
        work->unk_1AC = gUnk_09618118;
        LoadObjPaletteBank(work->unk_008->unk_06, gUnk_09618118);
        gUnk_02039B84->unk_068 &= ~0x800000000000;
        gUnk_02039B84->unk_068 |= 0x80000000000000;
    }
}

void func_080284C8(s16 a) {
    if (gUnk_02039BB0.unk_008 & 0x100) {
        return;
    }
    gUnk_02039B84->unk_1C8 += a;
    if (gUnk_02039B84->unk_1C8 < 0) {
        gUnk_02039B84->unk_1C8 = 0;
    } else if (gUnk_02039B84->unk_1C8 > 999) {
        gUnk_02039B84->unk_1C8 = 999;
    }
}

INCLUDE_ASM("btl/task_btl_riku_1.s");
INCLUDE_ASM("btl/task_btl_riku_2.s");

void task_btl_riku_3(BtlRikuWork* work) {
    UnkStruct_0801AF08* p;

    p = &work->unk_044;
    if (*(s32*)&gUnk_02039B84->unk_0A0 == 3) {
        gUnk_02039BB0.unk_032 = gUnk_02039BB0.unk_0F8;
    } else {
        gUnk_02039BB0.unk_032 = p->unk_2C;
    }
    func_08012304(&p->unk_40);
    func_080277E4(work);
    ReleaseObjTiles(work->unk_004);
    TaskPoolDestroy(&work->unk_028);
}

INCLUDE_ASM("btl/task_btl_map_0.s");
