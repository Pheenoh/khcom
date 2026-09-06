#include "macros.h"
#include "bos2.h"

s16 gUnk_0203ACC0 COMMON;
s16 gUnk_0203ACC4 COMMON;
s16 gUnk_0203ACC8 COMMON;
s16 gUnk_0203ACCC COMMON;
s8 gUnk_0203ACD0 COMMON;
s16 gUnk_0203ACD4 COMMON;
void* gUnk_0203ACD8;
u32 gUnk_0203ACDC;
u8 gUnk_0203ACE0[0x800];
s16 gUnk_0203B4E0 COMMON;
s16 gUnk_0203B4E4 COMMON;
s32 gUnk_0203B4E8;
u32 gUnk_0203B4EC;
void* gUnk_0203B4F0[4];
void* gUnk_0203B500;
u8 gUnk_0203B504[12];
u8 gUnk_0203B510[0x800];

void task_bos_tm_body_0(TmBodyWork* work, TmWork* arg) {
    work->tiles = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->unk_008 = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->unk_00C = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_124 = gUnk_09EF3950;
    work->unk_240 = gUnk_09EF3958;
    work->unk_35C = gUnk_09EF397C;
    work->unk_478 = gUnk_09EF3960;
    work->unk_000 = arg;
    work->unk_000->unk_40 = ((u16*)work->tiles)[3];
    work->unk_000->unk_42 += ((u16*)work->tiles)[4];
    work->unk_000->unk_44 = ((u16*)work->unk_008)[3];
    work->unk_480 = 0;
    work->unk_482 = 0;
    work->unk_484 = 0;
    work->unk_486 = 0;
    work->unk_128 = 0;
    work->unk_244 = 0;
    work->unk_360 = 0;
    work->unk_47C = 0;
    work->unk_488 = 0;
    work->unk_48A = 1300;
    work->unk_48C = 1300;
    work->unk_48E = 0;
    work->unk_490 = 10;
    work->unk_492 = 0;

    if (work->unk_000->unk_28 & 8) {
        func_080B83A4(work->unk_010, work->unk_000->unk_00 + 4, work->unk_000->unk_02,
                      work->unk_000->unk_04 - 34);
        func_080B83A4(work->unk_12C, work->unk_000->unk_00, work->unk_000->unk_02,
                      work->unk_000->unk_04 + 9);
        func_080B83A4(work->unk_248, work->unk_000->unk_00 + 12, work->unk_000->unk_02 + 1,
                      work->unk_000->unk_04 - 33);
        func_080B83A4(work->unk_364, work->unk_000->unk_00 - 1, work->unk_000->unk_02 - 4,
                      work->unk_000->unk_04 - 30);
    } else {
        func_080B83A4(work->unk_010, work->unk_000->unk_00 + 4, work->unk_000->unk_02,
                      work->unk_000->unk_04 - 34);
        func_080B8334(work->unk_12C, work->unk_000->unk_00, work->unk_000->unk_02,
                      work->unk_000->unk_04 - 16);
        func_080B83A4(work->unk_248, work->unk_000->unk_00 + 12, work->unk_000->unk_02 + 1,
                      work->unk_000->unk_04 - 33);
        func_080B83A4(work->unk_364, work->unk_000->unk_00 - 1, work->unk_000->unk_02 - 4,
                      work->unk_000->unk_04 - 30);
        memcpy(gUnk_0203AB50, work->unk_12C, 272);
    }
}
INCLUDE_ASM("bos2/task_bos_tm_body_1.s");
INCLUDE_ASM("bos2/task_bos_tm_body_2.s");

void task_bos_tm_body_3(TmBodyWork* work) {
    if ((work->unk_000->unk_28 & 8) == 0) {
        func_080B83B8(work->unk_12C);
    }

    ReleaseObjTiles(work->tiles);
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

#ifdef NON_MATCHING
void func_080BA08C(BosSub* work, s16 x, s16 y, s16 z, u16 a, u16 b, s32 c, s16 d) {
    work->x = x << 8;
    work->y = y << 8;
    work->z = z << 8;

    if (d >= 6 && d <= 7) {
        func_080122AC(&work->unk_040, 8, a, b);
        func_08012324(&work->unk_040, work->x, work->y, work->z);
    }
}
#else
INCLUDE_ASM("bos2/func_080BA08C.s");
#endif

void func_080BA0E4(s32* p, s32 a, s32 b, s32 c) {
    p[1] = (s16)a << 8;
    p[2] = (s16)b << 8;
    p[3] = (s16)c << 8;
}

void func_080BA0F8(u8* work) {
    func_08012304(work + 0x40);
}

void func_080BA104(BosSub* work) {
    func_08012324(&work->unk_040, work->x, work->y, work->z);
}

void func_080BA11C(TmFootWork* work) {
    work->unk_002 = 0;
    work->unk_000 = 0;
    func_08002A10(work->unk_00C, gUnk_09654C04);
    func_08002A10(work->unk_010, gUnk_09654C04);
    work->unk_12C = gUnk_09EF39DC[2];
    work->unk_244 = gUnk_09EF39DC[2];

    if (work->unk_47C->unk_28 & 0x20) {
        work->unk_020 = work->unk_47C->unk_08 + 0x100;
        work->unk_138 = work->unk_47C->unk_08 - 0x600;
        work->unk_250 = work->unk_47C->unk_08 + 0x600;
        work->unk_368 = work->unk_47C->unk_08 - 0x200;
        work->unk_024 = work->unk_47C->unk_0C + 0x200;
        work->unk_13C = work->unk_47C->unk_0C - 0x200;
        work->unk_254 = work->unk_47C->unk_0C + 0x500;
        work->unk_36C = work->unk_47C->unk_0C - 0x200;
        work->unk_028 = work->unk_47C->unk_10 - 0x400;
        work->unk_140 = work->unk_47C->unk_10 - 0x400;
        work->unk_258 = work->unk_47C->unk_10 + 0x2800;
        work->unk_370 = work->unk_47C->unk_10 + 0x2B00;
    } else {
        work->unk_020 = work->unk_47C->unk_08 + 0x600;
        work->unk_138 = work->unk_47C->unk_08 - 0x100;
        work->unk_250 = work->unk_47C->unk_08 + 0x200;
        work->unk_368 = work->unk_47C->unk_08 - 0x600;
        work->unk_024 = work->unk_47C->unk_0C - 0x200;
        work->unk_13C = work->unk_47C->unk_0C + 0x200;
        work->unk_254 = work->unk_47C->unk_0C - 0x500;
        work->unk_36C = work->unk_47C->unk_0C + 0x200;
        work->unk_028 = work->unk_47C->unk_10 - 0x400;
        work->unk_140 = work->unk_47C->unk_10 - 0x400;
        work->unk_258 = work->unk_47C->unk_10 + 0x2800;
        work->unk_370 = work->unk_47C->unk_10 + 0x2B00;
    }
}
void func_080BA2B0(TmFootWork* work) {
    func_08002A10(work->unk_00C, gUnk_09654C04);
    func_08002A10(work->unk_010, gUnk_09654C04);
    work->unk_12C = gUnk_09EF39DC[0];
    work->unk_244 = gUnk_09EF39DC[0];

    if (work->unk_47C->unk_28 & 0x20) {
        work->unk_020 = work->unk_47C->unk_08 + 0x100;
        work->unk_138 = work->unk_47C->unk_08 - 0x600;
        work->unk_250 = work->unk_47C->unk_08 + 0x600;
        work->unk_368 = work->unk_47C->unk_08 - 0x200;
        work->unk_024 = work->unk_47C->unk_18 + 0x200;
        work->unk_13C = work->unk_47C->unk_18 - 0x200;
        work->unk_254 = work->unk_47C->unk_18 + 0x500;
        work->unk_36C = work->unk_47C->unk_18 - 0x200;
        work->unk_028 = work->unk_47C->unk_1C - 0x400;
        work->unk_140 = work->unk_47C->unk_1C - 0x400;
        work->unk_258 = work->unk_47C->unk_1C + 0x1900;
        work->unk_370 = work->unk_47C->unk_1C + 0x1C00;
    } else {
        work->unk_020 = work->unk_47C->unk_08 + 0x600;
        work->unk_138 = work->unk_47C->unk_08 - 0x100;
        work->unk_250 = work->unk_47C->unk_08 + 0x200;
        work->unk_368 = work->unk_47C->unk_08 - 0x600;
        work->unk_024 = work->unk_47C->unk_18 - 0x200;
        work->unk_13C = work->unk_47C->unk_18 + 0x200;
        work->unk_254 = work->unk_47C->unk_18 - 0x500;
        work->unk_36C = work->unk_47C->unk_18 + 0x200;
        work->unk_028 = work->unk_47C->unk_1C - 0x400;
        work->unk_140 = work->unk_47C->unk_1C - 0x400;
        work->unk_258 = work->unk_47C->unk_1C + 0x1900;
        work->unk_370 = work->unk_47C->unk_1C + 0x1C00;
    }
}

void func_080BA43C(TmFootWork* work, s16 a) {
    work->unk_12C = gUnk_09EF39DC[gUnk_09EF2244[a].unk_06];
    work->unk_244 = gUnk_09EF39DC[gUnk_09EF2244[a].unk_0E];
    work->unk_028 += gUnk_09EF2244[a].unk_02 << 8;
    work->unk_140 += gUnk_09EF2244[a].unk_0A << 8;
}

void func_080BA49C(TmFootWork* work) {
    work->unk_002 = 0;
    work->unk_000 = 0;
    func_08002A10(work->unk_00C, gUnk_09658C04);
    func_08002A10(work->unk_010, gUnk_09658C04);
    work->unk_12C = gUnk_09EF3A1C[6];
    work->unk_244 = gUnk_09EF3A1C[1];

    if (work->unk_47C->unk_28 & 0x20) {
        work->unk_020 = work->unk_47C->unk_14 + 0x500;
        work->unk_138 = work->unk_47C->unk_14 - 0x600;
        work->unk_250 = work->unk_47C->unk_14 + 0x600;
        work->unk_368 = work->unk_47C->unk_14 - 0x200;
        work->unk_024 = work->unk_47C->unk_18 + 0x200;
        work->unk_13C = work->unk_47C->unk_18 - 0x200;
        work->unk_254 = work->unk_47C->unk_18 + 0x500;
        work->unk_36C = work->unk_47C->unk_18 - 0x200;
        work->unk_028 = work->unk_47C->unk_1C - 0x400;
        work->unk_140 = work->unk_47C->unk_1C - 0x400;
        work->unk_258 = work->unk_47C->unk_1C + 0x1E00;
        work->unk_370 = work->unk_47C->unk_1C + 0x3200;
    } else {
        work->unk_020 = work->unk_47C->unk_14 + 0x200;
        work->unk_138 = work->unk_47C->unk_14 - 0x100;
        work->unk_250 = work->unk_47C->unk_14 + 0x200;
        work->unk_368 = work->unk_47C->unk_14 - 0x600;
        work->unk_024 = work->unk_47C->unk_18 - 0x200;
        work->unk_13C = work->unk_47C->unk_18 + 0x200;
        work->unk_254 = work->unk_47C->unk_18 - 0x500;
        work->unk_36C = work->unk_47C->unk_18 + 0x200;
        work->unk_028 = work->unk_47C->unk_1C - 0x400;
        work->unk_140 = work->unk_47C->unk_1C - 0x400;
        work->unk_258 = work->unk_47C->unk_1C + 0x1E00;
        work->unk_370 = work->unk_47C->unk_1C + 0x3200;
    }
}
void func_080BA62C(TmFootWork* work) {
    if (work->unk_47C->unk_36 != 0) {
        return;
    }

    work->unk_12C = gUnk_09EF3A1C[gUnk_09EF2464[work->unk_47C->unk_34].unk_06];
    work->unk_244 = gUnk_09EF3A1C[gUnk_09EF2464[work->unk_47C->unk_34].unk_0E];

    if (work->unk_47C->unk_28 & 0x20) {
        work->unk_250 = work->unk_47C->unk_14 + ((gUnk_09EF2464[work->unk_47C->unk_34].unk_10 + 6) << 8);
        work->unk_368 = work->unk_47C->unk_14 + ((gUnk_09EF2464[work->unk_47C->unk_34].unk_18 - 2) << 8);
        work->unk_020 = work->unk_47C->unk_14 + 0x100;
        work->unk_138 = work->unk_47C->unk_14 - 0x600;
        work->unk_254 = work->unk_47C->unk_18 + 0x500;
        work->unk_36C = work->unk_47C->unk_18 - 0x200;
        work->unk_024 = work->unk_47C->unk_18 + 0x200;
        work->unk_13C = work->unk_47C->unk_18 - 0x200;
        work->unk_258 = work->unk_47C->unk_1C + ((gUnk_09EF2464[work->unk_47C->unk_34].unk_12 + 40) << 8);
        work->unk_370 = work->unk_47C->unk_1C + ((gUnk_09EF2464[work->unk_47C->unk_34].unk_1A + 43) << 8);
        work->unk_028 = work->unk_47C->unk_1C - 0x400;
        work->unk_140 = work->unk_47C->unk_1C - 0x400;
    } else {
        work->unk_250 = work->unk_47C->unk_14 + ((2 - gUnk_09EF2464[work->unk_47C->unk_34].unk_10) << 8);
        work->unk_368 = work->unk_47C->unk_14 + ((-6 - gUnk_09EF2464[work->unk_47C->unk_34].unk_18) << 8);
        work->unk_020 = work->unk_47C->unk_14 + 0x600;
        work->unk_138 = work->unk_47C->unk_14 - 0x100;
        work->unk_254 = work->unk_47C->unk_18 - 0x500;
        work->unk_36C = work->unk_47C->unk_18 + 0x200;
        work->unk_024 = work->unk_47C->unk_18 - 0x200;
        work->unk_13C = work->unk_47C->unk_18 + 0x200;
        work->unk_258 = work->unk_47C->unk_1C + ((gUnk_09EF2464[work->unk_47C->unk_34].unk_12 + 40) << 8);
        work->unk_370 = work->unk_47C->unk_1C + ((gUnk_09EF2464[work->unk_47C->unk_34].unk_1A + 43) << 8);
        work->unk_028 = work->unk_47C->unk_1C - 0x400;
        work->unk_140 = work->unk_47C->unk_1C - 0x400;
    }

    if (work->unk_47C->unk_34 == 2) {
        if (func_08011F78(239, work->unk_250, work->unk_254 - 0x500, 0, 20, 16, 20) == 1) {
            m4aSongNumStart(0x248);
        }
    }

    if (work->unk_47C->unk_34 == 7) {
        if (func_08011F78(239, work->unk_368, work->unk_36C - 0x500, 0, 20, 16, 20) == 1) {
            m4aSongNumStart(0x248);
        }
    }
}

void func_080BA8C8(TmFootWork* work, s16 a) {
    work->unk_12C = gUnk_09EF39DC[gUnk_09EF25A4[a].unk_06];
    work->unk_244 = gUnk_09EF39DC[gUnk_09EF25A4[a].unk_0E];
    work->unk_028 += gUnk_09EF25A4[a].unk_02 << 8;
    work->unk_140 += gUnk_09EF25A4[a].unk_0A << 8;
}

INCLUDE_ASM("bos2/task_bos_tm_foot_0.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_1.s");
#ifdef NON_MATCHING
void task_bos_tm_foot_2(TmFootWork* work) {
    void* pal;
    u16 mode;
    s16 x;
    s16 y;
    TmFootSub* s0;
    TmFootSub* s1;
    TmFootSub* s2;
    TmFootSub* s3;

    mode = 0x801;

    if (work->unk_47C->unk_28 & 0x20) {
        mode = 0x800;
    }

    if (gBtlWork->unk_070 != 0) {
        pal = work->unk_014;
    } else if (work->unk_47C->unk_28 & 1) {
        if (gFrameCounter & 1) {
            pal = work->unk_018;
        } else {
            pal = work->unk_014;
        }
    } else {
        pal = work->unk_014;
    }

    s0 = (TmFootSub*)&work->unk_01C;
    s1 = s0 + 1;
    s2 = s0 + 2;
    s3 = s0 + 3;
    WorldToScreen(&x, &y, s0->x, s0->y, s0->z);
    DrawSprite(x, y, s0->gfx, work->unk_00C, pal, 0, mode, (u16)(-4100 - (s0->y >> 8) * 4));
    WorldToScreen(&x, &y, s1->x, s1->y, s1->z);
    DrawSprite(x, y, s1->gfx, work->unk_010, pal, 0, mode, (u16)(-4100 - (s1->y >> 8) * 4));
    WorldToScreen(&x, &y, s2->x, s2->y, s2->z);
    DrawSprite(x, y, s2->gfx, work->tiles, pal, 0, mode, (u16)(-4100 - (s2->y >> 8) * 4));
    WorldToScreen(&x, &y, s3->x, s3->y, s3->z);
    DrawSprite(x, y, s3->gfx, work->tiles, pal, 0, mode, (u16)(-4100 - (s3->y >> 8) * 4));
}
#else
INCLUDE_ASM("bos2/task_bos_tm_foot_2.s");
#endif

void task_bos_tm_foot_3(TmFootWork* work) {
    if ((*(u16*)((u8*)*(void**)((u8*)work + 0x47C) + 40) & 8) == 0) {
        func_080BA0F8((u8*)work + 0x24C);
        func_080BA0F8((u8*)work + 0x364);
    }

    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->unk_014);
    ReleaseObjPalette((void*)work->unk_018);
}

void func_080BB1B8(void* pool, TmClbArg* p, TmClbSrc* a) {
    p->unk_08 = a;
    p->unk_00 = 0;
    p->unk_04 = 1;
    p->unk_0C = 0;
    TaskCreate(pool, gTaskDescBosTmClb, p);
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

    work->tiles = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->palette = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->unk_000 = arg;
    p = ((void**)arg)[2];
    work->unk_00C = *(u16*)((u8*)p + 12);
    work->x = *(s32*)p;
    work->y = *(s32*)((u8*)p + 4);
    work->z = *(s32*)((u8*)p + 8);
}

u8 task_bos_tm_clb_1(TmClbWork* work) {
    TmClbArg* a = work->unk_000;

    switch (a->unk_00) {
    case 4:
        work->x += (a->unk_08->unk_00 - work->x) >> 4;
        work->y = a->unk_08->unk_04;
        work->z += a->unk_0C;
        a->unk_0C += 51;

        if (a->unk_0C > 0 && work->z >= a->unk_08->unk_08) {
            work->z = a->unk_08->unk_08;
            a->unk_00 = 0;
            a->unk_04 = 1;
        }

        break;
    case 0:
        work->x = a->unk_08->unk_00;
        work->y = a->unk_08->unk_04;
        work->z = a->unk_08->unk_08;
        break;
    case 1:
        work->x = a->unk_08->unk_00;
        work->y = a->unk_08->unk_04;
        work->z = a->unk_08->unk_08;
        break;
    case 2:
        work->x = a->unk_08->unk_00 - 0x600;
        work->y = a->unk_08->unk_04;
        work->z = a->unk_08->unk_08;
        break;
    case 3:
        work->x = a->unk_08->unk_00 + 0x600;
        work->y = a->unk_08->unk_04;
        work->z = a->unk_08->unk_08 - 0x500;
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

    p = AllocObjAffineAngle(work->unk_00C, 0);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gUnk_0962E838, work->tiles, work->palette, (s32)p, 0x800,
               (u16)(-0x1002 - (work->y >> 8) * 4));
    p[0x0A] = 1;
    DrawSprite(x, y, work->unk_000->unk_14, work->unk_000->unk_10, work->palette, (s32)p, 0x800,
               (u16)(-0x1003 - (work->y >> 8) * 4));
}

