#include "mode_deck.h"
#include "task_descriptors.h"
#include "system_state.h"
#ifndef GUARD_MODE_CHKBTL_H
#define GUARD_MODE_CHKBTL_H

#include "card_api.h"

#include "mode_chkbtl_api.h"

#include "mode_test_api.h"

#include "fade.h"
#include "types.h"
#include "battle_work.h"
#include "game_state.h"
#include "taskpool.h"
#include "main.h"
#include "mode.h"
#include "mode_battle_data.h"
#include "engine.h"
#include "key.h"

#include "battle_debug_types.h"

typedef struct ChkBtlEntry {
    u8 world;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    TaskDesc* taskDesc;
    const char* name;
} ChkBtlEntry;

typedef struct ChkBtlPos {
    s32 x;
    s32 y;
    s32 z;
} ChkBtlPos;

typedef struct ChkBtlWorld {
    u8 unk_00;
    u8 unk_01[0x03];
    const char* name;
} ChkBtlWorld;

extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern const ChkBtlEntry gChkBtlEntries[];
extern const ChkBtlWorld gChkBtlWorlds[];
extern ChkBtlWork* gChkBtlWork;
extern const char gWhitePalette[32];

#endif /* GUARD_MODE_CHKBTL_H */
