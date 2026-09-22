#include "event_173_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09020E64[5] = {
    { gUnk_09020A50, 44, { 0, 0, 0 } },
    { gUnk_09020C6C, 64, { 0, 0, 0 } },
    { gUnk_09020CD8, 87, { 0, 0, 0 } },
    { gUnk_09020D8C, 69, { 0, 0, 0 } },
    { gUnk_09020DF8, 93, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09020E8C = {
    5,
    { 0, 0, 0 },
    gUnk_09020E64,
    gUnk_090208F0,
    gUnk_09020768,
    gUnk_090208D0,
    0,
    1485,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    172,
#else
    174,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
