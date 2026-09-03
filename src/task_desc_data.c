#include "taskpool.h"

extern const char gTaskNameEvtObj[];
extern const char gTaskNameEvtShadow[];
extern const char gTaskNameAcgtrans[];
extern const char gTaskNameBtlLockon[];
extern const char gTaskNameBtlArea[];
extern const char gTaskNameBtlSora[];
extern const char gTaskNameBtlRiku[];
extern const char gTaskNameBtlMap[];
extern const char gTaskNameBtlShadow[];
extern const char gTaskNameBtlHpply[];
extern const char gTaskNameBtlHpenm[];
extern const char gTaskNameBtlPause[];
extern const char gTaskNameBtlPop[];
extern const char gTaskNameBtlEscape[];
extern const char gTaskNameBtlPrize[];
extern const char gTaskNameBtlPremire[];
extern const char gTaskNameBtlStart[];
extern const char gTaskNameFldSora[];
extern const char gTaskNameFldRiku[];
extern const char gTaskNameFldShadow[];
extern const char gTaskNameEmy00[];
extern const char gTaskNameEmy01[];
extern const char gTaskNameEmy02[];
extern const char gTaskNameEmy03[];
extern const char gTaskNameEmy04[];
extern const char gTaskNameEmy06[];
extern const char gTaskNameEmy07[];
extern const char gTaskNameEmy08[];
extern const char gTaskNameEmy14[];
extern const char gTaskNameEmy15[];
extern const char gTaskNameEmy16[];
extern const char gTaskNameEmy16B[];
extern const char gTaskNameEmy16P[];
extern const char gTaskNameEmy18[];
extern const char gTaskNameEmy19[];
extern const char gTaskNameEmy21[];
extern const char gTaskNameEmy22[];
extern const char gTaskNameEmy23[];
extern const char gTaskNameEmy25[];
extern const char gTaskNameEmy26[];
extern const char gTaskNameEmy27[];
extern const char gTaskNameEmy28[];
extern const char gTaskNameEmy29[];
extern const char gTaskNameEmy30[];
extern const char gTaskNameEmy31[];
extern const char gTaskNameEmy37[];
extern const char gTaskNameEmy38[];
extern const char gTaskNameEmy39[];
extern const char gTaskNameEmy41[];
extern const char gTaskNameEmy44[];
extern const char gTaskNameEmy81[];
extern const char gTaskNameEmy82[];
extern const char gTaskNameEmy83[];
extern const char gTaskNameEmy83B[];
extern const char gTaskNameEmy83S[];
extern const char gTaskNameEmyTrumpH[];
extern const char gTaskNameEmyTrumpS[];
extern const char gTaskNameEmyTest[];
extern const char gTaskNameBosMap[];
extern const char gTaskNameBosShadow[];
extern const char gTaskNameRoomcreate[];
extern const char gTaskNameRomcriEff[];
extern const char gTaskNameRomcriEff2[];
extern const char gTaskNameBtlForm[];
extern const char gTaskNameBtlBorn[];
extern const char gTaskNameBtlRaid[];
extern const char gTaskNameBtlBadstatus[];
extern const char gTaskNameSmnCloud[];
extern const char gTaskNameSmnBambi[];
extern const char gTaskNameSmnTink[];
extern const char gTaskNameSmnTinkeff[];
extern const char gTaskNameSmnSimba[];
extern const char gTaskNameSmnMushu[];
extern const char gTaskNameSmnDumbo[];
extern const char gTaskNameSmnGenie[];
extern const char gTaskNameSmnKing[];
extern const char gTaskNameFrdDonald[];
extern const char gTaskNameFrdGoofy[];
extern const char gTaskNameFrdAriel[];
extern const char gTaskNameFrdJack[];
extern const char gTaskNameFrdPan[];
extern const char gTaskNameFrdAladdin[];
extern const char gTaskNameFrdBeast[];
extern const char gTaskNamePcAcddmg[];
extern const char gTaskNameHumCloud[];
extern const char gTaskNameHumHook[];
extern const char gTaskNameHumHookMoon[];
extern const char gTaskNameHumHookBomb[];
extern const char gTaskNameHumAnsem[];
extern const char gTaskNameHumHades[];
extern const char gTaskNameHumMahluxia[];
extern const char gTaskNameHumLaxene[];
extern const char gTaskNameHumLaxeneKnf[];
extern const char gTaskNameHumAxcel[];
extern const char gTaskNameHumAxcelPtc[];
extern const char gTaskNameHumVixen[];
extern const char gTaskNameHumVixenNdl[];
extern const char gTaskNameHumVixenIce[];
extern const char gTaskNameHumVixenFrz[];
extern const char gTaskNameHumVixenFrg[];
extern const char gTaskNameHumLexceus[];
extern const char gTaskNameHumLexTmh[];
extern const char gTaskNameHumLexTmh0[];
extern const char gTaskNameHumLexRock[];
extern const char gTaskNameHumMahluxiaFlw[];
extern const char gTaskNameHumRiku[];
extern const char gTaskNameHumLeon[];
extern const char gTaskNameHumRobe[];

