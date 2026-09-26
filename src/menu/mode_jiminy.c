#include "sprites_msg.h"
#include "jiminy_journal.h"
#include "sprites_bos5.h"
#include "worldinspect_assets.h"
#include "card_def_assets.h"
#include "task_animation_assets.h"
#include "sprites_emy.h"
#include "sprites_evt.h"
#include "sprites_smn.h"
#include "sprites_worldinspect.h"
#include "sprites_card_pictures.h"
#include "sprites_card.h"
#include "hum.h"

const JiminyEntry gUnk_08155554[21] = {
    { gUnk_08F62384, gUnk_09EDDECC, 3, -1, gUnk_0815552E, 0, 0 },
    { gUnk_08F61384, gUnk_09EDDED8, 17, 0, 0, gUnk_081552B0, 1 },
    { gUnk_08F5E384, gUnk_09EDDF1C, 7, 0, gUnk_0815553A, 0, 0 },
    { gUnk_08F5F384, gUnk_09EDDF38, 3, 0, gUnk_08155534, 0, 0 },
    { gUnk_08F5E384, gUnk_09EDDF44, 17, 2, 0, gUnk_0815539A, 2 },
    { gUnk_08F5E384, gUnk_09EDDF88, 14, 2, 0, gUnk_081553BC, 3 },
    { gUnk_08F5E384, gUnk_09EDDFC0, 7, 2, 0, gUnk_081553D8, 4 },
    { gUnk_08F5E384, gUnk_09EDDFDC, 7, 2, 0, gUnk_081553E6, 5 },
    { gUnk_08F5E384, gUnk_09EDDFF8, 49, 2, 0, gUnk_081553F4, 6 },
    { gUnk_08F5E384, gUnk_09EDE0BC, 26, 2, 0, gUnk_08155456, 7 },
    { gUnk_08F5E384, gUnk_09EDE124, 1, 2, 0, gUnk_0815548A, 8 },
    { gUnk_08F5F384, gUnk_09EDE128, 25, 3, 0, gUnk_081552D2, 9 },
    { gUnk_08F5F384, gUnk_09EDE18C, 40, 3, 0, gUnk_08155304, 10 },
    { gUnk_08F5F384, gUnk_09EDE22C, 35, 3, 0, gUnk_08155354, 11 },
    { gUnk_08F62384, gUnk_09EDDECC, 3, -1, gUnk_08155548, 0, 0 },
    { gUnk_08F61384, gUnk_09EDE2B8, 6, 14, 0, gUnk_0815548C, 12 },
    { gUnk_08F5E384, gUnk_09EDE3A4, 22, 14, 0, gUnk_08155498, 13 },
    { gUnk_08F5F384, gUnk_09EDDF38, 3, 14, gUnk_0815554E, 0, 0 },
    { gUnk_08F5F384, gUnk_09EDE2D0, 14, 17, 0, gUnk_081554C4, 14 },
    { gUnk_08F5F384, gUnk_09EDE308, 6, 17, 0, gUnk_081554E0, 15 },
    { gUnk_08F5F384, gUnk_09EDE320, 33, 17, 0, gUnk_081554EC, 16 },
};

#if defined(VERSION_US)

