#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "obj.h"

#include "card_types.h"

#include "ms_types.h"

#include "card_api.h"

#include "map_api.h"
#include "mode_worldwarp_api.h"

#include "mode_ms_api.h"

#include "mode_test_api.h"

#include "player_progression.h"

#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "text_types.h"
#include "key.h"
#include "taskpool.h"
#include "fld_types.h"
#include "anim.h"
#include "mode.h"
#include "malloc.h"
#include "m4a.h"




typedef struct MooglePackCardDef {
    u16 cardId;
    u8 unk_02[0x2];
    void* unk_04;
    u16 weights[4];
} MooglePackCardDef;

typedef struct MooglePackCardTable {
    MooglePackCardDef* cards;
    s16 count;
    u8 unk_06[0x2];
} MooglePackCardTable;

typedef struct MooglePackSpriteDef {
    void* palette;
    u16 paletteSize;
    u8 unk_06[0x2];
    void* tiles;
    u16 tilesSize;
    u8 unk_0E[0x2];
    void* sprite;
    u16 xOffset;
    u16 yOffset;
} MooglePackSpriteDef;

typedef struct MooglePackCardWork {
    FldRes* palette;
    void* tiles;
    void* gfx;
    FldRes* palette2;
    void* tiles2;
    s32 backSprite;
    AnimState anim;
    u16 flipAngle;
    u16 unk_32;
    s32 scale;
    u16 state;
    u16 unk_3A;
    s32 x;
    s32 y;
    u16 timer;
    u8 premium;
    u8 revealed;
} MooglePackCardWork;

typedef struct MooglePackTilemapDef {
    u16* tilemap;
    s16 srcX;
    s16 srcY;
} MooglePackTilemapDef;

typedef struct MooglePackMenuEntry {
    s16 upEntry;
    s16 downEntry;
    s16 leftEntry;
    s16 rightEntry;
    s16 cursorX;
    s16 cursorY;
    void* selectionTilemap;
    u16 selectionTilemapSize;
    s16 tilemapX;
    s16 tilemapY;
    u16 spriteX;
    u16 spriteY;
    u16 unk_1A;
    MooglePackTilemapDef packTilemaps[4];
} MooglePackMenuEntry;

void func_08102688(u16 a, u16 b, u16 c);
u8 func_081026C4(u16 a, u16 b, u16 c);
void func_08102704(u16 a);
void func_08102728(u16 a);
u8 func_0810274C(u16 a);
void func_08102774(void);
u8 func_081027B4(s16 a);
s32 MoogleShopReadMenuKeys(void);
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

void func_080A4234(void* pool, u32 a, u16 b);
void mode_ms_top_1(void);

void func_0810264C(u16 a, u16 b, u16 c);
u8 func_0810329C(u16 a);
void func_08102AB4(s16 x, s16 y);
void func_08103F94(s16 a, s16 b);
void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);

extern u8 gUnk_0203C590[];
extern u16 gUnk_09993334[];
extern u8 gUnk_09A3ABDC[];
extern struct ObjTiles* gUnk_020357C8;
extern struct ObjPalette* gUnk_020357CC;
extern struct ObjTiles* gUnk_020357D0;
extern struct ObjPalette* gUnk_020357D4;
extern struct ObjTiles* gUnk_020357F0;
extern struct ObjPalette* gUnk_020357F4;
extern struct ObjTiles* gUnk_02035810;
extern struct ObjPalette* gUnk_02035814;
extern void* gUnk_02035818[];
extern void* gUnk_02035820[];
extern struct ObjTiles* gUnk_02035858;
extern struct ObjPalette* gUnk_0203585C;
extern u16 gBldCnt;
extern u16 gBldAlpha;
extern s16 gUnk_020357C0;
extern AnimState gWorldwarpAnim;
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
extern MooglePackCardTable gUnk_099935A8[];
extern CardBack gUnk_08F709B0[];
extern u32 gFrameCounter;
extern u8 gUnk_09A17D1C[];
extern u8 gUnk_09A3DA1C[];
extern void* gUnk_09EE8F48[];
extern u8 gTaskDescMsShopHosi[];
extern void* gUnk_09EE981C[];
extern void* gUnk_09EE9894[];
extern s16 gSineTable[];
extern CardDef gCardDefs[];
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
extern MooglePackSpriteDef gUnk_099932D4[];
extern u8 gUnk_09A3D87C[];
extern u8 gUnk_09A1251C[];
extern u8 gUnk_09A18D7C[];
extern u8 gUnk_09A382DC[];
extern u8 gUnk_09A3AD5C[];
extern u8 gUnk_09A3DA7C[];
extern u8 gUnk_099A3CE4[];
extern u8 gUnk_09EF99F8[];
extern u8 gUnk_09EF99D8[];
extern MooglePackMenuEntry gUnk_099931E4[];
extern s16 gUnk_099935C0[][4][4];
extern s16 gUnk_09993760[][4];
extern u8 gUnk_09A18EBC[];
#endif /* GUARD_MODE_MS_H */
