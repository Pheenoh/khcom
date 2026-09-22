#include "event_169_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0901F188[2] = {
    { gUnk_0901F044, 83, { 0, 0, 0 } },
    { gUnk_0901F0F8, 82, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_0901F198 = {
    2,
    { 0, 0, 0 },
    gUnk_0901F188,
    gUnk_0901F024,
    gUnk_0901EF04,
    gUnk_0901F00C,
    0,
    620,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    168,
#else
    170,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
