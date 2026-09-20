#include "map_animation_data.h"
#include <stddef.h>
extern u8 gUnk_098EB224[];
extern u8 gUnk_098EAF64[];
extern u8 gUnk_098EADE4[];
extern u8 gUnk_098EACC4[];
extern u8 gUnk_098EAA84[];
extern u8 gUnk_098EA844[];
extern u8 gUnk_094F4238[];
extern u8 gUnk_094EABF8[];
extern u8 gUnk_0948A918[];
extern u8 gUnk_09469B58[];
extern u8 gUnk_09468FF8[];

const MapTileAnimationFrame gUnk_09035348[4] = {
    {0, 18, 0},
    {1024, 12, 0},
    {2048, 12, 0},
    {1024, 12, 0},
};

const MapTileAnimationFrame gUnk_09035358[4] = {
    {0, 15, 0},
    {3232, 15, 0},
    {6464, 15, 0},
    {9696, 15, 0},
};

const MapTileAnimationTrack gUnk_09035368[2] = {
    {gUnk_09035348, gUnk_09468FF8, 4, 0, 3232, 864, {0, 0}},
    {gUnk_09035358, gUnk_09469B58, 4, 0, 0, 3232, {0, 0}},
};

const MapTileAnimationDef gUnk_09035388 = {
    gUnk_09035368, 2, 1, 0,
};

const MapTileAnimationFrame gUnk_09035390[4] = {
    {0, 70, 0},
    {192, 7, 0},
    {384, 15, 0},
    {192, 7, 0},
};

const MapTileAnimationFrame gUnk_090353A0[4] = {
    {0, 25, 0},
    {192, 7, 0},
    {384, 15, 0},
    {192, 7, 0},
};

const MapTileAnimationFrame gUnk_090353B0[4] = {
    {0, 10, 0},
    {96, 10, 0},
    {192, 10, 0},
    {96, 10, 0},
};

const MapTileAnimationFrame gUnk_090353C0[4] = {
    {0, 50, 0},
    {128, 7, 0},
    {256, 10, 0},
    {128, 10, 0},
};

const MapTileAnimationFrame gUnk_090353D0[4] = {
    {0, 10, 0},
    {352, 20, 0},
    {0, 7, 0},
    {352, 150, 0},
};

const MapTileAnimationFrame gUnk_090353E0[4] = {
    {0, 50, 0},
    {128, 5, 0},
    {0, 7, 0},
    {128, 5, 0},
};

const MapTileAnimationTrack gUnk_090353F0[6] = {
    {gUnk_09035390, gUnk_098EA844, 4, 0, 2048, 192, {0, 0}},
    {gUnk_090353A0, gUnk_098EAA84, 4, 0, 2240, 192, {0, 0}},
    {gUnk_090353B0, gUnk_098EACC4, 4, 0, 2432, 96, {0, 0}},
    {gUnk_090353C0, gUnk_098EADE4, 4, 0, 2528, 128, {0, 0}},
    {gUnk_090353D0, gUnk_098EAF64, 4, 0, 3072, 352, {0, 0}},
    {gUnk_090353E0, gUnk_098EB224, 4, 0, 3424, 128, {0, 0}},
};

const MapTileAnimationDef gUnk_09035450 = {
    gUnk_090353F0, 6, 0, 0,
};

const MapTileAnimationFrame gUnk_09035458[5] = {
    {0, 6, 0},
    {1024, 6, 0},
    {2048, 6, 0},
    {3072, 6, 0},
    {4096, 6, 0},
};

const MapTileAnimationTrack gUnk_0903546C = {
    gUnk_09035458, gUnk_0948A918, 5, 0, 3072, 896, {0, 0},
};

const MapTileAnimationDef gUnk_0903547C = {
    &gUnk_0903546C, 1, 1, 0,
};

const MapTileAnimationFrame gUnk_09035484[4] = {
    {0, 30, 0},
    {3072, 30, 0},
    {6144, 30, 0},
    {9216, 30, 0},
};

const MapTileAnimationTrack gUnk_09035494 = {
    gUnk_09035484, gUnk_094EABF8, 4, 0, -15360, 3072, {0, 0},
};

const MapTileAnimationDef gUnk_090354A4 = {
    &gUnk_09035494, 1, 1, 0,
};

const MapTileAnimationFrame gUnk_090354AC[6] = {
    {0, 20, 0},
    {1024, 20, 0},
    {2048, 20, 0},
    {3072, 20, 0},
    {4096, 20, 0},
    {5120, 20, 0},
};

const MapTileAnimationTrack gUnk_090354C4 = {
    gUnk_090354AC, gUnk_094F4238, 6, 0, -5120, 1024, {0, 0},
};

const MapTileAnimationDef gUnk_090354D4 = {
    &gUnk_090354C4, 1, 1, 0,
};

const MapTileAnimationDef* gUnk_09EE4A2C[6] = {
    &gUnk_09035388,
    &gUnk_09035450,
    &gUnk_0903547C,
    &gUnk_090354A4,
    &gUnk_090354D4,
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A44 = {
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A48 = {
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A4C = {
    NULL,
};
