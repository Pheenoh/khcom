#ifndef GUARD_MODE_BATTLE_H
#define GUARD_MODE_BATTLE_H

#include "fade.h"
#include "btl_collision.h"
#include "types.h"
#include "battle_work.h"
#include "game_state.h"
#include "taskpool.h"
#include "gba/syscall.h"
#include "main.h"
#include "engine.h"
#include "m4a.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

extern u32 gUnk_03006C10;
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

void SetBgSize(s32 a, s32 b);
void func_0800AB8C(void);
void func_08012798(s32 a, u16 b);
void func_08012810(void);
void func_08012824(void);
void BtlWorkInit(void);
void _08019CB4(void);
void func_0801A920(s32 a, s32 b, s32 c, s32 d);
void func_0801C068(void);
void func_0801C104(void);

void mode_battle_0(u32 mode);
void mode_battle_1(void);
void mode_battle_2(void);

#endif /* GUARD_MODE_BATTLE_H */
