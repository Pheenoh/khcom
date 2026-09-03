#include "macros.h"
#include "mode_mapinspect.h"

s16 gUnk_02035FC4;
s16 gUnk_02035FC6;
s16 gUnk_02035FC8;
s16 gUnk_02035FCA;
s16 gUnk_02035FCC;
#ifdef VERSION_JP
u32 gUnkJp_02035F3C;
#endif
s32 gUnk_02035FD0[2];
s32 gUnk_02035FD8;
s32 gUnk_02035FDC;
s32 gUnk_02035FE0;
u8 gUnk_02035FE4;

#ifdef NON_MATCHING

void mode_mapinspect_0(void) {
    s16 i;
    s16 j;

    gUnk_02035E28 = EwramAlloc(0x2F4);
    func_08001F98();
    func_08006120(0, 16);
    func_08004DB0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 2, 30, 15);
    SetupBg(3, 0, 31, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    func_08107B84();
    gUnk_02035FCA = 0;
    gUnk_02035FCC = 16;
    gUnk_02035FD0[0] = -0x800;
    gUnk_02035FD0[1] = 0xA800;
    gUnk_02035FD8 = -0x8000;
    gUnk_02035E2E = 4;
    gUnk_02035E98 = 0;
    gUnk_02035E9A = 0;
    gUnk_02035E9C = 0;

    if (gUnk_02035E48 > 0) {
        gUnk_02035FDC = -0x200;
        gUnk_02035FE0 = 0x1000;
        gUnk_02035E2C = 0;
    } else {
        gUnk_02035FDC = gUnk_09EF9618[4].unk_04 * 7 * 512 - 0x100;
        gUnk_02035FE0 = 0;
        gUnk_02035E2C = 1;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            gUnk_02035EA0[i][j] = 0;
            gUnk_02035ED0[i][j] = 0;
            gUnk_02035F00[i][j] = 0;
            gUnk_02035F30[i][j] = 0;
        }
    }

    gUnk_02035F3C = 0;
    gUnk_02035F40 = 0;
    gUnk_02035F44 = 0;
    gUnk_02035F48 = 0;
    gUnk_02035F4C = 0;
    gUnk_02035F50 = 0;
    gUnk_02035F90 = 0;
    gUnk_02035E74 = 0;
    gUnk_02035FC4 = 0;
    gUnk_02035FC6 = 0;
    LoadBgPalette(0, gUnk_09A3D0DC, 0x160);
    LoadBgTiles(0, gUnk_09A03CFC, 0x2980);
    LoadBgPalette(2, gUnk_09611AB8, 0x20);
    LoadBgTiles(2, gUnk_099597E4, 0x140);
    LoadBgMap(2, gUnk_09985F44, 0x800);
    LoadBgMap(0, gUnk_09A3439C, 0x500);

    if (func_0810718C()->unk_04 == 3) {
        LoadBgMap(1, gUnk_09A3551C, 0x500);
    } else {
        LoadBgMap(1, gUnk_09A3501C, 0x500);
    }

    func_081078F0(gUnk_02035E2E);
    func_081075FC();
    func_0810764C();
    func_081076D4();
    gUnk_02035E4C = LoadObjPalette(gUnk_09A3D2DC, 0x20);
    gUnk_02035E50 = LoadObjTiles(gUnk_0999DAEC, 0xAC0);
    AnimInit(&gUnk_02035E58, gUnk_09EF981C, gUnk_09EF97EC);
    AnimStart(&gUnk_02035E58, 0, 1);
    gUnk_02035E78 = LoadObjTiles(gUnk_0999E69E, 0xD60);
    AnimInit(&gUnk_02035E80, gUnk_09EF9858, gUnk_09EF9830);
    AnimStart(&gUnk_02035E80, 0, 1);
    gUnk_02035E70 = LoadObjPalette(gUnk_09A3D2DC, 0x20);
    gUnk_02035F54 = LoadObjTiles(gUnk_0908B1B4, 0x9A0);
    AnimInit(&gUnk_02035F58, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&gUnk_02035F58, 0, 1);
    gUnk_02035F70 = LoadObjTiles(gUnk_0908C3CE, 0x260);
    AnimInit(&gUnk_02035F78, gUnk_09EEA198, gUnk_09EEA180);
    AnimStart(&gUnk_02035F78, 0, 1);

    gUnk_02035F94 = EwramAlloc(0x120);
    func_08065ACC(gUnk_02035F94, 0x24);
    gUnk_02035F9C = EwramAlloc(0x2D0);
    func_08065ACC(gUnk_02035F9C, 0x5A);

    gUnk_02035FAA = func_08065B54(gUnk_08159FBC);
    gUnk_02035FA4 = EwramAlloc(gUnk_02035FAA * 8);
    func_08065ACC(gUnk_02035FA4, gUnk_02035FAA);
    gUnk_02035FA8 = func_08065B6C(gUnk_08159FBC, gUnk_02035FA4);

    gUnk_02035FB2 = func_08065B54(gUnk_08159E10);
    gUnk_02035FAC = EwramAlloc(gUnk_02035FB2 * 8);
    func_08065ACC(gUnk_02035FAC, gUnk_02035FB2);
    gUnk_02035FB0 = func_08065B6C(gUnk_08159E10, gUnk_02035FAC);

    gUnk_02035FBA = func_08065B54(gUnk_08159E18);
    gUnk_02035FB4 = EwramAlloc(gUnk_02035FBA * 8);
    func_08065ACC(gUnk_02035FB4, gUnk_02035FBA);
    gUnk_02035FB8 = func_08065B6C(gUnk_08159E18, gUnk_02035FB4);

    gUnk_02035FC2[0] = func_08065B54(gUnk_0815C136);
    gUnk_02035FBC[0] = EwramAlloc(gUnk_02035FC2[0] * 8);
    func_08065ACC(gUnk_02035FBC[0], gUnk_02035FC2[0]);
    gUnk_02035FC0 = func_08065B6C(gUnk_0815C136, gUnk_02035FBC[0]);

    func_08107280();
    func_081073F0();
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}
#else
INCLUDE_ASM("mode_mapinspect/mode_mapinspect_0.s");
#endif

