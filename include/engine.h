#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include "types.h"
#include "anim.h"
#include "obj.h"
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

typedef struct Dma3Blit {
    void* unk_00;
    void* unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D;
} Dma3Blit;

typedef struct Dma3Fill {
    void* unk_00;
    void* unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
} Dma3Fill;

typedef struct Dma3Queue {
    Dma3Request requests[256];
    Dma3Blit unk_0C00[64];
    Dma3Fill unk_1000[8];
    void* unk_1060[8];
    Dma3Pending pending[4];
    vu16 unk_10A0;
    vu16 unk_10A2;
    vu16 unk_10A4;
    vu16 unk_10A6;
    vu16 count;
    u16 unk_10AA;
    u32 unk_10AC;
} Dma3Queue;
void AnimStart(AnimState* a, u16 animId, u16 flags);
u16 GetRandom(void);
void SeedRand(u32 seed);
u32 Rand(void);
void SeedRandom(u32 seed);

extern vu16* const gBgControl[];
extern u8 gBgPaletteBank[];
extern u16 gDispCnt;

extern u8* gSpriteWork;
extern Dma3Queue* gDma3Requests;
extern u8* gFadeWork;
extern u16 gBg0HOfs;
extern u16 gBg0VOfs;
extern u16 gBg1HOfs;
extern u16 gBg1VOfs;
extern u16 gBg2HOfs;
extern u16 gBg2VOfs;
extern u16 gBg3HOfs;
extern u16 gBg3VOfs;
extern u16 gUnk_030074CC;
extern u16 gBackdropColor;
extern vu16 gMosaic;
extern BgEntry* gBgEntries;
extern u16 gBldCnt;
extern u8 sVTransHeapName[];
extern u8 sBgHeapName[];
extern u8 sFadeHeapName[];
extern u16 gBldAlpha;
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
void EnableBg(s32 a);
void DisableBg(s32 bg);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgPriority(s32 bg, u16 priority);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void ApproachValue(s32* value, s32 target, u16 steps);
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
void SetBlendAlpha(u16 a, u16 b);
s32 func_08005920(u16 a);
u16 func_08005B30(AnimState* a);
u16 func_08005B38(AnimState* a);
void func_08005B64(AnimState* a);
void FadeReset(void);
void func_08005C60(u16 a);
u16 func_08006390(void);
void func_080063A8(void);
void func_08006404(void);
void func_0800675C(u8 a, s32 b, s32 c);
void func_08006B34(u16 a);
void func_08006B40(u16 a);
void func_08006B4C(void);
void VTransFree(void);
void func_08004BC4(void);
void SetBgMosaic(s32 bg, u8 on);
void FadeFree(void);
void func_080063C4(u8 on);
u8 GetBgScrollX(u32 a);
u8 GetBgScrollY(u32 a);
void SetBgOverflow(s32 bg, u8 on);
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
s32 Lerp8(s32 a, s32 b, s32 t);
void func_08005B44(AnimState* a, u16 frame);

void VTransInit(void);
void BgInit(void);
void FadeInit(void);
void InitDisplayRegs(void);

#endif /* GUARD_ENGINE_H */
