#ifndef GUARD_FRD_TASKS_H
#define GUARD_FRD_TASKS_H

#include "types.h"

struct FrdAladdinWork;
struct FrdArgs;
struct FrdArielWork;
struct FrdBeastWork;
struct FrdDonaldWork;
struct FrdGoofyWork;
struct FrdJackWork;
struct FrdPanWork;

void task_frd_donald_0(struct FrdDonaldWork* work, struct FrdArgs* args);
u8 task_frd_donald_1(struct FrdDonaldWork* work);
void task_frd_donald_2(struct FrdDonaldWork* work);
void task_frd_donald_3(struct FrdDonaldWork* work);
void task_frd_goofy_0(struct FrdGoofyWork* work, struct FrdArgs* args);
u8 task_frd_goofy_1(struct FrdGoofyWork* work);
void task_frd_goofy_2(struct FrdGoofyWork* work);
void task_frd_goofy_3(struct FrdGoofyWork* work);
void task_frd_ariel_0(struct FrdArielWork* work, struct FrdArgs* args);
u8 task_frd_ariel_1(struct FrdArielWork* work);
void task_frd_ariel_2(struct FrdArielWork* work);
void task_frd_ariel_3(struct FrdArielWork* work);
void task_frd_jack_0(struct FrdJackWork* work, struct FrdArgs* args);
u8 task_frd_jack_1(struct FrdJackWork* work);
void task_frd_jack_2(struct FrdJackWork* work);
void task_frd_jack_3(struct FrdJackWork* work);
void task_frd_pan_0(struct FrdPanWork* work, struct FrdArgs* args);
u8 task_frd_pan_1(struct FrdPanWork* work);
void task_frd_pan_2(struct FrdPanWork* work);
void task_frd_pan_3(struct FrdPanWork* work);
void task_frd_aladdin_0(struct FrdAladdinWork* work, struct FrdArgs* args);
u8 task_frd_aladdin_1(struct FrdAladdinWork* work);
void task_frd_aladdin_2(struct FrdAladdinWork* work);
void task_frd_aladdin_3(struct FrdAladdinWork* work);
void task_frd_beast_0(struct FrdBeastWork* work, struct FrdArgs* args);
u8 task_frd_beast_1(struct FrdBeastWork* work);
void task_frd_beast_2(struct FrdBeastWork* work);
void task_frd_beast_3(struct FrdBeastWork* work);

#endif
