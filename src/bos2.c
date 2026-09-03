#include "macros.h"
#include "bos2.h"

INCLUDE_ASM("bos2/task_bos_tm_body_0.s");
INCLUDE_ASM("bos2/task_bos_tm_body_1.s");
INCLUDE_ASM("bos2/task_bos_tm_body_2.s");
void task_bos_tm_body_3(TmBodyWork* work) {
    if ((work->unk_000->unk_28 & 8) == 0) {
        func_080B83B8(work->unk_12C);
    }

    ReleaseObjTiles(work->unk_004);
    ReleaseObjPalette(work->unk_008);
    ReleaseObjPalette(work->unk_00C);
}
void func_080B9FC4(TmBodyWork* work) {
    if (work->unk_158 < work->unk_15A / 2) {
        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 19) {
            func_08083900(GetRandom() % 2 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }
    } else if (GetRandom() % 100 <= 29) {
        func_08083900(GetRandom() % 3 + 6);
    } else {
        func_08083900(GetRandom() % 6 + 1);
    }
}
INCLUDE_ASM("bos2/func_080BA08C.s");

void func_080BA0E4(s32* p, s32 a, s32 b, s32 c) {
    p[1] = (s16)a << 8;
    p[2] = (s16)b << 8;
    p[3] = (s16)c << 8;
}

void func_080BA0F8(u8* work) {
    func_08012304(work + 0x40);
}

INCLUDE_ASM("bos2/func_080BA104.s");
INCLUDE_ASM("bos2/func_080BA2B0.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_0.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_1.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_2.s");

void task_bos_tm_foot_3(TmFootWork* work) {
    if ((*(u16*)((u8*)*(void**)((u8*)work + 0x47C) + 40) & 8) == 0) {
        func_080BA0F8((u8*)work + 0x24C);
        func_080BA0F8((u8*)work + 0x364);
    }

    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_014);
    ReleaseObjPalette((void*)work->unk_018);
}

void func_080BB1B8(void* pool, TmClbArg* p, TmClbSrc* a) {
    p->unk_08 = a;
    p->unk_00 = 0;
    p->unk_04 = 1;
    p->unk_0C = 0;
    TaskCreate(pool, gUnk_09EF26FC, p);
}

void func_080BB1D8(TmClbArg* p, TmClbSrc* a, s32 b) {
    p->unk_08 = a;
    p->unk_0C = b;
    p->unk_00 = 4;
    p->unk_04 = 0;
}

void func_080BB1E8(TmClbArg* p, TmClbSrc* a) {
    p->unk_08 = a;
    p->unk_0C = 0;
    p->unk_00 = 0;
    p->unk_04 = 0;
}

void func_080BB1F4(TmClbArg* p, TmClbSrc* a, u8 mode) {
    p->unk_08 = a;
    p->unk_0C = 0;
    p->unk_04 = 2;

    switch (mode) {
    case 0:
        p->unk_00 = 1;
        break;
    case 1:
        p->unk_00 = 1;
        break;
    case 2:
        p->unk_00 = 2;
        break;
    case 3:
        p->unk_00 = 3;
        break;
    }
}

void task_bos_tm_clb_0(TmClbWork* work, void* arg) {
    void* p;

    work->unk_004 = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->unk_008 = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->unk_000 = arg;
    p = ((void**)arg)[2];
    work->unk_00C = *(u16*)((u8*)p + 12);
    work->unk_010 = *(s32*)p;
    work->unk_014 = *(s32*)((u8*)p + 4);
    work->unk_018 = *(s32*)((u8*)p + 8);
}

