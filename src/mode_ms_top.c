#include "mode_ms_top.h"
#include "registration_data.h"
#include "system_state.h"
#include "mode_ms.h"
#include "mode_ms_top_api.h"
#include "worldwarp_catalog_assets.h"
#include "localized_resource_assets.h"
#include "room_resource_assets.h"
#include "sprites_09EDE878.h"
#include "sprites_evt.h"

extern u8 gUnk_09A3D77C[];
extern u8 gUnk_08B22BA8[];

static s16 gUnk_020357C0;
static void* gUnk_020357C4;
static struct ObjTiles* gUnk_020357C8;
static struct ObjPalette* gUnk_020357CC;
static struct ObjTiles* gUnk_020357D0;
static struct ObjPalette* gUnk_020357D4;
static AnimState gWorldwarpAnim;
static struct ObjTiles* gUnk_020357F0;
static struct ObjPalette* gUnk_020357F4;
static AnimState gUnk_020357F8;
static struct ObjTiles* gUnk_02035810;
static struct ObjPalette* gUnk_02035814;
static void* gUnk_02035818[2];
static void* gUnk_02035820[2];
static AnimState gUnk_02035828[2];
static struct ObjTiles* gUnk_02035858;
static struct ObjPalette* gUnk_0203585C;
static AnimState gUnk_02035860;
static s16 gUnk_02035878;
static s16 gUnk_0203587A;
static s16 gUnk_0203587C;
static s32 gUnk_02035880;
static s32 gUnk_02035884;
static s32 gUnk_02035888;
static s32 gUnk_0203588C;
static s16 gUnk_02035890;
static s16 gUnk_02035892;
static s32 gUnk_02035898[2];
static s32 gUnk_020358A0;
static u8 gUnk_020358A4;
static TaskPool gUnk_020358A8;
static s16 gUnk_020358BC;
static s16 gUnk_020358BE;
static u8 gUnk_020358C0;
static s16 gUnk_020358C2;

const WarpDef gUnk_09993118[2] = {
#if defined(VERSION_US)
    {&gModeMsShop, gUnk_09A36EDC, 1280, 104, 48, 1, 136, 80, 0, 48, 66, {0, 0}, {{64, 64, gWorldwarpAssetUs_09A3D81C, 32, {0, 0}, gWorldwarpAssetUs_099A2F84, 832, {0, 0}, gUnk_09EF999C, gUnk_09EF9998, 0, {0, 0}}, {192, 84, gUnk_09617D58, 32, {0, 0}, gUnk_099A2194, 2368, {0, 0}, gUnk_09EF9978, gUnk_09EF9928, 1, {0, 0}}}},
    {&gModeMsCharge, gUnk_09A373DC, 1280, 76, 48, 0, 112, 80, 1, 32, 32, {0, 0}, {{32, 64, gWorldwarpAssetUs_09A3D83C, 32, {0, 0}, gWorldwarpAssetUs_099A32E4, 832, {0, 0}, gUnk_09EF99A4, gUnk_09EF99A0, 0, {0, 0}}, {160, 84, gUnk_09A3D77C, 32, {0, 0}, gUnk_099A2194, 2368, {0, 0}, gUnk_09EF9978, gUnk_09EF9928, 0, {0, 0}}}},
#elif defined(VERSION_JP)
    {&gModeMsShop, gUnk_09A36EDC, 1280, 104, 48, 1, 136, 80, 0, 48, 66, {0, 0}, {{64, 64, gWorldwarpAssetJp_099F22A4, 32, {0, 0}, gWorldwarpAssetJp_09957A0C, 832, {0, 0}, gUnk_09EF999C, gUnk_09EF9998, 0, {0, 0}}, {192, 84, gUnk_09617D58, 32, {0, 0}, gUnk_099A2194, 2368, {0, 0}, gUnk_09EF9978, gUnk_09EF9928, 1, {0, 0}}}},
    {&gModeMsCharge, gUnk_09A373DC, 1280, 76, 48, 0, 112, 80, 1, 32, 32, {0, 0}, {{32, 64, gWorldwarpAssetJp_099F22C4, 32, {0, 0}, gWorldwarpAssetJp_09957D6C, 832, {0, 0}, gUnk_09EF99A4, gUnk_09EF99A0, 0, {0, 0}}, {160, 84, gUnk_09A3D77C, 32, {0, 0}, gUnk_099A2194, 2368, {0, 0}, gUnk_09EF9978, gUnk_09EF9928, 0, {0, 0}}}},
#elif defined(VERSION_EU)
    {&gModeMsShop, gUnk_09A36EDC, 1280, 104, 48, 1, 136, 80, 0, 48, 66, {0, 0}, {{64, 64, gWorldwarpAssetEu_09A9B2E0, 32, {0, 0}, gWorldwarpAssetEu_099B0F08, 832, {0, 0}, gUnk_09EF999C, gUnk_09EF9998, 0, {0, 0}}, {192, 84, gUnk_09617D58, 32, {0, 0}, gUnk_099A2194, 2368, {0, 0}, gUnk_09EF9978, gUnk_09EF9928, 1, {0, 0}}}},
    {&gModeMsCharge, gUnk_09A373DC, 1280, 76, 48, 0, 112, 80, 1, 32, 32, {0, 0}, {{32, 64, gWorldwarpAssetEu_09A9B300, 32, {0, 0}, gWorldwarpAssetEu_099B1268, 832, {0, 0}, gUnk_09EF99A4, gUnk_09EF99A0, 0, {0, 0}}, {160, 84, gUnk_09A3D77C, 32, {0, 0}, gUnk_099A2194, 2368, {0, 0}, gUnk_09EF9978, gUnk_09EF9928, 0, {0, 0}}}},
#endif
};

