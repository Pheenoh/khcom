#include "lib.h"
#include "macros.h"
#include "types.h"

u8* gUnk_02038628;
s32 gUnk_0203862C;
s32 gUnk_02038630;
s32* gUnk_02038634;
s32 gUnk_02038638[8];
s32 gUnk_02038658[16];

static inline void ShiftInByte(void) {
    gUnk_0203862C <<= 8;
    gUnk_0203862C |= *gUnk_02038628++;
}

static inline s32 ReadBits(s32 n) {
    if (gUnk_02038630 < n) {
        ShiftInByte();
        ShiftInByte();
        gUnk_02038630 += 16;
    }
    gUnk_02038630 -= n;
    return (gUnk_0203862C >> gUnk_02038630) & 1;
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
