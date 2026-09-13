#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include "graphics_state.h"

#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "anim.h"
#include "obj.h"

typedef struct ObjTileListEntry {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
} ObjTileListEntry;

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

typedef struct BgAnimationChunk {
    void* data;
    u16 size;
    u16 unk_06;
} BgAnimationChunk;

typedef struct BgAnimationDef {
    BgAnimationChunk* chunks;
    void* tilemap;
    void* palette;
    u16 paletteSize;
    u16 tilesPerFrame;
    u16 unk_10;
    u16 unk_12;
    u16 frameCount;
    u16 frameDuration;
} BgAnimationDef;

typedef char BgAnimationDef_size[(sizeof(BgAnimationDef) == 0x18) ? 1 : -1];
typedef char BgAnimationChunk_size[(sizeof(BgAnimationChunk) == 0x08) ? 1 : -1];

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

extern u8 sVTransHeapName[];
extern u8 sBgHeapName[];
extern u8 sFadeHeapName[];

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
