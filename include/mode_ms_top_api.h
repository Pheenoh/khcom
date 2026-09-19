#ifndef GUARD_MODE_MS_TOP_API_H
#define GUARD_MODE_MS_TOP_API_H

#include "types.h"

u32 GetMooglePoints(void);
void SetMooglePoints(u32 a);
u8 SpendMooglePoints(u32 a);
u8 AddMooglePoints(u32 a);
void LoadDecimalDigitTiles(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void mode_ms_top_0(u32 a);
void mode_ms_top_1(void);
void mode_ms_top_2(void);

#endif
