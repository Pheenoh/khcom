#ifndef GUARD_BTL3_TASKS_H
#define GUARD_BTL3_TASKS_H

#include "types.h"

struct BtlBadStatusWork;
struct BtlBornArgs;
struct BtlBornWork;
struct BtlFormList;
struct BtlFormWork;
struct BtlObj;
struct BtlRaidArgs;
struct BtlRaidWork;

void task_btl_form_0(struct BtlFormWork* work, struct BtlFormList* list);
u8 task_btl_form_1(struct BtlFormWork* work);
void task_btl_form_3(void);
void task_btl_born_0(struct BtlBornWork* work, struct BtlBornArgs* args);
u8 task_btl_born_1(struct BtlBornWork* work);
void task_btl_raid_0(struct BtlRaidWork* work, struct BtlRaidArgs* args);
u8 task_btl_raid_1(struct BtlRaidWork* work);
void task_btl_raid_2(struct BtlRaidWork* work);
void task_btl_raid_3(struct BtlRaidWork* work);
void task_btl_badstatus_0(struct BtlBadStatusWork* work, struct BtlObj* obj);
u8 task_btl_badstatus_1(struct BtlBadStatusWork* work);
void task_btl_badstatus_2(struct BtlBadStatusWork* work);
void task_btl_badstatus_3(struct BtlBadStatusWork* work);

#endif
