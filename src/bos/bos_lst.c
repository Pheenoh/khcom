#include "bos6.h"
#include "sprites_bos6.h"
#include "gba/io_reg.h"

#ifdef VERSION_EU
extern u8 eu_0810BA1C(BosLstWork* work, s32 idx);
#endif

const EmyKind gBosLstEmyKind = { 40, 256, 8, 8, 0, 128, 0 };

const BattleBackgroundDef gBosLstBattleBackgroundDef = {
    gUnk_09CC5054, 0x8000, { 0, 0 }, gUnk_09D69454, 0x140, { 0, 0 }, { gUnk_09D4B274, gUnk_09D4B274, gUnk_09D4B274, gUnk_09D4B274 }
};

const LstAnimDef gLstAnimDefs[8] = {
    { gUnk_09D4DA74, 0, 8, { 0, 0, 0, 0 }, 3, 47, { 0, 0 }, -15, 17, 61, 65535, 60, { 0, 0 }, -43, -17, 80, 72, 0, 72, { 0, 0 } },
    { gUnk_09D4FA74, 0, 8, { 1, 0, 0, 0 }, 65533, 47, { 1, 0 }, 15, 17, 61, 1, 60, { 1, 0 }, 43, -17, 80, 184, 0, 72, { 0, 0 } },
    { gUnk_09D4E274, 0, 8, { 0, 0, 0, 0 }, 3, 47, { 0, 0 }, -15, 17, 61, 65535, 60, { 0, 0 }, -43, -17, 80, 72, 0, 72, { 0, 0 } },
    { gUnk_09D50274, 0, 8, { 1, 0, 0, 0 }, 65533, 47, { 1, 0 }, 15, 17, 61, 1, 60, { 1, 0 }, 43, -17, 80, 184, 0, 72, { 0, 0 } },
    { gUnk_09D4EA74, 0, 8, { 0, 0, 0, 0 }, 3, 47, { 0, 0 }, -15, 17, 61, 65535, 60, { 0, 0 }, -43, -17, 80, 72, 0, 72, { 0, 0 } },
    { gUnk_09D50A74, 0, 8, { 1, 0, 0, 0 }, 65533, 47, { 1, 0 }, 15, 17, 61, 1, 60, { 1, 0 }, 43, -17, 80, 184, 0, 72, { 0, 0 } },
    { gUnk_09D4F274, 0, 8, { 0, 0, 0, 0 }, 3, 47, { 0, 0 }, -15, 17, 61, 65535, 60, { 0, 0 }, -43, -17, 80, 72, 0, 72, { 0, 0 } },
    { gUnk_09D51274, 0, 8, { 1, 0, 0, 0 }, 65533, 47, { 1, 0 }, 15, 17, 61, 1, 60, { 1, 0 }, 43, -17, 80, 184, 0, 72, { 0, 0 } },
};

const u16 gUnk_09A4D0EC[48] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
};

const u8 gUnk_09A4D14C[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };

const s32 gUnk_09A4D154[16] = { -1, -2, -3, -4, -5, -6, -7, -8, -7, -6, -5, -4, -3, -2, -1, 0 };

void* const gUnk_09A4D194[18][2] = {
    { gUnk_09CC5054, gUnk_09D4DA74 },
    { gUnk_09CCD054, gUnk_09D51A74 },
    { gUnk_09CCD694, gUnk_09D52274 },
    { gUnk_09CCDC14, gUnk_09D52A74 },
    { gUnk_09CCE1D4, gUnk_09D53274 },
    { gUnk_09CCE7F4, gUnk_09D53A74 },
    { gUnk_09CCEDB4, gUnk_09D54274 },
    { gUnk_09CCF374, gUnk_09D54A74 },
    { gUnk_09CCFA54, gUnk_09D55274 },
    { gUnk_09CC5054, gUnk_09D4FA74 },
    { gUnk_09CCD054, gUnk_09D55A74 },
    { gUnk_09CCD694, gUnk_09D56274 },
    { gUnk_09CCDC14, gUnk_09D56A74 },
    { gUnk_09CCE1D4, gUnk_09D57274 },
    { gUnk_09CCE7F4, gUnk_09D57A74 },
    { gUnk_09CCEDB4, gUnk_09D58274 },
    { gUnk_09CCF374, gUnk_09D58A74 },
    { gUnk_09CCFA54, gUnk_09D59274 },
};

TaskDesc gTaskDescBosLst = {
    "task_bos_lst",
    (TaskInitFunc)task_bos_lst_0,
    (TaskUpdateFunc)task_bos_lst_1,
    (TaskFunc)task_bos_lst_2,
    (TaskFunc)task_bos_lst_3,
    0x10A4,
};

s32 func_0810C2B4(s32 x) {
    return x * x;
}

s32 func_0810C2BC(s32 x) {
    return x * x;
}

void func_0810C2C4(u8** p) {
    p[1][1] = 1;
}

void func_0810C2CC(BosLstWork* work, u16 a, u16 b) {
    u16 zero;

    zero = 0;
    work->unk_00C = a;
    work->unk_00E = b;
    work->unk_070 = zero;
    work->unk_072 = zero;
}

void func_0810C2E0(BosLstWork* work) {
    func_0801BCD4(&work->unk_0E4);
    work->unk_070 += 1;
}

void func_0810C2F8(BosLstWork* work) {
    u32 i;

    for (i = 0; i < 0x20; i++) {
        if (work->lstTasks[i] != 0) {
            func_08000DE8(&gBtlWork->taskPools[1], work->lstTasks[i]);
        }
        work->lstTasks[i] = 0;
    }
}

u8 func_0810C32C(BosLstWork* work, s32 a) {
    LstSpawn s;
    u8 r;
    void* pool;
    s32 range;
    s32 d1;
    s32 d2;
    s32 d3;
    s32 d4;
    s32 d5;
    s32 d6;
    s32 d7;

    r = 0;
    if (work->unk_002 == 0) {
        s.unk_00 = a;
        s.unk_12 = work->unk_012;
        s.unk_14 = &work->unk_074;
        s.unk_04 = work->x;
        s.unk_08 = work->y + 0x400;
        s.unk_0C = work->z - 0x1400;
        switch (a) {
        default:
            s.unk_04 += work->unk_012 << 12;
            d1 = (GetRandom() % 21 << 8) + 0x800;
            s.unk_08 -= d1;
            d2 = (GetRandom() % 17 << 8) - 0x800;
            s.unk_0C += d2;
            pool = &gBtlWork->taskPools[1];
            break;
        case 4:
            range = 0x800;
            d3 = (GetRandom() % 17 << 8) - range;
            s.unk_04 += d3;
            d4 = (GetRandom() % 17 << 8) - range;
            s.unk_0C += d4;
            s.unk_10 = work->unk_07A * 4;
            pool = &work->tasks;
            break;
        case 5:
            d5 = (GetRandom() % 33 << 8) - 0x1000;
            s.unk_04 += d5;
            d6 = (GetRandom() % 21 << 8) + 0x800;
            s.unk_08 -= d6;
            d7 = (GetRandom() % 65 << 8) - 0x2000;
            s.unk_0C += d7;
            pool = &work->tasks;
            break;
        }
        TaskCreate(pool, &gTaskDescBosLstFal, &s);
        r = 1;
    }
    return r;
}

void func_0810C494(BosLstWork* work, u16 a, u16 b, u8 c) {
    u16 id;
    u16 v;

    id = a;
    v = id * 2;
    if (work->unk_012 < 0) {
        v ^= 1;
    }
    if (work->unk_01C == 1) {
        v ^= 1;
    }
    switch (gUnk_09A4D14C[a]) {
    case 0:
        SetObjTileSource(work->tiles, gUnk_09C4B012);
        AnimChangeWithTables(&work->anim, v, b, gUnk_09EFAD3C, gUnk_09EFABB0);
        break;
    case 1:
        v -= 14;
        SetObjTileSource(work->tiles, gUnk_09C51CBC);
        AnimChangeWithTables(&work->anim, v, b, gUnk_09EFADBC, gUnk_09EFAD74);
        break;
    }
    if (c == 1) {
        AnimChange(&work->anim, v, b);
    } else {
        AnimReset(&work->anim);
        AnimStart(&work->anim, v, b);
    }
    work->unk_01E = id;
    work->unk_020 = b;
    work->unk_022 = work->unk_012;
}

void func_0810C57C(BosLstWork* work, s16 a) {
    u8 f;

    if (work->unk_012 != a) {
        work->unk_012 = a;
        func_0810C494(work, work->unk_01E, work->unk_020, 1);
        f = 1;
        if (work->unk_012 > 0) {
            f = (work->unk_01C ^ f) != 0;
        } else if (work->unk_01C == 0) {
            f = 0;
        }
        if (f == 1) {
            work->unk_118 |= 4;
            work->sub[0].unk_04C |= 4;
            work->sub[1].unk_04C |= 4;
        } else {
            work->unk_118 &= ~4;
            work->sub[0].unk_04C &= ~4;
            work->sub[1].unk_04C &= ~4;
        }
    }
}

s16 func_0810C630(BosLstWork* work) {
    s16 r;

    r = -1;
    if (work->sub[0].unk_000 == 0) {
        r = 0;
    } else if (work->sub[1].unk_000 == 0) {
        r = 1;
    }
    return r;
}

