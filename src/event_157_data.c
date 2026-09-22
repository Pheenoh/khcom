#include "event_157_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09016CA0[3] = {
    { gUnk_090168B0, 83, { 0, 0, 0 } },
    { gUnk_090169F4, 67, { 0, 0, 0 } },
    { gUnk_09016B5C, 82, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09016CB8 = {
    3,
    { 0, 0, 0 },
    gUnk_09016CA0,
    gUnk_09016850,
    gUnk_09016680,
    gUnk_09016830,
    0,
    1700,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    156,
#else
    158,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
