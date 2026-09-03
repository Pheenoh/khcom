#include "task.h"

u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    u8 angle;

    dx = x1 - x0;
    dy = y1 - y0;
    angle = 0;

    if (dx == 0 && dy == 0) {
        angle = 0;
    } else if (dx > 0 && dy < 0) {
        dy = -dy;

        if (dx <= dy) {
            angle = ((0x200000 / dy) * dx) >> 16;
        } else {
            angle = 0x40 - (((0x200000 / dx) * dy) >> 16);
        }
    } else if (dx > 0 && dy > 0) {
        if (dx <= dy) {
            angle = 0x7F - (((0x200000 / dy) * dx) >> 16);
        } else {
            angle = (((0x200000 / dx) * dy) >> 16) + 0x3F;
        }
    } else if (dx < 0 && dy > 0) {
        dx = -dx;

        if (dx <= dy) {
            angle = (((0x200000 / dy) * dx) >> 16) - 0x80;
        } else {
            angle = -0x40 - (((0x200000 / dx) * dy) >> 16);
        }
    } else if (dx < 0 && dy < 0) {
        dx = -dx;
        dy = -dy;

        if (dx <= dy) {
            angle = -1 - (((0x200000 / dy) * dx) >> 16);
        } else {
            angle = (((0x200000 / dx) * dy) >> 16) - 0x41;
        }
    } else if (dx == 0 && dy < 0) {
        angle = 0;
    } else if (dx == 0 && dy > 0) {
        angle = 0x80;
    } else if (dx < 0 && dy == 0) {
        angle = 0xC0;
    } else if (dx > 0 && dy == 0) {
        angle = 0x40;
    }

    return angle;
}

void UpdatePlayTime(void) {
    if (gFrameCounter % 60 == 0) {
        if (gUnk_02039BB0.playTime <= 0x57E3E) {
            gUnk_02039BB0.playTime++;
        }
    }
}

void func_0801CCB4(void) {
    func_080DFAF4(0, 0);
    gUnk_02039BB0.unk_17A = 0xE7FF;
    gUnk_02039BB0.unk_17C = 0x80;
    _08085D04(0);
    gUnk_02039BB0.flags |= 8;
    gUnk_02039BB0.flags |= 0x100;
    func_0800FDD0(0);
    func_0800FDD0(0x15);
    func_0800FDD0(0xED);
    func_0800FDD0(0x11);
    func_0800FDD0(0x16);
    func_0800FDD0(0xEF);
    func_0800FDD0(0xF3);
}

void func_0801CD20(void) {
    gUnk_02039BB0.unk_17C = 3;
    func_08085C3C();
    gUnk_02039BB0.flags &= ~8;
    func_0800FDD0(0x11);
    func_0800FDD0(0x12);
    func_0800FDD0(0x13);
    func_0800FDD0(0x14);
    func_0800FDD0(0x15);
    func_0800FDD0(0x16);
    func_080DFAF4(0, 10);
}

void func_0801CD74(EvtObj* obj, s32 anim) {
    u16 t = obj->unk_14 | 1;

    obj->unk_14 = t;
    obj->unk_00 = (s32)&gUnk_0813766C[anim];
}

void func_0801CD8C(EvtObj* obj, s32 a, s32 b, s32 c) {
    obj->unk_04 = a;
    obj->unk_08 = b;
    obj->unk_0C = c;
}

void func_0801CD94(EvtObj* obj, s32 a) {
    obj->unk_10 = a;
}

void func_0801CD98(void* pool, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c) {
    EvtObjParam param;

    param.unk_00 = &gUnk_0813B09C[res].unk_00;
    param.unk_04 = obj;
    func_0801CD74(obj, anim);
    func_0801CD8C(obj, a, b, c);
    obj->unk_14 = 0;
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
    func_0801CD8C(obj, a, b, c);
    obj->unk_14 = 0;
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

    obj = work->unk_00;
    anim = (EvtObjAnim*)obj->unk_00;
    def = anim->unk_00;
    func_08005974(&work->unk_0C, anim->unk_0C, anim->unk_0E, def->unk_04, def->unk_00);
    func_08002A10(work->unk_04, def->unk_08);
    work->unk_00->unk_14 &= 0xFFFE;
}