void mode_mapinspect_1(void) {
    UpdatePlayTime();

    switch (gUnk_02035FCA) {
    case 0:
        ApproachValue(&gUnk_02035FD0[0], 0, gUnk_02035FCC);
        ApproachValue(&gUnk_02035FD0[1], 0x9800, gUnk_02035FCC);
        gUnk_02035FCC--;
        if (gUnk_02035FCC <= 0) {
            gUnk_02035FCC = 16;
            gUnk_02035FCA = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_02035FD8, 0, gUnk_02035FCC);
        gUnk_02035FCC--;
        if (gUnk_02035FCC <= 0) {
            LoadBgMap(0, gUnk_09A3489C, 0x500);
            gUnk_02035FCA = 2;
        }
        break;
    case 2:
        switch (gUnk_02035E2C) {
        case 0:
            func_08107D44();
            break;
        case 1:
            func_08107FF0();
            break;
        case 2:
            func_08108208();
            break;
        case 3:
            func_081083EC();
            break;
        case 4:
            func_081085E8();
            break;
        }
        break;
    case 3:
        ApproachValue(&gUnk_02035FD8, -0x8000, gUnk_02035FCC);
        gUnk_02035FCC--;
        if (gUnk_02035FCC <= 0) {
            gUnk_02035FCC = 16;
            gUnk_02035FCA = 4;
        }
        break;
    case 4:
        ApproachValue(&gUnk_02035FD0[0], -0x800, gUnk_02035FCC);
        ApproachValue(&gUnk_02035FD0[1], 0xA800, gUnk_02035FCC);
        gUnk_02035FCC--;
        if (gUnk_02035FCC <= 0) {
            func_08006184(0, 16);
            gUnk_02035FCA = 5;
        }
        break;
    case 5:
        if (!func_08006314()) {
            func_080E052C(gUnk_02035FE4);
        }
        break;
    }

    func_08108650();
}

#ifndef VERSION_JP
void mode_mapinspect_2(void) {
    s32 i;
    s32 j;

    ReleaseObjPalette(gUnk_02035E4C);
    ReleaseObjTiles(gUnk_02035E50);
    ReleaseObjTiles(gUnk_02035E78);
    ReleaseObjPalette(gUnk_02035E70);
    ReleaseObjTiles(gUnk_02035F54);
    ReleaseObjTiles(gUnk_02035F70);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (gUnk_02035EA0[i][j] != 0) {
                ReleaseObjPalette(gUnk_02035EA0[i][j]);
            }

            if (gUnk_02035ED0[i][j] != 0) {
                ReleaseObjTiles(gUnk_02035ED0[i][j]);
            }
        }
    }

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

    func_08065AE0(gUnk_02035F94, 0x24);
    EwramFree(gUnk_02035F94);
    func_08065AE0(gUnk_02035F9C, 0x5A);
    EwramFree(gUnk_02035F9C);
    func_08065AE0(gUnk_02035FA4, gUnk_02035FAA);
    EwramFree(gUnk_02035FA4);
    func_08065AE0(gUnk_02035FAC, gUnk_02035FB2);
    EwramFree(gUnk_02035FAC);
    func_08065AE0(gUnk_02035FB4, gUnk_02035FBA);
    EwramFree(gUnk_02035FB4);

    for (i = 0; i < 1; i++) {
        func_08065AE0(gUnk_02035FBC[i], gUnk_02035FC2[i]);
        EwramFree(gUnk_02035FBC[i]);
    }

    EwramFree(gUnk_02035E28);
}
#else
INCLUDE_ASM("mode_mapinspect/mode_mapinspect_2.s");
#endif
