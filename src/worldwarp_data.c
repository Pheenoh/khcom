#include "animation_resource_data.h"
#include <stddef.h>
#include "registration_data.h"
#include "worldwarp_data.h"
#include "worldwarp_catalog_assets.h"

WarpRect gUnk_099930E8[4] __attribute__((section(".data_gUnk_099930E8"))) = {
    {2, 1, 20, 2},
    {2, 5, 0, 13},
    {2, 5, 3, 13},
    {4, 6, 6, 13},
};

WarpIcon gUnk_09EF9384[13] __attribute__((section(".data_gUnk_09EF9384"))) = {
    {7, 8, 1, 3, 22, 16, 0, 21, 18, {0, 0}},
    {6, 9, 2, 0, 15, 16, 0, 14, 18, {0, 0}},
    {5, 10, 3, 1, 8, 16, 0, 7, 18, {0, 0}},
    {4, 12, 0, 2, 1, 16, 1, 0, 14, {0, 0}},
    {11, 3, 7, 5, 1, 12, 0, 7, 14, {0, 0}},
    {10, 2, 4, 6, 8, 12, 0, 14, 14, {0, 0}},
    {9, 1, 5, 7, 15, 12, 0, 21, 14, {0, 0}},
    {8, 0, 6, 4, 22, 12, 2, 28, 10, {0, 0}},
    {0, 7, 9, 11, 22, 8, 0, 21, 10, {0, 0}},
    {1, 6, 10, 8, 15, 8, 0, 14, 10, {0, 0}},
    {2, 5, 11, 9, 8, 8, 0, 7, 10, {0, 0}},
    {12, 4, 8, 10, 1, 8, 3, 0, 5, {0, 0}},
    {3, 11, 12, 12, 3, 3, 0, 0, 0, {0, 0}},
};

