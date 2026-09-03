#include "macros.h"
#include "bos7.h"

void task_bos_lst_fld_0(LstFldWork* work, LstFldArg* arg) {
    vu32* dma;
    s32 i;

    LoadBgTiles(0, arg->unk_00, arg->unk_04);
    LoadBgPalette(0, arg->unk_08, arg->unk_0C);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0xF800;
    gUnk_02039B84->unk_00C = 0x1F000;
    gUnk_02039B84->unk_000 = 0xF800;
    gUnk_02039B84->unk_004 = 0x1F000;
    gUnk_02039B84->unk_010 = 0xF800;
    gUnk_02039B84->unk_014 = 0x1F000;
    gUnk_02039B84->unk_01C = 0xF800;
    gUnk_02039B84->unk_020 = 0x1F000;
    gUnk_02039B84->unk_01A = 15;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_0810FE94();
    dma = (vu32*)0x040000D4;
    dma[0] = (vu32)gUnk_09A4D234;
    dma[1] = (vu32)work->unk_0C4;
    dma[2] = 0x80000340;
    dma[2];
    dma[0] = (vu32)gUnk_09A4F2B4;
    dma[1] = (vu32)work->unk_744;
    dma[2] = 0x800004A0;
    dma[2];

    for (i = 0; i < 0x1A0; i++) {
        work->unk_0C4[i] = (gSineTable[(i + 64) & 255] >> 1) & 0x1FF;
    }

    work->unk_000 = 0;
    work->unk_01C = 0;
    work->unk_004 = 0;
    work->unk_008 = 0;
    work->unk_00C = 0;
    work->unk_018 = 0;
    work->unk_020 = 0;
    work->unk_022 = 0;
    work->unk_010 = 0;
    work->unk_014 = 0;
}

void func_08110058(u16* dst, u16* src, s32 count, s32 level) {
    s32 c;
    s32 m;
    s32 v;

    level = level <= 31 ? 31 & ~level : 0;
    count--;

    while (count != -1) {
        v = src[count];
        m = 0x1F;
        c = (v & m) * level >> 5 & m;
        m <<= 5;
        c |= (v & m) * level >> 5 & m;
        m <<= 5;
        c |= (v & m) * level >> 5 & m;
        dst[count] = c;
        count--;
    }
}

u8 task_bos_lst_fld_1(LstFldWork* work) {
    s32 a;
    s32 b;
    s32 i;

    func_0802F208();

    switch (work->unk_000) {
    case 1:
        a = ((gUnk_02039B84->unk_0CC >> 8) - gUnk_02039B84->unk_008) >> 3;
        b = (gUnk_02039B84->unk_0D0 + gUnk_02039B84->unk_0D4 - gUnk_02039B84->unk_00C) >> 3;
        break;
    case 2:
        a = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
        b = (gUnk_02039B84->unk_07C->unk_08 + gUnk_02039B84->unk_07C->unk_0C -
              gUnk_02039B84->unk_00C) >> 3;
        if (b > 256) {
            b = 256;
        }
        if (b < -256) {
            b = -256;
        }
        break;
    default:
        a = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;

        if (gUnk_02039B84->unk_068 & 0x2000000000000) {
            b = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;
        } else if (gUnk_02039B84->unk_068 & 0x200000) {
            if (gUnk_02039B84->unk_07C->unk_0C < -0xA000) {
                b = (gUnk_02039B84->unk_07C->unk_08 + gUnk_02039B84->unk_07C->unk_0C -
                      gUnk_02039B84->unk_00C) >> 3;
            } else {
                b = 0;
            }
        } else {
            b = (gUnk_02039B84->unk_07C->unk_08 + gUnk_02039B84->unk_07C->unk_0C -
                  gUnk_02039B84->unk_00C) >> 3;
        }
        break;
    }

    if (a > 0x500) {
        a += 0x500;
    } else if (a < -0x500) {
        a += -0x500;
    }

    gUnk_02039B84->unk_008 += a;
    gUnk_02039B84->unk_00C += b;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;
    func_0810FEDC();

    if (gUnk_02039B84->unk_000 < (gUnk_02039B84->unk_0DA + 120) << 8) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 120) << 8;
    } else if (gUnk_02039B84->unk_000 > (gUnk_02039B84->unk_0DC - 120) << 8) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 120) << 8;
    }

    if (gUnk_02039B84->unk_004 + 0x5000 > gUnk_02039B84->unk_0E0 << 8) {
        gUnk_02039B84->unk_004 = (gUnk_02039B84->unk_0E0 - 80) << 8;
    }

    work->unk_018++;
    func_08116E8C();

    switch (work->unk_004) {
    case 0:
        work->unk_020 -= work->unk_00C * 4;

        for (i = 0; i <= 23; i++) {
            work->unk_1084[work->unk_018 & 1][i] = ((u32)work->unk_020 * 3 / 4) & 0x1FF;
        }
        for (; i <= 31; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 47 >> 6) & 0x1FF;
        }
        for (; i <= 39; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 46 >> 6) & 0x1FF;
        }
        for (; i <= 47; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 44 >> 6) & 0x1FF;
        }
        for (; i <= 55; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 42 >> 6) & 0x1FF;
        }
        for (; i <= 63; i++) {
            work->unk_1084[work->unk_018 & 1][i] = ((u32)work->unk_020 * 5 / 8) & 0x1FF;
        }
        for (; i <= 71; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 38 >> 6) & 0x1FF;
        }
        for (; i <= 79; i++) {
            work->unk_1084[work->unk_018 & 1][i] = ((u32)work->unk_020 * 9 / 16) & 0x1FF;
        }
        for (; i <= 159; i++) {
            work->unk_1084[work->unk_018 & 1][i] = work->unk_020 & 0x1FF;
        }

        func_08116E60(work->unk_1084[work->unk_018 & 1]);
        func_08116E80();
        break;
    case 1:
        work->unk_022 -= work->unk_00C * 4;
        func_08116E60(&work->unk_744[work->unk_018 & 0x3FF]);
        func_08116E80();
        break;
    case 3:
        work->unk_020 -= work->unk_01C * work->unk_00C;
        func_08116E60(&work->unk_0C4[(u8)work->unk_018]);
        func_08116E80();
        break;
    case 2:
        work->unk_020 -= work->unk_00C * 3;
        work->unk_022 += 3;

        for (i = 0; i <= 127; i++) {
            work->unk_1084[work->unk_018 & 1][i] = work->unk_022 & 0x1FF;
        }
        for (; i <= 159; i++) {
            a = ~(i * 2 - 256);
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_022 + a) & 0x1FF;
        }

        func_08116E60(work->unk_1084[work->unk_018 & 1]);
        func_08116E80();
        break;
    }

    SetBgScroll(0, work->unk_020, work->unk_022);

    if (work->unk_008 == 31) {
        work->unk_004 = work->unk_010;
        work->unk_00C = work->unk_014;
        work->unk_020 = 0;
        work->unk_022 = 0;

        switch (work->unk_010) {
        case 0:
            LoadBgMap(0, gUnk_09D4B274, 0x800);
            func_08116E00(0x04000010, work->unk_1084[work->unk_018 & 1], 0xA2600001);
            break;
        case 1:
            LoadBgMap(0, gUnk_09D4BA74, 0x800);
            func_08116E00(0x04000010, work->unk_744, 0xA2600001);
            break;
        case 2:
            work->unk_020 = -(work->unk_014 * 120);

            if (work->unk_014 > 0) {
                LoadBgMap(0, gUnk_09D4C274, 0x800);
            } else {
                LoadBgMap(0, gUnk_09D4CA74, 0x800);
            }

            func_08116E00(0x04000012, work->unk_1084[work->unk_018 & 1], 0xA2600001);
            break;
        case 3:
            work->unk_01C = 0;
            LoadBgMap(0, gUnk_09D4C274, 0x800);
            func_08116E00(0x04000012, work->unk_0C4, 0xA2600001);
            break;
        default:
            LoadBgMap(0, gUnk_09D4D274, 0x800);
            break;
        }
    }

    if (work->unk_008 <= 63) {
        func_08110058(work->unk_024, gUnk_09D694F4, 80, gUnk_09A4FC20[work->unk_008]);
        LoadPalette(work->unk_024, 0x050000A0, 160);
        work->unk_008++;
    }

    return 1;
}

void task_bos_lst_fld_2(void) {
}

void task_bos_lst_fld_3(LstFldWork* work) {
    func_08116CEC();
}

s32 func_08110658(s32 x) {
    return x * x;
}

s32 func_08110660(s32 x) {
    return x * x;
}

u8 func_08110668(LstWork* work) {
    LstState* s;

    s = work->unk_04;
    return s->unk_000 != 4;
}

void task_bos_lst_edg_0(LstEdgWork* work, LstEdgArg* arg) {
    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_006 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->unk_010 = arg->unk_0C;
    work->unk_014 = arg->unk_04;
    work->unk_018 = arg->unk_08;
    work->unk_01C = arg->unk_0C;
    work->unk_044 = (u32)AllocObjTiles(0x80, gUnk_09C5C4E2);
    work->unk_048 = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->unk_02C, gUnk_09EFAF1C, gUnk_09EFAEF8);
    AnimStart(&work->unk_02C, 0, 1);
}

u8 task_bos_lst_edg_1(LstEdgWork* work) {
    LstPos* p;

    switch (work->unk_000) {
    case 0:
        work->unk_006--;
        if (work->unk_006 <= 0) {
            work->unk_000 = 1;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
            p = gUnk_02039B84->unk_07C;
            work->unk_020 = p->unk_04;
            work->unk_024 = p->unk_08;
            work->unk_028 = -0x1000;
        }
        break;
    case 1:
        work->unk_020 = gUnk_02039B84->unk_07C->unk_04;
        func_0800592C(&work->unk_008, work->unk_020, 30);
        func_0800592C(&work->unk_00C, work->unk_024, 30);
        func_0800592C(&work->unk_010, work->unk_028, 30);
        work->unk_004++;
        if (work->unk_004 > 49) {
            work->unk_000 = 2;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
        }
        func_08011F78(0x10C, work->unk_008, work->unk_00C, work->unk_010, 8, 8, 1);
        break;
    case 2:
        func_0800592C(&work->unk_008, work->unk_014, 30);
        func_0800592C(&work->unk_00C, work->unk_018, 30);
        func_0800592C(&work->unk_010, work->unk_01C, 30);
        work->unk_004++;
        if (work->unk_004 > 49) {
            work->unk_000 = 3;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
        }
        func_08011F78(0x10C, work->unk_008, work->unk_00C, work->unk_010, 8, 8, 1);
        break;
    case 3:
        work->unk_000 = 4;
        work->unk_002 = 0;
        work->unk_004 = 0;
        work->unk_006 = 0;
        break;
    case 4:
        AnimStart(&work->unk_02C, 1, 1);
        break;
    }

    AnimUpdate(&work->unk_02C);

    return 1;
}

