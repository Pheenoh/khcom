#include "mode_deck.h"
#include "task_descriptors.h"
#include "card_def_data.h"
#include "map_text_data.h"
#include "map_ui_data.h"
#include "card_lookup_data.h"
#include "registration_data.h"
#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "map_room_data.h"
#include "map_fixed_data.h"
#include "map_enemy_data.h"

#include "field_state.h"

#include "map_types.h"
#include "map_room_types.h"

#include "card_api.h"

#include "map_api.h"
#include "msg_api.h"
#include "status_api.h"
#include "task.h"
#include "mode_pooh_api.h"

#include "mode_test_api.h"

#include "save_api.h"

#include "player_progression.h"

#include "card_deck.h"

#include "m4a_song.h"
#include <string.h>
#include <stdlib.h>
#include "text.h"
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "malloc.h"
#include "engine_math.h"
#include "listpool.h"
#include "game_state.h"
#include "anim.h"
#include "m4a.h"
#include "m4a_catalog_data.h"
#include "mode.h"
#include "mode_battle_data.h"
#include "key.h"
#include "taskpool.h"
#include "fld_types.h"
#include "card_types.h"
#include "text_types.h"
#include "battle_actor.h"
#include "bos4_api.h"

typedef struct UnkStruct_02034F20 {
    u16 unk_00;
    u16 unk_02;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u16 x;
    u16 y;
    u8 unk_0E;
    u8 unk_0F;
    s32 unk_10;
    s32 unk_14;
} UnkStruct_02034F20;

typedef struct UnkStruct_02034F24 {
    u8 unk_00[0x08];
} UnkStruct_02034F24;

typedef struct UnkStruct_02034F84 {
    u8 unk_00;
    u8 unk_01;
} UnkStruct_02034F84;

typedef struct UnkStruct_080E92B8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x02];
    u8 unk_04[0x21C];
    GameFloor floors[13];
} UnkStruct_080E92B8;

typedef struct UnkStruct_0984BC9C {
    const AnimDef* animDef;
    void* palette;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    TaskDesc* desc;
    u16 flags;
    u16 unk_16;
} UnkStruct_0984BC9C;

typedef struct UnkStruct_080E6034 {
    UnkStruct_080DFF1C unk_00;
    u8 unk_10;
    u8 unk_11[0x03];
    s32 unk_14;
    u8 unk_18[0x04];
    u8 unk_1C[0x14];
    const UnkStruct_0984BC9C* unk_30;
    void* unk_34;
} UnkStruct_080E6034;

typedef struct UnkStruct_080E7D80 {
    void* palette;
    void* tiles;
    u16 tilesSize;
    u8 unk_0A;
    u8 unk_0B;
    void* gfxTable;
    void* anims;
    u8 unk_14;
    u8 unk_15;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    u16 unk_22;
    void* unk_24;
} UnkStruct_080E7D80;

typedef struct UnkStruct_080E8B1C {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x02];
    u8* unk_08;
    u8* unk_0C;
    s16 unk_10;
    u8 unk_12[0x02];
    void* unk_14;
    s16* unk_18;
} UnkStruct_080E8B1C;

typedef struct UnkStruct_0203C7B8 {
    u16 unk_00;
    u8 unk_02[0x02];
    UnkStruct_080DFF1C unk_04;
    const UnkStruct_080E7D80* unk_14;
} UnkStruct_0203C7B8;

typedef struct UnkStruct_080E8374 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x0E];
    s16 unk_1A;
} UnkStruct_080E8374;

typedef struct UnkStruct_080E87EC {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A[0x02];
} UnkStruct_080E87EC;

typedef struct UnkStruct_080E64D4 {
    UnkStruct_080DFF1C unk_00;
    u8 unk_10[0x2A];
    u16 unk_3A;
    s32 unk_3C;
} UnkStruct_080E64D4;

typedef struct UnkStruct_080E8D64 {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
} UnkStruct_080E8D64;

typedef struct UnkStruct_080E8E24 {
    u8 unk_00[0x02];
    u16 unk_02;
} UnkStruct_080E8E24;

typedef struct UnkStruct_080E8E74 {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[0x02];
} UnkStruct_080E8E74;

typedef struct UnkStruct_080E8F50 {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x04];
    u16 unk_14;
    u8 unk_16[0x02];
} UnkStruct_080E8F50;

typedef struct UnkStruct_080EF4BC {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 angle;
    u8 unk_15[0x03];
    u8 unk_18[0x28];
} UnkStruct_080EF4BC;

typedef struct UnkStruct_080E5B90 {
    const UnkStruct_0984BC9C* unk_00;
    void* unk_04;
    UnkStruct_080DFF1C unk_08;
    u8 unk_18;
    u8 unk_19[0x03];
    s32 unk_1C;
} UnkStruct_080E5B90;

typedef struct UnkStruct_080E6394 {
    UnkStruct_080DFF1C unk_00;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x05];
    u16 unk_1A;
    u8 unk_1C[0x14];
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
} UnkStruct_080E6394;

typedef struct MapEnmWork {
    const UnkStruct_0984BC9C* unk_00;
    u16 flags;
    u16 unk_06;
    UnkStruct_080DFF1C unk_08;
    s32 unk_18;
    u8 unk_1C;
    u8 unk_1D[0x03];
    u8 unk_20[0x22];
    u16 unk_42;
    s32 unk_44;
    u8 collider[0x2C];
    u8 unk_74;
    u8 unk_75[0x0B];
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x1C];
    u8 anim[0x18];
    void* tiles;
    void* palette;
    void* gfx;
    s16 unk_C8;
    s16 unk_CA;
    void (*update)(struct MapEnmWork*);
    u16 unk_D0;
    u16 unk_D2;
    s32 unk_D4;
    s32 unk_D8;
    s32 unk_DC;
    s16 unk_E0;
    u8 unk_E2[0x02];
    u8 tasks[0x14];
} MapEnmWork;

