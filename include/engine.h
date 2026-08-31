#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include "types.h"

typedef struct AnimFrame {
    u16 unk_00;
    u16 unk_02;
} AnimFrame;

typedef struct AnimState {
    s32 unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x04];
    AnimFrame* unk_14;
} AnimState;

void func_08002BCC(void* a);
void func_08002C10(u8* p);
void func_08004FC8(s32 a);
void* func_0800514C(s32 a);
void func_0800510C(s32 a, void* b, u16 c);
void func_080043B4(void* dst, void* src, u16 size);
void func_080058FC(AnimState* a, s32 target, u16 steps);
void func_08005968(AnimState* a, s32 b, s32 c);
void* func_08005A64(AnimState* a);
void* func_08005AFC(AnimState* a);
u8 func_08005B1C(AnimState* a);

#endif /* GUARD_ENGINE_H */
