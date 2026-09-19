#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include "graphics_state.h"

#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "bg_animation_types.h"
#include "engine_math.h"
#include "listpool.h"
#include "anim.h"
#include "obj.h"

typedef struct ObjTileListEntry {
    u16 attr0;
    u16 attr1;
    u16 tile;
} ObjTileListEntry;

typedef struct Dma3Request {
    void* src;
    void* dst;
    u16 size;
} Dma3Request;

#define BG_ENTRY_COUNT 4

typedef struct BgEntry {
    u8 dirty;
    u8 unk_01[3];
    void* map;
    u8 width;
    u8 height;
    u16 x;
    u16 y;
    u16 unk_0E;
#ifdef VERSION_EU
    void** unkEu_10;
#endif
} BgEntry;

typedef struct Dma3Pending {
    void* dst;
    u16 size;
    u16 unk_06;
} Dma3Pending;

typedef struct Dma3Blit {
    void* src;
    void* dst;
    u8 srcX;
    u8 srcY;
    u8 dstX;
    u8 dstY;
    u8 width;
    u8 height;
} Dma3Blit;

typedef struct Dma3Fill {
    void* src;
    void* dst;
    u8 x;
    u8 y;
    u8 vertical;
} Dma3Fill;

typedef struct Dma3Queue {
    Dma3Request requests[256];
    Dma3Blit blits[64];
    Dma3Fill fills[8];
    void* callbacks[8];
    Dma3Pending pending[4];
#ifdef VERSION_EU
    Dma3Request unkEu_10A0[32];
#endif
    vu16 requestCount;
    vu16 blitCount;
    vu16 fillCount;
    vu16 callbackCount;
    vu16 count;
    vu16 unk_10AA;
    u32 transferredBytes;
} Dma3Queue;

extern vu16* const gBgControl[];

typedef struct SpriteWork SpriteWork;
extern SpriteWork* gSpriteWork;
extern Dma3Queue* gDma3Requests;

typedef struct FadeWork {
    PaletteSlot slots[32];
    u32 amount;
    u32 target;
    u32 lastAmount;
    u16 timer;
    u16 unk_58E;
    u32 mode;
    u16 flags;
    u16 unk_596;
} FadeWork;

typedef char FadeWork_size[(sizeof(FadeWork) == 0x598) ? 1 : -1];
typedef char PaletteSlot_size[(sizeof(PaletteSlot) == 0x2C) ? 1 : -1];

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

u8 func_08002060(s16 x, s16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h);
u8 func_0800216C(s16 x, s16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h);
u8 func_080022D4(s16 x, s16 y, void* obj, void* e, s32 f, u16 g, u16 h);
void ReleaseSharedObjTiles(ObjTiles* p);
void ReleaseAllocatedObjTiles(ObjTiles* p);
void ReleaseSpriteFrameTiles(ObjTiles* p);
void ReleaseObjPaletteRef(ObjPalette* p);
void SetSpriteMosaicEnabled(u8 a);
void BgAnimSetStopFrame(u16 a);
void VTransFree(void);
void BgFree(void);
void SetBgMosaic(s32 bg, u8 on);
void FadeFree(void);
u8 GetBgScrollX(u32 a);
u8 GetBgScrollY(u32 a);
void InitDynamicObjTilesAtSlot(ObjTiles* t, u16 slot, u16 size, void* src);
void* GetBgMapBlock(BgEntry* e, u16 x, u16 y);
void SetSpriteOamUpdatesPaused(u8 a);
void SetBgMosaicSize(u8 a, u8 b);
s32 Lerp8(s32 a, s32 b, s32 t);

void VTransInit(void);
void BgInit(void);
void FadeInit(void);
void InitDisplayRegs(void);

#endif /* GUARD_ENGINE_H */
