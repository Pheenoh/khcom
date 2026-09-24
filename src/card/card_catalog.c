#include <stddef.h>
#include "card_def_data.h"
#include "card_def_assets.h"
#include "sprites_card_pictures.h"
#include "sprite_palettes.h"
#include "card_label_data.h"
#include "card_localized_data.h"
#include "card_label_language_data.h"
#include "mode_test_assets.h"

const CardBack gUnk_08F709B0[5] = {
    {
        gUnk_0905A668, gUnk_0905D564, gUnk_09047A10, gUnk_0905A682, gUnk_0905D64E, gUnk_09047A2A,
    },
    {
        gUnk_09059E94, gUnk_0905ABA0, gUnk_0904723C, gUnk_09059EAE, gUnk_0905AC8A, gUnk_09047256,
    },
    {
        gUnk_0905A3CC, gUnk_0905C778, gUnk_09047774, gUnk_0905A3E6, gUnk_0905C862, gUnk_0904778E,
    },
    {
        gUnk_0905A130, gUnk_0905B98C, gUnk_090474D8, gUnk_0905A14A, gUnk_0905BA76, gUnk_090474F2,
    },
    {
        gUnk_0905A904, gUnk_0905E350, gUnk_09047CAC, gUnk_0905A91E, gUnk_0905E3BA, gUnk_09047CC6,
    },
};

const CardBack gUnk_08F70A28[5] = {
    {
        gUnk_0905A130, gUnk_0905B98C, gUnk_0904A190, gUnk_0905A14A, gUnk_0905BA76, gUnk_0904A1AA,
    },
    {
        gUnk_0905A130, gUnk_0905B98C, gUnk_0904A190, gUnk_0905A14A, gUnk_0905BA76, gUnk_0904A1AA,
    },
    {
        gUnk_0905A130, gUnk_0905B98C, gUnk_0904A190, gUnk_0905A14A, gUnk_0905BA76, gUnk_0904A1AA,
    },
    {
        gUnk_0905A130, gUnk_0905B98C, gUnk_0904A190, gUnk_0905A14A, gUnk_0905BA76, gUnk_0904A1AA,
    },
    {
        gUnk_0905A130, gUnk_0905B98C, gUnk_0904A190, gUnk_0905A14A, gUnk_0905BA76, gUnk_0904A1AA,
    },
};

const u8 gUnk_08F70AA0[3] = "\x81\x9C";

const u8 gUnk_08F70AA4[3] = "\x81\x9B";

const u8 gUnk_08F70AA8[3] = "\x81\x9A";

const u8 gUnk_08F70AAC[3] = "\x81\x99";

const CardDef gCardDefs[950] = {
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 0, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 1, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 2, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 3, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 4, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 5, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 6, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 7, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 8, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnk_0815A66A, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_JP)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, gUnkJp_0814E664, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#elif defined(VERSION_EU)
        gUnk_09051580, gUnk_09051594, gUnk_09611E58, &gUnkEu_0888E860, gUnk_0905F0BC, gUnk_0905F0D0, gUnk_09612C38,
#endif
        0, 0x0, 9, {0, 0, 0}, 0x0, 1, 0, 0, 10, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 0, {0, 0, 0}, 0x3, 11, 0, 0, 15, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 1, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 2, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 3, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 4, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 5, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 6, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 7, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 8, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnk_0815A682, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_JP)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, gUnkJp_0814E678, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#elif defined(VERSION_EU)
        gUnk_09051FCC, gUnk_09051FE0, gUnk_09611EB8, &gUnkEu_0888E8B4, gUnk_0905F2E4, gUnk_0905F2F8, gUnk_09612C78,
#endif
        1, 0x0, 9, {0, 0, 0}, 0x3, 11, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 0, {0, 0, 0}, 0x4, 21, 0, 0, 20, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 1, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 2, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 3, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 4, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 5, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 6, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 7, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 8, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnk_0815A69C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_JP)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, gUnkJp_0814E68C, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#elif defined(VERSION_EU)
        gUnk_090521E0, gUnk_090521F6, gUnk_09611ED8, &gUnkEu_0888E904, gUnk_0905F3F8, gUnk_0905F40C, gUnk_09612C98,
#endif
        2, 0x0, 9, {0, 0, 0}, 0x4, 21, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 0, {0, 0, 0}, 0x5, 31, 0, 0, 15, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 1, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 2, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 3, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 4, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 5, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 6, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 7, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 8, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnk_0815A6AE, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_JP)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, gUnkJp_0814E6A0, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#elif defined(VERSION_EU)
        gUnk_090523F8, gUnk_0905240C, gUnk_09611EF8, &gUnkEu_0888E964, gUnk_0905F50C, gUnk_0905F520, gUnk_09612CB8,
#endif
        3, 0x0, 9, {0, 0, 0}, 0x5, 31, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 0, {0, 0, 0}, 0x6, 41, 0, 0, 20, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 1, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 2, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 3, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 4, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 5, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 6, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 7, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 8, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnk_0815A6C6, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_JP)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, gUnkJp_0814E6B4, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#elif defined(VERSION_EU)
        gUnk_0905260C, gUnk_09052620, gUnk_09611F18, &gUnkEu_0888E9B8, gUnk_0905F620, gUnk_0905F634, gUnk_09612CD8,
#endif
        4, 0x0, 9, {0, 0, 0}, 0x6, 41, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 0, {0, 0, 0}, 0x7, 51, 0, 0, 15, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 1, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 2, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 3, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 4, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 5, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 6, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 7, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 8, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnk_0815A6DC, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_JP)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, gUnkJp_0814E6C8, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#elif defined(VERSION_EU)
        gUnk_09052820, gUnk_09052834, gUnk_09611F38, &gUnkEu_0888EA14, gUnk_0905F734, gUnk_0905F748, gUnk_09612CF8,
#endif
        5, 0x0, 9, {0, 0, 0}, 0x7, 51, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 0, {0, 0, 0}, 0x8, 61, 0, 0, 20, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 1, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 2, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 3, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 4, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 5, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 6, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 7, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 8, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnk_0815A6F6, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_JP)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, gUnkJp_0814E6DC, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#elif defined(VERSION_EU)
        gUnk_09052A34, gUnk_09052A48, gUnk_09611F58, &gUnkEu_0888EA64, gUnk_0905F848, gUnk_0905F85C, gUnk_09612D18,
#endif
        6, 0x0, 9, {0, 0, 0}, 0x8, 61, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 0, {0, 0, 0}, 0x9, 71, 0, 0, 20, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 1, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 2, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 3, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 4, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 5, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 6, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 7, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 8, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnk_0815A70E, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_JP)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, gUnkJp_0814E6F0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#elif defined(VERSION_EU)
        gUnk_09052C48, gUnk_09052C5C, gUnk_09611F78, &gUnkEu_0888EAC0, gUnk_0905F95C, gUnk_0905F970, gUnk_09612D38,
#endif
        7, 0x0, 9, {0, 0, 0}, 0x9, 71, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 0, {0, 0, 0}, 0x2, 81, 0, 0, 15, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 1, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 2, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 3, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 4, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 5, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 6, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 7, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 8, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnk_0815A72A, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_JP)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, gUnkJp_0814E700, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#elif defined(VERSION_EU)
        gUnk_090519A8, gUnk_090519CC, gUnk_09611E98, &gUnkEu_0888EB00, gUnk_0905F1D0, gUnk_0905F1E4, gUnk_09612C58,
#endif
        8, 0x0, 9, {0, 0, 0}, 0x2, 81, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 0, {0, 0, 0}, 0xa, 91, 0, 0, 20, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 1, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 2, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 3, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 4, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 5, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 6, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 7, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 8, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnk_0815A73A, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_JP)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, gUnkJp_0814E714, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#elif defined(VERSION_EU)
        gUnk_09052E5C, gUnk_09052E70, gUnk_09611F98, &gUnkEu_0888EB4C, gUnk_0905FA70, gUnk_0905FA84, gUnk_09612D58,
#endif
        9, 0x0, 9, {0, 0, 0}, 0xa, 91, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 0, {0, 0, 0}, 0xb, 101, 0, 0, 15, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 1, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 2, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 3, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 4, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 5, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 6, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 7, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 8, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnk_0815A74E, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_JP)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, gUnkJp_0814E724, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#elif defined(VERSION_EU)
        gUnk_09053070, gUnk_09053084, gUnk_09611FB8, &gUnkEu_0888EBA4, gUnk_0905FB84, gUnk_0905FB98, gUnk_09612D78,
#endif
        10, 0x0, 9, {0, 0, 0}, 0xb, 101, 0, 0, 15, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 0, {0, 0, 0}, 0xc, 111, 0, 0, 20, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 1, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 2, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 3, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 4, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 5, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 6, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 7, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 8, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnk_0815A762, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_JP)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, gUnkJp_0814E734, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#elif defined(VERSION_EU)
        gUnk_09053284, gUnk_09053298, gUnk_09611FD8, &gUnkEu_0888EBF0, gUnk_0905FC98, gUnk_0905FCAC, gUnk_09612D98,
#endif
        11, 0x0, 9, {0, 0, 0}, 0xc, 111, 0, 0, 20, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 0, {0, 0, 0}, 0xd, 121, 0, 0, 25, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 1, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 2, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 3, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 4, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 5, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 6, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 7, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 8, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnk_0815A77A, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_JP)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, gUnkJp_0814E748, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#elif defined(VERSION_EU)
        gUnk_09053498, gUnk_090534AC, gUnk_09611FF8, &gUnkEu_0888EC44, gUnk_0905FDAC, gUnk_0905FDC0, gUnk_09612DB8,
#endif
        12, 0x0, 9, {0, 0, 0}, 0xd, 121, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 0, {0, 0, 0}, 0xe, 131, 0, 0, 25, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 1, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 2, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 3, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 4, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 5, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 6, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 7, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 8, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnk_0815A790, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_JP)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, gUnkJp_0814E758, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#elif defined(VERSION_EU)
        gUnk_090536AC, gUnk_090536C0, gUnk_09612018, &gUnkEu_0888EC9C, gUnk_0905FEC0, gUnk_0905FED4, gUnk_09612DD8,
#endif
        13, 0x0, 9, {0, 0, 0}, 0xe, 131, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 0, {0, 0, 0}, 0x10, 141, 0, 0, 25, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 1, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 2, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 3, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 4, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 5, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 6, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 7, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 8, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnk_0815A7BE, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_JP)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, gUnkJp_0814E780, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#elif defined(VERSION_EU)
        gUnk_09053AD4, gUnk_09053AE8, gUnk_09612058, &gUnkEu_0888ED48, gUnk_090600E8, gUnk_090600FC, gUnk_09612E18,
#endif
        14, 0x0, 9, {0, 0, 0}, 0x10, 141, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 0, {0, 0, 0}, 0x11, 151, 0, 0, 25, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 1, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 2, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 3, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 4, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 5, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 6, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 7, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 8, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnk_0815A7D8, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_JP)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, gUnkJp_0814E794, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#elif defined(VERSION_EU)
        gUnk_09053CE8, gUnk_09053CFC, gUnk_09612078, &gUnkEu_0888EDAC, gUnk_090601FC, gUnk_09060210, gUnk_09612E38,
#endif
        15, 0x0, 9, {0, 0, 0}, 0x11, 151, 0, 0, 25, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 0, {0, 0, 0}, 0xf, 161, 0, 0, 30, {10, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 1, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 2, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 3, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 4, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 5, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 6, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 7, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 8, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnk_0815A7A2, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_JP)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, gUnkJp_0814E76C, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#elif defined(VERSION_EU)
        gUnk_090538C0, gUnk_090538D4, gUnk_09612038, &gUnkEu_0888ECE8, gUnk_0905FFD4, gUnk_0905FFE8, gUnk_09612DF8,
#endif
        16, 0x0, 9, {0, 0, 0}, 0xf, 161, 0, 0, 30, {2, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 0, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 1, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 2, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 3, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 4, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 5, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 6, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 7, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 8, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnk_0815A7FA, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_JP)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, gUnkJp_0814E7A0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#elif defined(VERSION_EU)
        gUnk_0904619C, gUnk_090461B0, gUnk_09611BB8, &gUnkEu_0888EDE0, gUnk_09060424, gUnk_09060438, gUnk_09612E78,
#endif
        18, 0x0, 9, {0, 0, 0}, 0x13, 171, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 0, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 1, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 2, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 3, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 4, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 5, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 6, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 7, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 8, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnk_0815A804, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_JP)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, gUnkJp_0814E7AC, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#elif defined(VERSION_EU)
        gUnk_090463B0, gUnk_090463C4, gUnk_09611BD8, &gUnkEu_0888EE18, gUnk_09060538, gUnk_0906054C, gUnk_09612E98,
