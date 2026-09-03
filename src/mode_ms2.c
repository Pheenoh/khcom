#include "macros.h"
#include "mode_ms2.h"
#include "gba/keys.h"

UnkStruct_0810718C* gUnk_02035E28;
s16 gUnk_02035E2C;
s16 gUnk_02035E2E;
u16 gUnk_02035E30[4];
u16 gUnk_02035E38[4];
s16 gUnk_02035E40[4];
s16 gUnk_02035E48;
void* gUnk_02035E4C;
void* gUnk_02035E50;
u32 gUnk_02035E54;
AnimState gUnk_02035E58;
void* gUnk_02035E70;
void* gUnk_02035E74;
void* gUnk_02035E78;
u32 gUnk_02035E7C;
AnimState gUnk_02035E80;
s16 gUnk_02035E98;
s16 gUnk_02035E9A;
s16 gUnk_02035E9C;
void* gUnk_02035EA0[4][3];
void* gUnk_02035ED0[4][3];
void* gUnk_02035F00[4][3];
u8 gUnk_02035F30[4][3];
void* gUnk_02035F3C;
void* gUnk_02035F40;
void* gUnk_02035F44;
void* gUnk_02035F48;
void* gUnk_02035F4C;
void* gUnk_02035F50;
void* gUnk_02035F54;
AnimState gUnk_02035F58;
void* gUnk_02035F70;
u32 gUnk_02035F74;
AnimState gUnk_02035F78;
u8 gUnk_02035F90;
u8* gUnk_02035F94;
u8 gUnk_02035F98;
u8* gUnk_02035F9C;
u8 gUnk_02035FA0;
u8* gUnk_02035FA4;
u8 gUnk_02035FA8;
u16 gUnk_02035FAA;
u8* gUnk_02035FAC;
u8 gUnk_02035FB0;
u16 gUnk_02035FB2;
u8* gUnk_02035FB4;
u8 gUnk_02035FB8;
u16 gUnk_02035FBA;
u8* gUnk_02035FBC;
u8 gUnk_02035FC0;
u16 gUnk_02035FC2[1];

