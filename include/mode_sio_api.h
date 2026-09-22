#ifndef GUARD_MODE_SIO_API_H
#define GUARD_MODE_SIO_API_H

#include "types.h"
#include "chara_types.h"

void func_080B31A0(void);

extern u16 gUnk_0203A9EC;
extern u16 gUnk_0203A9F0;
extern s8 gUnk_0203AA00;
extern CharaLinkData gUnk_0203AA10;
extern u8 gUnk_0203AA30[2][20];
extern u8 gUnk_0203AA58[2];
extern u8 gUnk_0203AA60[2][20];
extern u8 gUnk_0203AA88;
extern s8 gUnk_0203AA8C;
extern s8 gUnk_0203AA90;
extern s8 gUnk_0203AAA0[14];
extern u8 gUnk_0203AAB0;
extern CharaLinkData gUnk_0203AAC0;
extern u8 gUnk_0203AAE0[2][20];
#ifdef VERSION_EU
extern s8 gUnkEu_0203B108[2];
#endif
#ifndef VERSION_EU
extern s8 gUnk_0203AB10;
extern u16 gUnk_0203AB20[10];
extern s8 gUnk_0203AB34[2];
#endif

#endif
