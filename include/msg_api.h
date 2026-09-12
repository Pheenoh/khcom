#ifndef GUARD_MSG_API_H
#define GUARD_MSG_API_H

#include "types.h"

#include "text_types.h"

void func_0806180C(u16 a);
#ifdef VERSION_US
s32 func_08064DD4(u16* a);
#else
s32 func_08064DD4(u8* a);
#endif
void func_080658B8(u8 n);
void func_08065940(void);
#ifdef VERSION_EU
s16 eu_0806629C(TextSlot* p, u8 n);
#endif
#ifdef VERSION_US
s32 func_080660C0(u16* a, void** p);
#else
s32 func_080660C0(u8* a, void** p);
#endif
void FreeSmallFontResources(void* a, void* b);
u16 EncodeSmallFontString(u8* s, u16* out);
u16 FormatSmallFontHex(s32 v, u16* out);
s32 DrawSmallFontString(s16 x, s16 y, u16* s, void* d, void* e, u16 h, u8 n);
void func_0806BA0C(s16 v, u8* out);
u16 func_0806BA74(s32 mode, s32 flag);
void func_0806C2C0(u8 n);
void func_0806C34C(void);
s16 func_08075064(u8 a);

#endif
