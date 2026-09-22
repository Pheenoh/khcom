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

u32 gUnk_02034AA4;
u32 gUnk_02034AA8;
CardDisplayWork* gUnk_02034AAC;
u8 gActiveDeck;
u8 gUnk_02034AB1[3];
s16 gUnk_02034AB4;
u8 gUnk_02034AB6[2];
#ifdef VERSION_EU
u8 gUnkEu_02034AD4[4];
#endif

u8 gUnk_02039DD8 EWRAM_COMMON(4);
u8 gUnk_02039DDC EWRAM_COMMON(4);
Deck gDecks[3] EWRAM_COMMON(16);
u16 gCardCollection[999] EWRAM_COMMON(16);
Deck* gUnk_0203A850 EWRAM_COMMON(4);
void* gUnk_0203A854 EWRAM_COMMON(4);
u16 gCardCount EWRAM_COMMON(4);
CardUiSpriteState gUnk_0203A860 EWRAM_COMMON(16);

u8 func_0807EDEC(UnkStruct_08080268* w, void* a);
u8 func_0809511C(ReloadGageWork* w, void* a);
#ifdef VERSION_EU
extern u8* gUnkEu_09F6FE04[];
extern void* gUnkEu_09F72D08[];
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
extern void* gUnkEu_09F6FE30[];
extern void* gUnkEu_09F6FE58[];
extern void** gUnkEu_09F6FE44[];
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
extern void* gUnkEu_09F72D1C[];
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
void deckexchange_0(u8* work, void* a);
u8 deckexchange_1(u8* work, void* a);
void deckexchange_2(UnkStruct_0808C940* w);
void deckexchange_3(u8* work);
void func_080AAF78(void);
void func_080AAFB4(void);
void func_080AB008(void);
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
void eu_080AB9FC(void);
void eu_080ABA38(void);
void eu_080ABA7C(void);
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
u8 gUnkEu_09F6FD74[7] = { 'D', 'e', 'c', 'k', ' ', '1', 0 };

u8 gUnkEu_09F6FD7B[7] = { 'D', 'e', 'c', 'k', ' ', '2', 0 };

u8 gUnkEu_09F6FD82[7] = { 'D', 'e', 'c', 'k', ' ', '3', 0 };
#else
u16 gUnk_09EE4AC8[7] = { 'D', 'e', 'c', 'k', ' ', '1', 0 };

u16 gUnk_09EE4AD6[7] = { 'D', 'e', 'c', 'k', ' ', '2', 0 };

u16 gUnk_09EE4AE4[7] = { 'D', 'e', 'c', 'k', ' ', '3', 0 };
#endif
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
void* gUnkEu_09F6FE30[5] = { gUnk_090A5F1E, gUnk_090A5F1E, gUnkEu_091965CA, gUnkEu_091959DA, gUnk_090A5F1E };

void** gUnkEu_09F6FE44[5] = { gUnk_09EEB08C, gUnk_09EEB08C, gUnkEu_09F7721C, gUnkEu_09F771E4, gUnk_09EEB08C };

void* gUnkEu_09F6FE58[5] = { gUnk_09EEB0B8, gUnk_09EEB0B8, gUnkEu_09F77248, gUnkEu_09F77210, gUnk_09EEB0B8 };
#endif
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