typedef struct LoadGameMenuWork {
    u8* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    s32 x;
    AnimState anim;
    u8* palette;
    void* tiles;
    s32 y3;
    MapEnmWork* palette7;
    u8 unk_03C[0x120];
    u8 unk_15C;
    u8 unk_15D;
    u16 unk_15E;
    u8* palette3;
    void* tiles3;
    u8* palette4;
    void* tiles4;
    u8* palette5;
    void* tiles5;
    u8* palette6;
    void* tiles6;
    u8 unk_180;
    u8 unk_181;
    u8 unk_182;
    u8 selectedSlot;
    u8 unk_184;
    u8 unk_185;
    u16 timer;
    void (*update)(struct LoadGameMenuWork*);
} LoadGameMenuWork;

typedef struct UnkStruct_02034FE4 {
    u8 unk_00;
    u8 unk_01[0x03];
    void (*update)(struct UnkStruct_02034FE4*);
    TaskPool tasks;
} UnkStruct_02034FE4;

typedef struct NewGameSlotMenuWork {
    u8* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    u8* palette3;
    void* tiles3;
    AnimState anim;
    u8* palette;
    void* tiles;
    s32 y3;
    MapEnmWork* palette8;
    u8 unk_040[0x120];
    u8 unk_160;
    u8 unk_161;
    u16 unk_162;
    u8* palette9;
    u8 unk_168[0x1B0];
    u8 unk_318;
    u8 unk_319[0x03];
    u8* palette4;
    void* tiles4;
    u8* palette5;
    void* tiles5;
    u8* palette6;
    void* tiles6;
    u8* palette7;
    void* tiles7;
    u8 unk_33C;
    u8 unk_33D;
    u8 selectedSlot;
    u8 unk_33F;
    u16 timer;
    u8 unk_342[0x02];
    void (*update)(struct NewGameSlotMenuWork*);
} NewGameSlotMenuWork;

typedef struct MapRndWork {
    TaskPool tasks;
    u8 unk_10[0x04];
} MapRndWork;

typedef struct MapMenuWork {
    u8* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    void* tiles3;
    s32 x;
    void* tiles4;
    s32 x2;
    u8* palette3;
    void* tiles5;
    s32 x3;
    s32 x4;
    s32 x5;
    u8 unk_034;
    u8 unk_035[0x03];
    u8* palette4;
    u8* palette5;
    void* tiles6;
    s32 x6;
    AnimState anim;
    u8* palette;
    void* tiles;
    s32 x7;
    s32 y3;
    u8* palette8;
    u8 unk_074[0xC4];
    FldRes* palette6;
    void* tiles8;
    u8* palette7;
    void* tiles7;
    s32 x8;
    s32 y4;
    s32 unk_150;
    s32 unk_154;
    u8* palette9[0x03];
    void* tiles9[0x03];
    s32 gfx[0x03];
    u8* unk_17C;
    TextSlot unk_180[0x21];
#ifdef VERSION_EU
    u8 unkEu_288[0x108];
#endif
    u8 unk_288;
    u8 unk_289[0x03];
    TextSlot unk_28C[0x06];
    u8 unk_2BC;
    u8 unk_2BD[0x03];
    TextSlot unk_2C0[0x09];
    u8 unk_308;
    u8 unk_309;
    u8 unk_30A;
    u8 unk_30B;
    u16 unk_30C;
    u8 unk_30E;
    u8 unk_30F;
    s32 (*update)(struct MapMenuWork*);
} MapMenuWork;

typedef struct MapSaveWork {
    FldRes* palette2;
    void* tiles2;
    s32 y;
    s32 y2;
    s32 x;
    FldRes* palette3;
    void* tiles3;
    AnimState anim;
    FldRes* palette;
    void* tiles;
    s32 x2;
    FldRes* palette4;
    u8 unk_044[0x124];
    FldRes* palette5;
    void* tiles4;
    s32 x3;
    s32 y3;
    s32 unk_178;
    s32 unk_17C;
    FldRes* palette6;
    void* tiles5;
    FldRes* palette7;
    void* tiles6;
    FldRes* palette8;
    u8 unk_194[0xD8];
#ifdef VERSION_EU
    u8 unkEu_26C[0xD8];
#endif
    u8 unk_26C;
    u8 unk_26D[0x03];
    u8 unk_270[0x30];
    u8 unk_2A0;
    u8 unk_2A1[0x03];
    u8 unk_2A4[0x48];
    u8 unk_2EC;
    u8 unk_2ED[0x03];
    s32 (*update)(struct MapSaveWork*);
    u8 unk_2F4;
    u8 unk_2F5;
    u16 unk_2F6;
    u8 unk_2F8;
    u8 unk_2F9[0x03];
    TaskPool tasks;
    u8 unk_30C[0x04];
} MapSaveWork;

typedef struct MapAnmEntry {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
} MapAnmEntry;

typedef struct MapAnmWork {
    UnkStruct_080E8B1C unk_00[8];
} MapAnmWork;

typedef struct MapDbgWork {
    u8 unk_00;
    u8 unk_01[0x03];
    u8* unk_04;
    void (*update)(struct MapDbgWork*);
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E[0x02];
    void* tiles;
    void* palette;
    u16 unk_18[0x0A];
    u8 unk_2C;
    u8 unk_2D;
    u16 unk_2E[0x0A];
    u8 unk_42;
    u8 unk_43;
    u16 unk_44;
    u8 unk_46;
    u8 unk_47;
} MapDbgWork;

