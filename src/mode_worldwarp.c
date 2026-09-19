#include "localized_resource_data.h"
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "mode_worldwarp.h"

#ifdef VERSION_EU
extern u8 gUnkEu_09A4FBC0[];
extern u8 gUnkEu_09A50BC0[];
extern u8 gUnkEu_09A51BC0[];
extern u8 gUnkEu_09A52BC0[];
extern u8 gUnkEu_09A4F3C0[];
extern u8 gUnkEu_09A503C0[];
extern u8 gUnkEu_09A513C0[];
extern u8 gUnkEu_09A523C0[];
extern u8 gUnkEu_09A4CCC0[];
extern u8 gUnkEu_09A4BFC0[];
extern u8 gUnkEu_09A4E6C0[];
extern u8 gUnkEu_09A4D9C0[];
extern u8 gUnkEu_09A56780[];
extern u8 gUnkEu_09A53380[];
extern u8 gUnkEu_09A5CF80[];
extern u8 gUnkEu_09A59B80[];
extern u8 gUnkEu_09A57480[];
extern u8 gUnkEu_09A54080[];
extern u8 gUnkEu_09A5DC80[];
extern u8 gUnkEu_09A5A880[];
extern u8 gUnkEu_09A58180[];
extern u8 gUnkEu_09A54D80[];
extern u8 gUnkEu_09A5E980[];
extern u8 gUnkEu_09A5B580[];
extern u8 gUnkEu_09A58E80[];
extern u8 gUnkEu_09A55A80[];
extern u8 gUnkEu_09A5F680[];
extern u8 gUnkEu_09A5C280[];
extern u8 gUnkEu_099AAC2C[];
extern u8 gUnkEu_099ABA18[];
extern u8 gUnkEu_099ABFA0[];
extern u8 gUnkEu_099AC468[];
extern u8 gUnkEu_099AC9F0[];
#endif

s16 gUnk_020354E8;
s16 gUnk_020354EA;
u8 gUnk_020354EC[4];
s16 gUnk_020354F0[13];
s16 gUnk_0203550A;
void* gUnk_0203550C;
struct ObjTiles* gUnk_02035510;
struct ObjPalette* gUnk_02035514;
struct ObjTiles* gUnk_02035518;
struct ObjPalette* gUnk_0203551C;
AnimState gUnk_02035520;
AnimState gUnk_02035538;
struct ObjTiles* gUnk_02035550;
struct ObjPalette* gUnk_02035554;
AnimState gUnk_02035558;
void* gUnk_02035570[14];
void* gUnk_020355A8[14];
void* gUnk_020355E0[14];
u8 gUnk_02035618[192];
#ifdef VERSION_EU
u8 gUnkEu_02035B68[0xC0];
#endif
u8 gUnk_020356D8;
u8 gUnk_020356D9[7];
u8 gUnk_020356E0[192];
#ifdef VERSION_EU
u8 gUnkEu_02035CF0[0xC0];
#endif
u8 gUnk_020357A0;
s16 gUnk_020357A2;
s16 gUnk_020357A4;
s32 gUnk_020357A8[2];
s32 gUnk_020357B0;
s32 gUnk_020357B4;
s32 gUnk_020357B8;

void mode_worldwarp_0(void) {
    s32 i;
    void** p;
    vu32* dma;

    gUnk_020354EA = func_080DF750() + 1;
    p = &gUnk_0203550C;
    *p = EwramAlloc(0x500);
    SpriteReset();
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 30, 0);
    SetupBg(3, 0, 31, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    gUnk_020354E8 = gGameState.floor;
    gUnk_0203550A = -1;

    for (i = 0; i <= 12; i++) {
        if (i < gUnk_020354EA) {
            gUnk_020354F0[i] = gGameState.floors[i].world;
        } else {
            gUnk_020354F0[i] |= 0xFFFFu;
        }
    }

    gUnk_020357A2 = 0;
    gUnk_020357A4 = 16;
    gUnk_020357A8[0] = -0x800;
    gUnk_020357A8[1] = 0xA800;
    gUnk_020357B0 = -0x8000;
    gUnk_020357B4 = (gUnk_09EF9384[gUnk_020354E8].x << 11) + 0x2000;
    gUnk_020357B8 = (gUnk_09EF9384[gUnk_020354E8].y << 11) - 0x600;
    LoadBgPalette(0, gUnk_09A3D37C, 0x200);

    for (i = 0; i <= 12; i++) {
        if (gUnk_020354F0[i] > 0) {
            gUnk_020355A8[i] = LoadObjPalette(gUnk_09EF9488[gUnk_020354F0[i]].palette, gUnk_09EF9488[gUnk_020354F0[i]].paletteSize);
            gUnk_02035570[i] = LoadObjTiles(gUnk_09EF9488[gUnk_020354F0[i]].tiles, gUnk_09EF9488[gUnk_020354F0[i]].tilesSize);
            gUnk_020355E0[i] = gUnk_09EF9488[gUnk_020354F0[i]].sprite;
        } else {
            gUnk_020355A8[i] = 0;
            gUnk_02035570[i] = 0;
            gUnk_020355E0[i] = 0;
        }
    }

    LoadBgTiles(0, gUnk_09A06A7C, 0x6BC0);
#ifdef VERSION_EU
    if (gGameState.flags & 8) {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A4FBC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A50BC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A51BC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A52BC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        }
    } else {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A4F3C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A503C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A513C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A523C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        }
    }
