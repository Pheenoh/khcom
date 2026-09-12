#ifndef GUARD_OBJ_API_H
#define GUARD_OBJ_API_H

#include "types.h"

struct ObjTiles;
struct ObjPaletteNode;

struct ObjTiles* LoadObjTiles(void* src, u16 size);
struct ObjTiles* AllocObjTiles(u16 size, void* owner);
void ReleaseObjTiles(void* tiles);
struct ObjPaletteNode* LoadObjPalette(void* src, u16 size);
struct ObjPaletteNode* AllocObjPalette(u16 size);
void ReleaseObjPalette(struct ObjPaletteNode* palette);
u8 DrawSprite(s16 x, s16 y, void* sprite, void* tiles, void* palette, s32 affine, u16 flags, u16 priority);
u8* AllocObjAffine(u8 angle, s32 sx, s32 sy, u8 flags);
u8* AllocObjAffineAngle(u8 angle, u8 flags);
u8 CanAllocObjTiles(u16 size);
void SpriteReset(void);
void func_08002A10(void* tiles, void* src);
u16 GetMaxSpriteTileBytes(u16** sprites, u16 count);
u16 GetSpriteTileBytes(u16* sprite);
struct ObjTiles* func_080038C8(u16 size);
u8 func_080038E4(struct ObjTiles* tiles, u16* sprite, void* src);

void func_0800380C(struct ObjTiles* t, u16 slot, void* src, u16 size);
void func_0800388C(struct ObjTiles* t, u16 slot, void* src, u16 size);
void func_08003A70(struct ObjTiles* t, void* src);
u8 CanAllocObjPalette(u16 n);
void func_08002F50(void);
u8 IsRectOutsideScreen(s16 x, s16 y, s32 a, s32 b, s32 c, s32 d);
void SetObjPaletteRange(u16 a, u16 b);
u16 GetObjTileCount(u16 a, u16 b);

#endif
