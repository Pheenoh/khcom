#include "boss_boogie.h"
#include "boss_status_state.h"
#include "registration_data.h"
#include "card_api.h"
#include "engine_math.h"
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "battle_work.h"
#include "game_state.h"
#include "engine.h"
#include "m4a.h"

extern StatusAnimDef gUnk_096FDE54[];
extern StatusObjDef gUnk_096FDEE4[];
extern u8 gUnk_096FDF14[];
extern u8 gUnk_096FDF24[];
extern u8 gUnk_0984AF78[];
extern u8 gUnk_08F69BC4[];

static BoogieWork* gBoogieWork;

void func_080D8F14(BoogieWork* work) {
    if (gUnk_0203C560 <= 2) {
        gUnk_0203C56C = 0;
        gUnk_0203C570 = 0;

        if (gUnk_0203C558 == 0) {
            work->unk_000 = 8;
            work->unk_164 = TaskCreate(&work->tasks, &gTaskDescBosBoogieDisk, &work->actor);
        } else if (gUnk_0203C558 == 1) {
            work->unk_000 = 6;
            work->unk_004 = 0;
            func_0801BDDC(18, 0xA000, 0x24000, 0);
            func_0801BDDC(18, 0x15000, 0x24000, 0);
        } else if (gUnk_0203C558 == 2) {
            work->unk_000 = 6;
            work->unk_004 = 0;
            func_0801BDDC(17, 0xA000, 0x24000, 0);
            func_0801BDDC(17, 0x15000, 0x24000, 0);
        } else if (gUnk_0203C558 == 3) {
            work->unk_000 = 8;
            work->unk_164 = TaskCreate(&work->tasks, &gTaskDescBosBoogieKnifereader, 0);
        } else if (gUnk_0203C558 == 4) {
            work->unk_000 = 6;
            work->unk_004 = 0;
            func_0801BDDC(15, 0xA000, 0x24000, 0);
            func_0801BDDC(15, 0x15000, 0x24000, 0);
        } else {
            work->unk_000 = 8;
            work->unk_164 = TaskCreate(&work->tasks, &gTaskDescBosBoogieKaihuku, work);
        }
    }
}

void SetBoogieAnimation(BoogieWork* work, s32 a, u16 b) {
    if (work->animationIndex != a) {
        work->animationIndex = a;
        AnimChangeWithTables(&work->anim, gUnk_096FDE54[a].animId, b, gUnk_096FDE54[a].anims, gUnk_096FDE54[a].gfxTable);
        SetObjTileSource(work->tiles, gUnk_096FDE54[a].tiles);
    }
}

u8 ClampBoogiePosition(s32* a, s32* b) {
    u8 r;

    r = 0;

    if (*a < 0xA000) {
        *a = 0xA000;
        r = 1;
    }

    if (*a > 0x15000) {
        *a = 0x15000;
        r = 1;
    }

    if (*b < 0x22800) {
        *b = 0x22800;
        r = 1;
    }

    if (*b > 0x22800) {
        *b = 0x22800;
        r = 1;
    }
    return r;
}

