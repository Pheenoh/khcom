#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"

const LstFalAnim gBosLstFalAnims[8] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 } };

const char gTaskNameBosLstFal[] = "task_bos_lst_fal";

TaskDesc gTaskDescBosLstFal = {
    gTaskNameBosLstFal,
    (TaskInitFunc)task_bos_lst_fal_0,
    (TaskUpdateFunc)task_bos_lst_fal_1,
    (TaskFunc)task_bos_lst_fal_2,
    (TaskFunc)task_bos_lst_fal_3,
    0x40,
};

s32 func_08111BF4(s32 x) {
    return x * x;
}

s32 func_08111BFC(s32 x) {
    return x * x;
}

void task_bos_lst_fal_0(LstFalWork* work, LstFalArg* arg) {
    u16 anim;

    anim = gBosLstFalAnims[GetRandom() & 7].anim;
    work->unk_000 = arg->unk_00;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->vx = (GetRandom() % 0x181 + 0x80) * arg->unk_12;
    work->vz = GetRandom() % 0xC1 + 0x40;
    work->unk_018 = GetRandom() % 0x81 + 0x80;

    switch (arg->unk_00) {
    case 1:
        if ((GetRandom() & 1) != 0) {
            work->vx = work->vx * 512 >> 8;
            work->vz = work->vz * 384 >> 8;
            work->unk_018 = GetRandom() % 0x81 + 0x380;
        }
        break;
    case 2:
        work->vz = GetRandom() % 0x81 + 0x180;
        break;
    case 3:
        work->vx = work->vx * 640 >> 8;
        break;
    case 4:
        work->vx = (-gSineTable[arg->angle + 0x40] << 8) / 256;
        work->vz = (gSineTable[arg->angle] << 8) / 256;
        break;
    case 5:
        work->vx = GetRandom() % 0x201 - 0x100;
        work->vz = GetRandom() % 0xC1 + 0xC0;
        work->unk_018 = GetRandom() % 0x381 + 0x80;
        break;
    }

    switch (anim) {
    case 4:
    case 5:
        work->vx = work->vx * 320 >> 8;
        work->vz = work->vz * 320 >> 8;
        break;
    }

    work->unk_01C = arg->unk_14;
    (*work->unk_01C)++;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD1074, 0x700);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFBFC4, gUnk_09EFBF64);
    AnimStart(&work->anim, anim, 1);
}

u8 task_bos_lst_fal_1(LstFalWork* work) {
    u16 x;
    s16 y;
    u8 result;
    s32 d;

    result = 1;
    work->x += work->vx;
    work->z += work->vz;

    if (work->unk_000 != 4) {
        if (work->unk_018 > 0) {
            d = 512;
            if (work->unk_018 <= 512) {
                d = work->unk_018;
            }
            work->z -= d;
            work->unk_018 = work->unk_018 - 25;
        } else {
            work->unk_018 = GetRandom() % 0x41 + 0x40;
        }
    }

    WorldToScreen((s16*)&x, &y, work->x, work->y, work->z);

    if ((u16)(x + 16) > 272 || y < -64 || y > 224) {
        result = 0;
    }

    AnimUpdate(&work->anim);

    return result;
}

void task_bos_lst_fal_2(LstFalWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 prio;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    gfx = AnimGetGfx(&work->anim);
    prio = GetBattleSpritePriorityFlags(work->y) | 4;
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, 0, prio,
               -0x1004 - (work->y >> 8) * 4);
}

void task_bos_lst_fal_3(LstFalWork* work) {
    if (work->tiles != 0) {
        ReleaseObjTiles((void*)work->tiles);
    }
    if (work->palette != 0) {
        ReleaseObjPalette((void*)work->palette);
    }
    (*work->unk_01C)--;
}
