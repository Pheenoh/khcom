#ifndef GUARD_MODE_BATTLE_H
#define GUARD_MODE_BATTLE_H

#include "types.h"
#include "gba/syscall.h"
#include "main.h"

typedef struct BtlWork {
    u8 unk_000[0x2C];
    TaskPool unk_02C;
    TaskPool unk_040;
    TaskPool unk_054;
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    s16 unk_072;
    s16 unk_074;
    u8 unk_076[0x06];
    void* unk_07C;
    u8 unk_080[0x33];
    u8 unk_0B3;
    u8 unk_0B4[0x58];
    u32 unk_10C;
    u8 unk_110[0x18];
    void* unk_128;
    u8 unk_12C[0x98];
    u16 unk_1C4;
    u16 unk_1C6;
    u8 unk_1C8[0x08];
} BtlWork;

typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
    u8 world;
    u8 unk_00D;
    u8 unk_00E[0x02];
    u16 unk_010;
} GameState;

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

extern BtlWork* gBtlWork;
extern void* gUnk_02039B9C;
extern GameState gGameState;
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

void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void SetBgMode1(void);
void SetBgMode2(void);
void SetBgOverflow(s32 bg, u8 on);
void SetBgSize(s32 a, s32 b);
void func_08006120(s32 a, s32 b);
void func_0800AB8C(void);
void m4aSongNumStart(u16 id);
void func_0801227C(void);
void func_080125A4(void);
void func_08012798(s32 a, u16 b);
void func_08012810(void);
void func_08012824(void);
void BtlWorkInit(void);
void _08019CB4(void);
void func_0801A920(s32 a, s32 b, s32 c, s32 d);
void func_0801C068(void);
void func_0801C104(void);
void UpdatePlayTime(void);

void mode_battle_0(u32 mode);
void mode_battle_1(void);
void mode_battle_2(void);

void func_0801050C(void);
void func_080BD4A8(void);

#endif /* GUARD_MODE_BATTLE_H */
