#include "macros.h"
#include "bos3.h"

u16 gUnk_0203C3BC COMMON;
u16 gUnk_0203C3C0 COMMON;

void task_bos_jf_shadow_0(JfShadowWork* work, UnkStruct_02039B84* obj) {
    work->unk_0C = obj;
    work->unk_00 = LoadObjTiles(gUnk_08B22EFE, 0x140);
    work->unk_08 = gUnk_08B22EE4;
    work->unk_04 = LoadObjPalette(gUnk_08F69BA4, 32);
}

s32 task_bos_jf_shadow_1(void) {
    return 1;
}

void task_bos_jf_shadow_2(JfShadowWork* work) {
    UnkStruct_02039B84* obj;
    s16 x;
    s16 y;
    s32 size;
    s32 flip;
    u16 frame;
    s32 sprite;

    obj = work->unk_0C;

    if (obj->unk_0CC == 0) {
        return;
    }

    if (obj->unk_034 & 0x402000000) {
        return;
    }

    frame = func_0801AF1C(obj->unk_008);

    if (obj->unk_00C >= 0 && gUnk_02039B84->unk_024 == 0x100) {
        sprite = 0;
    } else {
        size = 0x200 - ((obj->unk_010 - obj->unk_00C) / 128);

        if (size <= 127) {
            size = 128;
        }

        flip = 0;

        if (size > 0x100) {
            flip = 1;
        }

        sprite = AllocObjAffine(0, size, size, flip);
    }

    WorldToScreen(&x, &y, obj->unk_004, obj->unk_008, obj->unk_010);
    DrawSprite(x, y, work->unk_08, work->unk_00, work->unk_04, sprite, frame, obj->unk_0CC);
}

void task_bos_jf_shadow_3(JfShadowWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void func_080C6FF8(void) {
    gUnk_0203C3C0 = 0;
    gUnk_0203C3BC = 0;
}

void func_080C700C(u16* out) {
    out[0] = gUnk_0203C3C0;
    out[1] = gUnk_0203C3BC;
}

void func_080C7024(u16* in) {
    gUnk_0203C3C0 = in[0];
    gUnk_0203C3BC = in[1];
}