#endif
        19, 0x0, 9, {0, 0, 0}, 0x14, 181, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 0, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 1, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 2, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 3, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 4, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 5, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 6, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 7, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 8, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnk_0815A816, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_JP)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, gUnkJp_0814E7B8, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#elif defined(VERSION_EU)
        gUnk_090465C4, gUnk_090465D8, gUnk_09611BF8, &gUnkEu_0888EE50, gUnk_0906064C, gUnk_09060660, gUnk_09612EB8,
#endif
        20, 0x0, 9, {0, 0, 0}, 0x15, 191, 1, 0, 15, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 0, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 1, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 2, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 3, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 4, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 5, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 6, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 7, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 8, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnk_0815A826, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_JP)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, gUnkJp_0814E7C4, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#elif defined(VERSION_EU)
        gUnk_090467D8, gUnk_090467EC, gUnk_09611C18, &gUnkEu_0888EE80, gUnk_09060760, gUnk_09060774, gUnk_09612ED8,
#endif
        21, 0x0, 9, {0, 0, 0}, 0x16, 201, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 0, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 1, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 2, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 3, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 4, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 5, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 6, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 7, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 8, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnk_0815A830, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_JP)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, gUnkJp_0814E7CC, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#elif defined(VERSION_EU)
        gUnk_090469EC, gUnk_09046A00, gUnk_09611C38, &gUnkEu_0888EEC0, gUnk_09060874, gUnk_09060888, gUnk_09612EF8,
#endif
        22, 0x0, 9, {0, 0, 0}, 0x17, 211, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 0, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 1, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 2, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 3, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 4, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 5, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 6, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 7, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 8, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnk_0815A840, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_JP)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, gUnkJp_0814E7D8, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#elif defined(VERSION_EU)
        gUnk_09046C00, gUnk_09046C14, gUnk_09611C58, &gUnkEu_0888EEF0, gUnk_09060988, gUnk_0906099C, gUnk_09612F18,
#endif
        23, 0x0, 9, {0, 0, 0}, 0x18, 221, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 0, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 1, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 2, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 3, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 4, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 5, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 6, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 7, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 8, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnk_0815A84A, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_JP)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, gUnkJp_0814E7E4, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#elif defined(VERSION_EU)
        gUnk_09046E14, gUnk_09046E28, gUnk_09611C78, &gUnkEu_0888EF20, gUnk_09060A9C, gUnk_09060AB0, gUnk_09612F38,
#endif
        24, 0x0, 9, {0, 0, 0}, 0x19, 231, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 0, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 1, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 2, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 3, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 4, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 5, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 6, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 7, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 8, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnk_0815A932, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_JP)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, gUnkJp_0814E8A8, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#elif defined(VERSION_EU)
        gUnk_0904815C, gUnk_09048170, gUnk_09617C58, &gUnkEu_0888F2C0, gUnk_09061450, gUnk_09061464, gUnk_09613058,
#endif
        39, 0x8, 9, {0, 0, 0}, 0x1c, 241, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 0, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 1, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 2, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 3, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 4, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 5, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 6, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 7, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 8, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnk_0815A94A, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_JP)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, gUnkJp_0814E8B8, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#elif defined(VERSION_EU)
        gUnk_09047F48, gUnk_09047F5C, gUnk_08F68384, &gUnkEu_0888F2F4, gUnk_0906133C, gUnk_09061350, gUnk_09613038,
#endif
        40, 0x8, 9, {0, 0, 0}, 0x1b, 251, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 0, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 1, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 2, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 3, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 4, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 5, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 6, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 7, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 8, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnk_0815A854, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_JP)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, gUnkJp_0814E7EC, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#elif defined(VERSION_EU)
        gUnk_09048370, gUnk_09048384, gUnk_09611CF8, &gUnkEu_0888EF54, gUnk_09061564, gUnk_09061578, gUnk_09613078,
#endif
        25, 0x4, 9, {0, 0, 0}, 0x1d, 261, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 0, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 1, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 2, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 3, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 4, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 5, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 6, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 7, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 8, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnk_0815A860, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_JP)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, gUnkJp_0814E7F4, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#elif defined(VERSION_EU)
        gUnk_09048584, gUnk_09048598, gUnk_09611D18, &gUnkEu_0888EF8C, gUnk_09061678, gUnk_0906168C, gUnk_09613098,
#endif
        26, 0x4, 9, {0, 0, 0}, 0x1e, 271, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 0, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 1, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 2, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 3, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 4, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 5, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 6, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 7, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 8, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnk_0815A86C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_JP)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, gUnkJp_0814E80C, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#elif defined(VERSION_EU)
        gUnk_09048798, gUnk_090487AC, gUnk_09617FF8, &gUnkEu_0888EFC0, gUnk_0906178C, gUnk_090617A0, gUnk_096130B8,
#endif
        27, 0x4, 9, {0, 0, 0}, 0x1f, 281, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 0, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 1, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 2, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 3, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 4, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 5, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 6, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 7, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 8, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnk_0815A878, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_JP)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, gUnkJp_0814E814, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#elif defined(VERSION_EU)
        gUnk_090489AC, gUnk_090489C0, gUnk_09611D58, &gUnkEu_0888EFF4, gUnk_090618A0, gUnk_090618B4, gUnk_096130D8,
#endif
        28, 0x4, 9, {0, 0, 0}, 0x20, 291, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 0, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 1, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 2, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 3, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 4, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 5, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 6, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 7, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 8, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnk_0815A884, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_JP)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, gUnkJp_0814E81C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#elif defined(VERSION_EU)
        gUnk_09048BC0, gUnk_09048BD4, gUnk_09618098, &gUnkEu_0888F03C, gUnk_090619B4, gUnk_090619C8, gUnk_096130F8,
#endif
        29, 0x4, 9, {0, 0, 0}, 0x21, 301, 1, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 0, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 1, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 2, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 3, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 4, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 5, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 6, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 7, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 8, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnk_0815A89C, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_JP)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, gUnkJp_0814E828, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#elif defined(VERSION_EU)
        gUnk_09048DD4, gUnk_09048DE8, gUnk_09618038, &gUnkEu_0888F070, gUnk_09061AC8, gUnk_09061ADC, gUnk_09613118,
#endif
        30, 0x4, 9, {0, 0, 0}, 0x22, 311, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 0, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 1, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 2, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 3, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 4, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 5, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 6, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 7, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 8, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnk_0815A8A8, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, gUnkJp_0814E834, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DB8, &gUnkEu_0888F0A4, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613138,
#endif
        31, 0x4, 9, {0, 0, 0}, 0x23, 321, 1, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 0, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 1, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 2, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 3, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 4, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 5, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 6, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 7, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 8, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnk_0815A956, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_JP)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, gUnkJp_0814E8DC, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#elif defined(VERSION_EU)
        gUnk_090491FC, gUnk_09049210, gUnk_09617D98, &gUnkEu_0888F394, gUnk_09061CF4, gUnk_09061D08, gUnk_096131F8,
#endif
        41, 0x8, 9, {0, 0, 0}, 0x28, 331, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 0, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 1, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 2, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 3, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 4, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 5, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 6, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 7, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 8, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnk_0815A966, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_JP)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, gUnkJp_0814E8E8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#elif defined(VERSION_EU)
        gUnk_09049410, gUnk_09049424, gUnk_09617DF8, &gUnkEu_0888F3C8, gUnk_09061E08, gUnk_09061E1C, gUnk_09613218,
#endif
        42, 0x8, 9, {0, 0, 0}, 0x29, 341, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 0, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 1, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 2, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 3, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 4, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 5, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 6, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 7, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 8, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnk_0815A972, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_JP)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, gUnkJp_0814E8F4, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#elif defined(VERSION_EU)
        gUnk_09049624, gUnk_09049638, gUnk_09617DB8, &gUnkEu_0888F3F8, gUnk_09061F1C, gUnk_09061F30, gUnk_09613238,
#endif
        43, 0x8, 9, {0, 0, 0}, 0x2a, 351, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 0, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 1, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 2, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 3, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 4, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 5, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 6, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 7, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 8, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnk_0815A97C, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_JP)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, gUnkJp_0814E900, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#elif defined(VERSION_EU)
        gUnk_09049838, gUnk_0904984C, gUnk_09617DD8, &gUnkEu_0888F440, gUnk_09062030, gUnk_09062044, gUnk_09613258,
#endif
        44, 0x8, 9, {0, 0, 0}, 0x2b, 361, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 0, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 1, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 2, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 3, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 4, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 5, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 6, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 7, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 8, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnk_0815A990, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_JP)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, gUnkJp_0814E910, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#elif defined(VERSION_EU)
        gUnk_09049A4C, gUnk_09049A60, gUnk_09617E18, &gUnkEu_0888F484, gUnk_09062144, gUnk_09062158, gUnk_09613278,
#endif
        45, 0x8, 9, {0, 0, 0}, 0x2c, 371, 2, 0, 25, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 0, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 1, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 2, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 3, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 4, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 5, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 6, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 7, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 8, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnk_0815A8B4, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_JP)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, gUnkJp_0814E840, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#elif defined(VERSION_EU)
        gUnk_09045240, gUnk_09045254, gUnk_09611AD8, &gUnkEu_0888F0DC, gUnk_09060BB0, gUnk_09060BC4, gUnk_09612F58,
#endif
        32, 0x2, 9, {0, 0, 0}, 0x2f, 381, 2, 0, 30, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 0, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 1, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 2, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 3, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 4, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 5, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 6, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 7, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 8, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnk_0815A8C2, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_JP)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, gUnkJp_0814E84C, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#elif defined(VERSION_EU)
        gUnk_09045454, gUnk_09045468, gUnk_09611AF8, &gUnkEu_0888F128, gUnk_09060CC4, gUnk_09060CD8, gUnk_09612F78,
#endif
        33, 0x2, 9, {0, 0, 0}, 0x30, 391, 2, 0, 40, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 0, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 1, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 2, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 3, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 4, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 5, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 6, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 7, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 8, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnk_0815A8D6, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_JP)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, gUnkJp_0814E85C, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#elif defined(VERSION_EU)
        gUnk_09045668, gUnk_0904567C, gUnk_09611B18, &gUnkEu_0888F178, gUnk_09060DD8, gUnk_09060DEC, gUnk_09612F98,
#endif
        34, 0x2, 9, {0, 0, 0}, 0x31, 401, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 0, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 1, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 2, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 3, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 4, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 5, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 6, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 7, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 8, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnk_0815A8EE, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_JP)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, gUnkJp_0814E86C, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#elif defined(VERSION_EU)
        gUnk_0904587C, gUnk_09045890, gUnk_09611B38, &gUnkEu_0888F1AC, gUnk_09060EEC, gUnk_09060F00, gUnk_09612FB8,
#endif
        35, 0x2, 9, {0, 0, 0}, 0x32, 411, 2, 0, 20, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 0, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 1, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 2, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 3, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 4, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 5, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 6, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 7, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 8, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnk_0815A8FA, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_JP)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, gUnkJp_0814E878, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#elif defined(VERSION_EU)
        gUnk_09045A90, gUnk_09045AA4, gUnk_09611B58, &gUnkEu_0888F1F4, gUnk_09061000, gUnk_09061014, gUnk_09612FD8,
#endif
        36, 0x2, 9, {0, 0, 0}, 0x33, 421, 2, 0, 35, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 0, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 1, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 2, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 3, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 4, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 5, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 6, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 7, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 8, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnk_0815A910, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_JP)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, gUnkJp_0814E888, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#elif defined(VERSION_EU)
        gUnk_09045CA4, gUnk_09045CB8, gUnk_09611B78, &gUnkEu_0888F22C, gUnk_09061114, gUnk_09061128, gUnk_09612FF8,
#endif
        37, 0x2, 9, {0, 0, 0}, 0x34, 431, 2, 0, 45, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 0, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 1, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 2, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 3, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 4, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 5, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 6, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 7, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 8, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnk_0815A91E, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_JP)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, gUnkJp_0814E894, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#elif defined(VERSION_EU)
        gUnk_09045EB8, gUnk_09045ECC, gUnk_09611B98, &gUnkEu_0888F278, gUnk_09061228, gUnk_0906123C, gUnk_09613018,
