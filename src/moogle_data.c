#include <stddef.h>
#include "moogle_data.h"
#include "moogle_assets.h"

#ifdef VERSION_EU
u16* gUnkEu_09F84F70[5] __attribute__((section(".data_gUnkEu_09F84F70"))) = {
    (u16*)gMoogleAssetEu_09A8F3A0,
    (u16*)gMoogleAssetEu_09A8F3A0,
    (u16*)gMoogleAssetEu_09A92E20,
    (u16*)gMoogleAssetEu_09A92620,
    (u16*)gMoogleAssetEu_09A91E20,
};

u16* gUnkEu_09F84F84[5] __attribute__((section(".data_gUnkEu_09F84F84"))) = {
    (u16*)gMoogleAssetEu_09A8FBA0,
    (u16*)gMoogleAssetEu_09A8FBA0,
    (u16*)gMoogleAssetEu_09A94620,
    (u16*)gMoogleAssetEu_09A93E20,
    (u16*)gMoogleAssetEu_09A93620,
};

#endif

u16 gUnk_099931D0[3] __attribute__((section(".data_gUnk_099931D0"))) = {
    129,
    130,
    131,
};

MooglePackMenuEntry gUnk_099931E4[4] __attribute__((section(".data_gUnk_099931E4"))) = {
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

MooglePackSpriteDef gUnk_099932D4[4] __attribute__((section(".data_gUnk_099932D4"))) = {
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

u16 gUnk_09993334[10] __attribute__((section(".data_gUnk_09993334"))) = {
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

MooglePackCardTable gUnk_099935A8[3] __attribute__((section(".data_gUnk_099935A8"))) = {
    {gUnk_09993348, 17, {0, 0}},
    {gUnk_09993458, 14, {0, 0}},
    {gUnk_09993538, 7, {0, 0}},
};

s16 gUnk_099935C0[13][4][4] __attribute__((section(".data_gUnk_099935C0"))) = {
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

s16 gUnk_09993760[4][4] __attribute__((section(".data_gUnk_09993760"))) = {
    {100, 200, 300, 500},
    {200, 250, 270, 300},
    {150, 200, 300, 350},
    {150, 200, 300, 400},
};

MapCardCategoryDef gUnk_09EF9618[5] __attribute__((section(".data_gUnk_09EF9618"))) = {
    {4, 1, 1, 0},
    {0, 2, 2, 0},
    {1, 3, 3, 0},
    {2, 65535, 4, 0},
    {65535, 0, 0, 0},
};

MooglePackCardDef gUnk_09993348[17] __attribute__((section(".data_gUnk_09993348"))) = {
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

MooglePackCardDef gUnk_09993458[14] __attribute__((section(".data_gUnk_09993458"))) = {
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

MooglePackCardDef gUnk_09993538[7] __attribute__((section(".data_gUnk_09993538"))) = {
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
