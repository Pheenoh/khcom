#include "bos6.h"
#include "sprites_bos6.h"
#include "sprites_staff_roll.h"

static u8 gUnk_02036008;
static s16 gUnk_0203600A;
static s16 gUnk_0203600C;
static s32 gUnk_02036010;

const s8 gUnk_09A4CA94[33] = {
    4, 4, 4, 4, -4, -4, -4, -4, 3, 3, 3, 3, -3, -3, -3, -3, 2, 2, 2, 2, -2, -2, -2, -2, 1, 1, 1, 1, -1, -1, -1, -1, 0,
};

const s8 gUnk_09A4CAB5[9] = {
    1, 2, 2, 1, -1, -2, -2, -1, 0,
};

const u16 gUnk_09A4CABE[3] = {
    1, 2, 0,
};

const s16 gUnk_09A4CAC4[3] = {
    6, 6, 6,
};

const s8* gUnk_09EF9E04[2] = { gUnk_09A4CA94, gUnk_09A4CAB5 };

TaskDesc gTaskDescBosPcFld = {
    "task_bos_pc_fld",
    (TaskInitFunc)task_bos_pc_fld_0,
    (TaskUpdateFunc)task_bos_pc_fld_1,
    (TaskFunc)task_bos_pc_fld_2,
    (TaskFunc)task_bos_pc_fld_3,
    0x6C,
};

static s32 Square(s32 x) {
    return x * x;
}

void func_0810B370(u8** p, u8 v) {
    p[1][0] = v;
}

void func_0810B378(void** p, u8 a) {
    PcFldWork* work;
    UnkStruct_080038C8* pal;

    work = (PcFldWork*)p[1];
    if (a == 1) {
        a = 0;
    } else {
        a = 1;
    }
    ColliderSetDisabled(&work->collider, a);
    if (a == 0) {
        if (work->tiles == 0) {
            work->tiles = (u32)LoadObjTiles(gUnk_09CC4E54, 0x200);
        }
        if (work->palette == 0) {
            pal = (UnkStruct_080038C8*)LoadObjPalette(gUnk_09D693D4, 0x60);
            work->palette = (u32)pal;
            LoadPalette(gUnk_09D69434, gUnk_05000220 + pal->index * 32, 32);
        }
    }
}

void func_0810B3E4(void) {
    gUnk_02036008 = 0;
    gUnk_0203600A = 0;
    gUnk_0203600C = 0;
    gUnk_02036010 = 0;
}

void func_0810B40C(s16 a) {
    gUnk_02036008 = 1;
    gUnk_0203600A = a;
    gUnk_0203600C = 0;
    gUnk_02036010 = 0;
}

void func_0810B434(void) {
    const s8* p;

    if (gUnk_02036008 != 0) {
        p = gUnk_09EF9E04[gUnk_0203600A];
        gUnk_02036010 += ((p[gUnk_0203600C] << 12) - gUnk_02036010) >> 3;
        gUnk_0203600C += 1;
        if (p[gUnk_0203600C] == 0) {
            gUnk_02036008 = 0;
            gUnk_02036010 = 0;
        }
    }
}

s32 func_0810B49C(void) {
    return gUnk_02036010;
}

void func_0810B4A8(u8* p) {
    u16 zero;

    zero = 0;
    *(u8*)(p + 0) = zero;
    *(u16*)(p + 2) = zero;
    *(u16*)(p + 4) = zero;
}

void func_0810B4B4(u8* p) {
    u16 t;
    u16 zero;

    if (p[0] != 0) {
        if (*(s16*)(p + 4) > gUnk_09A4CAC4[*(s16*)(p + 2)]) {
            t = gUnk_09A4CABE[*(s16*)(p + 2)];
            zero = 0;
            *(u16*)(p + 2) = t;
            *(u16*)(p + 4) = zero;
        }
        *(u16*)(p + 4) += 1;
    }
}

void func_0810B4F4(u8* p) {
    if (p[0] != 0) {
        LoadPalette(gUnk_09D69374 + *(s16*)(p + 2) * 32, gUnk_05000080, 32);
    }
}

