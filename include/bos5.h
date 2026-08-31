#ifndef GUARD_BOS5_H
#define GUARD_BOS5_H

#include "types.h"
#include "game.h"

typedef struct GaEntry {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x42];
} GaEntry;

void func_080F83E0(void* a, void* b);
void func_080F8374(void* a);

extern u8 gUnk_09992114[];
extern GaEntry gUnk_09992108[];

void task_bos_ga_2(u8* work);
void task_bos_ga_3(u8* work);
void task_bos_md_hahen_3(void** work);
void task_bos_md_fire_3(u8* work);
void task_bos_md_dai_3(void** work);
void func_080FB8E8(s32 unused, u16 index);
void func_080FB908(s32 unused, u16 index);

#endif /* GUARD_BOS5_H */