#ifdef NON_MATCHING
void mode_ms_charge_0(void) {
    s16 i;
    s16 j;
    void** pd;
    u8* pb;

    pd = &gUnk_02035C10;
    *pd = EwramAlloc(0x3A18);
    SpriteReset();
    func_08006120(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 30, 0);
    SetupBg(3, 0, 31, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    gUnk_02035C14 = 0;
    gUnk_02035C18 = 4;
    func_0810563C();
    gUnk_02035CE0 = 0;
    gUnk_02035CE2 = 0;
    gUnk_02035CE4 = 0;

    if (gUnk_02035C3A > 0) {
        gUnk_02035E18 = 0xB500;
        gUnk_02035E1C = 0x2800;
        gUnk_02035C16 = 0;
    } else {
        gUnk_02035E18 = gUnk_02035C18 * 3584 + 0xAC00;
        gUnk_02035E1C = 0x1000;
        gUnk_02035C16 = 1;
    }

    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 2; j++) {
            gUnk_02035CE8[i][j] = 0;
            gUnk_02035D18[i][j] = 0;
            gUnk_02035D48[i][j] = 0;
            gUnk_02035D78[i][j] = 0;
        }
    }
    gUnk_02035D84 = 0;
    gUnk_02035D88 = 0;
    gUnk_02035D8C = 0;
    gUnk_02035D94 = 0;
    gUnk_02035D98 = 0;
    gUnk_02035DD8 = 0;
    gUnk_02035E0C = 0;
    gUnk_02035E0E = 0;
    gUnk_02035CB8 = 0;
    gUnk_02035CBA = -1;
    gUnk_02035CBC = 0;
    LoadBgPalette(0, gUnk_09A3DBDC, 0x1A0);
    LoadBgTiles(0, gUnk_09A1913C, 0x4A60);
    LoadBgMap(0, gUnk_09A3B25C, 0x500);

    if (func_08104B2C()->unk_04 == 3) {
        LoadBgMap(1, gUnk_09A3BD5C, 0x500);
    } else {
        LoadBgMap(1, gUnk_09A3B85C, 0x500);
    }
    func_081052C8(gUnk_02035C18);
    LoadBgMap(2, gUnk_09A3C25C, 0x500);
    func_08104F2C();
    func_08104FA4();
    func_08104FF8();
    func_08105090();
    gUnk_02035D90 = LoadObjPalette(gUnk_09611AB8, 32);
    gUnk_02035D9C = LoadObjTiles(gUnk_0908B1B4, 0x9A0);
    AnimInit(&gUnk_02035DA0, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&gUnk_02035DA0, 0, 1);
    gUnk_02035DB8 = LoadObjTiles(gUnk_0908C3CE, 0x260);
    AnimInit(&gUnk_02035DC0, gUnk_09EEA198, gUnk_09EEA180);
    AnimStart(&gUnk_02035DC0, 0, 1);
    gUnk_02035C40 = LoadObjTiles(gUnk_099A7C78, 32);
    gUnk_02035C44 = LoadObjPalette(gUnk_09A3DE7C, 32);
    gUnk_02035C48 = LoadObjTiles(gUnk_099A6C82, 0xFE0);
    AnimInit(&gUnk_02035C50, gUnk_09EF9AA4, gUnk_09EF9A68);
    AnimStart(&gUnk_02035C50, 1, 1);
    AnimInit(&gUnk_02035C68, gUnk_09EF9AA4, gUnk_09EF9A68);
    AnimStart(&gUnk_02035C68, 2, 1);
    gUnk_02035C80 = LoadObjPalette(gUnk_09617D58, 32);
    gUnk_02035C84 = LoadObjTiles(gUnk_099A2194, 0x940);
    AnimInit(&gUnk_02035C88, gUnk_09EF9978, gUnk_09EF9928);
    AnimStart(&gUnk_02035C88, 3, 1);
    AnimInit(&gUnk_02035CA0, gUnk_09EF9978, gUnk_09EF9928);
    AnimStart(&gUnk_02035CA0, 0, 1);
    gUnk_02035CC0 = LoadObjPalette(gUnk_09617D58, 32);
    gUnk_02035CC4 = LoadObjTiles(gUnk_092028EC, 0xC00);
    AnimInit(&gUnk_02035CC8, gUnk_09EEEAC8, gUnk_09EEEA98);
    pd = &gUnk_02035DDC;
    *pd = EwramAlloc(0x120);
    func_08065ACC(gUnk_02035DDC, 36);
    pd = &gUnk_02035DE4;
    *pd = EwramAlloc(0x2D0);
    func_08065ACC(gUnk_02035DE4, 90);
    gUnk_02035DF2 = func_08065B54(gUnk_08159F38);
    pd = &gUnk_02035DEC;
    *pd = EwramAlloc(gUnk_02035DF2 * 8);
    func_08065ACC(gUnk_02035DEC, gUnk_02035DF2);
    pb = &gUnk_02035DF0;
    *pb = func_08065B6C(gUnk_08159F38, gUnk_02035DEC);
    gUnk_02035DFA = func_08065B54(gUnk_0815C204);
    pd = &gUnk_02035DF4;
    *pd = EwramAlloc(gUnk_02035DFA * 8);
    func_08065ACC(gUnk_02035DF4, gUnk_02035DFA);
    pb = &gUnk_02035DF8;
    *pb = func_08065B6C(gUnk_0815C204, gUnk_02035DF4);
    gUnk_02035E02 = func_08065B54(gUnk_08159E10);
    pd = &gUnk_02035DFC;
    *pd = EwramAlloc(gUnk_02035E02 * 8);
    func_08065ACC(gUnk_02035DFC, gUnk_02035E02);
    pb = &gUnk_02035E00;
    *pb = func_08065B6C(gUnk_08159E10, gUnk_02035DFC);
    gUnk_02035E0A = func_08065B54(gUnk_08159E18);
    pd = &gUnk_02035E04;
    *pd = EwramAlloc(gUnk_02035E0A * 8);
    func_08065ACC(gUnk_02035E04, gUnk_02035E0A);
    pb = &gUnk_02035E08;
    *pb = func_08065B6C(gUnk_08159E18, gUnk_02035E04);
    func_08104BBC();
    func_08104D18();
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}
#else
INCLUDE_ASM("mode_ms2/mode_ms_charge_0.s");
#endif

void mode_ms_charge_1(void) {
    UpdatePlayTime();
    gUnk_02035CB8 += 2;

    switch (gUnk_02035C14) {
    case 0:
        if (!func_08006314()) {
            gUnk_02035C14 = 1;
        }
        break;
    case 1:
        switch (gUnk_02035C16) {
        case 0:
            func_0810594C();
            break;
        case 1:
            func_08105BD8();
            break;
        case 2:
            func_08105DE0();
            break;
        case 3:
            func_0810601C();
            break;
        case 4:
            func_081061DC();
            break;
        }
        break;
    case 2:
        if (!func_08006314()) {
            if (gUnk_02035E20 != 0) {
                ModeRequest(&gModeMsTop, 2);
            } else {
                func_080E04EC();
            }
        }
        break;
    }

    if (gUnk_02035CBC > 0) {
        if (AnimGetId(&gUnk_02035CA0) != 2) {
            if (gUnk_02035CBA < 0) {
                gUnk_02035CBA = AnimGetId(&gUnk_02035CA0);
            }
            AnimStart(&gUnk_02035CA0, 2, 1);
        }

        if (--gUnk_02035CBC <= 0) {
            if (AnimGetId(&gUnk_02035CA0) != gUnk_02035CBA) {
                AnimStart(&gUnk_02035CA0, gUnk_02035CBA, 1);
            }
            gUnk_02035CBA = -1;
        }
    } else if (gUnk_02035CBA >= 0) {
        if (AnimGetId(&gUnk_02035CA0) != gUnk_02035CBA) {
            AnimStart(&gUnk_02035CA0, gUnk_02035CBA, 1);
        }
        gUnk_02035CBA = -1;
    }
    func_08106234();
}

