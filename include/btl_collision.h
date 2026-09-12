#ifndef GUARD_BTL_COLLISION_H
#define GUARD_BTL_COLLISION_H

#include "battle_actor_types.h"

s32 func_08011F78(s32 a, s32 x, s32 y, s32 z, s16 p, s16 q, s16 r);
void func_0801227C(void);
void func_080122AC(Collider* p, u32 type, u16 r, u16 h);
void func_08012304(Collider* p);
void func_08012324(Collider* p, s32 x, s32 y, s32 z);
void func_080125A4(void);
void func_08012614(Collider* p, u8 b);
void ColliderSetRadius(Collider* p, u16 r);
void ColliderSetHeight(Collider* p, u16 h);
u8 func_08012660(Collider* p, s32 bit);

struct FldObj;

u8 func_08011E3C(s32 x, s32 y, s32 z, s16 a, s16 b, s16 c);
s32 func_08011F68(s32 a, BtlObj* b);
void func_080121D4(struct FldObj* p);
void func_080121FC(struct FldObj* p);

#endif