#endif
        38, 0x2, 9, {0, 0, 0}, 0x35, 441, 2, 0, 50, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, gUnk_0815A9A4, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#elif defined(VERSION_JP)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, gUnkJp_0814E9EC, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#elif defined(VERSION_EU)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, &gUnkEu_0888F880, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#endif
        47, 0x0, 1, {0, 0, 0}, 0x1, 450, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, gUnk_0815A9A4, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#elif defined(VERSION_JP)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, gUnkJp_0814E9EC, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#elif defined(VERSION_EU)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, &gUnkEu_0888F880, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#endif
        47, 0x0, 1, {0, 0, 0}, 0x1, 450, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, gUnk_0815A9A4, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#elif defined(VERSION_JP)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, gUnkJp_0814E9EC, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#elif defined(VERSION_EU)
        gUnk_0904AD80, gUnk_0904AD94, gUnk_08F697A4, &gUnkEu_0888F880, gUnk_0906236C, gUnk_09062380, gUnk_096132B8,
#endif
        47, 0x0, 1, {0, 0, 0}, 0x1, 450, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, gUnk_0815A9B2, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#elif defined(VERSION_JP)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, gUnkJp_0814E9F8, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#elif defined(VERSION_EU)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, &gUnkEu_0888F8C4, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#endif
        48, 0x0, 1, {0, 0, 0}, 0x3, 453, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, gUnk_0815A9B2, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#elif defined(VERSION_JP)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, gUnkJp_0814E9F8, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#elif defined(VERSION_EU)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, &gUnkEu_0888F8C4, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#endif
        48, 0x0, 2, {0, 0, 0}, 0x3, 453, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, gUnk_0815A9B2, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#elif defined(VERSION_JP)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, gUnkJp_0814E9F8, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#elif defined(VERSION_EU)
        gUnk_0904BE20, gUnk_0904BE34, gUnk_08F697E4, &gUnkEu_0888F8C4, gUnk_090628D0, gUnk_090628E4, gUnk_096133B8,
#endif
        48, 0x0, 2, {0, 0, 0}, 0x3, 453, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, gUnk_0815A9EC, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#elif defined(VERSION_JP)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, gUnkJp_0814EA28, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#elif defined(VERSION_EU)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, &gUnkEu_0888F9AC, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#endif
        49, 0x0, 1, {0, 0, 0}, 0x33, 456, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, gUnk_0815A9EC, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#elif defined(VERSION_JP)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, gUnkJp_0814EA28, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#elif defined(VERSION_EU)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, &gUnkEu_0888F9AC, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#endif
        49, 0x0, 3, {0, 0, 0}, 0x33, 456, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, gUnk_0815A9EC, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#elif defined(VERSION_JP)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, gUnkJp_0814EA28, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#elif defined(VERSION_EU)
        gUnk_0904E188, gUnk_0904E19C, gUnk_08F697C4, &gUnkEu_0888F9AC, gUnk_09063A10, gUnk_09063A24, gUnk_096135B8,
#endif
        49, 0x0, 4, {0, 0, 0}, 0x33, 456, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, gUnk_0815AA46, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#elif defined(VERSION_JP)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, gUnkJp_0814EA78, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#elif defined(VERSION_EU)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, &gUnkEu_0888FB28, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#endif
        50, 0x0, 1, {0, 0, 0}, 0x4, 459, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, gUnk_0815AA46, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#elif defined(VERSION_JP)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, gUnkJp_0814EA78, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#elif defined(VERSION_EU)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, &gUnkEu_0888FB28, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#endif
        50, 0x0, 2, {0, 0, 0}, 0x4, 459, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, gUnk_0815AA46, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#elif defined(VERSION_JP)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, gUnkJp_0814EA78, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#elif defined(VERSION_EU)
        gUnk_0904AF94, gUnk_0904AFA8, gUnk_08F69804, &gUnkEu_0888FB28, gUnk_09062480, gUnk_09062494, gUnk_096132D8,
#endif
        50, 0x0, 4, {0, 0, 0}, 0x4, 459, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, gUnk_0815AA60, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#elif defined(VERSION_JP)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, gUnkJp_0814EA8C, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#elif defined(VERSION_EU)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, &gUnkEu_0888FB84, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#endif
        51, 0x0, 1, {0, 0, 0}, 0xb, 463, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, gUnk_0815AA60, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#elif defined(VERSION_JP)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, gUnkJp_0814EA8C, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#elif defined(VERSION_EU)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, &gUnkEu_0888FB84, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#endif
        51, 0x0, 2, {0, 0, 0}, 0xb, 463, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, gUnk_0815AA60, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#elif defined(VERSION_JP)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, gUnkJp_0814EA8C, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#elif defined(VERSION_EU)
        gUnk_0904B1A8, gUnk_0904B1BC, gUnk_08F69824, &gUnkEu_0888FB84, gUnk_09062480, gUnk_09062494, gUnk_096132F8,
#endif
        51, 0x0, 4, {0, 0, 0}, 0xb, 463, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, gUnk_0815AA7C, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#elif defined(VERSION_JP)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, gUnkJp_0814EAA0, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#elif defined(VERSION_EU)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, &gUnkEu_0888FBDC, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#endif
        52, 0x0, 1, {0, 0, 0}, 0xc, 466, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, gUnk_0815AA7C, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#elif defined(VERSION_JP)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, gUnkJp_0814EAA0, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#elif defined(VERSION_EU)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, &gUnkEu_0888FBDC, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#endif
        52, 0x0, 2, {0, 0, 0}, 0xc, 466, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, gUnk_0815AA7C, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#elif defined(VERSION_JP)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, gUnkJp_0814EAA0, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#elif defined(VERSION_EU)
        gUnk_0904B3BC, gUnk_0904B3D0, gUnk_08F69844, &gUnkEu_0888FBDC, gUnk_09062480, gUnk_09062494, gUnk_09613318,
#endif
        52, 0x0, 4, {0, 0, 0}, 0xc, 466, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, gUnk_0815AA96, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#elif defined(VERSION_JP)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, gUnkJp_0814EAB0, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#elif defined(VERSION_EU)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, &gUnkEu_0888FC34, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#endif
        53, 0x0, 1, {0, 0, 0}, 0xd, 469, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, gUnk_0815AA96, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#elif defined(VERSION_JP)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, gUnkJp_0814EAB0, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#elif defined(VERSION_EU)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, &gUnkEu_0888FC34, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#endif
        53, 0x0, 2, {0, 0, 0}, 0xd, 469, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, gUnk_0815AA96, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#elif defined(VERSION_JP)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, gUnkJp_0814EAB0, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#elif defined(VERSION_EU)
        gUnk_0904B5D0, gUnk_0904B5E4, gUnk_08F69864, &gUnkEu_0888FC34, gUnk_09062480, gUnk_09062494, gUnk_09613338,
#endif
        53, 0x0, 4, {0, 0, 0}, 0xd, 469, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, gUnk_0815A9C2, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#elif defined(VERSION_JP)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, gUnkJp_0814EA04, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#elif defined(VERSION_EU)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, &gUnkEu_0888F910, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#endif
        54, 0x0, 3, {0, 0, 0}, 0x1f, 471, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, gUnk_0815A9C2, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#elif defined(VERSION_JP)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, gUnkJp_0814EA04, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#elif defined(VERSION_EU)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, &gUnkEu_0888F910, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#endif
        54, 0x0, 3, {0, 0, 0}, 0x1f, 471, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, gUnk_0815A9C2, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#elif defined(VERSION_JP)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, gUnkJp_0814EA04, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#elif defined(VERSION_EU)
        gUnk_0904C034, gUnk_0904C048, gUnk_08F69944, &gUnkEu_0888F910, gUnk_090629E4, gUnk_090629F8, gUnk_096133D8,
#endif
        54, 0x0, 3, {0, 0, 0}, 0x1f, 471, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, gUnk_0815A9D6, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#elif defined(VERSION_JP)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, gUnkJp_0814EA14, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#elif defined(VERSION_EU)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, &gUnkEu_0888F960, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#endif
        55, 0x0, 2, {0, 0, 0}, 0x6, 474, 3, 0, 10, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, gUnk_0815A9D6, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#elif defined(VERSION_JP)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, gUnkJp_0814EA14, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#elif defined(VERSION_EU)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, &gUnkEu_0888F960, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#endif
        55, 0x0, 2, {0, 0, 0}, 0x6, 474, 3, 0, 10, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, gUnk_0815A9D6, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#elif defined(VERSION_JP)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, gUnkJp_0814EA14, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#elif defined(VERSION_EU)
        gUnk_0904C248, gUnk_0904C25C, gUnk_08F699C4, &gUnkEu_0888F960, gUnk_09062AF8, gUnk_09062B0C, gUnk_096133F8,
#endif
        55, 0x0, 2, {0, 0, 0}, 0x6, 474, 3, 0, 10, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, gUnk_0815AAC0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#elif defined(VERSION_JP)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, gUnkJp_0814EAD0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#elif defined(VERSION_EU)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, &gUnkEu_0888FCD0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#endif
        56, 0x0, 3, {0, 0, 0}, 0x1e, 477, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, gUnk_0815AAC0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#elif defined(VERSION_JP)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, gUnkJp_0814EAD0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#elif defined(VERSION_EU)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, &gUnkEu_0888FCD0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#endif
        56, 0x0, 4, {0, 0, 0}, 0x1e, 477, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, gUnk_0815AAC0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#elif defined(VERSION_JP)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, gUnkJp_0814EAD0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#elif defined(VERSION_EU)
        gUnk_0904C45C, gUnk_0904C470, gUnk_08F69B24, &gUnkEu_0888FCD0, gUnk_09062C0C, gUnk_09062C20, gUnk_09613418,
#endif
        56, 0x0, 4, {0, 0, 0}, 0x1e, 477, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, gUnk_0815AA2A, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#elif defined(VERSION_JP)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, gUnkJp_0814EA5C, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#elif defined(VERSION_EU)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, &gUnkEu_0888FA8C, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#endif
        57, 0x0, 1, {0, 0, 0}, 0x5, 480, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, gUnk_0815AA2A, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#elif defined(VERSION_JP)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, gUnkJp_0814EA5C, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#elif defined(VERSION_EU)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, &gUnkEu_0888FA8C, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#endif
        57, 0x0, 2, {0, 0, 0}, 0x5, 480, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, gUnk_0815AA2A, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#elif defined(VERSION_JP)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, gUnkJp_0814EA5C, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#elif defined(VERSION_EU)
        gUnk_0904C670, gUnk_0904C684, gUnk_08F69964, &gUnkEu_0888FA8C, gUnk_09062D20, gUnk_09062D34, gUnk_09613438,
#endif
        57, 0x0, 2, {0, 0, 0}, 0x5, 480, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, gUnk_0815AA02, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#elif defined(VERSION_JP)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, gUnkJp_0814EA38, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#elif defined(VERSION_EU)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, &gUnkEu_0888FA00, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#endif
        58, 0x0, 3, {0, 0, 0}, 0x24, 483, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, gUnk_0815AA02, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#elif defined(VERSION_JP)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, gUnkJp_0814EA38, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#elif defined(VERSION_EU)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, &gUnkEu_0888FA00, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#endif
        58, 0x0, 1, {0, 0, 0}, 0x24, 483, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, gUnk_0815AA02, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#elif defined(VERSION_JP)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, gUnkJp_0814EA38, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#elif defined(VERSION_EU)
        gUnk_0904E39C, gUnk_0904E3B0, gUnk_08F69AA4, &gUnkEu_0888FA00, gUnk_09063B24, gUnk_09063B38, gUnk_096135D8,
#endif
        58, 0x0, 6, {0, 0, 0}, 0x24, 483, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, gUnk_0815AAD8, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#elif defined(VERSION_JP)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, gUnkJp_0814EAE0, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#elif defined(VERSION_EU)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, &gUnkEu_0888FD24, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#endif
        59, 0x0, 4, {0, 0, 0}, 0x9, 486, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, gUnk_0815AAD8, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#elif defined(VERSION_JP)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, gUnkJp_0814EAE0, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#elif defined(VERSION_EU)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, &gUnkEu_0888FD24, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#endif
        59, 0x0, 4, {0, 0, 0}, 0x9, 486, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, gUnk_0815AAD8, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#elif defined(VERSION_JP)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, gUnkJp_0814EAE0, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#elif defined(VERSION_EU)
        gUnk_0904C884, gUnk_0904C898, gUnk_08F69884, &gUnkEu_0888FD24, gUnk_09062E34, gUnk_09062E48, gUnk_09613458,