void task_evt_obj_0(void* work, void* arg);
void task_evt_obj_1(void* work);
void task_evt_obj_2(void* work);
void task_evt_obj_3(void* work);
void task_evt_shadow_0(void* work, void* arg);
void task_evt_shadow_1(void* work);
void task_evt_shadow_2(void* work);
void task_evt_shadow_3(void* work);
void task_acgtrans_0(void* work, void* arg);
void task_acgtrans_1(void* work);
void task_btl_lockon_0(void* work, void* arg);
void task_btl_lockon_1(void* work);
void task_btl_lockon_2(void* work);
void task_btl_lockon_3(void* work);
void task_btl_area_0(void* work, void* arg);
void task_btl_area_1(void* work);
void task_btl_area_2(void* work);
void task_btl_area_3(void* work);
void task_btl_sora_0(void* work, void* arg);
void task_btl_sora_1(void* work);
void task_btl_sora_2(void* work);
void task_btl_sora_3(void* work);
void task_btl_riku_0(void* work, void* arg);
void task_btl_riku_1(void* work);
void task_btl_riku_2(void* work);
void task_btl_riku_3(void* work);
void task_btl_map_0(void* work, void* arg);
void task_btl_map_1(void* work);
void task_btl_shadow_0(void* work, void* arg);
void task_btl_shadow_1(void* work);
void task_btl_shadow_2(void* work);
void task_btl_shadow_3(void* work);
void task_btl_hpply_0(void* work, void* arg);
void task_btl_hpply_1(void* work);
void task_btl_hpply_2(void* work);
void task_btl_hpply_3(void* work);
void task_btl_hpenm_0(void* work, void* arg);
void task_btl_hpenm_1(void* work);
void task_btl_hpenm_2(void* work);
void task_btl_hpenm_3(void* work);
void task_btl_pause_0(void* work, void* arg);
void task_btl_pause_1(void* work);
void task_btl_pause_2(void* work);
void task_btl_pause_3(void* work);
void task_btl_pop_0(void* work, void* arg);
void task_btl_pop_1(void* work);
void task_btl_pop_2(void* work);
void task_btl_pop_3(void* work);
void task_btl_escape_0(void* work, void* arg);
void task_btl_escape_1(void* work);
void task_btl_escape_2(void* work);
void task_btl_escape_3(void* work);
void task_btl_prize_0(void* work, void* arg);
void task_btl_prize_1(void* work);
void task_btl_prize_2(void* work);
void task_btl_prize_3(void* work);
void task_btl_premire_0(void* work, void* arg);
void task_btl_premire_1(void* work);
void task_btl_premire_2(void* work);
void task_btl_premire_3(void* work);
void task_btl_start_0(void* work, void* arg);
void task_btl_start_1(void* work);
void task_fld_sora_0(void* work, void* arg);
void task_fld_sora_1(void* work);
void task_fld_sora_2(void* work);
void task_fld_sora_3(void* work);
void task_fld_riku_0(void* work, void* arg);
void task_fld_riku_1(void* work);
void task_fld_riku_2(void* work);
void task_fld_riku_3(void* work);
void task_fld_shadow_0(void* work, void* arg);
void task_fld_shadow_1(void* work);
void task_fld_shadow_2(void* work);
void task_fld_shadow_3(void* work);
void task_emy_00_0(void* work, void* arg);
void task_emy_00_1(void* work);
void task_emy_00_2(void* work);
void task_emy_00_3(void* work);
void task_emy_01_0(void* work, void* arg);
void task_emy_01_1(void* work);
void task_emy_01_2(void* work);
void task_emy_01_3(void* work);
void task_emy_02_0(void* work, void* arg);
void task_emy_02_1(void* work);
void task_emy_02_2(void* work);
void task_emy_02_3(void* work);
void task_emy_03_0(void* work, void* arg);
void task_emy_03_1(void* work);
void task_emy_03_2(void* work);
void task_emy_03_3(void* work);
void task_emy_04_0(void* work, void* arg);
void task_emy_04_1(void* work);
void task_emy_04_2(void* work);
void task_emy_04_3(void* work);
void task_emy_06_0(void* work, void* arg);
void task_emy_06_1(void* work);
void task_emy_06_2(void* work);
void task_emy_06_3(void* work);
void task_emy_07_0(void* work, void* arg);
void task_emy_07_1(void* work);
void task_emy_07_2(void* work);
void task_emy_07_3(void* work);
void task_emy_08_0(void* work, void* arg);
void task_emy_08_1(void* work);
void task_emy_08_2(void* work);
void task_emy_08_3(void* work);
void task_emy_14_0(void* work, void* arg);
void task_emy_14_1(void* work);
void task_emy_14_2(void* work);
void task_emy_14_3(void* work);
void task_emy_15_0(void* work, void* arg);
void task_emy_15_1(void* work);
void task_emy_15_2(void* work);
void task_emy_15_3(void* work);
void task_emy_16_0(void* work, void* arg);
void task_emy_16_1(void* work);
void task_emy_16_2(void* work);
void task_emy_16_3(void* work);
void task_emy_16_b_0(void* work, void* arg);
void task_emy_16_b_1(void* work);
void task_emy_16_b_2(void* work);
void task_emy_16_b_3(void* work);
void task_emy_16_p_0(void* work, void* arg);
void task_emy_16_p_1(void* work);
void task_emy_16_p_2(void* work);
void task_emy_16_p_3(void* work);
void task_emy_18_0(void* work, void* arg);
void task_emy_18_1(void* work);
void task_emy_18_2(void* work);
void task_emy_18_3(void* work);
void task_emy_19_0(void* work, void* arg);
void task_emy_19_1(void* work);
void task_emy_19_2(void* work);
void task_emy_19_3(void* work);
void task_emy_21_0(void* work, void* arg);
void task_emy_21_1(void* work);
void task_emy_21_2(void* work);
void task_emy_21_3(void* work);
void task_emy_22_0(void* work, void* arg);
void task_emy_22_1(void* work);
void task_emy_22_2(void* work);
void task_emy_22_3(void* work);
void task_emy_23_0(void* work, void* arg);
void task_emy_23_1(void* work);
void task_emy_23_2(void* work);
void task_emy_23_3(void* work);
void task_emy_25_0(void* work, void* arg);
void task_emy_25_1(void* work);
void task_emy_25_2(void* work);
void task_emy_25_3(void* work);
void task_emy_26_0(void* work, void* arg);
void task_emy_26_1(void* work);
void task_emy_26_2(void* work);
void task_emy_26_3(void* work);
void task_emy_27_0(void* work, void* arg);
void task_emy_27_1(void* work);
void task_emy_27_2(void* work);
void task_emy_27_3(void* work);
void task_emy_28_0(void* work, void* arg);
void task_emy_28_1(void* work);
void task_emy_28_2(void* work);
void task_emy_28_3(void* work);
void task_emy_29_0(void* work, void* arg);
void task_emy_29_1(void* work);
void task_emy_29_2(void* work);
void task_emy_29_3(void* work);
void task_emy_30_0(void* work, void* arg);
void task_emy_30_1(void* work);
void task_emy_30_2(void* work);
void task_emy_30_3(void* work);
void task_emy_31_0(void* work, void* arg);
void task_emy_31_1(void* work);
void task_emy_31_2(void* work);
void task_emy_31_3(void* work);
void task_emy_37_0(void* work, void* arg);
void task_emy_37_1(void* work);
void task_emy_37_2(void* work);
void task_emy_37_3(void* work);
void task_emy_38_0(void* work, void* arg);
void task_emy_38_1(void* work);
void task_emy_38_2(void* work);
void task_emy_38_3(void* work);
void task_emy_39_0(void* work, void* arg);
void task_emy_39_1(void* work);
void task_emy_39_2(void* work);
void task_emy_39_3(void* work);
void task_emy_41_0(void* work, void* arg);
void task_emy_41_1(void* work);
void task_emy_41_2(void* work);
void task_emy_41_3(void* work);
void task_emy_44_0(void* work, void* arg);
void task_emy_44_1(void* work);
void task_emy_44_2(void* work);
void task_emy_44_3(void* work);
void task_emy_81_0(void* work, void* arg);
void task_emy_81_1(void* work);
void task_emy_81_2(void* work);
void task_emy_81_3(void* work);
void task_emy_82_0(void* work, void* arg);
void task_emy_82_1(void* work);
void task_emy_82_2(void* work);
void task_emy_82_3(void* work);
void task_emy_83_0(void* work, void* arg);
void task_emy_83_1(void* work);
void task_emy_83_2(void* work);
void task_emy_83_3(void* work);
void task_emy_83_b_0(void* work, void* arg);
void task_emy_83_b_1(void* work);
void task_emy_83_b_2(void* work);
void task_emy_83_b_3(void* work);
void task_emy_83_s_0(void* work, void* arg);
void task_emy_83_s_1(void* work);
void task_emy_83_s_2(void* work);
void task_emy_83_s_3(void* work);
void task_emy_trump_h_0(void* work, void* arg);
void task_emy_trump_h_1(void* work);
void task_emy_trump_h_2(void* work);
void task_emy_trump_h_3(void* work);
void task_emy_trump_s_0(void* work, void* arg);
void task_emy_trump_s_1(void* work);
void task_emy_trump_s_2(void* work);
void task_emy_trump_s_3(void* work);
void task_emy_test_0(void* work, void* arg);
void task_emy_test_1(void* work);
void task_emy_test_2(void* work);
void task_emy_test_3(void* work);
void task_bos_map_0(void* work, void* arg);
void task_bos_map_1(void* work);
void task_bos_shadow_0(void* work, void* arg);
void task_bos_shadow_1(void* work);
void task_bos_shadow_2(void* work);
void task_bos_shadow_3(void* work);
void task_roomcreate_0(void* work, void* arg);
void task_roomcreate_1(void* work);
void task_roomcreate_2(void* work);
void task_roomcreate_3(void* work);
void task_romcri_eff_0(void* work, void* arg);
void task_romcri_eff_1(void* work);
void task_romcri_eff_3(void* work);
void task_romcri_eff2_0(void* work, void* arg);
void task_romcri_eff2_1(void* work);
void task_romcri_eff2_3(void* work);
void task_btl_form_0(void* work, void* arg);
void task_btl_form_1(void* work);
void task_btl_form_3(void* work);
void task_btl_born_0(void* work, void* arg);
void task_btl_born_1(void* work);
void task_btl_raid_0(void* work, void* arg);
void task_btl_raid_1(void* work);
void task_btl_raid_2(void* work);
void task_btl_raid_3(void* work);
void task_btl_badstatus_0(void* work, void* arg);
void task_btl_badstatus_1(void* work);
void task_btl_badstatus_2(void* work);
void task_btl_badstatus_3(void* work);
void task_smn_cloud_0(void* work, void* arg);
void task_smn_cloud_1(void* work);
void task_smn_cloud_2(void* work);
void task_smn_cloud_3(void* work);
void task_smn_bambi_0(void* work, void* arg);
void task_smn_bambi_1(void* work);
void task_smn_bambi_2(void* work);
void task_smn_bambi_3(void* work);
void task_smn_tink_0(void* work, void* arg);
void task_smn_tink_1(void* work);
void task_smn_tink_2(void* work);
void task_smn_tink_3(void* work);
void task_smn_tinkeff_0(void* work, void* arg);
void task_smn_tinkeff_1(void* work);
void task_smn_tinkeff_2(void* work);
void task_smn_tinkeff_3(void* work);
void task_smn_simba_0(void* work, void* arg);
void task_smn_simba_1(void* work);
void task_smn_simba_2(void* work);
void task_smn_simba_3(void* work);
void task_smn_mushu_0(void* work, void* arg);
void task_smn_mushu_1(void* work);
void task_smn_mushu_2(void* work);
void task_smn_mushu_3(void* work);
void task_smn_dumbo_0(void* work, void* arg);
void task_smn_dumbo_1(void* work);
void task_smn_dumbo_2(void* work);
void task_smn_dumbo_3(void* work);
void task_smn_genie_0(void* work, void* arg);
void task_smn_genie_1(void* work);
void task_smn_genie_2(void* work);
void task_smn_genie_3(void* work);
void task_smn_king_0(void* work, void* arg);
void task_smn_king_1(void* work);
void task_smn_king_2(void* work);
void task_smn_king_3(void* work);
void task_frd_donald_0(void* work, void* arg);
void task_frd_donald_1(void* work);
void task_frd_donald_2(void* work);
void task_frd_donald_3(void* work);
void task_frd_goofy_0(void* work, void* arg);
void task_frd_goofy_1(void* work);
void task_frd_goofy_2(void* work);
void task_frd_goofy_3(void* work);
void task_frd_ariel_0(void* work, void* arg);
void task_frd_ariel_1(void* work);
void task_frd_ariel_2(void* work);
void task_frd_ariel_3(void* work);
void task_frd_jack_0(void* work, void* arg);
void task_frd_jack_1(void* work);
void task_frd_jack_2(void* work);
void task_frd_jack_3(void* work);
void task_frd_pan_0(void* work, void* arg);
void task_frd_pan_1(void* work);
void task_frd_pan_2(void* work);
void task_frd_pan_3(void* work);
void task_frd_aladdin_0(void* work, void* arg);
void task_frd_aladdin_1(void* work);
void task_frd_aladdin_2(void* work);
void task_frd_aladdin_3(void* work);
void task_frd_beast_0(void* work, void* arg);
void task_frd_beast_1(void* work);
void task_frd_beast_2(void* work);
void task_frd_beast_3(void* work);
void task_pc_acddmg_0(void* work, void* arg);
void task_pc_acddmg_1(void* work);
void task_hum_cloud_0(void* work, void* arg);
void task_hum_cloud_1(void* work);
void task_hum_cloud_2(void* work);
void task_hum_cloud_3(void* work);
void task_hum_hook_0(void* work, void* arg);
void task_hum_hook_1(void* work);
void task_hum_hook_2(void* work);
void task_hum_hook_3(void* work);
void task_hum_hook_moon_0(void* work, void* arg);
void task_hum_hook_moon_1(void* work);
void task_hum_hook_moon_2(void* work);
void task_hum_hook_moon_3(void* work);
void task_hum_hook_bomb_0(void* work, void* arg);
void task_hum_hook_bomb_1(void* work);
void task_hum_hook_bomb_2(void* work);
void task_hum_hook_bomb_3(void* work);
void task_hum_ansem_0(void* work, void* arg);
void task_hum_ansem_1(void* work);
void task_hum_ansem_2(void* work);
void task_hum_ansem_3(void* work);
void task_hum_hades_0(void* work, void* arg);
void task_hum_hades_1(void* work);
void task_hum_hades_2(void* work);
void task_hum_hades_3(void* work);
void task_hum_mahluxia_0(void* work, void* arg);
void task_hum_mahluxia_1(void* work);
void task_hum_mahluxia_2(void* work);
void task_hum_mahluxia_3(void* work);
void task_hum_laxene_0(void* work, void* arg);
void task_hum_laxene_1(void* work);
void task_hum_laxene_2(void* work);
void task_hum_laxene_3(void* work);
void task_hum_laxene_knf_0(void* work, void* arg);
void task_hum_laxene_knf_1(void* work);
void task_hum_laxene_knf_2(void* work);
void task_hum_laxene_knf_3(void* work);
void task_hum_axcel_0(void* work, void* arg);
void task_hum_axcel_1(void* work);
void task_hum_axcel_2(void* work);
void task_hum_axcel_3(void* work);
void task_hum_axcel_ptc_0(void* work, void* arg);
void task_hum_axcel_ptc_1(void* work);
void task_hum_axcel_ptc_2(void* work);
void task_hum_axcel_ptc_3(void* work);
void task_hum_vixen_0(void* work, void* arg);
void task_hum_vixen_1(void* work);
void task_hum_vixen_2(void* work);
void task_hum_vixen_3(void* work);
void task_hum_vixen_ndl_0(void* work, void* arg);
void task_hum_vixen_ndl_1(void* work);
void task_hum_vixen_ndl_2(void* work);
void task_hum_vixen_ndl_3(void* work);
void task_hum_vixen_ice_0(void* work, void* arg);
void task_hum_vixen_ice_1(void* work);
void task_hum_vixen_ice_2(void* work);
void task_hum_vixen_ice_3(void* work);
void task_hum_vixen_frz_0(void* work, void* arg);
void task_hum_vixen_frz_1(void* work);
void task_hum_vixen_frz_2(void* work);
void task_hum_vixen_frz_3(void* work);
void task_hum_vixen_frg_0(void* work, void* arg);
void task_hum_vixen_frg_1(void* work);
void task_hum_vixen_frg_2(void* work);
void task_hum_vixen_frg_3(void* work);
void task_hum_lexceus_0(void* work, void* arg);
void task_hum_lexceus_1(void* work);
void task_hum_lexceus_2(void* work);
void task_hum_lexceus_3(void* work);
void task_hum_lex_tmh_0(void* work, void* arg);
void task_hum_lex_tmh_1(void* work);
void task_hum_lex_tmh_2(void* work);
void task_hum_lex_tmh_3(void* work);
void task_hum_lex_tmh0_0(void* work, void* arg);
void task_hum_lex_tmh0_1(void* work);
void task_hum_lex_tmh0_2(void* work);
void task_hum_lex_tmh0_3(void* work);
void task_hum_lex_rock_0(void* work, void* arg);
void task_hum_lex_rock_1(void* work);
void task_hum_lex_rock_2(void* work);
void task_hum_lex_rock_3(void* work);
void task_hum_mahluxia_flw_0(void* work, void* arg);
void task_hum_mahluxia_flw_1(void* work);
void task_hum_mahluxia_flw_2(void* work);
void task_hum_mahluxia_flw_3(void* work);
void task_hum_riku_0(void* work, void* arg);
void task_hum_riku_1(void* work);
void task_hum_riku_2(void* work);
void task_hum_riku_3(void* work);
void task_hum_leon_0(void* work, void* arg);
void task_hum_leon_1(void* work);
void task_hum_leon_2(void* work);
void task_hum_leon_3(void* work);
void task_hum_robe_0(void* work, void* arg);
void task_hum_robe_1(void* work);
void task_hum_robe_2(void* work);
void task_hum_robe_3(void* work);

