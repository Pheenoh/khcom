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

extern vu16* const gBgControl[];
extern u8 gBgPaletteBank[];
extern u16 gUnk_03007500;

void func_0800284C(u8* p);
void func_08002880(u8* p);
void func_080028A0(u8* p);
void ReleaseObjTiles(void* a);
void func_08002A10(void* a, void* b);
void func_08002BCC(void* a);
void ReleaseObjPalette(u8* p);
void func_08004FC8(s32 a);
void func_0800501C(s32 bg);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgPriority(s32 bg, u16 priority);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void func_080058FC(s32* value, s32 target, u16 steps);
void AnimInit(AnimState* a, s32 b, s32 c);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
u8 AnimIsFinished(AnimState* a);
u16 func_08005B34(AnimState* a);
void LoadPalette(void* src, void* dst, s32 size);

#endif /* GUARD_ENGINE_H */
