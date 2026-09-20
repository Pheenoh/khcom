#include "mode_test_data.h"
#include "mode_test_assets.h"
#include "mode_test.h"
#include "card_localized_data.h"

u8* gUnk_09EE26EC[2] __attribute__((section(".data_fonts"))) = { gUnk_08F6E190, gUnk_08F6F190 };
u8* gUnk_09EE26F4 __attribute__((section(".data_fonts"))) = gUnk_08F70AAC;
u8* gUnk_09EE26F8 __attribute__((section(".data_fonts"))) = gUnk_08F70AA8;
u8* gUnk_09EE26FC __attribute__((section(".data_fonts"))) = gUnk_08F70AA4;
u8* gUnk_09EE2700 __attribute__((section(".data_fonts"))) = gUnk_08F70AA0;

Mode gUnk_09EE2704 __attribute__((section(".data_deck_menu"))) = { gModeNameDeck, (void (*)(s32))func_08060A74, func_08060AD8, func_08060BAC };

TaskDesc gUnk_09EE2714 __attribute__((section(".data_deck_menu"))) = { gTaskNameMenu, (void (*)(void*, void*))menu_0, menu_1, (void (*)(void*))menu_2, (void (*)(void*))menu_3, sizeof(MenuWork) };

#ifdef VERSION_EU
void* gUnkEu_09F5D574[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_091078AE, gUnkEu_0910DD2E, gUnkEu_09121002, gUnkEu_0911AB16, gUnkEu_09114860 };
void** gUnkEu_09F5D588[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F753D0, gUnkEu_09F75498, gUnkEu_09F756F0, gUnkEu_09F75628, gUnkEu_09F75560 };
void* gUnkEu_09F5D59C[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09127204, gUnkEu_091292D6, gUnkEu_0912F83E, gUnkEu_0912D736, gUnkEu_0912B47C };
void** gUnkEu_09F5D5B0[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F757B8, gUnkEu_09F757FC, gUnkEu_09F758C8, gUnkEu_09F75884, gUnkEu_09F75840 };
void* gUnkEu_09F5D5C4[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09131BFE, gUnkEu_091367CC, gUnkEu_0914583A, gUnkEu_091407A2, gUnkEu_0913B7F4 };
void** gUnkEu_09F5D5D8[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F7590C, gUnkEu_09F759B8, gUnkEu_09F75BBC, gUnkEu_09F75B10, gUnkEu_09F75A64 };
void* gUnkEu_09F5D5EC[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_0914A2E4, gUnkEu_0914B41E, gUnkEu_0914E89E, gUnkEu_0914D7B0, gUnkEu_0914C648 };
void** gUnkEu_09F5D600[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F75C68, gUnkEu_09F75C8C, gUnkEu_09F75CF8, gUnkEu_09F75CD4, gUnkEu_09F75CB0 };
void* gUnkEu_09F5D614[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09160A0E, gUnkEu_09160C2A, gUnkEu_091611C8, gUnkEu_09160FE8, gUnkEu_09160E46 };
void** gUnkEu_09F5D628[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F75F38, gUnkEu_09F75F40, gUnkEu_09F75F58, gUnkEu_09F75F50, gUnkEu_09F75F48 };
void* gUnkEu_09F5D63C[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_0915E7D4, gUnkEu_0915EDDA, gUnkEu_091602F4, gUnkEu_0915FC28, gUnkEu_0915F468 };
void** gUnkEu_09F5D650[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F75EE8, gUnkEu_09F75EF8, gUnkEu_09F75F28, gUnkEu_09F75F18, gUnkEu_09F75F08 };
void* gUnkEu_09F5D664[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_0914FAD6, gUnkEu_091519CE, gUnkEu_091581F6, gUnkEu_09155EFE, gUnkEu_09153BC6 };
void** gUnkEu_09F5D678[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F75D1C, gUnkEu_09F75D5C, gUnkEu_09F75E1C, gUnkEu_09F75DDC, gUnkEu_09F75D9C };
void* gUnkEu_09F5D68C[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_0915A27A, gUnkEu_0915B004, gUnkEu_0915DAD4, gUnkEu_0915CC96, gUnkEu_0915BE46 };
void** gUnkEu_09F5D6A0[5] __attribute__((section(".data_eu_card_labels"))) = { gUnkEu_09F75E5C, gUnkEu_09F75E78, gUnkEu_09F75ECC, gUnkEu_09F75EB0, gUnkEu_09F75E94 };
#endif
