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
void func_080C6894(struct CharaObjParam* param);
u8 func_080C69B4(void);
void func_080C6EB0(u8* src, u8* dst, u16 size, s16 count);

#endif
