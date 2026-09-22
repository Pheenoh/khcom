#include "macros.h"
#include "card_localized_data.h"
#include "card_animation_data.h"
#include "card_sprite_data.h"
#include "msg_localized_data.h"
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "mode_sio_api.h"
#include "card_battle.h"
#include "mode_test_api.h"
#include "player_progression.h"
#include "m4a_song.h"
#include "game_state.h"
#include <string.h>
#include "text.h"
#include "monsgage.h"
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "engine_math.h"
#include "listpool.h"
#include "anim.h"
#include "obj.h"
#include "text_types.h"
#include "taskpool.h"
#include "key.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "card.h"
#include "card_reload_assets.h"
#include "map_card_assets.h"
#include "card_localized_assets.h"
#include "card_help_assets.h"
#include "card_message_assets.h"
#include "card_description_assets.h"
#include <stddef.h>
#include "game.h"
#include "bos4_api.h"

extern void* gUnk_09EE7578[];
extern AnimHeader** gUnk_09EE7588[];
extern void** gUnk_09EE7598[];
extern void* gUnk_09EE75A8[];
extern void** gUnk_09EE75B8[];
extern AnimHeader** gUnk_09EE75C8[];
extern void* gUnk_09EE7698[];
extern void* gUnk_09EE76C0[];
extern void** gUnk_09EE76D0[];
extern void* gUnk_09EE7708[];
extern AnimHeader** gUnk_09EE7714[];
extern void** gUnk_09EE7720[];
extern UnkStruct_09EE752C gUnk_09EE752C[7];
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
extern void* gUnkEu_09F72A3C[5];
extern void* gUnkEu_09F72A50[5];
extern void* gUnkEu_09F72A64[5];
extern void** gUnkEu_09F72BFC[5];
extern void* gUnkEu_09F6FD8C[];
extern void** gUnkEu_09F6FDA0[];
extern void** gUnkEu_09F72CC4[];
extern void* gUnkEu_09F72CB0[];
extern void* gUnkEu_09F6FDB4[];
extern void* gUnkEu_09F6FDDC[];
extern void* gUnkEu_09F7434C[];
extern void** gUnkEu_09F72E10[];
extern u8* gUnkEu_09F74374[];
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
u32 gUnk_02034AA4;
u32 gUnk_02034AA8;
CardDisplayWork* gUnk_02034AAC;
u8 gActiveDeck;
u8 gUnk_02034AB1[3];
s16 gUnk_02034AB4;
u8 gUnk_02034AB6[2];
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
u8 gUnkEu_02034AD4[4];
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
u8 gUnk_02034AB8[20];
u8 gUnk_02034ACC;
u32 gUnk_02034AD0;
void* gUnk_02034AD4;
u8 gUnk_02034AD8;
u8 gUnk_02034AD9;
u8 gUnk_02034ADA[6];
u8 gUnk_02034AE0[20];
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
u8 gUnk_02034AF4[4];
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
u8 gUnk_02034AF8;
UnkStruct_02034AFC* gUnk_02034AFC;

#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif

#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
u8 gUnk_02039DD8 EWRAM_COMMON(4);
u8 gUnk_02039DDC EWRAM_COMMON(4);
Deck gDecks[3] EWRAM_COMMON(16);
u16 gCardCollection[999] EWRAM_COMMON(16);
Deck* gUnk_0203A850 EWRAM_COMMON(4);
void* gUnk_0203A854 EWRAM_COMMON(4);
u16 gCardCount EWRAM_COMMON(4);
CardUiSpriteState gUnk_0203A860 EWRAM_COMMON(16);
MapCardUiResources gUnk_0203A890 EWRAM_COMMON(16);
u8 gUnk_0203A8C0[270] EWRAM_COMMON(16);
struct CardListWork* gUnk_0203A9D0 EWRAM_COMMON(4);
u8 gUnk_0203A9D4 EWRAM_COMMON(4);
u8 gUnk_0203A9D8 EWRAM_COMMON(4);
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif

u8 func_0807EDEC(UnkStruct_08080268* w, void* a);
u8 func_0809511C(ReloadGageWork* w, void* a);
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
extern u8* gUnkEu_09F6FE04[];
extern void* gUnkEu_09F72D08[];
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
u8 HCEffectName_1(HcEffectNameWork* w, void* a);
u8 EnemyUsecard_1(CardDisplayWork* p, void* a);
void func_080A27EC(u8* work);
void func_0807BC24(CardDisplayWork* p, CardDisplayArgs* a);
u8 func_0807BD64(CardDisplayWork* p, void* a);
void func_0807BEC0(CardDisplayWork* p);
void card_not_have_2(CardDisplayWork* p);
void func_0807C2E0(CardDisplayWork* p);
void card_reload_0(CardDisplayWork* p, CardDisplayArgs* a);
u8 card_reload_1(CardDisplayWork* p, void* a);
void card_reload_2(CardDisplayWork* p);
void card_reload_3(CardDisplayWork* p);
void func_0807E8F4(UnkStruct_08080268* w);
u8 func_0807EDEC(UnkStruct_08080268* w, void* a);
void func_0807F99C(UnkStruct_08080268* w);
void func_0807FA0C(u8* work);
void func_08081A3C(CardDisplayWork* p, CardDisplayArgs* a);
u8 func_08081B70(CardDisplayWork* p, void* a);
void func_08081C98(CardDisplayWork* p);
void NO_Card_2(CardDisplayWork* p);
void func_080820F4(CardDisplayWork* p);
void Reload_Card_0(CardDisplayWork* p, CardDisplayArgs* a);
u8 Reload_Card_1(CardDisplayWork* p, void* a);
void Reload_Card_3(CardDisplayWork* p);
void Reload_Card_2(CardDisplayWork* p);
void Bosscard_0(BossCardWork* w, u32* a);
u8 Bosscard_1(u8* work, void* a);
void Bosscard_2(void);
void Bosscard_3(void);
void map_anim_0(MapTileAnimationWork* p);
u8 map_anim_1(MapTileAnimationWork* w);
void map_anim_2(void);
void map_anim_3(void);
void func_08085FB4(u8* work, void* a);
u8 func_080863C0(u8* work, void* a);
void func_0808B66C(UnkStruct_0808B66C* w);
void func_0808C2F0(u8* work);
extern u8 gUnk_090A5F1E[];
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
extern void* gUnkEu_09F6FE30[];
extern void* gUnkEu_09F6FE58[];
extern void** gUnkEu_09F6FE44[];
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
void DeckCard2_0(DeckCard2Work* n, DeckCard2Args* a);
u8 DeckCard2_1(DeckCard2Work* n);
void DeckCard2_2(DeckCard2Work* n);
void DeckCard2_3(u8* p);
void card_enemy_0(CardDisplayWork* p, CardDisplayArgs* a);
u8 card_enemy_1(CardDisplayWork* p, void* a);
void func_08090374(CardDisplayWork* p);
void func_08090530(u8* work);
u8 EnemyUsecard_1(CardDisplayWork* p, void* a);
void func_08090EA0(CardDisplayWork* p, CardDisplayArgs* a);
void func_08091048(CardDisplayWork* p, CardDisplayArgs* a);
void func_08091138(CardDisplayWork* p, CardDisplayArgs* a);
void WORLDSELECT_0(void);
void WORLDSELECT_1(void);
void WORLDSELECT_2(void);
extern u8 gUnk_093F6734[];
void MapSelect_0(MapSelectWork* w, u8* a);
u8 MapSelect_1(MapSelectWork* w, void* a);
void MapSelect_2(MapSelectWork* w);
void MapSelect_3(MapSelectWork* w);
void Mapcard_0(MapcardWork* w, MapcardArgs* a);
u8 Mapcard_1(MapcardWork* w, void* a);
void Mapcard_2(MapcardWork* w);
void Mapcard_3(MapcardWork* w);
void func_08094EB0(ReloadGageWork* w, ReloadGageArgs* a);
u8 func_0809511C(ReloadGageWork* w, void* a);
void func_08095520(CardDisplayWork* p);
void func_080956AC(CardDisplayWork* p);
void PrizeCard_0(PrizeCardWork* w, PrizeCardTaskArgs* p);
u8 func_08095E68(PrizeCardWork* w, void* a);
void func_08096428(PrizeCardWork* w);
void func_080965CC(PrizeCardWork* w);
void func_08096714(PrizeCardInitWork* w, PrizeCardArgs* args);
s32 PrizeCardInit_1(PrizeCardInitWork* w);
s32 PrizeCardInit_Boss_1(PrizeCardInitWork* w, void* a);
void func_08096C20(void* pool);
void func_08096C2C(void* pool);
void DispCardname_0(u8* work, u16* a);
s32 DispCardname_1(void);
void DispCardname_2(u8* work);
void DispCardname_3(u8* work);
void Version_0(u8* work);
s32 Version_1(void);
void Version_2(u8* work);
void Version_3(s32* p);
void func_08096F94(UnkStruct_08096F94* w, s32* args);
u8 func_08097138(UnkStruct_08096F94* w, void* a);
void func_08097688(UnkStruct_08096F94* w);
void func_08097834(PrizeCardWork* w);
void SpotLight_0(SpotlightWork* w, u8* src);
u8 SpotLight_1(SpotlightWork* w, void* a);
void SpotLight_2(void);
void SpotLight_3(void);
void SELMAP_EVKEY_0(SelmapEventKeyWork* work, void* a);
s32 SELMAP_EVKEY_1(u8* work, void* a);
void SELMAP_EVKEY_2(u8* work);
void SELMAP_EVKEY_3(u8* work);
void RELOAD_CHILDREN_0(ReloadChildWork* w, ReloadChildArgs* a);
u8 RELOAD_CHILDREN_1(ReloadChildWork* w, void* a);
void RELOAD_CHILDREN_2(ReloadChildWork* w);
void RELOAD_CHILDREN_3(void** p);
void REV_COUNT_0(RevCountWork* w, RevCountArgs* a);
u8 REV_COUNT_1(RevCountWork* w, void* a);
void REV_COUNT_2(RevCountWork* w);
void REV_COUNT_3(RevCountWork* w);
void RELOAD_0(ReloadWork* w, ReloadArgs* a);
u8 RELOAD_1(u8* work, void* a);
void RELOAD_2(u8* work);
void RELOAD_3(void** p);
void PrizeBoss_0(BossPrizeWork* w, s32* args);
u8 PrizeBoss_1(BossPrizeWork* w, void* a);
void PrizeBoss_2(BossPrizeWork* w);
void PrizeBoss_3(BossPrizeWork* w);
void Card_EFFECT_0(CardEffectWork* w, CardEffectArgs* a);
u8 Card_EFFECT_1(CardEffectWork* w);
void Card_EFFECT_2(u8* work);
void Card_EFFECT_3(u8* work);
void scrollbar_0(ScrollBarWork* w, u16* args);
u8 scrollbar_1(ScrollBarWork* w);
void scrollbar_2(void);
void scrollbar_3(void);
void func_0809A02C(UnkStruct_0809A02C* w, s32* args);
void func_0809A1B8(UnkStruct_0809A02C* w, s32* args);
void func_0809A368(UnkStruct_0809A02C* w, UnkStruct_0809A368_Args* args);
s32 func_0809A54C(UnkStruct_0809A02C* w, void* a);
s32 func_0809A840(UnkStruct_0809A02C* w, void* a);
s32 func_0809AF84(UnkStruct_0809A02C* w, void* a);
void func_0809B200(UnkStruct_0809A02C* w);
void func_0809B3F4(UnkStruct_0809A02C* w);
void func_0809B59C(UnkStruct_0809A02C* w);
void func_0809B5F4(UnkStruct_0809A02C* w);
void func_0809B76C(u8* work, void** src);
u8 func_0809B840(StockNameWork* w);
void func_0809B8F0(u8* work);
void func_0809B920(u8* work, void** src);
u8 func_0809B9F4(StockNameWork* w);
void func_0809BAA4(u8* work);
void func_0809BAE4(u8* work);
void func_0809BB18(u8* work);
void func_0809BB4C(UnkStruct_0809BB4C* w);
u8 func_0809C078(u8* work, void* a);
void func_0809C110(u8* work);
void func_0809C1EC(u8* work);
void func_0809C534(UnkStruct_0809C534* w, UnkStruct_0809C534_Args* a);
u8 func_0809C710(u8* work, void* a);
void func_0809C78C(UnkStruct_0809C534* w);
void func_0809C98C(void** work);
void CardName_0(CardNameWork* w);
s32 CardName_1(void);
void CardName_2(u8* work);
void CardName_3(u8* work);
void func_0809CE88(PremiumCardEffectWork* w, s16* a);
void func_0809CF64(PremiumCardEffectWork* w, s16* a);
s32 func_0809D040(PremiumCardEffectWork* w);
s32 Premire_EFFECT2_1(PremiumCardEffectWork* w);
s32 func_0809D09C(PremiumCardEffectWork* w);
void func_0809D0CC(PremiumCardEffectWork* w);
void func_0809D0FC(PremiumCardEffectWork* w);
void Mode_Premire_0(void);
void Mode_Premire_1(void);
void Mode_Premire_2(void);
void HCEffectName_0(HcEffectNameWork* w, u8* a);
u8 HCEffectName_1(HcEffectNameWork* w, void* a);
void HCEffectName_2(HcEffectNameWork* w);
void HCEffectName_3(u8* work);
void NumberPlus_0(NumberPlusWork* w, NumberPlusArgs* args);
s32 NumberPlus_1(u8* work);
void NumberPlus_2(u8* work);
void NumberPlus_3(void** p);
extern u8 gUnk_0908CAEC[];
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
extern void* gUnkEu_09F72D1C[];
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
void Level_Up_0(LevelUpWork* w);
extern u8 gUnk_095112B8[];
extern u16* gUnk_09EE78D4[];
extern u16* gUnk_09EE78F0[];
extern void* gUnk_09EE7914[];
extern const void* gUnk_09EE790C[];
extern u8 gUnk_0950F2B8[];
u8 Level_Up_1(LevelUpWork* w, void* a);
extern const void* gUnk_09EE790C[];
void Level_Up_2(LevelUpWork* w);
void Level_Up_3(u8* work);
void LVUP_EFFECT_0(LevelUpEffectWork* w, LevelUpEffectArgs* a);
u8 LVUP_EFFECT_1(LevelUpEffectWork* w, void* a);
void LVUP_EFFECT_2(LevelUpEffectWork* w);
void LVUP_EFFECT_3(u8* work);
void Lvup_Logo_0(LevelUpEffectWork* w, LevelUpEffectArgs* a);
s32 Lvup_Logo_1(u8* work);
void Lvup_Logo_2(u8* work);
void Lvup_Logo_3(void** p);
void Ev_mapObj_0(u8* work, u8* a);
u8 Ev_mapObj_1(u8* work);
void Ev_mapObj_2(EventMapObjectWork* w);
void Ev_mapObj_3(u8* work);
void EV_BG_EFFECT_0(u8* a, u8* b);
u8 EV_BG_EFFECT_1(EventBgEffectWork* w, void* a);
void EV_BG_EFFECT_2(void);
void EV_BG_EFFECT_3(void);
void StockInfo_0(u8* work, void* a);
u8 StockInfo_1(u8* work, void* a);
void StockInfo_2(u8* work);
void StockInfo_3(u8* work);
void func_080A23A0(UnkStruct_080A2678* w, UnkStruct_080A23A0_Args* a);
s32 func_080A25B8(UnkStruct_080A2678* w, void* a);
void func_080A2678(UnkStruct_080A2678* w);
void func_080A27EC(u8* work);
void func_080A2844(DeckConfirmWork* w, u8* a);
void func_080A2980(DeckConfirmWork* w, u8* a);
void func_080A2A80(DeckConfirmWork* w, u8* a);
void func_080A2BA4(DeckConfirmWork* w, u8* a);
void func_080A2CC4(DeckConfirmWork* w, u8* a);
s32 func_080A2DE4(void);
void func_080A2E14(DeckConfirmWork* w);
void func_080A2EF8(DeckConfirmWork* w);
void Deck_Yes_No_0(DeckConfirmWork* w, u8* a);
s32 func_080A30C0(void);
void Deck_Clear_0(DeckConfirmWork* w, u8* a);
void func_080A33C4(UnkStruct_080A3F5C* w, void* a);
u8 func_080A3640(UnkStruct_080A3F5C* w, void* a);
void func_080A3848(UnkStruct_080A3F5C* w);
void func_080A3A04(UnkStruct_080A3F5C* w);
void func_080A430C(UnkStruct_080A4DCC* w, void* a);
u8 func_080A4578(UnkStruct_080A3F5C* w, void* a);
void func_080A4A50(UnkStruct_080A3F5C* w);
void func_080A4C1C(UnkStruct_080A3F5C* w);
void func_080A4DCC(UnkStruct_080A4DCC* w, void* a);
u8 func_080A4F14(UnkStruct_080A3F5C* w, void* a);
void func_080A52BC(UnkStruct_080A3F5C* w);
void func_080A53E4(UnkStruct_080A3F5C* w);
void WorldSel_Before_0(WorldSelBeforeWork* w, WorldSelBeforeArgs* a);
s32 WorldSel_Before_1(WorldSelBeforeWork* w);
void WorldSel_Before_2(WorldSelBeforeWork* w);
void WorldSel_Before_3(void** p);
void func_080A584C(u8* work, void* a);
u8 func_080A5C9C(u8* work, void* a);
void func_080A6500(u8* work);
void func_080A676C(u8* work);
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
void deckexchange_0(u8* work, void* a);
u8 deckexchange_1(u8* work, void* a);
void deckexchange_2(UnkStruct_0808C940* w);
void deckexchange_3(u8* work);
void func_080AAF78(void);
void func_080AAFB4(void);
void func_080AB008(void);
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
void DarkPoint_0(DarkPointWork* w);
s32 DarkPoint_1(DarkPointWork* w);
void DarkPoint_2(DarkPointWork* w);
void DarkPoint_3(void** p);
void func_080AB96C(void* a);
void Mode_riku_btlTutorial_1(void);
void Mode_riku_deckTutorial_1(void);
void func_080ABA70(void);
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void eu_080AB9FC(void);
void eu_080ABA38(void);
void eu_080ABA7C(void);
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
void task_print_0(void);
s32 task_print_1(void);
void task_print_2(void);
void task_print_3(void);
void func_0807BEC0(CardDisplayWork* p);
void func_08081C98(CardDisplayWork* p);
void func_08085FB4(u8* work, void* a);
void func_0809BB4C(struct UnkStruct_0809BB4C* w);
void func_080A584C(u8* work, void* a);

