#ifndef GUARD_BTL_EFFECT_H
#define GUARD_BTL_EFFECT_H

#include "battle_actor_types.h"

u8 func_080128EC(void);
void func_08014780(s32 x, s32 y, s32 z);

void func_08012798(u16 a, u16 bg);
void func_08012810(void);
void func_08012824(void);
void func_08012AAC(u16 a, s32 x, s32 y, s32 z);
void func_08012E44(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w);
void func_08012F74(s32 x, s32 y, s32 z, u8 f, s32 unused, s32 w, u16 a);
void func_08013308(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w);
void func_08013480(s32 x, s32 y, s32 z);
void func_08013994(s32 x, s32 y, s32 z);
void func_08013A68(s32 x, s32 y, s32 z);
void func_08013CB4(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q);
void func_08013DB8(s32 x, s32 y, s32 z, s32 s);
void func_08013E4C(s32 x, s32 y, s32 z, s32 s);
void func_08013EDC(s32 x, s32 y, s32 z, s32 s);
void func_08013F5C(s32 x, s32 y, s32 s, u16 b, u16 c);
void func_08014020(s32 x, s32 y, s32 z);
void func_080140C0(s32* a, s32* b, s32* c);
void func_080140E0(s32 x, s32 y, s32 z);
void func_0801416C(s32 x, s32 y, s32 z);
void func_080141FC(BtlObj* p);
void func_08014588(s32 x, s32 y, s32 z, s32 w, s32 a, s32 b);
void func_0801475C(s32 a, s32 b, s32 c);
void func_08014790(u8 bit);
void func_080147A8(s32 a, s32 b, s32 c);
void func_080147B8(u8 a);
void func_080147C8(s32 a, s32 b);
void func_080147D8(s32 x, s32 y);
void func_080148E0(u16 a, s32 x, s32 y, s32 z, s32 w);
void func_080149BC(s32 x, s32 y);
void func_08014A34(s32 x, s32 y);
void func_08014AAC(s32 x, s32 y);
void func_08014B30(s32 x, s32 y);
void func_08014D78(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w);
void func_08014EC0(s32 x, s32 y, s32 z, s32 w);
void func_08014FDC(s32 x, s32 y, u8 f);
void func_080150D8(s32 x, s32 y, s32 z, u8 f);
void func_08015228(s32 x, s32 y, s32 z, s32 s);
void func_0801536C(void);
void func_080154F4(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s, u16 a, s32 t);
void func_080155BC(s32 x, s32 y, s32 z, s32 w);
void func_08015834(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s);
void func_08015B50(u16 a, s32 x, s32 y, s32 z, u8 f, s32 w);
void func_08015D30(s32 x, s32 y, s32 z);
void func_08015DC8(s32 x, s32 y, s32 z);
void func_08015F3C(s32 x, s32 y, s32 z);
void func_08016038(s32 x, s32 y, s32 z);
void func_080165DC(s32 x, s32 y, s32 z);
void func_08016684(s32 x, s32 y, s32 z);
void func_08016750(s32 x, s32 y, s32 z, u8 f);
void func_080168B8(s32 x, s32 y, s32 z, u8 f, s32 w, u16 a);
void func_080169A0(s32 x, s32 y, s32 z, u8 f);
void func_08016C40(s32 x, s32 y, s32 z, s32 w, u8 f, u16 a);
void func_08016F2C(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w);
void func_08017008(s32 x, s32 y, s32 z);
void func_08017138(u16 a);
void func_080171FC(u16 a);
void func_08017260(s32 x, s32 y, s32 z, s32 s);
void func_080172F8(s32 x, s32 y, s32 z, s32 s);
void func_08017390(s32 x, s32 y, s32 z);
void func_08017514(s32 x, s32 y, s32 z, s32 w);
void func_080179F8(s32 x, s32 y, s32 z, s32 w, u8 f);
void func_08017B74(s32 x, s32 w);
void func_08017F70(s32 x, s32 y, s32 z, s32 w);
void func_0801801C(s32 x, s32 y, s32 z, s32 w);
void func_08018184(s32 x, s32 y, s32 z, s32 w);
void func_0801836C(s32 x, s32 y, s32 z, s32 w, s32 v);
void func_080184C4(s32 x, s32 y, s32 z, u8 f);
void func_0801853C(s32 x, s32 y, s32 z, s32 s);
void func_080188E4(u16 a, s32 x, s32 y, s32 z, s32 w);
void func_08018970(s32 x, s32 y, s32 z);
void func_080189DC(s32 x, s32 y, s32 z, s32 s);
void func_08018A70(s32 x, s32 y, s32 z, s32 s);
void func_08018B04(s32 x, s32 y, s32 z, s32 s);
void func_08018C38(s32 x, s32 y, s32 z);
void func_08018F28(s32 x, s32 y, s32 z);
void func_08018FE4(s32 x, s32 y, s32 z);

#endif
