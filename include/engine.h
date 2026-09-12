#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "anim.h"
#include "obj.h"
typedef struct ObjTiles {
    void* unk_00;
    u16 refCount;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    ListNode unk_0C;
    u32 unk_20;
    u8 unk_24;
    u8 unk_25[0x03];
    u32 unk_28;
    struct ObjTiles* self;
} ObjTiles;

typedef struct ObjTileListEntry {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
} ObjTileListEntry;

typedef struct ObjPaletteNode {
    void* unk_00;
    u16 refCount;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    ListNode unk_0C;
    u32 unk_20;
    struct ObjPaletteNode* self;
} ObjPaletteNode;
typedef struct Dma3Request {
    void* src;
    void* dst;
    u16 size;
} Dma3Request;

#define BG_ENTRY_COUNT 4

typedef struct BgEntry {
    u8 unk_00;
    u8 unk_01[3];
    void* unk_04;
    u8 unk_08;
    u8 unk_09;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
#ifdef VERSION_EU
    void** unkEu_10;
#endif
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
#ifdef VERSION_EU
    Dma3Request unkEu_10A0[32];
#endif
    vu16 requestCount;
    vu16 unk_10A2;
    vu16 unk_10A4;
    vu16 unk_10A6;
    vu16 count;
    vu16 unk_10AA;
    u32 unk_10AC;
} Dma3Queue;

extern vu16* const gBgControl[];
extern u8 gBgPaletteBank[];
extern u16 gDispCnt;

typedef struct SpriteWork SpriteWork;
extern SpriteWork* gSpriteWork;
extern Dma3Queue* gDma3Requests;

typedef struct FadeWork {
    PaletteSlot slots[32];
    u32 unk_580;
    u32 unk_584;
    u32 unk_588;
    u16 unk_58C;
    u16 unk_58E;
    u32 unk_590;
    u16 unk_594;
    u16 unk_596;
} FadeWork;

typedef char FadeWork_size[(sizeof(FadeWork) == 0x598) ? 1 : -1];
typedef char PaletteSlot_size[(sizeof(PaletteSlot) == 0x2C) ? 1 : -1];

extern FadeWork* gFadeWork;

typedef struct UnkBgAnimFrame {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} UnkBgAnimFrame;

typedef struct UnkBgAnim {
    UnkBgAnimFrame* unk_00;
    void* unk_04;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
} UnkBgAnim;

typedef char UnkBgAnim_size[(sizeof(UnkBgAnim) == 0x18) ? 1 : -1];
typedef char UnkBgAnimFrame_size[(sizeof(UnkBgAnimFrame) == 0x08) ? 1 : -1];

typedef struct Spline2D {
    s16 pointCount;
    u16 unk_02;
    s32* intervals;
    s32* scratch;
    s32* knots;
    s32* xCoefficients;
    s32* yCoefficients;
    s32* xValues;
    s32* yValues;
} Spline2D;

typedef char Spline2D_size[(sizeof(Spline2D) == 0x20) ? 1 : -1];

void SplineBuildAxisCoefficients(Spline2D* spline, s32* knots, s32* values, s32* coefficients);
s32 SplineEvaluateAxis(s16* count, s32 t, s32* knots, s32* values, s32* coefficients);
void SplineInit2D(Spline2D* spline, s32* xValues, s32* yValues, s16 count);
void SplineEvaluate2D(Spline2D* spline, s32 t, s32* x, s32* y);
void SplineFreeBuffers(Spline2D* spline);

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
void func_0800284C(ObjTiles* p);
void func_08002880(ObjTiles* p);
void func_080028A0(ObjTiles* p);
void func_08002A10(void* a, void* b);
void func_08002BCC(ObjPaletteNode* p);
u8 func_08006314(void);
void func_080034D8(u8 a);
s32 func_08005920(u16 a);
void FadeReset(void);
void func_08005C60(u16 a);
u16 func_08006390(void);
void func_080063A8(void);
void MosaicReset(void);
void func_0800675C(u8 a, s32 b, s32 c);
void func_08006B34(u16 a);
void func_08006B40(u16 a);
void func_08006B4C(void);
void VTransFree(void);
void BgFree(void);
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
u8 MosaicIsActive(void);
void func_0800388C(ObjTiles* t, u16 slot, void* src, u16 size);
s32 Sqrt8(s32 a);
void SetObjMosaicSize(u8 a, u8 b);
void func_08003510(u8 a);
ObjTiles* func_080038C8(u16 a);
void func_08003A70(ObjTiles* t, void* src);
void SetBgMosaicSize(u8 a, u8 b);
s32 Lerp8(s32 a, s32 b, s32 t);

void VTransInit(void);
void BgInit(void);
void FadeInit(void);
void InitDisplayRegs(void);

#ifdef VERSION_EU
void eu_080059D4(s32 bg, void* tiles);
void eu_080059F4(s32 bg, void* map);
u8 eu_08005A1C(s32 bg, void* src, u8 w, u8 h);
void eu_08005ADC(s32 id);
#endif

#endif /* GUARD_ENGINE_H */
