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
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} ChkBtlPos;

typedef struct ChkBtlWorld {
    u8 unk_00;
    u8 unk_01[0x03];
    const char* name;
} ChkBtlWorld;

extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern u32 gFrameCounter;
extern const ChkBtlEntry gChkBtlEntries[];
extern const ChkBtlWorld gChkBtlWorlds[];
extern ChkBtlWork* gChkBtlWork;
extern Mode gModeBattle;
extern Mode gUnk_09EE2704;
extern const char gWhitePalette[];
extern TaskDesc gTaskDescEmy00;
extern TaskDesc gTaskDescEmy01;
extern TaskDesc gTaskDescEmy02;
extern TaskDesc gTaskDescEmy03;
extern TaskDesc gTaskDescEmy04;
extern TaskDesc gTaskDescEmy06;
extern TaskDesc gTaskDescEmy07;
extern TaskDesc gTaskDescEmy08;
extern TaskDesc gTaskDescEmy14;
extern TaskDesc gTaskDescEmy15;
extern TaskDesc gTaskDescEmy16;
extern TaskDesc gTaskDescEmy18;
extern TaskDesc gTaskDescEmy19;
extern TaskDesc gTaskDescEmy21;
extern TaskDesc gTaskDescEmy22;
extern TaskDesc gTaskDescEmy23;
extern TaskDesc gTaskDescEmy25;
extern TaskDesc gTaskDescEmy26;
extern TaskDesc gTaskDescEmy27;
extern TaskDesc gTaskDescEmy28;
extern TaskDesc gTaskDescEmy29;
extern TaskDesc gTaskDescEmy30;
extern TaskDesc gTaskDescEmy31;
extern TaskDesc gTaskDescEmy37;
extern TaskDesc gTaskDescEmy38;
extern TaskDesc gTaskDescEmy39;
extern TaskDesc gTaskDescEmy41;
extern TaskDesc gTaskDescEmy44;
extern TaskDesc gTaskDescEmy81;
extern TaskDesc gTaskDescEmy82;
extern TaskDesc gTaskDescEmy83;
extern TaskDesc gTaskDescEmyTrumpH;
extern TaskDesc gTaskDescEmyTrumpS;
extern TaskDesc gTaskDescEmyTest;

#endif /* GUARD_MODE_CHKBTL_H */
