#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2CCC[];
extern const void* gUnk_09EE2CDC[];
extern const void* gUnk_09EE2CEC[];
extern const void* gUnk_09EE2D2C[];

EventBackgroundDef gUnk_08F7DFA8 = {
    gUnk_098EB324,
    gUnk_098F30A4,
    gUnk_099906A4,
    gUnk_09EE2CCC,
    gUnk_09EE2CDC,
    0,
    32128,
    11520,
    352,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7DF48,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7DFD8 = {
    gUnk_09475AF8,
    0,
    gUnk_09615A38,
    gUnk_09EE2CEC,
    gUnk_09EE2D2C,
    0,
#ifdef VERSION_EU
    12192,
#else
    30944,
#endif
    0,
    224,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7DF94,
    3,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
