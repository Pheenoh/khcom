#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3304[];
extern const void* gUnk_09EE3344[];

EventBackgroundDef gUnk_08F7EECC = {
    gUnk_094C6378,
    0,
    gUnk_09616FD8,
    gUnk_09EE3304,
    gUnk_09EE3344,
    0,
#ifdef VERSION_EU
    6096,
#else
    14816,
#endif
    0,
    320,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7EEB8,
    1,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
