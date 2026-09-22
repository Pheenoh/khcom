#include "event_background_data.h"
#include "event_background_assets.h"

extern const void* gUnk_09EE2904[];
extern const void* gUnk_09EE2914[];
extern const void* gUnk_09EE2924[];
extern const void* gUnk_09EE2964[];
extern const void* gUnk_09EE29A4[];
extern const void* gUnk_09EE29A8[];
extern const void* gUnk_09EE29E8[];

const EventBackgroundDef gUnk_08F7DB70 = {
    gUnk_09452B18,
    0,
    gUnk_09615518,
    gUnk_09EE2904,
    0,
    gUnk_09EE2914,
#ifdef VERSION_EU
    13644,
#else
    27200,
#endif
    0,
    160,
    2,
    2,
    5,
    0,
    { 0, 0, 0 },
    0,
    0,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

const EventBackgroundDef gUnk_08F7DBA0 = {
    gUnk_09459558,
    0,
    gUnk_096155B8,
    gUnk_09EE2924,
    gUnk_09EE2964,
    0,
#ifdef VERSION_EU
    20144,
#else
    31424,
#endif
    0,
    224,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    0,
    2,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

const EventBackgroundDef gUnk_08F7DBD0 = {
    gUnk_09459558,
    0,
    gUnk_096155B8,
    gUnk_09EE2924,
    0,
    0,
#ifdef VERSION_EU
    20144,
#else
    31424,
#endif
    0,
    224,
    4,
    4,
    5,
    0,
    { 0, 0, 0 },
    0,
    2,
    0,
#ifdef VERSION_EU
    { 3, 0 },
#else
    { 0, 0 },
#endif
};

const EventBackgroundDef gUnk_08F7DC00 = {
    gUnk_0964AE84,
    0,
    gUnk_096FB164,
    gUnk_09EE29A4,
    0,
    0,
    32768,
    0,
    320,
    1,
    1,
    5,
    0,
    { 0, 0, 0 },
    0,
    1,
    0,
    { 0, 0 },
};

const EventBackgroundDef gUnk_08F7DC30 = {
    gUnk_09443138,
    0,
    gUnk_096151D8,
    gUnk_09EE29A8,
    0,
    gUnk_09EE29E8,
#ifdef VERSION_EU
    12640,
#else
    32768,
#endif
    0,
    512,
    4,
    4,
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