u8 func_0810C65C(BosLstWork* work, u16 a) {
    s16 i;
    u8 r;

    r = 0;
    if (work->unk_006 == 1) {
        work->sub[0].unk_00A = 2;
        work->sub[1].unk_00A = 2;
    } else {
        if (a == 0) {
            i = 0;
            if (work->sub[i].unk_000 == 1) {
                work->sub[i].unk_00A = 2;
            } else {
                work->sub[i].unk_00A = 0;
            }
            work->sub[i].unk_002 = 1;
            i = 1;
            if (work->sub[i].unk_000 == 1) {
                work->sub[i].unk_00A = 2;
            } else {
                work->sub[i].unk_00A = 0;
            }
            work->sub[i].unk_002 = 1;
        } else {
            i = func_0810C630(work);
            work->sub[i].unk_00A = a;
            i = i ^ 1;
            if (work->sub[i].unk_000 == 1) {
                work->sub[i].unk_00A = 2;
            } else {
                work->sub[i].unk_00A = 0;
            }
            work->sub[i].unk_002 = 1;
        }
        r = 1;
    }
    return r;
}

void func_0810C754(BosLstWork* work) {
    s32 t;
    BtlObj* pos;

    t = work->unk_07C;
    work->unk_07C = t - 0x100;
    if (gBtlWork->flags & 0x20000000) {
        work->unk_07C = t - 0x200;
    }
    if (work->unk_012 > 0) {
        pos = gBtlWork->actor;
        if (pos->x > work->x + 0x1000) {
            work->unk_07C -= 0x80;
        }
    } else {
        pos = gBtlWork->actor;
        if (pos->x < work->x - 0x1000) {
            work->unk_07C -= 0x80;
        }
    }
}

void func_0810C7C4(BosLstWork* work) {
    work->unk_058 = gUnk_09A4D154[(work->unk_06A >> 2) & 15] << 8;
    work->unk_06A += 1;
    if (work->unk_000 == 1) {
        work->unk_058 -= 0x1800;
    }
}

void task_bos_lst_0(BosLstWork* work, void* pool) {
    BtlObj* pos;
    void* obj;
    void* anim;
    const void* tbl;
    void* p;
    BtlWork* g;
    u32 i;

    if (pool == 0) {
        work->unk_000 = 0;
        work->unk_001 = 0;
        work->task = TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFld, (void*)&gBosLstBattleBackgroundDef);
        work->unk_008 = 0;
        work->x = 0x14000;
        work->z = -0x5400;
    } else {
        work->unk_000 = 1;
        work->unk_001 = 0;
        work->task = TaskCreate(pool, &gTaskDescBosLstFld, (void*)&gBosLstBattleBackgroundDef);
        work->unk_008 = 7;
        work->x = 0x1D000;
        work->z = -0x14400;
    }
    work->unk_002 = 0;
    work->unk_006 = 0;
    work->unk_00A = 0;
    func_0810C2CC(work, 2, 1);
    work->unk_010 = 0;
    work->unk_012 = 1;
    work->unk_014 = 0;
    work->unk_016 = 0xFFFF;
    work->y = 0x1F000;
    work->unk_050 = 0;
    work->unk_054 = 0;
    work->unk_058 = 0;
    pos = gBtlWork->actor;
    work->unk_05C = pos->x;
    work->unk_060 = pos->y;
    work->unk_064 = pos->z;
#ifdef VERSION_EU
    work->unk_004 = 0;
#endif
    work->unk_068 = 0;
    work->unk_06A = 0;
    work->unk_06C = 0;
    work->unk_06E = 0;
    work->unk_070 = 0;
    work->unk_072 = 0;
    work->unk_074 = 0;
    work->unk_076 = 0;
    work->unk_078 = 0;
    work->unk_07C = 0x1E000;
    work->unk_082 = 0;
    work->unk_08E = 0;
    work->unk_0AA = 0;
    work->unk_0BE = 0;
    work->unk_0D4 = 0;
    work->unk_0D6 = 0;
    work->sub[0].unk_000 = 0;
    work->sub[0].unk_001 = 1;
    work->sub[0].unk_002 = 1;
    work->sub[0].unk_004 = 0;
    work->sub[0].timer = 0;
    work->sub[0].unk_008 = 0;
    work->sub[0].unk_00A = 0;
    work->sub[0].unk_00C = -1;
    work->sub[1].unk_000 = 0;
    work->sub[1].unk_001 = 0;
    work->sub[1].unk_002 = 1;
    work->sub[1].unk_004 = 0;
    work->sub[1].timer = 0;
    work->sub[1].unk_008 = 0;
    work->sub[1].unk_00A = 0;
    work->sub[1].unk_00C = -1;
    work->sub[0].tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EFADC4, 16), gUnk_09C53724);
    work->sub[1].tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EFAE54, 16), gUnk_09C58590);
    work->tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EFABB0, 0x62), gUnk_09C4B012);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    i = 0;
    obj = &work->unk_0E4;
    anim = &work->anim;
    for (; i < 32; i++) {
        work->lstTasks[i] = 0;
    }
    tbl = &gBosLstEmyKind;
    func_0801B37C(obj, tbl, work->x, work->y, work->z);
    work->unk_118 |= 0x200000000400;
    func_0801C2DC(obj, 1);
    obj = work->sub[0].unk_018;
    func_0801B37C(obj, tbl, work->x, work->y, work->z);
    do {
        work->sub[0].unk_04C |= 0x400;
        func_0801C7FC(obj, 40, 0x100);
    } while (0);
    obj = work->sub[1].unk_018;
    func_0801B37C(obj, tbl, work->x, work->y, work->z);
    work->sub[1].unk_04C |= 0x400;
    func_0801C7FC(obj, 40, 0x100);
    ColliderInit(work->collider, 8, 20, 20);
    p = &work->unk_4D0;
    ColliderInit(p, 8, 28, 64);
    ColliderSetDisabled(p, 1);
    for (i = 0; (s32)i < 8; i++) {
        ColliderInit(work->unk_52C[i], 7, 24, 4);
        ColliderSetDisabled(work->unk_52C[i], 1);
    }
    work->unk_01C = 0;
    work->unk_01E = 0;
    work->unk_020 = 0;
    work->unk_024 = 0xFFFF;
    work->unk_026 = 0;
    AnimInit(anim, gUnk_09EFAD3C, gUnk_09EFABB0);
    func_0810C494(work, 0, 1, 0);
    AnimInit(&work->sub[0].anim, gUnk_09EFAE1C, gUnk_09EFADC4);
    AnimStart(&work->sub[0].anim, 0, 1);
    AnimInit(&work->sub[1].anim, gUnk_09EFAEAC, gUnk_09EFAE54);
    AnimStart(&work->sub[1].anim, 0, 1);
    TaskPoolInit(&work->tasks, 0x60);
    func_0801C298(0, 1);
    func_0801C298(1, 1);
    func_0801C298(2, 1);
    SetBattleActorPosition(0xCC00, 0x1F000, 0);
    LoadBgMap(1, gUnk_09D34A74, 0x1000);
    LoadBgMap(1, gUnk_09D4DA74, 0x800);
    LoadBgMap(0, gUnk_09D4B274, 0x800);
    g = gBtlWork;
    g->unk_0CC = work->x;
    g->unk_0D0 = work->y;
    g->unk_0D4 = work->z;
    g->unk_0D8 = -16;
}
s32 func_0810CC14(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (c == 0) {
        c = Sqrt8((abs(a - b) << 8) / 768);
        if (c < d) {
            c = d;
        }
        if (c > e) {
            c = e;
        }
    }
    if (abs(a - b) < c) {
        a = b;
    } else if (a < b) {
        a += c;
    } else {
        a -= c;
    }
    return a;
}

void func_0810CC68(BosLstWork* work) {
    if (work->unk_012 > 0) {
        work->x = func_0810CC14(work->x, 0x14800, 0, 0x80, 0x200);
    } else {
        work->x = func_0810CC14(work->x, 0xA800, 0, 0x80, 0x200);
    }
    work->y = func_0810CC14(work->y, 0x1F000, 0, 0x80, 0x200);
    work->z = func_0810CC14(work->z, -0x5400, 0, 0x80, 0x400);
    if (work->z == -0x5400) {
        func_0810C754(work);
        if (work->unk_07C < 0) {
            work->unk_07C = 0x400;
            if (!(gBtlWork->flags & 0x20000000)) {
                func_0810C2E0(work);
            }
        }
    }
}

void func_0810CD00(BosLstWork* work) {
    BtlWork** pp;
    s32 y;

    if (work->unk_006 == 0) {
        func_0810C2CC(work, 2, 1);
        work->unk_08E = 0;
    }
    pp = &gBtlWork;
    func_0810C754(work);
    if (work->unk_07C < 0) {
        work->unk_07C = 0x400;
        if (((*pp)->flags & 0x20000000) == 0) {
            work->unk_084 = -0x1200;
            work->unk_088 = (*pp)->actor->x - ((work->unk_012 * 5) << 10);
            if (work->unk_088 > 0x14000) {
                work->unk_088 = 0x14000;
            }
            if (work->unk_088 < 0xB000) {
                work->unk_088 = 0xB000;
            }
            func_0810C2E0(work);
        }
    }
    if (work->unk_012 > 0) {
        if (work->x < 0x14800) {
            work->x = work->x + 192;
        }
    } else if (work->x > 0xA800) {
        work->x = work->x - 192;
    }
    y = 0x1F000;
    work->unk_050 = (-gSineTable[((work->unk_06C * 4) & 0xFF) + 64] / 16) << 8;
    work->y = func_0810CC14(work->y, y, 0, 0x100, 0x200);
    work->z = func_0810CC14(work->z, -0xA400, 0x400, 0x100, 0x200);
}

