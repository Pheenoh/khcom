#include "macros.h"
#include "mode_backupstat.h"
#include "gba/keys.h"

void mode_backupstat_0(void) {
    s32 i;
    s32 j;

    func_08004DB0();
    SetupBg(0, 0, 15, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08128304, 32, 15);
    gUnk_02035FE8 = 0;
    func_0805FCB0(0, 0, 2, gUnk_09993874);
    gUnk_02035FE9 = 6;
    gUnk_02035FEC = gUnk_099937E4;

    for (i = 0; i < gUnk_02035FE9; i++) {
        for (j = 0; j <= 1; j++) {
            switch (i) {
            case 0:
                gUnk_02035FF0[i * 2 + j] = SaveCheckHeaderSlot(j);
                break;
            case 1:
                gUnk_02035FF0[i * 2 + j] = SaveCheckFileLargeSlot(0, j);
                break;
            case 2:
                gUnk_02035FF0[i * 2 + j] = SaveCheckFileLargeSlot(1, j);
                break;
            case 3:
                gUnk_02035FF0[i * 2 + j] = SaveCheckFileSmallSlot(0, j);
                break;
            case 4:
                gUnk_02035FF0[i * 2 + j] = SaveCheckFileSmallSlot(1, j);
                break;
            case 5:
                gUnk_02035FF0[i * 2 + j] = SaveCheckSystemSlot(j);
                break;
            }
        }
    }

    for (i = 0; i < gUnk_02035FE9 * 2; i++) {
        func_0805FCB0(12, i * 9, 2, gUnk_02035FEC[i / 2].name);

        switch (i % 2) {
        case 0:
            func_0805FCB0(75, i * 9, 2, gUnk_09993878);
            break;
        case 1:
            func_0805FCB0(75, i * 9, 2, gUnk_09993880);
            break;
        }
        func_0805FCB0(120, i * 9, 2, gUnk_09EF9668[gUnk_02035FF0[i]]);
    }
}

void func_081097F4(void) {
    u16 slot;

    slot = gUnk_02035FE8 % 2;

    switch (gUnk_02035FE8 / 2) {
    case 0:
        SaveSetHeaderState(slot, gUnk_02035FF0[gUnk_02035FE8]);
        break;
    case 1:
        SaveSetFileLargeState(0, slot, gUnk_02035FF0[gUnk_02035FE8]);
        break;
    case 2:
        SaveSetFileLargeState(1, slot, gUnk_02035FF0[gUnk_02035FE8]);
        break;
    case 3:
        SaveSetFileSmallState(0, slot, gUnk_02035FF0[gUnk_02035FE8]);
        break;
    case 4:
        SaveSetFileSmallState(1, slot, gUnk_02035FF0[gUnk_02035FE8]);
        break;
    case 5:
        SaveSetSystemState(slot, gUnk_02035FF0[gUnk_02035FE8]);
        break;
    }
    func_0805FCB0(120, gUnk_02035FE8 * 9, 2, gUnk_09EF9668[gUnk_02035FF0[gUnk_02035FE8]]);
}

void mode_backupstat_1(void) {
    u8 prev;

    prev = gUnk_02035FE8;

    if (GetKeysRepeat() & DPAD_UP) {
        gUnk_02035FE8--;
    } else if (GetKeysRepeat() & DPAD_DOWN) {
        gUnk_02035FE8++;
    }

    if (prev != gUnk_02035FE8) {
        if (gUnk_02035FE8 < 0) {
            gUnk_02035FE8 = gUnk_02035FE9 * 2 - 1;
        } else if (gUnk_02035FE8 >= gUnk_02035FE9 * 2) {
            gUnk_02035FE8 = 0;
        }
        func_0805FCB0(0, prev * 9, 2, gUnk_09993888);
        func_0805FCB0(0, gUnk_02035FE8 * 9, 2, gUnk_09993874);
    }

    if ((GetKeysPressed() & DPAD_LEFT) != 0) {
        if (--gUnk_02035FF0[gUnk_02035FE8] < 0) {
            gUnk_02035FF0[gUnk_02035FE8] = 2;
        }
        func_081097F4();
    } else if (GetKeysPressed() & DPAD_RIGHT) {
        if (++gUnk_02035FF0[gUnk_02035FE8] > 2) {
            gUnk_02035FF0[gUnk_02035FE8] = 0;
        }
        func_081097F4();
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) {
        ModeRequest(&gUnk_09ECEB64, 0);
    } else {
        func_080605A4(0);
        func_08060598();
    }
}

