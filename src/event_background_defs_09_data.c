#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE31EC[];
extern const void* gUnk_09EE31FC[];
extern const void* gUnk_09EE320C[];
extern const void* gUnk_09EE321C[];

EventBackgroundDef gUnk_08F7ED48 = {
    gUnk_09902DA4,
    0,
    gUnk_09990984,
    gUnk_09EE31EC,
    gUnk_09EE31FC,
    0,
    32768,
    0,
    384,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    &gUnk_08F7ED34,
    1,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};

EventBackgroundDef gUnk_08F7ED78 = {
    gUnk_094B3098,
    0,
    gUnk_09616B58,
    gUnk_09EE320C,
    gUnk_09EE321C,
    0,
#ifdef VERSION_EU
    3964,
#else
    8352,
#endif
    0,
    224,
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
