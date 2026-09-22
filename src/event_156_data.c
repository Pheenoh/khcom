#include "event_156_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_09015F80[3] = {
    { gUnk_09015ADC, 44, { 0, 0, 0 } },
    { gUnk_09015CD4, 64, { 0, 0, 0 } },
    { gUnk_09015E18, 50, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_09015F98 = {
    3,
    { 0, 0, 0 },
    gUnk_09015F80,
    gUnk_09015A4C,
    gUnk_0901582C,
    gUnk_09015A24,
    gUnk_09015A8C,
    1250,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    155,
#else
    157,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
