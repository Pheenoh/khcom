#include "registration_data.h"
#include "system_state.h"
#include "mode.h"
#include "bos7.h"
#include "mode_staffroll.h"
#include "bos7_api.h"
#include "sprites_title.h"
#include "sprites_staff_roll.h"
#include "gba/io_reg.h"
#include "staff_roll_script_data.h"
#include "staff_roll_text_assets.h"
#include "staff_roll_scene_data.h"

const s32 gUnk_09A516C8[46] = {
    6, 6, 0, 0, 0, 6,
    4, 6, 0, 0, 208, 85,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 208, 100, 30,
    2, 5, 100, 0, 1,
    2, 5, 200, 0, 109,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A51780[61] = {
    6, 6, 0, 0, 1, 117,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 17, 70,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 32, 85, 30,
    2, 5, 100, 0, 112,
    2, 5, 120, 0, 125,
    2, 5, 256, 0, 112,
    2, 5, 306, 0, 136,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A51874[63] = {
    6, 6, 0, 0, 2, 149,
    4, 6, 0, 0, 218, 85,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 203, 100, 30,
    2, 5, 100, 0, 144,
    2, 5, 160, 0, 164,
    2, 5, 280, 0, 144,
    2, 5, 340, 0, 152,
    10, 5, 400, 0, 30,
    5, 7, 400, 0, 188, 115, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A51970[80] = {
    6, 6, 0, 0, 9, 245,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 17, 85,
    9, 5, 0, 0, 30,
    4, 6, 0, 0, 32, 100,
    2, 5, 50, 0, 236,
    6, 6, 150, 1, 8, 235,
    4, 6, 150, 1, 208, 100,
    11, 5, 150, 1, 8,
    14, 4, 160, 1,
    15, 5, 160, 0, 0,
    2, 5, 180, 0, 254,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A51AB0[93] = {
    6, 6, 0, 0, 12, 270,
    4, 6, 0, 0, 208, 130,
    9, 5, 0, 0, 30,
    2, 5, 160, 0, 276,
    6, 6, 180, 1, 68, 743,
    3, 5, 180, 1, 1,
    4, 6, 180, 1, 40, 120,
    6, 6, 200, 2, 59, 668,
    3, 5, 200, 2, 1,
    4, 6, 200, 2, 40, 120,
    5, 7, 200, 2, 40, 60, 60,
    7, 4, 232, 1,
    2, 5, 273, 2, 664,
    2, 5, 283, 2, 666,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 2,
    0, 0, -1,
};

const s32 gUnk_09A51C24[79] = {
    6, 6, 0, 1, 7, 222,
    4, 6, 0, 1, 208, 120,
    9, 5, 0, 0, 30,
    6, 6, 50, 0, 17, 337,
    3, 5, 50, 0, 1,
    4, 6, 50, 0, 32, 80,
    11, 5, 50, 0, 30,
    14, 4, 95, 0,
    2, 5, 100, 1, 228,
    2, 5, 260, 1, 222,
    2, 5, 280, 1, 221,
    2, 5, 300, 0, 340,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A51D60[141] = {
    6, 6, 0, 0, 55, 631,
    4, 6, 0, 0, 223, 65,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 208, 80, 30,
    6, 6, 100, 1, 60, 676,
    4, 6, 100, 1, 24, 120,
    3, 5, 100, 1, 1,
    11, 5, 100, 1, 30,
    6, 6, 100, 2, 61, 678,
    4, 6, 100, 2, 60, 108,
    3, 5, 100, 2, 1,
    11, 5, 100, 2, 30,
    14, 4, 135, 1,
    14, 4, 135, 2,
    2, 5, 140, 0, 627,
    3, 5, 260, 1, 0,
    3, 5, 270, 2, 0,
    2, 5, 280, 1, 677,
    2, 5, 290, 2, 680,
    2, 5, 300, 0, 631,
    16, 5, 370, 1, 1,
    16, 5, 380, 2, 1,
    16, 5, 400, 0, 1,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    7, 4, 480, 2,
    0, 0, -1,
};

const s32 gUnk_09A51F94[60] = {
    6, 6, 0, 0, 14, 299,
    4, 6, 0, 0, 24, 100,
    3, 5, 0, 0, 1,
    6, 6, 0, 1, 37, 456,
    4, 6, 0, 1, 64, 72,
    16, 5, 0, 1, 3,
    9, 5, 0, 0, 30,
    2, 5, 150, 0, 306,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A52084[113] = {
    6, 6, 0, 0, 15, 318,
    4, 6, 0, 0, 211, 75,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 196, 90, 30,
    6, 6, 80, 1, 38, 462,
    4, 6, 80, 1, 17, 95,
    3, 5, 80, 1, 1,
    11, 5, 80, 1, 30,
    5, 7, 80, 1, 32, 110, 60,
    14, 4, 145, 1,
    2, 5, 150, 0, 322,
    15, 5, 150, 0, 3,
    2, 5, 200, 0, 314,
    3, 5, 210, 0, 1,
    2, 5, 220, 0, 316,
    2, 5, 230, 0, 320,
    10, 5, 400, 0, 30,
    16, 5, 400, 0, 4,
    16, 5, 400, 1, 1,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A52248[61] = {
    6, 6, 0, 0, 13, 290,
    4, 6, 0, 0, 32, 100,
    3, 5, 0, 0, 1,
    9, 5, 0, 0, 30,
    2, 5, 50, 0, 288,
    2, 5, 150, 0, 298,
    2, 5, 250, 0, 292,
    2, 5, 350, 0, 294,
    10, 5, 400, 0, 30,
    5, 7, 400, 0, 32, 115, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A5233C[70] = {
    6, 6, 0, 0, 24, 387,
    4, 6, 0, 0, 208, 108,
    6, 6, 0, 1, 23, 381,
    3, 5, 0, 1, 1,
    4, 6, 0, 1, 24, 108,
    9, 5, 0, 0, 30,
    2, 5, 100, 1, 385,
    2, 5, 200, 1, 386,
    2, 5, 300, 0, 392,
    2, 5, 300, 1, 381,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A52454[44] = {
    6, 6, 0, 0, 16, 328,
    4, 6, 0, 0, 48, 108,
    3, 5, 0, 0, 1,
    9, 5, 0, 0, 30,
    2, 5, 140, 0, 335,
    2, 5, 270, 0, 332,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52504[65] = {
    6, 6, 0, 0, 10, 260,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 20, 100,
    6, 6, 0, 1, 54, 623,
    4, 6, 0, 1, 212, 100,
    9, 5, 0, 0, 30,
    2, 5, 100, 1, 626,
    2, 5, 200, 1, 623,
    2, 5, 300, 1, 626,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A52608[101] = {
    6, 6, 0, 0, 76, 827,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 24, 100,
    6, 6, 0, 1, 70, 756,
    4, 6, 0, 1, 220, 100,
    6, 6, 0, 2, 72, 810,
    3, 5, 0, 2, 1,
    4, 6, 0, 2, 184, 108,
    9, 5, 0, 0, 30,
    2, 5, 100, 0, 829,
    2, 5, 200, 0, 829,
    2, 5, 200, 1, 798,
    15, 5, 280, 1, 5,
    2, 5, 300, 0, 829,
    2, 5, 300, 1, 799,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    7, 4, 480, 2,
    0, 0, -1,
};

const s32 gUnk_09A5279C[51] = {
    6, 6, 0, 0, 19, 344,
    4, 6, 0, 0, 204, 110,
    9, 5, 0, 0, 30,
    2, 5, 120, 0, 348,
    2, 5, 240, 0, 351,
    2, 5, 300, 0, 349,
    10, 5, 400, 0, 30,
    5, 7, 400, 0, 189, 95, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52868[61] = {
    6, 6, 0, 0, 57, 638,
    4, 6, 0, 0, 24, 90,
    3, 5, 0, 0, 1,
    9, 5, 0, 0, 30,
    2, 5, 40, 0, 642,
    2, 5, 120, 0, 644,
    2, 5, 290, 0, 638,
    2, 5, 300, 0, 640,
    10, 5, 400, 0, 30,
    5, 7, 400, 0, 39, 105, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A5295C[88] = {
    6, 6, 0, 0, 35, 424,
    4, 6, 0, 0, 120, 100,
    9, 5, 0, 0, 80,
    5, 7, 0, 0, 216, 100, 80,
    6, 6, 100, 1, 34, 420,
    4, 6, 100, 1, 120, 100,
    3, 5, 100, 1, 1,
    11, 5, 100, 1, 80,
    5, 7, 100, 1, 24, 100, 80,
    14, 4, 185, 1,
    2, 5, 250, 1, 421,
    3, 5, 300, 0, 0,
    2, 5, 300, 0, 425,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A52ABC[51] = {
    6, 6, 0, 0, 44, 516,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 17, 95,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 32, 110, 30,
    2, 5, 100, 0, 514,
    2, 5, 200, 0, 567,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52B88[51] = {
    6, 6, 0, 0, 69, 747,
    4, 6, 0, 0, 223, 85,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 208, 100, 30,
    2, 5, 190, 0, 745,
    2, 5, 200, 0, 752,
    2, 5, 300, 0, 751,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52C54[44] = {
    6, 6, 0, 0, 43, 485,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 32, 110,
    9, 5, 0, 0, 30,
    2, 5, 150, 0, 509,
    2, 5, 300, 0, 495,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52D04[39] = {
    6, 6, 0, 0, 81, 856,
    4, 6, 0, 0, 200, 110,
    9, 5, 0, 0, 30,
    2, 5, 150, 0, 868,
    2, 5, 200, 0, 870,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52DA0[39] = {
    6, 6, 0, 0, 67, 721,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 28, 110,
    9, 5, 0, 0, 30,
    2, 5, 200, 0, 727,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52E3C[34] = {
    6, 6, 0, 0, 83, 889,
    4, 6, 0, 0, 216, 110,
    9, 5, 0, 0, 30,
    2, 5, 200, 0, 899,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52EC4[44] = {
    6, 6, 0, 0, 82, 887,
    3, 5, 0, 0, 1,
    4, 6, 0, 0, 32, 110,
    9, 5, 0, 0, 30,
    2, 5, 200, 0, 883,
    2, 5, 300, 0, 888,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A52F74[93] = {
    6, 6, 0, 0, 79, 841,
    4, 6, 0, 0, 184, 110,
    9, 5, 0, 0, 30,
    2, 5, 100, 0, 847,
    6, 6, 100, 1, 80, 853,
    4, 6, 100, 1, 184, 60,
    16, 5, 100, 1, 5,
    2, 5, 123, 0, 848,
    5, 7, 160, 1, 184, 110, 90,
    7, 4, 260, 1,
    6, 6, 260, 2, 80, 854,
    4, 6, 260, 2, 184, 110,
    7, 4, 300, 2,
    2, 5, 300, 0, 849,
    2, 5, 310, 0, 850,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A530E8[49] = {
    6, 6, 0, 0, 30, 410,
    4, 6, 0, 0, 48, 110,
    3, 5, 0, 0, 1,
    9, 5, 0, 0, 30,
    2, 5, 100, 0, 415,
    2, 5, 200, 0, 416,
    2, 5, 300, 0, 414,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A531AC[46] = {
    6, 6, 0, 0, 21, 364,
    4, 6, 0, 0, 212, 110,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 200, 110, 30,
    2, 5, 150, 0, 361,
    2, 5, 250, 0, 365,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A53264[110] = {
    6, 6, 0, 0, 25, 397,
    4, 6, 0, 0, 25, 105,
    3, 5, 0, 0, 1,
    6, 6, 0, 1, 26, 397,
    4, 6, 0, 1, 40, 256,
    3, 5, 0, 1, 1,
    9, 5, 0, 0, 30,
    5, 7, 0, 0, 40, 120, 30,
    2, 5, 100, 0, 395,
    2, 5, 200, 0, 401,
    6, 6, 210, 2, 27, 404,
    3, 5, 210, 2, 1,
    4, 6, 210, 2, 40, 120,
    4, 6, 235, 0, 40, 256,
    4, 6, 235, 1, 40, 120,
    2, 5, 235, 1, 402,
    7, 4, 275, 2,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

const s32 gUnk_09A5341C[54] = {
    6, 6, 0, 0, 47, 582,
    4, 6, 0, 0, 200, 110,
    9, 5, 0, 0, 30,
    2, 5, 160, 0, 581,
    2, 5, 170, 0, 579,
    2, 5, 180, 0, 576,
    2, 5, 280, 0, 584,
    2, 5, 300, 0, 585,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A534F4[44] = {
    6, 6, 0, 0, 20, 353,
    4, 6, 0, 0, 52, 110,
    3, 5, 0, 0, 1,
    9, 5, 0, 0, 30,
    2, 5, 100, 0, 356,
    2, 5, 300, 0, 360,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A535A4[34] = {
    6, 6, 0, 0, 64, 688,
    4, 6, 0, 0, 208, 110,
    9, 5, 0, 0, 30,
    2, 5, 200, 0, 694,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A5362C[39] = {
    6, 6, 0, 0, 84, 907,
    4, 6, 0, 0, 32, 110,
    3, 5, 0, 0, 1,
    9, 5, 0, 0, 30,
    2, 5, 150, 0, 908,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A536C8[44] = {
    6, 6, 0, 0, 65, 695,
    4, 6, 0, 0, 216, 100,
    9, 5, 0, 0, 30,
    2, 5, 100, 0, 706,
    2, 5, 250, 0, 695,
    2, 5, 280, 0, 698,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    0, 0, -1,
};

const s32 gUnk_09A53778[88] = {
    6, 6, 0, 1, 34, 420,
    4, 6, 0, 1, 128, 100,
    3, 5, 0, 1, 1,
    9, 5, 0, 0, 80,
    5, 7, 0, 1, 24, 100, 80,
    6, 6, 100, 0, 35, 424,
    4, 6, 100, 0, 120, 100,
    11, 5, 100, 0, 80,
    5, 7, 100, 0, 208, 100, 80,
    14, 4, 185, 0,
    2, 5, 250, 0, 425,
    3, 5, 300, 0, 0,
    2, 5, 300, 1, 421,
    10, 5, 400, 0, 30,
    7, 4, 480, 0,
    7, 4, 480, 1,
    0, 0, -1,
};

#ifdef VERSION_US

u8* gUnk_09EF9F54[632] = {
    gUnkUs_09A516BC,
    gUnkUs_09A516B8,
    gUnkUs_09A516A0,
    gUnkUs_09A5169C,
    gUnkUs_09A51678,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51668,
    gUnkUs_09A516B8,
    gUnkUs_09A5164C,
    gUnkUs_09A5169C,
    gUnkUs_09A51638,
    gUnkUs_09A5169C,
    gUnkUs_09A51620,
    gUnkUs_09A5169C,
    gUnkUs_09A51610,
    gUnkUs_09A5169C,
    gUnkUs_09A515F8,
    gUnkUs_09A5169C,
    gUnkUs_09A515D8,
    gUnkUs_09A5169C,
    gUnkUs_09A515C8,
    gUnkUs_09A5169C,
    gUnkUs_09A515A4,
    gUnkUs_09A5169C,
    gUnkUs_09A51584,
    gUnkUs_09A5169C,
    gUnkUs_09A51578,
    gUnkUs_09A5169C,
    gUnkUs_09A51558,
    gUnkUs_09A5169C,
    gUnkUs_09A51548,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51538,
    gUnkUs_09A516B8,
    gUnkUs_09A51524,
    gUnkUs_09A5169C,
    gUnkUs_09A51504,
    gUnkUs_09A5169C,
    gUnkUs_09A514E8,
    gUnkUs_09A5169C,
    gUnkUs_09A514C8,
    gUnkUs_09A5169C,
    gUnkUs_09A514A8,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51480,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A5169C,
    gUnkUs_09A51474,
    gUnkUs_09A516B8,
    gUnkUs_09A51460,
    gUnkUs_09A5169C,
    gUnkUs_09A51444,
    gUnkUs_09A5169C,
    gUnkUs_09A51428,
    gUnkUs_09A5169C,
    gUnkUs_09A51414,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51400,
    gUnkUs_09A516B8,
    gUnkUs_09A513F0,
    gUnkUs_09A5169C,
    gUnkUs_09A513DC,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A513CC,
    gUnkUs_09A516B8,
    gUnkUs_09A513A8,
    gUnkUs_09A5169C,
    gUnkUs_09A51388,
    gUnkUs_09A5169C,
    gUnkUs_09A51374,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51360,
    gUnkUs_09A516B8,
    gUnkUs_09A5134C,
    gUnkUs_09A5169C,
    gUnkUs_09A5132C,
    gUnkUs_09A5169C,
    gUnkUs_09A51308,
    gUnkUs_09A5169C,
    gUnkUs_09A512E8,
    gUnkUs_09A5169C,
    gUnkUs_09A512C8,
    gUnkUs_09A5169C,
    gUnkUs_09A512A4,
    gUnkUs_09A5169C,
    gUnkUs_09A51280,
    gUnkUs_09A5169C,
    gUnkUs_09A5126C,
    gUnkUs_09A5169C,
    gUnkUs_09A5125C,
    gUnkUs_09A5169C,
    gUnkUs_09A51240,
    gUnkUs_09A5169C,
    gUnkUs_09A5121C,
    gUnkUs_09A5169C,
    gUnkUs_09A51200,
    gUnkUs_09A5169C,
    gUnkUs_09A511EC,
    gUnkUs_09A5169C,
    gUnkUs_09A511DC,
    gUnkUs_09A5169C,
    gUnkUs_09A511CC,
    gUnkUs_09A5169C,
    gUnkUs_09A511BC,
    gUnkUs_09A5169C,
    gUnkUs_09A511AC,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A511A4,
    gUnkUs_09A516B8,
    gUnkUs_09A5118C,
    gUnkUs_09A5169C,
    gUnkUs_09A51178,
    gUnkUs_09A5169C,
    gUnkUs_09A51168,
    gUnkUs_09A5169C,
    gUnkUs_09A5115C,
    gUnkUs_09A5169C,
    gUnkUs_09A51148,
    gUnkUs_09A5169C,
    gUnkUs_09A5113C,
    gUnkUs_09A5169C,
    gUnkUs_09A51128,
    gUnkUs_09A5169C,
    gUnkUs_09A51118,
    gUnkUs_09A5169C,
    gUnkUs_09A51100,
    gUnkUs_09A5169C,
    gUnkUs_09A510DC,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A510CC,
    gUnkUs_09A516B8,
    gUnkUs_09A510C0,
    gUnkUs_09A510BC,
    gUnkUs_09A510A4,
    gUnkUs_09A51088,
    gUnkUs_09A51060,
    gUnkUs_09A51038,
    gUnkUs_09A51010,
    gUnkUs_09A50FF0,
    gUnkUs_09A50FC4,
    gUnkUs_09A50FA0,
    gUnkUs_09A50F84,
    gUnkUs_09A51674,
    gUnkUs_09A50F54,
    gUnkUs_09A50F2C,
    gUnkUs_09A51674,
    gUnkUs_09A50F0C,
    gUnkUs_09A51674,
    gUnkUs_09A50ED4,
    gUnkUs_09A50ED0,
    gUnkUs_09A516B8,
    gUnkUs_09A50EB4,
    gUnkUs_09A516B8,
    gUnkUs_09A50EA0,
    gUnkUs_09A5169C,
    gUnkUs_09A50E90,
    gUnkUs_09A5169C,
    gUnkUs_09A50E74,
    gUnkUs_09A5169C,
    gUnkUs_09A50E64,
    gUnkUs_09A5169C,
    gUnkUs_09A50E50,
    gUnkUs_09A5169C,
    gUnkUs_09A50E40,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50E2C,
    gUnkUs_09A516B8,
    gUnkUs_09A50E14,
    gUnkUs_09A5169C,
    gUnkUs_09A50E08,
    gUnkUs_09A5169C,
    gUnkUs_09A50EA0,
    gUnkUs_09A5169C,
    gUnkUs_09A50DF8,
    gUnkUs_09A5169C,
    gUnkUs_09A50DEC,
    gUnkUs_09A5169C,
    gUnkUs_09A50DDC,
    gUnkUs_09A5169C,
    gUnkUs_09A50DC4,
    gUnkUs_09A5169C,
    gUnkUs_09A50DB8,
    gUnkUs_09A5169C,
    gUnkUs_09A50DA8,
    gUnkUs_09A5169C,
    gUnkUs_09A50D98,
    gUnkUs_09A5169C,
    gUnkUs_09A50D80,
    gUnkUs_09A5169C,
    gUnkUs_09A50D74,
    gUnkUs_09A5169C,
    gUnkUs_09A50D60,
    gUnkUs_09A5169C,
    gUnkUs_09A50D50,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50D34,
    gUnkUs_09A516B8,
    gUnkUs_09A50D20,
    gUnkUs_09A5169C,
    gUnkUs_09A50D10,
    gUnkUs_09A5169C,
    gUnkUs_09A50D00,
    gUnkUs_09A5169C,
    gUnkUs_09A50CF4,
    gUnkUs_09A5169C,
    gUnkUs_09A50CE8,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50CD8,
    gUnkUs_09A5169C,
    gUnkUs_09A50CC8,
    gUnkUs_09A5169C,
    gUnkUs_09A50CB4,
    gUnkUs_09A5169C,
    gUnkUs_09A50CA0,
    gUnkUs_09A5169C,
    gUnkUs_09A50C94,
    gUnkUs_09A5169C,
    gUnkUs_09A50C88,
    gUnkUs_09A5169C,
    gUnkUs_09A50C78,
    gUnkUs_09A5169C,
    gUnkUs_09A50C6C,
    gUnkUs_09A5169C,
    gUnkUs_09A50C60,
    gUnkUs_09A5169C,
    gUnkUs_09A50C50,
    gUnkUs_09A5169C,
    gUnkUs_09A50C40,
    gUnkUs_09A5169C,
    gUnkUs_09A50C30,
    gUnkUs_09A5169C,
    gUnkUs_09A50C20,
    gUnkUs_09A5169C,
    gUnkUs_09A50C10,
    gUnkUs_09A5169C,
    gUnkUs_09A50C00,
    gUnkUs_09A5169C,
    gUnkUs_09A510BC,
    gUnkUs_09A51674,
    gUnkUs_09A50BEC,
    gUnkUs_09A50BB4,
    gUnkUs_09A50B8C,
    gUnkUs_09A51674,
    gUnkUs_09A50B74,
    gUnkUs_09A50B54,
    gUnkUs_09A50B30,
    gUnkUs_09A51674,
    gUnkUs_09A50B1C,
    gUnkUs_09A50AEC,
    gUnkUs_09A50AC4,
    gUnkUs_09A50AA8,
    gUnkUs_09A50ED0,
    gUnkUs_09A516B8,
    gUnkUs_09A50A90,
    gUnkUs_09A516B8,
    gUnkUs_09A50A7C,
    gUnkUs_09A5169C,
    gUnkUs_09A50A6C,
    gUnkUs_09A5169C,
    gUnkUs_09A50A60,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50A54,
    gUnkUs_09A5169C,
    gUnkUs_09A50A48,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50A38,
    gUnkUs_09A5169C,
    gUnkUs_09A50A28,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50A08,
    gUnkUs_09A5169C,
    gUnkUs_09A509F8,
    gUnkUs_09A5169C,
    gUnkUs_09A509E4,
    gUnkUs_09A5169C,
    gUnkUs_09A509D8,
    gUnkUs_09A5169C,
    gUnkUs_09A509B8,
    gUnkUs_09A5169C,
    gUnkUs_09A509B0,
    gUnkUs_09A5169C,
    gUnkUs_09A5098C,
    gUnkUs_09A5169C,
    gUnkUs_09A5097C,
    gUnkUs_09A5169C,
    gUnkUs_09A5095C,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A5094C,
    gUnkUs_09A516B8,
    gUnkUs_09A51128,
    gUnkUs_09A5169C,
    gUnkUs_09A5093C,
    gUnkUs_09A5169C,
    gUnkUs_09A50928,
    gUnkUs_09A5169C,
    gUnkUs_09A50918,
    gUnkUs_09A5169C,
    gUnkUs_09A50900,
    gUnkUs_09A5169C,
    gUnkUs_09A508F0,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A508DC,
    gUnkUs_09A516B8,
    gUnkUs_09A50E50,
    gUnkUs_09A5169C,
    gUnkUs_09A508CC,
    gUnkUs_09A5169C,
    gUnkUs_09A508BC,
    gUnkUs_09A5169C,
    gUnkUs_09A508A8,
    gUnkUs_09A5169C,
    gUnkUs_09A50894,
    gUnkUs_09A5169C,
    gUnkUs_09A50874,
    gUnkUs_09A5169C,
    gUnkUs_09A50858,
    gUnkUs_09A5169C,
    gUnkUs_09A50838,
    gUnkUs_09A5169C,
    gUnkUs_09A50814,
    gUnkUs_09A5169C,
    gUnkUs_09A50808,
    gUnkUs_09A5169C,
    gUnkUs_09A507E8,
    gUnkUs_09A5169C,
    gUnkUs_09A507C8,
    gUnkUs_09A5169C,
    gUnkUs_09A507A8,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50794,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50770,
    gUnkUs_09A516B8,
    gUnkUs_09A50760,
    gUnkUs_09A5169C,
    gUnkUs_09A5074C,
    gUnkUs_09A5169C,
    gUnkUs_09A50730,
    gUnkUs_09A5169C,
    gUnkUs_09A50714,
    gUnkUs_09A5169C,
    gUnkUs_09A506F8,
    gUnkUs_09A5169C,
    gUnkUs_09A506E8,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A5169C,
    gUnkUs_09A506D4,
    gUnkUs_09A5169C,
    gUnkUs_09A50E50,
    gUnkUs_09A5169C,
    gUnkUs_09A506C4,
    gUnkUs_09A5169C,
    gUnkUs_09A506AC,
    gUnkUs_09A5169C,
    gUnkUs_09A5069C,
    gUnkUs_09A5169C,
    gUnkUs_09A50680,
    gUnkUs_09A5169C,
    gUnkUs_09A50674,
    gUnkUs_09A5169C,
    gUnkUs_09A5065C,
    gUnkUs_09A5169C,
    gUnkUs_09A50650,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A5169C,
    gUnkUs_09A5063C,
    gUnkUs_09A5169C,
    gUnkUs_09A50620,
    gUnkUs_09A5169C,
    gUnkUs_09A50608,
    gUnkUs_09A5169C,
    gUnkUs_09A505F0,
    gUnkUs_09A5169C,
    gUnkUs_09A505D8,
    gUnkUs_09A5169C,
    gUnkUs_09A505B8,
    gUnkUs_09A5169C,
    gUnkUs_09A505A4,
    gUnkUs_09A5169C,
    gUnkUs_09A5058C,
    gUnkUs_09A5169C,
    gUnkUs_09A5057C,
    gUnkUs_09A5169C,
    gUnkUs_09A50568,
    gUnkUs_09A5169C,
    gUnkUs_09A50548,
    gUnkUs_09A5169C,
    gUnkUs_09A5052C,
    gUnkUs_09A5169C,
    gUnkUs_09A50510,
    gUnkUs_09A5169C,
    gUnkUs_09A504EC,
    gUnkUs_09A5169C,
    gUnkUs_09A504DC,
    gUnkUs_09A5169C,
    gUnkUs_09A504CC,
    gUnkUs_09A5169C,
    gUnkUs_09A504A4,
    gUnkUs_09A5169C,
    gUnkUs_09A50DC4,
    gUnkUs_09A5169C,
    gUnkUs_09A50498,
    gUnkUs_09A5169C,
    gUnkUs_09A50484,
    gUnkUs_09A5169C,
    gUnkUs_09A50464,
    gUnkUs_09A5169C,
    gUnkUs_09A50448,
    gUnkUs_09A5169C,
    gUnkUs_09A50430,
    gUnkUs_09A5169C,
    gUnkUs_09A50424,
    gUnkUs_09A5169C,
    gUnkUs_09A503F8,
    gUnkUs_09A5169C,
    gUnkUs_09A503F0,
    gUnkUs_09A5169C,
    gUnkUs_09A503D0,
    gUnkUs_09A5169C,
    gUnkUs_09A503BC,
    gUnkUs_09A5169C,
    gUnkUs_09A503AC,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50398,
    gUnkUs_09A516B8,
    gUnkUs_09A50380,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A5035C,
    gUnkUs_09A5169C,
    gUnkUs_09A50340,
    gUnkUs_09A5169C,
    gUnkUs_09A50320,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A502FC,
    gUnkUs_09A5169C,
    gUnkUs_09A502DC,
    gUnkUs_09A5169C,
    gUnkUs_09A502C0,
    gUnkUs_09A5169C,
    gUnkUs_09A502A0,
    gUnkUs_09A5169C,
    gUnkUs_09A50294,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50270,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50250,
    gUnkUs_09A5169C,
    gUnkUs_09A50230,
    gUnkUs_09A5169C,
    gUnkUs_09A50210,
    gUnkUs_09A5169C,
    gUnkUs_09A501EC,
    gUnkUs_09A5169C,
    gUnkUs_09A501C8,
    gUnkUs_09A5169C,
    gUnkUs_09A501A8,
    gUnkUs_09A5169C,
    gUnkUs_09A5018C,
    gUnkUs_09A5169C,
    gUnkUs_09A50168,
    gUnkUs_09A5169C,
    gUnkUs_09A50148,
    gUnkUs_09A5169C,
    gUnkUs_09A5012C,
    gUnkUs_09A5169C,
    gUnkUs_09A50108,
    gUnkUs_09A5169C,
    gUnkUs_09A500E8,
    gUnkUs_09A5169C,
    gUnkUs_09A500CC,
    gUnkUs_09A5169C,
    gUnkUs_09A500AC,
    gUnkUs_09A5169C,
    gUnkUs_09A50088,
    gUnkUs_09A5169C,
    gUnkUs_09A5006C,
    gUnkUs_09A5169C,
    gUnkUs_09A50048,
    gUnkUs_09A5169C,
    gUnkUs_09A5002C,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A50008,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A4FFD8,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A4FFC0,
    gUnkUs_09A516B8,
    gUnkUs_09A50DEC,
    gUnkUs_09A5169C,
    gUnkUs_09A4FF9C,
    gUnkUs_09A5169C,
    gUnkUs_09A4FF88,
    gUnkUs_09A5169C,
    gUnkUs_09A4FF60,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A4FF88,
    gUnkUs_09A5169C,
    gUnkUs_09A4FF54,
    gUnkUs_09A5169C,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A4FF50,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A4FF4C,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A4FF48,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    gUnkUs_09A516B8,
    gUnkUs_09A51674,
    0,
};

const s32* gUnk_09EFA934[17] = {
    gUnk_09A516C8,
    gUnk_09A51780,
    gUnk_09A51874,
    gUnk_09A51970,
    gUnk_09A51AB0,
    gUnk_09A51C24,
    gUnk_09A51D60,
    gUnk_09A51F94,
    gUnk_09A52084,
    gUnk_09A52248,
    gUnk_09A5233C,
    gUnk_09A52454,
    gUnk_09A52504,
    gUnk_09A52608,
    gUnk_09A5279C,
    gUnk_09A52868,
    gUnk_09A5295C,
};

const s32* gUnk_09EFA978[17] = {
    gUnk_09A52ABC,
    gUnk_09A52B88,
    gUnk_09A52C54,
    gUnk_09A52D04,
    gUnk_09A52DA0,
    gUnk_09A52E3C,
    gUnk_09A52EC4,
    gUnk_09A52F74,
    gUnk_09A530E8,
    gUnk_09A531AC,
    gUnk_09A53264,
    gUnk_09A5341C,
    gUnk_09A534F4,
    gUnk_09A535A4,
    gUnk_09A5362C,
    gUnk_09A536C8,
    gUnk_09A53778,
};

u8* gUnk_09EFA9BC = gUnkUs_09A516B8;

u8* gUnk_09EFA9C0 = gUnkUs_09A54204;

#endif

#ifdef VERSION_JP

u8* gUnk_09EF9F54[704] = {
    gUnkJp_09A0654C,
    gUnkJp_09A06548,
    gUnkJp_09A06530,
    gUnkJp_09A0652C,
    gUnkJp_09A06508,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A064F8,
    gUnkJp_09A06548,
    gUnkJp_09A064DC,
    gUnkJp_09A0652C,
    gUnkJp_09A064C8,
    gUnkJp_09A0652C,
    gUnkJp_09A064B0,
    gUnkJp_09A0652C,
    gUnkJp_09A064A0,
    gUnkJp_09A0652C,
    gUnkJp_09A06488,
    gUnkJp_09A0652C,
    gUnkJp_09A06468,
    gUnkJp_09A0652C,
    gUnkJp_09A06458,
    gUnkJp_09A0652C,
    gUnkJp_09A06434,
    gUnkJp_09A0652C,
    gUnkJp_09A06414,
    gUnkJp_09A0652C,
    gUnkJp_09A06408,
    gUnkJp_09A0652C,
    gUnkJp_09A063E8,
    gUnkJp_09A0652C,
    gUnkJp_09A063D8,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A063C8,
    gUnkJp_09A06548,
    gUnkJp_09A063B4,
    gUnkJp_09A0652C,
    gUnkJp_09A06394,
    gUnkJp_09A0652C,
    gUnkJp_09A06378,
    gUnkJp_09A0652C,
    gUnkJp_09A06358,
    gUnkJp_09A0652C,
    gUnkJp_09A06338,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06310,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A0652C,
    gUnkJp_09A06304,
    gUnkJp_09A06548,
    gUnkJp_09A062F0,
    gUnkJp_09A0652C,
    gUnkJp_09A062D4,
    gUnkJp_09A0652C,
    gUnkJp_09A062B8,
    gUnkJp_09A0652C,
    gUnkJp_09A062A4,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06290,
    gUnkJp_09A06548,
    gUnkJp_09A06280,
    gUnkJp_09A0652C,
    gUnkJp_09A0626C,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A0625C,
    gUnkJp_09A06548,
    gUnkJp_09A06238,
    gUnkJp_09A0652C,
    gUnkJp_09A06218,
    gUnkJp_09A0652C,
    gUnkJp_09A06204,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A061F0,
    gUnkJp_09A06548,
    gUnkJp_09A061DC,
    gUnkJp_09A0652C,
    gUnkJp_09A061BC,
    gUnkJp_09A0652C,
    gUnkJp_09A06198,
    gUnkJp_09A0652C,
    gUnkJp_09A06178,
    gUnkJp_09A0652C,
    gUnkJp_09A06158,
    gUnkJp_09A0652C,
    gUnkJp_09A06134,
    gUnkJp_09A0652C,
    gUnkJp_09A06110,
    gUnkJp_09A0652C,
    gUnkJp_09A060FC,
    gUnkJp_09A0652C,
    gUnkJp_09A060EC,
    gUnkJp_09A0652C,
    gUnkJp_09A060D0,
    gUnkJp_09A0652C,
    gUnkJp_09A060AC,
    gUnkJp_09A0652C,
    gUnkJp_09A06090,
    gUnkJp_09A0652C,
    gUnkJp_09A0607C,
    gUnkJp_09A0652C,
    gUnkJp_09A0606C,
    gUnkJp_09A0652C,
    gUnkJp_09A0605C,
    gUnkJp_09A0652C,
    gUnkJp_09A0604C,
    gUnkJp_09A0652C,
    gUnkJp_09A0603C,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06034,
    gUnkJp_09A06548,
    gUnkJp_09A0601C,
    gUnkJp_09A0652C,
    gUnkJp_09A06008,
    gUnkJp_09A0652C,
    gUnkJp_09A05FF8,
    gUnkJp_09A0652C,
    gUnkJp_09A05FEC,
    gUnkJp_09A0652C,
    gUnkJp_09A05FD8,
    gUnkJp_09A0652C,
    gUnkJp_09A05FCC,
    gUnkJp_09A0652C,
    gUnkJp_09A05FB8,
    gUnkJp_09A0652C,
    gUnkJp_09A05FA8,
    gUnkJp_09A0652C,
    gUnkJp_09A05F90,
    gUnkJp_09A0652C,
    gUnkJp_09A05F6C,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05F5C,
    gUnkJp_09A06548,
    gUnkJp_09A05F50,
    gUnkJp_09A05F4C,
    gUnkJp_09A05F34,
    gUnkJp_09A05F18,
    gUnkJp_09A05EF0,
    gUnkJp_09A05EC8,
    gUnkJp_09A05EA0,
    gUnkJp_09A05E80,
    gUnkJp_09A05E54,
    gUnkJp_09A05E30,
    gUnkJp_09A05E14,
    gUnkJp_09A06504,
    gUnkJp_09A05DE4,
    gUnkJp_09A05DBC,
    gUnkJp_09A06504,
    gUnkJp_09A05D9C,
    gUnkJp_09A06504,
    gUnkJp_09A05D64,
    gUnkJp_09A05D60,
    gUnkJp_09A06548,
    gUnkJp_09A05D44,
    gUnkJp_09A06548,
    gUnkJp_09A05D30,
    gUnkJp_09A0652C,
    gUnkJp_09A05D20,
    gUnkJp_09A0652C,
    gUnkJp_09A05D04,
    gUnkJp_09A0652C,
    gUnkJp_09A05CF4,
    gUnkJp_09A0652C,
    gUnkJp_09A05CE0,
    gUnkJp_09A0652C,
    gUnkJp_09A05CD0,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05CBC,
    gUnkJp_09A06548,
    gUnkJp_09A05D30,
    gUnkJp_09A0652C,
    gUnkJp_09A05CAC,
    gUnkJp_09A0652C,
    gUnkJp_09A05CA0,
    gUnkJp_09A0652C,
    gUnkJp_09A05C90,
    gUnkJp_09A0652C,
    gUnkJp_09A05C78,
    gUnkJp_09A0652C,
    gUnkJp_09A05C6C,
    gUnkJp_09A0652C,
    gUnkJp_09A05C54,
    gUnkJp_09A0652C,
    gUnkJp_09A05C48,
    gUnkJp_09A0652C,
    gUnkJp_09A05C38,
    gUnkJp_09A0652C,
    gUnkJp_09A05C28,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05C0C,
    gUnkJp_09A06548,
    gUnkJp_09A05BF8,
    gUnkJp_09A0652C,
    gUnkJp_09A05BE4,
    gUnkJp_09A0652C,
    gUnkJp_09A05BC4,
    gUnkJp_09A0652C,
    gUnkJp_09A05BAC,
    gUnkJp_09A0652C,
    gUnkJp_09A05B98,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05B7C,
    gUnkJp_09A0652C,
    gUnkJp_09A05B60,
    gUnkJp_09A0652C,
    gUnkJp_09A05B48,
    gUnkJp_09A0652C,
    gUnkJp_09A05B34,
    gUnkJp_09A0652C,
    gUnkJp_09A05B1C,
    gUnkJp_09A0652C,
    gUnkJp_09A05B0C,
    gUnkJp_09A0652C,
    gUnkJp_09A05AF0,
    gUnkJp_09A0652C,
    gUnkJp_09A05AD4,
    gUnkJp_09A0652C,
    gUnkJp_09A05ABC,
    gUnkJp_09A0652C,
    gUnkJp_09A05AA4,
    gUnkJp_09A0652C,
    gUnkJp_09A05A88,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05A70,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A0652C,
    gUnkJp_09A05A58,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05A4C,
    gUnkJp_09A0652C,
    gUnkJp_09A05A3C,
    gUnkJp_09A0652C,
    gUnkJp_09A05A2C,
    gUnkJp_09A0652C,
    gUnkJp_09A05F4C,
    gUnkJp_09A06504,
    gUnkJp_09A05A18,
    gUnkJp_09A059E0,
    gUnkJp_09A059B8,
    gUnkJp_09A06504,
    gUnkJp_09A059A0,
    gUnkJp_09A05980,
    gUnkJp_09A0595C,
    gUnkJp_09A06504,
    gUnkJp_09A05948,
    gUnkJp_09A05918,
    gUnkJp_09A058F0,
    gUnkJp_09A058D4,
    gUnkJp_09A05D60,
    gUnkJp_09A06548,
    gUnkJp_09A058C0,
    gUnkJp_09A06548,
    gUnkJp_09A058A8,
    gUnkJp_09A0652C,
    gUnkJp_09A05898,
    gUnkJp_09A0652C,
    gUnkJp_09A05884,
    gUnkJp_09A0652C,
    gUnkJp_09A05860,
    gUnkJp_09A0652C,
    gUnkJp_09A05850,
    gUnkJp_09A0652C,
    gUnkJp_09A05844,
    gUnkJp_09A0652C,
    gUnkJp_09A05820,
    gUnkJp_09A0652C,
    gUnkJp_09A05804,
    gUnkJp_09A0652C,
    gUnkJp_09A057E8,
    gUnkJp_09A0652C,
    gUnkJp_09A057C8,
    gUnkJp_09A0652C,
    gUnkJp_09A057B4,
    gUnkJp_09A0652C,
    gUnkJp_09A057A4,
    gUnkJp_09A0652C,
    gUnkJp_09A05784,
    gUnkJp_09A0652C,
    gUnkJp_09A05764,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A0574C,
    gUnkJp_09A06548,
    gUnkJp_09A05738,
    gUnkJp_09A0652C,
    gUnkJp_09A05728,
    gUnkJp_09A0652C,
    gUnkJp_09A0571C,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05710,
    gUnkJp_09A0652C,
    gUnkJp_09A05704,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A056F4,
    gUnkJp_09A0652C,
    gUnkJp_09A056E4,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A056C4,
    gUnkJp_09A0652C,
    gUnkJp_09A056B4,
    gUnkJp_09A0652C,
    gUnkJp_09A056A0,
    gUnkJp_09A0652C,
    gUnkJp_09A05694,
    gUnkJp_09A0652C,
    gUnkJp_09A05674,
    gUnkJp_09A0652C,
    gUnkJp_09A0566C,
    gUnkJp_09A0652C,
    gUnkJp_09A05648,
    gUnkJp_09A0652C,
    gUnkJp_09A05638,
    gUnkJp_09A0652C,
    gUnkJp_09A05618,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05608,
    gUnkJp_09A06548,
    gUnkJp_09A05FB8,
    gUnkJp_09A0652C,
    gUnkJp_09A055F8,
    gUnkJp_09A0652C,
    gUnkJp_09A055E4,
    gUnkJp_09A0652C,
    gUnkJp_09A055D4,
    gUnkJp_09A0652C,
    gUnkJp_09A055BC,
    gUnkJp_09A0652C,
    gUnkJp_09A055AC,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05598,
    gUnkJp_09A06548,
    gUnkJp_09A05CE0,
    gUnkJp_09A0652C,
    gUnkJp_09A05588,
    gUnkJp_09A0652C,
    gUnkJp_09A05578,
    gUnkJp_09A0652C,
    gUnkJp_09A05564,
    gUnkJp_09A0652C,
    gUnkJp_09A05550,
    gUnkJp_09A0652C,
    gUnkJp_09A05530,
    gUnkJp_09A0652C,
    gUnkJp_09A05514,
    gUnkJp_09A0652C,
    gUnkJp_09A054F4,
    gUnkJp_09A0652C,
    gUnkJp_09A054D0,
    gUnkJp_09A0652C,
    gUnkJp_09A054C4,
    gUnkJp_09A0652C,
    gUnkJp_09A054A4,
    gUnkJp_09A0652C,
    gUnkJp_09A05484,
    gUnkJp_09A0652C,
    gUnkJp_09A05464,
    gUnkJp_09A0652C,
    gUnkJp_09A05448,
    gUnkJp_09A0652C,
    gUnkJp_09A05438,
    gUnkJp_09A0652C,
    gUnkJp_09A05418,
    gUnkJp_09A0652C,
    gUnkJp_09A05408,
    gUnkJp_09A0652C,
    gUnkJp_09A053E8,
    gUnkJp_09A0652C,
    gUnkJp_09A053C8,
    gUnkJp_09A0652C,
    gUnkJp_09A053A8,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05394,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A0537C,
    gUnkJp_09A06548,
    gUnkJp_09A05368,
    gUnkJp_09A0652C,
    gUnkJp_09A05348,
    gUnkJp_09A0652C,
    gUnkJp_09A05338,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05314,
    gUnkJp_09A06548,
    gUnkJp_09A05CE0,
    gUnkJp_09A0652C,
    gUnkJp_09A05308,
    gUnkJp_09A0652C,
    gUnkJp_09A052FC,
    gUnkJp_09A0652C,
    gUnkJp_09A052DC,
    gUnkJp_09A0652C,
    gUnkJp_09A052B8,
    gUnkJp_09A0652C,
    gUnkJp_09A05290,
    gUnkJp_09A0652C,
    gUnkJp_09A0526C,
    gUnkJp_09A0652C,
    gUnkJp_09A05248,
    gUnkJp_09A0652C,
    gUnkJp_09A05238,
    gUnkJp_09A0652C,
    gUnkJp_09A05228,
    gUnkJp_09A0652C,
    gUnkJp_09A05204,
    gUnkJp_09A0652C,
    gUnkJp_09A051F8,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A051E4,
    gUnkJp_09A06548,
    gUnkJp_09A051CC,
    gUnkJp_09A0652C,
    gUnkJp_09A051C0,
    gUnkJp_09A0652C,
    gUnkJp_09A051AC,
    gUnkJp_09A0652C,
    gUnkJp_09A0519C,
    gUnkJp_09A0652C,
    gUnkJp_09A05184,
    gUnkJp_09A0652C,
    gUnkJp_09A05174,
    gUnkJp_09A0652C,
    gUnkJp_09A05160,
    gUnkJp_09A0652C,
    gUnkJp_09A05150,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A05130,
    gUnkJp_09A06548,
    gUnkJp_09A05CE0,
    gUnkJp_09A0652C,
    gUnkJp_09A0511C,
    gUnkJp_09A0652C,
    gUnkJp_09A05110,
    gUnkJp_09A0652C,
    gUnkJp_09A05100,
    gUnkJp_09A0652C,
    gUnkJp_09A050E4,
    gUnkJp_09A0652C,
    gUnkJp_09A050C0,
    gUnkJp_09A0652C,
    gUnkJp_09A050A0,
    gUnkJp_09A0652C,
    gUnkJp_09A05088,
    gUnkJp_09A0652C,
    gUnkJp_09A05068,
    gUnkJp_09A0652C,
    gUnkJp_09A05044,
    gUnkJp_09A0652C,
    gUnkJp_09A05020,
    gUnkJp_09A0652C,
    gUnkJp_09A05000,
    gUnkJp_09A0652C,
    gUnkJp_09A04FDC,
    gUnkJp_09A0652C,
    gUnkJp_09A04FCC,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04FA8,
    gUnkJp_09A06548,
    gUnkJp_09A05110,
    gUnkJp_09A0652C,
    gUnkJp_09A04F9C,
    gUnkJp_09A0652C,
    gUnkJp_09A04F8C,
    gUnkJp_09A0652C,
    gUnkJp_09A04F70,
    gUnkJp_09A0652C,
    gUnkJp_09A04F48,
    gUnkJp_09A0652C,
    gUnkJp_09A04F28,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04F04,
    gUnkJp_09A06548,
    gUnkJp_09A04EF4,
    gUnkJp_09A0652C,
    gUnkJp_09A04EE0,
    gUnkJp_09A0652C,
    gUnkJp_09A04EC4,
    gUnkJp_09A0652C,
    gUnkJp_09A04EA8,
    gUnkJp_09A0652C,
    gUnkJp_09A04E8C,
    gUnkJp_09A0652C,
    gUnkJp_09A04E7C,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04E68,
    gUnkJp_09A06548,
    gUnkJp_09A04E3C,
    gUnkJp_09A0652C,
    gUnkJp_09A04E10,
    gUnkJp_09A0652C,
    gUnkJp_09A04DE4,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04DC0,
    gUnkJp_09A0652C,
    gUnkJp_09A04DA4,
    gUnkJp_09A0652C,
    gUnkJp_09A04D84,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04D60,
    gUnkJp_09A0652C,
    gUnkJp_09A04D40,
    gUnkJp_09A0652C,
    gUnkJp_09A04D24,
    gUnkJp_09A0652C,
    gUnkJp_09A04D04,
    gUnkJp_09A0652C,
    gUnkJp_09A04CF8,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04CD4,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04CB4,
    gUnkJp_09A0652C,
    gUnkJp_09A04C94,
    gUnkJp_09A0652C,
    gUnkJp_09A04C74,
    gUnkJp_09A0652C,
    gUnkJp_09A04C50,
    gUnkJp_09A0652C,
    gUnkJp_09A04C2C,
    gUnkJp_09A0652C,
    gUnkJp_09A04C0C,
    gUnkJp_09A0652C,
    gUnkJp_09A04BF0,
    gUnkJp_09A0652C,
    gUnkJp_09A04BCC,
    gUnkJp_09A0652C,
    gUnkJp_09A04BAC,
    gUnkJp_09A0652C,
    gUnkJp_09A04B90,
    gUnkJp_09A0652C,
    gUnkJp_09A04B6C,
    gUnkJp_09A0652C,
    gUnkJp_09A04B4C,
    gUnkJp_09A0652C,
    gUnkJp_09A04B30,
    gUnkJp_09A0652C,
    gUnkJp_09A04B10,
    gUnkJp_09A0652C,
    gUnkJp_09A04AEC,
    gUnkJp_09A0652C,
    gUnkJp_09A04AD0,
    gUnkJp_09A0652C,
    gUnkJp_09A04AAC,
    gUnkJp_09A0652C,
    gUnkJp_09A04A90,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04A60,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04A48,
    gUnkJp_09A06548,
    gUnkJp_09A05CA0,
    gUnkJp_09A0652C,
    gUnkJp_09A04A24,
    gUnkJp_09A0652C,
    gUnkJp_09A04A10,
    gUnkJp_09A0652C,
    gUnkJp_09A049E8,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A04A10,
    gUnkJp_09A0652C,
    gUnkJp_09A049DC,
    gUnkJp_09A0652C,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A049D8,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A049D4,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A049D0,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    gUnkJp_09A06548,
    gUnkJp_09A06504,
    0,
};

const s32* gUnk_09EFA934[17] = {
    gUnk_09A516C8,
    gUnk_09A51780,
    gUnk_09A51874,
    gUnk_09A51970,
    gUnk_09A51AB0,
    gUnk_09A51C24,
    gUnk_09A51D60,
    gUnk_09A51F94,
    gUnk_09A52084,
    gUnk_09A52248,
    gUnk_09A5233C,
    gUnk_09A52454,
    gUnk_09A52504,
    gUnk_09A52608,
    gUnk_09A5279C,
    gUnk_09A52868,
    gUnk_09A5295C,
};

const s32* gUnk_09EFA978[17] = {
    gUnk_09A52ABC,
    gUnk_09A52B88,
    gUnk_09A52C54,
    gUnk_09A52D04,
    gUnk_09A52DA0,
    gUnk_09A52E3C,
    gUnk_09A52EC4,
    gUnk_09A52F74,
    gUnk_09A530E8,
    gUnk_09A531AC,
    gUnk_09A53264,
    gUnk_09A5341C,
    gUnk_09A534F4,
    gUnk_09A535A4,
    gUnk_09A5362C,
    gUnk_09A536C8,
    gUnk_09A53778,
};

u8* gUnk_09EFA9BC = gUnkJp_09A06548;

u8* gUnk_09EFA9C0 = gUnkJp_09A09094;

#endif

#ifdef VERSION_EU

u8* gUnk_09EF9F54[688] = {
    gUnkEu_09AAF3F4,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3D8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3B0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3A0,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF384,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF370,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF358,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF348,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF330,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF310,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF300,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF2DC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF2BC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF2B0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF290,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF280,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF270,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF25C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF23C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF220,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF200,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF1E0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF1B8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF1AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF198,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF17C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF160,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF14C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF138,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF128,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF114,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF104,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF0E0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF0C0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF0AC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF098,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF084,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF064,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF040,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF020,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF000,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEFDC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEFB8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEFA4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF94,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF78,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF54,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF38,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF24,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF14,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEF04,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEEF4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEEE4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEEDC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEEC4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEEB0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEEA0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE94,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE80,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE74,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE60,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE50,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE38,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEE14,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEE04,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEDF8,
    gUnkEu_09AAEDF4,
    gUnkEu_09AAEDDC,
    gUnkEu_09AAEDC0,
    gUnkEu_09AAED98,
    gUnkEu_09AAED70,
    gUnkEu_09AAED48,
    gUnkEu_09AAED28,
    gUnkEu_09AAECFC,
    gUnkEu_09AAECD8,
    gUnkEu_09AAECBC,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAEC8C,
    gUnkEu_09AAEC64,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAEC44,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAEC0C,
    gUnkEu_09AAEC08,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEBEC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEBD8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEBC8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEBAC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB9C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB88,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB78,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEB64,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEB4C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB40,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEBD8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB30,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB24,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB14,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAFC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAF0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAE0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAD0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAB8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAAC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEA98,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEA88,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEA6C,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEA50,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEA40,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEAFC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEA2C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEA10,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE9FC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE9EC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE9DC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE9D0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE9C4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE9B4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE9A4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE990,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE97C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE970,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE964,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE954,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE948,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE93C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE92C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE91C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE90C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE8FC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE8EC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE8DC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEDF4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAE8C8,
    gUnkEu_09AAE890,
    gUnkEu_09AAE868,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAE850,
    gUnkEu_09AAE830,
    gUnkEu_09AAE80C,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAE7F8,
    gUnkEu_09AAE7C8,
    gUnkEu_09AAE7A0,
    gUnkEu_09AAE784,
    gUnkEu_09AAEC08,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE76C,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE758,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE748,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE73C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE730,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE724,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE714,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE704,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE6E4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE6D4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE6C0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE6B4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE694,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE68C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE668,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE658,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE638,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE628,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEE60,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE618,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE604,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE5F4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE5DC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE5CC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE5B8,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEB88,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE5A8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE598,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE584,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE574,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE564,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE548,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE538,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE51C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE4F8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE4EC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE4CC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE4B0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE4A0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE48C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE468,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAE458,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE444,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE428,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE40C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE3F0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE3E0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE3CC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAEB88,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE3BC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE3A0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE394,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE370,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE364,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE340,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE330,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE30C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE2FC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE2D8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE2C4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE2A0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE288,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE274,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE260,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE250,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE238,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE224,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE200,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE1F0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE1D0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE1C0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE1A0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE188,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE15C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE14C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE124,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE114,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE574,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE104,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE0F4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE0DC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE0D0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE0B0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE09C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE088,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE06C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE05C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE034,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE018,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAE004,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADFF4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADFE4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADFC4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADFA8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADF90,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADF80,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADF70,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADF48,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADF24,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADF0C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADEF8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADEE8,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADEBC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADE94,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADE80,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADE6C,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADE54,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADE30,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADE14,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADDF4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADDD0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADDB0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADD94,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADD74,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADD68,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADD44,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADD24,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADD04,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADCE4,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADCC0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADC9C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADC7C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADC60,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADC3C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADC1C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADC00,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADBDC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADBBC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADBA0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADB80,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADB5C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADB40,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADB1C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADB00,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADAF0,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADACC,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADA9C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADA84,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAEB24,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADA60,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADA4C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADA24,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADA4C,
    gUnkEu_09AAF3D4,
    gUnkEu_09AADA18,
    gUnkEu_09AAF3D4,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADA14,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADA10,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AADA0C,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    gUnkEu_09AAF3F0,
    gUnkEu_09AAF3AC,
    0,
};

const s32* gUnk_09EFA934[17] = {
    gUnk_09A516C8,
    gUnk_09A51780,
    gUnk_09A51874,
    gUnk_09A51970,
    gUnk_09A51AB0,
    gUnk_09A51C24,
    gUnk_09A51D60,
    gUnk_09A51F94,
    gUnk_09A52084,
    gUnk_09A52248,
    gUnk_09A5233C,
    gUnk_09A52454,
    gUnk_09A52504,
    gUnk_09A52608,
    gUnk_09A5279C,
    gUnk_09A52868,
    gUnk_09A5295C,
};

const s32* gUnk_09EFA978[17] = {
    gUnk_09A52ABC,
    gUnk_09A52B88,
    gUnk_09A52C54,
    gUnk_09A52D04,
    gUnk_09A52DA0,
    gUnk_09A52E3C,
    gUnk_09A52EC4,
    gUnk_09A52F74,
    gUnk_09A530E8,
    gUnk_09A531AC,
    gUnk_09A53264,
    gUnk_09A5341C,
    gUnk_09A534F4,
    gUnk_09A535A4,
    gUnk_09A5362C,
    gUnk_09A536C8,
    gUnk_09A53778,
};

u8* gUnk_09EFA9BC = gUnkEu_09AAF3F0;

u8* gUnk_09EFA9C0 = gUnkEu_09AB1F3C;

#endif

#ifdef VERSION_JP

const StaffRollScene gUnk_09A538D8[22] = {
    { 0, 1, 1, 0, 120, 0, -2048, gUnk_09CD1774, 5120, 0, gUnk_09D59A74, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 1, 0, 300, -1024, -1024, gUnk_09CD2B74, 11200, 0, gUnk_09D5A274, 2048, 0, gUnk_09D69614, 512, 0, 30720, 31744, 0, 1 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CD5734, 11200, 0, gUnk_09D5AA74, 2048, 0, gUnk_09D69814, 512, 0, 30720, 31744, 0, 2 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CD5734, 11200, 0, gUnk_09D5AA74, 2048, 0, gUnk_09D69814, 512, 0, 30720, 31744, 0, 3 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CD82F4, 11200, 0, gUnk_09D5B274, 2048, 0, gUnk_09D69A14, 512, 0, 30720, 9216, 0, 4 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CD82F4, 11200, 0, gUnk_09D5B274, 2048, 0, gUnk_09D69A14, 512, 0, 30720, 9216, 0, 5 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CDAEB4, 11200, 0, gUnk_09D5BA74, 2048, 0, gUnk_09D69C14, 512, 0, 36864, 9216, 0, 6 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CDAEB4, 11200, 0, gUnk_09D5BA74, 2048, 0, gUnk_09D69C14, 512, 0, 36864, 9216, 0, 7 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CDDA74, 11200, 0, gUnk_09D5C274, 2048, 0, gUnk_09D69E14, 512, 0, 26624, 31744, 0, 8 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CDDA74, 11200, 0, gUnk_09D5C274, 2048, 0, gUnk_09D69E14, 512, 0, 26624, 31744, 0, 9 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CE0634, 11200, 0, gUnk_09D5CA74, 2048, 0, gUnk_09D6A014, 512, 0, 30720, 9216, 0, 10 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CE0634, 11200, 0, gUnk_09D5CA74, 2048, 0, gUnk_09D6A014, 512, 0, 30720, 9216, 0, 11 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5D274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 52224, 0, 0 },
    { 1, 1, 1, 0, 300, 0, -1024, gUnk_09CE31F4, 11200, 0, gUnk_09D5DA74, 2048, 0, gUnk_09D6A214, 512, 0, 40960, 31744, 0, 12 },
    { 1, 1, 0, 0, 180, 0, 0, gUnk_09CE5DB4, 11200, 0, gUnk_09D5E274, 2048, 0, gUnk_09D6A414, 512, 0, 30720, 9216, 1, 13 },
    { 1, 0, 1, 0, 180, 0, 0, gUnk_09CE5DB4, 11200, 0, gUnk_09D5E274, 2048, 0, gUnk_09D6A414, 512, 0, 30720, 9216, 1, 14 },
    { 1, 1, 0, 0, 180, 0, 0, gUnk_09CE8974, 11200, 0, gUnk_09D5EA74, 2048, 0, gUnk_09D6A614, 512, 0, 34816, 33792, 0, 15 },
    { 1, 0, 1, 0, 180, 0, 0, gUnk_09CE8974, 11200, 0, gUnk_09D5EA74, 2048, 0, gUnk_09D6A614, 512, 0, 30720, 31744, 1, 16 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5F274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CEB534, 11200, 0, gUnk_09D5FA74, 2048, 0, gUnk_09D6A814, 512, 0, 30720, 9216, 0, 17 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09CEB534, 11200, 0, gUnk_09D5FA74, 2048, 0, gUnk_09D6A814, 512, 0, 30720, 9216, 0, 18 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09CEB534, 11200, 0, gUnk_09D5FA74, 2048, 0, gUnk_09D6A814, 512, 0, 30720, 9216, 0, 19 },
};

const StaffRollScene gUnk_09A53D50[22] = {
    { 0, 1, 1, 0, 120, 0, -2048, gUnk_09CD1774, 5120, 0, gUnk_09D59A74, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 1, 0, 300, -1024, -1024, gUnk_09CEE0F4, 11200, 0, gUnk_09D60274, 2048, 0, gUnk_09D6AA14, 512, 0, 30720, 31744, 0, 1 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CF0CB4, 11200, 0, gUnk_09D60A74, 2048, 0, gUnk_09D6AC14, 512, 0, 30720, 31744, 0, 2 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CF0CB4, 11200, 0, gUnk_09D60A74, 2048, 0, gUnk_09D6AC14, 512, 0, 30720, 31744, 0, 3 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CF3874, 11200, 0, gUnk_09D61274, 2048, 0, gUnk_09D6AE14, 512, 0, 30720, 9216, 0, 4 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CF3874, 11200, 0, gUnk_09D61274, 2048, 0, gUnk_09D6AE14, 512, 0, 30720, 9216, 0, 5 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CF6434, 11200, 0, gUnk_09D61A74, 2048, 0, gUnk_09D6B014, 512, 0, 36864, 9216, 0, 6 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CF6434, 11200, 0, gUnk_09D61A74, 2048, 0, gUnk_09D6B014, 512, 0, 36864, 9216, 0, 7 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CF8FF4, 11200, 0, gUnk_09D62274, 2048, 0, gUnk_09D6B214, 512, 0, 26624, 31744, 0, 8 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CF8FF4, 11200, 0, gUnk_09D62274, 2048, 0, gUnk_09D6B214, 512, 0, 26624, 31744, 0, 9 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CFBBB4, 11200, 0, gUnk_09D62A74, 2048, 0, gUnk_09D6B414, 512, 0, 30720, 9216, 0, 10 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CFBBB4, 11200, 0, gUnk_09D62A74, 2048, 0, gUnk_09D6B414, 512, 0, 30720, 9216, 0, 11 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5D274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 52224, 0, 0 },
    { 1, 1, 1, 0, 300, 0, -1024, gUnk_09CFE774, 11200, 0, gUnk_09D63274, 2048, 0, gUnk_09D6B614, 512, 0, 40960, 31744, 0, 12 },
    { 1, 1, 0, 0, 180, 0, 0, gUnk_09D01334, 11200, 0, gUnk_09D63A74, 2048, 0, gUnk_09D6B814, 512, 0, 30720, 9216, 1, 13 },
    { 1, 0, 1, 0, 180, 0, 0, gUnk_09D01334, 11200, 0, gUnk_09D63A74, 2048, 0, gUnk_09D6B814, 512, 0, 30720, 9216, 1, 14 },
    { 1, 1, 0, 0, 180, 0, 0, gUnk_09D03EF4, 11200, 0, gUnk_09D64274, 2048, 0, gUnk_09D6BA14, 512, 0, 34816, 33792, 0, 15 },
    { 1, 0, 1, 0, 180, 0, 0, gUnk_09D03EF4, 11200, 0, gUnk_09D64274, 2048, 0, gUnk_09D6BA14, 512, 0, 30720, 31744, 1, 16 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5F274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09D06AB4, 11200, 0, gUnk_09D64A74, 2048, 0, gUnk_09D6BC14, 512, 0, 30720, 9216, 0, 17 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09D06AB4, 11200, 0, gUnk_09D64A74, 2048, 0, gUnk_09D6BC14, 512, 0, 30720, 9216, 0, 18 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09D06AB4, 11200, 0, gUnk_09D64A74, 2048, 0, gUnk_09D6BC14, 512, 0, 30720, 9216, 0, 19 },
};

#else

const StaffRollScene gUnk_09A538D8[22] = {
    { 0, 1, 1, 0, 120, 0, -2048, gUnk_09CD1774, 5120, 0, gUnk_09D59A74, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 1, 0, 300, -1024, -1024, gUnk_09CD2B74, 11200, 0, gUnk_09D5A274, 2048, 0, gUnk_09D69614, 512, 0, 30720, 32768, 0, 1 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CD5734, 11200, 0, gUnk_09D5AA74, 2048, 0, gUnk_09D69814, 512, 0, 30720, 32768, 0, 2 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CD5734, 11200, 0, gUnk_09D5AA74, 2048, 0, gUnk_09D69814, 512, 0, 30720, 32768, 0, 3 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CD82F4, 11200, 0, gUnk_09D5B274, 2048, 0, gUnk_09D69A14, 512, 0, 30720, 11264, 0, 4 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CD82F4, 11200, 0, gUnk_09D5B274, 2048, 0, gUnk_09D69A14, 512, 0, 30720, 11264, 0, 5 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CDAEB4, 11200, 0, gUnk_09D5BA74, 2048, 0, gUnk_09D69C14, 512, 0, 36864, 10240, 0, 6 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CDAEB4, 11200, 0, gUnk_09D5BA74, 2048, 0, gUnk_09D69C14, 512, 0, 36864, 10240, 0, 7 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CDDA74, 11200, 0, gUnk_09D5C274, 2048, 0, gUnk_09D69E14, 512, 0, 26624, 32768, 0, 8 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CDDA74, 11200, 0, gUnk_09D5C274, 2048, 0, gUnk_09D69E14, 512, 0, 26624, 32768, 0, 9 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CE0634, 11200, 0, gUnk_09D5CA74, 2048, 0, gUnk_09D6A014, 512, 0, 30720, 10240, 0, 10 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CE0634, 11200, 0, gUnk_09D5CA74, 2048, 0, gUnk_09D6A014, 512, 0, 30720, 10240, 0, 11 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5D274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 1, 0, 300, 0, -1024, gUnk_09CE31F4, 11200, 0, gUnk_09D5DA74, 2048, 0, gUnk_09D6A214, 512, 0, 40960, 32768, 0, 12 },
    { 1, 1, 0, 0, 180, 0, 2048, gUnk_09CE5DB4, 11200, 0, gUnk_09D5E274, 2048, 0, gUnk_09D6A414, 512, 0, 30720, 7168, 1, 13 },
    { 1, 0, 1, 0, 180, 0, 2048, gUnk_09CE5DB4, 11200, 0, gUnk_09D5E274, 2048, 0, gUnk_09D6A414, 512, 0, 30720, 7168, 1, 14 },
    { 1, 1, 0, 0, 180, 0, -2048, gUnk_09CE8974, 11200, 0, gUnk_09D5EA74, 2048, 0, gUnk_09D6A614, 512, 0, 34816, 32768, 0, 15 },
    { 1, 0, 1, 0, 180, 0, -2048, gUnk_09CE8974, 11200, 0, gUnk_09D5EA74, 2048, 0, gUnk_09D6A614, 512, 0, 39936, 29696, 1, 16 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5F274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CEB534, 11200, 0, gUnk_09D5FA74, 2048, 0, gUnk_09D6A814, 512, 0, 30720, 10240, 0, 17 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09CEB534, 11200, 0, gUnk_09D5FA74, 2048, 0, gUnk_09D6A814, 512, 0, 30720, 10240, 0, 18 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09CEB534, 11200, 0, gUnk_09D5FA74, 2048, 0, gUnk_09D6A814, 512, 0, 30720, 10240, 0, 19 },
};

const StaffRollScene gUnk_09A53D50[22] = {
    { 0, 1, 1, 0, 120, 0, -2048, gUnk_09CD1774, 5120, 0, gUnk_09D59A74, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 1, 0, 300, -1024, -1024, gUnk_09CEE0F4, 11200, 0, gUnk_09D60274, 2048, 0, gUnk_09D6AA14, 512, 0, 30720, 32768, 0, 1 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CF0CB4, 11200, 0, gUnk_09D60A74, 2048, 0, gUnk_09D6AC14, 512, 0, 30720, 32768, 0, 2 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CF0CB4, 11200, 0, gUnk_09D60A74, 2048, 0, gUnk_09D6AC14, 512, 0, 30720, 32768, 0, 3 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CF3874, 11200, 0, gUnk_09D61274, 2048, 0, gUnk_09D6AE14, 512, 0, 30720, 11264, 0, 4 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CF3874, 11200, 0, gUnk_09D61274, 2048, 0, gUnk_09D6AE14, 512, 0, 30720, 11264, 0, 5 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CF6434, 11200, 0, gUnk_09D61A74, 2048, 0, gUnk_09D6B014, 512, 0, 36864, 10240, 0, 6 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CF6434, 11200, 0, gUnk_09D61A74, 2048, 0, gUnk_09D6B014, 512, 0, 36864, 10240, 0, 7 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09CF8FF4, 11200, 0, gUnk_09D62274, 2048, 0, gUnk_09D6B214, 512, 0, 26624, 32768, 0, 8 },
    { 1, 0, 1, 0, 180, -1024, -1024, gUnk_09CF8FF4, 11200, 0, gUnk_09D62274, 2048, 0, gUnk_09D6B214, 512, 0, 26624, 32768, 0, 9 },
    { 1, 1, 0, 0, 180, 0, 1024, gUnk_09CFBBB4, 11200, 0, gUnk_09D62A74, 2048, 0, gUnk_09D6B414, 512, 0, 30720, 10240, 0, 10 },
    { 1, 0, 1, 0, 180, 0, 1024, gUnk_09CFBBB4, 11200, 0, gUnk_09D62A74, 2048, 0, gUnk_09D6B414, 512, 0, 30720, 10240, 0, 11 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5D274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 1, 0, 300, 0, -1024, gUnk_09CFE774, 11200, 0, gUnk_09D63274, 2048, 0, gUnk_09D6B614, 512, 0, 40960, 32768, 0, 12 },
    { 1, 1, 0, 0, 180, 0, 0, gUnk_09D01334, 11200, 0, gUnk_09D63A74, 2048, 0, gUnk_09D6B814, 512, 0, 30720, 7168, 1, 13 },
    { 1, 0, 1, 0, 180, 0, 0, gUnk_09D01334, 11200, 0, gUnk_09D63A74, 2048, 0, gUnk_09D6B814, 512, 0, 30720, 7168, 1, 14 },
    { 1, 1, 0, 0, 180, 0, 0, gUnk_09D03EF4, 11200, 0, gUnk_09D64274, 2048, 0, gUnk_09D6BA14, 512, 0, 34816, 32768, 0, 15 },
    { 1, 0, 1, 0, 180, 0, 0, gUnk_09D03EF4, 11200, 0, gUnk_09D64274, 2048, 0, gUnk_09D6BA14, 512, 0, 39936, 29696, 1, 16 },
    { 0, 1, 1, 0, 120, 0, 0, gUnk_09CD1774, 5120, 0, gUnk_09D5F274, 2048, 0, gUnk_09D695F4, 32, 0, 30720, 51200, 0, 0 },
    { 1, 1, 0, 0, 180, -1024, -1024, gUnk_09D06AB4, 11200, 0, gUnk_09D64A74, 2048, 0, gUnk_09D6BC14, 512, 0, 30720, 10240, 0, 17 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09D06AB4, 11200, 0, gUnk_09D64A74, 2048, 0, gUnk_09D6BC14, 512, 0, 30720, 10240, 0, 18 },
    { 1, 0, 0, 0, 180, -1024, -1024, gUnk_09D06AB4, 11200, 0, gUnk_09D64A74, 2048, 0, gUnk_09D6BC14, 512, 0, 30720, 10240, 0, 19 },
};

#endif

const u8 gUnk_09A541C8[60] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x00, 0x06, 0x00, 0xE0, 0x00, 0x06, 0x0F, 0x00, 0x0D, 0x00,
    0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x20, 0x00,
};

#if defined(VERSION_US)
const u8 gUnkUs_09A54204[2] = "~";
#elif defined(VERSION_JP)
const u8 gUnkJp_09A09094[2] = "~";
#else
const u8 gUnkEu_09AB1F3C[2] = "~";
#endif

StaffRollWork* gStaffRollWork;

void func_081125BC(StaffRollWork* w) {
    w->unk_078 = 0;
    w->unk_07C = 0;
    w->unk_080 = 0;
    gBldCnt = 0;
    gBldY = 0;
}

u8 func_081125D8(StaffRollWork* w) {
    u8 result;

    result = 1;
    if (w->unk_080 >= w->unk_07C) {
        gBldCnt &= ~BLDCNT_EFFECT_MASK;
        result = 0;
    }

    return result;
}

void func_08112600(StaffRollWork* w) {
    u16 v;

    if (w->unk_080 < w->unk_07C) {
        v = ((w->unk_080 << 12) / w->unk_07C) << 8 >> 16;
        w->unk_080 = w->unk_080 + 1;
    } else {
        v = 16;
        gBldCnt &= ~BLDCNT_EFFECT_MASK;
        gBldAlpha = 0;
        gBldY = 0;
    }

    switch (w->unk_078) {
    case 0:
    case 2:
        gBldY = 16 - v;
        break;
    case 1:
    case 3:
        gBldY = v;
        break;
    case 4:
        gBldAlpha = v;
        break;
    case 5:
        gBldAlpha = 16 - v;
        break;
    }
}

void func_081126A8(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 0;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0xE0;
    gBldY = 16;
}

void func_081126D0(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 1;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0xE0;
    gBldY = 0;
}

void func_081126F8(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 4;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0x40;
    gBldAlpha = 0;
}

void func_08112720(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 5;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0x40;
    gBldAlpha = 16;
}

u8* func_08112748(StaffRollWork* w) {
    return &w->unk_13C[w->unk_0CC[w->unk_0D0 + 3] * 0x2C];
}

void func_08112768(StaffRollWork* w) {
    StaffRollLabelArg arg;
    EvtObj* e;
    s32 run;
    s32 x;
    s32 y;

    if (w->unk_0CC == 0) {
        return;
    }

    run = 1;

    while (run != 0) {
        if (w->unk_0D4 != w->unk_0CC[w->unk_0D0 + 2]) {
            switch (w->unk_0D8) {
            case 5:
                if (w->unk_0F4 > w->unk_0E0) {
                    x = w->unk_0E4 + (w->unk_0EC - w->unk_0E4) * w->unk_0E0 / w->unk_0F4;
                    y = w->unk_0E0;
                    y = w->unk_0E8 + (w->unk_0F0 - w->unk_0E8) * y / w->unk_0F4;
                } else {
                    x = w->unk_0EC;
                    y = w->unk_0F0;
                    w->unk_0D8 = -1;
                    w->unk_0E0 = 0;
                }
                e = (EvtObj*)&w->unk_13C[w->unk_0DC * 0x2C];
                EvtObjSetPos(e, x, y, 0);
                w->unk_0E0++;
                break;
            case 8:
                if (w->unk_0F4 <= w->unk_0E0) {
                    w->unk_0D8 = -1;
                    w->unk_0E0 = 0;
                }
                w->unk_0E0++;
                break;
            }
            break;
        }

        w->unk_0D8 = -1;
        w->unk_0E0 = 0;

        switch (w->unk_0CC[w->unk_0D0]) {
        case 0:
            run = 0;
            continue;
        case 1:
            w->unk_0D0 = 0;
            w->unk_0D4 = 0;
            continue;
        case 2:
            e = (EvtObj*)func_08112748(w);
            EvtObjSetAnim(e, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 3:
            e = (EvtObj*)func_08112748(w);
            func_0801CE00(e, w->unk_0CC[w->unk_0D0 + 4] | 0x400);
            break;
        case 4:
            e = (EvtObj*)func_08112748(w);
            EvtObjSetPos(e, w->unk_0CC[w->unk_0D0 + 4] << 8, w->unk_0CC[w->unk_0D0 + 5] << 8, 0);
            break;
        case 5:
            e = (EvtObj*)func_08112748(w);
            w->unk_0D8 = 5;
            w->unk_0DC = w->unk_0CC[w->unk_0D0 + 3];
            w->unk_0E4 = e->x;
            w->unk_0E8 = e->y;
            w->unk_0EC = w->unk_0CC[w->unk_0D0 + 4] << 8;
            w->unk_0F0 = w->unk_0CC[w->unk_0D0 + 5] << 8;
            w->unk_0F4 = w->unk_0CC[w->unk_0D0 + 6];
            break;
        case 6:
            w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3] =
                func_0801CE04(w->tasks2, &gTaskDescSrollBChar, (EvtObj*)func_08112748(w), w->unk_0CC[w->unk_0D0 + 4],
                              w->unk_0CC[w->unk_0D0 + 5], 0x2800, 0xF000, 0);
            break;
        case 7:
            func_08000DE8(w->tasks2, (void*)w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3]);
            break;
        case 8:
            w->unk_0D8 = 5;
            w->unk_0F4 = w->unk_0CC[w->unk_0D0 + 4];
            break;
        case 9:
            FadeStartIn(0, (u16)w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 10:
            FadeStartOut(0, (u16)w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 11:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            func_081126F8(w, 0x2000, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 12:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            func_08112720(w, 0x2000, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 13:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            break;
        case 14:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 &= 0xFFFB;
            break;
        case 15:
            e = (EvtObj*)func_08112748(w);
            arg.unk_00 = w->unk_0CC[w->unk_0D0 + 4];
            arg.x = e->x;
            arg.y = e->y;
            TaskCreate(w->tasks2, &gTaskDescSrollBCrtn, &arg);
            break;
        case 16:
            func_081149B0((void*)w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3],
                          w->unk_0CC[w->unk_0D0 + 4]);
            break;
        default:
            continue;
        }

        w->unk_0D0 += w->unk_0CC[w->unk_0D0 + 1];
    }

    w->unk_0D4++;
}

void mode_StaffRoll_0(void) {
    StaffRollWork* w;
    StaffRollWork** p;

    p = &gStaffRollWork;
    w = EwramAlloc(0x418);
    *p = w;
    SetBackdropColor(0, 0, 0);
    SpriteReset();
    w->palette = (u32)LoadObjPalette(gUnk_09D6BE74, 0x100);
    w->unk_000 = 1;
    w->unk_001 = 1;
    w->unk_008 = 0;
    w->unk_00C = 0;
    w->unk_010 = 0;
    w->unk_014 = 0;
    func_081125BC(w);
    w->unk_084 = 0;
    w->unk_08C = 0;
    w->unk_088 = 0;
    w->unk_090 = -1;
    w->unk_094 = 0;
    w->unk_098 = 0;
    w->unk_0A4 = 0;
    w->unk_0A0 = 0;
    w->unk_0A8 = 0;
    w->unk_0AC = 0;
    w->unk_0B0 = -1;
    w->unk_0B8 = 0;
    w->unk_0BC = 0;
    w->unk_0C0 = 0;
    w->unk_0C4 = 0;
    w->unk_0C8 = 0;
    w->unk_0CC = 0;
    w->unk_0D0 = 0;
    w->unk_0D4 = 0;
    w->unk_0D8 = -1;
    w->unk_0E0 = 0;
    TaskPoolInit(w->tasks, 32);
    TaskPoolInit(w->tasks2, 32);
    w->unk_124[0] = 0;
    w->unk_124[1] = 0;
    w->unk_124[2] = 0;
    w->unk_124[4] = 0;
    w->unk_124[5] = 0;
    *(s32*)w->unk_13C = 0;
}

u8 func_08112C24(StaffRollWork* w) {
    u8 result;

    result = 1;
    if (w->unk_00C > 74) {
        result = 0;
    }
    w->unk_00C++;

    return result;
}

u8 func_08112C38(StaffRollWork* w) {
    StaffRollTaskArg arg;
    u8 result;
    s32 z;

    result = 1;

    if ((gGameState.flags & 8) != 0) {
        w->scene = gUnk_09A53D50;
    } else {
        w->scene = gUnk_09A538D8;
    }

    switch (w->unk_084) {
    case 0:
        SetBgMode1();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 29, 0);
        SetupBg(2, 0, 30, 11);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0);
        SetBgSize(1, 0);
        SetBgSize(2, 0x4000);
        SetBgSize(3, 0x4000);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        SetBgColorMode(0, 0x80);

        if (w->unk_090 != w->unk_094) {
            w->unk_090 = w->unk_094;

            if (w->scene[w->unk_090].unk_00 == 1) {
                SetBgColorMode(0, 0x80);
            } else {
                SetBgColorMode(0, 0);
            }

            EnableBg(0);
            LoadBgTiles(0, w->scene[w->unk_090].tiles, w->scene[w->unk_090].tilesSize);
            LoadBgMap(0, w->scene[w->unk_090].map, w->scene[w->unk_090].mapSize);
            LoadBgPalette(0, w->scene[w->unk_090].palette, w->scene[w->unk_090].paletteSize);
            SetBgScroll(0, (u16) - (w->scene[w->unk_090].x >> 8),
                        (u16) - (w->scene[w->unk_090].y >> 8));
        }

        w->unk_084 = 1;
        w->unk_08C = 0;
    case 1:
    {
        u8 t;

            if (w->unk_08C == 0) {
                if (w->scene[w->unk_090].unk_01 == 1) {
                    func_081126A8(w, 17, 30);
                } else {
                    func_081126A8(w, 16, 30);
                }
                w->unk_08C++;
            }

            func_08112600(w);
            t = func_081125D8(w);
            if (t != 0) {
                break;
            }

            arg.unk_00 = t;
            arg.unk_02 = w->scene[w->unk_090].unk_30;
            arg.unk_04 = t;
            arg.x = 0x14000;
            arg.y = w->scene[w->unk_090].targetY;
            arg.targetX = w->scene[w->unk_090].targetX;
            arg.targetY = w->scene[w->unk_090].targetY;
            w->unk_124[0] = (s32)TaskCreate(w->tasks, &gTaskDescSrollAName, &arg);
            arg.unk_00 = 1;
            arg.unk_02 = 1;
            arg.unk_04 = w->scene[w->unk_090].unk_32;
            arg.x = -0x5000;
            z = 0x7800;
            arg.targetX = z;
            w->unk_124[1] = (s32)TaskCreate(w->tasks, &gTaskDescSrollAName, &arg);
            arg.unk_00 = 2;
            arg.unk_02 = w->scene[w->unk_090].unk_30;
            arg.unk_04 = w->scene[w->unk_090].unk_32;
            arg.x = z;
            w->unk_124[2] = (s32)TaskCreate(w->tasks, &gTaskDescSrollAName, &arg);
            w->unk_084 = 2;
            w->unk_08C = t;
            break;
    }
    case 2:
        w->unk_088++;
        if (w->unk_088 >= w->scene[w->unk_090].unk_04) {
            w->unk_084 = 3;
            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
        }
        if ((w->flags & 1) != 0 || (w->unk_004 & 0x100) != 0) {
            w->unk_084 = 3;
            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
        }
        if ((w->flags & 2) == 0) {
            break;
        }
        func_08000DE8(w->tasks, (void*)w->unk_124[0]);
        func_08000DE8(w->tasks, (void*)w->unk_124[1]);
        func_08000DE8(w->tasks, (void*)w->unk_124[2]);
        w->unk_010 = 0x1518;
        w->unk_084 = 4;
        w->unk_08C = 0;
        w->unk_088 = 0;
        break;
    case 3:
    {
        u8 t;

            if (w->unk_08C == 0) {
                if (w->scene[w->unk_090].unk_02 == 1) {
                    func_081126D0(w, 17, 30);
                } else {
                    func_081126D0(w, 16, 30);
                }
                w->unk_08C++;
            }

            func_08112600(w);
            t = func_081125D8(w);
            if (t != 0) {
                break;
            }

            if (w->scene[w->unk_090].unk_02 == 1) {
                DisableBg(0);
            }

            func_08000DE8(w->tasks, (void*)w->unk_124[0]);
            func_08000DE8(w->tasks, (void*)w->unk_124[1]);
            func_08000DE8(w->tasks, (void*)w->unk_124[2]);
            w->unk_094 = w->unk_090 + 1;

            if (w->unk_094 > 21) {
                w->unk_084 = 4;
            } else {
                w->unk_084 = t;
            }

            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
    }
    case 4:
    {
        s32 v;

        v = w->unk_098 + 64;
        w->unk_098 = v;

        if (v > 0x1BFF) {
            SetBgScroll(0, (u16) - (w->scene[w->unk_090].x >> 8),
                        (u16)(-(w->scene[w->unk_090].y >> 8) + 28));
            if (w->unk_098 > 0x4000) {
                w->unk_084 = 6;
                w->unk_08C = 0;
                w->unk_088 = 0;
            }
        } else {
            SetBgScroll(0, (u16) - (w->scene[w->unk_090].x >> 8),
                        (u16)(-(w->scene[w->unk_090].y >> 8) + (v >> 8)));
        }
        break;
    }
    case 5:
        break;
    case 6:
        if (w->unk_08C == 0) {
            func_081126D0(w, 17, 120);
            w->unk_08C++;
        }
        func_08112600(w);
        if (func_081125D8(w) == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

#ifdef VERSION_JP
#define STAFFROLL_SCROLL_FRAMES 0x4321
#define STAFFROLL_SCROLL_SPEED 0x16000000
#define STAFFROLL_SCRIPT_PERIOD 635
#else
#ifdef VERSION_EU
#define STAFFROLL_SCROLL_FRAMES 0x431C
#define STAFFROLL_SCROLL_SPEED 0x15800000
#define STAFFROLL_SCRIPT_PERIOD 635
#else
#define STAFFROLL_SCROLL_FRAMES 0x431C
#define STAFFROLL_SCROLL_SPEED 0x13C00000
#define STAFFROLL_SCRIPT_PERIOD 627
#endif
#endif

u8 func_08113180(StaffRollWork* w) {
    u8 buf[80];
    StaffRollLogoArg logo;
    StaffRollSecnArg secn;
    u8 result;
    s32 i;
    u32 row;
    u8* s;
    s32 loop;
    s32 x;
    u32 y;
    s32 total;
    s32 wa;
    s32 wb;
    s32 wc;
    s32 w1;
    s32 n;
    s32 t;
    s32 sub;
    s32 idx;

    result = 1;

    switch (w->unk_0A4) {
    case 0:
        func_081125BC(w);
        SetBgMode1();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 29, 0);
        SetupBg(2, 0, 30, 11);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0);
        SetBgSize(1, 0);
        SetBgSize(2, 0x4000);
        SetBgSize(3, 0x4000);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);

        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 1);
        }

        SrollTextInit(w->unk_1C0, gUnk_09A541C8);
        LoadBgPalette(0, gUnk_09D6BE14, 32);
        (*(volatile u16*)&gDispCnt) |= 0;
        gWinIn = (WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ);
        gWinOut = (WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
        gWin0H = 0x10E0;
        gWin0V = 0x898;
        w->unk_0A4 = 1;
        w->unk_0A8 = 0;
    case 1:
        w->unk_0B4 = STAFFROLL_SCROLL_SPEED / ((STAFFROLL_SCROLL_FRAMES - w->unk_010) << 8);
        w->unk_0A4 = 2;
        w->unk_0A8 = 0;
        break;
    case 2:
        w->unk_0B8 += w->unk_0B4;
        sub = w->unk_0B8 >> 8;
        row = w->unk_0B8 >> 11;

        if (sub % 8 == 0 && w->unk_0B0 != row) {
            s = gUnk_09EF9F54[row];

            if (w->unk_0A0 == 0 && s == 0) {
                w->unk_0B4 = 0;
                w->unk_0A0 = 1;
            }

            if (*s != '!') {
                SrollTextClearRect(w->unk_1C0, 0, (row + 20) & 31, 30, 2, 1);
            }

            if (w->unk_0A0 == 0) {
                SrollTextSetColors(w->unk_1C0, 15, 13, 0, 14);
                loop = 1;

                while (loop) {
                    switch (*s) {
                    case '!':
                        loop = 0;
                        break;
                    case '*':
                        switch (s[1]) {
                        case 'D':
                            logo.unk_10 = 0;
                            break;
                        case 'S':
                            logo.unk_10 = 1;
                            break;
                        case 'J':
                            logo.unk_10 = 2;
                            break;
                        }
                        logo.unk_00 = 0x7800;
                        logo.unk_04 = ((w->unk_0B8 >> 8) + 168) << 8;
                        logo.unk_08 = &w->unk_0B8;
                        logo.unk_0C = &w->unk_0B4;
                        TaskCreate(w->tasks2, &gTaskDescSrollBLogo, &logo);
                        loop = 0;
                        break;
                    case '<':
                        secn.unk_00 = w->unk_014;
                        secn.unk_04 = 0x17800;
                        secn.unk_08 = ((w->unk_0B8 >> 8) + 168) << 8;
                        secn.unk_0C = &w->unk_0B8;
                        secn.unk_10 = &w->unk_0B4;
                        TaskCreate(w->tasks2, &gTaskDescSrollBSecn, &secn);
                        w->unk_014++;
                        loop = 0;
                        break;
                    case '[':
                        secn.unk_00 = -1;
                        secn.unk_04 = 0x7800;
                        secn.unk_08 = ((w->unk_0B8 >> 8) + 168) << 8;
                        secn.unk_0C = &w->unk_0B8;
                        secn.unk_10 = &w->unk_0B4;
                        TaskCreate(w->tasks2, &gTaskDescSrollBSecn, &secn);
                        loop = 0;
                        break;
                    case '#':
                        SrollTextSelectFont(w->unk_1C0, s[1] - '0');
                        s += 2;
                        break;
                    case '@':
                        SrollTextSetColors(w->unk_1C0, 7, 5, 0, 6);
                        s++;
                        break;
                    case '~':
                        s++;
                        wa = SrollTextMeasureWidth(w->unk_1C0, s);
                        wb = SrollTextMeasureWidth(w->unk_1C0, gUnk_09EFA9C0);
                        wc = SrollTextMeasureWidth(w->unk_1C0, gUnk_09EFA9BC);
                        w1 = wa - wb + wc * 3;
                        x = (240 - w1) >> 1;
                        SrollTextSetColors(w->unk_1C0, 7, 5, 0, 6);

                        for (n = 0; s[n] != '~'; n++) {
                            buf[n] = s[n];
                        }

                        buf[n] = ' ';
                        buf[n + 1] = ' ';
                        buf[n + 2] = ' ';
                        buf[n + 3] = 0;
                        w1 = SrollTextMeasureWidth(w->unk_1C0, buf);
                        SrollTextDrawStringAtPixelX(w->unk_1C0, x, (row + 20) & 31, buf, 1);
                        s += n + 1;

                        for (n = 0; s[n] != 0; n++) {
                            buf[n] = s[n];
                        }

                        buf[n] = 0;
                        SrollTextSetColors(w->unk_1C0, 15, 13, 0, 14);
                        SrollTextDrawStringAtPixelX(w->unk_1C0, x + w1, (row + 20) & 31, buf, 1);
                        loop = 0;
                        break;
                    case '=':
                        SrollTextDrawStringAtPixelX(w->unk_1C0, (240 - SrollTextMeasureWidth(w->unk_1C0, s + 1)) >> 1, (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    case '-':
                        SrollTextDrawStringAtPixelX(w->unk_1C0, 0, (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    case '+':
                        SrollTextDrawStringAtPixelX(w->unk_1C0, 240 - SrollTextMeasureWidth(w->unk_1C0, s + 1), (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    default:
                        SrollTextDrawStringAtPixelX(w->unk_1C0, (240 - SrollTextMeasureWidth(w->unk_1C0, s)) >> 1, (row + 20) & 31, s, 1);
                        loop = 0;
                        break;
                    }
                }
            }
        }

        w->unk_0B0 = row;
        t = w->unk_0A8;

        if (t % STAFFROLL_SCRIPT_PERIOD == 60) {
            w->unk_0CC = 0;
            idx = t / STAFFROLL_SCRIPT_PERIOD;

            if (idx <= 16) {
                if ((gGameState.flags & 8) != 0) {
                    w->unk_0CC = gUnk_09EFA978[idx];
                } else {
                    w->unk_0CC = gUnk_09EFA934[idx];
                }
            }

            w->unk_0D0 = 0;
            w->unk_0D4 = 0;
            w->unk_0D8 = -1;
            w->unk_0E0 = 0;
        }

        w->unk_0A8++;
        SetBgScroll(0, 0, (u16)(w->unk_0B8 >> 8));

        if (w->unk_010 >= STAFFROLL_SCROLL_FRAMES || (w->flags & 2) != 0) {
            w->unk_0A4 = 4;
            w->unk_0A8 = 0;
        }
        break;
    case 4:
        w->unk_0A8++;
        if (w->unk_0A8 > 120) {
            w->unk_0A4 = 3;
            w->unk_0A8 = 0;
        }
        break;
    case 3:
        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 0);
        }

        (*(volatile u16*)&gDispCnt) &= ~DISPCNT_WIN0_ON;
        gWinIn = 0;
        gWinOut = 0;
        gWin0H = 0;
        gWin0V = 0;
        result = 0;
        break;
    }

    func_08112768(w);
    TaskPoolUpdate(w->tasks2);
    TaskPoolDraw(w->tasks2);
    func_08112600(w);

    return result;
}

u8 func_0811394C(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0A4) {
    case 0:
        TaskPoolDestroy(w->tasks2);
        DisableBg(0);
        DisableBg(1);
        EnableBg(2);
        DisableBg(3);
        LoadBgTiles(2, gUnk_097CF758, 0x3F00);
        LoadBgMap(2, gUnk_0983FB98, 0x400);
        LoadBgPalette(2, gUnk_0984A618, 0xA0);
        SetBgAffine(2, 0, 0x100, 0x100, 0x7800, 0x5C00);
        w->unk_0A4 = 1;
        w->unk_0A8 = 0;
        break;
    case 1:
        if (w->unk_0A8 == 0) {
            FadeStartIn(0, 1);
            w->unk_0A8++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0A4 = 2;
            w->unk_0A8 = 0;
        }
        break;
    case 2:
        w->unk_0A8++;
        if (w->unk_0A8 > 179) {
            w->unk_0A4 = 3;
            w->unk_0A8 = 0;
        }
        break;
    case 3:
        if (w->unk_0A8 == 0) {
            FadeStartOut(0, 120);
            w->unk_0A8++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0A4 = 4;
            w->unk_0A8 = 0;
        }
        break;
    case 4:
        w->unk_0A8++;
        if (w->unk_0A8 > 119) {
            BlockAudioStop();
            result = 0;
        }
        break;
    }

    return result;
}

#ifdef VERSION_JP
#define STAFFROLL_HOLD_FRAMES 720
#else
#define STAFFROLL_HOLD_FRAMES 900
#endif

u8 func_08113A94(StaffRollWork* w) {
    u8 result;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
        break;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(0, 60);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            if ((gGameState.flags & 8) != 0) {
                w->unk_124[0] = (s32)TaskCreate(w->tasks, &gTaskDescSrollCChar, (void*)1);
            } else {
                w->unk_124[0] = (s32)TaskCreate(w->tasks, &gTaskDescSrollCChar, (void*)0);
            }
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if ((gGameState.flags & 8) != 0) {
            if (w->unk_0C0 >= STAFFROLL_HOLD_FRAMES) {
                w->unk_0BC = 3;
                w->unk_0C0 = 0;
            }
        } else {
            if (w->unk_0C0 >= 900) {
                w->unk_0BC = 3;
                w->unk_0C0 = 0;
            }
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(0, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113BB4(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        if (w->unk_0C0 <= 119) {
            w->unk_0C0++;
            break;
        }
        SetBgMode0();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(2, 0, 31, 0);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0x8000);
        SetBgSize(1, 0);
        SetBgSize(2, 0);
        SetBgSize(3, 0);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        LoadBgTiles(0, gUnk_09D09674, 0x7200);
        LoadBgMap(0, gUnk_09D65274, 0x1000);
        LoadBgPalette(0, gUnk_09D6BF74, 0x200);
        SetBgScroll(0, 0, 160);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(0, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        SetBgScroll(0, 0, (u16)(160 - (w->unk_0C0 >> 1)));
        if (w->unk_0C0 <= 255) {
            w->unk_0C0++;
        }
        if (w->unk_0C0 > 255) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 4;
            w->unk_0C0 = 0;
        }
        break;
    case 4:
        if (w->unk_0C0 == 0) {
            SetBackdropColor(31, 31, 31);
            FadeStartOut(1, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            SetBgScroll(0, 0, 0);
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113DB8(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D10874, 0x53C0);
        LoadBgMap(0, gUnk_09D66274, 0x800);
        LoadBgPalette(0, gUnk_09D6C174, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(1, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            SetBackdropColor(0, 0, 0);
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(0, 60);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113E94(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        if (w->unk_0C0 <= 119) {
            w->unk_0C0++;
            break;
        }
        SetBgMode0();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(2, 0, 31, 0);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0x8000);
        SetBgSize(1, 0);
        SetBgSize(2, 0);
        SetBgSize(3, 0);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        LoadBgTiles(0, gUnk_09D15C34, 0x53C0);
        LoadBgMap(0, gUnk_09D66A74, 0x800);
        LoadBgPalette(0, gUnk_09D6C374, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(0, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            SetBackdropColor(31, 31, 31);
            FadeStartOut(1, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08114048(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D1AFF4, 0x53C0);
        LoadBgMap(0, gUnk_09D67274, 0x800);
        LoadBgPalette(0, gUnk_09D6C574, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(1, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(1, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_0811411C(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D203B4, 0x53C0);
        LoadBgMap(0, gUnk_09D67A74, 0x800);
        LoadBgPalette(0, gUnk_09D6C774, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(1, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            SetBackdropColor(0, 0, 0);
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(0, 60);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_081141F8(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0C4) {
    case 0:
        DisableBg(0);
        EnableBg(1);
        DisableBg(2);
        DisableBg(3);
        SetBgScroll(1, 0, 0);
        SetBgColorMode(1, 0x80);

        if ((gGameState.flags & 8) != 0) {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                LoadBgMap(1, gUnkEu_09DD69A0, 0x800);
                break;
            case 1:
                LoadBgMap(1, gUnkEu_09DD71A0, 0x800);
                break;
            case 4:
                LoadBgMap(1, gUnkEu_09DD79A0, 0x800);
                break;
            case 3:
                LoadBgMap(1, gUnkEu_09DD81A0, 0x800);
                break;
            case 2:
            default:
                LoadBgMap(1, gUnkEu_09DD89A0, 0x800);
                break;
            }
            LoadBgTiles(1, gUnk_09D2B334, 0x45C0);
            LoadBgPalette(1, gUnk_09D6CB74, 0x200);
#else
            LoadBgTiles(1, gUnk_09D2B334, 0x7F40);
            LoadBgMap(1, gUnk_09D68A74, 0x800);
            LoadBgPalette(1, gUnk_09D6CB74, 0x200);
#endif
        } else {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                LoadBgMap(1, gUnk_09D68274, 0x800);
                break;
            case 1:
                LoadBgMap(1, gUnk_09D68A74, 0x800);
                break;
            case 4:
                LoadBgMap(1, gUnkEu_09DD51A0, 0x800);
                break;
            case 3:
                LoadBgMap(1, gUnkEu_09DD59A0, 0x800);
                break;
            case 2:
            default:
                LoadBgMap(1, gUnkEu_09DD61A0, 0x800);
                break;
            }
            LoadBgTiles(1, gUnk_09D25774, 0x5140);
            LoadBgPalette(1, gUnk_09D6C974, 0x200);
#else
            LoadBgTiles(1, gUnk_09D25774, 0x5BC0);
            LoadBgMap(1, gUnk_09D68274, 0x800);
            LoadBgPalette(1, gUnk_09D6C974, 0x200);
#endif
        }

        m4aSongNumStart(SONG_BGM_TITLE);
        w->unk_0C4 = 1;
        w->unk_0C8 = 0;
        break;
    case 1:
        w->unk_0C8++;
        if (w->unk_0C8 > 59) {
            w->unk_0C4 = 2;
            w->unk_0C8 = 0;
        }
        break;
    case 2:
        if (w->unk_0C8 == 0) {
            FadeStartIn(0, 120);
            w->unk_0C8++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0C4 = 3;
            w->unk_0C8 = 0;
        }
        break;
    default:
        if ((GetKeysPressed() & (A_BUTTON | START_BUTTON)) != 0) {
            result = 0;
        }
        break;
    }

    return result;
}

void mode_StaffRoll_1(void) {
    StaffRollWork* w;
    u16 tmp;

    w = gStaffRollWork;
    w->unk_004 = 0;
    w->flags = 0;

    switch (w->unk_008) {
    case 0:
        if (func_08112C24(w) != 0) {
            break;
        }
        w->unk_008 = 1;
        w->unk_00C = 0;
        w->unk_010 = 0;
        BlockAudioStart();
    case 1:
    {
        vu32* dma;

        if (func_08112C38(w) != 0) {
            break;
        }
        w->unk_008 = 2;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0A4 = 0;
        w->unk_0A8 = 0;
        break;
    }
    case 2:
    {
        vu32* dma;

        if (func_08113180(w) != 0) {
            break;
        }
        w->unk_008 = 3;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0A4 = 0;
        w->unk_0A8 = 0;
        break;
    }
    case 3:
    {
        vu32* dma;

        if (func_0811394C(w) != 0) {
            break;
        }
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        if ((gGameState.flags & 8) != 0) {
            w->unk_008 = 7;
            w->unk_0BC = 0;
        } else {
            w->unk_008 = 5;
            w->unk_0BC = 0;
        }
        w->unk_00C = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 4:
    {
        vu32* dma;

        if (func_08113A94(w) != 0) {
            break;
        }
        w->unk_008 = 10;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        w->unk_0C4 = 0;
        w->unk_0C8 = 0;
        break;
    }
    case 5:
    {
        vu32* dma;

        if (func_08113BB4(w) != 0) {
            break;
        }
        w->unk_008 = 6;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 6:
    {
        vu32* dma;

        if (func_08113DB8(w) != 0) {
            break;
        }
        w->unk_008 = 4;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 7:
    {
        vu32* dma;

        if (func_08113E94(w) != 0) {
            break;
        }
        w->unk_008 = 8;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 8:
    {
        vu32* dma;

        if (func_08114048(w) != 0) {
            break;
        }
        w->unk_008 = 9;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 9:
    {
        vu32* dma;

        if (func_0811411C(w) != 0) {
            break;
        }
        w->unk_008 = 4;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 10:
        if (func_081141F8(w) != 0) {
            break;
        }
        w->unk_008 = 11;
        w->unk_00C = 0;
        break;
    case 11:
        if (w->unk_00C == 0) {
            FadeStartOut(0, 120);
        }
        w->unk_00C++;
        if (w->unk_00C > 120) {
#ifdef VERSION_EU
            eu_0800115C();
#else
            SoftReset(0xFF);
#endif
        }
        break;
    }

    TaskPoolUpdate(w->tasks);
    TaskPoolDraw(w->tasks);
    BlockAudioUpdate();
    w->unk_010++;
}

void mode_StaffRoll_2(void) {
    StaffRollWork* w;

    w = gStaffRollWork;
    ReleaseObjPalette((void*)w->palette);
    TaskPoolDestroy(w->tasks);

    if (gStaffRollWork != 0) {
        EwramFree(w);
        gStaffRollWork = 0;
    }
}

s32 func_08114748(s32 x) {
    return x * x;
}

s32 func_08114750(s32 x) {
    return x * x;
}

const char gModeNameStaffRoll[] = "mode_StaffRoll";

Mode gModeStaffRoll = {
    gModeNameStaffRoll,
    (void (*)(s32))mode_StaffRoll_0,
    mode_StaffRoll_1,
    mode_StaffRoll_2,
};
