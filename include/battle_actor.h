#ifndef GUARD_BATTLE_ACTOR_H
#define GUARD_BATTLE_ACTOR_H

#include "battle_actor_types.h"

struct EmyKind;

void WorldToScreen(s16* x, s16* y, s32 px, s32 py, s32 pz);
void func_08019190(BtlObj* p, s16 b);
s32 func_0801ADAC(BtlObj* p);
void func_0801AF08(BtlObj* p);
u16 func_0801AF1C(s32 y);
void func_0801AF4C(BtlObj* actor);
void func_0801B37C(BtlObj* p, struct EmyKind* d, s32 x, s32 y, s32 z);
void func_0801B7D8(BtlObj* obj);
void func_0801B918(BtlObj* p);
void func_0801B994(BtlObj* p);
void func_0801BBF0(BtlObj* p);
void func_0801BCD4(BtlObj* p);
void func_0801BCF8(BtlObj* p);
void func_0801BDD4(BtlObj* p, BtlObj* v);
void func_0801C700(BtlObj* a, s32* b, s32* c, s32* d);
u8 func_0801CA00(BtlObj* p);

#endif
