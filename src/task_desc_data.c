#include "taskpool.h"

extern const char gUnk_0813B9DC[];
extern const char gUnk_0813B9EC[];
extern const char gUnk_0813B9FC[];
extern const char gUnk_0813BA0C[];
extern const char gUnk_0813BA1C[];
extern const char gUnk_0813C29C[];
extern const char gUnk_0813C7C8[];
extern const char gUnk_0813C7F8[];
extern const char gUnk_0813C808[];
extern const char gUnk_0813C818[];
extern const char gUnk_0813C828[];
extern const char gUnk_0813C838[];
extern const char gUnk_0813C848[];
extern const char gUnk_0813C858[];
extern const char gUnk_0813C868[];
extern const char gUnk_0813C878[];
extern const char gUnk_0813C88C[];
extern const char gUnk_0813CDCC[];
extern const char gUnk_0813D30C[];
extern const char gUnk_0813D31C[];
extern const char gUnk_0813D3F8[];
extern const char gUnk_0813D480[];
extern const char gUnk_0813D508[];
extern const char gUnk_0813D590[];
extern const char gUnk_0813D608[];
extern const char gUnk_0813D690[];
extern const char gUnk_0813D768[];
extern const char gUnk_0813D830[];
extern const char gUnk_0813D8B8[];
extern const char gUnk_0813D970[];
extern const char gUnk_0813D9F8[];
extern const char gUnk_0813DA04[];
extern const char gUnk_0813DA14[];
extern const char gUnk_0813DAC0[];
extern const char gUnk_0813DB78[];
extern const char gUnk_0813DC20[];
extern const char gUnk_0813DCA8[];
extern const char gUnk_0813DD30[];
extern const char gUnk_0813DDB8[];
extern const char gUnk_0813DE40[];
extern const char gUnk_0813DEC8[];
extern const char gUnk_0813DF70[];
extern const char gUnk_0813DFF8[];
extern const char gUnk_0813E0E0[];
extern const char gUnk_0813E178[];
extern const char gUnk_0813E290[];
extern const char gUnk_0813E318[];
extern const char gUnk_0813E3A0[];
extern const char gUnk_0813E428[];
extern const char gUnk_0813E4B0[];
extern const char gUnk_0813E568[];
extern const char gUnk_0813E630[];
extern const char gUnk_0813E6D8[];
extern const char gUnk_0813E6E4[];
extern const char gUnk_0813E6F4[];
extern const char gUnk_0813E770[];
extern const char gUnk_0813E7F0[];
extern const char gUnk_0813E860[];
extern const char gUnk_0813E870[];
extern const char gUnk_0813E880[];
extern const char gUnk_0813E890[];
extern const char gUnk_0813E8A0[];
extern const char gUnk_0813E8B0[];
extern const char gUnk_0813E8C4[];
extern const char gUnk_0813E8D4[];
extern const char gUnk_0813E8E4[];
extern const char gUnk_0813E944[];
extern const char gUnk_0813E9D8[];
extern const char gUnk_0813E9F8[];
extern const char gUnk_0813EA38[];
extern const char gUnk_0813EA48[];
extern const char gUnk_0813EA6C[];
extern const char gUnk_0813EACC[];
extern const char gUnk_0813EB0C[];
extern const char gUnk_0813EB3C[];
extern const char gUnk_0813EB7C[];
extern const char gUnk_0813EBEC[];
extern const char gUnk_0813EC4C[];
extern const char gUnk_0813EC8C[];
extern const char gUnk_0813ECEC[];
extern const char gUnk_0813ED3C[];
extern const char gUnk_0813ED7C[];
extern const char gUnk_0813EDB0[];
extern const char gUnk_0813EDC0[];
extern const char gUnk_0813EF44[];
extern const char gUnk_0813F080[];
extern const char gUnk_0813F090[];
extern const char gUnk_0813F0A4[];
extern const char gUnk_0813F204[];
extern const char gUnk_0813F340[];
extern const char gUnk_0813F46C[];
extern const char gUnk_0813F5A4[];
extern const char gUnk_0813F5B4[];
extern const char gUnk_0813F784[];
extern const char gUnk_0813F794[];
extern const char gUnk_0813F8E4[];
extern const char gUnk_0813F8F4[];
extern const char gUnk_0813F908[];
extern const char gUnk_0813F9EC[];
extern const char gUnk_0813FA78[];
extern const char gUnk_0813FB54[];
extern const char gUnk_0813FB68[];
extern const char gUnk_0813FB7C[];
extern const char gUnk_0813FB90[];
extern const char gUnk_0813FBA4[];
extern const char gUnk_0813FD48[];
extern const char gUnk_0813FDC4[];
extern const char gUnk_0813FE10[];

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