void task_bos_boogie_0(BoogieWork* work) {
    u8 i;
    u16 sz;
    u16 t;

    gBoogieWork = work;
    TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosBoogieMap, gUnk_096FDF24);
    work->unk_000 = 0;
    work->unk_004 = 0;
    gUnk_0203C564 = 0;
    gUnk_0203C568 = 0;
    gUnk_0203C554 = 0;
    work->unk_174 = 0;
    gUnk_0203C55C = &work->actor;
    gUnk_0203C560 = 0;
    SetBattleBounds(128, 368, 576, 632);
    func_0801B37C(&work->actor, gUnk_096FDF14, 0x15000, 0x22800, -0x2000);
    work->actor.unk_010 = -0x2000;
    work->actor.unk_034 |= 4;
    func_0801C2DC(&work->actor, 1);
    work->unk_150 = 0;
    work->unk_154 = 0;
    work->unk_158 = 0;
    work->palette = LoadObjPalette(gUnk_0984AF78, 0x20);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 0x20);
    sz = 0;

    for (i = 0; i <= 5; i++) {
        t = GetMaxSpriteTileBytes(gUnk_096FDEE4[i].sprites, gUnk_096FDEE4[i].spriteCount);
        if (sz < t) {
            sz = t;
        }
    }
    work->tiles = AllocObjTiles(sz, 0);
    AnimInit(&work->anim, 0, 0);
    work->animationIndex = 9;
    SetBoogieAnimation(work, 0, 1);
    TaskPoolInit(&work->tasks, 7);
    TaskCreate(&work->tasks, &gTaskDescBosShadow, &work->actor);
    TaskCreate(&work->tasks, &gTaskDescBosBoogieMapanime, 0);
    TaskCreate(&work->tasks, &gTaskDescBosBoogieSaku, work);
    work->unk_160 = 0;
    work->unk_164 = 0;
    work->unk_168 = 0;
    work->dialog = 0;
    gBtlWork->unk_0CC = work->actor.x;
    gBtlWork->unk_0D0 = work->actor.y;
    gBtlWork->unk_0D4 = work->actor.z;
}

