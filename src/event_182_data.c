#include "event_182_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09025B28[3] = {
    { gUnk_090257C8, 44, { 0, 0, 0 } },
    { gUnk_09025954, 34, { 0, 0, 0 } },
    { gUnk_09025A2C, 65, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09025B40 = {
    3,
    { 0, 0, 0 },
    gUnk_09025B28,
    gUnk_09025698,
    gUnk_090254C8,
    gUnk_09025678,
    gUnk_09025778,
    1770,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    181,
#else
    183,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
