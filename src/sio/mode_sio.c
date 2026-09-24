#include "macros.h"
#include "mode_sio_dbg.h"
#include "mode_chkobj_assets.h"
#include "registration_data.h"
#include "system_state.h"
#include "chara_api.h"
#include "map_api.h"
#include "msg_api.h"
#include "mode_sio_api.h"
#include "mode_pooh_api.h"
#include "m4a_song.h"
#include "pallet.h"
#include "sio_api.h"
#include "display.h"
#include "text.h"
#include "monsgage.h"
#include "mode_sio.h"
#include "gba/keys.h"
#include "btl.h"
#include "event_background_assets.h"
#include "jiminy_data.h"
#include "jiminy_text_assets.h"
#include "map.h"
#include "mode_dummy.h"
#include "sprites_boss_tm.h"
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_sora.h"
#include "battle_backgrounds.h"
#include "sprites_msg.h"
#include "link_menus.h"
#include "sprites_card_pictures.h"
#include "sprites_card.h"
#include "card_ids.h"

u16 gUnk_0203A9EC EWRAM_COMMON(4);
u16 gUnk_0203A9F0 EWRAM_COMMON(4);
s8 gUnk_0203AA00 EWRAM_COMMON(16);
CharaLinkData gUnk_0203AA10 EWRAM_COMMON(16);
u8 gUnk_0203AA30[2][20] EWRAM_COMMON(16);
u8 gUnk_0203AA58[2] EWRAM_COMMON(4);
u8 gUnk_0203AA60[2][20] EWRAM_COMMON(16);
u8 gUnk_0203AA88 EWRAM_COMMON(4);
s8 gUnk_0203AA8C EWRAM_COMMON(4);
s8 gUnk_0203AA90 EWRAM_COMMON(4);
s8 gUnk_0203AAA0[14] EWRAM_COMMON(16);
u8 gUnk_0203AAB0 EWRAM_COMMON(4);
CharaLinkData gUnk_0203AAC0 EWRAM_COMMON(16);
u8 gUnk_0203AAE0[2][20] EWRAM_COMMON(16);
#ifdef VERSION_EU
s8 gUnkEu_0203B108[2] EWRAM_COMMON(4);
#endif
#ifndef VERSION_EU
s8 gUnk_0203AB10 EWRAM_COMMON(16);
u16 gUnk_0203AB20[10] EWRAM_COMMON(16);
s8 gUnk_0203AB34[2] EWRAM_COMMON(4);
#endif

Mode gModeSioBattle = {
    "mode_sio_battle",
    mode_sio_battle_0,
    mode_sio_battle_1,
    mode_sio_battle_2,
};

Mode gModeSioBtlConnect = {
    "mode_sio_btl_connect",
    mode_sio_btl_connect_0,
    mode_sio_btl_connect_1,
    mode_sio_btl_connect_2,
};

const SioAnimDef gSioBtlOptionAnimDefs[2] = {
    {gUnk_09EDE99C, gUnk_09EDE9CC, gUnk_088BF162, 0},
    {gUnk_09EDEE08, gUnk_09EDEE14, gUnk_088E33C2, 0},
};

#ifndef VERSION_EU
extern const SioAnimDef gSioChgCardAnimDefs[3];
#endif

#ifdef VERSION_EU
const u8 gUnkEu_095DA860[7] = {'D', 'e', 'c', 'k', ' ', 'I', 0};
const u8 gUnkEu_095DA867[8] = {'D', 'e', 'c', 'k', ' ', 'I', 'I', 0};
#endif

#ifdef VERSION_EU
extern u8 gUnkEu_0967CB6C[];
extern u8 gUnkEu_095F18BE[];
extern u8 gUnkEu_095F3D12[];
extern u8 gUnkEu_095F24DA[];
extern u8 gUnkEu_095F30F6[];
extern u8 gUnkEu_095F492E[];
extern u8 gUnkEu_095EC758[];
extern u8 gUnkEu_095EC898[];
extern u8 gUnkEu_095ECB38[];
extern void* gUnkEu_08891580[];
extern void eu_080C24D8(void);
extern s32 eu_080C273C(void);
extern s32 eu_080C2740(void);

extern void* gUnkEu_08891508[];
extern void* gUnkEu_088920BC[];
extern u8 gUnkEu_096C798C[];
extern void* gUnkEu_08891714[];
extern void* gUnkEu_08891670[];
extern u8 gUnkEu_095ECDD8[];
extern u8 gUnkEu_095ED472[];
extern u8 gUnkEu_095F5550[];
extern u8 gUnkEu_095F5BB0[];
extern u8 gUnkEu_095F6150[];
extern u8 gUnkEu_095F67B0[];
extern u8 gUnkEu_095F6D50[];
extern u8 gUnkEu_095F73AA[];
extern u8 gUnkEu_095F79D2[];
extern u8 gUnkEu_095F7FAE[];
extern u8 gUnkEu_096C298C[];
extern u8 gUnkEu_096C498C[];
extern u8 gUnkEu_096C198C[];
extern u8 gUnkEu_096C398C[];
extern u8 gUnkEu_096C218C[];
extern u8 gUnkEu_096C418C[];
extern u8 gUnkEu_096C318C[];
extern u8 gUnkEu_096C518C[];
extern u8 gUnkEu_096C698C[];
extern u8 gUnkEu_096C598C[];
extern u8 gUnkEu_096C618C[];
extern u8 gUnkEu_096C718C[];
#endif

#ifdef VERSION_JP
extern u8 gUnk_0814F180[];
#endif

extern SioWorldEntry gSioWorldEntries[];
extern s8 gUnk_09EF14B8[];
extern u16 gUnk_09EF14C4[];
#ifndef VERSION_EU
extern SioChgCardPos gUnk_09EF150C[];
#endif

static SioBtlConnectWork* gSioBtlConnectWork;
static SioBtlOptionWork* gSioBtlOptionWork;
static SioBtlCardgetWork* gSioBtlCardgetWork;
#ifndef VERSION_EU
static SioBtlConnectWork* gSioChgConnectWork;
static SioChgCardWork* gSioChgCardWork;
#endif
static SioErrorWork* gSioErrorWork;

void mode_sio_btl_connect_0(s32 arg) {
    gSioBtlConnectWork = EwramAlloc(sizeof(SioBtlConnectWork));
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 7, 15);
    SetupBg(1, 1, 31, 0);
    EnableBg(0);
    EnableBg(1);
    LoadBgTiles(0, gUnk_096AD604, 0x140);
    LoadBgMap(0, gUnk_096F6464, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 0x20);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5C64, 0x800);
    gSioBtlConnectWork->unk_00 = 0;
    gSioBtlConnectWork->unk_02 = 0;
    gSioBtlConnectWork->state = 0;
    gSioBtlConnectWork->textSlotCount = 0;
    InitTextSlots(gSioBtlConnectWork->textSlots, SIO_CONNECT_TEXT_SLOTS);
#ifdef VERSION_EU
    gSioBtlConnectWork->textSlotCount = LoadTextSlots(eu_0805E924(gUnkEu_08891508), gSioBtlConnectWork->textSlots);
#else
    gSioBtlConnectWork->textSlotCount = LoadTextSlots(gUnk_08159E4A, gSioBtlConnectWork->textSlots);
#endif
    gSioBtlConnectWork->palette = LoadObjPalette(gUnk_096FBAA4, 32);
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
        SioReset();
        func_080C5A3C(func_080AEE50, func_080AEE6C, 0);
    }
#else
    SioReset();
    func_080C5A3C(func_080AEE50, func_080AEE6C, 0);
#endif
}

void mode_sio_btl_connect_1(void) {
    s32 i;
    s32 j;

#ifdef VERSION_EU
    s16 width;
    s16 x;
    if (gUnk_0203A9E4 == 0) {
#endif
    switch (gSioBtlConnectWork->state) {
    case 0:
        func_080C54B4();
        break;
    case 1:
        func_080C54B4();
        gSioBtlConnectWork->unk_02++;
        if (gSioBtlConnectWork->unk_02 > 4) {
            func_080C5DC0(func_080C6008, func_080C60D8);
            func_080C61D4();
            gSystemFlags |= 1;
            gSystemFlags |= 0x10;
            gSioBtlConnectWork->state++;
        }
        break;
    case 2:
        if (gUnk_02039B60 == 2) {
            gSioBtlConnectWork->unk_02 = 0;
            func_080AEE84();
            gSioBtlConnectWork->state++;
        }
        break;
    case 3:
        gSioBtlConnectWork->unk_02++;
        if (gSioBtlConnectWork->unk_02 > 4) {
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
            gUnk_0203AA00 = 1;
            gUnk_0203AA90 = 1;
            gUnk_0203AA8C = 1;
            gUnk_0203AA58[0] = 6;
            gUnk_0203AA58[1] = 6;

            for (i = 0; i < 2; i++) {
                for (j = 0; j < 20; j++) {
                    gUnk_0203AA60[i][j] = 0;
                    gUnk_0203AAE0[i][j] = 0;
                    gUnk_0203AA30[i][j] = 0;
                }
            }
            gUnk_0203A9EC = 0;
            gUnk_0203A9F0 = 0;
            ModeRequest(&gModeSioBtlOption, 0);
            return;
        }
        break;
    }
#ifdef VERSION_EU
    } else if (GetKeysPressed() & (A_BUTTON | START_BUTTON)) {
        gUnk_0203AA00 = 1;
        gUnk_0203AA90 = 1;
        gUnk_0203AA8C = 1;
        gUnk_0203AA58[0] = 6;
        gUnk_0203AA58[1] = 6;

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 20; j++) {
                gUnk_0203AA60[i][j] = 0;
                gUnk_0203AAE0[i][j] = 0;
                gUnk_0203AA30[i][j] = 0;
            }
        }
        func_080C7350();
        func_080AEE84();
        ModeRequest(&gModeSioBtlOption, 0);
    }
    width = eu_0806629C(gSioBtlConnectWork->textSlots, gSioBtlConnectWork->textSlotCount);
    if (gLanguage == 1) {
        x = 120 - (width >> 1);
        DrawTextSlots(x, 68, gSioBtlConnectWork->textSlots, gSioBtlConnectWork->palette, 20, gSioBtlConnectWork->textSlotCount);
    } else {
        x = 120 - (width >> 1);
        DrawTextSlots(x, 63, gSioBtlConnectWork->textSlots, gSioBtlConnectWork->palette, 20, gSioBtlConnectWork->textSlotCount);
    }
#elif defined(VERSION_JP)
    DrawTextSlots(0x3D, 0x3F, gSioBtlConnectWork->textSlots, gSioBtlConnectWork->palette, 20, gSioBtlConnectWork->textSlotCount);
#else
    DrawTextSlots(0x42, 0x3F, gSioBtlConnectWork->textSlots, gSioBtlConnectWork->palette, 20, gSioBtlConnectWork->textSlotCount);
#endif
}

void mode_sio_btl_connect_2(void) {
    ReleaseObjPalette(gSioBtlConnectWork->palette);
    FreeTextSlots(gSioBtlConnectWork->textSlots, SIO_CONNECT_TEXT_SLOTS);
    EwramFree(gSioBtlConnectWork);
}

void func_080AEE50(void) {
    m4aSongNumStart(SONG_SYS_ITEMGET);
    gSioBtlConnectWork->state++;
}

void func_080AEE6C(void) {
    m4aSongNumStart(SONG_SYS_CLOSE);
    ModeRequest(&gModeSioBattle, 2);
}

void func_080AEE84(void) {
    s32 i;
    s32 flags;
    gUnk_0203AA88 = 0;

    for (i = 0; i < 13; i++) {
        gUnk_0203AAA0[i] = 0;
    }
    flags = 0x1FFE;

    for (i = 1; i < 14; i++) {
        if ((flags >> i) & 1) {
            gUnk_0203AAA0[gUnk_0203AA88 + 1] = i;
            gUnk_0203AA88++;
        }
    }
}

void SetSioBtlOptionAnimation(u16 a, u16 b, u16 c) {
    const SioAnimDef* def = &gSioBtlOptionAnimDefs[b];
    AnimChangeWithTables(&gSioBtlOptionWork->anim2[a], def->animId, c, def->anims, def->gfxTable);
    SetObjTileSource(gSioBtlOptionWork->unk_008[a], def->tiles);
}

void mode_sio_btl_option_0(s32 arg) {
    gSioBtlOptionWork = EwramAlloc(sizeof(SioBtlOptionWork));
    SetBgMode1();
    SetupBg(0, 0, 7, 10);
    SetBgPriority(0, 0);
    SetBgOverflow(0, 1);
    SetBgSize(0, 0);
    SetupBg(1, 0, 15, 10);
    SetBgPriority(1, 1);
    SetBgOverflow(1, 1);
    SetBgSize(1, 0);
    SetupBg(2, 2, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, 1);
    SetBgSize(2, 0x8000);
    RequestDma3Copy(gUnk_096AD744, GetBgCharBase(0), 0x2000);
#ifdef VERSION_EU
    InitTextSlots(gSioBtlOptionWork->textSlots, 40);
    InitTextSlots(gSioBtlOptionWork->textSlots2, 20);
    InitTextSlots(gSioBtlOptionWork->textSlots3, 20);
    if (gUnk_0203A9E4 == 0) {
        gSioBtlOptionWork->textSlotCount2 = LoadTextSlots(gUnk_0203AA30[0], gSioBtlOptionWork->textSlots2);
        gSioBtlOptionWork->textSlotCount3 = LoadTextSlots(gUnk_0203AA30[1], gSioBtlOptionWork->textSlots3);
    } else {
        gSioBtlOptionWork->textSlotCount2 = LoadTextSlots((u16*)gUnkEu_095DA860, gSioBtlOptionWork->textSlots2);
        gSioBtlOptionWork->textSlotCount3 = LoadTextSlots((u16*)gUnkEu_095DA867, gSioBtlOptionWork->textSlots3);
    }
#else
    InitTextSlots(gSioBtlOptionWork->textSlots, 20);
    InitTextSlots(gSioBtlOptionWork->textSlots2, 10);
    InitTextSlots(gSioBtlOptionWork->textSlots3, 10);
    gSioBtlOptionWork->textSlotCount2 = LoadTextSlots(gUnk_0203AA30[0], gSioBtlOptionWork->textSlots2);
    gSioBtlOptionWork->textSlotCount3 = LoadTextSlots(gUnk_0203AA30[1], gSioBtlOptionWork->textSlots3);
#endif
    gSioBtlOptionWork->palette7 = LoadObjPalette(gUnk_096FBCC4, 32);
    gSioBtlOptionWork->palette8 = LoadObjPalette(gUnk_096FBCC4 + 64, 32);
    gSioBtlOptionWork->palette9 = LoadObjPalette(gUnk_096FBCC4 + 32, 32);
    gSioBtlOptionWork->unk_417 = gUnk_0203AAA0[gUnk_0203AA00];
    DisableBg(0);
    DisableBg(1);
    gSioBtlOptionWork->unk_21A = arg;
    gSioBtlOptionWork->unk_002 = 0;
}

void func_080AF0B0(void) {
    RequestDma3Copy(gUnk_096AF744, (u8*)GetBgCharBase(0) + 0x2000, 0x800);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        LoadBgMap(0, gUnk_096F6C64, 0x800);
        LoadBgMap(1, gUnk_096F7464, 0x800);
        break;
    case 3:
        LoadBgMap(0, gUnkEu_096C298C, 0x800);
        LoadBgMap(1, gUnkEu_096C498C, 0x800);
        break;
    case 1:
        LoadBgMap(0, gUnkEu_096C198C, 0x800);
        LoadBgMap(1, gUnkEu_096C398C, 0x800);
        break;
    case 4:
        LoadBgMap(0, gUnkEu_096C218C, 0x800);
        LoadBgMap(1, gUnkEu_096C418C, 0x800);
        break;
    case 2:
    default:
        LoadBgMap(0, gUnkEu_096C318C, 0x800);
        LoadBgMap(1, gUnkEu_096C518C, 0x800);
        break;
    }
#else
    LoadBgMap(0, gUnk_096F6C64, 0x800);
#endif
    LoadBgPalette(0, gUnk_096FBC04, 0xC0);
#ifndef VERSION_EU
    LoadBgMap(1, gUnk_096F7464, 0x800);
#endif
    DisableBg(0);
    DisableBg(1);
    gSioBtlOptionWork->unk_002 = 1;
}

