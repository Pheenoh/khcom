#include "pallet.h"
#include "malloc.h"
#include "types.h"

void CpuSet(void* src, void* dst, u32 ctrl);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void SetHBlankCallback(s32 a);
void ResetHBlankCallback(void);
void EnableHBlankIntr(void);
void DisableHBlankIntr(void);

u16* func_080078FC(u16* src, u16* dst, u16 size, u16 amount) {
    s32 base = ((s32)dst - 0x05000000) >> 1;
    u16 count = size >> 1;
    u16 i;
    u16 b[2];
    u16 g[2];
    u16 r[2];

    for (i = 0; i < count; i++) {
        r[0] = src[i] & 0x1F;
        g[0] = (src[i] & 0x3E0) >> 5;
        b[0] = (src[i] & 0x7C00) >> 10;
        r[1] = 0;
        g[1] = 0;
        b[1] = 0;
        if (b[0] > b[1]) {
            b[0] = b[0] - (amount * b[0] >> 5);
        } else {
            b[0] = b[1];
        }
        if (g[0] > g[1]) {
            g[0] = g[0] - (amount * g[0] >> 5);
        } else {
            g[0] = g[1];
        }
        if (r[0] > r[1]) {
            r[0] = r[0] - (amount * r[0] >> 5);
        } else {
            r[0] = r[1];
        }
        gUnk_0300756C->colors[i + base] = (b[0] << 10) | (g[0] << 5) | r[0];
    }
    if (base == 0) {
        RequestDma3Copy(&gUnk_0300756C->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gUnk_0300756C->colors[base], dst, size);
    }
    return &gUnk_0300756C->colors[base];
}

u16* func_08007A10(u16* src, u16* dst, u16 size, u16 amount) {
    s32 base = ((s32)dst - 0x05000000) >> 1;
    u16 count = size >> 1;
    s16 inv = 31 - amount;
    u16 i;

    for (i = 0; i < count; i++) {
        s16 r = src[i] & 0x1F;
        s16 g = ((src[i] & 0x3E0) >> 5) & 0x1F;
        s16 b = ((src[i] & 0x7C00) >> 10) & 0x1F;
        s16 gray = ((r + g + b) >> 2) * amount;

        r = (gray + r * inv) >> 5;
        g = (gray + g * inv) >> 5;
        b = (gray + b * inv) >> 5;
        gUnk_0300756C->colors[i + base] = (b << 10) | (g << 5) | r;
    }
    if (base == 0) {
        RequestDma3Copy(&gUnk_0300756C->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gUnk_0300756C->colors[base], dst, size);
    }
    return &gUnk_0300756C->colors[base];
}

u16* func_08007B08(u16* src, u16* dst, u16 size, u16 amount) {
    s32 base = ((s32)dst - 0x05000000) >> 1;
    u16 count = size >> 1;
    u16 i;
    u16 b[2];
    u16 g[2];
    u16 r[2];

    for (i = 0; i < count; i++) {
        r[0] = src[i] & 0x1F;
        g[0] = (src[i] & 0x3E0) >> 5;
        b[0] = (src[i] & 0x7C00) >> 10;
        r[1] = 31;
        g[1] = 31;
        b[1] = 31;
        if (b[0] < b[1]) {
            b[0] = b[0] + ((b[1] - b[0]) * amount >> 5);
        } else {
            b[0] = b[0] - ((b[0] - b[1]) * amount >> 5);
        }
        if (g[0] < g[1]) {
            g[0] = g[0] + ((g[1] - g[0]) * amount >> 5);
        } else {
            g[0] = g[0] - ((g[0] - g[1]) * amount >> 5);
        }
        if (r[0] < r[1]) {
            r[0] = r[0] + ((r[1] - r[0]) * amount >> 5);
        } else {
            r[0] = r[0] - ((r[0] - r[1]) * amount >> 5);
        }
        gUnk_0300756C->colors[i + base] = (b[0] << 10) | (g[0] << 5) | r[0];
    }
    if (base == 0) {
        RequestDma3Copy(&gUnk_0300756C->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gUnk_0300756C->colors[base], dst, size);
    }
    return &gUnk_0300756C->colors[base];
}

