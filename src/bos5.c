#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "display.h"
#include "fade.h"
#include "text.h"
#include "monsgage.h"
#include "bos5.h"
#include "anim.h"
#include "ms_charge.h"
#include "mode_mapinspect.h"
#include "mode_worldwarp.h"
#include "mode_battle_data.h"
#include "worldinspect_assets.h"
#include "sprites_bos5.h"
#include "sprites_worldinspect.h"

const char gTaskNameBosGa[] = "task_bos_ga";

const EmyKind gUnk_099920D8 = { 37, 1000, 16, 16, 0, 60, 1 };

const MdMapData gUnk_099920E8 = {
    gUnk_099AC97C, 32768, { 0, 0 }, gUnk_09A3C8BC, 192, { 0, 0 }, { gUnk_09A208DC, gUnk_09A210DC, gUnk_09A218DC, gUnk_09A220DC }
};

const GaEntry gUnk_09992108[41] = {
    {
        32, 0, gUnk_099B497C, 16864, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A228DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D559C, 1952, gUnk_099A7E04 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D06 } },
        { { -100, 0, -45, 0 } },
    },
    {
        32, 0, gUnk_099B497C, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A228DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D559C, 1952, gUnk_099A7E04 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D06 } },
        { { -100, 0, -45, 0 } },
    },
    {
        32, 0, gUnk_099B8B5C, 3872, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A230DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D5D3C, 2176, gUnk_099A7E54 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D34 } },
        { { -101, 0, -34, 0 } },
    },
    {
        32, 0, gUnk_099B9A7C, 4064, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A238DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D65BC, 2048, gUnk_099A7EA0 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -103, 0, -28, 0 } },
    },
    {
        0, 65521, gUnk_099C2E3C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A280DC },
        { { 0xFFF8, 112, 0xFF90, 0, gUnk_099DED9C, 2368, gUnk_099A8400 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -131, 0, -108, 0 } },
    },
    {
        3, 65524, gUnk_099C3F9C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A288DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DF6DC, 2400, gUnk_099A8468 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D34 } },
        { { -142, 0, -105, 0 } },
    },
    {
        4, 65529, gUnk_099C50FC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A290DC },
        { { 0, 112, 0xFF8F, 0, gUnk_099E003C, 2432, gUnk_099A84C4 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D06 } },
        { { -145, 0, -94, 0 } },
    },
    {
        43, 65504, gUnk_099BAA5C, 3712, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A240DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D6DBC, 2368, gUnk_099A7EF8 }, { 11, 56, 0xFFE0, 0, gUnk_099D42FC, 4768, gUnk_099A7C98 } },
        { { -67, 0, -126, 0 } },
    },
    {
        43, 65528, gUnk_099BB8DC, 3712, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A248DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D76FC, 1952, gUnk_099A7F48 }, { 24, 56, 0xFFE2, 0, gUnk_099D42FC, 4768, gUnk_099A7D6E } },
        { { -46, 0, -154, 0 } },
    },
    {
        31, 0, gUnk_099BC75C, 4160, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A250DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D7E9C, 2112, gUnk_099A7FAC }, { 2, 56, 0xFFF2, 0, gUnk_099D42FC, 4768, gUnk_099A7DBE } },
        { { -105, 0, -135, 0 } },
    },
    {
        29, 65531, gUnk_099BD79C, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A258DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D86DC, 2080, gUnk_099A8004 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D06 } },
        { { -123, 0, -42, 0 } },
    },
    {
        25, 65527, gUnk_099BE91C, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A260DC },
        { { 0, 112, 0xFF91, 0, gUnk_099D8EFC, 2368, gUnk_099A805C }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -123, 0, -30, 0 } },
    },
    {
        22, 65519, gUnk_099BFA9C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A268DC },
        { { 0xFFFF, 112, 0xFF90, 0, gUnk_099D983C, 2432, gUnk_099A80D0 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -129, 0, -36, 0 } },
    },
    {
        36, 65518, gUnk_099C0BFC, 4384, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A270DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DA1BC, 2208, gUnk_099A8134 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -115, 0, -31, 0 } },
    },
    {
        35, 65533, gUnk_099C1D1C, 4384, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A278DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DAA5C, 2016, gUnk_099A8190 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -98, 0, -49, 0 } },
    },
    {
        35, 65530, gUnk_099C2E3C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A280DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DB23C, 2336, gUnk_099A81E0 }, { 20, 56, 0xFFCF, 0, gUnk_099D42FC, 4768, gUnk_099A7D6E } },
        { { -94, 0, -100, 0 } },
    },
    {
        45, 65535, gUnk_099C3F9C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A288DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DBB5C, 1920, gUnk_099A8218 }, { 19, 56, 0xFFED, 0, gUnk_099D42FC, 4768, gUnk_099A7D90 } },
        { { -104, 0, -94, 0 } },
    },
    {
        48, 6, gUnk_099C50FC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A290DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DC2DC, 1632, gUnk_099A8270 }, { 17, 56, 0xFFF3, 0, gUnk_099D42FC, 4768, gUnk_099A7DBE } },
        { { -105, 0, -79, 0 } },
    },
    {
        56, 11, gUnk_099C627C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A298DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DC93C, 1408, gUnk_099A82B0 }, { 23, 56, 0xFFF8, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -103, 0, -57, 0 } },
    },
    {
        35, 65533, gUnk_099C73DC, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2A0DC },
        { { 0, 112, 0xFF9A, 0, gUnk_099DCEBC, 2176, gUnk_099A82E4 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -98, 0, -78, 0 } },
    },
    {
        36, 65535, gUnk_099C853C, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2A8DC },
        { { 0, 112, 0xFF92, 0, gUnk_099DD73C, 1920, gUnk_099A8328 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D34 } },
        { { -102, 0, -59, 0 } },
    },
    {
        38, 0, gUnk_099C96BC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2B0DC },
        { { 0, 112, 0xFF89, 0, gUnk_099DDEBC, 1824, gUnk_099A8368 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D34 } },
        { { -102, 0, -52, 0 } },
    },
    {
        37, 0, gUnk_099CA83C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2B8DC },
        { { 0, 112, 0xFF8D, 0, gUnk_099DE5DC, 1984, gUnk_099A83B4 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D06 } },
        { { -100, 0, -50, 0 } },
    },
    {
        5, 5, gUnk_099B9A7C, 4064, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A238DC },
        { { 0xFFFF, 112, 0xFF90, 0, gUnk_099E25DC, 2336, gUnk_099A865C }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -128, 0, -22, 0 } },
    },
    {
        41, 65504, gUnk_099CDBDC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2D0DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D6DBC, 2368, gUnk_099A7EF8 }, { 13, 56, 0xFFDF, 0, gUnk_099D42FC, 4768, gUnk_099A7C98 } },
        { { -108, 0, -88, 0 } },
    },
    {
        46, 65499, gUnk_099BAA5C, 3712, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A240DC },
        { { 11, 112, 0xFF85, 0, gUnk_099DCEBC, 2176, gUnk_099A82E4 }, { 29, 56, 0xFFBA, 0, gUnk_099D42FC, 4768, gUnk_099A7D6E } },
        { { -62, 0, -126, 0 } },
    },
    {
        60, 65491, gUnk_099CB99C, 4320, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2C0DC },
        { { 21, 112, 0xFF70, 0, gUnk_099DD73C, 1920, gUnk_099A8328 }, { 40, 56, 0xFFC4, 0, gUnk_099D42FC, 4768, gUnk_099A7D90 } },
        { { -3, 0, -168, 0 } },
    },
    {
        36, 65527, gUnk_099BC75C, 4160, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A250DC },
        { { 0, 112, 0xFF89, 0, gUnk_099DDEBC, 1824, gUnk_099A8368 }, { 17, 56, 0xFFF3, 0, gUnk_099D42FC, 4768, gUnk_099A7DBE } },
        { { -103, 0, -142, 0 } },
    },
    {
        1, 65530, gUnk_099C627C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A298DC },
        { { 0, 112, 0xFF8F, 0, gUnk_099E003C, 2432, gUnk_099A84C4 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -158, 0, -75, 0 } },
    },
    {
        36, 65518, gUnk_099C0BFC, 4384, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A270DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DA1BC, 2208, gUnk_099A8134 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -115, 0, -31, 0 } },
    },
    {
        35, 65533, gUnk_099C1D1C, 4384, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A278DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DAA5C, 2016, gUnk_099A8190 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -98, 0, -49, 0 } },
    },
    {
        0, 65525, gUnk_099CB99C, 4320, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2C0DC },
        { { 0xFFF8, 112, 0xFF90, 0, gUnk_099DED9C, 2368, gUnk_099A8400 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -62, 0, -136, 0 } },
    },
    {
        0, 65530, gUnk_099CCA7C, 4448, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2C8DC },
        { { 0, 112, 0xFF90, 0, gUnk_099DF6DC, 2400, gUnk_099A8468 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -98, 0, -135, 0 } },
    },
    {
        0, 65535, gUnk_099CDBDC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2D0DC },
        { { 0, 112, 0xFF8F, 0, gUnk_099E003C, 2432, gUnk_099A84C4 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -149, -20, -38, 0 } },
    },
    {
        0, 65535, gUnk_099CED5C, 4256, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2D8DC },
        { { 0, 112, 0xFF90, 0, gUnk_099E09BC, 2432, gUnk_099A8538 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -140, 17, -24, 0 } },
    },
    {
        0, 65532, gUnk_099CFDFC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A2E0DC },
        { { 0, 112, 0xFF90, 0, gUnk_099E133C, 2400, gUnk_099A8590 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -171, 0, -78, 0 } },
    },
    {
        0, 14, gUnk_099D0F7C, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_09A2F0DC, gUnk_09A2E8DC },
        { { 0, 112, 0xFF90, 0, gUnk_099E1C9C, 2368, gUnk_099A8600 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -190, -20, -33, 0 } },
    },
    {
        3, 12, gUnk_099D20FC, 4480, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_09A300DC, gUnk_09A2F8DC },
        { { 0, 112, 0xFF90, 0, gUnk_099E25DC, 2336, gUnk_099A865C }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -181, 17, -25, 0 } },
    },
    {
        31, 2, gUnk_099D327C, 4224, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A308DC },
        { { 0, 112, 0xFF90, 0, gUnk_099E2EFC, 1920, gUnk_099A86C0 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7D06 } },
        { { -86, 0, -26, 0 } },
    },
    {
        32, 65530, gUnk_099BAA5C, 3712, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A240DC },
        { { 0, 112, 0xFF90, 0, gUnk_099D559C, 1952, gUnk_099A7E04 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -79, 0, -98, 0 } },
    },
    {
        32, 4, gUnk_099C0BFC, 4384, 0,
        { gUnk_08125E24, gUnk_08125E24, gUnk_08125E24, gUnk_09A270DC },
        { { 0, 112, 0xFF90, 0, gUnk_099E2EFC, 1920, gUnk_099A86C0 }, { 0, 56, 0xFFEE, 0, gUnk_099D42FC, 4768, gUnk_099A7CD2 } },
        { { -119, 19, -27, 0 } },
    },
};

const MdAnimFrame gUnk_09992D34[4] = { { 1, 18 }, { 2, 12 }, { 3, 24 }, { 2, 12 } };

const MdAnimFrame gUnk_09992D44[4] = { { 4, 18 }, { 5, 12 }, { 6, 24 }, { 5, 12 } };

const MdAnimFrame gUnk_09992D54[4] = { { 7, 12 }, { 8, 30 }, { 9, 3 }, { 10, 6 } };

const MdAnimFrame gUnk_09992D64[2] = { { 11, 24 }, { 12, 6 } };

const MdAnimFrame gUnk_09992D6C[2] = { { 13, 6 }, { 14, 6 } };

const MdAnimFrame gUnk_09992D74[10] = { { 15, 6 }, { 16, 3 }, { 17, 3 }, { 18, 24 }, { 1, 6 }, { 19, 6 }, { 20, 3 }, { 21, 3 }, { 22, 24 }, { 1, 6 } };

