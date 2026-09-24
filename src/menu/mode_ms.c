#include <stddef.h>
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "mode_ms_api.h"
#include "display.h"
#include "text.h"
#include "monsgage.h"
#include "mode_ms.h"
#include "gba/keys.h"
#include "moogle_assets.h"
#include "localized_resource_assets.h"
#include "sprites_moogle_shop.h"
#include "sprites_card_pictures.h"

#ifdef VERSION_EU
#define LANGSTR(x) (((void**)(x))[gLanguage])
#define LANGSEL(x) eu_0805E924(x)
#else
#define LANGSTR(x) (x)
#define LANGSEL(x) (x)
#endif

#ifdef VERSION_EU
void* gUnkEu_09F84F5C[5] = {
    gUnkEu_09A8DAA0,
    gUnk_09A3B25C,
    gUnkEu_09A91920,
    gUnkEu_09A91420,
    gUnk_09A3B75C,
};

u16* gUnkEu_09F84F70[5] = {
    (u16*)gMoogleAssetEu_09A8F3A0,
    (u16*)gMoogleAssetEu_09A8F3A0,
    (u16*)gMoogleAssetEu_09A92E20,
    (u16*)gMoogleAssetEu_09A92620,
    (u16*)gMoogleAssetEu_09A91E20,
};

u16* gUnkEu_09F84F84[5] = {
    (u16*)gMoogleAssetEu_09A8FBA0,
    (u16*)gMoogleAssetEu_09A8FBA0,
    (u16*)gMoogleAssetEu_09A94620,
    (u16*)gMoogleAssetEu_09A93E20,
    (u16*)gMoogleAssetEu_09A93620,
};
#endif

const MooglePackMenuEntry gMooglePackMenuEntries[4] = {
#if defined(VERSION_US)
    {-1, 2, 5, 1, 67, 16, gMoogleAssetUs_09A387DC, 1280, 5, 3, 40, 24, 0, {{(u16*)gMoogleAssetUs_09A39BDC, 0, 0}, {(u16*)gMoogleAssetUs_09A39BDC, 0, 16}, {(u16*)gMoogleAssetUs_09A3A3DC, 0, 0}, {(u16*)gMoogleAssetUs_09A3A3DC, 0, 16}}},
    {-1, 3, 0, -1, 163, 16, gMoogleAssetUs_09A38CDC, 1280, 17, 3, 136, 24, 0, {{(u16*)gMoogleAssetUs_09A39BDC, 12, 0}, {(u16*)gMoogleAssetUs_09A39BDC, 12, 16}, {(u16*)gMoogleAssetUs_09A3A3DC, 12, 0}, {(u16*)gMoogleAssetUs_09A3A3DC, 12, 16}}},
    {0, -1, 5, 3, 67, 80, gMoogleAssetUs_09A391DC, 1280, 5, 11, 40, 88, 0, {{(u16*)gMoogleAssetUs_09A39BDC, 0, 8}, {(u16*)gMoogleAssetUs_09A39BDC, 0, 24}, {(u16*)gMoogleAssetUs_09A3A3DC, 0, 8}, {(u16*)gMoogleAssetUs_09A3A3DC, 0, 24}}},
    {1, -1, 2, -1, 163, 80, gMoogleAssetUs_09A396DC, 1280, 17, 11, 136, 88, 0, {{(u16*)gMoogleAssetUs_09A39BDC, 12, 8}, {(u16*)gMoogleAssetUs_09A39BDC, 12, 24}, {(u16*)gMoogleAssetUs_09A3A3DC, 12, 8}, {(u16*)gMoogleAssetUs_09A3A3DC, 12, 24}}},
#elif defined(VERSION_JP)
    {-1, 2, 5, 1, 67, 16, gMoogleAssetJp_099ED264, 1280, 5, 3, 40, 24, 0, {{(u16*)gMoogleAssetJp_099EE664, 0, 0}, {(u16*)gMoogleAssetJp_099EE664, 0, 16}, {(u16*)gMoogleAssetJp_099EEE64, 0, 0}, {(u16*)gMoogleAssetJp_099EEE64, 0, 16}}},
    {-1, 3, 0, -1, 163, 16, gMoogleAssetJp_099ED764, 1280, 17, 3, 136, 24, 0, {{(u16*)gMoogleAssetJp_099EE664, 12, 0}, {(u16*)gMoogleAssetJp_099EE664, 12, 16}, {(u16*)gMoogleAssetJp_099EEE64, 12, 0}, {(u16*)gMoogleAssetJp_099EEE64, 12, 16}}},
    {0, -1, 5, 3, 67, 80, gMoogleAssetJp_099EDC64, 1280, 5, 11, 40, 88, 0, {{(u16*)gMoogleAssetJp_099EE664, 0, 8}, {(u16*)gMoogleAssetJp_099EE664, 0, 24}, {(u16*)gMoogleAssetJp_099EEE64, 0, 8}, {(u16*)gMoogleAssetJp_099EEE64, 0, 24}}},
    {1, -1, 2, -1, 163, 80, gMoogleAssetJp_099EE164, 1280, 17, 11, 136, 88, 0, {{(u16*)gMoogleAssetJp_099EE664, 12, 8}, {(u16*)gMoogleAssetJp_099EE664, 12, 24}, {(u16*)gMoogleAssetJp_099EEE64, 12, 8}, {(u16*)gMoogleAssetJp_099EEE64, 12, 24}}},
#elif defined(VERSION_EU)
    {-1, 2, 5, 1, 67, 16, gMoogleAssetEu_09A8DFA0, 1280, 5, 3, 40, 24, 0, {{gUnkEu_09F84F70, 0, 0}, {gUnkEu_09F84F70, 0, 16}, {gUnkEu_09F84F84, 0, 0}, {gUnkEu_09F84F84, 0, 16}}},
    {-1, 3, 0, -1, 163, 16, gMoogleAssetEu_09A8E4A0, 1280, 17, 3, 136, 24, 0, {{gUnkEu_09F84F70, 12, 0}, {gUnkEu_09F84F70, 12, 16}, {gUnkEu_09F84F84, 12, 0}, {gUnkEu_09F84F84, 12, 16}}},
    {0, -1, 5, 3, 67, 80, gMoogleAssetEu_09A8E9A0, 1280, 5, 11, 40, 88, 0, {{gUnkEu_09F84F70, 0, 8}, {gUnkEu_09F84F70, 0, 24}, {gUnkEu_09F84F84, 0, 8}, {gUnkEu_09F84F84, 0, 24}}},
    {1, -1, 2, -1, 163, 80, gMoogleAssetEu_09A8EEA0, 1280, 17, 11, 136, 88, 0, {{gUnkEu_09F84F70, 12, 8}, {gUnkEu_09F84F70, 12, 24}, {gUnkEu_09F84F84, 12, 8}, {gUnkEu_09F84F84, 12, 24}}},
#endif
};

