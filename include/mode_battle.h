#include "registration_data.h"
#include "system_state.h"
#ifndef GUARD_MODE_BATTLE_H
#define GUARD_MODE_BATTLE_H

#include "mode_chkbtl_api.h"

#include "mode_battle_api.h"

#include "display.h"
#include "fade.h"
#include "battle_actor.h"
#include "btl_collision.h"
#include "types.h"
#include "battle_work.h"
#include "game_state.h"
#include "taskpool.h"
#include "gba/syscall.h"
#include "main.h"
#include "engine.h"
#include "m4a.h"
#include "btl_effect.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

#include "formation_data.h"
#ifdef VERSION_EU
#include "save_api.h"
#include "battle_localized_assets.h"
#endif
extern TaskDesc gTaskDescBtlSora;
extern TaskDesc gTaskDescBtlRiku;
extern TaskDesc gTaskDescBtlMap;
extern TaskDesc gTaskDescBtlPause;
extern TaskDesc gTaskDescBtlForm;
extern TaskDesc gTaskDescPcAcddmg;
extern TaskDesc gTaskDescHumCloud;
extern TaskDesc gTaskDescHumHook;
extern TaskDesc gTaskDescHumAnsem;
extern TaskDesc gTaskDescHumHades;
extern TaskDesc gTaskDescHumMahluxia;
extern TaskDesc gTaskDescHumLaxene;
extern TaskDesc gTaskDescHumAxcel;
extern TaskDesc gTaskDescHumVixen;
extern TaskDesc gTaskDescHumLexceus;
extern TaskDesc gTaskDescHumRiku;
extern TaskDesc gTaskDescHumLeon;
extern TaskDesc gTaskDescHumRobe;

void _08019CB4(void);

#ifdef VERSION_EU
typedef struct LangWork {
    s16 cursor;
    s16 timer;
    u32 state;
    u16 flags;
    u32 language;
    struct ObjTiles* tiles;
    struct ObjPalette* palette;
} LangWork;

extern LangWork* gLangWork;
extern u8 gUnkEu_08F6A6DC[];
extern u8 gUnkEu_08F6A6FC[];
extern u8 gUnkEu_08F77180[];
extern u8 gUnkEu_08F7EBF8[];
extern u8 gUnkEu_08F7EFB0[];
extern u8 gUnkEu_08C9CA58[];
#endif

#endif /* GUARD_MODE_BATTLE_H */
