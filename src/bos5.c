#include "macros.h"
#include "bos5.h"

INCLUDE_ASM("bos5/task_bos_ga_0.s");
INCLUDE_ASM("bos5/task_bos_ga_1.s");

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

    ReleaseObjTiles((void*)work->unk_A28);
    ReleaseObjPalette((void*)work->unk_A30);
    ReleaseObjPalette((void*)work->unk_A34);
}

INCLUDE_ASM("bos5/func_080FB8DC.s");

void func_080FB8E8(s32 unused, u16 index) {
    func_0800516C(1, gUnk_09992114 + index * 0x4C, 2, 2);
}

void func_080FB908(s32 unused, u16 index) {
    LoadBgTiles(1, gUnk_09992108[index].unk_04, gUnk_09992108[index].unk_08);
}

INCLUDE_ASM("bos5/func_080FB930.s");
INCLUDE_ASM("bos5/func_080FBA14.s");
INCLUDE_ASM("bos5/func_080FBA4C.s");
INCLUDE_ASM("bos5/func_080FC3FC.s");
INCLUDE_ASM("bos5/task_bos_md_0.s");
INCLUDE_ASM("bos5/task_bos_md_1.s");
INCLUDE_ASM("bos5/task_bos_md_2.s");

#ifdef NON_MATCHING
void task_bos_md_3(MdWork* work) {
    u8* a;
    u8* b;
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    s32 i;
    s32 off;

    DisableBg(1);
    a = (u8*)work + 0xA8;
    b = (u8*)work + 0x68;
    i = 0;

    do {
        func_08012304(a);
        func_0801B7D8(b);
        a += 0x110;
        b += 0x110;
    } while (--i >= 0);

    q = (u8*)work + 0x2C;
    r = (u8*)work + 0x40;
    t = (u8*)work + 0x54;
    off = 0;
    p = (u8*)work + 0x17C;
    i = 1;

    do {
        if (*(void**)(p + off) != 0) {
            ReleaseObjTiles(*(void**)(p + off));
        }

        off += 20;
    } while (--i >= 0);

    ReleaseObjPalette((void*)work->unk_020);
    ReleaseObjPalette((void*)work->unk_024);
    TaskPoolDestroy(q);
    TaskPoolDestroy(r);
    TaskPoolDestroy(t);
}
#else
INCLUDE_ASM("bos5/task_bos_md_3.s");
#endif
INCLUDE_ASM("bos5/task_bos_md_map_0.s");
INCLUDE_ASM("bos5/task_bos_md_map_1.s");
INCLUDE_ASM("bos5/func_080FCC14.s");
INCLUDE_ASM("bos5/func_080FCCB4.s");
INCLUDE_ASM("bos5/task_bos_md_fire_0.s");

#ifdef NON_MATCHING
u8 task_bos_md_fire_1(MdFireWork* work) {
    u8 result;

    func_080FCC14(work);
    result = func_080FCCB4(work);

    if ((s16)work->unk_006 > 0) {
        work->unk_006--;
    }

    work->unk_03C = work->unk_148;
    work->unk_040 = work->unk_14C;
    work->unk_044 = work->unk_150;
    func_08012324(&work->unk_078);
    return result;
}
#else
INCLUDE_ASM("bos5/task_bos_md_fire_1.s");
#endif
#ifdef NON_MATCHING
void task_bos_md_fire_2(MdFireWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 sprite;
    u16 frame;

    if ((s16)work->unk_006 > 0 && (gFrameCounter & 1)) {
        gfx = (void*)work->unk_010;
    } else {
        gfx = (void*)work->unk_00C;
    }

    WorldToScreen(&x, &y, work->unk_148, work->unk_14C, work->unk_150);
    frame = func_0801AF1C(work->unk_14C);

    if (work->unk_000 == 0) {
        ApproachValue(&work->unk_030, 0x100, work->unk_034);
    } else if (work->unk_000 == 4) {
        ApproachValue(&work->unk_030, 25, work->unk_034);
    } else {
        sprite = 0;
        goto draw;
    }

    sprite = AllocObjAffine(0, work->unk_030, work->unk_030, 0);

draw:
    DrawSprite(x, y, AnimUpdate(&work->unk_018), (void*)work->unk_014, gfx,
                  sprite, frame, (u16)(-4100 - (work->unk_14C >> 8) * 4));
}
#else
INCLUDE_ASM("bos5/task_bos_md_fire_2.s");
#endif

void task_bos_md_fire_3(MdFireWork* work) {
    func_08012304(&work->unk_078);
    func_0801B7D8(&work->unk_038);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    ReleaseObjTiles((void*)work->unk_014);
}

void task_bos_md_dai_0(MdDaiWork* work, s32* src) {
    u8* p;

    gUnk_02039B84->unk_068 |= 0x100000;
    work->unk_078 = src[1];
    work->unk_080 = src[0];
    work->unk_07C = 0;
    work->unk_07E = 0;
    work->unk_000 = 0x8000;
    work->unk_004 = 0x14F00;
    work->unk_008 = 0;
    work->unk_010 = 20;
    work->unk_00C = 0xFFFF6000;
    p = (u8*)work + 0x1C;
    func_080122AC(p, 7, 24, 24);
    func_08012324(p, work->unk_000, work->unk_004, work->unk_008);
    func_08012614(p, 1);
    work->unk_014 = (u32)LoadObjPalette(gUnk_09A3C9BC, 32);
    work->unk_018 = (u32)LoadObjTiles(gUnk_09999ED0, 0x480);
}