typedef struct MapGmkEnmWork {
    UnkStruct_080DFF1C unk_000;
    u8 unk_010[0x0A];
    u16 unk_01A;
    u8 unk_01C[0x24];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    s32 (*unk_064)(struct MapGmkEnmWork*);
    u8 unk_068;
    u8 unk_069[0x03];
    s32 unk_06C;
    u16 unk_070;
    u8 unk_072[0x02];
} MapGmkEnmWork;

typedef struct MapGmkJumpWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x04];
    u8 unk_014;
    u8 unk_015[0x2B];
    AnimState collider;
    u8 unk_058[0x08];
    void* unk_060;
    s32 unk_064;
    u8 unk_068[0x04];
    u16 unk_06C;
    u16 unk_06E;
    u16 unk_070;
    u8 unk_072[0x2A];
    AnimState anim;
    void* tiles;
    u8* palette;
    u8 unk_0BC[0x04];
    u8 unk_0C0;
    u8 unk_0C1[0x03];
    s32 unk_0C4;
    void (*update)(struct MapGmkJumpWork*);
} MapGmkJumpWork;

typedef struct MapGmkTutorialWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_00C;
    u8 unk_010[0x04];
    u8 unk_014;
    u8 unk_015[0x05];
    u16 unk_01A;
    u8 unk_01C[0x24];
    u8 collider[0x2E];
    u16 unk_06E;
    u8 unk_070[0x04];
    s32 unk_074;
    u8 unk_078[0x24];
    void* tiles;
    u8* palette;
    u8 unk_0A4[0x04];
    u8 unk_0A8;
    u8 unk_0A9[0x03];
    u8 (*update)(struct MapGmkTutorialWork*);
    TaskPool tasks;
    u8 unk_0C0[0x04];
} MapGmkTutorialWork;

typedef struct MapGmk01Work {
    UnkStruct_0203C7B8* unk_000;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u16 timer;
    u16 unk_0C6;
    u8 (*update)(struct MapGmk01Work*);
} MapGmk01Work;

typedef struct MapGmkSpiderWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    u8 unk_00C[0x0E];
    u16 unk_01A;
    u8 unk_01C[0x80];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u8 (*update)(struct MapGmkSpiderWork*);
    u8 unk_0C4;
    u8 unk_0C5[0x03];
} MapGmkSpiderWork;

typedef struct MapGmkGpWork {
    MapCell* cell;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u16 unk_0C4;
    u16 timer;
    u8 (*update)(struct MapGmkGpWork*);
} MapGmkGpWork;

typedef struct MapGmkGp1Work {
    MapCell* cell;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u16 unk_0C4;
    u8 unk_0C6;
    u8 unk_0C7;
    u8 (*update)(struct MapGmkGp1Work*);
} MapGmkGp1Work;

typedef struct MapGmk00Work {
    UnkStruct_0203C7B8* unk_000;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x2E];
    u16 unk_072;
    u8 unk_074[0x2C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u16 unk_0C4;
    u16 unk_0C6;
    u8 unk_0C8;
    u8 unk_0C9;
    u8 unk_0CA[0x02];
} MapGmk00Work;

typedef struct MapGmkBarrelWork {
    UnkStruct_0203C7B8* unk_000;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u8 unk_0C4;
    u8 unk_0C5[0x03];
    u8 (*update)(struct MapGmkBarrelWork*);
} MapGmkBarrelWork;

typedef struct MapPrizeWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
    u8 collider[0x5C];
    void* tiles;
    u8* palette;
    u8* gfx;
    u8* gfx2;
    void (*update)(struct MapPrizeWork*);
    u16 unk_80;
    u16 unk_82;
    s32 vz;
    s32 unk_88;
    u8 angle;
    u8 unk_8D;
    u8 unk_8E[0x02];
    s32 unk_90;
    u16 unk_94;
    u8 unk_96;
    u8 unk_97;
} MapPrizeWork;

typedef struct MapGmkGp8Work {
    MapCell* cell;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x2E];
    u16 flags;
    u8 unk_074[0x2C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    s32 (*unk_0C4)(struct MapGmkGp8Work*);
    u8 unk_0C8;
    u8 unk_0C9;
    u8 unk_0CA;
    u8 unk_0CB;
    s32 (*unk_0CC)(struct MapGmkGp8Work*);
} MapGmkGp8Work;

typedef struct MapGmkGp08Work {
    MapCell* cell;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x2E];
    u16 unk_072;
    u8 unk_074[0x2C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    void* unk_0C4;
    u16 unk_0C8;
    u8 unk_0CA;
    u8 unk_0CB;
    s32 (*unk_0CC)(struct MapGmkGp8Work*);
} MapGmkGp08Work;

typedef struct MapGmk04Work {
    UnkStruct_0203C7B8* unk_000;
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x5C];
    u8* palette;
    void* tiles;
    AnimState anim;
    void* gfx;
    void (*update)(struct MapGmk04Work*);
    TaskPool tasks;
} MapGmk04Work;

typedef struct MapGmk05Work {
    u8 unk_000[0x04];
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x2A];
    u16 unk_03E;
    s32 unk_040;
    u8 collider[0x5C];
    u8* palette;
    void* tiles;
    AnimState anim;
    void* gfx;
    void (*update)(struct MapGmk05Work*);
    u8 unk_0C8;
    u8 unk_0C9[0x03];
    TaskPool tasks;
    TaskPool tasks2;
} MapGmk05Work;

typedef struct MapFrdWork {
    u8 unk_000[0x40];
    u8 unk_040[0x74];
    void* tiles;
    u8* palette;
    u8 unk_0BC[0x08];
    TaskPool tasks;
    TaskPool tasks2;
} MapFrdWork;

