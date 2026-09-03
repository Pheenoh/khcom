#ifndef GUARD_MODE_JIMINY_H
#define GUARD_MODE_JIMINY_H

#include "types.h"
#include "jiminy_types.h"
#include "main.h"
#include "anim.h"
#include "obj.h"
typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
} GameState;

typedef struct JiminyLine {
    s32 unk_000;
    u8 unk_004[0x17C];
} JiminyLine;


typedef struct JiminyEntry {
    void* unk_00;
    void* unk_04;
    s16 unk_08;
    s16 unk_0A;
    u16* unk_0C;
    u16* unk_10;
    void* unk_14;
} JiminyEntry;

typedef struct JiminyWork {
    s32 unk_000;
    void* unk_004;
    ObjPalette* unk_008;
    void* unk_00C;
    ObjPalette* unk_010;
    ObjPalette* unk_014;
    void* unk_018;
    ObjPalette* unk_01C;
    void* unk_020;
    ObjPalette* unk_024;
    void* unk_028;
    ObjPalette* unk_02C;
    void* unk_030;
    ObjPalette* unk_034;
    void* unk_038;
    ObjPalette* unk_03C;
    void* unk_040;
    ObjPalette* unk_044;
    s16 unk_048;
    s16 unk_04A;
    s32 unk_04C;
    s32 unk_050;
    s32 unk_054;
    s32 unk_058;
    s32 unk_05C;
    JiminyLine unk_060[8];
    u8 unk_C60[8];
    u8 unk_C68[8];
    u8 unk_C70;
    u8 unk_C71;
    s16 unk_C72;
    s16 unk_C74;
    s16 unk_C76;
    s16 unk_C78;
    u8 unk_C7A[0x02];
    AnimState unk_C7C;
    AnimState unk_C94;
    u16 unk_CAC;
    s16 unk_CAE;
    s16 unk_CB0;
    s16 unk_CB2;
    s32 unk_CB4;
    u16* unk_CB8;
    u8 unk_CBC[0x04];
    s16 unk_CC0;
    s16 unk_CC2;
    s16 unk_CC4;
    s16 unk_CC6;
    s16 unk_CC8;
    u8 unk_CCA[0x02];
    void* unk_CCC;
    u16 unk_CD0;
    s16 unk_CD2;
    s16 unk_CD4;
    u16 unk_CD6;
    JiminyPair unk_CD8[21];
    s32 unk_D2C;
    u8 unk_D30[0x04];
    void* unk_D34;
    s32 unk_D38;
    u16 unk_D3C;
    u16 unk_D3E;
} JiminyWork;

extern JiminyEntry gUnk_08155554[];
extern s16 gSineTable[];
extern u16 gBldCnt;
extern u8 gUnk_08C69C04[];
extern u8 gUnk_08C69C20[];
extern u8 gUnk_08C69C54[];
extern u8 gUnk_08C69C76[];
extern u8 gUnk_08C6A51C[];
extern u8 gUnk_08C6A526[];
extern u8 gUnk_08C6A69A[];
extern u8 gUnk_08C6A6A4[];
extern u8 gUnk_08C6A878[];
extern u8 gUnk_08C6A8F8[];
extern u8 gUnk_08F62B84[];
extern u8 gUnk_08159FE0[];
extern u8 gUnk_08C69C9C[];
extern u8 gUnk_08C6A54E[];
extern u8 gUnk_08C6A6B8[];
extern u8 gUnk_08C6A88C[];
extern u8 gUnk_08C6A958[];
extern u8 gUnk_08EE4A64[];
extern u8 gUnk_08F60B84[];
extern u8 gUnk_08F61B84[];
extern u8 gUnk_08F6DD64[];
extern u8 gUnk_08F6DD84[];
extern u8 gUnk_08F6DDA4[];
extern u8 gUnk_08F6DDC4[];
extern u8 gUnk_08F6DDE4[];
extern u8 gUnk_08F6DE04[];
extern u8 gUnk_08F6DE24[];
extern u8 gUnk_090FDBF4[];
extern u8 gUnk_0913F0C2[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_09614AB8[];
extern u8 gUnk_09614D58[];
extern u8 gUnk_09A3CC9C[];
extern u8 gUnk_09EE2668[];
extern u8 gUnk_09EE2678[];
extern u8 gUnk_09EECA44[];
extern u8 gUnk_09EECAA0[];
extern u8 gUnk_09EED2BC[];
extern u8 gUnk_09EED320[];
extern GameState gGameState;

void SetBgMode0(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void* AllocObjTiles(s32 size, void* src);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* AnimUpdate(AnimState* a);
void func_080062F4(u16 slot, u8 value);
u8 func_08006314(void);
void func_08006120(s32 a, u16 b);
void EnableBg(s32 bg);
void DisableBg(s32 bg);
void DrawSprite(s16 x, s16 y, void* sprite, void* tiles, void* pal, s32 f, s32 g, s32 h);
void LoadObjPaletteBank(u16 bank, void* src);
void SetBlendAlpha(u16 a, u16 b);
void UpdatePlayTime(void);
void m4aSongNumStart(u16 id);
s32 abs(s32 x);
void SetModeUpdate(void (*fn)(void));
void ApproachValue(s32* value, s32 target, u16 steps);
void AnimReset(AnimState* a);
void func_08006184(s32 a, u16 b);
u16 func_08006390(void);
void func_080063A8(void);
u8 func_0800FF00(u16 a);
void func_080658B8(u8 a);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void func_080E052C(u8 a);
void func_0805A484(void);
u8 func_0805AA9C(void);
void func_0805A8D0(void);
void func_08064B80(s32 a);
s32 func_08065170(s32 a, s32 b, void* c);
void func_08065940(void);
void func_08065ACC(void* a, s32 b);
void func_0805A95C(s32 a, s16 b, void* c, void* d, void* e, s32 f, s32 g, s32 h);

void func_0805BAE4(void);
void func_0805B9D0(s16 a, s16 b, s32 c, s16 d, s16 e, s16 f);
void func_0805BAAC(s16 a, u8* out);

#endif /* GUARD_MODE_JIMINY_H */