u16* func_08007C50(u16* src, u16* dst, u16 size, u16 amount) {
    s32 base = ((s32)dst - 0x05000000) >> 1;
    u16 count = size >> 1;
    u16 i;

    for (i = 0; i < count; i++) {
        u16 r = src[i] & 0x1F;
        u16 g = ((src[i] & 0x3E0) >> 5) & 0x1F;
        u16 b = ((src[i] & 0x7C00) >> 10) & 0x1F;
        s32 rv = r << 8;
        s32 gv = g << 8;
        s32 bv = b << 8;

        rv += amount * gUnk_08121694[r];
        gv += amount * gUnk_08121694[g];
        bv += amount * gUnk_08121694[b];
        if (rv > 0x1F00) {
            rv = 0x1F00;
        }
        if (gv > 0x1F00) {
            gv = 0x1F00;
        }
        if (bv > 0x1F00) {
            bv = 0x1F00;
        }
        r = rv >> 8;
        g = gv >> 8;
        b = bv >> 8;
        gUnk_0300756C->colors[i + base] = (b << 10) | (g << 5) | r;
    }
    if (base == 0) {
        RequestDma3Copy(&gUnk_0300756C->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gUnk_0300756C->colors[base], dst, size);
    }
    return &gUnk_0300756C->colors[base];
}

u16* func_08007D74(void* src, u16* dst, u16 size) {
    s32 base = ((s32)dst - 0x05000000) >> 1;

    CpuSet(src, &gUnk_0300756C->colors[base], size >> 1);
    if (base == 0) {
        RequestDma3Copy(&gUnk_0300756C->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gUnk_0300756C->colors[base], dst, size);
    }
    return &gUnk_0300756C->colors[base];
}

u16* func_08007DD8(u8 bank) {
    return &gUnk_0300756C->colors[bank * 32];
}

void func_08007DEC(void) {
    gUnk_03007570 = 0;
    gUnk_03007572 = 0;
}

u16* func_08007E00(void* src, u16* dst, u16 size) {
    if (gUnk_03007570 == 0) {
        return func_08007D74(src, dst, size);
    }
    if (gUnk_03007570 < 0) {
        return func_08007A10(src, dst, size, -gUnk_03007570);
    }
    return func_08007C50(src, dst, size, gUnk_03007570);
}

s16 func_08007E50(void) {
    return gUnk_03007570;
}

void func_08007E5C(s16 a) {
    gUnk_03007570 = a;
}

void func_08007E68(s32 a) {
    gUnk_03007572 = gUnk_03007570;
    gUnk_03007570 = a;
}

void func_08007E7C(void) {
    gUnk_03007570 = gUnk_03007572;
}

void func_08007E90(void) {
    s32 zero;

    SetIwramHeapName(gUnk_08121714);
    gUnk_0300756C = IwramAlloc(0x440);
    zero = 0;
    CpuSet(&zero, gUnk_0300756C, 0x05000110);
    func_08007EE0();
}

void func_08007ECC(void) {
    IwramFree(gUnk_0300756C);
}

void func_08007EE0(void) {
    s32 i;

    for (i = 0; i < 512; i++) {
        gUnk_0300756C->colors[i] = 0;
    }
    for (i = 0; i < 32; i++) {
        gUnk_0300756C->banks[i] = 0;
    }
}

void func_08007F20(u16 bank, u8 a) {
    gUnk_0300756C->banks[bank] = a;
}

u16* func_08007F3C(u16* src, u16 amount) {
    u16 bank;
    u16 j;
    u16* pal = (u16*)0x05000000;
    u16 b[2];
    u16 g[2];
    u16 r[2];

    for (bank = 0; bank <= 31; bank++) {
        if (gUnk_0300756C->banks[bank] == 1) {
            for (j = 0; j <= 15; j++) {
                u16 idx = bank * 16 + j;

                r[0] = src[idx] & 0x1F;
                g[0] = (src[idx] & 0x3E0) >> 5;
                b[0] = (src[idx] & 0x7C00) >> 10;
                r[1] = 0;
                g[1] = 0;
                b[1] = 0;
                if (b[0] > b[1]) {
                    b[0] = b[0] - (amount * b[0] >> 5);
                } else {
                    b[0] = b[1];
                }
                if (g[0] > g[1]) {
                    g[0] = g[0] - (amount * g[0] >> 5);
                } else {
                    g[0] = g[1];
                }
                if (r[0] > r[1]) {
                    r[0] = r[0] - (amount * r[0] >> 5);
                } else {
                    r[0] = r[1];
                }
                gUnk_0300756C->colors[idx] = (b[0] << 10) | (g[0] << 5) | r[0];
            }
        }
    }
    RequestDma3Copy(&gUnk_0300756C->colors[1], pal + 1, 0x3FE);
    return gUnk_0300756C->colors;
}