void func_080AF11C(void) {
    s32 i;

#ifdef VERSION_EU
    RequestDma3Copy(gUnkEu_0967CB6C, (u8*)GetBgCharBase(0) + 0x49E0, 0x1620);
#endif

    if (gSioBtlOptionWork->unk_21A == 1) {
        gSioBtlOptionWork->unk_1B4 = 1;
        gSioBtlOptionWork->unk_000 = 1;
        gSioBtlOptionWork->y = gSioBtlOptionWork->unk_000 * 4608 + 10752;
    } else {
        gSioBtlOptionWork->unk_1B4 = 0;
        gSioBtlOptionWork->unk_000 = 0;
        gSioBtlOptionWork->y = 10752;
    }
    gSioBtlOptionWork->unk_004 = 0;
    gSioBtlOptionWork->unk_006 = 0;
    gSioBtlOptionWork->unk_217 = 0;
    gSioBtlOptionWork->unk_218 = 0;
    gSioBtlOptionWork->unk_410 = 0;
    gSioBtlOptionWork->unk_1FA = 0;
    gSioBtlOptionWork->unk_416 = 0;
    gSioBtlOptionWork->unk_418 = 0;
    SetBgAffine(2, 0, 256, 256, 0x10000, 0x16800);

    for (i = 0; i < 2; i++) {
        gSioBtlOptionWork->unk_008[i] = AllocObjTiles(0xC80, 0);
        AnimInit(&gSioBtlOptionWork->anim2[i], 0, 0);
        SetSioBtlOptionAnimation(i, 0, 0);
        gSioBtlOptionWork->gfx6[i] = AnimGetGfx(&gSioBtlOptionWork->anim2[i]);
    }

    if (gSioPlayerId == 0) {
        gSioBtlOptionWork->unk_008[2] = LoadObjPalette(gUnk_08F683A4, 32);
        gSioBtlOptionWork->unk_008[3] = LoadObjPalette(gUnk_096FAC64, 32);
    } else {
        gSioBtlOptionWork->unk_008[2] = LoadObjPalette(gUnk_096FAC64, 32);
        gSioBtlOptionWork->unk_008[3] = LoadObjPalette(gUnk_08F683A4, 32);
    }
#ifdef VERSION_EU
    gSioBtlOptionWork->palette = LoadObjPalette(gUnk_096FBD24, 32);
    switch (gLanguage) {
    case 0:
        gSioBtlOptionWork->tiles = LoadObjTiles(gUnkEu_095F18BE, 0xC00);
        gSioBtlOptionWork->gfx = gUnkEu_09F7EBB0[0];
        break;
    case 3:
        gSioBtlOptionWork->tiles = LoadObjTiles(gUnkEu_095F3D12, 0xC00);
        gSioBtlOptionWork->gfx = gUnkEu_09F7EBC8[0];
        break;
    case 1:
        gSioBtlOptionWork->tiles = LoadObjTiles(gUnkEu_095F24DA, 0xC00);
        gSioBtlOptionWork->gfx = gUnkEu_09F7EBB8[0];
        break;
    case 4:
        gSioBtlOptionWork->tiles = LoadObjTiles(gUnkEu_095F30F6, 0xC00);
        gSioBtlOptionWork->gfx = gUnkEu_09F7EBC0[0];
        break;
    case 2:
    default:
        gSioBtlOptionWork->tiles = LoadObjTiles(gUnkEu_095F492E, 0xC00);
        gSioBtlOptionWork->gfx = gUnkEu_09F7EBD0[0];
        break;
    }
#else
    gSioBtlOptionWork->tiles = LoadObjTiles(gUnk_0962BEDA, 0xC00);
    gSioBtlOptionWork->palette = LoadObjPalette(gUnk_096FBD24, 32);
    gSioBtlOptionWork->gfx = gUnk_09EF38D4[0];
#endif
    gSioBtlOptionWork->tiles2 = LoadObjTiles(gUnk_0962B090, 0x1C0);
    gSioBtlOptionWork->palette2 = LoadObjPalette(gUnk_096FBAA4, 32);
    AnimInit(&gSioBtlOptionWork->anim, gUnk_09EF38B4, gUnk_09EF3894);
    AnimStart(&gSioBtlOptionWork->anim, 1, 1);
    gSioBtlOptionWork->gfx2 = AnimGetGfx(&gSioBtlOptionWork->anim);
    gSioBtlOptionWork->unk_1E0 = 1;
    gSioBtlOptionWork->tiles3 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    gSioBtlOptionWork->palette3 = LoadObjPalette(gUnk_09611AB8, 32);
    gSioBtlOptionWork->gfx3 = gUnk_09EF1278[0];
    gSioBtlOptionWork->unk_228 = 0;
#ifdef VERSION_EU
    InitTextSlots(gSioBtlOptionWork->textSlots4, 120);
    gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(eu_0805E924(gUnkEu_08891580), gSioBtlOptionWork->textSlots4);
#else
    InitTextSlots(gSioBtlOptionWork->textSlots4, 60);
    gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(gUnk_0815A20C, gSioBtlOptionWork->textSlots4);
#endif
#ifdef VERSION_JP
    gSioBtlOptionWork->x = 68;
#else
    gSioBtlOptionWork->x = 65;
#endif
    gSioBtlOptionWork->y2 = 124;
    gSioBtlOptionWork->palette6 = LoadObjPalette(gUnk_096FBAA4, 32);
#ifdef VERSION_EU
    gSioBtlOptionWork->tiles4 = LoadObjTiles(gUnkEu_095EC758, 0x120);
#else
    gSioBtlOptionWork->tiles4 = LoadObjTiles(gUnk_0962D7C0, 0x120);
#endif
    gSioBtlOptionWork->palette4 = LoadObjPalette(gUnk_096FBD44, 32);
#ifdef VERSION_EU
    gSioBtlOptionWork->gfx4 = gUnkEu_09F7EB08[0];
    gSioBtlOptionWork->gfx7 = gUnkEu_09F7EB08[1];
    gSioBtlOptionWork->gfx8 = gUnkEu_09F7EB08[2];
#else
    gSioBtlOptionWork->gfx4 = gUnk_09EF38EC[0];
    gSioBtlOptionWork->gfx7 = gUnk_09EF38EC[1];
    gSioBtlOptionWork->gfx8 = gUnk_09EF38EC[2];
#endif
    gSioBtlOptionWork->unk_1F8 = 0;
#ifdef VERSION_EU
    gSioBtlOptionWork->tiles5[0] = LoadObjTiles(gUnkEu_095EC898, 0x280);
#else
    gSioBtlOptionWork->tiles5[0] = LoadObjTiles(gUnk_0962D900, 0x280);
#endif
    gSioBtlOptionWork->palette5[0] = LoadObjPalette(gUnk_096FBD64, 32);
#ifdef VERSION_EU
    gSioBtlOptionWork->gfx5[0] = gUnkEu_09F7EB18[0];
#else
    gSioBtlOptionWork->gfx5[0] = gUnk_09EF38FC[0];
#endif
    gSioBtlOptionWork->unk_214[0] = gUnk_0203AA58[0];
#ifdef VERSION_EU
    gSioBtlOptionWork->tiles5[1] = LoadObjTiles(gUnkEu_095ECB38, 0x280);
#else
    gSioBtlOptionWork->tiles5[1] = LoadObjTiles(gUnk_0962DBA0, 0x280);
#endif
    gSioBtlOptionWork->palette5[1] = LoadObjPalette(gUnk_096FBDA4, 32);
#ifdef VERSION_EU
    gSioBtlOptionWork->gfx5[1] = gUnkEu_09F7EB20[0];
#else
    gSioBtlOptionWork->gfx5[1] = gUnk_09EF3904[0];
#endif
    gSioBtlOptionWork->unk_214[1] = gUnk_0203AA58[1];

    if (gSioPlayerId == 0) {
        gSioBtlOptionWork->unk_216 = gUnk_0203AA58[0];
    } else {
        gSioBtlOptionWork->unk_216 = gUnk_0203AA58[1];
    }
    func_080B09C0();
    gSioBtlOptionWork->unk_002 = 2;
}

void func_080AF4F8(void) {
    s8 i = gUnk_0203AAA0[gUnk_0203AA00];
    RequestDma3Copy(gSioWorldEntries[i].tiles, GetBgCharBase(2), 0x2000);
    LoadBgPalette(2, gSioWorldEntries[i].palette, gSioWorldEntries[i].paletteSize);
#ifdef VERSION_EU
    eu_080059F4(2, gSioWorldEntries[i].map);
    gSioBtlOptionWork->textSlotCount = LoadTextSlots(eu_0805E924(gSioWorldEntries[i].text), gSioBtlOptionWork->textSlots);
#else
    LoadBgMap(2, gSioWorldEntries[i].map, gSioWorldEntries[i].mapSize);
    gSioBtlOptionWork->textSlotCount = LoadTextSlots(gSioWorldEntries[i].text, gSioBtlOptionWork->textSlots);
#endif
    DisableBg(2);
    gSioBtlOptionWork->unk_002++;
}

void func_080AF58C(void) {
    s8 i = gUnk_0203AAA0[gUnk_0203AA00];
    FadeStartIn(0, 16);
    RequestDma3Copy((u8*)gSioWorldEntries[i].tiles + 0x2000, (u8*)GetBgCharBase(2) + 0x2000, gSioWorldEntries[i].tilesSize - 0x2000);
    EnableBg(0);
    EnableBg(1);
    EnableBg(2);
    func_080B13D0();
    gSioBtlOptionWork->unk_001 = 4;
    gSioBtlOptionWork->unk_002 = 4;
}

void mode_sio_btl_option_1(void) {
    switch (gSioBtlOptionWork->unk_002) {
    case 0:
        func_080AF0B0();
        break;
    case 1:
        func_080AF11C();
        break;
    case 2:
        func_080AF4F8();
        break;
    case 3:
        func_080AF58C();
        break;
    case 4:
        func_080AFA90();
        break;
    case 5:
        func_080AFADC();
        func_080AF70C();
        break;
    case 6:
        func_080AFCD4();
        func_080AF70C();
        break;
    case 7:
        func_080AFEFC();
        func_080AF70C();
        break;
    case 8:
        func_080B0010();
        func_080AF70C();
        break;
    case 9:
        func_080B01FC();
        func_080AF70C();
        break;
    case 10:
        func_080B02A4();
        func_080AF70C();
        break;
    case 11:
        func_080B0380();
        func_080AF70C();
        break;
    case 12:
        func_080B03BC();
        func_080AF70C();
        break;
    case 13:
        func_080B03DC();
        func_080AF70C();
        break;
    case 14:
        func_080B041C();
        func_080AF70C();
        break;
    case 15:
        func_080B0440();
        func_080AF70C();
        break;
    case 16:
        func_080B0494();
        func_080AF70C();
        break;
    }
}

void func_080AF70C(void) {
#ifdef VERSION_EU
    s16 width;
    s32 multiline;
    s32 i;
#endif
    gSioBtlOptionWork->gfx6[0] = AnimUpdate(&gSioBtlOptionWork->anim2[0]);
    gSioBtlOptionWork->gfx6[1] = AnimUpdate(&gSioBtlOptionWork->anim2[1]);
    gSioBtlOptionWork->gfx2 = AnimUpdate(&gSioBtlOptionWork->anim);
    DrawSprite(60, 88, gSioBtlOptionWork->gfx6[0], gSioBtlOptionWork->unk_008[0], gSioBtlOptionWork->unk_008[2], 0, 1, 0xFFF0);
    DrawSprite(180, 88, gSioBtlOptionWork->gfx6[1], gSioBtlOptionWork->unk_008[1], gSioBtlOptionWork->unk_008[3], 0, 0, 0xFFF0);
#ifdef VERSION_EU
    width = GetTextSlotsWidth(gSioBtlOptionWork->textSlots, gSioBtlOptionWork->textSlotCount);
    DrawTextSlots(162 - width / 2, 4, gSioBtlOptionWork->textSlots, gSioBtlOptionWork->palette7, 20, gSioBtlOptionWork->textSlotCount);
#else
    DrawTextSlots(gSioWorldEntries[gSioBtlOptionWork->unk_417].textX + 108, 4, gSioBtlOptionWork->textSlots, gSioBtlOptionWork->palette7, 20, gSioBtlOptionWork->textSlotCount);
#endif
    DrawTextSlots(16, 144, gSioBtlOptionWork->textSlots2, gSioBtlOptionWork->palette8, 0xF200, gSioBtlOptionWork->textSlotCount2);
    DrawTextSlots(136, 144, gSioBtlOptionWork->textSlots3, gSioBtlOptionWork->palette9, 0xF200, gSioBtlOptionWork->textSlotCount3);
    DrawSprite(-((gSioBtlOptionWork->unk_1FA >> 3) % 4) + 88, 2, gSioBtlOptionWork->gfx4, gSioBtlOptionWork->tiles4, gSioBtlOptionWork->palette4, 0, 0, 0xFF00);
    DrawSprite(224 + ((gSioBtlOptionWork->unk_1FA >> 3) % 4), 2, gSioBtlOptionWork->gfx7, gSioBtlOptionWork->tiles4, gSioBtlOptionWork->palette4, 0, 0, 0xFF00);

    if (gSioBtlOptionWork->unk_1B4 == 1) {
        DrawSprite(72, 38, gSioBtlOptionWork->gfx, gSioBtlOptionWork->tiles, gSioBtlOptionWork->palette, 0, 0, 0x200);

        if (gSioBtlOptionWork->unk_1E0 == 1) {
            ApproachValueHalf(&gSioBtlOptionWork->y, gSioBtlOptionWork->unk_000 * 4608 + 10752);
            DrawSprite(64, gSioBtlOptionWork->y >> 8, gSioBtlOptionWork->gfx2, gSioBtlOptionWork->tiles2, gSioBtlOptionWork->palette2, 0, 0, 0x100);
        }
    }

    if (gSioBtlOptionWork->unk_228 == 1) {
        DrawSprite(120, 131, gSioBtlOptionWork->gfx3, gSioBtlOptionWork->tiles3, gSioBtlOptionWork->palette3, 0, 0, 0xF000);
#ifdef VERSION_EU
        width = eu_0806629C(gSioBtlOptionWork->textSlots4, gSioBtlOptionWork->textSlotCount4);
        multiline = 0;
        for (i = 0; i < gSioBtlOptionWork->textSlotCount4; i++) {
            if (gSioBtlOptionWork->textSlots4[i].tiles == 0) {
                multiline = 1;
                break;
            }
        }
        if (multiline != 0) {
            DrawTextSlots(120 - (width >> 1), 119, gSioBtlOptionWork->textSlots4, gSioBtlOptionWork->palette6, 20, gSioBtlOptionWork->textSlotCount4);
        } else {
            DrawTextSlots(120 - (width >> 1), 124, gSioBtlOptionWork->textSlots4, gSioBtlOptionWork->palette6, 20, gSioBtlOptionWork->textSlotCount4);
        }
#else
        DrawTextSlots(gSioBtlOptionWork->x, gSioBtlOptionWork->y2, gSioBtlOptionWork->textSlots4, gSioBtlOptionWork->palette6, 20, gSioBtlOptionWork->textSlotCount4);
#endif
    }
    DrawSprite(32, 24, gSioBtlOptionWork->gfx5[0], gSioBtlOptionWork->tiles5[0], gSioBtlOptionWork->palette5[0], 0, 0, 0xF100);
    DrawSprite(132, 24, gSioBtlOptionWork->gfx5[1], gSioBtlOptionWork->tiles5[1], gSioBtlOptionWork->palette5[1], 0, 0, 0xF100);

    if (gSioBtlOptionWork->unk_1F8 == 1) {
        DrawSprite(gSioPlayerId * 101 + 44 + gUnk_09EF14B8[gSioBtlOptionWork->unk_216], -((gSioBtlOptionWork->unk_1FA >> 3) % 4) / 2 + 22, gSioBtlOptionWork->gfx8, gSioBtlOptionWork->tiles4, gSioBtlOptionWork->palette4, 0, 0, 0xF000);
    }
    gSioBtlOptionWork->unk_1FA++;
}

