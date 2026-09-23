#include "localized_resource_assets.h"
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "text.h"
#include "monsgage.h"
#include "mode_mapinspect.h"
#include "gba/keys.h"
#include "sprites_card.h"
#include "sprites_worldinspect.h"
#include "sprites_map.h"
#include "sprites_card_pictures.h"

#ifdef VERSION_EU
extern u8 gUnkEu_08890EC0[];
extern u8 gUnkEu_08890E1C[];
extern u8 gUnkEu_08890E44[];
extern u8 gUnkEu_08895CF8[];
#endif

#ifdef VERSION_JP
extern u8 gUnk_0814FBB0[];
extern u8 gUnk_0814FBBC[];
#endif

#ifdef VERSION_EU
void* gUnkEu_09F85008[5] = {
    gUnk_0999D9C0,
    gUnkEu_099A6BA8,
    gUnkEu_099A9128,
    gUnkEu_099A84A8,
    gUnkEu_099A7828,
};

void* gUnkEu_09F8501C[5] = {
    gUnk_0999D9CA,
    gUnkEu_099A6BB2,
    gUnkEu_099A9132,
    gUnkEu_099A84B2,
    gUnkEu_099A7832,
};

void* gUnkEu_09F85030[5] = {
    gUnk_0999D9E6,
    gUnkEu_099A6BC8,
    gUnkEu_099A9148,
    gUnkEu_099A84C8,
    gUnkEu_099A7848,
};

void* gUnkEu_09F85044[5] = {
    gUnk_0999DA1A,
    gUnkEu_099A6BFC,
    gUnkEu_099A917C,
    gUnkEu_099A84FC,
    gUnkEu_099A787C,
};

void* gUnkEu_09F85058[5] = {
    gUnkEu_099A6090,
    gUnkEu_099A6CCE,
    gUnkEu_099A924E,
    gUnkEu_099A85CE,
    gUnkEu_099A794E,
};

AnimHeader** gUnkEu_09F8506C[5] = {
    gUnk_09EF981C,
    gUnkEu_09F8533C,
    gUnkEu_09F85408,
    gUnkEu_09F853C4,
    gUnkEu_09F85380,
};

void** gUnkEu_09F85080[5] = {
    gUnk_09EF97EC,
    gUnkEu_09F8530C,
    gUnkEu_09F853D8,
    gUnkEu_09F85394,
    gUnkEu_09F85350,
};
#endif

MapCardCategoryDef gMapCardCategoryDefs[5] = {
    {4, 1, 1, 0},
    {0, 2, 2, 0},
    {1, 3, 3, 0},
    {2, 65535, 4, 0},
    {65535, 0, 0, 0},
};

#ifdef VERSION_EU
const u16 gUnkEu_09999A50[5] = {2752, 2816, 2816, 2816, 2816};
#endif

const u16 gUnk_099937A0[4] = {2, 1, 3, 4};

MapCardInventoryEntry* gMapCardInventoryEntries;
s16 gUnk_02035E2C;
s16 gUnk_02035E2E;
u16 gUnk_02035E30[4] __attribute__((aligned(8)));
u16 gUnk_02035E38[4];
s16 gUnk_02035E40[4];
s16 gUnk_02035E48;
struct ObjPalette* gUnk_02035E4C;
struct ObjTiles* gUnk_02035E50;
u32 gUnk_02035E54;
AnimState gUnk_02035E58;
struct ObjPalette* gUnk_02035E70;
struct ObjPalette* gUnk_02035E74;
struct ObjTiles* gUnk_02035E78;
u32 gUnk_02035E7C;
AnimState gUnk_02035E80;
s16 gUnk_02035E98;
s16 gUnk_02035E9A;
s16 gUnk_02035E9C;
void* gUnk_02035EA0[4][3];
void* gUnk_02035ED0[4][3];
void* gUnk_02035F00[4][3];
u8 gUnk_02035F30[4][3];
struct ObjPalette* gUnk_02035F3C;
struct ObjTiles* gUnk_02035F40;
void* gUnk_02035F44;
struct ObjPalette* gUnk_02035F48;
struct ObjTiles* gUnk_02035F4C;
void* gUnk_02035F50;
struct ObjTiles* gUnk_02035F54;
AnimState gUnk_02035F58;
struct ObjTiles* gUnk_02035F70;
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
#ifdef VERSION_JP
u32 gUnkJp_02035F1C;
#endif
#ifdef VERSION_JP
u8* gUnk_02035FBC[2];
u8 gUnk_02035FC0[2];
u16 gUnkJp_02035F2A;
u16 gUnk_02035FC2[2];
#else
u8* gUnk_02035FBC[1];
u8 gUnk_02035FC0[1];
u16 gUnk_02035FC2[1];
#endif

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

