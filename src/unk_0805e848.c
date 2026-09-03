#include "macros.h"
#include "tutorial.h"

#ifdef VERSION_US
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
#else
INCLUDE_ASM("unk_0805e848/func_0805E848.s");
#endif

#ifdef VERSION_US
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
#else
INCLUDE_ASM("unk_0805e848/func_0805E89C.s");
#endif