const MdAnimFrame gUnk_09992D9C[8] = { { 23, 6 }, { 24, 6 }, { 25, 6 }, { 26, 30 }, { 27, 3 }, { 28, 6 }, { 29, 6 }, { 30, 6 } };

const MdAnimFrame gUnk_09992DBC[6] = { { 39, 3 }, { 31, 24 }, { 32, 3 }, { 33, 3 }, { 34, 24 }, { 40, 3 } };

const MdAnimFrame gUnk_09992DD4[8] = { { 39, 3 }, { 31, 24 }, { 32, 3 }, { 35, 3 }, { 36, 3 }, { 37, 24 }, { 34, 6 }, { 40, 6 } };

const MdAnimFrame gUnk_09992DF4[11] = { { 39, 3 }, { 31, 24 }, { 32, 3 }, { 33, 3 }, { 34, 24 }, { 35, 6 }, { 32, 12 }, { 36, 3 }, { 37, 24 }, { 34, 6 }, { 38, 6 } };

const MdAnimFrame gUnk_09992E20[1] = { { 1, 32767 } };

const MdAnimDef gUnk_09992E24[11] = {
    { gUnk_09992D34, 4, 0 },
    { gUnk_09992D44, 4, 0 },
    { gUnk_09992D54, 4, 0 },
    { gUnk_09992D64, 2, 0 },
    { gUnk_09992D6C, 2, 0 },
    { gUnk_09992D74, 10, 0 },
    { gUnk_09992D9C, 8, 0 },
    { gUnk_09992DBC, 6, 0 },
    { gUnk_09992DD4, 8, 0 },
    { gUnk_09992DF4, 11, 0 },
    { gUnk_09992E20, 1, 0 },
};

TaskDesc gTaskDescBosGa = {
    gTaskNameBosGa,
    (void (*)(void*, void*))task_bos_ga_0,
    task_bos_ga_1,
    (void (*)(void*))task_bos_ga_2,
    (void (*)(void*))task_bos_ga_3,
    0xA54,
};

const char gTaskNameBosMd[] = "task_bos_md";

TaskDesc gTaskDescBosMd = {
    gTaskNameBosMd,
    (void (*)(void*, void*))task_bos_md_0,
    task_bos_md_1,
    (void (*)(void*))task_bos_md_2,
    (void (*)(void*))task_bos_md_3,
    0x1B8,
};

const char gTaskNameBosMdMap[] = "task_bos_md_map";

const MdFirePoint gUnk_09992E98[4] = { { 88, 288, 240, 0 }, { 56, 312, 330, 0 }, { 72, 336, 420, 0 }, { 104, 360, 510, 0 } };

const MdFirePoint gUnk_09992EB8[4] = { { 128, 304, 0, 0 }, { 104, 324, 0, 0 }, { 144, 344, 0, 0 }, { 112, 364, 0, 0 } };

const MdFirePoint gUnk_09992ED8[4] = { { 128, 288, 0, 0 }, { 156, 312, 0, 0 }, { 172, 336, 0, 0 }, { 144, 360, 0, 0 } };

const MdFireDef gUnk_09992EF8[6] = {
    { gUnk_09992E98, 4, 0 },
    { gUnk_09992EB8, 4, 0 },
    { gUnk_09992ED8, 4, 0 },
    { gUnk_09992E98, 4, 0 },
    { gUnk_09992E98, 4, 0 },
    { gUnk_09992E98, 4, 0 },
};

const EmyKind gUnk_09992F28 = { 37, 1000, 16, 16, 0, 60, 1 };

TaskDesc gTaskDescBosMdMap = {
    gTaskNameBosMdMap,
    (void (*)(void*, void*))task_bos_md_map_0,
    task_bos_md_map_1,
    0,
    0,
    0x4,
};

const char gTaskNameBosMdFire[] = "task_bos_md_fire";

TaskDesc gTaskDescBosMdFire = {
    gTaskNameBosMdFire,
    (void (*)(void*, void*))task_bos_md_fire_0,
    task_bos_md_fire_1,
    (void (*)(void*))task_bos_md_fire_2,
    (void (*)(void*))task_bos_md_fire_3,
    0x170,
};

const char gTaskNameBosMdDai[] = "task_bos_md_dai";

TaskDesc gTaskDescBosMdDai = {
    gTaskNameBosMdDai,
    (void (*)(void*, void*))task_bos_md_dai_0,
    task_bos_md_dai_1,
    (void (*)(void*))task_bos_md_dai_2,
    (void (*)(void*))task_bos_md_dai_3,
    0x84,
};

const char gTaskNameBosMdHahen[] = "task_bos_md_hahen";

TaskDesc gTaskDescBosMdHahen = {
    gTaskNameBosMdHahen,
    (void (*)(void*, void*))task_bos_md_hahen_0,
    task_bos_md_hahen_1,
    (void (*)(void*))task_bos_md_hahen_2,
    (void (*)(void*))task_bos_md_hahen_3,
    0x28,
};

#ifdef VERSION_EU
void* gUnkEu_09F847D4[5] = {
    gUnk_09A31FDC,
    gUnkEu_09A840A0,
    gUnkEu_09A84FA0,
    gUnkEu_09A84AA0,
    gUnkEu_09A845A0,
};

void* gUnkEu_09F847E8[5] = {
    gUnkEu_09A03C80,
    gUnkEu_09A0A480,
    gUnkEu_09A1DC80,
    gUnkEu_09A17480,
    gUnkEu_09A10C80,
};

void* gUnkEu_09F847FC[5] = {
    gUnk_0999CB90,
    gUnkEu_099A31F4,
    gUnkEu_099A3DF4,
    gUnkEu_099A39CC,
    gUnkEu_099A35E0,
};

void* gUnkEu_09F84810[5] = {
    gUnk_0999CBB6,
    gUnkEu_099A3220,
    gUnkEu_099A3E1A,
    gUnkEu_099A39F2,
    gUnkEu_099A360C,
};

#endif

void* gUnk_09EF8F24[30] = {
    gUnk_09A3CA3C,
    gUnk_09A3CA5C,
    gUnk_09A3CA7C,
    gUnk_09A3CA9C,
    gUnk_09A3CABC,
    gUnk_09A3CADC,
    gUnk_09A3CAFC,
    gUnk_09A3CB1C,
    gUnk_09A3CB3C,
    gUnk_09A3CB5C,
    gUnk_09A3CB7C,
    gUnk_09A3CB9C,
    gUnk_09A3CBBC,
    gUnk_09A3CBDC,
    gUnk_09A3CBFC,
    gUnk_09A3CC1C,
    gUnk_09A3CBFC,
    gUnk_09A3CBDC,
    gUnk_09A3CBBC,
    gUnk_09A3CB9C,
    gUnk_09A3CB7C,
    gUnk_09A3CB5C,
    gUnk_09A3CB3C,
    gUnk_09A3CB1C,
    gUnk_09A3CAFC,
    gUnk_09A3CADC,
    gUnk_09A3CABC,
    gUnk_09A3CA9C,
    gUnk_09A3CA7C,
    gUnk_09A3CA5C,
};

#ifdef VERSION_EU
const WorldselectTileSizes gUnkEu_099991E0 = { { 896, 960, 1024, 1024, 960 } };
#endif

const MdModel gUnk_09992F70[13] = {
#ifdef VERSION_EU
    { 1, 1, 107, -1, gUnk_09A3CD1C, gUnk_099E7E7C, gUnk_099A8824, gUnkEu_09F847E8, 8192, 0 },
#else
    { 1, 1, 107, -1, gUnk_09A3CD1C, gUnk_099E7E7C, gUnk_099A8824, gUnk_099F6D3C },
#endif
#ifdef VERSION_EU
    { 2, 2, 101, -1, gUnk_09A3CD5C, gUnk_099E9E7C, gUnk_099A8880, gUnkEu_09F847E8, 12288, 0 },
#else
    { 2, 2, 101, -1, gUnk_09A3CD5C, gUnk_099E9E7C, gUnk_099A8880, gUnk_099F7D3C },
#endif
#ifdef VERSION_EU
    { 4, 3, 120, -1, gUnk_09A3CCFC, gUnk_099E6E7C, gUnk_099A87F8, gUnkEu_09F847E8, 6144, 0 },
#else
    { 4, 3, 120, -1, gUnk_09A3CCFC, gUnk_099E6E7C, gUnk_099A87F8, gUnk_099F653C },
#endif
#ifdef VERSION_EU
    { 8, 4, 94, -1, gUnk_09A3CC9C, gUnk_099E3E7C, gUnk_099A8758, gUnkEu_09F847E8, 0, 0 },
#else
    { 8, 4, 94, -1, gUnk_09A3CC9C, gUnk_099E3E7C, gUnk_099A8758, gUnk_099F4D3C },
#endif
#ifdef VERSION_EU
    { 16, 5, 74, -1, gUnk_09A3CD3C, gUnk_099E8E7C, gUnk_099A884C, gUnkEu_09F847E8, 10240, 0 },
#else
    { 16, 5, 74, -1, gUnk_09A3CD3C, gUnk_099E8E7C, gUnk_099A884C, gUnk_099F753C },
#endif
#ifdef VERSION_EU
    { 32, 6, 87, -1, gUnk_09A3CD7C, gUnk_099EAE7C, gUnk_099A88A0, gUnkEu_09F847E8, 14336, 0 },
#else
    { 32, 6, 87, -1, gUnk_09A3CD7C, gUnk_099EAE7C, gUnk_099A88A0, gUnk_099F853C },
#endif
#ifdef VERSION_EU
    { 64, 7, 115, -1, gUnk_09A3CD9C, gUnk_099EBE7C, gUnk_099A88D4, gUnkEu_09F847E8, 16384, 0 },
#else
    { 64, 7, 115, -1, gUnk_09A3CD9C, gUnk_099EBE7C, gUnk_099A88D4, gUnk_099F8D3C },
#endif
#ifdef VERSION_EU
    { 128, 8, 127, 149, gUnk_09A3CE1C, gUnk_099EEE7C, gUnk_099A8930, gUnkEu_09F847E8, 20480, 0 },
#else
    { 128, 8, 129, 151, gUnk_09A3CE1C, gUnk_099EEE7C, gUnk_099A8930, gUnk_099F9D3C },
#endif
#ifdef VERSION_EU
    { 256, 9, 53, 175, gUnk_09A3CCBC, gUnk_099E4E7C, gUnk_099A8780, gUnkEu_09F847E8, 2048, 0 },
#else
    { 256, 9, 53, 177, gUnk_09A3CCBC, gUnk_099E4E7C, gUnk_099A8780, gUnk_099F553C },
#endif
#ifdef VERSION_EU
    { 512, 10, 1, -1, gUnk_09A3CCDC, gUnk_099E5E7C, gUnk_099A87C0, gUnkEu_09F847E8, 4096, 0 },
#else
    { 512, 10, 1, -1, gUnk_09A3CCDC, gUnk_099E5E7C, gUnk_099A87C0, gUnk_099F5D3C },
#endif
#ifdef VERSION_EU
    { 2048, 11, 44, 184, gUnk_09A3CE3C, gUnk_099EFE7C, gUnk_099A895C, gUnkEu_09F847E8, 22528, 0 },
#else
    { 2048, 11, 44, 186, gUnk_09A3CE3C, gUnk_099EFE7C, gUnk_099A895C, gUnk_099FA53C },
#endif
#ifdef VERSION_EU
    { 4096, 12, 61, 190, gUnk_09A3CE5C, gUnk_099F0E7C, gUnk_099A897C, gUnkEu_09F847E8, 24576, 0 },
#else
    { 4096, 12, 61, 192, gUnk_09A3CE5C, gUnk_099F0E7C, gUnk_099A897C, gUnk_099FAD3C },
#endif
#ifdef VERSION_EU
    { 1024, 13, 132, -1, gUnk_09A3CDBC, gUnk_099ECE7C, gUnk_099A8900, gUnkEu_09F847E8, 18432, 0 },
#else
    { 1024, 13, 134, -1, gUnk_09A3CDBC, gUnk_099ECE7C, gUnk_099A8900, gUnk_099F953C },
#endif
};

