#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "types.h"
#include "key.h"
#include "taskpool.h"
#include "fld_types.h"
#include "anim.h"
#include "mode.h"

typedef struct CardBack {
    void* unk_00;
    u8 unk_04[0x8];
    void* unk_0C;
    u8 unk_10[0x8];
} CardBack;

typedef struct MsShopHosiArg {
    s16 x;
    s16 y;
    void* unk_04;
    u8 unk_08;
    u8 unk_09[0x3];
    s32 unk_0C;
} MsShopHosiArg;

typedef struct MsCardDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x2];
    u8 unk_20;
    u8 unk_21[0x7];
    u16 unk_28;
    u8 unk_2A;
    u8 unk_2B[0x9];
} MsCardDef;

typedef struct UnkStruct_099935A8_00 {
    u16 unk_00;
    u8 unk_02[0x2];
    void* unk_04;
    u16 unk_08[4];
} UnkStruct_099935A8_00;

typedef struct UnkStruct_099935A8 {
    UnkStruct_099935A8_00* unk_00;
    s16 unk_04;
    u8 unk_06[0x2];
} UnkStruct_099935A8;

typedef struct UnkStruct_099932D4 {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    void* unk_10;
    u16 unk_14;
    u16 unk_16;
} UnkStruct_099932D4;

typedef struct GameState {
    u8 unk_000[0x0E];
    s8 floor;
    u8 unk_00F[0x16B];
    u16 unk_17A;
    u8 unk_17C[0x2];
} GameState;

typedef struct UnkStruct_020358C8 {
    FldRes* unk_00;
    void* unk_04;
    void* unk_08;
    FldRes* unk_0C;
    void* unk_10;
    s32 unk_14;
    AnimState unk_18;
    u16 unk_30;
    u16 unk_32;
    s32 unk_34;
    u16 unk_38;
    u16 unk_3A;
    s32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u8 unk_46;
    u8 unk_47;
} UnkStruct_020358C8;

typedef struct UnkStruct_099931E4_1C {
    u16* unk_00;
    s16 unk_04;
    s16 unk_06;
} UnkStruct_099931E4_1C;

typedef struct UnkStruct_099931E4 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    void* unk_0C;
    u16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    UnkStruct_099931E4_1C unk_1C[4];
} UnkStruct_099931E4;

void func_081025AC(void);
void func_081025D4(void* a);
void func_08102610(void* a);
void func_08102688(u16 a, u16 b, u16 c);
u8 func_081026C4(u16 a, u16 b, u16 c);
void func_08102704(u16 a);
void func_08102728(u16 a);
u8 func_0810274C(u16 a);
void func_08102774(void);
u8 func_081027B4(s16 a);
s32 func_08102A94(void);
u16 func_08103F3C(void);
void func_08102984(s16 a);
void func_08103CD8(s16 a);
void mode_ms_top_2(void);
void func_08102DC8(void);
void mode_ms_shop_1(void);
void func_08104404(void);
void mode_ms_top_0(u32 a);
void mode_ms_shop_0(void);
void func_081041B4(void);
void mode_ms_shop_2(void);
void func_08103D54(s16 a);
void func_08103D7C(void);
void func_08103DE8(void);

u16 GetKeysRepeat(void);
u16 GetRandom(void);
void* GetBgScreenBase(s32 bg);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void TaskPoolDestroy(TaskPool* pool);
void m4aSongNumStart(u16 n);
u16 AnimGetFrame(AnimState* a);
void SetBgScroll(s32 bg, s32 x, s32 y);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void LoadPalette(void* src, void* dst, s32 size);
s32 func_08065B6C(void* a, void* b);
void TaskCreate(TaskPool* pool, void* desc, void* arg);
void LoadObjPaletteBank(u16 bank, void* src);
void ApproachValue(s32* value, s32 target, u16 steps);
void TaskPoolUpdate(TaskPool* pool);
void func_0800FDD0(s32 a);
u8 func_080A42C8(void);
void func_080A4234(void* pool, u32 a, u16 b);
u8 func_080A411C(TaskPool* a, s32 b, u16 c);
void func_08101768(void);
void func_081017A0(void);
void func_08101970(void);
void func_080063A8(void);
void mode_ms_top_1(void);
s16 func_08084458(u16 a);
u16 func_08060A2C(u16 a);
u8 func_0800FC5C(void* a);
u8 func_0810155C(u32 a);
void EwramFree(void* p);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void TaskPoolDraw(TaskPool* a);
void func_08065ACC(void* a, s32 b);
void UpdatePlayTime(void);
u8 func_08006314(void);
void func_080061E8(s32 a, u16 b);
void ModeRequest(Mode* mode, s32 arg);
void func_080E04EC(void);
void func_0810264C(u16 a, u16 b, u16 c);
u8 func_0810329C(u16 a);
void func_0805F1C0(s32* p, s32 v);
void* AnimUpdate(AnimState* a);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void func_08102F30(void);
void DisableBg(s32 bg);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgTiles(s32 bg, void* src, u16 size);
void* LoadObjPalette(void* a, s32 b);
void* LoadObjTiles(void* a, s32 b);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* EwramAlloc(u32 size);
void SpriteReset(void);
void TaskPoolInit(TaskPool* pool, s32 a);
void func_081015E8(void);
void func_08101654(void);
void func_08101740(s16 a);
void SetBgMode0(void);
void func_08006120(s32 a, s32 b);
u32 GetMooglePoints(void);
void func_08006238(s32 a, s32 b, s32 c);
u8 func_08101538(u32 a);
void func_08102AB4(s16 x, s16 y);
void func_08103F94(s16 a, s16 b);
void func_080062F4(u16 a, s32 b);
void func_08065AE0(void* a, s32 b);
void* GetBgCharBase(s32 bg);
void func_08101588(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);
void func_08006184(s32 a, u16 b);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_0800448C(void* src, void* dst, u8 x, u8 y, u8 w, u8 h, u8 sw, u8 sh);

