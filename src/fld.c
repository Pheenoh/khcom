#include "macros.h"
#include "fld.h"
#include "gba/keys.h"

UnkStruct_0203C7AC* gUnk_0203C7AC;

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
    work->gfx = AnimGetGfx(work->unk_08);

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
        work->gfx = AnimUpdate(work->unk_08);
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
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
u8 func_080324DC(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    s32 sx;
    s32 sy;
    s32 nx;
    s32 ny;
    s32 z;
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    z = func_08031F1C(work);
    sx = act->unk_00.x;
    sy = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    if ((work->unk_A4 & 4) == 0) {
        func_08031F60(act);
    }

    switch (work->unk_94) {
    case 12:
        if (work->unk_98 == 0) {
            gUnk_02039BA0->unk_68 = 0;
            func_08031F98(work, 14, 0);
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (AnimGetFrame(work->unk_08) > 3) {
            act->unk_00.z += work->unk_A0;
            work->unk_A0 += 66;

            if (act->unk_00.z > z) {
                act->unk_00.z = z;
                work->unk_A0 = 0;
            }
        } else {
            work->unk_A0 = 0;
        }

        act->unk_10 -= 38;

        if (act->unk_10 < 0) {
            act->unk_10 = 0;
        }

        switch (AnimGetFrame(work->unk_08)) {
        case 3:
        case 4:
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->unk_00.x + gSineTable[act->angle] * 12;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->unk_00.x + gSineTable[act->angle] * 27;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->unk_00.x + gSineTable[act->angle] * 20;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->unk_00.z - 0x800);
            break;
        }

        if (AnimIsFinished(work->unk_08) != 0) {
            if (work->unk_A0 < 0) {
                work->unk_94 = 3;
            } else {
                work->unk_94 = 4;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 2:
        if (work->unk_98 == 0) {
            func_08031F98(work, 3, 0);
            act->unk_10 >>= 1;
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (work->unk_98 > 3) {
            work->unk_B8 = gUnk_0203C7AC->unk_1C;

            if (work->unk_B8 == 0) {
                if (GetRandom() % 2 != 0) {
                    m4aSongNumStart(113);
                } else {
                    m4aSongNumStart(114);
                }

                work->unk_94 = 3;
                work->unk_A0 = -1331;
                act->unk_10 <<= 1;
                work->unk_98 = 0;
                act->unk_00.z += work->unk_A0;
                work->unk_A0 += 66;
            } else {
                act->angle = gUnk_0203C7AC->unk_18;
                work->unk_B8 = act->unk_00.z - work->unk_B8;
                work->unk_94 = 13;
                SetTaskUpdate(task, (u32)func_0803234C);
                work->unk_98 = 0;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 3:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 > -512) {
            func_08031F98(work, 5, 0);
        } else {
            func_08031F98(work, 4, 0);
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 66;

        if (work->unk_A0 < 0) {
            if ((GetKeysHeld() & B_BUTTON) == 0) {
                work->unk_A0 += 64;
            }
        }

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
        } else {
            work->unk_98++;
        }

        break;
    case 4:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 < 0x200) {
            func_08031F98(work, 5, 0);
        } else {
            func_08031F98(work, 6, 0);
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 66;

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (act->unk_00.z > z) {
            act->unk_00.z = z;
            work->unk_A0 = 0;

            if (work->unk_94 != 5) {
                work->unk_94 = 5;
                work->unk_98 = 0;
            }
        }

        break;
    case 5:
        if (work->unk_98 == 0) {
            func_08031F98(work, 7, 0);
            m4aSongNumStart(work->unk_AC[3]);
        }

        act->unk_10 = 0;

        if ((GetKeysPressed() & B_BUTTON) != 0) {
            work->unk_A4 &= ~4;
            work->unk_98 = 0;
            work->unk_94 = 2;
        } else if (work->unk_98 > 6) {
            gUnk_02039BA0->unk_70 &= ~0x800000;
            work->unk_A4 &= ~4;
            work->unk_94 = 0;
            work->unk_98 = 0;
            SetTaskUpdate(task, (u32)task_fld_sora_1);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 3:
        case 5:
        case 11:
            break;
        default:
            if ((work->unk_66 & 1) == 0) {
                act->unk_10 = 230 * act->unk_10 >> 8;
                act->unk_00.x += work->unk_70;
                act->unk_00.y += work->unk_74;
            }
            break;
        }
    }

    if (func_08031D74(&act->unk_00) != 0) {
        act->unk_00.x = sx;
        act->unk_00.y = sy;

        switch (func_08031E48(&act->unk_00, work)) {
        case 2:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 211;
            SetTaskUpdate(task, (u32)func_08032C3C);
            break;
        case 1:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 45;
            SetTaskUpdate(task, (u32)func_08032C3C);
            break;
        default:
            if (work->unk_94 == 4 && act->unk_00.unk_0C - act->unk_00.z > 0xFFF) {
                p1 = act->unk_00;
                p1.y -= 0x400;
                p1.z = act->unk_00.z - 0x3000;
                p2 = p1;
                p2.z += 768;

                if (func_08031D74(&p1) == 0 && func_08031D74(&p2) != 0) {
                    work->unk_98 = 0;
                    work->unk_94 = 8;
                    gUnk_02039BA0->unk_68 = 0;
                    SetTaskUpdate(task, (u32)func_08033150);
                }
            } else {
                act->unk_10 = 230 * act->unk_10 >> 8;
            }
            break;
        }
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);

    if ((gUnk_02039BA0->unk_70 & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08032268);
        TaskPoolUpdate(work->unk_24);
    }

    return 1;
}
u8 func_08032C3C(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    s32 x;
    s32 y;
    s32 limit;
    s32 d;
    s32 ny;
    s32 nx;
    s32 tx;
    s32 ty;

    act = &gUnk_02039BA0->unk_18;
    limit = func_08031F1C(work);
    x = act->unk_00.x;
    y = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    switch (work->unk_94) {
    case 6:
        if (work->unk_98 == 0) {
            work->unk_B8 = (act->unk_00.z >> 12) << 12;
            work->unk_98++;
            tx = (work->unk_B0 >> 11) / 4;
            ty = (work->unk_B4 >> 11) / 2;
            nx = (tx << 13) | 0x1000;
            ny = (ty << 12) | 0x800;
            x = nx;
            act->unk_00.x = nx;
            y = ny;
            act->unk_00.y = ny;
            m4aSongNumStart(work->unk_AC[5]);
            act->unk_00.unk_0C = func_080DFF1C(&act->unk_00);
        }

        func_08031F98(work, 8, 1);
        work->unk_16 = ((act->unk_00.z >> 8) + 4) & 31;
        work->gfx = AnimGetGfx(work->unk_08);

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 8:
                m4aSongNumStart(work->unk_AC[4]);
                break;
            case 24:
                m4aSongNumStart(work->unk_AC[5]);
                break;
            }
        }

        d = (((work->unk_B8 >> 12) << 12) - act->unk_00.z) >> 1;

        if (abs(d) <= 24) {
            d = 0;
        } else if (d > 384) {
            d = 384;
        } else if (d < -384) {
            d = -384;
        }

        act->unk_00.z += d;

        if (d < 0) {
            act->unk_00.x += gSineTable[act->angle];
            act->unk_00.y -= gSineTable[act->angle + 64];
            p = act->unk_00;
            p.z = work->unk_B8 - 0x2800;

            if (func_08031D74(&p) == 0) {
                act->unk_10 = 204;
                work->unk_A0 = -0x580;
                work->unk_A4 |= 4;
                work->unk_94 = 7;
                work->unk_98 = 0;
                m4aSongNumStart(work->unk_AC[6]);
            }
        } else if (d > 0) {
            if (act->unk_00.z >= limit) {
                act->unk_00.z = limit;
                act->angle += 0x80;
                act->unk_00.x += gSineTable[act->angle] * 10;
                act->unk_00.y += -gSineTable[act->angle + 64] * 10;
                func_08031F98(work, 0, 1);
                work->gfx = AnimGetGfx(work->unk_08);
                work->unk_94 = 0;
                work->unk_98 = 0;
                SetTaskUpdate(task, (u32)task_fld_sora_1);
            }
        } else if (d == 0) {
            if ((GetKeysHeld() & DPAD_UP) || ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0xD3) ||
                ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) - 1) << 12;
            } else if ((GetKeysHeld() & DPAD_DOWN) || ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0xD3) ||
                       ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) + 1) << 12;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->unk_A0 = 0;
            work->unk_98 = 0;
            work->unk_94 = 4;
            act->angle += 0x80;
            act->unk_10 = 0x80;
            work->unk_A4 |= 4;
            act->unk_00.x += gSineTable[act->angle] * 10;
            act->unk_00.y += -gSineTable[act->angle + 64] * 10;
            func_08031F98(work, 6, 0);
            work->gfx = AnimGetGfx(work->unk_08);
            SetTaskUpdate(task, (u32)func_080324DC);
        }

        break;
    case 7:
        func_08031F98(work, 11, 0);
        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        work->unk_A0 += 0x42;
        act->unk_00.z += work->unk_A0;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (u32)func_080324DC);
        } else {
            work->unk_98++;
        }

        work->gfx = AnimUpdate(work->unk_08);
        break;
    }

    if (func_08031D74(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
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

    work->gfx = AnimUpdate(work->unk_08);

    if (func_08031D74(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
u8 func_08033334(FldWork* work, void* task) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;

    switch (work->unk_94) {
    case 15:
        if (work->unk_98 == 0) {
            work->unk_A4 |= 0x10;
            act->angle = 45;
            func_08031F98(work, 2, 1);

            if (gGameState.unk_0E == 0) {
                act->unk_00.x = 0x32000;
            } else {
                act->unk_00.x = 0x22000;
            }

            act->unk_00.y = 0xF000;
            work->unk_9A = 30;
            act->unk_00.z = 0;
            act->unk_00.unk_0C = 0;
            work->unk_B0 = act->unk_00.x + 0x2000;
            work->unk_B4 = act->unk_00.y - 0x1000;
            work->unk_B8 = act->unk_00.unk_0C - 0x2800;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->unk_00.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->unk_00.y, work->unk_B4, work->unk_9A);
            ApproachValue(&act->unk_00.z, work->unk_B8, work->unk_9A);
            act->unk_00.unk_0C = act->unk_00.z;
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;

            if (work->unk_A4 & 0x20) {
                work->unk_94 = 16;
            } else {
                work->unk_94 = 17;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 16:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->unk_00.x + 0x2000;
            work->unk_B4 = act->unk_00.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->unk_00.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->unk_00.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 18;
        } else {
            work->unk_98++;
        }

        break;
    case 17:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->unk_00.x + 0x2000;
            work->unk_B4 = act->unk_00.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->unk_00.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->unk_00.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 18:
        if (work->unk_98 == 0) {
            func_08031F98(work, 12, 0);
            func_080062F4(work->palette->unk_06 + 16, 1);
        }

        if (work->unk_98 == 40) {
            func_080A5830(work->unk_24, act->unk_00.x, act->unk_00.y, act->unk_00.z);
        }

        if (work->unk_98 > 140) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 19:
        func_080DFC7C();
        break;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
u8 func_0803366C(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 nx;
    s32 ny;

    act = &gUnk_02039BA0->unk_18;
    x = act->unk_00.x;
    y = act->unk_00.y;

    if (work->unk_94 == 11) {
        if (work->unk_98 == 0) {
            func_08031F98(work, 13, 0);
            act->unk_10 = 0;
            gUnk_02039BA0->unk_68 = 0;
            work->unk_9A = 0;
            m4aSongNumStart(0x73);
        }

        if (work->unk_12 == 0) {
            switch (act->angle) {
            case 173:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x500;
                    act->unk_00.y += 0x400;
                    break;
                case 1:
                    act->unk_00.x -= 0x200;
                    break;
                case 2:
                    act->unk_00.x -= 0x300;
                    break;
                }

                break;
            case 83:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x += 0x500;
                    act->unk_00.y += 0x400;
                    break;
                case 1:
                    act->unk_00.x += 0x200;
                    break;
                case 2:
                    act->unk_00.x += 0x300;
                    break;
                }

                break;
            case 211:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x500;
                    act->unk_00.y -= 0x200;
                    break;
                case 1:
                    act->unk_00.x -= 0x500;
                    break;
                case 2:
                    act->unk_00.x -= 0x200;
                    break;
                }

                break;
            case 45:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x += 0x500;
                    act->unk_00.y -= 0x200;
                    break;
                case 1:
                    act->unk_00.x += 0x500;
                    break;
                case 2:
                    act->unk_00.x += 0x200;
                    break;
                }

                break;
            case 128:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x300;
                    act->unk_00.y += 0x400;
                    break;
                case 1:
                    act->unk_00.x += 0x100;
                    act->unk_00.y += 0x100;
                    break;
                case 2:
                    act->unk_00.y += 0x200;
                    break;
                case 3:
                    act->unk_00.y += 0x100;
                    break;
                }

                break;
            case 64:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x += 0x700;
                    act->unk_00.y += 0x100;
                    break;
                case 1:
                    act->unk_00.x += 0x300;
                    break;
                case 2:
                    act->unk_00.x += 0x200;
                    break;
                }

                break;
            case 192:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x700;
                    act->unk_00.y += 0x100;
                    break;
                case 1:
                    act->unk_00.x -= 0x300;
                    break;
                case 2:
                    act->unk_00.x -= 0x200;
                    break;
                }

                break;
            case 0:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.y -= 0x400;
                    break;
                case 1:
                    act->unk_00.y -= 0x400;
                    break;
                case 2:
                    act->unk_00.x -= 0x100;
                    act->unk_00.y += 0x100;
                    break;
                case 3:
                    act->unk_00.y -= 0x100;
                    break;
                }

                break;
            }
        }

        if (AnimGetFrame(work->unk_08) == 2) {
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->unk_00.x + gSineTable[act->angle] * 12;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->unk_00.x + gSineTable[act->angle] * 27;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->unk_00.x + gSineTable[act->angle] * 20;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->unk_00.z - 0x800);
        }

        if (AnimIsFinished(work->unk_08) != 0) {
            switch (act->angle) {
            case 173:
                act->unk_00.x -= 0x200;
                act->unk_00.y += 0x200;
                break;
            case 83:
                act->unk_00.x += 0x200;
                act->unk_00.y += 0x200;
                break;
            case 45:
            case 211:
                act->unk_00.y -= 0x400;
                break;
            case 128:
                act->unk_00.y += 0x200;
                break;
            case 0:
                act->unk_00.y -= 0x200;
                break;
            }

            func_08031F98(work, 0, 0);
            work->unk_94 = 0;
            SetTaskUpdate(task, (u32)task_fld_sora_1);
        } else {
            work->unk_98++;
        }
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 5:
        case 3:
        case 11:
            break;
        default:
            if ((work->unk_66 & 1) == 0) {
                act->unk_00.x += work->unk_70;
                act->unk_00.y += work->unk_74;
            }

            break;
        }
    }

    if (func_08031D74(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08032268);
    }

    return 1;
}
u8 task_fld_sora_1(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    FldPos p3;
    FldPos p4;
    s32 sx;
    s32 sy;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dw;
    s32 z;
    s32 r;
    u8 a;
    u8 b;
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;

    if ((work->unk_A4 & 8) != 0) {
        work->unk_A4 &= ~8;

        switch (work->unk_94) {
        case 12:
            work->unk_94 = 3;
        case 2:
        case 3:
        case 4:
            gUnk_02039BA0->unk_70 |= 0x800000;
        case 5:
            SetTaskUpdate(task, (u32)func_080324DC);
            gUnk_02039BA0->unk_68 = 0;
            break;
        case 6:
        case 7:
            SetTaskUpdate(task, (u32)func_08032C3C);
            gUnk_02039BA0->unk_68 = 0;
            work->unk_98 = 1;
            break;
        case 8:
        case 9:
        case 10:
            SetTaskUpdate(task, (u32)func_08033150);
            gUnk_02039BA0->unk_68 = 0;
            break;
        default:
            work->unk_94 = 0;
            break;
        }

        func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
        func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
        work->gfx = AnimUpdate(work->unk_08);
        TaskPoolUpdate(work->unk_24);
        return 1;
    } else if (func_080DFC24() != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08033334);
        TaskPoolUpdate(work->unk_24);
        work->unk_94 = 15;

        if (func_080DFC24() == 1) {
            work->unk_A4 |= 0x20;
        }

        return 1;
    } else if ((gUnk_02039BA0->unk_70 & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08032268);
        TaskPoolUpdate(work->unk_24);
        return 1;
    } else {
        sx = act->unk_00.x;
        sy = act->unk_00.y;

        if (work->unk_94 <= 1) {
            if ((gUnk_02039BA0->unk_70 & 0x4000) == 0) {
                func_08031F60(act);
            }

            if ((gUnk_02039BA0->unk_70 & 0x4000) == 0 && (GetKeysHeld() & DPAD_ANY) != 0) {
                act->unk_10 += 128;
                func_08031F98(work, 2, 1);

                if (act->unk_10 > 0x266) {
                    act->unk_10 = 0x266;
                }

                if (work->unk_12 == 0) {
                    switch (work->unk_16) {
                    case 3:
                        m4aSongNumStart(work->unk_AC[0]);
                        break;
                    case 7:
                        m4aSongNumStart(work->unk_AC[1]);
                        break;
                    }
                }
            } else {
                func_08031F98(work, 0, 1);
                act->unk_10 -= 128;

                if (act->unk_10 < 0) {
                    act->unk_10 = 0;
                }
            }

            act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

            if ((GetKeysPressed() & B_BUTTON) != 0) {
                gUnk_02039BA0->unk_68 = 0;
                gUnk_02039BA0->unk_70 |= 0x800000;
                work->unk_98 = 0;
                work->unk_94 = 2;
                SetTaskUpdate(task, (u32)func_080324DC);
                m4aSongNumStart(work->unk_AC[2]);
            } else if ((GetKeysPressed() & A_BUTTON) != 0) {
                work->unk_98 = 0;
                gUnk_02039BA0->unk_68 = 0;
                work->unk_94 = 11;
                SetTaskUpdate(task, (u32)func_0803366C);
            }
        } else if (AnimIsFinished(work->unk_08) != 0) {
            work->unk_94 = 0;
        }

        if (work->unk_64 != 0) {
            switch (work->unk_6C) {
            case 3:
            case 5:
            case 11:
                break;
            default:
                if ((work->unk_66 & 1) == 0) {
                    act->unk_10 = 230 * act->unk_10 >> 8;
                    act->unk_00.x += work->unk_70;
                    act->unk_00.y += work->unk_74;
                }
                break;
            }
        }

        if (func_08031D74(&act->unk_00) != 0) {
            act->unk_00.x = sx;
            act->unk_00.y = sy;
            r = func_08031E48(&act->unk_00, work);

            if (r != 0) {
                switch (r) {
                case 2:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 211;
                    gUnk_02039BA0->unk_68 = 0;
                    SetTaskUpdate(task, (u32)func_08032C3C);
                    break;
                case 1:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 45;
                    gUnk_02039BA0->unk_68 = 0;
                    SetTaskUpdate(task, (u32)func_08032C3C);
                    break;
                }
            } else {
                if (func_08031EC4(&act->unk_00) != 0) {
                    func_080062F4(work->palette->unk_06 + 16, 1);
                    gUnk_02039BA0->unk_70 |= 16;
                    return 1;
                }

                switch (act->angle) {
                case 173:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 83:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 211:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 45:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 128:
                    dx = -512;
                    dy = 192;
                    dz = 512;
                    dw = 192;
                    break;
                case 0:
                    dx = -512;
                    dy = -192;
                    dz = 512;
                    dw = -192;
                    break;
                case 64:
                    dx = 384;
                    dy = -307;
                    dz = 384;
                    dw = 307;
                    break;
                case 192:
                    dx = -384;
                    dy = -307;
                    dz = -384;
                    dw = 307;
                    break;
                default:
                    dw = 0;
                    dz = 0;
                    dy = 0;
                    dx = 0;
                    break;
                }

                p2 = act->unk_00;
                p1 = p2;
                p1.x += dx;
                p1.y += dy;
                p2.x += dz;
                p2.y += dw;
                a = func_08031D74(&p1);
                b = func_08031D74(&p2);

                if (a != 0) {
                    if (b == 0) {
                        p3 = act->unk_00;
                        p3.x += dz;
                        p3.y += dw;
                        p3.unk_0C = func_08031DF8(&p3);

                        if (p3.unk_0C >= p3.z) {
                            act->unk_00 = p3;
                        }
                    }
                } else if (b != 0) {
                    p4 = act->unk_00;
                    p4.x += dx;
                    p4.y += dy;
                    p4.unk_0C = func_08031DF8(&p4);

                    if (p4.unk_0C >= p4.z) {
                        act->unk_00 = p4;
                    }
                }

                act->unk_10 = 0;
            }
        }

        z = func_08031F1C(work);

        if (act->unk_00.unk_0C == 0x100000) {
            act->unk_00.unk_0C = act->unk_00.z;
        } else if (z != act->unk_00.z) {
            act->unk_10 >>= 2;
            work->unk_A0 = 0;
            work->unk_98 = 0;
            gUnk_02039BA0->unk_68 = 0;
            gUnk_02039BA0->unk_70 |= 0x800000;
            work->unk_94 = 4;
            SetTaskUpdate(task, (u32)func_080324DC);
        } else if (z != act->unk_00.unk_0C) {
            gUnk_02039BA0->unk_68 = 0;
        }
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}

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
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, pri, depth);
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
    work->gfx = AnimGetGfx(work->unk_08);

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
        work->gfx = AnimUpdate(work->unk_08);
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
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
u8 func_08034C88(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    s32 sx;
    s32 sy;
    s32 nx;
    s32 ny;
    s32 z;
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;
    z = func_080346C0(work);
    sx = act->unk_00.x;
    sy = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    if ((work->unk_A4 & 4) == 0) {
        func_08034704(act);
    }

    switch (work->unk_94) {
    case 12:
        if (work->unk_98 == 0) {
            gUnk_02039BA0->unk_68 = 0;
            func_0803473C(work, 14, 0);
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (AnimGetFrame(work->unk_08) > 3) {
            act->unk_00.z += work->unk_A0;
            work->unk_A0 += 66;

            if (act->unk_00.z > z) {
                act->unk_00.z = z;
                work->unk_A0 = 0;
            }
        } else {
            work->unk_A0 = 0;
        }

        act->unk_10 -= 38;

        if (act->unk_10 < 0) {
            act->unk_10 = 0;
        }

        switch (AnimGetFrame(work->unk_08)) {
        case 1:
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->unk_00.x + gSineTable[act->angle] * 12;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->unk_00.x + gSineTable[act->angle] * 27;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->unk_00.x + gSineTable[act->angle] * 20;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->unk_00.z - 0x800);
            break;
        }

        if (AnimIsFinished(work->unk_08) != 0) {
            if (work->unk_A0 < 0) {
                work->unk_94 = 3;
            } else {
                work->unk_94 = 4;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 2:
        if (work->unk_98 == 0) {
            func_0803473C(work, 3, 0);
            act->unk_10 >>= 1;
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (work->unk_98 > 3) {
            work->unk_B8 = gUnk_0203C7AC->unk_1C;

            if (work->unk_B8 == 0) {
                if (GetRandom() % 2 != 0) {
                    m4aSongNumStart(225);
                } else {
                    m4aSongNumStart(226);
                }

                work->unk_94 = 3;
                work->unk_A0 = -1536;
                act->unk_10 <<= 1;
                work->unk_98 = 0;
                act->unk_00.z += work->unk_A0;
                work->unk_A0 += 66;
            } else {
                act->angle = gUnk_0203C7AC->unk_18;
                work->unk_B8 = act->unk_00.z - work->unk_B8;
                work->unk_94 = 13;
                SetTaskUpdate(task, (u32)func_08034AF0);
                work->unk_98 = 0;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 3:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 > -512) {
            func_0803473C(work, 5, 0);
        } else {
            func_0803473C(work, 4, 0);
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 66;

        if (work->unk_A0 < 0) {
            if ((GetKeysHeld() & B_BUTTON) == 0) {
                work->unk_A0 += 64;
            }
        }

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
        } else {
            work->unk_98++;
        }

        break;
    case 4:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 < 0x200) {
            func_0803473C(work, 5, 0);
        } else {
            func_0803473C(work, 6, 0);
        }

        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->unk_00.z += work->unk_A0;
        work->unk_A0 += 66;

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (act->unk_00.z > z) {
            act->unk_00.z = z;
            work->unk_A0 = 0;

            if (work->unk_94 != 5) {
                work->unk_94 = 5;
                work->unk_98 = 0;
            }
        }

        break;
    case 5:
        if (work->unk_98 == 0) {
            func_0803473C(work, 7, 0);
            m4aSongNumStart(work->unk_AC[3]);
        }

        act->unk_10 = 0;

        if ((GetKeysPressed() & B_BUTTON) != 0) {
            work->unk_A4 &= ~4;
            work->unk_98 = 0;
            work->unk_94 = 2;
        } else if (work->unk_98 > 6) {
            gUnk_02039BA0->unk_70 &= ~0x800000;
            work->unk_A4 &= ~4;
            work->unk_94 = 0;
            work->unk_98 = 0;
            SetTaskUpdate(task, (u32)task_fld_riku_1);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 3:
        case 5:
        case 11:
            break;
        default:
            if ((work->unk_66 & 1) == 0) {
                act->unk_10 = 230 * act->unk_10 >> 8;
                act->unk_00.x += work->unk_70;
                act->unk_00.y += work->unk_74;
            }
            break;
        }
    }

    if (func_08034518(&act->unk_00) != 0) {
        act->unk_00.x = sx;
        act->unk_00.y = sy;

        switch (func_080345EC(&act->unk_00, work)) {
        case 2:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 211;
            SetTaskUpdate(task, (u32)func_080353DC);
            break;
        case 1:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 45;
            SetTaskUpdate(task, (u32)func_080353DC);
            break;
        default:
            if (work->unk_94 == 4 && act->unk_00.unk_0C - act->unk_00.z > 0xFFF) {
                p1 = act->unk_00;
                p1.y -= 0x400;
                p1.z = act->unk_00.z - 0x3000;
                p2 = p1;
                p2.z += 768;

                if (func_08034518(&p1) == 0 && func_08034518(&p2) != 0) {
                    work->unk_98 = 0;
                    work->unk_94 = 8;
                    gUnk_02039BA0->unk_68 = 0;
                    SetTaskUpdate(task, (u32)func_080358F0);
                }
            } else {
                act->unk_10 = 230 * act->unk_10 >> 8;
            }
            break;
        }
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);

    if ((gUnk_02039BA0->unk_70 & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08034A0C);
    }

    return 1;
}
u8 func_080353DC(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    s32 x;
    s32 y;
    s32 limit;
    s32 d;
    s32 ny;
    s32 nx;
    s32 tx;
    s32 ty;

    act = &gUnk_02039BA0->unk_18;
    limit = func_080346C0(work);
    x = act->unk_00.x;
    y = act->unk_00.y;
    gUnk_02039BA0->unk_68 = 0;

    switch (work->unk_94) {
    case 6:
        if (work->unk_98 == 0) {
            work->unk_B8 = (act->unk_00.z >> 12) << 12;
            work->unk_98++;
            tx = (work->unk_B0 >> 11) / 4;
            ty = (work->unk_B4 >> 11) / 2;
            nx = (tx << 13) | 0x1000;
            ny = (ty << 12) | 0x800;
            x = nx;
            act->unk_00.x = nx;
            y = ny;
            act->unk_00.y = ny;
            m4aSongNumStart(work->unk_AC[5]);
            act->unk_00.unk_0C = func_080DFF1C(&act->unk_00);
        }

        func_0803473C(work, 8, 1);
        work->unk_16 = ((act->unk_00.z >> 8) + 4) & 31;
        work->gfx = AnimGetGfx(work->unk_08);

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 8:
                m4aSongNumStart(work->unk_AC[4]);
                break;
            case 24:
                m4aSongNumStart(work->unk_AC[5]);
                break;
            }
        }

        d = (((work->unk_B8 >> 12) << 12) - act->unk_00.z) >> 1;

        if (abs(d) <= 24) {
            d = 0;
        } else if (d > 384) {
            d = 384;
        } else if (d < -384) {
            d = -384;
        }

        act->unk_00.z += d;

        if (d < 0) {
            act->unk_00.x += gSineTable[act->angle];
            act->unk_00.y -= gSineTable[act->angle + 64];
            p = act->unk_00;
            p.z = work->unk_B8 - 0x2800;

            if (func_08034518(&p) == 0) {
                act->unk_10 = 204;
                work->unk_A0 = -0x580;
                work->unk_A4 |= 4;
                work->unk_94 = 7;
                work->unk_98 = 0;
                m4aSongNumStart(work->unk_AC[6]);
            }
        } else if (d > 0) {
            if (act->unk_00.z >= limit) {
                act->unk_00.z = limit;
                act->angle += 0x80;
                act->unk_00.x += gSineTable[act->angle] * 10;
                act->unk_00.y += -gSineTable[act->angle + 64] * 10;
                func_0803473C(work, 0, 1);
                work->gfx = AnimGetGfx(work->unk_08);
                work->unk_94 = 0;
                work->unk_98 = 0;
                SetTaskUpdate(task, (u32)task_fld_riku_1);
            }
        } else if (d == 0) {
            if ((GetKeysHeld() & DPAD_UP) || ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0xD3) ||
                ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) - 1) << 12;
            } else if ((GetKeysHeld() & DPAD_DOWN) || ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0xD3) ||
                       ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) + 1) << 12;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->unk_A0 = 0;
            work->unk_98 = 0;
            work->unk_94 = 4;
            act->angle += 0x80;
            act->unk_10 = 0x80;
            work->unk_A4 |= 4;
            act->unk_00.x += gSineTable[act->angle] * 10;
            act->unk_00.y += -gSineTable[act->angle + 64] * 10;
            func_0803473C(work, 6, 0);
            work->gfx = AnimGetGfx(work->unk_08);
            SetTaskUpdate(task, (u32)func_08034C88);
        }

        break;
    case 7:
        func_0803473C(work, 11, 0);
        act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        work->unk_A0 += 0x42;
        act->unk_00.z += work->unk_A0;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (u32)func_08034C88);
        } else {
            work->unk_98++;
        }

        work->gfx = AnimUpdate(work->unk_08);
        break;
    }

    if (func_08034518(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
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

    work->gfx = AnimUpdate(work->unk_08);

    if (func_08034518(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
u8 func_08035AD4(FldWork* work, void* task) {
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;

    switch (work->unk_94) {
    case 15:
        if (work->unk_98 == 0) {
            work->unk_A4 |= 0x10;
            act->angle = 45;
            func_0803473C(work, 2, 1);

            act->unk_00.x = 0x22000;
            act->unk_00.y = 0xF000;
            work->unk_9A = 30;
            act->unk_00.z = 0;
            act->unk_00.unk_0C = 0;
            work->unk_B0 = act->unk_00.x + 0x2000;
            work->unk_B4 = act->unk_00.y - 0x1000;
            work->unk_B8 = act->unk_00.unk_0C - 0x2800;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->unk_00.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->unk_00.y, work->unk_B4, work->unk_9A);
            ApproachValue(&act->unk_00.z, work->unk_B8, work->unk_9A);
            act->unk_00.unk_0C = act->unk_00.z;
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;

            if (work->unk_A4 & 0x20) {
                work->unk_94 = 16;
            } else {
                work->unk_94 = 17;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 16:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->unk_00.x + 0x2000;
            work->unk_B4 = act->unk_00.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->unk_00.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->unk_00.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 18;
        } else {
            work->unk_98++;
        }

        break;
    case 17:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->unk_00.x + 0x2000;
            work->unk_B4 = act->unk_00.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->unk_00.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->unk_00.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 18:
        if (work->unk_98 == 0) {
            func_0803473C(work, 12, 0);
            func_080062F4(work->palette->unk_06 + 16, 1);
        }

        if (work->unk_98 == 40) {
            func_080A5830(work->unk_24, act->unk_00.x, act->unk_00.y, act->unk_00.z);
        }

        if (work->unk_98 > 140) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 19:
        func_080DFC7C();
        break;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}
u8 func_08035DFC(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 nx;
    s32 ny;

    act = &gUnk_02039BA0->unk_18;
    x = act->unk_00.x;
    y = act->unk_00.y;

    if (work->unk_94 == 11) {
        if (work->unk_98 == 0) {
            func_0803473C(work, 13, 0);
            act->unk_10 = 0;
            gUnk_02039BA0->unk_68 = 0;
            work->unk_9A = 0;
            m4aSongNumStart(0xE3);
        }

        if (work->unk_12 == 0) {
            switch (act->angle) {
            case 173:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x500;
                    act->unk_00.y += 0x400;
                    break;
                case 1:
                    act->unk_00.x -= 0x200;
                    break;
                case 2:
                    act->unk_00.x -= 0x300;
                    break;
                }

                break;
            case 83:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x += 0x500;
                    act->unk_00.y += 0x400;
                    break;
                case 1:
                    act->unk_00.x += 0x200;
                    break;
                case 2:
                    act->unk_00.x += 0x300;
                    break;
                }

                break;
            case 211:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x500;
                    act->unk_00.y -= 0x200;
                    break;
                case 1:
                    act->unk_00.x -= 0x500;
                    break;
                case 2:
                    act->unk_00.x -= 0x200;
                    break;
                }

                break;
            case 45:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x += 0x500;
                    act->unk_00.y -= 0x200;
                    break;
                case 1:
                    act->unk_00.x += 0x500;
                    break;
                case 2:
                    act->unk_00.x += 0x200;
                    break;
                }

                break;
            case 128:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x300;
                    act->unk_00.y += 0x400;
                    break;
                case 1:
                    act->unk_00.x += 0x100;
                    act->unk_00.y += 0x100;
                    break;
                case 2:
                    act->unk_00.y += 0x200;
                    break;
                case 3:
                    act->unk_00.y += 0x100;
                    break;
                }

                break;
            case 64:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x += 0x700;
                    act->unk_00.y += 0x100;
                    break;
                case 1:
                    act->unk_00.x += 0x300;
                    break;
                case 2:
                    act->unk_00.x += 0x200;
                    break;
                }

                break;
            case 192:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.x -= 0x700;
                    act->unk_00.y += 0x100;
                    break;
                case 1:
                    act->unk_00.x -= 0x300;
                    break;
                case 2:
                    act->unk_00.x -= 0x200;
                    break;
                }

                break;
            case 0:
                switch (AnimGetFrame(work->unk_08)) {
                case 0:
                    act->unk_00.y -= 0x400;
                    break;
                case 1:
                    act->unk_00.y -= 0x400;
                    break;
                case 2:
                    act->unk_00.x -= 0x100;
                    act->unk_00.y += 0x100;
                    break;
                case 3:
                    act->unk_00.y -= 0x100;
                    break;
                }

                break;
            }
        }

        if (AnimGetFrame(work->unk_08) == 3) {
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->unk_00.x + gSineTable[act->angle] * 12;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->unk_00.x + gSineTable[act->angle] * 27;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->unk_00.x + gSineTable[act->angle] * 20;
                ny = act->unk_00.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->unk_00.z - 0x800);
        }

        if (AnimIsFinished(work->unk_08) != 0) {
            switch (act->angle) {
            case 173:
                act->unk_00.x -= 0x200;
                act->unk_00.y += 0x200;
                break;
            case 83:
                act->unk_00.x += 0x200;
                act->unk_00.y += 0x200;
                break;
            case 45:
            case 211:
                act->unk_00.y -= 0x400;
                break;
            case 128:
                act->unk_00.y += 0x200;
                break;
            case 0:
                act->unk_00.y -= 0x200;
                break;
            }

            func_0803473C(work, 0, 0);
            work->unk_94 = 0;
            SetTaskUpdate(task, (u32)task_fld_riku_1);
        } else {
            work->unk_98++;
        }
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 5:
        case 3:
        case 11:
            break;
        default:
            if ((work->unk_66 & 1) == 0) {
                act->unk_00.x += work->unk_70;
                act->unk_00.y += work->unk_74;
            }

            break;
        }
    }

    if (func_08034518(&act->unk_00) != 0) {
        act->unk_00.x = x;
        act->unk_00.y = y;
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08034A0C);
        TaskPoolUpdate(work->unk_24);
    }

    return 1;
}
u8 task_fld_riku_1(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    FldPos p3;
    FldPos p4;
    s32 sx;
    s32 sy;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dw;
    s32 z;
    s32 r;
    u8 a;
    u8 b;
    FldActor* act;

    act = &gUnk_02039BA0->unk_18;

    if ((work->unk_A4 & 8) != 0) {
        work->unk_A4 &= ~8;

        switch (work->unk_94) {
        case 12:
            work->unk_94 = 3;
        case 2:
        case 3:
        case 4:
        case 5:
            SetTaskUpdate(task, (u32)func_08034C88);
            gUnk_02039BA0->unk_68 = 0;
            break;
        case 6:
        case 7:
            SetTaskUpdate(task, (u32)func_080353DC);
            gUnk_02039BA0->unk_68 = 0;
            work->unk_98 = 1;
            break;
        case 8:
        case 9:
        case 10:
            SetTaskUpdate(task, (u32)func_080358F0);
            gUnk_02039BA0->unk_68 = 0;
            break;
        default:
            work->unk_94 = 0;
            break;
        }

        func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
        func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
        work->gfx = AnimUpdate(work->unk_08);
        TaskPoolUpdate(work->unk_24);
        return 1;
    } else if (func_080DFC24() != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08035AD4);
        TaskPoolUpdate(work->unk_24);
        work->unk_94 = 15;

        if (func_080DFC24() == 1) {
            work->unk_A4 |= 0x20;
        }

        return 1;
    } else if ((gUnk_02039BA0->unk_70 & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (u32)func_08034A0C);
        TaskPoolUpdate(work->unk_24);
        return 1;
    } else {
        sx = act->unk_00.x;
        sy = act->unk_00.y;

        if (work->unk_94 <= 1) {
            if ((gUnk_02039BA0->unk_70 & 0x4000) == 0) {
                func_08034704(act);
            }

            if ((gUnk_02039BA0->unk_70 & 0x4000) == 0 && (GetKeysHeld() & DPAD_ANY) != 0) {
                act->unk_10 += 128;
                func_0803473C(work, 2, 1);

                if (act->unk_10 > 0x300) {
                    act->unk_10 = 0x300;
                }

                if (work->unk_12 == 0) {
                    switch (work->unk_16) {
                    case 3:
                        m4aSongNumStart(work->unk_AC[0]);
                        break;
                    case 7:
                        m4aSongNumStart(work->unk_AC[1]);
                        break;
                    }
                }
            } else {
                func_0803473C(work, 0, 1);
                act->unk_10 -= 128;

                if (act->unk_10 < 0) {
                    act->unk_10 = 0;
                }
            }

            act->unk_00.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->unk_00.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

            if ((GetKeysPressed() & B_BUTTON) != 0) {
                gUnk_02039BA0->unk_70 |= 0x800000;
                gUnk_02039BA0->unk_68 = 0;
                work->unk_98 = 0;
                work->unk_94 = 2;
                SetTaskUpdate(task, (u32)func_08034C88);
                m4aSongNumStart(work->unk_AC[2]);
            } else if ((GetKeysPressed() & A_BUTTON) != 0) {
                work->unk_98 = 0;
                gUnk_02039BA0->unk_68 = 0;
                work->unk_94 = 11;
                SetTaskUpdate(task, (u32)func_08035DFC);
            }
        } else if (AnimIsFinished(work->unk_08) != 0) {
            work->unk_94 = 0;
        }

        if (work->unk_64 != 0) {
            switch (work->unk_6C) {
            case 3:
            case 5:
            case 11:
                break;
            default:
                if ((work->unk_66 & 1) == 0) {
                    act->unk_10 = 230 * act->unk_10 >> 8;
                    act->unk_00.x += work->unk_70;
                    act->unk_00.y += work->unk_74;
                }
                break;
            }
        }

        if (func_08034518(&act->unk_00) != 0) {
            act->unk_00.x = sx;
            act->unk_00.y = sy;
            r = func_080345EC(&act->unk_00, work);

            if (r != 0) {
                switch (r) {
                case 2:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 211;
                    gUnk_02039BA0->unk_68 = 0;
                    SetTaskUpdate(task, (u32)func_080353DC);
                    break;
                case 1:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 45;
                    gUnk_02039BA0->unk_68 = 0;
                    SetTaskUpdate(task, (u32)func_080353DC);
                    break;
                }
            } else {
                if (func_08034668(&act->unk_00) != 0) {
                    func_080062F4(work->palette->unk_06 + 16, 1);
                    gUnk_02039BA0->unk_70 |= 16;
                    return 1;
                }

                switch (act->angle) {
                case 173:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 83:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 211:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 45:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 128:
                    dx = -512;
                    dy = 192;
                    dz = 512;
                    dw = 192;
                    break;
                case 0:
                    dx = -512;
                    dy = -192;
                    dz = 512;
                    dw = -192;
                    break;
                case 64:
                    dx = 384;
                    dy = -307;
                    dz = 384;
                    dw = 307;
                    break;
                case 192:
                    dx = -384;
                    dy = -307;
                    dz = -384;
                    dw = 307;
                    break;
                default:
                    dw = 0;
                    dz = 0;
                    dy = 0;
                    dx = 0;
                    break;
                }

                p2 = act->unk_00;
                p1 = p2;
                p1.x += dx;
                p1.y += dy;
                p2.x += dz;
                p2.y += dw;
                a = func_08034518(&p1);
                b = func_08034518(&p2);

                if (a != 0) {
                    if (b == 0) {
                        p3 = act->unk_00;
                        p3.x += dz;
                        p3.y += dw;
                        p3.unk_0C = func_0803459C(&p3);

                        if (p3.unk_0C >= p3.z) {
                            act->unk_00 = p3;
                        }
                    }
                } else if (b != 0) {
                    p4 = act->unk_00;
                    p4.x += dx;
                    p4.y += dy;
                    p4.unk_0C = func_0803459C(&p4);

                    if (p4.unk_0C >= p4.z) {
                        act->unk_00 = p4;
                    }
                }

                act->unk_10 = 0;
            }
        }

        z = func_080346C0(work);

        if (act->unk_00.unk_0C == 0x100000) {
            act->unk_00.unk_0C = act->unk_00.z;
        } else if (z != act->unk_00.z) {
            act->unk_10 >>= 2;
            work->unk_A0 = 0;
            work->unk_98 = 0;
            gUnk_02039BA0->unk_68 = 0;
            gUnk_02039BA0->unk_70 |= 0x800000;
            work->unk_94 = 4;
            SetTaskUpdate(task, (u32)func_08034C88);
        } else if (z != act->unk_00.unk_0C) {
            gUnk_02039BA0->unk_68 = 0;
        }
    }

    func_08012324(work->unk_38, act->unk_00.x, act->unk_00.y, act->unk_00.z);
    func_080E0298(act->unk_00.x, act->unk_00.y + act->unk_00.z);
    work->gfx = AnimUpdate(work->unk_08);
    TaskPoolUpdate(work->unk_24);
    return 1;
}

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
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, pri, depth);
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
    AnimInit(work->anim, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(work->anim, 0, 1);
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

    spr = AnimUpdate(work->anim);
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
