#include "macros.h"
#include "mode_eventselect.h"

INCLUDE_ASM("mode_eventselect/mode_eventselect_0.s");
INCLUDE_ASM("mode_eventselect/mode_eventselect_1.s");
INCLUDE_ASM("mode_eventselect/mode_eventselect_2.s");
INCLUDE_ASM("mode_eventselect/func_08076110.s");

void func_08076284(void) {
    gUnk_02034AA0 = 14;
}

void func_08076290(void) {
    gUnk_02034AA0 = 15;
}

void func_0807629C(void) {
    gUnk_02034AA0 = 16;
}

u8 func_080762A8(void) {
    return gUnk_02039DD4->unk_0D2;
}

void func_080762B8(void) {
    gUnk_02034AA0 = 17;
}

void func_080762C4(void) {
    gUnk_02034AA0 = 18;
}

void func_080762D0(void) {
    gUnk_02034AA0 = 19;
}

void func_080762DC(void) {
    gUnk_02034AA0 = 21;
}

void func_080762E8(void) {
    gUnk_02034AA0 = 22;
}

void func_080762F4(void) {
    gUnk_02034AA0 = 23;
}

void func_08076300(void) {
    gUnk_02034AA0 = 24;
}

void func_0807630C(void) {
    gUnk_02034AA0 = 20;
}

void func_08076318(void) {
    gUnk_02034A9C = 1;
}

void func_08076324(void) {
    gUnk_02034A9C = 2;
}

void func_08076330(void) {
    gUnk_02034A9C = 3;
}

void func_0807633C(void) {
    gUnk_02034A9C = 4;
}

void func_08076348(void) {
    gUnk_02034A9C = 5;
}

void func_08076354(void) {
    gUnk_02034A9C = 8;
}

void func_08076360(void) {
    gUnk_02034A9C = 6;
    func_0807E23C();
}

void func_08076374(void) {
    gUnk_02034A9C = 7;
    func_0807E248();
}

void func_08076388(void) {
    gUnk_02034A9C = 9;
}

void func_08076394(void) {
    gUnk_02034A9C = 10;
}

void func_080763A0(void) {
    gUnk_02034A9C = 11;
}

void func_080763AC(void) {
    gUnk_02034A9C = 12;
}

void func_080763B8(void) {
    gUnk_02034A9C = 13;
}

void func_080763C4(void) {
    gUnk_02034A9C = 0;
}

u8 func_080763D0(void) {
    if (gUnk_02034A98 != 0 && (gUnk_02034A98->unk_78 & 0x100000)) {
        return 1;
    }

    return 0;
}

void func_080763F0(void) {
    if (gUnk_02034A98 != 0) {
        if ((gUnk_02034A98->unk_78 & 0x01000044) == 0x01000044) {
            gUnk_02039DD4->unk_0E7 = 1;
        } else {
            gUnk_02039DD4->unk_0E7 = 0;
        }
    } else {
        gUnk_02039DD4->unk_0E7 = 0;
    }
}

void func_08076438(void) {
}

INCLUDE_ASM("mode_eventselect/func_0807643C.s");
INCLUDE_ASM("mode_eventselect/func_08076674.s");
INCLUDE_ASM("mode_eventselect/func_08076750.s");
INCLUDE_ASM("mode_eventselect/func_0807682C.s");