TaskDesc gTaskDescEvtObj = { gTaskNameEvtObj, task_evt_obj_0, task_evt_obj_1, task_evt_obj_2, task_evt_obj_3, 0x38 };

TaskDesc gTaskDescEvtShadow = { gTaskNameEvtShadow, task_evt_shadow_0, task_evt_shadow_1, task_evt_shadow_2, task_evt_shadow_3, 0x14 };

TaskDesc gTaskDescAcgtrans = { gTaskNameAcgtrans, task_acgtrans_0, task_acgtrans_1, 0, 0, 0x14 };

TaskDesc gTaskDescBtlLockon = { gTaskNameBtlLockon, task_btl_lockon_0, task_btl_lockon_1, task_btl_lockon_2, task_btl_lockon_3, 0x28 };

TaskDesc gTaskDescBtlArea = { gTaskNameBtlArea, task_btl_area_0, task_btl_area_1, task_btl_area_2, task_btl_area_3, 0xC };

TaskDesc gTaskDescBtlSora = { gTaskNameBtlSora, task_btl_sora_0, task_btl_sora_1, task_btl_sora_2, task_btl_sora_3, 0x1AC };

TaskDesc gTaskDescBtlRiku = { gTaskNameBtlRiku, task_btl_riku_0, task_btl_riku_1, task_btl_riku_2, task_btl_riku_3, 0x374 };

