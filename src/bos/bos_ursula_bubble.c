#include "bos4.h"
#include "sprites_bos4.h"

#ifdef VERSION_EU
extern u16 eu_080DA830(void);
extern void eu_080DA80C(u16 a, u16 b);
extern u8 eu_080DA848(void);
extern void* eu_080DA860(void);
#endif

TaskDesc gTaskDescBosUrsulaBubble = {
    gTaskNameBosUrsulaBubble,
    (TaskInitFunc)task_bos_ursula_bubble_0,
    (TaskUpdateFunc)task_bos_ursula_bubble_1,
    (TaskFunc)task_bos_ursula_bubble_2,
    (TaskFunc)task_bos_ursula_bubble_3,
#ifdef VERSION_EU
    0x5C,
#else
    0x44,
#endif
};

TaskDesc gTaskDescBosUrsulaBubbleSingle = {
    gTaskNameBosUrsulaBubbleSingle,
    (TaskInitFunc)task_bos_ursula_bubble_single_0,
    (TaskUpdateFunc)task_bos_ursula_bubble_single_1,
    (TaskFunc)task_bos_ursula_bubble_single_2,
    (TaskFunc)task_bos_ursula_bubble_single_3,
#ifdef VERSION_EU
    0x130,
#else
    0x148,
#endif
};

TaskDesc gTaskDescBosUrsulaThunder = {
    gTaskNameBosUrsulaThunder,
    (TaskInitFunc)task_bos_ursula_thunder_0,
    (TaskUpdateFunc)task_bos_ursula_thunder_1,
    (TaskFunc)task_bos_ursula_thunder_2,
    (TaskFunc)task_bos_ursula_thunder_3,
    0x10,
};

#ifdef VERSION_EU
u32 gUnkEu_02035104;
#endif

const char gTaskNameBosUrsulaBubble[] = "task_bos_ursula_bubble";

const EmyKind gBosUrsulaBubbleSingleEmyKind = { 35, 0, 1, 1, 0, 0, 0 };

const char gTaskNameBosUrsulaBubbleSingle[] = "task_bos_ursula_bubble_single";

const char gTaskNameBosUrsulaThunder[] = "task_bos_ursula_thunder";

u16 func_080DD7C4(UrsulaBubbleWork* work) {
    s8 v = 0x60;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[0] = TaskCreate(&work->tasks, &gTaskDescBosUrsulaBubbleSingle, &v);
    v = 0x20;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[1] = TaskCreate(&work->tasks, &gTaskDescBosUrsulaBubbleSingle, &v);
    v = 0x40;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[2] = TaskCreate(&work->tasks, &gTaskDescBosUrsulaBubbleSingle, &v);

    return 3;
}

u16 func_080DD854(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 14;

    for (i = 0; i <= 5; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->tasks, &gTaskDescBosUrsulaBubbleSingle, &v);
        a += 20;
    }

    return i;
}

u16 func_080DD8A8(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 240;

    for (i = 0; i <= 9; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->tasks, &gTaskDescBosUrsulaBubbleSingle, &v);
        a += 16;
    }

    return i;
}

void task_bos_ursula_bubble_0(UrsulaBubbleWork* work) {
#ifdef VERSION_EU
    gUnkEu_02035104 = (u32)work;
    AnimInit(&work->anim, gUnk_09EF68D8, gUnk_09EF68C0);
    AnimStart(&work->anim, 0, 1);
    *(void**)((u8*)gBtlWork + 0x118) =
        AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF68C0, 6), gUnk_097A0DE4);
#endif
    TaskPoolInit(&work->tasks, 10);
    work->unk_040 = 0;

    switch (func_080DC5E8()) {
    case 2:
        work->unk_040 = func_080DD8A8(work);
        break;
    case 1:
        work->unk_040 += func_080DD854(work);
        break;
    case 0:
    default:
        work->unk_040 += func_080DD7C4(work);
        break;
    }

    m4aSongNumStart(SONG_BTL_UR_BUBBLE);
}

u8 task_bos_ursula_bubble_1(UrsulaBubbleWork* work) {
    s32 i;

    TaskPoolUpdate(&work->tasks);
#ifdef VERSION_EU
    AnimUpdate(&work->anim);
#endif

    for (i = 0; i < work->unk_040; i++) {
        if (IsTaskActive(work->unk_018[i]) != 0) {
            break;
        }
    }

    if (i == work->unk_040) {
        return 0;
    }

    return 1;
}

