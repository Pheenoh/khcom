#include "smn.h"
#include "macros.h"

void task_smn_cloud_0(SmnCloudWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_163 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_110;
    } else {
        work->unk_163 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B9C->unk_110;
    }

    body->unk_04 = obj->unk_014;
    body->unk_08 = obj->unk_018;
    body->unk_0C = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->unk_34 = 4;
    } else {
        body->unk_34 = 0;
    }

    work->unk_162 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_08F6DC24, 32);
    work->unk_15C = 0;
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813E958, &work->unk_008, 0, 0, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14C = 0;
    work->unk_158 = 0;
    work->unk_150 = 10;
    work->unk_154 = 10;
    work->unk_164 = 0;
    work->unk_160 = 0;
    work->unk_168 = 0;
    work->unk_17C = 0;
    work->unk_16C = 0;
    TaskPoolInit(&work->unk_020, 2);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

INCLUDE_ASM("smn/task_smn_cloud_1.s");

void task_smn_cloud_2(SmnCloudWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);
    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (work->unk_150 == 256 && work->unk_154 == work->unk_150) {
        if (body->unk_34 & 4) {
            sclY = gUnk_02039B84->unk_024;
            sclX = sclY;
        } else if (gUnk_02039B84->unk_024 == work->unk_154) {
            sclY = gUnk_02039B84->unk_024;
            sclX = sclY;
            flags |= 1;
        } else {
            sclY = gUnk_02039B84->unk_024;
            sclX = -sclY;
        }
    } else if (body->unk_34 & 4) {
        sclX = gUnk_02039B84->unk_024 * work->unk_150 >> 8;
        sclY = gUnk_02039B84->unk_024 * work->unk_154 >> 8;
    } else {
        sclX = -(gUnk_02039B84->unk_024 * work->unk_150 >> 8);
        sclY = gUnk_02039B84->unk_024 * work->unk_154 >> 8;
    }

    if (sclY == 256 && sclX == sclY) {
        affine = 0;
    } else if (sclY <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_cloud_3(SmnCloudWork* work) {
    SmnObj* obj;

    obj = work->unk_163 != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

void func_08041D64(SmnBambiWork* work) {
    work->unk_170 = work->unk_038.unk_04 + gSineTable[work->unk_158] * 80;
    work->unk_174 = work->unk_038.unk_08 + -gSineTable[work->unk_158 + 0x40] * 40;
    work->unk_158 += GetRandom() % 0x21 + 0x20;

    if (work->unk_170 - work->unk_038.unk_04 > 0) {
        work->unk_038.unk_34 |= 4;
    } else {
        work->unk_038.unk_34 &= 0xFFFFFFFFFFFFFFFB;
    }
}

void task_smn_bambi_0(SmnBambiWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_163 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_114;
    } else {
        work->unk_163 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_114;
    }

    body->unk_04 = (gUnk_02039B84->unk_0DA
                    + GetRandom() % (gUnk_02039B84->unk_0DC - gUnk_02039B84->unk_0DA + 1)) << 8;
    body->unk_08 = (gUnk_02039B84->unk_0DE
                    + GetRandom() % (gUnk_02039B84->unk_0E0 - gUnk_02039B84->unk_0DE + 1)) << 8;
    body->unk_0C = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->unk_34 = 0;
        work->unk_158 = 0xC0;
    } else {
        body->unk_34 = 4;
        work->unk_158 = 0x40;
    }

    work->unk_162 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_09617FF8, 32);
    work->unk_15C = 0;
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813E9E8, &work->unk_008, 0, 0, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_150 = 0;
    work->unk_154 = 10;
    work->unk_164 = 0;
    work->unk_160 = 0;
    work->unk_168 = 0;
    work->unk_16C = 0;
    m4aSongNumStart(0xAB);
    TaskPoolInit(&work->unk_020, 2);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

u8 func_08041FCC(SmnBambiWork* work) {
    SmnBody* body;

    body = &work->unk_038;
    body->unk_10 = 0;
    func_0801C6D4(&body->unk_04, &body->unk_08, &body->unk_0C, &body->unk_10);
    body->unk_0C += work->unk_15C;
    work->unk_15C += 0x33;

    if (body->unk_0C > body->unk_10) {
        body->unk_0C = body->unk_10;
        work->unk_15C = 0;
        return 1;
    }

    return 0;
}