u8 task_bos_tm_clb_1(TmClbWork* work) {
    TmClbArg* a = work->unk_000;

    switch (a->unk_00) {
    case 4:
        work->unk_010 += (a->unk_08->unk_00 - work->unk_010) >> 4;
        work->unk_014 = a->unk_08->unk_04;
        work->unk_018 += a->unk_0C;
        a->unk_0C += 51;

        if (a->unk_0C > 0 && work->unk_018 >= a->unk_08->unk_08) {
            work->unk_018 = a->unk_08->unk_08;
            a->unk_00 = 0;
            a->unk_04 = 1;
        }

        break;
    case 0:
        work->unk_010 = a->unk_08->unk_00;
        work->unk_014 = a->unk_08->unk_04;
        work->unk_018 = a->unk_08->unk_08;
        break;
    case 1:
        work->unk_010 = a->unk_08->unk_00;
        work->unk_014 = a->unk_08->unk_04;
        work->unk_018 = a->unk_08->unk_08;
        break;
    case 2:
        work->unk_010 = a->unk_08->unk_00 - 0x600;
        work->unk_014 = a->unk_08->unk_04;
        work->unk_018 = a->unk_08->unk_08;
        break;
    case 3:
        work->unk_010 = a->unk_08->unk_00 + 0x600;
        work->unk_014 = a->unk_08->unk_04;
        work->unk_018 = a->unk_08->unk_08 - 0x500;
        break;
    }

    switch (a->unk_04) {
    case 0:
        work->unk_00C += 0x10;
        break;
    case 1:
        ApproachAngle(&work->unk_00C, a->unk_08->unk_0C, 2);
        break;
    case 2:
        work->unk_00C = a->unk_08->unk_0C;
        break;
    }

    return 1;
}
void task_bos_tm_clb_2(TmClbWork* work) {
    u8* p;
    s16 x;
    s16 y;

    p = func_08002C28(work->unk_00C, 0);
    WorldToScreen(&x, &y, work->unk_010, work->unk_014, work->unk_018);
    DrawSprite(x, y, gUnk_0962E838, work->unk_004, work->unk_008, (s32)p, 0x800,
               (u16)(-0x1002 - (work->unk_014 >> 8) * 4));
    p[0x0A] = 1;
    DrawSprite(x, y, work->unk_000->unk_14, work->unk_000->unk_10, work->unk_008, (s32)p, 0x800,
               (u16)(-0x1003 - (work->unk_014 >> 8) * 4));
}

void task_bos_tm_clb_3(TmClbWork* work) {
    ReleaseObjTiles(work->unk_004);
    ReleaseObjPalette(work->unk_008);
}

void func_080BB428(u8* dst, u8* src) {
    s32 i;

    i = 3;

    do {
        *(u16*)(dst + 20) = *src;
        src += 4;
        dst += 0x34;
    } while (--i >= 0);
}

void func_080BB43C(u8* work, u8* src, u16 a, u8* dst) {
    if (*(u8**)(work + 8) != src) {
        *(u8**)(work + 8) = src;
        *(u16*)(work + 0) = 0;
        *(u16*)(work + 2) = 0;
        *(u16*)(work + 4) = a;
        func_080BB428(dst, src + 4);
    }
}

void func_080BB464(TmArmWork* work) {
    TmArmJoint* s = &work->unk_010[7];
    TmArmPos* d = &work->unk_1F8[0];

    d->unk_00 = s->unk_00 + gSineTable[s->unk_08] * 12 + work->unk_00C->unk_00;
    d->unk_08 = s->unk_04 + -gSineTable[s->unk_08 + 0x40] * 12 + work->unk_00C->unk_08;
    d->unk_04 = work->unk_00C->unk_04;
}
void func_080BB4C0(TmArmWork* work) {
    TmArmJoint* s = &work->unk_010[3];
    TmArmPos* d = &work->unk_1F8[1];

    d->unk_00 = s->unk_00 + gSineTable[s->unk_08] * 12 + work->unk_00C->unk_0C;
    d->unk_08 = s->unk_04 + -gSineTable[s->unk_08 + 0x40] * 12 + work->unk_00C->unk_14;
    d->unk_04 = work->unk_00C->unk_10;
}