void task_bos_tm_clb_3(TmClbWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
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

#ifdef NON_MATCHING
void func_080BB518(TmArmJoint* joints) {
    s32 x;
    s32 y;
    u32 i;

    x = 0;
    y = 0;


    for (i = 0; i < 3; i++) {
        joints[i].unk_0C = x;
        joints[i].unk_10 = y;
        x += gSineTable[joints[i].unk_08] * gUnk_0961A63C[joints[i].unk_26];
        y += -gSineTable[joints[i].unk_08 + 0x40] * gUnk_0961A63C[joints[i].unk_26];
    }

    joints[3].unk_0C = x;
    joints[3].unk_10 = y;
}
#else
INCLUDE_ASM("bos2/func_080BB518.s");
#endif
#ifdef NON_MATCHING
void func_080BB588(u8* joints, u16 a) {
    s32 i;

    for (i = 0; i < 4; i++) {
        u8* p = joints + i * 0x34;
        u8* q = p + 8;

        ApproachAngle(q, *(u16*)(q + 12), a);
    }

    func_080BB518(joints);

    for (i = 0; i < 4; i++) {
        u8* p = joints + i * 0x34;

        *(s32*)p += (*(s32*)(p + 12) - *(s32*)p) >> 1;
        *(s32*)(p + 4) += (*(s32*)(p + 16) - *(s32*)(p + 4)) >> 1;
    }
}
#else
INCLUDE_ASM("bos2/func_080BB588.s");
#endif

void func_080BB5E8(u8* joints, TmAnim* a) {
    if (a->unk_00 >= a->unk_08[a->unk_02].unk_00) {
        a->unk_00 = 0;
        a->unk_02++;

        if (a->unk_02 >= a->unk_04) {
            a->unk_02 = 0;
        }

        func_080BB428(joints, a->unk_08[a->unk_02].unk_04);
    }

    a->unk_00++;
    func_080BB588(joints, 1);
}

INCLUDE_ASM("bos2/task_bos_tm_arm_0.s");
#ifdef NON_MATCHING
void func_080BB924(TmArmWork* work) {
    TmArmJoint* j;
    TmArmJoint* j2;
    s32 i;
    s32 r;
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    u8 v;

    switch (work->unk_00C->unk_18->unk_2C) {
    case 0:
    case 15:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 0x110;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x84], 3, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0xFC], 3, (u8*)&work->unk_010[4]);
            }
        }

        switch (work->unk_1B0 % 30) {
        case 0:
            v = 0;

            if (work->unk_230 == 0) {
                v = 1;
            }

            work->unk_230 = v;
            break;
        case 22:
            if (work->unk_230 != 0) {
                func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0x380);
            } else {
                func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[0], -0x380);
            }
            break;
        }

        work->unk_1B0++;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 0x110;
            func_080BB1E8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0]);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x638], 6, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x728], 6, (u8*)&work->unk_010[4]);
            }
        }

        work->unk_1B0++;
        break;
    case 12:
    case 14:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 90;
            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -128);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x14C], 1, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x174], 1, (u8*)&work->unk_010[4]);
            }
        }

        work->unk_1B0++;
        break;
    case 13:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 90;
            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -128);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x14C], 1, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x174], 1, (u8*)&work->unk_010[4]);
            }
        }

        work->unk_1B0++;
        break;
    case 1:
        if (work->unk_1B0 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x188], 3, (u8*)&work->unk_010[4]);
                work->unk_1F8[0].unk_0C = 0xE8;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 0);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x200], 3, (u8*)&work->unk_010[4]);
                work->unk_1F8[0].unk_0C = 0xF4;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 2);
            }
        }

        if (work->unk_1B0 == 45) {
            j = &work->unk_010[3];
            y = work->unk_00C->unk_10;
            z = work->unk_00C->unk_14 + j->unk_04 - 0x2300;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                x = work->unk_00C->unk_0C + j->unk_00 - 0x3E00;
                func_08012F74(x, y, z, 1, 0, 168, 20);
            } else {
                x = work->unk_00C->unk_0C + j->unk_00 + 0x4800;
                func_08012F74(x, y, z, 0, 0, 168, 20);
            }
        } else if (work->unk_1B0 > 55) {
            if (func_080128EC() == 0) {
                work->unk_1F8[0].unk_0C = 0x110;
                work->unk_00C->unk_18->unk_28 |= 2;
            }
        }

        work->unk_1B0++;
        break;
    case 10:
        if (work->unk_1B0 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x188], 3, (u8*)&work->unk_010[4]);
                work->unk_1F8[0].unk_0C = 0xE8;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 0);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x200], 3, (u8*)&work->unk_010[4]);
                work->unk_1F8[0].unk_0C = 0xF4;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 2);
            }
        }

        if (work->unk_1B0 == 30) {
            j = &work->unk_010[3];
            y = work->unk_00C->unk_10;
            z = work->unk_00C->unk_14 + j->unk_04 - 0x2300;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                x = work->unk_00C->unk_0C + j->unk_00 - 0x3E00;
                func_08012F74(x, y, z, 1, 0, 168, 18);
            } else {
                x = work->unk_00C->unk_0C + j->unk_00 + 0x4800;
                func_08012F74(x, y, z, 0, 0, 168, 18);
            }
        } else if (work->unk_1B0 > 70) {
            if (func_080128EC() == 0) {
                work->unk_1F8[0].unk_0C = 0x110;
                work->unk_00C->unk_18->unk_28 |= 2;
            }
        } else if (work->unk_1B0 > 50) {
            if (func_080128EC() == 0) {
                j2 = &work->unk_010[3];
                y2 = work->unk_00C->unk_10;
                z2 = work->unk_00C->unk_14 + j2->unk_04 - 0x2300;

                if (work->unk_00C->unk_18->unk_28 & 0x20) {
                    x2 = work->unk_00C->unk_0C + j2->unk_00 - 0x3E00;
                    func_08012F74(x2, y2, z2, 1, 0, 168, 18);
                } else {
                    x2 = work->unk_00C->unk_0C + j2->unk_00 + 0x4800;
                    func_08012F74(x2, y2, z2, 0, 0, 168, 18);
                }
            }
        }

        work->unk_1B0++;
        break;
    case 2:
        if (work->unk_1B0 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x278], 6, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x368], 6, (u8*)&work->unk_010[4]);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0xB00);
            work->unk_1F8[0].unk_0C = 0xE8;
        }

        if (work->unk_1B0 == 35) {
            work->unk_1F8[0].unk_0C = 0x110;
            work->unk_00C->unk_18->unk_3A = 1;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                r = func_08011F78(237, work->unk_1F8[1].unk_00 - 0x1000, work->unk_1F8[1].unk_04,
                                  work->unk_1F8[1].unk_08 + 0x1400, 16, 16, 16);
            } else {
                r = func_08011F78(237, work->unk_1F8[1].unk_00 + 0x2800, work->unk_1F8[1].unk_04,
                                  work->unk_1F8[1].unk_08 + 0x1400, 16, 16, 16);
            }

            if (r == 1) {
                m4aSongNumStart(0x248);
            }

            m4aSongNumStart(0x210);
        }

        if (work->unk_1B0 > 50) {
            work->unk_00C->unk_18->unk_28 |= 2;
        } else {
            work->unk_1B0++;
        }
        break;
    case 3:
        if (work->unk_1B0 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x278], 6, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x368], 6, (u8*)&work->unk_010[4]);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0xB00);
            work->unk_1F8[0].unk_0C = 0xE8;
        }

        if (work->unk_1B0 == 35) {
            work->unk_1F8[0].unk_0C = 0x110;
        }

        if (work->unk_1B0 == 37) {
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080147D8(0x10D00, 0x15800);
            } else {
                func_080147D8(0xF000, 0x15800);
            }

            func_0802F1E8();
            m4aSongNumStart(0x210);
            func_08011F78(238, gBtlWork->unk_000, gBtlWork->unk_004, 0, 320, 240, 1);
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;
        }

        if (work->unk_1B0 > 50) {
            work->unk_00C->unk_18->unk_28 |= 2;
        } else {
            work->unk_1B0++;
        }
        break;
    case 11:
        if (work->unk_1B0 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x458], 6, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x548], 6, (u8*)&work->unk_010[4]);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0xB00);
            work->unk_1F8[0].unk_0C = 0xE8;
        }

        if (work->unk_1B0 == 50) {
            work->unk_1F8[0].unk_0C = 0x110;
        }

        if (work->unk_1B0 == 52) {
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080147D8(0x10D00, 0x15800);
            } else {
                func_080147D8(0xF000, 0x15800);
            }

            func_0802F1E8();
            m4aSongNumStart(0x210);
            func_08011F78(238, gBtlWork->unk_000, gBtlWork->unk_004, 0, 320, 240, 1);
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;
        }

        if (work->unk_1B0 > 65) {
            work->unk_00C->unk_18->unk_28 |= 2;
        } else {
            work->unk_1B0++;
        }
        break;
    case 9:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 0x10C;
            func_080BB1E8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0]);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x818], 5, (u8*)&work->unk_010[4]);
            } else {
                func_080BB43C((u8*)work + 0x218, &gUnk_09619C94[0x8E0], 5, (u8*)&work->unk_010[4]);
            }
        }

        if (work->unk_1B0 == 21) {
            if (func_08011F78(240, work->unk_00C->unk_18->unk_08, work->unk_00C->unk_18->unk_0C,
                              work->unk_1F8[1].unk_08, 36, 32, 32) == 1) {
                m4aSongNumStart(0x248);
            }
        }

        if (work->unk_1B0 > 33) {
            work->unk_00C->unk_18->unk_28 |= 2;
        } else {
            work->unk_1B0++;
        }

        gUnk_0203AC74 = work->unk_1B0;
        break;
    case 17:
        return;
    }

    func_080BB5E8((u8*)&work->unk_010[4], (TmAnim*)((u8*)work + 0x218));
    func_080BB464(work);

    for (i = 0; i < 3; i++) {
        work->unk_010[i + 4].unk_30 = AnimUpdate((AnimState*)((u8*)&work->unk_010[i + 4] + 0x18));
    }
}
#else
INCLUDE_ASM("bos2/func_080BB924.s");
#endif

void func_080BC304(TmArmWork* work) {
    s32 i;

    switch (work->unk_00C->unk_18->unk_2C) {
    case 0:
    case 15:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 0x110;

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x48], 3, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0xC0], 3, (u8*)work->unk_010);
            }
        }

        if (work->unk_1B2 % 30 == 12) {
            if (work->unk_230 != 0) {
                func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0x600);
            } else {
                func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[1], -0x600);
            }
        }

        work->unk_1B2++;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 0x110;
            func_080BB1E8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1]);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x6B0], 6, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x7A0], 6, (u8*)work->unk_010);
            }
        }

        work->unk_1B2++;
        break;
    case 12:
    case 14:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 185;
            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -128);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x138], 1, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x160], 1, (u8*)work->unk_010);
            }
        }

        work->unk_1B2++;
        break;
    case 13:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 185;
            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -128);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x138], 1, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x160], 1, (u8*)work->unk_010);
            }
        }

        work->unk_1B2++;
        break;
    case 1:
        if (work->unk_1B2 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x1C4], 3, (u8*)work->unk_010);
                work->unk_1F8[1].unk_0C = 0x10C;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 1);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x23C], 3, (u8*)work->unk_010);
                work->unk_1F8[1].unk_0C = 0x118;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 3);
            }
        }

        if (work->unk_1B2 > 55) {
            if (func_080128EC() == 0) {
                work->unk_1F8[1].unk_0C = 240;
            }
        }

        work->unk_1B2++;
        break;
    case 10:
        if (work->unk_1B2 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x1C4], 3, (u8*)work->unk_010);
                work->unk_1F8[1].unk_0C = 0x10C;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 1);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x23C], 3, (u8*)work->unk_010);
                work->unk_1F8[1].unk_0C = 0x118;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 3);
            }
        }

        if (work->unk_1B2 > 70) {
            if (func_080128EC() == 0) {
                work->unk_1F8[1].unk_0C = 240;
            }
        }

        work->unk_1B2++;
        break;
    case 2:
        if (work->unk_1B2 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x2F0], 6, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x3E0], 6, (u8*)work->unk_010);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0xB00);
            work->unk_1F8[1].unk_0C = 0x10C;
        }

        if (work->unk_1B2 == 35) {
            work->unk_1F8[1].unk_0C = 240;
        }

        work->unk_1B2++;
        break;
    case 3:
        if (work->unk_1B2 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x2F0], 6, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x3E0], 6, (u8*)work->unk_010);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0xB00);
            work->unk_1F8[1].unk_0C = 0x10C;
        }

        if (work->unk_1B2 == 35) {
            work->unk_1F8[1].unk_0C = 240;
        }

        work->unk_1B2++;
        break;
    case 11:
        if (work->unk_1B2 == 0) {
            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x4D0], 6, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x5C0], 6, (u8*)work->unk_010);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0xB00);
            work->unk_1F8[1].unk_0C = 0x10C;
        }

        if (work->unk_1B2 == 50) {
            work->unk_1F8[1].unk_0C = 240;
        }

        work->unk_1B2++;
        break;
    case 9:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 0x110;
            func_080BB1E8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1]);

            if (work->unk_00C->unk_18->unk_28 & 0x20) {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x87C], 5, (u8*)work->unk_010);
            } else {
                func_080BB43C((u8*)work + 0x224, &gUnk_09619C94[0x944], 5, (u8*)work->unk_010);
            }
        }

        work->unk_1B2++;
        break;
    case 17:
        return;
    }

    func_080BB5E8((u8*)work->unk_010, (TmAnim*)((u8*)work + 0x224));
    func_080BB4C0(work);

    for (i = 0; i < 3; i++) {
        work->unk_010[i].unk_30 = AnimUpdate((AnimState*)((u8*)&work->unk_010[i] + 0x18));
    }
}

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
        gfx = AnimUpdate(&work->anim);
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

#ifdef NON_MATCHING
void task_bos_tm_arm_2(TmArmWork* work) {
    void* pal;
    s32 mode;
    s32 affine;
    s16 x;
    s16 y;
    s32 i;
    TmArmJoint* j;

    if (gBtlWork->unk_070 != 0) {
        pal = work->unk_004;
    } else if ((work->unk_00C->unk_18->unk_28 & 1) && (gFrameCounter & 1)) {
        pal = (void*)work->unk_008;
    } else {
        pal = work->unk_004;
    }

    for (i = 0; i < 3; i++) {
        j = &work->unk_010[i + 4];
        affine = AllocObjAffine(j->unk_08, 256, 256, 0);
        WorldToScreen(&x, &y, work->unk_00C->unk_00 + j->unk_00, work->unk_00C->unk_04,
                      work->unk_00C->unk_08 + j->unk_04);
        DrawSprite(x, y, j->unk_30, (void*)work->unk_000, pal, affine, 0x800,
                   (u16)(-4100 - (work->unk_00C->unk_04 >> 8) * 4));
        j = &work->unk_010[i];
        affine = AllocObjAffine(j->unk_08, 256, 256, 0);
        WorldToScreen(&x, &y, work->unk_00C->unk_0C + j->unk_00, work->unk_00C->unk_10,
                      work->unk_00C->unk_14 + j->unk_04);
        DrawSprite(x, y, j->unk_30, (void*)work->unk_000, pal, affine, 0x800,
                   (u16)(-4100 - (work->unk_00C->unk_10 >> 8) * 4));
    }

    if (work->unk_00C->unk_18->unk_28 & 32) {
        mode = 256;
    } else {
        mode = -256;
    }

    j = &work->unk_010[7];
    affine = AllocObjAffine(j->unk_08, mode, 256, 0);
    WorldToScreen(&x, &y, work->unk_00C->unk_00 + j->unk_00, work->unk_00C->unk_04,
                  work->unk_00C->unk_08 + j->unk_04);
    DrawSprite(x, y, j->unk_30, (void*)work->unk_000, pal, affine, 0x800,
               (u16)(-4100 - (work->unk_00C->unk_04 >> 8) * 4));
    j = &work->unk_010[3];
    affine = AllocObjAffine(j->unk_08, mode, 256, 0);
    WorldToScreen(&x, &y, work->unk_00C->unk_0C + j->unk_00, work->unk_00C->unk_10,
                  work->unk_00C->unk_14 + j->unk_04);
    DrawSprite(x, y, j->unk_30, (void*)work->unk_000, pal, affine, 0x800,
               (u16)(-4100 - (work->unk_00C->unk_10 >> 8) * 4));
    TaskPoolDraw(&work->unk_1B4);
}
#else
INCLUDE_ASM("bos2/task_bos_tm_arm_2.s");
#endif

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
    work->unk_000 = arg;
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

void task_bos_jf_0(JfWork* work, s32 a) {
    BosSub* sub;
    BtlWork* q;
    s32 v1;
    s32 v2;

    gUnk_0203AC80 = 0;
    gUnk_0203ACB0 = 0;
    gUnk_0203ACB4 = 0;
    work->unk_24C = 0;

    if (a != 0) {
        work->unk_24C = 8;
    }

    gUnk_0203ACC4 = 7;
    gUnk_0203ACD4 = 0;
    gUnk_0203ACC0 = 0;
    gUnk_0203AC90.unk_00 = gUnk_0965DC04;
    gUnk_0203AC90.unk_04 = 0x8000;
    gUnk_0203AC90.unk_08 = gUnk_096FB404;
    gUnk_0203AC90.unk_0C = 128;
    gUnk_0203AC90.unk_10[0] = gUnk_096C4C64;
    gUnk_0203AC90.unk_10[1] = gUnk_096C5464;
    gUnk_0203AC90.unk_10[2] = gUnk_0203ACE0;
    gUnk_0203AC90.unk_10[3] = gUnk_096C6464;
    TaskPoolInit(&work->unk_254, 4);

    if (work->unk_24C & 8) {
        TaskCreate(&work->unk_254, gTaskDescBosJfMap, &gUnk_0203AC90);
    } else {
        TaskCreate((u8*)gBtlWork + 0x40, gTaskDescBosJfMap, &gUnk_0203AC90);
    }

    work->unk_268 = 0;
    work->unk_26A = 0;
    v1 = work->unk_24C & 8;

    if (v1 != 0) {
        work->unk_238 = 10;
        work->unk_23C = 10;
    } else {
        work->unk_238 = 0;
        work->unk_23C = 0;
    }

    work->unk_240 = 0;
    work->unk_242 = 0;
    work->unk_244 = 0;
    work->unk_246 = 0;
    work->unk_248 = 8;
    work->unk_24A = 12;
    work->unk_24E = 0;
    work->unk_250 = 0;
    v2 = work->unk_24C & 8;

    if (v2 != 0) {
        work->unk_22C = 0x2A200;
        work->unk_230 = 0x15E00;
        work->unk_234 = -0x3800;
        func_0801B37C(work, gUnk_0961A668, work->unk_22C, work->unk_230, work->unk_234);
        work->unk_034 |= 4;
        TaskCreate(&work->unk_254, gTaskDescBosJfMajin, work);
    } else {
        work->unk_220 = 0x29600;
        work->unk_224 = 0x15400;
        work->unk_228 = -0xB400;
        sub = (BosSub*)&work->unk_110;
        func_0801B37C(sub, gUnk_0961A668, work->unk_220, work->unk_224, work->unk_228);
        sub->unk_034 |= 0x400;
        sub->unk_034 |= 0x200000000000;
        sub->unk_034 &= ~4;
        sub->unk_024 = v2;
        work->unk_1B2 = 4;
        work->unk_22C = 0x2A200;
        work->unk_230 = 0x15E00;
        work->unk_234 = -0x3800;
        func_0801B37C(work, gUnk_0961A668, work->unk_22C, work->unk_230, work->unk_234);
        work->unk_034 |= 4;
        work->unk_034 |= 0x8000;
        work->unk_034 |= 0x100000000;
        work->unk_09E = 32;
        work->unk_0A0 = 40;
        work->unk_09C = 28;
        func_0801BDD4(work, sub);
        gBtlWork->unk_0D8 = 0xFF00;
        func_0801C298(0, 1);
        func_0801BCC0(0x23E00, 0x16800, -0x4000);
        func_0801C274(0x20600, 0x16800, -0x800);
        TaskCreate(&work->unk_254, gTaskDescBosJfLamp, work);
        TaskCreate(&work->unk_254, gTaskDescBosJfMajin, work);
        q = gBtlWork;
        *(s32*)&q->unk_0CC = sub->x;
        *(s32*)&q->unk_0D0 = sub->y;
        *(s32*)&q->unk_0D4 = sub->z;
    }
}
u8 task_bos_jf_1(JfWork* work) {
    BosSub* sub = (BosSub*)&work->unk_110;
    BtlWork* q;
    u16 t;

    if (work->unk_24C & 8) {
        TaskPoolUpdate(&work->unk_254);
        return 1;
    }

    switch (func_0801ADAC(sub)) {
    case 5:
        work->unk_238 = work->unk_23C;
        work->unk_244 = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->unk_24C |= 1;
        work->unk_242 = 20;
        break;
    case 3:
    case 8:
        work->unk_238 = 9;
        work->unk_244 = 0;
        break;
    case 4:
        if (gGameState.flags & 8) {
            if (work->unk_250 == 0) {
                if (GetRandom() % 100 <= 19) {
                    _0801C1F8(0, sub->x, sub->y, sub->z);
                }
            }
        }

        work->unk_238 = 7;
        work->unk_244 = 0;
        break;
    }

    if (work->unk_24C & 1) {
        if (--work->unk_242 <= 0) {
            work->unk_240 = 0;
            work->unk_24C &= ~1;
            LoadPaletteWithEffect(gUnk_096FB584, (void*)0x05000000, 32);
            func_0801AF08(sub);

            if (sub->unk_02C > 0) {
                if (work->unk_238 != 1 && work->unk_238 != 6 && work->unk_238 != 7 &&
                    work->unk_238 != 11) {
                    work->unk_238 = 0;
                    work->unk_244 = 0;
                }
            }
        }
    }

    if ((gGameState.flags & 8) == 0) {
        if (sub->unk_024 & 0x20000000) {
            sub->unk_024 &= ~0x20000000;

            if ((work->unk_24C & 1) == 0) {
                if (work->unk_250 == 0) {
                    _0801C1F8(0, sub->x, sub->y, sub->z);
                }
            }
        }
    }

    if (func_0801C1C0(0)) {
        work->unk_244 = 0;
        work->unk_238 = 11;
        work->unk_24C |= 4;

        if (gBtlWork->unk_068 & 0x40) {
            gBtlWork->unk_068 |= 0x400000;
        }
    }

    t = work->unk_250;

    if ((s16)t > 0) {
        work->unk_250 = t - 1;
    }

    TaskPoolUpdate(&work->unk_254);
    q = gBtlWork;
    *(s32*)&q->unk_0CC = sub->x;
    *(s32*)&q->unk_0D0 = sub->y;
    *(s32*)&q->unk_0D4 = sub->z;

    if (work->unk_24C & 2) {
        return 0;
    }

    gUnk_0203AC80 = ((BtlWork*)q->unk_07C)->unk_004 >> 8;
    gUnk_0203ACB0 = ((BtlWork*)q->unk_07C)->unk_008 >> 8;
    gUnk_0203ACB4 = ((BtlWork*)q->unk_07C)->unk_00C >> 8;
    return 1;
}

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

