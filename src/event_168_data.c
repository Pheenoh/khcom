#include "event_168_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0901EAB0[5] = {
    { gUnk_0901E5C4, 81, { 0, 0, 0 } },
    { gUnk_0901E72C, 35, { 0, 0, 0 } },
    { gUnk_0901E804, 86, { 0, 0, 0 } },
    { gUnk_0901E84C, 65, { 0, 0, 0 } },
    { gUnk_0901EA20, 85, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_0901EAD8 = {
    5,
    { 0, 0, 0 },
    gUnk_0901EAB0,
    gUnk_0901E564,
    gUnk_0901E38C,
    gUnk_0901E554,
    0,
    1685,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    167,
#else
    169,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