INCLUDE_ASM("bos2/func_080BB518.s");
INCLUDE_ASM("bos2/func_080BB588.s");
INCLUDE_ASM("bos2/func_080BB5E8.s");
INCLUDE_ASM("bos2/task_bos_tm_arm_0.s");
INCLUDE_ASM("bos2/func_080BB924.s");
INCLUDE_ASM("bos2/func_080BC304.s");
u8 task_bos_tm_arm_1(TmArmWork* work) {
    void* gfx;

    if (work->unk_234 != work->unk_00C->unk_18->unk_2C) {
        work->unk_234 = work->unk_00C->unk_18->unk_2C;
        work->unk_1B0 = 0;
        work->unk_1B2 = 0;
    }

    if (gFrameCounter % 2 != 0) {
        func_080BB924(work);
    } else {
        func_080BC304(work);
    }

    if (work->unk_00C->unk_18->unk_2C != 13) {
        gfx = AnimUpdate(&work->unk_23C);
        work->unk_1DC = (u32)gfx;
        work->unk_1F4 = (u32)gfx;

        if (gFrameCounter % 5 == 0) {
            LoadObjPaletteBank(work->unk_004[3] + 1, gUnk_096FB304 + work->unk_254 * 32);
            work->unk_254 = (work->unk_254 + 1) & 7;
        }
    }

    TaskPoolUpdate(&work->unk_1B4);

    return 1;
}
INCLUDE_ASM("bos2/task_bos_tm_arm_2.s");

void task_bos_tm_arm_3(TmArmWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjTiles((void*)work->unk_238);
    ReleaseObjPalette(work->unk_004);
    ReleaseObjPalette((void*)work->unk_008);
    TaskPoolDestroy(&work->unk_1B4);
}

void task_bos_tm_tbl_0(TmTblWork* work, void* arg) {
    func_080122AC(&work->unk_004, 7, 0x1C, 0);
    func_08012324(&work->unk_004, 0x10000, 0x16000, 0);
    func_08012614(&work->unk_004, 0);
    DisableBg(1);
    work->unk_000 = (u32)arg;
    work->unk_068 = 0;
    work->unk_062 = 1;
    work->unk_064 = 0;
    work->unk_066 = 0;
    work->unk_067 = 0;
    work->unk_060 = 0;
}

INCLUDE_ASM("bos2/task_bos_tm_tbl_1.s");

void task_bos_tm_tbl_3(TmTblWork* work) {
    func_08012304(&work->unk_004);
    DisableBg(1);
}

INCLUDE_ASM("bos2/task_bos_jf_0.s");
INCLUDE_ASM("bos2/task_bos_jf_1.s");

void task_bos_jf_2(JfWork* work) {
    TaskPoolDraw(&work->unk_254);
}

void task_bos_jf_3(JfWork* work) {
    if ((work->unk_24C & 8) == 0) {
        func_0801B7D8(&work->unk_110);
        func_0801B7D8(work);
    }

    TaskPoolDestroy(&work->unk_254);
}
INCLUDE_ASM("bos2/func_080BD4A8.s");
u8 func_080BD7F8(s32* p, s32* a, s32 b, s32* out) {
    s32 v1;
    s32 v2;
    s32 v3;

    v1 = -((gUnk_0203ACC4 + 1) << 11);
    v2 = -((gUnk_0203ACD4 + 1) << 11);
    v3 = -((gUnk_0203ACC0 + 1) << 11);

    if (*p <= 0x259FF) {
        if (*p <= 0x221FF) {
            if (*p <= 0x1E9FF) {
                if (*p <= 0x1B1FF) {
                    *out = 0;

                    if (*p > 0x1AE00) {
                        return 0;
                    }
                } else {
                    *out = v1;

                    if (*p <= 0x1B5FF) {
                        return 0;
                    }

                    if (*p > 0x1E600 && v1 != v2) {
                        return 0;
                    }
                }
            } else {
                *out = v2;

                if (*p <= 0x1EDFF && v1 != v2) {
                    return 0;
                }

                if (*p > 0x21E00 && v2 != v3) {
                    return 0;
                }
            }
        } else {
            *out = v3;

            if (*p <= 0x225FF && v2 != v3) {
                return 0;
            }

            if (*p > 0x25600) {
                return 0;
            }
        }
    } else {
        *out = 0;

        if (*p <= 0x25DFF) {
            return 0;
        }
    }

    return 1;
}

