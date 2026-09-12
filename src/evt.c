#include "macros.h"
#include "evt.h"
#include "evt_api.h"

UnkStruct_02039DC8* gUnk_02039DC8;

void func_0801CD74(EvtObj* obj, s32 anim) {
    u16 t = obj->flags | 1;

    obj->flags = t;
    obj->unk_00 = (s32)&gUnk_0813766C[anim];
}

void EvtObjSetPos(EvtObj* obj, s32 a, s32 b, s32 c) {
    obj->x = a;
    obj->y = b;
    obj->z = c;
}

void func_0801CD94(EvtObj* obj, s32 a) {
    obj->unk_10 = a;
}

void func_0801CD98(void* pool, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c) {
    EvtObjParam param;

    param.unk_00 = &gUnk_0813B09C[res].unk_00;
    param.unk_04 = obj;
    func_0801CD74(obj, anim);
    EvtObjSetPos(obj, a, b, c);
    obj->flags = 0;
    obj->unk_10 = 0;
    obj->unk_16 = 0x800;
    obj->unk_24 = 0x100;
    obj->unk_20 = 0x100;
    obj->unk_28 = 0;
    TaskCreate(pool, gTaskDescEvtObj, &param);
}

void func_0801CE00(EvtObj* obj, u16 a) {
    obj->unk_16 = a;
}

s32 func_0801CE04(void* pool, void* desc, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c) {
    EvtObjParam param;

    param.unk_00 = &gUnk_0813B09C[res].unk_00;
    param.unk_04 = obj;
    func_0801CD74(obj, anim);
    EvtObjSetPos(obj, a, b, c);
    obj->flags = 0;
    obj->unk_10 = 0;
    obj->unk_16 = 0x800;
    obj->unk_24 = 0x100;
    obj->unk_20 = 0x100;
    obj->unk_28 = 0;
    TaskCreate(pool, desc, &param);
}

void func_0801CE70(EvtObjWork* work) {
    EvtObj* obj;
    EvtObjAnim* anim;
    EvtAnimDef* def;

    obj = work->obj;
    anim = (EvtObjAnim*)obj->unk_00;
    def = anim->unk_00;
    AnimChangeWithTables(&work->anim, anim->unk_0C, anim->unk_0E, def->unk_04, def->unk_00);
    SetObjTileSource(work->tiles, def->unk_08);
    work->obj->flags &= 0xFFFE;
}

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
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->tiles3 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->tiles2 = LoadObjTiles(gUnk_08B22EFE, 0x140);
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
        vram = work->tiles2;
    } else if (obj->flags & 0x10) {
        gfx = gUnk_08B22CBC;
        vram = work->tiles3;
    } else {
        gfx = gUnk_08B22BA8;
        vram = work->tiles;
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
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjTiles(work->tiles3);
    ReleaseObjPalette(work->palette);
}

ALIGN_ZERO(2);