#endif
        59, 0x0, 4, {0, 0, 0}, 0x9, 486, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, gUnk_0815AB36, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#elif defined(VERSION_JP)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, gUnkJp_0814EB20, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#elif defined(VERSION_EU)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, &gUnkEu_0888FE74, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#endif
        60, 0x0, 1, {0, 0, 0}, 0x23, 489, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, gUnk_0815AB36, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#elif defined(VERSION_JP)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, gUnkJp_0814EB20, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#elif defined(VERSION_EU)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, &gUnkEu_0888FE74, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#endif
        60, 0x0, 2, {0, 0, 0}, 0x23, 489, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, gUnk_0815AB36, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#elif defined(VERSION_JP)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, gUnkJp_0814EB20, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#elif defined(VERSION_EU)
        gUnk_0904CA98, gUnk_0904CAAC, gUnk_08F699E4, &gUnkEu_0888FE74, gUnk_09062F48, gUnk_09062F5C, gUnk_09613478,
#endif
        60, 0x0, 2, {0, 0, 0}, 0x23, 489, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, gUnk_0815AA18, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#elif defined(VERSION_JP)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, gUnkJp_0814EA50, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#elif defined(VERSION_EU)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, &gUnkEu_0888FA4C, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#endif
        61, 0x0, 1, {0, 0, 0}, 0x10, 492, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, gUnk_0815AA18, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#elif defined(VERSION_JP)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, gUnkJp_0814EA50, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#elif defined(VERSION_EU)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, &gUnkEu_0888FA4C, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#endif
        61, 0x0, 1, {0, 0, 0}, 0x10, 492, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, gUnk_0815AA18, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#elif defined(VERSION_JP)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, gUnkJp_0814EA50, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#elif defined(VERSION_EU)
        gUnk_0904B7E4, gUnk_0904B7F8, gUnk_08F69924, &gUnkEu_0888FA4C, gUnk_09062594, gUnk_090625A8, gUnk_09613358,
#endif
        61, 0x0, 1, {0, 0, 0}, 0x10, 492, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, gUnk_0815AB62, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#elif defined(VERSION_JP)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, gUnkJp_0814EB40, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#elif defined(VERSION_EU)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, &gUnkEu_0888FF00, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#endif
        62, 0x0, 1, {0, 0, 0}, 0x15, 495, 3, 0, 15, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, gUnk_0815AB62, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#elif defined(VERSION_JP)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, gUnkJp_0814EB40, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#elif defined(VERSION_EU)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, &gUnkEu_0888FF00, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#endif
        62, 0x0, 2, {0, 0, 0}, 0x15, 495, 3, 0, 15, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, gUnk_0815AB62, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#elif defined(VERSION_JP)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, gUnkJp_0814EB40, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#elif defined(VERSION_EU)
        gUnk_0904CCAC, gUnk_0904CCC0, gUnk_08F69984, &gUnkEu_0888FF00, gUnk_0906305C, gUnk_09063070, gUnk_09613498,
#endif
        62, 0x0, 2, {0, 0, 0}, 0x15, 495, 3, 0, 15, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, gUnk_0815AB50, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#elif defined(VERSION_JP)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, gUnkJp_0814EB30, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#elif defined(VERSION_EU)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, &gUnkEu_0888FEBC, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#endif
        63, 0x0, 2, {0, 0, 0}, 0x28, 498, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, gUnk_0815AB50, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#elif defined(VERSION_JP)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, gUnkJp_0814EB30, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#elif defined(VERSION_EU)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, &gUnkEu_0888FEBC, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#endif
        63, 0x0, 1, {0, 0, 0}, 0x28, 498, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, gUnk_0815AB50, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#elif defined(VERSION_JP)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, gUnkJp_0814EB30, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#elif defined(VERSION_EU)
        gUnk_0904E5B0, gUnk_0904E5C4, gUnk_08F699A4, &gUnkEu_0888FEBC, gUnk_09063C38, gUnk_09063C4C, gUnk_096135F8,
#endif
        63, 0x0, 7, {0, 0, 0}, 0x28, 498, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, gUnk_0815AAF4, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#elif defined(VERSION_JP)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, gUnkJp_0814EAF4, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#elif defined(VERSION_EU)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, &gUnkEu_0888FD80, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#endif
        64, 0x0, 2, {0, 0, 0}, 0x35, 501, 3, 0, 15, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, gUnk_0815AAF4, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#elif defined(VERSION_JP)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, gUnkJp_0814EAF4, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#elif defined(VERSION_EU)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, &gUnkEu_0888FD80, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#endif
        64, 0x0, 3, {0, 0, 0}, 0x35, 501, 3, 0, 15, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, gUnk_0815AAF4, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#elif defined(VERSION_JP)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, gUnkJp_0814EAF4, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#elif defined(VERSION_EU)
        gUnk_0904CEC0, gUnk_0904CED4, gUnk_08F69AE4, &gUnkEu_0888FD80, gUnk_09063170, gUnk_09063184, gUnk_096134B8,
#endif
        64, 0x0, 3, {0, 0, 0}, 0x35, 501, 3, 0, 15, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, gUnk_0815AB24, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#elif defined(VERSION_JP)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, gUnkJp_0814EB14, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#elif defined(VERSION_EU)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, &gUnkEu_0888FE18, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#endif
        65, 0x0, 3, {0, 0, 0}, 0x13, 504, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, gUnk_0815AB24, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#elif defined(VERSION_JP)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, gUnkJp_0814EB14, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#elif defined(VERSION_EU)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, &gUnkEu_0888FE18, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#endif
        65, 0x0, 4, {0, 0, 0}, 0x13, 504, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, gUnk_0815AB24, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#elif defined(VERSION_JP)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, gUnkJp_0814EB14, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#elif defined(VERSION_EU)
        gUnk_0904D0D4, gUnk_0904D0E8, gUnk_08F69A04, &gUnkEu_0888FE18, gUnk_09063284, gUnk_09063298, gUnk_096134D8,
#endif
        65, 0x0, 4, {0, 0, 0}, 0x13, 504, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, gUnk_0815AA38, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#elif defined(VERSION_JP)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, gUnkJp_0814EA6C, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#elif defined(VERSION_EU)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, &gUnkEu_0888FACC, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#endif
        66, 0x0, 1, {0, 0, 0}, 0x11, 507, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, gUnk_0815AA38, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#elif defined(VERSION_JP)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, gUnkJp_0814EA6C, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#elif defined(VERSION_EU)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, &gUnkEu_0888FACC, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#endif
        66, 0x0, 2, {0, 0, 0}, 0x11, 507, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, gUnk_0815AA38, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#elif defined(VERSION_JP)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, gUnkJp_0814EA6C, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#elif defined(VERSION_EU)
        gUnk_0904D2E8, gUnk_0904D2FC, gUnk_08F69A24, &gUnkEu_0888FACC, gUnk_09063398, gUnk_090633AC, gUnk_096134F8,
#endif
        66, 0x0, 2, {0, 0, 0}, 0x11, 507, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, gUnk_0815AB0E, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#elif defined(VERSION_JP)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, gUnkJp_0814EB04, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#elif defined(VERSION_EU)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, &gUnkEu_0888FDD4, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#endif
        67, 0x0, 3, {0, 0, 0}, 0x1d, 510, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, gUnk_0815AB0E, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#elif defined(VERSION_JP)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, gUnkJp_0814EB04, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#elif defined(VERSION_EU)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, &gUnkEu_0888FDD4, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#endif
        67, 0x0, 4, {0, 0, 0}, 0x1d, 510, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, gUnk_0815AB0E, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#elif defined(VERSION_JP)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, gUnkJp_0814EB04, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#elif defined(VERSION_EU)
        gUnk_0904D4FC, gUnk_0904D510, gUnk_08F69A44, &gUnkEu_0888FDD4, gUnk_090634AC, gUnk_090634C0, gUnk_09613518,
#endif
        67, 0x0, 4, {0, 0, 0}, 0x1d, 510, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, gUnk_0815AB78, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#elif defined(VERSION_JP)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, gUnkJp_0814EB54, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#elif defined(VERSION_EU)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, &gUnkEu_0888FF50, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#endif
        68, 0x0, 2, {0, 0, 0}, 0x7, 513, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, gUnk_0815AB78, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#elif defined(VERSION_JP)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, gUnkJp_0814EB54, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#elif defined(VERSION_EU)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, &gUnkEu_0888FF50, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#endif
        68, 0x0, 4, {0, 0, 0}, 0x7, 513, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, gUnk_0815AB78, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#elif defined(VERSION_JP)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, gUnkJp_0814EB54, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#elif defined(VERSION_EU)
        gUnk_0904D710, gUnk_0904D724, gUnk_08F69A64, &gUnkEu_0888FF50, gUnk_090635C0, gUnk_090635D4, gUnk_09613538,
#endif
        68, 0x0, 6, {0, 0, 0}, 0x7, 513, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, gUnk_0815AB98, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#elif defined(VERSION_JP)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, gUnkJp_0814EB70, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#elif defined(VERSION_EU)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, &gUnkEu_0888FFCC, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#endif
        69, 0x0, 5, {0, 0, 0}, 0xe, 516, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, gUnk_0815AB98, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#elif defined(VERSION_JP)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, gUnkJp_0814EB70, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#elif defined(VERSION_EU)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, &gUnkEu_0888FFCC, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#endif
        69, 0x0, 1, {0, 0, 0}, 0xe, 516, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, gUnk_0815AB98, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#elif defined(VERSION_JP)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, gUnkJp_0814EB70, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#elif defined(VERSION_EU)
        gUnk_0904E7C4, gUnk_0904E7D8, gUnk_08F69B04, &gUnkEu_0888FFCC, gUnk_09063D4C, gUnk_09063D60, gUnk_09613618,
#endif
        69, 0x0, 9, {0, 0, 0}, 0xe, 516, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, gUnk_0815AB8A, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#elif defined(VERSION_JP)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, gUnkJp_0814EB64, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#elif defined(VERSION_EU)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, &gUnkEu_0888FF88, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#endif
        70, 0x0, 4, {0, 0, 0}, 0x19, 519, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, gUnk_0815AB8A, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#elif defined(VERSION_JP)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, gUnkJp_0814EB64, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#elif defined(VERSION_EU)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, &gUnkEu_0888FF88, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#endif
        70, 0x0, 5, {0, 0, 0}, 0x19, 519, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, gUnk_0815AB8A, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#elif defined(VERSION_JP)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, gUnkJp_0814EB64, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#elif defined(VERSION_EU)
        gUnk_0904D924, gUnk_0904D938, gUnk_08F69AC4, &gUnkEu_0888FF88, gUnk_090636D4, gUnk_090636E8, gUnk_09613558,
#endif
        70, 0x0, 5, {0, 0, 0}, 0x19, 519, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, gUnk_0815AAB2, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#elif defined(VERSION_JP)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, gUnkJp_0814EAC4, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#elif defined(VERSION_EU)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, &gUnkEu_0888FC74, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#endif
        71, 0x0, 3, {0, 0, 0}, 0x26, 522, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, gUnk_0815AAB2, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#elif defined(VERSION_JP)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, gUnkJp_0814EAC4, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#elif defined(VERSION_EU)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, &gUnkEu_0888FC74, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#endif
        71, 0x0, 1, {0, 0, 0}, 0x26, 522, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, gUnk_0815AAB2, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#elif defined(VERSION_JP)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, gUnkJp_0814EAC4, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#elif defined(VERSION_EU)
        gUnk_0904DB38, gUnk_0904DB4C, gUnk_08F69904, &gUnkEu_0888FC74, gUnk_090637E8, gUnk_090637FC, gUnk_09613578,
#endif
        71, 0x0, 7, {0, 0, 0}, 0x26, 522, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, gUnk_0815AC2C, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#elif defined(VERSION_JP)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, gUnkJp_0814EBE0, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#elif defined(VERSION_EU)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, &gUnkEu_088901A8, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#endif
        72, 0x0, 7, {0, 0, 0}, 0x18, 525, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, gUnk_0815AC2C, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#elif defined(VERSION_JP)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, gUnkJp_0814EBE0, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#elif defined(VERSION_EU)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, &gUnkEu_088901A8, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#endif
        72, 0x0, 2, {0, 0, 0}, 0x18, 525, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, gUnk_0815AC2C, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#elif defined(VERSION_JP)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, gUnkJp_0814EBE0, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#elif defined(VERSION_EU)
        gUnk_0904DF74, gUnk_0904DF88, gUnk_08F69A84, &gUnkEu_088901A8, gUnk_090638FC, gUnk_09063910, gUnk_09613598,
#endif
        72, 0x0, 8, {0, 0, 0}, 0x18, 525, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904B9F8, gUnk_0904BA0C, gUnk_08F698A4, gUnk_0815ABAA, gUnk_090626A8, gUnk_090626BC, gUnk_09613378,
#elif defined(VERSION_JP)
        gUnk_0904B9F8, gUnk_0904BA0C, gUnk_08F698A4, gUnkJp_0814EB80, gUnk_090626A8, gUnk_090626BC, gUnk_09613378,