void mode_ms_charge_2(void) {
    s32 i;
    s32 j;

    ReleaseObjPalette(gUnk_02035D90);
    ReleaseObjTiles(gUnk_02035D9C);
    ReleaseObjTiles(gUnk_02035DB8);
    ReleaseObjTiles(gUnk_02035C40);
    ReleaseObjPalette(gUnk_02035C44);
    ReleaseObjTiles(gUnk_02035C48);
    ReleaseObjPalette(gUnk_02035C80);
    ReleaseObjTiles(gUnk_02035C84);
    ReleaseObjPalette(gUnk_02035CC0);
    ReleaseObjTiles(gUnk_02035CC4);

    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 2; j++) {
            if (gUnk_02035CE8[i][j] != 0) {
                ReleaseObjPalette(gUnk_02035CE8[i][j]);
            }

            if (gUnk_02035D18[i][j] != 0) {
                ReleaseObjTiles(gUnk_02035D18[i][j]);
            }
        }
    }

    if (gUnk_02035D84 != 0) {
        ReleaseObjPalette(gUnk_02035D84);
    }

    if (gUnk_02035D88 != 0) {
        ReleaseObjTiles(gUnk_02035D88);
    }

    if (gUnk_02035D94 != 0) {
        ReleaseObjTiles(gUnk_02035D94);
    }
    func_08065AE0(gUnk_02035DDC, 36);
    EwramFree(gUnk_02035DDC);
    func_08065AE0(gUnk_02035DE4, 90);
    EwramFree(gUnk_02035DE4);
    func_08065AE0(gUnk_02035DEC, gUnk_02035DF2);
    EwramFree(gUnk_02035DEC);
    func_08065AE0(gUnk_02035DF4, gUnk_02035DFA);
    EwramFree(gUnk_02035DF4);
    func_08065AE0(gUnk_02035DFC, gUnk_02035E02);
    EwramFree(gUnk_02035DFC);
    func_08065AE0(gUnk_02035E04, gUnk_02035E0A);
    EwramFree(gUnk_02035E04);
    EwramFree(gUnk_02035C10);
}

s16 func_0810712C(s16 a) {
    s16 r;

    if (a <= 3) {
        r = gUnk_02035E30[a];
    } else {
        r = 0;
    }
    return r;
}

s16 func_0810714C(void) {
    return func_0810712C(gUnk_02035E2E) + (gUnk_02035E9C + gUnk_02035E9A) * 3 + gUnk_02035E98;
}

UnkStruct_0810718C* func_0810718C(void) {
    return &gUnk_02035E28[func_0810714C()];
}

void func_081071AC(void) {
    UnkStruct_0810718C* p;
    s16 i;

    p = func_0810718C();
    if (p->unk_00 <= 26) {
        for (i = 0; i < 10; i++) {
            if (p->unk_06[i] > 0) {
                break;
            }
        }
        gUnk_02035FC4 = i / 5;
        gUnk_02035FC6 = i % 5;
    } else {
        gUnk_02035FC4 = 0;
        gUnk_02035FC6 = 0;
    }
}

s16 func_08107220(s16 a) {
    s16 r;
    s16 i;
    s32 t;

    if (a <= 3) {
        r = gUnk_02035E38[a];
    } else {
        r = 0;

        for (i = 0; i <= 3; i++) {
            t = gUnk_02035E38[i];
            r += t;
        }
    }
    return r;
}

u8 func_08107268(void) {
    if (gUnk_02035E48 > 20) {
        return 1;
    }
    return 0;
}

void func_08107280(void) {
    s16 a;
    s16 k;
    s16 i;
    s16 j;
    s16 b;
    u16 idx;

    a = func_0810712C(gUnk_02035E2E);
    b = func_08107220(gUnk_02035E2E);
    k = gUnk_02035E9C * 3;

    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 2; j++) {
            if (gUnk_02035EA0[i][j] != 0) {
                ReleaseObjPalette(gUnk_02035EA0[i][j]);
            }

            if (gUnk_02035ED0[i][j] != 0) {
                ReleaseObjTiles(gUnk_02035ED0[i][j]);
            }

            if (k < b) {
                idx = gUnk_02035E28[a + k].unk_02;
                gUnk_02035EA0[i][j] = LoadObjPalette(gUnk_09EE4C80[idx].unk_10, 32);
                gUnk_02035ED0[i][j] = LoadObjTiles(gUnk_09EE4C80[idx].unk_0C, gUnk_09EE4C80[idx].unk_1C);
                gUnk_02035F00[i][j] = *gUnk_09EE4C80[idx].unk_14;
                gUnk_02035F30[i][j] = gUnk_02035E28[a + k].unk_04 == 3;
            } else {
                gUnk_02035EA0[i][j] = 0;
                gUnk_02035ED0[i][j] = 0;
                gUnk_02035F00[i][j] = 0;
                gUnk_02035F30[i][j] = 0;
            }
            k++;
        }
    }
}

