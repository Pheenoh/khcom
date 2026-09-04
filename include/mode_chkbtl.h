#ifndef GUARD_MODE_CHKBTL_H
#define GUARD_MODE_CHKBTL_H

#include "types.h"
#include "taskpool.h"
#include "main.h"
#include "mode.h"

typedef struct ChkBtlWork {
    s8 unk_00;
    s8 bg;
    s16 enemy;
    s8 floor;
    u8 unk_05;
    s16 hp;
} ChkBtlWork;

typedef struct ChkBtlEntry {
    u8 world;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    TaskDesc* taskDesc;
    const char* name;
} ChkBtlEntry;

typedef struct BtlWork {
    u8 unk_00[0x2C];
    TaskPool unk_2C;
} BtlWork;

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

typedef struct GameState {
    u8 unk_00[0x08];
    u32 flags;
    u8 world;
    u8 unk_0D;
    u8 floor;
    u8 unk_0F[0x23];
    u16 hp;
    u8 unk_34[0xC4];
    u16 maxHp;
    u16 cp;
    u8 unk_FC[0x80];
    u16 unk_17C;
} GameState;
void ModeRequest(Mode* mode, s32 arg);
u16 GetKeysRepeat(void);
void SetBgMode0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void func_08006120(s32 a, s32 b);
void SeedRandom(u32 a);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_0805FA8C(s32 a, s32 b, s32 c);
void func_0805FC04(u8 x, u8 y, u8 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080609A0(void);
void func_080605A4(s32 a);
void func_08085CB0(void);
void _08085D04(u8 a);
void func_08085FB0(void);

void func_0800AB8C(void);
void func_0800ABD8(void);
void mode_chkbtl_0(void);
void mode_chkbtl_1(void);
void mode_chkbtl_2(void);

extern BtlWork* gBtlWork;
extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern GameState gGameState;
extern u32 gUnk_03006C10;
extern u32 gFrameCounter;
extern const ChkBtlEntry gChkBtlEntries[];
extern const ChkBtlWorld gChkBtlWorlds[];
extern ChkBtlWork* gChkBtlWork;
extern Mode gModeBattle;
extern Mode gModeDebug;
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
