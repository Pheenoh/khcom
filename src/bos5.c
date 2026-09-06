#include "macros.h"
#include "bos5.h"

GaWork* gGaWork;
u32 gUnk_02034FEC;
s16 gUnk_02034FF0;
u32 gUnk_02034FF4;
MdSlot gUnk_02034FF8[5];
s16 gUnk_02035070[14];
u32 gUnk_0203508C;
s16 gUnk_02035090;
s16 gUnk_02035092;
u32 gUnk_02035094;
void* gUnk_02035098[2];
void* gUnk_020350A0[2];
void* gUnk_020350A8;
void* gUnk_020350AC;
void* gUnk_020350B0;
u8 gUnk_020350B4;
s16 gUnk_020350B6;
s16 gUnk_020350B8;
s16 gUnk_020350BA;
void* gUnk_020350BC;
s16 gUnk_020350C0;
s16 gUnk_020350C2;
u32 gUnk_020350C4;
s32 gUnk_020350C8[2];
s32 gUnk_020350D0;
u32 gUnk_020350D4;
TaskPool gUnk_020350D8;
s16 gUnk_020350EC;
u8 gUnk_020350EE;
u8 gUnk_020350EF;
u8 gUnk_020350F0;
s16 gUnk_020350F2;
u16 gUnk_020350F4;
u16 gUnk_020350F6;
s16 gUnk_020350F8;
s16 gUnk_020350FA;
u32 gUnk_020350FC;
s16 gUnk_02035100[3];

void task_bos_ga_0(GaWork* work, s32 arg) {
    u32 i;
    GaEntryWork* p;

    gGaWork = work;

    if (arg == 0) {
        work->unk_000 = 1;
    } else {
        work->unk_000 = 0;
    }

    work->unk_004 = work->unk_000;
    work->unk_00E = 0;
    work->unk_008 = 0;
    work->unk_010 = 0;
    work->unk_012 = 0;
    work->unk_014 = 0;
    work->unk_018 = 0;
    work->unk_01C = 0;
    work->unk_A4C = 0;
    work->unk_A50 = 60;
    TaskCreate(&gBtlWork->unk_03C[4], gTaskDescBosMap, gUnk_0999202C);
    gBtlWork->unk_0CC = 0xE200;
    gBtlWork->unk_0D0 = 0x15E00;
    gBtlWork->unk_0D4 = 0;
    func_0801BCC0(0x8200, 0x15E00, 0);
    p = work->entries;

    for (i = 0; i <= 5; i++) {
        func_080F80FC(work, i, arg);
    }

    func_0801C2DC(p, 1);
    func_0801C2DC(&work->entries[1], 1);
    work->unk_A30 = LoadObjPalette(gUnk_09A3C89C, 32);
    work->unk_A34 = LoadObjPalette(gUnk_08F69BC4, 32);
    func_0801C298(work->unk_A30[6] + 16, 1);
    func_0801C298(work->unk_A34[6] + 16, 1);
    func_08083900(GetRandom() % 4 + 1);
}
u8 task_bos_ga_1(GaWork* work) {
    u8 result;
    GaEntryWork* p;
    AnimState* anim;
    u32 i;

    result = 1;
    work->unk_A50--;

    if (work->unk_A50 <= 0) {
        func_08083900(GetRandom() % 7 + 1);
        work->unk_A50 = 60;
    }

    work->unk_A52 = 0;
    i = 0;
    p = work->entries;

    do {
        func_080FB000(work, p);
        p++;
        i++;
    } while (i <= 5);

    switch (work->unk_000) {
    case 0:
        result = func_080F854C(work);
        break;
    case 1:
        result = func_080F8958(work);
        break;
    case 2:
        result = func_080F8AC8(work);
        break;
    case 3:
        result = func_080F8F9C(work);
        break;
    case 4:
        result = func_080F9744(work);
        break;
    case 5:
        result = func_080F99C0(work);
        break;
    case 6:
        result = func_080F9C2C(work);
        break;
    case 7:
        result = func_080F9EDC(work);
        break;
    case 8:
        result = func_080FA2B4(work);
        break;
    case 9:
        result = func_080FA644(work);
        break;
    case 10:
        result = func_080FAA18(work);
        break;
    case 11:
        result = func_080FABE4(work);
        break;
    }

    if (func_0801C1C0(0)) {
        func_080F7F54(work, 10);
    }

    anim = &work->entries[1].anim;

    if (AnimIsFinished(anim) && GetRandom() % 100 == 0 && work->unk_000 != 11) {
        AnimStart(anim, 1, 0);
    }

    return result;
}

void task_bos_ga_2(GaWork* work) {
    GaEntryWork* p;
    u32 i;

    i = 0;
    p = work->entries;

    do {
        func_080F83E0(work, p);
        p++;
        i++;
    } while (i <= 5);
}

void task_bos_ga_3(GaWork* work) {
    GaEntryWork* p;
    u32 i;

    i = 0;
    p = work->entries;

    do {
        func_080F8374(p);
        p++;
        i++;
    } while (i <= 5);

    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette(work->unk_A30);
    ReleaseObjPalette(work->unk_A34);
}

void func_080FB8DC(MdWork* work, s32 state) {
    u16 t;

    work->unk_004 = state;
    t = work->unk_014 | 1;
    work->unk_014 = t;
}

void func_080FB8E8(MdWork* work, u16 index) {
    func_0800516C(1, gUnk_09992114 + index * 0x4C, 2, 2);
}

void func_080FB908(MdWork* work, u16 index) {
    LoadBgTiles(1, gUnk_09992108[index].unk_04, gUnk_09992108[index].unk_08);
}

#ifdef NON_MATCHING
void func_080FB930(MdWork* work, u16 id) {
    s32 n;

    if (work->unk_01C == 0) {
        return;
    }

    func_080FB908(work, id);
    func_080FB8E8(work, id);
    work->unk_178 = gUnk_09992108[id].unk_00;
    work->unk_17A = gUnk_09992108[id].unk_02;

    for (n = 0; n < 2; n++) {
        work->unk_17C[n].unk_08 = gUnk_09992108[id].unk_1C[n].unk_10;

        if (work->unk_17C[n].unk_04 != gUnk_09992108[id].unk_1C[n].unk_08 && n == 0) {
            work->unk_17C[n].unk_04 = gUnk_09992108[id].unk_1C[n].unk_08;
            func_080038E4(work->unk_17C[n].unk_00, work->unk_17C[n].unk_08);
        }

        work->unk_17C[n].unk_0C = gUnk_09992108[id].unk_1C[n].unk_00;
        work->unk_17C[n].unk_0E = gUnk_09992108[id].unk_1C[n].unk_02;
        work->unk_17C[n].unk_10 = gUnk_09992108[id].unk_1C[n].unk_04;
    }
}
#else
INCLUDE_ASM("bos5/func_080FB930.s");
#endif

