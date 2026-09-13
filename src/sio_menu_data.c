#include <stddef.h>
#include "sio_menu_data.h"
#include "world_intro_assets.h"

SioWorldEntry gUnk_09EF1318[13] __attribute__((section(".data_gUnk_09EF1318"))) = {
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
    {gWorldIntroAssetEu_08CB8D3C, 16384, 0, gWorldIntroAssetEu_08F7B958, 1312, 0, gUnk_08F68C84, 224, 0, &gUnkEu_0888E4C0, 7, 0, 0},
    {gWorldIntroAssetEu_08CB4D3C, 16384, 0, gWorldIntroAssetEu_08F7B498, 1216, 0, gUnk_08F68B84, 256, 0, &gUnkEu_0888E3A0, 3, 0, 36},
    {gUnkEu_08CACD3C, 16384, 0, gUnkEu_08F7A7A8, 1620, 0, gUnk_08F689C4, 192, 0, &gUnkEu_0888E578, 4, 0, 32},
    {gWorldIntroAssetEu_08CA0D3C, 16384, 0, gWorldIntroAssetEu_08F79960, 1164, 0, gUnk_08F686E4, 224, 0, &gUnkEu_0888E530, 6, 0, 16},
    {gUnkEu_08CA8D3C, 16384, 0, gUnkEu_08F7A224, 1412, 0, gUnk_08F68904, 192, 0, &gUnkEu_0888E410, 1, 0, 28},
    {gUnkEu_08CB0D3C, 16384, 0, gUnkEu_08F7ADFC, 1692, 0, gUnk_08F68A84, 256, 0, &gUnkEu_0888E450, 5, 0, 36},
    {gWorldIntroAssetEu_08CB8D3C, 16384, 0, gWorldIntroAssetEu_08F7B958, 1312, 0, gUnk_08F68C84, 224, 0, &gUnkEu_0888E4C0, 7, 0, 18},
    {gUnkEu_08CBCD3C, 16064, 0, gUnkEu_08F7BE78, 1020, 0, gUnk_08F68D64, 320, 0, &gUnkEu_0888E5DC, 8, 0, 26},
    {gWorldIntroAssetEu_08CC4BFC, 16384, 0, gWorldIntroAssetEu_08F7C6CC, 1084, 0, gUnk_08F68FC4, 224, 0, &gUnkEu_0888E6BC, 10, 0, 20},
    {gWorldIntroAssetEu_08CC0BFC, 16384, 0, gWorldIntroAssetEu_08F7C274, 1112, 0, gUnk_08F68EA4, 288, 0, &gUnkEu_0888E72C, 9, 0, 18},
    {gUnk_08C6B0C4, 16384, 0, gWorldIntroAssetEu_08F79520, 1088, 0, gUnk_08F68624, 192, 0, &gUnkEu_0888E364, 11, 0, 20},
    {gWorldIntroAssetEu_08CC8BFC, 16384, 0, gWorldIntroAssetEu_08F7CB08, 1196, 0, gUnk_08F690A4, 320, 0, &gUnkEu_0888E78C, 13, 0, 22},
    {gWorldIntroAssetEu_08CCCBFC, 16384, 0, gWorldIntroAssetEu_08F7CFB4, 868, 0, gUnk_08F691E4, 224, 0, &gUnkEu_0888E804, 12, 0, 22},
#endif
};

s8 gUnk_09EF14B8[12] __attribute__((section(".data_gUnk_09EF14B8"))) = {
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

u16 gUnk_09EF14C4[12] __attribute__((section(".data_gUnk_09EF14C4"))) = {
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

#ifndef VERSION_EU
SioChgCardPos gUnk_09EF150C[13] __attribute__((section(".data_gUnk_09EF150C"))) = {
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

u8* gWorldNames[13] __attribute__((section(".data_gWorldNames"))) = {
#if defined(VERSION_US)
    (u8*)gUnk_0815A534,
    (u8*)gUnk_0815A59A,
    (u8*)gUnk_0815A57C,
    (u8*)gUnk_0815A5AA,
    (u8*)gUnk_0815A5BE,
    (u8*)gUnk_0815A54A,
    (u8*)gUnk_0815A5D4,
    (u8*)gUnk_0815A62A,
    (u8*)gUnk_0815A56C,
    (u8*)gUnk_0815A518,
    (u8*)gUnk_0815A5F2,
    (u8*)gUnk_0815A60E,
    (u8*)gUnk_0815A64A,
#elif defined(VERSION_JP)
    (u8*)gUnkJp_0814E59C,
    (u8*)gUnkJp_0814E5AC,
    (u8*)gUnkJp_0814E5B8,
    (u8*)gUnkJp_0814E5E4,
    (u8*)gUnkJp_0814E5F4,
    (u8*)gUnkJp_0814E5CC,
    (u8*)gUnkJp_0814E618,
    (u8*)gUnkJp_0814E62C,
    (u8*)gUnkJp_0814E590,
    (u8*)gUnkJp_0814E57C,
    (u8*)gUnkJp_0814E604,
    (u8*)gUnkJp_0814E644,
    (u8*)gUnkJp_0814E658,
#elif defined(VERSION_EU)
    (u8*)&gUnkEu_0888E410,
    (u8*)&gUnkEu_0888E450,
    (u8*)&gUnkEu_0888E4C0,
    (u8*)&gUnkEu_0888E578,
    (u8*)&gUnkEu_0888E5DC,
    (u8*)&gUnkEu_0888E530,
    (u8*)&gUnkEu_0888E6BC,
    (u8*)&gUnkEu_0888E72C,
    (u8*)&gUnkEu_0888E3A0,
    (u8*)&gUnkEu_0888E364,
    (u8*)&gUnkEu_0888E654,
    (u8*)&gUnkEu_0888E78C,
    (u8*)&gUnkEu_0888E804,
#endif
};

u8 gUnk_09EF15FC[13] __attribute__((section(".data_gUnk_09EF15FC"))) = {
    4,
    5,
    6,
    2,
    7,
    3,
    8,
    9,
    1,
    10,
    0,
    11,
    12,
};