SmnObj* func_08042018(SmnBambiWork* work) {
    SmnObj* list[10];
    SmnObj* p;
    s16 count;

    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_163 != 0) {
            p = gUnk_02039B9C->unk_07C;
        } else {
            p = gUnk_02039B84->unk_07C;
        }

        if (p->unk_02C <= 0) {
            return 0;
        }

        return p;
    }

    count = 0;
    p = func_08000C8C(gUnk_02039B84->unk_080);

    while (p != 0) {
        if (!(p->unk_034 & 0x01000000)) {
            list[count] = p;
            count++;
            if (count > 9) {
                break;
            }
        }
        p = func_08000CD4(&p->unk_0B8);
    }

    if (count == 0) {
        return 0;
    }

    p = list[work->unk_16C % count];
    work->unk_16C++;
    return p;
}
u8 task_smn_bambi_1(SmnBambiWork* work) {
    SmnBody* body;
    SmnObj* obj;
    SmnPrizeArgs args;

    body = &work->unk_038;
    obj = work->unk_163 != 0 ? gUnk_02039B84 : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    switch (work->unk_034) {
    case 0:
        if (work->unk_163 != 0) {
            func_0802F284(body->unk_04, body->unk_08, body->unk_0C);
        }

        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x235);
        }

        func_080058FC(&work->unk_154, 256, work->unk_14A);

        if (work->unk_14A > 0) {
            work->unk_148++;
            work->unk_14A--;
        } else {
            if (work->unk_162 == 3) {
                work->unk_034 = 2;
            } else {
                work->unk_034 = 1;
            }

            work->unk_148 = 0;
            work->unk_164 = 1;
        }
        break;
    case 3:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x239);
        }

        do {
            func_080058FC(&work->unk_154, 25, work->unk_14A);
        } while (0);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 2:
        if (work->unk_148 == 0) {
            AnimStart(&work->unk_008, 0, 0);
            work->unk_15C = -0x480;
            m4aSongNumStart(0x236);
            work->unk_168 = func_08042018(work);
            work->unk_14A = 0;
        }

        if (work->unk_15C > 0) {
            func_08019A30();

            if (func_08011F78(0x76, body->unk_04, body->unk_08, body->unk_0C - 0x400, 8, 8, 2) != 0) {
                func_0801416C(body->unk_04, body->unk_08, body->unk_0C);
                AnimStart(&work->unk_008, 0, 0);
                work->unk_15C = -0x400;
                m4aSongNumStart(0x236);
                m4aSongNumStart(0x28D);
                work->unk_168 = func_08042018(work);
                work->unk_14A++;
            }
        }

        if (func_08041FCC(work)) {
            AnimStart(&work->unk_008, 0, 0);
            work->unk_15C = -0x480;
            m4aSongNumStart(0x236);
            work->unk_168 = func_08042018(work);
            work->unk_14A++;
        }

        if ((work->unk_15C > 0 && work->unk_14A > 7) || work->unk_168 == 0) {
            work->unk_034 = 3;
            work->unk_148 = 0;
        } else {
            if (body->unk_04 < work->unk_168->unk_004) {
                body->unk_34 |= 4;
            } else {
                body->unk_34 &= 0xFFFFFFFFFFFFFFFB;
            }

            body->unk_04 += (work->unk_168->unk_004 - body->unk_04) >> 4;
            body->unk_08 += (work->unk_168->unk_008 - body->unk_08) >> 4;
            func_0801A8A4(&body->unk_04, &body->unk_08, -16, 0);
            work->unk_148++;
        }
        break;
    case 1:
        if (work->unk_14C == 0) {
            AnimStart(&work->unk_008, 0, 0);
            func_08041D64(work);
            work->unk_14A = 30;
        }

        if (work->unk_162 == 2) {
            func_08011F78(0x75, body->unk_04, body->unk_08, body->unk_0C, 8, 8, 8);
        } else {
            func_08011F78(0x74, body->unk_04, body->unk_08, body->unk_0C, 8, 8, 8);
        }

        if (work->unk_14C > 4) {
            if (work->unk_14C == 5) {
                work->unk_15C = -0x300;
                m4aSongNumStart(0x236);
            }

            if (work->unk_14A > 0) {
                func_0800592C(&body->unk_04, work->unk_170, work->unk_14A);
                func_0800592C(&body->unk_08, work->unk_174, work->unk_14A);
                work->unk_14A--;
            }
        }

        func_08041FCC(work);
        func_0801A8A4(&body->unk_04, &body->unk_08, -16, 0);

        if (AnimIsFinished(&work->unk_008)) {
            work->unk_14C = 0;
            work->unk_148++;
            args.unk_00 = body->unk_04;
            args.unk_04 = body->unk_08;
            args.unk_08 = body->unk_0C;

            if (work->unk_162 == 0) {
                args.unk_12 = 1;
            } else {
                args.unk_12 = 2;
            }

            args.unk_14 = 0;
            TaskCreate((TaskPool*)&gUnk_02039B84->unk_02C, gUnk_09EDAF18, &args);
        } else {
            work->unk_14C++;
        }

        if (work->unk_148 > 4) {
            work->unk_034 = 3;
            work->unk_148 = 0;
        }
        break;
    }

    if (work->unk_164 != 0) {
        AnimUpdate(&work->unk_008);
    }

    TaskPoolUpdate(&work->unk_020);
    return 1;
}