void func_080FBA14(MdWork* work, s16 id) {
    MdAnim* a;
    MdAnimDef* base;
    MdAnimDef* d;
    MdAnimFrame* f;

    a = &work->unk_1A4;
    a->unk_00 = id;
    base = gUnk_09992E24;
    d = base + id;
    f = d->unk_00;
    a->unk_04 = f;
    a->unk_08 = d->unk_04;
    a->unk_0A = 0;
    a->unk_0C = f->unk_02;
    func_080FB930(work, f->unk_00);
}
void func_080FBA4C(MdWork* work) {
    MdAnim* a;

    a = &work->unk_1A4;
    a->unk_0C--;

    if (a->unk_0C < 0) {
        a->unk_0A++;

        if (a->unk_0A >= a->unk_08) {
            a->unk_0A = 0;
        }

        a->unk_0C = a->unk_04[a->unk_0A].unk_02;
        func_080FB930(work, a->unk_04[a->unk_0A].unk_00);
    }
}
u8 func_080FBA9C(MdWork* work) {
    MdAnim* a;

    a = &work->unk_1A4;

    if (a->unk_0A >= a->unk_08 - 1) {
        return 1;
    }

    return 0;
}
u8 func_080FBAB8(MdWork* work) {
    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
    case 0:
        if (gBtlWork->unk_07C[1] > 0x8000) {
            func_080FBA14(work, 1);
        } else {
            func_080FBA14(work, 0);
        }

        if (gBtlWork->unk_068 & 0x100000) {
            work->unk_016 = ((GetRandom() & 3) + (GetRandom() & 3)) / 2 * 20 + 60;
        } else if (work->sub[0].unk_02C * 10 / work->sub[0].unk_02E > 4) {
            work->unk_016 = (GetRandom() % 5 + GetRandom() % 5) / 2 * 30 + 30;
        } else {
            work->unk_016 = (GetRandom() % 6 + GetRandom() % 6) / 2 * 10 + 30;
        }
        break;
    case 1:
        if (func_080FBA9C(work) != 0 && gBtlWork->unk_07C[1] > 0x8000) {
            func_080FBA14(work, 1);
        }

        if (gBtlWork->unk_0A0 != 0) {
            work->unk_016--;

            if (work->unk_016 <= 0) {
                func_0801BCD4(&work->sub[0]);
                func_080FB8DC(work, 0);
            }
        }
        break;
    case 2:
        break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FBC4C(MdWork* work) {
    s32 d;
    u16 r;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            d = gBtlWork->unk_07C[1];

            if (d > 0xA800) {
                switch (GetRandom() % 3) {
                case 0:
                    func_080FBA14(work, 7);
                    break;
                case 1:
                    func_080FBA14(work, 8);
                    break;
                case 2:
                    func_080FBA14(work, 9);
                    break;
                }
            } else if (d > 0x7000) {
                r = GetRandom() % 100;

                if (r <= 59) {
                    func_080FBA14(work, 7);
                } else if (r <= 89) {
                    func_080FBA14(work, 8);
                } else {
                    func_080FBA14(work, 9);
                }
            } else if (d > 0x3800) {
                r = GetRandom() % 100;

                if (r <= 59) {
                    func_080FBA14(work, 8);
                } else if (r <= 89) {
                    func_080FBA14(work, 7);
                } else {
                    func_080FBA14(work, 9);
                }
            } else {
                switch (GetRandom() % 3) {
                case 0:
                    func_080FBA14(work, 7);
                    break;
                case 1:
                    func_080FBA14(work, 8);
                    break;
                case 2:
                    func_080FBA14(work, 9);
                    break;
                }
            }
            break;
        case 1:
            switch ((s16)work->unk_1A4.unk_04[work->unk_1A4.unk_0A].unk_00) {
            case 33:
            case 34:
            case 36:
            case 37:
                if (func_08011F78(251, work->sub[0].unk_004, work->sub[0].unk_008,
                                  work->sub[0].unk_00C, 40, 20, 24) != 0) {
                    m4aSongNumStart(0x2A5);
                }
                break;
            }

            if (func_080FBA9C(work) != 0) {
                func_080FB8DC(work, 0);
            }
            break;
        case 2:
            func_0801AF08(&work->sub[0]);
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FBDD4(MdWork* work) {
    s32 v;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            if (gBtlWork->unk_07C[1] > 0xA800) {
                if (GetRandom() % 100 <= 59) {
                    func_080FBA14(work, 6);
                } else {
                    func_080FBA14(work, 5);
                }
            } else {
                if (GetRandom() % 100 <= 79) {
                    func_080FBA14(work, 5);
                } else {
                    func_080FBA14(work, 6);
                }
            }

            work->unk_00C = 0;
            break;
        case 1:
            switch (work->unk_00C) {
            case 0:
                v = (s16)work->unk_1A4.unk_04[work->unk_1A4.unk_0A].unk_00;

                if (v == 18) {
                    func_08011F78(252, gBtlWork->unk_000, gBtlWork->unk_004, 0,
                                  256, 256, 1);
                    m4aSongNumStart(0x2A7);
                    func_0802F1E8();
                    work->unk_1B4 |= 1;
                    work->unk_00C = 1;
                } else if (v == 28) {
                    func_08011F78(254, gBtlWork->unk_000, gBtlWork->unk_004, 0,
                                  256, 256, 1);
                    m4aSongNumStart(0x2A7);
                    func_0802F1E8();
                    work->unk_1B4 |= 1;
                    work->unk_00C = 2;
                }
                break;
            case 1:
                v = (s16)work->unk_1A4.unk_04[work->unk_1A4.unk_0A].unk_00;

                if (v == 22) {
                    func_08019A30();
                    func_08011F78(252, gBtlWork->unk_000, gBtlWork->unk_004, 0,
                                  256, 256, 1);
                    m4aSongNumStart(0x2A7);
                    func_0802F1E8();
                    work->unk_1B4 |= 1;
                    work->unk_00C = 2;
                }
                break;
            }

            if (func_080FBA9C(work) != 0) {
                func_080FB8DC(work, 0);
            }
            break;
        case 2:
            func_0801AF08(&work->sub[0]);
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FBFA8(MdWork* work) {
    MdFireArg a;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            work->unk_1B4 = work->unk_1B4 | 2;
            func_080FBA14(work, 2);
            work->unk_00C = 0;
            break;
        case 1:
            switch (work->unk_00C) {
                case 0:
                    if (func_080FBA9C(work) != 0) {
                        func_080FBA14(work, 3);
                        func_0801853C(work->sub[0].unk_004, work->sub[0].unk_008,
                                      work->sub[0].unk_00C + 0x1200, 512);
                        m4aSongNumStart(0x2A6);
                        work->unk_00C = 1;
                    }
                    break;
                case 1:
                    if (func_08011F78(253, work->sub[0].unk_004,
                                      work->sub[0].unk_008 + 0x1800, 0, 72, 48, 1) != 0) {
                        m4aSongNumStart(0x2CA);
                    }

                    if (func_080128EC() == 0) {
                        work->unk_1B4 &= 0xFFFD;
                        a.unk_00 = &work->unk_02C;
                        a.unk_06 = 0;
                        a.unk_08 = (s32)&work->unk_1B4;

                        if (work->sub[0].unk_02C * 10 / work->sub[0].unk_02E > 4) {
                            switch (GetRandom() % 3) {
                            case 0:
                                a.unk_04 = 0;
                                break;
                            case 1:
                                a.unk_04 = 1;
                                break;
                            case 2:
                                a.unk_04 = 2;
                                break;
                            }
                        } else {
                            switch (GetRandom() % 3) {
                            case 0:
                                a.unk_04 = 3;
                                break;
                            case 1:
                                a.unk_04 = 4;
                                break;
                            case 2:
                                a.unk_04 = 5;
                                break;
                            }
                        }

                        TaskCreate(&work->unk_02C, gTaskDescBosMdFire, &a);
                        func_080FBA14(work, 4);
                        work->unk_00C = 2;
                    }
                    break;
                case 2:
                    if (func_080FBA9C(work) != 0) {
                        func_080FB8DC(work, 0);
                    }
                    break;
            }
            break;
        case 2:
            func_0801AF08(&work->sub[0]);
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FC17C(MdWork* work) {
    u8 result;
    PrizeCardArg arg;

    result = 1;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            func_080FBA14(work, 10);
            func_0801AF4C(&work->sub[0]);
            work->unk_1B4 |= 2;
            work->unk_00C = 0;
            break;
        case 1:
            switch (work->unk_00C) {
            case 0:
                if (func_08006314() == 0) {
                    func_08014AAC(work->sub[0].unk_004,
                                  work->sub[0].unk_008 + work->sub[0].unk_00C);
                    func_08006238(0, gBtlWork->unk_0B3, 8);
                    work->unk_016 = 120;
                    work->unk_00C = 1;
                }
                break;
            case 1:
                work->unk_016--;

                if (work->unk_016 <= 0) {
                    func_0801536C();
                    work->unk_00C = 2;
                }
                break;
            case 2:
                if (work->unk_01C != 0 && func_08006390() == 31) {
                    DisableBg(1);
                    work->unk_01C = 0;
                }

                if (func_080128EC() == 0) {
                    arg.unk_00 = work->sub[0].unk_004;
                    arg.unk_04 = work->sub[0].unk_008;
                    arg.unk_08 = work->sub[0].unk_00C;
                    func_08096DC4(gBtlWork->unk_02C, &arg);
                    func_0801B918(&work->sub[0]);
                    func_0801B008();
                    result = 0;
                }
                break;
            }
            break;
        case 2:
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return result;
}
void func_080FC29C(MdWork* work) {
    s32 d;
    u16 r;

    d = gBtlWork->unk_07C[1];

    if (d > 0xA800) {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 2);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 1);
        }
    } else if (d > 0x7000) {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 1);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 2);
        }
    } else if (d > 0x3800) {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 1);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 2);
        }
    } else {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 2);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 1);
        }
    }
}
void func_080FC360(MdWork* work) {
    s16 i;

    for (i = 0; i < 1; i++) {
        MdSub* e = &work->sub[i];

        switch (func_0801ADAC(e)) {
        case 5:
            func_080FC29C(work);
            break;
        case 1:
        case 6:
        case 7:
            work->unk_01A = 30;
            work->unk_010[i] = 2;
            break;
        case 3:
        case 8:
            func_0801C2DC(e, 1);
            func_080FB8DC(work, 4);
            break;
        case 4:
            func_080FB8DC(work, 0);
            func_0801AF08(e);
            break;
        }
    }
}
void func_080FC3FC(MdWork* work) {
    s16 i;

    for (i = 0; i < 1; i++) {
        MdSub* e = &work->sub[i];

        if (work->unk_010[i] == 2 && work->unk_01A == 0) {
            work->unk_010[i] = 0;
            func_0801AF08(e);
        }
    }
}
void task_bos_md_0(MdWork* work, void* arg) {
    s16 i;

    TaskCreate(&gBtlWork->unk_03C[4], gTaskDescBosMdMap, gUnk_099920E8);
    gBtlWork->unk_068 &= 0xFFFFFFFFFFEFFFFF;
    work->unk_000 = 0;
    work->unk_004 = 0;
    work->unk_014 = 0;
    work->unk_008 = 0;
    work->unk_016 = 0;
    work->unk_018 = 0;
    work->unk_01A = 0;
    work->unk_1B4 = 0;
    work->unk_01C = 1;

    for (i = 0; i < 1; i++) {
        work->unk_010[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        work->unk_17C[i].unk_00 = 0;
        work->unk_17C[i].unk_04 = 0;
        work->unk_17C[i].unk_08 = 0;
        work->unk_17C[i].unk_0C = 0;
        work->unk_17C[i].unk_0E = 0;
    }

    work->unk_17C[0].unk_00 = func_080038C8(2432);
    work->unk_17C[1].unk_00 = LoadObjTiles(gUnk_099D42FC, 0x12A0);
    gBtlWork->unk_0CC = 0x11000;
    gBtlWork->unk_0D0 = 0x15000;
    gBtlWork->unk_0D4 = 0;
    func_0801BCC0(0x7800, gBtlWork->unk_0D0, 0);

    for (i = 0; i < 1; i++) {
        func_0801B37C(&work->sub[i], gUnk_099920D8, gBtlWork->unk_0CC,
                      gBtlWork->unk_0D0, gBtlWork->unk_0D4);
#ifdef VERSION_EU
        func_080122AC(work->sub[i].unk_040, 8, 16, 24);
#else
        func_080122AC(work->sub[i].unk_040, 8, 16, 16);
#endif

        if (i == 0) {
            work->sub[i].unk_034 |= 0x400;
        } else {
            work->sub[i].unk_034 |= 0x1000;
        }

        work->sub[i].unk_034 |= 4;
    }

    func_080FB930(work, 0);
    func_080FBA14(work, 0);
    LoadPalette(gUnk_09A3C97C, (void*)0x05000000, 32);
    func_0801C298(0, 1);
    work->unk_028 = gUnk_09A3C97C;
    work->unk_020 = LoadObjPalette(gUnk_09A3C97C, 32);
    func_0801C298(work->unk_020[6] + 16, 1);
    work->unk_024 = LoadObjPalette(gUnk_08F69BC4, 32);
    func_0801C298(work->unk_024[6] + 16, 1);
    TaskPoolInit(&work->unk_02C, 6);
    TaskPoolInit(&work->unk_040, 1);
    TaskPoolInit(&work->unk_054, 8);
    func_08005244(1, (gBtlWork->unk_000 >> 8) + 72 - work->unk_178,
                  (gBtlWork->unk_004 >> 8) + 48 - work->unk_17A);
}

s32 task_bos_md_1(MdWork* work) {
    void* args[2];
    s32 result;
    s16 i;

    result = 1;
    func_080FC360(work);

    switch (work->unk_000) {
    case 0:
        result = func_080FBAB8(work);
        break;
    case 1:
        result = func_080FBC4C(work);
        break;
    case 2:
        result = func_080FBDD4(work);
        break;
    case 3:
        result = func_080FBFA8(work);
        break;
    case 4:
        result = func_080FC17C(work);
        break;
    }

    func_080FC3FC(work);

    if (func_0801C1C0(0) != 0) {
        args[0] = &work->unk_054;
        args[1] = &work->unk_1B4;
        TaskCreate(&work->unk_040, gTaskDescBosMdDai, args);
    }

    func_080FBA4C(work);

    if (work->unk_01A > 0) {
        work->unk_01A--;
    }

    for (i = 0; i < 1; i++) {
        work->sub[i].unk_004 = gBtlWork->unk_0CC
            + gUnk_09992108[(s16)work->unk_1A4.unk_04[work->unk_1A4.unk_0A].unk_00]
                  .unk_44[i].unk_00 * 256;
        work->sub[i].unk_008 = gBtlWork->unk_0D0
            + gUnk_09992108[(s16)work->unk_1A4.unk_04[work->unk_1A4.unk_0A].unk_00]
                  .unk_44[i].unk_02 * 256;
        work->sub[i].unk_00C = gBtlWork->unk_0D4
            + gUnk_09992108[(s16)work->unk_1A4.unk_04[work->unk_1A4.unk_0A].unk_00]
                  .unk_44[i].unk_04 * 256;
        func_08012324(work->sub[i].unk_040, work->sub[i].unk_004, work->sub[i].unk_008,
                      work->sub[i].unk_00C);
    }

    TaskPoolUpdate(&work->unk_02C);
    TaskPoolUpdate(&work->unk_040);
    TaskPoolUpdate(&work->unk_054);
    return result;
}

void task_bos_md_2(MdWork* work) {
    s16 x;
    s16 y;
    void* pal;
    void* p1;
    void* p2;
    void* p0;
    s32 i;

    if (work->unk_01C == 0) {
        return;
    }

    if (func_0801CA00(&work->sub[0]) != 0) {
        if (work->unk_028 != gUnk_08F69BC4) {
            LoadPalette(gUnk_08F69BC4, (void*)0x05000000, 32);
            work->unk_028 = gUnk_08F69BC4;
        }

        pal = work->unk_024;
    } else {
        if (work->unk_028 != gUnk_09A3C97C) {
            LoadPalette(gUnk_09A3C97C, (void*)0x05000000, 32);
            work->unk_028 = gUnk_09A3C97C;
        }

        pal = work->unk_020;
    }

    x = (gBtlWork->unk_000 >> 8) - (work->unk_178 - 72);
    y = (gBtlWork->unk_004 >> 8) - (work->unk_17A - 48);
    func_08005244(1, x, y);
    p0 = &work->unk_02C;
    p1 = &work->unk_040;
    p2 = &work->unk_054;

    for (i = 0; i < 2; i++) {
        s32 wx;
        s32 wy;
        u16 frame;

        wx = (work->unk_17C[i].unk_0C + 224) * 256;
        wy = (work->unk_17C[i].unk_0E + 256) * 256;
        WorldToScreen(&x, &y, wx, wy, work->unk_17C[i].unk_10 * 256);
        frame = func_0801AF1C(wy);
        DrawSprite(x, y, work->unk_17C[i].unk_08, work->unk_17C[i].unk_00, pal, 0, frame,
                   (u16)(-4100 - (wy >> 6)));
    }

    TaskPoolDraw(p0);
    TaskPoolDraw(p1);
    TaskPoolDraw(p2);
}

void task_bos_md_3(MdWork* work) {
    void* q;
    void* r;
    void* t;
    s32 i;

    DisableBg(1);

    for (i = 0; i < 1; i++) {
        func_08012304(work->sub[i].unk_040);
        func_0801B7D8(&work->sub[i]);
    }

    q = &work->unk_02C;
    r = &work->unk_040;
    t = &work->unk_054;

    for (i = 0; i < 2; i++) {
        if (work->unk_17C[i].unk_00 != 0) {
            ReleaseObjTiles(work->unk_17C[i].unk_00);
        }
    }

    ReleaseObjPalette((void*)work->unk_020);
    ReleaseObjPalette((void*)work->unk_024);
    TaskPoolDestroy(q);
    TaskPoolDestroy(r);
    TaskPoolDestroy(t);
}

void task_bos_md_map_0(MdMapWork* work, MdMapData* p) {
    LoadBgTiles(0, p->unk_00, p->unk_04);
    LoadBgPalette(0, p->unk_08, p->unk_0C);
    func_0800516C(0, &p->unk_10, 2, 2);
    gBtlWork->unk_024 = 256;
    gBtlWork->unk_028 = 256;
    gBtlWork->unk_008 = 0x10000;
    gBtlWork->unk_00C = 0x14000;
    gBtlWork->unk_000 = 0x10000;
    gBtlWork->unk_004 = 0x14000;
    gBtlWork->unk_010 = 0x10000;
    gBtlWork->unk_014 = 0x14000;
    gBtlWork->unk_01C = 0x10000;
    gBtlWork->unk_020 = 0x14000;
    gBtlWork->unk_01A = 15;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}
s32 task_bos_md_map_1(MdMapWork* work) {
    s32 dx;
    s32 dy;

    func_0802F208();
    dx = (gBtlWork->unk_010 - gBtlWork->unk_008) >> 3;
    dy = (gBtlWork->unk_014 - gBtlWork->unk_00C) >> 3;

    if (dx > 1280) {
        dx = 1280;
    } else if (dx < -1280) {
        dx = -1280;
    }

    gBtlWork->unk_008 += dx;
    gBtlWork->unk_00C += dy;
    gBtlWork->unk_000 = gBtlWork->unk_008;
    gBtlWork->unk_004 = gBtlWork->unk_00C;

    if (gBtlWork->unk_000 - 30720 < gBtlWork->unk_0DA * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 120) * 256;
    } else if (gBtlWork->unk_000 + 30720 > (gBtlWork->unk_0DC + 96) * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 24) * 256;
    }

    if (gBtlWork->unk_004 + 20480 < gBtlWork->unk_0DE * 256) {
        gBtlWork->unk_004 = (gBtlWork->unk_0DE - 80) * 256;
    } else if (gBtlWork->unk_004 + 20480 > gBtlWork->unk_0E0 * 256) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 80) * 256;
    }

    gBtlWork->unk_004 += func_0802F268();
    func_08005244(0, (gBtlWork->unk_000 >> 8) + 8, (gBtlWork->unk_004 >> 8) + 40);
    return 1;
}
void func_080FCC14(MdFireWork* work) {
    MdSub* e;

    e = &work->unk_038;

    switch (func_0801ADAC(e)) {
    case 1:
    case 6:
    case 7:
        work->unk_006 = 30;
        work->unk_000 = 3;
        break;
    case 3:
    case 8:
        if (GetRandom() % 100 <= 49) {
            if ((gBtlWork->unk_068 & 0x100000) == 0) {
                _0801C1F8(0, e->unk_004, e->unk_008, e->unk_00C);
            }
        }

        func_0801C2DC(e, 1);
        work->unk_034 = 30;
        work->unk_000 = 4;
        break;
    }
}
u8 func_080FCCB4(MdFireWork* work) {
    u8 result;
    MdSub* e;
    u8 a;

    result = 1;
    e = &work->unk_038;

    if ((work->unk_16C->unk_00 & 2) && work->unk_000 != 4) {
        func_0801C2DC(e, 1);
        work->unk_034 = 30;
        work->unk_000 = 4;
    }

    switch (work->unk_000) {
        case 0:
            work->unk_034--;

            if (work->unk_034 <= 0) {
                func_0801C2DC(e, 0);
                work->unk_000 = 1;
            }
            break;
        case 1:
            switch (work->unk_15C) {
                case 0:
                    if (work->unk_004 > 0) {
                        work->unk_004--;

                        if (work->unk_004 <= 0) {
                            switch (work->unk_15E) {
                            case 0:
                            case 1:
                            case 2:
                            case 4:
                                a = func_080F7E0C(work->x, work->y,
                                                  gBtlWork->unk_07C[1],
                                                  gBtlWork->unk_07C[2]);
                                work->unk_154 = gSineTable[a] * 3;
                                work->unk_158 = -gSineTable[a + 0x40] * 3;
                                work->unk_004 = 90;
                                work->unk_15C = 1;
                                break;
                            case 3:
                                work->unk_15C = 2;
                                break;
                            case 5:
                                work->unk_15C = 3;
                                break;
                            }
                        }
                    }
                    break;
                case 1:
                    work->x += work->unk_154;
                    work->y += work->unk_158;
                    work->unk_004--;

#ifdef VERSION_EU
                    if (work->unk_004 <= 0 || work->y <= 0x12FFF) {
#else
                    if (work->unk_004 <= 0 || work->y <= 0x117FF) {
#endif
                        func_0801C2DC(e, 1);
                        work->unk_034 = 30;
                        work->unk_000 = 4;
                    }
                    break;
                case 2:
                    work->unk_162++;
                    work->x = gSineTable[work->unk_162] * 40 + work->unk_164;
                    work->y = -gSineTable[work->unk_162 + 0x40] * 40 + work->unk_168;
                    break;
                case 3:
                    work->unk_162++;
                    work->x = gSineTable[work->unk_162] * 32 + work->unk_164;
                    break;
            }

            if (work->unk_008 > 0) {
                work->unk_008--;
            } else if (func_08012660(work->unk_038.unk_040, 1) != 0) {
                m4aSongNumStart(0x2CA);
                *(u64*)&gBtlWork->unk_07C[13] |= 0x20000000;
                work->unk_008 = 60;
            }
            break;
        case 2:
            break;
        case 3:
            if (work->unk_006 == 0) {
                work->unk_000 = 1;
                func_0801AF08(e);
            }
            break;
        case 4:
            work->unk_034--;

            if (work->unk_034 <= 0) {
                result = 0;
            }
            break;
    }

    return result;
}
void func_080FCF78(MdFireWork* work) {
    MdFirePoint* p;

    switch (work->unk_15E) {
    case 0:
    case 1:
    case 2:
        p = gUnk_09992EF8[work->unk_15E].unk_00 + work->unk_160;
        work->x = p->unk_00 * 256;
        work->y = p->unk_02 * 256;
        work->unk_004 = p->unk_04;
        work->unk_15C = 0;
        break;
    case 3:
        work->unk_162 = work->unk_160 * 256 / 6;
        work->unk_164 = 0x8000;
        work->unk_168 = 0x14800;
        work->x = gSineTable[work->unk_162] * 40 + work->unk_164;
        work->y = -gSineTable[work->unk_162 + 0x40] * 40 + work->unk_168;
        work->unk_004 = 60;
        work->unk_15C = 0;
        break;
    case 4:
        work->x = GetRandom() % 96 * 256 + 0x9800;
        work->y = work->unk_160 * 4096 + 0x11800;
        work->unk_004 = work->unk_160 * 60 + 240;
        work->unk_15C = 0;
        break;
    case 5:
        work->unk_162 = 0;
        work->unk_164 = 0x9800;
        work->x = gSineTable[work->unk_162] * 32 + work->unk_164;
        work->y = work->unk_160 * 4096 + 0x11800;
        work->unk_004 = work->unk_160 * 256 / 6 + 60;
        work->unk_15C = 0;
        break;
    }
}
void task_bos_md_fire_0(MdFireWork* work, MdFireArg* arg) {
    MdFireArg a;
    s16 i;
    s16 n;

    work->unk_006 = 0;
    work->unk_008 = 0;
    work->unk_030 = 25;
    work->unk_034 = 30;
    work->unk_000 = 0;
    work->z = 0;
    work->unk_15E = arg->unk_04;
    work->unk_160 = arg->unk_06;
    work->unk_16C = (MdFireTarget*)arg->unk_08;
    func_080FCF78(work);
    func_0801B37C(&work->unk_038, gUnk_09992F28, work->x, work->y, work->z);
    func_080122AC(work->unk_038.unk_040, 3, 16, 16);
    func_08012324(work->unk_038.unk_040, work->unk_038.unk_004, work->unk_038.unk_008,
                  work->unk_038.unk_00C);
    work->unk_038.unk_034 |= 0x1000;
    work->unk_038.unk_02C = 20;
    work->unk_038.unk_02E = 20;
    func_0801C2DC(&work->unk_038, 1);
    work->unk_00C = (u32)LoadObjPalette(gUnk_09A3C99C, 32);
    work->unk_010 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    work->tiles = (u32)LoadObjTiles(gUnk_099E367C, 0x800);
    AnimInit(&work->anim, gUnk_09EF9BC0, gUnk_09EF9BB0);
    AnimStart(&work->anim, 0, 1);
    a.unk_00 = 0;
    a.unk_04 = arg->unk_04;
    a.unk_08 = arg->unk_08;

    if (arg->unk_00 != 0) {
        if (work->unk_15E <= 2) {
            n = gUnk_09992EF8[work->unk_15E].unk_04;
        } else {
            n = 6;
        }

        for (i = 1; i < n; i++) {
            a.unk_06 = i;
            TaskCreate(arg->unk_00, gTaskDescBosMdFire, &a);
        }
    }
}

u8 task_bos_md_fire_1(MdFireWork* work) {
    u8 result;

    func_080FCC14(work);
    result = func_080FCCB4(work);

    if ((s16)work->unk_006 > 0) {
        work->unk_006--;
    }

    work->unk_038.unk_004 = work->x;
    work->unk_038.unk_008 = work->y;
    work->unk_038.unk_00C = work->z;
    func_08012324(work->unk_038.unk_040, work->unk_038.unk_004, work->unk_038.unk_008,
                  work->unk_038.unk_00C);
    return result;
}

void task_bos_md_fire_2(MdFireWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 sprite;
    u16 frame;

    if (work->unk_006 > 0 && (gFrameCounter & 1)) {
        gfx = (void*)work->unk_010;
    } else {
        gfx = (void*)work->unk_00C;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    frame = func_0801AF1C(work->y);

    if (work->unk_000 == 0) {
        ApproachValue(&work->unk_030, 0x100, work->unk_034);
        sprite = AllocObjAffine(0, work->unk_030, work->unk_030, 0);
    } else if (work->unk_000 == 4) {
        ApproachValue(&work->unk_030, 25, work->unk_034);
        sprite = AllocObjAffine(0, work->unk_030, work->unk_030, 0);
    } else {
        sprite = 0;
    }

    DrawSprite(x, y, AnimUpdate(&work->anim), (void*)work->tiles, gfx,
                  sprite, frame, (u16)(-4100 - (work->y >> 8) * 4));
}

void task_bos_md_fire_3(MdFireWork* work) {
    func_08012304(work->unk_038.unk_040);
    func_0801B7D8(&work->unk_038);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    ReleaseObjTiles((void*)work->tiles);
}

void task_bos_md_dai_0(MdDaiWork* work, s32* src) {
    u8* p;

    gBtlWork->unk_068 |= 0x100000;
    work->unk_078 = (MdDaiTarget*)src[1];
    work->unk_080 = (void*)src[0];
    work->unk_07C = 0;
    work->unk_07E = 0;
    work->x = 0x8000;
    work->y = 0x14F00;
    work->z = 0;
    work->unk_010 = 20;
    work->unk_00C = -40960;
    p = (u8*)work + 0x1C;
    func_080122AC(p, 7, 24, 24);
    func_08012324(p, work->x, work->y, work->z);
    func_08012614(p, 1);
    work->palette = (u32)LoadObjPalette(gUnk_09A3C9BC, 32);
    work->tiles = (u32)LoadObjTiles(gUnk_09999ED0, 0x480);
}

s32 task_bos_md_dai_1(MdDaiWork* work) {
    s32 result;
    s32 args[3];
    s16 i;
    s16 n;

    result = 1;

    switch (work->unk_07E) {
    case 0:
        ApproachValue(&work->unk_00C, 0, work->unk_010);
        work->unk_010--;

        if (work->unk_010 <= 0) {
            func_08012614(&work->unk_01C, 0);
            ColliderSetHeight(&work->unk_01C, 8);
            work->unk_00C = work->z - 0xA000;
            m4aSongNumStart(680);
            work->unk_07C = 1;
            work->unk_010 = 20;
            work->unk_07E = 1;
        }
        break;
    case 1:
        ApproachValue(&work->unk_00C, -3584, work->unk_010);
        work->unk_010--;

        if (work->unk_010 <= 0) {
            func_08012614(&work->unk_01C, 0);
            ColliderSetHeight(&work->unk_01C, 16);
            work->unk_00C = work->z - 0xA000;
            m4aSongNumStart(680);
            work->unk_07C = 2;
            work->unk_010 = 20;
            work->unk_07E = 2;
        }
        break;
    case 2:
        ApproachValue(&work->unk_00C, -7168, work->unk_010);
        work->unk_010--;

        if (work->unk_010 <= 0) {
            func_08012614(&work->unk_01C, 0);
            ColliderSetHeight(&work->unk_01C, 24);
            m4aSongNumStart(680);
            work->unk_07C = 3;
            work->unk_078->unk_00 &= 0xFFFE;
            work->unk_07E = 3;
        }
        break;
    case 3:
        if (work->unk_078->unk_00 & 1) {
            work->unk_078->unk_00 &= 0xFFFE;
            args[0] = work->x;
            args[1] = work->y;
            args[2] = -((work->unk_07C - 1) * 7 << 9);
            n = GetRandom() % 3 + 3;

            for (i = 0; i < n; i++) {
                TaskCreate(work->unk_080, gTaskDescBosMdHahen, args);
            }

            work->unk_07C--;

            if (work->unk_07C <= 0) {
                func_08012614(&work->unk_01C, 1);
                result = 0;
            } else {
                ColliderSetHeight(&work->unk_01C, work->unk_07C * 8);
            }
        }
        break;
    }

    return result;
}
void task_bos_md_dai_2(MdDaiWork* work) {
    s16 x;
    s16 y;
    u16 frame;

    WorldToScreen(&x, &y, work->x, work->y, work->z + work->unk_00C);
    frame = func_0801AF1C(work->y);

    if (work->unk_07E <= 2) {
        DrawSprite(x, y + 24, gUnk_09999E0C, (void*)work->tiles, (void*)work->palette, 0,
                      frame, (u16)(-4100 - (work->y >> 8) * 4));
        DrawSprite(x, y, gUnk_09999E1C, (void*)work->tiles, (void*)work->palette, 0, frame,
                      (u16)(-4100 - (work->y >> 8) * 4));
        DrawSprite(x + 8, y - 16, gUnk_09999E0C, (void*)work->tiles, (void*)work->palette, 0,
                      frame, (u16)(-4100 - (work->y >> 8) * 4));
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    frame = func_0801AF1C(work->y);

    if (work->unk_07C > 0) {
        DrawSprite(x, y, (void*)gUnk_09EF9740[work->unk_07C + 1], (void*)work->tiles,
                      (void*)work->palette, 0, frame,
                      (u16)(-4100 - (work->y >> 8) * 4));
    }
}

void task_bos_md_dai_3(MdDaiWork* work) {
    func_08012304(&work->unk_01C);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjTiles((void*)work->tiles);
    gBtlWork->unk_068 &= 0xFFFFFFFFFFEFFFFF;
}

void task_bos_md_hahen_0(MdHahenWork* work, s32* src) {
    u8 angle;
    s32 speed;

    work->x = src[0];
    work->y = src[1];
    work->z = src[2];
    angle = GetRandom();
    speed = (GetRandom() & 0x1FF) + 0x100;
    work->unk_00C = -gSineTable[angle + 0x40] * speed >> 8;
    work->unk_010 = gSineTable[angle] * speed >> 8;
    work->unk_014 = -((GetRandom() & 0x1FF) + 0x100);
    work->unk_024 = 3;
    work->palette = (u32)LoadObjPalette(gUnk_09A3C9BC, 32);
    work->tiles = (u32)LoadObjTiles(gUnk_09999ED0, 0x480);
    work->unk_020 = gUnk_09EF9740[GetRandom() % 2];
}

s32 task_bos_md_hahen_1(MdHahenWork* work) {
    s32 result;

    result = 1;
    work->x += work->unk_00C;
    work->y += work->unk_010;

#ifdef VERSION_EU
    if (work->y <= 0x12FFF) {
#else
    if (work->y <= 0x117FF) {
#endif
        work->unk_010 = -work->unk_010;
    }

    work->z += work->unk_014;
    work->unk_014 += 102;

    if (work->z > 0) {
        work->z = 0;
        work->unk_014 = -(work->unk_014 * 8 / 10);
        work->unk_024--;

        if ((s16)work->unk_024 <= 0) {
            result = 0;
        }
    }

    return result;
}

void task_bos_md_hahen_2(MdHahenWork* work) {
    s16 x;
    s16 y;
    u16 frame;
    s32 flag;

    flag = gFrameCounter & 1;

    if (flag != 0) {
        return;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    frame = func_0801AF1C(work->y);
    DrawSprite(x, y, (void*)work->unk_020, (void*)work->tiles, (void*)work->palette,
                  flag, frame, (u16)(-4100 - (work->y >> 8) * 4));
}

void task_bos_md_hahen_3(MdHahenWork* work) {
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjTiles((void*)work->tiles);
}

void func_080FD9B8(s16 model, s16 slot) {
    void* src;
    s32 size;

    if (gUnk_09992F70[model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_09A3CDDC;
        size = 0x40;
    } else {
        src = gUnk_09992F70[model].unk_08;
        size = 0x20;
    }

    gUnk_02034FF8[slot].unk_0C = LoadObjPalette(src, size);
}

void func_080FDA28(s16 model, s16 slot) {
    void* src;

    if (gUnk_09992F70[model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_099EDE7C;
    } else {
        src = gUnk_09992F70[model].unk_0C;
    }

    gUnk_02034FF8[slot].unk_10 = LoadObjTiles(src, 0x1000);
}

s16 func_080FDA98(s16 model, s16 slot) {
    if (gUnk_09992F70[model].unk_02 == 13 && func_080D2DD8()) {
        gUnk_02034FF8[slot].unk_14 = gUnk_099A8914;
    } else {
        gUnk_02034FF8[slot].unk_14 = gUnk_09992F70[model].unk_10;
    }
}

#ifndef VERSION_EU
void func_080FDB1C(s16 model, s16 n) {
    vu32* dma;
    u16 zero;
    u8* src;
    u8* src2;
    u8* dst;
    u32 ctrl;
    u16* zp;

    zp = &zero;
    zero = 0;
    dma = (vu32*)0x040000D4;
    dma[0] = (vu32)zp;
    dma[1] = (vu32)gUnk_020350BC;
    dma[2] = 0x81000360;
    dma[2];

    if (n > 0) {
        src = gUnk_09992F70[model].unk_14;
        dma[0] = (vu32)src;
        dst = (u8*)gUnk_020350BC + (9 - n) * 32;
        dma[1] = (vu32)dst;
        ctrl = (n << 4) | 0x80000000;
        dma[2] = ctrl;
        dma[2];
        src2 = src + (18 - n) * 32;
        dma[0] = (vu32)src2;
        dma[1] = (vu32)((u8*)gUnk_020350BC + 288);
        dma[2] = ctrl;
        dma[2];
        dma[0] = (vu32)(src + 576);
        dma[1] = (vu32)(dst + 576);
        dma[2] = ctrl;
        dma[2];
        dma[0] = (vu32)(src2 + 576);
        dma[1] = (vu32)((u8*)gUnk_020350BC + 864);
        dma[2] = ctrl;
        dma[2];
        src += 1152;
        dma[0] = (vu32)src;
        dst += 1152;
        dma[1] = (vu32)dst;
        dma[2] = ctrl;
        dma[2];
        src2 += 1152;
        dma[0] = (vu32)src2;
        dma[1] = (vu32)((u8*)gUnk_020350BC + 1440);
        dma[2] = ctrl;
        dma[2];
    }

    RequestDma3Copy(gUnk_020350BC, (u8*)GetBgCharBase(0) + 1024, 0x6C0);
}
#else
INCLUDE_ASM("bos5/func_080FDB1C.s");
#endif

void func_080FDC04(void) {
    s16 i;
    s16 j;
    s16 k;
    u8 step;

    switch (gUnk_0203508C) {
    case 0:
        if (GetKeysPressed() & 1) {
            func_080065FC(2, 0x8000, 128);
            func_08006778(gUnk_09EDABA0 + 0x18, 112, 126);
            SetBgPriority(2, 1);
            gBldCnt |= 0x1000;
            gUnk_020350EF = 1;
            m4aSongNumStart(206);
            gUnk_020350F0 = 0;
            gUnk_020350C0 = 4;
        } else if ((GetKeysPressed() & 2) && gUnk_020350EE == 0) {
            m4aSongNumStart(104);
            LoadBgMap(0, gUnk_09A310DC, 0x500);
            LoadBgMap(1, gUnk_09A31ADC, 0x500);
            gUnk_020350F0 = 1;
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 5;
        } else if (gUnk_02035090 > 1) {
            if (GetKeysHeld() & 0x20) {
                j = gUnk_02034FF0 - gUnk_02035090 / 2;

                while (j < 0) {
                    j += gUnk_02035090;
                }

                ReleaseObjPalette(gUnk_02034FF8[j].unk_0C);
                ReleaseObjTiles(gUnk_02034FF8[j].unk_10);
                k = gUnk_02034FF8[gUnk_02034FF0].unk_00 - gUnk_02035090 / 2;

                while (k < 0) {
                    k += gUnk_02035092;
                }

                gUnk_02034FF8[j].unk_00 = k;
                func_080FD9B8(gUnk_02035070[k], j);
                func_080FDA28(gUnk_02035070[k], j);
                func_080FDA98(gUnk_02035070[k], j);
                gUnk_02034FF0--;

                if (gUnk_02034FF0 < 0) {
                    gUnk_02034FF0 = gUnk_02035090 - 1;
                }

                m4aSongNumStart(205);
                gUnk_020350B6 = 2;
                gUnk_0203508C = 2;
            } else if (GetKeysHeld() & 0x10) {
                j = gUnk_02034FF0 + gUnk_02035090 / 2;

                while (j >= gUnk_02035090) {
                    j -= gUnk_02035090;
                }

                ReleaseObjPalette(gUnk_02034FF8[j].unk_0C);
                ReleaseObjTiles(gUnk_02034FF8[j].unk_10);
                k = gUnk_02034FF8[gUnk_02034FF0].unk_00 + gUnk_02035090 / 2;

                while (k >= gUnk_02035092) {
                    k -= gUnk_02035092;
                }

                gUnk_02034FF8[j].unk_00 = k;
                func_080FD9B8(gUnk_02035070[k], j);
                func_080FDA28(gUnk_02035070[k], j);
                func_080FDA98(gUnk_02035070[k], j);
                gUnk_02034FF0++;

                if (gUnk_02034FF0 >= gUnk_02035090) {
                    gUnk_02034FF0 = 0;
                }

                m4aSongNumStart(205);
                gUnk_020350B6 = 2;
                gUnk_0203508C = 1;
            }
        }
        break;
    case 1:
        if (GetKeysHeld() & 0x20) {
            j = gUnk_02034FF0 - gUnk_02035090 / 2;

            while (j < 0) {
                j += gUnk_02035090;
            }

            ReleaseObjPalette(gUnk_02034FF8[j].unk_0C);
            ReleaseObjTiles(gUnk_02034FF8[j].unk_10);
            k = gUnk_02034FF8[gUnk_02034FF0].unk_00 - gUnk_02035090 / 2;

            while (k < 0) {
                k += gUnk_02035092;
            }

            gUnk_02034FF8[j].unk_00 = k;
            func_080FD9B8(gUnk_02035070[k], j);
            func_080FDA28(gUnk_02035070[k], j);
            func_080FDA98(gUnk_02035070[k], j);
            gUnk_02034FF0--;

            if (gUnk_02034FF0 < 0) {
                gUnk_02034FF0 = gUnk_02035090 - 1;
            }

            m4aSongNumStart(205);
            gUnk_0203508C = 2;
        } else {
            for (i = 0; i < gUnk_02035090; i++) {
                gUnk_02034FF8[i].unk_08 -= 2;
            }

            if (gUnk_02034FF8[gUnk_02034FF0].unk_08 <= 128) {
                if (GetKeysHeld() & 0x10) {
                    j = gUnk_02034FF0 + gUnk_02035090 / 2;

                    while (j >= gUnk_02035090) {
                        j -= gUnk_02035090;
                    }

                    ReleaseObjPalette(gUnk_02034FF8[j].unk_0C);
                    ReleaseObjTiles(gUnk_02034FF8[j].unk_10);
                    k = gUnk_02034FF8[gUnk_02034FF0].unk_00 + gUnk_02035090 / 2;

                    while (k >= gUnk_02035092) {
                        k -= gUnk_02035092;
                    }

                    gUnk_02034FF8[j].unk_00 = k;
                    func_080FD9B8(gUnk_02035070[k], j);
                    func_080FDA28(gUnk_02035070[k], j);
                    func_080FDA98(gUnk_02035070[k], j);
                    gUnk_02034FF0++;

                    if (gUnk_02034FF0 >= gUnk_02035090) {
                        gUnk_02034FF0 = 0;
                    }

                    m4aSongNumStart(205);
                    gUnk_0203508C = 1;
                } else {
                    step = 128 - gUnk_02034FF8[gUnk_02034FF0].unk_08;

                    for (i = 0; i < gUnk_02035090; i++) {
                        gUnk_02034FF8[i].unk_08 += step;
                    }

                    gUnk_020350B6 = 1;
                    gUnk_020350BA = gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00];
                    gUnk_0203508C = 0;
                }
            }
        }
        break;
    case 2:
        if (GetKeysHeld() & 0x10) {
            j = gUnk_02034FF0 + gUnk_02035090 / 2;

            while (j >= gUnk_02035090) {
                j -= gUnk_02035090;
            }

            ReleaseObjPalette(gUnk_02034FF8[j].unk_0C);
            ReleaseObjTiles(gUnk_02034FF8[j].unk_10);
            k = gUnk_02034FF8[gUnk_02034FF0].unk_00 + gUnk_02035090 / 2;

            while (k >= gUnk_02035092) {
                k -= gUnk_02035092;
            }

            gUnk_02034FF8[j].unk_00 = k;
            func_080FD9B8(gUnk_02035070[k], j);
            func_080FDA28(gUnk_02035070[k], j);
            func_080FDA98(gUnk_02035070[k], j);
            gUnk_02034FF0++;

            if (gUnk_02034FF0 >= gUnk_02035090) {
                gUnk_02034FF0 = 0;
            }

            m4aSongNumStart(205);
            gUnk_0203508C = 1;
        } else {
            for (i = 0; i < gUnk_02035090; i++) {
                gUnk_02034FF8[i].unk_08 += 2;
            }

            if ((s8)gUnk_02034FF8[gUnk_02034FF0].unk_08 < 0) {
                if (GetKeysHeld() & 0x20) {
                    j = gUnk_02034FF0 - gUnk_02035090 / 2;

                    while (j < 0) {
                        j += gUnk_02035090;
                    }

                    ReleaseObjPalette(gUnk_02034FF8[j].unk_0C);
                    ReleaseObjTiles(gUnk_02034FF8[j].unk_10);
                    k = gUnk_02034FF8[gUnk_02034FF0].unk_00 - gUnk_02035090 / 2;

                    while (k < 0) {
                        k += gUnk_02035092;
                    }

                    gUnk_02034FF8[j].unk_00 = k;
                    func_080FD9B8(gUnk_02035070[k], j);
                    func_080FDA28(gUnk_02035070[k], j);
                    func_080FDA98(gUnk_02035070[k], j);
                    gUnk_02034FF0--;

                    if (gUnk_02034FF0 < 0) {
                        gUnk_02034FF0 = gUnk_02035090 - 1;
                    }

                    m4aSongNumStart(205);
                    gUnk_0203508C = 2;
                } else {
                    step = gUnk_02034FF8[gUnk_02034FF0].unk_08 + 128;

                    for (i = 0; i < gUnk_02035090; i++) {
                        gUnk_02034FF8[i].unk_08 -= step;
                    }

                    gUnk_020350B6 = 1;
                    gUnk_020350BA = gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00];
                    gUnk_0203508C = 0;
                }
            }
        }
        break;
    }
}

#ifndef VERSION_EU
void func_080FE47C(void) {
    s16 i;
    s32 sprite;
    s16 x;
    s16 y;
    u8 ang;
    u8 t;
    s32 s;
    s32 h;
    s32 d;
    s32 w;
    s32 v;
    s16 angle;
    void* anim;
    void* tiles;
    void* pal;

    if (gUnk_020350C0 < 2 || gUnk_020350C0 > 4) {
        DrawSprite(gUnk_020350D0 >> 8, 0, gUnk_0999CB90, gUnk_020350A8, gUnk_020350AC, 0, 0x400,
                      0x3E8);
        DrawSprite(120, gUnk_020350C8[0] >> 8, gUnk_0999C394, gUnk_020350B0, gUnk_020350AC, 0,
                      0x400, 0x3E9);
        DrawSprite(120, gUnk_020350C8[1] >> 8, gUnk_0999C3C8, gUnk_020350B0, gUnk_020350AC, 0,
                      0xC00, 0xBBA);
    }

    for (i = 0; i < gUnk_02035090; i++) {
        ang = gUnk_02034FF8[i].unk_08;
        s = -gSineTable[((256 / gUnk_02035090 * i + gUnk_020350B4) & 0xFF) + 64];
        t = (s * 3 >> 7) + ang;

        if ((u8)(t - 62) > 2 && (u8)(t + 64) > 2) {
            h = -gSineTable[ang + 64] * 5 >> 5;
            d = -25600 / (h - 140);
            w = -gSineTable[t + 64] * d >> 8;
            angle = ang;
            x = (gSineTable[angle] * 5 >> 4) + 120;
            v = ((d << 3) * s >> 16) + 64;
            y = h + v;

            if ((u8)(t - 121) <= 14) {
                sprite = 0;
                tiles = gUnk_02035098[0];
                pal = gUnk_020350A0[0];
                anim = gUnk_0999A350;

                if (gUnk_020350C0 > 3 && gUnk_020350F0 == 0) {
                    func_080066F4(x - 1, y - 5);
                }
            } else if (t <= 61) {
                sprite = 0;
                tiles = gUnk_02035098[1];
                pal = gUnk_020350A0[1];
                anim = gUnk_09EF9770[(62 - t) / 13];
            } else if (t > 194) {
                sprite = 0;
                tiles = gUnk_02035098[1];
                pal = gUnk_020350A0[1];
                anim = gUnk_09EF9770[(t - 194) / 13];
            } else {
                sprite = AllocObjAffine(0, w, d, 0);
                tiles = gUnk_02035098[0];
                pal = gUnk_020350A0[0];
                anim = gUnk_0999A350;
            }

            DrawSprite(x, y, anim, tiles, pal, sprite, 0x800,
                          ang > 128 ? (u16)(ang * 2 + 0x6D1) : (u16)((128 - ang) * 2 + 0x7D1));

            if ((u8)(t - 65) <= 126) {
                DrawSprite(x, y, gUnk_02034FF8[i].unk_14, gUnk_02034FF8[i].unk_10,
                              gUnk_02034FF8[i].unk_0C, sprite, 0x800,
                              ang > 128 ? (u16)(ang * 2 + 0x6D0)
                                        : (u16)((128 - ang) * 2 + 0x7D0));
            }
        }
    }

    switch (gUnk_020350B6) {
    case 1:
        func_080FDB1C(gUnk_020350BA, gUnk_020350B8);

        if (gUnk_020350B8 <= 8) {
            gUnk_020350B8++;
        } else {
            gUnk_020350B6 = 0;
        }
        break;
    case 2:
        func_080FDB1C(gUnk_020350BA, gUnk_020350B8);

        if (gUnk_020350B8 > 0) {
            gUnk_020350B8--;
        } else {
            gUnk_020350B6 = 0;
        }
        break;
    }

    if (gUnk_020350EF != 0) {
        func_08006954();
    }

    TaskPoolDraw(&gUnk_020350D8);
}
#else
INCLUDE_ASM("bos5/func_080FE47C.s");
#endif

void func_080FE854(void) {
    SetBgMode0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 1, 30, 14);
    SetBgPriority(0, 3);
    SetBgPriority(1, 1);
    SetBgPriority(2, 0);
}
void func_080FE89C(void) {
    SetBgMode1();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 1, 30, 10);
    SetBgPriority(0, 3);
    SetBgPriority(1, 0);
    SetBgPriority(2, 2);
    gBldCnt = 0x344;
    gBldAlpha = 0x1010;
}
void func_080FE900(void) {
    gUnk_020350F2++;

    if (gUnk_020350F2 > 6) {
        gUnk_020350F2 = 0;
        gUnk_020350F4++;

        if (gUnk_020350F4 > 29) {
            gUnk_020350F4 = 0;
        }

        LoadPalette(gUnk_09EF8F24[(s16)gUnk_020350F4], (void*)0x05000040, 32);
    }
}

#ifndef VERSION_EU
void mode_worldselect_0(void) {
    s16 i;
    s16 j;
    void** p;

    SpriteReset();
    gUnk_020350EE = (gGameState.unk_17A ^ 1) & 1;
    gUnk_020350EF = 0;
    gUnk_020350F0 = 0;
    func_08006120(2, 16);

    if (gUnk_020350EE != 0) {
        func_080FE854();
    } else {
        func_080FE89C();
    }

    gUnk_02034FF0 = 0;
    gUnk_0203508C = 0;
    j = 0;

    for (i = 0; i <= 12; i++) {
        if (gUnk_02039D30 & gUnk_09992F70[i].unk_00) {
            gUnk_02035070[j] = i;
            j++;
        }
    }

    gUnk_02035092 = j;
    gUnk_02035090 = j > 5 ? 5 : j;
    j = 0;

    for (i = 0; i < gUnk_02035090; i++, j++) {
        if (j >= gUnk_02035092) {
            j = 0;
        }

        if (i == gUnk_02035090 - 1 && gUnk_02035090 > 2) {
            j = gUnk_02035092 - 1;
        }

        gUnk_02034FF8[i].unk_00 = j;
        gUnk_02034FF8[i].unk_08 = 256 / gUnk_02035090 * i - 128;
        func_080FD9B8(gUnk_02035070[j], i);
        func_080FDA28(gUnk_02035070[j], i);
        func_080FDA98(gUnk_02035070[j], i);
    }

    gUnk_020350B4 = 0;
    gUnk_020350B6 = 1;
    gUnk_020350B8 = 0;
    gUnk_020350BA = gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00];
    p = &gUnk_020350BC;
    *p = EwramAlloc(0x6C0);
    gUnk_020350F2 = 0;
    gUnk_020350F4 = 0;
    gUnk_020350C0 = 0;
    gUnk_020350C2 = 16;
    gUnk_020350C8[0] = -2048;
    gUnk_020350C8[1] = 0xA800;
    gUnk_020350D0 = -32768;
    LoadBgPalette(0, gUnk_09A3C9DC, 96);
    LoadBgTiles(0, gUnk_099F1E7C, 11968);
    func_080FDB1C(gUnk_020350BA, gUnk_020350B8);
    LoadBgMap(0, gUnk_09A310DC, 0x500);
    LoadBgMap(1, gUnk_09A31ADC, 0x500);

    if (gUnk_020350EE == 0) {
        func_080065FC(2, 0x8000, 128);
        func_08006778(gUnk_09EDABA0, 120, 110);
        func_08006B34(0);
        gUnk_020350EF = 1;
    }

    gUnk_020350A0[0] = LoadObjPalette(gUnk_09A3CC3C, 32);
    gUnk_02035098[0] = LoadObjTiles(gUnk_0999A394, 0xC40);
    gUnk_020350A0[1] = LoadObjPalette(gUnk_09A3CC5C, 32);
    gUnk_02035098[1] = LoadObjTiles(gUnk_0999B052, 0x1340);
    gUnk_020350AC = LoadObjPalette(gUnk_09A3CC7C, 32);
    gUnk_020350A8 = LoadObjTiles(gUnk_0999CBB6, 0x380);
    gUnk_020350B0 = LoadObjTiles(gUnk_0999C410, 0x780);
    TaskPoolInit(&gUnk_020350D8, 1);
    EnableBg(0);
    EnableBg(1);

    if (gUnk_020350EE != 0) {
        DisableBg(2);
    } else {
        EnableBg(2);
    }
}
#else
INCLUDE_ASM("bos5/mode_worldselect_0.s");
#endif

#ifndef VERSION_EU
void mode_worldselect_1(void) {
    s16 a;
    s16 b;

    UpdatePlayTime();
    gUnk_020350B4 += 2;

    switch (gUnk_020350C0) {
    case 0:
        ApproachValue(&gUnk_020350C8[0], 0, gUnk_020350C2);
        ApproachValue(&gUnk_020350C8[1], 0x9800, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020350D0, 0, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            if (gUnk_020350EE != 0) {
                gUnk_020350EC = 0;
                func_080A411C(&gUnk_020350D8, 2, 70);
                gUnk_020350C0 = 2;
            } else {
                gUnk_020350C0 = 3;
            }

            LoadBgMap(0, gUnk_09A315DC, 0x500);
            LoadBgMap(1, gUnk_09A31FDC, 0x500);
        }
        break;
    case 2:
        if (func_080A42C8() == 0) {
            if (gUnk_020350EC == 0) {
                func_080A411C(&gUnk_020350D8, 2, 71);
                gUnk_020350EC++;
            } else {
                gGameState.unk_17A |= 1;
                func_080FE89C();
                func_080065FC(2, 0x8000, 128);
                func_08006778(gUnk_09EDABA0, 120, 110);
                func_08006B34(0);
                gUnk_020350EF = 1;
                gUnk_020350C0 = 3;
            }
        }
        break;
    case 3:
        func_080FDC04();
        break;
    case 4:
        if (func_08006B74() != 0) {
            LoadBgMap(0, gUnk_09A310DC, 0x500);
            LoadBgMap(1, gUnk_09A31ADC, 0x500);
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 5;
        }
        break;
    case 5:
        ApproachValue(&gUnk_020350D0, -32768, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 6;
        }
        break;
    case 6:
        ApproachValue(&gUnk_020350C8[0], -2048, gUnk_020350C2);
        ApproachValue(&gUnk_020350C8[1], 0xA800, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            gUnk_020350C0 = 7;
        }
        break;
    case 7:
        func_080063A8();

        if (gUnk_020350F0 != 0) {
            func_08006184(0, 16);
        } else {
            func_08006184(2, 16);
        }

        gUnk_020350C0 = 8;
        break;
    case 8:
        if (func_08006314() == 0) {
            if (gUnk_020350F0 != 0) {
                func_080E04EC();
            } else {
                gUnk_020350C2 = 60;
                gUnk_020350C0 = 9;
            }
        }
        break;
    case 9:
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            a = gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_02;

            if ((gGameState.flags & 8) == 0) {
                b = gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_04;
            } else {
                b = gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_06;
            }

            gGameState.unk_180 &=
                ~gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_00;
            func_080DFA18(a);

            if (b >= 0) {
                func_0806180C(b);
            } else {
                if (gGameState.flags & 8) {
                    func_080938F8(221);
                }

                func_080DFA3C();
                func_080E04EC();
            }
        }
        break;
    }

    func_080FE900();

    if (func_08006314() != 0) {
        func_08006390();
    }

    TaskPoolUpdate(&gUnk_020350D8);
    func_080FE47C();
}
#else
INCLUDE_ASM("bos5/mode_worldselect_1.s");
#endif
void mode_worldselect_2(void) {
    s16 i;

    EwramFree(gUnk_020350BC);

    for (i = 0; i < gUnk_02035090; i++) {
        ReleaseObjPalette(gUnk_02034FF8[i].unk_0C);
        ReleaseObjTiles(gUnk_02034FF8[i].unk_10);
    }

    for (i = 0; i < 2; i++) {
        ReleaseObjPalette(gUnk_020350A0[i]);
        ReleaseObjTiles(gUnk_02035098[i]);
    }

    ReleaseObjPalette(gUnk_020350AC);
    ReleaseObjTiles(gUnk_020350A8);
    ReleaseObjTiles(gUnk_020350B0);
    TaskPoolDestroy(&gUnk_020350D8);
}
void func_080FF10C(u8 pal, u16 w, s16 h, u16* map, s16 x, s16 y) {
    s16 i;
    s16 j;
    s16 n;
    u16 v;

    n = w;
    v = pal << 12;
    map += x + y * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *map = (*map & 0xFFF) | v;
            map++;
        }
        map += 32 - n;
    }
}
void func_080FF19C(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
    s16 i;
    s16 j;
    s16 n;

    n = w;
    src += sx + sy * 32;
    dst += dx + dy * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *dst++ = *src++;
        }
        src += 32 - n;
        dst += 32 - n;
    }
}
#ifndef VERSION_EU
u8 func_080FF228(s16 id) {
    if (id == 0) {
        return 0;
    }

    return func_08065B6C(gUnk_09EF909C[id].unk_2C, gUnk_020351F8);
}
#else
INCLUDE_ASM("bos5/func_080FF228.s");
#endif
#ifndef VERSION_EU
u8 func_080FF25C(s16 id) {
    void** tbl;
    void** p;
    u16 i;

    if (id != 0) {
        tbl = gUnk_09EE9138;

        if (gGameState.flags & 8) {
            i = gUnk_09EF909C[id].unk_32;
        } else {
            i = gUnk_09EF909C[id].unk_30;
        }

        p = &tbl[i];
        return func_08065B6C(*p, gUnk_020352C0);
    }

    return 0;
}
#else
INCLUDE_ASM("bos5/func_080FF25C.s");
#endif

