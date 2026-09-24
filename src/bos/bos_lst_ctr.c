#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"

const EmyKind gUnk_09A4FE98 = { 0, 1, 8, 8, 0, 128, 0 };

const u32 gUnk_09A4FEA8[6][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 128, 0, 0, 0 },
    { 0, 86, 171, 0, 0 },
    { 0, 64, 128, 192, 0 },
    { 0, 51, 102, 153, 204 },
};

TaskDesc gTaskDescBosLstCtr = {
    "task_bos_lst_ctr",
    (TaskInitFunc)task_bos_lst_ctr_0,
    (TaskUpdateFunc)task_bos_lst_ctr_1,
    (TaskFunc)task_bos_lst_ctr_2,
    (TaskFunc)task_bos_lst_ctr_3,
    0x188,
};

s32 func_08111F3C(s32 x) {
    return x * x;
}

s32 func_08111F44(s32 x) {
    return x * x;
}

u8 func_08111F4C(LstWork* work) {
    LstState* s;

    s = work->state;
    return s->unk_008 != 4;
}

s32 func_08111F60(s32 n) {
    s32 x;
    s32 g;

    if (n <= 0) {
        return 0;
    }

    x = 1;
    g = n;
    while (x < g) {
        x <<= 1;
        g >>= 1;
    }

    do {
        g = x;
        x = (n / g + g) >> 1;
    } while (x < g);

    return g;
}

void task_bos_lst_ctr_0(LstCtrWork* work, LstCtrArg* arg) {
    work->unk_000 = arg->unk_00;
    work->unk_004 = arg->unk_04;
    work->unk_006 = arg->unk_06;
    work->state = 0;
    work->unk_00A = 0;
    work->unk_00C = 0;
    work->unk_00E = arg->unk_08;
    work->unk_020 = 0;
    work->unk_024 = 0;
    work->unk_028 = 0;
    work->unk_014 = arg->x;
    work->unk_018 = arg->y;
    work->unk_01C = arg->z;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->tiles = (u32)LoadObjTiles(gUnk_09C5C704, 0x500);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFAF50, gUnk_09EFAF24);
    AnimStart(&work->anim, 3, 1);
}

u8 task_bos_lst_ctr_1(LstCtrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    BtlObj* p;
    s32 c;

    work->unk_020 /= 2;
    work->unk_024 /= 2;
    work->unk_028 /= 2;

    switch (work->state) {
    case 0:
        c = (u16)work->unk_00C + 1;
        work->unk_00C = c;
        work->unk_00E--;
        if (work->unk_00E <= 0) {
            p = gBtlWork->actor;
            work->x2 = work->unk_014 - (work->unk_014 - p->x) / 4;
            work->y2 = p->y;
            work->z2 = -0x1000;
            work->state = 1;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
            WorldToScreen(&x1, &y1, work->x, work->y, work->z);
            WorldToScreen(&x2, &y2, work->x2, work->y2, work->z2);
            work->unk_010 = 0;
            work->unk_012 = (s16)func_08111F60((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 9;
        } else {
            work->unk_020 =
                (-gSineTable[((gUnk_09A4FEA8[work->unk_004][work->unk_006] + c) & 0xFF) + 0x40] * 5 >> 6) << 8;
            work->unk_028 =
                ((gSineTable[(gUnk_09A4FEA8[work->unk_004][work->unk_006] + c) & 0xFF] * 3 >> 5) - 4) << 8;
        }
        break;
    case 1:
        work->unk_014 = work->x - (work->x - work->x2) * work->unk_00C / work->unk_012;
        work->unk_018 = work->y + (work->y2 - work->y) * work->unk_00C / work->unk_012;
        work->unk_01C = work->z + (work->z2 - work->z) * work->unk_00C / work->unk_012;
        work->unk_00C++;
        if (work->unk_00C >= work->unk_012) {
            work->state = 2;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
        }
        if (func_08011F78(0x10F, work->unk_014, work->unk_018, work->unk_01C, 8, 1, 4) != 0) {
            m4aSongNumStart(SONG_EF_DS_ANKOKUPUNCH);
        }
        break;
    case 2:
        work->unk_00C++;
        if (work->unk_00C > 2) {
            work->state = 3;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
            work->unk_014 = work->x2;
            work->unk_018 = work->y2;
            work->unk_01C = work->z2;
            AnimStart(&work->anim, 1, 0);
            m4aSongNumStart(SONG_SND_710);
        }
        break;
    case 3:
        if (work->x > work->x2) {
            work->unk_010 = 0;
            work->unk_014 = work->unk_014 - 0x600;
            if (work->unk_014 < 0x6000) {
                work->state = 4;
                work->unk_00A = 0;
                work->unk_00C = 0;
                work->unk_00E = 0;
            }
        } else {
            work->unk_010 = 0x80;
            work->unk_014 = work->unk_014 + 0x600;
            if (work->unk_014 > 0x19000) {
                work->state = 4;
                work->unk_00A = 0;
                work->unk_00C = 0;
                work->unk_00E = 0;
            }
        }
        work->unk_01C = work->z2 - ((work->unk_00C >> 2) << 8);
        if (func_08011F78(0x10F, work->unk_014, work->unk_018, work->unk_01C, 8, 4, 4) != 0) {
            m4aSongNumStart(SONG_EF_DS_ANKOKUPUNCH);
        }
        work->unk_00C++;
        break;
    case 4:
        AnimStart(&work->anim, 2, 1);
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_ctr_2(LstCtrWork* work) {
    s16 x;
    s16 y;
    s32 affine;
    u16 prio;
    u16 z;
    void* gfx;
    s32 d;

    WorldToScreen(&x, &y, work->unk_014 + work->unk_020, work->unk_018 + work->unk_024,
                  work->unk_01C + work->unk_028);
    affine = 0;
    prio = GetBattleSpritePriorityFlags(work->unk_018 + work->unk_024) | 4;
    z = -0x1004 - ((work->unk_018 + work->unk_024) >> 8) * 4;

    switch (work->state) {
    case 0:
        d = work->unk_00C - work->unk_006 * 8;
        if (d <= 0) {
            return;
        }
        if (d <= 15) {
            affine = AllocObjAffine(0, 0x100, d * 16, 0);
        }
        break;
    case 1:
        affine = AllocObjAffine(0, 0x100 - work->unk_00C * 4, 0x100 - work->unk_00C * 4, 1);
        break;
    case 2:
        affine = AllocObjAffine(0, 0x100 - (work->unk_012 - work->unk_00C) * 4,
                                0x100 - work->unk_012 * 4, 1);
        break;
    default:
        if (work->unk_014 + work->unk_020 > work->x2) {
            prio |= 1;
        }
        break;
    }

    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, affine, prio, z);
}

void task_bos_lst_ctr_3(LstCtrWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}