const MooglePackSpriteDef gMooglePackSpriteDefs[4] = {
#if defined(VERSION_US)
    {gMoogleAssetUs_09A3DA9C, 32, {0, 0}, gMoogleAssetUs_099A3EC4, 800, {0, 0}, gMoogleAssetUs_099A3EA4, 10, 12},
    {gMoogleAssetUs_09A3DABC, 32, {0, 0}, gMoogleAssetUs_099A4204, 608, {0, 0}, gMoogleAssetUs_099A41E4, 12, 13},
    {gMoogleAssetUs_09A3DADC, 32, {0, 0}, gMoogleAssetUs_099A4484, 608, {0, 0}, gMoogleAssetUs_099A4464, 12, 13},
    {gMoogleAssetUs_09A3DAFC, 32, {0, 0}, gMoogleAssetUs_099A4704, 896, {0, 0}, gMoogleAssetUs_099A46E4, 9, 7},
#elif defined(VERSION_JP)
    {gMoogleAssetJp_099F2524, 32, {0, 0}, gMoogleAssetJp_0995894C, 800, {0, 0}, gMoogleAssetJp_0995892C, 10, 12},
    {gMoogleAssetJp_099F2544, 32, {0, 0}, gMoogleAssetJp_09958C8C, 608, {0, 0}, gMoogleAssetJp_09958C6C, 12, 13},
    {gMoogleAssetJp_099F2564, 32, {0, 0}, gMoogleAssetJp_09958F0C, 608, {0, 0}, gMoogleAssetJp_09958EEC, 12, 13},
    {gMoogleAssetJp_099F2584, 32, {0, 0}, gMoogleAssetJp_0995918C, 896, {0, 0}, gMoogleAssetJp_0995916C, 9, 7},
#elif defined(VERSION_EU)
    {gMoogleAssetEu_09A9B560, 32, {0, 0}, gMoogleAssetEu_099B1E48, 800, {0, 0}, gMoogleAssetEu_099B1E28, 10, 12},
    {gMoogleAssetEu_09A9B580, 32, {0, 0}, gMoogleAssetEu_099B2188, 608, {0, 0}, gMoogleAssetEu_099B2168, 12, 13},
    {gMoogleAssetEu_09A9B5A0, 32, {0, 0}, gMoogleAssetEu_099B2408, 608, {0, 0}, gMoogleAssetEu_099B23E8, 12, 13},
    {gMoogleAssetEu_09A9B5C0, 32, {0, 0}, gMoogleAssetEu_099B2688, 896, {0, 0}, gMoogleAssetEu_099B2668, 9, 7},
#endif
};

const u16 gUnk_09993334[10] = {
    5,
    15,
    15,
    16,
    14,
    10,
    10,
    6,
    5,
    4,
};

const MooglePackCardDef gUnk_09993348[17] = {
#if defined(VERSION_US)
    {0, {0, 0}, NULL, {0, 0, 0, 0}},
    {10, {0, 0}, gMoogleAssetUs_00000001, {20, 14, 4, 4}},
    {30, {0, 0}, gMoogleAssetUs_00000003, {20, 14, 4, 4}},
    {50, {0, 0}, gMoogleAssetUs_00000005, {20, 14, 4, 4}},
    {100, {0, 0}, gMoogleAssetUs_0000000A, {20, 14, 4, 4}},
    {80, {0, 0}, gMoogleAssetUs_00000008, {20, 14, 4, 4}},
    {70, {0, 0}, gMoogleAssetUs_00000007, {0, 5, 10, 6}},
    {20, {0, 0}, gMoogleAssetUs_00000002, {0, 5, 10, 6}},
    {40, {0, 0}, gMoogleAssetUs_00000004, {0, 5, 10, 6}},
    {90, {0, 0}, gMoogleAssetUs_00000009, {0, 5, 10, 6}},
    {60, {0, 0}, gMoogleAssetUs_00000006, {0, 5, 10, 6}},
    {110, {0, 0}, gMoogleAssetUs_0000000B, {0, 5, 10, 6}},
    {120, {0, 0}, gMoogleAssetUs_0000000C, {0, 0, 5, 10}},
    {130, {0, 0}, gMoogleAssetUs_0000000D, {0, 0, 5, 10}},
    {140, {0, 0}, gMoogleAssetUs_0000000F, {0, 0, 5, 10}},
    {150, {0, 0}, gMoogleAssetUs_00000010, {0, 0, 5, 10}},
    {160, {0, 0}, gMoogleAssetUs_0000000E, {0, 0, 0, 4}},
#elif defined(VERSION_JP)
    {0, {0, 0}, NULL, {0, 0, 0, 0}},
    {10, {0, 0}, gMoogleAssetJp_00000001, {20, 14, 4, 4}},
    {30, {0, 0}, gMoogleAssetJp_00000003, {20, 14, 4, 4}},
    {50, {0, 0}, gMoogleAssetJp_00000005, {20, 14, 4, 4}},
    {100, {0, 0}, gMoogleAssetJp_0000000A, {20, 14, 4, 4}},
    {80, {0, 0}, gMoogleAssetJp_00000008, {20, 14, 4, 4}},
    {70, {0, 0}, gMoogleAssetJp_00000007, {0, 5, 10, 6}},
    {20, {0, 0}, gMoogleAssetJp_00000002, {0, 5, 10, 6}},
    {40, {0, 0}, gMoogleAssetJp_00000004, {0, 5, 10, 6}},
    {90, {0, 0}, gMoogleAssetJp_00000009, {0, 5, 10, 6}},
    {60, {0, 0}, gMoogleAssetJp_00000006, {0, 5, 10, 6}},
    {110, {0, 0}, gMoogleAssetJp_0000000B, {0, 5, 10, 6}},
    {120, {0, 0}, gMoogleAssetJp_0000000C, {0, 0, 5, 10}},
    {130, {0, 0}, gMoogleAssetJp_0000000D, {0, 0, 5, 10}},
    {140, {0, 0}, gMoogleAssetJp_0000000F, {0, 0, 5, 10}},
    {150, {0, 0}, gMoogleAssetJp_00000010, {0, 0, 5, 10}},
    {160, {0, 0}, gMoogleAssetJp_0000000E, {0, 0, 0, 4}},
#elif defined(VERSION_EU)
    {0, {0, 0}, NULL, {0, 0, 0, 0}},
    {10, {0, 0}, gMoogleAssetEu_00000001, {20, 14, 4, 4}},
    {30, {0, 0}, gMoogleAssetEu_00000003, {20, 14, 4, 4}},
    {50, {0, 0}, gMoogleAssetEu_00000005, {20, 14, 4, 4}},
    {100, {0, 0}, gMoogleAssetEu_0000000A, {20, 14, 4, 4}},
    {80, {0, 0}, gMoogleAssetEu_00000008, {20, 14, 4, 4}},
    {70, {0, 0}, gMoogleAssetEu_00000007, {0, 5, 10, 6}},
    {20, {0, 0}, gMoogleAssetEu_00000002, {0, 5, 10, 6}},
    {40, {0, 0}, gMoogleAssetEu_00000004, {0, 5, 10, 6}},
    {90, {0, 0}, gMoogleAssetEu_00000009, {0, 5, 10, 6}},
    {60, {0, 0}, gMoogleAssetEu_00000006, {0, 5, 10, 6}},
    {110, {0, 0}, gMoogleAssetEu_0000000B, {0, 5, 10, 6}},
    {120, {0, 0}, gMoogleAssetEu_0000000C, {0, 0, 5, 10}},
    {130, {0, 0}, gMoogleAssetEu_0000000D, {0, 0, 5, 10}},
    {140, {0, 0}, gMoogleAssetEu_0000000F, {0, 0, 5, 10}},
    {150, {0, 0}, gMoogleAssetEu_00000010, {0, 0, 5, 10}},
    {160, {0, 0}, gMoogleAssetEu_0000000E, {0, 0, 0, 4}},
#endif
};