const JiminyDetail gUnk_0815574C[17] = {
    { gUnk_0815B502, gUnk_09EDB7EC, 22, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B51E, gUnk_09EDB844, 19, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B53C, gUnk_09EDD46C, 18, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B55C, gUnk_09EDB890, 22, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A518, gUnk_09EDD3B4, 20, 0, gUnk_099A87C0, gUnk_09A3CCDC, gUnk_099E5E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A534, gUnk_09EDD404, 26, 0, gUnk_099A8758, gUnk_09A3CC9C, gUnk_099E3E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A54A, gUnk_09EDB8E8, 17, 0, gUnk_099A87F8, gUnk_09A3CCFC, gUnk_099E6E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A56C, gUnk_09EDB92C, 32, 0, gUnk_099A8824, gUnk_09A3CD1C, gUnk_099E7E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A57C, gUnk_09EDD4B4, 22, 0, gUnk_099A88A0, gUnk_09A3CD7C, gUnk_099EAE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A59A, gUnk_09EDB9AC, 25, 0, gUnk_099A884C, gUnk_09A3CD3C, gUnk_099E8E7C, 0, 0, 0, 0, 0, 0, 0, 0, -8, 0 },
    { gUnk_0815A5AA, gUnk_09EDDD48, 25, 0, gUnk_099A8880, gUnk_09A3CD5C, gUnk_099E9E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A5BE, gUnk_09EDBA10, 27, 0, gUnk_099A88D4, gUnk_09A3CD9C, gUnk_099EBE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A5D4, gUnk_09EDBA7C, 25, 0, gUnk_099A8930, gUnk_09A3CE1C, gUnk_099EEE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A5F2, gUnk_09EDDDAC, 9, 0, gUnk_099A8900, gUnk_09A3CDBC, gUnk_099ECE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A60E, gUnk_09EDBAE0, 15, 0, gUnk_099A895C, gUnk_09A3CE3C, gUnk_099EFE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A62A, gUnk_09EDD50C, 16, 0, gUnk_099A8780, gUnk_09A3CCBC, gUnk_099E4E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A64A, gUnk_09EDDE38, 24, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08155B04[6] = {
    { gUnk_0815C01E, gUnk_09EDD698, 41, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C03A, gUnk_09EDBB1C, 26, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C058, gUnk_09EDBB84, 20, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C078, gUnk_09EDD73C, 20, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C096, gUnk_09EDBBD4, 23, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C0B2, gUnk_09EDD78C, 31, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08155C54[17] = {
    { gUnk_0815A66A, gUnk_09EDD928, 12, 0, gCardWep01Frame0, gCardWep01Palette, gCardWep01Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A682, gUnk_09EDD958, 11, 0, gCardWep04Frame0, gCardWep04Palette, gCardWep04Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A69C, gUnk_09EDD984, 12, 0, gCardWep05Frame0, gCardWep05Palette, gCardWep05Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A6AE, gUnk_09EDD9B4, 12, 0, gCardWep06Frame0, gCardWep06Palette, gCardWep06Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A6C6, gUnk_09EDD9E4, 11, 0, gCardWep07Frame0, gCardWep07Palette, gCardWep07Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A6DC, gUnk_09EDDA10, 11, 0, gCardWep08Frame0, gCardWep08Palette, gCardWep08Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A6F6, gUnk_09EDDA3C, 11, 0, gCardWep09Frame0, gCardWep09Palette, gCardWep09Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A70E, gUnk_09EDDA68, 12, 0, gCardWep10Frame0, gCardWep10Palette, gCardWep10Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A72A, gUnk_09EDDA98, 12, 0, gCardWep03Frame0, gCardWep03Palette, gCardWep03Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A73A, gUnk_09EDDAC8, 11, 0, gCardWep11Frame0, gCardWep11Palette, gCardWep11Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A74E, gUnk_09EDDAF4, 11, 0, gCardWep12Frame0, gCardWep12Palette, gCardWep12Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A762, gUnk_09EDDB20, 12, 0, gCardWep13Frame0, gCardWep13Palette, gCardWep13Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A77A, gUnk_09EDDB50, 11, 0, gCardWep14Frame0, gCardWep14Palette, gCardWep14Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A790, gUnk_09EDDB7C, 12, 0, gCardWep15Frame0, gCardWep15Palette, gCardWep15Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A7BE, gUnk_09EDDBAC, 12, 0, gCardWep18Frame0, gCardWep18Palette, gCardWep18Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A7D8, gUnk_09EDDBDC, 12, 0, gCardWep19Frame0, gCardWep19Palette, gCardWep19Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A7A2, gUnk_09EDDE98, 10, 0, gCardWep16Frame0, gCardWep16Palette, gCardWep16Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815600C[14] = {
    { gUnk_0815A7FA, gUnk_09EDCCAC, 4, 0, gCardMgc01Frame0, gCardMgc01Palette, gCardMgc01Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A804, gUnk_09EDCCBC, 4, 0, gCardMgc02Frame0, gCardMgc02Palette, gCardMgc02Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A816, gUnk_09EDCCCC, 5, 0, gCardMgc03Frame0, gCardMgc03Palette, gCardMgc03Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A826, gUnk_09EDCCE0, 3, 0, gCardMgc04Frame0, gCardMgc04Palette, gCardMgc04Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A830, gUnk_09EDCCEC, 5, 0, gCardMgc05Frame0, gCardMgc05Palette, gCardMgc05Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A840, gUnk_09EDCD00, 5, 0, gCardMgc06Frame0, gCardMgc06Palette, gCardMgc06Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A84A, gUnk_09EDCD14, 5, 0, gCardMgc07Frame0, gCardMgc07Palette, gCardMgc07Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A854, gUnk_09EDCD28, 6, 0, gCardSmn03Frame0, gCardSmn03Palette, gCardSmn03Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A878, gUnk_09EDCD40, 6, 0, gCardSmn06Frame0, gCardSmn06Palette, gCardSmn06Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A86C, gUnk_09EDCD58, 4, 0, gCardSmn05Frame0, gBanbPalette, gCardSmn05Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A89C, gUnk_09EDCD68, 5, 0, gCardSmn08Frame0, gMushuPalette, gCardSmn08Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A860, gUnk_09EDCD7C, 5, 0, gCardSmn04Frame0, gCardSmn04Palette, gCardSmn04Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A884, gUnk_09EDCD90, 4, 0, gCardSmn07Frame0, gTinkPalette, gCardSmn07Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A8A8, gUnk_09EDCDA0, 4, 0, gCardSmn09Frame0, gCardSmn09Palette, gCardSmn09Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815631C[7] = {
    { gUnk_0815A8B4, gUnk_09EDCDB0, 5, 0, gCardItm01Frame0, gCardItm01Palette, gCardItm01Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A8C2, gUnk_09EDCDC4, 5, 0, gCardItm02Frame0, gCardItm02Palette, gCardItm02Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A8D6, gUnk_09EDCDD8, 6, 0, gCardItm03Frame0, gCardItm03Palette, gCardItm03Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A8EE, gUnk_09EDCDF0, 5, 0, gCardItm04Frame0, gCardItm04Palette, gCardItm04Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A8FA, gUnk_09EDCE04, 6, 0, gCardItm05Frame0, gCardItm05Palette, gCardItm05Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A910, gUnk_09EDCE1C, 4, 0, gCardItm06Frame0, gCardItm06Palette, gCardItm06Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A91E, gUnk_09EDCE2C, 6, 0, gCardItm07Frame0, gCardItm07Palette, gCardItm07Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081564A4[7] = {
    { gUnk_0815A932, gUnk_09EDCE44, 5, 0, gCardSmn02Frame0, gDonaldPalette, gCardSmn02Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A94A, gUnk_09EDCE58, 4, 0, gCardSmn01Frame0, gGoofyPalette, gCardSmn01Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A956, gUnk_09EDCE68, 5, 0, gCardSmn10Frame0, gAladdinPalette, gCardSmn10Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A972, gUnk_09EDCE7C, 5, 0, gCardSmn12Frame0, gJackPalette, gCardSmn12Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A966, gUnk_09EDCE90, 5, 0, gCardSmn11Frame0, gArielPalette, gCardSmn11Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A97C, gUnk_09EDCEA4, 4, 0, gCardSmn13Frame0, gPeterPalette, gCardSmn13Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A990, gUnk_09EDCEB4, 5, 0, gCardSmn14Frame0, gBeastPalette, gCardSmn14Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815662C[49] = {
    { gUnk_0815A9A4, gUnk_09EDCEC8, 5, 0, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9B2, gUnk_09EDCEDC, 5, 0, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9EC, gUnk_09EDCEF0, 6, 0, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA46, gUnk_09EDCF08, 5, 0, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA60, gUnk_09EDCF1C, 5, 0, gUnk_0904B1A8, gEmy02Palette, gUnk_0904B1BC, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA7C, gUnk_09EDCF30, 5, 0, gUnk_0904B3BC, gEmy03Palette, gUnk_0904B3D0, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA96, gUnk_09EDCF44, 5, 0, gUnk_0904B5D0, gEmy04Palette, gUnk_0904B5E4, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9C2, gUnk_09EDCF58, 8, 0, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9D6, gUnk_09EDCF78, 6, 0, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AAC0, gUnk_09EDCF90, 4, 0, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA2A, gUnk_09EDCFA0, 6, 0, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA02, gUnk_09EDCFB8, 6, 0, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AAD8, gUnk_09EDCFD0, 4, 0, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB36, gUnk_09EDDDD0, 7, 0, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA18, gUnk_09EDCFE0, 5, 0, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB62, gUnk_09EDCFF4, 5, 0, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB50, gUnk_09EDD008, 6, 0, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AAF4, gUnk_09EDD020, 5, 0, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB24, gUnk_09EDD034, 6, 0, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA38, gUnk_09EDD04C, 5, 0, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB0E, gUnk_09EDD060, 6, 0, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB78, gUnk_09EDD078, 5, 0, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB98, gUnk_09EDD08C, 7, 0, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB8A, gUnk_09EDDDEC, 6, 0, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AAB2, gUnk_09EDD0A8, 6, 0, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC2C, gUnk_09EDD0C0, 5, 0, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ABAA, gUnk_09EDD0D4, 6, 0, gCardEmy07Frame0, gEmy07Palette, gCardEmy07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ABC8, gUnk_09EDD0EC, 5, 0, gCardEmy08Frame0, gEmy07bPalette, gCardEmy08Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ABE2, gUnk_09EDD100, 6, 0, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ABFE, gUnk_09EDDE04, 5, 0, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC18, gUnk_09EDD118, 6, 0, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC40, gUnk_09EDD130, 5, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACB0, gUnk_09EDDC3C, 6, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC64, gUnk_09EDDC70, 8, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACFA, gUnk_09EDDC0C, 6, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C178, gUnk_09EDDCA8, 5, 0, gCardNpcAw04Frame0, gTrumpHPalette, gCardNpcAw04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC58, gUnk_09EDD144, 9, 0, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC7C, gUnk_09EDDC90, 6, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC96, gUnk_09EDDC24, 6, 0, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC88, gUnk_09EDD168, 7, 0, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACCC, gUnk_09EDD184, 8, 0, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACD6, gUnk_09EDD1A4, 6, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B0F2, gUnk_09EDD1BC, 8, 0, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AD0C, gUnk_09EDD1DC, 7, 0, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AD16, gUnk_09EDD1F8, 7, 0, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AD40, gUnk_09EDD214, 9, 0, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AD4C, gUnk_09EDD238, 13, 0, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AD9A, gUnk_09EDD37C, 14, 0, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ADAA, gUnk_09EDDC54, 7, 0, gCardBos18Frame0, gCardBos18Palette, gCardBos18Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081570E4[26] = {
    { gUnk_0815ADF4, gUnk_09EDD26C, 2, 0, gCardRoom02Frame0, gCardRoom02Palette, gCardRoom02Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ADD2, gUnk_09EDDCBC, 4, 0, gCardRoom01Frame0, gCardRoom01Palette, gCardRoom01Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AE9E, gUnk_09EDD294, 3, 0, gCardRoom07Frame0, gCardRoom07Palette, gCardRoom07Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AEBE, gUnk_09EDDCE0, 5, 0, gCardRoom08Frame0, gCardRoom08Palette, gCardRoom08Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AE56, gUnk_09EDD280, 3, 0, gCardRoom05Frame0, gCardRoom05Palette, gCardRoom05Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AE34, gUnk_09EDDCCC, 5, 0, gCardRoom04Frame0, gCardRoom04Palette, gCardRoom04Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AF8E, gUnk_09EDD32C, 3, 0, gCardRoom20Frame0, gCardRoom20Palette, gCardRoom20Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AFA8, gUnk_09EDD338, 5, 0, gCardRoom21Frame0, gCardRoom21Palette, gCardRoom21Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AFBE, gUnk_09EDD34C, 4, 0, gCardRoom22Frame0, gCardRoom22Palette, gCardRoom22Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B02E, gUnk_09EDD2D0, 3, 0, gCardRoom13Frame0, gCardRoom13Palette, gCardRoom13Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AFEC, gUnk_09EDD2C4, 3, 0, gCardRoom12Frame0, gCardRoom12Palette, gCardRoom12Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B00E, gUnk_09EDD2DC, 3, 0, gCardRoom14Frame0, gCardRoom14Palette, gCardRoom14Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AF70, gUnk_09EDD2E8, 5, 0, gCardRoom15Frame0, gCardRoom15Palette, gCardRoom15Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AF52, gUnk_09EDD324, 2, 0, gCardRoom19Frame0, gCardRoom19Palette, gCardRoom19Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AF14, gUnk_09EDD304, 4, 0, gCardRoom17Frame0, gCardRoom17Palette, gCardRoom17Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AF38, gUnk_09EDD314, 4, 0, gCardRoom18Frame0, gCardRoom18Palette, gCardRoom18Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AEE2, gUnk_09EDD2A0, 2, 0, gCardRoom09Frame0, gCardRoom09Palette, gCardRoom09Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AE18, gUnk_09EDD274, 3, 0, gCardRoom03Frame0, gCardRoom03Palette, gCardRoom03Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AEFA, gUnk_09EDD2A8, 4, 0, gCardRoom10Frame0, gCardRoom10Palette, gCardRoom10Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AE7A, gUnk_09EDD28C, 2, 0, gCardRoom06Frame0, gCardRoom06Palette, gCardRoom06Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B04C, gUnk_09EDD2FC, 2, 0, gCardRoom16Frame0, gCardRoom16Palette, gCardRoom16Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AFD4, gUnk_09EDD2B8, 3, 0, gCardRoom11Frame0, gCardRoom11Palette, gCardRoom11Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B06C, gUnk_09EDD35C, 2, 0, gCardEve00Frame0, gCardEve00Palette, gCardEve00Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B090, gUnk_09EDD364, 2, 0, gCardEve01Frame0, gCardEve01Palette, gCardEve01Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B0B0, gUnk_09EDD36C, 2, 0, gCardEve02Frame0, gCardEve02Palette, gCardEve02Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B0CA, gUnk_09EDD374, 2, 0, gCardRoom23Frame0, gCardRoom23Palette, gCardRoom23Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08157694[1] = {
    { gUnk_0815C10E, gUnk_09EDDCF4, 17, 0, gUnk_08C6AA58, gUnk_08F6E164, gUnk_08C6AA7E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081576CC[22] = {
    { gUnk_0815C372, gUnk_09EDBC30, 4, 0, gCardWep20Frame0, gCardWep20Palette, gCardWep20Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815C360, gUnk_09EDDD38, 4, 0, gCardSmn15Frame0, gMickeyPalette, gCardSmn15Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9A4, gUnk_09EDCEC8, 5, 0, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9EC, gUnk_09EDCEF0, 6, 0, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A9C2, gUnk_09EDCF58, 8, 0, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA02, gUnk_09EDCFB8, 6, 0, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB36, gUnk_09EDDDD0, 7, 0, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA18, gUnk_09EDCFE0, 5, 0, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AAF4, gUnk_09EDD020, 5, 0, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AA38, gUnk_09EDD04C, 5, 0, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AB98, gUnk_09EDD08C, 7, 0, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC40, gUnk_09EDD130, 5, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACB0, gUnk_09EDDC3C, 6, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC64, gUnk_09EDDC70, 8, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACFA, gUnk_09EDDC0C, 6, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC58, gUnk_09EDD144, 9, 0, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC7C, gUnk_09EDDC90, 6, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC96, gUnk_09EDDC24, 6, 0, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AC88, gUnk_09EDD168, 7, 0, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACCC, gUnk_09EDD184, 8, 0, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815ACD6, gUnk_09EDD1A4, 6, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815AD9A, gUnk_09EDD37C, 14, 0, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08157B9C[25] = {
    { gUnk_0815B0E8, gUnk_09EDBC40, 15, 0, gSor1fl00Frame0, gSoraPalette, gSor1fl00Tiles, gCardNpcEx00Frame0, gCardNpcEx00Palette, gCardNpcEx00Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { gUnk_0815A932, gUnk_09EDBC7C, 16, 0, gDonaFl00Frame0, gDonaldPalette, gDonaFl00Tiles, gCardSmn02Frame0, gDonaldPalette, gCardSmn02Tiles, 0, 0, 0, 0, 0, 0, -9 },
    { gUnk_0815A94A, gUnk_09EDBCBC, 12, 0, gGoofyFl00Frame0, gGoofyPalette, gGoofyFl00Tiles, gCardSmn01Frame0, gGoofyPalette, gCardSmn01Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B434, gUnk_09EDBCEC, 7, 0, gJimFl00Frame0, gJiminyPalette, gJimFl00Tiles, gCardNpcEx01Frame0, gCardNpcEx01Palette, gCardNpcEx01Tiles, 0, 0, 0, 0, 0, -3, -11 },
    { gUnk_0815B0F2, gUnk_09EDBD08, 16, 0, gRikuFl00Frame0, gRikuPalette, gRikuFl00Tiles, gCardNpcEx03Frame0, gCardNpcEx03Palette, gCardNpcEx03Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnk_0815B0FC, gUnk_09EDD54C, 15, 0, gKairF00Frame0, gKairiPalette, gKairF00Tiles, gCardNpcEx05Frame0, gCardNpcEx05Palette, gCardNpcEx05Tiles, 0, 0, 0, 0, 0, -1, -3 },
    { gUnk_0815A854, gUnk_09EDBD48, 7, 0, gShinba10Frame0, gShinbaPalette, gShinba10Tiles, gCardSmn03Frame0, gCardSmn03Palette, gCardSmn03Tiles, 0, 0, 0, 0, 0, -2, -7 },
    { gUnk_0815A878, gUnk_09EDBD64, 11, 0, gUnk_088ABEF4, gDamboPalette, gUnk_088ABF88, gCardSmn06Frame0, gCardSmn06Palette, gCardSmn06Tiles, 0, 0, 0, 0, 0, 8, -7 },
    { gUnk_0815A86C, gUnk_09EDBD90, 6, 0, gBanb00Frame7, gBanbPalette, gBanb00Tiles, gCardSmn05Frame0, gBanbPalette, gCardSmn05Tiles, 0, 0, 0, 0, 0, -2, -7 },
    { gUnk_0815A89C, gUnk_09EDBDA8, 8, 0, gMushuF00Frame1, gMushuPalette, gMushuF00Tiles, gCardSmn08Frame0, gMushuPalette, gCardSmn08Tiles, 0, 0, 0, 0, 0, 0, -12 },
    { gUnk_0815B190, gUnk_09EDBDC8, 8, 0, gMoguFl00Frame0, gMoguPalette, gMoguFl00Tiles, gCardNpcEx02Frame0, gCardNpcEx02Palette, gCardNpcEx02Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnk_0815B14E, gUnk_09EDBDE8, 13, 0, gReonFl00Frame0, gReonPalette, gReonFl00Tiles, gCardNpcEx09Frame0, gCardNpcEx09Palette, gCardNpcEx09Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { gUnk_0815B116, gUnk_09EDBE1C, 11, 0, gYuffieFl00Frame0, gYuffiePalette, gYuffieFl00Tiles, gCardNpcEx10Frame0, gCardNpcEx10Palette, gCardNpcEx10Tiles, 0, 0, 0, 0, 0, -1, 2 },
    { gUnk_0815B124, gUnk_09EDBE48, 12, 0, gEarF00Frame0, gEarisPalette, gEarF00Tiles, gCardNpcEx06Frame0, gCardNpcEx06Palette, gCardNpcEx06Tiles, 0, 0, 0, 0, 0, -3, 4 },
    { gUnk_0815B188, gUnk_09EDBE78, 8, 0, gShidoF00Frame0, gShidoPalette, gShidoF00Tiles, gCardNpcEx07Frame0, gCardNpcEx07Palette, gCardNpcEx07Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { gUnk_0815A8A8, gUnk_09EDBE98, 10, 0, gCroudF00Frame0, gCroudPalette, gCroudF00Tiles, gCardSmn09Frame0, gCardSmn09Palette, gCardSmn09Tiles, 0, 0, 0, 0, 0, -3, 2 },
    { gUnk_0815B17C, gUnk_09EDD588, 9, 0, gTidusFl00Frame0, gTidusPalette, gTidusFl00Tiles, gCardNpcDi01Frame0, gCardNpcDi01Palette, gCardNpcDi01Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnk_0815B132, gUnk_09EDD5AC, 7, 0, gWakkaF00Frame0, gWakkaPalette, gWakkaF00Tiles, gCardNpcDi02Frame0, gCardNpcDi02Palette, gCardNpcDi02Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815B16C, gUnk_09EDD5C8, 8, 0, gSelphieFl00Frame0, gSelphiePalette, gSelphieFl00Tiles, gCardNpcDi03Frame0, gCardNpcDi03Palette, gCardNpcDi03Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnk_0815B108, gUnk_09EDBEC0, 15, 0, gNamiF00Frame0, gNaminePalette, gNamiF00Tiles, gCardNpcCom01Frame0, gCardNpcCom01Palette, gCardNpcCom01Tiles, 0, 0, 0, 0, 0, -1, -4 },
    { gUnk_0815C0D0, gUnk_09EDBEFC, 12, 0, gNiseFl00Frame0, gNiserikuPalette, gNiseFl00Tiles, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnk_0815AD0C, gUnk_09EDBF2C, 11, 0, gAcceleFl00Frame0, gAccelePalette, gAcceleFl00Tiles, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815AD16, gUnk_09EDD5E8, 13, 0, gLaxineFl00Frame0, gLaxinePalette, gLaxineFl00Tiles, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { gUnk_0815AD40, gUnk_09EDBF58, 11, 0, gVixenFl00Frame0, gVixenPalette, gVixenFl00Tiles, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815AD4C, gUnk_09EDBF84, 10, 0, gMaruxha2Fl00Frame0, gMaruxhaPalette, gMaruxha2Fl00Tiles, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, 0, 0, 0, 0, 0, -3, 6 },
};

const JiminyDetail gUnk_08158114[40] = {
    { gUnk_0815B296, gUnk_09EDC1E0, 11, 0, gAliceFl00Frame0, gAlicePalette, gAliceFl00Tiles, gCardNpcAw01Frame0, gCardNpcAw01Palette, gCardNpcAw01Tiles, 0, 0, 0, 0, 0, -1, -1 },
    { gUnk_0815B2A2, gUnk_09EDC20C, 8, 0, gQenF00Frame0, gQeenPalette, gQenF00Tiles, gCardNpcAw02Frame0, gCardNpcAw02Palette, gCardNpcAw02Tiles, 0, 0, 0, 0, 0, -3, 4 },
    { gUnk_0815B2CA, gUnk_09EDC22C, 7, 0, gUsagif00Frame0, gUsagi00Palette, gUsagif00Tiles, gCardNpcAw05Frame0, gCardNpcAw05Palette, gCardNpcAw05Tiles, 0, 0, 0, 0, 0, 0, -10 },
    { gUnk_0815AD5E, gUnk_09EDC248, 6, 0, gTrumpH00Frame0, gTrumpHPalette, gTrumpH00Tiles, gCardNpcAw04Frame0, gTrumpHPalette, gCardNpcAw04Tiles, 0, 0, 0, 0, 0, 0, 2 },
    { gUnk_0815AD7C, gUnk_09EDC260, 6, 0, gTrumpS00Frame0, gTrumpSPalette, gTrumpS00Tiles, gCardNpcAw03Frame0, gTrumpSPalette, gCardNpcAw03Tiles, 0, 0, 0, 0, 0, 0, 2 },
    { gUnk_0815B2EC, gUnk_09EDC278, 8, 0, gCheshireFrame0, gCheshirePalette, gCheshireTiles, gCardNpcAw06Frame0, gCardNpcAw06Palette, gCardNpcAw06Tiles, 0, 0, 0, 0, 0, -4, -12 },
    { gUnk_0815B26C, gUnk_09EDC178, 10, 0, gHeraclesFl00Frame0, gHeraclesPalette, gHeraclesFl00Tiles, gCardNpcHe02Frame0, gCardNpcHe02Palette, gCardNpcHe02Tiles, 0, 0, 0, 0, 0, 0, 13 },
    { gUnk_0815B27E, gUnk_09EDC1A0, 7, 0, gPhilFl00Frame0, gPhilPalette, gPhilFl00Tiles, gCardNpcHe01Frame0, gCardNpcHe01Palette, gCardNpcHe01Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { gUnk_0815AC58, gUnk_09EDC1BC, 9, 0, gHadesFl00Frame0, gHadesPalette, gHadesFl00Tiles, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, 0, 0, 0, 0, 0, 0, 18 },
    { gUnk_0815A956, gUnk_09EDBFAC, 16, 0, gAladdin00Frame0, gAladdinPalette, gAladdin00Tiles, gCardSmn10Frame0, gAladdinPalette, gCardSmn10Tiles, 0, 0, 0, 0, 0, -2, 6 },
    { gUnk_0815A860, gUnk_09EDBFEC, 11, 0, gGenie01Frame2, gGeniePalette, gGenie01Tiles, gCardSmn04Frame0, gCardSmn04Palette, gCardSmn04Tiles, 0, 0, 0, 0, 0, 2, 1 },
    { gUnk_0815B1E4, gUnk_09EDC018, 6, 0, gJasmineF00Frame0, gJasminePalette, gJasmineF00Tiles, gCardNpcAl01Frame0, gCardNpcAl01Palette, gCardNpcAl01Tiles, 0, 0, 0, 0, 0, -4, 5 },
    { gUnk_0815B1F4, gUnk_09EDC030, 7, 0, gUnk_09393218, gUnk_09618358, gUnk_0939322C, gCardNpcAl03Frame0, gCardNpcAl03Palette, gCardNpcAl03Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { gUnk_0815AC7C, gUnk_09EDC04C, 8, 0, gJafferFl00Frame0, gJafferPalette, gJafferFl00Tiles, gCardNpcAl02Frame0, gCardNpcAl02Palette, gCardNpcAl02Tiles, 0, 0, 0, 0, 0, -3, 19 },
    { gUnk_0815B1FE, gUnk_09EDC06C, 7, 0, 0, 0, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_08F67384, gUnk_08F6E104, gUnk_08EEC044, 32, 3744, 0, 0 },
    { gUnk_0815A972, gUnk_09EDC088, 7, 0, gJackFl00Frame0, gJackPalette, gJackFl00Tiles, gCardSmn12Frame0, gJackPalette, gCardSmn12Tiles, 0, 0, 0, 0, 0, 2, 11 },
    { gUnk_0815B21A, gUnk_09EDC0A4, 7, 0, gSariFl00Frame0, gSariPalette, gSariFl00Tiles, gCardNpcNm01Frame0, gCardNpcNm01Palette, gCardNpcNm01Tiles, 0, 0, 0, 0, 0, -2, 7 },
    { gUnk_0815B226, gUnk_09EDC0C0, 10, 0, gFinklF00Frame0, gFinklPalette, gFinklF00Tiles, gCardNpcNm02Frame0, gCardNpcNm02Palette, gCardNpcNm02Tiles, 0, 0, 0, 0, 0, -1, -7 },
    { gUnk_0815AC96, gUnk_09EDC0E8, 9, 0, gBugiFl00Frame0, gBugiPalette, gBugiFl00Tiles, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnk_0815B246, gUnk_09EDC10C, 13, 0, gPinoF00Frame0, gPinokioPalette, gPinoF00Tiles, gCardNpcPi01Frame0, gCardNpcPi01Palette, gCardNpcPi01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnk_0815B25A, gUnk_09EDC140, 14, 0, gGeppettoF00Frame0, gGeppettoPalette, gGeppettoF00Tiles, gCardNpcPi02Frame0, gCardNpcPi02Palette, gCardNpcPi02Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { gUnk_0815A966, gUnk_09EDD61C, 15, 0, gArielF00Frame0, gArielPalette, gArielF00Tiles, gCardSmn11Frame0, gArielPalette, gCardSmn11Tiles, 0, 0, 0, 0, 0, -4, 3 },
    { gUnk_0815B30E, gUnk_09EDC298, 8, 0, gSebastianFl00Frame0, gSebastianPalette, gSebastianFl00Tiles, gCardNpcLm01Frame0, gCardNpcLm01Palette, gCardNpcLm01Tiles, 0, 0, 0, 0, 0, -1, -13 },
    { gUnk_0815B322, gUnk_09EDC2B8, 10, 0, gFlounderFl00Frame0, gFlounderPalette, gFlounderFl00Tiles, gCardNpcLm02Frame0, gCardNpcLm02Palette, gCardNpcLm02Tiles, 0, 0, 0, 0, 0, -1, -17 },
    { gUnk_0815AC88, gUnk_09EDC2E0, 9, 0, gArthraFl00Frame0, gArthraPalette, gArthraFl00Tiles, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815A97C, gUnk_09EDC304, 13, 0, gPeterFl00Frame0, gPeterPalette, gPeterFl00Tiles, gCardSmn13Frame0, gPeterPalette, gCardSmn13Tiles, 0, 0, 0, 0, 0, -3, 5 },
    { gUnk_0815A884, gUnk_09EDC338, 4, 0, gTinkF00Frame2, gTinkPalette, gTinkF00Tiles, gCardSmn07Frame0, gTinkPalette, gCardSmn07Tiles, 0, 0, 0, 0, 0, -5, -10 },
    { gUnk_0815B334, gUnk_09EDC348, 7, 0, gWendyFl00Frame0, gWendyPalette, gWendyFl00Tiles, gCardNpcPp01Frame0, gCardNpcPp01Palette, gCardNpcPp01Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnk_0815B340, gUnk_09EDC364, 12, 0, gHookF00Frame0, gHookPalette, gHookF00Tiles, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, 0, 0, 0, 0, 0, -1, 17 },
    { gUnk_0815A990, gUnk_09EDC394, 10, 0, gBeastFl00Frame0, gBeastPalette, gBeastFl00Tiles, gCardSmn14Frame0, gBeastPalette, gCardSmn14Tiles, 0, 0, 0, 0, 0, -1, 10 },
    { gUnk_0815B34A, gUnk_09EDC3BC, 11, 0, gBellFl00Frame0, gBellPalette, gBellFl00Tiles, gCardNpcPc01Frame0, gCardNpcPc01Palette, gCardNpcPc01Tiles, 0, 0, 0, 0, 0, -4, 5 },
    { gUnk_0815B356, gUnk_09EDC3E8, 11, 0, gMarefF00Frame0, gMarefPalette, gMarefF00Tiles, gCardNpcPc02Frame0, gCardNpcPc02Palette, gCardNpcPc02Tiles, 0, 0, 0, 0, 0, -12, 16 },
    { gUnk_0815ACD6, gUnk_09EDC414, 8, 0, 0, 0, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_08F67B84, gUnk_08F6E124, gUnk_08EECEE4, 64, 5280, 0, 0 },
    { gUnk_0815B36C, gUnk_09EDD658, 9, 0, gPoohFl06Frame0, gPoohPalette, gPoohFl06Tiles, gCardNpcPo01Frame0, gCardNpcPo01Palette, gCardNpcPo01Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnk_0815B38C, gUnk_09EDC434, 6, 0, gUnk_09742FC4, gUnk_09849C18, gUnk_09742FD8, gCardNpcPo03Frame0, gCardNpcPo03Palette, gCardNpcPo03Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { gUnk_0815B39A, gUnk_09EDC44C, 6, 0, gOwlFl00Frame0, gOwlPalette, gOwlFl00Tiles, gCardNpcPo06Frame0, gCardNpcPo06Palette, gCardNpcPo06Tiles, 0, 0, 0, 0, 0, -3, -7 },
    { gUnk_0815B3A2, gUnk_09EDC464, 6, 0, gRooFl00Frame0, gRooPalette, gRooFl00Tiles, gCardNpcPo07Frame0, gCardNpcPo07Palette, gCardNpcPo07Tiles, 0, 0, 0, 0, 0, -1, -13 },
    { gUnk_0815B3AA, gUnk_09EDC47C, 8, 0, gEeyoreFl00Frame0, gEeyorePalette, gEeyoreFl00Tiles, gCardNpcPo04Frame0, gCardNpcPo04Palette, gCardNpcPo04Tiles, 0, 0, 0, 0, 0, 5, -13 },
    { gUnk_0815B3B8, gUnk_09EDC49C, 8, 0, gTiggerFl00Frame0, gTiggerPalette, gTiggerFl00Tiles, gCardNpcPo02Frame0, gCardNpcPo02Palette, gCardNpcPo02Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { gUnk_0815B3C6, gUnk_09EDC4BC, 9, 0, gRabbitFl00Frame0, gRabbitPalette, gRabbitFl00Tiles, gCardNpcPo05Frame0, gCardNpcPo05Palette, gCardNpcPo05Tiles, 0, 0, 0, 0, 0, -1, -3 },
};

const JiminyDetail gUnk_081589D4[35] = {
    { gUnk_0815A9A4, gUnk_09EDC540, 9, 0, gEmy00L00Frame0, gEmy00Palette, gEmy00L00Tiles, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, 0, 0, 0, 0, 0, 2, -12 },
    { gUnk_0815A9B2, gUnk_09EDC564, 7, 0, gEmy14Ll01Frame1, gEmy14Palette, gEmy14Ll01Tiles, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, 0, 0, 0, 0, 0, -8, 2 },
    { gUnk_0815A9EC, gUnk_09EDC580, 10, 0, gEmy3800Frame0, gEmy38Palette, gEmy3800Tiles, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, 0, 0, 0, 0, 0, -6, 6 },
    { gUnk_0815AA46, gUnk_09EDC5A8, 9, 0, gEmy01L00Frame16, gEmy01Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnk_0815AA60, gUnk_09EDC5CC, 9, 0, gEmy01L00Frame3, gEmy02Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy02Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -1, -11 },
    { gUnk_0815AA7C, gUnk_09EDC5F0, 9, 0, gEmy01L00Frame0, gEmy03Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy03Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -11 },
    { gUnk_0815AA96, gUnk_09EDC614, 11, 0, gEmy01L00Frame15, gEmy04Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy04Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnk_0815A9C2, gUnk_09EDC640, 7, 0, gEmy1500Frame7, gEmy15Palette, gEmy1500Tiles, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, 0, 0, 0, 0, 0, 0, -6 },
    { gUnk_0815A9D6, gUnk_09EDC65C, 6, 0, gEmy1600Frame0, gEmy16Palette, gEmy1600Tiles, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, 0, 0, 0, 0, 0, -1, -9 },
    { gUnk_0815AAC0, gUnk_09EDC674, 10, 0, gEmy1800Frame0, gEmy18Palette, gEmy1800Tiles, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, 0, 0, 0, 0, 0, -1, 3 },
    { gUnk_0815AA2A, gUnk_09EDC69C, 7, 0, gEmy1900Frame5, gEmy19Palette, gEmy1900Tiles, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, 0, 0, 0, 0, 0, -1, -6 },
    { gUnk_0815AA02, gUnk_09EDC6B8, 7, 0, gEmy3900Frame0, gEmy39Palette, gEmy3900Tiles, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnk_0815AAD8, gUnk_09EDC6D4, 9, 0, gEmy2100Frame0, gEmy21Palette, gEmy2100Tiles, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, 0, 0, 0, 0, 0, 1, -10 },
    { gUnk_0815AB36, gUnk_09EDC6F8, 7, 0, gEmy2200Frame9, gEmy22Palette, gEmy2200Tiles, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, 0, 0, 0, 0, 0, 2, 6 },
    { gUnk_0815AA18, gUnk_09EDDE18, 8, 0, gEmy0600Frame2, gEmy06Palette, gEmy0600Tiles, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnk_0815AB62, gUnk_09EDC714, 6, 0, gEmy2300Frame0, gEmy23Palette, gEmy2300Tiles, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, 0, 0, 0, 0, 0, 1, 2 },
    { gUnk_0815AB50, gUnk_09EDC72C, 8, 0, gEmy4100Frame0, gEmy41Palette, gEmy4100Tiles, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, 0, 0, 0, 0, 0, -2, 11 },
    { gUnk_0815AAF4, gUnk_09EDC74C, 7, 0, gEmy2500Frame3, gEmy25Palette, gEmy2500Tiles, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, 0, 0, 0, 0, 0, 4, 0 },
    { gUnk_0815AB24, gUnk_09EDC768, 7, 0, gEmy2600Frame0, gEmy26Palette, gEmy2600Tiles, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnk_0815AA38, gUnk_09EDC784, 10, 0, gEmy2700Frame0, gEmy27Palette, gEmy2700Tiles, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, 0, 0, 0, 0, 0, 10, -10 },
    { gUnk_0815AB0E, gUnk_09EDC7AC, 9, 0, gEmy2800Frame0, gEmy28Palette, gEmy2800Tiles, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, 0, 0, 0, 0, 0, 5, 5 },
    { gUnk_0815AB78, gUnk_09EDC7D0, 9, 0, gEmy2900Frame0, gEmy29Palette, gEmy2900Tiles, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { gUnk_0815AB98, gUnk_09EDC7F4, 13, 0, gEmy4400Frame0, gEmy44Palette, gEmy4400Tiles, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, 0, 0, 0, 0, 0, 3, 1 },
    { gUnk_0815AB8A, gUnk_09EDC828, 10, 0, gEmy3000Frame0, gEmy30Palette, gEmy3000Tiles, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, 0, 0, 0, 0, 0, 2, -5 },
    { gUnk_0815AAB2, gUnk_09EDC850, 8, 0, gEmy3100Frame6, gEmy31Palette, gEmy3100Tiles, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, 0, 0, 0, 0, 0, 5, -3 },
    { gUnk_0815AC2C, gUnk_09EDDEC0, 3, 0, gEmy3700Frame1, gEmy37Palette, gEmy3700Tiles, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnk_0815ABAA, gUnk_09EDC870, 8, 0, gEmy07Fl00Frame0, gEmy07Palette, gEmy07Fl00Tiles, gCardEmy07Frame0, gEmy07Palette, gCardEmy07Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnk_0815ABC8, gUnk_09EDC890, 12, 0, gEmy07Fl10tFrame7, gEmy07bPalette, gEmy07Fl10tTiles, gCardEmy08Frame0, gEmy07bPalette, gCardEmy08Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnk_0815ABE2, gUnk_09EDC8C0, 8, 0, gEmy8300Frame0, gEmy83Palette, gEmy8300Tiles, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, 0, 0, 0, 0, 0, 0, -4 },
    { gUnk_0815ABFE, gUnk_09EDC8E0, 9, 0, gEmy8100Frame0, gEmy81Palette, gEmy8100Tiles, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnk_0815AC18, gUnk_09EDC904, 6, 0, gEmy8201Frame2, gEmy82Palette, gEmy8201Tiles, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, 0, 0, 0, 0, 0, 4, -10 },
    { gUnk_0815AC40, gUnk_09EDC4E0, 6, 0, 0, 0, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_08F65B84, gUnk_08F6E044, gUnk_08EE8E84, 32, 3488, 3, -3 },
    { gUnk_0815ACB0, gUnk_09EDC4F8, 10, 0, 0, 0, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_08F66B84, gUnk_08F6E0A4, gUnk_08EEAD44, 96, 4864, 0, 0 },
    { gUnk_0815AC64, gUnk_09EDC520, 8, 0, 0, 0, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_08F66384, gUnk_08F6E064, gUnk_08EE9C24, 64, 4384, 0, 3 },
    { gUnk_0815ACFA, gUnk_09EDD67C, 7, 0, 0, 0, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_08F65384, gUnk_08F6E024, gUnk_08EE7A24, 32, 5216, 0, 0 },
};

const JiminyDetail gUnk_0815917C[14] = {
    { gUnk_0815B0F2, gUnk_09EDD808, 24, 0, gRikuFl00Frame0, gRikuPalette, gRikuFl00Tiles, gCardNpcEx03Frame0, gCardNpcEx03Palette, gCardNpcEx03Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnk_0815C360, gUnk_09EDD868, 15, 0, gMickeyFl00Frame0, gMickeyPalette, gMickeyFl00Tiles, gCardSmn15Frame0, gMickeyPalette, gCardSmn15Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnk_0815B0E8, gUnk_09EDC91C, 13, 0, gSor1fl00Frame0, gSoraPalette, gSor1fl00Tiles, gCardNpcEx00Frame0, gCardNpcEx00Palette, gCardNpcEx00Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { gUnk_0815B0FC, gUnk_09EDD8A4, 16, 0, gKairF00Frame0, gKairiPalette, gKairF00Tiles, gCardNpcEx05Frame0, gCardNpcEx05Palette, gCardNpcEx05Tiles, 0, 0, 0, 0, 0, -1, -3 },
    { gUnk_0815B108, gUnk_09EDC950, 16, 0, gNamiF00Frame0, gNaminePalette, gNamiF00Tiles, gCardNpcCom01Frame0, gCardNpcCom01Palette, gCardNpcCom01Tiles, 0, 0, 0, 0, 0, -1, -4 },
    { gUnk_0815C0D0, gUnk_09EDC990, 8, 0, gNiseFl00Frame0, gNiserikuPalette, gNiseFl00Tiles, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnk_0815ADAA, gUnk_09EDC9B0, 14, 0, gAnsemFl00Frame0, gAnsemPalette, gAnsemFl00Tiles, gCardBos18Frame0, gCardBos18Palette, gCardBos18Tiles, 0, 0, 0, 0, 0, -3, 9 },
    { gUnk_0815AD40, gUnk_09EDC9E8, 16, 0, gVixenFl00Frame0, gVixenPalette, gVixenFl00Tiles, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815AD9A, gUnk_09EDD8E4, 17, 0, gRexeusFl00Frame0, gRexeusPalette, gRexeusFl00Tiles, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, 0, 0, 0, 0, 0, -5, 14 },
    { gUnk_0815C010, gUnk_09EDCA28, 17, 0, gXexionFl00Frame0, gXexionPalette, gXexionFl00Tiles, gCardNpcCom02Frame0, gCardNpcCom02Palette, gCardNpcCom02Tiles, 0, 0, 0, 0, 0, -1, 6 },
    { gUnk_0815AD0C, gUnk_09EDCA6C, 19, 0, gAcceleFl00Frame0, gAccelePalette, gAcceleFl00Tiles, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815AD4C, gUnk_09EDCAB8, 19, 0, gMaruxha2Fl00Frame0, gMaruxhaPalette, gMaruxha2Fl00Tiles, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815AD16, gUnk_09EDCB04, 13, 0, gLaxineFl00Frame0, gLaxinePalette, gLaxineFl00Tiles, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { gUnk_0815C0EA, gUnk_09EDCB38, 11, 0, gDizFl00Frame0, gDizPalette, gDizFl00Tiles, gCardNpcCom03Frame0, gCardNpcCom03Palette, gCardNpcCom03Tiles, 0, 0, 0, 0, 0, -2, 8 },
};

const JiminyDetail gUnk_0815948C[6] = {
    { gUnk_0815B356, gUnk_09EDCB64, 13, 0, gMarefF00Frame0, gMarefPalette, gMarefF00Tiles, gCardNpcPc02Frame0, gCardNpcPc02Palette, gCardNpcPc02Tiles, 0, 0, 0, 0, 0, -12, 16 },
    { gUnk_0815B1FE, gUnk_09EDCB98, 8, 0, 0, 0, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_08F67384, gUnk_08F6E104, gUnk_08EEC044, 32, 3744, 0, 0 },
    { gUnk_0815AC88, gUnk_09EDCBB8, 9, 0, gArthraFl00Frame0, gArthraPalette, gArthraFl00Tiles, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnk_0815AC58, gUnk_09EDCBDC, 8, 0, gHadesFl00Frame0, gHadesPalette, gHadesFl00Tiles, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, 0, 0, 0, 0, 0, 0, 18 },
    { gUnk_0815AC96, gUnk_09EDCBFC, 8, 0, gBugiFl00Frame0, gBugiPalette, gBugiFl00Tiles, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnk_0815B340, gUnk_09EDCC1C, 6, 0, gHookF00Frame0, gHookPalette, gHookF00Tiles, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, 0, 0, 0, 0, 0, -1, 17 },
};

const JiminyDetail gUnk_081595DC[33] = {
    { gUnk_0815A9A4, gUnk_09EDC540, 9, 0, gEmy00L00Frame0, gEmy00Palette, gEmy00L00Tiles, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, 0, 0, 0, 0, 0, 2, -12 },
    { gUnk_0815A9B2, gUnk_09EDC564, 7, 0, gEmy14Ll01Frame1, gEmy14Palette, gEmy14Ll01Tiles, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, 0, 0, 0, 0, 0, -8, 2 },
    { gUnk_0815A9EC, gUnk_09EDC580, 10, 0, gEmy3800Frame0, gEmy38Palette, gEmy3800Tiles, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, 0, 0, 0, 0, 0, -6, 6 },
    { gUnk_0815AA46, gUnk_09EDC5A8, 9, 0, gEmy01L00Frame16, gEmy01Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnk_0815AA60, gUnk_09EDC5CC, 9, 0, gEmy01L00Frame3, gEmy02Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy02Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -1, -11 },
    { gUnk_0815AA7C, gUnk_09EDC5F0, 9, 0, gEmy01L00Frame0, gEmy03Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy03Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -11 },
    { gUnk_0815AA96, gUnk_09EDC614, 11, 0, gEmy01L00Frame15, gEmy04Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy04Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnk_0815A9C2, gUnk_09EDC640, 7, 0, gEmy1500Frame7, gEmy15Palette, gEmy1500Tiles, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, 0, 0, 0, 0, 0, 0, -6 },
    { gUnk_0815A9D6, gUnk_09EDC65C, 6, 0, gEmy1600Frame0, gEmy16Palette, gEmy1600Tiles, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, 0, 0, 0, 0, 0, -1, -9 },
    { gUnk_0815AAC0, gUnk_09EDC674, 10, 0, gEmy1800Frame0, gEmy18Palette, gEmy1800Tiles, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, 0, 0, 0, 0, 0, -1, 3 },
    { gUnk_0815AA2A, gUnk_09EDC69C, 7, 0, gEmy1900Frame5, gEmy19Palette, gEmy1900Tiles, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, 0, 0, 0, 0, 0, -1, -6 },
    { gUnk_0815AA02, gUnk_09EDC6B8, 7, 0, gEmy3900Frame0, gEmy39Palette, gEmy3900Tiles, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnk_0815AAD8, gUnk_09EDC6D4, 9, 0, gEmy2100Frame0, gEmy21Palette, gEmy2100Tiles, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, 0, 0, 0, 0, 0, 1, -10 },
    { gUnk_0815AB36, gUnk_09EDC6F8, 7, 0, gEmy2200Frame9, gEmy22Palette, gEmy2200Tiles, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, 0, 0, 0, 0, 0, 2, 6 },
    { gUnk_0815AA18, gUnk_09EDDE18, 8, 0, gEmy0600Frame2, gEmy06Palette, gEmy0600Tiles, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnk_0815AB62, gUnk_09EDC714, 6, 0, gEmy2300Frame0, gEmy23Palette, gEmy2300Tiles, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, 0, 0, 0, 0, 0, 1, 2 },
    { gUnk_0815AB50, gUnk_09EDC72C, 8, 0, gEmy4100Frame0, gEmy41Palette, gEmy4100Tiles, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, 0, 0, 0, 0, 0, -2, 11 },
    { gUnk_0815AAF4, gUnk_09EDC74C, 7, 0, gEmy2500Frame3, gEmy25Palette, gEmy2500Tiles, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, 0, 0, 0, 0, 0, 4, 0 },
    { gUnk_0815AB24, gUnk_09EDC768, 7, 0, gEmy2600Frame0, gEmy26Palette, gEmy2600Tiles, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnk_0815AA38, gUnk_09EDC784, 10, 0, gEmy2700Frame0, gEmy27Palette, gEmy2700Tiles, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, 0, 0, 0, 0, 0, 10, -10 },
    { gUnk_0815AB0E, gUnk_09EDC7AC, 9, 0, gEmy2800Frame0, gEmy28Palette, gEmy2800Tiles, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, 0, 0, 0, 0, 0, 5, 5 },
    { gUnk_0815AB78, gUnk_09EDC7D0, 9, 0, gEmy2900Frame0, gEmy29Palette, gEmy2900Tiles, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { gUnk_0815AB98, gUnk_09EDC7F4, 13, 0, gEmy4400Frame0, gEmy44Palette, gEmy4400Tiles, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, 0, 0, 0, 0, 0, 3, 1 },
    { gUnk_0815AB8A, gUnk_09EDC828, 10, 0, gEmy3000Frame0, gEmy30Palette, gEmy3000Tiles, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, 0, 0, 0, 0, 0, 2, -5 },
    { gUnk_0815AAB2, gUnk_09EDC850, 8, 0, gEmy3100Frame6, gEmy31Palette, gEmy3100Tiles, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, 0, 0, 0, 0, 0, 5, -3 },
    { gUnk_0815AC2C, gUnk_09EDDEC0, 3, 0, gEmy3700Frame1, gEmy37Palette, gEmy3700Tiles, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnk_0815ABE2, gUnk_09EDC8C0, 8, 0, gEmy8300Frame0, gEmy83Palette, gEmy8300Tiles, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, 0, 0, 0, 0, 0, 0, -4 },
    { gUnk_0815ABFE, gUnk_09EDC8E0, 9, 0, gEmy8100Frame0, gEmy81Palette, gEmy8100Tiles, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnk_0815AC18, gUnk_09EDC904, 6, 0, gEmy8201Frame2, gEmy82Palette, gEmy8201Tiles, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, 0, 0, 0, 0, 0, 4, -10 },
    { gUnk_0815AC40, gUnk_09EDCC34, 7, 0, 0, 0, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_08F65B84, gUnk_08F6E044, gUnk_08EE8E84, 32, 3488, 3, -3 },
    { gUnk_0815ACB0, gUnk_09EDCC50, 7, 0, 0, 0, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_08F66B84, gUnk_08F6E0A4, gUnk_08EEAD44, 96, 4864, 0, 0 },
    { gUnk_0815AC64, gUnk_09EDCC6C, 8, 0, 0, 0, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_08F66384, gUnk_08F6E064, gUnk_08EE9C24, 64, 4384, 0, 3 },
    { gUnk_0815ACFA, gUnk_09EDCC8C, 8, 0, 0, 0, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_08F65384, gUnk_08F6E024, gUnk_08EE7A24, 32, 5216, 0, 0 },
};

#elif defined(VERSION_JP)

const JiminyDetail gUnk_0815574C[17] = {
    { gUnkJp_0814F25C, gUnk_09EDB7EC, 12, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F270, gUnk_09EDB844, 14, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F284, gUnk_09EDD46C, 16, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F298, gUnk_09EDB890, 18, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E57C, gUnk_09EDD3B4, 16, 0, gUnk_099A87C0, gUnk_09A3CCDC, gUnk_099E5E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E59C, gUnk_09EDD404, 16, 0, gUnk_099A8758, gUnk_09A3CC9C, gUnk_099E3E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E5CC, gUnk_09EDB8E8, 16, 0, gUnk_099A87F8, gUnk_09A3CCFC, gUnk_099E6E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E590, gUnk_09EDB92C, 26, 0, gUnk_099A8824, gUnk_09A3CD1C, gUnk_099E7E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E5B8, gUnk_09EDD4B4, 19, 0, gUnk_099A88A0, gUnk_09A3CD7C, gUnk_099EAE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E5AC, gUnk_09EDB9AC, 22, 0, gUnk_099A884C, gUnk_09A3CD3C, gUnk_099E8E7C, 0, 0, 0, 0, 0, 0, 0, 0, -8, 0 },
    { gUnkJp_0814E5E4, gUnk_09EDDD48, 21, 0, gUnk_099A8880, gUnk_09A3CD5C, gUnk_099E9E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E5F4, gUnk_09EDBA10, 22, 0, gUnk_099A88D4, gUnk_09A3CD9C, gUnk_099EBE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E618, gUnk_09EDBA7C, 21, 0, gUnk_099A8930, gUnk_09A3CE1C, gUnk_099EEE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E604, gUnk_09EDDDAC, 10, 0, gUnk_099A8900, gUnk_09A3CDBC, gUnk_099ECE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E644, gUnk_09EDBAE0, 10, 0, gUnk_099A895C, gUnk_09A3CE3C, gUnk_099EFE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E62C, gUnk_09EDD50C, 11, 0, gUnk_099A8780, gUnk_09A3CCBC, gUnk_099E4E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E658, gUnk_09EDDE38, 16, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08155B04[6] = {
    { gUnkJp_0814FA18, gUnk_09EDD698, 28, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814FA2C, gUnk_09EDBB1C, 16, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814FA40, gUnk_09EDBB84, 13, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814FA54, gUnk_09EDD73C, 14, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814FA68, gUnk_09EDBBD4, 16, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814FA7C, gUnk_09EDD78C, 23, 0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08155C54[17] = {
    { gUnkJp_0814E664, gUnk_09EDD928, 11, 0, gCardWep01Frame0, gCardWep01Palette, gCardWep01Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E678, gUnk_09EDD958, 11, 0, gCardWep04Frame0, gCardWep04Palette, gCardWep04Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E68C, gUnk_09EDD984, 13, 0, gCardWep05Frame0, gCardWep05Palette, gCardWep05Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E6A0, gUnk_09EDD9B4, 12, 0, gCardWep06Frame0, gCardWep06Palette, gCardWep06Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E6B4, gUnk_09EDD9E4, 11, 0, gCardWep07Frame0, gCardWep07Palette, gCardWep07Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E6C8, gUnk_09EDDA10, 11, 0, gCardWep08Frame0, gCardWep08Palette, gCardWep08Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E6DC, gUnk_09EDDA3C, 10, 0, gCardWep09Frame0, gCardWep09Palette, gCardWep09Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E6F0, gUnk_09EDDA68, 11, 0, gCardWep10Frame0, gCardWep10Palette, gCardWep10Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E700, gUnk_09EDDA98, 12, 0, gCardWep03Frame0, gCardWep03Palette, gCardWep03Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E714, gUnk_09EDDAC8, 10, 0, gCardWep11Frame0, gCardWep11Palette, gCardWep11Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E724, gUnk_09EDDAF4, 12, 0, gCardWep12Frame0, gCardWep12Palette, gCardWep12Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E734, gUnk_09EDDB20, 12, 0, gCardWep13Frame0, gCardWep13Palette, gCardWep13Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E748, gUnk_09EDDB50, 10, 0, gCardWep14Frame0, gCardWep14Palette, gCardWep14Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E758, gUnk_09EDDB7C, 11, 0, gCardWep15Frame0, gCardWep15Palette, gCardWep15Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E780, gUnk_09EDDBAC, 12, 0, gCardWep18Frame0, gCardWep18Palette, gCardWep18Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E794, gUnk_09EDDBDC, 12, 0, gCardWep19Frame0, gCardWep19Palette, gCardWep19Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E76C, gUnk_09EDDE98, 10, 0, gCardWep16Frame0, gCardWep16Palette, gCardWep16Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815600C[14] = {
    { gUnkJp_0814E7A0, gUnk_09EDCCAC, 5, 0, gCardMgc01Frame0, gCardMgc01Palette, gCardMgc01Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7AC, gUnk_09EDCCBC, 5, 0, gCardMgc02Frame0, gCardMgc02Palette, gCardMgc02Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7B8, gUnk_09EDCCCC, 5, 0, gCardMgc03Frame0, gCardMgc03Palette, gCardMgc03Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7C4, gUnk_09EDCCE0, 4, 0, gCardMgc04Frame0, gCardMgc04Palette, gCardMgc04Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7CC, gUnk_09EDCCEC, 5, 0, gCardMgc05Frame0, gCardMgc05Palette, gCardMgc05Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7D8, gUnk_09EDCD00, 5, 0, gCardMgc06Frame0, gCardMgc06Palette, gCardMgc06Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7E4, gUnk_09EDCD14, 6, 0, gCardMgc07Frame0, gCardMgc07Palette, gCardMgc07Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7EC, gUnk_09EDCD28, 5, 0, gCardSmn03Frame0, gCardSmn03Palette, gCardSmn03Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E814, gUnk_09EDCD40, 4, 0, gCardSmn06Frame0, gCardSmn06Palette, gCardSmn06Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E80C, gUnk_09EDCD58, 4, 0, gCardSmn05Frame0, gBanbPalette, gCardSmn05Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E828, gUnk_09EDCD68, 4, 0, gCardSmn08Frame0, gMushuPalette, gCardSmn08Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E7F4, gUnk_09EDCD7C, 4, 0, gCardSmn04Frame0, gCardSmn04Palette, gCardSmn04Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E81C, gUnk_09EDCD90, 4, 0, gCardSmn07Frame0, gTinkPalette, gCardSmn07Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E834, gUnk_09EDCDA0, 3, 0, gCardSmn09Frame0, gCardSmn09Palette, gCardSmn09Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815631C[7] = {
    { gUnkJp_0814E840, gUnk_09EDCDB0, 5, 0, gCardItm01Frame0, gCardItm01Palette, gCardItm01Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E84C, gUnk_09EDCDC4, 5, 0, gCardItm02Frame0, gCardItm02Palette, gCardItm02Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E85C, gUnk_09EDCDD8, 6, 0, gCardItm03Frame0, gCardItm03Palette, gCardItm03Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E86C, gUnk_09EDCDF0, 5, 0, gCardItm04Frame0, gCardItm04Palette, gCardItm04Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E878, gUnk_09EDCE04, 6, 0, gCardItm05Frame0, gCardItm05Palette, gCardItm05Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E888, gUnk_09EDCE1C, 4, 0, gCardItm06Frame0, gCardItm06Palette, gCardItm06Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E894, gUnk_09EDCE2C, 6, 0, gCardItm07Frame0, gCardItm07Palette, gCardItm07Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081564A4[7] = {
    { gUnkJp_0814E8A8, gUnk_09EDCE44, 5, 0, gCardSmn02Frame0, gDonaldPalette, gCardSmn02Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E8B8, gUnk_09EDCE58, 4, 0, gCardSmn01Frame0, gGoofyPalette, gCardSmn01Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E8DC, gUnk_09EDCE68, 4, 0, gCardSmn10Frame0, gAladdinPalette, gCardSmn10Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E8F4, gUnk_09EDCE7C, 5, 0, gCardSmn12Frame0, gJackPalette, gCardSmn12Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E8E8, gUnk_09EDCE90, 4, 0, gCardSmn11Frame0, gArielPalette, gCardSmn11Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E900, gUnk_09EDCEA4, 3, 0, gCardSmn13Frame0, gPeterPalette, gCardSmn13Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E910, gUnk_09EDCEB4, 3, 0, gCardSmn14Frame0, gBeastPalette, gCardSmn14Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815662C[49] = {
    { gUnkJp_0814E9EC, gUnk_09EDCEC8, 5, 0, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E9F8, gUnk_09EDCEDC, 5, 0, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA28, gUnk_09EDCEF0, 6, 0, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA78, gUnk_09EDCF08, 5, 0, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA8C, gUnk_09EDCF1C, 5, 0, gUnk_0904B1A8, gEmy02Palette, gUnk_0904B1BC, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAA0, gUnk_09EDCF30, 5, 0, gUnk_0904B3BC, gEmy03Palette, gUnk_0904B3D0, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAB0, gUnk_09EDCF44, 5, 0, gUnk_0904B5D0, gEmy04Palette, gUnk_0904B5E4, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA04, gUnk_09EDCF58, 8, 0, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA14, gUnk_09EDCF78, 5, 0, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAD0, gUnk_09EDCF90, 5, 0, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA5C, gUnk_09EDCFA0, 5, 0, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA38, gUnk_09EDCFB8, 6, 0, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAE0, gUnk_09EDCFD0, 5, 0, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB20, gUnk_09EDDDD0, 7, 0, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA50, gUnk_09EDCFE0, 5, 0, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB40, gUnk_09EDCFF4, 5, 0, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB30, gUnk_09EDD008, 5, 0, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAF4, gUnk_09EDD020, 5, 0, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB14, gUnk_09EDD034, 5, 0, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA6C, gUnk_09EDD04C, 5, 0, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB04, gUnk_09EDD060, 5, 0, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB54, gUnk_09EDD078, 5, 0, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB70, gUnk_09EDD08C, 6, 0, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB64, gUnk_09EDDDEC, 5, 0, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAC4, gUnk_09EDD0A8, 6, 0, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EBE0, gUnk_09EDD0C0, 5, 0, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB80, gUnk_09EDD0D4, 5, 0, gCardEmy07Frame0, gEmy07Palette, gCardEmy07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB98, gUnk_09EDD0EC, 5, 0, gCardEmy08Frame0, gEmy07bPalette, gCardEmy08Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EBAC, gUnk_09EDD100, 5, 0, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EBC0, gUnk_09EDDE04, 6, 0, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EBD4, gUnk_09EDD118, 6, 0, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EBF0, gUnk_09EDD130, 6, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC3C, gUnk_09EDDC3C, 7, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC08, gUnk_09EDDC70, 7, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC70, gUnk_09EDDC0C, 7, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814FB0C, gUnk_09EDDCA8, 5, 0, gCardNpcAw04Frame0, gTrumpHPalette, gCardNpcAw04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC00, gUnk_09EDD144, 8, 0, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC1C, gUnk_09EDDC90, 5, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC34, gUnk_09EDDC24, 6, 0, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC28, gUnk_09EDD168, 7, 0, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC50, gUnk_09EDD184, 8, 0, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC58, gUnk_09EDD1A4, 6, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E924, gUnk_09EDD1BC, 9, 0, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E9B8, gUnk_09EDD1DC, 7, 0, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E9AC, gUnk_09EDD1F8, 6, 0, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E9C4, gUnk_09EDD214, 8, 0, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E9D0, gUnk_09EDD238, 13, 0, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EE88, gUnk_09EDD37C, 11, 0, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EE94, gUnk_09EDDC54, 9, 0, gCardBos18Frame0, gCardBos18Palette, gCardBos18Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081570E4[26] = {
    { gUnkJp_0814F364, gUnk_09EDD26C, 2, 0, gCardRoom02Frame0, gCardRoom02Palette, gCardRoom02Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F358, gUnk_09EDDCBC, 5, 0, gCardRoom01Frame0, gCardRoom01Palette, gCardRoom01Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F3A8, gUnk_09EDD294, 2, 0, gCardRoom07Frame0, gCardRoom07Palette, gCardRoom07Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F3B8, gUnk_09EDDCE0, 5, 0, gCardRoom08Frame0, gCardRoom08Palette, gCardRoom08Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F390, gUnk_09EDD280, 3, 0, gCardRoom05Frame0, gCardRoom05Palette, gCardRoom05Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F380, gUnk_09EDDCCC, 5, 0, gCardRoom04Frame0, gCardRoom04Palette, gCardRoom04Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F484, gUnk_09EDD32C, 3, 0, gCardRoom20Frame0, gCardRoom20Palette, gCardRoom20Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F494, gUnk_09EDD338, 4, 0, gCardRoom21Frame0, gCardRoom21Palette, gCardRoom21Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F4A4, gUnk_09EDD34C, 4, 0, gCardRoom22Frame0, gCardRoom22Palette, gCardRoom22Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F408, gUnk_09EDD2D0, 2, 0, gCardRoom13Frame0, gCardRoom13Palette, gCardRoom13Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F3F8, gUnk_09EDD2C4, 2, 0, gCardRoom12Frame0, gCardRoom12Palette, gCardRoom12Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F418, gUnk_09EDD2DC, 2, 0, gCardRoom14Frame0, gCardRoom14Palette, gCardRoom14Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F428, gUnk_09EDD2E8, 3, 0, gCardRoom15Frame0, gCardRoom15Palette, gCardRoom15Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F474, gUnk_09EDD324, 3, 0, gCardRoom19Frame0, gCardRoom19Palette, gCardRoom19Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F448, gUnk_09EDD304, 4, 0, gCardRoom17Frame0, gCardRoom17Palette, gCardRoom17Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F460, gUnk_09EDD314, 4, 0, gCardRoom18Frame0, gCardRoom18Palette, gCardRoom18Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F3C8, gUnk_09EDD2A0, 1, 0, gCardRoom09Frame0, gCardRoom09Palette, gCardRoom09Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F374, gUnk_09EDD274, 2, 0, gCardRoom03Frame0, gCardRoom03Palette, gCardRoom03Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F3D8, gUnk_09EDD2A8, 4, 0, gCardRoom10Frame0, gCardRoom10Palette, gCardRoom10Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F39C, gUnk_09EDD28C, 3, 0, gCardRoom06Frame0, gCardRoom06Palette, gCardRoom06Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F438, gUnk_09EDD2FC, 2, 0, gCardRoom16Frame0, gCardRoom16Palette, gCardRoom16Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F3E8, gUnk_09EDD2B8, 2, 0, gCardRoom11Frame0, gCardRoom11Palette, gCardRoom11Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F4B4, gUnk_09EDD35C, 2, 0, gCardEve00Frame0, gCardEve00Palette, gCardEve00Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F4CC, gUnk_09EDD364, 2, 0, gCardEve01Frame0, gCardEve01Palette, gCardEve01Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F4E4, gUnk_09EDD36C, 2, 0, gCardEve02Frame0, gCardEve02Palette, gCardEve02Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814F4F8, gUnk_09EDD374, 2, 0, gCardRoom23Frame0, gCardRoom23Palette, gCardRoom23Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08157694[1] = {
    { gUnkJp_0814FAB8, gUnk_09EDDCF4, 13, 0, gUnk_08C6AA58, gUnk_08F6E164, gUnk_08C6AA7E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081576CC[22] = {
    { gUnkJp_0814EEA8, gUnk_09EDBC30, 3, 0, gCardWep20Frame0, gCardWep20Palette, gCardWep20Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EEA0, gUnk_09EDDD38, 4, 0, gCardSmn15Frame0, gMickeyPalette, gCardSmn15Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E9EC, gUnk_09EDCEC8, 5, 0, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA28, gUnk_09EDCEF0, 6, 0, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA04, gUnk_09EDCF58, 8, 0, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA38, gUnk_09EDCFB8, 6, 0, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB20, gUnk_09EDDDD0, 7, 0, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA50, gUnk_09EDCFE0, 5, 0, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EAF4, gUnk_09EDD020, 5, 0, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EA6C, gUnk_09EDD04C, 5, 0, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EB70, gUnk_09EDD08C, 6, 0, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EBF0, gUnk_09EDD130, 6, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC3C, gUnk_09EDDC3C, 7, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC08, gUnk_09EDDC70, 7, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC70, gUnk_09EDDC0C, 7, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC00, gUnk_09EDD144, 8, 0, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC1C, gUnk_09EDDC90, 5, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC34, gUnk_09EDDC24, 6, 0, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC28, gUnk_09EDD168, 7, 0, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC50, gUnk_09EDD184, 8, 0, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EC58, gUnk_09EDD1A4, 6, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814EE88, gUnk_09EDD37C, 11, 0, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08157B9C[25] = {
    { gUnkJp_0814E91C, gUnk_09EDBC40, 8, 0, gSor1fl00Frame0, gSoraPalette, gSor1fl00Tiles, gCardNpcEx00Frame0, gCardNpcEx00Palette, gCardNpcEx00Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { gUnkJp_0814E8A8, gUnk_09EDBC7C, 10, 0, gDonaFl00Frame0, gDonaldPalette, gDonaFl00Tiles, gCardSmn02Frame0, gDonaldPalette, gCardSmn02Tiles, 0, 0, 0, 0, 0, 0, -9 },
    { gUnkJp_0814E8B8, gUnk_09EDBCBC, 9, 0, gGoofyFl00Frame0, gGoofyPalette, gGoofyFl00Tiles, gCardSmn01Frame0, gGoofyPalette, gCardSmn01Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E8C4, gUnk_09EDBCEC, 6, 0, gJimFl00Frame0, gJiminyPalette, gJimFl00Tiles, gCardNpcEx01Frame0, gCardNpcEx01Palette, gCardNpcEx01Tiles, 0, 0, 0, 0, 0, -3, -11 },
    { gUnkJp_0814E924, gUnk_09EDBD08, 10, 0, gRikuFl00Frame0, gRikuPalette, gRikuFl00Tiles, gCardNpcEx03Frame0, gCardNpcEx03Palette, gCardNpcEx03Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnkJp_0814E92C, gUnk_09EDD54C, 10, 0, gKairF00Frame0, gKairiPalette, gKairF00Tiles, gCardNpcEx05Frame0, gCardNpcEx05Palette, gCardNpcEx05Tiles, 0, 0, 0, 0, 0, -1, -3 },
    { gUnkJp_0814E7EC, gUnk_09EDBD48, 7, 0, gShinba10Frame0, gShinbaPalette, gShinba10Tiles, gCardSmn03Frame0, gCardSmn03Palette, gCardSmn03Tiles, 0, 0, 0, 0, 0, -2, -7 },
    { gUnkJp_0814E814, gUnk_09EDBD64, 8, 0, gUnk_088ABEF4, gDamboPalette, gUnk_088ABF88, gCardSmn06Frame0, gCardSmn06Palette, gCardSmn06Tiles, 0, 0, 0, 0, 0, 8, -7 },
    { gUnkJp_0814E80C, gUnk_09EDBD90, 5, 0, gBanb00Frame7, gBanbPalette, gBanb00Tiles, gCardSmn05Frame0, gBanbPalette, gCardSmn05Tiles, 0, 0, 0, 0, 0, -2, -7 },
    { gUnkJp_0814E828, gUnk_09EDBDA8, 6, 0, gMushuF00Frame1, gMushuPalette, gMushuF00Tiles, gCardSmn08Frame0, gMushuPalette, gCardSmn08Tiles, 0, 0, 0, 0, 0, 0, -12 },
    { gUnkJp_0814E998, gUnk_09EDBDC8, 5, 0, gMoguFl00Frame0, gMoguPalette, gMoguFl00Tiles, gCardNpcEx02Frame0, gCardNpcEx02Palette, gCardNpcEx02Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnkJp_0814E964, gUnk_09EDBDE8, 9, 0, gReonFl00Frame0, gReonPalette, gReonFl00Tiles, gCardNpcEx09Frame0, gCardNpcEx09Palette, gCardNpcEx09Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { gUnkJp_0814E93C, gUnk_09EDBE1C, 6, 0, gYuffieFl00Frame0, gYuffiePalette, gYuffieFl00Tiles, gCardNpcEx10Frame0, gCardNpcEx10Palette, gCardNpcEx10Tiles, 0, 0, 0, 0, 0, -1, 2 },
    { gUnkJp_0814E944, gUnk_09EDBE48, 8, 0, gEarF00Frame0, gEarisPalette, gEarF00Tiles, gCardNpcEx06Frame0, gCardNpcEx06Palette, gCardNpcEx06Tiles, 0, 0, 0, 0, 0, -3, 4 },
    { gUnkJp_0814E990, gUnk_09EDBE78, 5, 0, gShidoF00Frame0, gShidoPalette, gShidoF00Tiles, gCardNpcEx07Frame0, gCardNpcEx07Palette, gCardNpcEx07Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { gUnkJp_0814E834, gUnk_09EDBE98, 8, 0, gCroudF00Frame0, gCroudPalette, gCroudF00Tiles, gCardSmn09Frame0, gCardSmn09Palette, gCardSmn09Tiles, 0, 0, 0, 0, 0, -3, 2 },
    { gUnkJp_0814E984, gUnk_09EDD588, 5, 0, gTidusFl00Frame0, gTidusPalette, gTidusFl00Tiles, gCardNpcDi01Frame0, gCardNpcDi01Palette, gCardNpcDi01Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnkJp_0814E950, gUnk_09EDD5AC, 5, 0, gWakkaF00Frame0, gWakkaPalette, gWakkaF00Tiles, gCardNpcDi02Frame0, gCardNpcDi02Palette, gCardNpcDi02Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E978, gUnk_09EDD5C8, 5, 0, gSelphieFl00Frame0, gSelphiePalette, gSelphieFl00Tiles, gCardNpcDi03Frame0, gCardNpcDi03Palette, gCardNpcDi03Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnkJp_0814E934, gUnk_09EDBEC0, 11, 0, gNamiF00Frame0, gNaminePalette, gNamiF00Tiles, gCardNpcCom01Frame0, gCardNpcCom01Palette, gCardNpcCom01Tiles, 0, 0, 0, 0, 0, -1, -4 },
    { gUnkJp_0814FA90, gUnk_09EDBEFC, 7, 0, gNiseFl00Frame0, gNiserikuPalette, gNiseFl00Tiles, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnkJp_0814E9B8, gUnk_09EDBF2C, 6, 0, gAcceleFl00Frame0, gAccelePalette, gAcceleFl00Tiles, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814E9AC, gUnk_09EDD5E8, 7, 0, gLaxineFl00Frame0, gLaxinePalette, gLaxineFl00Tiles, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { gUnkJp_0814E9C4, gUnk_09EDBF58, 6, 0, gVixenFl00Frame0, gVixenPalette, gVixenFl00Tiles, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814E9D0, gUnk_09EDBF84, 6, 0, gMaruxha2Fl00Frame0, gMaruxhaPalette, gMaruxha2Fl00Tiles, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, 0, 0, 0, 0, 0, -3, 6 },
};

const JiminyDetail gUnk_08158114[40] = {
    { gUnkJp_0814ED50, gUnk_09EDC1E0, 8, 0, gAliceFl00Frame0, gAlicePalette, gAliceFl00Tiles, gCardNpcAw01Frame0, gCardNpcAw01Palette, gCardNpcAw01Tiles, 0, 0, 0, 0, 0, -1, -1 },
    { gUnkJp_0814ED58, gUnk_09EDC20C, 6, 0, gQenF00Frame0, gQeenPalette, gQenF00Tiles, gCardNpcAw02Frame0, gCardNpcAw02Palette, gCardNpcAw02Tiles, 0, 0, 0, 0, 0, -3, 4 },
    { gUnkJp_0814ED68, gUnk_09EDC22C, 4, 0, gUsagif00Frame0, gUsagi00Palette, gUsagif00Tiles, gCardNpcAw05Frame0, gCardNpcAw05Palette, gCardNpcAw05Tiles, 0, 0, 0, 0, 0, 0, -10 },
    { gUnkJp_0814ED8C, gUnk_09EDC248, 4, 0, gTrumpH00Frame0, gTrumpHPalette, gTrumpH00Tiles, gCardNpcAw04Frame0, gTrumpHPalette, gCardNpcAw04Tiles, 0, 0, 0, 0, 0, 0, 2 },
    { gUnkJp_0814ED74, gUnk_09EDC260, 4, 0, gTrumpS00Frame0, gTrumpSPalette, gTrumpS00Tiles, gCardNpcAw03Frame0, gTrumpSPalette, gCardNpcAw03Tiles, 0, 0, 0, 0, 0, 0, 2 },
    { gUnkJp_0814EDA0, gUnk_09EDC278, 6, 0, gCheshireFrame0, gCheshirePalette, gCheshireTiles, gCardNpcAw06Frame0, gCardNpcAw06Palette, gCardNpcAw06Tiles, 0, 0, 0, 0, 0, -4, -12 },
    { gUnkJp_0814ED3C, gUnk_09EDC178, 7, 0, gHeraclesFl00Frame0, gHeraclesPalette, gHeraclesFl00Tiles, gCardNpcHe02Frame0, gCardNpcHe02Palette, gCardNpcHe02Tiles, 0, 0, 0, 0, 0, 0, 13 },
    { gUnkJp_0814ED48, gUnk_09EDC1A0, 6, 0, gPhilFl00Frame0, gPhilPalette, gPhilFl00Tiles, gCardNpcHe01Frame0, gCardNpcHe01Palette, gCardNpcHe01Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { gUnkJp_0814EC00, gUnk_09EDC1BC, 7, 0, gHadesFl00Frame0, gHadesPalette, gHadesFl00Tiles, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, 0, 0, 0, 0, 0, 0, 18 },
    { gUnkJp_0814E8DC, gUnk_09EDBFAC, 11, 0, gAladdin00Frame0, gAladdinPalette, gAladdin00Tiles, gCardSmn10Frame0, gAladdinPalette, gCardSmn10Tiles, 0, 0, 0, 0, 0, -2, 6 },
    { gUnkJp_0814E7F4, gUnk_09EDBFEC, 8, 0, gGenie01Frame2, gGeniePalette, gGenie01Tiles, gCardSmn04Frame0, gCardSmn04Palette, gCardSmn04Tiles, 0, 0, 0, 0, 0, 2, 1 },
    { gUnkJp_0814ECDC, gUnk_09EDC018, 5, 0, gJasmineF00Frame0, gJasminePalette, gJasmineF00Tiles, gCardNpcAl01Frame0, gCardNpcAl01Palette, gCardNpcAl01Tiles, 0, 0, 0, 0, 0, -4, 5 },
    { gUnkJp_0814ECE8, gUnk_09EDC030, 5, 0, gUnk_09393218, gUnk_09618358, gUnk_0939322C, gCardNpcAl03Frame0, gCardNpcAl03Palette, gCardNpcAl03Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { gUnkJp_0814EC1C, gUnk_09EDC04C, 6, 0, gJafferFl00Frame0, gJafferPalette, gJafferFl00Tiles, gCardNpcAl02Frame0, gCardNpcAl02Palette, gCardNpcAl02Tiles, 0, 0, 0, 0, 0, -3, 19 },
    { gUnkJp_0814ECF4, gUnk_09EDC06C, 6, 0, 0, 0, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_08F67384, gUnk_08F6E104, gUnk_08EEC044, 32, 3744, 0, 0 },
    { gUnkJp_0814E8F4, gUnk_09EDC088, 6, 0, gJackFl00Frame0, gJackPalette, gJackFl00Tiles, gCardSmn12Frame0, gJackPalette, gCardSmn12Tiles, 0, 0, 0, 0, 0, 2, 11 },
    { gUnkJp_0814ED00, gUnk_09EDC0A4, 6, 0, gSariFl00Frame0, gSariPalette, gSariFl00Tiles, gCardNpcNm01Frame0, gCardNpcNm01Palette, gCardNpcNm01Tiles, 0, 0, 0, 0, 0, -2, 7 },
    { gUnkJp_0814ED08, gUnk_09EDC0C0, 8, 0, gFinklF00Frame0, gFinklPalette, gFinklF00Tiles, gCardNpcNm02Frame0, gCardNpcNm02Palette, gCardNpcNm02Tiles, 0, 0, 0, 0, 0, -1, -7 },
    { gUnkJp_0814EC34, gUnk_09EDC0E8, 7, 0, gBugiFl00Frame0, gBugiPalette, gBugiFl00Tiles, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnkJp_0814ED1C, gUnk_09EDC10C, 10, 0, gPinoF00Frame0, gPinokioPalette, gPinoF00Tiles, gCardNpcPi01Frame0, gCardNpcPi01Palette, gCardNpcPi01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnkJp_0814ED28, gUnk_09EDC140, 10, 0, gGeppettoF00Frame0, gGeppettoPalette, gGeppettoF00Tiles, gCardNpcPi02Frame0, gCardNpcPi02Palette, gCardNpcPi02Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { gUnkJp_0814E8E8, gUnk_09EDD61C, 12, 0, gArielF00Frame0, gArielPalette, gArielF00Tiles, gCardSmn11Frame0, gArielPalette, gCardSmn11Tiles, 0, 0, 0, 0, 0, -4, 3 },
    { gUnkJp_0814EDAC, gUnk_09EDC298, 6, 0, gSebastianFl00Frame0, gSebastianPalette, gSebastianFl00Tiles, gCardNpcLm01Frame0, gCardNpcLm01Palette, gCardNpcLm01Tiles, 0, 0, 0, 0, 0, -1, -13 },
    { gUnkJp_0814EDBC, gUnk_09EDC2B8, 7, 0, gFlounderFl00Frame0, gFlounderPalette, gFlounderFl00Tiles, gCardNpcLm02Frame0, gCardNpcLm02Palette, gCardNpcLm02Tiles, 0, 0, 0, 0, 0, -1, -17 },
    { gUnkJp_0814EC28, gUnk_09EDC2E0, 6, 0, gArthraFl00Frame0, gArthraPalette, gArthraFl00Tiles, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814E900, gUnk_09EDC304, 9, 0, gPeterFl00Frame0, gPeterPalette, gPeterFl00Tiles, gCardSmn13Frame0, gPeterPalette, gCardSmn13Tiles, 0, 0, 0, 0, 0, -3, 5 },
    { gUnkJp_0814E81C, gUnk_09EDC338, 4, 0, gTinkF00Frame2, gTinkPalette, gTinkF00Tiles, gCardSmn07Frame0, gTinkPalette, gCardSmn07Tiles, 0, 0, 0, 0, 0, -5, -10 },
    { gUnkJp_0814EDD4, gUnk_09EDC348, 6, 0, gWendyFl00Frame0, gWendyPalette, gWendyFl00Tiles, gCardNpcPp01Frame0, gCardNpcPp01Palette, gCardNpcPp01Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnkJp_0814EDE0, gUnk_09EDC364, 8, 0, gHookF00Frame0, gHookPalette, gHookF00Tiles, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, 0, 0, 0, 0, 0, -1, 17 },
    { gUnkJp_0814E910, gUnk_09EDC394, 10, 0, gBeastFl00Frame0, gBeastPalette, gBeastFl00Tiles, gCardSmn14Frame0, gBeastPalette, gCardSmn14Tiles, 0, 0, 0, 0, 0, -1, 10 },
    { gUnkJp_0814EDE8, gUnk_09EDC3BC, 9, 0, gBellFl00Frame0, gBellPalette, gBellFl00Tiles, gCardNpcPc01Frame0, gCardNpcPc01Palette, gCardNpcPc01Tiles, 0, 0, 0, 0, 0, -4, 5 },
    { gUnkJp_0814EDF0, gUnk_09EDC3E8, 9, 0, gMarefF00Frame0, gMarefPalette, gMarefF00Tiles, gCardNpcPc02Frame0, gCardNpcPc02Palette, gCardNpcPc02Tiles, 0, 0, 0, 0, 0, -12, 16 },
    { gUnkJp_0814EC58, gUnk_09EDC414, 5, 0, 0, 0, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_08F67B84, gUnk_08F6E124, gUnk_08EECEE4, 64, 5280, 0, 0 },
    { gUnkJp_0814EE00, gUnk_09EDD658, 6, 0, gPoohFl06Frame0, gPoohPalette, gPoohFl06Tiles, gCardNpcPo01Frame0, gCardNpcPo01Palette, gCardNpcPo01Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnkJp_0814EE08, gUnk_09EDC434, 6, 0, gUnk_09742FC4, gUnk_09849C18, gUnk_09742FD8, gCardNpcPo03Frame0, gCardNpcPo03Palette, gCardNpcPo03Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { gUnkJp_0814EE14, gUnk_09EDC44C, 5, 0, gOwlFl00Frame0, gOwlPalette, gOwlFl00Tiles, gCardNpcPo06Frame0, gCardNpcPo06Palette, gCardNpcPo06Tiles, 0, 0, 0, 0, 0, -3, -7 },
    { gUnkJp_0814EE1C, gUnk_09EDC464, 5, 0, gRooFl00Frame0, gRooPalette, gRooFl00Tiles, gCardNpcPo07Frame0, gCardNpcPo07Palette, gCardNpcPo07Tiles, 0, 0, 0, 0, 0, -1, -13 },
    { gUnkJp_0814EE24, gUnk_09EDC47C, 5, 0, gEeyoreFl00Frame0, gEeyorePalette, gEeyoreFl00Tiles, gCardNpcPo04Frame0, gCardNpcPo04Palette, gCardNpcPo04Tiles, 0, 0, 0, 0, 0, 5, -13 },
    { gUnkJp_0814EE30, gUnk_09EDC49C, 6, 0, gTiggerFl00Frame0, gTiggerPalette, gTiggerFl00Tiles, gCardNpcPo02Frame0, gCardNpcPo02Palette, gCardNpcPo02Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { gUnkJp_0814EE3C, gUnk_09EDC4BC, 6, 0, gRabbitFl00Frame0, gRabbitPalette, gRabbitFl00Tiles, gCardNpcPo05Frame0, gCardNpcPo05Palette, gCardNpcPo05Tiles, 0, 0, 0, 0, 0, -1, -3 },
};

const JiminyDetail gUnk_081589D4[35] = {
    { gUnkJp_0814E9EC, gUnk_09EDC540, 7, 0, gEmy00L00Frame0, gEmy00Palette, gEmy00L00Tiles, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, 0, 0, 0, 0, 0, 2, -12 },
    { gUnkJp_0814E9F8, gUnk_09EDC564, 5, 0, gEmy14Ll01Frame1, gEmy14Palette, gEmy14Ll01Tiles, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, 0, 0, 0, 0, 0, -8, 2 },
    { gUnkJp_0814EA28, gUnk_09EDC580, 8, 0, gEmy3800Frame0, gEmy38Palette, gEmy3800Tiles, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, 0, 0, 0, 0, 0, -6, 6 },
    { gUnkJp_0814EA78, gUnk_09EDC5A8, 8, 0, gEmy01L00Frame16, gEmy01Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnkJp_0814EA8C, gUnk_09EDC5CC, 6, 0, gEmy01L00Frame3, gEmy02Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy02Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -1, -11 },
    { gUnkJp_0814EAA0, gUnk_09EDC5F0, 6, 0, gEmy01L00Frame0, gEmy03Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy03Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -11 },
    { gUnkJp_0814EAB0, gUnk_09EDC614, 8, 0, gEmy01L00Frame15, gEmy04Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy04Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnkJp_0814EA04, gUnk_09EDC640, 6, 0, gEmy1500Frame7, gEmy15Palette, gEmy1500Tiles, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, 0, 0, 0, 0, 0, 0, -6 },
    { gUnkJp_0814EA14, gUnk_09EDC65C, 6, 0, gEmy1600Frame0, gEmy16Palette, gEmy1600Tiles, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, 0, 0, 0, 0, 0, -1, -9 },
    { gUnkJp_0814EAD0, gUnk_09EDC674, 7, 0, gEmy1800Frame0, gEmy18Palette, gEmy1800Tiles, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, 0, 0, 0, 0, 0, -1, 3 },
    { gUnkJp_0814EA5C, gUnk_09EDC69C, 5, 0, gEmy1900Frame5, gEmy19Palette, gEmy1900Tiles, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, 0, 0, 0, 0, 0, -1, -6 },
    { gUnkJp_0814EA38, gUnk_09EDC6B8, 6, 0, gEmy3900Frame0, gEmy39Palette, gEmy3900Tiles, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnkJp_0814EAE0, gUnk_09EDC6D4, 6, 0, gEmy2100Frame0, gEmy21Palette, gEmy2100Tiles, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, 0, 0, 0, 0, 0, 1, -10 },
    { gUnkJp_0814EB20, gUnk_09EDC6F8, 5, 0, gEmy2200Frame9, gEmy22Palette, gEmy2200Tiles, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, 0, 0, 0, 0, 0, 2, 6 },
    { gUnkJp_0814EA50, gUnk_09EDDE18, 7, 0, gEmy0600Frame2, gEmy06Palette, gEmy0600Tiles, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnkJp_0814EB40, gUnk_09EDC714, 4, 0, gEmy2300Frame0, gEmy23Palette, gEmy2300Tiles, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, 0, 0, 0, 0, 0, 1, 2 },
    { gUnkJp_0814EB30, gUnk_09EDC72C, 5, 0, gEmy4100Frame0, gEmy41Palette, gEmy4100Tiles, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, 0, 0, 0, 0, 0, -2, 11 },
    { gUnkJp_0814EAF4, gUnk_09EDC74C, 5, 0, gEmy2500Frame3, gEmy25Palette, gEmy2500Tiles, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, 0, 0, 0, 0, 0, 4, 0 },
    { gUnkJp_0814EB14, gUnk_09EDC768, 5, 0, gEmy2600Frame0, gEmy26Palette, gEmy2600Tiles, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnkJp_0814EA6C, gUnk_09EDC784, 7, 0, gEmy2700Frame0, gEmy27Palette, gEmy2700Tiles, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, 0, 0, 0, 0, 0, 10, -10 },
    { gUnkJp_0814EB04, gUnk_09EDC7AC, 6, 0, gEmy2800Frame0, gEmy28Palette, gEmy2800Tiles, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, 0, 0, 0, 0, 0, 5, 5 },
    { gUnkJp_0814EB54, gUnk_09EDC7D0, 7, 0, gEmy2900Frame0, gEmy29Palette, gEmy2900Tiles, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { gUnkJp_0814EB70, gUnk_09EDC7F4, 9, 0, gEmy4400Frame0, gEmy44Palette, gEmy4400Tiles, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, 0, 0, 0, 0, 0, 3, 1 },
    { gUnkJp_0814EB64, gUnk_09EDC828, 6, 0, gEmy3000Frame0, gEmy30Palette, gEmy3000Tiles, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, 0, 0, 0, 0, 0, 2, -5 },
    { gUnkJp_0814EAC4, gUnk_09EDC850, 4, 0, gEmy3100Frame6, gEmy31Palette, gEmy3100Tiles, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, 0, 0, 0, 0, 0, 5, -3 },
    { gUnkJp_0814EBE0, gUnk_09EDDEC0, 2, 0, gEmy3700Frame1, gEmy37Palette, gEmy3700Tiles, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnkJp_0814EB80, gUnk_09EDC870, 7, 0, gEmy07Fl00Frame0, gEmy07Palette, gEmy07Fl00Tiles, gCardEmy07Frame0, gEmy07Palette, gCardEmy07Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnkJp_0814EB98, gUnk_09EDC890, 8, 0, gEmy07Fl10tFrame7, gEmy07bPalette, gEmy07Fl10tTiles, gCardEmy08Frame0, gEmy07bPalette, gCardEmy08Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnkJp_0814EBAC, gUnk_09EDC8C0, 7, 0, gEmy8300Frame0, gEmy83Palette, gEmy8300Tiles, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, 0, 0, 0, 0, 0, 0, -4 },
    { gUnkJp_0814EBC0, gUnk_09EDC8E0, 6, 0, gEmy8100Frame0, gEmy81Palette, gEmy8100Tiles, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnkJp_0814EBD4, gUnk_09EDC904, 5, 0, gEmy8201Frame2, gEmy82Palette, gEmy8201Tiles, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, 0, 0, 0, 0, 0, 4, -10 },
    { gUnkJp_0814EBF0, gUnk_09EDC4E0, 4, 0, 0, 0, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_08F65B84, gUnk_08F6E044, gUnk_08EE8E84, 32, 3488, 3, -3 },
    { gUnkJp_0814EC3C, gUnk_09EDC4F8, 8, 0, 0, 0, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_08F66B84, gUnk_08F6E0A4, gUnk_08EEAD44, 96, 4864, 0, 0 },
    { gUnkJp_0814EC08, gUnk_09EDC520, 6, 0, 0, 0, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_08F66384, gUnk_08F6E064, gUnk_08EE9C24, 64, 4384, 0, 3 },
    { gUnkJp_0814EC70, gUnk_09EDD67C, 6, 0, 0, 0, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_08F65384, gUnk_08F6E024, gUnk_08EE7A24, 32, 5216, 0, 0 },
};

const JiminyDetail gUnk_0815917C[14] = {
    { gUnkJp_0814E924, gUnk_09EDD808, 11, 0, gRikuFl00Frame0, gRikuPalette, gRikuFl00Tiles, gCardNpcEx03Frame0, gCardNpcEx03Palette, gCardNpcEx03Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnkJp_0814EEA0, gUnk_09EDD868, 7, 0, gMickeyFl00Frame0, gMickeyPalette, gMickeyFl00Tiles, gCardSmn15Frame0, gMickeyPalette, gCardSmn15Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { gUnkJp_0814E91C, gUnk_09EDC91C, 7, 0, gSor1fl00Frame0, gSoraPalette, gSor1fl00Tiles, gCardNpcEx00Frame0, gCardNpcEx00Palette, gCardNpcEx00Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { gUnkJp_0814E92C, gUnk_09EDD8A4, 10, 0, gKairF00Frame0, gKairiPalette, gKairF00Tiles, gCardNpcEx05Frame0, gCardNpcEx05Palette, gCardNpcEx05Tiles, 0, 0, 0, 0, 0, -1, -3 },
    { gUnkJp_0814E934, gUnk_09EDC950, 8, 0, gNamiF00Frame0, gNaminePalette, gNamiF00Tiles, gCardNpcCom01Frame0, gCardNpcCom01Palette, gCardNpcCom01Tiles, 0, 0, 0, 0, 0, -1, -4 },
    { gUnkJp_0814FA90, gUnk_09EDC990, 7, 0, gNiseFl00Frame0, gNiserikuPalette, gNiseFl00Tiles, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { gUnkJp_0814EE94, gUnk_09EDC9B0, 8, 0, gAnsemFl00Frame0, gAnsemPalette, gAnsemFl00Tiles, gCardBos18Frame0, gCardBos18Palette, gCardBos18Tiles, 0, 0, 0, 0, 0, -3, 9 },
    { gUnkJp_0814E9C4, gUnk_09EDC9E8, 10, 0, gVixenFl00Frame0, gVixenPalette, gVixenFl00Tiles, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814EE88, gUnk_09EDD8E4, 10, 0, gRexeusFl00Frame0, gRexeusPalette, gRexeusFl00Tiles, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, 0, 0, 0, 0, 0, -5, 14 },
    { gUnkJp_0814FA0C, gUnk_09EDCA28, 11, 0, gXexionFl00Frame0, gXexionPalette, gXexionFl00Tiles, gCardNpcCom02Frame0, gCardNpcCom02Palette, gCardNpcCom02Tiles, 0, 0, 0, 0, 0, -1, 6 },
    { gUnkJp_0814E9B8, gUnk_09EDCA6C, 10, 0, gAcceleFl00Frame0, gAccelePalette, gAcceleFl00Tiles, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814E9D0, gUnk_09EDCAB8, 12, 0, gMaruxha2Fl00Frame0, gMaruxhaPalette, gMaruxha2Fl00Tiles, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814E9AC, gUnk_09EDCB04, 9, 0, gLaxineFl00Frame0, gLaxinePalette, gLaxineFl00Tiles, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { gUnkJp_0814FAA0, gUnk_09EDCB38, 7, 0, gDizFl00Frame0, gDizPalette, gDizFl00Tiles, gCardNpcCom03Frame0, gCardNpcCom03Palette, gCardNpcCom03Tiles, 0, 0, 0, 0, 0, -2, 8 },
};

const JiminyDetail gUnk_0815948C[6] = {
    { gUnkJp_0814EDF0, gUnk_09EDCB64, 6, 0, gMarefF00Frame0, gMarefPalette, gMarefF00Tiles, gCardNpcPc02Frame0, gCardNpcPc02Palette, gCardNpcPc02Tiles, 0, 0, 0, 0, 0, -12, 16 },
    { gUnkJp_0814ECF4, gUnk_09EDCB98, 6, 0, 0, 0, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_08F67384, gUnk_08F6E104, gUnk_08EEC044, 32, 3744, 0, 0 },
    { gUnkJp_0814EC28, gUnk_09EDCBB8, 6, 0, gArthraFl00Frame0, gArthraPalette, gArthraFl00Tiles, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { gUnkJp_0814EC00, gUnk_09EDCBDC, 5, 0, gHadesFl00Frame0, gHadesPalette, gHadesFl00Tiles, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, 0, 0, 0, 0, 0, 0, 18 },
    { gUnkJp_0814EC34, gUnk_09EDCBFC, 5, 0, gBugiFl00Frame0, gBugiPalette, gBugiFl00Tiles, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnkJp_0814EDE0, gUnk_09EDCC1C, 4, 0, gHookF00Frame0, gHookPalette, gHookF00Tiles, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, 0, 0, 0, 0, 0, -1, 17 },
};

const JiminyDetail gUnk_081595DC[33] = {
    { gUnkJp_0814E9EC, gUnk_09EDC540, 7, 0, gEmy00L00Frame0, gEmy00Palette, gEmy00L00Tiles, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, 0, 0, 0, 0, 0, 2, -12 },
    { gUnkJp_0814E9F8, gUnk_09EDC564, 5, 0, gEmy14Ll01Frame1, gEmy14Palette, gEmy14Ll01Tiles, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, 0, 0, 0, 0, 0, -8, 2 },
    { gUnkJp_0814EA28, gUnk_09EDC580, 8, 0, gEmy3800Frame0, gEmy38Palette, gEmy3800Tiles, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, 0, 0, 0, 0, 0, -6, 6 },
    { gUnkJp_0814EA78, gUnk_09EDC5A8, 8, 0, gEmy01L00Frame16, gEmy01Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnkJp_0814EA8C, gUnk_09EDC5CC, 6, 0, gEmy01L00Frame3, gEmy02Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy02Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -1, -11 },
    { gUnkJp_0814EAA0, gUnk_09EDC5F0, 6, 0, gEmy01L00Frame0, gEmy03Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy03Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -11 },
    { gUnkJp_0814EAB0, gUnk_09EDC614, 8, 0, gEmy01L00Frame15, gEmy04Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy04Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { gUnkJp_0814EA04, gUnk_09EDC640, 6, 0, gEmy1500Frame7, gEmy15Palette, gEmy1500Tiles, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, 0, 0, 0, 0, 0, 0, -6 },
    { gUnkJp_0814EA14, gUnk_09EDC65C, 6, 0, gEmy1600Frame0, gEmy16Palette, gEmy1600Tiles, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, 0, 0, 0, 0, 0, -1, -9 },
    { gUnkJp_0814EAD0, gUnk_09EDC674, 7, 0, gEmy1800Frame0, gEmy18Palette, gEmy1800Tiles, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, 0, 0, 0, 0, 0, -1, 3 },
    { gUnkJp_0814EA5C, gUnk_09EDC69C, 5, 0, gEmy1900Frame5, gEmy19Palette, gEmy1900Tiles, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, 0, 0, 0, 0, 0, -1, -6 },
    { gUnkJp_0814EA38, gUnk_09EDC6B8, 6, 0, gEmy3900Frame0, gEmy39Palette, gEmy3900Tiles, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnkJp_0814EAE0, gUnk_09EDC6D4, 6, 0, gEmy2100Frame0, gEmy21Palette, gEmy2100Tiles, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, 0, 0, 0, 0, 0, 1, -10 },
    { gUnkJp_0814EB20, gUnk_09EDC6F8, 5, 0, gEmy2200Frame9, gEmy22Palette, gEmy2200Tiles, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, 0, 0, 0, 0, 0, 2, 6 },
    { gUnkJp_0814EA50, gUnk_09EDDE18, 7, 0, gEmy0600Frame2, gEmy06Palette, gEmy0600Tiles, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnkJp_0814EB40, gUnk_09EDC714, 4, 0, gEmy2300Frame0, gEmy23Palette, gEmy2300Tiles, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, 0, 0, 0, 0, 0, 1, 2 },
    { gUnkJp_0814EB30, gUnk_09EDC72C, 5, 0, gEmy4100Frame0, gEmy41Palette, gEmy4100Tiles, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, 0, 0, 0, 0, 0, -2, 11 },
    { gUnkJp_0814EAF4, gUnk_09EDC74C, 5, 0, gEmy2500Frame3, gEmy25Palette, gEmy2500Tiles, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, 0, 0, 0, 0, 0, 4, 0 },
    { gUnkJp_0814EB14, gUnk_09EDC768, 5, 0, gEmy2600Frame0, gEmy26Palette, gEmy2600Tiles, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { gUnkJp_0814EA6C, gUnk_09EDC784, 7, 0, gEmy2700Frame0, gEmy27Palette, gEmy2700Tiles, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, 0, 0, 0, 0, 0, 10, -10 },
    { gUnkJp_0814EB04, gUnk_09EDC7AC, 6, 0, gEmy2800Frame0, gEmy28Palette, gEmy2800Tiles, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, 0, 0, 0, 0, 0, 5, 5 },
    { gUnkJp_0814EB54, gUnk_09EDC7D0, 7, 0, gEmy2900Frame0, gEmy29Palette, gEmy2900Tiles, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { gUnkJp_0814EB70, gUnk_09EDC7F4, 9, 0, gEmy4400Frame0, gEmy44Palette, gEmy4400Tiles, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, 0, 0, 0, 0, 0, 3, 1 },
    { gUnkJp_0814EB64, gUnk_09EDC828, 6, 0, gEmy3000Frame0, gEmy30Palette, gEmy3000Tiles, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, 0, 0, 0, 0, 0, 2, -5 },
    { gUnkJp_0814EAC4, gUnk_09EDC850, 4, 0, gEmy3100Frame6, gEmy31Palette, gEmy3100Tiles, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, 0, 0, 0, 0, 0, 5, -3 },
    { gUnkJp_0814EBE0, gUnk_09EDDEC0, 2, 0, gEmy3700Frame1, gEmy37Palette, gEmy3700Tiles, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { gUnkJp_0814EBAC, gUnk_09EDC8C0, 7, 0, gEmy8300Frame0, gEmy83Palette, gEmy8300Tiles, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, 0, 0, 0, 0, 0, 0, -4 },
    { gUnkJp_0814EBC0, gUnk_09EDC8E0, 6, 0, gEmy8100Frame0, gEmy81Palette, gEmy8100Tiles, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { gUnkJp_0814EBD4, gUnk_09EDC904, 5, 0, gEmy8201Frame2, gEmy82Palette, gEmy8201Tiles, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, 0, 0, 0, 0, 0, 4, -10 },
    { gUnkJp_0814EBF0, gUnk_09EDCC34, 4, 0, 0, 0, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_08F65B84, gUnk_08F6E044, gUnk_08EE8E84, 32, 3488, 3, -3 },
    { gUnkJp_0814EC3C, gUnk_09EDCC50, 4, 0, 0, 0, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_08F66B84, gUnk_08F6E0A4, gUnk_08EEAD44, 96, 4864, 0, 0 },
    { gUnkJp_0814EC08, gUnk_09EDCC6C, 4, 0, 0, 0, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_08F66384, gUnk_08F6E064, gUnk_08EE9C24, 64, 4384, 0, 3 },
    { gUnkJp_0814EC70, gUnk_09EDCC8C, 5, 0, 0, 0, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_08F65384, gUnk_08F6E024, gUnk_08EE7A24, 32, 5216, 0, 0 },
};

#elif defined(VERSION_EU)

const JiminyDetail gUnk_0815574C[17] = {
    { &gUnkEu_08892450, &gUnkEu_0883FB1C, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088924BC, &gUnkEu_088402A4, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889252C, &gUnkEu_08840A14, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892598, &gUnkEu_08841350, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E364, &gUnkEu_08841BD8, gUnk_099A87C0, gUnk_09A3CCDC, gUnk_099E5E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E410, &gUnkEu_088425D4, gUnk_099A8758, gUnk_09A3CC9C, gUnk_099E3E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E530, &gUnkEu_08842D0C, gUnk_099A87F8, gUnk_09A3CCFC, gUnk_099E6E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E3A0, &gUnkEu_08843A70, gUnk_099A8824, gUnk_09A3CD1C, gUnk_099E7E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E4C0, &gUnkEu_088443FC, gUnk_099A88A0, gUnk_09A3CD7C, gUnk_099EAE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E450, &gUnkEu_08844E8C, gUnk_099A884C, gUnk_09A3CD3C, gUnk_099E8E7C, 0, 0, 0, 0, 0, 0, 0, 0, -8, 0 },
    { &gUnkEu_0888E578, &gUnkEu_08845978, gUnk_099A8880, gUnk_09A3CD5C, gUnk_099E9E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E5DC, &gUnkEu_0884642C, gUnk_099A88D4, gUnk_09A3CD9C, gUnk_099EBE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E6BC, &gUnkEu_08846E6C, gUnk_099A8930, gUnk_09A3CE1C, gUnk_099EEE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E654, &gUnkEu_0884721C, gUnk_099A8900, gUnk_09A3CDBC, gUnk_099ECE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E78C, &gUnkEu_0884783C, gUnk_099A895C, gUnk_09A3CE3C, gUnk_099EFE7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E72C, &gUnkEu_08847E04, gUnk_099A8780, gUnk_09A3CCBC, gUnk_099E4E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E804, &gUnkEu_08848808, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08155B04[6] = {
    { &gUnkEu_088954F4, &gUnkEu_08849768, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08895560, &gUnkEu_0884A1C8, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088955D0, &gUnkEu_0884AA20, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889563C, &gUnkEu_0884B1AC, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088956A4, &gUnkEu_0884BB40, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08895710, &gUnkEu_0884C7C0, gUnk_099A897C, gUnk_09A3CE5C, gUnk_099F0E7C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08155C54[17] = {
    { &gUnkEu_0888E860, &gUnkEu_0884CB9C, gCardWep01Frame0, gCardWep01Palette, gCardWep01Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E8B4, &gUnkEu_0884CF0C, gCardWep04Frame0, gCardWep04Palette, gCardWep04Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E904, &gUnkEu_0884D304, gCardWep05Frame0, gCardWep05Palette, gCardWep05Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E964, &gUnkEu_0884D708, gCardWep06Frame0, gCardWep06Palette, gCardWep06Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888E9B8, &gUnkEu_0884DAB0, gCardWep07Frame0, gCardWep07Palette, gCardWep07Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EA14, &gUnkEu_0884DE4C, gCardWep08Frame0, gCardWep08Palette, gCardWep08Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EA64, &gUnkEu_0884E1C4, gCardWep09Frame0, gCardWep09Palette, gCardWep09Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EAC0, &gUnkEu_0884E5D0, gCardWep10Frame0, gCardWep10Palette, gCardWep10Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EB00, &gUnkEu_0884E9D4, gCardWep03Frame0, gCardWep03Palette, gCardWep03Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EB4C, &gUnkEu_0884ED28, gCardWep11Frame0, gCardWep11Palette, gCardWep11Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EBA4, &gUnkEu_0884F0D8, gCardWep12Frame0, gCardWep12Palette, gCardWep12Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EBF0, &gUnkEu_0884F478, gCardWep13Frame0, gCardWep13Palette, gCardWep13Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EC44, &gUnkEu_0884F7D4, gCardWep14Frame0, gCardWep14Palette, gCardWep14Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EC9C, &gUnkEu_0884FBD8, gCardWep15Frame0, gCardWep15Palette, gCardWep15Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888ED48, &gUnkEu_0884FFF8, gCardWep18Frame0, gCardWep18Palette, gCardWep18Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EDAC, &gUnkEu_08850400, gCardWep19Frame0, gCardWep19Palette, gCardWep19Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888ECE8, &gUnkEu_08850724, gCardWep16Frame0, gCardWep16Palette, gCardWep16Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815600C[14] = {
    { &gUnkEu_0888EDE0, &gUnkEu_088508FC, gCardMgc01Frame0, gCardMgc01Palette, gCardMgc01Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EE18, &gUnkEu_08850AE0, gCardMgc02Frame0, gCardMgc02Palette, gCardMgc02Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EE50, &gUnkEu_08850CD0, gCardMgc03Frame0, gCardMgc03Palette, gCardMgc03Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EE80, &gUnkEu_08850E80, gCardMgc04Frame0, gCardMgc04Palette, gCardMgc04Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EEC0, &gUnkEu_08851108, gCardMgc05Frame0, gCardMgc05Palette, gCardMgc05Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EEF0, &gUnkEu_08851358, gCardMgc06Frame0, gCardMgc06Palette, gCardMgc06Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EF20, &gUnkEu_088515B4, gCardMgc07Frame0, gCardMgc07Palette, gCardMgc07Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EF54, &gUnkEu_0885188C, gCardSmn03Frame0, gCardSmn03Palette, gCardSmn03Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EFF4, &gUnkEu_08851F64, gCardSmn06Frame0, gCardSmn06Palette, gCardSmn06Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EFC0, &gUnkEu_08851CDC, gCardSmn05Frame0, gBanbPalette, gCardSmn05Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F070, &gUnkEu_08852398, gCardSmn08Frame0, gMushuPalette, gCardSmn08Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888EF8C, &gUnkEu_08851ADC, gCardSmn04Frame0, gCardSmn04Palette, gCardSmn04Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F03C, &gUnkEu_08852150, gCardSmn07Frame0, gTinkPalette, gCardSmn07Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F0A4, &gUnkEu_08852574, gCardSmn09Frame0, gCardSmn09Palette, gCardSmn09Tiles, gUnk_09059E94, gCard00Palette, gUnk_09059EAE, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815631C[7] = {
    { &gUnkEu_0888F0DC, &gUnkEu_088527E4, gCardItm01Frame0, gCardItm01Palette, gCardItm01Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F128, &gUnkEu_08852A50, gCardItm02Frame0, gCardItm02Palette, gCardItm02Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F178, &gUnkEu_08852D50, gCardItm03Frame0, gCardItm03Palette, gCardItm03Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F1AC, &gUnkEu_08852FB8, gCardItm04Frame0, gCardItm04Palette, gCardItm04Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F1F4, &gUnkEu_088532A8, gCardItm05Frame0, gCardItm05Palette, gCardItm05Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F22C, &gUnkEu_088534A4, gCardItm06Frame0, gCardItm06Palette, gCardItm06Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F278, &gUnkEu_08853754, gCardItm07Frame0, gCardItm07Palette, gCardItm07Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081564A4[7] = {
    { &gUnkEu_0888F2C0, &gUnkEu_08853980, gCardSmn02Frame0, gDonaldPalette, gCardSmn02Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F2F4, &gUnkEu_08853B98, gCardSmn01Frame0, gGoofyPalette, gCardSmn01Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F394, &gUnkEu_08853DAC, gCardSmn10Frame0, gAladdinPalette, gCardSmn10Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F3F8, &gUnkEu_088541F8, gCardSmn12Frame0, gJackPalette, gCardSmn12Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F3C8, &gUnkEu_08853FE4, gCardSmn11Frame0, gArielPalette, gCardSmn11Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F440, &gUnkEu_088543D8, gCardSmn13Frame0, gPeterPalette, gCardSmn13Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F484, &gUnkEu_088545F8, gCardSmn14Frame0, gBeastPalette, gCardSmn14Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_0815662C[49] = {
    { &gUnkEu_0888F880, &gUnkEu_0885479C, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F8C4, &gUnkEu_08855548, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F9AC, &gUnkEu_08857454, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FB28, &gUnkEu_08854940, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FB84, &gUnkEu_08854AF0, gUnk_0904B1A8, gEmy02Palette, gUnk_0904B1BC, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FBDC, &gUnkEu_08854CA4, gUnk_0904B3BC, gEmy03Palette, gUnk_0904B3D0, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FC34, &gUnkEu_08854E38, gUnk_0904B5D0, gEmy04Palette, gUnk_0904B5E4, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F910, &gUnkEu_08855834, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F960, &gUnkEu_08855A14, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FCD0, &gUnkEu_08855BD0, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FA8C, &gUnkEu_08855DE4, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FA00, &gUnkEu_08857650, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FD24, &gUnkEu_08855F6C, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FE74, &gUnkEu_08856204, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FA4C, &gUnkEu_08854FF8, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FF00, &gUnkEu_088563AC, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FEBC, &gUnkEu_08857848, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FD80, &gUnkEu_0885657C, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FE18, &gUnkEu_08856760, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FACC, &gUnkEu_08856900, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FDD4, &gUnkEu_08856AFC, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FF50, &gUnkEu_08856CB4, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FFCC, &gUnkEu_08857AD4, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FF88, &gUnkEu_08856EB4, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FC74, &gUnkEu_088570D8, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088901A8, &gUnkEu_08857244, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890020, &gUnkEu_08855208, gCardEmy07Frame0, gEmy07Palette, gCardEmy07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890070, &gUnkEu_088553A8, gCardEmy08Frame0, gEmy07bPalette, gCardEmy08Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088900CC, &gUnkEu_088580B0, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890118, &gUnkEu_08857C74, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889015C, &gUnkEu_08857EA4, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890200, &gUnkEu_08858284, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088903AC, &gUnkEu_08859410, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890290, &gUnkEu_08858A8C, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890484, &gUnkEu_08859BE0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088959B8, &gUnkEu_08858454, gCardNpcAw04Frame0, gTrumpHPalette, gCardNpcAw04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890230, &gUnkEu_088587B0, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088902C8, &gUnkEu_08858C90, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890354, &gUnkEu_0885917C, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890300, &gUnkEu_08858F38, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088903E0, &gUnkEu_08859768, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889043C, &gUnkEu_08859974, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F52C, &gUnkEu_0885A13C, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F770, &gUnkEu_0885A450, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F740, &gUnkEu_08859E54, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F7A4, &gUnkEu_0885A7A4, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F7E8, &gUnkEu_0885B4CC, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890F7C, &gUnkEu_0885ACC0, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890FB0, &gUnkEu_0885AF84, gCardBos18Frame0, gCardBos18Palette, gCardBos18Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081570E4[26] = {
    { &gUnkEu_088929B0, &gUnkEu_0885BB4C, gCardRoom02Frame0, gCardRoom02Palette, gCardRoom02Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889294C, &gUnkEu_0885BA50, gCardRoom01Frame0, gCardRoom01Palette, gCardRoom01Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892BB0, &gUnkEu_0885C230, gCardRoom07Frame0, gCardRoom07Palette, gCardRoom07Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892C18, &gUnkEu_0885C450, gCardRoom08Frame0, gCardRoom08Palette, gCardRoom08Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892AE0, &gUnkEu_0885BFC4, gCardRoom05Frame0, gCardRoom05Palette, gCardRoom05Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892A78, &gUnkEu_0885BE74, gCardRoom04Frame0, gCardRoom04Palette, gCardRoom04Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088930B0, &gUnkEu_0885D4B0, gCardRoom20Frame0, gCardRoom20Palette, gCardRoom20Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08893108, &gUnkEu_0885D688, gCardRoom21Frame0, gCardRoom21Palette, gCardRoom21Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889315C, &gUnkEu_0885D85C, gCardRoom22Frame0, gCardRoom22Palette, gCardRoom22Tiles, gUnk_093F5EFC, gUnk_09618D78, gUnk_093F5F16, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892DEC, &gUnkEu_0885CAC0, gCardRoom13Frame0, gCardRoom13Palette, gCardRoom13Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892D88, &gUnkEu_0885C990, gCardRoom12Frame0, gCardRoom12Palette, gCardRoom12Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892E54, &gUnkEu_0885CBE4, gCardRoom14Frame0, gCardRoom14Palette, gCardRoom14Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892EC0, &gUnkEu_0885CDF0, gCardRoom15Frame0, gCardRoom15Palette, gCardRoom15Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08893058, &gUnkEu_0885D364, gCardRoom19Frame0, gCardRoom19Palette, gCardRoom19Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892F94, &gUnkEu_0885D06C, gCardRoom17Frame0, gCardRoom17Palette, gCardRoom17Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892FF4, &gUnkEu_0885D254, gCardRoom18Frame0, gCardRoom18Palette, gCardRoom18Tiles, gUnk_093F5C60, gUnk_09618D78, gUnk_093F5C7A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892C74, &gUnkEu_0885C514, gCardRoom09Frame0, gCardRoom09Palette, gCardRoom09Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892A14, &gUnkEu_0885BC78, gCardRoom03Frame0, gCardRoom03Palette, gCardRoom03Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892CD0, &gUnkEu_0885C6FC, gCardRoom10Frame0, gCardRoom10Palette, gCardRoom10Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892B48, &gUnkEu_0885C108, gCardRoom06Frame0, gCardRoom06Palette, gCardRoom06Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892F24, &gUnkEu_0885CECC, gCardRoom16Frame0, gCardRoom16Palette, gCardRoom16Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08892D20, &gUnkEu_0885C86C, gCardRoom11Frame0, gCardRoom11Palette, gCardRoom11Tiles, gUnk_093F6198, gUnk_09618D78, gUnk_093F61B2, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088931D0, &gUnkEu_0885D950, gCardEve00Frame0, gCardEve00Palette, gCardEve00Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08893238, &gUnkEu_0885DA48, gCardEve01Frame0, gCardEve01Palette, gCardEve01Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088932A4, &gUnkEu_0885DB40, gCardEve02Frame0, gCardEve02Palette, gCardEve02Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08893310, &gUnkEu_0885DC30, gCardRoom23Frame0, gCardRoom23Palette, gCardRoom23Tiles, gUnk_093F6434, gUnk_09618D78, gUnk_093F644E, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08157694[1] = {
    { &gUnkEu_08895850, &gUnkEu_0885E1D8, gUnk_08C6AA58, gUnk_08F6E164, gUnk_08C6AA7E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_081576CC[22] = {
    { &gUnkEu_0889103C, &gUnkEu_0885B6AC, gCardWep20Frame0, gCardWep20Palette, gCardWep20Tiles, gUnk_0905A668, gCard00Palette, gUnk_0905A682, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890FEC, &gUnkEu_0885B870, gCardSmn15Frame0, gMickeyPalette, gCardSmn15Tiles, gUnk_0905A3CC, gCard00Palette, gUnk_0905A3E6, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F880, &gUnkEu_0885479C, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F9AC, &gUnkEu_08857454, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F910, &gUnkEu_08855834, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FA00, &gUnkEu_08857650, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FE74, &gUnkEu_08856204, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FA4C, &gUnkEu_08854FF8, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FD80, &gUnkEu_0885657C, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FACC, &gUnkEu_08856900, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888FFCC, &gUnkEu_08857AD4, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890200, &gUnkEu_08858284, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088903AC, &gUnkEu_08859410, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890290, &gUnkEu_08858A8C, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890484, &gUnkEu_08859BE0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890230, &gUnkEu_088587B0, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088902C8, &gUnkEu_08858C90, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890354, &gUnkEu_0885917C, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890300, &gUnkEu_08858F38, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_088903E0, &gUnkEu_08859768, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0889043C, &gUnkEu_08859974, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_08890F7C, &gUnkEu_0885ACC0, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, gUnk_0905A130, gCard00Palette, gUnk_0905A14A, 0, 0, 0, 0, 0, 0, 0 },
};

const JiminyDetail gUnk_08157B9C[25] = {
    { &gUnkEu_0888F4FC, &gUnkEu_0885E7B8, gSor1fl00Frame0, gSoraPalette, gSor1fl00Tiles, gCardNpcEx00Frame0, gCardNpcEx00Palette, gCardNpcEx00Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { &gUnkEu_0888F2C0, &gUnkEu_0885ED64, gDonaFl00Frame0, gDonaldPalette, gDonaFl00Tiles, gCardSmn02Frame0, gDonaldPalette, gCardSmn02Tiles, 0, 0, 0, 0, 0, 0, -9 },
    { &gUnkEu_0888F2F4, &gUnkEu_0885F1AC, gGoofyFl00Frame0, gGoofyPalette, gGoofyFl00Tiles, gCardSmn01Frame0, gGoofyPalette, gCardSmn01Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F358, &gUnkEu_0885F518, gJimFl00Frame0, gJiminyPalette, gJimFl00Tiles, gCardNpcEx01Frame0, gCardNpcEx01Palette, gCardNpcEx01Tiles, 0, 0, 0, 0, 0, -3, -11 },
    { &gUnkEu_0888F52C, &gUnkEu_0885FB34, gRikuFl00Frame0, gRikuPalette, gRikuFl00Tiles, gCardNpcEx03Frame0, gCardNpcEx03Palette, gCardNpcEx03Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { &gUnkEu_0888F560, &gUnkEu_08860154, gKairF00Frame0, gKairiPalette, gKairF00Tiles, gCardNpcEx05Frame0, gCardNpcEx05Palette, gCardNpcEx05Tiles, 0, 0, 0, 0, 0, -1, -3 },
    { &gUnkEu_0888EF54, &gUnkEu_0886040C, gShinba10Frame0, gShinbaPalette, gShinba10Tiles, gCardSmn03Frame0, gCardSmn03Palette, gCardSmn03Tiles, 0, 0, 0, 0, 0, -2, -7 },
    { &gUnkEu_0888EFF4, &gUnkEu_08860848, gUnk_088ABEF4, gDamboPalette, gUnk_088ABF88, gCardSmn06Frame0, gCardSmn06Palette, gCardSmn06Tiles, 0, 0, 0, 0, 0, 8, -7 },
    { &gUnkEu_0888EFC0, &gUnkEu_08860A78, gBanb00Frame7, gBanbPalette, gBanb00Tiles, gCardSmn05Frame0, gBanbPalette, gCardSmn05Tiles, 0, 0, 0, 0, 0, -2, -7 },
    { &gUnkEu_0888F070, &gUnkEu_08860DB4, gMushuF00Frame1, gMushuPalette, gMushuF00Tiles, gCardSmn08Frame0, gMushuPalette, gCardSmn08Tiles, 0, 0, 0, 0, 0, 0, -12 },
    { &gUnkEu_0888F4CC, &gUnkEu_088610E8, gMoguFl00Frame0, gMoguPalette, gMoguFl00Tiles, gCardNpcEx02Frame0, gCardNpcEx02Palette, gCardNpcEx02Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { &gUnkEu_0888F66C, &gUnkEu_08861624, gReonFl00Frame0, gReonPalette, gReonFl00Tiles, gCardNpcEx09Frame0, gCardNpcEx09Palette, gCardNpcEx09Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { &gUnkEu_0888F5D0, &gUnkEu_08861A78, gYuffieFl00Frame0, gYuffiePalette, gYuffieFl00Tiles, gCardNpcEx10Frame0, gCardNpcEx10Palette, gCardNpcEx10Tiles, 0, 0, 0, 0, 0, -1, 2 },
    { &gUnkEu_0888F608, &gUnkEu_08861F4C, gEarF00Frame0, gEarisPalette, gEarF00Tiles, gCardNpcEx06Frame0, gCardNpcEx06Palette, gCardNpcEx06Tiles, 0, 0, 0, 0, 0, -3, 4 },
    { &gUnkEu_0888F704, &gUnkEu_08862214, gShidoF00Frame0, gShidoPalette, gShidoF00Tiles, gCardNpcEx07Frame0, gCardNpcEx07Palette, gCardNpcEx07Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { &gUnkEu_0888F0A4, &gUnkEu_08862634, gCroudF00Frame0, gCroudPalette, gCroudF00Tiles, gCardSmn09Frame0, gCardSmn09Palette, gCardSmn09Tiles, 0, 0, 0, 0, 0, -3, 2 },
    { &gUnkEu_0888F6DC, &gUnkEu_08862984, gTidusFl00Frame0, gTidusPalette, gTidusFl00Tiles, gCardNpcDi01Frame0, gCardNpcDi01Palette, gCardNpcDi01Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { &gUnkEu_0888F63C, &gUnkEu_08862C30, gWakkaF00Frame0, gWakkaPalette, gWakkaF00Tiles, gCardNpcDi02Frame0, gCardNpcDi02Palette, gCardNpcDi02Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F6A8, &gUnkEu_08862EEC, gSelphieFl00Frame0, gSelphiePalette, gSelphieFl00Tiles, gCardNpcDi03Frame0, gCardNpcDi03Palette, gCardNpcDi03Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { &gUnkEu_0888F598, &gUnkEu_0886347C, gNamiF00Frame0, gNaminePalette, gNamiF00Tiles, gCardNpcCom01Frame0, gCardNpcCom01Palette, gCardNpcCom01Tiles, 0, 0, 0, 0, 0, -1, -4 },
    { &gUnkEu_0889575C, &gUnkEu_088638D4, gNiseFl00Frame0, gNiserikuPalette, gNiseFl00Tiles, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { &gUnkEu_0888F770, &gUnkEu_08863D04, gAcceleFl00Frame0, gAccelePalette, gAcceleFl00Tiles, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_0888F740, &gUnkEu_08864160, gLaxineFl00Frame0, gLaxinePalette, gLaxineFl00Tiles, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { &gUnkEu_0888F7A4, &gUnkEu_088645FC, gVixenFl00Frame0, gVixenPalette, gVixenFl00Tiles, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_0888F7E8, &gUnkEu_08864A34, gMaruxha2Fl00Frame0, gMaruxhaPalette, gMaruxha2Fl00Tiles, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, 0, 0, 0, 0, 0, -3, 6 },
};

const JiminyDetail gUnk_08158114[40] = {
    { &gUnkEu_088908E4, &gUnkEu_088683FC, gAliceFl00Frame0, gAlicePalette, gAliceFl00Tiles, gCardNpcAw01Frame0, gCardNpcAw01Palette, gCardNpcAw01Tiles, 0, 0, 0, 0, 0, -1, -1 },
    { &gUnkEu_08890950, &gUnkEu_0886871C, gQenF00Frame0, gQeenPalette, gQenF00Tiles, gCardNpcAw02Frame0, gCardNpcAw02Palette, gCardNpcAw02Tiles, 0, 0, 0, 0, 0, -3, 4 },
    { &gUnkEu_088909B4, &gUnkEu_08868954, gUsagif00Frame0, gUsagi00Palette, gUsagif00Tiles, gCardNpcAw05Frame0, gCardNpcAw05Palette, gCardNpcAw05Tiles, 0, 0, 0, 0, 0, 0, -10 },
    { &gUnkEu_08890A80, &gUnkEu_08868B78, gTrumpH00Frame0, gTrumpHPalette, gTrumpH00Tiles, gCardNpcAw04Frame0, gTrumpHPalette, gCardNpcAw04Tiles, 0, 0, 0, 0, 0, 0, 2 },
    { &gUnkEu_08890A18, &gUnkEu_08868D9C, gTrumpS00Frame0, gTrumpSPalette, gTrumpS00Tiles, gCardNpcAw03Frame0, gTrumpSPalette, gCardNpcAw03Tiles, 0, 0, 0, 0, 0, 0, 2 },
    { &gUnkEu_08890AE0, &gUnkEu_08869070, gCheshireFrame0, gCheshirePalette, gCheshireTiles, gCardNpcAw06Frame0, gCardNpcAw06Palette, gCardNpcAw06Tiles, 0, 0, 0, 0, 0, -4, -12 },
    { &gUnkEu_08890864, &gUnkEu_08867A20, gHeraclesFl00Frame0, gHeraclesPalette, gHeraclesFl00Tiles, gCardNpcHe02Frame0, gCardNpcHe02Palette, gCardNpcHe02Tiles, 0, 0, 0, 0, 0, 0, 13 },
    { &gUnkEu_088908B0, &gUnkEu_08867C68, gPhilFl00Frame0, gPhilPalette, gPhilFl00Tiles, gCardNpcHe01Frame0, gCardNpcHe01Palette, gCardNpcHe01Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { &gUnkEu_08890230, &gUnkEu_08867FA0, gHadesFl00Frame0, gHadesPalette, gHadesFl00Tiles, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, 0, 0, 0, 0, 0, 0, 18 },
    { &gUnkEu_0888F394, &gUnkEu_08865050, gAladdin00Frame0, gAladdinPalette, gAladdin00Tiles, gCardSmn10Frame0, gAladdinPalette, gCardSmn10Tiles, 0, 0, 0, 0, 0, -2, 6 },
    { &gUnkEu_0888EF8C, &gUnkEu_08865450, gGenie01Frame2, gGeniePalette, gGenie01Tiles, gCardSmn04Frame0, gCardSmn04Palette, gCardSmn04Tiles, 0, 0, 0, 0, 0, 2, 1 },
    { &gUnkEu_08890678, &gUnkEu_088656A0, gJasmineF00Frame0, gJasminePalette, gJasmineF00Tiles, gCardNpcAl01Frame0, gCardNpcAl01Palette, gCardNpcAl01Tiles, 0, 0, 0, 0, 0, -4, 5 },
    { &gUnkEu_088906A8, &gUnkEu_088658CC, gUnk_09393218, gUnk_09618358, gUnk_0939322C, gCardNpcAl03Frame0, gCardNpcAl03Palette, gCardNpcAl03Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { &gUnkEu_088902C8, &gUnkEu_08865BD8, gJafferFl00Frame0, gJafferPalette, gJafferFl00Tiles, gCardNpcAl02Frame0, gCardNpcAl02Palette, gCardNpcAl02Tiles, 0, 0, 0, 0, 0, -3, 19 },
    { &gUnkEu_08890700, &gUnkEu_08865EE4, 0, 0, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_08F67384, gUnk_08F6E104, gUnk_08EEC044, 32, 3744, 0, 0 },
    { &gUnkEu_0888F3F8, &gUnkEu_088661B0, gJackFl00Frame0, gJackPalette, gJackFl00Tiles, gCardSmn12Frame0, gJackPalette, gCardSmn12Tiles, 0, 0, 0, 0, 0, 2, 11 },
    { &gUnkEu_08890734, &gUnkEu_08866440, gSariFl00Frame0, gSariPalette, gSariFl00Tiles, gCardNpcNm01Frame0, gCardNpcNm01Palette, gCardNpcNm01Tiles, 0, 0, 0, 0, 0, -2, 7 },
    { &gUnkEu_0889079C, &gUnkEu_088668B0, gFinklF00Frame0, gFinklPalette, gFinklF00Tiles, gCardNpcNm02Frame0, gCardNpcNm02Palette, gCardNpcNm02Tiles, 0, 0, 0, 0, 0, -1, -7 },
    { &gUnkEu_08890354, &gUnkEu_08866C54, gBugiFl00Frame0, gBugiPalette, gBugiFl00Tiles, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { &gUnkEu_088907E0, &gUnkEu_08867190, gPinoF00Frame0, gPinokioPalette, gPinoF00Tiles, gCardNpcPi01Frame0, gCardNpcPi01Palette, gCardNpcPi01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { &gUnkEu_08890824, &gUnkEu_08867690, gGeppettoF00Frame0, gGeppettoPalette, gGeppettoF00Tiles, gCardNpcPi02Frame0, gCardNpcPi02Palette, gCardNpcPi02Tiles, 0, 0, 0, 0, 0, 0, 0 },
    { &gUnkEu_0888F3C8, &gUnkEu_0886961C, gArielF00Frame0, gArielPalette, gArielF00Tiles, gCardSmn11Frame0, gArielPalette, gCardSmn11Tiles, 0, 0, 0, 0, 0, -4, 3 },
    { &gUnkEu_08890B28, &gUnkEu_08869944, gSebastianFl00Frame0, gSebastianPalette, gSebastianFl00Tiles, gCardNpcLm01Frame0, gCardNpcLm01Palette, gCardNpcLm01Tiles, 0, 0, 0, 0, 0, -1, -13 },
    { &gUnkEu_08890B68, &gUnkEu_08869CB0, gFlounderFl00Frame0, gFlounderPalette, gFlounderFl00Tiles, gCardNpcLm02Frame0, gCardNpcLm02Palette, gCardNpcLm02Tiles, 0, 0, 0, 0, 0, -1, -17 },
    { &gUnkEu_08890300, &gUnkEu_0886A024, gArthraFl00Frame0, gArthraPalette, gArthraFl00Tiles, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_0888F440, &gUnkEu_0886A49C, gPeterFl00Frame0, gPeterPalette, gPeterFl00Tiles, gCardSmn13Frame0, gPeterPalette, gCardSmn13Tiles, 0, 0, 0, 0, 0, -3, 5 },
    { &gUnkEu_0888F03C, &gUnkEu_0886A654, gTinkF00Frame2, gTinkPalette, gTinkF00Tiles, gCardSmn07Frame0, gTinkPalette, gCardSmn07Tiles, 0, 0, 0, 0, 0, -5, -10 },
    { &gUnkEu_08890B9C, &gUnkEu_0886A94C, gWendyFl00Frame0, gWendyPalette, gWendyFl00Tiles, gCardNpcPp01Frame0, gCardNpcPp01Palette, gCardNpcPp01Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { &gUnkEu_08890BD0, &gUnkEu_0886AD64, gHookF00Frame0, gHookPalette, gHookF00Tiles, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, 0, 0, 0, 0, 0, -1, 17 },
    { &gUnkEu_0888F484, &gUnkEu_0886B178, gBeastFl00Frame0, gBeastPalette, gBeastFl00Tiles, gCardSmn14Frame0, gBeastPalette, gCardSmn14Tiles, 0, 0, 0, 0, 0, -1, 10 },
    { &gUnkEu_08890C04, &gUnkEu_0886B574, gBellFl00Frame0, gBellPalette, gBellFl00Tiles, gCardNpcPc01Frame0, gCardNpcPc01Palette, gCardNpcPc01Tiles, 0, 0, 0, 0, 0, -4, 5 },
    { &gUnkEu_08890C48, &gUnkEu_0886B974, gMarefF00Frame0, gMarefPalette, gMarefF00Tiles, gCardNpcPc02Frame0, gCardNpcPc02Palette, gCardNpcPc02Tiles, 0, 0, 0, 0, 0, -12, 16 },
    { &gUnkEu_0889043C, &gUnkEu_0886BC2C, 0, 0, 0, gCardBos07Frame0, gCardBos07Palette, gCardBos07Tiles, gUnk_08F67B84, gUnk_08F6E124, gUnk_08EECEE4, 64, 5280, 0, 0 },
    { &gUnkEu_08890CA8, &gUnkEu_0886BF6C, gPoohFl06Frame0, gPoohPalette, gPoohFl06Tiles, gCardNpcPo01Frame0, gCardNpcPo01Palette, gCardNpcPo01Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { &gUnkEu_08890CE0, &gUnkEu_0886C1B8, gUnk_09742FC4, gUnk_09849C18, gUnk_09742FD8, gCardNpcPo03Frame0, gCardNpcPo03Palette, gCardNpcPo03Tiles, 0, 0, 0, 0, 0, -2, -10 },
    { &gUnkEu_08890D14, &gUnkEu_0886C3D4, gOwlFl00Frame0, gOwlPalette, gOwlFl00Tiles, gCardNpcPo06Frame0, gCardNpcPo06Palette, gCardNpcPo06Tiles, 0, 0, 0, 0, 0, -3, -7 },
    { &gUnkEu_08890D48, &gUnkEu_0886C5E0, gRooFl00Frame0, gRooPalette, gRooFl00Tiles, gCardNpcPo07Frame0, gCardNpcPo07Palette, gCardNpcPo07Tiles, 0, 0, 0, 0, 0, -1, -13 },
    { &gUnkEu_08890D80, &gUnkEu_0886C8D0, gEeyoreFl00Frame0, gEeyorePalette, gEeyoreFl00Tiles, gCardNpcPo04Frame0, gCardNpcPo04Palette, gCardNpcPo04Tiles, 0, 0, 0, 0, 0, 5, -13 },
    { &gUnkEu_08890DB8, &gUnkEu_0886CC00, gTiggerFl00Frame0, gTiggerPalette, gTiggerFl00Tiles, gCardNpcPo02Frame0, gCardNpcPo02Palette, gCardNpcPo02Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { &gUnkEu_08890DF4, &gUnkEu_0886CF18, gRabbitFl00Frame0, gRabbitPalette, gRabbitFl00Tiles, gCardNpcPo05Frame0, gCardNpcPo05Palette, gCardNpcPo05Tiles, 0, 0, 0, 0, 0, -1, -3 },
};

const JiminyDetail gUnk_081589D4[35] = {
    { &gUnkEu_0888F880, &gUnkEu_0886DF4C, gEmy00L00Frame0, gEmy00Palette, gEmy00L00Tiles, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, 0, 0, 0, 0, 0, 2, -12 },
    { &gUnkEu_0888F8C4, &gUnkEu_0886E1FC, gEmy14Ll01Frame1, gEmy14Palette, gEmy14Ll01Tiles, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, 0, 0, 0, 0, 0, -8, 2 },
    { &gUnkEu_0888F9AC, &gUnkEu_0886E5EC, gEmy3800Frame0, gEmy38Palette, gEmy3800Tiles, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, 0, 0, 0, 0, 0, -6, 6 },
    { &gUnkEu_0888FB28, &gUnkEu_0886E9AC, gEmy01L00Frame16, gEmy01Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { &gUnkEu_0888FB84, &gUnkEu_0886ECC0, gEmy01L00Frame3, gEmy02Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy02Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -1, -11 },
    { &gUnkEu_0888FBDC, &gUnkEu_0886EFE8, gEmy01L00Frame0, gEmy03Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy03Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -11 },
    { &gUnkEu_0888FC34, &gUnkEu_0886F410, gEmy01L00Frame15, gEmy04Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy04Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { &gUnkEu_0888F910, &gUnkEu_0886F6B4, gEmy1500Frame7, gEmy15Palette, gEmy1500Tiles, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, 0, 0, 0, 0, 0, 0, -6 },
    { &gUnkEu_0888F960, &gUnkEu_0886F94C, gEmy1600Frame0, gEmy16Palette, gEmy1600Tiles, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, 0, 0, 0, 0, 0, -1, -9 },
    { &gUnkEu_0888FCD0, &gUnkEu_0886FCC4, gEmy1800Frame0, gEmy18Palette, gEmy1800Tiles, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, 0, 0, 0, 0, 0, -1, 3 },
    { &gUnkEu_0888FA8C, &gUnkEu_0886FFC8, gEmy1900Frame5, gEmy19Palette, gEmy1900Tiles, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, 0, 0, 0, 0, 0, -1, -6 },
    { &gUnkEu_0888FA00, &gUnkEu_08870298, gEmy3900Frame0, gEmy39Palette, gEmy3900Tiles, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { &gUnkEu_0888FD24, &gUnkEu_088705F0, gEmy2100Frame0, gEmy21Palette, gEmy2100Tiles, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, 0, 0, 0, 0, 0, 1, -10 },
    { &gUnkEu_0888FE74, &gUnkEu_088708C4, gEmy2200Frame9, gEmy22Palette, gEmy2200Tiles, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, 0, 0, 0, 0, 0, 2, 6 },
    { &gUnkEu_0888FA4C, &gUnkEu_08870BC4, gEmy0600Frame2, gEmy06Palette, gEmy0600Tiles, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { &gUnkEu_0888FF00, &gUnkEu_08870E2C, gEmy2300Frame0, gEmy23Palette, gEmy2300Tiles, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, 0, 0, 0, 0, 0, 1, 2 },
    { &gUnkEu_0888FEBC, &gUnkEu_088710CC, gEmy4100Frame0, gEmy41Palette, gEmy4100Tiles, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, 0, 0, 0, 0, 0, -2, 11 },
    { &gUnkEu_0888FD80, &gUnkEu_088713AC, gEmy2500Frame3, gEmy25Palette, gEmy2500Tiles, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, 0, 0, 0, 0, 0, 4, 0 },
    { &gUnkEu_0888FE18, &gUnkEu_08871634, gEmy2600Frame0, gEmy26Palette, gEmy2600Tiles, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { &gUnkEu_0888FACC, &gUnkEu_08871A6C, gEmy2700Frame0, gEmy27Palette, gEmy2700Tiles, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, 0, 0, 0, 0, 0, 10, -10 },
    { &gUnkEu_0888FDD4, &gUnkEu_08871E00, gEmy2800Frame0, gEmy28Palette, gEmy2800Tiles, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, 0, 0, 0, 0, 0, 5, 5 },
    { &gUnkEu_0888FF50, &gUnkEu_0887215C, gEmy2900Frame0, gEmy29Palette, gEmy2900Tiles, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { &gUnkEu_0888FFCC, &gUnkEu_08872678, gEmy4400Frame0, gEmy44Palette, gEmy4400Tiles, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, 0, 0, 0, 0, 0, 3, 1 },
    { &gUnkEu_0888FF88, &gUnkEu_08872A00, gEmy3000Frame0, gEmy30Palette, gEmy3000Tiles, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, 0, 0, 0, 0, 0, 2, -5 },
    { &gUnkEu_0888FC74, &gUnkEu_08872C8C, gEmy3100Frame6, gEmy31Palette, gEmy3100Tiles, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, 0, 0, 0, 0, 0, 5, -3 },
    { &gUnkEu_088901A8, &gUnkEu_08872DE4, gEmy3700Frame1, gEmy37Palette, gEmy3700Tiles, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { &gUnkEu_08890020, &gUnkEu_088730C4, gEmy07Fl00Frame0, gEmy07Palette, gEmy07Fl00Tiles, gCardEmy07Frame0, gEmy07Palette, gCardEmy07Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { &gUnkEu_08890070, &gUnkEu_08873500, gEmy07Fl10tFrame7, gEmy07bPalette, gEmy07Fl10tTiles, gCardEmy08Frame0, gEmy07bPalette, gCardEmy08Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { &gUnkEu_088900CC, &gUnkEu_08873838, gEmy8300Frame0, gEmy83Palette, gEmy8300Tiles, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, 0, 0, 0, 0, 0, 0, -4 },
    { &gUnkEu_08890118, &gUnkEu_08873B94, gEmy8100Frame0, gEmy81Palette, gEmy8100Tiles, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { &gUnkEu_0889015C, &gUnkEu_08873DB0, gEmy8201Frame2, gEmy82Palette, gEmy8201Tiles, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, 0, 0, 0, 0, 0, 4, -10 },
    { &gUnkEu_08890200, &gUnkEu_0886D198, 0, 0, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_08F65B84, gUnk_08F6E044, gUnk_08EE8E84, 32, 3488, 3, -3 },
    { &gUnkEu_088903AC, &gUnkEu_0886D560, 0, 0, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_08F66B84, gUnk_08F6E0A4, gUnk_08EEAD44, 96, 4864, 0, 0 },
    { &gUnkEu_08890290, &gUnkEu_0886D8F0, 0, 0, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_08F66384, gUnk_08F6E064, gUnk_08EE9C24, 64, 4384, 0, 3 },
    { &gUnkEu_08890484, &gUnkEu_0886DBF8, 0, 0, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_08F65384, gUnk_08F6E024, gUnk_08EE7A24, 32, 5216, 0, 0 },
};

const JiminyDetail gUnk_0815917C[14] = {
    { &gUnkEu_0888F52C, &gUnkEu_08874658, gRikuFl00Frame0, gRikuPalette, gRikuFl00Tiles, gCardNpcEx03Frame0, gCardNpcEx03Palette, gCardNpcEx03Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { &gUnkEu_08890FEC, &gUnkEu_08874BC8, gMickeyFl00Frame0, gMickeyPalette, gMickeyFl00Tiles, gCardSmn15Frame0, gMickeyPalette, gCardSmn15Tiles, 0, 0, 0, 0, 0, -2, -6 },
    { &gUnkEu_0888F4FC, &gUnkEu_088750B8, gSor1fl00Frame0, gSoraPalette, gSor1fl00Tiles, gCardNpcEx00Frame0, gCardNpcEx00Palette, gCardNpcEx00Tiles, 0, 0, 0, 0, 0, -3, -3 },
    { &gUnkEu_0888F560, &gUnkEu_088756D4, gKairF00Frame0, gKairiPalette, gKairF00Tiles, gCardNpcEx05Frame0, gCardNpcEx05Palette, gCardNpcEx05Tiles, 0, 0, 0, 0, 0, -1, -3 },
    { &gUnkEu_0888F598, &gUnkEu_08875D30, gNamiF00Frame0, gNaminePalette, gNamiF00Tiles, gCardNpcCom01Frame0, gCardNpcCom01Palette, gCardNpcCom01Tiles, 0, 0, 0, 0, 0, -1, -4 },
    { &gUnkEu_0889575C, &gUnkEu_08876100, gNiseFl00Frame0, gNiserikuPalette, gNiseFl00Tiles, gCardBos12Frame0, gCardBos12Palette, gCardBos12Tiles, 0, 0, 0, 0, 0, -3, 0 },
    { &gUnkEu_08890FB0, &gUnkEu_088765D4, gAnsemFl00Frame0, gAnsemPalette, gAnsemFl00Tiles, gCardBos18Frame0, gCardBos18Palette, gCardBos18Tiles, 0, 0, 0, 0, 0, -3, 9 },
    { &gUnkEu_0888F7A4, &gUnkEu_08876BC4, gVixenFl00Frame0, gVixenPalette, gVixenFl00Tiles, gCardBos15Frame0, gCardBos15Palette, gCardBos15Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_08890F7C, &gUnkEu_088771B0, gRexeusFl00Frame0, gRexeusPalette, gRexeusFl00Tiles, gCardBos17Frame0, gCardBos17Palette, gCardBos17Tiles, 0, 0, 0, 0, 0, -5, 14 },
    { &gUnkEu_0889548C, &gUnkEu_0887781C, gXexionFl00Frame0, gXexionPalette, gXexionFl00Tiles, gCardNpcCom02Frame0, gCardNpcCom02Palette, gCardNpcCom02Tiles, 0, 0, 0, 0, 0, -1, 6 },
    { &gUnkEu_0888F770, &gUnkEu_08877E8C, gAcceleFl00Frame0, gAccelePalette, gAcceleFl00Tiles, gCardBos13Frame0, gCardBos13Palette, gCardBos13Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_0888F7E8, &gUnkEu_088785F0, gMaruxha2Fl00Frame0, gMaruxhaPalette, gMaruxha2Fl00Tiles, gCardBos16Frame0, gCardBos16Palette, gCardBos16Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_0888F740, &gUnkEu_08878B64, gLaxineFl00Frame0, gLaxinePalette, gLaxineFl00Tiles, gCardBos14Frame0, gCardBos14Palette, gCardBos14Tiles, 0, 0, 0, 0, 0, -2, 5 },
    { &gUnkEu_08895784, &gUnkEu_08878F40, gDizFl00Frame0, gDizPalette, gDizFl00Tiles, gCardNpcCom03Frame0, gCardNpcCom03Palette, gCardNpcCom03Tiles, 0, 0, 0, 0, 0, -2, 8 },
};

const JiminyDetail gUnk_0815948C[6] = {
    { &gUnkEu_08890C48, &gUnkEu_088793FC, gMarefF00Frame0, gMarefPalette, gMarefF00Tiles, gCardNpcPc02Frame0, gCardNpcPc02Palette, gCardNpcPc02Tiles, 0, 0, 0, 0, 0, -12, 16 },
    { &gUnkEu_08890700, &gUnkEu_08879700, 0, 0, 0, gCardBos05Frame0, gCardBos05Palette, gCardBos05Tiles, gUnk_08F67384, gUnk_08F6E104, gUnk_08EEC044, 32, 3744, 0, 0 },
    { &gUnkEu_08890300, &gUnkEu_08879A6C, gArthraFl00Frame0, gArthraPalette, gArthraFl00Tiles, gCardBos06Frame0, gCardBos06Palette, gCardBos06Tiles, 0, 0, 0, 0, 0, -3, 6 },
    { &gUnkEu_08890230, &gUnkEu_08879D24, gHadesFl00Frame0, gHadesPalette, gHadesFl00Tiles, gCardBos11Frame0, gCardBos11Palette, gCardBos11Tiles, 0, 0, 0, 0, 0, 0, 18 },
    { &gUnkEu_08890354, &gUnkEu_08879FFC, gBugiFl00Frame0, gBugiPalette, gBugiFl00Tiles, gCardBos02Frame0, gBoss02objPalette, gCardBos02Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { &gUnkEu_08890BD0, &gUnkEu_0887A250, gHookF00Frame0, gHookPalette, gHookF00Tiles, gCardBos10Frame0, gCardBos10Palette, gCardBos10Tiles, 0, 0, 0, 0, 0, -1, 17 },
};

const JiminyDetail gUnk_081595DC[33] = {
    { &gUnkEu_0888F880, &gUnkEu_0886DF4C, gEmy00L00Frame0, gEmy00Palette, gEmy00L00Tiles, gCardEmy00Frame0, gEmy00Palette, gCardEmy00Tiles, 0, 0, 0, 0, 0, 2, -12 },
    { &gUnkEu_0888F8C4, &gUnkEu_0886E1FC, gEmy14Ll01Frame1, gEmy14Palette, gEmy14Ll01Tiles, gCardEmy14Frame0, gEmy14Palette, gCardEmy14Tiles, 0, 0, 0, 0, 0, -8, 2 },
    { &gUnkEu_0888F9AC, &gUnkEu_0886E5EC, gEmy3800Frame0, gEmy38Palette, gEmy3800Tiles, gCardEmy38Frame0, gEmy38Palette, gCardEmy38Tiles, 0, 0, 0, 0, 0, -6, 6 },
    { &gUnkEu_0888FB28, &gUnkEu_0886E9AC, gEmy01L00Frame16, gEmy01Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy01Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { &gUnkEu_0888FB84, &gUnkEu_0886ECC0, gEmy01L00Frame3, gEmy02Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy02Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -1, -11 },
    { &gUnkEu_0888FBDC, &gUnkEu_0886EFE8, gEmy01L00Frame0, gEmy03Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy03Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -11 },
    { &gUnkEu_0888FC34, &gUnkEu_0886F410, gEmy01L00Frame15, gEmy04Palette, gEmy01L00Tiles, gCardEmy01Frame0, gEmy04Palette, gCardEmy01Tiles, 0, 0, 0, 0, 0, -2, -8 },
    { &gUnkEu_0888F910, &gUnkEu_0886F6B4, gEmy1500Frame7, gEmy15Palette, gEmy1500Tiles, gCardEmy15Frame0, gEmy15Palette, gCardEmy15Tiles, 0, 0, 0, 0, 0, 0, -6 },
    { &gUnkEu_0888F960, &gUnkEu_0886F94C, gEmy1600Frame0, gEmy16Palette, gEmy1600Tiles, gCardEmy16Frame0, gEmy16Palette, gCardEmy16Tiles, 0, 0, 0, 0, 0, -1, -9 },
    { &gUnkEu_0888FCD0, &gUnkEu_0886FCC4, gEmy1800Frame0, gEmy18Palette, gEmy1800Tiles, gCardEmy18Frame0, gEmy18Palette, gCardEmy18Tiles, 0, 0, 0, 0, 0, -1, 3 },
    { &gUnkEu_0888FA8C, &gUnkEu_0886FFC8, gEmy1900Frame5, gEmy19Palette, gEmy1900Tiles, gCardEmy19Frame0, gEmy19Palette, gCardEmy19Tiles, 0, 0, 0, 0, 0, -1, -6 },
    { &gUnkEu_0888FA00, &gUnkEu_08870298, gEmy3900Frame0, gEmy39Palette, gEmy3900Tiles, gCardEmy39Frame0, gEmy39Palette, gCardEmy39Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { &gUnkEu_0888FD24, &gUnkEu_088705F0, gEmy2100Frame0, gEmy21Palette, gEmy2100Tiles, gCardEmy21Frame0, gEmy21Palette, gCardEmy21Tiles, 0, 0, 0, 0, 0, 1, -10 },
    { &gUnkEu_0888FE74, &gUnkEu_088708C4, gEmy2200Frame9, gEmy22Palette, gEmy2200Tiles, gCardEmy22Frame0, gEmy22Palette, gCardEmy22Tiles, 0, 0, 0, 0, 0, 2, 6 },
    { &gUnkEu_0888FA4C, &gUnkEu_08870BC4, gEmy0600Frame2, gEmy06Palette, gEmy0600Tiles, gCardEmy06Frame0, gEmy06Palette, gCardEmy06Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { &gUnkEu_0888FF00, &gUnkEu_08870E2C, gEmy2300Frame0, gEmy23Palette, gEmy2300Tiles, gCardEmy23Frame0, gEmy23Palette, gCardEmy23Tiles, 0, 0, 0, 0, 0, 1, 2 },
    { &gUnkEu_0888FEBC, &gUnkEu_088710CC, gEmy4100Frame0, gEmy41Palette, gEmy4100Tiles, gCardEmy41Frame0, gEmy41Palette, gCardEmy41Tiles, 0, 0, 0, 0, 0, -2, 11 },
    { &gUnkEu_0888FD80, &gUnkEu_088713AC, gEmy2500Frame3, gEmy25Palette, gEmy2500Tiles, gCardEmy25Frame0, gEmy25Palette, gCardEmy25Tiles, 0, 0, 0, 0, 0, 4, 0 },
    { &gUnkEu_0888FE18, &gUnkEu_08871634, gEmy2600Frame0, gEmy26Palette, gEmy2600Tiles, gCardEmy26Frame0, gEmy26Palette, gCardEmy26Tiles, 0, 0, 0, 0, 0, -4, 9 },
    { &gUnkEu_0888FACC, &gUnkEu_08871A6C, gEmy2700Frame0, gEmy27Palette, gEmy2700Tiles, gCardEmy27Frame0, gEmy27Palette, gCardEmy27Tiles, 0, 0, 0, 0, 0, 10, -10 },
    { &gUnkEu_0888FDD4, &gUnkEu_08871E00, gEmy2800Frame0, gEmy28Palette, gEmy2800Tiles, gCardEmy28Frame0, gEmy28Palette, gCardEmy28Tiles, 0, 0, 0, 0, 0, 5, 5 },
    { &gUnkEu_0888FF50, &gUnkEu_0887215C, gEmy2900Frame0, gEmy29Palette, gEmy2900Tiles, gCardEmy29Frame0, gEmy29Palette, gCardEmy29Tiles, 0, 0, 0, 0, 0, -3, 7 },
    { &gUnkEu_0888FFCC, &gUnkEu_08872678, gEmy4400Frame0, gEmy44Palette, gEmy4400Tiles, gCardEmy44Frame0, gEmy44Palette, gCardEmy44Tiles, 0, 0, 0, 0, 0, 3, 1 },
    { &gUnkEu_0888FF88, &gUnkEu_08872A00, gEmy3000Frame0, gEmy30Palette, gEmy3000Tiles, gCardEmy30Frame0, gEmy30Palette, gCardEmy30Tiles, 0, 0, 0, 0, 0, 2, -5 },
    { &gUnkEu_0888FC74, &gUnkEu_08872C8C, gEmy3100Frame6, gEmy31Palette, gEmy3100Tiles, gCardEmy31Frame0, gEmy31Palette, gCardEmy31Tiles, 0, 0, 0, 0, 0, 5, -3 },
    { &gUnkEu_088901A8, &gUnkEu_08872DE4, gEmy3700Frame1, gEmy37Palette, gEmy3700Tiles, gCardEmy37Frame0, gEmy37Palette, gCardEmy37Tiles, 0, 0, 0, 0, 0, -1, 4 },
    { &gUnkEu_088900CC, &gUnkEu_08873838, gEmy8300Frame0, gEmy83Palette, gEmy8300Tiles, gCardEmy83Frame0, gEmy83Palette, gCardEmy83Tiles, 0, 0, 0, 0, 0, 0, -4 },
    { &gUnkEu_08890118, &gUnkEu_08873B94, gEmy8100Frame0, gEmy81Palette, gEmy8100Tiles, gCardEmy81Frame0, gEmy81Palette, gCardEmy81Tiles, 0, 0, 0, 0, 0, -2, -3 },
    { &gUnkEu_0889015C, &gUnkEu_08873DB0, gEmy8201Frame2, gEmy82Palette, gEmy8201Tiles, gCardEmy82Frame0, gEmy82Palette, gCardEmy82Tiles, 0, 0, 0, 0, 0, 4, -10 },
    { &gUnkEu_08890200, &gUnkEu_0887A4D8, 0, 0, 0, gCardBos01Frame0, gBoss01objPalette, gCardBos01Tiles, gUnk_08F65B84, gUnk_08F6E044, gUnk_08EE8E84, 32, 3488, 3, -3 },
    { &gUnkEu_088903AC, &gUnkEu_0887A744, 0, 0, 0, gCardBos04Frame0, gBosPcBgPalette, gCardBos04Tiles, gUnk_08F66B84, gUnk_08F6E0A4, gUnk_08EEAD44, 96, 4864, 0, 0 },
    { &gUnkEu_08890290, &gUnkEu_0887AA0C, 0, 0, 0, gCardBos03Frame0, gBoss03objPalette, gCardBos03Tiles, gUnk_08F66384, gUnk_08F6E064, gUnk_08EE9C24, 64, 4384, 0, 3 },
    { &gUnkEu_08890484, &gUnkEu_0887AD44, 0, 0, 0, gCardBos00Frame0, gBoss00ObjPalette, gCardBos00Tiles, gUnk_08F65384, gUnk_08F6E024, gUnk_08EE7A24, 32, 5216, 0, 0 },
};

#endif

#if defined(VERSION_US)

const JiminyTextChar gUnk_08159D14[2] = { '?', 0 };

const JiminyTextChar gUnk_08159D18[3] = { '?', '?', 0 };

const JiminyTextChar gUnk_08159D1E[4] = { '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D26[5] = { '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D30[6] = { '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D3C[7] = { '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D4A[8] = { '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D5A[9] = { '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D6C[10] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D80[11] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159D96[12] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159DAE[13] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnk_08159DC8[14] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

#elif defined(VERSION_JP)

const JiminyTextChar gUnkJp_0814E494[27] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E4B0[25] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E4CC[23] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E4E4[21] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E4FC[19] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E510[17] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E524[15] = "\201\110\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E534[13] = "\201\110\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E544[11] = "\201\110\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E550[9] = "\201\110\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E55C[7] = "\201\110\201\110\201\110";

const JiminyTextChar gUnkJp_0814E564[5] = "\201\110\201\110";

const JiminyTextChar gUnkJp_0814E56C[3] = "\201\110";

#else

const JiminyTextChar gUnkEu_0887F2CC[2] = { '?', 0 };

const JiminyTextChar gUnkEu_0887F2CE[3] = { '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2D1[4] = { '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2D5[5] = { '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2DA[6] = { '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2E0[7] = { '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2E7[8] = { '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2EF[9] = { '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F2F8[10] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F302[11] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F30D[12] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F319[13] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

const JiminyTextChar gUnkEu_0887F326[14] = { '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', 0 };

#endif

JiminyWork* gJiminyWork;

void func_0805A484(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        gJiminyWork->unk_C68[i] = 0;
        FreeTextSlots(&gJiminyWork->lines[i], 48);

        for (j = 0; j < 48; j++) {
            if (gJiminyWork->lines[i].textSlots[j].tiles != 0) {
                gJiminyWork->lines[i].textSlots[j].tiles = 0;
            }
        }
    }
}

void func_0805A4D8(s16 a, s16 b, s16 c) {
    gJiminyWork->unk_CC0 = 0;
    gJiminyWork->x4 = a << 8;
    gJiminyWork->y5 = (b + gJiminyWork->unk_C74 * c) << 8;
}

void func_0805A514(s16 a, s16 b, s16 c) {
    s32 v;

    v = (b + gJiminyWork->unk_C74 * c) << 8;
    ApproachValueHalf(&gJiminyWork->y5, v);

    if (gJiminyWork->unk_CC0 > 0) {
        gJiminyWork->unk_CC0--;
    }
}

u16 func_0805A55C(u16* p) {
    s32 n;
    u16* q;

    q = p;
    n = 0;

    while (1) {
#ifdef VERSION_US
        if (q[n] == 0) {
#else
        if (((u8*)q)[n] == 0) {
#endif
#ifdef VERSION_JP
            return n / 2;
#else
            return n;
#endif
        }
        n++;
    }
}

s32 func_0805A574(s32 idx) {
    JiminyEntry* e;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 i;

    e = &gUnk_08155554[idx];
    if (e->flags != 0) {
        a = 1;
        b = 1;

        for (i = 0; i < (u16)e->count; i++) {
            if (func_0800FF70(e->flags[i])) {
                return 1;
            }

            if (func_0800FF00(e->flags[i]) == 0) {
                a = 0;
            } else {
                b = 0;
            }
        }

        if (a) {
            return 2;
        }

        if (b) {
            return 3;
        }
        return 0;
    }

    if (e->children == 0) {
        return 3;
    }
    c = 1;
    d = 1;

    for (i = 0; i < (u16)e->count; i++) {
        switch (func_0805A574(e->children[i])) {
        case 1:
            return 1;
        case 0:
            c = 0;
            d = 0;
            break;
        case 2:
            d = 0;
            break;
        case 3:
            c = 0;
            break;
        }
    }

    if (c) {
        return 2;
    }

    if (d) {
        return 3;
    }
    return 0;
}

void func_0805A638(s32 a, u16** b) {
    s16 t;

    t = func_0805A55C(b[a]);
    t--;
    if (t < 0) {
        t = 0;
    }

    if (t > 12) {
        t = 12;
    }
    gJiminyWork->textSlotCounts[a] = LoadTextSlots(gUnk_09EDE3FC[t], &gJiminyWork->lines[a]);
}

void func_0805A698(s16 a, s16 b, u16** d, const u16* c, const u16* e, s16 f, s16 g, s16 h) {
    s16 n;
    s32 i;

    n = a > b ? b : a;

    if (c == 0) {
        for (i = 0; i < n; i++) {
            if (e != 0) {
                gJiminyWork->unk_C68[i] = func_0805A574(e[i]);
                if (gJiminyWork->unk_C68[i] == 3) {
                    func_0805A638(i, d);
                } else {
                    gJiminyWork->textSlotCounts[i] =
                        LoadTextSlots(d[i], &gJiminyWork->lines[i]);
                }
            } else {
                gJiminyWork->textSlotCounts[i] =
                    LoadTextSlots(d[i], &gJiminyWork->lines[i]);
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (func_0800FF00(c[i])) {
                gJiminyWork->textSlotCounts[i] =
                    LoadTextSlots(d[i], &gJiminyWork->lines[i]);

                if (func_0800FF70(c[i])) {
                    gJiminyWork->unk_C68[i] = 1;
                }
            } else {
                func_0805A638(i, d);
            }
        }
    }
}

void func_0805A7D0(void) {
    s16 t;

    t = gJiminyWork->unk_C72 - gJiminyWork->unk_C74;
    func_0805A484();

    if (gJiminyWork->unk_CB8 != 0) {
        func_0805A698(gJiminyWork->unk_C78, gJiminyWork->unk_C76,
            gJiminyWork->unk_CB4 + t, gJiminyWork->unk_CB8 + t, 0,
            gJiminyWork->unk_CAE, gJiminyWork->unk_CB0, gJiminyWork->unk_CB2);
    } else {
        func_0805A698(gJiminyWork->unk_C78, gJiminyWork->unk_C76,
            gJiminyWork->unk_CB4 + t, 0, gJiminyWork->unk_CBC + t,
            gJiminyWork->unk_CAE, gJiminyWork->unk_CB0, gJiminyWork->unk_CB2);
    }
}

void func_0805A8D0(void) {
    s16 t;

    t = gJiminyWork->unk_C72 - gJiminyWork->unk_C74;
    func_0805A484();
    func_0805A698(gJiminyWork->unk_C78, gJiminyWork->unk_C76,
        gJiminyWork->unk_CB4 + t, 0, 0,
        gJiminyWork->unk_CAE, gJiminyWork->unk_CB0, gJiminyWork->unk_CB2);
}

void func_0805A95C(s16 a, s16 b, u16** c, const u16* d, const u16* e, s16 f, s16 g, s16 h) {
#ifdef VERSION_EU
    s32 i;
#endif

    gJiminyWork->unk_CAE = f;
    gJiminyWork->unk_CB0 = g;
    gJiminyWork->unk_CB2 = h;
    gJiminyWork->unk_C76 = b;
    gJiminyWork->unk_C78 = a;
#ifdef VERSION_EU

    for (i = 0; i < b; i++) {
        gJiminyWork->unk_D40[i] = eu_0805E924(c[i]);
    }

    gJiminyWork->unk_CB4 = gJiminyWork->unk_D40;
#else
    gJiminyWork->unk_CB4 = c;
#endif
    gJiminyWork->unk_CB8 = d;
    gJiminyWork->unk_CBC = e;
    gJiminyWork->x = f + 56;
    gJiminyWork->x2 = f + 56;
    gJiminyWork->y = g - 10;
    gJiminyWork->y2 = g + h * (a - 1) + 12;
    gJiminyWork->flags = (gJiminyWork->flags & 0xFFE5) | 4;
    gJiminyWork->unk_C70 = 0;
    func_0805A4D8(gJiminyWork->unk_CAE - 24, gJiminyWork->unk_CB0 - 4,
        gJiminyWork->unk_CB2);
    func_0805A7D0();
    gJiminyWork->unk_D3E = 0;
}

u8 func_0805AA9C(void) {
    if (FadeIsActive()) {
        return 1;
    }

    if (gJiminyWork->unk_C70 < gJiminyWork->unk_C71) {
        AnimChange(&gJiminyWork->anim, 1, 1);

        if (!FadeIsActive()) {
            if (gJiminyWork->unk_048 % 5 == 0) {
                gJiminyWork->unk_C70++;
            }
        }
    } else {
        AnimChange(&gJiminyWork->anim, 0, 1);
    }

    if (gJiminyWork->unk_C74 < gJiminyWork->unk_C72) {
        gJiminyWork->flags |= 8;
    } else {
        gJiminyWork->flags &= 0xFFF7;
    }

    if (gJiminyWork->unk_C78 - gJiminyWork->unk_C74 <
        gJiminyWork->unk_C76 - gJiminyWork->unk_C72) {
        gJiminyWork->flags |= 0x10;
    } else {
        gJiminyWork->flags &= 0xFFEF;
    }

    if (gJiminyWork->unk_CC0 <= 0) {
        if (GetKeysRepeat() & DPAD_UP) {
            if (gJiminyWork->unk_C72 > 0) {
                gJiminyWork->unk_CC0 = 1;
                gJiminyWork->unk_C72--;
                m4aSongNumStart(SONG_SYS_CLICK);

                if (gJiminyWork->unk_C74 > 0) {
                    gJiminyWork->unk_C74--;
                } else {
                    func_0805A7D0();
                }
            }
        } else if (GetKeysRepeat() & DPAD_DOWN) {
            if (gJiminyWork->unk_C72 < gJiminyWork->unk_C76 - 1) {
                gJiminyWork->unk_CC0 = 1;
                gJiminyWork->unk_C72++;
                m4aSongNumStart(SONG_SYS_CLICK);

                if (gJiminyWork->unk_C74 < gJiminyWork->unk_C78 - 1) {
                    gJiminyWork->unk_C74++;
                } else {
                    func_0805A7D0();
                }
            }
        }
    }
    func_0805A514(gJiminyWork->unk_CAE - 24, gJiminyWork->unk_CB0 - 4,
        gJiminyWork->unk_CB2);

    if (GetKeysPressed() & START_BUTTON) {
        gJiminyWork->unk_048 = 0;
        gJiminyWork->unk_000 = 5;
        m4aSongNumStart(SONG_SYS_CLOSE);
        return 1;
    }
    return 0;
}

void mode_jiminy_0(void) {
    s32 i;
    s32 j;
    JiminyEntry* e;

#ifdef VERSION_EU
    gJiminyWork = EwramAlloc(0xED0);
#else
    gJiminyWork = EwramAlloc(0xD40);
#endif
    SetBgMode0();
    SetupBg(0, 0, 0x1D, 0);
    SetupBg(1, 0, 0x1E, 0);
    SetupBg(2, 0, 0x1F, 0);
    SetupBg(3, 0, 0x1C, 0x0D);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 0);
    SetBgPriority(3, 0);
#ifdef VERSION_JP
    LoadBgTiles(1, gUnk_08EE4A64, 0x2DA0);
#elif defined(VERSION_EU)
    LoadBgTiles(1, gUnk_08EE4A64, 0x2F60);
    switch (gLanguage) {
    case 1:
        RequestDma3Copy(gUnkEu_08EF3EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 4:
        RequestDma3Copy(gUnkEu_08EF4EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 3:
        RequestDma3Copy(gUnkEu_08EF5EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 2:
        RequestDma3Copy(gUnkEu_08EF6EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    }
#else
    LoadBgTiles(1, gUnk_08EE4A64, 0x2E80);
#endif
    LoadBgPalette(1, gUnk_08F6DE24, 0x200);
    LoadBgMap(1, gUnk_08F61B84, 0x800);
    LoadBgMap(2, gUnk_08F60B84, 0x800);
#ifdef VERSION_EU
    if (gLanguage == 0) {
        gJiminyWork->tiles = LoadObjTiles(gUnk_08C69C9C, 0x880);
    } else {
        gJiminyWork->tiles = LoadObjTiles(gUnkEu_08C9A5E2, 0x1780);
    }
#else
    gJiminyWork->tiles = LoadObjTiles(gUnk_08C69C9C, 0x880);
#endif
    gJiminyWork->palette = LoadObjPalette(gUnk_08F6DD64, 0x20);
    FadeSetPaletteExcluded(gJiminyWork->palette->index + 0x10, 1);
    gJiminyWork->tiles2 = LoadObjTiles(gUnk_08C6A88C, 0x40);
    gJiminyWork->palette2 = LoadObjPalette(gUnk_08F6DDE4, 0x20);
    gJiminyWork->palette3 = LoadObjPalette(gUnk_08F6DD84, 0x20);
    gJiminyWork->tiles5 = LoadObjTiles(gUnk_08C6A54E, 0x140);
    gJiminyWork->palette6 = LoadObjPalette(gUnk_08F6DDA4, 0x20);
#ifdef VERSION_EU
    gJiminyWork->tiles6 = LoadObjTiles(gUnk_08C6A6B8, 0x340);
#else
    gJiminyWork->tiles6 = LoadObjTiles(gUnk_08C6A6B8, 0x1C0);
#endif
    gJiminyWork->palette7 = LoadObjPalette(gUnk_08F6DDC4, 0x20);
    gJiminyWork->x3 = -0x8000;
    gJiminyWork->y3 = -0x800;
    gJiminyWork->y4 = 0xA000;
    gJiminyWork->unk_000 = 0;
    gJiminyWork->unk_048 = 0;
    gJiminyWork->unk_C70 = 0;
    gJiminyWork->unk_C72 = 0;
    gJiminyWork->unk_C74 = 0;

    if (gGameState.flags & 8) {
        gJiminyWork->tiles3 = AllocObjTiles(0x1000, gTalk2700Tiles);
        gJiminyWork->palette4 = LoadObjPalette(gTalk2700Palette, 0x20);
        AnimInit(&gJiminyWork->anim, gTalk2700Anims, gTalk2700Frames);
        AnimStart(&gJiminyWork->anim, 0, 1);
    } else {
        gJiminyWork->tiles3 = AllocObjTiles(0x1000, gTalk0600Tiles);
        gJiminyWork->palette4 = LoadObjPalette(gTalk0600Palette, 0x20);
        AnimInit(&gJiminyWork->anim, gTalk0600Anims, gTalk0600Frames);
        AnimStart(&gJiminyWork->anim, 0, 1);
    }

    if (FadeIsActive() == 0) {
        gJiminyWork->tiles4 = AllocObjTiles(0x200, gUnk_08C6A958);
        gJiminyWork->palette5 = LoadObjPalette(gUnk_08F6DE04, 0x20);
        AnimInit(&gJiminyWork->anim2, gUnk_09EE2678, gUnk_09EE2668);
        AnimStart(&gJiminyWork->anim2, 2, 1);
    }

    gJiminyWork->tiles7 = AllocObjTiles(0x2000, 0);
#ifdef VERSION_EU
    gJiminyWork->palette8 = LoadObjPalette(gUnk_09A3CDDC, 0x40);
#else
    gJiminyWork->palette8 = LoadObjPalette(gUnk_09A3CC9C, 0x20);
#endif
    gJiminyWork->tiles8 = AllocObjTiles(0x800, 0);
    gJiminyWork->palette9 = LoadObjPalette(gCard00Palette, 0x20);
    gJiminyWork->unk_D3C = 0;
    gJiminyWork->unk_D38 = 0x100;
    FadeStartIn(0, 0x10);

    for (i = 0; i < 8; i++) {
        InitTextSlots(&gJiminyWork->lines[i], 0x30);
    }

    func_08064B80(0);
#ifdef VERSION_JP
    gJiminyWork->unk_C71 = func_080653D4(0x400, 0x2600, gUnk_08159FE0);
#elif defined(VERSION_EU)
    gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, eu_0805E924(gUnkEu_08892334));
#else
    gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);
#endif

    for (j = 0; j <= 0x14; j++) {
        gJiminyWork->pairs[j].unk_00 = 0;
        gJiminyWork->pairs[j].unk_02 = 0;
    }

    if (gGameState.flags & 8) {
        gJiminyWork->unk_D2C = 14;
        e = gUnk_08155554;
        e += 14;
        func_0805A95C(3, e->count, e->names, e->flags, e->children, 0x80, 0x40, 0x18);
        gJiminyWork->flags = 2;
    } else {
        gJiminyWork->unk_D2C = 0;
        e = gUnk_08155554;
        func_0805A95C(3, e->count, e->names, e->flags, e->children, 0x80, 0x40, 0x18);
        gJiminyWork->flags = 3;
    }
}

void mode_jiminy_1(void) {
    s32 i;
    u16 c;
    u16 t;
    JiminyEntry* e;
    JiminyPair* p;
    JiminyEntry* e2;
    JiminyPair* p2;

    switch (gJiminyWork->unk_000) {
    case 0:
        if (gJiminyWork->unk_048 == 0) {
            gJiminyWork->unk_04A = 16;
        }
        ApproachValue(&gJiminyWork->y3, 0, gJiminyWork->unk_04A);
        ApproachValue(&gJiminyWork->y4, 0x9800, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 1;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 1:
        if (gJiminyWork->unk_048 == 0) {
            gJiminyWork->unk_04A = 16;
        }
        ApproachValue(&gJiminyWork->x3, 0, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 6;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 2:
        if (gJiminyWork->unk_048 == 0) {
            c = gJiminyWork->flags | 2;
            gJiminyWork->flags = c & 0xFFFB;
            gJiminyWork->unk_04A = 16;
            LoadBgMap(1, gUnk_08F61B84, 0x800);
        }
        ApproachValue(&gJiminyWork->x3, -0x8000, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 3;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 3:
        if (gJiminyWork->unk_048 == 0) {
            gJiminyWork->unk_04A = 16;
        }
        ApproachValue(&gJiminyWork->y3, -0x800, gJiminyWork->unk_04A);
        ApproachValue(&gJiminyWork->y4, 0xA000, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 4;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 4:
        if (gJiminyWork->unk_048 == 0) {
            FadeStartOut(0, 16);
            FadeLock();
        }

        if (FadeGetAmount() > 30) {
            func_080E052C(1);
        }
        break;
    case 5:
        if (gJiminyWork->unk_048 == 0) {
            FadeStartOut(0, 16);
            FadeLock();
        }

        if (FadeGetAmount() > 30) {
            func_080E052C(0);
        }
        break;
    case 6:
        e = &gUnk_08155554[gJiminyWork->unk_D2C];
        p = &gJiminyWork->pairs[gJiminyWork->unk_D2C];
#ifdef VERSION_JP
        gJiminyWork->unk_C71 = func_080653D4(0x400, 0x2600, gUnk_08159FE0);
#else
#ifdef VERSION_EU
        gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, eu_0805E924(gUnkEu_08892334));
#else
        gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);
#endif
#endif
        DisableBg(3);
        DisableBg(0);
        gJiminyWork->unk_C72 = p->unk_00;
        gJiminyWork->unk_C74 = p->unk_02;

        if (gJiminyWork->unk_D2C == 0 || gJiminyWork->unk_D2C == 14) {
            if (gGameState.flags & 8) {
                LoadBgMap(1, gUnk_08F62B84, 0x800);
            } else {
                LoadBgMap(1, e->map, 0x800);
            }
            LoadObjPaletteBank(gJiminyWork->palette3->index, gUnk_08F6DD84);
            func_0805A95C(3, e->count, e->names, e->flags, e->children, 0x80, 0x40, 0x18);
        } else {
            LoadBgMap(1, e->map, 0x800);
            LoadObjPaletteBank(gJiminyWork->palette3->index, gUnk_08F6DDC4);
#ifdef VERSION_JP
            func_0805A95C(8, e->count, e->names, e->flags, e->children, 0x70, 0x1A, 0x10);
#else
            func_0805A95C(4, e->count, e->names, e->flags, e->children, 0x70, 0x3A, 0x10);
#endif
        }

        gJiminyWork->unk_000 = 7;
    case 7:
        e2 = &gUnk_08155554[gJiminyWork->unk_D2C];
        p2 = &gJiminyWork->pairs[gJiminyWork->unk_D2C];

        if (func_0805AA9C() != 0) {
            break;
        }

        p2->unk_00 = gJiminyWork->unk_C72;
        p2->unk_02 = gJiminyWork->unk_C74;

        if (GetKeysPressed() & B_BUTTON) {
            gJiminyWork->unk_048 = 0;

            if (e2->parent == -1) {
                gJiminyWork->unk_000 = 2;
            } else {
                gJiminyWork->unk_000 = 6;
                gJiminyWork->unk_D2C = e2->parent;
                FadeStartIn(0, 5);
                FadeLock();
            }
            m4aSongNumStart(SONG_SYS_CLOSE);
            break;
        }

        if (GetKeysPressed() & A_BUTTON) {
            u32 ok;

            ok = 1;

            if (e2->flags != 0) {
                ok = func_0800FF00(e2->flags[gJiminyWork->unk_C72]) != 0;
            } else {
                if (gJiminyWork->unk_C68[gJiminyWork->unk_C74] == 3) {
                    ok = 0;
                }
            }

            if (ok != 0) {
                m4aSongNumStart(SONG_SYS_KETTEI);

                if (e2->children != 0) {
                    gJiminyWork->unk_000 = 6;
                    gJiminyWork->unk_D2C = e2->children[gJiminyWork->unk_C72];
                    gJiminyWork->unk_048 = 0;
                    FadeStartIn(0, 5);
                    FadeLock();
                    break;
                } else {
                    FadeStartIn(0, 5);
                    FadeLock();
                    gJiminyWork->unk_048 = 0;
                    gJiminyWork->unk_000 = 8;
                    gJiminyWork->unk_CD2 = gJiminyWork->unk_C72;
                    gJiminyWork->unk_D34 = e2->detail;
                    SetModeUpdate(func_0805BAE4);
                    break;
                }
            }
        }

        gJiminyWork->unk_048++;
        break;
    }

    t = abs(gSineTable[(gJiminyWork->unk_D3E * 2) & 0xFF]) * 15 >> 8;
    gBldCnt = (BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    SetBlendAlpha(t, 16 - t);

    if (gJiminyWork->flags & 1) {
        EnableBg(2);
        func_080658B8(gJiminyWork->unk_C70);
        DrawSprite(0x23, 0x76, AnimUpdate(&gJiminyWork->anim), gJiminyWork->tiles3,
            gJiminyWork->palette4, 0, 0, 0);
    } else {
        DisableBg(2);
    }

    for (i = 0; gJiminyWork->lines[i].textSlots[0].tiles != 0; i++) {
        if (i >= gJiminyWork->unk_C78) {
            break;
        }
        DrawTextSlots(gJiminyWork->unk_CAE, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i,
            &gJiminyWork->lines[i], gJiminyWork->palette3, 0, gJiminyWork->textSlotCounts[i]);

        if (gJiminyWork->unk_000 == 7) {
            switch (gJiminyWork->unk_C68[i]) {
            case 1:
#ifdef VERSION_EU
                switch (gLanguage) {
                case 0:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnk_08C6A6A4,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 1:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BD82,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 4:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BD8C,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 3:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BD9C,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 2:
                default:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BDAC,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                }
#else
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnk_08C6A6A4,
                    gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0);
#endif
                break;
            case 2:
#ifdef VERSION_EU
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i - 2, gUnk_08C6A69A,
                    gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
#else
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i - 2, gUnk_08C6A69A,
                    gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0);
#endif
                break;
            }
        }
    }

    if (gJiminyWork->flags & 2) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnk_08C69C76, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnk_08C69C04, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->y3 >> 8, gUnk_08C69C20, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->y4 >> 8, gUnk_08C69C54, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 1:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A538, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A4CC, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->y3 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->y4 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 4:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A564, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A554, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->y3 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->y4 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 3:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A590, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A57A, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->y3 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->y4 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 2:
        default:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A5C2, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->x3 >> 8, 0, gUnkEu_08C9A5A6, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->y3 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->y4 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        }
#else
        if (gGameState.flags & 8) {
            DrawSprite(gJiminyWork->x3 >> 8, 0, gUnk_08C69C76, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 0);
        } else {
            DrawSprite(gJiminyWork->x3 >> 8, 0, gUnk_08C69C04, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 0);
        }
        DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
        DrawSprite(0x80, gJiminyWork->y3 >> 8, gUnk_08C69C20, gJiminyWork->tiles,
            gJiminyWork->palette, 0, 0, 1);
        DrawSprite(0x80, gJiminyWork->y4 >> 8, gUnk_08C69C54, gJiminyWork->tiles,
            gJiminyWork->palette, 0, 0, 1);
#endif
    }

    if (gJiminyWork->unk_000 == 7) {
        if (gJiminyWork->flags & 8) {
            DrawSprite(gJiminyWork->x, gJiminyWork->y - ((gJiminyWork->unk_D3E >> 3) & 3),
                gUnk_08C6A51C, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
        }

        if (gJiminyWork->flags & 0x10) {
            DrawSprite(gJiminyWork->x2, gJiminyWork->y2 + ((gJiminyWork->unk_D3E >> 3) & 3),
                gUnk_08C6A526, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
        }

        if (FadeIsActive() == 0) {
            if (gJiminyWork->flags & 4) {
                if (gJiminyWork->unk_CC0 <= 0) {
                    DrawSprite(gJiminyWork->x4 >> 8, gJiminyWork->y5 >> 8,
                        AnimUpdate(&gJiminyWork->anim2), gJiminyWork->tiles4,
                        gJiminyWork->palette5, 0, 0, 0);
                } else {
                    DrawSprite(gJiminyWork->x4 >> 8, gJiminyWork->y5 >> 8, gUnk_08C6A8F8,
                        gJiminyWork->tiles4, gJiminyWork->palette5, 0, 0, 0);

                    if (gJiminyWork->unk_CC0 == 1) {
                        AnimReset(&gJiminyWork->anim2);
                    }
                }
            }
        }
    }

    UpdatePlayTime();
    gJiminyWork->unk_D3E++;
}

void func_0805B9D0(s16 a, s16 b, s32 c, s16 d, s16 e, s16 f) {
    gJiminyWork->unk_CAE = d;
    gJiminyWork->unk_CB0 = e;
    gJiminyWork->unk_CB2 = f;
    gJiminyWork->unk_C76 = b;
    gJiminyWork->unk_C78 = a;
    gJiminyWork->unk_CB4 = c;
    gJiminyWork->x = d + 0x38;
    gJiminyWork->x2 = d + 0x38;
    gJiminyWork->y = e - 10;
    gJiminyWork->y2 = e + f * (a - 1) + 12;
    gJiminyWork->unk_C72 = 0;
    gJiminyWork->unk_C74 = 0;
    gJiminyWork->unk_CC0 = 0;
    gJiminyWork->unk_D3E = 0;
    func_0805A8D0();
}

void SplitThreeDecimalDigits(s16 a, u8* out) {
    out[0] = a / 100;
    out[1] = a % 100 / 10;
    out[2] = a % 10;
}

void func_0805BAE4(void) {
    s32 count;
    JiminyDetail* entries;
    s16 i;
    s16 unlocked;
    s16 selected;
    s16 width;
    u8 digits[3];
    u8* map0;
    u8* map1;
    u8* source;
    u8* dest;
    u16* paletteDest;
#ifdef VERSION_EU
    s32 wide = 0;
#endif

    switch ((u32)gJiminyWork->unk_000) {
    case 8:
        switch ((u32)gJiminyWork->unk_D34) {
        case 1:
            count = 17;
            entries = gUnk_0815574C;
            gJiminyWork->unk_D30 = 0;
            break;
        case 2:
            count = 17;
            entries = gUnk_08155C54;
            gJiminyWork->unk_D30 = 1;
            break;
        case 3:
            count = 14;
            entries = gUnk_0815600C;
            gJiminyWork->unk_D30 = 1;
            break;
        case 4:
            count = 7;
            entries = gUnk_0815631C;
            gJiminyWork->unk_D30 = 1;
            break;
        case 5:
            count = 7;
            entries = gUnk_081564A4;
            gJiminyWork->unk_D30 = 1;
            break;
        case 6:
            count = 49;
            entries = gUnk_0815662C;
            gJiminyWork->unk_D30 = 1;
            break;
        case 7:
            count = 26;
            entries = gUnk_081570E4;
            gJiminyWork->unk_D30 = 1;
            break;
        case 8:
            count = 1;
            entries = gUnk_08157694;
            gJiminyWork->unk_D30 = 1;
            break;
        case 9:
            count = 25;
            entries = gUnk_08157B9C;
            gJiminyWork->unk_D30 = 2;
            break;
        case 10:
            count = 40;
            entries = gUnk_08158114;
            gJiminyWork->unk_D30 = 2;
            break;
        case 11:
            count = 35;
            entries = gUnk_081589D4;
            gJiminyWork->unk_D30 = 2;
            break;
        case 12:
            count = 6;
            entries = gUnk_08155B04;
            gJiminyWork->unk_D30 = 0;
            break;
        case 13:
            count = 22;
            entries = gUnk_081576CC;
            gJiminyWork->unk_D30 = 1;
            break;
        case 14:
            count = 14;
            entries = gUnk_0815917C;
            gJiminyWork->unk_D30 = 2;
            break;
        case 15:
            count = 6;
            entries = gUnk_0815948C;
            gJiminyWork->unk_D30 = 2;
            break;
        case 16:
            count = 33;
            entries = gUnk_081595DC;
            gJiminyWork->unk_D30 = 2;
            break;
        default:
            count = 25;
            entries = gUnk_08157B9C;
            gJiminyWork->unk_D30 = 2;
            break;
        }
        gJiminyWork->unk_CD0 = count;
        if (gJiminyWork->unk_CD2 >= (s16)count) {
            gJiminyWork->unk_CD2 = 0;
        }
        gJiminyWork->detail = &entries[gJiminyWork->unk_CD2];
        if (gJiminyWork->unk_CB8 != 0) {
            func_0800FFE0(gJiminyWork->unk_CB8[gJiminyWork->unk_CD2]);
            unlocked = 0;
            selected = 0;
            for (i = 0; i < count; i++) {
                if (func_0800FF00(gJiminyWork->unk_CB8[i])) {
                    if (gJiminyWork->unk_CD2 == i) {
                        selected = unlocked;
                    }
                    unlocked++;
                }
            }
            gJiminyWork->unk_CD4 = gJiminyWork->unk_CD2;
            gJiminyWork->unk_CD6 = gJiminyWork->unk_CD2;
            i = gJiminyWork->unk_CD2 + 1;
            for (;;) {
                if (i >= count) {
                    i = 0;
                }
                if (i == gJiminyWork->unk_CD2) {
                    break;
                }
                if (func_0800FF00(gJiminyWork->unk_CB8[i])) {
                    gJiminyWork->unk_CD4 = i;
                    break;
                }
                i++;
            }
            i = gJiminyWork->unk_CD2 - 1;
            for (;;) {
                if (i < 0) {
                    i = count - 1;
                }
                if (i == gJiminyWork->unk_CD2) {
                    break;
                }
                if (func_0800FF00(gJiminyWork->unk_CB8[i])) {
                    gJiminyWork->unk_CD6 = i;
                    break;
                }
                i--;
            }
        } else {
            unlocked = count;
            selected = gJiminyWork->unk_CD2;
            gJiminyWork->unk_CD4 = gJiminyWork->unk_CD2 + 1;
            if (gJiminyWork->unk_CD4 >= count) {
                gJiminyWork->unk_CD4 = 0;
            }
            gJiminyWork->unk_CD6 = gJiminyWork->unk_CD2 - 1;
            if (gJiminyWork->unk_CD6 < 0) {
                gJiminyWork->unk_CD6 = count - 1;
            }
        }
        switch (gJiminyWork->unk_D30) {
        case 0:
            map0 = gUnk_08F64384;
            map1 = gUnk_08F60384;
#ifdef VERSION_JP
            gJiminyWork->unk_C71 = func_080653D4(0x400,
                0x1800, gJiminyWork->detail->name);
#elif defined(VERSION_EU)
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, eu_0805E924(gJiminyWork->detail->name));
#else
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, gJiminyWork->detail->name);
#endif
#ifdef VERSION_EU
            func_0805B9D0(4, eu_0805E9AC(gJiminyWork->detail->text), (s32)eu_0805E968(gJiminyWork->detail->text), 8, 0x3A, 16);
#else
#ifdef VERSION_JP
            func_0805B9D0(7, gJiminyWork->detail->lineCount, (s32)gJiminyWork->detail->text, 8, 0x2A, 16);
#else
            func_0805B9D0(4, gJiminyWork->detail->lineCount, (s32)gJiminyWork->detail->text, 8, 0x3A, 16);
#endif
#endif
            break;
        case 1:
            map0 = gUnk_08F64384;
            map1 = gUnk_08F5EB84;
#ifdef VERSION_JP
            gJiminyWork->unk_C71 = func_080653D4(0x400,
                0x1800, gJiminyWork->detail->name);
#elif defined(VERSION_EU)
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, eu_0805E924(gJiminyWork->detail->name));
#else
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, gJiminyWork->detail->name);
#endif
#ifdef VERSION_EU
            func_0805B9D0(4, eu_0805E9AC(gJiminyWork->detail->text), (s32)eu_0805E968(gJiminyWork->detail->text), 8, 0x3A, 16);
#else
#ifdef VERSION_JP
            func_0805B9D0(7, gJiminyWork->detail->lineCount, (s32)gJiminyWork->detail->text, 8, 0x2A, 16);
#else
            func_0805B9D0(4, gJiminyWork->detail->lineCount, (s32)gJiminyWork->detail->text, 8, 0x3A, 16);
#endif
#endif
            break;
        case 2:
        default:
            map0 = gUnk_08F63384;
            map1 = gUnk_08F5FB84;
#ifdef VERSION_JP
            gJiminyWork->unk_C71 = func_080653D4(0x2800,
                0x1800, gJiminyWork->detail->name);
#elif defined(VERSION_EU)
            gJiminyWork->unk_C71 = func_08065170(0x2800,
                0x1600, eu_0805E924(gJiminyWork->detail->name));
#else
            gJiminyWork->unk_C71 = func_08065170(0x2800,
                0x1600, gJiminyWork->detail->name);
#endif
#ifdef VERSION_EU
            func_0805B9D0(4, eu_0805E9AC(gJiminyWork->detail->text), (s32)eu_0805E968(gJiminyWork->detail->text), 8, 0x3A, 16);
#else
            func_0805B9D0(
#ifdef VERSION_JP
                6,
#else
                4,
#endif
                gJiminyWork->detail->lineCount, (s32)gJiminyWork->detail->text, 8, 0x3A, 16);
#endif
            break;
        }
        LoadBgMap(0, map0, 0x800);
        LoadBgMap(1, map1, 0x800);
        if (gJiminyWork->detail->tiles != 0) {
#ifdef VERSION_EU
            if (gJiminyWork->detail->palette == gUnkEu_09A9A880 && func_080D2DD8()) {
                LoadObjPaletteBank(gJiminyWork->palette8->index, gUnkEu_09A9A8A0);
                LoadObjPaletteBank(gJiminyWork->palette8->index + 1, gUnkEu_09A9A8A0 + 0x20);
                SetObjTileSource(gJiminyWork->tiles7, gUnk_099EDE7C);
            } else
#endif
            {
                LoadObjPaletteBank(gJiminyWork->palette8->index, gJiminyWork->detail->palette);
                SetObjTileSource(gJiminyWork->tiles7, gJiminyWork->detail->tiles);
            }
        }
        if (gJiminyWork->detail->tiles2 != 0) {
            LoadObjPaletteBank(gJiminyWork->palette9->index, gJiminyWork->detail->palette2);
            SetObjTileSource(gJiminyWork->tiles8, gJiminyWork->detail->tiles2);
        }
        if (gJiminyWork->unk_D30 == 2) {
            source = gUnk_08F63B84;
            dest = (u8*)GetBgScreenBase(0) + 0x8E;
        } else {
            source = gUnk_08F64B84;
            dest = (u8*)GetBgScreenBase(0) + 0x80;
        }
        if (gJiminyWork->unk_D30 < 2) {
#ifdef VERSION_JP
            switch (gJiminyWork->unk_C71) {
            case 1: source += 0xC0; break;
            case 2: source += 0x240; break;
            case 3: source += 0x300; break;
            case 4: source += 0x480; break;
            case 5: source += 0x540; break;
            case 6: source += 0x600; break;
            case 7: source += 0x6C0; break;
            case 8: source += 0xE0; break;
            case 9: source += 0x1A0; break;
            case 10: source += 0x260; break;
            default: source += 0x320; break;
            }
#else
            width = func_08064DD4(
#ifdef VERSION_EU
                eu_0805E924(gJiminyWork->detail->name)
#else
                gJiminyWork->detail->name
#endif
            );
            switch ((width + 12) / 8) {
            case 0: source += 0x240; break;
            case 1: source += 0x240; break;
            case 2: source += 0x240; break;
            case 3: source += 0x240; break;
            case 4: source += 0x300; break;
            case 5: source += 0x3C0; break;
            case 6: source += 0x480; break;
            case 7: source += 0x540; break;
            case 8: source += 0x600; break;
            case 9: source += 0x6C0; break;
            case 10: source += 0x20; break;
            case 11: source += 0xE0; break;
            case 12: source += 0x1A0; break;
            case 13: source += 0x260; break;
#ifdef VERSION_EU
            case 14: source += 0x320; break;
            case 15: source += 0x3E0; break;
            default: source += 0x3E0; wide = 1; break;
#else
            default: source += 0x320; break;
#endif
            }
#endif
        } else {
#ifdef VERSION_JP
            width = gJiminyWork->unk_C71;
#else
            width = (s16)func_08064DD4(
#ifdef VERSION_EU
                eu_0805E924(gJiminyWork->detail->name)
#else
                gJiminyWork->detail->name
#endif
            ) / 8;
#endif
            switch (width) {
            case 0: break;
            case 1: break;
            case 2: source += 0xC0; break;
            case 3: source += 0x180; break;
            case 4: source += 0x240; break;
            case 5: source += 0x300; break;
            case 6: source += 0x3C0; break;
#ifdef VERSION_JP
            case 7: source += 0x540; break;
            case 8: source += 0x600; break;
            case 9: source += 0x6C0; break;
            case 10: source += 0x20; break;
            case 11: source += 0x1A0; break;
            case 12: source += 0x1A0; break;
            case 13: source += 0x1A0; break;
#else
            case 7: source += 0x480; break;
            case 8: source += 0x540; break;
            case 9: source += 0x600; break;
            case 10: source += 0x6C0; break;
            case 11: source += 0x20; break;
            case 12: source += 0xE0; break;
            case 13: source += 0x1A0; break;
#endif
            default: source += 0x260; break;
            }
        }
        RequestDma3Copy(source, dest, 0x20);
        RequestDma3Copy(source + 0x40, dest + 0x40, 0x20);
        RequestDma3Copy(source + 0x80, dest + 0x80, 0x20);
#ifdef VERSION_EU
        if (wide) {
            RequestDma3Copy(source, dest + 2, 0x20);
            RequestDma3Copy(source + 0x40, dest + 0x42, 0x20);
            RequestDma3Copy(source + 0x80, dest + 0x82, 0x20);
        }
#endif
        source = gUnk_08EE78E4;
        SplitThreeDecimalDigits(selected + 1, digits);
        dest = (u8*)GetBgCharBase(0) + 0x20;
        RequestDma3Copy(source + digits[0] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0x40;
        RequestDma3Copy(source + digits[1] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0x60;
        RequestDma3Copy(source + digits[2] * 0x20, dest, 0x20);
        SplitThreeDecimalDigits(unlocked, digits);
        dest = (u8*)GetBgCharBase(0) + 0x80;
        RequestDma3Copy(source + digits[0] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0xA0;
        RequestDma3Copy(source + digits[1] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0xC0;
        RequestDma3Copy(source + digits[2] * 0x20, dest, 0x20);
        gJiminyWork->unk_000 = 9;
        DisableBg(2);
        if (gJiminyWork->detail->bgTiles != 0) {
            EnableBg(3);
            RequestDma3Copy(gJiminyWork->detail->bgTiles,
                (u8*)GetBgCharBase(3) + 0x4000, gJiminyWork->detail->tileSize);
            switch ((u16)gJiminyWork->detail->paletteSize) {
            case 0x60:
                paletteDest = (u16*)0x050001A0;
                LoadPalette(gJiminyWork->detail->bgPalette, paletteDest, 0x60);
                break;
            case 0x40:
                paletteDest = (u16*)0x050001C0;
                LoadPalette(gJiminyWork->detail->bgPalette, paletteDest, 0x40);
                break;
            case 0x20:
            default:
                paletteDest = (u16*)0x050001E0;
                LoadPalette(gJiminyWork->detail->bgPalette, paletteDest, 0x20);
                break;
            }
            LoadBgMap(3, gJiminyWork->detail->bgMap, 0x800);
        } else {
            DisableBg(3);
        }
        gJiminyWork->unk_D3C = 5;
        SetBlendAlpha(0, 16);
    case 9:
        if (gJiminyWork->unk_C72 > 0) {
            gJiminyWork->flags |= 8;
        } else {
            gJiminyWork->flags &= ~8;
        }
        if (gJiminyWork->unk_C78 < gJiminyWork->unk_C76 - gJiminyWork->unk_C72) {
            gJiminyWork->flags |= 0x10;
        } else {
            gJiminyWork->flags &= ~0x10;
        }
        if (FadeIsActive() != 0) {
            break;
        }
        if (gJiminyWork->unk_CC0 <= 0) {
            if (GetKeysRepeat() & DPAD_UP) {
                if (gJiminyWork->unk_C72 > 0) {
                    gJiminyWork->unk_CC0 = 1;
                    gJiminyWork->unk_C72--;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                    func_0805A8D0();
                }
            } else if (GetKeysRepeat() & DPAD_DOWN) {
                if (gJiminyWork->unk_C78 < gJiminyWork->unk_C76 - gJiminyWork->unk_C72) {
                    gJiminyWork->unk_CC0 = 1;
                    gJiminyWork->unk_C72++;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                    func_0805A8D0();
                }
            }
        } else {
            gJiminyWork->unk_CC0 = 0;
        }
        if (gJiminyWork->unk_CD2 != gJiminyWork->unk_CD4) {
            if (GetKeysRepeat() & L_BUTTON) {
                gJiminyWork->unk_000 = 8;
                gJiminyWork->unk_048 = 0;
                gJiminyWork->unk_CD2 = gJiminyWork->unk_CD6;
                m4aSongNumStart(SONG_SYS_CANSEL);
                break;
            } else if (GetKeysRepeat() & R_BUTTON) {
                gJiminyWork->unk_000 = 8;
                gJiminyWork->unk_048 = 0;
                gJiminyWork->unk_CD2 = gJiminyWork->unk_CD4;
                m4aSongNumStart(SONG_SYS_CANSEL);
                break;
            }
        }
        if (GetKeysPressed() & B_BUTTON) {
            gJiminyWork->unk_048 = 0;
            gJiminyWork->unk_000 = 6;
            FadeStartIn(0, 5);
            FadeLock();
            SetModeUpdate(mode_jiminy_1);
            m4aSongNumStart(SONG_SYS_CLOSE);
        } else if (GetKeysPressed() & START_BUTTON) {
            gJiminyWork->unk_048 = 0;
            gJiminyWork->unk_000 = 5;
            m4aSongNumStart(SONG_SYS_CLOSE);
        }
        break;
    case 5:
        if (gJiminyWork->unk_048 == 0) {
            FadeStartOut(0, 16);
            FadeLock();
        }
        if (FadeGetAmount() > 30) {
            func_080E052C(0);
        }
        break;
    }
    func_080658B8(gJiminyWork->unk_C71);
    for (i = 0; gJiminyWork->lines[i].textSlots[0].tiles != 0 && i < gJiminyWork->unk_C78; i++) {
        DrawTextSlots(gJiminyWork->unk_CAE, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i,
            &gJiminyWork->lines[i], gJiminyWork->palette3, 0, gJiminyWork->textSlotCounts[i]);
    }
    if (gJiminyWork->flags & 8) {
        DrawSprite(gJiminyWork->x, gJiminyWork->y - ((gJiminyWork->unk_D3E >> 3) & 3) + 4,
            gUnk_08C6A51C, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
    }
    if (gJiminyWork->flags & 0x10) {
        DrawSprite(gJiminyWork->x2, gJiminyWork->y2 + ((gJiminyWork->unk_D3E >> 3) & 3),
            gUnk_08C6A526, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
    }
    if (gJiminyWork->unk_CD2 != gJiminyWork->unk_CD4) {
        DrawSprite(-((gJiminyWork->unk_D3E >> 3) & 3) + 0x9A, 5, gUnk_08C6A530,
            gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
        DrawSprite(0xE0 + ((gJiminyWork->unk_D3E >> 3) & 3), 5, gUnk_08C6A53A,
            gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
    }
    switch (gJiminyWork->unk_D30) {
    case 0:
        if (gJiminyWork->detail->tiles != 0) {
            DrawSprite(gJiminyWork->detail->x + 0xC8, gJiminyWork->detail->y + 0x5C,
                gJiminyWork->detail->sprite, gJiminyWork->tiles7, gJiminyWork->palette8, 0, 4, 1);
        }
        break;
    case 1:
        if (gJiminyWork->detail->tiles != 0) {
            DrawSprite(0xC2, 0x5E, gJiminyWork->detail->sprite,
                gJiminyWork->tiles7, gJiminyWork->palette8, 0, 4, 1);
        }
        if (gJiminyWork->detail->tiles2 != 0 && gJiminyWork->detail->sprite2 != 0) {
            DrawSprite(0xC2, 0x5E, gJiminyWork->detail->sprite2,
                gJiminyWork->tiles8, gJiminyWork->palette9, 0, 4, 0);
        }
        break;
    case 2:
        if (gJiminyWork->detail->tiles != 0) {
            DrawSprite(gJiminyWork->detail->x + 0xC4, gJiminyWork->detail->y + 0x74,
                gJiminyWork->detail->sprite, gJiminyWork->tiles7, gJiminyWork->palette8, 0, 4, 1);
        }
        if (gJiminyWork->detail->tiles2 != 0) {
            DrawSprite(0x14, 0x25, gJiminyWork->detail->sprite2,
                gJiminyWork->tiles8, gJiminyWork->palette9, 0, 0x404, 0);
        }
        break;
    }
    if ((s16)gJiminyWork->unk_D3C > 0) {
        gJiminyWork->unk_D3C--;
    }
    UpdatePlayTime();
    gJiminyWork->unk_D3E++;
}

void mode_jiminy_2(void) {
    func_08065940();
    ReleaseObjTiles(gJiminyWork->tiles);
    ReleaseObjPalette(gJiminyWork->palette);
    ReleaseObjTiles(gJiminyWork->tiles2);
    ReleaseObjPalette(gJiminyWork->palette2);
    ReleaseObjPalette(gJiminyWork->palette3);
    ReleaseObjTiles(gJiminyWork->tiles3);
    ReleaseObjPalette(gJiminyWork->palette4);
    ReleaseObjTiles(gJiminyWork->tiles4);
    ReleaseObjPalette(gJiminyWork->palette5);
    ReleaseObjTiles(gJiminyWork->tiles5);
    ReleaseObjPalette(gJiminyWork->palette6);
    ReleaseObjTiles(gJiminyWork->tiles6);
    ReleaseObjPalette(gJiminyWork->palette7);
    ReleaseObjTiles(gJiminyWork->tiles7);
    ReleaseObjPalette(gJiminyWork->palette8);
    ReleaseObjTiles(gJiminyWork->tiles8);
    ReleaseObjPalette(gJiminyWork->palette9);
    func_0805A484();
    EwramFree(gJiminyWork);
}

Mode gModeJiminy = {
    "mode_jiminy",
    (ModeInitFunc)mode_jiminy_0,
    mode_jiminy_1,
    mode_jiminy_2,
};