TaskDesc gTaskDescEvtObj = { gUnk_0813B9DC, task_evt_obj_0, task_evt_obj_1, task_evt_obj_2, task_evt_obj_3, 0x38 };

TaskDesc gTaskDescEvtShadow = { gUnk_0813B9EC, task_evt_shadow_0, task_evt_shadow_1, task_evt_shadow_2, task_evt_shadow_3, 0x14 };

TaskDesc gTaskDescAcgtrans = { gUnk_0813B9FC, task_acgtrans_0, task_acgtrans_1, 0, 0, 0x14 };

TaskDesc gTaskDescBtlLockon = { gUnk_0813BA0C, task_btl_lockon_0, task_btl_lockon_1, task_btl_lockon_2, task_btl_lockon_3, 0x28 };

TaskDesc gTaskDescBtlArea = { gUnk_0813BA1C, task_btl_area_0, task_btl_area_1, task_btl_area_2, task_btl_area_3, 0xC };

TaskDesc gTaskDescBtlSora = { gUnk_0813C29C, task_btl_sora_0, task_btl_sora_1, task_btl_sora_2, task_btl_sora_3, 0x1AC };

TaskDesc gTaskDescBtlRiku = { gUnk_0813C7C8, task_btl_riku_0, task_btl_riku_1, task_btl_riku_2, task_btl_riku_3, 0x374 };

TaskDesc gTaskDescBtlMap = { gUnk_0813C7F8, task_btl_map_0, task_btl_map_1, 0, 0, 0x10 };

TaskDesc gTaskDescBtlShadow = { gUnk_0813C808, task_btl_shadow_0, task_btl_shadow_1, task_btl_shadow_2, task_btl_shadow_3, 0x10 };

TaskDesc gTaskDescBtlHpply = { gUnk_0813C818, task_btl_hpply_0, task_btl_hpply_1, task_btl_hpply_2, task_btl_hpply_3, 0x6C };

TaskDesc gTaskDescBtlHpenm = { gUnk_0813C828, task_btl_hpenm_0, task_btl_hpenm_1, task_btl_hpenm_2, task_btl_hpenm_3, 0x24 };

TaskDesc gTaskDescBtlPause = { gUnk_0813C838, task_btl_pause_0, task_btl_pause_1, task_btl_pause_2, task_btl_pause_3, 0x28 };

TaskDesc gTaskDescBtlPop = { gUnk_0813C848, task_btl_pop_0, task_btl_pop_1, task_btl_pop_2, task_btl_pop_3, 0x34 };

TaskDesc gTaskDescBtlEscape = { gUnk_0813C858, task_btl_escape_0, task_btl_escape_1, task_btl_escape_2, task_btl_escape_3, 0x24 };

TaskDesc gTaskDescBtlPrize = { gUnk_0813C868, task_btl_prize_0, task_btl_prize_1, task_btl_prize_2, task_btl_prize_3, 0x4C };

TaskDesc gTaskDescBtlPremire = { gUnk_0813C878, task_btl_premire_0, task_btl_premire_1, task_btl_premire_2, task_btl_premire_3, 0x60 };

TaskDesc gTaskDescBtlStart = { gUnk_0813C88C, task_btl_start_0, task_btl_start_1, 0, 0, 0x4 };

TaskDesc gTaskDescFldSora = { gUnk_0813CDCC, task_fld_sora_0, task_fld_sora_1, task_fld_sora_2, task_fld_sora_3, 0xC0 };

TaskDesc gTaskDescFldRiku = { gUnk_0813D30C, task_fld_riku_0, task_fld_riku_1, task_fld_riku_2, task_fld_riku_3, 0xC0 };

TaskDesc gTaskDescFldShadow = { gUnk_0813D31C, task_fld_shadow_0, task_fld_shadow_1, task_fld_shadow_2, task_fld_shadow_3, 0x2C };

TaskDesc gTaskDescEmy00 = { gUnk_0813D3F8, task_emy_00_0, task_emy_00_1, task_emy_00_2, task_emy_00_3, 0x184 };

