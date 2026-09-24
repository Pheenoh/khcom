#include "bos2.h"
#include "sprites_bos2.h"

void task_bos_dsd_ita_0(DsdItaWork* work, void* arg) {
    work->dsd = arg;
    work->unk_074 = 0x1E;
    work->unk_076 = 0;
    work->unk_078 = 0;
    work->state = 0;
    work->x = 0x12C00;
    work->y = 0x17C00;
    work->z = -0x7800;
    work->vz = 0x100;
    work->unk_070 = 0x19;
    work->flags = 0;
    work->unk_07E = 0;
    work->unk_080 = 0;
    ColliderInit(&work->collider, 7, 0x20, 3);
    ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    work->gfx = (u32)gUnk_09EF3BF8[0];
    work->gfx2 = (u32)gUnk_09EF3C18;
}

u8 task_bos_dsd_ita_1(DsdItaWork* work) {
    BtlObj* a = &work->dsd->body[1];

    func_080C427C(work);

    switch (work->state) {
    case 0:
        if (work->unk_074 > 0) {
            ApproachValue(&work->x, 0x1400, work->unk_074);
            ApproachValue(&work->z, -0x1400, work->unk_074);
            work->unk_074--;
        } else {
            work->state = 1;
        }
        break;
    case 1:
        if (work->dsd->flags & 32) {
            work->state = 2;
        }

        func_080C4398(work);
        break;
    case 2:
        if (work->dsd->flags & 32) {
            func_080C43E4(&work->x, a->x - 12800);
            func_080C43E4(&work->y, a->y);
            func_080C43E4(&work->z, a->z + 0x500);
        } else if (work->unk_078 > 49) {
            work->state = 3;
        } else {
            work->unk_078++;
        }

        func_080C4398(work);
        break;
    case 3:
        if (work->z < 0) {
            work->z += work->vz;
            work->vz += work->unk_070;
        } else {
            work->z = 0;
        }

        if (work->dsd->flags & 32) {
            work->unk_078 = 0;
            work->state = 2;
        }

        func_080C4398(work);
        break;
    case 4:
        if (work->unk_074 > 0) {
            ApproachValue(&work->x, -0x5000, work->unk_074);
            ApproachValue(&work->z, -0x1400, work->unk_074);
            work->unk_074--;
        } else {
            work->state++;
        }
        break;
    default:
        work->dsd->flags &= ~8;
        return 0;
    }

    ColliderSetPosition(&work->collider, work->x, work->y, work->z);

    return 1;
}

void task_bos_dsd_ita_2(DsdItaWork* work) {
    u16 pal;
    u16 prio;
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->dsd->flags & 32) {
        pal = 0x800;
        prio = -4100 - ((work->y - 0x4000) >> 8) * 4;
    } else {
        pal = GetBattleSpritePriorityFlags(work->y);
        prio = -4102 - (work->y >> 8) * 4;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->dsd->tiles2, work->dsd->palette2, 0, pal, prio);

    if (work->z >= 0 && gBtlWork->scale == 0x100) {
        affine = 0;
    } else {
        scale = 0x100 - -work->z / 128;

        if (scale <= 0x7F) {
            scale = 0x80;
        }

        flag = 0;

        if (scale > 0x100) {
            flag = 1;
        }

        affine = AllocObjAffine(0, scale, scale, flag);
    }

    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, work->gfx2, work->dsd->tiles2, work->dsd->palette3, affine, 0xC00, 0xFFF0);
}

void task_bos_dsd_ita_3(DsdItaWork* work) {
    ColliderUnregister(&work->collider);
}

void func_080C427C(DsdItaWork* work) {
    s32 v;
    s16 k;

    if (gBtlWork->unk_0F0 == (u32)&work->collider) {
        v = work->dsd->flags & 32;

        if (v == 0) {
            work->flags |= 1;
            work->dsd->flags |= 32;
            work->unk_07E = v;
        }
    } else if (work->dsd->flags & 32) {
        work->dsd->flags &= ~32;
        work->flags |= 2;
        work->unk_07E = 0;
    }

    if (work->flags & 2) {
        k = gUnk_0961A860[work->unk_07E];
        work->unk_080 -= k << 8;

        if (k == 0) {
            work->flags &= 0xFFFD;
            work->unk_080 = 0;
        } else {
            work->unk_07E++;
        }
    } else if (work->flags & 1) {
        k = gUnk_0961A860[work->unk_07E];
        work->unk_080 += k << 8;

        if (k == 0) {
            work->flags &= 0xFFFE;
        } else {
            work->unk_07E++;
        }
    }
}