TaskDesc gTaskDescBtlMap = { gTaskNameBtlMap, task_btl_map_0, task_btl_map_1, 0, 0, 0x10 };

TaskDesc gTaskDescBtlShadow = { gTaskNameBtlShadow, task_btl_shadow_0, task_btl_shadow_1, task_btl_shadow_2, task_btl_shadow_3, 0x10 };

TaskDesc gTaskDescBtlHpply = { gTaskNameBtlHpply, task_btl_hpply_0, task_btl_hpply_1, task_btl_hpply_2, task_btl_hpply_3, 0x6C };

TaskDesc gTaskDescBtlHpenm = { gTaskNameBtlHpenm, task_btl_hpenm_0, task_btl_hpenm_1, task_btl_hpenm_2, task_btl_hpenm_3, 0x24 };

TaskDesc gTaskDescBtlPause = { gTaskNameBtlPause, task_btl_pause_0, task_btl_pause_1, task_btl_pause_2, task_btl_pause_3, 0x28 };

TaskDesc gTaskDescBtlPop = { gTaskNameBtlPop, task_btl_pop_0, task_btl_pop_1, task_btl_pop_2, task_btl_pop_3, 0x34 };

TaskDesc gTaskDescBtlEscape = { gTaskNameBtlEscape, task_btl_escape_0, task_btl_escape_1, task_btl_escape_2, task_btl_escape_3, 0x24 };

