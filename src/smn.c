#include "smn.h"
#include "macros.h"

void task_smn_cloud_0(SmnCloudWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_163 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_110;
    } else {
        work->unk_163 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gUnk_02039B9C->unk_110;
    }

    body->x = obj->unk_014;
    body->y = obj->unk_018;
    body->z = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->flags = 4;
    } else {
        body->flags = 0;
    }

    work->unk_162 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_08F6DC24, 32);
    work->unk_15C = 0;
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813E958, &work->anim, 0, 0, work->tiles);
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
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);
    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (work->unk_150 == 256 && work->unk_154 == work->unk_150) {
        if (body->flags & 4) {
            sclY = gBtlWork->unk_024;
            sclX = sclY;
        } else if (gBtlWork->unk_024 == work->unk_154) {
            sclY = gBtlWork->unk_024;
            sclX = sclY;
            flags |= 1;
        } else {
            sclY = gBtlWork->unk_024;
            sclX = -sclY;
        }
    } else if (body->flags & 4) {
        sclX = gBtlWork->unk_024 * work->unk_150 >> 8;
        sclY = gBtlWork->unk_024 * work->unk_154 >> 8;
    } else {
        sclX = -(gBtlWork->unk_024 * work->unk_150 >> 8);
        sclY = gBtlWork->unk_024 * work->unk_154 >> 8;
    }

    if (sclY == 256 && sclX == sclY) {
        affine = 0;
    } else if (sclY <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_cloud_3(SmnCloudWork* work) {
    BtlWork* obj;

    obj = work->unk_163 != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

void func_08041D64(SmnBambiWork* work) {
    work->unk_170 = work->unk_038.x + gSineTable[work->unk_158] * 80;
    work->unk_174 = work->unk_038.y + -gSineTable[work->unk_158 + 0x40] * 40;
    work->unk_158 += GetRandom() % 0x21 + 0x20;

    if (work->unk_170 - work->unk_038.x > 0) {
        work->unk_038.flags |= 4;
    } else {
        work->unk_038.flags &= 0xFFFFFFFFFFFFFFFB;
    }
}

void task_smn_bambi_0(SmnBambiWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_163 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_163 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    body->x = (gBtlWork->unk_0DA
                    + GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA + 1)) << 8;
    body->y = (gBtlWork->unk_0DE
                    + GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE + 1)) << 8;
    body->z = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->flags = 0;
        work->unk_158 = 0xC0;
    } else {
        body->flags = 4;
        work->unk_158 = 0x40;
    }

    work->unk_162 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_09617FF8, 32);
    work->unk_15C = 0;
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813E9E8, &work->anim, 0, 0, work->tiles);
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
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
}

u8 func_08041FCC(SmnBambiWork* work) {
    SmnBody* body;

    body = &work->unk_038;
    body->unk_10 = 0;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);
    body->z += work->unk_15C;
    work->unk_15C += 0x33;

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
        work->unk_15C = 0;
        return 1;
    }

    return 0;
}

