#include <stddef.h>
#include "room_data.h"
#include "room_record_assets.h"

EmyKind gUnk_09991F44 __attribute__((section(".data_gUnk_09991F44"))) =
{32, 100, 16, 16, 0, 100, 1}
;

RoomTableEntry gUnk_09991F54[6] __attribute__((section(".data_gUnk_09991F54"))) = {
#if defined(VERSION_US)
    {256, 0, 0, -15872, 0, 0, gRoomAssetUs_099939FA, gRoomAssetUs_09EF96A4, gRoomAssetUs_09EF9684, 8, 0},
    {256, -2560, 2048, -25088, 0, 0, gRoomAssetUs_09995E9C, gRoomAssetUs_09EF96C8, gRoomAssetUs_09EF96B0, 6, 0},
    {256, 2560, 5632, -14848, 0, 0, gRoomAssetUs_09996B82, gRoomAssetUs_09EF96EC, gRoomAssetUs_09EF96D0, 7, 0},
    {256, -11264, -3328, -12288, 0, 0, gRoomAssetUs_09997F64, gRoomAssetUs_09EF9710, gRoomAssetUs_09EF96F4, 7, 0},
    {256, 3840, 512, -2048, 0, 0, gRoomAssetUs_09999244, gRoomAssetUs_09EF971C, gRoomAssetUs_09EF9718, 1, 0},
    {256, -3328, -1792, -2048, 0, 0, gRoomAssetUs_099995FC, gRoomAssetUs_09EF9724, gRoomAssetUs_09EF9720, 1, 0},
#elif defined(VERSION_JP)
    {256, 0, 0, -15872, 0, 0, gRoomAssetJp_0994850E, gRoomAssetJp_09ED0A90, gRoomAssetJp_09ED0A70, 8, 0},
    {256, -2560, 2048, -25088, 0, 0, gRoomAssetJp_0994A9B0, gRoomAssetJp_09ED0AB4, gRoomAssetJp_09ED0A9C, 6, 0},
    {256, 2560, 5632, -14848, 0, 0, gRoomAssetJp_0994B696, gRoomAssetJp_09ED0AD8, gRoomAssetJp_09ED0ABC, 7, 0},
    {256, -11264, -3328, -12288, 0, 0, gRoomAssetJp_0994CA78, gRoomAssetJp_09ED0AFC, gRoomAssetJp_09ED0AE0, 7, 0},
    {256, 3840, 512, -2048, 0, 0, gRoomAssetJp_0994DD58, gRoomAssetJp_09ED0B08, gRoomAssetJp_09ED0B04, 1, 0},
    {256, -3328, -1792, -2048, 0, 0, gRoomAssetJp_0994E110, gRoomAssetJp_09ED0B10, gRoomAssetJp_09ED0B0C, 1, 0},
#elif defined(VERSION_EU)
    {256, 0, 0, -15872, 0, 0, gRoomAssetEu_09999CB6, gRoomAssetEu_09F85120, gRoomAssetEu_09F85100, 8, 0},
    {256, -2560, 2048, -25088, 0, 0, gRoomAssetEu_0999C158, gRoomAssetEu_09F85144, gRoomAssetEu_09F8512C, 6, 0},
    {256, 2560, 5632, -14848, 0, 0, gRoomAssetEu_0999CE3E, gRoomAssetEu_09F85168, gRoomAssetEu_09F8514C, 7, 0},
    {256, -11264, -3328, -12288, 0, 0, gRoomAssetEu_0999E220, gRoomAssetEu_09F8518C, gRoomAssetEu_09F85170, 7, 0},
    {256, 3840, 512, -2048, 0, 0, gRoomAssetEu_0999F500, gRoomAssetEu_09F85198, gRoomAssetEu_09F85194, 1, 0},
    {256, -3328, -1792, -2048, 0, 0, gRoomAssetEu_0999F8B8, gRoomAssetEu_09F851A0, gRoomAssetEu_09F8519C, 1, 0},
#endif
};

s32 gUnk_0999204C[32] __attribute__((section(".data_gUnk_0999204C"))) = {
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
