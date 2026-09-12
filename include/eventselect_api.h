#ifndef GUARD_EVENTSELECT_API_H
#define GUARD_EVENTSELECT_API_H

#include "types.h"

void func_080763F0(void);
void func_08076318(void);
void func_08076324(void);
void func_08076330(void);
void func_0807633C(void);
void func_08076348(void);
void func_08076394(void);
u8 func_080763D0(void);
u8 func_0807643C(void);
void func_08076360(void);
void func_08076374(void);
void func_08076300(void);
void func_080762B8(void);
void func_080762C4(void);
void func_080762D0(void);
void func_080762DC(void);
void func_080762E8(void);
void func_080762F4(void);
void func_08076110(u16 song, s16 x, s16 y);
void func_08076284(void);
void func_08076290(void);
void func_0807629C(void);
void func_0807630C(void);

struct CardSlot;
struct EventTaskHost;
struct UnkStruct_08078754;
struct UnkStruct_08080268;

s32 func_08076F80(struct UnkStruct_08080268* w, u8* task);
struct CardSlot* func_08076674(struct UnkStruct_08078754* w, u8 slot, u16* n);
struct CardSlot* func_08076750(struct UnkStruct_08078754* w, u8 slot, u16* n);
void func_08075E60(struct EventTaskHost* h);

#endif