BtlWork* func_08042018(SmnBambiWork* work) {
    BtlWork* list[10];
    BtlWork* p;
    s16 count;

    if (gBtlWork->unk_068 & 0x4000) {
        if (work->unk_163 != 0) {
            p = gUnk_02039B9C->unk_07C;
        } else {
            p = gBtlWork->unk_07C;
        }

        if (p->unk_02C <= 0) {
            return 0;
        }

        return p;
    }

    count = 0;
    p = ListPoolFirst(gBtlWork->unk_080);

    while (p != 0) {
        if (!(p->unk_034 & 0x01000000)) {
            list[count] = p;
            count++;
            if (count > 9) {
                break;
            }
        }
        p = ListPoolNext(&p->unk_0B8);
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
    BtlWork* obj;
    SmnPrizeArgs args;

    body = &work->unk_038;
    obj = work->unk_163 != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    switch (work->unk_034) {
    case 0:
        if (work->unk_163 != 0) {
            func_0802F284(body->x, body->y, body->z);
        }

        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x235);
        }

        ApproachValue(&work->unk_154, 256, work->unk_14A);

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
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x239);
        }

        do {
            ApproachValue(&work->unk_154, 25, work->unk_14A);
        } while (0);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 2:
        if (work->unk_148 == 0) {
            AnimStart(&work->anim, 0, 0);
            work->unk_15C = -0x480;
            m4aSongNumStart(0x236);
            work->unk_168 = func_08042018(work);
            work->unk_14A = 0;
        }

        if (work->unk_15C > 0) {
            func_08019A30();

            if (func_08011F78(0x76, body->x, body->y, body->z - 0x400, 8, 8, 2) != 0) {
                func_0801416C(body->x, body->y, body->z);
                AnimStart(&work->anim, 0, 0);
                work->unk_15C = -0x400;
                m4aSongNumStart(0x236);
                m4aSongNumStart(0x28D);
                work->unk_168 = func_08042018(work);
                work->unk_14A++;
            }
        }

        if (func_08041FCC(work)) {
            AnimStart(&work->anim, 0, 0);
            work->unk_15C = -0x480;
            m4aSongNumStart(0x236);
            work->unk_168 = func_08042018(work);
            work->unk_14A++;
        }

        if ((work->unk_15C > 0 && work->unk_14A > 7) || work->unk_168 == 0) {
            work->unk_034 = 3;
            work->unk_148 = 0;
        } else {
            if (body->x < work->unk_168->unk_004) {
                body->flags |= 4;
            } else {
                body->flags &= 0xFFFFFFFFFFFFFFFB;
            }

            body->x += (work->unk_168->unk_004 - body->x) >> 4;
            body->y += (work->unk_168->unk_008 - body->y) >> 4;
            func_0801A8A4(&body->x, &body->y, -16, 0);
            work->unk_148++;
        }
        break;
    case 1:
        if (work->unk_14C == 0) {
            AnimStart(&work->anim, 0, 0);
            func_08041D64(work);
            work->unk_14A = 30;
        }

        if (work->unk_162 == 2) {
            func_08011F78(0x75, body->x, body->y, body->z, 8, 8, 8);
        } else {
            func_08011F78(0x74, body->x, body->y, body->z, 8, 8, 8);
        }

        if (work->unk_14C > 4) {
            if (work->unk_14C == 5) {
                work->unk_15C = -0x300;
                m4aSongNumStart(0x236);
            }

            if (work->unk_14A > 0) {
                func_0800592C(&body->x, work->unk_170, work->unk_14A);
                func_0800592C(&body->y, work->unk_174, work->unk_14A);
                work->unk_14A--;
            }
        }

        func_08041FCC(work);
        func_0801A8A4(&body->x, &body->y, -16, 0);

        if (AnimIsFinished(&work->anim)) {
            work->unk_14C = 0;
            work->unk_148++;
            args.x = body->x;
            args.y = body->y;
            args.z = body->z;

            if (work->unk_162 == 0) {
                args.unk_12 = 1;
            } else {
                args.unk_12 = 2;
            }

            args.unk_14 = 0;
            TaskCreate((TaskPool*)&gBtlWork->unk_02C, gTaskDescBtlPrize, &args);
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
        AnimUpdate(&work->anim);
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_154 == gBtlWork->unk_024) {
        sclY = work->unk_154;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_154 >> 8;
    sclY = sclY * work->unk_154 >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_bambi_3(SmnBambiWork* work) {
    BtlWork* obj;

    obj = work->unk_163 != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_tink_0(SmnTinkWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;
    s32 t;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_153 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_153 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    body->x = obj->unk_014;
    body->y = obj->unk_018;
    body->z = obj->unk_01C - 0x3000;
#ifdef VERSION_EU
    body->unk_10 = 0;
#else
    body->unk_10 = obj->unk_01C;
#endif

    if (obj->unk_034 & 4) {
        body->flags = 0x80004;
    } else {
        body->flags = 0x80000;
    }

    work->unk_152 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_09618098, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EA08, &work->anim, 0, 1, work->tiles);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 10;
    work->unk_154 = 0;
    work->unk_150 = 0;
    work->unk_16C = 0;
    work->unk_170 = 0;

    if (work->unk_153 != 0) {
        work->unk_17C = gBtlWork->unk_07C;
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
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
}

void func_080428E8(SmnTinkWork* work) {
    if (work->unk_170 % 3 == 0) {
        TaskCreate(&work->unk_020, gTaskDescSmnTinkeff, &work->unk_038);
    }
}
#ifdef NON_MATCHING
u8 task_smn_tink_1(SmnTinkWork* work) {
    SmnBody* body;
    BtlWork* obj;
    BtlWork* p;
    s32 x;
    s32 y;
    s32 z;
    s32 d;
    s32 i;
    s32 t;

    body = &work->unk_038;
    obj = work->unk_153 != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    if (work->unk_16E <= 0) {
        if (work->unk_034 != 1) {
            work->unk_034 = 1;
            work->unk_148 = 0;
        }
    } else {
        ApproachValue(&work->unk_178, work->unk_174, work->unk_16E);
        work->unk_17C->unk_02C = work->unk_178 >> 8;
        work->unk_16E--;
    }

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x235);
        }

        ApproachValue(&work->unk_14C, 256, work->unk_14A);

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
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x239);
        }

        ApproachValue(&work->unk_14C, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 2:
        func_080428E8(work);

        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EA08, &work->anim, 0, 1, work->tiles);
            work->unk_160 = body->z;
            work->unk_14A = 30;
        } else {
            body->z += (work->unk_160 + gSineTable[work->unk_148 & 0xFF] * 12
                             - body->z) >> 2;
        }

        if (work->unk_17C->unk_004 < body->x) {
            body->flags |= 4;
        } else {
            body->flags &= 0xFFFFFFFFFFFFFFFB;
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
            func_08019068(gUnk_0813EA08, &work->anim, 1, 1, work->tiles);
        }

        p = work->unk_17C;
        i = (u16)work->unk_148 * 4 & 0xFF;
        x = p->unk_004 + gSineTable[i] * 32;
        y = p->unk_008 - gSineTable[i + 0x40] * 16;
        z = gSineTable[(u16)work->unk_148 * 2 & 0xFF] * 16 - 0x1E00 + p->unk_00C;

        if (x < body->x) {
            body->flags |= 4;
        } else {
            body->flags &= 0xFFFFFFFFFFFFFFFB;
        }

        d = (x - body->x) >> 3;

        if (d > 0x400) {
            d = 0x400;
        } else if (d < -0x400) {
            d = -0x400;
        }

        body->x += d;
        d = (y - body->y) >> 3;

        if (d > 0x200) {
            d = 0x200;
        } else if (d < -0x200) {
            d = -0x200;
        }

        body->y += d;
        body->z += (z - body->z) >> 3;
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
            func_08019068(gUnk_0813EA08, &work->anim, 2, 0, work->tiles);

            if (body->flags & 4) {
                work->unk_16C = 0xC0;
            } else {
                work->unk_16C = 0x40;
            }
        }

        body->x += gSineTable[(u8)work->unk_16C] * work->unk_168 >> 8;
        body->z += -gSineTable[(u8)work->unk_16C + 0x40] * work->unk_168 >> 8;

        if (body->flags & 4) {
            work->unk_16C += 7;
        } else {
            work->unk_16C -= 7;
        }

        if (AnimIsFinished(&work->anim)) {
            func_08019068(gUnk_0813EA08, &work->anim, 1, 1, work->tiles);
            work->unk_034 = 3;
            work->unk_148 = 1;
        } else {
            work->unk_148++;
        }
        break;
    }

    func_0801A8A4(&body->x, &body->y, -16, 0);

    if (work->unk_154 != 0) {
        AnimUpdate(&work->anim);
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_14C == gBtlWork->unk_024) {
        sclY = work->unk_14C;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_14C >> 8;
    sclY = sclY * work->unk_14C >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_tink_3(SmnTinkWork* work) {
    BtlWork* obj;

    obj = work->unk_153 != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    m4aSongNumStop(0x24F);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

#ifdef NON_MATCHING
void task_smn_tinkeff_0(SmnTinkeffWork* work, SmnBody* args) {
    work->x = args->x + ((GetRandom() % 9) << 8) - 0x400;
    work->y = args->y + ((GetRandom() % 9) << 8) - 0x400;
    work->z = args->z;
    work->unk_2C = GetRandom() % 0xE8 + 0x4C;
    work->tiles = LoadObjTiles(gUnk_088A5D7A, 0x200);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    AnimInit(&work->anim, gUnk_09EDE7E4, gUnk_09EDE7B4);

    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->anim, 0, 1);
        break;
    case 1:
        AnimStart(&work->anim, 1, 1);
        break;
    case 2:
        AnimStart(&work->anim, 2, 1);
        break;
    }
}
#else
INCLUDE_ASM("smn/task_smn_tinkeff_0.s");
#endif