void task_bos_jf_map_0(JfMapWork* work, JfMapArg* arg) {
    RequestDma3Copy(gUnk_096C5C64, gUnk_0203ACE0, 0x800);
    gUnk_0203ACD8 = arg->unk_10;
    func_080BDAAC();
    LoadBgTiles(0, arg->unk_00, arg->unk_04);
    LoadBgPalette(0, arg->unk_08, arg->unk_0C);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0x23E00;
    gUnk_02039B84->unk_00C = 0x12800;
    gUnk_02039B84->unk_000 = 0x23E00;
    gUnk_02039B84->unk_004 = 0x12800;
    gUnk_02039B84->unk_010 = 0x23E00;
    gUnk_02039B84->unk_014 = 0x12800;
    gUnk_02039B84->unk_01C = 0x23E00;
    gUnk_02039B84->unk_020 = 0x12800;
    gUnk_02039B84->unk_01A = 0xF;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
    work->unk_00 = 0;
    work->unk_02 = 0;
    gUnk_0203ACD0 = 0;
    gUnk_0203B4E0 = 0;
    gUnk_0203ACC8 = 0;
    gUnk_0203ACCC = 0;
    gUnk_0203B4E8 = 0;
}

u8 task_bos_jf_map_1(JfMapWork* work) {
    s32 dx;
    s32 dy;

    work->unk_00++;

    if (work->unk_00 > 14) {
        work->unk_00 = 0;
        work->unk_02++;

        if (work->unk_02 > 7) {
            work->unk_02 = 0;
        }

        LoadPalette(gUnk_096FB484 + work->unk_02 * 32, (void*)0x05000020, 0x20);
    }

    func_0802F208();
    dx = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
    dy = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gUnk_02039B84->unk_008 += dx;
    gUnk_02039B84->unk_00C += dy;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;

    if (gUnk_02039B84->unk_000 < (gUnk_02039B84->unk_0DA + 0x14) << 8) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 0x14) << 8;
    } else if (gUnk_02039B84->unk_000 > (gUnk_02039B84->unk_0DC - 0x1C) << 8) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 0x1C) << 8;
    }

    if (gUnk_02039B84->unk_004 < (gUnk_02039B84->unk_0DE - 0x90) << 8) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0DE - 0x90) << 8;
    } else if (gUnk_02039B84->unk_004 > (gUnk_02039B84->unk_0E0 - 0x48) << 8) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0E0 - 0x48) << 8;
    }

    gUnk_02039B84->unk_004 += func_0802F268() + func_080BDB58();
    func_08005244(0, (gUnk_02039B84->unk_000 >> 8) + 8, (gUnk_02039B84->unk_004 >> 8) + 0x28);

    return 1;
}

void func_080BDAAC(void) {
    func_080C6EB0(gUnk_09EF275C[0][gUnk_0203ACC4], gUnk_0203AF2C[0], 7, 0x17);
    func_080C6EB0(gUnk_09EF275C[1][gUnk_0203ACD4], gUnk_0203AF2C[1], 7, 0x17);
    func_080C6EB0(gUnk_09EF275C[0][gUnk_0203ACC0], gUnk_0203AF2C[2], 7, 0x17);
    func_0800516C(0, gUnk_0203ACD8, 2, 2);
}
void func_080BDB28(s16 a) {
    gUnk_0203ACD0 = 1;
    gUnk_0203B4E0 = 0;
    gUnk_0203ACC8 = 0;
    gUnk_0203ACCC = a;
    gUnk_0203B4E8 = 0;
}

s32 func_080BDB58(void) {
    if (gUnk_0203ACD0 == 1) {
        gUnk_0203ACC8++;

        if (gUnk_0203ACC8 < gUnk_0203ACCC) {
            if (gUnk_0203B4E0 % 4 == 0) {
                gUnk_0203B4E8 = 0x200;
            } else if (gUnk_0203B4E0 % 4 == 2) {
                gUnk_0203B4E8 = -0x200;
            }

            gUnk_0203B4E0++;
        } else {
            gUnk_0203ACD0 = 0;
        }
    }

    return gUnk_0203B4E8;
}

INCLUDE_ASM("bos2/task_bos_jf_lamp_0.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_1.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_2.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_3.s");