const char gModeNameWorldselect[] = "mode_worldselect";

Mode gModeWorldselect = {
    gModeNameWorldselect,
    (void (*)(s32))mode_worldselect_0,
    (void (*)(void))mode_worldselect_1,
    (void (*)(void))mode_worldselect_2,
};

GaWork* gGaWork;
u32 gUnk_02034FEC;
s16 gUnk_02034FF0;
u32 gUnk_02034FF4;
MdSlot gUnk_02034FF8[5];
s16 gUnk_02035070[14];
u32 gUnk_0203508C;
s16 gUnk_02035090;
s16 gUnk_02035092;
u32 gUnk_02035094;
void* gUnk_02035098[2];
void* gUnk_020350A0[2];
struct ObjTiles* gUnk_020350A8;
struct ObjPalette* gUnk_020350AC;
struct ObjTiles* gUnk_020350B0;
u8 gUnk_020350B4;
s16 gUnk_020350B6;
s16 gUnk_020350B8;
s16 gUnk_020350BA;
void* gUnk_020350BC;
s16 gUnk_020350C0;
s16 gUnk_020350C2;
u32 gUnk_020350C4;
s32 gUnk_020350C8[2];
s32 gUnk_020350D0;
u32 gUnk_020350D4;
TaskPool gUnk_020350D8;
s16 gUnk_020350EC;
u8 gUnk_020350EE;
u8 gUnk_020350EF;
u8 gUnk_020350F0;
s16 gUnk_020350F2;
u16 gUnk_020350F4;

void func_080FB000(GaWork* work, GaEntryWork* e) {
    s32 d1;
    s32 d2;
    s32 flag;
    s32 v;
    u16 t;

    if (e->unk_15A & 0x10) {
        return;
    }

    switch (func_0801ADAC((MdSub*)e)) {
    case 5:
        work->unk_A52 = 1;

        if (work->unk_000 == 10 || work->unk_004 == 10) {
            func_0801AF08(e);
        } else {
            d1 = gBtlWork->actor->x - e->unk_124;
            d1 = (d1 * d1) >> 8;
            d2 = gBtlWork->actor->y - e->unk_128;
            d2 = (d2 * d2) >> 8;

            if (work->entries[2].unk_15A & work->entries[3].unk_15A & work->entries[4].unk_15A & work->entries[5].unk_15A & 4) {
                switch (GetRandom() % 3) {
                case 0:
                    func_080F7F54(work, 7);
                    break;
                case 1:
                    func_080F7F54(work, 8);
                    break;
                case 2:
                    func_080F7F54(work, 9);
                    break;
                }
            } else if (d1 + d2 <= 0xE0FFF) {
                if (GetRandom() % 100 < 70) {
                    if ((work->entries[2].unk_15A & work->entries[3].unk_15A & 4) == 0) {
                        flag = 0;

                        if (gBtlWork->unk_0CC <= gBtlWork->actor->x) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    } else {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    }
                } else {
                    if ((work->entries[4].unk_15A & work->entries[5].unk_15A & 4) == 0) {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    } else {
                        flag = 0;

                        if (gBtlWork->unk_0CC <= gBtlWork->actor->x) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    }
                }
            } else if (d1 + d2 <= 0x270FFF) {
                if (GetRandom() % 100 < 50) {
                    if ((work->entries[2].unk_15A & work->entries[3].unk_15A & 4) == 0) {
                        flag = 0;

                        if (gBtlWork->unk_0CC <= gBtlWork->actor->x) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    } else {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    }
                } else {
                    if ((work->entries[4].unk_15A & work->entries[5].unk_15A & 4) == 0) {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    } else {
                        flag = 0;

                        if (gBtlWork->unk_0CC <= gBtlWork->actor->x) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    }
                }
            } else {
                if (GetRandom() % 100 < 30) {
                    if ((work->entries[2].unk_15A & work->entries[3].unk_15A & 4) == 0) {
                        flag = 0;

                        if (gBtlWork->unk_0CC <= gBtlWork->actor->x) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    } else {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    }
                } else {
                    if ((work->entries[4].unk_15A & work->entries[5].unk_15A & 4) == 0) {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    } else {
                        flag = 0;

                        if (gBtlWork->unk_0CC <= gBtlWork->actor->x) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    }
                }
            }
        }

        if (GetRandom() % 3 != 0) {
            if (work->unk_A4C == 0) {
                work->unk_A4C = 1;
            } else {
                work->unk_A4C = 0;
            }
        }
        break;
    case 1:
    case 6:
    case 7:
        e->unk_15A |= 2;
        e->unk_1A6 = 0;

        if (e->unk_1A0 == 0) {
            work->entries[1].unk_15A |= 2;
            work->entries[1].unk_1A6 = 0;
        }
        break;
    case 3:
    case 8:
        func_0801C2DC(e, 1);
        e->unk_15A |= 4;

        if (e->unk_1A0 == 0) {
            func_0801AF4C((MdSub*)e);
            e->unk_11C = 0;
            e->unk_15C = 0;
            work->entries[1].unk_11C = 0;
            work->entries[1].unk_15C = 0;
            func_080F7F54(work, 11);
        } else {
            e->unk_11C = 3;
            e->unk_15C = 0;

            if (work->unk_000 != 10 && work->unk_004 != 10) {
                if (work->unk_A52 != 0) {
                    func_0801AF08(&work->entries[0]);
                }
                func_080F7F54(work, 1);
            }
        }
        break;
    case 4:
        if (work->unk_000 != 10 && work->unk_004 != 10) {
            if (GetRandom() % 100 < 30) {
                _0801C1F8(0, e->unk_124, e->unk_128, e->unk_12C);
            }
            func_080F7F54(work, 1);
        }
        func_0801AF08(e);
        break;
    }

    switch ((u32)e->unk_11C) {
    case 0:
        v = (e->unk_124 - e->x) >> 1;
        if (v > 0x600) {
            v = 0x600;
        } else if (v < -0x600) {
            v = -0x600;
        }
        e->x += v;
        v = (e->unk_128 - e->y) >> 1;
        if (v > 0x600) {
            v = 0x600;
        } else if (v < -0x600) {
            v = -0x600;
        }
        e->y += v;
        v = ((e->unk_12C + e->unk_13C) - e->z) >> 1;
        if (v > 0x600) {
            v = 0x600;
        } else if (v < -0x600) {
            v = -0x600;
        }
        e->z += v;
        t = e->unk_112;
        ApproachAngle(&t, 0, 3);
        e->unk_112 = t;

        if (e->unk_15A & 1) {
            break;
        }
        e->unk_13C = gSineTable[e->unk_158] << 2;
        e->unk_158 += 4;
        break;
    case 1:
        func_080F7E84(e);
        break;
    case 3:
        if (e->unk_15C == 0) {
            e->unk_15A |= 2;
            e->unk_1A6 = 0;

            if (!func_080128EC()) {
                func_08013DB8(e->x, e->y + e->z, 0, 0x100);
                e->unk_15C++;
            }
        } else if (e->unk_15C > 0) {
            if (work->entries[2].unk_15A & work->entries[3].unk_15A & work->entries[4].unk_15A & work->entries[5].unk_15A & 4) {
                func_0801C2DC(&work->entries[0], 0);
            }
            func_0801AF08(e);
            func_080F8374(e);
            return;
        }
        func_080F7E84(e);
        break;
    }

    if (e->unk_15A & 2) {
        e->unk_1A6++;
        if (e->unk_1A6 > 30) {
            func_0801AF08(e);
            e->unk_15A &= 0xFFFD;
            e->unk_1A6 = 0;
        }
    }
    e->gfx = AnimUpdate(&e->anim);

    if (e->unk_1A0 == 0) {
        work->gfx = AnimUpdate(&work->anim);
    }

    if (e->unk_06C != 0) {
        e->x += e->unk_078;
        e->y += e->unk_07C;
    }
    ColliderSetPosition(&e->collider, e->x, e->y, e->z + e->unk_13C);
    TaskPoolUpdate(&e->tasks);
}

void task_bos_ga_0(GaWork* work, s32 arg) {
    u32 i;
    GaEntryWork* p;

    gGaWork = work;

    if (arg == 0) {
        work->unk_000 = 1;
    } else {
        work->unk_000 = 0;
    }

    work->unk_004 = work->unk_000;
    work->unk_00E = 0;
    work->unk_008 = 0;
    work->unk_010 = 0;
    work->unk_012 = 0;
    work->unk_014 = 0;
    work->unk_018 = 0;
    work->angle = 0;
    work->unk_A4C = 0;
    work->unk_A50 = 60;
    TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosMap, &gUnk_0999202C);
    gBtlWork->unk_0CC = 0xE200;
    gBtlWork->unk_0D0 = 0x15E00;
    gBtlWork->unk_0D4 = 0;
    SetBattleActorPosition(0x8200, 0x15E00, 0);
    p = work->entries;

    for (i = 0; i <= 5; i++) {
        func_080F80FC(work, i, arg);
    }

    func_0801C2DC(p, 1);
    func_0801C2DC(&work->entries[1], 1);
    work->palette = LoadObjPalette(gUnk_09A3C89C, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    func_0801C298(work->palette[6] + 16, 1);
    func_0801C298(work->palette2[6] + 16, 1);
    func_08083900(GetRandom() % 4 + 1);
}
u8 task_bos_ga_1(GaWork* work) {
    u8 result;
    GaEntryWork* p;
    AnimState* anim;
    u32 i;

    result = 1;
    work->unk_A50--;

    if (work->unk_A50 <= 0) {
        func_08083900(GetRandom() % 7 + 1);
        work->unk_A50 = 60;
    }

    work->unk_A52 = 0;
    i = 0;
    p = work->entries;

    do {
        func_080FB000(work, p);
        p++;
        i++;
    } while (i <= 5);

    switch (work->unk_000) {
    case 0:
        result = func_080F854C(work);
        break;
    case 1:
        result = func_080F8958(work);
        break;
    case 2:
        result = func_080F8AC8(work);
        break;
    case 3:
        result = func_080F8F9C(work);
        break;
    case 4:
        result = func_080F9744(work);
        break;
    case 5:
        result = func_080F99C0(work);
        break;
    case 6:
        result = func_080F9C2C(work);
        break;
    case 7:
        result = func_080F9EDC(work);
        break;
    case 8:
        result = func_080FA2B4(work);
        break;
    case 9:
        result = func_080FA644(work);
        break;
    case 10:
        result = func_080FAA18(work);
        break;
    case 11:
        result = func_080FABE4(work);
        break;
    }

    if (func_0801C1C0(0)) {
        func_080F7F54(work, 10);
    }

    anim = &work->entries[1].anim;

    if (AnimIsFinished(anim) && GetRandom() % 100 == 0 && work->unk_000 != 11) {
        AnimStart(anim, 1, 0);
    }

    return result;
}

void task_bos_ga_2(GaWork* work) {
    GaEntryWork* p;
    u32 i;

    i = 0;
    p = work->entries;

    do {
        func_080F83E0(work, p);
        p++;
        i++;
    } while (i <= 5);
}

void task_bos_ga_3(GaWork* work) {
    GaEntryWork* p;
    u32 i;

    i = 0;
    p = work->entries;

    do {
        func_080F8374(p);
        p++;
        i++;
    } while (i <= 5);

    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}

void func_080FB8DC(MdWork* work, s32 state) {
    u16 t;

    work->unk_004 = state;
    t = work->unk_014 | 1;
    work->unk_014 = t;
}

void func_080FB8E8(MdWork* work, u16 index) {
    SetBgMapBlocks(1, (void*)gUnk_09992108[index].blocks, 2, 2);
}