void task_bos_lst_edg_2(LstEdgWork* work) {
    s16 x;
    s16 y;
    u16 prio;
    u16 z;
    void* gfx;

    WorldToScreen(&x, &y, work->unk_008, work->unk_00C, work->unk_010);
    prio = func_0801AF1C(work->unk_00C);
    z = -0x1004 - (work->unk_00C >> 8) * 4;
    gfx = AnimGetGfx(&work->unk_02C);
    DrawSprite(x, y, gfx, (void*)work->unk_044, (void*)work->unk_048, 0, prio, z);
}

void task_bos_lst_edg_3(LstEdgWork* work) {
    ReleaseObjTiles((void*)work->unk_044);
    ReleaseObjPalette((void*)work->unk_048);
}

s32 func_0811089C(s32 x) {
    return x * x;
}

s32 func_081108A4(s32 x) {
    return x * x;
}

u8 func_081108AC(LstState* work, s32 kind) {
    LstFalArg arg;
    u8 result;

    result = 0;

    if (work->unk_00E != 0) {
        return 0;
    }

    if ((s16)*work->unk_020 <= 31) {
        arg.unk_00 = 0;
        if (kind == 1) {
            arg.unk_04 = work->unk_050;
            arg.unk_08 = work->unk_054;
            arg.unk_0C = work->unk_058;
        } else {
            arg.unk_04 = work->unk_028;
            arg.unk_08 = work->unk_02C;
            arg.unk_0C = work->unk_030;
        }
        arg.unk_12 = *work->unk_01C;
        arg.unk_14 = work->unk_020;
        TaskCreate(gUnk_02039B84->unk_040, gUnk_09EF9F0C, &arg);
        result = 1;
    }

    return result;
}

u8 func_08110918(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->unk_04;
    result = 1;

    if (s->unk_0A0.unk_2C <= 0 || s->unk_002 == 6) {
        result = 0;
    }

    return result;
}

u8 func_08110938(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->unk_04;
    result = func_08110918(work);

    if (result == 1 && s->unk_012 <= 0) {
        result = 0;
    }

    return result;
}

s16 func_0811095C(LstWork* work, u16 a) {
    LstState* s;

    s = work->unk_04;

    if (func_08110918(work) == 1 && a == 0) {
        s->unk_010 = a;
        a = 1;
    }

    return a;
}

void func_08110984(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->unk_04;
    zero = 0;
    s->unk_002 = 1;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
}

void func_08110994(LstWork* work, u16 a) {
    LstState* s;
    u16 zero;

    s = work->unk_04;
    zero = 0;
    s->unk_002 = 2;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
    s->unk_012 = a;
}

#ifndef VERSION_EU
void func_081109A8(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->unk_04;
    zero = 0;
    s->unk_002 = 5;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
}
#else
INCLUDE_ASM("bos7/func_081109A8.s");
#endif

u8 func_081109B8(LstWork* work, u8 a) {
    LstState* s;
    u8 result;

    s = work->unk_04;
    result = 0;
    func_08111660(s->unk_1C4);
    func_08111660(s->unk_1C8);
    func_08111660(s->unk_1CC);
    s->unk_012 = 0;

    if (s->unk_002 >= 5 && s->unk_002 <= 6) {
        return 0;
    }

    if (a == 1 && s->unk_010 == 0) {
        s->unk_0A0.unk_2C = 0;
        func_0801C2DC(&s->unk_0A0, 1);
        func_081108AC(s, 0);
        func_081108AC(s, 0);
        result = 1;
    }

    s->unk_002 = 7;
    s->unk_004 = 0;
    s->unk_006 = 0;
    s->unk_008 = 0;

    return result;
}

s32 func_08110A38(s32 a, s32 b) {
    s32 v;
    s32 step;
    s32 i;

    if (a == 0 || b == 0) {
        return 0;
    }

    v = (b << 8) / a;
    if (v <= gUnk_09A4FD5C[0]) {
        return 0;
    }

    step = 8;
    i = 16;
    while (step != 0 && v != gUnk_09A4FD5C[i]) {
        if (v < gUnk_09A4FD5C[i]) {
            i -= step;
        } else {
            i += step;
        }
        step /= 2;
    }

    return i;
}

s32 func_08110A98(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    s32 a;

    dx = x0 - x1;
    dy = y0 - y1;

    if (abs(dx) >= abs(dy)) {
        a = func_08110A38(abs(dx), abs(dy));
    } else {
        a = 63 - func_08110A38(abs(dy), abs(dx));
    }

    if (dx >= 0) {
        if (dy >= 0) {
            a = 63 - a;
            a = a + 192;
        }
    } else if (dy >= 0) {
        a = a + 128;
    } else {
        a = 63 - a;
        a = a + 64;
    }

    a = 255 - a;
    a = a + 65;

    return a & 255;
}

s32 func_08110B10(u8 a, u8 b) {
    s32 d;

    if (a > b) {
        d = a - b;
        if (d > 128) {
            d = d - 256;
        }
        return -d;
    }

    d = b - a;
    if (d > 128) {
        d = d - 256;
    }

    return d;
}

