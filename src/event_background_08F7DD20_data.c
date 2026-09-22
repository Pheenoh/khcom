#include "event_background_08F7DD20_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2B70[];

const EventBackgroundDef gUnk_08F7DD20 = {
#ifdef VERSION_EU
    gUnkEu_08CA8D3C,
#else
    gUnk_08C84824,
#endif
    0,
    gUnk_08F68904,
    gUnk_09EE2B70,
    0,
    0,
    16384,
    0,
    192,
    1,
    1,
    5,
    1,
    { 0, 0, 0 },
    0,
    0,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