void func_080FB908(MdWork* work, u16 index) {
    LoadBgTiles(1, gUnk_09992108[index].tiles, gUnk_09992108[index].tilesSize);
}

void func_080FB930(MdWork* work, u16 id) {
    s32 n;

    if (work->unk_01C == 0) {
        return;
    }

    func_080FB908(work, id);
    func_080FB8E8(work, id);
    work->unk_178 = gUnk_09992108[id].unk_00;
    work->unk_17A = gUnk_09992108[id].unk_02;

    for (n = 0; n < 2; n++) {
        work->gfx[n].sprite = gUnk_09992108[id].desc[n].sprite;

        if (work->gfx[n].src != gUnk_09992108[id].desc[n].src && n == 0) {
            work->gfx[n].src = gUnk_09992108[id].desc[n].src;
            UpdateSpriteFrameTiles(work->gfx[n].tiles, work->gfx[n].sprite, work->gfx[n].src);
        }

        work->gfx[n].x = gUnk_09992108[id].desc[n].x;
        work->gfx[n].y = gUnk_09992108[id].desc[n].y;
        work->gfx[n].z = gUnk_09992108[id].desc[n].z;
    }
}

void func_080FBA14(MdWork* work, s16 id) {
    MdAnim* a;
    const MdAnimDef* base;
    const MdAnimDef* d;
    const MdAnimFrame* f;

    a = &work->anim;
    a->animId = id;
    base = gUnk_09992E24;
    d = base + id;
    f = d->frames;
    a->frames = f;
    a->frameCount = d->frameCount;
    a->frame = 0;
    a->timer = f->duration;
    func_080FB930(work, f->gfxIndex);
}
void func_080FBA4C(MdWork* work) {
    MdAnim* a;

    a = &work->anim;
    a->timer--;

    if (a->timer < 0) {
        a->frame++;

        if (a->frame >= a->frameCount) {
            a->frame = 0;
        }

        a->timer = a->frames[a->frame].duration;
        func_080FB930(work, a->frames[a->frame].gfxIndex);
    }
}
u8 func_080FBA9C(MdWork* work) {
    MdAnim* a;

    a = &work->anim;

    if (a->frame >= a->frameCount - 1) {
        return 1;
    }

    return 0;
}
u8 func_080FBAB8(MdWork* work) {
    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
    case 0:
        if (gBtlWork->actor->x > 0x8000) {
            func_080FBA14(work, 1);
        } else {
            func_080FBA14(work, 0);
        }

        if (gBtlWork->unk_068 & 0x100000) {
            work->unk_016 = ((GetRandom() & 3) + (GetRandom() & 3)) / 2 * 20 + 60;
        } else if (work->sub[0].unk_02C * 10 / work->sub[0].unk_02E > 4) {
            work->unk_016 = (GetRandom() % 5 + GetRandom() % 5) / 2 * 30 + 30;
        } else {
            work->unk_016 = (GetRandom() % 6 + GetRandom() % 6) / 2 * 10 + 30;
        }
        break;
    case 1:
        if (func_080FBA9C(work) != 0 && gBtlWork->actor->x > 0x8000) {
            func_080FBA14(work, 1);
        }

        if (gBtlWork->unk_0A0 != 0) {
            work->unk_016--;

            if (work->unk_016 <= 0) {
                func_0801BCD4(&work->sub[0]);
                func_080FB8DC(work, 0);
            }
        }
        break;
    case 2:
        break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FBC4C(MdWork* work) {
    s32 d;
    u16 r;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            d = gBtlWork->actor->x;

            if (d > 0xA800) {
                switch (GetRandom() % 3) {
                case 0:
                    func_080FBA14(work, 7);
                    break;
                case 1:
                    func_080FBA14(work, 8);
                    break;
                case 2:
                    func_080FBA14(work, 9);
                    break;
                }
            } else if (d > 0x7000) {
                r = GetRandom() % 100;

                if (r <= 59) {
                    func_080FBA14(work, 7);
                } else if (r <= 89) {
                    func_080FBA14(work, 8);
                } else {
                    func_080FBA14(work, 9);
                }
            } else if (d > 0x3800) {
                r = GetRandom() % 100;

                if (r <= 59) {
                    func_080FBA14(work, 8);
                } else if (r <= 89) {
                    func_080FBA14(work, 7);
                } else {
                    func_080FBA14(work, 9);
                }
            } else {
                switch (GetRandom() % 3) {
                case 0:
                    func_080FBA14(work, 7);
                    break;
                case 1:
                    func_080FBA14(work, 8);
                    break;
                case 2:
                    func_080FBA14(work, 9);
                    break;
                }
            }
            break;
        case 1:
            switch ((s16)work->anim.frames[work->anim.frame].gfxIndex) {
            case 33:
            case 34:
            case 36:
            case 37:
                if (func_08011F78(251, work->sub[0].unk_004, work->sub[0].unk_008,
                                  work->sub[0].unk_00C, 40, 20, 24) != 0) {
                    m4aSongNumStart(0x2A5);
                }
                break;
            }

            if (func_080FBA9C(work) != 0) {
                func_080FB8DC(work, 0);
            }
            break;
        case 2:
            func_0801AF08(&work->sub[0]);
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FBDD4(MdWork* work) {
    s32 v;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            if (gBtlWork->actor->x > 0xA800) {
                if (GetRandom() % 100 <= 59) {
                    func_080FBA14(work, 6);
                } else {
                    func_080FBA14(work, 5);
                }
            } else {
                if (GetRandom() % 100 <= 79) {
                    func_080FBA14(work, 5);
                } else {
                    func_080FBA14(work, 6);
                }
            }

            work->unk_00C = 0;
            break;
        case 1:
            switch (work->unk_00C) {
            case 0:
                v = (s16)work->anim.frames[work->anim.frame].gfxIndex;

                if (v == 18) {
                    func_08011F78(252, gBtlWork->unk_000, gBtlWork->unk_004, 0,
                                  256, 256, 1);
                    m4aSongNumStart(0x2A7);
                    func_0802F1E8();
                    work->unk_1B4 |= 1;
                    work->unk_00C = 1;
                } else if (v == 28) {
                    func_08011F78(254, gBtlWork->unk_000, gBtlWork->unk_004, 0,
                                  256, 256, 1);
                    m4aSongNumStart(0x2A7);
                    func_0802F1E8();
                    work->unk_1B4 |= 1;
                    work->unk_00C = 2;
                }
                break;
            case 1:
                v = (s16)work->anim.frames[work->anim.frame].gfxIndex;

                if (v == 22) {
                    func_08019A30();
                    func_08011F78(252, gBtlWork->unk_000, gBtlWork->unk_004, 0,
                                  256, 256, 1);
                    m4aSongNumStart(0x2A7);
                    func_0802F1E8();
                    work->unk_1B4 |= 1;
                    work->unk_00C = 2;
                }
                break;
            }

            if (func_080FBA9C(work) != 0) {
                func_080FB8DC(work, 0);
            }
            break;
        case 2:
            func_0801AF08(&work->sub[0]);
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FBFA8(MdWork* work) {
    MdFireArg a;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            work->unk_1B4 = work->unk_1B4 | 2;
            func_080FBA14(work, 2);
            work->unk_00C = 0;
            break;
        case 1:
            switch (work->unk_00C) {
                case 0:
                    if (func_080FBA9C(work) != 0) {
                        func_080FBA14(work, 3);
                        func_0801853C(work->sub[0].unk_004, work->sub[0].unk_008,
                                      work->sub[0].unk_00C + 0x1200, 512);
                        m4aSongNumStart(0x2A6);
                        work->unk_00C = 1;
                    }
                    break;
                case 1:
                    if (func_08011F78(253, work->sub[0].unk_004,
                                      work->sub[0].unk_008 + 0x1800, 0, 72, 48, 1) != 0) {
                        m4aSongNumStart(0x2CA);
                    }

                    if (func_080128EC() == 0) {
                        work->unk_1B4 &= 0xFFFD;
                        a.unk_00 = &work->tasks;
                        a.unk_06 = 0;
                        a.unk_08 = (s32)&work->unk_1B4;

                        if (work->sub[0].unk_02C * 10 / work->sub[0].unk_02E > 4) {
                            switch (GetRandom() % 3) {
                            case 0:
                                a.unk_04 = 0;
                                break;
                            case 1:
                                a.unk_04 = 1;
                                break;
                            case 2:
                                a.unk_04 = 2;
                                break;
                            }
                        } else {
                            switch (GetRandom() % 3) {
                            case 0:
                                a.unk_04 = 3;
                                break;
                            case 1:
                                a.unk_04 = 4;
                                break;
                            case 2:
                                a.unk_04 = 5;
                                break;
                            }
                        }

                        TaskCreate(&work->tasks, &gTaskDescBosMdFire, &a);
                        func_080FBA14(work, 4);
                        work->unk_00C = 2;
                    }
                    break;
                case 2:
                    if (func_080FBA9C(work) != 0) {
                        func_080FB8DC(work, 0);
                    }
                    break;
            }
            break;
        case 2:
            func_0801AF08(&work->sub[0]);
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return 1;
}
u8 func_080FC17C(MdWork* work) {
    u8 result;
    PrizeCardArg arg;

    result = 1;

    if (work->unk_014 & 1) {
        work->unk_008 = 2;
    }

    switch (work->unk_008) {
        case 0:
            func_080FBA14(work, 10);
            func_0801AF4C(&work->sub[0]);
            work->unk_1B4 |= 2;
            work->unk_00C = 0;
            break;
        case 1:
            switch (work->unk_00C) {
            case 0:
                if (FadeIsActive() == 0) {
                    func_08014AAC(work->sub[0].unk_004,
                                  work->sub[0].unk_008 + work->sub[0].unk_00C);
                    FadeToAmount(0, gBtlWork->unk_0B3, 8);
                    work->unk_016 = 120;
                    work->unk_00C = 1;
                }
                break;
            case 1:
                work->unk_016--;

                if (work->unk_016 <= 0) {
                    func_0801536C();
                    work->unk_00C = 2;
                }
                break;
            case 2:
                if (work->unk_01C != 0 && FadeGetAmount() == 31) {
                    DisableBg(1);
                    work->unk_01C = 0;
                }

                if (func_080128EC() == 0) {
                    arg.x = work->sub[0].unk_004;
                    arg.y = work->sub[0].unk_008;
                    arg.z = work->sub[0].unk_00C;
                    CreateBossPrizeCardTask(&gBtlWork->taskPools[0], &arg);
                    func_0801B918(&work->sub[0]);
                    func_0801B008();
                    result = 0;
                }
                break;
            }
            break;
        case 2:
            break;
    }

    if (work->unk_008 == 0) {
        work->unk_008 = 1;
    }

    if (work->unk_008 == 2) {
        work->unk_000 = work->unk_004;
        work->unk_008 = 0;
        work->unk_014 &= 0xFFFE;
    }

    return result;
}
void func_080FC29C(MdWork* work) {
    s32 d;
    u16 r;

    d = gBtlWork->actor->x;

    if (d > 0xA800) {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 2);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 1);
        }
    } else if (d > 0x7000) {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 1);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 2);
        }
    } else if (d > 0x3800) {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 1);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 2);
        }
    } else {
        r = GetRandom() % 100;

        if (r <= 59) {
            func_080FB8DC(work, 2);
        } else if (r <= 89) {
            func_080FB8DC(work, 3);
        } else {
            func_080FB8DC(work, 1);
        }
    }
}
void func_080FC360(MdWork* work) {
    s16 i;

    for (i = 0; i < 1; i++) {
        MdSub* e = &work->sub[i];

        switch (func_0801ADAC(e)) {
        case 5:
            func_080FC29C(work);
            break;
        case 1:
        case 6:
        case 7:
            work->unk_01A = 30;
            work->unk_010[i] = 2;
            break;
        case 3:
        case 8:
            func_0801C2DC(e, 1);
            func_080FB8DC(work, 4);
            break;
        case 4:
            func_080FB8DC(work, 0);
            func_0801AF08(e);
            break;
        }
    }
}
void func_080FC3FC(MdWork* work) {
    s16 i;

    for (i = 0; i < 1; i++) {
        MdSub* e = &work->sub[i];

        if (work->unk_010[i] == 2 && work->unk_01A == 0) {
            work->unk_010[i] = 0;
            func_0801AF08(e);
        }
    }
}
void task_bos_md_0(MdWork* work, void* arg) {
    s16 i;

    TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosMdMap, (void*)&gUnk_099920E8);
    gBtlWork->unk_068 &= 0xFFFFFFFFFFEFFFFF;
    work->unk_000 = 0;
    work->unk_004 = 0;
    work->unk_014 = 0;
    work->unk_008 = 0;
    work->unk_016 = 0;
    work->unk_018 = 0;
    work->unk_01A = 0;
    work->unk_1B4 = 0;
    work->unk_01C = 1;

    for (i = 0; i < 1; i++) {
        work->unk_010[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        work->gfx[i].tiles = 0;
        work->gfx[i].src = 0;
        work->gfx[i].sprite = 0;
        work->gfx[i].x = 0;
        work->gfx[i].y = 0;
    }

    work->gfx[0].tiles = AllocSpriteFrameTiles(2432);
    work->gfx[1].tiles = LoadObjTiles(gUnk_099D42FC, 0x12A0);
    gBtlWork->unk_0CC = 0x11000;
    gBtlWork->unk_0D0 = 0x15000;
    gBtlWork->unk_0D4 = 0;
    SetBattleActorPosition(0x7800, gBtlWork->unk_0D0, 0);

    for (i = 0; i < 1; i++) {
        func_0801B37C(&work->sub[i], &gUnk_099920D8, gBtlWork->unk_0CC,
                      gBtlWork->unk_0D0, gBtlWork->unk_0D4);
#ifdef VERSION_EU
        ColliderInit(work->sub[i].unk_040, 8, 16, 24);
#else
        ColliderInit(work->sub[i].unk_040, 8, 16, 16);
#endif

        if (i == 0) {
            work->sub[i].unk_034 |= 0x400;
        } else {
            work->sub[i].unk_034 |= 0x1000;
        }

        work->sub[i].unk_034 |= 4;
    }

    func_080FB930(work, 0);
    func_080FBA14(work, 0);
    LoadPalette(gUnk_09A3C97C, (void*)0x05000000, 32);
    func_0801C298(0, 1);
    work->unk_028 = gUnk_09A3C97C;
    work->palette = LoadObjPalette(gUnk_09A3C97C, 32);
    func_0801C298(work->palette[6] + 16, 1);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    func_0801C298(work->palette2[6] + 16, 1);
    TaskPoolInit(&work->tasks, 6);
    TaskPoolInit(&work->tasks2, 1);
    TaskPoolInit(&work->tasks3, 8);
    ScrollBgMapTo(1, (gBtlWork->unk_000 >> 8) + 72 - work->unk_178,
                  (gBtlWork->unk_004 >> 8) + 48 - work->unk_17A);
}

