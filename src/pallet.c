#include "pallet.h"
#include "intr.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "types.h"

extern u32 gFrameCounter;
PaletteBuffer* gPaletteBuffer;
s16 gPaletteEffect;
s16 gPaletteEffectSaved;

u8 RequestDma3Copy(void* src, void* dst, u16 size);

u16* FadePaletteToBlack(u16* src, u16* dst, u16 size, u16 amount) {
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
        gPaletteBuffer->colors[i + base] = (b[0] << 10) | (g[0] << 5) | r[0];
    }

    if (base == 0) {
        RequestDma3Copy(&gPaletteBuffer->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gPaletteBuffer->colors[base], dst, size);
    }
    return &gPaletteBuffer->colors[base];
}

u16* FadePaletteToGray(u16* src, u16* dst, u16 size, u16 amount) {
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
        gPaletteBuffer->colors[i + base] = (b << 10) | (g << 5) | r;
    }

    if (base == 0) {
        RequestDma3Copy(&gPaletteBuffer->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gPaletteBuffer->colors[base], dst, size);
    }
    return &gPaletteBuffer->colors[base];
}

u16* FadePaletteToWhite(u16* src, u16* dst, u16 size, u16 amount) {
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
        gPaletteBuffer->colors[i + base] = (b[0] << 10) | (g[0] << 5) | r[0];
    }

    if (base == 0) {
        RequestDma3Copy(&gPaletteBuffer->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gPaletteBuffer->colors[base], dst, size);
    }
    return &gPaletteBuffer->colors[base];
}

u16* BrightenPalette(u16* src, u16* dst, u16 size, u16 amount) {
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
        gPaletteBuffer->colors[i + base] = (b << 10) | (g << 5) | r;
    }

    if (base == 0) {
        RequestDma3Copy(&gPaletteBuffer->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gPaletteBuffer->colors[base], dst, size);
    }
    return &gPaletteBuffer->colors[base];
}

u16* LoadPaletteBuffered(void* src, u16* dst, u16 size) {
    s32 base = ((s32)dst - 0x05000000) >> 1;

    CpuSet(src, &gPaletteBuffer->colors[base], size >> 1);

    if (base == 0) {
        RequestDma3Copy(&gPaletteBuffer->colors[1], dst + 1, size - 2);
    } else {
        RequestDma3Copy(&gPaletteBuffer->colors[base], dst, size);
    }
    return &gPaletteBuffer->colors[base];
}

u16* GetPaletteBufferBank(u8 bank) {
    return &gPaletteBuffer->colors[bank * 32];
}

void ResetPaletteEffect(void) {
    gPaletteEffect = 0;
    gPaletteEffectSaved = 0;
}

u16* LoadPaletteWithEffect(void* src, u16* dst, u16 size) {
    if (gPaletteEffect == 0) {
        return LoadPaletteBuffered(src, dst, size);
    }

    if (gPaletteEffect < 0) {
        return FadePaletteToGray(src, dst, size, -gPaletteEffect);
    }
    return BrightenPalette(src, dst, size, gPaletteEffect);
}

s16 GetPaletteEffect(void) {
    return gPaletteEffect;
}

void SetPaletteEffect(s16 a) {
    gPaletteEffect = a;
}

void PushPaletteEffect(s32 a) {
    gPaletteEffectSaved = gPaletteEffect;
    gPaletteEffect = a;
}

void PopPaletteEffect(void) {
    gPaletteEffect = gPaletteEffectSaved;
}

void PalletInit(void) {
    s32 zero;

    SetIwramHeapName(sPalletHeapName);
    gPaletteBuffer = IwramAlloc(0x440);
    zero = 0;
    CpuSet(&zero, gPaletteBuffer, 0x05000110);
    PalletClear();
}

void PalletFree(void) {
    IwramFree(gPaletteBuffer);
}

void PalletClear(void) {
    s32 i;

    for (i = 0; i < 512; i++) {
        gPaletteBuffer->colors[i] = 0;
    }

    for (i = 0; i < 32; i++) {
        gPaletteBuffer->banks[i] = 0;
    }
}

void func_08007F20(u16 bank, u8 a) {
    gPaletteBuffer->banks[bank] = a;
}

u16* FadeAllPalettesToBlack(u16* src, u16 amount) {
    u16 bank;
    u16 j;
    u16* pal = (u16*)0x05000000;
    u16 b[2];
    u16 g[2];
    u16 r[2];

    for (bank = 0; bank <= 31; bank++) {
        if (gPaletteBuffer->banks[bank] == 1) {
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
                gPaletteBuffer->colors[idx] = (b[0] << 10) | (g[0] << 5) | r[0];
            }
        }
    }
    RequestDma3Copy(&gPaletteBuffer->colors[1], pal + 1, 0x3FE);
    return gPaletteBuffer->colors;
}

u16* FadeAllPalettesToWhite(u16* src, u16 amount) {
    u16* pal = (u16*)0x05000000;
    u16 bank;
    u16 j;
    u16 b[2];
    u16 g[2];
    u16 r[2];

    for (bank = 0; bank <= 31; bank++) {
        if (gPaletteBuffer->banks[bank] == 1) {
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
                gPaletteBuffer->colors[idx] = (b[0] << 10) | (g[0] << 5) | r[0];
            }
        }
    }
    RequestDma3Copy(&gPaletteBuffer->colors[1], pal + 1, 0x3FE);
    return gPaletteBuffer->colors;
}

void StartBgWave(s32 a) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gBgWaves[i].amplitude = 1;
        gBgWaves[i].frequency = 1;
        gBgWaves[i].enabled = 0;
    }
    SetHBlankCallback(a);
    EnableHBlankIntr();
}

void SetBgWaveParams(s32 a, u8 b, u8 c) {
    gBgWaves[a].amplitude = b;
    gBgWaves[a].frequency = c;
}

void EnableBgWave(s32 a) {
    gBgWaves[a].enabled = 1;
}

void DisableBgWave(s32 a) {
    gBgWaves[a].enabled = 0;
}

void HBlankIntrBgWave1(s32 a) {
    vu16 line;

    line = REG_VCOUNT;
    line = (line + 1) % 228;

    if (gBgWaves[a].enabled == 1) {
        REG_BGHOFS(0) = gSineTable[((line + gFrameCounter) * gBgWaves[a].frequency) & 0xFF] * gBgWaves[a].amplitude >> 8;
    }
}

void StopBgWave(s32 a) {
    gBgWaves[a].enabled = 0;
    ResetHBlankCallback();
    DisableHBlankIntr();
}

void HBlankIntrBgWave(void) {
    vu16 line;
    s32 i;

    line = REG_VCOUNT;
    line = (line + 1) % 228;

    for (i = 0; i < 4; i++) {
        s16* sine = gSineTable;

        if (gBgWaves[i].enabled == 1) {
            REG_BGHOFS(i) = sine[((line + gFrameCounter) * gBgWaves[i].frequency) & 0xFF] * gBgWaves[i].amplitude / 256;
        }
    }
}

void StopAllBgWaves(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gBgWaves[i].enabled = 0;
    }
    ResetHBlankCallback();
    DisableHBlankIntr();
}