const MooglePackCardDef gUnk_09993458[14] = {
#if defined(VERSION_US)
    {170, {0, 0}, gMoogleAssetUs_00000011, {15, 10, 5, 5}},
    {180, {0, 0}, gMoogleAssetUs_00000012, {15, 10, 5, 5}},
    {190, {0, 0}, gMoogleAssetUs_00000013, {15, 10, 5, 5}},
    {210, {0, 0}, gMoogleAssetUs_00000015, {0, 5, 10, 5}},
    {220, {0, 0}, gMoogleAssetUs_00000016, {0, 5, 10, 5}},
    {230, {0, 0}, gMoogleAssetUs_00000017, {0, 5, 10, 5}},
    {200, {0, 0}, gMoogleAssetUs_00000014, {10, 5, 0, 0}},
    {260, {0, 0}, gMoogleAssetUs_00000018, {20, 5, 5, 5}},
    {270, {0, 0}, gMoogleAssetUs_00000019, {10, 20, 8, 10}},
    {280, {0, 0}, gNumMusicPlayers, {0, 0, 8, 10}},
    {290, {0, 0}, gMoogleAssetUs_0000001B, {10, 20, 8, 10}},
    {300, {0, 0}, gMoogleAssetUs_0000001C, {0, 0, 8, 10}},
    {310, {0, 0}, gMoogleAssetUs_0000001D, {0, 0, 8, 10}},
    {320, {0, 0}, gMoogleAssetUs_0000001E, {5, 5, 10, 15}},
#elif defined(VERSION_JP)
    {170, {0, 0}, gMoogleAssetJp_00000011, {15, 10, 5, 5}},
    {180, {0, 0}, gMoogleAssetJp_00000012, {15, 10, 5, 5}},
    {190, {0, 0}, gMoogleAssetJp_00000013, {15, 10, 5, 5}},
    {210, {0, 0}, gMoogleAssetJp_00000015, {0, 5, 10, 5}},
    {220, {0, 0}, gMoogleAssetJp_00000016, {0, 5, 10, 5}},
    {230, {0, 0}, gMoogleAssetJp_00000017, {0, 5, 10, 5}},
    {200, {0, 0}, gMoogleAssetJp_00000014, {10, 5, 0, 0}},
    {260, {0, 0}, gMoogleAssetJp_00000018, {20, 5, 5, 5}},
    {270, {0, 0}, gMoogleAssetJp_00000019, {10, 20, 8, 10}},
    {280, {0, 0}, gNumMusicPlayers, {0, 0, 8, 10}},
    {290, {0, 0}, gMoogleAssetJp_0000001B, {10, 20, 8, 10}},
    {300, {0, 0}, gMoogleAssetJp_0000001C, {0, 0, 8, 10}},
    {310, {0, 0}, gMoogleAssetJp_0000001D, {0, 0, 8, 10}},
    {320, {0, 0}, gMoogleAssetJp_0000001E, {5, 5, 10, 15}},
#elif defined(VERSION_EU)
    {170, {0, 0}, gMoogleAssetEu_00000011, {15, 10, 5, 5}},
    {180, {0, 0}, gMoogleAssetEu_00000012, {15, 10, 5, 5}},
    {190, {0, 0}, gMoogleAssetEu_00000013, {15, 10, 5, 5}},
    {210, {0, 0}, gMoogleAssetEu_00000015, {0, 5, 10, 5}},
    {220, {0, 0}, gMoogleAssetEu_00000016, {0, 5, 10, 5}},
    {230, {0, 0}, gMoogleAssetEu_00000017, {0, 5, 10, 5}},
    {200, {0, 0}, gMoogleAssetEu_00000014, {10, 5, 0, 0}},
    {260, {0, 0}, gMoogleAssetEu_00000018, {20, 5, 5, 5}},
    {270, {0, 0}, gMoogleAssetEu_00000019, {10, 20, 8, 10}},
    {280, {0, 0}, gNumMusicPlayers, {0, 0, 8, 10}},
    {290, {0, 0}, gMoogleAssetEu_0000001B, {10, 20, 8, 10}},
    {300, {0, 0}, gMoogleAssetEu_0000001C, {0, 0, 8, 10}},
    {310, {0, 0}, gMoogleAssetEu_0000001D, {0, 0, 8, 10}},
    {320, {0, 0}, gMoogleAssetEu_0000001E, {5, 5, 10, 15}},
#endif
};

const MooglePackCardDef gUnk_09993538[7] = {
#if defined(VERSION_US)
    {380, {0, 0}, gMoogleAssetUs_0000001F, {50, 40, 0, 0}},
    {410, {0, 0}, gMoogleAssetUs_00000022, {50, 40, 20, 15}},
    {390, {0, 0}, gMoogleAssetUs_00000020, {0, 10, 25, 20}},
    {420, {0, 0}, gMoogleAssetUs_00000023, {0, 10, 25, 20}},
    {400, {0, 0}, gMoogleAssetUs_00000021, {0, 0, 15, 20}},
    {430, {0, 0}, gMoogleAssetUs_00000024, {0, 0, 15, 15}},
    {440, {0, 0}, gMoogleAssetUs_00000025, {0, 0, 0, 10}},
#elif defined(VERSION_JP)
    {380, {0, 0}, gMoogleAssetJp_0000001F, {50, 40, 0, 0}},
    {410, {0, 0}, gMoogleAssetJp_00000022, {50, 40, 20, 15}},
    {390, {0, 0}, gMoogleAssetJp_00000020, {0, 10, 25, 20}},
    {420, {0, 0}, gMoogleAssetJp_00000023, {0, 10, 25, 20}},
    {400, {0, 0}, gMoogleAssetJp_00000021, {0, 0, 15, 20}},
    {430, {0, 0}, gMoogleAssetJp_00000024, {0, 0, 15, 15}},
    {440, {0, 0}, gMoogleAssetJp_00000025, {0, 0, 0, 10}},
#elif defined(VERSION_EU)
    {380, {0, 0}, gMoogleAssetEu_0000001F, {50, 40, 0, 0}},
    {410, {0, 0}, gMoogleAssetEu_00000022, {50, 40, 20, 15}},
    {390, {0, 0}, gMoogleAssetEu_00000020, {0, 10, 25, 20}},
    {420, {0, 0}, gMoogleAssetEu_00000023, {0, 10, 25, 20}},
    {400, {0, 0}, gMoogleAssetEu_00000021, {0, 0, 15, 20}},
    {430, {0, 0}, gMoogleAssetEu_00000024, {0, 0, 15, 15}},
    {440, {0, 0}, gMoogleAssetEu_00000025, {0, 0, 0, 10}},
#endif
};

const MooglePackCardTable gMooglePackCardTables[3] = {
    {gUnk_09993348, 17, {0, 0}},
    {gUnk_09993458, 14, {0, 0}},
    {gUnk_09993538, 7, {0, 0}},
};

const s16 gUnk_099935C0[13][4][4] = {
    {{0, 0, -1, -1}, {0, 0, -1, -1}, {0, 0, -1, -1}, {0, 0, -1, -1}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}},
    {{0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}},
    {{0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}},
    {{0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 1, 1, 2}},
    {{0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}},
    {{0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}},
    {{0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}},
};

const s16 gUnk_09993760[4][4] = {
    {100, 200, 300, 500},
    {200, 250, 270, 300},
    {150, 200, 300, 350},
    {150, 200, 300, 400},
};

