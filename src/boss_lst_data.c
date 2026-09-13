#include "boss_lst_data.h"

const s8 gUnk_09A4FBF4[33] __attribute__((section(".rodata_lst_shake"), aligned(1))) = {
    4, 4, 4, 4, -4, -4, -4, -4, 3, 3, 3, 3, -3, -3, -3, -3, 2, 2, 2, 2, -2, -2, -2, -2, 1, 1, 1, 1, -1, -1, -1, -1, 0,
};

const s8 gUnk_09A4FC15[9] __attribute__((section(".rodata_lst_shake"), aligned(1))) = {
    1, 2, 2, 1, -1, -2, -2, -1, 0,
};

const s8* const gUnk_09EF9E6C[2] __attribute__((section(".rodata_lst_shake_index"))) = { gUnk_09A4FBF4, gUnk_09A4FC15 };

LstAnimSet gUnk_09EF9EA4[4] __attribute__((section(".data_lst_anim_set"))) = {
    { 5, 0, 4, 5 },
    { 5, 0, 4, 12 },
    { 5, 0, 4, 13 },
    { 5, 0, 4, 14 },
};
