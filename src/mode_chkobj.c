#include "mode_chkobj_assets.h"
#include "mode_chkobj.h"
#include "mode_chkbtl.h"
#include "gba/keys.h"
#include "sprites_bos4.h"
#include "sprites_btl.h"
#include "sprites_card.h"
#include "sprites_card_pictures.h"
#include "sprites_cloud.h"
#include "sprites_continue.h"
#include "sprites_emy.h"
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_frd.h"
#include "sprites_hum.h"
#include "sprites_map.h"
#include "sprites_map_tasks.h"
#include "sprites_mode_test.h"
#include "sprites_msg.h"
#include "sprites_pooh.h"
#include "sprites_riku.h"
#include "sprites_sio2.h"
#include "sprites_smn.h"
#include "sprites_sora.h"

extern ObjDef gUnk_09ECEB74[];
extern ObjDef gUnk_09ED82D4[];
extern ObjDef gUnk_09ECF354[];
extern ObjDef gUnk_09ED07B4[];
extern ObjDef gUnk_09ED09F4[];
extern ObjDef gUnk_09ED1774[];
extern ObjDef gUnk_09ED4834[];
extern ObjDef gUnk_09ED5D34[];
extern ObjDef gUnk_09ED76F4[];
extern ObjDef gUnk_09ED77D4[];

const char gUnk_0812858C[16] = "sor1ll75.aob";
const char gUnk_0812859C[16] = "sor1ll74.aob";
const char gUnk_081285AC[16] = "sor1ll73.aob";
const char gUnk_081285BC[16] = "sor1ll72.aob";
const char gUnk_081285CC[16] = "sor1ll71.aob";
const char gUnk_081285DC[16] = "sor1ll70.aob";
const char gUnk_081285EC[16] = "sor1ll69.aob";
const char gUnk_081285FC[16] = "sor1ll68w.aob";
const char gUnk_0812860C[16] = "sor1ll68.aob";
const char gUnk_0812861C[16] = "sor1ll67.aob";
const char gUnk_0812862C[16] = "sor1ll66.aob";
const char gUnk_0812863C[16] = "sor1ll65.aob";
const char gUnk_0812864C[16] = "sor1ll60.aob";
const char gUnk_0812865C[16] = "sor1ll59.aob";
const char gUnk_0812866C[16] = "sor1ll58.aob";
const char gUnk_0812867C[16] = "sor1ll57.aob";
const char gUnk_0812868C[16] = "sor1ll56.aob";
const char gUnk_0812869C[16] = "sor1ll55.aob";
const char gUnk_081286AC[16] = "sor1ll54.aob";
const char gUnk_081286BC[16] = "sor1ll53.aob";
const char gUnk_081286CC[16] = "sor1ll51.aob";
const char gUnk_081286DC[16] = "sor1ll50.aob";
const char gUnk_081286EC[16] = "sor1bb15.aob";
const char gUnk_081286FC[16] = "sor1bl15.aob";
const char gUnk_0812870C[16] = "sor1ll15.aob";
const char gUnk_0812871C[16] = "sor1fl15.aob";
const char gUnk_0812872C[16] = "sor1ff15.aob";
const char gUnk_0812873C[16] = "sor1bl11.aob";
const char gUnk_0812874C[16] = "sor1bb11.aob";
const char gUnk_0812875C[16] = "sor1bb61.aob";
const char gUnk_0812876C[16] = "sor1bl61.aob";
const char gUnk_0812877C[16] = "sor1ll61.aob";
const char gUnk_0812878C[16] = "sor1fl61.aob";
const char gUnk_0812879C[16] = "sor1ff61.aob";
const char gUnk_081287AC[16] = "sor1bb10.aob";
const char gUnk_081287BC[16] = "sor1ll10.aob";
const char gUnk_081287CC[16] = "sor1bl10.aob";
const char gUnk_081287DC[16] = "sor1fl10.aob";
const char gUnk_081287EC[16] = "sor1ff10.aob";
const char gUnk_081287FC[16] = "sor1ll09.aob";
const char gUnk_0812880C[16] = "sor1ll08.aob";
const char gUnk_0812881C[16] = "sor1ll07.aob";
const char gUnk_0812882C[16] = "sor1bl05.aob";
const char gUnk_0812883C[16] = "sor1bb03.aob";
const char gUnk_0812884C[16] = "sor1bl03.aob";
const char gUnk_0812885C[16] = "sor1ll03.aob";
const char gUnk_0812886C[16] = "sor1fl03.aob";
const char gUnk_0812887C[16] = "sor1ff03.aob";
const char gUnk_0812888C[16] = "sor1bb02.aob";
const char gUnk_0812889C[16] = "sor1bl02.aob";
const char gUnk_081288AC[16] = "sor1ll02.aob";
const char gUnk_081288BC[16] = "sor1fl02.aob";
const char gUnk_081288CC[16] = "sor1ff02.aob";
const char gUnk_081288DC[16] = "sor1bb01.aob";
const char gUnk_081288EC[16] = "sor1bl01.aob";
const char gUnk_081288FC[16] = "sor1ll01.aob";
const char gUnk_0812890C[16] = "sor1fl01.aob";
const char gUnk_0812891C[16] = "sor1ff01.aob";
const char gUnk_0812892C[16] = "sor1bb00.aob";
const char gUnk_0812893C[16] = "sor1bl00.aob";
const char gUnk_0812894C[16] = "sor1ll00.aob";
const char gUnk_0812895C[16] = "sor1fl00.aob";
const char gUnk_0812896C[12] = "sora.acl";
const char gUnk_08128978[16] = "sor1ff00.aob";
const char gUnk_08128988[16] = "trump_S_10.aob";
const char gUnk_08128998[16] = "trump_S_03.aob";
const char gUnk_081289A8[16] = "trump_S_02b.aob";
const char gUnk_081289B8[12] = "trump_S.acl";
const char gUnk_081289C4[16] = "trump_S_00b.aob";
const char gUnk_081289D4[16] = "trump_H_10.aob";
const char gUnk_081289E4[16] = "trump_H_03.aob";
const char gUnk_081289F4[16] = "trump_H_02b.aob";
const char gUnk_08128A04[12] = "trump_H.acl";
const char gUnk_08128A10[16] = "trump_H_00b.aob";
const char gUnk_08128A20[16] = "emy_83_11b.aob";
const char gUnk_08128A30[16] = "emy_83_11.aob";
const char gUnk_08128A40[16] = "emy_83_10b.aob";
const char gUnk_08128A50[16] = "emy_83_10.aob";
const char gUnk_08128A60[16] = "emy_83_02.aob";
const char gUnk_08128A70[12] = "emy_83.acl";
const char gUnk_08128A7C[16] = "emy_83_00.aob";
const char gUnk_08128A8C[16] = "emy_82_12.aob";
const char gUnk_08128A9C[16] = "emy_82_11.aob";
const char gUnk_08128AAC[16] = "emy_82_10j.aob";
const char gUnk_08128ABC[16] = "emy_82_10.aob";
const char gUnk_08128ACC[16] = "emy_82_02.aob";
const char gUnk_08128ADC[16] = "emy_82_01.aob";
const char gUnk_08128AEC[12] = "emy_82.acl";
const char gUnk_08128AF8[16] = "emy_82_00.aob";
const char gUnk_08128B08[16] = "emy_81_11.aob";
const char gUnk_08128B18[16] = "emy_81_10.aob";
const char gUnk_08128B28[16] = "emy_81_05.aob";
const char gUnk_08128B38[16] = "emy_81_02.aob";
const char gUnk_08128B48[12] = "emy_81.acl";
const char gUnk_08128B54[16] = "emy_81_00.aob";
const char gUnk_08128B64[16] = "emy_44_12.aob";
const char gUnk_08128B74[16] = "emy_44_10.aob";
const char gUnk_08128B84[16] = "emy_44_02.aob";
const char gUnk_08128B94[16] = "emy_44_01.aob";
const char gUnk_08128BA4[12] = "emy_44.acl";
const char gUnk_08128BB0[16] = "emy_44_00.aob";
const char gUnk_08128BC0[16] = "emy_41_11.aob";
const char gUnk_08128BD0[16] = "emy_41_10.aob";
const char gUnk_08128BE0[16] = "emy_41_02.aob";
const char gUnk_08128BF0[16] = "emy_41_01.aob";
const char gUnk_08128C00[12] = "emy_41.acl";
const char gUnk_08128C0C[16] = "emy_41_00.aob";
const char gUnk_08128C1C[16] = "emy_39_11.aob";
const char gUnk_08128C2C[16] = "emy_39_10.aob";
const char gUnk_08128C3C[16] = "emy_39_02.aob";
const char gUnk_08128C4C[16] = "emy_39_01.aob";
const char gUnk_08128C5C[12] = "emy_39.acl";
const char gUnk_08128C68[16] = "emy_39_00.aob";
const char gUnk_08128C78[16] = "emy_38_11.aob";
const char gUnk_08128C88[16] = "emy_38_10.aob";
const char gUnk_08128C98[16] = "emy_38_02.aob";
const char gUnk_08128CA8[16] = "emy_38_01.aob";
const char gUnk_08128CB8[12] = "emy_38.acl";
const char gUnk_08128CC4[16] = "emy_38_00.aob";
const char gUnk_08128CD4[16] = "emy_37_21.aob";
const char gUnk_08128CE4[16] = "emy_37_20.aob";
const char gUnk_08128CF4[16] = "emy_37_11.aob";
const char gUnk_08128D04[16] = "emy_37_10.aob";
const char gUnk_08128D14[16] = "emy_37_02.aob";
const char gUnk_08128D24[16] = "emy_37_01.aob";
const char gUnk_08128D34[12] = "emy_37.acl";
const char gUnk_08128D40[16] = "emy_37_00.aob";
const char gUnk_08128D50[16] = "emy_31_07.aob";
const char gUnk_08128D60[16] = "emy_31_06.aob";
const char gUnk_08128D70[16] = "emy_31_05.aob";
const char gUnk_08128D80[16] = "emy_31_04.aob";
const char gUnk_08128D90[12] = "emy_31.acl";
const char gUnk_08128D9C[16] = "emy_31_00.aob";
const char gUnk_08128DAC[16] = "emy_30_11.aob";
const char gUnk_08128DBC[16] = "emy_30_10.aob";
const char gUnk_08128DCC[16] = "emy_30_02.aob";
const char gUnk_08128DDC[16] = "emy_30_01.aob";
const char gUnk_08128DEC[12] = "emy_30.acl";
const char gUnk_08128DF8[16] = "emy_30_00.aob";
const char gUnk_08128E08[16] = "emy_29_11.aob";
const char gUnk_08128E18[16] = "emy_29_10.aob";
const char gUnk_08128E28[16] = "emy_29_02.aob";
const char gUnk_08128E38[12] = "emy_29.acl";
const char gUnk_08128E44[16] = "emy_29_00.aob";
const char gUnk_08128E54[16] = "emy_28_11.aob";
const char gUnk_08128E64[16] = "emy_28_10.aob";
const char gUnk_08128E74[16] = "emy_28_02.aob";
const char gUnk_08128E84[16] = "emy_28_01.aob";
const char gUnk_08128E94[12] = "emy_28.acl";
const char gUnk_08128EA0[16] = "emy_28_00.aob";
const char gUnk_08128EB0[16] = "emy_27_11.aob";
const char gUnk_08128EC0[16] = "emy_27_10.aob";
const char gUnk_08128ED0[16] = "emy_27_02.aob";
const char gUnk_08128EE0[16] = "emy_27_01.aob";
const char gUnk_08128EF0[12] = "emy_27.acl";
const char gUnk_08128EFC[16] = "emy_27_00.aob";
const char gUnk_08128F0C[16] = "emy_26_11.aob";
const char gUnk_08128F1C[16] = "emy_26_10.aob";
const char gUnk_08128F2C[16] = "emy_26_02.aob";
const char gUnk_08128F3C[16] = "emy_26_01.aob";
const char gUnk_08128F4C[12] = "emy_26.acl";
const char gUnk_08128F58[16] = "emy_26_00.aob";
const char gUnk_08128F68[16] = "emy_25_11.aob";
const char gUnk_08128F78[16] = "emy_25_10.aob";
const char gUnk_08128F88[16] = "emy_25_02.aob";
const char gUnk_08128F98[16] = "emy_25_01.aob";
const char gUnk_08128FA8[12] = "emy_25.acl";
const char gUnk_08128FB4[16] = "emy_25_00.aob";
const char gUnk_08128FC4[16] = "emy_23_11.aob";
const char gUnk_08128FD4[16] = "emy_23_10.aob";
const char gUnk_08128FE4[16] = "emy_23_02.aob";
const char gUnk_08128FF4[16] = "emy_23_01.aob";
const char gUnk_08129004[12] = "emy_23.acl";
const char gUnk_08129010[16] = "emy_23_00.aob";
const char gUnk_08129020[16] = "emy_22_11.aob";
const char gUnk_08129030[16] = "emy_22_10.aob";
const char gUnk_08129040[16] = "emy_22_02.aob";
const char gUnk_08129050[12] = "emy_22.acl";
const char gUnk_0812905C[16] = "emy_22_00.aob";
const char gUnk_0812906C[16] = "emy_21_11f.aob";
const char gUnk_0812907C[16] = "emy_21_11.aob";
const char gUnk_0812908C[16] = "emy_21_10.aob";
const char gUnk_0812909C[16] = "emy_21_03.aob";
const char gUnk_081290AC[16] = "emy_21_02.aob";
const char gUnk_081290BC[16] = "emy_21_01.aob";
const char gUnk_081290CC[12] = "emy_21.acl";
const char gUnk_081290D8[16] = "emy_21_00.aob";
const char gUnk_081290E8[16] = "emy_19_11.aob";
const char gUnk_081290F8[16] = "emy_19_10.aob";
const char gUnk_08129108[16] = "emy_19_02.aob";
const char gUnk_08129118[16] = "emy_19_01.aob";
const char gUnk_08129128[12] = "emy_19.acl";
const char gUnk_08129134[16] = "emy_19_00.aob";
const char gUnk_08129144[16] = "emy_18_11.aob";
const char gUnk_08129154[16] = "emy_18_10.aob";
const char gUnk_08129164[16] = "emy_18_02.aob";
const char gUnk_08129174[16] = "emy_18_01.aob";
const char gUnk_08129184[12] = "emy_18.acl";
const char gUnk_08129190[16] = "emy_18_00.aob";
const char gUnk_081291A0[16] = "emy_16_11b.aob";
const char gUnk_081291B0[16] = "emy_16_11.aob";
const char gUnk_081291C0[16] = "emy_16_10b.aob";
const char gUnk_081291D0[16] = "emy_16_10.aob";
const char gUnk_081291E0[16] = "emy_16_02.aob";
const char gUnk_081291F0[16] = "emy_16_01.aob";
const char gUnk_08129200[12] = "emy_16.acl";
const char gUnk_0812920C[16] = "emy_16_00.aob";
const char gUnk_0812921C[16] = "emy_15_11.aob";
const char gUnk_0812922C[16] = "emy_15_10.aob";
const char gUnk_0812923C[16] = "emy_15_02.aob";
const char gUnk_0812924C[16] = "emy_15_01.aob";
const char gUnk_0812925C[12] = "emy_15.acl";
const char gUnk_08129268[16] = "emy_15_00.aob";
const char gUnk_08129278[16] = "emy_14_ll04.aob";
const char gUnk_08129288[16] = "emy_14_ll03.aob";
const char gUnk_08129298[16] = "emy_14_ll02.aob";
const char gUnk_081292A8[16] = "emy_14_ll01.aob";
const char gUnk_081292B8[12] = "emy_14.acl";
const char gUnk_081292C4[16] = "emy_14_ll00.aob";
const char gUnk_081292D4[12] = "emy_07m.acl";
const char gUnk_081292E0[20] = "emy_07_fl11f.aob";
const char gUnk_081292F4[20] = "emy_07_fl11t.aob";
const char gUnk_08129308[20] = "emy_07_fl10f.aob";
const char gUnk_0812931C[20] = "emy_07_fl10t.aob";
const char gUnk_08129330[16] = "emy_07_fl10.aob";
const char gUnk_08129340[12] = "emy_07b.acl";
const char gUnk_0812934C[16] = "emy_07_fl09.aob";
const char gUnk_0812935C[16] = "emy_07_fl08.aob";
const char gUnk_0812936C[16] = "emy_07_fl07.aob";
const char gUnk_0812937C[16] = "emy_07_fl06.aob";
const char gUnk_0812938C[16] = "emy_07_fl05.aob";
const char gUnk_0812939C[20] = "emy_07_fl04t.aob";
const char gUnk_081293B0[16] = "emy_07_fl04.aob";
const char gUnk_081293C0[16] = "emy_07_fl03.aob";
const char gUnk_081293D0[16] = "emy_07_fl02.aob";
const char gUnk_081293E0[16] = "emy_07_fl01.aob";
const char gUnk_081293F0[12] = "emy_07.acl";
const char gUnk_081293FC[16] = "emy_07_fl00.aob";
const char gUnk_0812940C[16] = "emy_06_11.aob";
const char gUnk_0812941C[16] = "emy_06_10.aob";
const char gUnk_0812942C[16] = "emy_06_03.aob";
const char gUnk_0812943C[12] = "emy_06.acl";
const char gUnk_08129448[16] = "emy_06_00.aob";
const char gUnk_08129458[12] = "emy_04.acl";
const char gUnk_08129464[12] = "emy_03.acl";
const char gUnk_08129470[12] = "emy_02.acl";
const char gUnk_0812947C[12] = "emy_01.acl";
const char gUnk_08129488[16] = "emy_01_l_00.aob";
const char gUnk_08129498[16] = "emy_00_l_12.aob";
const char gUnk_081294A8[16] = "emy_00_l_11.aob";
const char gUnk_081294B8[16] = "emy_00_l_10.aob";
const char gUnk_081294C8[16] = "emy_00_l_09.aob";
const char gUnk_081294D8[16] = "emy_00_l_07.aob";
const char gUnk_081294E8[16] = "emy_00_l_06.aob";
const char gUnk_081294F8[16] = "emy_00_l_04.aob";
const char gUnk_08129508[16] = "emy_00_l_02.aob";
const char gUnk_08129518[12] = "emy_00.acl";
const char gUnk_08129524[16] = "emy_00_l_00.aob";
const char gUnk_08129534[12] = "mickey.acl";
const char gUnk_08129540[16] = "mickey_10.aob";
const char gUnk_08129550[12] = "beast.acl";
const char gUnk_0812955C[20] = "felosiaslange.aob";
const char gUnk_08129570[12] = "genie.acl";
const char gUnk_0812957C[16] = "genie_00.aob";
const char gUnk_0812958C[12] = "peter.acl";
const char gUnk_08129598[16] = "peter_tuki.aob";
const char gUnk_081295A8[12] = "aladdin.acl";
const char gUnk_081295B4[16] = "aladdin_10.aob";
const char gUnk_081295C4[12] = "mushu.acl";
const char gUnk_081295D0[16] = "mushu_10.aob";
const char gUnk_081295E0[12] = "banb.acl";
const char gUnk_081295EC[12] = "banb_00.aob";
const char gUnk_081295F8[12] = "shinba.acl";
const char gUnk_08129604[16] = "shinba_10.aob";
const char gUnk_08129614[16] = "croud_13.aob";
const char gUnk_08129624[16] = "croud_12.aob";
const char gUnk_08129634[16] = "croud_11.aob";
const char gUnk_08129644[16] = "croud_10.aob";
const char gUnk_08129654[16] = "croud_02.aob";
const char gUnk_08129664[12] = "croud.acl";
const char gUnk_08129670[16] = "croud_01.aob";
const char gUnk_08129680[12] = "donald.acl";
const char gUnk_0812968C[20] = "dona_bt_ll00.aob";
const char gUnk_081296A0[16] = "goofy_16.aob";
const char gUnk_081296B0[16] = "goofy_14.aob";
const char gUnk_081296C0[12] = "goofy.acl";
const char gUnk_081296CC[16] = "goofy_05.aob";
const char gUnk_081296DC[28] = "hades_framespread_hi.aob";
const char gUnk_081296F8[24] = "hades_framespread.aob";
const char gUnk_08129710[20] = "hades_angry_hi.aob";
const char gUnk_08129724[24] = "hades_nail_frame.aob";
const char gUnk_0812973C[24] = "hades_figaball_ball.aob";
const char gUnk_08129754[24] = "hades_firashot_fira.aob";
const char gUnk_0812976C[16] = "hades_angry.acl";
const char gUnk_0812977C[16] = "hades_angry.aob";
const char gUnk_0812978C[24] = "hades_nailofframe.aob";
const char gUnk_081297A4[20] = "hades_figaball.aob";
const char gUnk_081297B8[20] = "hades_firashot.aob";
const char gUnk_081297CC[20] = "hades_walk_f.aob";
const char gUnk_081297E0[20] = "hades_damage.aob";
const char gUnk_081297F4[24] = "hades_float_back.aob";
const char gUnk_0812980C[12] = "hades.acl";
const char gUnk_08129818[24] = "hades_float_follow.aob";
const char gUnk_08129830[20] = "ansemback_bt05.aob";
const char gUnk_08129844[20] = "ansemback_bt04.aob";
const char gUnk_08129858[20] = "ansemback_bt03b.aob";
const char gUnk_0812986C[20] = "ansemback_bt03.aob";
const char gUnk_08129880[20] = "ansemback_bt02.aob";
const char gUnk_08129894[20] = "ansemback_bt01.aob";
const char gUnk_081298A8[16] = "ansemback.acl";
const char gUnk_081298B8[20] = "ansemback_bt00.aob";
const char gUnk_081298CC[16] = "ansem_bt05.aob";
const char gUnk_081298DC[16] = "ansem_bt04.aob";
const char gUnk_081298EC[16] = "ansem_bt03.aob";
const char gUnk_081298FC[16] = "ansem_bt01.aob";
const char gUnk_0812990C[12] = "ansem.acl";
const char gUnk_08129918[16] = "ansem_bt00.aob";
const char gUnk_08129928[16] = "p_bakudan.acl";
const char gUnk_08129938[16] = "p_bakudan.aob";
const char gUnk_08129948[16] = "hook_bt12.aob";
const char gUnk_08129958[16] = "hook_bt11.aob";
const char gUnk_08129968[16] = "hook_bt10.aob";
const char gUnk_08129978[16] = "hook_bt03.aob";
const char gUnk_08129988[16] = "hook_bt02.aob";
const char gUnk_08129998[16] = "hook_bt01.aob";
const char gUnk_081299A8[12] = "hook.acl";
const char gUnk_081299B4[16] = "hook_bt00.aob";
const char gUnk_081299C4[16] = "croud_bt03.aob";
const char gUnk_081299D4[16] = "croud_bt02.aob";
const char gUnk_081299E4[16] = "croud_bt01.aob";
const char gUnk_081299F4[16] = "croud_bt00.aob";
const char gUnk_08129A04[16] = "croud_00.aob";
const char gUnk_08129A14[20] = "maruxha_bt_eff2.aob";
const char gUnk_08129A28[20] = "maruxha_bt_eff.acl";
const char gUnk_08129A3C[20] = "maruxha_bt_eff1.aob";
const char gUnk_08129A50[20] = "maruxha_atk4.aob";
const char gUnk_08129A64[20] = "maruxha_atk3.aob";
const char gUnk_08129A78[20] = "maruxha_atk2.aob";
const char gUnk_08129A8C[20] = "maruxha_atk1.aob";
const char gUnk_08129AA0[20] = "maruxha_damege.aob";
const char gUnk_08129AB4[20] = "maruxha_move.aob";
const char gUnk_08129AC8[12] = "maruxha.acl";
const char gUnk_08129AD4[20] = "maruxha_idle.aob";
const char gUnk_08129AE8[16] = "b_states.acl";
const char gUnk_08129AF8[20] = "accele_bt06_wep.aob";
const char gUnk_08129B0C[16] = "accele_bt06.aob";
const char gUnk_08129B1C[16] = "accele_bt05.aob";
const char gUnk_08129B2C[20] = "accele_bt_wep.aob";
const char gUnk_08129B40[16] = "accele_bt04.aob";
const char gUnk_08129B50[16] = "accele_bt03.aob";
const char gUnk_08129B60[16] = "accele_bt02.aob";
const char gUnk_08129B70[16] = "accele_bt01.aob";
const char gUnk_08129B80[12] = "accele.acl";
const char gUnk_08129B8C[16] = "accele_bt00.aob";
const char gUnk_08129B9C[24] = "vixen_reitou_hahen.aob";
const char gUnk_08129BB4[16] = "reitou_nise.aob";
const char gUnk_08129BC4[16] = "reitou_riku.aob";
const char gUnk_08129BD4[16] = "reitou_sora.aob";
const char gUnk_08129BE4[20] = "vixen_reitou.aob";
const char gUnk_08129BF8[16] = "vixen_e_2.aob";
const char gUnk_08129C08[12] = "vix_e.acl";
const char gUnk_08129C14[16] = "vixen_e_1.aob";
const char gUnk_08129C24[16] = "vixen_m_4.aob";
const char gUnk_08129C34[16] = "vixen_m_2a.aob";
const char gUnk_08129C44[16] = "vixen_m_1b.aob";
const char gUnk_08129C54[16] = "vixen_m_1a.aob";
const char gUnk_08129C64[16] = "vixen_w_1.aob";
const char gUnk_08129C74[16] = "vixen_a_1.aob";
const char gUnk_08129C84[16] = "vixen_d_1.aob";
const char gUnk_08129C94[12] = "vixen.acl";
const char gUnk_08129CA0[16] = "vixen_s_1.aob";
const char gUnk_08129CB0[24] = "niseriku_darkfiga.aob";
const char gUnk_08129CC8[24] = "niseriku_yami_end.aob";
const char gUnk_08129CE0[24] = "niseriku_yami_ing.aob";
const char gUnk_08129CF8[24] = "niseriku_yami_start.aob";
const char gUnk_08129D10[20] = "niseriku_kabuto.aob";
const char gUnk_08129D24[24] = "niseriku_tategiri.aob";
const char gUnk_08129D3C[24] = "niseriku_furiharai.aob";
const char gUnk_08129D54[20] = "niseriku_dash.aob";
const char gUnk_08129D68[20] = "niseriku_jump.aob";
const char gUnk_08129D7C[20] = "niseriku_damage.aob";
const char gUnk_08129D90[20] = "niseriku_run.aob";
const char gUnk_08129DA4[16] = "niseriku.acl";
const char gUnk_08129DB4[20] = "niseriku_idol.aob";
const char gUnk_08129DC8[24] = "laxine_knifethrow.aob";
const char gUnk_08129DE0[20] = "laxine_knife.aob";
const char gUnk_08129DF4[20] = "laxine_magic.aob";
const char gUnk_08129E08[20] = "laxine_renzok.aob";
const char gUnk_08129E1C[20] = "laxine_damage.aob";
const char gUnk_08129E30[16] = "laxine_move.aob";
const char gUnk_08129E40[12] = "laxine.acl";
const char gUnk_08129E4C[16] = "laxine_idle.aob";
const char gUnk_08129E5C[20] = "rexeus__rock_02.acl";
const char gUnk_08129E70[20] = "rexeus__rock_02.aob";
const char gUnk_08129E84[20] = "rexeus__rock_01.acl";
const char gUnk_08129E98[20] = "rexeus__rock_01.aob";
const char gUnk_08129EAC[16] = "rexeus_imp.aob";
const char gUnk_08129EBC[16] = "rexeus_rck.aob";
const char gUnk_08129ECC[20] = "rexeus_tmh_ax.aob";
const char gUnk_08129EE0[16] = "rexeus_tmh.aob";
const char gUnk_08129EF0[16] = "rexeus_cmb2.aob";
const char gUnk_08129F00[16] = "rexeus_cmb1.aob";
const char gUnk_08129F10[16] = "rexeus_dmg.aob";
const char gUnk_08129F20[16] = "rexeus_mov.aob";
const char gUnk_08129F30[12] = "rexeus.acl";
const char gUnk_08129F3C[16] = "rexeus_idl.aob";
const char gUnk_08129F4C[16] = "mickey_08.aob";
const char gUnk_08129F5C[16] = "mickey_07.aob";
const char gUnk_08129F6C[16] = "mickey_06.aob";
const char gUnk_08129F7C[16] = "mickey_05.aob";
const char gUnk_08129F8C[16] = "mickey_04.aob";
const char gUnk_08129F9C[16] = "mickey_03.aob";
const char gUnk_08129FAC[16] = "mickey_02.aob";
const char gUnk_08129FBC[16] = "mickey_01.aob";
const char gUnk_08129FCC[16] = "mickey_bl00.aob";
const char gUnk_08129FDC[16] = "mickey_fl00.aob";
const char gUnk_08129FEC[16] = "nise_bl00.aob";
const char gUnk_08129FFC[20] = "niseriku_te_f.aob";
const char gUnk_0812A010[24] = "niseriku_shock_b.aob";
const char gUnk_0812A028[24] = "niseriku_shock_f.aob";
const char gUnk_0812A040[20] = "niseriku_down_f.aob";
const char gUnk_0812A054[20] = "niseriku_run_b.aob";
const char gUnk_0812A068[20] = "niseriku_run_f.aob";
const char gUnk_0812A07C[20] = "niseriku_walk_b.aob";
const char gUnk_0812A090[20] = "niseriku_walk_f.aob";
const char gUnk_0812A0A4[24] = "niseriku_warai_f.aob";
const char gUnk_0812A0BC[24] = "niseriku_ryote_b.aob";
const char gUnk_0812A0D4[24] = "niseriku_ryote_f.aob";
const char gUnk_0812A0EC[24] = "niseriku_omamori_f.aob";
const char gUnk_0812A104[24] = "niseriku_kamae_b.aob";
const char gUnk_0812A11C[24] = "niseriku_kamae_f.aob";
const char gUnk_0812A134[20] = "niseriku_hiza_f.aob";
const char gUnk_0812A148[24] = "niseriku_fuiuchi_f.aob";
const char gUnk_0812A160[16] = "nise_fl00.aob";
const char gUnk_0812A170[16] = "yuffie_bl01.aob";
const char gUnk_0812A180[16] = "yuffie_fl01.aob";
const char gUnk_0812A190[16] = "yuffie_bl00.aob";
const char gUnk_0812A1A0[12] = "yuffie.acl";
const char gUnk_0812A1AC[16] = "yuffie_fl00.aob";
const char gUnk_0812A1BC[16] = "wendy_bl00.aob";
const char gUnk_0812A1CC[12] = "wendy.acl";
const char gUnk_0812A1D8[16] = "wendy_fl00.aob";
const char gUnk_0812A1E8[16] = "tidus_fl01.aob";
const char gUnk_0812A1F8[16] = "tidus_bl00.aob";
const char gUnk_0812A208[12] = "tidus.acl";
const char gUnk_0812A214[16] = "tidus_fl00.aob";
const char gUnk_0812A224[20] = "genie_foot00.aob";
const char gUnk_0812A238[16] = "genie_08.aob";
const char gUnk_0812A248[16] = "genie_07.aob";
const char gUnk_0812A258[16] = "genie_06.aob";
const char gUnk_0812A268[16] = "genie_05.aob";
const char gUnk_0812A278[16] = "genie_04.aob";
const char gUnk_0812A288[16] = "genie_03.aob";
const char gUnk_0812A298[16] = "genie_02.aob";
const char gUnk_0812A2A8[16] = "genie_01.aob";
const char gUnk_0812A2B8[16] = "genie_b00.aob";
const char gUnk_0812A2C8[16] = "genie_f00.aob";
const char gUnk_0812A2D8[16] = "wakka_fl01.aob";
const char gUnk_0812A2E8[12] = "wakka.acl";
const char gUnk_0812A2F4[16] = "wakka_f00.aob";
const char gUnk_0812A304[16] = "dona2_bl04.aob";
const char gUnk_0812A314[16] = "dona2_bl03.aob";
const char gUnk_0812A324[16] = "dona2_bl02.aob";
const char gUnk_0812A334[16] = "dona2_bl01.aob";
const char gUnk_0812A344[16] = "dona2_bl00.aob";
const char gUnk_0812A354[12] = "donald2.acl";
const char gUnk_0812A360[16] = "dona2_fl00.aob";
const char gUnk_0812A370[16] = "reon_card.aob";
const char gUnk_0812A380[16] = "reon_event.aob";
const char gUnk_0812A390[20] = "reon_bl_walk.aob";
const char gUnk_0812A3A4[20] = "reon_fl_walk.aob";
const char gUnk_0812A3B8[16] = "reon_bl00.aob";
const char gUnk_0812A3C8[12] = "reon.acl";
const char gUnk_0812A3D4[16] = "reon_fl00.aob";
const char gUnk_0812A3E4[16] = "jaffer_lamp.aob";
const char gUnk_0812A3F4[20] = "jaffer_walk_b.aob";
const char gUnk_0812A408[20] = "jaffer_fl_walk.aob";
const char gUnk_0812A41C[16] = "jaffer_bl00.aob";
const char gUnk_0812A42C[12] = "jaffer.acl";
const char gUnk_0812A438[16] = "jaffer_fl00.aob";
const char gUnk_0812A448[16] = "jasmine_03.aob";
const char gUnk_0812A458[16] = "jasmine_02.aob";
const char gUnk_0812A468[16] = "jasmine_01.aob";
const char gUnk_0812A478[12] = "jasmine.acl";
const char gUnk_0812A484[20] = "jasmine_f_00.aob";
const char gUnk_0812A498[20] = "selphie_fl02.aob";
const char gUnk_0812A4AC[20] = "selphie_bl01.aob";
const char gUnk_0812A4C0[20] = "selphie_fl01.aob";
const char gUnk_0812A4D4[20] = "selphie_bl00.aob";
const char gUnk_0812A4E8[12] = "selphie.acl";
const char gUnk_0812A4F4[20] = "selphie_fl00.aob";
const char gUnk_0812A508[16] = "shido_f02.aob";
const char gUnk_0812A518[16] = "shido_f01.aob";
const char gUnk_0812A528[16] = "shido_b00.aob";
const char gUnk_0812A538[12] = "shido.acl";
const char gUnk_0812A544[16] = "shido_f00.aob";
const char gUnk_0812A554[16] = "goofy2_13.aob";
const char gUnk_0812A564[16] = "goofy2_10.aob";
const char gUnk_0812A574[16] = "goofy2_09.aob";
const char gUnk_0812A584[16] = "goofy2_07.aob";
const char gUnk_0812A594[16] = "goofy2_03.aob";
const char gUnk_0812A5A4[16] = "goofy2_02.aob";
const char gUnk_0812A5B4[16] = "goofy2_01.aob";
const char gUnk_0812A5C4[16] = "goofy2_bl00.aob";
const char gUnk_0812A5D4[12] = "goofy2.acl";
const char gUnk_0812A5E0[16] = "goofy2_fl00.aob";
const char gUnk_0812A5F0[16] = "hook_b02.aob";
const char gUnk_0812A600[16] = "hook_b00.aob";
const char gUnk_0812A610[16] = "hook_f03.aob";
const char gUnk_0812A620[16] = "hook_f02.aob";
const char gUnk_0812A630[16] = "hook_f01.aob";
const char gUnk_0812A640[16] = "hook_f00.aob";
const char gUnk_0812A650[12] = "drug.aob";
const char gUnk_0812A65C[16] = "sari_drug_.aob";
const char gUnk_0812A66C[16] = "sari_walk.aob";
const char gUnk_0812A67C[16] = "sari_bl00.aob";
const char gUnk_0812A68C[12] = "sari.acl";
const char gUnk_0812A698[16] = "sari_fl00.aob";
const char gUnk_0812A6A8[20] = "accele_wepon.aob";
const char gUnk_0812A6BC[16] = "accele_bl03.aob";
const char gUnk_0812A6CC[16] = "accele_bl02.aob";
const char gUnk_0812A6DC[16] = "accele_bl01.aob";
const char gUnk_0812A6EC[16] = "accele_bl00.aob";
const char gUnk_0812A6FC[16] = "accele_fl07.aob";
const char gUnk_0812A70C[16] = "accele_fl06.aob";
const char gUnk_0812A71C[16] = "accele_fl05.aob";
const char gUnk_0812A72C[16] = "accele_fl04.aob";
const char gUnk_0812A73C[16] = "accele_fl03.aob";
const char gUnk_0812A74C[16] = "accele_fl02.aob";
const char gUnk_0812A75C[16] = "accele_fl01.aob";
const char gUnk_0812A76C[16] = "accele_fl00.aob";
const char gUnk_0812A77C[24] = "sebastian_bl_swim.aob";
const char gUnk_0812A794[24] = "sebastian_fl_swim.aob";
const char gUnk_0812A7AC[20] = "sebastian_bl00.aob";
const char gUnk_0812A7C0[16] = "sebastian.acl";
const char gUnk_0812A7D0[20] = "sebastian_fl00.aob";
const char gUnk_0812A7E4[16] = "tink_b00.aob";
const char gUnk_0812A7F4[12] = "tink.acl";
const char gUnk_0812A800[16] = "tink_f00.aob";
const char gUnk_0812A810[12] = "ear_b01.aob";
const char gUnk_0812A81C[12] = "ear_f01.aob";
const char gUnk_0812A828[12] = "ear_b00.aob";
const char gUnk_0812A834[12] = "earis.acl";
const char gUnk_0812A840[12] = "ear_f00.aob";
const char gUnk_0812A84C[12] = "kairi.acl";
const char gUnk_0812A858[16] = "kair_f00.aob";
const char gUnk_0812A868[16] = "mushu_f00.aob";
const char gUnk_0812A878[16] = "shinba_f00.aob";
const char gUnk_0812A888[16] = "banb_stand.aob";
const char gUnk_0812A898[16] = "maref_b00.aob";
const char gUnk_0812A8A8[16] = "maref_04.aob";
const char gUnk_0812A8B8[16] = "maref_03.aob";
const char gUnk_0812A8C8[16] = "maref_02.aob";
const char gUnk_0812A8D8[16] = "maref_01.aob";
const char gUnk_0812A8E8[12] = "maref.acl";
const char gUnk_0812A8F4[16] = "maref_f00.aob";
const char gUnk_0812A904[16] = "finkl_02.aob";
const char gUnk_0812A914[16] = "finkl_01.aob";
const char gUnk_0812A924[16] = "finkl_b00.aob";
const char gUnk_0812A934[12] = "finkl.acl";
const char gUnk_0812A940[16] = "finkl_f00.aob";
const char gUnk_0812A950[12] = "dambo.acl";
const char gUnk_0812A95C[12] = "dambo.aob";
const char gUnk_0812A968[16] = "hades_magic.aob";
const char gUnk_0812A978[20] = "hades_walk_b.aob";
const char gUnk_0812A98C[16] = "hades_bl00.aob";
const char gUnk_0812A99C[16] = "hades_fl00.aob";
const char gUnk_0812A9AC[24] = "heracles_odoroki_f.aob";
const char gUnk_0812A9C4[20] = "heracles_hiza_f.aob";
const char gUnk_0812A9D8[24] = "heracles_kamae_f.aob";
const char gUnk_0812A9F0[20] = "heracles_walk_b.aob";
const char gUnk_0812AA04[20] = "heracles_run_b.aob";
const char gUnk_0812AA18[24] = "heracles_fl_walk.aob";
const char gUnk_0812AA30[20] = "heracles_bl00.aob";
const char gUnk_0812AA44[16] = "heracles.acl";
const char gUnk_0812AA54[20] = "heracles_fl00.aob";
const char gUnk_0812AA68[20] = "phil_bl_walk.aob";
const char gUnk_0812AA7C[16] = "phil_bl00.aob";
const char gUnk_0812AA8C[12] = "phil.acl";
const char gUnk_0812AA98[16] = "phil_fl00.aob";
const char gUnk_0812AAA8[16] = "bell_fl02.aob";
const char gUnk_0812AAB8[16] = "bell_fl03.aob";
const char gUnk_0812AAC8[16] = "bell_bl01.aob";
const char gUnk_0812AAD8[16] = "bell_fl01.aob";
const char gUnk_0812AAE8[16] = "bell_bl00.aob";
const char gUnk_0812AAF8[12] = "bell.acl";
const char gUnk_0812AB04[16] = "bell_fl00.aob";
const char gUnk_0812AB14[16] = "bugi_bl01.aob";
const char gUnk_0812AB24[16] = "bugi_bl00.aob";
const char gUnk_0812AB34[16] = "bugi_fl03.aob";
const char gUnk_0812AB44[16] = "bugi_fl02.aob";
const char gUnk_0812AB54[16] = "bugi_fl01.aob";
const char gUnk_0812AB64[12] = "bugi.acl";
const char gUnk_0812AB70[16] = "bugi_fl00.aob";
const char gUnk_0812AB80[20] = "arthra_f_aogu.aob";
const char gUnk_0812AB94[20] = "arthra_f_tefuri.aob";
const char gUnk_0812ABA8[20] = "arthra_f_aruku.aob";
const char gUnk_0812ABBC[20] = "arthra_f_warau.aob";
const char gUnk_0812ABD0[16] = "arthra_bl00.aob";
const char gUnk_0812ABE0[12] = "arthra.acl";
const char gUnk_0812ABEC[16] = "arthra_fl00.aob";
const char gUnk_0812ABFC[16] = "croud_b04.aob";
const char gUnk_0812AC0C[16] = "croud_b03.aob";
const char gUnk_0812AC1C[16] = "croud_b02.aob";
const char gUnk_0812AC2C[16] = "croud_b01.aob";
const char gUnk_0812AC3C[16] = "croud_b00.aob";
const char gUnk_0812AC4C[16] = "croud_f02.aob";
const char gUnk_0812AC5C[16] = "croud_f01.aob";
const char gUnk_0812AC6C[16] = "croud_f00.aob";
const char gUnk_0812AC7C[16] = "geppetto_01.aob";
const char gUnk_0812AC8C[20] = "geppetto_b00.aob";
const char gUnk_0812ACA0[16] = "geppetto.acl";
const char gUnk_0812ACB0[20] = "geppetto_f00.aob";
const char gUnk_0812ACC4[16] = "cheshire.acl";
const char gUnk_0812ACD4[16] = "cheshire.aob";
const char gUnk_0812ACE4[20] = "beast_odoroki_b.aob";
const char gUnk_0812ACF8[20] = "beast_odoroki_f.aob";
const char gUnk_0812AD0C[20] = "beast_kamae_b.aob";
const char gUnk_0812AD20[16] = "beast_run_b.aob";
const char gUnk_0812AD30[20] = "beast_syucyo_f.aob";
const char gUnk_0812AD44[20] = "beast_bl_walk.aob";
const char gUnk_0812AD58[16] = "beast_bl00.aob";
const char gUnk_0812AD68[20] = "beast_fl_walk.aob";
const char gUnk_0812AD7C[16] = "beast_fl00.aob";
const char gUnk_0812AD8C[16] = "ariel_f01.aob";
const char gUnk_0812AD9C[20] = "ariel_swim_b.aob";
const char gUnk_0812ADB0[20] = "ariel_swim_f.aob";
const char gUnk_0812ADC4[16] = "ariel_b00.aob";
const char gUnk_0812ADD4[12] = "ariel.acl";
const char gUnk_0812ADE0[16] = "ariel_f00.aob";
const char gUnk_0812ADF0[16] = "peter_bl00.aob";
const char gUnk_0812AE00[16] = "peter_fl00.aob";
const char gUnk_0812AE10[16] = "jack_claim.aob";
const char gUnk_0812AE20[16] = "jack_appeal.aob";
const char gUnk_0812AE30[20] = "jack_run_back.aob";
const char gUnk_0812AE44[20] = "jack_walk_back.aob";
const char gUnk_0812AE58[16] = "jack_run.aob";
const char gUnk_0812AE68[16] = "jack_walk.aob";
const char gUnk_0812AE78[16] = "jack_bl00.aob";
const char gUnk_0812AE88[12] = "jack.acl";
const char gUnk_0812AE94[16] = "jack_fl00.aob";
const char gUnk_0812AEA4[16] = "aladdin_b05.aob";
const char gUnk_0812AEB4[16] = "aladdin_b04.aob";
const char gUnk_0812AEC4[16] = "aladdin_b03.aob";
const char gUnk_0812AED4[16] = "aladdin_b02.aob";
const char gUnk_0812AEE4[16] = "aladdin_b01.aob";
const char gUnk_0812AEF4[16] = "aladdin_b00.aob";
const char gUnk_0812AF04[16] = "aladdin_09.aob";
const char gUnk_0812AF14[16] = "aladdin_08.aob";
const char gUnk_0812AF24[16] = "aladdin_07.aob";
const char gUnk_0812AF34[16] = "aladdin_06.aob";
const char gUnk_0812AF44[16] = "aladdin_05.aob";
const char gUnk_0812AF54[16] = "aladdin_04.aob";
const char gUnk_0812AF64[16] = "aladdin_03.aob";
const char gUnk_0812AF74[16] = "aladdin_02.aob";
const char gUnk_0812AF84[16] = "aladdin_01.aob";
const char gUnk_0812AF94[16] = "aladdin_00.aob";
const char gUnk_0812AFA4[16] = "usagi_04.aob";
const char gUnk_0812AFB4[16] = "usagi_03.aob";
const char gUnk_0812AFC4[16] = "usagi_02.aob";
const char gUnk_0812AFD4[16] = "usagi_01.aob";
const char gUnk_0812AFE4[16] = "usagib00.aob";
const char gUnk_0812AFF4[12] = "usagi00.acl";
const char gUnk_0812B000[16] = "usagif00.aob";
const char gUnk_0812B010[16] = "mogu_bl00.aob";
const char gUnk_0812B020[12] = "mogu.acl";
const char gUnk_0812B02C[16] = "mogu_fl00.aob";
const char gUnk_0812B03C[16] = "pino_b03.aob";
const char gUnk_0812B04C[16] = "pino_f03.aob";
const char gUnk_0812B05C[16] = "pino_bl02.aob";
const char gUnk_0812B06C[16] = "pino_bl01.aob";
const char gUnk_0812B07C[16] = "pino_b00.aob";
const char gUnk_0812B08C[16] = "pino_fl02.aob";
const char gUnk_0812B09C[16] = "pino_fl01.aob";
const char gUnk_0812B0AC[12] = "pinokio.acl";
const char gUnk_0812B0B8[16] = "pino_f00.aob";
const char gUnk_0812B0C8[16] = "jim_bl01.aob";
const char gUnk_0812B0D8[16] = "jim_fl01.aob";
const char gUnk_0812B0E8[16] = "jim_bl00.aob";
const char gUnk_0812B0F8[12] = "jiminy.acl";
const char gUnk_0812B104[16] = "jim_fl00.aob";
const char gUnk_0812B114[16] = "alice_bl00.aob";
const char gUnk_0812B124[12] = "alice.acl";
const char gUnk_0812B130[16] = "alice_fl00.aob";
const char gUnk_0812B140[12] = "qen_std.aob";
const char gUnk_0812B14C[12] = "qen_b01.aob";
const char gUnk_0812B158[12] = "qen_b00.aob";
const char gUnk_0812B164[12] = "qen_f02.aob";
const char gUnk_0812B170[12] = "qen_f01.aob";
const char gUnk_0812B17C[12] = "qeen.acl";
const char gUnk_0812B188[12] = "qen_f00.aob";
const char gUnk_0812B194[16] = "trump_S_02.aob";
const char gUnk_0812B1A4[16] = "trump_S_01.aob";
const char gUnk_0812B1B4[16] = "trump_S_00.aob";
const char gUnk_0812B1C4[16] = "trump_H_02.aob";
const char gUnk_0812B1D4[16] = "trump_H_01.aob";
const char gUnk_0812B1E4[16] = "trump_H_00.aob";
const char gUnk_0812B1F4[16] = "robe_bl00.aob";
const char gUnk_0812B204[12] = "robe.acl";
const char gUnk_0812B210[16] = "robe_fl00.aob";
const char gUnk_0812B220[20] = "sora_continue.aob";
const char gUnk_0812B234[16] = "sor1bl29.aob";
const char gUnk_0812B244[16] = "sor1bl26.aob";
const char gUnk_0812B254[16] = "sor1bl25.aob";
const char gUnk_0812B264[16] = "sor1bl24.aob";
const char gUnk_0812B274[16] = "sor1bl23.aob";
const char gUnk_0812B284[16] = "sor1bl22.aob";
const char gUnk_0812B294[16] = "sor1bl21.aob";
const char gUnk_0812B2A4[16] = "sor1bl20.aob";
const char gUnk_0812B2B4[16] = "sor1fl29.aob";
const char gUnk_0812B2C4[16] = "sor1fl28.aob";
const char gUnk_0812B2D4[16] = "sor1fl27.aob";
const char gUnk_0812B2E4[16] = "sor1fl26.aob";
const char gUnk_0812B2F4[16] = "sor1fl23.aob";
const char gUnk_0812B304[16] = "sor1fl20.aob";
const char gUnk_0812B314[16] = "dona_ll00.aob";
const char gUnk_0812B324[16] = "dona_bl00.aob";
const char gUnk_0812B334[16] = "dona_fl00.aob";
const char gUnk_0812B344[16] = "dona_ff00.aob";
const char gUnk_0812B354[16] = "dona_bb00.aob";
const char gUnk_0812B364[16] = "goofy_20.aob";
const char gUnk_0812B374[16] = "goofy_19.aob";
const char gUnk_0812B384[16] = "goofy_18.aob";
const char gUnk_0812B394[16] = "goofy_17.aob";
const char gUnk_0812B3A4[16] = "goofy_13.aob";
const char gUnk_0812B3B4[16] = "goofy_12.aob";
const char gUnk_0812B3C4[16] = "goofy_11.aob";
const char gUnk_0812B3D4[16] = "goofy_10.aob";
const char gUnk_0812B3E4[16] = "goofy_09.aob";
const char gUnk_0812B3F4[16] = "goofy_08.aob";
const char gUnk_0812B404[16] = "goofy_07.aob";
const char gUnk_0812B414[16] = "goofy_06.aob";
const char gUnk_0812B424[16] = "goofy_04.aob";
const char gUnk_0812B434[16] = "goofy_03.aob";
const char gUnk_0812B444[16] = "goofy_02.aob";
const char gUnk_0812B454[16] = "goofy_01.aob";
const char gUnk_0812B464[16] = "goofy_fl00.aob";
const char gUnk_0812B474[16] = "goofy_ll00.aob";
const char gUnk_0812B484[16] = "goofy_ff00.aob";
const char gUnk_0812B494[16] = "goofy_bl00.aob";
const char gUnk_0812B4A4[16] = "goofy_bb00.aob";
const char gUnk_0812B4B4[24] = "maruxha2_fl03_wep.aob";
const char gUnk_0812B4CC[20] = "maruxha2_fl03.aob";
const char gUnk_0812B4E0[20] = "maruxha2_bl02.aob";
const char gUnk_0812B4F4[20] = "maruxha2_bl01.aob";
const char gUnk_0812B508[20] = "maruxha2_bl00.aob";
const char gUnk_0812B51C[20] = "maruxha2_fl02.aob";
const char gUnk_0812B530[20] = "maruxha2_fl01.aob";
const char gUnk_0812B544[20] = "maruxha2_fl00.aob";
const char gUnk_0812B558[16] = "laxine_bl04.aob";
const char gUnk_0812B568[16] = "laxine_bl00.aob";
const char gUnk_0812B578[16] = "laxine_fl10.aob";
const char gUnk_0812B588[16] = "laxine_fl09.aob";
const char gUnk_0812B598[16] = "laxine_fl06.aob";
const char gUnk_0812B5A8[16] = "laxine_fl04.aob";
const char gUnk_0812B5B8[16] = "laxine_fl03.aob";
const char gUnk_0812B5C8[16] = "laxine_fl00.aob";
const char gUnk_0812B5D8[16] = "rexeus_p_1.aob";
const char gUnk_0812B5E8[16] = "rexeus_k_1.aob";
const char gUnk_0812B5F8[16] = "rexeus_h_1.aob";
const char gUnk_0812B608[20] = "rexeus_fl_walk.aob";
const char gUnk_0812B61C[16] = "rexeus_bl00.aob";
const char gUnk_0812B62C[16] = "rexeus_fl00.aob";
const char gUnk_0812B63C[16] = "ansem_fl04.aob";
const char gUnk_0812B64C[16] = "ansem_fl03.aob";
const char gUnk_0812B65C[16] = "ansem_bl00.aob";
const char gUnk_0812B66C[16] = "ansem_fl02.aob";
const char gUnk_0812B67C[16] = "ansem_fl01.aob";
const char gUnk_0812B68C[16] = "ansem_fl00.aob";
const char gUnk_0812B69C[8] = "diz.acl";
const char gUnk_0812B6A4[16] = "diz_fl00.aob";
const char gUnk_0812B6B4[12] = "omamori.acl";
const char gUnk_0812B6C0[12] = "f_item.aob";
const char gUnk_0812B6CC[16] = "nami_walk_b.aob";
const char gUnk_0812B6DC[16] = "nami_run_b.aob";
const char gUnk_0812B6EC[16] = "nami_run_f.aob";
const char gUnk_0812B6FC[16] = "nami_b00.aob";
const char gUnk_0812B70C[16] = "nami_f01.aob";
const char gUnk_0812B71C[12] = "namine.acl";
const char gUnk_0812B728[16] = "nami_f00.aob";
const char gUnk_0812B738[20] = "riku_continue.aob";
const char gUnk_0812B74C[16] = "riku_ev10.aob";
const char gUnk_0812B75C[16] = "riku_ev09.aob";
const char gUnk_0812B76C[16] = "riku_ev08.aob";
const char gUnk_0812B77C[16] = "riku_ev07.aob";
const char gUnk_0812B78C[16] = "riku_ev06.aob";
const char gUnk_0812B79C[16] = "riku_ev05.aob";
const char gUnk_0812B7AC[16] = "riku_ev04.aob";
const char gUnk_0812B7BC[16] = "riku_ev03.aob";
const char gUnk_0812B7CC[16] = "riku_ev02.aob";
const char gUnk_0812B7DC[16] = "riku_ev01.aob";
const char gUnk_0812B7EC[16] = "riku_ev00.aob";
const char gUnk_0812B7FC[16] = "rik1bb02.aob";
const char gUnk_0812B80C[16] = "rik1bl02.aob";
const char gUnk_0812B81C[16] = "rik1ll02.aob";
const char gUnk_0812B82C[16] = "rik1fl02.aob";
const char gUnk_0812B83C[16] = "rik1ff02.aob";
const char gUnk_0812B84C[16] = "rik1bl01.aob";
const char gUnk_0812B85C[16] = "rik1ll01.aob";
const char gUnk_0812B86C[16] = "rik1fl01.aob";
const char gUnk_0812B87C[16] = "rik1bl24.aob";
const char gUnk_0812B88C[16] = "rik1bl23.aob";
const char gUnk_0812B89C[16] = "rik1bl22.aob";
const char gUnk_0812B8AC[16] = "rik1bl21.aob";
const char gUnk_0812B8BC[16] = "rik1bl20.aob";
const char gUnk_0812B8CC[16] = "rik1fl24.aob";
const char gUnk_0812B8DC[16] = "rik1fl21.aob";
const char gUnk_0812B8EC[16] = "rik1fl20.aob";
const char gUnk_0812B8FC[16] = "riku_bl00.aob";
const char gUnk_0812B90C[16] = "riku_fl00.aob";
const char gUnk_0812B91C[12] = "riku.acl";
const char gUnk_0812B928[16] = "riku_ff00.aob";
const char gUnk_0812B938[16] = "vixen_fl04.aob";
const char gUnk_0812B948[16] = "vixen_bl01.aob";
const char gUnk_0812B958[16] = "vixen_bl00.aob";
const char gUnk_0812B968[16] = "vixen_fl03.aob";
const char gUnk_0812B978[16] = "vixen_fl02.aob";
const char gUnk_0812B988[16] = "vixen_fl00.aob";
const char gUnk_0812B998[12] = "koukyu.acl";
const char gUnk_0812B9A4[12] = "koukyu.aob";
const char gUnk_0812B9B0[16] = "shougekiha2.aob";
const char gUnk_0812B9C0[16] = "shougekiha.acl";
const char gUnk_0812B9D0[16] = "shougekiha.aob";
const char gUnk_0812B9E0[12] = "pooh.acl";
const char gUnk_0812B9EC[16] = "pooh_fl08.aob";
const char gUnk_0812B9FC[20] = "mareficent_ball.acl";
const char gUnk_0812BA10[20] = "mareficent_ball.aob";
const char gUnk_0812BA24[20] = "flounder_swim_f.aob";
const char gUnk_0812BA38[20] = "flounder_bl00.aob";
const char gUnk_0812BA4C[16] = "flounder.acl";
const char gUnk_0812BA5C[20] = "flounder_fl00.aob";
const char gUnk_0812BA70[16] = "xexion_bl00.aob";
const char gUnk_0812BA80[12] = "xexion.acl";
const char gUnk_0812BA8C[16] = "xexion_fl00.aob";
const char gUnk_0812BA9C[12] = "f_event.aob";
const char gUnk_0812BAA8[16] = "talk_61_00.acl";
const char gUnk_0812BAB8[16] = "talk_61_00.aob";
const char gUnk_0812BAC8[16] = "talk_60_00.acl";
const char gUnk_0812BAD8[16] = "talk_60_00.aob";
const char gUnk_0812BAE8[16] = "talk_59_00.acl";
const char gUnk_0812BAF8[16] = "talk_59_00.aob";
const char gUnk_0812BB08[16] = "talk_58_00.acl";
const char gUnk_0812BB18[16] = "talk_58_00.aob";
const char gUnk_0812BB28[16] = "talk_57_02.aob";
const char gUnk_0812BB38[16] = "talk_57_00.acl";
const char gUnk_0812BB48[16] = "talk_57_00.aob";
const char gUnk_0812BB58[16] = "talk_56_02.aob";
const char gUnk_0812BB68[16] = "talk_56_00.acl";
const char gUnk_0812BB78[16] = "talk_56_00.aob";
const char gUnk_0812BB88[16] = "talk_55_03.aob";
const char gUnk_0812BB98[16] = "talk_55_02.aob";
const char gUnk_0812BBA8[16] = "talk_55_00.acl";
const char gUnk_0812BBB8[16] = "talk_55_00.aob";
const char gUnk_0812BBC8[16] = "talk_54_02.aob";
const char gUnk_0812BBD8[16] = "talk_54_01.aob";
const char gUnk_0812BBE8[16] = "talk_54_00.acl";
const char gUnk_0812BBF8[16] = "talk_54_00.aob";
const char gUnk_0812BC08[16] = "talk_53_04.aob";
const char gUnk_0812BC18[16] = "talk_53_03.aob";
const char gUnk_0812BC28[16] = "talk_53_02.aob";
const char gUnk_0812BC38[16] = "talk_53_01.aob";
const char gUnk_0812BC48[16] = "talk_53_00.acl";
const char gUnk_0812BC58[16] = "talk_53_00.aob";
const char gUnk_0812BC68[16] = "talk_52_04.aob";
const char gUnk_0812BC78[16] = "talk_52_03.aob";
const char gUnk_0812BC88[16] = "talk_52_02.aob";
const char gUnk_0812BC98[16] = "talk_52_01.aob";
const char gUnk_0812BCA8[16] = "talk_52_00.acl";
const char gUnk_0812BCB8[16] = "talk_52_00.aob";
const char gUnk_0812BCC8[16] = "talk_51_02.aob";
const char gUnk_0812BCD8[16] = "talk_51_00.acl";
const char gUnk_0812BCE8[16] = "talk_51_00.aob";
const char gUnk_0812BCF8[16] = "talk_50_02.aob";
const char gUnk_0812BD08[16] = "talk_50_01.aob";
const char gUnk_0812BD18[16] = "talk_50_00.acl";
const char gUnk_0812BD28[16] = "talk_50_00.aob";
const char gUnk_0812BD38[16] = "talk_49_00.acl";
const char gUnk_0812BD48[16] = "talk_49_00.aob";
const char gUnk_0812BD58[16] = "talk_48_04.aob";
const char gUnk_0812BD68[16] = "talk_48_03.aob";
const char gUnk_0812BD78[16] = "talk_48_02.aob";
const char gUnk_0812BD88[16] = "talk_48_01.aob";
const char gUnk_0812BD98[16] = "talk_48_00.acl";
const char gUnk_0812BDA8[16] = "talk_48_00.aob";
const char gUnk_0812BDB8[16] = "talk_47_00.acl";
const char gUnk_0812BDC8[16] = "talk_47_00.aob";
const char gUnk_0812BDD8[16] = "talk_46_00.acl";
const char gUnk_0812BDE8[16] = "talk_46_00.aob";
const char gUnk_0812BDF8[16] = "talk_45_00.acl";
const char gUnk_0812BE08[16] = "talk_45_00.aob";
const char gUnk_0812BE18[16] = "talk_44_00.acl";
const char gUnk_0812BE28[16] = "talk_44_00.aob";
const char gUnk_0812BE38[16] = "talk_43_00.acl";
const char gUnk_0812BE48[16] = "talk_43_00.aob";
const char gUnk_0812BE58[16] = "talk_42_00.acl";
const char gUnk_0812BE68[16] = "talk_42_00.aob";
const char gUnk_0812BE78[16] = "talk_41_01.aob";
const char gUnk_0812BE88[16] = "talk_41_00.acl";
const char gUnk_0812BE98[16] = "talk_41_00.aob";
const char gUnk_0812BEA8[16] = "talk_40_03.aob";
const char gUnk_0812BEB8[16] = "talk_40_02.aob";
const char gUnk_0812BEC8[16] = "talk_40_01.aob";
const char gUnk_0812BED8[16] = "talk_40_00.acl";
const char gUnk_0812BEE8[16] = "talk_40_00.aob";
const char gUnk_0812BEF8[16] = "talk_39_00.acl";
const char gUnk_0812BF08[16] = "talk_39_00.aob";
const char gUnk_0812BF18[16] = "talk_38_03.aob";
const char gUnk_0812BF28[16] = "talk_38_02.aob";
const char gUnk_0812BF38[16] = "talk_38_00.acl";
const char gUnk_0812BF48[16] = "talk_38_00.aob";
const char gUnk_0812BF58[16] = "talk_37_00.acl";
const char gUnk_0812BF68[16] = "talk_37_00.aob";
const char gUnk_0812BF78[16] = "talk_36_00.acl";
const char gUnk_0812BF88[16] = "talk_36_00.aob";
const char gUnk_0812BF98[16] = "talk_35_02.aob";
const char gUnk_0812BFA8[16] = "talk_35_01.aob";
const char gUnk_0812BFB8[16] = "talk_35_00.acl";
const char gUnk_0812BFC8[16] = "talk_35_00.aob";
const char gUnk_0812BFD8[16] = "talk_34_00.acl";
const char gUnk_0812BFE8[16] = "talk_34_00.aob";
const char gUnk_0812BFF8[16] = "talk_33_04.aob";
const char gUnk_0812C008[16] = "talk_33_03.aob";
const char gUnk_0812C018[16] = "talk_33_02.aob";
const char gUnk_0812C028[16] = "talk_33_01.aob";
const char gUnk_0812C038[16] = "talk_33_00.acl";
const char gUnk_0812C048[16] = "talk_33_00.aob";
const char gUnk_0812C058[16] = "talk_32_02.aob";
const char gUnk_0812C068[16] = "talk_32_01.aob";
const char gUnk_0812C078[16] = "talk_32_00.acl";
const char gUnk_0812C088[16] = "talk_32_00.aob";
const char gUnk_0812C098[16] = "talk_31_03.aob";
const char gUnk_0812C0A8[16] = "talk_31_02.aob";
const char gUnk_0812C0B8[16] = "talk_31_01.aob";
const char gUnk_0812C0C8[16] = "talk_31_00.acl";
const char gUnk_0812C0D8[16] = "talk_31_00.aob";
const char gUnk_0812C0E8[16] = "talk_30_03.aob";
const char gUnk_0812C0F8[16] = "talk_30_02.aob";
const char gUnk_0812C108[16] = "talk_30_01.aob";
const char gUnk_0812C118[16] = "talk_30_00.acl";
const char gUnk_0812C128[16] = "talk_30_00.aob";
const char gUnk_0812C138[16] = "talk_29_04.aob";
const char gUnk_0812C148[16] = "talk_29_03.aob";
const char gUnk_0812C158[16] = "talk_29_02.aob";
const char gUnk_0812C168[16] = "talk_29_01.aob";
const char gUnk_0812C178[16] = "talk_29_00.acl";
const char gUnk_0812C188[16] = "talk_29_00.aob";
const char gUnk_0812C198[16] = "talk_28_05.aob";
const char gUnk_0812C1A8[16] = "talk_28_04.aob";
const char gUnk_0812C1B8[16] = "talk_28_03.aob";
const char gUnk_0812C1C8[16] = "talk_28_02.aob";
const char gUnk_0812C1D8[16] = "talk_28_01.aob";
const char gUnk_0812C1E8[16] = "talk_28_00.acl";
const char gUnk_0812C1F8[16] = "talk_28_00.aob";
const char gUnk_0812C208[16] = "talk_27_00.acl";
const char gUnk_0812C218[16] = "talk_27_00.aob";
const char gUnk_0812C228[16] = "talk_26_01.aob";
const char gUnk_0812C238[16] = "talk_26_00.acl";
const char gUnk_0812C248[16] = "talk_26_00.aob";
const char gUnk_0812C258[16] = "talk_25_05.aob";
const char gUnk_0812C268[16] = "talk_25_04.aob";
const char gUnk_0812C278[16] = "talk_25_03.aob";
const char gUnk_0812C288[16] = "talk_25_02.aob";
const char gUnk_0812C298[16] = "talk_25_01.aob";
const char gUnk_0812C2A8[16] = "talk_25_00.acl";
const char gUnk_0812C2B8[16] = "talk_25_00.aob";
const char gUnk_0812C2C8[16] = "talk_24_05.aob";
const char gUnk_0812C2D8[16] = "talk_24_04.aob";
const char gUnk_0812C2E8[16] = "talk_24_03.aob";
const char gUnk_0812C2F8[16] = "talk_24_02.aob";
const char gUnk_0812C308[16] = "talk_24_01.aob";
const char gUnk_0812C318[16] = "talk_24_00.acl";
const char gUnk_0812C328[16] = "talk_24_00.aob";
const char gUnk_0812C338[16] = "talk_21_04.aob";
const char gUnk_0812C348[16] = "talk_21_03.aob";
const char gUnk_0812C358[16] = "talk_21_02.aob";
const char gUnk_0812C368[16] = "talk_21_01.aob";
const char gUnk_0812C378[16] = "talk_21_00.acl";
const char gUnk_0812C388[16] = "talk_21_00.aob";
const char gUnk_0812C398[16] = "talk_20_03.aob";
const char gUnk_0812C3A8[16] = "talk_20_02.aob";
const char gUnk_0812C3B8[16] = "talk_20_01.aob";
const char gUnk_0812C3C8[16] = "talk_20_00.acl";
const char gUnk_0812C3D8[16] = "talk_20_00.aob";
const char gUnk_0812C3E8[16] = "talk_19_00.acl";
const char gUnk_0812C3F8[16] = "talk_19_00.aob";
const char gUnk_0812C408[16] = "talk_18_00.acl";
const char gUnk_0812C418[16] = "talk_18_00.aob";
const char gUnk_0812C428[16] = "talk_17_00.acl";
const char gUnk_0812C438[16] = "talk_17_00.aob";
const char gUnk_0812C448[16] = "talk_16_00.acl";
const char gUnk_0812C458[16] = "talk_16_00.aob";
const char gUnk_0812C468[16] = "talk_15_03.aob";
const char gUnk_0812C478[16] = "talk_15_02.aob";
const char gUnk_0812C488[16] = "talk_15_00.acl";
const char gUnk_0812C498[16] = "talk_15_00.aob";
const char gUnk_0812C4A8[16] = "talk_14_02.aob";
const char gUnk_0812C4B8[16] = "talk_14_01.aob";
const char gUnk_0812C4C8[16] = "talk_14_00.acl";
const char gUnk_0812C4D8[16] = "talk_14_00.aob";
const char gUnk_0812C4E8[16] = "talk_13_01.aob";
const char gUnk_0812C4F8[16] = "talk_13_00.acl";
const char gUnk_0812C508[16] = "talk_13_00.aob";
const char gUnk_0812C518[16] = "talk_12_03.aob";
const char gUnk_0812C528[16] = "talk_12_02.aob";
const char gUnk_0812C538[16] = "talk_12_01.aob";
const char gUnk_0812C548[16] = "talk_12_00.acl";
const char gUnk_0812C558[16] = "talk_12_00.aob";
const char gUnk_0812C568[16] = "talk_11_04.aob";
const char gUnk_0812C578[16] = "talk_11_03.aob";
const char gUnk_0812C588[16] = "talk_11_02.aob";
const char gUnk_0812C598[16] = "talk_11_01.aob";
const char gUnk_0812C5A8[16] = "talk_11_00.acl";
const char gUnk_0812C5B8[16] = "talk_11_00.aob";
const char gUnk_0812C5C8[16] = "talk_10_04.aob";
const char gUnk_0812C5D8[16] = "talk_10_03.aob";
const char gUnk_0812C5E8[16] = "talk_10_02.aob";
const char gUnk_0812C5F8[16] = "talk_10_00.acl";
const char gUnk_0812C608[16] = "talk_10_00.aob";
const char gUnk_0812C618[16] = "talk_09_00.acl";
const char gUnk_0812C628[16] = "talk_09_00.aob";
const char gUnk_0812C638[16] = "talk_08_00.acl";
const char gUnk_0812C648[16] = "talk_08_00.aob";
const char gUnk_0812C658[16] = "talk_07_00.acl";
const char gUnk_0812C668[16] = "talk_07_00.aob";
const char gUnk_0812C678[16] = "talk_06_00.acl";
const char gUnk_0812C688[16] = "talk_06_00.aob";
const char gUnk_0812C698[16] = "talk_05_00.acl";
const char gUnk_0812C6A8[16] = "talk_05_00.aob";
const char gUnk_0812C6B8[16] = "talk_04_03.aob";
const char gUnk_0812C6C8[16] = "talk_04_02.aob";
const char gUnk_0812C6D8[16] = "talk_04_01.aob";
const char gUnk_0812C6E8[16] = "talk_04_00.acl";
const char gUnk_0812C6F8[16] = "talk_04_00.aob";
const char gUnk_0812C708[16] = "talk_03_00.acl";
const char gUnk_0812C718[16] = "talk_03_00.aob";
const char gUnk_0812C728[16] = "talk_23_00.acl";
const char gUnk_0812C738[16] = "talk_02_04.aob";
const char gUnk_0812C748[16] = "talk_02_03.aob";
const char gUnk_0812C758[16] = "talk_02_02.aob";
const char gUnk_0812C768[16] = "talk_02_01.aob";
const char gUnk_0812C778[16] = "talk_02_00.acl";
const char gUnk_0812C788[16] = "talk_02_00.aob";
const char gUnk_0812C798[16] = "talk_22_00.acl";
const char gUnk_0812C7A8[16] = "talk_01_05.aob";
const char gUnk_0812C7B8[16] = "talk_01_04.aob";
const char gUnk_0812C7C8[16] = "talk_01_03.aob";
const char gUnk_0812C7D8[16] = "talk_01_02.aob";
const char gUnk_0812C7E8[16] = "talk_01_01.aob";
const char gUnk_0812C7F8[16] = "talk_01_00.acl";
const char gUnk_0812C808[16] = "talk_01_00.aob";
const char gUnk_0812C818[16] = "talk_00_05.aob";
const char gUnk_0812C828[16] = "talk_00_04.aob";
const char gUnk_0812C838[16] = "talk_00_03.aob";
const char gUnk_0812C848[16] = "talk_00_02.aob";
const char gUnk_0812C858[16] = "talk_00_01.aob";
const char gUnk_0812C868[16] = "talk_00_00.acl";
const char gUnk_0812C878[16] = "talk_00_00.aob";
const char gUnk_0812C888[16] = "card_eve02.acl";
const char gUnk_0812C898[16] = "card_eve02.aob";
const char gUnk_0812C8A8[16] = "card_eve01.acl";
const char gUnk_0812C8B8[16] = "card_eve01.aob";
const char gUnk_0812C8C8[16] = "card_eve00.acl";
const char gUnk_0812C8D8[16] = "card_eve00.aob";
const char gUnk_0812C8E8[16] = "card_room23.acl";
const char gUnk_0812C8F8[16] = "card_room23.aob";
const char gUnk_0812C908[16] = "card_room22.acl";
const char gUnk_0812C918[16] = "card_room22.aob";
const char gUnk_0812C928[16] = "card_room21.acl";
const char gUnk_0812C938[16] = "card_room21.aob";
const char gUnk_0812C948[16] = "card_room20.acl";
const char gUnk_0812C958[16] = "card_room20.aob";
const char gUnk_0812C968[16] = "card_room19.acl";
const char gUnk_0812C978[16] = "card_room19.aob";
const char gUnk_0812C988[16] = "card_room18.acl";
const char gUnk_0812C998[16] = "card_room18.aob";
const char gUnk_0812C9A8[16] = "card_room17.acl";
const char gUnk_0812C9B8[16] = "card_room17.aob";
const char gUnk_0812C9C8[16] = "card_room16.acl";
const char gUnk_0812C9D8[16] = "card_room16.aob";
const char gUnk_0812C9E8[16] = "card_room15.acl";
const char gUnk_0812C9F8[16] = "card_room15.aob";
const char gUnk_0812CA08[16] = "card_room14.acl";
const char gUnk_0812CA18[16] = "card_room14.aob";
const char gUnk_0812CA28[16] = "card_room13.acl";
const char gUnk_0812CA38[16] = "card_room13.aob";
const char gUnk_0812CA48[16] = "card_room12.acl";
const char gUnk_0812CA58[16] = "card_room12.aob";
const char gUnk_0812CA68[16] = "card_room11.acl";
const char gUnk_0812CA78[16] = "card_room11.aob";
const char gUnk_0812CA88[16] = "card_room10.acl";
const char gUnk_0812CA98[16] = "card_room10.aob";
const char gUnk_0812CAA8[16] = "card_room09.acl";
const char gUnk_0812CAB8[16] = "card_room09.aob";
const char gUnk_0812CAC8[16] = "card_room08.acl";
const char gUnk_0812CAD8[16] = "card_room08.aob";
const char gUnk_0812CAE8[16] = "card_room07.acl";
const char gUnk_0812CAF8[16] = "card_room07.aob";
const char gUnk_0812CB08[16] = "card_room06.acl";
const char gUnk_0812CB18[16] = "card_room06.aob";
const char gUnk_0812CB28[16] = "card_room05.acl";
const char gUnk_0812CB38[16] = "card_room05.aob";
const char gUnk_0812CB48[16] = "card_room04.acl";
const char gUnk_0812CB58[16] = "card_room04.aob";
const char gUnk_0812CB68[16] = "card_room03.acl";
const char gUnk_0812CB78[16] = "card_room03.aob";
const char gUnk_0812CB88[16] = "card_room02.acl";
const char gUnk_0812CB98[16] = "card_room02.aob";
const char gUnk_0812CBA8[16] = "card_room01.acl";
const char gUnk_0812CBB8[16] = "card_room01.aob";
const char gUnk_0812CBC8[20] = "card_npc_lm02.acl";
const char gUnk_0812CBDC[20] = "card_npc_lm02.aob";
const char gUnk_0812CBF0[20] = "card_npc_lm01.acl";
const char gUnk_0812CC04[20] = "card_npc_lm01.aob";
const char gUnk_0812CC18[20] = "card_npc_nm02.acl";
const char gUnk_0812CC2C[20] = "card_npc_nm02.aob";
const char gUnk_0812CC40[20] = "card_npc_nm01.acl";
const char gUnk_0812CC54[20] = "card_npc_nm01.aob";
const char gUnk_0812CC68[20] = "card_npc_pi02.acl";
const char gUnk_0812CC7C[20] = "card_npc_pi02.aob";
const char gUnk_0812CC90[20] = "card_npc_pi01.acl";
const char gUnk_0812CCA4[20] = "card_npc_pi01.aob";
const char gUnk_0812CCB8[20] = "card_npc_pp01.acl";
const char gUnk_0812CCCC[20] = "card_npc_pp01.aob";
const char gUnk_0812CCE0[20] = "card_npc_pc02.acl";
const char gUnk_0812CCF4[20] = "card_npc_pc02.aob";
const char gUnk_0812CD08[20] = "card_npc_pc01.acl";
const char gUnk_0812CD1C[20] = "card_npc_pc01.aob";
const char gUnk_0812CD30[20] = "card_npc_po07.acl";
const char gUnk_0812CD44[20] = "card_npc_po07.aob";
const char gUnk_0812CD58[20] = "card_npc_po06.acl";
const char gUnk_0812CD6C[20] = "card_npc_po06.aob";
const char gUnk_0812CD80[20] = "card_npc_po05.acl";
const char gUnk_0812CD94[20] = "card_npc_po05.aob";
const char gUnk_0812CDA8[20] = "card_npc_po04.acl";
const char gUnk_0812CDBC[20] = "card_npc_po04.aob";
const char gUnk_0812CDD0[20] = "card_npc_po03.acl";
const char gUnk_0812CDE4[20] = "card_npc_po03.aob";
const char gUnk_0812CDF8[20] = "card_npc_po02.acl";
const char gUnk_0812CE0C[20] = "card_npc_po02.aob";
const char gUnk_0812CE20[20] = "card_npc_po01.acl";
const char gUnk_0812CE34[20] = "card_npc_po01.aob";
const char gUnk_0812CE48[20] = "card_npc_he02.acl";
const char gUnk_0812CE5C[20] = "card_npc_he02.aob";
const char gUnk_0812CE70[20] = "card_npc_he01.acl";
const char gUnk_0812CE84[20] = "card_npc_he01.aob";
const char gUnk_0812CE98[20] = "card_npc_di03.acl";
const char gUnk_0812CEAC[20] = "card_npc_di03.aob";
const char gUnk_0812CEC0[20] = "card_npc_di02.acl";
const char gUnk_0812CED4[20] = "card_npc_di02.aob";
const char gUnk_0812CEE8[20] = "card_npc_di01.acl";
const char gUnk_0812CEFC[20] = "card_npc_di01.aob";
const char gUnk_0812CF10[20] = "card_npc_ex10.acl";
const char gUnk_0812CF24[20] = "card_npc_ex10.aob";
const char gUnk_0812CF38[20] = "card_npc_ex09.acl";
const char gUnk_0812CF4C[20] = "card_npc_ex09.aob";
const char gUnk_0812CF60[20] = "card_npc_ex08.acl";
const char gUnk_0812CF74[20] = "card_npc_ex08.aob";
const char gUnk_0812CF88[20] = "card_npc_ex07.acl";
const char gUnk_0812CF9C[20] = "card_npc_ex07.aob";
const char gUnk_0812CFB0[20] = "card_npc_ex06.acl";
const char gUnk_0812CFC4[20] = "card_npc_ex06.aob";
const char gUnk_0812CFD8[20] = "card_npc_ex05.acl";
const char gUnk_0812CFEC[20] = "card_npc_ex05.aob";
const char gUnk_0812D000[20] = "card_npc_ex03.acl";
const char gUnk_0812D014[20] = "card_npc_ex03.aob";
const char gUnk_0812D028[20] = "card_npc_ex02.acl";
const char gUnk_0812D03C[20] = "card_npc_ex02.aob";
const char gUnk_0812D050[20] = "card_npc_ex01.acl";
const char gUnk_0812D064[20] = "card_npc_ex01.aob";
const char gUnk_0812D078[20] = "card_npc_ex00.acl";
const char gUnk_0812D08C[20] = "card_npc_ex00.aob";
const char gUnk_0812D0A0[20] = "card_npc_aw06.acl";
const char gUnk_0812D0B4[20] = "card_npc_aw06.aob";
const char gUnk_0812D0C8[20] = "card_npc_aw05.acl";
const char gUnk_0812D0DC[20] = "card_npc_aw05.aob";
const char gUnk_0812D0F0[20] = "card_npc_aw02.acl";
const char gUnk_0812D104[20] = "card_npc_aw02.aob";
const char gUnk_0812D118[20] = "card_npc_aw01.acl";
const char gUnk_0812D12C[20] = "card_npc_aw01.aob";
const char gUnk_0812D140[20] = "card_npc_al03.acl";
const char gUnk_0812D154[20] = "card_npc_al03.aob";
const char gUnk_0812D168[20] = "card_npc_al02.acl";
const char gUnk_0812D17C[20] = "card_npc_al02.aob";
const char gUnk_0812D190[20] = "card_npc_al01.acl";
const char gUnk_0812D1A4[20] = "card_npc_al01.aob";
const char gUnk_0812D1B8[20] = "card_npc_aw04.aob";
const char gUnk_0812D1CC[20] = "card_npc_aw03.aob";
const char gUnk_0812D1E0[20] = "card_bos_18d.acl";
const char gUnk_0812D1F4[20] = "card_bos_18c.acl";
const char gUnk_0812D208[20] = "card_bos_18b.acl";
const char gUnk_0812D21C[20] = "card_bos_18a.acl";
const char gUnk_0812D230[16] = "card_bos_18.acl";
const char gUnk_0812D240[16] = "card_bos_18.aob";
const char gUnk_0812D250[20] = "card_npc_com03.acl";
const char gUnk_0812D264[20] = "card_npc_com03.aob";
const char gUnk_0812D278[20] = "card_npc_com02.acl";
const char gUnk_0812D28C[20] = "card_npc_com02.aob";
const char gUnk_0812D2A0[20] = "card_npc_com01.acl";
const char gUnk_0812D2B4[20] = "card_npc_com01.aob";
const char gUnk_0812D2C8[20] = "card_bos_17c.acl";
const char gUnk_0812D2DC[20] = "card_bos_17d.acl";
const char gUnk_0812D2F0[20] = "card_bos_17b.acl";
const char gUnk_0812D304[20] = "card_bos_17a.acl";
const char gUnk_0812D318[16] = "card_bos_17.acl";
const char gUnk_0812D328[16] = "card_bos_17.aob";
const char gUnk_0812D338[20] = "card_bos_16d.acl";
const char gUnk_0812D34C[20] = "card_bos_16c.acl";
const char gUnk_0812D360[20] = "card_bos_16b.acl";
const char gUnk_0812D374[20] = "card_bos_16a.acl";
const char gUnk_0812D388[16] = "card_bos_16.acl";
const char gUnk_0812D398[16] = "card_bos_16.aob";
const char gUnk_0812D3A8[20] = "card_bos_15d.acl";
const char gUnk_0812D3BC[20] = "card_bos_15c.acl";
const char gUnk_0812D3D0[20] = "card_bos_15b.acl";
const char gUnk_0812D3E4[20] = "card_bos_15a.acl";
const char gUnk_0812D3F8[16] = "card_bos_15.acl";
const char gUnk_0812D408[16] = "card_bos_15.aob";
const char gUnk_0812D418[20] = "card_bos_14d.acl";
const char gUnk_0812D42C[20] = "card_bos_14c.acl";
const char gUnk_0812D440[20] = "card_bos_14b.acl";
const char gUnk_0812D454[20] = "card_bos_14a.acl";
const char gUnk_0812D468[16] = "card_bos_14.acl";
const char gUnk_0812D478[16] = "card_bos_14.aob";
const char gUnk_0812D488[20] = "card_bos_13d.acl";
const char gUnk_0812D49C[20] = "card_bos_13c.acl";
const char gUnk_0812D4B0[20] = "card_bos_13b.acl";
const char gUnk_0812D4C4[20] = "card_bos_13a.acl";
const char gUnk_0812D4D8[16] = "card_bos_13.acl";
const char gUnk_0812D4E8[16] = "card_bos_13.aob";
const char gUnk_0812D4F8[20] = "card_bos_12d.acl";
const char gUnk_0812D50C[20] = "card_bos_12c.acl";
const char gUnk_0812D520[20] = "card_bos_12b.acl";
const char gUnk_0812D534[20] = "card_bos_12a.acl";
const char gUnk_0812D548[16] = "card_bos_12.acl";
const char gUnk_0812D558[16] = "card_bos_12.aob";
const char gUnk_0812D568[20] = "card_bos_11d.acl";
const char gUnk_0812D57C[20] = "card_bos_11c.acl";
const char gUnk_0812D590[20] = "card_bos_11b.acl";
const char gUnk_0812D5A4[20] = "card_bos_11a.acl";
const char gUnk_0812D5B8[16] = "card_bos_11.acl";
const char gUnk_0812D5C8[16] = "card_bos_11.aob";
const char gUnk_0812D5D8[20] = "card_bos_10d.acl";
const char gUnk_0812D5EC[20] = "card_bos_10c.acl";
const char gUnk_0812D600[20] = "card_bos_10b.acl";
const char gUnk_0812D614[20] = "card_bos_10a.acl";
const char gUnk_0812D628[16] = "card_bos_10.acl";
const char gUnk_0812D638[16] = "card_bos_10.aob";
const char gUnk_0812D648[16] = "card_bos_08.acl";
const char gUnk_0812D658[16] = "card_bos_08.aob";
const char gUnk_0812D668[16] = "card_bos_07.acl";
const char gUnk_0812D678[16] = "card_bos_07.aob";
const char gUnk_0812D688[16] = "card_bos_06.acl";
const char gUnk_0812D698[16] = "card_bos_06.aob";
const char gUnk_0812D6A8[16] = "card_bos_05.acl";
const char gUnk_0812D6B8[16] = "card_bos_05.aob";
const char gUnk_0812D6C8[16] = "bos_pc_bg.acl";
const char gUnk_0812D6D8[16] = "card_bos04.aob";
const char gUnk_0812D6E8[16] = "boss03obj.acl";
const char gUnk_0812D6F8[16] = "card_bos03.aob";
const char gUnk_0812D708[16] = "boss02obj.acl";
const char gUnk_0812D718[16] = "card_bos02.aob";
const char gUnk_0812D728[16] = "boss01obj.acl";
const char gUnk_0812D738[16] = "card_bos01.aob";
const char gUnk_0812D748[16] = "boss00_obj.acl";
const char gUnk_0812D758[16] = "card_bos00.aob";
const char gUnk_0812D768[16] = "card_emy83.aob";
const char gUnk_0812D778[16] = "card_emy82.aob";
const char gUnk_0812D788[16] = "card_emy81.aob";
const char gUnk_0812D798[16] = "card_emy44.aob";
const char gUnk_0812D7A8[16] = "card_emy41.aob";
const char gUnk_0812D7B8[16] = "card_emy39.aob";
const char gUnk_0812D7C8[16] = "card_emy38.aob";
const char gUnk_0812D7D8[16] = "card_emy37.aob";
const char gUnk_0812D7E8[16] = "card_emy31.aob";
const char gUnk_0812D7F8[16] = "card_emy30.aob";
const char gUnk_0812D808[16] = "card_emy29.aob";
const char gUnk_0812D818[16] = "card_emy28.aob";
const char gUnk_0812D828[16] = "card_emy27.aob";
const char gUnk_0812D838[16] = "card_emy26.aob";
const char gUnk_0812D848[16] = "card_emy25.aob";
const char gUnk_0812D858[16] = "card_emy23.aob";
const char gUnk_0812D868[16] = "card_emy22.aob";
const char gUnk_0812D878[16] = "card_emy21.aob";
const char gUnk_0812D888[16] = "card_emy19.aob";
const char gUnk_0812D898[16] = "card_emy18.aob";
const char gUnk_0812D8A8[16] = "card_emy16.aob";
const char gUnk_0812D8B8[16] = "card_emy15.aob";
const char gUnk_0812D8C8[16] = "card_emy14.aob";
const char gUnk_0812D8D8[16] = "card_emy08.aob";
const char gUnk_0812D8E8[16] = "card_emy07.aob";
const char gUnk_0812D8F8[16] = "card_emy06.aob";
const char gUnk_0812D908[16] = "card_emy01.aob";
const char gUnk_0812D918[16] = "card_emy00.aob";
const char gUnk_0812D928[16] = "card_smn15.aob";
const char gUnk_0812D938[16] = "card_smn14.aob";
const char gUnk_0812D948[16] = "card_smn13.aob";
const char gUnk_0812D958[16] = "card_smn12.aob";
const char gUnk_0812D968[16] = "card_smn11.aob";
const char gUnk_0812D978[16] = "card_smn10.aob";
const char gUnk_0812D988[16] = "card_smn09d.acl";
const char gUnk_0812D998[16] = "card_smn09c.acl";
const char gUnk_0812D9A8[16] = "card_smn09b.acl";
const char gUnk_0812D9B8[16] = "card_smn09a.acl";
const char gUnk_0812D9C8[16] = "card_smn09.acl";
const char gUnk_0812D9D8[16] = "card_smn09.aob";
const char gUnk_0812D9E8[16] = "card_smn08.aob";
const char gUnk_0812D9F8[16] = "card_smn07.aob";
const char gUnk_0812DA08[16] = "card_smn06.acl";
const char gUnk_0812DA18[16] = "card_smn06.aob";
const char gUnk_0812DA28[16] = "card_smn05.aob";
const char gUnk_0812DA38[16] = "card_smn04.acl";
const char gUnk_0812DA48[16] = "card_smn04.aob";
const char gUnk_0812DA58[16] = "card_smn03.acl";
const char gUnk_0812DA68[16] = "card_smn03.aob";
const char gUnk_0812DA78[16] = "card_smn02.aob";
const char gUnk_0812DA88[16] = "card_smn01.aob";
const char gUnk_0812DA98[16] = "card_mgc07.acl";
const char gUnk_0812DAA8[16] = "card_mgc07.aob";
const char gUnk_0812DAB8[16] = "card_mgc06.acl";
const char gUnk_0812DAC8[16] = "card_mgc06.aob";
const char gUnk_0812DAD8[16] = "card_mgc05.acl";
const char gUnk_0812DAE8[16] = "card_mgc05.aob";
const char gUnk_0812DAF8[16] = "card_mgc04.acl";
const char gUnk_0812DB08[16] = "card_mgc04.aob";
const char gUnk_0812DB18[16] = "card_mgc03.acl";
const char gUnk_0812DB28[16] = "card_mgc03.aob";
const char gUnk_0812DB38[16] = "card_mgc02.acl";
const char gUnk_0812DB48[16] = "card_mgc02.aob";
const char gUnk_0812DB58[16] = "card_mgc01.acl";
const char gUnk_0812DB68[16] = "card_mgc01.aob";
const char gUnk_0812DB78[16] = "card_wep20.acl";
const char gUnk_0812DB88[16] = "card_wep20.aob";
const char gUnk_0812DB98[16] = "card_wep19.acl";
const char gUnk_0812DBA8[16] = "card_wep19.aob";
const char gUnk_0812DBB8[16] = "card_wep18.acl";
const char gUnk_0812DBC8[16] = "card_wep18.aob";
const char gUnk_0812DBD8[16] = "card_wep16.acl";
const char gUnk_0812DBE8[16] = "card_wep16.aob";
const char gUnk_0812DBF8[16] = "card_wep15.acl";
const char gUnk_0812DC08[16] = "card_wep15.aob";
const char gUnk_0812DC18[16] = "card_wep14.acl";
const char gUnk_0812DC28[16] = "card_wep14.aob";
const char gUnk_0812DC38[16] = "card_wep13.acl";
const char gUnk_0812DC48[16] = "card_wep13.aob";
const char gUnk_0812DC58[16] = "card_wep12.acl";
const char gUnk_0812DC68[16] = "card_wep12.aob";
const char gUnk_0812DC78[16] = "card_wep11.acl";
const char gUnk_0812DC88[16] = "card_wep11.aob";
const char gUnk_0812DC98[16] = "card_wep10.acl";
const char gUnk_0812DCA8[16] = "card_wep10.aob";
const char gUnk_0812DCB8[16] = "card_wep09.acl";
const char gUnk_0812DCC8[16] = "card_wep09.aob";
const char gUnk_0812DCD8[16] = "card_wep08.acl";
const char gUnk_0812DCE8[16] = "card_wep08.aob";
const char gUnk_0812DCF8[16] = "card_wep07.acl";
const char gUnk_0812DD08[16] = "card_wep07.aob";
const char gUnk_0812DD18[16] = "card_wep06.acl";
const char gUnk_0812DD28[16] = "card_wep06.aob";
const char gUnk_0812DD38[16] = "card_wep05.acl";
const char gUnk_0812DD48[16] = "card_wep05.aob";
const char gUnk_0812DD58[16] = "card_wep04.acl";
const char gUnk_0812DD68[16] = "card_wep04.aob";
const char gUnk_0812DD78[16] = "card_wep03.acl";
const char gUnk_0812DD88[16] = "card_wep03.aob";
const char gUnk_0812DD98[16] = "card_wep01.acl";
const char gUnk_0812DDA8[16] = "card_wep01.aob";
const char gUnk_0812DDB8[16] = "card_itm07.acl";
const char gUnk_0812DDC8[16] = "card_itm07.aob";
const char gUnk_0812DDD8[16] = "card_itm06.acl";
const char gUnk_0812DDE8[16] = "card_itm06.aob";
const char gUnk_0812DDF8[16] = "card_itm05.acl";
const char gUnk_0812DE08[16] = "card_itm05.aob";
const char gUnk_0812DE18[16] = "card_itm04.acl";
const char gUnk_0812DE28[16] = "card_itm04.aob";
const char gUnk_0812DE38[16] = "card_itm03.acl";
const char gUnk_0812DE48[16] = "card_itm03.aob";
const char gUnk_0812DE58[16] = "card_itm02.acl";
const char gUnk_0812DE68[16] = "card_itm02.aob";
const char gUnk_0812DE78[16] = "card_itm01.acl";
const char gUnk_0812DE88[16] = "card_itm01.aob";
const char gUnk_0812DE98[12] = "card_00.acl";
const char gUnk_0812DEA4[20] = "ri_card_f0_red.aob";
#ifndef VERSION_EU
const char gUnk_0812DEB8[16] = "b_hpgag_e.aob";
const char gUnk_0812DEC8[12] = "b_hpgag.aob";
#endif
const char gUnk_0812DED4[16] = "b_puraizu.aob";
const char gUnk_0812DEE4[12] = "saku.aob";
const char gUnk_0812DEF0[12] = "knife.acl";
const char gUnk_0812DEFC[12] = "knife.aob";
const char gUnk_0812DF08[16] = "nokogiri.aob";
const char gUnk_0812DF18[12] = "kaifuku.acl";
const char gUnk_0812DF24[12] = "kaifuku.aob";
const char gUnk_0812DF30[16] = "ro_footmark.acl";
const char gUnk_0812DF40[16] = "ro_footmark.aob";
const char gUnk_0812DF50[16] = "pooh_ll10.aob";
const char gUnk_0812DF60[16] = "pooh_ff10.aob";
const char gUnk_0812DF70[16] = "pooh_gauge.acl";
const char gUnk_0812DF80[16] = "pooh_honey.aob";
const char gUnk_0812DF90[16] = "ra_wagon.acl";
const char gUnk_0812DFA0[16] = "ra_wagon.aob";
const char gUnk_0812DFB0[20] = "ra_vegetables.acl";
const char gUnk_0812DFC4[20] = "ra_vegetables.aob";
const char gUnk_0812DFD8[16] = "rabbit_bl00.aob";
const char gUnk_0812DFE8[12] = "rabbit.acl";
const char gUnk_0812DFF4[16] = "rabbit_fl00.aob";
const char gUnk_0812E004[12] = "ee_bee.acl";
const char gUnk_0812E010[12] = "ee_bee.aob";
const char gUnk_0812E01C[20] = "ee_honeycomb.acl";
const char gUnk_0812E030[20] = "ee_honeycomb.aob";
const char gUnk_0812E044[12] = "eeyore.acl";
const char gUnk_0812E050[16] = "eeyore_fl00.aob";
const char gUnk_0812E060[8] = "owl.acl";
const char gUnk_0812E068[16] = "owl_fl00.aob";
const char gUnk_0812E078[16] = "pooh_fl09.aob";
const char gUnk_0812E088[16] = "pooh_bl07.aob";
const char gUnk_0812E098[16] = "pooh_fl07.aob";
const char gUnk_0812E0A8[16] = "pooh_bl03.aob";
const char gUnk_0812E0B8[16] = "pooh_fl03.aob";
const char gUnk_0812E0C8[8] = "roo.acl";
const char gUnk_0812E0D0[16] = "roo_fl00.aob";
const char gUnk_0812E0E0[16] = "tigger_fl03.aob";
const char gUnk_0812E0F0[20] = "tigger_bl02s.aob";
const char gUnk_0812E104[20] = "tigger_fl02s.aob";
const char gUnk_0812E118[16] = "tigger_bl02.aob";
const char gUnk_0812E128[16] = "tigger_fl02.aob";
const char gUnk_0812E138[16] = "tigger_fl01.aob";
const char gUnk_0812E148[12] = "tigger.acl";
const char gUnk_0812E154[16] = "tigger_fl00.aob";
const char gUnk_0812E164[16] = "pooh_fl06.aob";
const char gUnk_0812E174[16] = "pooh_fl05.aob";
const char gUnk_0812E184[16] = "pooh_ff04a.aob";
const char gUnk_0812E194[16] = "pooh_ff04.aob";
const char gUnk_0812E1A4[16] = "pooh_fl04a.aob";
const char gUnk_0812E1B4[16] = "pooh_fl04.aob";
const char gUnk_0812E1C4[16] = "pooh_ll04a.aob";
const char gUnk_0812E1D4[16] = "pooh_ll04.aob";
const char gUnk_0812E1E4[16] = "pooh_bl04a.aob";
const char gUnk_0812E1F4[16] = "pooh_bl04.aob";
const char gUnk_0812E204[16] = "pooh_bb04a.aob";
const char gUnk_0812E214[16] = "pooh_bb04.aob";
const char gUnk_0812E224[16] = "trap01_bb00.aob";
const char gUnk_0812E234[16] = "trap01_bl00.aob";
const char gUnk_0812E244[16] = "trap01_ll00.aob";
const char gUnk_0812E254[16] = "trap01_fl00.aob";
const char gUnk_0812E264[16] = "trap01_00.acl";
const char gUnk_0812E274[16] = "trap01_ff00.aob";
const char gUnk_0812E284[20] = "pooh_ff00_ll.aob";
const char gUnk_0812E298[20] = "pooh_ff00_fl.aob";
const char gUnk_0812E2AC[16] = "pooh_ff00.aob";
const char gUnk_0812E2BC[20] = "pooh_ff00_fr.aob";
const char gUnk_0812E2D0[20] = "pooh_ff00_rr.aob";
const char gUnk_0812E2E4[20] = "pooh_fr00_fl.aob";
const char gUnk_0812E2F8[20] = "pooh_fr00_ff.aob";
const char gUnk_0812E30C[16] = "pooh_fr00.aob";
const char gUnk_0812E31C[20] = "pooh_fr00_rr.aob";
const char gUnk_0812E330[20] = "pooh_fr00_br.aob";
const char gUnk_0812E344[20] = "pooh_rr00_ff.aob";
const char gUnk_0812E358[20] = "pooh_rr00_fr.aob";
const char gUnk_0812E36C[16] = "pooh_rr00.aob";
const char gUnk_0812E37C[20] = "pooh_rr00_br.aob";
const char gUnk_0812E390[20] = "pooh_rr00_bb.aob";
const char gUnk_0812E3A4[20] = "pooh_br00_fr.aob";
const char gUnk_0812E3B8[20] = "pooh_br00_rr.aob";
const char gUnk_0812E3CC[16] = "pooh_br00.aob";
const char gUnk_0812E3DC[20] = "pooh_br00_bb.aob";
const char gUnk_0812E3F0[20] = "pooh_br00_bl.aob";
const char gUnk_0812E404[20] = "pooh_bb00_rr.aob";
const char gUnk_0812E418[20] = "pooh_bb00_br.aob";
const char gUnk_0812E42C[16] = "pooh_bb00.aob";
const char gUnk_0812E43C[20] = "pooh_bb00_bl.aob";
const char gUnk_0812E450[20] = "pooh_bb00_ll.aob";
const char gUnk_0812E464[16] = "trap00_06.aob";
const char gUnk_0812E474[16] = "trap00_05.aob";
const char gUnk_0812E484[16] = "trap00_04.acl";
const char gUnk_0812E494[16] = "trap00_04.aob";
const char gUnk_0812E4A4[16] = "trap00_03.acl";
const char gUnk_0812E4B4[16] = "trap00_03.aob";
const char gUnk_0812E4C4[16] = "trap00_02.acl";
const char gUnk_0812E4D4[16] = "trap00_02.aob";
const char gUnk_0812E4E4[16] = "trap00_01fl.aob";
const char gUnk_0812E4F4[16] = "trap00_01ll.aob";
const char gUnk_0812E504[16] = "trap00_01bl.aob";
const char gUnk_0812E514[16] = "trap00_01bb.aob";
const char gUnk_0812E524[16] = "trap00_01br.aob";
const char gUnk_0812E534[16] = "trap00_01rr.aob";
const char gUnk_0812E544[16] = "trap00_01fr.aob";
const char gUnk_0812E554[16] = "trap00_01.acl";
const char gUnk_0812E564[16] = "trap00_01ff.aob";
const char gUnk_0812E574[16] = "pooh_fl01.aob";
const char gUnk_0812E584[16] = "pooh_ll01.aob";
const char gUnk_0812E594[16] = "pooh_bl01.aob";
const char gUnk_0812E5A4[16] = "pooh_bb01.aob";
const char gUnk_0812E5B4[16] = "pooh_br01.aob";
const char gUnk_0812E5C4[16] = "pooh_rr01.aob";
const char gUnk_0812E5D4[16] = "pooh_fr01.aob";
const char gUnk_0812E5E4[16] = "pooh_ff01.aob";
const char gUnk_0812E5F4[16] = "riku_bb17.aob";
const char gUnk_0812E604[16] = "riku_bl17.aob";
const char gUnk_0812E614[16] = "riku_fl17.aob";
const char gUnk_0812E624[16] = "riku_ff17.aob";
const char gUnk_0812E634[16] = "rik1bb10.aob";
const char gUnk_0812E644[16] = "rik1bl10.aob";
const char gUnk_0812E654[16] = "rik1fl10.aob";
const char gUnk_0812E664[16] = "rik1ff10.aob";
const char gUnk_0812E674[16] = "rik1bb03.aob";
const char gUnk_0812E684[16] = "rik1bl03.aob";
const char gUnk_0812E694[16] = "rik1ll03.aob";
const char gUnk_0812E6A4[16] = "rik1fl03.aob";
const char gUnk_0812E6B4[16] = "rik1ff03.aob";
const char gUnk_0812E6C4[16] = "riku_ll17.aob";
const char gUnk_0812E6D4[16] = "riku_bt13.aob";
const char gUnk_0812E6E4[16] = "riku_bt11.aob";
const char gUnk_0812E6F4[16] = "riku_bt10.aob";
const char gUnk_0812E704[16] = "riku_bt05.aob";
const char gUnk_0812E714[16] = "riku_bt04.aob";
const char gUnk_0812E724[16] = "riku_bt02.aob";
const char gUnk_0812E734[16] = "riku_bt00.aob";

#ifdef VERSION_EU
#define CHKOBJ_ETC_COUNT 5
#else
#define CHKOBJ_ETC_COUNT 7
#endif

const ChkObjEntry gChkObjEntries[10] = {
    { gUnk_09ECEB74, 0x3F, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x82\x72\x82\x6e\x82\x71\x82\x60" },
    { gUnk_09ED82D4, 0x1B, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x82\x71\x82\x68\x82\x6a\x82\x74" },
    { gUnk_09ECF354, 0xA3, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x82\x64\x82\x6d\x82\x64\x82\x6c\x82\x78" },
    { gUnk_09ED07B4, 0x12, 0, "\x81\x40\x81\x40\x81\x40\x82\x72\x82\x74\x82\x6c\x82\x6c\x82\x6e\x82\x6d" },
    { gUnk_09ED09F4, 0x6C, 0, "\x81\x40\x81\x40\x82\x67\x82\x74\x82\x6c\x82\x61\x82\x6e\x82\x72\x82\x72" },
    { gUnk_09ED1774, 0x186, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x82\x64\x82\x75\x82\x64\x82\x6d\x82\x73" },
    { gUnk_09ED4834, 0xA8, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x82\x65\x82\x60\x82\x62\x82\x64" },
    { gUnk_09ED5D34, 0xCE, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x82\x62\x82\x60\x82\x71\x82\x63" },
    { gUnk_09ED76F4, CHKOBJ_ETC_COUNT, 0, "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x82\x64\x82\x73\x82\x62" },
    { gUnk_09ED77D4, 0x58, 0, "\x81\x40\x82\x6f\x82\x6e\x82\x6e\x82\x67\x82\x66\x82\x60\x82\x6c\x82\x64" },
};

void mode_chkobj_0(void) {
    SetBgMode0();
    gChkObjWork = EwramAlloc(sizeof(ChkObjWork));
    TaskPoolInit(&gChkObjWork->pool, 1);
    TaskCreate(&gChkObjWork->pool, &gTaskDescPrint, 0);
    gChkObjWork->unk_14 = 0;
    gChkObjWork->animId = 0;
    gChkObjWork->unk_18 = 0;
    gChkObjWork->tiles = AllocObjTiles(0x2000, 0);
    gChkObjWork->palette = LoadObjPalette(gUnk_08F683A4, 0x20);
    gChkObjWork->gfx = gUnk_088B629C;
    gChkObjWork->paused = 0;
    gChkObjWork->unk_42 = 0x80A0;
    gChkObjWork->unk_44 = 0;
    gChkObjWork->y = 0;
    func_0800B30C(gChkObjEntries[0].defs);
    SetupBg(1, 0, 15, 0);
    EnableBg(0);
    func_0805FA8C(1, 0x5400, 0x500);
    func_0805FA60(1, gWhitePalette, 0x20, 0x0F);
    func_0805FCB0(166, 0, 2, gChkObjEntries[0].name);
}

void mode_chkobj_1(void) {
    ObjDef* def;
    u16 keys;
    s16 v;

    if (GetKeysPressed() & 2) {
        ModeRequest(&gModeDebug, 0);
    } else {
        if (GetKeysPressed() & 8) {
            gChkObjWork->paused = !gChkObjWork->paused;
        }

        if (AnimIsFinished(&gChkObjWork->anim) && (GetKeysHeld() & 1)) {
            AnimStart(&gChkObjWork->anim, gChkObjWork->animId, 0);
        }

        if (GetKeysRepeat() & (DPAD_RIGHT | DPAD_LEFT)) {
            if (GetKeysRepeat() & DPAD_LEFT) {
                gChkObjWork->animId--;
            }

            if (GetKeysRepeat() & DPAD_RIGHT) {
                gChkObjWork->animId++;
            }

            gChkObjWork->y = 0;
            gChkObjWork->paused = 0;
            gChkObjWork->unk_44 = 0;
            def = &gChkObjEntries[gChkObjWork->unk_18].defs[gChkObjWork->unk_14];

            if (gChkObjWork->animId < 0) {
                gChkObjWork->unk_14--;

                if (gChkObjWork->unk_14 < 0) {
                    gChkObjWork->unk_18--;

                    if (gChkObjWork->unk_18 < 0) {
                        gChkObjWork->unk_18 = 9;
                    }

                    gChkObjWork->unk_14 = gChkObjEntries[gChkObjWork->unk_18].count - 1;
                }

                def = &gChkObjEntries[gChkObjWork->unk_18].defs[gChkObjWork->unk_14];
                gChkObjWork->animId = def->animCount - 1;
                func_0800B30C(def);
            } else if (gChkObjWork->animId >= def->animCount) {
                gChkObjWork->unk_14++;

                if (gChkObjWork->unk_14 >= gChkObjEntries[gChkObjWork->unk_18].count) {
                    gChkObjWork->unk_18++;

                    if ((u16)gChkObjWork->unk_18 > 9) {
                        gChkObjWork->unk_18 = 0;
                    }

                    gChkObjWork->unk_14 = 0;
                }

                def = &gChkObjEntries[gChkObjWork->unk_18].defs[gChkObjWork->unk_14];
                gChkObjWork->animId = 0;
                func_0800B30C(def);
            } else {
                AnimStart(&gChkObjWork->anim, gChkObjWork->animId, 0);
            }

            func_0805FCB0(166, 0, 2, gChkObjEntries[gChkObjWork->unk_18].name);
        }

        keys = GetKeysHeld() & 4;

        if (keys != 0) {
            if (GetKeysHeld() & L_BUTTON) {
                gChkObjWork->unk_42--;
            }

            if (GetKeysHeld() & R_BUTTON) {
                gChkObjWork->unk_42++;
            }
        } else if (GetKeysRepeat() & (L_BUTTON | R_BUTTON)) {
            gChkObjWork->y = 0;
            gChkObjWork->paused = 0;
            gChkObjWork->unk_44 = 0;

            if (GetKeysRepeat() & L_BUTTON) {
                gChkObjWork->unk_18--;
            }

            if (GetKeysRepeat() & R_BUTTON) {
                gChkObjWork->unk_18++;
            }

            if (gChkObjWork->unk_18 < 0) {
                gChkObjWork->unk_18 = 9;
            } else if ((u16)gChkObjWork->unk_18 > 9) {
                gChkObjWork->unk_18 = 0;
            }

            gChkObjWork->animId = 0;
            gChkObjWork->unk_14 = 0;
            def = gChkObjEntries[gChkObjWork->unk_18].defs;
            func_0800B30C(def);
            func_0805FCB0(166, 0, 2, gChkObjEntries[gChkObjWork->unk_18].name);
        }

        SetBackdropColor((u16)abs(gSineTable[gChkObjWork->unk_42 & 0xFF] * 5 >> 6),
                      (u16)abs(gSineTable[(gChkObjWork->unk_42 / 2) & 0xFF] * 5 >> 6),
                      (u16)abs(gSineTable[(gChkObjWork->unk_42 / 4) & 0xFF] * 5 >> 6));

        if (GetKeysHeld() & DPAD_UP) {
            gChkObjWork->y--;
        } else if (GetKeysHeld() & DPAD_DOWN) {
            gChkObjWork->y++;
        }

        TaskPoolUpdate(&gChkObjWork->pool);
        TaskPoolDraw(&gChkObjWork->pool);

        if (gChkObjWork->paused == 0 || (GetKeysRepeat() & 1)) {
            AnimUpdate(&gChkObjWork->anim);
        }

        gChkObjWork->gfx = AnimGetGfx(&gChkObjWork->anim);

        if (gChkObjWork->paused != 0) {
            func_0809D2B0(0, 1, 0, "PAUSE");
        } else {
            func_0809D2B0(0, 1, 0, "     ");
        }

        def = &gChkObjEntries[gChkObjWork->unk_18].defs[gChkObjWork->unk_14];
        func_0809D2B0(0, 12, 0, "                                      ");
        func_0809D2B0(0, 13, 0, "                                      ");
        func_0809D2B0(0, 14, 0, "                                      ");
        func_0809D2B0(0, 15, 0, "                                      ");
        func_0809D2B0(0, 16, 0, "                                      ");
        func_0809D2B0(0, 17, 0, "                                      ");
        func_0809D2B0(0, 18, 0, "                                      ");
        func_0809D2B0(0, 19, 0, "                                      ");
        func_0809D2B0(0, 0, 0, "    ");
        func_0809D458(0, 0, 0, gChkObjWork->unk_14);
        func_0809D2B0(0, 12, 0, def->aobName);
        func_0809D2B0(0, 13, 0, "aob");
        func_0809D458(6, 13, 0, AnimGetGfxIndex(&gChkObjWork->anim));
        func_0809D2B0(0, 14, 0, def->aclName);
        func_0809D2B0(0, 15, 0, "anime");
        func_0809D458(6, 15, 0, gChkObjWork->animId);
        func_0809D2B0(0, 16, 0, "pic");
        func_0809D458(6, 16, 0, gChkObjWork->anim.frame);
        func_0809D2B0(0, 17, 0, "frame");
        func_0809D458(6, 17, 0, gChkObjWork->anim.timer);
        v = GetSpriteTileBytes(gChkObjWork->gfx) >> 5;
        func_0809D2B0(0, 18, 0, "chara");
        func_0809D458(6, 18, 0, v);

        if (gChkObjWork->unk_44 < v) {
            gChkObjWork->unk_44 = v;
        }

        func_0809D2B0(0, 19, 0, "maxChr");
        func_0809D458(6, 19, 0, gChkObjWork->unk_44);
        DrawSprite(120, gChkObjWork->y + 96, gChkObjWork->gfx, gChkObjWork->tiles,
                   gChkObjWork->palette, 0, 0, 0);
        func_080605A4(1);
        func_08060598();
    }
}

void mode_chkobj_2(void) {
    TaskPoolDestroy(&gChkObjWork->pool);
    ReleaseObjTiles(gChkObjWork->tiles);
    ReleaseObjPalette(gChkObjWork->palette);
    EwramFree(gChkObjWork);
    func_080609A0();
}

const char gModeNameChkobj[12] = "mode_chkobj";

ObjDef gUnk_09ECEB74[] = {
    { gUnk_09EDE8CC, gUnk_09EDE918, gUnk_088B6560, 2, 0, gUnk_08F683A4, gUnk_08128978, gUnk_0812896C, 32, 0 },
    { gUnk_09EDE99C, gUnk_09EDE9CC, gUnk_088BF162, 8, 0, gUnk_08F683A4, gUnk_0812895C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEA68, gUnk_09EDEA6C, gUnk_088C56C6, 1, 0, gUnk_08F683A4, gUnk_0812894C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEB0C, gUnk_09EDEB40, gUnk_088CBAA2, 10, 0, gUnk_08F683A4, gUnk_0812893C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDED34, gUnk_09EDED38, gUnk_088DBD58, 1, 0, gUnk_08F683A4, gUnk_0812892C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDE920, gUnk_09EDE940, gUnk_088BAC36, 1, 0, gUnk_08F683A4, gUnk_0812891C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDE9EC, gUnk_09EDEA0C, gUnk_088C1388, 1, 0, gUnk_08F683A4, gUnk_0812890C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEA70, gUnk_09EDEA90, gUnk_088C5AAA, 1, 0, gUnk_08F683A4, gUnk_081288FC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEB68, gUnk_09EDEB88, gUnk_088CE0C2, 1, 0, gUnk_08F683A4, gUnk_081288EC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDED3C, gUnk_09EDED5C, gUnk_088DC192, 1, 0, gUnk_08F683A4, gUnk_081288DC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDE944, gUnk_09EDE964, gUnk_088BC6DE, 1, 0, gUnk_08F683A4, gUnk_081288CC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEA10, gUnk_09EDEA30, gUnk_088C2D72, 1, 0, gUnk_08F683A4, gUnk_081288BC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEA94, gUnk_09EDEAB4, gUnk_088C75A0, 1, 0, gUnk_08F683A4, gUnk_081288AC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEB8C, gUnk_09EDEBAC, gUnk_088CF9CE, 1, 0, gUnk_08F683A4, gUnk_0812889C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDED60, gUnk_09EDED80, gUnk_088DDAF6, 1, 0, gUnk_08F683A4, gUnk_0812888C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 6, 0, gUnk_08F683A4, gUnk_0812887C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 6, 0, gUnk_08F683A4, gUnk_0812886C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 6, 0, gUnk_08F683A4, gUnk_0812885C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 6, 0, gUnk_08F683A4, gUnk_0812884C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 6, 0, gUnk_08F683A4, gUnk_0812883C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEBE4, gUnk_09EDEBFC, gUnk_088D2638, 1, 0, gUnk_08F683A4, gUnk_0812882C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEAEC, gUnk_09EDEB08, gUnk_088CA102, 1, 0, gUnk_08F683A4, gUnk_0812881C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEEF4, gUnk_09EDEF08, gUnk_088EAF1C, 1, 0, gUnk_08F683A4, gUnk_0812880C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEF0C, gUnk_09EDEF28, gUnk_088EBFDA, 4, 0, gUnk_08F683A4, gUnk_081287FC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF34C, gUnk_09EDF35C, gUnk_0891D344, 1, 0, gUnk_08F683A4, gUnk_081287EC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF308, gUnk_09EDF31C, gUnk_0891A166, 1, 0, gUnk_08F683A4, gUnk_081287DC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF320, gUnk_09EDF334, gUnk_0891B26C, 1, 0, gUnk_08F683A4, gUnk_081287CC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF338, gUnk_09EDF348, gUnk_0891C1E8, 1, 0, gUnk_08F683A4, gUnk_081287BC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF360, gUnk_09EDF370, gUnk_0891DFC4, 1, 0, gUnk_08F683A4, gUnk_081287AC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF004, gUnk_09EDF01C, gUnk_088F5298, 1, 0, gUnk_08F683A4, gUnk_0812879C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF020, gUnk_09EDF03C, gUnk_088F695C, 1, 0, gUnk_08F683A4, gUnk_0812878C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 6, 0, gUnk_08F683A4, gUnk_0812877C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF074, gUnk_09EDF08C, gUnk_088FA0DA, 1, 0, gUnk_08F683A4, gUnk_0812876C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF090, gUnk_09EDF0A8, gUnk_088FB5F2, 1, 0, gUnk_08F683A4, gUnk_0812875C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDECFC, gUnk_09EDED28, gUnk_088D9C76, 3, 0, gUnk_08F683A4, gUnk_0812874C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEC00, gUnk_09EDEC2C, gUnk_088D3A68, 3, 0, gUnk_08F683A4, gUnk_0812873C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDECA8, gUnk_09EDECB4, gUnk_088D7CCE, 3, 0, gUnk_08F683A4, gUnk_0812872C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEC88, gUnk_09EDEC9C, gUnk_088D702C, 3, 0, gUnk_08F683A4, gUnk_0812871C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEC50, gUnk_09EDEC5C, gUnk_088D5E98, 3, 0, gUnk_08F683A4, gUnk_0812870C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEC68, gUnk_09EDEC7C, gUnk_088D6282, 3, 0, gUnk_08F683A4, gUnk_081286FC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEC38, gUnk_09EDEC44, gUnk_088D5AB0, 3, 0, gUnk_08F683A4, gUnk_081286EC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEDB8, gUnk_09EDEDEC, gUnk_088E0BC0, 7, 0, gUnk_08F683A4, gUnk_081286DC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEE08, gUnk_09EDEE14, gUnk_088E33C2, 2, 0, gUnk_08F683A4, gUnk_081286CC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEE1C, gUnk_09EDEE3C, gUnk_088E3E78, 1, 0, gUnk_08F683A4, gUnk_081286BC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEF84, gUnk_09EDEF98, gUnk_088F05DC, 4, 0, gUnk_08F683A4, gUnk_081286AC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEE40, gUnk_09EDEE54, gUnk_088E56C6, 5, 0, gUnk_08F683A4, gUnk_0812869C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEF38, gUnk_09EDEF50, gUnk_088ED77A, 5, 0, gUnk_08F683A4, gUnk_0812868C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEE68, gUnk_09EDEE7C, gUnk_088E67B6, 5, 0, gUnk_08F683A4, gUnk_0812867C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEE90, gUnk_09EDEEB0, gUnk_088E7974, 5, 0, gUnk_08F683A4, gUnk_0812866C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEFA8, gUnk_09EDEFBC, gUnk_088F19DC, 5, 0, gUnk_08F683A4, gUnk_0812865C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEFD0, gUnk_09EDEFF0, gUnk_088F2F5C, 5, 0, gUnk_08F683A4, gUnk_0812864C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEEC4, gUnk_09EDEEEC, gUnk_088E967C, 2, 0, gUnk_08F683A4, gUnk_0812863C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDEF64, gUnk_09EDEF80, gUnk_088EEAD4, 1, 0, gUnk_08F683A4, gUnk_0812862C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF0AC, gUnk_09EDF0C4, gUnk_088FCCCE, 4, 0, gUnk_08F683A4, gUnk_0812861C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF0D4, gUnk_09EDF114, gUnk_088FDE7A, 4, 0, gUnk_08F683A4, gUnk_0812860C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF124, gUnk_09EDF154, gUnk_08901C8A, 1, 0, gUnk_08F683A4, gUnk_081285FC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF158, gUnk_09EDF1B0, gUnk_08902C3C, 4, 0, gUnk_08F683A4, gUnk_081285EC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF1C0, gUnk_09EDF1F8, gUnk_08908DE6, 5, 0, gUnk_08F683A4, gUnk_081285DC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF20C, gUnk_09EDF244, gUnk_0890C34E, 1, 0, gUnk_08F683A4, gUnk_081285CC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF248, gUnk_09EDF268, gUnk_0890FCE0, 1, 0, gUnk_08F683A4, gUnk_081285BC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF26C, gUnk_09EDF290, gUnk_08911BC8, 1, 0, gUnk_08F683A4, gUnk_081285AC, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF294, gUnk_09EDF2C4, gUnk_08914288, 3, 0, gUnk_08F683A4, gUnk_0812859C, gUnk_0812896C, 32, 0 },
    { gUnk_09EDF2D0, gUnk_09EDF2FC, gUnk_089173FC, 3, 0, gUnk_08F683A4, gUnk_0812858C, gUnk_0812896C, 32, 0 },
};

ObjDef gUnk_09ECF354[] = {
    { gUnk_09EDF834, gUnk_09EDF85C, gUnk_08957290, 1, 0, gUnk_08F697A4, gUnk_08129524, gUnk_08129518, 32, 0 },
    { gUnk_09EDF884, gUnk_09EDF8A4, gUnk_0895A12A, 1, 0, gUnk_08F697A4, gUnk_08129508, gUnk_08129518, 32, 0 },
    { gUnk_09EDF8CC, gUnk_09EDF8EC, gUnk_0895C5E6, 1, 0, gUnk_08F697A4, gUnk_081294F8, gUnk_08129518, 32, 0 },
    { gUnk_09EDF914, gUnk_09EDF940, gUnk_0895EECC, 2, 0, gUnk_08F697A4, gUnk_081294E8, gUnk_08129518, 32, 0 },
    { gUnk_09EDF948, gUnk_09EDF974, gUnk_089605FC, 2, 0, gUnk_08F697A4, gUnk_081294D8, gUnk_08129518, 32, 0 },
    { gUnk_09EDF9A8, gUnk_09EDF9BC, gUnk_08963BAC, 1, 0, gUnk_08F697A4, gUnk_081294C8, gUnk_08129518, 32, 0 },
    { gUnk_09EDF9C0, gUnk_09EDF9D8, gUnk_08964BF6, 1, 0, gUnk_08F697A4, gUnk_081294B8, gUnk_08129518, 32, 0 },
    { gUnk_09EDF9DC, gUnk_09EDF9F4, gUnk_08965D48, 1, 0, gUnk_08F697A4, gUnk_081294A8, gUnk_08129518, 32, 0 },
    { gUnk_09EDF9F8, gUnk_09EDFA04, gUnk_0896700E, 1, 0, gUnk_08F697A4, gUnk_08129498, gUnk_08129518, 32, 0 },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 9, 0, gUnk_08F69804, gUnk_08129488, gUnk_0812947C, 32, 0 },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 9, 0, gUnk_08F69824, gUnk_08129488, gUnk_08129470, 32, 0 },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 9, 0, gUnk_08F69844, gUnk_08129488, gUnk_08129464, 32, 0 },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 9, 0, gUnk_08F69864, gUnk_08129488, gUnk_08129458, 32, 0 },
    { gUnk_09EE00D0, gUnk_09EE00F0, gUnk_089D8148, 1, 0, gUnk_08F69924, gUnk_08129448, gUnk_0812943C, 32, 0 },
    { gUnk_09EE00F4, gUnk_09EE0114, gUnk_089DA20E, 1, 0, gUnk_08F69924, gUnk_0812942C, gUnk_0812943C, 32, 0 },
    { gUnk_09EE0118, gUnk_09EE013C, gUnk_089DBFA8, 1, 0, gUnk_08F69924, gUnk_0812941C, gUnk_0812943C, 32, 0 },
    { gUnk_09EE0140, gUnk_09EE0178, gUnk_089DDB2C, 1, 0, gUnk_08F69924, gUnk_0812940C, gUnk_0812943C, 32, 0 },
    { gUnk_09EDFDBC, gUnk_09EDFDD4, gUnk_089AE276, 1, 0, gUnk_08F698A4, gUnk_081293FC, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFDD8, gUnk_09EDFDFC, gUnk_089AF520, 1, 0, gUnk_08F698A4, gUnk_081293E0, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFE00, gUnk_09EDFE24, gUnk_089B0C42, 1, 0, gUnk_08F698A4, gUnk_081293D0, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFE28, gUnk_09EDFE44, gUnk_089B225C, 1, 0, gUnk_08F698A4, gUnk_081293C0, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFE48, gUnk_09EDFE60, gUnk_089B370E, 1, 0, gUnk_08F698A4, gUnk_081293B0, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFE64, gUnk_09EDFE7C, gUnk_089B4A42, 1, 0, gUnk_08F698A4, gUnk_0812939C, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFE80, gUnk_09EDFEA0, gUnk_089B5D96, 1, 0, gUnk_08F698A4, gUnk_0812938C, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFEA4, gUnk_09EDFEB4, gUnk_089B75F2, 1, 0, gUnk_08F698A4, gUnk_0812937C, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFEB8, gUnk_09EDFED0, gUnk_089B807A, 1, 0, gUnk_08F698A4, gUnk_0812936C, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFED4, gUnk_09EDFEE8, gUnk_089B902C, 1, 0, gUnk_08F698A4, gUnk_0812935C, gUnk_081293F0, 32, 0 },
    { gUnk_09EDFEEC, gUnk_09EDFF0C, gUnk_089B9DD2, 1, 0, gUnk_08F698E4, gUnk_0812934C, gUnk_08129340, 32, 0 },
    { gUnk_09EDFF10, gUnk_09EDFF30, gUnk_089BB67A, 1, 0, gUnk_08F698E4, gUnk_08129330, gUnk_08129340, 32, 0 },
    { gUnk_09EDFF34, gUnk_09EDFF5C, gUnk_089BCC54, 1, 0, gUnk_08F698E4, gUnk_0812931C, gUnk_08129340, 32, 0 },
    { gUnk_09EDFF60, gUnk_09EDFF88, gUnk_089BE7BA, 1, 0, gUnk_08F698E4, gUnk_08129308, gUnk_08129340, 32, 0 },
    { gUnk_09EDFF8C, gUnk_09EDFFAC, gUnk_089BFDD6, 1, 0, gUnk_08F698E4, gUnk_081292F4, gUnk_08129340, 32, 0 },
    { gUnk_09EDFFB0, gUnk_09EDFFD8, gUnk_089C11E6, 1, 0, gUnk_08F698C4, gUnk_081292E0, gUnk_081292D4, 32, 0 },
    { gUnk_09EDFAA4, gUnk_09EDFAC4, gUnk_0897CDAC, 1, 0, gUnk_08F697E4, gUnk_081292C4, gUnk_081292B8, 32, 0 },
    { gUnk_09EDFAC8, gUnk_09EDFAEC, gUnk_0897EFB2, 1, 0, gUnk_08F697E4, gUnk_081292A8, gUnk_081292B8, 32, 0 },
    { gUnk_09EDFAF0, gUnk_09EDFB10, gUnk_08981824, 1, 0, gUnk_08F697E4, gUnk_08129298, gUnk_081292B8, 32, 0 },
    { gUnk_09EDFB14, gUnk_09EDFB30, gUnk_08983E36, 2, 0, gUnk_08F697E4, gUnk_08129288, gUnk_081292B8, 32, 0 },
    { gUnk_09EDFB38, gUnk_09EDFB58, gUnk_08985F9E, 1, 0, gUnk_08F697E4, gUnk_08129278, gUnk_081292B8, 32, 0 },
    { gUnk_09EE017C, gUnk_09EE01A0, gUnk_089DF930, 1, 0, gUnk_08F69944, gUnk_08129268, gUnk_0812925C, 32, 0 },
    { gUnk_09EE01A4, gUnk_09EE01C4, gUnk_089E26BE, 1, 0, gUnk_08F69944, gUnk_0812924C, gUnk_0812925C, 32, 0 },
    { gUnk_09EE01C8, gUnk_09EE01E0, gUnk_089E416E, 1, 0, gUnk_08F69944, gUnk_0812923C, gUnk_0812925C, 32, 0 },
    { gUnk_09EE01E4, gUnk_09EE0200, gUnk_089E5EA0, 3, 0, gUnk_08F69944, gUnk_0812922C, gUnk_0812925C, 32, 0 },
    { gUnk_09EE020C, gUnk_09EE0230, gUnk_089E8384, 2, 0, gUnk_08F69944, gUnk_0812921C, gUnk_0812925C, 32, 0 },
    { gUnk_09EE0424, gUnk_09EE0448, gUnk_08A1823A, 1, 0, gUnk_08F699C4, gUnk_0812920C, gUnk_08129200, 32, 0 },
    { gUnk_09EE044C, gUnk_09EE046C, gUnk_08A1AB00, 1, 0, gUnk_08F699C4, gUnk_081291F0, gUnk_08129200, 32, 0 },
    { gUnk_09EE0470, gUnk_09EE0484, gUnk_08A1CDA8, 1, 0, gUnk_08F699C4, gUnk_081291E0, gUnk_08129200, 32, 0 },
    { gUnk_09EE0488, gUnk_09EE04A8, gUnk_08A1E4CC, 1, 0, gUnk_08F699C4, gUnk_081291D0, gUnk_08129200, 32, 0 },
    { gUnk_09EE04AC, gUnk_09EE04B4, gUnk_08A20BCE, 1, 0, gUnk_08F699C4, gUnk_081291C0, gUnk_08129200, 32, 0 },
    { gUnk_09EE04B8, gUnk_09EE04DC, gUnk_08A20D96, 1, 0, gUnk_08F699C4, gUnk_081291B0, gUnk_08129200, 32, 0 },
    { gUnk_09EE04E0, gUnk_09EE04F4, gUnk_08A23630, 3, 0, gUnk_08F699C4, gUnk_081291A0, gUnk_08129200, 32, 0 },
    { gUnk_09EE0D2C, gUnk_09EE0D6C, gUnk_08AF0E4E, 1, 0, gUnk_08F69B24, gUnk_08129190, gUnk_08129184, 32, 0 },
    { gUnk_09EE0D70, gUnk_09EE0DB8, gUnk_08AF4A6E, 3, 0, gUnk_08F69B24, gUnk_08129174, gUnk_08129184, 32, 0 },
    { gUnk_09EE0DC4, gUnk_09EE0DE0, gUnk_08AF7F7E, 1, 0, gUnk_08F69B24, gUnk_08129164, gUnk_08129184, 32, 0 },
    { gUnk_09EE0DE4, gUnk_09EE0E04, gUnk_08AFA282, 1, 0, gUnk_08F69B24, gUnk_08129154, gUnk_08129184, 32, 0 },
    { gUnk_09EE0E08, gUnk_09EE0E28, gUnk_08AFCC84, 1, 0, gUnk_08F69B24, gUnk_08129144, gUnk_08129184, 32, 0 },
    { gUnk_09EE0238, gUnk_09EE0250, gUnk_089EB0D6, 1, 0, gUnk_08F69964, gUnk_08129134, gUnk_08129128, 32, 0 },
    { gUnk_09EE0254, gUnk_09EE0274, gUnk_089ECE06, 1, 0, gUnk_08F69964, gUnk_08129118, gUnk_08129128, 32, 0 },
    { gUnk_09EE0278, gUnk_09EE0284, gUnk_089EEFFC, 1, 0, gUnk_08F69964, gUnk_08129108, gUnk_08129128, 32, 0 },
    { gUnk_09EE0288, gUnk_09EE02A4, gUnk_089EFC28, 4, 0, gUnk_08F69964, gUnk_081290F8, gUnk_08129128, 32, 0 },
    { gUnk_09EE02B4, gUnk_09EE02D0, gUnk_089F18A0, 1, 0, gUnk_08F69964, gUnk_081290E8, gUnk_08129128, 32, 0 },
    { gUnk_09EDFC60, gUnk_09EDFC80, gUnk_0899014C, 1, 0, gUnk_08F69884, gUnk_081290D8, gUnk_081290CC, 32, 0 },
    { gUnk_09EDFC84, gUnk_09EDFC9C, gUnk_089943B0, 1, 0, gUnk_08F69884, gUnk_081290BC, gUnk_081290CC, 32, 0 },
    { gUnk_09EDFCA0, gUnk_09EDFCB8, gUnk_089975F8, 1, 0, gUnk_08F69884, gUnk_081290AC, gUnk_081290CC, 32, 0 },
    { gUnk_09EDFCBC, gUnk_09EDFCF4, gUnk_0899A8BE, 1, 0, gUnk_08F69884, gUnk_0812909C, gUnk_081290CC, 32, 0 },
    { gUnk_09EDFCF8, gUnk_09EDFD10, gUnk_0899DE26, 1, 0, gUnk_08F69884, gUnk_0812908C, gUnk_081290CC, 32, 0 },
    { gUnk_09EDFD14, gUnk_09EDFD44, gUnk_089A1034, 2, 0, gUnk_08F69884, gUnk_0812907C, gUnk_081290CC, 32, 0 },
    { gUnk_09EDFD4C, gUnk_09EDFD6C, gUnk_089A7288, 1, 0, gUnk_08F69884, gUnk_0812906C, gUnk_081290CC, 32, 0 },
    { gUnk_09EE0500, gUnk_09EE0530, gUnk_08A239E2, 1, 0, gUnk_08F699E4, gUnk_0812905C, gUnk_08129050, 32, 0 },
    { gUnk_09EE0534, gUnk_09EE0550, gUnk_08A2723C, 1, 0, gUnk_08F699E4, gUnk_08129040, gUnk_08129050, 32, 0 },
    { gUnk_09EE0554, gUnk_09EE057C, gUnk_08A2A2C4, 1, 0, gUnk_08F699E4, gUnk_08129030, gUnk_08129050, 32, 0 },
    { gUnk_09EE0580, gUnk_09EE05BC, gUnk_08A2D81C, 1, 0, gUnk_08F699E4, gUnk_08129020, gUnk_08129050, 32, 0 },
    { gUnk_09EE02D4, gUnk_09EE02F4, gUnk_089F3E0E, 1, 0, gUnk_08F69984, gUnk_08129010, gUnk_08129004, 32, 0 },
    { gUnk_09EE02F8, gUnk_09EE0310, gUnk_089F840E, 1, 0, gUnk_08F69984, gUnk_08128FF4, gUnk_08129004, 32, 0 },
    { gUnk_09EE0314, gUnk_09EE0328, gUnk_089FB642, 1, 0, gUnk_08F69984, gUnk_08128FE4, gUnk_08129004, 32, 0 },
    { gUnk_09EE032C, gUnk_09EE034C, gUnk_089FDD92, 1, 0, gUnk_08F69984, gUnk_08128FD4, gUnk_08129004, 32, 0 },
    { gUnk_09EE0350, gUnk_09EE036C, gUnk_08A02308, 1, 0, gUnk_08F69984, gUnk_08128FC4, gUnk_08129004, 32, 0 },
    { gUnk_09EE0B18, gUnk_09EE0B64, gUnk_08ABBF0E, 1, 0, gUnk_08F69AE4, gUnk_08128FB4, gUnk_08128FA8, 32, 0 },
    { gUnk_09EE0B68, gUnk_09EE0B90, gUnk_08AC206A, 1, 0, gUnk_08F69AE4, gUnk_08128F98, gUnk_08128FA8, 32, 0 },
    { gUnk_09EE0B94, gUnk_09EE0BB4, gUnk_08AC59DA, 1, 0, gUnk_08F69AE4, gUnk_08128F88, gUnk_08128FA8, 32, 0 },
    { gUnk_09EE0BB8, gUnk_09EE0BE4, gUnk_08AC85A2, 1, 0, gUnk_08F69AE4, gUnk_08128F78, gUnk_08128FA8, 32, 0 },
    { gUnk_09EE0BE8, gUnk_09EE0C54, gUnk_08ACC9D0, 1, 0, gUnk_08F69AE4, gUnk_08128F68, gUnk_08128FA8, 32, 0 },
    { gUnk_09EE05C0, gUnk_09EE05E0, gUnk_08A31D86, 1, 0, gUnk_08F69A04, gUnk_08128F58, gUnk_08128F4C, 32, 0 },
    { gUnk_09EE05E4, gUnk_09EE05F4, gUnk_08A3623E, 1, 0, gUnk_08F69A04, gUnk_08128F3C, gUnk_08128F4C, 32, 0 },
    { gUnk_09EE05F8, gUnk_09EE0610, gUnk_08A38370, 1, 0, gUnk_08F69A04, gUnk_08128F2C, gUnk_08128F4C, 32, 0 },
    { gUnk_09EE0614, gUnk_09EE062C, gUnk_08A3B798, 1, 0, gUnk_08F69A04, gUnk_08128F1C, gUnk_08128F4C, 32, 0 },
    { gUnk_09EE0630, gUnk_09EE064C, gUnk_08A3EE2E, 3, 0, gUnk_08F69A04, gUnk_08128F0C, gUnk_08128F4C, 32, 0 },
    { gUnk_09EE0658, gUnk_09EE0678, gUnk_08A42C16, 1, 0, gUnk_08F69A24, gUnk_08128EFC, gUnk_08128EF0, 32, 0 },
    { gUnk_09EE067C, gUnk_09EE069C, gUnk_08A44658, 1, 0, gUnk_08F69A24, gUnk_08128EE0, gUnk_08128EF0, 32, 0 },
    { gUnk_09EE06A0, gUnk_09EE06AC, gUnk_08A4677E, 1, 0, gUnk_08F69A24, gUnk_08128ED0, gUnk_08128EF0, 32, 0 },
    { gUnk_09EE06B0, gUnk_09EE06CC, gUnk_08A473D8, 1, 0, gUnk_08F69A24, gUnk_08128EC0, gUnk_08128EF0, 32, 0 },
    { gUnk_09EE06D0, gUnk_09EE06E8, gUnk_08A49124, 1, 0, gUnk_08F69A24, gUnk_08128EB0, gUnk_08128EF0, 32, 0 },
    { gUnk_09EE06EC, gUnk_09EE070C, gUnk_08A4AD94, 1, 0, gUnk_08F69A44, gUnk_08128EA0, gUnk_08128E94, 32, 0 },
    { gUnk_09EE0710, gUnk_09EE0728, gUnk_08A4E2F8, 3, 0, gUnk_08F69A44, gUnk_08128E84, gUnk_08128E94, 32, 0 },
    { gUnk_09EE0734, gUnk_09EE0740, gUnk_08A51622, 1, 0, gUnk_08F69A44, gUnk_08128E74, gUnk_08128E94, 32, 0 },
    { gUnk_09EE0744, gUnk_09EE075C, gUnk_08A52E8A, 1, 0, gUnk_08F69A44, gUnk_08128E64, gUnk_08128E94, 32, 0 },
    { gUnk_09EE0760, gUnk_09EE077C, gUnk_08A566B8, 1, 0, gUnk_08F69A44, gUnk_08128E54, gUnk_08128E94, 32, 0 },
    { gUnk_09EE0780, gUnk_09EE07A0, gUnk_08A59DDC, 2, 0, gUnk_08F69A64, gUnk_08128E44, gUnk_08128E38, 32, 0 },
    { gUnk_09EE07A8, gUnk_09EE07B4, gUnk_08A5D6BA, 1, 0, gUnk_08F69A64, gUnk_08128E28, gUnk_08128E38, 32, 0 },
    { gUnk_09EE07B8, gUnk_09EE07D4, gUnk_08A5ECC6, 2, 0, gUnk_08F69A64, gUnk_08128E18, gUnk_08128E38, 32, 0 },
    { gUnk_09EE07DC, gUnk_09EE0800, gUnk_08A62944, 9, 0, gUnk_08F69A64, gUnk_08128E08, gUnk_08128E38, 32, 0 },
    { gUnk_09EE09D0, gUnk_09EE09EC, gUnk_08A971D2, 2, 0, gUnk_08F69AC4, gUnk_08128DF8, gUnk_08128DEC, 32, 0 },
    { gUnk_09EE09F4, gUnk_09EE0A0C, gUnk_08A9B688, 3, 0, gUnk_08F69AC4, gUnk_08128DDC, gUnk_08128DEC, 32, 0 },
    { gUnk_09EE0A18, gUnk_09EE0A2C, gUnk_08A9EE4E, 1, 0, gUnk_08F69AC4, gUnk_08128DCC, gUnk_08128DEC, 32, 0 },
    { gUnk_09EE0A30, gUnk_09EE0A50, gUnk_08AA22EA, 3, 0, gUnk_08F69AC4, gUnk_08128DBC, gUnk_08128DEC, 32, 0 },
    { gUnk_09EE0A5C, gUnk_09EE0A78, gUnk_08AA7146, 3, 0, gUnk_08F69AC4, gUnk_08128DAC, gUnk_08128DEC, 32, 0 },
    { gUnk_09EE0008, gUnk_09EE0028, gUnk_089C44A8, 1, 0, gUnk_08F69904, gUnk_08128D9C, gUnk_08128D90, 32, 0 },
    { gUnk_09EE002C, gUnk_09EE0044, gUnk_089C8588, 1, 0, gUnk_08F69904, gUnk_08128D80, gUnk_08128D90, 32, 0 },
    { gUnk_09EE0048, gUnk_09EE0068, gUnk_089CB296, 3, 0, gUnk_08F69904, gUnk_08128D70, gUnk_08128D90, 32, 0 },
    { gUnk_09EE0074, gUnk_09EE0094, gUnk_089CF49A, 3, 0, gUnk_08F69904, gUnk_08128D60, gUnk_08128D90, 32, 0 },
    { gUnk_09EE00A0, gUnk_09EE00C4, gUnk_089D354A, 3, 0, gUnk_08F69904, gUnk_08128D50, gUnk_08128D90, 32, 0 },
    { gUnk_09EE0824, gUnk_09EE0844, gUnk_08A67796, 1, 0, gUnk_08F69A84, gUnk_08128D40, gUnk_08128D34, 32, 0 },
    { gUnk_09EE0848, gUnk_09EE0860, gUnk_08A6AA32, 1, 0, gUnk_08F69A84, gUnk_08128D24, gUnk_08128D34, 32, 0 },
    { gUnk_09EE0864, gUnk_09EE0874, gUnk_08A6DA7E, 1, 0, gUnk_08F69A84, gUnk_08128D14, gUnk_08128D34, 32, 0 },
    { gUnk_09EE0878, gUnk_09EE0890, gUnk_08A6FB4C, 1, 0, gUnk_08F69A84, gUnk_08128D04, gUnk_08128D34, 32, 0 },
    { gUnk_09EE0894, gUnk_09EE08CC, gUnk_08A72E8A, 4, 0, gUnk_08F69A84, gUnk_08128CF4, gUnk_08128D34, 32, 0 },
    { gUnk_09EE08DC, gUnk_09EE0910, gUnk_08A79200, 4, 0, gUnk_08F69A84, gUnk_08128CE4, gUnk_08128D34, 32, 0 },
    { gUnk_09EE0920, gUnk_09EE092C, gUnk_08A7D0F4, 2, 0, gUnk_08F69A84, gUnk_08128CD4, gUnk_08128D34, 32, 0 },
    { gUnk_09EDFA08, gUnk_09EDFA24, gUnk_08967A32, 1, 0, gUnk_08F697C4, gUnk_08128CC4, gUnk_08128CB8, 32, 0 },
    { gUnk_09EDFA28, gUnk_09EDFA48, gUnk_0896C03A, 1, 0, gUnk_08F697C4, gUnk_08128CA8, gUnk_08128CB8, 32, 0 },
    { gUnk_09EDFA4C, gUnk_09EDFA5C, gUnk_089717E4, 1, 0, gUnk_08F697C4, gUnk_08128C98, gUnk_08128CB8, 32, 0 },
    { gUnk_09EDFA60, gUnk_09EDFA7C, gUnk_089744FE, 1, 0, gUnk_08F697C4, gUnk_08128C88, gUnk_08128CB8, 32, 0 },
    { gUnk_09EDFA80, gUnk_09EDFAA0, gUnk_089789A4, 1, 0, gUnk_08F697C4, gUnk_08128C78, gUnk_08128CB8, 32, 0 },
    { gUnk_09EE0934, gUnk_09EE0954, gUnk_08A7E6E4, 1, 0, gUnk_08F69AA4, gUnk_08128C68, gUnk_08128C5C, 32, 0 },
    { gUnk_09EE0958, gUnk_09EE0978, gUnk_08A844FC, 1, 0, gUnk_08F69AA4, gUnk_08128C4C, gUnk_08128C5C, 32, 0 },
    { gUnk_09EE097C, gUnk_09EE098C, gUnk_08A8A10E, 1, 0, gUnk_08F69AA4, gUnk_08128C3C, gUnk_08128C5C, 32, 0 },
    { gUnk_09EE0990, gUnk_09EE09A8, gUnk_08A8D2C4, 1, 0, gUnk_08F69AA4, gUnk_08128C2C, gUnk_08128C5C, 32, 0 },
    { gUnk_09EE09AC, gUnk_09EE09CC, gUnk_08A91ACA, 1, 0, gUnk_08F69AA4, gUnk_08128C1C, gUnk_08128C5C, 32, 0 },
    { gUnk_09EE0370, gUnk_09EE038C, gUnk_08A0625A, 1, 0, gUnk_08F699A4, gUnk_08128C0C, gUnk_08128C00, 32, 0 },
    { gUnk_09EE0390, gUnk_09EE03A8, gUnk_08A0A3DA, 1, 0, gUnk_08F699A4, gUnk_08128BF0, gUnk_08128C00, 32, 0 },
    { gUnk_09EE03AC, gUnk_09EE03B8, gUnk_08A0DE08, 1, 0, gUnk_08F699A4, gUnk_08128BE0, gUnk_08128C00, 32, 0 },
    { gUnk_09EE03BC, gUnk_09EE03DC, gUnk_08A0FCAA, 1, 0, gUnk_08F699A4, gUnk_08128BD0, gUnk_08128C00, 32, 0 },
    { gUnk_09EE03E0, gUnk_09EE0420, gUnk_08A15034, 1, 0, gUnk_08F699A4, gUnk_08128BC0, gUnk_08128C00, 32, 0 },
    { gUnk_09EE0C58, gUnk_09EE0C80, gUnk_08AD3CFC, 1, 0, gUnk_08F69B04, gUnk_08128BB0, gUnk_08128BA4, 32, 0 },
    { gUnk_09EE0C84, gUnk_09EE0CA4, gUnk_08AD990E, 1, 0, gUnk_08F69B04, gUnk_08128B94, gUnk_08128BA4, 32, 0 },
    { gUnk_09EE0CA8, gUnk_09EE0CC8, gUnk_08ADE50C, 1, 0, gUnk_08F69B04, gUnk_08128B84, gUnk_08128BA4, 32, 0 },
    { gUnk_09EE0CCC, gUnk_09EE0CF4, gUnk_08AE35CC, 1, 0, gUnk_08F69B04, gUnk_08128B74, gUnk_08128BA4, 32, 0 },
    { gUnk_09EE0CF8, gUnk_09EE0D28, gUnk_08AEA246, 1, 0, gUnk_08F69B04, gUnk_08128B64, gUnk_08128BA4, 32, 0 },
    { gUnk_09EE0E2C, gUnk_09EE0E4C, gUnk_08AFF950, 1, 0, gUnk_08F69B44, gUnk_08128B54, gUnk_08128B48, 32, 0 },
    { gUnk_09EE0E50, gUnk_09EE0E70, gUnk_08B01336, 1, 0, gUnk_08F69B44, gUnk_08128B38, gUnk_08128B48, 32, 0 },
    { gUnk_09EE0E74, gUnk_09EE0EBC, gUnk_08B02F02, 3, 0, gUnk_08F69B44, gUnk_08128B28, gUnk_08128B48, 32, 0 },
    { gUnk_09EE0EC8, gUnk_09EE0EEC, gUnk_08B06B56, 1, 0, gUnk_08F69B44, gUnk_08128B18, gUnk_08128B48, 32, 0 },
    { gUnk_09EE0EF0, gUnk_09EE0F14, gUnk_08B08984, 1, 0, gUnk_08F69B44, gUnk_08128B08, gUnk_08128B48, 32, 0 },
    { gUnk_09EE0F18, gUnk_09EE0F38, gUnk_08B0AAE6, 1, 0, gUnk_08F69B64, gUnk_08128AF8, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE0F3C, gUnk_09EE0F58, gUnk_08B0C1D2, 1, 0, gUnk_08F69B64, gUnk_08128ADC, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE0F5C, gUnk_09EE0F80, gUnk_08B0D658, 1, 0, gUnk_08F69B64, gUnk_08128ACC, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE0F84, gUnk_09EE0FAC, gUnk_08B0EB86, 1, 0, gUnk_08F69B64, gUnk_08128ABC, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE0FB0, gUnk_09EE0FC8, gUnk_08B114B0, 3, 0, gUnk_08F69B64, gUnk_08128AAC, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE0FD4, gUnk_09EE0FF8, gUnk_08B1278E, 1, 0, gUnk_08F69B64, gUnk_08128A9C, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE0FFC, gUnk_09EE1020, gUnk_08B149BC, 1, 0, gUnk_08F69B64, gUnk_08128A8C, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE1024, gUnk_09EE1044, gUnk_08B16A8A, 1, 0, gUnk_08F69B84, gUnk_08128A7C, gUnk_08128A70, 32, 0 },
    { gUnk_09EE1048, gUnk_09EE1058, gUnk_08B185C6, 1, 0, gUnk_08F69B84, gUnk_08128A60, gUnk_08128A70, 32, 0 },
    { gUnk_09EE105C, gUnk_09EE1088, gUnk_08B19556, 2, 0, gUnk_08F69B84, gUnk_08128A50, gUnk_08128A70, 32, 0 },
    { gUnk_09EE1090, gUnk_09EE10A4, gUnk_08B1B854, 3, 0, gUnk_08F69B84, gUnk_08128A40, gUnk_08128A70, 32, 0 },
    { gUnk_09EE10B0, gUnk_09EE10D4, gUnk_08B1BAA8, 3, 0, gUnk_08F69B84, gUnk_08128A30, gUnk_08128A70, 32, 0 },
    { gUnk_09EE10E0, gUnk_09EE10E8, gUnk_08B1D846, 1, 0, gUnk_08F69B84, gUnk_08128A20, gUnk_08128A70, 32, 0 },
    { gUnk_09EE0A84, gUnk_09EE0A9C, gUnk_08AAB264, 1, 0, gUnk_09617C98, gUnk_08128A10, gUnk_08128A04, 32, 0 },
    { gUnk_09EE0AA0, gUnk_09EE0AB0, gUnk_08AAE8C6, 1, 0, gUnk_09617C98, gUnk_081289F4, gUnk_08128A04, 32, 0 },
    { gUnk_09EEE640, gUnk_09EEE658, gUnk_091DFA24, 1, 0, gUnk_09617C98, gUnk_081289E4, gUnk_08128A04, 32, 0 },
    { gUnk_09EE0AB4, gUnk_09EE0AC8, gUnk_08AB0C38, 1, 0, gUnk_09617C98, gUnk_081289D4, gUnk_08128A04, 32, 0 },
    { gUnk_09EE0ACC, gUnk_09EE0AE4, gUnk_08AB357C, 1, 0, gUnk_09617CB8, gUnk_081289C4, gUnk_081289B8, 32, 0 },
    { gUnk_09EE0AE8, gUnk_09EE0AF8, gUnk_08AB69D8, 1, 0, gUnk_09617CB8, gUnk_081289A8, gUnk_081289B8, 32, 0 },
    { gUnk_09EEE69C, gUnk_09EEE6B4, gUnk_091E8B6E, 1, 0, gUnk_09617CB8, gUnk_08128998, gUnk_081289B8, 32, 0 },
    { gUnk_09EE0AFC, gUnk_09EE0B14, gUnk_08AB8BE8, 1, 0, gUnk_09617CB8, gUnk_08128988, gUnk_081289B8, 32, 0 },
};

ObjDef gUnk_09ED07B4[] = {
    { gUnk_09EDE4F0, gUnk_09EDE50C, gUnk_0886ADEC, 3, 0, gUnk_08F68384, gUnk_081296CC, gUnk_081296C0, 32, 0 },
    { gUnk_09EDE518, gUnk_09EDE534, gUnk_0886E396, 1, 0, gUnk_08F68384, gUnk_081296B0, gUnk_081296C0, 32, 0 },
    { gUnk_09EDE538, gUnk_09EDE540, gUnk_088717D8, 2, 0, gUnk_08F68384, gUnk_081296A0, gUnk_081296C0, 32, 0 },
    { gUnk_09EDE548, gUnk_09EDE584, gUnk_088724E2, 4, 0, gUnk_09617C58, gUnk_0812968C, gUnk_08129680, 32, 0 },
    { gUnk_09EDE6AC, gUnk_09EDE6D4, gUnk_08888D44, 3, 0, gUnk_08F6DC24, gUnk_08129670, gUnk_08129664, 32, 0 },
    { gUnk_09EDE6E0, gUnk_09EDE70C, gUnk_0888F218, 2, 0, gUnk_08F6DC24, gUnk_08129654, gUnk_08129664, 32, 0 },
    { gUnk_09EDE714, gUnk_09EDE720, gUnk_08895A7E, 1, 0, gUnk_08F6DC24, gUnk_08129644, gUnk_08129664, 32, 0 },
    { gUnk_09EDE724, gUnk_09EDE740, gUnk_08897494, 1, 0, gUnk_08F6DC24, gUnk_08129634, gUnk_08129664, 32, 0 },
    { gUnk_09EDE744, gUnk_09EDE764, gUnk_0889B1A4, 1, 0, gUnk_08F6DC24, gUnk_08129624, gUnk_08129664, 32, 0 },
    { gUnk_09EDE768, gUnk_09EDE78C, gUnk_0889F73C, 1, 0, gUnk_08F6DC24, gUnk_08129614, gUnk_08129664, 32, 0 },
    { gUnk_09EDE7F0, gUnk_09EDE810, gUnk_088A6022, 1, 0, gUnk_09618018, gUnk_08129604, gUnk_081295F8, 32, 0 },
    { gUnk_09EDE790, gUnk_09EDE7B0, gUnk_088A4ADE, 1, 0, gUnk_09617FF8, gUnk_081295EC, gUnk_081295E0, 32, 0 },
    { gUnk_09EDE814, gUnk_09EDE834, gUnk_088AAB32, 5, 0, gUnk_09618038, gUnk_081295D0, gUnk_081295C4, 32, 0 },
    { gUnk_09EDE5FC, gUnk_09EDE630, gUnk_0887A400, 3, 0, gUnk_09617D98, gUnk_081295B4, gUnk_081295A8, 32, 0 },
    { gUnk_09EDE63C, gUnk_09EDE654, gUnk_088801BE, 4, 0, gUnk_09617DD8, gUnk_08129598, gUnk_0812958C, 32, 0 },
    { gUnk_09EDE878, gUnk_09EDE898, gUnk_088B087C, 2, 0, gUnk_09618298, gUnk_0812957C, gUnk_08129570, 32, 0 },
    { gUnk_09EDE664, gUnk_09EDE680, gUnk_08881798, 2, 0, gUnk_09617E18, gUnk_0812955C, gUnk_08129550, 32, 0 },
    { gUnk_09EDE8A0, gUnk_09EDE8C0, gUnk_088B4A9C, 3, 0, gUnk_096183F8, gUnk_08129540, gUnk_08129534, 32, 0 },
};

ObjDef gUnk_09ED09F4[] = {
    { gUnk_09EE21BC, gUnk_09EE21DC, gUnk_08C1ED72, 1, 0, gUnk_09618478, gUnk_08129F3C, gUnk_08129F30, 32, 0 },
    { gUnk_09EE21E0, gUnk_09EE21EC, gUnk_08C238AC, 1, 0, gUnk_09618478, gUnk_08129F20, gUnk_08129F30, 32, 0 },
    { gUnk_09EE21F0, gUnk_09EE2200, gUnk_08C25516, 1, 0, gUnk_09618478, gUnk_08129F10, gUnk_08129F30, 32, 0 },
    { gUnk_09EE2204, gUnk_09EE2224, gUnk_08C27FBE, 2, 0, gUnk_09618478, gUnk_08129F00, gUnk_08129F30, 32, 0 },
    { gUnk_09EE222C, gUnk_09EE2248, gUnk_08C2D1B6, 2, 0, gUnk_09618478, gUnk_08129EF0, gUnk_08129F30, 32, 0 },
    { gUnk_09EE2250, gUnk_09EE2288, gUnk_08C3151E, 4, 0, gUnk_09618478, gUnk_08129EE0, gUnk_08129F30, 32, 0 },
    { gUnk_09EE2298, gUnk_09EE22B0, gUnk_08C3724C, 1, 0, gUnk_09618478, gUnk_08129ECC, gUnk_08129F30, 32, 0 },
    { gUnk_09EE22B4, gUnk_09EE22D8, gUnk_08C3866C, 2, 0, gUnk_09618478, gUnk_08129EBC, gUnk_08129F30, 32, 0 },
    { gUnk_09EE22E0, gUnk_09EE2308, gUnk_08C3D7E6, 1, 0, gUnk_09618478, gUnk_08129EAC, gUnk_08129F30, 32, 0 },
    { gUnk_09EE230C, gUnk_09EE2338, gUnk_08C42BBE, 1, 0, gUnk_08F6DCC4, gUnk_08129E98, gUnk_08129E84, 32, 0 },
    { gUnk_09EE233C, gUnk_09EE239C, gUnk_08C46790, 7, 0, gUnk_08F6DCE4, gUnk_08129E70, gUnk_08129E5C, 32, 0 },
    { gUnk_09EE1CBC, gUnk_09EE1CD0, gUnk_08BCB542, 1, 0, gUnk_09618458, gUnk_08129E4C, gUnk_08129E40, 32, 0 },
    { gUnk_09EE1CD4, gUnk_09EE1CE8, gUnk_08BCCC34, 2, 0, gUnk_09618458, gUnk_08129E30, gUnk_08129E40, 32, 0 },
    { gUnk_09EE1CF0, gUnk_09EE1D00, gUnk_08BCE468, 1, 0, gUnk_09618458, gUnk_08129E1C, gUnk_08129E40, 32, 0 },
    { gUnk_09EE1D04, gUnk_09EE1D38, gUnk_08BCFC2A, 5, 0, gUnk_09618458, gUnk_08129E08, gUnk_08129E40, 32, 0 },
    { gUnk_09EE1D4C, gUnk_09EE1D88, gUnk_08BD46AE, 7, 0, gUnk_09618458, gUnk_08129DF4, gUnk_08129E40, 32, 0 },
    { gUnk_09EE1DA4, gUnk_09EE1DB4, gUnk_08BD99F4, 2, 0, gUnk_09618458, gUnk_08129DE0, gUnk_08129E40, 32, 0 },
    { gUnk_09EE1DBC, gUnk_09EE1DDC, gUnk_08BD9D9C, 1, 0, gUnk_09618458, gUnk_08129DC8, gUnk_08129E40, 32, 0 },
    { gUnk_09EE23B8, gUnk_09EE23D0, gUnk_08C492E2, 2, 0, gUnk_09618338, gUnk_08129DB4, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE23D8, gUnk_09EE23F8, gUnk_08C4AEA0, 1, 0, gUnk_09618338, gUnk_08129D90, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE23FC, gUnk_09EE2410, gUnk_08C4D30E, 1, 0, gUnk_09618338, gUnk_08129D7C, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 7, 0, gUnk_09618338, gUnk_08129D68, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE2458, gUnk_09EE2480, gUnk_08C51312, 4, 0, gUnk_09618338, gUnk_08129D54, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE2490, gUnk_09EE24C0, gUnk_08C5411E, 2, 0, gUnk_09618338, gUnk_08129D3C, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE24C8, gUnk_09EE24E4, gUnk_08C579A4, 2, 0, gUnk_09618338, gUnk_08129D24, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE24EC, gUnk_09EE2518, gUnk_08C5997A, 3, 0, gUnk_09618338, gUnk_08129D10, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 3, 0, gUnk_09618338, gUnk_08129CF8, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 3, 0, gUnk_09618338, gUnk_08129CE0, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE2584, gUnk_09EE25A4, gUnk_08C61980, 1, 0, gUnk_09618338, gUnk_08129CC8, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE25A8, gUnk_09EE25CC, gUnk_08C63E3C, 1, 0, gUnk_09618338, gUnk_08129CB0, gUnk_08129DA4, 32, 0 },
    { gUnk_09EE1FDC, gUnk_09EE1FEC, gUnk_08BF7A1A, 1, 0, gUnk_096183B8, gUnk_08129CA0, gUnk_08129C94, 32, 0 },
    { gUnk_09EE2000, gUnk_09EE2010, gUnk_08BFB696, 1, 0, gUnk_096183B8, gUnk_08129C84, gUnk_08129C94, 32, 0 },
    { gUnk_09EE2014, gUnk_09EE2030, gUnk_08BFD4A2, 1, 0, gUnk_096183B8, gUnk_08129C74, gUnk_08129C94, 32, 0 },
    { gUnk_09EE1FF0, gUnk_09EE1FFC, gUnk_08BF97D4, 1, 0, gUnk_096183B8, gUnk_08129C64, gUnk_08129C94, 32, 0 },
    { gUnk_09EE2034, gUnk_09EE2048, gUnk_08C00AB6, 3, 0, gUnk_096183B8, gUnk_08129C54, gUnk_08129C94, 32, 0 },
    { gUnk_09EE2054, gUnk_09EE2070, gUnk_08C0319C, 1, 0, gUnk_096183B8, gUnk_08129C44, gUnk_08129C94, 32, 0 },
    { gUnk_09EE2074, gUnk_09EE2088, gUnk_08C067EC, 4, 0, gUnk_096183B8, gUnk_08129C34, gUnk_08129C94, 32, 0 },
    { gUnk_09EE20B4, gUnk_09EE20E4, gUnk_08C0B5EE, 1, 0, gUnk_096183B8, gUnk_08129C24, gUnk_08129C94, 32, 0 },
    { gUnk_09EE2690, gUnk_09EE26B0, gUnk_08EE3A84, 1, 0, gUnk_08F6DCA4, gUnk_08129C14, gUnk_08129C08, 32, 0 },
    { gUnk_09EE26B4, gUnk_09EE26CC, gUnk_08EE4264, 2, 0, gUnk_08F6DCA4, gUnk_08129BF8, gUnk_08129C08, 32, 0 },
    { gUnk_09EE20E8, gUnk_09EE2110, gUnk_08C10A58, 4, 0, gUnk_08F6DCA4, gUnk_08129BE4, gUnk_08129C08, 32, 0 },
    { gUnk_09EE2120, gUnk_09EE2138, gUnk_08C1516A, 3, 0, gUnk_08F6DCA4, gUnk_08129BD4, gUnk_08129C08, 32, 0 },
    { gUnk_09EE2144, gUnk_09EE215C, gUnk_08C1837E, 3, 0, gUnk_08F6DCA4, gUnk_08129BC4, gUnk_08129C08, 32, 0 },
    { gUnk_09EE2168, gUnk_09EE2180, gUnk_08C1B592, 3, 0, gUnk_08F6DCA4, gUnk_08129BB4, gUnk_08129C08, 32, 0 },
    { gUnk_09EE218C, gUnk_09EE21A4, gUnk_08C1E78C, 6, 0, gUnk_08F6DCA4, gUnk_08129B9C, gUnk_08129C08, 32, 0 },
    { gUnk_09EE1DE0, gUnk_09EE1DF8, gUnk_08BDC7B6, 1, 0, gUnk_096180F8, gUnk_08129B8C, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1DFC, gUnk_09EE1E0C, gUnk_08BDF086, 1, 0, gUnk_096180F8, gUnk_08129B70, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1E10, gUnk_09EE1E24, gUnk_08BE1504, 1, 0, gUnk_096180F8, gUnk_08129B60, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1E28, gUnk_09EE1E50, gUnk_08BE412A, 5, 0, gUnk_096180F8, gUnk_08129B50, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1E64, gUnk_09EE1E74, gUnk_08BE95F8, 3, 0, gUnk_096180F8, gUnk_08129B40, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1FCC, gUnk_09EE1FD8, gUnk_08BF76FE, 1, 0, gUnk_096180F8, gUnk_08129B2C, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1E80, gUnk_09EE1EA4, gUnk_08BEB9A0, 3, 0, gUnk_096180F8, gUnk_08129B1C, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1EB0, gUnk_09EE1EE8, gUnk_08BEEBAA, 3, 0, gUnk_096180F8, gUnk_08129B0C, gUnk_08129B80, 32, 0 },
    { gUnk_09EE1EF4, gUnk_09EE1F6C, gUnk_08BF50CA, 9, 0, gUnk_08F69BA4, gUnk_08129AF8, gUnk_08129AE8, 32, 0 },
    { gUnk_09EE1B84, gUnk_09EE1B94, gUnk_08BB1F72, 1, 0, gUnk_09618438, gUnk_08129AD4, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1B98, gUnk_09EE1BA8, gUnk_08BB37EA, 1, 0, gUnk_09618438, gUnk_08129AB4, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1BAC, gUnk_09EE1BC0, gUnk_08BB5ABC, 1, 0, gUnk_09618438, gUnk_08129AA0, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1BC4, gUnk_09EE1BE4, gUnk_08BB86CC, 5, 0, gUnk_09618438, gUnk_08129A8C, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1BF8, gUnk_09EE1C20, gUnk_08BBD3CA, 1, 0, gUnk_09618438, gUnk_08129A78, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1C24, gUnk_09EE1C4C, gUnk_08BC2318, 1, 0, gUnk_09618438, gUnk_08129A64, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1C50, gUnk_09EE1C68, gUnk_08BC70E8, 3, 0, gUnk_09618438, gUnk_08129A50, gUnk_08129AC8, 32, 0 },
    { gUnk_09EE1C74, gUnk_09EE1C90, gUnk_08BCA01C, 1, 0, gUnk_08F6DC84, gUnk_08129A3C, gUnk_08129A28, 32, 0 },
    { gUnk_09EE1C94, gUnk_09EE1CB4, gUnk_08BCB3D8, 2, 0, gUnk_08F6DC84, gUnk_08129A14, gUnk_08129A28, 32, 0 },
    { gUnk_09EDE688, gUnk_09EDE69C, gUnk_08885C06, 4, 0, gUnk_08F6DC24, gUnk_08129A04, gUnk_08129664, 32, 0 },
    { gUnk_09EDE6AC, gUnk_09EDE6D4, gUnk_08888D44, 3, 0, gUnk_08F6DC24, gUnk_08129670, gUnk_08129664, 32, 0 },
    { gUnk_09EDE6E0, gUnk_09EDE70C, gUnk_0888F218, 2, 0, gUnk_08F6DC24, gUnk_08129654, gUnk_08129664, 32, 0 },
    { gUnk_09EDE714, gUnk_09EDE720, gUnk_08895A7E, 1, 0, gUnk_08F6DC24, gUnk_08129644, gUnk_08129664, 32, 0 },
    { gUnk_09EDE724, gUnk_09EDE740, gUnk_08897494, 1, 0, gUnk_08F6DC24, gUnk_08129634, gUnk_08129664, 32, 0 },
    { gUnk_09EDE744, gUnk_09EDE764, gUnk_0889B1A4, 1, 0, gUnk_08F6DC24, gUnk_08129624, gUnk_08129664, 32, 0 },
    { gUnk_09EDE768, gUnk_09EDE78C, gUnk_0889F73C, 1, 0, gUnk_08F6DC24, gUnk_08129614, gUnk_08129664, 32, 0 },
    { gUnk_09EE15FC, gUnk_09EE1614, gUnk_08B268D2, 1, 0, gUnk_08F6DC24, gUnk_081299F4, gUnk_08129664, 32, 0 },
    { gUnk_09EE1618, gUnk_09EE1638, gUnk_08B2A57A, 1, 0, gUnk_08F6DC24, gUnk_081299E4, gUnk_08129664, 32, 0 },
    { gUnk_09EE163C, gUnk_09EE1650, gUnk_08B2F5FE, 1, 0, gUnk_08F6DC24, gUnk_081299D4, gUnk_08129664, 32, 0 },
    { gUnk_09EE1654, gUnk_09EE1670, gUnk_08B326C8, 5, 0, gUnk_08F6DC24, gUnk_081299C4, gUnk_08129664, 32, 0 },
    { gUnk_09EE1684, gUnk_09EE16A4, gUnk_08B36DEC, 1, 0, gUnk_09618158, gUnk_081299B4, gUnk_081299A8, 32, 0 },
    { gUnk_09EE16A8, gUnk_09EE16C8, gUnk_08B3BFE6, 1, 0, gUnk_09618158, gUnk_08129998, gUnk_081299A8, 32, 0 },
    { gUnk_09EE16CC, gUnk_09EE16E4, gUnk_08B4181C, 1, 0, gUnk_09618158, gUnk_08129988, gUnk_081299A8, 32, 0 },
    { gUnk_09EE16E8, gUnk_09EE170C, gUnk_08B452A4, 5, 0, gUnk_09618158, gUnk_08129978, gUnk_081299A8, 32, 0 },
    { gUnk_09EE1720, gUnk_09EE173C, gUnk_08B4A9A0, 1, 0, gUnk_09618158, gUnk_08129968, gUnk_081299A8, 32, 0 },
    { gUnk_09EE1740, gUnk_09EE1768, gUnk_08B4ECCA, 3, 0, gUnk_09618158, gUnk_08129958, gUnk_081299A8, 32, 0 },
    { gUnk_09EE1774, gUnk_09EE1794, gUnk_08B54EC0, 1, 0, gUnk_09618158, gUnk_08129948, gUnk_081299A8, 32, 0 },
    { gUnk_09EE1798, gUnk_09EE17AC, gUnk_08B59E52, 2, 0, gUnk_08F6DC44, gUnk_08129938, gUnk_08129928, 32, 0 },
    { gUnk_09EE17C0, gUnk_09EE17D0, gUnk_08B5B51E, 1, 0, gUnk_09618318, gUnk_08129918, gUnk_0812990C, 32, 0 },
    { gUnk_09EE17D4, gUnk_09EE17E4, gUnk_08B5CC5E, 1, 0, gUnk_09618318, gUnk_081298FC, gUnk_0812990C, 32, 0 },
    { gUnk_09EE17E8, gUnk_09EE1814, gUnk_08B5E3CA, 1, 0, gUnk_09618318, gUnk_081298EC, gUnk_0812990C, 32, 0 },
    { gUnk_09EE1818, gUnk_09EE1830, gUnk_08B621F8, 1, 0, gUnk_09618318, gUnk_081298DC, gUnk_0812990C, 32, 0 },
    { gUnk_09EE1834, gUnk_09EE184C, gUnk_08B64412, 3, 0, gUnk_09618318, gUnk_081298CC, gUnk_0812990C, 32, 0 },
    { gUnk_09EE1858, gUnk_09EE1878, gUnk_08B67572, 1, 0, gUnk_09618378, gUnk_081298B8, gUnk_081298A8, 32, 0 },
    { gUnk_09EE187C, gUnk_09EE1890, gUnk_08B6C8F2, 1, 0, gUnk_09618378, gUnk_08129894, gUnk_081298A8, 32, 0 },
    { gUnk_09EE1894, gUnk_09EE18B0, gUnk_08B704A2, 1, 0, gUnk_09618378, gUnk_08129880, gUnk_081298A8, 32, 0 },
    { gUnk_09EE18B4, gUnk_09EE18D8, gUnk_08B748D0, 1, 0, gUnk_09618378, gUnk_0812986C, gUnk_081298A8, 32, 0 },
    { gUnk_09EE18DC, gUnk_09EE18F8, gUnk_08B7B81C, 2, 0, gUnk_09618378, gUnk_08129858, gUnk_081298A8, 32, 0 },
    { gUnk_09EE1900, gUnk_09EE191C, gUnk_08B7DF70, 1, 0, gUnk_09618378, gUnk_08129844, gUnk_081298A8, 32, 0 },
    { gUnk_09EE1920, gUnk_09EE1930, gUnk_08B82F32, 3, 0, gUnk_09618378, gUnk_08129830, gUnk_081298A8, 32, 0 },
    { gUnk_09EE193C, gUnk_09EE1950, gUnk_08B85CB4, 1, 0, gUnk_09617F18, gUnk_08129818, gUnk_0812980C, 32, 0 },
    { gUnk_09EE1954, gUnk_09EE1968, gUnk_08B88BD4, 1, 0, gUnk_09617F18, gUnk_081297F4, gUnk_0812980C, 32, 0 },
    { gUnk_09EE196C, gUnk_09EE1988, gUnk_08B8BE78, 1, 0, gUnk_09617F18, gUnk_081297E0, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF3D0, gUnk_09EEF3F0, gUnk_092A5250, 1, 0, gUnk_09617F18, gUnk_081297CC, gUnk_0812980C, 32, 0 },
    { gUnk_09EE198C, gUnk_09EE19C8, gUnk_08B90EDA, 1, 0, gUnk_09617F18, gUnk_081297B8, gUnk_0812980C, 32, 0 },
    { gUnk_09EE19F4, gUnk_09EE1A2C, gUnk_08B971A4, 1, 0, gUnk_09617F18, gUnk_081297A4, gUnk_0812980C, 32, 0 },
    { gUnk_09EE1A30, gUnk_09EE1A54, gUnk_08B9CCEE, 1, 0, gUnk_09617F18, gUnk_0812978C, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF444, gUnk_09EEF474, gUnk_092B03A2, 3, 0, gUnk_09617F38, gUnk_0812977C, gUnk_0812976C, 32, 0 },
    { gUnk_09EE19CC, gUnk_09EE19F0, gUnk_08B95CE2, 1, 0, gUnk_08F69BA4, gUnk_08129754, gUnk_08129AE8, 32, 0 },
    { gUnk_09EE1A58, gUnk_09EE1AB4, gUnk_08BA17EE, 3, 0, gUnk_08F69BA4, gUnk_0812973C, gUnk_08129AE8, 32, 0 },
    { gUnk_09EE1AC0, gUnk_09EE1ADC, gUnk_08BA4592, 1, 0, gUnk_08F69BA4, gUnk_08129724, gUnk_08129AE8, 32, 0 },
    { gUnk_09EE1AE0, gUnk_09EE1AF8, gUnk_08BA6EAE, 1, 0, gUnk_08F69BA4, gUnk_08129710, gUnk_08129AE8, 32, 0 },
    { gUnk_09EE1AFC, gUnk_09EE1B28, gUnk_08BA9958, 4, 0, gUnk_09617F18, gUnk_081296F8, gUnk_0812980C, 32, 0 },
    { gUnk_09EE1B38, gUnk_09EE1B78, gUnk_08BAFB62, 3, 0, gUnk_08F69BA4, gUnk_081296DC, gUnk_08129AE8, 32, 0 },
};

ObjDef gUnk_09ED1774[] = {
    { gUnk_09EEFCAC, gUnk_09EEFD38, gUnk_09320796, 10, 0, gUnk_08F69BA4, gUnk_0812BA9C, gUnk_08129AE8, 32, 0 },
    { gUnk_09EF0C70, gUnk_09EF0CD4, gUnk_093D7BDA, 15, 0, gUnk_09618498, gUnk_0812BA8C, gUnk_0812BA80, 32, 0 },
    { gUnk_09EF0D10, gUnk_09EF0D20, gUnk_093DE54C, 3, 0, gUnk_09618498, gUnk_0812BA70, gUnk_0812BA80, 32, 0 },
    { gUnk_09EEF6E0, gUnk_09EEF6E4, gUnk_092D6544, 1, 0, gUnk_096180D8, gUnk_0812BA5C, gUnk_0812BA4C, 32, 0 },
    { gUnk_09EEF6E8, gUnk_09EEF6EC, gUnk_092D6758, 1, 0, gUnk_096180D8, gUnk_0812BA38, gUnk_0812BA4C, 32, 0 },
    { gUnk_09EEF71C, gUnk_09EEF744, gUnk_092D7F0E, 1, 0, gUnk_096180D8, gUnk_0812BA24, gUnk_0812BA4C, 32, 0 },
    { gUnk_09EF0F2C, gUnk_09EF0F5C, gUnk_093EC8A4, 2, 0, gUnk_09618538, gUnk_0812BA10, gUnk_0812B9FC, 32, 0 },
    { gUnk_09EF0EF8, gUnk_09EF0F20, gUnk_093EB8AA, 3, 0, gUnk_09849A98, gUnk_0812B9EC, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EEF49C, gUnk_09EEF4B4, gUnk_092B6E7E, 1, 0, gUnk_09617F58, gUnk_0812B9D0, gUnk_0812B9C0, 32, 0 },
    { gUnk_09EEF4B8, gUnk_09EEF4E0, gUnk_092B769C, 1, 0, gUnk_09617F58, gUnk_0812B9B0, gUnk_0812B9C0, 32, 0 },
    { gUnk_09EF0ED8, gUnk_09EF0EF0, gUnk_093EB4CC, 2, 0, gUnk_09618518, gUnk_0812B9A4, gUnk_0812B998, 32, 0 },
    { gUnk_09EF06CC, gUnk_09EF0708, gUnk_09393CCA, 9, 0, gUnk_096183B8, gUnk_0812B988, gUnk_08129C94, 32, 0 },
    { gUnk_09EF072C, gUnk_09EF0738, gUnk_093990DE, 1, 0, gUnk_096183B8, gUnk_0812B978, gUnk_08129C94, 32, 0 },
    { gUnk_09EF073C, gUnk_09EF0758, gUnk_0939A37A, 3, 0, gUnk_096183B8, gUnk_0812B968, gUnk_08129C94, 32, 0 },
    { gUnk_09EF078C, gUnk_09EF07A4, gUnk_0939D6B2, 3, 0, gUnk_096183B8, gUnk_0812B958, gUnk_08129C94, 32, 0 },
    { gUnk_09EF07B0, gUnk_09EF07D0, gUnk_0939F560, 1, 0, gUnk_096183B8, gUnk_0812B948, gUnk_08129C94, 32, 0 },
    { gUnk_09EF0764, gUnk_09EF077C, gUnk_0939BAB6, 4, 0, gUnk_096183B8, gUnk_0812B938, gUnk_08129C94, 32, 0 },
    { gUnk_09EEF89C, gUnk_09EEF8C0, gUnk_092EB78A, 2, 0, gUnk_09618118, gUnk_0812B928, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF894, gUnk_09EEF898, gUnk_092EB288, 1, 0, gUnk_09618118, gUnk_0812B90C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF8C8, gUnk_09EEF8CC, gUnk_092ED580, 1, 0, gUnk_09618118, gUnk_0812B8FC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF960, gUnk_09EEF96C, gUnk_092F4966, 2, 0, gUnk_09618118, gUnk_0812B8EC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF974, gUnk_09EEF97C, gUnk_092F5514, 2, 0, gUnk_09618118, gUnk_0812B8DC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF984, gUnk_09EEF98C, gUnk_092F5D4C, 2, 0, gUnk_09618118, gUnk_0812B8CC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF9DC, gUnk_09EEF9E8, gUnk_092FA4FA, 2, 0, gUnk_09618118, gUnk_0812B8BC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF9F0, gUnk_09EEFA00, gUnk_092FB00A, 4, 0, gUnk_09618118, gUnk_0812B8AC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA10, gUnk_09EEFA1C, gUnk_092FBECA, 2, 0, gUnk_09618118, gUnk_0812B89C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA24, gUnk_09EEFA34, gUnk_092FC904, 2, 0, gUnk_09618118, gUnk_0812B88C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA3C, gUnk_09EEFA44, gUnk_092FD688, 2, 0, gUnk_09618118, gUnk_0812B87C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF8D0, gUnk_09EEF8F0, gUnk_092ED9F6, 1, 0, gUnk_09618118, gUnk_0812B86C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF8F4, gUnk_09EEF914, gUnk_092EFAD4, 1, 0, gUnk_09618118, gUnk_0812B85C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF918, gUnk_09EEF938, gUnk_092F15E4, 1, 0, gUnk_09618118, gUnk_0812B84C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA70, gUnk_09EEFA90, gUnk_092FF906, 1, 0, gUnk_09618118, gUnk_0812B83C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF93C, gUnk_09EEF95C, gUnk_092F31E0, 1, 0, gUnk_09618118, gUnk_0812B82C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF994, gUnk_09EEF9B4, gUnk_092F65A2, 1, 0, gUnk_09618118, gUnk_0812B81C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF9B8, gUnk_09EEF9D8, gUnk_092F881A, 1, 0, gUnk_09618118, gUnk_0812B80C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA4C, gUnk_09EEFA6C, gUnk_092FDDC6, 1, 0, gUnk_09618118, gUnk_0812B7FC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA94, gUnk_09EEFAA0, gUnk_09300FC4, 1, 0, gUnk_09618118, gUnk_0812B7EC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFAA4, gUnk_09EEFAAC, gUnk_093020E6, 1, 0, gUnk_09618118, gUnk_0812B7DC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFAB0, gUnk_09EEFAD4, gUnk_093029E0, 4, 0, gUnk_09618118, gUnk_0812B7CC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFAE4, gUnk_09EEFAEC, gUnk_093044F2, 2, 0, gUnk_09618118, gUnk_0812B7BC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFAF4, gUnk_09EEFB0C, gUnk_09305220, 4, 0, gUnk_09618118, gUnk_0812B7AC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFB1C, gUnk_09EEFB28, gUnk_0930782E, 1, 0, gUnk_09618118, gUnk_0812B79C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFB2C, gUnk_09EEFB38, gUnk_0930812E, 2, 0, gUnk_09618118, gUnk_0812B78C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFB40, gUnk_09EEFB54, gUnk_09308D8E, 2, 0, gUnk_09618118, gUnk_0812B77C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFB5C, gUnk_09EEFB64, gUnk_0930A1B2, 1, 0, gUnk_09618118, gUnk_0812B76C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFB68, gUnk_09EEFB84, gUnk_0930AA56, 4, 0, gUnk_09618118, gUnk_0812B75C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFB94, gUnk_09EEFBA0, gUnk_0930DE0E, 1, 0, gUnk_09618118, gUnk_0812B74C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEB150, gUnk_09EEB180, gUnk_090A8FC4, 2, 0, gUnk_09618118, gUnk_0812B738, gUnk_0812B91C, 32, 0 },
    { gUnk_09EF0D48, gUnk_09EF0D64, gUnk_093E1EE0, 6, 0, gUnk_096184D8, gUnk_0812B728, gUnk_0812B71C, 32, 0 },
    { gUnk_09EF0D7C, gUnk_09EF0DA4, gUnk_093E2D02, 7, 0, gUnk_096184D8, gUnk_0812B70C, gUnk_0812B71C, 32, 0 },
    { gUnk_09EF0DC0, gUnk_09EF0E14, gUnk_093E3F38, 13, 0, gUnk_096184D8, gUnk_0812B6FC, gUnk_0812B71C, 32, 0 },
    { gUnk_09EF0E6C, gUnk_09EF0E8C, gUnk_093E7C92, 1, 0, gUnk_096184D8, gUnk_0812B6EC, gUnk_0812B71C, 32, 0 },
    { gUnk_09EF0E48, gUnk_09EF0E68, gUnk_093E64DE, 1, 0, gUnk_096184D8, gUnk_0812B6DC, gUnk_0812B71C, 32, 0 },
    { gUnk_09EF0E90, gUnk_09EF0EB0, gUnk_093E91C4, 1, 0, gUnk_096184D8, gUnk_0812B6CC, gUnk_0812B71C, 32, 0 },
    { gUnk_09EEFE70, gUnk_09EEFE98, gUnk_09322A1A, 10, 0, gUnk_09618198, gUnk_0812B6C0, gUnk_0812B6B4, 32, 0 },
    { gUnk_09EF0D2C, gUnk_09EF0D40, gUnk_093DF636, 2, 0, gUnk_096184B8, gUnk_0812B6A4, gUnk_0812B69C, 32, 0 },
    { gUnk_09EF0454, gUnk_09EF0458, gUnk_09376574, 1, 0, gUnk_09618318, gUnk_0812B68C, gUnk_0812990C, 32, 0 },
    { gUnk_09EF045C, gUnk_09EF047C, gUnk_09376BC6, 1, 0, gUnk_09618318, gUnk_0812B67C, gUnk_0812990C, 32, 0 },
    { gUnk_09EF0480, gUnk_09EF0498, gUnk_0937994C, 2, 0, gUnk_09618318, gUnk_0812B66C, gUnk_0812990C, 32, 0 },
    { gUnk_09EF04CC, gUnk_09EF04D0, gUnk_0937E3B8, 1, 0, gUnk_09618318, gUnk_0812B65C, gUnk_0812990C, 32, 0 },
    { gUnk_09EF04A0, gUnk_09EF04AC, gUnk_0937B9A4, 1, 0, gUnk_09618318, gUnk_0812B64C, gUnk_0812990C, 32, 0 },
    { gUnk_09EF04B0, gUnk_09EF04C8, gUnk_0937C8D6, 1, 0, gUnk_09618318, gUnk_0812B63C, gUnk_0812990C, 32, 0 },
    { gUnk_09EF0BFC, gUnk_09EF0C00, gUnk_093CF228, 1, 0, gUnk_09618478, gUnk_0812B62C, gUnk_08129F30, 32, 0 },
    { gUnk_09EF0C04, gUnk_09EF0C08, gUnk_093CF8C8, 1, 0, gUnk_09618478, gUnk_0812B61C, gUnk_08129F30, 32, 0 },
    { gUnk_09EF0C0C, gUnk_09EF0C2C, gUnk_093CFFC4, 1, 0, gUnk_09618478, gUnk_0812B608, gUnk_08129F30, 32, 0 },
    { gUnk_09EF0C30, gUnk_09EF0C34, gUnk_093D2F10, 1, 0, gUnk_09618478, gUnk_0812B5F8, gUnk_08129F30, 32, 0 },
    { gUnk_09EF0C38, gUnk_09EF0C4C, gUnk_093D35FA, 2, 0, gUnk_09618478, gUnk_0812B5E8, gUnk_08129F30, 32, 0 },
    { gUnk_09EF0C54, gUnk_09EF0C6C, gUnk_093D5346, 1, 0, gUnk_09618478, gUnk_0812B5D8, gUnk_08129F30, 32, 0 },
    { gUnk_09EF0A50, gUnk_09EF0AA8, gUnk_093BB982, 10, 0, gUnk_09618458, gUnk_0812B5C8, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0B30, gUnk_09EF0B48, gUnk_093C6304, 2, 0, gUnk_09618458, gUnk_0812B5B8, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0B50, gUnk_09EF0B70, gUnk_093C7BEA, 1, 0, gUnk_09618458, gUnk_0812B5A8, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0B74, gUnk_09EF0BB8, gUnk_093CA1AA, 3, 0, gUnk_09618458, gUnk_0812B598, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0BC4, gUnk_09EF0BD8, gUnk_093CD962, 1, 0, gUnk_09618458, gUnk_0812B588, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0BDC, gUnk_09EF0BEC, gUnk_093CEE46, 4, 0, gUnk_09618458, gUnk_0812B578, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0AD0, gUnk_09EF0AF8, gUnk_093C1456, 5, 0, gUnk_09618458, gUnk_0812B568, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0B0C, gUnk_09EF0B2C, gUnk_093C3E7E, 1, 0, gUnk_09618458, gUnk_0812B558, gUnk_08129E40, 32, 0 },
    { gUnk_09EF0930, gUnk_09EF0934, gUnk_093AECCE, 1, 0, gUnk_09618438, gUnk_0812B544, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF0938, gUnk_09EF0958, gUnk_093AF202, 1, 0, gUnk_09618438, gUnk_0812B530, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF095C, gUnk_09EF0970, gUnk_093B16DA, 2, 0, gUnk_09618438, gUnk_0812B51C, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF0A14, gUnk_09EF0A18, gUnk_093B804A, 1, 0, gUnk_09618438, gUnk_0812B508, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF0A1C, gUnk_09EF0A3C, gUnk_093B8578, 1, 0, gUnk_09618438, gUnk_0812B4F4, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF0A40, gUnk_09EF0A4C, gUnk_093BA9DA, 1, 0, gUnk_09618438, gUnk_0812B4E0, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF0978, gUnk_09EF09AC, gUnk_093B3122, 4, 0, gUnk_09618438, gUnk_0812B4CC, gUnk_08129AC8, 32, 0 },
    { gUnk_09EF09BC, gUnk_09EF0A0C, gUnk_093B7610, 2, 0, gUnk_08F6DC84, gUnk_0812B4B4, gUnk_08129A28, 32, 0 },
    { gUnk_09EEE1B0, gUnk_09EEE1B4, gUnk_091AB17C, 1, 0, gUnk_08F68384, gUnk_0812B4A4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE1D0, gUnk_09EEE1D4, gUnk_091AC1CC, 1, 0, gUnk_08F68384, gUnk_0812B494, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE1B8, gUnk_09EEE1BC, gUnk_091AB590, 1, 0, gUnk_08F68384, gUnk_0812B484, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE1C0, gUnk_09EEE1C4, gUnk_091AB9A4, 1, 0, gUnk_08F68384, gUnk_0812B474, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE1C8, gUnk_09EEE1CC, gUnk_091ABDB8, 1, 0, gUnk_08F68384, gUnk_0812B464, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE1D8, gUnk_09EEE1F8, gUnk_091AC67E, 1, 0, gUnk_08F68384, gUnk_0812B454, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE1FC, gUnk_09EEE21C, gUnk_091AEEB8, 1, 0, gUnk_08F68384, gUnk_0812B444, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE220, gUnk_09EEE240, gUnk_091B1788, 1, 0, gUnk_08F68384, gUnk_0812B434, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE244, gUnk_09EEE264, gUnk_091B46B0, 1, 0, gUnk_08F68384, gUnk_0812B424, gUnk_081296C0, 32, 0 },
    { gUnk_09EDE4F0, gUnk_09EDE50C, gUnk_0886ADEC, 3, 0, gUnk_08F68384, gUnk_081296CC, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE268, gUnk_09EEE278, gUnk_091B779C, 3, 0, gUnk_08F68384, gUnk_0812B414, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE284, gUnk_09EEE294, gUnk_091B8702, 3, 0, gUnk_08F68384, gUnk_0812B404, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE2A0, gUnk_09EEE2B0, gUnk_091B97E4, 2, 0, gUnk_08F68384, gUnk_0812B3F4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE2B8, gUnk_09EEE2C0, gUnk_091BAB86, 1, 0, gUnk_08F68384, gUnk_0812B3E4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE2C4, gUnk_09EEE2D4, gUnk_091BB3EA, 1, 0, gUnk_08F68384, gUnk_0812B3D4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE2D8, gUnk_09EEE2E4, gUnk_091BC2B0, 2, 0, gUnk_08F68384, gUnk_0812B3C4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE2EC, gUnk_09EEE2F4, gUnk_091BCEF2, 1, 0, gUnk_08F68384, gUnk_0812B3B4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE2F8, gUnk_09EEE308, gUnk_091BD754, 2, 0, gUnk_08F68384, gUnk_0812B3A4, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE310, gUnk_09EEE314, gUnk_091BEAEE, 1, 0, gUnk_08F68384, gUnk_0812B394, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE318, gUnk_09EEE324, gUnk_091BF026, 1, 0, gUnk_08F68384, gUnk_0812B384, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE328, gUnk_09EEE338, gUnk_091BFCDC, 2, 0, gUnk_08F68384, gUnk_0812B374, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE340, gUnk_09EEE360, gUnk_091C10B0, 3, 0, gUnk_08F68384, gUnk_0812B364, gUnk_081296C0, 32, 0 },
    { gUnk_09EEE00C, gUnk_09EEE010, gUnk_0919E99E, 1, 0, gUnk_09617C58, gUnk_0812B354, gUnk_08129680, 32, 0 },
    { gUnk_09EEE014, gUnk_09EEE018, gUnk_0919EC3A, 1, 0, gUnk_09617C58, gUnk_0812B344, gUnk_08129680, 32, 0 },
    { gUnk_09EEE03C, gUnk_09EEE0A8, gUnk_0919FDF8, 7, 0, gUnk_09617C58, gUnk_0812B334, gUnk_08129680, 32, 0 },
    { gUnk_09EEE0C4, gUnk_09EEE170, gUnk_091A4386, 16, 0, gUnk_09617C58, gUnk_0812B324, gUnk_08129680, 32, 0 },
    { gUnk_09EEE01C, gUnk_09EEE030, gUnk_0919EF32, 3, 0, gUnk_09617C58, gUnk_0812B314, gUnk_08129680, 32, 0 },
    { gUnk_09EEE410, gUnk_09EEE418, gUnk_091CBA82, 1, 0, gUnk_08F683A4, gUnk_0812B304, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE4B4, gUnk_09EEE4C0, gUnk_091CEAE2, 2, 0, gUnk_08F683A4, gUnk_0812B2F4, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE4C8, gUnk_09EEE4E8, gUnk_091CF5D4, 8, 0, gUnk_08F683A4, gUnk_0812B2E4, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE574, gUnk_09EEE588, gUnk_091D4234, 2, 0, gUnk_08F683A4, gUnk_0812B2D4, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE508, gUnk_09EEE514, gUnk_091D081A, 2, 0, gUnk_08F683A4, gUnk_0812B2C4, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE590, gUnk_09EEE5CC, gUnk_091D53D2, 4, 0, gUnk_08F683A4, gUnk_0812B2B4, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE568, gUnk_09EEE570, gUnk_091D3B2E, 1, 0, gUnk_08F683A4, gUnk_0812B2A4, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE41C, gUnk_09EEE438, gUnk_091CC21E, 7, 0, gUnk_08F683A4, gUnk_0812B294, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE4A4, gUnk_09EEE4B0, gUnk_091CE144, 1, 0, gUnk_08F683A4, gUnk_0812B284, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE554, gUnk_09EEE560, gUnk_091D3174, 2, 0, gUnk_08F683A4, gUnk_0812B274, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE51C, gUnk_09EEE52C, gUnk_091D1244, 1, 0, gUnk_08F683A4, gUnk_0812B264, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE530, gUnk_09EEE538, gUnk_091D1F34, 1, 0, gUnk_08F683A4, gUnk_0812B254, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE53C, gUnk_09EEE540, gUnk_091D256E, 1, 0, gUnk_08F683A4, gUnk_0812B244, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE5DC, gUnk_09EEE5F8, gUnk_091D8610, 2, 0, gUnk_08F683A4, gUnk_0812B234, gUnk_0812896C, 32, 0 },
    { gUnk_09EEB11C, gUnk_09EEB14C, gUnk_090A7F0A, 1, 0, gUnk_08F683A4, gUnk_0812B220, gUnk_0812896C, 32, 0 },
    { gUnk_09EEE36C, gUnk_09EEE3BC, gUnk_091C37E0, 10, 0, gUnk_09617C78, gUnk_0812B210, gUnk_0812B204, 32, 0 },
    { gUnk_09EEE3E4, gUnk_09EEE408, gUnk_091C9186, 2, 0, gUnk_09617C78, gUnk_0812B1F4, gUnk_0812B204, 32, 0 },
    { gUnk_09EEE600, gUnk_09EEE60C, gUnk_091D9F7A, 2, 0, gUnk_09617C98, gUnk_0812B1E4, gUnk_08128A04, 32, 0 },
    { gUnk_09EEE614, gUnk_09EEE61C, gUnk_091DB802, 2, 0, gUnk_09617C98, gUnk_0812B1D4, gUnk_08128A04, 32, 0 },
    { gUnk_09EEE624, gUnk_09EEE63C, gUnk_091DC354, 1, 0, gUnk_09617C98, gUnk_0812B1C4, gUnk_08128A04, 32, 0 },
    { gUnk_09EEE640, gUnk_09EEE658, gUnk_091DFA24, 1, 0, gUnk_09617C98, gUnk_081289E4, gUnk_08128A04, 32, 0 },
    { gUnk_09EEE65C, gUnk_09EEE668, gUnk_091E320E, 2, 0, gUnk_09617CB8, gUnk_0812B1B4, gUnk_081289B8, 32, 0 },
    { gUnk_09EEE670, gUnk_09EEE678, gUnk_091E48D6, 2, 0, gUnk_09617CB8, gUnk_0812B1A4, gUnk_081289B8, 32, 0 },
    { gUnk_09EEE680, gUnk_09EEE698, gUnk_091E56E2, 1, 0, gUnk_09617CB8, gUnk_0812B194, gUnk_081289B8, 32, 0 },
    { gUnk_09EEE69C, gUnk_09EEE6B4, gUnk_091E8B6E, 1, 0, gUnk_09617CB8, gUnk_08128998, gUnk_081289B8, 32, 0 },
    { gUnk_09EEE6B8, gUnk_09EEE6C0, gUnk_091EBFC8, 2, 0, gUnk_09617CD8, gUnk_0812B188, gUnk_0812B17C, 32, 0 },
    { gUnk_09EEE6C8, gUnk_09EEE6E8, gUnk_091EC9DC, 1, 0, gUnk_09617CD8, gUnk_0812B170, gUnk_0812B17C, 32, 0 },
    { gUnk_09EEE6EC, gUnk_09EEE708, gUnk_091EF636, 2, 0, gUnk_09617CD8, gUnk_0812B164, gUnk_0812B17C, 32, 0 },
    { gUnk_09EEE710, gUnk_09EEE714, gUnk_091F1D48, 2, 0, gUnk_09617CD8, gUnk_0812B158, gUnk_0812B17C, 32, 0 },
    { gUnk_09EEE71C, gUnk_09EEE73C, gUnk_091F2376, 1, 0, gUnk_09617CD8, gUnk_0812B14C, gUnk_0812B17C, 32, 0 },
    { gUnk_09EEE740, gUnk_09EEE744, gUnk_091F4A0A, 1, 0, gUnk_09617CD8, gUnk_0812B140, gUnk_0812B17C, 32, 0 },
    { gUnk_09EEE7AC, gUnk_09EEE7F0, gUnk_091F81C2, 3, 0, gUnk_09617CF8, gUnk_0812B130, gUnk_0812B124, 32, 0 },
    { gUnk_09EEE748, gUnk_09EEE798, gUnk_091F5270, 5, 0, gUnk_09617CF8, gUnk_0812B114, gUnk_0812B124, 32, 0 },
    { gUnk_09EEE7FC, gUnk_09EEE820, gUnk_091FA88E, 2, 0, gUnk_09617D18, gUnk_0812B104, gUnk_0812B0F8, 32, 0 },
    { gUnk_09EEE860, gUnk_09EEE884, gUnk_091FB8E6, 2, 0, gUnk_09617D18, gUnk_0812B0E8, gUnk_0812B0F8, 32, 0 },
    { gUnk_09EEE828, gUnk_09EEE858, gUnk_091FB25C, 2, 0, gUnk_09617D18, gUnk_0812B0D8, gUnk_0812B0F8, 32, 0 },
    { gUnk_09EEE88C, gUnk_09EEE89C, gUnk_091FC22A, 1, 0, gUnk_09617D18, gUnk_0812B0C8, gUnk_0812B0F8, 32, 0 },
    { gUnk_09EEE8A0, gUnk_09EEE8AC, gUnk_091FC786, 3, 0, gUnk_09617D38, gUnk_0812B0B8, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEE8DC, gUnk_09EEE93C, gUnk_091FD25E, 3, 0, gUnk_09617D38, gUnk_0812B09C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEE948, gUnk_09EEE990, gUnk_091FEC5E, 3, 0, gUnk_09617D38, gUnk_0812B08C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEEA5C, gUnk_09EEEA68, gUnk_09201FF2, 3, 0, gUnk_09617D38, gUnk_0812B07C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEE99C, gUnk_09EEE9FC, gUnk_091FFBD2, 3, 0, gUnk_09617D38, gUnk_0812B06C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEEA08, gUnk_09EEEA50, gUnk_09201116, 3, 0, gUnk_09617D38, gUnk_0812B05C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEE8B8, gUnk_09EEE8D0, gUnk_091FCB0A, 3, 0, gUnk_09617D38, gUnk_0812B04C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEEA74, gUnk_09EEEA8C, gUnk_09202336, 3, 0, gUnk_09617D38, gUnk_0812B03C, gUnk_0812B0AC, 32, 0 },
    { gUnk_09EEEA98, gUnk_09EEEAC8, gUnk_092028EC, 2, 0, gUnk_09617D58, gUnk_0812B02C, gUnk_0812B020, 32, 0 },
    { gUnk_09EEEAD0, gUnk_09EEEB00, gUnk_092035A0, 2, 0, gUnk_09617D58, gUnk_0812B010, gUnk_0812B020, 32, 0 },
    { gUnk_09EEEB08, gUnk_09EEEB0C, gUnk_092041BA, 1, 0, gUnk_09617D78, gUnk_0812B000, gUnk_0812AFF4, 32, 0 },
    { gUnk_09EEEB10, gUnk_09EEEB14, gUnk_092044D6, 1, 0, gUnk_09617D78, gUnk_0812AFE4, gUnk_0812AFF4, 32, 0 },
    { gUnk_09EEEB18, gUnk_09EEEB30, gUnk_09204886, 1, 0, gUnk_09617D78, gUnk_0812AFD4, gUnk_0812AFF4, 32, 0 },
    { gUnk_09EEEB34, gUnk_09EEEB4C, gUnk_09205B1A, 1, 0, gUnk_09617D78, gUnk_0812AFC4, gUnk_0812AFF4, 32, 0 },
    { gUnk_09EEEB50, gUnk_09EEEB60, gUnk_09206972, 1, 0, gUnk_09617D78, gUnk_0812AFB4, gUnk_0812AFF4, 32, 0 },
    { gUnk_09EEEB64, gUnk_09EEEB6C, gUnk_092073A2, 1, 0, gUnk_09617D78, gUnk_0812AFA4, gUnk_0812AFF4, 32, 0 },
    { gUnk_09EEEB70, gUnk_09EEEB74, gUnk_092078BE, 1, 0, gUnk_09617D98, gUnk_0812AF94, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEB78, gUnk_09EEEB94, gUnk_09207DD8, 1, 0, gUnk_09617D98, gUnk_0812AF84, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEB98, gUnk_09EEEBB0, gUnk_09209E62, 1, 0, gUnk_09617D98, gUnk_0812AF74, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEBB4, gUnk_09EEEBC0, gUnk_0920BBAC, 1, 0, gUnk_09617D98, gUnk_0812AF64, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEBC4, gUnk_09EEEBD0, gUnk_0920C680, 1, 0, gUnk_09617D98, gUnk_0812AF54, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEBD4, gUnk_09EEEBDC, gUnk_0920D7AE, 1, 0, gUnk_09617D98, gUnk_0812AF44, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEBE0, gUnk_09EEEBF0, gUnk_0920E142, 1, 0, gUnk_09617D98, gUnk_0812AF34, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEBF4, gUnk_09EEEC04, gUnk_0920FBBA, 1, 0, gUnk_09617D98, gUnk_0812AF24, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC08, gUnk_09EEEC14, gUnk_092111B4, 1, 0, gUnk_09617D98, gUnk_0812AF14, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC18, gUnk_09EEEC2C, gUnk_092128FC, 3, 0, gUnk_09617D98, gUnk_0812AF04, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC38, gUnk_09EEEC3C, gUnk_09213B76, 1, 0, gUnk_09617D98, gUnk_0812AEF4, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC40, gUnk_09EEEC5C, gUnk_09214096, 1, 0, gUnk_09617D98, gUnk_0812AEE4, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC60, gUnk_09EEEC78, gUnk_0921612E, 1, 0, gUnk_09617D98, gUnk_0812AED4, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC7C, gUnk_09EEEC88, gUnk_09217F50, 1, 0, gUnk_09617D98, gUnk_0812AEC4, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC8C, gUnk_09EEEC98, gUnk_09218C0A, 1, 0, gUnk_09617D98, gUnk_0812AEB4, gUnk_081295A8, 32, 0 },
    { gUnk_09EEEC9C, gUnk_09EEECA4, gUnk_09219EBA, 1, 0, gUnk_09617D98, gUnk_0812AEA4, gUnk_081295A8, 32, 0 },
    { gUnk_09EEECA8, gUnk_09EEECAC, gUnk_0921A7D6, 1, 0, gUnk_09617DB8, gUnk_0812AE94, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEECB0, gUnk_09EEECB4, gUnk_0921AC32, 1, 0, gUnk_09617DB8, gUnk_0812AE78, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEECB8, gUnk_09EEECD8, gUnk_0921B12C, 1, 0, gUnk_09617DB8, gUnk_0812AE68, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEECDC, gUnk_09EEECFC, gUnk_0921D3AA, 1, 0, gUnk_09617DB8, gUnk_0812AE58, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEED28, gUnk_09EEED48, gUnk_092211F6, 1, 0, gUnk_09617DB8, gUnk_0812AE44, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEED4C, gUnk_09EEED6C, gUnk_0922346A, 1, 0, gUnk_09617DB8, gUnk_0812AE30, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEED00, gUnk_09EEED18, gUnk_0921F896, 4, 0, gUnk_09617DB8, gUnk_0812AE20, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEED70, gUnk_09EEED90, gUnk_092258B4, 1, 0, gUnk_09617DB8, gUnk_0812AE10, gUnk_0812AE88, 32, 0 },
    { gUnk_09EEED94, gUnk_09EEEDC8, gUnk_09228926, 10, 0, gUnk_09617DD8, gUnk_0812AE00, gUnk_0812958C, 32, 0 },
    { gUnk_09EEEDF0, gUnk_09EEEE00, gUnk_0922BA7E, 5, 0, gUnk_09617DD8, gUnk_0812ADF0, gUnk_0812958C, 32, 0 },
    { gUnk_09EEEE14, gUnk_09EEEE1C, gUnk_0922C4B4, 2, 0, gUnk_09617DF8, gUnk_0812ADE0, gUnk_0812ADD4, 32, 0 },
    { gUnk_09EEEE4C, gUnk_09EEEE54, gUnk_0922E1FC, 2, 0, gUnk_09617DF8, gUnk_0812ADC4, gUnk_0812ADD4, 32, 0 },
    { gUnk_09EEEE70, gUnk_09EEEE90, gUnk_0922F578, 2, 0, gUnk_09617DF8, gUnk_0812ADB0, gUnk_0812ADD4, 32, 0 },
    { gUnk_09EEEE98, gUnk_09EEEEB8, gUnk_09231710, 2, 0, gUnk_09617DF8, gUnk_0812AD9C, gUnk_0812ADD4, 32, 0 },
    { gUnk_09EEEE24, gUnk_09EEEE30, gUnk_0922CD72, 2, 0, gUnk_09617DF8, gUnk_0812AD8C, gUnk_0812ADD4, 32, 0 },
    { gUnk_09EEEF10, gUnk_09EEEF14, gUnk_0923EFB8, 1, 0, gUnk_09617E18, gUnk_0812AD7C, gUnk_08129550, 32, 0 },
    { gUnk_09EEEEEC, gUnk_09EEEF0C, gUnk_0923A22A, 1, 0, gUnk_09617E18, gUnk_0812AD68, gUnk_08129550, 32, 0 },
    { gUnk_09EEEEE4, gUnk_09EEEEE8, gUnk_0923967A, 1, 0, gUnk_09617E18, gUnk_0812AD58, gUnk_08129550, 32, 0 },
    { gUnk_09EEEEC0, gUnk_09EEEEE0, gUnk_09233A66, 1, 0, gUnk_09617E18, gUnk_0812AD44, gUnk_08129550, 32, 0 },
    { gUnk_09EEEF50, gUnk_09EEEF5C, gUnk_09246F52, 1, 0, gUnk_09617E18, gUnk_0812AD30, gUnk_08129550, 32, 0 },
    { gUnk_09EEEF2C, gUnk_09EEEF4C, gUnk_09242508, 1, 0, gUnk_09617E18, gUnk_0812AD20, gUnk_08129550, 32, 0 },
    { gUnk_09EEEF18, gUnk_09EEEF28, gUnk_0923FB84, 1, 0, gUnk_09617E18, gUnk_0812AD0C, gUnk_08129550, 32, 0 },
    { gUnk_09EEEF60, gUnk_09EEEF6C, gUnk_09248EAA, 1, 0, gUnk_09617E18, gUnk_0812ACF8, gUnk_08129550, 32, 0 },
    { gUnk_09EEEF70, gUnk_09EEEF7C, gUnk_0924B266, 1, 0, gUnk_09617E18, gUnk_0812ACE4, gUnk_08129550, 32, 0 },
    { gUnk_09EEEF80, gUnk_09EEEFA4, gUnk_0924D1F8, 4, 0, gUnk_09617E38, gUnk_0812ACD4, gUnk_0812ACC4, 32, 0 },
    { gUnk_09EEEFB4, gUnk_09EEEFB8, gUnk_0924EA0C, 1, 0, gUnk_09617E58, gUnk_0812ACB0, gUnk_0812ACA0, 32, 0 },
    { gUnk_09EEEFBC, gUnk_09EEEFC0, gUnk_0924EE20, 1, 0, gUnk_09617E58, gUnk_0812AC8C, gUnk_0812ACA0, 32, 0 },
    { gUnk_09EEEFC4, gUnk_09EEEFE0, gUnk_0924F294, 1, 0, gUnk_09617E58, gUnk_0812AC7C, gUnk_0812ACA0, 32, 0 },
    { gUnk_09EEEFE4, gUnk_09EEEFE8, gUnk_09250EF4, 1, 0, gUnk_08F6DC24, gUnk_0812AC6C, gUnk_08129664, 32, 0 },
    { gUnk_09EEEFEC, gUnk_09EEF00C, gUnk_0925159A, 1, 0, gUnk_08F6DC24, gUnk_0812AC5C, gUnk_08129664, 32, 0 },
    { gUnk_09EEF010, gUnk_09EEF024, gUnk_09255CD4, 2, 0, gUnk_08F6DC24, gUnk_0812AC4C, gUnk_08129664, 32, 0 },
    { gUnk_09EEF02C, gUnk_09EEF030, gUnk_09257894, 1, 0, gUnk_08F6DC24, gUnk_0812AC3C, gUnk_08129664, 32, 0 },
    { gUnk_09EEF034, gUnk_09EEF054, gUnk_09257ECC, 1, 0, gUnk_08F6DC24, gUnk_0812AC2C, gUnk_08129664, 32, 0 },
    { gUnk_09EEF058, gUnk_09EEF064, gUnk_0925C2B2, 1, 0, gUnk_08F6DC24, gUnk_0812AC1C, gUnk_08129664, 32, 0 },
    { gUnk_09EEF068, gUnk_09EEF080, gUnk_0925D4C0, 1, 0, gUnk_08F6DC24, gUnk_0812AC0C, gUnk_08129664, 32, 0 },
    { gUnk_09EEF084, gUnk_09EEF09C, gUnk_0925F12C, 1, 0, gUnk_08F6DC24, gUnk_0812ABFC, gUnk_08129664, 32, 0 },
    { gUnk_09EEF0A0, gUnk_09EEF0A4, gUnk_0926221E, 1, 0, gUnk_09617E78, gUnk_0812ABEC, gUnk_0812ABE0, 32, 0 },
    { gUnk_09EEF0A8, gUnk_09EEF0AC, gUnk_092630E4, 1, 0, gUnk_09617E78, gUnk_0812ABD0, gUnk_0812ABE0, 32, 0 },
    { gUnk_09EEF0B0, gUnk_09EEF0C0, gUnk_0926400E, 2, 0, gUnk_09617E78, gUnk_0812ABBC, gUnk_0812ABE0, 32, 0 },
    { gUnk_09EEF0C8, gUnk_09EEF0E4, gUnk_09266250, 1, 0, gUnk_09617E78, gUnk_0812ABA8, gUnk_0812ABE0, 32, 0 },
    { gUnk_09EEF108, gUnk_09EEF120, gUnk_0926F480, 2, 0, gUnk_09617E78, gUnk_0812AB94, gUnk_0812ABE0, 32, 0 },
    { gUnk_09EEF128, gUnk_09EEF138, gUnk_092736C2, 1, 0, gUnk_09617E78, gUnk_0812AB80, gUnk_0812ABE0, 32, 0 },
    { gUnk_09EEF13C, gUnk_09EEF140, gUnk_092764DE, 1, 0, gUnk_09617E98, gUnk_0812AB70, gUnk_0812AB64, 32, 0 },
    { gUnk_09EEF178, gUnk_09EEF194, gUnk_0927C41C, 1, 0, gUnk_09617E98, gUnk_0812AB54, gUnk_0812AB64, 32, 0 },
    { gUnk_09EEF198, gUnk_09EEF1B8, gUnk_0928043A, 2, 0, gUnk_09617E98, gUnk_0812AB44, gUnk_0812AB64, 32, 0 },
    { gUnk_09EEF1C0, gUnk_09EEF1D8, gUnk_0928638C, 2, 0, gUnk_09617E98, gUnk_0812AB34, gUnk_0812AB64, 32, 0 },
    { gUnk_09EEF144, gUnk_09EEF148, gUnk_092770FA, 1, 0, gUnk_09617E98, gUnk_0812AB24, gUnk_0812AB64, 32, 0 },
    { gUnk_09EEF14C, gUnk_09EEF168, gUnk_09277DF8, 4, 0, gUnk_09617E98, gUnk_0812AB14, gUnk_0812AB64, 32, 0 },
    { gUnk_09EEF1E0, gUnk_09EEF1EC, gUnk_0928A614, 2, 0, gUnk_09617EB8, gUnk_0812AB04, gUnk_0812AAF8, 32, 0 },
    { gUnk_09EEF240, gUnk_09EEF244, gUnk_0928FF34, 1, 0, gUnk_09617EB8, gUnk_0812AAE8, gUnk_0812AAF8, 32, 0 },
    { gUnk_09EEF1F4, gUnk_09EEF214, gUnk_0928B386, 1, 0, gUnk_09617EB8, gUnk_0812AAD8, gUnk_0812AAF8, 32, 0 },
    { gUnk_09EEF248, gUnk_09EEF268, gUnk_0929046A, 1, 0, gUnk_09617EB8, gUnk_0812AAC8, gUnk_0812AAF8, 32, 0 },
    { gUnk_09EEF234, gUnk_09EEF23C, gUnk_0928F512, 1, 0, gUnk_09617EB8, gUnk_0812AAB8, gUnk_0812AAF8, 32, 0 },
    { gUnk_09EEF218, gUnk_09EEF230, gUnk_0928D658, 1, 0, gUnk_09617EB8, gUnk_0812AAA8, gUnk_0812AAF8, 32, 0 },
    { gUnk_09EEF26C, gUnk_09EEF2A8, gUnk_092929C0, 4, 0, gUnk_09617ED8, gUnk_0812AA98, gUnk_0812AA8C, 32, 0 },
    { gUnk_09EEF2B8, gUnk_09EEF2BC, gUnk_092949BA, 1, 0, gUnk_09617ED8, gUnk_0812AA7C, gUnk_0812AA8C, 32, 0 },
    { gUnk_09EEF2C0, gUnk_09EEF2E0, gUnk_09294CB4, 1, 0, gUnk_09617ED8, gUnk_0812AA68, gUnk_0812AA8C, 32, 0 },
    { gUnk_09EEF2E4, gUnk_09EEF2E8, gUnk_0929605A, 1, 0, gUnk_09617EF8, gUnk_0812AA54, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF2EC, gUnk_09EEF2F0, gUnk_09296642, 1, 0, gUnk_09617EF8, gUnk_0812AA30, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF2F4, gUnk_09EEF314, gUnk_09296CB0, 1, 0, gUnk_09617EF8, gUnk_0812AA18, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF318, gUnk_09EEF338, gUnk_0929985E, 1, 0, gUnk_09617EF8, gUnk_0812AA04, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF33C, gUnk_09EEF35C, gUnk_0929CB78, 1, 0, gUnk_09617EF8, gUnk_0812A9F0, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF360, gUnk_09EEF36C, gUnk_0929F8C4, 1, 0, gUnk_09617EF8, gUnk_0812A9D8, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF370, gUnk_09EEF380, gUnk_092A0864, 2, 0, gUnk_09617EF8, gUnk_0812A9C4, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF388, gUnk_09EEF394, gUnk_092A1C88, 1, 0, gUnk_09617EF8, gUnk_0812A9AC, gUnk_0812AA44, 32, 0 },
    { gUnk_09EEF398, gUnk_09EEF3B0, gUnk_092A2E72, 1, 0, gUnk_09617F18, gUnk_0812A99C, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF3B4, gUnk_09EEF3CC, gUnk_092A403A, 1, 0, gUnk_09617F18, gUnk_0812A98C, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF3D0, gUnk_09EEF3F0, gUnk_092A5250, 1, 0, gUnk_09617F18, gUnk_081297CC, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF3F4, gUnk_09EEF414, gUnk_092A8E84, 1, 0, gUnk_09617F18, gUnk_0812A978, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF418, gUnk_09EEF43C, gUnk_092ACCF8, 2, 0, gUnk_09617F18, gUnk_0812A968, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF444, gUnk_09EEF474, gUnk_092B03A2, 3, 0, gUnk_09617F18, gUnk_0812977C, gUnk_0812980C, 32, 0 },
    { gUnk_09EEF444, gUnk_09EEF474, gUnk_092B03A2, 3, 0, gUnk_09617F38, gUnk_0812977C, gUnk_0812976C, 32, 0 },
    { gUnk_09EEF4E4, gUnk_09EEF4E8, gUnk_092BA1DC, 1, 0, gUnk_09617F98, gUnk_0812A95C, gUnk_0812A950, 32, 0 },
    { gUnk_09EEF4EC, gUnk_09EEF4F0, gUnk_092BA6B6, 1, 0, gUnk_09617FB8, gUnk_0812A940, gUnk_0812A934, 32, 0 },
    { gUnk_09EEF4F4, gUnk_09EEF4F8, gUnk_092BA9D2, 1, 0, gUnk_09617FB8, gUnk_0812A924, gUnk_0812A934, 32, 0 },
    { gUnk_09EEF4FC, gUnk_09EEF508, gUnk_092BAD16, 1, 0, gUnk_09617FB8, gUnk_0812A914, gUnk_0812A934, 32, 0 },
    { gUnk_09EEF50C, gUnk_09EEF518, gUnk_092BB65A, 1, 0, gUnk_09617FB8, gUnk_0812A904, gUnk_0812A934, 32, 0 },
    { gUnk_09EEF51C, gUnk_09EEF520, gUnk_092BBF82, 1, 0, gUnk_09617FD8, gUnk_0812A8F4, gUnk_0812A8E8, 32, 0 },
    { gUnk_09EEF524, gUnk_09EEF544, gUnk_092BCD18, 1, 0, gUnk_09617FD8, gUnk_0812A8D8, gUnk_0812A8E8, 32, 0 },
    { gUnk_09EEF548, gUnk_09EEF568, gUnk_092C2DB8, 1, 0, gUnk_09617FD8, gUnk_0812A8C8, gUnk_0812A8E8, 32, 0 },
    { gUnk_09EEF56C, gUnk_09EEF578, gUnk_092C7D12, 1, 0, gUnk_09617FD8, gUnk_0812A8B8, gUnk_0812A8E8, 32, 0 },
    { gUnk_09EEF57C, gUnk_09EEF58C, gUnk_092CA3C4, 2, 0, gUnk_09617FD8, gUnk_0812A8A8, gUnk_0812A8E8, 32, 0 },
    { gUnk_09EEF594, gUnk_09EEF598, gUnk_092CC876, 1, 0, gUnk_09617FD8, gUnk_0812A898, gUnk_0812A8E8, 32, 0 },
    { gUnk_09EEF59C, gUnk_09EEF5A0, gUnk_092CD252, 1, 0, gUnk_09617FF8, gUnk_0812A888, gUnk_081295E0, 32, 0 },
    { gUnk_09EEF5A4, gUnk_09EEF5A8, gUnk_092CD4C6, 1, 0, gUnk_09618018, gUnk_0812A878, gUnk_081295F8, 32, 0 },
    { gUnk_09EEF5AC, gUnk_09EEF5B4, gUnk_092CDC70, 2, 0, gUnk_09618038, gUnk_0812A868, gUnk_081295C4, 32, 0 },
    { gUnk_09EEF5BC, gUnk_09EEF5C8, gUnk_092CDEE4, 2, 0, gUnk_09618058, gUnk_0812A858, gUnk_0812A84C, 32, 0 },
    { gUnk_09EEF5D0, gUnk_09EEF5D4, gUnk_092CE4B8, 1, 0, gUnk_09618078, gUnk_0812A840, gUnk_0812A834, 32, 0 },
    { gUnk_09EEF5FC, gUnk_09EEF600, gUnk_092D0944, 1, 0, gUnk_09618078, gUnk_0812A828, gUnk_0812A834, 32, 0 },
    { gUnk_09EEF5D8, gUnk_09EEF5F8, gUnk_092CE92E, 1, 0, gUnk_09618078, gUnk_0812A81C, gUnk_0812A834, 32, 0 },
    { gUnk_09EEF604, gUnk_09EEF624, gUnk_092D0DC0, 1, 0, gUnk_09618078, gUnk_0812A810, gUnk_0812A834, 32, 0 },
    { gUnk_09EEF628, gUnk_09EEF65C, gUnk_092D2EB6, 4, 0, gUnk_09618098, gUnk_0812A800, gUnk_0812A7F4, 32, 0 },
    { gUnk_09EEF66C, gUnk_09EEF680, gUnk_092D452A, 2, 0, gUnk_09618098, gUnk_0812A7E4, gUnk_0812A7F4, 32, 0 },
    { gUnk_09EEF688, gUnk_09EEF68C, gUnk_092D4B66, 1, 0, gUnk_096180B8, gUnk_0812A7D0, gUnk_0812A7C0, 32, 0 },
    { gUnk_09EEF690, gUnk_09EEF694, gUnk_092D4CC2, 1, 0, gUnk_096180B8, gUnk_0812A7AC, gUnk_0812A7C0, 32, 0 },
    { gUnk_09EEF698, gUnk_09EEF6B8, gUnk_092D4EEA, 1, 0, gUnk_096180B8, gUnk_0812A794, gUnk_0812A7C0, 32, 0 },
    { gUnk_09EEF6BC, gUnk_09EEF6DC, gUnk_092D592E, 1, 0, gUnk_096180B8, gUnk_0812A77C, gUnk_0812A7C0, 32, 0 },
    { gUnk_09EEF748, gUnk_09EEF754, gUnk_092D88E8, 4, 0, gUnk_096180F8, gUnk_0812A76C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF7AC, gUnk_09EEF7DC, gUnk_092DDC64, 4, 0, gUnk_096180F8, gUnk_0812A75C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF7EC, gUnk_09EEF804, gUnk_092E17A8, 1, 0, gUnk_096180F8, gUnk_0812A74C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF808, gUnk_09EEF818, gUnk_092E367E, 1, 0, gUnk_096180F8, gUnk_0812A73C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF81C, gUnk_09EEF840, gUnk_092E4EAE, 4, 0, gUnk_096180F8, gUnk_0812A72C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF850, gUnk_09EEF860, gUnk_092E80F2, 2, 0, gUnk_096180F8, gUnk_0812A71C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF868, gUnk_09EEF86C, gUnk_092E962C, 1, 0, gUnk_096180F8, gUnk_0812A70C, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF870, gUnk_09EEF880, gUnk_092E9AA8, 1, 0, gUnk_096180F8, gUnk_0812A6FC, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF764, gUnk_09EEF768, gUnk_092D9802, 1, 0, gUnk_096180F8, gUnk_0812A6EC, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF76C, gUnk_09EEF784, gUnk_092D9D82, 1, 0, gUnk_096180F8, gUnk_0812A6DC, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF788, gUnk_09EEF798, gUnk_092DBBDA, 1, 0, gUnk_096180F8, gUnk_0812A6CC, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF79C, gUnk_09EEF7A4, gUnk_092DD01A, 2, 0, gUnk_096180F8, gUnk_0812A6BC, gUnk_08129B80, 32, 0 },
    { gUnk_09EEF884, gUnk_09EEF890, gUnk_092EAEB4, 1, 0, gUnk_096180F8, gUnk_0812A6A8, gUnk_08129B80, 32, 0 },
    { gUnk_09EEFBA4, gUnk_09EEFBA8, gUnk_0930EAAA, 1, 0, gUnk_09618138, gUnk_0812A698, gUnk_0812A68C, 32, 0 },
    { gUnk_09EEFBAC, gUnk_09EEFBB0, gUnk_0930EEF0, 2, 0, gUnk_09618138, gUnk_0812A67C, gUnk_0812A68C, 32, 0 },
    { gUnk_09EEFBD8, gUnk_09EEFBF8, gUnk_09310582, 1, 0, gUnk_09618138, gUnk_0812A66C, gUnk_0812A68C, 32, 0 },
    { gUnk_09EEFBB8, gUnk_09EEFBCC, gUnk_0930F3BC, 3, 0, gUnk_09618138, gUnk_0812A65C, gUnk_0812A68C, 32, 0 },
    { gUnk_09EEFBFC, gUnk_09EEFC00, gUnk_09312D98, 1, 0, gUnk_09618138, gUnk_0812A650, gUnk_0812A68C, 32, 0 },
    { gUnk_09EEFC04, gUnk_09EEFC08, gUnk_09312DDE, 1, 0, gUnk_09618158, gUnk_0812A640, gUnk_081299A8, 32, 0 },
    { gUnk_09EEFC0C, gUnk_09EEFC24, gUnk_093136AC, 1, 0, gUnk_09618158, gUnk_0812A630, gUnk_081299A8, 32, 0 },
    { gUnk_09EEFC28, gUnk_09EEFC34, gUnk_09315E1E, 1, 0, gUnk_09618158, gUnk_0812A620, gUnk_081299A8, 32, 0 },
    { gUnk_09EEFC38, gUnk_09EEFC60, gUnk_09317A62, 5, 0, gUnk_09618158, gUnk_0812A610, gUnk_081299A8, 32, 0 },
    { gUnk_09EEFC74, gUnk_09EEFC78, gUnk_0931D970, 1, 0, gUnk_09618158, gUnk_0812A600, gUnk_081299A8, 32, 0 },
    { gUnk_09EEFC7C, gUnk_09EEFC88, gUnk_0931E174, 1, 0, gUnk_09618158, gUnk_0812A5F0, gUnk_081299A8, 32, 0 },
    { gUnk_09EEFEC0, gUnk_09EEFEC4, gUnk_09322F50, 1, 0, gUnk_096181B8, gUnk_0812A5E0, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFEC8, gUnk_09EEFECC, gUnk_09323364, 1, 0, gUnk_096181B8, gUnk_0812A5C4, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFED0, gUnk_09EEFEF0, gUnk_09323816, 1, 0, gUnk_096181B8, gUnk_0812A5B4, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFEF4, gUnk_09EEFF14, gUnk_09326050, 1, 0, gUnk_096181B8, gUnk_0812A5A4, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFF18, gUnk_09EEFF38, gUnk_09328920, 1, 0, gUnk_096181B8, gUnk_0812A594, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFF3C, gUnk_09EEFF48, gUnk_0932B7B6, 3, 0, gUnk_096181B8, gUnk_0812A584, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFF54, gUnk_09EEFF5C, gUnk_0932C85A, 1, 0, gUnk_096181B8, gUnk_0812A574, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFF60, gUnk_09EEFF68, gUnk_0932D07E, 1, 0, gUnk_096181B8, gUnk_0812A564, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EEFF6C, gUnk_09EEFF7C, gUnk_0932D8E0, 2, 0, gUnk_096181B8, gUnk_0812A554, gUnk_0812A5D4, 32, 0 },
    { gUnk_09EF00AC, gUnk_09EF00B0, gUnk_093380EC, 1, 0, gUnk_096181F8, gUnk_0812A544, gUnk_0812A538, 32, 0 },
    { gUnk_09EF00B4, gUnk_09EF00B8, gUnk_093385CC, 1, 0, gUnk_096181F8, gUnk_0812A528, gUnk_0812A538, 32, 0 },
    { gUnk_09EF00BC, gUnk_09EF00D8, gUnk_09338B2A, 1, 0, gUnk_096181F8, gUnk_0812A518, gUnk_0812A538, 32, 0 },
    { gUnk_09EF00DC, gUnk_09EF00F4, gUnk_0933AD50, 1, 0, gUnk_096181F8, gUnk_0812A508, gUnk_0812A538, 32, 0 },
    { gUnk_09EF00F8, gUnk_09EF00FC, gUnk_0933C8BC, 1, 0, gUnk_09618218, gUnk_0812A4F4, gUnk_0812A4E8, 32, 0 },
    { gUnk_09EF0100, gUnk_09EF0104, gUnk_0933CB22, 1, 0, gUnk_09618218, gUnk_0812A4D4, gUnk_0812A4E8, 32, 0 },
    { gUnk_09EF0108, gUnk_09EF0128, gUnk_0933CDBA, 1, 0, gUnk_09618218, gUnk_0812A4C0, gUnk_0812A4E8, 32, 0 },
    { gUnk_09EF012C, gUnk_09EF014C, gUnk_0933E1E4, 1, 0, gUnk_09618218, gUnk_0812A4AC, gUnk_0812A4E8, 32, 0 },
    { gUnk_09EF0150, gUnk_09EF0170, gUnk_0933F4C2, 1, 0, gUnk_09618218, gUnk_0812A498, gUnk_0812A4E8, 32, 0 },
    { gUnk_09EEFC8C, gUnk_09EEFC90, gUnk_0931F91A, 1, 0, gUnk_09618178, gUnk_0812A484, gUnk_0812A478, 32, 0 },
    { gUnk_09EEFC94, gUnk_09EEFC98, gUnk_0931FC36, 1, 0, gUnk_09618178, gUnk_0812A468, gUnk_0812A478, 32, 0 },
    { gUnk_09EEFC9C, gUnk_09EEFCA0, gUnk_0931FE92, 1, 0, gUnk_09618178, gUnk_0812A458, gUnk_0812A478, 32, 0 },
    { gUnk_09EEFCA4, gUnk_09EEFCA8, gUnk_093202B4, 1, 0, gUnk_09618178, gUnk_0812A448, gUnk_0812A478, 32, 0 },
    { gUnk_09EF0174, gUnk_09EF0178, gUnk_0934090A, 1, 0, gUnk_09618238, gUnk_0812A438, gUnk_0812A42C, 32, 0 },
    { gUnk_09EF017C, gUnk_09EF0180, gUnk_09340FD2, 1, 0, gUnk_09618238, gUnk_0812A41C, gUnk_0812A42C, 32, 0 },
    { gUnk_09EF0184, gUnk_09EF01A4, gUnk_093419F8, 1, 0, gUnk_09618238, gUnk_0812A408, gUnk_0812A42C, 32, 0 },
    { gUnk_09EF01A8, gUnk_09EF01C8, gUnk_09344D76, 1, 0, gUnk_09618238, gUnk_0812A3F4, gUnk_0812A42C, 32, 0 },
    { gUnk_09EF01CC, gUnk_09EF01E8, gUnk_0934888C, 2, 0, gUnk_09618238, gUnk_0812A3E4, gUnk_0812A42C, 32, 0 },
    { gUnk_09EF01F0, gUnk_09EF01F8, gUnk_0934B7EC, 2, 0, gUnk_09618258, gUnk_0812A3D4, gUnk_0812A3C8, 32, 0 },
    { gUnk_09EF0200, gUnk_09EF0204, gUnk_0934BF86, 1, 0, gUnk_09618258, gUnk_0812A3B8, gUnk_0812A3C8, 32, 0 },
    { gUnk_09EF0208, gUnk_09EF022C, gUnk_0934C4C2, 1, 0, gUnk_09618258, gUnk_0812A3A4, gUnk_0812A3C8, 32, 0 },
    { gUnk_09EF0230, gUnk_09EF0254, gUnk_0934EF04, 1, 0, gUnk_09618258, gUnk_0812A390, gUnk_0812A3C8, 32, 0 },
    { gUnk_09EF0258, gUnk_09EF0278, gUnk_09351D0C, 4, 0, gUnk_09618258, gUnk_0812A380, gUnk_0812A3C8, 32, 0 },
    { gUnk_09EF0288, gUnk_09EF02A4, gUnk_09354030, 1, 0, gUnk_09618258, gUnk_0812A370, gUnk_0812A3C8, 32, 0 },
    { gUnk_09EEFF84, gUnk_09EEFFCC, gUnk_0932EDD8, 4, 0, gUnk_096181D8, gUnk_0812A360, gUnk_0812A354, 32, 0 },
    { gUnk_09EEFFDC, gUnk_09EF0024, gUnk_093319DA, 4, 0, gUnk_096181D8, gUnk_0812A344, gUnk_0812A354, 32, 0 },
    { gUnk_09EF0034, gUnk_09EF0054, gUnk_09334A18, 4, 0, gUnk_096181D8, gUnk_0812A334, gUnk_0812A354, 32, 0 },
    { gUnk_09EF0064, gUnk_09EF0078, gUnk_09335F02, 1, 0, gUnk_096181D8, gUnk_0812A324, gUnk_0812A354, 32, 0 },
    { gUnk_09EF007C, gUnk_09EF008C, gUnk_09336BEE, 3, 0, gUnk_096181D8, gUnk_0812A314, gUnk_0812A354, 32, 0 },
    { gUnk_09EF0098, gUnk_09EF00A8, gUnk_093376CA, 1, 0, gUnk_096181D8, gUnk_0812A304, gUnk_0812A354, 32, 0 },
    { gUnk_09EF02A8, gUnk_09EF02AC, gUnk_0935644A, 1, 0, gUnk_09618278, gUnk_0812A2F4, gUnk_0812A2E8, 32, 0 },
    { gUnk_09EF02B0, gUnk_09EF02D0, gUnk_093569F0, 1, 0, gUnk_09618278, gUnk_0812A2D8, gUnk_0812A2E8, 32, 0 },
    { gUnk_09EF02D4, gUnk_09EF02D8, gUnk_09357F42, 1, 0, gUnk_09618298, gUnk_0812A2C8, gUnk_08129570, 32, 0 },
    { gUnk_09EF02DC, gUnk_09EF02E0, gUnk_09358A2A, 1, 0, gUnk_09618298, gUnk_0812A2B8, gUnk_08129570, 32, 0 },
    { gUnk_09EF02E4, gUnk_09EF02FC, gUnk_0935944E, 1, 0, gUnk_09618298, gUnk_0812A2A8, gUnk_08129570, 32, 0 },
    { gUnk_09EF0300, gUnk_09EF0320, gUnk_0935C8DA, 1, 0, gUnk_09618298, gUnk_0812A298, gUnk_08129570, 32, 0 },
    { gUnk_09EF0324, gUnk_09EF0348, gUnk_093612D6, 1, 0, gUnk_09618298, gUnk_0812A288, gUnk_08129570, 32, 0 },
    { gUnk_09EF034C, gUnk_09EF0364, gUnk_09365464, 1, 0, gUnk_09618298, gUnk_0812A278, gUnk_08129570, 32, 0 },
    { gUnk_09EF0368, gUnk_09EF036C, gUnk_09369504, 1, 0, gUnk_09618298, gUnk_0812A268, gUnk_08129570, 32, 0 },
    { gUnk_09EF0370, gUnk_09EF0380, gUnk_09369F9A, 1, 0, gUnk_09618298, gUnk_0812A258, gUnk_08129570, 32, 0 },
    { gUnk_09EF0384, gUnk_09EF0390, gUnk_0936C2AA, 1, 0, gUnk_09618298, gUnk_0812A248, gUnk_08129570, 32, 0 },
    { gUnk_09EF0394, gUnk_09EF03A4, gUnk_0936E046, 1, 0, gUnk_09618298, gUnk_0812A238, gUnk_08129570, 32, 0 },
    { gUnk_09EF03A8, gUnk_09EF03AC, gUnk_09370722, 1, 0, gUnk_09618298, gUnk_0812A224, gUnk_08129570, 32, 0 },
    { gUnk_09EF03B0, gUnk_09EF03B4, gUnk_09371150, 1, 0, gUnk_096182B8, gUnk_0812A214, gUnk_0812A208, 32, 0 },
    { gUnk_09EF03DC, gUnk_09EF03E0, gUnk_09372946, 1, 0, gUnk_096182B8, gUnk_0812A1F8, gUnk_0812A208, 32, 0 },
    { gUnk_09EF03B8, gUnk_09EF03D8, gUnk_09371474, 1, 0, gUnk_096182B8, gUnk_0812A1E8, gUnk_0812A208, 32, 0 },
    { gUnk_09EF03E4, gUnk_09EF03EC, gUnk_09372BE0, 2, 0, gUnk_096182D8, gUnk_0812A1D8, gUnk_0812A1CC, 32, 0 },
    { gUnk_09EF03F4, gUnk_09EF03F8, gUnk_093730A6, 1, 0, gUnk_096182D8, gUnk_0812A1BC, gUnk_0812A1CC, 32, 0 },
    { gUnk_09EF03FC, gUnk_09EF0400, gUnk_093732B4, 1, 0, gUnk_096182F8, gUnk_0812A1AC, gUnk_0812A1A0, 32, 0 },
    { gUnk_09EF0404, gUnk_09EF0408, gUnk_0937353A, 1, 0, gUnk_096182F8, gUnk_0812A190, gUnk_0812A1A0, 32, 0 },
    { gUnk_09EF040C, gUnk_09EF042C, gUnk_093738A6, 1, 0, gUnk_096182F8, gUnk_0812A180, gUnk_0812A1A0, 32, 0 },
    { gUnk_09EF0430, gUnk_09EF0450, gUnk_09375012, 1, 0, gUnk_096182F8, gUnk_0812A170, gUnk_0812A1A0, 32, 0 },
    { gUnk_09EF04D4, gUnk_09EF04D8, gUnk_0937E90A, 1, 0, gUnk_09618338, gUnk_0812A160, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF04DC, gUnk_09EF04F8, gUnk_0937ED58, 1, 0, gUnk_09618338, gUnk_0812A148, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF04FC, gUnk_09EF0510, gUnk_0938044A, 1, 0, gUnk_09618338, gUnk_0812A134, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0514, gUnk_09EF052C, gUnk_093815C2, 3, 0, gUnk_09618338, gUnk_0812A11C, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF065C, gUnk_09EF0690, gUnk_0938FFD8, 4, 0, gUnk_09618338, gUnk_0812A104, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0538, gUnk_09EF0548, gUnk_09382FF6, 2, 0, gUnk_09618338, gUnk_0812A0EC, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0550, gUnk_09EF0560, gUnk_09383A96, 1, 0, gUnk_09618338, gUnk_0812A0D4, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0564, gUnk_09EF0574, gUnk_09384AD6, 1, 0, gUnk_09618338, gUnk_0812A0BC, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0578, gUnk_09EF0588, gUnk_09385B5E, 1, 0, gUnk_09618338, gUnk_0812A0A4, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF058C, gUnk_09EF05AC, gUnk_093868D6, 1, 0, gUnk_09618338, gUnk_0812A090, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF05B0, gUnk_09EF05D0, gUnk_0938894E, 1, 0, gUnk_09618338, gUnk_0812A07C, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF05D4, gUnk_09EF05EC, gUnk_0938A9E6, 1, 0, gUnk_09618338, gUnk_0812A068, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF05F0, gUnk_09EF0608, gUnk_0938BD70, 1, 0, gUnk_09618338, gUnk_0812A054, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF060C, gUnk_09EF0628, gUnk_0938D282, 2, 0, gUnk_09618338, gUnk_0812A040, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0630, gUnk_09EF0638, gUnk_0938E526, 1, 0, gUnk_09618338, gUnk_0812A028, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF063C, gUnk_09EF0644, gUnk_0938ED68, 1, 0, gUnk_09618338, gUnk_0812A010, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0648, gUnk_09EF0658, gUnk_0938F3BE, 1, 0, gUnk_09618338, gUnk_08129FFC, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF06A0, gUnk_09EF06A4, gUnk_09392F58, 1, 0, gUnk_09618338, gUnk_08129FEC, gUnk_08129DA4, 32, 0 },
    { gUnk_09EF0820, gUnk_09EF0824, gUnk_093A5E10, 1, 0, gUnk_096183F8, gUnk_08129FDC, gUnk_08129534, 32, 0 },
    { gUnk_09EF0828, gUnk_09EF082C, gUnk_093A60B6, 1, 0, gUnk_096183F8, gUnk_08129FCC, gUnk_08129534, 32, 0 },
    { gUnk_09EF0830, gUnk_09EF0850, gUnk_093A636E, 1, 0, gUnk_096183F8, gUnk_08129FBC, gUnk_08129534, 32, 0 },
    { gUnk_09EF0854, gUnk_09EF0864, gUnk_093A78CC, 1, 0, gUnk_096183F8, gUnk_08129FAC, gUnk_08129534, 32, 0 },
    { gUnk_09EF0868, gUnk_09EF0888, gUnk_093A84B2, 1, 0, gUnk_096183F8, gUnk_08129F9C, gUnk_08129534, 32, 0 },
    { gUnk_09EF088C, gUnk_09EF089C, gUnk_093A9D0A, 1, 0, gUnk_096183F8, gUnk_08129F8C, gUnk_08129534, 32, 0 },
    { gUnk_09EF08A0, gUnk_09EF08B0, gUnk_093AA962, 1, 0, gUnk_096183F8, gUnk_08129F7C, gUnk_08129534, 32, 0 },
    { gUnk_09EF08B4, gUnk_09EF08C0, gUnk_093AB5A6, 1, 0, gUnk_096183F8, gUnk_08129F6C, gUnk_08129534, 32, 0 },
    { gUnk_09EF08C4, gUnk_09EF08E4, gUnk_093ABF4E, 1, 0, gUnk_096183F8, gUnk_08129F5C, gUnk_08129534, 32, 0 },
    { gUnk_09EF08E8, gUnk_09EF0908, gUnk_093AD4FC, 1, 0, gUnk_096183F8, gUnk_08129F4C, gUnk_08129534, 32, 0 },
};

ObjDef gUnk_09ED4834[] = {
    { gUnk_09EEC670, gUnk_09EEC698, gUnk_090D806A, 4, 0, gUnk_096149F8, gUnk_0812C878, gUnk_0812C868, 32, 0 },
    { gUnk_09EEC6A8, gUnk_09EEC6BC, gUnk_090D923A, 2, 0, gUnk_096149F8, gUnk_0812C858, gUnk_0812C868, 32, 0 },
    { gUnk_09EEC6C4, gUnk_09EEC6D8, gUnk_090DA002, 2, 0, gUnk_096149F8, gUnk_0812C848, gUnk_0812C868, 32, 0 },
    { gUnk_09EEC6E0, gUnk_09EEC6F4, gUnk_090DAC90, 2, 0, gUnk_096149F8, gUnk_0812C838, gUnk_0812C868, 32, 0 },
    { gUnk_09EEC6FC, gUnk_09EEC708, gUnk_090DBAA0, 2, 0, gUnk_096149F8, gUnk_0812C828, gUnk_0812C868, 32, 0 },
    { gUnk_09EEC710, gUnk_09EEC730, gUnk_090DC82A, 4, 0, gUnk_096149F8, gUnk_0812C818, gUnk_0812C868, 32, 0 },
    { gUnk_09EEC740, gUnk_09EEC768, gUnk_090DDB7C, 4, 0, gUnk_09614A18, gUnk_0812C808, gUnk_0812C7F8, 32, 0 },
    { gUnk_09EEC778, gUnk_09EEC7A0, gUnk_090DF972, 4, 0, gUnk_09614A18, gUnk_0812C7E8, gUnk_0812C7F8, 32, 0 },
    { gUnk_09EEC7B0, gUnk_09EEC7D8, gUnk_090E1970, 4, 0, gUnk_09614A18, gUnk_0812C7D8, gUnk_0812C7F8, 32, 0 },
    { gUnk_09EEC7E8, gUnk_09EEC810, gUnk_090E381E, 4, 0, gUnk_09614A18, gUnk_0812C7C8, gUnk_0812C7F8, 32, 0 },
    { gUnk_09EEC820, gUnk_09EEC834, gUnk_090E5BF4, 2, 0, gUnk_09614A18, gUnk_0812C7B8, gUnk_0812C7F8, 32, 0 },
    { gUnk_09EEC83C, gUnk_09EEC864, gUnk_090E6DB2, 4, 0, gUnk_09614A18, gUnk_0812C7A8, gUnk_0812C7F8, 32, 0 },
    { gUnk_09EEC740, gUnk_09EEC768, gUnk_090DDB7C, 4, 0, gUnk_09614CB8, gUnk_0812C808, gUnk_0812C798, 32, 0 },
    { gUnk_09EEC778, gUnk_09EEC7A0, gUnk_090DF972, 4, 0, gUnk_09614CB8, gUnk_0812C7E8, gUnk_0812C798, 32, 0 },
    { gUnk_09EEC7B0, gUnk_09EEC7D8, gUnk_090E1970, 4, 0, gUnk_09614CB8, gUnk_0812C7D8, gUnk_0812C798, 32, 0 },
    { gUnk_09EEC7E8, gUnk_09EEC810, gUnk_090E381E, 4, 0, gUnk_09614CB8, gUnk_0812C7C8, gUnk_0812C798, 32, 0 },
    { gUnk_09EEC83C, gUnk_09EEC864, gUnk_090E6DB2, 4, 0, gUnk_09614CB8, gUnk_0812C7A8, gUnk_0812C798, 32, 0 },
    { gUnk_09EEC874, gUnk_09EEC89C, gUnk_090E93DC, 4, 0, gUnk_09614A38, gUnk_0812C788, gUnk_0812C778, 32, 0 },
    { gUnk_09EEC8AC, gUnk_09EEC8D4, gUnk_090EB8D6, 4, 0, gUnk_09614A38, gUnk_0812C768, gUnk_0812C778, 32, 0 },
    { gUnk_09EEC8E4, gUnk_09EEC90C, gUnk_090EEAD6, 4, 0, gUnk_09614A38, gUnk_0812C758, gUnk_0812C778, 32, 0 },
    { gUnk_09EEC91C, gUnk_09EEC930, gUnk_090F0C52, 2, 0, gUnk_09614A38, gUnk_0812C748, gUnk_0812C778, 32, 0 },
    { gUnk_09EEC938, gUnk_09EEC94C, gUnk_090F1DC0, 2, 0, gUnk_09614A38, gUnk_0812C738, gUnk_0812C778, 32, 0 },
    { gUnk_09EEC874, gUnk_09EEC89C, gUnk_090E93DC, 4, 0, gUnk_09614CD8, gUnk_0812C788, gUnk_0812C728, 32, 0 },
    { gUnk_09EEC8AC, gUnk_09EEC8D4, gUnk_090EB8D6, 4, 0, gUnk_09614CD8, gUnk_0812C768, gUnk_0812C728, 32, 0 },
    { gUnk_09EEC8E4, gUnk_09EEC90C, gUnk_090EEAD6, 4, 0, gUnk_09614CD8, gUnk_0812C758, gUnk_0812C728, 32, 0 },
    { gUnk_09EEC954, gUnk_09EEC95C, gUnk_090F355E, 2, 0, gUnk_09614A58, gUnk_0812C718, gUnk_0812C708, 32, 0 },
    { gUnk_09EEC964, gUnk_09EEC978, gUnk_090F4176, 2, 0, gUnk_09614A78, gUnk_0812C6F8, gUnk_0812C6E8, 32, 0 },
    { gUnk_09EEC980, gUnk_09EEC99C, gUnk_090F69AA, 2, 0, gUnk_09614A78, gUnk_0812C6D8, gUnk_0812C6E8, 32, 0 },
    { gUnk_09EEC9A4, gUnk_09EEC9B8, gUnk_090F8522, 2, 0, gUnk_09614A78, gUnk_0812C6C8, gUnk_0812C6E8, 32, 0 },
    { gUnk_09EEC9C0, gUnk_09EEC9D4, gUnk_090FA1DA, 2, 0, gUnk_09614A78, gUnk_0812C6B8, gUnk_0812C6E8, 32, 0 },
    { gUnk_09EEC9DC, gUnk_09EECA24, gUnk_090FC130, 8, 0, gUnk_09614A98, gUnk_0812C6A8, gUnk_0812C698, 32, 0 },
    { gUnk_09EECA44, gUnk_09EECAA0, gUnk_090FDBF4, 10, 0, gUnk_09614AB8, gUnk_0812C688, gUnk_0812C678, 32, 0 },
    { gUnk_09EECAC8, gUnk_09EECAD0, gUnk_09100820, 2, 0, gUnk_09614AD8, gUnk_0812C668, gUnk_0812C658, 32, 0 },
    { gUnk_09EECAD8, gUnk_09EECB00, gUnk_0910150E, 4, 0, gUnk_09614AF8, gUnk_0812C648, gUnk_0812C638, 32, 0 },
    { gUnk_09EECB10, gUnk_09EECB28, gUnk_09102A5E, 2, 0, gUnk_09614B18, gUnk_0812C628, gUnk_0812C618, 32, 0 },
    { gUnk_09EECB30, gUnk_09EECB84, gUnk_09104D42, 12, 0, gUnk_09614B38, gUnk_0812C608, gUnk_0812C5F8, 32, 0 },
    { gUnk_09EECBB4, gUnk_09EECBF0, gUnk_09105E38, 6, 0, gUnk_09614B38, gUnk_0812C5E8, gUnk_0812C5F8, 32, 0 },
    { gUnk_09EECC08, gUnk_09EECC44, gUnk_09106E0A, 6, 0, gUnk_09614B38, gUnk_0812C5D8, gUnk_0812C5F8, 32, 0 },
    { gUnk_09EECC5C, gUnk_09EECC98, gUnk_09107DA0, 6, 0, gUnk_09614B38, gUnk_0812C5C8, gUnk_0812C5F8, 32, 0 },
    { gUnk_09EECCB0, gUnk_09EECCBC, gUnk_09108B24, 2, 0, gUnk_09614B58, gUnk_0812C5B8, gUnk_0812C5A8, 32, 0 },
    { gUnk_09EECCC4, gUnk_09EECCD0, gUnk_0910980C, 2, 0, gUnk_09614B58, gUnk_0812C598, gUnk_0812C5A8, 32, 0 },
    { gUnk_09EECCD8, gUnk_09EECCE4, gUnk_0910A636, 2, 0, gUnk_09614B58, gUnk_0812C588, gUnk_0812C5A8, 32, 0 },
    { gUnk_09EECCEC, gUnk_09EECCF8, gUnk_0910B540, 2, 0, gUnk_09614B58, gUnk_0812C578, gUnk_0812C5A8, 32, 0 },
    { gUnk_09EECD00, gUnk_09EECD0C, gUnk_0910C214, 2, 0, gUnk_09614B58, gUnk_0812C568, gUnk_0812C5A8, 32, 0 },
    { gUnk_09EECD14, gUnk_09EECD28, gUnk_0910D0D6, 2, 0, gUnk_09614B78, gUnk_0812C558, gUnk_0812C548, 32, 0 },
    { gUnk_09EECD30, gUnk_09EECD44, gUnk_0910F63A, 2, 0, gUnk_09614B78, gUnk_0812C538, gUnk_0812C548, 32, 0 },
    { gUnk_09EECD4C, gUnk_09EECD60, gUnk_09111B54, 2, 0, gUnk_09614B78, gUnk_0812C528, gUnk_0812C548, 32, 0 },
    { gUnk_09EECD68, gUnk_09EECD7C, gUnk_09113E16, 2, 0, gUnk_09614B78, gUnk_0812C518, gUnk_0812C548, 32, 0 },
    { gUnk_09EECD84, gUnk_09EECDCC, gUnk_09116698, 8, 0, gUnk_09614B98, gUnk_0812C508, gUnk_0812C4F8, 32, 0 },
    { gUnk_09EECDEC, gUnk_09EECE14, gUnk_091183C6, 4, 0, gUnk_09614B98, gUnk_0812C4E8, gUnk_0812C4F8, 32, 0 },
    { gUnk_09EECE24, gUnk_09EECE38, gUnk_09119238, 2, 0, gUnk_09614BB8, gUnk_0812C4D8, gUnk_0812C4C8, 32, 0 },
    { gUnk_09EECE40, gUnk_09EECE54, gUnk_0911A380, 2, 0, gUnk_09614BB8, gUnk_0812C4B8, gUnk_0812C4C8, 32, 0 },
    { gUnk_09EECE5C, gUnk_09EECE70, gUnk_0911BC8C, 2, 0, gUnk_09614BB8, gUnk_0812C4A8, gUnk_0812C4C8, 32, 0 },
    { gUnk_09EECE78, gUnk_09EECEB4, gUnk_0911D7D0, 6, 0, gUnk_09614BD8, gUnk_0812C498, gUnk_0812C488, 32, 0 },
    { gUnk_09EECECC, gUnk_09EECEE0, gUnk_0911E908, 2, 0, gUnk_09614BD8, gUnk_0812C478, gUnk_0812C488, 32, 0 },
    { gUnk_09EECEE8, gUnk_09EECEFC, gUnk_0911F500, 2, 0, gUnk_09614BD8, gUnk_0812C468, gUnk_0812C488, 32, 0 },
    { gUnk_09EECF04, gUnk_09EECF54, gUnk_09120572, 8, 0, gUnk_09614BF8, gUnk_0812C458, gUnk_0812C448, 32, 0 },
    { gUnk_09EECF74, gUnk_09EECFA8, gUnk_09122BB8, 6, 0, gUnk_09614C18, gUnk_0812C438, gUnk_0812C428, 32, 0 },
    { gUnk_09EECFC0, gUnk_09EECFFC, gUnk_09123D24, 6, 0, gUnk_09614C38, gUnk_0812C418, gUnk_0812C408, 32, 0 },
    { gUnk_09EED014, gUnk_09EED038, gUnk_09125D3A, 6, 0, gUnk_09614C58, gUnk_0812C3F8, gUnk_0812C3E8, 32, 0 },
    { gUnk_09EED050, gUnk_09EED064, gUnk_09127738, 2, 0, gUnk_09614C78, gUnk_0812C3D8, gUnk_0812C3C8, 32, 0 },
    { gUnk_09EED06C, gUnk_09EED080, gUnk_0912864E, 2, 0, gUnk_09614C78, gUnk_0812C3B8, gUnk_0812C3C8, 32, 0 },
    { gUnk_09EED088, gUnk_09EED09C, gUnk_0912930A, 2, 0, gUnk_09614C78, gUnk_0812C3A8, gUnk_0812C3C8, 32, 0 },
    { gUnk_09EED0A4, gUnk_09EED0B8, gUnk_0912A122, 2, 0, gUnk_09614C78, gUnk_0812C398, gUnk_0812C3C8, 32, 0 },
    { gUnk_09EED0C0, gUnk_09EED0D4, gUnk_0912AE36, 2, 0, gUnk_09614C98, gUnk_0812C388, gUnk_0812C378, 32, 0 },
    { gUnk_09EED0DC, gUnk_09EED0F0, gUnk_0912CC3E, 2, 0, gUnk_09614C98, gUnk_0812C368, gUnk_0812C378, 32, 0 },
    { gUnk_09EED0F8, gUnk_09EED10C, gUnk_0912EA68, 2, 0, gUnk_09614C98, gUnk_0812C358, gUnk_0812C378, 32, 0 },
    { gUnk_09EED114, gUnk_09EED120, gUnk_09130B36, 2, 0, gUnk_09614C98, gUnk_0812C348, gUnk_0812C378, 32, 0 },
    { gUnk_09EED128, gUnk_09EED13C, gUnk_09132AF4, 2, 0, gUnk_09614C98, gUnk_0812C338, gUnk_0812C378, 32, 0 },
    { gUnk_09EED144, gUnk_09EED158, gUnk_091348F0, 2, 0, gUnk_09614CF8, gUnk_0812C328, gUnk_0812C318, 32, 0 },
    { gUnk_09EED160, gUnk_09EED174, gUnk_091354EC, 2, 0, gUnk_09614CF8, gUnk_0812C308, gUnk_0812C318, 32, 0 },
    { gUnk_09EED17C, gUnk_09EED190, gUnk_09136068, 2, 0, gUnk_09614CF8, gUnk_0812C2F8, gUnk_0812C318, 32, 0 },
    { gUnk_09EED198, gUnk_09EED1AC, gUnk_09136CA4, 2, 0, gUnk_09614CF8, gUnk_0812C2E8, gUnk_0812C318, 32, 0 },
    { gUnk_09EED1B4, gUnk_09EED1C0, gUnk_09137888, 2, 0, gUnk_09614CF8, gUnk_0812C2D8, gUnk_0812C318, 32, 0 },
    { gUnk_09EED1C8, gUnk_09EED1DC, gUnk_09138384, 2, 0, gUnk_09614CF8, gUnk_0812C2C8, gUnk_0812C318, 32, 0 },
    { gUnk_09EED1E4, gUnk_09EED1F8, gUnk_09138FDE, 2, 0, gUnk_09614D18, gUnk_0812C2B8, gUnk_0812C2A8, 32, 0 },
    { gUnk_09EED200, gUnk_09EED214, gUnk_09139BDA, 2, 0, gUnk_09614D18, gUnk_0812C298, gUnk_0812C2A8, 32, 0 },
    { gUnk_09EED21C, gUnk_09EED230, gUnk_0913A7D6, 2, 0, gUnk_09614D18, gUnk_0812C288, gUnk_0812C2A8, 32, 0 },
    { gUnk_09EED238, gUnk_09EED24C, gUnk_0913B3D2, 2, 0, gUnk_09614D18, gUnk_0812C278, gUnk_0812C2A8, 32, 0 },
    { gUnk_09EED254, gUnk_09EED268, gUnk_0913BFCE, 2, 0, gUnk_09614D18, gUnk_0812C268, gUnk_0812C2A8, 32, 0 },
    { gUnk_09EED270, gUnk_09EED284, gUnk_0913CBCA, 2, 0, gUnk_09614D18, gUnk_0812C258, gUnk_0812C2A8, 32, 0 },
    { gUnk_09EED28C, gUnk_09EED2A0, gUnk_0913D796, 2, 0, gUnk_09614D38, gUnk_0812C248, gUnk_0812C238, 32, 0 },
    { gUnk_09EED2A8, gUnk_09EED2B4, gUnk_0913E1EA, 2, 0, gUnk_09614D38, gUnk_0812C228, gUnk_0812C238, 32, 0 },
    { gUnk_09EED2BC, gUnk_09EED320, gUnk_0913F0C2, 10, 0, gUnk_09614D58, gUnk_0812C218, gUnk_0812C208, 32, 0 },
    { gUnk_09EED348, gUnk_09EED35C, gUnk_09142D0E, 2, 0, gUnk_09614D78, gUnk_0812C1F8, gUnk_0812C1E8, 32, 0 },
    { gUnk_09EED364, gUnk_09EED370, gUnk_091437A2, 2, 0, gUnk_09614D78, gUnk_0812C1D8, gUnk_0812C1E8, 32, 0 },
    { gUnk_09EED378, gUnk_09EED38C, gUnk_091441CE, 2, 0, gUnk_09614D78, gUnk_0812C1C8, gUnk_0812C1E8, 32, 0 },
    { gUnk_09EED394, gUnk_09EED3A8, gUnk_09144CBA, 2, 0, gUnk_09614D78, gUnk_0812C1B8, gUnk_0812C1E8, 32, 0 },
    { gUnk_09EED3B0, gUnk_09EED3C4, gUnk_091457A6, 2, 0, gUnk_09614D78, gUnk_0812C1A8, gUnk_0812C1E8, 32, 0 },
    { gUnk_09EED3CC, gUnk_09EED3D8, gUnk_0914623A, 2, 0, gUnk_09614D78, gUnk_0812C198, gUnk_0812C1E8, 32, 0 },
    { gUnk_09EED3E0, gUnk_09EED3F4, gUnk_09146C84, 2, 0, gUnk_09614D98, gUnk_0812C188, gUnk_0812C178, 32, 0 },
    { gUnk_09EED3FC, gUnk_09EED410, gUnk_091477CE, 2, 0, gUnk_09614D98, gUnk_0812C168, gUnk_0812C178, 32, 0 },
    { gUnk_09EED418, gUnk_09EED424, gUnk_09148322, 2, 0, gUnk_09614D98, gUnk_0812C158, gUnk_0812C178, 32, 0 },
    { gUnk_09EED42C, gUnk_09EED440, gUnk_09148E2C, 2, 0, gUnk_09614D98, gUnk_0812C148, gUnk_0812C178, 32, 0 },
    { gUnk_09EED448, gUnk_09EED45C, gUnk_09149A16, 2, 0, gUnk_09614D98, gUnk_0812C138, gUnk_0812C178, 32, 0 },
    { gUnk_09EED464, gUnk_09EED478, gUnk_0914A5AC, 2, 0, gUnk_09614DB8, gUnk_0812C128, gUnk_0812C118, 32, 0 },
    { gUnk_09EED480, gUnk_09EED494, gUnk_0914B292, 2, 0, gUnk_09614DB8, gUnk_0812C108, gUnk_0812C118, 32, 0 },
    { gUnk_09EED49C, gUnk_09EED4B0, gUnk_0914BEE6, 2, 0, gUnk_09614DB8, gUnk_0812C0F8, gUnk_0812C118, 32, 0 },
    { gUnk_09EED4B8, gUnk_09EED4CC, gUnk_0914CB9C, 2, 0, gUnk_09614DB8, gUnk_0812C0E8, gUnk_0812C118, 32, 0 },
    { gUnk_09EED4D4, gUnk_09EED4E8, gUnk_0914D870, 2, 0, gUnk_09614DD8, gUnk_0812C0D8, gUnk_0812C0C8, 32, 0 },
    { gUnk_09EED4F0, gUnk_09EED504, gUnk_0914E544, 2, 0, gUnk_09614DD8, gUnk_0812C0B8, gUnk_0812C0C8, 32, 0 },
    { gUnk_09EED50C, gUnk_09EED520, gUnk_0914F218, 2, 0, gUnk_09614DD8, gUnk_0812C0A8, gUnk_0812C0C8, 32, 0 },
    { gUnk_09EED528, gUnk_09EED53C, gUnk_0914FEEC, 2, 0, gUnk_09614DD8, gUnk_0812C098, gUnk_0812C0C8, 32, 0 },
    { gUnk_09EED544, gUnk_09EED558, gUnk_09150BD2, 2, 0, gUnk_09614DF8, gUnk_0812C088, gUnk_0812C078, 32, 0 },
    { gUnk_09EED560, gUnk_09EED574, gUnk_091519DA, 2, 0, gUnk_09614DF8, gUnk_0812C068, gUnk_0812C078, 32, 0 },
    { gUnk_09EED57C, gUnk_09EED590, gUnk_09152800, 2, 0, gUnk_09614DF8, gUnk_0812C058, gUnk_0812C078, 32, 0 },
    { gUnk_09EED598, gUnk_09EED5B8, gUnk_0915362A, 4, 0, gUnk_09614E18, gUnk_0812C048, gUnk_0812C038, 32, 0 },
    { gUnk_09EED5C8, gUnk_09EED5DC, gUnk_09154234, 2, 0, gUnk_09614E18, gUnk_0812C028, gUnk_0812C038, 32, 0 },
    { gUnk_09EED5E4, gUnk_09EED5F8, gUnk_09154E3C, 2, 0, gUnk_09614E18, gUnk_0812C018, gUnk_0812C038, 32, 0 },
    { gUnk_09EED600, gUnk_09EED614, gUnk_09155A44, 2, 0, gUnk_09614E18, gUnk_0812C008, gUnk_0812C038, 32, 0 },
    { gUnk_09EED61C, gUnk_09EED630, gUnk_0915664C, 2, 0, gUnk_09614E18, gUnk_0812BFF8, gUnk_0812C038, 32, 0 },
    { gUnk_09EED638, gUnk_09EED64C, gUnk_09157254, 2, 0, gUnk_09614E38, gUnk_0812BFE8, gUnk_0812BFD8, 32, 0 },
    { gUnk_09EED654, gUnk_09EED668, gUnk_09157E86, 2, 0, gUnk_09614E58, gUnk_0812BFC8, gUnk_0812BFB8, 32, 0 },
    { gUnk_09EED670, gUnk_09EED684, gUnk_09158B5A, 2, 0, gUnk_09614E58, gUnk_0812BFA8, gUnk_0812BFB8, 32, 0 },
    { gUnk_09EED68C, gUnk_09EED6A0, gUnk_09159810, 2, 0, gUnk_09614E58, gUnk_0812BF98, gUnk_0812BFB8, 32, 0 },
    { gUnk_09EED6A8, gUnk_09EED6BC, gUnk_0915A48C, 2, 0, gUnk_09614E78, gUnk_0812BF88, gUnk_0812BF78, 32, 0 },
    { gUnk_09EED6C4, gUnk_09EED6EC, gUnk_0915B290, 4, 0, gUnk_09614E98, gUnk_0812BF68, gUnk_0812BF58, 32, 0 },
    { gUnk_09EED6FC, gUnk_09EED730, gUnk_0915CCF8, 6, 0, gUnk_09614EB8, gUnk_0812BF48, gUnk_0812BF38, 32, 0 },
    { gUnk_09EED748, gUnk_09EED75C, gUnk_0915E942, 2, 0, gUnk_09614EB8, gUnk_0812BF28, gUnk_0812BF38, 32, 0 },
    { gUnk_09EED764, gUnk_09EED778, gUnk_0915F78A, 2, 0, gUnk_09614EB8, gUnk_0812BF18, gUnk_0812BF38, 32, 0 },
    { gUnk_09EED780, gUnk_09EED7C8, gUnk_09160A9E, 8, 0, gUnk_09614ED8, gUnk_0812BF08, gUnk_0812BEF8, 32, 0 },
    { gUnk_09EED800, gUnk_09EED814, gUnk_09163C18, 2, 0, gUnk_09614EF8, gUnk_0812BEE8, gUnk_0812BED8, 32, 0 },
    { gUnk_09EED81C, gUnk_09EED830, gUnk_09164CE6, 2, 0, gUnk_09614EF8, gUnk_0812BEC8, gUnk_0812BED8, 32, 0 },
    { gUnk_09EED838, gUnk_09EED84C, gUnk_09165FC8, 2, 0, gUnk_09614EF8, gUnk_0812BEB8, gUnk_0812BED8, 32, 0 },
    { gUnk_09EED854, gUnk_09EED868, gUnk_09167104, 2, 0, gUnk_09614EF8, gUnk_0812BEA8, gUnk_0812BED8, 32, 0 },
    { gUnk_09EED870, gUnk_09EED898, gUnk_091684B0, 4, 0, gUnk_09614F18, gUnk_0812BE98, gUnk_0812BE88, 32, 0 },
    { gUnk_09EED8A8, gUnk_09EED8D0, gUnk_09169596, 4, 0, gUnk_09614F18, gUnk_0812BE78, gUnk_0812BE88, 32, 0 },
    { gUnk_09EED8E0, gUnk_09EED91C, gUnk_0916B056, 6, 0, gUnk_09614F38, gUnk_0812BE68, gUnk_0812BE58, 32, 0 },
    { gUnk_09EED934, gUnk_09EED970, gUnk_0916CD7C, 6, 0, gUnk_09614F58, gUnk_0812BE48, gUnk_0812BE38, 32, 0 },
    { gUnk_09EED988, gUnk_09EED9B0, gUnk_0916E20A, 4, 0, gUnk_09614F78, gUnk_0812BE28, gUnk_0812BE18, 32, 0 },
    { gUnk_09EED9C0, gUnk_09EED9E8, gUnk_0916FE52, 4, 0, gUnk_09614F98, gUnk_0812BE08, gUnk_0812BDF8, 32, 0 },
    { gUnk_09EED9F8, gUnk_09EEDA2C, gUnk_09170ED0, 6, 0, gUnk_09614FB8, gUnk_0812BDE8, gUnk_0812BDD8, 32, 0 },
    { gUnk_09EEDA44, gUnk_09EEDA78, gUnk_091728BC, 6, 0, gUnk_09614FD8, gUnk_0812BDC8, gUnk_0812BDB8, 32, 0 },
    { gUnk_09EEDA90, gUnk_09EEDAA4, gUnk_091743FC, 2, 0, gUnk_09614FF8, gUnk_0812BDA8, gUnk_0812BD98, 32, 0 },
    { gUnk_09EEDAAC, gUnk_09EEDAC0, gUnk_0917513A, 2, 0, gUnk_09614FF8, gUnk_0812BD88, gUnk_0812BD98, 32, 0 },
    { gUnk_09EEDAC8, gUnk_09EEDADC, gUnk_09175E7A, 2, 0, gUnk_09614FF8, gUnk_0812BD78, gUnk_0812BD98, 32, 0 },
    { gUnk_09EEDAE4, gUnk_09EEDAF8, gUnk_09176B90, 2, 0, gUnk_09614FF8, gUnk_0812BD68, gUnk_0812BD98, 32, 0 },
    { gUnk_09EEDB00, gUnk_09EEDB14, gUnk_091779F0, 2, 0, gUnk_09614FF8, gUnk_0812BD58, gUnk_0812BD98, 32, 0 },
    { gUnk_09EEDB1C, gUnk_09EEDB64, gUnk_0917895E, 8, 0, gUnk_09615018, gUnk_0812BD48, gUnk_0812BD38, 32, 0 },
    { gUnk_09EEDB9C, gUnk_09EEDBB0, gUnk_0917D0D0, 2, 0, gUnk_09615038, gUnk_0812BD28, gUnk_0812BD18, 32, 0 },
    { gUnk_09EEDBB8, gUnk_09EEDBE0, gUnk_0917E348, 4, 0, gUnk_09615038, gUnk_0812BD08, gUnk_0812BD18, 32, 0 },
    { gUnk_09EEDBF0, gUnk_09EEDC04, gUnk_0917F7A6, 2, 0, gUnk_09615038, gUnk_0812BCF8, gUnk_0812BD18, 32, 0 },
    { gUnk_09EEDC0C, gUnk_09EEDC34, gUnk_091808CE, 4, 0, gUnk_09615078, gUnk_0812BCE8, gUnk_0812BCD8, 32, 0 },
    { gUnk_09EEDC44, gUnk_09EEDC50, gUnk_09181626, 2, 0, gUnk_09615078, gUnk_0812BCC8, gUnk_0812BCD8, 32, 0 },
    { gUnk_09EEDC58, gUnk_09EEDC6C, gUnk_0918218C, 2, 0, gUnk_09615098, gUnk_0812BCB8, gUnk_0812BCA8, 32, 0 },
    { gUnk_09EEDC74, gUnk_09EEDC88, gUnk_09182EFC, 2, 0, gUnk_09615098, gUnk_0812BC98, gUnk_0812BCA8, 32, 0 },
    { gUnk_09EEDC90, gUnk_09EEDCA4, gUnk_09183C6C, 2, 0, gUnk_09615098, gUnk_0812BC88, gUnk_0812BCA8, 32, 0 },
    { gUnk_09EEDCAC, gUnk_09EEDCC0, gUnk_091849E2, 2, 0, gUnk_09615098, gUnk_0812BC78, gUnk_0812BCA8, 32, 0 },
    { gUnk_09EEDCC8, gUnk_09EEDCDC, gUnk_09185AF4, 2, 0, gUnk_09615098, gUnk_0812BC68, gUnk_0812BCA8, 32, 0 },
    { gUnk_09EEDCE4, gUnk_09EEDCF8, gUnk_0918689C, 2, 0, gUnk_096150B8, gUnk_0812BC58, gUnk_0812BC48, 32, 0 },
    { gUnk_09EEDD00, gUnk_09EEDD14, gUnk_091875F0, 2, 0, gUnk_096150B8, gUnk_0812BC38, gUnk_0812BC48, 32, 0 },
    { gUnk_09EEDD1C, gUnk_09EEDD30, gUnk_09188204, 2, 0, gUnk_096150B8, gUnk_0812BC28, gUnk_0812BC48, 32, 0 },
    { gUnk_09EEDD38, gUnk_09EEDD4C, gUnk_09188E18, 2, 0, gUnk_096150B8, gUnk_0812BC18, gUnk_0812BC48, 32, 0 },
    { gUnk_09EEDD54, gUnk_09EEDD68, gUnk_09189A4A, 2, 0, gUnk_096150B8, gUnk_0812BC08, gUnk_0812BC48, 32, 0 },
    { gUnk_09EEDD70, gUnk_09EEDD84, gUnk_0918A6DA, 2, 0, gUnk_096150D8, gUnk_0812BBF8, gUnk_0812BBE8, 32, 0 },
    { gUnk_09EEDD8C, gUnk_09EEDDA0, gUnk_0918B5B4, 2, 0, gUnk_096150D8, gUnk_0812BBD8, gUnk_0812BBE8, 32, 0 },
    { gUnk_09EEDDA8, gUnk_09EEDDBC, gUnk_0918C55E, 2, 0, gUnk_096150D8, gUnk_0812BBC8, gUnk_0812BBE8, 32, 0 },
    { gUnk_09EEDDC4, gUnk_09EEDDE4, gUnk_0918D538, 4, 0, gUnk_096150F8, gUnk_0812BBB8, gUnk_0812BBA8, 32, 0 },
    { gUnk_09EEDDF4, gUnk_09EEDE00, gUnk_0918E2B6, 2, 0, gUnk_096150F8, gUnk_0812BB98, gUnk_0812BBA8, 32, 0 },
    { gUnk_09EEDE08, gUnk_09EEDE1C, gUnk_0918EE36, 2, 0, gUnk_096150F8, gUnk_0812BB88, gUnk_0812BBA8, 32, 0 },
    { gUnk_09EEDE24, gUnk_09EEDE4C, gUnk_0918FB92, 4, 0, gUnk_09615118, gUnk_0812BB78, gUnk_0812BB68, 32, 0 },
    { gUnk_09EEDE5C, gUnk_09EEDE70, gUnk_09190A10, 2, 0, gUnk_09615118, gUnk_0812BB58, gUnk_0812BB68, 32, 0 },
    { gUnk_09EEDE78, gUnk_09EEDE98, gUnk_091915E8, 4, 0, gUnk_09615138, gUnk_0812BB48, gUnk_0812BB38, 32, 0 },
    { gUnk_09EEDEA8, gUnk_09EEDEB4, gUnk_09192446, 2, 0, gUnk_09615138, gUnk_0812BB28, gUnk_0812BB38, 32, 0 },
    { gUnk_09EEDEBC, gUnk_09EEDEDC, gUnk_09193326, 4, 0, gUnk_09615158, gUnk_0812BB18, gUnk_0812BB08, 32, 0 },
    { gUnk_09EEDEEC, gUnk_09EEDF28, gUnk_091942A4, 6, 0, gUnk_09615178, gUnk_0812BAF8, gUnk_0812BAE8, 32, 0 },
    { gUnk_09EEDF40, gUnk_09EEDF54, gUnk_09195750, 2, 0, gUnk_09615198, gUnk_0812BAD8, gUnk_0812BAC8, 32, 0 },
    { gUnk_09EEDF5C, gUnk_09EEDF90, gUnk_0919632C, 6, 0, gUnk_096151B8, gUnk_0812BAB8, gUnk_0812BAA8, 32, 0 },
};

ObjDef gUnk_09ED5D34[] = {
    { gUnk_09EEAF4C, gUnk_09EEAFB0, gUnk_090A0C86, 9, 0, gUnk_09611AB8, gUnk_0812DEA4, gUnk_0812DE98, 32, 0 },
    { gUnk_09EE91B0, gUnk_09EE91B4, gUnk_09045254, 1, 0, gUnk_09611AD8, gUnk_0812DE88, gUnk_0812DE78, 32, 0 },
    { gUnk_09EE91B8, gUnk_09EE91BC, gUnk_09045468, 1, 0, gUnk_09611AF8, gUnk_0812DE68, gUnk_0812DE58, 32, 0 },
    { gUnk_09EE91C0, gUnk_09EE91C4, gUnk_0904567C, 1, 0, gUnk_09611B18, gUnk_0812DE48, gUnk_0812DE38, 32, 0 },
    { gUnk_09EE91C8, gUnk_09EE91CC, gUnk_09045890, 1, 0, gUnk_09611B38, gUnk_0812DE28, gUnk_0812DE18, 32, 0 },
    { gUnk_09EE91D0, gUnk_09EE91D4, gUnk_09045AA4, 1, 0, gUnk_09611B58, gUnk_0812DE08, gUnk_0812DDF8, 32, 0 },
    { gUnk_09EE91D8, gUnk_09EE91DC, gUnk_09045CB8, 1, 0, gUnk_09611B78, gUnk_0812DDE8, gUnk_0812DDD8, 32, 0 },
    { gUnk_09EE91E0, gUnk_09EE91E4, gUnk_09045ECC, 1, 0, gUnk_09611B98, gUnk_0812DDC8, gUnk_0812DDB8, 32, 0 },
    { gUnk_09EE94A4, gUnk_09EE94A8, gUnk_09051594, 1, 0, gUnk_09611E58, gUnk_0812DDA8, gUnk_0812DD98, 32, 0 },
    { gUnk_09EE94B4, gUnk_09EE94BC, gUnk_090519CC, 1, 0, gUnk_09611E98, gUnk_0812DD88, gUnk_0812DD78, 32, 0 },
    { gUnk_09EE94C0, gUnk_09EE94C4, gUnk_09051FE0, 1, 0, gUnk_09611EB8, gUnk_0812DD68, gUnk_0812DD58, 32, 0 },
    { gUnk_09EE94C8, gUnk_09EE94D0, gUnk_090521F6, 1, 0, gUnk_09611ED8, gUnk_0812DD48, gUnk_0812DD38, 32, 0 },
    { gUnk_09EE94D4, gUnk_09EE94D8, gUnk_0905240C, 1, 0, gUnk_09611EF8, gUnk_0812DD28, gUnk_0812DD18, 32, 0 },
    { gUnk_09EE94DC, gUnk_09EE94E0, gUnk_09052620, 1, 0, gUnk_09611F18, gUnk_0812DD08, gUnk_0812DCF8, 32, 0 },
    { gUnk_09EE94E4, gUnk_09EE94E8, gUnk_09052834, 1, 0, gUnk_09611F38, gUnk_0812DCE8, gUnk_0812DCD8, 32, 0 },
    { gUnk_09EE94EC, gUnk_09EE94F0, gUnk_09052A48, 1, 0, gUnk_09611F58, gUnk_0812DCC8, gUnk_0812DCB8, 32, 0 },
    { gUnk_09EE94F4, gUnk_09EE94F8, gUnk_09052C5C, 1, 0, gUnk_09611F78, gUnk_0812DCA8, gUnk_0812DC98, 32, 0 },
    { gUnk_09EE94FC, gUnk_09EE9500, gUnk_09052E70, 1, 0, gUnk_09611F98, gUnk_0812DC88, gUnk_0812DC78, 32, 0 },
    { gUnk_09EE9504, gUnk_09EE9508, gUnk_09053084, 1, 0, gUnk_09611FB8, gUnk_0812DC68, gUnk_0812DC58, 32, 0 },
    { gUnk_09EE950C, gUnk_09EE9510, gUnk_09053298, 1, 0, gUnk_09611FD8, gUnk_0812DC48, gUnk_0812DC38, 32, 0 },
    { gUnk_09EE9514, gUnk_09EE9518, gUnk_090534AC, 1, 0, gUnk_09611FF8, gUnk_0812DC28, gUnk_0812DC18, 32, 0 },
    { gUnk_09EE951C, gUnk_09EE9520, gUnk_090536C0, 1, 0, gUnk_09612018, gUnk_0812DC08, gUnk_0812DBF8, 32, 0 },
    { gUnk_09EE9524, gUnk_09EE9528, gUnk_090538D4, 1, 0, gUnk_09612038, gUnk_0812DBE8, gUnk_0812DBD8, 32, 0 },
    { gUnk_09EE952C, gUnk_09EE9530, gUnk_09053AE8, 1, 0, gUnk_09612058, gUnk_0812DBC8, gUnk_0812DBB8, 32, 0 },
    { gUnk_09EE9534, gUnk_09EE9538, gUnk_09053CFC, 1, 0, gUnk_09612078, gUnk_0812DBA8, gUnk_0812DB98, 32, 0 },
    { gUnk_09EE953C, gUnk_09EE9540, gUnk_09053F10, 1, 0, gUnk_09612098, gUnk_0812DB88, gUnk_0812DB78, 32, 0 },
    { gUnk_09EE9208, gUnk_09EE920C, gUnk_090461B0, 1, 0, gUnk_09611BB8, gUnk_0812DB68, gUnk_0812DB58, 32, 0 },
    { gUnk_09EE9210, gUnk_09EE9214, gUnk_090463C4, 1, 0, gUnk_09611BD8, gUnk_0812DB48, gUnk_0812DB38, 32, 0 },
    { gUnk_09EE9218, gUnk_09EE921C, gUnk_090465D8, 1, 0, gUnk_09611BF8, gUnk_0812DB28, gUnk_0812DB18, 32, 0 },
    { gUnk_09EE9220, gUnk_09EE9224, gUnk_090467EC, 1, 0, gUnk_09611C18, gUnk_0812DB08, gUnk_0812DAF8, 32, 0 },
    { gUnk_09EE9228, gUnk_09EE922C, gUnk_09046A00, 1, 0, gUnk_09611C38, gUnk_0812DAE8, gUnk_0812DAD8, 32, 0 },
    { gUnk_09EE9230, gUnk_09EE9234, gUnk_09046C14, 1, 0, gUnk_09611C58, gUnk_0812DAC8, gUnk_0812DAB8, 32, 0 },
    { gUnk_09EE9238, gUnk_09EE923C, gUnk_09046E28, 1, 0, gUnk_09611C78, gUnk_0812DAA8, gUnk_0812DA98, 32, 0 },
    { gUnk_09EE9270, gUnk_09EE9274, gUnk_09047F5C, 1, 0, gUnk_08F68384, gUnk_0812DA88, gUnk_081296C0, 32, 0 },
    { gUnk_09EE9278, gUnk_09EE927C, gUnk_09048170, 1, 0, gUnk_09617C58, gUnk_0812DA78, gUnk_08129680, 32, 0 },
    { gUnk_09EE9280, gUnk_09EE9284, gUnk_09048384, 1, 0, gUnk_09611CF8, gUnk_0812DA68, gUnk_0812DA58, 32, 0 },
    { gUnk_09EE9288, gUnk_09EE928C, gUnk_09048598, 1, 0, gUnk_09611D18, gUnk_0812DA48, gUnk_0812DA38, 32, 0 },
    { gUnk_09EE9290, gUnk_09EE9294, gUnk_090487AC, 1, 0, gUnk_09617FF8, gUnk_0812DA28, gUnk_081295E0, 32, 0 },
    { gUnk_09EE9298, gUnk_09EE929C, gUnk_090489C0, 1, 0, gUnk_09611D58, gUnk_0812DA18, gUnk_0812DA08, 32, 0 },
    { gUnk_09EE92A0, gUnk_09EE92A4, gUnk_09048BD4, 1, 0, gUnk_09618098, gUnk_0812D9F8, gUnk_0812A7F4, 32, 0 },
    { gUnk_09EE92A8, gUnk_09EE92AC, gUnk_09048DE8, 1, 0, gUnk_09618038, gUnk_0812D9E8, gUnk_081295C4, 32, 0 },
    { gUnk_09EE92B0, gUnk_09EE92B4, gUnk_09048FFC, 1, 0, gUnk_09611DB8, gUnk_0812D9D8, gUnk_0812D9C8, 32, 0 },
    { gUnk_09EE92B0, gUnk_09EE92B4, gUnk_09048FFC, 1, 0, gUnk_09611DD8, gUnk_0812D9D8, gUnk_0812D9B8, 32, 0 },
    { gUnk_09EE92B0, gUnk_09EE92B4, gUnk_09048FFC, 1, 0, gUnk_09611DF8, gUnk_0812D9D8, gUnk_0812D9A8, 32, 0 },
    { gUnk_09EE92B0, gUnk_09EE92B4, gUnk_09048FFC, 1, 0, gUnk_09611E18, gUnk_0812D9D8, gUnk_0812D998, 32, 0 },
    { gUnk_09EE92B0, gUnk_09EE92B4, gUnk_09048FFC, 1, 0, gUnk_09611E38, gUnk_0812D9D8, gUnk_0812D988, 32, 0 },
    { gUnk_09EE92B8, gUnk_09EE92BC, gUnk_09049210, 1, 0, gUnk_09617D98, gUnk_0812D978, gUnk_081295A8, 32, 0 },
    { gUnk_09EE92C0, gUnk_09EE92C4, gUnk_09049424, 1, 0, gUnk_09617DF8, gUnk_0812D968, gUnk_0812ADD4, 32, 0 },
    { gUnk_09EE92C8, gUnk_09EE92CC, gUnk_09049638, 1, 0, gUnk_09617DB8, gUnk_0812D958, gUnk_0812AE88, 32, 0 },
    { gUnk_09EE92D0, gUnk_09EE92D4, gUnk_0904984C, 1, 0, gUnk_09617DD8, gUnk_0812D948, gUnk_0812958C, 32, 0 },
    { gUnk_09EE92D8, gUnk_09EE92DC, gUnk_09049A60, 1, 0, gUnk_09617E18, gUnk_0812D938, gUnk_08129550, 32, 0 },
    { gUnk_09EE92E0, gUnk_09EE92E4, gUnk_09049C74, 1, 0, gUnk_096183F8, gUnk_0812D928, gUnk_08129534, 32, 0 },
    { gUnk_09EE9310, gUnk_09EE9314, gUnk_0904AD94, 1, 0, gUnk_08F697A4, gUnk_0812D918, gUnk_08129518, 32, 0 },
    { gUnk_09EE9318, gUnk_09EE931C, gUnk_0904AFA8, 1, 0, gUnk_08F69804, gUnk_0812D908, gUnk_0812947C, 32, 0 },
    { gUnk_09EE9318, gUnk_09EE931C, gUnk_0904AFA8, 1, 0, gUnk_08F69824, gUnk_0812D908, gUnk_08129470, 32, 0 },
    { gUnk_09EE9318, gUnk_09EE931C, gUnk_0904AFA8, 1, 0, gUnk_08F69844, gUnk_0812D908, gUnk_08129464, 32, 0 },
    { gUnk_09EE9318, gUnk_09EE931C, gUnk_0904AFA8, 1, 0, gUnk_08F69864, gUnk_0812D908, gUnk_08129458, 32, 0 },
    { gUnk_09EE9338, gUnk_09EE933C, gUnk_0904B7F8, 1, 0, gUnk_08F69924, gUnk_0812D8F8, gUnk_0812943C, 32, 0 },
    { gUnk_09EE9340, gUnk_09EE9344, gUnk_0904BA0C, 1, 0, gUnk_08F698A4, gUnk_0812D8E8, gUnk_081293F0, 32, 0 },
    { gUnk_09EE9348, gUnk_09EE934C, gUnk_0904BC20, 1, 0, gUnk_08F698E4, gUnk_0812D8D8, gUnk_08129340, 32, 0 },
    { gUnk_09EE9350, gUnk_09EE9354, gUnk_0904BE34, 1, 0, gUnk_08F697E4, gUnk_0812D8C8, gUnk_081292B8, 32, 0 },
    { gUnk_09EE9358, gUnk_09EE935C, gUnk_0904C048, 1, 0, gUnk_08F69944, gUnk_0812D8B8, gUnk_0812925C, 32, 0 },
    { gUnk_09EE9360, gUnk_09EE9364, gUnk_0904C25C, 1, 0, gUnk_08F699C4, gUnk_0812D8A8, gUnk_08129200, 32, 0 },
    { gUnk_09EE9368, gUnk_09EE936C, gUnk_0904C470, 1, 0, gUnk_08F69B24, gUnk_0812D898, gUnk_08129184, 32, 0 },
    { gUnk_09EE9370, gUnk_09EE9374, gUnk_0904C684, 1, 0, gUnk_08F69964, gUnk_0812D888, gUnk_08129128, 32, 0 },
    { gUnk_09EE9378, gUnk_09EE937C, gUnk_0904C898, 1, 0, gUnk_08F69884, gUnk_0812D878, gUnk_081290CC, 32, 0 },
    { gUnk_09EE9380, gUnk_09EE9384, gUnk_0904CAAC, 1, 0, gUnk_08F699E4, gUnk_0812D868, gUnk_08129050, 32, 0 },
    { gUnk_09EE9388, gUnk_09EE938C, gUnk_0904CCC0, 1, 0, gUnk_08F69984, gUnk_0812D858, gUnk_08129004, 32, 0 },
    { gUnk_09EE9390, gUnk_09EE9394, gUnk_0904CED4, 1, 0, gUnk_08F69AE4, gUnk_0812D848, gUnk_08128FA8, 32, 0 },
    { gUnk_09EE9398, gUnk_09EE939C, gUnk_0904D0E8, 1, 0, gUnk_08F69A04, gUnk_0812D838, gUnk_08128F4C, 32, 0 },
    { gUnk_09EE93A0, gUnk_09EE93A4, gUnk_0904D2FC, 1, 0, gUnk_08F69A24, gUnk_0812D828, gUnk_08128EF0, 32, 0 },
    { gUnk_09EE93A8, gUnk_09EE93AC, gUnk_0904D510, 1, 0, gUnk_08F69A44, gUnk_0812D818, gUnk_08128E94, 32, 0 },
    { gUnk_09EE93B0, gUnk_09EE93B4, gUnk_0904D724, 1, 0, gUnk_08F69A64, gUnk_0812D808, gUnk_08128E38, 32, 0 },
    { gUnk_09EE93B8, gUnk_09EE93BC, gUnk_0904D938, 1, 0, gUnk_08F69AC4, gUnk_0812D7F8, gUnk_08128DEC, 32, 0 },
    { gUnk_09EE93C0, gUnk_09EE93C4, gUnk_0904DB4C, 1, 0, gUnk_08F69904, gUnk_0812D7E8, gUnk_08128D90, 32, 0 },
    { gUnk_09EE93D0, gUnk_09EE93D4, gUnk_0904DF88, 1, 0, gUnk_08F69A84, gUnk_0812D7D8, gUnk_08128D34, 32, 0 },
    { gUnk_09EE93D8, gUnk_09EE93DC, gUnk_0904E19C, 1, 0, gUnk_08F697C4, gUnk_0812D7C8, gUnk_08128CB8, 32, 0 },
    { gUnk_09EE93E0, gUnk_09EE93E4, gUnk_0904E3B0, 1, 0, gUnk_08F69AA4, gUnk_0812D7B8, gUnk_08128C5C, 32, 0 },
    { gUnk_09EE93E8, gUnk_09EE93EC, gUnk_0904E5C4, 1, 0, gUnk_08F699A4, gUnk_0812D7A8, gUnk_08128C00, 32, 0 },
    { gUnk_09EE93F0, gUnk_09EE93F4, gUnk_0904E7D8, 1, 0, gUnk_08F69B04, gUnk_0812D798, gUnk_08128BA4, 32, 0 },
    { gUnk_09EE93F8, gUnk_09EE93FC, gUnk_0904E9EC, 1, 0, gUnk_08F69B44, gUnk_0812D788, gUnk_08128B48, 32, 0 },
    { gUnk_09EE9400, gUnk_09EE9404, gUnk_0904EC00, 1, 0, gUnk_08F69B64, gUnk_0812D778, gUnk_08128AEC, 32, 0 },
    { gUnk_09EE9408, gUnk_09EE940C, gUnk_0904EE14, 1, 0, gUnk_08F69B84, gUnk_0812D768, gUnk_08128A70, 32, 0 },
    { gUnk_09EE9410, gUnk_09EE9414, gUnk_0904F028, 1, 0, gUnk_096FB8A4, gUnk_0812D758, gUnk_0812D748, 32, 0 },
    { gUnk_09EE9418, gUnk_09EE941C, gUnk_0904F23C, 1, 0, gUnk_09A3C89C, gUnk_0812D738, gUnk_0812D728, 32, 0 },
    { gUnk_09EE9420, gUnk_09EE9424, gUnk_0904F450, 1, 0, gUnk_0984AF78, gUnk_0812D718, gUnk_0812D708, 32, 0 },
    { gUnk_09EE9428, gUnk_09EE942C, gUnk_0904F664, 1, 0, gUnk_096FB2A4, gUnk_0812D6F8, gUnk_0812D6E8, 96, 0 },
    { gUnk_09EE9430, gUnk_09EE9434, gUnk_0904F878, 1, 0, gUnk_09D69274, gUnk_0812D6D8, gUnk_0812D6C8, 256, 0 },
    { gUnk_09EE9438, gUnk_09EE943C, gUnk_0904FA8C, 1, 0, gUnk_09612598, gUnk_0812D6B8, gUnk_0812D6A8, 32, 0 },
    { gUnk_09EE9440, gUnk_09EE9444, gUnk_0904FCA0, 1, 0, gUnk_096125B8, gUnk_0812D698, gUnk_0812D688, 32, 0 },
    { gUnk_09EE9448, gUnk_09EE944C, gUnk_0904FEB4, 1, 0, gUnk_096125D8, gUnk_0812D678, gUnk_0812D668, 32, 0 },
    { gUnk_09EE9450, gUnk_09EE9458, gUnk_090500CA, 1, 0, gUnk_096125F8, gUnk_0812D658, gUnk_0812D648, 32, 0 },
    { gUnk_09EE945C, gUnk_09EE9460, gUnk_090502E0, 1, 0, gUnk_09612618, gUnk_0812D638, gUnk_0812D628, 32, 0 },
    { gUnk_09EE945C, gUnk_09EE9460, gUnk_090502E0, 1, 0, gUnk_09612638, gUnk_0812D638, gUnk_0812D614, 32, 0 },
    { gUnk_09EE945C, gUnk_09EE9460, gUnk_090502E0, 1, 0, gUnk_09612658, gUnk_0812D638, gUnk_0812D600, 32, 0 },
    { gUnk_09EE945C, gUnk_09EE9460, gUnk_090502E0, 1, 0, gUnk_09612678, gUnk_0812D638, gUnk_0812D5EC, 32, 0 },
    { gUnk_09EE945C, gUnk_09EE9460, gUnk_090502E0, 1, 0, gUnk_09612698, gUnk_0812D638, gUnk_0812D5D8, 32, 0 },
    { gUnk_09EE9464, gUnk_09EE9468, gUnk_090504F4, 1, 0, gUnk_096126B8, gUnk_0812D5C8, gUnk_0812D5B8, 32, 0 },
    { gUnk_09EE9464, gUnk_09EE9468, gUnk_090504F4, 1, 0, gUnk_096126D8, gUnk_0812D5C8, gUnk_0812D5A4, 32, 0 },
    { gUnk_09EE9464, gUnk_09EE9468, gUnk_090504F4, 1, 0, gUnk_096126F8, gUnk_0812D5C8, gUnk_0812D590, 32, 0 },
    { gUnk_09EE9464, gUnk_09EE9468, gUnk_090504F4, 1, 0, gUnk_09612718, gUnk_0812D5C8, gUnk_0812D57C, 32, 0 },
    { gUnk_09EE9464, gUnk_09EE9468, gUnk_090504F4, 1, 0, gUnk_09612738, gUnk_0812D5C8, gUnk_0812D568, 32, 0 },
    { gUnk_09EE946C, gUnk_09EE9470, gUnk_09050708, 1, 0, gUnk_09612758, gUnk_0812D558, gUnk_0812D548, 32, 0 },
    { gUnk_09EE946C, gUnk_09EE9470, gUnk_09050708, 1, 0, gUnk_09612778, gUnk_0812D558, gUnk_0812D534, 32, 0 },
    { gUnk_09EE946C, gUnk_09EE9470, gUnk_09050708, 1, 0, gUnk_09612798, gUnk_0812D558, gUnk_0812D520, 32, 0 },
    { gUnk_09EE946C, gUnk_09EE9470, gUnk_09050708, 1, 0, gUnk_096127B8, gUnk_0812D558, gUnk_0812D50C, 32, 0 },
    { gUnk_09EE946C, gUnk_09EE9470, gUnk_09050708, 1, 0, gUnk_096127D8, gUnk_0812D558, gUnk_0812D4F8, 32, 0 },
    { gUnk_09EE9474, gUnk_09EE9478, gUnk_0905091C, 1, 0, gUnk_096127F8, gUnk_0812D4E8, gUnk_0812D4D8, 32, 0 },
    { gUnk_09EE9474, gUnk_09EE9478, gUnk_0905091C, 1, 0, gUnk_09612818, gUnk_0812D4E8, gUnk_0812D4C4, 32, 0 },
    { gUnk_09EE9474, gUnk_09EE9478, gUnk_0905091C, 1, 0, gUnk_09612838, gUnk_0812D4E8, gUnk_0812D4B0, 32, 0 },
    { gUnk_09EE9474, gUnk_09EE9478, gUnk_0905091C, 1, 0, gUnk_09612858, gUnk_0812D4E8, gUnk_0812D49C, 32, 0 },
    { gUnk_09EE9474, gUnk_09EE9478, gUnk_0905091C, 1, 0, gUnk_09612878, gUnk_0812D4E8, gUnk_0812D488, 32, 0 },
    { gUnk_09EE947C, gUnk_09EE9480, gUnk_09050B30, 1, 0, gUnk_09612898, gUnk_0812D478, gUnk_0812D468, 32, 0 },
    { gUnk_09EE947C, gUnk_09EE9480, gUnk_09050B30, 1, 0, gUnk_096128B8, gUnk_0812D478, gUnk_0812D454, 32, 0 },
    { gUnk_09EE947C, gUnk_09EE9480, gUnk_09050B30, 1, 0, gUnk_096128D8, gUnk_0812D478, gUnk_0812D440, 32, 0 },
    { gUnk_09EE947C, gUnk_09EE9480, gUnk_09050B30, 1, 0, gUnk_096128F8, gUnk_0812D478, gUnk_0812D42C, 32, 0 },
    { gUnk_09EE947C, gUnk_09EE9480, gUnk_09050B30, 1, 0, gUnk_09612918, gUnk_0812D478, gUnk_0812D418, 32, 0 },
    { gUnk_09EE9484, gUnk_09EE9488, gUnk_09050D44, 1, 0, gUnk_09612938, gUnk_0812D408, gUnk_0812D3F8, 32, 0 },
    { gUnk_09EE9484, gUnk_09EE9488, gUnk_09050D44, 1, 0, gUnk_09612958, gUnk_0812D408, gUnk_0812D3E4, 32, 0 },
    { gUnk_09EE9484, gUnk_09EE9488, gUnk_09050D44, 1, 0, gUnk_09612978, gUnk_0812D408, gUnk_0812D3D0, 32, 0 },
    { gUnk_09EE9484, gUnk_09EE9488, gUnk_09050D44, 1, 0, gUnk_09612998, gUnk_0812D408, gUnk_0812D3BC, 32, 0 },
    { gUnk_09EE9484, gUnk_09EE9488, gUnk_09050D44, 1, 0, gUnk_096129B8, gUnk_0812D408, gUnk_0812D3A8, 32, 0 },
    { gUnk_09EE948C, gUnk_09EE9490, gUnk_09050F58, 1, 0, gUnk_096129D8, gUnk_0812D398, gUnk_0812D388, 32, 0 },
    { gUnk_09EE948C, gUnk_09EE9490, gUnk_09050F58, 1, 0, gUnk_096129F8, gUnk_0812D398, gUnk_0812D374, 32, 0 },
    { gUnk_09EE948C, gUnk_09EE9490, gUnk_09050F58, 1, 0, gUnk_09612A18, gUnk_0812D398, gUnk_0812D360, 32, 0 },
    { gUnk_09EE948C, gUnk_09EE9490, gUnk_09050F58, 1, 0, gUnk_09612A38, gUnk_0812D398, gUnk_0812D34C, 32, 0 },
    { gUnk_09EE948C, gUnk_09EE9490, gUnk_09050F58, 1, 0, gUnk_09612A58, gUnk_0812D398, gUnk_0812D338, 32, 0 },
    { gUnk_09EE9494, gUnk_09EE9498, gUnk_0905116C, 1, 0, gUnk_09612A78, gUnk_0812D328, gUnk_0812D318, 32, 0 },
    { gUnk_09EE9494, gUnk_09EE9498, gUnk_0905116C, 1, 0, gUnk_09612A98, gUnk_0812D328, gUnk_0812D304, 32, 0 },
    { gUnk_09EE9494, gUnk_09EE9498, gUnk_0905116C, 1, 0, gUnk_09612AB8, gUnk_0812D328, gUnk_0812D2F0, 32, 0 },
    { gUnk_09EE9494, gUnk_09EE9498, gUnk_0905116C, 1, 0, gUnk_09612AF8, gUnk_0812D328, gUnk_0812D2DC, 32, 0 },
    { gUnk_09EE9494, gUnk_09EE9498, gUnk_0905116C, 1, 0, gUnk_09612AD8, gUnk_0812D328, gUnk_0812D2C8, 32, 0 },
    { gUnk_09EE9694, gUnk_09EE9698, gUnk_0905986C, 1, 0, gUnk_09612BD8, gUnk_0812D2B4, gUnk_0812D2A0, 32, 0 },
    { gUnk_09EE969C, gUnk_09EE96A0, gUnk_09059A80, 1, 0, gUnk_09612BF8, gUnk_0812D28C, gUnk_0812D278, 32, 0 },
    { gUnk_09EE96A4, gUnk_09EE96A8, gUnk_09059C94, 1, 0, gUnk_09612C18, gUnk_0812D264, gUnk_0812D250, 32, 0 },
    { gUnk_09EE949C, gUnk_09EE94A0, gUnk_09051380, 1, 0, gUnk_09612B18, gUnk_0812D240, gUnk_0812D230, 32, 0 },
    { gUnk_09EE949C, gUnk_09EE94A0, gUnk_09051380, 1, 0, gUnk_09612B38, gUnk_0812D240, gUnk_0812D21C, 32, 0 },
    { gUnk_09EE949C, gUnk_09EE94A0, gUnk_09051380, 1, 0, gUnk_09612B58, gUnk_0812D240, gUnk_0812D208, 32, 0 },
    { gUnk_09EE949C, gUnk_09EE94A0, gUnk_09051380, 1, 0, gUnk_09612B78, gUnk_0812D240, gUnk_0812D1F4, 32, 0 },
    { gUnk_09EE949C, gUnk_09EE94A0, gUnk_09051380, 1, 0, gUnk_09612B98, gUnk_0812D240, gUnk_0812D1E0, 32, 0 },
    { gUnk_09EE9574, gUnk_09EE9578, gUnk_09054D9C, 1, 0, gUnk_09617CB8, gUnk_0812D1CC, gUnk_081289B8, 32, 0 },
    { gUnk_09EE957C, gUnk_09EE9580, gUnk_09054FB0, 1, 0, gUnk_09617C98, gUnk_0812D1B8, gUnk_08128A04, 32, 0 },
    { gUnk_09EE954C, gUnk_09EE9550, gUnk_09054338, 1, 0, gUnk_096120B8, gUnk_0812D1A4, gUnk_0812D190, 32, 0 },
    { gUnk_09EE9554, gUnk_09EE9558, gUnk_0905454C, 1, 0, gUnk_096120D8, gUnk_0812D17C, gUnk_0812D168, 32, 0 },
    { gUnk_09EE955C, gUnk_09EE9560, gUnk_09054760, 1, 0, gUnk_096120F8, gUnk_0812D154, gUnk_0812D140, 32, 0 },
    { gUnk_09EE9564, gUnk_09EE9568, gUnk_09054974, 1, 0, gUnk_09612118, gUnk_0812D12C, gUnk_0812D118, 32, 0 },
    { gUnk_09EE956C, gUnk_09EE9570, gUnk_09054B88, 1, 0, gUnk_09612138, gUnk_0812D104, gUnk_0812D0F0, 32, 0 },
    { gUnk_09EE9584, gUnk_09EE9588, gUnk_090551C4, 1, 0, gUnk_09612158, gUnk_0812D0DC, gUnk_0812D0C8, 32, 0 },
    { gUnk_09EE958C, gUnk_09EE9590, gUnk_090553D8, 1, 0, gUnk_09612178, gUnk_0812D0B4, gUnk_0812D0A0, 32, 0 },
    { gUnk_09EE9594, gUnk_09EE9598, gUnk_090555EC, 1, 0, gUnk_09612198, gUnk_0812D08C, gUnk_0812D078, 32, 0 },
    { gUnk_09EE959C, gUnk_09EE95A0, gUnk_09055800, 1, 0, gUnk_096121B8, gUnk_0812D064, gUnk_0812D050, 32, 0 },
    { gUnk_09EE95A4, gUnk_09EE95A8, gUnk_09055A14, 1, 0, gUnk_096121D8, gUnk_0812D03C, gUnk_0812D028, 32, 0 },
    { gUnk_09EE95AC, gUnk_09EE95B0, gUnk_09055C28, 1, 0, gUnk_096121F8, gUnk_0812D014, gUnk_0812D000, 32, 0 },
    { gUnk_09EE95BC, gUnk_09EE95C0, gUnk_09056050, 1, 0, gUnk_09612238, gUnk_0812CFEC, gUnk_0812CFD8, 32, 0 },
    { gUnk_09EE95C4, gUnk_09EE95C8, gUnk_09056264, 1, 0, gUnk_09612258, gUnk_0812CFC4, gUnk_0812CFB0, 32, 0 },
    { gUnk_09EE95CC, gUnk_09EE95D0, gUnk_09056478, 1, 0, gUnk_09612278, gUnk_0812CF9C, gUnk_0812CF88, 32, 0 },
    { gUnk_09EE95D4, gUnk_09EE95D8, gUnk_0905668C, 1, 0, gUnk_09612298, gUnk_0812CF74, gUnk_0812CF60, 32, 0 },
    { gUnk_09EE95DC, gUnk_09EE95E0, gUnk_090568A0, 1, 0, gUnk_096122B8, gUnk_0812CF4C, gUnk_0812CF38, 32, 0 },
    { gUnk_09EE95E4, gUnk_09EE95E8, gUnk_09056AB4, 1, 0, gUnk_096122D8, gUnk_0812CF24, gUnk_0812CF10, 32, 0 },
    { gUnk_09EE95EC, gUnk_09EE95F0, gUnk_09056CC8, 1, 0, gUnk_096122F8, gUnk_0812CEFC, gUnk_0812CEE8, 32, 0 },
    { gUnk_09EE95F4, gUnk_09EE95F8, gUnk_09056EDC, 1, 0, gUnk_09612318, gUnk_0812CED4, gUnk_0812CEC0, 32, 0 },
    { gUnk_09EE95FC, gUnk_09EE9600, gUnk_090570F0, 1, 0, gUnk_09612338, gUnk_0812CEAC, gUnk_0812CE98, 32, 0 },
    { gUnk_09EE9604, gUnk_09EE9608, gUnk_09057304, 1, 0, gUnk_09612358, gUnk_0812CE84, gUnk_0812CE70, 32, 0 },
    { gUnk_09EE960C, gUnk_09EE9610, gUnk_09057518, 1, 0, gUnk_09612378, gUnk_0812CE5C, gUnk_0812CE48, 32, 0 },
    { gUnk_09EE9614, gUnk_09EE9618, gUnk_0905772C, 1, 0, gUnk_09612398, gUnk_0812CE34, gUnk_0812CE20, 32, 0 },
    { gUnk_09EE961C, gUnk_09EE9620, gUnk_09057940, 1, 0, gUnk_096123B8, gUnk_0812CE0C, gUnk_0812CDF8, 32, 0 },
    { gUnk_09EE9624, gUnk_09EE9628, gUnk_09057B54, 1, 0, gUnk_096123D8, gUnk_0812CDE4, gUnk_0812CDD0, 32, 0 },
    { gUnk_09EE962C, gUnk_09EE9630, gUnk_09057D68, 1, 0, gUnk_096123F8, gUnk_0812CDBC, gUnk_0812CDA8, 32, 0 },
    { gUnk_09EE9634, gUnk_09EE9638, gUnk_09057F7C, 1, 0, gUnk_09612418, gUnk_0812CD94, gUnk_0812CD80, 32, 0 },
    { gUnk_09EE963C, gUnk_09EE9640, gUnk_09058190, 1, 0, gUnk_09612438, gUnk_0812CD6C, gUnk_0812CD58, 32, 0 },
    { gUnk_09EE9644, gUnk_09EE9648, gUnk_090583A4, 1, 0, gUnk_09612458, gUnk_0812CD44, gUnk_0812CD30, 32, 0 },
    { gUnk_09EE966C, gUnk_09EE9670, gUnk_09058E08, 1, 0, gUnk_096124F8, gUnk_0812CD1C, gUnk_0812CD08, 32, 0 },
    { gUnk_09EE9674, gUnk_09EE9678, gUnk_0905901C, 1, 0, gUnk_09612518, gUnk_0812CCF4, gUnk_0812CCE0, 32, 0 },
    { gUnk_09EE967C, gUnk_09EE9680, gUnk_09059230, 1, 0, gUnk_09612538, gUnk_0812CCCC, gUnk_0812CCB8, 32, 0 },
    { gUnk_09EE9684, gUnk_09EE9688, gUnk_09059444, 1, 0, gUnk_09612558, gUnk_0812CCA4, gUnk_0812CC90, 32, 0 },
    { gUnk_09EE968C, gUnk_09EE9690, gUnk_09059658, 1, 0, gUnk_09612578, gUnk_0812CC7C, gUnk_0812CC68, 32, 0 },
    { gUnk_09EE965C, gUnk_09EE9660, gUnk_090589E0, 1, 0, gUnk_096124B8, gUnk_0812CC54, gUnk_0812CC40, 32, 0 },
    { gUnk_09EE9664, gUnk_09EE9668, gUnk_09058BF4, 1, 0, gUnk_096124D8, gUnk_0812CC2C, gUnk_0812CC18, 32, 0 },
    { gUnk_09EE964C, gUnk_09EE9650, gUnk_090585B8, 1, 0, gUnk_09612478, gUnk_0812CC04, gUnk_0812CBF0, 32, 0 },
    { gUnk_09EE9654, gUnk_09EE9658, gUnk_090587CC, 1, 0, gUnk_09612498, gUnk_0812CBDC, gUnk_0812CBC8, 32, 0 },
    { gUnk_09EF0FA8, gUnk_09EF0FAC, gUnk_093EF068, 1, 0, gUnk_09618598, gUnk_0812CBB8, gUnk_0812CBA8, 32, 0 },
    { gUnk_09EF0FB0, gUnk_09EF0FB4, gUnk_093EF27C, 1, 0, gUnk_096185B8, gUnk_0812CB98, gUnk_0812CB88, 32, 0 },
    { gUnk_09EF0FB8, gUnk_09EF0FBC, gUnk_093EF490, 1, 0, gUnk_096185D8, gUnk_0812CB78, gUnk_0812CB68, 32, 0 },
    { gUnk_09EF0FC0, gUnk_09EF0FC4, gUnk_093EF6A4, 1, 0, gUnk_096185F8, gUnk_0812CB58, gUnk_0812CB48, 32, 0 },
    { gUnk_09EF0FC8, gUnk_09EF0FCC, gUnk_093EF8B8, 1, 0, gUnk_09618618, gUnk_0812CB38, gUnk_0812CB28, 32, 0 },
    { gUnk_09EF0FD0, gUnk_09EF0FD4, gUnk_093EFACC, 1, 0, gUnk_09618638, gUnk_0812CB18, gUnk_0812CB08, 32, 0 },
    { gUnk_09EF0FD8, gUnk_09EF0FDC, gUnk_093EFCE0, 1, 0, gUnk_09618658, gUnk_0812CAF8, gUnk_0812CAE8, 32, 0 },
    { gUnk_09EF0FE0, gUnk_09EF0FE4, gUnk_093EFEF4, 1, 0, gUnk_09618678, gUnk_0812CAD8, gUnk_0812CAC8, 32, 0 },
    { gUnk_09EF0FE8, gUnk_09EF0FEC, gUnk_093F0108, 1, 0, gUnk_09618698, gUnk_0812CAB8, gUnk_0812CAA8, 32, 0 },
    { gUnk_09EF0FF0, gUnk_09EF0FF4, gUnk_093F031C, 1, 0, gUnk_096186B8, gUnk_0812CA98, gUnk_0812CA88, 32, 0 },
    { gUnk_09EF0FF8, gUnk_09EF0FFC, gUnk_093F0530, 1, 0, gUnk_096186D8, gUnk_0812CA78, gUnk_0812CA68, 32, 0 },
    { gUnk_09EF1000, gUnk_09EF1004, gUnk_093F0744, 1, 0, gUnk_096186F8, gUnk_0812CA58, gUnk_0812CA48, 32, 0 },
    { gUnk_09EF1008, gUnk_09EF100C, gUnk_093F0958, 1, 0, gUnk_09618718, gUnk_0812CA38, gUnk_0812CA28, 32, 0 },
    { gUnk_09EF1010, gUnk_09EF1014, gUnk_093F0B6C, 1, 0, gUnk_09618738, gUnk_0812CA18, gUnk_0812CA08, 32, 0 },
    { gUnk_09EF1018, gUnk_09EF101C, gUnk_093F0D80, 1, 0, gUnk_09618758, gUnk_0812C9F8, gUnk_0812C9E8, 32, 0 },
    { gUnk_09EF1020, gUnk_09EF1024, gUnk_093F0F94, 1, 0, gUnk_09618778, gUnk_0812C9D8, gUnk_0812C9C8, 32, 0 },
    { gUnk_09EF1028, gUnk_09EF102C, gUnk_093F11A8, 1, 0, gUnk_09618798, gUnk_0812C9B8, gUnk_0812C9A8, 32, 0 },
    { gUnk_09EF1030, gUnk_09EF1034, gUnk_093F13BC, 1, 0, gUnk_096187B8, gUnk_0812C998, gUnk_0812C988, 32, 0 },
    { gUnk_09EF1038, gUnk_09EF103C, gUnk_093F15D0, 1, 0, gUnk_096187D8, gUnk_0812C978, gUnk_0812C968, 32, 0 },
    { gUnk_09EF1040, gUnk_09EF1044, gUnk_093F17E4, 1, 0, gUnk_096187F8, gUnk_0812C958, gUnk_0812C948, 32, 0 },
    { gUnk_09EF1048, gUnk_09EF104C, gUnk_093F19F8, 1, 0, gUnk_09618818, gUnk_0812C938, gUnk_0812C928, 32, 0 },
    { gUnk_09EF1050, gUnk_09EF1054, gUnk_093F1C0C, 1, 0, gUnk_09618838, gUnk_0812C918, gUnk_0812C908, 32, 0 },
    { gUnk_09EF1058, gUnk_09EF105C, gUnk_093F1E20, 1, 0, gUnk_09618858, gUnk_0812C8F8, gUnk_0812C8E8, 32, 0 },
    { gUnk_09EF1138, gUnk_09EF113C, gUnk_093F3E50, 1, 0, gUnk_09618BD8, gUnk_0812C8D8, gUnk_0812C8C8, 32, 0 },
    { gUnk_09EF1140, gUnk_09EF1144, gUnk_093F4064, 1, 0, gUnk_09618BF8, gUnk_0812C8B8, gUnk_0812C8A8, 32, 0 },
    { gUnk_09EF1148, gUnk_09EF114C, gUnk_093F4278, 1, 0, gUnk_09618C18, gUnk_0812C898, gUnk_0812C888, 32, 0 },
};

ObjDef gUnk_09ED76F4[] = {
    { gUnk_09EF681C, gUnk_09EF6820, gUnk_09799FB0, 1, 0, gUnk_0984AFB8, gUnk_0812DF24, gUnk_0812DF18, 32, 0 },
    { gUnk_09EF6824, gUnk_09EF6844, gUnk_0979A426, 1, 0, gUnk_0984AFB8, gUnk_0812DF08, gUnk_0812DF18, 32, 0 },
    { gUnk_09EF6848, gUnk_09EF684C, gUnk_0979C44E, 1, 0, gUnk_0984AFD8, gUnk_0812DEFC, gUnk_0812DEF0, 32, 0 },
    { gUnk_09EF67FC, gUnk_09EF680C, gUnk_09799CBA, 4, 0, gUnk_0984AF78, gUnk_0812DEE4, gUnk_0812D708, 32, 0 },
    { gUnk_09EE1244, gUnk_09EE1278, gUnk_08B209E0, 11, 0, gUnk_08F69BA4, gUnk_0812DED4, gUnk_08129AE8, 32, 0 },
#ifndef VERSION_EU
    { gUnk_09EE1420, gUnk_09EE1498, gUnk_08B24016, 15, 0, gUnk_08F69BA4, gUnk_0812DEC8, gUnk_08129AE8, 32, 0 },
    { gUnk_09EE14D4, gUnk_09EE150C, gUnk_08B24DAA, 5, 0, gUnk_08F69BA4, gUnk_0812DEB8, gUnk_08129AE8, 32, 0 },
#endif
};

ObjDef gUnk_09ED77D4[] = {
    { gUnk_09EF52C0, gUnk_09EF52EC, gUnk_096FEFBE, 1, 0, gUnk_09849A98, gUnk_0812E5E4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF52F0, gUnk_09EF531C, gUnk_097006F8, 1, 0, gUnk_09849A98, gUnk_0812E5D4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5320, gUnk_09EF534C, gUnk_09701FDA, 1, 0, gUnk_09849A98, gUnk_0812E5C4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5350, gUnk_09EF537C, gUnk_09703C44, 1, 0, gUnk_09849A98, gUnk_0812E5B4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5380, gUnk_09EF53AC, gUnk_097058D2, 1, 0, gUnk_09849A98, gUnk_0812E5A4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5410, gUnk_09EF543C, gUnk_0970AA98, 1, 0, gUnk_09849A98, gUnk_0812E594, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF53E0, gUnk_09EF540C, gUnk_09708E2E, 1, 0, gUnk_09849A98, gUnk_0812E584, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF53B0, gUnk_09EF53DC, gUnk_0970754C, 1, 0, gUnk_09849A98, gUnk_0812E574, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF59D8, gUnk_09EF59E8, gUnk_0972C694, 1, 0, gUnk_09849AD8, gUnk_0812E564, gUnk_0812E554, 32, 0 },
    { gUnk_09EF5A28, gUnk_09EF5A38, gUnk_0972E5A4, 1, 0, gUnk_09849AD8, gUnk_0812E544, gUnk_0812E554, 32, 0 },
    { gUnk_09EF5A3C, gUnk_09EF5A4C, gUnk_0972ED68, 1, 0, gUnk_09849AD8, gUnk_0812E534, gUnk_0812E554, 32, 0 },
    { gUnk_09EF5A00, gUnk_09EF5A10, gUnk_0972D61C, 1, 0, gUnk_09849AD8, gUnk_0812E524, gUnk_0812E554, 32, 0 },
    { gUnk_09EF59C4, gUnk_09EF59D4, gUnk_0972BED0, 1, 0, gUnk_09849AD8, gUnk_0812E514, gUnk_0812E554, 32, 0 },
    { gUnk_09EF59EC, gUnk_09EF59FC, gUnk_0972CE58, 1, 0, gUnk_09849AD8, gUnk_0812E504, gUnk_0812E554, 32, 0 },
    { gUnk_09EF5A50, gUnk_09EF5A60, gUnk_0972F52C, 1, 0, gUnk_09849AD8, gUnk_0812E4F4, gUnk_0812E554, 32, 0 },
    { gUnk_09EF5A14, gUnk_09EF5A24, gUnk_0972DDE0, 1, 0, gUnk_09849AD8, gUnk_0812E4E4, gUnk_0812E554, 32, 0 },
    { gUnk_09EF5A64, gUnk_09EF5A90, gUnk_0972FD80, 2, 0, gUnk_09849AF8, gUnk_0812E4D4, gUnk_0812E4C4, 32, 0 },
    { gUnk_09EF5A98, gUnk_09EF5A9C, gUnk_09732026, 1, 0, gUnk_09849B18, gUnk_0812E4B4, gUnk_0812E4A4, 32, 0 },
    { gUnk_09EF5AA0, gUnk_09EF5AB4, gUnk_09732272, 1, 0, gUnk_09849B38, gUnk_0812E494, gUnk_0812E484, 32, 0 },
    { gUnk_09EF5AB8, gUnk_09EF5ACC, gUnk_0973291E, 1, 0, gUnk_09849B38, gUnk_0812E474, gUnk_0812E484, 32, 0 },
    { gUnk_09EF5AD0, gUnk_09EF5AE0, gUnk_09732FB6, 1, 0, gUnk_09849B38, gUnk_0812E464, gUnk_0812E484, 32, 0 },
    { gUnk_09EF5458, gUnk_09EF545C, gUnk_0970CD86, 1, 0, gUnk_09849A98, gUnk_0812E450, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5448, gUnk_09EF544C, gUnk_0970C8CE, 1, 0, gUnk_09849A98, gUnk_0812E43C, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF52B8, gUnk_09EF52BC, gUnk_096FECD6, 1, 0, gUnk_09849A98, gUnk_0812E42C, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5450, gUnk_09EF5454, gUnk_0970CB2A, 1, 0, gUnk_09849A98, gUnk_0812E418, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5440, gUnk_09EF5444, gUnk_0970C672, 1, 0, gUnk_09849A98, gUnk_0812E404, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5470, gUnk_09EF5474, gUnk_0970D49A, 1, 0, gUnk_09849A98, gUnk_0812E3F0, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5460, gUnk_09EF5464, gUnk_0970CFE2, 1, 0, gUnk_09849A98, gUnk_0812E3DC, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF52B0, gUnk_09EF52B4, gUnk_096FEA7A, 1, 0, gUnk_09849A98, gUnk_0812E3CC, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5478, gUnk_09EF547C, gUnk_0970D6F6, 1, 0, gUnk_09849A98, gUnk_0812E3B8, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5468, gUnk_09EF546C, gUnk_0970D23E, 1, 0, gUnk_09849A98, gUnk_0812E3A4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54C0, gUnk_09EF54C4, gUnk_0970EC32, 1, 0, gUnk_09849A98, gUnk_0812E390, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54D8, gUnk_09EF54DC, gUnk_0970F2E6, 1, 0, gUnk_09849A98, gUnk_0812E37C, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF52A8, gUnk_09EF52AC, gUnk_096FE83E, 1, 0, gUnk_09849A98, gUnk_0812E36C, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54D0, gUnk_09EF54D4, gUnk_0970F0AA, 1, 0, gUnk_09849A98, gUnk_0812E358, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54C8, gUnk_09EF54CC, gUnk_0970EE6E, 1, 0, gUnk_09849A98, gUnk_0812E344, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54A8, gUnk_09EF54AC, gUnk_0970E51E, 1, 0, gUnk_09849A98, gUnk_0812E330, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54A0, gUnk_09EF54A4, gUnk_0970E2C2, 1, 0, gUnk_09849A98, gUnk_0812E31C, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF52A0, gUnk_09EF52A4, gUnk_096FE5E2, 1, 0, gUnk_09849A98, gUnk_0812E30C, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54B0, gUnk_09EF54B4, gUnk_0970E77A, 1, 0, gUnk_09849A98, gUnk_0812E2F8, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF54B8, gUnk_09EF54BC, gUnk_0970E9D6, 1, 0, gUnk_09849A98, gUnk_0812E2E4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5488, gUnk_09EF548C, gUnk_0970DBAE, 1, 0, gUnk_09849A98, gUnk_0812E2D0, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5490, gUnk_09EF5494, gUnk_0970DE0A, 1, 0, gUnk_09849A98, gUnk_0812E2BC, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5298, gUnk_09EF529C, gUnk_096FE386, 1, 0, gUnk_09849A98, gUnk_0812E2AC, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5480, gUnk_09EF5484, gUnk_0970D952, 1, 0, gUnk_09849A98, gUnk_0812E298, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5498, gUnk_09EF549C, gUnk_0970E066, 1, 0, gUnk_09849A98, gUnk_0812E284, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5D04, gUnk_09EF5D14, gUnk_0974431A, 1, 0, gUnk_09849C38, gUnk_0812E274, gUnk_0812E264, 32, 0 },
    { gUnk_09EF5D18, gUnk_09EF5D28, gUnk_0974441A, 1, 0, gUnk_09849C38, gUnk_0812E254, gUnk_0812E264, 32, 0 },
    { gUnk_09EF5D2C, gUnk_09EF5D3C, gUnk_097444DA, 1, 0, gUnk_09849C38, gUnk_0812E244, gUnk_0812E264, 32, 0 },
    { gUnk_09EF5D40, gUnk_09EF5D50, gUnk_0974459A, 1, 0, gUnk_09849C38, gUnk_0812E234, gUnk_0812E264, 32, 0 },
    { gUnk_09EF5D54, gUnk_09EF5D64, gUnk_0974465A, 1, 0, gUnk_09849C38, gUnk_0812E224, gUnk_0812E264, 32, 0 },
    { gUnk_09EF54E0, gUnk_09EF5508, gUnk_0970F5C4, 1, 0, gUnk_09849A98, gUnk_0812E214, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF55BC, gUnk_09EF55F4, gUnk_09716366, 1, 0, gUnk_09849A98, gUnk_0812E204, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF550C, gUnk_09EF5534, gUnk_09710CA0, 1, 0, gUnk_09849A98, gUnk_0812E1F4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF55F8, gUnk_09EF5630, gUnk_097179FA, 1, 0, gUnk_09849A98, gUnk_0812E1E4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5538, gUnk_09EF5560, gUnk_09712406, 1, 0, gUnk_09849A98, gUnk_0812E1D4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5634, gUnk_09EF5670, gUnk_09719286, 1, 0, gUnk_09849A98, gUnk_0812E1C4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5564, gUnk_09EF558C, gUnk_0971381C, 1, 0, gUnk_09849A98, gUnk_0812E1B4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5674, gUnk_09EF56B0, gUnk_0971AB32, 1, 0, gUnk_09849A98, gUnk_0812E1A4, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5590, gUnk_09EF55B8, gUnk_09714D3A, 1, 0, gUnk_09849A98, gUnk_0812E194, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF56B4, gUnk_09EF56F0, gUnk_0971C3F2, 1, 0, gUnk_09849A98, gUnk_0812E184, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5844, gUnk_09EF5904, gUnk_097257D8, 10, 0, gUnk_09849A98, gUnk_0812E174, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF592C, gUnk_09EF594C, gUnk_097293BE, 4, 0, gUnk_09849A98, gUnk_0812E164, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5B54, gUnk_09EF5B58, gUnk_0973700E, 1, 0, gUnk_09849BD8, gUnk_0812E154, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5B5C, gUnk_09EF5B80, gUnk_097373D6, 1, 0, gUnk_09849BD8, gUnk_0812E138, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5B84, gUnk_09EF5BA4, gUnk_0973900E, 2, 0, gUnk_09849BD8, gUnk_0812E128, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5BAC, gUnk_09EF5BCC, gUnk_0973AC64, 2, 0, gUnk_09849BD8, gUnk_0812E118, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5C08, gUnk_09EF5C34, gUnk_0973EB16, 3, 0, gUnk_09849BD8, gUnk_0812E104, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5C40, gUnk_09EF5C64, gUnk_09740DD8, 2, 0, gUnk_09849BD8, gUnk_0812E0F0, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5BD4, gUnk_09EF5BFC, gUnk_0973CBAA, 3, 0, gUnk_09849BD8, gUnk_0812E0E0, gUnk_0812E148, 32, 0 },
    { gUnk_09EF5EF8, gUnk_09EF5FA0, gUnk_09753154, 10, 0, gUnk_09849CF8, gUnk_0812E0D0, gUnk_0812E0C8, 32, 0 },
    { gUnk_09EF57A4, gUnk_09EF57C4, gUnk_097205C2, 1, 0, gUnk_09849A98, gUnk_0812E0B8, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF57C8, gUnk_09EF57E8, gUnk_0972186A, 1, 0, gUnk_09849A98, gUnk_0812E0A8, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF56F4, gUnk_09EF5744, gUnk_0971DD78, 2, 0, gUnk_09849A98, gUnk_0812E098, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF574C, gUnk_09EF579C, gUnk_0971F0F2, 2, 0, gUnk_09849A98, gUnk_0812E088, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF595C, gUnk_09EF59B0, gUnk_0972A136, 3, 0, gUnk_09849A98, gUnk_0812E078, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5DC4, gUnk_09EF5E24, gUnk_097471E2, 5, 0, gUnk_09849C78, gUnk_0812E068, gUnk_0812E060, 32, 0 },
    { gUnk_09EF5D68, gUnk_09EF5DA8, gUnk_097448BA, 7, 0, gUnk_09849C58, gUnk_0812E050, gUnk_0812E044, 32, 0 },
    { gUnk_09EF5FF0, gUnk_09EF5FF4, gUnk_09756810, 1, 0, gUnk_09849D78, gUnk_0812E030, gUnk_0812E01C, 32, 0 },
    { gUnk_09EF5FF8, gUnk_09EF6024, gUnk_09756ACE, 2, 0, gUnk_09849D98, gUnk_0812E010, gUnk_0812E004, 32, 0 },
    { gUnk_09EF5E48, gUnk_09EF5E98, gUnk_0974C196, 4, 0, gUnk_09849CB8, gUnk_0812DFF4, gUnk_0812DFE8, 64, 0 },
    { gUnk_09EF5EA8, gUnk_09EF5EE4, gUnk_0974FB26, 5, 0, gUnk_09849CB8, gUnk_0812DFD8, gUnk_0812DFE8, 64, 0 },
    { gUnk_09EF602C, gUnk_09EF6060, gUnk_09756E28, 6, 0, gUnk_09849DB8, gUnk_0812DFC4, gUnk_0812DFB0, 32, 0 },
    { gUnk_09EF6078, gUnk_09EF60AC, gUnk_09758C94, 6, 0, gUnk_09849DD8, gUnk_0812DFA0, gUnk_0812DF90, 32, 0 },
    { gUnk_09EF5AE4, gUnk_09EF5B1C, gUnk_097339E8, 4, 0, gUnk_09849B98, gUnk_0812DF80, gUnk_0812DF70, 64, 0 },
    { gUnk_09EF5808, gUnk_09EF5820, gUnk_09723C6A, 1, 0, gUnk_09849A98, gUnk_0812DF60, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF57EC, gUnk_09EF5804, gUnk_09722CEA, 1, 0, gUnk_09849A98, gUnk_0812DF50, gUnk_0812B9E0, 32, 0 },
    { gUnk_09EF5FC8, gUnk_09EF5FD0, gUnk_09755A34, 2, 0, gUnk_09849D18, gUnk_0812DF40, gUnk_0812DF30, 32, 0 },
};

ObjDef gUnk_09ED82D4[] = {
    { gUnk_09EDF374, gUnk_09EDF38C, gUnk_0891ED26, 1, 0, gUnk_09618118, gUnk_0812E734, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF390, gUnk_09EDF3A8, gUnk_089209A6, 2, 0, gUnk_09618118, gUnk_0812E724, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF3B0, gUnk_09EDF3C4, gUnk_08922670, 1, 0, gUnk_09618118, gUnk_0812E714, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF3C8, gUnk_09EDF3E4, gUnk_08923C74, 1, 0, gUnk_09618118, gUnk_0812E704, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF404, gUnk_09EDF418, gUnk_08927806, 4, 0, gUnk_09618118, gUnk_0812E6F4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF428, gUnk_09EDF464, gUnk_0892935E, 4, 0, gUnk_09618118, gUnk_0812E6E4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF474, gUnk_09EDF498, gUnk_0892E268, 2, 0, gUnk_09618118, gUnk_0812E6D4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF4A0, gUnk_09EDF4B8, gUnk_089315B4, 2, 0, gUnk_09618118, gUnk_0812E6C4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA70, gUnk_09EEFA90, gUnk_092FF906, 1, 0, gUnk_09618118, gUnk_0812B83C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF93C, gUnk_09EEF95C, gUnk_092F31E0, 1, 0, gUnk_09618118, gUnk_0812B82C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF994, gUnk_09EEF9B4, gUnk_092F65A2, 1, 0, gUnk_09618118, gUnk_0812B81C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEF9B8, gUnk_09EEF9D8, gUnk_092F881A, 1, 0, gUnk_09618118, gUnk_0812B80C, gUnk_0812B91C, 32, 0 },
    { gUnk_09EEFA4C, gUnk_09EEFA6C, gUnk_092FDDC6, 1, 0, gUnk_09618118, gUnk_0812B7FC, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF518, gUnk_09EDF530, gUnk_0893757C, 5, 0, gUnk_09618118, gUnk_0812E6B4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF570, gUnk_09EDF588, gUnk_08939F00, 5, 0, gUnk_09618118, gUnk_0812E6A4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF59C, gUnk_09EDF5B4, gUnk_0893B3D2, 5, 0, gUnk_09618118, gUnk_0812E694, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF5C8, gUnk_09EDF5E0, gUnk_0893C7C6, 5, 0, gUnk_09618118, gUnk_0812E684, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF544, gUnk_09EDF55C, gUnk_08938A14, 5, 0, gUnk_09618118, gUnk_0812E674, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF694, gUnk_09EDF6A8, gUnk_08943FFC, 1, 0, gUnk_09618118, gUnk_0812E664, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF6C4, gUnk_09EDF6D8, gUnk_08946552, 1, 0, gUnk_09618118, gUnk_0812E654, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF6DC, gUnk_09EDF6F0, gUnk_08947B36, 1, 0, gUnk_09618118, gUnk_0812E644, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF6AC, gUnk_09EDF6C0, gUnk_08945356, 1, 0, gUnk_09618118, gUnk_0812E634, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF6F4, gUnk_09EDF70C, gUnk_089492FC, 1, 0, gUnk_09618118, gUnk_0812E624, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF710, gUnk_09EDF728, gUnk_0894B386, 1, 0, gUnk_09618118, gUnk_0812E614, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF4A0, gUnk_09EDF4B8, gUnk_089315B4, 2, 0, gUnk_09618118, gUnk_0812E6C4, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF72C, gUnk_09EDF744, gUnk_0894CECA, 1, 0, gUnk_09618118, gUnk_0812E604, gUnk_0812B91C, 32, 0 },
    { gUnk_09EDF748, gUnk_09EDF760, gUnk_0894EC7C, 1, 0, gUnk_09618118, gUnk_0812E5F4, gUnk_0812B91C, 32, 0 },
};

Mode gModeChkobj = { gModeNameChkobj, (void (*)(s32))mode_chkobj_0, mode_chkobj_1, mode_chkobj_2 };
