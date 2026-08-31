#ifndef GUARD_BOS2_H
#define GUARD_BOS2_H

#include "types.h"
#include "game.h"

void task_bos_dsd_rock_3(void);
void task_bos_dsd_circle_3(void);
void task_bos_dsd_energy2_3(void);
void task_bos_dsd_ita_3(u8* work);
void task_bos_jf_2(u8* work);
void task_bos_dsd_2(u8* work);
void task_bos_dsd_3(u8* work);
void task_bos_tm_tbl_3(u8* work);
void task_bos_tm_clb_3(void** work);
void func_080BA0E4(s32* p, s32 a, s32 b, s32 c);
void func_080BA0F8(u8* work);
void func_080BB428(u8* dst, u8* src);
void func_080BB43C(u8* work, u8* src, u16 a, u8* dst);
void func_080C211C(u8 index);
void func_080C43E4(s32* p, s32 target);

#endif /* GUARD_BOS2_H */