const char gTaskName_09EE496C[] __attribute__((section(".rodata_registration_name_gUnk_09EE496C"), aligned(1))) = "card";

TaskDesc gUnk_09EE496C = {
    gTaskName_09EE496C,
    (void (*)(void*, void*))func_0807BC24,
    func_0807BD64,
    (void (*)(void*))func_0807BEC0,
    (void (*)(void*))func_0807C2E0,
    0xA8,
};

const char gTaskName_09EE4984[] __attribute__((section(".rodata_registration_name_gUnk_09EE4984"), aligned(1))) = "card_not_have";

TaskDesc gUnk_09EE4984 = {
    gTaskName_09EE4984,
    (void (*)(void*, void*))func_0807BC24,
    func_0807BD64,
    (void (*)(void*))card_not_have_2,
    (void (*)(void*))func_0807C2E0,
    0xA8,
};

const char gTaskName_09EE499C[] __attribute__((section(".rodata_registration_name_gUnk_09EE499C"), aligned(1))) = "card_reload";

TaskDesc gUnk_09EE499C = {
    gTaskName_09EE499C,
    (void (*)(void*, void*))card_reload_0,
    card_reload_1,
    (void (*)(void*))card_reload_2,
    (void (*)(void*))card_reload_3,
    0xA8,
};

const char gTaskNameCardBattleRiku[] __attribute__((section(".rodata_registration_name_gTaskDescCardBattleRiku"), aligned(1))) = "cardbattle";

TaskDesc gTaskDescCardBattleRiku = {
    gTaskNameCardBattleRiku,
    (void (*)(void*, void*))func_0807E8F4,
    func_0807EDEC,
    (void (*)(void*))func_0807F99C,
    (void (*)(void*))func_0807FA0C,
    0xCC,
};

const char gTaskName_09EE49CC[] __attribute__((section(".rodata_registration_name_gUnk_09EE49CC"), aligned(1))) = "card";

TaskDesc gUnk_09EE49CC = {
    gTaskName_09EE49CC,
    (void (*)(void*, void*))func_08081A3C,
    func_08081B70,
    (void (*)(void*))func_08081C98,
    (void (*)(void*))func_080820F4,
    0xA8,
};

const char gTaskName_09EE49E4[] __attribute__((section(".rodata_registration_name_gUnk_09EE49E4"), aligned(1))) = "NO_Card";

TaskDesc gUnk_09EE49E4 = {
    gTaskName_09EE49E4,
    (void (*)(void*, void*))func_08081A3C,
    func_08081B70,
    (void (*)(void*))NO_Card_2,
    (void (*)(void*))func_080820F4,
    0xA8,
};

const char gTaskName_09EE49FC[] __attribute__((section(".rodata_registration_name_gUnk_09EE49FC"), aligned(1))) = "Reload_Card";

TaskDesc gUnk_09EE49FC = {
    gTaskName_09EE49FC,
    (void (*)(void*, void*))Reload_Card_0,
    Reload_Card_1,
    (void (*)(void*))Reload_Card_2,
    (void (*)(void*))Reload_Card_3,
    0xA8,
};

const char gTaskNameBosscard[] __attribute__((section(".rodata_registration_name_gTaskDescBosscard"), aligned(1))) = "Bosscard";

TaskDesc gTaskDescBosscard = {
    gTaskNameBosscard,
    (void (*)(void*, void*))Bosscard_0,
    Bosscard_1,
    (void (*)(void*))Bosscard_2,
    (void (*)(void*))Bosscard_3,
    0x38,
};

