#ifndef GUARD_MODE_MOVIE_H
#define GUARD_MODE_MOVIE_H

#include "obj_api.h"
#include "types.h"
#include "mode.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "sprite.h"
#include "main.h"
#include "engine.h"
#include "util.h"
#include "m4a.h"

typedef struct MovieSub {
    s16 unk_00;
    s16 unk_02;
    u16* unk_04;
    u8 unk_08;
    u8 unk_09;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
} MovieSub;

extern vu16 gUnk_02034938;
extern s32 gUnk_0203493C;
extern u16 gUnk_02034940;
extern volatile s16 gUnk_02034942;
extern volatile s16 gUnk_02034944;
extern volatile u16 gUnk_02034946;
extern MovieSub* volatile gUnk_02034948;
extern MovieSub* volatile gUnk_0203494C;
extern void* gUnk_02034950;
extern volatile s16 gUnk_02034954;
extern volatile u16 gUnk_02034956;
extern volatile u16 gUnk_02034958;
extern volatile u16 gUnk_0203495A;
extern volatile s16 gUnk_0203495C;
extern volatile u16 gUnk_0203495E;
extern volatile u16 gUnk_02034960;
extern void* gVBlankHandlerOverride;
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
extern u8 gModeStaffRoll[];

s32 GetIwramHeapStart(void);
s32 GetIwramHeapSize(void);
s32 GetEwramHeapStart(void);
s32 GetEwramHeapSize(void);
void MovieSetCallbacks(void* a, void* b, void* c, void* d);
s32 MovieStart(void* a);
void MoviePlay(void* a, s32 b);
void MovieClose(void);
void PalletInit(void);
void VTransReset(void);
void BgReset(void);
void func_0806180C(s32 a);
void func_0805EA90(void);
s32 func_0805E93C(void);
u16 func_0805E89C(u16* str);

void MovieUpdate(void);
s32 func_0806C490(void* str);
s32 func_0806C81C(void* str, u16 tile);
u8 func_0806CBAC(void* str, u16* widths, u16 tile);
#ifdef VERSION_JP
u16 func_0805E848(u8* str);
#else
s16 func_0805E848(u16* widths, u16 count);
#endif
extern u16 gUnk_02034968[];
extern u16 gUnk_020349B8[];
#endif
