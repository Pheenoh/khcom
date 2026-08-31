#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include "types.h"

typedef struct AnimFrame {
    u16 unk_00;
    u16 unk_02;
} AnimFrame;

typedef struct ObjTiles {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u8 unk_0C[0x10];
    u8 unk_1C[0x04];
    u32 unk_20;
    u8 unk_24;
    u8 unk_25[0x03];
    u32 unk_28;
    struct ObjTiles* unk_2C;
} ObjTiles;

typedef struct PaletteSlot {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x20];
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x02];
} PaletteSlot;

typedef struct Dma3Request {
    void* src;
    void* dst;
    u16 size;
} Dma3Request;

typedef struct AnimHeader {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
} AnimHeader;

typedef struct AnimState {
    AnimHeader** unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    AnimFrame* unk_14;
} AnimState;

void AnimStart(AnimState* a, u16 animId, u16 flags);
u16 GetRandom(void);

extern vu16* const gBgControl[];
extern u8 gBgPaletteBank[];
extern u16 gUnk_03007500;

extern u8* gUnk_030074C8;
extern Dma3Request* gDma3Requests;
extern u16 gUnk_0300786C;
extern u32 gRandomState[4];
extern u8* gUnk_03007568;
extern u16 gUnk_03007544;
extern u16 gUnk_030074FC;
extern u16 gUnk_03007538;
extern u16 gUnk_03007558;
extern u16 gUnk_03007520;
extern u16 gUnk_03007534;
extern u16 gUnk_0300755C;
extern u16 gUnk_030074E4;

u8 func_08002060(s16 x, s16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h);
u8 func_0800216C(s16 x, s16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h);
u8 func_080022D4(s16 x, s16 y, void* obj, void* e, s32 f, u16 g, u16 h);
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
void SetBgScroll(s32 bg, s32 x, s32 y);
u8 func_08006314(void);

#endif /* GUARD_ENGINE_H */
