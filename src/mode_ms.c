#include "macros.h"
#include "mode_ms.h"

INCLUDE_ASM("mode_ms/mode_ms_top_0.s");
INCLUDE_ASM("mode_ms/mode_ms_top_1.s");
INCLUDE_ASM("mode_ms/mode_ms_top_2.s");
void func_081025AC(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        gUnk_02035B68[i] = 0;
    }
    for (i = 0; i < 2; i++) {
        gUnk_02035BA8[i] = 0;
    }
}

void func_081025D4(void* a) {
    u16* p = a;
    s32 i;

    for (i = 0; i < 32; i++) {
        p[i] = gUnk_02035B68[i];
    }
    for (i = 0; i < 2; i++) {
        p[i + 32] = gUnk_02035BA8[i];
    }
}

void func_08102610(void* a) {
    u16* p = a;
    s32 i;

    for (i = 0; i < 32; i++) {
        gUnk_02035B68[i] = p[i];
    }
    for (i = 0; i < 2; i++) {
        gUnk_02035BA8[i] = p[i + 32];
    }
}

void func_0810264C(u16 a, u16 b, u16 c) {
    u16 v;

    v = a * 16 + b * 4 + c;
    if (v <= 0x1FF) {
        gUnk_02035B68[v >> 4] |= 1 << (v & 15);
    }
}

void func_08102688(u16 a, u16 b, u16 c) {
    u16 v;

    v = a * 16 + b * 4 + c;
    if (v <= 0x1FF) {
        gUnk_02035B68[v >> 4] &= ~(1 << (v & 15));
    }
}

s32 func_081026C4(u16 a, u16 b, u16 c) {
    u16 v;

    v = a * 16 + b * 4 + c;
    if (v <= 0x1FF) {
        return gUnk_02035B68[v >> 4] >> (v & 15) & 1;
    }
    return 0;
}

void func_08102704(u16 a) {
    if (a <= 31) {
        gUnk_02035BA8[a >> 4] |= 1 << (a & 15);
    }
}

void func_08102728(u16 a) {
    if (a <= 31) {
        gUnk_02035BA8[a >> 4] &= ~(1 << (a & 15));
    }
}

s32 func_0810274C(u16 a) {
    if (a <= 31) {
        return gUnk_02035BA8[a >> 4] >> (a & 15) & 1;
    }
    return 0;
}

void func_08102774(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            func_08102688(gUnk_0203C590[6], i, j);
        }
    }
    func_08102728(gUnk_0203C590[6]);
}
INCLUDE_ASM("mode_ms/func_081027B4.s");
void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
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
INCLUDE_ASM("mode_ms/func_08102984.s");
INCLUDE_ASM("mode_ms/func_08102A94.s");
INCLUDE_ASM("mode_ms/func_08102AB4.s");
INCLUDE_ASM("mode_ms/func_08102DC8.s");
INCLUDE_ASM("mode_ms/func_08102F30.s");
INCLUDE_ASM("mode_ms/func_08103CD8.s");
INCLUDE_ASM("mode_ms/func_08103D54.s");
INCLUDE_ASM("mode_ms/func_08103F3C.s");
INCLUDE_ASM("mode_ms/func_08103F94.s");