u8 task_bos_boogie_1(BoogieWork* work) {
    BtlObj* a = &work->actor;
    BoogieFx fx;
    u16 random;

    switch (func_0801ADAC(a)) {
    case 5:
        work->unk_000 = 1;
        work->unk_004 = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->unk_000 = 3;
        work->unk_004 = 0;
        break;
    case 3:
    case 8:
        if (work->unk_000 != 4) {
            work->unk_000 = 4;
            work->unk_170 = 0;
            work->unk_004 = 0;
        }
        break;
    case 4:
        work->unk_000 = 2;
        work->unk_004 = 0;
        break;
    default:
        if (gUnk_0203C564 != 0 && work->unk_000 != 4) {
            work->unk_000 = 5;
            work->unk_004 = 0;
        }
        break;
    }

    switch (work->unk_000) {
    case 3:
        if (work->unk_004 == 0) {
            AnimReset(&work->anim);
            SetBoogieAnimation(work, 4, 1);
            work->unk_158 = -((a->unk_0AC << 9) >> 8);
            work->unk_150 = ((gSineTable[a->unk_0B0] * 375) >> 8) * a->unk_0A8 >> 8;
            work->unk_154 = ((-gSineTable[a->unk_0B0 + 64] * 375) >> 8) * a->unk_0A8 >> 8;
            work->unk_004++;
        }
        if (AnimIsFinished(&work->anim)) {
            func_0801AF08(a);
            work->unk_000 = 0;
            work->unk_004 = 0;
        }
        break;
    case 4:
        SetBoogieAnimation(work, 8, 0);
        switch (work->unk_170) {
        case 0:
            if (work->unk_004 <= 1) {
                work->unk_004++;
            } else {
                work->unk_170 = 1;
            }
            break;
        case 1:
            func_0801AF4C(a);
            work->unk_170 = 2;
            break;
        case 2:
            if (FadeIsActive() == 0) {
                func_08014AAC(a->x, a->y + a->z - (((BoogieResource*)gUnk_096FDF14)->unk_0A << 8));
                func_0801C298(((BoogiePalette*)work->palette)->unk_06 + 16, 0);
                FadeToAmount(0, gBtlWork->unk_0B3, 8);
                work->unk_170 = 3;
                work->unk_004 = 0;
            }
            break;
        case 3:
            if (work->unk_004 <= 119) {
                work->unk_004++;
            } else {
                work->unk_170 = 4;
                func_0801536C();
            }
            break;
        case 4:
            if (func_080128EC() == 0) {
                fx.x = a->x;
                fx.y = 0x24000;
                fx.z = -0x6400;
                CreateBossPrizeCardTask(&gBtlWork->taskPools[0], &fx);
                func_0801B008();
                func_0801B918(a);
                return 0;
            }
            break;
        }
        break;
    case 0:
        SetBoogieAnimation(work, 0, 1);
        if (AnimIsFinished(&work->anim)) {
            random = GetRandom();
            if ((random & 15) <= 7 && FadeIsActive() == 0) {
                work->unk_000 = 11;
                if (work->unk_174 != 0) {
                    func_08083914();
                    work->unk_174 = 0;
                }
                work->unk_004 = 0;
                SetBoogieAnimation(work, 1, 1);
            } else {
                AnimReset(&work->anim);
            }
        }
        break;
    case 11:
        SetBoogieAnimation(work, 1, 1);
        work->unk_004++;
        if (gUnk_0203C560 <= 2 && !IsTaskActive((Task*)work->unk_160) &&
            !IsTaskActive((Task*)work->unk_168) && !IsTaskActive((Task*)work->dialog) &&
            !IsTaskActive((Task*)work->unk_164) && gBtlWork->unk_0EC <= 0 && work->unk_174 == 0) {
            random = GetRandom() % 100;
            if (random == 0) {
                func_08083900(8);
                work->unk_174 = 1;
                work->unk_004 = 0;
            }
        }
        if (func_08083920() == 8) {
            if (work->unk_174 != 0) {
#ifdef VERSION_EU
                if (func_0801C1C0(0)) {
                    func_080D9A58();
                    break;
                }
#endif
                func_08083914();
                work->unk_174 = 0;
                work->unk_175 = 0;
                work->unk_160 = (s32)TaskCreate(&work->tasks, &gTaskDescBosBoogieDice, work);
                work->unk_175 = 1;
                work->unk_168 = (s32)TaskCreate(&work->tasks, &gTaskDescBosBoogieDice, work);
                work->dialog = TaskCreate(&work->tasks, &gTaskDescBosBoogieDice, work);
                SetBoogieAnimation(work, 2, 1);
                m4aSongNumStart(272);
                work->unk_000 = 9;
                work->unk_004 = 0;
#ifndef VERSION_EU
                if (func_0801C1C0(0)) {
                    gUnk_0203C568 = 0;
                }
#endif
                break;
            }
        } else if (work->unk_174 != 0 && work->unk_004 > 10) {
            func_08083914();
            work->unk_174 = 0;
        }
        random = GetRandom();
        if ((random & 255) == 0 && work->unk_174 == 0) {
            work->unk_000 = 0;
            work->unk_004 = 0;
        } else if (a->unk_034 & 4) {
            a->x -= 256;
            if (a->x <= 0xA000) {
                a->x = 0xA000;
                a->unk_034 &= ~4ULL;
            }
        } else {
            a->x += 256;
            if (a->x >= 0x15000) {
                a->x = 0x15000;
                a->unk_034 |= 4;
            }
        }
        break;
    case 5:
        gUnk_0203C564 = 0;
        SetBoogieAnimation(work, 6, 0);
        if (func_0801C1C0(0)) {
            func_080D9A58();
            work->unk_000 = 0;
            work->unk_004 = 0;
        } else if (AnimIsFinished(&work->anim)) {
            func_080D8F14(work);
        }
        break;
    case 6:
        if (work->unk_004 > 29) {
            work->unk_000 = 7;
        } else {
            work->unk_004++;
        }
        break;
    case 8:
        if (gUnk_0203C56C != 0) {
            work->unk_000 = 10;
            work->unk_004 = 0;
        } else if (gUnk_0203C570 != 0) {
            work->unk_000 = 0;
            work->unk_004 = 0;
        } else if (!IsTaskActive((Task*)work->unk_164)) {
            work->unk_000 = 7;
            work->unk_004 = 0;
        }
        break;
    case 7:
        SetBoogieAnimation(work, 7, 0);
        if (AnimIsFinished(&work->anim)) {
            work->unk_000 = 0;
            work->unk_004 = 0;
        }
        break;
    case 9:
        SetBoogieAnimation(work, 2, 1);
        if (work->unk_004 == 0) {
            m4aSongNumStart(599);
        }
        work->unk_004++;
        if (AnimIsFinished(&work->anim)) {
            work->unk_000 = 0;
            work->unk_004 = 0;
        }
        break;
    case 10:
        gUnk_0203C56C = 0;
        SetBoogieAnimation(work, 5, 1);
        if (AnimIsFinished(&work->anim)) {
            work->unk_000 = 0;
            work->unk_004 = 0;
        }
        break;
    }
    AnimUpdate(&work->anim);
    a->z += work->unk_158;
    work->unk_158 += 66;
    if (a->z > -0x2000) {
        a->z = -0x2000;
        work->unk_158 = 0;
    }
    if (work->unk_150 > 0) {
        a->x += work->unk_150;
        work->unk_150 -= 17;
        if (work->unk_150 < 0) {
            work->unk_150 = 0;
        }
    } else if (work->unk_150 < 0) {
        a->x += work->unk_150;
        work->unk_150 += 17;
        if (work->unk_150 > 0) {
            work->unk_150 = 0;
        }
    }
    if (work->unk_154 > 0) {
        a->y += work->unk_154 / 2;
        work->unk_154 -= 17;
        if (work->unk_154 < 0) {
            work->unk_154 = 0;
        }
    } else if (work->unk_154 < 0) {
        a->y += work->unk_154 / 2;
        work->unk_154 += 17;
        if (work->unk_154 > 0) {
            work->unk_154 = 0;
        }
    }
    ClampBoogiePosition(&a->x, &a->y);
    ColliderSetPosition(&a->collider, a->x, a->y, a->z);
    TaskPoolUpdate(&work->tasks);
    if (func_0801C1C0(0)) {
        func_080D9A58();
    }
    gBtlWork->unk_0CC = a->x;
    gBtlWork->unk_0D0 = a->y;
    gBtlWork->unk_0D4 = a->z;
    return 1;
}

