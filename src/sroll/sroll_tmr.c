#include "audio_block_codec.h"
#include "pcm_audio.h"
#include "m4a.h"
#include "sroll.h"
#include "sprites_staff_roll.h"

DmaStream gDmaStream __attribute__((aligned(8)));
u8 gUnk_02036048;
u32 gUnk_0203604C;
s32 gUnk_02036050[0x810];
u32* gUnk_02038090;
s32 gUnk_02038094;
s32 gUnk_02038098;

static s32 Square(s32 x) {
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

    if (GetKeysPressed() & SELECT_BUTTON) {
        if (w->unk_00 == 1) {
            w->unk_00 = 0;
        } else {
            w->unk_00 = r;
        }
    }
    FadeSetPaletteExcluded((w->palette->index & 15) + 16, 1);
    w->unk_04++;
    return r;
}

void task_sroll_tmr_2(SrollTmrWork* w) {
    s32 t;
    u16 h;
    u16 m;
    u16 s;
    u16 z;

    if (w->unk_00 == 0) {
        return;
    }

    t = w->unk_04;
    h = t / 3600;
    m = t / 60 % 60;
    s = t % 60;
    z = 0;
    DrawSprite(8, 8, gUnk_09EFBAE8[h / 10 % 10], w->tiles, w->palette, z, z, z);
    DrawSprite(16, 8, gUnk_09EFBAE8[h % 10], w->tiles, w->palette, z, z, z);
    DrawSprite(24, 8, gUnk_09EFBAE8[10], w->tiles, w->palette, z, z, z);
    DrawSprite(32, 8, gUnk_09EFBAE8[m / 10], w->tiles, w->palette, z, z, z);
    DrawSprite(40, 8, gUnk_09EFBAE8[m % 10], w->tiles, w->palette, z, z, z);
    DrawSprite(48, 8, gUnk_09EFBAE8[10], w->tiles, w->palette, z, z, z);
    DrawSprite(56, 8, gUnk_09EFBAE8[s / 10], w->tiles, w->palette, z, z, z);
    DrawSprite(64, 8, gUnk_09EFBAE8[s % 10], w->tiles, w->palette, z, z, z);
}
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

