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

#endif
