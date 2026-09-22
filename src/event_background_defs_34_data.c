#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE3734[];
extern const void* gUnk_09EE3774[];
extern const void* gUnk_09EE37B4[];

EventBackgroundDef gUnk_08F7F4E8 = {
    gUnk_099199C4,
    gUnk_099211C4,
    gUnk_09990C64,
    gUnk_09EE3734,
    gUnk_09EE3774,
    gUnk_09EE37B4,
    30720,
    12224,
    352,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7F4D4,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
