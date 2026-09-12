#ifndef GUARD_ANIM_H
#define GUARD_ANIM_H

#include "types.h"

typedef struct AnimFrame {
    u16 gfxIndex;
    u16 duration;
} AnimFrame;

typedef struct AnimHeader {
    u32 unk_00;
    u16 frameCount;
    u16 unk_06;
} AnimHeader;

typedef struct AnimState {
    AnimHeader** anims;
    u32* gfxTable;
    u16 flags;
    u16 timer;
    u16 frameCount;
    u16 frame;
    u16 animId;
    u16 unk_12;
    AnimFrame* frames;
} AnimState;

void AnimInit(AnimState* anim, void* anims, void* gfxTable);

void AnimStart(AnimState* anim, u16 animId, u16 flags);
void AnimChange(AnimState* anim, u16 animId, u16 flags);
void* AnimUpdate(AnimState* anim);
void* AnimGetGfx(AnimState* anim);
u8 AnimIsFinished(AnimState* anim);
u16 AnimGetId(AnimState* anim);
u16 AnimGetFrame(AnimState* anim);
u16 AnimGetGfxIndex(AnimState* anim);
void AnimSetFrame(AnimState* anim, u16 frame);
void AnimReset(AnimState* anim);

#endif