#ifndef VERSION_EU
void func_080FF2B8(s16 index) {
    u8* src;

    if ((gGameState.flags & 8) == 0) {
        src = gUnk_09A020FC;
    } else {
        src = gUnk_09A02EFC;
    }

    if (index < gUnk_020350FA) {
        src += index * 256;
    } else {
        src += 0xD00;
    }

    RequestDma3Copy(src, (u8*)GetBgCharBase(0) + 32, 0x100);
}
#else
INCLUDE_ASM("bos5/func_080FF2B8.s");
#endif
s32 func_080FF310(void) {
    s32 keys;

    keys = GetKeysPressed() & 0xF;
    keys |= GetKeysRepeat() & 0x3F0;
    return keys;
}
#ifndef VERSION_EU
void func_080FF330(void) {
    u16 keys;
    s16 old;
    s16 i;

    old = gUnk_020350F8;
    keys = func_080FF310();

    if (keys & 1) {
        if (gUnk_02035100[gUnk_020350F8] != 0) {
            gUnk_020354A8[0] = LoadObjPalette(gUnk_09A3CC3C, 32);
            gUnk_020354B0[0] = LoadObjTiles(gUnk_0999A394, 0xC40);
            gUnk_020354B8[0] = gUnk_0999A350;

            if (gUnk_020350F8 <= 9) {
                for (i = 10; i < 12; i++) {
                    if (gUnk_02035168[i] != 0) {
                        ReleaseObjPalette(gUnk_02035168[i]);
                        gUnk_02035168[i] = 0;
                    }
                }
            } else {
                for (i = 4; i < 6; i++) {
                    if (gUnk_02035168[i] != 0) {
                        ReleaseObjPalette(gUnk_02035168[i]);
                        gUnk_02035168[i] = 0;
                    }
                }
            }

            if (gUnk_02035100[gUnk_020350F8] == 13 && func_080D2DD8()) {
                gUnk_020354A8[1] = LoadObjPalette(gUnk_09A3CDDC, 64);
                gUnk_020354B0[1] = LoadObjTiles(gUnk_099EDE7C, 0x1000);
                gUnk_020354B8[1] = gUnk_099A8914;
            } else {
                gUnk_020354A8[1] =
                    LoadObjPalette(gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].unk_18,
                                   gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].unk_1C);
                gUnk_020354B0[1] =
                    LoadObjTiles(gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].unk_20,
                                 gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].unk_24);
                gUnk_020354B8[1] = gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].unk_28;
            }

            gUnk_020354A0 = func_080FF25C(gUnk_02035100[gUnk_020350F8]);
            gBldCnt = 0x744;
            gBldAlpha = 0x808;
            EnableBg(2);
            EnableBg(3);
            m4aSongNumStart(102);
            gUnk_02035118 = 1;
        }
    } else if (keys & 2) {
        m4aSongNumStart(104);
        LoadBgMap(0, gUnk_09A324DC, 0x500);
        gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
        gUnk_020354E0 = 1;
        gUnk_020354C2 = 16;
        gUnk_020354C0 = 3;
    } else if (keys & 8) {
        m4aSongNumStart(104);
        LoadBgMap(0, gUnk_09A324DC, 0x500);
        gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
        gUnk_020354E0 = 0;
        func_08006184(0, 16);
        gUnk_020354C0 = 5;
    } else if (keys & 0x40) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].unk_00;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    } else if (keys & 0x80) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].unk_02;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    } else if (keys & 0x20) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].unk_04;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    } else if (keys & 0x10) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].unk_06;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    }

    if (gUnk_020350F8 != old) {
        func_080FF2B8(gUnk_020350F8);
        gUnk_020352B8 = func_080FF228(gUnk_02035100[gUnk_020350F8]);
        m4aSongNumStart(101);
    }
}
#else
INCLUDE_ASM("bos5/func_080FF330.s");
#endif
void func_080FF794(void) {
    u16 keys;
    s32 i;

    keys = func_080FF310();

    if (keys & 10) {
        m4aSongNumStart(104);

        for (i = 0; i < 2; i++) {
            ReleaseObjPalette(gUnk_020354A8[i]);
            ReleaseObjTiles(gUnk_020354B0[i]);
        }

        if (gUnk_020350F8 <= 9) {
            for (i = 10; i < 12; i++) {
                if (gUnk_02035100[i] != 0) {
                    gUnk_02035168[i] = LoadObjPalette(gUnk_09EF909C[gUnk_02035100[i]].unk_04,
                                                      gUnk_09EF909C[gUnk_02035100[i]].unk_08);
                }
            }
        } else {
            for (i = 4; i < 6; i++) {
                if (gUnk_02035100[i] != 0) {
                    gUnk_02035168[i] = LoadObjPalette(gUnk_09EF909C[gUnk_02035100[i]].unk_04,
                                                      gUnk_09EF909C[gUnk_02035100[i]].unk_08);
                }
            }
        }

        gBldCnt = 0;
        DisableBg(2);
        DisableBg(3);
        gUnk_020354E0 = 1;
        gUnk_02035118 = 0;

#ifdef VERSION_EU
        gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
#endif

        if (keys & 8) {
            LoadBgMap(0, gUnk_09A324DC, 0x500);
#ifndef VERSION_EU
            gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
#endif
            gUnk_020354E0 = 0;
            func_08006184(0, 16);
            gUnk_020354C0 = 5;
        }
    }
}
#ifndef VERSION_EU
void func_080FF8CC(void) {
    s32 i;
    u16 prio;

    if (gUnk_020354C0 != 2) {
        DrawSprite(gUnk_020354D0 >> 8, 0, gUnk_0999CF38, gUnk_02035120, gUnk_0203511C, 0,
                      0xC00, 3000);
        DrawSprite(112, gUnk_020354C8[0] >> 8, gUnk_0999CF54, gUnk_02035120, gUnk_0203511C, 0,
                      0xC00, 3001);
        DrawSprite(112, gUnk_020354C8[1] >> 8, gUnk_0999CF88, gUnk_02035120, gUnk_0203511C, 0,
                      0xC00, 3001);
    }

    prio = 0x400;

    if (gUnk_02035118 == 1) {
        prio |= 4;
    }

    if (gUnk_020354C0 == 2) {
        DrawSprite((s16)(gUnk_09EF8FAC[gUnk_020350F8].unk_08 * 8 + 22),
                      (s16)(gUnk_09EF8FAC[gUnk_020350F8].unk_0A * 8 + 12),
                      AnimUpdate(&gUnk_02035130), gUnk_02035128, gUnk_02035124, 0, prio, 2013);
        func_0805F1C0(&gUnk_020354D8,
                      (gUnk_09EF8FAC[gUnk_020350F8].unk_08 << 11) + 0x2000);
        func_0805F1C0(&gUnk_020354DC,
                      (gUnk_09EF8FAC[gUnk_020350F8].unk_0A << 11) + 0xFFFFFA00);
        DrawSprite(gUnk_020354D8 >> 8, gUnk_020354DC >> 8, AnimUpdate(&gUnk_02035150),
                      gUnk_0203514C, gUnk_02035148, 0, prio, 2000);
    }

    for (i = 0; i < 12; i++) {
        if (gUnk_020351C8[i] != 0 && gUnk_02035168[i] != 0) {
            DrawSprite((s16)(gUnk_09EF8FAC[i].unk_08 * 8 + 16), (s16)(gUnk_09EF8FAC[i].unk_0A * 8 + 16),
                          gUnk_020351C8[i], gUnk_02035198[i], gUnk_02035168[i], 0, prio,
                          (u16)(i + 2001));
        }
    }

    if (gUnk_020351C8[gUnk_020350F8] != 0) {
        DrawSprite(112, 32, gUnk_020351C8[gUnk_020350F8], gUnk_02035198[gUnk_020350F8],
                      gUnk_02035168[gUnk_020350F8], 0, 0, 0);
    }

    if (gUnk_020352B8 != 0) {
        func_080664D8(128, 28, gUnk_020351F8, gUnk_02035148, 1, gUnk_020352B8);
    }

    if (gUnk_02035118 == 1) {
        if (gUnk_020354A0 != 0) {
            func_080664D8(97, 56, gUnk_020352C0, gUnk_02035124, 0, gUnk_020354A0);
        }

        DrawSprite(47, (-gSineTable[gUnk_0203511A + 0x40] >> 5) + 84, gUnk_020354B8[0],
                      gUnk_020354B0[0], gUnk_020354A8[0], 0, 0, 1);
        DrawSprite(47, (-gSineTable[gUnk_0203511A + 0x40] >> 5) + 84, gUnk_020354B8[1],
                      gUnk_020354B0[1], gUnk_020354A8[1], 0, 0, 0);
    }
}
#else
INCLUDE_ASM("bos5/func_080FF8CC.s");
#endif
