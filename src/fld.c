#include "macros.h"
#include "fld.h"
#include "gba/keys.h"

struct UnkStruct_0203C7AC* gUnk_0203C7AC;

void task_fld_sora_0(FldWork* work) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    work->tiles = AllocObjTiles(0x500, 0);
    work->palette = LoadObjPalette(gUnk_08F683A4, 32);
    act->unk_1A = 16;
    work->unk_BC = 0;
    work->unk_9C = 0;
    work->unk_9D = 0;
    work->unk_9E = 0;
    work->unk_98 = 0;
    work->unk_A4 = 8;
    work->unk_A8 = 16;
    act->unk_32 = 0;
    act->unk_30 = 0;

    if (gGameState.unk_00 != 0) {
        act->unk_00 = gGameState.unk_14;
        act->angle = gGameState.unk_24;
        act->unk_10 = gGameState.unk_28;
        work->unk_94 = gGameState.unk_30;
        work->unk_A0 = gGameState.unk_2C;
        work->unk_B0 = gGameState.unk_34;
        work->unk_B4 = gGameState.unk_38;
        work->unk_B8 = gGameState.unk_3C;
    } else {
        act->unk_00.x = gUnk_02039BA0->unk_DC;
        act->unk_00.y = gUnk_02039BA0->unk_E0;
        act->unk_00.z = 0;
        act->angle = gUnk_02039BA0->unk_E4;
        func_080DFF4C(&act->unk_00);
        act->unk_00.z = act->unk_00.unk_0C;
        act->unk_00.y -= act->unk_00.unk_0C;
        act->unk_10 = 0;
        work->unk_94 = 0;
        work->unk_A0 = 0;
    }

    AnimInit(work->unk_08, 0, 0);
    func_08031F98(work, 0, 1);
    work->unk_20 = AnimGetGfx(work->unk_08);

    switch (gGameState.unk_0C) {
    case 7:
        work->unk_AC = gUnk_0813CD4C[1];
        break;
    case 2:
        work->unk_AC = gUnk_0813CD4C[2];
        break;
    case 5:
        work->unk_AC = gUnk_0813CD4C[3];
        break;
    case 4:
        work->unk_AC = gUnk_0813CD4C[4];
        break;
    case 6:
        work->unk_AC = gUnk_0813CD4C[5];
        break;
    case 0:
    case 3:
    case 12:
        work->unk_AC = gUnk_0813CD4C[6];
        break;
    case 9:
        work->unk_AC = gUnk_0813CD4C[7];
        break;
    default:
        work->unk_AC = gUnk_0813CD4C[0];
        break;
    }

    TaskPoolInit(work->unk_24, 2);
    TaskCreate(work->unk_24, &gTaskDescFldShadow, &gUnk_02039BA0->unk_18);
    func_080122AC(work->unk_38, 1, 4, 32);
    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
}
u8 func_08032268(FldWork* work, void* task) {
    FldActor* act;
    s16* p;
    s32 flags;

    act = &gUnk_02039BA0->unk_18;
    flags = gUnk_02039BA0->unk_70;

    if (flags & 0x100000) {
        func_08031F98(work, 12, 0);
    } else if (flags & 0x80000) {
        func_08031F98(work, 1, 1);
    } else {
        func_08031F98(work, 0, 1);
    }

    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        func_080062F4(work->palette->unk_06 + 16, 0);
        work->unk_94 = 0;
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)task_fld_sora_1);
        TaskPoolUpdate(work->unk_24);
    } else {
        p = &work->unk_98;

        if (*p == 0) {
            func_080062F4(work->palette->unk_06 + 16, 1);
            act->unk_10 = 0;
            work->unk_BC = 0;
        }

        TaskPoolUpdate(work->unk_24);
        work->unk_20 = AnimUpdate(work->unk_08);
        func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
        (*p)++;
    }

    return 1;
}
u8 func_0803234C(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 z;

    act = &gUnk_02039BA0->unk_18;
    x = act->unk_00.x;
    y = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    switch (work->unk_94) {
    case 13:
        m4aSongNumStart(0x8B);
        work->unk_94 = 14;
        work->unk_A0 = -0x800;
        work->unk_98 = 0;
        act->unk_10 = 0;
        work->unk_B0 = work->unk_7C;
        work->unk_B4 = work->unk_80;
    case 14:
        if (work->unk_A0 > -0x300) {
            func_08031F98(work, 11, 0);
            act->unk_10 = 0x180;
            act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        } else {
            func_08031F98(work, 4, 0);
            act->unk_00.x += (work->unk_B0 - act->unk_00.x) >> 3;
            act->unk_00.y += (work->unk_B4 - act->unk_00.y) >> 3;
        }

        work->unk_A0 = (work->unk_B8 - (z = act->unk_00.z + 0xF00)) >> 3;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 >= 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            work->unk_A4 |= 4;
            SetTaskUpdate(task, (u32)func_080324DC);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (func_08031D74(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->unk_20 = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
INCLUDE_ASM("fld/func_080324DC.s");
INCLUDE_ASM("fld/func_08032C3C.s");
u8 func_08033054(FldWork* work, void* task) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;

    if ((GetKeysPressed() & B_BUTTON) || (GetKeysPressed() & DPAD_DOWN) ||
        (act->angle == 0xD3 && (GetKeysPressed() & DPAD_RIGHT)) ||
        (act->angle == 0x2D && (GetKeysPressed() & DPAD_LEFT))) {
        work->unk_98 = 0;
        work->unk_94 = 4;
        work->unk_A0 = 0;
        act->angle += 0x80;
        gUnk_02039BA0->unk_68 = 0;
        SetTaskUpdate(task, (u32)func_080324DC);
        return 1;
    }

    if ((GetKeysHeld() & DPAD_UP) ||
        (act->angle == 0xD3 && (GetKeysHeld() & DPAD_LEFT)) ||
        (act->angle == 0x2D && (GetKeysHeld() & DPAD_RIGHT))) {
        work->unk_98 = 0;
        work->unk_94 = 10;
        act->unk_10 = 0x133;
        work->unk_A0 = -0x5C0;
        work->unk_A4 |= 4;
        m4aSongNumStart(0x8E);
        gUnk_02039BA0->unk_68 = 0;
        return 1;
    }

    return 0;
}
u8 func_08033150(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    u8 ret;
    s32 x;
    s32 y;

    act = &gUnk_02039BA0->unk_18;
    ret = 0;
    x = act->unk_00.x;
    y = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    switch (work->unk_94) {
    case 8:
        if (work->unk_98 == 0) {
            p = act->unk_00;
            p.y -= 0xA00;
            act->unk_00.z = func_080DFF1C(&p) + 0x2B00;
            m4aSongNumStart(0x8D);
            act->angle = func_080DFF94(act->unk_00.x, act->unk_00.y, act->unk_00.z);
            func_08031F98(work, 9, 0);
        }

        if (work->unk_98 > 15) {
            ret = func_08033054(work, task);
        }

        act->unk_00.x += gSineTable[act->angle];
        act->unk_00.y -= gSineTable[act->angle + 64];

        if (AnimIsFinished(work->unk_08) != 0 && ret == 0) {
            work->unk_94 = 9;
        } else {
            work->unk_98++;
        }

        break;
    case 9:
        func_08031F98(work, 10, 0);
        func_08033054(work, task);
        break;
    case 10:
        func_08031F98(work, 11, 0);
        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (u32)func_080324DC);
        } else {
            work->unk_98++;
        }

        break;
    }

    work->unk_20 = AnimUpdate(work->unk_08);

    if (func_08031D74(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
INCLUDE_ASM("fld/func_08033334.s");
INCLUDE_ASM("fld/func_0803366C.s");
INCLUDE_ASM("fld/task_fld_sora_1.s");

void task_fld_sora_2(FldWork* work) {
    FldActor* act;
    u16 depth;
    s32 pri;
    s32 x;
    s32 y;
    s32 z;

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
        depth = -0x1004 - (act->unk_00.y >> 8) * 4;

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

    x = (act->unk_00.x >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (act->unk_00.y >> 8) + (act->unk_00.z >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, work->unk_20, work->tiles, work->palette, 0, pri, depth);
    TaskPoolDraw(work->unk_24);
}

void task_fld_sora_3(FldWork* work) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    func_08012304(work->unk_38);

    if (gGameState.unk_00 != 0) {
        gGameState.unk_28 = act->unk_10;
        gGameState.unk_14 = act->unk_00;
        gGameState.unk_24 = act->angle;
        gGameState.unk_30 = work->unk_94;
        gGameState.unk_2C = work->unk_A0;
        gGameState.unk_34 = work->unk_B0;
        gGameState.unk_38 = work->unk_B4;
        gGameState.unk_3C = work->unk_B8;
    } else {
        gGameState.unk_24 = act->angle;
    }

    TaskPoolDestroy(work->unk_24);
}

void func_08034368(FldActor* act) {
    if ((GetKeysHeld() & DPAD_LEFT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 0xAD;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_LEFT)) {
        act->angle = 0xD3;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_RIGHT)) {
        act->angle = 0x2D;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 0x53;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 0xAD;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 0x53;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 0xD3;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 0x2D;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 0xD3;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 0xAD;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 0x2D;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 0x53;
    } else if (GetKeysHeld() & DPAD_DOWN) {
        act->angle = 0x80;
    } else if (GetKeysHeld() & DPAD_UP) {
        act->angle = 0;
    } else if (GetKeysHeld() & DPAD_LEFT) {
        act->angle = 0xC0;
    } else if (GetKeysHeld() & DPAD_RIGHT) {
        act->angle = 0x40;
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
    a.y -= 0x600;
    b.y += 0x600;

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
    a.y -= 0x600;
    b.y += 0x600;

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
    a.y -= 0x600;
    b.y += 0x600;

    hit = _080DFE1C(&a);

    if (hit != 0) {
        work->unk_B0 = a.x;
        work->unk_B4 = a.y;
        return hit;
    }

    hit = _080DFE1C(&b);

    if (hit != 0) {
        work->unk_B0 = b.x;
        work->unk_B4 = b.y;
        return hit;
    }

    return 0;
}

u8 func_08034668(FldActor* act) {
    FldPos v;

    v = act->unk_00;
    v.x += gSineTable[act->angle] * 8;
    v.y -= gSineTable[act->angle + 64] * 8;

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

    dir = act->angle;
    func_08034368(act);

    if (dir != act->angle) {
        diff = GetAngleDiff(dir, act->angle);

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

    switch (gUnk_02039BA0->unk_18.angle) {
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
    func_08002A10(work->tiles, def->unk_08);
}

void task_fld_riku_0(FldWork* work) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    work->tiles = AllocObjTiles(0xA00, 0);
    work->palette = LoadObjPalette(gUnk_09618118, 32);
    act->unk_1A = 16;
    work->unk_BC = 0;
    work->unk_9C = 0;
    work->unk_9D = 0;
    work->unk_9E = 0;
    work->unk_98 = 0;
    work->unk_A4 = 8;
    work->unk_A8 = 16;
    act->unk_32 = 0;
    act->unk_30 = 0;

    if (gGameState.unk_00 != 0) {
        act->unk_00 = gGameState.unk_14;
        act->angle = gGameState.unk_24;
        act->unk_10 = gGameState.unk_28;
        work->unk_94 = gGameState.unk_30;
        work->unk_A0 = gGameState.unk_2C;
        work->unk_B0 = gGameState.unk_34;
        work->unk_B4 = gGameState.unk_38;
        work->unk_B8 = gGameState.unk_3C;
    } else {
        act->unk_00.x = gUnk_02039BA0->unk_DC;
        act->unk_00.y = gUnk_02039BA0->unk_E0;
        act->unk_00.z = 0;
        act->angle = gUnk_02039BA0->unk_E4;
        func_080DFF4C(&act->unk_00);
        act->unk_00.z = act->unk_00.unk_0C;
        act->unk_00.y -= act->unk_00.unk_0C;
        act->unk_10 = 0;
        work->unk_94 = 0;
        work->unk_A0 = 0;
    }

    AnimInit(work->unk_08, 0, 0);
    func_0803473C(work, 0, 1);
    work->unk_20 = AnimGetGfx(work->unk_08);

    switch (gGameState.unk_0C) {
    case 7:
        work->unk_AC = gUnk_0813D28C[1];
        break;
    case 2:
        work->unk_AC = gUnk_0813D28C[2];
        break;
    case 5:
        work->unk_AC = gUnk_0813D28C[3];
        break;
    case 4:
        work->unk_AC = gUnk_0813D28C[4];
        break;
    case 6:
        work->unk_AC = gUnk_0813D28C[5];
        break;
    case 0:
    case 3:
    case 12:
        work->unk_AC = gUnk_0813D28C[6];
        break;
    case 9:
        work->unk_AC = gUnk_0813D28C[7];
        break;
    default:
        work->unk_AC = gUnk_0813D28C[0];
        break;
    }

    TaskPoolInit(work->unk_24, 2);
    TaskCreate(work->unk_24, &gTaskDescFldShadow, &gUnk_02039BA0->unk_18);
    func_080122AC(work->unk_38, 1, 4, 32);
    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
}
u8 func_08034A0C(FldWork* work, void* task) {
    FldActor* act;
    s16* p;
    s32 flags;

    act = &gUnk_02039BA0->unk_18;
    flags = gUnk_02039BA0->unk_70;

    if (flags & 0x100000) {
        func_0803473C(work, 12, 0);
    } else if (flags & 0x80000) {
        func_0803473C(work, 1, 1);
    } else {
        func_0803473C(work, 0, 1);
    }

    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        func_080062F4(work->palette->unk_06 + 16, 0);
        work->unk_94 = 0;
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)task_fld_riku_1);
        TaskPoolUpdate(work->unk_24);
    } else {
        p = &work->unk_98;

        if (*p == 0) {
            func_080062F4(work->palette->unk_06 + 16, 1);
            act->unk_10 = 0;
            work->unk_BC = 0;
        }

        TaskPoolUpdate(work->unk_24);
        work->unk_20 = AnimUpdate(work->unk_08);
        func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
        (*p)++;
    }

    return 1;
}
u8 func_08034AF0(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 z;

    act = &gUnk_02039BA0->unk_18;
    x = act->unk_00.x;
    y = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    switch (work->unk_94) {
    case 13:
        m4aSongNumStart(0x8B);
        work->unk_94 = 14;
        work->unk_A0 = -0x800;
        work->unk_98 = 0;
        act->unk_10 = 0;
        work->unk_B0 = work->unk_7C;
        work->unk_B4 = work->unk_80;
        break;
    case 14:
        if (work->unk_A0 > -0x300) {
            func_0803473C(work, 11, 0);
            act->unk_10 = 0x180;
            act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        } else {
            func_0803473C(work, 4, 0);
            act->unk_00.x += (work->unk_B0 - act->unk_00.x) >> 3;
            act->unk_00.y += (work->unk_B4 - act->unk_00.y) >> 3;
        }

        work->unk_A0 = (work->unk_B8 - (z = act->unk_00.z + 0xF00)) >> 3;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 >= 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            work->unk_A4 |= 4;
            SetTaskUpdate(task, (u32)func_08034C88);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (func_08034518(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->unk_20 = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
INCLUDE_ASM("fld/func_08034C88.s");
INCLUDE_ASM("fld/func_080353DC.s");
u8 func_080357F4(FldWork* work, void* task) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;

    if ((GetKeysPressed() & B_BUTTON) || (GetKeysPressed() & DPAD_DOWN) ||
        (act->angle == 0xD3 && (GetKeysPressed() & DPAD_RIGHT)) ||
        (act->angle == 0x2D && (GetKeysPressed() & DPAD_LEFT))) {
        work->unk_98 = 0;
        work->unk_94 = 4;
        work->unk_A0 = 0;
        act->angle += 0x80;
        gUnk_02039BA0->unk_68 = 0;
        SetTaskUpdate(task, (u32)func_08034C88);
        return 1;
    }

    if ((GetKeysHeld() & DPAD_UP) ||
        (act->angle == 0xD3 && (GetKeysHeld() & DPAD_LEFT)) ||
        (act->angle == 0x2D && (GetKeysHeld() & DPAD_RIGHT))) {
        work->unk_98 = 0;
        work->unk_94 = 10;
        act->unk_10 = 0x133;
        work->unk_A0 = -0x5C0;
        work->unk_A4 |= 4;
        m4aSongNumStart(0x8E);
        gUnk_02039BA0->unk_68 = 0;
        return 1;
    }

    return 0;
}
u8 func_080358F0(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    u8 ret;
    s32 x;
    s32 y;

    act = &gUnk_02039BA0->unk_18;
    ret = 0;
    x = act->unk_00.x;
    y = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    switch (work->unk_94) {
    case 8:
        if (work->unk_98 == 0) {
            p = act->unk_00;
            p.y -= 0xA00;
            act->unk_00.z = func_080DFF1C(&p) + 0x2B00;
            m4aSongNumStart(0x8D);
            act->angle = func_080DFF94(act->unk_00.x, act->unk_00.y, act->unk_00.z);
            func_0803473C(work, 9, 0);
        }

        if (work->unk_98 > 15) {
            ret = func_080357F4(work, task);
        }

        act->unk_00.x += gSineTable[act->angle];
        act->unk_00.y -= gSineTable[act->angle + 64];

        if (AnimIsFinished(work->unk_08) != 0 && ret == 0) {
            work->unk_94 = 9;
        } else {
            work->unk_98++;
        }

        break;
    case 9:
        func_0803473C(work, 10, 0);
        func_080357F4(work, task);
        break;
    case 10:
        func_0803473C(work, 11, 0);
        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (u32)func_08034C88);
        } else {
            work->unk_98++;
        }

        break;
    }

    work->unk_20 = AnimUpdate(work->unk_08);

    if (func_08034518(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
INCLUDE_ASM("fld/func_08035AD4.s");
INCLUDE_ASM("fld/func_08035DFC.s");
INCLUDE_ASM("fld/task_fld_riku_1.s");

void task_fld_riku_2(FldWork* work) {
    FldActor* act;
    u16 depth;
    s32 pri;
    s32 x;
    s32 y;
    s32 z;

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
        depth = -0x1004 - (act->unk_00.y >> 8) * 4;

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

    x = (act->unk_00.x >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (act->unk_00.y >> 8) + (act->unk_00.z >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, work->unk_20, work->tiles, work->palette, 0, pri, depth);
    TaskPoolDraw(work->unk_24);
}

void task_fld_riku_3(FldWork* work) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    func_08012304(work->unk_38);

    if (gGameState.unk_00 != 0) {
        gGameState.unk_28 = act->unk_10;
        gGameState.unk_14 = act->unk_00;
        gGameState.unk_24 = act->angle;
        gGameState.unk_30 = work->unk_94;
        gGameState.unk_2C = work->unk_A0;
        gGameState.unk_34 = work->unk_B0;
        gGameState.unk_38 = work->unk_B4;
        gGameState.unk_3C = work->unk_B8;
    } else {
        gGameState.unk_24 = act->angle;
    }

    TaskPoolDestroy(work->unk_24);
}

void task_fld_shadow_0(FldShadowWork* work, FldActor* obj) {
    work->unk_10 = obj;
    work->unk_00 = obj->unk_00.x;
    work->unk_04 = obj->unk_00.y;
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(work->unk_14, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(work->unk_14, 0, 1);
}

s32 task_fld_shadow_1(FldShadowWork* work) {
    work->unk_00 = work->unk_10->unk_00.x;
    work->unk_04 = work->unk_10->unk_00.y;
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

    if (obj->unk_00.z >= z) {
        sprite = 0;
    } else {
        size = 0x100 - (z - obj->unk_00.z) / 128;

        if (size <= 0x18) {
            size = 0x19;
        }

        sprite = AllocObjAffine(0, size, size, 0);
    }

    x = (work->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (work->unk_04 >> 8) + (z >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, spr, work->tiles, work->palette, sprite, 0x800, obj->unk_3A);
}

void task_fld_shadow_3(FldShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

ALIGN_ZERO(2);
