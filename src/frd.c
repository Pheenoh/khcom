#include "frd.h"
#include "macros.h"

INCLUDE_ASM("frd/task_frd_donald_0.s");

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

INCLUDE_ASM("frd/task_frd_goofy_0.s");

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

INCLUDE_ASM("frd/task_frd_ariel_0.s");

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

INCLUDE_ASM("frd/task_frd_jack_0.s");

INCLUDE_ASM("frd/task_frd_jack_1.s");

INCLUDE_ASM("frd/task_frd_jack_2.s");

void task_frd_jack_3(FrdJackWork* work) {
    FrdObj* obj;

    obj = work->unk_14C != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_01C);
    TaskPoolDestroy(&work->unk_000);
}

INCLUDE_ASM("frd/task_frd_pan_0.s");

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

INCLUDE_ASM("frd/task_frd_aladdin_0.s");

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

INCLUDE_ASM("frd/task_frd_beast_0.s");

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