void func_080BE380(u8 a, u16 b, JfMajinWork* work) {
    func_080BE3DC(a, work);
    func_0800516C(1, gUnk_0203B500, 2, 2);
    LoadBgTiles(1, gUnk_09EF28D0[a], b * 32);
    work->unk_00->unk_24C &= ~0x10;
}
void func_080BE3DC(u8 a, JfMajinWork* work) {
    s16 n;

    if (work->unk_00->unk_00C < -0x8000) {
        RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, 0x800);
    } else {
        n = ((work->unk_00->unk_00C >> 8) + 0x88) / 8 + work->unk_6A;

        if (n > 0x20) {
            func_0800443C(gUnk_0203B510, 0x800);
        } else {
            RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, (0x20 - n) * 64);
            func_0800443C(gUnk_0203B510 + (0x20 - n) * 64, n * 64);
        }
    }
}
void func_080BE478(u8 a, JfMajinWork* work) {
    s16 n;

    if (work->unk_00->unk_00C >= -0x8000) {
        n = ((work->unk_00->unk_00C >> 8) + 0x88) / 8 + work->unk_6A;

        if (n > 0x20) {
            func_0800443C(gUnk_0203B510, 0x800);
        } else {
            RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, (0x20 - n) * 64);
            func_0800443C(gUnk_0203B510 + (0x20 - n) * 64, n * 64);
        }

        func_0800516C(1, gUnk_0203B500, 2, 2);
    }
}

INCLUDE_ASM("bos2/task_bos_jf_majin_0.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_1.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_2.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_3.s");
INCLUDE_ASM("bos2/func_080C0258.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_0.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_1.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_2.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_3.s");
INCLUDE_ASM("bos2/task_bos_jf_borderline_0.s");

u8 task_bos_jf_borderline_1(JfBorderlineWork* work) {
    BosPos* p = work->unk_000;

    func_080C1A48(work);
    work->unk_098 = p->unk_04 + work->unk_0A4;
    work->unk_09C = p->unk_08 + work->unk_0A8;
    work->unk_00C = AnimUpdate(&work->unk_01C);
    work->unk_010 = AnimUpdate(&work->unk_034);
    work->unk_014 = AnimUpdate(&work->unk_04C);
    work->unk_018 = AnimUpdate(&work->unk_064);
    work->unk_07C = AnimUpdate(&work->unk_080);

    return 1;
}

INCLUDE_ASM("bos2/task_bos_jf_borderline_2.s");

void task_bos_jf_borderline_3(JfBorderlineWork* work) {
    ReleaseObjTiles((void*)work->unk_004);
    ReleaseObjPalette((void*)work->unk_008);
}

INCLUDE_ASM("bos2/func_080C1A48.s");
INCLUDE_ASM("bos2/task_bos_dsd_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_1.s");

void task_bos_dsd_2(DsdWork* work) {
    TaskPoolDraw(&work->unk_37C);
}

void task_bos_dsd_3(DsdWork* work) {
    BosSub* a;
    BosSub* b;

    a = &work->unk_000[1];
    b = &work->unk_000[2];
    TaskPoolDestroy(&work->unk_37C);
    func_08012304(&work->unk_000[2].unk_040);
    func_0801B7D8(work);
    func_0801B7D8(a);
    func_0801B7D8(b);
}

void func_080C211C(u8 index) {
    func_0800516C(1, gUnk_09EF2AA4 + index * 0x10, 2, 2);
}

void func_080C213C(u8 index, u16 a) {
    func_0800516C(1, gUnk_09EF2AA4 + index * 0x10, 2, 2);
    LoadBgTiles(1, gUnk_09EF2D94[index], a * 32);
}

INCLUDE_ASM("bos2/task_bos_dsd_main_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_main_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_main_2.s");

void task_bos_dsd_main_3(DsdMainWork* work) {
    ReleaseObjTiles(work->unk_00C);
    ReleaseObjTiles(work->unk_010);
    ReleaseObjPalette(work->unk_04C);
    ReleaseObjPalette(work->unk_050);
    ReleaseObjTiles(work->unk_000->unk_360);
    ReleaseObjPalette(work->unk_000->unk_364);
    ReleaseObjTiles(work->unk_000->unk_368);
    ReleaseObjPalette(work->unk_000->unk_36C);
    ReleaseObjPalette(work->unk_000->unk_370);
    ReleaseObjTiles(work->unk_000->unk_374);
    ReleaseObjPalette(work->unk_000->unk_378);
    func_08012304(work->unk_0B4);
    TaskPoolDestroy(&work->unk_058);
}