void task_smn_bambi_2(SmnBambiWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_154 == gUnk_02039B84->unk_024) {
        sclY = work->unk_154;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_154 >> 8;
    sclY = sclY * work->unk_154 >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_bambi_3(SmnBambiWork* work) {
    SmnObj* obj;

    obj = work->unk_163 != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_tink_0(SmnTinkWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;
    s32 t;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_153 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_114;
    } else {
        work->unk_153 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_114;
    }

    body->unk_04 = obj->unk_014;
    body->unk_08 = obj->unk_018;
    body->unk_0C = obj->unk_01C - 0x3000;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->unk_34 = 0x80004;
    } else {
        body->unk_34 = 0x80000;
    }

    work->unk_152 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_09618098, 32);
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813EA08, &work->unk_008, 0, 1, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 10;
    work->unk_154 = 0;
    work->unk_150 = 0;
    work->unk_16C = 0;
    work->unk_170 = 0;

    if (work->unk_153 != 0) {
        work->unk_17C = gUnk_02039B84->unk_07C;
    } else {
        work->unk_17C = gUnk_02039B9C->unk_07C;
    }

    m4aSongNumStart(0xAB);
    work->unk_178 = work->unk_17C->unk_02C << 8;

    switch (args->unk_00) {
    case 0:
        t = 0x4C;
        work->unk_16E = 0xB4;
        break;
    case 1:
        t = 0x99;
        work->unk_16E = 0x12C;
        break;
    case 2:
    default:
        t = 0x100;
        work->unk_16E = 0x1A4;
        break;
    }

    if (*(u32*)(work->unk_17C->unk_0E4 + 0xF4) == 0x27) {
        t = 332 * t >> 8;
    }

    work->unk_174 = work->unk_17C->unk_02E * t + work->unk_178;

    if (work->unk_174 > work->unk_17C->unk_02E << 8) {
        work->unk_174 = work->unk_17C->unk_02E << 8;
    }

    TaskPoolInit(&work->unk_020, 15);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

void func_080428E8(SmnTinkWork* work) {
    if (work->unk_170 % 3 == 0) {
        TaskCreate(&work->unk_020, gUnk_09EDB458, &work->unk_038);
    }
}
#ifdef NON_MATCHING
u8 task_smn_tink_1(SmnTinkWork* work) {
    SmnBody* body;
    SmnObj* obj;
    SmnObj* p;
    s32 x;
    s32 y;
    s32 z;
    s32 d;
    s32 i;
    s32 t;

    body = &work->unk_038;
    obj = work->unk_153 != 0 ? gUnk_02039B84 : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    if (work->unk_16E <= 0) {
        if (work->unk_034 != 1) {
            work->unk_034 = 1;
            work->unk_148 = 0;
        }
    } else {
        func_080058FC(&work->unk_178, work->unk_174, work->unk_16E);
        work->unk_17C->unk_02C = work->unk_178 >> 8;
        work->unk_16E--;
    }

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x235);
        }

        func_080058FC(&work->unk_14C, 256, work->unk_14A);

        if (work->unk_14A > 0) {
            work->unk_148++;
            work->unk_14A--;
        } else {
            work->unk_034 = 2;
            work->unk_148 = 0;
            work->unk_154 = 1;
            m4aSongNumStart(0x24F);
        }
        break;
    case 1:
        if (work->unk_148 == 0) {
            work->unk_14A = 20;
            m4aSongNumStop(0x24F);
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x239);
        }

        func_080058FC(&work->unk_14C, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 2:
        func_080428E8(work);

        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EA08, &work->unk_008, 0, 1, work->unk_000);
            work->unk_160 = body->unk_0C;
            work->unk_14A = 30;
        } else {
            body->unk_0C += (work->unk_160 + gSineTable[work->unk_148 & 0xFF] * 12
                             - body->unk_0C) >> 2;
        }

        if (work->unk_17C->unk_004 < body->unk_04) {
            body->unk_34 |= 4;
        } else {
            body->unk_34 &= 0xFFFFFFFFFFFFFFFB;
        }

        if (work->unk_14A-- <= 0) {
            work->unk_148 = 0;
            work->unk_034 = 3;
        } else {
            work->unk_148++;
        }
        break;
    case 3:
        func_080428E8(work);

        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EA08, &work->unk_008, 1, 1, work->unk_000);
        }

        p = work->unk_17C;
        i = (u16)work->unk_148 * 4 & 0xFF;
        x = p->unk_004 + gSineTable[i] * 32;
        y = p->unk_008 - gSineTable[i + 0x40] * 16;
        z = gSineTable[(u16)work->unk_148 * 2 & 0xFF] * 16 - 0x1E00 + p->unk_00C;

        if (x < body->unk_04) {
            body->unk_34 |= 4;
        } else {
            body->unk_34 &= 0xFFFFFFFFFFFFFFFB;
        }

        d = (x - body->unk_04) >> 3;

        if (d > 0x400) {
            d = 0x400;
        } else if (d < -0x400) {
            d = -0x400;
        }

        body->unk_04 += d;
        d = (y - body->unk_08) >> 3;

        if (d > 0x200) {
            d = 0x200;
        } else if (d < -0x200) {
            d = -0x200;
        }

        body->unk_08 += d;
        body->unk_0C += (z - body->unk_0C) >> 3;
        t = work->unk_148 % 60;

        if (t == 0) {
            switch (GetRandom() % 3) {
            case 0:
                work->unk_168 = 0x280;
                work->unk_034 = 4;
                work->unk_148 = t;
                break;
            case 1:
                work->unk_034 = 2;
                work->unk_148 = t;
                break;
            case 2:
            default:
                work->unk_148++;
                break;
            }
        } else {
            work->unk_148++;
        }
        break;
    case 4:
        func_080428E8(work);

        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EA08, &work->unk_008, 2, 0, work->unk_000);

            if (body->unk_34 & 4) {
                work->unk_16C = 0xC0;
            } else {
                work->unk_16C = 0x40;
            }
        }

        body->unk_04 += gSineTable[(u8)work->unk_16C] * work->unk_168 >> 8;
        body->unk_0C += -gSineTable[(u8)work->unk_16C + 0x40] * work->unk_168 >> 8;

        if (body->unk_34 & 4) {
            work->unk_16C += 7;
        } else {
            work->unk_16C -= 7;
        }

        if (AnimIsFinished(&work->unk_008)) {
            func_08019068(gUnk_0813EA08, &work->unk_008, 1, 1, work->unk_000);
            work->unk_034 = 3;
            work->unk_148 = 1;
        } else {
            work->unk_148++;
        }
        break;
    }

    func_0801A8A4(&body->unk_04, &body->unk_08, -16, 0);

    if (work->unk_154 != 0) {
        AnimUpdate(&work->unk_008);
    }

    TaskPoolUpdate(&work->unk_020);
    work->unk_170++;
    return 1;
}
#else
INCLUDE_ASM("smn/task_smn_tink_1.s");
#endif