#ifdef NON_MATCHING
u8 func_080BD4A8(s32* p, s32 b, s32* a, s32* out) {
    s32 v1;
    s32 v2;
    s32 v3;
    s32 lo;
    s32 hi;
    s32 x;

    v1 = -((gUnk_0203ACC4 + 1) << 11);
    v2 = -((gUnk_0203ACD4 + 1) << 11);
    v3 = -((gUnk_0203ACC0 + 1) << 11);
    ((BtlWork*)gBtlWork->unk_07C)->unk_034 &= ~0x2000000;

    if (gUnk_0203ACC4 > gUnk_0203ACD4) {
        lo = 0x1F600;

        if (gUnk_0203ACD4 > gUnk_0203ACC0) {
            hi = 0x22E00;
            gUnk_0203B4E4 = 0;
            x = *p;

            if (x > hi) {
                *out = v3;
                return 0;
            }

            if (x > lo) {
                if (*a <= v2) {
                    *out = v2;

                    if (x > hi - 0x1000) {
                        goto setbit;
                    }

                    return 0;
                }

                *out = v3;
                *p = hi;
                return 1;
            } else {
                if (*a <= v1) {
                    *out = v1;

                    if (x > lo - 0x1000) {
                        goto setbit;
                    }

                    return 0;
                }

                *out = v2;
                *p = lo;
                return 1;
            }
        } else if (gUnk_0203ACD4 < gUnk_0203ACC0) {
            hi = 0x21200;
            gUnk_0203B4E4 = 1;
            x = *p;

            if (x <= lo) {
                if (*a <= v1) {
                    *out = v1;

                    if (x > lo - 0x1000) {
                        goto setbit;
                    }

                    return 0;
                }

                *out = v2;
                *p = lo;
                return 1;
            } else {
                if (x < hi) {
                    *out = v2;
                    return 0;
                }

                if (*a <= v3) {
                    *out = v3;

                    if (x < hi + 0x1000) {
                        goto setbit;
                    }

                    return 0;
                }

                *out = v2;
                *p = hi;
                return 1;
            }
        } else {
            gUnk_0203B4E4 = 2;
            x = *p;

            if (x > lo) {
                *out = v2;
                return 0;
            }

            if (*a <= v1) {
                *out = v1;

                if (x > lo - 0x1000) {
                    goto setbit;
                }

                return 0;
            }

            *out = v2;
            *p = lo;
            return 1;
        }
    } else if (gUnk_0203ACC4 < gUnk_0203ACD4) {
        lo = 0x1DA00;

        if (gUnk_0203ACD4 > gUnk_0203ACC0) {
            hi = 0x22E00;
            gUnk_0203B4E4 = 3;
            x = *p;

            if (x < lo) {
                *out = v1;
                return 0;
            }

            if (x > hi) {
                *out = v3;
                return 0;
            }

            if (*a <= v2) {
                *out = v2;

                if (x < lo + 0x1000) {
                    goto setbit;
                }

                if (x > hi - 0x1000) {
                    goto setbit;
                }

                return 0;
            }

            if (x <= 0x205FF) {
                *out = v1;
                *p = lo;
                return 1;
            }

            *out = v3;
            *p = hi;
            return 1;
        } else if (gUnk_0203ACD4 < gUnk_0203ACC0) {
            hi = 0x21200;
            gUnk_0203B4E4 = 4;
            x = *p;

            if (x < lo) {
                *out = v1;
                return 0;
            }

            if (x < hi) {
                if (*a <= v2) {
                    *out = v2;

                    if (x < lo + 0x1000) {
                        goto setbit;
                    }

                    return 0;
                }

                *out = v1;
                *p = lo;
                return 1;
            } else {
                if (*a <= v3) {
                    *out = v3;

                    if (x < hi + 0x1000) {
                        goto setbit;
                    }

                    return 0;
                }

                *out = v2;
                *p = hi;
                return 1;
            }
        } else {
            gUnk_0203B4E4 = 5;
            x = *p;

            if (x < lo) {
                *out = v1;
                return 0;
            }

            if (*a <= v2) {
                *out = v2;

                if (x < lo + 0x1000) {
                    goto setbit;
                }

                return 0;
            }

            *out = v1;
            *p = lo;
            return 1;
        }
    } else {
        if (gUnk_0203ACD4 > gUnk_0203ACC0) {
            hi = 0x22E00;
            gUnk_0203B4E4 = 6;
            x = *p;

            if (x > hi) {
                *out = v3;
                return 0;
            }

            if (*a <= v2) {
                *out = v2;

                if (x > hi - 0x1000) {
                    goto setbit;
                }

                return 0;
            }

            *out = v3;
            *p = hi;
            return 1;
        } else if (gUnk_0203ACD4 < gUnk_0203ACC0) {
            hi = 0x21200;
            gUnk_0203B4E4 = 7;
            x = *p;

            if (x < hi) {
                *out = v2;
                return 0;
            }

            if (*a <= v3) {
                *out = v3;

                if (x < hi + 0x1000) {
                    goto setbit;
                }

                return 0;
            }

            *out = v2;
            *p = hi;
            return 1;
        } else {
            gUnk_0203B4E4 = 8;
            *out = v2;
            return 0;
        }
    }

setbit:
    ((BtlWork*)gBtlWork->unk_07C)->unk_034 |= 0x2000000;
    return 0;
}
#else
INCLUDE_ASM("bos2/func_080BD4A8.s");
#endif

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
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->unk_008 = 0x23E00;
    gBtlWork->unk_00C = 0x12800;
    gBtlWork->unk_000 = 0x23E00;
    gBtlWork->unk_004 = 0x12800;
    gBtlWork->unk_010 = 0x23E00;
    gBtlWork->unk_014 = 0x12800;
    gBtlWork->unk_01C = 0x23E00;
    gBtlWork->unk_020 = 0x12800;
    gBtlWork->unk_01A = 0xF;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
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
    dx = (gBtlWork->unk_010 - gBtlWork->unk_008) >> 3;
    dy = (gBtlWork->unk_014 - gBtlWork->unk_00C) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->unk_008 += dx;
    gBtlWork->unk_00C += dy;
    gBtlWork->unk_000 = gBtlWork->unk_008;
    gBtlWork->unk_004 = gBtlWork->unk_00C;

    if (gBtlWork->unk_000 < (gBtlWork->unk_0DA + 0x14) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x14) << 8;
    } else if (gBtlWork->unk_000 > (gBtlWork->unk_0DC - 0x1C) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x1C) << 8;
    }

    if (gBtlWork->unk_004 < (gBtlWork->unk_0DE - 0x90) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0DE - 0x90) << 8;
    } else if (gBtlWork->unk_004 > (gBtlWork->unk_0E0 - 0x48) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 0x48) << 8;
    }

    gBtlWork->unk_004 += func_0802F268() + func_080BDB58();
    func_08005244(0, (gBtlWork->unk_000 >> 8) + 8, (gBtlWork->unk_004 >> 8) + 0x28);

    return 1;
}

void func_080BDAAC(void) {
    func_080C6EB0(gUnk_09EF275C[0][gUnk_0203ACC4], gUnk_0203ACE0 + 0x24c, 7, 0x17);
    func_080C6EB0(gUnk_09EF275C[1][gUnk_0203ACD4], gUnk_0203ACE0 + 0x25a, 7, 0x17);
    func_080C6EB0(gUnk_09EF275C[0][gUnk_0203ACC0], gUnk_0203ACE0 + 0x268, 7, 0x17);
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

#ifdef NON_MATCHING
void task_bos_jf_lamp_0(JfLampWork* work, JfWork* arg) {
    work->unk_00 = arg;
    work->unk_28 = 0x80;
    work->unk_04 = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->unk_08 = gUnk_09EF3A48[12];
    work->unk_0C = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->unk_10 = gUnk_09EF3A48[14];
    work->unk_14 = LoadObjPalette(gUnk_096FB5A4, 0x60);
    work->unk_18 = LoadObjPalette(gUnk_08F69BC4, 32);
    func_080062F4(*(u16*)((u8*)work->unk_14 + 6) + 16, 1);
    work->unk_2E = 0;
    work->unk_1C = 0;
    work->unk_1E = 0;
    work->unk_20 = GetRandom() % 0x79 + 0x1E0;
    work->unk_22 = 0;
    work->unk_24 = 1;
    work->unk_2D = 1;
    work->unk_32 = 0;
    work->unk_34 = 0;
    work->unk_38 = 0;
    work->unk_42 = 0;
    TaskPoolInit(&work->unk_44, 1);
    TaskCreate(&work->unk_44, gTaskDescBtlShadow, &((BosSub*)work->unk_00)[1]);
}
#else
INCLUDE_ASM("bos2/task_bos_jf_lamp_0.s");
#endif
u8 task_bos_jf_lamp_1(JfLampWork* work) {
    BosSub* sub = (BosSub*)&work->unk_00->unk_110;
    JfWork* jf = work->unk_00;
    u16* p;
    s32 d;

    if (jf->unk_238 <= 3) {
        if (++work->unk_22 > work->unk_20) {
            work->unk_22 = 0;
            m4aSongNumStart(274);
            work->unk_20 = GetRandom() % 121 + 480;
        }
    }

    if (work->unk_00->unk_238 == 9) {
        work->unk_32 = 5;
    }

    switch (work->unk_32) {
    case 0:
        if (work->unk_34 == 0) {
            work->unk_38 = func_080BE278(work);
            d = (s16)((work->unk_38 >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->unk_034 &= ~4;
            } else if (d < 0) {
                sub->unk_034 |= 4;
            }

            work->unk_2E = 200;
            work->unk_34++;
        } else if (work->unk_2E > 0) {
            ApproachValue(&sub->x, work->unk_38, work->unk_2E);
            work->unk_2E--;
        } else {
            work->unk_34 = 0;
            work->unk_32 = 1;
        }

        sub->z = gSineTable[(u8)work->unk_42] * 20 - 0xB400;
        work->unk_42 += 2;
        break;
    case 1:
        if (work->unk_34 == 0) {
            d = (s16)((((BtlWork*)gBtlWork->unk_07C)->unk_004 >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->unk_034 &= ~4;
            } else if (d < 0) {
                sub->unk_034 |= 4;
            }

            work->unk_34++;
        } else if (work->unk_34 > 60) {
            work->unk_34 = 0;
            work->unk_32 = 2;
        } else {
            work->unk_34++;
        }

        sub->z = gSineTable[(u8)work->unk_42] * 20 - 0xB400;
        work->unk_42 += 2;
        break;
    case 2:
        if (work->unk_34 == 0) {
            if (jf->unk_034 & 4) {
                work->unk_38 = 0x27800;
            } else {
                work->unk_38 = 0x19400;
            }

            d = (s16)((work->unk_38 >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->unk_034 &= ~4;
            } else if (d < 0) {
                sub->unk_034 |= 4;
            }

            work->unk_2E = 200;
            work->unk_34++;
        } else if (work->unk_2E > 0) {
            ApproachValue(&sub->x, work->unk_38, work->unk_2E);
            ApproachValue(&sub->z, -0xB400, work->unk_2E);
            work->unk_2E--;
        } else {
            work->unk_34 = 0;
            work->unk_32 = 3;
        }

        sub->z = gSineTable[(u8)work->unk_42] * 20 - 0xB400;
        work->unk_42 += 2;
        break;
    case 3:
        if (work->unk_34 == 0) {
            d = (s16)((((BtlWork*)gBtlWork->unk_07C)->unk_004 >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->unk_034 &= ~4;
            } else if (d < 0) {
                sub->unk_034 |= 4;
            }

            work->unk_34++;
        } else if (work->unk_34 > 60) {
            work->unk_34 = 0;
            work->unk_32 = 0;
        } else {
            work->unk_34++;
        }

        sub->z = gSineTable[(u8)work->unk_42] * 20 - 0xB400;
        work->unk_42 += 2;
        break;
    case 4:
        if (work->unk_34 == 0) {
            work->unk_2E = 20;
            sub->unk_034 |= 4;
            work->unk_28 = -204;
            work->unk_34++;
        } else {
            if (work->unk_2E > 0) {
                ApproachValue(&sub->z, -0xA000, work->unk_2E);
                work->unk_2E--;
            } else {
                if (sub->x <= 0x19400) {
                    sub->unk_034 &= ~4;
                    work->unk_28 = 204;
                }

                if (sub->x > 0x277FF) {
                    sub->unk_034 |= 4;
                    work->unk_28 = -204;
                }

                sub->x += work->unk_28;
            }

            if (work->unk_00->unk_250 == 0) {
                work->unk_34 = 0;
                work->unk_32 = 2;
            }
        }
        break;
    case 5:
        break;
    }

    if (work->unk_00->unk_24E == 2) {
        work->unk_34 = 0;
        work->unk_32 = 4;
    }

    if (work->unk_1E > 3) {
        work->unk_1E = 0;
        work->unk_1C++;

        if (work->unk_1C > 5) {
            work->unk_1C = 0;
        }

        p = work->unk_0C;
        RequestDma3Copy(gUnk_09685DA4 + (work->unk_1C << 9), gUnk_06010000 + (p[3] << 5), 512);
    }

    work->unk_1E++;
    work->unk_2D = func_080BD7F8(&sub->x, &sub->y, (s32)&sub->z, &sub->unk_010);
    func_08012324(&sub->unk_040, sub->x, sub->y, sub->z);
    TaskPoolUpdate(&work->unk_44);

    return 1;
}

void task_bos_jf_lamp_2(JfLampWork* work) {
    BosSub* sub = &((BosSub*)work->unk_00)[1];
    void* pal;
    u16 mode;
    s16 x;
    s16 y;

    mode = func_0801AF1C(sub->y);

    if (sub->unk_034 & 4) {
        mode &= 0xFFFE;
    } else {
        mode |= 1;
    }

    if (gBtlWork->unk_070 == 0 && (work->unk_00->unk_24C & 1) && (gFrameCounter & 1)) {
        pal = work->unk_18;
    } else {
        pal = work->unk_14;
    }

    WorldToScreen(&x, &y, sub->x, sub->y, sub->z);
    DrawSprite(x, y, work->unk_08, work->unk_04, pal, 0, mode, (u16)(-4100 - (sub->y >> 8) * 4));
    DrawSprite(x, y - 14, work->unk_10, work->unk_0C, work->unk_14, 0, mode,
               (u16)(-4101 - (sub->y >> 8) * 4));

    if (work->unk_2D == 1) {
        TaskPoolDraw(&work->unk_44);
    }
}

void task_bos_jf_lamp_3(JfLampWork* work) {
    ReleaseObjTiles(work->unk_0C);
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_14);
    ReleaseObjPalette(work->unk_18);
    TaskPoolDestroy(&work->unk_44);
}

s32 func_080BE278(JfLampWork* work) {
    s16 v;
    s32 r;

    if (work->unk_00->unk_034 & 4) {
        switch (gUnk_0203B4E4) {
        case 5:
        case 6:
            r = 0x27800;
            break;
        case 1:
        case 4:
        case 7:
            r = 0x21800;
            break;
        case 8:
            v = GetRandom() % 3;

            if (v == 0) {
                r = 0x27800;
            } else if (v == 1) {
                r = 0x24600;
            } else {
                r = 0x21800;
            }
            break;
        case 0:
        case 2:
        case 3:
            r = 0x24600;
            break;
        default:
            r = 0;
            break;
        }

        return r;
    }

    switch (gUnk_0203B4E4) {
    case 0:
    case 2:
        r = 0x1F400;
        break;
    case 3:
    case 5:
    case 7:
        r = 0x19400;
        break;
    case 8:
        v = GetRandom() % 3;

        if (v == 0) {
            r = 0x19400;
        } else if (v == 1) {
            r = 0x1CE00;
        } else {
            r = 0x1F400;
        }
        break;
    case 1:
    case 4:
    case 6:
        r = 0x1CE00;
        break;
    default:
        r = 0;
        break;
    }

    return r;
}

void func_080BE380(u8 a, u16 b, JfMajinWork* work) {
    func_080BE3DC(a, work);
    func_0800516C(1, gUnk_0203B500, 2, 2);
    LoadBgTiles(1, gUnk_09EF28D0[a], b * 32);
    work->unk_00->unk_24C &= ~0x10;
}
void func_080BE3DC(u8 a, JfMajinWork* work) {
    s16 n;

    if (work->unk_00->z < -0x8000) {
        RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, 0x800);
    } else {
        n = ((work->unk_00->z >> 8) + 0x88) / 8 + work->unk_6A;

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

    if (work->unk_00->z >= -0x8000) {
        n = ((work->unk_00->z >> 8) + 0x88) / 8 + work->unk_6A;

        if (n > 0x20) {
            func_0800443C(gUnk_0203B510, 0x800);
        } else {
            RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, (0x20 - n) * 64);
            func_0800443C(gUnk_0203B510 + (0x20 - n) * 64, n * 64);
        }

        func_0800516C(1, gUnk_0203B500, 2, 2);
    }
}

#ifdef NON_MATCHING
void task_bos_jf_majin_0(JfMajinWork* work, void* p) {
    JfWork* arg = p;
    s32 x;
    s32 y;
    s32 z;


    work->unk_00 = arg;
    x = arg->x;
    y = arg->y;
    z = arg->z;
    work->unk_48 = 0;
    work->unk_46 = 0;
    work->unk_44 = 0;
    work->unk_50 = x;
    work->unk_54 = y;
    work->unk_58 = z;
    work->unk_5C = 0;
    work->unk_5E = gUnk_0203ACC4;
    work->unk_60 = gUnk_0203ACD4;
    work->unk_62 = gUnk_0203ACC0;
    work->unk_64 = gUnk_0203ACC4;
    work->unk_66 = gUnk_0203ACD4;
    work->unk_68 = gUnk_0203ACC0;
    work->unk_49 = 0;
    work->unk_4A = 0;
    work->unk_4C = 0x133;
    work->unk_6A = 0;
    gUnk_0203B4F0[0] = gUnk_08125E24;
    gUnk_0203B4F0[1] = gUnk_08125E24;
    gUnk_0203B4F0[2] = gUnk_08125E24;
    gUnk_0203B4F0[3] = gUnk_0203B510;
    RequestDma3Copy(gUnk_096CAC64, gUnk_0203B510, 0x800);
    gUnk_0203B500 = gUnk_0203B4F0;
    LoadBgPalette(1, gUnk_096FB584, 32);
    LoadBgTiles(1, gUnk_09665C04, 0x2700);
    func_0800516C(1, gUnk_0203B500, 2, 2);
    work->tiles = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->unk_08 = LoadObjPalette(gUnk_096FB5A4, 0x60);
    work->unk_0C = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_2C = 1;
    work->unk_30 = 0x2A200;
    work->unk_34 = 0x12600;
    work->unk_40 = 0;
    work->unk_3C = 0;
    AnimInit(&work->anim, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim, 1, 1);
    work->gfx = AnimGetGfx(&work->anim);
    func_08005244(1, ((gBtlWork->unk_000 - arg->x) >> 8) + 0x308,
                  ((gBtlWork->unk_004 - (arg->y + arg->z)) >> 8) + 0x126);
    TaskPoolInit(&work->unk_6C, 2);
    TaskCreate(&work->unk_6C, gUnk_09EF2A74, work->unk_00);
}
#else
INCLUDE_ASM("bos2/task_bos_jf_majin_0.s");
#endif

u8 task_bos_jf_majin_1(JfMajinWork* work) {
    JfWork* jf = work->unk_00;

    jf->unk_24C |= 0x10;

    switch (work->unk_00->unk_238) {
    case 0:
        func_080BE9A0(work);
        break;
    case 1:
        func_080BEAE8(work);
        break;
    case 2:
        func_080BEDF4(work);
        break;
    case 3:
        func_080BF160(work);
        break;
    case 4:
        func_080BF4F4(work);
        break;
    case 5:
        func_080BF8C4(work);
        break;
    case 8:
        func_080BFDD4(work);
        break;
    case 6:
        func_080C02AC(work);
        break;
    case 7:
        func_080BFDD8(work);
        break;
    case 9:
        func_080BFFF8(work);
        break;
    case 10:
        func_080C0624(work);
        break;
    case 11:
        func_080BFEF0(work);
        break;
    }

    func_08012324(&jf->unk_040, jf->x, jf->y, jf->z);
    TaskPoolUpdate(&work->unk_6C);

    if (work->unk_00->unk_24C & 0x10) {
        if (work->unk_00->unk_238 != 6) {
            func_080BE478(work->unk_00->unk_248, work);
        }
    }

    return 1;
}

void task_bos_jf_majin_2(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    void* gfx;
    u16 pal;
    s16 x;
    s16 y;

    if (gBtlWork->unk_070 == 0) {
        if (jf->unk_24C & 1) {
            if (gFrameCounter & 1) {
                LoadPaletteWithEffect(gUnk_08F69BC4, (void*)0x05000000, 32);
                gfx = work->unk_0C;
            } else {
                LoadPaletteWithEffect(gUnk_096FB584, (void*)0x05000000, 32);
                gfx = work->unk_08;
            }
        } else {
            gfx = work->unk_08;
        }
    } else {
        LoadPaletteWithEffect(gUnk_096FB584, (void*)0x05000000, 32);
        gfx = work->unk_08;
    }

    func_08005244(1, ((gBtlWork->unk_000 - jf->x) >> 8) + 776,
                  ((gBtlWork->unk_004 - (jf->y + jf->z)) >> 8) + 294);

    if (work->unk_2C == 1) {
        if (jf->unk_034 & 4) {
            pal = func_0801AF1C(jf->y);
        } else {
            pal = func_0801AF1C(jf->y);
            pal |= 1;
        }

        WorldToScreen(&x, &y, jf->x, jf->y, jf->z);
        DrawSprite(x, work->unk_40 + (y - 61), work->gfx, work->tiles, gfx, 0, pal,
                   (u16)(-4100 - (jf->y >> 8) * 4));
    }

    TaskPoolDraw(&work->unk_6C);
}

void task_bos_jf_majin_3(JfMajinWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->unk_08);
    ReleaseObjPalette(work->unk_0C);
    TaskPoolDestroy(&work->unk_6C);
}
s32 func_080BE910(void) {
    s32 v = ((BtlWork*)gBtlWork->unk_07C)->unk_004;

    if (v < 0x1EA00) {
        return 0;
    }

    if (v < 0x22200) {
        return 1;
    }

    return 2;
}

s32 func_080BE940(JfMajinWork* work) {
    s32 v;

    if (work->unk_00->unk_034 & 4) {
        v = ((BtlWork*)gBtlWork->unk_07C)->unk_004;

        if (v < 0x1EA00) {
            return 2;
        }

        if (v < 0x22200) {
            return 1;
        }

        return 0;
    }

    v = ((BtlWork*)gBtlWork->unk_07C)->unk_004;

    if (v > 0x22200) {
        return 2;
    }

    if (v > 0x1EA00) {
        return 1;
    }

    return 0;
}

void func_080BE9A0(JfMajinWork* work) {
    JfWork* jf = work->unk_00;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 8;
            work->unk_5C = 8;
        } else {
            jf->unk_248 = 28;
            work->unk_5C = 28;
        }

        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->unk_00->unk_244++;
    } else {
        if (jf->unk_24A >= gUnk_0961A6A8[jf->unk_248]) {
            jf->unk_24A = 0;
            work->unk_00->unk_248++;
            work->unk_3C++;

            if (work->unk_00->unk_248 > work->unk_5C + 5) {
                work->unk_00->unk_248 = work->unk_5C;
                work->unk_3C = 0;
            }

            func_080BE380(work->unk_00->unk_248, 0x80, work);
        }

        work->unk_00->unk_24A++;
        work->gfx = AnimUpdate(&work->anim);
        work->unk_40 = gUnk_0961A70A[work->unk_3C];

        if (gBtlWork->unk_0A0 != 0) {
            if (GetRandom() % 80 == 0) {
                func_080C0714(work);
                work->unk_00->unk_244 = 0;
            }
        }
    }
}

