#include "anim.h"
#include "aux_animation_09EDF764_data.h"
#include "aux_animation_09EDF8F0_data.h"
#include "aux_animation_09EE12A4_data.h"
#include "event_sprite_09EEB110_data.h"
#include "card_animation_09EEFD7C_data.h"
#include "room_resources_data.h"
#include "worldinspect_resources_data.h"
#include "room_data.h"
#include "room_record_assets.h"

const EmyKind gUnk_09991F44 =
{32, 100, 16, 16, 0, 100, 1}
;

const RoomTableEntry gUnk_09991F54[6] = {
#if defined(VERSION_US)
    {256, 0, 0, -15872, 0, 0, gRoomAssetUs_099939FA, gUnk_09EF96A4, gUnk_09EF9684, 8, 0},
    {256, -2560, 2048, -25088, 0, 0, gRoomAssetUs_09995E9C, gUnk_09EF96C8, gUnk_09EF96B0, 6, 0},
    {256, 2560, 5632, -14848, 0, 0, gRoomAssetUs_09996B82, gUnk_09EF96EC, gUnk_09EF96D0, 7, 0},
    {256, -11264, -3328, -12288, 0, 0, gRoomAssetUs_09997F64, gUnk_09EF9710, gUnk_09EF96F4, 7, 0},
    {256, 3840, 512, -2048, 0, 0, gRoomAssetUs_09999244, gUnk_09EF971C, gUnk_09EF9718, 1, 0},
    {256, -3328, -1792, -2048, 0, 0, gRoomAssetUs_099995FC, gUnk_09EF9724, gUnk_09EF9720, 1, 0},
#elif defined(VERSION_JP)
    {256, 0, 0, -15872, 0, 0, gRoomAssetJp_0994850E, gUnk_09EF96A4, gUnk_09EF9684, 8, 0},
    {256, -2560, 2048, -25088, 0, 0, gRoomAssetJp_0994A9B0, gUnk_09EF96C8, gUnk_09EF96B0, 6, 0},
    {256, 2560, 5632, -14848, 0, 0, gRoomAssetJp_0994B696, gUnk_09EF96EC, gUnk_09EF96D0, 7, 0},
    {256, -11264, -3328, -12288, 0, 0, gRoomAssetJp_0994CA78, gUnk_09EF9710, gUnk_09EF96F4, 7, 0},
    {256, 3840, 512, -2048, 0, 0, gRoomAssetJp_0994DD58, gUnk_09EF971C, gUnk_09EF9718, 1, 0},
    {256, -3328, -1792, -2048, 0, 0, gRoomAssetJp_0994E110, gUnk_09EF9724, gUnk_09EF9720, 1, 0},
#elif defined(VERSION_EU)
    {256, 0, 0, -15872, 0, 0, gRoomAssetEu_09999CB6, gUnk_09EF96A4, gUnk_09EF9684, 8, 0},
    {256, -2560, 2048, -25088, 0, 0, gRoomAssetEu_0999C158, gUnk_09EF96C8, gUnk_09EF96B0, 6, 0},
    {256, 2560, 5632, -14848, 0, 0, gRoomAssetEu_0999CE3E, gUnk_09EF96EC, gUnk_09EF96D0, 7, 0},
    {256, -11264, -3328, -12288, 0, 0, gRoomAssetEu_0999E220, gUnk_09EF9710, gUnk_09EF96F4, 7, 0},
    {256, 3840, 512, -2048, 0, 0, gRoomAssetEu_0999F500, gUnk_09EF971C, gUnk_09EF9718, 1, 0},
    {256, -3328, -1792, -2048, 0, 0, gRoomAssetEu_0999F8B8, gUnk_09EF9724, gUnk_09EF9720, 1, 0},
#endif
};

const BosMapConfig gUnk_0999202C =
#if defined(VERSION_US)
{gRoomAssetUs_099A899C, 16352, 0, gRoomAssetUs_09A3C75C, 320, 0, {gRoomAssetUs_09A1E0DC, gRoomAssetUs_09A1F0DC, gRoomAssetUs_09A1E8DC, gRoomAssetUs_09A1F8DC}}
#elif defined(VERSION_JP)
{gRoomAssetJp_0995D424, 16352, 0, gRoomAssetJp_099F11E4, 320, 0, {gRoomAssetJp_099D2B64, gRoomAssetJp_099D3B64, gRoomAssetJp_099D3364, gRoomAssetJp_099D4364}}
#elif defined(VERSION_EU)
{gRoomAssetEu_099B6920, 16352, 0, gRoomAssetEu_09A9A220, 320, 0, {gRoomAssetEu_09A6FCA0, gRoomAssetEu_09A70CA0, gRoomAssetEu_09A704A0, gRoomAssetEu_09A714A0}}
#endif
;

const s32 gUnk_0999204C[32] = {
    6,
    12,
    18,
    25,
    31,
    37,
    44,
    50,
    57,
    64,
    70,
    77,
    84,
    91,
    98,
    106,
    113,
    121,
    128,
    136,
    145,
    153,
    162,
    171,
    180,
    189,
    199,
    210,
    220,
    232,
    243,
    256,
};