TaskDesc gTaskDescBtlPrize = { gTaskNameBtlPrize, task_btl_prize_0, task_btl_prize_1, task_btl_prize_2, task_btl_prize_3, 0x4C };

TaskDesc gTaskDescBtlPremire = { gTaskNameBtlPremire, task_btl_premire_0, task_btl_premire_1, task_btl_premire_2, task_btl_premire_3, 0x60 };

TaskDesc gTaskDescBtlStart = { gTaskNameBtlStart, task_btl_start_0, task_btl_start_1, 0, 0, 0x4 };

TaskDesc gTaskDescFldSora = { gTaskNameFldSora, task_fld_sora_0, task_fld_sora_1, task_fld_sora_2, task_fld_sora_3, 0xC0 };

TaskDesc gTaskDescFldRiku = { gTaskNameFldRiku, task_fld_riku_0, task_fld_riku_1, task_fld_riku_2, task_fld_riku_3, 0xC0 };

TaskDesc gTaskDescFldShadow = { gTaskNameFldShadow, task_fld_shadow_0, task_fld_shadow_1, task_fld_shadow_2, task_fld_shadow_3, 0x2C };

TaskDesc gTaskDescEmy00 = { gTaskNameEmy00, task_emy_00_0, task_emy_00_1, task_emy_00_2, task_emy_00_3, 0x184 };

TaskDesc gTaskDescEmy01 = { gTaskNameEmy01, task_emy_01_0, task_emy_01_1, task_emy_01_2, task_emy_01_3, 0x184 };

TaskDesc gTaskDescEmy02 = { gTaskNameEmy02, task_emy_02_0, task_emy_02_1, task_emy_02_2, task_emy_02_3, 0x184 };

TaskDesc gTaskDescEmy03 = { gTaskNameEmy03, task_emy_03_0, task_emy_03_1, task_emy_03_2, task_emy_03_3, 0x190 };

