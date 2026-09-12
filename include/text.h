#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#include "text_types.h"

void func_08065ACC(TextSlot* slots, s32 count);
void func_08065AE0(TextSlot* slots, s32 count);
s16 func_08065B08(TextSlot* slots, u8 count);
s32 func_08065B54(u16* text);
u16 func_08065B6C(u16* text, TextSlot* slots);
void* _08066468(s32 palette);
void func_080664D8(s16 x, s16 y, TextSlot* slots, void* palette, u16 priority, u8 count);
void* func_080668F0(void);
void* func_08066904(void);

#ifdef VERSION_EU
void* eu_0805E924(void* strings);
#endif

#endif
