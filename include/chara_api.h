#ifndef GUARD_CHARA_API_H
#define GUARD_CHARA_API_H

#include "types.h"

struct CharaObjParam;
struct CharaObjParam2;

u8 func_080C54B4(void);
u8 func_080C55DC(void);
void func_080C57A4(void);
void func_080C57B4(void);
u8 func_080C5930(void);
void func_080C5A3C(void (*a)(void), void (*b)(void), u8 c);
void func_080C5D00(void);
s32 func_080C5D50(void);
s32 func_080C5D80(void);
void func_080C5DC0(s32 (*a)(void), s32 (*b)(void));
s32 func_080C5E58(void);
s32 func_080C5ECC(void);
void func_080C5F94(void);
s32 func_080C6008(void);
s32 func_080C60D8(void);
void func_080C61D4(void);
void func_080C640C(struct CharaObjParam2* param);
u8 func_080C64A4(void);
void func_080C6894(struct CharaObjParam* param);
u8 func_080C69B4(void);
void func_080C6EB0(u8* src, u8* dst, u16 size, s16 count);

extern u32 gUnk_0203BD10[100];
extern u32 gUnk_0203BEA0;
extern s16 gUnk_0203BEA4;
extern s16 gUnk_0203BEA8;
extern void (*gUnk_0203BEAC)(void);
extern u32 gUnk_0203BEB0;
extern s16 gUnk_0203BEB8;
extern u32 gUnk_0203BEBC;
extern u32 gUnk_0203BEC0[100];
extern u32 gUnk_0203C050[100];
extern u32 gUnk_0203C1E0[100];
extern u16 gUnk_0203C370;
extern s8 gUnk_0203C374;
extern u16 gUnk_0203C378;
extern u16* gUnk_0203C37C;
extern s8 gUnk_0203C380;
extern s8 gUnk_0203C384;
extern u16 gUnk_0203C388;
extern s8 gUnk_0203C38C;
extern u16* gUnk_0203C390;
#ifdef VERSION_EU
extern u16 gUnkEu_0203C964;
#endif
extern u16 gUnk_0203C394;
extern u16* gUnk_0203C398;
#ifdef VERSION_EU
extern u16 gUnkEu_0203C970;
#endif
extern u16* gUnk_0203C39C;
extern s8 gUnk_0203C3A0;
#ifdef VERSION_EU
extern u16 gUnkEu_0203C97C;
#endif
extern s8 gUnk_0203C3A4;
extern s8 gUnk_0203C3A8;
extern void (*gUnk_0203C3AC)(void);
extern u16 gUnk_0203C3B0;
extern u16 gUnk_0203C3B4;
extern u16 gUnk_0203C3B8;

#endif
