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

extern void* gUnk_09EDA2A0[];
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
extern TaskDesc gTaskDescMonsgage;
extern TaskDesc gTaskDescTutorial;
extern TaskDesc gTaskDescBosTm;
extern TaskDesc gTaskDescBosJf;
extern TaskDesc gTaskDescBosDsd;
extern TaskDesc gTaskDescBosBoogie;
extern TaskDesc gTaskDescBosUrsula;
extern TaskDesc gTaskDescBosGa;
extern TaskDesc gTaskDescBosMd;
extern TaskDesc gTaskDescBosPc;
extern TaskDesc gTaskDescBosLst;

void _08019CB4(void);

#endif /* GUARD_MODE_BATTLE_H */