const MapTileAnimationDef* gUnk_09EE4A2C[6] = {
    &gUnk_09035388,
    &gUnk_09035450,
    &gUnk_0903547C,
    &gUnk_090354A4,
    &gUnk_090354D4,
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A44 = {
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A48 = {
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A4C = {
    NULL,
};

const char gTaskNameMapAnim[] __attribute__((section(".rodata_registration_name_gTaskDescMapAnim"), aligned(1))) = "map_anim";

TaskDesc gTaskDescMapAnim = {
    gTaskNameMapAnim,
    (void (*)(void*, void*))map_anim_0,
    map_anim_1,
    (void (*)(void*))map_anim_2,
    (void (*)(void*))map_anim_3,
    0x18,
};

const u16* gUnk_09EE4A68[12] = {
    gUnk_090354E8,
    gUnk_09035512,
    gUnk_0903553A,
    gUnk_09035564,
    gUnk_0903557C,
    gUnk_090355A4,
    gUnk_090355C8,
    gUnk_090355EA,
    gUnk_0903560A,
    gUnk_09035630,
    gUnk_0903563A,
    gUnk_0903566C,
};

const u16* gUnk_09EE4A98[12] = {
    &gUnk_090356A8,
    &gUnk_090356AA,
    &gUnk_090356AC,
    &gUnk_090356AE,
    &gUnk_090356B0,
    &gUnk_090356B2,
    &gUnk_090356B4,
    &gUnk_090356B6,
    &gUnk_090356B8,
    &gUnk_090356B8,
    gUnk_090356BA,
    gUnk_090356BA,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
u8 gUnkEu_09F6FD74[7] = { 'D', 'e', 'c', 'k', ' ', '1', 0 };

u8 gUnkEu_09F6FD7B[7] = { 'D', 'e', 'c', 'k', ' ', '2', 0 };

u8 gUnkEu_09F6FD82[7] = { 'D', 'e', 'c', 'k', ' ', '3', 0 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
#ifdef VERSION_EU
#else
u16 gUnk_09EE4AC8[7] = { 'D', 'e', 'c', 'k', ' ', '1', 0 };

u16 gUnk_09EE4AD6[7] = { 'D', 'e', 'c', 'k', ' ', '2', 0 };

u16 gUnk_09EE4AE4[7] = { 'D', 'e', 'c', 'k', ' ', '3', 0 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnkEu_09F6FD8C[5] = { gUnkEu_09187A0E, gUnkEu_09189F36, gUnkEu_0918A73A, gUnkEu_0918A48E, gUnkEu_0918A1E2 };

void** gUnkEu_09F6FDA0[5] = { &gUnk_09EEAFD4, &gUnkEu_09F77070, &gUnkEu_09F77094, &gUnkEu_09F77088, &gUnkEu_09F7707C };

void* gUnkEu_09F6FDB4[5] = { gUnk_090A261E, gUnkEu_0918B8F2, gUnkEu_0919016A, gUnkEu_0918E942, gUnkEu_0918D11A };

void** gUnkEu_09F6FDC8[5] = {
    &gUnk_09EEAFE8,
    &gUnkEu_09F770C0,
    &gUnkEu_09F770D8,
    &gUnkEu_09F770D0,
    &gUnkEu_09F770C8,
};

void* gUnkEu_09F6FDDC[5] = { gUnk_090A3E46, gUnkEu_09191992, gUnkEu_0919236A, gUnkEu_09192022, gUnkEu_09191CDA };

void** gUnkEu_09F6FDF0[5] = {
    &gUnk_09EEAFF0,
    &gUnkEu_09F770E0,
    &gUnkEu_09F770F8,
    &gUnkEu_09F770F0,
    &gUnkEu_09F770E8,
};

u8* gUnkEu_09F6FE04[5] = { gUnkEu_094EAD64, gUnkEu_094E90E4, gUnkEu_094EA2E4, gUnkEu_094E9CE4, gUnkEu_094E96E4 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskName_09EE4AF4[] __attribute__((section(".rodata_registration_name_gUnk_09EE4AF4"), aligned(1))) = "Deckmenu2";

TaskDesc gUnk_09EE4AF4 = {
    gTaskName_09EE4AF4,
    (void (*)(void*, void*))func_08085FB4,
    func_080863C0,
    (void (*)(void*))func_0808B66C,
    (void (*)(void*))func_0808C2F0,
#ifdef VERSION_EU
    0x8DC,
#else
    0x8D8,
#endif
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnkEu_09F6FE30[5] = { gUnk_090A5F1E, gUnk_090A5F1E, gUnkEu_091965CA, gUnkEu_091959DA, gUnk_090A5F1E };

void** gUnkEu_09F6FE44[5] = { gUnk_09EEB08C, gUnk_09EEB08C, gUnkEu_09F7721C, gUnkEu_09F771E4, gUnk_09EEB08C };

void* gUnkEu_09F6FE58[5] = { gUnk_09EEB0B8, gUnk_09EEB0B8, gUnkEu_09F77248, gUnkEu_09F77210, gUnk_09EEB0B8 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
#ifdef VERSION_US
const u8* gUnk_09EE4B0C[7] = {
    gKeyboardTextUs_09035742,
    gKeyboardTextUs_09035762,
    gKeyboardTextUs_0903577A,
    gKeyboardTextUs_0903579A,
    gKeyboardTextUs_090357B2,
    gKeyboardTextUs_090357D2,
    gKeyboardTextUs_090357F2,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
#ifdef VERSION_JP
const u8* gUnk_09EE4B0C[7] = {
    gKeyboardTextJp_09008AE0,
    gKeyboardTextJp_09008AC0,
    gKeyboardTextJp_09008AA0,
    gKeyboardTextJp_09008A88,
    gKeyboardTextJp_09008A68,
    gKeyboardTextJp_09008A48,
    gKeyboardTextJp_09008A2C,
};

const u8* gUnkJp_09EBC148[7] = {
    gKeyboardTextJp_09008BB4,
    gKeyboardTextJp_09008B94,
    gKeyboardTextJp_09008B74,
    gKeyboardTextJp_09008B5C,
    gKeyboardTextJp_09008B3C,
    gKeyboardTextJp_09008B1C,
    gKeyboardTextJp_09008B00,
};

const u8* gUnkJp_09EBC164[7] = {
    gKeyboardTextJp_09008C84,
    gKeyboardTextJp_09008C64,
    gKeyboardTextJp_09008C44,
    gKeyboardTextJp_09008C24,
    gKeyboardTextJp_09008C0C,
    gKeyboardTextJp_09008BEC,
    gKeyboardTextJp_09008BD4,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
const u8* gUnkEu_09F6FE6C[8] = {
    gKeyboardTextEu_090CEA56,
    gKeyboardTextEu_090CEA66,
    gKeyboardTextEu_090CEA72,
    gKeyboardTextEu_090CEA82,
    gKeyboardTextEu_090CEA8E,
    gKeyboardTextEu_090CEA9E,
    gKeyboardTextEu_090CEAA9,
    gKeyboardTextEu_090CEAB9,
};

const u8* gUnkEu_09F6FE8C[7] = {
    gKeyboardTextEu_090CEAC4,
    gKeyboardTextEu_090CEAD4,
    gKeyboardTextEu_090CEADF,
    gKeyboardTextEu_090CEAEF,
    gKeyboardTextEu_090CEAFF,
    gKeyboardTextEu_090CEB05,
    gKeyboardTextEu_090CEB15,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskName_09EE4B28[] __attribute__((section(".rodata_registration_name_gUnk_09EE4B28"), aligned(1))) = "DeckCard2";

TaskDesc gUnk_09EE4B28 = {
    gTaskName_09EE4B28,
    (void (*)(void*, void*))DeckCard2_0,
    DeckCard2_1,
    (void (*)(void*))DeckCard2_2,
    (void (*)(void*))DeckCard2_3,
    0x50,
};

const char gTaskName_09EE4B40[] __attribute__((section(".rodata_registration_name_gUnk_09EE4B40"), aligned(1))) = "card_enemy";

TaskDesc gUnk_09EE4B40 = {
    gTaskName_09EE4B40,
    (void (*)(void*, void*))card_enemy_0,
    card_enemy_1,
    (void (*)(void*))func_08090374,
    (void (*)(void*))func_08090530,
    0xA8,
};

const char gTaskName_09EE4B58[] __attribute__((section(".rodata_registration_name_gUnk_09EE4B58"), aligned(1))) = "EnemyUsecard";

TaskDesc gUnk_09EE4B58 = {
    gTaskName_09EE4B58,
    (void (*)(void*, void*))func_08090EA0,
    EnemyUsecard_1,
    (void (*)(void*))func_08090374,
    (void (*)(void*))func_08090530,
    0xA8,
};

TaskDesc gUnk_09EE4B70 = {
    gTaskName_09EE4B58,
    (void (*)(void*, void*))func_08091048,
    EnemyUsecard_1,
    (void (*)(void*))func_08090374,
    (void (*)(void*))func_08090530,
    0xA8,
};

TaskDesc gUnk_09EE4B88 = {
    gTaskName_09EE4B58,
    (void (*)(void*, void*))func_08091138,
    EnemyUsecard_1,
    (void (*)(void*))func_08090374,
    (void (*)(void*))func_08090530,
    0xA8,
};

const char gUnk_090359BC[] __attribute__((section(".rodata_registration_name_gUnk_09EE4BA0"), aligned(1))) = "WORLDSELECT";

Mode gUnk_09EE4BA0 = {
    gUnk_090359BC,
    (void (*)(s32))WORLDSELECT_0,
    WORLDSELECT_1,
    WORLDSELECT_2,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnkEu_09F6FF30[5] = {
    gUnk_093F6734, gUnkEu_094C9860, gUnk_093F6734, gUnkEu_094C9860, gUnkEu_094C9C20,
};

void** gUnkEu_09F6FF44[5] = {
    gUnk_09EF11F8, gUnkEu_09F7C454, gUnk_09EF11F8, gUnkEu_09F7C454, gUnkEu_09F7C47C,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const void* gUnk_09EE4BB0[2] = {
    gUnk_08125E24, gUnk_096102B8,
};

s16 gUnk_09EE4BB8[5] = {
    59, 99, 139, 179, 219,
};

s16 gUnk_09EE4BC2[2] = {
    88, 112,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void** gUnkEu_09F6FF70[5] = {
    gUnk_09EF1228, gUnkEu_09F7C414, gUnkEu_09F7C42C, gUnkEu_09F7C424, gUnkEu_09F7C41C,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskNameMapSelect[] __attribute__((section(".rodata_registration_name_gTaskDescMapSelect"), aligned(1))) = "MapSelect";

TaskDesc gTaskDescMapSelect = {
    gTaskNameMapSelect,
    (void (*)(void*, void*))MapSelect_0,
    MapSelect_1,
    (void (*)(void*))MapSelect_2,
    (void (*)(void*))MapSelect_3,
    0x2E4,
};

u16 gUnk_09EE4BE0[10] = {
    72, 77, 82, 87, 92, 168, 173, 178, 183, 188,
};

MapCardBackDef gUnk_09EE4BF4[5] = {
    { gUnk_093F61B2, gUnk_09618D78, gUnk_09EF11E8, gUnk_0905E3BA, gUnk_09EE97F4, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F5C7A, gUnk_09618D78, gUnk_09EF11D8, gUnk_0905C862, gUnk_09EE9764, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F5F16, gUnk_09618D78, gUnk_09EF11E0, gUnk_0905D64E, gUnk_09EE97AC, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F61B2, gUnk_09618D78, gUnk_09EF11E8, gUnk_0905AC8A, gUnk_09EE96D4, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F644E, gUnk_09618D78, gUnk_09EF11F0, gUnk_0905E3BA, gUnk_09EE97F4, 640, 32, { 128, 2, 0, 0 } },
};

MapCardDef gUnk_09EE4C80[260] = {
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 0, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 1, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 2, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 3, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 4, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 5, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 6, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 7, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 8, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 9, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 0, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 1, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 2, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 3, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 4, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 5, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 6, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 7, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 8, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 9, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 0, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 1, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 2, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 3, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 4, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 5, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 6, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 7, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 8, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 9, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 0, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 1, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 2, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 3, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 4, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 5, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 6, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 7, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 8, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 9, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 0, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 1, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 2, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 3, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 4, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 5, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 6, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 7, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 8, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 9, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 0, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 1, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 2, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 3, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 4, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 5, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 6, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 7, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 8, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 9, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 0, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 1, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 2, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 3, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 4, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 5, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 6, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 7, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 8, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 9, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 0, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 1, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 2, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 3, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 4, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 5, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 6, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 7, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 8, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 9, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 0, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 1, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 2, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 3, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 4, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 5, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 6, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 7, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 8, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 9, 2, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 0, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 1, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 2, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 3, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 4, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 5, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 6, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 7, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 8, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 9, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 0, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 1, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 2, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 3, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 4, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 5, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 6, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 7, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 8, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 9, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 0, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 1, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 2, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 3, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 4, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 5, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 6, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 7, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 8, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 9, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 0, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 1, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 2, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 3, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 4, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 5, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 6, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 7, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 8, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 9, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 0, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 1, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 2, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 3, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 4, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 5, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 6, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 7, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 8, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 9, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 0, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 1, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 2, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 3, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 4, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 5, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 6, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 7, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 8, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 9, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 0, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 1, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 2, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 3, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 4, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 5, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 6, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 7, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 8, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 9, 1, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 0, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 1, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 2, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 3, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 4, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 5, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 6, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 7, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 8, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 9, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 0, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 1, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 2, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 3, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 4, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 5, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 6, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 7, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 8, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 9, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 0, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 1, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 2, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 3, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 4, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 5, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 6, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 7, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 8, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 9, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 0, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 1, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 2, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 3, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 4, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 5, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 6, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 7, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 8, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 9, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 0, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 1, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 2, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 3, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 4, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 5, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 6, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 7, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 8, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 9, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 0, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 1, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 2, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 3, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 4, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 5, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 6, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 7, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 8, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 9, 3, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 0, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 1, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 2, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 3, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 4, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 5, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 6, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 7, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 8, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 9, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 0, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 1, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 2, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 3, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 4, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 5, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 6, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 7, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 8, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 9, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 0, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 1, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 2, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 3, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 4, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 5, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 6, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 7, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 8, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 9, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 0, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 1, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 2, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 3, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 4, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 5, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 6, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 7, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 8, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 9, 4, 0 },
};

s16 gUnk_09EE7520[6] = {
    20,
    57,
    94,
    131,
    168,
    205,
};

UnkStruct_09EE752C gUnk_09EE752C[7] = {
    { 0, 5, 0, 0 },
    { 1, 5, 0, 0 },
    { 2, 5, 0, 0 },
    { 3, 5, 0, 0 },
    { 4, 5, 0, 0 },
    { 5, 5, 0, 0 },
    { 0, 100, 0, 0 },
};

const char gTaskNameMapcard[] __attribute__((section(".rodata_registration_name_gTaskDescMapcard"), aligned(1))) = "Mapcard";

TaskDesc gTaskDescMapcard = {
    gTaskNameMapcard,
    (void (*)(void*, void*))Mapcard_0,
    Mapcard_1,
    (void (*)(void*))Mapcard_2,
    (void (*)(void*))Mapcard_3,
    0x78,
};

const char gTaskName_09EE7560[] __attribute__((section(".rodata_registration_name_gUnk_09EE7560"), aligned(1))) = "Reload Gage";

TaskDesc gUnk_09EE7560 = {
    gTaskName_09EE7560,
    (void (*)(void*, void*))func_08094EB0,
    func_0809511C,
    (void (*)(void*))func_08095520,
    (void (*)(void*))func_080956AC,
    0xA8,
};

void* gUnk_09EE7578[4] = {
    gUnk_0909A4E0,
    gUnk_0909AB98,
    gUnk_09099E28,
    gUnk_0909AB98,
};

AnimHeader** gUnk_09EE7588[4] = {
    gUnk_09EEA4E0,
    gUnk_09EEA578,
    gUnk_09EEA448,
    gUnk_09EEA578,
};

void** gUnk_09EE7598[4] = {
    gUnk_09EEA494,
    gUnk_09EEA52C,
    gUnk_09EEA3FC,
    gUnk_09EEA52C,
};

void* gUnk_09EE75A8[4] = {
    gUnk_0909FDCA,
    gUnk_090A0C86,
    gUnk_0909EFDE,
    gUnk_0909EFDE,
};

void** gUnk_09EE75B8[4] = {
    gUnk_09EEAF04,
    gUnk_09EEAEBC,
    gUnk_09EEAE74,
    gUnk_09EEAEBC,
};

AnimHeader** gUnk_09EE75C8[4] = {
    gUnk_09EEAF38,
    gUnk_09EEAEF0,
    gUnk_09EEAEA8,
    gUnk_09EEAEF0,
};

const char gTaskName_09EE75D8[] __attribute__((section(".rodata_registration_name_gUnk_09EE75D8"), aligned(1))) = "PrizeCard";

TaskDesc gUnk_09EE75D8 = {
    gTaskName_09EE75D8,
    (void (*)(void*, void*))PrizeCard_0,
    func_08095E68,
    (void (*)(void*))func_08096428,
    (void (*)(void*))func_080965CC,
    0x100,
};

const char gTaskNamePrizeCardInit[] __attribute__((section(".rodata_registration_name_gTaskDescPrizeCardInit"), aligned(1))) = "PrizeCardInit";

TaskDesc gTaskDescPrizeCardInit = {
    gTaskNamePrizeCardInit,
    (void (*)(void*, void*))func_08096714,
    PrizeCardInit_1,
    (void (*)(void*))func_08096C20,
    (void (*)(void*))func_08096C2C,
    0x38,
};

const char gTaskNamePrizeCardInitBoss[] __attribute__((section(".rodata_registration_name_gTaskDescPrizeCardInitBoss"), aligned(1))) = "PrizeCardInit_Boss";

TaskDesc gTaskDescPrizeCardInitBoss = {
    gTaskNamePrizeCardInitBoss,
    (void (*)(void*, void*))func_08096714,
    PrizeCardInit_Boss_1,
    (void (*)(void*))func_08096C20,
    (void (*)(void*))func_08096C2C,
    0x38,
};

const char gTaskNameDispCardname[] __attribute__((section(".rodata_registration_name_gTaskDescDispCardname"), aligned(1))) = "DispCardname";

TaskDesc gTaskDescDispCardname = {
    gTaskNameDispCardname,
    (void (*)(void*, void*))DispCardname_0,
    DispCardname_1,
    (void (*)(void*))DispCardname_2,
    (void (*)(void*))DispCardname_3,
    0x110,
};

const char gTaskNameVersion[] __attribute__((section(".rodata_registration_name_gTaskDescVersion"), aligned(1))) = "Version";

TaskDesc gTaskDescVersion = {
    gTaskNameVersion,
    (void (*)(void*, void*))Version_0,
    Version_1,
    (void (*)(void*))Version_2,
    (void (*)(void*))Version_3,
    0x2C,
};

const char gTaskName_09EE7650[] __attribute__((section(".rodata_registration_name_gUnk_09EE7650"), aligned(1))) = "PrizeCard";

TaskDesc gUnk_09EE7650 = {
    gTaskName_09EE7650,
    (void (*)(void*, void*))func_08096F94,
    func_08097138,
    (void (*)(void*))func_08097688,
    (void (*)(void*))func_08097834,
    0xEC,
};

const char gTaskNameSpotLight[] __attribute__((section(".rodata_registration_name_gTaskDescSpotLight"), aligned(1))) = "SpotLight";

TaskDesc gTaskDescSpotLight = {
    gTaskNameSpotLight,
    (void (*)(void*, void*))SpotLight_0,
    SpotLight_1,
    (void (*)(void*))SpotLight_2,
    (void (*)(void*))SpotLight_3,
    0x18,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnkEu_09F72A3C[5] = { gUnk_09EF1224, gUnkEu_09F7C438, gUnkEu_09F7C450, gUnkEu_09F7C448, gUnkEu_09F7C440 };
void* gUnkEu_09F72A50[5] = { gUnk_09EF1220, gUnkEu_09F7C434, gUnkEu_09F7C44C, gUnkEu_09F7C444, gUnkEu_09F7C43C };
void* gUnkEu_09F72A64[5] = { gUnkEu_094C6154, gUnkEu_094C7CCE, gUnkEu_094C9180, gUnkEu_094C8946, gUnkEu_094C8288 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskNameSELMAPEVKEY[] __attribute__((section(".rodata_registration_name_gTaskDescSELMAPEVKEY"), aligned(1))) = "SELMAP_EVKEY";

TaskDesc gTaskDescSELMAPEVKEY = {
    gTaskNameSELMAPEVKEY,
    (void (*)(void*, void*))SELMAP_EVKEY_0,
    SELMAP_EVKEY_1,
    (void (*)(void*))SELMAP_EVKEY_2,
    (void (*)(void*))SELMAP_EVKEY_3,
    0x124,
};

void* gUnk_09EE7698[4] = {
    gUnk_090994A4,
    gUnk_0909937C,
    gUnk_09099410,
    gUnk_09099538,
};

const char gTaskNameReloadChildren[] __attribute__((section(".rodata_registration_name_gTaskDescReloadChildren"), aligned(1))) = "RELOAD_CHILDREN";

TaskDesc gTaskDescReloadChildren = {
    gTaskNameReloadChildren,
    (void (*)(void*, void*))RELOAD_CHILDREN_0,
    RELOAD_CHILDREN_1,
    (void (*)(void*))RELOAD_CHILDREN_2,
    (void (*)(void*))RELOAD_CHILDREN_3,
    0x48,
};

void* gUnk_09EE76C0[4] = {
    gUnk_0909D2AC,
    gUnk_0909D2AC,
    gUnk_0909D2AC,
    gUnk_0909D2AC,
};

void** gUnk_09EE76D0[4] = {
    gUnk_09EEA5C4,
    gUnk_09EEA5C4,
    gUnk_09EEA5C4,
    gUnk_09EEA5C4,
};

AnimHeader** gUnk_09EE76E0 = &gUnk_09EEA750;

AnimHeader** gUnk_09EE76E4 = &gUnk_09EEABA8;

AnimHeader** gUnk_09EE76E8 = &gUnk_09EEA97C;

AnimHeader** gUnk_09EE76EC = &gUnk_09EEADD4;

const char gTaskNameREVCOUNT[] __attribute__((section(".rodata_registration_name_gTaskDescREVCOUNT"), aligned(1))) = "REV_COUNT";

TaskDesc gTaskDescREVCOUNT = {
    gTaskNameREVCOUNT,
    (void (*)(void*, void*))REV_COUNT_0,
    REV_COUNT_1,
    (void (*)(void*))REV_COUNT_2,
    (void (*)(void*))REV_COUNT_3,
    0x44,
};

void* gUnk_09EE7708[3] = {
    gUnk_0909885E,
    gUnk_09098E0E,
    gUnk_09098B36,
};

AnimHeader** gUnk_09EE7714[3] = {
    gUnk_09EEA304,
    gUnk_09EEA32C,
    gUnk_09EEA318,
};

void** gUnk_09EE7720[3] = {
    gUnk_09EEA2F4,
    gUnk_09EEA31C,
    gUnk_09EEA308,
};

const char gTaskName_09EE772C[] __attribute__((section(".rodata_registration_name_gUnk_09EE772C"), aligned(1))) = "RELOAD";

TaskDesc gUnk_09EE772C = {
    gTaskName_09EE772C,
    (void (*)(void*, void*))RELOAD_0,
    RELOAD_1,
    (void (*)(void*))RELOAD_2,
    (void (*)(void*))RELOAD_3,
    0x38,
};

const char gTaskNamePrizeBoss[] __attribute__((section(".rodata_registration_name_gTaskDescPrizeBoss"), aligned(1))) = "PrizeBoss";

TaskDesc gTaskDescPrizeBoss = {
    gTaskNamePrizeBoss,
    (void (*)(void*, void*))PrizeBoss_0,
    PrizeBoss_1,
    (void (*)(void*))PrizeBoss_2,
    (void (*)(void*))PrizeBoss_3,
    0xF0,
};

const char gTaskNameCardEFFECT[] __attribute__((section(".rodata_registration_name_gTaskDescCardEFFECT"), aligned(1))) = "Card_EFFECT";

TaskDesc gTaskDescCardEFFECT = {
    gTaskNameCardEFFECT,
    (void (*)(void*, void*))Card_EFFECT_0,
    Card_EFFECT_1,
    (void (*)(void*))Card_EFFECT_2,
    (void (*)(void*))Card_EFFECT_3,
    0x4C,
};

const char gTaskNameScrollbar[] __attribute__((section(".rodata_registration_name_gTaskDescScrollbar"), aligned(1))) = "scrollbar";

TaskDesc gTaskDescScrollbar = {
    gTaskNameScrollbar,
    (void (*)(void*, void*))scrollbar_0,
    scrollbar_1,
    (void (*)(void*))scrollbar_2,
    (void (*)(void*))scrollbar_3,
    0x18,
};

const char gTaskName_09EE778C[] __attribute__((section(".rodata_registration_name_gUnk_09EE778C"), aligned(1))) = "Friend card";

TaskDesc gUnk_09EE778C = {
    gTaskName_09EE778C,
    (void (*)(void*, void*))func_0809A02C,
    func_0809A54C,
    (void (*)(void*))func_0809B200,
    (void (*)(void*))func_0809B59C,
    0x1D4,
};

const char gTaskName_09EE77A4[] __attribute__((section(".rodata_registration_name_gUnk_09EE77A4"), aligned(1))) = "Heartless card";

TaskDesc gUnk_09EE77A4 = {
    gTaskName_09EE77A4,
    (void (*)(void*, void*))func_0809A1B8,
    func_0809AF84,
    (void (*)(void*))func_0809B3F4,
    (void (*)(void*))func_0809B5F4,
    0x1D4,
};

const char gTaskName_09EE77BC[] __attribute__((section(".rodata_registration_name_gUnk_09EE77BC"), aligned(1))) = "Gimmick card";

TaskDesc gUnk_09EE77BC = {
    gTaskName_09EE77BC,
    (void (*)(void*, void*))func_0809A368,
    func_0809A840,
    (void (*)(void*))func_0809B200,
    (void (*)(void*))func_0809B59C,
    0x1D4,
};

const char gTaskName_09EE77D4[] __attribute__((section(".rodata_registration_name_gUnk_09EE77D4"), aligned(1))) = "StockName";

TaskDesc gUnk_09EE77D4 = {
    gTaskName_09EE77D4,
    (void (*)(void*, void*))func_0809B76C,
    func_0809B840,
    (void (*)(void*))func_0809B8F0,
    (void (*)(void*))func_0809BB18,
    0x34,
};

TaskDesc gUnk_09EE77EC = {
    gTaskName_09EE77D4,
    (void (*)(void*, void*))func_0809B920,
    func_0809B9F4,
    (void (*)(void*))func_0809BAA4,
    (void (*)(void*))func_0809BAE4,
    0x34,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void** gUnkEu_09F72BFC[5] = { gUnk_09EEA16C, &gUnkEu_09F75FB4, &gUnkEu_09F75FCC, &gUnkEu_09F75FC4, &gUnkEu_09F75FBC };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskName_09EE7804[] __attribute__((section(".rodata_registration_name_gUnk_09EE7804"), aligned(1))) = "Premire Chance";

TaskDesc gUnk_09EE7804 = {
    gTaskName_09EE7804,
    (void (*)(void*, void*))func_0809BB4C,
    func_0809C078,
    (void (*)(void*))func_0809C110,
    (void (*)(void*))func_0809C1EC,
    0x90,
};

const char gTaskName_09EE781C[] __attribute__((section(".rodata_registration_name_gUnk_09EE781C"), aligned(1))) = "Premire Chance";

TaskDesc gUnk_09EE781C = {
    gTaskName_09EE781C,
    (void (*)(void*, void*))func_0809C534,
    func_0809C710,
    (void (*)(void*))func_0809C78C,
    (void (*)(void*))func_0809C98C,
    0x78,
};

const char gTaskName_09EE7834[] __attribute__((section(".rodata_registration_name_gUnk_09EE7834"), aligned(1))) = "CardName";

TaskDesc gUnk_09EE7834 = {
    gTaskName_09EE7834,
    (void (*)(void*, void*))CardName_0,
    CardName_1,
    (void (*)(void*))CardName_2,
    (void (*)(void*))CardName_3,
#ifdef VERSION_EU
    0x31C,
#else
    0x22C,
#endif
};

const char gTaskName_09EE784C[] __attribute__((section(".rodata_registration_name_gUnk_09EE784C"), aligned(1))) = "Premire_EFFECT";

TaskDesc gUnk_09EE784C = {
    gTaskName_09EE784C,
    (void (*)(void*, void*))func_0809CE88,
    func_0809D040,
    (void (*)(void*))func_0809D0CC,
    (void (*)(void*))func_0809D0FC,
    0x54,
};

const char gTaskName_09EE7864[] __attribute__((section(".rodata_registration_name_gUnk_09EE7864"), aligned(1))) = "Premire_EFFECT2";

TaskDesc gUnk_09EE7864 = {
    gTaskName_09EE7864,
    (void (*)(void*, void*))func_0809CE88,
    Premire_EFFECT2_1,
    (void (*)(void*))func_0809D0CC,
    (void (*)(void*))func_0809D0FC,
    0x54,
};

TaskDesc gUnk_09EE787C = {
    gTaskName_09EE784C,
    (void (*)(void*, void*))func_0809CF64,
    func_0809D09C,
    (void (*)(void*))func_0809D0CC,
    (void (*)(void*))func_0809D0FC,
    0x54,
};

Mode gUnk_09EE7894 = {
    gUnk_09037F80,
    (void (*)(s32))Mode_Premire_0,
    Mode_Premire_1,
    Mode_Premire_2,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnkEu_09F72CB0[5] = { gUnk_093FB954, gUnkEu_094CE490, gUnkEu_094CE820, gUnkEu_094CE6F0, gUnkEu_094CE5C0 };

void** gUnkEu_09F72CC4[5] = { gUnk_09EF12C8, gUnkEu_09F7C55C, gUnkEu_09F7C57C, gUnkEu_09F7C59C, gUnkEu_09F7C5BC };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskNameHCEffectName[] __attribute__((section(".rodata_registration_name_gTaskDescHCEffectName"), aligned(1))) = "HCEffectName";

TaskDesc gTaskDescHCEffectName = {
    gTaskNameHCEffectName,
    (void (*)(void*, void*))HCEffectName_0,
    HCEffectName_1,
    (void (*)(void*))HCEffectName_2,
    (void (*)(void*))HCEffectName_3,
    0x28,
};

const char gTaskNameNumberPlus[] __attribute__((section(".rodata_registration_name_gTaskDescNumberPlus"), aligned(1))) = "NumberPlus";

TaskDesc gTaskDescNumberPlus = {
    gTaskNameNumberPlus,
    (void (*)(void*, void*))NumberPlus_0,
    NumberPlus_1,
    (void (*)(void*))NumberPlus_2,
    (void (*)(void*))NumberPlus_3,
    0x2C,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnkEu_09F72D08[5] = { gUnkEu_094CF704, gUnkEu_094D72E4, gUnkEu_094DB664, gUnkEu_094D9FE4, gUnkEu_094D8964 };

void* gUnkEu_09F72D1C[5] = { gUnk_0908CAEC, gUnkEu_09170AA0, gUnkEu_09171B2C, gUnkEu_091715A8, gUnkEu_09171024 };

void** gUnk_09EEA1BC[5] = {
    gUnkEu_09F75FF4,
    gUnkEu_09F761AC,
    gUnkEu_09F7623C,
    gUnkEu_09F7620C,
    gUnkEu_09F761DC,
};

void* gUnkEu_09F72D44[5] = {
    gUnkEu_09178D40,
    gUnkEu_09179CEE,
    gUnkEu_0917CFE2,
    gUnkEu_0917BFA6,
    gUnkEu_0917AF3A,
};

void** gUnkEu_09F72D58[5] = {
    gUnkEu_09F762C4,
    gUnkEu_09F762E4,
    gUnkEu_09F76344,
    gUnkEu_09F76324,
    gUnkEu_09F76304,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
u16* gUnk_09EE78D4[7] = { gUnk_0815A066, gUnk_0815A0BA, gUnk_0815B1D2, gUnk_0815A078, gUnk_0815A0CC, gUnk_0815B1A8, gUnk_09037FAC };

u16* gUnk_09EE78F0[7] = { gUnk_0815A066, gUnk_0815A116, gUnk_0815A158, gUnk_0815A0F4, gUnk_0815A130, gUnk_0815A176, gUnk_09037FAC };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const void* gUnk_09EE790C[2] = { gUnk_08125E24, gUnk_0950F2B8 };

void* gUnk_09EE7914[3] = { gUnk_095112B8, gUnk_09511AB8, gUnk_095122B8 };

const char gTaskNameLevelUp[] __attribute__((section(".rodata_registration_name_gTaskDescLevelUp"), aligned(1))) = "Level_Up";

TaskDesc gTaskDescLevelUp = {
    gTaskNameLevelUp,
    (void (*)(void*, void*))Level_Up_0,
    Level_Up_1,
    (void (*)(void*))Level_Up_2,
    (void (*)(void*))Level_Up_3,
#ifdef VERSION_EU
    0x124,
#else
    0x7CC,
#endif
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
void* gUnk_09EE7938[6] = { gUnkEu_09163774, gUnkEu_0916377E, gUnkEu_09163788, gUnkEu_09163792, gUnkEu_0916379C, gUnkEu_091637A6 };

void* gUnkEu_09F72DB0[6] = { gUnkEu_0916F94C, gUnkEu_0916F956, gUnkEu_0916F960, gUnkEu_0916F96A, gUnkEu_0916F974, gUnkEu_0916F97E };

void* gUnkEu_09F72DC8[6] = { gUnkEu_0916FD84, gUnkEu_0916FD8E, gUnkEu_0916FD98, gUnkEu_0916FDA2, gUnkEu_0916FDAC, gUnkEu_0916FDB6 };

void* gUnkEu_09F72DE0[6] = { gUnkEu_091701BC, gUnkEu_091701C6, gUnkEu_091701D0, gUnkEu_091701DA, gUnkEu_091701E4, gUnkEu_091701EE };

void* gUnkEu_09F72DF8[6] = { gUnkEu_091705F4, gUnkEu_091705FE, gUnkEu_09170608, gUnkEu_09170612, gUnkEu_0917061C, gUnkEu_09170626 };

void** gUnkEu_09F72E10[5] = { gUnk_09EE7938, gUnkEu_09F72DB0, gUnkEu_09F72DF8, gUnkEu_09F72DE0, gUnkEu_09F72DC8 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#ifdef VERSION_EU
#elif defined(VERSION_JP)
void* gUnk_09EE7938[6] = { gUnkJp_09047EB0, gUnkJp_09047EBA, gUnkJp_09047EC4, gUnkJp_09047ECE, gUnkJp_09047ED8, gUnkJp_09047EE2 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
#ifdef VERSION_EU
#elif defined(VERSION_JP)
#else
void* gUnk_09EE7938[6] = { gUnkUs_0908C640, gUnkUs_0908C64A, gUnkUs_0908C654, gUnkUs_0908C65E, gUnkUs_0908C668, gUnkUs_0908C672 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const char gTaskNameLVUPEFFECT[] __attribute__((section(".rodata_registration_name_gTaskDescLVUPEFFECT"), aligned(1))) = "LVUP_EFFECT";

TaskDesc gTaskDescLVUPEFFECT = {
    gTaskNameLVUPEFFECT,
    (void (*)(void*, void*))LVUP_EFFECT_0,
    LVUP_EFFECT_1,
    (void (*)(void*))LVUP_EFFECT_2,
    (void (*)(void*))LVUP_EFFECT_3,
    0xAC,
};

const char gTaskNameLvupLogo[] __attribute__((section(".rodata_registration_name_gTaskDescLvupLogo"), aligned(1))) = "Lvup_Logo";

TaskDesc gTaskDescLvupLogo = {
    gTaskNameLvupLogo,
    (void (*)(void*, void*))Lvup_Logo_0,
    Lvup_Logo_1,
    (void (*)(void*))Lvup_Logo_2,
    (void (*)(void*))Lvup_Logo_3,
    0xAC,
};

const char gTaskNameEvMapObj[] __attribute__((section(".rodata_registration_name_gTaskDescEvMapObj"), aligned(1))) = "Ev_mapObj";

TaskDesc gTaskDescEvMapObj = {
    gTaskNameEvMapObj,
    (void (*)(void*, void*))Ev_mapObj_0,
    Ev_mapObj_1,
    (void (*)(void*))Ev_mapObj_2,
    (void (*)(void*))Ev_mapObj_3,
    0x5C,
};

void* gUnk_09EE7998[7] = { gUnk_0951F2B8, gUnk_0951FAB8, gUnk_095202B8, gUnk_095212B8, gUnk_09520AB8, gUnk_09521AB8, gUnk_095222B8 };

EventBgEffectDef* gUnk_09EE79B4[8] = {
    &gUnk_0903803C,
    &gUnk_09038078,
    &gUnk_090380B4,
    &gUnk_090380F8,
    &gUnk_0903813C,
    &gUnk_09038198,
    &gUnk_090381CC,
    NULL,
};

const char gTaskNameEVBGEFFECT[] __attribute__((section(".rodata_registration_name_gTaskDescEVBGEFFECT"), aligned(1))) = "EV_BG_EFFECT";

TaskDesc gTaskDescEVBGEFFECT = {
    gTaskNameEVBGEFFECT,
    (void (*)(void*, void*))EV_BG_EFFECT_0,
    EV_BG_EFFECT_1,
    (void (*)(void*))EV_BG_EFFECT_2,
    (void (*)(void*))EV_BG_EFFECT_3,
    0x18,
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE79EC[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090381F8,
    gCardHelpTextUs_09038260,
#elif defined(VERSION_EU)
    &gUnkEu_09F6C9B8,
    &gUnkEu_09F6C9CC,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE79F4[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090382DC,
    gCardHelpTextUs_0903835A,
    gCardHelpTextUs_090383C4,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900B6E8,
    gCardHelpTextJp_0900B734,
#elif defined(VERSION_EU)
    &gUnkEu_09F6C9E0,
    &gUnkEu_09F6C9F4,
    &gUnkEu_09F6CA08,
#endif
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE7A00[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038440,
    gCardHelpTextUs_0903848E,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CA1C,
    &gUnkEu_09F6CA30,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7A08[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090384DC,
    gCardHelpTextUs_0903857A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900B7B4,
    gCardHelpTextJp_0900B7F0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CA44,
    &gUnkEu_09F6CA58,
#endif
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE7A10[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090385CC,
    gCardHelpTextUs_09038646,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CA6C,
    &gUnkEu_09F6CA80,
#endif
};

CardHelpText* gUnk_09EE7A18[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038694,
    gCardHelpTextUs_090386F0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CA94,
    &gUnkEu_09F6CAA8,
#endif
};

CardHelpText* gUnk_09EE7A20[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038736,
    gCardHelpTextUs_090387A4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CABC,
    &gUnkEu_09F6CAD0,
#endif
};

CardHelpText* gUnk_09EE7A28[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903881C,
    gCardHelpTextUs_0903887A,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CAE4,
    &gUnkEu_09F6CAF8,
#endif
};

CardHelpText* gUnk_09EE7A30[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090388F2,
    gCardHelpTextUs_0903897C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CB0C,
    &gUnkEu_09F6CB20,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7A38[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090389D2,
    gCardHelpTextUs_09038A32,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900B9F0,
    gCardHelpTextJp_0900BA08,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CB34,
    &gUnkEu_09F6CB48,
#endif
};

CardHelpText* gUnk_09EE7A40[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038A4E,
    gCardHelpTextUs_09038AAA,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BA24,
    gCardHelpTextJp_0900BA3C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CB5C,
    &gUnkEu_09F6CB70,
#endif
};

CardHelpText* gUnk_09EE7A48[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038AD6,
    gCardHelpTextUs_09038B3E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BA58,
    gCardHelpTextJp_0900BA70,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CB84,
    &gUnkEu_09F6CB98,
#endif
};

CardHelpText* gUnk_09EE7A50[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038B66,
    gCardHelpTextUs_09038B90,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BA84,
    gCardHelpTextJp_0900BA9C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CBAC,
    &gUnkEu_09F6CBC0,
#endif
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE7A58[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038BAC,
    gCardHelpTextUs_09038C10,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CBD4,
    &gUnkEu_09F6CBE8,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7A60[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038C38,
    gCardHelpTextUs_09038C96,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BAAC,
    gCardHelpTextJp_0900BAC8,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CBFC,
    &gUnkEu_09F6CC10,
#endif
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE7A68[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038CB2,
    gCardHelpTextUs_09038D16,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CC24,
    &gUnkEu_09F6CC38,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7A70[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038D32,
    gCardHelpTextUs_09038D90,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BADC,
    gCardHelpTextJp_0900BAF4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CC4C,
    &gUnkEu_09F6CC60,
#endif
};

CardHelpText* gUnk_09EE7A78[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038DBA,
    gCardHelpTextUs_09038E16,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BB14,
    gCardHelpTextJp_0900BB2C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CC74,
    &gUnkEu_09F6CC88,
#endif
};

CardHelpText* gUnk_09EE7A80[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038E58,
    gCardHelpTextUs_09038EBA,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BB4C,
    gCardHelpTextJp_0900BB64,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CC9C,
    &gUnkEu_09F6CCB0,
#endif
};

CardHelpText* gUnk_09EE7A88[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038EF6,
    gCardHelpTextUs_09038F3C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BB84,
    gCardHelpTextJp_0900BBA0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CCC4,
    &gUnkEu_09F6CCD8,
#endif
};
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
CardHelpText* gUnk_09EE7A58[] = {
    gCardHelpTextJp_0900BBB8,
    gCardHelpTextJp_0900BBE4,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7A90[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09038F66,
    gCardHelpTextUs_09038FCA,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BBF8,
    gCardHelpTextJp_0900BC24,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CCEC,
    &gUnkEu_09F6CD00,
#endif
};

CardHelpText* gUnk_09EE7A98[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039006,
    gCardHelpTextUs_0903906E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BC44,
    gCardHelpTextJp_0900BC6C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CD14,
    &gUnkEu_09F6CD28,
#endif
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE7AA0[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039098,
    gCardHelpTextUs_09039110,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CD3C,
    &gUnkEu_09F6CD50,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7AA8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903913A,
    gCardHelpTextUs_090391BA,
    gCardHelpTextUs_090391DA,
    gCardHelpTextUs_0903926E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BD20,
    gCardHelpTextJp_0900BD4C,
    gCardHelpTextJp_0900BD5C,
    gCardHelpTextJp_0900BD90,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CD64,
    &gUnkEu_09F6CD78,
    &gUnkEu_09F6CD8C,
    &gUnkEu_09F6CDA0,
#endif
};

CardHelpText* gUnk_09EE7AB8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903913A,
    gCardHelpTextUs_090391BA,
    gCardHelpTextUs_090391DA,
    gCardHelpTextUs_0903926E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BD20,
    gCardHelpTextJp_0900BD4C,
    gCardHelpTextJp_0900BD5C,
    gCardHelpTextJp_0900BD90,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CD64,
    &gUnkEu_09F6CD78,
    &gUnkEu_09F6CD8C,
    &gUnkEu_09F6CDA0,
#endif
};

CardHelpText* gUnk_09EE7AC8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903929E,
    gCardHelpTextUs_09039334,
    gCardHelpTextUs_09039354,
    gCardHelpTextUs_090393EE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BDA8,
    gCardHelpTextJp_0900BDE0,
    gCardHelpTextJp_0900BDF4,
    gCardHelpTextJp_0900BE2C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CDB4,
    &gUnkEu_09F6CDC8,
    &gUnkEu_09F6CDDC,
    &gUnkEu_09F6CDF0,
#endif
};

CardHelpText* gUnk_09EE7AD8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903929E,
    gCardHelpTextUs_09039334,
    gCardHelpTextUs_09039354,
    gCardHelpTextUs_090393EE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BDA8,
    gCardHelpTextJp_0900BDE0,
    gCardHelpTextJp_0900BDF4,
    gCardHelpTextJp_0900BE2C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CDB4,
    &gUnkEu_09F6CDC8,
    &gUnkEu_09F6CDDC,
    &gUnkEu_09F6CDF0,
#endif
};

CardHelpText* gUnk_09EE7AE8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903941E,
    gCardHelpTextUs_09039490,
    gCardHelpTextUs_090394C8,
    gCardHelpTextUs_09039562,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BE4C,
    gCardHelpTextJp_0900BE7C,
    gCardHelpTextJp_0900BE90,
    gCardHelpTextJp_0900BEC4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CE04,
    &gUnkEu_09F6CE18,
    &gUnkEu_09F6CE2C,
    &gUnkEu_09F6CE40,
#endif
};

CardHelpText* gUnk_09EE7AF8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903941E,
    gCardHelpTextUs_09039490,
    gCardHelpTextUs_090394C8,
    gCardHelpTextUs_09039562,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BE4C,
    gCardHelpTextJp_0900BE7C,
    gCardHelpTextJp_0900BE90,
    gCardHelpTextJp_0900BEC4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CE04,
    &gUnkEu_09F6CE18,
    &gUnkEu_09F6CE2C,
    &gUnkEu_09F6CE40,
#endif
};

CardHelpText* gUnk_09EE7B08[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090395B6,
    gCardHelpTextUs_09039646,
    gCardHelpTextUs_09039666,
    gCardHelpTextUs_09039708,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BEE4,
    gCardHelpTextJp_0900BF14,
    gCardHelpTextJp_0900BF2C,
    gCardHelpTextJp_0900BF64,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CE54,
    &gUnkEu_09F6CE68,
    &gUnkEu_09F6CE7C,
    &gUnkEu_09F6CE90,
#endif
};

CardHelpText* gUnk_09EE7B18[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090395B6,
    gCardHelpTextUs_09039646,
    gCardHelpTextUs_09039666,
    gCardHelpTextUs_09039708,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BEE4,
    gCardHelpTextJp_0900BF14,
    gCardHelpTextJp_0900BF2C,
    gCardHelpTextJp_0900BF64,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CE54,
    &gUnkEu_09F6CE68,
    &gUnkEu_09F6CE7C,
    &gUnkEu_09F6CE90,
#endif
};
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
CardHelpText* gUnk_09EE7B30[] = {
    gCardHelpTextJp_0900BF88,
    gCardHelpTextJp_0900BF9C,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7B28[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090397BA,
    gCardHelpTextUs_09039842,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BFB0,
    gCardHelpTextJp_0900BFDC,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CECC,
    &gUnkEu_09F6CEE0,
#endif
};
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
#if defined(VERSION_US) || defined(VERSION_EU)
CardHelpText* gUnk_09EE7B30[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039738,
    gCardHelpTextUs_0903979A,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CEA4,
    &gUnkEu_09F6CEB8,
#endif
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7B38[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039872,
    gCardHelpTextUs_090398D4,
    gCardHelpTextUs_090398F4,
    gCardHelpTextUs_09039988,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BFFC,
    gCardHelpTextJp_0900C02C,
    gCardHelpTextJp_0900C03C,
    gCardHelpTextJp_0900C084,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CEF4,
    &gUnkEu_09F6CF08,
    &gUnkEu_09F6CF1C,
    &gUnkEu_09F6CF30,
#endif
};

CardHelpText* gUnk_09EE7B48[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039872,
    gCardHelpTextUs_090398D4,
    gCardHelpTextUs_090398F4,
    gCardHelpTextUs_09039988,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900BFFC,
    gCardHelpTextJp_0900C02C,
    gCardHelpTextJp_0900C03C,
    gCardHelpTextJp_0900C084,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CEF4,
    &gUnkEu_09F6CF08,
    &gUnkEu_09F6CF1C,
    &gUnkEu_09F6CF30,
#endif
};

CardHelpText* gUnk_09EE7B58[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090399B8,
    gCardHelpTextUs_09039A3A,
    gCardHelpTextUs_09039A5A,
    gCardHelpTextUs_09039AF8,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C09C,
    gCardHelpTextJp_0900C0CC,
    gCardHelpTextJp_0900C0DC,
    gCardHelpTextJp_0900C118,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CF44,
    &gUnkEu_09F6CF58,
    &gUnkEu_09F6CF6C,
    &gUnkEu_09F6CF80,
#endif
};

CardHelpText* gUnk_09EE7B68[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_090399B8,
    gCardHelpTextUs_09039A3A,
    gCardHelpTextUs_09039A5A,
    gCardHelpTextUs_09039AF8,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C09C,
    gCardHelpTextJp_0900C0CC,
    gCardHelpTextJp_0900C0DC,
    gCardHelpTextJp_0900C118,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CF44,
    &gUnkEu_09F6CF58,
    &gUnkEu_09F6CF6C,
    &gUnkEu_09F6CF80,
#endif
};

CardHelpText* gUnk_09EE7B78[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039B28,
    gCardHelpTextUs_09039B96,
    gCardHelpTextUs_09039BBA,
    gCardHelpTextUs_09039C30,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C130,
    gCardHelpTextJp_0900C174,
    gCardHelpTextJp_0900C188,
    gCardHelpTextJp_0900C1CC,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CF94,
    &gUnkEu_09F6CFA8,
    &gUnkEu_09F6CFBC,
    &gUnkEu_09F6CFD0,
#endif
};

CardHelpText* gUnk_09EE7B88[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039B28,
    gCardHelpTextUs_09039B96,
    gCardHelpTextUs_09039BBA,
    gCardHelpTextUs_09039C30,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C188,
    gCardHelpTextJp_0900C1CC,
    gCardHelpTextJp_0900C130,
    gCardHelpTextJp_0900C174,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CF94,
    &gUnkEu_09F6CFA8,
    &gUnkEu_09F6CFBC,
    &gUnkEu_09F6CFD0,
#endif
};

CardHelpText* gUnk_09EE7B98[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039C66,
    gCardHelpTextUs_09039CEE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C1EC,
    gCardHelpTextJp_0900C218,
#elif defined(VERSION_EU)
    &gUnkEu_09F6CFE4,
    &gUnkEu_09F6CFF8,
#endif
};

CardHelpText* gUnk_09EE7BA0[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039D0E,
    gCardHelpTextUs_09039D8E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C230,
    gCardHelpTextJp_0900C25C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D00C,
    &gUnkEu_09F6D020,
#endif
};

CardHelpText* gUnk_09EE7BA8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039DBE,
    gCardHelpTextUs_09039E1A,
    gCardHelpTextUs_09039E42,
    gCardHelpTextUs_09039ED6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C280,
    gCardHelpTextJp_0900C29C,
    gCardHelpTextJp_0900C2B0,
    gCardHelpTextJp_0900C2E0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D034,
    &gUnkEu_09F6D048,
    &gUnkEu_09F6D05C,
    &gUnkEu_09F6D070,
#endif
};

CardHelpText* gUnk_09EE7BB8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039DBE,
    gCardHelpTextUs_09039E1A,
    gCardHelpTextUs_09039E42,
    gCardHelpTextUs_09039ED6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C280,
    gCardHelpTextJp_0900C29C,
    gCardHelpTextJp_0900C2B0,
    gCardHelpTextJp_0900C2E0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D034,
    &gUnkEu_09F6D048,
    &gUnkEu_09F6D05C,
    &gUnkEu_09F6D070,
#endif
};

CardHelpText* gUnk_09EE7BC8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039F12,
    gCardHelpTextUs_09039F82,
    gCardHelpTextUs_09039F9E,
    gCardHelpTextUs_0903A012,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C300,
    gCardHelpTextJp_0900C33C,
    gCardHelpTextJp_0900C350,
    gCardHelpTextJp_0900C38C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D084,
    &gUnkEu_09F6D098,
    &gUnkEu_09F6D0AC,
    &gUnkEu_09F6D0C0,
#endif
};

CardHelpText* gUnk_09EE7BD8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_09039F12,
    gCardHelpTextUs_09039F82,
    gCardHelpTextUs_09039F9E,
    gCardHelpTextUs_0903A012,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C300,
    gCardHelpTextJp_0900C33C,
    gCardHelpTextJp_0900C350,
    gCardHelpTextJp_0900C38C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D084,
    &gUnkEu_09F6D098,
    &gUnkEu_09F6D0AC,
    &gUnkEu_09F6D0C0,
#endif
};

CardHelpText* gUnk_09EE7BE8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A03C,
    gCardHelpTextUs_0903A0A4,
    gCardHelpTextUs_0903A0C4,
    gCardHelpTextUs_0903A15C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C3AC,
    gCardHelpTextJp_0900C3DC,
    gCardHelpTextJp_0900C3F0,
    gCardHelpTextJp_0900C428,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D0D4,
    &gUnkEu_09F6D0E8,
    &gUnkEu_09F6D0FC,
    &gUnkEu_09F6D110,
#endif
};

CardHelpText* gUnk_09EE7BF8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A03C,
    gCardHelpTextUs_0903A0A4,
    gCardHelpTextUs_0903A0C4,
    gCardHelpTextUs_0903A15C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C3AC,
    gCardHelpTextJp_0900C3DC,
    gCardHelpTextJp_0900C3F0,
    gCardHelpTextJp_0900C428,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D0D4,
    &gUnkEu_09F6D0E8,
    &gUnkEu_09F6D0FC,
    &gUnkEu_09F6D110,
#endif
};

CardHelpText* gUnk_09EE7C08[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A18C,
    gCardHelpTextUs_0903A1FE,
    gCardHelpTextUs_0903A22E,
    gCardHelpTextUs_0903A2D0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C448,
    gCardHelpTextJp_0900C474,
    gCardHelpTextJp_0900C490,
    gCardHelpTextJp_0900C4C0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D124,
    &gUnkEu_09F6D138,
    &gUnkEu_09F6D14C,
    &gUnkEu_09F6D160,
#endif
};

CardHelpText* gUnk_09EE7C18[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A18C,
    gCardHelpTextUs_0903A1FE,
    gCardHelpTextUs_0903A22E,
    gCardHelpTextUs_0903A2D0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C448,
    gCardHelpTextJp_0900C474,
    gCardHelpTextJp_0900C490,
    gCardHelpTextJp_0900C4C0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D124,
    &gUnkEu_09F6D138,
    &gUnkEu_09F6D14C,
    &gUnkEu_09F6D160,
#endif
};

CardHelpText* gUnk_09EE7C28[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A318,
    gCardHelpTextUs_0903A39A,
    gCardHelpTextUs_0903A3CA,
    gCardHelpTextUs_0903A448,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C4EC,
    gCardHelpTextJp_0900C524,
    gCardHelpTextJp_0900C538,
    gCardHelpTextJp_0900C568,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D174,
    &gUnkEu_09F6D188,
    &gUnkEu_09F6D19C,
    &gUnkEu_09F6D1B0,
#endif
};

CardHelpText* gUnk_09EE7C38[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A318,
    gCardHelpTextUs_0903A39A,
    gCardHelpTextUs_0903A3CA,
    gCardHelpTextUs_0903A448,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C4EC,
    gCardHelpTextJp_0900C524,
    gCardHelpTextJp_0900C538,
    gCardHelpTextJp_0900C568,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D174,
    &gUnkEu_09F6D188,
    &gUnkEu_09F6D19C,
    &gUnkEu_09F6D1B0,
#endif
};
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
CardHelpText* gUnk_09EE7D54[] = {
    gCardHelpTextJp_0900D0D8,
    gCardHelpTextJp_0900D110,
    gCardHelpTextJp_0900D11C,
    gCardHelpTextJp_0900D158,
};

CardHelpText* gUnk_09EE7D44[] = {
    gCardHelpTextJp_0900D16C,
    gCardHelpTextJp_0900D174,
};

CardHelpText* gUnk_09EE7D64[] = {
    gCardHelpTextJp_0900D11C,
    gCardHelpTextJp_0900D158,
};

CardHelpText* gUnk_09EE7A68[] = {
    gCardHelpTextJp_0900BC8C,
    gCardHelpTextJp_0900BCC0,
};

CardHelpText* gUnk_09EE7AA0[] = {
    gCardHelpTextJp_0900BCD0,
    gCardHelpTextJp_0900BD08,
};

CardHelpText* gUnk_09EE79EC[] = {
    gCardHelpTextJp_0900B684,
    gCardHelpTextJp_0900B6B0,
};

CardHelpText* gUnk_09EE7A00[] = {
    gCardHelpTextJp_0900B76C,
    gCardHelpTextJp_0900B78C,
};

CardHelpText* gUnk_09EE7A10[] = {
    gCardHelpTextJp_0900B81C,
    gCardHelpTextJp_0900B83C,
};

CardHelpText* gUnk_09EE7A18[] = {
    gCardHelpTextJp_0900B864,
    gCardHelpTextJp_0900B8A0,
};

CardHelpText* gUnk_09EE7A20[] = {
    gCardHelpTextJp_0900B8C8,
    gCardHelpTextJp_0900B8F0,
};

CardHelpText* gUnk_09EE7A28[] = {
    gCardHelpTextJp_0900B928,
    gCardHelpTextJp_0900B950,
};

CardHelpText* gUnk_09EE7A30[] = {
    gCardHelpTextJp_0900B988,
    gCardHelpTextJp_0900B9C4,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7C48[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A490,
    gCardHelpTextUs_0903A4D0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C588,
    gCardHelpTextJp_0900C5B0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D1C4,
    &gUnkEu_09F6D1D8,
#endif
};

CardHelpText* gUnk_09EE7C50[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A4FA,
    gCardHelpTextUs_0903A562,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C5CC,
    gCardHelpTextJp_0900C600,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D1EC,
    &gUnkEu_09F6D200,
#endif
};

CardHelpText* gUnk_09EE7C58[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A592,
    gCardHelpTextUs_0903A5FC,
    gCardHelpTextUs_0903A652,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C61C,
    gCardHelpTextJp_0900C644,
    gCardHelpTextJp_0900C668,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D214,
    &gUnkEu_09F6D228,
    &gUnkEu_09F6D23C,
#endif
};

CardHelpText* gUnk_09EE7C64[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A692,
    gCardHelpTextUs_0903A700,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C68C,
    gCardHelpTextJp_0900C6C0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D250,
    &gUnkEu_09F6D264,
#endif
};
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
CardHelpText* gUnk_09EE7D74[] = {
    gCardHelpTextJp_0900C6E0,
    gCardHelpTextJp_0900C718,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7C6C[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A750,
    gCardHelpTextUs_0903A7B0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C728,
    gCardHelpTextJp_0900C75C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D278,
    &gUnkEu_09F6D28C,
#endif
};

CardHelpText* gUnk_09EE7C74[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A806,
    gCardHelpTextUs_0903A878,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C788,
    gCardHelpTextJp_0900C7B8,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D2A0,
    &gUnkEu_09F6D2B4,
#endif
};

CardHelpText* gUnk_09EE7C7C[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A8CE,
    gCardHelpTextUs_0903A95A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C7E0,
    gCardHelpTextJp_0900C82C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D2C8,
    &gUnkEu_09F6D2DC,
#endif
};

CardHelpText* gUnk_09EE7C84[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903A9B2,
    gCardHelpTextUs_0903AA08,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C858,
    gCardHelpTextJp_0900C880,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D2F0,
    &gUnkEu_09F6D304,
#endif
};

CardHelpText* gUnk_09EE7C8C[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AA5E,
    gCardHelpTextUs_0903AAB2,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C8AC,
    gCardHelpTextJp_0900C8D4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D318,
    &gUnkEu_09F6D32C,
#endif
};

CardHelpText* gUnk_09EE7C94[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AB10,
    gCardHelpTextUs_0903AB70,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C900,
    gCardHelpTextJp_0900C928,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D340,
    &gUnkEu_09F6D354,
#endif
};

CardHelpText* gUnk_09EE7C9C[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903ABCC,
    gCardHelpTextUs_0903AC32,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C954,
    gCardHelpTextJp_0900C988,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D368,
    &gUnkEu_09F6D37C,
#endif
};

CardHelpText* gUnk_09EE7CA4[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AC8E,
    gCardHelpTextUs_0903AD26,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900C9B4,
    gCardHelpTextJp_0900C9F0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D390,
    &gUnkEu_09F6D3A4,
#endif
};

CardHelpText* gUnk_09EE7CAC[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AD58,
    gCardHelpTextUs_0903ADD8,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CA0C,
    gCardHelpTextJp_0900CA48,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D3B8,
    &gUnkEu_09F6D3CC,
#endif
};

CardHelpText* gUnk_09EE7CB4[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AE2A,
    gCardHelpTextUs_0903AE60,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CA78,
    gCardHelpTextJp_0900CAA4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D3E0,
    &gUnkEu_09F6D3F4,
#endif
};
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
#if defined(VERSION_JP)
CardHelpText* gUnk_09EE7D7C[] = {
    gCardHelpTextJp_0900CAC4,
    gCardHelpTextJp_0900CAFC,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardHelpText* gUnk_09EE7CBC[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AEA2,
    gCardHelpTextUs_0903AF44,
    gCardHelpTextUs_0903AF98,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CB0C,
    gCardHelpTextJp_0900CB48,
    gCardHelpTextJp_0900CB6C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D408,
    &gUnkEu_09F6D41C,
    &gUnkEu_09F6D430,
#endif
};

CardHelpText* gUnk_09EE7CC8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903AFDE,
    gCardHelpTextUs_0903B02C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CB90,
    gCardHelpTextJp_0900CBAC,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D444,
    &gUnkEu_09F6D458,
#endif
};

CardHelpText* gUnk_09EE7CD0[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B058,
    gCardHelpTextUs_0903B0E6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CBCC,
    gCardHelpTextJp_0900CBF8,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D46C,
    &gUnkEu_09F6D480,
#endif
};

CardHelpText* gUnk_09EE7CD8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B128,
    gCardHelpTextUs_0903B192,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CC20,
    gCardHelpTextJp_0900CC50,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D494,
    &gUnkEu_09F6D4A8,
#endif
};

CardHelpText* gUnk_09EE7CE0[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B1EA,
    gCardHelpTextUs_0903B260,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CC78,
    gCardHelpTextJp_0900CCA4,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D4BC,
    &gUnkEu_09F6D4D0,
#endif
};

CardHelpText* gUnk_09EE7CE8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B2B8,
    gCardHelpTextUs_0903B31A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CCCC,
    gCardHelpTextJp_0900CCFC,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D4E4,
    &gUnkEu_09F6D4F8,
#endif
};

CardHelpText* gUnk_09EE7CF0[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B35C,
    gCardHelpTextUs_0903B3C6,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CD20,
    gCardHelpTextJp_0900CD50,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D50C,
    &gUnkEu_09F6D520,
#endif
};

CardHelpText* gUnk_09EE7CF8[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B404,
    gCardHelpTextUs_0903B476,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CD70,
    gCardHelpTextJp_0900CDA0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D534,
    &gUnkEu_09F6D548,
#endif
};

CardHelpText* gUnk_09EE7D00[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B4BC,
    gCardHelpTextUs_0903B522,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CDC0,
    gCardHelpTextJp_0900CDFC,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D55C,
    &gUnkEu_09F6D570,
#endif
};

CardHelpText* gUnk_09EE7D08[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B552,
    gCardHelpTextUs_0903B5DE,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CE18,
    gCardHelpTextJp_0900CE54,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D584,
    &gUnkEu_09F6D598,
#endif
};

CardHelpText* gUnk_09EE7D10[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B622,
    gCardHelpTextUs_0903B6B0,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CE74,
    gCardHelpTextJp_0900CEB0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D5AC,
    &gUnkEu_09F6D5C0,
#endif
};

CardHelpText* gUnk_09EE7D18[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B6F6,
    gCardHelpTextUs_0903B76E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CED0,
    gCardHelpTextJp_0900CF0C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D5D4,
    &gUnkEu_09F6D5E8,
#endif
};

CardHelpText* gUnk_09EE7D20[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B7B4,
    gCardHelpTextUs_0903B842,
    gCardHelpTextUs_0903B89E,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CF2C,
    gCardHelpTextJp_0900CF68,
    gCardHelpTextJp_0900CF90,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D5FC,
    &gUnkEu_09F6D610,
    &gUnkEu_09F6D624,
#endif
};

CardHelpText* gUnk_09EE7D2C[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B8DA,
    gCardHelpTextUs_0903B976,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900CFB4,
    gCardHelpTextJp_0900CFE8,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D638,
    &gUnkEu_09F6D64C,
#endif
};

CardHelpText* gUnk_09EE7D34[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903B9C4,
    gCardHelpTextUs_0903BA4A,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900D014,
    gCardHelpTextJp_0900D04C,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D660,
    &gUnkEu_09F6D674,
#endif
};

CardHelpText* gUnk_09EE7D3C[] = {
#if defined(VERSION_US)
    gCardHelpTextUs_0903BA9A,
    gCardHelpTextUs_0903BB2C,
#elif defined(VERSION_JP)
    gCardHelpTextJp_0900D078,
    gCardHelpTextJp_0900D0B0,
#elif defined(VERSION_EU)
    &gUnkEu_09F6D688,
    &gUnkEu_09F6D69C,
#endif
};
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
#if defined(VERSION_US)
CardHelpText* gUnk_09EE7D44[] = {
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
};

CardHelpText* gUnk_09EE7D54[] = {
    gCardHelpTextUs_0903BB76,
    gCardHelpTextUs_0903BBF8,
    gCardHelpTextUs_0903BC24,
    gCardHelpTextUs_0903BCB8,
};

CardHelpText* gUnk_09EE7D64[] = {
    gCardHelpTextUs_0903BB76,
    gCardHelpTextUs_0903BBF8,
    gCardHelpTextUs_0903BC24,
    gCardHelpTextUs_0903BCB8,
};

CardHelpText* gUnk_09EE7D74[] = {
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
};

CardHelpText* gUnk_09EE7D7C[] = {
    gCardHelpTextUs_0903BCFA,
    gCardHelpTextUs_0903BCFA,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
#if defined(VERSION_EU)
CardHelpText* gUnk_09EE7D54[] = {
    &gUnkEu_09F6D6B0,
    &gUnkEu_09F6D6C4,
    &gUnkEu_09F6D6D8,
    &gUnkEu_09F6D6EC,
};

CardHelpText* gUnk_09EE7D64[] = {
    &gUnkEu_09F6D6B0,
    &gUnkEu_09F6D6C4,
    &gUnkEu_09F6D6D8,
    &gUnkEu_09F6D6EC,
};
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
const CardHelpDef* gUnk_09EE7D84[] = {
    &gUnk_0903BD0C,
    &gUnk_0903BD14,
    &gUnk_0903BD1C,
    &gUnk_0903BD24,
    &gUnk_0903BD2C,
    &gUnk_0903BD34,
    &gUnk_0903BD3C,
    &gUnk_0903BD44,
    &gUnk_0903BD4C,
    &gUnk_0903BD54,
    &gUnk_0903BD5C,
    &gUnk_0903BD64,
    &gUnk_0903BD6C,
    &gUnk_0903BD74,
    &gUnk_0903BD84,
    &gUnk_0903BD7C,
    &gUnk_0903BD8C,
    &gUnk_0903BD94,
    &gUnk_0903BD9C,
    &gUnk_0903BDA4,
    &gUnk_0903BDAC,
    &gUnk_0903BDB4,
    &gUnk_0903BDBC,
    &gUnk_0903BDC4,
    &gUnk_0903BDCC,
    &gUnk_0903BDD4,
    &gUnk_0903BDDC,
    &gUnk_0903BDE4,
    &gUnk_0903BDEC,
    &gUnk_0903BDF4,
    &gUnk_0903BDFC,
    &gUnk_0903BE04,
    &gUnk_0903BE0C,
    &gUnk_0903BE14,
    &gUnk_0903BE1C,
    &gUnk_0903BE24,
    &gUnk_0903BE2C,
    &gUnk_0903BE34,
    &gUnk_0903BE3C,
    &gUnk_0903BE44,
    &gUnk_0903BE4C,
    &gUnk_0903BE54,
    &gUnk_0903BE5C,
    &gUnk_0903BE64,
    &gUnk_0903BE6C,
    &gUnk_0903BE74,
    &gUnk_0903BE7C,
    &gUnk_0903BE84,
    &gUnk_0903BE8C,
    &gUnk_0903BE94,
    &gUnk_0903BE9C,
    &gUnk_0903BEA4,
    &gUnk_0903BEAC,
    &gUnk_0903BEB4,
    &gUnk_0903BEBC,
    &gUnk_0903BEC4,
    &gUnk_0903BECC,
#if defined(VERSION_US) || defined(VERSION_JP)
    &gUnk_0903BED4,
#elif defined(VERSION_EU)
    0,
#endif
    &gUnk_0903BEDC,
    &gUnk_0903BEE4,
    &gUnk_0903BEEC,
    &gUnk_0903BEF4,
    &gUnk_0903BEFC,
    &gUnk_0903BF04,
    &gUnk_0903BF0C,
    &gUnk_0903BF14,
    &gUnk_0903BF1C,
    &gUnk_0903BF24,
#if defined(VERSION_US) || defined(VERSION_JP)
    &gUnk_0903BF2C,
#elif defined(VERSION_EU)
    0,
#endif
    &gUnk_0903BF34,
    &gUnk_0903BF3C,
    &gUnk_0903BF44,
    &gUnk_0903BF4C,
    &gUnk_0903BF54,
    &gUnk_0903BF5C,
    &gUnk_0903BF64,
    &gUnk_0903BF6C,
    &gUnk_0903BF74,
    &gUnk_0903BF7C,
    &gUnk_0903BF84,
    &gUnk_0903BF8C,
    &gUnk_0903BF94,
    &gUnk_0903BF9C,
    &gUnk_0903BFA4,
    &gUnk_0903BFAC,
#if defined(VERSION_US) || defined(VERSION_JP)
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
#endif
};

const char gTaskName_09EE7F30[] __attribute__((section(".rodata_registration_name_gUnk_09EE7F30"), aligned(1))) = "StockInfo";

TaskDesc gUnk_09EE7F30 = {
    gTaskName_09EE7F30,
    (void (*)(void*, void*))StockInfo_0,
    StockInfo_1,
    (void (*)(void*))StockInfo_2,
    (void (*)(void*))StockInfo_3,
    0x2C,
};

const char gTaskName_09EE7F48[] __attribute__((section(".rodata_registration_name_gUnk_09EE7F48"), aligned(1))) = "Lvup msg";

TaskDesc gUnk_09EE7F48 = {
    gTaskName_09EE7F48,
    (void (*)(void*, void*))func_080A23A0,
    func_080A25B8,
    (void (*)(void*))func_080A2678,
    (void (*)(void*))func_080A27EC,
#ifdef VERSION_JP
    0x218,
#else
    0x2B8,
#endif
};

const char gTaskName_09EE7F60[] __attribute__((section(".rodata_registration_name_gUnk_09EE7F60"), aligned(1))) = "Deck Equip";

TaskDesc gUnk_09EE7F60 = {
    gTaskName_09EE7F60,
    (void (*)(void*, void*))func_080A2844,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

const char gTaskName_09EE7F78[] __attribute__((section(".rodata_registration_name_gUnk_09EE7F78"), aligned(1))) = "Deck_Yes_No";

TaskDesc gUnk_09EE7F78 = {
    gTaskName_09EE7F78,
    (void (*)(void*, void*))Deck_Yes_No_0,
    func_080A30C0,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

const char gTaskName_09EE7F90[] __attribute__((section(".rodata_registration_name_gUnk_09EE7F90"), aligned(1))) = "Deck_Clear";

TaskDesc gUnk_09EE7F90 = {
    gTaskName_09EE7F90,
    (void (*)(void*, void*))Deck_Clear_0,
    func_080A30C0,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

const char gTaskName_09EE7FA8[] __attribute__((section(".rodata_registration_name_gUnk_09EE7FA8"), aligned(1))) = "Deck Error";

TaskDesc gUnk_09EE7FA8 = {
    gTaskName_09EE7FA8,
    (void (*)(void*, void*))func_080A2980,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

TaskDesc gUnk_09EE7FC0 = {
    gTaskName_09EE7FA8,
    (void (*)(void*, void*))func_080A2A80,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

TaskDesc gUnk_09EE7FD8 = {
    gTaskName_09EE7FA8,
    (void (*)(void*, void*))func_080A2BA4,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

TaskDesc gUnk_09EE7FF0 = {
    gTaskName_09EE7FA8,
    (void (*)(void*, void*))func_080A2CC4,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
u8* gUnkEu_09F73464[5] = { gUnkEu_090D1DA5, gUnkEu_090D1DA5, gUnkEu_090D1DA5, gUnkEu_090D1DA5, gUnkEu_090D1DA5 };
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
CardMessageDef gUnk_09EE8008[] = {
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660F4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0901048C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F5B8,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66108,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010454,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F642,
#endif
        0,
        0,
    },
    {
        1, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6611C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010410,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F6A2,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66130,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090103D0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F714,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66144,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010394,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F778,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66158,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010348,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F7F0,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6616C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010314,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F87C,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66180,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090102E0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F8E4,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66194,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090102A0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F94C,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661A8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010250,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F9BC,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661BC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010218,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FA2A,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661D0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090101DC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FAB2,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661E4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090101A0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FB04,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661F8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010184,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FB76,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6620C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010154,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FBAC,
#endif
        0,
        0,
    },
    {
        1, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66220,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010124,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FBFA,
#endif
        0,
        0,
    },
    {
        1, 3, 2, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66234,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090100E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FC6A,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66248,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090100A4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FCDE,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6625C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010078,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FD46,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66270,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0901003C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FDAA,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66284,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010000,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FE34,
#endif
        0,
        0,
    },
    {
        1, 3, 2, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66298,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FFD0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FEA2,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662AC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FF8C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FEF8,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662C0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FF54,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FF4E,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662D4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FF08,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FFC4,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662E8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FED0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040042,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662FC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FEA0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090400DC,
#endif
        0,
        0,
    },
    {
        2, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66310,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FE58,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040170,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66324,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FE14,
#elif defined(VERSION_US)
        gCardMessageTextUs_090401E4,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66338,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FDE8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904026E,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6634C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FDC0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090402D0,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66360,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FD8C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040328,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66374,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FD50,
#elif defined(VERSION_US)
        gCardMessageTextUs_090403A0,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66388,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FD18,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904041C,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6639C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FCD0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090404AA,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663B0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FC80,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040552,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663C4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FC38,
#elif defined(VERSION_US)
        gCardMessageTextUs_090405D8,
#endif
        0,
        0,
    },
    {
        2, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663D8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FC00,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040662,
#endif
        0,
        0,
    },
    {
        2, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663EC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FBCC,
#elif defined(VERSION_US)
        gCardMessageTextUs_090406E4,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66400,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FB90,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040758,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66414,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FB5C,
#elif defined(VERSION_US)
        gCardMessageTextUs_090407B2,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66428,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FB20,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904083C,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6643C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FAE8,
#elif defined(VERSION_US)
        gCardMessageTextUs_090408CC,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66450,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA90,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040932,
#endif
        0,
        0,
    },
    {
        2, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66464,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA60,
#elif defined(VERSION_US)
        gCardMessageTextUs_090409E6,
#endif
        0,
        0,
    },
    {
        2, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66478,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA2C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040A5C,
#endif
        0,
        0,
    },
    {
        2, 3, 2, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6648C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA04,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040AEE,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664A0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F9C4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040B46,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664B4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F998,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040BA8,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664C8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F968,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040C0C,
#endif
        0,
        0,
    },
    {
        60, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664DC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F934,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040C98,
#endif
        0,
        0,
    },
    {
        60, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664F0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F8F4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040D0E,
#endif
        0,
        0,
    },
    {
        27, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66504,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F8D0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040D90,
#endif
        0,
        0,
    },
    {
        36, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F69614,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F8B0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0900868C,
#endif
        1,
        0,
    },
    {
        47, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68368,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F880,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C10C,
#endif
        0,
        0,
    },
    {
        48, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68354,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F844,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C186,
#endif
        0,
        0,
    },
    {
        50, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68340,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F820,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C0D4,
#endif
        0,
        0,
    },
    {
        50, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6832C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F7E0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C060,
#endif
        0,
        0,
    },
    {
        51, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F683A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F798,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C20C,
#endif
        0,
        0,
    },
    {
        49, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68390,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F75C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C2F4,
#endif
        0,
        0,
    },
    {
        49, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6837C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F720,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C272,
#endif
        0,
        0,
    },
    {
        61, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6C97C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F6E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040DDA,
#endif
        0,
        0,
    },
    {
        61, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6C990,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F6B4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040E4C,
#endif
        0,
        0,
    },
    {
        61, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6C9A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F668,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040ED6,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660CC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F638,
#elif defined(VERSION_US)
        gCardMessageTextUs_090411BA,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F608,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041224,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660B8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F5E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041176,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F5C8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041E66,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F5A0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041E66,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66068,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F588,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C03C,
#endif
        3,
        0,
    },
    {
        3, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E44,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F554,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C37E,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E58,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F50C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C410,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E6C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F4D4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C656,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E80,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F4AC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C6F0,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E94,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F498,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C76E,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EA8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F424,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C79A,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EBC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F40C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C86C,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63ED0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F3A8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C898,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EE4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F2E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C97C,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EF8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F2A8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CAD0,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F0C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F274,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CB7C,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F20,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F40C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CBE4,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F34,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F234,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CC10,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F48,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F1FC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CC80,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F5C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F1B4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CCF2,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F70,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F180,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CD96,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F84,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F134,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CE0C,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F98,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F0EC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CEC4,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FAC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F010,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CF58,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FC0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EF60,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D0BE,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FD4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EF2C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D1FA,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FE8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EEE4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D294,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FFC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EE28,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D32E,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64010,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EE00,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D47A,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64024,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ED7C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D4C2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64164,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ED44,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E7EC,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64178,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ED0C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E854,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6418C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ECD4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E8C4,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641A0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EC94,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E91C,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641B4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EC58,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E9C8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641C8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EC14,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EA78,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641DC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EBD8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EB28,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641F0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EB18,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EB8E,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64204,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EAA0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903ED16,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64204,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EA28,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903ED16,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64218,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E980,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EE14,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6422C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E914,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EF68,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64240,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E8E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F02C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64254,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E854,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F098,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64268,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E824,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F180,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6427C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E7F0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F1E2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64290,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E7C4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F25A,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F642A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E768,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F2D0,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F642B8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E710,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F410,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64038,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E648,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D5E8,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6404C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E5E4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D774,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64060,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E528,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D872,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64074,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E4F4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DA40,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64088,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E450,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DA92,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6409C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E3E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DC44,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640B0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E398,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DD36,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640C4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E364,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DDCA,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640D8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E2EC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DE28,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640EC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E240,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DF44,
#endif
        0,
        0,
    },
    {
        62, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64100,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E210,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E0CA,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        31, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64114,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E144,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E142,
#endif
        0,
        0,
    },
    {
        62, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64128,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E0F8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E2C8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        31, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6413C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E00C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E370,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64150,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DF14,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E5D4,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F682F0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DED0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040F4E,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68304,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DE50,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040FE2,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68318,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DE04,
#elif defined(VERSION_US)
        gCardMessageTextUs_090410E8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6459C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DD60,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C4C2,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66518,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DD34,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041492,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6652C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DCEC,
#elif defined(VERSION_US)
        gCardMessageTextUs_090414BE,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66540,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DCC8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041522,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66554,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DCA4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041548,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66568,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DC74,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041568,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6657C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DC20,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041594,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66590,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DBFC,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041606,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DBD0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904162C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665B8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DBA4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904165C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665CC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DB78,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041690,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DB4C,
#elif defined(VERSION_US)
        gCardMessageTextUs_090416C0,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665F4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DB1C,
#elif defined(VERSION_US)
        gCardMessageTextUs_090416EA,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66608,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DAF0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041718,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6661C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DAC4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904174A,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66630,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA94,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041774,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66644,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA64,
#elif defined(VERSION_US)
        gCardMessageTextUs_090417A4,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66658,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA40,
#elif defined(VERSION_US)
        gCardMessageTextUs_090417DA,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6666C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA14,
#elif defined(VERSION_US)
        gCardMessageTextUs_090417FC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66680,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D9E4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041830,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66694,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D9C0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904185E,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666A8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D99C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041886,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666BC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D974,
#elif defined(VERSION_US)
        gCardMessageTextUs_090418AC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666D0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D948,
#elif defined(VERSION_US)
        gCardMessageTextUs_090418DC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666E4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D91C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904190C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666F8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D8F8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904193C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6670C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D8CC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904195C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66798,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D8B0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090419E2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66784,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D88C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041A08,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667C0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D870,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041A38,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667E8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D854,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041A5C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667FC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D834,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041AE2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66810,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D810,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041CAC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66824,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D7DC,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041B10,
#endif
        1,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66838,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D7C4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041B6C,
#endif
        1,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F642CC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D728,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F492,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66748,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D700,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041BA0,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6675C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D6D8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041BDC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66770,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D6B4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041C14,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6684C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D68C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041C46,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667D4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D670,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041C7C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66734,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D650,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041D06,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66720,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D650,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041CD6,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667AC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D610,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041D38,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66018,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D5E0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041D98,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F697E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D560,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904128A,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D500,
#elif defined(VERSION_US)
        gCardMessageTextUs_090413BE,
#endif
        0,
        0,
    },
#ifndef VERSION_EU
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_JP)
        gCardMessageTextJp_0900D4C0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041DE2,
#endif
        0,
        0,
    },
#endif
};

const char gTaskName_09EE8E18[] __attribute__((section(".rodata_registration_name_gUnk_09EE8E18"), aligned(1))) = "msgwin";

TaskDesc gUnk_09EE8E18 = {
    gTaskName_09EE8E18,
    (void (*)(void*, void*))func_080A33C4,
    func_080A3640,
    (void (*)(void*))func_080A3848,
    (void (*)(void*))func_080A3A04,
    0x150,
};

#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif

#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU
#ifndef VERSION_EU

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif

#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU
#ifdef VERSION_EU

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
#endif

#endif
