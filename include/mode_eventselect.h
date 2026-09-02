#ifndef GUARD_MODE_EVENTSELECT_H
#define GUARD_MODE_EVENTSELECT_H

#include "types.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "game.h"
#include "card.h"

extern u32 gUnk_02034A9C;
extern u32 gUnk_02034AA0;
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_0905EEE6[];
extern u8 gUnk_09611AB8[];

void func_080062F4(u16 a, s32 b);
void TaskPoolInit(TaskPool* pool, s32 count);
void func_0807B668(UnkStruct_02039DD4* p);
void func_0807E23C(void);
void func_0807E248(void);

void func_08076284(void);
void func_08076290(void);
void func_0807629C(void);
u8 func_080762A8(void);
void func_080762B8(void);
void func_080762C4(void);
void func_080762D0(void);
void func_080762DC(void);
void func_080762E8(void);
void func_080762F4(void);
void func_08076300(void);
void func_0807630C(void);
void func_08076318(void);
void func_08076324(void);
void func_08076330(void);
void func_0807633C(void);
void func_08076348(void);
void func_08076354(void);
void func_08076360(void);
void func_08076374(void);
void func_08076388(void);
void func_08076394(void);
void func_080763A0(void);
void func_080763AC(void);
void func_080763B8(void);
void func_080763C4(void);
u8 func_080763D0(void);
void func_080763F0(void);
void func_08076438(void);
u8 func_0807643C(void);
void func_08076458(void);

#endif
