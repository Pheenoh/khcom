#ifndef GUARD_MODE_SIO2_API_H
#define GUARD_MODE_SIO2_API_H

#include "types.h"

struct PoohNear;
struct PoohPos;
struct PoohWork;

void func_080C75A4(u32 a, u16 b);
void func_080C736C(void);
void func_080C73A4(u16 r, u16 g, u16 b);
void func_080C7568(u32 a, u16 b);
void func_080C73D8(void);
void func_080C7350(void);
void func_080C7684(s32 a, s32 b, s32 c);
u8 func_080C76B0(struct PoohNear* p);
void func_080C7B84(u32 a);
void func_080C7BCC(u16 a);
u16 func_080C7BF8(u8 kind, u8 count, s32 x, s32 y, s32 z);
void func_080C7CB0(u8 a);
u8 func_080C7CBC(void);
void func_080C7CC8(struct PoohWork* w);
void func_080C7FEC(struct PoohWork* w, u32 anim);
u8 func_080C83C4(u16 x, u16 y, u16 px, u16 py);
s32 func_080C8404(struct PoohPos* a, struct PoohPos* b);
void func_080C84E0(struct PoohWork* w, u32 b);

#endif