void func_0810B51C(u8* p) {
    *p = 0;
}

void task_bos_pc_fld_0(PcFldWork* work, BattleBackgroundDef* arg) {
    void* p;

    LoadBgTiles(0, arg->tiles, arg->tilesSize);
    LoadBgPalette(0, arg->palette, arg->paletteSize);
    SetBgMapBlocks(0, &arg->map, 2, 3);
    gBtlWork->scale = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0x11400;
    gBtlWork->y = 0x15300;
    gBtlWork->unk_000 = 0x11400;
    gBtlWork->unk_004 = 0x15300;
    gBtlWork->x2 = 0x11400;
    gBtlWork->y2 = 0x15300;
    gBtlWork->unk_01C = 0x11400;
    gBtlWork->unk_020 = 0x15300;
    gBtlWork->unk_01A = 15;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    func_0810B3E4();
    ScrollBgMapTo(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
    func_0810B4A8((u8*)work);
    func_0810B4B4((u8*)work);
    work->tiles = 0;
    work->palette = 0;
    p = &work->collider;
    ColliderInit(p, 6, 40, 8);
    ColliderSetPosition(p, 0x17400, 0x15400, 0);
    ColliderSetDisabled(p, 1);
}

u8 task_bos_pc_fld_1(PcFldWork* work) {
    s32 t;
    s32 u;
    s32 dx;
    s32 dy;
    BtlObj* pos;

    func_0802F208();
    func_0810B434();
    pos = gBtlWork->actor;
    u = gBtlWork->unk_000 - 0x7800;
    t = pos->x - u;
    if (t < 0) {
        t = 0;
    }
    gBtlWork->x2 = t / 2 + 0xF000;
    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;
    if (dx > 0x500) {
        dx += 0x500;
    } else if (dx < -0x500) {
        dx -= 0x500;
    }
    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;
    if (gBtlWork->unk_000 - 0x7800 < gBtlWork->unk_0DA * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 120) * 256;
    } else if (gBtlWork->unk_000 + 0x7800 > gBtlWork->unk_0DC * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 120) * 256;
    }
    if (gBtlWork->unk_004 + 0x3000 < gBtlWork->unk_0DE * 256) {
        gBtlWork->unk_004 = (gBtlWork->unk_0DE - 48) * 256;
    } else if (gBtlWork->unk_004 + 0x5000 > gBtlWork->unk_0E0 * 256) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 80) * 256;
    }
    gBtlWork->unk_004 += func_0802F268();
    gBtlWork->unk_004 += func_0810B49C();
    ScrollBgMapTo(0, (gBtlWork->unk_000 >> 8) + 8, (gBtlWork->unk_004 >> 8) + 40);
    func_0810B4B4((u8*)work);
    return 1;
}

void task_bos_pc_fld_2(PcFldWork* work) {
    s16 sx;
    s16 sy;
    BtlObj* pos;
    u32 x;
    u32 y;
    s32 z;

    func_0810B4F4((u8*)work);
    pos = gBtlWork->actor;
    if (pos->z >= -0x100) {
        if ((pos->flags & 0x80) == 0) {
            if (work->tiles != 0) {
                if (work->palette != 0) {
                    x = 0x17000;
                    y = 0x14800;
                    z = -0x800;
                    WorldToScreen(&sx, &sy, x, y, z);
                    DrawSprite(sx, sy, gUnk_09EFBEB8, (void*)work->tiles,
                        (void*)work->palette, 0, GetBattleSpritePriorityFlags(y),
                        (u16)(-0x1004 - (s32)(y >> 6)));
                }
            }
        }
    }
}

void task_bos_pc_fld_3(PcFldWork* work) {
    func_0810B51C((u8*)work);
    ColliderUnregister(&work->collider);

    if (work->tiles != 0) {
        ReleaseObjTiles((void*)work->tiles);
    }

    if (work->palette != 0) {
        ReleaseObjPalette((void*)work->palette);
    }
}
