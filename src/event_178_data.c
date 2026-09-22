#include "event_178_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09023C94[3] = {
    { gUnk_090237F0, 44, { 0, 0, 0 } },
    { gUnk_09023B2C, 83, { 0, 0, 0 } },
    { gUnk_09023C04, 34, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09023CAC = {
    3,
    { 0, 0, 0 },
    gUnk_09023C94,
    gUnk_090236E0,
    gUnk_09023570,
    gUnk_090236C0,
    gUnk_090237A0,
    1700,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    177,
#else
    179,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