typedef struct MapGmk06Work {
    u8 unk_000[0x04];
    UnkStruct_080DFF1C unk_004;
    u8 unk_014[0x30];
    u8 collider[0x5C];
    AnimState anim;
    u8* palette;
    void* tiles;
    void* gfx;
    void (*update)(struct MapGmk06Work*);
    TaskPool tasks;
} MapGmk06Work;

typedef struct UnkStruct_08F70ACC {
    u8 unk_00[0x04];
    u8 unk_04;
    u8 unk_05[0x09];
    u8 unk_0E;
    u8 unk_0F[0x09];
} UnkStruct_08F70ACC;

typedef struct MapPrzCardWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 collider[0x5C];
    FldRes* palette;
    void* tiles;
    FldRes* palette2;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    u8* palette3;
    u16 unk_088;
    u16 timer;
    void (*update)(struct MapPrzCardWork*);
    UnkStruct_08F70ACC unk_090;
    u16 cardId;
    u8 unk_0AA[0x02];
    s32 unk_0AC;
    s32 unk_0B0;
    s16 unk_0B4;
    s16 unk_0B6;
    u8 unk_0B8;
    u8 unk_0B9;
    s16 x;
    s16 y;
    u16 unk_0BE;
    s32 unk_0C0;
    s32 unk_0C4;
    s32 unk_0C8;
    s16 unk_0CC;
    u8 unk_0CE;
    u8 unk_0CF;
    u8 unk_0D0;
    u8 unk_0D1;
    u8 unk_0D2;
    u8 unk_0D3;
    TaskPool tasks;
} MapPrzCardWork;

typedef struct MapPrzStockWork {
    u16* unk_00;
    void (*update)(struct MapPrzStockWork*);
    TaskPool tasks;
    u8 unk_18[0x04];
} MapPrzStockWork;

typedef struct MapSparkWork {
    void* unk_00;
    AnimState anim;
    void* tiles;
    u8* palette;
    u8 unk_24[0x04];
} MapSparkWork;

typedef struct MapFaintWork {
    void* unk_00;
    AnimState anim;
    void* tiles;
    u8* palette;
    u8 unk_24[0x04];
} MapFaintWork;

typedef struct MapTalkWork {
    s32* unk_00;
    AnimState anim;
    void* tiles;
    u8* palette;
    u8 unk_24[0x04];
    u8 unk_28;
    u8 unk_29[0x03];
} MapTalkWork;

typedef struct MapDonaldWork {
    s32 unk_000;
    s32 unk_004;
    u8 unk_008[0x38];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void (*update)(struct MapDonaldWork*);
    u8 unk_0C0;
    u8 unk_0C1;
    u8 unk_0C2[0x02];
    TaskPool tasks;
    TaskPool tasks2;
} MapDonaldWork;

typedef struct MapGoofyWork {
    s32 unk_000;
    s32 unk_004;
    u8 unk_008[0x38];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void (*update)(struct MapGoofyWork*);
    u8 unk_0C0;
    u8 unk_0C1;
    u8 unk_0C2[0x02];
    TaskPool tasks;
    TaskPool tasks2;
} MapGoofyWork;

typedef struct MapNamineWork {
    s32 unk_000;
    s32 unk_004;
    u8 unk_008[0x38];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void (*update)(struct MapNamineWork*);
    u8 unk_0C0;
    u8 unk_0C1;
    u8 unk_0C2;
    u8 unk_0C3;
    u16 unk_0C4;
    u8 unk_0C6[0x02];
    TaskPool tasks;
    TaskPool tasks2;
} MapNamineWork;

typedef struct MapMickeyWork {
    u8 unk_000[0x40];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void (*update)(struct MapMickeyWork*);
    u8 unk_0C0;
    u8 unk_0C1;
    u16 unk_0C2;
    TaskPool tasks;
    TaskPool tasks2;
} MapMickeyWork;

typedef struct MapTutorialWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_00C;
    s32 vz;
    u8 unk_014[0x2C];
    u8 unk_040[0x2C];
    u8 unk_06C;
    u8 unk_06D[0x07];
    s32 unk_074;
    s32 unk_078;
    s32 unk_07C;
    u8 unk_080[0x1C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void* gfx;
    u8 unk_0C0;
    u8 unk_0C1;
    u8 unk_0C2;
    u8 unk_0C3;
    void (*update)(struct MapTutorialWork*);
    TaskPool tasks;
    TaskPool tasks2;
} MapTutorialWork;

typedef struct MapNiserikuWork {
    u8 unk_000[0x40];
    u8 collider[0x5C];
    AnimState anim;
    void* tiles;
    u8* palette;
    void (*update)(struct MapNiserikuWork*);
    u8 unk_0C0;
    u8 unk_0C1;
    u8 unk_0C2;
    u8 unk_0C3;
    TaskPool tasks;
    TaskPool tasks2;
} MapNiserikuWork;

typedef struct MapFloorWork {
    void* tiles;
    void* palette;
    void* gfx;
    s16 unk_0C;
    u16 unk_0E;
    u8 unk_10;
    u8 unk_11[0x03];
    void* palette2;
    u8 unk_18[0x140];
} MapFloorWork;

typedef struct MapMsgWork {
    FldRes* palette;
    u8 unk_004[0x180];
    u8 unk_184;
    u8 unk_185;
    s16 unk_186;
    u16 timer;
    u8 unk_18A[0x02];
} MapMsgWork;

typedef struct MapStairWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x04];
    u8 unk_14;
    u8 unk_15[0x2B];
    u8* palette;
    void* tiles;
    u8 unk_48;
    u8 unk_49[0x03];
    void (*update)(struct MapStairWork*);
    TaskPool tasks;
    u8 unk_60[0x04];
} MapStairWork;

