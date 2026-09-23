#include "task_descriptors.h"
#include "system_state.h"
#include "map_api.h"
#include "ms_api.h"
#include "fade.h"
#include "obj_api.h"
#include "pallet.h"
#include "hum.h"
#include "task_animation_assets.h"
#include "sprites_btl.h"
#include "sprites_cloud.h"
#include "sprites_evt.h"
#include "sprites_hum.h"

const u32 gUnk_0813EDD0[2][3] = {
    { 37, 37, 37 },
    { 37, 36, 37 },
};

const AnimDef gUnk_0813EDE8[20] = {
    { gUnk_09EE15FC, gUnk_09EE1614, gUnk_08B268D2, 0, { 0, 0, 0 } },
    { gUnk_09EE1618, gUnk_09EE1638, gUnk_08B2A57A, 0, { 0, 0, 0 } },
    { gUnk_09EE163C, gUnk_09EE1650, gUnk_08B2F5FE, 0, { 0, 0, 0 } },
    { gUnk_09EE1654, gUnk_09EE1670, gUnk_08B326C8, 0, { 0, 0, 0 } },
    { gUnk_09EE1654, gUnk_09EE1670, gUnk_08B326C8, 1, { 0, 0, 0 } },
    { gUnk_09EE1654, gUnk_09EE1670, gUnk_08B326C8, 2, { 0, 0, 0 } },
    { gUnk_09EE1654, gUnk_09EE1670, gUnk_08B326C8, 3, { 0, 0, 0 } },
    { gUnk_09EE1654, gUnk_09EE1670, gUnk_08B326C8, 4, { 0, 0, 0 } },
    { gUnk_09EDE6AC, gUnk_09EDE6D4, gUnk_08888D44, 2, { 0, 0, 0 } },
    { gUnk_09EDE6AC, gUnk_09EDE6D4, gUnk_08888D44, 2, { 0, 0, 0 } },
    { gUnk_09EDE688, gUnk_09EDE69C, gUnk_08885C06, 0, { 0, 0, 0 } },
    { gUnk_09EDE688, gUnk_09EDE69C, gUnk_08885C06, 1, { 0, 0, 0 } },
    { gUnk_09EDE688, gUnk_09EDE69C, gUnk_08885C06, 2, { 0, 0, 0 } },
    { gUnk_09EDE688, gUnk_09EDE69C, gUnk_08885C06, 3, { 0, 0, 0 } },
    { gUnk_09EDE714, gUnk_09EDE720, gUnk_08895A7E, 0, { 0, 0, 0 } },
    { gUnk_09EDE724, gUnk_09EDE740, gUnk_08897494, 0, { 0, 0, 0 } },
    { gUnk_09EDE744, gUnk_09EDE764, gUnk_0889B1A4, 0, { 0, 0, 0 } },
    { gUnk_09EDE768, gUnk_09EDE78C, gUnk_0889F73C, 0, { 0, 0, 0 } },
    { gUnk_09EDE6AC, gUnk_09EDE6D4, gUnk_08888D44, 0, { 0, 0, 0 } },
    { gUnk_09EDE6E0, gUnk_09EDE70C, gUnk_0888F218, 0, { 0, 0, 0 } },
};

const HumDef gUnk_0813EF28 = { 128, 0, gUnk_08F6DC24, 0, { 43, 99, 38, 14, 24, 99, 0 } };

const char gTaskNameHumCloud[] = "task_hum_cloud";

const u32 gUnk_0813EF54[3] = {
    36, 36, 38,
};

const u32 gUnk_0813EF60[3] = {
    37, 37, 38,
};

const AnimDef gUnk_0813EF6C[15] = {
    { gUnk_09EE1684, gUnk_09EE16A4, gUnk_08B36DEC, 0, { 0, 0, 0 } },
    { gUnk_09EE16A8, gUnk_09EE16C8, gUnk_08B3BFE6, 0, { 0, 0, 0 } },
    { gUnk_09EE16CC, gUnk_09EE16E4, gUnk_08B4181C, 0, { 0, 0, 0 } },
    { gUnk_09EE16E8, gUnk_09EE170C, gUnk_08B452A4, 0, { 0, 0, 0 } },
    { gUnk_09EE16E8, gUnk_09EE170C, gUnk_08B452A4, 1, { 0, 0, 0 } },
    { gUnk_09EE16E8, gUnk_09EE170C, gUnk_08B452A4, 2, { 0, 0, 0 } },
    { gUnk_09EE16E8, gUnk_09EE170C, gUnk_08B452A4, 3, { 0, 0, 0 } },
    { gUnk_09EE16E8, gUnk_09EE170C, gUnk_08B452A4, 4, { 0, 0, 0 } },
    { gUnk_09EE1720, gUnk_09EE173C, gUnk_08B4A9A0, 0, { 0, 0, 0 } },
    { gUnk_09EE1740, gUnk_09EE1768, gUnk_08B4ECCA, 1, { 0, 0, 0 } },
    { gUnk_09EE1740, gUnk_09EE1768, gUnk_08B4ECCA, 0, { 0, 0, 0 } },
    { gUnk_09EE1740, gUnk_09EE1768, gUnk_08B4ECCA, 2, { 0, 0, 0 } },
    { gUnk_09EE1774, gUnk_09EE1794, gUnk_08B54EC0, 0, { 0, 0, 0 } },
    { gUnk_09EEFC38, gUnk_09EEFC60, gUnk_09317A62, 2, { 0, 0, 0 } },
    { gUnk_09EEFC38, gUnk_09EEFC60, gUnk_09317A62, 3, { 0, 0, 0 } },
};

const HumDef gUnk_0813F05C = { 128, 0, gUnk_09618158, 0, { 42, 99, 38, 14, 24, 99, 0 } };

const u8 gUnk_0813F078[8] = {
    0, 4, 4, 6, 8, 10, 8, 6,
};

const char gTaskNameHumHook[] = "task_hum_hook";

const char gTaskNameHumHookMoon[] = "task_hum_hook_moon";

const char gTaskNameHumHookBomb[] = "task_hum_hook_bomb";

const u32 gUnk_0813F0B8[3] = {
    36, 37, 37,
};

const u32 gUnk_0813F0C4[3] = {
    36, 37, 36,
};

const AnimDef gUnk_0813F0D0[7] = {
    { gUnk_09EE17C0, gUnk_09EE17D0, gUnk_08B5B51E, 0, { 0, 0, 0 } },
    { gUnk_09EE17D4, gUnk_09EE17E4, gUnk_08B5CC5E, 0, { 0, 0, 0 } },
    { gUnk_09EE17E8, gUnk_09EE1814, gUnk_08B5E3CA, 0, { 0, 0, 0 } },
    { gUnk_09EE1818, gUnk_09EE1830, gUnk_08B621F8, 0, { 0, 0, 0 } },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 0, { 0, 0, 0 } },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 1, { 0, 0, 0 } },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 2, { 0, 0, 0 } },
};

const AnimDef gUnk_0813F140[10] = {
    { gUnk_09EE1858, gUnk_09EE1878, gUnk_08B67572, 0, { 0, 0, 0 } },
    { gUnk_09EE187C, gUnk_09EE1890, gUnk_08B6C8F2, 0, { 0, 0, 0 } },
    { gUnk_09EE1894, gUnk_09EE18B0, gUnk_08B704A2, 0, { 0, 0, 0 } },
    { gUnk_09EE18B4, gUnk_09EE18D8, gUnk_08B748D0, 0, { 0, 0, 0 } },
    { gUnk_09EE18DC, gUnk_09EE18F8, gUnk_08B7B81C, 1, { 0, 0, 0 } },
    { gUnk_09EE18DC, gUnk_09EE18F8, gUnk_08B7B81C, 0, { 0, 0, 0 } },
    { gUnk_09EE1900, gUnk_09EE191C, gUnk_08B7DF70, 0, { 0, 0, 0 } },
    { gUnk_09EE1920, gUnk_09EE1930, gUnk_08B82F32, 0, { 0, 0, 0 } },
    { gUnk_09EE1920, gUnk_09EE1930, gUnk_08B82F32, 1, { 0, 0, 0 } },
    { gUnk_09EE1920, gUnk_09EE1930, gUnk_08B82F32, 2, { 0, 0, 0 } },
};

const HumSubDef gUnk_0813F1E0 = { gUnk_09618378, 128, 0 };

const HumDef gUnk_0813F1E8 = { 80, 0, gUnk_09618318, 0, { 52, 99, 65, 14, 42, 99, 0 } };

const char gTaskNameHumAnsem[] = "task_hum_ansem";

const u32 gUnk_0813F214[3] = {
    36, 36, 36,
};

const u32 gUnk_0813F220[3] = {
    37, 36, 37,
};

const AnimDef gUnk_0813F22C[10] = {
    { gUnk_09EE193C, gUnk_09EE1950, gUnk_08B85CB4, 0, { 0, 0, 0 } },
    { gUnk_09EE1954, gUnk_09EE1968, gUnk_08B88BD4, 0, { 0, 0, 0 } },
    { gUnk_09EE196C, gUnk_09EE1988, gUnk_08B8BE78, 0, { 0, 0, 0 } },
    { gUnk_09EE198C, gUnk_09EE19C8, gUnk_08B90EDA, 0, { 0, 0, 0 } },
    { gUnk_09EE19F4, gUnk_09EE1A2C, gUnk_08B971A4, 0, { 0, 0, 0 } },
    { gUnk_09EE1A30, gUnk_09EE1A54, gUnk_08B9CCEE, 0, { 0, 0, 0 } },
    { gUnk_09EEF444, gUnk_09EEF474, gUnk_092B03A2, 0, { 0, 0, 0 } },
    { gUnk_09EE1AFC, gUnk_09EE1B28, gUnk_08BA9958, 1, { 0, 0, 0 } },
    { gUnk_09EE1AFC, gUnk_09EE1B28, gUnk_08BA9958, 2, { 0, 0, 0 } },
    { gUnk_09EE1AFC, gUnk_09EE1B28, gUnk_08BA9958, 3, { 0, 0, 0 } },
};

const AnimDef gUnk_0813F2CC[5] = {
    { gUnk_09EE1AE0, gUnk_09EE1AF8, gUnk_08BA6EAE, 0, { 0, 0, 0 } },
    { gUnk_09EE1AC0, gUnk_09EE1ADC, gUnk_08BA4592, 0, { 0, 0, 0 } },
    { gUnk_09EE1A58, gUnk_09EE1AB4, gUnk_08BA17EE, 0, { 0, 0, 0 } },
    { gUnk_09EE1A58, gUnk_09EE1AB4, gUnk_08BA17EE, 1, { 0, 0, 0 } },
    { gUnk_09EE19CC, gUnk_09EE19F0, gUnk_08B95CE2, 0, { 0, 0, 0 } },
};

const HumSubDef gUnk_0813F31C = { gUnk_08F69BA4, 75, 0 };

const HumDef gUnk_0813F324 = {
#ifdef VERSION_EU
        100
#else
        128
#endif
    , 0, gUnk_09617F18, 0, { 44, 99, 90, 14, 52, 99, 4 } };

const char gTaskNameHumHades[] = "task_hum_hades";

const u32 gUnk_0813F350[3] = {
    37, 36, 37,
};

const u32 gUnk_0813F35C[3] = {
    36, 37, 38,
};

const AnimDef gUnk_0813F368[13] = {
    { gUnk_09EE1B84, gUnk_09EE1B94, gUnk_08BB1F72, 0, { 0, 0, 0 } },
    { gUnk_09EE1B98, gUnk_09EE1BA8, gUnk_08BB37EA, 0, { 0, 0, 0 } },
    { gUnk_09EE1BAC, gUnk_09EE1BC0, gUnk_08BB5ABC, 0, { 0, 0, 0 } },
    { gUnk_09EE1BC4, gUnk_09EE1BE4, gUnk_08BB86CC, 0, { 0, 0, 0 } },
    { gUnk_09EE1C50, gUnk_09EE1C68, gUnk_08BC70E8, 0, { 0, 0, 0 } },
    { gUnk_09EE1C50, gUnk_09EE1C68, gUnk_08BC70E8, 1, { 0, 0, 0 } },
    { gUnk_09EE1C50, gUnk_09EE1C68, gUnk_08BC70E8, 2, { 0, 0, 0 } },
    { gUnk_09EE1BC4, gUnk_09EE1BE4, gUnk_08BB86CC, 1, { 0, 0, 0 } },
    { gUnk_09EE1C24, gUnk_09EE1C4C, gUnk_08BC2318, 0, { 0, 0, 0 } },
    { gUnk_09EE1BF8, gUnk_09EE1C20, gUnk_08BBD3CA, 0, { 0, 0, 0 } },
    { gUnk_09EE1BC4, gUnk_09EE1BE4, gUnk_08BB86CC, 2, { 0, 0, 0 } },
    { gUnk_09EE1BC4, gUnk_09EE1BE4, gUnk_08BB86CC, 3, { 0, 0, 0 } },
    { gUnk_09EE1BC4, gUnk_09EE1BE4, gUnk_08BB86CC, 4, { 0, 0, 0 } },
};

const AnimDef gUnk_0813F438 = { gUnk_09EE1C74, gUnk_09EE1C90, gUnk_08BCA01C, 0, { 0, 0, 0 } };

const HumSubDef gUnk_0813F448 = { gUnk_08F6DC84, 90, 0 };

const HumDef gUnk_0813F450 = { 90, 0, gUnk_09618438, 0, { 51, 99, 60, 14, 40, 99, 0 } };

const char gTaskNameHumMahluxia[] = "task_hum_mahluxia";

const u32 gUnk_0813F480[2][3] = {
    { 36, 38, 38 },
    { 37, 37, 36 },
};

const AnimDef gUnk_0813F498[15] = {
    { gUnk_09EE1CBC, gUnk_09EE1CD0, gUnk_08BCB542, 0, { 0, 0, 0 } },
    { gUnk_09EE1CD4, gUnk_09EE1CE8, gUnk_08BCCC34, 0, { 0, 0, 0 } },
    { gUnk_09EE1CD4, gUnk_09EE1CE8, gUnk_08BCCC34, 1, { 0, 0, 0 } },
    { gUnk_09EE1CF0, gUnk_09EE1D00, gUnk_08BCE468, 0, { 0, 0, 0 } },
    { gUnk_09EE1D04, gUnk_09EE1D38, gUnk_08BCFC2A, 1, { 0, 0, 0 } },
    { gUnk_09EE1D04, gUnk_09EE1D38, gUnk_08BCFC2A, 2, { 0, 0, 0 } },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 0, { 0, 0, 0 } },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 1, { 0, 0, 0 } },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 2, { 0, 0, 0 } },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 3, { 0, 0, 0 } },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 4, { 0, 0, 0 } },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 5, { 0, 0, 0 } },
    { gUnk_09EE1DBC, gUnk_09EE1DDC, gUnk_08BD9D9C, 0, { 0, 0, 0 } },
    { gUnk_09EE1D04, gUnk_09EE1D38, gUnk_08BCFC2A, 3, { 0, 0, 0 } },
    { gUnk_09EE1D04, gUnk_09EE1D38, gUnk_08BCFC2A, 4, { 0, 0, 0 } },
};

const HumDef gUnk_0813F588 = { 128, 0, gUnk_09618458, 0, { 49, 99, 60, 14, 46, 99, 0 } };

const char gTaskNameHumLaxene[] = "task_hum_laxene";

const char gTaskNameHumLaxeneKnf[] = "task_hum_laxene_knf";

const u32 gUnk_0813F5C8[2][3] = {
    { 36, 36, 36 },
    { 36, 37, 36 },
};

const AnimDef gUnk_0813F5E0[14] = {
    { gUnk_09EE1DE0, gUnk_09EE1DF8, gUnk_08BDC7B6, 0, { 0, 0, 0 } },
    { gUnk_09EE1DFC, gUnk_09EE1E0C, gUnk_08BDF086, 0, { 0, 0, 0 } },
    { gUnk_09EE1E10, gUnk_09EE1E24, gUnk_08BE1504, 0, { 0, 0, 0 } },
    { gUnk_09EE1E28, gUnk_09EE1E50, gUnk_08BE412A, 1, { 0, 0, 0 } },
    { gUnk_09EE1E28, gUnk_09EE1E50, gUnk_08BE412A, 2, { 0, 0, 0 } },
    { gUnk_09EE1E64, gUnk_09EE1E74, gUnk_08BE95F8, 0, { 0, 0, 0 } },
    { gUnk_09EE1E64, gUnk_09EE1E74, gUnk_08BE95F8, 1, { 0, 0, 0 } },
    { gUnk_09EE1E64, gUnk_09EE1E74, gUnk_08BE95F8, 2, { 0, 0, 0 } },
    { gUnk_09EE1EB0, gUnk_09EE1EE8, gUnk_08BEEBAA, 0, { 0, 0, 0 } },
    { gUnk_09EE1EB0, gUnk_09EE1EE8, gUnk_08BEEBAA, 1, { 0, 0, 0 } },
    { gUnk_09EE1EB0, gUnk_09EE1EE8, gUnk_08BEEBAA, 2, { 0, 0, 0 } },
    { gUnk_09EE1E80, gUnk_09EE1EA4, gUnk_08BEB9A0, 0, { 0, 0, 0 } },
    { gUnk_09EE1E80, gUnk_09EE1EA4, gUnk_08BEB9A0, 1, { 0, 0, 0 } },
    { gUnk_09EE1E80, gUnk_09EE1EA4, gUnk_08BEB9A0, 2, { 0, 0, 0 } },
};

const AnimDef gUnk_0813F6C0[10] = {
    { gUnk_09EE1FCC, gUnk_09EE1FD8, gUnk_08BF76FE, 0, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 0, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 1, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 2, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 7, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 3, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 4, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 5, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 8, { 0, 0, 0 } },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 6, { 0, 0, 0 } },
};

const HumSubDef gUnk_0813F760 = { gUnk_08F69BA4, 64, 0 };

const HumDef gUnk_0813F768 = {
#ifdef VERSION_EU
        102
#else
        128
#endif
    , 0, gUnk_096180F8, 0, { 48, 99, 60, 14, 32, 99, 0 } };

const char gTaskNameHumAxcel[] = "task_hum_axcel";

const char gTaskNameHumAxcelPtc[] = "task_hum_axcel_ptc";

const u32 gUnk_0813F7A8[3] = {
    36, 37, 36,
};

const u32 gUnk_0813F7B4[3] = {
    37, 36, 36,
};

const u32 gUnk_0813F7C0[3] = {
    36, 36, 37,
};

const u32 gUnk_0813F7CC[3] = {
    36, 36, 36,
};

const AnimDef gUnk_0813F7D8[15] = {
    { gUnk_09EE1FDC, gUnk_09EE1FEC, gUnk_08BF7A1A, 0, { 0, 0, 0 } },
    { gUnk_09EE1FF0, gUnk_09EE1FFC, gUnk_08BF97D4, 0, { 0, 0, 0 } },
    { gUnk_09EE2000, gUnk_09EE2010, gUnk_08BFB696, 0, { 0, 0, 0 } },
    { gUnk_09EE2014, gUnk_09EE2030, gUnk_08BFD4A2, 0, { 0, 0, 0 } },
    { gUnk_09EE2054, gUnk_09EE2070, gUnk_08C0319C, 0, { 0, 0, 0 } },
    { gUnk_09EE2074, gUnk_09EE2088, gUnk_08C067EC, 0, { 0, 0, 0 } },
    { gUnk_09EE2074, gUnk_09EE2088, gUnk_08C067EC, 2, { 0, 0, 0 } },
    { gUnk_09EE2074, gUnk_09EE2088, gUnk_08C067EC, 3, { 0, 0, 0 } },
    { gUnk_09EE20B4, gUnk_09EE20E4, gUnk_08C0B5EE, 0, { 0, 0, 0 } },
    { gUnk_09EE2034, gUnk_09EE2048, gUnk_08C00AB6, 0, { 0, 0, 0 } },
    { gUnk_09EE2034, gUnk_09EE2048, gUnk_08C00AB6, 1, { 0, 0, 0 } },
    { gUnk_09EE2034, gUnk_09EE2048, gUnk_08C00AB6, 2, { 0, 0, 0 } },
    { gUnk_09EE2098, gUnk_09EE20A8, gUnk_08C08E48, 0, { 0, 0, 0 } },
    { gUnk_09EE2098, gUnk_09EE20A8, gUnk_08C08E48, 1, { 0, 0, 0 } },
    { gUnk_09EE2098, gUnk_09EE20A8, gUnk_08C08E48, 2, { 0, 0, 0 } },
};

const HumDef gUnk_0813F8C8 = { 83, 0, gUnk_096183B8, 0, { 50, 99, 80, 14, 48, 99, 0 } };

const char gTaskNameHumVixen[] = "task_hum_vixen";

const char gTaskNameHumVixenNdl[] = "task_hum_vixen_ndl";

const char gTaskNameHumVixenIce[] = "task_hum_vixen_ice";

const AnimDef gUnk_0813F91C[13] = {
    { gUnk_09EE20E8, gUnk_09EE2110, gUnk_08C10A58, 0, { 0, 0, 0 } },
    { gUnk_09EE20E8, gUnk_09EE2110, gUnk_08C10A58, 1, { 0, 0, 0 } },
    { gUnk_09EE2120, gUnk_09EE2138, gUnk_08C1516A, 0, { 0, 0, 0 } },
    { gUnk_09EE20E8, gUnk_09EE2110, gUnk_08C10A58, 2, { 0, 0, 0 } },
    { gUnk_09EE2120, gUnk_09EE2138, gUnk_08C1516A, 1, { 0, 0, 0 } },
    { gUnk_09EE20E8, gUnk_09EE2110, gUnk_08C10A58, 3, { 0, 0, 0 } },
    { gUnk_09EE2120, gUnk_09EE2138, gUnk_08C1516A, 2, { 0, 0, 0 } },
    { gUnk_09EE2144, gUnk_09EE215C, gUnk_08C1837E, 0, { 0, 0, 0 } },
    { gUnk_09EE2144, gUnk_09EE215C, gUnk_08C1837E, 1, { 0, 0, 0 } },
    { gUnk_09EE2144, gUnk_09EE215C, gUnk_08C1837E, 2, { 0, 0, 0 } },
    { gUnk_09EE2168, gUnk_09EE2180, gUnk_08C1B592, 0, { 0, 0, 0 } },
    { gUnk_09EE2168, gUnk_09EE2180, gUnk_08C1B592, 1, { 0, 0, 0 } },
    { gUnk_09EE2168, gUnk_09EE2180, gUnk_08C1B592, 2, { 0, 0, 0 } },
};

const char gTaskNameHumVixenFrz[] = "task_hum_vixen_frz";

const VixenFrgDef gVixenFrgDefs[15] = {
    { 12, -29, 3, 0 },
    { 5, -37, 0, 0 },
    { -16, -24, 3, 2 },
    { -18, -6, 0, 1 },
    { 14, -4, 5, 0 },
    { 17, -5, 4, 0 },
    { -12, -44, 5, 1 },
    { -16, -40, 2, 0 },
    { 8, 0, 1, 0 },
    { 0, -13, 2, 2 },
    { -4, -24, 5, 0 },
    { 8, -12, 5, 0 },
    { 4, -48, 5, 3 },
    { -7, -39, 4, 1 },
    { 3, -54, 1, 1 },
};

const char gTaskNameHumVixenFrg[] = "task_hum_vixen_frg";

const u32 gUnk_0813FA8C[3] = {
    36, 37, 36,
};

const AnimDef gUnk_0813FA98[10] = {
    { gUnk_09EE21BC, gUnk_09EE21DC, gUnk_08C1ED72, 0, { 0, 0, 0 } },
    { gUnk_09EE21E0, gUnk_09EE21EC, gUnk_08C238AC, 0, { 0, 0, 0 } },
    { gUnk_09EE21F0, gUnk_09EE2200, gUnk_08C25516, 0, { 0, 0, 0 } },
    { gUnk_09EE2204, gUnk_09EE2224, gUnk_08C27FBE, 0, { 0, 0, 0 } },
    { gUnk_09EE222C, gUnk_09EE2248, gUnk_08C2D1B6, 1, { 0, 0, 0 } },
    { gUnk_09EE2250, gUnk_09EE2288, gUnk_08C3151E, 0, { 0, 0, 0 } },
    { gUnk_09EE2250, gUnk_09EE2288, gUnk_08C3151E, 1, { 0, 0, 0 } },
    { gUnk_09EE22B4, gUnk_09EE22D8, gUnk_08C3866C, 0, { 0, 0, 0 } },
    { gUnk_09EE22B4, gUnk_09EE22D8, gUnk_08C3866C, 1, { 0, 0, 0 } },
    { gUnk_09EE22E0, gUnk_09EE2308, gUnk_08C3D7E6, 0, { 0, 0, 0 } },
};

const HumDef gUnk_0813FB38 = { 128, 0, gUnk_09618478, 0, { 53, 99, 70, 24, 52, 99, 4 } };

const char gTaskNameHumLexceus[] = "task_hum_lexceus";

const char gTaskNameHumLexTmh[] = "task_hum_lex_tmh";

const char gTaskNameHumLexTmh0[] = "task_hum_lex_tmh0";

const char gTaskNameHumLexRock[] = "task_hum_lex_rock";

const char gTaskNameHumMahluxiaFlw[] = "task_hum_mahluxia_flw";

const u32 gUnk_0813FBBC[2][3] = {
    { 36, 36, 38 },
    { 37, 37, 39 },
};

const AnimDef gUnk_0813FBD4[21] = {
    { gUnk_09EE23B8, gUnk_09EE23D0, gUnk_08C492E2, 0, { 0, 0, 0 } },
    { gUnk_09EE23D8, gUnk_09EE23F8, gUnk_08C4AEA0, 0, { 0, 0, 0 } },
    { gUnk_09EE23FC, gUnk_09EE2410, gUnk_08C4D30E, 0, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 0, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 1, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 2, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 3, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 4, { 0, 0, 0 } },
    { gUnk_09EE2458, gUnk_09EE2480, gUnk_08C51312, 0, { 0, 0, 0 } },
    { gUnk_09EE2490, gUnk_09EE24C0, gUnk_08C5411E, 0, { 0, 0, 0 } },
    { gUnk_09EE24C8, gUnk_09EE24E4, gUnk_08C579A4, 0, { 0, 0, 0 } },
    { gUnk_09EE24EC, gUnk_09EE2518, gUnk_08C5997A, 0, { 0, 0, 0 } },
    { gUnk_09EE24EC, gUnk_09EE2518, gUnk_08C5997A, 2, { 0, 0, 0 } },
    { gUnk_09EE25A8, gUnk_09EE25CC, gUnk_08C63E3C, 0, { 0, 0, 0 } },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 0, { 0, 0, 0 } },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 1, { 0, 0, 0 } },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 2, { 0, 0, 0 } },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 0, { 0, 0, 0 } },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 1, { 0, 0, 0 } },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 2, { 0, 0, 0 } },
    { gUnk_09EE2584, gUnk_09EE25A4, gUnk_08C61980, 0, { 0, 0, 0 } },
};

const HumDef gUnk_0813FD24 = { 64, 0, gUnk_09618338, 0, { 45, 99, 38, 14, 24, 99, 0 } };

const HumSubDef gUnk_0813FD40 = { gUnk_09618338, 64, 0 };

const char gTaskNameHumRiku[] = "task_hum_riku";

const AnimDef gUnk_0813FD58[5] = {
    { gUnk_09EF01F0, gUnk_09EF01F8, gUnk_0934B7EC, 0, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 0, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 3, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 1, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 2, { 0, 0, 0 } },
};

const HumDef gUnk_0813FDA8 = { 128, 0, gUnk_09618258, 0, { 41, 99, 64, 14, 40, 99, 0 } };

const char gTaskNameHumLeon[] = "task_hum_leon";

const AnimDef gUnk_0813FDD4[2] = {
    { gUnk_09EEE36C, gUnk_09EEE3BC, gUnk_091C37E0, 5, { 0, 0, 0 } },
    { gUnk_09EE25F4, gUnk_09EE2604, gUnk_08C67F86, 0, { 0, 0, 0 } },
};

const HumDef gUnk_0813FDF4 = { 128, 0, gUnk_09617C78, 0, { 51, 99, 64, 14, 32, 99, 0 } };

const char gTaskNameHumRobe[] = "task_hum_robe";

void task_hum_cloud_0(CloudWork* work, void* obj) {
    HumInit(&work->base, &gUnk_0813EF28);
    work->unk_188 = 0;
    work->base.unk_184 = gUnk_0813EDD0[0];
}

