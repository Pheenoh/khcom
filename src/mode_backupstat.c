#include "macros.h"
#include "mode_backupstat.h"

void mode_backupstat_0(void) {
    s32 i;
    s32 j;

    func_08004DB0();
    SetupBg(0, 0, 15, 0);
    func_08004FC8(0);
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
    if (GetKeysRepeat() & 0x40) {
        gUnk_02035FE8--;
    } else if (GetKeysRepeat() & 0x80) {
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

    if ((GetKeysPressed() & 0x20) != 0) {
        if (--gUnk_02035FF0[gUnk_02035FE8] < 0) {
            gUnk_02035FF0[gUnk_02035FE8] = 2;
        }
        func_081097F4();
    } else if (GetKeysPressed() & 0x10) {
        if (++gUnk_02035FF0[gUnk_02035FE8] > 2) {
            gUnk_02035FF0[gUnk_02035FE8] = 0;
        }
        func_081097F4();
    }

    if (GetKeysPressed() & 0xF) {
        func_080010CC(&gUnk_09ECEB64, 0);
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

INCLUDE_ASM("mode_backupstat/func_0810A018.s");

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
