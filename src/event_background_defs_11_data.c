#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE36D4[];
extern const void* gUnk_09EE36E4[];
extern const void* gUnk_09EE36F4[];
extern const void* gUnk_09EE3704[];
extern const void* gUnk_09EE3714[];
extern const void* gUnk_09EE3724[];

EventBackgroundDef gUnk_08F7F408 = {
    gUnk_0948F1B8,
    0,
    gUnk_09616058,
    gUnk_09EE36D4,
    gUnk_09EE36E4,
    0,
#ifdef VERSION_EU
    11084,
#else
    19712,
#endif
    0,
    256,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7F3F4,
    1,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7F438 = {
    gUnk_09493EB8,
    0,
    gUnk_09616158,
    gUnk_09EE36F4,
    gUnk_09EE3704,
    0,
#ifdef VERSION_EU
    9528,
#else
    18208,
#endif
    0,
    288,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    0,
    0,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7F468 = {
    gUnk_094985D8,
    0,
    gUnk_09616278,
    gUnk_09EE3714,
    gUnk_09EE3724,
    0,
#ifdef VERSION_EU
    5084,
#else
    10688,
#endif
    0,
    480,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    0,
    0,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
