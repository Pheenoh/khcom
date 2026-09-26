#include "macros.h"
#include "card_localized_data.h"
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
#include "sprites_btl.h"
#include "prize_card.h"
#include "sprites_worldselect.h"
#include "sprites_card_pictures.h"
#include "sprites_card.h"
#include "gba/io_reg.h"
#include "card_ids.h"

extern UnkStruct_09EE752C gUnk_09EE752C[7];
#ifdef VERSION_EU
extern void* gUnkEu_09F72A3C[5];
extern void* gUnkEu_09F72A50[5];
extern void* gUnkEu_09F72A64[5];
#endif
u16 func_08093B08(u16 a);
u16 func_08096C38(const UnkStruct_08096C38* tbl, u16 n);
u16 func_08096CCC(void);
void CreateCardNameDisplay(void* a, void* b);
u16 func_08096D0C(u16 a, s32 b);
u16 func_08096D48(u16 a, s32 b);
s32 func_08097A80(u8* work);
s32 func_08097DE4(u8* work);
u8 func_0808510C(u16 id);
s32 AddMapCard(u16 a);
u16 func_08093B08(u16 a);
u16 func_08093B38(void);
u16 func_08093B58(void);
void* GetRoomName(u16 a);
u8 HasMapCard(u16 a);

const u16 gUnk_090359FC[10] = { 10, 5, 5, 15, 15, 15, 15, 10, 5, 5 };

