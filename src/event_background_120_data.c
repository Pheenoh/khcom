#include "event_background_120_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3170[];
extern const void* gUnk_09EE3174[];
extern const void* gUnk_09EE3178[];

const EventBackgroundDef gUnk_08F7EB10 = {
    gUnk_098C9D84,
    gUnk_098D1584,
    gUnk_09990264,
    gUnk_09EE3170,
    gUnk_09EE3174,
    gUnk_09EE3178,
    30720,
    12160,
    352,
    1,
    1,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7EAFC,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