u8 task_smn_tinkeff_1(SmnTinkeffWork* work) {
    work->z += work->unk_2C;

    if (AnimIsFinished(&work->anim)) {
        return 0;
    }

    AnimUpdate(&work->anim);
    return 1;
}

void task_smn_tinkeff_2(SmnTinkeffWork* work) {
    void* gfx;
    s16 sx;
    s16 sy;

    gfx = AnimGetGfx(&work->anim);
    WorldToScreen(&sx, &sy, work->x, work->y, work->z);
    DrawSprite(sx, sy, gfx, work->tiles, work->palette, 0, 0x800,
               -4100 - ((work->y >> 8) * 4));
}

void task_smn_tinkeff_3(SmnTinkeffWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_smn_simba_0(SmnSimbaWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_155 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_110;
    } else {
        work->unk_155 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gUnk_02039B9C->unk_110;
    }

    body->x = obj->unk_014;
    body->y = obj->unk_018;
    body->z = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->flags = 0x20004;
    } else {
        body->flags = 0x20000;
    }

    work->unk_154 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_09618018, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EA5C, &work->anim, 0, 0, work->tiles);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_150 = 10;
    work->unk_156 = 0;
    TaskPoolInit(&work->unk_020, 2);
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
}

u8 task_smn_simba_1(SmnSimbaWork* work) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;
    obj = work->unk_155 != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        do {
            return 0;
        } while (0);
    }

    func_0802F284(body->x, body->y, body->z);

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x235);
        }

        ApproachValue(&work->unk_150, 256, work->unk_14A);

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
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x239);
        }

        ApproachValue(&work->unk_150, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 1:
        switch (work->unk_148) {
        case 0:
            if (body->flags & 4) {
                func_08019050(30, 0x133, body->x - 0x1400,
                              body->y + body->z - 0x1400);
            } else {
                func_08019050(30, 0x133, body->x + 0x1400,
                              body->y + body->z - 0x1400);
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

            if (body->flags & 4) {
                func_08014FDC(body->x - 0x1400, body->y + body->z - 0x1400, 1);
            } else {
                func_08014FDC(body->x + 0x1400, body->y + body->z - 0x1400, 0);
            }

            switch (work->unk_154) {
            case 0:
                if (body->flags & 4) {
                    func_08011F78(0x99, body->x - 0x8000, body->y, body->z,
                                  0x80, 0x100, 0x100);
                } else {
                    func_08011F78(0x99, body->x + 0x8000, body->y, body->z,
                                  0x80, 0x100, 0x100);
                }
                break;
            case 1:
                if (body->flags & 4) {
                    func_08011F78(0x9A, body->x - 0x8000, body->y, body->z,
                                  0x80, 0x100, 0x100);
                } else {
                    func_08011F78(0x9A, body->x + 0x8000, body->y, body->z,
                                  0x80, 0x100, 0x100);
                }
                break;
            case 2:
            default:
                if (body->flags & 4) {
                    func_08011F78(0x9B, body->x - 0x8000, body->y, body->z,
                                  0x80, 0x100, 0x100);
                } else {
                    func_08011F78(0x9B, body->x + 0x8000, body->y, body->z,
                                  0x80, 0x100, 0x100);
                }
                break;
            }
            break;
        }

        if (AnimIsFinished(&work->anim)) {
            func_08019050(8, 256, gBtlWork->unk_010, gBtlWork->unk_014);
            work->unk_034 = 2;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    }

    if (work->unk_156 != 0) {
        AnimUpdate(&work->anim);
    }

    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_150 == gBtlWork->unk_024) {
        sclY = work->unk_150;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_150 >> 8;
    sclY = sclY * work->unk_150 >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_simba_3(SmnSimbaWork* work) {
    BtlWork* obj;

    obj = work->unk_155 != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_mushu_0(SmnMushuWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_153 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_153 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    body->x = obj->unk_004;
    body->y = obj->unk_008;
    body->z = obj->unk_00C - 0x2200;
    body->unk_10 = obj->unk_010;

    if (obj->unk_034 & 4) {
        body->flags = 4;
    } else {
        body->flags = 0;
    }

    work->unk_152 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_09618038, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EA7C, &work->anim, 0, 1, work->tiles);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 10;
    work->unk_154 = 0;
    work->unk_150 = 0;

    if (work->unk_153 != 0) {
        work->unk_158 = gBtlWork->unk_07C;
    } else {
        work->unk_158 = gUnk_02039B9C->unk_07C;
    }

    m4aSongNumStart(0xAB);
    TaskPoolInit(&work->unk_020, 3);
}

u8 task_smn_mushu_1(SmnMushuWork* work) {
    SmnBody* body;
    BtlWork* obj;
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
    obj = work->unk_153 != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    px = body->x;
    py = body->y;
    pz = body->z;
    body->x = work->unk_158->unk_004;
    body->y = work->unk_158->unk_008;
    body->z = work->unk_158->unk_00C - 0x2200;

    if (work->unk_158->unk_034 & 4) {
        body->flags |= 4;
    } else {
        body->flags &= 0xFFFFFFFFFFFFFFFB;
    }

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x235);
        }

        ApproachValue(&work->unk_14C, 256, work->unk_14A);

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
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x239);
        }

        ApproachValue(&work->unk_14C, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 3:
        func_08019068(gUnk_0813EA7C, &work->anim, 2, 0, work->tiles);

        if (AnimIsFinished(&work->anim)) {
            work->unk_034 = 2;
            work->unk_148 = 0;
        }
        break;
    case 2:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EA7C, &work->anim, 3, 1, work->tiles);

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

        if (AnimGetGfxIndex(&work->anim) == 5 && work->anim.timer == 0) {
            if (body->flags & 4) {
                x = body->x - 0xC800;
            } else {
                x = body->x + 0xC800;
            }

            y = body->y;
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

            if (body->flags & 4) {
                func_08012E44(0, body->x - 0x3800, body->y, body->z - 0x800,
                              x, y, z, 1, n);
            } else {
                func_08012E44(0, body->x + 0x3800, body->y, body->z - 0x800,
                              x, y, z, 0, n);
            }
        }

        func_08006B80(&v1, &v2);

        if (v1 <= 3) {
            func_0801475C(body->x - px, body->y - py, body->z - pz);
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
        AnimUpdate(&work->anim);
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_14C == gBtlWork->unk_024) {
        sclY = work->unk_14C;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_14C >> 8;
    sclY = sclY * work->unk_14C >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4101 - ((body->y >> 8) * 4));
    TaskPoolDraw(&work->unk_020);
}

