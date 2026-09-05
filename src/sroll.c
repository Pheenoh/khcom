#include "lib.h"
#include "m4a.h"
#include "macros.h"
#include "sio.h"
#include "sroll.h"
#include "types.h"

DmaStream gUnk_02036028;
u8 gUnk_02036048;
u32 gUnk_0203604C;
s32 gUnk_02036050[0x810];
u32* gUnk_02038090;
s32 gUnk_02038094;
s32 gUnk_02038098;
u32 gUnk_0203809C;
s32 gUnk_020380A0;
s32 gUnk_020380A4;
s8 gUnk_020380A8[0x2C0];
s8 gUnk_02038368[0x2C0];

#define REG_ADDR_DMA0 0x040000B0

#define DMA_SOUND_FIFO                                                        \
    ((DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT | DMA_DEST_FIXED) << 16)

#define SOUND_MASTER_ENABLE 0x0080

void task_sroll_a_name_0(SrollANameWork* w, SrollANameArg* a) {
    AnimState* anim;

    w->unk_02 = a->unk_00;
    w->unk_08 = a->unk_08;
    w->unk_0C = a->unk_0C;
    w->unk_10 = a->unk_10;
    w->unk_14 = a->unk_14;
    w->unk_00 = 0;
    w->unk_04 = 0;

    switch (a->unk_00) {
    case 0:
#ifdef VERSION_JP
        w->tiles = LoadObjTiles(gUnk_09C638BE, 45 * 32);
#else
        w->tiles = LoadObjTiles(gUnk_09C638BE, 35 * 32);
#endif
        anim = &w->anim;
        AnimInit(anim, (s32)gUnk_09EFB200, (s32)gUnk_09EFB1F8);
        AnimStart(anim, a->unk_02, 0);
        break;
    case 1:
        w->tiles = LoadObjTiles(gUnk_09A54218[a->unk_04][0], *(u16*)&gUnk_09A54218[a->unk_04][1]);
        anim = &w->anim;
        AnimInit(anim, (s32)gUnk_09EFB244, (s32)gUnk_09EFB208);
        AnimStart(anim, a->unk_02, 0);
        break;
    case 2:
        w->tiles = LoadObjTiles(gUnk_09A54218[a->unk_04][0], *(u16*)&gUnk_09A54218[a->unk_04][1]);

        if (a->unk_02 == 1) {
            anim = &w->anim;
            AnimInit(anim, (s32)gUnk_09EFB5EC, (s32)gUnk_09EFB5B0);
        } else {
            anim = &w->anim;
            AnimInit(anim, (s32)gUnk_09EFB244, (s32)gUnk_09EFB208);
        }
        AnimStart(anim, 2, 0);
        gBldCnt = 0x140;
        gBldAlpha = 0;
        break;
    }
    w->palette = LoadObjPalette(gUnk_09D6CD74, 64);
}

u8 task_sroll_a_name_1(SrollANameWork* w) {
    w->unk_04++;

    if (w->unk_02 == 2) {
        if (w->unk_04 <= 47) {
            gBldAlpha = w->unk_04 / 3;
        } else {
            if (w->unk_04 == 48) {
                gBldCnt = 0;
                gBldAlpha = 0;
            }
            AnimUpdate(&w->anim);
        }
    } else {
        AnimUpdate(&w->anim);
    }
    return 1;
}

#ifdef NON_MATCHING
void task_sroll_a_name_2(SrollANameWork* w) {
    s32 x;
    s32 y;
    s32 flags;
    s32 ofs;

    if (w->unk_04 <= 29) {
        x = w->unk_08 + (w->unk_10 - w->unk_08) * w->unk_04 / 30;
        y = w->unk_0C + (w->unk_14 - w->unk_0C) * w->unk_04 / 30;
    } else {
        x = w->unk_10;
        y = w->unk_14;
    }

    flags = 0;

    if (w->unk_02 == 2) {
        flags = 4;
        ofs = AnimGetFrame(&w->anim) * 32 + 32;
        LoadPalette(&gUnk_09D6CD74[ofs], &gUnk_05000220[(w->palette->unk_06 & 15) * 32], 32);
    }
    DrawSprite(x >> 8, y >> 8, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, flags,
               0xFF0 - w->unk_02);
}
#else
INCLUDE_ASM("sroll/task_sroll_a_name_2.s");
#endif

