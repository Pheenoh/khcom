#ifndef GUARD_MODE_WORLDWARP_H
#define GUARD_MODE_WORLDWARP_H

#include "types.h"
#include "text_types.h"
#include "taskpool.h"
#include "main.h"
#include "anim.h"
typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
    u8 unk_00C[0x02];
    s8 floor;
    u8 unk_00F[0x165];
    u32 mooglePoints;
    u8 unk_178[0x0E];
    u8 unk_186[13][4];
} GameState;

typedef struct WarpIcon {
    u8 unk_00[0x08];
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12[0x02];
} WarpIcon;

typedef struct UnkStruct_09EF9488 {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x02];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
    void* unk_10;
    u8 unk_14[0x04];
} UnkStruct_09EF9488;

typedef struct WarpRect {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} WarpRect;

typedef struct WarpGfx {
    u16 unk_00;
    s16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x02];
    void* unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    void* unk_14;
    void* unk_18;
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

extern GameState gGameState;
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
extern WarpIcon gUnk_09EF9384[];
extern UnkStruct_09EF9488 gUnk_09EF9488[];
extern WarpRect gUnk_099930E8[];
extern u8 gUnk_09A3D37C[];
extern u8 gUnk_09A06A7C[];
extern u8 gUnk_09A35A1C[];
extern u8 gUnk_09A3641C[];
extern u8 gUnk_09A3691C[];
extern u8 gUnk_09A0E33C[];
extern u8 gUnk_09A0D63C[];
extern u8 gUnk_09A0FD3C[];
extern u8 gUnk_09A0F03C[];
extern u8 gUnk_09A3D57C[];
extern u8 gUnk_0999F488[];
extern u8 gUnk_09A3D59C[];
extern u8 gUnk_0999FA20[];
extern u8 gUnk_09A3D5BC[];
extern u8 gUnk_099A012C[];
extern u8 gUnk_09EF9898[];
extern u8 gUnk_09EF9870[];
extern u8 gUnk_09EF98B0[];
extern u8 gUnk_09EF98A0[];

u8 RequestDma3Copy(void* src, void* dst, u16 size);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(u8* p);
void LoadBgMap(s32 bg, void* src, u16 size);
void ApproachValue(s32* value, s32 target, u16 steps);
void UpdatePlayTime(void);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_080DF9E0(u8 a);
void func_080E04EC(void);
void func_08100980(void);
void func_081006AC(void);
void func_08065AE0(TextSlot* p, s32 n);
void func_080063A8(void);
u8 func_080A42C8(void);
void func_080A42E0(void);
void m4aSongNumStart(u16 id);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void* AnimUpdate(AnimState* a);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_08102F30(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgTiles(s32 bg, void* src, u16 size);
void* GetBgCharBase(s32 bg);
void SpriteReset(void);
void SetBgMode0(void);
void EnableBg(s32 a);
void DisableBg(s32 bg);
void func_08006120(s32 a, s32 b);
void func_08065ACC(void* a, s32 b);
u8 func_080DF750(void);
void func_0810057C(s32 a, s32 b, void* c, s32 d, s32 e, void* f, s32 g, s32 h);
void func_081004EC(s32 a, s32 b, s32 c, void* d, s32 e, s32 f);
u8 func_08100608(s16 a);
u8 func_0810063C(s16 a);
void func_08100670(s32 a, void* b, void* c);

void mode_worldwarp_0(void);
void mode_worldwarp_1(void);
void mode_worldwarp_2(void);
u32 GetMooglePoints(void);
void SetMooglePoints(u32 a);
u8 func_08101538(u32 a);
u8 func_0810155C(u32 a);
void func_08101588(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void func_081015E8(void);
void func_08101654(void);
void func_08101740(s16 a);
void func_08101768(void);
void func_081017A0(void);
void func_08101970(void);

#endif /* GUARD_MODE_WORLDWARP_H */
