#include "bos6.h"
#include "sprites_bos6.h"

const s16 gUnk_09A4CADC[256] = {
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92,
    97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176,
    181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234,
    236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255,
    256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185,
    181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103,
    97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92,
    -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176,
    -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255,
    -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238,
    -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185,
    -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103,
    -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6,
};

const s16 gUnk_09A4CCDC[256] = {
    256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185,
    181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103,
    97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92,
    -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176,
    -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255,
    -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238,
    -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185,
    -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103,
    -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6,
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92,
    97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176,
    181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234,
    236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255,
};

const UnkStruct_09A4CEDC gUnk_09A4CEDC[12] = {
    { -16, -16, 0, 0 },
    { -16, 0, 24, 11 },
    { -16, 2, 24, 13 },
    { -16, 4, 21, 14 },
    { -16, 6, 16, 15 },
    { -16, 7, 12, 0 },
    { -10, 3, 16, 17 },
    { -10, 4, 16, 18 },
    { -10, 5, 14, 19 },
    { -10, 6, 12, 20 },
    { -10, 7, 8, 0 },
    { -16, 1, 24, 12 },
};

TaskDesc gTaskDescBosPcFlt = {
    "task_bos_pc_flt",
    (TaskInitFunc)task_bos_pc_flt_0,
    (TaskUpdateFunc)task_bos_pc_flt_1,
    (TaskFunc)task_bos_pc_flt_2,
    (TaskFunc)task_bos_pc_flt_3,
    0xB4,
};

s32 func_0810B7D8(s32 x) {
    return x * x;
}

s32 func_0810B7E0(s32 x) {
    return x * x;
}

void func_0810B7E8(void** p, s32* a, s32* b, s32* c) {
    PcFltWork* work;

    work = (PcFltWork*)p[1];
    *a = work->x;
    *b = work->y;
    *c = work->z;
}

u8 func_0810B800(void** p) {
    PcFltWork* work;

    work = (PcFltWork*)p[1];
    if (work->unk_005 == 8 && AnimGetGfxIndex(&work->anim) == 0) {
        return 1;
    }
    return 0;
}

u8 func_0810B824(void** p) {
    PcFltWork* work;
    u8 r;

    work = (PcFltWork*)p[1];
    r = 0;
    if (func_0801BCA8(&work->collider) == 1) {
        r = 1;
    }
    return r;
}

void func_0810B844(PcFltWork* work) {
    AnimState* anim;

    work->z = work->unk_024;
    if (work->pos->unk_02 == 0) {
        if (func_0801BCA8(&work->collider) == 1) {
            work->z += 0x200;
            if (work->unk_000 != 1) {
                work->unk_000 = 1;
                AnimChange(&work->anim, 8, 0);
            }
            work->unk_018 -= 2;
            if (work->unk_018 < 0) {
                work->unk_005 = 1;
                work->unk_000 = 0;
                work->timer = 0;
                work->unk_018 = 360;
                AnimChange(&work->anim, 7, 0);
            }
        } else {
            if (work->unk_000 == 1) {
                work->unk_018 -= 120;
                AnimChange(&work->anim, 1, 0);
            } else {
                work->unk_018 += 1;
                if (work->unk_018 > 720) {
                    work->unk_018 = 720;
                }
            }
            work->unk_000 = 0;
        }
    } else {
        work->unk_005 = 5;
        work->unk_000 = 0;
        work->timer = 0;
        AnimChange(&work->anim, 5, 0);
    }
}

void func_0810B8F8(PcFltWork* work) {
    AnimState* anim;

    work->z = work->unk_024;
    anim = &work->anim;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 2;
        work->timer = 0;
        AnimReset(anim);
        AnimChange(anim, 3, 0);
    }
}

void func_0810B930(PcFltWork* work) {
    work->z = work->unk_024;
    if (AnimIsFinished(&work->anim) == 1) {
        work->unk_005 = 3;
        work->unk_000 = 0;
        work->timer = 60;
    }
}

