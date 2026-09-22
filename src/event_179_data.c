#include "event_179_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09024498[3] = {
    { gUnk_09024180, 44, { 0, 0, 0 } },
    { gUnk_0902430C, 83, { 0, 0, 0 } },
    { gUnk_0902442C, 44, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_090244B0 = {
    3,
    { 0, 0, 0 },
    gUnk_09024498,
    gUnk_09024030,
    gUnk_09023F80,
    gUnk_09024010,
    gUnk_09024130,
    900,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    178,
#else
    180,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