u8 task_hum_cloud_1(CloudWork* work) {
    CloudWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    u8 ret;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, &z);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        switch ((u32)_0800F84C(work)) {
        case 36:
        case 38:
            if (act->z < 0) {
                work->base.unk_170 = 21;
            } else {
                work->base.unk_170 = 19;
            }
            break;
        case 37:
        case 39:
            if (act->z < 0) {
                work->base.unk_170 = 21;
            } else {
                work->base.unk_170 = 20;
            }
            break;
        case 0xEB3ACEB3:
            work->base.unk_170 = 31;
            break;
        case 0xEB3AA6B3:
            work->base.unk_170 = 28;
            break;
        }
        break;
    case 4:
        work->unk_190 = 0;
        break;
    }
    if (func_0800F5A4(&work->base, 8, 32, 32, 24)) {
        if ((u16)GetRandom() % 2) {
            work->base.unk_184 = gUnk_0813EDD0[0];
        } else {
            work->base.unk_184 = gUnk_0813EDD0[1];
        }
    }
    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813EDE8, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17: {
        func_08019068(gUnk_0813EDE8, &w->base.anim, 0, 3, w->base.tiles);
        if (gBtlWork->flags & 0x20000000) {
            if ((u8)func_08049F50((struct PcCharaWork*)w)) {
                break;
            }
        }
        if ((act->x - x >= 0) ? act->x - x <= 0x4FFF : x - act->x <= 0x4FFF) {
            if (x <= 0xFFFF) {
                func_08049F24((struct PcCharaWork*)w, (gBtlWork->unk_0DC - 40) << 8,
                    (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            } else {
                func_08049F24((struct PcCharaWork*)w, (gBtlWork->unk_0DA + 40) << 8,
                    (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            }
        }
        break;
    }
    case 0:
        func_08019068(gUnk_0813EDE8, &w->base.anim, 0, 3, w->base.tiles);
        if (func_08081828()) {
            break;
        }
        if ((u16)((u16)GetRandom() % 60) == 0) {
            work->base.unk_170 = 8;
            work->base.unk_150 = 0;
            break;
        }
        if (func_0800F4C8(work, 40)) {
            func_08049F24((struct PcCharaWork*)w, 0x10000,
                (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            break;
        }
        if (gBtlWork->flags & 0x20000000) {
            if ((u8)func_08049F50((struct PcCharaWork*)w)) {
                break;
            }
        } else {
            func_0800F368(work, 30);
        }
        work->base.unk_150++;
        break;
    case 8: {
        func_08019068(gUnk_0813EDE8, &w->base.anim, 1, 3, w->base.tiles);
        work->base.targetX = x;
        work->base.targetY = y;
        if (func_0800F3BC(&work->base, work->base.targetX, y, 0x133)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        if ((u16)((u16)GetRandom() % 150) == 0) {
            if ((act->x - x >= 0) ? act->x - x > 70 : x - act->x > 70) {
                func_08049EE4((struct PcCharaWork*)w, x, y);
                break;
            }
        }
        if (gBtlWork->flags & 0x20000000) {
            if ((u8)func_08049F50((struct PcCharaWork*)w)) {
                break;
            }
        } else {
            func_0800F368(work, 30);
        }
        work->base.unk_150++;
        break;
    }
    case 1:
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813EDE8, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813EDE8, &w->base.anim, 8, 0, w->base.tiles);
            m4aSongNumStart(267);
            func_08019A30();
        }
        if (AnimGetFrame(&work->base.anim) == 6) {
            if ((act->flags & 4)
                ? func_08011F78(0x11A, act->x - 9216, act->y, act->z, 24, 16, 50)
                : func_08011F78(0x11A, act->x + 9216, act->y, act->z, 24, 16, 50)) {
                m4aSongNumStart(523);
            }
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 20:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813EDE8, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(268);
            func_08019A30();
        }
        if (AnimGetFrame(&work->base.anim) == 6) {
            if ((act->flags & 4)
                ? func_08011F78(0x11A, act->x - 8192, act->y, act->z, 22, 16, 50)
                : func_08011F78(0x11A, act->x + 8192, act->y, act->z, 22, 16, 50)) {
                m4aSongNumStart(524);
            }
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 3, 0, w->base.tiles);
        }
        if ((s16)work->base.unk_150 > 3) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 26;
            work->base.unk_158 = w->unk_188;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26: {
        s32 d;

        act->x += ((s32)work->base.targetX - act->x) >> 4;
        act->y += ((s32)work->base.targetY - act->y) >> 4;
        d = work->base.unk_158;
        if (d < 0) {
            if (d <= -0x200) {
                func_08019068(gUnk_0813EDE8, &w->base.anim, 4, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813EDE8, &w->base.anim, 5, 0, w->base.tiles);
            }
        } else if (d <= 0x1FF) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 5, 0, w->base.tiles);
        } else {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 6, 0, w->base.tiles);
        }
        if (act->z >= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 27;
        } else {
            func_0800F368(work, 1);
            work->base.unk_150++;
        }
        break;
    }
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 7, 0, w->base.tiles);
        }
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = w->unk_190;
        } else {
            work->base.unk_150++;
        }
        break;
    case 33: {
        s32 d;

        if ((s16)work->base.unk_150 == 0) {
            work->base.unk_158 = -0x500;
        }
        d = work->base.unk_158;
        if (d < 0) {
            if (d > -0x200) {
                func_08019068(gUnk_0813EDE8, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813EDE8, &w->base.anim, 4, 0, w->base.tiles);
            }
        }
        if ((s32)work->base.unk_158 > 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 34;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 34: {
        s32 d;

        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 14, 0, w->base.tiles);
            w->unk_188 = 0;
            work->base.targetZ = act->z;
        }
        ret = func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, w->unk_188);
        if (ret) {
            work->base.unk_170 = 26;
            w->unk_190 = 0;
            work->base.unk_150 = 0;
        } else {
            w->unk_188 += 76;
            if ((s32)w->unk_188 > 0x800) {
                w->unk_188 = 0x800;
            }
            d = ((s32)work->base.targetX - act->x) >> 3;
            if (d < 0) {
                d = -d;
            }
            if (d < (s32)w->unk_188) {
                w->unk_188 = d;
            }
            {
                s32 v = work->base.targetZ + gSineTable[(gFrameCounter * 4) & 0xFF] * 12;
            work->base.unk_158 = 0;
            act->z += (v - act->z) >> 3;
            }
            if (act->x < (s32)work->base.targetX) {
                act->flags &= ~4;
            } else {
                act->flags |= 4;
            }
            work->base.unk_150++;
        }
        break;
    }
    case 21: {
        s32 d;

        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813EDE8, &w->base.anim, 10, 0, w->base.tiles);
        }
        act->z += (gSineTable[gFrameCounter % 256] * 10 - (d = act->z + 0x2C00)) >> 3;
        if (act->x < x) {
            s32 d = act->x + 0x2100;
            act->x += (x - d) >> 3;
        } else {
            s32 d = act->x - 0x2100;
            act->x += (x - d) >> 3;
        }
        act->y += (y - act->y) >> 4;
        work->base.unk_158 = 0;
        if ((s16)work->base.unk_150 > 30) {
            work->base.unk_170 = 22;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 11, 0, w->base.tiles);
        }
        work->base.unk_158 = 0;
        if ((s16)work->base.unk_150 > 8) {
            work->base.unk_158 = 0x500;
            work->base.unk_170 = 23;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 12, 0, w->base.tiles);
        }
        if (act->z >= 0) {
            work->base.unk_170 = 24;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 13, 0, w->base.tiles);
        }
        if ((act->flags & 4)
            ? func_08011F78(0x11A, act->x - 0x2000, act->y, act->z, 22, 16, 30)
            : func_08011F78(0x11A, act->x + 0x2000, act->y, act->z, 22, 16, 30)) {
            m4aSongNumStart(0x20D);
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 31:
        if (act->z >= act->unk_010) {
            s32 v;
            work->base.targetX = x + (v = ((u16)((u16)GetRandom() % 41) << 8) - 0x1400);
            work->base.targetY = y;
            work->base.unk_170 = 25;
            work->base.unk_150 = 0;
            w->unk_188 = -0x500;
            w->unk_190 = 32;
        }
        break;
    case 32: {
        s32 d;
        if ((s16)work->base.unk_150 == 0) {
            w->unk_18E = 0;
            func_08019068(gUnk_0813EDE8, &w->base.anim, 18, 0, w->base.tiles);
        } else if ((s16)w->unk_18E == 0 && AnimIsFinished(&work->base.anim)) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 19, 0, w->base.tiles);
            w->unk_18E++;
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            w->unk_190 = 0;
            work->base.unk_150 = 0;
            break;
        }
        func_0800F368(work, 1);
        if (work->base.anim.timer == 0) {
            if ((s16)w->unk_18E == 0) {
                switch (AnimGetFrame(&work->base.anim)) {
                case 2:
                    m4aSongNumStart(0x10B);
                    break;
                case 6:
                    if ((act->flags & 4)
                        ? func_08011F78(0x11B, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : func_08011F78(0x11B, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(0x20B);
                        FadeStartIn(2, 20);
                        if (act->flags & 4) {
                            func_08019050(6, 0x133, act->x - 0x2000, (d = act->z - 0x1800, act->y + d));
                        } else {
                            func_08019050(6, 0x133, act->x + 0x2000, (d = act->z - 0x1800, act->y + d));
                        }
                    }
                    break;
                case 7:
                    func_08019050(6, 0x100, gBtlWork->x2, gBtlWork->y2);
                    break;
                case 9:
                    m4aSongNumStart(0x10C);
                    break;
                }
            } else {
                switch (AnimGetFrame(&work->base.anim)) {
                case 0:
                    func_08019A30();
                    if ((act->flags & 4)
                        ? func_08011F78(0x11B, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : func_08011F78(0x11B, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(0x20C);
                        FadeStartIn(2, 20);
                        if (act->flags & 4) {
                            func_08019050(6, 0x133, act->x - 0x2000, (d = act->z - 0x1800, act->y + d));
                        } else {
                            func_08019050(6, 0x133, act->x + 0x2000, (d = act->z - 0x1800, act->y + d));
                        }
                    }
                    break;
                case 1:
                    func_08019050(6, 0x100, gBtlWork->x2, gBtlWork->y2);
                    break;
                case 4:
                    m4aSongNumStart(0x10D);
                    break;
                case 5:
                    func_08019A30();
                    if ((act->flags & 4)
                        ? func_08011F78(0x11C, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : func_08011F78(0x11C, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(0x20D);
                        FadeStartIn(2, 50);
                        if (act->flags & 4) {
                            func_08019050(6, 0x200, act->x - 0x2000, (d = act->z - 0x1800, act->y + d));
                        } else {
                            func_08019050(6, 0x200, act->x + 0x2000, (d = act->z - 0x1800, act->y + d));
                        }
                    }
                    break;
                case 6:
                    func_08019050(6, 0x100, gBtlWork->x2, gBtlWork->y2);
                    break;
                }
            }
        }
        work->base.unk_150++;
        break;
    }
    case 28: {
        s32 d;

        if ((s16)work->base.unk_150 == 0) {
            work->base.unk_158 = -0x500;
        }
        d = work->base.unk_158;
        if (d < 0) {
            if (d > -0x200) {
                func_08019068(gUnk_0813EDE8, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813EDE8, &w->base.anim, 4, 0, w->base.tiles);
            }
        }
        if ((s32)work->base.unk_158 > 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 29;
            w->state = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 29: {
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EDE8, &w->base.anim, 14, 0, w->base.tiles);
            w->unk_188 = 0;
            if (act->flags & 4) {
                work->base.targetX = (gBtlWork->unk_0DA + 50) << 8;
            } else {
                work->base.targetX = (gBtlWork->unk_0DC - 50) << 8;
            }
            work->base.targetY = act->y;
            work->base.targetZ = -0xC800;
        }
        work->base.unk_158 = 0;
        act->x += ((s32)work->base.targetX - act->x) >> 4;
        act->y += ((s32)work->base.targetY - act->y) >> 4;
        {
            s32 v;
        v = ((s32)work->base.targetZ - act->z) >> 3;
        if (v > (s32)w->unk_188) {
            v = w->unk_188;
        }
        if (v < -(s32)w->unk_188) {
            v = -w->unk_188;
        }
        act->z += v;
        }
        w->unk_188 += 0x80;
        if ((act->z - (s32)work->base.targetZ >= 0) ? act->z - (s32)work->base.targetZ <= 0xFFF : (s32)work->base.targetZ - act->z <= 0xFFF) {
            work->base.unk_170 = 30;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 30:
        if ((s16)work->base.unk_150 == 0) {
            work->base.targetX = x;
            work->base.targetY = y;
            work->base.targetZ = z - 0x1000;
            func_08019A30();
            switch ((s16)w->state) {
            case 0:
                m4aSongNumStart(0x10B);
                func_08019068(gUnk_0813EDE8, &w->base.anim, 15, 0, w->base.tiles);
                break;
            case 1:
                m4aSongNumStart(0x10C);
                func_08019068(gUnk_0813EDE8, &w->base.anim, 16, 0, w->base.tiles);
                break;
            case 2:
            default:
                m4aSongNumStart(0x10D);
                func_08019068(gUnk_0813EDE8, &w->base.anim, 17, 0, w->base.tiles);
                break;
            }
            if (act->x < (s32)work->base.targetX) {
                act->flags &= ~4;
            } else {
                act->flags |= 4;
            }
        }
        work->base.unk_158 = 0;
        act->x += ((s32)work->base.targetX - act->x) >> 3;
        act->y += ((s32)work->base.targetY - act->y) >> 3;
        act->z += ((s32)work->base.targetZ - act->z) >> 3;
        if (work->base.anim.timer == 0) {
            switch ((s16)w->state) {
            case 0:
                if (AnimGetFrame(&work->base.anim) == 4) {
                    if ((act->flags & 4)
                        ? func_08011F78(0x11D, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : func_08011F78(0x11D, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(0x20B);
                        FadeStartIn(2, 20);
                    }
                }
                break;
            case 1:
                if (AnimGetFrame(&work->base.anim) == 3) {
                    func_08019A30();
                    if ((act->flags & 4)
                        ? func_08011F78(0x11D, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : func_08011F78(0x11D, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(0x20C);
                        FadeStartIn(2, 20);
                    }
                }
                break;
            case 2:
            default:
                if (AnimGetFrame(&work->base.anim) == 3) {
                    func_08019A30();
                    if ((act->flags & 4)
                        ? func_08011F78(0x11D, act->x - 0x2800, act->y, act->z, 24, 24, 48)
                        : func_08011F78(0x11D, act->x + 0x2800, act->y, act->z, 24, 24, 48)) {
                        m4aSongNumStart(0x20D);
                        FadeStartIn(2, 20);
                    }
                }
                break;
            }
        }
        if ((s16)work->base.unk_150 > 23 && AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            w->state++;
            if ((s16)w->state > 2) {
                func_0801AF08(act);
                work->base.unk_170 = 26;
                w->unk_190 = 0;
            } else {
                work->base.unk_170 = 29;
            }
        } else {
            work->base.unk_150++;
        }
        break;
    }
    return func_0800E5F0(&work->base);
}

void task_hum_cloud_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_cloud_3(HumWork* work) {
    HumReleaseResources(work);
}

void func_0804B44C(CloudWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    BtlObj* act = &w->actor;

    if (act->flags & 4) {
        work->base.targetX = act->x - (a << 8);
    } else {
        work->base.targetX = act->x + (a << 8);
    }
    w->targetY = act->y;
    w->unk_170 = 0x16;
    w->unk_150 = 0;
    work->unk_188 = -b;
}

void func_0804B4BC(CloudWork* work, s32 a, s32 b) {
    work->base.targetX = a;
    work->base.targetY = b;
    work->base.unk_170 = 0x16;
    work->base.unk_150 = 0;
    work->unk_188 = -0x680;
}

u8 func_0804B4F4(CloudWork* work) {
    s32 x;
    s32 y;
    BtlObj* c;

    c = gBtlWork->actor;
    func_0801C700(&work->base.actor, &x, &y, 0);
    func_0800F368(work, 1);

    if (func_0800F504(work, 0x100, 0x100, 0x100)) {
        if (gBtlWork->flags & 0x8000) {
            func_0804B44C(work, -99, 0x280);
        } else if (GetRandom() & 1) {
            if (c->flags & 4) {
                func_0804B4BC(work, x + 0x2800, y);
            } else {
                func_0804B4BC(work, x - 0x2800, y);
            }
        } else {
            func_0804B44C(work, -80, 0x500);
        }
        return 1;
    }
    return 0;
}

void task_hum_hook_0(HookWork* work, void* arg) {
    TaskCreate(&gBtlWork->taskPools[0], &gTaskDescHumHookMoon, 0);
    HumInit(&work->base, &gUnk_0813F05C);
    work->base.actor.flags |= 0x10000000;

    if (GetRandom() % 2) {
        work->base.unk_184 = gUnk_0813EF54;
    } else {
        work->base.unk_184 = gUnk_0813EF60;
    }
    work->base.flags |= 0x40;
    work->unk_188 = 0;
    work->unk_18C = 0;
    work->unk_190 = 0;
    work->angle = 0;
    work->unk_196 = 0;
    work->flags = 0;
    TaskPoolInit(&work->tasks, 3);
}

u8 task_hum_hook_1(HookWork* work) {
    HookWork* w;
    BtlObj* act;
    BtlObj* c;
    VixenNdlArgs args;
    s32 x;
    s32 y;
    s32 z;
    u16 f;
    u8 a;

    w = work;
    act = &work->base.actor;
    c = gBtlWork->actor;
    func_0801C700(act, &x, &y, &z);

    if (_0800E434(work) == 5) {
        work->base.unk_150 = 0;

        switch ((u32)_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 20;
            break;
        case 37:
            work->base.unk_170 = 21;
            break;
        case 38:
            work->base.unk_170 = 19;
            break;
        case 39:
            work->base.unk_170 = 25;
            break;
        case 0xED1AF6BD:
            work->base.unk_170 = 26;
            break;
        case 0xED1B1EC7:
            work->base.unk_170 = 29;
            work->base.unk_152 = 0;
            break;
        }
    }

    if (func_0800F5A4(work, 13, 40, 40, 24)) {
        if (GetRandom() % 2) {
            w->base.unk_184 = gUnk_0813EF54;
        } else {
            w->base.unk_184 = gUnk_0813EF60;
        }
    }

    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17: {
        s32 d;

        func_08019068(gUnk_0813EF6C, &w->base.anim, 0, 3, w->base.tiles);

        if (gBtlWork->flags & 0x20000000) {
            if (func_0804B4F4((CloudWork*)w)) {
                break;
            }
        }
        d = act->x - x;

        if ((d >= 0) ? d <= 0x3FFF : (d = x - act->x) <= 0x3FFF) {
            if (x <= 0xFFFF) {
                func_0804B4BC((CloudWork*)w, (gBtlWork->unk_0DC - 40) << 8,
                    (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            } else {
                func_0804B4BC((CloudWork*)w, (gBtlWork->unk_0DA + 40) << 8,
                    (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            }
        }
        break;
    }
    case 0:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 0, 3, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if (GetRandom() % 150 == 0) {
            work->base.unk_170 = 8;
            work->base.unk_150 = 0;
            break;
        }

        if (func_0800F4C8(work, 40)) {
            func_0804B4BC((CloudWork*)w, 0x10000,
                (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            break;
        }

        if (gBtlWork->flags & 0x20000000) {
            if (func_0804B4F4((CloudWork*)w)) {
                break;
            }
        } else {
            func_0800F368(work, 8);
        }
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 1, 3, w->base.tiles);
        work->base.targetX = x;
        work->base.targetY = y;

        if (func_0800F3BC(work, work->base.targetX, y, 358)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }

        if (gBtlWork->flags & 0x20000000) {
            if (func_0804B4F4((CloudWork*)w)) {
                break;
            }
        } else {
            func_0800F368(work, 8);
        }
        work->base.unk_150++;
        break;
    case 3:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 2, 0, w->base.tiles);
        gBtlWork->unk_018 = 0;
        break;
    case 1:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 2:
        if (func_08081828() == 0) {
            break;
        }

        if (GetRandom() % 10 != 0) {
            break;
        }

        if (x <= 0xFFFF) {
            work->base.targetX = (gBtlWork->unk_0DC - 40) << 8;
        } else {
            work->base.targetX = (gBtlWork->unk_0DA + 40) << 8;
        }
        work->base.targetY = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
        work->base.unk_170 = 23;
        work->base.unk_150 = 0;
        work->base.unk_158 = -0x680;
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 11, 1, w->base.tiles);
        }
        func_0802F284(act->x, act->y, act->z);
        func_0800F368(work, 1);

        if (act->flags & 4) {
            s32 d = act->x - 0x1000;
            act->x += (x - d) >> 4;
        } else {
            s32 d = act->x + 0x1000;
            act->x += (x - d) >> 4;
        }
        act->y += (y - act->y) >> 4;

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 2:
            case 4:
            case 7:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(280, act->x - 0x1400, act->y, act->z, 20, 20, 50)
                    : func_08011F78(280, act->x + 0x1400, act->y, act->z, 20, 20, 50)) {
                    m4aSongNumStart(0x22E);
                }
                break;
            }
        }

        if ((s16)work->base.unk_150 > 120) {
            work->base.unk_170 = 27;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 27:
        func_0802F284(act->x, act->y, act->z);

        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 9, 0, w->base.tiles);
        }
        func_0800F368(work, 1);

        if (act->flags & 4) {
            s32 d = act->x - 0x1000;
            act->x += (x - d) >> 4;
        } else {
            s32 d = act->x + 0x1000;
            act->x += (x - d) >> 4;
        }
        act->y += (y - act->y) >> 4;

        if (work->base.anim.timer == 0 && AnimGetFrame(&work->base.anim) == 3) {
            func_08019A30();

            if ((act->flags & 4)
                ? func_08011F78(0x119, act->x - 0x1400, act->y, act->z, 20, 20, 50)
                : func_08011F78(0x119, act->x + 0x1400, act->y, act->z, 20, 20, 50)) {
                m4aSongNumStart(0x22E);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 28;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 28:
        func_0802F284(act->x, act->y, act->z);

        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 12, 0, w->base.tiles);
            w->unk_1B0 = 0;
            w->unk_1B4 = 0;
            w->unk_1B8 = 0;
            w->flags &= 0xFFFC;
            m4aSongNumStart(198);
        }

        if ((w->flags & 1) == 0) {
            if (AnimGetFrame(&work->base.anim) == 6 && work->base.anim.timer == 0) {
                if (act->flags & 4) {
                    args.x = act->x - 0x3200;
                    args.y = act->y;
                    args.z = act->z - 0x1C00;
                    args.unk_12 = 1;
                    args.unk_14 = 1;
                } else {
                    args.x = act->x + 0x3200;
                    args.y = act->y;
                    args.z = act->z - 0x1C00;
                    args.unk_12 = 0;
                    args.unk_14 = 1;
                }
                w->unk_1B0 = TaskCreate(&w->tasks, &gTaskDescHumHookBomb, &args);
                w->unk_1B4 = TaskCreate(&w->tasks, &gTaskDescHumHookBomb, &args);
                w->unk_1B8 = TaskCreate(&w->tasks, &gTaskDescHumHookBomb, &args);
                w->flags |= 1;
            }
        } else if (w->flags & 2) {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 14, 1, w->base.tiles);
            }
        } else {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 13, 0, w->base.tiles);
                w->flags |= 2;
            }
        }

        if ((w->flags & 1) &&
            IsTaskActiveNamed(w->unk_1B0, gTaskDescHumHookBomb.name) == 0 &&
            IsTaskActiveNamed(w->unk_1B4, gTaskDescHumHookBomb.name) == 0 &&
            IsTaskActiveNamed(w->unk_1B8, gTaskDescHumHookBomb.name) == 0) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 12, 0, w->base.tiles);
            w->unk_1B0 = 0;
            w->flags &= 0xFFFC;
            m4aSongNumStart(198);
        }

        if ((w->flags & 1) == 0) {
            if (AnimGetFrame(&work->base.anim) == 6 && work->base.anim.timer == 0) {
                if (act->flags & 4) {
                    args.x = act->x - 0x3200;
                    args.y = act->y;
                    args.z = act->z - 0x1C00;
                    args.unk_12 = 1;
                    args.unk_14 = 0;
                } else {
                    args.x = act->x + 0x3200;
                    args.y = act->y;
                    args.z = act->z - 0x1C00;
                    args.unk_12 = 0;
                    args.unk_14 = 0;
                }
                w->unk_1B0 = TaskCreate(&w->tasks, &gTaskDescHumHookBomb, &args);
                w->flags |= 1;
            }
        } else if (w->flags & 2) {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 14, 1, w->base.tiles);
            }
        } else {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 13, 0, w->base.tiles);
                w->flags |= 2;
            }
        }

        if ((w->flags & 1) &&
            IsTaskActiveNamed(w->unk_1B0, gTaskDescHumHookBomb.name) == 0) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813EF6C, &w->base.anim, 12, 0, w->base.tiles);
            w->unk_1B0 = 0;
            w->flags &= 0xFFFE;
            m4aSongNumStart(198);
        }
        func_0800F368(work, 1);

        if ((w->flags & 1) == 0) {
            if (AnimGetFrame(&work->base.anim) == 6 && work->base.anim.timer == 0) {
                if (act->flags & 4) {
                    args.x = act->x - 0x3200;
                    args.y = act->y;
                    args.z = act->z - 0x1C00;
                    args.unk_12 = 1;
                    args.unk_14 = 2;
                } else {
                    args.x = act->x + 0x3200;
                    args.y = act->y;
                    args.z = act->z - 0x1C00;
                    args.unk_12 = 0;
                    args.unk_14 = 2;
                }
                w->unk_1B0 = TaskCreate(&w->tasks, &gTaskDescHumHookBomb, &args);
                w->flags |= 1;
            }
        }

        if (w->flags & 1) {
            if ((s16)work->base.unk_152 <= 4) {
                work->base.unk_150 = 0;
                work->base.unk_152++;
                work->base.unk_170 = 29;
            } else {
                if (IsTaskActiveNamed(w->unk_1B0, gTaskDescHumHookBomb.name) == 0) {
                    work->base.unk_150 = 0;
                    func_0801AF08(act);
                    work->base.unk_170 = 0;
                }
            }
        } else {
            work->base.unk_150++;
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(198);
        }
        f = AnimGetFrame(&work->base.anim);

        if (f > 1) {
            if (act->flags & 4) {
                s32 d = act->x + 0x1400;
                act->x += (act->unk_014 - d) >> 3;
            } else {
                s32 d = act->x - 0x1400;
                act->x += (act->unk_014 - d) >> 3;
            }
        }

        if (f == 2) {
            if ((act->flags & 4)
                ? func_08011F78(0x115, act->x - 0x2000, act->y, act->z, 16, 16, 50)
                : func_08011F78(0x115, act->x + 0x2000, act->y, act->z, 16, 16, 50)) {
                m4aSongNumStart(0x22E);
            }
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 8, 0, w->base.tiles);
            m4aSongNumStart(199);
        }
        f = AnimGetFrame(&work->base.anim);

        if (f >= 3 && f <= 5) {
            if (act->flags & 4) {
                s32 d = act->x + 0x4000;
                act->x += (act->unk_014 - d) >> 3;
            } else {
                s32 d = act->x - 0x4000;
                act->x += (act->unk_014 - d) >> 3;
            }
        }

        switch (f) {
        case 4:
        case 5:
            if ((act->flags & 4)
                ? func_08011F78(0x115, act->x - 0x4400, act->y, act->z, 20, 16, 50)
                : func_08011F78(0x115, act->x + 0x4400, act->y, act->z, 20, 16, 50)) {
                m4aSongNumStart(0x22E);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 10, 0, w->base.tiles);
        }
        func_0800F368(work, 1);
        f = AnimGetFrame(&work->base.anim);

        switch (f) {
        case 2:
        case 6:
            if (work->base.anim.timer == 0) {
                if (GetRandom() & 1) {
                    m4aSongNumStart(198);
                } else {
                    m4aSongNumStart(199);
                }
                a = GetAngle(act->x, act->y, x, y);
                work->base.targetX = act->x + gSineTable[a] * 50;
                work->base.targetY = act->y + -gSineTable[a + 64] * 50;
                func_08019A30();
            }
            act->x += ((s32)work->base.targetX - act->x) >> 3;
            act->y += ((s32)work->base.targetY - act->y) >> 3;

            if ((act->flags & 4)
                ? func_08011F78(278, act->x - 0x1000, act->y, act->z, 32, 24, 70)
                : func_08011F78(278, act->x + 0x1000, act->y, act->z, 32, 24, 70)) {
                m4aSongNumStart(0x22F);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 3, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 23;
            work->base.unk_158 = w->unk_188;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23: {
        s32 d;

        act->x += ((s32)work->base.targetX - act->x) >> 4;
        act->y += ((s32)work->base.targetY - act->y) >> 4;
        d = work->base.unk_158;

        if (d < 0) {
            if (d > -0x200) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 4, 0, w->base.tiles);
            }
        } else if (d <= 0x1FF) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 5, 0, w->base.tiles);
        } else {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (act->z >= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 24;
        } else {
            func_0800F368(work, 1);
            work->base.unk_150++;
        }
        break;
    }
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 7, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }

    if ((s16)act->unk_02C > 0) {
        gBtlWork->unk_018 = (gSineTable[(w->angle / 2) & 0xFF] * gUnk_0813F078[w->unk_196]) >> 8;
        {
            s32 t;

            t = w->angle + 1;
            w->angle = t;

            if ((t & 511) == 0) {
                w->unk_196++;

                if (w->unk_196 > 7) {
                    w->unk_196 = 1;
                }
            }
        }

        if (c->z >= c->unk_010 && (s16)c->unk_02C > 0 && c->unk_0E8 != 2 &&
            !(c->flags & 16)) {
            w->unk_18C += (((s16)GetAngleDiff(0, gBtlWork->unk_018) << 6) - w->unk_18C) >> 4;
            c->x -= w->unk_18C;
        } else {
            w->unk_18C = 0;
        }

        if (act->z >= act->unk_010 && (s16)act->unk_02C > 0 && act->unk_0E8 != 2 &&
            !(act->flags & 16)) {
            w->unk_190 += (((s16)GetAngleDiff(0, gBtlWork->unk_018) << 6) - w->unk_190) >> 4;
            act->x -= w->unk_190;
        } else {
            w->unk_190 = 0;
        }
    }
    TaskPoolUpdate(&w->tasks);
    return func_0800E5F0(work);
}

void task_hum_hook_2(HookWork* work) {
    TaskPoolDraw(&work->tasks);
    func_0800EFE8(&work->base);
}

void task_hum_hook_3(HookWork* work) {
    TaskPoolDestroy(&work->tasks);
    HumReleaseResources(&work->base);
    gBtlWork->unk_018 = 0;
}

