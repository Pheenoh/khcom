#ifndef GUARD_EVENTSELECT_API_H
#define GUARD_EVENTSELECT_API_H

#include "types.h"

struct EventTaskHost;
struct UnkStruct_02039DD0;

extern struct UnkStruct_02039DD0* gUnk_02039DD0;

void func_08076110(u16 song, s16 x, s16 y);
void CreateTinkerbellTask(struct EventTaskHost* h);
void CreateDownTask(struct EventTaskHost* h);
void CreateSmokeTask(struct EventTaskHost* h);
void CreateExclamationTask(struct EventTaskHost* h);
void CreateBalloonTask(struct EventTaskHost* h);
void CreateQuestionTask(struct EventTaskHost* h);
void CreateGlowNoseTask(struct EventTaskHost* h);
void CreateHanabiraTask(struct EventTaskHost* h);

#endif
