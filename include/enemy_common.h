#ifndef GUARD_ENEMY_COMMON_H
#define GUARD_ENEMY_COMMON_H

#include "types.h"

struct EmyDef;
struct EmyObj;
struct EmyWork;

void func_0800C778(struct EmyWork* work, struct EmyDef* def, struct EmyObj* obj);
s16 func_0800C980(struct EmyWork* work, s16 a, s16 b, s16 c, s32 d, s16 e, u16 f, s16 g, s16 h, u16 i);
void func_0800CB4C(struct EmyWork* work);
u8 _0800CBDC(struct EmyWork* work);
void func_0800CD40(struct EmyWork* work);
s32 _0800CDF0(struct EmyWork* work);
void func_0800DF30(struct EmyWork* work);
void func_0800E0D0(struct EmyWork* work);

#endif