const u16 gUnk_099931D0[3] = {
    129,
    130,
    131,
};

const char gModeNameMsTop[] = "mode_ms_top";

#ifdef VERSION_EU
void* gUnkEu_09F84EE8[5] = {
    gUnk_09A378DC,
    gUnk_09A382DC,
    gUnkEu_09A8C1A0,
    gUnkEu_09A8BCA0,
    gUnkEu_09A8B7A0,
};

void* gUnkEu_09F84EFC[5] = {
    gUnk_09A37DDC,
    gUnkEu_09A8C6A0,
    gUnkEu_09A8D5A0,
    gUnkEu_09A8D0A0,
    gUnkEu_09A8CBA0,
};

void* gUnkEu_09F84F10[5] = {
    gUnk_099A2AD4,
    gUnkEu_099AFC68,
    gUnkEu_099B0A58,
    gUnkEu_099B0588,
    gUnkEu_099B00F8,
};

void* gUnkEu_09F84F24[5] = {
    gUnk_099A2AF0,
    gUnkEu_099AFC84,
    gUnkEu_099B0A74,
    gUnkEu_099B05A4,
    gUnkEu_099B0114,
};

void* gUnkEu_09F84F38[5] = {
    gUnk_099A2B24,
    gUnkEu_099AFCB8,
    gUnkEu_099B0AA8,
    gUnkEu_099B05D8,
    gUnkEu_099B0148,
};
#endif

Mode gModeMsTop = {
    gModeNameMsTop,
    (void (*)(s32))mode_ms_top_0,
    (void (*)(void))mode_ms_top_1,
    (void (*)(void))mode_ms_top_2,
};

u32 GetMooglePoints(void) {
    return gGameState.progression.mooglePoints;
}

void SetMooglePoints(u32 a) {
    gGameState.progression.mooglePoints = a;
}

u8 SpendMooglePoints(u32 a) {
    u8 ok = 0;

    if (GetMooglePoints() >= a) {
        SetMooglePoints(GetMooglePoints() - a);
        ok = 1;
    }
    return ok;
}