void func_080BEAE8(JfMajinWork* work) {
    JfWork* jf = work->unk_00;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 0;
        } else {
            jf->unk_248 = 7;
        }

        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0xA0, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_2C = 0;
        work->unk_00->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (jf->unk_24A >= gUnk_0961A6A8[jf->unk_248]) {
                jf->unk_24A = 0;

                if (jf->unk_034 & 4) {
                    work->unk_00->unk_248++;

                    if (work->unk_00->unk_248 > 7) {
                        work->unk_00->unk_248 = 0;
                    }
                } else {
                    work->unk_00->unk_248--;

                    if (work->unk_00->unk_248 < 0) {
                        work->unk_00->unk_248 = 7;
                    }
                }

                func_080BE380(work->unk_00->unk_248, 0xA0, work);
            }

            work->unk_00->unk_24A++;
            jf->z += 0x400;
            work->unk_46++;

            if (work->unk_46 > 40) {
                work->unk_46 = 0;
                work->unk_48++;
            }

            if (work->unk_46 == 21) {
                jf->unk_034 |= 0x1000000;
            }
            break;
        case 1:
            work->unk_46++;

            if (work->unk_46 > 60) {
                work->unk_46 = 0;
                work->unk_00->unk_24A = 0;

                if (jf->unk_034 & 4) {
                    jf->unk_034 &= ~4;
                    jf->x = 0x16A00;
                    work->unk_00->unk_248 = 3;
                } else {
                    jf->unk_034 |= 4;
                    jf->x = 0x2A200;
                    work->unk_00->unk_248 = 3;
                }

                func_080BE380(work->unk_00->unk_248, 0xA0, work);
                m4aSongNumStart(0x277);
                work->unk_48++;
            }
            break;
        case 2:
            if (jf->unk_24A >= gUnk_0961A6A8[jf->unk_248]) {
                jf->unk_24A = 0;

                if (jf->unk_034 & 4) {
                    work->unk_00->unk_248++;

                    if (work->unk_00->unk_248 > 7) {
                        work->unk_00->unk_248 = 0;
                    }
                } else {
                    work->unk_00->unk_248--;

                    if (work->unk_00->unk_248 < 0) {
                        work->unk_00->unk_248 = 7;
                    }
                }

                func_080BE380(work->unk_00->unk_248, 0xA0, work);
            }

            work->unk_00->unk_24A++;
            jf->z -= 0x400;
            work->unk_46++;

            if (work->unk_46 > 40) {
                work->unk_46 = 0;
                work->unk_48++;
            }

            if (work->unk_46 == 22) {
                jf->unk_034 &= ~0x1000000;
            }
            break;
        default:
            work->unk_00->unk_244 = 0;
            work->unk_00->unk_238 = 0;
            break;
        }
    }
}
void func_080BEDF4(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    u32* q = &jf->unk_110;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 0;
            work->unk_5C = 14;
        } else {
            jf->unk_248 = 7;
            work->unk_5C = 34;
        }

        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0xA0, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_2C = 0;
        work->unk_00->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (work->unk_00->unk_24A >= gUnk_0961A6A8[work->unk_00->unk_248]) {
                work->unk_00->unk_24A = 0;

                if (jf->unk_034 & 4) {
                    work->unk_00->unk_248++;

                    if (work->unk_00->unk_248 > 7) {
                        work->unk_00->unk_248 = 0;
                    }
                } else {
                    work->unk_00->unk_248--;

                    if (work->unk_00->unk_248 < 0) {
                        work->unk_00->unk_248 = 7;
                    }
                }

                func_080BE380(work->unk_00->unk_248, 0xA0, work);
            }

            work->unk_00->unk_24A++;
            jf->z += 0x400;
            work->unk_46++;

            if (work->unk_46 > 60) {
                work->unk_46 = 0;
                work->unk_48++;
            }

            if (work->unk_46 == 23) {
                jf->unk_034 |= 0x1000000;
            }
            break;
        case 1:
            if (jf->unk_034 & 4) {
                work->unk_00->unk_248 = 14;
                work->unk_58 = -0x2000 - ((gUnk_0203ACC0 + 1) << 11);
            } else {
                work->unk_00->unk_248 = 34;
                work->unk_58 = -0x2000 - ((gUnk_0203ACC4 + 1) << 11);
            }

            work->unk_00->unk_24A = 0;
            work->unk_80 = TaskCreate(&work->unk_6C, gUnk_09EF2A5C, work->unk_00);
            func_080BE380(work->unk_00->unk_248, 0xA0, work);
            work->unk_44 = 120;
            work->unk_48++;
            break;
        case 2:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;

                if (work->unk_44 == 30) {
                    jf->unk_034 &= ~0x1000000;
                }
            } else {
                work->unk_48++;
            }
            break;
        case 3:
            if (work->unk_00->unk_24A >= gUnk_0961A6A8[work->unk_00->unk_248]) {
                work->unk_00->unk_24A = 0;
                work->unk_00->unk_248++;

                if (work->unk_00->unk_248 > work->unk_5C + 4) {
                    if (jf->unk_034 & 4) {
                        work->unk_00->unk_248 = 8;
                    } else {
                        work->unk_00->unk_248 = 28;
                    }

                    work->unk_2C = 1;
                    work->unk_48++;
                }

                func_080BE380(work->unk_00->unk_248, 0xA0, work);
            }

            work->unk_00->unk_24A++;
            break;
        case 4:
            if (IsTaskActive(work->unk_80) == 0) {
                work->unk_58 = -0x3800;
                work->unk_44 = 10;
                work->unk_48++;
            }
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->unk_00->unk_244 = 0;
            work->unk_00->unk_238 = 6;
            break;
        }
    }
}
void func_080BF160(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    u32* q = &jf->unk_110;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 19;
            work->unk_00->unk_24A = 0;
            work->unk_5C = 19;
            work->unk_50 = 0x27A00;
            work->unk_58 = -0x5200 - ((gUnk_0203ACC0 + 1) << 11);
        } else {
            jf->unk_248 = 39;
            work->unk_00->unk_24A = 0;
            work->unk_5C = 39;
            work->unk_50 = 0x19200;
            work->unk_58 = -0x5200 - ((gUnk_0203ACC4 + 1) << 11);
        }

        func_080BE380(work->unk_00->unk_248, 0xA0, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 40;
        work->unk_2C = 0;
        work->unk_00->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->x, work->unk_50, work->unk_44);
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;

                if (work->unk_00->unk_24A >= gUnk_0961A6A8[work->unk_00->unk_248]) {
                    work->unk_00->unk_24A = 0;
                    work->unk_00->unk_248++;

                    if (work->unk_00->unk_248 >= work->unk_5C + 1) {
                        work->unk_00->unk_248 = work->unk_5C + 1;
                    }

                    func_080BE380(work->unk_00->unk_248, 0xA0, work);
                }

                work->unk_00->unk_24A++;
            } else {
                work->unk_48++;
            }
            break;
        case 1:
            work->unk_46++;

            if (work->unk_46 > 20) {
                work->unk_46 = 0;
                work->unk_6A = 1;
                work->unk_48++;
            }
            break;
        case 2:
            jf->z += 0xA00;

            if (work->unk_00->unk_24A >= gUnk_0961A6A8[work->unk_00->unk_248]) {
                work->unk_00->unk_24A = 0;
                work->unk_00->unk_248++;

                if (work->unk_00->unk_248 == work->unk_5C + 4) {
                    work->unk_6A = 0;
                    work->unk_48++;
                }

                func_080BE380(work->unk_00->unk_248, 0xA0, work);
            }

            work->unk_00->unk_24A++;
            break;
        case 3:
            if (jf->unk_034 & 4) {
                func_080147D8(jf->x - 0x3000, jf->y + jf->z + 0x1800);
                func_08011F78(0xE8, jf->x - 0x3000, jf->y, jf->z + 0x1800, 30, 30, 30);
            } else {
                func_080147D8(jf->x + 0x3000, jf->y + jf->z + 0x1800);
                func_08011F78(0xE8, jf->x + 0x3000, jf->y, jf->z + 0x1800, 30, 30, 30);
            }

            func_0802F1E8();
            m4aSongNumStart(0x210);
            work->unk_46 = 0;
            work->unk_48++;
            break;
        case 4:
            if (work->unk_46 == 10) {
                work->unk_00->unk_248 = work->unk_5C + 5;
                func_080BE380(work->unk_00->unk_248, 0xA0, work);
            }

            if (work->unk_46 > 20) {
                work->unk_46 = 0;

                if (jf->unk_034 & 4) {
                    work->unk_50 = 0x2A200;
                } else {
                    work->unk_50 = 0x16A00;
                }

                work->unk_58 = -0x3800;
                work->unk_44 = 10;
                work->unk_48++;
            }

            work->unk_46++;
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->x, work->unk_50, work->unk_44);
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->unk_00->unk_244 = 0;
            work->unk_00->unk_238 = 6;
            break;
        }
    }
}
void func_080BF4F4(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    u32* q = &jf->unk_110;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 25;
            work->unk_00->unk_24A = 0;
            work->unk_5C = 25;
            work->unk_50 = 0x2A200;
            work->unk_58 = -0x2400 - ((gUnk_0203ACC0 + 1) << 11);
        } else {
            jf->unk_248 = 45;
            work->unk_00->unk_24A = 0;
            work->unk_5C = 45;
            work->unk_50 = 0x16A00;
            work->unk_58 = -0x2400 - ((gUnk_0203ACC4 + 1) << 11);
        }

        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 40;
        work->unk_2C = 0;
        work->unk_00->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        case 1:
            if (jf->unk_034 & 4) {
                jf->x += 0x100;
            } else {
                jf->x -= 0x100;
            }

            work->unk_46++;

            if (work->unk_46 > 20) {
                work->unk_46 = 0;
                work->unk_00->unk_248 = work->unk_5C + 1;
                func_080BE380(work->unk_00->unk_248, 0x80, work);
                work->unk_44 = 2;
                work->unk_48++;
            }
            break;
        case 2:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->x, work->unk_50, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
                work->unk_44 = 0;
            }
            break;
        case 3:
            if (jf->unk_034 & 4) {
                func_08016C40(jf->x - 0x1A00, jf->y, jf->z - 0x3100, 0x133, 160, 45);
            } else {
                func_08016C40(jf->x + 0x1A00, jf->y, jf->z - 0x3100, 0x133, 96, 45);
            }

            m4aSongNumStart(0x27A);
            jf->x = (work->unk_50 - 0x100) + (work->unk_44++ % 2) * 0x200;
            work->unk_46 = 0;
            work->unk_48++;
            break;
        case 4:
            jf->x = (work->unk_50 - 0x100) + (work->unk_44++ % 2) * 0x200;

            if (jf->unk_034 & 4) {
                func_08014780(jf->x - 0x1A00, jf->y, jf->z - 0x3100);
            } else {
                func_08014780(jf->x + 0x1A00, jf->y, jf->z - 0x3100);
            }

            if (work->unk_46 > 10 && work->unk_46 % 10 == 9) {
                if (jf->unk_034 & 4) {
                    func_08011F78(0xE9, jf->x - 0x6400, jf->y + 0xA00, jf->z + 0x2000, 20, 20, 20);
                } else {
                    func_08011F78(0xE9, jf->x + 0x6400, jf->y + 0xA00, jf->z + 0x2000, 20, 20, 20);
                }
            }

            if (work->unk_46 > 80) {
                work->unk_46 = 0;
                work->unk_58 = -0x3800;
                work->unk_44 = 10;
                work->unk_00->unk_248 = work->unk_5C + 2;
                func_080BE380(work->unk_00->unk_248, 0x80, work);
                work->unk_48++;
            }

            work->unk_46++;
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->x, work->unk_50, work->unk_44);
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->unk_00->unk_244 = 0;
            work->unk_00->unk_238 = 6;
            break;
        }
    }
}
void func_080BF8C4(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    u32* q = &jf->unk_110;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 25;
            work->unk_00->unk_24A = 0;
            work->unk_5C = 25;
            work->unk_50 = 0x2A200;
            work->unk_54 = ((BtlWork*)gBtlWork->unk_07C)->unk_008 - 0x1400;
            work->unk_58 = -0x2400 - ((gUnk_0203ACC0 + 1) << 11);
        } else {
            jf->unk_248 = 45;
            work->unk_00->unk_24A = 0;
            work->unk_5C = 45;
            work->unk_50 = 0x16A00;
            work->unk_54 = ((BtlWork*)gBtlWork->unk_07C)->unk_008 - 0x1400;
            work->unk_58 = -0x2400 - ((gUnk_0203ACC4 + 1) << 11);
        }

        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 40;
        work->unk_2C = 0;
        work->unk_00->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            func_0802F274(jf->x, jf->y + jf->z);

            if (work->unk_44 > 0) {
                ApproachValue(&jf->y, work->unk_54, work->unk_44);
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        case 1:
            if (jf->unk_034 & 4) {
                jf->x += 0x100;
            } else {
                jf->x -= 0x100;
            }

            work->unk_46++;

            if (work->unk_46 > 20) {
                work->unk_46 = 0;
                work->unk_00->unk_248 = work->unk_5C + 1;
                func_080BE380(work->unk_00->unk_248, 0x80, work);
                work->unk_44 = 2;
                work->unk_48++;
            }
            break;
        case 2:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->x, work->unk_50, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
                work->unk_44 = 0;
            }
            break;
        case 3:
            if (jf->unk_034 & 4) {
                work->unk_49 = 148;
                work->unk_4C = 0x100;
                func_08016C40(jf->x - 0x1A00, jf->y, jf->z - 0x3100, 0x100, work->unk_49, 45);
                func_080147C8(0x133, 0x100);
            } else {
                work->unk_49 = 108;
                work->unk_4C = 0x133;
                func_08016C40(jf->x + 0x1A00, jf->y, jf->z - 0x3100, 0x100, work->unk_49, 45);
                func_080147C8(0x133, 0x100);
            }

            m4aSongNumStart(0x27A);
            jf->x = (work->unk_50 - 0x100) + (work->unk_44++ % 2) * 0x200;
            work->unk_46 = 0;
            work->unk_4A = 0;
            work->unk_48++;
            break;
        case 4:
            work->unk_44++;

            if (jf->unk_034 & 4) {
                jf->x = (work->unk_50 - 0x100) + (work->unk_44 % 2) * 0x200;
                func_08014780(jf->x - 0x1A00, jf->y, jf->z - 0x3100);

                if (work->unk_49 <= 173 && work->unk_44 % 2 == 0) {
                    work->unk_49++;
                    func_080147B8(work->unk_49);
                    work->unk_4A++;
                    work->unk_4C = gUnk_09EF2994[work->unk_4A];
                    func_080147C8(0x133, work->unk_4C);
                }
            } else {
                jf->x = (work->unk_50 - 0x100) + (work->unk_44 % 2) * 0x200;
                func_08014780(jf->x + 0x1A00, jf->y, jf->z - 0x3100);

                if (work->unk_49 > 82 && work->unk_44 % 2 == 0) {
                    work->unk_49--;
                    func_080147B8(work->unk_49);
                    work->unk_4A++;
                    work->unk_4C = gUnk_09EF2994[work->unk_4A];
                    func_080147C8(0x133, work->unk_4C);
                }
            }

            if (work->unk_46 >= 11 && work->unk_46 <= 50) {
                if (jf->unk_034 & 4) {
                    func_08011F78(0xEA, jf->x - 0x3200 - work->unk_4A * 3 * 512, jf->y + 0xA00, jf->z + 0x2C00, 20, 20, 20);
                } else {
                    func_08011F78(0xEA, jf->x + 0x3200 + work->unk_4A * 3 * 512, jf->y + 0xA00, jf->z + 0x2C00, 20, 20, 20);
                }
            }

            if (work->unk_46 > 80) {
                work->unk_46 = 0;
                work->unk_54 = 0x15E00;
                work->unk_58 = -0x3800;
                work->unk_44 = 10;
                work->unk_00->unk_248 = work->unk_5C + 2;
                func_080BE380(work->unk_00->unk_248, 0x80, work);
                work->unk_48++;
            } else {
                work->unk_46++;
            }
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->x, work->unk_50, work->unk_44);
                ApproachValue(&jf->y, work->unk_54, work->unk_44);
                ApproachValue(&jf->z, work->unk_58, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->unk_00->unk_244 = 0;
            work->unk_00->unk_238 = 6;
            break;
        }
    }
}