void mode_backupstat_2(void) {
    func_080609A0();
}

INCLUDE_ASM("mode_backupstat/func_08109AAC.s");

s32 func_08109EA8(s32 a) {
    return a * a;
}

PcAnimStep* func_08109EB0(PcWork* work) {
    return work->unk_02C != 0 ? &work->unk_02C[work->unk_032] : gUnk_09A4AF34;
}

void* func_08109ECC(PcWork* work) {
    PcAnimStep* step;

    if (work->unk_02C == 0) {
        return gUnk_09A3DF34;
    }
    step = &work->unk_02C[work->unk_032];
    return gUnk_09EF9C34[step->unk_20];
}

void func_08109EF8(PcWork* work, s32 a) {
    if (work->unk_02C != gUnk_09EF9DB4[a]) {
        work->unk_02C = gUnk_09EF9DB4[a];
        work->unk_030 = 0;
        work->unk_034 = 0;
        work->unk_032 = 0;
        work->unk_036 = -1;
    }
}

void func_08109F20(PcWork* work) {
    PcAnimStep* step;
    s32 cont;
    s32 v;

    cont = work->unk_034 >= 0;
    while (cont) {
        step = &work->unk_02C[work->unk_030];
        switch (step->unk_00) {
        case 0:
            work->unk_034++;
            if (work->unk_034 > step->unk_22) {
                work->unk_030++;
                do {
                    work->unk_034 = 0;
                } while (0);
            } else {
                work->unk_032 = work->unk_030;
                cont = 0;
            }
            break;
        case 1:
            work->unk_030 = 0;
            work->unk_034 = 0;
            break;
        case 2:
            work->unk_034 = 0xFFFF;
            cont = 0;
            break;
        }
    }
    step = &work->unk_02C[work->unk_032];
    if (step->unk_00 == 0) {
        if (work->unk_034 == 0) {
            v = work->unk_2E8.unk_00;
            if (v < 0x20) {
                work->unk_034 += step->unk_22 / 2;
            } else if (v < 0x40) {
                work->unk_034 += step->unk_22 / 4;
            } else if (v < 0x80) {
                work->unk_034 += step->unk_22 / 8;
            }
        }
    }
}

u16 func_08109FF0(PcWork* work, s32 a) {
    return func_0801AF1C(a);
}

u16 func_0810A000(PcWork* work, s32 a, s32 b) {
    return (0xEFFC - ((a >> 8) << 2)) | b;
}