TaskDesc gTaskDescEmy01 = { gUnk_0813D480, task_emy_01_0, task_emy_01_1, task_emy_01_2, task_emy_01_3, 0x184 };

TaskDesc gTaskDescEmy02 = { gUnk_0813D508, task_emy_02_0, task_emy_02_1, task_emy_02_2, task_emy_02_3, 0x184 };

TaskDesc gTaskDescEmy03 = { gUnk_0813D590, task_emy_03_0, task_emy_03_1, task_emy_03_2, task_emy_03_3, 0x190 };

TaskDesc gTaskDescEmy04 = { gUnk_0813D608, task_emy_04_0, task_emy_04_1, task_emy_04_2, task_emy_04_3, 0x188 };

TaskDesc gTaskDescEmy06 = { gUnk_0813D690, task_emy_06_0, task_emy_06_1, task_emy_06_2, task_emy_06_3, 0x188 };

TaskDesc gTaskDescEmy07 = { gUnk_0813D768, task_emy_07_0, task_emy_07_1, task_emy_07_2, task_emy_07_3, 0x188 };

TaskDesc gTaskDescEmy08 = { gUnk_0813D830, task_emy_08_0, task_emy_08_1, task_emy_08_2, task_emy_08_3, 0x190 };

TaskDesc gTaskDescEmy14 = { gUnk_0813D8B8, task_emy_14_0, task_emy_14_1, task_emy_14_2, task_emy_14_3, 0x184 };

TaskDesc gTaskDescEmy15 = { gUnk_0813D970, task_emy_15_0, task_emy_15_1, task_emy_15_2, task_emy_15_3, 0x184 };

TaskDesc gTaskDescEmy16 = { gUnk_0813D9F8, task_emy_16_0, task_emy_16_1, task_emy_16_2, task_emy_16_3, 0x1A4 };

TaskDesc gTaskDescEmy16B = { gUnk_0813DA04, task_emy_16_b_0, task_emy_16_b_1, task_emy_16_b_2, task_emy_16_b_3, 0xA0 };

TaskDesc gTaskDescEmy16P = { gUnk_0813DA14, task_emy_16_p_0, task_emy_16_p_1, task_emy_16_p_2, task_emy_16_p_3, 0x34 };

TaskDesc gTaskDescEmy18 = { gUnk_0813DAC0, task_emy_18_0, task_emy_18_1, task_emy_18_2, task_emy_18_3, 0x188 };

TaskDesc gTaskDescEmy19 = { gUnk_0813DB78, task_emy_19_0, task_emy_19_1, task_emy_19_2, task_emy_19_3, 0x188 };

TaskDesc gTaskDescEmy21 = { gUnk_0813DC20, task_emy_21_0, task_emy_21_1, task_emy_21_2, task_emy_21_3, 0x188 };

TaskDesc gTaskDescEmy22 = { gUnk_0813DCA8, task_emy_22_0, task_emy_22_1, task_emy_22_2, task_emy_22_3, 0x188 };

TaskDesc gTaskDescEmy23 = { gUnk_0813DD30, task_emy_23_0, task_emy_23_1, task_emy_23_2, task_emy_23_3, 0x188 };

TaskDesc gTaskDescEmy25 = { gUnk_0813DDB8, task_emy_25_0, task_emy_25_1, task_emy_25_2, task_emy_25_3, 0x184 };

TaskDesc gTaskDescEmy26 = { gUnk_0813DE40, task_emy_26_0, task_emy_26_1, task_emy_26_2, task_emy_26_3, 0x184 };

TaskDesc gTaskDescEmy27 = { gUnk_0813DEC8, task_emy_27_0, task_emy_27_1, task_emy_27_2, task_emy_27_3, 0x184 };

TaskDesc gTaskDescEmy28 = { gUnk_0813DF70, task_emy_28_0, task_emy_28_1, task_emy_28_2, task_emy_28_3, 0x188 };

TaskDesc gTaskDescEmy29 = { gUnk_0813DFF8, task_emy_29_0, task_emy_29_1, task_emy_29_2, task_emy_29_3, 0x188 };

TaskDesc gTaskDescEmy30 = { gUnk_0813E0E0, task_emy_30_0, task_emy_30_1, task_emy_30_2, task_emy_30_3, 0x184 };

