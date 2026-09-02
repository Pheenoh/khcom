#include "macros.h"
#include "roomcreate.h"


void task_roomcreate_0(RoomCreateWork* work) {
    FldActor* act;

    func_08093C04();
    gUnk_02039BA0->unk_70 |= 0x40000;
    gUnk_02039BA0->unk_70 |= 2;
    work->unk_29 = 0;
    work->unk_28 = 0;
    work->unk_26 = 0;
    work->unk_40 = 0;
    SetBgPriority(0, 2);
    SetBgPriority(1, 2);
    TaskPoolInit(&work->unk_2C, 3);
    work->unk_00 = gUnk_02039BA0->unk_18.unk_00.unk_00;
    work->unk_04 = gUnk_02039BA0->unk_18.unk_00.unk_04;
    work->unk_08 = gUnk_02039BA0->unk_18.unk_00.unk_08;
    act = gUnk_02039BA0->unk_68;
    work->unk_0C = act->unk_00.unk_00;
    work->unk_10 = act->unk_00.unk_04;
    work->unk_14 = act->unk_00.unk_08;
    work->unk_24 = act->unk_14;
    work->unk_18 = work->unk_0C + gSineTable[work->unk_24] * 50;
    work->unk_1C = work->unk_10 + -gSineTable[work->unk_24 + 0x40] * 50;
    work->unk_20 = work->unk_14;
    work->unk_25 = gUnk_02039BA0->unk_18.unk_14;
}

u8 task_roomcreate_1(RoomCreateWork* work) {
    s16 steps;
    s32 i;

    switch (work->unk_40) {
    case 0:
        if (work->unk_26 == 0) {
            gUnk_02039BA0->unk_18.unk_14 = work->unk_24 + 0x80;
            TaskCreate(&work->unk_2C, &gUnk_09EE7668, &work->unk_28);
            gUnk_02039BA0->unk_70 |= 0x80000;
        }
        steps = 30 - work->unk_26;
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_00, work->unk_18, steps);
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_04, work->unk_1C, steps);
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_08, work->unk_20, steps);
        if (steps <= 1) {
            func_080E0418();
            work->unk_40 = 1;
            gUnk_02039BA0->unk_70 &= ~0x80000;
            work->unk_26 = 8;
        } else {
            func_080E0298((gUnk_02039BA0->unk_18.unk_00.unk_00 + work->unk_0C) / 2,
                          (gUnk_02039BA0->unk_18.unk_00.unk_04 + gUnk_02039BA0->unk_18.unk_00.unk_08 + work->unk_10 + work->unk_14) / 2);
            work->unk_26++;
        }
        break;
    case 1:
        if (work->unk_26 > 0) {
            ApproachValue(&gUnk_02039BA0->unk_00, gUnk_02039BA0->unk_08 - 0x7800, work->unk_26);
            ApproachValue(&gUnk_02039BA0->unk_04, gUnk_02039BA0->unk_0C - 0x6000, work->unk_26);
            work->unk_26--;
        } else if (work->unk_26 == 0) {
            m4aMPlayVolumeControl(gUnk_0203DB10, 0xFF, 0x80);
            func_08093B78(&work->unk_2C, &work->unk_29);
            SetBgPriority(1, 1);
            work->unk_26--;
        }
        switch (work->unk_29) {
        case 1:
            work->unk_40 = 2;
            work->unk_26 = 0;
            func_080E042C();
            SetBgPriority(1, 2);
            break;
        case 2:
            work->unk_40 = 3;
            work->unk_26 = 0;
            break;
        }
        break;
    case 3:
        if (work->unk_26 == 0) {
            gUnk_02039BA0->unk_70 |= 0x100000;
            DisableBg(2);
            DisableBg(3);
            func_08006120(0, 1);
            work->unk_26++;
        } else if (work->unk_26 == 1) {
            for (i = 0; i <= 31; i++) {
                func_080062F4(i, 0);
            }
            work->unk_26++;
        } else if (work->unk_26 <= 19) {
            work->unk_26++;
        } else if (work->unk_26 == 20) {
            m4aSongNumStart(0x77);
            TaskCreate(&work->unk_2C, &gUnk_09EDB398, (void*)(u32)work->unk_24);
            work->unk_26++;
        }
        if (work->unk_29 == 1) {
            work->unk_26 = 0;
            work->unk_40 = 4;
        }
        break;
    case 4:
        if (work->unk_26 == 16) {
            TaskCreate(&work->unk_2C, &gUnk_09EDB380, (void*)(u32)work->unk_24);
        }
        if (work->unk_26 == 40) {
            gUnk_02039BA0->unk_70 |= 0x200000;
        }
        if (work->unk_26 > 60) {
            work->unk_26 = 0;
            work->unk_40 = 6;
            gUnk_02039BA0->unk_70 &= ~0x100000;
        } else {
            work->unk_26++;
        }
        break;
    case 5:
        if (work->unk_26 > 60) {
            work->unk_26 = 0;
            work->unk_40 = 6;
        } else {
            work->unk_26++;
        }
        break;
    case 2:
        if (work->unk_26 == 0) {
            work->unk_28 = 1;
            gUnk_02039BA0->unk_70 |= 0x80000;
        }
        steps = 30 - work->unk_26;
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_00, work->unk_00, steps);
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_04, work->unk_04, steps);
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_08, work->unk_08, steps);
        if (steps <= 1) {
            gUnk_02039BA0->unk_18.unk_14 = work->unk_25;
            gUnk_02039BA0->unk_70 &= ~0x40000;
            gUnk_02039BA0->unk_70 &= ~2;
            DisableBg(0);
            SetBgPriority(1, 1);
            return 0;
        }
        work->unk_26++;
        func_080E0298((gUnk_02039BA0->unk_18.unk_00.unk_00 + work->unk_0C) / 2,
                      (gUnk_02039BA0->unk_18.unk_00.unk_04 + gUnk_02039BA0->unk_18.unk_00.unk_08 + work->unk_10 + work->unk_14) / 2);
        break;
    case 6:
        if (work->unk_26 == 0) {
            gUnk_02039BA0->unk_70 |= 0x80000;
        }
        steps = 40 - work->unk_26;
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_00, work->unk_0C, steps);
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_04, work->unk_10, steps);
        ApproachValue(&gUnk_02039BA0->unk_18.unk_00.unk_08, work->unk_14, steps);
        if (func_080DFD84(&gUnk_02039BA0->unk_18.unk_00)) {
            gUnk_02039BA0->unk_70 |= 0x10;
        }
        break;
    case 7:
        break;
    }
    TaskPoolUpdate(&work->unk_2C);
    return 1;
}

void task_roomcreate_2(RoomCreateWork* work) {
    TaskPoolDraw(&work->unk_2C);
}

void task_roomcreate_3(RoomCreateWork* work) {
    m4aMPlayVolumeControl(gUnk_0203DB10, 0xFF, 0x100);
    TaskPoolDestroy(&work->unk_2C);
}