s32 task_bos_md_1(MdWork* work) {
    void* args[2];
    s32 result;
    s16 i;

    result = 1;
    func_080FC360(work);

    switch (work->unk_000) {
    case 0:
        result = func_080FBAB8(work);
        break;
    case 1:
        result = func_080FBC4C(work);
        break;
    case 2:
        result = func_080FBDD4(work);
        break;
    case 3:
        result = func_080FBFA8(work);
        break;
    case 4:
        result = func_080FC17C(work);
        break;
    }

    func_080FC3FC(work);

    if (func_0801C1C0(0) != 0) {
        args[0] = &work->tasks3;
        args[1] = &work->unk_1B4;
        TaskCreate(&work->tasks2, &gTaskDescBosMdDai, args);
    }

    func_080FBA4C(work);

    if (work->unk_01A > 0) {
        work->unk_01A--;
    }

    for (i = 0; i < 1; i++) {
        work->sub[i].unk_004 = gBtlWork->unk_0CC
            + gUnk_09992108[(s16)work->anim.frames[work->anim.frame].gfxIndex]
                  .pos[i].x * 256;
        work->sub[i].unk_008 = gBtlWork->unk_0D0
            + gUnk_09992108[(s16)work->anim.frames[work->anim.frame].gfxIndex]
                  .pos[i].y * 256;
        work->sub[i].unk_00C = gBtlWork->unk_0D4
            + gUnk_09992108[(s16)work->anim.frames[work->anim.frame].gfxIndex]
                  .pos[i].z * 256;
        ColliderSetPosition(work->sub[i].unk_040, work->sub[i].unk_004, work->sub[i].unk_008,
                      work->sub[i].unk_00C);
    }

    TaskPoolUpdate(&work->tasks);
    TaskPoolUpdate(&work->tasks2);
    TaskPoolUpdate(&work->tasks3);
    return result;
}

void task_bos_md_2(MdWork* work) {
    s16 x;
    s16 y;
    void* pal;
    void* p1;
    void* p2;
    void* p0;
    s32 i;

    if (work->unk_01C == 0) {
        return;
    }

    if (func_0801CA00(&work->sub[0]) != 0) {
        if (work->unk_028 != gUnk_08F69BC4) {
            LoadPalette(gUnk_08F69BC4, (void*)0x05000000, 32);
            work->unk_028 = gUnk_08F69BC4;
        }

        pal = work->palette2;
    } else {
        if (work->unk_028 != gUnk_09A3C97C) {
            LoadPalette(gUnk_09A3C97C, (void*)0x05000000, 32);
            work->unk_028 = gUnk_09A3C97C;
        }

        pal = work->palette;
    }

    x = (gBtlWork->unk_000 >> 8) - (work->unk_178 - 72);
    y = (gBtlWork->unk_004 >> 8) - (work->unk_17A - 48);
    ScrollBgMapTo(1, x, y);
    p0 = &work->tasks;
    p1 = &work->tasks2;
    p2 = &work->tasks3;

    for (i = 0; i < 2; i++) {
        s32 wx;
        s32 wy;
        u16 frame;

        wx = (work->gfx[i].x + 224) * 256;
        wy = (work->gfx[i].y + 256) * 256;
        WorldToScreen(&x, &y, wx, wy, work->gfx[i].z * 256);
        frame = GetBattleSpritePriorityFlags(wy);
        DrawSprite(x, y, work->gfx[i].sprite, work->gfx[i].tiles, pal, 0, frame,
                   (u16)(-4100 - (wy >> 6)));
    }

    TaskPoolDraw(p0);
    TaskPoolDraw(p1);
    TaskPoolDraw(p2);
}

void task_bos_md_3(MdWork* work) {
    void* q;
    void* r;
    void* t;
    s32 i;

    DisableBg(1);

    for (i = 0; i < 1; i++) {
        ColliderUnregister(work->sub[i].unk_040);
        func_0801B7D8(&work->sub[i]);
    }

    q = &work->tasks;
    r = &work->tasks2;
    t = &work->tasks3;

    for (i = 0; i < 2; i++) {
        if (work->gfx[i].tiles != 0) {
            ReleaseObjTiles(work->gfx[i].tiles);
        }
    }

    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(q);
    TaskPoolDestroy(r);
    TaskPoolDestroy(t);
}