MapCardInventoryEntry* func_0810718C(void) {
    return &gMapCardInventoryEntries[func_0810714C()];
}

void func_081071AC(void) {
    MapCardInventoryEntry* p;
    s16 i;

    p = func_0810718C();
    if (p->cardType <= 26) {
        for (i = 0; i < 10; i++) {
            if (p->countsByValue[i] > 0) {
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
                idx = gMapCardInventoryEntries[a + k].cardIndex;
                gUnk_02035EA0[i][j] = LoadObjPalette(gUnk_09EE4C80[idx].palette2, 32);
                gUnk_02035ED0[i][j] = LoadObjTiles(gUnk_09EE4C80[idx].tiles2, gUnk_09EE4C80[idx].tilesSize2);
                gUnk_02035F00[i][j] = *gUnk_09EE4C80[idx].sprites2;
                gUnk_02035F30[i][j] = gMapCardInventoryEntries[a + k].category == 3;
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
    MapCardInventoryEntry* p;
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

    if (p->cardType <= 26 && func_08107220(gUnk_02035E2E) > 0) {
        idx = p->cardIndex;
        k = gUnk_099937A0[p->category];
        gUnk_02035F3C = LoadObjPalette(gUnk_09EE4C80[idx].palette, gUnk_09EE4C80[idx].paletteSize);
        gUnk_02035F40 = LoadObjTiles(gUnk_09EE4C80[idx].tiles, gUnk_09EE4C80[idx].tilesSize);
        gUnk_02035F44 = *gUnk_09EE4C80[idx].sprites;
        gUnk_02035F48 = LoadObjPalette(gUnk_09EE4BF4[k].palette, gUnk_09EE4BF4[k].paletteSize);
        gUnk_02035F4C = LoadObjTiles(gUnk_09EE4BF4[k].tiles, gUnk_09EE4BF4[k].tilesSize);
        gUnk_02035F50 = *gUnk_09EE4BF4[k].sprites;
        gUnk_02035F90 = p->category == 3;
        gUnk_02035E74 = LoadObjPalette(gUnk_09A3D2FC + p->category * 32, 32);
        q = &gUnk_02035F98;
        *q = LoadTextSlots(func_08093C18(p->cardType), gUnk_02035F94);
#ifdef VERSION_EU
        {
            u8** strings = gUnk_09EE90D0[p->cardType]->strings;
            q = &gUnk_02035FA0;
            *q = LoadTextSlots((void*)strings[gLanguage], gUnk_02035F9C);
        }
#else
        q = &gUnk_02035FA0;
        *q = LoadTextSlots((void*)gUnk_09EE90D0[p->cardType], gUnk_02035F9C);
#endif
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
    LoadDecimalDigitTiles(gUnk_02035E48, gUnk_09A0693C, (u8*)GetBgCharBase(0) + 0x3A0, 32, 2);
    LoadDecimalDigitTiles(99, gUnk_09A0693C, (u8*)GetBgCharBase(0) + 0x3E0, 32, 2);
}

void func_0810764C(void) {
    s16 i;
    s16 v;

    for (i = 0; i <= 3; i++) {
        v = gUnk_02035E40[i];
        if (v != 0) {
            LoadDecimalDigitTiles(v, gUnk_09A0669C, (u8*)GetBgCharBase(0) + (i * 64 + 0x2A0), 32, 2);
        } else {
            LoadDecimalDigitTiles(0, gUnk_09A0667C, (u8*)GetBgCharBase(0) + (i * 64 + 0x2A0), 32, 2);
        }
    }
}

void func_081076D4(void) {
    MapCardInventoryEntry* p;
    s16 i;
    s32 v;

    p = func_0810718C();

    if (func_08107220(gUnk_02035E2E) > 0) {
        LoadPalette(gUnk_09A3D23C + p->category * 32, (void*)0x05000000, 12);
    }

    if (gUnk_02035E2C == 1) {
        for (i = 0; i <= 9; i++) {
            LoadDecimalDigitTiles(0, gUnk_09A067DC, (u8*)GetBgCharBase(0) + (i * 64 + 0x40), 32, 1);
            LoadPalette(gUnk_09A3D2C8, (void*)(0x05000000 + (i + 6) * 2), 2);
        }
    } else if (p->category == 3) {
        if (func_08107220(gUnk_02035E2E) > 0) {
            LoadBgMap(1, gUnk_09A3551C, 0x500);
        }

        for (i = 0; i <= 9; i++) {
            v = p->countsByValue[i];
            if (v != 0 && func_08107220(gUnk_02035E2E) > 0) {
                LoadDecimalDigitTiles(v, gUnk_09A067FC, (u8*)GetBgCharBase(0) + 0x40, 32, 1);
                LoadPalette(gUnk_09A3D248, (void*)0x0500000C, 2);
                break;
            }
        }

        if (i > 9) {
            LoadDecimalDigitTiles(0, gUnk_09A067DC, (u8*)GetBgCharBase(0) + 0x40, 32, 1);
            LoadPalette(gUnk_09A3D2C8, (void*)0x0500000C, 2);
        }
    } else {
        if (func_08107220(gUnk_02035E2E) > 0) {
            LoadBgMap(1, gUnk_09A3501C, 0x500);
        }

        for (i = 0; i <= 9; i++) {
            v = p->countsByValue[i];
            if (v != 0 && func_08107220(gUnk_02035E2E) > 0) {
                LoadDecimalDigitTiles(v, gUnk_09A067FC, (u8*)GetBgCharBase(0) + (i * 64 + 0x40), 32, 1);
                LoadPalette(gUnk_09A3D248, (void*)(0x05000000 + (i + 6) * 2), 2);
            } else {
                LoadDecimalDigitTiles(0, gUnk_09A067DC, (u8*)GetBgCharBase(0) + (i * 64 + 0x40), 32, 1);
                LoadPalette(gUnk_09A3D2C8, (void*)(0x05000000 + (i + 6) * 2), 2);
            }
        }
    }
}

void func_081078F0(s16 a) {
    RequestTilemapRectCopy(gUnk_09A34D9C, GetBgScreenBase(0), 0, gMapCardCategoryDefs[a].displayIndex * 2, 0, 2, 11, 2);
}

void func_08107938(void) {
    MapCardInventoryEntry* p;
    u16 card;

    p = func_0810718C();
    if (p->countsByValue[func_081075D8()] > 0) {
        card = func_081075D8() + p->cardIndex;
        gUnk_02035E40[p->category]--;
        gUnk_02035E48--;
        p->countsByValue[func_081075D8()]--;
        RemoveMapCard(card);
        func_081075FC();
        func_081076D4();
        func_0810764C();
    }
}

u8 func_081079A8(MapCardInventoryEntry* p) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (p->countsByValue[i] > 0) {
            break;
        }
    }

    if (i > 9) {
        return 1;
    }
    return 0;
}

u8 func_081079E4(MapCardInventoryEntry* p) {
    if (p->countsByValue[func_081075D8()] == 0) {
        return 1;
    }
    return 0;
}

void func_08107A08(MapCardInventoryEntry* p) {
    s16 k;
    s16 i;

    k = func_081075D8();

    for (i = 0; i <= 9; i++) {
        if (p->countsByValue[k] > 0) {
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

void func_08107A74(MapCardInventoryEntry* p) {
    vu32* dma;
    vu16 zero;
    MapCardInventoryEntry* q;
    u16 row;
    s16 j;

    row = p->category;
    dma = (vu32*)REG_ADDR_DMA3;
    dma[0] = (u32)(p + 1);
    dma[1] = (u32)p;
    dma[2] = ((26 - func_0810714C()) * 14) | 0x80000000;
    dma[2];
    zero = 0;
    dma[0] = (u32)&zero;
    q = &gMapCardInventoryEntries[26];
    dma[1] = (u32)q;
    dma[2] = 0x8100000E;
    dma[2];
    q->cardType = 27;

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

void func_08107B84(void) {
    s16* pd;
    vu32* dma;
    vu16 zero;
    s32 w;
    s16 k;
    s16 j;
    s16 i;
    s16 a;
    u16 u;
    u16 n;
    u16 t;

    zero = 0;
    dma = (vu32*)REG_ADDR_DMA3;
    dma[0] = (u32)&zero;
    dma[1] = (u32)gMapCardInventoryEntries;
    dma[2] = 0x8100017A;
    dma[2];

    for (i = 0; i <= 26; i++) {
        gMapCardInventoryEntries[i].cardType = 27;
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

                for (i = 0; i <= 9; i++) {
                    n = gUnk_0203A8C0[(u16)(k * 10 + i)];
                    if (n != 0) {
                        if (t != 4) {
                            gUnk_02035E48 += n;
                        }
                        {
                            s16* counts = gUnk_02035E40;
                            s32 index = a;

                            counts[j] += n;
                            gMapCardInventoryEntries[index].cardType = u;
                            gMapCardInventoryEntries[index].cardIndex = k * 10;
                            gMapCardInventoryEntries[index].category = j;
                            gMapCardInventoryEntries[index].countsByValue[i] = n;
                        }
                    }
                }
            }

            if (gMapCardInventoryEntries[a].cardType <= 26) {
                a++;
            }
        }
        pd = &gUnk_02035E38[j];
        w = gUnk_02035E30[j];
        *pd = a - w;
    }
}

u16 MapInspectReadMenuKeys(void) {
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
    keys = MapInspectReadMenuKeys();
    if (keys & 1) {
        if (func_0810718C()->category != 3) {
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
        FadeStartOut(0, 16);
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
    keys = MapInspectReadMenuKeys();
    if ((keys & 1) == 0) {
        if (keys & 8) {
            LoadBgMap(0, gUnk_09A3439C, 0x500);
            m4aSongNumStart(0x68);
            gUnk_02035FE4 = 0;
            FadeStartOut(0, 16);
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
            gUnk_02035E2E = gMapCardCategoryDefs[gUnk_02035E2E].leftCategory;
        } else if (keys & 0x10) {
            gUnk_02035E2E = gMapCardCategoryDefs[gUnk_02035E2E].rightCategory;
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

void func_08108170(MapCardInventoryEntry* p, u16 row) {
    s16 c;
    s16 i;
    s32 k;

    c = gUnk_02035FC6;

    for (i = 0; i <= 4; i++) {
        k = c - i;
        if (k >= 0 && p->countsByValue[func_081075C0(row, k)] > 0) {
            gUnk_02035FC4 = row;
            gUnk_02035FC6 = k;
            return;
        }
        k = c + i;
        if (k <= 4 && p->countsByValue[func_081075C0(row, k)] > 0) {
            gUnk_02035FC4 = row;
            gUnk_02035FC6 = k;
            return;
        }
    }
}

void func_08108208(void) {
    MapCardInventoryEntry* p;
    s16 a;
    s16 b;
    s16 i;
    u16 keys;
    u16 trg;

    p = func_0810718C();
    a = gUnk_02035FC4;
    b = gUnk_02035FC6;
    trg = MapInspectReadMenuKeys();
    keys = trg;

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
            FadeStartOut(0, 16);
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

                if (p->countsByValue[func_081075D8()] > 0) {
                    break;
                }
            }
        } else if (keys & 0x80) {
            for (i = 0; i <= 4; i++) {
                if (++gUnk_02035FC6 > 4) {
                    gUnk_02035FC6 = 0;
                }

                if (p->countsByValue[func_081075D8()] > 0) {
                    break;
                }
            }
        }
    }

    if (gUnk_02035FC4 != a || gUnk_02035FC6 != b) {
        m4aSongNumStart(0x65);
    }
}

void func_081083EC(void) {
    MapCardInventoryEntry* p;
    s16 old;
    u16 keys;

    p = func_0810718C();
    old = gUnk_02035FC8;
    keys = MapInspectReadMenuKeys();
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
        FadeStartOut(0, 16);
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

    keys = MapInspectReadMenuKeys();
    if (keys & 3) {
        DisableBg(2);
        m4aSongNumStart(0x68);
        gUnk_02035E2C = 2;
    } else if (keys & 8) {
        LoadBgMap(0, gUnk_09A3439C, 0x500);
        m4aSongNumStart(0x68);
        gUnk_02035FE4 = 0;
        FadeStartOut(0, 16);
        gUnk_02035FCA = 5;
    }
}

void func_08108650(void) {
    s32 i;
    s32 j;
    s16 n;
    s16 t;
    void* anim;

    if (gUnk_02035FCA != 2) {
        DrawSprite(gUnk_02035FD8 >> 8, 0,
#ifdef VERSION_EU
            gUnkEu_09F8501C[gLanguage],
#else
            gUnk_0999D9CA,
#endif
            gUnk_02035E50, gUnk_02035E4C, 0, 0xC00, 0xBB8);
        DrawSprite(128, gUnk_02035FD0[0] >> 8,
#ifdef VERSION_EU
            gUnkEu_09F85030[gLanguage],
#else
            gUnk_0999D9E6,
#endif
            gUnk_02035E50, gUnk_02035E4C, 0, 0xC00, 0xBB9);
        DrawSprite(128, gUnk_02035FD0[1] >> 8,
#ifdef VERSION_EU
            gUnkEu_09F85044[gLanguage],
#else
            gUnk_0999DA1A,
#endif
            gUnk_02035E50, gUnk_02035E4C, 0, 0xC00, 0xBB9);
    }
    n = (func_08107220(gUnk_02035E2E) + 2) / 3 - 4;
    if (gUnk_02035E9C <= n) {
        t = 84 * gUnk_02035E9C / n;
    } else {
        t = 0;
    }
    DrawSprite(72, t + 40,
#ifdef VERSION_EU
            gUnkEu_09F85008[gLanguage],
#else
            gUnk_0999D9C0,
#endif
            gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x898);

    if (gUnk_02035FCA == 2) {
        switch (gUnk_02035E2C) {
        case 1:
            ApproachValueHalf(&gUnk_02035FDC, gMapCardCategoryDefs[gUnk_02035E2E].displayIndex * 3584 - 256);
            ApproachValueHalf(&gUnk_02035FE0, 0);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x7D0);
            break;
        case 0:
            ApproachValueHalf(&gUnk_02035FDC, (gUnk_02035E98 * 23 - 2) * 256);
            ApproachValueHalf(&gUnk_02035FE0, (gUnk_02035E9A * 26 + 16) * 256);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x7D0);
            DrawSprite(gUnk_02035E98 * 23 - 3, gUnk_02035E9A * 26 + 28, AnimUpdate(&gUnk_02035E80), gUnk_02035E78, gUnk_02035E74, 0, 0x800, 0x7DA);
            break;
        case 2:
            func_0810718C();
            ApproachValueHalf(&gUnk_02035FDC, gUnk_02035FC4 * 12288 + 0x9200);
            ApproachValueHalf(&gUnk_02035FE0, gUnk_02035FC6 * 2048 + 0x1000);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0x800, 0x7D0);
            DrawSprite(gUnk_02035FC4 * 48 + 133, gUnk_02035FC6 * 8 + 35, AnimUpdate(&gUnk_02035E80), gUnk_02035E78, gUnk_02035E74, 0, 0x800, 0x7DA);
            break;
        case 3:
            ApproachValueHalf(&gUnk_02035FDC, gUnk_02035FC8 == 0 ? 0x3400 : 0x7400);
            ApproachValueHalf(&gUnk_02035FE0, 0x5000);
            DrawSprite(gUnk_02035FDC >> 8, gUnk_02035FE0 >> 8, AnimUpdate(&gUnk_02035E58), gUnk_02035E50, gUnk_02035E4C, 0, 0, 0);

            if (gUnk_02035FA8 != 0) {
                DrawTextSlots(120 - GetTextSlotsWidth(gUnk_02035FA4, gUnk_02035FA8) / 2, 64, gUnk_02035FA4, gUnk_02035E4C, 1, gUnk_02035FA8);
            }

            if (gUnk_02035FB0 != 0) {
                DrawTextSlots(80, 84, gUnk_02035FAC, gUnk_02035E4C, 1, gUnk_02035FB0);
            }

            if (gUnk_02035FB8 != 0) {
                DrawTextSlots(144, 84, gUnk_02035FB4, gUnk_02035E4C, 1, gUnk_02035FB8);
            }
            break;
        case 4:
            if (gUnk_02035FC0[0] != 0) {
                DrawTextSlots(120 - GetTextSlotsWidth(gUnk_02035FBC[0], gUnk_02035FC0[0]) / 2, 68, gUnk_02035FBC[0], gUnk_02035E4C, 1, gUnk_02035FC0[0]);
#ifdef VERSION_JP
                DrawTextSlots(120 - GetTextSlotsWidth(gUnk_02035FBC[1], gUnk_02035FC0[1]) / 2, 80, gUnk_02035FBC[1], gUnk_02035E4C, 1, gUnk_02035FC0[1]);
#endif
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
                    DrawTextSlots(96, 92, gUnk_02035F94, gUnk_02035E74, 1, gUnk_02035F98);
                }
            }
        }

        if (gUnk_02035FA0 != 0) {
            DrawTextSlots(95, 107, gUnk_02035F9C, gUnk_02035E4C, 1, gUnk_02035FA0);
        }
    }
}

void mode_mapinspect_0(void) {
    s16 i;
    s16 j;
    s16 v;
    u16 length;

    gMapCardInventoryEntries = EwramAlloc(0x2F4);
    SpriteReset();
    FadeStartIn(0, 16);
    SetBgMode0();
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
        gUnk_02035FDC = (v = 0, -0x200);
        gUnk_02035FE0 = 0x1000;
        gUnk_02035E2C = v;
    } else {
        gUnk_02035FDC = gMapCardCategoryDefs[4].displayIndex * 7 * 512 - 0x100;
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
#ifdef VERSION_EU
    LoadBgTiles(0, gUnk_09A03CFC, 0x2C00);

    switch (gLanguage) {
    case 0:
        break;
    case 1:
        RequestDma3Copy(gUnkEu_09A3D400, (u8*)GetBgCharBase(0) + 0x800, 0xC00);
        RequestDma3Copy(gUnkEu_09A3D400 + 0xC00, (u8*)GetBgCharBase(0) + 0x2400, 0x800);
        break;
    case 2:
        RequestDma3Copy(gUnkEu_09A41000, (u8*)GetBgCharBase(0) + 0x800, 0xC00);
        RequestDma3Copy(gUnkEu_09A41000 + 0xC00, (u8*)GetBgCharBase(0) + 0x2400, 0x800);
        break;
    case 3:
        RequestDma3Copy(gUnkEu_09A3FC00, (u8*)GetBgCharBase(0) + 0x800, 0xC00);
        RequestDma3Copy(gUnkEu_09A3FC00 + 0xC00, (u8*)GetBgCharBase(0) + 0x2400, 0x800);
        break;
    case 4:
        RequestDma3Copy(gUnkEu_09A3E800, (u8*)GetBgCharBase(0) + 0x800, 0xC00);
        RequestDma3Copy(gUnkEu_09A3E800 + 0xC00, (u8*)GetBgCharBase(0) + 0x2400, 0x800);
        break;
    }
#else
    LoadBgTiles(0, gUnk_09A03CFC, 0x2980);
#endif
    LoadBgPalette(2, gUnk_09611AB8, 0x20);
    LoadBgTiles(2, gUnk_099597E4, 0x140);
    LoadBgMap(2, gUnk_09985F44, 0x800);
    LoadBgMap(0, gUnk_09A3439C, 0x500);

    if (func_0810718C()->category == 3) {
        LoadBgMap(1, gUnk_09A3551C, 0x500);
    } else {
        LoadBgMap(1, gUnk_09A3501C, 0x500);
    }

    func_081078F0(gUnk_02035E2E);
    func_081075FC();
    func_0810764C();
    func_081076D4();
    gUnk_02035E4C = LoadObjPalette(gUnk_09A3D2DC, 0x20);
#ifdef VERSION_EU
    gUnk_02035E50 = LoadObjTiles(gUnkEu_09F85058[gLanguage], gUnkEu_09999A50[gLanguage]);
    AnimInit(&gUnk_02035E58, gUnkEu_09F8506C[gLanguage], gUnkEu_09F85080[gLanguage]);
#else
#ifdef VERSION_JP
    gUnk_02035E50 = LoadObjTiles(gUnk_0999DAEC, 0xA80);
#else
    gUnk_02035E50 = LoadObjTiles(gUnk_0999DAEC, 0xAC0);
#endif
    AnimInit(&gUnk_02035E58, gUnk_09EF981C, gUnk_09EF97EC);
#endif
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
    InitTextSlots(gUnk_02035F94, 0x24);
    gUnk_02035F9C = EwramAlloc(0x2D0);
    InitTextSlots(gUnk_02035F9C, 0x5A);

#ifdef VERSION_EU
    length = func_08065B54(eu_0805E924(gUnkEu_08890EC0));
#else
    length = func_08065B54(gUnk_08159FBC);
#endif
    gUnk_02035FAA = length;
    gUnk_02035FA4 = EwramAlloc(gUnk_02035FAA * 8);
    InitTextSlots(gUnk_02035FA4, gUnk_02035FAA);
#ifdef VERSION_EU
    gUnk_02035FA8 = LoadTextSlots(eu_0805E924(gUnkEu_08890EC0), gUnk_02035FA4);
#else
    gUnk_02035FA8 = LoadTextSlots(gUnk_08159FBC, gUnk_02035FA4);
#endif

#ifdef VERSION_EU
    length = func_08065B54(eu_0805E924(gUnkEu_08890E1C));
#else
    length = func_08065B54(gUnk_08159E10);
#endif
    gUnk_02035FB2 = length;
    gUnk_02035FAC = EwramAlloc(gUnk_02035FB2 * 8);
    InitTextSlots(gUnk_02035FAC, gUnk_02035FB2);
#ifdef VERSION_EU
    gUnk_02035FB0 = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), gUnk_02035FAC);
#else
    gUnk_02035FB0 = LoadTextSlots(gUnk_08159E10, gUnk_02035FAC);
#endif

#ifdef VERSION_EU
    length = func_08065B54(eu_0805E924(gUnkEu_08890E44));
#else
    length = func_08065B54(gUnk_08159E18);
#endif
    gUnk_02035FBA = length;
    gUnk_02035FB4 = EwramAlloc(gUnk_02035FBA * 8);
    InitTextSlots(gUnk_02035FB4, gUnk_02035FBA);
#ifdef VERSION_EU
    gUnk_02035FB8 = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), gUnk_02035FB4);
