#ifndef GUARD_MODE_CHKEFF_H
#define GUARD_MODE_CHKEFF_H

#include "types.h"
#include "main.h"

typedef struct ChkEffWork {
    TaskPool pool;
    s16 unk_14;
    u8 unk_16;
    u8 unk_17;
    u16 unk_18;
    u16 unk_1A;
    u8 unk_1C;
    u8 unk_1D[0x03];
    s32 unk_20;
    u16 unk_24;
    u16 unk_26;
} ChkEffWork;

typedef struct Mode {
    const char* name;
    void (*unk_04)(void);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

void func_080010CC(Mode* mode, s32 b);
u16 GetKeysRepeat(void);
void func_08004E64(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgScroll(s32 a, u16 b, u16 c);
void SetBgPriority(s32 bg, u16 priority);
void SetBgBlend(s32 a, s32 b, s32 c);
void SetBlendAlpha(u16 a, u16 b);
void func_080062F4(s32 a, s32 b);
void func_080065FC(s32 a, s32 b, s32 c);
void func_0800675C(u8 a, s32 b, s32 c);
void func_08006778(void* a, s32 x, s32 y);
void func_08006954(void);
u8 func_08006B74(void);
void func_08006B80(u16* a, u16* b);
void func_0809D2B0(s32 a, s32 b, s32 c, const char* s);
void func_0809D458(s32 a, s32 b, s32 c, s32 v);

void mode_chkeff_0(void);
void mode_chkeff_1(void);
void mode_chkeff_2(void);

extern ChkEffWork* gUnk_020348B8;
extern u32 gFrameCounter;
extern u8 gUnk_08C6B0C4[];
extern u8 gUnk_08EEE384[];
extern u8 gUnk_08F683C4[];
extern Mode gUnk_09ECEB64;
extern void* gUnk_09ED9A1C[];
extern TaskDesc gUnk_09EE9190;
extern const char gUnk_081309E0[];
extern const char gUnk_081309E8[];
extern const char gUnk_081309F0[];
extern const char gUnk_08130A18[];
extern const char gUnk_08130A20[];
extern const char gUnk_08130A28[];
extern const char gUnk_08130A30[];
extern const char gUnk_08130A34[];
extern const char gUnk_08130A38[];

#endif /* GUARD_MODE_CHKEFF_H */
