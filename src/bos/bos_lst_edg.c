#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"

const char gTaskNameBosLstEdg[] = "task_bos_lst_edg";

TaskDesc gTaskDescBosLstEdg = {
    gTaskNameBosLstEdg,
    (TaskInitFunc)task_bos_lst_edg_0,
    (TaskUpdateFunc)task_bos_lst_edg_1,
    (TaskFunc)task_bos_lst_edg_2,
    (TaskFunc)task_bos_lst_edg_3,
    0x4C,
};

s32 func_08110658(s32 x) {
    return x * x;
}

s32 func_08110660(s32 x) {
    return x * x;
}

u8 func_08110668(LstWork* work) {
    LstState* s;

    s = work->state;
    return s->unk_000 != 4;
}

void task_bos_lst_edg_0(LstEdgWork* work, LstEdgArg* arg) {
    work->state = 0;
    work->unk_002 = 0;
    work->timer = 0;
    work->unk_006 = arg->unk_00;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->unk_014 = arg->x;
    work->unk_018 = arg->y;
    work->unk_01C = arg->z;
    work->tiles = (u32)AllocObjTiles(0x80, gUnk_09C5C4E2);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFAF1C, gUnk_09EFAEF8);
    AnimStart(&work->anim, 0, 1);
}

u8 task_bos_lst_edg_1(LstEdgWork* work) {
    BtlObj* p;

    switch (work->state) {
    case 0:
        work->unk_006--;
        if (work->unk_006 <= 0) {
            work->state = 1;
            work->unk_002 = 0;
            work->timer = 0;
            work->unk_006 = 0;
            p = gBtlWork->actor;
            work->unk_020 = p->x;
            work->unk_024 = p->y;
            work->unk_028 = -0x1000;
        }
        break;
    case 1:
        work->unk_020 = gBtlWork->actor->x;
        ApproachValueHalfSteps(&work->x, work->unk_020, 30);
        ApproachValueHalfSteps(&work->y, work->unk_024, 30);
        ApproachValueHalfSteps(&work->z, work->unk_028, 30);
        work->timer++;
        if (work->timer > 49) {
            work->state = 2;
            work->unk_002 = 0;
            work->timer = 0;
            work->unk_006 = 0;
        }
        func_08011F78(0x10C, work->x, work->y, work->z, 8, 8, 1);
        break;
    case 2:
        ApproachValueHalfSteps(&work->x, work->unk_014, 30);
        ApproachValueHalfSteps(&work->y, work->unk_018, 30);
        ApproachValueHalfSteps(&work->z, work->unk_01C, 30);
        work->timer++;
        if (work->timer > 49) {
            work->state = 3;
            work->unk_002 = 0;
            work->timer = 0;
            work->unk_006 = 0;
        }
        func_08011F78(0x10C, work->x, work->y, work->z, 8, 8, 1);
        break;
    case 3:
        work->state = 4;
        work->unk_002 = 0;
        work->timer = 0;
        work->unk_006 = 0;
        break;
    case 4:
        AnimStart(&work->anim, 1, 1);
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_edg_2(LstEdgWork* work) {
    s16 x;
    s16 y;
    u16 prio;
    u16 z;
    void* gfx;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    prio = GetBattleSpritePriorityFlags(work->y);
    z = -0x1004 - (work->y >> 8) * 4;
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, 0, prio, z);
}

void task_bos_lst_edg_3(LstEdgWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}