TaskDesc gTaskDescEmy04 = { gTaskNameEmy04, task_emy_04_0, task_emy_04_1, task_emy_04_2, task_emy_04_3, 0x188 };

TaskDesc gTaskDescEmy06 = { gTaskNameEmy06, task_emy_06_0, task_emy_06_1, task_emy_06_2, task_emy_06_3, 0x188 };

TaskDesc gTaskDescEmy07 = { gTaskNameEmy07, task_emy_07_0, task_emy_07_1, task_emy_07_2, task_emy_07_3, 0x188 };

TaskDesc gTaskDescEmy08 = { gTaskNameEmy08, task_emy_08_0, task_emy_08_1, task_emy_08_2, task_emy_08_3, 0x190 };

TaskDesc gTaskDescEmy14 = { gTaskNameEmy14, task_emy_14_0, task_emy_14_1, task_emy_14_2, task_emy_14_3, 0x184 };

TaskDesc gTaskDescEmy15 = { gTaskNameEmy15, task_emy_15_0, task_emy_15_1, task_emy_15_2, task_emy_15_3, 0x184 };

TaskDesc gTaskDescEmy16 = { gTaskNameEmy16, task_emy_16_0, task_emy_16_1, task_emy_16_2, task_emy_16_3, 0x1A4 };

TaskDesc gTaskDescEmy16B = { gTaskNameEmy16B, task_emy_16_b_0, task_emy_16_b_1, task_emy_16_b_2, task_emy_16_b_3, 0xA0 };

TaskDesc gTaskDescEmy16P = { gTaskNameEmy16P, task_emy_16_p_0, task_emy_16_p_1, task_emy_16_p_2, task_emy_16_p_3, 0x34 };

TaskDesc gTaskDescEmy18 = { gTaskNameEmy18, task_emy_18_0, task_emy_18_1, task_emy_18_2, task_emy_18_3, 0x188 };

TaskDesc gTaskDescEmy19 = { gTaskNameEmy19, task_emy_19_0, task_emy_19_1, task_emy_19_2, task_emy_19_3, 0x188 };

TaskDesc gTaskDescEmy21 = { gTaskNameEmy21, task_emy_21_0, task_emy_21_1, task_emy_21_2, task_emy_21_3, 0x188 };

TaskDesc gTaskDescEmy22 = { gTaskNameEmy22, task_emy_22_0, task_emy_22_1, task_emy_22_2, task_emy_22_3, 0x188 };

TaskDesc gTaskDescEmy23 = { gTaskNameEmy23, task_emy_23_0, task_emy_23_1, task_emy_23_2, task_emy_23_3, 0x188 };

TaskDesc gTaskDescEmy25 = { gTaskNameEmy25, task_emy_25_0, task_emy_25_1, task_emy_25_2, task_emy_25_3, 0x184 };

TaskDesc gTaskDescEmy26 = { gTaskNameEmy26, task_emy_26_0, task_emy_26_1, task_emy_26_2, task_emy_26_3, 0x184 };

TaskDesc gTaskDescEmy27 = { gTaskNameEmy27, task_emy_27_0, task_emy_27_1, task_emy_27_2, task_emy_27_3, 0x184 };

TaskDesc gTaskDescEmy28 = { gTaskNameEmy28, task_emy_28_0, task_emy_28_1, task_emy_28_2, task_emy_28_3, 0x188 };

TaskDesc gTaskDescEmy29 = { gTaskNameEmy29, task_emy_29_0, task_emy_29_1, task_emy_29_2, task_emy_29_3, 0x188 };

TaskDesc gTaskDescEmy30 = { gTaskNameEmy30, task_emy_30_0, task_emy_30_1, task_emy_30_2, task_emy_30_3, 0x184 };

TaskDesc gTaskDescEmy31 = { gTaskNameEmy31, task_emy_31_0, task_emy_31_1, task_emy_31_2, task_emy_31_3, 0x194 };

TaskDesc gTaskDescEmy37 = { gTaskNameEmy37, task_emy_37_0, task_emy_37_1, task_emy_37_2, task_emy_37_3, 0x190 };

TaskDesc gTaskDescEmy38 = { gTaskNameEmy38, task_emy_38_0, task_emy_38_1, task_emy_38_2, task_emy_38_3, 0x184 };

TaskDesc gTaskDescEmy39 = { gTaskNameEmy39, task_emy_39_0, task_emy_39_1, task_emy_39_2, task_emy_39_3, 0x188 };

TaskDesc gTaskDescEmy41 = { gTaskNameEmy41, task_emy_41_0, task_emy_41_1, task_emy_41_2, task_emy_41_3, 0x190 };

TaskDesc gTaskDescEmy44 = { gTaskNameEmy44, task_emy_44_0, task_emy_44_1, task_emy_44_2, task_emy_44_3, 0x184 };

TaskDesc gTaskDescEmy81 = { gTaskNameEmy81, task_emy_81_0, task_emy_81_1, task_emy_81_2, task_emy_81_3, 0x194 };

TaskDesc gTaskDescEmy82 = { gTaskNameEmy82, task_emy_82_0, task_emy_82_1, task_emy_82_2, task_emy_82_3, 0x188 };

TaskDesc gTaskDescEmy83 = { gTaskNameEmy83, task_emy_83_0, task_emy_83_1, task_emy_83_2, task_emy_83_3, 0x1A8 };

TaskDesc gTaskDescEmy83B = { gTaskNameEmy83B, task_emy_83_b_0, task_emy_83_b_1, task_emy_83_b_2, task_emy_83_b_3, 0x90 };

TaskDesc gTaskDescEmy83S = { gTaskNameEmy83S, task_emy_83_s_0, task_emy_83_s_1, task_emy_83_s_2, task_emy_83_s_3, 0x24 };

