#ifndef GUARD_BTL_COLLISION_H
#define GUARD_BTL_COLLISION_H

#include "battle_actor_types.h"

s32 func_08011F78(s32 a, s32 x, s32 y, s32 z, s16 p, s16 q, s16 r);
void ColliderPoolsInit(void);
void ColliderInit(Collider* p, u32 type, u16 r, u16 h);
void ColliderUnregister(Collider* p);
void ColliderSetPosition(Collider* p, s32 x, s32 y, s32 z);
void ColliderUpdateAll(void);
void ColliderSetDisabled(Collider* p, u8 b);
void ColliderSetRadius(Collider* p, u16 r);
void ColliderSetHeight(Collider* p, u16 h);
u8 ColliderIsTouchingType(Collider* p, s32 bit);

struct FldObj;

u8 func_08011E3C(s32 x, s32 y, s32 z, s16 a, s16 b, s16 c);
s32 func_08011F68(s32 a, BtlObj* b);
void func_080121D4(struct FldObj* p);
void func_080121FC(struct FldObj* p);

#endif