typedef struct UnkStruct_080F023C {
    u8 unk_00[0x04];
    u16 flags;
    u16 unk_06;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1C[0x2C];
    u8 collider[0x5C];
    AnimState anim;
    u8 unk_BC[0x08];
    void* gfx;
    u8 unk_C8[0x04];
    void (*update)(struct UnkStruct_080F023C*);
    u16 timer;
    u8 unk_D2[0x02];
    s32 unk_D4;
    s32 unk_D8;
    s32 unk_DC;
    u8 unk_E0[0x04];
    TaskPool tasks;
    s32 unk_F8;
    s32 unk_FC;
    s32 unk_100;
    s32 unk_104;
} UnkStruct_080F023C;

typedef struct UnkStruct_080EFA30 {
    u8 unk_00[0x08];
    s32 unk_08;
    u8 unk_0C[0xC0];
    void* unk_CC;
    u16 unk_D0;
    u8 unk_D2[0x26];
    u8 unk_F8;
    u8 unk_F9[0x03];
} UnkStruct_080EFA30;

typedef struct MapFixWork {
    u8 unk_00;
    u8 unk_01[0x03];
    u8 unk_04[5][0x5C];
    TaskPool tasks;
#ifdef VERSION_EU
    u8 unk_1E4;
    u8 unk_1E5;
    u8 unk_1E6;
#endif
} MapFixWork;

typedef struct UnkStruct_080ECFE8 {
    u8 unk_000[0x20];
    FldRes* palette;
    u8 unk_024[0x14];
    FldRes* palette2;
    FldRes* palette3;
    u8 unk_040[0x20];
    FldRes* palette4;
    u8 unk_064[0x0C];
    FldRes* palette5;
    u8 unk_074[0xE4];
    FldRes* palettes[3];
} UnkStruct_080ECFE8;

typedef struct UnkStruct_0984B968 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    void* unk_20;
} UnkStruct_0984B968;

typedef struct MapDoorWork {
    UnkStruct_080DFB7C* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x34];
    void* tiles;
    u8* palette;
    void* unk_4C;
    void* unk_50;
    void* unk_54;
    void* tiles2;
    u8* palette2;
    void* unk_60;
    void* unk_64;
    void* unk_68;
    u8 (*update)(struct MapDoorWork*);
    u8 unk_70;
    u8 unk_71;
    u8 unk_72[0x02];
    TaskPool tasks;
} MapDoorWork;

typedef struct UnkStruct_080ED06C {
    FldRes* palette;
    u8 unk_004[0x134];
    FldRes* palette2;
    u8 unk_13C[0x04];
    FldRes* palette3;
} UnkStruct_080ED06C;

typedef struct UnkStruct_080EE50C {
    u8 unk_000[0x14];
    FldRes* palette;
    u8 unk_018[0x1C];
    FldRes* palette2;
    u8 unk_038[0x08];
    FldRes* palette3;
    u8 unk_044[0x14C];
    FldRes* palette4;
} UnkStruct_080EE50C;

typedef struct UnkStruct_080EE580 {
    FldRes* palette;
    u8 unk_004[0x164];
    FldRes* palette2;
    u8 unk_16C[0x14];
    FldRes* palette3;
    u8 unk_184[0x04];
    FldRes* palette4;
} UnkStruct_080EE580;

extern u8 gUnk_093A5E10[];
extern u8 gUnk_096183F8[];
extern u8 gUnk_08988980[];
extern u8 gUnk_08F69804[];
extern u8 gUnk_089D8148[];
extern u8 gUnk_08F69924[];
extern u8 gUnk_0899A8BE[];
extern u8 gUnk_08963BAC[];
extern u8 gUnk_08B1E974[];
extern u8 gUnk_08B1E97E[];
extern u8 gUnk_08B1E988[];
extern u8 gUnk_08B1E992[];
extern u8 gUnk_08B1E9A6[];
extern u8 gUnk_0984C868[];
extern UnkStruct_0203C7AC* gUnk_0203C7AC;
extern vu32 gFrameCounter;

