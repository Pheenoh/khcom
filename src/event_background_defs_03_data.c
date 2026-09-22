#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2B7C[];
extern const void* gUnk_09EE2BBC[];
extern const void* gUnk_09EE2BFC[];
extern const void* gUnk_09EE2C3C[];

EventBackgroundDef gUnk_08F7DDB0 = {
    gUnk_0947D3D8,
    0,
    gUnk_09615B58,
    gUnk_09EE2B7C,
    0,
    gUnk_09EE2BBC,
#ifdef VERSION_EU
    15120,
#else
    21952,
#endif
    0,
    288,
    4,
    4,
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

EventBackgroundDef gUnk_08F7DDE0 = {
    gUnk_09482998,
    0,
    gUnk_09615C78,
    gUnk_09EE2BFC,
    gUnk_09EE2C3C,
    0,
#ifdef VERSION_EU
    9844,
#else
    32640,
#endif
    0,
    256,
    4,
    4,
    2,
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