u8 AddMooglePoints(u32 a) {
    a += GetMooglePoints();
    if (a > 99999) {
        SetMooglePoints(99999);
        return 0;
    }
    SetMooglePoints(a);
    return 1;
}

void LoadDecimalDigitTiles(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count) {
    s32 i;
    u32 digit;

    for (i = 0; i < count; i++) {
        digit = value % 10;
        value /= 10;
        RequestDma3Copy(&glyphs[digit * stride], &dst[(count - 1 - i) * stride], stride);
    }
}

void func_081015E8(void) {
    s32 flag;
    s16 x;
    s32 v;
    s32 base;

    x = gUnk_09993118[0].x3 + ((gUnk_0203588C - gUnk_02035884) >> 8);
    flag = 0;
    v = x;
    base = (-gUnk_02035880) >> 8;
    if (v <= base + 0x1C || v >= base + 0x1C + 0x62) {
        flag = 1;
    }
    ReleaseObjPalette(gUnk_0203585C);
    gUnk_0203585C = LoadObjPalette(flag == 0 ? gUnk_09617D58 : gUnk_09A3D77C, 0x20);
}

void func_08101654(void) {
    s16 i;
    s32 flag;
    s16 x;
    s32 v;
    s32 base;

    for (i = 0; i <= 1; i++) {
        x = gUnk_09993118[0].gfx[i].x - (gUnk_02035884 >> 8);
        flag = 0;
        v = x;
        base = (-gUnk_02035880) >> 8;
        if (v <= base + 0x18 || v >= base + 0x18 + 0x6A) {
            flag = 1;
        }

        if (gUnk_02035820[i] != 0) {
            ReleaseObjPalette(gUnk_02035820[i]);
        }

        if (gUnk_02035818[i] != 0) {
            ReleaseObjTiles(gUnk_02035818[i]);
        }
        gUnk_02035820[i] = LoadObjPalette(gUnk_09993118[flag].gfx[i].palette, gUnk_09993118[flag].gfx[i].paletteSize);
        gUnk_02035818[i] = LoadObjTiles(gUnk_09993118[flag].gfx[i].tiles, gUnk_09993118[flag].gfx[i].tilesSize);
        AnimInit(&gUnk_02035828[i], gUnk_09993118[flag].gfx[i].anims, gUnk_09993118[flag].gfx[i].gfxTable);
        AnimStart(&gUnk_02035828[i], gUnk_09993118[flag].gfx[i].animId, 1);
    }
}

void func_08101740(s16 a) {
    AnimStart(&gWorldwarpAnim, gUnk_09993118[a].animId, 1);
}

void func_08101768(void) {
    if (gUnk_020358BC < 0) {
        if (gUnk_020358C2 <= 2) {
            gUnk_020358BC = gUnk_099931D0[gUnk_020358C2];
            gUnk_020358C2++;
        }
    }
}