#ifdef NON_MATCHING
void func_0810A018(PcWork* work) {
    PcAnimStep* step;
    PcSpriteCmd* cmd;
    PcSpriteDef* def;
    PcOam* oam;
    void* gfx;
    s16 sx;
    s16 sy;
    s16 ox;
    s16 oy;
    s32 i;
    s32 j;
    u16 t;

    if (work->unk_02C == 0) {
        return;
    }
    step = &work->unk_02C[work->unk_032];
    if (step->unk_00 != 0) {
        return;
    }
    ox = 0;
    oy = 0;

    if (work->unk_2E8.unk_05 == 1) {
        ox = gUnk_02039DC8->unk_68;
        oy = gUnk_02039DC8->unk_6A;
    }
    gfx = work->unk_04C;

    if (work->unk_018 == 0) {
        if (func_0801CA00(&work->unk_054)) {
            gfx = work->unk_050;
            work->unk_00A = 1;
        } else {
            work->unk_00A = 0;
        }
    } else {
        work->unk_00A = 0;
    }

    if (work->unk_00A != work->unk_00C) {
        if (work->unk_00A == 0) {
            LoadPalette(gUnk_09D69274, gUnk_05000000, 32);
        } else {
            LoadPalette(gUnk_08F69BC4, gUnk_05000000, 32);
        }
        work->unk_00C = work->unk_00A;
    }
    WorldToScreen(&sx, &sy, work->unk_020 - ox * 256, work->unk_024 - oy * 256, work->unk_028);
    cmd = gUnk_09EF9C34[step->unk_20];

    for (i = 23; i >= 0; i--) {
        work->unk_2FC[i].count = 0;
    }

    j = 0;

    while (!(cmd->unk_00 & 0x80)) {
        if (cmd->unk_00 & 1) {
            DrawSprite(cmd->unk_04 + sx, cmd->unk_06 + sy, gUnk_09EFAB18[cmd->unk_01],
                work->unk_044[j], gfx, 0,
                func_08109FF0(work, work->unk_024 + (cmd->unk_02 << 10) - 0x3300),
                func_0810A000(work, work->unk_024 + (cmd->unk_02 << 10) - 0x3300, 1));
        } else {
            def = gUnk_09EFBB18[cmd->unk_01];
            oam = &work->unk_2FC[cmd->unk_02];
            t = (u8)def->unk_02;
            if (t & 0x80) {
                t |= 0xFF00;
            }

            if ((u16)((s16)((s16)t + cmd->unk_06) + sy + 7) <= 0xAE) {
                oam->attr[oam->count * 3 + 1] = (def->unk_02 & 0xFF00) | ((cmd->unk_06 + def->unk_02 + 0x40) & 0xFF);
                oam->attr[oam->count * 3 + 2] = (def->unk_04 & 0xFE00) | ((def->unk_04 + cmd->unk_04) & 0x1FF);
                oam->attr[oam->count * 3 + 3] = def->unk_06;
                oam->count++;
            }
        }
        cmd++;
        j++;
    }

    for (i = 23; i >= 0; i--) {
        if (work->unk_2FC[i].count != 0) {
            work->unk_2FC[i].attr[0] = work->unk_2FC[i].count;
            DrawSprite(sx, sy - 0x40, work->unk_2FC[i].attr, work->unk_040, gfx, 0,
                func_08109FF0(work, work->unk_024 + i * 0x400 - 0x3400),
                func_0810A000(work, work->unk_024 + i * 0x400 - 0x3400, 1));
        }
    }

    if (work->unk_02C == gUnk_09A4C278) {
        gUnk_02039B84->unk_0D8 = 24;
    } else {
        gUnk_02039B84->unk_0D8 = 0xFFF6;
    }
    WorldToScreen(&sx, &sy, work->unk_020 + ((-0x70 - ox) << 8), work->unk_024 + ((-0x64 - oy) << 8), work->unk_028);

    if (work->unk_032 != work->unk_036) {
        LoadBgTiles(1, gUnk_09A4AC84[step->unk_1E].unk_00, gUnk_09A4AC84[step->unk_1E].unk_04);
        LoadBgMap(1, gUnk_09A4AC84[step->unk_1E].unk_08, gUnk_09A4AC84[step->unk_1E].unk_0C);
        work->unk_036 = work->unk_032;
    }
    SetBgScroll(1, 0x50 - sx, 8 - sy);
}
#else
INCLUDE_ASM("mode_backupstat/func_0810A018.s");
#endif

u8 func_0810A424(PcWork* work) {
    PcAnimStep* step;

    if (work->unk_02C != 0) {
        step = &work->unk_02C[work->unk_030];
        if (step->unk_00 != 2) {
            return 0;
        }
    }
    return 1;
}

void func_0810A444(PcWork* work) {
    work->unk_038 = 1;
    work->unk_03A = 0;
    work->unk_03C = 0;
}

void func_0810A454(PcWork* work) {
    if (work->unk_038 != 0) {
        if (work->unk_03C > gUnk_09A4C9F2[work->unk_03A]) {
            work->unk_03A = gUnk_09A4C9EC[work->unk_03A];
            work->unk_03C = 0;
        }
        work->unk_03C++;
    }
}

void func_0810A498(PcWork* work) {
    if (work->unk_038 != 0) {
        LoadPalette(&gUnk_09D69374[work->unk_03A * 32], gUnk_05000080, 32);
    }
}

void func_0810A4C4(PcWork* work) {
    work->unk_038 = 0;
}

void func_0810A4CC(PcWork* work, u16 a, s32 b, s32 c, s32 d, u8 e) {
    PcSpawnArg arg;

    arg.unk_00 = e;
    arg.unk_02 = a << 8;
    arg.unk_04 = b;
    arg.unk_08 = c;
    arg.unk_0C = d;
    arg.unk_10 = &work->unk_2E8;
    work->unk_2D4[e] = TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF9E24, &arg);
}

void func_0810A51C(PcWork* work, TaskPool* pool) {
    if ((s32)pool > 0x01FFFFFF) {
        gUnk_02039B84->unk_07C->unk_04 = 0xFE00;
        gUnk_02039B84->unk_07C->unk_08 = 0x15D00;
        gUnk_02039B84->unk_07C->unk_0C = 0;
        work->unk_2E4 = TaskCreate(pool, &gUnk_09EF9E3C, &work->unk_2E8);
    } else {
        work->unk_2E4 = TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF9E3C, &work->unk_2E8);
    }
}