extern u8 gUnk_0203C590[];
extern u16 gUnk_09993334[];
extern u8 gUnk_09A3ABDC[];
extern void* gUnk_020357C8;
extern void* gUnk_020357CC;
extern void* gUnk_020357D0;
extern void* gUnk_020357D4;
extern void* gUnk_020357F0;
extern void* gUnk_020357F4;
extern void* gUnk_02035810;
extern void* gUnk_02035814;
extern void* gUnk_02035818[];
extern void* gUnk_02035820[];
extern void* gUnk_02035858;
extern void* gUnk_0203585C;
extern u16 gBldCnt;
extern u16 gBldAlpha;
extern s16 gUnk_020357C0;
extern AnimState gUnk_020357D8;
extern AnimState gUnk_020357F8;
extern AnimState gUnk_02035860;
extern s16 gUnk_02035878;
extern s16 gUnk_0203587A;
extern s16 gUnk_0203587C;
extern s32 gUnk_02035880;
extern s32 gUnk_02035884;
extern s32 gUnk_02035888;
extern s32 gUnk_0203588C;
extern s16 gUnk_02035890;
extern s16 gUnk_02035892;
extern s32 gUnk_02035898[];
extern s32 gUnk_020358A0;
extern u8 gUnk_020358A4;
extern TaskPool gUnk_020358A8;
extern void* gUnk_020357C4;
extern s16 gUnk_020358BC;extern s16 gUnk_020358BE;
extern u8 gUnk_020358C0;
extern s16 gUnk_020358C2;
extern u8 gUnk_09A3D79C[];
extern u8 gUnk_09A10A3C[];
extern u8 gUnk_09A123DC[];
extern u8 gUnk_09A36EDC[];
extern u8 gUnk_09A373DC[];
extern u8 gUnk_09A378DC[];
extern u8 gUnk_09A37DDC[];
extern u8 gUnk_09A3D7FC[];
extern u8 gUnk_099A2B62[];
extern u8 gUnk_09A3D85C[];
extern u8 gUnk_099A36F8[];
extern u8 gUnk_09EF99D0[];
extern u8 gUnk_09EF99A8[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_088C56C6[];
extern u8 gUnk_09EDEA6C[];
extern u8 gUnk_09EDEA68[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_092028EC[];
extern u8 gUnk_09EEEAC8[];
extern u8 gUnk_09EEEA98[];
extern UnkStruct_099935A8 gUnk_099935A8[];
extern CardBack gUnk_08F709B0[];
extern u32 gFrameCounter;
extern u8 gUnk_09A17D1C[];
extern u8 gUnk_09A3DA1C[];
extern void* gUnk_09EE8F48[];
extern u8 gTaskDescMsShopHosi[];
extern void* gUnk_09EE981C[];
extern void* gUnk_09EE9894[];
extern s16 gSineTable[];
extern MsCardDef gCardDefs[];
extern u8 gUnk_09A3DB1C[];
extern u8 gUnk_099A4B9A[];
extern u8 gUnk_09EF9A48[];
extern u8 gUnk_09EF9A20[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_09A3DB7C[];
extern u8 gUnk_0908B1B4[];
extern u8 gUnk_09EEA164[];
extern u8 gUnk_09EEA148[];
extern Mode gModeMsTop;
extern GameState gGameState;
extern UnkStruct_099932D4 gUnk_099932D4[];
extern u8 gUnk_09A3D87C[];
extern u8 gUnk_09A1251C[];
extern u8 gUnk_09A18D7C[];
extern u8 gUnk_09A382DC[];
extern u8 gUnk_09A3AD5C[];
extern u8 gUnk_09A3DA7C[];
extern u8 gUnk_099A3CE4[];
extern u8 gUnk_09EF99F8[];
extern u8 gUnk_09EF99D8[];
extern UnkStruct_099931E4 gUnk_099931E4[];
extern s16 gUnk_099935C0[][4][4];
extern s16 gUnk_09993760[][4];
extern u8 gUnk_09A18EBC[];
#endif /* GUARD_MODE_MS_H */