#else
    gUnk_02035FB8 = LoadTextSlots(gUnk_08159E18, gUnk_02035FB4);
#endif

#ifdef VERSION_JP
    gUnk_02035FC2[0] = func_08065B54(gUnk_0814FBB0);
    gUnk_02035FBC[0] = EwramAlloc(gUnk_02035FC2[0] * 8);
    InitTextSlots(gUnk_02035FBC[0], gUnk_02035FC2[0]);
    gUnk_02035FC0[0] = LoadTextSlots(gUnk_0814FBB0, gUnk_02035FBC[0]);

    gUnk_02035FC2[1] = func_08065B54(gUnk_0814FBBC);
    gUnk_02035FBC[1] = EwramAlloc(gUnk_02035FC2[1] * 8);
    InitTextSlots(gUnk_02035FBC[1], gUnk_02035FC2[1]);
    gUnk_02035FC0[1] = LoadTextSlots(gUnk_0814FBBC, gUnk_02035FBC[1]);
#else
#ifdef VERSION_EU
    gUnk_02035FC2[0] = func_08065B54(eu_0805E924(gUnkEu_08895CF8));
#else
    gUnk_02035FC2[0] = func_08065B54(gUnk_0815C136);
#endif
    gUnk_02035FBC[0] = EwramAlloc(gUnk_02035FC2[0] * 8);
    InitTextSlots(gUnk_02035FBC[0], gUnk_02035FC2[0]);