static MooglePackCardWork gUnk_020358C8[5];
static struct ObjPalette* gUnk_02035A30;
static struct ObjTiles* gUnk_02035A34;
static struct ObjPalette* gUnk_02035A38;
static struct ObjTiles* gUnk_02035A3C;
static struct ObjPalette* gUnk_02035A40;
static void* gUnk_02035A44;
static u8 gUnk_02035A48;
static void* gUnk_02035A4C;
static u8 gUnk_02035A50;
static struct ObjTiles* gUnk_02035A54;
static AnimState gUnk_02035A58;
static TaskPool gUnk_02035A70[5];
static s32 gUnk_02035AD4;
static s32 gUnk_02035AD8;
static struct ObjTiles* gUnk_02035ADC;
static struct ObjPalette* gUnk_02035AE0;
static AnimState gUnk_02035AE8;
static u8 gUnk_02035B00;
static s16 gUnk_02035B02;
static s16 gUnk_02035B04;
static s16 gUnk_02035B08[4];
static s16 gUnk_02035B10;
static s16 gUnk_02035B18[4][4][2];
static u16 gUnk_02035B58[5];
static s16 gUnk_02035B62;
static u16 gUnk_02035B68[32];
static u16 gUnk_02035BA8[2];
static struct ObjTiles* gUnk_02035BAC;
static struct ObjPalette* gUnk_02035BB0;
static AnimState gUnk_02035BB8;
static void* gUnk_02035BD0[4];
static void* gUnk_02035BE0[4];
static void* gUnk_02035BF0[4];
static u16* gUnk_02035C00;
static s32 gUnk_02035C04;
static s32 gUnk_02035C08;
static u8 gUnk_02035C0C;

void func_081025AC(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        gUnk_02035B68[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        gUnk_02035BA8[i] = 0;
    }
}

void func_081025D4(void* a) {
    u16* p = a;
    s32 i;

    for (i = 0; i < 32; i++) {
        p[i] = gUnk_02035B68[i];
    }

    for (i = 0; i < 2; i++) {
        p[i + 32] = gUnk_02035BA8[i];
    }
}

void func_08102610(void* a) {
    u16* p = a;
    s32 i;

    for (i = 0; i < 32; i++) {
        gUnk_02035B68[i] = p[i];
    }

    for (i = 0; i < 2; i++) {
        gUnk_02035BA8[i] = p[i + 32];
    }
}

void func_0810264C(u16 a, u16 b, u16 c) {
    u16 v;
    v = a * 16 + b * 4 + c;

    if (v <= 0x1FF) {
        gUnk_02035B68[v >> 4] |= 1 << (v & 15);
    }
}

void func_08102688(u16 a, u16 b, u16 c) {
    u16 v;
    v = a * 16 + b * 4 + c;

    if (v <= 0x1FF) {
        gUnk_02035B68[v >> 4] &= ~(1 << (v & 15));
    }
}

u8 func_081026C4(u16 a, u16 b, u16 c) {
    u16 v;
    v = a * 16 + b * 4 + c;

    if (v <= 0x1FF) {
        return gUnk_02035B68[v >> 4] >> (v & 15) & 1;
    }
    return 0;
}

void func_08102704(u16 a) {
    if (a <= 31) {
        gUnk_02035BA8[a >> 4] |= 1 << (a & 15);
    }
}

void func_08102728(u16 a) {
    if (a <= 31) {
        gUnk_02035BA8[a >> 4] &= ~(1 << (a & 15));
    }
}

u8 func_0810274C(u16 a) {
    if (a <= 31) {
        return gUnk_02035BA8[a >> 4] >> (a & 15) & 1;
    }

    return 0;
}

void func_08102774(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            func_08102688(gUnk_0203C590[6], i, j);
        }
    }

    func_08102728(gUnk_0203C590[6]);
}

u8 func_081027B4(s16 a) {
    s16 i;
    s16 k;
    s16 m;
    s16 n;
    s16 v;
    s32 r;

    for (i = 0; i < 4; i++) {
        gUnk_02035B08[i] |= 0xFFFFu;

        for (k = 0; k < 4; k++) {
            gUnk_02035B18[i][k][0] |= 0xFFFFu;
        }
    }

    n = 0;

    for (i = 0; i < 4; i++) {
        m = 0;

        for (k = 0; k < 4; k++) {
            v = gUnk_099935C0[a][i][k];

            if (func_081026C4(gUnk_0203C590[6], i, k) == 0) {
                if (v >= 0) {
                    gUnk_02035B18[n][m][0] = k;
                    gUnk_02035B18[n][m][1] = v;
                    m++;
                }
            }
        }

        if (m > 0) {
            gUnk_02035B08[n] = i;
            n++;
        }
    }

    r = 0;

    if (n > 0) {
        r = 1;
    }

    return r;
}

void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
    s16 i;
    s16 j;
    s16 n;

    n = w;
    src += sx + sy * 32;
    dst += dx + dy * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *dst++ = *src++;
        }

        src += 32 - n;
        dst += 32 - n;
    }
}

void func_08102984(s16 a) {
    vu32* dma;
    vu16 zero;
    s32 j;

    zero = 0;
    dma = (vu32*)REG_ADDR_DMA3;
    dma[0] = (u32)&zero;
    dma[1] = (u32)gUnk_02035C00;
    dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x280;
    dma[2];

    for (j = 0; j < 4; j++) {
        if (gUnk_02035B18[a][j][0] >= 0) {
            LoadDecimalDigitTiles(gUnk_09993760[gUnk_02035B08[a]][gUnk_02035B18[a][j][1]], gUnk_09A18EBC,
                (u8*)GetBgCharBase(2) + (j * 0xC0 + 0xC0), 0x40, 3);
            func_081028F8(12, 8, LANGSTR(gMooglePackMenuEntries[j].packTilemaps[gUnk_02035B08[a]].tilemap),
                gMooglePackMenuEntries[j].packTilemaps[gUnk_02035B08[a]].srcX,
                gMooglePackMenuEntries[j].packTilemaps[gUnk_02035B08[a]].srcY, gUnk_02035C00,
                gMooglePackMenuEntries[j].tilemapX, gMooglePackMenuEntries[j].tilemapY);
        }
    }

    LoadBgMap(2, gUnk_02035C00, 0x500);
}

s32 MoogleShopReadMenuKeys(void) {
    s32 k;

    k = GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    return k | (GetKeysRepeat() & (DPAD_ANY | R_BUTTON | L_BUTTON));
}

void func_08102AB4(s16 x, s16 y) {
    s16 i;
    u16 id;
    void** p;

    for (i = 0; i < 5; i++) {
        id = gUnk_02035B58[i];

        if (id & 0x8000) {
            gUnk_020358C8[i].premium = 1;
        } else {
            gUnk_020358C8[i].premium = 0;
        }

        gUnk_020358C8[i].revealed = 0;
        id &= 0xFFF;
        gUnk_020358C8[i].palette = LoadObjPalette(gCardDefs[id].palette, 0x20);
        FadeSetPaletteExcluded(gUnk_020358C8[i].palette->index + 0x10, 1);
        gUnk_020358C8[i].tiles = LoadObjTiles(gCardDefs[id].tiles, 0x200);
        gUnk_020358C8[i].gfx = gCardDefs[id].gfx;
        gUnk_020358C8[i].palette2 = LoadObjPalette(gUnk_09A3DB1C + gCardDefs[id].unk_2A * 32, 0x20);
        FadeSetPaletteExcluded(gUnk_020358C8[i].palette2->index + 0x10, 1);
        gUnk_020358C8[i].tiles2 = LoadObjTiles(gUnk_099A4B9A, 0x1D80);
        gUnk_020358C8[i].backSprite = 0;
        AnimInit(&gUnk_020358C8[i].anim, gUnk_09EF9A48, gUnk_09EF9A20);
        AnimStart(&gUnk_020358C8[i].anim, 0, 1);
        gUnk_020358C8[i].x = x << 8;
        gUnk_020358C8[i].y = y << 8;
        gUnk_020358C8[i].scale = 2;
        gUnk_020358C8[i].flipAngle = 0;
        gUnk_020358C8[i].state = 0;
        gUnk_020358C8[i].timer = 0;
    }

    gUnk_02035A30 = LoadObjPalette(gUnk_09611AB8, 0x20);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035A30)->index + 0x10, 1);
    gUnk_02035A34 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    gUnk_02035A38 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035A38)->index + 0x10, 1);
    gUnk_02035A3C = LoadObjTiles(gUnk_0905ED36, 0x140);
    gUnk_02035AE0 = LoadObjPalette(gUnk_09A3DA7C, 0x20);
    gUnk_02035ADC = LoadObjTiles(gUnk_099A3CE4, 0x1C0);
    AnimInit(&gUnk_02035AE8, gUnk_09EF99F8, gUnk_09EF99D8);
    AnimStart(&gUnk_02035AE8, 0, 1);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035AE0)->index + 0x10, 1);
    gUnk_02035A40 = LoadObjPalette(gUnk_09A3DB7C, 0x20);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035A40)->index + 0x10, 1);
    p = &gUnk_02035A44;
    *p = EwramAlloc(0x120);
    InitTextSlots(gUnk_02035A44, 0x24);
    p = &gUnk_02035A4C;
    *p = EwramAlloc(0x2D0);
    InitTextSlots(gUnk_02035A4C, 0x5A);
    gUnk_02035A54 = LoadObjTiles(gUnk_0908B1B4, 0x9A0);
    AnimInit(&gUnk_02035A58, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&gUnk_02035A58, 0, 1);

    for (i = 0; i < 5; i++) {
        TaskPoolInit(&gUnk_02035A70[i], 8);
    }

    gUnk_020358C8[0].timer = 15;
}

