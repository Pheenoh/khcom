#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3194[];
extern const void* gUnk_09EE31A4[];

EventBackgroundDef gUnk_08F7EC1C = {
    gUnk_0948CC98,
    0,
    gUnk_09615F98,
    gUnk_09EE3194,
    gUnk_09EE31A4,
    0,
#ifdef VERSION_EU
    5304,
#else
    9504,
#endif
    0,
    64,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7EC08,
    1,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