const UnkStruct_08096C38_Item gUnk_09035A10[1] = {
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035A14[4] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035A24[2] = {
    { gUnk_09035A10, 1, 30 },
    { gUnk_09035A14, 4, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035A34[2] = {
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035A3C[7] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035A58[8] = {
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035A78[3] = {
    { gUnk_09035A34, 2, 40 },
    { gUnk_09035A3C, 7, 85 },
    { gUnk_09035A58, 8, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035A90[2] = {
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035A98[7] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035AB4[8] = {
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035AD4[3] = {
    { gUnk_09035A90, 2, 40 },
    { gUnk_09035A98, 7, 85 },
    { gUnk_09035AB4, 8, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035AEC[2] = {
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035AF4[7] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035B10[7] = {
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035B2C[3] = {
    { gUnk_09035AEC, 2, 40 },
    { gUnk_09035AF4, 7, 85 },
    { gUnk_09035B10, 7, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035B44[2] = {
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035B4C[7] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035B68[8] = {
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035B88[3] = {
    { gUnk_09035B44, 2, 40 },
    { gUnk_09035B4C, 7, 85 },
    { gUnk_09035B68, 8, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035BA0[2] = {
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035BA8[7] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035BC4[8] = {
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035BE4[3] = {
    { gUnk_09035BA0, 2, 40 },
    { gUnk_09035BA8, 7, 85 },
    { gUnk_09035BC4, 8, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035BFC[1] = {
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035C00[5] = {
    { CARD_ID(CARD_FIRE, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_BLIZZARD, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035C14[9] = {
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035C38[3] = {
    { gUnk_09035BFC, 1, 20 },
    { gUnk_09035C00, 5, 80 },
    { gUnk_09035C14, 9, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035C50[1] = {
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035C54[5] = {
    { CARD_ID(CARD_FIRE, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_BLIZZARD, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035C68[9] = {
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035C8C[3] = {
    { gUnk_09035C50, 1, 20 },
    { gUnk_09035C54, 5, 80 },
    { gUnk_09035C68, 9, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035CA4[1] = {
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035CA8[5] = {
    { CARD_ID(CARD_FIRE, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_BLIZZARD, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035CBC[9] = {
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035CE0[3] = {
    { gUnk_09035CA4, 1, 20 },
    { gUnk_09035CA8, 5, 80 },
    { gUnk_09035CBC, 9, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035CF8[1] = {
    { CARD_ID(CARD_CURE, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035CFC[6] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035D14[8] = {
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_LADY_LUCK, 0), 0 },
    { CARD_ID(CARD_LIONHEART, 0), 0 },
    { CARD_ID(CARD_DIVINE_ROSE, 0), 0 },
    { CARD_ID(CARD_OATHKEEPER, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035D34[3] = {
    { gUnk_09035CF8, 1, 20 },
    { gUnk_09035CFC, 6, 80 },
    { gUnk_09035D14, 8, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035D4C[1] = {
    { CARD_ID(CARD_CURE, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035D50[4] = {
    { CARD_ID(CARD_FIRE, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_BLIZZARD, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035D60[5] = {
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_SPELLBINDER, 0), 0 },
    { CARD_ID(CARD_METAL_CHOCOBO, 0), 0 },
    { CARD_ID(CARD_OLYMPIA, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035D74[3] = {
    { gUnk_09035D4C, 1, 30 },
    { gUnk_09035D50, 4, 80 },
    { gUnk_09035D60, 5, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035D8C[9] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_FIRE, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_ULTIMA_WEAPON, 0), 0 },
    { CARD_ID(CARD_BLIZZARD, 0), 0 },
};

const UnkStruct_08096C38_Item gUnk_09035DB0[3] = {
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_GRAVITY, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035DBC[2] = {
    { gUnk_09035D8C, 9, 85 },
    { gUnk_09035DB0, 3, 100 },
};

const UnkStruct_09035DCC gUnk_09035DCC[14] = {
    { gUnk_09035A24, 2 },
    { gUnk_09035A78, 3 },
    { gUnk_09035C38, 3 },
    { gUnk_09035B88, 3 },
    { gUnk_09035BE4, 3 },
    { gUnk_09035B2C, 3 },
    { gUnk_09035AD4, 3 },
    { gUnk_09035C8C, 3 },
    { gUnk_09035CE0, 3 },
    { gUnk_09035D74, 3 },
    { gUnk_09035A24, 2 },
    { gUnk_09035D34, 3 },
    { gUnk_09035DBC, 2 },
    { gUnk_09035DBC, 2 },
};

const u16 gUnk_09035E3C[10] = { 10, 5, 5, 15, 15, 15, 15, 10, 5, 5 };

const UnkStruct_08096C38_Item gUnk_09035E50[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035E7C[1] = {
    { gUnk_09035E50, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035E84[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035EB0[1] = {
    { gUnk_09035E84, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035EB8[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035EE4[1] = {
    { gUnk_09035EB8, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035EEC[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035F18[1] = {
    { gUnk_09035EEC, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035F20[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035F4C[1] = {
    { gUnk_09035F20, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035F54[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035F80[1] = {
    { gUnk_09035F54, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035F88[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035FB4[1] = {
    { gUnk_09035F88, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09035FBC[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09035FE8[1] = {
    { gUnk_09035FBC, 11, 100 },
};

#ifdef VERSION_EU
const UnkStruct_08096C38_Item gUnk_09035FF0[9] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};
#else
const UnkStruct_08096C38_Item gUnk_09035FF0[10] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};
#endif

#ifdef VERSION_EU
const UnkStruct_08096C38 gUnk_09036018[1] = {
    { gUnk_09035FF0, 9, 100 },
};
#else
const UnkStruct_08096C38 gUnk_09036018[1] = {
    { gUnk_09035FF0, 10, 100 },
};
#endif

const UnkStruct_08096C38_Item gUnk_09036020[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_0903604C[1] = {
    { gUnk_09036020, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09036054[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_09036080[1] = {
    { gUnk_09036054, 11, 100 },
};

const UnkStruct_08096C38_Item gUnk_09036088[11] = {
    { CARD_ID(CARD_THREE_WISHES, 0), 0 },
    { CARD_ID(CARD_KINGDOM_KEY, 0), 0 },
    { CARD_ID(CARD_WISHING_STAR, 0), 0 },
    { CARD_ID(CARD_FAIRY_HARP, 0), 0 },
    { CARD_ID(CARD_THUNDER, 0), 0 },
    { CARD_ID(CARD_CRABCLAW, 0), 0 },
    { CARD_ID(CARD_PUMPKINHEAD, 0), 0 },
    { CARD_ID(CARD_CURE, 0), 0 },
    { CARD_ID(CARD_DIAMOND_DUST, 0), 0 },
    { CARD_ID(CARD_ONE_WINGED_ANGEL, 0), 0 },
    { CARD_ID(CARD_OBLIVION, 0), 0 },
};

const UnkStruct_08096C38 gUnk_090360B4[1] = {
    { gUnk_09036088, 11, 100 },
};

const UnkStruct_09035DCC gUnk_090360BC[14] = {
    { gUnk_09035E7C, 1 },
    { gUnk_09035EB0, 1 },
    { gUnk_09035FB4, 1 },
    { gUnk_09035F4C, 1 },
    { gUnk_09035F80, 1 },
    { gUnk_09035F18, 1 },
    { gUnk_09035EE4, 1 },
    { gUnk_09035FE8, 1 },
    { gUnk_09036018, 1 },
    { gUnk_09036080, 1 },
    { gUnk_09035E7C, 1 },
    { gUnk_0903604C, 1 },
    { gUnk_090360B4, 1 },
    { gUnk_090360B4, 1 },
};

const u16 gUnk_0903612C[16] = { 0, 0, 8, 0, 0, 0, 0, 8, 8, 12, 0, 12, 16, 16, 16, 0 };

void func_08096714(PrizeCardInitWork* w, PrizeCardArgs* args) {
    w->unk_14 = 0;
    w->args = *args;
    TaskPoolInit(w, 1);
}

s32 PrizeCardInit_1(PrizeCardInitWork* w) {
    s32 args[9];
    s32 v;

    if (w->unk_14 == 0) {
        if ((gGameState.progression.unk_82 & 0x20) == 0) {
            *(PrizeCardArgs*)args = w->args;
            args[8] = 2;
            func_0809797C(w, args);
            gGameState.progression.unk_82 |= 0x20;
        } else if ((s8)gGameState.floor == 0) {
            if (func_08093B58() == 0) {
                *(PrizeCardArgs*)args = w->args;
                args[8] = func_08096D0C(gGameState.world, 1);

                if (args[8] != 0xFFFF) {
                    func_0809797C(w, args);
                } else {
                    return 0;
                }
            } else {
                *(PrizeCardArgs*)args = w->args;
                args[8] = func_08096D48(gGameState.world, 1);

                if (args[8] != 0xFFFF) {
                    func_0809797C(w, args);
                } else {
                    return 0;
                }
            }
        } else {
            v = gBtlWork->unk_10C;

            if (v >= 125 && v <= 127) {
                if ((gGameState.flags & 8) == 0) {
                    if (GetRandom() % 100 < 20) {
                        *(PrizeCardArgs*)args = w->args;
#ifdef VERSION_EU
                        if (func_08093B38() <= 98) {
                            args[8] = CARD_ID(CARD_GRAVITY, GetRandom() % 10);
                        } else {
                            args[8] = 0xFFFF;
                        }
#else
                        args[8] = CARD_ID(CARD_GRAVITY, GetRandom() % 10);
#endif
                    } else {
                        *(PrizeCardArgs*)args = w->args;
                        args[8] = func_08096D48(gGameState.world, 1);
                    }

                    if (args[8] != 0xFFFF) {
                        func_0809797C(w, args);
                    } else {
                        return 0;
                    }
                } else {
                    *(PrizeCardArgs*)args = w->args;
                    args[8] = func_08096D48(gGameState.world, 1);

                    if (args[8] != 0xFFFF) {
                        func_0809797C(w, args);
                    } else {
                        return 0;
                    }
                }
            } else if (v >= 131 && v <= 133) {
#ifdef VERSION_EU
                if (func_08093B38() <= 98) {
                    *(PrizeCardArgs*)args = w->args;
                    args[8] = CARD_ID(CARD_ULTIMA_WEAPON, GetRandom() % 10);
                    func_0809797C(w, args);
                }
#else
                *(PrizeCardArgs*)args = w->args;
                args[8] = CARD_ID(CARD_ULTIMA_WEAPON, GetRandom() % 10);
                func_0809797C(w, args);
#endif
            } else {
                *(PrizeCardArgs*)args = w->args;

                if ((gGameState.flags & 8) == 0) {
                    if (HasMapCard(0xFB) == 0) {
                        if (func_080E924C() == 0) {
                            if (gUnk_0903612C[gGameState.world] != 0) {
                                if (GetRandom() % 100 <= gUnk_0903612C[gGameState.world]) {
                                    args[8] = 0xFB;
                                } else {
                                    args[8] = func_08096D48(gGameState.world, 1);
                                }
                            } else {
                                args[8] = func_08096D48(gGameState.world, 1);
                            }
                        } else {
                            args[8] = func_08096D48(gGameState.world, 1);
                        }
                    } else {
                        args[8] = func_08096D48(gGameState.world, 1);
                    }
                } else {
                    args[8] = func_08096D48(gGameState.world, 1);
                }

                if (args[8] != 0xFFFF) {
                    func_0809797C(w, args);
                } else {
                    return 0;
                }
            }
        }

        w->unk_14 = 1;
    }

    TaskPoolUpdate(w);
    return 1;
}

s32 PrizeCardInit_Boss_1(PrizeCardInitWork* w, void* a) {
    PrizeCardTaskArgs args;

    if (w->unk_14 == 0) {
        *(PrizeCardArgs*)&args = w->args;

        switch (gBtlWork->unk_10C) {
        case 148:
            args.cardId = CARD_GUARD_ARMOR_1;
            break;
        case 149:
            args.cardId = CARD_JAFAR_1;
            break;
        case 150:
            args.cardId = CARD_TRICKMASTER_1;
            break;
        case 151:
            args.cardId = CARD_URSULA_1;
            break;
        case 152:
            args.cardId = CARD_PARASITE_CAGE_1;
            break;
        case 153:
            args.cardId = CARD_DRAGON_MALEFICENT_1;
            break;
        case 154:
            args.cardId = CARD_DARKSIDE_1;
            break;
        case 155:
            args.cardId = CARD_OOGIE_BOOGIE_1;
            break;
        case 156:
            args.cardId = CARD_MARLUXIA_1;
            break;
        case 120:
            args.cardId = CARD_CARD_SOLDIER_2;
            break;
        case 162:
            args.cardId = CARD_ID(CARD_FIRE, 5);
            break;
        case 163:
            args.cardId = CARD_ID(CARD_THUNDER, 7);
            break;
        case 161:
            args.cardId = CARD_ID(CARD_AERO, 6);
            break;
        case 157:
        case 158:
            args.cardId = CARD_HOOK_9;
            break;
        case 159:
            args.cardId = CARD_ID(CARD_HI_POTION, 3);
            break;
        case 160:
            args.cardId = CARD_HADES_9;
            break;
        case 165:
            args.cardId = CARD_MARLUXIA_9;
            break;
        case 164:
            args.cardId = CARD_ID(CARD_MEGA_ETHER, 4);
            break;
        case 169:
            args.cardId = CARD_ID(CARD_MEGA_POTION, 2);
            break;
        case 170:
            args.cardId = CARD_RIKU_9;
            break;
        case 173:
            args.cardId = CARD_AXEL_9;
            break;
        case 174:
            args.cardId = CARD_LARXENE_9;
            break;
        case 175:
            args.cardId = CARD_VEXEN_9;
            break;
        case 121:
            args.cardId = CARD_ID(CARD_DUMBO, 3);
            break;
        case 124:
            args.cardId = CARD_ID(CARD_ETHER, 3);
            break;
        case 167:
            args.cardId = CARD_LEXAEUS_9;
            break;
        default:
            w->unk_14 = 1;
            return 1;
        }

        if (gBtlWork->unk_10C != 121) {
            if (func_0808510C(args.cardId) == 0) {
                TaskCreate(w, &gTaskDescPrizeBoss, &args);
            }
        } else {
            TaskCreate(w, &gTaskDescPrizeBoss, &args);
        }

        w->unk_14 = 1;
    }

    TaskPoolUpdate(w);
    return 1;
}

void func_08096C20(void* pool) {
    TaskPoolDraw(pool);
}
void func_08096C2C(void* pool) {
    TaskPoolDestroy(pool);
}

u16 func_08096C38(const UnkStruct_08096C38* tbl, u16 n) {
    s32 i;
    const UnkStruct_08096C38_Item* arr;
    u16 cnt;
    u16 v;
    u16 card;

    i = 0;

    if (func_08093B38() <= 98) {
        while (i < n) {
            arr = tbl[i].unk_00;
            cnt = tbl[i].unk_04;
            v = GetRandom() % 100;

            if (v <= tbl[i].unk_06) {
                card = arr[GetRandom() % cnt].unk_00;
                v = func_08093B08(card);

                if (v <= 89) {
                    return card;
                }
            }

            i++;

            if (i >= n) {
                i = 0;
            }
        }
    } else {
        return 0xFFFF;
    }
}

u16 func_08096CCC(void) {
    u16 i;

    do {
        i = GetRandom() % 10;
    } while (gUnk_090359FC[i] <= GetRandom() % 100);

    return i;
}

u16 func_08096D0C(u16 a, s32 b) {
    const UnkStruct_08096C38* tiles;
    u16 n;

    if (gGameState.flags & 8) {
        tiles = gUnk_090360BC[a].data;
        n = gUnk_090360BC[a].size;
    } else {
        tiles = gUnk_09035DCC[a].data;
        n = gUnk_09035DCC[a].size;
    }

    return func_08096C38(tiles, n);
}

u16 func_08096D48(u16 a, s32 b) {
    const UnkStruct_08096C38* tiles;
    u16 base;
    u16 off;

    off = 0;

    if (gGameState.flags & 8) {
        tiles = gUnk_090360BC[a].data;
        base = func_08096C38(tiles, gUnk_090360BC[a].size);
    } else {
        tiles = gUnk_09035DCC[a].data;
        base = func_08096C38(tiles, gUnk_09035DCC[a].size);
    }

    if (base != 0xFFFF) {
        do {
            off = func_08096CCC();
        } while (gUnk_0203A8C0[base + off] == 9);
    }

    return base + off;
}

void CreatePrizeCardTask(void* a, void* b) {
    TaskCreate(a, &gTaskDescPrizeCardInit, b);
}

void CreateBossPrizeCardTask(void* a, void* b) {
    TaskCreate(a, &gTaskDescPrizeCardInitBoss, b);
}
void DispCardname_0(u8* work, u16* a) {
    UnkStruct_080038C8* p;
    s32 v;

    InitTextSlots((TextSlot*)work, 32);
    p = _08066468(1);
    *(void**)&work[0x104] = p;
    FadeSetPaletteExcluded(p->index + 16, 1);
    work[0x10E] = LoadTextSlots(a, (TextSlot*)work);
    *(void**)&work[0x100] = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
    *(void**)&work[0x108] = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_JP
    v = (240 - work[0x10E] * 10) / 2;
#else
    v = (240 - GetTextSlotsWidth((TextSlot*)work, work[0x10E])) / 2;
#endif
    *(s16*)&work[0x10C] = v;
}
s32 DispCardname_1(void) {
    return 1;
}

void DispCardname_2(u8* work) {
    DrawTextSlots(*(s16*)&work[0x10C], 120, work, *(void**)&work[0x104], 50,
                  work[0x10E]);
    DrawSprite(120, 125, gUnk_09EF126C[0], *(void**)&work[0x100],
               *(void**)&work[0x108], 0, 0, 55);
}

void DispCardname_3(u8* work) {
    FreeTextSlots(work, 32);
    ReleaseObjTiles(*(void**)&work[0x100]);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x104])->index + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x104]);
    ReleaseObjPalette(*(void**)&work[0x108]);
}

void CreateCardNameDisplay(void* a, void* b) {
    TaskCreate(a, &gTaskDescDispCardname, b);
}
void Version_0(u8* work) {
    *(void**)&work[0x00] = LoadSmallFontTiles();
    *(void**)&work[0x04] = LoadSmallFontPalette();
    work[0x28] = EncodeSmallFontString(gUnk_081283C0, &work[0x08]);
}
s32 Version_1(void) {
    return 1;
}
void Version_2(u8* work) {
    DrawSmallFontString(0, 152, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}
void Version_3(s32* p) {
    FreeSmallFontResources(p[0], p[1]);
}
s32 CreateVersionDisplay(void* a) {
    return (s32)TaskCreate(a, &gTaskDescVersion, 0);
}
static void PrizeCard_0(UnkStruct_08096F94* w, s32* args) {
    u8* p;

    w->unk_B0 = args[8];
    w->cardDef = &gUnk_09EE4C80[args[8]];
    w->cardBack = &gUnk_09EE4BF4[w->cardDef->backIndex];
    w->tiles = LoadObjTiles(w->cardDef->tiles, 0x300);
    w->palette = LoadObjPalette(w->cardDef->palette, 32);
    *(u64*)&w->unk_3C = *(u64*)&w->cardDef->unk_20;
    w->tiles2 = LoadObjTiles(w->cardBack->tiles, w->cardBack->tilesSize);
    w->tiles3 = LoadObjTiles(w->cardBack->tiles, w->cardBack->tilesSize);
    w->palette2 = LoadObjPalette(w->cardBack->palette, w->cardBack->paletteSize);
    w->tiles4 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->tiles5 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette3 = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_A0 = args[0];
    w->unk_A4 = args[1];
    w->unk_A8 = 0;
    w->unk_AC = 0;
    w->unk_DE = 24;
    w->unk_B4 = -(GetRandom() % 129 + 0x300);
    w->unk_B8 = GetRandom() % 129 + 0x80;
    w->unk_DC = GetRandom() % 256;
    w->scaleX = 0x80;
    w->scaleY = 0x80;
    w->unk_DA = 0x80;
    w->unk_DF = 0;
    w->unk_E0 = 0;
    p = w->unk_44;
    ColliderInit(p, 5, 8, 10);
    ColliderSetDisabled(p, 1);
    ColliderSetPosition(p, w->unk_A0, w->unk_A4, w->unk_A8);
    w->unk_E6 = 0;
    w->unk_E7 = 0;
    w->unk_E8 = 0;
    w->unk_E1 = 0;
    w->unk_E5 = 0;
    w->unk_E2 = 0;
    w->unk_E3 = 0;
    TaskPoolInit(&w->tasks, 1);
    gBtlWork->unk_0B0++;
}
static u8 PrizeCard_1(UnkStruct_08096F94* w, void* a) {
    s16 x;
    s16 y;

    w->unk_B4 += 56;
    w->unk_A8 += w->unk_B4;
    w->unk_A0 += (gSineTable[(u8)w->unk_DC] * w->unk_B8) >> 8;
    w->unk_A4 += (-gSineTable[(u8)w->unk_DC + 64] * w->unk_B8) >> 8;

    if (ClampBattlePosition(&w->unk_A0, &w->unk_A4, -10, -10)) {
        w->unk_DC += GetRandom() % 57 + 100;
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_44, 50);
    } else {
        ColliderSetRadius(w->unk_44, 10);
    }

    if (w->unk_A8 - 8 > w->unk_AC) {
        w->unk_A8 = w->unk_AC - 8;
        w->unk_B4 = -((w->unk_B4 * 217) >> 8);
        w->unk_DC = (u8)GetAngle(w->unk_A0, w->unk_A4, gBtlWork->actor->x, gBtlWork->actor->y);
        w->unk_DC += GetRandom() % 65 - 32;

        if (w->unk_B4 > -0x200) {
            w->unk_B4 = -0x200;
        }
    }

    if (w->unk_70 != 0) {
        w->unk_E5 = 1;
        m4aSongNumStart(SONG_SYS_ITEMGET);
        AddMapCard(w->unk_B0);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08097404);
        WorldToScreen(&x, &y, w->unk_A0, w->unk_A4, w->unk_A8);
        w->unk_A0 = x << 8;
        w->unk_A4 = y << 8;
        ColliderSetDisabled(w->unk_44, 1);
        w->unk_CC = 50;
        func_08097390(w);
        return 1;
    } else {
        ColliderSetPosition(w->unk_44, w->unk_A0, w->unk_A4, w->unk_A8);
        WorldToScreen(&w->x, &w->y2, w->unk_A0, w->unk_A4, w->unk_A8);
        WorldToScreen(&w->x2, &w->y, w->unk_A0, w->unk_A4, w->unk_AC);
        w->unk_CC = -0x1004 - (w->unk_A4 >> 8) * 4;
        func_080978B0(w);
        w->unk_E0 += 2;

        if (w->unk_E1 == 20) {
            ColliderSetDisabled(w->unk_44, 0);
        }

        if (w->unk_E1 <= 59) {
            w->unk_E1++;
        }
    }

    return 1;
}

void func_08097390(UnkStruct_08096F94* w) {
    s16 x;
    s16 y;
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    WorldToScreen(&x, &y, gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);
    tx = 0x7800;
    ty = 0x5000;
    dx = tx - w->unk_A0;
    dy = ty - w->unk_A4;
    w->unk_C4 = NormalizeVector2D8(&dx, &dy);
    w->unk_BC = -dx;
    w->unk_C0 = -dy;
    w->unk_B8 = 0x300;
    w->unk_B4 = 2;
}

u8 func_08097404(UnkStruct_08096F94* w, void* a) {
    s32 dx;
    s32 dy;
    u8 z;
    u8 t;
    s32 x;
    s32 y;
    s16* q1;
    s16* q2;

    if (w->unk_B8 < 0) {
        dx = 0x7800 - w->unk_A0;
        dy = 0x5000 - w->unk_A4;
        NormalizeVector2D8(&dx, &dy);
        w->unk_BC = -dx;
        w->unk_C0 = -dy;

        if (w->unk_C4 <= 0x7FF) {
            w->unk_E2 = 0;
            w->unk_DE = 0;
            SetTaskUpdate(a, (TaskUpdateFunc)func_0809753C);
            CreateCardNameDisplay(&w->tasks, GetRoomName(w->cardDef->unk_20));
        }
    }

    w->unk_A0 += (w->unk_BC * w->unk_B8) >> 8;
    w->unk_A4 += (w->unk_C0 * w->unk_B8) >> 8;
    t = w->unk_DE + 32;
    z = 0;
    w->unk_DE = t;
    w->unk_DF += (64 - w->unk_DF) >> 4;
    w->unk_E0 = z;
    w->unk_C4 = VectorLength2D(0x7800 - w->unk_A0, 0x5000 - w->unk_A4);
    w->unk_B8 -= w->unk_B4;
    w->unk_B4 += 2;

    if (w->unk_DA <= 0xFF) {
        w->unk_DA += 3;
    }

    x = w->unk_A0 >> 8;
    q1 = &w->x;
    *q1 = x;
    y = w->unk_A4 >> 8;
    q2 = &w->y2;
    *q2 = y;
    func_080978B0(w);
    return 1;
}
u8 func_0809753C(UnkStruct_08096F94* w, void* a) {
    s32 v;
    s16 lim;
    s32 x;
    s16* q;

    v = w->unk_DE << 8;
    ApproachValue((s32*)&w->unk_DF, 0, w->unk_E2);
    ApproachValue(&v, 0, w->unk_E2);
    ApproachValue(&w->unk_A0, 0x7800, w->unk_E2);
    ApproachValue(&w->unk_A4, 0x5800, w->unk_E2);
    w->unk_DE = v >> 8;

    if (w->unk_E2 != 0) {
        w->unk_E2--;
    }

    lim = 0x100;

    if (w->unk_DA < 0x100) {
        w->unk_DA += 2;
    } else {
        w->unk_DA = lim;
    }

    x = w->unk_A0 >> 8;
    q = &w->x;
    *q = x;
    x = w->unk_A4 >> 8;
    q = &w->y2;
    *q = x;
    func_080978B0(w);
    w->unk_E3++;

    if (w->unk_E3 == 30) {
        w->unk_E3 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08097600);
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_08097600(UnkStruct_08096F94* w) {
    w->unk_DE += 32;
    WorldToScreen(&w->x3, &w->y3, gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);
    w->x += (w->x3 - w->x) >> 3;
    w->y2 += (w->y3 - w->y2) >> 3;
    w->scaleX -= 10;
    w->scaleY -= 10;

    if (w->scaleX <= 10) {
        return 0;
    }

    return 1;
}

static void PrizeCard_2(UnkStruct_08096F94* w) {
    u16 pal;
    s32 affine;
    void* gfx;
    s16 v;

    pal = w->unk_E5 == 0 ? GetBattleSpritePriorityFlags(w->unk_A4) : 0;

    if (w->scaleX == 0x100 && w->unk_DE == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_DE, w->scaleX, w->scaleY, 1);
    }

    DrawSprite(w->x, (u16)w->y2 - 8,
               *w->cardDef->sprites,
               w->tiles, w->palette, affine, pal,
               (u16)(w->unk_CC + 1));

    if (w->cardDef->backIndex == 4) {
        gfx = w->cardBack->sprites[w->unk_E8];
    } else {
        gfx = w->cardBack->sprites[0];
    }

    DrawSprite(w->x, (u16)w->y2 - 8, gfx,
               w->tiles2, w->palette2, affine, pal,
               w->unk_CC);

    if (w->cardDef->backIndex != 4) {
        gfx = gUnk_09EE981C[w->unk_3E];
        DrawSprite(w->x, (u16)w->y2 - 8, gfx,
                   w->tiles4, w->palette2, affine, pal,
                   (u16)(w->unk_CC - 1));
    }

    if (w->unk_E5 == 0) {
        v = 204 - ((w->unk_AC - w->unk_A8) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(w->x2, w->y, gUnk_09EE1380[0],
                   w->tiles5, w->palette3,
                   AllocObjAffine(0, v, v, 0), pal,
                   (u16)(w->unk_CC + 2));
    }

    TaskPoolDraw(&w->tasks);
}

static void PrizeCard_3(PrizeCardWork* w) {
    FadeSetPaletteExcluded(w->palette2->index + 16, 0);
    FadeSetPaletteExcluded(w->palette->index + 16, 0);
    ColliderUnregister(&w->unk_20[0x24]);
    ReleaseObjTiles(w->tiles);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjTiles(w->tiles3);
    ReleaseObjTiles(w->tiles5);
    ReleaseObjPalette(w->palette);
    ReleaseObjPalette(w->palette2);
    ReleaseObjPalette(w->palette3);
    TaskPoolDestroy(&w->unk_20[8]);
    gBtlWork->unk_0B0--;
}

void func_080978B0(UnkStruct_08096F94* w) {
    w->scaleX = (-gSineTable[((w->unk_E0 + 0x80) & 0xFF) + 0x40] * w->unk_DA) >> 8;
    w->scaleY = (-gSineTable[((w->unk_DF + 0x80) & 0xFF) + 0x40] * w->unk_DA) >> 8;

    if ((u16)(w->scaleX + 2) <= 4) {
        w->scaleX = 2;
    }

    if ((u16)(w->scaleY + 2) <= 4) {
        w->scaleY = 2;
    }
}
#ifndef VERSION_EU
void func_0809792C(UnkStruct_08096F94* w) {
    u8* p;
    u8* q;
    u8 k;
    u8 v;
    u8 z;

    v = gUnk_09EE752C[w->unk_E7].unk_00;
    q = &w->unk_E8;
    z = 0;
    *q = v;
    p = &w->unk_E6;
    k = w->unk_E7;

    if (*p == gUnk_09EE752C[k].unk_01) {
        w->unk_E7 = k + 1;

        if (w->unk_E7 == 7) {
            w->unk_E7 = z;
        }

        *p = z;
    }

    w->unk_E6++;
}
#endif
void func_0809797C(void* a, void* b) {
    TaskCreate(a, &gUnk_09EE7650, b);
}

void SpotLight_0(SpotlightWork* w, u8* src) {
    if (src != 0) {
        w->unk_10 = src;
    } else {
        w->unk_10 = &w->unk_14;
        w->unk_14 = 0;
    }

    LoadBgTiles(0, gUnk_09501778, 0xCA0);
    LoadPalette(gUnk_09618C38, gUnk_050001A0, 32);
    FadeSetPaletteExcluded(13, 1);
    LoadBgMap(0, gUnk_0960F2B8, 0x800);
    SetBgScroll(0, 0, 0);
    w->unk_00 = 30;
    w->unk_04 = 0x1000;
    w->unk_08 = 0;
    FadeStartOut(0, 30);
    gBldCnt = (BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
}

u8 SpotLight_1(SpotlightWork* w, void* a) {
    ApproachValue(&w->unk_08, 0x1000, w->unk_00);

    if (w->unk_00 != 0) {
        w->unk_00--;
        w->unk_0C = ((w->unk_04 >> 8) << 8) | (w->unk_08 >> 8);
        gBldAlpha = w->unk_0C;
    }

    if (*w->unk_10 == 1) {
        FadeStartIn(0, 30);
        w->unk_00 = 30;
        gBldCnt = (BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08097A80);
    }

    return 1;
}

s32 func_08097A80(u8* work) {
    s32 v;

    ApproachValue(&work[0x08], 0, work[0x00]);

    if (work[0x00] != 0) {
        work[0x00]--;
    }

    v = ((*(s32*)&work[0x04] >> 8) << 8) | (*(s32*)&work[0x08] >> 8);
    *(u16*)&work[0x0C] = v;
    gBldAlpha = v;
    return 1;
}
void SpotLight_2(void) {
}
void SpotLight_3(void) {
    FadeSetPaletteExcluded(13, 0);
}
void SELMAP_EVKEY_0(SelmapEventKeyWork* work, void* a) {
    s32 zero;
    s32 i;
    s32 ofs;
    u8* q1;
    u8* q2;
    u8* q3;

    zero = 0;
    CpuSet(&zero, work, 0x05000049);
    work->unk_D8 = a;
    work->unk_F8 = ((void**)a)[1];
    work->unk_121 = func_080E8D00();

    for (i = 0; i < work->unk_121; i++) {
        ofs = i * 52;
        func_08098014(&work->unk_08[ofs], func_080E8D1C((u8)i));
        q1 = &work->unk_08[0xC];

        if (*(u8**)&q1[ofs] != 0) {
            FadeSetPaletteExcluded(*(u16*)&(*(u8**)&q1[ofs])[6] + 16, 1);
        }
        q2 = &work->unk_08[0x10];

        if (*(u8**)&q2[ofs] != 0) {
            FadeSetPaletteExcluded(*(u16*)&(*(u8**)&q2[ofs])[6] + 16, 1);
        }
        q3 = &work->unk_08[0x14];

        if (*(u8**)&q3[ofs] != 0) {
            FadeSetPaletteExcluded(*(u16*)&(*(u8**)&q3[ofs])[6] + 16, 1);
        }
    }

#ifdef VERSION_EU
    work->tiles = AllocObjTiles(0x800, 0);
    SetObjTileSource(work->tiles, gUnkEu_09F72A64[gLanguage]);
    AnimInit(&work->anim, gUnkEu_09F72A3C[gLanguage], gUnkEu_09F72A50[gLanguage]);
#else
#ifdef VERSION_JP
    work->tiles = AllocObjTiles(0x480, 0);
    SetObjTileSource(work->tiles, &gUnk_093F47E4[0x22DC]);
#else
    work->tiles = AllocObjTiles(0x6C0, 0);
    SetObjTileSource(work->tiles, &gUnk_093F47E4[0x22E8]);
#endif
    AnimInit(&work->anim, gUnk_09EF1224, gUnk_09EF1220);
#endif
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
    work->palette = *work->unk_D8;
    work->unk_11C = 0;
    work->unk_11D = 0;
    work->unk_11E = 8;
    work->unk_11F = 8;
    work->unk_120 = 0;
    work->unk_123 = 0;
    SetObjMosaicSize(work->unk_11E, work->unk_11F);
    work->unk_FC = 0x7800;
    work->unk_100 = 0x4000;
    work->unk_114 = 0x100;
    work->unk_116 = 0x100;
    work->unk_11B = 0;
    work->unk_122 = 0;
    work->unk_11A = 8;
    work->unk_118 = 0;
    func_08098598(0x10000, work->unk_100, (s32*)&work->unk_08[0]);
    func_08098598(0x10000, work->unk_100, (s32*)&work->unk_08[0x34]);
    func_08098598(0x10000, work->unk_100, (s32*)&work->unk_08[0x68]);
    func_08098598(0x10000, work->unk_100, (s32*)&work->unk_08[0x9C]);
}
s32 SELMAP_EVKEY_1(u8* work, void* a) {
    s32 i;
    u8* q1;
    u8* q2;
    u8* q3;
    u8* r;
    u8 n;

    *(void**)&work[0xF4] = AnimUpdate(&work[0xDC]);
    *(s32*)&work[0x104] = ((240 - (work[0x121] - work[0x122]) * 32) << 7) + 0x1000;
    ApproachValue(&work[0xFC], *(s32*)&work[0x104], work[0x11A]);

    if (work[0x11A] != 0) {
        work[0x11A]--;
    }

    for (i = work[0x122]; i < work[0x121]; i++) {
        func_08098598(*(s32*)&work[0xFC] + ((i - work[0x122]) << 13), *(s32*)&work[0x100], (s32*)&work[i * 52 + 8]);
    }

    SetObjMosaicSize(work[0x11E], work[0x11F]);

    if (work[0x120] == 2) {
        if (work[0x11E] != 0) {
            work[0x11E]--;
        }

        if (work[0x11F] != 0) {
            work[0x11F]--;
        }

        work[0x120] = 0;
    }

    work[0x120]++;
    work[0x11D]++;

    if ((*(void***)&work[0xD8])[2] != 0) {
        SetTaskUpdate(a, (TaskUpdateFunc)func_08097DE4);
    }

    q1 = &work[work[0x122] * 52];

    if (*(u16*)&q1[0x36] != 0) {
        r = func_080E8D1C(0);
        q2 = &work[work[0x122] * 52];
        *(u16*)&q2[0x36] = r[3];
        n = work[0x122];
        q3 = &work[n * 52];

        if (*(u16*)&q3[0x38] != *(u16*)&q3[0x36]) {
            func_080984E4((UnkStruct_080984E4*)&work[n * 52 + 8]);
        }
    }

    *(u16*)&work[0x118] += 8;
    return 1;
}
s32 func_08097DE4(u8* work) {
    u8* a;
    u8* b;

    a = &work[0x11E];

    if (*a <= 14) {
        (*a)++;
    }

    b = &work[0x11F];

    if (*b <= 14) {
        (*b)++;
    }

    SetObjMosaicSize(*a, *b);
    return 1;
}
void SELMAP_EVKEY_2(u8* work) {
    s32 i;
    s32 ofs;
    u8* e;
    u8* q1;
    u8* q2;

    switch ((*(s32**)&work[0xD8])[2]) {
    case 0:
    case 2:
        if (work[0x11E] == 15) {
            return;
        }

        if (work[0x11F] == 15) {
            break;
        }

        for (i = work[0x122]; i < work[0x121]; i++) {
            if (i == work[0x122]) {
                func_080985A0((UnkStruct_08098670*)&work[i * 52 + 8], 0x808, 0,
                              (gSineTable[work[0x118]] >> 8) * 8 + 256);
                e = &work[i * 52];

                switch (e[58]) {
                case 2:
                    ofs = i * 52;
                    DrawSprite(*(s32*)&(q1 = &work[44])[ofs] >> 8, (*(s32*)&(q2 = &work[48])[ofs] >> 8) + 8,
                               gMapCardUiResources.sprites[4], gMapCardUiResources.extraTiles, gMapCardUiResources.palette, 0, 8, 20);
                    break;
                case 3:
                    ofs = i * 52;
                    DrawSprite(*(s32*)&(q1 = &work[44])[ofs] >> 8, (*(s32*)&(q2 = &work[48])[ofs] >> 8) + 8,
                               gMapCardUiResources.sprites[8], gMapCardUiResources.extraTiles, gMapCardUiResources.palette, 0, 8, 20);
                    break;
                case 1:
                    ofs = i * 52;
                    DrawSprite(*(s32*)&(q1 = &work[44])[ofs] >> 8, (*(s32*)&(q2 = &work[48])[ofs] >> 8) + 8,
                               gMapCardUiResources.sprites[6], gMapCardUiResources.extraTiles, gMapCardUiResources.palette, 0, 8, 20);
                    break;
                case 0:
                case 4:
                default:
                    break;
                }
            } else {
                func_08098670((UnkStruct_08098670*)&work[i * 52 + 8], 0x808);
            }
        }
        break;
    }

    if (work[0x11E] == 15) {
        return;
    }

    if (work[0x11F] == 15) {
        return;
    }

    DrawSprite(120, 42, *(void**)&work[0xF4], *(void**)&work[0], *(void**)&work[4], 0, 8, 10);
}
void SELMAP_EVKEY_3(u8* work) {
    s32 i;

    for (i = 0; i < work[0x121]; i++) {
        func_08098778((void**)&work[i * 52 + 8]);
    }

    ReleaseObjTiles(*(void**)&work[0x00]);
}

void func_08098014(u8* work, const u8* a) {
    s32 zero;
    MapCardDef* c;
    MapCardBackDef* b;
    MapCardBackDef* d;
    CardBack* cb;
    u8 n;
    s32 z;
    u8 t;

    zero = 0;
    CpuSet((void*)&zero, work, 0x0500000D);

    if (a[0] != 255) {
        c = &gUnk_09EE4C80[a[0] * 10];
        b = &gUnk_09EE4BF4[c->backIndex];
        *(void**)&work[0x00] = LoadObjTiles(c->tiles, c->tilesSize);
        *(void**)&work[0x0C] = LoadObjPalette(c->palette, c->paletteSize);
        *(void**)&work[0x18] = *c->sprites;
        *(void**)&work[0x04] = LoadObjTiles(b->tiles, b->tilesSize);
        *(void**)&work[0x10] = LoadObjPalette(b->palette, b->paletteSize);
        *(void**)&work[0x1C] = *b->sprites;
        *(s32*)&work[0x08] = 0;
        *(s32*)&work[0x14] = 0;
        return;
    }

    *(s32*)&work[0x00] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x14] = 0;

    if (a[1] == 0) {
        n = a[1];
        *(s32*)&work[0x04] = 0;
        *(s32*)&work[0x10] = 0;
        *(s32*)&work[0x1C] = 0;
    } else {
        d = &gUnk_09EE4BF4[a[1]];
        *(void**)&work[0x04] = LoadObjTiles(d->tiles2, *(u16*)&d->unk_18[0]);
        *(void**)&work[0x10] = LoadObjPalette(d->palette, d->paletteSize);
        *(void**)&work[0x1C] = *d->sprites2;
        *(s32*)&work[0x08] = 0;
        *(s32*)&work[0x00] = 0;
        *(s32*)&work[0x0C] = 0;
        *(s32*)&work[0x18] = 0;
        *(s32*)&work[0x14] = 0;

        switch (a[1]) {
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 3;
            break;
        default:
            n = a[1];
            break;
        }
    }

    work[0x32] = (z = 0, n);

    if (a[2] == 0) {
        return;
    }

    switch (a[2]) {
    case 1:
        if (a[3] <= 9) {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x100);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + a[3] * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + 0x500, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        } else {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x180);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (u8)(a[3] / 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 8) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + 0x500, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        }
        break;
    case 2:
        if (a[3] <= 9) {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x100);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + a[3] * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + 0x580, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        } else {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x180);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (u8)(a[3] / 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 8) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + 0x580, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        }
        break;
    case 3:
        if (a[3] <= 9) {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x100);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + a[3] * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + 0x600, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        } else {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x180);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (u8)(a[3] / 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 8) * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + 0x600, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        }
        break;
    case 4:
        if (a[3] <= 9) {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x80);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[0], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + a[3] * 128, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
        } else {
            *(void**)&work[0x08] = AllocSpriteFrameTiles(0x100);
            UpdateSpriteFrameTiles(*(void**)&work[0x08], gUnk_09EF1198[2], gUnk_0950C478);
            *(s32*)&work[0x20] = z;
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (u8)(a[3] / 10) * 128, &gUnk_06010000[(*(UnkStruct_080038C8**)&work[0x08])->index * 32], 128);
            RequestDma3Copy((*(UnkStruct_080038C8**)&work[0x08])->src + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[((*(UnkStruct_080038C8**)&work[0x08])->index + 4) * 32], 128);
        }

        t = a[3];
        *(u16*)&work[0x2E] = t;
        *(u16*)&work[0x30] = t;
        break;
    }

    *(s32*)&work[0x00] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(void**)&work[0x14] = LoadObjPalette(gUnk_09618D38, 32);

    if (*(void**)&work[0x04] == 0) {
        cb = &gUnk_08F709B0[4];
        *(void**)&work[0x04] = LoadObjTiles(cb->tiles2, 0x300);
        *(void**)&work[0x10] = LoadObjPalette(gUnk_09618D38, 32);
        *(void**)&work[0x1C] = cb->gfx2;
    }
}

void func_080984E4(UnkStruct_080984E4* w) {
    s32 z;

    if (w->unk_2E <= 9) {
        z = 0;
        UpdateSpriteFrameTiles(w->tiles, gUnk_09EF1198[0], gUnk_0950C478);
        w->unk_20 = z;
        RequestDma3Copy(w->tiles->src + w->unk_2E * 128, &gUnk_06010000[w->tiles->index * 32], 128);
    } else {
        z = 0;
        UpdateSpriteFrameTiles(w->tiles, gUnk_09EF1198[2], gUnk_0950C478);
        w->unk_20 = z;
        RequestDma3Copy(w->tiles->src + (u16)(w->unk_2E / 10) * 128, &gUnk_06010000[w->tiles->index * 32], 128);
        RequestDma3Copy(w->tiles->src + (w->unk_2E - (u16)(w->unk_2E / 10) * 10) * 128, &gUnk_06010000[(w->tiles->index + 4) * 32], 128);
    }

    w->unk_30 = w->unk_2E;
}

void func_08098598(s32 a, s32 b, s32* c) {
    c[9] = a;
    c[10] = b;
}

void func_080985A0(UnkStruct_08098670* w, u16 b, s16 c, s16 d) {
    s32 aff;

    aff = AllocObjAffine(0, d, d, 1);

    if (w->tiles != 0) {
        DrawSprite(w->x >> 8, c + (w->y >> 8), w->gfx, w->tiles, w->palette, aff, b, 10);
    }

    if (w->tiles2 != 0) {
        DrawSprite(w->x >> 8, c + (w->y >> 8), w->gfx2, w->tiles2, w->palette2, aff, b, 9);
    }

    if (w->tiles3 != 0) {
        DrawSprite(w->x >> 8, c + (w->y >> 8), w->gfx3, w->tiles3, w->palette3, aff, b, 8);
    }
}

void func_08098670(UnkStruct_08098670* p, u16 a) {
    if (p->tiles != 0) {
        DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, 0, a, 10);
    }

    if (p->tiles2 != 0) {
        DrawSprite(p->x >> 8, p->y >> 8, p->gfx2, p->tiles2, p->palette2, 0, a, 9);
    }

    if (p->tiles3 != 0) {
        DrawSprite(p->x >> 8, p->y >> 8, p->gfx3, p->tiles3, p->palette3, 0, a, 8);
    }
}

UnkStruct_080038C8* func_080986FC(u8 a) {
    UnkStruct_080038C8* obj;

    if (a != 0) {
        obj = AllocSpriteFrameTiles(256);
        UpdateSpriteFrameTiles(obj, gUnk_09EF1198[1], gUnk_0950C478);
        RequestDma3Copy(&obj->src[a * 128], (void*)(0x06010000 + (obj->index + 4) * 32), 128);
        RequestDma3Copy(&obj->src[0x500], (void*)(0x06010000 + obj->index * 32), 128);
    } else {
        obj = AllocSpriteFrameTiles(128);
        UpdateSpriteFrameTiles(obj, gUnk_09EF1198[0], gUnk_0950C478);
    }

    return obj;
}

void func_08098778(void** p) {
    if (p[0] != 0) {
        ReleaseObjTiles(p[0]);
    }

    if (p[1] != 0) {
        ReleaseObjTiles(p[1]);
    }

    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
    }

    if (p[3] != 0) {
        ReleaseObjPalette(p[3]);
    }

    if (p[4] != 0) {
        ReleaseObjPalette(p[4]);
    }

    if (p[5] != 0) {
        ReleaseObjPalette(p[5]);
    }
}

u8 func_080987C0(u16 n) {
    u8 idx;

    idx = 0;

    switch (n) {
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 170;
        break;
    case 3:
        idx = 50;
        break;
    case 4:
        idx = 40;
        break;
    case 5:
        idx = 190;
        break;
    case 6:
        idx = 20;
        break;
    case 7:
        idx = 30;
        break;
    case 8:
        idx = 160;
        break;
    case 9:
        idx = 180;
        break;
    case 10:
        idx = 210;
        break;
    case 11:
        idx = 100;
        break;
    case 12:
        idx = 90;
        break;
    case 13:
        idx = 110;
        break;
    case 14:
        idx = 120;
        break;
    case 15:
        idx = 200;
        break;
    case 16:
        idx = 140;
        break;
    case 17:
        idx = 150;
        break;
    case 18:
        idx = 130;
        break;
    case 19:
        idx = 60;
        break;
    case 20:
        idx = 70;
        break;
    case 21:
        idx = 80;
        break;
    case 22:
        idx = 220;
        break;
    case 23:
        idx = 230;
        break;
    case 24:
        idx = 240;
        break;
    case 0:
    case 26:
        idx = 10;
        break;
    case 25:
    case 27:
        idx = 250;
        break;
    }

    return gUnk_09EE4C80[idx].backIndex;
}

TaskDesc gTaskDescPrizeCardInit = {
    "PrizeCardInit",
    (TaskInitFunc)func_08096714,
    (TaskUpdateFunc)PrizeCardInit_1,
    func_08096C20,
    func_08096C2C,
    0x38,
};

TaskDesc gTaskDescPrizeCardInitBoss = {
    "PrizeCardInit_Boss",
    (TaskInitFunc)func_08096714,
    (TaskUpdateFunc)PrizeCardInit_Boss_1,
    func_08096C20,
    func_08096C2C,
    0x38,
};

TaskDesc gTaskDescDispCardname = {
    "DispCardname",
    (TaskInitFunc)DispCardname_0,
    (TaskUpdateFunc)DispCardname_1,
    (TaskFunc)DispCardname_2,
    (TaskFunc)DispCardname_3,
    0x110,
};

TaskDesc gTaskDescVersion = {
    "Version",
    (TaskInitFunc)Version_0,
    (TaskUpdateFunc)Version_1,
    (TaskFunc)Version_2,
    (TaskFunc)Version_3,
    0x2C,
};

TaskDesc gUnk_09EE7650 = {
    "PrizeCard",
    (TaskInitFunc)PrizeCard_0,
    (TaskUpdateFunc)PrizeCard_1,
    (TaskFunc)PrizeCard_2,
    (TaskFunc)PrizeCard_3,
    0xEC,
};

TaskDesc gTaskDescSpotLight = {
    "SpotLight",
    (TaskInitFunc)SpotLight_0,
    (TaskUpdateFunc)SpotLight_1,
    (TaskFunc)SpotLight_2,
    (TaskFunc)SpotLight_3,
    0x18,
};
#ifdef VERSION_EU
void* gUnkEu_09F72A3C[5] = { gUnk_09EF1224, gUnkEu_09F7C438, gUnkEu_09F7C450, gUnkEu_09F7C448, gUnkEu_09F7C440 };

void* gUnkEu_09F72A50[5] = { gUnk_09EF1220, gUnkEu_09F7C434, gUnkEu_09F7C44C, gUnkEu_09F7C444, gUnkEu_09F7C43C };

void* gUnkEu_09F72A64[5] = { gUnk_093F6ACC, gUnkEu_094C7CCE, gUnkEu_094C9180, gUnkEu_094C8946, gUnkEu_094C8288 };
#endif

TaskDesc gTaskDescSELMAPEVKEY = {
    "SELMAP_EVKEY",
    (TaskInitFunc)SELMAP_EVKEY_0,
    (TaskUpdateFunc)SELMAP_EVKEY_1,
    (TaskFunc)SELMAP_EVKEY_2,
    (TaskFunc)SELMAP_EVKEY_3,
    0x124,
};