void func_081073F0(void) {
    UnkStruct_0810718C* p;
    u16 idx;
    u16 k;
    u8* q;

    p = func_0810718C();

    if (gUnk_02035F3C != 0) {
        ReleaseObjPalette(gUnk_02035F3C);
    }

    if (gUnk_02035F40 != 0) {
        ReleaseObjTiles(gUnk_02035F40);
    }

    if (gUnk_02035F48 != 0) {
        ReleaseObjPalette(gUnk_02035F48);
    }

    if (gUnk_02035F4C != 0) {
        ReleaseObjTiles(gUnk_02035F4C);
    }

    if (gUnk_02035E74 != 0) {
        ReleaseObjPalette(gUnk_02035E74);
    }

    if (p->unk_00 <= 26 && func_08107220(gUnk_02035E2E) > 0) {
        idx = p->unk_02;
        k = gUnk_099937A0[p->unk_04];
        gUnk_02035F3C = LoadObjPalette(gUnk_09EE4C80[idx].unk_04, gUnk_09EE4C80[idx].unk_1A);
        gUnk_02035F40 = LoadObjTiles(gUnk_09EE4C80[idx].unk_00, gUnk_09EE4C80[idx].unk_18);
        gUnk_02035F44 = *gUnk_09EE4C80[idx].unk_08;
        gUnk_02035F48 = LoadObjPalette(gUnk_09EE4BF4[k].unk_04, gUnk_09EE4BF4[k].unk_16);
        gUnk_02035F4C = LoadObjTiles(gUnk_09EE4BF4[k].unk_00, gUnk_09EE4BF4[k].unk_14);
        gUnk_02035F50 = *gUnk_09EE4BF4[k].unk_08;
        gUnk_02035F90 = p->unk_04 == 3;
        gUnk_02035E74 = LoadObjPalette(gUnk_09A3D2FC + p->unk_04 * 32, 32);
        q = &gUnk_02035F98;
        *q = func_08065B6C(func_08093C18(p->unk_00), gUnk_02035F94);
        q = &gUnk_02035FA0;
        *q = func_08065B6C(gUnk_09EE90D0[p->unk_00], gUnk_02035F9C);
    } else {
        gUnk_02035F3C = 0;
        gUnk_02035F40 = 0;
        gUnk_02035F44 = 0;
        gUnk_02035F48 = 0;
        gUnk_02035F4C = 0;
        gUnk_02035F50 = 0;
        gUnk_02035F90 = 0;
        gUnk_02035E74 = 0;
        gUnk_02035F98 = 0;
        gUnk_02035FA0 = 0;
    }
}

s16 func_081075C0(s16 a, s16 b) {
    return b + a * 5;
}

s16 func_081075D8(void) {
    return func_081075C0(gUnk_02035FC4, gUnk_02035FC6);
}

void func_081075FC(void) {
    func_08101588(gUnk_02035E48, gUnk_09A0693C, (u8*)GetBgCharBase(0) + 0x3A0, 32, 2);
    func_08101588(99, gUnk_09A0693C, (u8*)GetBgCharBase(0) + 0x3E0, 32, 2);
}

void func_0810764C(void) {
    s16 i;
    s16 v;

    for (i = 0; i <= 3; i++) {
        v = gUnk_02035E40[i];
        if (v != 0) {
            func_08101588(v, gUnk_09A0669C, (u8*)GetBgCharBase(0) + (i * 64 + 0x2A0), 32, 2);
        } else {
            func_08101588(0, gUnk_09A0667C, (u8*)GetBgCharBase(0) + (i * 64 + 0x2A0), 32, 2);
        }
    }
}

#ifdef NON_MATCHING
void func_081076D4(void) {
    UnkStruct_0810718C* p;
    s16 i;
    s16 v;

    p = func_0810718C();

    if (func_08107220(gUnk_02035E2E) > 0) {
        LoadPalette(gUnk_09A3D2FC + p->unk_04 * 32, (void*)0x05000000, 12);
    }

    if (gUnk_02035E2C == 1) {
        for (i = 0; i <= 9; i++) {
            func_08101588(0, gUnk_09A067DC, (u8*)GetBgCharBase(0) + (i * 64 + 0x40), 32, 1);
            LoadPalette(gUnk_09A3D2C8, (void*)(0x0500000C + i * 2), 2);
        }
    } else if (p->unk_04 == 3) {
        if (func_08107220(gUnk_02035E2E) > 0) {
            LoadBgMap(1, gUnk_09A3551C, 0x500);
        }

        for (i = 0; i <= 9; i++) {
            v = p->unk_06[i];
            if (v != 0 && func_08107220(gUnk_02035E2E) > 0) {
                func_08101588(v, gUnk_09A067FC, (u8*)GetBgCharBase(0) + 0x40, 32, 1);
                LoadPalette(gUnk_09A3D248, (void*)0x0500000C, 2);
                break;
            }
        }

        if (i > 9) {
            func_08101588(0, gUnk_09A067DC, (u8*)GetBgCharBase(0) + 0x40, 32, 1);
            LoadPalette(gUnk_09A3D2C8, (void*)0x0500000C, 2);
        }
    } else {
        if (func_08107220(gUnk_02035E2E) > 0) {
            LoadBgMap(1, gUnk_09A3501C, 0x500);
        }

        for (i = 0; i <= 9; i++) {
            v = p->unk_06[i];
            if (v != 0 && func_08107220(gUnk_02035E2E) > 0) {
                func_08101588(v, gUnk_09A067FC, (u8*)GetBgCharBase(0) + (i * 64 + 0x40), 32, 1);
                LoadPalette(gUnk_09A3D248, (void*)(0x0500000C + i * 2), 2);
            } else {
                func_08101588(0, gUnk_09A067DC, (u8*)GetBgCharBase(0) + (i * 64 + 0x40), 32, 1);
                LoadPalette(gUnk_09A3D2C8, (void*)(0x0500000C + i * 2), 2);
            }
        }
    }
}
#else
INCLUDE_ASM("mode_ms2/func_081076D4.s");
#endif