void task_smn_tink_2(SmnTinkWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_14C == gUnk_02039B84->unk_024) {
        sclY = work->unk_14C;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_14C >> 8;
    sclY = sclY * work->unk_14C >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_tink_3(SmnTinkWork* work) {
    SmnObj* obj;

    obj = work->unk_153 != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    m4aSongNumStop(0x24F);
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

#ifdef NON_MATCHING
void task_smn_tinkeff_0(SmnTinkeffWork* work, SmnBody* args) {
    work->unk_20 = args->unk_04 + ((GetRandom() % 9) << 8) - 0x400;
    work->unk_24 = args->unk_08 + ((GetRandom() % 9) << 8) - 0x400;
    work->unk_28 = args->unk_0C;
    work->unk_2C = GetRandom() % 0xE8 + 0x4C;
    work->unk_00 = LoadObjTiles(gUnk_088A5D7A, 0x200);
    work->unk_04 = LoadObjPalette(gUnk_08F69BA4, 32);
    AnimInit(&work->unk_08, gUnk_09EDE7E4, gUnk_09EDE7B4);

    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->unk_08, 0, 1);
        break;
    case 1:
        AnimStart(&work->unk_08, 1, 1);
        break;
    case 2:
        AnimStart(&work->unk_08, 2, 1);
        break;
    }
}
#else
INCLUDE_ASM("smn/task_smn_tinkeff_0.s");
#endif

u8 task_smn_tinkeff_1(SmnTinkeffWork* work) {
    work->unk_28 += work->unk_2C;

    if (AnimIsFinished(&work->unk_08)) {
        return 0;
    }

    AnimUpdate(&work->unk_08);
    return 1;
}

void task_smn_tinkeff_2(SmnTinkeffWork* work) {
    void* gfx;
    s16 sx;
    s16 sy;

    gfx = AnimGetGfx(&work->unk_08);
    WorldToScreen(&sx, &sy, work->unk_20, work->unk_24, work->unk_28);
    DrawSprite(sx, sy, gfx, work->unk_00, work->unk_04, 0, 0x800,
               -4100 - ((work->unk_24 >> 8) * 4));
}

void task_smn_tinkeff_3(SmnTinkeffWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void task_smn_simba_0(SmnSimbaWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_155 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_110;
    } else {
        work->unk_155 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B9C->unk_110;
    }

    body->unk_04 = obj->unk_014;
    body->unk_08 = obj->unk_018;
    body->unk_0C = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->unk_34 = 0x20004;
    } else {
        body->unk_34 = 0x20000;
    }

    work->unk_154 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_09618018, 32);
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813EA5C, &work->unk_008, 0, 0, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_150 = 10;
    work->unk_156 = 0;
    TaskPoolInit(&work->unk_020, 2);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

