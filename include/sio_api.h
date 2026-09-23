#ifndef GUARD_SIO_API_H
#define GUARD_SIO_API_H

#include "types.h"
#include "sio_types.h"

void SioReset(void);
u32 func_08006ED4(u8* a, u16* b, u16 (*c)[2]);
u32 func_0800702C(u8* a, u16* b, u16 (*c)[2]);
void func_080078A4(void);
u8 func_080078E8(void);

extern u8 gUnk_020397D0;
extern s16 gUnk_020397D4;
extern u16 gUnk_020397E0[4][2];
extern u32 gUnk_020397F0;
extern s32 (*gUnk_020397F8)(void);
extern u8 gUnk_020397FC;
extern u8 gUnk_02039800;
extern s32 (*gUnk_02039804)(void);
extern u16 gUnk_02039810[4][2];
extern u32 gSioStatus;
extern u8 gUnk_02039824;
extern u32 gSioPlayerId;
extern u8 gUnk_0203982C;
extern SioWork gSioWork;
extern u16 gUnk_02039B58[4];
extern u8 gUnk_02039B60;
extern u16 gUnk_02039B68[4];

#endif
