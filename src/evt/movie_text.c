#include "movie_text.h"

#ifndef VERSION_JP
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
#endif

u16 CountNonSpaceChars(TextChar* str) {
    s32 i;
#ifndef VERSION_JP
    s32 n;
    TextChar c;
#endif

    i = 0;
#ifndef VERSION_JP
    n = 0;
#endif

    for (;;) {
#ifdef VERSION_JP
        if (str[i] == 0) {
            return i / 2;
        }
#else
        c = str[i];
        if (c == 0) {
            return n;
        }

        if (c != 0x20) {
            n++;
        }
#endif
        i++;
    }
}