INCLUDE_ASM("bos5/task_bos_md_dai_1.s");
INCLUDE_ASM("bos5/task_bos_md_dai_2.s");

void task_bos_md_dai_3(MdDaiWork* work) {
    func_08012304(&work->unk_01C);
    ReleaseObjPalette((void*)work->unk_014);
    ReleaseObjTiles((void*)work->unk_018);
    gUnk_02039B84->unk_068 &= 0xFFFFFFFFFFEFFFFF;
}

#ifdef NON_MATCHING
void task_bos_md_hahen_0(MdHahenWork* work, s32* src) {
    u8 angle;
    s32 speed;

    work->unk_000 = src[0];
    work->unk_004 = src[1];
    work->unk_008 = src[2];
    angle = GetRandom();
    speed = (GetRandom() & 0x1FF) + 0x100;
    work->unk_00C = -gSineTable[angle + 0x40] * speed >> 8;
    work->unk_010 = gSineTable[angle] * speed >> 8;
    work->unk_014 = -((GetRandom() & 0x1FF) + 0x100);
    work->unk_024 = 3;
    work->unk_018 = (u32)LoadObjPalette(gUnk_09A3C9BC, 32);
    work->unk_01C = (u32)LoadObjTiles(gUnk_09999ED0, 0x480);
    work->unk_020 = gUnk_09EF9740[(u16)GetRandom() & 1];
}
#else
INCLUDE_ASM("bos5/task_bos_md_hahen_0.s");
#endif

#ifndef VERSION_EU
s32 task_bos_md_hahen_1(MdHahenWork* work) {
    s32 result;

    result = 1;
    work->unk_000 += work->unk_00C;
    work->unk_004 += work->unk_010;

    if (work->unk_004 <= 0x117FF) {
        work->unk_010 = -work->unk_010;
    }

    work->unk_008 += work->unk_014;
    work->unk_014 += 102;

    if (work->unk_008 > 0) {
        work->unk_008 = 0;
        work->unk_014 = -(work->unk_014 * 8 / 10);
        work->unk_024--;

        if ((s16)work->unk_024 <= 0) {
            result = 0;
        }
    }

    return result;
}
#else
INCLUDE_ASM("bos5/task_bos_md_hahen_1.s");
#endif

void task_bos_md_hahen_2(MdHahenWork* work) {
    s16 x;
    s16 y;
    u16 frame;
    s32 flag;

    flag = gFrameCounter & 1;

    if (flag != 0) {
        return;
    }

    WorldToScreen(&x, &y, work->unk_000, work->unk_004, work->unk_008);
    frame = func_0801AF1C(work->unk_004);
    DrawSprite(x, y, (void*)work->unk_020, (void*)work->unk_01C, (void*)work->unk_018,
                  flag, frame, (u16)(-4100 - (work->unk_004 >> 8) * 4));
}

void task_bos_md_hahen_3(MdHahenWork* work) {
    ReleaseObjPalette((void*)work->unk_018);
    ReleaseObjTiles((void*)work->unk_01C);
}

#ifndef VERSION_EU
void func_080FD9B8(u16 model, u16 slot) {
    void* src;
    s32 size;

    if (gUnk_09992F70[(s16)model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_09A3CDDC;
        size = 0x40;
    } else {
        src = gUnk_09992F70[(s16)model].unk_08;
        size = 0x20;
    }

    gUnk_02034FF8[(s16)slot].unk_0C = LoadObjPalette(src, size);
}
#else
INCLUDE_ASM("bos5/func_080FD9B8.s");
#endif

#ifndef VERSION_EU
void func_080FDA28(u16 model, u16 slot) {
    void* src;

    if (gUnk_09992F70[(s16)model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_099EDE7C;
    } else {
        src = gUnk_09992F70[(s16)model].unk_0C;
    }

    gUnk_02034FF8[(s16)slot].unk_10 = LoadObjTiles(src, 0x1000);
}
#else
INCLUDE_ASM("bos5/func_080FDA28.s");
#endif

#ifndef VERSION_EU
s16 func_080FDA98(u16 model, u16 slot) {
    if (gUnk_09992F70[(s16)model].unk_02 == 13 && func_080D2DD8()) {
        gUnk_02034FF8[(s16)slot].unk_14 = gUnk_099A8914;
    } else {
        gUnk_02034FF8[(s16)slot].unk_14 = gUnk_09992F70[(s16)model].unk_10;
    }
}
#else
INCLUDE_ASM("bos5/func_080FDA98.s");
#endif

INCLUDE_ASM("bos5/func_080FDB1C.s");
INCLUDE_ASM("bos5/func_080FE89C.s");
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
INCLUDE_ASM("bos5/func_080FF228.s");
INCLUDE_ASM("bos5/func_080FF2B8.s");
INCLUDE_ASM("bos5/func_080FF310.s");
INCLUDE_ASM("bos5/func_080FF330.s");
INCLUDE_ASM("bos5/func_080FF794.s");
INCLUDE_ASM("bos5/func_080FF8CC.s");