void func_080BFDD4(JfMajinWork* work) {
}
void func_080BFDD8(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    u32* q = &jf->unk_110;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->x = 0x2A200;
            jf->unk_248 = 8;
        } else {
            jf->x = 0x16A00;
            jf->unk_248 = 28;
        }

        jf->y = 0x15E00;
        jf->z = -0x3800;
        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->unk_6A = 0;
        jf->unk_034 &= ~0x1000000;
        func_08019190(jf, 9);
        work->unk_00->unk_244++;
    } else if (jf->unk_244 > 60) {
        func_0801AF08(q);
        work->unk_00->unk_244 = 0;

        if (jf->unk_034 & 4) {
            work->unk_00->unk_248 = 8;
        } else {
            work->unk_00->unk_248 = 28;
        }

        work->unk_00->unk_24A = 0;
        work->unk_00->unk_238 = 6;
    } else {
        work->unk_00->unk_244++;
    }
}

void func_080BFEF0(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    u32* q = &jf->unk_110;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->x = 0x2A200;
            jf->unk_248 = 8;
        } else {
            jf->x = 0x16A00;
            jf->unk_248 = 28;
        }

        jf->y = 0x15E00;
        jf->z = -0x3800;
        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->unk_6A = 0;
        jf->unk_034 &= ~0x1000000;
        work->unk_00->unk_244++;
    } else {
        func_0801AF08(q);
        work->unk_00->unk_244 = 0;

        if (jf->unk_034 & 4) {
            work->unk_00->unk_248 = 8;
        } else {
            work->unk_00->unk_248 = 28;
        }

        work->unk_00->unk_24A = 0;
        work->unk_00->unk_238 = 6;
    }
}

#ifndef VERSION_EU
void func_080BFFF8(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    BosSub* q = (BosSub*)&jf->unk_110;
    JfMajinFx fx;
    s32 v;

    if (jf->unk_244 == 0) {
        if (jf->unk_034 & 4) {
            jf->unk_248 = 8;
            v = 0x2A200;
        } else {
            jf->unk_248 = 28;
            v = 0x16A00;
        }

        jf->x = v;

        jf->y = 0x15E00;
        jf->z = -0x3800;
        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_2C = 1;
        func_0802F274(jf->x, jf->y + jf->z);
        func_0801AF4C((BosSub*)jf);
        work->unk_48 = 0;
        work->unk_44 = 0;
        work->unk_00->unk_244++;
        return;
    }

    switch (work->unk_48) {
    case 0:
        func_0802F274(jf->x, jf->y + jf->z);

        if (work->unk_44 > 1) {
            work->unk_44 = 0;
            work->unk_48++;
        } else {
            work->unk_44++;
        }
        break;
    case 1:
        func_0802F274(jf->x, jf->y + jf->z);

        if (func_08006314() != 0) {
            break;
        }

        if (jf->unk_034 & 4) {
            func_08014AAC(jf->x - 0x800, jf->y + jf->z - 0x800);
        } else {
            func_08014AAC(jf->x + 0x800, jf->y + jf->z - 0x800);
        }

        func_08006238(0, gBtlWork->unk_0B3, 8);
        work->unk_48++;
        break;
    case 2:
        func_0802F274(jf->x, jf->y + jf->z);

        if (work->unk_44 <= 119) {
            work->unk_44++;
        } else {
            func_0801536C();
            work->unk_48++;
        }
        break;
    case 3:
        if (func_080128EC() == 0) {
            if (q->x < 0x1B200) {
                q->x = 0x1BA00;
            }

            if (q->x > 0x25A00) {
                q->x = 0x25200;
            }

            fx.unk_00 = q->x;
            fx.unk_04 = q->y;
            fx.unk_08 = -0x7800;
            func_08096DC4((u8*)gBtlWork + 44, &fx);
            func_0801B918((BosSub*)jf);
            gUnk_0203ACC4 = 0;
            gUnk_0203ACD4 = 0;
            gUnk_0203ACC0 = 0;
            func_080BDAAC();
            jf->x = 0;
            jf->y = 0;
            jf->z = 0;
            func_08005244(1, (gBtlWork->unk_000 >> 8) + 776, (gBtlWork->unk_004 >> 8) + 294);
            work->unk_48++;
        } else {
            func_0802F274(jf->x, jf->y + jf->z);
        }
        break;
    default:
        func_0801B008();
        work->unk_00->unk_24C |= 2;
        break;
    }
}
#else
INCLUDE_ASM("bos2/func_080BFFF8.s");
#endif

u8 func_080C0258(u16* p, s16 b, u8 c, u8 d) {
    if ((s16)*p == b) {
        return 1;
    }

    if ((s16)*p > b) {
        *p = *p - 1;
    } else {
        BtlWork* q;
        s32 v;

        *p = *p + 1;

        if (c == d) {
            q = (BtlWork*)gBtlWork->unk_07C;
            v = -(((s16)*p + 1) << 11);

            if (q->unk_00C >= v) {
                q->unk_00C = v;
            }
        }
    }

    return 0;
}

#ifdef NON_MATCHING
void func_080C02AC(JfMajinWork* work) {
    JfWork* jf = work->unk_00;
    BosSub* s = (BosSub*)&work->unk_00->unk_110;
    s16 n;
    s16 m;
    u8 v;

    if (jf->unk_250 > 0) {
        jf->unk_244 = 0;
        work->unk_00->unk_238 = 0;
        return;
    }

    switch (jf->unk_244) {
    default:
        work->unk_46++;

        if (work->unk_46 <= 1) {
            return;
        }

        work->unk_46 = 0;
        v = func_080BE910();
        n = (s8)func_080C0258(&work->unk_5E, work->unk_64, v, 0);
        n += (s8)func_080C0258(&work->unk_60, work->unk_66, v, 1);
        n += (s8)func_080C0258(&work->unk_62, work->unk_68, v, 2);
        break;
    case 0:
        if (jf->unk_034 & 4) {
            jf->unk_248 = 8;
            work->unk_5C = 8;
        } else {
            jf->unk_248 = 28;
            work->unk_5C = 28;
        }

        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;

        if (work->unk_00->unk_24C & 4) {
            work->unk_00->unk_24C &= ~4;
            work->unk_00->unk_24E = 2;
            m = 14;
        } else if (s->unk_02C < s->unk_02E / 2) {
            switch (work->unk_00->unk_24E) {
            case 0:
                m = GetRandom() & 1;
                break;
            case 1:
            case 2:
                m = GetRandom() % 6 + 2;
                break;
            case 3:
                m = GetRandom() % 6 + 8;
                break;
            default:
                m = 0;
                break;
            }
        } else if (work->unk_00->unk_24E == 0) {
            m = GetRandom() % 6 + 8;
        } else {
            m = GetRandom() % 8;
        }

        work->unk_5E = gUnk_0203ACC4;
        work->unk_60 = gUnk_0203ACD4;
        work->unk_62 = gUnk_0203ACC0;
        work->unk_64 = gUnk_0961A710[m][0];
        work->unk_66 = gUnk_0961A710[m][1];
        work->unk_68 = gUnk_0961A710[m][2];
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 0;
        func_080BDB28(60);
        work->unk_00->unk_244++;
        return;
    case 1:
        work->unk_46++;

        if (work->unk_46 > 80) {
            work->unk_46 = 0;
            m4aSongNumStart(0x26A);
            work->unk_00->unk_244++;
        }
        return;
    }

    if (n == 3) {
        if (s->unk_02C < s->unk_02E / 2) {
            switch (work->unk_00->unk_24E) {
            case 0:
                work->unk_00->unk_24E = 3;
                break;
            case 1:
                work->unk_00->unk_24E = 0;
                break;
            case 2:
                work->unk_00->unk_24E = 0;
                work->unk_00->unk_250 = 300;
                break;
            case 3:
                work->unk_00->unk_24E = 1;
                break;
            }
        } else {
            switch (work->unk_00->unk_24E) {
            case 0:
                work->unk_00->unk_24E = 1;
                break;
            case 1:
                work->unk_00->unk_24E = 0;
                break;
            case 2:
                work->unk_00->unk_24E = 0;
                work->unk_00->unk_250 = 300;
                break;
            }
        }

        work->unk_00->unk_244 = 0;
        work->unk_00->unk_238 = 0;
    } else {
        gUnk_0203ACC4 = work->unk_5E;
        gUnk_0203ACD4 = work->unk_60;
        gUnk_0203ACC0 = work->unk_62;
        func_080BDAAC();
    }
}
#else
INCLUDE_ASM("bos2/func_080C02AC.s");
#endif

