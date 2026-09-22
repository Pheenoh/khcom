#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE365C[];
extern const void* gUnk_09EE3680[];

EventBackgroundDef gUnk_08F7F2D4 = {
    gUnk_094EDAF8,
    0,
    gUnk_096179F8,
    gUnk_09EE365C,
    gUnk_09EE3680,
    0,
#ifdef VERSION_EU
    9452,
#else
    26432,
#endif
    0,
    288,
    3,
    3,
    4,
    0,
    { 0, 0, 0 },
    &gUnk_08F7F2C0,
    2,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};
