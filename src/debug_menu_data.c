#include "debug_menu_data.h"
#include "debug_menu_assets.h"

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