void func_08102DC8(void) {
    s16 i;

    for (i = 0; i < 5; i++) {
        FadeSetPaletteExcluded(gUnk_020358C8[i].palette->index + 0x10, 0);
        ReleaseObjPalette(gUnk_020358C8[i].palette);
        ReleaseObjTiles(gUnk_020358C8[i].tiles);
        FadeSetPaletteExcluded(gUnk_020358C8[i].palette2->index + 0x10, 0);
        ReleaseObjPalette(gUnk_020358C8[i].palette2);
        ReleaseObjTiles(gUnk_020358C8[i].tiles2);
    }

    FadeSetPaletteExcluded(((FldRes*)gUnk_02035AE0)->index + 0x10, 0);
    ReleaseObjPalette(gUnk_02035AE0);
    ReleaseObjTiles(gUnk_02035ADC);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035A40)->index + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A40);
    FreeTextSlots(gUnk_02035A44, 0x24);
    EwramFree(gUnk_02035A44);
    FreeTextSlots(gUnk_02035A4C, 0x5A);
    EwramFree(gUnk_02035A4C);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035A30)->index + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A30);
    ReleaseObjTiles(gUnk_02035A34);
    FadeSetPaletteExcluded(((FldRes*)gUnk_02035A38)->index + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A38);
    ReleaseObjTiles(gUnk_02035A3C);
    ReleaseObjTiles(gUnk_02035A54);

    for (i = 0; i < 5; i++) {
        TaskPoolDestroy(&gUnk_02035A70[i]);
    }
}

void func_08102F30(void) {
    s16 i;
    s32 affine;
    void* obj;
    s32 v;
    void* anim;

    anim = AnimUpdate(&gUnk_02035A58);

    for (i = 0; i < 5; i++) {
        if (gUnk_020358C8[i].revealed == 0) {
            v = gUnk_020358C8[i].scale;
            affine = AllocObjAffine(0, v, v, 0);
            obj = AnimUpdate(&gUnk_020358C8[i].anim);
        } else {
            v = gUnk_020358C8[i].scale * -gSineTable[(gUnk_020358C8[i].flipAngle & 0xFF) + 0x40] >> 8;
            affine = AllocObjAffine(0, v, gUnk_020358C8[i].scale, 0);
            obj = gUnk_020358C8[i].backSprite;
        }

        if (v != 0) {
            DrawSprite(gUnk_020358C8[i].x >> 8, gUnk_020358C8[i].y >> 8, obj, gUnk_020358C8[i].tiles2, gUnk_020358C8[i].palette2, affine, 0, 0x50);

            if (gUnk_020358C8[i].revealed != 0) {
                DrawSprite(gUnk_020358C8[i].x >> 8, gUnk_020358C8[i].y >> 8, gUnk_020358C8[i].gfx, gUnk_020358C8[i].tiles, gUnk_020358C8[i].palette, affine, 0, 0x58);

                if (gUnk_020358C8[i].premium != 0) {
                    DrawSprite(gUnk_020358C8[i].x >> 8, gUnk_020358C8[i].y >> 8, gUnk_09EE9894[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_20], gUnk_02035A3C, gUnk_02035A38, affine, 0, 0x48);
                    DrawSprite(gUnk_020358C8[i].x >> 8, gUnk_020358C8[i].y >> 8, anim, gUnk_02035A54, gUnk_02035A30, affine, 0, 0x40);
                } else {
                    DrawSprite(gUnk_020358C8[i].x >> 8, gUnk_020358C8[i].y >> 8, gUnk_09EE981C[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_20], gUnk_02035A34, gUnk_02035A30, affine, 0, 0x48);
                }
            }
        }

        if (gUnk_020358C8[i].state == 9) {
            DrawTextSlots(0x30, 0x63, gUnk_02035A44, gUnk_02035A40, 0, gUnk_02035A48);
            DrawTextSlots(0x31, 0x72, gUnk_02035A4C, gUnk_02035AE0, 0, gUnk_02035A50);
            ApproachValueHalf(&gUnk_02035AD4, gUnk_020358C8[gUnk_02035B62].x - 0x1000);
            ApproachValueHalf(&gUnk_02035AD8, gUnk_020358C8[gUnk_02035B62].y - 0x2000);
            DrawSprite(gUnk_02035AD4 >> 8, gUnk_02035AD8 >> 8, AnimUpdate(&gUnk_02035AE8), gUnk_02035ADC, gUnk_02035AE0, 0, 0, 0);
        }
    }

    for (i = 0; i < 5; i++) {
        TaskPoolDraw(&gUnk_02035A70[i]);
    }
}

