#ifndef GUARD_FADE_H
#define GUARD_FADE_H

#include "types.h"

void FadeReset(void);
void FadeUpdate(void);
void FadeStartIn(s32 mode, u16 frames);
void FadeStartOut(s32 mode, u16 frames);
void FadeToOriginal(s32 mode, u16 frames);
void FadeToAmount(s32 mode, u16 amount, u16 frames);
void FadeFromAmount(s32 mode, u16 amount, u16 frames);
void FadeSetPaletteExcluded(u16 slot, u8 excluded);
u8 FadeIsActive(void);
void FadeLock(void);
void FadeSetPaused(u8 on);

void FadeClearPaletteSlot(u16 slot);
u16 FadeGetAmount(void);
u16 FadeGetColor(void);

#endif