void func_081017A0(void) {
    s16 prev;
    u16 keys;

    prev = gUnk_020357C0;
    keys = GetKeysPressed();
    if (keys & 1) {
        if (gUnk_020357C0 == 1) {
            AnimStart(&gUnk_02035828[gUnk_020357C0], 2, 1);
        }
        gUnk_020357C4 = gUnk_09993118[gUnk_020357C0].mode;
        m4aSongNumStart(0x66);
        FadeStartOut(0, 16);
        FadeLock();
        gUnk_02035890 = 11;
    } else if (keys & 2) {
        gUnk_020357C4 = 0;
        m4aSongNumStart(0x68);
        gUnk_020358A4 = 1;
#ifdef VERSION_EU
        LoadBgMap(2, gUnkEu_09F84EE8[gLanguage], 0x500);
#else
        LoadBgMap(2, gUnk_09A378DC, 0x500);
#endif
        gUnk_02035892 = 16;
        gUnk_02035890 = 9;
    } else if (keys & 8) {
        gUnk_020357C4 = 0;
        m4aSongNumStart(0x68);
        gUnk_020358A4 = 1;
#ifdef VERSION_EU
        LoadBgMap(2, gUnkEu_09F84EE8[gLanguage], 0x500);
#else
        LoadBgMap(2, gUnk_09A378DC, 0x500);
#endif
        FadeStartOut(0, 16);
        FadeLock();
        gUnk_02035890 = 11;
    } else if ((keys & 0x20) && gUnk_02035878 != 1 && gUnk_020357C0 != 0) {
        gUnk_020357C0 = 0;
        gUnk_02035878 = 1;
        gUnk_0203587A = 30 - gUnk_0203587A;
        gUnk_0203587C = 1;
        AnimStart(&gUnk_02035860, 1, 1);
    } else if ((keys & 0x10) && gUnk_02035878 != 2 && gUnk_020357C0 != 1) {
        gUnk_020357C0 = 1;
        gUnk_02035878 = 2;
        gUnk_0203587A = 30 - gUnk_0203587A;
        gUnk_0203587C = 2;
        AnimStart(&gUnk_02035860, 1, 1);
    }

    if (gUnk_020357C0 != prev) {
        if (func_080A42C8()) {
            func_080A42E0();
        }
        gUnk_020358BE = gUnk_020357C0 == 0 ? 0x40 : 0x41;
        func_08101740(gUnk_020357C0);
        m4aSongNumStart(0x65);
    }
}

void func_08101970(void) {
    s32 i;
    u16 flags;

    if (gUnk_020358A4 != 0) {
#ifdef VERSION_EU
        DrawSprite(gUnk_020358A0 >> 8, 0, gUnkEu_09F84F10[gLanguage], gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D0);
        DrawSprite(0x80, gUnk_02035898[0] >> 8, gUnkEu_09F84F24[gLanguage], gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D1);
        DrawSprite(0x80, gUnk_02035898[1] >> 8, gUnkEu_09F84F38[gLanguage], gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D1);
#else
        DrawSprite(gUnk_020358A0 >> 8, 0, gUnk_099A2AD4, gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D0);
        DrawSprite(0x80, gUnk_02035898[0] >> 8, gUnk_099A2AF0, gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D1);
        DrawSprite(0x80, gUnk_02035898[1] >> 8, gUnk_099A2B24, gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D1);
#endif
    }

    flags = 0x800;

    switch (gUnk_0203587C) {
    case 0:
        if (gUnk_020357C0 == 0) {
            flags |= 1;
        }
        break;
    case 1:
        break;
    case 2:
        flags |= 1;
        break;
    }
    DrawSprite(gUnk_09993118[0].x3 + ((gUnk_0203588C - gUnk_02035884) >> 8), gUnk_09993118[0].y3,
        AnimUpdate(&gUnk_02035860), gUnk_02035858, gUnk_0203585C, 0, flags, 0x834);
    DrawSprite((gUnk_02035888 >> 8) + gUnk_09993118[0].x, gUnk_09993118[0].y,
        AnimUpdate(&gWorldwarpAnim), gUnk_020357D0, gUnk_020357D4, 0, 0x800, 0x7D0);

    DrawSprite(gUnk_09993118[0].x2 + (gUnk_02035888 >> 8), gUnk_09993118[0].y2,
        AnimUpdate(&gUnk_020357F8), gUnk_020357F0, gUnk_020357F4, 0,
        0x800 | gUnk_09993118[gUnk_020357C0].flags, 0x7D0);
    DrawSprite(gUnk_09993118[0].x2 + (gUnk_02035888 >> 8), gUnk_09993118[0].y2,
        gUnk_08B22BA8, gUnk_02035810, gUnk_02035814, 0,
        0x800 | gUnk_09993118[gUnk_020357C0].flags, 0x7D1);

    for (i = 0; i <= 1; i++) {
        DrawSprite(gUnk_09993118[0].gfx[i].x - (gUnk_02035884 >> 8), gUnk_09993118[0].gfx[i].y,
            AnimUpdate(&gUnk_02035828[i]), gUnk_02035818[i], gUnk_02035820[i], 0, 0x800, 0x7D0);
    }

    if (gUnk_02035890 == 6) {
        func_08102F30();
    }
    TaskPoolDraw(&gUnk_020358A8);
    SetBgScroll(0, (u16)(gUnk_02035884 >> 8), 0);
    SetBgScroll(1, (u16)(gUnk_02035880 >> 8), 0);
}