#elif defined(VERSION_EU)
        gUnk_0904B9F8, gUnk_0904BA0C, gUnk_08F698A4, &gUnkEu_08890020, gUnk_090626A8, gUnk_090626BC, gUnk_09613378,
#endif
        73, 0x0, 2, {0, 0, 0}, 0x2a, 528, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, gUnk_0815ABC8, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#elif defined(VERSION_JP)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, gUnkJp_0814EB98, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#elif defined(VERSION_EU)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, &gUnkEu_08890070, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#endif
        74, 0x0, 7, {0, 0, 0}, 0x25, 529, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, gUnk_0815ABC8, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#elif defined(VERSION_JP)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, gUnkJp_0814EB98, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#elif defined(VERSION_EU)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, &gUnkEu_08890070, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#endif
        74, 0x0, 7, {0, 0, 0}, 0x25, 529, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, gUnk_0815ABC8, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#elif defined(VERSION_JP)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, gUnkJp_0814EB98, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#elif defined(VERSION_EU)
        gUnk_0904BC0C, gUnk_0904BC20, gUnk_08F698E4, &gUnkEu_08890070, gUnk_090627BC, gUnk_090627D0, gUnk_09613398,
#endif
        74, 0x0, 7, {0, 0, 0}, 0x25, 529, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, gUnk_0815ABE2, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#elif defined(VERSION_JP)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, gUnkJp_0814EBAC, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#elif defined(VERSION_EU)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, &gUnkEu_088900CC, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#endif
        75, 0x0, 2, {0, 0, 0}, 0x14, 532, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, gUnk_0815ABE2, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#elif defined(VERSION_JP)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, gUnkJp_0814EBAC, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#elif defined(VERSION_EU)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, &gUnkEu_088900CC, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#endif
        75, 0x0, 4, {0, 0, 0}, 0x14, 532, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, gUnk_0815ABE2, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#elif defined(VERSION_JP)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, gUnkJp_0814EBAC, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#elif defined(VERSION_EU)
        gUnk_0904EE00, gUnk_0904EE14, gUnk_08F69B84, &gUnkEu_088900CC, gUnk_09064088, gUnk_0906409C, gUnk_09613678,
#endif
        75, 0x0, 6, {0, 0, 0}, 0x14, 532, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, gUnk_0815ABFE, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#elif defined(VERSION_JP)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, gUnkJp_0814EBC0, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#elif defined(VERSION_EU)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, &gUnkEu_08890118, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#endif
        76, 0x0, 2, {0, 0, 0}, 0xa, 535, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, gUnk_0815ABFE, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#elif defined(VERSION_JP)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, gUnkJp_0814EBC0, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#elif defined(VERSION_EU)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, &gUnkEu_08890118, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#endif
        76, 0x0, 4, {0, 0, 0}, 0xa, 535, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, gUnk_0815ABFE, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#elif defined(VERSION_JP)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, gUnkJp_0814EBC0, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#elif defined(VERSION_EU)
        gUnk_0904E9D8, gUnk_0904E9EC, gUnk_08F69B44, &gUnkEu_08890118, gUnk_09063E60, gUnk_09063E74, gUnk_09613638,
#endif
        76, 0x0, 6, {0, 0, 0}, 0xa, 535, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, gUnk_0815AC18, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#elif defined(VERSION_JP)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, gUnkJp_0814EBD4, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#elif defined(VERSION_EU)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, &gUnkEu_0889015C, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#endif
        77, 0x0, 2, {0, 0, 0}, 0x27, 538, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, gUnk_0815AC18, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#elif defined(VERSION_JP)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, gUnkJp_0814EBD4, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#elif defined(VERSION_EU)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, &gUnkEu_0889015C, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#endif
        77, 0x0, 4, {0, 0, 0}, 0x27, 538, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, gUnk_0815AC18, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#elif defined(VERSION_JP)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, gUnkJp_0814EBD4, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#elif defined(VERSION_EU)
        gUnk_0904EBEC, gUnk_0904EC00, gUnk_08F69B64, &gUnkEu_0889015C, gUnk_09063F74, gUnk_09063F88, gUnk_09613658,
#endif
        77, 0x0, 6, {0, 0, 0}, 0x27, 538, 3, 0, 20, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AC40, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814EBF0, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890200, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 1, {0, 0, 0}, 0x22, 575, 3, 0, 30, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815ACB0, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814EC3C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_088903AC, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 1, {0, 0, 0}, 0x29, 605, 3, 0, 60, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AC64, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814EC08, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890290, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 1, {0, 0, 0}, 0x30, 595, 3, 0, 25, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815ACFA, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814EC70, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890484, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 1, {0, 0, 0}, 0x2d, 565, 3, 0, 99, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, gUnk_0815C178, gUnk_09066530, gUnk_09066544, gUnk_09613DB8,
#elif defined(VERSION_JP)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, gUnkJp_0814FB0C, gUnk_09066530, gUnk_09066544, gUnk_09613DB8,
#elif defined(VERSION_EU)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, &gUnkEu_088959B8, gUnkEu_090F3F2C, gUnk_09066544, gUnk_09613DB8,
#endif
        82, 0x0, 2, {0, 0, 0}, 0x2c, 545, 3, 0, 55, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, gUnk_0815C178, gUnk_09066530, gUnk_09066544, gUnk_09613DB8,
#elif defined(VERSION_JP)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, gUnkJp_0814FB0C, gUnk_09066530, gUnk_09066544, gUnk_09613DB8,
#elif defined(VERSION_EU)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, &gUnkEu_088959B8, gUnkEu_090F3F2C, gUnk_09066544, gUnk_09613DB8,
#endif
        82, 0x0, 3, {0, 0, 0}, 0x2c, 545, 3, 0, 55, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, gUnk_0815C178, gUnk_09066530, gUnk_09066544, gUnk_09613DB8,
#elif defined(VERSION_JP)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, gUnkJp_0814FB0C, gUnk_09066530, gUnk_09066544, gUnk_09613DB8,
#elif defined(VERSION_EU)
        gUnk_09054F9C, gUnk_09054FB0, gUnk_09617C98, &gUnkEu_088959B8, gUnkEu_090F3F2C, gUnk_09066544, gUnk_09613DB8,
#endif
        82, 0x0, 3, {0, 0, 0}, 0x2c, 545, 3, 0, 55, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, gUnk_0815C178, gUnk_0906641C, gUnk_09066430, gUnk_09613D98,
#elif defined(VERSION_JP)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, gUnkJp_0814FB0C, gUnk_0906641C, gUnk_09066430, gUnk_09613D98,
#elif defined(VERSION_EU)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, &gUnkEu_088959B8, gUnkEu_090F3E18, gUnk_09066430, gUnk_09613D98,
#endif
        83, 0x0, 1, {0, 0, 0}, 0x2c, 548, 3, 0, 55, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, gUnk_0815C178, gUnk_0906641C, gUnk_09066430, gUnk_09613D98,
#elif defined(VERSION_JP)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, gUnkJp_0814FB0C, gUnk_0906641C, gUnk_09066430, gUnk_09613D98,
#elif defined(VERSION_EU)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, &gUnkEu_088959B8, gUnkEu_090F3E18, gUnk_09066430, gUnk_09613D98,
#endif
        83, 0x0, 4, {0, 0, 0}, 0x2c, 548, 3, 0, 55, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, gUnk_0815C178, gUnk_0906641C, gUnk_09066430, gUnk_09613D98,
#elif defined(VERSION_JP)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, gUnkJp_0814FB0C, gUnk_0906641C, gUnk_09066430, gUnk_09613D98,
#elif defined(VERSION_EU)
        gUnk_09054D88, gUnk_09054D9C, gUnk_09617CB8, &gUnkEu_088959B8, gUnkEu_090F3E18, gUnk_09066430, gUnk_09613D98,
#endif
        83, 0x0, 4, {0, 0, 0}, 0x2c, 548, 3, 0, 55, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126B8, gUnk_0815AC58, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613858,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126B8, gUnkJp_0814EC00, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613858,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126B8, &gUnkEu_08890230, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613858,
#endif
        84, 0x0, 9, {0, 0, 0}, 0x8, 551, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AC7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814EC1C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_088902C8, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 1, {0, 0, 0}, 0x2, 615, 3, 0, 65, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AC96, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814EC34, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890354, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 1, {0, 0, 0}, 0x17, 585, 3, 0, 40, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AC88, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814EC28, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890300, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 1, {0, 0, 0}, 0x2e, 625, 3, 0, 50, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612618, gUnk_0815ACCC, gUnk_09064B50, gUnk_09064B64, gUnk_096137B8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612618, gUnkJp_0814EC50, gUnk_09064B50, gUnk_09064B64, gUnk_096137B8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612618, &gUnkEu_088903E0, gUnk_09064B50, gUnk_09064B64, gUnk_096137B8,
#endif
        88, 0x0, 9, {0, 0, 0}, 0x1a, 555, 3, 0, 35, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815ACD6, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814EC58, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_0889043C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 1, {0, 0, 0}, 0x2b, 635, 3, 0, 70, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612758, gUnk_0815B0F2, gUnk_090650B4, gUnk_090650C8, gUnk_096138F8,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612758, gUnkJp_0814E924, gUnk_090650B4, gUnk_090650C8, gUnk_096138F8,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612758, &gUnkEu_0888F52C, gUnk_090652DC, gUnk_090650C8, gUnk_096138F8,
#endif
        90, 0x0, 9, {0, 0, 0}, 0xf, 557, 3, 0, 80, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_096127F8, gUnk_0815AD0C, gUnk_090651C8, gUnk_090651DC, gUnk_09613998,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_096127F8, gUnkJp_0814E9B8, gUnk_090651C8, gUnk_090651DC, gUnk_09613998,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_096127F8, &gUnkEu_0888F770, gUnk_09065840, gUnk_090651DC, gUnk_09613998,
#endif
        91, 0x0, 9, {0, 0, 0}, 0x12, 558, 3, 0, 75, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_09612898, gUnk_0815AD16, gUnk_090652DC, gUnk_090652F0, gUnk_09613A38,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_09612898, gUnkJp_0814E9AC, gUnk_090652DC, gUnk_090652F0, gUnk_09613A38,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_09612898, &gUnkEu_0888F740, gUnk_09065B7C, gUnk_090652F0, gUnk_09613A38,
#endif
        92, 0x0, 9, {0, 0, 0}, 0x32, 559, 3, 0, 60, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612938, gUnk_0815AD40, gUnk_090653F0, gUnk_09065404, gUnk_09613AD8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612938, gUnkJp_0814E9C4, gUnk_090653F0, gUnk_09065404, gUnk_09613AD8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612938, &gUnkEu_0888F7A4, gUnk_09065FCC, gUnk_09065404, gUnk_09613AD8,
#endif
        93, 0x0, 9, {0, 0, 0}, 0x1b, 560, 3, 0, 60, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129D8, gUnk_0815AD4C, gUnk_0906572C, gUnk_09065740, gUnk_09613B78,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129D8, gUnkJp_0814E9D0, gUnk_0906572C, gUnk_09065740, gUnk_09613B78,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129D8, &gUnkEu_0888F7E8, gUnk_09066308, gUnk_09065740, gUnk_09613B78,
#endif
        94, 0x0, 9, {0, 0, 0}, 0x2f, 561, 3, 0, 99, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD4C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814E9D0, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_0888F7E8, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 1, {0, 0, 0}, 0x2b, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A78, gUnk_0815AD9A, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C18,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A78, gUnkJp_0814EE88, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C18,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A78, &gUnkEu_08890F7C, gUnk_09066758, gUnk_09065B90, gUnk_09613C18,
#endif
        96, 0x0, 9, {0, 0, 0}, 0x31, 563, 3, 0, 99, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B18, gUnk_0815ADAA, gUnk_09065EB8, gUnk_09065ECC, gUnk_09613CB8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B18, gUnkJp_0814EE94, gUnk_09065EB8, gUnk_09065ECC, gUnk_09613CB8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B18, &gUnkEu_08890FB0, gUnk_09066A94, gUnk_09065ECC, gUnk_09613CB8,
#endif
        97, 0x0, 9, {0, 0, 0}, 0x1c, 564, 3, 0, 60, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 0, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 1, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 2, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 3, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 4, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 5, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 6, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 7, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 8, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnk_0815AD7C, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_JP)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, gUnkJp_0814ED74, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#elif defined(VERSION_EU)
        gUnk_0904F014, gUnk_0904F028, gUnk_096FB8A4, &gUnkEu_08890A18, gUnk_0906419C, gUnk_090641B0, gUnk_09613698,