#endif

    LoadBgMap(0, gUnk_09A35A1C, 0x500);
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)gUnk_09A3641C;
    dma[1] = (u32)gUnk_0203550C;
    dma[2] = 0x80000280;
    dma[2];

    for (i = 0; i <= 12; i++) {
        if (gUnk_020354F0[i] >= 0) {
            func_0810057C(7, 4, gUnk_09A3691C, 0, 0, gUnk_0203550C, gUnk_09EF9384[i].x, gUnk_09EF9384[i].y);
        }
    }

    for (i = 0; i < gUnk_020354EA - 1; i++) {
        if (gUnk_020354F0[i] >= 0 && gUnk_020354F0[i + 1] >= 0) {
            func_0810057C(gUnk_099930E8[gUnk_09EF9384[i].rect].width, gUnk_099930E8[gUnk_09EF9384[i].rect].height,
                gUnk_09A3691C, gUnk_099930E8[gUnk_09EF9384[i].rect].x,
                gUnk_099930E8[gUnk_09EF9384[i].rect].y, gUnk_0203550C,
                gUnk_09EF9384[i].x2, gUnk_09EF9384[i].y2);
        }
    }

    for (i = 0; i < gUnk_020354EA; i++) {
        if (gUnk_020354F0[i] >= 0) {
            if ((gGameState.flags & 8) == 0) {
                if (i <= 8) {
                    func_0810057C(3, 1, gUnk_09A3691C, i * 3, 9, gUnk_0203550C,
                        gUnk_09EF9384[i].x + 3, gUnk_09EF9384[i].y + 2);
                } else {
                    func_0810057C(4, 1, gUnk_09A3691C, (i - 9) * 4, 10, gUnk_0203550C,
                        gUnk_09EF9384[i].x + 3, gUnk_09EF9384[i].y + 2);
                }
            } else if (i <= 2) {
                func_0810057C(4, 1, gUnk_09A3691C, i * 4, 21, gUnk_0203550C,
                    gUnk_09EF9384[i].x + 3, gUnk_09EF9384[i].y + 2);
            } else {
                func_0810057C(3, 1, gUnk_09A3691C, (i - 3) * 3, 22, gUnk_0203550C,
                    gUnk_09EF9384[i].x + 3, gUnk_09EF9384[i].y + 2);
            }
        }
    }

    for (i = 0; i < gUnk_020354EA; i++) {
        if (gUnk_020354E8 == i) {
            func_081004EC(3, 7, 4, gUnk_0203550C, gUnk_09EF9384[i].x, gUnk_09EF9384[i].y);
        } else {
            func_081004EC(2, 7, 4, gUnk_0203550C, gUnk_09EF9384[i].x, gUnk_09EF9384[i].y);
        }
    }

    LoadBgMap(1, gUnk_0203550C, 0x500);

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A4CCC0, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A4BFC0, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A4E6C0, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A4D9C0, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 1:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A56780, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A53380, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5CF80, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A59B80, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 4:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A57480, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A54080, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5DC80, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A5A880, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 3:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A58180, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A54D80, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5E980, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A5B580, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 2:
    default:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A58E80, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A55A80, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5F680, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnkEu_09A5C280, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    }
#else
    if ((gGameState.flags & 8) == 0) {
        func_08100670(gGameState.floor, gUnk_09A0E33C, (u8*)GetBgCharBase(0) + 0x120);
        func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
    } else {
        func_08100670(gGameState.floor, gUnk_09A0FD3C, (u8*)GetBgCharBase(0) + 0x120);
        func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
    }