void func_080AFA90(void) {
    if (gSioBtlOptionWork->unk_006 > 4) {
        gSioBtlOptionWork->unk_006 = 0;

        if (gSioBtlOptionWork->unk_21A == 1) {
            gSioBtlOptionWork->unk_002 = 6;
        } else {
            gSioBtlOptionWork->unk_002 = 5;
        }
    } else {
        gSioBtlOptionWork->unk_006++;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
}

void func_080AFADC(void) {
    s8 v = 0;
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
    gUnk_02039B58[1] |= 5;

    if (GetKeysPressed() & A_BUTTON) {
        gUnk_02039B58[1] |= 0x1F20;
    } else if (GetKeysPressed() & B_BUTTON) {
        gUnk_02039B58[1] |= 0xC2F0;
    }

    if (GetKeysPressed() & L_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(SONG_SYS_BEEP);
        } else {
            v = gUnk_0203AA00;
            v--;
            if (v <= 0) {
                v = gUnk_0203AA88;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else if (GetKeysPressed() & R_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(SONG_SYS_BEEP);
        } else {
            v = gUnk_0203AA00;
            v++;
            if (v > gUnk_0203AA88) {
                v = 1;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else {
        gUnk_02039B58[2] &= 0xFFF0;
    }

    if ((gUnk_02039810[1][0] & 0xFFF0) == 0xC2F0 || (gUnk_02039810[1][1] & 0xFFF0) == 0xC2F0) {
        if ((gUnk_02039810[1][0] & 15) == 5 && (gUnk_02039810[1][1] & 15) == 5 && gSioBtlOptionWork->unk_416 == 0) {
            func_080C57B4();
            m4aMPlayAllStop();
            gUnk_0203A9EC = 0;
            gUnk_0203A9F0 = 0;
            ModeRequest(&gModeSioBtlConnect, 0);
        }
    } else if ((gUnk_02039810[1][0] & 0xFFF0) == 0x1F20) {
        gSioBtlOptionWork->unk_416 = 10;

        if (gSioPlayerId == 0) {
            m4aSongNumStart(SONG_SYS_CANSEL);
            gSioBtlOptionWork->unk_1B4 = 1;
            gSioBtlOptionWork->unk_002 = 6;
        }
    } else if ((gUnk_02039810[1][1] & 0xFFF0) == 0x1F20) {
        gSioBtlOptionWork->unk_416 = 10;

        if (gSioPlayerId == 1) {
            m4aSongNumStart(SONG_SYS_CANSEL);
            gSioBtlOptionWork->unk_1B4 = 1;
            gSioBtlOptionWork->unk_002 = 6;
        }
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();

    if (gSioBtlOptionWork->unk_416 > 0) {
        gSioBtlOptionWork->unk_416--;
    }
#ifdef VERSION_EU
    } else {
        if (GetKeysPressed() & A_BUTTON) {
            m4aSongNumStart(SONG_SYS_CANSEL);
            gSioBtlOptionWork->unk_1B4 = 1;
            gSioBtlOptionWork->unk_002 = 6;
        }
        if (GetKeysPressed() & L_BUTTON) {
            if (gUnk_0203AA88 == 1) {
                m4aSongNumStart(SONG_SYS_BEEP);
            } else {
                v = gUnk_0203AA00;
                v--;
                if (v <= 0) {
                    v = gUnk_0203AA88;
                }
                gSioBtlOptionWork->unk_006 = 0;
                gSioBtlOptionWork->unk_004 = 0;
                gSioBtlOptionWork->unk_410 = 0;
                gSioBtlOptionWork->unk_001 = gSioBtlOptionWork->unk_002;
                gUnk_0203AA90 = gUnk_0203AA00;
                gUnk_0203AA00 = v;
                gSioBtlOptionWork->unk_002 = 8;
                m4aSongNumStart(SONG_SYS_CANSEL);
            }
        } else if (GetKeysPressed() & R_BUTTON) {
            if (gUnk_0203AA88 == 1) {
                m4aSongNumStart(SONG_SYS_BEEP);
            } else {
                v = gUnk_0203AA00;
                v++;
                if (v > gUnk_0203AA88) {
                    v = 1;
                }
                gSioBtlOptionWork->unk_006 = 0;
                gSioBtlOptionWork->unk_004 = 0;
                gSioBtlOptionWork->unk_410 = 0;
                gSioBtlOptionWork->unk_001 = gSioBtlOptionWork->unk_002;
                gUnk_0203AA90 = gUnk_0203AA00;
                gUnk_0203AA00 = v;
                gSioBtlOptionWork->unk_002 = 8;
                m4aSongNumStart(SONG_SYS_CANSEL);
            }
        } else {
            gUnk_02039B58[2] &= 0xFFF0;
        }

        func_080B0634();
        func_080B1064();
        func_080B06D4();
        func_080B0874();
    }
#endif
}

void func_080AFCD4(void) {
    s8 v;
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
    gUnk_02039B58[1] = 6;

    if (GetKeysPressed() & DPAD_UP) {
        m4aSongNumStart(SONG_SYS_CLICK);
        gSioBtlOptionWork->unk_000--;
        if (gSioBtlOptionWork->unk_000 < 0) {
            gSioBtlOptionWork->unk_000 = 2;
        }
    } else if (GetKeysPressed() & DPAD_DOWN) {
        m4aSongNumStart(SONG_SYS_CLICK);
        gSioBtlOptionWork->unk_000++;
        if (gSioBtlOptionWork->unk_000 > 2) {
            gSioBtlOptionWork->unk_000 = 0;
        }
    }

    if (GetKeysPressed() & L_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(SONG_SYS_BEEP);
        } else {
            v = gUnk_0203AA00;
            v--;
            if (v <= 0) {
                v = gUnk_0203AA88;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else if (GetKeysPressed() & R_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(SONG_SYS_BEEP);
        } else {
            v = gUnk_0203AA00;
            v++;
            if (v > gUnk_0203AA88) {
                v = 1;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else {
        gUnk_02039B58[2] &= 0xFFF0;
    }

    if (GetKeysPressed() & A_BUTTON) {
        m4aSongNumStart(SONG_SYS_KETTEI);

        switch (gSioBtlOptionWork->unk_000) {
        case 0:
            if (gSioPlayerId == 0) {
                gUnk_02039B58[1] = 0x2FCF;
            } else {
                gUnk_02039B58[1] = 0x6AD6;
            }
            gSioBtlOptionWork->unk_1B4 = 0;
            gSioBtlOptionWork->unk_228 = 1;
#ifdef VERSION_EU
            gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(eu_0805E924(gUnkEu_08891580), gSioBtlOptionWork->textSlots4);
#else
            gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(gUnk_0815A20C, gSioBtlOptionWork->textSlots4);
#endif
#ifdef VERSION_JP
            gSioBtlOptionWork->x = 68;
#else
            gSioBtlOptionWork->x = 65;
#endif
            gSioBtlOptionWork->y2 = 124;
            gSioBtlOptionWork->unk_002 = 9;
            break;
        case 1:
            ModeRequest(&gUnk_09EE2704, 0);
            break;
        case 2:
            gSioBtlOptionWork->unk_1E0 = 0;
            gSioBtlOptionWork->unk_1F8 = 1;
            gSioBtlOptionWork->unk_002 = 7;
            break;
        }
    } else if (GetKeysPressed() & B_BUTTON) {
        m4aSongNumStart(SONG_SYS_CLOSE);
        gSioBtlOptionWork->unk_1B4 = 0;
        gSioBtlOptionWork->unk_002 = 5;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
#ifdef VERSION_EU
    } else {
        if (GetKeysPressed() & DPAD_UP) {
            m4aSongNumStart(SONG_SYS_CLICK);
            gSioBtlOptionWork->unk_000--;
            if (gSioBtlOptionWork->unk_000 < 0) {
                gSioBtlOptionWork->unk_000 = 2;
            }
        } else if (GetKeysPressed() & DPAD_DOWN) {
            m4aSongNumStart(SONG_SYS_CLICK);
            gSioBtlOptionWork->unk_000++;
            if (gSioBtlOptionWork->unk_000 > 2) {
                gSioBtlOptionWork->unk_000 = 0;
            }
        }

        if (GetKeysPressed() & L_BUTTON) {
            if (gUnk_0203AA88 == 1) {
                m4aSongNumStart(SONG_SYS_BEEP);
            } else {
                v = gUnk_0203AA00;
                v--;
                if (v <= 0) {
                    v = gUnk_0203AA88;
                }
                gSioBtlOptionWork->unk_006 = 0;
                gSioBtlOptionWork->unk_004 = 0;
                gSioBtlOptionWork->unk_410 = 0;
                gSioBtlOptionWork->unk_001 = gSioBtlOptionWork->unk_002;
                gUnk_0203AA90 = gUnk_0203AA00;
                gUnk_0203AA00 = v;
                gSioBtlOptionWork->unk_002 = 8;
                m4aSongNumStart(SONG_SYS_CANSEL);
            }
        } else if (GetKeysPressed() & R_BUTTON) {
            if (gUnk_0203AA88 == 1) {
                m4aSongNumStart(SONG_SYS_BEEP);
            } else {
                v = gUnk_0203AA00;
                v++;
                if (v > gUnk_0203AA88) {
                    v = 1;
                }
                gSioBtlOptionWork->unk_006 = 0;
                gSioBtlOptionWork->unk_004 = 0;
                gSioBtlOptionWork->unk_410 = 0;
                gSioBtlOptionWork->unk_001 = gSioBtlOptionWork->unk_002;
                gUnk_0203AA90 = gUnk_0203AA00;
                gUnk_0203AA00 = v;
                gSioBtlOptionWork->unk_002 = 8;
                m4aSongNumStart(SONG_SYS_CANSEL);
            }
        }

        if (GetKeysPressed() & A_BUTTON) {
            m4aSongNumStart(SONG_SYS_KETTEI);

            switch (gSioBtlOptionWork->unk_000) {
            case 0:
                gUnkEu_0203B108[0] = 1;
                gSioBtlOptionWork->unk_1B4 = 0;
                gSioBtlOptionWork->unk_228 = 1;
                gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(eu_0805E924(gUnkEu_08891580), gSioBtlOptionWork->textSlots4);
#ifdef VERSION_JP
                gSioBtlOptionWork->x = 68;
#else
                gSioBtlOptionWork->x = 65;
#endif
                gSioBtlOptionWork->y2 = 124;
                gSioBtlOptionWork->unk_002 = 9;
                break;
            case 1:
                ModeRequest(&gUnk_09EE2704, 0);
                break;
            case 2:
                gSioBtlOptionWork->unk_1E0 = 0;
                gSioBtlOptionWork->unk_1F8 = 1;
                gSioBtlOptionWork->unk_002 = 7;
                break;
            }
        } else if (GetKeysPressed() & B_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            gSioBtlOptionWork->unk_1B4 = 0;
            gSioBtlOptionWork->unk_002 = 5;
        }
        func_080B0634();
        func_080B1064();
        func_080B06D4();
        func_080B0874();
    }
#endif
}

void func_080AFEFC(void) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
    if (GetKeysPressed() & DPAD_LEFT) {
        if (gSioBtlOptionWork->unk_216 > 1) {
            m4aSongNumStart(SONG_SYS_CLICK);
            gSioBtlOptionWork->unk_216--;
        } else {
            m4aSongNumStart(SONG_SYS_BEEP);
        }
    } else if (GetKeysPressed() & DPAD_RIGHT) {
        if (gSioBtlOptionWork->unk_216 <= 10) {
            m4aSongNumStart(SONG_SYS_CLICK);
            gSioBtlOptionWork->unk_216++;
        } else {
            m4aSongNumStart(SONG_SYS_BEEP);
        }
    }

    if (gSioPlayerId == 0) {
        gUnk_0203AA58[0] = gSioBtlOptionWork->unk_216;
    } else {
        gUnk_0203AA58[1] = gSioBtlOptionWork->unk_216;
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON)) {
        m4aSongNumStart(SONG_SYS_CLOSE);
        gSioBtlOptionWork->unk_1E0 = 1;
        gSioBtlOptionWork->unk_1F8 = 0;
        gSioBtlOptionWork->unk_002 = 6;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
#ifdef VERSION_EU
    } else {
        if (GetKeysPressed() & DPAD_LEFT) {
            if (gSioBtlOptionWork->unk_216 > 1) {
                m4aSongNumStart(SONG_SYS_CLICK);
                gSioBtlOptionWork->unk_216--;
                gUnk_0203AA58[0] = gSioBtlOptionWork->unk_216;
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
        } else if (GetKeysPressed() & DPAD_RIGHT) {
            if (gSioBtlOptionWork->unk_216 <= 10) {
                m4aSongNumStart(SONG_SYS_CLICK);
                gSioBtlOptionWork->unk_216++;
                gUnk_0203AA58[0] = gSioBtlOptionWork->unk_216;
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
        }
        if (GetKeysPressed() & L_BUTTON) {
            if ((s8)gUnk_0203AA58[1] > 1) {
                m4aSongNumStart(SONG_SYS_CLICK);
                gUnk_0203AA58[1]--;
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
        } else if (GetKeysPressed() & R_BUTTON) {
            if ((s8)gUnk_0203AA58[1] <= 10) {
                m4aSongNumStart(SONG_SYS_CLICK);
                gUnk_0203AA58[1]++;
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
        }
        if (GetKeysPressed() & (A_BUTTON | B_BUTTON)) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            gSioBtlOptionWork->unk_1E0 = 1;
            gSioBtlOptionWork->unk_1F8 = 0;
            gSioBtlOptionWork->unk_002 = 6;
        }
        func_080B0634();
        func_080B1064();
        func_080B06D4();
        func_080B0874();
    }
#endif
}

void func_080B0010(void) {
    s8 a = gUnk_0203AAA0[gUnk_0203AA90];
    s8 b = gUnk_0203AAA0[gUnk_0203AA00];

    switch (gSioBtlOptionWork->unk_410) {
    case 0:
        gSioBtlOptionWork->unk_006++;
        if (gSioBtlOptionWork->unk_006 > 1) {
            gSioBtlOptionWork->unk_006 = 0;

            if (gSioBtlOptionWork->unk_004 > 31) {
                gSioBtlOptionWork->unk_004 = 32;
                gSioBtlOptionWork->unk_410++;
            } else {
                gSioBtlOptionWork->unk_004 += 8;
                FadePaletteToBlack(gSioWorldEntries[a].palette, (u16*)0x05000000, gSioWorldEntries[a].paletteSize, gSioBtlOptionWork->unk_004);
            }
        }
        break;
    case 1:
        FadePaletteToBlack(gSioWorldEntries[b].palette, (u16*)0x05000000, gSioWorldEntries[b].paletteSize, 32);
#ifdef VERSION_EU
        eu_080059F4(2, gSioWorldEntries[b].map);
#else
        LoadBgMap(2, gSioWorldEntries[b].map, gSioWorldEntries[b].mapSize);
#endif
        RequestDma3Copy(gSioWorldEntries[b].tiles, GetBgCharBase(2), 0x2000);
        gSioBtlOptionWork->unk_410++;
        break;
    case 2:
        RequestDma3Copy((u8*)gSioWorldEntries[b].tiles + 0x2000, (u8*)GetBgCharBase(2) + 0x2000, gSioWorldEntries[b].tilesSize - 0x2000);
#ifdef VERSION_EU
        gSioBtlOptionWork->textSlotCount = LoadTextSlots(eu_0805E924(gSioWorldEntries[b].text), gSioBtlOptionWork->textSlots);
#else
        gSioBtlOptionWork->textSlotCount = LoadTextSlots(gSioWorldEntries[b].text, gSioBtlOptionWork->textSlots);
#endif
        gSioBtlOptionWork->unk_417 = b;
        gSioBtlOptionWork->unk_410++;
        break;
    case 3:
        gSioBtlOptionWork->unk_006++;
        if (gSioBtlOptionWork->unk_006 > 1) {
            gSioBtlOptionWork->unk_006 = 0;

            if (gSioBtlOptionWork->unk_004 <= 0) {
                gSioBtlOptionWork->unk_004 = 0;
                func_080B13D0();
                gSioBtlOptionWork->unk_410++;
            } else {
                gSioBtlOptionWork->unk_004 -= 8;
                if (gSioBtlOptionWork->unk_004 == 0) {
                    LoadPaletteWithEffect(gSioWorldEntries[b].palette, (u16*)0x05000000, gSioWorldEntries[b].paletteSize);
                } else {
                    FadePaletteToBlack(gSioWorldEntries[b].palette, (u16*)0x05000000, gSioWorldEntries[b].paletteSize, gSioBtlOptionWork->unk_004);
                }
            }
        }
        break;
    default:
        gSioBtlOptionWork->unk_002 = gSioBtlOptionWork->unk_001;
        break;
    }
    func_080B0634();
    func_080B1064();
    func_080B0874();
}

void func_080B01FC(void) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
        if (gSioPlayerId == 0) {
            gUnk_02039B58[1] = 0x2FCF;
        } else {
            gUnk_02039B58[1] = 0x6AD6;
        }
#ifdef VERSION_EU
    } else if (GetKeysPressed() & A_BUTTON) {
        gUnkEu_0203B108[1] = 1;
    }
#endif

    if (gSioBtlOptionWork->unk_217 == 1 && gSioBtlOptionWork->unk_218 == 1) {
        gSioBtlOptionWork->unk_006 = 0;
#ifdef VERSION_EU
        gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(eu_0805E924(gUnkEu_08891670), gSioBtlOptionWork->textSlots4);
#else
        gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(gUnk_0815A23C, gSioBtlOptionWork->textSlots4);
#endif
#ifdef VERSION_JP
        gSioBtlOptionWork->x = 61;
#else
        gSioBtlOptionWork->x = 68;
#endif
        gSioBtlOptionWork->y2 = 119;
        gSioBtlOptionWork->unk_002++;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
}

void func_080B02A4(void) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
    if (GetKeysPressed() & A_BUTTON) {
        gUnk_02039B58[1] = 0xA926;
    } else if (GetKeysPressed() & B_BUTTON) {
        gUnk_02039B58[1] = 0xDD42;
    }

    if (gUnk_02039810[1][0] == 0xA926 || gUnk_02039810[1][1] == 0xA926) {
        m4aSongNumStart(SONG_SYS_ITEMGET);
        gSioBtlOptionWork->unk_006 = 0;
#ifdef VERSION_EU
        gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(eu_0805E924(gUnkEu_08891714), gSioBtlOptionWork->textSlots4);
#else
        gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(gUnk_0815B3D4, gSioBtlOptionWork->textSlots4);
#endif
#ifdef VERSION_JP
        gSioBtlOptionWork->x = 74;
#else
        gSioBtlOptionWork->x = 72;
#endif
        gSioBtlOptionWork->y2 = 124;
        gSioBtlOptionWork->unk_002++;
    } else if (gUnk_02039810[1][0] == 0xDD42 || gUnk_02039810[1][1] == 0xDD42) {
        gSioBtlOptionWork->unk_416 = 10;
        m4aSongNumStart(SONG_SYS_CLOSE);
        gSioBtlOptionWork->unk_006 = 0;
        func_080B1364();
        gSioBtlOptionWork->unk_002 = 5;
    }
#ifdef VERSION_EU
    } else if (GetKeysPressed() & A_BUTTON) {
        m4aSongNumStart(SONG_SYS_ITEMGET);
        gSioBtlOptionWork->unk_006 = 0;
        gSioBtlOptionWork->textSlotCount4 = LoadTextSlots(eu_0805E924(gUnkEu_08891714), gSioBtlOptionWork->textSlots4);
        gSioBtlOptionWork->x = 72;
        gSioBtlOptionWork->y2 = 124;
        gSioBtlOptionWork->unk_002++;
    }
#endif
}

void func_080B0380(void) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
        gSioBtlOptionWork->unk_006++;
        if (gSioBtlOptionWork->unk_006 > 9) {
            func_080C5DC0(func_080C6008, func_080C60D8);
            func_080C5F94();
            gSioBtlOptionWork->unk_002++;
        }
    } else {
        gSioBtlOptionWork->unk_006++;
        if (gSioBtlOptionWork->unk_006 > 9) {
            func_080C5F94();
            eu_080C24D8();
            gSioBtlOptionWork->unk_006 = 0;
            gSioBtlOptionWork->unk_002++;
        }
    }
#else
    gSioBtlOptionWork->unk_006++;
    if (gSioBtlOptionWork->unk_006 > 9) {
        func_080C5DC0(func_080C6008, func_080C60D8);
        func_080C5F94();
        gSioBtlOptionWork->unk_002++;
    }
#endif
}

void func_080B03BC(void) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
        if (gUnk_02039B60 == 2) {
            gSioBtlOptionWork->unk_006 = 0;
            gSioBtlOptionWork->unk_002++;
        }
    } else {
        gSioBtlOptionWork->unk_006++;
        if (gSioBtlOptionWork->unk_006 > 59) {
            gSioBtlOptionWork->unk_006 = 0;
            gSystemFlags |= 1;
            func_080C5DC0(eu_080C273C, eu_080C2740);
            func_080B0F18();
            gUnkEu_0203C970 = 180;
            gUnkEu_0203C97C = 0;
            gUnkEu_0203C964 = 120;
            ModeRequest(&gModeVsbattle, 0);
        }
    }
#else
    if (gUnk_02039B60 == 2) {
        gSioBtlOptionWork->unk_006 = 0;
        gSioBtlOptionWork->unk_002++;
    }
#endif
}

void func_080B03DC(void) {
    gSioBtlOptionWork->unk_006++;
    if (gSioBtlOptionWork->unk_006 > 4) {
        gSioBtlOptionWork->unk_006 = 0;
        func_080C5DC0(func_080C5D50, func_080C5D80);
        func_080C5D00();
        gSioBtlOptionWork->unk_002++;
    }
}

void func_080B041C(void) {
    gSioBtlOptionWork->unk_006++;
    if (gSioBtlOptionWork->unk_006 > 30) {
        gSioBtlOptionWork->unk_006 = 0;
        gSioBtlOptionWork->unk_002++;
    }
}

void func_080B0440(void) {
    gSioBtlOptionWork->unk_006++;
    if (gSioBtlOptionWork->unk_006 > 20) {
        gUnk_02039B58[1] = 0x7CD2;

        if (gUnk_02039810[1][0] == 0x7CD2 && gUnk_02039810[1][1] == 0x7CD2) {
            gSioBtlOptionWork->unk_006 = 0;
            gSystemFlags &= 0xFFEF;
            gSioBtlOptionWork->unk_002++;
        }
    }
}

void func_080B0494(void) {
    gSioBtlOptionWork->unk_006++;
    if (gSioBtlOptionWork->unk_006 > 4) {
        gSioBtlOptionWork->unk_006 = 0;
        func_080C5DC0(func_080C5E58, func_080C5ECC);
        func_080B0F18();

        if (gSioPlayerId == 0) {
            ModeRequest(&gModeVsbattle, 0);
        } else {
            ModeRequest(&gModeVsbattle, 1);
        }
    }
}

void mode_sio_btl_option_2(void) {
    ReleaseObjTiles(gSioBtlOptionWork->unk_008[0]);
    ReleaseObjPalette(gSioBtlOptionWork->unk_008[2]);
    ReleaseObjTiles(gSioBtlOptionWork->unk_008[1]);
    ReleaseObjPalette(gSioBtlOptionWork->unk_008[3]);
    ReleaseObjPalette(gSioBtlOptionWork->palette7);
    ReleaseObjPalette(gSioBtlOptionWork->palette8);
    ReleaseObjPalette(gSioBtlOptionWork->palette9);
    ReleaseObjPalette(gSioBtlOptionWork->palette6);
#ifdef VERSION_EU
    FreeTextSlots(gSioBtlOptionWork->textSlots, 40);
    FreeTextSlots(gSioBtlOptionWork->textSlots2, 20);
    FreeTextSlots(gSioBtlOptionWork->textSlots3, 20);
    FreeTextSlots(gSioBtlOptionWork->textSlots4, 120);
#else
    FreeTextSlots(gSioBtlOptionWork->textSlots, 20);
    FreeTextSlots(gSioBtlOptionWork->textSlots2, 10);
    FreeTextSlots(gSioBtlOptionWork->textSlots3, 10);
    FreeTextSlots(gSioBtlOptionWork->textSlots4, 60);
#endif
    ReleaseObjTiles(gSioBtlOptionWork->tiles);
    ReleaseObjPalette(gSioBtlOptionWork->palette);
    ReleaseObjTiles(gSioBtlOptionWork->tiles2);
    ReleaseObjPalette(gSioBtlOptionWork->palette2);
    ReleaseObjTiles(gSioBtlOptionWork->tiles3);
    ReleaseObjPalette(gSioBtlOptionWork->palette3);
    ReleaseObjTiles(gSioBtlOptionWork->tiles4);
    ReleaseObjPalette(gSioBtlOptionWork->palette4);
    ReleaseObjTiles(gSioBtlOptionWork->tiles5[0]);
    ReleaseObjPalette(gSioBtlOptionWork->palette5[0]);
    ReleaseObjTiles(gSioBtlOptionWork->tiles5[1]);
    ReleaseObjPalette(gSioBtlOptionWork->palette5[1]);
    EwramFree(gSioBtlOptionWork);
}

void func_080B0634(void) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
    if (gUnk_02039810[1][0] == 0x2FCF) {
        RequestDma3Copy(gUnk_096B2724, (void*)0x06000020, 0xC0);

        if (gSioBtlOptionWork->unk_217 == 0) {
            SetSioBtlOptionAnimation(0, 1, 1);
        }
        gSioBtlOptionWork->unk_217 = 1;
    }

    if (gUnk_02039810[1][1] == 0x6AD6) {
        RequestDma3Copy(gUnk_096B2B24, (void*)0x06000300, 0xC0);

        if (gSioBtlOptionWork->unk_218 == 0) {
            SetSioBtlOptionAnimation(1, 1, 1);
        }
        gSioBtlOptionWork->unk_218 = 1;
    }
#ifdef VERSION_EU
    } else {
    if (gUnkEu_0203B108[0] == 1) {
        RequestDma3Copy(gUnk_096B2724, (void*)0x06000020, 0xC0);

        if (gSioBtlOptionWork->unk_217 == 0) {
            SetSioBtlOptionAnimation(0, 1, 1);
        }
        gSioBtlOptionWork->unk_217 = 1;
    }

    if (gUnkEu_0203B108[1] == 1) {
        RequestDma3Copy(gUnk_096B2B24, (void*)0x06000300, 0xC0);

        if (gSioBtlOptionWork->unk_218 == 0) {
            SetSioBtlOptionAnimation(1, 1, 1);
        }
        gSioBtlOptionWork->unk_218 = 1;
    }
    }
#endif
}

void func_080B06D4(void) {
    s8 x;
    s8 y;
#ifdef VERSION_EU
    if (gUnk_0203A9E4 != 0) {
        return;
    }
#endif
    x = gUnk_02039810[2][0] & 15;
    y = gUnk_02039810[2][1] & 15;
    if (x != 0 || y != 0) {
        if (x <= 12 && y <= 12) {
            gUnk_0203AA90 = gUnk_0203AA00;

            if (x > y) {
                gUnk_0203AA00 = x;
            } else if (x < y) {
                gUnk_0203AA00 = y;
            } else {
                gUnk_0203AA00 = x;
            }
            gSioBtlOptionWork->unk_006 = 0;
            gSioBtlOptionWork->unk_004 = 0;
            gSioBtlOptionWork->unk_410 = 0;
            gSioBtlOptionWork->unk_001 = gSioBtlOptionWork->unk_002;
            gSioBtlOptionWork->unk_002 = 8;
            m4aSongNumStart(SONG_SYS_CANSEL);
        }
    }
}

void func_080B0754(void) {
    u8 buf[2];
    s8 x;
    s8 y;
    s32 i;
#ifdef VERSION_EU
    if (gUnk_0203A9E4 != 0) {
        return;
    }
#endif
    buf[0] = (gUnk_02039810[2][0] & 0xF0) >> 4;
    buf[1] = (gUnk_02039810[2][1] & 0xF0) >> 4;

    if (buf[0] >= 1 && buf[0] <= 11) {
        gUnk_0203AA58[0] = buf[0];
    }

    if (buf[1] >= 1 && buf[1] <= 11) {
        gUnk_0203AA58[1] = buf[1];
    }

    if ((gUnk_02039810[2][0] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][0] >> 12) - 1;
        gUnk_0203AAE0[0][n * 2] = gUnk_02039810[3][0];
        gUnk_0203AAE0[0][n * 2 + 1] = gUnk_02039810[3][0] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[0][i] = gUnk_0203AAE0[0][i];
            }
        }
    }

    if ((gUnk_02039810[2][1] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][1] >> 12) - 1;
        gUnk_0203AAE0[1][n * 2] = gUnk_02039810[3][1];
        gUnk_0203AAE0[1][n * 2 + 1] = gUnk_02039810[3][1] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[1][i] = gUnk_0203AAE0[1][i];
            }
        }
    }
    x = gUnk_02039810[2][0] & 15;
    y = gUnk_02039810[2][1] & 15;
    if (x != 0 || y != 0) {
        if (x <= 12 && y <= 12) {
            if (x > y) {
                gUnk_0203AA00 = x;
            } else if (x < y) {
                gUnk_0203AA00 = y;
            } else {
                gUnk_0203AA00 = x;
            }
        }
    }
}

