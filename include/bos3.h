#ifndef GUARD_BOS3_H
#define GUARD_BOS3_H

#include "types.h"
#include "game.h"

typedef struct JfShadowWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    UnkStruct_02039B84* unk_0C;
} JfShadowWork;

void task_bos_jf_shadow_0(JfShadowWork* work, UnkStruct_02039B84* obj);
s32 task_bos_jf_shadow_1(void);
void task_bos_jf_shadow_2(JfShadowWork* work);
void task_bos_jf_shadow_3(JfShadowWork* work);
void func_080C6FF8(void);
void func_080C700C(u16* out);
void func_080C7024(u16* in);

#endif /* GUARD_BOS3_H */
