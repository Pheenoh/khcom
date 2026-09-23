#include "task_descriptors.h"
#include "map_api.h"
#include "m4a_song.h"
#include "roomcreate.h"

const char gTaskNameRoomcreate[] = "task_roomcreate";

void task_roomcreate_0(RoomCreateWork* work) {
    FldActor* act;

    func_08093C04();
    gFieldState->flags |= 0x40000;
    gFieldState->flags |= 2;
    work->unk_29 = 0;
    work->unk_28 = 0;
    work->unk_26 = 0;
    work->state = 0;
    SetBgPriority(0, 2);
    SetBgPriority(1, 2);
    TaskPoolInit(&work->tasks, 3);
    work->x = gFieldState->actor.fieldPosition.x;
    work->y = gFieldState->actor.fieldPosition.y;
    work->z = gFieldState->actor.fieldPosition.z;
    act = gFieldState->unk_68;
    work->x2 = act->fieldPosition.x;
    work->y2 = act->fieldPosition.y;
    work->z2 = act->fieldPosition.z;
    work->angle = act->angle;
    work->unk_18 = work->x2 + gSineTable[work->angle] * 50;
    work->unk_1C = work->y2 + -gSineTable[work->angle + 0x40] * 50;
    work->unk_20 = work->z2;
    work->unk_25 = gFieldState->actor.angle;
}

u8 task_roomcreate_1(RoomCreateWork* work) {
    s16 steps;
    s32 i;

    switch (work->state) {
    case 0:
        if (work->unk_26 == 0) {
            gFieldState->actor.angle = work->angle + 0x80;
            TaskCreate(&work->tasks, &gTaskDescSpotLight, &work->unk_28);
            gFieldState->flags |= 0x80000;
        }
        steps = 30 - work->unk_26;
        ApproachValue(&gFieldState->actor.fieldPosition.x, work->unk_18, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.y, work->unk_1C, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.z, work->unk_20, steps);

        if (steps <= 1) {
            func_080E0418();
            work->state = 1;
            gFieldState->flags &= ~0x80000;
            work->unk_26 = 8;
        } else {
            func_080E0298((gFieldState->actor.fieldPosition.x + work->x2) / 2,
                          (gFieldState->actor.fieldPosition.y + gFieldState->actor.fieldPosition.z + work->y2 + work->z2) / 2);
            work->unk_26++;
        }
        break;
    case 1:
        if (work->unk_26 > 0) {
            ApproachValue(&gFieldState->x, gFieldState->x2 - 0x7800, work->unk_26);
            ApproachValue(&gFieldState->y, gFieldState->y2 - 0x6000, work->unk_26);
            work->unk_26--;
        } else if (work->unk_26 == 0) {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x80);
            CreateMapCardSelection(&work->tasks, &work->unk_29);
            SetBgPriority(1, 1);
            work->unk_26--;
        }

        switch (work->unk_29) {
        case 1:
            work->state = 2;
            work->unk_26 = 0;
            func_080E042C();
            SetBgPriority(1, 2);
            break;
        case 2:
            work->state = 3;
            work->unk_26 = 0;
            break;
        }
        break;
    case 3:
        if (work->unk_26 == 0) {
            gFieldState->flags |= 0x100000;
            DisableBg(2);
            DisableBg(3);
            FadeStartIn(0, 1);
            work->unk_26++;
        } else if (work->unk_26 == 1) {
            for (i = 0; i <= 31; i++) {
                FadeSetPaletteExcluded(i, 0);
            }
            work->unk_26++;
        } else if (work->unk_26 <= 19) {
            work->unk_26++;
        } else if (work->unk_26 == 20) {
            m4aSongNumStart(0x77);
            TaskCreate(&work->tasks, &gTaskDescRomcriEff2, (void*)(u32)work->angle);
            work->unk_26++;
        }

        if (work->unk_29 == 1) {
            work->unk_26 = 0;
            work->state = 4;
        }
        break;
    case 4:
        if (work->unk_26 == 16) {
            TaskCreate(&work->tasks, &gTaskDescRomcriEff, (void*)(u32)work->angle);
        }

        if (work->unk_26 == 40) {
            gFieldState->flags |= 0x200000;
        }

        if (work->unk_26 > 60) {
            work->unk_26 = 0;
            work->state = 6;
            gFieldState->flags &= ~0x100000;
        } else {
            work->unk_26++;
        }
        break;
    case 5:
        if (work->unk_26 > 60) {
            work->unk_26 = 0;
            work->state = 6;
        } else {
            work->unk_26++;
        }
        break;
    case 2:
        if (work->unk_26 == 0) {
            work->unk_28 = 1;
            gFieldState->flags |= 0x80000;
        }
        steps = 30 - work->unk_26;
        ApproachValue(&gFieldState->actor.fieldPosition.x, work->x, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.y, work->y, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.z, work->z, steps);

        if (steps <= 1) {
            gFieldState->actor.angle = work->unk_25;
            gFieldState->flags &= ~0x40000;
            gFieldState->flags &= ~2;
            DisableBg(0);
            SetBgPriority(1, 1);
            return 0;
        }
        work->unk_26++;
        func_080E0298((gFieldState->actor.fieldPosition.x + work->x2) / 2,
                      (gFieldState->actor.fieldPosition.y + gFieldState->actor.fieldPosition.z + work->y2 + work->z2) / 2);
        break;
    case 6:
        if (work->unk_26 == 0) {
            gFieldState->flags |= 0x80000;
        }
        steps = 40 - work->unk_26;
        ApproachValue(&gFieldState->actor.fieldPosition.x, work->x2, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.y, work->y2, steps);
        ApproachValue(&gFieldState->actor.fieldPosition.z, work->z2, steps);

        if (func_080DFD84(&gFieldState->actor.fieldPosition)) {
            gFieldState->flags |= 0x10;
        }
        break;
    case 7:
        break;
    }
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_roomcreate_2(RoomCreateWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_roomcreate_3(RoomCreateWork* work) {
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
    TaskPoolDestroy(&work->tasks);
}

TaskDesc gTaskDescRoomcreate = { gTaskNameRoomcreate, task_roomcreate_0, task_roomcreate_1, task_roomcreate_2, task_roomcreate_3, 0x44 };
