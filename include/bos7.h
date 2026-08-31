#ifndef GUARD_BOS7_H
#define GUARD_BOS7_H

#include "types.h"
#include "game.h"

typedef struct LstState {
    u16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A[0x04];
    u16 unk_12;
    u8 unk_14[0xB8];
    s16 unk_CC;
} LstState;

typedef struct LstWork {
    void* unk_00;
    LstState* unk_04;
} LstWork;

void func_080059A4(void* a, s32 b, s32 c);

void task_bos_lst_fld_2(void);
u8 func_08110918(LstWork* work);
void func_08110984(LstWork* work);
void func_08110994(LstWork* work, u16 a);
void func_081109A8(LstWork* work);
void func_08111660(LstWork* work);

#endif /* GUARD_BOS7_H */