#endif
    gUnk_02035514 = LoadObjPalette(gUnk_09A3D57C, 32);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099AAC2C, 0x500);
        break;
    case 1:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099ABA18, 0x500);
        break;
    case 4:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099ABFA0, 0x440);
        break;
    case 3:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099AC468, 0x500);
        break;
    case 2:
    default:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099AC9F0, 0x500);
        break;
    }
#else
    gUnk_02035510 = LoadObjTiles(gUnk_0999F488, 0x500);
#endif
    gUnk_0203551C = LoadObjPalette(gUnk_09A3D59C, 32);
    gUnk_02035518 = LoadObjTiles(gUnk_0999FA20, 0x680);
    AnimInit(&gUnk_02035520, gUnk_09EF9898, gUnk_09EF9870);
    AnimStart(&gUnk_02035520, 0, 1);
    AnimInit(&gUnk_02035538, gUnk_09EF9898, gUnk_09EF9870);
    AnimStart(&gUnk_02035538, 1, 1);
    gUnk_02035554 = LoadObjPalette(gUnk_09A3D5BC, 32);
    gUnk_02035550 = LoadObjTiles(gUnk_099A012C, 192);
    AnimInit(&gUnk_02035558, gUnk_09EF98B0, gUnk_09EF98A0);
    AnimStart(&gUnk_02035558, 0, 1);
#ifdef VERSION_EU
    InitTextSlots(gUnk_02035618, 48);
    InitTextSlots(gUnk_020356E0, 48);
#else
    InitTextSlots(gUnk_02035618, 24);
    InitTextSlots(gUnk_020356E0, 24);
#endif
    gUnk_020356D8 = func_08100608(gUnk_020354F0[gGameState.floor]);
    gUnk_020357A0 = func_0810063C(gUnk_020354F0[gUnk_020354E8]);
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}

void mode_worldwarp_1(void) {
    UpdatePlayTime();

    switch (gUnk_020357A2) {
    case 0:
        ApproachValue(&gUnk_020357A8[0], 0, gUnk_020357A4);
        ApproachValue(&gUnk_020357A8[1], 0x9800, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020357B0, 0, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            LoadBgMap(0, gUnk_09A35F1C, 0x500);
            gUnk_020357A2 = 2;
        }
        break;
    case 2:
        func_081006AC();
        break;
    case 3:
        ApproachValue(&gUnk_020357B0, -0x8000, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 4;
        }
        break;
    case 4:
        ApproachValue(&gUnk_020357A8[0], -0x800, gUnk_020357A4);
        ApproachValue(&gUnk_020357A8[1], 0xA800, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            FadeStartOut(0, 16);
            gUnk_020357A2 = 5;
        }
        break;
    case 5:
        if (!FadeIsActive()) {
            if (gUnk_0203550A >= 0) {
                func_080DF9E0(gUnk_0203550A);
            } else {
                func_080E04EC();
            }
        }
        break;
    }
    func_08100980();
}

void mode_worldwarp_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_02035514);
    ReleaseObjTiles(gUnk_02035510);
    ReleaseObjPalette(gUnk_0203551C);
    ReleaseObjTiles(gUnk_02035518);
    ReleaseObjPalette(gUnk_02035554);
    ReleaseObjTiles(gUnk_02035550);

    for (i = 0; i <= 12; i++) {
        if (gUnk_020355A8[i] != 0) {
            ReleaseObjPalette(gUnk_020355A8[i]);
        }

        if (gUnk_02035570[i] != 0) {
            ReleaseObjTiles(gUnk_02035570[i]);
        }
    }
#ifdef VERSION_EU
    FreeTextSlots(gUnk_02035618, 48);
#else
    FreeTextSlots(gUnk_02035618, 24);
#endif
#ifdef VERSION_EU
    FreeTextSlots(gUnk_020356E0, 48);
#else
    FreeTextSlots(gUnk_020356E0, 24);
#endif
    EwramFree(gUnk_0203550C);
}

const char gModeNameWorldwarp[] = "mode_worldwarp";

Mode gModeWorldwarp = {
    gModeNameWorldwarp,
    (void (*)(s32))mode_worldwarp_0,
    (void (*)(void))mode_worldwarp_1,
    (void (*)(void))mode_worldwarp_2,
};