u16* func_0800805C(u16* src, u16 amount) {
    u16* pal = (u16*)0x05000000;
    u16 bank;
    u16 j;
    u16 b[2];
    u16 g[2];
    u16 r[2];

    for (bank = 0; bank <= 31; bank++) {
        if (gUnk_0300756C->banks[bank] == 1) {
            for (j = 0; j <= 15; j++) {
                u16 idx = bank * 16 + j;

                r[0] = src[idx] & 0x1F;
                g[0] = (src[idx] & 0x3E0) >> 5;
                b[0] = (src[idx] & 0x7C00) >> 10;
                r[1] = 31;
                g[1] = 31;
                b[1] = 31;
                if (b[0] < b[1]) {
                    b[0] = b[0] + ((b[1] - b[0]) * amount >> 5);
                } else {
                    b[0] = b[0] - ((b[0] - b[1]) * amount >> 5);
                }
                if (g[0] < g[1]) {
                    g[0] = g[0] + ((g[1] - g[0]) * amount >> 5);
                } else {
                    g[0] = g[0] - ((g[0] - g[1]) * amount >> 5);
                }
                if (r[0] < r[1]) {
                    r[0] = r[0] + ((r[1] - r[0]) * amount >> 5);
                } else {
                    r[0] = r[0] - ((r[0] - r[1]) * amount >> 5);
                }
                gUnk_0300756C->colors[idx] = (b[0] << 10) | (g[0] << 5) | r[0];
            }
        }
    }
    RequestDma3Copy(&gUnk_0300756C->colors[1], pal + 1, 0x3FE);
    return gUnk_0300756C->colors;
}

void func_080081B8(s32 a) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gUnk_02039B70[i].unk_00 = 1;
        gUnk_02039B70[i].unk_01 = 1;
        gUnk_02039B70[i].unk_02 = 0;
    }
    SetHBlankCallback(a);
    EnableHBlankIntr();
}

void func_080081E4(s32 a, u8 b, u8 c) {
    gUnk_02039B70[a].unk_00 = b;
    gUnk_02039B70[a].unk_01 = c;
}

void func_080081F4(s32 a) {
    gUnk_02039B70[a].unk_02 = 1;
}

void func_08008204(s32 a) {
    gUnk_02039B70[a].unk_02 = 0;
}

void func_08008214(s32 a) {
    vu16 line;

    line = REG_VCOUNT;
    line = (line + 1) % 228;
    if (gUnk_02039B70[a].unk_02 == 1) {
        REG_BGHOFS(0) = gSineTable[((line + gFrameCounter) * gUnk_02039B70[a].unk_01) & 0xFF] * gUnk_02039B70[a].unk_00 >> 8;
    }
}

void func_08008280(s32 a) {
    gUnk_02039B70[a].unk_02 = 0;
    ResetHBlankCallback();
    DisableHBlankIntr();
}

void func_0800829C(void) {
    vu16 line;
    s32 i;

    line = REG_VCOUNT;
    line = (line + 1) % 228;
    for (i = 0; i < 4; i++) {
        s16* sine = gSineTable;

        if (gUnk_02039B70[i].unk_02 == 1) {
            REG_BGHOFS(i) = sine[((line + gFrameCounter) * gUnk_02039B70[i].unk_01) & 0xFF] * gUnk_02039B70[i].unk_00 / 256;
        }
    }
}

void func_08008318(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gUnk_02039B70[i].unk_02 = 0;
    }
    ResetHBlankCallback();
    DisableHBlankIntr();
}