TaskDesc gTaskDescEmy31 = { gUnk_0813E178, task_emy_31_0, task_emy_31_1, task_emy_31_2, task_emy_31_3, 0x194 };

TaskDesc gTaskDescEmy37 = { gUnk_0813E290, task_emy_37_0, task_emy_37_1, task_emy_37_2, task_emy_37_3, 0x190 };

TaskDesc gTaskDescEmy38 = { gUnk_0813E318, task_emy_38_0, task_emy_38_1, task_emy_38_2, task_emy_38_3, 0x184 };

TaskDesc gTaskDescEmy39 = { gUnk_0813E3A0, task_emy_39_0, task_emy_39_1, task_emy_39_2, task_emy_39_3, 0x188 };

TaskDesc gTaskDescEmy41 = { gUnk_0813E428, task_emy_41_0, task_emy_41_1, task_emy_41_2, task_emy_41_3, 0x190 };

TaskDesc gTaskDescEmy44 = { gUnk_0813E4B0, task_emy_44_0, task_emy_44_1, task_emy_44_2, task_emy_44_3, 0x184 };

TaskDesc gTaskDescEmy81 = { gUnk_0813E568, task_emy_81_0, task_emy_81_1, task_emy_81_2, task_emy_81_3, 0x194 };

TaskDesc gTaskDescEmy82 = { gUnk_0813E630, task_emy_82_0, task_emy_82_1, task_emy_82_2, task_emy_82_3, 0x188 };

TaskDesc gTaskDescEmy83 = { gUnk_0813E6D8, task_emy_83_0, task_emy_83_1, task_emy_83_2, task_emy_83_3, 0x1A8 };

TaskDesc gTaskDescEmy83B = { gUnk_0813E6E4, task_emy_83_b_0, task_emy_83_b_1, task_emy_83_b_2, task_emy_83_b_3, 0x90 };

TaskDesc gTaskDescEmy83S = { gUnk_0813E6F4, task_emy_83_s_0, task_emy_83_s_1, task_emy_83_s_2, task_emy_83_s_3, 0x24 };

TaskDesc gTaskDescEmyTrumpH = { gUnk_0813E770, task_emy_trump_h_0, task_emy_trump_h_1, task_emy_trump_h_2, task_emy_trump_h_3, 0x184 };

TaskDesc gTaskDescEmyTrumpS = { gUnk_0813E7F0, task_emy_trump_s_0, task_emy_trump_s_1, task_emy_trump_s_2, task_emy_trump_s_3, 0x184 };

TaskDesc gTaskDescEmyTest = { gUnk_0813E860, task_emy_test_0, task_emy_test_1, task_emy_test_2, task_emy_test_3, 0x184 };

TaskDesc gTaskDescBosMap = { gUnk_0813E870, task_bos_map_0, task_bos_map_1, 0, 0, 0x4 };

TaskDesc gTaskDescBosShadow = { gUnk_0813E880, task_bos_shadow_0, task_bos_shadow_1, task_bos_shadow_2, task_bos_shadow_3, 0xC };

TaskDesc gTaskDescRoomcreate = { gUnk_0813E890, task_roomcreate_0, task_roomcreate_1, task_roomcreate_2, task_roomcreate_3, 0x44 };

TaskDesc gTaskDescRomcriEff = { gUnk_0813E8A0, task_romcri_eff_0, task_romcri_eff_1, 0, task_romcri_eff_3, 0x4 };

TaskDesc gTaskDescRomcriEff2 = { gUnk_0813E8B0, task_romcri_eff2_0, task_romcri_eff2_1, 0, task_romcri_eff2_3, 0x4 };

TaskDesc gTaskDescBtlForm = { gUnk_0813E8C4, task_btl_form_0, task_btl_form_1, 0, task_btl_form_3, 0x28 };

TaskDesc gTaskDescBtlBorn = { gUnk_0813E8D4, task_btl_born_0, task_btl_born_1, 0, 0, 0x14 };

TaskDesc gTaskDescBtlRaid = { gUnk_0813E8E4, task_btl_raid_0, task_btl_raid_1, task_btl_raid_2, task_btl_raid_3, 0x6C };

TaskDesc gTaskDescBtlBadstatus = { gUnk_0813E944, task_btl_badstatus_0, task_btl_badstatus_1, task_btl_badstatus_2, task_btl_badstatus_3, 0x30 };

