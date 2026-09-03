#include "macros.h"
#include "bos6.h"

INCLUDE_ASM("bos6/task_bos_pc_0.s");
INCLUDE_ASM("bos6/func_0810A850.s");

u8 func_0810A914(PcWork* work) {
    s32 u;
    s16 t;

    func_08109EF8(work, 0);
    work->unk_004 -= 1;
    if (work->unk_004 < 0) {
        if ((gUnk_02039B84->unk_068 & 0x20000000) == 0) {
            func_0801BCD4(&work->unk_054);
            u = work->unk_2E8;
            work->unk_004 = ((u >> 6) + 6) * 60;
        } else {
            work->unk_004 = 4;
        }
    } else if (work->unk_004 % (work->unk_2E8 >> 4) == 0) {
        if (gUnk_02039B84->unk_068 & 0x20000000) {
            t = (((s32)work->unk_2E8 * 5) >> 3) + 96;
            if (GetRandom() >> 7 > t) {
                func_0801BCD4(&work->unk_054);
            }
        }
    }
    return 1;
}

INCLUDE_ASM("bos6/func_0810A9CC.s");

u8 func_0810ACB8(PcWork* work) {
    void* p;

    p = &work->unk_054;
    if (work->unk_002 == 0) {
        work->unk_010 = *(s32*)((u8*)p + 40);
        work->unk_014 = *(s32*)((u8*)p + 36);
    }
    work->unk_002 += 1;
    if (work->unk_002 > 15) {
        func_0801AF08(p);
        if (work->unk_014 & 0x10000000) {
            switch (work->unk_010) {
            case 67:
                work->unk_008 = 2;
                work->unk_000 = 5;
                work->unk_002 = 0;
                return 1;
            case 68:
                work->unk_008 = 3;
                work->unk_000 = 5;
                work->unk_002 = 0;
                return 1;
            default:
                work->unk_008 = 1;
                work->unk_000 = 5;
                work->unk_002 = 0;
                return 1;
            }
        } else {
            switch (work->unk_010) {
            case 2:
            case 14:
            case 17:
            case 20:
            case 23:
            case 26:
            case 29:
            case 32:
            case 35:
            case 38:
            case 41:
            case 44:
            case 47:
            case 50:
            case 53:
            case 56:
            case 59:
            case 62:
            case 65:
                if (work->unk_2F4 <= 0) {
                    if ((GetRandom() & 0x300) == 0x300) {
                        work->unk_008 = 1;
                        work->unk_000 = 5;
                        work->unk_002 = 0;
                        break;
                    }
                }
            default:
                work->unk_004 = work->unk_004 / 4;
                work->unk_000 = 0;
                work->unk_002 = 0;
                break;
            }
        }
    }
    return 1;
}

u8 func_0810AE74(PcWork* work) {
    void* p;

    p = &work->unk_054;
    func_08109EF8(work, work->unk_008);
    if (func_0810A424(work) != 0) {
        work->unk_004 = 180;
        if (work->unk_006 > 0) {
            func_0801AF08(p);
            work->unk_006 = 0;
        }
        work->unk_000 = 0;
        work->unk_002 = 0;
    } else {
        if (work->unk_006 == 1) {
            func_0801AF08(p);
        }
        if (work->unk_006 > 0) {
            work->unk_006 -= 1;
        }
    }
    return 1;
}

u8 func_0810AED4(PcWork* work) {
    void* p;

    p = &work->unk_054;
    work->unk_2F0 = 240;
    if (gUnk_02039BB0.unk_008 & 8) {
        if (work->unk_2F4 <= 0) {
            if (GetRandom() % 0xA01 > 0x800) {
                _0801C1F8(0, work->unk_020, work->unk_024, work->unk_028);
            }
        }
    }
    work->unk_002 += 1;
    func_0801AF08(p);
    work->unk_000 = 0;
    work->unk_002 = 0;
    return 1;
}

u8 func_0810AF44(PcWork* work) {
    s32 args[8];
    void* p;
    s16 s;
    s32 n;
    s32 i;

    p = &work->unk_054;
    s = work->unk_002;
    switch (s) {
    case 0:
        func_0801AF4C(p);
        ReleaseObjPalette((void*)work->unk_050);
        work->unk_050 = 0;
        func_0801C2DC(p, 1);
        func_0801C2DC(&work->unk_164, 1);
        gUnk_02039B84->unk_068 |= 0x100000;
        work->unk_2EB = 255;
        work->unk_2F4 = 0x34BC0;
        func_08109EF8(work, 11);
        m4aSongNumStart(332);
        m4aSongNumStart(0x2CD);
        work->unk_002 += 1;
        break;
    case 1:
        n = 0;
        for (i = 0; i <= 3; i++) {
            if (work->unk_2D4[i] == 0) {
                n++;
            } else if (func_0810B800(work->unk_2D4[i]) == 1) {
                func_08000DE8(gUnk_02039B84->unk_02C, work->unk_2D4[i]);
                work->unk_2D4[i] = 0;
            }
        }
        if (n == 4) {
            args[0] = 0x11400;
            args[1] = 0x15300;
            args[2] = -0x5C00;
            func_08096DC4(gUnk_02039B84->unk_02C, args);
            func_0801B918(p);
            func_0810B378(work->unk_2D0, 1);
            work->unk_002 += 1;
        }
        break;
    case 2:
        work->unk_018 = 1;
        work->unk_002 += 1;
        break;
    default:
        func_0801B008();
        break;
    }
    return 1;
}

INCLUDE_ASM("bos6/task_bos_pc_1.s");

void task_bos_pc_2(PcWork* work) {
    func_0810A018(work);
    func_0810A498(work);
}

void task_bos_pc_3(PcWork* work) {
    func_0801B7D8(&work->unk_054);
    func_0801B7D8(&work->unk_164);
    func_08012304(&work->unk_274);
    ReleaseObjTiles((void*)work->unk_040);
    ReleaseObjTiles((void*)work->unk_044);
    ReleaseObjTiles((void*)work->unk_048);
    ReleaseObjPalette((void*)work->unk_04C);
    if (work->unk_050 != 0) {
        ReleaseObjPalette((void*)work->unk_050);
    }
    func_0810A4C4(work);
}

s32 func_0810B348(s32 x) {
    return x * x;
}

s32 func_0810B350(void** p) {
    void* work;

    work = p[1];
    func_08109EF8(work, 13);
    return func_08109F20(work);
}

s32 func_0810B368(s32 x) {
    return x * x;
}

void func_0810B370(u8** p, u8 v) {
    p[1][0] = v;
}

void func_0810B378(void** p, u8 a) {
    PcFldWork* work;
    UnkStruct_080038C8* pal;

    work = (PcFldWork*)p[1];
    if (a == 1) {
        a = 0;
    } else {
        a = 1;
    }
    func_08012614(&work->unk_010, a);
    if (a == 0) {
        if (work->unk_008 == 0) {
            work->unk_008 = (u32)LoadObjTiles(gUnk_09CC4E54, 0x200);
        }
        if (work->unk_00C == 0) {
            pal = (UnkStruct_080038C8*)LoadObjPalette(gUnk_09D693D4, 0x60);
            work->unk_00C = (u32)pal;
            LoadPalette(gUnk_09D69434, gUnk_05000220 + pal->unk_06 * 32, 32);
        }
    }
}