void func_081078F0(s16 a) {
    func_0800448C(gUnk_09A34D9C, GetBgScreenBase(0), 0, gUnk_09EF9618[a].unk_04 * 2, 0, 2, 11, 2);
}

INCLUDE_ASM("mode_ms2/func_08107938.s");

u8 func_081079A8(UnkStruct_0810718C* p) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (p->unk_06[i] > 0) {
            break;
        }
    }

    if (i > 9) {
        return 1;
    }
    return 0;
}

u8 func_081079E4(UnkStruct_0810718C* p) {
    if (p->unk_06[func_081075D8()] == 0) {
        return 1;
    }
    return 0;
}

void func_08107A08(UnkStruct_0810718C* p) {
    s16 k;
    s16 i;

    k = func_081075D8();

    for (i = 0; i <= 9; i++) {
        if (p->unk_06[k] > 0) {
            break;
        }
        k++;
        if (k > 9) {
            k = 0;
        }
    }
    gUnk_02035FC4 = k / 5;
    gUnk_02035FC6 = k % 5;
}

void func_08107A74(UnkStruct_0810718C* p) {
    vu32* dma;
    vu16 zero;
    UnkStruct_0810718C* q;
    u16 row;
    s16 j;

    row = p->unk_04;
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)(p + 1);
    dma[1] = (u32)p;
    dma[2] = ((26 - func_0810714C()) * 14) | 0x80000000;
    dma[2];
    zero = 0;
    dma[0] = (u32)&zero;
    q = &gUnk_02035E28[26];
    dma[1] = (u32)q;
    dma[2] = 0x8100000E;
    dma[2];
    q->unk_00 = 27;

    for (j = row + 1; j <= 3; j++) {
        gUnk_02035E30[j]--;
    }
    gUnk_02035E38[row]--;

    if (func_0810714C() >= func_08107220(gUnk_02035E2E)) {
        if (--gUnk_02035E98 < 0) {
            gUnk_02035E98 = 2;

            if (--gUnk_02035E9A < 0) {
                gUnk_02035E9A = 0;

                if (--gUnk_02035E9C < 0) {
                    gUnk_02035E98 = 0;
                    gUnk_02035E9C = 0;
                }
            }
        }
    }
    gUnk_02035FC4 = 0;
    gUnk_02035FC6 = 0;
    func_08107280();
    func_081073F0();
    func_081076D4();
}

#ifdef NON_MATCHING
void func_08107B84(void) {
    s16* pd;
    vu32* dma;
    vu16 zero;
    s16 i;
    s32 w;
    s16 k;
    s16 j;
    s16 m;
    s16 a;
    u16 u;
    u16 n;
    u16 t;

    zero = 0;
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)&zero;
    dma[1] = (u32)gUnk_02035E28;
    dma[2] = 0x8100017A;
    dma[2];

    for (i = 0; i <= 26; i++) {
        gUnk_02035E28[i].unk_00 = 27;
    }
    a = 0;
    gUnk_02035E48 = 0;

    for (j = 0; j <= 3; j++) {
        gUnk_02035E30[j] = a;
        gUnk_02035E40[j] = 0;

        for (k = 0; k <= 26; k++) {
            t = gUnk_09EE4C80[k * 10].unk_24;
            if (t == gUnk_099937A0[j]) {
                u = gUnk_09EE4C80[k * 10].unk_20;

                for (m = 0; m <= 9; m++) {
                    n = gUnk_0203C0A8[(u16)(k * 10 + m)];
                    if (n != 0) {
                        if (t != 4) {
                            gUnk_02035E48 += n;
                        }
                        gUnk_02035E40[j] += n;
                        gUnk_02035E28[a].unk_00 = u;
                        gUnk_02035E28[a].unk_02 = k * 10;
                        gUnk_02035E28[a].unk_04 = j;
                        gUnk_02035E28[a].unk_06[m] = n;
                    }
                }
            }

            if (gUnk_02035E28[a].unk_00 <= 26) {
                a++;
            }
        }
        pd = &gUnk_02035E38[j];
        w = gUnk_02035E30[j];
        *pd = a - w;
    }
}
#else
INCLUDE_ASM("mode_ms2/func_08107B84.s");
#endif

u16 func_08107D24(void) {
    u16 keys;

    keys = GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    keys |= GetKeysRepeat() & (DPAD_ANY | L_BUTTON | R_BUTTON);
    return keys;
}