void task_sroll_a_name_3(SrollANameWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

static s32 func_081149A8(s32 x) {
    return x * x;
}

void func_081149B0(SrollBCharWork* w, s32 v) {
    *w->unk_04 = v;
}

void func_081149B8(SrollBCharWork* w) {
    SrollBCharDef* def;
    SrollBCharGfx* gfx;

    def = w->unk_08->unk_00;
    gfx = def->unk_00;
    func_08005974(&w->anim, def->unk_0C, def->unk_0E, gfx->unk_04, gfx->unk_00);
    func_08002A10(w->tiles, gfx->unk_08);
    w->unk_08->unk_14 &= 0xFFFE;
}

void task_sroll_b_char_0(SrollBCharWork* w, SrollBCharArg* a) {
    SrollBCharSet* set;
    AnimState* anim;

    set = a->unk_00;
    w->unk_00 = 0;
    w->unk_04 = 0;
    w->unk_08 = a->unk_04;
    w->tiles = AllocObjTiles((u16)(set->unk_00 * 32), 0);
    w->palette = LoadObjPalette(set->unk_08, 32);
    anim = &w->anim;
    AnimInit(anim, 0, 0);
    w->unk_08->unk_18 = anim;
    w->unk_08->unk_1C = w->palette->unk_06;
    func_081149B8(w);
    TaskPoolInit(&w->unk_2C, 4);
}

INCLUDE_ASM("sroll/task_sroll_b_char_1.s");
void task_sroll_b_char_2(SrollBCharWork* w) {
    SrollBCharSub* sub;
    void* gfx;
    u16 x;
    u16 y;

    sub = w->unk_08;

    if ((sub->unk_14 & 2) == 0) {
        x = sub->unk_04 >> 8;
        y = (sub->unk_08 + sub->unk_0C) >> 8;
        gfx = AnimGetGfx(&w->anim);
        DrawSprite(x, y, gfx, w->tiles, w->palette,
                   AllocObjAffine(sub->unk_28, sub->unk_20, sub->unk_24, 1), sub->unk_16, 0xFF0);
        TaskPoolDraw(&w->unk_2C);
    }
}

void task_sroll_b_char_3(SrollBCharWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
    TaskPoolDestroy(&w->unk_2C);
}

static s32 func_08114C1C(s32 x) {
    return x * x;
}

#ifndef VERSION_EU
void task_sroll_b_logo_0(SrollBLogoWork* w, SrollBLogoArg* a) {
    AnimState* anim;
    u32 i;

    w->unk_00 = a->unk_00;
    w->unk_04 = a->unk_04;
    w->unk_08 = a->unk_08;
    w->unk_0C = a->unk_0C;
    w->tiles = LoadObjTiles(gUnk_09C5CC7C, 94 * 32);
    w->palette = LoadObjPalette(gUnk_09D6BE34, 64);
    anim = &w->anim;
    AnimInit(anim, (s32)gUnk_09EFAF6C, (s32)gUnk_09EFAF60);
    AnimStart(anim, a->unk_10, 0);

    for (i = 0; i < 2; i++) {
        func_080062F4((w->palette->unk_06 + i) % 16 + 16, 1);
    }
}
#else
INCLUDE_ASM("sroll/task_sroll_b_logo_0.s");
#endif

u8 task_sroll_b_logo_1(SrollBLogoWork* w) {
    u8 r;

    r = 1;

    if ((s16)((w->unk_04 >> 8) - (*w->unk_08 >> 8)) <= -32) {
        r = 0;
    }
    AnimUpdate(&w->anim);
    return r;
}

void task_sroll_b_logo_2(SrollBLogoWork* w) {
    u16 y;

    y = (w->unk_04 >> 8) - (*w->unk_08 >> 8);
    DrawSprite(w->unk_00 >> 8, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0, 0xFF0);
}

void task_sroll_b_logo_3(SrollBLogoWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

static s32 func_08114D2C(s32 x) {
    return x * x;
}

INCLUDE_ASM("sroll/task_sroll_b_secn_0.s");

u8 task_sroll_b_secn_1(SrollBSecnWork* w) {
    u8 r;
    s16 y;

    r = 1;
    y = (w->unk_08 >> 8) - (*w->unk_0C >> 8);
    if (y <= -32) {
        r = 0;
    }

    if (y <= 159) {
        func_0800592C(&w->unk_04, 0x7800, 20);

        if (abs(w->unk_04 - 0x7800) <= 255) {
            w->unk_04 = 0x7800;
        }

        if (w->unk_04 == 0x7800) {
            AnimUpdate(&w->unk_1C);
            AnimUpdate(&w->unk_34);
        }
    }
    w->unk_00++;
    return r;
}

void task_sroll_b_secn_2(SrollBSecnWork* w) {
    u16 y;

    y = (w->unk_08 >> 8) - (*w->unk_0C >> 8);
    DrawSprite(120, y, AnimGetGfx(&w->unk_1C), w->tiles, w->unk_18, 0, 0, 0xEF0);
    DrawSprite(120, y, AnimGetGfx(&w->unk_34), w->tiles, w->unk_18, 0, 0, 0xEE0);
}

void task_sroll_b_secn_3(SrollBSecnWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->unk_18);
}

static s32 func_08114F3C(s32 x) {
    return x * x;
}

#ifdef NON_MATCHING
void task_sroll_b_crtn_0(SrollBCrtnWork* w, SrollBCrtnArg* a) {
    AnimState* anim;
    s32 t;

    w->unk_00 = 0;
    w->unk_04 = a->unk_00;
    switch (w->unk_04) {
    case 0:
    case 1:
    case 5:
        w->unk_08 = a->unk_04;
        w->unk_0C = a->unk_08 + 0xFFFFE000;
        w->tiles = AllocObjTiles(128, gUnk_09320796);
        w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
        anim = &w->anim;
        AnimInit(anim, (s32)gUnk_09EEFD38, (s32)gUnk_09EEFCAC);
        AnimStart(anim, w->unk_04, 0);
        break;
    case 3:
        w->unk_08 = a->unk_04;
        w->unk_0C = a->unk_08 + 0xFFFFD000;
        w->tiles = AllocObjTiles(128, gUnk_09320796);
        w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
        anim = &w->anim;
        AnimInit(anim, (s32)gUnk_09EEFD38, (s32)gUnk_09EEFCAC);
        AnimStart(anim, 0, 0);
        break;
    case 2:
        t = (GetRandom() % 9) * 256 - 0x400;
        w->unk_08 = t + a->unk_04;
        t = (GetRandom() % 9) * 256 - 0x400;
        w->unk_0C = t + a->unk_08;
        w->tiles = AllocObjTiles(128, gUnk_088A5D7A);
        w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
        anim = &w->anim;
        AnimInit(anim, (s32)gUnk_09EDE7E4, (s32)gUnk_09EDE7B4);
        AnimStart(anim, w->unk_04, 0);
        break;
    }
    func_080062F4((w->palette->unk_06 & 15) + 16, 0);
}
#else
INCLUDE_ASM("sroll/task_sroll_b_crtn_0.s");
#endif

u8 task_sroll_b_crtn_1(SrollBCrtnWork* w) {
    u8 r;

    r = 1;
    AnimUpdate(&w->anim);
    w->unk_00++;

    switch (w->unk_04) {
    case 1:
        if (w->unk_00 > 120) {
            r = 0;
        }
        break;
    case 2:
        w->unk_0C += 0x100;

        if (w->unk_00 > 20) {
            r = 0;
        }
        break;
    case 5:
        if (w->unk_00 == 12) {
            AnimStart(&w->anim, 6, 1);
        }
    case 0:
    case 3:
        if (w->unk_00 > 50) {
            r = 0;
        }
        break;
    }
    return r;
}

void task_sroll_b_crtn_2(SrollBCrtnWork* w) {
    DrawSprite(w->unk_08 >> 8, w->unk_0C >> 8, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x400,
               0xFE0);
}

void task_sroll_b_crtn_3(SrollBCrtnWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

static s32 func_08115178(s32 x) {
    return x * x;
}

#ifndef VERSION_EU
void task_sroll_c_char_0(SrollCCharWork* w, s32 kind) {
    AnimState* p;
    s32 i;

    if (kind == 0) {
#ifdef VERSION_JP
        w->tiles = LoadObjTiles(gUnk_09C8D47A, 200 * 16);
#else
        w->tiles = LoadObjTiles(gUnk_09C8D47A, 154 * 32);
#endif
        w->palette = LoadObjPalette(gUnk_09D6CF54, 224);

        for (i = 0, p = w->unk_20; i <= 4; i++) {
            AnimInit(p, (s32)gUnk_09EFB9B8, (s32)gUnk_09EFB840);
            AnimStart(p, i, 0);
            p++;
        }
    } else {
#ifdef VERSION_JP
        w->tiles = LoadObjTiles(gUnk_09C8F1FA, 200 * 16);
#else
        w->tiles = LoadObjTiles(gUnk_09C8F1FA, 146 * 32);
#endif
        w->palette = LoadObjPalette(gUnk_09D6D034, 224);

        for (i = 0, p = w->unk_20; i <= 4; i++) {
            AnimInit(p, (s32)gUnk_09EFBAD4, (s32)gUnk_09EFB9CC);
            AnimStart(p, i, 0);
            p++;
        }
    }
}
#else
INCLUDE_ASM("sroll/task_sroll_c_char_0.s");
#endif

u8 task_sroll_c_char_1(SrollCCharWork* w) {
    AnimState* p;
    s32 i;

    p = w->unk_20;

    for (i = 4; i >= 0; i--) {
        AnimUpdate(p);
        p++;
    }
    return 1;
}

void task_sroll_c_char_2(SrollCCharWork* w) {
    AnimState* p;
    s32 i;
    s32 flags;

    flags = 0;
    p = w->unk_20;

    for (i = 4; i >= 0; i--) {
        DrawSprite(120, 80, AnimGetGfx(p), w->tiles, w->palette, 0, flags, 0xFF0);
        p++;
    }
}

void task_sroll_c_char_3(SrollCCharWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

static s32 func_0811529C(s32 x) {
    return x * x;
}

void task_sroll_tmr_0(SrollTmrWork* w, void* arg) {
    w->unk_00 = 0;
    w->unk_04 = 0;
    w->tiles = LoadObjTiles(gUnk_09C904B4, 352);
    w->palette = LoadObjPalette(gUnk_09D6D114, 32);
}

u8 task_sroll_tmr_1(SrollTmrWork* w) {
    u8 r;

    r = 1;

    if (GetKeysPressed() & 4) {
        if (w->unk_00 == 1) {
            w->unk_00 = 0;
        } else {
            w->unk_00 = r;
        }
    }
    func_080062F4((w->palette->unk_06 & 15) + 16, 1);
    w->unk_04++;
    return r;
}

INCLUDE_ASM("sroll/task_sroll_tmr_2.s");
void task_sroll_tmr_3(SrollTmrWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
}

void func_0811549C(void) {
}

void func_081154A0(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_081154EC(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_08115548(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        v |= pal[(c >> 29) & 1] << 8;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_081155B0(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        v |= pal[(c >> 29) & 1] << 8;
        v |= pal[(c >> 28) & 1] << 12;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_08115628(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        v |= pal[(c >> 29) & 1] << 8;
        v |= pal[(c >> 28) & 1] << 12;
        v |= pal[(c >> 27) & 1] << 16;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_081156AC(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        v |= pal[(c >> 29) & 1] << 8;
        v |= pal[(c >> 28) & 1] << 12;
        v |= pal[(c >> 27) & 1] << 16;
        v |= pal[(c >> 26) & 1] << 20;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_08115740(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        v |= pal[(c >> 29) & 1] << 8;
        v |= pal[(c >> 28) & 1] << 12;
        v |= pal[(c >> 27) & 1] << 16;
        v |= pal[(c >> 26) & 1] << 20;
        v |= pal[(c >> 25) & 1] << 24;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

#ifdef NON_MATCHING
void func_081157E0(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    u32* d;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];
    d = dst;

    for (i = 0; i <= 7; i++) {
        c = src[i] << 24;
        v = pal[(c >> 31) & 1];
        v |= pal[(c >> 30) & 1] << 4;
        v |= pal[(c >> 29) & 1] << 8;
        v |= pal[(c >> 28) & 1] << 12;
        v |= pal[(c >> 27) & 1] << 16;
        v |= pal[(c >> 26) & 1] << 20;
        v |= pal[(c >> 25) & 1] << 24;
        v |= pal[src[i] & 1] << 28;
        d[0] |= v << t->unk_00;
        d[8] |= v >> t->unk_04;
        d++;
    }
}
#else
INCLUDE_ASM("sroll/func_081157E0.s");
#endif
u32 func_0811589C(SrollBlit* w) {
    SrollMask* m;
    u32* d;
    u32* p;
    u32 k;
    s32 e;
    u32 r;

    e = w->unk_00 + w->unk_04;
    p = w->unk_14;
    d = w->unk_0C;
    m = &gUnk_09A54918[w->unk_04][w->unk_00];
    k = m->unk_00 | m->unk_08;
    p[0] = d[0] & k;
    p[1] = d[1] & k;
    p[2] = d[2] & k;
    p[3] = d[3] & k;
    p[4] = d[4] & k;
    p[5] = d[5] & k;
    p[6] = d[6] & k;
    p[7] = d[7] & k;

    if (e > 8) {
        k = m->unk_04;
        p[8] = d[8] & k;
        p[9] = d[9] & k;
        p[10] = d[10] & k;
        p[11] = d[11] & k;
        p[12] = d[12] & k;
        p[13] = d[13] & k;
        p[14] = d[14] & k;
        p[15] = d[15] & k;
    }
    gUnk_09A54CB8[w->unk_04](p, w->unk_08, w->unk_10, w->unk_00);
    d[0] = p[0];
    d[1] = p[1];
    d[2] = p[2];
    d[3] = p[3];
    d[4] = p[4];
    d[5] = p[5];
    d[6] = p[6];
    d[7] = p[7];

    if (e > 8) {
        d[8] = p[8];
        d[9] = p[9];
        d[10] = p[10];
        d[11] = p[11];
        d[12] = p[12];
        d[13] = p[13];
        d[14] = p[14];
        d[15] = p[15];
    }
    r = 1;

    if (e > 8) {
        r = 2;
    }
    return r;
}

void func_081159AC(void) {
}

void func_081159B0(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    u32* d;
    u16* s;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];
    d = dst;
    s = src;

    for (i = 0; i <= 7; i++) {
        c = *s << 16;
        v = pal[(c >> 22) & 3];
        d[0] |= v << t->unk_00;
        d[8] |= v >> t->unk_04;
        d++;
        s++;
    }
}

void func_081159FC(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

void func_08115A5C(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        v |= pal[(c >> 18) & 3] << 8;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}

#ifdef NON_MATCHING
void func_08115AD4(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        v |= pal[(c >> 18) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
#else
INCLUDE_ASM("sroll/func_08115AD4.s");
#endif
#ifdef NON_MATCHING
void func_08115B6C(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        v |= pal[(c >> 18) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(c >> 30) & 3] << 16;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
#else
INCLUDE_ASM("sroll/func_08115B6C.s");
#endif
#ifdef NON_MATCHING
void func_08115C04(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        v |= pal[(c >> 18) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(c >> 30) & 3] << 16;
        v |= pal[(c >> 28) & 3] << 20;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
#else
INCLUDE_ASM("sroll/func_08115C04.s");
#endif
#ifdef NON_MATCHING
void func_08115CAC(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        v |= pal[(c >> 18) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(c >> 30) & 3] << 16;
        v |= pal[(c >> 28) & 3] << 20;
        v |= pal[(c >> 26) & 3] << 24;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
#else
INCLUDE_ASM("sroll/func_08115CAC.s");
#endif
#ifdef NON_MATCHING
void func_08115D60(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;
    u32 c;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        c = src[i] << 16;
        v = pal[(c >> 22) & 3];
        v |= pal[(c >> 20) & 3] << 4;
        v |= pal[(c >> 18) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(c >> 30) & 3] << 16;
        v |= pal[(c >> 28) & 3] << 20;
        v |= pal[(c >> 26) & 3] << 24;
        v |= pal[(c >> 24) & 3] << 28;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
#else
INCLUDE_ASM("sroll/func_08115D60.s");
#endif
u32 func_08115E24(SrollBlit* w) {
    SrollMask* m;
    u32* d;
    u32* p;
    u32 k;
    s32 e;
    u32 r;

    e = w->unk_00 + w->unk_04;
    p = w->unk_14;
    d = w->unk_0C;
    m = &gUnk_09A54918[w->unk_04][w->unk_00];
    k = m->unk_00 | m->unk_08;
    p[0] = d[0] & k;
    p[1] = d[1] & k;
    p[2] = d[2] & k;
    p[3] = d[3] & k;
    p[4] = d[4] & k;
    p[5] = d[5] & k;
    p[6] = d[6] & k;
    p[7] = d[7] & k;

    if (e > 8) {
        k = m->unk_04;
        p[8] = d[8] & k;
        p[9] = d[9] & k;
        p[10] = d[10] & k;
        p[11] = d[11] & k;
        p[12] = d[12] & k;
        p[13] = d[13] & k;
        p[14] = d[14] & k;
        p[15] = d[15] & k;
    }
    gUnk_09A54CDC[w->unk_04](p, w->unk_08, w->unk_10, w->unk_00);
    d[0] = p[0];
    d[1] = p[1];
    d[2] = p[2];
    d[3] = p[3];
    d[4] = p[4];
    d[5] = p[5];
    d[6] = p[6];
    d[7] = p[7];

    if (e > 8) {
        d[8] = p[8];
        d[9] = p[9];
        d[10] = p[10];
        d[11] = p[11];
        d[12] = p[12];
        d[13] = p[13];
        d[14] = p[14];
        d[15] = p[15];
    }
    r = 1;

    if (e > 8) {
        r = 2;
    }
    return r;
}

u16 func_08115F34(u16 c, u8* font) {
    u16 result;
    s32 off;
    s32 hi;
    s32 a;
    s32 b;
    u8 v;

    result = 0;
    off = (c & 0x7F00) >> 6;
    hi = font[off + 1] << 8;
    a = font[off] | hi;
    hi = font[off + 3] << 8;
    b = font[off + 2] | hi;

    if (a != 0xFFFF) {

        if (font[(u16)(a + 0xFFC0 + (c & 0xFF))] != 0xFF) {
            v = font[(u16)(a + 0xFFC0 + (c & 0xFF))];
            result = b + v;
        }
    }
    return result;
}

u8 func_08115F8C(u16 c, u8* font, u8* widths, u32 count) {
    u8 w;

    w = 0;

    if (widths != 0) {
        u16 idx = func_08115F34(c, font);
        if (idx < count) {
            w = widths[idx];
        }
    }

    if (w == 0) {
        w = 8;
    }
    return w;
}

s32 func_08115FBC(SrollWork* w, u8* s) {
    s32 total;
    u16 c;
    s32 hi;

    total = 0;

    while (*s != 0) {
        if (*s & 0x80) {
            hi = s[0] << 8;
            c = s[1] | hi;
            s += 2;
        } else {
            c = func_08116CDC(s[0]);
            s += 1;
        }
        total += func_08115F8C(c, w->unk_34, w->unk_3C, w->unk_40);
    }
    return total;
}

u32 func_08116008(u16 c, u8* font, u32 base, u16 a, u16 b) {
    return base + func_08115F34(c, font) * (a << 3) * b;
}

u32 func_08116034(SrollWork* w, u32* dst, u8* src, s32 width) {
    SrollBlit b;
    u32 pal[16];
    u32 fill;
    u32* q;
    u32 bg;
    u32 r;
    u16 c;
    u16 n;

    r = 0;
    pal[0] = c = w->unk_06;
    pal[1] = w->unk_02;
    pal[2] = w->unk_04;
    pal[3] = w->unk_08;
    bg = (c << 4) | c;
    bg |= bg << 8;
    bg |= bg << 16;
    b.unk_00 = w->unk_20 & 7;
    b.unk_04 = width;
    b.unk_08 = src;
    b.unk_0C = dst;
    b.unk_10 = pal;
    n = w->unk_24;

    if (n-- != 0) {
        q = &fill;
        do {
            if (b.unk_00 == 0) {
                *q = bg;
                CpuFastSet(q, b.unk_0C, CPU_SET_SRC_FIXED | 8);
            }

            switch (w->unk_26) {
            case 1:
                r = func_0811589C(&b);
                break;
            case 2:
                r = func_08115E24(&b);
                break;
            }
            b.unk_08 += w->unk_26 * 8;
            b.unk_0C += w->unk_1C * 8;
        } while (n-- != 0);
    }
    return r;
}

void func_081160EC(SrollWork* w, u32 mode) {
    if (mode > 1) {
        mode = 0;
    }
    w->unk_26 = gUnk_09A5B440[mode].unk_00;
    w->unk_24 = gUnk_09A5B440[mode].unk_02;
    w->unk_34 = gUnk_09A5B440[mode].unk_04;
    w->unk_38 = gUnk_09A5B440[mode].unk_08;
    w->unk_3C = gUnk_09A5B440[mode].unk_0C;
    w->unk_40 = gUnk_09A5B440[mode].unk_10;
    w->unk_44 = gUnk_09A5B440[mode].unk_14;
    func_08116228(w, w->unk_20, w->unk_22);
}

void func_0811614C(SrollWork* w, SrollInit* a) {
    func_081160EC(w, a->unk_04);
    func_08116268(w, a->unk_20, a->unk_22, a->unk_24, a->unk_26);
    w->unk_0A = 32;
    w->unk_00 = 0;
    w->unk_0C = a->unk_28;
    w->unk_10 = a->unk_2C;
    w->unk_12 = a->unk_2E;
    w->unk_14 = a->unk_30;
    w->unk_16 = a->unk_32;
    w->unk_18 = a->unk_34;
    w->unk_1A = a->unk_36;
    w->unk_1C = a->unk_38;
    w->unk_1E = a->unk_3A;
    w->unk_2C = a->unk_08;
    w->unk_2E = a->unk_0A;
    w->unk_30 = a->unk_0C;
    w->unk_48 = a->unk_10;
    w->unk_4C = a->unk_14;
    w->unk_50 = a->unk_18;
    w->unk_54 = a->unk_1C;
    func_081161D4(w);
    func_08116698(w, 1);
}

void func_081161C8(SrollWork* w) {
    func_0811627C(w, 1);
}

void func_081161D4(SrollWork* w) {
    w->writeIdx = 0;
    w->readIdx = 0;
}

u8 func_081161DC(SrollWork* w) {
    u8 r;

    r = 0;

    if (w->writeIdx == w->readIdx) {
        r = 1;
    }
    return r;
}

void func_081161EC(SrollWork* w, u16 c) {
    w->charQueue[w->writeIdx] = c;
    w->writeIdx = (w->writeIdx + 1) & 0xFF;
}

u16 sub_08116204(SrollWork* w) {
    u16 c;

    if (w->writeIdx == w->readIdx) {
        return 0;
    }
    c = w->charQueue[w->readIdx];
    w->readIdx = (w->readIdx + 1) & 0xFF;
    return c;
}

void func_08116228(SrollWork* w, u16 x, u16 y) {
    if (x >= w->unk_1C) {
        x = 0;
    }

    if (y + w->unk_24 > w->unk_1E) {
        y = 0;
    }
    w->unk_20 = x * 8;
    w->unk_22 = y;
}

void func_08116254(SrollWork* w, u16 x) {
    if (x >= w->unk_1C * 8) {
        x = 0;
    }
    w->unk_20 = x;
}

void func_08116268(SrollWork* w, u16 a, u16 b, u16 c, u16 d) {
    w->unk_02 = a;
    w->unk_04 = b;
    w->unk_06 = c;
    w->unk_08 = d;
}

void func_0811627C(SrollWork* w, u8 flush) {
    u16 fill[1];
    u16* p;
    u16 i;

    p = (u16*)((u8*)sub_08116B10(w) + w->unk_12 * w->unk_0A * 2 + w->unk_10 * 2);

    for (i = 0; i < w->unk_16; i++) {
        fill[0] = w->unk_2C;
        CpuSet(fill, p, w->unk_14 | CPU_SET_SRC_FIXED);
        p += w->unk_0A;
    }

    if (flush == 1) {
        func_08116B1C(w);
    }
}

void func_081162E8(SrollWork* w) {
    u16 a;
    u16 b;
    u16 c;
    u16* p;
    u16* q;
    u16 i;
    u16 t;

    p = (u16*)((u8*)sub_08116B10(w) + w->unk_12 * w->unk_0A * 2 + w->unk_10 * 2);
    t = w->unk_2E + 1;
    q = &a;
    a = t + 2;
    CpuSet(q, p + 1, (((u32)(w->unk_14 - 2) << 11) >> 11) | CPU_SET_SRC_FIXED);
    p[0] = t + 1;
    p[w->unk_14 - 1] = t + 3;
    p += w->unk_0A;

    for (i = 1; i < w->unk_16 - 1; i++) {
        b = t;
        CpuSet(&b, p + 1, (((u32)(w->unk_14 - 2) << 11) >> 11) | CPU_SET_SRC_FIXED);
        p[0] = t + 4;
        p[w->unk_14 - 1] = t + 5;
        p += w->unk_0A;
    }
    c = t + 7;
    CpuSet(&c, p + 1, (((u32)(w->unk_14 - 2) << 11) >> 11) | CPU_SET_SRC_FIXED);
    p[0] = t + 6;
    p[w->unk_14 - 1] = t + 8;
}
INCLUDE_ASM("sroll/func_081163CC.s");
INCLUDE_ASM("sroll/func_08116500.s");
void func_08116644(SrollWork* w) {
    u16 fill;
    u16* p;
    u16 i;
    u16 t;

    p = (u16*)((u8*)sub_08116B10(w) + w->unk_1A * w->unk_0A * 2 + w->unk_18 * 2);
    t = w->unk_2E + 1;

    for (i = 0; i < w->unk_1E; i++) {
        fill = t;
        CpuSet(&fill, p, w->unk_1C | CPU_SET_SRC_FIXED);
        p += w->unk_0A;
    }
}
void func_08116698(SrollWork* w, u8 flush) {
    u16 t;

    switch (w->unk_0C) {
    case 1:
        func_081162E8(w);
        break;
    case 2:
        func_081163CC(w);
        break;
    case 3:
        func_08116500(w);
        break;
    default:
        func_08116644(w);
        break;
    }
    func_08116228(w, 0, 0);

    if (flush == 1) {
        func_08116B1C(w);
    } else {
        t = w->unk_00 | 1;
        w->unk_00 = t;
    }
}
#ifdef NON_MATCHING
void func_081166F8(SrollWork* w, u16 x, u16 y, u16 cw, u16 ch, u8 flush) {
    u16 fill;
    u16* p;
    u16 i;
    u16 t;
    u16 v;

    if (x >= w->unk_1C) {
        return;
    }

    if (y >= w->unk_1E) {
        return;
    }

    if (x + cw > w->unk_1C) {
        cw = w->unk_1C - x;
    }

    if (y + ch > w->unk_1E) {
        ch = w->unk_1E - y;
    }

    p = (u16*)((u8*)sub_08116B10(w) + (w->unk_1A + y) * w->unk_0A * 2 + (w->unk_18 + x) * 2);
    v = w->unk_2E + 1;
    i = 0;

    while (i < ch) {
        fill = v;
        CpuSet(&fill, p, cw | CPU_SET_SRC_FIXED);
        p += w->unk_0A;
        i++;
    }

    if (flush == 1) {
        func_08116B1C(w);
    } else {
        t = w->unk_00 | 1;
        w->unk_00 = t;
    }
}
#else
INCLUDE_ASM("sroll/func_081166F8.s");
#endif

void func_081167CC(void) {
}

u16 func_081167D0(u16 c) {
    u16 v;

    v = c;
    if ((u16)(v - '0') <= 9) {
        v -= '0';
    } else {
        v -= 'a';
        v += 10;
    }
    return v;
}
u8* func_081167F8(SrollWork* w, u8* s) {
    s32 hi;

    while (*s != 0) {
        if (*s & 0x80) {
            hi = s[0] << 8;
            func_081161EC(w, s[1] | hi);
            s += 2;
        } else {
            func_081161EC(w, func_08116CDC(s[0]));
            s += 1;
        }
    }
    return s + 1;
}
u8 sub_0811683C(SrollWork* w) {
    u16 v[2];
    u16* p;
    u32 off;
    u32 g;
    u32 n;
    u16 c;
    u16 t;
    u16 i;
    u8 r;
    u8 wd;

    r = 0;

    if (w->unk_20 >= w->unk_1C * 8) {
        w->unk_20 = 0;
    }
    c = sub_08116204(w);
    if (c & 0xFF00) {
        off = (w->unk_22 * w->unk_1C + (w->unk_20 >> 3)) * 32;
        g = func_08116008(c, w->unk_34, w->unk_38, w->unk_26, w->unk_24);
        wd = func_08115F8C(c, w->unk_34, w->unk_3C, w->unk_40);
        n = func_08116034(w, (u32*)(w->unk_50 + off), (u8*)g, wd);
        t = w->unk_22 * w->unk_1C + (w->unk_20 >> 3) + w->unk_30;
        p = (u16*)((u8*)sub_08116B10(w) +
                   ((w->unk_1A + w->unk_22) * w->unk_0A + ((w->unk_20 >> 3) + w->unk_18)) * 2);

        for (i = 0; i < w->unk_24; i++) {
            if (n == 1) {
                p[0] = t;
            } else {
                p[0] = t;
                p[1] = t + 1;
            }
            p += w->unk_0A;
            t += w->unk_1C;
        }
        w->unk_20 += wd;
        w->unk_00 |= 1;
        r = 1;
    } else {
        switch (c) {
        case '@':
            v[0] = sub_08116204(w);
            v[1] = sub_08116204(w);

            switch (v[0]) {
            case 'F':
                func_081160EC(w, func_081167D0(v[1]));
                break;
            case 'f':
                w->unk_02 = func_081167D0(v[1]);
                break;
            case 's':
                w->unk_04 = func_081167D0(v[1]);
                break;
            case 'b':
                w->unk_06 = func_081167D0(v[1]);
                break;
            case 'e':
                w->unk_08 = func_081167D0(v[1]);
                break;
            }
            break;
        case 0:
            break;
        case '\n':
            w->unk_20 = 0;
            w->unk_22 += w->unk_24;

            if (w->unk_22 + w->unk_24 > w->unk_1E) {
                w->unk_22 = 0;
            }
            break;
        }
    }
    return r;
}
void func_08116A98(SrollWork* w, u8 flush) {
    u8 r;

    r = 0;
    while (!func_081161DC(w) && r == 0) {
        r = sub_0811683C(w);
    }

    if (flush == 1 && (w->unk_00 & 1)) {
        func_08116B1C(w);
    }
}

void func_08116AD8(SrollWork* w, u8 flush) {
    while (!func_081161DC(w)) {
        sub_0811683C(w);
    }

    if (flush == 1 && (w->unk_00 & 1)) {
        func_08116B1C(w);
    }
}

u32 sub_08116B10(SrollWork* w) {
    u32 v;

    v = w->unk_4C;
    if (v == 0) {
        v = w->unk_54;
    }
    return v;
}

void func_08116B1C(SrollWork* w) {
    u32 off;

    if (w->unk_4C != 0) {
        off = w->unk_12 * w->unk_0A * 2;
        RequestDma3Copy((u8*)w->unk_4C + off, (u8*)w->unk_54 + off, w->unk_16 * w->unk_0A * 2);
    }
    w->unk_00 &= 0xFFFE;
}

void func_08116B54(SrollWork* w, u8* s, u8 flush) {
    func_08116AD8(w, 0);
    func_081167F8(w, s);
    func_08116AD8(w, 0);

    if (flush == 1 && (w->unk_00 & 1)) {
        func_08116B1C(w);
    }
}

void func_08116B90(SrollWork* w, u16 x, u16 y, u8* s, u8 flush) {
    func_08116AD8(w, 0);
    func_08116228(w, x, y);
    func_081167F8(w, s);
    func_08116AD8(w, 0);

    if (flush == 1 && (w->unk_00 & 1)) {
        func_08116B1C(w);
    }
}

void func_08116BEC(SrollWork* w, u16 x, u16 y, u8* s, u8 flush) {
    u32 off;
    u32 g;
    s32 n;

    func_08116AD8(w, 0);
    func_08116228(w, x >> 3, y);
    n = x & 7;
    if (n != 0) {
        off = (w->unk_22 * w->unk_1C + (x >> 3)) * 32;
        g = func_08116008(0x8140, w->unk_34, w->unk_38, w->unk_26, w->unk_24);
        func_08116034(w, (u32*)(w->unk_50 + off), (u8*)g, n);
    }
    func_08116254(w, x);
    func_081167F8(w, s);
    func_08116AD8(w, 0);

    if ((w->unk_20 & 7) != 0) {
        off = (w->unk_22 * w->unk_1C + (w->unk_20 >> 3)) * 32;
        g = func_08116008(0x8140, w->unk_34, w->unk_38, w->unk_26, w->unk_24);
        func_08116034(w, (u32*)(w->unk_50 + off), (u8*)g, 8 - (w->unk_20 & 7));
    }

    if (flush == 1 && (w->unk_00 & 1)) {
        func_08116B1C(w);
    }
}

u16 func_08116CDC(u8 c) {
    return gUnk_09A5B470[c];
}

void func_08116CEC(void) {
    vu16* dma;

    dma = (vu16*)REG_ADDR_DMA0;
    dma[5] &= 0xC5FF;
    dma[5] &= 0x7FFF;
    dma[5];
    gUnk_02036028.unk_00 = 0;
    gUnk_02036028.unk_01 = 0;
    gUnk_02036028.unk_04 = 0;
    gUnk_02036028.dst = 0;
    gUnk_02036028.unk_0C = 0;
    gUnk_02036028.src[0] = 0;
    gUnk_02036028.src[1] = 0;
    gUnk_02036028.cnt = 0;
}

void func_08116D28(void) {
    vu16* dma;
    vu32* dma32;
    u8* src;

    dma = (vu16*)REG_ADDR_DMA0;
    dma[5] &= 0xC5FF;
    dma[5] &= 0x7FFF;
    dma[5];

    if (gUnk_02036028.unk_00 != 0) {
        if (gUnk_02036028.unk_01 != 0) {
            gUnk_02036028.unk_0C ^= 1;
            src = gUnk_02036028.src[gUnk_02036028.unk_0C];
            gUnk_02036028.unk_18 = src;

            if (!(gUnk_02036028.cnt & CPU_SET_SRC_FIXED)) {
                if (gUnk_02036028.cnt & CPU_SET_32BIT) {
                    gUnk_02036028.unk_18 = src + 4;
                } else {
                    gUnk_02036028.unk_18 = src + 2;
                }
            }
            gUnk_02036028.unk_01 = 0;
        }

        if (gUnk_02036028.src[gUnk_02036028.unk_0C] != 0 && gUnk_02036028.dst != 0 &&
            gUnk_02036028.cnt != 0) {
            dma32 = (vu32*)REG_ADDR_DMA0;
            dma32[0] = (u32)gUnk_02036028.unk_18;
            dma32[1] = (u32)gUnk_02036028.dst;
            dma32[2] = gUnk_02036028.cnt;
            dma32[2];
        }

        if (gUnk_02036028.unk_04 != 0) {
            gUnk_02036028.unk_04();
        }
    }
}

void func_08116DD0(void) {
    *gUnk_02036028.dst = *(u32*)gUnk_02036028.src[gUnk_02036028.unk_0C];
}

void func_08116DE8(void) {
    *gUnk_02036028.dst = *(u16*)gUnk_02036028.src[gUnk_02036028.unk_0C];
}

void func_08116E00(vu16* dst, u8* src, u32 cnt) {
    func_08116CEC();
    gUnk_02036028.src[0] = src;
    gUnk_02036028.src[1] = src;
    gUnk_02036028.unk_18 = src;

    if (cnt & CPU_SET_32BIT) {
        gUnk_02036028.unk_04 = func_08116DD0;

        if (!(cnt & CPU_SET_SRC_FIXED)) {
            gUnk_02036028.unk_18 = src + 4;
        }
    } else {
        gUnk_02036028.unk_04 = func_08116DE8;

        if (!(cnt & CPU_SET_SRC_FIXED)) {
            gUnk_02036028.unk_18 = src + 2;
        }
    }
    gUnk_02036028.dst = dst;
    gUnk_02036028.cnt = cnt;
}

void func_08116E60(u8* src) {
    gUnk_02036028.src[gUnk_02036028.unk_0C ^ 1] = src;
    gUnk_02036028.unk_01 = 1;
}

void func_08116E80(void) {
    gUnk_02036028.unk_00 = 1;
}

void func_08116E8C(void) {
    gUnk_02036028.unk_00 = 0;
}

void func_08116E98(void) {
    gUnk_02036048 = 1;
    func_08116F64(func_08116F28());
    func_081170C0(func_08116F20());
    SetVBlankCallback(func_08000714);
    func_08117154();
}

void func_08116ECC(void) {
    if (gUnk_02036048 == 1) {
        gUnk_02036048 = func_08116FE4();
        if (gUnk_02036048 == 0) {
            func_08116F08();
        }
    }
}

void func_08116EF0(void) {
    if (gUnk_02036048 == 1) {
        func_08117194();
    }
}

void func_08116F08(void) {
    ResetVBlankCallback();
    func_08117170();
    m4aSoundInit();
    m4aSoundVSyncOn();
}

u16 func_08116F20(void) {
    return 21024;
}

u32* func_08116F28(void) {
    return gUnk_09A5B674;
}

u8* func_08116F30(u32** p) {
    u32* base;
    u32* q;
    u32 v;

    base = *p;
    q = base;
    v = *q++;

    if ((v & 0xFF) != 0x53) {
        *p = 0;
        return 0;
    }
    *p = (u32*)((u8*)base + (((v >> 8) & 0xFF00) << 2) + ((v >> 24) << 2));
    return (u8*)q;
}

s32 func_08116F64(u32* src) {
    s32* p;
    u8* q;

    for (p = gUnk_02036050; p < gUnk_02036050 + 0x810;) {
        *p++ = 0;
    }
    gUnk_02038090 = src;

    for (gUnk_02038094 = 0; gUnk_02038094 <= 0x7FF; gUnk_02038094 += 0x200) {
        if (gUnk_02038090 != 0) {
            q = func_08116F30(&gUnk_02038090);
            if (q != 0) {
                func_08117F5C(q, (s32)gUnk_02036050, (void*)gUnk_02038094);
            }
        }
    }
    gUnk_02038094 &= 0x7FF;
    gUnk_02038098 = 0;
    return gUnk_02038090 != 0;
}

s32 func_08116FE4(void) {
    u8* q;

    if (gUnk_02038098 > gUnk_02038094 + 0x200 || gUnk_02038098 < gUnk_02038094) {
        if (gUnk_02038090 != 0) {
            q = func_08116F30(&gUnk_02038090);
            if (q != 0) {
                func_08117F5C(q, (s32)gUnk_02036050, (void*)gUnk_02038094);
            }
            gUnk_02038094 = (gUnk_02038094 + 0x200) & 0x7FF;
        }
    }
    return gUnk_02038090 != 0;
}

s32* func_08117044(void) {
    return gUnk_02036050;
}

s32 func_0811704C(void) {
    return gUnk_02038098;
}

void func_08117058(s32 pos) {
    gUnk_02038098 = pos;
}

#ifdef NON_MATCHING
u8 func_08117064(u32 id, u16* rate, u32* count) {
    s32 i;

    for (i = 0; gUnk_09EFAA7C[i].unk_00 != id; i++) {
        if (gUnk_09EFAA7C[i + 1].unk_00 == 0) {
            return 0;
        }
    }
    *rate = gUnk_09EFAA7C[i].unk_08;
    *count = gUnk_09EFAA7C[i].unk_04;
    return 1;
}
#else
INCLUDE_ASM("sroll/func_08117064.s");
#endif

u8 func_081170C0(u32 id) {
    u16 rate;
    s32 i;

    if (!func_08117064(id, &rate, (u32*)&gUnk_020380A4)) {
        return 0;
    }
    REG_SOUNDCNT_H = 0x0B06;
    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE;
    REG_DMA1DAD = (s32)&REG_FIFO_A;
    REG_TM0CNT_L = rate;
    REG_DMA1CNT = DMA_SOUND_FIFO;

    for (i = 0; i < gUnk_020380A4; i++) {
        gUnk_020380A8[i] = gUnk_02038368[i] = 0;
    }
    gUnk_020380A0 = 1;
    REG_DMA1SAD = (s32)gUnk_020380A8;
    return 1;
}

void func_08117154(void) {
    REG_TM0CNT_H = TIMER_ENABLE;
    REG_DMA1CNT |= DMA_ENABLE << 16;
}

void func_08117170(void) {
    REG_DMA1CNT = 0;
    REG_TM0CNT_H = 0;
    REG_SOUNDCNT_H |= 0x800;
}

void func_08117194(void) {
    s32* src;
    s8* dst;
    s32 pos;
    s32 i;

    src = func_08117044();
    pos = func_0811704C();
    REG_DMA1CNT ^= DMA_ENABLE << 16;
    REG_DMA1SAD = (s32)(gUnk_020380A0 == 1 ? gUnk_02038368 : gUnk_020380A8);
    REG_DMA1CNT ^= DMA_ENABLE << 16;
    gUnk_020380A0 = gUnk_020380A0 == 1 ? 2 : 1;
    dst = gUnk_020380A0 == 1 ? gUnk_02038368 : gUnk_020380A8;

    if (pos + gUnk_020380A4 <= 0x7FF) {
        for (i = 0; i < gUnk_020380A4; i++) {
            dst[i] = src[pos] >> 8;
            pos++;
        }
        func_08117058(pos);
    } else {
        for (i = 0; i < 0x800 - pos; i++) {
            dst[i] = src[pos + i] >> 8;
        }

        for (; i < gUnk_020380A4; i++) {
            dst[i] = src[pos + i - 0x800] >> 8;
        }
        func_08117058(pos + gUnk_020380A4 - 0x800);
    }
}

INCLUDE_ASM("sroll/_08117284.s");
INCLUDE_ASM("sroll/_08117674.s");
INCLUDE_ASM("sroll/_08117A4C.s");