#endif
        81, 0x0, 9, {0, 0, 0}, 0x0, 565, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 0, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 1, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 2, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 3, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 4, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 5, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 6, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 7, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 8, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnk_0815AD7C, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_JP)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, gUnkJp_0814ED74, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#elif defined(VERSION_EU)
        gUnk_0904F228, gUnk_0904F23C, gUnk_09A3C89C, &gUnkEu_08890A18, gUnk_090642B0, gUnk_090642C4, gUnk_096136B8,
#endif
        78, 0x0, 9, {0, 0, 0}, 0x0, 575, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 0, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 1, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 2, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 3, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 4, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 5, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 6, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 7, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 8, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnk_0815AD7C, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_JP)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, gUnkJp_0814ED74, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#elif defined(VERSION_EU)
        gUnk_0904F43C, gUnk_0904F450, gUnk_0984AF78, &gUnkEu_08890A18, gUnk_090643C4, gUnk_090643D8, gUnk_096136D8,
#endif
        86, 0x0, 9, {0, 0, 0}, 0x0, 585, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 0, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 1, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 2, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 3, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 4, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 5, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 6, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 7, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 8, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnk_0815AD7C, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_JP)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, gUnkJp_0814ED74, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#elif defined(VERSION_EU)
        gUnk_0904F650, gUnk_0904F664, gUnk_096FB2A4, &gUnkEu_08890A18, gUnk_090644D8, gUnk_090644EC, gUnk_096136F8,
#endif
        80, 0x0, 9, {0, 0, 0}, 0x0, 595, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 0, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 1, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 2, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 3, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 4, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 5, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 6, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 7, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 8, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnk_0815AD7C, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_JP)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, gUnkJp_0814ED74, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#elif defined(VERSION_EU)
        gUnk_0904F864, gUnk_0904F878, gUnk_09D69274, &gUnkEu_08890A18, gUnk_090645EC, gUnk_09064600, gUnk_09613718,
#endif
        79, 0x0, 9, {0, 0, 0}, 0x0, 605, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 0, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 1, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 2, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 3, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 4, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 5, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 6, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 7, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 8, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnk_0815AD7C, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_JP)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, gUnkJp_0814ED74, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#elif defined(VERSION_EU)
        gUnk_0904FA78, gUnk_0904FA8C, gUnk_09612598, &gUnkEu_08890A18, gUnk_09064700, gUnk_09064714, gUnk_09613738,
#endif
        85, 0x0, 9, {0, 0, 0}, 0x0, 615, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 0, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 1, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 2, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 3, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 4, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 5, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 6, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 7, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 8, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnk_0815AD7C, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_JP)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, gUnkJp_0814ED74, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#elif defined(VERSION_EU)
        gUnk_0904FC8C, gUnk_0904FCA0, gUnk_096125B8, &gUnkEu_08890A18, gUnk_09064814, gUnk_09064828, gUnk_09613758,
#endif
        87, 0x0, 9, {0, 0, 0}, 0x0, 625, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 0, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 1, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 2, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 3, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 4, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 5, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 6, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 7, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 8, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnk_0815AD7C, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_JP)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, gUnkJp_0814ED74, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#elif defined(VERSION_EU)
        gUnk_0904FEA0, gUnk_0904FEB4, gUnk_096125D8, &gUnkEu_08890A18, gUnk_09064928, gUnk_0906493C, gUnk_09613778,
#endif
        89, 0x0, 9, {0, 0, 0}, 0x0, 635, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 0, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 1, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 2, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 3, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 4, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 5, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 6, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 7, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 8, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnk_0815AD7C, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_JP)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, gUnkJp_0814ED74, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#elif defined(VERSION_EU)
        gUnk_090500B4, gUnk_090500CA, gUnk_096125F8, &gUnkEu_08890A18, gUnk_09064A3C, gUnk_09064A50, gUnk_09613798,
#endif
        95, 0x0, 9, {0, 0, 0}, 0x0, 645, 3, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnk_0815AD7C, NULL, NULL, NULL,
#elif defined(VERSION_JP)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnkJp_0814ED74, NULL, NULL, NULL,
#elif defined(VERSION_EU)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, &gUnkEu_08890A18, NULL, NULL, NULL,
#endif
        98, 0x10, 0, {0, 0, 0}, 0x8c, 655, 2, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnk_0815AD7C, NULL, NULL, NULL,
#elif defined(VERSION_JP)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnkJp_0814ED74, NULL, NULL, NULL,
#elif defined(VERSION_EU)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, &gUnkEu_08890A18, NULL, NULL, NULL,
#endif
        99, 0x10, 0, {0, 0, 0}, 0x8d, 656, 2, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnk_0815AD7C, NULL, NULL, NULL,
#elif defined(VERSION_JP)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnkJp_0814ED74, NULL, NULL, NULL,
#elif defined(VERSION_EU)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, &gUnkEu_08890A18, NULL, NULL, NULL,
#endif
        100, 0x10, 0, {0, 0, 0}, 0x8e, 657, 2, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnk_0815AD7C, NULL, NULL, NULL,
#elif defined(VERSION_JP)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnkJp_0814ED74, NULL, NULL, NULL,
#elif defined(VERSION_EU)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, &gUnkEu_08890A18, NULL, NULL, NULL,
#endif
        101, 0x10, 0, {0, 0, 0}, 0x8f, 658, 2, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnk_0815AD7C, NULL, NULL, NULL,
#elif defined(VERSION_JP)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, gUnkJp_0814ED74, NULL, NULL, NULL,
#elif defined(VERSION_EU)
        gUnk_09054110, gUnk_09054124, gUnk_09612BB8, &gUnkEu_08890A18, NULL, NULL, NULL,
#endif
        102, 0x10, 0, {0, 0, 0}, 0x90, 659, 2, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 0, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 1, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 2, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 3, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 4, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 5, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 6, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 7, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 8, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnk_0815C372, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_JP)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, gUnkJp_0814EEA8, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#elif defined(VERSION_EU)
        gUnk_09053EFC, gUnk_09053F10, gUnk_09612098, &gUnkEu_0889103C, gUnk_09060310, gUnk_09060324, gUnk_09612E58,
#endif
        17, 0x0, 9, {0, 0, 0}, 0x12, 661, 0, 0, 0, {5, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 0, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 1, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 2, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 3, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 4, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 5, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 6, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 7, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 8, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnk_0815C360, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_JP)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, gUnkJp_0814EEA0, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#elif defined(VERSION_EU)
        gUnk_09049C60, gUnk_09049C74, gUnk_096183F8, &gUnkEu_08890FEC, gUnk_09062258, gUnk_0906226C, gUnk_09613298,
#endif
        46, 0x8, 9, {0, 0, 0}, 0x2d, 671, 2, 0, 0, {3, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 0, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 1, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 2, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 3, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 4, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 5, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 6, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 7, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 8, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DD8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613158,
#endif
        131, 0x0, 9, {0, 0, 0}, 0x24, 681, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 0, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 1, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 2, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 3, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 4, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 5, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 6, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 7, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 8, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnk_0815AD7C, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_JP)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, gUnkJp_0814ED74, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#elif defined(VERSION_EU)
        gUnk_09048FE8, gUnk_09048FFC, gUnk_09611DF8, &gUnkEu_08890A18, gUnk_09061BDC, gUnk_09061BF2, gUnk_09613178,
#endif
        132, 0x0, 9, {0, 0, 0}, 0x25, 691, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 0, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 1, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 2, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 3, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 4, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 5, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 6, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 7, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 8, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnk_0815AD7C, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, gUnkJp_0814ED74, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612638, &gUnkEu_08890A18, gUnk_09064C64, gUnk_09064C78, gUnk_096137D8,
#endif
        103, 0x0, 9, {0, 0, 0}, 0x24, 701, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 0, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 1, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 2, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 3, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 4, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 5, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 6, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 7, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 8, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnk_0815AD7C, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, gUnkJp_0814ED74, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612658, &gUnkEu_08890A18, gUnk_09064D78, gUnk_09064D8C, gUnk_096137D8,
#endif
        104, 0x0, 9, {0, 0, 0}, 0x25, 711, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 0, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 1, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 2, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 3, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 4, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 5, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 6, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 7, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 8, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnk_0815AD7C, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, gUnkJp_0814ED74, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612678, &gUnkEu_08890A18, gUnk_09064E8C, gUnk_09064EA0, gUnk_096137D8,
#endif
        105, 0x0, 9, {0, 0, 0}, 0x26, 721, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 0, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 1, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 2, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 3, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 4, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 5, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 6, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 7, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 8, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnk_0815AD7C, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_JP)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, gUnkJp_0814ED74, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#elif defined(VERSION_EU)
        gUnk_090502CC, gUnk_090502E0, gUnk_09612698, &gUnkEu_08890A18, gUnk_09064B50, gUnk_09064B64, gUnk_096137D8,
#endif
        106, 0x0, 9, {0, 0, 0}, 0x27, 731, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 0, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 1, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 2, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 3, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 4, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 5, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 6, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 7, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 8, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613878,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126D8, &gUnkEu_08890A18, gUnk_090650B4, gUnkEu_090F1EE8, gUnk_09613878,
#endif
        107, 0x0, 9, {0, 0, 0}, 0x24, 741, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 0, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 1, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 2, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 3, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 4, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 5, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 6, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 7, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 8, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnk_0815AD7C, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_JP)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, gUnkJp_0814ED74, gUnk_09064FA0, gUnk_09064FB4, gUnk_09613898,
#elif defined(VERSION_EU)
        gUnk_090504E0, gUnk_090504F4, gUnk_096126F8, &gUnkEu_08890A18, gUnk_090651C8, gUnkEu_090F1FFC, gUnk_09613878,
#endif
        108, 0x0, 9, {0, 0, 0}, 0x25, 751, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 0, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 1, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 2, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 3, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 4, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 5, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 6, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 7, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 8, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613918,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612778, &gUnkEu_08890A18, gUnk_090653F0, gUnkEu_090F2224, gUnk_09613918,
#endif
        111, 0x0, 9, {0, 0, 0}, 0x24, 761, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 0, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 1, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 2, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 3, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 4, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 5, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 6, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 7, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 8, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613938,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_09612798, &gUnkEu_08890A18, gUnk_09065504, gUnkEu_090F2338, gUnk_09613918,
#endif
        112, 0x0, 9, {0, 0, 0}, 0x25, 771, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 0, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 1, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 2, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 3, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 4, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 5, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 6, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 7, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 8, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613958,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127B8, &gUnkEu_08890A18, gUnk_09065618, gUnkEu_090F244C, gUnk_09613918,
#endif
        113, 0x0, 9, {0, 0, 0}, 0x26, 781, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 0, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 1, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 2, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 3, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 4, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 5, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 6, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 7, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 8, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnk_0815AD7C, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_JP)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, gUnkJp_0814ED74, gUnk_090650B4, gUnk_090650C8, gUnk_09613978,
#elif defined(VERSION_EU)
        gUnk_090506F4, gUnk_09050708, gUnk_096127D8, &gUnkEu_08890A18, gUnk_0906572C, gUnkEu_090F2560, gUnk_09613918,
#endif
        114, 0x0, 9, {0, 0, 0}, 0x27, 791, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 0, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 1, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 2, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 3, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 4, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 5, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 6, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 7, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 8, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139B8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612818, &gUnkEu_08890A18, gUnk_09065954, gUnkEu_090F2788, gUnk_096139B8,
#endif
        115, 0x0, 9, {0, 0, 0}, 0x24, 801, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 0, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 1, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 2, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 3, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 4, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 5, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 6, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 7, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 8, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnk_0815AD7C, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_JP)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, gUnkJp_0814ED74, gUnk_090651C8, gUnk_090651DC, gUnk_096139D8,
#elif defined(VERSION_EU)
        gUnk_09050908, gUnk_0905091C, gUnk_09612838, &gUnkEu_08890A18, gUnk_09065A68, gUnkEu_090F289C, gUnk_096139B8,
#endif
        116, 0x0, 9, {0, 0, 0}, 0x25, 811, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 0, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 1, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 2, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 3, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 4, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 5, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 6, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 7, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 8, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A58,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128B8, &gUnkEu_08890A18, gUnk_09065C90, gUnkEu_090F2AC4, gUnk_09613A58,
#endif
        119, 0x0, 9, {0, 0, 0}, 0x24, 821, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 0, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 1, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 2, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 3, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 4, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 5, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 6, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 7, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 8, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A78,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128D8, &gUnkEu_08890A18, gUnk_09065DA4, gUnkEu_090F2BD8, gUnk_09613A58,
