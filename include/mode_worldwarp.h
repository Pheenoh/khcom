#ifndef GUARD_MODE_WORLDWARP_H
#define GUARD_MODE_WORLDWARP_H

#include "types.h"
#include "main.h"

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

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C[0x168];
    u32 unk_174;
} UnkStruct_02039BB0;

typedef struct WarpGfx {
    u16 unk_00;
    s16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x02];
    void* unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    s32 unk_14;
    s32 unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
} WarpGfx;

typedef struct WarpDef {
    void* unk_00;
    u8 unk_04[0x06];
    u16 unk_0A;
    s16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    s16 unk_12;
    u16 unk_14;
    u16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x02];
    WarpGfx unk_1C[2];
} WarpDef;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern const WarpDef gUnk_09993118[];
extern u16 gUnk_099931D0[];
extern s32 gUnk_02035880;
extern s32 gUnk_02035884;
extern s32 gUnk_0203588C;
extern void* gUnk_0203585C;
extern void* gUnk_02035818[];
extern void* gUnk_02035820[];
extern AnimState gUnk_02035828[];
extern AnimState gUnk_020357D8;
extern s16 gUnk_020358BC;
extern s16 gUnk_020358C2;
extern u8 gUnk_09A3D77C[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_09A35F1C[];
extern s16 gUnk_020357A2;
extern s16 gUnk_020357A4;
extern s32 gUnk_020357A8[];
extern s32 gUnk_020357B0;
extern s16 gUnk_0203550A;
extern void* gUnk_0203550C;
extern void* gUnk_02035510;
extern void* gUnk_02035514;
extern void* gUnk_02035518;
extern void* gUnk_0203551C;
extern void* gUnk_02035550;
extern void* gUnk_02035554;
extern void* gUnk_02035570[];
extern void* gUnk_020355A8[];
extern s16 gUnk_020357C0;
extern void* gUnk_020357C4;
extern AnimState gUnk_02035860;
extern s16 gUnk_02035878;
extern s16 gUnk_0203587A;
extern s16 gUnk_0203587C;
extern s16 gUnk_02035890;
extern s16 gUnk_02035892;
extern u8 gUnk_020358A4;
extern s16 gUnk_020358BE;
extern u8 gUnk_09A378DC[];
extern void* gUnk_02035858;
extern s32 gUnk_02035888;
extern s32 gUnk_02035898[];
extern s32 gUnk_020358A0;
extern void* gUnk_020357C8;
extern void* gUnk_020357CC;
extern void* gUnk_020357D0;
extern void* gUnk_020357D4;
extern AnimState gUnk_020357F8;
extern void* gUnk_020357F0;
extern void* gUnk_020357F4;
extern void* gUnk_02035810;
extern void* gUnk_02035814;
extern TaskPool gUnk_020358A8;
extern u8 gUnk_099A2AD4[];
extern u8 gUnk_099A2AF0[];
extern u8 gUnk_099A2B24[];
extern u8 gUnk_08B22BA8[];
extern u8 gUnk_02035618[];
extern u8 gUnk_020356E0[];

u8 RequestDma3Copy(void* src, void* dst, u16 size);
void AnimInit(AnimState* a, s32 b, s32 c);
void AnimStart(AnimState* a, u16 b, s32 c);
void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_080058FC(s32* value, s32 target, u16 steps);
void func_0801CC80(void);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_080DF9E0(u8 a);
void func_080E04EC(void);
void func_08100980(void);
void func_081006AC(void);
void func_08065AE0(void* a, s32 b);
void func_080063A8(void);
u8 func_080A42C8(void);
void func_080A42E0(void);
void m4aSongNumStart(u16 id);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void* AnimUpdate(AnimState* a);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_08102F30(void);
u16 GetKeysPressed(void);

void mode_worldwarp_0(void);
void mode_worldwarp_1(void);
void mode_worldwarp_2(void);
u32 func_08101518(void);
void func_08101528(u32 a);
u8 func_08101538(u32 a);
u8 func_0810155C(u32 a);
void func_08101588(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void func_081015E8(void);
void func_08101654(void);
void func_08101740(s16 a);
void func_08101768(void);

#endif /* GUARD_MODE_WORLDWARP_H */