void func_08107D44(void) {
    s16 a;
    s16 b;
    s16 c;
    u16 keys;

    a = gUnk_02035E98;
    b = gUnk_02035E9A;
    c = gUnk_02035E9C;
    keys = func_08107D24();
    if (keys & 1) {
        if (func_0810718C()->unk_04 != 3) {
            func_081071AC();
            m4aSongNumStart(0x66);
            AnimStart(&gUnk_02035E80, 1, 1);
            gUnk_02035E2C = 2;
        } else {
            m4aSongNumStart(0x69);
        }
    } else if (keys & 2) {
        LoadBgMap(0, gUnk_09A3439C, 0x500);
        m4aSongNumStart(0x68);
        gUnk_02035FE4 = 1;
        gUnk_02035FCC = 16;
        gUnk_02035FCA = 3;
    } else if (keys & 8) {
        LoadBgMap(0, gUnk_09A3439C, 0x500);
        m4aSongNumStart(0x68);
        gUnk_02035FE4 = 0;
        func_08006184(0, 16);
        gUnk_02035FCA = 5;
    } else if (keys & 4) {
        gUnk_02035E98 = 0;
        gUnk_02035E9A = 0;
        gUnk_02035E9C = 0;
        m4aSongNumStart(0x79);
        gUnk_02035E2C = 1;
        func_081076D4();
    } else if (keys & 0x40) {
        if (gUnk_02035E9A > 0) {
            gUnk_02035E9A--;
        } else if (gUnk_02035E9C > 0) {
            gUnk_02035E9C--;
        } else {
            m4aSongNumStart(0x79);
            gUnk_02035E2C = 1;
            func_081076D4();
        }
    } else if (keys & 0x80) {
        if ((gUnk_02035E9C + gUnk_02035E9A + 1) * 3 + gUnk_02035E98 < func_08107220(gUnk_02035E2E)) {
            if (gUnk_02035E9A > 2) {
                gUnk_02035E9C++;
            } else {
                gUnk_02035E9A++;
            }
        } else if (gUnk_02035E9A == 3) {
            if ((gUnk_02035E9C + gUnk_02035E9A + 1) * 3 < func_08107220(gUnk_02035E2E)) {
                gUnk_02035E98 = (func_08107220(gUnk_02035E2E) - 1) % 3;
                gUnk_02035E9C++;
            }
        }
    } else if (keys & 0x20) {
        if (gUnk_02035E98 > 0) {
            gUnk_02035E98--;
        }
    } else if (keys & 0x10) {
        if ((gUnk_02035E9C + gUnk_02035E9A) * 3 + gUnk_02035E98 + 1 < func_08107220(gUnk_02035E2E)) {
            if (gUnk_02035E98 <= 1) {
                gUnk_02035E98++;
            }
        }
    }

    if (gUnk_02035E98 != a || gUnk_02035E9A != b || gUnk_02035E9C != c) {
        func_081071AC();
        func_081076D4();
        func_081073F0();
        m4aSongNumStart(0x79);

        if (gUnk_02035E9C != c) {
            func_08107280();
        }
    }
}

void func_08107FF0(void) {
    s16 old;
    u16 keys;

    old = gUnk_02035E2E;
    keys = func_08107D24();
    if ((keys & 1) == 0) {
        if (keys & 8) {
            LoadBgMap(0, gUnk_09A3439C, 0x500);
            m4aSongNumStart(0x68);
            gUnk_02035FE4 = 0;
            func_08006184(0, 16);
            gUnk_02035FCA = 5;
        } else if (keys & 0x82) {
            if (func_08107220(gUnk_02035E2E) > 0) {
                gUnk_02035E98 = 0;
                gUnk_02035E9A = 0;
                gUnk_02035E9C = 0;
                func_081071AC();
                func_081076D4();
                func_081073F0();
                AnimStart(&gUnk_02035E80, 0, 1);
                m4aSongNumStart(0x79);
                gUnk_02035E2C = 0;
                func_081076D4();
            } else if (keys & 2) {
                LoadBgMap(0, gUnk_09A3439C, 0x500);
                m4aSongNumStart(0x68);
                gUnk_02035FE4 = 1;
                gUnk_02035FCC = 16;
                gUnk_02035FCA = 3;
            } else if (keys & 0x80) {
                m4aSongNumStart(0x69);
            }
        } else if (keys & 0x20) {
            gUnk_02035E2E = gUnk_09EF9618[gUnk_02035E2E].unk_00;
        } else if (keys & 0x10) {
            gUnk_02035E2E = gUnk_09EF9618[gUnk_02035E2E].unk_02;
        }
    }

    if (gUnk_02035E2E < 0) {
        gUnk_02035E2E = old;
    }

    if (gUnk_02035E2E != old) {
        func_081078F0(gUnk_02035E2E);
        func_08107280();
        m4aSongNumStart(0x65);
    }
}

void func_08108170(UnkStruct_0810718C* p, u16 row) {
    s16 c;
    s16 i;
    s32 k;

    c = gUnk_02035FC6;

    for (i = 0; i <= 4; i++) {
        k = c - i;
        if (k >= 0 && p->unk_06[func_081075C0(row, k)] > 0) {
            gUnk_02035FC4 = row;
            gUnk_02035FC6 = k;
            return;
        }
        k = c + i;
        if (k <= 4 && p->unk_06[func_081075C0(row, k)] > 0) {
            gUnk_02035FC4 = row;
            gUnk_02035FC6 = k;
            return;
        }
    }
}

