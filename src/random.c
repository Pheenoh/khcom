#include "pallet.h"
#include "gba/syscall.h"
#include "sprite.h"

u32 gRandSeed;
u8 gUnk_0203402C[4];
u32 gRandomState[4];
BgAnimationDef* gBgAnimCurrent;
u16 gUnk_02034044;
u16 gUnk_02034046;
s32 gUnk_02034048;
u16 gUnk_0203404C;
u16 gUnk_0203404E;
s16 gUnk_02034050;
s16 gUnk_02034052;
u8 gUnk_02034054;
u16 gUnk_02034056;
u8 gUnk_02034058;
u32 gUnk_0203405C;
u32 gUnk_02034060;
u8 gUnk_02034064;
s16 gUnk_02034066;
s16 gUnk_02034068;
u16 gUnk_0203406A;

void SeedRand(u32 seed) {
    gRandSeed = seed;
}

u32 Rand(void) {
    gRandSeed = (gRandSeed * 0x41C64E6D + 12345) & 0x7FFF;
    return gRandSeed;
}

void SeedRandom(u32 seed) {
    SeedRand(seed);
    gRandomState[0] = Rand();
    gRandomState[1] = Rand();
    gRandomState[2] = Rand();
    gRandomState[3] = Rand();
}

u16 GetRandom(void) {
    u32 x;

    x = gRandomState[1];
    x <<= 1;

    if (gRandomState[0] & 0x80000000) {
        x++;
    }
    x <<= 1;

    if (gRandomState[0] & 0x40000000) {
        x++;
    }
    gRandomState[3] <<= 1;

    if (gRandomState[2] & 0x80000000) {
        gRandomState[3]++;
    }
    x ^= gRandomState[3];
    gRandomState[3] = gRandomState[2];
    gRandomState[2] = gRandomState[1];
    gRandomState[1] = gRandomState[0];
    gRandomState[0] = x;
    x &= 0x7FFF;
    return x;
}

void BgAnimInit(s32 bg, u16 b, u16 c) {
    gUnk_02034048 = bg;
    gBgAnimCurrent = 0;
    gUnk_02034050 = 0;
    gUnk_02034052 = 0;
    gUnk_02034054 = 1;

    if (c == 0) {
        gUnk_02034058 = 0;

        switch (b) {
        case 0x4000:
        case 0x8000:
            gUnk_02034056 = 0x1000;
            break;
        case 0xC000:
            gUnk_02034056 = 0x2000;
            break;
        case 0:
        default:
            gUnk_02034056 = 0x800;
            break;
        }
    } else {
        gUnk_02034058 = 1;

        switch (b) {
        case 0x4000:
            gUnk_02034056 = 0x400;
            break;
        case 0x8000:
            gUnk_02034056 = 0x1000;
            break;
        case 0xC000:
            gUnk_02034056 = 0x4000;
            break;
        case 0:
        default:
            gUnk_02034056 = 0x100;
            break;
        }
    }
    SetBgSize(bg, b);
    DisableBg(bg);
}
void BgAnimSetPosition(s16 x, s16 y) {
    if (gUnk_02034058 != 0) {
        gUnk_02034050 = -x;
        gUnk_02034052 = -y;
    } else {
        gUnk_02034050 = (gBgAnimCurrent->unk_10 << 2) - x;
        gUnk_02034052 = (gBgAnimCurrent->unk_12 << 2) - y;
    }
}

void BgAnimSetTransform(u8 a, s32 b, s32 c) {
    gUnk_02034064 = a;
    gUnk_0203405C = b;
    gUnk_02034060 = c;
}

