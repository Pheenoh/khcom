#include "frd.h"
#include "macros.h"

void task_frd_donald_0(FrdDonaldWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0;
    }

    body->unk_08 = work->unk_014->unk_008;
    body->unk_0C = -0x5000;
    body->unk_10 = 0;
    work->unk_01C = LoadObjPalette(gUnk_09617C58, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813EB8C, &work->unk_130, 0, 0, work->unk_018);

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
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);
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
    gfx = AnimGetGfx(&work->unk_130);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (gUnk_02039B84->unk_024 == 256) {
        affine = 0;
    } else if (gUnk_02039B84->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->unk_01C, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_donald_3(FrdDonaldWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080465F0(FrdGoofyWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    func_0801C6D4(&body->unk_04, &body->unk_08, &body->unk_0C, &body->unk_10);
    body->unk_0C += work->unk_154;
    work->unk_154 += 0x33;

    if (body->unk_0C > body->unk_10) {
        body->unk_0C = body->unk_10;
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
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0;
    }

    body->unk_08 = work->unk_014->unk_008;
    body->unk_0C = -0x5000;
    body->unk_10 = 0;
    work->unk_01C = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813EBFC, &work->unk_130, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);
}

INCLUDE_ASM("frd/task_frd_goofy_1.s");

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
    gfx = AnimGetGfx(&work->unk_130);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (gUnk_02039B84->unk_024 == 256) {
        affine = 0;
    } else if (gUnk_02039B84->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->unk_01C, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_goofy_3(FrdGoofyWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

void task_frd_ariel_0(FrdArielWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xBB);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;

    if (work->unk_014->unk_034 & 4) {
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 4;
    } else {
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0;
    }

    body->unk_08 = work->unk_014->unk_008;
    body->unk_10 = 0;
    work->unk_154 = -0x1000;
    body->unk_0C = -0x1000;
    work->unk_01C = LoadObjPalette(gUnk_09617DF8, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813EC5C, &work->unk_130, 1, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);

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

INCLUDE_ASM("frd/task_frd_ariel_1.s");

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
    gfx = AnimGetGfx(&work->unk_130);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (gUnk_02039B84->unk_024 == 256) {
        affine = 0;
    } else if (gUnk_02039B84->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->unk_01C, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_ariel_3(FrdArielWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080474A8(FrdJackWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    func_0801C6D4(&body->unk_04, &body->unk_08, &body->unk_0C, &body->unk_10);
    body->unk_0C += work->unk_154;
    work->unk_154 += 0x33;

    if (body->unk_0C > body->unk_10) {
        body->unk_0C = body->unk_10;
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
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0;
    }

    body->unk_08 = work->unk_014->unk_008;
    body->unk_0C = -0x5000;
    body->unk_10 = 0;
    work->unk_160 = 0;
    work->unk_01C = LoadObjPalette(gUnk_09617DB8, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813EC9C, &work->unk_130, 0, 0, work->unk_018);

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
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);
}

INCLUDE_ASM("frd/task_frd_jack_1.s");

INCLUDE_ASM("frd/task_frd_jack_2.s");

void task_frd_jack_3(FrdJackWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

void task_frd_pan_0(FrdPanWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xB9);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_158 = 0;

    if (work->unk_014->unk_034 & 4) {
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 0x20004;
        work->unk_168 = -0x800;
        work->unk_16C = 0;
    } else {
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0x20000;
        work->unk_168 = 0x800;
        work->unk_16C = 1;
    }

    work->unk_15C = 0x10000;
    body->unk_08 = work->unk_014->unk_008;
    body->unk_10 = 0;
    work->unk_164 = -0x2000;
    body->unk_0C = -0x2000;
    work->unk_01C = LoadObjPalette(gUnk_09617DD8, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813ECFC, &work->unk_130, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 15);
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);

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

INCLUDE_ASM("frd/func_08048980.s");

INCLUDE_ASM("frd/func_08048A68.s");

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
    gfx = AnimGetGfx(&work->unk_130);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (gUnk_02039B84->unk_024 == 256) {
        affine = 0;
    } else if (gUnk_02039B84->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->unk_01C, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_pan_3(FrdPanWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

INCLUDE_ASM("frd/func_080490FC.s");

void task_frd_aladdin_0(FrdAladdinWork* work, FrdArgs* args) {
    FrdBody* body;

    body = &work->unk_020;
    m4aSongNumStart(0xBC);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0;
    }

    body->unk_08 = work->unk_014->unk_008;
    body->unk_0C = -0x5000;
    body->unk_10 = 0;
    work->unk_01C = LoadObjPalette(gUnk_09617D98, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813ED4C, &work->unk_130, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);

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
    gfx = AnimGetGfx(&work->unk_130);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (gUnk_02039B84->unk_024 == 256) {
        affine = 0;
    } else if (gUnk_02039B84->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->unk_01C, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_aladdin_3(FrdAladdinWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

u8 func_080497E8(FrdBeastWork* work) {
    FrdBody* body;

    body = &work->unk_020;
    func_0801C6D4(&body->unk_04, &body->unk_08, &body->unk_0C, &body->unk_10);
    body->unk_0C += work->unk_158;
    work->unk_158 += 0x33;

    if (body->unk_0C > body->unk_10) {
        body->unk_0C = body->unk_10;
        work->unk_158 = 0;
        return 1;
    }

    return 0;
}

void task_frd_beast_0(FrdBeastWork* work, FrdArgs* args) {
    FrdBody* body;
    FrdObj* obj;

    body = &work->unk_020;
    m4aSongNumStart(0xBA);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B84->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
        obj = gUnk_02039B84->unk_078;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->unk_018 = gUnk_02039B84->unk_114;
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
        body->unk_04 = (gUnk_02039B84->unk_0DC + 0x30) << 8;
        body->unk_34 = 0x20004;
    } else {
        body->unk_04 = (gUnk_02039B84->unk_0DA - 0x30) << 8;
        body->unk_34 = 0x20000;
    }

    body->unk_08 = work->unk_154;
    body->unk_0C = 0;
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

    work->unk_01C = LoadObjPalette(gUnk_09617E18, 32);
    AnimInit(&work->unk_130, 0, 0);
    func_08019068(gUnk_0813ED90, &work->unk_130, 0, 0, work->unk_018);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gUnk_09EDAE88, body);
}

INCLUDE_ASM("frd/task_frd_beast_1.s");

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
    gfx = AnimGetGfx(&work->unk_130);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (gUnk_02039B84->unk_024 == 256) {
        affine = 0;
    } else if (gUnk_02039B84->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_018, work->unk_01C, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_beast_3(FrdBeastWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}
