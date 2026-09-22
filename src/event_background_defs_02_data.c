#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2AA8[];
extern const void* gUnk_09EE2AE8[];
extern const void* gUnk_09EE2B68[];

EventBackgroundDef gUnk_08F7DC90 = {
    gUnk_09461018,
    0,
    gUnk_09615698,
    gUnk_09EE2AA8,
    gUnk_09EE2AE8,
    0,
#ifdef VERSION_EU
    15520,
#else
    32736,
#endif
    0,
    288,
    4,
    4,
    0,
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

EventBackgroundDef gUnk_08F7DCC0 = {
#ifdef VERSION_EU
    gUnkEu_08F7042C,
#else
    gUnk_08CB06E4,
#endif
    0,
    gUnk_08F69404,
    gUnk_09EE2B68,
    0,
    0,
#ifdef VERSION_EU
    6164,
#else
    16384,
#endif
    0,
    192,
    1,
    1,
    5,
    1,
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