void func_080C2734(DsdMainWork* work) {
    BosSub* q = &work->unk_000->unk_000[1];

    if (q->unk_02C > 0) {
        if (GetRandom() % 30 == 0) {
            TaskCreate(&work->unk_058, gUnk_09EF2EA8, work->unk_000);
        }

        if ((work->unk_000->unk_358 & 0x20) == 0) {
            *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) += work->unk_000->unk_35C;
        }

        if (work->unk_070 != (s8)gUnk_02039B84->unk_1CA[0]) {
            if ((s8)gUnk_02039B84->unk_1CA[0] > 0) {
                work->unk_000->unk_358 |= 0x40;

                if ((s8)gUnk_02039B84->unk_1CA[0] > 14) {
                    work->unk_000->unk_35C = 0x180;
                } else {
                    work->unk_000->unk_35C = ((s8)gUnk_02039B84->unk_1CA[0] << 8) / 10;
                }
            } else if ((s8)gUnk_02039B84->unk_1CA[0] < 0) {
                work->unk_000->unk_358 |= 0x40;
                work->unk_000->unk_35C = ((s8)gUnk_02039B84->unk_1CA[0] << 9) / 10;
            } else {
                work->unk_000->unk_358 &= ~0x40;
            }
        } else {
            work->unk_000->unk_358 &= ~0x40;
        }
    }
}

void func_080C2828(DsdMainWork* work) {
    DsdWork* p = work->unk_000;
    BosSub* q = &p->unk_000[1];

    p->unk_354 = 0;
    work->unk_00A = 0;
    work->unk_000->unk_356 = 0;
    func_080C213C(0, 0x60);
    work->unk_054 = 1;
    AnimStart(&work->unk_01C, 0, 1);
    AnimStart(&work->unk_034, 0, 1);
    p->unk_000[0].unk_00C = -0x6400;
    q->unk_00C = -0x8C00;
}

INCLUDE_ASM("bos2/func_080C288C.s");
INCLUDE_ASM("bos2/func_080C2944.s");

void func_080C297C(DsdMainWork* work, s32 x, s32 y, s32 z) {
    BosSub* q = &work->unk_000->unk_000[1];

    func_080062F4(0, 0);
    func_080062F4(0x13, 0);
    func_08006238(0, 0x14, 8);
    func_08018B04(x - 0x1400, y, z - 0xA00, 0x100);
    m4aSongNumStart(0x2D1);
    q->unk_034 |= 0x01000000;
}

INCLUDE_ASM("bos2/func_080C29F4.s");
INCLUDE_ASM("bos2/func_080C2F68.s");
INCLUDE_ASM("bos2/func_080C3504.s");

void task_bos_dsd_map_0(void) {
    LoadBgTiles(0, gUnk_096874E4, 0x8000);
    LoadBgPalette(0, gUnk_096FB744, 0x120);
    func_0800516C(0, gUnk_09EF2E68, 2, 2);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0xA000;
    gUnk_02039B84->unk_00C = 0x13600;
    gUnk_02039B84->unk_000 = 0xA000;
    gUnk_02039B84->unk_004 = 0x13600;
    gUnk_02039B84->unk_010 = 0xA000;
    gUnk_02039B84->unk_014 = 0x13600;
    gUnk_02039B84->unk_01C = 0xA000;
    gUnk_02039B84->unk_020 = 0x13600;
    gUnk_02039B84->unk_01A = 0xF;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
}

u8 task_bos_dsd_map_1(void) {
    s32 dx;
    s32 dy;

    func_0802F208();
    dx = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
    dy = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gUnk_02039B84->unk_008 += dx;
    gUnk_02039B84->unk_00C += dy;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;

    if (gUnk_02039B84->unk_000 < (gUnk_02039B84->unk_0DA + 0x78) << 8) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 0x78) << 8;
    } else if (gUnk_02039B84->unk_000 > (gUnk_02039B84->unk_0DC - 0x78) << 8) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 0x78) << 8;
    }

    if (gUnk_02039B84->unk_004 < 0x5000) {
        gUnk_02039B84->unk_004 = 0x5000;
    } else if (gUnk_02039B84->unk_004 > (gUnk_02039B84->unk_0E0 - 0x50) << 8) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0E0 - 0x50) << 8;
    }

    gUnk_02039B84->unk_004 += func_0802F268();
    func_08005244(0, (gUnk_02039B84->unk_000 >> 8) - 0x78, (gUnk_02039B84->unk_004 >> 8) - 0x28);

    return 1;
}