void func_080C0624(JfMajinWork* work) {
    if (work->unk_00->unk_244 == 0) {
        work->unk_00->unk_248 = 8;
        work->unk_5C = 8;
        work->unk_00->unk_24A = 0;
        func_080BE380(work->unk_00->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->unk_00->unk_244++;
    } else {
        if (work->unk_00->unk_24A >= gUnk_0961A6A8[work->unk_00->unk_248]) {
            work->unk_00->unk_24A = 0;
            work->unk_00->unk_248++;
            work->unk_3C++;

            if (work->unk_00->unk_248 > work->unk_5C + 5) {
                work->unk_00->unk_248 = work->unk_5C;
                work->unk_3C = 0;
            }

            func_080BE380(work->unk_00->unk_248, 0x80, work);
        }

        work->unk_00->unk_24A++;
        work->gfx = AnimUpdate(&work->anim);
        work->unk_40 = gUnk_0961A70A[work->unk_3C];
    }
}

void func_080C0714(JfMajinWork* work) {
    BosSub* s = (BosSub*)&work->unk_00->unk_110;
    u8 v;
    s32 r;

    if (s->unk_02C < s->unk_02E / 2) {
        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 19) {
            func_08083900(GetRandom() % 2 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }

        if (gUnk_0203ACC4 == gUnk_0203ACD4 && gUnk_0203ACC4 == gUnk_0203ACC0 && GetRandom() % 100 <= 79) {
            func_0801BCD4(s);
            work->unk_00->unk_23C = 5;
        } else {
            v = func_080BE940(work);

            switch (v) {
            case 0:
                func_0801BCD4(s);
                r = (s16)(GetRandom() % 100);

                if (r <= 39) {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 3;
                } else if (r <= 79) {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 4;
                } else {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 2;
                }
                break;
            case 1:
                func_0801BCD4(s);
                work->unk_00->unk_23C = 2;
                break;
            case 2:
                if (GetRandom() % 100 <= 49) {
                    work->unk_00->unk_238 = 1;
                } else {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 2;
                }
                break;
            }
        }
    } else {
        if (GetRandom() % 100 <= 29) {
            func_08083900(GetRandom() % 3 + 6);
        } else {
            func_08083900(GetRandom() % 6 + 1);
        }

        if (gUnk_0203ACC4 == gUnk_0203ACD4 && gUnk_0203ACC4 == gUnk_0203ACC0 && GetRandom() % 100 <= 19) {
            func_0801BCD4(s);
            work->unk_00->unk_23C = 5;
        } else {
            v = func_080BE940(work);

            switch (v) {
            case 0:
                func_0801BCD4(s);

                if (GetRandom() % 100 <= 59) {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 3;
                } else {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 4;
                }
                break;
            case 1:
                if (GetRandom() % 100 <= 79) {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 2;
                } else {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 4;
                }
                break;
            case 2:
                if (GetRandom() % 100 <= 69) {
                    work->unk_00->unk_238 = 1;
                } else {
                    func_0801BCD4(s);
                    work->unk_00->unk_23C = 2;
                }
                break;
            }
        }
    }
}
void task_bos_jf_rock_0(JfRockWork* work, JfWork* arg) {
    work->unk_000 = arg;
    work->unk_030 = arg->x;
    work->unk_034 = arg->y + 0x500;
    work->unk_038 = arg->z - 0x4800;
    work->unk_03C = 0;
    work->unk_0F8 = 0xFE00;
    work->unk_060 = 0x20000;
    work->unk_13C = 0;
    work->unk_140 = 0;
    work->unk_144 = 0;
    work->unk_148 = 0;
    work->unk_14C = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;
    work->unk_028 = 0;
    work->unk_02A = 0;
    work->unk_194 = 0;

    if (arg->unk_034 & 4) {
        work->unk_170 = arg->x + 0x2000;
        work->unk_174 = arg->y + 0xA00;
        work->unk_178 = arg->z - 0x1900;
        work->unk_144 = -((gUnk_0203ACC0 + 1) << 11) - 0x2000;
    } else {
        work->unk_170 = arg->x - 0x2000;
        work->unk_174 = arg->y + 0xA00;
        work->unk_178 = arg->z - 0x1900;
        work->unk_144 = -0x2000 - ((gUnk_0203ACC4 + 1) << 11);
    }

    work->unk_17C = 0;
    work->unk_17E = 0;
    work->unk_15A = 0;
    work->unk_158 = 0;
    work->unk_15C = 120;
    work->unk_15E = 0;
    work->unk_160 = 0;
    work->unk_004 = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->unk_008 = LoadObjPalette(gUnk_096FB5A4, 0x60);
    AnimInit(&work->anim, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim, gUnk_09EF2A38[work->unk_158], 0);
    work->gfx = AnimGetGfx(&work->anim);
    work->unk_164 = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->unk_168 = LoadObjPalette(gUnk_096FB5A4, 0x60);
    work->unk_16C = gUnk_09EF3A48[gUnk_09EF2A42[work->unk_17E]];
    TaskPoolInit(&work->unk_180, 1);
    TaskCreate(&work->unk_180, gUnk_09EF34D8, &work->unk_02C);
}
u8 task_bos_jf_rock_1(JfRockWork* work) {
    JfWork* jf = work->unk_000;
    BtlWork* b;
    s16 n;

    switch (work->unk_160) {
    case 0:
        if (work->unk_15C > 40) {
            func_0802F274(work->unk_030, work->unk_034 + work->unk_038 - 0x2000);
        }

        work->unk_02A++;

        if (work->unk_02A > 2) {
            work->unk_02A = 0;
            work->unk_028++;

            if (work->unk_028 > 8) {
                work->unk_028 = 0;
            }

            LoadObjPaletteBank(((u16*)work->unk_008)[3] + 2, gUnk_096FB604 + (work->unk_028 << 5));
        }

        if (work->unk_15C > 0) {
            ApproachValue(&work->unk_038, work->unk_144 - 0x4800, work->unk_15C);
            ApproachValue(&work->unk_178, work->unk_144 - 0x1C00, work->unk_15C);
            work->unk_15C--;

            if (work->unk_038 <= -0xC00) {
                work->unk_158 = 8;
                work->unk_15A = 1;
            } else {
                n = 8 - ((work->unk_038 >> 8) + 12) / 8;

                if (n < 0) {
                    work->unk_158 = 0;
                    work->unk_15A = 0;
                } else {
                    work->unk_158 = n;
                    work->unk_15A = 1;
                }
            }

            AnimStart(&work->anim, gUnk_09EF2A38[work->unk_158], 0);
            work->gfx = AnimGetGfx(&work->anim);

            if (work->unk_178 <= -0x1000) {
                work->unk_17E = 11;
                work->unk_17C = 1;
            } else {
                n = 11 - ((work->unk_178 >> 8) + 16) / 8;

                if (n < 0) {
                    work->unk_17E = 0;
                    work->unk_17C = 0;
                } else {
                    work->unk_17E = n;
                    work->unk_17C = 1;
                }
            }

            work->unk_16C = gUnk_09EF3A48[gUnk_09EF2A42[work->unk_17E]];
        } else {
            work->unk_13C = (b = (BtlWork*)gBtlWork->unk_07C)->unk_004;
            work->unk_140 = b->unk_008;
            work->unk_144 = b->unk_00C;
            work->unk_148 = (work->unk_13C - work->unk_030) / 40;
            work->unk_14C = (work->unk_140 - work->unk_034) / 40;
            work->unk_150 = 0;
            work->unk_154 = (work->unk_144 - work->unk_038) / 820;
            work->unk_160++;
        }

        if (work->unk_000->unk_238 == 7 || work->unk_000->unk_238 == 11) {
            m4aSongNumStart(0x1F9);
            work->unk_17C = 0;
            work->unk_15C = 0;
            work->unk_160 = 5;
        }
        break;
    case 1:
        work->unk_02A++;

        if (work->unk_02A > 2) {
            work->unk_02A = 0;
            work->unk_028++;

            if (work->unk_028 > 8) {
                work->unk_028 = 0;
            }

            LoadObjPaletteBank(((u16*)work->unk_008)[3] + 2, gUnk_096FB604 + (work->unk_028 << 5));
        }

        work->unk_15E++;

        if (work->unk_15E > 3) {
            work->unk_15E = 0;

            if (jf->unk_034 & 4) {
                work->unk_170 = jf->x + 0x1000;
                work->unk_174 = jf->y + 0xA00;
                work->unk_178 = jf->z - 0x1000;
            } else {
                work->unk_170 = jf->x - 0x1000;
                work->unk_174 = jf->y + 0xA00;
                work->unk_178 = jf->z - 0x1000;
            }

            work->unk_16C = gUnk_09EF3A48[15];
            m4aSongNumStart(632);
            work->unk_194 = 1;
            work->unk_160++;
        }

        if (work->unk_000->unk_238 == 7 || work->unk_000->unk_238 == 11) {
            m4aSongNumStart(0x1F9);
            work->unk_17C = 0;
            work->unk_194 = 0;
            work->unk_15C = 0;
            work->unk_160 = 5;
        }
        break;
    case 2:
        work->unk_02A++;

        if (work->unk_02A > 2) {
            work->unk_02A = 0;
            work->unk_028++;

            if (work->unk_028 > 8) {
                work->unk_028 = 0;
            }

            LoadObjPaletteBank(((u16*)work->unk_008)[3] + 2, gUnk_096FB604 + (work->unk_028 << 5));
        }

        work->unk_030 += work->unk_148;
        work->unk_034 += work->unk_14C;
        work->unk_038 += work->unk_150;
        work->unk_150 += work->unk_154;

        if (work->unk_15E == 7) {
            work->unk_17C = 0;
        }

        if (func_08011F78(231, work->unk_030, work->unk_034, work->unk_038 - 0x2000, 28, 28, 28) == 1) {
            m4aSongNumStart(0x279);
            func_08014020(work->unk_030 - 0x800, work->unk_034 + work->unk_038 - 0x2400, 0);
            work->unk_194 = 0;
            work->unk_160 = 3;
        }

        if (work->unk_000->unk_238 == 7 || work->unk_000->unk_238 == 11) {
            m4aSongNumStart(0x1F9);
            work->unk_17C = 0;
            work->unk_194 = 0;
            work->unk_15C = 0;
            work->unk_160 = 5;
        }

        switch ((s8)func_080C1370(work->unk_030, work->unk_034, work->unk_038 - 0x2000)) {
        case 1:
            m4aSongNumStart(0x1F9);
            func_08014020(work->unk_030 - 0x800, work->unk_034 + work->unk_038 - 0x2400, 0);
            work->unk_194 = 0;
            work->unk_160 = 3;
            break;
        case 2:
            work->unk_194 = 0;
            work->unk_160 = 4;
            break;
        }

        work->unk_15E++;
        break;
    case 5:
        if (MosaicIsActive() == 0) {
            if (work->unk_15C == 0) {
                func_08014020(work->unk_030 - 0x800, work->unk_034 + work->unk_038 - 0x2400, 0);
                work->unk_15C++;
            } else {
                if (AnimIsFinished(&work->anim)) {
                    return 0;
                }

                work->gfx = AnimUpdate(&work->anim);
            }
        }
        break;
    case 3:
        if (AnimIsFinished(&work->anim)) {
            return 0;
        }

        work->gfx = AnimUpdate(&work->anim);
        break;
    default:
        return 0;
    }

    func_080BD7F8(&work->unk_030, &work->unk_034, (s32)&work->unk_038, (s32*)&work->unk_03C);
    TaskPoolUpdate(&work->unk_180);

    return 1;
}

void task_bos_jf_rock_2(JfRockWork* work) {
    JfWork* jf = work->unk_000;
    u16 pal;
    s32 prio;
    s16 x;
    s16 y;

    if (work->unk_15A == 1) {
        if (jf->unk_034 & 4) {
            if (work->unk_030 <= 0x259FF) {
                pal = func_0801AF1C(work->unk_034);
                prio = 0xFD00;
            } else {
                pal = 0x400;
                prio = 0xFFF5;
            }
        } else if (work->unk_030 > 0x1B200) {
            pal = func_0801AF1C(work->unk_034);
            prio = 0xFD00;
        } else {
            pal = 0x400;
            prio = 0xFFF5;
        }

        WorldToScreen(&x, &y, work->unk_030, work->unk_034, work->unk_038);
        DrawSprite(x, y, work->gfx, work->unk_004, work->unk_008, 0, pal, prio);
    }

    if (work->unk_17C == 1) {
        if (jf->unk_034 & 4) {
            pal = 0x400;
        } else {
            pal = 0x400;
            pal |= 1;
        }

        WorldToScreen(&x, &y, work->unk_170, work->unk_174, work->unk_178);
        DrawSprite(x, y, work->unk_16C, work->unk_164, work->unk_168, 0, pal, 0xFFF2);
    }

    if (work->unk_194 == 1) {
        TaskPoolDraw(&work->unk_180);
    }
}

void task_bos_jf_rock_3(JfRockWork* work) {
    ReleaseObjTiles(work->unk_004);
    ReleaseObjPalette(work->unk_008);
    ReleaseObjTiles(work->unk_164);
    ReleaseObjPalette(work->unk_168);
    TaskPoolDestroy(&work->unk_180);
}

u8 func_080C1370(s32 a, s32 b, s32 c) {
    s32 t0 = -((gUnk_0203ACC4 + 1) << 11);
    s32 t1 = -((gUnk_0203ACD4 + 1) << 11);
    s32 t2 = -((gUnk_0203ACC0 + 1) << 11);
    s32 hi = a + 0x1C00;
    s32 lo = a - 0x1C00;
    s32 zh = c + 0x1C00;
    s32 zl = c - 0x1C00;

    if (zh >= t0 && hi > 0x1B200 && lo < 0x1EA00) {
        return 1;
    }

    if (zh >= t1 && hi > 0x1EA00 && lo < 0x22200) {
        return 1;
    }

    if (zh >= t2 && hi > 0x22200 && lo < 0x25A00) {
        return 1;
    }

    if (zl > 0 || lo > 0x2CA00 || hi < 0x14200) {
        return 2;
    }

    return 0;
}

void task_bos_jf_borderline_0(JfBorderlineWork* work, BosPos* arg) {
    work->unk_000 = arg;
    func_080C1A48(work);
    work->unk_0A8 = 0xA00;
    work->unk_0AC = 0x3600;
    work->unk_098 = arg->unk_04 + work->unk_0A4;
    work->unk_09C = arg->unk_08 + work->unk_0A8;
    work->unk_0A0 = arg->unk_0C + work->unk_0AC;
    work->unk_0B0 = 0;
    work->unk_0B2 = 0;
    work->unk_0B4 = 0;
    work->unk_0B5 = 0;
    work->tiles = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->palette = LoadObjPalette(gUnk_096FB5A4, 0x60);
    AnimInit(&work->unk_01C, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->unk_01C, 27, 1);
    work->unk_00C = AnimGetGfx(&work->unk_01C);
    AnimInit(&work->unk_034, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->unk_034, 8, 1);
    work->unk_010 = AnimGetGfx(&work->unk_034);
    AnimInit(&work->unk_04C, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->unk_04C, 7, 1);
    work->unk_014 = AnimGetGfx(&work->unk_04C);
    AnimInit(&work->unk_064, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->unk_064, 28, 1);
    work->unk_018 = AnimGetGfx(&work->unk_064);
    AnimInit(&work->unk_080, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->unk_080, 6, 1);
    work->unk_07C = AnimGetGfx(&work->unk_080);
    func_0801C298(*(u8*)((u8*)work->palette + 6) + 16, 0);
}

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

#ifdef NON_MATCHING
void task_bos_jf_borderline_2(JfBorderlineWork* work) {
    s16 sx;
    s16 sy;

    WorldToScreen(&sx, &sy, work->unk_098, work->unk_09C, work->unk_0A0);

    switch (work->unk_0B5) {
    case 0:
        DrawSprite(sx - 16, sy - 1, work->unk_00C, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 16, sy - 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx, sy + 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 16, sy - 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 16, sy - 1, work->unk_010, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 8, sy + 4, work->unk_00C, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 8, sy + 4, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 8, sy + 4, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 8, sy + 4, work->unk_010, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        break;
    case 1:
        DrawSprite(sx - 40, sy - 1, work->unk_00C, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 40, sy - 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 24, sy + 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 8, sy + 2, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 8, sy + 2, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 24, sy + 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 40, sy - 1, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 40, sy - 1, work->unk_010, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 32, sy + 4, work->unk_00C, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 32, sy + 4, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx - 16, sy + 6, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx, sy + 7, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 16, sy + 6, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 32, sy + 4, work->unk_014, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 32, sy - 4, work->unk_010, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        break;
    }

    DrawSprite(sx, sy - 8, work->unk_07C, work->tiles, work->palette, 0, 0x400, 0xFF00);
}
#else
INCLUDE_ASM("bos2/task_bos_jf_borderline_2.s");
#endif

void task_bos_jf_borderline_3(JfBorderlineWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

void func_080C1A48(JfBorderlineWork* work) {
    JfWork* jf = (JfWork*)work->unk_000;

    switch (jf->unk_238) {
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        if (jf->unk_034 & 4) {
            work->unk_0A4 = -0x500;
        } else {
            work->unk_0A4 = 0x500;
        }
        break;
    case 3:
        if (jf->unk_034 & 4) {
            work->unk_0A4 = -0x100;
        } else {
            work->unk_0A4 = 0x100;
        }
        break;
    case 4:
    case 5:
        if (jf->unk_034 & 4) {
            work->unk_0A4 = 0x1000;
        } else {
            work->unk_0A4 = -0x1000;
        }
        break;
    case 1:
    case 2:
        if (jf->unk_034 & 4) {
            work->unk_0A4 = -0xA00;
        } else {
            work->unk_0A4 = 0xA00;
        }

        work->unk_0B5 = 1;
        return;
    default:
        if (jf->unk_034 & 4) {
            work->unk_0A4 = -0x500;
        } else {
            work->unk_0A4 = 0x500;
        }
        break;
    }

    work->unk_0B5 = 0;
}

#ifdef NON_MATCHING
void task_bos_dsd_0(DsdWork* work, void* arg) {
    s32 v;
    DsdWork* w;
    BosSub* p1;
    BosSub* p2;

    work->unk_358 = 0;

    if (arg != 0) {
        work->unk_358 = 16;
    }

    TaskPoolInit(&work->unk_37C, 4);

    if (work->unk_358 & 16) {
        TaskCreate(&work->unk_37C, gTaskDescBosDsdMap, 0);
    } else {
        TaskCreate((u8*)gBtlWork + 64, gTaskDescBosDsdMap, work);
    }

    work->unk_390 = 0;
    work->unk_392 = 0;

    if (work->unk_358 & 16) {
        work->unk_334 = 9;
    } else {
        work->unk_334 = 1;
    }

    work->unk_338 = 1;
    work->unk_330 = 1;
    work->unk_33C = 0;
    work->unk_34C = 0;
    work->unk_34E = 0;
    work->unk_350 = 0;
    work->unk_352 = 0;
    work->unk_354 = 0;
    work->unk_356 = 0;
    work->unk_35A = 0;
    work->unk_35C = -51;
    v = (s16)(work->unk_358 & 16);

    if (v != 0) {
        work->unk_340 = 0xDC00;
        work->unk_344 = 0x16800;
        work->unk_348 = -0x6400;
        w = work;
        func_0801B37C(w, gUnk_0961A7B0, work->unk_340, work->unk_344, work->unk_348);
        p1 = &w->unk_000[1];
        func_0801B37C(p1, gUnk_0961A7B0, 0xDC00, 0x16800, -0x8C00);
        p2 = &w->unk_000[2];
        func_0801B37C(p2, gUnk_0961A7B0, 0x9000, 0x16800, 0);
        TaskCreate(&w->unk_37C, gTaskDescBosDsdMain, w);
    } else {
        work->unk_340 = 0xDC00;
        work->unk_344 = 0x16800;
        work->unk_348 = -0x6400;
        w = work;
        func_0801B37C(w, gUnk_0961A7B0, work->unk_340, work->unk_344, work->unk_348);
        w->unk_000[0].unk_034 |= 0x1000000;
        w->unk_000[0].unk_034 |= 4;
        p1 = &w->unk_000[1];
        func_0801B37C(p1, gUnk_0961A7B0, work->unk_340, work->unk_344, -0x8C00);
        p1->unk_034 |= 4;
        p1->unk_034 |= 0x400;
        p1->unk_0A2 = v;
        p1->unk_09E = 16;
        p1->unk_0A0 = 16;
        p1->unk_09C = 16;
        p2 = &w->unk_000[2];
        func_0801B37C(p2, gUnk_0961A7B0, 0x9000, 0x16800, v);
        p2->unk_034 |= 0x003C000001000004ULL;
        p2->unk_0A2 = v;
        p2->unk_09E = 16;
        p2->unk_0A0 = 16;
        p2->unk_09C = 32;
        func_080122AC(&p2->unk_040, 7, 16, 32);
        func_08012324(&p2->unk_040, p2->x, p2->y, p2->z);
        func_08012614(&p2->unk_040, 1);
        func_0801BDD4(p2, p1);
        gBtlWork->unk_0D8 = v;
        func_0801C298(0, 1);
        func_0801BCC0(0x6400, 0x16800, 0);
        func_0801C274(0x2800, 0x16800, 0);
        TaskCreate(&w->unk_37C, gTaskDescBosDsdMain, w);
        *(s32*)&gBtlWork->unk_0CC = w->unk_000[0].x;
        gBtlWork->unk_0D0 = w->unk_000[0].y;
        gBtlWork->unk_0D4 = w->unk_000[0].z;
    }
}
#else
INCLUDE_ASM("bos2/task_bos_dsd_0.s");
#endif
u8 task_bos_dsd_1(DsdWork* work) {
    BtlWork* q;
    BosSub* a = work->unk_000;
    BosSub* b = &work->unk_000[1];

    if (work->unk_358 & 0x10) {
        TaskPoolUpdate(&work->unk_37C);
        return 1;
    }

    switch (func_0801ADAC(b)) {
    case 5:
        work->unk_334 = 2;
        b->unk_034 |= 0x1000000;
        work->unk_350 = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->unk_358 |= 1;
        work->unk_34E = 20;
        break;
    case 3:
    case 8:
        work->unk_334 = 11;
        work->unk_350 = 0;
        break;
    case 4:
        work->unk_334 = 8;
        work->unk_350 = 0;
        break;
    }

    if (work->unk_358 & 1) {
        work->unk_34E--;

        if ((s16)work->unk_34E <= 0) {
            work->unk_34C = 0;
            work->unk_358 &= ~1;
            LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
            func_0801AF08(b);

            if (b->unk_02C > 0) {
                switch (work->unk_334) {
                case 0:
                case 1:
                case 4:
                case 5:
                case 8:
                    break;
                default:
                    work->unk_334 = 0;
                    work->unk_350 = 0;
                    break;
                }
            }
        }
    }

    if (func_0801C1C0(0)) {
        work->unk_358 |= 8;
        TaskCreate(&work->unk_37C, gTaskDescBosDsdIta, work);
    }

    if (work->unk_334 == 4) {
        if (((BtlWork*)gBtlWork->unk_07C)->unk_00C <= -0x1000) {
            gBtlWork->unk_0D8 = -30;
        } else {
            gBtlWork->unk_0D8 = 0;
        }
    } else {
        gBtlWork->unk_0D8 = 0;
    }

    TaskPoolUpdate(&work->unk_37C);
    q = gBtlWork;
    *(s32*)&q->unk_0CC = a->x;
    *(s32*)&q->unk_0D0 = a->y;
    *(s32*)&q->unk_0D4 = a->z;

    if (work->unk_358 & 2) {
        return 0;
    }

    return 1;
}

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

#ifdef NON_MATCHING
void task_bos_dsd_main_0(DsdMainWork* work, DsdWork* arg) {
    BosSub* s = &work->unk_074;

    work->unk_000 = arg;
    SetBgPriority(1, 1);
    SetBgPriority(0, 3);
    work->unk_000->unk_334 = arg->unk_334;
    work->unk_008 = 0;
    work->unk_006 = 0;
    work->unk_004 = 0;
    work->unk_00A = 0;
    work->unk_054 = 1;
    work->unk_06C = 0;
    work->unk_070 = gBtlWork->unk_1CA;
    func_0800516C(1, gUnk_09EF2AA4, 2, 2);
    work->unk_00C = LoadObjTiles(gUnk_096983E4, 0x12A0);
    AnimInit(&work->unk_01C, gUnk_09EF3C34, gUnk_09EF3C20);
    AnimStart(&work->unk_01C, 0, 1);
    work->unk_014 = AnimGetGfx(&work->unk_01C);
    work->unk_010 = LoadObjTiles(gUnk_096983E4, 0x12A0);
    AnimInit(&work->unk_034, gUnk_09EF3C4C, gUnk_09EF3C38);
    AnimStart(&work->unk_034, 0, 1);
    work->unk_018 = AnimGetGfx(&work->unk_034);
    work->unk_04C = LoadObjPalette(gUnk_096FB8C4, 32);
    work->unk_050 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_000->unk_360 = AllocObjTiles(0x800, gUnk_096A2F04);
    work->unk_000->unk_364 = LoadObjPalette(gUnk_096FB8E4, 32);
    work->unk_000->unk_368 = LoadObjTiles(gUnk_096869A4, 0x740);
    work->unk_000->unk_36C = LoadObjPalette(gUnk_096FB864, 32);
    work->unk_000->unk_370 = LoadObjPalette(gUnk_096FB884, 32);
    work->unk_000->unk_374 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->unk_000->unk_378 = LoadObjPalette(gUnk_08F69BA4, 32);
    s->x = 0xDC00;
    s->y = 0x16800;
    s->z = 0;
    func_080122AC(&s->unk_040, 8, 24, 100);
    func_08012324(&s->unk_040, s->x, s->y, s->z);
    func_08005244(1, ((gBtlWork->unk_000 - arg->unk_000[0].x) >> 8) + 100,
                  ((gBtlWork->unk_004 - (arg->unk_000[0].y + arg->unk_000[0].z)) >> 8) + 280);
    TaskPoolInit(&work->unk_058, 10);
    func_080C2828(work);
}
#else
INCLUDE_ASM("bos2/task_bos_dsd_main_0.s");
#endif

u8 task_bos_dsd_main_1(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* p = &work->unk_074;

    func_080C2734(work);

    switch (work->unk_000->unk_334) {
    case 0:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C2BB0(work);
        break;
    case 1:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C2944(work);
        break;
    case 2:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C2A2C(work);
        break;
    case 3:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C2CC0(work);
        break;
    case 4:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C2FD8(work);
        break;
    case 5:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C3188(work);
        break;
    case 6:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C3574(work);
        break;
    case 7:
        work->unk_000->unk_330 = work->unk_000->unk_334;
        func_080C3754(work);
        break;
    case 8:
        func_080C386C(work);
        break;
    case 9:
        func_080C3C34(work);
        break;
    case 10:
        func_080C3868(work);
        break;
    case 11:
        func_080C3928(work);
        break;
    }

    func_08012324(&d->unk_000[0].unk_040, d->unk_000[0].x, d->unk_000[0].y, d->unk_000[0].z);
    func_08012324(&p->unk_040, p->x, p->y, p->z);
    TaskPoolUpdate(&work->unk_058);
    work->unk_070 = gBtlWork->unk_1CA;

    return 1;
}

void task_bos_dsd_main_2(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    void* gfx;
    s16 x;
    s16 y;

    if (gBtlWork->unk_070 != 0) {
        LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
        gfx = work->unk_04C;
    } else if (d->unk_358 & 1) {
        if (gFrameCounter & 1) {
            LoadPaletteWithEffect(gUnk_08F69BC4, (void*)0x05000000, 32);
            gfx = work->unk_050;
        } else {
            LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
            gfx = work->unk_04C;
        }
    } else {
        gfx = work->unk_04C;
    }

    func_08005244(1, ((gBtlWork->unk_000 - d->unk_000[0].x) >> 8) + 100,
                  ((gBtlWork->unk_004 - (d->unk_000[0].y + d->unk_000[0].z)) >> 8) + 280);

    if (work->unk_054 == 1) {
        func_0801AF1C(d->unk_000[0].y);
        WorldToScreen(&x, &y, d->unk_000[0].x, d->unk_000[0].y, -0x6400);
        DrawSprite(x - 96, y + 20, work->unk_014, work->unk_00C, gfx, 0, 0x400,
                   (u16)(-4101 - (d->unk_000[0].y >> 8) * 4));
        DrawSprite(x - 96, y + 20, work->unk_018, work->unk_010, gfx, 0, 0x800,
                   (u16)(-4099 - (d->unk_000[0].y >> 8) * 4));
    }

    TaskPoolDraw(&work->unk_058);
}

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
    func_08012304(&work->unk_074.unk_040);
    TaskPoolDestroy(&work->unk_058);
}

void func_080C2734(DsdMainWork* work) {
    BosSub* q = &work->unk_000->unk_000[1];

    if (q->unk_02C > 0) {
        if (GetRandom() % 30 == 0) {
            TaskCreate(&work->unk_058, gTaskDescBosDsdRock, work->unk_000);
        }

        if ((work->unk_000->unk_358 & 0x20) == 0) {
            *(s32*)((u8*)gBtlWork->unk_07C + 4) += work->unk_000->unk_35C;
        }

        if (work->unk_070 != (s8)gBtlWork->unk_1CA) {
            if ((s8)gBtlWork->unk_1CA > 0) {
                work->unk_000->unk_358 |= 0x40;

                if ((s8)gBtlWork->unk_1CA > 14) {
                    work->unk_000->unk_35C = 0x180;
                } else {
                    work->unk_000->unk_35C = ((s8)gBtlWork->unk_1CA << 8) / 10;
                }
            } else if ((s8)gBtlWork->unk_1CA < 0) {
                work->unk_000->unk_358 |= 0x40;
                work->unk_000->unk_35C = ((s8)gBtlWork->unk_1CA << 9) / 10;
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
    p->unk_000[0].z = -0x6400;
    q->z = -0x8C00;
}

void func_080C288C(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* q = &d->unk_000[1];

    if (d->unk_356 >= gUnk_0961A7D0[d->unk_354]) {
        d->unk_356 = 0;
        work->unk_000->unk_354++;

        if (work->unk_000->unk_354 > work->unk_00A + 7) {
            work->unk_000->unk_354 = work->unk_00A;
        }

        func_080C213C(work->unk_000->unk_354, 0x60);
        d->unk_000[0].z += gUnk_0961A82E[work->unk_000->unk_354] << 8;
        q->z += gUnk_0961A82E[work->unk_000->unk_354] << 8;
    }

    work->unk_000->unk_356++;
    work->unk_014 = AnimUpdate(&work->unk_01C);
    work->unk_018 = AnimUpdate(&work->unk_034);
}

void func_080C2944(DsdMainWork* work) {
    func_080C288C(work);

    if (gBtlWork->unk_0A0 != 0) {
        if (GetRandom() % 80 == 0) {
            func_080C3C40(work);
        }
    }
}

void func_080C297C(DsdMainWork* work, s32 x, s32 y, s32 z) {
    BosSub* q = &work->unk_000->unk_000[1];

    func_080062F4(0, 0);
    func_080062F4(0x13, 0);
    func_08006238(0, 0x14, 8);
    func_08018B04(x - 0x1400, y, z - 0xA00, 0x100);
    m4aSongNumStart(0x2D1);
    q->unk_034 |= 0x01000000;
}

void func_080C29F4(DsdMainWork* work) {
    BosSub* q = &work->unk_000->unk_000[1];

    func_080061E8(0, 8);
    func_080062F4(0, 1);
    func_080062F4(19, 1);
    q->unk_034 &= ~0x1000000;
}

void func_080C2A2C(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* q = &d->unk_000[1];
    BosSub* p = &work->unk_074;

    switch (d->unk_350) {
    case 0:
        func_080C297C(work, d->unk_000[0].x, d->unk_000[0].y, d->unk_000[0].z);
        work->unk_006 = 0;
        work->unk_000->unk_350++;
        break;
    case 1:
        work->unk_006++;

        if (work->unk_006 > 11) {
            DisableBg(1);
            work->unk_054 = 0;
            work->unk_000->unk_350++;
        }
        break;
    case 2:
        switch (d->unk_338) {
        case 4:
        case 5:
            func_0801D1C4(&work->unk_058, 1, 0, 0x2C8, 8, (u32)gUnk_09699684);
            break;
        case 6:
            func_0801D1C4(&work->unk_058, 1, 0, 0x280, 8, (u32)gUnk_096A3F44);
            break;
        case 7:
            func_0801D1C4(&work->unk_058, 1, 0, 0x200, 8, (u32)gUnk_096A8BA4);
            break;
        }

        work->unk_006 = 0;
        work->unk_000->unk_350++;
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 9) {
            work->unk_006 = 0;
            d->unk_350++;
        }
        break;
    default:
        work->unk_000->unk_350 = 0;

        switch (work->unk_000->unk_338) {
        case 4:
        case 5:
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = -0x4000;
            work->unk_000->unk_334 = 3;
            break;
        case 6:
            p->x = 0xBC00;
            p->y = 0x16800;
            p->z = 0;
            work->unk_000->unk_334 = 6;
            break;
        case 7:
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = 0;
            work->unk_000->unk_334 = 7;
            break;
        }

        q->unk_034 &= ~0x1000000;
        break;
    }
}

void func_080C2BB0(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* q = &d->unk_000[1];
    BosSub* p = &work->unk_074;

    switch (d->unk_350) {
    case 0:
        func_080C297C(work, d->unk_000[0].x, d->unk_000[0].y, d->unk_000[0].z);
        work->unk_006 = 0;
        work->unk_000->unk_350++;
        break;
    case 1:
        work->unk_006++;

        if (work->unk_006 > 4) {
            DisableBg(1);
            work->unk_000->unk_350++;
        }
        break;
    case 2:
        func_0801D1C4(&work->unk_058, 1, 0, 0x120, 3, (u32)gUnk_096874E4);
        work->unk_006 = 0;
        work->unk_000->unk_350++;
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            func_080C2828(work);
            d->unk_000[0].x = 0xDC00;
            q->x = 0xDC00;
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = 0;
            work->unk_000->unk_350++;
        }
        break;
    case 4:
        if (func_080128EC() == 0) {
            func_080C29F4(work);
            work->unk_000->unk_350++;
        }
        break;
    default:
        d->unk_350 = 0;
        work->unk_000->unk_334 = 1;
        break;
    }
}

void func_080C2CC0(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* q = &d->unk_000[1];

    switch (d->unk_350) {
    case 0:
        work->unk_000->unk_354 = 8;
        work->unk_00A = 8;
        work->unk_000->unk_356 = 0;
        work->unk_006 = 0;
        work->unk_004 = 30;
        func_080C213C(8, 0x80);
        EnableBg(1);
        d->unk_000[0].x = 0x13C00;
        d->unk_000[0].y = 0x16800;
        d->unk_000[0].z = -0xAC00;
        q->x = 0x13C00;
        q->y = 0x16800;
        q->z = -0xD400;
        work->unk_000->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_000->unk_350++;
        break;
    case 2:
        if ((s16)work->unk_004 > 0) {
            ApproachValue(&d->unk_000[0].x, 0xDC00, work->unk_004);
            ApproachValue(&d->unk_000[0].z, -0x9400, work->unk_004);
            ApproachValue(&q->x, 0xDC00, work->unk_004);
            ApproachValue(&q->z, -0xBC00, work->unk_004);
            func_0802F274(d->unk_000[0].x, d->unk_000[0].y + d->unk_000[0].z);
            work->unk_004--;
        } else {
            work->unk_006 = 0;
            work->unk_000->unk_354 = 9;
            func_080C213C(work->unk_000->unk_354, 0x80);
            q->x = 0xEC00;
            q->z = -0x9400;
            work->unk_000->unk_350++;
        }
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->unk_000->unk_354 = 10;
            func_080C213C(work->unk_000->unk_354, 0x80);
            q->x = 0xFC00;
            q->z = -0x9400;
            work->unk_000->unk_350++;
        }
        break;
    case 4:
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->unk_000[0].x += 0x100;
            d->unk_000[0].z += -0x100;
            work->unk_000->unk_350++;
        }
        break;
    case 5:
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->unk_000[0].x += -0x100;
            d->unk_000[0].z += 0x100;
            work->unk_000->unk_350++;
        }
        break;
    case 6:
        work->unk_006++;

        if (work->unk_006 > 25) {
            work->unk_006 = 0;
            work->unk_000->unk_354 = 11;
            func_080C213C(work->unk_000->unk_354, 0x80);
            q->x = 0xEC00;
            q->z = -0x9400;
            work->unk_000->unk_350++;
        }
        break;
    case 7:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->unk_000->unk_354 = 12;
            func_080C213C(work->unk_000->unk_354, 0x80);
            q->x = 0xB400;
            q->z = -0x8400;
            work->unk_000->unk_350++;
        }
        break;
    case 8:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->unk_000->unk_350++;
        }
        break;
    default:
        d->unk_350 = 0;
        work->unk_000->unk_334 = work->unk_000->unk_338;
        break;
    }
}

