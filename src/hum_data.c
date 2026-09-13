#include "hum.h"
#include "task_animation_assets.h"

const u32 gUnk_0813EDD0[2][3] __attribute__((section(".rodata_hum_000"))) = {
    { 37, 37, 37 },
    { 37, 36, 37 },
};

AnimDef gUnk_0813EDE8[20] __attribute__((section(".rodata_hum_000"))) = {
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

HumDef gUnk_0813EF28 __attribute__((section(".rodata_hum_000"))) = { 128, 0, gUnk_08F6DC24, 0, { 43, 99, 38, 14, 24, 99, 0 } };

const u32 gUnk_0813EF54[3] __attribute__((section(".rodata_hum_001"))) = {
    36, 36, 38,
};

const u32 gUnk_0813EF60[3] __attribute__((section(".rodata_hum_001"))) = {
    37, 37, 38,
};

AnimDef gUnk_0813EF6C[15] __attribute__((section(".rodata_hum_001"))) = {
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

HumDef gUnk_0813F05C __attribute__((section(".rodata_hum_001"))) = { 128, 0, gUnk_09618158, 0, { 42, 99, 38, 14, 24, 99, 0 } };

u8 gUnk_0813F078[8] __attribute__((section(".rodata_hum_001"))) = {
    0, 4, 4, 6, 8, 10, 8, 6,
};

const u32 gUnk_0813F0B8[3] __attribute__((section(".rodata_hum_002"))) = {
    36, 37, 37,
};

const u32 gUnk_0813F0C4[3] __attribute__((section(".rodata_hum_002"))) = {
    36, 37, 36,
};

AnimDef gUnk_0813F0D0[7] __attribute__((section(".rodata_hum_002"))) = {
    { gUnk_09EE17C0, gUnk_09EE17D0, gUnk_08B5B51E, 0, { 0, 0, 0 } },
    { gUnk_09EE17D4, gUnk_09EE17E4, gUnk_08B5CC5E, 0, { 0, 0, 0 } },
    { gUnk_09EE17E8, gUnk_09EE1814, gUnk_08B5E3CA, 0, { 0, 0, 0 } },
    { gUnk_09EE1818, gUnk_09EE1830, gUnk_08B621F8, 0, { 0, 0, 0 } },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 0, { 0, 0, 0 } },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 1, { 0, 0, 0 } },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 2, { 0, 0, 0 } },
};

