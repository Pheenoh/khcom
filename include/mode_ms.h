#include "card_def_data.h"
#include "card_lookup_data.h"
#include "card_reload_sprite_data.h"
#include "registration_data.h"
#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "card_description_data.h"

#include "obj.h"

#include "card_types.h"

#include "ms_types.h"

#include "card_api.h"

#include "map_api.h"
#include "mode_ms_top_api.h"

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
    const MooglePackCardDef* cards;
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

typedef struct MooglePackTilemapDef {
#ifdef VERSION_EU
    u16** tilemap;
#else
    u16* tilemap;
#endif
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
void func_08102DC8(void);
void mode_ms_shop_1(void);
void func_08104404(void);
void mode_ms_shop_0(void);
void func_081041B4(void);
void mode_ms_shop_2(void);
void LoadMooglePackSelectionTilemap(s16 a);
void func_08103D7C(void);
void func_08103DE8(void);

void func_080A4234(void* pool, u32 a, u16 b);

void func_0810264C(u16 a, u16 b, u16 c);
u8 func_0810329C(u16 a);
void func_08102AB4(s16 x, s16 y);
void func_08103F94(s16 a, s16 b);
void MoogleShopCopyTilemapRect(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);

extern u8 gUnk_0203C590[];

extern u8 gUnk_08F683A4[];
extern u8 gUnk_088C56C6[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_092028EC[];
extern u32 gFrameCounter;
extern u8 gUnk_09611AB8[];
#endif /* GUARD_MODE_MS_H */