#ifdef NON_MATCHING
void func_08108208(void) {
    UnkStruct_0810718C* p;
    s16 a;
    s16 b;
    s16 i;
    u16 keys;

    p = func_0810718C();
    a = gUnk_02035FC4;
    b = gUnk_02035FC6;
    keys = func_08107D24();
    if (keys & 1) {
        if (func_08107268()) {
            gUnk_02035FC8 = 1;
            gUnk_02035FDC = 0x7400;
            gUnk_02035FE0 = 0x5000;
            AnimStart(&gUnk_02035E58, 4, 1);
            EnableBg(2);
            m4aSongNumStart(0x67);
            gUnk_02035E2C = 3;
        } else {
            EnableBg(2);
            m4aSongNumStart(0x69);
            gUnk_02035E2C = 4;
        }
    } else {
        if (keys & 2) {
            m4aSongNumStart(0x68);
            AnimStart(&gUnk_02035E80, 0, 1);
            gUnk_02035E2C = 0;
        } else if (keys & 8) {
            LoadBgMap(0, gUnk_09A3439C, 0x500);
            m4aSongNumStart(0x68);
            gUnk_02035FE4 = 0;
            func_08006184(0, 16);
            gUnk_02035FCA = 5;
        } else if (keys & 0x20) {
            func_08108170(p, 0);
        } else if (keys & 0x10) {
            func_08108170(p, 1);
        } else if (keys & 0x40) {
            for (i = 0; i <= 4; i++) {
                if (--gUnk_02035FC6 < 0) {
                    gUnk_02035FC6 = 4;
                }

                if (p->unk_06[func_081075D8()] > 0) {
                    break;
                }
            }
        } else if (keys & 0x80) {
            for (i = 0; i <= 4; i++) {
                if (++gUnk_02035FC6 > 4) {
                    gUnk_02035FC6 = 0;
                }

                if (p->unk_06[func_081075D8()] > 0) {
                    break;
                }
            }
        }
    }

    if (gUnk_02035FC4 != a || gUnk_02035FC6 != b) {
        m4aSongNumStart(0x65);
    }
}
#else
INCLUDE_ASM("mode_ms2/func_08108208.s");
#endif

void func_081083EC(void) {
    UnkStruct_0810718C* p;
    s16 old;
    u16 keys;

    p = func_0810718C();
    old = gUnk_02035FC8;
    keys = func_08107D24();
    if (keys & 1) {
        gUnk_02035FDC = gUnk_02035FC4 * 12288 + 0x9200;
        gUnk_02035FE0 = gUnk_02035FC6 * 2048 + 0x1000;
        AnimStart(&gUnk_02035E58, 0, 1);
        DisableBg(2);

        if (gUnk_02035FC8 == 0) {
            func_08107938();
            m4aSongNumStart(0x8A);

            if (func_081079A8(p)) {
                func_08107A74(p);

                if (func_08107220(gUnk_02035E2E) > 0) {
                    AnimStart(&gUnk_02035E80, 0, 1);
                    gUnk_02035E2C = 0;
                } else {
                    gUnk_02035E2C = 1;
                }
            } else {
                if (func_081079E4(p)) {
                    func_08107A08(p);
                }
                AnimStart(&gUnk_02035E80, 1, 1);
                gUnk_02035E2C = 2;
            }
        } else {
            m4aSongNumStart(0x68);
            AnimStart(&gUnk_02035E80, 1, 1);
            gUnk_02035E2C = 2;
        }
    } else if (keys & 2) {
        gUnk_02035FDC = gUnk_02035FC4 * 12288 + 0x9200;
        gUnk_02035FE0 = gUnk_02035FC6 * 2048 + 0x1000;
        AnimStart(&gUnk_02035E58, 0, 1);
        DisableBg(2);
        m4aSongNumStart(0x68);
        AnimStart(&gUnk_02035E80, 1, 1);
        gUnk_02035E2C = 2;
    } else if (keys & 8) {
        LoadBgMap(0, gUnk_09A3439C, 0x500);
        m4aSongNumStart(0x68);
        gUnk_02035FE4 = 0;
        func_08006184(0, 16);
        gUnk_02035FCA = 5;
    } else if (keys & 0x20) {
        gUnk_02035FC8 = 0;
    } else if (keys & 0x10) {
        gUnk_02035FC8 = 1;
    }

    if (gUnk_02035FC8 != old) {
        m4aSongNumStart(0x65);
    }
}

void func_081085E8(void) {
    u16 keys;

    keys = func_08107D24();
    if (keys & 3) {
        DisableBg(2);
        m4aSongNumStart(0x68);
        gUnk_02035E2C = 2;
    } else if (keys & 8) {
        LoadBgMap(0, gUnk_09A3439C, 0x500);
        m4aSongNumStart(0x68);
        gUnk_02035FE4 = 0;
        func_08006184(0, 16);
        gUnk_02035FCA = 5;
    }
}

