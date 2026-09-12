#ifndef GUARD_BTL2_TASKS_H
#define GUARD_BTL2_TASKS_H

#include "types.h"

struct BtlEscapeWork;
struct BtlHpenmWork;
struct BtlHpplyWork;
struct BtlObj;
struct BtlPauseWork;
struct BtlPopWork;
struct BtlPremireSrc;
struct BtlPremireWork;
struct BtlPrizeWork;
struct BtlShadowWork;
struct BtlStartWork;

void task_btl_shadow_0(struct BtlShadowWork* work, struct BtlObj* actor);
s32 task_btl_shadow_1(void);
void task_btl_shadow_2(struct BtlShadowWork* work);
void task_btl_shadow_3(struct BtlShadowWork* work);
void task_btl_hpply_0(struct BtlHpplyWork* work);
s32 task_btl_hpply_1(struct BtlHpplyWork* work);
void task_btl_hpply_2(struct BtlHpplyWork* work);
void task_btl_hpply_3(struct BtlHpplyWork* work);
void task_btl_hpenm_0(struct BtlHpenmWork* work);
s32 task_btl_hpenm_1(struct BtlHpenmWork* work);
void task_btl_hpenm_2(struct BtlHpenmWork* work);
void task_btl_hpenm_3(struct BtlHpenmWork* work);
void task_btl_pause_0(struct BtlPauseWork* work);
s32 task_btl_pause_1(struct BtlPauseWork* work);
void task_btl_pause_2(struct BtlPauseWork* work);
void task_btl_pause_3(struct BtlPauseWork* work);
void task_btl_pop_0(struct BtlPopWork* work, struct BtlPremireSrc* src);
s32 task_btl_pop_1(struct BtlPopWork* work);
void task_btl_pop_2(struct BtlPopWork* work);
void task_btl_pop_3(struct BtlPopWork* work);
void task_btl_escape_0(struct BtlEscapeWork* work);
s32 task_btl_escape_1(struct BtlEscapeWork* work);
void task_btl_escape_2(struct BtlEscapeWork* work);
void task_btl_escape_3(struct BtlEscapeWork* work);
void task_btl_prize_0(struct BtlPrizeWork* work, struct BtlPremireSrc* src);
s32 task_btl_prize_1(struct BtlPrizeWork* work);
void task_btl_prize_2(struct BtlPrizeWork* work);
void task_btl_prize_3(struct BtlPrizeWork* work);
void task_btl_premire_0(struct BtlPremireWork* work, struct BtlPremireSrc* src);
s32 task_btl_premire_1(struct BtlPremireWork* work);
void task_btl_premire_2(struct BtlPremireWork* work);
void task_btl_premire_3(struct BtlPremireWork* work);
void task_btl_start_0(struct BtlStartWork* work);
s32 task_btl_start_1(struct BtlStartWork* work);

#endif
