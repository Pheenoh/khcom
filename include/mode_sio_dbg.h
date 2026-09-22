#ifndef GUARD_MODE_SIO_DBG_H
#define GUARD_MODE_SIO_DBG_H

#include "types.h"

void mode_sio_dbg_flg_0(s32 arg);
void mode_sio_dbg_flg_1(void);
void mode_sio_dbg_flg_2(void);
void func_080C7350(void);

#ifdef VERSION_EU
extern u16 gUnk_0203C3C4;
#else
extern s8 gUnk_0203C3C4;
#endif
extern u16 gUnk_0203C3C8;
extern u16 gUnk_0203C3CC;
extern u16 gUnk_0203C3D0;
#ifdef VERSION_EU
extern u16 gUnk_0203C3D4;
extern u16 gUnkEu_0203C9B4;
extern u16 gUnkEu_0203C9B8;
extern u16 gUnkEu_0203C9BC;
extern u16 gUnkEu_0203C9C0;
extern u16 gUnkEu_0203C9C4;
#else
extern s8 gUnk_0203C3D4;
#endif

#endif
