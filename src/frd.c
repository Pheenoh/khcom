#include "frd.h"
#include "macros.h"

void task_frd_donald_0(FrdDonaldWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->unk_014->unk_008;
    body->z = -0x5000;
    body->unk_10 = 0;
    work->palette = LoadObjPalette(gUnk_09617C58, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EB8C, &work->anim, 0, 0, work->unk_018);

    switch (args->unk_00) {
    case 0:
        work->unk_160 = 1;
        m4aSongNumStart(0xB4);
        break;
    case 1:
        work->unk_160 = 1;
        m4aSongNumStart(0xB4);
        break;
    case 2:
        work->unk_160 = 1;
        m4aSongNumStart(0xB4);
        break;
    default:
        m4aSongNumStart(0xB3);
        func_08017260(0, 0, 0, 0x180);
        func_08045494(body, 0, 8, 8);
        break;
    }

    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);
}

INCLUDE_ASM("frd/task_frd_donald_1.s");

void task_frd_donald_2(FrdDonaldWork* work) {
    FrdBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_donald_3(FrdDonaldWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080465F0(FrdGoofyWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);
    body->z += work->unk_154;
    work->unk_154 += 0x33;

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_goofy_0(FrdGoofyWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xAE);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->unk_014->unk_008;
    body->z = -0x5000;
    body->unk_10 = 0;
    work->palette = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EBFC, &work->anim, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);
}