void func_080B0874(void) {
    s32 deck;
    s32 i;
#ifdef VERSION_EU
    if (gUnk_0203A9E4 != 0) {
        return;
    }
#endif
    deck = GetActiveDeckIndex();
    gUnk_02039B58[2] |= (gUnk_0203AA8C & 15) << 12;
    gUnk_02039B58[3] = gDecks[deck].unk_C6[(gUnk_0203AA8C - 1) * 2] | (gDecks[deck].unk_C6[(gUnk_0203AA8C - 1) * 2 + 1] << 8);
    gUnk_0203AA8C++;
    if (gUnk_0203AA8C > 10) {
        gUnk_0203AA8C = 1;
    }

    if ((gUnk_02039810[2][0] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][0] >> 12) - 1;
        gUnk_0203AAE0[0][n * 2] = gUnk_02039810[3][0];
        gUnk_0203AAE0[0][n * 2 + 1] = gUnk_02039810[3][0] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[0][i] = gUnk_0203AAE0[0][i];
                gUnk_0203AA30[0][i] = gUnk_0203AA60[0][i];
            }
            gSioBtlOptionWork->textSlotCount2 = LoadTextSlots(gUnk_0203AA30[0], gSioBtlOptionWork->textSlots2);
        }
    }

    if ((gUnk_02039810[2][1] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][1] >> 12) - 1;
        gUnk_0203AAE0[1][n * 2] = gUnk_02039810[3][1];
        gUnk_0203AAE0[1][n * 2 + 1] = gUnk_02039810[3][1] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[1][i] = gUnk_0203AAE0[1][i];
                gUnk_0203AA30[1][i] = gUnk_0203AA60[1][i];
            }
            gSioBtlOptionWork->textSlotCount3 = LoadTextSlots(gUnk_0203AA30[1], gSioBtlOptionWork->textSlots3);
        }
    }
}

void func_080B09C0(void) {
    s16 digits[4];
    s16 a, b, c, d, e, f, g, h;

#ifdef VERSION_EU
    if ((gUnk_0203A9E4 == 0 ? gSioPlayerId : 0) != 0) {
        a = gUnk_0203AA10.unk_04;
        b = gUnk_0203AAC0.unk_04;
        c = gUnk_0203AA10.unk_02;
        d = gUnk_0203AAC0.unk_02;
        e = gUnk_0203AA10.unk_06;
        f = gUnk_0203AAC0.unk_06;
        g = gUnk_0203AA10.unk_08;
        h = gUnk_0203AAC0.unk_08;
    } else {
        a = gUnk_0203AAC0.unk_04;
        b = gUnk_0203AA10.unk_04;
        c = gUnk_0203AAC0.unk_02;
        d = gUnk_0203AA10.unk_02;
        e = gUnk_0203AAC0.unk_06;
        f = gUnk_0203AA10.unk_06;
        g = gUnk_0203AAC0.unk_08;
        h = gUnk_0203AA10.unk_08;
    }
#else
    if (gSioPlayerId == 0) {
        a = gUnk_0203AAC0.unk_04;
        b = gUnk_0203AA10.unk_04;
        c = gUnk_0203AAC0.unk_02;
        d = gUnk_0203AA10.unk_02;
        e = gUnk_0203AAC0.unk_06;
        f = gUnk_0203AA10.unk_06;
        g = gUnk_0203AAC0.unk_08;
        h = gUnk_0203AA10.unk_08;
    } else {
        a = gUnk_0203AA10.unk_04;
        b = gUnk_0203AAC0.unk_04;
        c = gUnk_0203AA10.unk_02;
        d = gUnk_0203AAC0.unk_02;
        e = gUnk_0203AA10.unk_06;
        f = gUnk_0203AAC0.unk_06;
        g = gUnk_0203AA10.unk_08;
        h = gUnk_0203AAC0.unk_08;
    }
#endif

    digits[0] = a / 100;
    a %= 100;
    digits[1] = a / 10;
    a %= 10;
    digits[2] = a;
    RequestDma3Copy(gUnk_096B2124 + digits[1] * 32, (void*)0x06000100, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[2] * 32, (void*)0x06000120, 32);

    digits[0] = c / 100;
    c %= 100;
    digits[1] = c / 10;
    c %= 10;
    digits[2] = c;
    RequestDma3Copy(gUnk_096B2124 + digits[0] * 32, (void*)0x06000140, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[1] * 32, (void*)0x06000160, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[2] * 32, (void*)0x06000180, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[0] * 32, (void*)0x060001A0, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[1] * 32, (void*)0x060001C0, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[2] * 32, (void*)0x060001E0, 32);

    digits[0] = e / 1000;
    e %= 1000;
    digits[1] = e / 100;
    e %= 100;
    digits[2] = e / 10;
    e %= 10;
    digits[3] = e;
    RequestDma3Copy(gUnk_096B2124 + digits[0] * 32, (void*)0x06000200, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[1] * 32, (void*)0x06000220, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[2] * 32, (void*)0x06000240, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[3] * 32, (void*)0x06000260, 32);

    digits[0] = g / 1000;
    g %= 1000;
    digits[1] = g / 100;
    g %= 100;
    digits[2] = g / 10;
    g %= 10;
    digits[3] = g;
    RequestDma3Copy(gUnk_096B2124 + digits[0] * 32, (void*)0x06000280, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[1] * 32, (void*)0x060002A0, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[2] * 32, (void*)0x060002C0, 32);
    RequestDma3Copy(gUnk_096B2124 + digits[3] * 32, (void*)0x060002E0, 32);

    digits[0] = b / 100;
    b %= 100;
    digits[1] = b / 10;
    b %= 10;
    digits[2] = b;
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[1] * 32, (void*)0x060003E0, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[2] * 32, (void*)0x06000400, 32);

    digits[0] = d / 100;
    d %= 100;
    digits[1] = d / 10;
    d %= 10;
    digits[2] = d;
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[0] * 32, (void*)0x06000420, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[1] * 32, (void*)0x06000440, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[2] * 32, (void*)0x06000460, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[0] * 32, (void*)0x06000480, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[1] * 32, (void*)0x060004A0, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[2] * 32, (void*)0x060004C0, 32);

    digits[0] = f / 1000;
    f %= 1000;
    digits[1] = f / 100;
    f %= 100;
    digits[2] = f / 10;
    f %= 10;
    digits[3] = f;
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[0] * 32, (void*)0x060004E0, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[1] * 32, (void*)0x06000500, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[2] * 32, (void*)0x06000520, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[3] * 32, (void*)0x06000540, 32);

    digits[0] = h / 1000;
    h %= 1000;
    digits[1] = h / 100;
    h %= 100;
    digits[2] = h / 10;
    h %= 10;
    digits[3] = h;
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[0] * 32, (void*)0x06000560, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[1] * 32, (void*)0x06000580, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[2] * 32, (void*)0x060005A0, 32);
    RequestDma3Copy(gUnk_096B2124 + 0x400 + digits[3] * 32, (void*)0x060005C0, 32);
}
void func_080B0F18(void) {
    s8* base;
    s8* p;
    GameState* gs;
    SioWorldEntry* table;
    SioWorldEntry* entry;

    base = gUnk_0203AAA0;
    p = base + gUnk_0203AA00;
    gs = &gGameState;
    table = gSioWorldEntries;
    entry = &table[*p];

    gs->unk_00D = entry->world;
    gUnk_0203AAB0 = gs->world;
    gs->world = entry->world;

    if (gSioPlayerId == 0) {
        gUnk_0203AAC0.unk_0A += gUnk_09EF14C4[gSioBtlOptionWork->unk_214[0]];
        gUnk_0203AA10.unk_0A += gUnk_09EF14C4[gSioBtlOptionWork->unk_214[1]];
    } else {
        gUnk_0203AAC0.unk_0A += gUnk_09EF14C4[gSioBtlOptionWork->unk_214[1]];
        gUnk_0203AA10.unk_0A += gUnk_09EF14C4[gSioBtlOptionWork->unk_214[0]];
    }

    gGameState.unk_1E0 = gUnk_0203AAC0.unk_02;
    gGameState.unk_1E2 = gUnk_0203AAC0.unk_0A;
    gGameState.unk_1E4 = gUnk_0203AAC0.unk_04;
    gGameState.unk_1E8 = gUnk_0203AAC0.unk_0C;
    gGameState.unk_1F0 = gUnk_0203AAC0.unk_14;
    gGameState.unk_1F8 = gUnk_0203AA10.unk_02;
    gGameState.unk_1FA = gUnk_0203AA10.unk_0A;
    gGameState.unk_1FC = gUnk_0203AA10.unk_04;
    gGameState.unk_200 = gUnk_0203AA10.unk_0C;
    gGameState.unk_208 = gUnk_0203AA10.unk_14;
}

void func_080B1064(void) {
    u8 buf[2];

#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
#endif
    if (gSioPlayerId == 0) {
        gUnk_02039B58[2] |= (gUnk_0203AA58[0] & 15) << 4;
    } else {
        gUnk_02039B58[2] |= (gUnk_0203AA58[1] & 15) << 4;
    }
    buf[0] = (gUnk_02039810[2][0] & 0xF0) >> 4;
    buf[1] = (gUnk_02039810[2][1] & 0xF0) >> 4;

    if (buf[0] >= 1 && buf[0] <= 11) {
        gSioBtlOptionWork->unk_214[0] = buf[0];
        gUnk_0203AA58[0] = gSioBtlOptionWork->unk_214[0];
    }

    if (buf[1] >= 1 && buf[1] <= 11) {
        gSioBtlOptionWork->unk_214[1] = buf[1];
        gUnk_0203AA58[1] = gSioBtlOptionWork->unk_214[1];
    }
    func_080B1134(gSioBtlOptionWork->unk_214[0], gSioBtlOptionWork->unk_214[1]);
#ifdef VERSION_EU
    } else {
    buf[0] = gUnk_0203AA58[0];
    buf[1] = gUnk_0203AA58[1];

    if (buf[0] >= 1 && buf[0] <= 11) {
        gSioBtlOptionWork->unk_214[0] = buf[0];
    }

    if (buf[1] >= 1 && buf[1] <= 11) {
        gSioBtlOptionWork->unk_214[1] = buf[1];
    }
    func_080B1134(gSioBtlOptionWork->unk_214[0], gSioBtlOptionWork->unk_214[1]);
    }