void func_0810B3E4(void) {
    gUnk_02036008 = 0;
    gUnk_0203600A = 0;
    gUnk_0203600C = 0;
    gUnk_02036010 = 0;
}

void func_0810B40C(s16 a) {
    gUnk_02036008 = 1;
    gUnk_0203600A = a;
    gUnk_0203600C = 0;
    gUnk_02036010 = 0;
}

void func_0810B434(void) {
    s8* p;

    if (gUnk_02036008 != 0) {
        p = gUnk_09EF9E04[gUnk_0203600A];
        gUnk_02036010 += ((p[gUnk_0203600C] << 12) - gUnk_02036010) >> 3;
        gUnk_0203600C += 1;
        if (p[gUnk_0203600C] == 0) {
            gUnk_02036008 = 0;
            gUnk_02036010 = 0;
        }
    }
}

s32 func_0810B49C(void) {
    return gUnk_02036010;
}

void func_0810B4A8(u8* p) {
    u16 zero;

    zero = 0;
    *(u8*)(p + 0) = zero;
    *(u16*)(p + 2) = zero;
    *(u16*)(p + 4) = zero;
}

void func_0810B4B4(u8* p) {
    u16 t;
    u16 zero;

    if (p[0] != 0) {
        if (*(s16*)(p + 4) > gUnk_09A4CAC4[*(s16*)(p + 2)]) {
            t = gUnk_09A4CABE[*(s16*)(p + 2)];
            zero = 0;
            *(u16*)(p + 2) = t;
            *(u16*)(p + 4) = zero;
        }
        *(u16*)(p + 4) += 1;
    }
}

void func_0810B4F4(u8* p) {
    if (p[0] != 0) {
        LoadPalette(gUnk_09D69374 + *(s16*)(p + 2) * 32, gUnk_05000080, 32);
    }
}

void func_0810B51C(u8* p) {
    *p = 0;
}

void task_bos_pc_fld_0(PcFldWork* work, FldInit* arg) {
    void* p;

    LoadBgTiles(0, arg->unk_00, arg->unk_04);
    LoadBgPalette(0, arg->unk_08, arg->unk_0C);
    func_0800516C(0, &arg->unk_10, 2, 3);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0x11400;
    gUnk_02039B84->unk_00C = 0x15300;
    gUnk_02039B84->unk_000 = 0x11400;
    gUnk_02039B84->unk_004 = 0x15300;
    gUnk_02039B84->unk_010 = 0x11400;
    gUnk_02039B84->unk_014 = 0x15300;
    gUnk_02039B84->unk_01C = 0x11400;
    gUnk_02039B84->unk_020 = 0x15300;
    gUnk_02039B84->unk_01A = 15;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_0810B3E4();
    func_08005244(0, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
    func_0810B4A8((u8*)work);
    func_0810B4B4((u8*)work);
    work->unk_008 = 0;
    work->unk_00C = 0;
    p = &work->unk_010;
    func_080122AC(p, 6, 40, 8);
    func_08012324(p, 0x17400, 0x15400, 0);
    func_08012614(p, 1);
}

u8 task_bos_pc_fld_1(PcFldWork* work) {
    s32 t;
    s32 u;
    s32 dx;
    s32 dy;
    PcPos* pos;

    func_0802F208();
    func_0810B434();
    pos = (PcPos*)gUnk_02039B84->unk_07C;
    u = gUnk_02039B84->unk_000 - 0x7800;
    t = pos->unk_04 - u;
    if (t < 0) {
        t = 0;
    }
    gUnk_02039B84->unk_010 = t / 2 + 0xF000;
    dx = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
    dy = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;
    if (dx > 0x500) {
        dx += 0x500;
    } else if (dx < -0x500) {
        dx -= 0x500;
    }
    gUnk_02039B84->unk_008 += dx;
    gUnk_02039B84->unk_00C += dy;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;
    if (gUnk_02039B84->unk_000 - 0x7800 < gUnk_02039B84->unk_0DA * 256) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 120) * 256;
    } else if (gUnk_02039B84->unk_000 + 0x7800 > gUnk_02039B84->unk_0DC * 256) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 120) * 256;
    }
    if (gUnk_02039B84->unk_004 + 0x3000 < gUnk_02039B84->unk_0DE * 256) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0DE - 48) * 256;
    } else if (gUnk_02039B84->unk_004 + 0x5000 > gUnk_02039B84->unk_0E0 * 256) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0E0 - 80) * 256;
    }
    gUnk_02039B84->unk_004 += func_0802F268();
    gUnk_02039B84->unk_004 += func_0810B49C();
    func_08005244(0, (gUnk_02039B84->unk_000 >> 8) + 8, (gUnk_02039B84->unk_004 >> 8) + 40);
    func_0810B4B4((u8*)work);
    return 1;
}

void task_bos_pc_fld_2(PcFldWork* work) {
    s16 sx;
    s16 sy;
    PcPos* pos;
    u32 x;
    u32 y;
    s32 z;

    func_0810B4F4((u8*)work);
    pos = (PcPos*)gUnk_02039B84->unk_07C;
    if (pos->unk_0C >= -0x100) {
        if ((pos->unk_34 & 0x80) == 0) {
            if (work->unk_008 != 0) {
                if (work->unk_00C != 0) {
                    x = 0x17000;
                    y = 0x14800;
                    z = -0x800;
                    WorldToScreen(&sx, &sy, x, y, z);
                    DrawSprite(sx, sy, gUnk_09EFBEB8, (void*)work->unk_008,
                        (void*)work->unk_00C, 0, func_0801AF1C(y),
                        (u16)(-0x1004 - (s32)(y >> 6)));
                }
            }
        }
    }
}

void task_bos_pc_fld_3(PcFldWork* work) {
    func_0810B51C((u8*)work);
    func_08012304(&work->unk_010);

    if (work->unk_008 != 0) {
        ReleaseObjTiles((void*)work->unk_008);
    }

    if (work->unk_00C != 0) {
        ReleaseObjPalette((void*)work->unk_00C);
    }
}

s32 func_0810B7D8(s32 x) {
    return x * x;
}

s32 func_0810B7E0(s32 x) {
    return x * x;
}

void func_0810B7E8(void** p, s32* a, s32* b, s32* c) {
    PcFltWork* work;

    work = (PcFltWork*)p[1];
    *a = work->unk_028;
    *b = work->unk_02C;
    *c = work->unk_030;
}

u8 func_0810B800(void** p) {
    PcFltWork* work;

    work = (PcFltWork*)p[1];
    if (work->unk_005 == 8 && func_08005B38(&work->unk_09C) == 0) {
        return 1;
    }
    return 0;
}

u8 func_0810B824(void** p) {
    PcFltWork* work;
    u8 r;

    work = (PcFltWork*)p[1];
    r = 0;
    if (func_0801BCA8(&work->unk_040) == 1) {
        r = 1;
    }
    return r;
}