#ifndef VERSION_JP
void func_08108650(void) {
    s32 i;
    s32 j;
    s16 n;
    s16 t;
    void* anim;

    if (gUnk_02035FCA != 2) {
        DrawSprite(gUnk_02035FD8 >> 8, 0, gUnk_0999D9CA, gUnk_02035E50, gUnk_02035E4C, 0, 0xC00, 0xBB8);
        DrawSprite(128, gUnk_02035FD0[0] >> 8, gUnk_0999D9E6, gUnk_02035E50, gUnk_02035E4C, 0, 0xC00, 0xBB9);
        DrawSprite(128, gUnk_02035FD0[1] >> 8, gUnk_0999DA1A, gUnk_02035E50, gUnk_02035E4C, 0, 0xC00, 0xBB9);
    }
    n = (func_08107220(gUnk_02035E2E) + 2) / 3 - 4;
    if (gUnk_02035E9C <= n) {
        t = 84 * gUnk_02035E9C / n;
    } else {
        t = 0;
    }
    DrawSprite(72, t + 40, gUnk_0999D9C0, gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x898);

    if (gUnk_02035FCA == 2) {
        switch (gUnk_02035E2C) {
        case 1:
            func_0805F1C0(&gUnk_02035FDC, gUnk_09EF9618[gUnk_02035E2E].unk_04 * 3584 - 256);
            func_0805F1C0(&gUnk_02035FE0, 0);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x7D0);
            break;
        case 0:
            func_0805F1C0(&gUnk_02035FDC, (gUnk_02035E98 * 23 - 2) * 256);
            func_0805F1C0(&gUnk_02035FE0, (gUnk_02035E9A * 26 + 16) * 256);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x7D0);
            DrawSprite(gUnk_02035E98 * 23 - 3, gUnk_02035E9A * 26 + 28, AnimUpdate(&gUnk_02035E80), gUnk_02035E78, gUnk_02035E74, 0, 0x800, 0x7DA);
            break;
        case 2:
            func_0810718C();
            func_0805F1C0(&gUnk_02035FDC, gUnk_02035FC4 * 12288 + 0x9200);
            func_0805F1C0(&gUnk_02035FE0, gUnk_02035FC6 * 2048 + 0x1000);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x7D0);
            DrawSprite(gUnk_02035FC4 * 48 + 133, gUnk_02035FC6 * 8 + 35, AnimUpdate(&gUnk_02035E80), gUnk_02035E78, gUnk_02035E74, 0, 0x800, 0x7DA);
            break;
        case 3:
            func_0805F1C0(&gUnk_02035FDC, gUnk_02035FC8 == 0 ? 0x3400 : 0x7400);
            func_0805F1C0(&gUnk_02035FE0, 0x5000);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0, 0);

            if (gUnk_02035FA8 != 0) {
                func_080664D8(120 - func_08065B08(gUnk_02035FA4, gUnk_02035FA8) / 2, 64, gUnk_02035FA4, gUnk_02035E4C, 1, gUnk_02035FA8);
            }

            if (gUnk_02035FB0 != 0) {
                func_080664D8(80, 84, gUnk_02035FAC, gUnk_02035E4C, 1, gUnk_02035FB0);
            }

            if (gUnk_02035FB8 != 0) {
                func_080664D8(144, 84, gUnk_02035FB4, gUnk_02035E4C, 1, gUnk_02035FB8);
            }
            break;
        case 4:
            if (gUnk_02035FC0 != 0) {
                func_080664D8(120 - func_08065B08(gUnk_02035FBC, gUnk_02035FC0) / 2, 68, gUnk_02035FBC, gUnk_02035E4C, 1, gUnk_02035FC0);
            }
            break;
        }
    }
    anim = AnimUpdate(&gUnk_02035F78);

    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 2; j++) {
            if (gUnk_02035F00[i][j] != 0) {
                DrawSprite(j * 23 + 13, i * 26 + 47, gUnk_02035F00[i][j], gUnk_02035ED0[i][j], gUnk_02035EA0[i][j], 0, 0x800, 0x83E);

                if (gUnk_02035F30[i][j] != 0) {
                    DrawSprite(j * 23 + 13, i * 26 + 47, anim, gUnk_02035F70, gUnk_02035F48, 0, 0x800, 0x834);
                }
            }
        }
    }

    if (gUnk_02035E2C != 1) {
        if (gUnk_02035F44 != 0) {
            DrawSprite(112, 56, gUnk_02035F44, gUnk_02035F40, gUnk_02035F3C, 0, 0x800, 0x848);
        }

        if (gUnk_02035F50 != 0) {
            DrawSprite(112, 56, gUnk_02035F50, gUnk_02035F4C, gUnk_02035F48, 0, 0x800, 0x83E);

            if (gUnk_02035F90 != 0) {
                DrawSprite(112, 56, AnimUpdate(&gUnk_02035F58), gUnk_02035F54, gUnk_02035F48, 0, 0x800, 0x834);
            }
        }

        if (gUnk_02035F98 != 0) {
            if (gUnk_02035E2C != 3) {
                if (gUnk_02035E2C != 4) {
                    func_080664D8(96, 92, gUnk_02035F94, gUnk_02035E74, 1, gUnk_02035F98);
                }
            }
        }

        if (gUnk_02035FA0 != 0) {
            func_080664D8(95, 107, gUnk_02035F9C, gUnk_02035E4C, 1, gUnk_02035FA0);
        }
    }
}
#else
INCLUDE_ASM("mode_ms2/func_08108650.s");
#endif