#endif
}

void func_080B1134(u16 a, u16 b) {
    switch (a) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LoadPalette(gUnk_096FBD64, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[0])->index * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBD64 + 0x22, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[0])->index * 32 + 0x05000202), (6 - a) * 2);
        break;
    case 6:
        LoadPalette(gUnk_096FBD64, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[0])->index * 32 + 0x05000200), 32);
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        LoadPalette(gUnk_096FBD64, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[0])->index * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBD64 + 0x2C, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[0])->index * 32 + 0x0500020C), (a - 6) * 2);
        break;
    }

    switch (b) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LoadPalette(gUnk_096FBDA4, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[1])->index * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBDA4 + 0x22, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[1])->index * 32 + 0x05000202), (6 - b) * 2);
        break;
    case 6:
        LoadPalette(gUnk_096FBDA4, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[1])->index * 32 + 0x05000200), 32);
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        LoadPalette(gUnk_096FBDA4, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[1])->index * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBDA4 + 0x2C, (void*)(((ObjPalette*)gSioBtlOptionWork->palette5[1])->index * 32 + 0x0500020C), (b - 6) * 2);
        break;
    }
}

void func_080B1364(void) {
    gSioBtlOptionWork->unk_228 = 0;
    RequestDma3Copy(gUnk_096B2664, (void*)0x06000020, 0xC0);
    RequestDma3Copy(gUnk_096B2664 + 0x400, (void*)0x06000300, 0xC0);
    gSioBtlOptionWork->unk_217 = 0;
    gSioBtlOptionWork->unk_218 = 0;
    SetSioBtlOptionAnimation(0, 0, 0);
    SetSioBtlOptionAnimation(1, 0, 0);
}

void func_080B13D0(void) {
    s8 i = gUnk_0203AAA0[gUnk_0203AA00];
    switch (i) {
    case 1:
        m4aSongNumStart(SONG_BGM_ALADDIN_BATTLE);
        break;
    case 2:
        m4aSongNumStart(SONG_BGM_MARMAID_BATTLE);
        break;
    case 3:
        m4aSongNumStart(SONG_BGM_HERCULES_BATTLE);
        break;
    case 4:
        m4aSongNumStart(SONG_BGM_ALICE_BTL);
        break;
    case 5:
        m4aSongNumStart(SONG_BGM_PINOCCHIO_BTL);
        break;
    case 6:
        m4aSongNumStart(SONG_BGM_HALLOWEEN_BTL);
        break;
    case 7:
        m4aSongNumStart(SONG_BGM_PETERPAN_BTL);
        break;
    case 8:
        m4aSongNumStart(SONG_BGM_HOLLOW_BATTLE);
        break;
    case 9:
        m4aSongNumStart(SONG_BGM_DESTINY_BATTLE);
        break;
    case 10:
        m4aSongNumStart(SONG_BGM_TOWN_BTL);
        break;
    case 11:
        m4aSongNumStart(SONG_BGM_TWILIGHT_BATTLE);
        break;
    case 12:
        m4aSongNumStart(SONG_BGM_F13F_FORGET_BATTLE);
        break;
    }
}

void mode_sio_btl_cardget_0(s32 arg) {
#ifdef VERSION_EU
    if (gUnk_0203A9E4 == 0) {
        gSystemFlags |= 0x10;
    }
#else
    gSystemFlags |= 0x10;
#endif

    if (gUnk_0203C374 == 1) {
        func_080C57A4();
        gUnk_0203C374 = 0;
    }
    gSioBtlCardgetWork = EwramAlloc(sizeof(SioBtlCardgetWork));

    if (arg == 0) {
        gSioBtlCardgetWork->unk_06 = 0;
    } else {
        gSioBtlCardgetWork->unk_06 = 1;
    }
    SetBgMode0();
    SetupBg(1, 0, 16, 0);
    SetBgPriority(1, 1);
    SetupBg(2, 0, 24, 0);
    SetBgPriority(2, 2);
    RequestDma3Copy(gUnk_096AD744, GetBgCharBase(1), 0x2000);
    gSioBtlCardgetWork->state = 0;
}

void func_080B1534(void) {
    RequestDma3Copy(gUnk_096AF744, (u8*)GetBgCharBase(1) + 0x2000, 0x2000);
}

void func_080B1558(void) {
#ifdef VERSION_EU
    RequestDma3Copy(gUnk_096B1744, (u8*)GetBgCharBase(1) + 0x4000, 0x2000);
#else
    RequestDma3Copy(gUnk_096B1744, (u8*)GetBgCharBase(1) + 0x4000, 0x9E0);
#endif
    LoadBgPalette(1, gUnk_096FBAC4, 0x200);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        LoadBgMap(1, gUnk_096F7C64, 0x800);
        break;
    case 3:
        LoadBgMap(1, gUnkEu_096C698C, 0x800);
        break;
    case 1:
        LoadBgMap(1, gUnkEu_096C598C, 0x800);
        break;
    case 4:
        LoadBgMap(1, gUnkEu_096C618C, 0x800);
        break;
    case 2:
    default:
        LoadBgMap(1, gUnkEu_096C718C, 0x800);
        break;
    }
#else
    LoadBgMap(1, gUnk_096F7C64, 0x800);
#endif
    DisableBg(1);
}

void func_080B15A4(void) {
    FadeStartIn(0, 16);
    DisableBg(0);
    EnableBg(1);
    EnableBg(2);
    DisableBg(3);

    if (gSioBtlCardgetWork->unk_06 == 0) {
        gUnk_0203A9EC++;
        if (gUnk_0203A9EC > 0x270F) {
            gUnk_0203A9EC = 0x270F;
        }

        if (gSioPlayerId == 0) {
            func_080B18C4();
            gSioBtlCardgetWork->palette = LoadObjPalette(gUnk_08F683A4, 32);
            gSioBtlCardgetWork->palette2 = LoadObjPalette(gUnk_096FAC64, 32);
        } else {
            func_080B1974();
            gSioBtlCardgetWork->palette = LoadObjPalette(gUnk_096FAC64, 32);
            gSioBtlCardgetWork->palette2 = LoadObjPalette(gUnk_08F683A4, 32);
        }
    } else {
        gUnk_0203A9F0++;
        if (gUnk_0203A9F0 > 0x270F) {
            gUnk_0203A9F0 = 0x270F;
        }

        if (gSioPlayerId == 0) {
            func_080B1974();
            gSioBtlCardgetWork->palette = LoadObjPalette(gUnk_08F683A4, 32);
            gSioBtlCardgetWork->palette2 = LoadObjPalette(gUnk_096FAC64, 32);
        } else {
            func_080B18C4();
            gSioBtlCardgetWork->palette = LoadObjPalette(gUnk_096FAC64, 32);
            gSioBtlCardgetWork->palette2 = LoadObjPalette(gUnk_08F683A4, 32);
        }
    }

    if (gSioPlayerId == 0) {
        gSioBtlCardgetWork->unk_20 = 0x3C00;
        gSioBtlCardgetWork->unk_24 = 0x6000;
    } else {
        gSioBtlCardgetWork->unk_20 = 0xB400;
        gSioBtlCardgetWork->unk_24 = 0x6000;
    }
    gSioBtlCardgetWork->unk_02 = 0;
    gSioBtlCardgetWork->unk_04 = 0;
    gGameState.hp = gUnk_0203AAC0.unk_00;
    gGameState.world = gUnk_0203AAB0;
}

void mode_sio_btl_cardget_1(void) {
#ifdef VERSION_EU
    SioBtlCardgetWork* work;
#endif
    switch (gSioBtlCardgetWork->state) {
    case 0:
        func_080B1534();
        gSioBtlCardgetWork->state++;
        break;
    case 1:
        func_080B1558();
        gSioBtlCardgetWork->state++;
        break;
    case 2:
        func_080B15A4();
        gSioBtlCardgetWork->state++;
        break;
    case 3:
        gSioBtlCardgetWork->unk_04++;
        if (gSioBtlCardgetWork->unk_04 > 4) {
            gSioBtlCardgetWork->unk_04 = 0;
#ifdef VERSION_EU
            if (gUnk_0203A9E4 == 0) {
#endif
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
#ifdef VERSION_EU
            }
#endif
            gSioBtlCardgetWork->state++;
        }
        func_080B1848();
        break;
    case 4:
        gSioBtlCardgetWork->unk_04++;
        if (gSioBtlCardgetWork->unk_04 > 4) {
            gSioBtlCardgetWork->unk_04 = 0;
            gSioBtlCardgetWork->state++;
        }
        func_080B1848();
        break;
    case 5:
#ifdef VERSION_EU
        if (gUnk_0203A9E4 == 0) {
#endif
        if (GetKeysPressed() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
            gUnk_02039B58[1] = 0x45FC;
        }

        if (gUnk_02039810[1][0] == 0x45FC || gUnk_02039810[1][1] == 0x45FC) {
            m4aSongNumStart(SONG_SYS_ITEMGET);
            gSioBtlCardgetWork->unk_04 = 0;
            gSioBtlCardgetWork->state++;
        }
#ifdef VERSION_EU
        } else if (GetKeysPressed() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
            m4aSongNumStart(SONG_SYS_ITEMGET);
            gSioBtlCardgetWork->unk_04 = 0;
            gSioBtlCardgetWork->state++;
        }
#endif
        func_080B1848();
        break;
    case 6:
        gSioBtlCardgetWork->unk_04++;
        if (gSioBtlCardgetWork->unk_04 > 4) {
#ifdef VERSION_EU
            work = gSioBtlCardgetWork;
            if (gUnk_0203A9E4 == 0) {
#endif
            func_080C5DC0(func_080C6008, func_080C60D8);
            func_080C61D4();
#ifdef VERSION_EU
                work = gSioBtlCardgetWork;
            }
            work->state++;
#else
            gSioBtlCardgetWork->state++;
#endif
        }
        func_080B1848();
        break;
    case 7:
#ifdef VERSION_EU
        if (gUnk_0203A9E4 == 0) {
#endif
        if (gUnk_02039B60 == 2) {
            gSioBtlCardgetWork->unk_04 = 0;
            gSioBtlCardgetWork->state++;
        }
#ifdef VERSION_EU
        } else {
            gSioBtlCardgetWork->unk_04 = 0;
            gSioBtlCardgetWork->state++;
        }
#endif
        func_080B1848();
        break;
    case 8:
        gSioBtlCardgetWork->unk_04++;
        if (gSioBtlCardgetWork->unk_04 > 4) {
#ifdef VERSION_EU
            work = gSioBtlCardgetWork;
            if (gUnk_0203A9E4 == 0) {
#endif
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
#ifdef VERSION_EU
                work = gSioBtlCardgetWork;
            }
            work->state++;
#else
            gSioBtlCardgetWork->state++;
#endif
        }
        func_080B1848();
        break;
    case 9:
        ModeRequestHeapReset(&gModeSioBtlOption, 0);
        gSioBtlCardgetWork->state++;
        break;
    }
}

void mode_sio_btl_cardget_2(void) {
}

void func_080B1848(void) {
    DrawSprite(60, 116, gSioBtlCardgetWork->gfx, gSioBtlCardgetWork->tiles, gSioBtlCardgetWork->palette, 0, 0, 0xFFF0);
    DrawSprite(180, 116, gSioBtlCardgetWork->gfx2, gSioBtlCardgetWork->tiles2, gSioBtlCardgetWork->palette2, 0, 0, 0xFFF0);
#ifdef VERSION_JP
    DrawSprite(28, 36, gSioBtlCardgetWork->gfx3, gSioBtlCardgetWork->tiles3, gSioBtlCardgetWork->palette3, 0, 0, 0xFF00);
#else
    DrawSprite(13, 36, gSioBtlCardgetWork->gfx3, gSioBtlCardgetWork->tiles3, gSioBtlCardgetWork->palette3, 0, 0, 0xFF00);
#endif
#ifdef VERSION_JP
    DrawSprite(148, 36, gSioBtlCardgetWork->gfx4, gSioBtlCardgetWork->tiles4, gSioBtlCardgetWork->palette4, 0, 0, 0xFF00);
#else
    DrawSprite(135, 36, gSioBtlCardgetWork->gfx4, gSioBtlCardgetWork->tiles4, gSioBtlCardgetWork->palette4, 0, 0, 0xFF00);
#endif
}

void func_080B18C4(void) {
    LoadBgMap(2, gUnk_096F8C64, 0x800);
    gSioBtlCardgetWork->tiles = AllocObjTiles(0xC80, gUnk_088B6560);
    gSioBtlCardgetWork->gfx = gUnk_09EDE8CC[18];
    gSioBtlCardgetWork->tiles2 = AllocObjTiles(0xC80, gUnk_091CF5D4);
    gSioBtlCardgetWork->gfx2 = gUnk_09EEE4C8[6];
#ifdef VERSION_EU
    gSioBtlCardgetWork->palette3 = LoadObjPalette(gUnk_096FBDE4, 32);
    gSioBtlCardgetWork->palette4 = LoadObjPalette(gUnk_096FBE04, 32);
    switch (gLanguage) {
    case 0:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095ECDD8, 0x680);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EB28[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095ED472, 0x600);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EB30[0];
        break;
    case 1:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F5550, 0x640);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EBD8[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F5BB0, 0x580);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EBE0[0];
        break;
    case 4:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F6150, 0x640);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EBE8[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F67B0, 0x580);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EBF0[0];
        break;
    case 3:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F6D50, 0x640);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EBF8[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F73AA, 0x600);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EC00[0];
        break;
    case 2:
    default:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F79D2, 0x5C0);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EC08[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F7FAE, 0x600);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EC10[0];
        break;
    }
#else
#ifdef VERSION_JP
    gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnk_0962CAFC, 0x500);
#else
    gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnk_0962CAFC, 0x680);
#endif
    gSioBtlCardgetWork->palette3 = LoadObjPalette(gUnk_096FBDE4, 32);
    gSioBtlCardgetWork->gfx3 = gUnk_09EF38DC[0];
#ifdef VERSION_JP
    gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnk_0962D196, 0x480);
#else
    gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnk_0962D196, 0x600);
#endif
    gSioBtlCardgetWork->palette4 = LoadObjPalette(gUnk_096FBE04, 32);
    gSioBtlCardgetWork->gfx4 = gUnk_09EF38E4[0];
#endif
}

void func_080B1974(void) {
    LoadBgMap(2, gUnk_096F8464, 0x800);
    gSioBtlCardgetWork->tiles = AllocObjTiles(0xC80, gUnk_091CF5D4);
    gSioBtlCardgetWork->gfx = gUnk_09EEE4C8[6];
    gSioBtlCardgetWork->tiles2 = AllocObjTiles(0xC80, gUnk_088B6560);
    gSioBtlCardgetWork->gfx2 = gUnk_09EDE8CC[18];
#ifdef VERSION_EU
    gSioBtlCardgetWork->palette3 = LoadObjPalette(gUnk_096FBE04, 32);
    gSioBtlCardgetWork->palette4 = LoadObjPalette(gUnk_096FBDE4, 32);
    switch (gLanguage) {
    case 0:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095ED472, 0x600);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EB30[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095ECDD8, 0x680);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EB28[0];
        break;
    case 1:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F5BB0, 0x580);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EBE0[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F5550, 0x640);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EBD8[0];
        break;
    case 4:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F67B0, 0x580);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EBF0[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F6150, 0x640);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EBE8[0];
        break;
    case 3:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F73AA, 0x600);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EC00[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F6D50, 0x640);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EBF8[0];
        break;
    case 2:
    default:
        gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnkEu_095F7FAE, 0x600);
        gSioBtlCardgetWork->gfx3 = gUnkEu_09F7EC10[0];
        gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnkEu_095F79D2, 0x5C0);
        gSioBtlCardgetWork->gfx4 = gUnkEu_09F7EC08[0];
        break;
    }
#else
#ifdef VERSION_JP
    gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnk_0962D196, 0x480);
#else
    gSioBtlCardgetWork->tiles3 = LoadObjTiles(gUnk_0962D196, 0x600);
#endif
    gSioBtlCardgetWork->palette3 = LoadObjPalette(gUnk_096FBE04, 32);
    gSioBtlCardgetWork->gfx3 = gUnk_09EF38E4[0];
#ifdef VERSION_JP
    gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnk_0962CAFC, 0x500);
#else
    gSioBtlCardgetWork->tiles4 = LoadObjTiles(gUnk_0962CAFC, 0x680);
#endif
    gSioBtlCardgetWork->palette4 = LoadObjPalette(gUnk_096FBDE4, 32);
    gSioBtlCardgetWork->gfx4 = gUnk_09EF38DC[0];
#endif
}

#ifndef VERSION_EU
void mode_sio_chg_connect_0(s32 arg) {
    gSioChgConnectWork = EwramAlloc(sizeof(SioBtlConnectWork));
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 7, 15);
    SetupBg(1, 1, 31, 0);
    EnableBg(0);
    EnableBg(1);
    LoadBgTiles(0, gUnk_096AD604, 0x140);
    LoadBgMap(0, gUnk_096F6464, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 0x20);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5C64, 0x800);
    gSioChgConnectWork->unk_00 = 0;
    gSioChgConnectWork->unk_02 = 0;
    gSioChgConnectWork->state = 0;
    gSioChgConnectWork->textSlotCount = 0;
    InitTextSlots(gSioChgConnectWork->textSlots, 0x5A);
    gSioChgConnectWork->textSlotCount = LoadTextSlots(gUnk_08159EC4, gSioChgConnectWork->textSlots);
    gSioChgConnectWork->palette = LoadObjPalette(gUnk_096FBAA4, 32);
    SioReset();
    func_080C5A3C(func_080B1BE0, func_080B1BFC, 1);
}
#endif

