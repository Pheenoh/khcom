#include "event_181_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09024DA8[3] = {
    { gUnk_09024A00, 44, { 0, 0, 0 } },
    { gUnk_09024B8C, 0, { 0, 0, 0 } },
    { gUnk_09024D3C, 89, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09024DC0 = {
    3,
    { 0, 0, 0 },
    gUnk_09024DA8,
    gUnk_090248E0,
    gUnk_09024810,
    gUnk_090248B8,
    0,
    850,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    180,
#else
    182,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
