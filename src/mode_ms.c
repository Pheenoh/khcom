#include "macros.h"
#include "types.h"

INCLUDE_ASM("mode_ms/mode_ms_top_0.s");
INCLUDE_ASM("mode_ms/mode_ms_top_1.s");
INCLUDE_ASM("mode_ms/mode_ms_top_2.s");
INCLUDE_ASM("mode_ms/func_081025AC.s");
INCLUDE_ASM("mode_ms/func_081025D4.s");
INCLUDE_ASM("mode_ms/func_08102610.s");
INCLUDE_ASM("mode_ms/func_08102688.s");
INCLUDE_ASM("mode_ms/func_081026C4.s");
INCLUDE_ASM("mode_ms/func_08102728.s");
INCLUDE_ASM("mode_ms/func_08102774.s");
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