WorldSelectDef gUnk_09EF9488[14] __attribute__((section(".data_gUnk_09EF9488"))) = {
#if defined(VERSION_US)
    {NULL, 0, {0, 0}, NULL, 0, {0, 0}, NULL, NULL},
    {gUnk_09A3D65C, 32, {0, 0}, gUnk_099A0B5C, 576, {0, 0}, gUnk_099A0B3C, gUnk_0815A56C},
    {gUnk_09A3D69C, 32, {0, 0}, gUnk_099A0F70, 512, {0, 0}, gUnk_099A0F5C, gUnk_0815A5AA},
    {gUnk_09A3D63C, 32, {0, 0}, gUnk_099A08BA, 640, {0, 0}, gUnk_099A08A0, gUnk_0815A54A},
    {gUnk_09A3D5DC, 32, {0, 0}, gUnk_099A0206, 544, {0, 0}, gUnk_099A01EC, gUnk_0815A534},
    {gUnk_09A3D67C, 32, {0, 0}, gUnk_099A0DBC, 416, {0, 0}, gUnk_099A0D9C, gUnk_0815A59A},
    {gUnk_09A3D6BC, 32, {0, 0}, gUnk_099A118A, 544, {0, 0}, gUnk_099A1170, gUnk_0815A57C},
    {gUnk_09A3D6DC, 32, {0, 0}, gUnk_099A13CC, 544, {0, 0}, gUnk_099A13AC, gUnk_0815A5BE},
    {gUnk_09A3D71C, 32, {0, 0}, gUnk_099A181A, 768, {0, 0}, gUnk_099A1800, gUnk_0815A5D4},
    {gUnk_09A3D5FC, 32, {0, 0}, gUnk_099A0442, 544, {0, 0}, gUnk_099A0428, gUnk_0815A62A},
    {gUnk_09A3D61C, 32, {0, 0}, gUnk_099A067E, 544, {0, 0}, gUnk_099A0664, gUnk_0815A518},
    {gUnk_09A3D73C, 32, {0, 0}, gUnk_099A1B30, 512, {0, 0}, gUnk_099A1B1C, gUnk_0815A60E},
    {gUnk_09A3D75C, 32, {0, 0}, gUnk_099A1D44, 512, {0, 0}, gUnk_099A1D30, gUnk_0815A64A},
    {gUnk_09A3D6FC, 32, {0, 0}, gUnk_099A1600, 512, {0, 0}, gUnk_099A15EC, gUnk_0815A5F2},
#elif defined(VERSION_JP)
    {NULL, 0, {0, 0}, NULL, 0, {0, 0}, NULL, NULL},
    {gUnk_09A3D65C, 32, {0, 0}, gUnk_099A0B5C, 576, {0, 0}, gUnk_099A0B3C, gUnkJp_0814E590},
    {gUnk_09A3D69C, 32, {0, 0}, gUnk_099A0F70, 512, {0, 0}, gUnk_099A0F5C, gUnkJp_0814E5E4},
    {gUnk_09A3D63C, 32, {0, 0}, gUnk_099A08BA, 640, {0, 0}, gUnk_099A08A0, gUnkJp_0814E5CC},
    {gUnk_09A3D5DC, 32, {0, 0}, gUnk_099A0206, 544, {0, 0}, gUnk_099A01EC, gUnkJp_0814E59C},
    {gUnk_09A3D67C, 32, {0, 0}, gUnk_099A0DBC, 416, {0, 0}, gUnk_099A0D9C, gUnkJp_0814E5AC},
    {gUnk_09A3D6BC, 32, {0, 0}, gUnk_099A118A, 544, {0, 0}, gUnk_099A1170, gUnkJp_0814E5B8},
    {gUnk_09A3D6DC, 32, {0, 0}, gUnk_099A13CC, 544, {0, 0}, gUnk_099A13AC, gUnkJp_0814E5F4},
    {gUnk_09A3D71C, 32, {0, 0}, gUnk_099A181A, 768, {0, 0}, gUnk_099A1800, gUnkJp_0814E618},
    {gUnk_09A3D5FC, 32, {0, 0}, gUnk_099A0442, 544, {0, 0}, gUnk_099A0428, gUnkJp_0814E62C},
    {gUnk_09A3D61C, 32, {0, 0}, gUnk_099A067E, 544, {0, 0}, gUnk_099A0664, gUnkJp_0814E57C},
    {gUnk_09A3D73C, 32, {0, 0}, gUnk_099A1B30, 512, {0, 0}, gUnk_099A1B1C, gUnkJp_0814E644},
    {gUnk_09A3D75C, 32, {0, 0}, gUnk_099A1D44, 512, {0, 0}, gUnk_099A1D30, gUnkJp_0814E658},
    {gUnk_09A3D6FC, 32, {0, 0}, gUnk_099A1600, 512, {0, 0}, gUnk_099A15EC, gUnkJp_0814E604},
#elif defined(VERSION_EU)
    {NULL, 0, {0, 0}, NULL, 0, {0, 0}, NULL, NULL},
    {gUnk_09A3D65C, 32, {0, 0}, gUnk_099A0B5C, 576, {0, 0}, gUnk_099A0B3C, &gUnkEu_0888E3A0},
    {gUnk_09A3D69C, 32, {0, 0}, gUnk_099A0F70, 512, {0, 0}, gUnk_099A0F5C, &gUnkEu_0888E578},
    {gUnk_09A3D63C, 32, {0, 0}, gUnk_099A08BA, 640, {0, 0}, gUnk_099A08A0, &gUnkEu_0888E530},
    {gUnk_09A3D5DC, 32, {0, 0}, gUnk_099A0206, 544, {0, 0}, gUnk_099A01EC, &gUnkEu_0888E410},
    {gUnk_09A3D67C, 32, {0, 0}, gUnk_099A0DBC, 416, {0, 0}, gUnk_099A0D9C, &gUnkEu_0888E450},
    {gUnk_09A3D6BC, 32, {0, 0}, gUnk_099A118A, 544, {0, 0}, gUnk_099A1170, &gUnkEu_0888E4C0},
    {gUnk_09A3D6DC, 32, {0, 0}, gUnk_099A13CC, 544, {0, 0}, gUnk_099A13AC, &gUnkEu_0888E5DC},
    {gUnk_09A3D71C, 32, {0, 0}, gUnk_099A181A, 768, {0, 0}, gUnk_099A1800, &gUnkEu_0888E6BC},
    {gUnk_09A3D5FC, 32, {0, 0}, gUnk_099A0442, 544, {0, 0}, gUnk_099A0428, &gUnkEu_0888E72C},
    {gUnk_09A3D61C, 32, {0, 0}, gUnk_099A067E, 544, {0, 0}, gUnk_099A0664, &gUnkEu_0888E364},
    {gUnk_09A3D73C, 32, {0, 0}, gUnk_099A1B30, 512, {0, 0}, gUnk_099A1B1C, &gUnkEu_0888E78C},
    {gUnk_09A3D75C, 32, {0, 0}, gUnk_099A1D44, 512, {0, 0}, gUnk_099A1D30, &gUnkEu_0888E804},
    {gUnk_09A3D6FC, 32, {0, 0}, gUnk_099A1600, 512, {0, 0}, gUnk_099A15EC, &gUnkEu_0888E654},
#endif
};
