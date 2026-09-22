#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3080[];
extern const void* gUnk_09EE3084[];

EventBackgroundDef gUnk_08F7E84C = {
    gUnk_098F71A4,
    0,
    gUnk_09990804,
    gUnk_09EE3080,
    gUnk_09EE3084,
    0,
    32768,
    0,
    384,
    1,
    1,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7E838,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
