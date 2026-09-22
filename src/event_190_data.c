#include "event_190_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0902D110[4] = {
    { gUnk_0902CA74, 44, { 0, 0, 0 } },
    { gUnk_0902CCD8, 69, { 0, 0, 0 } },
    { gUnk_0902CF60, 84, { 0, 0, 0 } },
    { gUnk_0902CFF0, 50, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_0902D130 = {
    4,
    { 0, 0, 0 },
    gUnk_0902D110,
    gUnk_0902C9F4,
    gUnk_0902C85C,
    gUnk_0902C9C4,
    0,
    1640,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    189,
#else
    191,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