void task_bos_md_map_0(MdMapWork* work, MdMapData* p) {
    LoadBgTiles(0, p->tiles, p->tilesSize);
    LoadBgPalette(0, p->palette, p->paletteSize);
    SetBgMapBlocks(0, &p->map, 2, 2);
    gBtlWork->unk_024 = 256;
    gBtlWork->unk_028 = 256;
    gBtlWork->x = 0x10000;
    gBtlWork->y = 0x14000;
    gBtlWork->unk_000 = 0x10000;
    gBtlWork->unk_004 = 0x14000;
    gBtlWork->x2 = 0x10000;
    gBtlWork->y2 = 0x14000;
    gBtlWork->unk_01C = 0x10000;
    gBtlWork->unk_020 = 0x14000;
    gBtlWork->unk_01A = 15;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    ScrollBgMapTo(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}
s32 task_bos_md_map_1(MdMapWork* work) {
    s32 dx;
    s32 dy;

    func_0802F208();
    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (dx > 1280) {
        dx = 1280;
    } else if (dx < -1280) {
        dx = -1280;
    }

    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gBtlWork->unk_000 - 30720 < gBtlWork->unk_0DA * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 120) * 256;
    } else if (gBtlWork->unk_000 + 30720 > (gBtlWork->unk_0DC + 96) * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 24) * 256;
    }

    if (gBtlWork->unk_004 + 20480 < gBtlWork->unk_0DE * 256) {
        gBtlWork->unk_004 = (gBtlWork->unk_0DE - 80) * 256;
    } else if (gBtlWork->unk_004 + 20480 > gBtlWork->unk_0E0 * 256) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 80) * 256;
    }

    gBtlWork->unk_004 += func_0802F268();
    ScrollBgMapTo(0, (gBtlWork->unk_000 >> 8) + 8, (gBtlWork->unk_004 >> 8) + 40);
    return 1;
}
void func_080FCC14(MdFireWork* work) {
    MdSub* e;

    e = &work->sub;

    switch (func_0801ADAC(e)) {
    case 1:
    case 6:
    case 7:
        work->unk_006 = 30;
        work->unk_000 = 3;
        break;
    case 3:
    case 8:
        if (GetRandom() % 100 <= 49) {
            if ((gBtlWork->unk_068 & 0x100000) == 0) {
                _0801C1F8(0, e->unk_004, e->unk_008, e->unk_00C);
            }
        }

        func_0801C2DC(e, 1);
        work->unk_034 = 30;
        work->unk_000 = 4;
        break;
    }
}
u8 func_080FCCB4(MdFireWork* work) {
    u8 result;
    MdSub* e;
    u8 a;

    result = 1;
    e = &work->sub;

    if ((work->target->unk_00 & 2) && work->unk_000 != 4) {
        func_0801C2DC(e, 1);
        work->unk_034 = 30;
        work->unk_000 = 4;
    }

    switch (work->unk_000) {
        case 0:
            work->unk_034--;

            if (work->unk_034 <= 0) {
                func_0801C2DC(e, 0);
                work->unk_000 = 1;
            }
            break;
        case 1:
            switch (work->unk_15C) {
                case 0:
                    if (work->unk_004 > 0) {
                        work->unk_004--;

                        if (work->unk_004 <= 0) {
                            switch (work->unk_15E) {
                            case 0:
                            case 1:
                            case 2:
                            case 4:
                                a = func_080F7E0C(work->x, work->y,
                                                  gBtlWork->actor->x,
                                                  gBtlWork->actor->y);
                                work->vx = gSineTable[a] * 3;
                                work->vy = -gSineTable[a + 0x40] * 3;
                                work->unk_004 = 90;
                                work->unk_15C = 1;
                                break;
                            case 3:
                                work->unk_15C = 2;
                                break;
                            case 5:
                                work->unk_15C = 3;
                                break;
                            }
                        }
                    }
                    break;
                case 1:
                    work->x += work->vx;
                    work->y += work->vy;
                    work->unk_004--;

#ifdef VERSION_EU
                    if (work->unk_004 <= 0 || work->y <= 0x12FFF) {
#else
                    if (work->unk_004 <= 0 || work->y <= 0x117FF) {
#endif
                        func_0801C2DC(e, 1);
                        work->unk_034 = 30;
                        work->unk_000 = 4;
                    }
                    break;
                case 2:
                    work->angle++;
                    work->x = gSineTable[work->angle] * 40 + work->unk_164;
                    work->y = -gSineTable[work->angle + 0x40] * 40 + work->unk_168;
                    break;
                case 3:
                    work->angle++;
                    work->x = gSineTable[work->angle] * 32 + work->unk_164;
                    break;
            }

            if (work->unk_008 > 0) {
                work->unk_008--;
            } else if (ColliderIsTouchingType(work->sub.unk_040, 1) != 0) {
                m4aSongNumStart(0x2CA);
                gBtlWork->actor->unk_034 |= 0x20000000;
                work->unk_008 = 60;
            }
            break;
        case 2:
            break;
        case 3:
            if (work->unk_006 == 0) {
                work->unk_000 = 1;
                func_0801AF08(e);
            }
            break;
        case 4:
            work->unk_034--;

            if (work->unk_034 <= 0) {
                result = 0;
            }
            break;
    }

    return result;
}
void func_080FCF78(MdFireWork* work) {
    const MdFirePoint* p;

    switch (work->unk_15E) {
    case 0:
    case 1:
    case 2:
        p = gUnk_09992EF8[work->unk_15E].points + work->unk_160;
        work->x = p->x * 256;
        work->y = p->y * 256;
        work->unk_004 = p->unk_04;
        work->unk_15C = 0;
        break;
    case 3:
        work->angle = work->unk_160 * 256 / 6;
        work->unk_164 = 0x8000;
        work->unk_168 = 0x14800;
        work->x = gSineTable[work->angle] * 40 + work->unk_164;
        work->y = -gSineTable[work->angle + 0x40] * 40 + work->unk_168;
        work->unk_004 = 60;
        work->unk_15C = 0;
        break;
    case 4:
        work->x = GetRandom() % 96 * 256 + 0x9800;
        work->y = work->unk_160 * 4096 + 0x11800;
        work->unk_004 = work->unk_160 * 60 + 240;
        work->unk_15C = 0;
        break;
    case 5:
        work->angle = 0;
        work->unk_164 = 0x9800;
        work->x = gSineTable[work->angle] * 32 + work->unk_164;
        work->y = work->unk_160 * 4096 + 0x11800;
        work->unk_004 = work->unk_160 * 256 / 6 + 60;
        work->unk_15C = 0;
        break;
    }
}
void task_bos_md_fire_0(MdFireWork* work, MdFireArg* arg) {
    MdFireArg a;
    s16 i;
    s16 n;

    work->unk_006 = 0;
    work->unk_008 = 0;
    work->unk_030 = 25;
    work->unk_034 = 30;
    work->unk_000 = 0;
    work->z = 0;
    work->unk_15E = arg->unk_04;
    work->unk_160 = arg->unk_06;
    work->target = (MdFireTarget*)arg->unk_08;
    func_080FCF78(work);
    func_0801B37C(&work->sub, &gUnk_09992F28, work->x, work->y, work->z);
    ColliderInit(work->sub.unk_040, 3, 16, 16);
    ColliderSetPosition(work->sub.unk_040, work->sub.unk_004, work->sub.unk_008,
                  work->sub.unk_00C);
    work->sub.unk_034 |= 0x1000;
    work->sub.unk_02C = 20;
    work->sub.unk_02E = 20;
    func_0801C2DC(&work->sub, 1);
    work->palette = (u32)LoadObjPalette(gUnk_09A3C99C, 32);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    work->tiles = (u32)LoadObjTiles(gUnk_099E367C, 0x800);
    AnimInit(&work->anim, gUnk_09EF9BC0, gUnk_09EF9BB0);
    AnimStart(&work->anim, 0, 1);
    a.unk_00 = 0;
    a.unk_04 = arg->unk_04;
    a.unk_08 = arg->unk_08;

    if (arg->unk_00 != 0) {
        if (work->unk_15E <= 2) {
            n = gUnk_09992EF8[work->unk_15E].unk_04;
        } else {
            n = 6;
        }

        for (i = 1; i < n; i++) {
            a.unk_06 = i;
            TaskCreate(arg->unk_00, &gTaskDescBosMdFire, &a);
        }
    }
}

u8 task_bos_md_fire_1(MdFireWork* work) {
    u8 result;

    func_080FCC14(work);
    result = func_080FCCB4(work);

    if ((s16)work->unk_006 > 0) {
        work->unk_006--;
    }

    work->sub.unk_004 = work->x;
    work->sub.unk_008 = work->y;
    work->sub.unk_00C = work->z;
    ColliderSetPosition(work->sub.unk_040, work->sub.unk_004, work->sub.unk_008,
                  work->sub.unk_00C);
    return result;
}

void task_bos_md_fire_2(MdFireWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 sprite;
    u16 frame;

    if (work->unk_006 > 0 && (gFrameCounter & 1)) {
        gfx = (void*)work->palette2;
    } else {
        gfx = (void*)work->palette;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    frame = GetBattleSpritePriorityFlags(work->y);

    if (work->unk_000 == 0) {
        ApproachValue(&work->unk_030, 0x100, work->unk_034);
        sprite = AllocObjAffine(0, work->unk_030, work->unk_030, 0);
    } else if (work->unk_000 == 4) {
        ApproachValue(&work->unk_030, 25, work->unk_034);
        sprite = AllocObjAffine(0, work->unk_030, work->unk_030, 0);
    } else {
        sprite = 0;
    }

    DrawSprite(x, y, AnimUpdate(&work->anim), (void*)work->tiles, gfx,
                  sprite, frame, (u16)(-4100 - (work->y >> 8) * 4));
}

void task_bos_md_fire_3(MdFireWork* work) {
    ColliderUnregister(work->sub.unk_040);
    func_0801B7D8(&work->sub);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    ReleaseObjTiles((void*)work->tiles);
}

void task_bos_md_dai_0(MdDaiWork* work, s32* src) {
    u8* p;

    gBtlWork->unk_068 |= 0x100000;
    work->target = (MdDaiTarget*)src[1];
    work->unk_080 = (void*)src[0];
    work->unk_07C = 0;
    work->state = 0;
    work->x = 0x8000;
    work->y = 0x14F00;
    work->z = 0;
    work->unk_010 = 20;
    work->unk_00C = -40960;
    p = (u8*)work + 0x1C;
    ColliderInit(p, 7, 24, 24);
    ColliderSetPosition(p, work->x, work->y, work->z);
    ColliderSetDisabled(p, 1);
    work->palette = (u32)LoadObjPalette(gUnk_09A3C9BC, 32);
    work->tiles = (u32)LoadObjTiles(gUnk_09999ED0, 0x480);
}

s32 task_bos_md_dai_1(MdDaiWork* work) {
    s32 result;
    s32 args[3];
    s16 i;
    s16 n;

    result = 1;

    switch (work->state) {
    case 0:
        ApproachValue(&work->unk_00C, 0, work->unk_010);
        work->unk_010--;

        if (work->unk_010 <= 0) {
            ColliderSetDisabled(&work->collider, 0);
            ColliderSetHeight(&work->collider, 8);
            work->unk_00C = work->z - 0xA000;
            m4aSongNumStart(680);
            work->unk_07C = 1;
            work->unk_010 = 20;
            work->state = 1;
        }
        break;
    case 1:
        ApproachValue(&work->unk_00C, -3584, work->unk_010);
        work->unk_010--;

        if (work->unk_010 <= 0) {
            ColliderSetDisabled(&work->collider, 0);
            ColliderSetHeight(&work->collider, 16);
            work->unk_00C = work->z - 0xA000;
            m4aSongNumStart(680);
            work->unk_07C = 2;
            work->unk_010 = 20;
            work->state = 2;
        }
        break;
    case 2:
        ApproachValue(&work->unk_00C, -7168, work->unk_010);
        work->unk_010--;

        if (work->unk_010 <= 0) {
            ColliderSetDisabled(&work->collider, 0);
            ColliderSetHeight(&work->collider, 24);
            m4aSongNumStart(680);
            work->unk_07C = 3;
            work->target->unk_00 &= 0xFFFE;
            work->state = 3;
        }
        break;
    case 3:
        if (work->target->unk_00 & 1) {
            work->target->unk_00 &= 0xFFFE;
            args[0] = work->x;
            args[1] = work->y;
            args[2] = -((work->unk_07C - 1) * 7 << 9);
            n = GetRandom() % 3 + 3;

            for (i = 0; i < n; i++) {
                TaskCreate(work->unk_080, &gTaskDescBosMdHahen, args);
            }

            work->unk_07C--;

            if (work->unk_07C <= 0) {
                ColliderSetDisabled(&work->collider, 1);
                result = 0;
            } else {
                ColliderSetHeight(&work->collider, work->unk_07C * 8);
            }
        }
        break;
    }

    return result;
}
void task_bos_md_dai_2(MdDaiWork* work) {
    s16 x;
    s16 y;
    u16 frame;

    WorldToScreen(&x, &y, work->x, work->y, work->z + work->unk_00C);
    frame = GetBattleSpritePriorityFlags(work->y);

    if (work->state <= 2) {
        DrawSprite(x, y + 24, gUnk_09999E0C, (void*)work->tiles, (void*)work->palette, 0,
                      frame, (u16)(-4100 - (work->y >> 8) * 4));
        DrawSprite(x, y, gUnk_09999E1C, (void*)work->tiles, (void*)work->palette, 0, frame,
                      (u16)(-4100 - (work->y >> 8) * 4));
        DrawSprite(x + 8, y - 16, gUnk_09999E0C, (void*)work->tiles, (void*)work->palette, 0,
                      frame, (u16)(-4100 - (work->y >> 8) * 4));
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    frame = GetBattleSpritePriorityFlags(work->y);

    if (work->unk_07C > 0) {
        DrawSprite(x, y, (void*)gUnk_09EF9740[work->unk_07C + 1], (void*)work->tiles,
                      (void*)work->palette, 0, frame,
                      (u16)(-4100 - (work->y >> 8) * 4));
    }
}

void task_bos_md_dai_3(MdDaiWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjTiles((void*)work->tiles);
    gBtlWork->unk_068 &= 0xFFFFFFFFFFEFFFFF;
}

void task_bos_md_hahen_0(MdHahenWork* work, s32* src) {
    u8 angle;
    s32 speed;

    work->x = src[0];
    work->y = src[1];
    work->z = src[2];
    angle = GetRandom();
    speed = (GetRandom() & 0x1FF) + 0x100;
    work->vx = -gSineTable[angle + 0x40] * speed >> 8;
    work->vy = gSineTable[angle] * speed >> 8;
    work->vz = -((GetRandom() & 0x1FF) + 0x100);
    work->unk_024 = 3;
    work->palette = (u32)LoadObjPalette(gUnk_09A3C9BC, 32);
    work->tiles = (u32)LoadObjTiles(gUnk_09999ED0, 0x480);
    work->gfx = gUnk_09EF9740[GetRandom() % 2];
}

s32 task_bos_md_hahen_1(MdHahenWork* work) {
    s32 result;

    result = 1;
    work->x += work->vx;
    work->y += work->vy;

#ifdef VERSION_EU
    if (work->y <= 0x12FFF) {
#else
    if (work->y <= 0x117FF) {
#endif
        work->vy = -work->vy;
    }

    work->z += work->vz;
    work->vz += 102;

    if (work->z > 0) {
        work->z = 0;
        work->vz = -(work->vz * 8 / 10);
        work->unk_024--;

        if ((s16)work->unk_024 <= 0) {
            result = 0;
        }
    }

    return result;
}

void task_bos_md_hahen_2(MdHahenWork* work) {
    s16 x;
    s16 y;
    u16 frame;
    s32 flag;

    flag = gFrameCounter & 1;

    if (flag != 0) {
        return;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    frame = GetBattleSpritePriorityFlags(work->y);
    DrawSprite(x, y, (void*)work->gfx, (void*)work->tiles, (void*)work->palette,
                  flag, frame, (u16)(-4100 - (work->y >> 8) * 4));
}

void task_bos_md_hahen_3(MdHahenWork* work) {
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjTiles((void*)work->tiles);
}

void func_080FD9B8(s16 model, s16 slot) {
    void* src;
    s32 size;

    if (gUnk_09992F70[model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_09A3CDDC;
        size = 0x40;
    } else {
        src = gUnk_09992F70[model].unk_08;
        size = 0x20;
    }

    gUnk_02034FF8[slot].palette = LoadObjPalette(src, size);
}

void func_080FDA28(s16 model, s16 slot) {
    void* src;

    if (gUnk_09992F70[model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_099EDE7C;
    } else {
        src = gUnk_09992F70[model].unk_0C;
    }

    gUnk_02034FF8[slot].tiles = LoadObjTiles(src, 0x1000);
}

s16 func_080FDA98(s16 model, s16 slot) {
    if (gUnk_09992F70[model].unk_02 == 13 && func_080D2DD8()) {
        gUnk_02034FF8[slot].gfx = gUnk_099A8914;
    } else {
        gUnk_02034FF8[slot].gfx = gUnk_09992F70[model].unk_10;
    }
}

void func_080FDB1C(s16 model, s16 n) {
    vu32* dma;
    u16 zero;
    u8* src;
    u8* src2;
    u8* dst;
    u32 ctrl;
    u16* zp;

    zp = &zero;
    zero = 0;
    dma = (vu32*)0x040000D4;
    dma[0] = (vu32)zp;
    dma[1] = (vu32)gUnk_020350BC;
    dma[2] = 0x81000360;
    dma[2];

    if (n > 0) {
#ifdef VERSION_EU
        src = ((u8**)gUnk_09992F70[model].unk_14)[gLanguage];
        src += gUnk_09992F70[model].unkEu_18;
#else
        src = gUnk_09992F70[model].unk_14;
#endif
        dma[0] = (vu32)src;
        dst = (u8*)gUnk_020350BC + (9 - n) * 32;
        dma[1] = (vu32)dst;
        ctrl = (n << 4) | 0x80000000;
        dma[2] = ctrl;
        dma[2];
        src2 = src + (18 - n) * 32;
        dma[0] = (vu32)src2;
        dma[1] = (vu32)((u8*)gUnk_020350BC + 288);
        dma[2] = ctrl;
        dma[2];
        dma[0] = (vu32)(src + 576);
        dma[1] = (vu32)(dst + 576);
        dma[2] = ctrl;
        dma[2];
        dma[0] = (vu32)(src2 + 576);
        dma[1] = (vu32)((u8*)gUnk_020350BC + 864);
        dma[2] = ctrl;
        dma[2];
        src += 1152;
        dma[0] = (vu32)src;
        dst += 1152;
        dma[1] = (vu32)dst;
        dma[2] = ctrl;
        dma[2];
        src2 += 1152;
        dma[0] = (vu32)src2;
        dma[1] = (vu32)((u8*)gUnk_020350BC + 1440);
        dma[2] = ctrl;
        dma[2];
    }

    RequestDma3Copy(gUnk_020350BC, (u8*)GetBgCharBase(0) + 1024, 0x6C0);
}

void func_080FDC04(void) {
    s16 i;
    s16 j;
    s16 k;
    u8 step;

    switch (gUnk_0203508C) {
    case 0:
        if (GetKeysPressed() & 1) {
            BgAnimInit(2, 0x8000, 128);
            BgAnimStart(&gUnk_09EDABB8, 112, 126);
            SetBgPriority(2, 1);
            gBldCnt |= 0x1000;
            gUnk_020350EF = 1;
            m4aSongNumStart(206);
            gUnk_020350F0 = 0;
            gUnk_020350C0 = 4;
        } else if ((GetKeysPressed() & 2) && gUnk_020350EE == 0) {
            m4aSongNumStart(104);
            LoadBgMap(0, gUnk_09A310DC, 0x500);
            LoadBgMap(1, gUnk_09A31ADC, 0x500);
            gUnk_020350F0 = 1;
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 5;
        } else if (gUnk_02035090 > 1) {
            if (GetKeysHeld() & 0x20) {
                j = gUnk_02034FF0 - gUnk_02035090 / 2;

                while (j < 0) {
                    j += gUnk_02035090;
                }

                ReleaseObjPalette(gUnk_02034FF8[j].palette);
                ReleaseObjTiles(gUnk_02034FF8[j].tiles);
                k = gUnk_02034FF8[gUnk_02034FF0].unk_00 - gUnk_02035090 / 2;

                while (k < 0) {
                    k += gUnk_02035092;
                }

                gUnk_02034FF8[j].unk_00 = k;
                func_080FD9B8(gUnk_02035070[k], j);
                func_080FDA28(gUnk_02035070[k], j);
                func_080FDA98(gUnk_02035070[k], j);
                gUnk_02034FF0--;

                if (gUnk_02034FF0 < 0) {
                    gUnk_02034FF0 = gUnk_02035090 - 1;
                }

                m4aSongNumStart(205);
                gUnk_020350B6 = 2;
                gUnk_0203508C = 2;
            } else if (GetKeysHeld() & 0x10) {
                j = gUnk_02034FF0 + gUnk_02035090 / 2;

                while (j >= gUnk_02035090) {
                    j -= gUnk_02035090;
                }

                ReleaseObjPalette(gUnk_02034FF8[j].palette);
                ReleaseObjTiles(gUnk_02034FF8[j].tiles);
                k = gUnk_02034FF8[gUnk_02034FF0].unk_00 + gUnk_02035090 / 2;

                while (k >= gUnk_02035092) {
                    k -= gUnk_02035092;
                }

                gUnk_02034FF8[j].unk_00 = k;
                func_080FD9B8(gUnk_02035070[k], j);
                func_080FDA28(gUnk_02035070[k], j);
                func_080FDA98(gUnk_02035070[k], j);
                gUnk_02034FF0++;

                if (gUnk_02034FF0 >= gUnk_02035090) {
                    gUnk_02034FF0 = 0;
                }

                m4aSongNumStart(205);
                gUnk_020350B6 = 2;
                gUnk_0203508C = 1;
            }
        }
        break;
    case 1:
        if (GetKeysHeld() & 0x20) {
            j = gUnk_02034FF0 - gUnk_02035090 / 2;

            while (j < 0) {
                j += gUnk_02035090;
            }

            ReleaseObjPalette(gUnk_02034FF8[j].palette);
            ReleaseObjTiles(gUnk_02034FF8[j].tiles);
            k = gUnk_02034FF8[gUnk_02034FF0].unk_00 - gUnk_02035090 / 2;

            while (k < 0) {
                k += gUnk_02035092;
            }

            gUnk_02034FF8[j].unk_00 = k;
            func_080FD9B8(gUnk_02035070[k], j);
            func_080FDA28(gUnk_02035070[k], j);
            func_080FDA98(gUnk_02035070[k], j);
            gUnk_02034FF0--;

            if (gUnk_02034FF0 < 0) {
                gUnk_02034FF0 = gUnk_02035090 - 1;
            }

            m4aSongNumStart(205);
            gUnk_0203508C = 2;
        } else {
            for (i = 0; i < gUnk_02035090; i++) {
                gUnk_02034FF8[i].unk_08 -= 2;
            }

            if (gUnk_02034FF8[gUnk_02034FF0].unk_08 <= 128) {
                if (GetKeysHeld() & 0x10) {
                    j = gUnk_02034FF0 + gUnk_02035090 / 2;

                    while (j >= gUnk_02035090) {
                        j -= gUnk_02035090;
                    }

                    ReleaseObjPalette(gUnk_02034FF8[j].palette);
                    ReleaseObjTiles(gUnk_02034FF8[j].tiles);
                    k = gUnk_02034FF8[gUnk_02034FF0].unk_00 + gUnk_02035090 / 2;

                    while (k >= gUnk_02035092) {
                        k -= gUnk_02035092;
                    }

                    gUnk_02034FF8[j].unk_00 = k;
                    func_080FD9B8(gUnk_02035070[k], j);
                    func_080FDA28(gUnk_02035070[k], j);
                    func_080FDA98(gUnk_02035070[k], j);
                    gUnk_02034FF0++;

                    if (gUnk_02034FF0 >= gUnk_02035090) {
                        gUnk_02034FF0 = 0;
                    }

                    m4aSongNumStart(205);
                    gUnk_0203508C = 1;
                } else {
                    step = 128 - gUnk_02034FF8[gUnk_02034FF0].unk_08;

                    for (i = 0; i < gUnk_02035090; i++) {
                        gUnk_02034FF8[i].unk_08 += step;
                    }

                    gUnk_020350B6 = 1;
                    gUnk_020350BA = gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00];
                    gUnk_0203508C = 0;
                }
            }
        }
        break;
    case 2:
        if (GetKeysHeld() & 0x10) {
            j = gUnk_02034FF0 + gUnk_02035090 / 2;

            while (j >= gUnk_02035090) {
                j -= gUnk_02035090;
            }

            ReleaseObjPalette(gUnk_02034FF8[j].palette);
            ReleaseObjTiles(gUnk_02034FF8[j].tiles);
            k = gUnk_02034FF8[gUnk_02034FF0].unk_00 + gUnk_02035090 / 2;

            while (k >= gUnk_02035092) {
                k -= gUnk_02035092;
            }

            gUnk_02034FF8[j].unk_00 = k;
            func_080FD9B8(gUnk_02035070[k], j);
            func_080FDA28(gUnk_02035070[k], j);
            func_080FDA98(gUnk_02035070[k], j);
            gUnk_02034FF0++;

            if (gUnk_02034FF0 >= gUnk_02035090) {
                gUnk_02034FF0 = 0;
            }

            m4aSongNumStart(205);
            gUnk_0203508C = 1;
        } else {
            for (i = 0; i < gUnk_02035090; i++) {
                gUnk_02034FF8[i].unk_08 += 2;
            }

            if ((s8)gUnk_02034FF8[gUnk_02034FF0].unk_08 < 0) {
                if (GetKeysHeld() & 0x20) {
                    j = gUnk_02034FF0 - gUnk_02035090 / 2;

                    while (j < 0) {
                        j += gUnk_02035090;
                    }

                    ReleaseObjPalette(gUnk_02034FF8[j].palette);
                    ReleaseObjTiles(gUnk_02034FF8[j].tiles);
                    k = gUnk_02034FF8[gUnk_02034FF0].unk_00 - gUnk_02035090 / 2;

                    while (k < 0) {
                        k += gUnk_02035092;
                    }

                    gUnk_02034FF8[j].unk_00 = k;
                    func_080FD9B8(gUnk_02035070[k], j);
                    func_080FDA28(gUnk_02035070[k], j);
                    func_080FDA98(gUnk_02035070[k], j);
                    gUnk_02034FF0--;

                    if (gUnk_02034FF0 < 0) {
                        gUnk_02034FF0 = gUnk_02035090 - 1;
                    }

                    m4aSongNumStart(205);
                    gUnk_0203508C = 2;
                } else {
                    step = gUnk_02034FF8[gUnk_02034FF0].unk_08 + 128;

                    for (i = 0; i < gUnk_02035090; i++) {
                        gUnk_02034FF8[i].unk_08 -= step;
                    }

                    gUnk_020350B6 = 1;
                    gUnk_020350BA = gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00];
                    gUnk_0203508C = 0;
                }
            }
        }
        break;
    }
}

void func_080FE47C(void) {
    s16 i;
    s32 sprite;
    s16 x;
    s16 y;
    u8 ang;
    u8 t;
    s32 s;
    s32 h;
    s32 d;
    s32 w;
    s32 v;
    s16 angle;
    void* anim;
    void* tiles;
    void* pal;

    if (gUnk_020350C0 < 2 || gUnk_020350C0 > 4) {
        DrawSprite(gUnk_020350D0 >> 8, 0,
#ifdef VERSION_EU
                      gUnkEu_09F847FC[gLanguage],
#else
                      gUnk_0999CB90,
#endif
                      gUnk_020350A8, gUnk_020350AC, 0, 0x400,
                      0x3E8);
        DrawSprite(120, gUnk_020350C8[0] >> 8, gUnk_0999C394, gUnk_020350B0, gUnk_020350AC, 0,
                      0x400, 0x3E9);
        DrawSprite(120, gUnk_020350C8[1] >> 8, gUnk_0999C3C8, gUnk_020350B0, gUnk_020350AC, 0,
                      0xC00, 0xBBA);
    }

    for (i = 0; i < gUnk_02035090; i++) {
        ang = gUnk_02034FF8[i].unk_08;
        s = -gSineTable[((256 / gUnk_02035090 * i + gUnk_020350B4) & 0xFF) + 64];
        t = (s * 3 >> 7) + ang;

        if ((u8)(t - 62) > 2 && (u8)(t + 64) > 2) {
            h = -gSineTable[ang + 64] * 5 >> 5;
            d = -25600 / (h - 140);
            w = -gSineTable[t + 64] * d >> 8;
            angle = ang;
            x = (gSineTable[angle] * 5 >> 4) + 120;
            v = ((d << 3) * s >> 16) + 64;
            y = h + v;

            if ((u8)(t - 121) <= 14) {
                sprite = 0;
                tiles = gUnk_02035098[0];
                pal = gUnk_020350A0[0];
                anim = gUnk_0999A350;

                if (gUnk_020350C0 > 3 && gUnk_020350F0 == 0) {
                    BgAnimSetPosition(x - 1, y - 5);
                }
            } else if (t <= 61) {
                sprite = 0;
                tiles = gUnk_02035098[1];
                pal = gUnk_020350A0[1];
                anim = gUnk_09EF9770[(62 - t) / 13];
            } else if (t > 194) {
                sprite = 0;
                tiles = gUnk_02035098[1];
                pal = gUnk_020350A0[1];
                anim = gUnk_09EF9770[(t - 194) / 13];
            } else {
                sprite = AllocObjAffine(0, w, d, 0);
                tiles = gUnk_02035098[0];
                pal = gUnk_020350A0[0];
                anim = gUnk_0999A350;
            }

            DrawSprite(x, y, anim, tiles, pal, sprite, 0x800,
                          ang > 128 ? (u16)(ang * 2 + 0x6D1) : (u16)((128 - ang) * 2 + 0x7D1));

            if ((u8)(t - 65) <= 126) {
                DrawSprite(x, y, gUnk_02034FF8[i].gfx, gUnk_02034FF8[i].tiles,
                              gUnk_02034FF8[i].palette, sprite, 0x800,
                              ang > 128 ? (u16)(ang * 2 + 0x6D0)
                                        : (u16)((128 - ang) * 2 + 0x7D0));
            }
        }
    }

    switch (gUnk_020350B6) {
    case 1:
        func_080FDB1C(gUnk_020350BA, gUnk_020350B8);

        if (gUnk_020350B8 <= 8) {
            gUnk_020350B8++;
        } else {
            gUnk_020350B6 = 0;
        }
        break;
    case 2:
        func_080FDB1C(gUnk_020350BA, gUnk_020350B8);

        if (gUnk_020350B8 > 0) {
            gUnk_020350B8--;
        } else {
            gUnk_020350B6 = 0;
        }
        break;
    }

    if (gUnk_020350EF != 0) {
        BgAnimUpdate();
    }

    TaskPoolDraw(&gUnk_020350D8);
}

void func_080FE854(void) {
    SetBgMode0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 1, 30, 14);
    SetBgPriority(0, 3);
    SetBgPriority(1, 1);
    SetBgPriority(2, 0);
}
void func_080FE89C(void) {
    SetBgMode1();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 1, 30, 10);
    SetBgPriority(0, 3);
    SetBgPriority(1, 0);
    SetBgPriority(2, 2);
    gBldCnt = 0x344;
    gBldAlpha = 0x1010;
}
void func_080FE900(void) {
    gUnk_020350F2++;

    if (gUnk_020350F2 > 6) {
        gUnk_020350F2 = 0;
        gUnk_020350F4++;

        if (gUnk_020350F4 > 29) {
            gUnk_020350F4 = 0;
        }

        LoadPalette(gUnk_09EF8F24[(s16)gUnk_020350F4], (void*)0x05000040, 32);
    }
}

void mode_worldselect_0(void) {
    s16 i;
    s16 j;
    void** p;

    SpriteReset();
    gUnk_020350EE = (gGameState.progression.unk_82 ^ 1) & 1;
    gUnk_020350EF = 0;
    gUnk_020350F0 = 0;
    FadeStartIn(2, 16);

    if (gUnk_020350EE != 0) {
        func_080FE854();
    } else {
        func_080FE89C();
    }

    gUnk_02034FF0 = 0;
    gUnk_0203508C = 0;
    j = 0;

    for (i = 0; i <= 12; i++) {
        if (gGameState.unk_180 & gUnk_09992F70[i].unk_00) {
            gUnk_02035070[j] = i;
            j++;
        }
    }

    gUnk_02035092 = j;
    gUnk_02035090 = j > 5 ? 5 : j;
    j = 0;

    for (i = 0; i < gUnk_02035090; i++, j++) {
        if (j >= gUnk_02035092) {
            j = 0;
        }

        if (i == gUnk_02035090 - 1 && gUnk_02035090 > 2) {
            j = gUnk_02035092 - 1;
        }

        gUnk_02034FF8[i].unk_00 = j;
        gUnk_02034FF8[i].unk_08 = 256 / gUnk_02035090 * i - 128;
        func_080FD9B8(gUnk_02035070[j], i);
        func_080FDA28(gUnk_02035070[j], i);
        func_080FDA98(gUnk_02035070[j], i);
    }

    gUnk_020350B4 = 0;
    gUnk_020350B6 = 1;
    gUnk_020350B8 = 0;
    gUnk_020350BA = gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00];
    p = &gUnk_020350BC;
    *p = EwramAlloc(0x6C0);
    gUnk_020350F2 = 0;
    gUnk_020350F4 = 0;
    gUnk_020350C0 = 0;
    gUnk_020350C2 = 16;
    gUnk_020350C8[0] = -2048;
    gUnk_020350C8[1] = 0xA800;
    gUnk_020350D0 = -32768;
    LoadBgPalette(0, gUnk_09A3C9DC, 96);
#ifdef VERSION_EU
    LoadBgTiles(0, gUnk_099F1E7C, 16000);
#else
    LoadBgTiles(0, gUnk_099F1E7C, 11968);
#endif
    func_080FDB1C(gUnk_020350BA, gUnk_020350B8);
    LoadBgMap(0, gUnk_09A310DC, 0x500);
    LoadBgMap(1, gUnk_09A31ADC, 0x500);

    if (gUnk_020350EE == 0) {
        BgAnimInit(2, 0x8000, 128);
        BgAnimStart(&gUnk_09EDABA0, 120, 110);
        BgAnimSetLoopStartFrame(0);
        gUnk_020350EF = 1;
    }

    gUnk_020350A0[0] = LoadObjPalette(gUnk_09A3CC3C, 32);
    gUnk_02035098[0] = LoadObjTiles(gUnk_0999A394, 0xC40);
    gUnk_020350A0[1] = LoadObjPalette(gUnk_09A3CC5C, 32);
    gUnk_02035098[1] = LoadObjTiles(gUnk_0999B052, 0x1340);
    gUnk_020350AC = LoadObjPalette(gUnk_09A3CC7C, 32);
#ifdef VERSION_EU
    gUnk_020350A8 = LoadObjTiles(gUnkEu_09F84810[gLanguage], gUnkEu_099991E0.sizes[gLanguage]);
#else
    gUnk_020350A8 = LoadObjTiles(gUnk_0999CBB6, 0x380);
#endif
    gUnk_020350B0 = LoadObjTiles(gUnk_0999C410, 0x780);
    TaskPoolInit(&gUnk_020350D8, 1);
    EnableBg(0);
    EnableBg(1);

    if (gUnk_020350EE != 0) {
        DisableBg(2);
    } else {
        EnableBg(2);
    }
}

void mode_worldselect_1(void) {
    s16 a;
    s16 b;

    UpdatePlayTime();
    gUnk_020350B4 += 2;

    switch (gUnk_020350C0) {
    case 0:
        ApproachValue(&gUnk_020350C8[0], 0, gUnk_020350C2);
        ApproachValue(&gUnk_020350C8[1], 0x9800, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020350D0, 0, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            if (gUnk_020350EE != 0) {
                gUnk_020350EC = 0;
                func_080A411C(&gUnk_020350D8, 2, 70);
                gUnk_020350C0 = 2;
            } else {
                gUnk_020350C0 = 3;
            }

            LoadBgMap(0, gUnk_09A315DC, 0x500);
#ifdef VERSION_EU
            LoadBgMap(1, gUnkEu_09F847D4[gLanguage], 0x500);
#else
            LoadBgMap(1, gUnk_09A31FDC, 0x500);
#endif
        }
        break;
    case 2:
        if (func_080A42C8() == 0) {
            if (gUnk_020350EC == 0) {
                func_080A411C(&gUnk_020350D8, 2, 71);
                gUnk_020350EC++;
            } else {
                gGameState.progression.unk_82 |= 1;
                func_080FE89C();
                BgAnimInit(2, 0x8000, 128);
                BgAnimStart(&gUnk_09EDABA0, 120, 110);
                BgAnimSetLoopStartFrame(0);
                gUnk_020350EF = 1;
                gUnk_020350C0 = 3;
            }
        }
        break;
    case 3:
        func_080FDC04();
        break;
    case 4:
        if (BgAnimIsStopped() != 0) {
            LoadBgMap(0, gUnk_09A310DC, 0x500);
            LoadBgMap(1, gUnk_09A31ADC, 0x500);
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 5;
        }
        break;
    case 5:
        ApproachValue(&gUnk_020350D0, -32768, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            gUnk_020350C2 = 16;
            gUnk_020350C0 = 6;
        }
        break;
    case 6:
        ApproachValue(&gUnk_020350C8[0], -2048, gUnk_020350C2);
        ApproachValue(&gUnk_020350C8[1], 0xA800, gUnk_020350C2);
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            gUnk_020350C0 = 7;
        }
        break;
    case 7:
        FadeLock();

        if (gUnk_020350F0 != 0) {
            FadeStartOut(0, 16);
        } else {
            FadeStartOut(2, 16);
        }

        gUnk_020350C0 = 8;
        break;
    case 8:
        if (FadeIsActive() == 0) {
            if (gUnk_020350F0 != 0) {
                func_080E04EC();
            } else {
                gUnk_020350C2 = 60;
                gUnk_020350C0 = 9;
            }
        }
        break;
    case 9:
        gUnk_020350C2--;

        if (gUnk_020350C2 <= 0) {
            a = gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_02;

            if ((gGameState.flags & 8) == 0) {
                b = gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_04;
            } else {
                b = gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_06;
            }

            gGameState.unk_180 &=
                ~gUnk_09992F70[gUnk_02035070[gUnk_02034FF8[gUnk_02034FF0].unk_00]].unk_00;
            func_080DFA18(a);

            if (b >= 0) {
                func_0806180C(b);
            } else {
                if (gGameState.flags & 8) {
                    AddMapCard(221);
                }

                func_080DFA3C();
                func_080E04EC();
            }
        }
        break;
    }

    func_080FE900();

    if (FadeIsActive() != 0) {
        FadeGetAmount();
    }

    TaskPoolUpdate(&gUnk_020350D8);
    func_080FE47C();
}

void mode_worldselect_2(void) {
    s16 i;

    EwramFree(gUnk_020350BC);

    for (i = 0; i < gUnk_02035090; i++) {
        ReleaseObjPalette(gUnk_02034FF8[i].palette);
        ReleaseObjTiles(gUnk_02034FF8[i].tiles);
    }

    for (i = 0; i < 2; i++) {
        ReleaseObjPalette(gUnk_020350A0[i]);
        ReleaseObjTiles(gUnk_02035098[i]);
    }

    ReleaseObjPalette(gUnk_020350AC);
    ReleaseObjTiles(gUnk_020350A8);
    ReleaseObjTiles(gUnk_020350B0);
    TaskPoolDestroy(&gUnk_020350D8);
}