u8 task_frd_goofy_1(FrdGoofyWork* work) {
    FrdBody* body;
    BtlWork* obj;
    s32 t;

    body = &work->unk_020;
    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    switch (work->unk_148) {
    case 0:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 0, 0, work->unk_018);
            work->unk_14E++;
        }

        body->x += (work->unk_158 - body->x) >> 4;
        func_0801A8A4(&body->x, &body->y, -16, 0);

        if (func_080465F0(work)) {
            work->unk_148 = 1;
            work->unk_14E = 0;
            m4aSongNumStart(0xB2);
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 1, 0, work->unk_018);
        }

        if (AnimIsFinished(&work->anim)) {
            switch (work->unk_14D) {
            case 0:
            case 1:
                work->unk_148 = 4;
                break;
            case 2:
                work->unk_148 = 5;
                break;
            }

            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 1, 0, work->unk_018);
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_148 = 3;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 3:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 0, 0, work->unk_018);

            if (body->flags & 4) {
                work->unk_158 = (gBtlWork->unk_0DA - 0x40) << 8;
            } else {
                work->unk_158 = (gBtlWork->unk_0DC + 0x40) << 8;
            }

            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }

        ApproachValue(&body->x, work->unk_158, work->unk_150);
        func_080465F0(work);

        if (work->unk_150 <= 0) {
            return 0;
        }

        work->unk_14E++;
        work->unk_150--;
        break;
    case 4:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 2, 0, work->unk_018);

            if (body->flags & 4) {
                work->unk_158 = body->x - 0x8500;
            } else {
                work->unk_158 = body->x + 0x8500;
            }
        }

        if (work->unk_14E == 40) {
            work->unk_15C = work->unk_014->unk_008;
        }

        if (work->unk_14E > 39) {
            body->x += (work->unk_158 - body->x) >> 4;
            body->y += (work->unk_15C - body->y) >> 4;

            if (body->flags & 4
                    ? func_08011F78(work->unk_14D + 120, body->x - 0xF00, body->y, body->z, 0x1E, 0x0C, 0x30)
                    : func_08011F78(work->unk_14D + 120, body->x + 0xF00, body->y, body->z, 0x1E, 0x0C, 0x30)) {
                m4aSongNumStart(0x20A);
            }

            func_0801A8A4(&body->x, &body->y, -16, 0);
        }

        func_080465F0(work);

        if (AnimIsFinished(&work->anim)) {
            work->unk_148 = 2;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 5:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 3, 0, work->unk_018);
        }

        func_080465F0(work);

        if (AnimIsFinished(&work->anim)) {
            work->unk_148 = 6;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 6:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 4, 1, work->unk_018);
            work->unk_160 = GetRandom();
        }

        work->unk_158 = work->unk_014->unk_004 + (gSineTable[work->unk_160] << 6);
        work->unk_15C = work->unk_014->unk_008 - (gSineTable[work->unk_160 + 0x40] << 5);
        body->x += (work->unk_158 - body->x) >> 3;
        body->y += (work->unk_15C - body->y) >> 3;
        func_0801A8A4(&body->x, &body->y, -16, 0);
        work->unk_160 += 4;

        if (func_08011F78(0x7A, body->x, body->y, body->z, 0x23, 0x1C, 0x30)) {
            m4aSongNumStart(0x20A);
        }

        func_080465F0(work);

        if (work->unk_14E > 179) {
            work->unk_148 = 2;
            work->unk_14E = 0;
        }

        work->unk_14E++;
        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_goofy_2(FrdGoofyWork* work) {
    FrdBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_goofy_3(FrdGoofyWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

void task_frd_ariel_0(FrdArielWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xBB);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;

    if (work->unk_014->unk_034 & 4) {
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->unk_014->unk_008;
    body->unk_10 = 0;
    work->unk_154 = -0x1000;
    body->z = -0x1000;
    work->palette = LoadObjPalette(gUnk_09617DF8, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EC5C, &work->anim, 1, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);

    switch (args->unk_00) {
    case 0:
        work->unk_15C = 0x500;
        work->unk_158 = 0;
        break;
    case 1:
        work->unk_15C = 0x800;
        work->unk_158 = 1;
        break;
    case 2:
    default:
        work->unk_15C = 0xC00;
        work->unk_158 = 4;
        break;
    }
}

u8 task_frd_ariel_1(FrdArielWork* work) {
    FrdBody* body;
    BtlWork* obj;
    s32 t;


    body = &work->unk_020;

    if (gGameState.world != 2) {
        return 0;
    }

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);

    switch (work->unk_148) {
    case 0:
        if (body->flags & 4) {
            t = gBtlWork->unk_0DC - 0x30;
        } else {
            t = gBtlWork->unk_0DA + 0x30;
        }

        body->x += ((t << 8) - body->x) >> 3;

        if (work->unk_14E > 20) {
            work->unk_14E = 0;
            work->unk_148 = 1;
        } else {
            work->unk_14E++;
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            work->unk_160 = 0;
            work->unk_150 = 12;
            func_08019068(gUnk_0813EC5C, &work->anim, 2, 0, work->unk_018);
        }

        switch (AnimGetFrame(&work->anim)) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        default:
            if (work->unk_150 > 0) {
                ApproachValue(&work->unk_160, work->unk_15C, work->unk_150);
                work->unk_150--;
            }

            if (body->flags & 4) {
                body->x -= work->unk_160;
            } else {
                body->x += work->unk_160;
            }
            break;
        }

        if (work->unk_150 <= 0 && AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->unk_148 = 2;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        func_08019068(gUnk_0813EC5C, &work->anim, 0, 1, work->unk_018);

        if (body->flags & 4
                ? func_08011F78(0x77, body->x, body->y, body->z, 0x10, 0x10, 0x10)
                : func_08011F78(0x77, body->x, body->y, body->z, 0x10, 0x10, 0x10)) {
            m4aSongNumStart(0x250);
        }

        if (body->flags & 4) {
            body->x -= work->unk_15C;

            if (body->x < (gBtlWork->unk_0DA - 0x30) << 8) {
                if (work->unk_158 == 0) {
                    return 0;
                }

                work->unk_158--;
                body->flags &= 0xFFFFFFFFFFFFFFFB;
                work->unk_14E = 0;
                body->y = work->unk_014->unk_008;
                func_08019A30();
            }
        } else {
            body->x += work->unk_15C;

            if (body->x > (gBtlWork->unk_0DC + 0x30) << 8) {
                if (work->unk_158 == 0) {
                    return 0;
                }

                work->unk_158--;
                body->flags |= 4;
                work->unk_14E = 0;
                body->y = work->unk_014->unk_008;
                func_08019A30();
            }
        }

        body->z = work->unk_154 + (gSineTable[((u16)work->unk_14E * 8) & 0xFF] << 3);
        body->y += (work->unk_014->unk_008 - body->y) >> 4;

        if (work->unk_14E == 20) {
            m4aSongNumStart(0xBE);
        }

        work->unk_14E++;
        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_ariel_2(FrdArielWork* work) {
    FrdBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_ariel_3(FrdArielWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080474A8(FrdJackWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);
    body->z += work->unk_154;
    work->unk_154 += 0x33;

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_jack_0(FrdJackWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xB8);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->unk_014->unk_008;
    body->z = -0x5000;
    body->unk_10 = 0;
    work->unk_160 = 0;
    work->palette = LoadObjPalette(gUnk_09617DB8, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EC9C, &work->anim, 0, 0, work->unk_018);

    switch (args->unk_00) {
    case 0:
        work->unk_168 = 0;
        break;
    case 1:
        work->unk_168 = 1;
        break;
    case 2:
    default:
        work->unk_168 = 2;
        break;
    }

    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);
}

INCLUDE_ASM("frd/task_frd_jack_1.s");

INCLUDE_ASM("frd/task_frd_jack_2.s");

void task_frd_jack_3(FrdJackWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

void task_frd_pan_0(FrdPanWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xB9);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_158 = 0;

    if (work->unk_014->unk_034 & 4) {
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 0x20004;
        work->unk_168 = -0x800;
        work->unk_16C = 0;
    } else {
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0x20000;
        work->unk_168 = 0x800;
        work->unk_16C = 1;
    }

    work->unk_15C = 0x10000;
    body->y = work->unk_014->unk_008;
    body->unk_10 = 0;
    work->unk_164 = -0x2000;
    body->z = -0x2000;
    work->palette = LoadObjPalette(gUnk_09617DD8, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813ECFC, &work->anim, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 15);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);

    switch (work->unk_14D) {
    case 0:
        work->unk_152 = 0x78;
        break;
    case 1:
        work->unk_152 = 0xF0;
        break;
    case 2:
    default:
        work->unk_152 = 0x1E0;
        break;
    }
}

void func_08048980(FrdPanWork* work) {
    FrdBody sub;

    if ((s16)work->unk_14E % 3 == 0) {
        sub.x = work->unk_020.x;
        sub.y = work->unk_020.y;
        sub.z = work->unk_020.z;

        switch (AnimGetGfxIndex(&work->anim)) {
        case 1:
        case 2:
            sub.z -= 0x800;
            break;
        case 3:
        case 4:
            sub.z -= 0x1800;

            if (work->unk_020.flags & 4) {
                sub.x += 0x2000;
            } else {
                sub.x -= 0x2000;
            }
            break;
        case 5:
        default:
            sub.z -= 0x1000;

            if (work->unk_020.flags & 4) {
                sub.x += 0x1000;
            } else {
                sub.x -= 0x1000;
            }
            break;
        }

        TaskCreate(&work->unk_000, gTaskDescSmnTinkeff, &sub);
    }
}

void func_08048A68(FrdPanWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    body->z += ((work->unk_164 + (gSineTable[((u16)work->unk_14E * 2) & 0xFF] << 4)) - body->z) >> 2;
}

INCLUDE_ASM("frd/task_frd_pan_1.s");

void task_frd_pan_2(FrdPanWork* work) {
    FrdBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_pan_3(FrdPanWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080490FC(FrdAladdinWork* work) {
    FrdBody* body;

    body = &work->unk_020;

    if (func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10)) {
        body->z += work->unk_154;
        work->unk_154 = -0x200;
    } else {
        body->z += work->unk_154;
        work->unk_154 += 0x33;
    }

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_aladdin_0(FrdAladdinWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xBC);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->unk_014->unk_008;
    body->z = -0x5000;
    body->unk_10 = 0;
    work->palette = LoadObjPalette(gUnk_09617D98, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813ED4C, &work->anim, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);

    switch (work->unk_14D) {
    case 0:
        work->unk_152 = 0x78;
        break;
    case 1:
        work->unk_152 = 0xF0;
        break;
    case 2:
    default:
        work->unk_152 = 0x1E0;
        break;
    }
}

INCLUDE_ASM("frd/task_frd_aladdin_1.s");

void task_frd_aladdin_2(FrdAladdinWork* work) {
    FrdBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_aladdin_3(FrdAladdinWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080497E8(FrdBeastWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);
    body->z += work->unk_158;
    work->unk_158 += 0x33;

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
        work->unk_158 = 0;
        return 1;
    }

    return 0;
}

void task_frd_beast_0(FrdBeastWork* work, FrdArgs* args) {
    FrdBody* body;
    BtlWork* obj;

    body = &work->unk_020;
    m4aSongNumStart(0xBA);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
        obj = gBtlWork->unk_078;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gBtlWork->unk_114;
        obj = gUnk_02039B9C->unk_078;
    }

    work->unk_14D = args->unk_00;
    work->unk_14E = 0;
    work->unk_158 = 0;

    if (obj != 0) {
        work->unk_150 = obj->unk_004;
        work->unk_154 = obj->unk_008;
    } else {
        work->unk_150 = 0x10000;
        work->unk_154 = work->unk_014->unk_008;
    }

    if (work->unk_014->unk_034 & 4) {
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 0x20004;
    } else {
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0x20000;
    }

    body->y = work->unk_154;
    body->z = 0;
    body->unk_10 = 0;

    switch (work->unk_14D) {
    case 0:
        work->unk_148 = 1;
        work->unk_15C = 0xA0;
        break;
    case 1:
        work->unk_148 = 1;
        work->unk_15C = 0xA1;
        break;
    case 2:
    default:
        work->unk_148 = 2;
        work->unk_15C = 0xA1;
        break;
    }

    work->palette = LoadObjPalette(gUnk_09617E18, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813ED90, &work->anim, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);
}

u8 task_frd_beast_1(FrdBeastWork* work) {
    FrdBody* body;
    BtlWork* obj;

    body = &work->unk_020;

    if (gGameState.world != 8) {
        return 0;
    }

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    switch (work->unk_148) {
    case 2:
        if (work->unk_14E == 0) {
            m4aSongNumStart(0xBD);
        }

        if (work->anim.timer == 0 && AnimGetFrame(&work->anim) == 2) {
            work->unk_158 = -0x400;
            m4aSongNumStart(0x270);
        }

        if (body->z < body->unk_10) {
            body->x += (work->unk_150 - body->x) >> 4;
            body->y += (work->unk_154 - body->y) >> 4;
        }

        if (work->unk_158 > 0) {
            if (gBtlWork->unk_10C == 0x99) {
                func_08011F78(0xA3, body->x, body->y, body->z - 0x1800, 0x28, 0x14, 0x10);
            } else {
                func_08011F78(0xA2, body->x, body->y, body->z - 0x1800, 0x28, 0x14, 0x10);
            }
        }

        if (func_080497E8(work) && AnimIsFinished(&work->anim)) {
            work->unk_148 = 1;
            work->unk_15C = 0xA1;
            work->unk_14E = 0;
            func_0802F1E8();
            break;
        }

        work->unk_14E++;
        break;
    case 1:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ED90, &work->anim, 1, 1, work->unk_018);

            if (work->unk_14D != 2) {
                m4aSongNumStart(0xBD);
            }
        }

        if (body->flags & 4) {
            body->x -= 0x380;

            if (body->x < (gBtlWork->unk_0DA - 0x28) << 8) {
                return 0;
            }
        } else {
            body->x += 0x380;

            if (body->x > (gBtlWork->unk_0DC + 0x28) << 8) {
                return 0;
            }
        }

        if (func_08011F78(work->unk_15C, body->x, body->y, body->z - 0x1800, 0x28, 0x14, 0x10)) {
            m4aSongNumStart(0x26F);
        }

        func_080497E8(work);
        work->unk_14E++;
        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_beast_2(FrdBeastWork* work) {
    FrdBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_beast_3(FrdBeastWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}