void task_hum_hook_moon_0(HookMoonWork* work) {
    work->tiles = LoadObjTiles(gUnk_08B5A872, 0xC00);
    PushPaletteEffect(0);
    work->palette = LoadObjPalette(gUnk_08F6DC64, 0x20);
    PopPaletteEffect();
    func_0801C298(work->palette[6] + 16, 0);
    work->unk_0A = 0;
    work->angle = 0;
}

u8 task_hum_hook_moon_1(HookMoonWork* work) {
    work->angle++;
    return 1;
}

void task_hum_hook_moon_2(HookMoonWork* work) {
    s16 x;
    s16 y;
    u16 v;
    u16 t;
    s32 s;

    x = 248 - (gBtlWork->unk_000 >> 9);
    y = 208 - (gBtlWork->unk_004 >> 9);
    s = gSineTable[(u8)work->angle];
    y += s >> 5;
    DrawSprite(x + 64, y - 28, gUnk_08B5A854, work->tiles, work->palette, 0, 0xC00, 0xFFFF);
    DrawSprite(x - 144, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x - 88, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x - 32, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x + 24, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x + 80, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    v = FadeGetAmount();
    if (v != 0) {
        switch (FadeGetColor()) {
        case 0:
            t = 9 - v;
            if ((s16)t < 0) {
                t = 0;
            }
            SetBackdropColor(0, 0, t);
            break;
        case 0x7FFF:
            t = v + 9;
            if ((s16)t > 31) {
                t = 31;
            }
            SetBackdropColor(v, v, t);
            break;
        case 31:
            SetBackdropColor(v, 0, 9);
            break;
        case 0x7C00:
            t = v + 9;
            if ((s16)t > 31) {
                t = 31;
            }
            SetBackdropColor(0, 0, t);
            break;
        case 0x3E0:
            SetBackdropColor(0, v, 9);
            break;
        }
        work->unk_0A = 1;
    } else if (work->unk_0A != 0) {
        SetBackdropColor(0, 0, 9);
        work->unk_0A = v;
    }
}

void task_hum_hook_moon_3(HookMoonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_hook_bomb_0(HookBombWork* work, VixenNdlArgs* args) {
    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->palette = LoadObjPalette(gUnk_08F6DC44, 0x20);
    work->tiles = AllocObjTiles(0x280, gUnk_08B59E52);
    AnimInit(&work->anim, gUnk_09EE17AC, gUnk_09EE1798);
    AnimStart(&work->anim, 0, 1);
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->unk_4E = args->unk_14;
    work->timer = 0;
    work->unk_4A = 0;
    work->unk_50 = GetRandom() % 0x201 + 0x14C;
    work->vz = -(GetRandom() % 0x201 + 0x100);

    switch (work->unk_4E) {
    case 0:
        work->angle = GetAngle(work->x, work->y,
            gBtlWork->unk_130, gBtlWork->unk_134);
        work->unk_4C = GetRandom() % 3 + 1;
        work->unk_38 = 0;
        break;
    case 2:
        work->angle = GetAngle(work->x, work->y,
            gBtlWork->unk_130, gBtlWork->unk_134);
        work->unk_4C = 0;
        work->unk_38 = 1;
        break;
    case 1:
    default:
        work->angle = GetRandom();
        work->unk_4C = GetRandom() % 5 + 4;
        work->unk_38 = 0;
        break;
    }
    work->tiles2 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->palette2 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_48 = 1;
}

u8 task_hum_hook_bomb_1(HookBombWork* work) {
    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    switch (work->unk_38) {
    case 0:
        work->x += gSineTable[work->angle] * work->unk_50 >> 8;
        work->y += -gSineTable[work->angle + 64] * work->unk_50 >> 8;
        work->z += work->vz;
        work->vz += 64;

        if (work->z > 0) {
            work->z = 0;

            if (work->unk_4A >= work->unk_4C) {
                work->timer = 0;
                work->unk_38 = 1;
                break;
            }
            work->vz = -(GetRandom() % 0x301 + 0x200);

            if (work->unk_4E == 0) {
                work->angle = GetAngle(work->x, work->y,
                    gBtlWork->unk_130, gBtlWork->unk_134);
            } else {
                work->angle = GetRandom();
            }
            work->unk_4A++;
        }

        if (func_08011E3C(work->x, work->y, work->z, 2, 2, 2)) {
            work->timer = 0;
            work->unk_38 = 1;
            break;
        }
        work->timer++;
        break;
    default:
        if (work->timer == 0) {
            AnimStart(&work->anim, 1, 0);
        }

        if (work->timer <= 17) {
            work->x += gSineTable[work->angle] * work->unk_50 >> 8;
            work->y += -gSineTable[work->angle + 64] * work->unk_50 >> 8;
            work->z += work->vz;
            work->vz += 64;

            if (work->z > 0) {
                work->z = 0;
                work->vz = -(GetRandom() % 0x301 + 0x200);
                work->angle = GetAngle(work->x, work->y,
                    gBtlWork->unk_130, gBtlWork->unk_134);
            }
        } else if (work->timer == 18) {
            func_08019A30();
            func_08014020(work->x, work->y, work->z);
            work->unk_48 = 0;
        } else if (work->timer > 18) {
            if (func_08011F78(0x117, work->x, work->y, work->z, 24, 24, 24)) {
                m4aSongNumStart(0x264);
            }
        }

        if (work->timer > 17 && func_080128EC() == 0) {
            return 0;
        }
        work->timer++;
        break;
    }
    if (ClampBattlePosition(&work->x, &work->y, 0, 0)) {
        work->angle = (u8)(work->angle + 118) + GetRandom() % 21;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_hook_bomb_2(HookBombWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;

    if (work->unk_48 == 0) {
        return;
    }
    gfx = AnimGetGfx(&work->anim);
    attr = GetBattleSpritePriorityFlags(work->y);

    if (work->unk_2C == 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
        -0x1004 - ((work->y + 0x800) >> 8) * 4);
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B22CBC, work->tiles2, work->palette2, 0, attr, 0xFFF0);
}

void task_hum_hook_bomb_3(HookBombWork* work) {
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette2);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_0804D018(HumWork* work, s32 a) {
    BtlObj* act = &work->actor;
    s32 t;

    if (a != 0) {
        t = a + gSineTable[gFrameCounter * 4 % 256] * 8;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 4;
    }
}

void func_0804D060(AnsemWork* work) {
    BtlObj* act = &work->base.actor;

    if (act->flags & 4) {
        *(s32*)&work->unk_1C8 += (0x1800 - *(s32*)&work->unk_1C8) >> 3;
    } else {
        *(s32*)&work->unk_1C8 += (-0x1800 - *(s32*)&work->unk_1C8) >> 3;
    }
    *(s32*)&work->unk_1CC += (-0x1200 - *(s32*)&work->unk_1CC) >> 3;
    work->sub.x = act->x + *(s32*)&work->unk_1C8;
    work->sub.y = act->y;
    work->sub.z = act->z + *(s32*)&work->unk_1CC;
}

void task_hum_ansem_0(AnsemWork* work) {
    HumInit(&work->base, &gUnk_0813F1E8);
    HumSubInit(&work->base, &work->sub, &gUnk_0813F1E0);
    work->unk_1C4 = -0xC00;
    *(s32*)&work->unk_1C8 = 0;
    work->base.unk_174 = -50;
    work->base.unk_184 = gUnk_0813F0B8;
}

u8 task_hum_ansem_1(AnsemWork* work) {
    AnsemWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, 0);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        act->flags &= ~0x100008000;
        func_08019A30();

        switch ((u32)_0800F84C(work)) {
        case 36:
        case 38:
            work->base.unk_170 = 20;
            break;
        case 37:
        case 39:
            work->base.unk_170 = 25;
            break;
        case 0xFADEB7A3:
            work->base.unk_170 = 26;
            work->unk_1D8 = 0;
            break;
        case 0xFA3EB7A3:
            work->base.unk_170 = 21;
            work->unk_1D8 = 0;
            break;
        }
        break;
    case 4:
        act->flags &= ~0x100008000;
        work->sub.flags &= ~5;
        break;
    }

    if (gBtlWork->unk_10C == 166) {
        func_0800F5A4(&work->base, 30, 80, 80, 24);
    } else if (func_0800F5A4(&work->base, 2, 80, 80, 24)) {
        if (GetRandom() % 2) {
            work->base.unk_184 = gUnk_0813F0B8;
        } else {
            work->base.unk_184 = gUnk_0813F0C4;
        }
    }

    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
        func_08019068(gUnk_0813F140, &w->base.sub->anim, 0, 1, w->base.sub->tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
        func_08019068(gUnk_0813F140, &w->base.sub->anim, 0, 1, w->base.sub->tiles);
        w->unk_1C4 = -0x5000;
        break;
    case 0:
        func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
        func_08019068(gUnk_0813F140, &w->base.sub->anim, 0, 1, w->base.sub->tiles);
        w->unk_1C4 = -0xC00;

        if (func_08081828()) {
            break;
        }

        if (gBtlWork->unk_10C == 177) {
            if ((u16)(GetRandom() % 15) == 0) {
                if (gBtlWork->flags & 0x20000000) {
                    work->base.unk_170 = 29;
                    work->base.unk_150 = 0;
                    break;
                }
            }
        }

        if ((u16)(GetRandom() % 80) == 0) {
            work->base.unk_170 = 8;
            work->base.unk_150 = 0;
            break;
        }
        func_0800F368(work, 3);
        work->base.unk_150++;
        break;
    case 8:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 0, 1, w->base.sub->tiles);
            w->unk_1C4 = -0xC00;
            work->base.targetY = y;

            if (act->x < x) {
                work->base.targetX = x - 0x7800;
            } else {
                work->base.targetX = x + 0x7800;
            }
        }

        if (gBtlWork->unk_10C == 177) {
            if ((u16)(GetRandom() % 30) == 0) {
                if (gBtlWork->flags & 0x20000000) {
                    work->base.unk_170 = 29;
                    work->base.unk_150 = 0;
                    break;
                }
            }
        }

        if (func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, 0x300)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        func_0800F368(work, 1);
        work->base.unk_150++;
        break;
    case 1:
    case 3:
    case 9:
    case 11:
    case 14:
        w->unk_1C4 = 0;
        func_08019068(gUnk_0813F0D0, &w->base.anim, 1, 0, w->base.tiles);
        func_08019068(gUnk_0813F140, &w->base.sub->anim, 1, 0, w->base.sub->tiles);
        break;
    case 2:
        if (gBtlWork->unk_10C != 177) {
            break;
        }

        if (!(gBtlWork->flags & 0x20000000)) {
            break;
        }

        if (!(GetRandom() % 2)) {
            break;
        }
        work->base.unk_170 = 29;
        work->base.unk_150 = 0;
        break;
    case 20:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 2, 0, w->base.sub->tiles);
            w->unk_1C4 = -0x800;
            m4aSongNumStart(270);
        }

        if (act->flags & 4) {
            s32 d = act->x - 0x2800;
            act->x = act->x + ((x - d) >> 4);
        } else {
            s32 d = act->x + 0x2800;
            act->x = act->x + ((x - d) >> 4);
        }
        act->y += (y - act->y) >> 4;

        switch (AnimGetFrame(&w->sub.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (act->flags & 4) {
                act->x -= 0x100;
            } else {
                act->x += 0x100;
            }
            break;
        case 4:
            w->sub.flags |= 1;

            if ((act->flags & 4)
                ? func_08011F78(0x140, act->x - 0x2000, act->y, act->z, 20, 12, 24)
                : func_08011F78(0x140, act->x + 0x2000, act->y, act->z, 20, 12, 24)) {
                m4aSongNumStart(0x261);
            }
            break;
        }

        if (AnimIsFinished(&w->sub.anim)) {
            w->sub.flags &= ~1;
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 2, 0, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 3, 0, w->base.sub->tiles);
            w->unk_1D0 = 0;
            FadeStartOut(9, 90);
            m4aSongNumStart(0x271);
            w->unk_1C4 = -0xC00;
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            func_0804D060(w);
            break;
        default:
            w->unk_1D0 += 25;
            w->sub.z -= w->unk_1D0;
            break;
        }

        if (AnimIsFinished(&w->sub.anim)) {
            work->base.unk_170 = 22;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 5, 0, w->base.sub->tiles);
        }
        w->unk_1D0 += 25;
        w->sub.z -= w->unk_1D0;

        if (w->sub.z < -0x12C00) {
            work->base.unk_170 = 23;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F0D0, &w->base.anim, 0, 1, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 4, 0, w->base.sub->tiles);
            w->unk_1D0 = 0x800;
            w->sub.x = x + (d = ((u16)(GetRandom() % 65) << 8) - 0x2000);
            w->sub.y = y;
            w->sub.z = 0;
            w->sub.flags |= 4;
            m4aSongNumStart(0x272);
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 5:
            if (w->sub.anim.timer == 4) {
                m4aSongNumStart(0x223);
            }
            break;
        case 6:
            w->unk_1D0 += 25;
            w->sub.z -= w->unk_1D0;
            break;
        }

        if ((s16)((s16)work->base.unk_150 % 10) == 0) {
            func_08019A30();
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 2:
        case 3:
            if (func_08011F78(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x800, 20, 16, 8)) {
                m4aSongNumStart(0x261);
            }
            break;
        case 4:
            if (func_08011F78(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x1000, 20, 16, 16)) {
                m4aSongNumStart(0x211);
            }
            break;
        case 5:
            if (func_08011F78(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x2000, 20, 16, 32)) {
                m4aSongNumStart(0x211);
            }
            break;
        case 6:
            if (func_08011F78(0x141, w->sub.x, w->sub.y,
                    w->sub.z - 0x3000, 20, 16, 48)) {
                m4aSongNumStart(0x211);
            }
            break;
        }

        if (w->sub.z < -0x12C00) {
            w->sub.flags &= ~4;
            work->base.unk_150 = 0;

            if (w->unk_1D8 > 6) {
                work->base.unk_170 = 24;
                break;
            }
            work->base.unk_170 = 23;
            w->unk_1D8++;
            break;
        }
        work->base.unk_150++;
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 0, 1, w->base.sub->tiles);
            w->unk_1D6 = 30;
        }

        if (act->flags & 4) {
            ApproachValueHalfSteps(&w->sub.x, act->x + 0x1800, w->unk_1D6);
        } else {
            ApproachValueHalfSteps(&w->sub.x, act->x - 0x1800, w->unk_1D6);
        }
        ApproachValueHalfSteps(&w->sub.y, act->y, w->unk_1D6);
        ApproachValueHalfSteps(&w->sub.z, act->z, w->unk_1D6);
        w->unk_1D6--;

        if (w->unk_1D6 <= 0) {
            FadeStartIn(0, 30);
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 7, 0, w->base.sub->tiles);
            w->sub.flags |= 1;
            act->unk_014 = act->x;
            act->flags |= 0x200;
        }
        func_0800F368(work, 1);

        if (AnimGetFrame(&w->sub.anim) != 0) {
            act->flags |= 0x100008000;

            if (act->flags & 4) {
                s32 d = act->x - 0x1000;
                act->x = act->x + ((act->unk_014 - d) >> 2);
            } else {
                s32 d = act->x + 0x1000;
                act->x = act->x + ((act->unk_014 - d) >> 2);
            }
            *(s32*)&w->unk_1C8 += (0 - *(s32*)&w->unk_1C8) >> 2;
            *(s32*)&w->unk_1CC += (0 - *(s32*)&w->unk_1CC) >> 2;
            w->sub.x = act->x + *(s32*)&w->unk_1C8;
            w->sub.y = act->y;
            w->sub.z = act->z + *(s32*)&w->unk_1CC;
        }

        if ((s16)work->base.unk_150 == 25) {
            act->flags &= ~0x200;
        }

        if ((s16)work->base.unk_150 > 50) {
            w->sub.flags &= ~1;
            act->flags &= ~0x100008000;
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 4, 0, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 7, 0, w->base.sub->tiles);
            w->unk_1C4 = -0xC00;
            m4aSongNumStart(0x10F);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 27;
            break;
        }
        work->base.unk_150++;
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            if (act->x <= 0xFFFF) {
                work->base.targetX = (gBtlWork->unk_0DC - 48) << 8;
                act->flags &= ~4;
            } else {
                work->base.targetX = (gBtlWork->unk_0DA + 48) << 8;
                act->flags |= 4;
            }
            work->base.targetY = y;
            AnimReset(&work->base.anim);
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F0D0, &w->base.anim, 5, 1, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 8, 1, w->base.sub->tiles);
            w->unk_1C4 = -0xC00;
            w->unk_1D6 = 40;
            func_080169A0(w->sub.x, w->sub.y,
                w->sub.z - 0x2100, act->flags & 4);
        }
        a = w->sub.x;
        b = w->sub.y;
        c = w->sub.z;

        if (w->unk_1D6 > 0) {
            ApproachValue(&act->x, work->base.targetX, w->unk_1D6);
            ApproachValueHalfSteps(&act->y, work->base.targetY, w->unk_1D6);
        }
        w->unk_1D6--;

        if ((s16)work->base.unk_150 > 5) {
            w->sub.flags |= 1;

            if (act->flags & 4) {
                *(s32*)&w->unk_1C8 += (-0x2200 - *(s32*)&w->unk_1C8) >> 3;
            } else {
                *(s32*)&w->unk_1C8 += (0x2200 - *(s32*)&w->unk_1C8) >> 3;
            }
            *(s32*)&w->unk_1CC += (0 - *(s32*)&w->unk_1CC) >> 3;
            w->sub.x = act->x + *(s32*)&w->unk_1C8;
            w->sub.y = act->y;
            w->sub.z = act->z + *(s32*)&w->unk_1CC;
        } else {
            func_0804D060(w);
        }

        if (func_08011F78(0x143, w->sub.x, w->sub.y,
                w->sub.z, 32, 16, 32)) {
            m4aSongNumStart(0x221);
        }
        func_0801475C(w->sub.x - a, w->sub.y - b, w->sub.z - c);

        if (w->unk_1D6 <= 0) {
            w->sub.flags &= ~1;
            work->base.unk_150 = 0;

            if (w->unk_1D8 > 3) {
                work->base.unk_170 = 28;
                break;
            }
            work->base.unk_170 = 27;
            w->unk_1D8++;
        } else {
            work->base.unk_150++;
        }
        break;
    case 28:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 6, 0, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 9, 0, w->base.sub->tiles);
            w->unk_1C4 = -0xC00;
        }

        if (!AnimIsFinished(&work->base.anim)) {
            break;
        }
        func_0801AF08(act);
        work->base.unk_170 = 0;
        work->base.unk_150 = 0;
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F0D0, &w->base.anim, 3, 0, w->base.tiles);
            func_08019068(gUnk_0813F140, &w->base.sub->anim, 6, 0, w->base.sub->tiles);
            FadeToAmount(0, gBtlWork->unk_0B3, 8);
            w->unk_1C4 = -0xC00;
        }

        if ((s16)work->base.unk_150 == 20) {
            if (act->flags & 4) {
                func_08016AF4(act->x, act->y, 0, 1, 0x142);
            } else {
                func_08016AF4(act->x, act->y, 0, 0, 0x142);
            }
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0804D060(w);
            break;
        case 5:
            if (w->sub.anim.timer == 0) {
                w->unk_1D6 = 8;
            }

            if (w->unk_1D6 > 0) {
                ApproachValueHalfSteps(&w->sub.z, act->z - 0x3000, w->unk_1D6);
                w->unk_1D6--;
            }
            break;
        case 6:
            if (w->sub.anim.timer == 0) {
                w->unk_1D6 = 8;
            }

            if (w->unk_1D6 > 0) {
                ApproachValueHalfSteps(&w->sub.z, act->z - 0x1000, w->unk_1D6);
                w->unk_1D6--;
            }
            break;
        }

        if (AnimIsFinished(&w->sub.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                FadeToOriginal(0, 8);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    }

    if (!(act->flags & 0x2000) && act->unk_0E8 != 2) {
        func_0804D018(&work->base, w->unk_1C4);
    }

    switch (work->base.unk_170) {
    case 21:
    case 22:
    case 23:
    case 25:
    case 27:
    case 29:
        break;
    default:
        func_0804D060(w);
        break;
    }
    return func_0800E5F0(&work->base);
}

void task_hum_ansem_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_ansem_3(HumWork* work) {
    HumReleaseResources(work);
}

void func_0804E3BC(HumWork* work, s32 a) {
    BtlObj* act = &work->actor;
    s32 t;

    if (a != 0) {
        t = a + gSineTable[gFrameCounter * 4 % 256] * 4;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 4;
    }
}

void func_0804E404(AnsemWork* work) {
    BtlObj* act = &work->base.actor;

    if (work->unk_1CC > 2) {
        LoadObjPaletteBank(((u16*)work->base.palette)[3], gUnk_09617F18);
        work->base.unk_178 = gUnk_09617F18;
        work->unk_1CA &= 0xFFFE;
        work->base.unk_184 = gUnk_0813F214;
    } else {
        work->unk_1CC++;
    }
    func_0801AF08(act);
}

void task_hum_hades_0(HadesWork* work) {
    HumInit(&work->base, &gUnk_0813F324);
    HumSubInit(&work->base, &work->sub, &gUnk_0813F31C);
    work->base.actor.flags |= 0x100000;
    work->base.flags |= 0x40;
    work->unk_1CA = 0;
    work->unk_1C4 = -0xA00;
    work->sub.flags |= 3;
    work->tiles = AllocObjTiles(0x80, gUnk_08BAFB62);
    work->tiles2 = AllocObjTiles(0x280, gUnk_08BAFB62);
    work->tiles3 = AllocObjTiles(0x3A0, gUnk_08BAFB62);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->anim, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->anim, 2, 1);
    AnimInit(&work->anim2, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->anim2, 1, 1);
    AnimInit(&work->anim3, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->anim3, 0, 1);
    work->base.unk_184 = gUnk_0813F214;
}

u8 task_hum_hades_1(HadesWork* work) {
    HadesWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    s16 p;
    s16 q;
    s16 r;
    s16 s;
    u16 frame;
    u8 t;
    u8 ret;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, &z);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;

        switch ((u32)_0800F84C(work)) {
        case 36:
        case 38:
            if (w->unk_1CA & 1) {
                work->base.unk_170 = 21;
            } else {
                work->base.unk_170 = 20;
            }
            break;
        case 37:
        case 39:
            if (w->unk_1CA & 1) {
                work->base.unk_170 = 24;
            } else {
                work->base.unk_170 = 20;
            }
            break;
        case 0xEE5B96E5:
        case 0xEEFB96EF:
            if (w->unk_1CA & 1) {
                work->base.unk_170 = 22;
            } else {
                work->base.unk_170 = 19;
            }
            break;
        }
        break;
    case 4:
        work->sub.flags |= 2;
        work->unk_1CA &= 0xFFFD;
        break;
    }

    if (w->unk_1CA & 1) {
        func_0800F5A4(&work->base, 3, 40, 40, 24);
    } else {
        func_0800F5A4(&work->base, 15, 40, 40, 24);
    }
    w->unk_1C4 = -0xA00;

    switch (work->base.unk_170) {
    case 12:
    case 17:
    case 18:
        func_08019068(gUnk_0813F22C, &w->base.anim, 1, 1, w->base.tiles);
        break;
    case 0:
    case 8:
        t = -((u8)work->base.unk_150 * 2);
        work->base.targetX = x + gSineTable[t] * 90;
        work->base.targetY = y + (-gSineTable[t + 64]) * 45;

        if (w->unk_1CA & 1) {
            func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, 0x333);
        } else {
            func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, 0x140);
        }
        func_0800F368(&work->base, 5);

        if (AnimIsFinished(&work->base.anim)) {
            if (act->flags & 4) {
                if ((s32)work->base.targetX < act->x) {
                    func_08019068(gUnk_0813F22C, &w->base.anim, 0, 1, w->base.tiles);
                } else {
                    func_08019068(gUnk_0813F22C, &w->base.anim, 1, 1, w->base.tiles);
                }
            } else {
                if ((s32)work->base.targetX < act->x) {
                    func_08019068(gUnk_0813F22C, &w->base.anim, 1, 1, w->base.tiles);
                } else {
                    func_08019068(gUnk_0813F22C, &w->base.anim, 0, 1, w->base.tiles);
                }
            }
        }
        work->base.unk_150++;
        break;
    case 1:
    case 3:
    case 9:
    case 11:
    case 14:
        w->unk_1C4 = 0;
        func_08019068(gUnk_0813F22C, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 6, 0, w->base.tiles);
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F2CC, &w->base.sub->anim, 0, 0, w->base.sub->tiles);
            w->sub.flags &= 0xFFFD;
        }
        w->sub.x = act->x;
        w->sub.y = act->y;
        w->sub.z = act->z;

        if (AnimGetFrame(&w->sub.anim) == 1 && w->sub.anim.timer == 0) {
            m4aSongNumStart(0x26C);
        }

        if (AnimGetFrame(&work->base.anim) == 5 && work->base.anim.timer == 0) {
            LoadObjPaletteBank(((u16*)work->base.palette)[3], gUnk_09617F38);
            work->base.unk_178 = gUnk_09617F38;
            w->unk_1CA |= 1;
            work->base.unk_184 = gUnk_0813F220;
            w->unk_1CC = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            w->sub.flags |= 2;
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 4, 0, w->base.tiles);
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F2CC, &w->base.sub->anim, 2, 0, w->base.sub->tiles);
            w->sub.flags &= 0xFFFD;
            m4aSongNumStart(252);
            m4aSongNumStart(0x2B5);
        }
        w->sub.x = act->x;
        w->sub.y = act->y;
        w->sub.z = act->z;

        if (AnimIsFinished(&w->sub.anim)) {
            work->base.unk_170 = 23;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F2CC, &w->base.sub->anim, 3, 1, w->base.sub->tiles);

            if (act->flags & 4) {
                w->sub.x -= 0xA00;
            } else {
                w->sub.x += 0xA00;
            }
            w->sub.z -= 0x4E00;
            w->unk_1D0 = 0;
            m4aSongNumStart(0x26D);
        }

        if (act->flags & 4) {
            w->sub.x -= 0x700;
        } else {
            w->sub.x += 0x700;
        }
        w->sub.y += (y - w->sub.y) >> 4;
        w->sub.z += w->unk_1D0;
        w->unk_1D0 += 89;

        if (w->sub.z + 0xF00 > 0) {
            w->sub.z = -0xF00;
            w->unk_1D0 = -(w->unk_1D0 >> 1);
        }

        if (func_08011F78(0x120, w->sub.x, w->sub.y, w->sub.z, 16, 16, 16)) {
            m4aSongNumStart(0x22C);
        }

        if (w->sub.x < (gBtlWork->unk_0DA - 32) << 8 || w->sub.x > (gBtlWork->unk_0DC + 32) << 8) {
            w->sub.flags |= 2;
            func_0804E404((AnsemWork*)w);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 7, 0, w->base.tiles);
#ifdef VERSION_EU
            if (act->btl->unk_0F4 == 8) {
                act->btl->unk_0F8--;
            }