TaskDesc gTaskDescSmnCloud = { gUnk_0813E9D8, task_smn_cloud_0, task_smn_cloud_1, task_smn_cloud_2, task_smn_cloud_3, 0x180 };

TaskDesc gTaskDescSmnBambi = { gUnk_0813E9F8, task_smn_bambi_0, task_smn_bambi_1, task_smn_bambi_2, task_smn_bambi_3, 0x178 };

TaskDesc gTaskDescSmnTink = { gUnk_0813EA38, task_smn_tink_0, task_smn_tink_1, task_smn_tink_2, task_smn_tink_3, 0x180 };

TaskDesc gTaskDescSmnTinkeff = { gUnk_0813EA48, task_smn_tinkeff_0, task_smn_tinkeff_1, task_smn_tinkeff_2, task_smn_tinkeff_3, 0x30 };

TaskDesc gTaskDescSmnSimba = { gUnk_0813EA6C, task_smn_simba_0, task_smn_simba_1, task_smn_simba_2, task_smn_simba_3, 0x158 };

TaskDesc gTaskDescSmnMushu = { gUnk_0813EACC, task_smn_mushu_0, task_smn_mushu_1, task_smn_mushu_2, task_smn_mushu_3, 0x15C };

TaskDesc gTaskDescSmnDumbo = { gUnk_0813EB0C, task_smn_dumbo_0, task_smn_dumbo_1, task_smn_dumbo_2, task_smn_dumbo_3, 0x158 };

TaskDesc gTaskDescSmnGenie = { gUnk_0813EB3C, task_smn_genie_0, task_smn_genie_1, task_smn_genie_2, task_smn_genie_3, 0x168 };

TaskDesc gTaskDescSmnKing = { gUnk_0813EB7C, task_smn_king_0, task_smn_king_1, task_smn_king_2, task_smn_king_3, 0x168 };

TaskDesc gTaskDescFrdDonald = { gUnk_0813EBEC, task_frd_donald_0, task_frd_donald_1, task_frd_donald_2, task_frd_donald_3, 0x164 };

TaskDesc gTaskDescFrdGoofy = { gUnk_0813EC4C, task_frd_goofy_0, task_frd_goofy_1, task_frd_goofy_2, task_frd_goofy_3, 0x164 };

TaskDesc gTaskDescFrdAriel = { gUnk_0813EC8C, task_frd_ariel_0, task_frd_ariel_1, task_frd_ariel_2, task_frd_ariel_3, 0x164 };

TaskDesc gTaskDescFrdJack = { gUnk_0813ECEC, task_frd_jack_0, task_frd_jack_1, task_frd_jack_2, task_frd_jack_3, 0x16C };

TaskDesc gTaskDescFrdPan = { gUnk_0813ED3C, task_frd_pan_0, task_frd_pan_1, task_frd_pan_2, task_frd_pan_3, 0x170 };

TaskDesc gTaskDescFrdAladdin = { gUnk_0813ED7C, task_frd_aladdin_0, task_frd_aladdin_1, task_frd_aladdin_2, task_frd_aladdin_3, 0x160 };

TaskDesc gTaskDescFrdBeast = { gUnk_0813EDB0, task_frd_beast_0, task_frd_beast_1, task_frd_beast_2, task_frd_beast_3, 0x160 };

TaskDesc gTaskDescPcAcddmg = { gUnk_0813EDC0, task_pc_acddmg_0, task_pc_acddmg_1, 0, 0, 0xC };

TaskDesc gTaskDescHumCloud = { gUnk_0813EF44, task_hum_cloud_0, task_hum_cloud_1, task_hum_cloud_2, task_hum_cloud_3, 0x194 };

TaskDesc gTaskDescHumHook = { gUnk_0813F080, task_hum_hook_0, task_hum_hook_1, task_hum_hook_2, task_hum_hook_3, 0x1BC };

TaskDesc gTaskDescHumHookMoon = { gUnk_0813F090, task_hum_hook_moon_0, task_hum_hook_moon_1, task_hum_hook_moon_2, task_hum_hook_moon_3, 0xC };

TaskDesc gTaskDescHumHookBomb = { gUnk_0813F0A4, task_hum_hook_bomb_0, task_hum_hook_bomb_1, task_hum_hook_bomb_2, task_hum_hook_bomb_3, 0x54 };

TaskDesc gTaskDescHumAnsem = { gUnk_0813F204, task_hum_ansem_0, task_hum_ansem_1, task_hum_ansem_2, task_hum_ansem_3, 0x1DC };

