#include "event_164_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0901B354[3] = {
    { gUnk_0901AFD0, 44, { 0, 0, 0 } },
    { gUnk_0901B1C8, 65, { 0, 0, 0 } },
    { gUnk_0901B2E8, 92, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_0901B36C = {
    3,
    { 0, 0, 0 },
    gUnk_0901B354,
    gUnk_0901AED0,
    gUnk_0901ADB0,
    gUnk_0901AEB8,
    0,
    760,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    163,
#else
    165,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
