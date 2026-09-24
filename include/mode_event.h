#ifndef GUARD_MODE_EVENT_H
#define GUARD_MODE_EVENT_H

#include "mode.h"
#include "taskpool.h"

typedef struct EvtArg {
    u32 unk_00 : 8;
    u32 unk_08 : 8;
    u32 unk_10 : 16;
} EvtArg;

extern Mode gUnk_09EE273C;
extern Mode gUnk_09EE274C;
extern TaskPool gEventTaskPool;
extern u32 gUnk_02034A78;

void func_08061824(void);
void func_08061FC8(void);
void func_0806250C(void);
void func_0806297C(void);
u8 func_080629CC(void);
void func_080629F8(void);
void func_08062CE4(void);
void func_08062D20(void);
void func_08062D3C(void);

#endif