u8 task_smn_simba_1(SmnSimbaWork* work) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;
    obj = work->unk_155 != 0 ? gUnk_02039B84 : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        do {
            return 0;
        } while (0);
    }

    func_0802F284(body->unk_04, body->unk_08, body->unk_0C);

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x235);
        }

        func_080058FC(&work->unk_150, 256, work->unk_14A);

        if (work->unk_14A > 0) {
            work->unk_148++;
            work->unk_14A--;
        } else {
            work->unk_034 = 1;
            work->unk_148 = 0;
            work->unk_156 = 1;
        }
        break;
    case 2:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x239);
        }

        func_080058FC(&work->unk_150, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 1:
        switch (work->unk_148) {
        case 0:
            if (body->unk_34 & 4) {
                func_08019050(30, 0x133, body->unk_04 - 0x1400,
                              body->unk_08 + body->unk_0C - 0x1400);
            } else {
                func_08019050(30, 0x133, body->unk_04 + 0x1400,
                              body->unk_08 + body->unk_0C - 0x1400);
            }
            break;
        case 50:
            switch (work->unk_154) {
            case 0:
                m4aSongNumStart(0x24A);
                break;
            case 1:
                m4aSongNumStart(0x24B);
                break;
            case 2:
            default:
                m4aSongNumStart(0x24C);
                break;
            }

            func_0802F1E8();
            func_08006290(5, 8, 20);
            func_08019050(30, 0xCC, 0x10000, 0x15E00);

            if (body->unk_34 & 4) {
                func_08014FDC(body->unk_04 - 0x1400, body->unk_08 + body->unk_0C - 0x1400, 1);
            } else {
                func_08014FDC(body->unk_04 + 0x1400, body->unk_08 + body->unk_0C - 0x1400, 0);
            }

            switch (work->unk_154) {
            case 0:
                if (body->unk_34 & 4) {
                    func_08011F78(0x99, body->unk_04 - 0x8000, body->unk_08, body->unk_0C,
                                  0x80, 0x100, 0x100);
                } else {
                    func_08011F78(0x99, body->unk_04 + 0x8000, body->unk_08, body->unk_0C,
                                  0x80, 0x100, 0x100);
                }
                break;
            case 1:
                if (body->unk_34 & 4) {
                    func_08011F78(0x9A, body->unk_04 - 0x8000, body->unk_08, body->unk_0C,
                                  0x80, 0x100, 0x100);
                } else {
                    func_08011F78(0x9A, body->unk_04 + 0x8000, body->unk_08, body->unk_0C,
                                  0x80, 0x100, 0x100);
                }
                break;
            case 2:
            default:
                if (body->unk_34 & 4) {
                    func_08011F78(0x9B, body->unk_04 - 0x8000, body->unk_08, body->unk_0C,
                                  0x80, 0x100, 0x100);
                } else {
                    func_08011F78(0x9B, body->unk_04 + 0x8000, body->unk_08, body->unk_0C,
                                  0x80, 0x100, 0x100);
                }
                break;
            }
            break;
        }

        if (AnimIsFinished(&work->unk_008)) {
            func_08019050(8, 256, gUnk_02039B84->unk_010, gUnk_02039B84->unk_014);
            work->unk_034 = 2;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    }

    if (work->unk_156 != 0) {
        AnimUpdate(&work->unk_008);
    }

    func_0801C6D4(&body->unk_04, &body->unk_08, &body->unk_0C, &body->unk_10);

    if (body->unk_0C > body->unk_10) {
        body->unk_0C = body->unk_10;
    }

    TaskPoolUpdate(&work->unk_020);
    return 1;
}

void task_smn_simba_2(SmnSimbaWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_150 == gUnk_02039B84->unk_024) {
        sclY = work->unk_150;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_150 >> 8;
    sclY = sclY * work->unk_150 >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_simba_3(SmnSimbaWork* work) {
    SmnObj* obj;

    obj = work->unk_155 != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_mushu_0(SmnMushuWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_153 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_114;
    } else {
        work->unk_153 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_114;
    }

    body->unk_04 = obj->unk_004;
    body->unk_08 = obj->unk_008;
    body->unk_0C = obj->unk_00C - 0x2200;
    body->unk_10 = obj->unk_010;

    if (obj->unk_034 & 4) {
        body->unk_34 = 4;
    } else {
        body->unk_34 = 0;
    }

    work->unk_152 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_09618038, 32);
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813EA7C, &work->unk_008, 0, 1, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 10;
    work->unk_154 = 0;
    work->unk_150 = 0;

    if (work->unk_153 != 0) {
        work->unk_158 = gUnk_02039B84->unk_07C;
    } else {
        work->unk_158 = gUnk_02039B9C->unk_07C;
    }

    m4aSongNumStart(0xAB);
    TaskPoolInit(&work->unk_020, 3);
}