void mode_ms_top_0(u32 a) {
    s32 i;

    SpriteReset();
    FadeStartIn(0, 16);
    SetBgMode0();
    gBldCnt = 0x142;
    gBldAlpha = 0x1010;
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 30, 0);
    SetupBg(3, 3, 31, 14);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);

    if (a & 1) {
        func_08102774();
    }

    if (a & 2) {
        gUnk_020358A4 = 0;
        gUnk_02035890 = 7;
    } else {
        gUnk_020358A4 = 1;
        gUnk_02035890 = 0;
        gUnk_02035892 = 16;
        gUnk_02035898[0] = -0x800;
        gUnk_02035898[1] = 0xA800;
        gUnk_020358A0 = -0x8000;
        gUnk_020357C0 = 0;
    }

    gUnk_02035878 = 0;
    gUnk_0203587A = 0;
    gUnk_0203587C = 0;

    if (gUnk_020357C0 == 0) {
        gUnk_02035880 = 0;
        gUnk_02035884 = 0;
        gUnk_02035888 = 0;
        gUnk_0203588C = 0;
    } else {
        gUnk_02035880 = -0x6100;
        gUnk_02035884 = 0x2100;
        gUnk_02035888 = -0x1C00;
        gUnk_0203588C = 0xBC00;
    }

    gUnk_020358BC = -1;
    gUnk_020358BE = -1;
    gUnk_020358C0 = 0;
    LoadBgPalette(0, gUnk_09A3D79C, 0x60);
#ifdef VERSION_EU
    LoadBgTiles(0, gUnk_09A10A3C, 0x24C0);
#else
    LoadBgTiles(0, gUnk_09A10A3C, 0x19A0);
#endif
    LoadDecimalDigitTiles(GetMooglePoints(), gUnk_09A123DC, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
    LoadBgMap(0, gUnk_09A36EDC, 0x500);
    LoadBgMap(1, gUnk_09A373DC, 0x500);

    if (gUnk_020358A4 != 0) {
#ifdef VERSION_EU
        LoadBgMap(2, gUnkEu_09F84EE8[gLanguage], 0x500);
#else
        LoadBgMap(2, gUnk_09A378DC, 0x500);
#endif
    } else {
#ifdef VERSION_EU
        LoadBgMap(2, gUnkEu_09F84EFC[gLanguage], 0x500);
#else
        LoadBgMap(2, gUnk_09A37DDC, 0x500);
#endif
    }

    for (i = 0; i < 2; i++) {
        gUnk_02035820[i] = 0;
        gUnk_02035818[i] = 0;
    }

    gUnk_020357CC = LoadObjPalette(gUnk_09A3D7FC, 0x20);
    gUnk_020357C8 = LoadObjTiles(gUnk_099A2B62, 0x400);
    gUnk_020357D4 = LoadObjPalette(gUnk_09A3D85C, 0x20);
    gUnk_020357D0 = LoadObjTiles(gUnk_099A36F8, 0x500);
    AnimInit(&gWorldwarpAnim, gUnk_09EF99D0, gUnk_09EF99A8);
    gUnk_020357F4 = LoadObjPalette(gUnk_08F683A4, 0x20);
    gUnk_020357F0 = LoadObjTiles(gUnk_088C56C6, 0x300);
    AnimInit(&gUnk_020357F8, gUnk_09EDEA6C, gUnk_09EDEA68);
    AnimStart(&gUnk_020357F8, 0, 1);
    gUnk_02035814 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    gUnk_02035810 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    gUnk_0203585C = LoadObjPalette(gUnk_09617D58, 0x20);
    gUnk_02035858 = LoadObjTiles(gUnk_092028EC, 0xC00);
    AnimInit(&gUnk_02035860, gUnk_09EEEAC8, gUnk_09EEEA98);
    AnimStart(&gUnk_02035860, 0, 1);
    func_08101740(gUnk_020357C0);
    func_08101654();
    func_081015E8();
    TaskPoolInit(&gUnk_020358A8, 1);
    EnableBg(0);
    EnableBg(1);
    EnableBg(2);
    DisableBg(3);
}

