#ifndef GUARD_BOS4_H
#define GUARD_BOS4_H

#include "types.h"
#include "game.h"

u8 func_080DEBAC(u8 a);
void func_080DEC44(void);
u8* func_080DED98(u8 a);
void func_080D2C78(s32 a);
void func_080D2DB0(s32 a);
void func_080D2DC4(s32 a);
s32 func_080E5590(u8 a);
void func_080E04EC(void);

u16 func_080DDEA0(u16* p);
void func_080DDEA4(s32 a);
void func_080DDEB0(s32 a);
void func_080DDEBC(s32 a);
void func_080DDDDC(u8* p, void* q);
u8* func_080DEE18(u8 index);
u8 func_080DEE28(u8 a, u8 b);
u32 func_080DF804(u8 index);
void func_080DF730(u8 a, u8 b);
void func_080DF814(void);
s32 func_080DFB7C(u8 a);
u8 func_080DC510(void);
u8 func_080DC528(void);
u8 func_080DA73C(void);

void task_bos_boogie_knifereader_2(u8* work);
void task_bos_boogie_knifereader_3(u8* work);
void task_bos_boogie_mapanime_2(void);
void task_bos_boogie_mapanime_3(void);
void task_bos_ursula_thunder_2(void);
void task_bos_ursula_thunder_3(void);
void task_bos_ursula_map_3(void);
s32 task_bos_ursula_border_1(void);
void task_bos_ursula_bubble_2(u8* work);
void task_bos_ursula_bubble_3(u8* work);
void task_bos_ursula_mapanime_2(u8* work);
void task_bos_ursula_mapanime_3(u8* work);

#endif /* GUARD_BOS4_H */