u8 task_smn_mushu_1(SmnMushuWork* work) {
    SmnBody* body;
    SmnObj* obj;
    s32 px;
    s32 py;
    s32 pz;
    s32 x;
    s32 y;
    s32 z;
    s32 n;
    u16 v1;
    u16 v2;

    body = &work->unk_038;
    obj = work->unk_153 != 0 ? gUnk_02039B84 : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    px = body->unk_04;
    py = body->unk_08;
    pz = body->unk_0C;
    body->unk_04 = work->unk_158->unk_004;
    body->unk_08 = work->unk_158->unk_008;
    body->unk_0C = work->unk_158->unk_00C - 0x2200;

    if (work->unk_158->unk_034 & 4) {
        body->unk_34 |= 4;
    } else {
        body->unk_34 &= 0xFFFFFFFFFFFFFFFB;
    }

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x235);
        }

        func_080058FC(&work->unk_14C, 256, work->unk_14A);

        if (work->unk_14A > 0) {
            work->unk_148++;
            work->unk_14A--;
        } else {
            work->unk_034 = 3;
            work->unk_148 = 0;
            work->unk_154 = 1;
        }
        break;
    case 1:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x239);
        }

        func_080058FC(&work->unk_14C, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 3:
        func_08019068(gUnk_0813EA7C, &work->unk_008, 2, 0, work->unk_000);

        if (AnimIsFinished(&work->unk_008)) {
            work->unk_034 = 2;
            work->unk_148 = 0;
        }
        break;
    case 2:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EA7C, &work->unk_008, 3, 1, work->unk_000);

            switch (work->unk_152) {
            case 0:
                work->unk_14A = 0x78;
                break;
            case 1:
                work->unk_14A = 0xF0;
                break;
            case 2:
            default:
                work->unk_14A = 0x1E0;
                break;
            }
        }

        if (func_08005B38(&work->unk_008) == 5 && work->unk_008.unk_0A == 0) {
            if (body->unk_34 & 4) {
                x = body->unk_04 - 0xC800;
            } else {
                x = body->unk_04 + 0xC800;
            }

            y = body->unk_08;
            z = 0;

            switch (work->unk_152) {
            case 0:
                n = 0x9D;
                break;
            case 1:
                n = 0x9E;
                break;
            case 2:
            default:
                n = 0x9F;
                break;
            }

            func_08019A30();
            m4aSongNumStart(0x24D);

            if (body->unk_34 & 4) {
                func_08012E44(0, body->unk_04 - 0x3800, body->unk_08, body->unk_0C - 0x800,
                              x, y, z, 1, n);
            } else {
                func_08012E44(0, body->unk_04 + 0x3800, body->unk_08, body->unk_0C - 0x800,
                              x, y, z, 0, n);
            }
        }

        func_08006B80(&v1, &v2);

        if (v1 <= 3) {
            func_0801475C(body->unk_04 - px, body->unk_08 - py, body->unk_0C - pz);
        }

        if (work->unk_148 > work->unk_14A) {
            work->unk_034 = 1;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    }

    if (work->unk_154 != 0) {
        AnimUpdate(&work->unk_008);
    }

    TaskPoolUpdate(&work->unk_020);
    return 1;
}

void task_smn_mushu_2(SmnMushuWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_14C == gUnk_02039B84->unk_024) {
        sclY = work->unk_14C;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_14C >> 8;
    sclY = sclY * work->unk_14C >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4101 - ((body->unk_08 >> 8) * 4));
    TaskPoolDraw(&work->unk_020);
}

void task_smn_mushu_3(SmnMushuWork* work) {
    SmnObj* obj;

    obj = work->unk_153 != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_dumbo_0(SmnDumboWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_155 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_110;
    } else {
        work->unk_155 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B9C->unk_110;
    }

    body->unk_04 = obj->unk_014;
    body->unk_08 = obj->unk_018;
    body->unk_0C = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->unk_34 = 0x20004;
    } else {
        body->unk_34 = 0x20000;
    }

    work->unk_154 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_09617F98, 32);
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813EADC, &work->unk_008, 0, 0, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_150 = 10;
    work->unk_156 = 0;
    TaskPoolInit(&work->unk_020, 1);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