void func_0810CE1C(BosLstWork* work) {
    if (work->unk_006 == 1) {
        func_0810C2CC(work, 3, 2);
        work->unk_08E = 0;
    }
    if (work->unk_012 > 0) {
        work->x = func_0810CC14(work->x, 0x14800, 0, 0x80, 0x200);
    } else {
        work->x = func_0810CC14(work->x, 0xA800, 0, 0x80, 0x200);
    }
    work->y = func_0810CC14(work->y, 0x1F000, 0, 0x80, 0x200);
    work->z = func_0810CC14(work->z, -0x5400, 0, 0x80, 0x400);
    func_0810C754(work);
    if (work->unk_07C < 0) {
        work->unk_07C = 0x400;
        if (!(gBtlWork->flags & 0x20000000)) {
            func_0810C2E0(work);
        }
    }
}

void func_0810CEC8(BosLstWork* work) {
    s16 v;
    s16 n;
    s32 target;
    s32 dir;
    s32 dir2;

    if (work->unk_006 == 0) {
        func_0810C2CC(work, 0, 3);
        return;
    }
    if (work->unk_0AA > 0) {
        work->unk_00A = 1;
    }
    if (work->unk_012 > 0) {
        work->x = func_0810CC14(work->x, 0x14800, 0, 0x80, 0x100);
    } else {
        work->x = func_0810CC14(work->x, 0xA800, 0, 0x80, 0x100);
    }
    work->y = func_0810CC14(work->y, 0x1F000, 0, 0x100, 0x400);
    work->z = func_0810CC14(work->z, -0x5400, 0, 0x100, 0x400);
    if (work->unk_00A == 0) {
        func_0810C754(work);
        if (work->unk_07C < 0) {
            work->unk_07C = 0x400;
            if ((gBtlWork->flags & 0x20000000) == 0) {
                work->unk_00A += 1;
                work->unk_0AA += 1;
                work->unk_0A8 = 0;
                work->unk_0B0 = 0;
                work->unk_0AC = 0;
                work->unk_068 = 0;
            }
        }
        if (work->unk_00A == 0) {
            return;
        }
    }
    switch (work->unk_0A8) {
    case 0:
        if (work->unk_008 != 4) {
            if ((((s16)work->unk_06C + 4) & 7) == 0) {
                func_0810C32C(work, 0);
            }
        }
        if (work->z < -0x25400 || (work->unk_012 > 0 && work->x < -0x7000) ||
            (work->unk_012 < 0 && work->x > 0x26000)) {
            dir = work->unk_012;
            func_0810C57C(work, -dir);
            work->unk_0A8 = 1;
            work->unk_068 = 0;
            work->unk_0B0 = 0;
            v = 27 - (*(s32*)&work->unk_018 >> 4);
            if (work->sub[0].unk_000 == 1) {
                v += 8;
                work->unk_0B0 = 0x100;
            }
            if (work->sub[1].unk_000 == 1) {
                v += 8;
                work->unk_0B0 += 0x100;
            }
            if (work->unk_012 < 0) {
                work->x = -0x1000;
            } else {
                work->x = 0x20000;
            }
            work->y = 0x1F000;
            work->z = (-64 - v) << 8;
            work->unk_0B4 = 0xA0;
        } else {
            work->unk_0B0 += 64;
            if (work->unk_0B0 > 0x800) {
                work->unk_0B0 = 0x800;
            }
            work->x -= (work->unk_012 << 1) * work->unk_0B0;
            work->z -= (work->unk_0B0 * 192) >> 8;
        }
        break;
    case 1:
        if (work->unk_012 > 0) {
            work->x = func_0810CC14(work->x, 0x15800, 0, 0x100, 0x400);
        } else {
            work->x = func_0810CC14(work->x, 0x9800, 0, 0x100, 0x400);
        }
        work->y = func_0810CC14(work->y, 0x1F000, 0, 0x100, 0x400);
        work->unk_068 += 1;
        if (work->unk_068 == ((*(s32*)&work->unk_018 * 60) >> 8) + 90) {
            work->unk_0A8 = 2;
            work->unk_068 = 0;
        }
        break;
    case 2:
        func_0810C2E0(work);
        work->unk_068 = 0;
        work->unk_0B0 = (work->unk_0AA + 1) << 8;
        if (work->sub[0].unk_000 == 1) {
            work->unk_0B0 += 0x100;
        }
        if (work->sub[1].unk_000 == 1) {
            work->unk_0B0 += 0x100;
        }
        break;
    case 3:
    case 4:
        v = 39 - (*(s32*)&work->unk_018 >> 4);
        if (work->sub[0].unk_000 == 1) {
            v += 8;
            work->unk_0B0 += 0x100;
        }
        if (work->sub[1].unk_000 == 1) {
            v += 8;
            work->unk_0B0 += 0x100;
        }
        work->z = (-64 - v) << 8;
        work->unk_0B4 = 12;
        work->unk_068 += 1;
        if (work->unk_068 > 59) {
            n = 3;
            if (*(s32*)&work->unk_018 <= 63) {
                n = 6;
            } else if (*(s32*)&work->unk_018 <= 127) {
                n = 5;
            } else if (*(s32*)&work->unk_018 <= 191) {
                n = 4;
            }
            work->unk_0AA += 1;
            if (work->unk_0AA >= n) {
                work->unk_0A8 = 5;
                work->unk_068 = 0;
                if (gBtlWork->actor->x < 0xF800) {
                    work->x = 0x14800;
                    func_0810C57C(work, 1);
                } else {
                    work->x = 0xA800;
                    func_0810C57C(work, -1);
                }
                work->y = 0x1F000;
                work->z = -0x25400;
            } else {
                if (work->unk_006 == 1) {
                    work->unk_0A8 = 2;
                } else {
                    work->unk_0A8 = 1;
                }
                work->unk_068 = 0;
                dir2 = work->unk_012;
                func_0810C57C(work, -dir2);
            }
        }
        break;
    case 5:
        work->z = func_0810CC14(work->z, target = -0x5400, 0, 0x200, 0x800);
        if (work->z == target) {
            func_0810C2CC(work, 0, 3);
            work->unk_068 = 0;
            work->unk_0AA = 0;
        }
        break;
    }
}

u8 func_0810D304(BosLstWork* work, s32 idx) {
    s32 i;
    u8 r;

    r = 0;
    if (idx < 0) {
        for (i = 0; i < work->unk_0C4; i++) {
            if (func_08110938(work->lstTasks[i]) == 1) {
                r = 1;
                break;
            }
        }
    } else if (idx < work->unk_0C4) {
        if (func_08110938(work->lstTasks[idx]) == 1) {
            r = 1;
        }
    }
    return r;
}

#ifdef VERSION_EU
extern u8 eu_0810F08C(LstTask* work);
u8 eu_0810BA1C(BosLstWork* work, s32 idx) {
    s32 i;
    u8 r;

    r = 0;
    if (idx < 0) {
        for (i = 0; i < work->unk_0C4; i++) {
            if (eu_0810F08C(work->lstTasks[i]) == 1) {
                r = 1;
                break;
            }
        }
    } else if (idx < work->unk_0C4) {
        if (eu_0810F08C(work->lstTasks[idx]) == 1) {
            r = 1;
        }
    }
    return r;
}
#endif

u8 func_0810D364(BosLstWork* work) {
    s16 v;
    s32 i;

    v = 0;
    for (i = 0; i < work->unk_0C4; i++) {
        v = func_0811095C(work->lstTasks[i], v);
    }
    return v != 0;
}

void func_0810D3A8(BosLstWork* work) {
    s32 i;

    for (i = 0; i < work->unk_0C4; i++) {
        if (func_08110918(work->lstTasks[i]) == 1) {
            func_08110984(work->lstTasks[i]);
        }
    }
}

u8 func_0810D3E0(BosLstWork* work, s32 idx, s16 a) {
    s32 i;
    u8 r;

    r = 0;
    if (idx < 0) {
        for (i = 0; i < work->unk_0C4; i++) {
            if (func_08110918(work->lstTasks[i]) == 1) {
                func_08110994(work->lstTasks[i], a);
                r = 1;
            }
        }
    } else if (idx < work->unk_0C4) {
        if (func_08110918(work->lstTasks[idx]) == 1) {
            func_08110994(work->lstTasks[idx], a);
            r = 1;
        }
    }
    return r;
}

void func_0810D478(BosLstWork* work) {
    s32 i;

    for (i = 0; i < work->unk_0C4; i++) {
        if (func_08110918(work->lstTasks[i]) == 1) {
            func_081109A8(work->lstTasks[i]);
        }
    }
}

void func_0810D4B0(BosLstWork* work) {
    s32 i;
    u8 flag;

    flag = 1;
    for (i = 0; i < work->unk_0C4; i++) {
        if (func_08110918(work->lstTasks[i]) == 1) {
            if (func_081109B8(work->lstTasks[i], flag) == 1) {
                flag = 0;
            }
        }
    }
}