void task_bos_dsd_ita_0(DsdItaWork* work, void* arg) {
    work->unk_000 = (u32)arg;
    work->unk_074 = 0x1E;
    work->unk_076 = 0;
    work->unk_078 = 0;
    work->unk_07A = 0;
    work->unk_060 = 0x12C00;
    work->unk_064 = 0x17C00;
    work->unk_068 = -0x7800;
    work->unk_06C = 0x100;
    work->unk_070 = 0x19;
    work->unk_07C = 0;
    work->unk_07E = 0;
    work->unk_080 = 0;
    func_080122AC(&work->unk_004, 7, 0x20, 3);
    func_08012324(&work->unk_004, work->unk_060, work->unk_064, work->unk_068);
    work->unk_088 = (u32)gUnk_09EF3BF8;
    work->unk_08C = (u32)gUnk_09EF3C18;
}

INCLUDE_ASM("bos2/task_bos_dsd_ita_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_ita_2.s");

void task_bos_dsd_ita_3(DsdItaWork* work) {
    func_08012304(&work->unk_004);
}

INCLUDE_ASM("bos2/func_080C427C.s");

void func_080C43E4(s32* p, s32 target) {
    s32 cur;
    s32 delta;

    cur = *p;
    delta = (target - cur) >> 1;

    if (target > cur) {
        if (delta > 0x4FF) {
            delta = 0x500;
        }
    } else if (target < cur) {
        if (delta <= -0x500) {
            delta = -0x500;
        }
    } else {
        return;
    }

    *p = cur + delta;
}

INCLUDE_ASM("bos2/task_bos_dsd_rock_0.s");

u8 task_bos_dsd_rock_1(DsdRockWork* work) {
    if ((work->unk_00->unk_358 & 0x40) != 0) {
        work->unk_10 = -work->unk_10;
        work->unk_18 = -work->unk_18;
    } else {
        work->unk_04 += work->unk_10;
        work->unk_0C += work->unk_18;
    }

    if (work->unk_04 > gUnk_02039B84->unk_000 + 0x8800 || work->unk_04 < gUnk_02039B84->unk_000 - 0x8800) {
        return 0;
    }

    return 1;
}
void task_bos_dsd_rock_2(DsdRockWork* work) {
    s32 affine;
    s32 h;
    s32 prio;
    s16 x;
    s16 y;

    if (work->unk_20 != 0) {
        affine = 0;
        h = 10;
        prio = 0x400;
    } else {
        affine = AllocObjAffine(0, 0x59, 0x59, 0);
        h = 0xFFF5;
        prio = 0xC00;
    }

    WorldToScreen(&x, &y, work->unk_04, work->unk_08, work->unk_0C);
    DrawSprite(x, y, work->unk_1C, work->unk_00->unk_368, work->unk_00->unk_36C, affine, prio, h);
}

void task_bos_dsd_rock_3(void) {
}

void task_bos_dsd_circle_0(DsdCircleWork* work, void* arg) {
    work->unk_00 = arg;
    work->unk_08 = (gUnk_0961A89E << 8) + 0xDC00;
    work->unk_0C = (gUnk_0961A8B0 << 8) + 0x16800;
    work->unk_10 = 0;
    work->unk_14 = 0;
    work->unk_16 = 0;
    work->unk_1A = 0;
    work->unk_1C = 0;
    work->unk_18 = 0;
    work->unk_04 = gUnk_09EF3C50;
}

INCLUDE_ASM("bos2/task_bos_dsd_circle_1.s");

