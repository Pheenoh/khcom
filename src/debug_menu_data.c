#include "debug_menu_data.h"
#include "debug_menu_assets.h"

const char* const gUnk_09EF6960[] __attribute__((section(".rodata_gUnk_09EF6960"))) = {
#if defined(VERSION_US)
    gDebugMenuTextUs_0984B648,
    gDebugMenuTextUs_0984B634,
    gDebugMenuTextUs_0984B620,
    gDebugMenuTextUs_0984B60C,
    gDebugMenuTextUs_0984B5F8,
#elif defined(VERSION_JP)
    gDebugMenuTextJp_0980015C,
    gDebugMenuTextJp_09800148,
    gDebugMenuTextJp_09800134,
    gDebugMenuTextJp_09800120,
    gDebugMenuTextJp_0980010C,
#elif defined(VERSION_EU)
    gDebugMenuTextEu_0982801C,
    gDebugMenuTextEu_09828008,
    gDebugMenuTextEu_09827FF4,
    gDebugMenuTextEu_09827FE0,
    gDebugMenuTextEu_09827FCC,
#endif
};

const char* const gUnk_09EF6974[] __attribute__((section(".rodata_gUnk_09EF6974"))) = {
#if defined(VERSION_US)
    gDebugMenuTextUs_0984B71C,
    gDebugMenuTextUs_0984B70C,
    gDebugMenuTextUs_0984B6FC,
    gDebugMenuTextUs_0984B6EC,
    gDebugMenuTextUs_0984B6DC,
    gDebugMenuTextUs_0984B6CC,
    gDebugMenuTextUs_0984B6BC,
    gDebugMenuTextUs_0984B6AC,
    gDebugMenuTextUs_0984B69C,
    gDebugMenuTextUs_0984B68C,
    gDebugMenuTextUs_0984B67C,
    gDebugMenuTextUs_0984B66C,
    gDebugMenuTextUs_0984B65C,
#elif defined(VERSION_JP)
    gDebugMenuTextJp_09800230,
    gDebugMenuTextJp_09800220,
    gDebugMenuTextJp_09800210,
    gDebugMenuTextJp_09800200,
    gDebugMenuTextJp_098001F0,
    gDebugMenuTextJp_098001E0,
    gDebugMenuTextJp_098001D0,
    gDebugMenuTextJp_098001C0,
    gDebugMenuTextJp_098001B0,
    gDebugMenuTextJp_098001A0,
    gDebugMenuTextJp_09800190,
    gDebugMenuTextJp_09800180,
    gDebugMenuTextJp_09800170,
#elif defined(VERSION_EU)
    gDebugMenuTextEu_098280F0,
    gDebugMenuTextEu_098280E0,
    gDebugMenuTextEu_098280D0,
    gDebugMenuTextEu_098280C0,
    gDebugMenuTextEu_098280B0,
    gDebugMenuTextEu_098280A0,
    gDebugMenuTextEu_09828090,
    gDebugMenuTextEu_09828080,
    gDebugMenuTextEu_09828070,
    gDebugMenuTextEu_09828060,
    gDebugMenuTextEu_09828050,
    gDebugMenuTextEu_09828040,
    gDebugMenuTextEu_09828030,
#endif
};

const char* const gUnk_09EF34F0[] __attribute__((section(".rodata_gUnk_09EF34F0"))) = {
#if defined(VERSION_US)
    gDebugMenuTextUs_0961A994,
    gDebugMenuTextUs_0961A980,
    gDebugMenuTextUs_0961A96C,
    gDebugMenuTextUs_0961A958,
    gDebugMenuTextUs_0961A944,
#elif defined(VERSION_JP)
    gDebugMenuTextJp_095D3470,
    gDebugMenuTextJp_095D345C,
    gDebugMenuTextJp_095D3448,
    gDebugMenuTextJp_095D3434,
    gDebugMenuTextJp_095D3420,
#elif defined(VERSION_EU)
    gDebugMenuTextEu_095DBE8C,
    gDebugMenuTextEu_095DBE70,
    gDebugMenuTextEu_095DBE54,
    gDebugMenuTextEu_095DBE38,
    gDebugMenuTextEu_095DBE1C,
    gDebugMenuTextEu_095DBE00,
    gDebugMenuTextEu_095DBDE4,
    gDebugMenuTextEu_095DBDC8,
    gDebugMenuTextEu_095DBDAC,
    gDebugMenuTextEu_095DBD90,
#endif
};

#ifndef VERSION_EU
const char* const gUnk_09EF3504[] __attribute__((section(".rodata_gUnk_09EF3504"))) = {
#if defined(VERSION_US)
    gDebugMenuTextUs_0961A9B8,
    gDebugMenuTextUs_0961A9A8,
#elif defined(VERSION_JP)
    gDebugMenuTextJp_095D3494,
    gDebugMenuTextJp_095D3484,
#endif
};

#endif

#ifdef VERSION_EU
const char* const gSioUnusedFlagLabelEu_09F7E750 __attribute__((section(".rodata_gSioUnusedFlagLabelEu_09F7E750"))) = gDebugMenuTextEu_095DBD74;
#endif

#ifdef VERSION_EU
const char* const gSioUnusedFlagLabelEu_09F7E754 __attribute__((section(".rodata_gSioUnusedFlagLabelEu_09F7E754"))) = gDebugMenuTextEu_095DBD58;
#endif
