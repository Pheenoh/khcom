#include "macros.h"
#include "fld.h"

INCLUDE_ASM("fld/task_fld_sora_0.s");
INCLUDE_ASM("fld/func_08032268.s");
INCLUDE_ASM("fld/func_0803234C.s");
INCLUDE_ASM("fld/func_080324DC.s");
INCLUDE_ASM("fld/func_08032C3C.s");
INCLUDE_ASM("fld/func_08033054.s");
INCLUDE_ASM("fld/func_08033150.s");
INCLUDE_ASM("fld/func_08033334.s");
INCLUDE_ASM("fld/func_0803366C.s");
INCLUDE_ASM("fld/task_fld_sora_1.s");

void task_fld_sora_2(FldWork* work) {
    FldActor* act;
    u16 depth;
    s32 pri;
    s32 x;
    s32 y;

    act = &gUnk_02039BA0->unk_18;
    pri = (work->unk_A4 & 2) ? 0x801 : 0x800;

    if (work->unk_BC != 0) {
        depth = -0x1006 - (work->unk_80 >> 8) * 4;

        if (work->unk_84 <= work->unk_48) {
            act->unk_3A = 0;
            act->unk_3C = func_080DFF1C(&act->unk_00);
        } else {
            act->unk_3C = work->unk_78;
            act->unk_3A = depth + 1;
        }
    } else {
        depth = -0x1004 - (act->unk_00.unk_04 >> 8) * 4;

        if (work->unk_A4 & 0x10) {
            act->unk_3C = act->unk_00.unk_0C;
        } else {
            act->unk_3C = func_080DFF1C(&act->unk_00);
        }

        if (act->unk_3C != act->unk_00.unk_0C) {
            act->unk_3A = 0;
        } else {
            act->unk_3A = depth + 1;
        }
    }

    x = (act->unk_00.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (act->unk_00.unk_04 >> 8) + (act->unk_00.unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, work->unk_20, work->unk_00, work->unk_04, 0, pri, depth);
    TaskPoolDraw(work->unk_24);
}

void task_fld_sora_3(FldWork* work) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
    func_08012304(work->unk_38);

    if (gUnk_02039BB0.unk_00 != 0) {
        gUnk_02039BB0.unk_28 = act->unk_10;
        gUnk_02039BB0.unk_14 = act->unk_00;
        gUnk_02039BB0.unk_24 = act->unk_14;
        gUnk_02039BB0.unk_30 = work->unk_94;
        gUnk_02039BB0.unk_2C = work->unk_A0;
        gUnk_02039BB0.unk_34 = work->unk_B0;
        gUnk_02039BB0.unk_38 = work->unk_B4;
        gUnk_02039BB0.unk_3C = work->unk_B8;
    } else {
        gUnk_02039BB0.unk_24 = act->unk_14;
    }

    TaskPoolDestroy(work->unk_24);
}

void func_08034368(FldActor* act) {
    if ((GetKeysHeld() & 0x20) && (GetKeysHeld() & 0x80)) {
        act->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x40) && (GetKeysHeld() & 0x20)) {
        act->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x40) && (GetKeysHeld() & 0x10)) {
        act->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x10) && (GetKeysHeld() & 0x80)) {
        act->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x80) && func_08001534(0x20) <= 4) {
        act->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x80) && func_08001534(0x10) <= 4) {
        act->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x40) && func_08001534(0x20) <= 4) {
        act->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x40) && func_08001534(0x10) <= 4) {
        act->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x20) && func_08001534(0x40) <= 4) {
        act->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x20) && func_08001534(0x80) <= 4) {
        act->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x10) && func_08001534(0x40) <= 4) {
        act->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x10) && func_08001534(0x80) <= 4) {
        act->unk_14 = 0x53;
    } else if (GetKeysHeld() & 0x80) {
        act->unk_14 = 0x80;
    } else if (GetKeysHeld() & 0x40) {
        act->unk_14 = 0;
    } else if (GetKeysHeld() & 0x20) {
        act->unk_14 = 0xC0;
    } else if (GetKeysHeld() & 0x10) {
        act->unk_14 = 0x40;
    }
}

