#include "event_175_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09021ADC[2] = {
    { gUnk_090219BC, 83, { 0, 0, 0 } },
    { gUnk_09021A4C, 43, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09021AEC = {
    2,
    { 0, 0, 0 },
    gUnk_09021ADC,
    gUnk_0902197C,
    gUnk_09021834,
    gUnk_0902196C,
    0,
    560,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    174,
#else
    176,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
