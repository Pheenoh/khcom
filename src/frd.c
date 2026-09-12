#include "display.h"
#include "frd.h"
#include "macros.h"

#ifdef VERSION_EU
extern u32 gLanguage;
#endif

void task_frd_donald_0(FrdDonaldWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->unk_020;

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0;
    }

    body->unk_008 = work->unk_014->unk_008;
    body->unk_00C = -0x5000;
    body->unk_010 = 0;
    work->palette = LoadObjPalette(gUnk_09617C58, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EB8C, &work->anim, 0, 0, work->tiles);

    switch (args->unk_00) {
    case 0:
        work->unk_160 = 1;
#ifdef VERSION_EU
        if (gLanguage == 3) {
            m4aSongNumStart(0xAB);
        } else {
            m4aSongNumStart(0xB4);
        }
#else
        m4aSongNumStart(0xB4);
#endif
        break;
    case 1:
        work->unk_160 = 1;
#ifdef VERSION_EU
        if (gLanguage == 3) {
            m4aSongNumStart(0xAB);
        } else {
            m4aSongNumStart(0xB4);
        }
#else
        m4aSongNumStart(0xB4);
#endif
        break;
    case 2:
        work->unk_160 = 1;
#ifdef VERSION_EU
        if (gLanguage == 3) {
            m4aSongNumStart(0xAB);
        } else {
            m4aSongNumStart(0xB4);
        }
#else
        m4aSongNumStart(0xB4);
#endif
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

u8 task_frd_donald_1(FrdDonaldWork* work) {
    BtlObj* body = &work->unk_020;
    BtlWork* owner;
    BtlObj* target;
    s32 angle;
    if (work->unk_14C != 0) {
        owner = gBtlWork;
        target = owner->unk_078;
    } else {
        owner = gUnk_02039B9C;
        target = owner->unk_078;
    }
    if (owner->unk_068 & 0x40000000) return 0;
    switch (work->unk_148) {
    case 0:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EB8C, &work->anim, 2, 0, work->tiles);
            work->unk_14E++;
        }
        body->unk_004 += (work->unk_158 - body->unk_004) >> 4;
        func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);
        if (work->unk_14D == 3) func_08045494(body, 0, 8, 8);
        if (func_0804544C(work)) {
            work->unk_14E = 0;
            if (work->unk_14D == 3) work->unk_148 = 8;
            else {
                work->unk_148 = 1;
                m4aSongNumStart(0xB3);
            }
        }
        break;
    case 1:
        if (work->unk_14E == 0) func_08019068(gUnk_0813EB8C, &work->anim, 3, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            func_0801D288();
            if (gBtlWork->unk_068 & 0x800000000ULL) work->unk_148 = 4;
            else {
                u16 spell = GetRandom();
                spell &= 3;
                switch (spell) {
                case 0:
                    work->unk_148 = 4;
                    break;
                case 1:
                    work->unk_148 = 5;
                    break;
                case 2:
                    work->unk_148 = 6;
                    break;
                case 3:
                    work->unk_148 = 7;
                    break;
                }
            }
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 2:
        if (work->unk_160 > 0) {
            func_0801D288();
            if (gBtlWork->unk_068 & 0x800000000ULL) work->unk_148 = 4;
            else {
                u16 spell = GetRandom();
                spell &= 3;
                switch (spell) {
                case 0:
                    work->unk_148 = 4;
                    break;
                case 1:
                    work->unk_148 = 5;
                    break;
                case 2:
                    work->unk_148 = 6;
                    break;
                case 3:
                    work->unk_148 = 7;
                    break;
                }
            }
            work->unk_14E = 0;
            work->unk_160--;
        } else {
            if (work->unk_14E == 0) func_08019068(gUnk_0813EB8C, &work->anim, 3, 0, work->tiles);
            if (AnimIsFinished(&work->anim)) {
                work->unk_148 = 3;
                work->unk_14E = 0;
            } else work->unk_14E++;
        }
        break;
    case 3:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EB8C, &work->anim, 2, 0, work->tiles);
            if (!(body->unk_034 & 4)) work->unk_158 = (gBtlWork->unk_0DA - 64) * 256;
            else work->unk_158 = (gBtlWork->unk_0DC + 64) * 256;
            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }
        ApproachValue(&body->unk_004, work->unk_158, work->unk_150);
        if (work->unk_14D == 3) func_08045494(body, 0, 8, 8);
        func_0804544C(work);
        if (work->unk_150 <= 0) {
            if (work->unk_14D == 3) func_08006B4C();
            return 0;
        }
        work->unk_14E++;
        work->unk_150--;
        break;
    case 8:
        if (work->unk_14E == 0) {
            if (body->unk_034 & 4) angle = GetRandom() % 2 ? 0xAD : 0xD3;
            else angle = GetRandom() % 2 ? 0x53 : 0x2D;
            work->unk_158 = gSineTable[angle] * 3;
            work->unk_15C = -gSineTable[angle + 64] * 3;
        }
        if (work->unk_15C > 0) func_08019068(gUnk_0813EB8C, &work->anim, 4, 1, work->tiles);
        else func_08019068(gUnk_0813EB8C, &work->anim, 5, 1, work->tiles);
        if (work->unk_158 < 0) body->unk_034 |= 4;
        else body->unk_034 &= ~4ULL;
        body->unk_004 += work->unk_158;
        body->unk_008 += work->unk_15C;
        func_0804544C(work);
        func_08045494(body, 1, 2, 8);
        switch (func_0801A8A4(&body->unk_004, &body->unk_008, 0, 0)) {
        case 1:
        case 2:
            work->unk_158 = -work->unk_158;
            break;
        case 3:
        case 4:
            work->unk_15C = -work->unk_15C;
            break;
        }
        if (work->unk_14E > 179) {
            work->unk_14E = 0;
            work->unk_148 = 3;
        } else work->unk_14E++;
        break;
    case 4:
        {
            s32 x,y,z;
            if (work->unk_14E == 0) {
                func_08019068(gUnk_0813EB8C, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                }
            }
            if (work->unk_14E == 40) {
                if (target != 0) {
                    x = target->unk_004;
                    y = target->unk_008;
                    z = target->unk_00C - target->unk_0A2 * 256;
                    if (x < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                } else {
                    if (body->unk_034 & 4) x = body->unk_004 - 0xC800;
                    else x = body->unk_004 + 0xC800;
                    y = body->unk_008;
                    z = body->unk_00C - 0x800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->unk_034 & 4) func_08012E44(0, body->unk_004 - 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 1, 123);
                    else func_08012E44(0, body->unk_004 + 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 0, 123);
                    break;
                case 1:
                    if (body->unk_034 & 4) func_08012E44(1, body->unk_004 - 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 1, 124);
                    else func_08012E44(1, body->unk_004 + 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 0, 124);
                    break;
                case 2:
                default:
                    if (body->unk_034 & 4) func_08012E44(2, body->unk_004 - 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 1, 125);
                    else func_08012E44(2, body->unk_004 + 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 0, 125);
                    break;
                }
            }
            if (work->unk_14E > 40) {
                if (!func_080128EC()) {
                    work->unk_148 = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->unk_004, target->unk_008, target->unk_00C - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 5:
        {
            s32 x,y,z;
            if (work->unk_14E == 0) {
                func_08019068(gUnk_0813EB8C, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                }
            }
            if (work->unk_14E == 40) {
                if (target != 0) {
                    x = target->unk_004;
                    y = target->unk_008;
                    z = target->unk_00C - target->unk_0A2 * 256;
                    if (x < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                } else {
                    if (body->unk_034 & 4) x = body->unk_004 - 0x6400;
                    else x = body->unk_004 + 0x6400;
                    y = body->unk_008;
                    z = body->unk_00C - 0x800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->unk_034 & 4) func_08013308(0, body->unk_004 - 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 1, 126);
                    else func_08013308(0, body->unk_004 + 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 0, 126);
                    break;
                case 1:
                    if (body->unk_034 & 4) func_08013308(1, body->unk_004 - 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 1, 127);
                    else func_08013308(1, body->unk_004 + 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 0, 127);
                    break;
                case 2:
                default:
                    if (body->unk_034 & 4) func_08013308(2, body->unk_004 - 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 1, 128);
                    else func_08013308(2, body->unk_004 + 0x5000, body->unk_008, body->unk_00C - 0x800, x, y, z, 0, 128);
                    break;
                }
            }
            if (work->unk_14E > 40) {
                if (!func_080128EC()) {
                    work->unk_148 = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->unk_004, target->unk_008, target->unk_00C - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 6:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EB8C, &work->anim, 1, 0, work->tiles);
            AnimReset(&work->anim);
            if (target != 0) {
                if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                else body->unk_034 &= ~4ULL;
            }
        }
        if (work->unk_14E == 40) {
            switch (work->unk_14D) {
            case 0:
                {
                    s32 x,y,z;
                    if (target != 0) {
                        x=target->unk_004;
                        y=target->unk_008;
                        z=target->unk_010;
                    } else {
                        if (body->unk_034 & 4) x=body->unk_004-0x5000;
                        else x=body->unk_004+0x5000;
                        y=body->unk_008;
                        z=0;
                    }
                    func_08015834(0, body->unk_004, body->unk_008, body->unk_00C-0x4000, x,y,z,129);
                    break;
                }
            case 1:
                func_08013CB4(1,body->unk_004,body->unk_008,body->unk_00C-0x4000,body->unk_010,130);
                break;
            case 2:
            default:
                func_08013CB4(2,body->unk_004,body->unk_008,body->unk_00C-0x4000,body->unk_010,131);
                break;
            }
        }
        if (work->unk_14E == 60) func_08019050(15,148,0x10000,0x12C00);
        if (work->unk_14E > 40 && !func_080128EC()) {
            work->unk_148=2;
            func_08019050(15,256,gBtlWork->unk_010,gBtlWork->unk_014);
            work->unk_14E=0;
        } else work->unk_14E++;
        break;
    case 7:
        {
            BtlObj* ally=work->unk_14C != 0 ? gBtlWork->unk_07C : gUnk_02039B9C->unk_07C;
            if (work->unk_14E == 0) {
                func_08019068(gUnk_0813EB8C,&work->anim,1,0,work->tiles);
                AnimReset(&work->anim);
                if (ally->unk_004 < body->unk_004) body->unk_034 |= 4;
                else body->unk_034 &= ~4ULL;
            }
            if (work->unk_14E == 40) {
                switch (work->unk_14D) {
                case 0:
                    func_08012AAC(0,ally->unk_004,ally->unk_008,ally->unk_00C-0x2C00);
                    break;
                case 1:
                    func_08012AAC(1,ally->unk_004,ally->unk_008,ally->unk_00C-0x2C00);
                    break;
                case 2:
                    func_08012AAC(2,ally->unk_004,ally->unk_008,ally->unk_00C-0x2C00);
                    break;
                default:
                    func_08012AAC(0,ally->unk_004,ally->unk_008,ally->unk_00C-0x2C00);
                    break;
                }
            }
            if (work->unk_14E > 40) {
                if (func_080128EC()) {
                    func_08014780(ally->unk_004,ally->unk_008,ally->unk_00C-0x2C00);
                } else {
                    if (ally->unk_0E4->unk_0F4 == 13) {
                        switch (work->unk_14D) {
                        case 0:
                            ally->unk_02C+=75;
                            break;
                        case 1:
                            ally->unk_02C+=225;
                            break;
                        case 2:
                            ally->unk_02C+=450;
                            break;
                        }
                    } else {
                        switch (work->unk_14D) {
                        case 0:
                            ally->unk_02C+=50;
                            break;
                        case 1:
                            ally->unk_02C+=150;
                            break;
                        case 2:
                            ally->unk_02C+=300;
                            break;
                        }
                    }
                    if (ally->unk_02C > ally->unk_02E) ally->unk_02C=ally->unk_02E;
                    func_08019190(ally,10);
                    work->unk_148=2;
                    func_08019050(15,256,gBtlWork->unk_010,gBtlWork->unk_014);
                    work->unk_14E=0;
                    break;
                }
            }
            work->unk_14E++;
            break;
        }
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_donald_2(FrdDonaldWork* work) {
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);

    if (body->unk_034 & 4) {
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

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
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
    BtlObj* body;

    body = &work->unk_020;
    func_0801C6D4(&body->unk_004, &body->unk_008, &body->unk_00C, &body->unk_010);
    body->unk_00C += work->unk_154;
    work->unk_154 += 0x33;

    if (body->unk_00C > body->unk_010) {
        body->unk_00C = body->unk_010;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_goofy_0(FrdGoofyWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->unk_020;
#ifdef VERSION_EU
    if (gLanguage == 1 || gLanguage == 3) {
        m4aSongNumStart(0xAB);
    } else {
        m4aSongNumStart(0xAE);
    }
#else
    m4aSongNumStart(0xAE);
#endif

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0;
    }

    body->unk_008 = work->unk_014->unk_008;
    body->unk_00C = -0x5000;
    body->unk_010 = 0;
    work->palette = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EBFC, &work->anim, 0, 0, work->tiles);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);
}

u8 task_frd_goofy_1(FrdGoofyWork* work) {
    BtlObj* body;
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
            func_08019068(gUnk_0813EBFC, &work->anim, 0, 0, work->tiles);
            work->unk_14E++;
        }

        body->unk_004 += (work->unk_158 - body->unk_004) >> 4;
        func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);

        if (func_080465F0(work)) {
            work->unk_148 = 1;
            work->unk_14E = 0;
            m4aSongNumStart(0xB2);
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 1, 0, work->tiles);
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
            func_08019068(gUnk_0813EBFC, &work->anim, 1, 0, work->tiles);
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
            func_08019068(gUnk_0813EBFC, &work->anim, 0, 0, work->tiles);

            if (body->unk_034 & 4) {
                work->unk_158 = (gBtlWork->unk_0DA - 0x40) << 8;
            } else {
                work->unk_158 = (gBtlWork->unk_0DC + 0x40) << 8;
            }

            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }

        ApproachValue(&body->unk_004, work->unk_158, work->unk_150);
        func_080465F0(work);

        if (work->unk_150 <= 0) {
            return 0;
        }

        work->unk_14E++;
        work->unk_150--;
        break;
    case 4:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EBFC, &work->anim, 2, 0, work->tiles);

            if (body->unk_034 & 4) {
                work->unk_158 = body->unk_004 - 0x8500;
            } else {
                work->unk_158 = body->unk_004 + 0x8500;
            }
        }

        if (work->unk_14E == 40) {
            work->unk_15C = work->unk_014->unk_008;
        }

        if (work->unk_14E > 39) {
            body->unk_004 += (work->unk_158 - body->unk_004) >> 4;
            body->unk_008 += (work->unk_15C - body->unk_008) >> 4;

            if (body->unk_034 & 4
                    ? func_08011F78(work->unk_14D + 120, body->unk_004 - 0xF00, body->unk_008, body->unk_00C, 0x1E, 0x0C, 0x30)
                    : func_08011F78(work->unk_14D + 120, body->unk_004 + 0xF00, body->unk_008, body->unk_00C, 0x1E, 0x0C, 0x30)) {
                m4aSongNumStart(0x20A);
            }

            func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);
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
            func_08019068(gUnk_0813EBFC, &work->anim, 3, 0, work->tiles);
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
            func_08019068(gUnk_0813EBFC, &work->anim, 4, 1, work->tiles);
            work->unk_160 = GetRandom();
        }

        work->unk_158 = work->unk_014->unk_004 + (gSineTable[work->unk_160] << 6);
        work->unk_15C = work->unk_014->unk_008 - (gSineTable[work->unk_160 + 0x40] << 5);
        body->unk_004 += (work->unk_158 - body->unk_004) >> 3;
        body->unk_008 += (work->unk_15C - body->unk_008) >> 3;
        func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);
        work->unk_160 += 4;

        if (func_08011F78(0x7A, body->unk_004, body->unk_008, body->unk_00C, 0x23, 0x1C, 0x30)) {
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
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);

    if (body->unk_034 & 4) {
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

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
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
    BtlObj* body;

    body = &work->unk_020;
    m4aSongNumStart(0xBB);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;

    if (work->unk_014->unk_034 & 4) {
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 4;
    } else {
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0;
    }

    body->unk_008 = work->unk_014->unk_008;
    body->unk_010 = 0;
    work->unk_154 = -0x1000;
    body->unk_00C = -0x1000;
    work->palette = LoadObjPalette(gUnk_09617DF8, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EC5C, &work->anim, 1, 0, work->tiles);
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
    BtlObj* body;
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

    func_0801C6D4(&body->unk_004, &body->unk_008, &body->unk_00C, &body->unk_010);

    switch (work->unk_148) {
    case 0:
        if (body->unk_034 & 4) {
            t = gBtlWork->unk_0DC - 0x30;
        } else {
            t = gBtlWork->unk_0DA + 0x30;
        }

        body->unk_004 += ((t << 8) - body->unk_004) >> 3;

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
            func_08019068(gUnk_0813EC5C, &work->anim, 2, 0, work->tiles);
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

            if (body->unk_034 & 4) {
                body->unk_004 -= work->unk_160;
            } else {
                body->unk_004 += work->unk_160;
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
        func_08019068(gUnk_0813EC5C, &work->anim, 0, 1, work->tiles);

        if (body->unk_034 & 4
                ? func_08011F78(0x77, body->unk_004, body->unk_008, body->unk_00C, 0x10, 0x10, 0x10)
                : func_08011F78(0x77, body->unk_004, body->unk_008, body->unk_00C, 0x10, 0x10, 0x10)) {
            m4aSongNumStart(0x250);
        }

        if (body->unk_034 & 4) {
            body->unk_004 -= work->unk_15C;

            if (body->unk_004 < (gBtlWork->unk_0DA - 0x30) << 8) {
                if (work->unk_158 == 0) {
                    return 0;
                }

                work->unk_158--;
                body->unk_034 &= 0xFFFFFFFFFFFFFFFB;
                work->unk_14E = 0;
                body->unk_008 = work->unk_014->unk_008;
                func_08019A30();
            }
        } else {
            body->unk_004 += work->unk_15C;

            if (body->unk_004 > (gBtlWork->unk_0DC + 0x30) << 8) {
                if (work->unk_158 == 0) {
                    return 0;
                }

                work->unk_158--;
                body->unk_034 |= 4;
                work->unk_14E = 0;
                body->unk_008 = work->unk_014->unk_008;
                func_08019A30();
            }
        }

        body->unk_00C = work->unk_154 + (gSineTable[((u16)work->unk_14E * 8) & 0xFF] << 3);
        body->unk_008 += (work->unk_014->unk_008 - body->unk_008) >> 4;

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
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);

    if (body->unk_034 & 4) {
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

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
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
    BtlObj* body;

    body = &work->unk_020;
    func_0801C6D4(&body->unk_004, &body->unk_008, &body->unk_00C, &body->unk_010);
    body->unk_00C += work->unk_154;
    work->unk_154 += 0x33;

    if (body->unk_00C > body->unk_010) {
        body->unk_00C = body->unk_010;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_jack_0(FrdJackWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->unk_020;
    m4aSongNumStart(0xB8);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0;
    }

    body->unk_008 = work->unk_014->unk_008;
    body->unk_00C = -0x5000;
    body->unk_010 = 0;
    work->unk_160 = 0;
    work->palette = LoadObjPalette(gUnk_09617DB8, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813EC9C, &work->anim, 0, 0, work->tiles);

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

u8 task_frd_jack_1(FrdJackWork* work) {
    BtlObj* body = &work->unk_020;
    BtlWork* owner;
    BtlObj* target;
    if (gGameState.world != 6) return 0;
    if (work->unk_14C != 0) {
        owner = gBtlWork;
        target = owner->unk_078;
    } else {
        owner = gUnk_02039B9C;
        target = owner->unk_078;
    }
    if (owner->unk_068 & 0x40000000) return 0;
    switch (work->unk_148) {
    case 0:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EC9C, &work->anim, 1, 0, work->tiles);
            work->unk_14E++;
        }
        body->unk_004 += (work->unk_158 - body->unk_004) >> 4;
        func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);
        if (func_080474A8(work)) {
            work->unk_148 = 1;
            work->unk_14E = 0;
            m4aSongNumStart(0xC1);
        }
        break;
    case 1:
        if (work->unk_14E == 0) func_08019068(gUnk_0813EC9C, &work->anim, 2, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            u16 spell;
            func_0801D288();
            spell = GetRandom();
            spell &= 3;
            switch (spell) {
            case 0:
                work->unk_148 = 4;
                break;
            case 1:
                work->unk_148 = 5;
                break;
            case 2:
                work->unk_148 = 6;
                break;
            case 3:
                work->unk_148 = 7;
                break;
            }
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 2:
        if (work->unk_168 > 0) {
            work->unk_148 = 8;
            work->unk_14E = 0;
            work->unk_168--;
        } else {
            if (work->unk_14E == 0) func_08019068(gUnk_0813EC9C, &work->anim, 4, 0, work->tiles);
            if (AnimIsFinished(&work->anim)) {
                work->unk_148 = 3;
                work->unk_14E = 0;
            } else work->unk_14E++;
        }
        break;
    case 3:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EC9C, &work->anim, 3, 0, work->tiles);
            if (!(body->unk_034 & 4)) work->unk_158 = (gBtlWork->unk_0DA - 64) * 256;
            else work->unk_158 = (gBtlWork->unk_0DC + 64) * 256;
            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }
        ApproachValue(&body->unk_004, work->unk_158, work->unk_150);
        func_080474A8(work);
        if (work->unk_150 <= 0) return 0;
        work->unk_14E++;
        work->unk_150--;
        break;
    case 8:
        if (work->unk_14E == 0) func_08019068(gUnk_0813EC9C, &work->anim, 4, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            work->unk_148 = 9;
            GetRandom();
            m4aSongNumStart(0xC1);
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 9:
        if (work->unk_14E == 0) {
            if (work->unk_014->unk_034 & 4) work->unk_158 = work->unk_014->unk_004 - 0x2D00;
            else work->unk_158 = work->unk_014->unk_004 + 0x2D00;
            work->unk_15C = work->unk_014->unk_008;
            work->unk_154 = -0x500;
            work->unk_150 = 45;
            if (work->unk_158 > body->unk_004) {
                if (body->unk_034 & 4) {
                    work->unk_164 = 256;
                } else {
                    work->unk_164 = -256;
                }
            } else {
                if (body->unk_034 & 4) {
                    work->unk_164 = -256;
                } else {
                    work->unk_164 = 256;
                }
            }
            work->unk_14E++;
        }
        func_080474A8(work);
        if (work->unk_154 > 0) func_08019068(gUnk_0813EC9C, &work->anim, 1, 0, work->tiles);
        else func_08019068(gUnk_0813EC9C, &work->anim, 3, 0, work->tiles);
        if (work->unk_150 > 0) {
            ApproachValueHalfSteps(&body->unk_004, work->unk_158, work->unk_150);
            ApproachValueHalfSteps(&body->unk_008, work->unk_15C, work->unk_150);
            if (work->unk_150 <= 39) ApproachValueHalfSteps(&work->unk_160, work->unk_164, work->unk_150);
            work->unk_150--;
        }
        if (body->unk_00C >= body->unk_010 && work->unk_150 <= 0) {
            work->unk_14E = 0;
            work->unk_160 = 0;
            work->unk_148 = 10;
        }
        break;
    case 10:
        if (work->unk_14E == 0) func_08019068(gUnk_0813EC9C, &work->anim, 2, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            u16 spell;
            func_0801D288();
            spell = GetRandom();
            spell &= 3;
            switch (spell) {
            case 0:
                work->unk_148 = 4;
                break;
            case 1:
                work->unk_148 = 5;
                break;
            case 2:
                work->unk_148 = 6;
                break;
            case 3:
                work->unk_148 = 7;
                break;
            }
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 4:
        {
            s32 x, y, z;
            if (work->unk_14E == 0) {
                func_08019068(gUnk_0813EC9C, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                }
            }
            if (work->unk_14E == 44) {
                if (target != 0) {
                    x = target->unk_004;
                    y = target->unk_008;
                    z = target->unk_00C - target->unk_0A2 * 256;
                    if (x < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                } else {
                    if (body->unk_034 & 4) x = body->unk_004 - 0xC800;
                    else x = body->unk_004 + 0xC800;
                    y = body->unk_008;
                    z = body->unk_00C - 0x1800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->unk_034 & 4) func_08012E44(0, body->unk_004 - 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 133);
                    else func_08012E44(0, body->unk_004 + 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 133);
                    break;
                case 1:
                    if (body->unk_034 & 4) func_08012E44(1, body->unk_004 - 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 134);
                    else func_08012E44(1, body->unk_004 + 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 134);
                    break;
                case 2:
                default:
                    if (body->unk_034 & 4) func_08012E44(2, body->unk_004 - 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 135);
                    else func_08012E44(2, body->unk_004 + 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 135);
                    break;
                }
            }
            if (work->unk_14E > 44) {
                if (!func_080128EC()) {
                    work->unk_148 = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->unk_004, target->unk_008, target->unk_00C - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 7:
        {
            s32 x, y, z;
            if (work->unk_14E == 0) {
                func_08019068(gUnk_0813EC9C, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                }
                FadeToAmount(2, 13, 60);
            }
            if (work->unk_14E == 44) {
                if (target != 0) {
                    x = target->unk_004;
                    y = target->unk_008;
                    z = target->unk_010;
                    if (x < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                } else {
                    if (body->unk_034 & 4) x = body->unk_004 - 0x4000;
                    else x = body->unk_004 + 0x4000;
                    y = body->unk_008;
                    z = body->unk_010;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->unk_034 & 4) func_08014D78(0, body->unk_004 - 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 142);
                    else func_08014D78(0, body->unk_004 + 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 142);
                    break;
                case 1:
                    if (body->unk_034 & 4) func_08014D78(1, body->unk_004 - 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 143);
                    else func_08014D78(1, body->unk_004 + 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 143);
                    break;
                case 2:
                default:
                    if (body->unk_034 & 4) func_08014D78(2, body->unk_004 - 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 144);
                    else func_08014D78(2, body->unk_004 + 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 144);
                    break;
                }
            }
            if (work->unk_14E > 44 && !func_080128EC()) {
                FadeToOriginal(2, 20);
                work->unk_148 = 2;
                work->unk_14E = 0;
            } else work->unk_14E++;
            break;
        }
    case 5:
        {
            s32 x, y, z;
            if (work->unk_14E == 0) {
                func_08019068(gUnk_0813EC9C, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                }
            }
            if (work->unk_14E == 44) {
                if (target != 0) {
                    x = target->unk_004;
                    y = target->unk_008;
                    z = target->unk_00C - target->unk_0A2 * 256;
                    if (x < body->unk_004) body->unk_034 |= 4;
                    else body->unk_034 &= ~4ULL;
                } else {
                    if (body->unk_034 & 4) x = body->unk_004 - 0x6400;
                    else x = body->unk_004 + 0x6400;
                    y = body->unk_008;
                    z = body->unk_00C - 0x1800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->unk_034 & 4) func_08013308(0, body->unk_004 - 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 136);
                    else func_08013308(0, body->unk_004 + 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 136);
                    break;
                case 1:
                    if (body->unk_034 & 4) func_08013308(1, body->unk_004 - 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 137);
                    else func_08013308(1, body->unk_004 + 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 137);
                    break;
                case 2:
                default:
                    if (body->unk_034 & 4) func_08013308(2, body->unk_004 - 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 1, 138);
                    else func_08013308(2, body->unk_004 + 0x4A00, body->unk_008, body->unk_00C - 0x1800, x, y, z, 0, 138);
                    break;
                }
            }
            if (work->unk_14E > 44) {
                if (!func_080128EC()) {
                    work->unk_148 = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->unk_004, target->unk_008, target->unk_00C - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 6:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813EC9C, &work->anim, 0, 0, work->tiles);
            AnimReset(&work->anim);
            if (target != 0) {
                if (target->unk_004 < body->unk_004) body->unk_034 |= 4;
                else body->unk_034 &= ~4ULL;
            }
        }
        if (work->unk_14E == 44) {
            switch (work->unk_14D) {
            case 0:
                {
                    s32 x, y, z;
                    if (target != 0) {
                        x = target->unk_004;
                        y = target->unk_008;
                        z = target->unk_010;
                    } else {
                        if (body->unk_034 & 4) x = body->unk_004 - 0x5000;
                        else x = body->unk_004 + 0x5000;
                        y = body->unk_008;
                        z = 0;
                    }
                    if (body->unk_034 & 4) func_08015834(0, body->unk_004 - 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 139);
                    else func_08015834(0, body->unk_004 + 0x2800, body->unk_008, body->unk_00C - 0x1800, x, y, z, 139);
                    break;
                }
            case 1:
                if (body->unk_034 & 4) func_08013CB4(1, body->unk_004 - 0x2800, body->unk_008, body->unk_00C - 0x1800, body->unk_010, 140);
                else func_08013CB4(1, body->unk_004 + 0x2800, body->unk_008, body->unk_00C - 0x1800, body->unk_010, 140);
                break;
            case 2:
            default:
                if (body->unk_034 & 4) func_08013CB4(2, body->unk_004 - 0x2800, body->unk_008, body->unk_00C - 0x1800, body->unk_010, 141);
                else func_08013CB4(2, body->unk_004 + 0x2800, body->unk_008, body->unk_00C - 0x1800, body->unk_010, 141);
                break;
            }
        }
        if (work->unk_14E == 64) func_08019050(15, 148, 0x10000, 0x12C00);
        if (work->unk_14E > 44 && !func_080128EC()) {
            work->unk_148 = 2;
            func_08019050(15, 256, gBtlWork->unk_010, gBtlWork->unk_014);
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_jack_2(FrdJackWork* work) {
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;
    u8 angle;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);
    angle = work->unk_160;

    if (body->unk_034 & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (angle == 0 && gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (angle != 0) {
        affine = AllocObjAffine(angle, sclX, sclY, 1);
    } else if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    if (body->unk_034 & 4) {
        sx = sx + (gSineTable[(u16)(angle + 128) & 0xFF] * 5 >> 5);
    } else {
        sx = sx - (gSineTable[(u16)(angle + 128) & 0xFF] * 5 >> 5);
    }

    sy = sy + (-gSineTable[((u16)(angle + 128) & 0xFF) + 64] * 5 >> 5) - 40;
    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags, -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_jack_3(FrdJackWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}

void task_frd_pan_0(FrdPanWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->unk_020;
    m4aSongNumStart(0xB9);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_158 = 0;

    if (work->unk_014->unk_034 & 4) {
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 0x20004;
        work->unk_168 = -0x800;
        work->unk_16C = 0;
    } else {
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0x20000;
        work->unk_168 = 0x800;
        work->unk_16C = 1;
    }

    work->unk_15C = 0x10000;
    body->unk_008 = work->unk_014->unk_008;
    body->unk_010 = 0;
    work->unk_164 = -0x2000;
    body->unk_00C = -0x2000;
    work->palette = LoadObjPalette(gUnk_09617DD8, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813ECFC, &work->anim, 0, 0, work->tiles);
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
    BtlObj sub;

    if ((s16)work->unk_14E % 3 == 0) {
        sub.unk_004 = work->unk_020.unk_004;
        sub.unk_008 = work->unk_020.unk_008;
        sub.unk_00C = work->unk_020.unk_00C;

        switch (AnimGetGfxIndex(&work->anim)) {
        case 1:
        case 2:
            sub.unk_00C -= 0x800;
            break;
        case 3:
        case 4:
            sub.unk_00C -= 0x1800;

            if (work->unk_020.unk_034 & 4) {
                sub.unk_004 += 0x2000;
            } else {
                sub.unk_004 -= 0x2000;
            }
            break;
        case 5:
        default:
            sub.unk_00C -= 0x1000;

            if (work->unk_020.unk_034 & 4) {
                sub.unk_004 += 0x1000;
            } else {
                sub.unk_004 -= 0x1000;
            }
            break;
        }

        TaskCreate(&work->unk_000, gTaskDescSmnTinkeff, &sub);
    }
}

void func_08048A68(FrdPanWork* work) {
    BtlObj* body;

    body = &work->unk_020;
    body->unk_00C += ((work->unk_164 + (gSineTable[((u16)work->unk_14E * 2) & 0xFF] << 4)) - body->unk_00C) >> 2;
}

u8 task_frd_pan_1(FrdPanWork* work) {
    BtlObj* body = &work->unk_020;
    BtlWork* owner;
    BtlObj* target;
    s32 ground;
    s32 y;
    s32 z;
    if (gGameState.world != 7) {
        return 0;
    }
    owner = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    target = owner->unk_078;
    if (owner->unk_068 & 0x40000000) {
        return 0;
    }
    if (gBtlWork->unk_128 != 0) {
        ground = body->unk_010;
        gBtlWork->unk_128(&body->unk_004, &body->unk_008, &body->unk_00C, &ground);
        if (ground != body->unk_010) {
            work->unk_164 = body->unk_010 - 0x1000;
            body->unk_010 = ground;
        }
    }
    switch (work->unk_148) {
    case 0:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ECFC, &work->anim, 0, 0, work->tiles);
            work->unk_150 = 30;
        }
        ApproachValueHalfSteps(&body->unk_004, work->unk_15C, work->unk_150);
        func_08048A68(work);
        if (work->unk_150 <= 0) {
            work->unk_148 = 3;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
            work->unk_150--;
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ECFC, &work->anim, 0, 0, work->tiles);
        }
        func_08048A68(work);
        if (AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->unk_148 = 2;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ECFC, &work->anim, 0, 0, work->tiles);
            if (!(body->unk_034 & 4)) {
                work->unk_15C = (gBtlWork->unk_0DA - 64) * 256;
            } else {
                work->unk_15C = (gBtlWork->unk_0DC + 64) * 256;
            }
            work->unk_150 = 30;
        }
        work->unk_164 -= 0x400;
        ApproachValue(&body->unk_004, work->unk_15C, work->unk_150);
        func_08048A68(work);
        if (work->unk_150 <= 0) {
            return 0;
        }
        work->unk_14E++;
        work->unk_150--;
        break;
    case 3:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ECFC, &work->anim, 1, 0, work->tiles);
        }
        func_08048A68(work);
        if (AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->unk_148 = 4;
            m4aSongNumStart(0xBF);
        } else {
            work->unk_14E++;
        }
        break;
    case 4:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ECFC, &work->anim, 2, 1, work->tiles);
            work->unk_150 = 70;
            FadeToAmount(0, gBtlWork->unk_0B3, 8);
        }
        func_0801D288();
        if (gBtlWork->unk_068 & 0x4000) {
            BtlObj* other = work->unk_14C != 0 ? gUnk_02039B9C->unk_07C : gBtlWork->unk_07C;
            y = other->unk_008;
            z = other->unk_00C;
        } else if (target != 0) {
            y = target->unk_008;
            z = target->unk_00C;
        } else {
            y = work->unk_014->unk_008;
            z = work->unk_014->unk_00C;
        }
        body->unk_008 += (y - body->unk_008) >> 5;
        work->unk_164 += (z - work->unk_164) >> 5;
        func_08048A68(work);
        if (work->unk_16C != 0) {
            ApproachValue(&work->unk_168, -0x800, work->unk_150);
        } else {
            ApproachValue(&work->unk_168, 0x800, work->unk_150);
        }
        body->unk_004 += work->unk_168;
        if (--work->unk_150 <= 0) {
            work->unk_150 = 70;
            work->unk_16C = !work->unk_16C;
        }
        if (work->unk_168 < 0) {
            body->unk_034 |= 4;
        } else {
            body->unk_034 &= ~4ULL;
        }
        if (body->unk_034 & 4) {
            if (func_08011F78(150, body->unk_004 - 0x1C00, body->unk_008, body->unk_00C - 0x1400, 20, 20, 20)) {
                m4aSongNumStart(0x252);
            }
        } else {
            if (func_08011F78(150, body->unk_004 + 0x1C00, body->unk_008, body->unk_00C - 0x1400, 20, 20, 20)) {
                m4aSongNumStart(0x252);
            }
        }
        if (work->unk_14E > work->unk_152) {
            work->unk_14E = 0;
            work->unk_148 = 5;
        } else {
            work->unk_14E++;
        }
        break;
    case 5:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ECFC, &work->anim, 3, 0, work->tiles);
        }
        func_08048A68(work);
        if (AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->unk_148 = 1;
            FadeToOriginal(0, 8);
        } else {
            work->unk_14E++;
        }
        break;
    }
    func_08048980(work);
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_pan_2(FrdPanWork* work) {
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);

    if (body->unk_034 & 4) {
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

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
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
    BtlObj* body;

    body = &work->unk_020;

    if (func_0801C6D4(&body->unk_004, &body->unk_008, &body->unk_00C, &body->unk_010)) {
        body->unk_00C += work->unk_154;
        work->unk_154 = -0x200;
    } else {
        body->unk_00C += work->unk_154;
        work->unk_154 += 0x33;
    }

    if (body->unk_00C > body->unk_010) {
        body->unk_00C = body->unk_010;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_aladdin_0(FrdAladdinWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->unk_020;
    m4aSongNumStart(0xBC);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
    }

    work->unk_14D = args->unk_00;
    work->unk_148 = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->unk_014->unk_034 & 4) {
        work->unk_158 = work->unk_014->unk_004 - 0x3000;
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 4;
    } else {
        work->unk_158 = work->unk_014->unk_004 + 0x3000;
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0;
    }

    body->unk_008 = work->unk_014->unk_008;
    body->unk_00C = -0x5000;
    body->unk_010 = 0;
    work->palette = LoadObjPalette(gUnk_09617D98, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813ED4C, &work->anim, 0, 0, work->tiles);
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

u8 task_frd_aladdin_1(FrdAladdinWork* work) {
    BtlObj* body;
    s32 x;
    s32 y;
    s32 delta;

    body = &work->unk_020;
    if (gGameState.world != 1) {
        return 0;
    }
    if ((work->unk_14C ? gBtlWork->unk_068 : gUnk_02039B9C->unk_068) & 0x40000000) return 0;
    switch (work->unk_148) {
    case 0:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ED4C, &work->anim, 0, 0, work->tiles);
            work->unk_14E++;
        }
        body->unk_004 += (work->unk_158 - body->unk_004) >> 4;
        func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);
        if (func_080490FC(work)) {
            work->unk_148 = 1;
            work->unk_14E = 0;
            m4aSongNumStart(0xC0);
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ED4C, &work->anim, 1, 0, work->tiles);
        }
        if (AnimIsFinished(&work->anim)) {
            work->unk_148 = 3;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ED4C, &work->anim, 0, 0, work->tiles);
            if (!(body->unk_034 & 4)) {
                work->unk_158 = (gBtlWork->unk_0DA - 64) << 8;
            } else {
                work->unk_158 = (gBtlWork->unk_0DC + 64) << 8;
            }
            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }
        ApproachValue(&body->unk_004, work->unk_158, work->unk_150);
        func_080490FC(work);
        if (work->unk_150 <= 0) {
            return 0;
        }
        work->unk_14E++;
        work->unk_150--;
        break;
    case 3:
        if (work->unk_14E == 0) {
            func_08019068(gUnk_0813ED4C, &work->anim, 2, 1, work->tiles);
        }
        func_0801D288();
        if (work->unk_014->unk_034 & 4) {
            body->unk_034 |= 4;
            x = work->unk_014->unk_004 - 0x2800;
        } else {
            body->unk_034 &= ~4ULL;
            x = work->unk_014->unk_004 + 0x2800;
        }
        y = work->unk_014->unk_008;
        delta = (x - body->unk_004) >> 3;
        if (delta < -0x400) {
            delta = -0x400;
        } else if (delta > 0x400) {
            delta = 0x400;
        }
        body->unk_004 += delta;
        delta = (y - body->unk_008) >> 5;
        if (delta < -0x200) {
            delta = -0x200;
        } else if (delta > 0x200) {
            delta = 0x200;
        }
        body->unk_008 += delta;
        if (work->anim.timer == 0) {
            switch (AnimGetFrame(&work->anim)) {
            case 0:
            case 1:
            case 5:
            case 6:
                if ((body->unk_034 & 4) ? func_08011F78(0x95, body->unk_004 - 0x1E00, body->unk_008, body->unk_00C, 20, 20, 50) : func_08011F78(0x95, body->unk_004 + 0x1E00, body->unk_008, body->unk_00C, 20, 20, 50)) {
                    m4aSongNumStart(0x251);
                }
                break;
            }
        }
        func_080490FC(work);
        func_0801A8A4(&body->unk_004, &body->unk_008, -16, 0);
        if (work->unk_14E > work->unk_152) {
            work->unk_14E = 0;
            work->unk_148 = 2;
        } else {
            work->unk_14E++;
        }
        break;
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->unk_000);
    return 1;
}