u8 func_08034518(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 lo;
    s32 hi;
    s32 v;

    a = *p;
    b = *p;
    a.unk_04 -= 0x600;
    b.unk_04 += 0x600;

    lo = func_080DFF1C(&a);

    if (lo > a.unk_0C) {
        a.unk_0C = lo;
    }

    hi = func_080DFF1C(&b);

    if (hi > b.unk_0C) {
        b.unk_0C = hi;
    }

    if (func_080DFBDC(&a) != 0 || func_080DFBDC(&b) != 0) {
        return 1;
    }

    v = hi;

    if (v > lo) {
        v = lo;
    }

    p->unk_0C = v;
    return 0;
}

s32 func_0803459C(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 lo;
    s32 hi;

    a = *p;
    b = *p;
    a.unk_04 -= 0x600;
    b.unk_04 += 0x600;

    lo = func_080DFF1C(&a);
    hi = func_080DFF1C(&b);

    if (hi > lo) {
        hi = lo;
    }

    return hi;
}

u8 func_080345EC(FldPos* p, FldWork* work) {
    FldPos a;
    FldPos b;
    u8 hit;

    a = *p;
    b = *p;
    a.unk_04 -= 0x600;
    b.unk_04 += 0x600;

    hit = _080DFE1C(&a);

    if (hit != 0) {
        work->unk_B0 = a.unk_00;
        work->unk_B4 = a.unk_04;
        return hit;
    }

    hit = _080DFE1C(&b);

    if (hit != 0) {
        work->unk_B0 = b.unk_00;
        work->unk_B4 = b.unk_04;
        return hit;
    }

    return 0;
}

u8 func_08034668(FldActor* act) {
    FldPos v;

    v = act->unk_00;
    v.unk_00 += gSineTable[act->unk_14] * 8;
    v.unk_04 -= gSineTable[act->unk_14 + 64] * 8;

    if (func_080DFCDC(&v) != 0) {
        return 1;
    }

    return 0;
}

s32 func_080346C0(FldWork* work) {
    FldActor* act;
    s32 v;

    act = &gUnk_02039BA0->unk_18;

    if (work->unk_66 & 1) {
        if (act->unk_00.unk_0C < work->unk_78) {
            v = act->unk_00.unk_0C;
        } else {
            v = work->unk_78;
        }

        work->unk_BC = 1;
    } else {
        work->unk_BC = 0;
        v = act->unk_00.unk_0C;
    }

    return v;
}

void func_08034704(FldActor* act) {
    u8 dir;
    s32 diff;

    dir = act->unk_14;
    func_08034368(act);

    if (dir != act->unk_14) {
        diff = func_08005824(dir, act->unk_14);

        if (diff < 0) {
            diff = -diff;
        }

        if (diff > 100) {
            act->unk_10 = 0;
        } else {
            act->unk_10 = act->unk_10 >> 1;
        }
    }
}

void func_0803473C(FldWork* work, s32 index, u16 flags) {
    FldAnimDef* def;
    s32 dir;

    switch (gUnk_02039BA0->unk_18.unk_14) {
        case 0x2D:
            dir = 4;
            work->unk_A4 |= 2;
            break;
        case 0x40:
            dir = 3;
            work->unk_A4 |= 2;
            break;
        case 0x53:
            dir = 2;
            work->unk_A4 |= 2;
            break;
        case 0x80:
            dir = 1;
            work->unk_A4 &= 0xFFFD;
            break;
        case 0xAD:
            dir = 2;
            work->unk_A4 &= 0xFFFD;
            break;
        case 0xC0:
            dir = 3;
            work->unk_A4 &= 0xFFFD;
            break;
        case 0xD3:
            dir = 4;
            work->unk_A4 &= 0xFFFD;
            break;
        case 0x00:
        default:
            dir = 0;
            work->unk_A4 &= 0xFFFD;
            break;
    }

    if (work->unk_A8 == index) {
        flags |= 4;
    }

    work->unk_A8 = index;
    def = &gUnk_0813CDDC[index][dir];
    func_08005974(work->unk_08, def->unk_0C, flags, def->unk_04, def->unk_00);
    func_08002A10(work->unk_00, def->unk_08);
}

