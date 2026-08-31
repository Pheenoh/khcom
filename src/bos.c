#include "macros.h"
#include "bos.h"

void task_bos_map_0(s32 unused, BosMapConfig* cfg) {
    func_080050B8(0, cfg->unk_00, cfg->unk_04);
    func_080050DC(0, cfg->unk_08, cfg->unk_0C);
    func_0800516C(0, cfg->unk_10, 2, 2);

    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0x10000;
    gUnk_02039B84->unk_00C = 0x14000;
    gUnk_02039B84->unk_000 = 0x10000;
    gUnk_02039B84->unk_004 = 0x14000;
    gUnk_02039B84->unk_010 = 0x10000;
    gUnk_02039B84->unk_014 = 0x14000;
    gUnk_02039B84->unk_01C = 0x10000;
    gUnk_02039B84->unk_020 = 0x14000;
    gUnk_02039B84->unk_01A = 15;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();

    func_08005244(0, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
}

s32 task_bos_map_1(void) {
    s32 dx;
    s32 dy;
    s32 y;

    func_0802F208();

    dx = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
    dy = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gUnk_02039B84->unk_008 += dx;
    gUnk_02039B84->unk_00C += dy;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;

    if (gUnk_02039B84->unk_000 - 0x7800 < (gUnk_02039B84->unk_0DA << 8)) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 0x78) << 8;
    } else if (gUnk_02039B84->unk_000 + 0x7800 > (gUnk_02039B84->unk_0DC << 8)) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 0x78) << 8;
    }

    if (gUnk_02039B84->unk_004 + 0x5000 < (gUnk_02039B84->unk_0DE << 8)) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0DE - 0x50) << 8;
    } else if (gUnk_02039B84->unk_004 + 0x5000 > (gUnk_02039B84->unk_0E0 << 8)) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0E0 - 0x50) << 8;
    }

    y = gUnk_02039B84->unk_004 + func_0802F268();
    gUnk_02039B84->unk_004 = y;
    func_08005244(0, (gUnk_02039B84->unk_000 >> 8) + 8, (y >> 8) + 0x28);

    return 1;
}

void task_bos_shadow_0(BosShadowWork* work, UnkStruct_02039B84* obj) {
    work->unk_08 = obj;
    work->unk_00 = func_080026A4(gUnk_08B22BBC, 0x100);
    work->unk_04 = func_08002A14(gUnk_08F69BA4, 32);
}

s32 task_bos_shadow_1(void) {
    return 1;
}

void task_bos_shadow_2(BosShadowWork* work) {
    UnkStruct_02039B84* obj;
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

    sprite = func_08002CB4(0, size, size, flip);
    func_0801909C(&x, &y, obj->unk_004, obj->unk_008, obj->unk_010);
    func_080023E0(x, y, gfx, work->unk_00, work->unk_04, sprite, frame, 0xFFF0);
}

void task_bos_shadow_3(BosShadowWork* work) {
    func_080028C0(work->unk_00);
    func_08002C10(work->unk_04);
}

ALIGN_ZERO(2);
