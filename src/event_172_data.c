#include "event_172_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0902030C[3] = {
    { gUnk_09020114, 44, { 0, 0, 0 } },
    { gUnk_09020210, 82, { 0, 0, 0 } },
    { gUnk_090202A0, 92, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09020324 = {
    3,
    { 0, 0, 0 },
    gUnk_0902030C,
    gUnk_09020024,
    gUnk_0901FF64,
    gUnk_0901FFF4,
    gUnk_090200C4,
    650,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    171,
#else
    173,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