TaskDesc gTaskDescHumHades = { gUnk_0813F340, task_hum_hades_0, task_hum_hades_1, task_hum_hades_2, task_hum_hades_3, 0x280 };

TaskDesc gTaskDescHumMahluxia = { gUnk_0813F46C, task_hum_mahluxia_0, task_hum_mahluxia_1, task_hum_mahluxia_2, task_hum_mahluxia_3, 0x3A4 };

TaskDesc gTaskDescHumLaxene = { gUnk_0813F5A4, task_hum_laxene_0, task_hum_laxene_1, task_hum_laxene_2, task_hum_laxene_3, 0x1A8 };

TaskDesc gTaskDescHumLaxeneKnf = { gUnk_0813F5B4, task_hum_laxene_knf_0, task_hum_laxene_knf_1, task_hum_laxene_knf_2, task_hum_laxene_knf_3, 0x44 };

TaskDesc gTaskDescHumAxcel = { gUnk_0813F784, task_hum_axcel_0, task_hum_axcel_1, task_hum_axcel_2, task_hum_axcel_3, 0x238 };

TaskDesc gTaskDescHumAxcelPtc = { gUnk_0813F794, task_hum_axcel_ptc_0, task_hum_axcel_ptc_1, task_hum_axcel_ptc_2, task_hum_axcel_ptc_3, 0x30 };

TaskDesc gTaskDescHumVixen = { gUnk_0813F8E4, task_hum_vixen_0, task_hum_vixen_1, task_hum_vixen_2, task_hum_vixen_3, 0x218 };

TaskDesc gTaskDescHumVixenNdl = { gUnk_0813F8F4, task_hum_vixen_ndl_0, task_hum_vixen_ndl_1, task_hum_vixen_ndl_2, task_hum_vixen_ndl_3, 0x30 };

TaskDesc gTaskDescHumVixenIce = { gUnk_0813F908, task_hum_vixen_ice_0, task_hum_vixen_ice_1, task_hum_vixen_ice_2, task_hum_vixen_ice_3, 0x94 };

TaskDesc gTaskDescHumVixenFrz = { gUnk_0813F9EC, task_hum_vixen_frz_0, task_hum_vixen_frz_1, task_hum_vixen_frz_2, task_hum_vixen_frz_3, 0x38 };

TaskDesc gTaskDescHumVixenFrg = { gUnk_0813FA78, task_hum_vixen_frg_0, task_hum_vixen_frg_1, task_hum_vixen_frg_2, task_hum_vixen_frg_3, 0x220 };

TaskDesc gTaskDescHumLexceus = { gUnk_0813FB54, task_hum_lexceus_0, task_hum_lexceus_1, task_hum_lexceus_2, task_hum_lexceus_3, 0x204 };

TaskDesc gTaskDescHumLexTmh = { gUnk_0813FB68, task_hum_lex_tmh_0, task_hum_lex_tmh_1, task_hum_lex_tmh_2, task_hum_lex_tmh_3, 0x4C };

TaskDesc gTaskDescHumLexTmh0 = { gUnk_0813FB7C, task_hum_lex_tmh0_0, task_hum_lex_tmh0_1, task_hum_lex_tmh0_2, task_hum_lex_tmh0_3, 0x38 };

TaskDesc gTaskDescHumLexRock = { gUnk_0813FB90, task_hum_lex_rock_0, task_hum_lex_rock_1, task_hum_lex_rock_2, task_hum_lex_rock_3, 0x2C4 };

TaskDesc gTaskDescHumMahluxiaFlw = { gUnk_0813FBA4, task_hum_mahluxia_flw_0, task_hum_mahluxia_flw_1, task_hum_mahluxia_flw_2, task_hum_mahluxia_flw_3, 0x3C };

TaskDesc gTaskDescHumRiku = { gUnk_0813FD48, task_hum_riku_0, task_hum_riku_1, task_hum_riku_2, task_hum_riku_3, 0x384 };

TaskDesc gTaskDescHumLeon = { gUnk_0813FDC4, task_hum_leon_0, task_hum_leon_1, task_hum_leon_2, task_hum_leon_3, 0x19C };

TaskDesc gTaskDescHumRobe = { gUnk_0813FE10, task_hum_robe_0, task_hum_robe_1, task_hum_robe_2, task_hum_robe_3, 0x18C };
