#include "macros.h"
#include "mode_allmap.h"

void mode_allmap_0(s32 a) {
    gUnk_02034E81 = 0;
    if (a == 1) {
        gUnk_02034E81 = a;
    }
    func_08001F5C(0, 14);
    func_080D4D44();
    func_08004DB0();
    func_08005074(3, 1, 28, 8);
    func_080055C8(3, 3);
    func_080050B8(3, gUnk_097B62B8, 0xF60);
    func_080050DC(3, gUnk_09849F78, 0x100);
    func_0800510C(3, gUnk_0983AD98, 0x500);
    func_08005074(2, 1, 29, 8);
    func_080055C8(2, 0);
    func_0800510C(2, gUnk_08125E24, 0x200);
    func_080D30C8();
    func_080D313C();
    func_08005074(0, 0, 26, 0);
    func_080055C8(0, 2);
    func_080050B8(0, gUnk_0976B340, 0x2400);
    func_080050DC(0, gUnk_0984A0F8, 0xE0);
    func_080D2F64();
    func_0800516C(0, gUnk_0203C4C0, 2, 4);
    func_08005074(1, 0, 27, 0);
    func_080055C8(1, 2);
    func_0800516C(1, gUnk_0203C510, 2, 4);
    func_08000E64(&gUnk_0203C4F0, 1);
    func_08000E14(&gUnk_0203C4F0, &gUnk_09EF4E08, 0);
    gUnk_0203C4E0 = 0;
    func_080D4EBC();
    REG_IME = 0;
    REG_IE |= 4;
    REG_DISPSTAT &= 0xFF;
    REG_DISPSTAT |= 0x5020;
    func_08006C40(func_080D2F20);
    REG_IME = 1;
    func_08006120(0, 16);
    if (gUnk_02034E81 != 0) {
        func_08120EF8(gUnk_0203DB10, 0xFF, 0x80);
    }
    gUnk_0203C534 = 30;
    gUnk_0203C508 = 30;
    gUnk_02034E38 = 0;
    gUnk_02034E3A = 0;
}

void func_080D3370(void) {
    func_080062F4(10, 1);
    func_08117FE8(gUnk_05000140, gUnk_02034E40, 16);
    func_08005BE8(gUnk_02034E40, gUnk_05000140, 32);
}

void mode_allmap_1(void) {
    func_0801CC80();
    func_08000EA4(&gUnk_0203C4F0);
    func_08000EE0(&gUnk_0203C4F0);
    if (gUnk_0203C4E0 == 0 && !func_08006314()) {
        if (gUnk_0203C534 != 0 && gUnk_0203C508 != 0) {
            gUnk_0203C4E0 = 1;
            gUnk_02034E3C = 16;
        } else {
            func_080E052C(gUnk_02034E80);
        }
    }
    if (gUnk_0203C4E0 == 2) {
        if (gUnk_0203C534 != 0) {
            gUnk_0203C534--;
        }
        if (gUnk_0203C508 != 0) {
            gUnk_0203C508--;
        }
        if (gUnk_02034E3C > 0) {
            if (gUnk_02034E3C == 16) {
                func_080D3008();
            }
            gUnk_02034E3C--;
            func_080D3034(gUnk_02034E3C);
            if (gUnk_02034E3C == 0) {
                func_080D3370();
            }
        }
        if (gUnk_0203C534 == 0 && gUnk_0203C508 == 0) {
            gUnk_0203C4E0 = 3;
        }
    }
    func_080D3050();
    if (gUnk_0203C4E0 == 2 || gUnk_0203C4E0 == 3) {
        func_08004FC8(0);
        func_08004FC8(1);
        func_080D51D8();
    } else {
        func_0800501C(0);
        func_0800501C(1);
    }
}

void mode_allmap_2(void) {
    func_080D53A8();
    func_08000F0C(&gUnk_0203C4F0);
    REG_IME = 0;
    REG_IE &= 0xFFFB;
    REG_DISPSTAT &= 0xFFDF;
    REG_IME = 1;
    func_08006C68();
    if (gUnk_02034E81 != 0) {
        func_08120EF8(gUnk_0203DB10, 0xFF, 0x100);
    }
    func_080009C4(gUnk_0203C530);
    func_080009C4(gUnk_0203C504);
}

void func_080D352C(u8 a) {
    gUnk_02034E80 = a;
}

u8 func_080D3538(u8 a, u8 b) {
    u8* p = func_080DED98(a);
    if ((u8)(p[b] + 3) <= 1) {
        return 1;
    }
    return 0;
}

u8 func_080D3564(u8 a, u8 b) {
    u16 v = func_080DEE44(a, b);
    if (v == 0 || (v & 8) != 0) {
        return 0;
    }
    return 1;
}

u8 func_080D358C(u8 a, u8 b) {
    u16 v = func_080DEE44(a, b);
    if ((v & 2) != 0) {
        return 1;
    }
    return 0;
}

s32 func_080D35B0(AllmapRoomWork* work) {
    AllmapRoomOrder order = gUnk_096FDB70;
    AllmapRoomDirs dirs = gUnk_096FDBB0;
    u32 mask;
    u8 i;

    for (i = 0; i < 4; i++) {
        work->unk_01C[i] = 0;
        work->unk_00C[i] = 0;
    }

    if (func_080DF51C(work->unk_098) == 1 || func_080DF51C(work->unk_098) == 4) {
        if (func_080D5944(work->unk_098, 8) != 0) {
            return 17;
        }
        if (func_080D5944(work->unk_098, 2) == 0) {
            return 1;
        }
    } else if (func_080D5944(work->unk_098, 2) == 0) {
        return 0;
    }

    mask = 0;
    for (i = 0; i < 4; i++) {
        if (func_080D3564(work->unk_098, i) == 0) {
            continue;
        }
        mask += 1 << i;
        if (func_080D3538(work->unk_098, i) != 0) {
            func_08005968(&work->unk_02C[i], gUnk_09EF653C, gUnk_09EF64FC);
            func_080059A4(&work->unk_02C[i], dirs.unk_00[i], 1);
            work->unk_01C[i] = func_08005AFC(&work->unk_02C[i]);
            if (work->unk_09C == 0) {
                work->unk_00C[i] = func_080026A4(gUnk_0976DEDC, 0x500);
            } else {
                work->unk_00C[i] = func_080028F8(func_08003524(gUnk_09EF64FC, 16), gUnk_0976DEDC);
            }
        } else if (func_080D358C(work->unk_098, i) == 0) {
            func_08005968(&work->unk_02C[i], gUnk_09EF658C, gUnk_09EF654C);
            func_080059A4(&work->unk_02C[i], dirs.unk_00[i], 1);
            work->unk_01C[i] = func_08005AFC(&work->unk_02C[i]);
            if (work->unk_09C == 0) {
                work->unk_00C[i] = func_080026A4(gUnk_0976E4D4, 0x500);
            } else {
                work->unk_00C[i] = func_080028F8(func_08003524(gUnk_09EF654C, 16), gUnk_0976E4D4);
            }
        }
    }
    return order.unk_00[mask] + 1;
}

s32 func_080D37BC(u8 a) {
    u8 r = 0;
    if (func_080DF51C(a) == 1 || func_080DF51C(a) == 4) {
        r = 1;
    }
    return r << 5;
}

ALIGN_ZERO(2);
