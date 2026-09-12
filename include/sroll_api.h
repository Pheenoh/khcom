#ifndef GUARD_SROLL_API_H
#define GUARD_SROLL_API_H

#include "types.h"

struct SrollBCharWork;
struct SrollInit;
struct SrollWork;

void func_081149B0(struct SrollBCharWork* w, s32 v);
s32 func_08115FBC(struct SrollWork* w, u8* s);
void func_081160EC(struct SrollWork* w, u32 mode);
void func_0811614C(struct SrollWork* w, struct SrollInit* a);
void func_08116268(struct SrollWork* w, u16 a, u16 b, u16 c, u16 d);
void func_081166F8(struct SrollWork* w, u16 x, u16 y, u16 cw, u16 ch, u8 flush);
void func_08116BEC(struct SrollWork* w, u16 x, u16 y, u8* s, u8 flush);
void func_08116CEC(void);
void func_08116E00(vu16* dst, u8* src, u32 cnt);
void func_08116E60(u8* src);
void func_08116E80(void);
void func_08116E8C(void);
void func_08116E98(void);
void func_08116ECC(void);
void func_08116F08(void);

#endif