TaskDesc gTaskDescEmyTrumpH = { gTaskNameEmyTrumpH, task_emy_trump_h_0, task_emy_trump_h_1, task_emy_trump_h_2, task_emy_trump_h_3, 0x184 };

TaskDesc gTaskDescEmyTrumpS = { gTaskNameEmyTrumpS, task_emy_trump_s_0, task_emy_trump_s_1, task_emy_trump_s_2, task_emy_trump_s_3, 0x184 };

TaskDesc gTaskDescEmyTest = { gTaskNameEmyTest, task_emy_test_0, task_emy_test_1, task_emy_test_2, task_emy_test_3, 0x184 };

TaskDesc gTaskDescBosMap = { gTaskNameBosMap, task_bos_map_0, task_bos_map_1, 0, 0, 0x4 };

TaskDesc gTaskDescBosShadow = { gTaskNameBosShadow, task_bos_shadow_0, task_bos_shadow_1, task_bos_shadow_2, task_bos_shadow_3, 0xC };

TaskDesc gTaskDescRoomcreate = { gTaskNameRoomcreate, task_roomcreate_0, task_roomcreate_1, task_roomcreate_2, task_roomcreate_3, 0x44 };

TaskDesc gTaskDescRomcriEff = { gTaskNameRomcriEff, task_romcri_eff_0, task_romcri_eff_1, 0, task_romcri_eff_3, 0x4 };

TaskDesc gTaskDescRomcriEff2 = { gTaskNameRomcriEff2, task_romcri_eff2_0, task_romcri_eff2_1, 0, task_romcri_eff2_3, 0x4 };

TaskDesc gTaskDescBtlForm = { gTaskNameBtlForm, task_btl_form_0, task_btl_form_1, 0, task_btl_form_3, 0x28 };

TaskDesc gTaskDescBtlBorn = { gTaskNameBtlBorn, task_btl_born_0, task_btl_born_1, 0, 0, 0x14 };

TaskDesc gTaskDescBtlRaid = { gTaskNameBtlRaid, task_btl_raid_0, task_btl_raid_1, task_btl_raid_2, task_btl_raid_3, 0x6C };

TaskDesc gTaskDescBtlBadstatus = { gTaskNameBtlBadstatus, task_btl_badstatus_0, task_btl_badstatus_1, task_btl_badstatus_2, task_btl_badstatus_3, 0x30 };

TaskDesc gTaskDescSmnCloud = { gTaskNameSmnCloud, task_smn_cloud_0, task_smn_cloud_1, task_smn_cloud_2, task_smn_cloud_3, 0x180 };

TaskDesc gTaskDescSmnBambi = { gTaskNameSmnBambi, task_smn_bambi_0, task_smn_bambi_1, task_smn_bambi_2, task_smn_bambi_3, 0x178 };

TaskDesc gTaskDescSmnTink = { gTaskNameSmnTink, task_smn_tink_0, task_smn_tink_1, task_smn_tink_2, task_smn_tink_3, 0x180 };

TaskDesc gTaskDescSmnTinkeff = { gTaskNameSmnTinkeff, task_smn_tinkeff_0, task_smn_tinkeff_1, task_smn_tinkeff_2, task_smn_tinkeff_3, 0x30 };

TaskDesc gTaskDescSmnSimba = { gTaskNameSmnSimba, task_smn_simba_0, task_smn_simba_1, task_smn_simba_2, task_smn_simba_3, 0x158 };

TaskDesc gTaskDescSmnMushu = { gTaskNameSmnMushu, task_smn_mushu_0, task_smn_mushu_1, task_smn_mushu_2, task_smn_mushu_3, 0x15C };

TaskDesc gTaskDescSmnDumbo = { gTaskNameSmnDumbo, task_smn_dumbo_0, task_smn_dumbo_1, task_smn_dumbo_2, task_smn_dumbo_3, 0x158 };

TaskDesc gTaskDescSmnGenie = { gTaskNameSmnGenie, task_smn_genie_0, task_smn_genie_1, task_smn_genie_2, task_smn_genie_3, 0x168 };

TaskDesc gTaskDescSmnKing = { gTaskNameSmnKing, task_smn_king_0, task_smn_king_1, task_smn_king_2, task_smn_king_3, 0x168 };

TaskDesc gTaskDescFrdDonald = { gTaskNameFrdDonald, task_frd_donald_0, task_frd_donald_1, task_frd_donald_2, task_frd_donald_3, 0x164 };

TaskDesc gTaskDescFrdGoofy = { gTaskNameFrdGoofy, task_frd_goofy_0, task_frd_goofy_1, task_frd_goofy_2, task_frd_goofy_3, 0x164 };

TaskDesc gTaskDescFrdAriel = { gTaskNameFrdAriel, task_frd_ariel_0, task_frd_ariel_1, task_frd_ariel_2, task_frd_ariel_3, 0x164 };

TaskDesc gTaskDescFrdJack = { gTaskNameFrdJack, task_frd_jack_0, task_frd_jack_1, task_frd_jack_2, task_frd_jack_3, 0x16C };

TaskDesc gTaskDescFrdPan = { gTaskNameFrdPan, task_frd_pan_0, task_frd_pan_1, task_frd_pan_2, task_frd_pan_3, 0x170 };

TaskDesc gTaskDescFrdAladdin = { gTaskNameFrdAladdin, task_frd_aladdin_0, task_frd_aladdin_1, task_frd_aladdin_2, task_frd_aladdin_3, 0x160 };

TaskDesc gTaskDescFrdBeast = { gTaskNameFrdBeast, task_frd_beast_0, task_frd_beast_1, task_frd_beast_2, task_frd_beast_3, 0x160 };

