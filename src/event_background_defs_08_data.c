#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE31BC[];
extern const void* gUnk_09EE31CC[];
extern const void* gUnk_09EE31DC[];

const EventBackgroundDef gUnk_08F7ECB0 = {
    gUnk_09902DA4,
    0,
    gUnk_09990984,
    gUnk_09EE31BC,
    gUnk_09EE31CC,
    0,
    32768,
    0,
    384,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7EC9C,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};

const EventBackgroundDef gUnk_08F7ECE0 = {
    gUnk_094B5138,
    0,
    gUnk_09616C38,
    gUnk_09EE31DC,
    0,
    0,
#ifdef VERSION_EU
    11560,
#else
    18016,
#endif
    0,
    288,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    0,
    1,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