void func_0810D4F8(BosLstWork* work) {
    LstSpawn4 s;
    PcPos* obj;
    s32 i;
    s16* pBC;
    s16* pBE;
    s32 v;

    obj = (PcPos*)&work->unk_0E4;
    if (work->unk_012 > 0) {
        work->x = func_0810CC14(work->x, 0x14800, 0, 0x100, 0x400);
    } else {
        work->x = func_0810CC14(work->x, 0xA800, 0, 0x100, 0x400);
    }
    work->y = func_0810CC14(work->y, 0x1F000, 0, 0x100, 0x400);
    work->z = func_0810CC14(work->z, -0x5400, 0, 0x100, 0x400);
    v = work->unk_0BE;
    pBE = &work->unk_0BE;
    pBC = &work->unk_0BC;
    if (v == 0) {
        work->unk_0C4 = 3;
        s.x = obj->x;
        s.y = obj->y - 0x1100;
        s.z = obj->z + 0x800;
        for (i = 0; i < work->unk_0C4; i++) {
            s.unk_00 = 0;
            s.unk_04 = i;
            s.unk_08 = &work->unk_012;
            s.unk_0C = &work->unk_074;
            s.unk_10 = &work->unk_004;
            s.unk_20 = s.x + (i << 11);
            s.y2 = obj->y + 0x1400;
            s.unk_28 = s.z + ((i << 2) << 8);
            work->lstTasks[i] = TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstBit, &s);
        }
        *pBC = 0;
        *pBE += 1;
        work->unk_068 = 0;
        work->unk_07C = 0xC000;
        func_0810C494(work, 5, 0, 1);
        m4aSongNumStart(SONG_VO_MARL_ATTACK01);
    }
    if (func_0810D364(work) == 0) {
        func_0810C2F8(work);
        work->unk_068 = 0;
        *pBC = 0;
        *pBE = 0;
        func_0810C2CC(work, 0, 5);
        func_0810C494(work, 0, 1, 0);
    } else {
        switch (*pBC) {
        case 0:
            work->unk_068 += 1;
            if (work->unk_068 > 30) {
                work->unk_068 = 0;
                *pBC += 1;
            }
            break;
        case 1:
            if (work->unk_004 <= 0) {
                work->unk_07C -= 0x100;
            }
            if (work->unk_07C <= 0) {
                work->unk_07C = 0x400;
#ifdef VERSION_EU
                if (eu_0810BA1C(work, -1) != 0) {
                    break;
                }
#endif
                if ((gBtlWork->flags & 0x20000000) == 0) {
                    func_0810C2E0(work);
                    work->unk_0C0 = 0;
                }
            } else if (((work->unk_07C >> 8) & 0x3F) == 0) {
                func_0810D3A8(work);
            }
            break;
#ifdef VERSION_EU
        default:
            func_0810D478(work);
            break;
#endif
        }
    }
}

s32 func_0810D70C(BosLstWork* work) {
    s32 base;
    s16 d;
    s32 r;

    base = work->y + work->unk_058;
    r = base + 0x1A00;
    d = abs((gBtlWork->actor->x - work->x) >> 8);
    if (d > 23) {
        if (d <= 83) {
            r -= (d / 3) << 8;
        } else if (d <= 143) {
            r = base - 0x400;
        } else {
            base -= 0x400;
            r = base + (((d - 144) / 4) << 8);
        }
    }
    return r;
}

void func_0810D77C(BosLstWork* work) {
    LstSpawn4 s;
    PcPos* obj;
    s32 i;
    s32 st;
    s32 target;
    s32 k;
    u8 found;
    s32* pDC;
    s32* p4C;
    u16 v;
    s32 z;

    work->unk_026 = 30;
    st = work->unk_0D6;
    switch (st) {
    case 0:
        work->z = func_0810CC14(work->z, target = -0x2000, 0x400, k = 0x100, 0x400);
        if (work->z != target) {
            break;
        }
        work->unk_0D6 += 1;
        work->unk_06E = st;
        work->unk_0D4 = 0;
        work->unk_0DC = k;
        work->unk_0BE = st;
        for (i = 0; i < 8; i++) {
            ColliderSetDisabled(work->unk_52C[i], 0);
        }
    case 1:
        obj = (PcPos*)&work->unk_0E4;
        v = work->unk_06E;
        if (work->unk_06E == 0) {
            work->unk_06E = v + 1;
            work->unk_0C4 = 3;
            s.x = obj->x;
            s.y = obj->y - 0x1100;
            s.z = obj->z + 0x800;
            for (i = 0; i < work->unk_0C4; i++) {
                s.unk_00 = 1;
                s.unk_04 = i;
                s.unk_08 = &work->unk_012;
                s.unk_0C = &work->unk_074;
                s.unk_10 = &work->unk_004;
                s.unk_20 = s.x + (i << 11);
                s.y2 = obj->y + 0x1400;
                s.unk_28 = s.z + ((i << 2) << 8);
                work->lstTasks[i] = TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstBit, &s);
            }
        }
        if ((gBtlWork->flags & 0x2000000000000) == 0) {
            work->unk_06E += 1;
        }
        found = 0;
        for (i = 0; i < 8; i++) {
            if (func_0801BCA8(work->unk_52C[i]) == 1) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            if (work->unk_0D4 == 0) {
                func_0810C494(work, 2, 0, 1);
            }
            work->unk_0D4 = found;
            work->z = func_0810CC14(work->z, -0x16800, 0, 0x100, 0x400);
        }
        if (work->unk_0D4 == 1) {
            if (func_0810D364(work) == 1) {
                func_0810C754(work);
                if (work->unk_07C < 0) {
                    work->unk_07C = 0x2000;
                    func_0810C2E0(work);
                    work->unk_0C0 = 0;
                } else if ((work->unk_06E & 0x1F) == 0) {
                    func_0810D3A8(work);
                }
            } else {
                work->unk_0DC += 1;
            }
            work->unk_0DC += 1;
            if (work->unk_0DC > 0x900) {
                work->unk_0DC = 0x900;
            }
            func_0810FF6C(work->task, work->unk_0DC);
        } else if (work->unk_06E > 180) {
            func_0810D478(work);
            work->unk_0D6 += 1;
            work->unk_0DC = 0;
        }
        if (work->unk_06E > 0x4AF ||
            (work->unk_0D4 == 1 && (gBtlWork->flags & 0x2000000000000) == 0 &&
             gBtlWork->actor->z > work->z + work->unk_058 + 0x1800)) {
            func_0810D478(work);
            work->unk_0D6 += 1;
        }
        work->y = func_0810CC14(work->y, 0x1F000, 0x100, 0x100, 0x400);
        break;
    case 2:
        p4C = &work->z;
        for (i = 0; i < 8; i++) {
            ColliderSetDisabled(work->unk_52C[i], 1);
        }
        ApproachValueHalfSteps(p4C, -0x16800, 48);
        if (work->unk_012 < 0) {
            if (work->x < 0x26000) {
                work->x += 0x800;
                return;
            }
        } else {
            if (work->x > -0x7000) {
                work->x -= 0x800;
                return;
            }
        }
        func_0810C2F8(work);
        work->unk_0BE = 0;
        if (gBtlWork->actor->x < 0xF800) {
            work->x = 0x14800;
            func_0810C57C(work, 1);
        } else {
            work->x = 0xA800;
            func_0810C57C(work, -1);
        }
        work->y = 0x1F000;
        work->z = -0x26800;
        func_0810C2CC(work, 0, 3);
        work->unk_0D4 = 0;
        work->unk_0D6 = 0;
        work->unk_06E = 0;
        work->unk_01C = 0;
        func_0810C494(work, 0, 1, 0);
        break;
    }
}

u8 func_0810DB40(BosLstWork* work) {
    switch (work->unk_00C) {
    case 0:
        func_0810FF50(work->task, 2, work->unk_012);
        func_0810CC68(work);
        break;
    case 1:
        func_0810FF50(work->task, 1, work->unk_012);
        func_0810CD00(work);
        break;
    case 2:
        func_0810FF50(work->task, 1, work->unk_012);
        func_0810CE1C(work);
        break;
    case 3:
        func_0810FF50(work->task, 0, work->unk_012);
        func_0810CEC8(work);
        break;
    case 4:
        func_0810FF50(work->task, 2, work->unk_012);
        func_0810D4F8(work);
        break;
    case 5:
        func_0810FF50(work->task, 3, work->unk_012);
        func_0810D77C(work);
        break;
    }
    func_0810C7C4(work);
    return 1;
}

u8 func_0810DC28(BosLstWork* work) {
    s32 v;
    u8 r;

    r = 1;
    v = *(s32*)&work->unk_018;
    if (work->unk_00A == 0) {
        work->unk_00A += 1;
        work->unk_082 += 1;
        work->unk_080 = 0;
        work->unk_068 = 0;
    }
    switch (work->unk_080) {
    case 0:
        if (work->unk_068 == 0) {
            m4aSongNumStart(SONG_VO_MARL_ATTACK03);
            work->unk_068 += 1;
        }
        work->x = func_0810CC14(work->x, work->unk_088, 0, 384, 768);
        work->z += work->unk_084;
        work->unk_084 += 320;
        if (work->z > -0x5400) {
            work->z = -0x5400;
            work->unk_080 = 3;
            work->unk_068 = 0;
        }
        break;
    case 1:
    case 2:
        break;
    case 3:
        func_08017F70(work->x + (work->unk_012 << 12), work->y, 0, 268);
        m4aSongNumStart(SONG_EF_MARL_GROUND);
        work->unk_080 = 4;
        work->unk_068 = 0;
    case 4:
        work->unk_068 += 1;
        if (work->unk_068 <= 19) {
            if (func_08011F78(268, gBtlWork->actor->x,
                              gBtlWork->actor->y, 0,
                              32, 32, (s16)(((v * 8) >> 8) + 8)) != 0) {
                m4aSongNumStart(SONG_BTL_MARL_GROUNDHIT);
            }
        }
        if (func_080128EC() == 0) {
            if (work->unk_068 >= ((v * 30) >> 8) + 31) {
                work->unk_080 = 5;
                work->unk_068 = 0;
                if (work->unk_082 > 2) {
                    if (work->unk_006 == 0) {
                        func_0810C2CC(work, 2, 1);
                    } else {
                        func_0810C2CC(work, 3, 2);
                    }
                    work->unk_082 = 0;
                    r = 0;
                }
            }
        }
        break;
    case 5:
        work->z = func_0810CC14(work->z, -0x5400, 0, 256, 1024);
        if (work->z == -0x5400) {
            work->unk_080 = 1;
            work->unk_068 = 0;
            r = 0;
        }
        break;
    }
    return r;
}

