#include "macros.h"
#include "registration_data.h"
#include "boss_tm.h"
#include "boss_tm_assets.h"
#include "chara_api.h"
#include "acgtrans.h"

s16 gUnk_0203AB3C EWRAM_COMMON(4);
s16 gUnk_0203AB40 EWRAM_COMMON(4);
s16 gUnk_0203AB44 EWRAM_COMMON(4);
s16 gUnk_0203AB48 EWRAM_COMMON(4);

const char gTaskNameBosTm[] = "task_bos_tm";

static Task* gBosTmBodyTask;
static Task* gBosTmArmTask;
static Task* gBosTmFootTask;
static Task* gBosTmTblTask;
static TaskPool gBosTmTaskPool;

void func_080B7E68(TmWork* w) {
    if (w->flags & 0x20) {
        w->unk_48 = w->x2 + 0x1000;
        w->unk_54 = w->x2 - 0x700;
        w->unk_4C = w->y2 + 0x700;
        w->unk_58 = w->y2 - 0x400;
        w->unk_50 = w->z2 - 0x2200;
        w->unk_5C = w->z2 - 0x1C00;
    } else {
        w->unk_48 = w->x2 + 0x700;
        w->unk_54 = w->x2 - 0xE00;
        w->unk_4C = w->y2 - 0x400;
        w->unk_58 = w->y2 + 0x700;
        w->unk_50 = w->z2 - 0x1C00;
        w->unk_5C = w->z2 - 0x2200;
    }
}

void task_bos_tm_0(TmWork* w, BtlObj* arg) {
    w->flags = 0;

    if (arg != 0) {
        w->flags = 8;
    }
    TaskPoolInit(&gBosTmTaskPool, 4);

    if (w->flags & 8) {
        w->x = arg->x >> 8;
        w->y = arg->y >> 8;
        w->z = arg->z >> 8;
    } else {
        w->x = 0x15D;
        w->y = 0x16C;
        w->z = -0x3C;
        gBtlWork->unk_0CC = w->x << 8;
        gBtlWork->unk_0D0 = 0x156 << 8;
        gBtlWork->unk_0D4 = (s16)w->z << 8;
    }
    w->unk_08 = (s16)w->x << 8;
    w->unk_0C = (s16)w->y << 8;
    w->unk_10 = (s16)w->z << 8;
    w->x2 = w->unk_08;
    w->y2 = w->unk_0C;
    w->z2 = w->unk_10;
    w->unk_20 = 0;
    w->unk_24 = 0;
    w->unk_34 = 0;
    w->unk_36 = 0;
    w->unk_30 = 0;
    w->unk_32 = 55;
    w->unk_38 = 0;
    w->unk_3A = 0;
    w->flags |= 0x30;
    w->unk_3B = 0;
    w->unk_3C = 16;
    w->unk_40 = 0;
    w->unk_42 = 0;
    w->unk_44 = 0;
    w->unk_60 = w;
    func_080B7E68(w);

    if (w->flags & 8) {
        w->unk_2C = 15;
        gBosTmBodyTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmBody, w);
        gBosTmFootTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmFoot, w);
        gBosTmArmTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmArm, &w->unk_48);
    } else {
        w->unk_2C = 0;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosMap, gUnk_09619C68);
        gBosTmTblTask = TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosTmTbl, w);
        gBosTmBodyTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmBody, w);
        gBosTmFootTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmFoot, w);
        gBosTmArmTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmArm, &w->unk_48);
        gBtlWork->unk_0D8 = 10;
    }
}

u8 task_bos_tm_1(TmWork* w) {
    WlogoObjParam param;
    u16 t;

    switch (w->unk_2C) {
    case 0:
    case 15:
        w->unk_36++;

        if ((s16)w->unk_36 > 8) {
            w->unk_36 = 0;
            w->unk_34++;

            if ((s16)w->unk_34 > 7) {
                w->unk_34 = 0;
            }
        }
        break;
    case 12:
        w->unk_34++;
        t = w->unk_30;

        if ((s16)t == 1) {
            w->unk_30 = t + 1;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        w->unk_36++;

        if ((s16)w->unk_36 > 6) {
            w->unk_36 = 0;
            w->unk_34++;

            if ((s16)w->unk_34 > 9) {
                w->unk_34 = 0;
            }
        }
        break;
    case 13:
        if ((s16)w->unk_34 != 0) {
            if (!func_080C64A4()) {
                func_0801B008();
                return 0;
            }
        } else {
            param.tiles = 0x06010000 + (w->unk_40 << 5);
            param.unk_04 = w->unk_42;
            param.palette = 0x05000200 + (w->unk_44 << 5);
            param.unk_0C = 0x60;
            param.x = w->x2;
            param.y = w->y2;
            param.z = w->z2;
            param.unk_1C = func_080B82D4;
            gUnk_0203AB50.x = w->x2;
            gUnk_0203AB50.y = w->y2;
            gUnk_0203AB50.z = w->z2;
            param.unk_20 = &gUnk_0203AB50;
            func_080C640C(&param);
            w->flags &= ~1;
            w->unk_34++;
        }
        break;
    case 2:
    case 3:
    case 9:
    case 11:
        w->unk_34++;
        break;
    case 17:
        break;
    }
    gUnk_0203AB44 = gBtlWork->actor->y >> 8;
    gUnk_0203AB40 = gBtlWork->actor->unk_01C >> 8;
    gUnk_0203AB3C = gBtlWork->actor->z >> 8;
    gUnk_0203AB48 = gBtlWork->unk_0D0 >> 8;

    if ((gBtlWork->flags & 0x20000000) && w->unk_2C != 13) {
        if (gBtlWork->actor->unk_01C <= -0x2D00) {
            gBtlWork->unk_0D8 = -10;
        } else {
            gBtlWork->unk_0D8 = 10;
        }
    } else {
        if (gBtlWork->actor->z <= -0x2D00) {
            gBtlWork->unk_0D8 = -10;
        } else {
            gBtlWork->unk_0D8 = 10;
        }
    }
    TaskPoolUpdate(&gBosTmTaskPool);
    func_080B7E68(w);
    w->unk_38++;
    return 1;
}

void task_bos_tm_2(TmWork* w) {
    TaskPoolDraw(&gBosTmTaskPool);
}

void task_bos_tm_3(TmWork* w) {
    TaskPoolDestroy(&gBosTmTaskPool);
}

void func_080B82D4(void) {
    func_08000DE8(&gBtlWork->taskPools[1], gBosTmTblTask);
    func_08000DE8(&gBosTmTaskPool, gBosTmBodyTask);
    func_08000DE8(&gBosTmTaskPool, gBosTmFootTask);
    func_08000DE8(&gBosTmTaskPool, gBosTmArmTask);
}

TaskDesc gTaskDescBosTm = {
    gTaskNameBosTm,
    (TaskInitFunc)task_bos_tm_0,
    (TaskUpdateFunc)task_bos_tm_1,
    (TaskFunc)task_bos_tm_2,
    (TaskFunc)task_bos_tm_3,
    0x64,
};