#ifndef VERSION_EU
void mode_sio_chg_connect_1(void) {
    switch (gSioChgConnectWork->state) {
    case 0:
        func_080C54B4();
        break;
    case 1:
        func_080C54B4();
        gSioChgConnectWork->unk_02++;
        if (gSioChgConnectWork->unk_02 > 4) {
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
            gSystemFlags |= 1;
            gSystemFlags |= 0x10;
            func_080B1C14();
            return;
        }
        break;
    }
    DrawTextSlots(61, 68, gSioChgConnectWork->textSlots, gSioChgConnectWork->palette, 20, gSioChgConnectWork->textSlotCount);
}
#endif

#ifndef VERSION_EU
void mode_sio_chg_connect_2(void) {
    ReleaseObjPalette(gSioChgConnectWork->palette);
    FreeTextSlots(gSioChgConnectWork->textSlots, 0x5A);
    EwramFree(gSioChgConnectWork);
}
#endif

#ifndef VERSION_EU
void func_080B1BE0(void) {
    m4aSongNumStart(SONG_SYS_ITEMGET);
    gSioChgConnectWork->state++;
}
#endif

#ifndef VERSION_EU
void func_080B1BFC(void) {
    m4aSongNumStart(SONG_SYS_CLOSE);
    ModeRequest(&gModeSioBattle, 3);
}
#endif

#ifndef VERSION_EU
void func_080B1C14(void) {
    s32 i;

    if (gSioPlayerId == 0) {
        gUnk_0203AB10 = 0;
    } else {
        gUnk_0203AB10 = 5;
    }

    for (i = 0; i < 10; i++) {
        gUnk_0203AB20[i] = 0x800;
    }

    for (i = 0; i < 2; i++) {
        gUnk_0203AB34[i] = 0;
    }
    ModeRequest(&gModeSioChgCard, 0x800);
}
#endif

#ifndef VERSION_EU
void SetSioChgCardAnimation(u16 a, u16 b, u16 c) {
    const SioAnimDef* def = &gSioChgCardAnimDefs[b];
    AnimChangeWithTables(&gSioChgCardWork->anim[a], def->animId, c, def->anims, def->gfxTable);
    SetObjTileSource(gSioChgCardWork->unk_008[a], def->tiles);
}
#endif

#ifndef VERSION_EU
void mode_sio_chg_card_0(s32 arg) {
    gSioChgCardWork = EwramAlloc(sizeof(SioChgCardWork));
    SetBgMode0();
    SetupBg(0, 0, 7, 0);
    SetBgPriority(0, 0);
    SetBgOverflow(0, 1);
    SetBgSize(0, 0);
    SetupBg(1, 0, 15, 0);
    SetBgPriority(1, 1);
    SetBgOverflow(1, 1);
    SetBgSize(1, 0);
    SetupBg(2, 0, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, 1);
    SetBgSize(2, 0);
    RequestDma3Copy(gUnk_096B2BE4, GetBgCharBase(0), 0x2000);
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    gSioChgCardWork->unk_002 = 0;
    gSioChgCardWork->unk_004 = 0;
    gSioChgCardWork->unk_0A4 = 0;
    gSioChgCardWork->state = 0;
    gSioChgCardWork->unk_404 = 0;
    gSioChgCardWork->unk_BE0 = 0;
    gSioChgCardWork->unk_202 = arg;
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((arg + 1) & 0x0FFF);
}
#endif

#ifndef VERSION_EU
void func_080B1DDC(void) {
    RequestDma3Copy(gUnk_096B4BE4, (u8*)GetBgCharBase(0) + 0x2000, 0x11C0);
    LoadBgPalette(0, gUnk_096FBE24, 0xE0);
    LoadBgMap(0, gUnk_096FA464, 0x800);
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gSioChgCardWork->unk_202 + 1) & 0x0FFF);
    gSioChgCardWork->state++;
}
#endif

#ifndef VERSION_EU
void func_080B1E70(void) {
    s32 i;
    s16 n;
    FadeStartIn(0, 16);
    LoadBgMap(1, gUnk_096F9C64, 0x800);
    LoadBgMap(2, gUnk_096F9464, 0x800);
    DisableBg(0);
    EnableBg(1);
    EnableBg(2);
    gSioChgCardWork->unk_076 = gUnk_0203AB10;
    gSioChgCardWork->x = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_00;
    gSioChgCardWork->y = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_02;
    gSioChgCardWork->unk_078 = gSioChgCardWork->unk_076;
    gSioChgCardWork->unk_074 = 1;

    for (i = 0; i < 2; i++) {
        gSioChgCardWork->unk_008[i] = AllocObjTiles(0xC80, 0);
        AnimInit(&gSioChgCardWork->anim[i], 0, 0);

        if (gUnk_0203AB34[i] == 0) {
            SetSioChgCardAnimation(i, 0, 0);
        } else {
            SetSioChgCardAnimation(i, 2, 0);
        }
        gSioChgCardWork->gfx[i] = AnimGetGfx(&gSioChgCardWork->anim[i]);
    }

    if (gSioPlayerId == 0) {
        gSioChgCardWork->unk_008[2] = LoadObjPalette(gUnk_08F683A4, 32);
        gSioChgCardWork->unk_008[3] = LoadObjPalette(gUnk_096FAC64, 32);
    } else {
        gSioChgCardWork->unk_008[2] = LoadObjPalette(gUnk_096FAC64, 32);
        gSioChgCardWork->unk_008[3] = LoadObjPalette(gUnk_08F683A4, 32);
    }
    gSioChgCardWork->tiles = LoadObjTiles(gUnk_0962DEA8, 0x780);
    gSioChgCardWork->palette = LoadObjPalette(gUnk_096FBF04, 32);
    AnimInit(&gSioChgCardWork->anim2, gUnk_09EF3920, gUnk_09EF390C);
    AnimStart(&gSioChgCardWork->anim2, 0, 1);
    gSioChgCardWork->gfx2 = AnimGetGfx(&gSioChgCardWork->anim2);
    gSioChgCardWork->tiles2 = LoadObjTiles(gUnk_0962B090, 0x1C0);
    gSioChgCardWork->palette2 = LoadObjPalette(gUnk_096FBAA4, 32);
    AnimInit(&gSioChgCardWork->anim3, gUnk_09EF38B4, gUnk_09EF3894);
    AnimStart(&gSioChgCardWork->anim3, 0, 1);
    gSioChgCardWork->gfx3 = AnimGetGfx(&gSioChgCardWork->anim3);

    for (i = 0; i < 10; i++) {
        if (gUnk_0203AB20[i] == 0x800) {
            gSioChgCardWork->unk_0A5[i] = 0;
            gSioChgCardWork->x2[i] = gUnk_09EF150C[i].unk_00 << 8;
            gSioChgCardWork->y2[i] = gUnk_09EF150C[i].unk_02 << 8;
            gSioChgCardWork->tiles3[i] = LoadObjTiles(gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].tiles2, 0x200);
            gSioChgCardWork->palette3[i] = LoadObjPalette(gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].palette2, 32);
            gSioChgCardWork->gfx4[i] = gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].gfx2;
            gSioChgCardWork->gfx5[i] = gUnk_09EE981C[0];
            gSioChgCardWork->unk_1A8[i] = 0x100;
            gSioChgCardWork->unk_1D0[i] = 0x100;
            gSioChgCardWork->unk_1F8[i] = 0;
        } else {
            gSioChgCardWork->unk_0A5[i] = 1;
            gSioChgCardWork->x2[i] = gUnk_09EF150C[i].unk_00 << 8;
            gSioChgCardWork->y2[i] = gUnk_09EF150C[i].unk_02 << 8;
            n = gUnk_0203AB20[i];
            gSioChgCardWork->tiles3[i] = LoadObjTiles(gCardDefs[n].tiles2, 0x200);
            gSioChgCardWork->palette3[i] = LoadObjPalette(gCardDefs[n].palette2, 32);
            gSioChgCardWork->gfx4[i] = gCardDefs[n].gfx2;
            gSioChgCardWork->gfx5[i] = gUnk_09EE981C[gCardDefs[n].unk_20];
            gSioChgCardWork->unk_1A8[i] = 0x100;
            gSioChgCardWork->unk_1D0[i] = 0x100;
            gSioChgCardWork->unk_1F8[i] = 0;
        }
    }
    gSioChgCardWork->tiles4 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    gSioChgCardWork->palette4 = LoadObjPalette(gUnk_09611AB8, 32);
    gSioChgCardWork->tiles5 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    gSioChgCardWork->gfx6 = gUnk_09EF1278[0];
    gSioChgCardWork->unk_20C = 0;
    InitTextSlots(gSioChgCardWork->textSlots, 42);
    gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A394, gSioChgCardWork->textSlots);
    gSioChgCardWork->x3 = 68;
    gSioChgCardWork->y3 = 124;
    InitTextSlots(gSioChgCardWork->textSlots2, 20);
    gSioChgCardWork->textSlotCount2 = LoadTextSlots(gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].name, gSioChgCardWork->textSlots2);
    gSioChgCardWork->unk_360 = 0;
    TaskPoolInit(gSioChgCardWork->tasks, 11);
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gSioChgCardWork->unk_202 + 1) & 0x0FFF);
    gSioChgCardWork->state++;
}
#endif

#ifndef VERSION_EU
void mode_sio_chg_card_1(void) {
    switch (gSioChgCardWork->state) {
    case 0:
        func_080B1DDC();
        break;
    case 1:
        func_080B1E70();
        break;
    case 2:
        func_080B2420();
        func_080B2CD0();
        break;
    case 3:
        func_080B2480();
        func_080B2CD0();
        break;
    case 4:
        func_080B2788();
        func_080B2CD0();
        break;
    case 5:
        func_080B2854();
        func_080B2CD0();
        break;
    case 6:
        func_080B28A8();
        func_080B2CD0();
        break;
    case 7:
        func_080B298C();
        func_080B2CD0();
        break;
    case 8:
        func_080B29BC();
        func_080B2CD0();
        break;
    case 9:
        func_080B29D8();
        func_080B2CD0();
        break;
    case 10:
        func_080B2A5C();
        func_080B2CD0();
        break;
    case 11:
        func_080B2AE8();
        func_080B2CD0();
        break;
    case 12:
        func_080B2B48();
        func_080B2CD0();
        break;
    case 13:
        func_080B2B78();
        func_080B2CD0();
        break;
    }
}

void func_080B2420(void) {
    gSioChgCardWork->unk_004++;
    if (gSioChgCardWork->unk_004 > 5) {
        func_080B2FC0();
        func_080B3204();
        gSioChgCardWork->state++;
    }
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gSioChgCardWork->unk_202 + 1) & 0x0FFF);
}

void func_080B2480(void) {
    gUnk_02039B58[2] = (GetKeysPressed() & 0x0FFF) | 0x5000;
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gSioChgCardWork->unk_202 + 1) & 0x0FFF);

    if (gSioChgCardWork->unk_0A4 == 0) {
        func_080B3354();
    } else {
        func_080B3DF8();
        gUnk_02039B58[1] = 0x1AC7;
    }

    if (gUnk_02039810[1][0] == 0x1AC7) {
        if (gUnk_0203AB34[0] == 0) {
            SetSioChgCardAnimation(0, 1, 0);
            m4aSongNumStart(SONG_SYS_KETTEI);
        }
        RequestDma3Copy(gUnk_096B5FA4, (void*)0x06000020, 0xC0);
        gUnk_0203AB34[0] = 1;
    } else if (gUnk_02039810[1][0] == 0x2B9A) {
        if (gUnk_0203AB34[0] == 1) {
            SetSioChgCardAnimation(0, 0, 0);
            m4aSongNumStart(SONG_SYS_CLOSE);
            gSioChgCardWork->unk_20C = 0;
        }
        RequestDma3Copy(gUnk_096B5EE4, (void*)0x06000020, 0xC0);
        gUnk_0203AB34[0] = 0;
    }

    if (gUnk_02039810[1][1] == 0x1AC7) {
        if (gUnk_0203AB34[1] == 0) {
            SetSioChgCardAnimation(1, 1, 0);
            m4aSongNumStart(SONG_SYS_KETTEI);
        }
        RequestDma3Copy(gUnk_096B63A4, (void*)0x060000E0, 0xC0);
        gUnk_0203AB34[1] = 1;
    } else if (gUnk_02039810[1][1] == 0x2B9A) {
        if (gUnk_0203AB34[1] == 1) {
            SetSioChgCardAnimation(1, 0, 0);
            m4aSongNumStart(SONG_SYS_CLOSE);
            gSioChgCardWork->unk_20C = 0;
        }
        RequestDma3Copy(gUnk_096B62E4, (void*)0x060000E0, 0xC0);
        gUnk_0203AB34[1] = 0;
    }

    if (gUnk_0203AB34[0] == 1 && gUnk_0203AB34[1] == 1) {
        gSioChgCardWork->unk_004 = 0;
        m4aSongNumStart(SONG_SYS_ITEMGET);
        gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A3C0, gSioChgCardWork->textSlots);
        gSioChgCardWork->x3 = 64;
        gSioChgCardWork->y3 = 114;
        gSioChgCardWork->state++;
    }

    if (gUnk_02039810[1][0] == 0xA4CA || gUnk_02039810[1][1] == 0xA4CA) {
        if ((gUnk_02039810[2][0] & 0xF000) == 0x5000 && (gUnk_02039810[2][1] & 0xF000) == 0x5000 && gSioChgCardWork->unk_BE0 == 0) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            func_080B3DA0();
            func_080C57B4();
            ModeRequest(&gModeSioChgConnect, 3);
        }
    } else if (gUnk_02039810[1][0] == 0x1D58) {
        gSioChgCardWork->unk_BE0 = 10;

        if (gSioPlayerId == 0) {
            m4aSongNumStart(SONG_SYS_KETTEI);
            gUnk_0203AB10 = gSioChgCardWork->unk_076;
            ModeRequest(&gUnk_09EE8F20, 0);
        }
    } else if (gUnk_02039810[1][1] == 0x1D58) {
        gSioChgCardWork->unk_BE0 = 10;

        if (gSioPlayerId == 1) {
            m4aSongNumStart(SONG_SYS_KETTEI);
            gUnk_0203AB10 = gSioChgCardWork->unk_076;
            ModeRequest(&gUnk_09EE8F20, 0);
        }
    }
    func_080B2FC0();
    func_080B3204();

    if (gSioChgCardWork->unk_BE0 > 0) {
        gSioChgCardWork->unk_BE0--;
    }
}

void func_080B2788(void) {
    if (GetKeysPressed() & A_BUTTON) {
        gUnk_02039B58[1] = 0xEF01;
    } else if (GetKeysPressed() & B_BUTTON) {
        gUnk_02039B58[1] = 0x58FA;
    }

    if (gUnk_02039810[1][0] == 0xEF01 || gUnk_02039810[1][1] == 0xEF01) {
        gSioChgCardWork->unk_004 = 0;
        gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A404, gSioChgCardWork->textSlots);
        gSioChgCardWork->x3 = 71;
        gSioChgCardWork->y3 = 124;
        gSioChgCardWork->state++;
    }

    if (gUnk_02039810[1][0] == 0x58FA || gUnk_02039810[1][1] == 0x58FA) {
        m4aSongNumStart(SONG_SYS_CLOSE);
        gSioChgCardWork->unk_004 = 0;
        func_080B3A68();
        gSioChgCardWork->state = 3;
    }
    func_080B2FC0();
    func_080B3204();
}

void func_080B2854(void) {
    func_080B3C64();
    gSioChgCardWork->unk_404 = func_080B3D28();
    if (gSioChgCardWork->unk_404 == 1) {
        gUnk_02039B58[1] = 0xEF23;
    } else {
        gUnk_02039B58[1] = 0x1269;
    }
    gSioChgCardWork->state++;
}

void func_080B28A8(void) {
    if (gSioChgCardWork->unk_404 == 1) {
        gUnk_02039B58[1] = 0xEF23;
    } else {
        gUnk_02039B58[1] = 0x1269;
    }

    if (gUnk_02039810[1][0] == 0xEF23 && gUnk_02039810[1][1] == 0xEF23) {
        m4aSongNumStart(SONG_SYS_ITEMGET);
        gSioChgCardWork->unk_004 = 0;
        gGameState.progression.unk_34 = gSioChgCardWork->unk_BD4;
        gSioChgCardWork->state = 8;
    }

    if (gUnk_02039810[1][0] == 0x1269 || gUnk_02039810[1][1] == 0x1269) {
        m4aSongNumStart(SONG_SYS_BEEP);
        gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A4B6, gSioChgCardWork->textSlots);
        gSioChgCardWork->x3 = 63;
        gSioChgCardWork->y3 = 118;
        func_080B3CC0();
        gSioChgCardWork->unk_004 = 0;
        gSioChgCardWork->state = 7;
    }
}

void func_080B298C(void) {
    if (gSioChgCardWork->unk_004 > 179) {
        gSioChgCardWork->unk_004 = 0;
        func_080B3A68();
        gSioChgCardWork->state = 3;
    } else {
        gSioChgCardWork->unk_004++;
    }
}

void func_080B29BC(void) {
    func_080B3B5C();
    gSioChgCardWork->unk_004 = 0;
    gSioChgCardWork->state++;
}

void func_080B29D8(void) {
    TaskPoolUpdate(gSioChgCardWork->tasks);

    if (func_080C5930() == 0) {
        if (gUnk_0203A9E4 == 0) {
            if (gGameState.flags & 0x10) {
                SaveWriteFileLarge(1);
            } else {
                SaveWriteFileLarge(0);
            }
        }
    } else {
        gSystemFlags &= 0xFFFE;
        ModeRequest(&gModeSioError, 0);
    }
    gSioChgCardWork->unk_004 = 0;
    gSioChgCardWork->state++;
}