#endif
        }

        if (AnimGetFrame(&work->base.anim) == 4) {
            work->base.unk_170 = 25;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 8, 1, w->base.tiles);
            w->unk_27C = 10;
            work->base.unk_152 = 8;
            w->unk_1CA = (w->unk_1CA & 0xFFFB) | 2;

            if (act->flags & 4) {
                w->sub2[0].x = w->sub2[0].x2 = w->sub2[0].x3 = act->x - 0x2800;
                w->sub2[0].y = w->sub2[0].y2 = w->sub2[0].y3 = act->y;
                w->sub2[0].z = w->sub2[0].z2 = w->sub2[0].z3 = act->z - 0x3600;
                w->sub2[1].x = w->sub2[1].x2 = w->sub2[1].x3 = act->x + 0x600;
                w->sub2[1].y = w->sub2[1].y2 = w->sub2[1].y3 = act->y;
                w->sub2[1].z = w->sub2[1].z2 = w->sub2[1].z3 = act->z - 0x3400;
            } else {
                w->sub2[0].x = w->sub2[0].x2 = w->sub2[0].x3 = act->x + 0x2800;
                w->sub2[0].y = w->sub2[0].y2 = w->sub2[0].y3 = act->y;
                w->sub2[0].z = w->sub2[0].z2 = w->sub2[0].z3 = act->z - 0x3600;
                w->sub2[1].x = w->sub2[1].x2 = w->sub2[1].x3 = act->x - 0x600;
                w->sub2[1].y = w->sub2[1].y2 = w->sub2[1].y3 = act->y;
                w->sub2[1].z = w->sub2[1].z2 = w->sub2[1].z3 = act->z - 0x3400;
            }
            m4aSongNumStart(0x2B6);
        }
        w->unk_1C4 = 0;

        if ((s16)work->base.unk_152 > 0) {
            if (w->unk_1CA & 4) {
                ApproachValue(&w->unk_27C, 10, (u16)work->base.unk_152);
            } else {
                ApproachValue(&w->unk_27C, 0x100, (u16)work->base.unk_152);
            }
            work->base.unk_152--;
        }

        if ((s16)work->base.unk_150 == 180) {
            w->unk_1CA |= 4;
            work->base.unk_152 = 8;
        }
        func_0800F368(&work->base, 8);
        act->y += (y - act->y) >> 4;
        act->x += gSineTable[(u8)work->base.unk_150];
        w->sub2[0].unk_00 = act->y;
        w->sub2[1].unk_00 = act->y;

        if (w->unk_1CA & 2) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                p = 44;
                q = -50;
                r = 2;
                s = -44;
                break;
            case 3:
                p = 44;
                q = -39;
                r = 33;
                s = -32;
                break;
            case 4:
                p = 46;
                q = -42;
                r = 21;
                s = -32;
                break;
            case 5:
                p = 46;
                q = -50;
                r = -3;
                s = -30;
                break;
            case 6:
                p = 48;
                q = -43;
                r = -2;
                s = -30;
                break;
            case 7:
                p = 45;
                q = -43;
                r = 2;
                s = -31;
                break;
            case 8:
                p = 42;
                q = -48;
                r = 19;
                s = -34;
                break;
            case 9:
            default:
                p = 33;
                q = -49;
                r = 20;
                s = -41;
                break;
            }

            if (act->flags & 4) {
                w->sub2[0].x += (act->x - ((s16)p << 8) - w->sub2[0].x) >> 1;
                w->sub2[1].x += (act->x - ((s16)r << 8) - w->sub2[1].x) >> 1;
            } else {
                w->sub2[0].x += (act->x + ((s16)p << 8) - w->sub2[0].x) >> 1;
                w->sub2[1].x += (act->x + ((s16)r << 8) - w->sub2[1].x) >> 1;
            }
            w->sub2[0].y += (act->y - w->sub2[0].y) >> 1;
            w->sub2[1].y += (act->y - w->sub2[1].y) >> 1;
            w->sub2[0].z += (act->z + ((s16)q << 8) - w->sub2[0].z) >> 1;
            w->sub2[1].z += (act->z + ((s16)s << 8) - w->sub2[1].z) >> 1;
            {
                s32 v = w->unk_27C;
                p = (s16)p + (v * 14 >> 8);
                q = (s16)q + (v * 10 >> 8);
                r = (s16)r + (v * 8 >> 8);
                s = (s16)s + (v * 12 >> 8);
            }

            if (act->flags & 4) {
                w->sub2[0].x2 += (act->x - ((s16)p << 8) - w->sub2[0].x2) >> 3;
                w->sub2[1].x2 += (act->x - ((s16)r << 8) - w->sub2[1].x2) >> 3;
            } else {
                w->sub2[0].x2 += (act->x + ((s16)p << 8) - w->sub2[0].x2) >> 3;
                w->sub2[1].x2 += (act->x + ((s16)r << 8) - w->sub2[1].x2) >> 3;
            }
            w->sub2[0].y2 += (act->y - w->sub2[0].y2) >> 3;
            w->sub2[1].y2 += (act->y - w->sub2[1].y2) >> 3;
            w->sub2[0].z2 += (act->z + ((s16)q << 8) - w->sub2[0].z2) >> 3;
            w->sub2[1].z2 += (act->z + ((s16)s << 8) - w->sub2[1].z2) >> 3;
            {
                s32 v = w->unk_27C;
                p = (s16)p + (v * 24 >> 8);
                q = (s16)q + (v * 20 >> 8);
                r = (s16)r + (v * 10 >> 8);
                s = (s16)s + (v * 20 >> 8);
            }

            if (act->flags & 4) {
                w->sub2[0].x3 += (act->x - ((s16)p << 8) - w->sub2[0].x3) >> 4;
                w->sub2[1].x3 += (act->x - ((s16)r << 8) - w->sub2[1].x3) >> 4;
            } else {
                w->sub2[0].x3 += (act->x + ((s16)p << 8) - w->sub2[0].x3) >> 4;
                w->sub2[1].x3 += (act->x + ((s16)r << 8) - w->sub2[1].x3) >> 4;
            }
            w->sub2[0].y3 += (act->y - w->sub2[0].y3) >> 4;
            w->sub2[1].y3 += (act->y - w->sub2[1].y3) >> 4;
            w->sub2[0].z3 += (act->z + ((s16)q << 8) - w->sub2[0].z3) >> 4;
            w->sub2[1].z3 += (act->z + ((s16)s << 8) - w->sub2[1].z3) >> 4;
        }

#ifndef VERSION_EU
        if (act->btl->unk_0F4 == 8 && act->unk_02C < act->unk_02E >> 1) {
            gBtlWork->unk_124 = 0x200;
        }
#endif

        if (w->unk_27C == 0x100) {
            if (func_08011F78(0x121, w->sub2[0].x3, w->sub2[0].unk_00, w->sub2[0].z3, 16, 16, 16)) {
                m4aSongNumStart(0x1F9);
            }

            if (func_08011F78(0x121, w->sub2[1].x3, w->sub2[1].unk_00, w->sub2[1].z3, 16, 16, 16)) {
                m4aSongNumStart(0x1F9);
            }
        }
#ifndef VERSION_EU
        gBtlWork->unk_124 = 0;
#endif

        if ((w->unk_1CA & 4) && (s16)work->base.unk_152 <= 0) {
            w->unk_1CA &= 0xFFFD;
            work->base.unk_170 = 26;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 9, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 5, 0, w->base.tiles);
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F2CC, &w->base.sub->anim, 1, 0, w->base.sub->tiles);
            w->sub.flags &= 0xFFFD;
#ifdef VERSION_EU
            if (act->btl->unk_0F4 == 8) {
                act->btl->unk_0F8--;
            }
#endif
        }
        w->sub.x = act->x;
        w->sub.y = act->y;
        w->sub.z = act->z;

        frame = AnimGetFrame(&w->sub.anim);

        switch (frame) {
        case 2:
        case 3:
        case 4:
#ifndef VERSION_EU
            if (act->btl->unk_0F4 == 8 && act->unk_02C < act->unk_02E >> 1) {
                gBtlWork->unk_124 = 0x200;
            }
#endif

            if ((act->flags & 4)
                ? func_08011F78(0x11F, act->x - 0x1E00, act->y, act->z, 30, 16, 60)
                : func_08011F78(0x11F, act->x + 0x1E00, act->y, act->z, 30, 16, 60)) {
                m4aSongNumStart(0x1F9);
            }
#ifndef VERSION_EU
            gBtlWork->unk_124 = 0;
#endif
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            w->sub.flags |= 2;
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F22C, &w->base.anim, 3, 0, w->base.tiles);
            AnimReset(&w->sub.anim);
            func_08019068(gUnk_0813F2CC, &w->base.sub->anim, 4, 0, w->base.sub->tiles);
            w->sub.flags &= 0xFFFD;
            w->sub.x = act->x;
            w->sub.y = act->y;
            w->sub.z = act->z;
            m4aSongNumStart(253);
#ifdef VERSION_EU
            if (act->btl->unk_0F4 == 8) {
                act->btl->unk_0F8--;
            }
#endif
        }

        switch (AnimGetFrame(&w->sub.anim)) {
        case 1:
            if (w->sub.anim.timer == 0) {
                m4aSongNumStart(0x26E);
            }
            break;
        case 2:
#ifndef VERSION_EU
            if (act->btl->unk_0F4 == 8 && act->unk_02C < act->unk_02E >> 1) {
                gBtlWork->unk_124 = 0x200;
            }
#endif

            if (act->flags & 4) {
                func_08011F78(0x11E, act->x - 0x2000, act->y, act->z, 24, 16, 60);
            } else {
                func_08011F78(0x11E, act->x + 0x2000, act->y, act->z, 24, 16, 60);
            }
#ifndef VERSION_EU
            gBtlWork->unk_124 = 0;
#endif
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            w->sub.flags |= 2;
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }

    if (!(act->flags & 0x2000) && act->unk_0E8 != 2) {
        func_0804E3BC(&work->base, w->unk_1C4);
    }

    if (w->unk_1CA & 2) {
        AnimUpdate(&w->anim);
        AnimUpdate(&w->anim2);
        AnimUpdate(&w->anim3);
    }
    ret = func_0800E5F0(&work->base);
    return ret;
}

void task_hum_hades_2(HadesWork* work) {
    BtlObj* act;
    HadesSub* e;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 affine;
    s16 x;
    s16 y;
    s32 i;

    func_0800EFE8(&work->base);

    if ((work->unk_1CA & 2) == 0) {
        return;
    }
    act = &work->base.actor;

    for (i = 0; i < 2; i++) {
        e = &work->sub2[i];
        attr = GetBattleSpritePriorityFlags(e->unk_00);

        if (work->unk_27C == 0x100) {
            if ((act->flags & 4) == 0) {
                attr |= 1;
            }
            sx = work->unk_27C;
        } else {
            if ((act->flags & 4) == 0) {
                sx = work->unk_27C;
            } else {
                sx = -work->unk_27C;
            }
        }
        affine = AllocObjAffine(0, sx, work->unk_27C, 0);
        gfx = AnimGetGfx(&work->anim);
        WorldToScreen(&x, &y, e->x, e->y, e->z);
        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, attr,
            -0x1005 - (e->unk_00 >> 8) * 4);
        gfx = AnimGetGfx(&work->anim2);
        WorldToScreen(&x, &y, e->x2, e->y2, e->z2);
        DrawSprite(x, y, gfx, work->tiles2, work->palette, affine, attr,
            -0x1006 - (e->unk_00 >> 8) * 4);
        gfx = AnimGetGfx(&work->anim3);
        WorldToScreen(&x, &y, e->x3, e->y3, e->z3);
        DrawSprite(x, y, gfx, work->tiles3, work->palette, affine, attr,
            -0x1007 - (e->unk_00 >> 8) * 4);
    }
}

void task_hum_hades_3(HadesWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjTiles(work->tiles3);
    ReleaseObjPalette(work->palette);
    HumReleaseResources(&work->base);
}

void func_0804F8F0(MahluxiaWork* work, s16 a) {
    HumWork* w = &work->base;
    BtlObj* act = &w->actor;
    s32 v;

    func_0801C700(act, &v, 0, 0);

    if (act->flags & 4) {
        w->targetX = act->x - (a << 8);
    } else {
        w->targetX = act->x + (a << 8);
    }
    w->unk_170 = 20;
    w->unk_150 = 0;
    work->unk_1C4 = -0x300;

    if (act->y < v) {
        w->targetY = (gBtlWork->unk_0DE + 16) << 8;
    } else {
        w->targetY = (gBtlWork->unk_0E0 - 16) << 8;
    }
}

void func_0804F9A0(MahluxiaWork* work, s32 a, u16 b) {
    work->base.targetX = a;
    work->unk_1C8 = b;
    work->base.unk_170 = 19;
    work->base.unk_150 = 0;
}

u8 func_0804F9C8(MahluxiaWork* work) {
    s32 v;
    BtlObj* c;

    c = gBtlWork->actor;
    func_0801C700(&work->base.actor, &v, 0, 0);
    func_0800F368(work, 1);

    if (func_0800F504(work, 0x100, 0x100, 0x100)) {
        if (gBtlWork->flags & 0x8000) {
            func_0804F8F0(work, -128);
        } else if (GetRandom() & 1) {
            if (c->flags & 4) {
                func_0804F9A0(work, v + 0x2800, 48);
            } else {
                func_0804F9A0(work, v - 0x2800, 48);
            }
        } else {
            func_0804F8F0(work, -128);
        }
        return 1;
    }
    return 0;
}

void func_0804FA70(MahluxiaWork* work, RikuSpawn* dst) {
    BtlObj* act = &work->base.actor;

    dst->x = act->x;
    dst->y = act->y;
    dst->z = act->z;

    if (act->flags & 4) {
        dst->flags |= 1;
    } else {
        dst->flags &= 0xFFFE;
    }
    dst->anim = work->base.anim;
    dst->unk_28 = *(u32*)work->base.tiles;
    dst->unk_2C = gBtlWork->unk_024;
}

void func_0804FAD4(MahluxiaWork* work, RikuSpawn* p) {
    BtlObj* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    s32 affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.sub;
    gfx = AnimGetGfx(&p->anim);
    act = &work->base.actor;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(4, 14);
        attr = 0x804;
    } else {
        attr = GetBattleSpritePriorityFlags(act->y);
    }

    if (p->flags & 1) {
        sy = p->unk_2C;
        sx = sy;
    } else if (p->unk_2C == 0x100) {
        sy = p->unk_2C;
        sx = sy;
        attr |= 1;
    } else {
        sx = -gBtlWork->unk_024;
        sy = gBtlWork->unk_024;
    }

    if (sy == 0x100 && sx == sy) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }
    pri = 0xFFF0;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    SetObjTileSource(sub->tiles, p->unk_28);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void func_0804FBDC(HumWork* work, s32 a) {
    BtlObj* act;
    s32 t;

    if (a != 0) {
        act = &work->actor;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 4;
    }
}

void task_hum_mahluxia_0(MahluxiaWork* work) {
    HumInit(&work->base, &gUnk_0813F450);
    HumSubInit(&work->base, &work->sub, &gUnk_0813F448);
    work->flags = 0;
    work->unk_1C4 = -0x300;
    work->sub.flags |= 3;
    work->unk_1D8 = 0;
    func_08019068(gUnk_0813F368, &work->base.anim, 0, 1, work->base.tiles);
    func_0804FA70(work, &work->spawns[0]);
    work->spawns[1] = work->spawns[0];
    work->spawns[2] = work->spawns[0];
    work->spawns[3] = work->spawns[0];
    work->spawns[4] = work->spawns[0];
    work->spawns[5] = work->spawns[0];
    work->spawns[6] = work->spawns[0];
    work->spawns[7] = work->spawns[0];
    work->spawns[8] = work->spawns[0];
    TaskPoolInit(&work->tasks, 22);
    work->base.unk_184 = gUnk_0813F35C;
}

void func_0804FD7C(MahluxiaWork* work) {
    BtlObj* act = &work->base.actor;
    VixenNdlArgs args;
    s32 range;

    if (gFrameCounter % 5 == 0) {
        args.x = act->x;
        args.y = act->y;
        args.z = act->z - ((s16)act->unk_0A2 << 8);
        range = 0x2000;
        args.x += ((GetRandom() % 65) << 8) - range;
        range = 0x1000;
        args.y += ((GetRandom() % 33) << 8) - range;
        args.z += ((GetRandom() % 41) << 8) - range;
        TaskCreate(&work->tasks, &gTaskDescHumMahluxiaFlw, &args);
    }
}

u8 task_hum_mahluxia_1(MahluxiaWork* work) {
    MahluxiaWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    u16 n;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, &z);
    work->flags &= ~2;

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        w->unk_1C4 = 0;

        switch ((u32)_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 21;
            break;
        case 37:
            work->base.unk_170 = 27;
            break;
        case 38:
        case 39:
            work->base.unk_170 = 28;
            break;
        case 0xF71D9F71:
            work->base.unk_170 = 26;
            break;
        case 0xF7BDC767:
            work->base.unk_170 = 22;
            break;
        }
        break;
    case 4:
        w->sub.flags |= 2;
        break;
    }

    if (func_0800F5A4(&work->base, 4, 40, 40, 24)) {
        if (GetRandom() % 2) {
            work->base.unk_184 = gUnk_0813F35C;
        } else {
            work->base.unk_184 = gUnk_0813F350;
        }
    }

    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F368, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F368, &w->base.anim, 0, 1, w->base.tiles);

        if (gBtlWork->flags & 0x20000000) {
            if (func_0804F9C8(w)) {
                break;
            }
        }

        if (act->x - x >= 0 ? act->x - x <= 0x4FFF : x - act->x <= 0x4FFF) {
            if (x <= 0xFFFF) {
                func_0804F9A0(w, (gBtlWork->unk_0DC - 60) << 8, 48);
            } else {
                func_0804F9A0(w, (gBtlWork->unk_0DA + 60) << 8, 48);
            }
        }
        break;
    case 0:
        func_08019068(gUnk_0813F368, &w->base.anim, 0, 1, w->base.tiles);
        w->unk_1C4 = -0x300;

        if (func_08081828()) {
            break;
        }

        if (act->x - x >= 0 ? act->x - x > 0x2800 : x - act->x > 0x2800) {
            if (GetRandom() % 80 == 0) {
                work->base.unk_170 = 8;
                work->base.unk_150 = 0;
                break;
            }
        }

        if (func_0800F4C8(work, 40)) {
            func_0804F9A0(w, 0x10000, 48);
            break;
        }

        if (gBtlWork->flags & 0x20000000) {
            if (func_0804F9C8(w)) {
                break;
            }
        } else {
            func_0800F368(work, 8);
        }
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813F368, &w->base.anim, 1, 1, w->base.tiles);
        work->base.targetX = x;
        work->base.targetY = y;

        if (func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, 358)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }

        if (gBtlWork->flags & 0x20000000) {
            if (func_0804F9C8(w)) {
                break;
            }
        } else {
            func_0800F368(work, 30);
        }
        work->base.unk_150++;
        break;
    case 1:
        func_0804FD7C(w);
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813F368, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 20:
        func_08019068(gUnk_0813F368, &w->base.anim, 1, 0, w->base.tiles);
        act->x += ((s32)work->base.targetX - act->x) >> 4;
        act->y += ((s32)work->base.targetY - act->y) >> 4;

        if ((work->base.flags & 1)
                || ((s32)work->base.targetX - act->x >= 0
                    ? (s32)work->base.targetX - act->x <= 0x7FF
                    : act->x - (s32)work->base.targetX <= 0x7FF)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
            break;
        }
        func_0800F368(work, 1);
        func_0804FD7C(w);
        w->flags |= 2;
        work->base.unk_150++;
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1CA = 60;
            w->angle = 0;
            w->unk_1D4 = act->y;

            if (((gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7) < act->y) {
                w->flags &= ~1;
            } else {
                w->flags |= 1;
            }
            func_08019068(gUnk_0813F368, &w->base.anim, 1, 1, w->base.tiles);
        }

        if ((s16)w->unk_1CA != 0) {
            ApproachValueHalfSteps(&act->x, work->base.targetX, w->unk_1CA);
            ApproachValueHalfSteps(&w->angle, 128, w->unk_1CA);

            if (w->flags & 1) {
                act->y = w->unk_1D4 + gSineTable[(u8)w->angle] * w->unk_1C8;
            } else {
                act->y = w->unk_1D4 - gSineTable[(u8)w->angle] * w->unk_1C8;
            }
            w->unk_1CA--;
        }
        func_0804FD7C(w);

        if ((s16)w->unk_1CA <= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
            break;
        }
        func_0800F368(work, 3);
        w->flags |= 2;
        work->base.unk_150++;
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 4, 0, w->base.tiles);
        }
        w->flags |= 2;

        if (!AnimIsFinished(&work->base.anim)) {
            work->base.unk_150++;
            break;
        }
        work->base.unk_170 = 23;
        work->base.unk_150 = 0;
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 5, 1, w->base.tiles);
        }
        act->y += (y - act->y) >> 2;
        n = (u16)work->base.unk_150;

        if ((s16)n > 60) {
            work->base.unk_170 = 24;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150 = n + 1;
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 6, 0, w->base.tiles);
        }
        w->flags |= 2;

        if (!AnimIsFinished(&work->base.anim)) {
            work->base.unk_150++;
            break;
        }
        work->base.unk_170 = 25;
        work->base.unk_150 = 0;
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 7, 0, w->base.tiles);
            m4aSongNumStart(0x116);
        }
        w->flags |= 2;

        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
            if (work->base.anim.timer == 0) {
                func_0800F368(work, 1);
                func_0801836C(act->x, act->y, act->z, x - act->x, 316);
            }
            break;
        case 2:
            if (work->base.anim.timer == 0) {
                if ((act->flags & 4)
                    ? func_08011F78(0x13B, act->x - 0x2800, act->y, act->z, 40, 12, 64)
                    : func_08011F78(0x13B, act->x + 0x2800, act->y, act->z, 40, 12, 64)) {
                    m4aSongNumStart(0x20D);
                }
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 28:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 10, 0, w->base.tiles);
            m4aSongNumStart(0x119);
        }
        w->flags |= 2;

        if (act->flags & 4) {
            act->x = act->x - 0x105;
        } else {
            act->x = act->x + 0x105;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 29;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 11, 0, w->base.tiles);
            FadeStartIn(2, 20);
            m4aSongNumStart(0x2C2);
            FadeLock();
            gBtlWork->unk_072 = 20;
            w->flags |= 2;

            if (act->flags & 4) {
                act->x -= 0x5000;
                func_08011F78(0x13F, act->x + 0x2800, act->y, 0, 40, 16, 40);
            } else {
                act->x += 0x5000;
                func_08011F78(0x13F, act->x - 0x2800, act->y, 0, 40, 16, 40);
            }
        }
        n = (u16)work->base.unk_150;

        if ((s16)n > 60) {
            work->base.unk_170 = 30;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150 = n + 1;
        break;
    case 30:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 12, 0, w->base.tiles);
        }
        w->flags |= 2;

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 8, 0, w->base.tiles);
            w->flags &= ~4;
            m4aSongNumStart(0x117);
        }
        w->flags |= 2;

        if (AnimGetFrame(&work->base.anim) == 4) {
            if (work->base.anim.timer == 0) {
                func_08018184(act->x, act->y, act->z - 0x4D00, 318);
                w->flags |= 4;
            }
        }

        if (w->flags & 4) {
            func_0804FD7C(w);
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(0x119);
        }
        w->flags |= 2;

        switch (AnimGetFrame(&work->base.anim)) {
        case 4:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2A9);

                if (act->flags & 4) {
                    func_08017F70(act->x + 0x1700, act->y, 0, 0x13D);
                } else {
                    func_08017F70(act->x - 0x1700, act->y, 0, 0x13D);
                }
            }
            break;
        case 5:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2AA);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 3, 0, w->base.tiles);
            w->flags &= ~4;

            if (act->flags & 4) {
                w->sub.x = act->x - 0x4600;
            } else {
                w->sub.x = act->x + 0x4600;
            }
            w->sub.z = 0;
            w->unk_38C = 0;
            m4aSongNumStart(0x119);
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
            w->flags |= 2;
            act->y += (y - act->y) >> 2;
            w->sub.y = act->y;
            break;
        case 4:
            if (work->base.anim.timer == 0) {
                AnimReset(&w->sub.anim);
                func_08019068(&gUnk_0813F438, &w->base.sub->anim, 0, 0, w->base.sub->tiles);
                w->flags |= 4;
                w->sub.flags &= ~2;
                m4aSongNumStart(0x224);

                if ((act->flags & 4)
                    ? func_08011F78(0x13B, act->x - 0x2800, act->y, act->z, 40, 12, 64)
                    : func_08011F78(0x13B, act->x + 0x2800, act->y, act->z, 40, 12, 64)) {
                    m4aSongNumStart(0x20D);
                }
            }
            func_0804FD7C(w);
            break;
        case 5:
        case 6:
            func_0804FD7C(w);
            break;
        }

        if (w->flags & 4) {
            w->unk_38C += 25;

            if (act->flags & 4) {
                w->sub.x = w->sub.x - w->unk_38C;
            } else {
                w->sub.x = w->sub.x + w->unk_38C;
            }

            switch (AnimGetFrame(&w->sub.anim)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                if (func_08011F78(0x13B, w->sub.x, w->sub.y, w->sub.z, 8, 4, 64)) {
                    m4aSongNumStart(0x28C);
                }
                break;
            default:
                if (func_08011F78(0x13B, w->sub.x, w->sub.y, w->sub.z, 16, 4, 20)) {
                    m4aSongNumStart(0x28C);
                }
                break;
            }

            if (w->sub.x < (gBtlWork->unk_0DA - 32) << 8 ||
                w->sub.x > (gBtlWork->unk_0DC + 32) << 8) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                w->sub.flags |= 2;
                break;
            }
        }
        work->base.unk_150++;
        break;
    }

    if (!(act->flags & 0x2000)) {
        if (act->unk_0E8 != 2) {
            func_0804FBDC(&work->base, w->unk_1C4);
        }
    }
    TaskPoolUpdate(&w->tasks);
    return func_0800E5F0(&work->base);
}

void task_hum_mahluxia_2(MahluxiaWork* work) {
    func_0800EFE8(&work->base);

    if ((work->flags & 2) && (work->sub.flags & 2)) {
        switch (work->unk_1D8 % 12) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
            func_0804FAD4(work, &work->spawns[2]);
            break;
        case 1:
        case 3:
        case 7:
            func_0804FAD4(work, &work->spawns[4]);
            break;
        case 5:
        case 9:
            func_0804FAD4(work, &work->spawns[6]);
            break;
        case 11:
            func_0804FAD4(work, &work->spawns[8]);
            break;
        }
        work->unk_1D8++;
    }
    work->spawns[8] = work->spawns[7];
    work->spawns[7] = work->spawns[6];
    work->spawns[6] = work->spawns[5];
    work->spawns[5] = work->spawns[4];
    work->spawns[4] = work->spawns[3];
    work->spawns[3] = work->spawns[2];
    work->spawns[2] = work->spawns[1];
    work->spawns[1] = work->spawns[0];
    func_0804FA70(work, &work->spawns[0]);
    TaskPoolDraw(&work->tasks);
}