u8 task_smn_dumbo_1(SmnDumboWork* work) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;
    obj = work->unk_155 != 0 ? gUnk_02039B84 : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    func_0802F284(body->unk_04, body->unk_08, body->unk_0C);

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x235);
        }

        func_080058FC(&work->unk_150, 256, work->unk_14A);

        if (work->unk_14A > 0) {
            work->unk_148++;
            work->unk_14A--;
        } else {
            work->unk_034 = 2;
            work->unk_148 = 0;
            work->unk_156 = 1;
        }
        break;
    case 1:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->unk_04, body->unk_08, body->unk_0C);
            m4aSongNumStart(0x239);
        }

        func_080058FC(&work->unk_150, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 2:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EADC, &work->unk_008, 0, 0, work->unk_000);
        }

        if (AnimIsFinished(&work->unk_008)) {
            work->unk_034 = 3;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    case 3:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EADC, &work->unk_008, 1, 1, work->unk_000);

            if (body->unk_34 & 4) {
                func_08015B50(work->unk_154, body->unk_04 - 0x1C00, body->unk_08,
                              body->unk_0C - 0x1B00, 0, 0x9C);
            } else {
                func_08015B50(work->unk_154, body->unk_04 + 0x1C00, body->unk_08,
                              body->unk_0C - 0x1B00, 1, 0x9C);
            }

            m4aSongNumStart(0x24E);
        } else if (func_080128EC() == 0) {
            m4aSongNumStop(0x24E);
            work->unk_034 = 4;
            work->unk_148 = 0;
            break;
        }

        work->unk_148++;
        break;
    case 4:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EADC, &work->unk_008, 2, 0, work->unk_000);
        }

        if (AnimIsFinished(&work->unk_008)) {
            work->unk_034 = 1;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    }

    if (work->unk_156 != 0) {
        AnimUpdate(&work->unk_008);
    }

    func_0801C6D4(&body->unk_04, &body->unk_08, &body->unk_0C, &body->unk_10);

    if (body->unk_0C > body->unk_10) {
        body->unk_0C = body->unk_10;
    }

    TaskPoolUpdate(&work->unk_020);
    return 1;
}

void task_smn_dumbo_2(SmnDumboWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_150 == gUnk_02039B84->unk_024) {
        sclY = work->unk_150;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_150 >> 8;
    sclY = sclY * work->unk_150 >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_dumbo_3(SmnDumboWork* work) {
    SmnObj* obj;

    obj = work->unk_155 != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    m4aSongNumStop(0x24E);
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_genie_0(SmnGenieWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_151 = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_110;
    } else {
        work->unk_151 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B9C->unk_110;
    }

    if (obj->unk_034 & 4) {
        body->unk_34 = 0x20004;
        body->unk_04 = obj->unk_014 + 0x3700;
    } else {
        body->unk_34 = 0x20000;
        body->unk_04 = obj->unk_014 - 0x3700;
    }

    body->unk_08 = obj->unk_018;
    body->unk_0C = obj->unk_01C - 0x2800;
    body->unk_10 = obj->unk_01C;
    work->unk_150 = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_09618298, 32);
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813EB1C, &work->unk_008, 0, 0, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 10;
    work->unk_152 = 0;
    work->unk_160 = 0;
    work->unk_164 = 0;

    switch (args->unk_00) {
    case 0:
        work->unk_15A = 1;
        break;
    case 1:
        work->unk_15A = 2;
        break;
    case 2:
    default:
        work->unk_15A = 3;
        break;
    }

    work->unk_158 = 0;
    TaskPoolInit(&work->unk_020, 1);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

SmnObj* func_08044450(SmnGenieWork* work) {
    SmnObj* list[10];
    SmnObj* p;
    s16 count;

    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_151 != 0) {
            p = gUnk_02039B9C->unk_07C;
        } else {
            p = gUnk_02039B84->unk_07C;
        }

        if (p->unk_02C <= 0) {
            return 0;
        }

        return p;
    }

    count = 0;
    p = func_08000C8C(gUnk_02039B84->unk_080);

    while (p != 0) {
        if (!(p->unk_034 & 0x01000000)) {
            list[count] = p;
            count++;
            if (count > 9) {
                break;
            }
        }
        p = func_08000CD4(&p->unk_0B8);
    }

    if (count == 0) {
        return 0;
    }

    p = list[work->unk_158 % count];
    work->unk_158++;
    return p;
}

void func_08044518(SmnGenieWork* work) {
    SmnBody* body;
    SmnObj* obj;
    s32 tx;
    s32 ty;
    s32 zt;
    s32 v;
    s32 lim;

    obj = work->unk_154;
    body = &work->unk_038;

    if (obj == 0) {
        return;
    }

    if (obj->unk_004 < body->unk_04) {
        body->unk_34 |= 4;
    } else {
        body->unk_34 &= 0xFFFFFFFFFFFFFFFB;
    }

    if (obj->unk_004 > 0x10000) {
        tx = obj->unk_004 - 0x3700;
    } else {
        tx = obj->unk_004 + 0x3700;
    }

    ty = obj->unk_008;
    zt = body->unk_10 - 0x200;
    v = (tx - body->unk_04) >> 3;
    lim = work->unk_160;

    if (v > lim) {
        v = lim;
        work->unk_160 = lim + 0x4C;
    } else if (v < -lim) {
        v = -lim;
        work->unk_160 = lim + 0x4C;
    } else {
        work->unk_160 = abs(v);
    }

    body->unk_04 += v;
    v = (ty - body->unk_08) >> 3;
    lim = work->unk_164;

    if (v > lim) {
        v = lim;
        work->unk_164 = lim + 0x4C;
    } else if (v < -lim) {
        v = -lim;
        work->unk_164 = lim + 0x4C;
    } else {
        work->unk_164 = abs(v);
    }

    body->unk_08 += v;
    body->unk_0C += (zt - gSineTable[(work->unk_148 * 2) & 0xFF] * 8 - body->unk_0C) >> 3;
}
INCLUDE_ASM("smn/task_smn_genie_1.s");

