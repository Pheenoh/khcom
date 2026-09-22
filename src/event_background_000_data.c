#include "event_background_000_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3244[];
extern const void* gUnk_09EE3284[];
extern const void* gUnk_09EE32C4[];

const EventBackgroundDef gUnk_08F7EE70 = {
    gUnk_094B9798,
    0,
    gUnk_09616D58,
    gUnk_09EE3244,
    gUnk_09EE3284,
    gUnk_09EE32C4,
#ifdef VERSION_EU
    13896,
#else
    28256,
#endif
    0,
    320,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7EE5C,
    1,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