void task_frd_aladdin_2(FrdAladdinWork* work) {
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);

    if (body->unk_034 & 4) {
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

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
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
    BtlObj* body;

    body = &work->unk_020;
    func_0801C6D4(&body->unk_004, &body->unk_008, &body->unk_00C, &body->unk_010);
    body->unk_00C += work->unk_158;
    work->unk_158 += 0x33;

    if (body->unk_00C > body->unk_010) {
        body->unk_00C = body->unk_010;
        work->unk_158 = 0;
        return 1;
    }

    return 0;
}

void task_frd_beast_0(FrdBeastWork* work, FrdArgs* args) {
    BtlObj* body;
    BtlObj* obj;

    body = &work->unk_020;
#ifdef VERSION_EU
    if (gLanguage == 0) {
        m4aSongNumStart(0xBA);
    } else {
        m4aSongNumStart(0xAB);
    }
#else
    m4aSongNumStart(0xBA);
#endif

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->unk_014 = gBtlWork->unk_07C;
        work->tiles = gBtlWork->unk_114;
        obj = gBtlWork->unk_078;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->unk_014 = gUnk_02039B9C->unk_07C;
        work->tiles = gBtlWork->unk_114;
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
        body->unk_004 = (gBtlWork->unk_0DC + 0x30) << 8;
        body->unk_034 = 0x20004;
    } else {
        body->unk_004 = (gBtlWork->unk_0DA - 0x30) << 8;
        body->unk_034 = 0x20000;
    }

    body->unk_008 = work->unk_154;
    body->unk_00C = 0;
    body->unk_010 = 0;

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
    func_08019068(gUnk_0813ED90, &work->anim, 0, 0, work->tiles);
    TaskPoolInit(&work->unk_000, 1);
    TaskCreate(&work->unk_000, gTaskDescBtlShadow, body);
}

