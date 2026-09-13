#include "worldinspect_data.h"
#include "worldinspect_assets.h"

WorldinspectNav gUnk_09EF8FAC[12] __attribute__((section(".data_worldinspect"))) = {
    { 7, 8, 1, 3, 22, 14, 0, 21, 16, { 0, 0 } },
    { 6, 9, 2, 0, 15, 14, 0, 14, 16, { 0, 0 } },
    { 5, 10, 3, 1, 8, 14, 0, 7, 16, { 0, 0 } },
    { 4, 11, 0, 2, 1, 14, 1, 0, 12, { 0, 0 } },
    { 11, 3, 7, 5, 1, 10, 0, 7, 12, { 0, 0 } },
    { 10, 2, 4, 6, 8, 10, 0, 14, 12, { 0, 0 } },
    { 9, 1, 5, 7, 15, 10, 0, 21, 12, { 0, 0 } },
    { 8, 0, 6, 4, 22, 10, 2, 28, 8, { 0, 0 } },
    { 0, 7, 9, 11, 22, 6, 0, 21, 8, { 0, 0 } },
    { 1, 6, 10, 8, 15, 6, 0, 14, 8, { 0, 0 } },
    { 2, 5, 11, 9, 8, 6, 0, 7, 8, { 0, 0 } },
    { 3, 4, 8, 10, 1, 6, 0, 0, 8, { 0, 0 } },
};

