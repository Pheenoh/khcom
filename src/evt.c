#include "macros.h"
#include "evt.h"

UnkStruct_02039DC8* gUnk_02039DC8;

void task_evt_obj_0(EvtObjWork* work, EvtObjParam* param) {
    EvtObjRes* res;

    res = param->unk_00;
    work->obj = param->unk_04;
    work->tiles = AllocObjTiles(res->unk_00 * 32, 0);
    work->palette = LoadObjPalette(res->unk_08, 32);
    AnimInit(&work->anim, 0, 0);
    work->obj->unk_18 = &work->anim;
    work->obj->unk_1C = work->palette[3];
    func_0801CE70(work);
    TaskPoolInit(&work->unk_24, 1);
    TaskCreate(&work->unk_24, gTaskDescEvtShadow, work->obj);
}

s32 task_evt_obj_1(EvtObjWork* work) {
    if (work->obj->flags & 1) {
        func_0801CE70(work);
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_24);

    return 1;
}

void task_evt_obj_2(EvtObjWork* work) {
    EvtObj* obj;
    u16 x;
    u16 y;
    void* gfx;

    obj = work->obj;

    if (obj->flags & 2) {
        return;
    }

    x = (obj->x >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (obj->y >> 8) + (obj->z >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, work->tiles, work->palette,
        AllocObjAffine(obj->unk_28, obj->unk_20, obj->unk_24, 1), obj->unk_16,
        (u16)(-0x1002 - (obj->y >> 8) * 4));
    TaskPoolDraw(&work->unk_24);
}

void task_evt_obj_3(EvtObjWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_24);
}

void task_evt_shadow_0(EvtShadowWork* work, EvtObj* obj) {
    work->obj = obj;
    work->unk_08 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->unk_10 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->unk_0C = LoadObjTiles(gUnk_08B22EFE, 0x140);
    work->palette = LoadObjPalette(gUnk_08F69BE4, 32);
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

    obj = work->obj;

    if (obj->flags & 4) {
        return;
    }

    if (obj->flags & 8) {
        gfx = gUnk_08B22EE4;
        vram = work->unk_0C;
    } else if (obj->flags & 0x10) {
        gfx = gUnk_08B22CBC;
        vram = work->unk_10;
    } else {
        gfx = gUnk_08B22BA8;
        vram = work->unk_08;
    }

    if (obj->z >= obj->unk_10) {
        sprite = 0;
    } else {
        size = 0x100 - (obj->unk_10 - obj->z) / 128;

        if (size <= 0x18) {
            size = 0x19;
        }

        sprite = AllocObjAffine(0, size, size, 0);
    }

    x = (obj->x >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (obj->y >> 8) + (obj->unk_10 >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    DrawSprite(x, y, gfx, vram, work->palette, sprite, obj->unk_16, 0xFFF0);
}

void task_evt_shadow_3(EvtShadowWork* work) {
    ReleaseObjTiles(work->unk_08);
    ReleaseObjTiles(work->unk_0C);
    ReleaseObjTiles(work->unk_10);
    ReleaseObjPalette(work->palette);
}

ALIGN_ZERO(2);