u8 task_frd_beast_1(FrdBeastWork* work) {
    BtlObj* body;
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

        if (body->unk_00C < body->unk_010) {
            body->unk_004 += (work->unk_150 - body->unk_004) >> 4;
            body->unk_008 += (work->unk_154 - body->unk_008) >> 4;
        }

        if (work->unk_158 > 0) {
            if (gBtlWork->unk_10C == 0x99) {
                func_08011F78(0xA3, body->unk_004, body->unk_008, body->unk_00C - 0x1800, 0x28, 0x14, 0x10);
            } else {
                func_08011F78(0xA2, body->unk_004, body->unk_008, body->unk_00C - 0x1800, 0x28, 0x14, 0x10);
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
            func_08019068(gUnk_0813ED90, &work->anim, 1, 1, work->tiles);

            if (work->unk_14D != 2) {
                m4aSongNumStart(0xBD);
            }
        }

        if (body->unk_034 & 4) {
            body->unk_004 -= 0x380;

            if (body->unk_004 < (gBtlWork->unk_0DA - 0x28) << 8) {
                return 0;
            }
        } else {
            body->unk_004 += 0x380;

            if (body->unk_004 > (gBtlWork->unk_0DC + 0x28) << 8) {
                return 0;
            }
        }

        if (func_08011F78(work->unk_15C, body->unk_004, body->unk_008, body->unk_00C - 0x1800, 0x28, 0x14, 0x10)) {
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
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->unk_020;
    gfx = AnimGetGfx(&work->anim);
    flags = func_0801AF1C(body->unk_008);

    if (body->unk_034 & 4) {
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

    WorldToScreen(&sx, &sy, body->unk_004, body->unk_008, body->unk_00C);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->unk_008 >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->unk_008 >> 8) * 4)) | 2;
    TaskPoolDraw(&work->unk_000);
}

void task_frd_beast_3(FrdBeastWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_000);
}