void func_080C2F68(DsdMainWork* work) {
    if (work->unk_000->unk_356 >= gUnk_0961A7D0[work->unk_000->unk_354]) {
        work->unk_000->unk_356 = 0;
        work->unk_000->unk_354++;

        if (work->unk_000->unk_354 > work->unk_00A + 7) {
            work->unk_000->unk_354 = work->unk_00A;
        }

        func_080C213C(work->unk_000->unk_354, 0x80);
    }

    work->unk_000->unk_356++;
}

void func_080C2FD8(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* a = &d->unk_000[1];
    BosSub* b = &d->unk_000[2];

    switch (d->unk_350) {
    case 0:
        work->unk_000->unk_354 = 13;
        work->unk_00A = 13;
        work->unk_000->unk_356 = 0;
        work->unk_006 = 0;
        func_080C213C(13, 0x80);
        b->x = 0x7600;
        b->y = 0x16800;
        b->z = 0;
        b->unk_034 &= ~0x1000000;
        func_0802F1E8();
        m4aSongNumStart(0x2B9);
        func_0801801C(0x7800, 0x16800, 0, 0x100);
        func_08012614(&b->unk_040, 0);
        work->unk_000->unk_350++;
        break;
    case 1:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->unk_000[0].x += -0x100;
            d->unk_000[0].z += 0x100;
            work->unk_000->unk_350++;
        }
        break;
    case 2:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->unk_000[0].x += 0x100;
            d->unk_000[0].z += -0x100;
            work->unk_000->unk_350++;
        }
        break;
    case 3:
        func_080C2F68(work);

        if (func_080128EC() == 0) {
            func_0801AF08(a);
            work->unk_006 = 0;
            work->unk_000->unk_350++;
        }
        break;
    case 4:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 179) {
            work->unk_006 = 0;
            work->unk_000->unk_350++;
        }
        break;
    case 5:
        func_080C213C(8, 0x80);
        b->unk_034 |= 0x1000000;
        func_08012614(&b->unk_040, 1);
        work->unk_000->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->unk_000->unk_334 = 0;
        break;
    }
}

void func_080C3188(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* a = &d->unk_000[1];
    BosSub* b = &d->unk_000[2];
    BtlWork* e;

    switch (d->unk_350) {
    case 0:
        work->unk_000->unk_354 = 21;
        work->unk_00A = 21;
        work->unk_000->unk_356 = 0;
        func_080C213C(work->unk_000->unk_354, 0x80);
        TaskCreate(&work->unk_058, gTaskDescBosDsdCircle, work->unk_000);
        func_080147D8(0x8000, 0x15400);
        func_08011F78(0x101, 0x8000, 0x16800, -0x1400, 16, 16, 16);
        m4aSongNumStart(0x2BC);
        work->unk_000->unk_350++;
        break;
    case 1:
        if (++work->unk_000->unk_356 >= gUnk_0961A7D0[work->unk_000->unk_354]) {
            work->unk_000->unk_356 = 0;
            work->unk_000->unk_354++;
            a->z += 0x600;

            if (work->unk_000->unk_354 > work->unk_00A + 6) {
                work->unk_000->unk_354 = work->unk_00A + 6;
                work->unk_000->unk_350++;
            }

            func_080C213C(work->unk_000->unk_354, 0x80);
        }
        break;
    case 2:
        work->unk_000->unk_354 = 28;
        work->unk_00A = 28;
        work->unk_000->unk_356 = 0;
        work->unk_006 = 0;
        func_0801AF08(a);
        b->x = 0x9000;
        b->y = 0x16800;
        b->z = 0;
        b->unk_034 &= ~0x1000000;
        work->unk_000->unk_350++;
        break;
    case 3:
        if (++work->unk_000->unk_356 >= gUnk_0961A7D0[work->unk_000->unk_354]) {
            work->unk_000->unk_356 = 0;
            work->unk_000->unk_354++;

            if (work->unk_000->unk_354 > work->unk_00A + 6) {
                work->unk_000->unk_354 = work->unk_00A;
            }

            func_080C213C(work->unk_000->unk_354, 0x80);
        }

        work->unk_006++;

        if (work->unk_006 > 299) {
            work->unk_000->unk_350++;
        }
        break;
    case 4:
        work->unk_000->unk_354 = 27;
        work->unk_00A = 27;
        work->unk_000->unk_356 = 0;
        work->unk_006 = 0;
        b->unk_034 |= 0x1000000;
        work->unk_000->unk_350++;
        break;
    case 5:
        if (++work->unk_000->unk_356 >= gUnk_0961A7D0[work->unk_000->unk_354]) {
            work->unk_000->unk_356 = 0;
            work->unk_000->unk_354--;
            a->z -= 0x600;

            if (work->unk_000->unk_354 < work->unk_00A - 6) {
                work->unk_000->unk_354 = work->unk_00A - 6;

                if (gBtlWork->unk_0EC <= 0 && (work->unk_000->unk_358 & 8) == 0) {
                    _0801C1F8(0, d->unk_000[0].x, d->unk_000[0].y, d->unk_000[0].z);
                }

                work->unk_000->unk_350++;
            }

            func_080C213C(work->unk_000->unk_354, 0x80);
        }
        break;
    case 6:
        work->unk_006 = 0;
        func_080C213C(8, 0x80);
        e = ListPoolFirst(gBtlWork->unk_080);

        while (e != 0) {
            if (e->unk_000 == 0) {
                e->unk_034 |= 0x40;
                m4aSongNumStart(0x227);
            }

            e = ListPoolNext((u8*)e + 0xB8);
        }

        work->unk_000->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->unk_000->unk_334 = 0;
        break;
    }
}

void func_080C3504(DsdMainWork* work) {
    if (work->unk_000->unk_356 >= gUnk_0961A7D0[work->unk_000->unk_354]) {
        work->unk_000->unk_356 = 0;
        work->unk_000->unk_354++;

        if (work->unk_000->unk_354 > work->unk_00A + 4) {
            work->unk_000->unk_354 = work->unk_00A;
        }

        func_080C211C(work->unk_000->unk_354);
    }

    work->unk_000->unk_356++;
}

void func_080C3574(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* q = &d->unk_000[1];

    switch (d->unk_350) {
    case 0:
        work->unk_000->unk_354 = 36;
        work->unk_00A = 36;
        work->unk_000->unk_356 = 0;
        work->unk_004 = 30;
        work->unk_054 = 0;
        func_080C211C(work->unk_000->unk_354);
        q->x = 0xDC00;
        q->z = -0x6000;
        work->unk_000->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_006 = 0;
        work->unk_004 = 0;
        work->unk_000->unk_350++;
        break;
    case 2:
        func_080C3504(work);
        work->unk_184 = TaskCreate(&work->unk_058, gTaskDescBosDsdEnergy1, work->unk_000);
        work->unk_000->unk_350++;
        break;
    case 3:
        func_080C3504(work);

        if (IsTaskActive(work->unk_184) != 0) {
            break;
        }

        if (work->unk_000->unk_35A == 0) {
            work->unk_000->unk_350 = 6;
            break;
        }

        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            work->unk_188 = TaskCreate(&work->unk_058, gTaskDescBosDsdEnergy1, work->unk_000);
            work->unk_000->unk_350++;
        }
        break;
    case 4:
        func_080C3504(work);

        if (IsTaskActive(work->unk_188) != 0) {
            break;
        }

        if (work->unk_000->unk_35A == 1) {
            work->unk_000->unk_350 = 6;
            break;
        }

        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            work->unk_18C = TaskCreate(&work->unk_058, gTaskDescBosDsdEnergy1, work->unk_000);
            work->unk_000->unk_350++;
        }
        break;
    case 5:
        func_080C3504(work);

        if (IsTaskActive(work->unk_18C) != 0) {
            break;
        }

        work->unk_000->unk_350++;
        break;
    case 6:
        func_080C3504(work);
        func_0801AF08(q);
        work->unk_000->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->unk_000->unk_334 = 0;
        break;
    }
}

void func_080C3754(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* q = &d->unk_000[1];

    switch (d->unk_350) {
    case 0:
        work->unk_000->unk_354 = 41;
        work->unk_00A = 41;
        work->unk_000->unk_356 = 0;
        work->unk_004 = 30;
        work->unk_054 = 0;
        func_080C211C(work->unk_000->unk_354);
        work->unk_006 = 0;
        q->x = 0xE400;
        q->z = -0x5C00;
        work->unk_000->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_004 = 0;
        work->unk_000->unk_350++;
        break;
    case 2:
        func_080C3504(work);
        LoadPalette(gUnk_096FB744, (void*)0x05000000, 32);
        work->unk_06C = TaskCreate(&work->unk_058, gTaskDescBosDsdEnergy2, work->unk_000);
        work->unk_000->unk_350++;
        break;
    case 3:
        func_080C3504(work);

        if (IsTaskActive(work->unk_06C) != 0) {
            break;
        }

        work->unk_000->unk_350++;
        break;
    case 4:
        func_080C3504(work);
        func_0801AF08(q);
        work->unk_000->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->unk_000->unk_334 = 0;
        break;
    }
}

void func_080C3868(DsdMainWork* work) {
}

void func_080C386C(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* a = &d->unk_000[1];
    BosSub* b = &d->unk_000[2];

    if (d->unk_330 == 2 || d->unk_330 == 3) {
        func_0801AF08(a);
        b->unk_034 |= 0x1000000;
        func_08012614(&b->unk_040, 1);
        work->unk_000->unk_350 = 0;
        work->unk_000->unk_334 = 0;
    } else if (d->unk_350 > 60) {
        func_0801AF08(a);
        b->unk_034 |= 0x1000000;
        func_08012614(&b->unk_040, 1);
        work->unk_000->unk_350 = 0;
        work->unk_000->unk_334 = 0;
    } else {
        d->unk_350++;
    }
}

void func_080C3928(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* a = &d->unk_000[1];
    BosSub* b = &d->unk_000[2];
    BosSub* c = &work->unk_074;
    BtlWork* e;
    CharaObjParam param;

    switch (d->unk_350) {
    case 0:
        e = ListPoolFirst(gBtlWork->unk_080);

        while (e != 0) {
            if (e->unk_000 == 0) {
                e->unk_034 |= 0x40;
                m4aSongNumStart(0x227);
            }

            e = ListPoolNext((u8*)e + 0xB8);
        }

        work->unk_000->unk_350++;
        break;
    case 1:
        func_0801AF4C(a);
        func_08012614(&a->unk_040, 1);
        func_08012614(&b->unk_040, 1);
        func_08012614(&c->unk_040, 1);
        func_080062F4(0, 0);
        func_080062F4(19, 0);
        func_08006238(0, 20, 8);
        func_08018B04(a->x - 0x1400, a->y, a->z - 0xA00, 0x100);
        m4aSongNumStart(0x2D1);
        work->unk_006 = 0;
        work->unk_000->unk_350++;
        func_0802F274(d->unk_000[0].x - 0x1400, d->unk_000[0].y + d->unk_000[0].z + 0x3000);
        break;
    case 2:
        func_0802F274(d->unk_000[0].x - 0x1400, d->unk_000[0].y + d->unk_000[0].z + 0x3000);
        work->unk_006++;

        if (work->unk_006 > 11) {
            DisableBg(1);
            work->unk_054 = 0;
            work->unk_000->unk_350++;
        }
        break;
    case 3:
        func_080C213C(36, 0xE0);
        EnableBg(1);
        func_0802F274(d->unk_000[0].x - 0x1400, d->unk_000[0].y + d->unk_000[0].z + 0x3000);
        work->unk_000->unk_350++;
        break;
    case 4:
        func_0802F274(d->unk_000[0].x - 0x1400, d->unk_000[0].y + d->unk_000[0].z + 0x3000);

        if (func_080128EC() != 0) {
            break;
        }

        func_080061E8(0, 8);
        func_080062F4(0, 1);
        func_080062F4(19, 1);
        work->unk_000->unk_350++;
        break;
    case 5:
        func_0802F274(d->unk_000[0].x - 0x1400, d->unk_000[0].y + d->unk_000[0].z + 0x3000);
        work->unk_000->unk_350++;
        break;
    case 6:
        func_0802F274(d->unk_000[0].x - 0x1400, d->unk_000[0].y + d->unk_000[0].z + 0x3000);
        param.unk_00 = 0;
        param.unk_04 = 0;
        param.unk_08 = 0;
        param.unk_0C = 0;
        param.unk_10 = 0;
        param.unk_14 = 0;
        param.unk_18 = 0;
        param.unk_1C = 0;
        param.unk_20 = 0x6000000;
        param.unk_24 = 0xE0;
        param.unk_28 = 0x5000000;
        param.unk_2C = 32;
        param.unk_30 = d->unk_000[0].x - 0x1400;
        param.unk_34 = d->unk_000[0].y;
        param.unk_38 = d->unk_000[0].z + 0x3000;
        param.unk_3C = 0;
        param.unk_40 = (u32)a;
        param.unk_44 = 1;
        func_080C6894(&param);
        work->unk_000->unk_350++;
        break;
    case 7:
        if (func_080C69B4() == 0) {
            d->unk_000[0].x = 300;
            d->unk_000[0].y = 0;
            d->unk_000[0].z = 0;
            func_08005244(1, ((gBtlWork->unk_000 - 300) >> 8) + 100, (gBtlWork->unk_004 >> 8) + 280);
            func_0801B008();
            work->unk_000->unk_350++;
        } else {
            func_0802F274(d->unk_000[0].x - 0x1800, d->unk_000[0].y + d->unk_000[0].z + 0x3000);
        }
        break;
    default:
        d->unk_358 |= 2;
        break;
    }
}

void func_080C3C34(DsdMainWork* work) {
    func_080C288C(work);
}