TaskDesc gTaskDescPcAcddmg = { gTaskNamePcAcddmg, task_pc_acddmg_0, task_pc_acddmg_1, 0, 0, 0xC };

TaskDesc gTaskDescHumCloud = { gTaskNameHumCloud, task_hum_cloud_0, task_hum_cloud_1, task_hum_cloud_2, task_hum_cloud_3, 0x194 };

TaskDesc gTaskDescHumHook = { gTaskNameHumHook, task_hum_hook_0, task_hum_hook_1, task_hum_hook_2, task_hum_hook_3, 0x1BC };

TaskDesc gTaskDescHumHookMoon = { gTaskNameHumHookMoon, task_hum_hook_moon_0, task_hum_hook_moon_1, task_hum_hook_moon_2, task_hum_hook_moon_3, 0xC };

TaskDesc gTaskDescHumHookBomb = { gTaskNameHumHookBomb, task_hum_hook_bomb_0, task_hum_hook_bomb_1, task_hum_hook_bomb_2, task_hum_hook_bomb_3, 0x54 };

TaskDesc gTaskDescHumAnsem = { gTaskNameHumAnsem, task_hum_ansem_0, task_hum_ansem_1, task_hum_ansem_2, task_hum_ansem_3, 0x1DC };

TaskDesc gTaskDescHumHades = { gTaskNameHumHades, task_hum_hades_0, task_hum_hades_1, task_hum_hades_2, task_hum_hades_3, 0x280 };

TaskDesc gTaskDescHumMahluxia = { gTaskNameHumMahluxia, task_hum_mahluxia_0, task_hum_mahluxia_1, task_hum_mahluxia_2, task_hum_mahluxia_3, 0x3A4 };

TaskDesc gTaskDescHumLaxene = { gTaskNameHumLaxene, task_hum_laxene_0, task_hum_laxene_1, task_hum_laxene_2, task_hum_laxene_3, 0x1A8 };

TaskDesc gTaskDescHumLaxeneKnf = { gTaskNameHumLaxeneKnf, task_hum_laxene_knf_0, task_hum_laxene_knf_1, task_hum_laxene_knf_2, task_hum_laxene_knf_3, 0x44 };

TaskDesc gTaskDescHumAxcel = { gTaskNameHumAxcel, task_hum_axcel_0, task_hum_axcel_1, task_hum_axcel_2, task_hum_axcel_3, 0x238 };

TaskDesc gTaskDescHumAxcelPtc = { gTaskNameHumAxcelPtc, task_hum_axcel_ptc_0, task_hum_axcel_ptc_1, task_hum_axcel_ptc_2, task_hum_axcel_ptc_3, 0x30 };

TaskDesc gTaskDescHumVixen = { gTaskNameHumVixen, task_hum_vixen_0, task_hum_vixen_1, task_hum_vixen_2, task_hum_vixen_3, 0x218 };

TaskDesc gTaskDescHumVixenNdl = { gTaskNameHumVixenNdl, task_hum_vixen_ndl_0, task_hum_vixen_ndl_1, task_hum_vixen_ndl_2, task_hum_vixen_ndl_3, 0x30 };

TaskDesc gTaskDescHumVixenIce = { gTaskNameHumVixenIce, task_hum_vixen_ice_0, task_hum_vixen_ice_1, task_hum_vixen_ice_2, task_hum_vixen_ice_3, 0x94 };

TaskDesc gTaskDescHumVixenFrz = { gTaskNameHumVixenFrz, task_hum_vixen_frz_0, task_hum_vixen_frz_1, task_hum_vixen_frz_2, task_hum_vixen_frz_3, 0x38 };

TaskDesc gTaskDescHumVixenFrg = { gTaskNameHumVixenFrg, task_hum_vixen_frg_0, task_hum_vixen_frg_1, task_hum_vixen_frg_2, task_hum_vixen_frg_3, 0x220 };

TaskDesc gTaskDescHumLexceus = { gTaskNameHumLexceus, task_hum_lexceus_0, task_hum_lexceus_1, task_hum_lexceus_2, task_hum_lexceus_3, 0x204 };

TaskDesc gTaskDescHumLexTmh = { gTaskNameHumLexTmh, task_hum_lex_tmh_0, task_hum_lex_tmh_1, task_hum_lex_tmh_2, task_hum_lex_tmh_3, 0x4C };

TaskDesc gTaskDescHumLexTmh0 = { gTaskNameHumLexTmh0, task_hum_lex_tmh0_0, task_hum_lex_tmh0_1, task_hum_lex_tmh0_2, task_hum_lex_tmh0_3, 0x38 };

TaskDesc gTaskDescHumLexRock = { gTaskNameHumLexRock, task_hum_lex_rock_0, task_hum_lex_rock_1, task_hum_lex_rock_2, task_hum_lex_rock_3, 0x2C4 };

TaskDesc gTaskDescHumMahluxiaFlw = { gTaskNameHumMahluxiaFlw, task_hum_mahluxia_flw_0, task_hum_mahluxia_flw_1, task_hum_mahluxia_flw_2, task_hum_mahluxia_flw_3, 0x3C };

TaskDesc gTaskDescHumRiku = { gTaskNameHumRiku, task_hum_riku_0, task_hum_riku_1, task_hum_riku_2, task_hum_riku_3, 0x384 };

TaskDesc gTaskDescHumLeon = { gTaskNameHumLeon, task_hum_leon_0, task_hum_leon_1, task_hum_leon_2, task_hum_leon_3, 0x19C };

TaskDesc gTaskDescHumRobe = { gTaskNameHumRobe, task_hum_robe_0, task_hum_robe_1, task_hum_robe_2, task_hum_robe_3, 0x18C };