void task_hum_mahluxia_3(MahluxiaWork* work) {
    HumReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

void func_08050EC4(HumWork* work, s32 a) {
    BtlObj* act;
    s32 t;

    if (a != 0) {
        act = &work->actor;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 6;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 3;
    }
}

void CreateHumLaxeneKnfTask(LaxeneWork* work, s16 a, s16 b) {
    BtlObj* act = &work->base.actor;
    VixenNdlArgs args;

    if (act->flags & 4) {
        args.x = act->x + (a << 8);
        args.unk_12 = 1;
    } else {
        args.x = act->x - (a << 8);
        args.unk_12 = 0;
    }
    args.z = act->z + (b << 8);
    args.y = act->y;
    TaskCreate(&work->tasks, &gTaskDescHumLaxeneKnf, &args);
}

void task_hum_laxene_0(LaxeneWork* work) {
    HumInit(&work->base, &gUnk_0813F588);
    work->flags = 0;
    work->unk_188 = -0x3000;
    work->unk_190 = 0;
    work->base.actor.flags |= 0x80000000000;
    work->base.unk_184 = gUnk_0813F480[0];
    TaskPoolInit(&work->tasks, 12);
}

u8 task_hum_laxene_1(LaxeneWork* work) {
    LaxeneWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    s16 d;
    s32 u;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, &z);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        work->base.unk_152 = 0;

        switch ((u32)_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 21;
            break;
        case 37:
            work->base.unk_170 = 30;
            break;
        case 38:
        case 39:
            if (act->unk_02C < (act->unk_02E >> 1)) {
                work->base.unk_170 = 31;
            } else {
                work->base.unk_170 = 22;
            }
            break;
        case 0xF49D2735:
            work->base.unk_170 = 25;
            break;
        case 0xF35CFF3F:
            work->base.unk_152 = GetRandom() % 4 + 4;
            work->base.unk_170 = 32;
            m4aSongNumStart(284);
            break;
        }
        break;
    case 4:
        m4aSongNumStop(0x2A2);
        work->base.unk_168 = 256;
        work->base.unk_16C = 256;
        break;
    }

    if (gBtlWork->unk_10C == 163) {
        if (func_0800F5A4(&work->base, 15, 80, 80, 50)) {
            work->base.unk_184 = gUnk_0813F480[0];
        }
    } else if (func_0800F5A4(&work->base, 5, 80, 80, 50)) {
        if (GetRandom() % 2) {
            work->base.unk_184 = gUnk_0813F480[0];
        } else {
            work->base.unk_184 = gUnk_0813F480[1];
        }
    }

    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F498, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F498, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        func_08019068(gUnk_0813F498, &w->base.anim, 0, 1, w->base.tiles);
        func_0800F368(work, 5);

        if (func_08081828() == 0) {
            if (GetRandom() % 30 == 0) {
                work->base.unk_170 = 8;
                work->base.unk_150 = 0;
            } else {
                work->base.unk_150++;
            }
        }
        break;
    case 8:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 1, 0, w->base.tiles);
            work->base.targetX = (gBtlWork->unk_0DA + GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA + 1)) << 8;
            work->base.targetY = (gBtlWork->unk_0DE + GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE + 1)) << 8;
            work->base.targetZ = -((GetRandom() % 71) << 8);

            if (act->btl->unk_0F4 == 50) {
                work->base.unk_152 = 12;
            } else {
                work->base.unk_152 = 25;
            }
            w->unk_188 = 0;
        } else if (AnimIsFinished(&work->base.anim)) {
            func_08019068(gUnk_0813F498, &w->base.anim, 2, 1, w->base.tiles);
        }
        ApproachValue(&act->x, work->base.targetX, (u16)work->base.unk_152);
        ApproachValue(&act->y, work->base.targetY, (u16)work->base.unk_152);
        ApproachValue(&act->z, work->base.targetZ, (u16)work->base.unk_152);
        work->base.unk_152--;

        if ((s16)work->base.unk_152 <= 0) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            w->unk_188 = act->z;
            break;
        }
        work->base.unk_158 = 0;

        if (act->x < (s32)work->base.targetX) {
            act->flags &= ~4;
        } else {
            act->flags |= 4;
        }
        work->base.unk_150++;
        break;
    case 1:
    case 3:
    case 9:
    case 11:
    case 14:
        w->unk_188 = 0;
        func_08019068(gUnk_0813F498, &w->base.anim, 3, 0, w->base.tiles);
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 6, 0, w->base.tiles);
            w->unk_188 = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 26;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 7, 1, w->base.tiles);

            if (act->flags & 4) {
                func_08015834(0, act->x + 0x400, act->y, act->z - 0x5000, act->x,
                    act->y, act->z - 0x5000, 0x135);
            } else {
                func_08015834(0, act->x - 0x400, act->y, act->z - 0x5000, act->x,
                    act->y, act->z - 0x5000, 0x135);
            }
        }

        if (func_080128EC()) {
            work->base.unk_150++;
        } else {
            work->base.unk_150 = 0;
            work->base.unk_170 = 27;
        }
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 9, 0, w->base.tiles);
        }
        func_0800F368(work, 1);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 28;
        } else {
            work->base.unk_150++;
        }
        break;
    case 28:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 10, 1, w->base.tiles);
            m4aSongNumStart(0x2A2);

            if (act->flags & 4) {
                func_08018724(act->x - 0x1000, act->y, act->z - 0x3000, 1, 310);
            } else {
                func_08018724(act->x + 0x1000, act->y, act->z - 0x3000, 0, 310);
            }
        }
        u = (y - act->y) >> 3;
        act->y += u;
        func_0801475C(0, u, 0);

        if (func_080128EC()) {
            work->base.unk_150++;
        } else {
            m4aSongNumStop(0x2A2);
            work->base.unk_150 = 0;
            work->base.unk_170 = 29;
        }
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 11, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 6, 0, w->base.tiles);
            w->unk_188 = 0;
            m4aSongNumStart(0x11B);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 23;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 7, 1, w->base.tiles);

            if (act->flags & 4) {
                func_08015834(1, act->x + 0x400, act->y, act->z - 0x5000, x, y, 0, 0x135);
            } else {
                func_08015834(1, act->x - 0x400, act->y, act->z - 0x5000, x, y, 0, 0x135);
            }
        }

        if (func_080128EC()) {
            work->base.unk_150++;
        } else {
            work->base.unk_150 = 0;
            work->base.unk_170 = 24;
        }
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F498, &w->base.anim, 8, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 30:
        if ((s16)work->base.unk_150 == 0) {
            m4aSongNumStart(0x11D);
            func_08019068(gUnk_0813F498, &w->base.anim, 12, 0, w->base.tiles);
            FadeToAmount(0, gBtlWork->unk_0B3, 8);
            w->unk_188 = 0;
            work->base.unk_158 = 0x400;
        }
        func_08019A30();

        switch ((s16)work->base.unk_150) {
        case 28:
            CreateHumLaxeneKnfTask(w, -38, -11);
            break;
        case 32:
            CreateHumLaxeneKnfTask(w, -37, -25);
            break;
        case 36:
            CreateHumLaxeneKnfTask(w, -32, -38);
            break;
        case 44:
            CreateHumLaxeneKnfTask(w, -36, -18);
            break;
        case 48:
            CreateHumLaxeneKnfTask(w, -35, -32);
            break;
        case 52:
            CreateHumLaxeneKnfTask(w, -30, -45);
            break;
        }

        if ((s16)work->base.unk_150 > 120) {
            FadeToOriginal(0, 8);
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);

            if ((s16)work->base.unk_152 == 0) {
                func_08019068(gUnk_0813F498, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813F498, &w->base.anim, 4, 0, w->base.tiles);
            }
            w->unk_188 = 0;
            w->flags &= ~1;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                d = 13;
                break;
            case 3:
                d = -1;
                break;
            case 4:
                d = -4;
                break;
            case 5:
                d = -3;
                break;
            case 9:
                d = -2;
                break;
            case 10:
                d = -3;
                break;
            default:
                d = 0;
                break;
            }

            if (act->flags & 4) {
                act->x -= d << 8;
            } else {
                act->x += d << 8;
            }
        }

        if (act->flags & 4) {
            s32 v = act->x - 0x1000;
            act->x += (x - v) >> 4;
        } else {
            s32 v = act->x + 0x1000;
            act->x += (x - v) >> 4;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(0x131, act->x - 0x1800, act->y, act->z, 8, 24, 50)
                    : func_08011F78(0x131, act->x + 0x1800, act->y, act->z, 8, 24, 50)) {
                    m4aSongNumStart(0x2A3);
                    w->flags |= 1;
                }
                break;
            case 8:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(0x132, act->x - 0x1000, act->y, act->z, 16, 24, 50)
                    : func_08011F78(0x132, act->x + 0x1000, act->y, act->z, 16, 24, 50)) {
                    m4aSongNumStart(0x2A3);
                    w->flags |= 1;
                }
                break;
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;

            if ((s16)work->base.unk_152 <= 0 && (w->flags & 1)) {
                work->base.unk_170 = 21;
                work->base.unk_152++;
            } else {
                func_0801AF08(act);
                work->base.unk_170 = 0;
            }
        } else {
            work->base.unk_150++;
        }
        break;
    case 31:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);

            if ((work->base.unk_152 & 1) == 0) {
                func_08019068(gUnk_0813F498, &w->base.anim, 13, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813F498, &w->base.anim, 14, 0, w->base.tiles);
            }
            w->unk_188 = 0;
            w->flags &= ~1;
            act->unk_014 = act->x;
            work->base.unk_158 = 0x400;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                d = 13;
                break;
            case 3:
                d = -1;
                break;
            case 4:
                d = -4;
                break;
            case 5:
                d = -3;
                break;
            case 9:
                d = -2;
                break;
            case 10:
                d = -3;
                break;
            default:
                d = 0;
                break;
            }

            if (act->flags & 4) {
                act->x -= d << 8;
            } else {
                act->x += d << 8;
            }
        }

        if (act->flags & 4) {
            s32 v = act->x - 0x1000;
            act->x += (x - v) >> 3;
        } else {
            s32 v = act->x + 0x1000;
            act->x += (x - v) >> 3;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(0x131, act->x - 0x1800, act->y, act->z, 8, 24, 50)
                    : func_08011F78(0x131, act->x + 0x1800, act->y, act->z, 8, 24, 50)) {
                    m4aSongNumStart(0x2A3);
                    w->flags |= 1;

                    if ((s16)work->base.unk_152 == 4) {
                        func_08019A30();
                        func_080155BC(x, y, 0, 0x137);
                    }
                }
                break;
            case 8:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(0x132, act->x - 0x1000, act->y, act->z, 16, 24, 50)
                    : func_08011F78(0x132, act->x + 0x1000, act->y, act->z, 16, 24, 50)) {
                    m4aSongNumStart(0x2A3);
                    w->flags |= 1;

                    if ((s16)work->base.unk_152 == 4) {
                        func_08019A30();
                        func_080155BC(x, y, z, 0x137);
                    }
                }
                break;
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;

            if (w->flags & 1) {
                if ((s16)work->base.unk_152 > 3) {
                    func_0801AF08(act);
                    work->base.unk_170 = 0;
                } else {
                    work->base.unk_170 = 31;
                    work->base.unk_152++;
                }
            } else {
                func_0801AF08(act);
                work->base.unk_170 = 0;
            }
        } else {
            work->base.unk_150++;
        }
        break;
    case 32:
        if ((s16)work->base.unk_150 == 0) {
            act->flags ^= 4;

            if (act->flags & 4) {
                s32 t = ((GetRandom() % 57) << 8) + 0x1800;
                act->x = x + t;
            } else {
                s32 t = ((GetRandom() % 57) << 8) + 0x1800;
                act->x = x - t;
            }
            {
                s32 t = ((GetRandom() % 27) << 8) - 0xD00;
                act->y = y + t;
            }
            act->z = 0;
            AnimReset(&work->base.anim);

            if ((GetRandom() & 1) == 0) {
                func_08019068(gUnk_0813F498, &w->base.anim, 13, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813F498, &w->base.anim, 14, 0, w->base.tiles);
            }
            w->unk_188 = 0;
            w->flags &= ~1;
            w->unk_190 = 8;
            work->base.unk_168 = 5;
            work->base.unk_16C = 384;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                d = 13;
                break;
            case 3:
                d = -1;
                break;
            case 4:
                d = -4;
                break;
            case 5:
                d = -3;
                break;
            case 9:
                d = -2;
                break;
            case 10:
                d = -3;
                break;
            default:
                d = 0;
                break;
            }

            if (act->flags & 4) {
                act->x -= d << 8;
            } else {
                act->x += d << 8;
            }
        }

        if (act->flags & 4) {
            s32 v = act->x - 0x1000;
            act->x += (x - v) >> 3;
        } else {
            s32 v = act->x + 0x1000;
            act->x += (x - v) >> 3;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(0x131, act->x - 0x1800, act->y, act->z, 8, 24, 50)
                    : func_08011F78(0x131, act->x + 0x1800, act->y, act->z, 8, 24, 50)) {
                    m4aSongNumStart(0x2A3);
                    w->flags |= 1;
                }
                break;
            case 8:
                func_08019A30();

                if ((act->flags & 4)
                    ? func_08011F78(0x132, act->x - 0x1000, act->y, act->z, 16, 24, 50)
                    : func_08011F78(0x132, act->x + 0x1000, act->y, act->z, 16, 24, 50)) {
                    m4aSongNumStart(0x2A3);
                    w->flags |= 1;
                }
                break;
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_152--;

            if ((s16)work->base.unk_152 > 0) {
                if (GetRandom() % 6 != 0) {
                    work->base.unk_170 = 32;
                } else {
                    work->base.unk_170 = 33;
                }
            } else {
                func_0801AF08(act);
                work->base.unk_170 = 0;
            }
        } else {
            work->base.unk_150++;
        }
        break;
    case 33:
        if ((s16)work->base.unk_150 == 0) {
            m4aSongNumStart(0x11D);
            act->flags ^= 4;

            if (act->flags & 4) {
                s32 t = ((GetRandom() % 41) << 8) + 0x5000;
                act->x = x + t;
            } else {
                s32 t = ((GetRandom() % 41) << 8) + 0x5000;
                act->x = x - t;
            }
            {
                s32 t = ((GetRandom() % 49) << 8) - 0x1800;
                act->y = y + t;
            }
            act->z = 0;
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813F498, &w->base.anim, 12, 0, w->base.tiles);
            FadeToAmount(0, gBtlWork->unk_0B3, 8);
            w->unk_188 = 0;
            work->base.unk_158 = 0x400;
            w->unk_190 = 8;
            work->base.unk_168 = 5;
            work->base.unk_16C = 384;
        }
        func_08019A30();

        switch ((s16)work->base.unk_150) {
        case 28:
            CreateHumLaxeneKnfTask(w, -38, -11);
            break;
        case 32:
            CreateHumLaxeneKnfTask(w, -37, -25);
            break;
        case 36:
            CreateHumLaxeneKnfTask(w, -32, -38);
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            FadeToOriginal(0, 8);
            work->base.unk_150 = 0;
            work->base.unk_152--;

            if ((s16)work->base.unk_152 <= 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
            } else if (GetRandom() & 10) {
                work->base.unk_170 = 32;
            } else {
                work->base.unk_170 = 33;
            }
        } else {
            work->base.unk_150++;
        }
        break;
    }

    if (!(act->flags & 0x2000) && act->unk_0E8 != 2) {
        func_08050EC4(&work->base, w->unk_188);
    }
    TaskPoolUpdate(&w->tasks);

    if ((s16)w->unk_190 > 0) {
        ApproachValue(&work->base.unk_168, 256, w->unk_190);
        ApproachValue(&work->base.unk_16C, 256, w->unk_190);
        w->unk_190--;
    }

    return func_0800E5F0(&work->base);
}

void task_hum_laxene_2(LaxeneWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_hum_laxene_3(LaxeneWork* work) {
    m4aSongNumStop(0x2A2);
    HumReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

void task_hum_laxene_knf_0(LaxeneKnfWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618458, 0x20);
    work->tiles = LoadObjTiles(gUnk_08BD99F4, 0x2C0);
    AnimInit(&work->anim, gUnk_09EE1DB4, gUnk_09EE1DA4);
    AnimStart(&work->anim, 0, 0);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->timer = 0;
    work->unk_2D = 1;
    work->state = 0;
    work->unk_30 = gBtlWork->actor->x;
    work->unk_34 = gBtlWork->actor->y;
    work->unk_38 = gBtlWork->actor->z;
    work->vx = GetRandom() % 897 + 0x800;
    m4aSongNumStart(0x2A4);
}

u8 task_hum_laxene_knf_1(LaxeneKnfWork* work) {
    BtlObj* c;

    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    if (work->unk_2D == 0) {
        return 0;
    }

    switch (work->state) {
    case 0:
        if (func_08011F78(0x133, work->x, work->y, work->z, 1, 6, 2)) {
            m4aSongNumStart(0x2A3);
            work->timer = 0;
            work->state = 1;
            func_08013994(work->x, work->y, work->z + 0x1000);
        } else {
            if (work->unk_2C != 0) {
                work->x = work->x - work->vx;
            } else {
                work->x = work->x + work->vx;
            }
            work->timer++;
        }
        break;
    case 1:
        if ((s16)work->timer == 0) {
            AnimStart(&work->anim, 1, 0);
        }
        c = gBtlWork->actor;
        work->x += c->x - work->unk_30;
        work->y += c->y - work->unk_34;
        work->z += c->z - work->unk_38;

        if ((s16)work->timer > 30) {
            return 0;
        }
        work->timer++;
        break;
    }
    AnimUpdate(&work->anim);
    work->unk_30 = gBtlWork->actor->x;
    work->unk_34 = gBtlWork->actor->y;
    work->unk_38 = gBtlWork->actor->z;
    return 1;
}

void task_hum_laxene_knf_2(LaxeneKnfWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);

    if (work->unk_2C != 0) {
        attr = GetBattleSpritePriorityFlags(work->y);
    } else {
        attr = GetBattleSpritePriorityFlags(work->y) | 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (IsRectOutsideScreen(x, y, 2, 2, 32, 32)) {
        work->unk_2D = 0;
    }
}

void task_hum_laxene_knf_3(LaxeneKnfWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080526A8(HumWork* work, s32 a, s32 b) {
    work->targetX = a;
    work->targetY = b;
    work->unk_170 = 19;
    work->unk_150 = 0;
}

void func_080526D4(AxcelWork* work, s32 a, s32 b, u16 c) {
    work->unk_208 = c;
    work->unk_20C = a;
    work->unk_210 = b;
}

void func_080526F0(HumWork* work, s32 a) {
    BtlObj* act;
    s32 t;

    if (a != 0) {
        act = &work->actor;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 4;
    }
}

void func_0805273C(AxcelWork* work, HumSub* sub) {
    s32 args[3];

    if (GetRandom() % 6 == 0) {
        args[0] = sub->x + (GetRandom() % 29 - 14) * 256;
        args[1] = sub->y + (GetRandom() % 15 - 7) * 256;
        args[2] = sub->z;
        TaskCreate(&work->tasks, &gTaskDescHumAxcelPtc, args);
    }
}

void task_hum_axcel_0(AxcelWork* work) {
    HumInit(&work->base, &gUnk_0813F768);
    HumSubInit(&work->base, &work->sub, &gUnk_0813F760);
    HumSubInit(&work->base, &work->sub2, &gUnk_0813F760);
    work->base.actor.flags |= 0x04000000;
    work->base.unk_184 = gUnk_0813F5C8[0];
    work->flags = 0;
    work->unk_200 = -0x300;
    work->unk_208 = 0;
    work->sub.flags |= 2;
    work->sub2.flags |= 2;
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    TaskPoolInit(&work->tasks, 16);
}

u8 task_hum_axcel_1(AxcelWork* work) {
    AxcelWork* w;
    HumSub* sub;
    HumSub* sub2;
    BtlObj* act;
    s32 x;
    s32 y;

    w = work;
    sub = &work->sub;
    sub2 = &work->sub2;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, 0);
    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        switch ((u32)_0800F84C(work)) {
        case 36:
        case 38:
            work->base.unk_170 = 20;
            work->base.unk_152 = 0;
            break;
        case 37:
        case 39:
            work->base.unk_170 = 22;
            break;
        case 0xF21C8721:
            work->base.unk_170 = 32;
            break;
        case 0xF21CAF21:
            work->base.unk_170 = 26;
            break;
        }
        w->unk_20C = work->base.unk_168 = 0x100;
        w->unk_210 = work->base.unk_16C = 0x100;
        break;
    case 4:
        work->base.flags &= ~32;
#ifdef VERSION_EU
        act->flags &= ~0x2000000ULL;
#endif
        sub->flags |= 2;
        sub2->flags |= 2;
        work->unk_20C = work->base.unk_168 = 0x100;
        work->unk_210 = work->base.unk_16C = 0x100;
        m4aSongNumStop(654);
        break;
    }
    if (gBtlWork->unk_10C == 162) {
        if (func_0800F5A4(&work->base, 20, 40, 40, 24)) {
            work->base.unk_184 = gUnk_0813F5C8[0];
        }
    } else if (func_0800F5A4(&work->base, 5, 40, 40, 24)) {
        if ((u16)GetRandom() % 2) {
            work->base.unk_184 = gUnk_0813F5C8[0];
        } else {
            work->base.unk_184 = gUnk_0813F5C8[1];
        }
    }
    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F5E0, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F5E0, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        func_08019068(gUnk_0813F5E0, &w->base.anim, 0, 1, w->base.tiles);
        w->unk_200 = -0x300;
        if (func_08081828()) {
            break;
        }
        if ((u16)((u16)GetRandom() % 80) == 0) {
            work->base.unk_170 = 8;
            work->base.unk_150 = 0;
            break;
        }
        if (func_0800F4C8(work, 40)) {
            func_080526A8(&w->base, 0x10000, act->y);
            break;
        }
        func_0800F368(work, 8);
        work->base.unk_150++;
        break;
    case 8:
        if ((s16)work->base.unk_150 == 0) {
            work->base.targetX = x + (((u16)((u16)GetRandom() % 201) - 100) << 8);
            work->base.targetY = y + (((u16)((u16)GetRandom() % 65) - 32) << 8);
            work->base.unk_170 = 19;
        }
        break;
    case 1:
        if ((s16)work->base.unk_150 == 0) {
            if (act->btl->unk_0F4 == 18) {
                act->btl->unk_0F8--;
#ifdef VERSION_EU
                w->unk_20C = work->base.unk_168 = 0x100;
                w->unk_210 = work->base.unk_16C = 0x100;
#endif
                act->vx = act->vy = 0;
                work->base.unk_158 = 0;
                act->unk_0E2 = 30;
                work->base.unk_150 = 6;
                break;
            }
        }
    case 3:
    case 9:
    case 11:
    case 14:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_20C = work->base.unk_168 = 0x100;
            w->unk_210 = work->base.unk_16C = 0x100;
        }
        w->unk_200 = 0;
        func_08019068(gUnk_0813F5E0, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 1, 1, w->base.tiles);
            work->base.unk_152 = 10;
        }
        if (act->x < x) {
            work->base.targetX = x - 0x6E00;
        } else {
            work->base.targetX = x + 0x6E00;
        }
        ApproachValueHalfSteps(&act->x, work->base.targetX, (u16)work->base.unk_152);
        work->base.unk_152--;
        func_0800F368(work, 1);
        if ((s16)work->base.unk_152 <= 0) {
            work->base.unk_170 = 23;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 5, 0, w->base.tiles);
            w->unk_200 = 0;
            work->base.targetX = x * 2 - act->x;
            work->base.targetY = y * 2 - act->y;
        }
        func_0800F368(work, 1);
        func_0802F284(act->x, act->y, act->z);
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 24;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 6, 0, w->base.tiles);
            func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 0, 1, w->base.sub->tiles);
            sub->palette2 = work->base.palette;
            sub->flags |= 4;
            sub->flags &= ~2;
            m4aSongNumStart(649);
            if (act->flags & 4) {
                sub->x = act->x - 0x2000;
            } else {
                sub->x = act->x + 0x2000;
            }
            sub->y = act->y;
            sub->z = act->z - 0x2000;
            func_0800F368(work, 1);
            w->unk_204 = 30;
        }
        ApproachValue(&sub->x, work->base.targetX, w->unk_204);
        ApproachValue(&sub->y, work->base.targetY, w->unk_204);
        w->unk_204--;
        func_0802F284(sub->x, sub->y, sub->z);
        if (func_08011F78(302, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(559);
        }
        if ((s16)w->unk_204 == 19) {
            func_080526D4(w, 12, 0x200, 8);
        }
        if ((s16)w->unk_204 == 11) {
            act->x = work->base.targetX;
            act->y = work->base.targetY;
            act->flags ^= 4;
            func_080526D4(w, 0x100, 0x100, 8);
        }
        if ((s16)w->unk_204 <= 4) {
            work->base.unk_170 = 25;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 7, 0, w->base.tiles);
            sub->flags |= 2;
            sub->flags &= ~4;
        }
        func_0802F284(act->x, act->y, act->z);
        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 8, 0, w->base.tiles);
            AnimReset(&sub->anim);
            AnimReset(&sub2->anim);
            func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 6, 0, w->base.sub->tiles);
            func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 2, 0, ((HumSub*)w->base.sub2)->tiles);
            sub->palette2 = sub->palette;
            sub->flags &= ~6;
            sub2->flags &= ~6;
            sub->flags |= 1;
            sub2->flags &= ~1;
            w->unk_200 = 0;
        }
        func_0800F368(work, 1);
        work->base.unk_158 = 0;
        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                m4aSongNumStart(650);
                func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 7, 1, w->base.sub->tiles);
                func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 3, 1, ((HumSub*)w->base.sub2)->tiles);
                break;
            case 6:
                m4aSongNumStart(290);
                func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 8, 1, w->base.sub->tiles);
                func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 4, 1, ((HumSub*)w->base.sub2)->tiles);
                break;
            case 7:
                func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 9, 0, w->base.sub->tiles);
                func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 5, 0, ((HumSub*)w->base.sub2)->tiles);
                m4aSongNumStart(651);
                break;
            }
        }
        switch (AnimGetFrame(&work->base.anim)) {
        case 3:
        case 4:
        case 5:
            {
                s32 t = act->z + 0x1000;
                act->z += (act->unk_01C - t) >> 4;
            }
            break;
        case 6:
            if (act->flags & 4) {
                {
                s32 t = act->x - 0x800;
                act->x += (act->unk_014 - t) >> 3;
            }
            } else {
                {
                s32 t = act->x + 0x800;
                act->x += (act->unk_014 - t) >> 3;
            }
            }
            {
                s32 t = act->z + 0x1400;
                act->z += (act->unk_01C - t) >> 3;
            }
            break;
        }
        act->y += (((gBtlWork->unk_0DE + gBtlWork->unk_0E0 + 32) << 7) - act->y) >> 3;
        sub->x = act->x;
        sub->y = act->y;
        sub->z = act->z;
        sub2->x = act->x;
        sub2->y = act->y;
        sub2->z = act->z;
        if (AnimIsFinished(&work->base.anim)) {
            if (act->unk_02C < act->unk_02E / 2) {
                work->base.unk_170 = 31;
            } else if ((x - act->x >= 0) ? x - act->x <= 0x4FFF : act->x - x <= 0x4FFF) {
                work->base.unk_170 = 29;
            } else {
                work->base.unk_170 = 27;
            }
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 27: {
        s32 t;
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 9, 1, w->base.tiles);
            func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 1, 1, w->base.sub->tiles);
            func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 1, 1, ((HumSub*)w->base.sub2)->tiles);
            sub->flags |= 4;
            sub2->flags |= 4;
            if (act->flags & 4) {
                sub->x = act->x - 0x3700;
                sub2->x = act->x - 0x5700;
            } else {
                sub->x = act->x + 0x3700;
                sub2->x = act->x + 0x5700;
            }
            sub->y = act->y + 0xA00;
            sub->z = act->z - 0x1E00;
            sub2->y = act->y - 0xA00;
            sub2->z = act->z - 0x1400;
            w->unk_200 = act->z;
        }
        if (act->flags & 4) {
            s32 d = ((s16)work->base.unk_150 << 9) + 0x5A00;
            t = act->x - d;
        } else {
            s32 d = ((s16)work->base.unk_150 << 9) + 0x5A00;
            t = act->x + d;
        }
        sub->x += (t - sub->x) >> 3;
        sub2->x += (t - sub2->x) >> 3;
        sub->y += (act->y + gSineTable[((u16)work->base.unk_150 * 4) & 255] * 55 - sub->y) >> 2;
        sub2->y += (act->y - gSineTable[((u16)work->base.unk_150 * 4) & 255] * 55 - sub2->y) >> 2;
        {
            s32* ground = &gBtlWork->unk_138;
            {
                s32 t = sub->z + 0x1800;
                sub->z += (*ground - t) >> 2;
            }
            {
                s32 t = sub2->z + 0x1800;
                sub2->z += (*ground - t) >> 3;
            }
        }
        if (func_08011F78(304, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(505);
        }
        if (func_08011F78(304, sub2->x, sub2->y, sub2->z, 8, 8, 2)) {
            m4aSongNumStart(505);
        }
        func_0805273C(w, sub);
        func_0805273C(w, sub2);
        if (sub->x > ((gBtlWork->unk_0DC + 32) << 8) ||
            sub->x < ((gBtlWork->unk_0DA - 32) << 8)) {
            sub->flags |= 2;
            sub2->flags |= 2;
            work->base.unk_150 = 0;
            work->base.unk_170 = 28;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 29: {
        u16 angle;
        s32 dx;
        s32 dy;
        func_0800F368(work, 1);
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 9, 1, w->base.tiles);
            func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 1, 1, w->base.sub->tiles);
            func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 1, 1, ((HumSub*)w->base.sub2)->tiles);
            sub->flags |= 4;
            sub2->flags |= 4;
            if (act->flags & 4) {
                sub->x = act->x - 0x3700;
                sub2->x = act->x - 0x5700;
            } else {
                sub->x = act->x + 0x3700;
                sub2->x = act->x + 0x5700;
            }
            sub->y = act->y + 0xA00;
            sub->z = act->z - 0x1E00;
            sub2->y = act->y - 0xA00;
            sub2->z = act->z - 0x1400;
            w->unk_200 = act->z;
            w->unk_204 = 200;
            w->unk_214 = 0x5A00;
            m4aSongNumStart(651);
        }
        angle = (u16)work->base.unk_150 * 4;
        ApproachValue(&w->unk_214, 0x2800, w->unk_204);
        w->unk_204--;
        dx = gSineTable[angle % 256] * w->unk_214 >> 8;
        dy = -gSineTable[angle % 256 + 64] * w->unk_214 >> 8;
        sub->x += (x + dx - sub->x) >> 4;
        sub->y += (y + dy - sub->y) >> 4;
        sub2->x += (x - dx - sub2->x) >> 4;
        sub2->y += (y - dy - sub2->y) >> 4;
        sub->z += (-0x1800 - sub->z) >> 3;
        sub2->z += (-0x1800 - sub2->z) >> 3;
        if (func_08011F78(304, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(505);
        }
        if (func_08011F78(304, sub2->x, sub2->y, sub2->z, 8, 8, 2)) {
            m4aSongNumStart(505);
        }
        func_0805273C(w, sub);
        func_0805273C(w, sub2);
        if ((s16)w->unk_204 <= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 30;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 30:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_204 = 20;
        }
        if (act->flags & 4) {
            ApproachValue(&sub->x, (gBtlWork->unk_0DA - 32) << 8, w->unk_204);
            ApproachValue(&sub2->x, (gBtlWork->unk_0DA - 32) << 8, w->unk_204);
        } else {
            ApproachValue(&sub->x, (gBtlWork->unk_0DC + 32) << 8, w->unk_204);
            ApproachValue(&sub2->x, (gBtlWork->unk_0DC + 32) << 8, w->unk_204);
        }
        ApproachValue(&sub->z, -0x5A00, w->unk_204);
        ApproachValue(&sub2->z, -0x5A00, w->unk_204);
        w->unk_204--;
        if ((s16)w->unk_204 <= 0) {
            sub->flags |= 2;
            sub2->flags |= 2;
            work->base.unk_150 = 0;
            work->base.unk_170 = 28;
        } else {
            work->base.unk_150++;
        }
        break;
    case 31:
        func_0800F368(work, 1);
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 9, 1, w->base.tiles);
            func_08019068(gUnk_0813F6C0, &w->base.sub->anim, 1, 1, w->base.sub->tiles);
            func_08019068(gUnk_0813F6C0, &((HumSub*)w->base.sub2)->anim, 1, 1, ((HumSub*)w->base.sub2)->tiles);
            sub->flags |= 4;
            sub2->flags |= 4;
            if (act->flags & 4) {
                sub->x = act->x - 0x3700;
                sub2->x = act->x - 0x5700;
            } else {
                sub->x = act->x + 0x3700;
                sub2->x = act->x + 0x5700;
            }
            sub->y = act->y + 0xA00;
            sub->z = act->z - 0x1E00;
            sub2->y = act->y - 0xA00;
            sub2->z = act->z - 0x1400;
            w->unk_200 = act->z;
            w->unk_234 = GetAngle(sub->x, sub->y, x, y);
            w->unk_236 = GetAngle(sub2->x, sub2->y, x, y);
        }
        sub->x += gSineTable[(u8)w->unk_234] * 6;
        sub->y -= gSineTable[(u8)w->unk_234 + 64] * 4;
        sub2->x += gSineTable[(u8)w->unk_236] * 6;
        sub2->y -= gSineTable[(u8)w->unk_236 + 64] * 4;
        sub->z += (-0x1000 - sub->z) >> 3;
        sub2->z += (-0x1000 - sub2->z) >> 3;
        w->unk_234 += 2;
        w->unk_236 -= 2;
        if (ClampBattlePosition(&sub->x, &sub->y, 0, 0)) {
            w->unk_234 += 128;
        }
        if (ClampBattlePosition(&sub2->x, &sub2->y, 0, 0)) {
            w->unk_236 += 128;
        }
        if (func_08011F78(304, sub->x, sub->y, sub->z, 8, 8, 2)) {
            m4aSongNumStart(505);
            w->unk_234 += 128;
        }
        if (func_08011F78(304, sub2->x, sub2->y, sub2->z, 8, 8, 2)) {
            m4aSongNumStart(505);
            w->unk_236 += 128;
        }
        func_0805273C(w, sub);
        func_0805273C(w, sub2);
        if ((s16)work->base.unk_150 > 300) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 30;
        } else {
            work->base.unk_150++;
        }
        break;
    case 28:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 10, 0, w->base.tiles);
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 == 0) {
            m4aSongNumStart(291);
            func_08019068(gUnk_0813F5E0, &w->base.anim, 3, 0, w->base.tiles);
            w->unk_200 = 0;
            w->flags &= ~1;
        }
        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
        case 2:
        case 3:
            if (act->flags & 4) {
                s32 t = act->x + 0x3000;
                act->x += (act->unk_014 - t) >> 3;
            } else {
                s32 t = act->x - 0x3000;
                act->x += (act->unk_014 - t) >> 3;
            }
            break;
        }
        if (AnimGetFrame(&work->base.anim) == 2 && work->base.anim.timer == 0) {
            func_08019A30();
            if (act->flags & 4 ?
                func_08011F78(300, act->x - 0x2000, act->y, act->z, 20, 24, 50) :
                func_08011F78(300, act->x + 0x2000, act->y, act->z, 20, 24, 50)) {
                m4aSongNumStart(558);
                w->flags |= 1;
            }
        }
        if (w->flags & 1) {
            work->base.unk_170 = 21;
            work->base.unk_150 = 0;
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 4, 0, w->base.tiles);
            w->unk_200 = 0;
            w->flags &= ~1;
        }
        if (AnimGetFrame(&work->base.anim) == 1) {
            if (act->flags & 4) {
                s32 t = act->x + 0x2800;
                act->x += (act->unk_014 - t) >> 3;
            } else {
                s32 t = act->x - 0x2800;
                act->x += (act->unk_014 - t) >> 3;
            }
        }
        if (AnimGetFrame(&work->base.anim) == 2 && work->base.anim.timer == 0) {
            func_08019A30();
            if (act->flags & 4 ?
                func_08011F78(301, act->x - 0x2000, act->y, act->z, 24, 24, 50) :
                func_08011F78(301, act->x + 0x2000, act->y, act->z, 24, 24, 50)) {
                m4aSongNumStart(558);
                w->flags |= 1;
            }
        }
        if ((s16)work->base.unk_152 <= 1 && (w->flags & 1) && AnimGetFrame(&work->base.anim) > 2) {
            work->base.unk_170 = 20;
            work->base.unk_150 = 0;
            work->base.unk_152++;
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 32:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 11, 0, w->base.tiles);
            w->unk_200 = 0;
            m4aSongNumStart(289);
        }
        func_0800F368(work, 1);
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 33;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 33: {
        s32 a, b, c;
        if ((s16)work->base.unk_150 == 0) {
            FadeToAmount(0, gBtlWork->unk_0B3, 8);
            func_08019068(gUnk_0813F5E0, &w->base.anim, 12, 0, w->base.tiles);
            if (act->flags & 4) {
                func_08017E18(act->x, 1, 303);
            } else {
                func_08017E18(act->x, 0, 303);
            }
            work->base.flags |= 32;
#ifdef VERSION_EU
            act->flags |= 0x2000000ULL;
#endif
            m4aSongNumStart(654);
        }
        if (act->flags & 4) {
            func_0801475C(-76, 0, 0);
        } else {
            func_0801475C(76, 0, 0);
        }
        func_080140C0(&a, &b, &c);
        if (!func_080128EC() || a < ((gBtlWork->unk_0DA - 64) << 8) || a > ((gBtlWork->unk_0DC + 64) << 8)) {
            m4aSongNumStop(654);
            work->base.unk_170 = 34;
            work->base.unk_150 = 0;
            gBtlWork->flags |= 0x400000;
            FadeToOriginal(0, 8);
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 34:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 13, 0, w->base.tiles);
            w->unk_200 = 0;
        }
        if (AnimIsFinished(&work->base.anim)) {
            work->base.flags &= ~32;
#ifdef VERSION_EU
            act->flags &= ~0x2000000ULL;
#endif
            func_0801AF08(act);
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F5E0, &w->base.anim, 0, 1, w->base.tiles);
            func_080526D4(w, 12, 512, 8);
        }
        if ((s16)work->base.unk_150 > 6) {
            if ((s16)work->base.unk_150 == 7) {
                act->x = work->base.targetX;
                act->y = work->base.targetY;
                func_080526D4(w, 256, 256, 8);
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    }
    if (act->unk_0E8 != 2) {
        func_080526F0(&work->base, w->unk_200);
    }
    if ((s16)w->unk_208 > 0) {
        ApproachValue(&work->base.unk_168, w->unk_20C, w->unk_208);
        ApproachValue(&work->base.unk_16C, w->unk_210, w->unk_208);
        w->unk_208--;
    }
    TaskPoolUpdate(&w->tasks);
    return func_0800E5F0(&work->base);
}