void func_080C3C40(DsdMainWork* work) {
    DsdWork* d = work->unk_000;
    BosSub* a = &d->unk_000[1];

    if (a->unk_02C < a->unk_02E / 3) {
        d->unk_35A = 2;

        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 49) {
            func_08083900(GetRandom() % 2 + 8);
        } else {
            func_08083900(GetRandom() % 3 + 5);
        }
    } else if (a->unk_02C < a->unk_02E / 3 * 2) {
        d->unk_35A = 1;

        if (GetRandom() % 100 <= 29) {
            func_08083900(GetRandom() % 2 + 8);
        } else {
            func_08083900(GetRandom() % 3 + 4);
        }
    } else {
        d->unk_35A = 0;

        if (GetRandom() % 100 <= 59) {
            func_08083900(GetRandom() % 3 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }
    }

    switch (work->unk_000->unk_33C) {
    case 0:
        work->unk_000->unk_338 = 5;
        break;
    case 1:
        work->unk_000->unk_338 = 6;
        break;
    case 2:
        work->unk_000->unk_338 = 4;
        break;
    case 3:
        work->unk_000->unk_338 = 7;
        break;
    default:
        work->unk_000->unk_338 = 0;
        break;
    }

    work->unk_000->unk_33C++;

    if (work->unk_000->unk_33C > 3) {
        work->unk_000->unk_33C = 0;
    }

    func_0801BCD4(a);
}

void task_bos_dsd_map_0(void) {
    LoadBgTiles(0, gUnk_096874E4, 0x8000);
    LoadBgPalette(0, gUnk_096FB744, 0x120);
    func_0800516C(0, gUnk_09EF2E68, 2, 2);
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->unk_008 = 0xA000;
    gBtlWork->unk_00C = 0x13600;
    gBtlWork->unk_000 = 0xA000;
    gBtlWork->unk_004 = 0x13600;
    gBtlWork->unk_010 = 0xA000;
    gBtlWork->unk_014 = 0x13600;
    gBtlWork->unk_01C = 0xA000;
    gBtlWork->unk_020 = 0x13600;
    gBtlWork->unk_01A = 0xF;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}

u8 task_bos_dsd_map_1(void) {
    s32 dx;
    s32 dy;

    func_0802F208();
    dx = (gBtlWork->unk_010 - gBtlWork->unk_008) >> 3;
    dy = (gBtlWork->unk_014 - gBtlWork->unk_00C) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->unk_008 += dx;
    gBtlWork->unk_00C += dy;
    gBtlWork->unk_000 = gBtlWork->unk_008;
    gBtlWork->unk_004 = gBtlWork->unk_00C;

    if (gBtlWork->unk_000 < (gBtlWork->unk_0DA + 0x78) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x78) << 8;
    } else if (gBtlWork->unk_000 > (gBtlWork->unk_0DC - 0x78) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x78) << 8;
    }

    if (gBtlWork->unk_004 < 0x5000) {
        gBtlWork->unk_004 = 0x5000;
    } else if (gBtlWork->unk_004 > (gBtlWork->unk_0E0 - 0x50) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 0x50) << 8;
    }

    gBtlWork->unk_004 += func_0802F268();
    func_08005244(0, (gBtlWork->unk_000 >> 8) - 0x78, (gBtlWork->unk_004 >> 8) - 0x28);

    return 1;
}

void task_bos_dsd_ita_0(DsdItaWork* work, void* arg) {
    work->unk_000 = arg;
    work->unk_074 = 0x1E;
    work->unk_076 = 0;
    work->unk_078 = 0;
    work->unk_07A = 0;
    work->x = 0x12C00;
    work->y = 0x17C00;
    work->z = -0x7800;
    work->unk_06C = 0x100;
    work->unk_070 = 0x19;
    work->unk_07C = 0;
    work->unk_07E = 0;
    work->unk_080 = 0;
    func_080122AC(&work->unk_004, 7, 0x20, 3);
    func_08012324(&work->unk_004, work->x, work->y, work->z);
    work->unk_088 = (u32)gUnk_09EF3BF8[0];
    work->unk_08C = (u32)gUnk_09EF3C18;
}

u8 task_bos_dsd_ita_1(DsdItaWork* work) {
    BosSub* a = &work->unk_000->unk_000[1];

    func_080C427C(work);

    switch (work->unk_07A) {
    case 0:
        if (work->unk_074 > 0) {
            ApproachValue(&work->x, 0x1400, work->unk_074);
            ApproachValue(&work->z, -0x1400, work->unk_074);
            work->unk_074--;
        } else {
            work->unk_07A = 1;
        }
        break;
    case 1:
        if (work->unk_000->unk_358 & 32) {
            work->unk_07A = 2;
        }

        func_080C4398(work);
        break;
    case 2:
        if (work->unk_000->unk_358 & 32) {
            func_080C43E4(&work->x, a->x - 12800);
            func_080C43E4(&work->y, a->y);
            func_080C43E4(&work->z, a->z + 0x500);
        } else if (work->unk_078 > 49) {
            work->unk_07A = 3;
        } else {
            work->unk_078++;
        }

        func_080C4398(work);
        break;
    case 3:
        if (work->z < 0) {
            work->z += work->unk_06C;
            work->unk_06C += work->unk_070;
        } else {
            work->z = 0;
        }

        if (work->unk_000->unk_358 & 32) {
            work->unk_078 = 0;
            work->unk_07A = 2;
        }

        func_080C4398(work);
        break;
    case 4:
        if (work->unk_074 > 0) {
            ApproachValue(&work->x, -0x5000, work->unk_074);
            ApproachValue(&work->z, -0x1400, work->unk_074);
            work->unk_074--;
        } else {
            work->unk_07A++;
        }
        break;
    default:
        work->unk_000->unk_358 &= ~8;
        return 0;
    }

    func_08012324(&work->unk_004, work->x, work->y, work->z);

    return 1;
}

void task_bos_dsd_ita_2(DsdItaWork* work) {
    u16 pal;
    u16 prio;
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_000->unk_358 & 32) {
        pal = 0x800;
        prio = -4100 - ((work->y - 0x4000) >> 8) * 4;
    } else {
        pal = func_0801AF1C(work->y);
        prio = -4102 - (work->y >> 8) * 4;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->unk_088, work->unk_000->unk_368, work->unk_000->unk_36C, 0, pal, prio);

    if (work->z >= 0 && gBtlWork->unk_024 == 0x100) {
        affine = 0;
    } else {
        scale = 0x100 - -work->z / 128;

        if (scale <= 0x7F) {
            scale = 0x80;
        }

        flag = 0;

        if (scale > 0x100) {
            flag = 1;
        }

        affine = AllocObjAffine(0, scale, scale, flag);
    }

    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, work->unk_08C, work->unk_000->unk_368, work->unk_000->unk_370, affine, 0xC00, 0xFFF0);
}

void task_bos_dsd_ita_3(DsdItaWork* work) {
    func_08012304(&work->unk_004);
}

void func_080C427C(DsdItaWork* work) {
    s32 v;
    s16 k;

    if (gBtlWork->unk_0F0 == (u32)&work->unk_004) {
        v = work->unk_000->unk_358 & 32;

        if (v == 0) {
            work->unk_07C |= 1;
            work->unk_000->unk_358 |= 32;
            work->unk_07E = v;
        }
    } else if (work->unk_000->unk_358 & 32) {
        work->unk_000->unk_358 &= ~32;
        work->unk_07C |= 2;
        work->unk_07E = 0;
    }

    if (work->unk_07C & 2) {
        k = gUnk_0961A860[work->unk_07E];
        work->unk_080 -= k << 8;

        if (k == 0) {
            work->unk_07C &= 0xFFFD;
            work->unk_080 = 0;
        } else {
            work->unk_07E++;
        }
    } else if (work->unk_07C & 1) {
        k = gUnk_0961A860[work->unk_07E];
        work->unk_080 += k << 8;

        if (k == 0) {
            work->unk_07C &= 0xFFFE;
        } else {
            work->unk_07E++;
        }
    }
}

void func_080C4398(DsdItaWork* work) {
    if ((s16)work->unk_076 >= 600) {
        work->unk_074 = 30;
        work->unk_07A = 4;
    } else {
        work->unk_076++;
    }

    if (work->unk_000->unk_334 == 11) {
        work->unk_07A = 4;
    }
}

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

void task_bos_dsd_rock_0(DsdRockWork* work, DsdWork* arg) {
    s32 r;
    u8 ang;

    work->unk_00 = arg;
    work->unk_20 = GetRandom() % 2;
    work->unk_1C = gUnk_09EF3BF8[GetRandom() % 3 + 1];

    if (work->unk_00->unk_35C > 0) {
        if (work->unk_20 != 0) {
            r = GetRandom() % 0x301 + 0x700;
            ang = GetRandom() % 13 + 58;
            work->x = gBtlWork->unk_000 - 0x8800;
            work->y = (*(s16*)((u8*)gBtlWork + 0xE0) - 140) << 8;
        } else {
            r = GetRandom() % 0x201 + 0x400;
            ang = -(GetRandom() % 13 + 58);
            work->x = gBtlWork->unk_000 + 0x8800;
            work->y = (*(s16*)((u8*)gBtlWork + 0xDE) - 140) << 8;
        }
    } else {
        if (work->unk_20 != 0) {
            r = GetRandom() % 0x301 + 0x700;
            ang = -(GetRandom() % 13 + 58);
            work->x = gBtlWork->unk_000 + 0x8800;
            work->y = (*(s16*)((u8*)gBtlWork + 0xE0) - 140) << 8;
        } else {
            r = GetRandom() % 0x201 + 0x400;
            ang = GetRandom() % 13 + 58;
            work->x = gBtlWork->unk_000 - 0x8800;
            work->y = (*(s16*)((u8*)gBtlWork + 0xDE) - 140) << 8;
        }
    }

    work->z = (GetRandom() % 101) << 8;
    work->unk_10 = gSineTable[ang] * r >> 8;
    work->unk_18 = -gSineTable[ang + 0x40] * r >> 8;
}

u8 task_bos_dsd_rock_1(DsdRockWork* work) {
    if ((work->unk_00->unk_358 & 0x40) != 0) {
        work->unk_10 = -work->unk_10;
        work->unk_18 = -work->unk_18;
    } else {
        work->x += work->unk_10;
        work->z += work->unk_18;
    }

    if (work->x > gBtlWork->unk_000 + 0x8800 || work->x < gBtlWork->unk_000 - 0x8800) {
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

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->unk_1C, work->unk_00->unk_368, work->unk_00->unk_36C, affine, prio, h);
}

void task_bos_dsd_rock_3(void) {
}

void task_bos_dsd_circle_0(DsdCircleWork* work, void* arg) {
    work->unk_00 = arg;
    work->x = (gUnk_0961A89E[0] << 8) + 0xDC00;
    work->y = (gUnk_0961A8B0[0] << 8) + 0x16800;
    work->z = 0;
    work->unk_14 = 0;
    work->unk_16 = 0;
    work->unk_1A = 0;
    work->unk_1C = 0;
    work->unk_18 = 0;
    work->unk_04 = gUnk_09EF3C50[0];
}

#ifdef NON_MATCHING
u8 task_bos_dsd_circle_1(DsdCircleWork* work) {
    DsdWork* d = work->unk_00;

    if (d->unk_334 == 8 || d->unk_334 == 0) {
        if (work->unk_18 > 66) {
            return 0;
        }

        work->unk_18++;
        return 1;
    }

    switch (d->unk_350) {
    case 1:
        work->unk_1A = work->unk_00->unk_354 - 21;
        work->unk_04 = gUnk_09EF3C50[work->unk_1A];
        work->x = (gUnk_0961A89E[work->unk_1A] << 8) + 0xDC00;
        work->y = (gUnk_0961A8B0[work->unk_1A] << 8) + 0x16800;
        break;
    case 2:
        break;
    case 3:
        work->unk_14++;

        if (work->unk_14 >= gUnk_0961A894[work->unk_16]) {
            work->unk_14 = 0;
            work->unk_16++;

            if (work->unk_16 > 7) {
                work->unk_16 = 0;
            }

            LoadObjPaletteBank(((u16*)work->unk_00->unk_364)[3],
                               &gUnk_096FB904[work->unk_16 * 32]);
        }

        if (work->unk_1C == 60 || work->unk_1C == 110) {
            func_0801BDDC(0, work->x + (GetRandom() % 101 * 256 - 0x3200),
                          work->y + (GetRandom() % 17 * 256 - 0x800), 0);
        }

        work->unk_1C++;
        break;
    case 4:
        LoadObjPaletteBank(((u16*)work->unk_00->unk_364)[3], gUnk_096FB904);
        work->unk_1A = work->unk_00->unk_354 - 21;
        break;
    case 5:
        work->unk_1A = work->unk_00->unk_354 - 21;
        work->unk_04 = gUnk_09EF3C50[work->unk_1A];
        work->x = (gUnk_0961A89E[work->unk_1A] << 8) + 0xDC00;
        work->y = (gUnk_0961A8B0[work->unk_1A] << 8) + 0x16800;
        break;
    case 6:
        work->unk_1A = 0;
        work->unk_04 = gUnk_09EF3C50[work->unk_1A];
        work->x = (gUnk_0961A89E[work->unk_1A] << 8) + 0xDC00;
        work->y = (gUnk_0961A8B0[work->unk_1A] << 8) + 0x16800;
        break;
    case 7:
        return 0;
    }

    if (work->unk_00->unk_334 == 11) {
        if (func_080128EC() == 1) {
            func_08006B4C();
        }

        return 0;
    }

    return 1;
}
#else
INCLUDE_ASM("bos2/task_bos_dsd_circle_1.s");
#endif
















void task_bos_dsd_circle_2(DsdCircleWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
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

u8 task_bos_dsd_energy1_1(DsdEnergy1Work* work) {
    switch (work->unk_34) {
    case 0:
        func_08013EDC(work->unk_04, work->unk_08, work->unk_0C, 0x100);
        work->unk_34++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_08014588(work->unk_04, work->unk_08, work->unk_0C, 0x100, work->unk_3C, 0);
        m4aSongNumStart(0x2BD);
        work->unk_34++;
        break;
    case 2:
        work->unk_38++;

        if (work->unk_38 >= work->unk_3C) {
            work->unk_48 = 1;
            work->unk_38 = 0;
            work->unk_36 = 10;
            work->unk_20 = (gBtlWork->unk_134 - work->unk_08) / 15;
            work->unk_34++;
        }
        break;
    case 3:
        func_080C4C54(work);
        break;
    case 4:
        func_080C4CCC(work);
        break;
    case 5:
        func_0801475C(work->unk_1C, work->unk_20, work->unk_24);
        work->unk_04 += work->unk_1C;
        work->unk_08 += work->unk_20;
        work->unk_0C += work->unk_24;
        break;
    }

    if (func_08011F78(0x102, work->unk_04, work->unk_08, work->unk_0C, 16, 16, 16) == 1) {
        func_08014790(0);
        m4aSongNumStart(0x2A1);
        work->unk_48 = 0;
        return 0;
    }

    if (work->unk_0C >= -0x800 || work->unk_04 <= -0x2000 || work->unk_04 > 0x11FFF ||
        work->unk_00->unk_334 == 8 || work->unk_00->unk_334 == 11) {
        func_08014790(0);
        work->unk_48 = 0;
        return 0;
    }

    return 1;
}

void task_bos_dsd_energy1_2(DsdEnergy1Work* work) {
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_48 == 1) {
        if (work->unk_0C >= 0 && gBtlWork->unk_024 == 0x100) {
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

void task_bos_dsd_energy1_3(void) {
}

void func_080C4C54(DsdEnergy1Work* work) {
    work->unk_1C = gSineTable[work->unk_28] * work->unk_2C >> 8;
    work->unk_24 = -gSineTable[work->unk_28 + 0x40] * work->unk_2C >> 8;
    work->unk_2C -= 76;
    work->unk_28 -= 3;
    work->unk_04 += work->unk_1C;
    work->unk_08 += work->unk_20;
    work->unk_0C += work->unk_24;
    func_0801475C(work->unk_1C, work->unk_20, work->unk_24);

    if ((s16)work->unk_38 > 15) {
        work->unk_34++;
    } else {
        work->unk_38++;
    }
}

void func_080C4CCC(DsdEnergy1Work* work) {
    u16 d;

    if (work->unk_40 > 0) {
        work->unk_40 = 0;
        work->unk_29 = GetAngle(work->unk_04, work->unk_0C, gBtlWork->unk_130, gBtlWork->unk_138);

        if (work->unk_29 >= work->unk_28) {
            d = work->unk_29 - work->unk_28;

            if ((s16)d > 10) {
                d = 10;
            }
        } else {
            d = work->unk_29 - work->unk_28;

            if ((s16)d < -10) {
                d = -10;
            }
        }

        work->unk_28 += d;
        work->unk_1C = gSineTable[work->unk_28] * work->unk_2C >> 8;
        work->unk_20 = 0;
        work->unk_24 = -gSineTable[work->unk_28 + 0x40] * work->unk_2C >> 8;
    }

    work->unk_40++;
    work->unk_2C += 25;
    func_0801475C(work->unk_1C, work->unk_20, work->unk_24);
    work->unk_04 += work->unk_1C;
    work->unk_08 += work->unk_20;
    work->unk_0C += work->unk_24;
}

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

u8 task_bos_dsd_energy2_1(DsdEnergy2Work* work) {
    BtlWork* p;

    switch (work->unk_2C) {
    case 0:
        func_080147C8(work->unk_10, work->unk_14);
        work->unk_10 += 25;
        work->unk_14 += 25;

        if (work->unk_30 >= work->unk_32) {
            func_0802F274(work->unk_04, work->unk_08 + work->unk_0C);
            work->unk_2C++;
        } else {
            work->unk_30++;
        }
        break;
    case 1:
        func_0801475C(work->unk_20, work->unk_24, work->unk_28);
        work->unk_04 += work->unk_20;
        work->unk_08 += work->unk_24;
        work->unk_0C += work->unk_28;
        func_0802F274(work->unk_04, work->unk_08 + work->unk_0C);

        if (work->unk_0C <= -0xF000) {
            work->unk_2C++;
        }
        break;
    case 2:
        func_08017F70(work->unk_04, work->unk_08, work->unk_0C, 0x103);
        m4aSongNumStart(0x2C1);
        func_0802F274(work->unk_04, work->unk_08 + work->unk_0C);
        work->unk_2C++;
        break;
    case 3:
        func_0802F274(work->unk_04, work->unk_08 + work->unk_0C);

        if (func_080128EC() == 0) {
            work->unk_2C++;
        }
        break;
    case 4:
        func_08006238(0, gBtlWork->unk_0B3, 8);
        work->unk_2C++;
        break;
    case 5:
        work->unk_04 = (p = (BtlWork*)gBtlWork->unk_07C)->unk_004 + (-0x4000 + GetRandom() % 0x8001);

        if (work->unk_04 < -0xFFF || work->unk_04 > 0x10FFF) {
            work->unk_04 = p->unk_004;
        }

        work->unk_08 = ((BtlWork*)gBtlWork->unk_07C)->unk_008 - 0x2400 + GetRandom() % 0x4001;
        work->unk_0C = -0xF000;
        work->unk_28 = 0x600;
        func_08014588(work->unk_04, work->unk_08, work->unk_0C, 0x100, work->unk_32, 0);
        work->unk_3C = 1;
        work->unk_30 = 0;
        work->unk_2C++;
        break;
    case 6:
        func_0801475C(0, 0, work->unk_28);
        work->unk_0C += work->unk_28;

        if (func_08011F78(0x104, work->unk_04, work->unk_08, work->unk_0C, 16, 16, 16) == 1) {
            m4aSongNumStart(0x29E);
            func_08014790(0);
            work->unk_3C = 0;
            work->unk_2C = 7;
        }

        if (work->unk_0C >= -0x800) {
            func_08014790(0);
            m4aSongNumStart(0x2BF);
            work->unk_3C = 0;
            work->unk_2C = 7;
        }

        work->unk_30++;
        break;
    case 7:
        if (work->unk_34 >= (s8)work->unk_35 - 1) {
            if (func_080128EC() == 0) {
                func_08006B4C();
                func_080061E8(0, 8);
                work->unk_2C++;
            }

            return 1;
        }

        if (work->unk_30 > 49) {
            work->unk_30 = 0;
            work->unk_34++;
            work->unk_2C = 5;
        } else {
            work->unk_30++;
        }
        break;
    default:
        return 0;
    }

    if (work->unk_00->unk_334 == 8 || work->unk_00->unk_334 == 11) {
        if (func_080128EC() == 1) {
            func_08006B4C();
            func_080061E8(0, 8);
        }

        work->unk_3C = 0;
        return 0;
    }

    return 1;
}

void task_bos_dsd_energy2_2(DsdEnergy2Work* work) {
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_3C == 1) {
        if (work->unk_0C >= 0 && gBtlWork->unk_024 == 0x100) {
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