u8 func_0810329C(u16 a) {
    MsShopHosiArg arg0;
    MsShopHosiArg arg1;
    MsShopHosiArg arg2;
    u8 result;
    s16 i;
    s16 j;
    s16 k;
    s16 old;
    u16 keys;
    u16 d;
    s32 f;
    s32 g;
    s32 h;

    result = 1;

    for (i = 0; i < 5; i++) {
        switch (gUnk_020358C8[i].state) {
        case 0:
            if (FadeIsActive() == 0) {
                if (gUnk_020358C8[i].timer != 0) {
                    gUnk_020358C8[i].state = 1;
                }
            }

            break;
        case 1:
            ApproachValue(&gUnk_020358C8[i].x, i * 10240 + 0x2800, gUnk_020358C8[i].timer);
            ApproachValue(&gUnk_020358C8[i].y, 0x6400, gUnk_020358C8[i].timer);
            ApproachValue(&gUnk_020358C8[i].scale, 0x100, gUnk_020358C8[i].timer);

            if (--gUnk_020358C8[i].timer == 0) {
                if (gUnk_020358C8[i].premium != 0) {
                    gUnk_020358C8[i].state = 5;
                } else {
                    gUnk_020358C8[i].state = 2;
                }
                if (i <= 3) {
                    gUnk_020358C8[i + 1].timer = 15;
                } else {
                    for (j = 0; j < 5; j++) {
                        if (gUnk_020358C8[j].state == 2) {
                            gUnk_020358C8[j].timer = 8;
                            break;
                        }
                    }
                    if (j == 5) {
                        gUnk_020358C8[0].timer = 8;
                    }
                }
            }

            break;
        case 2:
            if (gUnk_020358C8[i].timer != 0) {
                if (AnimGetFrame(&gUnk_020358C8[i].anim) == 3 || AnimGetFrame(&gUnk_020358C8[i].anim) == 8) {
                    ReleaseObjPalette(gUnk_020358C8[i].palette2);
                    ReleaseObjTiles(gUnk_020358C8[i].tiles2);
                    gUnk_020358C8[i].palette2 = LoadObjPalette(gUnk_09611AB8, 0x20);
                    FadeSetPaletteExcluded(gUnk_020358C8[i].palette2->index + 0x10, 1);
                    gUnk_020358C8[i].tiles2 = LoadObjTiles(gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].tiles, 0x300);
                    gUnk_020358C8[i].backSprite = gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].gfx;
                    gUnk_020358C8[i].flipAngle = 0x40;
                    gUnk_020358C8[i].state = 3;
                    gUnk_020358C8[i].revealed = 1;
                }
            }
            break;
        case 3:
            d = 0x80 - gUnk_020358C8[i].flipAngle;
            gUnk_020358C8[i].flipAngle += d / gUnk_020358C8[i].timer;

            if (--gUnk_020358C8[i].timer == 0) {
                gUnk_020358C8[i].timer = 5;
                gUnk_020358C8[i].state = 4;
            }

            break;
        case 4:
            ApproachValue(&gUnk_020358C8[i].y, 0x4600, gUnk_020358C8[i].timer);

            if (--gUnk_020358C8[i].timer == 0) {
                m4aSongNumStart(SONG_SYS_KAIHUKU);
                gUnk_020358C8[i].state = 8;

                for (j = 0; j < 5; j++) {
                    if (gUnk_020358C8[j].state == 2) {
                        gUnk_020358C8[j].timer = 8;
                        break;
                    }
                }

                if (j == 5) {
                    for (j = 0; j < 5; j++) {
                        if (gUnk_020358C8[j].state == 5) {
                            gUnk_020358C8[j].timer = 8;
                            break;
                        }
                    }
                    if (j == 5) {
                        gUnk_020358C8[0].timer = 60;
                    }
                }
            }

            break;
        case 5:
            if (gUnk_020358C8[i].timer != 0) {
                if (AnimGetFrame(&gUnk_020358C8[i].anim) == 3 || AnimGetFrame(&gUnk_020358C8[i].anim) == 8) {
                    ReleaseObjPalette(gUnk_020358C8[i].palette2);
                    ReleaseObjTiles(gUnk_020358C8[i].tiles2);
                    gUnk_020358C8[i].palette2 = LoadObjPalette(gUnk_09611AB8, 0x20);
                    FadeSetPaletteExcluded(gUnk_020358C8[i].palette2->index + 0x10, 1);
                    gUnk_020358C8[i].tiles2 = LoadObjTiles(gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].tiles, 0x300);
                    gUnk_020358C8[i].backSprite = gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].gfx;
                    gUnk_020358C8[i].flipAngle = 0x40;
                    gUnk_020358C8[i].state = 6;
                    gUnk_020358C8[i].revealed = 1;
                }
            }

            break;
        case 6:
            d = 0x80 - gUnk_020358C8[i].flipAngle;
            gUnk_020358C8[i].flipAngle += d / gUnk_020358C8[i].timer;

            if (--gUnk_020358C8[i].timer == 0) {
                gUnk_020358C8[i].timer = 5;
                gUnk_020358C8[i].state = 7;

                for (k = 0; k < 8; k++) {
                    arg0.x = gUnk_020358C8[i].x >> 8;
                    arg0.y = gUnk_020358C8[i].y >> 8;
                    arg0.palette = gUnk_02035A40;
                    arg0.angle = GetRandom() % 96 - 48;
                    arg0.speed = GetRandom() % 256 + 0x1C0;
                    TaskCreate(&gUnk_02035A70[i], &gTaskDescMsShopHosi, &arg0);
                }
            }

            break;
        case 7:
            ApproachValue(&gUnk_020358C8[i].y, 0x4600, gUnk_020358C8[i].timer);
            f = gFrameCounter & 0x1F;
            if (f == 0) {
                arg0.x = (gUnk_020358C8[i].x >> 8) + GetRandom() % 32 - 16;
                arg0.y = (gUnk_020358C8[i].y >> 8) + GetRandom() % 32 - 16;
                arg0.palette = gUnk_02035A40;
                arg0.angle = 0x80;
                arg0.speed = f;
                TaskCreate(&gUnk_02035A70[i], &gTaskDescMsShopHosi, &arg0);
            }

            if (--gUnk_020358C8[i].timer == 0) {
                m4aSongNumStart(SONG_SYS_KAIHUKU);
                gUnk_020358C8[i].state = 8;

                for (j = 0; j < 5; j++) {
                    if (gUnk_020358C8[j].state == 5) {
                        gUnk_020358C8[j].timer = 8;
                        break;
                    }
                }
                if (j == 5) {
                    gUnk_020358C8[0].timer = 60;
                }
            }

            break;
        case 8:
            if (gUnk_020358C8[i].premium != 0) {
                g = gFrameCounter & 0x1F;
                if (g == 0) {
                    arg1.x = (gUnk_020358C8[i].x >> 8) + GetRandom() % 32 - 16;
                    arg1.y = (gUnk_020358C8[i].y >> 8) + GetRandom() % 32 - 16;
                    arg1.palette = gUnk_02035A40;
                    arg1.angle = 0x80;
                    arg1.speed = g;
                    TaskCreate(&gUnk_02035A70[i], &gTaskDescMsShopHosi, &arg1);
                }
            }

            if (gUnk_020358C8[i].timer != 0) {
                if (--gUnk_020358C8[i].timer == 0) {
                    if (a & 1) {
                        SetupBg(3, 0, 31, 0);
                        SetBgScroll(3, 0, 0);
                        RequestDma3Copy(gUnk_09A17D1C, (u8*)GetBgCharBase(3) + 0x5800, 0x1400);
                        LoadBgMap(3, gUnk_09A3AD5C, 0x500);
                    }

                    gUnk_02035B62 = 0;
                    gUnk_02035AD4 = gUnk_020358C8[0].x - 0x1000;
                    gUnk_02035AD8 = gUnk_020358C8[0].y - 0x2000;
                    LoadPalette(gUnk_09A3DA1C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32, (void*)0x050001A0, 0x20);
                    gUnk_02035A48 = LoadTextSlots(LANGSEL(gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].name), gUnk_02035A44);
                    gUnk_02035A50 = LoadTextSlots((void*)LANGSTR(gUnk_09EE8F48[gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_1C]), gUnk_02035A4C);
                    LoadObjPaletteBank(((FldRes*)gUnk_02035A40)->index, gUnk_09A3DB7C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32);
                    EnableBg(3);
                    gUnk_020358C8[i].state = 9;
                }
            }

            break;
        case 9:
            if (gUnk_020358C8[i].premium != 0) {
                h = gFrameCounter & 0x1F;
                if (h == 0) {
                    arg2.x = (gUnk_020358C8[i].x >> 8) + GetRandom() % 32 - 16;
                    arg2.y = (gUnk_020358C8[i].y >> 8) + GetRandom() % 32 - 16;
                    arg2.palette = gUnk_02035A40;
                    arg2.angle = 0x80;
                    arg2.speed = h;
                    TaskCreate(&gUnk_02035A70[i], &gTaskDescMsShopHosi, &arg2);
                }
            }

            keys = MoogleShopReadMenuKeys();
            old = gUnk_02035B62;

            if (keys & (A_BUTTON | B_BUTTON)) {
                m4aSongNumStart(SONG_SYS_CLOSE);
                result = 0;
            } else if (keys & DPAD_LEFT) {
                gUnk_02035B62--;
                if (gUnk_02035B62 < 0) {
                    gUnk_02035B62 = 4;
                }
            } else if (keys & DPAD_RIGHT) {
                gUnk_02035B62++;
                if (gUnk_02035B62 > 4) {
                    gUnk_02035B62 = 0;
                }
            }

            if (gUnk_02035B62 != old) {
                LoadPalette(gUnk_09A3DA1C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32, (void*)0x050001A0, 0x20);
                gUnk_02035A48 = LoadTextSlots(LANGSEL(gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].name), gUnk_02035A44);
                gUnk_02035A50 = LoadTextSlots((void*)LANGSTR(gUnk_09EE8F48[gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_1C]), gUnk_02035A4C);
                LoadObjPaletteBank(((FldRes*)gUnk_02035A40)->index, gUnk_09A3DB7C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32);
                m4aSongNumStart(SONG_SYS_CLICK);
            }

            break;
        }
    }

    for (i = 0; i < 5; i++) {
        TaskPoolUpdate(&gUnk_02035A70[i]);
    }

    return result;
}

