#include "event_194_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0902F2A0[5] = {
    { gUnk_0902ED48, 44, { 0, 0, 0 } },
    { gUnk_0902EF64, 64, { 0, 0, 0 } },
    { gUnk_0902F060, 87, { 0, 0, 0 } },
    { gUnk_0902F138, 69, { 0, 0, 0 } },
    { gUnk_0902F1EC, 92, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_0902F2C8 = {
    5,
    { 0, 0, 0 },
    gUnk_0902F2A0,
    gUnk_0902EB78,
    gUnk_0902EA70,
    gUnk_0902EB18,
    gUnk_0902ECF8,
    1680,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    193,
#else
    195,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