void mode_ms_top_1(void) {
    UpdatePlayTime();

    switch (gUnk_02035890) {
    case 0:
        ApproachValue(&gUnk_02035898[0], 0, gUnk_02035892);
        ApproachValue(&gUnk_02035898[1], 0x9800, gUnk_02035892);

        if (--gUnk_02035892 <= 0) {
            gUnk_02035892 = 16;
            gUnk_02035890 = 1;
        }

        break;
    case 1:
        ApproachValue(&gUnk_020358A0, 0, gUnk_02035892);

        if (--gUnk_02035892 <= 0) {
            gUnk_020358A4 = 0;
#ifdef VERSION_EU
            LoadBgMap(2, gUnkEu_09F84EFC[gLanguage], 0x500);
#else
            LoadBgMap(2, gUnk_09A37DDC, 0x500);
#endif
            gUnk_02035890 = 2;
        }
        break;
    case 2:
        if ((gGameState.progression.unk_82 & 0x80) == 0) {
            gUnk_020358C2 = 0;
            gUnk_02035890 = 3;
        } else {
            gUnk_02035890 = 4;
        }
        break;
    case 3:
        func_08101768();

        if (gUnk_020358C2 > 2 && gUnk_020358BC < 0 && func_080A42C8() == 0) {
            func_0800FDD0(27);
            gGameState.progression.unk_82 |= 0x80;
            gUnk_02035890 = 4;
        }
        break;
    case 4:
        if (func_0810274C(gUnk_0203C590[6]) == 0) {
            gUnk_020358BC = 0x42;
            gUnk_02035890 = 5;
        } else {
            gUnk_02035890 = 7;
        }
        break;
    case 5:
        if (func_080A42C8() == 0) {
            if (gGameState.floor <= 5) {
                func_08103F94(0, 0);
            } else if (gGameState.floor <= 9) {
                func_08103F94(0, 1);
            } else {
                func_08103F94(0, 2);
            }

            func_08102AB4(120, 80);
            FadeSetPaletteExcluded(13, 1);
            FadeToAmount(0, 16, 8);
            gUnk_02035890 = 6;
        }
        break;
    case 6:
        if (func_0810329C(1) == 0) {
            func_08102DC8();
            func_08102704(gUnk_0203C590[6]);
            SetupBg(3, 3, 31, 14);
            DisableBg(3);
            LoadDecimalDigitTiles(GetMooglePoints(), gUnk_09A123DC, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
            FadeToOriginal(0, 8);
            gUnk_02035890 = 7;
        }
        break;
    case 7:
        gUnk_020358BE = gUnk_020357C0 == 0 ? 0x40 : 0x41;
        gUnk_02035890 = 8;
        break;
    case 8:
        func_081017A0();
        break;
    case 9:
        ApproachValue(&gUnk_020358A0, -0x8000, gUnk_02035892);

        if (--gUnk_02035892 <= 0) {
            gUnk_02035892 = 16;
            gUnk_02035890 = 10;
        }

        break;
    case 10:
        ApproachValue(&gUnk_02035898[0], -0x800, gUnk_02035892);
        ApproachValue(&gUnk_02035898[1], 0xA800, gUnk_02035892);

        if (--gUnk_02035892 <= 0) {
            FadeStartOut(0, 16);
            FadeLock();
            gUnk_02035890 = 11;
        }

        break;
    case 11:
        if (FadeIsActive() == 0) {
            if (gUnk_020357C4 != 0) {
                ModeRequest(gUnk_020357C4, 0);
            } else {
                func_080E04EC();
            }
        }

        break;
    }

    switch (gUnk_02035878) {
    case 0:
        break;
    case 1:
        func_08101654();
        ApproachValue(&gUnk_02035880, 0, gUnk_0203587A);
        ApproachValue(&gUnk_02035884, 0, gUnk_0203587A);
        ApproachValue(&gUnk_02035888, 0, gUnk_0203587A);

        if (--gUnk_0203587A <= 0) {
            gUnk_02035878 = 0;
        }

        break;
    case 2:
        func_08101654();
        ApproachValue(&gUnk_02035880, -0x6100, gUnk_0203587A);
        ApproachValue(&gUnk_02035884, 0x2100, gUnk_0203587A);
        ApproachValue(&gUnk_02035888, -0x1C00, gUnk_0203587A);

        if (--gUnk_0203587A <= 0) {
            gUnk_02035878 = 0;
        }

        break;
    }

    switch (gUnk_0203587C) {
    case 0:
        break;
    case 1:
        func_081015E8();
        gUnk_0203588C -= 0x180;

        if (gUnk_0203588C <= 0) {
            AnimStart(&gUnk_02035860, 0, 1);
            gUnk_0203588C = 0;
            gUnk_0203587C = 0;
        }
        break;
    case 2:
        func_081015E8();
        gUnk_0203588C += 0x180;
        if (gUnk_0203588C >= 0xBC00) {
            AnimStart(&gUnk_02035860, 0, 1);
            gUnk_0203588C = 0xBC00;
            gUnk_0203587C = 0;
        }
        break;
    }

    if (gUnk_020358BE >= 0) {
        if (gUnk_020358C0 != 0) {
            if (func_080A42C8() == 0) {
                func_080A4234(&gUnk_020358A8, 3, gUnk_020358BE);
                gUnk_020358BE = -1;
            }
        } else {
            func_080A4234(&gUnk_020358A8, 3, gUnk_020358BE);
            gUnk_020358BE = -1;
            gUnk_020358C0 = 1;
        }
    }

    if (gUnk_020358BC >= 0) {
        if (gUnk_020358C0 != 0) {
            if (func_080A42C8() == 0) {
                func_080A411C(&gUnk_020358A8, 3, gUnk_020358BC);
                gUnk_020358BC = -1;
            }
        } else {
            func_080A411C(&gUnk_020358A8, 3, gUnk_020358BC);
            gUnk_020358BC = -1;
            gUnk_020358C0 = 1;
        }
    }

    TaskPoolUpdate(&gUnk_020358A8);
    func_08101970();
}

void mode_ms_top_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_020357CC);
    ReleaseObjTiles(gUnk_020357C8);
    ReleaseObjPalette(gUnk_020357D4);
    ReleaseObjTiles(gUnk_020357D0);
    ReleaseObjPalette(gUnk_020357F4);
    ReleaseObjTiles(gUnk_020357F0);
    ReleaseObjPalette(gUnk_02035814);
    ReleaseObjTiles(gUnk_02035810);

    for (i = 0; i < 2; i++) {
        ReleaseObjPalette(gUnk_02035820[i]);
        ReleaseObjTiles(gUnk_02035818[i]);
    }

    ReleaseObjPalette(gUnk_0203585C);
    ReleaseObjTiles(gUnk_02035858);
    TaskPoolDestroy(&gUnk_020358A8);
}