#endif
        120, 0x0, 9, {0, 0, 0}, 0x25, 831, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 0, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 1, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 2, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 3, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 4, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 5, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 6, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 7, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 8, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnk_0815AD7C, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_JP)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, gUnkJp_0814ED74, gUnk_090652DC, gUnk_090652F0, gUnk_09613A98,
#elif defined(VERSION_EU)
        gUnk_09050B1C, gUnk_09050B30, gUnk_096128F8, &gUnkEu_08890A18, gUnk_09065EB8, gUnkEu_090F2CEC, gUnk_09613A58,
#endif
        121, 0x0, 9, {0, 0, 0}, 0x26, 841, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 0, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 1, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 2, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 3, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 4, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 5, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 6, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 7, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 8, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnk_0815AD7C, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, gUnkJp_0814ED74, gUnk_09065504, gUnk_09065518, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612958, &gUnkEu_08890A18, gUnk_090660E0, gUnk_09065518, gUnk_09613AF8,
#endif
        123, 0x0, 9, {0, 0, 0}, 0x24, 851, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 0, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 1, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 2, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 3, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 4, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 5, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 6, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 7, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 8, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnk_0815AD7C, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_JP)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, gUnkJp_0814ED74, gUnk_09065618, gUnk_0906562C, gUnk_09613AF8,
#elif defined(VERSION_EU)
        gUnk_09050D30, gUnk_09050D44, gUnk_09612978, &gUnkEu_08890A18, gUnk_090661F4, gUnk_0906562C, gUnk_09613AF8,
#endif
        124, 0x0, 9, {0, 0, 0}, 0x25, 861, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 0, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 1, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 2, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 3, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 4, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 5, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 6, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 7, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 8, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnk_0815AD7C, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, gUnkJp_0814ED74, gUnk_09065840, gUnk_09065854, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_096129F8, &gUnkEu_08890A18, gUnk_0906641C, gUnk_09065854, gUnk_09613B98,
#endif
        127, 0x0, 9, {0, 0, 0}, 0x24, 871, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 0, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 1, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 2, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 3, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 4, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 5, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 6, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 7, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 8, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnk_0815AD7C, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, gUnkJp_0814ED74, gUnk_09065954, gUnk_09065968, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A18, &gUnkEu_08890A18, gUnk_09066530, gUnk_09065968, gUnk_09613B98,
#endif
        128, 0x0, 9, {0, 0, 0}, 0x25, 881, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 0, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 1, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 2, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 3, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 4, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 5, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 6, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 7, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 8, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnk_0815AD7C, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_JP)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, gUnkJp_0814ED74, gUnk_09065A68, gUnk_09065A7C, gUnk_09613B98,
#elif defined(VERSION_EU)
        gUnk_09050F44, gUnk_09050F58, gUnk_09612A38, &gUnkEu_08890A18, gUnk_09066644, gUnk_09065A7C, gUnk_09613B98,
#endif
        129, 0x0, 9, {0, 0, 0}, 0x26, 891, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 0, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 1, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 2, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 3, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 4, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 5, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 6, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 7, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 8, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnk_0815AD7C, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, gUnkJp_0814ED74, gUnk_09065C90, gUnk_09065CA4, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612A98, &gUnkEu_08890A18, gUnk_0906686C, gUnk_09065CA4, gUnk_09613C38,
#endif
        139, 0x0, 9, {0, 0, 0}, 0x24, 901, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 0, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 1, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 2, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 3, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 4, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 5, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 6, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 7, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 8, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnk_0815AD7C, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, gUnkJp_0814ED74, gUnk_09065DA4, gUnk_09065DB8, gUnk_09613C38,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AB8, &gUnkEu_08890A18, gUnk_09066980, gUnk_09065DB8, gUnk_09613C38,
#endif
        140, 0x0, 9, {0, 0, 0}, 0x25, 911, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 0, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 1, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 2, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 3, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 4, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 5, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 6, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 7, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 8, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnk_0815AD7C, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_JP)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, gUnkJp_0814ED74, gUnk_09065B7C, gUnk_09065B90, gUnk_09613C78,
#elif defined(VERSION_EU)
        gUnk_09051158, gUnk_0905116C, gUnk_09612AD8, &gUnkEu_08890A18, gUnk_09066758, gUnk_09065B90, gUnk_09613C78,
#endif
        141, 0x0, 9, {0, 0, 0}, 0x26, 921, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 0, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 1, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 2, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 3, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 4, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 5, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 6, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 7, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 8, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnk_0815AD7C, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, gUnkJp_0814ED74, gUnk_09065FCC, gUnk_09065FE0, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B38, &gUnkEu_08890A18, gUnk_09066BA8, gUnk_09065FE0, gUnk_09613CD8,
#endif
        135, 0x0, 9, {0, 0, 0}, 0x24, 931, 1, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 0, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 1, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 2, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 3, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 4, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 5, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 6, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 7, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 8, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
    {
#if defined(VERSION_US)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnk_0815AD7C, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_JP)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, gUnkJp_0814ED74, gUnk_090660E0, gUnk_090660F4, gUnk_09613CD8,
#elif defined(VERSION_EU)
        gUnk_0905136C, gUnk_09051380, gUnk_09612B58, &gUnkEu_08890A18, gUnkEu_090F3ADC, gUnk_090660F4, gUnk_09613CD8,
#endif
        136, 0x0, 9, {0, 0, 0}, 0x25, 941, 0, 0, 0, {0, 0, 0, 0, 0, 0},
    },
};

const UnkStruct_08F7CBA8 gUnk_08F7CBA8[55] = {
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        0,
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        0,
        2,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        33,
#elif defined(VERSION_JP)
        1,
#elif defined(VERSION_US)
        33,
#endif
        20,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        1,
#elif defined(VERSION_JP)
        2,
#elif defined(VERSION_US)
        1,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        9,
#elif defined(VERSION_JP)
        3,
#elif defined(VERSION_US)
        9,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        7,
#elif defined(VERSION_JP)
        4,
#elif defined(VERSION_US)
        7,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        3,
#elif defined(VERSION_JP)
        5,
#elif defined(VERSION_US)
        3,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        22,
#elif defined(VERSION_JP)
        6,
#elif defined(VERSION_US)
        22,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        32,
#elif defined(VERSION_JP)
        7,
#elif defined(VERSION_US)
        32,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        30,
#elif defined(VERSION_JP)
        8,
#elif defined(VERSION_US)
        30,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        28,
#elif defined(VERSION_JP)
        9,
#elif defined(VERSION_US)
        28,
#endif
#ifdef VERSION_EU
        1,
#else
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        10,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        11,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        12,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        24,
#elif defined(VERSION_JP)
        13,
#elif defined(VERSION_US)
        24,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        43,
#elif defined(VERSION_JP)
        14,
#elif defined(VERSION_US)
        43,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        6,
#elif defined(VERSION_JP)
        15,
#elif defined(VERSION_US)
        6,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        8,
#elif defined(VERSION_JP)
        16,
#elif defined(VERSION_US)
        8,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        41,
#elif defined(VERSION_JP)
        17,
#elif defined(VERSION_US)
        41,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        16,
#elif defined(VERSION_JP)
        18,
#elif defined(VERSION_US)
        16,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        20,
#elif defined(VERSION_JP)
        19,
#elif defined(VERSION_US)
        20,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        21,
#elif defined(VERSION_JP)
        20,
#elif defined(VERSION_US)
        21,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        21,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        36,
#elif defined(VERSION_JP)
        22,
#elif defined(VERSION_US)
        36,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        15,
#elif defined(VERSION_JP)
        23,
#elif defined(VERSION_US)
        15,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        23,
#elif defined(VERSION_JP)
        24,
#elif defined(VERSION_US)
        23,
#endif
#ifdef VERSION_EU
        3,
#else
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        38,
#elif defined(VERSION_JP)
        25,
#elif defined(VERSION_US)
        38,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        44,
#elif defined(VERSION_JP)
        26,
#elif defined(VERSION_US)
        44,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        42,
#elif defined(VERSION_JP)
        27,
#elif defined(VERSION_US)
        42,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        17,
#elif defined(VERSION_JP)
        28,
#elif defined(VERSION_US)
        17,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        27,
#elif defined(VERSION_JP)
        29,
#elif defined(VERSION_US)
        27,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        2,
#elif defined(VERSION_JP)
        30,
#elif defined(VERSION_US)
        2,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        31,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        32,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        31,
#elif defined(VERSION_JP)
        33,
#elif defined(VERSION_US)
        31,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        19,
#elif defined(VERSION_JP)
        34,
#elif defined(VERSION_US)
        19,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        35,
#elif defined(VERSION_US)
        4,
#endif
        2,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        26,
#elif defined(VERSION_JP)
        36,
#elif defined(VERSION_US)
        26,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        14,
#elif defined(VERSION_JP)
        37,
#elif defined(VERSION_US)
        14,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        13,
#elif defined(VERSION_JP)
        38,
#elif defined(VERSION_US)
        13,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        29,
#elif defined(VERSION_JP)
        39,
#elif defined(VERSION_US)
        29,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        37,
#elif defined(VERSION_JP)
        40,
#elif defined(VERSION_US)
        37,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        25,
#elif defined(VERSION_JP)
        41,
#elif defined(VERSION_US)
        25,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        39,
#elif defined(VERSION_JP)
        42,
#elif defined(VERSION_US)
        39,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        40,
#elif defined(VERSION_JP)
        43,
#elif defined(VERSION_US)
        40,
#endif
        30,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        34,
#elif defined(VERSION_JP)
        44,
#elif defined(VERSION_US)
        34,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        35,
#elif defined(VERSION_JP)
        45,
#elif defined(VERSION_US)
        35,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        45,
#elif defined(VERSION_JP)
        46,
#elif defined(VERSION_US)
        45,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        46,
#elif defined(VERSION_JP)
        47,
#elif defined(VERSION_US)
        46,
#endif
        10,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        48,
        50,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        47,
#elif defined(VERSION_JP)
        49,
#elif defined(VERSION_US)
        47,
#endif
        15,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        5,
#elif defined(VERSION_JP)
        50,
#elif defined(VERSION_US)
        5,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        34,
#elif defined(VERSION_JP)
        51,
#elif defined(VERSION_US)
        34,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
#if defined(VERSION_EU)
        18,
#elif defined(VERSION_JP)
        52,
#elif defined(VERSION_US)
        18,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D574,
#else
        gUnk_09079EB2,
#endif
#ifndef VERSION_EU
#if defined(VERSION_JP)
        28032,
#elif defined(VERSION_US)
        24704,
#endif
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D588,
#elif defined(VERSION_JP)
        gUnkJp_09EC12D4,
#elif defined(VERSION_US)
        gUnkUs_09EE9EF8,
#endif
        0,
        1,
    },
};

