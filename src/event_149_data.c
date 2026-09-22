#include "event_149_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_090109A8[4] = {
    { gUnk_090103C0, 44, { 0, 0, 0 } },
    { gUnk_09010768, 88, { 0, 0, 0 } },
    { gUnk_09010888, 50, { 0, 0, 0 } },
    { gUnk_0901093C, 93, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_090109C8 = {
    4,
    { 0, 0, 0 },
    gUnk_090109A8,
    gUnk_09010220,
    gUnk_09010030,
    gUnk_090101F8,
    0,
    2390,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    148,
#else
    150,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
