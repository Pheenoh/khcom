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

typedef struct BgEntry {
    u8 unk_00;
    u8 unk_01[3];
    void* unk_04;
    u8 unk_08;
    u8 unk_09;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
} BgEntry;

typedef struct Dma3Pending {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} Dma3Pending;

typedef struct Dma3Queue {
    Dma3Request requests[352];
    Dma3Pending pending[4];
    vu16 unk_10A0;
    vu16 unk_10A2;
    vu16 unk_10A4;
    vu16 unk_10A6;
    vu16 count;
    u16 unk_10AA;
    u32 unk_10AC;
} Dma3Queue;

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
void SeedRand(u32 seed);
u32 Rand(void);
void SeedRandom(u32 seed);

extern vu16* const gBgControl[];
extern u8 gBgPaletteBank[];
extern u16 gUnk_03007500;

extern u8* gUnk_030074C8;
extern Dma3Request* gDma3Requests;
extern u16 gUnk_0300786C;
extern u32 gRandSeed;
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
extern u16 gUnk_030074CC;
extern u16 gUnk_030074D8;
extern vu16 gUnk_03007528;
extern BgEntry* gUnk_030074D4;
extern u16 gUnk_03007554;
extern u8 gUnk_08121680[];
extern u8 gUnk_08121688[];
extern u8 gUnk_0812168C[];
extern u16 gUnk_03007564;
extern u32 gUnk_0203401C;
extern u32 gUnk_02034020;
extern u16 gUnk_02034024;
extern u8 gUnk_02034026;
extern u8* gUnk_02034040;
extern s16 gUnk_02034050;
extern s16 gUnk_02034052;
extern u8 gUnk_02034058;
extern s32 gUnk_02034048;
extern u8 gUnk_02034054;
extern u32 gUnk_0203405C;
extern u32 gUnk_02034060;
extern u8 gUnk_02034064;
extern u16 gUnk_02034066;
extern u16 gUnk_02034068;

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
void LoadObjPaletteBank(u16 bank, void* src);
void func_080034D8(u8 a);
void func_08005810(u16 a, u16 b);
s32 func_08005920(u16 a);
u16 func_08005B30(AnimState* a);
u16 func_08005B38(AnimState* a);
void func_08005B64(AnimState* a);
void func_08005BC4(void);
void func_08005C60(u16 a);
u16 func_08006390(void);
void func_080063A8(void);
void func_08006404(void);
void func_0800675C(u8 a, s32 b, s32 c);
void func_08006B34(u16 a);
void func_08006B40(u16 a);
void func_08006B4C(void);
void func_08004350(void);
void func_08004BC4(void);
void func_08005490(s32 bg, u8 on);
void func_08005BB0(void);
void func_080063C4(u8 on);
u8 func_08005550(u32 a);
u8 func_0800558C(u32 a);
void func_08005654(s32 bg, u8 on);
void func_0800380C(ObjTiles* t, u16 slot, void* src, u16 size);
void func_08003858(ObjTiles* t, u16 slot, u16 size, void* src);
void* func_08004BD8(BgEntry* e, u16 x, u16 y);
u8 func_08005AC4(AnimState* a);
void func_08006494(u16 a, u16 b);
void func_080064E8(u16 a, u16 b);
u8 func_0800653C(void);
void func_0800388C(ObjTiles* t, u16 slot, void* src, u16 size);
s32 func_08003C9C(s32 a);
void func_080034EC(u8 a, u8 b);
void func_08003510(u8 a);
ObjTiles* func_080038C8(u16 a);
void func_08003A70(ObjTiles* t, void* src);
void func_080054C8(u8 a, u8 b);
void func_0800592C(s32* p, s32 target, u16 steps);
s32 func_08005954(s32 a, s32 b, s32 t);
void func_08005B44(AnimState* a, u16 frame);

#endif /* GUARD_ENGINE_H */
