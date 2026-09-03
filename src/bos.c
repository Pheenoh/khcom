#include "macros.h"
#include "bos.h"

void task_bos_map_0(s32 unused, BosMapConfig* cfg) {
    LoadBgTiles(0, cfg->tiles, cfg->tilesSize);
    LoadBgPalette(0, cfg->palette, cfg->paletteSize);
    func_0800516C(0, cfg->unk_10, 2, 2);

    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->unk_008 = 0x10000;
    gBtlWork->unk_00C = 0x14000;
    gBtlWork->unk_000 = 0x10000;
    gBtlWork->unk_004 = 0x14000;
    gBtlWork->unk_010 = 0x10000;
    gBtlWork->unk_014 = 0x14000;
    gBtlWork->unk_01C = 0x10000;
    gBtlWork->unk_020 = 0x14000;
    gBtlWork->unk_01A = 15;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();

    func_08005244(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}

s32 task_bos_map_1(void) {
    s32 dx;
    s32 dy;
    s32 y;

    func_0802F208();

    dx = (gBtlWork->unk_010 - gBtlWork->unk_008) >> 3;
    dy = (gBtlWork->unk_014 - gBtlWork->unk_00C) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->unk_008 += dx;
    gBtlWork->unk_00C += dy;
    gBtlWork->unk_000 = gBtlWork->unk_008;
    gBtlWork->unk_004 = gBtlWork->unk_00C;

    if (gBtlWork->unk_000 - 0x7800 < (gBtlWork->unk_0DA << 8)) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x78) << 8;
    } else if (gBtlWork->unk_000 + 0x7800 > (gBtlWork->unk_0DC << 8)) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x78) << 8;
    }

    if (gBtlWork->unk_004 + 0x5000 < (gBtlWork->unk_0DE << 8)) {
        gBtlWork->unk_004 = (gBtlWork->unk_0DE - 0x50) << 8;
    } else if (gBtlWork->unk_004 + 0x5000 > (gBtlWork->unk_0E0 << 8)) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 0x50) << 8;
    }

    y = gBtlWork->unk_004 + func_0802F268();
    gBtlWork->unk_004 = y;
    func_08005244(0, (gBtlWork->unk_000 >> 8) + 8, (y >> 8) + 0x28);

    return 1;
}

void task_bos_shadow_0(BosShadowWork* work, BtlWork* obj) {
    work->unk_08 = obj;
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
}

s32 task_bos_shadow_1(void) {
    return 1;
}

void task_bos_shadow_2(BosShadowWork* work) {
    BtlWork* obj;
    s16 x;
    s16 y;
    s32 size;
    s32 flip;
    u16 frame;
    s32 sprite;
    u8* gfx;

    obj = work->unk_08;
    flip = 0;
    gfx = gUnk_08B22BA8;
    frame = func_0801AF1C(obj->unk_008);
    size = 0x100 - ((obj->unk_010 - obj->unk_00C) >> 7);

    if (size <= 0xB2) {
        size = 0xB3;
    }

    if (work->unk_08->unk_034 & 0x20000) {
        size += 0x100;
        flip = 1;
    }

    sprite = AllocObjAffine(0, size, size, flip);
    WorldToScreen(&x, &y, obj->unk_004, obj->unk_008, obj->unk_010);
    DrawSprite(x, y, gfx, work->tiles, work->palette, sprite, frame, 0xFFF0);
}

void task_bos_shadow_3(BosShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

ALIGN_ZERO(2);