void func_080B2A5C(void) {
    TaskPoolUpdate(gSioChgCardWork->tasks);

    if (gSioChgCardWork->unk_004 == 80) {
        gSioChgCardWork->unk_20C = 0;
    }
    gSioChgCardWork->unk_004++;
    if (gSioChgCardWork->unk_004 > 199) {
        gSioChgCardWork->unk_004 = 0;
        gSioChgCardWork->unk_20C = 1;
        gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A428, gSioChgCardWork->textSlots);
        gSioChgCardWork->x3 = 70;
        gSioChgCardWork->y3 = 119;
        gSioChgCardWork->state++;
    }
}

void func_080B2AE8(void) {
    gSioChgCardWork->unk_004++;
    if (gSioChgCardWork->unk_004 > 119) {
        gSioChgCardWork->unk_004 = 0;
        gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815B3FA, gSioChgCardWork->textSlots);
        gSioChgCardWork->x3 = 83;
        gSioChgCardWork->y3 = 124;
        gSioChgCardWork->state++;
    }
}

void func_080B2B48(void) {
    gSioChgCardWork->unk_004++;
    if (gSioChgCardWork->unk_004 > 119) {
        gSioChgCardWork->unk_004 = 0;
        gSioChgCardWork->unk_20C = 0;
        gSioChgCardWork->state++;
    }
}

void func_080B2B78(void) {
    s32 i;
    gUnk_02039B58[1] = 0x25FD;

    if (gUnk_02039810[1][0] == 0x25FD || gUnk_02039810[1][1] == 0x25FD) {
        if (gSioPlayerId == 0) {
            gUnk_0203AB10 = 0;
        } else {
            gUnk_0203AB10 = 5;
        }

        for (i = 0; i < 10; i++) {
            gUnk_0203AB20[i] = 0x800;
        }
        gUnk_0203AB34[0] = 0;
        gUnk_0203AB34[1] = 0;
        ModeRequest(&gModeSioChgCard, 0x800);
    }
}

void mode_sio_chg_card_2(void) {
    s32 i;
    ReleaseObjTiles(gSioChgCardWork->unk_008[0]);
    ReleaseObjTiles(gSioChgCardWork->unk_008[1]);
    ReleaseObjPalette(gSioChgCardWork->unk_008[2]);
    ReleaseObjPalette(gSioChgCardWork->unk_008[3]);
    ReleaseObjTiles(gSioChgCardWork->tiles);
    ReleaseObjPalette(gSioChgCardWork->palette);
    ReleaseObjTiles(gSioChgCardWork->tiles2);
    ReleaseObjPalette(gSioChgCardWork->palette2);

    for (i = 0; i < 10; i++) {
        ReleaseObjTiles(gSioChgCardWork->tiles3[i]);
        ReleaseObjPalette(gSioChgCardWork->palette3[i]);
    }
    ReleaseObjTiles(gSioChgCardWork->tiles4);
    ReleaseObjPalette(gSioChgCardWork->palette4);
    ReleaseObjTiles(gSioChgCardWork->tiles5);
    FreeTextSlots(gSioChgCardWork->textSlots, 42);
    FreeTextSlots(gSioChgCardWork->textSlots2, 20);
    TaskPoolDestroy(gSioChgCardWork->tasks);
    EwramFree(gSioChgCardWork);
}

void func_080B2CD0(void) {
    s32 i;
    s32 aff;
    gSioChgCardWork->gfx[0] = AnimUpdate(&gSioChgCardWork->anim[0]);
    gSioChgCardWork->gfx[1] = AnimUpdate(&gSioChgCardWork->anim[1]);
    gSioChgCardWork->gfx2 = AnimUpdate(&gSioChgCardWork->anim2);
    gSioChgCardWork->gfx3 = AnimUpdate(&gSioChgCardWork->anim3);
    DrawSprite(72, 72, gSioChgCardWork->gfx[0], gSioChgCardWork->unk_008[0], gSioChgCardWork->unk_008[2], 0, 0x401, 0xFFFF);
    DrawSprite(168, 72, gSioChgCardWork->gfx[1], gSioChgCardWork->unk_008[1], gSioChgCardWork->unk_008[3], 0, 0x400, 0xFFFF);

    if (gSioChgCardWork->unk_074 == 1) {
        DrawSprite(gSioChgCardWork->x, gSioChgCardWork->y, gSioChgCardWork->gfx2, gSioChgCardWork->tiles, gSioChgCardWork->palette, 0, 0x400, 0xFFC0);
        DrawSprite(gSioChgCardWork->x + 2, gSioChgCardWork->y - 8, gSioChgCardWork->gfx3, gSioChgCardWork->tiles2, gSioChgCardWork->palette2, 0, 0x400, 0xFFA0);
    }

    for (i = 0; i < 10; i++) {
        if (gSioChgCardWork->unk_0A5[i] == 1) {
            aff = AllocObjAffine(gSioChgCardWork->unk_1F8[i], gSioChgCardWork->unk_1A8[i], gSioChgCardWork->unk_1D0[i], 1);
            DrawSprite((gSioChgCardWork->x2[i] >> 8) + 16, (gSioChgCardWork->y2[i] >> 8) + 20, gSioChgCardWork->gfx4[i], gSioChgCardWork->tiles3[i], gSioChgCardWork->palette3[i], aff, 0x400, 0xFFF0);

            if (gCardDefs[gUnk_0203AB20[i]].unk_2A != 3) {
                DrawSprite((gSioChgCardWork->x2[i] >> 8) + 13, (gSioChgCardWork->y2[i] >> 8) + 16, gSioChgCardWork->gfx5[i], gSioChgCardWork->tiles4, gSioChgCardWork->palette4, aff, 0x400, 0xFFE0);
            }
        }
    }

    if (gSioChgCardWork->unk_20C == 1) {
        DrawSprite(120, 131, gSioChgCardWork->gfx6, gSioChgCardWork->tiles5, gSioChgCardWork->palette4, 0, 0, 0xFF00);
        DrawTextSlots(gSioChgCardWork->x3, gSioChgCardWork->y3, gSioChgCardWork->textSlots, gSioChgCardWork->palette2, 20, gSioChgCardWork->textSlotCount);
    }

    if (gSioChgCardWork->unk_360 == 1) {
        DrawTextSlots(58, 27, gSioChgCardWork->textSlots2, gSioChgCardWork->palette, 18, gSioChgCardWork->textSlotCount2);
        DrawTextSlots(52, 42, gSioChgCardWork->textSlots, gSioChgCardWork->palette2, 18, gSioChgCardWork->textSlotCount);
    }
}

void func_080B2FC0(void) {
    if (gUnk_02039810[0][0] == 0xACD) {
        func_080B2FEC(gUnk_02039810[3][0]);
    }

    if (gUnk_02039810[0][1] == 0xACD) {
        func_080B2FEC(gUnk_02039810[3][1]);
    }
}

void func_080B2FEC(u16 a) {
    u16 slot;
    s32 i;

    if (a != 0) {
        i = a;
        i = i >> 12;
        slot = (a & 0x0FFF) - 1;
        if (slot == 0x800) {
            gSioChgCardWork->unk_0A5[i] = 0;
            ReleaseObjTiles(gSioChgCardWork->tiles3[i]);
            ReleaseObjPalette(gSioChgCardWork->palette3[i]);
            gSioChgCardWork->tiles3[i] = LoadObjTiles(gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].tiles2, 0x200);
            gSioChgCardWork->palette3[i] = LoadObjPalette(gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].palette2, 32);
            gSioChgCardWork->gfx4[i] = gCardDefs[CARD_ID(CARD_KINGDOM_KEY, 0)].gfx2;
            gSioChgCardWork->gfx5[i] = gUnk_09EE981C[0];
            gUnk_0203AB20[i] = slot;

            if (gSioChgCardWork->unk_360 == 1) {
                if (i == gSioChgCardWork->unk_076) {
                    func_080B3A48();
                }
            }
        } else {
            gSioChgCardWork->unk_0A5[i] = 1;
            ReleaseObjTiles(gSioChgCardWork->tiles3[i]);
            ReleaseObjPalette(gSioChgCardWork->palette3[i]);
            gSioChgCardWork->tiles3[i] = LoadObjTiles(gCardDefs[slot].tiles2, 0x200);
            gSioChgCardWork->palette3[i] = LoadObjPalette(gCardDefs[slot].palette2, 32);
            gSioChgCardWork->gfx4[i] = gCardDefs[slot].gfx2;
            gSioChgCardWork->gfx5[i] = gUnk_09EE981C[gCardDefs[slot].unk_20];
            gUnk_0203AB20[i] = slot;
        }
    }
}

void func_080B31A0(void) {
    gUnk_02039B58[2] = 0x6000;

    if (gUnk_02039810[0][0] == 0xACD) {
        func_080B31D8(gUnk_02039810[3][0]);
    }

    if (gUnk_02039810[0][1] == 0xACD) {
        func_080B31D8(gUnk_02039810[3][1]);
    }
}

void func_080B31D8(u16 a) {
    u16 slot;
    s32 i;

    if (a != 0) {
        i = a;
        i = i >> 12;
        slot = (a & 0x0FFF) - 1;
        if (slot == 0x800) {
            gUnk_0203AB20[i] = 0x800;
        } else {
            gUnk_0203AB20[i] = slot;
        }
    }
}

void func_080B3204(void) {
    u16 sum;
    s32 lim;
    s32 x;
    s32 i;
    s32 j;
    s16 digits[3];
    s32 v;

    sum = 0;
    lim = 0x800;
    for (i = 0; i < 5; i++) {
        x = gUnk_0203AB20[i];
        if ((s16)x != lim) {
            sum = GetCardMooglePointValue(x) - (0 - sum);
        }
    }
    v = (s16)sum;
    digits[0] = v / 100;
    v = v % 100;
    digits[1] = v / 10;
    v = v % 10;
    digits[2] = v;
    RequestDma3Copy(&gUnk_096B5DA4[digits[0] * 32], (void*)0x060001A0, 32);
    RequestDma3Copy(&gUnk_096B5DA4[digits[1] * 32], (void*)0x060001C0, 32);
    RequestDma3Copy(&gUnk_096B5DA4[digits[2] * 32], (void*)0x060001E0, 32);

    sum = 0;
    for (j = 5; j < 10; j++) {
        x = gUnk_0203AB20[j];
        if ((s16)x != 0x800) {
            sum = GetCardMooglePointValue(x) - (0 - sum);
        }
    }
    v = (s16)sum;
    digits[0] = v / 100;
    v = v % 100;
    digits[1] = v / 10;
    v = v % 10;
    digits[2] = v;
    RequestDma3Copy(&gUnk_096B5DA4[digits[0] * 32], (void*)0x06000200, 32);
    RequestDma3Copy(&gUnk_096B5DA4[digits[1] * 32], (void*)0x06000220, 32);
    RequestDma3Copy(&gUnk_096B5DA4[digits[2] * 32], (void*)0x06000240, 32);
}

void func_080B3354(void) {
    u16 k1;
    u16 k2;
    s16 v;
    k1 = GetKeysPressed();
    k2 = GetKeysPressed();

    if (gSioChgCardWork->unk_360 == 1) {
        if (GetKeysPressed() & B_BUTTON) {
            if (gSioChgCardWork->unk_360 == 1) {
                func_080B3A48();
            }
        }
    } else if (gSioPlayerId == 0) {
        if (k1 & DPAD_ANY) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        if (k1 & DPAD_UP) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_05;
        } else if (k1 & DPAD_DOWN) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_06;
        }

        if (k1 & DPAD_LEFT) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_07;
        } else if (k1 & DPAD_RIGHT) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_08;
        }

        if (gSioChgCardWork->unk_078 != 11) {
            gSioChgCardWork->unk_076 = gSioChgCardWork->unk_078;
        }

        if (k1 & START_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLICK);
            gSioChgCardWork->unk_078 = 10;
            gSioChgCardWork->unk_076 = 10;
        }
        gSioChgCardWork->x = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_00;
        gSioChgCardWork->y = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_02;
        v = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_04;

        if (k1 & A_BUTTON) {
            if (v == 2) {
                if (func_080B3908() == 1) {
                    gSioChgCardWork->unk_0A4 = 1;
                    gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A394, gSioChgCardWork->textSlots);
                    gSioChgCardWork->x3 = 68;
                    gSioChgCardWork->y3 = 124;
                    gSioChgCardWork->unk_20C = 1;
                } else {
                    m4aSongNumStart(SONG_SYS_BEEP);
                }
            } else if (gUnk_0203AB20[gSioChgCardWork->unk_076] == 0x800) {
                if (v == 0) {
                    gUnk_02039B58[1] = 0x1D58;
                }
            } else if (gSioChgCardWork->unk_360 == 0) {
                m4aSongNumStart(SONG_SYS_KETTEI);
                func_080B397C();
            }
        } else if (k1 & B_BUTTON) {
            if (func_080B3958() == 1) {
                gUnk_02039B58[1] = 0xA4CA;
            } else if (v == 0) {
                if (gUnk_0203AB20[gSioChgCardWork->unk_076] != 0x800) {
                    m4aSongNumStart(SONG_SYS_CLOSE);
                    func_080B38A4();
                }
            }
        }
    } else {
        if (k2 & DPAD_ANY) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        if (k2 & DPAD_UP) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_05;
        } else if (k2 & DPAD_DOWN) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_06;
        }

        if (k2 & DPAD_LEFT) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_07;
        } else if (k2 & DPAD_RIGHT) {
            gSioChgCardWork->unk_078 = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_08;
        }

        if (gSioChgCardWork->unk_078 != 10) {
            gSioChgCardWork->unk_076 = gSioChgCardWork->unk_078;
        }

        if (k2 & START_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLICK);
            gSioChgCardWork->unk_078 = 11;
            gSioChgCardWork->unk_076 = 11;
        }
        gSioChgCardWork->x = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_00;
        gSioChgCardWork->y = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_02;
        v = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_04;

        if (k2 & A_BUTTON) {
            if (v == 2) {
                if (func_080B3908() == 1) {
                    gSioChgCardWork->unk_0A4 = 1;
                    gSioChgCardWork->textSlotCount = LoadTextSlots(gUnk_0815A394, gSioChgCardWork->textSlots);
                    gSioChgCardWork->x3 = 68;
                    gSioChgCardWork->y3 = 124;
                    gSioChgCardWork->unk_20C = 1;
                } else {
                    m4aSongNumStart(SONG_SYS_BEEP);
                }
            } else if (gUnk_0203AB20[gSioChgCardWork->unk_076] == 0x800) {
                if (v == 1) {
                    gUnk_02039B58[1] = 0x1D58;
                }
            } else if (gSioChgCardWork->unk_360 == 0) {
                m4aSongNumStart(SONG_SYS_KETTEI);
                func_080B397C();
            }
        } else if (k2 & B_BUTTON) {
            if (func_080B3958() == 1) {
                gUnk_02039B58[1] = 0xA4CA;
            } else if (v == 1) {
                if (gUnk_0203AB20[gSioChgCardWork->unk_076] != 0x800) {
                    m4aSongNumStart(SONG_SYS_CLOSE);
                    func_080B38A4();
                }
            }
        }
    }

    if (gSioChgCardWork->unk_076 == 10) {
        gSioChgCardWork->unk_074 = 0;

        if (gFrameCounter % 10 == 0) {
            RequestDma3Copy(&gUnk_096B5EE4[gSioChgCardWork->unk_002 * 192], (void*)0x06000020, 0xC0);
            gSioChgCardWork->unk_002 = 1 - gSioChgCardWork->unk_002;
        }
    } else if (gSioChgCardWork->unk_076 == 11) {
        gSioChgCardWork->unk_074 = 0;

        if (gFrameCounter % 10 == 0) {
            RequestDma3Copy(&gUnk_096B62E4[gSioChgCardWork->unk_002 * 192], (void*)0x060000E0, 0xC0);
            gSioChgCardWork->unk_002 = 1 - gSioChgCardWork->unk_002;
        }
    } else {
        gSioChgCardWork->unk_074 = 1;
        RequestDma3Copy(gUnk_096B5EE4, (void*)0x06000020, 0xC0);
        RequestDma3Copy(gUnk_096B5EE4 + 0x400, (void*)0x060000E0, 0xC0);
    }
}

void func_080B38A4(void) {
    AddCardToCollection(gUnk_0203AB20[gSioChgCardWork->unk_076]);
    gUnk_0203AB20[gSioChgCardWork->unk_076] = 0x800;
    gUnk_0203AB10 = gSioChgCardWork->unk_076;
    gSioChgCardWork->unk_202 = 0x800;
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gSioChgCardWork->unk_202 + 1) & 0x0FFF);
}

s8 func_080B3908(void) {
    s32 i;

    if (gSioPlayerId == 0) {
        for (i = 0; i < 5; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                return 1;
            }
        }
    } else {
        for (i = 5; i < 10; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                return 1;
            }
        }
    }
    return 0;
}

s8 func_080B3958(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (gUnk_0203AB20[i] != 0x800) {
            return 0;
        }
    }
    return 1;
}

void func_080B397C(void) {
    s16 n;
    u32 off;
    u16 nameId;
    CardDef* defs;
    CardDef* def;

    n = gUnk_0203AB20[gSioChgCardWork->unk_076];
    defs = gCardDefs;
    def = &defs[n];
    off = def->unk_2A << 5;
    LoadPalette(gUnk_096FBF84 + off, (void*)0x050000A0, 32);
    LoadObjPaletteBank(((ObjPalette*)gSioChgCardWork->palette)->index, gUnk_096FBF04 + off);
    nameId = def->unk_1C;
    defs = (CardDef*)((u8*)defs + 12);
    gSioChgCardWork->textSlotCount2 = LoadTextSlots(defs[n].gfx, gSioChgCardWork->textSlots2);
    gSioChgCardWork->textSlotCount = LoadTextSlots((void*)gUnk_09EE8F48[nameId], gSioChgCardWork->textSlots);
    EnableBg(0);
    gSioChgCardWork->unk_360 = 1;
}