void task_smn_mushu_3(SmnMushuWork* work) {
    BtlWork* obj;

    obj = work->unk_153 != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_dumbo_0(SmnDumboWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_155 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_110;
    } else {
        work->unk_155 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gUnk_02039B9C->unk_110;
    }

    body->x = obj->unk_014;
    body->y = obj->unk_018;
    body->z = obj->unk_01C;
    body->unk_10 = obj->unk_01C;

    if (obj->unk_034 & 4) {
        body->flags = 0x20004;
    } else {
        body->flags = 0x20000;
    }

    work->unk_154 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_09617F98, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EADC, &work->anim, 0, 0, work->tiles);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_150 = 10;
    work->unk_156 = 0;
    TaskPoolInit(&work->unk_020, 1);
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
}

u8 task_smn_dumbo_1(SmnDumboWork* work) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;
    obj = work->unk_155 != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->unk_068 & 0x40000000) {
        return 0;
    }

    func_0802F284(body->x, body->y, body->z);

    switch (work->unk_034) {
    case 0:
        if (work->unk_148 == 0) {
            work->unk_14A = 30;
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x235);
        }

        ApproachValue(&work->unk_150, 256, work->unk_14A);

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
            func_080140E0(body->x, body->y, body->z);
            m4aSongNumStart(0x239);
        }

        ApproachValue(&work->unk_150, 25, work->unk_14A);

        if (work->unk_14A <= 0) {
            return 0;
        }

        work->unk_148++;
        work->unk_14A--;
        break;
    case 2:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EADC, &work->anim, 0, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_034 = 3;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    case 3:
        if (work->unk_148 == 0) {
            func_08019068(gUnk_0813EADC, &work->anim, 1, 1, work->tiles);

            if (body->flags & 4) {
                func_08015B50(work->unk_154, body->x - 0x1C00, body->y,
                              body->z - 0x1B00, 0, 0x9C);
            } else {
                func_08015B50(work->unk_154, body->x + 0x1C00, body->y,
                              body->z - 0x1B00, 1, 0x9C);
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
            func_08019068(gUnk_0813EADC, &work->anim, 2, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_034 = 1;
            work->unk_148 = 0;
        } else {
            work->unk_148++;
        }
        break;
    }

    if (work->unk_156 != 0) {
        AnimUpdate(&work->anim);
    }

    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_10);

    if (body->z > body->unk_10) {
        body->z = body->unk_10;
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_150 == gBtlWork->unk_024) {
        sclY = work->unk_150;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_150 >> 8;
    sclY = sclY * work->unk_150 >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_dumbo_3(SmnDumboWork* work) {
    BtlWork* obj;

    obj = work->unk_155 != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    m4aSongNumStop(0x24E);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_genie_0(SmnGenieWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_151 = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_110;
    } else {
        work->unk_151 = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gUnk_02039B9C->unk_110;
    }

    if (obj->unk_034 & 4) {
        body->flags = 0x20004;
        body->x = obj->unk_014 + 0x3700;
    } else {
        body->flags = 0x20000;
        body->x = obj->unk_014 - 0x3700;
    }

    body->y = obj->unk_018;
    body->z = obj->unk_01C - 0x2800;
    body->unk_10 = obj->unk_01C;
    work->unk_150 = args->unk_00;
    work->palette = LoadObjPalette(gUnk_09618298, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EB1C, &work->anim, 0, 0, work->tiles);
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
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
}

BtlWork* func_08044450(SmnGenieWork* work) {
    BtlWork* list[10];
    BtlWork* p;
    s16 count;

    if (gBtlWork->unk_068 & 0x4000) {
        if (work->unk_151 != 0) {
            p = gUnk_02039B9C->unk_07C;
        } else {
            p = gBtlWork->unk_07C;
        }

        if (p->unk_02C <= 0) {
            return 0;
        }

        return p;
    }

    count = 0;
    p = ListPoolFirst(gBtlWork->unk_080);

    while (p != 0) {
        if (!(p->unk_034 & 0x01000000)) {
            list[count] = p;
            count++;
            if (count > 9) {
                break;
            }
        }
        p = ListPoolNext(&p->unk_0B8);
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
    BtlWork* obj;
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

    if (obj->unk_004 < body->x) {
        body->flags |= 4;
    } else {
        body->flags &= 0xFFFFFFFFFFFFFFFB;
    }

    if (obj->unk_004 > 0x10000) {
        tx = obj->unk_004 - 0x3700;
    } else {
        tx = obj->unk_004 + 0x3700;
    }

    ty = obj->unk_008;
    zt = body->unk_10 - 0x200;
    v = (tx - body->x) >> 3;
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

    body->x += v;
    v = (ty - body->y) >> 3;
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

    body->y += v;
    body->z += (zt - gSineTable[(work->unk_148 * 2) & 0xFF] * 8 - body->z) >> 3;
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_14C == gBtlWork->unk_024) {
        sclY = work->unk_14C;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_14C >> 8;
    sclY = sclY * work->unk_14C >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_genie_3(SmnGenieWork* work) {
    gBtlWork->unk_068 |= 0x40000;

    if (work->unk_151 != 0) {
        gBtlWork->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    } else {
        gUnk_02039B9C->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    }

    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

void task_smn_king_0(SmnKingWork* work, SmnArgs* args) {
    SmnBody* body;
    BtlWork* obj;

    body = &work->unk_038;

    if (args->unk_02 != 0) {
        work->unk_15D = 1;
        gBtlWork->unk_068 |= 0x200000;
        obj = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_110;
    } else {
        work->unk_15D = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        obj = gUnk_02039B9C->unk_07C;
        work->tiles = gUnk_02039B9C->unk_110;
    }

    body->x = obj->unk_014;
    body->y = obj->unk_018;
    body->z = obj->unk_01C - 0x4000;
    body->unk_10 = 0;
    body->flags = obj->unk_034 & 4;
    work->unk_15C = args->unk_00;
    work->palette = LoadObjPalette(gUnk_096183F8, 32);
    work->unk_158 = 0;
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EB4C, &work->anim, 0, 0, work->tiles);
    work->unk_034 = 0;
    work->unk_148 = 0;
    work->unk_14A = 0;
    work->unk_14C = 0;
    work->unk_154 = 10;
    work->unk_15E = 0;
    TaskPoolInit(&work->unk_020, 1);
    TaskCreate(&work->unk_020, gTaskDescBtlShadow, body);
}

u8 func_08044F98(SmnKingWork* work) {
    SmnBody* body;

    body = &work->unk_038;
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
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256 && work->unk_154 == gBtlWork->unk_024) {
        sclY = work->unk_154;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    sclX = sclX * work->unk_154 >> 8;
    sclY = sclY * work->unk_154 >> 8;

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (sclX <= 256 && sclY <= 256) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_020);
}

void task_smn_king_3(SmnKingWork* work) {
    BtlWork* obj;

    obj = work->unk_15D != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_020);
}

u8 func_0804544C(SmnFrdWork* work) {
    SmnBody* body;

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

    y = body->y;
    z = body->z - (c << 8);
    w = 0x180;

    if (body->flags & 4) {
        x = body->x + (b << 8);
        t = -0x180;
    } else {
        x = body->x - (b << 8);
        t = w;
    }

    func_08014780(x, y, z);
    func_080147C8(t, w);

    if (a != 0) {
        if (gBtlWork->unk_10C == 0x98) {
            p = 0x20;
            q = 0x20;
            r = 0x30;
        } else {
            p = 0x0A;
            q = 0x0A;
            r = 0x0A;
        }

        if (func_08011F78(0x84, x, y, z, p, q, r) != 0) {
            m4aSongNumStart(0x1F9);
        }
    }
}
#else
INCLUDE_ASM("smn/func_08045494.s");
#endif
