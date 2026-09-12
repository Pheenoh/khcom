#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#include "text_types.h"

void InitTextSlots(TextSlot* slots, s32 count);
void FreeTextSlots(TextSlot* slots, s32 count);
s16 GetTextSlotsWidth(TextSlot* slots, u8 count);
s32 func_08065B54(u16* text);
u16 LoadTextSlots(u16* text, TextSlot* slots);
void* _08066468(s32 palette);
void DrawTextSlots(s16 x, s16 y, TextSlot* slots, void* palette, u16 priority, u8 count);
void* LoadSmallFontTiles(void);
void* LoadSmallFontPalette(void);

#ifdef VERSION_EU
void* eu_0805E924(void* strings);
#endif

#endif
