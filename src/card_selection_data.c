#include "card_selection_data.h"
#include "mode_battle_data.h"
#include "card_sprite_data.h"

extern const u16 gUnk_096102B8[];
#ifdef VERSION_EU
extern u8 gUnk_093F6734[];
extern u8 gUnkEu_094C9860[];
extern u8 gUnkEu_094C9C20[];
#endif

const void* gUnk_09EE4BB0[2] __attribute__((section(".data_card_selection_09EE4BB0"), aligned(4))) = {
    gUnk_08125E24, gUnk_096102B8,
};

s16 gUnk_09EE4BB8[5] __attribute__((section(".data_card_selection_09EE4BB8"), aligned(2))) = {
    59, 99, 139, 179, 219,
};

s16 gUnk_09EE4BC2[2] __attribute__((section(".data_card_selection_09EE4BC2"), aligned(2))) = {
    88, 112,
};

u16 gUnk_09EE4BE0[10] __attribute__((section(".data_card_selection_09EE4BE0"), aligned(2))) = {
    72, 77, 82, 87, 92, 168, 173, 178, 183, 188,
};

#ifdef VERSION_EU
void* gUnkEu_09F6FF30[5] __attribute__((section(".data_card_selection_09F6FF30"), aligned(4))) = {
    gUnk_093F6734, gUnkEu_094C9860, gUnk_093F6734, gUnkEu_094C9860, gUnkEu_094C9C20,
};

void** gUnkEu_09F6FF44[5] __attribute__((section(".data_card_selection_09F6FF44"), aligned(4))) = {
    gUnk_09EF11F8, gUnkEu_09F7C454, gUnk_09EF11F8, gUnkEu_09F7C454, gUnkEu_09F7C47C,
};

void** gUnkEu_09F6FF70[5] __attribute__((section(".data_card_selection_09F6FF70"), aligned(4))) = {
    gUnk_09EF1228, gUnkEu_09F7C414, gUnkEu_09F7C42C, gUnkEu_09F7C424, gUnkEu_09F7C41C,
};

u16 gUnkEu_090CED64[5] __attribute__((section(".data_card_selection_090CED64"), aligned(2))) = {
    864, 864, 864, 864, 864,
};

#endif