INCLUDE_ASM("fld/task_fld_riku_0.s");
INCLUDE_ASM("fld/func_08034A0C.s");
INCLUDE_ASM("fld/func_08034AF0.s");
INCLUDE_ASM("fld/func_08034C88.s");
INCLUDE_ASM("fld/func_080353DC.s");
INCLUDE_ASM("fld/func_080357F4.s");
INCLUDE_ASM("fld/func_080358F0.s");
INCLUDE_ASM("fld/func_08035AD4.s");
INCLUDE_ASM("fld/func_08035DFC.s");
INCLUDE_ASM("fld/task_fld_riku_1.s");

void task_fld_riku_2(FldWork* work) {
    FldActor* act;
    u16 depth;
    s32 pri;
    s32 x;
    s32 y;

    act = &gUnk_02039BA0->unk_18;
    pri = (work->unk_A4 & 2) ? 0x801 : 0x800;

    if (work->unk_BC != 0) {
        depth = -0x1006 - (work->unk_80 >> 8) * 4;

        if (work->unk_84 <= work->unk_48) {
            act->unk_3A = 0;
            act->unk_3C = func_080DFF1C(&act->unk_00);
        } else {
            act->unk_3C = work->unk_78;
            act->unk_3A = depth + 1;
        }
    } else {
        depth = -0x1004 - (act->unk_00.unk_04 >> 8) * 4;

        if (work->unk_A4 & 0x10) {
            act->unk_3C = act->unk_00.unk_0C;
        } else {
            act->unk_3C = func_080DFF1C(&act->unk_00);
        }

        if (act->unk_3C != act->unk_00.unk_0C) {
            act->unk_3A = 0;
        } else {
            act->unk_3A = depth + 1;
        }
    }

    x = (act->unk_00.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (act->unk_00.unk_04 >> 8) + (act->unk_00.unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, work->unk_20, work->unk_00, work->unk_04, 0, pri, depth);
    TaskPoolDraw(work->unk_24);
}

void task_fld_riku_3(FldWork* work) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
    func_08012304(work->unk_38);

    if (gUnk_02039BB0.unk_00 != 0) {
        gUnk_02039BB0.unk_28 = act->unk_10;
        gUnk_02039BB0.unk_14 = act->unk_00;
        gUnk_02039BB0.unk_24 = act->unk_14;
        gUnk_02039BB0.unk_30 = work->unk_94;
        gUnk_02039BB0.unk_2C = work->unk_A0;
        gUnk_02039BB0.unk_34 = work->unk_B0;
        gUnk_02039BB0.unk_38 = work->unk_B4;
        gUnk_02039BB0.unk_3C = work->unk_B8;
    } else {
        gUnk_02039BB0.unk_24 = act->unk_14;
    }

    TaskPoolDestroy(work->unk_24);
}

void task_fld_shadow_0(FldShadowWork* work, FldActor* obj) {
    work->unk_10 = obj;
    work->unk_00 = obj->unk_00.unk_00;
    work->unk_04 = obj->unk_00.unk_04;
    work->unk_08 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->unk_0C = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(work->unk_14, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(work->unk_14, 0, 1);
}

s32 task_fld_shadow_1(FldShadowWork* work) {
    work->unk_00 = work->unk_10->unk_00.unk_00;
    work->unk_04 = work->unk_10->unk_00.unk_04;
    return 1;
}

void task_fld_shadow_2(FldShadowWork* work) {
    FldActor* obj;
    void* spr;
    s32 z;
    s32 size;
    s32 sprite;
    s32 x;
    s32 y;

    obj = work->unk_10;

    if (obj->unk_3A == 0) {
        return;
    }

    spr = AnimUpdate(work->unk_14);
    z = obj->unk_3C;

    if (obj->unk_00.unk_08 >= z) {
        sprite = 0;
    } else {
        size = 0x100 - (z - obj->unk_00.unk_08) / 128;

        if (size <= 0x18) {
            size = 0x19;
        }

        sprite = AllocObjAffine(0, size, size, 0);
    }

    x = (work->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (work->unk_04 >> 8) + (z >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, spr, work->unk_08, work->unk_0C, sprite, 0x800, obj->unk_3A);
}

void task_fld_shadow_3(FldShadowWork* work) {
    ReleaseObjTiles(work->unk_08);
    ReleaseObjPalette(work->unk_0C);
}

ALIGN_ZERO(2);