const SpriteFrameResourceDef gUnk_08F7CF18[106] = {
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#ifdef VERSION_EU
        640,
#else
        384,
#endif
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        2,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        576,
#endif
        4,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#ifdef VERSION_EU
        640,
#else
        384,
#endif
#if defined(VERSION_EU)
        6,
#elif defined(VERSION_JP)
        10,
#elif defined(VERSION_US)
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        10,
#elif defined(VERSION_JP)
        6,
#elif defined(VERSION_US)
        10,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        1,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        576,
#elif defined(VERSION_US)
        640,
#endif
#if defined(VERSION_EU)
        3,
#elif defined(VERSION_JP)
        1,
#elif defined(VERSION_US)
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        448,
#endif
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        576,
#endif
        5,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
#if defined(VERSION_EU)
        7,
#elif defined(VERSION_JP)
        11,
#elif defined(VERSION_US)
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        8,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        512,
#endif
        9,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        11,
#elif defined(VERSION_JP)
        7,
#elif defined(VERSION_US)
        11,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
        2,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        640,
#endif
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        384,
#elif defined(VERSION_US)
        640,
#endif
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        512,
#elif defined(VERSION_US)
        640,
#endif
#if defined(VERSION_EU)
        14,
#elif defined(VERSION_JP)
        12,
#elif defined(VERSION_US)
        14,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        512,
#elif defined(VERSION_US)
        640,
#endif
#if defined(VERSION_EU)
        14,
#elif defined(VERSION_JP)
        12,
#elif defined(VERSION_US)
        14,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        704,
#elif defined(VERSION_US)
        512,
#endif
#if defined(VERSION_EU)
        15,
#elif defined(VERSION_JP)
        17,
#elif defined(VERSION_US)
        15,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        704,
#elif defined(VERSION_US)
        512,
#endif
#if defined(VERSION_EU)
        15,
#elif defined(VERSION_JP)
        17,
#elif defined(VERSION_US)
        15,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        20,
#elif defined(VERSION_JP)
        19,
#elif defined(VERSION_US)
        20,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        20,
#elif defined(VERSION_JP)
        19,
#elif defined(VERSION_US)
        20,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        21,
#elif defined(VERSION_JP)
        20,
#elif defined(VERSION_US)
        21,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        21,
#elif defined(VERSION_JP)
        20,
#elif defined(VERSION_US)
        21,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        16,
#elif defined(VERSION_JP)
        42,
#elif defined(VERSION_US)
        16,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        16,
#elif defined(VERSION_JP)
        42,
#elif defined(VERSION_US)
        16,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        17,
#elif defined(VERSION_JP)
        18,
#elif defined(VERSION_US)
        17,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        17,
#elif defined(VERSION_JP)
        18,
#elif defined(VERSION_US)
        17,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        576,
#endif
#if defined(VERSION_EU)
        19,
#elif defined(VERSION_JP)
        16,
#elif defined(VERSION_US)
        19,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        18,
#elif defined(VERSION_JP)
        15,
#elif defined(VERSION_US)
        18,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        3,
#elif defined(VERSION_JP)
        6,
#elif defined(VERSION_US)
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        3,
#elif defined(VERSION_JP)
        6,
#elif defined(VERSION_US)
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        5,
#elif defined(VERSION_JP)
        3,
#elif defined(VERSION_US)
        5,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        5,
#elif defined(VERSION_JP)
        3,
#elif defined(VERSION_US)
        5,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        7,
#elif defined(VERSION_US)
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        7,
#elif defined(VERSION_US)
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        6,
#elif defined(VERSION_JP)
        5,
#elif defined(VERSION_US)
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        6,
#elif defined(VERSION_JP)
        5,
#elif defined(VERSION_US)
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        7,
#elif defined(VERSION_JP)
        4,
#elif defined(VERSION_US)
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5EC,
#else
        gUnk_09086C1C,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D600,
#elif defined(VERSION_JP)
        gUnkJp_09EC14A4,
#elif defined(VERSION_US)
        gUnkUs_09EEA0B0,
#endif
        640,
#if defined(VERSION_EU)
        7,
#elif defined(VERSION_JP)
        4,
#elif defined(VERSION_US)
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D614,
#else
        gUnk_0908AF32,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D628,
#elif defined(VERSION_JP)
        gUnkJp_09EC1534,
#elif defined(VERSION_US)
        gUnkUs_09EEA140,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D614,
#else
        gUnk_0908AF32,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D628,
#elif defined(VERSION_JP)
        gUnkJp_09EC1534,
#elif defined(VERSION_US)
        gUnkUs_09EEA140,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        512,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        12,
#elif defined(VERSION_JP)
        13,
#elif defined(VERSION_US)
        12,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        512,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        13,
#elif defined(VERSION_JP)
        14,
#elif defined(VERSION_US)
        13,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        0,
#elif defined(VERSION_JP)
        8,
#elif defined(VERSION_US)
        0,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        2,
#elif defined(VERSION_JP)
        5,
#elif defined(VERSION_US)
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        576,
#elif defined(VERSION_US)
        640,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        2,
#elif defined(VERSION_US)
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        5,
#elif defined(VERSION_JP)
        7,
#elif defined(VERSION_US)
        5,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        6,
#elif defined(VERSION_JP)
        4,
#elif defined(VERSION_US)
        6,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        7,
#elif defined(VERSION_JP)
        6,
#elif defined(VERSION_US)
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
#if defined(VERSION_EU)
        8,
#elif defined(VERSION_JP)
        3,
#elif defined(VERSION_US)
        8,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        384,
#endif
#if defined(VERSION_EU)
        22,
#elif defined(VERSION_JP)
        21,
#elif defined(VERSION_US)
        22,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
#if defined(VERSION_EU)
        23,
#elif defined(VERSION_JP)
        22,
#elif defined(VERSION_US)
        23,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        448,
#endif
#if defined(VERSION_EU)
        24,
#elif defined(VERSION_JP)
        23,
#elif defined(VERSION_US)
        24,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        512,
#endif
#if defined(VERSION_EU)
        25,
#elif defined(VERSION_JP)
        24,
#elif defined(VERSION_US)
        25,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        25,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        9,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        10,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        11,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        12,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        13,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        14,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D59C,
#else
        gUnk_09080074,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5B0,
#elif defined(VERSION_JP)
        gUnkJp_09EC13AC,
#elif defined(VERSION_US)
        gUnkUs_09EE9FC0,
#endif
        640,
        15,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        26,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        448,
#endif
        27,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        28,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        29,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        30,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        31,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        32,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        33,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        34,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        640,
        35,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
        704,
        36,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        512,
#endif
        37,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        320,
#endif
        38,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        512,
#endif
        39,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        448,
#endif
        40,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D5C4,
#else
        gUnk_090822F2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D5D8,
#elif defined(VERSION_JP)
        gUnkJp_09EC13F4,
#elif defined(VERSION_US)
        gUnkUs_09EEA004,
#endif
#if defined(VERSION_EU)
        640,
#elif defined(VERSION_JP)
        640,
#elif defined(VERSION_US)
        512,
#endif
        41,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D63C,
#else
        gUnk_0908A958,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D650,
#elif defined(VERSION_JP)
        gUnkJp_09EC1524,
#elif defined(VERSION_US)
        gUnkUs_09EEA130,
#endif
        640,
#if defined(VERSION_EU)
        2,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D63C,
#else
        gUnk_0908A958,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D650,
#elif defined(VERSION_JP)
        gUnkJp_09EC1524,
#elif defined(VERSION_US)
        gUnkUs_09EEA130,
#endif
        640,
#if defined(VERSION_EU)
        0,
#elif defined(VERSION_JP)
        1,
#elif defined(VERSION_US)
        0,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D63C,
#else
        gUnk_0908A958,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D650,
#elif defined(VERSION_JP)
        gUnkJp_09EC1524,
#elif defined(VERSION_US)
        gUnkUs_09EEA130,
#endif
        640,
#if defined(VERSION_EU)
        1,
#elif defined(VERSION_JP)
        2,
#elif defined(VERSION_US)
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D68C,
#else
        gUnk_09089C16,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D6A0,
#elif defined(VERSION_JP)
        gUnkJp_09EC1508,
#elif defined(VERSION_US)
        gUnkUs_09EEA114,
#endif
        640,
        0,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D68C,
#else
        gUnk_09089C16,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D6A0,
#elif defined(VERSION_JP)
        gUnkJp_09EC1508,
#elif defined(VERSION_US)
        gUnkUs_09EEA114,
#endif
        640,
        1,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D68C,
#else
        gUnk_09089C16,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D6A0,
#elif defined(VERSION_JP)
        gUnkJp_09EC1508,
#elif defined(VERSION_US)
        gUnkUs_09EEA114,
#endif
        640,
        2,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D68C,
#else
        gUnk_09089C16,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D6A0,
#elif defined(VERSION_JP)
        gUnkJp_09EC1508,
#elif defined(VERSION_US)
        gUnkUs_09EEA114,
#endif
        640,
        3,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        2,
#elif defined(VERSION_JP)
        1,
#elif defined(VERSION_US)
        2,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D68C,
#else
        gUnk_09089C16,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D6A0,
#elif defined(VERSION_JP)
        gUnkJp_09EC1508,
#elif defined(VERSION_US)
        gUnkUs_09EEA114,
#endif
        640,
        4,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D68C,
#else
        gUnk_09089C16,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D6A0,
#elif defined(VERSION_JP)
        gUnkJp_09EC1508,
#elif defined(VERSION_US)
        gUnkUs_09EEA114,
#endif
        640,
        5,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        10,
#elif defined(VERSION_JP)
        2,
#elif defined(VERSION_US)
        10,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        3,
#elif defined(VERSION_US)
        4,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        7,
#elif defined(VERSION_JP)
        4,
#elif defined(VERSION_US)
        7,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
        5,
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        11,
#elif defined(VERSION_JP)
        6,
#elif defined(VERSION_US)
        11,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        3,
#elif defined(VERSION_JP)
        7,
#elif defined(VERSION_US)
        3,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        1,
#elif defined(VERSION_JP)
        8,
#elif defined(VERSION_US)
        1,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        8,
#elif defined(VERSION_JP)
        9,
#elif defined(VERSION_US)
        8,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        9,
#elif defined(VERSION_JP)
        10,
#elif defined(VERSION_US)
        9,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#ifdef VERSION_EU
        13,
#else
        12,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        14,
#elif defined(VERSION_JP)
        13,
#elif defined(VERSION_US)
        14,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        12,
#elif defined(VERSION_JP)
        11,
#elif defined(VERSION_US)
        12,
#endif
    },
    {
#ifdef VERSION_EU
        gUnkEu_09F5D664,
#else
        gUnk_09087DD2,
#endif
#if defined(VERSION_EU)
        gUnkEu_09F5D678,
#elif defined(VERSION_JP)
        gUnkJp_09EC14C8,
#elif defined(VERSION_US)
        gUnkUs_09EEA0D4,
#endif
        640,
#if defined(VERSION_EU)
        6,
#elif defined(VERSION_JP)
        14,
#elif defined(VERSION_US)
        6,
#endif
    },
};

#ifdef VERSION_EU
void* gUnkEu_09F5D574[5] = { gUnk_09079EB2, gUnkEu_0910DD2E, gUnkEu_09121002, gUnkEu_0911AB16, gUnkEu_09114860 };
void** gUnkEu_09F5D588[5] = { gUnkEu_09F753D0, gUnkEu_09F75498, gUnkEu_09F756F0, gUnkEu_09F75628, gUnkEu_09F75560 };
void* gUnkEu_09F5D59C[5] = { gUnk_09080074, gUnkEu_091292D6, gUnkEu_0912F83E, gUnkEu_0912D736, gUnkEu_0912B47C };
void** gUnkEu_09F5D5B0[5] = { gUnkEu_09F757B8, gUnkEu_09F757FC, gUnkEu_09F758C8, gUnkEu_09F75884, gUnkEu_09F75840 };
void* gUnkEu_09F5D5C4[5] = { gUnk_090822F2, gUnkEu_091367CC, gUnkEu_0914583A, gUnkEu_091407A2, gUnkEu_0913B7F4 };
void** gUnkEu_09F5D5D8[5] = { gUnkEu_09F7590C, gUnkEu_09F759B8, gUnkEu_09F75BBC, gUnkEu_09F75B10, gUnkEu_09F75A64 };
void* gUnkEu_09F5D5EC[5] = { gUnk_09086C1C, gUnkEu_0914B41E, gUnkEu_0914E89E, gUnkEu_0914D7B0, gUnkEu_0914C648 };
void** gUnkEu_09F5D600[5] = { gUnkEu_09F75C68, gUnkEu_09F75C8C, gUnkEu_09F75CF8, gUnkEu_09F75CD4, gUnkEu_09F75CB0 };
void* gUnkEu_09F5D614[5] = { gUnkEu_09160A0E, gUnkEu_09160C2A, gUnk_0908AF32, gUnk_0908A958, gUnkEu_09160E46 };
void** gUnkEu_09F5D628[5] = { gUnkEu_09F75F38, gUnkEu_09F75F40, gUnkEu_09F75F58, gUnkEu_09F75F50, gUnkEu_09F75F48 };
void* gUnkEu_09F5D63C[5] = { gUnkEu_0915E7D4, gUnkEu_0915EDDA, gUnkEu_091602F4, gUnkEu_0915FC28, gUnkEu_0915F468 };
void** gUnkEu_09F5D650[5] = { gUnkEu_09F75EE8, gUnkEu_09F75EF8, gUnkEu_09F75F28, gUnkEu_09F75F18, gUnkEu_09F75F08 };
void* gUnkEu_09F5D664[5] = { gUnk_09087DD2, gUnkEu_091519CE, gUnkEu_091581F6, gUnkEu_09155EFE, gUnkEu_09153BC6 };
void** gUnkEu_09F5D678[5] = { gUnkEu_09F75D1C, gUnkEu_09F75D5C, gUnkEu_09F75E1C, gUnkEu_09F75DDC, gUnkEu_09F75D9C };
void* gUnkEu_09F5D68C[5] = { gUnk_09089C16, gUnkEu_0915B004, gUnkEu_0915DAD4, gUnkEu_0915CC96, gUnkEu_0915BE46 };
void** gUnkEu_09F5D6A0[5] = { gUnkEu_09F75E5C, gUnkEu_09F75E78, gUnkEu_09F75ECC, gUnkEu_09F75EB0, gUnkEu_09F75E94 };
#endif