u8 func_0810DE04(BosLstWork* work) {
    PcPos* sub;
    s16* p8C;
    s32 st;
    u16 v;
    s16 z;
    u8 r;

    r = 1;
    sub = (PcPos*)work->sub[func_0810C630(work)].unk_018;
    v = work->unk_00A;
    if (work->unk_00A == 0) {
        work->unk_00A = v + 1;
        work->unk_08E += 1;
        work->unk_08C = 0;
        work->unk_068 = 0;
    }
    st = work->unk_08C;
    p8C = &work->unk_08C;
    switch (st) {
    case 0:
        if (work->unk_068 == 0) {
            m4aSongNumStart(SONG_SND_712);
            func_0810C65C(work, 3);
        }
        work->unk_068 += 1;
        if (work->unk_068 > 30) {
            *p8C = 1;
            work->unk_068 = 0;
            m4aSongNumStart(SONG_VO_MARL_ATTACK00);
        }
        break;
    case 1:
        work->unk_068 += 1;
        work->x += work->unk_012 * 0x600;
        work->z -= work->unk_068 << 8;
        if (work->z < -0x1E000) {
            *p8C = 3;
            work->unk_068 = 0;
            work->unk_094 = work->y;
            work->unk_098 = work->z;
            if (gBtlWork->actor->x > 0xF7FF) {
                work->unk_090 = (GetRandom() % 41 << 8) + 0xB000;
                func_0810C57C(work, 1);
            } else {
                work->unk_090 = (GetRandom() % 40 << 8) + 0x11800;
                func_0810C57C(work, -1);
            }
            func_0810C65C(work, 5);
            work->x = work->unk_090;
            work->unk_09C = gBtlWork->actor->x + work->unk_012 * 0x3000;
            work->unk_0A0 = 0x1F000;
            work->unk_0A4 = -0x5400;
        }
        break;
    case 2:
        z = 0;
        *p8C = 3;
        work->unk_068 = z;
        work->unk_09C = gBtlWork->actor->x;
        work->unk_0A0 = 0x1F000;
        work->unk_0A4 = -0x5400;
        break;
    case 3:
        if (work->unk_068 <= 7) {
            ApproachValueHalfSteps(&work->unk_09C, gBtlWork->actor->x + work->unk_012 * 0x3000, 8);
        }
        if (work->unk_068 == 0) {
            work->unk_0A0 = func_0810CC14(work->unk_0A0, gBtlWork->actor->y, 0x100, 0x100, 0x100);
        }
        work->x = func_0810CC14(work->x, work->unk_09C, 0, 0x100, 0x800);
        work->y = work->unk_0A0;
        work->z = func_0810CC14(work->z, work->unk_0A4, 0, 0x1000, 0x1800);
        if (work->z == work->unk_0A4) {
            work->unk_068 += 1;
            if (work->unk_068 > 16) {
                *p8C = 4;
                work->unk_068 = 0;
                work->unk_078 = 0;
                func_0810C65C(work, 4);
                func_0801836C(sub->x, work->unk_0A0, sub->z + 0x2800, -(work->unk_012 * 0x3000), 0x10A);
                m4aSongNumStart(SONG_EF_MARL_KAMAEF);
            }
        }
        break;
    case 4:
        switch (work->unk_068) {
        case 0:
            if (func_08011F78(0x10A, sub->x - (work->unk_012 << 13), work->unk_0A0, sub->z, 48, 12, 64) != 0) {
                m4aSongNumStart(SONG_BTL_MARL_EFEHIT);
            }
        case 1:
        case 2:
        case 3:
            work->x -= work->unk_012 << 9;
            work->z += 0x400;
            break;
        case 4:
        case 5:
        case 6:
            work->x -= work->unk_012 * 0x300;
            work->z += 0x600;
            break;
        case 7:
        case 8:
        case 9:
            work->x -= work->unk_012 << 9;
            work->z += 0x400;
            break;
        case 10:
        case 11:
            work->z -= 0x300;
            break;
        case 12:
        case 13:
            work->z -= 0x180;
            break;
        }
        work->unk_068 += 1;
        if (func_080128EC() == 0) {
            *p8C = 5;
            work->unk_068 = 0;
            func_0810C65C(work, 0);
        }
        break;
    case 5:
        if (work->unk_08E > 2) {
            func_0810C2CC(work, 3, 2);
            work->unk_08E = 0;
            r = 0;
        } else {
            z = 0;
            *p8C = z;
            work->unk_068 = z;
            r = z;
        }
        break;
    }
    return r;
}

u8 func_0810E210(BosLstWork* work) {
    u8 r;

    r = 1;
    if (work->unk_00A == 0) {
        func_0810C494(work, 7, 0, 1);
        m4aSongNumStart(SONG_VO_MARL_ATTACK01);
        m4aSongNumStart(SONG_VO_MARL_ATTACK02);
        work->unk_00A += 1;
    }
    func_0810C32C(work, 1);
    if (work->unk_068 == 30) {
        m4aSongNumStart(SONG_SND_711);
    }
    if (work->unk_068 > 30) {
        work->unk_0B0 += 32;
        if (work->unk_0B0 > 0x800) {
            work->unk_0B0 = 0x800;
        }
        work->x = work->x - work->unk_012 * work->unk_0B0;
        if (work->unk_012 > 0) {
            if (work->x <= -0x8000) {
                r = 0;
            }
        } else if (work->x >= 0x27000) {
            r = 0;
        }
        if (work->unk_0B4 > 0) {
            work->unk_0B4 = work->unk_0B4 + 8;
        } else {
            work->unk_0B4 = work->unk_0B4 - 8;
        }
        work->z += work->unk_0B4;
        if (func_08011F78(0x10B, work->x, work->y, work->z + 0x4000, 12, 32, 64) != 0) {
            m4aSongNumStart(SONG_BTL_MON_HIT06);
        }
        if (r == 0) {
            work->unk_0A8 = 4;
            work->unk_068 = 0;
            func_0810C494(work, 0, 1, 1);
        }
    } else {
        work->unk_068 += 1;
    }
    return r;
}

u8 func_0810E32C(BosLstWork* work) {
    LstSpawn2 s;
    PcPos* obj;
    s16 ang;
    s32 i;
    u8 r;

    obj = (PcPos*)&work->unk_0E4;
    r = 1;
    switch (work->unk_00A) {
    case 0:
        m4aSongNumStart(SONG_SND_709);
        if (work->unk_012 > 0) {
            func_08018A70(obj->x - 0x1800, obj->y - 0x400, obj->z, 256);
        } else {
            func_080189DC(obj->x + 0x1800, obj->y - 0x400, obj->z, 256);
        }
        work->unk_068 = 0;
        work->unk_00A += 1;
        break;
    case 1:
        func_0810C494(work, 6, 0, 1);
        m4aSongNumStart(SONG_VO_MARL_ATTACK01);
        work->unk_00A += 1;
        break;
    case 2:
        work->unk_068 += 1;
        if (work->unk_068 == 32) {
            work->unk_0B8 = 3 - work->unk_072;
            if (work->unk_0B8 <= 0) {
                work->unk_0B8 = 1;
            }
            if (work->sub[0].unk_000 == 1) {
                work->unk_0B8 += 1;
            }
            if (work->sub[1].unk_000 == 1) {
                work->unk_0B8 += 1;
            }
            ang = ((*(s32*)&work->unk_018 * 30) / 256) + 30;
            if (ang <= 44) {
                ang = 45;
            }
            s.unk_0C = obj->x;
            s.unk_10 = obj->y + 0x800;
            s.unk_14 = obj->z - 0x1000;
            for (i = 0; i < work->unk_0B8; i++) {
                s.unk_00 = &work->unk_004;
                s.unk_04 = work->unk_0B8;
                s.unk_06 = i;
                s.unk_08 = i * ang + 90;
                work->lstTasks[i] = TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstCtr, &s);
            }
            work->unk_004 = 0;
            work->unk_068 = 0;
            work->unk_00A += 1;
        }
        break;
    default:
        r = 0;
        for (i = 0; i < work->unk_0B8; i++) {
            if (func_08111F4C(work->lstTasks[i]) == 1) {
                r = 1;
                break;
            }
        }
        if (r == 0) {
            func_0810C2F8(work);
            func_0810C2CC(work, 4, 4);
            func_0810C494(work, 0, 1, 0);
        }
        break;
    }
    func_0810C7C4(work);
    return r;
}

