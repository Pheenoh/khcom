#ifndef GUARD_BTL2_API_H
#define GUARD_BTL2_API_H

#include "types.h"

struct FldActor;
struct FldPos;
struct FldWork;

u8 func_08031D74(struct FldPos* p);
s32 func_08031DF8(struct FldPos* p);
u8 func_08031E48(struct FldPos* p, struct FldWork* work);
u8 func_08031EC4(struct FldActor* act);
s32 func_08031F1C(struct FldWork* work);
void func_08031F60(struct FldActor* act);
void func_08031F98(struct FldWork* work, s32 a, s32 b);

#endif
