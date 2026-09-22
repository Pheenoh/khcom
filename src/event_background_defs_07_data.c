#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3088[];
extern const void* gUnk_09EE308C[];
extern const void* gUnk_09EE3090[];
extern const void* gUnk_09EE30A0[];

const EventBackgroundDef gUnk_08F7E8B4 = {
    gUnk_094ADB38,
    0,
    gUnk_09616918,
    gUnk_09EE3088,
    gUnk_09EE308C,
    0,
#ifdef VERSION_EU
    4176,
#else
    7744,
#endif
    0,
    320,
    1,
    1,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7E8A0,
    1,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

const EventBackgroundDef gUnk_08F7E8E4 = {
    gUnk_094AF978,
    0,
    gUnk_09616A58,
    gUnk_09EE3090,
    gUnk_09EE30A0,
    0,
#ifdef VERSION_EU
    6536,
#else
    14112,
#endif
    0,
    256,
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