void task_bos_dsd_circle_2(DsdCircleWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->unk_08, work->unk_0C, work->unk_10);
    DrawSprite(x, y, work->unk_04, work->unk_00->unk_360, work->unk_00->unk_364, 0, 0xC00, 0xFFFF);
}

void task_bos_dsd_circle_3(void) {
}

void task_bos_dsd_energy1_0(DsdEnergy1Work* work, void* arg) {
    work->unk_00 = arg;
    work->unk_04 = 0xBC00;
    work->unk_08 = 0x16800;
    work->unk_0C = -0x2400;
    work->unk_10 = 0;
    work->unk_14 = 0;
    work->unk_18 = 0;
    work->unk_28 = 0xF4;
    work->unk_29 = 0xF4;
    work->unk_2C = 0x800;
    work->unk_30 = 0x19;
    work->unk_34 = 0;
    work->unk_36 = 0;
    work->unk_38 = 0;
    work->unk_3C = 0xF;
    work->unk_3A = 0x3C;
    work->unk_48 = 0;
    work->unk_1C = gSineTable[work->unk_28] * work->unk_2C >> 8;
    work->unk_20 = 0;
    work->unk_24 = -gSineTable[work->unk_28 + 0x40] * work->unk_2C >> 8;
    work->unk_44 = gUnk_08B22CBC;
}

INCLUDE_ASM("bos2/task_bos_dsd_energy1_1.s");

void task_bos_dsd_energy1_2(DsdEnergy1Work* work) {
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_48 == 1) {
        if (work->unk_0C >= 0 && gUnk_02039B84->unk_024 == 0x100) {
            affine = 0;
        } else {
            scale = 0x200 - -work->unk_0C / 128;

            if (scale <= 0x7F) {
                scale = 0x80;
            }

            flag = 0;

            if (scale > 0x100) {
                flag = 1;
            }

            affine = AllocObjAffine(0, scale, scale, flag);
        }

        WorldToScreen(&x, &y, work->unk_04, work->unk_08, 0);
        DrawSprite(x, y, work->unk_44, work->unk_00->unk_374, work->unk_00->unk_378, affine, 0xC00, 0xFFF0);
    }
}

INCLUDE_ASM("bos2/task_bos_dsd_energy1_3.s");

void task_bos_dsd_energy2_0(DsdEnergy2Work* work, void* arg) {
    work->unk_00 = arg;
    work->unk_04 = 0xBC00;
    work->unk_08 = 0x16800;
    work->unk_0C = -0x2C00;
    work->unk_2C = 0;
    work->unk_2E = 0;
    work->unk_30 = 0;
    work->unk_32 = 0xF;
    work->unk_10 = 0x80;
    work->unk_14 = 0x80;
    work->unk_20 = 0;
    work->unk_24 = 0;
    work->unk_28 = -0x500;
    work->unk_34 = 0;
    work->unk_3C = 0;
    work->unk_38 = gUnk_08B22CBC;
    func_08014588(work->unk_04, work->unk_08, work->unk_0C, work->unk_10, work->unk_32, 0);
    m4aSongNumStart(0x2C0);

    switch (work->unk_00->unk_35A) {
    case 1:
        work->unk_35 = 5;
        break;
    case 2:
        work->unk_35 = 7;
        break;
    case 0:
    default:
        work->unk_35 = 3;
        break;
    }
}

INCLUDE_ASM("bos2/task_bos_dsd_energy2_1.s");

void task_bos_dsd_energy2_2(DsdEnergy2Work* work) {
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_3C == 1) {
        if (work->unk_0C >= 0 && gUnk_02039B84->unk_024 == 0x100) {
            affine = 0;
        } else {
            scale = 0x200 - -work->unk_0C / 128;

            if (scale <= 0x7F) {
                scale = 0x80;
            }

            flag = 0;

            if (scale > 0x100) {
                flag = 1;
            }

            affine = AllocObjAffine(0, scale, scale, flag);
        }

        WorldToScreen(&x, &y, work->unk_04 + 0x100, work->unk_08, 0);
        DrawSprite(x, y, work->unk_38, work->unk_00->unk_374, work->unk_00->unk_378, affine, 0xC00, 0xFFF0);
    }
}

void task_bos_dsd_energy2_3(void) {
}

ALIGN_ZERO(2);
