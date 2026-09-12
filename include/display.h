#ifndef GUARD_DISPLAY_H
#define GUARD_DISPLAY_H

#include "types.h"

void SetBgMode0(void);
void SetBgMode1(void);
void SetBgMode2(void);
void SetBgMode3(void);
void EnableBg(s32 bg);
void DisableBg(s32 bg);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void SetBgScroll(s32 bg, s32 x, s32 y);
void SetBgPriority(s32 bg, u16 priority);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void LoadPalette(void* src, void* dst, u16 size);
void LoadObjPaletteBank(u16 bank, void* src);
void SetBlendAlpha(u16 a, u16 b);

void SetBackdropColor(u32 r, u32 g, u32 b);
void SetBgBlend(s32 bg, u16 a, u16 b);
void SetBgSize(s32 bg, u16 size);
void SetBgAffine(s32 bg, u8 rot, s32 sx, s32 sy, s32 dx, s32 dy);
void func_0800516C(s32 bg, void* src, u8 w, u8 h);
void func_080051C4(s32 bg, u16 x, u16 y);
void func_08005244(s32 bg, u16 x, u16 y);
void SetBgColorMode(s32 bg, u16 mode);
void SetBgOverflow(s32 bg, u8 on);
void SetObjMosaicSize(u8 x, u8 y);

#ifdef VERSION_EU
void eu_080059D4(s32 bg, void* src);
void eu_080059F4(s32 bg, void* src);
#endif

#endif
