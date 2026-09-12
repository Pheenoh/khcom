#include "audio_block_codec.h"

u8* gUnk_02038628;
s32 gUnk_0203862C;
s32 gUnk_02038630;
s32* gUnk_02038634;
s32 gUnk_02038638[8];
s32 gUnk_02038658[16];

extern u8 gUnk_09C43688[];
extern u8 gUnk_09C436A8[];

void func_081213C4(s32* a, s32* b, u8* c);
void func_081213CC(s32* a, s32* b);
void func_081213D4(s32* a, s32* b);

static inline void ShiftInByte(void) {
    gUnk_0203862C = (u32)gUnk_0203862C << 8;
    gUnk_0203862C |= *gUnk_02038628++;
}

static inline s32 ReadBits(s32 n) {
    if (gUnk_02038630 < n) {
        ShiftInByte();
        ShiftInByte();
        gUnk_02038630 += 16;
    }
    gUnk_02038630 -= n;
    return (gUnk_0203862C >> gUnk_02038630) & ((1 << n) - 1);
}

static inline s32 PeekByte(void) {
    if (gUnk_02038630 < 8) {
        ShiftInByte();
        gUnk_02038630 += 8;
    }
    return (gUnk_0203862C >> (gUnk_02038630 - 8)) & 0xFF;
}


static inline s32* AudioCodecSampleAtByteOffset(u32 offset, s32* base) {
    return (s32*)(offset + (u32)base);
}

void _08117284(s32 p) {
    s32 n;
    s32 up;
    s32 left;
    s32 c;
    s32 t;
    s32 i;
    u32 destOffset;
    s32 mask;

    n = ReadBits(6);
    gUnk_02038638[1] = 0;
    gUnk_02038638[2] = 0;
    gUnk_02038638[3] = 0;
    gUnk_02038638[4] = 0;
    gUnk_02038638[5] = 0;
    gUnk_02038638[6] = 0;
    gUnk_02038638[7] = 0;
    c = PeekByte();

    if (c & 0x80) {
        gUnk_02038630 -= 1;
        c = 0;
    } else {
        gUnk_02038630 -= 3;
        c = ((c >> 5) & 3) + 1;
    }

    gUnk_02038638[0] = (s32)((u32)ReadBits(4) << 28) >> 28;

    if (c > 0) {
        if (ReadBits(1)) {
            t = (s32)((u32)ReadBits(4) << 28) >> 28;
            gUnk_02038638[1] = t;

            if (t >= 0) {
                gUnk_02038638[1] = t + 1;
            }
        }

        if (c > 1) {
            if (ReadBits(1)) {
                t = (s32)((u32)ReadBits(3) << 29) >> 29;
                gUnk_02038638[2] = t;

                if (t >= 0) {
                    gUnk_02038638[2] = t + 1;
                }
            }

            if (c > 2) {
                if (ReadBits(1)) {
                    t = (s32)((u32)ReadBits(3) << 29) >> 29;
                    gUnk_02038638[3] = t;

                    if (t >= 0) {
                        gUnk_02038638[3] = t + 1;
                    }
                }

                if (c > 3) {
                    if (ReadBits(1)) {
                        t = (s32)((u32)ReadBits(3) << 29) >> 29;
                        gUnk_02038638[4] = t;

                        if (t >= 0) {
                            gUnk_02038638[4] = t + 1;
                        }
                    }
                }
            }
        }
    }

    func_081213C4(gUnk_02038638, gUnk_02038638, gUnk_09C43688);

    i = 0;
    t = p - 72;
    left = p - 1;
    up = t + n;
    mask = 0x7FF;
    destOffset = (u32)p * sizeof(s32);

    for (; i <= 7; destOffset += 4, i++) {
        s32 a;
        s32 d;
        a = up + i;
        c = left;
        d = up - 1;
        a &= mask;
        c &= mask;
        d &= mask;
        *AudioCodecSampleAtByteOffset(destOffset, gUnk_02038634) =
            gUnk_02038638[i] + gUnk_02038634[a] + gUnk_02038634[c] - gUnk_02038634[d];
    }

    if (p <= 15) {
        for (i = 0; i <= 7; i++) {
            gUnk_02038634[p + i + 0x800] = gUnk_02038634[p + i];
        }
    }
}

