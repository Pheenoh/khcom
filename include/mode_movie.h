#ifndef GUARD_MODE_MOVIE_H
#define GUARD_MODE_MOVIE_H

#include "types.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "sprite.h"
#include "main.h"

extern vu16 gUnk_02034938;
extern s32 gUnk_0203493C;
extern s16 gUnk_02034940;
extern s16 gUnk_02034942;
extern s16 gUnk_02034944;
extern s16 gUnk_02034946;
extern s32 gUnk_02034948;
extern s32 gUnk_0203494C;
extern void* gUnk_02034950;
extern s16 gUnk_02034954;
extern s16 gUnk_02034956;
extern s16 gUnk_02034958;
extern s16 gUnk_0203495A;
extern s16 gUnk_0203495C;
extern s16 gUnk_0203495E;
extern s16 gUnk_02034960;
extern void* gUnk_03007484;
extern u16 gDispCnt;
extern u8 gUnk_0815C3EC[];
extern u8 gUnk_084E0F34[];
extern u8 gUnk_084F4660[];
extern u8 gUnk_0855CCB4[];
extern u8 gUnk_086FBA14[];
extern u8 gUnk_0886AB40[];
extern u8 gUnk_0886AB90[];
extern u8 gUnk_0886AC70[];
extern u8 sMovieHeapName[];
extern u8 gUnk_08F69C04[];
extern u8 gUnk_09614718[];
extern u8 gUnk_09ECEB64[];
extern u8 gUnk_09EFA9C4[];

void InitDisplayRegs(void);
void m4aSoundVSyncOff(void);
s32 GetIwramHeapStart(void);
s32 GetIwramHeapSize(void);
s32 GetEwramHeapStart(void);
s32 GetEwramHeapSize(void);
void func_081181BC(void* a, void* b, void* c, void* d);
s32 func_081181EC(void* a);
void func_08118344(void* a, s32 b);
void func_08118538(void);
void VTransInit(void);
void BgInit(void);
void FadeInit(void);
void PalletInit(void);
void SioKeyInit(void);
void VTransReset(void);
void func_08004D74(void);
void func_08001F98(void);
void FadeReset(void);
void func_08006404(void);
void m4aSoundInit(void);
void m4aSoundVSyncOn(void);
void func_0806180C(s32 a);
void func_080010CC(void* a, s32 b);
void func_0805EA90(void);
void func_0805E93C(void);

#endif /* GUARD_MODE_MOVIE_H */