void task_bos_ursula_bubble_2(UrsulaBubbleWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_bos_ursula_bubble_3(UrsulaBubbleWork* work) {
    TaskPoolDestroy(&work->tasks);
#ifdef VERSION_EU
    ReleaseObjTiles(*(void**)((u8*)gBtlWork + 0x118));
#endif
}

void func_080DD9B0(UrsulaBubbleWork* work) {
    s32 i;

    for (i = 0; i < work->unk_040; i++) {
        if (IsTaskActive(work->unk_018[i]) != 0) {
            func_080DDD30(*(void**)((u8*)work->unk_018[i] + 4));
        }
    }
}

#ifdef VERSION_EU
void eu_080DA80C(u16 a, u16 b) {
    AnimChange(&((UrsulaBubbleWork*)gUnkEu_02035104)->anim, a, b);
}

u16 eu_080DA830(void) {
    return AnimGetId(&((UrsulaBubbleWork*)gUnkEu_02035104)->anim);
}

u8 eu_080DA848(void) {
    return AnimIsFinished(&((UrsulaBubbleWork*)gUnkEu_02035104)->anim);
}

void* eu_080DA860(void) {
    return AnimGetGfx(&((UrsulaBubbleWork*)gUnkEu_02035104)->anim);
}
#endif

void task_bos_ursula_bubble_single_0(UrsulaBubbleSingleWork* work, u8* arg) {
    work->angle = *arg;
    work->unk_140 = 0x333;
    func_0801B37C(&work->unk_024, &gBosUrsulaBubbleSingleEmyKind, gBtlWork->unk_0CC,
        gBtlWork->unk_0D0 + 0x1000, gBtlWork->unk_0D4);
    func_0801C2DC(&work->unk_024, 1);
#ifdef VERSION_EU
    work->tiles = *(void**)((u8*)gBtlWork + 0x118);
#else
    work->tiles = LoadObjTiles(gUnk_097A0DE4, 0xA80);
#endif
    work->palette = LoadObjPalette(gUnk_0984B0F8, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
#ifdef VERSION_EU
    eu_080DA80C(0, 1);
#else
    AnimInit(&work->anim, gUnk_09EF68D8, gUnk_09EF68C0);
    AnimStart(&work->anim, 0, 1);
#endif
    work->unk_138 = 0;
    work->timer = 0x3C;
}
u8 task_bos_ursula_bubble_single_1(UrsulaBubbleSingleWork* work) {
    BtlObjPos* p = (BtlObjPos*)&work->unk_024;

    work->unk_140 -= 12;

    if (work->unk_140 < 0x166) {
        work->unk_140 = 0x166;
    }

    if (work->unk_138 == 0) {
        p->x += gSineTable[(u8)work->angle] * work->unk_140 >> 8;
        p->z += -gSineTable[(u8)work->angle + 0x40] * work->unk_140 >> 8;
        work->timer--;

        if (p->z >= 0) {
            p->z = 0;
            work->timer = 0;
        }

        if (work->timer == 0) {
            work->timer = 180;
            work->unk_138 = 1;
        }
    }

    if (work->unk_138 == 1 && work->timer != 0) {
        work->targetAngle = (u8)GetAngle(p->x, p->z,
            gBtlWork->actor->x, gBtlWork->actor->z);
        ApproachAngle(&work->angle, work->targetAngle, 4);
        p->x += gSineTable[(u8)work->angle] * work->unk_140 >> 8;
        p->z += -gSineTable[(u8)work->angle + 0x40] * work->unk_140 >> 8;

        if (work->timer <= 169) {
            ApproachValue(&p->y, gBtlWork->actor->y, 30);
        }

        if ((u32)p->x > 0x20800 || p->y > 0x20800) {
            return 0;
        }

        work->timer--;

        if (work->timer == 0) {
#ifdef VERSION_EU
            eu_080DA80C(1, 0);
#else
            AnimStart(&work->anim, 1, 0);
#endif
            func_0801C2DC(&work->unk_024, 1);
        }
    }

#ifdef VERSION_EU
    if (eu_080DA830() == 0
#else
    if (AnimGetId(&work->anim) == 0
#endif
            && func_08011F78(0xF2, p->x, p->y, p->z, 1, 1, 1) == 1) {
        m4aSongNumStart(SONG_EF_UR_BUBBHIT);

        return 0;
    }

#ifdef VERSION_EU
    if (eu_080DA830() == 1 && eu_080DA848() != 0) {
        return 0;
    }

#else
    if (AnimGetId(&work->anim) == 1 && AnimIsFinished(&work->anim) != 0) {
        return 0;
    }

    AnimUpdate(&work->anim);
#endif
    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);

    return 1;
}

void task_bos_ursula_bubble_single_2(UrsulaBubbleSingleWork* work) {
    BtlObjPos* p = (BtlObjPos*)&work->unk_024;
    void* pal;
    u16 v;
    s16 x;
    s16 y;

    v = GetBattleSpritePriorityFlags(p->y);
    pal = func_0801CA00(p) != 0 ? work->palette2 : work->palette;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
#ifdef VERSION_EU
    DrawSprite(x, y, eu_080DA860(), work->tiles, pal, 0, v, -0x1004 - (p->y >> 8) * 4);
#else
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, 0, v, -0x1004 - (p->y >> 8) * 4);
#endif
}

void task_bos_ursula_bubble_single_3(UrsulaBubbleSingleWork* work) {
    func_0801B7D8(&work->unk_024);
#ifndef VERSION_EU
    ReleaseObjTiles((void*)work->tiles);
#endif
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
}

void func_080DDD30(UrsulaBubbleSingleWork* work) {
#ifdef VERSION_EU
    if (eu_080DA830() == 0) {
#else
    if (AnimGetId(&work->anim) == 0) {
#endif
        work->timer = 0;
#ifdef VERSION_EU
        eu_080DA80C(1, 0);
#else
        AnimStart(&work->anim, 1, 0);
#endif
        func_0801C2DC(&work->unk_024, 1);
        work->unk_138 = 2;
    }
}

void task_bos_ursula_thunder_0(UrsulaThunderWork* work) {
    BtlObj* p = gBtlWork->actor;

    work->x = p->x;
    work->y = p->y;
    work->z = p->z - 0x6000;
    func_08017390(work->x, work->y, work->z);
    work->unk_000 = 0;
}

u8 task_bos_ursula_thunder_1(UrsulaThunderWork* work) {
    if (func_080128EC() == 0) {
        if (work->unk_000 != 0) {
            return 0;
        }

        func_080155BC(work->x, work->y, 0, 244);
        work->unk_000 = 1;
    }

    return 1;
}

void task_bos_ursula_thunder_2(void) {
}

void task_bos_ursula_thunder_3(void) {
}

void func_080DDDDC(UnkStruct_080DDDDC* p, const UnkStruct_096FE034* q) {
    p->unk_00 = 0;
    p->unk_02 = 0;
    p->unk_04 = 1;
    p->unk_08 = q;
}

u8 func_080DDDEC(UnkStruct_080DDDDC* p, const UnkStruct_096FE034* q, u8 a) {
    if (p->unk_04 == 0) {
        p->unk_00++;

        if (p->unk_00 > q->unk_00[p->unk_02].unk_00) {
            p->unk_00 = 0;
            p->unk_02++;

            if (p->unk_02 >= q->unk_04) {
                p->unk_02 = 0;
            }
        }
    }

    if (a == 0) {
        if (p->unk_00 == 0 || p->unk_04 != 0) {
            RequestDma3Copy((u8*)q->unk_08 + q->unk_10 * q->unk_00[p->unk_02].unk_02,
                (u8*)GetBgCharBase(q->bg) + q->unk_0C, q->unk_0E);
            p->unk_04 = 0;
        }
    } else if (p->unk_00 == 0) {
        p->unk_04 = 1;
    }

    return a;
}

u8 func_080DDE74(UnkStruct_080DDDDC* p) {
    const UnkStruct_096FE034* q = p->unk_08;

    if (p->unk_00 + 1 > q->unk_00[p->unk_02].unk_00 && p->unk_02 + 1 >= q->unk_04) {
        return 1;
    }

    return 0;
}

u16 func_080DDEA0(UnkStruct_080DDDDC* p) {
    return p->unk_02;
}

void func_080DDEA4(void) {
    func_080D2C78();
}

void func_080DDEB0(s32 a) {
    GetPooState(a);
}

void func_080DDEBC(s32 a) {
    SetPooState(a);
}
