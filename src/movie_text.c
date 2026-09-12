#include "movie_text.h"
#include "macros.h"
#include "tutorial.h"

#ifdef VERSION_JP
u16 func_0805E848(u8* str) {
    s32 i;

    i = 0;
    for (;;) {
        if (str[i] == 0) {
            return i / 2;
        }
        i++;
    }
}
ALIGN_ZERO(2);
#else
s16 func_0805E848(u16* widths, u16 count) {
    s16 i;
    s16 total;

    total = 0;

    for (i = 0; i < count; i++) {
        total += *widths;
        widths++;
    }

    if (total / 2 > 120) {
        total = 240;
    }
    return 120 - total / 2;
}

#ifdef VERSION_EU
u16 func_0805E89C(u8* str) {
    s32 i;
    s32 n;
    u8 c;

    i = 0;
    n = 0;
    for (;;) {
        c = str[i];
        if (c == 0) {
            return n;
        }
        if (c != 0x20) {
            n++;
        }
        i++;
    }
}
ALIGN_ZERO(2);
#else
u16 func_0805E89C(u16* str) {
    s32 n;
    u16 c;

    n = 0;

    for (;;) {
        c = *str;
        if (c == 0) {
            return n;
        }

        if (c != 0x20) {
            n++;
        }
        str++;
    }
}
#endif
#endif