void BgAnimStart(BgAnimationDef* a, s32 x, s32 y) {
    gBgAnimCurrent = a;
    BgAnimSetPosition((s16)x, (s16)y);

    if (gUnk_02034058 != 0) {
        gUnk_0203404C = a->tilesPerFrame << 6;
    } else {
        gUnk_0203404C = a->tilesPerFrame << 5;
    }
    gUnk_0203404E = 0x8000 / gUnk_0203404C;
    gUnk_02034066 = -1;
    gUnk_02034068 = -1;
    gUnk_02034044 = 0;
    gUnk_02034046 = 0;
    gUnk_02034054 = 0;
    gUnk_0203406A = a->frameDuration;

    if (gUnk_02034058 != 0) {
        gUnk_0203405C = 0x100;
        gUnk_02034060 = 0x100;
        gUnk_02034064 = 0;
    }
    PushPaletteEffect(0);
    LoadBgPalette(gUnk_02034048, a->palette, a->paletteSize);
    PopPaletteEffect();
    LoadBgMap(gUnk_02034048, a->tilemap, gUnk_02034056);
}
void BgAnimApplyAffineTransform(s32 bg, u8 rot, s32 sx, s32 sy, s16 cx, s16 cy) {
    BgAffineSrcData src;
    BgAffineDstData dst;

    src.texX = gBgAnimCurrent->unk_10 << 10;
    src.texY = gBgAnimCurrent->unk_12 << 10;
    src.scrX = -cx;
    src.scrY = -cy;
    src.sx = 0x10000 / sx;
    src.sy = 0x10000 / sy;
    src.alpha = -rot << 8;
    BgAffineSet(&src, &dst, 1);

    switch (bg) {
    case 2:
        gBg2PA = dst.pa;
        gBg2PB = dst.pb;
        gBg2PC = dst.pc;
        gBg2PD = dst.pd;
        gBg2X = dst.dx;
        gBg2Y = dst.dy;
        break;
    case 3:
        gBg3PA = dst.pa;
        gBg3PB = dst.pb;
        gBg3PC = dst.pc;
        gBg3PD = dst.pd;
        gBg3X = dst.dx;
        gBg3Y = dst.dy;
        break;
    }
}
void BgAnimUpdate(void) {
    u8* src;
    u16 q;
    u16 off;
    u16 len;
    s16 over;
    s32 vis;

    if (gBgAnimCurrent == 0) {
        return;
    }

    if (gUnk_02034046 >= gBgAnimCurrent->frameCount) {
        if (gUnk_02034066 >= 0) {
            gUnk_02034046 = gUnk_02034066;
            gUnk_02034044 = 0;
        } else {
            BgAnimStop();
        }
        return;
    }

    if (gUnk_02034058 != 0) {
        BgAnimApplyAffineTransform(gUnk_02034048, gUnk_02034064, gUnk_0203405C, gUnk_02034060, gUnk_02034050, gUnk_02034052);
        vis = 1;
    } else {
        SetBgScroll(gUnk_02034048, (u16)gUnk_02034050, (u16)gUnk_02034052);
        if (gUnk_02034050 > -256 && gUnk_02034050 < 128 && gUnk_02034052 < 128 && gUnk_02034052 > -256) {
            vis = 1;
        } else {
            vis = 0;
        }
    }

    if (vis != 0) {
        EnableBg(gUnk_02034048);

        if (gUnk_02034044 == 0) {
            q = gUnk_02034046 / gUnk_0203404E;
            off = gUnk_02034046 % gUnk_0203404E * gUnk_0203404C;
            src = (u8*)gBgAnimCurrent->chunks[q].data + off;
            over = off + gUnk_0203404C - gBgAnimCurrent->chunks[q].size;

            if (over > 0) {
                len = gUnk_0203404C - over;
                RequestDma3Copy(src, GetBgCharBase(gUnk_02034048), len);
                RequestDma3Clear((u8*)GetBgCharBase(gUnk_02034048) + len, over);
            } else {
                RequestDma3Copy(src, GetBgCharBase(gUnk_02034048), gUnk_0203404C);
            }
        }
    } else {
        DisableBg(gUnk_02034048);
    }
    gUnk_02034044++;

    if (gUnk_02034044 >= gUnk_0203406A) {
        gUnk_02034044 = 0;

        if (gUnk_02034046 != gUnk_02034068) {
            gUnk_02034046++;
        }
    }
}

void BgAnimSetFrameDuration(u16 a) {
    gUnk_0203406A = a;
}

void BgAnimSetLoopStartFrame(u16 a) {
    gUnk_02034066 = a;
}

void BgAnimSetStopFrame(u16 a) {
    gUnk_02034068 = a;
}

void BgAnimStop(void) {
    gBgAnimCurrent = 0;
    gUnk_02034054 = 1;
    DisableBg(gUnk_02034048);
}

u8 BgAnimIsStopped(void) {
    return gUnk_02034054;
}

void BgAnimGetFrameState(u16* a, u16* b) {
    if (a != 0) {
        *a = gUnk_02034046;
    }

    if (b != 0) {
        *b = gUnk_02034044;
    }
}

u32 BgAnimGetDuration(BgAnimationDef* p) {
    return (u32)p->frameCount * p->frameDuration;
}

BgAnimationDef* BgAnimGetCurrent(void) {
    return gBgAnimCurrent;
}