void task_bos_lst_bit_0(LstState* work, LstBitArg* arg) {
    LstBitSubArg sub;
    LstPos* p;
    void* pool;

    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    work->unk_008 = 0;
    work->unk_00A = 0;
    work->unk_00C = 0;
    work->unk_00E = arg->unk_00;
    work->unk_010 = arg->unk_04;
    work->unk_012 = 0;
    work->unk_014 = GetRandom() % 32;
    work->unk_01C = arg->unk_08;
    work->unk_020 = arg->unk_0C;
    work->unk_024 = arg->unk_10;
    work->unk_028 = arg->unk_14;
    work->unk_02C = arg->unk_18;
    work->unk_030 = arg->unk_1C;
    work->unk_044 = arg->unk_14;
    work->unk_048 = arg->unk_18;
    work->unk_04C = arg->unk_1C;
    work->unk_040 = 0;
    work->unk_050 = arg->unk_20;
    work->unk_054 = arg->unk_24;
    work->unk_058 = arg->unk_28;
    p = gUnk_02039B84->unk_07C;
    work->unk_068 = p->unk_04;
    work->unk_06C = p->unk_08;
    work->unk_070 = p->unk_0C;
    work->unk_016 = arg->unk_04 << 7;
    work->unk_074 = 2;
    work->unk_078 = 2;
    work->unk_094 = (u32)LoadObjTiles(gUnk_09CD0334, 0x900);
    work->unk_098 = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    work->unk_09C = (u32)LoadObjPalette(gUnk_08F69BC4, 0x20);
    AnimInit(&work->unk_07C, gUnk_09EFBF18, gUnk_09EFBEC4);
    AnimStart(&work->unk_07C, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
    func_0801B37C(&work->unk_0A0, gUnk_09A4FD4C, work->unk_028, work->unk_02C, work->unk_030);
    pool = &work->unk_1B0;
    TaskPoolInit(pool, 4);
    sub.unk_00 = work->unk_00E;
    sub.unk_04 = work->unk_01C;
    sub.unk_08 = work->unk_020;
    work->unk_1C4 = TaskCreate(pool, gUnk_09EF9EDC, &sub);
    work->unk_1C8 = TaskCreate(pool, gUnk_09EF9EDC, &sub);
    work->unk_1CC = TaskCreate(pool, gUnk_09EF9EDC, &sub);
}

void func_08110C9C(LstState* work) {
    void* anim;

    anim = &work->unk_0A0;

    switch (func_0801ADAC(anim)) {
    case 1:
    case 6:
    case 7:
        work->unk_00A = 20;
        func_081108AC(work, 0);
        func_0801AF08(anim);
        break;
    case 3:
        func_0801C2DC(&work->unk_0A0, 1);
        func_081108AC(work, 0);
        func_081108AC(work, 0);
        func_0801AF08(anim);
        break;
    case 5:
        func_0801AF08(anim);
        break;
    case 4:
        func_0801AF08(anim);
        break;
    case 2:
        break;
    }
}

u8 task_bos_lst_bit_1(LstState* work) {
    Vec3 a;
    Vec3 b;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    LstPos* p;
    s32 d;
    u8 dir;
    LstObj* obj;

    obj = &work->unk_0A0;

    if (obj->unk_2C <= 0) {
        func_0801C2DC(obj, 1);
        return 1;
    }

    func_08110C9C(work);

    switch (work->unk_002) {
    case 0:
        func_0800592C(&work->unk_028, work->unk_050, 20);
        func_0800592C(&work->unk_02C, work->unk_054, 20);
        func_0800592C(&work->unk_030, work->unk_058, 20);
        func_0800592C(&work->unk_074, 0x100, 32);
        func_0800592C(&work->unk_078, 0x100, 32);
        work->unk_006++;

        if (work->unk_006 > 29) {
            work->unk_002 = 1;
            work->unk_004 = 0;
            work->unk_006 = 0;
            work->unk_008 = 0;
            work->unk_074 = 0x100;
            work->unk_078 = 0x100;
        }
        break;
    case 1:
        if (work->unk_006 == 0) {
            if (gUnk_02039B84->unk_068 & 0x2000000000000) {
                work->unk_050 = (GetRandom() % 113 << 8) + 0xC000;
                work->unk_054 = gUnk_02039B84->unk_07C->unk_08;
            } else if (work->unk_00E == 0) {
                work->unk_050 = (GetRandom() % 113 << 8) + 0xC000;
                work->unk_054 = gUnk_02039B84->unk_07C->unk_08 + (gUnk_09A4FDDC[work->unk_010] << 8);
            } else {
                work->unk_050 = gUnk_02039B84->unk_07C->unk_04;
                work->unk_054 = gUnk_02039B84->unk_07C->unk_08;
            }

            func_08005B64(&work->unk_07C);
            AnimChange(&work->unk_07C, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
        }

        if (!(gUnk_02039B84->unk_068 & 0x2000000000000)) {
            if (gUnk_02039B84->unk_07C->unk_0C > -0xC000) {
                work->unk_058 = -0x6000;
            } else {
                work->unk_058 = gUnk_02039B84->unk_0D4 - 0x5000;
            }
        }

        work->unk_006++;

        if ((work->unk_014 & 31) == 0) {
            func_081108AC(work, 0);
        }

        func_0800592C(&work->unk_028, work->unk_050, 20);
        func_0800592C(&work->unk_02C, work->unk_054, 20);
        func_0800592C(&work->unk_030, work->unk_058, 20);
        break;
    case 2:
        if (work->unk_006 == 0) {
            work->unk_050 = gUnk_02039B84->unk_07C->unk_04;
            work->unk_054 = gUnk_02039B84->unk_07C->unk_08;

            if (gUnk_02039B84->unk_07C->unk_0C > -0xC000) {
                work->unk_058 = 0;
            } else {
                work->unk_058 = gUnk_02039B84->unk_0D4;
            }

            func_08005B64(&work->unk_07C);
            AnimChange(&work->unk_07C, gUnk_09EF9EA4[work->unk_000].unk_02, 0);
        }

        work->unk_006++;

        if (func_08005B30(&work->unk_07C) == (s16)gUnk_09EF9EA4[work->unk_000].unk_02 && AnimIsFinished(&work->unk_07C) == 1) {
            work->unk_002 = 3;
            work->unk_006 = 0;
            work->unk_018 = 1;
            work->unk_01A = work->unk_01B;
            work->unk_05C = work->unk_028 + work->unk_034;
            work->unk_060 = work->unk_02C + work->unk_038;
            work->unk_064 = work->unk_030 + work->unk_03C;
            m4aSongNumStart(0x2C4);
            func_08005B64(&work->unk_07C);
            AnimChange(&work->unk_07C, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
        }
        break;
    case 3:
        if (work->unk_006 == 0) {
            if (func_081115B4(work->unk_1C4) == 0) {
                a.x = work->unk_05C;
                a.y = work->unk_060;
                a.z = work->unk_064;
                b.x = work->unk_050;
                b.y = work->unk_054;
                b.z = work->unk_058;
                func_081115CC(work->unk_1C4, &a, &b, work->unk_01A, 0);
            }

            work->unk_006++;
        } else {
            work->unk_050 = gUnk_02039B84->unk_07C->unk_04;
            work->unk_054 = gUnk_02039B84->unk_07C->unk_08;

            if (gUnk_02039B84->unk_07C->unk_0C > -0xC000) {
                work->unk_058 = 0;
            } else {
                work->unk_058 = gUnk_02039B84->unk_0D4;
            }

            if (func_081115B4(work->unk_1C4) == 0) {
                if (work->unk_012 > 1) {
                    work->unk_002 = 2;
                    work->unk_006 = 0;
                    work->unk_012--;
                } else {
                    work->unk_012 = 0;
                }
            }
        }
        break;
    case 4:
        if (work->unk_006 > 14) {
            break;
        }

        func_08011F78(0x10D, work->unk_050, work->unk_054, work->unk_058, 8, 8, 8);

        if ((work->unk_006 & 3) == 0) {
            func_081108AC(work, 1);
        }

        if (abs(work->unk_050 - gUnk_02039B84->unk_07C->unk_04) < 0x180) {
            work->unk_050 = gUnk_02039B84->unk_07C->unk_04;
        } else if (work->unk_050 > gUnk_02039B84->unk_07C->unk_04) {
            work->unk_050 = work->unk_050 - 0x180;
        } else if (work->unk_050 < gUnk_02039B84->unk_07C->unk_04) {
            work->unk_050 = work->unk_050 + 0x180;
        }

        if (abs(work->unk_054 - gUnk_02039B84->unk_07C->unk_08) < 0x180) {
            work->unk_054 = gUnk_02039B84->unk_07C->unk_08;
        } else if (work->unk_054 > gUnk_02039B84->unk_07C->unk_08) {
            work->unk_054 = work->unk_054 - 0x180;
        } else if (work->unk_054 < gUnk_02039B84->unk_07C->unk_08) {
            work->unk_054 = work->unk_054 + 0x180;
        }

        work->unk_006++;
        break;
    case 5:
        work->unk_050 = gUnk_02039B84->unk_0CC;
        work->unk_054 = gUnk_02039B84->unk_0D0 - 0x1400;
        work->unk_058 = gUnk_02039B84->unk_0D4;
        func_0800592C(&work->unk_028, work->unk_050, 16);
        func_0800592C(&work->unk_02C, work->unk_054, 16);
        func_0800592C(&work->unk_030, work->unk_058, 16);
        func_0800592C(&work->unk_074, 0x200, 16);
        func_0800592C(&work->unk_078, 2, 16);
        work->unk_006++;

        if (work->unk_006 > 59) {
            work->unk_002 = 6;
            work->unk_004 = 0;
            work->unk_006 = 0;
            work->unk_008 = 0;
        }
        break;
    case 6:
        work->unk_074 = 0x100;
        work->unk_078 = 0x100;
        func_08005B64(&work->unk_07C);
        AnimChange(&work->unk_07C, 4, 1);
        break;
    case 7:
        AnimChange(&work->unk_07C, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
        break;
    }

    WorldToScreen(&x1, &y1, work->unk_028 + work->unk_034, work->unk_02C + work->unk_038,
                  work->unk_030 + work->unk_03C);

    if (gUnk_02039B84->unk_068 & 0x2000000000000) {
        WorldToScreen(&x2, &y2, work->unk_068, work->unk_06C, work->unk_070);
        work->unk_016 += 2;
    } else {
        if (work->unk_00E == 0) {
            switch (work->unk_002) {
            case 2:
            case 3:
                work->unk_016 += 2;
                WorldToScreen(&x2, &y2, work->unk_050, work->unk_054, work->unk_058);
                break;
            default:
                work->unk_016 += 2;
                WorldToScreen(&x2, &y2, gUnk_02039B84->unk_07C->unk_04, gUnk_02039B84->unk_07C->unk_08,
                              gUnk_02039B84->unk_07C->unk_0C);
                break;
            }
        } else {
            switch (work->unk_002) {
            case 2:
            case 3:
            case 4:
                work->unk_016 += 6;
                WorldToScreen(&x2, &y2, work->unk_050, work->unk_054, work->unk_058);
                break;
            default:
                work->unk_016 += 2;
                WorldToScreen(&x2, &y2, gUnk_02039B84->unk_07C->unk_04, gUnk_02039B84->unk_07C->unk_08,
                              gUnk_02039B84->unk_07C->unk_0C);
                break;
            }
        }

        work->unk_068 = gUnk_02039B84->unk_07C->unk_04;
        work->unk_06C = gUnk_02039B84->unk_07C->unk_08;
        work->unk_070 = gUnk_02039B84->unk_07C->unk_0C;
    }

    work->unk_016 &= 0xFF;

    if (work->unk_00E == 0) {
        work->unk_034 = (-gSineTable[(work->unk_016 & 0xFF) + 64] * 3 >> 6) << 8;
        work->unk_038 = (gSineTable[work->unk_016 & 0xFF] * 3 >> 6) << 8;
        work->unk_03C = work->unk_03C / 2;
    } else if (work->unk_010 == 0) {
        work->unk_034 = work->unk_034 / 2;
        work->unk_038 = work->unk_038 / 2;
        work->unk_03C = work->unk_03C / 2;
    } else {
        work->unk_034 = (-gSineTable[(work->unk_016 & 0xFF) + 64] >> 3) << 8;
        work->unk_038 = (gSineTable[work->unk_016 & 0xFF] * 3 >> 6) << 8;
        work->unk_03C = 0x800;
    }

    work->unk_040 = gUnk_09A4FDE8[(work->unk_00C >> 2) & 15] << 8;
    dir = func_08110A98(x2, y2, x1, y1);
    d = func_08110B10(work->unk_01B, dir);

    if (abs(d) <= 1) {
        work->unk_01B = dir;
    } else {
        work->unk_01B += d / 2;
    }

    obj->unk_04 = work->unk_028 + work->unk_034;
    obj->unk_08 = work->unk_02C + work->unk_038;
    obj->unk_0C = work->unk_030 + work->unk_03C + work->unk_040;
    AnimUpdate(&work->unk_07C);
    TaskPoolUpdate(&work->unk_1B0);
    work->unk_014++;
    work->unk_00C++;

    return 1;
}

void task_bos_lst_bit_2(LstState* work) {
    s16 x;
    s16 y;
    void* pal;
    s32 affine;
    u16 prio;
    u16 z;
    void* gfx;

    if (work->unk_0A0.unk_2C <= 0) {
        return;
    }

    pal = (void*)work->unk_098;
    if ((work->unk_00A & 1) != 0) {
        pal = (void*)work->unk_09C;
    }

    if (work->unk_00A > 0) {
        work->unk_00A = work->unk_00A - 1;
    }

    WorldToScreen(&x, &y, work->unk_028 + work->unk_034, work->unk_02C + work->unk_038,
                  work->unk_030 + work->unk_03C + work->unk_040);
    prio = func_0801AF1C(work->unk_02C);
    z = -0x1004 - (work->unk_02C >> 8) * 4;
    affine = AllocObjAffine(work->unk_01B, work->unk_074, work->unk_078, 0);
    gfx = AnimGetGfx(&work->unk_07C);
    DrawSprite(x, y, gfx, (void*)work->unk_094, pal, affine, prio, z);
    TaskPoolDraw(&work->unk_1B0);
}

void task_bos_lst_bit_3(LstBitWork* work) {
    func_0801B7D8(&work->unk_0A0);
    ReleaseObjTiles((void*)work->unk_094);
    ReleaseObjPalette((void*)work->unk_098);
    ReleaseObjPalette((void*)work->unk_09C);
    TaskPoolDestroy(&work->unk_1B0);
}

s32 func_0811156C(s32 x) {
    return x * x;
}

s32 func_08111574(s32 x) {
    return x * x;
}

s32 func_0811157C(s32 n) {
    s32 x;
    s32 g;

    if (n <= 0) {
        return 0;
    }

    x = 1;
    g = n;
    while (x < g) {
        x <<= 1;
        g >>= 1;
    }

    do {
        g = x;
        x = (n / g + g) >> 1;
    } while (x < g);

    return g;
}

u8 func_081115B4(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->unk_04;
    result = 0;

    switch (s->unk_000) {
    case 2:
    case 3:
        result = 1;
        break;
    }

    return result;
}

void func_081115CC(LstWork* work, Vec3* a, Vec3* b, s32 c, u16 d) {
    LstState* s;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;

    s = work->unk_04;
    s->unk_000 = 1;
    *(u8*)&s->unk_002 = c;
    s->unk_012 = d;
    *(Vec3*)&s->unk_024 = *a;
    *(Vec3*)&s->unk_030 = *b;
    WorldToScreen(&x1, &y1, s->unk_024, s->unk_028, s->unk_02C);
    WorldToScreen(&x2, &y2, s->unk_030, s->unk_034, s->unk_038);
    s->unk_014 = (s16)func_0811157C((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 16;

    if (s->unk_014 <= 1) {
        s->unk_014 = 2;
    }

    s->unk_010 = 0;
}

void func_08111660(LstLsrTask* t) {
    LstLsrWork* w;

    w = t->unk_04;
    w->unk_000 = 0;
    w->unk_010 = 0;
    AnimStart(&w->unk_044, 4, 0);
}

u8 func_08111678(LstLsrWork* work) {
    LstFalArg arg;
    u8 result;

    result = 0;

    if (work->unk_004 != 0) {
        return 0;
    }

    if ((s16)*work->unk_00C <= 31) {
        arg.unk_00 = 0;
        arg.unk_04 = work->unk_030;
        arg.unk_08 = work->unk_034;
        arg.unk_0C = work->unk_038;
        arg.unk_12 = *work->unk_008;
        arg.unk_14 = work->unk_00C;
        TaskCreate(gUnk_02039B84->unk_040, gUnk_09EF9F0C, &arg);
        result = 1;
    }

    return result;
}

void task_bos_lst_lsr_0(LstLsrWork* work, LstLsrArg* arg) {
    work->unk_004 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->unk_000 = 0;
    work->unk_03C = (u32)LoadObjTiles(gUnk_09CD0334, 0x900);
    work->unk_040 = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->unk_044, gUnk_09EFBF18, gUnk_09EFBEC4);
    AnimStart(&work->unk_044, 4, 0);
}

u8 task_bos_lst_lsr_1(LstLsrWork* work) {
    switch (work->unk_000) {
    case 0:
        break;
    case 1:
        work->unk_012--;
        if (work->unk_012 > 0) {
            break;
        }
        work->unk_000 = 2;
        work->unk_012 = 0;
    case 2:
        work->unk_010++;
        if (work->unk_010 >= work->unk_014) {
            work->unk_000 = 3;
            work->unk_010 = 0;
            func_08005B64(&work->unk_044);
            AnimChange(&work->unk_044, 6, 1);
        }
        break;
    case 3:
        if (work->unk_010 > 15) {
            work->unk_000 = 0;
            work->unk_010 = 0;
            AnimChange(&work->unk_044, 4, 0);
        } else {
            func_08011F78(0x10D, work->unk_030, work->unk_034, work->unk_038, 8, 8, 8);
            if ((work->unk_010 & 3) == 0) {
                func_08111678(work);
            }
            if (abs(work->unk_030 - gUnk_02039B84->unk_07C->unk_04) < 384) {
                work->unk_030 = gUnk_02039B84->unk_07C->unk_04;
            } else if (work->unk_030 > gUnk_02039B84->unk_07C->unk_04) {
                work->unk_030 = work->unk_030 - 384;
            } else if (work->unk_030 < gUnk_02039B84->unk_07C->unk_04) {
                work->unk_030 = work->unk_030 + 384;
            }
            if (abs(work->unk_034 - gUnk_02039B84->unk_07C->unk_08) < 384) {
                work->unk_034 = gUnk_02039B84->unk_07C->unk_08;
            } else if (work->unk_034 > gUnk_02039B84->unk_07C->unk_08) {
                work->unk_034 = work->unk_034 - 384;
            } else if (work->unk_034 < gUnk_02039B84->unk_07C->unk_08) {
                work->unk_034 = work->unk_034 + 384;
            }
            work->unk_010++;
        }
        break;
    }

    AnimUpdate(&work->unk_044);

    return 1;
}

void task_bos_lst_lsr_2(LstLsrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    u16 z;
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    s32 oam;

    switch (work->unk_000) {
    case 2:
        WorldToScreen(&x1, &y1, work->unk_030, work->unk_034, work->unk_038);
        prio = func_0801AF1C(work->unk_034);
        z = -0x1004 - (work->unk_034 >> 8) * 4;
        WorldToScreen(&x2, &y2, work->unk_024, work->unk_028, work->unk_02C);
        oam = func_08002C28(work->unk_002, 1);
        x = x2 + (x1 - x2) * work->unk_010 / work->unk_014;
        y = y2 + (y1 - y2) * work->unk_010 / work->unk_014;
        DrawSprite(x, y, gUnk_09EFBEC4[13], (void*)work->unk_03C, (void*)work->unk_040,
                   oam, prio, z);
        break;
    case 3:
        WorldToScreen(&x1, &y1, work->unk_030, work->unk_034, work->unk_038);
        prio = func_0801AF1C(work->unk_034);
        z = -0x1004 - (work->unk_034 >> 8) * 4;
        oam = AllocObjAffine(0, 0x100 - work->unk_010 * 8, work->unk_010 * 16 + 0x100, 1);
        gfx = AnimGetGfx(&work->unk_044);
        DrawSprite(x1, y1, gfx, (void*)work->unk_03C, (void*)work->unk_040,
                   oam, prio | 4, z);
        break;
    }
}

void task_bos_lst_lsr_3(LstLsrWork* work) {
    ReleaseObjTiles((void*)work->unk_03C);
    ReleaseObjPalette((void*)work->unk_040);
}

s32 func_081119F8(s32 x) {
    return x * x;
}

s32 func_08111A00(s32 x) {
    return x * x;
}

u8 func_08111A08(LstWork* work) {
    LstState* s;

    s = work->unk_04;
    return s->unk_000 != 2;
}

void task_bos_lst_ptl_0(LstPtlWork* work, LstPtlArg* arg) {
    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_006 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->unk_010 = 0;
    work->unk_014 = 0;
    work->unk_030 = (u32)LoadObjTiles(gUnk_09CD0C34, 0x200);
    work->unk_034 = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->unk_018, gUnk_09EFBF54, gUnk_09EFBF40);
    AnimStart(&work->unk_018, 0, 1);
}

u8 task_bos_lst_ptl_1(LstPtlWork* work) {
    u8 result;

    result = 1;

    switch (work->unk_000) {
    case 0:
        work->unk_006--;
        if (work->unk_006 <= 0) {
            work->unk_000 = 1;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
            func_08005B64(&work->unk_018);
            AnimChange(&work->unk_018, 1, 1);
        }
        break;
    case 1:
        work->unk_008 -= 0x80;
        work->unk_00C += 0x100;
        work->unk_010 = -gSineTable[((work->unk_004 * 8) & 0xFF) + 0x40];
        work->unk_014 = gSineTable[(work->unk_004 * 2) & 0xFF];
        work->unk_004++;
        if ((work->unk_00C >> 8) > 0xA8) {
            work->unk_000 = 2;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
        }
        break;
    case 2:
        func_08005B64(&work->unk_018);
        AnimChange(&work->unk_018, 0, 1);
        break;
    }

    AnimUpdate(&work->unk_018);

    return result;
}

void task_bos_lst_ptl_2(LstPtlWork* work) {
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    u16 z;

    x = (work->unk_008 >> 8) + (work->unk_010 * 12 >> 8);
    y = (work->unk_00C >> 8) + (work->unk_014 * 6 >> 8);
    prio = func_0801AF1C(0x20100);
    z = 0xE7F8;
    gfx = AnimGetGfx(&work->unk_018);
    DrawSprite(x, y, gfx, (void*)work->unk_030, (void*)work->unk_034, 0, prio, z);
}

void task_bos_lst_ptl_3(LstPtlWork* work) {
    ReleaseObjTiles((void*)work->unk_030);
    ReleaseObjPalette((void*)work->unk_034);
}

s32 func_08111BF4(s32 x) {
    return x * x;
}

s32 func_08111BFC(s32 x) {
    return x * x;
}

void task_bos_lst_fal_0(LstFalWork* work, LstFalArg* arg) {
    u16 anim;

    anim = gUnk_09A4FE64[GetRandom() & 7][0];
    work->unk_000 = arg->unk_00;
    work->unk_004 = arg->unk_04;
    work->unk_008 = arg->unk_08;
    work->unk_00C = arg->unk_0C;
    work->unk_010 = (GetRandom() % 0x181 + 0x80) * arg->unk_12;
    work->unk_014 = GetRandom() % 0xC1 + 0x40;
    work->unk_018 = GetRandom() % 0x81 + 0x80;

    switch (arg->unk_00) {
    case 1:
        if ((GetRandom() & 1) != 0) {
            work->unk_010 = work->unk_010 * 512 >> 8;
            work->unk_014 = work->unk_014 * 384 >> 8;
            work->unk_018 = GetRandom() % 0x81 + 0x380;
        }
        break;
    case 2:
        work->unk_014 = GetRandom() % 0x81 + 0x180;
        break;
    case 3:
        work->unk_010 = work->unk_010 * 640 >> 8;
        break;
    case 4:
        work->unk_010 = (-gSineTable[arg->unk_10 + 0x40] << 8) / 256;
        work->unk_014 = (gSineTable[arg->unk_10] << 8) / 256;
        break;
    case 5:
        work->unk_010 = GetRandom() % 0x201 - 0x100;
        work->unk_014 = GetRandom() % 0xC1 + 0xC0;
        work->unk_018 = GetRandom() % 0x381 + 0x80;
        break;
    }

    switch (anim) {
    case 4:
    case 5:
        work->unk_010 = work->unk_010 * 320 >> 8;
        work->unk_014 = work->unk_014 * 320 >> 8;
        break;
    }

    work->unk_01C = arg->unk_14;
    (*work->unk_01C)++;
    work->unk_020 = (u32)LoadObjTiles(gUnk_09CD1074, 0x700);
    work->unk_024 = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->unk_028, gUnk_09EFBFC4, gUnk_09EFBF64);
    AnimStart(&work->unk_028, anim, 1);
}

u8 task_bos_lst_fal_1(LstFalWork* work) {
    u16 x;
    s16 y;
    u8 result;
    s32 d;

    result = 1;
    work->unk_004 += work->unk_010;
    work->unk_00C += work->unk_014;

    if (work->unk_000 != 4) {
        if (work->unk_018 > 0) {
            d = 512;
            if (work->unk_018 <= 512) {
                d = work->unk_018;
            }
            work->unk_00C -= d;
            work->unk_018 = work->unk_018 - 25;
        } else {
            work->unk_018 = GetRandom() % 0x41 + 0x40;
        }
    }

    WorldToScreen((s16*)&x, &y, work->unk_004, work->unk_008, work->unk_00C);

    if ((u16)(x + 16) > 272 || y < -64 || y > 224) {
        result = 0;
    }

    AnimUpdate(&work->unk_028);

    return result;
}

void task_bos_lst_fal_2(LstFalWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 prio;

    WorldToScreen(&x, &y, work->unk_004, work->unk_008, work->unk_00C);
    gfx = AnimGetGfx(&work->unk_028);
    prio = func_0801AF1C(work->unk_008) | 4;
    DrawSprite(x, y, gfx, (void*)work->unk_020, (void*)work->unk_024, 0, prio,
               -0x1004 - (work->unk_008 >> 8) * 4);
}

void task_bos_lst_fal_3(LstFalWork* work) {
    if (work->unk_020 != 0) {
        ReleaseObjTiles((void*)work->unk_020);
    }
    if (work->unk_024 != 0) {
        ReleaseObjPalette((void*)work->unk_024);
    }
    (*work->unk_01C)--;
}

s32 func_08111F3C(s32 x) {
    return x * x;
}

s32 func_08111F44(s32 x) {
    return x * x;
}

u8 func_08111F4C(LstWork* work) {
    LstState* s;

    s = work->unk_04;
    return s->unk_008 != 4;
}

s32 func_08111F60(s32 n) {
    s32 x;
    s32 g;

    if (n <= 0) {
        return 0;
    }

    x = 1;
    g = n;
    while (x < g) {
        x <<= 1;
        g >>= 1;
    }

    do {
        g = x;
        x = (n / g + g) >> 1;
    } while (x < g);

    return g;
}

void task_bos_lst_ctr_0(LstCtrWork* work, LstCtrArg* arg) {
    work->unk_000 = arg->unk_00;
    work->unk_004 = arg->unk_04;
    work->unk_006 = arg->unk_06;
    work->unk_008 = 0;
    work->unk_00A = 0;
    work->unk_00C = 0;
    work->unk_00E = arg->unk_08;
    work->unk_020 = 0;
    work->unk_024 = 0;
    work->unk_028 = 0;
    work->unk_014 = arg->unk_0C;
    work->unk_018 = arg->unk_10;
    work->unk_01C = arg->unk_14;
    work->unk_02C = arg->unk_0C;
    work->unk_030 = arg->unk_10;
    work->unk_034 = arg->unk_14;
    work->unk_05C = (u32)LoadObjTiles(gUnk_09C5C704, 0x500);
    work->unk_060 = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->unk_044, gUnk_09EFAF50, gUnk_09EFAF24);
    AnimStart(&work->unk_044, 3, 1);
}

u8 task_bos_lst_ctr_1(LstCtrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    LstPos* p;
    s32 c;

    work->unk_020 /= 2;
    work->unk_024 /= 2;
    work->unk_028 /= 2;

    switch (work->unk_008) {
    case 0:
        c = (u16)work->unk_00C + 1;
        work->unk_00C = c;
        work->unk_00E--;
        if (work->unk_00E <= 0) {
            p = gUnk_02039B84->unk_07C;
            work->unk_038 = work->unk_014 - (work->unk_014 - p->unk_04) / 4;
            work->unk_03C = p->unk_08;
            work->unk_040 = -0x1000;
            work->unk_008 = 1;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
            WorldToScreen(&x1, &y1, work->unk_02C, work->unk_030, work->unk_034);
            WorldToScreen(&x2, &y2, work->unk_038, work->unk_03C, work->unk_040);
            work->unk_010 = 0;
            work->unk_012 = (s16)func_08111F60((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 9;
        } else {
            work->unk_020 =
                (-gSineTable[((gUnk_09A4FEA8[work->unk_004][work->unk_006] + c) & 0xFF) + 0x40] * 5 >> 6) << 8;
            work->unk_028 =
                ((gSineTable[(gUnk_09A4FEA8[work->unk_004][work->unk_006] + c) & 0xFF] * 3 >> 5) - 4) << 8;
        }
        break;
    case 1:
        work->unk_014 = work->unk_02C - (work->unk_02C - work->unk_038) * work->unk_00C / work->unk_012;
        work->unk_018 = work->unk_030 + (work->unk_03C - work->unk_030) * work->unk_00C / work->unk_012;
        work->unk_01C = work->unk_034 + (work->unk_040 - work->unk_034) * work->unk_00C / work->unk_012;
        work->unk_00C++;
        if (work->unk_00C >= work->unk_012) {
            work->unk_008 = 2;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
        }
        if (func_08011F78(0x10F, work->unk_014, work->unk_018, work->unk_01C, 8, 1, 4) != 0) {
            m4aSongNumStart(0x2BB);
        }
        break;
    case 2:
        work->unk_00C++;
        if (work->unk_00C > 2) {
            work->unk_008 = 3;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
            work->unk_014 = work->unk_038;
            work->unk_018 = work->unk_03C;
            work->unk_01C = work->unk_040;
            AnimStart(&work->unk_044, 1, 0);
            m4aSongNumStart(0x2C6);
        }
        break;
    case 3:
        if (work->unk_02C > work->unk_038) {
            work->unk_010 = 0;
            work->unk_014 = work->unk_014 - 0x600;
            if (work->unk_014 < 0x6000) {
                work->unk_008 = 4;
                work->unk_00A = 0;
                work->unk_00C = 0;
                work->unk_00E = 0;
            }
        } else {
            work->unk_010 = 0x80;
            work->unk_014 = work->unk_014 + 0x600;
            if (work->unk_014 > 0x19000) {
                work->unk_008 = 4;
                work->unk_00A = 0;
                work->unk_00C = 0;
                work->unk_00E = 0;
            }
        }
        work->unk_01C = work->unk_040 - ((work->unk_00C >> 2) << 8);
        if (func_08011F78(0x10F, work->unk_014, work->unk_018, work->unk_01C, 8, 4, 4) != 0) {
            m4aSongNumStart(0x2BB);
        }
        work->unk_00C++;
        break;
    case 4:
        AnimStart(&work->unk_044, 2, 1);
        break;
    }

    AnimUpdate(&work->unk_044);

    return 1;
}

void task_bos_lst_ctr_2(LstCtrWork* work) {
    s16 x;
    s16 y;
    s32 affine;
    u16 prio;
    u16 z;
    void* gfx;
    s32 d;

    WorldToScreen(&x, &y, work->unk_014 + work->unk_020, work->unk_018 + work->unk_024,
                  work->unk_01C + work->unk_028);
    affine = 0;
    prio = func_0801AF1C(work->unk_018 + work->unk_024) | 4;
    z = -0x1004 - ((work->unk_018 + work->unk_024) >> 8) * 4;

    switch (work->unk_008) {
    case 0:
        d = work->unk_00C - work->unk_006 * 8;
        if (d <= 0) {
            return;
        }
        if (d <= 15) {
            affine = AllocObjAffine(0, 0x100, d * 16, 0);
        }
        break;
    case 1:
        affine = AllocObjAffine(0, 0x100 - work->unk_00C * 4, 0x100 - work->unk_00C * 4, 1);
        break;
    case 2:
        affine = AllocObjAffine(0, 0x100 - (work->unk_012 - work->unk_00C) * 4,
                                0x100 - work->unk_012 * 4, 1);
        break;
    default:
        if (work->unk_014 + work->unk_020 > work->unk_038) {
            prio |= 1;
        }
        break;
    }

    gfx = AnimGetGfx(&work->unk_044);
    DrawSprite(x, y, gfx, (void*)work->unk_05C, (void*)work->unk_060, affine, prio, z);
}

void task_bos_lst_ctr_3(LstCtrWork* work) {
    ReleaseObjTiles((void*)work->unk_05C);
    ReleaseObjPalette((void*)work->unk_060);
}

s32 func_08112410(s32 x) {
    return x * x;
}

s32 func_08112418(s32 x) {
    return x * x;
}

void task_bos_lst_snp_0(LstSnpWork* work, LstSnpArg* arg) {
    work->unk_000 = 0;
    work->unk_004 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->unk_010 = (GetRandom() % 0x181 + 0x80) * arg->unk_0C;
    work->unk_014 = -(GetRandom() % 0x201 + 0x400);
    work->unk_018 = (u32)LoadObjTiles(gUnk_09CD0E34, 0x240);
    work->unk_01C = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    m4aSongNumStart(0x2C3);
    AnimInit(&work->unk_020, gUnk_09EFBF60, gUnk_09EFBF5C);
    AnimStart(&work->unk_020, 0, 1);
}

u8 task_bos_lst_snp_1(LstSnpWork* work) {
    s16 x;
    s16 y;
    u8 result;

    result = 1;
    work->unk_000 += 8;
    work->unk_004 += work->unk_010;
    work->unk_00C += work->unk_014;
    work->unk_014 += 64;
    WorldToScreen(&x, &y, work->unk_004, work->unk_008, work->unk_00C);

    if (y > 192) {
        result = 0;
    }

    AnimUpdate(&work->unk_020);

    return result;
}

void task_bos_lst_snp_2(LstSnpWork* work) {
    s16 x;
    s16 y;
    s32 oam;
    void* gfx;
    u16 prio;

    WorldToScreen(&x, &y, work->unk_004, work->unk_008, work->unk_00C);
    oam = func_08002C28(work->unk_000, 1);
    gfx = AnimGetGfx(&work->unk_020);
    prio = func_0801AF1C(work->unk_008) | 4;
    DrawSprite(x, y, gfx, (void*)work->unk_018, (void*)work->unk_01C, oam, prio,
               -0x1004 - (work->unk_008 >> 8) * 4);
}

void task_bos_lst_snp_3(LstSnpWork* work) {
    ReleaseObjTiles((void*)work->unk_018);
    ReleaseObjPalette((void*)work->unk_01C);
}

s32 func_081125B4(s32 x) {
    return x * x;
}

void func_081125BC(StaffRollWork* w) {
    w->unk_078 = 0;
    w->unk_07C = 0;
    w->unk_080 = 0;
    gBldCnt = 0;
    gBldY = 0;
}

u8 func_081125D8(StaffRollWork* w) {
    u8 result;

    result = 1;
    if (w->unk_080 >= w->unk_07C) {
        gBldCnt &= 0xFF3F;
        result = 0;
    }

    return result;
}

void func_08112600(StaffRollWork* w) {
    u16 v;

    if (w->unk_080 < w->unk_07C) {
        v = ((w->unk_080 << 12) / w->unk_07C) << 8 >> 16;
        w->unk_080 = w->unk_080 + 1;
    } else {
        v = 16;
        gBldCnt &= 0xFF3F;
        gBldAlpha = 0;
        gBldY = 0;
    }

    switch (w->unk_078) {
    case 0:
    case 2:
        gBldY = 16 - v;
        break;
    case 1:
    case 3:
        gBldY = v;
        break;
    case 4:
        gBldAlpha = v;
        break;
    case 5:
        gBldAlpha = 16 - v;
        break;
    }
}

void func_081126A8(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 0;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0xE0;
    gBldY = 16;
}

void func_081126D0(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 1;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0xE0;
    gBldY = 0;
}

void func_081126F8(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 4;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0x40;
    gBldAlpha = 0;
}

void func_08112720(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 5;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0x40;
    gBldAlpha = 16;
}

u8* func_08112748(StaffRollWork* w) {
    return &w->unk_13C[w->unk_0CC[w->unk_0D0 + 3] * 0x2C];
}

void func_08112768(StaffRollWork* w) {
    StaffRollLabelArg arg;
    EvtObj* e;
    s32 run;
    s32 x;
    s32 y;

    if (w->unk_0CC == 0) {
        return;
    }

    run = 1;

    while (run != 0) {
        if (w->unk_0D4 != w->unk_0CC[w->unk_0D0 + 2]) {
            switch (w->unk_0D8) {
            case 5:
                if (w->unk_0F4 > w->unk_0E0) {
                    x = w->unk_0E4 + (w->unk_0EC - w->unk_0E4) * w->unk_0E0 / w->unk_0F4;
                    y = w->unk_0E0;
                    y = w->unk_0E8 + (w->unk_0F0 - w->unk_0E8) * y / w->unk_0F4;
                } else {
                    x = w->unk_0EC;
                    y = w->unk_0F0;
                    w->unk_0D8 = -1;
                    w->unk_0E0 = 0;
                }
                e = (EvtObj*)&w->unk_13C[w->unk_0DC * 0x2C];
                func_0801CD8C(e, x, y, 0);
                w->unk_0E0++;
                break;
            case 8:
                if (w->unk_0F4 <= w->unk_0E0) {
                    w->unk_0D8 = -1;
                    w->unk_0E0 = 0;
                }
                w->unk_0E0++;
                break;
            }
            break;
        }

        w->unk_0D8 = -1;
        w->unk_0E0 = 0;

        switch (w->unk_0CC[w->unk_0D0]) {
        case 0:
            goto done;
        case 1:
            w->unk_0D0 = 0;
            w->unk_0D4 = 0;
            continue;
        case 2:
            e = (EvtObj*)func_08112748(w);
            func_0801CD74(e, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 3:
            e = (EvtObj*)func_08112748(w);
            func_0801CE00(e, w->unk_0CC[w->unk_0D0 + 4] | 0x400);
            break;
        case 4:
            e = (EvtObj*)func_08112748(w);
            func_0801CD8C(e, w->unk_0CC[w->unk_0D0 + 4] << 8, w->unk_0CC[w->unk_0D0 + 5] << 8, 0);
            break;
        case 5:
            e = (EvtObj*)func_08112748(w);
            w->unk_0D8 = 5;
            w->unk_0DC = w->unk_0CC[w->unk_0D0 + 3];
            w->unk_0E4 = e->unk_04;
            w->unk_0E8 = e->unk_08;
            w->unk_0EC = w->unk_0CC[w->unk_0D0 + 4] << 8;
            w->unk_0F0 = w->unk_0CC[w->unk_0D0 + 5] << 8;
            w->unk_0F4 = w->unk_0CC[w->unk_0D0 + 6];
            break;
        case 6:
            w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3] =
                func_0801CE04(w->unk_110, gUnk_09EFA9EC, (EvtObj*)func_08112748(w), w->unk_0CC[w->unk_0D0 + 4],
                              w->unk_0CC[w->unk_0D0 + 5], 0x2800, 0xF000, 0);
            break;
        case 7:
            func_08000DE8(w->unk_110, (void*)w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3]);
            break;
        case 8:
            w->unk_0D8 = 5;
            w->unk_0F4 = w->unk_0CC[w->unk_0D0 + 4];
            break;
        case 9:
            func_08006120(0, (u16)w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 10:
            func_08006184(0, (u16)w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 11:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            func_081126F8(w, 0x2000, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 12:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            func_08112720(w, 0x2000, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 13:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            break;
        case 14:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 &= 0xFFFB;
            break;
        case 15:
            e = (EvtObj*)func_08112748(w);
            arg.unk_00 = w->unk_0CC[w->unk_0D0 + 4];
            arg.unk_04 = e->unk_04;
            arg.unk_08 = e->unk_08;
            TaskCreate(w->unk_110, gUnk_09EFAA34, &arg);
            break;
        case 16:
            func_081149B0((void*)w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3],
                          w->unk_0CC[w->unk_0D0 + 4]);
            break;
        default:
            continue;
        }

        w->unk_0D0 += w->unk_0CC[w->unk_0D0 + 1];
    }

done:
    w->unk_0D4++;
}

void mode_StaffRoll_0(void) {
    StaffRollWork* w;
    StaffRollWork** p;

    p = &gUnk_02036020;
    w = EwramAlloc(0x418);
    *p = w;
    func_08005778(0, 0, 0);
    func_08001F98();
    w->unk_0F8 = (u32)LoadObjPalette(gUnk_09D6BE74, 0x100);
    w->unk_000 = 1;
    w->unk_001 = 1;
    w->unk_008 = 0;
    w->unk_00C = 0;
    w->unk_010 = 0;
    w->unk_014 = 0;
    func_081125BC(w);
    w->unk_084 = 0;
    w->unk_08C = 0;
    w->unk_088 = 0;
    w->unk_090 = -1;
    w->unk_094 = 0;
    w->unk_098 = 0;
    w->unk_0A4 = 0;
    w->unk_0A0 = 0;
    w->unk_0A8 = 0;
    w->unk_0AC = 0;
    w->unk_0B0 = -1;
    w->unk_0B8 = 0;
    w->unk_0BC = 0;
    w->unk_0C0 = 0;
    w->unk_0C4 = 0;
    w->unk_0C8 = 0;
    w->unk_0CC = 0;
    w->unk_0D0 = 0;
    w->unk_0D4 = 0;
    w->unk_0D8 = -1;
    w->unk_0E0 = 0;
    TaskPoolInit(w->unk_0FC, 32);
    TaskPoolInit(w->unk_110, 32);
    w->unk_124[0] = 0;
    w->unk_124[1] = 0;
    w->unk_124[2] = 0;
    w->unk_124[4] = 0;
    w->unk_124[5] = 0;
    *(s32*)w->unk_13C = 0;
}

u8 func_08112C24(StaffRollWork* w) {
    u8 result;

    result = 1;
    if (w->unk_00C > 74) {
        result = 0;
    }
    w->unk_00C++;

    return result;
}

u8 func_08112C38(StaffRollWork* w) {
    StaffRollTaskArg arg;
    u8 result;
    s32 z;

    result = 1;

    if ((gUnk_02039BB0.unk_008 & 8) != 0) {
        w->unk_09C = gUnk_09A53D50;
    } else {
        w->unk_09C = gUnk_09A538D8;
    }

    switch (w->unk_084) {
    case 0:
        func_08004E64();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 29, 0);
        SetupBg(2, 0, 30, 11);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0);
        SetBgSize(1, 0);
        SetBgSize(2, 0x4000);
        SetBgSize(3, 0x4000);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        SetBgColorMode(0, 0x80);

        if (w->unk_090 != w->unk_094) {
            w->unk_090 = w->unk_094;

            if (w->unk_09C[w->unk_090].unk_00 == 1) {
                SetBgColorMode(0, 0x80);
            } else {
                SetBgColorMode(0, 0);
            }

            EnableBg(0);
            LoadBgTiles(0, w->unk_09C[w->unk_090].unk_10, w->unk_09C[w->unk_090].unk_14);
            LoadBgMap(0, w->unk_09C[w->unk_090].unk_18, w->unk_09C[w->unk_090].unk_1C);
            LoadBgPalette(0, w->unk_09C[w->unk_090].unk_20, w->unk_09C[w->unk_090].unk_24);
            SetBgScroll(0, (u16) - (w->unk_09C[w->unk_090].unk_08 >> 8),
                        (u16) - (w->unk_09C[w->unk_090].unk_0C >> 8));
        }

        w->unk_084 = 1;
        w->unk_08C = 0;
    case 1:
    {
        u8 t;

            if (w->unk_08C == 0) {
                if (w->unk_09C[w->unk_090].unk_01 == 1) {
                    func_081126A8(w, 17, 30);
                } else {
                    func_081126A8(w, 16, 30);
                }
                w->unk_08C++;
            }

            func_08112600(w);
            t = func_081125D8(w);
            if (t != 0) {
                break;
            }

            arg.unk_00 = t;
            arg.unk_02 = w->unk_09C[w->unk_090].unk_30;
            arg.unk_04 = t;
            arg.unk_08 = 0x14000;
            arg.unk_0C = w->unk_09C[w->unk_090].unk_2C;
            arg.unk_10 = w->unk_09C[w->unk_090].unk_28;
            arg.unk_14 = w->unk_09C[w->unk_090].unk_2C;
            w->unk_124[0] = (s32)TaskCreate(w->unk_0FC, gUnk_09EFA9D4, &arg);
            arg.unk_00 = 1;
            arg.unk_02 = 1;
            arg.unk_04 = w->unk_09C[w->unk_090].unk_32;
            arg.unk_08 = -0x5000;
            z = 0x7800;
            arg.unk_10 = z;
            w->unk_124[1] = (s32)TaskCreate(w->unk_0FC, gUnk_09EFA9D4, &arg);
            arg.unk_00 = 2;
            arg.unk_02 = w->unk_09C[w->unk_090].unk_30;
            arg.unk_04 = w->unk_09C[w->unk_090].unk_32;
            arg.unk_08 = z;
            w->unk_124[2] = (s32)TaskCreate(w->unk_0FC, gUnk_09EFA9D4, &arg);
            w->unk_084 = 2;
            w->unk_08C = t;
            break;
    }
    case 2:
        w->unk_088++;
        if (w->unk_088 >= w->unk_09C[w->unk_090].unk_04) {
            w->unk_084 = 3;
            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
        }
        if ((w->unk_002 & 1) != 0 || (w->unk_004 & 0x100) != 0) {
            w->unk_084 = 3;
            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
        }
        if ((w->unk_002 & 2) == 0) {
            break;
        }
        func_08000DE8(w->unk_0FC, (void*)w->unk_124[0]);
        func_08000DE8(w->unk_0FC, (void*)w->unk_124[1]);
        func_08000DE8(w->unk_0FC, (void*)w->unk_124[2]);
        w->unk_010 = 0x1518;
        w->unk_084 = 4;
        w->unk_08C = 0;
        w->unk_088 = 0;
        break;
    case 3:
    {
        u8 t;

            if (w->unk_08C == 0) {
                if (w->unk_09C[w->unk_090].unk_02 == 1) {
                    func_081126D0(w, 17, 30);
                } else {
                    func_081126D0(w, 16, 30);
                }
                w->unk_08C++;
            }

            func_08112600(w);
            t = func_081125D8(w);
            if (t != 0) {
                break;
            }

            if (w->unk_09C[w->unk_090].unk_02 == 1) {
                DisableBg(0);
            }

            func_08000DE8(w->unk_0FC, (void*)w->unk_124[0]);
            func_08000DE8(w->unk_0FC, (void*)w->unk_124[1]);
            func_08000DE8(w->unk_0FC, (void*)w->unk_124[2]);
            w->unk_094 = w->unk_090 + 1;

            if (w->unk_094 > 21) {
                w->unk_084 = 4;
            } else {
                w->unk_084 = t;
            }

            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
    }
    case 4:
    {
        s32 v;

        v = w->unk_098 + 64;
        w->unk_098 = v;

        if (v > 0x1BFF) {
            SetBgScroll(0, (u16) - (w->unk_09C[w->unk_090].unk_08 >> 8),
                        (u16)(-(w->unk_09C[w->unk_090].unk_0C >> 8) + 28));
            if (w->unk_098 > 0x4000) {
                w->unk_084 = 6;
                w->unk_08C = 0;
                w->unk_088 = 0;
            }
        } else {
            SetBgScroll(0, (u16) - (w->unk_09C[w->unk_090].unk_08 >> 8),
                        (u16)(-(w->unk_09C[w->unk_090].unk_0C >> 8) + (v >> 8)));
        }
        break;
    }
    case 5:
        break;
    case 6:
        if (w->unk_08C == 0) {
            func_081126D0(w, 17, 120);
            w->unk_08C++;
        }
        func_08112600(w);
        if (func_081125D8(w) == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

#ifdef VERSION_JP
#define STAFFROLL_SCROLL_FRAMES 0x4321
#define STAFFROLL_SCROLL_SPEED 0x16000000
#define STAFFROLL_SCRIPT_PERIOD 635
#else
#define STAFFROLL_SCROLL_FRAMES 0x431C
#define STAFFROLL_SCROLL_SPEED 0x13C00000
#define STAFFROLL_SCRIPT_PERIOD 627
#endif

u8 func_08113180(StaffRollWork* w) {
    u8 buf[80];
    StaffRollLogoArg logo;
    StaffRollSecnArg secn;
    u8 result;
    s32 i;
    u32 row;
    u8* s;
    s32 loop;
    s32 x;
    u32 y;
    s32 total;
    s32 wa;
    s32 wb;
    s32 wc;
    s32 w1;
    s32 n;
    s32 t;
    s32 sub;
    s32 idx;

    result = 1;

    switch (w->unk_0A4) {
    case 0:
        func_081125BC(w);
        func_08004E64();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 29, 0);
        SetupBg(2, 0, 30, 11);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0);
        SetBgSize(1, 0);
        SetBgSize(2, 0x4000);
        SetBgSize(3, 0x4000);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);

        for (i = 0; i < 32; i++) {
            func_080062F4(i, 1);
        }

        func_0811614C(w->unk_1C0, gUnk_09A541C8);
        LoadBgPalette(0, gUnk_09D6BE14, 32);
        gDispCnt |= 0;
        gWinIn = 31;
        gWinOut = 30;
        gWin0H = 0x10E0;
        gWin0V = 0x898;
        w->unk_0A4 = 1;
        w->unk_0A8 = 0;
    case 1:
        w->unk_0B4 = STAFFROLL_SCROLL_SPEED / ((STAFFROLL_SCROLL_FRAMES - w->unk_010) << 8);
        w->unk_0A4 = 2;
        w->unk_0A8 = 0;
        break;
    case 2:
        w->unk_0B8 += w->unk_0B4;
        sub = w->unk_0B8 >> 8;
        row = w->unk_0B8 >> 11;

        if (sub % 8 == 0 && w->unk_0B0 != row) {
            s = gUnk_09EF9F54[row];

            if (w->unk_0A0 == 0 && s == 0) {
                w->unk_0B4 = 0;
                w->unk_0A0 = 1;
            }

            if (*s != '!') {
                func_081166F8(w->unk_1C0, 0, (row + 20) & 31, 30, 2, 1);
            }

            if (w->unk_0A0 == 0) {
                func_08116268(w->unk_1C0, 15, 13, 0, 14);
                loop = 1;

                while (loop) {
                    switch (*s) {
                    case '!':
                        loop = 0;
                        break;
                    case '*':
                        switch (s[1]) {
                        case 'D':
                            logo.unk_10 = 0;
                            break;
                        case 'S':
                            logo.unk_10 = 1;
                            break;
                        case 'J':
                            logo.unk_10 = 2;
                            break;
                        }
                        logo.unk_00 = 0x7800;
                        logo.unk_04 = ((w->unk_0B8 >> 8) + 168) << 8;
                        logo.unk_08 = &w->unk_0B8;
                        logo.unk_0C = &w->unk_0B4;
                        TaskCreate(w->unk_110, gUnk_09EFAA04, &logo);
                        loop = 0;
                        break;
                    case '<':
                        secn.unk_00 = w->unk_014;
                        secn.unk_04 = 0x17800;
                        secn.unk_08 = ((w->unk_0B8 >> 8) + 168) << 8;
                        secn.unk_0C = &w->unk_0B8;
                        secn.unk_10 = &w->unk_0B4;
                        TaskCreate(w->unk_110, gUnk_09EFAA1C, &secn);
                        w->unk_014++;
                        loop = 0;
                        break;
                    case '[':
                        secn.unk_00 = -1;
                        secn.unk_04 = 0x7800;
                        secn.unk_08 = ((w->unk_0B8 >> 8) + 168) << 8;
                        secn.unk_0C = &w->unk_0B8;
                        secn.unk_10 = &w->unk_0B4;
                        TaskCreate(w->unk_110, gUnk_09EFAA1C, &secn);
                        loop = 0;
                        break;
                    case '#':
                        func_081160EC(w->unk_1C0, s[1] - '0');
                        s += 2;
                        break;
                    case '@':
                        func_08116268(w->unk_1C0, 7, 5, 0, 6);
                        s++;
                        break;
                    case '~':
                        s++;
                        wa = func_08115FBC(w->unk_1C0, s);
                        wb = func_08115FBC(w->unk_1C0, gUnk_09EFA9C0);
                        wc = func_08115FBC(w->unk_1C0, gUnk_09EFA9BC);
                        w1 = wa - wb + wc * 3;
                        x = (240 - w1) >> 1;
                        func_08116268(w->unk_1C0, 7, 5, 0, 6);

                        for (n = 0; s[n] != '~'; n++) {
                            buf[n] = s[n];
                        }

                        buf[n] = ' ';
                        buf[n + 1] = ' ';
                        buf[n + 2] = ' ';
                        buf[n + 3] = 0;
                        w1 = func_08115FBC(w->unk_1C0, buf);
                        func_08116BEC(w->unk_1C0, x, (row + 20) & 31, buf, 1);
                        s += n + 1;

                        for (n = 0; s[n] != 0; n++) {
                            buf[n] = s[n];
                        }

                        buf[n] = 0;
                        func_08116268(w->unk_1C0, 15, 13, 0, 14);
                        func_08116BEC(w->unk_1C0, x + w1, (row + 20) & 31, buf, 1);
                        loop = 0;
                        break;
                    case '=':
                        func_08116BEC(w->unk_1C0, (240 - func_08115FBC(w->unk_1C0, s + 1)) >> 1, (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    case '-':
                        func_08116BEC(w->unk_1C0, 0, (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    case '+':
                        func_08116BEC(w->unk_1C0, 240 - func_08115FBC(w->unk_1C0, s + 1), (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    default:
                        func_08116BEC(w->unk_1C0, (240 - func_08115FBC(w->unk_1C0, s)) >> 1, (row + 20) & 31, s, 1);
                        loop = 0;
                        break;
                    }
                }
            }
        }

        w->unk_0B0 = row;
        t = w->unk_0A8;

        if (t % STAFFROLL_SCRIPT_PERIOD == 60) {
            w->unk_0CC = 0;
            idx = t / STAFFROLL_SCRIPT_PERIOD;

            if (idx <= 16) {
                if ((gUnk_02039BB0.unk_008 & 8) != 0) {
                    w->unk_0CC = gUnk_09EFA978[idx];
                } else {
                    w->unk_0CC = gUnk_09EFA934[idx];
                }
            }

            w->unk_0D0 = 0;
            w->unk_0D4 = 0;
            w->unk_0D8 = -1;
            w->unk_0E0 = 0;
        }

        w->unk_0A8++;
        SetBgScroll(0, 0, (u16)(w->unk_0B8 >> 8));

        if (w->unk_010 >= STAFFROLL_SCROLL_FRAMES || (w->unk_002 & 2) != 0) {
            w->unk_0A4 = 4;
            w->unk_0A8 = 0;
        }
        break;
    case 4:
        w->unk_0A8++;
        if (w->unk_0A8 > 120) {
            w->unk_0A4 = 3;
            w->unk_0A8 = 0;
        }
        break;
    case 3:
        for (i = 0; i < 32; i++) {
            func_080062F4(i, 0);
        }

        gDispCnt &= 0xDFFF;
        gWinIn = 0;
        gWinOut = 0;
        gWin0H = 0;
        gWin0V = 0;
        result = 0;
        break;
    }

    func_08112768(w);
    TaskPoolUpdate(w->unk_110);
    TaskPoolDraw(w->unk_110);
    func_08112600(w);

    return result;
}

u8 func_0811394C(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0A4) {
    case 0:
        TaskPoolDestroy(w->unk_110);
        DisableBg(0);
        DisableBg(1);
        EnableBg(2);
        DisableBg(3);
        LoadBgTiles(2, gUnk_097CF758, 0x3F00);
        LoadBgMap(2, gUnk_0983FB98, 0x400);
        LoadBgPalette(2, gUnk_0984A618, 0xA0);
        func_08005690(2, 0, 0x100, 0x100, 0x7800, 0x5C00);
        w->unk_0A4 = 1;
        w->unk_0A8 = 0;
        break;
    case 1:
        if (w->unk_0A8 == 0) {
            func_08006120(0, 1);
            w->unk_0A8++;
        }
        t = func_08006314();
        if (t == 0) {
            w->unk_0A4 = 2;
            w->unk_0A8 = 0;
        }
        break;
    case 2:
        w->unk_0A8++;
        if (w->unk_0A8 > 179) {
            w->unk_0A4 = 3;
            w->unk_0A8 = 0;
        }
        break;
    case 3:
        if (w->unk_0A8 == 0) {
            func_08006184(0, 120);
            w->unk_0A8++;
        }
        t = func_08006314();
        if (t == 0) {
            w->unk_0A4 = 4;
            w->unk_0A8 = 0;
        }
        break;
    case 4:
        w->unk_0A8++;
        if (w->unk_0A8 > 119) {
            func_08116F08();
            result = 0;
        }
        break;
    }

    return result;
}

#ifdef VERSION_JP
#define STAFFROLL_HOLD_FRAMES 720
#else
#define STAFFROLL_HOLD_FRAMES 900
#endif

u8 func_08113A94(StaffRollWork* w) {
    u8 result;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
        break;
    case 1:
        if (w->unk_0C0 == 0) {
            func_08006120(0, 60);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            if ((gUnk_02039BB0.unk_008 & 8) != 0) {
                w->unk_124[0] = (s32)TaskCreate(w->unk_0FC, gUnk_09EFAA4C, (void*)1);
            } else {
                w->unk_124[0] = (s32)TaskCreate(w->unk_0FC, gUnk_09EFAA4C, (void*)0);
            }
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if ((gUnk_02039BB0.unk_008 & 8) != 0) {
            if (w->unk_0C0 >= STAFFROLL_HOLD_FRAMES) {
                w->unk_0BC = 3;
                w->unk_0C0 = 0;
            }
        } else {
            if (w->unk_0C0 >= 900) {
                w->unk_0BC = 3;
                w->unk_0C0 = 0;
            }
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            func_08006184(0, 120);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113BB4(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        if (w->unk_0C0 <= 119) {
            w->unk_0C0++;
            break;
        }
        func_08004DB0();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(2, 0, 31, 0);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0x8000);
        SetBgSize(1, 0);
        SetBgSize(2, 0);
        SetBgSize(3, 0);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        LoadBgTiles(0, gUnk_09D09674, 0x7200);
        LoadBgMap(0, gUnk_09D65274, 0x1000);
        LoadBgPalette(0, gUnk_09D6BF74, 0x200);
        SetBgScroll(0, 0, 160);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            func_08006120(0, 120);
            w->unk_0C0++;
        }
        t = func_08006314();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        SetBgScroll(0, 0, (u16)(160 - (w->unk_0C0 >> 1)));
        if (w->unk_0C0 <= 255) {
            w->unk_0C0++;
        }
        if (w->unk_0C0 > 255) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 4;
            w->unk_0C0 = 0;
        }
        break;
    case 4:
        if (w->unk_0C0 == 0) {
            func_08005778(31, 31, 31);
            func_08006184(1, 120);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            SetBgScroll(0, 0, 0);
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113DB8(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D10874, 0x53C0);
        LoadBgMap(0, gUnk_09D66274, 0x800);
        LoadBgPalette(0, gUnk_09D6C174, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            func_08006120(1, 120);
            w->unk_0C0++;
        }
        t = func_08006314();
        if (t == 0) {
            func_08005778(0, 0, 0);
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            func_08006184(0, 60);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113E94(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        if (w->unk_0C0 <= 119) {
            w->unk_0C0++;
            break;
        }
        func_08004DB0();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(2, 0, 31, 0);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0x8000);
        SetBgSize(1, 0);
        SetBgSize(2, 0);
        SetBgSize(3, 0);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        LoadBgTiles(0, gUnk_09D15C34, 0x53C0);
        LoadBgMap(0, gUnk_09D66A74, 0x800);
        LoadBgPalette(0, gUnk_09D6C374, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            func_08006120(0, 120);
            w->unk_0C0++;
        }
        t = func_08006314();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            func_08005778(31, 31, 31);
            func_08006184(1, 120);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08114048(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D1AFF4, 0x53C0);
        LoadBgMap(0, gUnk_09D67274, 0x800);
        LoadBgPalette(0, gUnk_09D6C574, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            func_08006120(1, 120);
            w->unk_0C0++;
        }
        t = func_08006314();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            func_08006184(1, 120);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_0811411C(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D203B4, 0x53C0);
        LoadBgMap(0, gUnk_09D67A74, 0x800);
        LoadBgPalette(0, gUnk_09D6C774, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            func_08006120(1, 120);
            w->unk_0C0++;
        }
        t = func_08006314();
        if (t == 0) {
            func_08005778(0, 0, 0);
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            func_08006184(0, 60);
            w->unk_0C0++;
        }
        if (func_08006314() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_081141F8(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0C4) {
    case 0:
        DisableBg(0);
        EnableBg(1);
        DisableBg(2);
        DisableBg(3);
        SetBgScroll(1, 0, 0);
        SetBgColorMode(1, 0x80);

        if ((gUnk_02039BB0.unk_008 & 8) != 0) {
            LoadBgTiles(1, gUnk_09D2B334, 0x7F40);
            LoadBgMap(1, gUnk_09D68A74, 0x800);
            LoadBgPalette(1, gUnk_09D6CB74, 0x200);
        } else {
            LoadBgTiles(1, gUnk_09D25774, 0x5BC0);
            LoadBgMap(1, gUnk_09D68274, 0x800);
            LoadBgPalette(1, gUnk_09D6C974, 0x200);
        }

        m4aSongNumStart(6);
        w->unk_0C4 = 1;
        w->unk_0C8 = 0;
        break;
    case 1:
        w->unk_0C8++;
        if (w->unk_0C8 > 59) {
            w->unk_0C4 = 2;
            w->unk_0C8 = 0;
        }
        break;
    case 2:
        if (w->unk_0C8 == 0) {
            func_08006120(0, 120);
            w->unk_0C8++;
        }
        t = func_08006314();
        if (t == 0) {
            w->unk_0C4 = 3;
            w->unk_0C8 = 0;
        }
        break;
    default:
        if ((GetKeysPressed() & 9) != 0) {
            result = 0;
        }
        break;
    }

    return result;
}

void mode_StaffRoll_1(void) {
    StaffRollWork* w;
    u16 tmp;

    w = gUnk_02036020;
    w->unk_004 = 0;
    w->unk_002 = 0;

    switch (w->unk_008) {
    case 0:
        if (func_08112C24(w) != 0) {
            break;
        }
        w->unk_008 = 1;
        w->unk_00C = 0;
        w->unk_010 = 0;
        func_08116E98();
    case 1:
    {
        vu32* dma;

        if (func_08112C38(w) != 0) {
            break;
        }
        w->unk_008 = 2;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0A4 = 0;
        w->unk_0A8 = 0;
        break;
    }
    case 2:
    {
        vu32* dma;

        if (func_08113180(w) != 0) {
            break;
        }
        w->unk_008 = 3;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0A4 = 0;
        w->unk_0A8 = 0;
        break;
    }
    case 3:
    {
        vu32* dma;

        if (func_0811394C(w) != 0) {
            break;
        }
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        if ((gUnk_02039BB0.unk_008 & 8) != 0) {
            w->unk_008 = 7;
            w->unk_0BC = 0;
        } else {
            w->unk_008 = 5;
            w->unk_0BC = 0;
        }
        w->unk_00C = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 4:
    {
        vu32* dma;

        if (func_08113A94(w) != 0) {
            break;
        }
        w->unk_008 = 10;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        w->unk_0C4 = 0;
        w->unk_0C8 = 0;
        break;
    }
    case 5:
    {
        vu32* dma;

        if (func_08113BB4(w) != 0) {
            break;
        }
        w->unk_008 = 6;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 6:
    {
        vu32* dma;

        if (func_08113DB8(w) != 0) {
            break;
        }
        w->unk_008 = 4;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 7:
    {
        vu32* dma;

        if (func_08113E94(w) != 0) {
            break;
        }
        w->unk_008 = 8;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 8:
    {
        vu32* dma;

        if (func_08114048(w) != 0) {
            break;
        }
        w->unk_008 = 9;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 9:
    {
        vu32* dma;

        if (func_0811411C(w) != 0) {
            break;
        }
        w->unk_008 = 4;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)0x040000D4;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = 0x81000020;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = 0x81002000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 10:
        if (func_081141F8(w) != 0) {
            break;
        }
        w->unk_008 = 11;
        w->unk_00C = 0;
        break;
    case 11:
        if (w->unk_00C == 0) {
            func_08006184(0, 120);
        }
        w->unk_00C++;
        if (w->unk_00C > 120) {
            SoftReset(0xFF);
        }
        break;
    }

    TaskPoolUpdate(w->unk_0FC);
    TaskPoolDraw(w->unk_0FC);
    func_08116ECC();
    w->unk_010++;
}

void mode_StaffRoll_2(void) {
    StaffRollWork* w;

    w = gUnk_02036020;
    ReleaseObjPalette((void*)w->unk_0F8);
    TaskPoolDestroy(w->unk_0FC);

    if (gUnk_02036020 != 0) {
        EwramFree(w);
        gUnk_02036020 = 0;
    }
}

s32 func_08114748(s32 x) {
    return x * x;
}

s32 func_08114750(s32 x) {
    return x * x;
}