u8 func_0810E524(BosLstWork* work) {
    s16 f;
    u8 r;

    r = 1;
    if (work->unk_0C0 == 0) {
        work->unk_0C0 += 1;
        if (work->unk_0BE <= 1) {
            work->unk_0BC = 1;
        } else {
            work->unk_0BC = 0;
        }
        work->unk_068 = 0;
    }
    if (func_0810D364(work) == 0) {
        func_0810C2F8(work);
        func_0810C2CC(work, 0, 5);
        work->unk_0BE = 0;
        work->unk_0BC = 3;
        work->unk_068 = 0;
    }
    switch (work->unk_0BC) {
    case 0:
        if (work->unk_068 == 0) {
            func_0810D3A8(work);
        }
        work->unk_068 += 1;
        if (work->unk_068 > 59) {
            work->unk_0BC = 1;
            work->unk_068 = 0;
        }
        break;
    case 1:
        f = 1;
        if (work->sub[0].unk_000 == 1) {
            f = 2;
        }
        if (work->sub[1].unk_000 == 1) {
            f++;
        }
        switch (work->unk_068) {
        case 0:
            if (work->unk_00E == 6) {
                func_0810D3E0(work, -1, 1);
                break;
            }
            if (func_0810D304(work, 1) == 0) {
                if (func_0810D3E0(work, 1, f) == 1) {
                    break;
                }
            }
        case 12:
            if (func_0810D304(work, 0) == 0) {
                if (func_0810D3E0(work, 0, f) == 1) {
                    break;
                }
            }
        case 24:
            if (func_0810D304(work, 2) == 0) {
                func_0810D3E0(work, 2, f);
            }
            break;
        }
        work->unk_068 += 1;
        if (func_0810D304(work, -1) == 0) {
            work->unk_068 = 0;
            if (work->unk_0BE > 6) {
                work->unk_0BC = 2;
            } else {
                if (work->unk_00C != 5) {
                    work->unk_0BE += 1;
                }
                r = 0;
            }
        }
        break;
    case 2:
        if (work->unk_068 == 30) {
            func_0810D478(work);
        }
        work->unk_068 += 1;
        if (work->unk_068 > 74) {
            work->unk_0BC = 3;
            work->unk_068 = 0;
        }
        break;
    case 3:
        func_0810C2F8(work);
        func_0810C2CC(work, 0, 5);
        work->unk_0BE = 0;
        r = 0;
        break;
    }
    func_0810C7C4(work);
    return r;
}