void func_081157E0(u32* dst, u8* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        v = pal[(src[i] >> 7) & 1];
        v |= pal[(src[i] >> 6) & 1] << 4;
        v |= pal[(src[i] >> 5) & 1] << 8;
        v |= pal[(src[i] >> 4) & 1] << 12;
        v |= pal[(src[i] >> 3) & 1] << 16;
        v |= pal[(src[i] >> 2) & 1] << 20;
        v |= pal[(src[i] >> 1) & 1] << 24;
        v |= pal[src[i] & 1] << 28;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
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

void func_08115AD4(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        v = pal[(src[i] >> 6) & 3];
        v |= pal[(src[i] >> 4) & 3] << 4;
        v |= pal[(src[i] >> 2) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
void func_08115B6C(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        v = pal[(src[i] >> 6) & 3];
        v |= pal[(src[i] >> 4) & 3] << 4;
        v |= pal[(src[i] >> 2) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(src[i] >> 14) & 3] << 16;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
void func_08115C04(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        v = pal[(src[i] >> 6) & 3];
        v |= pal[(src[i] >> 4) & 3] << 4;
        v |= pal[(src[i] >> 2) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(src[i] >> 14) & 3] << 16;
        v |= pal[(src[i] >> 12) & 3] << 20;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
void func_08115CAC(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        v = pal[(src[i] >> 6) & 3];
        v |= pal[(src[i] >> 4) & 3] << 4;
        v |= pal[(src[i] >> 2) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(src[i] >> 14) & 3] << 16;
        v |= pal[(src[i] >> 12) & 3] << 20;
        v |= pal[(src[i] >> 10) & 3] << 24;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
void func_08115D60(u32* dst, u16* src, u32* pal, s32 x) {
    SrollShift* t;
    s32 i;
    u32 v;

    t = &gUnk_09A54C78[x];

    for (i = 0; i <= 7; i++) {
        v = pal[(src[i] >> 6) & 3];
        v |= pal[(src[i] >> 4) & 3] << 4;
        v |= pal[(src[i] >> 2) & 3] << 8;
        v |= pal[src[i] & 3] << 12;
        v |= pal[(src[i] >> 14) & 3] << 16;
        v |= pal[(src[i] >> 12) & 3] << 20;
        v |= pal[(src[i] >> 10) & 3] << 24;
        v |= pal[(src[i] >> 8) & 3] << 28;
        dst[i] |= v << t->unk_00;
        dst[i + 8] |= v >> t->unk_04;
    }
}
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

u16 SrollTextGetGlyphIndex(u16 c, u8* font) {
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

u8 SrollTextGetGlyphWidth(u16 c, u8* font, u8* widths, u32 count) {
    u8 w;

    w = 0;

    if (widths != 0) {
        u16 idx = SrollTextGetGlyphIndex(c, font);
        if (idx < count) {
            w = widths[idx];
        }
    }

    if (w == 0) {
        w = 8;
    }
    return w;
}

s32 SrollTextMeasureWidth(SrollWork* w, u8* s) {
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
            c = SrollTextMapSingleByteChar(s[0]);
            s += 1;
        }
        total += SrollTextGetGlyphWidth(c, w->unk_34, w->unk_3C, w->unk_40);
    }
    return total;
}

u32 SrollTextGetGlyphAddress(u16 c, u8* font, u32 base, u16 a, u16 b) {
    return base + SrollTextGetGlyphIndex(c, font) * (a << 3) * b;
}

u32 SrollTextBlitGlyph(SrollWork* w, u32* dst, u8* src, s32 width) {
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
    b.unk_00 = w->x & 7;
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

void SrollTextSelectFont(SrollWork* w, u32 mode) {
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
    SrollTextSetCursorTile(w, w->x, w->y);
}

void SrollTextInit(SrollWork* w, SrollInit* a) {
    SrollTextSelectFont(w, a->unk_04);
    SrollTextSetColors(w, a->unk_20, a->unk_22, a->unk_24, a->unk_26);
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
    SrollTextClearQueue(w);
    func_08116698(w, 1);
}

void SrollTextClearWindowImmediate(SrollWork* w) {
    SrollTextClearWindow(w, 1);
}

void SrollTextClearQueue(SrollWork* w) {
    w->writeIdx = 0;
    w->readIdx = 0;
}

u8 SrollTextQueueIsEmpty(SrollWork* w) {
    u8 r;

    r = 0;

    if (w->writeIdx == w->readIdx) {
        r = 1;
    }
    return r;
}

void SrollTextEnqueueChar(SrollWork* w, u16 c) {
    w->charQueue[w->writeIdx] = c;
    w->writeIdx = (w->writeIdx + 1) & 0xFF;
}

u16 SrollTextDequeueChar(SrollWork* w) {
    u16 c;

    if (w->writeIdx == w->readIdx) {
        return 0;
    }
    c = w->charQueue[w->readIdx];
    w->readIdx = (w->readIdx + 1) & 0xFF;
    return c;
}

void SrollTextSetCursorTile(SrollWork* w, u16 x, u16 y) {
    if (x >= w->unk_1C) {
        x = 0;
    }

    if (y + w->unk_24 > w->unk_1E) {
        y = 0;
    }
    w->x = x * 8;
    w->y = y;
}

void SrollTextSetCursorPixelX(SrollWork* w, u16 x) {
    if (x >= w->unk_1C * 8) {
        x = 0;
    }
    w->x = x;
}

void SrollTextSetColors(SrollWork* w, u16 a, u16 b, u16 c, u16 d) {
    w->unk_02 = a;
    w->unk_04 = b;
    w->unk_06 = c;
    w->unk_08 = d;
}

void SrollTextClearWindow(SrollWork* w, u8 flush) {
    u16 fill[1];
    u16* p;
    u16 i;

    p = (u16*)((u8*)SrollTextGetTilemap(w) + w->unk_12 * w->unk_0A * 2 + w->unk_10 * 2);

    for (i = 0; i < w->unk_16; i++) {
        fill[0] = w->unk_2C;
        CpuSet(fill, p, w->unk_14 | CPU_SET_SRC_FIXED);
        p += w->unk_0A;
    }

    if (flush == 1) {
        SrollTextFlushTilemap(w);
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

    p = (u16*)((u8*)SrollTextGetTilemap(w) + w->unk_12 * w->unk_0A * 2 + w->unk_10 * 2);
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
void func_081163CC(SrollWork* w) {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16* p;
    u16* q;
    u16 i;
    u16 t;

    p = (u16*)((u8*)SrollTextGetTilemap(w) + w->unk_12 * w->unk_0A * 2 + w->unk_10 * 2);
    t = w->unk_2E + 1;
    q = &a;
    a = t + 2;
    CpuSet(q, p + 2, (((u32)(w->unk_14 - 3) << 11) >> 11) | CPU_SET_SRC_FIXED);
    p[1] = t + 1;
    p[w->unk_14 - 1] = t + 3;
    p += w->unk_0A;

    for (i = 1; i < w->unk_16 - 2; i++) {
        b = t;
        CpuSet(&b, p + 2, (((u32)(w->unk_14 - 3) << 11) >> 11) | CPU_SET_SRC_FIXED);
        p[1] = t + 4;
        p[w->unk_14 - 1] = t + 5;
        p += w->unk_0A;
    }

    c = t;
    CpuSet(&c, p + 2, ((((u32)(w->unk_14 - 3) << 1) >> 1) & 0x1FFFFF) | CPU_SET_SRC_FIXED);
    p[0] = t + 10;
    p[1] = t + 11;
    p[w->unk_14 - 1] = t + 5;
    p += w->unk_0A;

    d = t + 7;
    CpuSet(&d, p + 2, ((((u32)(w->unk_14 - 3) << 1) >> 1) & 0x1FFFFF) | CPU_SET_SRC_FIXED);
    p[1] = t + 6;
    p[w->unk_14 - 1] = t + 8;
}

void func_08116500(SrollWork* w) {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16* p;
    u16* q;
    u16 i;
    u16 t;

    p = (u16*)((u8*)SrollTextGetTilemap(w) + w->unk_12 * w->unk_0A * 2 + w->unk_10 * 2);
    t = w->unk_2E + 1;
    q = &a;
    a = t + 2;
    CpuSet(q, p + 1, (((u32)(w->unk_14 - 3) << 11) >> 11) | CPU_SET_SRC_FIXED);
    p[0] = t + 1;
    p[w->unk_14 - 2] = t + 3;
    p += w->unk_0A;

    for (i = 1; i < w->unk_16 - 2; i++) {
        b = t;
        CpuSet(&b, p + 1, (((u32)(w->unk_14 - 3) << 11) >> 11) | CPU_SET_SRC_FIXED);
        p[0] = t + 4;
        p[w->unk_14 - 2] = t + 5;
        p += w->unk_0A;
    }

    c = t;
    CpuSet(&c, p + 1, ((((u32)(w->unk_14 - 3) << 1) >> 1) & 0x1FFFFF) | CPU_SET_SRC_FIXED);
    p[0] = t + 4;
    p[w->unk_14 - 2] = (t | 0x400) + 11;
    p[w->unk_14 - 1] = (t | 0x400) + 10;
    p += w->unk_0A;

    d = t + 7;
    CpuSet(&d, p + 1, ((((u32)(w->unk_14 - 3) << 1) >> 1) & 0x1FFFFF) | CPU_SET_SRC_FIXED);
    p[0] = t + 6;
    p[w->unk_14 - 2] = t + 8;
}
void SrollTextClearTextArea(SrollWork* w) {
    u16 fill;
    u16* p;
    u16 i;
    u16 t;

    p = (u16*)((u8*)SrollTextGetTilemap(w) + w->unk_1A * w->unk_0A * 2 + w->unk_18 * 2);
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
        SrollTextClearTextArea(w);
        break;
    }
    SrollTextSetCursorTile(w, 0, 0);

    if (flush == 1) {
        SrollTextFlushTilemap(w);
    } else {
        t = w->unk_00 | 1;
        w->unk_00 = t;
    }
}
void SrollTextClearRect(SrollWork* w, u16 x, u16 y, u16 cw, u16 ch, u8 flush) {
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

    p = (u16*)((u8*)SrollTextGetTilemap(w) + (w->unk_1A + y) * w->unk_0A * 2 + (w->unk_18 + x) * 2);
    v = w->unk_2E + 1;
    i = 0;

    while (i < ch) {
        fill = v;
        CpuSet(&fill, p, (((u32)(cw * 2) >> 1) & 0x1FFFFF) | CPU_SET_SRC_FIXED);
        p += w->unk_0A;
        i++;
    }

    if (flush == 1) {
        SrollTextFlushTilemap(w);
    } else {
        t = w->unk_00 | 1;
        w->unk_00 = t;
    }
}

void func_081167CC(void) {
}

u16 ParseLowercaseHexDigit(u16 c) {
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
u8* SrollTextEnqueueString(SrollWork* w, u8* s) {
    s32 hi;

    while (*s != 0) {
        if (*s & 0x80) {
            hi = s[0] << 8;
            SrollTextEnqueueChar(w, s[1] | hi);
            s += 2;
        } else {
            SrollTextEnqueueChar(w, SrollTextMapSingleByteChar(s[0]));
            s += 1;
        }
    }
    return s + 1;
}
u8 SrollTextProcessNextChar(SrollWork* w) {
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

    if (w->x >= w->unk_1C * 8) {
        w->x = 0;
    }
    c = SrollTextDequeueChar(w);
    if (c & 0xFF00) {
        off = (w->y * w->unk_1C + (w->x >> 3)) * 32;
        g = SrollTextGetGlyphAddress(c, w->unk_34, w->unk_38, w->unk_26, w->unk_24);
        wd = SrollTextGetGlyphWidth(c, w->unk_34, w->unk_3C, w->unk_40);
        n = SrollTextBlitGlyph(w, (u32*)(w->unk_50 + off), (u8*)g, wd);
        t = w->y * w->unk_1C + (w->x >> 3) + w->unk_30;
        p = (u16*)((u8*)SrollTextGetTilemap(w) +
                   ((w->unk_1A + w->y) * w->unk_0A + ((w->x >> 3) + w->unk_18)) * 2);

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
        w->x += wd;
        w->unk_00 |= 1;
        r = 1;
    } else {
        switch (c) {
        case '@':
            v[0] = SrollTextDequeueChar(w);
            v[1] = SrollTextDequeueChar(w);

            switch (v[0]) {
            case 'F':
                SrollTextSelectFont(w, ParseLowercaseHexDigit(v[1]));
                break;
            case 'f':
                w->unk_02 = ParseLowercaseHexDigit(v[1]);
                break;
            case 's':
                w->unk_04 = ParseLowercaseHexDigit(v[1]);
                break;
            case 'b':
                w->unk_06 = ParseLowercaseHexDigit(v[1]);
                break;
            case 'e':
                w->unk_08 = ParseLowercaseHexDigit(v[1]);
                break;
            }
            break;
        case 0:
            break;
        case '\n':
            w->x = 0;
            w->y += w->unk_24;

            if (w->y + w->unk_24 > w->unk_1E) {
                w->y = 0;
            }
            break;
        }
    }
    return r;
}
void SrollTextDrawNextGlyph(SrollWork* w, u8 flush) {
    u8 r;

    r = 0;
    while (!SrollTextQueueIsEmpty(w) && r == 0) {
        r = SrollTextProcessNextChar(w);
    }

    if (flush == 1 && (w->unk_00 & 1)) {
        SrollTextFlushTilemap(w);
    }
}

void SrollTextDrawQueued(SrollWork* w, u8 flush) {
    while (!SrollTextQueueIsEmpty(w)) {
        SrollTextProcessNextChar(w);
    }

    if (flush == 1 && (w->unk_00 & 1)) {
        SrollTextFlushTilemap(w);
    }
}

u32 SrollTextGetTilemap(SrollWork* w) {
    u32 v;

    v = w->unk_4C;
    if (v == 0) {
        v = w->unk_54;
    }
    return v;
}

void SrollTextFlushTilemap(SrollWork* w) {
    u32 off;

    if (w->unk_4C != 0) {
        off = w->unk_12 * w->unk_0A * 2;
        RequestDma3Copy((u8*)w->unk_4C + off, (u8*)w->unk_54 + off, w->unk_16 * w->unk_0A * 2);
    }
    w->unk_00 &= 0xFFFE;
}

void SrollTextDrawString(SrollWork* w, u8* s, u8 flush) {
    SrollTextDrawQueued(w, 0);
    SrollTextEnqueueString(w, s);
    SrollTextDrawQueued(w, 0);

    if (flush == 1 && (w->unk_00 & 1)) {
        SrollTextFlushTilemap(w);
    }
}

void SrollTextDrawStringAtTile(SrollWork* w, u16 x, u16 y, u8* s, u8 flush) {
    SrollTextDrawQueued(w, 0);
    SrollTextSetCursorTile(w, x, y);
    SrollTextEnqueueString(w, s);
    SrollTextDrawQueued(w, 0);

    if (flush == 1 && (w->unk_00 & 1)) {
        SrollTextFlushTilemap(w);
    }
}

void SrollTextDrawStringAtPixelX(SrollWork* w, u16 x, u16 y, u8* s, u8 flush) {
    u32 off;
    u32 g;
    s32 n;

    SrollTextDrawQueued(w, 0);
    SrollTextSetCursorTile(w, x >> 3, y);
    n = x & 7;
    if (n != 0) {
        off = (w->y * w->unk_1C + (x >> 3)) * 32;
        g = SrollTextGetGlyphAddress(0x8140, w->unk_34, w->unk_38, w->unk_26, w->unk_24);
        SrollTextBlitGlyph(w, (u32*)(w->unk_50 + off), (u8*)g, n);
    }
    SrollTextSetCursorPixelX(w, x);
    SrollTextEnqueueString(w, s);
    SrollTextDrawQueued(w, 0);

    if ((w->x & 7) != 0) {
        off = (w->y * w->unk_1C + (w->x >> 3)) * 32;
        g = SrollTextGetGlyphAddress(0x8140, w->unk_34, w->unk_38, w->unk_26, w->unk_24);
        SrollTextBlitGlyph(w, (u32*)(w->unk_50 + off), (u8*)g, 8 - (w->x & 7));
    }

    if (flush == 1 && (w->unk_00 & 1)) {
        SrollTextFlushTilemap(w);
    }
}

u16 SrollTextMapSingleByteChar(u8 c) {
    return gUnk_09A5B470[c];
}

void ScanlineDmaReset(void) {
    vu16* dma;

    dma = (vu16*)REG_ADDR_DMA0;
    dma[5] &= ~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT);
    dma[5] &= ~DMA_ENABLE;
    dma[5];
    gDmaStream.unk_00 = 0;
    gDmaStream.unk_01 = 0;
    gDmaStream.update = 0;
    gDmaStream.dst = 0;
    gDmaStream.unk_0C = 0;
    gDmaStream.src[0] = 0;
    gDmaStream.src[1] = 0;
    gDmaStream.cnt = 0;
}

void ScanlineDmaUpdate(void) {
    vu16* dma;
    vu32* dma32;
    u8* src;

    dma = (vu16*)REG_ADDR_DMA0;
    dma[5] &= ~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT);
    dma[5] &= ~DMA_ENABLE;
    dma[5];

    if (gDmaStream.unk_00 != 0) {
        if (gDmaStream.unk_01 != 0) {
            gDmaStream.unk_0C ^= 1;
            src = gDmaStream.src[gDmaStream.unk_0C];
            gDmaStream.unk_18 = src;

            if (!(gDmaStream.cnt & CPU_SET_SRC_FIXED)) {
                if (gDmaStream.cnt & CPU_SET_32BIT) {
                    gDmaStream.unk_18 = src + 4;
                } else {
                    gDmaStream.unk_18 = src + 2;
                }
            }
            gDmaStream.unk_01 = 0;
        }

        if (gDmaStream.src[gDmaStream.unk_0C] != 0 && gDmaStream.dst != 0 &&
            gDmaStream.cnt != 0) {
            dma32 = (vu32*)REG_ADDR_DMA0;
            dma32[0] = (u32)gDmaStream.unk_18;
            dma32[1] = (u32)gDmaStream.dst;
            dma32[2] = gDmaStream.cnt;
            dma32[2];
        }

        if (gDmaStream.update != 0) {
            gDmaStream.update();
        }
    }
}

void ScanlineDmaPrime32Bit(void) {
    *gDmaStream.dst = *(u32*)gDmaStream.src[gDmaStream.unk_0C];
}

void ScanlineDmaPrime16Bit(void) {
    *gDmaStream.dst = *(u16*)gDmaStream.src[gDmaStream.unk_0C];
}

void ScanlineDmaInit(vu16* dst, u8* src, u32 cnt) {
    ScanlineDmaReset();
    gDmaStream.src[0] = src;
    gDmaStream.src[1] = src;
    gDmaStream.unk_18 = src;

    if (cnt & CPU_SET_32BIT) {
        gDmaStream.update = ScanlineDmaPrime32Bit;

        if (!(cnt & CPU_SET_SRC_FIXED)) {
            gDmaStream.unk_18 = src + 4;
        }
    } else {
        gDmaStream.update = ScanlineDmaPrime16Bit;

        if (!(cnt & CPU_SET_SRC_FIXED)) {
            gDmaStream.unk_18 = src + 2;
        }
    }
    gDmaStream.dst = dst;
    gDmaStream.cnt = cnt;
}

void ScanlineDmaQueueBuffer(u8* src) {
    gDmaStream.src[gDmaStream.unk_0C ^ 1] = src;
    gDmaStream.unk_01 = 1;
}

void ScanlineDmaEnable(void) {
    gDmaStream.unk_00 = 1;
}

void ScanlineDmaDisable(void) {
    gDmaStream.unk_00 = 0;
}

void BlockAudioStart(void) {
    gUnk_02036048 = 1;
    AudioBlockStreamInit(GetBlockAudioData());
    PcmPlaybackInit(GetBlockAudioSampleRate());
    SetVBlankCallback(VBlankIntrBlockAudio);
    PcmPlaybackStart();
}

void BlockAudioUpdate(void) {
    if (gUnk_02036048 == 1) {
        gUnk_02036048 = AudioBlockStreamUpdate();
        if (gUnk_02036048 == 0) {
            BlockAudioStop();
        }
    }
}

void BlockAudioVBlank(void) {
    if (gUnk_02036048 == 1) {
        PcmPlaybackUpdate();
    }
}

void BlockAudioStop(void) {
    ResetVBlankCallback();
    PcmPlaybackStop();
    m4aSoundInit();
    m4aSoundVSyncOn();
}

u16 GetBlockAudioSampleRate(void) {
    return 21024;
}

u32* GetBlockAudioData(void) {
    return gUnk_09A5B674;
}

u8* ReadNextAudioBlock(u32** p) {
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

s32 AudioBlockStreamInit(u32* src) {
    s32* p;
    u8* q;

    for (p = gUnk_02036050; p < gUnk_02036050 + 0x810;) {
        *p++ = 0;
    }
    gUnk_02038090 = src;

    for (gUnk_02038094 = 0; gUnk_02038094 <= 0x7FF; gUnk_02038094 += 0x200) {
        if (gUnk_02038090 != 0) {
            q = ReadNextAudioBlock(&gUnk_02038090);
            if (q != 0) {
                DecodeAudioBlock(q, gUnk_02036050, gUnk_02038094);
            }
        }
    }
    gUnk_02038094 &= 0x7FF;
    gUnk_02038098 = 0;
    return gUnk_02038090 != 0;
}

s32 AudioBlockStreamUpdate(void) {
    u8* q;

    if (gUnk_02038098 > gUnk_02038094 + 0x200 || gUnk_02038098 < gUnk_02038094) {
        if (gUnk_02038090 != 0) {
            q = ReadNextAudioBlock(&gUnk_02038090);
            if (q != 0) {
                DecodeAudioBlock(q, gUnk_02036050, gUnk_02038094);
            }
            gUnk_02038094 = (gUnk_02038094 + 0x200) & 0x7FF;
        }
    }
    return gUnk_02038090 != 0;
}

s32* GetDecodedAudioBuffer(void) {
    return gUnk_02036050;
}

s32 GetDecodedAudioReadPosition(void) {
    return gUnk_02038098;
}

void SetDecodedAudioReadPosition(s32 pos) {
    gUnk_02038098 = pos;
}

TaskDesc gTaskDescSrollTmr = {
    "task_sroll_tmr",
    (TaskInitFunc)task_sroll_tmr_0,
    (TaskUpdateFunc)task_sroll_tmr_1,
    (TaskFunc)task_sroll_tmr_2,
    (TaskFunc)task_sroll_tmr_3,
    0x10,
};
