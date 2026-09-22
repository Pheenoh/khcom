#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE35B4[];
extern const void* gUnk_09EE35B8[];
extern const void* gUnk_09EE35BC[];
extern const void* gUnk_09EE35CC[];
extern const void* gUnk_09EE35DC[];
extern const void* gUnk_09EE35EC[];

EventBackgroundDef gUnk_08F7F16C = {
    gUnk_0992FF64,
    0,
    gUnk_09990F44,
    gUnk_09EE35B4,
    gUnk_09EE35B8,
    0,
    32768,
    0,
    384,
    1,
    1,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7F158,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7F19C = {
    gUnk_094DB238,
    0,
    gUnk_09617578,
    gUnk_09EE35BC,
    gUnk_09EE35CC,
    0,
#ifdef VERSION_EU
    12208,
#else
    24320,
#endif
    0,
    480,
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

EventBackgroundDef gUnk_08F7F1CC = {
    gUnk_094E1138,
    0,
    gUnk_09617758,
    gUnk_09EE35DC,
    gUnk_09EE35EC,
    0,
#ifdef VERSION_EU
    10652,
#else
    23488,
#endif
    0,
    416,
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