u8 func_0810E73C(BosLstWork* work) {
    s16 s;
    u8 r;

    r = 1;
    s = work->unk_00A;
    switch (s) {
    case 0:
        func_0810C494(work, 4, 0, 1);
        m4aSongNumStart(SONG_VO_MARL_ATTACK03);
        work->unk_00A += 1;
        work->unk_068 = 0;
        break;
    case 1:
        work->unk_068 += 1;
        if (work->unk_068 > 120) {
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 2:
        if (AnimIsFinished(&work->anim) == 1) {
            func_08018184(work->x, work->y, work->z - 0x2000, 270);
            m4aSongNumStart(SONG_EF_MARL_HANABIRA);
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 3:
        if (func_080128EC() == 0) {
            func_0810C494(work, 0, 1, 0);
            r = 0;
        }
        if (r == 0) {
            if (work->unk_006 == 1) {
                func_0810C2CC(work, 1, 0);
            } else {
                func_0810C2CC(work, 2, 1);
            }
        }
        break;
    }
    if (work->z > -0x5400) {
        work->z = work->z - 0x400;
    }
    func_0810C7C4(work);
    return r;
}

u8 func_0810E844(BosLstWork* work) {
    void* p;
    s16 t;
    u8 d;

    p = &work->unk_0E4;
    t = work->unk_018;
    if (work->unk_018 <= 63) {
        t = 64;
    }
    switch (work->unk_00E) {
    case 0:
        d = func_0810DC28(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 1:
        d = func_0810DE04(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 2:
        d = func_0810E210(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 3:
        d = func_0810E32C(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 4:
    case 6:
        d = func_0810E524(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = 0x5A00;
        return 1;
    case 5:
        d = func_0810E73C(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    default:
        func_0801AF08(p);
        work->unk_008 = 0;
        work->unk_00A = 0;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    }
    return 1;
}

u8 func_0810E950(BosLstWork* work) {
    void* p;

    p = &work->unk_0E4;
    if (AnimIsFinished((AnimState*)&work->anim) == 1) {
        func_0801AF08(p);
        func_0810C494(work, 0, 1, 1);
        work->unk_008 = 0;
    }
    return 1;
}

u8 func_0810E984(BosLstWork* work) {
    func_0801AF08(&work->unk_0E4);
    work->unk_008 = 0;
    work->unk_00A = 0;
    return 1;
}

u8 func_0810E99C(BosLstWork* work) {
    LstSpawn3 s;
    PcPos* obj;

    obj = (PcPos*)&work->unk_0E4;
    func_0801AF08(obj);
    work->unk_072 += 1;
    work->unk_078 = 0;
    if (work->unk_01E != 2) {
        func_0810C494(work, 0, 1, 0);
    }
    func_0810C65C(work, 0);
    work->unk_07C = ((((*(s32*)&work->unk_018 * 240) >> 9) + 120) << 8);
    if (work->unk_006 == 1) {
        work->unk_026 = 120;
    }
    if (work->unk_00C < 4 || work->unk_00C > 5) {
        func_0810C2F8(work);
    }
    switch (work->unk_00C) {
    case 0:
        switch (work->unk_00E) {
        case 3:
            if (work->unk_072 > 2) {
                func_0810C2CC(work, 4, 4);
            }
            break;
        case 5:
            if (work->unk_006 == 0) {
                func_0810C2CC(work, 2, 1);
            } else {
                func_0810C2CC(work, 1, 0);
            }
            break;
        }
        break;
    case 1:
        if (work->unk_082 + work->unk_072 > 3) {
            work->unk_082 = 0;
            func_0810C2CC(work, 3, 2);
            work->y = 0x1F000;
            work->z = -0x5400;
        }
        break;
    case 2:
        work->y = 0x1F000;
        work->z = -0x5400;
        if (work->unk_08E + work->unk_072 > 3) {
            work->unk_08E = 0;
            func_0810C2CC(work, 3, 2);
        }
        break;
    case 3:
        work->unk_0AA = 0;
        func_0810C2CC(work, 5, 6);
        work->unk_06E = 0;
        if (gBtlWork->actor->x < 0xF800) {
            work->x = 0x15000;
            func_0810C57C(work, -1);
        } else {
            work->x = 0xA000;
            func_0810C57C(work, 1);
        }
        work->y = 0x1F000;
        work->z = -0x5400;
        break;
    case 4:
        func_0810D4B0(work);
        break;
    case 5:
        work->unk_026 = 0;
        func_0810D4B0(work);
        break;
    }
    work->unk_008 = 0;
    work->unk_00A = 0;
    s.unk_00 = work->x + work->unk_050;
    s.unk_04 = work->y + work->unk_054;
    s.unk_08 = (work->z + work->unk_058) - ((obj->unk_9C >> 1) << 8);
    s.unk_12 = 9;
    TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBtlPop, &s);
    return 1;
}

u8 func_0810EBA0(BosLstWork* work) {
    u8 r;
    s32 i;
    s32 d1;
    s32 d2;
    s32 range;

    r = 1;
    func_0801C2DC(&work->unk_0E4, 1);
    work->unk_0DC = 0;
    func_0810C2F8(work);
    work->x = func_0810CC14(work->x, 0xF800, 0x80, 0x100, 0x100);
    work->y = func_0810CC14(work->y, 0x1F000, 0x80, 0x100, 0x100);
    if ((work->unk_07A & 7) == 0) {
        func_0810C32C(work, 4);
    }
    if ((work->unk_07A & 7) == 4) {
        func_0810C32C(work, 5);
    }
    work->unk_07A += 1;
    if (work->z >= -0x5500 || work->unk_00A > 4) {
        func_0810FF64(work->task, 2);
    } else {
        func_0810FF64(work->task, 1);
    }
    switch (work->unk_00A) {
    case 0:
        work->unk_068 = 0;
        func_0801AF4C(&work->unk_0E4);
        m4aSongNumStart(SONG_SND_713);
        m4aSongNumStart(SONG_EV_FLASH00);
        func_0810C494(work, 3, 0, 0);
        work->unk_00A += 1;
    case 1:
        work->z = func_0810CC14(work->z, -0x5400, 0x80, 0x100, 0x140);
        if (work->unk_068 & 0x20) {
            range = 0x200;
            d1 = (GetRandom() % 5 << 8) - range;
            work->unk_050 = d1;
            d2 = (GetRandom() % 5 << 8) - range;
            work->unk_058 = d2;
        } else {
            work->unk_050 = 0;
            work->unk_058 = 0;
        }
        work->unk_068 += 1;
        if (work->unk_068 <= 63) {
            break;
        }
        for (i = 0; i < 8; i++) {
            ColliderSetDisabled(work->unk_52C[i], 1);
        }
        work->unk_0D4 = 0;
        work->unk_00A += 1;
        work->unk_068 = 0;
    case 2:
        work->z = func_0810CC14(work->z, -0x5400, 0x80, 0x100, 0x140);
        if (work->unk_068 & 0x10) {
            range = 0x400;
            d1 = (GetRandom() % 9 << 8) - range;
            work->unk_050 = d1;
            d2 = (GetRandom() % 9 << 8) - range;
            work->unk_058 = d2;
        } else {
            work->unk_050 = 0;
            work->unk_058 = 0;
        }
        work->unk_068 += 1;
        if (work->unk_068 > 180) {
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 3:
        func_08014A34(work->x, -0x800 + work->y + work->z);
        m4aSongNumStart(SONG_SND_718);
        FadeToAmount(0, gBtlWork->fadeAmount, 8);
        work->unk_00A += 1;
        work->unk_068 = 0;
    case 4:
        work->unk_068 += 1;
        if (work->unk_068 <= 39) {
            range = 0x600;
            d1 = (GetRandom() % 13 << 8) - range;
            work->unk_050 = d1;
            d2 = (GetRandom() % 13 << 8) - range;
            work->unk_058 = d2;
        } else {
            work->unk_050 = 0;
            work->unk_058 = 0;
        }
        if (work->unk_068 <= 199) {
            switch (work->unk_068) {
            case 40:
                for (i = 0; i < 8; i++) {
                    func_0810C32C(work, 5);
                }
                FadeStartOut(2, 4);
                m4aSongNumStart(SONG_SND_720);
                break;
            case 120:
            case 170:
            case 190:
                for (i = 0; i < 8; i++) {
                    func_0810C32C(work, 5);
                }
                FadeStartOut(2, 2);
                m4aSongNumStart(SONG_SND_720);
                break;
            case 44:
                FadeStartIn(2, 4);
                break;
            case 122:
            case 172:
            case 192:
                FadeStartIn(2, 2);
                break;
            }
        } else {
            for (i = 0; i < 80; i++) {
                func_0810C32C(work, 5);
            }
            FadeStartIn(2, 60);
            FadeLock();
            m4aSongNumStart(SONG_SND_719);
            gBtlWork->flags |= 0x400000;
            work->unk_002 = 1;
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 5:
        work->unk_068 += 1;
        if (work->unk_068 > 90) {
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 6:
    default:
        work->unk_068 += 1;
        if (work->unk_068 > 210) {
            func_0801B008();
            r = 0;
        }
        break;
    }
    return r;
}

u8 func_0810EF94(BosLstWork* work) {
    switch (work->unk_001) {
    case 0:
        work->x = func_0810CC14(work->x, 0x1D000, 0, 0x80, 0x200);
        work->y = func_0810CC14(work->y, 0x1F000, 0, 0x80, 0x200);
        work->z = func_0810CC14(work->z, -0x14400, 0, 0x80, 0x400);
        func_0810FF50(work->task, 4, work->unk_012);
        break;
    case 1:
        work->x = func_0810CC14(work->x, 0x15500, 0, 0x80, 0x200);
        work->y = func_0810CC14(work->y, 0x1F000, 0, 0x80, 0x200);
        work->z = func_0810CC14(work->z, -0x8400, 0, 0x80, 0x400);
        func_0810FF50(work->task, 0, work->unk_012);
        break;
    }
    func_0810C7C4(work);
    return 1;
}

void func_0810F064(BosLstWork* work, LstSub* p) {
    LstSpawn5 s;
    void* obj;
    u8 f;

    obj = &p->unk_018;
    if (p->unk_002 == 1) {
        p->anim.animId = 0xFFFF;
        p->unk_00C = -1;
        p->unk_002 = 0;
    }
    if (p->unk_00A == p->unk_00C) {
        switch (p->unk_00A) {
        case 3:
        case 4:
            break;
        default:
            if (AnimIsFinished(&p->anim) == 1) {
                if (p->unk_000 == 1) {
                    p->unk_00A = 2;
                } else {
                    p->unk_00A = 0;
                }
            }
            break;
        }
    }
    f = 1;
    switch (p->unk_00A) {
    case 1:
    case 3:
    case 4:
    case 6:
        f = 0;
        break;
    }
    if (work->unk_012 > 0) {
        if (p->unk_001 == 1) {
            AnimChangeWithTables(&p->anim, p->unk_00A * 2, f, gUnk_09EFAE1C, gUnk_09EFADC4);
        } else {
            AnimChangeWithTables(&p->anim, p->unk_00A * 2, f, gUnk_09EFAEAC, gUnk_09EFAE54);
        }
    } else {
        if (p->unk_001 == 1) {
            AnimChangeWithTables(&p->anim, p->unk_00A * 2 + 1, f, gUnk_09EFAEAC, gUnk_09EFAE54);
        } else {
            AnimChangeWithTables(&p->anim, p->unk_00A * 2 + 1, f, gUnk_09EFAE1C, gUnk_09EFADC4);
        }
    }
    p->unk_00C = p->unk_00A;
    AnimUpdate(&p->anim);
    switch (p->unk_00A) {
    default:
        func_0801C2DC(obj, 1);
        break;
    case 0:
        func_0801C2DC(obj, 0);
        break;
    case 2:
        func_0801C2DC(obj, 1);
        return;
    }
    switch (func_0801ADAC(obj)) {
    case 5:
        p->unk_004 = 1;
        p->timer = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->unk_07C = work->unk_07C * 3;
        work->unk_07C = work->unk_07C / 4;
        p->unk_008 = 20;
        work->unk_076 = 20;
        if (p->unk_004 == 5) {
            func_0801AF08(obj);
        } else {
            p->unk_004 = 3;
            p->timer = 0;
        }
        break;
    case 3:
        p->unk_004 = 4;
        p->timer = 0;
        p->unk_002 = 1;
        p->unk_00A = 6;
        s.unk_00 = p->unk_01C;
        s.unk_04 = p->unk_020;
        s.unk_08 = p->unk_024;
        s.unk_0C = work->unk_012;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstSnp, &s);
        break;
    case 4:
        p->unk_004 = 2;
        p->timer = 0;
        break;
    }
    switch (p->unk_004) {
    case 0:
        break;
    case 3:
        p->timer += 1;
        if (p->timer > 20) {
            func_0801AF08(obj);
            p->unk_004 = 0;
            p->timer = 0;
        }
        break;
    case 1:
    case 2:
    case 5:
        func_0801AF08(obj);
        p->unk_004 = 0;
        p->timer = 0;
        break;
    case 4:
        p->unk_000 = 1;
        p->unk_008 = 0;
        break;
    }
}

u8 task_bos_lst_1(BosLstWork* work) {
    s16 sx;
    s16 sy;
    u8 r;
    PcPos* obj;
    BtlObj* pos;
    PcPos* sub;
    LstSub* s;
    BtlWork** gp;
    s32 v;
    BtlObj* p2;
    s32 t;
    s32 y;
    s32 lim;
    s16 anim;
    s16 idx;
    s32 i;
    s32 k;
    s32 j;

    obj = (PcPos*)&work->unk_0E4;
    r = 1;
    work->unk_050 = work->unk_050 / 512;
    *(s32*)&work->unk_018 = (work->unk_110 * 255) / work->unk_112;
    gp = &gBtlWork;
    pos = (*gp)->actor;
    pos->flags |= 0x2000000;
    (*gp)->unk_0D8 = -16;
    if (work->unk_0D4 == 1) {
        y = func_0810D70C(work);
        p2 = (*gp)->actor;
        p2->y = y;
        if (((*gp)->flags & 0x2000000000000) == 0) {
            t = (work->unk_0DC * 70) >> 8;
            v = p2->x + t * work->unk_012;
            p2->x = v;
            if (work->unk_012 < 0) {
                lim = work->x - 0x2000;
                if (v > lim) {
                    p2->x = lim;
                }
            } else {
                lim = work->x + 0x2000;
                if (v < lim) {
                    p2->x = lim;
                }
            }
        }
    }
    anim = gUnk_09A4D0EC[work->unk_010] << 1;
    idx = 0;
    if (work->unk_012 < 0) {
        anim |= 1;
        idx = 1;
    }
    idx = (s16)idx;
    work->unk_026 -= 1;
    if (work->unk_026 < 0) {
        work->unk_026 = 0;
    }
    func_0801C2DC(&work->unk_0E4, 1);
    if (work->sub[0].unk_000 == 1 && work->sub[1].unk_000 == 1) {
        work->unk_006 = 1;
        if (work->unk_00C == 5) {
            if (work->unk_01C == 1) {
                func_0801C2DC(&work->unk_0E4, 0);
            }
        } else if (work->unk_026 > 0) {
            func_0801C2DC(&work->unk_0E4, 0);
        }
    } else {
        work->unk_006 = 0;
    }
    switch (func_0801ADAC(obj)) {
    case 5:
        work->unk_008 = 1;
        work->unk_00A = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->unk_07C = work->unk_07C * 3;
        work->unk_07C = work->unk_07C / 4;
        work->unk_076 = 20;
        func_0810C32C(work, 0);
        func_0810C32C(work, 0);
        func_0810C32C(work, 0);
        func_0810C32C(work, 0);
        work->unk_0DC += 0x80;
        func_0810C494(work, 1, 0, 0);
        if (work->unk_008 == 5) {
            func_0801AF08(obj);
        } else {
            work->unk_008 = 3;
        }
        break;
    case 3:
        work->unk_008 = 4;
        work->unk_00A = 0;
        work->unk_07A = 0;
        break;
    case 4:
        work->unk_008 = 2;
        work->unk_00A = 0;
        break;
    }
    switch (work->unk_008) {
    case 0:
        func_0810DB40(work);
        break;
    case 1:
        func_0810E844(work);
        break;
    case 3:
        func_0810E950(work);
        break;
    case 5:
        func_0810E984(work);
        break;
    case 2:
        func_0810E99C(work);
        break;
    case 4:
        r = func_0810EBA0(work);
        break;
    case 7:
        func_0810EF94(work);
        break;
    case 6:
    default:
        break;
    }
    func_0810F064(work, &work->sub[0]);
    func_0810F064(work, &work->sub[1]);
    obj->x = work->x + work->unk_050;
    obj->y = work->y + work->unk_054;
    obj->z = work->z + work->unk_058;
    k = idx;
    if (work->sub[k].unk_000 == 0) {
        sub = (PcPos*)work->sub[k].unk_018;
        sub->x = work->x + work->unk_050 + (gLstAnimDefs[anim].unk_12 << 8);
        sub->y = work->y + work->unk_054 + (gLstAnimDefs[anim].unk_14 << 8);
        sub->z = work->z + work->unk_058 + (gLstAnimDefs[anim].unk_16 << 8);
    }
    j = idx ^ 1;
    if (work->sub[j].unk_000 == 0) {
        s = &work->sub[j];
        sub = (PcPos*)s->unk_018;
        sub->x = work->x + work->unk_050 + (gLstAnimDefs[anim].unk_1E << 8);
        sub->y = work->y + work->unk_054 + (gLstAnimDefs[anim].unk_20 << 8);
        sub->z = work->z + work->unk_058 + (gLstAnimDefs[anim].unk_22 << 8);
    }
    ColliderSetPosition(obj->collider, obj->x + (work->unk_012 << 10), obj->y, obj->z);
    ColliderSetPosition(work->collider, obj->x, obj->y - 0x1000, obj->z + 0x1800);
    ColliderSetPosition(&work->unk_4D0, obj->x, obj->y - 0x1000, obj->z + 0x4000);
    for (i = 0; i < 8; i++) {
        ColliderSetPosition(work->unk_52C[i], work->x + ((i << 12) + 0x1800) * work->unk_012, work->y, work->z);
    }
    switch (work->unk_01E) {
    case 1:
        if (AnimIsFinished(&work->anim) == 1) {
            func_0810C494(work, 0, 1, 0);
        }
        break;
    case 2:
        if (AnimIsFinished(&work->anim) == 1) {
            work->unk_01C = 1;
            func_0810C494(work, 0, 1, 0);
        }
        break;
    }
    AnimUpdate(&work->anim);
    work->unk_010 += 1;
    work->unk_010 = (u32)work->unk_010 % 48;
    gBtlWork->unk_0CC = work->x;
    gBtlWork->unk_0D0 = work->y;
    gBtlWork->unk_0D4 = work->z;
    if (work->unk_008 != 4 && (work->unk_06C & 0xF) == 0) {
        WorldToScreen(&sx, &sy, work->x + work->unk_050, work->y + work->unk_054, work->z + work->unk_058);
        if (sy < -16) {
            func_0810C32C(work, 2);
        } else if (work->unk_0D4 == 1) {
            func_0810C32C(work, 3);
        } else {
            func_0810C32C(work, 0);
        }
    }
    work->unk_06C += 1;
    TaskPoolUpdate(&work->tasks);
    return r;
}

void task_bos_lst_2(BosLstWork* work) {
    s16 sx;
    s16 sy;
    u32 fill;
    s16 idx;
    vu32* dma;
    u32* src;
    LstSub* sub;
    s16 anim;
    s16 n;
    s32 k;
    s32 j;
    u16 v;
    u16 w;

    TaskPoolDraw(&work->tasks);
    anim = gUnk_09A4D0EC[work->unk_010] << 1;
    idx = 0;
    if (work->unk_012 < 0) {
        anim |= 1;
        idx = 1;
    }
    idx = (s16)idx;
    if (func_0801CA00(&work->unk_0E4) != 0 || func_0801CA00(work->sub[0].unk_018) != 0 ||
        func_0801CA00(work->sub[1].unk_018) != 0) {
        work->unk_014 = 1;
    } else {
        work->unk_014 = 0;
    }
    if ((s16)work->unk_014 != (s16)work->unk_016) {
        if ((s16)work->unk_014 == 0) {
            LoadPalette(gUnk_09D69454, (void*)0x05000000, 0x60);
            LoadPalette(gUnk_09D69594, (void*)(0x05000200 + ((((UnkStruct_080038C8*)work->palette)->index & 15) << 5)), 0x60);
        } else {
            LoadPalette(gUnk_08F69BC4, (void*)0x05000000, 32);
            LoadPalette(gUnk_08F69BC4, (void*)0x05000020, 32);
            LoadPalette(gUnk_08F69BC4, (void*)0x05000040, 32);
            LoadPalette(gUnk_08F69BC4, (void*)(0x05000200 + ((((UnkStruct_080038C8*)work->palette)->index & 15) << 5)), 32);
            LoadPalette(gUnk_08F69BC4, (void*)(0x05000220 + ((((UnkStruct_080038C8*)work->palette)->index & 15) << 5)), 32);
            LoadPalette(gUnk_08F69BC4, (void*)(0x05000240 + ((((UnkStruct_080038C8*)work->palette)->index & 15) << 5)), 32);
        }
        work->unk_016 = work->unk_014;
    }
    if (work->unk_002 == 1 || (work->unk_078 & 1)) {
        DisableBg(1);
        return;
    }
    WorldToScreen(&sx, &sy, work->x + work->unk_050 - (gLstAnimDefs[anim].unk_24 << 8),
                  work->y + work->unk_054 - (gLstAnimDefs[anim].unk_26 << 8),
                  work->z + work->unk_058 - (gLstAnimDefs[anim].unk_28 << 8));
    SetBgScroll(1, (u16)(-sx), (u16)(-sy));
    if ((u16)(sy + 255) > 0x19E || (u16)(sx + 255) > 0x1FE) {
        DisableBg(1);
    } else {
        if (work->unk_01C == 1) {
            n = 8;
        } else {
            switch (AnimGetGfxIndex(&work->anim)) {
            case 58:
                n = 1;
                break;
            case 59:
                n = 2;
                break;
            case 60:
                n = 3;
                break;
            case 61:
                n = 4;
                break;
            case 62:
                n = 5;
                break;
            case 63:
                n = 6;
                break;
            case 64:
                n = 7;
                break;
            case 28:
            case 29:
                n = 8;
                break;
            default:
                n = 0;
                break;
            }
        }
        if ((s16)work->unk_024 != n) {
            LoadBgTiles(1, gUnk_09A4D194[n][0], 0xC00);
            work->unk_024 = n;
        }
        if (work->unk_012 < 0) {
            n += 9;
        }
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (u32)gLstAnimDefs[anim].unk_00;
        dma[1] = (u32)work->unk_8A4;
        dma[2] = (DMA_ENABLE << 16) | 0x400;
        dma[2];
        src = gUnk_09A4D194[n][1];
        dma[0] = (u32)src;
        dma[1] = (u32)work->unk_8A4;
        dma[2] = (DMA_ENABLE << 16) | 0x140;
        dma[2];
        if (work->unk_012 > 0) {
            dma[0] = (u32)(src + 160);
            dma[1] = (u32)work->unk_B24;
        } else {
            dma[0] = (u32)(src + 169);
            dma[1] = (u32)work->unk_B48;
        }
        dma[2] = (DMA_ENABLE << 16) | 0xE;
        dma[2];
        if (sy < 0) {
            fill = 0;
            CpuFastSet(&fill, work->unk_8A4, ((((-sy) >> 3) << 4) & 0x1FFFFF) | 0x1000000);
        } else if (sy <= 159) {
            fill = 0;
            CpuFastSet(&fill, work->unk_8A4 + ((20 - (sy >> 3)) << 6), ((((sy >> 3) + 12) << 4) & 0x1FFFFF) | 0x1000000);
        }
        LoadBgMap(1, work->unk_8A4, 0x800);
    }
    WorldToScreen(&sx, &sy, work->x + work->unk_050, work->y + work->unk_054, work->z + work->unk_058);
    DrawSprite(sx + gLstAnimDefs[anim].unk_04, sy + gLstAnimDefs[anim].unk_06, AnimGetGfx(&work->anim), (void*)work->tiles, (void*)work->palette, 0,
               GetBattleSpritePriorityFlags(work->y + work->unk_054 + ((s16)gBtlWork->unk_0D8 << 8)),
               (u16)(-0x1004 - (((work->y + work->unk_054 + ((s16)gBtlWork->unk_0D8 << 8)) >> 8) << 2)));
    WorldToScreen(&sx, &sy, work->x + work->unk_050, work->y + work->unk_054, work->z + work->unk_058);
    k = idx;
    v = work->sub[k].unk_008;
    if (work->sub[k].unk_008 > 0) {
        work->sub[k].unk_008 = v - 1;
    }
    sub = &work->sub[k];
    DrawSprite(sx + gLstAnimDefs[anim].unk_0C, sy + gLstAnimDefs[anim].unk_0E, AnimGetGfx(&sub->anim), (void*)work->sub[0].tiles, (void*)work->palette, 0,
               GetBattleSpritePriorityFlags(work->y + work->unk_054),
               (u16)(-0x1004 - (((work->y + work->unk_054) >> 8) << 2)));
    j = idx ^ 1;
    w = work->sub[j].unk_008;
    if (work->sub[j].unk_008 > 0) {
        work->sub[j].unk_008 = w - 1;
    }
    sub = &work->sub[j];
    DrawSprite(sx + gLstAnimDefs[anim].unk_18, sy + gLstAnimDefs[anim].unk_1A, AnimGetGfx(&sub->anim), (void*)work->sub[1].tiles, (void*)work->palette, 0,
               GetBattleSpritePriorityFlags(work->y + work->unk_054 - 0x1100),
               (u16)(-0x1004 - (((work->y + work->unk_054 - 0x1100) >> 8) << 2)));
}

void task_bos_lst_3(BosLstWork* work) {
    s32 i;

    func_0801B7D8(&work->unk_0E4);
    func_0801B7D8(&work->sub[0].unk_018);
    func_0801B7D8(&work->sub[1].unk_018);
    ColliderUnregister(work->collider);
    ColliderUnregister(&work->unk_4D0);
    for (i = 0; i < 8; i++) {
        ColliderUnregister(work->unk_52C[i]);
    }
    func_0810C2F8(work);
    ReleaseObjTiles((void*)work->sub[0].tiles);
    ReleaseObjTiles((void*)work->sub[1].tiles);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    TaskPoolDestroy(&work->tasks);
}
