#include "event_184_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09026FCC[4] = {
    { gUnk_09026B28, 83, { 0, 0, 0 } },
    { gUnk_09026C90, 43, { 0, 0, 0 } },
    { gUnk_09026DF8, 65, { 0, 0, 0 } },
    { gUnk_09026F60, 93, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09026FEC = {
    4,
    { 0, 0, 0 },
    gUnk_09026FCC,
    gUnk_09026A18,
    gUnk_09026840,
    gUnk_090269F0,
    gUnk_09026AD8,
    1710,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    183,
#else
    185,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
