#include "event_167_data.h"
#include "event_chara_assets.h"
#include "event_sequence_assets.h"

const EventCharaTrack gUnk_0901DB8C[5] = {
    { gUnk_0901D2F8, 43, { 0, 0, 0 } },
    { gUnk_0901D580, 81, { 0, 0, 0 } },
    { gUnk_0901D3F4, 67, { 0, 0, 0 } },
    { gUnk_0901D778, 50, { 0, 0, 0 } },
    { gUnk_0901D850, 65, { 0, 0, 0 } },
};

const EventSequenceDef gUnk_0901DBB4 = {
    5,
    { 0, 0, 0 },
    gUnk_0901DB8C,
    gUnk_0901D1C8,
    gUnk_0901CEA0,
    gUnk_0901D1A0,
    gUnk_0901D2A8,
#ifdef VERSION_EU
    2270,
#else
    2130,
#endif
    0,
    1,
    0,
    0,
    0,
    0,
    0,
#ifdef VERSION_EU
    166,
#else
    168,
#endif
    0,
    { 0, 0 },
    65535,
    0,
    255,
    255,
};