void _08117674(s32 p) {
    s32 n;
    s32 v;
    s32 t;
    s32 i;

    n = ReadBits(6);
    gUnk_02038638[1] = 0;
    gUnk_02038638[2] = 0;
    gUnk_02038638[3] = 0;
    gUnk_02038638[4] = 0;
    gUnk_02038638[5] = 0;
    gUnk_02038638[6] = 0;
    gUnk_02038638[7] = 0;
    v = PeekByte();

    if (v & 0x80) {
        gUnk_02038630 -= 1;
        v = 0;
    } else {
        gUnk_02038630 -= 3;
        v = ((v >> 5) & 3) + 1;
    }

    gUnk_02038638[0] = (ReadBits(4) << 28) >> 28;

    if (v > 0) {
        if (ReadBits(1)) {
            t = (ReadBits(4) << 28) >> 28;
            gUnk_02038638[1] = t;

            if (t >= 0) {
                gUnk_02038638[1] = t + 1;
            }
        }

        if (v > 1) {
            if (ReadBits(1)) {
                t = (ReadBits(3) << 29) >> 29;
                gUnk_02038638[2] = t;

                if (t >= 0) {
                    gUnk_02038638[2] = t + 1;
                }
            }

            if (v > 2) {
                if (ReadBits(1)) {
                    t = (ReadBits(3) << 29) >> 29;
                    gUnk_02038638[3] = t;

                    if (t >= 0) {
                        gUnk_02038638[3] = t + 1;
                    }
                }

                if (v > 3) {
                    if (ReadBits(1)) {
                        t = (ReadBits(3) << 29) >> 29;
                        gUnk_02038638[4] = t;

                        if (t >= 0) {
                            gUnk_02038638[4] = t + 1;
                        }
                    }
                }
            }
        }
    }

    n = (n - 72 + p) & 0x7FF;
    func_081213CC(&gUnk_02038634[n], gUnk_02038658);
    gUnk_02038658[0] += gUnk_02038638[0];
    gUnk_02038658[1] += gUnk_02038638[1];
    gUnk_02038658[2] += gUnk_02038638[2];
    gUnk_02038658[3] += gUnk_02038638[3];
    gUnk_02038658[4] += gUnk_02038638[4];
    gUnk_02038658[5] += gUnk_02038638[5];
    func_081213D4(gUnk_02038658, &gUnk_02038634[p]);

    if (p <= 15) {
        for (i = 0; i <= 7; i++) {
            gUnk_02038634[p + i + 0x800] = gUnk_02038634[p + i];
        }
    }
}

void _08117A4C(s32 p) {
    s32 n;
    s32 c;
    s32 t;
    s32 i;
    s32 up;
    s32 left;

    n = ReadBits(10);
    gUnk_02038638[1] = 0;
    gUnk_02038638[2] = 0;
    gUnk_02038638[3] = 0;
    gUnk_02038638[4] = 0;
    gUnk_02038638[5] = 0;
    gUnk_02038638[6] = 0;
    gUnk_02038638[7] = 0;
    c = PeekByte();

    if (c & 0x80) {
        gUnk_02038630 -= 1;
        c = 0;
    } else {
        gUnk_02038630 -= 3;
        c = ((c >> 5) & 3) + 1;
    }

    gUnk_02038638[0] = (s32)((u32)ReadBits(4) << 28) >> 28;

    if (c > 0) {
        if (ReadBits(1)) {
            t = (s32)((u32)ReadBits(4) << 28) >> 28;
            gUnk_02038638[1] = t;

            if (t >= 0) {
                gUnk_02038638[1] = t + 1;
            }
        }

        if (c > 1) {
            if (ReadBits(1)) {
                t = (s32)((u32)ReadBits(4) << 28) >> 28;
                gUnk_02038638[2] = t;

                if (t >= 0) {
                    gUnk_02038638[2] = t + 1;
                }
            }

            if (c > 2) {
                if (ReadBits(1)) {
                    t = (s32)((u32)ReadBits(4) << 28) >> 28;
                    gUnk_02038638[3] = t;

                    if (t >= 0) {
                        gUnk_02038638[3] = t + 1;
                    }
                }

                if (c > 3) {
                    if (ReadBits(1)) {
                        t = (s32)((u32)ReadBits(4) << 28) >> 28;
                        gUnk_02038638[4] = t;

                        if (t >= 0) {
                            gUnk_02038638[4] = t + 1;
                        }
                    }
                }
            }
        }
    }

    func_081213C4(gUnk_02038638, gUnk_02038638, gUnk_09C436A8);
    i = 0;
    t = p - 1040;
    left = p - 1;
    up = t + n;

    for (; i <= 15; i++) {
        s32 a;
        s32 d;
        a = up + i;
        c = left;
        d = up - 1;
        a &= 0x7FF;
        c &= 0x7FF;
        d &= 0x7FF;
        gUnk_02038634[p + i] = gUnk_02038634[a] + gUnk_02038634[c] -
                               gUnk_02038634[d] + gUnk_02038638[i >> 1];
    }

    if (p <= 15) {
        for (i = 0; i <= 15; i++) {
            gUnk_02038634[p + i + 0x800] = gUnk_02038634[p + i];
        }
    }
}

void func_08117E44(s32 p) {
    if (ReadBits(1) != 0) {
        _08117A4C(p);
    } else {
        if (ReadBits(1) != 0) {
            _08117674(p);
        } else {
            _08117284(p);
        }

        if (ReadBits(1) != 0) {
            _08117674(p + 8);
        } else {
            _08117284(p + 8);
        }
    }
}

void func_08117F5C(u8* src, s32* a1, s32 dst) {
    u8** p = &gUnk_02038628;
    s32 i;

    gUnk_02038634 = a1;
    gUnk_0203862C = *src;
    *p = src + 1;
    gUnk_02038630 = 8;

    for (i = 31; i >= 0; i--) {
        func_08117E44(dst);
        dst += 0x10;
    }
}

s32 func_08117F9C(void) {
    if (gUnk_02038630 < 8) {
        ShiftInByte();
        gUnk_02038630 += 8;
    }
    return (gUnk_0203862C >> (gUnk_02038630 - 8)) & 0xFF;
}