extern UnkStruct_0203C590 gUnk_0203C590;
extern u8 gUnk_09618118[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_088B6560[];
extern u8 gUnk_09617C58[];
extern u8 gUnk_08F68384[];
extern const UnkStruct_0203C7B0 gUnk_0984D1F4[];
extern UnkStruct_080E7D80 gUnk_09857A2C[];
extern const UnkStruct_080E7D80 gUnk_0984C190;
extern const UnkStruct_080E7D80 gUnk_0984C158;
extern const UnkStruct_080E7D80 gUnk_0984C1CC;
extern UnkStruct_080E7D80 gUnk_09856FB4[];
extern const UnkStruct_080E7D80 gUnk_0984C204;
extern const UnkStruct_080E7D80 gUnk_0984C23C;
extern const u8 gUnk_0984C2E4[28];
extern const u8 gUnk_0984C310[28];
extern u8 gUnk_0985ADAA[];
extern u8 gUnk_0985BDEA[];
extern u8 gUnk_099912C4[];
extern u8 gUnk_099912E4[];
extern u8 gUnk_09991324[];
extern u8 gUnk_09991344[];
extern UnkStruct_02034F7C gUnk_0984CECC[];
extern const u8 gUnk_0984B8F8[13];
extern const u8 gUnk_0984B905[13];
extern u8 gUnk_0984B860[][8];
extern const u8 gUnk_0984D134[][8];
extern const u8 gUnk_0984D314[][4];
extern const u8 gUnk_0984D32C[][4];
extern const u8 gUnk_0984D3F8[][4];
extern const u8 gUnk_09961A64[][320];
extern const u8 gUnk_09962BE4[][320];
extern const u8 gUnk_09963D64[][320];
extern const u8 gUnk_09964EE4[][320];
extern const u8 gUnk_099581A4[];
extern const u8 gUnk_09966064[];
extern u8 gUnk_050001C0[];
extern u8 gUnk_08159E10[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_0815A03A[];
extern u8 gUnk_0815B5A6[];
extern u8 gUnk_093E1EE0[];
extern u8 gUnk_096184D8[];
extern u8 gUnk_08159E1E[];
extern u8 gUnk_09991D24[];
extern u8 gUnk_096181B8[];
extern u8 gUnk_096181D8[];
extern u8 gUnk_09991BE4[];
extern u8 gUnk_09991C04[];
extern u8 gUnk_09991D04[];
extern u8 gUnk_098A8C66[];
extern u8 gUnk_092EB78A[];
extern u8 gUnk_08B1EA00[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_098A4B68[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_0993AF64[];
extern u8 gUnk_099910C4[];
extern u8 gUnk_09991984[];
extern u8 gUnk_091ABDB8[];
extern u8 gUnk_09991924[];
extern u8 gUnk_09991944[];
extern u8 gUnk_09991964[];
extern u8 gUnk_099919A4[];
extern u8 gUnk_098A8628[];
extern u8 gUnk_09991C44[];
extern u8 gUnk_09991C84[];
extern u8 gUnk_098A8F8A[];
extern u8 gUnk_08159DF0[];
extern u8 gUnk_099919C4[];
extern u8 gUnk_09991BC4[];
extern u8 gUnk_098A87AA[];
extern u8 gUnk_098A8AE2[];
extern u8 gUnk_098A8F28[];
extern u8 gUnk_098A5C90[];
extern u8 gUnk_098A5C9A[];
extern u8 gUnk_098A5CA4[];
extern u8 gUnk_098A5CAE[];
extern u8 gUnk_098A5CB8[];
extern u8 gUnk_098A5CF4[];
extern u8 gUnk_0919FDF8[];
extern const UnkStruct_0984B968 gUnk_0984B968[14];
extern u8 gUnk_098A948C[];
extern u8 gUnk_098A94A0[];
extern u8 gUnk_098A94B4[];
extern u8 gUnk_098A94C8[];
extern u8 gUnk_098A94DC[];
extern u8 gUnk_098A94FC[];
extern u8 gUnk_09991284[];
extern u8 gUnk_09991104[];
extern u8 gUnk_09991124[];
extern u8 gUnk_09991144[];
extern u8 gUnk_09991164[];
extern u8 gUnk_09991184[];
extern u8 gUnk_099911A4[];
extern u8 gUnk_099911C4[];
extern u8 gUnk_099911E4[];
extern u8 gUnk_09991204[];
extern u8 gUnk_09991224[];
extern u8 gUnk_09991244[];
extern u8 gUnk_09991264[];

void func_080ED250(u8* work);
void func_080EBE90(LoadGameMenuWork* work);
void func_080EBD00(LoadGameMenuWork* work);
void func_080EBEC8(LoadGameMenuWork* work);
void func_080EBFB8(LoadGameMenuWork* work);
void func_080EC04C(LoadGameMenuWork* work);
void func_080EBFF8(LoadGameMenuWork* work);
void func_080E4D68(s32 a, s32 b);
void func_080E3C1C(s32 a, s16* px, s16* py, s16* pz, s16 lo, s16 hi);
extern u8 gUnk_0937E90A[];
extern u8 gUnk_0938044A[];
extern u8 gUnk_0938D282[];
extern u8 gUnk_09618338[];
void func_080E6394(MapEnmWork* p, UnkStruct_080E5B90* q);

s32 func_080EB7A0(u8 a);
s32 func_080EE824(MapSaveWork* w);
s32 func_080ED6CC(MapMenuWork* w);
s32 func_080ED7CC(MapMenuWork* w);
s32 func_080ED498(MapMenuWork* w);
s32 func_080ED91C(MapMenuWork* w);
s32 func_080EDA90(MapMenuWork* w);
s32 func_080EDB4C(MapMenuWork* w);
s32 func_080EDC94(MapMenuWork* w);
s32 func_080EDC38(MapMenuWork* w);
s32 func_080EDD7C(MapMenuWork* w);
s32 Task_MapMenu_1(MapMenuWork* w);
s32 func_080ED35C(MapMenuWork* w);
s32 func_080EE7B0(MapSaveWork* w);
s32 func_080EEB00(MapSaveWork* w);
s32 func_080EEC5C(MapSaveWork* w);
s32 func_080EEC9C(MapSaveWork* w);
s32 func_080EED44(MapSaveWork* w);
void func_080E2C50(void);
void func_080EB1AC(NewGameSlotMenuWork* w);
void func_080EB1F4(NewGameSlotMenuWork* w);
void func_080EB27C(NewGameSlotMenuWork* w);
void func_080EB2D0(NewGameSlotMenuWork* w);
void func_080ED314(u8* work);
s32 Task_MapSave_1(MapSaveWork* w);
void func_080E4B34(void);
void RequestTilemapStripCopy(void* a, void* b, u8 c, u8 d, s32 e);
void* func_08093BF8(void);
s32 func_080ECAC8(MapDoorWork* p);
s32 func_080ECBC8(MapDoorWork* p);
s32 func_080ECC54(MapDoorWork* p);
void func_080E9078(s32 x, s32 y, s32 z);
u8 func_080840E4(void);
MapCell* func_080E08BC(s16 x, s16 y);
void func_080E2D80(void);
void func_080E0960(MapCell* p, s32 n);
void sub_080E0B00(MapCell* p, s32 n);
void func_080E2668(UnkStruct_02034F20* p, s32 a);
void func_080E4EB0(u16* a, u16* b, u16* c, s16 d, s16 e);
void func_080E507C(u16* a, u16* b, u16* c, s16 d, s16 e);
u8 func_080E524C(UnkStruct_080DFF1C* a, s32* b);
u8 func_080E5354(UnkStruct_080DFF1C* a, s32* b);
void func_080E56B4(void* a);
s32 func_080E55A4(s16 x, s16 y);
void func_080E5B90(UnkStruct_080E5B90* p, const UnkStruct_0984BC9C* q);
u8 func_080E59D8(UnkStruct_080E5B90* w);
u8 func_080E5AC8(UnkStruct_080E5B90* w);
void func_080E5C00(UnkStruct_080E5B90* w, u8 a, u8 b);
void func_080E5EAC(MapEnmWork* p);
u8* func_080E8644(void* a, u16 b, u16 c);
void* func_080E8668(u8 a);
u8 func_080E8374(UnkStruct_080E8374* p);
u16 func_080E83C4(void);
void func_080E83DC(s32 a, s32 b, s32 c);
void func_080E55E4(const u8* src);
void func_080E5800(void);
void func_080E8864(UnkStruct_080E8864* p);
u8 func_080E87EC(s16 x, s16 y, const UnkStruct_080E87EC* p);
void func_080E8724(s16 x, s16 y, const u8* p, u16* base);
void func_080E893C(s16 x, s16 y, const u8* p, u16* base);
void func_080E8A24(UnkStruct_080E8864* p);
UnkStruct_080E8E24* func_080E8E74(u8 a);
void func_080EAB20(u8 a, u8 b, u8 c);
void func_080EABB8(u8 a, u16 v);
void func_080EAC60(u8 a, u32 b);

s32 func_080DFEBC(s32 x, s32 y, s32 z);
s32 func_080DFF30(UnkStruct_080DFF1C* p);
void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b);
void func_080DFFEC(UnkStruct_080DFF1C* p);
s32 func_080E0010(s32 x);
s32 func_080E0044(s32 y);
void func_080E0078(void);
void func_080E0558(void);
void func_080E062C(void);
u8 func_080E02E0(UnkStruct_080DFF1C* p, s16 a, s16 b);
u8 func_080E0378(void);
s32 func_080E0390(void);
s32 func_080E03C0(s32 a);
void func_080E05E4(void);
void func_080E0780(void);
void func_080E0820(void);
void* func_080D3A20(void* pool);
void func_080EC500(UnkStruct_02034FE4* w);
void func_080EC544(UnkStruct_02034FE4* w);
void func_080EC57C(s32 arg);
void func_080104F4(void);
void func_080E0878(void);
void func_080E0900(MapCell* p, s32 a, s32 b);
u8 func_080E0920(UnkStruct_080DFF1C* p, u16 a);
u8 func_080E0938(u8 a);
void func_080E09B4(MapCell* p, u8 n, u8 v);
void func_080E0A38(MapCell* p);
void func_080E0A70(MapCell* p, s32 n);
void func_080E0B98(MapCell* p, s32 n, u8 v);
void func_080E0BF4(s16 x, s16 y, s32 a, s32 b);
s16 func_080E1204(u8 a, u8 b, s16 c);
u8 func_080E1CE0(s16 x, s16 y, u8 n);
s16 func_080E1194(u8 a, u8 b, s16 c);
void func_080E1C64(s16 x, s16 y, u8 n);
u8 func_080E1CA8(s16 x, s16 y);
void func_080E1D08(s16 x, s16 y);
void func_080E1FA8(s16 x, s16 y);
void func_080E2318(s16 y);
void func_080E23CC(s16 y);
void func_080E249C(void);
u8 func_080E2BA0(u8 a);
s32 func_080E2B08(void);
void func_080E2BF8(u8 a);
void func_080E2C2C(u8 a);
s32 func_080E2E24(s16 a, s16 b, s16 c);
s32 func_080E2E9C(s16 a, s16 b, s16 c);
s32 func_080E2F14(s16 x, s16 y);
s32 func_080E2F48(s16 a, s16 b, s16 c, u8 d);
s32 func_080E2F98(s16 a, s16 b, s16 c, u8 d);
s32 func_080E300C(u8 d, s16 x, s16 y);
u8 func_080E3D80(s16* a, s16* b, s16* c, s16* d);
void func_080E3060(u8 i, u16 a, u16 b, s16 c);
void func_080E309C(u8 i, s16 a, s16 b, s16 c, u8 e);
void func_080E3768(u8 i, s16 a, s16 b, s16 c, s16 d, u8 e);
void func_080E3400(u8 i, s16 a, s16 b, s16 c, u8 e);
void func_080E3EFC(void);
void func_080E4FF0(void* p, s16 a, s16 b);
void func_080E51C0(void* p, s16 a, s16 b);
UnkStruct_02034F20* func_080E54A0(u8 a);
void* func_080E5504(void);
u16 func_080E5564(void);
void func_080E49DC(u16 a, u16 b);
void func_080E590C(UnkStruct_080E5B90* p);
void func_080E5938(UnkStruct_080E5B90* p);
s32 func_080E5968(UnkStruct_080E5B90* p);
void func_080E5CD4(MapEnmWork* p);
void func_080E5D6C(MapEnmWork* p, u8 n, u16 a);
void func_080E5DEC(MapEnmWork* p);
u8 func_080E5E44(void);
void func_080E5F50(MapEnmWork* p);
s32 func_080E5FB4(MapEnmWork* p);
void func_080E6034(MapEnmWork* p);
void func_080E607C(void);
void func_080E6100(void);
void func_080E6178(void);
void func_080E6264(void);
MapCell* func_080E67D4(s32 x, s32 y);
u8 func_080E68A4(s16 x, s16 y, u8 n);
s32 func_080E68E4(s16 x, s16 y, u8 w, u8 h, u8 n);
s32 func_080E6968(s16 a, s16 b, u8 c);
s32 func_080E6A80(s16 x, s16 y, u16 n);
void func_080E657C(MapEnmWork* p);
s32 func_080E6804(s16 x, s16 y);
void func_080E6998(s16 x, s16 y, u8 w, u8 h);
s16 func_080E6A14(s16 x, s16 y);
void func_080E8B1C(UnkStruct_080E8B1C* p, const UnkStruct_080E7D80* q);
void func_080E8B40(UnkStruct_080E8B1C* p);
void func_080E8B84(UnkStruct_080E8B1C* p);
void func_080E8BA0(UnkStruct_080E8B1C* p);
s32 Task_MapAnm_1(MapAnmWork* w);
void func_080E8BB4(UnkStruct_080E8B1C* p);
u8 func_080E8BE4(UnkStruct_080E8B1C* p);
void func_080E58E4(void);
void func_080EAD84(u8 a);
u8 func_080E6634(u8 a);
u8 func_080E7D64(UnkStruct_080DFF1C* a, u8 b);
s32 func_080E7D80(void* a);
s32 func_080E7DB8(u8 flag, void* a);
void func_080E7DF8(void);
void func_080E7E3C(void);
void func_080E7FCC(void);
void func_080E8058(void);
void func_080E80E0(void);
void func_080E826C(void);
void func_080E853C(void);
void func_080E8594(void);
void func_080E84DC(UnkStruct_080DFF1C* p);
void func_080E8624(void);
void func_080E891C(UnkStruct_080E8864* p);
u8 func_080E89E4(s16 x, s16 y, const u8* p);
void func_080E8AC8(UnkStruct_080E8864* p);
void func_080E8AE8(void);
u8 func_080E8C38(u8 a, u8 b);
u8 func_080E8D64(UnkStruct_080E8D64* p);
s32 func_080E8E24(UnkStruct_080E8E24* p);
u8 func_080E8F0C(void);
s32 func_080E8F50(UnkStruct_080E8E24* a, u8 b, s32 c, s32 d, s32 e);
u8 func_080E8FB8(u8 a, s32 b, s32 c, s32 d);
void func_080E9338(s32 a);
void func_080E9344(s32 a);
void func_080E9034(u8 a, u8 b, s32 c, s32 d, s32 e);
void func_080E935C(void);
void func_080E93FC(void);
void func_080E9508(void);
void func_080E9550(void);
void func_080E95C4(void);
void func_080E95E8(void);
void func_080E963C(void);
void Mode_MapDbg_0(void);
void Mode_MapDbg_1(void);
void Mode_MapDbg_2(void);
void func_080E98B0(void);
void func_080E9A00(void);
void func_080E9A28(void);
void func_080E9AF0(void);
void func_080E9B7C(void);
void func_080E9CBC(void);
void func_080E9E04(void);
void func_080E9E28(void);
void func_080E9E94(void);
void func_080E9F30(void);
void Mode_MapFld_0(void);
void Mode_MapFld_1(void);
void Mode_MapFld_2(void);
UnkStruct_09EF8370* func_080EA20C(void);
void func_080EA2AC(void);
u8 func_080EA400(void);
u8 func_080EA45C(void);
void func_080EA498(void);
void func_080EA5A8(void);
void func_080EA5CC(void);
void func_080EA694(void);
void func_080EA730(void);
void func_080EA78C(void);
void func_080EA7FC(void);
void Mode_MapFix_0(void);
void func_080EA7D8(void);
void Mode_MapFix_1(void);
void Mode_MapFix_2(void);
void func_080E9D94(void);
void func_080E988C(s32 a);
void func_080E9898(s32 a);
void func_080EA1E8(s32 a);
void func_080EA1F4(s32 a);
s32 func_080EAD3C(u8 i);
void func_080EB818(u8 a, u8 b, u8 c);
void func_080EB898(u8 a, u16 b);
void func_080EB93C(u8 a, u32 v);
void func_080ED0B8(FldRes* p, u8 a, u16 v);
void func_080ED14C(FldRes* p, u8 a, u32 v);
s32 Task_MapFix_1(u8* work);
void func_080ECA88(MapDoorWork* p);
u8 func_080ECC8C(MapDoorWork* p);
void func_080ECFE8(UnkStruct_080ECFE8* p, u8 a);
void func_080ED06C(UnkStruct_080ED06C* p, u8 a);
void func_080EE50C(UnkStruct_080EE50C* p, u8 a);
void func_080EE580(UnkStruct_080EE580* p, u8 a);
void func_080EE5E0(u8 a);

void func_080E3CD4(s32 a, s16* px, s16* py, s16* pz, s16 e, s16 f);
void func_080E64D4(MapEnmWork* p);
void func_080EBA58(u8 a);
void func_080EE760(u8* work, u8 i);
void func_080E00E4(s32 a, s32 b);
void func_080EAF10(void);
void func_080EBB24(void);
void func_080EB12C(NewGameSlotMenuWork* w);
void Mode_MenuNew_1(void);
void Mode_MenuLoad_1(void);
s32 Task_MapRnd_1(MapRndWork* w);
void func_080ECAA8(MapDoorWork* p);
void func_080EE62C(u16 v);
void func_080EE6AC(u32 t);
void func_080E0C1C(u16 a, u16 b);
void func_080E0ED4(UnkStruct_02034F20* p);
void func_080E0FD8(UnkStruct_02034F20* p);
void func_080E1138(void);

#endif /* GUARD_MAP_H */