void func_08054100(AxcelWork* work, HumSub* sub) {
    s16 x;
    s16 y;
    s32 affine;
    s32 scale;
    s32 f;

    if ((sub->flags & 2) == 0) {
        if (sub->z >= 0) {
            affine = 0;
        } else {
            scale = 0x100 - (-sub->z) / 128;
            if (scale <= 127) {
                scale = 128;
            }
            f = 0;

            if (scale > 0x100) {
                f = 1;
            }
            affine = AllocObjAffine(0, scale, scale, f);
        }
        WorldToScreen(&x, &y, sub->x, sub->y, 0);
        DrawSprite(x, y, gUnk_08B22BA8, work->tiles, work->palette, affine, 0x800, 0xFFFE);
    }
}

void task_hum_axcel_2(AxcelWork* work) {
    func_0800EFE8(&work->base);
    func_08054100(work, &work->sub);
    func_08054100(work, &work->sub2);
    TaskPoolDraw(&work->tasks);
}

void task_hum_axcel_3(AxcelWork* work) {
    m4aSongNumStop(0x28E);
    TaskPoolDestroy(&work->tasks);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    HumReleaseResources(&work->base);
}

void task_hum_axcel_ptc_0(AxcelPtcWork* work, s32* args) {
    work->x = args[0];
    work->y = args[1];
    work->z = args[2];
    work->tiles = LoadObjTiles(gUnk_08BF73C6, 0x300);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->anim, gUnk_09EE1FC0, gUnk_09EE1F90);

    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->anim, 0, 0);
        break;
    case 1:
        AnimStart(&work->anim, 1, 0);
        break;
    case 2:
        AnimStart(&work->anim, 2, 0);
        break;
    }
}

u8 task_hum_axcel_ptc_1(AxcelPtcWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_hum_axcel_ptc_2(AxcelPtcWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0,
        GetBattleSpritePriorityFlags(work->y), -0x1004 - (work->y >> 8) * 4);
}

void task_hum_axcel_ptc_3(AxcelPtcWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_08054334(VixenWork* work) {
    VixenSub* p;
    s32 i;

    m4aSongNumStart(0x287);
    p = work->sub;

    for (i = 0; i < 3; i++) {
        p[i].unk_00 = p[i].unk_01 = 1;
        p[i].x = (gBtlWork->unk_0DA + 32 +
            GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA - 0x3F)) << 8;
        p[i].y = (gBtlWork->unk_0DE + 16 +
            GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE - 0x1F)) << 8;
    }
}

void func_080543B4(VixenWork* work) {
    VixenSub* p;
    s32 i;
    u8 z;

    z = 0;
    p = work->sub;

    for (i = 0; i < 3; i++) {
        p->unk_01 = z;
        p->unk_00 = z;
        TaskCreate(&work->tasks, &gTaskDescHumVixenIce, &work->sub[i]);
        p++;
    }
}

void func_080543F4(HumWork* work, s32 a) {
    BtlObj* act;
    s32 t;

    if (a != 0) {
        act = &work->actor;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 4;
    }
}

void task_hum_vixen_0(VixenWork* work) {
    HumInit(&work->base, &gUnk_0813F8C8);
    work->unk_188 = 0;
    work->base.actor.flags |= 0x08000000;
    work->flags = 0;
    TaskPoolInit(&work->tasks, 15);
    func_080543B4(work);
    work->base.unk_184 = gUnk_0813F7A8;

    if (gGameState.flags & 8) {
        gBtlWork->tiles2 = AllocObjTiles(0x840, 0);
    }
}

u8 task_hum_vixen_1(VixenWork* work) {
    VixenWork* w;
    BtlObj* act;
    VixenNdlArgs args;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    u8 ang;
    s32 d;
    s32 v;
    s32 cx;
    s32 ax;
    u16 t;
    u8 r;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, &z);

    switch ((u32)_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;

        switch ((u32)_0800F84C(work)) {
        case 36:
        case 38:
            w->base.unk_170 = 22;
            break;
        case 37:
        case 39:
            w->base.unk_170 = 21;
            break;
        case 0xF53D7753:
            work->base.unk_170 = 33;
            break;
        case 0xF53D4F5D:
            work->base.unk_170 = 28;
            break;
        case 0xF5DD4F53:
            work->base.unk_170 = 29;
            break;
        case 0xF53D4F53:
            work->base.unk_170 = 23;
            break;
        }
        break;
    case 4:
        m4aSongNumStop(0x288);
        break;
    case 3:
    case 8:
        if (act->btl->unk_0F4 == 27) {
            w->base.unk_170 = 37;
            w->base.unk_150 = 0;
        }
        break;
    }

    switch ((u32)gBtlWork->unk_10C) {
    case 164:
        if (func_0800F5A4(w, 30, 40, 40, 24)) {
            w->base.unk_184 = gUnk_0813F7A8;
        }
        break;
    case 175:
        if (func_0800F5A4(w, 5, 40, 40, 24)) {
            switch (GetRandom() % 3) {
            case 0:
                w->base.unk_184 = gUnk_0813F7A8;
                break;
            case 1:
                w->base.unk_184 = gUnk_0813F7C0;
                break;
            case 2:
                w->base.unk_184 = gUnk_0813F7CC;
                break;
            }
        }
        break;
    case 176:
    default:
        if (func_0800F5A4(w, 30, 40, 40, 24)) {
            switch (GetRandom() % 3) {
            case 0:
                w->base.unk_184 = gUnk_0813F7A8;
                break;
            case 1:
                w->base.unk_184 = gUnk_0813F7B4;
                break;
            case 2:
                w->base.unk_184 = gUnk_0813F7CC;
                break;
            }
        }
        break;
    }

    switch (w->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 0, 1, work->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = -0x4000;
        func_0800F368(w, 20);
        break;
    case 0:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = 0;

        if (func_08081828() == 0) {
            func_0800F368(w, 80);

            if (AnimIsFinished(&w->base.anim) && GetRandom() % 80 == 0) {
                w->base.unk_170 = 8;
                w->base.unk_150 = 0;
            } else {
                w->base.unk_150++;
            }
        }
        break;
    case 8:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 1, 1, work->base.tiles);
            work->unk_188 = -0xF00;

            if (act->x <= 0xFFFF) {
                act->flags &= ~4;
                w->base.targetX = (gBtlWork->unk_0DC - 48) << 8;
            } else {
                act->flags |= 4;
                w->base.targetX = (gBtlWork->unk_0DA + 48) << 8;
            }
            work->unk_1C0 = 0;
        }
        work->unk_1C0 += 17;

        if (work->unk_1C0 > 0x199) {
            work->unk_1C0 = 0x199;
        }

        if (act->flags & 4) {
            act->x -= work->unk_1C0;
        } else {
            act->x += work->unk_1C0;
        }

        if (w->base.flags & 1) {
            work->flags ^= 1;
        }

        if (work->flags & 1) {
            act->y += work->unk_1C0;
        } else {
            act->y -= work->unk_1C0;
        }
        d = act->x - (s32)w->base.targetX;

        if ((d >= 0) ? d <= 0xBFF : (s32)w->base.targetX - act->x <= 0xBFF) {
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 1:
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 2, 0, work->base.tiles);
        break;
    case 21:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 3, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimGetFrame(&w->base.anim) == 3) {
            if (act->flags & 4) {
                s32 d = act->x + 0x3200;
                act->x += (act->unk_014 - d) >> 2;
            } else {
                s32 d = act->x - 0x3200;
                act->x += (act->unk_014 - d) >> 2;
            }

            if ((act->flags & 4)
                ? func_08011F78(312, act->x - 0x2000, act->y, act->z, 12, 12, 48)
                : func_08011F78(312, act->x + 0x2000, act->y, act->z, 12, 12, 48)) {
                m4aSongNumStart(0x285);
            }
        }

        if (AnimIsFinished(&w->base.anim)) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 37:
        if ((s16)w->base.unk_150 == 0) {
            AnimReset(&w->base.anim);
            func_08019068(gUnk_0813F7D8, &work->base.anim, 2, 0, work->base.tiles);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.flags &= ~4;
            act->btl->unk_0F8--;
            v = 0;
            act->unk_02C = act->unk_02E / 4;
            act->flags &= ~0x100;
            func_0801AF08(act);
            func_08019190(act, 10);
            w->base.unk_170 = v;
            w->base.unk_150 = v;
        } else {
            w->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimGetFrame(&w->base.anim) == 3 && w->base.anim.timer == 0) {
            if (act->flags & 4) {
                func_08013308(1, act->x - 0x3700, act->y, act->z - 0x4000,
                    act->x - 0x6E00, act->y, -0x1400, 1, 0x139);
            } else {
                func_08013308(1, act->x + 0x3700, act->y, act->z - 0x4000,
                    act->x + 0x6E00, act->y, -0x1400, 0, 0x139);
            }
        }

        if (AnimIsFinished(&w->base.anim) && func_080128EC() == 0) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 5, 0, work->base.tiles);
            work->unk_188 = 0;
            work->unk_1BC = 0;
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 24;
        } else {
            w->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 6, 1, work->base.tiles);
        }

        if ((s16)w->base.unk_150 > 60) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 25;
        } else {
            w->base.unk_150++;
        }
        break;
    case 25:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 7, 0, work->base.tiles);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 26;
        } else {
            w->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);

            if (act->flags & 4) {
                work->unk_198 = act->x - 0x2000;
                work->angle = 192;
            } else {
                work->unk_198 = act->x + 0x2000;
                work->angle = 64;
            }
            work->unk_19C = act->y;
            m4aSongNumStart(276);
            InitObjTilesAtSlot(&work->unk_1E8, *(u16*)((u8*)gBtlWork->tiles2 + 6), gUnk_08EE3A84, 0x7E0);
        }

        if (AnimGetFrame(&w->base.anim) > 2) {
            ang = GetAngle(work->unk_198, work->unk_19C, x, y);
            ApproachAngle(&work->angle, ang, 3);
            s = abs(gSineTable[((u16)w->base.unk_150 * 2) & 0xFF]);
            s += 384;
            work->unk_198 += (gSineTable[(u8)work->angle] * s) >> 8;
            work->unk_19C += (-gSineTable[(u8)work->angle + 64] * s) >> 8;
            ClampBattlePosition(&work->unk_198, &work->unk_19C, 0, 0);
            func_0800F368(w, 1);

            if ((s16)w->base.unk_150 % 9 == 0) {
                args.x = work->unk_198;
                args.y = work->unk_19C;
                args.z = 0;
                args.unk_12 = work->unk_1BC % 8;
                args.unk_18 = &work->unk_1E8;
                work->unk_1BC++;
                TaskCreate(&work->tasks, &gTaskDescHumVixenNdl, &args);
            }
        }

        if ((s16)w->base.unk_150 > 360 || (gBtlWork->actor->flags & 0x2000)) {
            w->base.unk_170 = 27;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 27:
        if ((s16)w->base.unk_150 > 70) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 28:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 8, 0, work->base.tiles);
            work->unk_188 = 0;
            FadeToAmount(0, *((u8*)gBtlWork + 0xB3), 8);
        }

        if (AnimGetFrame(&w->base.anim) > 4 && func_080128EC() == 0) {
            m4aSongNumStart(0x115);
            m4aSongNumStart(0x288);
            func_080171FC(9999);
        }

        if ((s16)w->base.unk_150 % 15 == 0) {
            t = gBtlWork->actor->unk_02C;

            if ((s16)t > 1) {
                gBtlWork->actor->unk_02C = t - 1;
            }
        }

        if ((s16)w->base.unk_150 > 300 ||
            ((s16)w->base.unk_150 > 120 && (s16)gBtlWork->actor->unk_02C <= 1)) {
            m4aSongNumStop(0x288);
            FadeToOriginal(0, 8);
            gBtlWork->flags |= 0x400000;
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 29:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 9, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 30;
        } else {
            w->base.unk_150++;
        }
        break;
    case 30:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 10, 1, work->base.tiles);
        }

        if ((s16)w->base.unk_150 > 60) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 31;
        } else {
            w->base.unk_150++;
        }
        break;
    case 31:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 11, 0, work->base.tiles);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 32;
        } else {
            w->base.unk_150++;
        }
        break;
    case 32:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);
        }

        if (AnimGetFrame(&w->base.anim) == 3 && w->base.anim.timer == 0) {
            FadeStartIn(1, 60);
            func_08054334(work);
        }

        if (AnimIsFinished(&w->base.anim) && FadeIsActive() == 0) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 33:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 12, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 34;
        } else {
            w->base.unk_150++;
        }
        break;
    case 34:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 13, 1, work->base.tiles);
        }

        if ((s16)w->base.unk_150 > 60) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 35;
        } else {
            w->base.unk_150++;
        }
        break;
    case 35:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 14, 0, work->base.tiles);
            m4aSongNumStart(0x113);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 36;
        } else {
            w->base.unk_150++;
        }
        break;
    case 36:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);
            work->task = 0;
        }

        if (AnimGetFrame(&w->base.anim) == 3 && w->base.anim.timer == 0) {
            args.x = x;
            args.y = y;
            args.z = 0;
            work->task = TaskCreate(&work->tasks, &gTaskDescHumVixenFrz, &args);
        }

        if (AnimIsFinished(&w->base.anim) &&
            IsTaskActiveNamed(work->task, gTaskDescHumVixenFrz.name) == 0) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    }

    if (!(act->flags & 0x2000) && act->unk_0E8 != 2) {
        func_080543F4(&w->base, work->unk_188);
    }
    r = func_0800E5F0(&w->base);
    cx = gBtlWork->actor->x;
    ax = act->x;

    if ((cx < ax && (act->flags & 4)) || (cx > ax && !(act->flags & 4))) {
        act->flags |= 0x8000;
    } else {
        act->flags &= ~0x8000;
    }
    TaskPoolUpdate(&work->tasks);
    return r;
}

void task_hum_vixen_2(VixenWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_hum_vixen_3(VixenWork* work) {
    if (gGameState.flags & 8) {
        ReleaseObjTiles(gBtlWork->tiles2);
    }
    HumReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

void task_hum_vixen_ndl_0(VixenNdlWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->tiles = args->unk_18;
    AnimInit(&work->anim, gUnk_09EE26B0, gUnk_09EE2690);
    AnimStart(&work->anim, 0, 0);
    work->unk_2C = args->unk_12;
    work->x = args->x;
    work->y = args->y + (GetRandom() % 11 - 5) * 256;
    work->z = args->z;
    work->unk_2D = 0;
    m4aSongNumStart(0x286);

    if ((GetRandom() & 1) != 0) {
        work->unk_2E = 1;
    } else {
        work->unk_2E = 0;
    }
}

u8 task_hum_vixen_ndl_1(VixenNdlWork* work) {
    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    if (AnimIsFinished(&work->anim)) {
        return 0;
    }

    switch (AnimGetFrame(&work->anim)) {
    case 1:
    case 2:
        if (work->unk_2D == 0) {
            if (gFrameCounter % 8 == work->unk_2C) {
                func_08011F78(0x13A, work->x, work->y, 0, 4, 4, 16);
            }
        }
        break;
    }

    if (gBtlWork->actor->flags & 0x2000) {
        work->unk_2D = 1;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_ndl_2(VixenNdlWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);
    attr = GetBattleSpritePriorityFlags(work->y);

    if (work->unk_2E != 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_vixen_ndl_3(VixenNdlWork* work) {
    ReleaseObjPalette(work->palette);
}

void task_hum_vixen_ice_0(VixenIceWork* work, VixenSub* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->tiles = LoadObjTiles(gUnk_08EE4264, 0x800);
    work->sub = args;
    work->state = 3;
    AnimInit(&work->anim, gUnk_09EE26CC, gUnk_09EE26B4);
    AnimStart(&work->anim, 0, 0);
    ColliderInit(&work->collider, 12, 27, 1);
    ColliderSetDisabled(&work->collider, 1);
}

u8 task_hum_vixen_ice_1(VixenIceWork* work) {
    if (work->sub->unk_01 == 0) {
        if (work->sub->unk_00 != 0) {
            FadeSetPaletteExcluded(((ObjPalette*)work->palette)->index + 16, 1);
            work->sub->unk_00 = 0;
            ColliderSetDisabled(&work->collider, 1);
        }
        return 1;
    }

    if (work->sub->unk_00 != 0) {
        FadeSetPaletteExcluded(((ObjPalette*)work->palette)->index + 16, 0);
        work->sub->unk_00 = 0;
        work->state = 0;
        work->unk_84 = 0;
        work->unk_8C = 10;

        switch (GetRandom() % 3) {
        case 0:
            work->unk_90 = 0x100;
            break;
        case 1:
            work->unk_90 = 0xC0;
            break;
        case 2:
            work->unk_90 = 0x80;
            break;
        }
    }

    switch (work->state) {
    case 0:
        if (work->unk_84 == 0) {
            work->unk_86 = 30;
            work->unk_84++;
        }
        ApproachValue(&work->unk_8C, work->unk_90, work->unk_86);
        work->unk_86--;
        if ((s16)work->unk_86 <= 0) {
            ColliderSetDisabled(&work->collider, 0);
            work->state = 1;
            work->unk_84 = 0;
            work->unk_88 = GetRandom() % 0x259 + 600;
        }
        break;
    case 1:
        if (work->unk_84 == 0) {
            AnimStart(&work->anim, 0, 0);
            work->unk_84++;
        }

        if (GetRandom() % 300 == 0) {
            work->state = 2;
            work->unk_84 = 0;
        }
        break;
    case 2:
        if (work->unk_84 == 0) {
            AnimStart(&work->anim, 1, 0);
            work->unk_84++;
        }

        if (AnimIsFinished(&work->anim)) {
            work->state = 1;
            work->unk_84 = 0;
        }
        break;
    }

    switch (work->state) {
    case 1:
    case 2:
        ApproachValue(&work->unk_8C, 10, work->unk_88);
        work->unk_88--;
        if ((s16)work->unk_88 <= 0) {
            work->sub->unk_01 = 0;
            work->sub->unk_00 = 1;
        }
        ColliderSetRadius(&work->collider, work->unk_8C * 27 >> 8);
        ColliderSetPosition(&work->collider, work->sub->x, work->sub->y, 0);
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_ice_2(VixenIceWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 s;
    s32 affine;

    if (work->sub->unk_01 != 0) {
        gfx = AnimGetGfx(&work->anim);
        WorldToScreen(&x, &y, work->sub->x, work->sub->y, 0);
        s = work->unk_8C * gBtlWork->unk_024 >> 8;
        if (gBtlWork->unk_018 != 0 || s > 0x100) {
            affine = AllocObjAffine(gBtlWork->unk_018, s, s, 1);
        } else {
            affine = AllocObjAffine(gBtlWork->unk_018, s, s, 0);
        }
        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, 0x800, 0xFFFF);
    }
}

void task_hum_vixen_ice_3(VixenIceWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(&work->collider);
}

void task_hum_vixen_frz_0(VixenFrzWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->tiles = gBtlWork->tiles2;

    if (gGameState.flags & 8) {
        if (gBtlWork->flags & 0x800000000000) {
            work->unk_32 = 2;
        } else {
            work->unk_32 = 1;
        }
    } else {
        work->unk_32 = 0;
    }
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813F91C, &work->anim, 0, 0, work->tiles);
    work->unk_2C = 0;

    if (gBtlWork->actor->flags & 4) {
        work->unk_34 = 0;
    } else {
        work->unk_34 = 1;
    }
    m4aSongNumStart(0x1FE);
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
}

u8 task_hum_vixen_frz_1(VixenFrzWork* work) {
    VixenNdlArgs args;
    VixenNdlArgs args2;

    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    switch (work->unk_2C) {
    case 1:
        if (work->timer == 0) {
            switch (work->unk_32) {
            case 0:
                func_08019068(gUnk_0813F91C, &work->anim, 2, 0, work->tiles);
                break;
            case 1:
                func_08019068(gUnk_0813F91C, &work->anim, 7, 0, work->tiles);
                break;
            case 2:
                func_08019068(gUnk_0813F91C, &work->anim, 10, 0, work->tiles);
                break;
            }
        }
        work->x = gBtlWork->actor->x;
        work->y = gBtlWork->actor->y;
        work->z = gBtlWork->actor->z;

        if (AnimIsFinished(&work->anim)) {
            work->unk_2C = 2;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 2:
        if (work->timer == 0) {
            switch (work->unk_32) {
            case 0:
                func_08019068(gUnk_0813F91C, &work->anim, 4, 0, work->tiles);
                break;
            case 1:
                func_08019068(gUnk_0813F91C, &work->anim, 8, 0, work->tiles);
                break;
            case 2:
                func_08019068(gUnk_0813F91C, &work->anim, 11, 0, work->tiles);
                break;
            }
        }
        work->x = gBtlWork->actor->x;
        work->y = gBtlWork->actor->y;
        work->z = gBtlWork->actor->z;

        if (gBtlWork->flags & 0x100000) {
            work->unk_2C = 3;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 3:
        if (work->timer == 0) {
            switch (work->unk_32) {
            case 0:
                func_08019068(gUnk_0813F91C, &work->anim, 6, 0, work->tiles);
                break;
            case 1:
                func_08019068(gUnk_0813F91C, &work->anim, 9, 0, work->tiles);
                break;
            case 2:
                func_08019068(gUnk_0813F91C, &work->anim, 12, 0, work->tiles);
                break;
            }
        }
        work->x = gBtlWork->actor->x;
        work->y = gBtlWork->actor->y;
        work->z = gBtlWork->actor->z;

        if (AnimIsFinished(&work->anim)) {
            args.x = work->x;
            args.y = work->y;
            args.z = work->z;
            TaskCreate(&gBtlWork->taskPools[0], &gTaskDescHumVixenFrg, &args);
            work->unk_2C = 6;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 0:
        if (!AnimIsFinished(&work->anim)) {
            break;
        }

        if (func_08011E3C(work->x, work->y, work->z, 8, 8, 1)) {
            gBtlWork->actor->x = work->x;
            gBtlWork->actor->y = work->y;
            gBtlWork->actor->z = work->z;
            gBtlWork->actor->flags |= 0x100000000200;
            work->unk_2C = 1;
            gBtlWork->flags &= ~0x100000;
            work->timer = 0;
        } else {
            work->unk_2C = 4;
            work->timer = 0;
        }
        break;
    case 4:
        if (work->timer == 0) {
            func_08019068(gUnk_0813F91C, &work->anim, 1, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_2C = 5;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 5:
        if (work->timer == 0) {
            func_08019068(gUnk_0813F91C, &work->anim, 5, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim)) {
            args2.x = work->x;
            args2.y = work->y;
            args2.z = work->z;
            TaskCreate(&gBtlWork->taskPools[0], &gTaskDescHumVixenFrg, &args2);
            work->unk_2C = 6;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 6:
        if (work->timer > 80) {
            return 0;
        }
        work->timer++;
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_frz_2(VixenFrzWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    if (work->unk_2C != 6) {
        gfx = AnimGetGfx(&work->anim);
        attr = GetBattleSpritePriorityFlags(work->y) | work->unk_34;
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
            -0x1004 - (work->y >> 8) * 4);
    }
}

void task_hum_vixen_frz_3(VixenFrzWork* work) {
    ReleaseObjPalette(work->palette);
}

void task_hum_vixen_frg_0(VixenFrgWork* work, VixenNdlArgs* args) {
    VixenFrgSub* e;
    s32 i;
    s32 a;
    s32 b;

    InitObjTilesAtSlot(work, ((ObjTiles*)gBtlWork->tiles2)->index, gUnk_08C1E78C, 0x4C0);
    work->tiles = work;
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_38 = 0;
    work->unk_21C = 0;

    for (i = 0; i < 15; i++) {
        const VixenFrgDef* d = &gVixenFrgDefs[i];
        e = &work->sub[i];
        e->x = args->x + (d->unk_00 << 8);
        e->y = args->y;
        e->z = args->z + (d->unk_02 << 8);
        e->unk_1C = d->unk_06;
        e->gfx = gUnk_09EE218C[d->unk_04];
        e->vz = GetRandom() % 0x401 - 0x500;
        a = (u8)GetRandom();
        b = GetRandom() % 0x380;
        e->vx = gSineTable[a] * b >> 8;
        e->vy = -gSineTable[a + 64] * (b >> 1) >> 8;
    }
    m4aSongNumStart(0x2A0);
}

u8 task_hum_vixen_frg_1(VixenFrgWork* work) {
    VixenFrgSub* e;
    s32 i;

    if (gBtlWork->flags & 0x200000) {
        return 0;
    }

    for (i = 0; i < 15; i++) {
        e = &work->sub[i];
        e->x += e->vx;
        e->y += e->vy;
        e->z += e->vz;
        e->vz += gBtlWork->unk_12C;

        if (e->z > 0) {
            e->z = 0;
            e->vz = -(e->vz >> 1);
            e->vx = e->vx >> 1;
            e->vy = e->vy >> 1;
        }
        ClampBattlePosition(&e->x, &e->y, 0, 0);
    }
    work->unk_38++;
    if (work->unk_38 == 50) {
        work->unk_21C = 1;
    }

    if (work->unk_38 > 70) {
        return 0;
    }
    return 1;
}

void task_hum_vixen_frg_2(VixenFrgWork* work) {
    VixenFrgSub* p;
    s16 x;
    s16 y;
    u16 attr;
    s32 i;

    if (work->unk_21C != 0) {
        if (work->unk_38 & 1) {
            return;
        }
    }
    p = work->sub;

    for (i = 0; i < 15; i++) {
        attr = GetBattleSpritePriorityFlags(p[i].y) | p[i].unk_1C;
        WorldToScreen(&x, &y, p[i].x, p[i].y, p[i].z);
        DrawSprite(x, y, p[i].gfx, work->tiles, work->palette, 0, attr,
            -0x1004 - (p[i].y >> 8) * 4);
    }
}

void task_hum_vixen_frg_3(VixenFrgWork* work) {
    ReleaseObjPalette(work->palette);
}

void func_080560AC(HumWork* work, s32 a) {
    BtlObj* act;
    s32 t;

    if (a != 0) {
        act = &work->actor;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->z += (t - act->z) >> 4;
    }
}

void task_hum_lexceus_0(LexceusWork* work) {
    HumInit(&work->base, &gUnk_0813FB38);
    work->flags = 0;
    work->unk_1C4 = 0;
    work->unk_1CC = 0;
    work->unk_1F8 = 0;
    work->unk_1F0 = 0;
    work->unk_1F4 = 0;
    work->unk_1FC = 0;
    work->base.unk_184 = gUnk_0813FA8C;
    TaskPoolInit(&work->tasks, 3);
}

u8 task_hum_lexceus_1(LexceusWork* work) {
    LexceusWork* w;
    BtlObj* act;
    BtlObj* p;
    VixenNdlArgs a1;
    VixenNdlArgs a2;
    s32 x;
    s32 y;
    s32 z;
    s16 dx;
    s16 dy;

    w = work;
    act = &work->base.actor;
    p = gBtlWork->actor;
    func_0801C700(act, &x, &y, &z);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        work->base.unk_152 = 0;

        switch ((u32)_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 21;
            break;
        case 37:
            work->base.unk_170 = 23;
            break;
        case 38:
        case 39:
            work->base.unk_170 = 27;
            break;
        case 0xF85E3F85:
            work->base.unk_170 = 25;
            break;
        }
        break;
    case 4:
        work->base.unk_168 = work->unk_1D0 = 0x100;
        work->base.unk_16C = work->unk_1D4 = 0x100;
        work->unk_1CC = 0;

        if (work->unk_1F4 != 0) {
            work->unk_1F4 = 0;
            work->unk_1F8 = 420;
        }
        break;
    }
    func_0800F5A4(&work->base, 3, 40, 40, 20);
    w->unk_1C4 = 0;

    switch (work->base.unk_170) {
    case 12:
        func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
    case 18:
        func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (GetRandom() % 80 == 0) {
                work->base.unk_170 = 8;
                work->base.unk_150 = 0;
                break;
            }
        }
        func_0800F368(work, 10);
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813FA98, &w->base.anim, 1, 1, w->base.tiles);
        w->unk_1C4 = -0x1000;
        work->base.targetX = x;
        work->base.targetY = y;

        if (AnimIsFinished(&work->base.anim)) {
            if (func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, 0x100)) {
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        func_0800F368(work, 10);
        work->base.unk_150++;
        break;
    case 1:
        act->vx = act->vy = 0;
        work->base.unk_158 = 0;

        if ((s16)work->base.unk_150 > 5) {
            break;
        }
        work->base.unk_150 = 6;
        act->unk_0E2 = 30;
        break;
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813FA98, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            m4aSongNumStart(0x11E);
            func_08019068(gUnk_0813FA98, &w->base.anim, 7, 0, w->base.tiles);
            gBtlWork->flags &= ~0x100000;
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 2:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2B7);
            }
            break;
        case 3:
            if (work->base.anim.timer == 0) {
                if (act->flags & 4) {
                    a1.x = act->x - 0x2000;
                    a1.unk_12 = 1;
                } else {
                    a1.x = act->x + 0x2000;
                    a1.unk_12 = 0;
                }
                a1.y = act->y;
                a1.z = 0;
                w->task = TaskCreate(&w->tasks, &gTaskDescHumLexRock, &a1);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 26;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FA98, &w->base.anim, 8, 0, w->base.tiles);
            gBtlWork->flags |= 0x100000;
        }

        if (IsTaskActiveNamed(w->task, gTaskDescHumLexRock.name)) {
            break;
        }

        if (!AnimIsFinished(&work->base.anim)) {
            break;
        }
        work->base.unk_150 = 0;
        work->base.unk_170 = 0;
        func_0801AF08(act);
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1C4 = 0;
            func_08019068(gUnk_0813FA98, &w->base.anim, 5, 0, w->base.tiles);
            w->flags &= ~4;
            w->task = 0;
            m4aSongNumStart(0x11F);
        }

        if (AnimGetFrame(&work->base.anim) == 3) {
            if (work->base.anim.timer == 2) {
                if (act->flags & 4) {
                    a1.x = act->x - 0x1800;
                    a1.unk_12 = 1;
                } else {
                    a1.x = act->x + 0x1800;
                    a1.unk_12 = 0;
                }
                a1.y = act->y;
                a1.z = act->z - 0x6000;
                w->flags |= 4;
                w->task = TaskCreate(&w->tasks, &gTaskDescHumLexTmh, &a1);
            }
        }

        if (w->flags & 4) {
            if (IsTaskActiveNamed(w->task, gTaskDescHumLexTmh.name) == 0) {
                work->base.unk_150 = 0;
                work->base.unk_170 = 24;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FA98, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (AnimGetFrame(&work->base.anim) == 2) {
            if (work->base.anim.timer == 10) {
                if (act->flags & 4) {
                    a2.x = act->x - 0x700;
                    a2.unk_12 = 1;
                } else {
                    a2.x = act->x + 0x700;
                    a2.unk_12 = 0;
                }
                a2.y = act->y;
                a2.z = act->z;
                TaskCreate(&w->tasks, &gTaskDescHumLexTmh0, &a2);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1C4 = 0;
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813FA98, &w->base.anim, 3, 0, w->base.tiles);
            w->flags &= ~3;
#ifdef VERSION_EU
            if (act->btl->unk_0F4 == 49) {
                act->btl->unk_0F8--;
            }
#endif
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                dx = 9;
                dy = 0;
                break;
            case 4:
                dx = 13;
                dy = 0;
                break;
            case 5:
                dx = 6;
                dy = 6;
                break;
            case 7:
                dx = -21;
                dy = -6;
                break;
            default:
                dx = 0;
                dy = 0;
                break;
            }

            if (!AnimIsFinished(&work->base.anim)) {
                if (act->flags & 4) {
                    act->x = act->x - (dx << 8);
                } else {
                    act->x = act->x + (dx << 8);
                }
                act->y = act->y + (dy << 8);
            }

            if (work->base.anim.timer == 0) {
                if (AnimGetGfxIndex(&work->base.anim) == 5) {
                    func_08019A30();

                    if ((act->flags & 4)
                        ? func_08011F78(0x144, act->x - 0x3C00, act->y, act->z, 24, 20, 30)
                        : func_08011F78(0x144, act->x + 0x3C00, act->y, act->z, 24, 20, 30)) {
                        m4aSongNumStart(0x2B0);
                        w->flags |= 1;
                    }
                }
            }
        }

        if (w->flags & 1) {
            if (AnimGetFrame(&work->base.anim) == 6) {
                if (work->base.anim.timer == 19) {
                    w->flags |= 2;
                }
            }
        }

        if (w->flags & 2) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 22;
            work->base.unk_152++;
        } else if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            func_0801AF08(act);
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1C4 = 0;
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813FA98, &w->base.anim, 4, 0, w->base.tiles);
            w->flags &= ~1;
#ifdef VERSION_EU
            if (act->btl->unk_0F4 == 49) {
                act->btl->unk_0F8--;
            }
#endif
        }

        if (work->base.anim.timer == 0) {
            if (AnimGetGfxIndex(&work->base.anim) == 1) {
                func_08019A30();

                if (act->btl->unk_0F4 == 49) {
                    if ((act->flags & 4)
                        ? func_08011F78(0x149, act->x - 0x2800, act->y, act->z, 24, 20, 55)
                        : func_08011F78(0x149, act->x + 0x2800, act->y, act->z, 24, 20, 55)) {
                        m4aSongNumStart(0x2B0);
                        w->flags |= 1;
                    }
                } else {
                    if ((act->flags & 4)
                        ? func_08011F78(0x145, act->x - 0x2800, act->y, act->z, 24, 20, 55)
                        : func_08011F78(0x145, act->x + 0x2800, act->y, act->z, 24, 20, 55)) {
                        m4aSongNumStart(0x2B0);
                        w->flags |= 1;
                    }
                }
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (act->flags & 4) {
                act->x = act->x - 0x1900;
            } else {
                act->x = act->x + 0x1900;
            }
            func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);
            work->base.unk_150 = 0;
            func_0801AF08(act);
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FA98, &w->base.anim, 9, 0, w->base.tiles);
            w->unk_1C4 = 0;
            w->unk_200 = gBtlWork->y;
        }

        if (AnimGetFrame(&work->base.anim) == 3) {
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x120);
            }
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0800F368(work, 1);
            break;
        case 5:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2B9);

                if ((act->flags & 4) == 0) {
                    w->unk_1F4 = -0x800;
                } else {
                    w->unk_1F4 = 0x800;
                }
                w->unk_1F8 = 10;

                if (act->flags & 4) {
                    func_0801801C(act->x - 0x3000, act->y + 0xE00, 0, 0x147);
                } else {
                    func_0801801C(act->x + 0x3000, act->y + 0xE00, 0, 0x147);
                }
            }

            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->y2 = w->unk_200 - 0x4000;
            } else {
                gBtlWork->y2 = w->unk_200 + 0x4000;
            }
            break;
        case 6:
            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->y2 = w->unk_200 - 0x3000;
            } else {
                gBtlWork->y2 = w->unk_200 + 0x3000;
            }
            break;
        case 7:
            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->y2 = w->unk_200 - 0x2000;
            } else {
                gBtlWork->y2 = w->unk_200 + 0x2000;
            }
            break;
        case 8:
            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->y2 = w->unk_200 - 0x1000;
            } else {
                gBtlWork->y2 = w->unk_200 + 0x1000;
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            w->unk_1F4 = 0;
            w->unk_1F8 = 420;
        } else {
            work->base.unk_150++;
        }
        break;
    }

    if (!(act->flags & 0x2000)) {
        if (act->unk_0E8 != 2) {
            func_080560AC(&work->base, w->unk_1C4);
        }
    }

    if ((s16)w->unk_1F8 > 0) {
        ApproachValue(&w->unk_1F0, w->unk_1F4, w->unk_1F8);
        w->unk_1F8--;
    }
    gBtlWork->unk_018 = w->unk_1F0 >> 8;

    if (p->z >= p->unk_010 && (s16)p->unk_02C > 0 && p->unk_0E8 != 2 && !(p->flags & 16)) {
        w->unk_1FC += (GetAngleDiff(0, gBtlWork->unk_018) * 64 - w->unk_1FC) >> 4;
        p->x -= w->unk_1FC;
    } else {
        w->unk_1FC = 0;
    }
    TaskPoolUpdate(&w->tasks);
    return func_0800E5F0(&work->base);
}

