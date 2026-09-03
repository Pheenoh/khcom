#ifndef GUARD_UNK_0810FE94_H
#define GUARD_UNK_0810FE94_H

#include "types.h"
#include "main.h"

typedef struct LstFldWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
} LstFldWork;

extern const s8* const gUnk_09EF9E6C[];

void func_0810FE94(void);
void func_0810FEBC(s16 a);
void func_0810FEDC(void);
s32 func_0810FF44(void);
void func_0810FF50(Task* t, s32 a, s32 b);
void func_0810FF64(Task* t, s32 a);
void func_0810FF6C(Task* t, s32 a);

#endif /* GUARD_UNK_0810FE94_H */
