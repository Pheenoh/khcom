#include "macros.h"
#include "evt.h"

void task_evt_obj_0(EvtObjWork* work, EvtObjParam* param) {
    EvtObjRes* res;

    res = param->unk_00;
    work->unk_00 = param->unk_04;
    work->unk_04 = func_080028F8(res->unk_00 * 32, 0);
    work->unk_08 = func_08002A14(res->unk_08, 32);
    func_08005968(&work->unk_0C, 0, 0);
    work->unk_00->unk_18 = &work->unk_0C;
    work->unk_00->unk_1C = work->unk_08[3];
    func_0801CE70(work);
    func_08000E64(&work->unk_24, 1);
    func_08000E14(&work->unk_24, gUnk_09EDADE0, work->unk_00);
}

s32 task_evt_obj_1(EvtObjWork* work) {
    if (work->unk_00->unk_14 & 1) {
        func_0801CE70(work);
    }

    func_08005A64(&work->unk_0C);
    func_08000EA4(&work->unk_24);

    return 1;
}

void task_evt_obj_2(EvtObjWork* work) {
    EvtObj* obj;
    u16 x;
    u16 y;
    void* gfx;

    obj = work->unk_00;

    if (obj->unk_14 & 2) {
        return;
    }

    x = (obj->unk_04 >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (obj->unk_08 >> 8) + (obj->unk_0C >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    gfx = func_08005AFC(&work->unk_0C);
    func_080023E0(x, y, gfx, work->unk_04, work->unk_08,
        func_08002CB4(obj->unk_28, obj->unk_20, obj->unk_24, 1), obj->unk_16,
        (u16)(-0x1002 - (obj->unk_08 >> 8) * 4));
    func_08000EE0(&work->unk_24);
}

void task_evt_obj_3(EvtObjWork* work) {
    func_080028C0(work->unk_04);
    func_08002C10(work->unk_08);
    func_08000F0C(&work->unk_24);
}

void task_evt_shadow_0(EvtShadowWork* work, EvtObj* obj) {
    work->unk_04 = obj;
    work->unk_08 = func_080026A4(gUnk_08B22BBC, 0x100);
    work->unk_10 = func_080026A4(gUnk_08B22CE4, 0x200);
    work->unk_0C = func_080026A4(gUnk_08B22EFE, 0x140);
    work->unk_00 = func_08002A14(gUnk_08F69BE4, 32);
}

s32 task_evt_shadow_1(void) {
    return 1;
}

void task_evt_shadow_2(EvtShadowWork* work) {
    EvtObj* obj;
    u8* gfx;
    void* vram;
    s32 size;
    s32 sprite;
    s32 x;
    s32 y;

    obj = work->unk_04;

    if (obj->unk_14 & 4) {
        return;
    }

    if (obj->unk_14 & 8) {
        gfx = gUnk_08B22EE4;
        vram = work->unk_0C;
    } else if (obj->unk_14 & 0x10) {
        gfx = gUnk_08B22CBC;
        vram = work->unk_10;
    } else {
        gfx = gUnk_08B22BA8;
        vram = work->unk_08;
    }

    if (obj->unk_0C >= obj->unk_10) {
        sprite = 0;
    } else {
        size = 0x100 - (obj->unk_10 - obj->unk_0C) / 128;

        if (size <= 0x18) {
            size = 0x19;
        }

        sprite = func_08002CB4(0, size, size, 0);
    }

    x = (obj->unk_04 >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (obj->unk_08 >> 8) + (obj->unk_10 >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    func_080023E0(x, y, gfx, vram, work->unk_00, sprite, obj->unk_16, 0xFFF0);
}

void task_evt_shadow_3(EvtShadowWork* work) {
    func_080028C0(work->unk_08);
    func_080028C0(work->unk_0C);
    func_080028C0(work->unk_10);
    func_08002C10(work->unk_00);
}

ALIGN_ZERO(2);