void func_08103CD8(s16 a) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gUnk_02035B08[i] >= 0) {
            RequestTilemapRectCopy(gUnk_09A3ABDC, GetBgScreenBase(0), gUnk_02035B08[i] * 6, i == a ? 0 : 3, 0, i * 3 + 3, 6, 3);
        }
    }
}

void func_08103D54(s16 a) {
    LoadBgMap(1, gMooglePackMenuEntries[a].selectionTilemap, gMooglePackMenuEntries[a].selectionTilemapSize);
}

void func_08103D7C(void) {
    u16 keys;
    keys = MoogleShopReadMenuKeys();

    if ((keys & A_BUTTON) == 0) {
        if (keys & B_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            FadeStartOut(0, 16);
            gUnk_02035C0C = 1;
            gUnk_02035B02 = 5;
        } else if (keys & START_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            FadeStartOut(0, 16);
            gUnk_02035C0C = 0;
            gUnk_02035B02 = 5;
        }
    }
}

void func_08103DE8(void) {
    u16 keys;
    s16 old;
    s16 i;

    old = gUnk_02035B04;
    keys = MoogleShopReadMenuKeys();

    if ((keys & A_BUTTON) == 0) {
        if (keys & B_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            FadeStartOut(0, 16);
            gUnk_02035C0C = 1;
            gUnk_02035B02 = 5;
        } else if (keys & START_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            FadeStartOut(0, 16);
            gUnk_02035C0C = 0;
            gUnk_02035B02 = 5;
        } else if (keys & DPAD_UP) {
            gUnk_02035B04--;

            if (gUnk_02035B04 < 0) {
                i = 3;

                if (gUnk_02035B08[i] < 0) {
                    do {
                        i--;

                        if (i <= 0) {
                            break;
                        }
                    } while (gUnk_02035B08[i] < 0);
                }

                gUnk_02035B04 = i;
            }
        } else if (keys & DPAD_DOWN) {
            gUnk_02035B04++;

            if (gUnk_02035B04 > 3) {
                gUnk_02035B04 = 0;
            } else if (gUnk_02035B08[gUnk_02035B04] < 0) {
                gUnk_02035B04 = 0;
            }
        } else if (keys & DPAD_RIGHT) {
            gUnk_02035B02 = 3;
            gUnk_02035B10 = 0;
            func_08103D54(0);
            m4aSongNumStart(SONG_SYS_CLICK);
        }
    }

    if (gUnk_02035B04 == -1) {
        gUnk_02035B04 = old;
    }

    if (gUnk_02035B04 != old) {
        func_08103CD8(gUnk_02035B04);
        func_08102984(gUnk_02035B04);
        m4aSongNumStart(SONG_SYS_CLICK);
    }
}

u16 func_08103F3C(void) {
    s16 i;
    u16 r;
    u16 acc;

    r = GetRandom() % 100;
    i = 0;
    acc = gUnk_09993334[0];

    if (r >= acc) {
        do {
            i++;

            if (i > 9) {
                break;
            }

            acc += gUnk_09993334[i];
        } while (r >= acc);
    }

    return i % 10;
}

void func_08103F94(s16 a, s16 b) {
    s16 lo;
    s16 hi;
    s16 j;
    s16 m;
    s16 k;
    s16 cnt;
    u16 total;
    u16 rnd;
    u16 acc;
    u16 id;
    const MooglePackCardDef** list;
    const MooglePackCardDef* e;
    s16 n;

    id = 0;

    if (a <= 2) {
        lo = a;
        hi = a + 1;
    } else {
        lo = 0;
        hi = 3;
    }

    total = 0;
    cnt = 0;

    for (j = lo; j < hi; j++) {
        cnt += gMooglePackCardTables[j].count;
    }

    list = EwramAlloc(cnt * 4);
    k = 0;

    for (j = lo; j < hi; j++) {
        e = gMooglePackCardTables[j].cards;
        n = gMooglePackCardTables[j].count;

        for (m = 0; m < n; m++) {
            if (e[m].weights[b] != 0) {
                total += e[m].weights[b];
                list[k] = &e[m];
                k++;
            }
        }
    }

    for (j = 0; j < 5; j++) {
        rnd = GetRandom() % total;
        acc = 0;

        for (m = 0; m < k; m++) {
            acc += list[m]->weights[b];

            if (rnd < acc) {
                if (func_0800FC5C(list[m]->unk_04) != 0) {
                    id = list[m]->cardId;
                } else {
                    switch (gCardDefs[list[m]->cardId].unk_2A) {
                    case 0:
                        id = 0;
                        break;
                    case 1:
                        id = 200;
                        break;
                    case 2:
                        id = 380;
                        break;
                    }
                }

                id += func_08103F3C();

                if (gCardDefs[id].unk_2A <= 1) {
                    if (GetRandom() % 100 <= 9) {
                        id |= 0x8000;
                    }
                }

                gUnk_02035B58[j] = id;

                if (func_08084458(id) < 0) {
                    AddMooglePoints(GetCardMooglePointValue(id));
                }

                break;
            }
        }
    }

    EwramFree(list);
}

void func_081041B4(void) {
    u16 keys;
    s16 old;

    old = gUnk_02035B10;
    keys = MoogleShopReadMenuKeys();

    if (keys & A_BUTTON) {
        if (gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0] >= 0 &&
            SpendMooglePoints(gUnk_09993760[gUnk_02035B08[gUnk_02035B04]][gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][1]]) != 0) {
            func_08103F94(gUnk_02035B08[gUnk_02035B04], gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][1]);
            func_08102AB4(gUnk_02035B10 % 2 * 96 + 72, gUnk_02035B10 / 2 * 64 + 48);
            FadeSetPaletteExcluded(13, 1);
            FadeToAmount(0, 16, 8);
            m4aSongNumStart(SONG_SYS_KETTEI);
            gUnk_02035B02 = 4;
        } else {
            m4aSongNumStart(SONG_SYS_BEEP);
        }
    } else if (keys & B_BUTTON) {
        m4aSongNumStart(SONG_SYS_CLOSE);
        FadeStartOut(0, 16);
        gUnk_02035C0C = 1;
        gUnk_02035B02 = 5;
    } else if (keys & START_BUTTON) {
        m4aSongNumStart(SONG_SYS_CLOSE);
        FadeStartOut(0, 16);
        gUnk_02035C0C = 0;
        gUnk_02035B02 = 5;
    } else if (keys & DPAD_UP) {
        gUnk_02035B10 = gMooglePackMenuEntries[gUnk_02035B10].upEntry;
    } else if (keys & DPAD_DOWN) {
        gUnk_02035B10 = gMooglePackMenuEntries[gUnk_02035B10].downEntry;
    } else if (keys & DPAD_LEFT) {
        gUnk_02035B10 = gMooglePackMenuEntries[gUnk_02035B10].leftEntry;
    } else if (keys & DPAD_RIGHT) {
        gUnk_02035B10 = gMooglePackMenuEntries[gUnk_02035B10].rightEntry;
    }

    if (gUnk_02035B10 == -1) {
        gUnk_02035B10 = old;
    } else if (gUnk_02035B10 == 5) {
        gUnk_02035B10 = old;
        gUnk_02035B02 = 2;
        DisableBg(1);
        m4aSongNumStart(SONG_SYS_CLICK);
    } else if (gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0] < 0) {
        gUnk_02035B10 = old;
    }

    if (gUnk_02035B10 != old) {
        func_08103D54(gUnk_02035B10);
        m4aSongNumStart(SONG_SYS_CLICK);
    }
}