void task_bos_boogie_2(BoogieWork* work) {
    BtlObj* a;
    u16 f;
    void* pal;
    s16 x;
    s16 y;

    a = &work->actor;
    f = GetBattleSpritePriorityFlags(a->y);

    if (!(a->unk_034 & 4)) {
        f |= 1;
    }

    if (func_0801CA00(a) && work->unk_000 != 4) {
        pal = work->palette2;
    } else {
        pal = work->palette;
    }
    WorldToScreen(&x, &y, a->x, a->y, a->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, 0, f, -4100 - (a->y >> 8) * 4);
    TaskPoolDraw(&work->tasks);
}

void task_bos_boogie_3(BoogieWork* work) {
    func_0801B7D8(&work->actor);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}

void func_080D9A14(void) {
    BtlObj* t;

    t = ListPoolFirst(&gBtlWork->pool);
    while (t != 0) {
        if (t->unk_000 != 39) {
            t->unk_034 |= 0x40;
            t->unk_024 = 0;
        }
        t = ListPoolNext(&t->node);
    }
}

void func_080D9A58(void) {
    func_080D9A14();
    gUnk_0203C568 = 0;

    if (gUnk_0203C560 <= 2) {
        gUnk_0203C560 = 3;
        gUnk_0203C554 += 540;
    }
}

u32 GetBoogieDiceState(void) {
    if (IsTaskActive((Task*)gBoogieWork->unk_160) != 0) {
        return *(s32*)((Task*)gBoogieWork->unk_160)->work;
    }
    return 11;
}

const char gTaskNameBosBoogie[] = "task_bos_boogie";

TaskDesc gTaskDescBosBoogie = {
    gTaskNameBosBoogie,
    (void (*)(void*, void*))task_bos_boogie_0,
    task_bos_boogie_1,
    (void (*)(void*))task_bos_boogie_2,
    (void (*)(void*))task_bos_boogie_3,
    0x178,
};
