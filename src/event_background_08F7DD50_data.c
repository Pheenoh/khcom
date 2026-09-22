#include "event_background_08F7DD50_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2B74[];

const EventBackgroundDef gUnk_08F7DD50 = {
#ifdef VERSION_EU
    gUnkEu_08CB0D3C,
#else
    gUnk_08C8C824,
#endif
    0,
    gUnk_08F68A84,
    gUnk_09EE2B74,
    0,
    0,
    16384,
    0,
    256,
    1,
    1,
    5,
    1,
    { 0, 0, 0 },
    0,
    2,
    0,
#ifdef VERSION_EU
    { 2, 0 },
#else
    { 0, 0 },
#endif
};
