#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE304C[];
extern const void* gUnk_09EE305C[];

EventBackgroundDef gUnk_08F7E764 = {
    gUnk_098B3A44,
    0,
    gUnk_0998FFA4,
    gUnk_09EE304C,
    gUnk_09EE305C,
    0,
    30720,
    0,
    352,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7E750,
    0,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