void func_08104404(void) {
    s32 i;
    s16 v;

    switch (gUnk_02035B02) {
    case 2:
        if (gUnk_02035B00 != 0) {
            ApproachValueHalf(&gUnk_02035C04, 0x400);
            ApproachValueHalf(&gUnk_02035C08, gUnk_02035B04 * 6144 + 0x800);
            DrawSprite(gUnk_02035C04 >> 8, gUnk_02035C08 >> 8, AnimUpdate(&gUnk_02035BB8), gUnk_02035BAC, gUnk_02035BB0, 0, 0x400, 0x3E8);
        }
        break;
    case 3:
        ApproachValueHalf(&gUnk_02035C04, gMooglePackMenuEntries[gUnk_02035B10].cursorX << 8);
        ApproachValueHalf(&gUnk_02035C08, gMooglePackMenuEntries[gUnk_02035B10].cursorY << 8);
        DrawSprite(gUnk_02035C04 >> 8, gUnk_02035C08 >> 8, AnimUpdate(&gUnk_02035BB8), gUnk_02035BAC, gUnk_02035BB0, 0, 0x400, 0x3E8);
        break;
    case 4:
        func_08102F30();
        break;
    }

    for (i = 0; i < 4; i++) {
        if (gUnk_02035B18[gUnk_02035B04][i][0] >= 0) {
            v = gUnk_02035B18[gUnk_02035B04][i][1];
            DrawSprite(gMooglePackMenuEntries[i].spriteX + gMooglePackSpriteDefs[v].xOffset, gMooglePackMenuEntries[i].spriteY + gMooglePackSpriteDefs[v].yOffset, gUnk_02035BF0[v], gUnk_02035BD0[v], gUnk_02035BE0[v], 0, 0x400, 0x3F2);
        }
    }
}

void mode_ms_shop_0(void) {
    s16 i;
    s32 size;
    u16** p;

    p = &gUnk_02035C00;
    size = 0x500;
    *p = EwramAlloc(size);
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
    gUnk_02035B02 = 0;
    gUnk_02035B04 = 0;
    gUnk_02035B10 = 0;
    gUnk_02035B00 = func_081027B4(gGameState.floor);
    LoadBgPalette(0, gUnk_09A3D87C, 0x1A0);
    LoadBgTiles(0, gUnk_09A1251C, 0x6860);
    LoadDecimalDigitTiles(GetMooglePoints(), gUnk_09A18D7C, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
#ifdef VERSION_EU
    LoadBgMap(0, gUnkEu_09F84F5C[gLanguage], size);
#else
    LoadBgMap(0, gUnk_09A382DC, size);
#endif
    func_08103CD8(gUnk_02035B04);

    if (gUnk_02035B00 != 0) {
        func_08103D54(gUnk_02035B10);
    }

    func_08102984(gUnk_02035B04);
    LoadBgMap(3, gUnk_09A3AD5C, size);
    gUnk_02035BB0 = LoadObjPalette(gUnk_09A3DA7C, 0x20);
    gUnk_02035BAC = LoadObjTiles(gUnk_099A3CE4, 0x1C0);
    AnimInit(&gUnk_02035BB8, gUnk_09EF99F8, gUnk_09EF99D8);
    AnimStart(&gUnk_02035BB8, 0, 1);

    for (i = 0; i < 4; i++) {
        gUnk_02035BE0[i] = LoadObjPalette(gMooglePackSpriteDefs[i].palette, gMooglePackSpriteDefs[i].paletteSize);
        gUnk_02035BD0[i] = LoadObjTiles(gMooglePackSpriteDefs[i].tiles, gMooglePackSpriteDefs[i].tilesSize);
        gUnk_02035BF0[i] = gMooglePackSpriteDefs[i].sprite;
    }

    EnableBg(0);
    DisableBg(1);
    EnableBg(2);
    DisableBg(3);
}

void mode_ms_shop_1(void) {
    UpdatePlayTime();

    switch (gUnk_02035B02) {
    case 0:
        if (FadeIsActive() == 0) {
            if (gUnk_02035B00 != 0) {
                gUnk_02035C04 = 0x400;
                gUnk_02035C08 = gUnk_02035B04 * 6144 + 0x800;
                gUnk_02035B02 = 2;
            } else {
                gUnk_02035B02 = 1;
            }
        }
        break;
    case 1:
        func_08103D7C();
        break;
    case 2:
        func_08103DE8();
        break;
    case 3:
        func_081041B4();
        break;
    case 4:
        if (func_0810329C(0) == 0) {
            func_08102DC8();
            func_0810264C(gUnk_0203C590[6], gUnk_02035B08[gUnk_02035B04], gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0]);
            gUnk_02035B00 = func_081027B4(gGameState.floor);
#ifdef VERSION_EU
            LoadBgMap(0, gUnkEu_09F84F5C[gLanguage], 0x500);
#else
            LoadBgMap(0, gUnk_09A382DC, 0x500);
#endif

            if (gUnk_02035B04 > 0) {
                if (gUnk_02035B08[gUnk_02035B04] < 0) {
                    do {
                        gUnk_02035B04--;
                        if (gUnk_02035B04 <= 0) {
                            break;
                        }
                    } while (gUnk_02035B08[gUnk_02035B04] < 0);
                }
            }

            func_08103CD8(gUnk_02035B04);
            func_08102984(gUnk_02035B04);

            if (gUnk_02035B00 != 0) {
                for (; gUnk_02035B10 > 0 && gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0] < 0; gUnk_02035B10--) {
                }
                func_08103D54(gUnk_02035B10);
            } else {
                DisableBg(1);
            }
            
            LoadDecimalDigitTiles(GetMooglePoints(), gUnk_09A18D7C, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
            DisableBg(3);
            FadeToOriginal(0, 8);
            gUnk_02035B02 = gUnk_02035B00 != 0 ? 3 : 1;
        }
        break;
    case 5:
        if (FadeIsActive() == 0) {
            if (gUnk_02035C0C != 0) {
                ModeRequest(&gModeMsTop, 2);
            } else {
                func_080E04EC();
            }
        }
        break;
    }

    func_08104404();
}

void mode_ms_shop_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_02035BB0);
    ReleaseObjTiles(gUnk_02035BAC);

    for (i = 0; i < 4; i++) {
        ReleaseObjPalette(gUnk_02035BE0[i]);
        ReleaseObjTiles(gUnk_02035BD0[i]);
    }

    EwramFree(gUnk_02035C00);
}

const char gModeNameMsShop[] = "mode_ms_shop";

Mode gModeMsShop = {
    gModeNameMsShop,
    (ModeInitFunc)mode_ms_shop_0,
    mode_ms_shop_1,
    mode_ms_shop_2,
};
