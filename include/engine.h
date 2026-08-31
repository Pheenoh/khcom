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
void ReleaseObjPalette(u8* p);
void func_08004FC8(s32 a);
void* GetBgScreenBase(s32 a);
void LoadBgMap(s32 bg, void* src, u16 size);
void RequestDma3Copy(void* src, void* dst, u16 size);
void func_080058FC(s32* value, s32 target, u16 steps);
void AnimInit(AnimState* a, s32 b, s32 c);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
u8 AnimIsFinished(AnimState* a);

#endif /* GUARD_ENGINE_H */