AnimDef gUnk_0813F140[10] __attribute__((section(".rodata_hum_002"))) = {
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

HumSubDef gUnk_0813F1E0 __attribute__((section(".rodata_hum_002"))) = { gUnk_09618378, 128, 0 };

HumDef gUnk_0813F1E8 __attribute__((section(".rodata_hum_002"))) = { 80, 0, gUnk_09618318, 0, { 52, 99, 65, 14, 42, 99, 0 } };

const u32 gUnk_0813F214[3] __attribute__((section(".rodata_hum_003"))) = {
    36, 36, 36,
};

const u32 gUnk_0813F220[3] __attribute__((section(".rodata_hum_003"))) = {
    37, 36, 37,
};

AnimDef gUnk_0813F22C[10] __attribute__((section(".rodata_hum_003"))) = {
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

AnimDef gUnk_0813F2CC[5] __attribute__((section(".rodata_hum_003"))) = {
    { gUnk_09EE1AE0, gUnk_09EE1AF8, gUnk_08BA6EAE, 0, { 0, 0, 0 } },
    { gUnk_09EE1AC0, gUnk_09EE1ADC, gUnk_08BA4592, 0, { 0, 0, 0 } },
    { gUnk_09EE1A58, gUnk_09EE1AB4, gUnk_08BA17EE, 0, { 0, 0, 0 } },
    { gUnk_09EE1A58, gUnk_09EE1AB4, gUnk_08BA17EE, 1, { 0, 0, 0 } },
    { gUnk_09EE19CC, gUnk_09EE19F0, gUnk_08B95CE2, 0, { 0, 0, 0 } },
};

HumSubDef gUnk_0813F31C __attribute__((section(".rodata_hum_003"))) = { gUnk_08F69BA4, 75, 0 };

HumDef gUnk_0813F324 __attribute__((section(".rodata_hum_003"))) = { 
#ifdef VERSION_EU
        100
#else
        128
#endif
    , 0, gUnk_09617F18, 0, { 44, 99, 90, 14, 52, 99, 4 } };

const u32 gUnk_0813F350[3] __attribute__((section(".rodata_hum_004"))) = {
    37, 36, 37,
};

const u32 gUnk_0813F35C[3] __attribute__((section(".rodata_hum_004"))) = {
    36, 37, 38,
};

AnimDef gUnk_0813F368[13] __attribute__((section(".rodata_hum_004"))) = {
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

AnimDef gUnk_0813F438 __attribute__((section(".rodata_hum_004"))) = { gUnk_09EE1C74, gUnk_09EE1C90, gUnk_08BCA01C, 0, { 0, 0, 0 } };

HumSubDef gUnk_0813F448 __attribute__((section(".rodata_hum_004"))) = { gUnk_08F6DC84, 90, 0 };

HumDef gUnk_0813F450 __attribute__((section(".rodata_hum_004"))) = { 90, 0, gUnk_09618438, 0, { 51, 99, 60, 14, 40, 99, 0 } };

const u32 gUnk_0813F480[2][3] __attribute__((section(".rodata_hum_005"))) = {
    { 36, 38, 38 },
    { 37, 37, 36 },
};

AnimDef gUnk_0813F498[15] __attribute__((section(".rodata_hum_005"))) = {
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

HumDef gUnk_0813F588 __attribute__((section(".rodata_hum_005"))) = { 128, 0, gUnk_09618458, 0, { 49, 99, 60, 14, 46, 99, 0 } };

const u32 gUnk_0813F5C8[2][3] __attribute__((section(".rodata_hum_006"))) = {
    { 36, 36, 36 },
    { 36, 37, 36 },
};

AnimDef gUnk_0813F5E0[14] __attribute__((section(".rodata_hum_006"))) = {
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

AnimDef gUnk_0813F6C0[10] __attribute__((section(".rodata_hum_006"))) = {
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

HumSubDef gUnk_0813F760 __attribute__((section(".rodata_hum_006"))) = { gUnk_08F69BA4, 64, 0 };

HumDef gUnk_0813F768 __attribute__((section(".rodata_hum_006"))) = { 
#ifdef VERSION_EU
        102
#else
        128
#endif
    , 0, gUnk_096180F8, 0, { 48, 99, 60, 14, 32, 99, 0 } };

const u32 gUnk_0813F7A8[3] __attribute__((section(".rodata_hum_007"))) = {
    36, 37, 36,
};

const u32 gUnk_0813F7B4[3] __attribute__((section(".rodata_hum_007"))) = {
    37, 36, 36,
};

const u32 gUnk_0813F7C0[3] __attribute__((section(".rodata_hum_007"))) = {
    36, 36, 37,
};

const u32 gUnk_0813F7CC[3] __attribute__((section(".rodata_hum_007"))) = {
    36, 36, 36,
};

AnimDef gUnk_0813F7D8[15] __attribute__((section(".rodata_hum_007"))) = {
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

HumDef gUnk_0813F8C8 __attribute__((section(".rodata_hum_007"))) = { 83, 0, gUnk_096183B8, 0, { 50, 99, 80, 14, 48, 99, 0 } };

AnimDef gUnk_0813F91C[13] __attribute__((section(".rodata_hum_008"))) = {
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

VixenFrgDef gUnk_0813FA00[15] __attribute__((section(".rodata_hum_009"))) = {
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

const u32 gUnk_0813FA8C[3] __attribute__((section(".rodata_hum_010"))) = {
    36, 37, 36,
};

AnimDef gUnk_0813FA98[10] __attribute__((section(".rodata_hum_010"))) = {
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

HumDef gUnk_0813FB38 __attribute__((section(".rodata_hum_010"))) = { 128, 0, gUnk_09618478, 0, { 53, 99, 70, 24, 52, 99, 4 } };

const u32 gUnk_0813FBBC[2][3] __attribute__((section(".rodata_hum_011"))) = {
    { 36, 36, 38 },
    { 37, 37, 39 },
};

AnimDef gUnk_0813FBD4[21] __attribute__((section(".rodata_hum_011"))) = {
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

HumDef gUnk_0813FD24 __attribute__((section(".rodata_hum_011"))) = { 64, 0, gUnk_09618338, 0, { 45, 99, 38, 14, 24, 99, 0 } };

HumSubDef gUnk_0813FD40 __attribute__((section(".rodata_hum_011"))) = { gUnk_09618338, 64, 0 };

AnimDef gUnk_0813FD58[5] __attribute__((section(".rodata_hum_012"))) = {
    { gUnk_09EF01F0, gUnk_09EF01F8, gUnk_0934B7EC, 0, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 0, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 3, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 1, { 0, 0, 0 } },
    { gUnk_09EE25D0, gUnk_09EE25E4, gUnk_08C6668E, 2, { 0, 0, 0 } },
};

HumDef gUnk_0813FDA8 __attribute__((section(".rodata_hum_012"))) = { 128, 0, gUnk_09618258, 0, { 41, 99, 64, 14, 40, 99, 0 } };

AnimDef gUnk_0813FDD4[2] __attribute__((section(".rodata_hum_013"))) = {
    { gUnk_09EEE36C, gUnk_09EEE3BC, gUnk_091C37E0, 5, { 0, 0, 0 } },
    { gUnk_09EE25F4, gUnk_09EE2604, gUnk_08C67F86, 0, { 0, 0, 0 } },
};

HumDef gUnk_0813FDF4 __attribute__((section(".rodata_hum_013"))) = { 128, 0, gUnk_09617C78, 0, { 51, 99, 64, 14, 32, 99, 0 } };