void func_0810B844(PcFltWork* work) {
    AnimState* anim;

    work->unk_030 = work->unk_024;
    if (work->unk_03C->unk_02 == 0) {
        if (func_0801BCA8(&work->unk_040) == 1) {
            work->unk_030 += 0x200;
            if (work->unk_000 != 1) {
                work->unk_000 = 1;
                AnimChange(&work->unk_09C, 8, 0);
            }
            work->unk_018 -= 2;
            if (work->unk_018 < 0) {
                work->unk_005 = 1;
                work->unk_000 = 0;
                work->unk_002 = 0;
                work->unk_018 = 360;
                AnimChange(&work->unk_09C, 7, 0);
            }
        } else {
            if (work->unk_000 == 1) {
                work->unk_018 -= 120;
                AnimChange(&work->unk_09C, 1, 0);
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
        work->unk_002 = 0;
        AnimChange(&work->unk_09C, 5, 0);
    }
}

void func_0810B8F8(PcFltWork* work) {
    AnimState* anim;

    work->unk_030 = work->unk_024;
    anim = &work->unk_09C;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 2;
        work->unk_002 = 0;
        func_08005B64(anim);
        AnimChange(anim, 3, 0);
    }
}

void func_0810B930(PcFltWork* work) {
    work->unk_030 = work->unk_024;
    if (AnimIsFinished(&work->unk_09C) == 1) {
        work->unk_005 = 3;
        work->unk_000 = 0;
        work->unk_002 = 60;
    }
}

void func_0810B95C(PcFltWork* work) {
    work->unk_030 = work->unk_024 + 0x1000;
    work->unk_002 -= 1;
    if (work->unk_002 < 0) {
        if (work->unk_03C->unk_02 == 0) {
            work->unk_005 = 4;
            work->unk_002 = 0;
            AnimChange(&work->unk_09C, 4, 0);
        } else {
            work->unk_005 = 6;
            work->unk_002 = 0;
            AnimChange(&work->unk_09C, 9, 0);
        }
    }
}

void func_0810B9A8(PcFltWork* work) {
    AnimState* anim;

    work->unk_030 = work->unk_024;
    anim = &work->unk_09C;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 0;
        func_08005B64(anim);
        AnimChange(anim, 1, 0);
    }
}

void func_0810B9DC(PcFltWork* work) {
    AnimState* anim;

    work->unk_030 = work->unk_024;
    anim = &work->unk_09C;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 6;
        work->unk_002 = 0;
        func_08005B64(anim);
        AnimChange(anim, 2, 0);
    }
}

void func_0810BA14(PcFltWork* work) {
    work->unk_030 = work->unk_024;
    if (work->unk_03C->unk_02 == 0) {
        work->unk_005 = 7;
        work->unk_002 = 0;
        AnimChange(&work->unk_09C, 6, 0);
    }
}

void func_0810BA3C(PcFltWork* work) {
    AnimState* anim;

    work->unk_030 = work->unk_024;
    anim = &work->unk_09C;
    if (AnimIsFinished(anim) == 1) {
        work->unk_005 = 0;
        work->unk_002 = 0;
        func_08005B64(anim);
        AnimChange(anim, 1, 0);
    }
}

void func_0810BA74(PcFltWork* work) {
    AnimState* anim;
    u8 fin;
    u16 id;

    work->unk_030 = work->unk_024;
    if (work->unk_002 == 0) {
        anim = &work->unk_09C;
        fin = AnimIsFinished(anim);
        if (fin == 1) {
            id = func_08005B38(anim);
            if (id != 0) {
                func_08005B64(anim);
                AnimChange(anim, gUnk_09A4CEDC[id].unk_06, 0);
            } else {
                work->unk_002 = 1;
            }
        }
    } else if (work->unk_03C->unk_0C <= 119) {
        work->unk_005 = 3;
        work->unk_000 = 0;
        work->unk_002 = work->unk_004 * 30;
    }
}