void func_080C4398(DsdItaWork* work) {
    if ((s16)work->unk_076 >= 600) {
        work->unk_074 = 30;
        work->state = 4;
    } else {
        work->unk_076++;
    }

    if (work->dsd->unk_334 == 11) {
        work->state = 4;
    }
}

void func_080C43E4(s32* p, s32 target) {
    s32 cur;
    s32 delta;

    cur = *p;
    delta = (target - cur) >> 1;

    if (target > cur) {
        if (delta > 0x4FF) {
            delta = 0x500;
        }
    } else if (target < cur) {
        if (delta <= -0x500) {
            delta = -0x500;
        }
    } else {
        return;
    }

    *p = cur + delta;
}

void task_bos_dsd_rock_0(DsdRockWork* work, DsdWork* arg) {
    s32 r;
    u8 ang;

    work->dsd = arg;
    work->unk_20 = GetRandom() % 2;
    work->gfx = gUnk_09EF3BF8[GetRandom() % 3 + 1];

    if (work->dsd->unk_35C > 0) {
        if (work->unk_20 != 0) {
            r = GetRandom() % 0x301 + 0x700;
            ang = GetRandom() % 13 + 58;
            work->x = gBtlWork->unk_000 - 0x8800;
            work->y = (gBtlWork->unk_0E0 - 140) << 8;
        } else {
            r = GetRandom() % 0x201 + 0x400;
            ang = -(GetRandom() % 13 + 58);
            work->x = gBtlWork->unk_000 + 0x8800;
            work->y = (gBtlWork->unk_0DE - 140) << 8;
        }
    } else {
        if (work->unk_20 != 0) {
            r = GetRandom() % 0x301 + 0x700;
            ang = -(GetRandom() % 13 + 58);
            work->x = gBtlWork->unk_000 + 0x8800;
            work->y = (gBtlWork->unk_0E0 - 140) << 8;
        } else {
            r = GetRandom() % 0x201 + 0x400;
            ang = GetRandom() % 13 + 58;
            work->x = gBtlWork->unk_000 - 0x8800;
            work->y = (gBtlWork->unk_0DE - 140) << 8;
        }
    }

    work->z = (GetRandom() % 101) << 8;
    work->vx = gSineTable[ang] * r >> 8;
    work->vz = -gSineTable[ang + 0x40] * r >> 8;
}

u8 task_bos_dsd_rock_1(DsdRockWork* work) {
    if ((work->dsd->flags & 0x40) != 0) {
        work->vx = -work->vx;
        work->vz = -work->vz;
    } else {
        work->x += work->vx;
        work->z += work->vz;
    }

    if (work->x > gBtlWork->unk_000 + 0x8800 || work->x < gBtlWork->unk_000 - 0x8800) {
        return 0;
    }

    return 1;
}
void task_bos_dsd_rock_2(DsdRockWork* work) {
    s32 affine;
    s32 h;
    s32 prio;
    s16 x;
    s16 y;

    if (work->unk_20 != 0) {
        affine = 0;
        h = 10;
        prio = 0x400;
    } else {
        affine = AllocObjAffine(0, 0x59, 0x59, 0);
        h = 0xFFF5;
        prio = 0xC00;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->dsd->tiles2, work->dsd->palette2, affine, prio, h);
}

void task_bos_dsd_rock_3(void) {
}

const s16 gUnk_0961A860[6] = { 3, 2, 1, 1, 0, 0 };

const char gTaskNameBosDsdIta[] = "task_bos_dsd_ita";

const char gTaskNameBosDsdRock[] = "task_bos_dsd_rock";

TaskDesc gTaskDescBosDsdIta = {
    gTaskNameBosDsdIta,
    (TaskInitFunc)task_bos_dsd_ita_0,
    (TaskUpdateFunc)task_bos_dsd_ita_1,
    (TaskFunc)task_bos_dsd_ita_2,
    (TaskFunc)task_bos_dsd_ita_3,
    0x90,
};

TaskDesc gTaskDescBosDsdRock = {
    gTaskNameBosDsdRock,
    (TaskInitFunc)task_bos_dsd_rock_0,
    (TaskUpdateFunc)task_bos_dsd_rock_1,
    (TaskFunc)task_bos_dsd_rock_2,
    (TaskFunc)task_bos_dsd_rock_3,
    0x24,
};
