#ifndef GUARD_ROOM_API_H
#define GUARD_ROOM_API_H

#include "types.h"

struct GaEntryWork;
struct GaWork;

s32 func_080F7E0C(s32 x0, s32 y0, s32 x1, s32 y1);
void func_080F7E84(struct GaEntryWork* e);
void func_080F7F54(struct GaWork* work, s32 state);
void func_080F80FC(struct GaWork* work, u32 i, s32 c);
void func_080F8374(struct GaEntryWork* e);
void func_080F83E0(struct GaWork* work, struct GaEntryWork* e);
u8 func_080F8958(struct GaWork* work);
u8 func_080F9744(struct GaWork* work);
u8 func_080F99C0(struct GaWork* work);
u8 func_080F9C2C(struct GaWork* work);
u8 func_080FA2B4(struct GaWork* work);
u8 func_080FAA18(struct GaWork* work);

#endif