void func_0810B95C(PcFltWork* work) {
    work->z = work->unk_024 + 0x1000;
    work->timer -= 1;
    if (work->timer < 0) {
        if (work->pos->unk_02 == 0) {
            work->unk_005 = 4;
            work->timer = 0;
            AnimChange(&work->anim, 4, 0);
        } else {
            work->unk_005 = 6;
            work->timer = 0;
            AnimChange(&work->anim, 9, 0);
        }
    }
}

void func_0810B9A8(PcFltWork* work) {
    AnimState* anim;

    work->z = work->unk_024;
    anim = &work->anim;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 0;
        AnimReset(anim);
        AnimChange(anim, 1, 0);
    }
}

void func_0810B9DC(PcFltWork* work) {
    AnimState* anim;

    work->z = work->unk_024;
    anim = &work->anim;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 6;
        work->timer = 0;
        AnimReset(anim);
        AnimChange(anim, 2, 0);
    }
}

void func_0810BA14(PcFltWork* work) {
    work->z = work->unk_024;
    if (work->pos->unk_02 == 0) {
        work->unk_005 = 7;
        work->timer = 0;
        AnimChange(&work->anim, 6, 0);
    }
}

void func_0810BA3C(PcFltWork* work) {
    AnimState* anim;

    work->z = work->unk_024;
    anim = &work->anim;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 0;
        work->timer = 0;
        AnimReset(anim);
        AnimChange(anim, 1, 0);
    }
}

void func_0810BA74(PcFltWork* work) {
    AnimState* anim;
    u8 fin;
    u16 id;

    work->z = work->unk_024;
    if (work->timer == 0) {
        anim = &work->anim;
        fin = AnimIsFinished(anim);
        if (fin == 1) {
            id = AnimGetGfxIndex(anim);
            if (id != 0) {
                AnimReset(anim);
                AnimChange(anim, gUnk_09A4CEDC[id].unk_06, 0);
            } else {
                work->timer = 1;
            }
        }
    } else if (work->pos->z <= 119) {
        work->unk_005 = 3;
        work->unk_000 = 0;
        work->timer = work->unk_004 * 30;
    }
}

void func_0810BAE4(PcFltWork* work) {
    s32 f;

    if ((gBtlWork->flags & 0x20000000) || (gBtlWork->flags & 0x40) ||
        work->pos->y > 0) {
        f = -1;
    } else {
        f = work->unk_007;
    }
    if (work->unk_005 != 8 && work->pos->z > 0x257) {
        work->unk_005 = 8;
        work->unk_000 = 0;
        work->timer = 0;
        work->unk_018 = 360;
    }
    if (work->pos->unk_02 == 0) {
        if (work->unk_00C > 0xF400) {
            work->unk_00C -= 32;
        }
        if (work->unk_010 > 0x15400) {
            work->unk_010 -= 32;
        }
        if (work->unk_014 <= 0x3FFF) {
            work->unk_014 += 64;
        }
        if (work->unk_016 <= 0x1FFF) {
            work->unk_016 += 32;
        }
    } else {
        if (work->unk_00C <= 0x103FF) {
            work->unk_00C += 32;
        }
        if (work->unk_010 <= 0x153FF) {
            work->unk_010 += 32;
        }
        if (work->unk_014 > 0x3400) {
            work->unk_014 -= 64;
        }
        if (work->unk_016 > 0x1E00) {
            work->unk_016 -= 32;
        }
    }
    if (f >= 0) {
        work->x = (((gUnk_09A4CCDC[work->unk_008 >> 8] * (work->unk_014 >> 8)) >> 8) + (work->unk_00C >> 8)) << 8;
        work->y = (((gUnk_09A4CADC[work->unk_008 >> 8] * (work->unk_016 >> 8)) >> 8) + (work->unk_010 >> 8)) << 8;
        work->unk_008 = work->unk_008 - (((work->pos->unk_00 * 3) << 4) / 256 - 112);
    }
    switch (work->unk_005) {
    case 0:
        func_0810B844(work);
        break;
    case 1:
        func_0810B8F8(work);
        break;
    case 2:
        func_0810B930(work);
        break;
    case 3:
        func_0810B95C(work);
        break;
    case 4:
        func_0810B9A8(work);
        break;
    case 5:
        func_0810B9DC(work);
        break;
    case 6:
        func_0810BA14(work);
        break;
    case 7:
        func_0810BA3C(work);
        break;
    case 8:
        func_0810BA74(work);
        break;
    }
    if (func_0801BCA8(&work->collider) == 1) {
        work->unk_000 = 1;
    }
}

