#ifndef GUARD_PALLET_H
#define GUARD_PALLET_H

#include "types.h"

#define REG_VCOUNT (*(vu16*)0x04000006)
#define REG_BGHOFS(n) (*(vu16*)(0x04000010 + (n) * 4))

typedef struct PaletteBuffer {
    u16 colors[512];
    u16 banks[32];
} PaletteBuffer;

typedef struct PaletteWave {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
} PaletteWave;

extern PaletteWave gBgWaves[];
extern s16 gSineTable[];
extern u8 sPalletHeapName[];
extern s32 gUnk_08121694[];

u16* FadePaletteToBlack(u16* src, u16* dst, u16 size, u16 amount);
u16* FadePaletteToGray(u16* src, u16* dst, u16 size, u16 amount);
u16* FadePaletteToWhite(u16* src, u16* dst, u16 size, u16 amount);
u16* BrightenPalette(u16* src, u16* dst, u16 size, u16 amount);
u16* LoadPaletteBuffered(void* src, u16* dst, u16 size);
u16* func_08007DD8(u8 bank);
void ResetPaletteEffect(void);
u16* LoadPaletteWithEffect(void* src, u16* dst, u16 size);
s16 GetPaletteEffect(void);
void SetPaletteEffect(s16 a);
void PushPaletteEffect(s32 a);
void PopPaletteEffect(void);
void PalletInit(void);
void PalletFree(void);
void PalletClear(void);
void func_08007F20(u16 bank, u8 a);
u16* FadeAllPalettesToBlack(u16* src, u16 amount);
u16* FadeAllPalettesToWhite(u16* src, u16 amount);
void StartBgWave(s32 a);
void SetBgWaveParams(s32 a, u8 b, u8 c);
void EnableBgWave(s32 a);
void DisableBgWave(s32 a);
void HBlankIntrBgWave1(s32 a);
void StopBgWave(s32 a);
void HBlankIntrBgWave(void);
void StopAllBgWaves(void);

#endif /* GUARD_PALLET_H */