void task_hum_lexceus_2(LexceusWork* work) {
    func_0800EFE8(&work->base);

    if (work->unk_1CC > 0) {
        ApproachValue(&work->base.unk_168, work->unk_1D0, work->unk_1CC);
        ApproachValue(&work->base.unk_16C, work->unk_1D4, work->unk_1CC);
        work->unk_1CC--;
    }
    TaskPoolDraw(&work->tasks);
}

void task_hum_lexceus_3(LexceusWork* work) {
    HumReleaseResources(&work->base);
    TaskPoolDestroy(&work->tasks);
}

void task_hum_lex_tmh_0(LexTmhWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618478, 0x20);
    work->tiles = AllocObjTiles(0x400, gUnk_08C3724C);
    AnimInit(&work->anim, gUnk_09EE22B0, gUnk_09EE2298);
    AnimStart(&work->anim, 0, 1);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->unk_34 = gBtlWork->unk_130 + (GetRandom() % 65 - 32) * 256;
    work->unk_38 = gBtlWork->unk_134 + (GetRandom() % 33 - 16) * 256;
    work->state = 0;
    work->unk_4A = 0;
    work->unk_2D = 0;
    work->vz = -0x980;
    work->tiles2 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette2 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    m4aSongNumStart(0x2B1);
}

u8 task_hum_lex_tmh_1(LexTmhWork* work) {
    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    if (work->unk_2D != 0) {
        return 0;
    }

    switch (work->state) {
    case 0:
        work->x += (work->unk_34 - work->x) >> 4;
        work->y += (work->unk_38 - work->y) >> 4;
        work->z += work->vz;
        work->vz += 64;

        if (func_08011F78(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(0x2B3);
            work->unk_4A = 0;
            work->state = 1;
        } else if (work->z >= 0) {
            m4aSongNumStart(0x2B2);
            work->unk_4A = 0;
            work->state = 1;
        } else {
            work->unk_4A++;
        }
        break;
    case 1:
        if (work->unk_4A == 0) {
            work->vz = -work->vz >> 1;

            if (gBtlWork->unk_130 < work->x) {
                work->unk_48 = 1;
            } else {
                work->unk_48 = 0;
            }
        }

        if (work->x < (gBtlWork->unk_0DA - 32) << 8 ||
            work->x > (gBtlWork->unk_0DC + 32) << 8) {
            work->unk_2D = 1;
        }

        if (work->unk_48 != 0) {
            work->x += -0x400;
        } else {
            work->x += 0x400;
        }
        work->y += (gBtlWork->unk_134 - work->y) >> 4;
        work->z += work->vz;
        work->vz += 64;

        if (func_08011F78(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(0x2B3);
        }

        if (work->z >= 0) {
            m4aSongNumStart(0x2B2);
            work->vz = -work->vz >> 1;
            work->z = 0;
        }
        work->unk_4A++;
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_lex_tmh_2(LexTmhWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;
    s32 affine;
    s32 scale;

    gfx = AnimGetGfx(&work->anim);

    if (work->unk_2C != 0) {
        attr = GetBattleSpritePriorityFlags(work->y);
    } else {
        attr = GetBattleSpritePriorityFlags(work->y) | 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (work->z >= 0) {
        affine = 0;
    } else {
        scale = 0x100 - (-work->z) / 256;
        if (scale <= 75) {
            scale = 76;
        }
        affine = AllocObjAffine(0, scale, scale, 0);
    }
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B22BA8, work->tiles2, work->palette2, affine, attr, 0xFFF0);
}

void task_hum_lex_tmh_3(LexTmhWork* work) {
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette2);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_lex_tmh0_0(LexTmh0Work* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618478, 0x20);
    work->tiles = AllocObjTiles(0x400, gUnk_08C3151E);
    AnimInit(&work->anim, gUnk_09EE2288, gUnk_09EE2250);
    AnimStart(&work->anim, 2, 1);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->unk_30 = 10;
    work->unk_34 = 21;
    m4aSongNumStart(0x2B4);
}

u8 task_hum_lex_tmh0_1(LexTmh0Work* work) {
    if (gBtlWork->flags & 0x40) {
        ApproachValue(&work->unk_30, 0x100, work->unk_34--);

        if (work->unk_34 > 0) {
            AnimUpdate(&work->anim);
            return 1;
        }
    }
    return 0;
}

void task_hum_lex_tmh0_2(LexTmh0Work* work) {
    void* gfx;
    u16 attr;
    s32 sx;
    s32 h;
    s32 affine;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);
    attr = GetBattleSpritePriorityFlags(work->y);
    h = work->unk_30;
    if (h == 0x100) {
        if (work->unk_2C == 0) {
            attr |= 1;
        }
        sx = h;
    } else {
        if (work->unk_2C != 0) {
            sx = h;
        } else {
            sx = -h;
        }
    }
    affine = AllocObjAffine(0, sx, 0x100, 0);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, attr,
        -0x100C - (work->y >> 8) * 4);
}

void task_hum_lex_tmh0_3(LexTmh0Work* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_lex_rock_0(LexRockWork* work, VixenNdlArgs* args) {
    if (args->unk_12 != 0) {
        work->unk_160 = 1;
    } else {
        work->unk_160 = 0;
    }
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->state = 0;
    work->unk_164 = 0;
    work->tiles = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_2C0 = 0;
}

u8 task_hum_lex_rock_1(LexRockWork* work) {
    s32 i;
    s32 range;
    LexRockSub* e;
    u32 v;

    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    switch (work->state) {
    case 0:
        work->unk_164 = 1;
        work->palette2 = LoadObjPalette(gUnk_08F6DCC4, 0x20);
        work->tiles2[0] = AllocObjTiles(0xDC0, gUnk_08C42BBE);
        AnimInit(&work->anim[0], gUnk_09EE2338, gUnk_09EE230C);
        AnimStart(&work->anim[0], 0, 0);
        work->state++;
        break;
    case 1:
        if (!AnimIsFinished(&work->anim[0])) {
            break;
        }
        work->state++;
        break;
    case 2:
        ReleaseObjTiles(work->tiles2[0]);
        ReleaseObjPalette(work->palette2);
        work->unk_164 = 1;
        work->palette2 = LoadObjPalette(gUnk_08F6DCE4, 0x20);
        work->tiles2[0] = AllocObjTiles(0xDC0, gUnk_08C46790);
        AnimInit(&work->anim[0], gUnk_09EE239C, gUnk_09EE233C);
        AnimStart(&work->anim[0], 0, 0);
        work->z -= 0x4000;
        work->state++;
        break;
    case 3:
        if (gBtlWork->flags & 0x100000) {
            m4aSongNumStart(0x2B8);
            work->state += 2;
        }
        break;
    case 4:
        if (!AnimIsFinished(&work->anim[0])) {
            break;
        }
        work->state++;
        break;
    case 5:
        work->unk_164 = 12;
        ReleaseObjTiles(work->tiles2[0]);

        for (i = 0; i < 12; i++) {
            e = &work->sub[i];
            work->tiles2[i] = AllocObjTiles(0xC0, gUnk_08C46790);
            AnimInit(&work->anim[i], gUnk_09EE239C, gUnk_09EE233C);
            AnimStart(&work->anim[i], GetRandom() % 5 + 2, 3);

            if (work->unk_160 != 0) {
                e->vx = -(GetRandom() % 0x501 + 0x300);
            } else {
                e->vx = GetRandom() % 0x501 + 0x300;
            }
            e->vy = GetRandom() % 0x801 - 0x400;
            e->x = work->x + ((GetRandom() % 17 - 8) << 8);
            e->y = work->y + ((GetRandom() % 17 - 8) << 8);
            e->z = work->z + ((GetRandom() % 17 - 8) << 8);
            e->unk_00 = 0;

            if (GetRandom() % 2) {
                e->vz = -(GetRandom() % 0x701 + 0x100);
            } else {
                e->vz = GetRandom() % 1 + 0x300;
            }
        }
        work->state++;
        work->unk_166 = 0;
        break;
    case 6:
        if (work->unk_2C0 == 0) {
            func_08019A30();

            for (i = 0; i < 12; i++) {
                e = &work->sub[i];
                e->x += e->vx;
                e->y += e->vy;
                e->z += e->vz;
                e->vz += 64;

                if (e->z > 0) {
                    e->z = 0;
                    e->vz = -(e->vz >> 1);
                }
                v = ClampBattlePosition(&e->x, &e->y, 0, 0);

                switch (v) {
                case 3:
                case 4:
                    e->vy = -e->vy;
                    break;
                case 1:
                case 2:
                    e->vx = -e->vx;
                    break;
                }

                if (e->unk_00 == 0) {
                    if (func_08011F78(0x148, e->x, e->y, e->z, 4, 4, 4)) {
                        m4aSongNumStart(0x221);
                        e->unk_00 = 1;
                    }
                }
            }
        }

        if (work->unk_166 == 80) {
            work->unk_2C0 = 1;
        }

        if (work->unk_166 > 100) {
            return 0;
        }
        work->unk_166++;
        break;
    }

    for (i = 0; i < work->unk_164; i++) {
        AnimUpdate(&work->anim[i]);
    }
    return 1;
}

void task_hum_lex_rock_2(LexRockWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;
    s32 i;
    LexRockSub* e;

    if (work->unk_2C0 != 0 && (work->unk_166 & 1)) {
        return;
    }

    if (work->unk_164 == 1) {
        gfx = AnimGetGfx(&work->anim[0]);

        if (work->unk_160 != 0) {
            attr = GetBattleSpritePriorityFlags(work->y);
        } else {
            attr = GetBattleSpritePriorityFlags(work->y) | 1;
        }
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->tiles2[0], work->palette2, 0, attr,
            -0x1006 - (work->y >> 8) * 4);
    } else if (work->unk_164 == 12) {
        for (i = 0; i < work->unk_164; i++) {
            e = &work->sub[i];
            gfx = AnimGetGfx(&work->anim[i]);

            if (work->unk_160 != 0) {
                attr = GetBattleSpritePriorityFlags(e->y);
            } else {
                attr = GetBattleSpritePriorityFlags(e->y) | 1;
            }
            WorldToScreen(&x, &y, e->x, e->y,
                e->z);
            DrawSprite(x, y, gfx, work->tiles2[i], work->palette2, 0, attr,
                -0x1006 - (e->y >> 8) * 4);
            WorldToScreen(&x, &y, e->x, e->y, 0);
            DrawSprite(x, y, gUnk_08B22CBC, work->tiles, work->palette, 0, attr, 0xFFFE);
        }
    }
}

void task_hum_lex_rock_3(LexRockWork* work) {
    s32 i;

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);

    if (work->unk_164 != 0) {
        ReleaseObjPalette(work->palette2);

        for (i = 0; i < work->unk_164; i++) {
            ReleaseObjTiles(work->tiles2[i]);
        }
    }
}

void task_hum_mahluxia_flw_0(MahluxiaFlwWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DC84, 0x20);
    work->tiles = LoadObjTiles(gUnk_08BCB3D8, 0x100);
    work->state = 0;
    work->x = args->x;
    work->y = args->y;
    work->z = args->z;
    work->vx = GetRandom() % 717 - 358;
    work->vz = -(GetRandom() % 539 + 102);
    AnimInit(&work->anim, gUnk_09EE1CB4, gUnk_09EE1C94);
    AnimStart(&work->anim, GetRandom() & 1, 1);
}

