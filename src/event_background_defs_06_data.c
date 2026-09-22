#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2DB4[];
extern const void* gUnk_09EE2DBC[];
extern const void* gUnk_09EE2DC4[];
extern const void* gUnk_09EE2DD4[];
extern const void* gUnk_09EE2DE4[];
extern const void* gUnk_09EE2DF4[];
extern const void* gUnk_09EE2E04[];
extern const void* gUnk_09EE2E44[];

EventBackgroundDef gUnk_08F7E210 = {
    gUnk_094AAFF8,
    0,
    gUnk_09616898,
    gUnk_09EE2DB4,
    gUnk_09EE2DBC,
    0,
#ifdef VERSION_EU
    6708,
#else
    11072,
#endif
    0,
    128,
    2,
    1,
    5,
    0,
    { 0, 0, 0 },
    0,
    2,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7E240 = {
    gUnk_094A19D8,
    0,
    gUnk_09616678,
    gUnk_09EE2DC4,
    gUnk_09EE2DD4,
    0,
#ifdef VERSION_EU
    6296,
#else
    12192,
#endif
    0,
    224,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    0,
    2,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7E270 = {
    gUnk_094A4978,
    0,
    gUnk_09616758,
    gUnk_09EE2DE4,
    gUnk_09EE2DF4,
    0,
#ifdef VERSION_EU
    13112,
#else
    26240,
#endif
    0,
    320,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    0,
    2,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7E2A0 = {
    gUnk_098BDA44,
    0,
    gUnk_09990104,
    gUnk_09EE2E04,
    gUnk_09EE2E44,
    0,
    32256,
    0,
    352,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7E1FC,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