void func_080B3A48(void) {
    DisableBg(0);
    gSioChgCardWork->unk_360 = 0;
}

void func_080B3A68(void) {
    s8 v;

    gSioChgCardWork->unk_0A4 = 0;

    if (gSioPlayerId == 0) {
        gUnk_0203AB10 = 0;
    } else {
        gUnk_0203AB10 = 5;
    }

    v = gUnk_0203AB10;
    gSioChgCardWork->unk_076 = v;
    gSioChgCardWork->unk_078 = v;
    gSioChgCardWork->x = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_00;
    gSioChgCardWork->y = gUnk_09EF150C[gSioChgCardWork->unk_076].unk_02;
    gSioChgCardWork->unk_074 = 1;
    gSioChgCardWork->unk_202 = gUnk_0203AB20[gSioChgCardWork->unk_076];
    SetSioChgCardAnimation(0, 0, 0);
    SetSioChgCardAnimation(1, 0, 0);
    RequestDma3Copy(gUnk_096B5EE4, (void*)0x06000020, 0xC0);
    RequestDma3Copy(gUnk_096B5EE4 + 0x400, (void*)0x060000E0, 0xC0);
    gUnk_0203AB34[0] = 0;
    gUnk_0203AB34[1] = 0;
    gSioChgCardWork->unk_20C = 0;
}

void func_080B3B5C(void) {
    SioCardTaskArg arg;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (gUnk_0203AB20[i] != 0x800) {
            arg.unk_00 = &gSioChgCardWork->x2[i];
            arg.unk_04 = &gSioChgCardWork->y2[i];
            arg.unk_08 = &gSioChgCardWork->unk_1A8[i];
            arg.unk_0C = &gSioChgCardWork->unk_1D0[i];
            arg.unk_10 = &gSioChgCardWork->unk_1F8[i];
            arg.unk_14 = &gSioChgCardWork->unk_0A5[i];
            arg.unk_18 = 0xA000;
            arg.unk_1C = 0x800;
            arg.unk_20 = (5 - i) * 20;
            TaskCreate(gSioChgCardWork->tasks, &gTaskDescChgCardObj, &arg);
        }
    }

    for (i = 5; i < 10; i++) {
        if (gUnk_0203AB20[i] != 0x800) {
            arg.unk_00 = &gSioChgCardWork->x2[i];
            arg.unk_04 = &gSioChgCardWork->y2[i];
            arg.unk_08 = &gSioChgCardWork->unk_1A8[i];
            arg.unk_0C = &gSioChgCardWork->unk_1D0[i];
            arg.unk_10 = &gSioChgCardWork->unk_1F8[i];
            arg.unk_14 = &gSioChgCardWork->unk_0A5[i];
            arg.unk_18 = 0x4000;
            arg.unk_1C = 0x800;
            arg.unk_20 = (10 - i) * 20 + 10;
            TaskCreate(gSioChgCardWork->tasks, &gTaskDescChgCardObj, &arg);
        }
    }
}

void func_080B3C64(void) {
    u16 i;

    for (i = 0; i <= 0x3E6; i++) {
        gSioChgCardWork->unk_406[i] = gCardCollection[i];
    }
    gSioChgCardWork->unk_BD4 = gGameState.progression.unk_34;
}

void func_080B3CC0(void) {
    u16 i;

    for (i = 0; i <= 0x3E6; i++) {
        gCardCollection[i] = gSioChgCardWork->unk_406[i];
    }
    gGameState.progression.unk_34 = gSioChgCardWork->unk_BD4;
}

s16 func_080B3D28(void) {
    s32 i;
    s32 t;

    if (gSioPlayerId == 0) {
        for (i = 5; i < 10; i++) {
            t = gUnk_0203AB20[i] != 0x800;
            if (t) {
                if (AddCardToCollection(gUnk_0203AB20[i]) == -1) {
                    return 0;
                }
            }
        }
    } else {
        for (i = 0; i < 5; i++) {
            t = gUnk_0203AB20[i] != 0x800;
            if (t) {
                if (AddCardToCollection(gUnk_0203AB20[i]) == -1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void func_080B3DA0(void) {
    s32 i;

    if (gSioPlayerId == 0) {
        for (i = 0; i < 5; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                AddCardToCollection(gUnk_0203AB20[i]);
            }
        }
    } else {
        for (i = 5; i < 10; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                AddCardToCollection(gUnk_0203AB20[i]);
            }
        }
    }
}

void func_080B3DF8(void) {
}
#endif

void mode_sioError_0(s32 arg) {
    gSystemFlags |= 0x20;
    gSioErrorWork = EwramAlloc(sizeof(SioErrorWork));
    m4aMPlayAllStop();
    FadeStartIn(0, 16);
    func_080C57B4();
    SetBgMode0();
    SetupBg(0, 0, 7, 15);
    SetupBg(1, 1, 31, 0);
    SetBgSize(1, 0);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5C64, 0x800);
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
    gSioErrorWork->unk_00 = 0;
    gSioErrorWork->unk_02 = 0;
    gSioErrorWork->unk_04 = 0;
#ifdef VERSION_EU
    LoadBgPalette(0, gUnk_09611AB8, 32);
    LoadBgTiles(0, gUnk_0950E2F8, 0x140);
    if (gLanguage == 1 || gLanguage == 4) {
        LoadBgMap(0, gUnkEu_096C798C, 0x800);
        SetBgScroll(0, 0xFFE9, 0xFFCD);
    } else {
        LoadBgMap(0, gUnk_096112B8, 0x800);
        SetBgScroll(0, 0xFFE9, 0xFFD0);
    }
#elif defined(VERSION_JP)
    LoadBgTiles(0, gUnk_096AD604, 0x140);
    LoadBgMap(0, gUnk_096F6464, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 32);
#else
    LoadBgTiles(0, gUnk_0950E2F8, 0x140);
    LoadBgMap(0, gUnk_096112B8, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 32);
    SetBgScroll(0, 0xFFE9, 0xFFD0);
#endif
    InitTextSlots(gSioErrorWork->textSlots, SIO_ERROR_TEXT_SLOTS);
#ifdef VERSION_EU
    gSioErrorWork->textSlotCount = LoadTextSlots(eu_0805E924(gUnkEu_088920BC), gSioErrorWork->textSlots);
#elif defined(VERSION_JP)
    gSioErrorWork->textSlotCount = LoadTextSlots(gUnk_0814F180, gSioErrorWork->textSlots);
#else
    gSioErrorWork->textSlotCount = LoadTextSlots(gUnk_0815A2BE, gSioErrorWork->textSlots);
#endif
    gSioErrorWork->palette = LoadObjPalette(gUnk_096FBAA4, 32);
}

void mode_sioError_1(void) {
    func_080B3F24();
}

void func_080B3F24(void) {
#ifdef VERSION_JP
    DrawTextSlots(58, 62, gSioErrorWork->textSlots, gSioErrorWork->palette, 20, gSioErrorWork->textSlotCount);
#else
    DrawTextSlots(36, 57, gSioErrorWork->textSlots, gSioErrorWork->palette, 20, gSioErrorWork->textSlotCount);
#endif
}

void mode_sioError_2(void) {
    ReleaseObjPalette(gSioErrorWork->palette);
    FreeTextSlots(gSioErrorWork->textSlots, SIO_ERROR_TEXT_SLOTS);
    EwramFree(gSioErrorWork);
}

SioWorldEntry gSioWorldEntries[13] = {
#if defined(VERSION_US)
    {gUnk_08C94824, 16384, 0, gUnk_08EF6384, 4096, 0, gUnk_08F68C84, 224, 0, gUnk_0815A57C, 7, 0, 0},
    {gUnk_08C90824, 16384, 0, gUnk_08EF5384, 4096, 0, gUnk_08F68B84, 256, 0, gUnk_0815A56C, 3, 0, 36},
    {gUnk_08C88824, 16384, 0, gUnk_08EF3384, 4096, 0, gUnk_08F689C4, 192, 0, gUnk_0815A5AA, 4, 0, 32},
    {gUnk_08C7C824, 16384, 0, gUnk_08EF0384, 4096, 0, gUnk_08F686E4, 224, 0, gUnk_0815A54A, 6, 0, 16},
    {gUnk_08C84824, 16384, 0, gUnk_08EF2384, 4096, 0, gUnk_08F68904, 192, 0, gUnk_0815A534, 1, 0, 28},
    {gUnk_08C8C824, 16384, 0, gUnk_08EF4384, 4096, 0, gUnk_08F68A84, 256, 0, gUnk_0815A59A, 5, 0, 36},
    {gUnk_08C94824, 16384, 0, gUnk_08EF6384, 4096, 0, gUnk_08F68C84, 224, 0, gUnk_0815A57C, 7, 0, 18},
    {gUnk_08C98824, 16064, 0, gUnk_08EF7384, 4096, 0, gUnk_08F68D64, 320, 0, gUnk_0815A5BE, 8, 0, 26},
    {gUnk_08CA06E4, 16384, 0, gUnk_08EF9384, 4096, 0, gUnk_08F68FC4, 224, 0, gUnk_0815A5D4, 10, 0, 20},
    {gUnk_08C9C6E4, 16384, 0, gUnk_08EF8384, 4096, 0, gUnk_08F68EA4, 288, 0, gUnk_0815A62A, 9, 0, 18},
    {gUnk_08C78824, 16384, 0, gUnk_08EEF384, 4096, 0, gUnk_08F68624, 192, 0, gUnk_0815A518, 11, 0, 20},
    {gUnk_08CA46E4, 16384, 0, gUnk_08EFA384, 4096, 0, gUnk_08F690A4, 320, 0, gUnk_0815A60E, 13, 0, 22},
    {gUnk_08CA86E4, 16384, 0, gUnk_08EFB384, 4096, 0, gUnk_08F691E4, 224, 0, gUnk_0815A64A, 12, 0, 22},
#elif defined(VERSION_JP)
    {gUnk_08C94824, 16384, 0, gUnk_08EF6384, 4096, 0, gUnk_08F68C84, 224, 0, gUnkJp_0814E5B8, 7, 0, 0},
    {gUnk_08C90824, 16384, 0, gUnk_08EF5384, 4096, 0, gUnk_08F68B84, 256, 0, gUnkJp_0814E590, 3, 0, 28},
    {gUnk_08C88824, 16384, 0, gUnk_08EF3384, 4096, 0, gUnk_08F689C4, 192, 0, gUnkJp_0814E5E4, 4, 0, 20},
    {gUnk_08C7C824, 16384, 0, gUnk_08EF0384, 4096, 0, gUnk_08F686E4, 224, 0, gUnkJp_0814E5CC, 6, 0, 8},
    {gUnk_08C84824, 16384, 0, gUnk_08EF2384, 4096, 0, gUnk_08F68904, 192, 0, gUnkJp_0814E59C, 1, 0, 20},
    {gUnk_08C8C824, 16384, 0, gUnk_08EF4384, 4096, 0, gUnk_08F68A84, 256, 0, gUnkJp_0814E5AC, 5, 0, 28},
    {gUnk_08C94824, 16384, 0, gUnk_08EF6384, 4096, 0, gUnk_08F68C84, 224, 0, gUnkJp_0814E5B8, 7, 0, 16},
    {gUnk_08C98824, 16064, 0, gUnk_08EF7384, 4096, 0, gUnk_08F68D64, 320, 0, gUnkJp_0814E5F4, 8, 0, 26},
    {gUnk_08CA06E4, 16384, 0, gUnk_08EF9384, 4096, 0, gUnk_08F68FC4, 224, 0, gUnkJp_0814E618, 10, 0, 12},
    {gUnk_08C9C6E4, 16384, 0, gUnk_08EF8384, 4096, 0, gUnk_08F68EA4, 288, 0, gUnkJp_0814E62C, 9, 0, 2},
    {gUnk_08C78824, 16384, 0, gUnk_08EEF384, 4096, 0, gUnk_08F68624, 192, 0, gUnkJp_0814E57C, 11, 0, 12},
    {gUnk_08CA46E4, 16384, 0, gUnk_08EFA384, 4096, 0, gUnk_08F690A4, 320, 0, gUnkJp_0814E644, 13, 0, 12},
    {gUnk_08CA86E4, 16384, 0, gUnk_08EFB384, 4096, 0, gUnk_08F691E4, 224, 0, gUnkJp_0814E658, 12, 0, 34},
#elif defined(VERSION_EU)
    {gUnk_08C94824, 16384, 0, gUnk_08EF6384, 1312, 0, gUnk_08F68C84, 224, 0, &gUnkEu_0888E4C0, 7, 0, 0},
    {gUnk_08C90824, 16384, 0, gUnk_08EF5384, 1216, 0, gUnk_08F68B84, 256, 0, &gUnkEu_0888E3A0, 3, 0, 36},
    {gUnk_08C88824, 16384, 0, gUnk_08EF3384, 1620, 0, gUnk_08F689C4, 192, 0, &gUnkEu_0888E578, 4, 0, 32},
    {gUnk_08C7C824, 16384, 0, gUnk_08EF0384, 1164, 0, gUnk_08F686E4, 224, 0, &gUnkEu_0888E530, 6, 0, 16},
    {gUnk_08C84824, 16384, 0, gUnk_08EF2384, 1412, 0, gUnk_08F68904, 192, 0, &gUnkEu_0888E410, 1, 0, 28},
    {gUnk_08C8C824, 16384, 0, gUnk_08EF4384, 1692, 0, gUnk_08F68A84, 256, 0, &gUnkEu_0888E450, 5, 0, 36},
    {gUnk_08C94824, 16384, 0, gUnk_08EF6384, 1312, 0, gUnk_08F68C84, 224, 0, &gUnkEu_0888E4C0, 7, 0, 18},
    {gUnk_08C98824, 16064, 0, gUnk_08EF7384, 1020, 0, gUnk_08F68D64, 320, 0, &gUnkEu_0888E5DC, 8, 0, 26},
    {gUnk_08CA06E4, 16384, 0, gUnk_08EF9384, 1084, 0, gUnk_08F68FC4, 224, 0, &gUnkEu_0888E6BC, 10, 0, 20},
    {gUnk_08C9C6E4, 16384, 0, gUnk_08EF8384, 1112, 0, gUnk_08F68EA4, 288, 0, &gUnkEu_0888E72C, 9, 0, 18},
    {gUnk_08C78824, 16384, 0, gUnk_08EEF384, 1088, 0, gUnk_08F68624, 192, 0, &gUnkEu_0888E364, 11, 0, 20},
    {gUnk_08CA46E4, 16384, 0, gUnk_08EFA384, 1196, 0, gUnk_08F690A4, 320, 0, &gUnkEu_0888E78C, 13, 0, 22},
    {gUnk_08CA86E4, 16384, 0, gUnk_08EFB384, 868, 0, gUnk_08F691E4, 224, 0, &gUnkEu_0888E804, 12, 0, 22},
#endif
};

s8 gUnk_09EF14B8[12] = {
    0,
    0,
    4,
    8,
    12,
    16,
    21,
    26,
    30,
    34,
    38,
    42,
};

u16 gUnk_09EF14C4[12] = {
    0,
    65527,
    65528,
    65529,
    65530,
    65531,
    65532,
    65533,
    65534,
    65535,
    0,
    1,
};

Mode gModeSioBtlOption = {
    "mode_sio_btl_option",
    mode_sio_btl_option_0,
    mode_sio_btl_option_1,
    mode_sio_btl_option_2,
};

Mode gModeSioBtlCardget = {
    "mode_sio_btl_cardget",
    mode_sio_btl_cardget_0,
    mode_sio_btl_cardget_1,
    mode_sio_btl_cardget_2,
};

#ifndef VERSION_EU
Mode gModeSioChgConnect = {
    "mode_sio_chg_connect",
    mode_sio_chg_connect_0,
    mode_sio_chg_connect_1,
    mode_sio_chg_connect_2,
};

SioChgCardPos gUnk_09EF150C[13] = {
    {16, 76, 0, 10, 1, 9, 2, {0, 0, 0}},
    {30, 105, 0, 0, 10, 8, 3, {0, 0, 0}},
    {43, 76, 0, 10, 3, 0, 4, {0, 0, 0}},
    {57, 105, 0, 2, 10, 1, 6, {0, 0, 0}},
    {70, 76, 0, 10, 3, 2, 5, {0, 0, 0}},
    {139, 76, 1, 11, 6, 4, 7, {0, 0, 0}},
    {153, 105, 1, 7, 11, 3, 8, {0, 0, 0}},
    {166, 76, 1, 11, 6, 5, 9, {0, 0, 0}},
    {180, 105, 1, 9, 11, 6, 1, {0, 0, 0}},
    {193, 76, 1, 11, 8, 7, 0, {0, 0, 0}},
    {0, 0, 2, 1, 0, 10, 10, {0, 0, 0}},
    {0, 0, 2, 8, 9, 11, 11, {0, 0, 0}},
    {0, 0, 0, 0, 0, 0, 0, {0, 0, 0}},
};
#endif

#ifndef VERSION_EU
const SioAnimDef gSioChgCardAnimDefs[3] = {
    {gUnk_09EDE99C, gUnk_09EDE9CC, gUnk_088BF162, 0},
    {gUnk_09EDEC88, gUnk_09EDEC9C, gUnk_088D702C, 0},
    {gUnk_09EDEC88, gUnk_09EDEC9C, gUnk_088D702C, 1},
};
#endif

#ifndef VERSION_EU
Mode gModeSioChgCard = {
    "mode_sio_chg_card",
    mode_sio_chg_card_0,
    mode_sio_chg_card_1,
    mode_sio_chg_card_2,
};
#endif

Mode gModeSioError = {
    "mode_sioError",
    mode_sioError_0,
    mode_sioError_1,
    mode_sioError_2,
};