#ifdef VERSION_EU
    gUnk_02035FC0[0] = LoadTextSlots(eu_0805E924(gUnkEu_08895CF8), gUnk_02035FBC[0]);
#else
    gUnk_02035FC0[0] = LoadTextSlots(gUnk_0815C136, gUnk_02035FBC[0]);
#endif
#endif

    func_08107280();
    func_081073F0();
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}

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
            FadeStartOut(0, 16);
            gUnk_02035FCA = 5;
        }
        break;
    case 5:
        if (!FadeIsActive()) {
            func_080E052C(gUnk_02035FE4);
        }
        break;
    }

    func_08108650();
}

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

    FreeTextSlots(gUnk_02035F94, 0x24);
    EwramFree(gUnk_02035F94);
    FreeTextSlots(gUnk_02035F9C, 0x5A);
    EwramFree(gUnk_02035F9C);
    FreeTextSlots(gUnk_02035FA4, gUnk_02035FAA);
    EwramFree(gUnk_02035FA4);
    FreeTextSlots(gUnk_02035FAC, gUnk_02035FB2);
    EwramFree(gUnk_02035FAC);
    FreeTextSlots(gUnk_02035FB4, gUnk_02035FBA);
    EwramFree(gUnk_02035FB4);

#ifdef VERSION_JP
    for (i = 0; i < 2; i++) {
#else
    for (i = 0; i < 1; i++) {
#endif
        FreeTextSlots(gUnk_02035FBC[i], gUnk_02035FC2[i]);
        EwramFree(gUnk_02035FBC[i]);
    }

    EwramFree(gMapCardInventoryEntries);
}

const char gModeNameMapinspect[] = "mode_mapinspect";

Mode gModeMapinspect = {
    gModeNameMapinspect,
    (void (*)(s32))mode_mapinspect_0,
    (void (*)(void))mode_mapinspect_1,
    (void (*)(void))mode_mapinspect_2,
};
