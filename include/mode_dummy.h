#ifndef GUARD_MODE_DUMMY_H
#define GUARD_MODE_DUMMY_H

#include "types.h"
#include "game_state.h"
#include "key.h"
#include "mode.h"
typedef struct DummyEntry {
    const char* name;
    const char* desc;
    u16 unk_08;
} DummyEntry;

extern u32 gFrameCounter;
extern const DummyEntry gDummyEntries[];
extern u8 gWhitePalette[];
extern u8 gUnk_08C6B0C4[];
extern u8 gUnk_08F683C4[];
extern u8 gUnk_08EEE384[];
extern Mode gModeMovie;
extern Mode gModeWorldselect;
extern Mode gModeCopyright1;
#ifdef VERSION_EU
extern Mode gModeLang;
#endif

void SetModeUpdate(void (*fn)(void));
void SetBgMode0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void UpdatePlayTime(void);
void func_0805FA8C(s32 a, u16 b, u16 c);
void func_0805FCB0(s32 a, s32 b, s32 c, const char* s);
void func_080605A4(s32 a);
void func_0806180C(u16 a);
void func_080DF380(void);
void func_080E04EC(void);

void mode_dummy_0(u32 arg);
void func_0800C064(void);
void mode_dummy_1(void);
void mode_dummy_2(void);

#endif /* GUARD_MODE_DUMMY_H */
