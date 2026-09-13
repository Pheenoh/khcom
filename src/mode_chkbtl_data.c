#include "mode_chkbtl_api.h"
#include "mode.h"

#include "battle_debug_types.h"

struct ChkBtlWork gUnk_02034890;
extern const char gModeNameChkbtl[];


struct ChkBtlWork* gChkBtlWork = &gUnk_02034890;

Mode gModeChkbtl = { gModeNameChkbtl, mode_chkbtl_0, mode_chkbtl_1, mode_chkbtl_2 };