u8 task_hum_mahluxia_flw_1(MahluxiaFlwWork* work) {
    switch (work->state) {
    case 0:
        work->x += work->vx;
        work->z += work->vz;
        work->vz += 17;
        if (work->vz > 0x1CC) {
            work->state = 1;
        }
        break;
    case 1:
        work->x += work->vx;
        work->z += work->vz;
        work->vz -= 12;
        if (work->vz < 0) {
            work->vz = GetRandom() % 181 + 204;

            if (work->vx > 0) {
                work->vx = -(GetRandom() % 257 + 128);
            } else {
                work->vx = GetRandom() % 257 + 128;
            }
        }

        if (work->z >= 0) {
            return 0;
        }
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_mahluxia_flw_2(MahluxiaFlwWork* work) {
    s16 x;
    s16 y;
    void* gfx;

    gfx = AnimGetGfx(&work->anim);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, 0x800,
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_mahluxia_flw_3(MahluxiaFlwWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_08057CBC(RikuWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    BtlObj* act = &w->actor;

    if (act->flags & 4) {
        work->base.targetX = act->x - (a << 8);
    } else {
        work->base.targetX = act->x + (a << 8);
    }
    w->targetY = act->y;
    w->unk_170 = 19;
    w->unk_150 = 0;
    work->unk_1C4 = -b;
    work->unk_1C8 = 0;
}

void func_08057D30(RikuWork* work, s32 a, s32 b) {
    work->base.targetX = a;
    work->base.targetY = b;
    work->base.unk_170 = 19;
    work->base.unk_150 = 0;
    work->unk_1C4 = -0x500;
}

u8 func_08057D68(RikuWork* work) {
    s32 v;
    s32 w;
    BtlObj* c;

    c = gBtlWork->actor;

    if (GetRandom() % 30 == 0) {
        func_0801C700(&work->base.actor, &v, &w, 0);
        func_0800F368(work, 1);

        if (func_0800F504(work, 0x100, 0x100, 0x100)) {
            if (gBtlWork->flags & 0x8000) {
                func_08057CBC(work, -99, 0x280);
            } else if (GetRandom() & 1) {
                if (c->flags & 4) {
                    func_08057D30(work, v + 0x2800, w);
                } else {
                    func_08057D30(work, v - 0x2800, w);
                }
            } else {
                func_08057CBC(work, -80, 0x500);
            }
            return 1;
        }
    }
    return 0;
}

void func_08057E2C(RikuWork* work, RikuSpawn* dst) {
    BtlObj* act = &work->base.actor;

    dst->x = act->x;
    dst->y = act->y;
    dst->z = act->z;

    if (act->flags & 4) {
        dst->flags |= 1;
    } else {
        dst->flags &= 0xFFFE;
    }
    dst->anim = work->base.anim;
    dst->unk_28 = *(u32*)work->base.tiles;
    dst->unk_2C = gBtlWork->unk_024;
}

void func_08057E90(RikuWork* work, RikuSpawn* p) {
    BtlObj* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    s32 affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.sub;
    gfx = AnimGetGfx(&p->anim);
    act = &work->base.actor;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(6, 12);
        attr = 0x804;
    } else {
        attr = GetBattleSpritePriorityFlags(act->y);
    }

    if (p->flags & 1) {
        sy = p->unk_2C;
        sx = sy;
    } else if (p->unk_2C == 0x100) {
        sy = p->unk_2C;
        sx = sy;
        attr |= 1;
    } else {
        sx = -gBtlWork->unk_024;
        sy = gBtlWork->unk_024;
    }

    if (sy == 0x100 && sx == sy) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }
    pri = 0xFFF0;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    SetObjTileSource(sub->tiles, p->unk_28);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void task_hum_riku_0(RikuWork* work) {
    HumInit(&work->base, &gUnk_0813FD24);
    HumSubInit(&work->base, &work->sub, &gUnk_0813FD40);
    work->unk_1C4 = 0;
    work->flags = 0;
    work->sub.flags |= 3;
    work->unk_1CC = 0;

    if (gBtlWork->unk_10C != 0xA1) {
        work->base.unk_184 = gUnk_0813FBBC[0];
    }
    func_08057E2C(work, &work->spawns[0]);
    work->spawns[1] = work->spawns[0];
    work->spawns[2] = work->spawns[0];
    work->spawns[3] = work->spawns[0];
    work->spawns[4] = work->spawns[0];
    work->spawns[5] = work->spawns[0];
    work->spawns[6] = work->spawns[0];
    work->spawns[7] = work->spawns[0];
    work->spawns[8] = work->spawns[0];
}

u8 task_hum_riku_1(RikuWork* work) {
    RikuWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &x, &y, &z);
    work->flags &= ~4;
    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        switch ((u32)_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 24;
            break;
        case 37:
            work->base.unk_170 = 22;
            break;
        case 38:
            work->base.unk_170 = 23;
            break;
        case 39:
            work->base.unk_170 = 25;
            break;
        case 0xF0DBE6F9:
            work->base.unk_170 = 29;
            break;
        case 0xF17C0F03:
            work->base.unk_170 = 30;
            break;
        }
        break;
    case 4:
        work->base.flags &= ~8;
        work->base.unk_168 = 256;
        break;
    }
    switch (gBtlWork->unk_10C) {
    case 161:
        func_0800F5A4(&work->base, 20, 40, 40, 20);
        break;
    case 168:
    case 171:
        if (func_0800F5A4(&work->base, 15, 40, 40, 20)) {
            work->base.unk_184 = gUnk_0813FBBC[0];
        }
        break;
    case 169:
        if (func_0800F5A4(&work->base, 10, 40, 40, 20)) {
            work->base.unk_184 = gUnk_0813FBBC[0];
        }
        break;
    case 170:
    case 172:
        if (func_0800F5A4(&work->base, 3, 40, 40, 20)) {
            if ((u16)GetRandom() % 2) {
                work->base.unk_184 = gUnk_0813FBBC[0];
            } else {
                work->base.unk_184 = gUnk_0813FBBC[1];
            }
        }
        break;
    }
    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813FBD4, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813FBD4, &w->base.anim, 0, 3, w->base.tiles);
        if ((gBtlWork->flags & 0x20000000) && func_08057D68(w)) {
            break;
        }
        if ((act->x - x >= 0 ? act->x - x : x - act->x) <= 0x4FFF) {
            if (x < 0x10000) {
                func_08057D30(w, (gBtlWork->unk_0DC - 40) << 8, (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            } else {
                func_08057D30(w, (gBtlWork->unk_0DA + 40) << 8, (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            }
        }
        break;
    case 0:
        func_08019068(gUnk_0813FBD4, &w->base.anim, 0, 1, w->base.tiles);
        if (func_08081828()) {
            break;
        }
        if (AnimIsFinished(&work->base.anim) && (u16)((u16)GetRandom() % 60) == 0) {
            work->base.unk_170 = 8;
            work->base.unk_150 = 0;
            break;
        }
        if (func_0800F4C8(&work->base, 40)) {
            func_08057D30(w, 0x10000, (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            break;
        }
        if (gBtlWork->flags & 0x20000000) {
            if (func_08057D68(w)) {
                break;
            }
        } else {
            func_0800F368(work, 60);
        }
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813FBD4, &w->base.anim, 1, 1, w->base.tiles);
        work->base.targetX = x;
        work->base.targetY = y;
        if (func_0800F3BC(&work->base, work->base.targetX, work->base.targetY, 512) && AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        if ((u16)((u16)GetRandom() % 500) == 0 && (act->x - x >= 0 ? act->x - x : x - act->x) > 70) {
            func_08057D30(w, x, y);
            break;
        }
        if (gBtlWork->flags & 0x20000000) {
            if (func_08057D68(w)) {
                break;
            }
        } else {
            func_0800F368(work, 1);
        }
        work->base.unk_150++;
        break;
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813FBD4, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 1:
        func_08019068(gUnk_0813FBD4, &w->base.anim, 2, 0, w->base.tiles);
        if ((s16)work->base.unk_150 == 3) {
            switch ((s32)(u16)((u16)GetRandom() % 3)) {
            case 0:
                m4aSongNumStart(263);
                break;
            case 1:
                m4aSongNumStart(264);
                break;
            case 2:
            default:
                m4aSongNumStart(265);
                break;
            }
        }
        break;
    case 30:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 14, 0, w->base.tiles);
            m4aSongNumStart(262);
            m4aSongNumStart(625);
            FadeStartOut(9, 80);
        }
        work->base.unk_158 = 0;
        act->z += (-0x2800 - act->z) >> 5;
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 31;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 31: {

        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 15, 0, w->base.tiles);
        }
        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
        case 2:
            work->base.unk_158 -= 179;
            break;
        }
        w->flags |= 4;
        if (act->flags & 4) {
            s32 t = act->x - 0x3000;
            act->x += (act->unk_014 - t) >> 3;
        } else {
            s32 t = act->x + 0x3000;
            act->x += (act->unk_014 - t) >> 3;
        }
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 32;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    case 32:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 16, 0, w->base.tiles);
            work->base.flags |= 8;
        }
        work->base.unk_158 = 0;
        w->flags |= 4;
        if (act->flags & 4) {
            act->x -= 0xC00;
        } else {
            act->x += 0xC00;
        }
        if (act->x < ((gBtlWork->unk_0DA - 48) << 8) ||
            act->x > ((gBtlWork->unk_0DC + 48) << 8)) {
            work->base.unk_170 = 33;
            work->base.unk_150 = 0;
            w->unk_380 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 33:
        if ((s16)work->base.unk_150 == 0) {
            act->flags ^= 4;
            switch ((u16)((u16)GetRandom() % 3)) {
            case 0:
                func_08019068(gUnk_0813FBD4, &w->base.anim, 17, 1, w->base.tiles);
                if (act->flags & 4) {
                    w->unk_1C4 = (u16)((u16)GetRandom() % 17) + 184;
                } else {
                    w->unk_1C4 = (u16)((u16)GetRandom() % 17) + 56;
                }
                act->y = y + (((u16)((u16)GetRandom() % 33) - 16) << 8);
                break;
            case 1:
                func_08019068(gUnk_0813FBD4, &w->base.anim, 18, 1, w->base.tiles);
                if (act->flags & 4) {
                    w->unk_1C4 = (u16)((u16)GetRandom() % 17) + 203;
                } else {
                    w->unk_1C4 = (u16)((u16)GetRandom() % 17) + 37;
                }
                act->y = y + (((u16)((u16)GetRandom() % 17) + 16) << 8);
                break;
            case 2:
                func_08019068(gUnk_0813FBD4, &w->base.anim, 19, 1, w->base.tiles);
                if (act->flags & 4) {
                    w->unk_1C4 = (u16)((u16)GetRandom() % 17) + 165;
                } else {
                    w->unk_1C4 = (u16)((u16)GetRandom() % 17) + 75;
                }
                act->y = y - (((u16)((u16)GetRandom() % 17) + 16) << 8);
                break;
            }
            act->z = -0x1000;
            if (act->flags & 4) {
                act->x = x + 0x6300;
                func_080184C4(act->x, act->y, act->z, 192);
            } else {
                act->x = x - 0x6300;
                func_080184C4(act->x, act->y, act->z, 64);
            }
            m4aSongNumStart(670);
            work->base.unk_152 = 10;
            work->base.unk_168 = 10;
        }
        work->base.unk_158 = 0;
        func_0802F284(gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);
        ApproachValue(&work->base.unk_168, 256, (u16)work->base.unk_152);
        work->base.unk_152--;
        if ((s16)work->base.unk_152 <= 0) {
            work->base.unk_170 = 34;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 34:
        if ((s16)work->base.unk_150 == 0) {
            m4aSongNumStart(671);
            func_08019A30();
        }
        w->flags |= 4;
        act->x += gSineTable[(u8)w->unk_1C4] * 12;
        act->y += -gSineTable[(u8)w->unk_1C4 + 64] * 12;
        if (func_08011F78(295, act->x, act->y, act->z, 24, 16, 24)) {
            m4aSongNumStart(658);
        }
        work->base.unk_158 = 0;
        func_0802F284(gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);
        if ((s16)work->base.unk_150 == 15 && (s16)w->unk_380 > 4) {
            work->base.unk_170 = 35;
            work->base.unk_150 = 0;
        } else if ((s16)work->base.unk_150 > 30) {
            work->base.unk_170 = 33;
            work->base.unk_150 = 0;
            w->unk_380++;
        } else {
            work->base.unk_150++;
        }
        break;
    case 35:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 20, 0, w->base.tiles);
            work->base.unk_152 = 40;
        }
        if ((s16)work->base.unk_152 > 0) {
            ApproachValue(&act->x, act->unk_014, (u16)work->base.unk_152);
            ApproachValue(&act->y, act->unk_018, (u16)work->base.unk_152);
            ApproachValue(&act->z, act->unk_01C, (u16)work->base.unk_152);
            work->base.unk_152--;
            if ((s16)work->base.unk_152 <= 0) {
                func_08018F28(act->x, act->y - 0x2000, 0);
            }
        }
        if (!func_080128EC() && (s16)work->base.unk_152 <= 0 && AnimIsFinished(&work->base.anim)) {
            work->base.flags &= ~8;
            func_0801AF08(act);
            work->base.unk_170 = 0;
            FadeStartIn(9, 30);
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 10, 0, w->base.tiles);
            m4aSongNumStart(261);
        }
        if (work->base.anim.timer == 0) {
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 1:
                work->base.unk_158 = -972;
                break;
            case 4:
                work->base.unk_158 = 0x1000;
                if (act->flags & 4 ?
                    func_08011F78(293, act->x - 0x2000, act->y, act->z, 28, 16, 16) :
                    func_08011F78(293, act->x + 0x2000, act->y, act->z, 28, 16, 16)) {
                    m4aSongNumStart(655);
                }
                break;
            }
        }
        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
        case 2:
        case 3: {

            if (act->flags & 4) {
                s32 t = act->x + 0x3200;
                act->x += (act->unk_014 - t) >> 3;
            } else {
                s32 t = act->x - 0x3200;
                act->x += (act->unk_014 - t) >> 3;
            }
            break;
        }
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 13, 0, w->base.tiles);
            m4aSongNumStart(262);
            w->flags &= ~2;
            func_0800F368(work, 1);
        }
        if (w->flags & 2) {
            BtlObj* p = gBtlWork->actor;
            if (p != 0) {
                s32 follow = 0;
                if (act->flags & 4) {
                    if (p->x < act->x - 0x2000) {
                        follow = 1;
                    }
                } else {
                    if (p->x > act->x + 0x2000) {
                        follow = 1;
                    }
                }
                if (follow) {
                    func_080147A8(p->x, p->y, p->z - ((s16)p->unk_0A2 << 8));
                }
            }
        }
        if (!(w->flags & 2) && work->base.anim.timer == 0) {
            s16 d = 0;
            s32 spawn = 0;
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                d = -10;
                break;
            case 1:
                d = -24;
                break;
            case 4:
                d = 12;
                break;
            case 5:
                d = 15;
                break;
            case 6:
                d = 7;
                spawn = 1;
                break;
            }
            if (act->flags & 4) {
                act->x -= d << 8;
            } else {
                act->x += d << 8;
            }
            if (spawn) {
                w->flags |= 2;
                if (act->flags & 4) {
                    func_08012E44(3, act->x - 0x4A00, act->y, act->z - 0x1800,
                        act->unk_014 - 0xC800, act->unk_018, act->z - 0x1800, 1, 296);
                } else {
                    func_08012E44(3, act->x + 0x4A00, act->y, act->z - 0x1800,
                        act->unk_014 + 0xC800, act->unk_018, act->z - 0x1800, 0, 296);
                }
            }
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 0, 1, w->base.tiles);
        }
        if (AnimIsFinished(&work->base.anim) && !func_080128EC()) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart((u16)GetRandom() % 2 + 259);
        }
        if (work->base.anim.timer == 0) {
            s32 d = 0;
            s32 hit = 0;
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 2:
                d = 4;
                break;
            case 3:
                d = 16;
                hit = 1;
                break;
            case 4:
                d = 5;
                break;
            case 6:
                d = 1;
                break;
            case 7:
                d = 4;
                hit = 1;
                break;
            case 8:
                d = 6;
                break;
            case 9:
            case 10:
                d = 2;
                break;
            }
            if (act->flags & 4) {
                act->x -= d << 8;
            } else {
                act->x += d << 8;
            }
            if (hit) {
                func_08019A30();
                if (act->flags & 4 ?
                    func_08011F78(292, act->x - 0x1400, act->y, act->z, 30, 16, 16) :
                    func_08011F78(292, act->x + 0x1400, act->y, act->z, 30, 16, 16)) {
                    m4aSongNumStart(656);
                }
            }
        }
        switch (AnimGetFrame(&work->base.anim)) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            if (act->flags & 4) {
                act->x -= 256;
            } else {
                act->x += 256;
            }
            break;
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 8, 0, w->base.tiles);
            m4aSongNumStart((u16)GetRandom() % 2 + 259);
        }
        if (AnimGetGfxIndex(&work->base.anim) == 6) {

            w->flags |= 4;
            if (act->flags & 4) {
                s32 t = act->x + 0x5800;
                act->x += (act->unk_014 - t) >> 2;
            } else {
                s32 t = act->x - 0x5800;
                act->x += (act->unk_014 - t) >> 2;
            }
        }
        if (work->base.anim.timer == 0) {
            s16 d = 0;
            s32 hit = 0;
            s32 attack = 290;
            switch (AnimGetGfxIndex(&work->base.anim)) {
            case 1:
                d = 15;
                break;
            case 2:
                d = 5;
                hit = 1;
                attack = 290;
                break;
            case 4:
                d = -5;
                break;
            case 5:
                d = 10;
                break;
            case 6:
                d = 20;
                hit = 1;
                attack = 291;
                break;
            case 7:
                d = -9;
                break;
            case 8:
                d = 6;
                break;
            case 9:
                d = 1;
                break;
            }
            if (act->flags & 4) {
                act->x -= d << 8;
            } else {
                act->x += d << 8;
            }
            if (hit) {
                func_08019A30();
                if (act->flags & 4 ?
                    func_08011F78(attack, act->x - 0x1400, act->y, act->z, 20, 8, 16) :
                    func_08011F78(attack, act->x + 0x1400, act->y, act->z, 20, 8, 16)) {
                    m4aSongNumStart(656);
                    if (attack == 291) {
                        FadeStartIn(2, 45);
                        if (act->flags & 4) {
                            func_08019050(6, 332, act->x - 0x2000, (act->y - 0x1800) + act->z);
                        } else {
                            func_08019050(6, 332, act->x + 0x2000, (act->y - 0x1800) + act->z);
                        }
                    }
                }
            }
        }
        if (work->base.anim.timer == 2 && AnimGetGfxIndex(&work->base.anim) == 6) {
            func_08019050(8, 256, gBtlWork->x2, gBtlWork->y2);
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 25:
        if (act->z < act->unk_010) {
            break;
        }
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 3, 0, w->base.tiles);
            m4aSongNumStart(261);
        }
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 26;
            work->base.unk_158 = -0x600;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26:
        act->x += (x - act->x) >> 4;
        act->y += (y - act->y) >> 4;
        if ((s32)work->base.unk_158 < 0) {
            if ((s32)work->base.unk_158 > -0x200) {
                func_08019068(gUnk_0813FBD4, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813FBD4, &w->base.anim, 4, 0, w->base.tiles);
            }
        } else {
            work->base.unk_150 = 0;
            work->base.unk_170 = 27;
            break;
        }
        work->base.unk_150++;
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 11, 0, w->base.tiles);
            w->flags &= ~1;
        }
        act->x += (x - act->x) >> 4;
        act->y += (y - act->y) >> 4;
        if (AnimGetFrame(&work->base.anim) > 1) {
            if (func_08011F78(294, act->x, act->y, act->z, 10, 10, 4)) {
                m4aSongNumStart(657);
                w->flags |= 1;
            }
        }
        if ((w->flags & 1) || act->z >= act->unk_010) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 28;
        } else {
            work->base.unk_150++;
        }
        break;
    case 28:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 12, 0, w->base.tiles);
            work->base.unk_158 = -0x400;
            if (act->flags & 4) {
                work->base.targetX = act->x + 0x3000;
            } else {
                work->base.targetX = act->x - 0x3000;
            }
        }
        act->x += ((s32)work->base.targetX - act->x) >> 3;
        if (AnimIsFinished(&work->base.anim) && act->z >= act->unk_010) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 3, 0, w->base.tiles);
        }
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 20;
            work->base.unk_158 = w->unk_1C4;
        } else {
            work->base.unk_150++;
        }
        break;
    case 20:
        act->x += ((s32)work->base.targetX - act->x) >> 4;
        act->y += ((s32)work->base.targetY - act->y) >> 4;
        if ((s32)work->base.unk_158 < 0) {
            if ((s32)work->base.unk_158 <= -0x200) {
                func_08019068(gUnk_0813FBD4, &w->base.anim, 4, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813FBD4, &w->base.anim, 5, 0, w->base.tiles);
            }
        } else if ((s32)work->base.unk_158 <= 0x1FF) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 5, 0, w->base.tiles);
        } else {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 6, 0, w->base.tiles);
        }
        if (act->z >= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 21;
            break;
        }
        func_0800F368(&work->base, 1);
        work->base.unk_150++;
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FBD4, &w->base.anim, 7, 0, w->base.tiles);
        }
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }
    return func_0800E5F0(&work->base);
}

void task_hum_riku_2(RikuWork* work) {
    func_0800EFE8(&work->base);

    if ((work->flags & 4) && (work->sub.flags & 2)) {
        switch (work->unk_1CC % 2) {
        case 0:
            func_08057E90(work, &work->spawns[2]);
            break;
        case 1:
            func_08057E90(work, &work->spawns[4]);
            break;
        }
        work->unk_1CC++;
    }
    work->spawns[4] = work->spawns[3];
    work->spawns[3] = work->spawns[2];
    work->spawns[2] = work->spawns[1];
    work->spawns[1] = work->spawns[0];
    func_08057E2C(work, &work->spawns[0]);
}

void task_hum_riku_3(HumWork* work) {
    HumReleaseResources(work);
}

void task_hum_leon_0(LeonWork* work) {
    HumInit(&work->base, &gUnk_0813FDA8);
    work->unk_188 = 0;
    work->unk_18A = 0;
    func_08019068(gUnk_0813FD58, &work->base.anim, 0, 1, work->base.tiles);
    work->unk_18C = gGameState.progression.unk_14;
    work->unk_194 = gGameState.progression.unk_1C;
    gGameState.progression.unk_14 = 0;
    gGameState.progression.unk_1C = 0;
}

u8 task_hum_leon_1(LeonWork* work) {
    LeonWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 z;
    s32 a;
    s32 b;
    s32 c;
    u8 r;

    w = work;
    act = &work->base.actor;
    func_0801C700(act, &a, &b, &c);

    switch (_0800E434(work)) {
    case 4:
        break;
    case 5:
        work->base.unk_170 = 19;
        work->base.unk_150 = 0;
        break;
    }
    func_0800F368(work, 1);

    switch (work->base.unk_170) {
    case 12:
        func_08019068(gUnk_0813FD58, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        if (gBtlWork->flags & 0x20000000000) {
            if (w->unk_18A == 0) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 1, 0, w->base.tiles);
                w->unk_18A = 1;
            } else if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 3, 0, w->base.tiles);
            }
        } else {
            if (w->unk_18A != 0) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 2, 0, w->base.tiles);
                w->unk_18A = 0;
            } else if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 0, 1, w->base.tiles);
            }
        }

        if (gBtlWork->flags & 0x100000) {
            if (gBtlWork->flags & 0x20000000) {
                work->base.unk_170 = 20;
                work->base.unk_150 = 0;
            }
        }
        break;
    case 1:
        if ((s16)work->base.unk_150 == 0) {
            func_0801AF08(act);
            func_08019068(gUnk_0813FD58, &w->base.anim, 4, 0, w->base.tiles);
            work->base.unk_150 = 8;
        }
        break;
    case 2:
        if (gBtlWork->flags & 0x100000) {
            if (gBtlWork->flags & 0x20000000) {
                work->base.unk_170 = 20;
                work->base.unk_150 = 0;
            }
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 > 10) {
            gBtlWork->unk_0EF |= 32;
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 19:
        if ((s16)work->base.unk_150 > 80) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    default:
        func_08019068(gUnk_0813FD58, &w->base.anim, 3, 0, w->base.tiles);
        func_0800F368(work, 1);
        break;
    }

    if ((s16)w->unk_188 > 0) {
        w->unk_188--;
        act->flags |= 0x2000;
    } else {
        act->flags &= ~0x2000;
    }
    x = act->x;
    y = act->y;
    z = act->z;
    r = func_0800E5F0(work);
    act->x = x;
    act->y = y;
    act->z = z;
    return r;
}

void task_hum_leon_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_leon_3(LeonWork* work) {
    gGameState.progression.unk_14 = work->unk_18C;
    gGameState.progression.unk_1C = work->unk_194;
    HumReleaseResources(&work->base);
}

void task_hum_robe_0(RobeWork* work) {
    HumInit(&work->base, &gUnk_0813FDF4);
    work->unk_188 = 1;
    func_08019068(gUnk_0813FDD4, &work->base.anim, 0, 1, work->base.tiles);
}

u8 task_hum_robe_1(RobeWork* work) {
    BtlObj* act = &work->base.actor;
    s32 x;
    s32 y;
    s32 z;
    u8 r;

    if (_0800E434(work) == 1) {
        work->base.unk_150 = 1;
    }

    if (gBtlWork->flags & 0x20000000) {
        if (work->unk_188 == 1) {
            func_08019068(gUnk_0813FDD4, &work->base.anim, 1, 0, work->base.tiles);
            work->unk_188 = 0;
        }
    } else if (AnimIsFinished(&work->base.anim)) {
        func_08019068(gUnk_0813FDD4, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = 1;
    }
    func_0800F368(work, 1);
    x = act->x;
    y = act->y;
    z = act->z;
    r = func_0800E5F0(work);
    act->x = x;
    act->y = y;
    act->z = z;
    return r;
}

void task_hum_robe_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_robe_3(HumWork* work) {
    HumReleaseResources(work);
}

void MakeSaveHeaderData(SaveHeaderData* data, s16 file) {
    s16 i;

    data->flags = 0;

    if (gGameState.flags & 0x20) {
        data->flags = 1;
    }

    if (gGameState.flags & 0x800) {
        data->flags |= 4;

        if (gGameState.flags & 8) {
            data->flags |= 2;
        } else {
            data->flags &= ~2;
        }
    } else if (gGameState.flags & 0x20) {
        data->flags |= 2;
    }

#ifdef VERSION_EU
    data->unk_02 = gLanguage;
#endif

    for (i = 0; i < 4; i++) {
        if (file == i) {
            data->files[i].floor = gGameState.floor;
            data->files[i].world = gGameState.world;
            data->files[i].level = gGameState.progression.level;
            data->files[i].playTime = gGameState.playTime;
        } else {
            data->files[i].floor = gGameState.fileSummaries[i].floor;
            data->files[i].world = gGameState.fileSummaries[i].world;
            data->files[i].level = gGameState.fileSummaries[i].level;
            data->files[i].playTime = gGameState.fileSummaries[i].playTime;
        }
    }
}

void MakeSaveSystem(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, &gGameState.progression.maxHp, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(&save->shared);
    func_080A324C(&save->large);
    func_080C700C(&save->unk_E6C);
    func_080DDEB0(save->unk_E70);
    func_0810962C(&save->unk_EB4);
}

void MakeSaveFileLarge(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, &gGameState.progression.maxHp, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(&save->shared);
    func_080A324C(&save->large);
    func_080C700C(&save->unk_E6C);
    func_080DDEB0(save->unk_E70);
    func_0810962C(&save->unk_EB4);

    if (gGameState.flags & 0x10) {
        gGameState.fileSummaries[1].floor = gGameState.floor;
        gGameState.fileSummaries[1].world = gGameState.world;
        gGameState.fileSummaries[1].level = gGameState.progression.level;
        gGameState.fileSummaries[1].playTime = gGameState.playTime;
    } else {
        gGameState.fileSummaries[0].floor = gGameState.floor;
        gGameState.fileSummaries[0].world = gGameState.world;
        gGameState.fileSummaries[0].level = gGameState.progression.level;
        gGameState.fileSummaries[0].playTime = gGameState.playTime;
    }
}

void MakeSaveFileSmall(SaveFileSmall* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, &gGameState.progression.maxHp, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(&save->shared);
    CopyMapCardInventory(&save->small);

    if (gGameState.flags & 0x10) {
        gGameState.fileSummaries[3].floor = gGameState.floor;
        gGameState.fileSummaries[3].world = gGameState.world;
        gGameState.fileSummaries[3].level = gGameState.progression.level;
        gGameState.fileSummaries[3].playTime = gGameState.playTime;
    } else {
        gGameState.fileSummaries[2].floor = gGameState.floor;
        gGameState.fileSummaries[2].world = gGameState.world;
        gGameState.fileSummaries[2].level = gGameState.progression.level;
        gGameState.fileSummaries[2].playTime = gGameState.playTime;
    }
}

void ApplySaveHeaderData(SaveHeaderData* data) {
    if (SaveRepairHeader() == SAVE_OK) {
        if (data->flags & 1) {
            gGameState.flags |= 0x20;
        }

        if (data->flags & 4) {
            gGameState.flags |= 0x800;
        }

        if (data->flags & 2) {
            gGameState.flags |= 0x200;
        }

#ifdef VERSION_EU
        gLanguage = data->unk_02;
#endif
    }

    if (SaveRepairFileLarge(0) == SAVE_OK) {
        gGameState.fileSummaries[0].floor = data->files[0].floor;
        gGameState.fileSummaries[0].world = data->files[0].world;
        gGameState.fileSummaries[0].level = data->files[0].level;
        gGameState.fileSummaries[0].playTime = data->files[0].playTime;
    } else {
        gGameState.fileSummaries[0].floor = 0;
        gGameState.fileSummaries[0].world = 0;
        gGameState.fileSummaries[0].level = 0;
        gGameState.fileSummaries[0].playTime = 0;
    }

    if (SaveRepairFileLarge(1) == SAVE_OK) {
        gGameState.fileSummaries[1].floor = data->files[1].floor;
        gGameState.fileSummaries[1].world = data->files[1].world;
        gGameState.fileSummaries[1].level = data->files[1].level;
        gGameState.fileSummaries[1].playTime = data->files[1].playTime;
    } else {
        gGameState.fileSummaries[1].floor = 0;
        gGameState.fileSummaries[1].world = 0;
        gGameState.fileSummaries[1].level = 0;
        gGameState.fileSummaries[1].playTime = 0;
    }

    if (SaveRepairFileSmall(0) == SAVE_OK) {
        gGameState.fileSummaries[2].floor = data->files[2].floor;
        gGameState.fileSummaries[2].world = data->files[2].world;
        gGameState.fileSummaries[2].level = data->files[2].level;
        gGameState.fileSummaries[2].playTime = data->files[2].playTime;
    } else {
        gGameState.fileSummaries[2].floor = 0;
        gGameState.fileSummaries[2].world = 0;
        gGameState.fileSummaries[2].level = 0;
        gGameState.fileSummaries[2].playTime = 0;
    }

    if (SaveRepairFileSmall(1) == SAVE_OK) {
        gGameState.fileSummaries[3].floor = data->files[3].floor;
        gGameState.fileSummaries[3].world = data->files[3].world;
        gGameState.fileSummaries[3].level = data->files[3].level;
        gGameState.fileSummaries[3].playTime = data->files[3].playTime;
    } else {
        gGameState.fileSummaries[3].floor = 0;
        gGameState.fileSummaries[3].world = 0;
        gGameState.fileSummaries[3].level = 0;
        gGameState.fileSummaries[3].playTime = 0;
    }
}

void ApplySaveSystem(SaveFileLarge* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(&gGameState.progression.maxHp, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(&save->shared);
    func_080A32DC(&save->large);
    func_080C7024(&save->unk_E6C);
    func_080DDEBC(save->unk_E70);
    func_08109638(&save->unk_EB4);
}

void ApplySaveFileLarge(SaveFileLarge* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(&gGameState.progression.maxHp, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(&save->shared);
    func_080A32DC(&save->large);
    func_080C7024(&save->unk_E6C);
    func_080DDEBC(save->unk_E70);
    func_08109638(&save->unk_EB4);
    gGameState.flags &= ~8;
}

void ApplySaveFileSmall(SaveFileSmall* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(&gGameState.progression.maxHp, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(&save->shared);
    RestoreMapCardInventory(&save->small);
    gGameState.flags |= 8;
}

TaskDesc gTaskDescHumCloud = { gTaskNameHumCloud, task_hum_cloud_0, task_hum_cloud_1, task_hum_cloud_2, task_hum_cloud_3, 0x194 };

TaskDesc gTaskDescHumHook = { gTaskNameHumHook, task_hum_hook_0, task_hum_hook_1, task_hum_hook_2, task_hum_hook_3, 0x1BC };

TaskDesc gTaskDescHumHookMoon = { gTaskNameHumHookMoon, task_hum_hook_moon_0, task_hum_hook_moon_1, task_hum_hook_moon_2, task_hum_hook_moon_3, 0xC };

TaskDesc gTaskDescHumHookBomb = { gTaskNameHumHookBomb, task_hum_hook_bomb_0, task_hum_hook_bomb_1, task_hum_hook_bomb_2, task_hum_hook_bomb_3, 0x54 };

TaskDesc gTaskDescHumAnsem = { gTaskNameHumAnsem, task_hum_ansem_0, task_hum_ansem_1, task_hum_ansem_2, task_hum_ansem_3, 0x1DC };

TaskDesc gTaskDescHumHades = { gTaskNameHumHades, task_hum_hades_0, task_hum_hades_1, task_hum_hades_2, task_hum_hades_3, 0x280 };

TaskDesc gTaskDescHumMahluxia = { gTaskNameHumMahluxia, task_hum_mahluxia_0, task_hum_mahluxia_1, task_hum_mahluxia_2, task_hum_mahluxia_3, 0x3A4 };

TaskDesc gTaskDescHumLaxene = { gTaskNameHumLaxene, task_hum_laxene_0, task_hum_laxene_1, task_hum_laxene_2, task_hum_laxene_3, 0x1A8 };

TaskDesc gTaskDescHumLaxeneKnf = { gTaskNameHumLaxeneKnf, task_hum_laxene_knf_0, task_hum_laxene_knf_1, task_hum_laxene_knf_2, task_hum_laxene_knf_3, 0x44 };

TaskDesc gTaskDescHumAxcel = { gTaskNameHumAxcel, task_hum_axcel_0, task_hum_axcel_1, task_hum_axcel_2, task_hum_axcel_3, 0x238 };

TaskDesc gTaskDescHumAxcelPtc = { gTaskNameHumAxcelPtc, task_hum_axcel_ptc_0, task_hum_axcel_ptc_1, task_hum_axcel_ptc_2, task_hum_axcel_ptc_3, 0x30 };

TaskDesc gTaskDescHumVixen = { gTaskNameHumVixen, task_hum_vixen_0, task_hum_vixen_1, task_hum_vixen_2, task_hum_vixen_3, 0x218 };

TaskDesc gTaskDescHumVixenNdl = { gTaskNameHumVixenNdl, task_hum_vixen_ndl_0, task_hum_vixen_ndl_1, task_hum_vixen_ndl_2, task_hum_vixen_ndl_3, 0x30 };

TaskDesc gTaskDescHumVixenIce = { gTaskNameHumVixenIce, task_hum_vixen_ice_0, task_hum_vixen_ice_1, task_hum_vixen_ice_2, task_hum_vixen_ice_3, 0x94 };

TaskDesc gTaskDescHumVixenFrz = { gTaskNameHumVixenFrz, task_hum_vixen_frz_0, task_hum_vixen_frz_1, task_hum_vixen_frz_2, task_hum_vixen_frz_3, 0x38 };

TaskDesc gTaskDescHumVixenFrg = { gTaskNameHumVixenFrg, task_hum_vixen_frg_0, task_hum_vixen_frg_1, task_hum_vixen_frg_2, task_hum_vixen_frg_3, 0x220 };

TaskDesc gTaskDescHumLexceus = { gTaskNameHumLexceus, task_hum_lexceus_0, task_hum_lexceus_1, task_hum_lexceus_2, task_hum_lexceus_3, 0x204 };

TaskDesc gTaskDescHumLexTmh = { gTaskNameHumLexTmh, task_hum_lex_tmh_0, task_hum_lex_tmh_1, task_hum_lex_tmh_2, task_hum_lex_tmh_3, 0x4C };

TaskDesc gTaskDescHumLexTmh0 = { gTaskNameHumLexTmh0, task_hum_lex_tmh0_0, task_hum_lex_tmh0_1, task_hum_lex_tmh0_2, task_hum_lex_tmh0_3, 0x38 };

TaskDesc gTaskDescHumLexRock = { gTaskNameHumLexRock, task_hum_lex_rock_0, task_hum_lex_rock_1, task_hum_lex_rock_2, task_hum_lex_rock_3, 0x2C4 };

TaskDesc gTaskDescHumMahluxiaFlw = { gTaskNameHumMahluxiaFlw, task_hum_mahluxia_flw_0, task_hum_mahluxia_flw_1, task_hum_mahluxia_flw_2, task_hum_mahluxia_flw_3, 0x3C };

TaskDesc gTaskDescHumRiku = { gTaskNameHumRiku, task_hum_riku_0, task_hum_riku_1, task_hum_riku_2, task_hum_riku_3, 0x384 };

TaskDesc gTaskDescHumLeon = { gTaskNameHumLeon, task_hum_leon_0, task_hum_leon_1, task_hum_leon_2, task_hum_leon_3, 0x19C };

TaskDesc gTaskDescHumRobe = { gTaskNameHumRobe, task_hum_robe_0, task_hum_robe_1, task_hum_robe_2, task_hum_robe_3, 0x18C };