void task_smn_genie_2(SmnGenieWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_14C == gUnk_02039B84->unk_024) {
        sclY = work->unk_14C;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_14C >> 8;
    sclY = sclY * work->unk_14C >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_genie_3(SmnGenieWork* work) {
    gUnk_02039B84->unk_068 |= 0x40000;

    if (work->unk_151 != 0) {
        gUnk_02039B84->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    } else {
        gUnk_02039B9C->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    }

    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_king_0(SmnKingWork* work, SmnArgs* args) {
    SmnBody* body;
    SmnObj* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_15D = 1;
        gUnk_02039B84->unk_068 |= 0x200000;
        obj = gUnk_02039B84->unk_07C;
        work->unk_000 = gUnk_02039B84->unk_110;
    } else {
        work->unk_15D = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->unk_000 = gUnk_02039B9C->unk_110;
    }

    body->unk_04 = obj->unk_014;
    body->unk_08 = obj->unk_018;
    body->unk_0C = obj->unk_01C - 0x4000;
    body->unk_10 = 0;
    body->unk_34 = obj->unk_034 & 4;
    work->unk_15C = args->unk_00;
    work->unk_004 = LoadObjPalette(gUnk_096183F8, 32);
    work->unk_158 = 0;
    AnimInit(&work->unk_008, 0, 0);
    func_08019068(gUnk_0813EB4C, &work->unk_008, 0, 0, work->unk_000);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_154 = 10;
    work->unk_15E = 0;
    TaskPoolInit(&work->unk_020, 1);
    TaskCreate(&work->unk_020, gUnk_09EDAE88, body);
}

u8 func_08044F98(SmnKingWork* work) {
    SmnBody* body;

    body = &work->unk_038;
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

INCLUDE_ASM("smn/task_smn_king_1.s");

void task_smn_king_2(SmnKingWork* work) {
    SmnBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_038;
    gfx = AnimGetGfx(&work->unk_008);
    flags = func_0801AF1C(body->unk_08);

    if (body->unk_34 & 4) {
        sclY = gUnk_02039B84->unk_024;
        sclX = sclY;
    } else if (gUnk_02039B84->unk_024 == 256 && work->unk_154 == gUnk_02039B84->unk_024) {
        sclY = work->unk_154;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gUnk_02039B84->unk_024;
        sclY = gUnk_02039B84->unk_024;
    }

    sclX = sclX * work->unk_154 >> 8;
    sclY = sclY * work->unk_154 >> 8;

    WorldToScreen(&sx, &sy, body->unk_04, body->unk_08, body->unk_0C);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->unk_000, work->unk_004, affine, flags,
               -4100 - ((body->unk_08 >> 8) * 4));
    body->unk_CC = (-4100 - ((body->unk_08 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_king_3(SmnKingWork* work) {
    SmnObj* obj;

    obj = work->unk_15D != 0 ? gUnk_02039B84 : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->unk_004);
    TaskPoolDestroy(&work->unk_020);
}

u8 func_0804544C(SmnFrdWork* work) {
    SmnBody* body;

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

#ifdef NON_MATCHING
void func_08045494(SmnBody* body, u8 a, s16 b, s16 c) {
    s32 x;
    s32 y;
    s32 z;
    s32 w;
    s32 t;
    s32 p;
    s32 q;
    s32 r;

    y = body->unk_08;
    z = body->unk_0C - (c << 8);
    w = 0x180;

    if (body->unk_34 & 4) {
        x = body->unk_04 + (b << 8);
        t = -0x180;
    } else {
        x = body->unk_04 - (b << 8);
        t = w;
    }

    func_08014780(x, y, z);
    func_080147C8(t, w);

    if (a != 0) {
        if (gUnk_02039B84->unk_10C == 0x98) {
            r = 0x30;
            q = 0x20;
            p = 0x20;
        } else {
            r = 0x0A;
            q = 0x0A;
            p = 0x0A;
        }

        if (func_08011F78(0x84, x, y, z, p, q, r) != 0) {
            m4aSongNumStart(0x1F9);
        }
    }
}
#else
INCLUDE_ASM("smn/func_08045494.s");
#endif