WorldinspectMsg gUnk_09EF909C[14] __attribute__((section(".data_worldinspect"))) = {
    {
        0, 0, 0, 0, { 0, 0 }, 0, 0, { 0, 0 }, 0, 0, 0, { 0, 0 }, 0, 0, { 0, 0 }, 0,
        0,
        0, 0,
    },
    {
        1, 1, gUnk_09A3D65C, 32, { 0, 0 }, gUnk_099A0B5C, 576, { 0, 0 }, gUnk_099A0B3C, gUnk_09A3CD1C, 32, { 0, 0 }, gUnk_099E7E7C, 4096, { 0, 0 }, gUnk_099A8824,
#if defined(VERSION_EU)
        &gUnkEu_0888E3A0,
#elif defined(VERSION_JP)
        gUnkJp_0814E590,
#elif defined(VERSION_US)
        gUnk_0815A56C,
#endif
        0, 0,
    },
    {
        2, 2, gUnk_09A3D69C, 32, { 0, 0 }, gUnk_099A0F70, 512, { 0, 0 }, gUnk_099A0F5C, gUnk_09A3CD5C, 32, { 0, 0 }, gUnk_099E9E7C, 4096, { 0, 0 }, gUnk_099A8880,
#if defined(VERSION_EU)
        &gUnkEu_0888E578,
#elif defined(VERSION_JP)
        gUnkJp_0814E5E4,
#elif defined(VERSION_US)
        gUnk_0815A5AA,
#endif
        2, 2,
    },
    {
        4, 3, gUnk_09A3D63C, 32, { 0, 0 }, gUnk_099A08BA, 640, { 0, 0 }, gUnk_099A08A0, gUnk_09A3CCFC, 32, { 0, 0 }, gUnk_099E6E7C, 4096, { 0, 0 }, gUnk_099A87F8,
#if defined(VERSION_EU)
        &gUnkEu_0888E530,
#elif defined(VERSION_JP)
        gUnkJp_0814E5CC,
#elif defined(VERSION_US)
        gUnk_0815A54A,
#endif
        6, 6,
    },
    {
        8, 4, gUnk_09A3D5DC, 32, { 0, 0 }, gUnk_099A0206, 544, { 0, 0 }, gUnk_099A01EC, gUnk_09A3CC9C, 32, { 0, 0 }, gUnk_099E3E7C, 4096, { 0, 0 }, gUnk_099A8758,
#if defined(VERSION_EU)
        &gUnkEu_0888E410,
#elif defined(VERSION_JP)
        gUnkJp_0814E59C,
#elif defined(VERSION_US)
        gUnk_0815A534,
#endif
        4, 4,
    },
    {
        16, 5, gUnk_09A3D67C, 32, { 0, 0 }, gUnk_099A0DBC, 416, { 0, 0 }, gUnk_099A0D9C, gUnk_09A3CD3C, 32, { 0, 0 }, gUnk_099E8E7C, 4096, { 0, 0 }, gUnk_099A884C,
#if defined(VERSION_EU)
        &gUnkEu_0888E450,
#elif defined(VERSION_JP)
        gUnkJp_0814E5AC,
#elif defined(VERSION_US)
        gUnk_0815A59A,
#endif
        3, 3,
    },
    {
        32, 6, gUnk_09A3D6BC, 32, { 0, 0 }, gUnk_099A118A, 544, { 0, 0 }, gUnk_099A1170, gUnk_09A3CD7C, 32, { 0, 0 }, gUnk_099EAE7C, 4096, { 0, 0 }, gUnk_099A88A0,
#if defined(VERSION_EU)
        &gUnkEu_0888E4C0,
#elif defined(VERSION_JP)
        gUnkJp_0814E5B8,
#elif defined(VERSION_US)
        gUnk_0815A57C,
#endif
        5, 5,
    },
    {
        64, 7, gUnk_09A3D6DC, 32, { 0, 0 }, gUnk_099A13CC, 544, { 0, 0 }, gUnk_099A13AC, gUnk_09A3CD9C, 32, { 0, 0 }, gUnk_099EBE7C, 4096, { 0, 0 }, gUnk_099A88D4,
#if defined(VERSION_EU)
        &gUnkEu_0888E5DC,
#elif defined(VERSION_JP)
        gUnkJp_0814E5F4,
#elif defined(VERSION_US)
        gUnk_0815A5BE,
#endif
        1, 1,
    },
    {
        128, 8, gUnk_09A3D71C, 32, { 0, 0 }, gUnk_099A181A, 768, { 0, 0 }, gUnk_099A1800, gUnk_09A3CE1C, 32, { 0, 0 }, gUnk_099EEE7C, 4096, { 0, 0 }, gUnk_099A8930,
#if defined(VERSION_EU)
        &gUnkEu_0888E6BC,
#elif defined(VERSION_JP)
        gUnkJp_0814E618,
#elif defined(VERSION_US)
        gUnk_0815A5D4,
#endif
        7, 7,
    },
    {
        256, 9, gUnk_09A3D5FC, 32, { 0, 0 }, gUnk_099A0442, 544, { 0, 0 }, gUnk_099A0428, gUnk_09A3CCBC, 32, { 0, 0 }, gUnk_099E4E7C, 4096, { 0, 0 }, gUnk_099A8780,
#if defined(VERSION_EU)
        &gUnkEu_0888E72C,
#elif defined(VERSION_JP)
        gUnkJp_0814E62C,
#elif defined(VERSION_US)
        gUnk_0815A62A,
#endif
        8, 8,
    },
    {
        512, 10, gUnk_09A3D61C, 32, { 0, 0 }, gUnk_099A067E, 544, { 0, 0 }, gUnk_099A0664, gUnk_09A3CCDC, 32, { 0, 0 }, gUnk_099E5E7C, 4096, { 0, 0 }, gUnk_099A87C0,
#if defined(VERSION_EU)
        &gUnkEu_0888E364,
#elif defined(VERSION_JP)
        gUnkJp_0814E57C,
#elif defined(VERSION_US)
        gUnk_0815A518,
#endif
        9, 9,
    },
    {
        2048, 11, gUnk_09A3D73C, 32, { 0, 0 }, gUnk_099A1B30, 512, { 0, 0 }, gUnk_099A1B1C, gUnk_09A3CE3C, 32, { 0, 0 }, gUnk_099EFE7C, 4096, { 0, 0 }, gUnk_099A895C,
#if defined(VERSION_EU)
        &gUnkEu_0888E78C,
#elif defined(VERSION_JP)
        gUnkJp_0814E644,
#elif defined(VERSION_US)
        gUnk_0815A60E,
#endif
        10, 10,
    },
    {
        4096, 12, gUnk_09A3D75C, 32, { 0, 0 }, gUnk_099A1D44, 512, { 0, 0 }, gUnk_099A1D30, gUnk_09A3CE5C, 32, { 0, 0 }, gUnk_099F0E7C, 4096, { 0, 0 }, gUnk_099A897C,
#if defined(VERSION_EU)
        &gUnkEu_0888E804,
#elif defined(VERSION_JP)
        gUnkJp_0814E658,
#elif defined(VERSION_US)
        gUnk_0815A64A,
#endif
        11, 13,
    },
    {
        1024, 13, gUnk_09A3D6FC, 32, { 0, 0 }, gUnk_099A1600, 512, { 0, 0 }, gUnk_099A15EC, gUnk_09A3CDBC, 32, { 0, 0 }, gUnk_099ECE7C, 4096, { 0, 0 }, gUnk_099A8900,
#if defined(VERSION_EU)
        &gUnkEu_0888E654,
#elif defined(VERSION_JP)
        gUnkJp_0814E604,
#elif defined(VERSION_US)
        gUnk_0815A5F2,
#endif
        12, 12,
    },
};
