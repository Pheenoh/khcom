#include "macros.h"
#include "types.h"


void func_080089E0(void* dst, s16 size) {
    u16 zero;
    u16* p;
    vu32* dma;

    if (size & 1) {
        ((u8*)dst)[size - 1] = 0;
    }

    p = &zero;
    *p = 0;
    dma = (vu32*)0x40000D4;
    dma[0] = (u32)p;
    dma[1] = (u32)dst;
    dma[2] = 0x81000000 | (size / 2);
    dma[2];
}

void func_08008A24(u8* src, u8* dst, s16 len) {
    s16 i;

    for (i = 0; i < len; i++) {
        dst[i] = src[i];
    }
}

u8 func_08008A54(u8* a, u8* b, s16 len) {
    s16 i;

    for (i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

INCLUDE_ASM("save/func_08008A8C.s");
INCLUDE_ASM("save/func_08008AD8.s");
INCLUDE_ASM("save/func_08008B40.s");
INCLUDE_ASM("save/func_08008B84.s");
INCLUDE_ASM("save/func_08008BBC.s");
INCLUDE_ASM("save/func_08008C58.s");
INCLUDE_ASM("save/func_08008CA8.s");
INCLUDE_ASM("save/func_08008DCC.s");
INCLUDE_ASM("save/func_08008E18.s");
INCLUDE_ASM("save/func_08008E58.s");
INCLUDE_ASM("save/func_08009088.s");
INCLUDE_ASM("save/func_080090F4.s");
INCLUDE_ASM("save/func_08009150.s");
INCLUDE_ASM("save/func_08009298.s");
INCLUDE_ASM("save/func_08009330.s");
INCLUDE_ASM("save/func_08009418.s");
INCLUDE_ASM("save/func_08009488.s");
INCLUDE_ASM("save/func_080094EC.s");
INCLUDE_ASM("save/func_0800963C.s");
INCLUDE_ASM("save/func_080096D4.s");