void func_0810BAE4(PcFltWork* work) {
    s32 f;

    if ((gUnk_02039B84->unk_068 & 0x20000000) || (gUnk_02039B84->unk_068 & 0x40) ||
        work->unk_03C->unk_08 > 0) {
        f = -1;
    } else {
        f = work->unk_007;
    }
    if (work->unk_005 != 8 && work->unk_03C->unk_0C > 0x257) {
        work->unk_005 = 8;
        work->unk_000 = 0;
        work->unk_002 = 0;
        work->unk_018 = 360;
    }
    if (work->unk_03C->unk_02 == 0) {
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
        work->unk_028 = (((gUnk_09A4CCDC[work->unk_008 >> 8] * (work->unk_014 >> 8)) >> 8) + (work->unk_00C >> 8)) << 8;
        work->unk_02C = (((gUnk_09A4CADC[work->unk_008 >> 8] * (work->unk_016 >> 8)) >> 8) + (work->unk_010 >> 8)) << 8;
        work->unk_008 = work->unk_008 - (((work->unk_03C->unk_00 * 3) << 4) / 256 - 112);
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
    if (func_0801BCA8(&work->unk_040) == 1) {
        work->unk_000 = 1;
    }
}

void func_0810BCD4(PcFltWork* work) {
    void* p;

    p = &work->unk_040;
    func_08012324(p, work->unk_028, work->unk_02C + 0x200, 0);
    func_08012658(p, -work->unk_030 >> 8);
    if (work->unk_030 > 0) {
        func_08012614(p, 1);
    } else {
        func_08012614(p, 0);
    }
}

void task_bos_pc_flt_0(PcFltWork* work, PcFltInit* arg) {
    AnimState* anim;

    work->unk_034 = (u32)LoadObjTiles(gUnk_09CB8F54, 0xDC0);
    work->unk_038 = (u32)LoadObjPalette(gUnk_09D693D4, 0x60);
    anim = &work->unk_09C;
    AnimInit(anim, gUnk_09EFBBEC, gUnk_09EFBBBC);
    AnimStart(anim, 1, 0);
    func_080122AC(&work->unk_040, 7, 26, 4);
    work->unk_000 = 0;
    work->unk_002 = 0;
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
    work->unk_03C = arg->unk_10;
    func_0810BAE4(work);
    func_0810BCD4(work);
}

u8 task_bos_pc_flt_1(PcFltWork* work) {
    AnimState* anim;
    u16 id;

    func_0810BAE4(work);
    anim = &work->unk_09C;
    AnimUpdate(anim);
    id = func_08005B38(anim);
    if (id == 0) {
        work->unk_030 += 0x1000;
    } else {
        work->unk_030 += gUnk_09A4CEDC[id].unk_02 << 8;
        func_08012650(&work->unk_040, gUnk_09A4CEDC[id].unk_04);
    }
    func_0810BCD4(work);
    work->unk_007 = work->unk_03C->unk_00 & 1;
    return 1;
}

void task_bos_pc_flt_2(PcFltWork* work) {
    s16 sx;
    s16 sy;
    u16 id;
    u16 g;
    u16 h;

    if (work->unk_030 <= 0) {
        id = func_08005B38(&work->unk_09C);
        WorldToScreen(&sx, &sy, work->unk_028,
            work->unk_02C + (gUnk_09A4CEDC[id].unk_00 << 8), work->unk_030);
        if (gUnk_02039B84->unk_0F0 != 0) {
            g = func_0801AF1C(work->unk_02C + (gUnk_09A4CEDC[id].unk_00 << 8));
            h = (-0x1004 - ((work->unk_02C >> 8) << 2)) | 3;
        } else {
            g = func_0801AF1C(work->unk_02C);
            h = -0x1004 - ((work->unk_02C >> 8) << 2);
        }
        DrawSprite(sx, sy, AnimGetGfx(&work->unk_09C), (void*)work->unk_034,
                   (void*)work->unk_038, 0, g, h);
    }
}

void task_bos_pc_flt_3(PcFltWork* work) {
    func_08012304(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_034);
    ReleaseObjPalette((void*)work->unk_038);
}

s32 func_0810BF14(s32 x) {
    return x * x;
}

s32 func_0810BF1C(s32 x) {
    return x * x;
}

void func_0810BF24(u8** p, u8 v) {
    p[1][24] = v;
}

void task_bos_pc_acd_0(PcAcdWork* work, void* arg) {
    AnimState* anim;

    work->unk_000 = 0;
    work->unk_004 = (u32)AllocObjTiles(0x300, gUnk_09C489E4);
    work->unk_008 = (u32)LoadObjPalette(gUnk_09D693D4, 0x60);
    work->unk_00C = -1;
    work->unk_010 = -1;
    work->unk_014 = -1;
    work->unk_01C = arg;
    anim = &work->unk_020;
    AnimInit(anim, gUnk_09EFABA4, gUnk_09EFAB68);
    if (work->unk_01C->unk_005 == 1) {
        work->unk_018 = 1;
        AnimStart(anim, 1, 0);
    } else {
        work->unk_018 = 0;
        AnimStart(anim, 0, 0);
    }
}

u8 task_bos_pc_acd_1(PcAcdWork* work) {
    AnimState* anim;
    s32 v;

    func_080062F4(((UnkStruct_080038C8*)work->unk_008)->unk_06 + 17, 0);
    func_080062F4(((UnkStruct_080038C8*)work->unk_008)->unk_06 + 18, 0);
    anim = &work->unk_020;
    AnimUpdate(anim);
    if (((PcPos*)gUnk_02039B84->unk_07C)->unk_0C >= 0) {
        if ((gUnk_02039B84->unk_068 & 0x20000000) == 0 ||
            (gUnk_02039B84->unk_068 & 0x200000) == 0) {
            if (work->unk_00C < 0 || AnimIsFinished(anim) == 1) {
                v = 0;
                if (work->unk_018 == 1) {
                    v = 1;
                }
                func_08005B64(anim);
                AnimStart(anim, v, 0);
            }
        }
    }
    return 1;
}

INCLUDE_ASM("bos6/task_bos_pc_acd_2.s");

void task_bos_pc_acd_3(PcAcdWork* work) {
    ReleaseObjTiles((void*)work->unk_004);
    ReleaseObjPalette((void*)work->unk_008);
}

s32 func_0810C2B4(s32 x) {
    return x * x;
}

s32 func_0810C2BC(s32 x) {
    return x * x;
}

void func_0810C2C4(u8** p) {
    p[1][1] = 1;
}

void func_0810C2CC(BosLstWork* work, u16 a, u16 b) {
    u16 zero;

    zero = 0;
    work->unk_00C = a;
    work->unk_00E = b;
    work->unk_070 = zero;
    work->unk_072 = zero;
}

void func_0810C2E0(BosLstWork* work) {
    func_0801BCD4(&work->unk_0E4);
    work->unk_070 += 1;
}

void func_0810C2F8(BosLstWork* work) {
    u32 i;

    for (i = 0; i < 0x20; i++) {
        if (work->unk_810[i] != 0) {
            func_08000DE8(&gUnk_02039B84->unk_03C[4], work->unk_810[i]);
        }
        work->unk_810[i] = 0;
    }
}

INCLUDE_ASM("bos6/func_0810C32C.s");

void func_0810C494(BosLstWork* work, u16 a, u16 b, u8 c) {
    u16 id;
    u16 v;

    id = a;
    v = id * 2;
    if (work->unk_012 < 0) {
        v ^= 1;
    }
    if (work->unk_01C == 1) {
        v ^= 1;
    }
    switch (gUnk_09A4D14C[a]) {
    case 0:
        func_08002A10(work->unk_028, gUnk_09C4B012);
        func_08005974(&work->unk_02C, v, b, gUnk_09EFAD3C, gUnk_09EFABB0);
        break;
    case 1:
        v -= 14;
        func_08002A10(work->unk_028, gUnk_09C51CBC);
        func_08005974(&work->unk_02C, v, b, gUnk_09EFADBC, gUnk_09EFAD74);
        break;
    }
    if (c == 1) {
        AnimChange(&work->unk_02C, v, b);
    } else {
        func_08005B64(&work->unk_02C);
        AnimStart(&work->unk_02C, v, b);
    }
    work->unk_01E = id;
    work->unk_020 = b;
    work->unk_022 = work->unk_012;
}

void func_0810C57C(BosLstWork* work, s16 a) {
    u8 f;

    if (work->unk_012 != a) {
        work->unk_012 = a;
        func_0810C494(work, work->unk_01E, work->unk_020, 1);
        f = 1;
        if (work->unk_012 > 0) {
            f = (work->unk_01C ^ f) != 0;
        } else if (work->unk_01C == 0) {
            f = 0;
        }
        if (f == 1) {
            work->unk_118 |= 4;
            work->unk_1F4[0].unk_04C |= 4;
            work->unk_1F4[1].unk_04C |= 4;
        } else {
            work->unk_118 &= ~4;
            work->unk_1F4[0].unk_04C &= ~4;
            work->unk_1F4[1].unk_04C &= ~4;
        }
    }
}

s16 func_0810C630(BosLstWork* work) {
    s16 r;

    r = -1;
    if (work->unk_1F4[0].unk_000 == 0) {
        r = 0;
    } else if (work->unk_1F4[1].unk_000 == 0) {
        r = 1;
    }
    return r;
}

u8 func_0810C65C(BosLstWork* work, u16 a) {
    s16 i;
    u8 r;

    r = 0;
    if (work->unk_006 == 1) {
        work->unk_1F4[0].unk_00A = 2;
        work->unk_1F4[1].unk_00A = 2;
    } else {
        if (a == 0) {
            i = 0;
            if (work->unk_1F4[i].unk_000 == 1) {
                work->unk_1F4[i].unk_00A = 2;
            } else {
                work->unk_1F4[i].unk_00A = 0;
            }
            work->unk_1F4[i].unk_002 = 1;
            i = 1;
            if (work->unk_1F4[i].unk_000 == 1) {
                work->unk_1F4[i].unk_00A = 2;
            } else {
                work->unk_1F4[i].unk_00A = 0;
            }
            work->unk_1F4[i].unk_002 = 1;
        } else {
            i = func_0810C630(work);
            work->unk_1F4[i].unk_00A = a;
            i = i ^ 1;
            if (work->unk_1F4[i].unk_000 == 1) {
                work->unk_1F4[i].unk_00A = 2;
            } else {
                work->unk_1F4[i].unk_00A = 0;
            }
            work->unk_1F4[i].unk_002 = 1;
        }
        r = 1;
    }
    return r;
}

void func_0810C754(BosLstWork* work) {
    s32 t;
    PcPos* pos;

    t = work->unk_07C;
    work->unk_07C = t - 0x100;
    if (gUnk_02039B84->unk_068 & 0x20000000) {
        work->unk_07C = t - 0x200;
    }
    if (work->unk_012 > 0) {
        pos = (PcPos*)gUnk_02039B84->unk_07C;
        if (pos->unk_04 > work->unk_044 + 0x1000) {
            work->unk_07C -= 0x80;
        }
    } else {
        pos = (PcPos*)gUnk_02039B84->unk_07C;
        if (pos->unk_04 < work->unk_044 - 0x1000) {
            work->unk_07C -= 0x80;
        }
    }
}

void func_0810C7C4(BosLstWork* work) {
    work->unk_058 = gUnk_09A4D154[(work->unk_06A >> 2) & 15] << 8;
    work->unk_06A += 1;
    if (work->unk_000 == 1) {
        work->unk_058 -= 0x1800;
    }
}

INCLUDE_ASM("bos6/task_bos_lst_0.s");

s32 func_0810CC14(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (c == 0) {
        c = func_08003C9C((abs(a - b) << 8) / 768);
        if (c < d) {
            c = d;
        }
        if (c > e) {
            c = e;
        }
    }
    if (abs(a - b) < c) {
        a = b;
    } else if (a < b) {
        a += c;
    } else {
        a -= c;
    }
    return a;
}

void func_0810CC68(BosLstWork* work) {
    if (work->unk_012 > 0) {
        work->unk_044 = func_0810CC14(work->unk_044, 0x14800, 0, 0x80, 0x200);
    } else {
        work->unk_044 = func_0810CC14(work->unk_044, 0xA800, 0, 0x80, 0x200);
    }
    work->unk_048 = func_0810CC14(work->unk_048, 0x1F000, 0, 0x80, 0x200);
    work->unk_04C = func_0810CC14(work->unk_04C, -0x5400, 0, 0x80, 0x400);
    if (work->unk_04C == -0x5400) {
        func_0810C754(work);
        if (work->unk_07C < 0) {
            work->unk_07C = 0x400;
            if (!(gUnk_02039B84->unk_068 & 0x20000000)) {
                func_0810C2E0(work);
            }
        }
    }
}

void func_0810CD00(BosLstWork* work) {
    UnkStruct_02039B84** pp;
    s32 y;

    if (work->unk_006 == 0) {
        func_0810C2CC(work, 2, 1);
        work->unk_08E = 0;
    }
    pp = &gUnk_02039B84;
    func_0810C754(work);
    if (work->unk_07C < 0) {
        work->unk_07C = 0x400;
        if (((*pp)->unk_068 & 0x20000000) == 0) {
            work->unk_084 = -0x1200;
            work->unk_088 = ((PcPos*)(*pp)->unk_07C)->unk_04 - ((work->unk_012 * 5) << 10);
            if (work->unk_088 > 0x14000) {
                work->unk_088 = 0x14000;
            }
            if (work->unk_088 < 0xB000) {
                work->unk_088 = 0xB000;
            }
            func_0810C2E0(work);
        }
    }
    if (work->unk_012 > 0) {
        if (work->unk_044 < 0x14800) {
            work->unk_044 = work->unk_044 + 192;
        }
    } else if (work->unk_044 > 0xA800) {
        work->unk_044 = work->unk_044 - 192;
    }
    y = 0x1F000;
    work->unk_050 = (-gSineTable[((work->unk_06C * 4) & 0xFF) + 64] / 16) << 8;
    work->unk_048 = func_0810CC14(work->unk_048, y, 0, 0x100, 0x200);
    work->unk_04C = func_0810CC14(work->unk_04C, -0xA400, 0x400, 0x100, 0x200);
}

void func_0810CE1C(BosLstWork* work) {
    if (work->unk_006 == 1) {
        func_0810C2CC(work, 3, 2);
        work->unk_08E = 0;
    }
    if (work->unk_012 > 0) {
        work->unk_044 = func_0810CC14(work->unk_044, 0x14800, 0, 0x80, 0x200);
    } else {
        work->unk_044 = func_0810CC14(work->unk_044, 0xA800, 0, 0x80, 0x200);
    }
    work->unk_048 = func_0810CC14(work->unk_048, 0x1F000, 0, 0x80, 0x200);
    work->unk_04C = func_0810CC14(work->unk_04C, -0x5400, 0, 0x80, 0x400);
    func_0810C754(work);
    if (work->unk_07C < 0) {
        work->unk_07C = 0x400;
        if (!(gUnk_02039B84->unk_068 & 0x20000000)) {
            func_0810C2E0(work);
        }
    }
}

INCLUDE_ASM("bos6/func_0810CEC8.s");

u8 func_0810D304(BosLstWork* work, s32 idx) {
    s32 i;
    u8 r;

    r = 0;
    if (idx < 0) {
        for (i = 0; i < work->unk_0C4; i++) {
            if (func_08110938(work->unk_810[i]) == 1) {
                r = 1;
                break;
            }
        }
    } else if (idx < work->unk_0C4) {
        if (func_08110938(work->unk_810[idx]) == 1) {
            r = 1;
        }
    }
    return r;
}

u8 func_0810D364(BosLstWork* work) {
    s16 v;
    s32 i;

    v = 0;
    for (i = 0; i < work->unk_0C4; i++) {
        v = func_0811095C(work->unk_810[i], v);
    }
    return v != 0;
}

void func_0810D3A8(BosLstWork* work) {
    s32 i;

    for (i = 0; i < work->unk_0C4; i++) {
        if (func_08110918(work->unk_810[i]) == 1) {
            func_08110984(work->unk_810[i]);
        }
    }
}

u8 func_0810D3E0(BosLstWork* work, s32 idx, s16 a) {
    s32 i;
    u8 r;

    r = 0;
    if (idx < 0) {
        for (i = 0; i < work->unk_0C4; i++) {
            if (func_08110918(work->unk_810[i]) == 1) {
                func_08110994(work->unk_810[i], a);
                r = 1;
            }
        }
    } else if (idx < work->unk_0C4) {
        if (func_08110918(work->unk_810[idx]) == 1) {
            func_08110994(work->unk_810[idx], a);
            r = 1;
        }
    }
    return r;
}

void func_0810D478(BosLstWork* work) {
    s32 i;

    for (i = 0; i < work->unk_0C4; i++) {
        if (func_08110918(work->unk_810[i]) == 1) {
            func_081109A8(work->unk_810[i]);
        }
    }
}

void func_0810D4B0(BosLstWork* work) {
    s32 i;
    u8 flag;

    flag = 1;
    for (i = 0; i < work->unk_0C4; i++) {
        if (func_08110918(work->unk_810[i]) == 1) {
            if (func_081109B8(work->unk_810[i], flag) == 1) {
                flag = 0;
            }
        }
    }
}

INCLUDE_ASM("bos6/func_0810D4F8.s");

s32 func_0810D70C(BosLstWork* work) {
    s32 base;
    s16 d;
    s32 r;

    base = work->unk_048 + work->unk_058;
    r = base + 0x1A00;
    d = abs((((PcPos*)gUnk_02039B84->unk_07C)->unk_04 - work->unk_044) >> 8);
    if (d > 23) {
        if (d <= 83) {
            r -= (d / 3) << 8;
        } else if (d <= 143) {
            r = base - 0x400;
        } else {
            base -= 0x400;
            r = base + (((d - 144) / 4) << 8);
        }
    }
    return r;
}

INCLUDE_ASM("bos6/func_0810D77C.s");

u8 func_0810DB40(BosLstWork* work) {
    switch (work->unk_00C) {
    case 0:
        func_0810FF50(work->unk_80C, 2, work->unk_012);
        func_0810CC68(work);
        break;
    case 1:
        func_0810FF50(work->unk_80C, 1, work->unk_012);
        func_0810CD00(work);
        break;
    case 2:
        func_0810FF50(work->unk_80C, 1, work->unk_012);
        func_0810CE1C(work);
        break;
    case 3:
        func_0810FF50(work->unk_80C, 0, work->unk_012);
        func_0810CEC8(work);
        break;
    case 4:
        func_0810FF50(work->unk_80C, 2, work->unk_012);
        func_0810D4F8(work);
        break;
    case 5:
        func_0810FF50(work->unk_80C, 3, work->unk_012);
        func_0810D77C(work);
        break;
    }
    func_0810C7C4(work);
    return 1;
}

u8 func_0810DC28(BosLstWork* work) {
    s32 v;
    u8 r;

    r = 1;
    v = *(s32*)&work->unk_018;
    if (work->unk_00A == 0) {
        work->unk_00A += 1;
        work->unk_082 += 1;
        work->unk_080 = 0;
        work->unk_068 = 0;
    }
    switch (work->unk_080) {
    case 0:
        if (work->unk_068 == 0) {
            m4aSongNumStart(0x119);
            work->unk_068 += 1;
        }
        work->unk_044 = func_0810CC14(work->unk_044, work->unk_088, 0, 384, 768);
        work->unk_04C += work->unk_084;
        work->unk_084 += 320;
        if (work->unk_04C > -0x5400) {
            work->unk_04C = -0x5400;
            work->unk_080 = 3;
            work->unk_068 = 0;
        }
        break;
    case 1:
    case 2:
        break;
    case 3:
        func_08017F70(work->unk_044 + (work->unk_012 << 12), work->unk_048, 0, 268);
        m4aSongNumStart(0x2AA);
        work->unk_080 = 4;
        work->unk_068 = 0;
    case 4:
        work->unk_068 += 1;
        if (work->unk_068 <= 19) {
            if (func_08011F78(268, ((PcPos*)gUnk_02039B84->unk_07C)->unk_04,
                              ((PcPos*)gUnk_02039B84->unk_07C)->unk_08, 0,
                              32, 32, (s16)(((v * 8) >> 8) + 8)) != 0) {
                m4aSongNumStart(0x2AB);
            }
        }
        if (func_080128EC() == 0) {
            if (work->unk_068 >= ((v * 30) >> 8) + 31) {
                work->unk_080 = 5;
                work->unk_068 = 0;
                if (work->unk_082 > 2) {
                    if (work->unk_006 == 0) {
                        func_0810C2CC(work, 2, 1);
                    } else {
                        func_0810C2CC(work, 3, 2);
                    }
                    work->unk_082 = 0;
                    r = 0;
                }
            }
        }
        break;
    case 5:
        work->unk_04C = func_0810CC14(work->unk_04C, -0x5400, 0, 256, 1024);
        if (work->unk_04C == -0x5400) {
            work->unk_080 = 1;
            work->unk_068 = 0;
            r = 0;
        }
        break;
    }
    return r;
}

INCLUDE_ASM("bos6/func_0810DE04.s");

u8 func_0810E210(BosLstWork* work) {
    u8 r;

    r = 1;
    if (work->unk_00A == 0) {
        func_0810C494(work, 7, 0, 1);
        m4aSongNumStart(0x117);
        m4aSongNumStart(280);
        work->unk_00A += 1;
    }
    func_0810C32C(work, 1);
    if (work->unk_068 == 30) {
        m4aSongNumStart(0x2C7);
    }
    if (work->unk_068 > 30) {
        work->unk_0B0 += 32;
        if (work->unk_0B0 > 0x800) {
            work->unk_0B0 = 0x800;
        }
        work->unk_044 = work->unk_044 - work->unk_012 * work->unk_0B0;
        if (work->unk_012 > 0) {
            if (work->unk_044 <= -0x8000) {
                r = 0;
            }
        } else if (work->unk_044 >= 0x27000) {
            r = 0;
        }
        if (work->unk_0B4 > 0) {
            work->unk_0B4 = work->unk_0B4 + 8;
        } else {
            work->unk_0B4 = work->unk_0B4 - 8;
        }
        work->unk_04C += work->unk_0B4;
        if (func_08011F78(0x10B, work->unk_044, work->unk_048, work->unk_04C + 0x4000, 12, 32, 64) != 0) {
            m4aSongNumStart(0x261);
        }
        if (r == 0) {
            work->unk_0A8 = 4;
            work->unk_068 = 0;
            func_0810C494(work, 0, 1, 1);
        }
    } else {
        work->unk_068 += 1;
    }
    return r;
}

u8 func_0810E32C(BosLstWork* work) {
    LstSpawn2 s;
    PcPos* obj;
    s16 ang;
    s32 i;
    u8 r;

    obj = (PcPos*)&work->unk_0E4;
    r = 1;
    switch (work->unk_00A) {
    case 0:
        m4aSongNumStart(0x2C5);
        if (work->unk_012 > 0) {
            func_08018A70(obj->unk_04 - 0x1800, obj->unk_08 - 0x400, obj->unk_0C, 256);
        } else {
            func_080189DC(obj->unk_04 + 0x1800, obj->unk_08 - 0x400, obj->unk_0C, 256);
        }
        work->unk_068 = 0;
        work->unk_00A += 1;
        break;
    case 1:
        func_0810C494(work, 6, 0, 1);
        m4aSongNumStart(0x117);
        work->unk_00A += 1;
        break;
    case 2:
        work->unk_068 += 1;
        if (work->unk_068 == 32) {
            work->unk_0B8 = 3 - work->unk_072;
            if (work->unk_0B8 <= 0) {
                work->unk_0B8 = 1;
            }
            if (work->unk_1F4[0].unk_000 == 1) {
                work->unk_0B8 += 1;
            }
            if (work->unk_1F4[1].unk_000 == 1) {
                work->unk_0B8 += 1;
            }
            ang = ((*(s32*)&work->unk_018 * 30) / 256) + 30;
            if (ang <= 44) {
                ang = 45;
            }
            s.unk_0C = obj->unk_04;
            s.unk_10 = obj->unk_08 + 0x800;
            s.unk_14 = obj->unk_0C - 0x1000;
            for (i = 0; i < work->unk_0B8; i++) {
                s.unk_00 = &work->unk_004;
                s.unk_04 = work->unk_0B8;
                s.unk_06 = i;
                s.unk_08 = i * ang + 90;
                work->unk_810[i] = TaskCreate(&gUnk_02039B84->unk_03C[4], gUnk_09EF9F24, &s);
            }
            work->unk_004 = 0;
            work->unk_068 = 0;
            work->unk_00A += 1;
        }
        break;
    default:
        r = 0;
        for (i = 0; i < work->unk_0B8; i++) {
            if (func_08111F4C(work->unk_810[i]) == 1) {
                r = 1;
                break;
            }
        }
        if (r == 0) {
            func_0810C2F8(work);
            func_0810C2CC(work, 4, 4);
            func_0810C494(work, 0, 1, 0);
        }
        break;
    }
    func_0810C7C4(work);
    return r;
}

u8 func_0810E524(BosLstWork* work) {
    s16 f;
    u8 r;

    r = 1;
    if (work->unk_0C0 == 0) {
        work->unk_0C0 += 1;
        if (work->unk_0BE <= 1) {
            work->unk_0BC = 1;
        } else {
            work->unk_0BC = 0;
        }
        work->unk_068 = 0;
    }
    if (func_0810D364(work) == 0) {
        func_0810C2F8(work);
        func_0810C2CC(work, 0, 5);
        work->unk_0BE = 0;
        work->unk_0BC = 3;
        work->unk_068 = 0;
    }
    switch (work->unk_0BC) {
    case 0:
        if (work->unk_068 == 0) {
            func_0810D3A8(work);
        }
        work->unk_068 += 1;
        if (work->unk_068 > 59) {
            work->unk_0BC = 1;
            work->unk_068 = 0;
        }
        break;
    case 1:
        f = 1;
        if (work->unk_1F4[0].unk_000 == 1) {
            f = 2;
        }
        if (work->unk_1F4[1].unk_000 == 1) {
            f++;
        }
        switch (work->unk_068) {
        case 0:
            if (work->unk_00E == 6) {
                func_0810D3E0(work, -1, 1);
                break;
            }
            if (func_0810D304(work, 1) == 0) {
                if (func_0810D3E0(work, 1, f) == 1) {
                    break;
                }
            }
        case 12:
            if (func_0810D304(work, 0) == 0) {
                if (func_0810D3E0(work, 0, f) == 1) {
                    break;
                }
            }
        case 24:
            if (func_0810D304(work, 2) == 0) {
                func_0810D3E0(work, 2, f);
            }
            break;
        }
        work->unk_068 += 1;
        if (func_0810D304(work, -1) == 0) {
            work->unk_068 = 0;
            if (work->unk_0BE > 6) {
                work->unk_0BC = 2;
            } else {
                if (work->unk_00C != 5) {
                    work->unk_0BE += 1;
                }
                r = 0;
            }
        }
        break;
    case 2:
        if (work->unk_068 == 30) {
            func_0810D478(work);
        }
        work->unk_068 += 1;
        if (work->unk_068 > 74) {
            work->unk_0BC = 3;
            work->unk_068 = 0;
        }
        break;
    case 3:
        func_0810C2F8(work);
        func_0810C2CC(work, 0, 5);
        work->unk_0BE = 0;
        r = 0;
        break;
    }
    func_0810C7C4(work);
    return r;
}

u8 func_0810E73C(BosLstWork* work) {
    s16 s;
    u8 r;

    r = 1;
    s = work->unk_00A;
    switch (s) {
    case 0:
        func_0810C494(work, 4, 0, 1);
        m4aSongNumStart(0x119);
        work->unk_00A += 1;
        work->unk_068 = 0;
        break;
    case 1:
        work->unk_068 += 1;
        if (work->unk_068 > 120) {
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 2:
        if (AnimIsFinished(&work->unk_02C) == 1) {
            func_08018184(work->unk_044, work->unk_048, work->unk_04C - 0x2000, 270);
            m4aSongNumStart(0x2AE);
            work->unk_00A += 1;
            work->unk_068 = 0;
        }
        break;
    case 3:
        if (func_080128EC() == 0) {
            func_0810C494(work, 0, 1, 0);
            r = 0;
        }
        if (r == 0) {
            if (work->unk_006 == 1) {
                func_0810C2CC(work, 1, 0);
            } else {
                func_0810C2CC(work, 2, 1);
            }
        }
        break;
    }
    if (work->unk_04C > -0x5400) {
        work->unk_04C = work->unk_04C - 0x400;
    }
    func_0810C7C4(work);
    return r;
}

u8 func_0810E844(BosLstWork* work) {
    void* p;
    s16 t;
    u8 d;

    p = &work->unk_0E4;
    t = work->unk_018;
    if (work->unk_018 <= 63) {
        t = 64;
    }
    switch (work->unk_00E) {
    case 0:
        d = func_0810DC28(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 1:
        d = func_0810DE04(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 2:
        d = func_0810E210(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 3:
        d = func_0810E32C(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    case 4:
    case 6:
        d = func_0810E524(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = 0x5A00;
        return 1;
    case 5:
        d = func_0810E73C(work);
        if (d != 0) {
            return 1;
        }
        func_0801AF08(p);
        work->unk_008 = d;
        work->unk_00A = d;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    default:
        func_0801AF08(p);
        work->unk_008 = 0;
        work->unk_00A = 0;
        work->unk_07C = ((t * 15) >> 4) << 8;
        return 1;
    }
    return 1;
}

u8 func_0810E950(BosLstWork* work) {
    void* p;

    p = &work->unk_0E4;
    if (AnimIsFinished((AnimState*)&work->unk_02C) == 1) {
        func_0801AF08(p);
        func_0810C494(work, 0, 1, 1);
        work->unk_008 = 0;
    }
    return 1;
}

u8 func_0810E984(BosLstWork* work) {
    func_0801AF08(&work->unk_0E4);
    work->unk_008 = 0;
    work->unk_00A = 0;
    return 1;
}

u8 func_0810E99C(BosLstWork* work) {
    LstSpawn3 s;
    PcPos* obj;

    obj = (PcPos*)&work->unk_0E4;
    func_0801AF08(obj);
    work->unk_072 += 1;
    work->unk_078 = 0;
    if (work->unk_01E != 2) {
        func_0810C494(work, 0, 1, 0);
    }
    func_0810C65C(work, 0);
    work->unk_07C = ((((*(s32*)&work->unk_018 * 240) >> 9) + 120) << 8);
    if (work->unk_006 == 1) {
        work->unk_026 = 120;
    }
    if (work->unk_00C < 4 || work->unk_00C > 5) {
        func_0810C2F8(work);
    }
    switch (work->unk_00C) {
    case 0:
        switch (work->unk_00E) {
        case 3:
            if (work->unk_072 > 2) {
                func_0810C2CC(work, 4, 4);
            }
            break;
        case 5:
            if (work->unk_006 == 0) {
                func_0810C2CC(work, 2, 1);
            } else {
                func_0810C2CC(work, 1, 0);
            }
            break;
        }
        break;
    case 1:
        if (work->unk_082 + work->unk_072 > 3) {
            work->unk_082 = 0;
            func_0810C2CC(work, 3, 2);
            work->unk_048 = 0x1F000;
            work->unk_04C = -0x5400;
        }
        break;
    case 2:
        work->unk_048 = 0x1F000;
        work->unk_04C = -0x5400;
        if (work->unk_08E + work->unk_072 > 3) {
            work->unk_08E = 0;
            func_0810C2CC(work, 3, 2);
        }
        break;
    case 3:
        work->unk_0AA = 0;
        func_0810C2CC(work, 5, 6);
        work->unk_06E = 0;
        if (((PcPos*)gUnk_02039B84->unk_07C)->unk_04 < 0xF800) {
            work->unk_044 = 0x15000;
            func_0810C57C(work, -1);
        } else {
            work->unk_044 = 0xA000;
            func_0810C57C(work, 1);
        }
        work->unk_048 = 0x1F000;
        work->unk_04C = -0x5400;
        break;
    case 4:
        func_0810D4B0(work);
        break;
    case 5:
        work->unk_026 = 0;
        func_0810D4B0(work);
        break;
    }
    work->unk_008 = 0;
    work->unk_00A = 0;
    s.unk_00 = work->unk_044 + work->unk_050;
    s.unk_04 = work->unk_048 + work->unk_054;
    s.unk_08 = (work->unk_04C + work->unk_058) - ((obj->unk_9C >> 1) << 8);
    s.unk_12 = 9;
    TaskCreate(&gUnk_02039B84->unk_03C[4], gTaskDescBtlPop, &s);
    return 1;
}

INCLUDE_ASM("bos6/func_0810EBA0.s");

u8 func_0810EF94(BosLstWork* work) {
    switch (work->unk_001) {
    case 0:
        work->unk_044 = func_0810CC14(work->unk_044, 0x1D000, 0, 0x80, 0x200);
        work->unk_048 = func_0810CC14(work->unk_048, 0x1F000, 0, 0x80, 0x200);
        work->unk_04C = func_0810CC14(work->unk_04C, -0x14400, 0, 0x80, 0x400);
        func_0810FF50(work->unk_80C, 4, work->unk_012);
        break;
    case 1:
        work->unk_044 = func_0810CC14(work->unk_044, 0x15500, 0, 0x80, 0x200);
        work->unk_048 = func_0810CC14(work->unk_048, 0x1F000, 0, 0x80, 0x200);
        work->unk_04C = func_0810CC14(work->unk_04C, -0x8400, 0, 0x80, 0x400);
        func_0810FF50(work->unk_80C, 0, work->unk_012);
        break;
    }
    func_0810C7C4(work);
    return 1;
}

void func_0810F064(BosLstWork* work, LstSub* p) {
    LstSpawn5 s;
    void* obj;
    u8 f;

    obj = &p->unk_018;
    if (p->unk_002 == 1) {
        p->unk_128.animId = 0xFFFF;
        p->unk_00C = -1;
        p->unk_002 = 0;
    }
    if (p->unk_00A == p->unk_00C) {
        switch (p->unk_00A) {
        case 3:
        case 4:
            break;
        default:
            if (AnimIsFinished(&p->unk_128) == 1) {
                if (p->unk_000 == 1) {
                    p->unk_00A = 2;
                } else {
                    p->unk_00A = 0;
                }
            }
            break;
        }
    }
    f = 1;
    switch (p->unk_00A) {
    case 1:
    case 3:
    case 4:
    case 6:
        f = 0;
        break;
    }
    if (work->unk_012 > 0) {
        if (p->unk_001 == 1) {
            func_08005974(&p->unk_128, p->unk_00A * 2, f, gUnk_09EFAE1C, gUnk_09EFADC4);
        } else {
            func_08005974(&p->unk_128, p->unk_00A * 2, f, gUnk_09EFAEAC, gUnk_09EFAE54);
        }
    } else {
        if (p->unk_001 == 1) {
            func_08005974(&p->unk_128, p->unk_00A * 2 + 1, f, gUnk_09EFAEAC, gUnk_09EFAE54);
        } else {
            func_08005974(&p->unk_128, p->unk_00A * 2 + 1, f, gUnk_09EFAE1C, gUnk_09EFADC4);
        }
    }
    p->unk_00C = p->unk_00A;
    AnimUpdate(&p->unk_128);
    switch (p->unk_00A) {
    default:
        func_0801C2DC(obj, 1);
        break;
    case 0:
        func_0801C2DC(obj, 0);
        break;
    case 2:
        func_0801C2DC(obj, 1);
        return;
    }
    switch (func_0801ADAC(obj)) {
    case 5:
        p->unk_004 = 1;
        p->unk_006 = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->unk_07C = work->unk_07C * 3;
        work->unk_07C = work->unk_07C / 4;
        p->unk_008 = 20;
        work->unk_076 = 20;
        if (p->unk_004 == 5) {
            func_0801AF08(obj);
        } else {
            p->unk_004 = 3;
            p->unk_006 = 0;
        }
        break;
    case 3:
        p->unk_004 = 4;
        p->unk_006 = 0;
        p->unk_002 = 1;
        p->unk_00A = 6;
        s.unk_00 = p->unk_01C;
        s.unk_04 = p->unk_020;
        s.unk_08 = p->unk_024;
        s.unk_0C = work->unk_012;
        TaskCreate(&gUnk_02039B84->unk_03C[4], gUnk_09EF9F3C, &s);
        break;
    case 4:
        p->unk_004 = 2;
        p->unk_006 = 0;
        break;
    }
    switch (p->unk_004) {
    case 0:
        break;
    case 3:
        p->unk_006 += 1;
        if (p->unk_006 > 20) {
            func_0801AF08(obj);
            p->unk_004 = 0;
            p->unk_006 = 0;
        }
        break;
    case 1:
    case 2:
    case 5:
        func_0801AF08(obj);
        p->unk_004 = 0;
        p->unk_006 = 0;
        break;
    case 4:
        p->unk_000 = 1;
        p->unk_008 = 0;
        break;
    }
}

INCLUDE_ASM("bos6/task_bos_lst_1.s");
INCLUDE_ASM("bos6/task_bos_lst_2.s");

void task_bos_lst_3(BosLstWork* work) {
    s32 i;

    func_0801B7D8(&work->unk_0E4);
    func_0801B7D8(&work->unk_1F4[0].unk_018);
    func_0801B7D8(&work->unk_1F4[1].unk_018);
    func_08012304(work->unk_474);
    func_08012304(&work->unk_4D0);
    for (i = 0; i < 8; i++) {
        func_08012304(work->unk_52C[i]);
    }
    func_0810C2F8(work);
    ReleaseObjTiles((void*)work->unk_1F4[0].unk_010);
    ReleaseObjTiles((void*)work->unk_1F4[1].unk_010);
    ReleaseObjTiles((void*)work->unk_028);
    ReleaseObjPalette((void*)work->unk_0E0);
    TaskPoolDestroy(&work->unk_890);
}

s32 func_0810FE84(s32 x) {
    return x * x;
}

s32 func_0810FE8C(s32 x) {
    return x * x;
}