void func_0810BCD4(PcFltWork* work) {
    void* p;

    p = &work->collider;
    ColliderSetPosition(p, work->x, work->y + 0x200, 0);
    ColliderSetHeight(p, -work->z >> 8);
    if (work->z > 0) {
        ColliderSetDisabled(p, 1);
    } else {
        ColliderSetDisabled(p, 0);
    }
}

void task_bos_pc_flt_0(PcFltWork* work, PcFltInit* arg) {
    AnimState* anim;

    work->tiles = (u32)LoadObjTiles(gUnk_09CB8F54, 0xDC0);
    work->palette = (u32)LoadObjPalette(gUnk_09D693D4, 0x60);
    anim = &work->anim;
    AnimInit(anim, gUnk_09EFBBEC, gUnk_09EFBBBC);
    AnimStart(anim, 1, 0);
    ColliderInit(&work->collider, 7, 26, 4);
    work->unk_000 = 0;
    work->timer = 0;
    work->unk_004 = arg->unk_00;
    work->unk_005 = 0;
    work->unk_006 = 0;
    work->unk_007 = 0;
    work->unk_008 = (arg->unk_00 << 14) + arg->unk_02;
    work->unk_00C = 0xF400;
    work->unk_010 = 0x15400;
    work->unk_014 = 0x4000;
    work->unk_016 = 0x2000;
    work->unk_018 = 720;
    work->unk_01C = arg->unk_04;
    work->unk_020 = arg->unk_08;
    work->unk_024 = arg->unk_0C;
    work->pos = arg->unk_10;
    func_0810BAE4(work);
    func_0810BCD4(work);
}

u8 task_bos_pc_flt_1(PcFltWork* work) {
    AnimState* anim;
    u16 id;

    func_0810BAE4(work);
    anim = &work->anim;
    AnimUpdate(anim);
    id = AnimGetGfxIndex(anim);
    if (id == 0) {
        work->z += 0x1000;
    } else {
        work->z += gUnk_09A4CEDC[id].unk_02 << 8;
        ColliderSetRadius(&work->collider, gUnk_09A4CEDC[id].unk_04);
    }
    func_0810BCD4(work);
    work->unk_007 = work->pos->unk_00 & 1;
    return 1;
}

void task_bos_pc_flt_2(PcFltWork* work) {
    s16 sx;
    s16 sy;
    u16 id;
    u16 g;
    u16 h;

    if (work->z <= 0) {
        id = AnimGetGfxIndex(&work->anim);
        WorldToScreen(&sx, &sy, work->x,
            work->y + (gUnk_09A4CEDC[id].unk_00 << 8), work->z);
        if (gBtlWork->unk_0F0 != 0) {
            g = GetBattleSpritePriorityFlags(work->y + (gUnk_09A4CEDC[id].unk_00 << 8));
            h = (-0x1004 - ((work->y >> 8) << 2)) | 3;
        } else {
            g = GetBattleSpritePriorityFlags(work->y);
            h = -0x1004 - ((work->y >> 8) << 2);
        }
        DrawSprite(sx, sy, AnimGetGfx(&work->anim), (void*)work->tiles,
                   (void*)work->palette, 0, g, h);
    }
}

void task_bos_pc_flt_3(PcFltWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}
