#ifndef GUARD_MODE_DEBUG_H
#define GUARD_MODE_DEBUG_H

#include "card_api.h"

#include "mode_debug_api.h"

#include "mode_test_api.h"

#include "pallet.h"
#include "save_api.h"

#include "player_progression.h"

#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "chkobj.h"
#include "main.h"
#include "anim.h"
#include "mode.h"
#include "key.h"
#include "m4a.h"
#include "battle_actor.h"
typedef struct DebugWork {
    s8 unk_00;
    s8 unk_01;
    u8 unk_02[0x02];
    void* tiles;
    void* palette;
    AnimState anim;
} DebugWork;

extern const char gUnk_08F68604[];
extern u8 gUnk_08950902[];
extern u8 gUnk_08C72CE4[];
extern u8 gUnk_08EEEB84[];
extern u8 gUnk_08F683E4[];
extern u8 gUnk_08F685E4[];
extern u8 gUnk_09EDF764[];
extern u8 gUnk_09EDF774[];
extern Mode gModeChkbtl;
extern Mode gModeChkobj;
extern Mode gModeChksnd;
extern Mode gModeChkeff;
extern Mode gModeDebflag;
extern Mode gModeMovie;
extern Mode gModeEventselect;
extern Mode gModeSioBattle;
extern Mode gModeWLogo;
extern Mode gModePooh;
extern Mode gModeCopyright1;
extern Mode gModeMapChk;
extern Mode gModeBackupstat;

#endif /* GUARD_MODE_DEBUG_H */
