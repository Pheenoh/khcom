#include "macros.h"
#include "mode_eventselect.h"

INCLUDE_ASM("mode_eventselect/mode_eventselect_0.s");
INCLUDE_ASM("mode_eventselect/mode_eventselect_1.s");
INCLUDE_ASM("mode_eventselect/mode_eventselect_2.s");

void func_08076110(u16 song, s16 x, s16 y) {
    u8 idx;
    s32 sx;
    s16 dx;
    s16 pan;
    s16 dist;
    s16 t;
    s16 v;
    u32 d;

    v = 0;

    if (gUnk_02039DD0 == 0) {
        return;
    }

    idx = gSongTable[song].ms;
    m4aMPlayImmInit(gMPlayTable[idx].info);

    if ((u16)x > 240) {
        gUnk_02039DD0[idx].unk_00 = v;
        gUnk_02039DD0[idx].unk_02 = v;
    }

    if ((u16)y > 160) {
        gUnk_02039DD0[idx].unk_00 = v;
        gUnk_02039DD0[idx].unk_02 = v;
    }

    sx = x;
    dx = sx;
    dx -= 120;
    pan = dx;

    if (pan > 127) {
        pan = 127;
    }

    if (pan < -128) {
        pan = -128;
    }

    gUnk_02039DD0[idx].unk_00 = pan;

    if (120 - sx >= 0) {
        t = 120 - sx;
    } else {
        t = dx;
    }

    dist = t;

    if (80 - y * 2 < 0) {
        d = y * 2 - 80;
        t = d / 2;
    } else {
        d = 80 - y * 2;
        t = d / 2;
    }
    v = dist + t;

    if (v > 256) {
        v = 256;
    }

    gUnk_02039DD0[idx].unk_02 = 256 - v;

    if (gUnk_02039DD0[idx].unk_02 < 12) {
        gUnk_02039DD0[idx].unk_02 = 12;
    }
}

void func_08076214(u8* work) {
    *(void**)&work[0x00] = func_080668F0();
    *(void**)&work[0x04] = func_08066904();
}

s32 func_0807622C(u8* work) {
    work[0x28] = _080669DC(gUnk_02039DC8->unk_6C, &work[0x08]);
    return 1;
}

void func_08076250(u8* work) {
    func_08066DC0(0, 0, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}

void func_08076274(s32* p) {
    func_08066918(p[0], p[1]);
}

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

u8 func_0807643C(void) {
    if (gUnk_02034A98 != 0) {
        return gUnk_02034A98->unk_78 & 2;
    }

    return 0;
}

void func_08076458(void) {
    u32 zero;

    gUnk_02039DD4 = EwramAlloc(sizeof(UnkStruct_02039DD4));
    zero = 0;
    CpuSet(&zero, gUnk_02039DD4, 0x05000043);
    gUnk_02039DD4->unk_000 = 0;
    gUnk_02039DD4->unk_004 = 0;
    gUnk_02039DD4->unk_008 = 0;
    gUnk_02039DD4->unk_00C = 0;
    gUnk_02039DD4->unk_010 = 0;
    gUnk_02039DD4->unk_014 = 0;
    gUnk_02039DD4->unk_0B0 = 145;
    gUnk_02039DD4->unk_0B4 = 145;
    gUnk_02039DD4->unk_0B8 = 950;
    gUnk_02039DD4->unk_0BC = 950;
    gUnk_02039DD4->unk_0C0 = 0;
    gUnk_02039DD4->unk_0C2 = 0;
    gUnk_02039DD4->unk_0C4 = 106;
    gUnk_02039DD4->unk_0C6 = 106;
    gUnk_02039DD4->unk_0C8 = 256;
    gUnk_02039DD4->unk_0CA = 256;
    gUnk_02039DD4->unk_0CC = 0;
    gUnk_02039DD4->unk_0CE = 0;
    gUnk_02039DD4->unk_0D0 = 0;
    gUnk_02039DD4->unk_0D1 = 0;
    gUnk_02039DD4->unk_0D2 = 0;
    gUnk_02039DD4->unk_0D3 = 0;
    gUnk_02039DD4->unk_0D4 = 0;
    gUnk_02039DD4->unk_0D5 = 0;
    gUnk_02039DD4->unk_0D6 = 0;
    gUnk_02039DD4->unk_0D7 = 0;
    gUnk_02039DD4->unk_0D8 = 0;
    gUnk_02039DD4->unk_0D9 = 0;
    gUnk_02039DD4->unk_0DC = 0;
    gUnk_02039DD4->unk_0E0 = 0;
    gUnk_02039DD4->unk_0E1 = 0;
    gUnk_02039DD4->unk_0E2 = 0;
    gUnk_02039DD4->unk_0E0 = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    gUnk_02039DD4->unk_0E4 = 0;
    gUnk_02039DD4->unk_0E5 = 0;
    gUnk_02039DD4->unk_0E6 = 0;
    gUnk_02039DD4->unk_0E9 = 0;
    gUnk_02039DD4->unk_0DA[0] = 0;
    gUnk_02039DD4->unk_0DA[1] = 0;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0EB = 0;
    gUnk_02039DD4->unk_0EC = 0;
    gUnk_02039DD4->unk_0ED = 0;
    gUnk_02039DD4->unk_0DE = 0;
    gUnk_02039DD4->unk_0DF = 0;
    gUnk_02039DD4->unk_0EE = 0;
    gUnk_02039DD4->unk_0F0 = 0;
    gUnk_02039DD4->unk_0F4 = 0;
    gUnk_02039DD4->unk_0F8 = 0;
    gUnk_02039DD4->unk_0FC = 0;
    gUnk_02039DD4->unk_0FE = 0;
    gUnk_02039DD4->unk_100 = 4;
    gUnk_02039DD4->unk_102 = 4;
    gUnk_02039DD4->unk_104 = 2;
    gUnk_02039DD4->unk_106 = 2;
    gUnk_02039DD4->unk_108[0] = 0;
    gUnk_02039DD4->unk_108[1] = 0;
    TaskPoolInit(&gUnk_02039DD4->unk_09C, 6);
    gUnk_02039DD4->unk_030 = LoadObjTiles(gUnk_08F709B0[0].unk_0C, 640);
    gUnk_02039DD4->unk_034 = LoadObjTiles(gUnk_08F709B0[1].unk_0C, 640);
    gUnk_02039DD4->unk_038 = LoadObjTiles(gUnk_08F709B0[2].unk_0C, 640);
    gUnk_02039DD4->unk_03C = LoadObjTiles(gUnk_08F709B0[3].unk_0C, 640);
    gUnk_02039DD4->unk_044 = LoadObjTiles(gUnk_0905EAE8, 320);
    gUnk_02039DD4->unk_048 = LoadObjTiles(gUnk_0905ED36, 320);
    gUnk_02039DD4->unk_04C = LoadObjTiles(gUnk_0905EEE6, 320);
    gUnk_02039DD4->unk_054 = LoadObjPalette(gUnk_09611AB8, 32);
    gUnk_02039DD4->unk_058 = LoadObjPalette(gUnk_08F69BA4, 32);
    func_080062F4(((UnkStruct_080038C8*)gUnk_02039DD4->unk_054)->unk_06 + 16, 1);
    func_0807B668(gUnk_02039DD4);
}

INCLUDE_ASM("mode_eventselect/func_08076674.s");
INCLUDE_ASM("mode_eventselect/func_08076750.s");
INCLUDE_ASM("mode_eventselect/func_0807682C.s");
