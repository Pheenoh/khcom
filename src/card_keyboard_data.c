#include "card_keyboard_data.h"
#include "card_keyboard_text.h"

#ifdef VERSION_US
const u8* gUnk_09EE4B0C[7] __attribute__((section(".data_card_keyboard_gUnk_09EE4B0C"), aligned(4))) = {
    gKeyboardTextUs_09035742,
    gKeyboardTextUs_09035762,
    gKeyboardTextUs_0903577A,
    gKeyboardTextUs_0903579A,
    gKeyboardTextUs_090357B2,
    gKeyboardTextUs_090357D2,
    gKeyboardTextUs_090357F2,
};

#endif

#ifdef VERSION_JP
const u8* gUnk_09EE4B0C[7] __attribute__((section(".data_card_keyboard_gUnk_09EE4B0C"), aligned(4))) = {
    gKeyboardTextJp_09008AE0,
    gKeyboardTextJp_09008AC0,
    gKeyboardTextJp_09008AA0,
    gKeyboardTextJp_09008A88,
    gKeyboardTextJp_09008A68,
    gKeyboardTextJp_09008A48,
    gKeyboardTextJp_09008A2C,
};

const u8* gUnkJp_09EBC148[7] __attribute__((section(".data_card_keyboard_gUnkJp_09EBC148"), aligned(4))) = {
    gKeyboardTextJp_09008BB4,
    gKeyboardTextJp_09008B94,
    gKeyboardTextJp_09008B74,
    gKeyboardTextJp_09008B5C,
    gKeyboardTextJp_09008B3C,
    gKeyboardTextJp_09008B1C,
    gKeyboardTextJp_09008B00,
};

const u8* gUnkJp_09EBC164[7] __attribute__((section(".data_card_keyboard_gUnkJp_09EBC164"), aligned(4))) = {
    gKeyboardTextJp_09008C84,
    gKeyboardTextJp_09008C64,
    gKeyboardTextJp_09008C44,
    gKeyboardTextJp_09008C24,
    gKeyboardTextJp_09008C0C,
    gKeyboardTextJp_09008BEC,
    gKeyboardTextJp_09008BD4,
};

#endif

#ifdef VERSION_EU
const u8* gUnkEu_09F6FE6C[8] __attribute__((section(".data_card_keyboard_gUnkEu_09F6FE6C"), aligned(4))) = {
    gKeyboardTextEu_090CEA56,
    gKeyboardTextEu_090CEA66,
    gKeyboardTextEu_090CEA72,
    gKeyboardTextEu_090CEA82,
    gKeyboardTextEu_090CEA8E,
    gKeyboardTextEu_090CEA9E,
    gKeyboardTextEu_090CEAA9,
    gKeyboardTextEu_090CEAB9,
};

const u8* gUnkEu_09F6FE8C[7] __attribute__((section(".data_card_keyboard_gUnkEu_09F6FE8C"), aligned(4))) = {
    gKeyboardTextEu_090CEAC4,
    gKeyboardTextEu_090CEAD4,
    gKeyboardTextEu_090CEADF,
    gKeyboardTextEu_090CEAEF,
    gKeyboardTextEu_090CEAFF,
    gKeyboardTextEu_090CEB05,
    gKeyboardTextEu_090CEB15,
};

#endif
