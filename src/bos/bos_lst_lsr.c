#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"

TaskDesc gTaskDescBosLstLsr = {
    "task_bos_lst_lsr",
    (TaskInitFunc)task_bos_lst_lsr_0,
    (TaskUpdateFunc)task_bos_lst_lsr_1,
    (TaskFunc)task_bos_lst_lsr_2,
    (TaskFunc)task_bos_lst_lsr_3,
    0x5C,
};

s32 func_0811156C(s32 x) {
    return x * x;
}

s32 func_08111574(s32 x) {
    return x * x;
}

s32 func_0811157C(s32 n) {
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

u8 func_081115B4(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = 0;

    switch (s->unk_000) {
    case 2:
    case 3:
        result = 1;
        break;
    }

    return result;
}

void func_081115CC(LstWork* work, Vec3* a, Vec3* b, s32 c, u16 d) {
    LstState* s;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;

    s = work->state;
    s->unk_000 = 1;
    *(u8*)&s->unk_002 = c;
    s->unk_012 = d;
    *(Vec3*)&s->unk_024 = *a;
    *(Vec3*)&s->unk_030 = *b;
    WorldToScreen(&x1, &y1, s->unk_024, s->unk_028, s->unk_02C);
    WorldToScreen(&x2, &y2, s->unk_030, s->unk_034, s->unk_038);
    s->unk_014 = (s16)func_0811157C((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 16;

    if (s->unk_014 <= 1) {
        s->unk_014 = 2;
    }

    s->unk_010 = 0;
}

void func_08111660(LstLsrTask* t) {
    LstLsrWork* w;

    w = t->work;
    w->state = 0;
    w->unk_010 = 0;
    AnimStart(&w->anim, 4, 0);
}

u8 func_08111678(LstLsrWork* work) {
    LstFalArg arg;
    u8 result;

    result = 0;

    if (work->unk_004 != 0) {
        return 0;
    }

    if ((s16)*work->unk_00C <= 31) {
        arg.unk_00 = 0;
        arg.x = work->x2;
        arg.y = work->y2;
        arg.z = work->z2;
        arg.unk_12 = *work->unk_008;
        arg.unk_14 = work->unk_00C;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFal, &arg);
        result = 1;
    }

    return result;
}

void task_bos_lst_lsr_0(LstLsrWork* work, LstLsrArg* arg) {
    work->unk_004 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->state = 0;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD0334, 0x900);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFBF18, gUnk_09EFBEC4);
    AnimStart(&work->anim, 4, 0);
}

u8 task_bos_lst_lsr_1(LstLsrWork* work) {
    switch (work->state) {
    case 0:
        break;
    case 1:
        work->unk_012--;
        if (work->unk_012 > 0) {
            break;
        }
        work->state = 2;
        work->unk_012 = 0;
    case 2:
        work->unk_010++;
        if (work->unk_010 >= work->unk_014) {
            work->state = 3;
            work->unk_010 = 0;
            AnimReset(&work->anim);
            AnimChange(&work->anim, 6, 1);
        }
        break;
    case 3:
        if (work->unk_010 > 15) {
            work->state = 0;
            work->unk_010 = 0;
            AnimChange(&work->anim, 4, 0);
        } else {
            func_08011F78(0x10D, work->x2, work->y2, work->z2, 8, 8, 8);
            if ((work->unk_010 & 3) == 0) {
                func_08111678(work);
            }
            if (abs(work->x2 - gBtlWork->actor->x) < 384) {
                work->x2 = gBtlWork->actor->x;
            } else if (work->x2 > gBtlWork->actor->x) {
                work->x2 = work->x2 - 384;
            } else if (work->x2 < gBtlWork->actor->x) {
                work->x2 = work->x2 + 384;
            }
            if (abs(work->y2 - gBtlWork->actor->y) < 384) {
                work->y2 = gBtlWork->actor->y;
            } else if (work->y2 > gBtlWork->actor->y) {
                work->y2 = work->y2 - 384;
            } else if (work->y2 < gBtlWork->actor->y) {
                work->y2 = work->y2 + 384;
            }
            work->unk_010++;
        }
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_lsr_2(LstLsrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    u16 z;
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    s32 oam;

    switch (work->state) {
    case 2:
        WorldToScreen(&x1, &y1, work->x2, work->y2, work->z2);
        prio = GetBattleSpritePriorityFlags(work->y2);
        z = -0x1004 - (work->y2 >> 8) * 4;
        WorldToScreen(&x2, &y2, work->x, work->y, work->z);
        oam = AllocObjAffineAngle(work->angle, 1);
        x = x2 + (x1 - x2) * work->unk_010 / work->unk_014;
        y = y2 + (y1 - y2) * work->unk_010 / work->unk_014;
        DrawSprite(x, y, gUnk_09EFBEC4[13], (void*)work->tiles, (void*)work->palette,
                   oam, prio, z);
        break;
    case 3:
        WorldToScreen(&x1, &y1, work->x2, work->y2, work->z2);
        prio = GetBattleSpritePriorityFlags(work->y2);
        z = -0x1004 - (work->y2 >> 8) * 4;
        oam = AllocObjAffine(0, 0x100 - work->unk_010 * 8, work->unk_010 * 16 + 0x100, 1);
        gfx = AnimGetGfx(&work->anim);
        DrawSprite(x1, y1, gfx, (void*)work->tiles, (void*)work->palette,
                   oam, prio | 4, z);
        break;
    }
}

void task_bos_lst_lsr_3(LstLsrWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}
