#include "unk_0810fe94.h"

u8 gUnk_02036014;
s16 gUnk_02036016;
s16 gUnk_02036018;
s32 gUnk_0203601C;

void func_0810FE94(void) {
    gUnk_02036014 = 0;
    gUnk_02036016 = 0;
    gUnk_02036018 = 0;
    gUnk_0203601C = 0;
}

void func_0810FEBC(s16 a) {
    gUnk_02036016 = a;
    gUnk_02036018 = 0;
    gUnk_0203601C = 0;
}

void func_0810FEDC(void) {
    const s8* p;

    if (gUnk_02036014 != 0) {
        p = gUnk_09EF9E6C[gUnk_02036016];
        gUnk_0203601C += ((p[gUnk_02036018] << 12) - gUnk_0203601C) >> 3;
        gUnk_02036018++;
        if (p[gUnk_02036018] == 0) {
            gUnk_02036014 = 0;
            gUnk_0203601C = 0;
        }
    }
}

s32 func_0810FF44(void) {
    return gUnk_0203601C;
}

void func_0810FF50(Task* t, s32 a, s32 b) {
    LstFldWork* w = t->work;

    if (a != w->unk_010) {
        w->unk_010 = a;
        w->unk_008 = 0;
        w->unk_014 = b;
    }
}

void func_0810FF64(Task* t, s32 a) {
    LstFldWork* w = t->work;

    w->unk_000 = a;
}

void func_0810FF6C(Task* t, s32 a) {
    LstFldWork* w = t->work;

    w->unk_01C = ((a >> 8) * 5 >> 2) + 2;
}
