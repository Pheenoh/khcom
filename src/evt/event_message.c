#include "macros.h"
#include "registration_data.h"
#include "eventselect_api.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "intr.h"
#include "m4a_song.h"
#include "obj_api.h"
#include "pallet.h"
#include "display.h"
#include "text.h"
#include "monsgage.h"
#include "anim.h"
#include "msg.h"
#include "sprites_deck_menu.h"
#include "sprites_evt.h"
#include "sprites_msg.h"
#include "sprites_card.h"
#include "msg_portrait_data.h"
#include "msg_portrait_assets.h"

extern const u16 gUnk_0951D2B8[1024];
extern const u16 gUnk_0951DAB8[1024];
extern const u16 gUnk_0951E2B8[1024];
extern const u16 gUnk_0951EAB8[1024];

#ifdef VERSION_EU
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];
#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif

const MsgFaceAnim gUnk_09032484[8] = {
    {
        gUnk_090D806A,
        gUnk_096149F8,
        gUnk_09EEC670,
        gUnk_09EEC698,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090D923A,
        gUnk_096149F8,
        gUnk_09EEC6A8,
        gUnk_09EEC6BC,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DA002,
        gUnk_096149F8,
        gUnk_09EEC6C4,
        gUnk_09EEC6D8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DAC90,
        gUnk_096149F8,
        gUnk_09EEC6E0,
        gUnk_09EEC6F4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DBAA0,
        gUnk_096149F8,
        gUnk_09EEC6FC,
        gUnk_09EEC708,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DC82A,
        gUnk_096149F8,
        gUnk_09EEC710,
        gUnk_09EEC730,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DC82A,
        gUnk_096149F8,
        gUnk_09EEC710,
        gUnk_09EEC730 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090D806A,
        gUnk_096149F8,
        gUnk_09EEC670,
        gUnk_09EEC698 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032524[6] = {
    {
        gUnk_090DDB7C,
        gUnk_09614A18,
        gUnk_09EEC740,
        gUnk_09EEC768,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DF972,
        gUnk_09614A18,
        gUnk_09EEC778,
        gUnk_09EEC7A0,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E1970,
        gUnk_09614A18,
        gUnk_09EEC7B0,
        gUnk_09EEC7D8,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E381E,
        gUnk_09614A18,
        gUnk_09EEC7E8,
        gUnk_09EEC810,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E5BF4,
        gUnk_09614A18,
        gUnk_09EEC820,
        gUnk_09EEC834,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E6DB2,
        gUnk_09614A18,
        gUnk_09EEC83C,
        gUnk_09EEC864,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903259C[5] = {
    {
        gUnk_090DDB7C,
        gUnk_09614CB8,
        gUnk_09EEC740,
        gUnk_09EEC768 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090DF972,
        gUnk_09614CB8,
        gUnk_09EEC778,
        gUnk_09EEC7A0 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E1970,
        gUnk_09614CB8,
        gUnk_09EEC7B0,
        gUnk_09EEC7D8 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E381E,
        gUnk_09614CB8,
        gUnk_09EEC7E8,
        gUnk_09EEC810 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090E6DB2,
        gUnk_09614CB8,
        gUnk_09EEC83C,
        gUnk_09EEC864 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032600[5] = {
    {
        gUnk_090E93DC,
        gUnk_09614A38,
        gUnk_09EEC874,
        gUnk_09EEC89C,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090EB8D6,
        gUnk_09614A38,
        gUnk_09EEC8AC,
        gUnk_09EEC8D4,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090EEAD6,
        gUnk_09614A38,
        gUnk_09EEC8E4,
        gUnk_09EEC90C,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090F0C52,
        gUnk_09614A38,
        gUnk_09EEC91C,
        gUnk_09EEC930,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090F1DC0,
        gUnk_09614A38,
        gUnk_09EEC938,
        gUnk_09EEC94C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032664[3] = {
    {
        gUnk_090E93DC,
        gUnk_09614CD8,
        gUnk_09EEC874,
        gUnk_09EEC89C + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090EB8D6,
        gUnk_09614CD8,
        gUnk_09EEC8AC,
        gUnk_09EEC8D4 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_090EEAD6,
        gUnk_09614CD8,
        gUnk_09EEC8E4,
        gUnk_09EEC90C + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090326A0 = {
    gUnk_090F355E,
    gUnk_09614A58,
    gUnk_09EEC954,
    gUnk_09EEC95C,
    2,
    1,
    { 0, 0 },
};

const MsgFaceAnim gUnk_090326B4[4] = {
    {
        gUnk_090F4176,
        gUnk_09614A78,
        gUnk_09EEC964,
        gUnk_09EEC978,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090F69AA,
        gUnk_09614A78,
        gUnk_09EEC980,
        gUnk_09EEC99C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090F8522,
        gUnk_09614A78,
        gUnk_09EEC9A4,
        gUnk_09EEC9B8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FA1DA,
        gUnk_09614A78,
        gUnk_09EEC9C0,
        gUnk_09EEC9D4,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032704[4] = {
    {
        gUnk_090FC130,
        gUnk_09614A98,
        gUnk_09EEC9DC,
        gUnk_09EECA24,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FC130,
        gUnk_09614A98,
        gUnk_09EEC9DC,
        gUnk_09EECA24 + 2,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FC130,
        gUnk_09614A98,
        gUnk_09EEC9DC,
        gUnk_09EECA24 + 4,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FC130,
        gUnk_09614A98,
        gUnk_09EEC9DC,
        gUnk_09EECA24 + 6,
        8,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032754[5] = {
    {
        gUnk_090FDBF4,
        gUnk_09614AB8,
        gUnk_09EECA44,
        gUnk_09EECAA0,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FDBF4,
        gUnk_09614AB8,
        gUnk_09EECA44,
        gUnk_09EECAA0 + 2,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FDBF4,
        gUnk_09614AB8,
        gUnk_09EECA44,
        gUnk_09EECAA0 + 4,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FDBF4,
        gUnk_09614AB8,
        gUnk_09EECA44,
        gUnk_09EECAA0 + 6,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_090FDBF4,
        gUnk_09614AB8,
        gUnk_09EECA44,
        gUnk_09EECAA0 + 8,
        10,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090327B8 = {
    gUnk_09100820,
    gUnk_09614AD8,
    gUnk_09EECAC8,
    gUnk_09EECAD0,
    2,
    1,
    { 0, 0 },
};

const MsgFaceAnim gUnk_090327CC[2] = {
    {
        gUnk_0910150E,
        gUnk_09614AF8,
        gUnk_09EECAD8,
        gUnk_09EECB00,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0910150E,
        gUnk_09614AF8,
        gUnk_09EECAD8,
        gUnk_09EECB00 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090327F4[2] = {
    {
        gUnk_09102A5E,
        gUnk_09614B18,
        gUnk_09EECB10,
        gUnk_09EECB28,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09102A5E,
        gUnk_09614B18,
        gUnk_09EECB10,
        gUnk_09EECB28 + 1,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903281C[15] = {
    {
        gUnk_09104D42,
        gUnk_09614B38,
        gUnk_09EECB30,
        gUnk_09EECB84,
        12,
        1,
        { 0, 0 },
    },
    {
        gUnk_09104D42,
        gUnk_09614B38,
        gUnk_09EECB30,
        gUnk_09EECB84 + 2,
        12,
        1,
        { 0, 0 },
    },
    {
        gUnk_09104D42,
        gUnk_09614B38,
        gUnk_09EECB30,
        gUnk_09EECB84 + 4,
        12,
        1,
        { 0, 0 },
    },
    {
        gUnk_09104D42,
        gUnk_09614B38,
        gUnk_09EECB30,
        gUnk_09EECB84 + 6,
        12,
        1,
        { 0, 0 },
    },
    {
        gUnk_09104D42,
        gUnk_09614B38,
        gUnk_09EECB30,
        gUnk_09EECB84 + 8,
        12,
        1,
        { 0, 0 },
    },
    {
        gUnk_09104D42,
        gUnk_09614B38,
        gUnk_09EECB30,
        gUnk_09EECB84 + 10,
        12,
        1,
        { 0, 0 },
    },
    {
        gUnk_09105E38,
        gUnk_09614B38,
        gUnk_09EECBB4,
        gUnk_09EECBF0,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09105E38,
        gUnk_09614B38,
        gUnk_09EECBB4,
        gUnk_09EECBF0 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09105E38,
        gUnk_09614B38,
        gUnk_09EECBB4,
        gUnk_09EECBF0 + 4,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09106E0A,
        gUnk_09614B38,
        gUnk_09EECC08,
        gUnk_09EECC44,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09106E0A,
        gUnk_09614B38,
        gUnk_09EECC08,
        gUnk_09EECC44 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09106E0A,
        gUnk_09614B38,
        gUnk_09EECC08,
        gUnk_09EECC44 + 4,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09107DA0,
        gUnk_09614B38,
        gUnk_09EECC5C,
        gUnk_09EECC98,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09107DA0,
        gUnk_09614B38,
        gUnk_09EECC5C,
        gUnk_09EECC98 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09107DA0,
        gUnk_09614B38,
        gUnk_09EECC5C,
        gUnk_09EECC98 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032948[5] = {
    {
        gUnk_09108B24,
        gUnk_09614B58,
        gUnk_09EECCB0,
        gUnk_09EECCBC,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0910980C,
        gUnk_09614B58,
        gUnk_09EECCC4,
        gUnk_09EECCD0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0910A636,
        gUnk_09614B58,
        gUnk_09EECCD8,
        gUnk_09EECCE4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0910B540,
        gUnk_09614B58,
        gUnk_09EECCEC,
        gUnk_09EECCF8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0910C214,
        gUnk_09614B58,
        gUnk_09EECD00,
        gUnk_09EECD0C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090329AC[4] = {
    {
        gUnk_0910D0D6,
        gUnk_09614B78,
        gUnk_09EECD14,
        gUnk_09EECD28,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0910F63A,
        gUnk_09614B78,
        gUnk_09EECD30,
        gUnk_09EECD44,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09111B54,
        gUnk_09614B78,
        gUnk_09EECD4C,
        gUnk_09EECD60,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09113E16,
        gUnk_09614B78,
        gUnk_09EECD68,
        gUnk_09EECD7C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090329FC[6] = {
    {
        gUnk_09116698,
        gUnk_09614B98,
        gUnk_09EECD84,
        gUnk_09EECDCC,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09116698,
        gUnk_09614B98,
        gUnk_09EECD84,
        gUnk_09EECDCC + 2,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09116698,
        gUnk_09614B98,
        gUnk_09EECD84,
        gUnk_09EECDCC + 4,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09116698,
        gUnk_09614B98,
        gUnk_09EECD84,
        gUnk_09EECDCC + 6,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_091183C6,
        gUnk_09614B98,
        gUnk_09EECDEC,
        gUnk_09EECE14,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_091183C6,
        gUnk_09614B98,
        gUnk_09EECDEC,
        gUnk_09EECE14 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032A74[3] = {
    {
        gUnk_09119238,
        gUnk_09614BB8,
        gUnk_09EECE24,
        gUnk_09EECE38,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0911A380,
        gUnk_09614BB8,
        gUnk_09EECE40,
        gUnk_09EECE54,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0911BC8C,
        gUnk_09614BB8,
        gUnk_09EECE5C,
        gUnk_09EECE70,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032AB0[5] = {
    {
        gUnk_0911D7D0,
        gUnk_09614BD8,
        gUnk_09EECE78,
        gUnk_09EECEB4,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0911D7D0,
        gUnk_09614BD8,
        gUnk_09EECE78,
        gUnk_09EECEB4 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0911E908,
        gUnk_09614BD8,
        gUnk_09EECECC,
        gUnk_09EECEE0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0911F500,
        gUnk_09614BD8,
        gUnk_09EECEE8,
        gUnk_09EECEFC,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0911D7D0,
        gUnk_09614BD8,
        gUnk_09EECE78,
        gUnk_09EECEB4 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032B14[4] = {
    {
        gUnk_09120572,
        gUnk_09614BF8,
        gUnk_09EECF04,
        gUnk_09EECF54,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09120572,
        gUnk_09614BF8,
        gUnk_09EECF04,
        gUnk_09EECF54 + 2,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09120572,
        gUnk_09614BF8,
        gUnk_09EECF04,
        gUnk_09EECF54 + 4,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09120572,
        gUnk_09614BF8,
        gUnk_09EECF04,
        gUnk_09EECF54 + 6,
        8,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032B64[3] = {
    {
        gUnk_09122BB8,
        gUnk_09614C18,
        gUnk_09EECF74,
        gUnk_09EECFA8,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09122BB8,
        gUnk_09614C18,
        gUnk_09EECF74,
        gUnk_09EECFA8 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09122BB8,
        gUnk_09614C18,
        gUnk_09EECF74,
        gUnk_09EECFA8 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032BA0[3] = {
    {
        gUnk_09123D24,
        gUnk_09614C38,
        gUnk_09EECFC0,
        gUnk_09EECFFC,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09123D24,
        gUnk_09614C38,
        gUnk_09EECFC0,
        gUnk_09EECFFC + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09123D24,
        gUnk_09614C38,
        gUnk_09EECFC0,
        gUnk_09EECFFC + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032BDC[3] = {
    {
        gUnk_09125D3A,
        gUnk_09614C58,
        gUnk_09EED014,
        gUnk_09EED038,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09125D3A,
        gUnk_09614C58,
        gUnk_09EED014,
        gUnk_09EED038 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09125D3A,
        gUnk_09614C58,
        gUnk_09EED014,
        gUnk_09EED038 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032C18[4] = {
    {
        gUnk_09127738,
        gUnk_09614C78,
        gUnk_09EED050,
        gUnk_09EED064,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0912864E,
        gUnk_09614C78,
        gUnk_09EED06C,
        gUnk_09EED080,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0912930A,
        gUnk_09614C78,
        gUnk_09EED088,
        gUnk_09EED09C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0912A122,
        gUnk_09614C78,
        gUnk_09EED0A4,
        gUnk_09EED0B8,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032C68[5] = {
    {
        gUnk_0912AE36,
        gUnk_09614C98,
        gUnk_09EED0C0,
        gUnk_09EED0D4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0912CC3E,
        gUnk_09614C98,
        gUnk_09EED0DC,
        gUnk_09EED0F0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0912EA68,
        gUnk_09614C98,
        gUnk_09EED0F8,
        gUnk_09EED10C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09130B36,
        gUnk_09614C98,
        gUnk_09EED114,
        gUnk_09EED120,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09132AF4,
        gUnk_09614C98,
        gUnk_09EED128,
        gUnk_09EED13C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032CCC = {
    gUnk_0915A48C,
    gUnk_09614E78,
    gUnk_09EED6A8,
    gUnk_09EED6BC,
    2,
    1,
    { 0, 0 },
};

const MsgFaceAnim gUnk_09032CE0[2] = {
    {
        gUnk_0915B290,
        gUnk_09614E98,
        gUnk_09EED6C4,
        gUnk_09EED6EC,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915B290,
        gUnk_09614E98,
        gUnk_09EED6C4,
        gUnk_09EED6EC + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032D08[6] = {
    {
        gUnk_091348F0,
        gUnk_09614CF8,
        gUnk_09EED144,
        gUnk_09EED158,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091354EC,
        gUnk_09614CF8,
        gUnk_09EED160,
        gUnk_09EED174,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09136068,
        gUnk_09614CF8,
        gUnk_09EED17C,
        gUnk_09EED190,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09136CA4,
        gUnk_09614CF8,
        gUnk_09EED198,
        gUnk_09EED1AC,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09137888,
        gUnk_09614CF8,
        gUnk_09EED1B4,
        gUnk_09EED1C0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09138384,
        gUnk_09614CF8,
        gUnk_09EED1C8,
        gUnk_09EED1DC,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032D80[6] = {
    {
        gUnk_09138FDE,
        gUnk_09614D18,
        gUnk_09EED1E4,
        gUnk_09EED1F8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09139BDA,
        gUnk_09614D18,
        gUnk_09EED200,
        gUnk_09EED214,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913A7D6,
        gUnk_09614D18,
        gUnk_09EED21C,
        gUnk_09EED230,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913B3D2,
        gUnk_09614D18,
        gUnk_09EED238,
        gUnk_09EED24C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913BFCE,
        gUnk_09614D18,
        gUnk_09EED254,
        gUnk_09EED268,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913CBCA,
        gUnk_09614D18,
        gUnk_09EED270,
        gUnk_09EED284,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032DF8[2] = {
    {
        gUnk_0913D796,
        gUnk_09614D38,
        gUnk_09EED28C,
        gUnk_09EED2A0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913E1EA,
        gUnk_09614D38,
        gUnk_09EED2A8,
        gUnk_09EED2B4,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032E20[4] = {
    {
        gUnk_0914A5AC,
        gUnk_09614DB8,
        gUnk_09EED464,
        gUnk_09EED478,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914B292,
        gUnk_09614DB8,
        gUnk_09EED480,
        gUnk_09EED494,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914BEE6,
        gUnk_09614DB8,
        gUnk_09EED49C,
        gUnk_09EED4B0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914CB9C,
        gUnk_09614DB8,
        gUnk_09EED4B8,
        gUnk_09EED4CC,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032E70[4] = {
    {
        gUnk_0914D870,
        gUnk_09614DD8,
        gUnk_09EED4D4,
        gUnk_09EED4E8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914E544,
        gUnk_09614DD8,
        gUnk_09EED4F0,
        gUnk_09EED504,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914F218,
        gUnk_09614DD8,
        gUnk_09EED50C,
        gUnk_09EED520,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914FEEC,
        gUnk_09614DD8,
        gUnk_09EED528,
        gUnk_09EED53C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032EC0[6] = {
    {
        gUnk_0915362A,
        gUnk_09614E18,
        gUnk_09EED598,
        gUnk_09EED5B8,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09154234,
        gUnk_09614E18,
        gUnk_09EED5C8,
        gUnk_09EED5DC,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09154E3C,
        gUnk_09614E18,
        gUnk_09EED5E4,
        gUnk_09EED5F8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09155A44,
        gUnk_09614E18,
        gUnk_09EED600,
        gUnk_09EED614,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915664C,
        gUnk_09614E18,
        gUnk_09EED61C,
        gUnk_09EED630,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915362A,
        gUnk_09614E18,
        gUnk_09EED598,
        gUnk_09EED5B8 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032F38[5] = {
    {
        gUnk_0915CCF8,
        gUnk_09614EB8,
        gUnk_09EED6FC,
        gUnk_09EED730,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915CCF8,
        gUnk_09614EB8,
        gUnk_09EED6FC,
        gUnk_09EED730 + 4,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915E942,
        gUnk_09614EB8,
        gUnk_09EED748,
        gUnk_09EED75C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915F78A,
        gUnk_09614EB8,
        gUnk_09EED764,
        gUnk_09EED778,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0915CCF8,
        gUnk_09614EB8,
        gUnk_09EED6FC,
        gUnk_09EED730 + 2,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032F9C[4] = {
    {
        gUnk_09163C18,
        gUnk_09614EF8,
        gUnk_09EED800,
        gUnk_09EED814,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09164CE6,
        gUnk_09614EF8,
        gUnk_09EED81C,
        gUnk_09EED830,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09165FC8,
        gUnk_09614EF8,
        gUnk_09EED838,
        gUnk_09EED84C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09167104,
        gUnk_09614EF8,
        gUnk_09EED854,
        gUnk_09EED868,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09032FEC[4] = {
    {
        gUnk_091684B0,
        gUnk_09614F18,
        gUnk_09EED870,
        gUnk_09EED898,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09169596,
        gUnk_09614F18,
        gUnk_09EED8A8,
        gUnk_09EED8D0,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09169596,
        gUnk_09614F18,
        gUnk_09EED8A8,
        gUnk_09EED8D0 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_091684B0,
        gUnk_09614F18,
        gUnk_09EED870,
        gUnk_09EED898 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903303C[3] = {
    {
        gUnk_0916B056,
        gUnk_09614F38,
        gUnk_09EED8E0,
        gUnk_09EED91C,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0916B056,
        gUnk_09614F38,
        gUnk_09EED8E0,
        gUnk_09EED91C + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0916B056,
        gUnk_09614F38,
        gUnk_09EED8E0,
        gUnk_09EED91C + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033078[3] = {
    {
        gUnk_0916CD7C,
        gUnk_09614F58,
        gUnk_09EED934,
        gUnk_09EED970,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0916CD7C,
        gUnk_09614F58,
        gUnk_09EED934,
        gUnk_09EED970 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0916CD7C,
        gUnk_09614F58,
        gUnk_09EED934,
        gUnk_09EED970 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090330B4[2] = {
    {
        gUnk_0916E20A,
        gUnk_09614F78,
        gUnk_09EED988,
        gUnk_09EED9B0,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0916E20A,
        gUnk_09614F78,
        gUnk_09EED988,
        gUnk_09EED9B0 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090330DC[2] = {
    {
        gUnk_0916FE52,
        gUnk_09614F98,
        gUnk_09EED9C0,
        gUnk_09EED9E8,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0916FE52,
        gUnk_09614F98,
        gUnk_09EED9C0,
        gUnk_09EED9E8 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033104[3] = {
    {
        gUnk_09170ED0,
        gUnk_09614FB8,
        gUnk_09EED9F8,
        gUnk_09EEDA2C,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09170ED0,
        gUnk_09614FB8,
        gUnk_09EED9F8,
        gUnk_09EEDA2C + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_09170ED0,
        gUnk_09614FB8,
        gUnk_09EED9F8,
        gUnk_09EEDA2C + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033140[3] = {
    {
        gUnk_091728BC,
        gUnk_09614FD8,
        gUnk_09EEDA44,
        gUnk_09EEDA78,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_091728BC,
        gUnk_09614FD8,
        gUnk_09EEDA44,
        gUnk_09EEDA78 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_091728BC,
        gUnk_09614FD8,
        gUnk_09EEDA44,
        gUnk_09EEDA78 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903317C[4] = {
    {
        gUnk_0917D0D0,
        gUnk_09615038,
        gUnk_09EEDB9C,
        gUnk_09EEDBB0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917E348,
        gUnk_09615038,
        gUnk_09EEDBB8,
        gUnk_09EEDBE0,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917F7A6,
        gUnk_09615038,
        gUnk_09EEDBF0,
        gUnk_09EEDC04,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917E348,
        gUnk_09615058,
        gUnk_09EEDBB8,
        gUnk_09EEDBE0 + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090331CC[3] = {
    {
        gUnk_091808CE,
        gUnk_09615078,
        gUnk_09EEDC0C,
        gUnk_09EEDC34,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_091808CE,
        gUnk_09615078,
        gUnk_09EEDC0C,
        gUnk_09EEDC34 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09181626,
        gUnk_09615078,
        gUnk_09EEDC44,
        gUnk_09EEDC50,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033208[4] = {
    {
        gUnk_0918D538,
        gUnk_096150F8,
        gUnk_09EEDDC4,
        gUnk_09EEDDE4,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0918D538,
        gUnk_096150F8,
        gUnk_09EEDDC4,
        gUnk_09EEDDE4 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0918E2B6,
        gUnk_096150F8,
        gUnk_09EEDDF4,
        gUnk_09EEDE00,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0918EE36,
        gUnk_096150F8,
        gUnk_09EEDE08,
        gUnk_09EEDE1C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033258[4] = {
    {
        gUnk_09160A9E,
        gUnk_09614ED8,
        gUnk_09EED780,
        gUnk_09EED7C8,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09160A9E,
        gUnk_09614ED8,
        gUnk_09EED780,
        gUnk_09EED7C8 + 2,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09160A9E,
        gUnk_09614ED8,
        gUnk_09EED780,
        gUnk_09EED7C8 + 4,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_09160A9E,
        gUnk_09614ED8,
        gUnk_09EED780,
        gUnk_09EED7C8 + 6,
        8,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090332A8[5] = {
    {
        gUnk_0918218C,
        gUnk_09615098,
        gUnk_09EEDC58,
        gUnk_09EEDC6C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09182EFC,
        gUnk_09615098,
        gUnk_09EEDC74,
        gUnk_09EEDC88,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09183C6C,
        gUnk_09615098,
        gUnk_09EEDC90,
        gUnk_09EEDCA4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091849E2,
        gUnk_09615098,
        gUnk_09EEDCAC,
        gUnk_09EEDCC0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09185AF4,
        gUnk_09615098,
        gUnk_09EEDCC8,
        gUnk_09EEDCDC,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903330C[3] = {
    {
        gUnk_0918A6DA,
        gUnk_096150D8,
        gUnk_09EEDD70,
        gUnk_09EEDD84,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0918B5B4,
        gUnk_096150D8,
        gUnk_09EEDD8C,
        gUnk_09EEDDA0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0918C55E,
        gUnk_096150D8,
        gUnk_09EEDDA8,
        gUnk_09EEDDBC,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033348[4] = {
    {
        gUnk_0917895E,
        gUnk_09615018,
        gUnk_09EEDB1C,
        gUnk_09EEDB64,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917895E,
        gUnk_09615018,
        gUnk_09EEDB1C,
        gUnk_09EEDB64 + 2,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917895E,
        gUnk_09615018,
        gUnk_09EEDB1C,
        gUnk_09EEDB64 + 4,
        8,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917895E,
        gUnk_09615018,
        gUnk_09EEDB1C,
        gUnk_09EEDB64 + 6,
        8,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033398[5] = {
    {
        gUnk_091743FC,
        gUnk_09614FF8,
        gUnk_09EEDA90,
        gUnk_09EEDAA4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0917513A,
        gUnk_09614FF8,
        gUnk_09EEDAAC,
        gUnk_09EEDAC0,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09175E7A,
        gUnk_09614FF8,
        gUnk_09EEDAC8,
        gUnk_09EEDADC,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09176B90,
        gUnk_09614FF8,
        gUnk_09EEDAE4,
        gUnk_09EEDAF8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091779F0,
        gUnk_09614FF8,
        gUnk_09EEDB00,
        gUnk_09EEDB14,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090333FC[3] = {
    {
        gUnk_0918FB92,
        gUnk_09615118,
        gUnk_09EEDE24,
        gUnk_09EEDE4C,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_0918FB92,
        gUnk_09615118,
        gUnk_09EEDE24,
        gUnk_09EEDE4C + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09190A10,
        gUnk_09615118,
        gUnk_09EEDE5C,
        gUnk_09EEDE70,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033438[2] = {
    {
        gUnk_09193326,
        gUnk_09615158,
        gUnk_09EEDEBC,
        gUnk_09EEDEDC,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09193326,
        gUnk_09615158,
        gUnk_09EEDEBC,
        gUnk_09EEDEDC + 2,
        4,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033460[3] = {
    {
        gUnk_091942A4,
        gUnk_09615178,
        gUnk_09EEDEEC,
        gUnk_09EEDF28,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_091942A4,
        gUnk_09615178,
        gUnk_09EEDEEC,
        gUnk_09EEDF28 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_091942A4,
        gUnk_09615178,
        gUnk_09EEDEEC,
        gUnk_09EEDF28 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903349C = {
    gUnk_09195750,
    gUnk_09615198,
    gUnk_09EEDF40,
    gUnk_09EEDF54,
    2,
    1,
    { 0, 0 },
};

const MsgFaceAnim gUnk_090334B0[3] = {
    {
        gUnk_0919632C,
        gUnk_096151B8,
        gUnk_09EEDF5C,
        gUnk_09EEDF90,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0919632C,
        gUnk_096151B8,
        gUnk_09EEDF5C,
        gUnk_09EEDF90 + 2,
        6,
        1,
        { 0, 0 },
    },
    {
        gUnk_0919632C,
        gUnk_096151B8,
        gUnk_09EEDF5C,
        gUnk_09EEDF90 + 4,
        6,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090334EC = {
    gUnk_09157254,
    gUnk_09614E38,
    gUnk_09EED638,
    gUnk_09EED64C,
    2,
    1,
    { 0, 0 },
};

const MsgFaceAnim gUnk_09033500[3] = {
    {
        gUnk_09157E86,
        gUnk_09614E58,
        gUnk_09EED654,
        gUnk_09EED668,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09158B5A,
        gUnk_09614E58,
        gUnk_09EED670,
        gUnk_09EED684,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09159810,
        gUnk_09614E58,
        gUnk_09EED68C,
        gUnk_09EED6A0,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903353C[5] = {
    {
        gUnk_0918689C,
        gUnk_096150B8,
        gUnk_09EEDCE4,
        gUnk_09EEDCF8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091875F0,
        gUnk_096150B8,
        gUnk_09EEDD00,
        gUnk_09EEDD14,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09188204,
        gUnk_096150B8,
        gUnk_09EEDD1C,
        gUnk_09EEDD30,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09188E18,
        gUnk_096150B8,
        gUnk_09EEDD38,
        gUnk_09EEDD4C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09189A4A,
        gUnk_096150B8,
        gUnk_09EEDD54,
        gUnk_09EEDD68,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090335A0[5] = {
    {
        gUnk_09146C84,
        gUnk_09614D98,
        gUnk_09EED3E0,
        gUnk_09EED3F4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091477CE,
        gUnk_09614D98,
        gUnk_09EED3FC,
        gUnk_09EED410,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09148322,
        gUnk_09614D98,
        gUnk_09EED418,
        gUnk_09EED424,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09148E2C,
        gUnk_09614D98,
        gUnk_09EED42C,
        gUnk_09EED440,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09149A16,
        gUnk_09614D98,
        gUnk_09EED448,
        gUnk_09EED45C,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_09033604[6] = {
    {
        gUnk_09142D0E,
        gUnk_09614D78,
        gUnk_09EED348,
        gUnk_09EED35C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091437A2,
        gUnk_09614D78,
        gUnk_09EED364,
        gUnk_09EED370,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091441CE,
        gUnk_09614D78,
        gUnk_09EED378,
        gUnk_09EED38C,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09144CBA,
        gUnk_09614D78,
        gUnk_09EED394,
        gUnk_09EED3A8,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091457A6,
        gUnk_09614D78,
        gUnk_09EED3B0,
        gUnk_09EED3C4,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_0914623A,
        gUnk_09614D78,
        gUnk_09EED3CC,
        gUnk_09EED3D8,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_0903367C[3] = {
    {
        gUnk_09150BD2,
        gUnk_09614DF8,
        gUnk_09EED544,
        gUnk_09EED558,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_091519DA,
        gUnk_09614DF8,
        gUnk_09EED560,
        gUnk_09EED574,
        2,
        1,
        { 0, 0 },
    },
    {
        gUnk_09152800,
        gUnk_09614DF8,
        gUnk_09EED57C,
        gUnk_09EED590,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090336B8[3] = {
    {
        gUnk_091915E8,
        gUnk_09615138,
        gUnk_09EEDE78,
        gUnk_09EEDE98,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_091915E8,
        gUnk_09615138,
        gUnk_09EEDE78,
        gUnk_09EEDE98 + 2,
        4,
        1,
        { 0, 0 },
    },
    {
        gUnk_09192446,
        gUnk_09615138,
        gUnk_09EEDEA8,
        gUnk_09EEDEB4,
        2,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim gUnk_090336F4[5] = {
    {
        gUnk_0913F0C2,
        gUnk_09614D58,
        gUnk_09EED2BC,
        gUnk_09EED320,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913F0C2,
        gUnk_09614D58,
        gUnk_09EED2BC,
        gUnk_09EED320 + 2,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913F0C2,
        gUnk_09614D58,
        gUnk_09EED2BC,
        gUnk_09EED320 + 4,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913F0C2,
        gUnk_09614D58,
        gUnk_09EED2BC,
        gUnk_09EED320 + 6,
        10,
        1,
        { 0, 0 },
    },
    {
        gUnk_0913F0C2,
        gUnk_09614D58,
        gUnk_09EED2BC,
        gUnk_09EED320 + 8,
        10,
        1,
        { 0, 0 },
    },
};

const MsgFaceAnim* gMsgFaceAnims[62] = {
    gUnk_09032484,
    gUnk_09032524,
    gUnk_09032600,
    &gUnk_090326A0,
    gUnk_090326B4,
    gUnk_09032704,
    gUnk_09032754,
    &gUnk_090327B8,
    gUnk_090327CC,
    gUnk_090327F4,
    gUnk_0903281C,
    gUnk_09032948,
    gUnk_090329AC,
    gUnk_090329FC,
    gUnk_09032A74,
    gUnk_09032AB0,
    gUnk_09032B14,
    gUnk_09032B64,
    gUnk_09032BA0,
    gUnk_09032BDC,
    gUnk_09032C18,
    gUnk_09032C68,
    &gUnk_09032CCC,
    gUnk_09032CE0,
    gUnk_0903259C,
    gUnk_09032664,
    gUnk_09032D08,
    gUnk_09032D80,
    gUnk_09032DF8,
    gUnk_09032F38,
    gUnk_09032F9C,
    gUnk_09032FEC,
    gUnk_09033078,
    gUnk_090330B4,
    gUnk_0903317C,
    gUnk_090331CC,
    gUnk_09033208,
    gUnk_0903303C,
    gUnk_09032E20,
    gUnk_090330DC,
    gUnk_09033104,
    gUnk_09033140,
    gUnk_09033258,
    gUnk_090332A8,
    gUnk_0903330C,
    gUnk_09033348,
    gUnk_09033398,
    gUnk_090333FC,
    gUnk_09033438,
    gUnk_09033460,
    &gUnk_0903349C,
    gUnk_090334B0,
    &gUnk_090334EC,
    gUnk_0903353C,
    gUnk_090335A0,
    gUnk_09032EC0,
    gUnk_09033500,
    gUnk_0903367C,
    gUnk_09032E70,
    gUnk_090336B8,
    gUnk_09033604,
    gUnk_090336F4,
};

const s32 gUnk_09033758[45] = {
    -8192, -8192, -8192, -12288, -8192, -8192, -8192, -12288,
    -8192, -8192, -8192, -12288, -8192, -8192, -8192, -12288,
    -8192, -8192, -8192, -12288, -8192, -8192, -8192, -12288,
    -8192, -8192, -8192, -12288, -8192, -8192, -8192, -12288,
    -8192, -8192, -8192, -12288, -8192, -8192, -8192, -12288,
    -8192, -8192, -8192, -12288, -12288,
};

const EventCharaParams gUnk_0903380C[94] = {
    { -42, 256, 460, 0, 0, 0 },
    { -34, 256, 384, 0, 0, 0 },
    { -56, 256, 307, 0, 0, 0 },
    { -64, 256, 384, 16, -32, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -54, 256, 384, 0, 0, 0 },
    { -44, 256, 384, 0, 0, 0 },
    { -16, 256, 384, 0, 0, 0 },
    { -32, 256, 384, 0, 0, 0 },
    { -32, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -64, 256, 384, 0, 0, 0 },
    { -64, 256, 384, 0, 0, 0 },
    { -64, 256, 460, 0, 0, 0 },
    { -54, 256, 460, 0, 0, 0 },
    { -76, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -56, 256, 384, 0, 0, 0 },
    { -60, 256, 460, 0, 0, 0 },
    { -70, 332, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -64, 256, 384, 0, 0, 0 },
    { -33, 256, 384, 0, 0, 0 },
    { -77, 256, 460, 0, 0, 0 },
    { -82, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -30, 256, 384, 0, 0, 0 },
    { -90, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -59, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -64, 256, 384, 16, -50, 0 },
    { -49, 256, 384, 0, 0, 0 },
    { -60, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -70, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -56, 256, 384, 0, 0, 0 },
    { -66, 256, 384, 0, 0, 0 },
    { -44, 256, 384, 0, 0, 0 },
    { -90, 256, 384, 0, 0, 0 },
    { -65, 256, 384, 0, 0, 0 },
    { -34, 256, 384, 0, 0, 0 },
    { -72, 256, 384, 0, 0, 0 },
    { -53, 256, 384, 0, 0, 0 },
    { -45, 256, 384, 0, 0, 0 },
    { -54, 256, 384, 0, 0, 0 },
    { -54, 256, 384, 0, 0, 0 },
    { -72, 256, 384, 0, 0, 0 },
    { -54, 256, 384, 0, 0, 0 },
    { -54, 256, 384, 0, 0, 0 },
    { -71, 256, 384, 0, 0, 0 },
    { -54, 256, 384, 0, 0, 0 },
    { -41, 256, 384, 0, 0, 0 },
    { -34, 128, 384, 0, 0, 0 },
    { -54, 204, 384, 0, 0, 0 },
    { -24, 256, 384, 0, 0, 0 },
    { -32, 256, 384, 0, 0, 0 },
    { -23, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -66, 256, 384, 0, 0, 0 },
    { -66, 256, 384, 0, 0, 0 },
    { -60, 256, 384, 0, 0, 0 },
    { -77, 256, 384, 0, 0, 0 },
    { -64, 256, 384, 0, 0, 0 },
    { -60, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { -40, 256, 384, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};

const char gTaskNameEventSeq[] = "event_seq";

const char gTaskNameEventChara[] = "event_chara";

const u16 gUnk_09033C8C[2] = {
    145, 167,
};

const u16 gUnk_09033C90[4] = {
    2048, 2048, 2048, 2048,
};

const u16 gUnk_09033C98[4] = {
    0, 0, 255, 255,
};

const u16 gUnk_09033CA0[4] = {
    255, 255, 0, 0,
};

const s32 gUnk_09033CA8[4] = {
    4096, 4096, 18432, 18432,
};

const s32 gUnk_09033CB8[4] = {
    3584, 28160, 3584, 28160,
};

const char gTaskNameMsgwin[] = "msgwin";

const s32 gUnk_09033CD0[4] = {
    114944, 114944, -76544, -76544,
};

const s32 gUnk_09033CE0[4] = {
    52736, 52736, 9216, 9216,
};

const s32 gUnk_09033CF0[4] = {
    14336, 32768, 14336, 32768,
};

const char gTaskNameMsgface[] = "msgface";

const s32 gUnk_09033D08[4][2] = {
    {26112, 15872},
    {26112, 40448},
    {36864, 15872},
    {36864, 40448},
};

const s32 gUnk_09033D28[2] = {
    16128, 19968,
};

const char gTaskNameMsgwait[] = "msgwait";

EventScanlineScroll* gEventScanlineScroll EWRAM_COMMON(4);

void event_seq_0(EventSeqWork* work, u8* a) {
#ifdef VERSION_EU
    EventBackgroundDef* u;
#endif

    gUnk_02039DD0 = NULL;
    gBtlWork = NULL;
    work->task = 0;
    work->unk_2C = a[0];
    work->unk_2E = a[1];
    work->seqDef = gUnk_09EE3FB4[work->unk_2C];
    work->unk_30 = 0;
    work->unk_31 = 0;
    gEventState->unk_8A = 0;
    work->unk_2F = 0;
    work->unk_32 = 0;
#ifdef VERSION_EU
    work->unk_3D = 0;
    work->unk_3A = 0;
    work->unk_3B = 0;
    work->unk_3C = 0;
#endif

    if (gEventState != NULL) {
        gEventState->unk_7A = 1;
        gEventState->unk_7B = 0;
        gEventState->unk_78 = 0;
        gEventState->unk_79 = 0;
        gEventState->unk_7F = 0;
        gEventState->unk_68 = 0;
        gEventState->unk_6A = 0;
        gEventState->unk_80 = 0;
        gEventState->unk_82 = 0;
        gEventState->unk_84 = 0;
        gEventState->unk_85 = 0;
        gEventState->unk_83 = 0;
#ifndef VERSION_EU
        RequestDma3Clear(GetBgCharBase(1), 0x8000);
#endif

        if (work->seqDef->keyframes->unk_14 & 0x80) {
            SetBackdropColor(31, 31, 31);
            FadeStartIn(1, 0x40);
        }
#ifdef VERSION_EU
        u = gUnk_09EE3CA0[work->unk_2C];
        if (u != NULL) {
            if (u->tiles2 != NULL) {
                if ((u->flags & 1) != 0) {
                    SetupBg(0, 3, 31, 14);
                    SetupBg(1, 0, 29, 0);
                    SetupBg(2, 2, 30, 0);
                    SetupBg(3, 0, 28, 0);
                } else {
                    SetupBg(0, 3, 31, 14);
                    SetupBg(1, 2, 30, 0);
                    SetupBg(2, 0, 22, 0);
                    SetupBg(3, 0, 23, 0);
                }
            }
            if (u->unk_24 != 0) {
                if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
                    eu_080059D4(2, u->tiles);
                } else {
                    LoadBgTiles(2, u->tiles, u->tilesSize);
                }
                LoadBgPalette(2, u->palette, u->paletteSize);
                SetBgColorMode(2, 128);
                SetBgSize(2, 0x8000);
                if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                    eu_080059F4(2, (void*)*u->maps);
                } else {
                    LoadBgMap(2, (void*)*u->maps, 0x1000);
                }
                SetBgAffine(2, 0, 256, 256, 0, 0);
            } else {
                eu_0806C734(work);
                eu_0806C7C8(work);
                eu_0806C848(work);
            }
        }
        if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0) {
            FadeStartIn(0, 64);
        } else if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0x80) {
            FadeStartIn(1, 120);
        }
        work->timer = 0;
        eu_0806C974(work);
#endif
    }
}

#ifdef VERSION_EU
u8 eu_0806C734(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
            eu_080059D4(3, u->tiles);
        } else {
            LoadBgTiles(3, u->tiles, u->tilesSize);
        }
        LoadBgPalette(3, u->palette, u->paletteSize);
        if (u->maps != NULL) {
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3A = 1;
                eu_08005A1C(3, u->maps, u->mapWidth, u->mapHeight);
            } else {
                work->unk_3A = 0;
                SetBgMapBlocks(3, u->maps, u->mapWidth, u->mapHeight);
            }
            RedrawBgMapAt(3, 0, 0);
        }
    }
    return 1;
}
u8 eu_0806C7C8(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->maps2 != NULL) {
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3B = 1;
                eu_08005A1C(2, u->maps2, u->mapWidth, u->mapHeight);
            } else {
                work->unk_3B = 0;
                SetBgMapBlocks(2, u->maps2, u->mapWidth, u->mapHeight);
            }
            RedrawBgMapAt(2, 0, 0);
            gEventState->unk_78 = 1;
        } else {
            DisableBg(2);
        }
    }
    return 1;
}
u8 eu_0806C848(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->tiles2 != NULL) {
            if ((u->flags & 1) != 0) {
                LoadBgTiles(2, u->tiles2, u->tilesSize2);
            } else if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
                eu_080059D4(1, u->tiles2);
            } else {
                LoadBgTiles(1, u->tiles2, u->tilesSize2);
            }
        }
        if (u->maps3 != NULL) {
            if ((u->flags & 2) != 0) {
                gBldCnt = (BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ);
                (*(volatile u16*)&gBldAlpha) = 0x050E;
                SetBgPriority(2, 1);
                gEventState->unk_6E = 0x1D42;
                gEventState->unk_70 = 0x050E;
            } else {
                gEventState->unk_6E = 0;
                gEventState->unk_70 = 0;
            }
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3C = 1;
                eu_08005A1C(1, u->maps3, u->mapWidth, u->mapHeight);
            } else {
                work->unk_3C = 0;
                SetBgMapBlocks(1, u->maps3, u->mapWidth, u->mapHeight);
            }
            RedrawBgMapAt(1, 0, 0);
            gEventState->unk_79 = 1;
        } else {
            DisableBg(1);
        }
    }
    return 1;
}
u8 eu_0806C974(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    const EventCameraKeyframe* q = work->seqDef->keyframes;
    u16 i;
    gEventState->unk_50 = q->unk_04;
    gEventState->unk_54 = q->unk_08;
    gEventState->unk_48 = gEventState->unk_50 - 0x7800;
    gEventState->unk_4C = gEventState->unk_54 - 0x5000;
    gEventState->flags = 0;
    gEventState->unk_6C = 0;
    gEventState->unk_7C = 0;
    gEventState->unk_87 = 0;
    gEventState->unk_81 = 0;
    gEventState->unk_88 = 0;
    gEventState->unk_89 = 0;
    gEventState->unk_7D = 0;
    gEventState->unk_7E = 0;
    gEventState->unk_60 = 0;
    if (u->unk_20 != 5) {
        gEventState->unk_44 = u->unk_20;
        work->unk_3D = 1;
    } else {
        gEventState->unk_44 = u->unk_20;
    }
    for (i = 0; i < 16; i++) {
        gEventState->unk_00[i] = NULL;
    }
    return 1;
}
#endif
u8 event_seq_1(EventSeqWork* work, void* a) {
    EventSeqArg arg;
#ifndef VERSION_EU
    s32 flag;
#endif
    EventBackgroundDef* u;
    EventSequenceDef* t;
#ifndef VERSION_EU
    const EventCameraKeyframe* q;
    u16 i;
#endif
    u8 j;

#ifndef VERSION_EU
    flag = 0;
#endif
    u = gUnk_09EE3CA0[work->unk_2C];
#ifndef VERSION_EU

    if (u != NULL) {
        if (u->tiles2 != NULL) {
            if ((u->flags & 1) != 0) {
                SetupBg(0, 3, 31, 14);
                SetupBg(1, 0, 29, 0);
                SetupBg(2, 2, 30, 0);
                SetupBg(3, 0, 28, 0);
            } else {
                SetupBg(0, 3, 31, 14);
                SetupBg(1, 2, 30, 0);
                SetupBg(2, 0, 22, 0);
                SetupBg(3, 0, 23, 0);
            }
        }

        if (u->unk_24 != 0) {
            LoadBgTiles(2, u->tiles, u->tilesSize);
            LoadBgPalette(2, u->palette, u->paletteSize);
            SetBgColorMode(2, 128);
            SetBgSize(2, 0x8000);
            LoadBgMap(2, (void*)*u->maps, 0x1000);
            SetBgAffine(2, 0, 256, 256, 0, 0);
        } else {
            LoadBgTiles(3, u->tiles, u->tilesSize);
            LoadBgPalette(3, u->palette, u->paletteSize);

            if (u->tiles2 != NULL) {
                if ((u->flags & 1) != 0) {
                    LoadBgTiles(2, u->tiles2, u->tilesSize2);
                } else {
                    LoadBgTiles(1, u->tiles2, u->tilesSize2);
                }
            }

            if (u->maps != NULL) {
                SetBgMapBlocks(3, u->maps, u->mapWidth, u->mapHeight);
                RedrawBgMapAt(3, 0, 0);
            }

            if (u->maps2 != NULL) {
                SetBgMapBlocks(2, u->maps2, u->mapWidth, u->mapHeight);
                RedrawBgMapAt(2, 0, 0);
                gEventState->unk_78 = 1;
            } else {
                DisableBg(2);
            }

            if (u->maps3 != NULL) {
                if ((u->flags & 2) != 0) {
                    gBldCnt = (BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ);
                    (*(volatile u16*)&gBldAlpha) = 0x050E;
                    SetBgPriority(2, 1);
                    gEventState->unk_6E = 0x1D42;
                    gEventState->unk_70 = 0x050E;
                } else {
                    gEventState->unk_6E = 0;
                    gEventState->unk_70 = 0;
                }

                SetBgMapBlocks(1, u->maps3, u->mapWidth, u->mapHeight);
                RedrawBgMapAt(1, 0, 0);
                gEventState->unk_79 = 1;
            } else {
                DisableBg(1);
            }
        }
    }

    q = work->seqDef->keyframes;
    gEventState->unk_50 = q->unk_04;
    gEventState->unk_54 = q->unk_08;
    gEventState->unk_48 = gEventState->unk_50 - 0x7800;
    gEventState->unk_4C = gEventState->unk_54 - 0x5000;
    gEventState->flags = 0;
    gEventState->unk_6C = 0;
    gEventState->unk_7C = 0;
    gEventState->unk_87 = 0;
    gEventState->unk_81 = 0;
    gEventState->unk_88 = 0;
    gEventState->unk_89 = 0;
    gEventState->unk_7D = 0;
    gEventState->unk_7E = 0;
    gEventState->unk_60 = 0;

    if (u->unk_20 != 5) {
        gEventState->unk_44 = u->unk_20;
        flag = 1;
    } else {
        gEventState->unk_44 = 5;
    }

    i = 0;
    t = work->seqDef;

    while (i < 16) {
        gEventState->unk_00[i] = NULL;
        i++;
    }

#else
    t = work->seqDef;
#endif

    TaskPoolInit(&work->tasks, t->unk_00 + 8);
    TaskPoolInit(&work->tasks2, 1);
    work->task = (u32)TaskCreate(&work->tasks2, &gTaskDescMsgwin, &work->unk_2C);

    for (j = 0; j < t->unk_00; j++) {
        arg.unk_00 = work->unk_2C;
        arg.unk_02 = t->charaTracks[j].unk_04;
        arg.unk_03 = j;

        if (arg.unk_02 > 94) {
            work->unk_32 = 1;
            gEventState->unk_60 = arg.unk_02;
        }

        TaskCreate(&work->tasks, &gTaskDescEventChara, &arg);
    }

    TaskCreate(&work->tasks, &gTaskDescView, &work->unk_2C);
    TaskCreate(&work->tasks, &gTaskDescEvSound, &work->unk_2C);
    TaskCreate(&work->tasks, &gTaskDescEVBGEFFECT, &work->unk_2C);

#ifdef VERSION_EU
    if (work->unk_3D != 0) {
#else
    if (flag != 0) {
#endif
        TaskCreate(&work->tasks, &gTaskDescMapAnim, NULL);
    }

#ifndef VERSION_EU
    if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0) {
        FadeStartIn(0, 64);
    } else if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0x80) {
        FadeStartIn(1, 120);
    }

    work->timer = 0;
#endif

    if (u != NULL) {
        if (u->mapObjects != 0) {
            TaskCreate(&work->tasks, &gTaskDescEvMapObj, &work->unk_2C);
        }

        if ((u->flags & 1) != 0) {
            func_080CA35C();
            TaskCreate(&work->tasks, &gTaskDescPooMapanime, NULL);
        }
    }

    SetTaskUpdate(a, (TaskUpdateFunc)func_0806D830);
    return 1;
}
u8 func_0806D808(void) {
    u8 r = FadeIsActive();
    u8 v;

    if (r != 0) {
        v = 1;
    } else {
        gEventState->unk_7A = 0;
        m4aMPlayAllStop();
        v = 0;
    }
    return v;
}
u8 func_0806D830(EventSeqWork* p, void* a) {
    EventSequenceDef* t;
    u8 i;

    if (gEventState == NULL) {
        return 0;
    }

    if ((GetKeysHeld() & START_BUTTON) != 0) {
        switch (p->unk_2C) {
        case 68:
        case 83:
        case 84:
            break;
        default:
            gEventState->unk_8A++;
            break;
        }
    } else {
        gEventState->unk_8A = 0;
    }

    if (gEventState->unk_8A > 64 || gEventState->unk_83 == 1) {
        gEventState->unk_8A = 64;
        p->unk_2F = 1;
        gEventState->unk_82 = 1;
        FadeStartOut(0, 64);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0806D808);

        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 0);
        }
        return 1;
    }

    if (p->timer == p->seqDef->unk_24) {
        gEventState->flags |= 2;
    } else {
        s32 t = p->seqDef->keyframes->unk_14 & 0xFF0;

        if (t == 0) {
            FadeStartIn(0, 64);
        } else if (t == 128) {
            FadeStartIn(1, 120);
        }
        p->timer++;
    }
    TaskPoolUpdate(&p->tasks);
    TaskPoolUpdate(&p->tasks2);

    if (p->unk_32 != 0) {
        gBtlWork->unk_000 = gEventState->unk_48;
        gBtlWork->unk_004 = gEventState->unk_4C;
    }

    if ((gEventState->flags & 3) == 2) {
        gEventState->unk_6C++;
    }

    t = gUnk_09EE3FB4[p->unk_2C];

    if (gEventState->unk_6C >= t->unk_18 && p->unk_2F == 0 && FadeIsActive() == 0) {
        if (gEventState->unk_7F == 0) {
            FadeStartOut(0, 64);
        }
        p->unk_2F = 1;
        gEventState->unk_82 = 1;
    }

    if (p->unk_2F == 1) {
        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 0);
        }

        if (FadeIsActive() == 0) {
            gEventState->unk_7A = 0;
            return 0;
        }
    }
    return 1;
}
void event_seq_2(EventSeqWork* p) {
    TaskPoolDraw(&p->tasks2);

    if (p->unk_32 != 0) {
        TaskPoolDraw(&gBtlWork->taskPools[0]);
    }
    TaskPoolDraw(&p->tasks);
}
void event_seq_3(EventSeqWork* p) {
    TaskPoolDestroy(&p->tasks);

    if (p->task != 0) {
        TaskPoolDestroy(&p->tasks2);
    }
#ifdef VERSION_EU
    if (p->unk_3A != 0) {
        eu_08005ADC(3);
    }

    if (p->unk_3B != 0) {
        eu_08005ADC(2);
    }

    if (p->unk_3C != 0) {
        eu_08005ADC(1);
    }
#endif
}
void event_chara_0(EventCharaWork* p, u32* a) {
    s32 v0;
    s32 v1;

    TaskPoolInit(&p->tasks, 8);
    *(s32*)&p->unk_024 = *a;
    p->keyframes = gUnk_09EE3FB4[p->unk_024]->charaTracks[p->unk_027].keyframes;
    p->unk_1A0 = 0;
    p->unk_1A4 = p->keyframes->unk_04;
    p->unk_188 = 0;
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_1A9 = 0;
    p->unk_1AA = 0;
    p->unk_180 = 0;
    p->unk_184 = 0;
    p->tiles = NULL;
    p->palette = NULL;
    p->gfx = NULL;
    p->unk_1B1 = 0;
    p->unk_1B2 = 0;
    p->unk_1B3 = 0;
    p->unk_1B5 = 0;
    p->unk_1B0 = 0;
    p->unk_1B6 = 1;
    p->unk_1B8 = 0;
    gEventState->unk_00[p->unk_027] = (Ent08074EC8*)p->unk_028;

    switch (p->unk_026) {
    case 95:
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        gBtlWork->flags = 0;
        p->unk_1B3 = 1;
        gBtlWork->unk_000 = gEventState->unk_48;
        gBtlWork->unk_004 = gEventState->unk_4C;
        gBtlWork->scale = 0x100;
        gBtlWork->unk_018 = 0;
        gBtlWork->unk_028 = 0x100;
        gBtlWork->x = gEventState->unk_48;
        gBtlWork->y = gEventState->unk_4C;
        gBtlWork->x2 = 0x10000;
        gBtlWork->y2 = 0x14000;
        gBtlWork->unk_01C = 0x10000;
        gBtlWork->unk_020 = 0x14000;
        gBtlWork->unk_01A = 15;
        p->unk_02C = p->keyframes->unk_08;
        p->unk_030 = p->keyframes->unk_0C;
        p->unk_034 = p->keyframes->unk_10;
        TaskCreate(&p->tasks, &gTaskDescBosTm, p->unk_028);
        break;
    case 96:
        gBtlWork = EwramAlloc(464);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->scale = 0x100;
        gBtlWork->unk_018 = 0;
        SetBattleBounds(128, 424, 294, 384);
        gEventState->unk_00[16] = TaskCreate(&p->tasks, &gTaskDescBosPc, NULL);
        break;
    case 97:
        gBtlWork = EwramAlloc(464);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->scale = 0x100;
        gBtlWork->unk_018 = 0;
        SetBattleBounds(128, 424, 294, 384);
        gEventState->unk_00[16] = TaskCreate(&p->tasks, &gTaskDescBosPc, &p->tasks);
        p->unk_1B4 = 0;
        gEventState->unk_48 = v0 = gBtlWork->unk_000;
        gEventState->unk_4C = v1 = gBtlWork->unk_004;
        gEventState->unk_50 = gBtlWork->x;
        gEventState->unk_54 = gBtlWork->y;
        gEventState->x = v0;
        gEventState->y = v1;
        break;
    case 100:
        SetBgSize(1, 0x4000);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->scale = 0x100;
        gBtlWork->unk_018 = 0;
        SetBattleBounds(128, 368, 480, 512);
        gEventState->unk_00[16] = TaskCreate(&p->tasks, &gTaskDescBosLst, &p->tasks);
        break;
    case 101:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->x = 0x26600;
        gBtlWork->y = 0x12800;
        gBtlWork->unk_000 = 0x26600;
        gBtlWork->unk_004 = 0x12800;
        gBtlWork->x2 = 0x26600;
        gBtlWork->y2 = 0x12800;
        p->unk_02C = 0x2A200;
        p->unk_030 = 0x15E00;
        p->unk_034 = -0x3800;
        SetBattleBounds(420, 612, 328, 384);
        TaskCreate(&p->tasks, &gTaskDescBosJf, p->unk_028);
        break;
    case 103:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        gBtlWork->flags = 0;
        p->unk_1B3 = 1;
        gBtlWork->x = 0x12C00;
        gBtlWork->y = 0x16800;
        gBtlWork->unk_000 = 0x12C00;
        gBtlWork->unk_004 = 0x16800;
        gBtlWork->x2 = 0x12C00;
        gBtlWork->y2 = 0x16800;
        gEventState->unk_48 = gBtlWork->x - 0x7800;
        gEventState->unk_4C = gBtlWork->y - 0x5000;
        gEventState->unk_50 = gBtlWork->x;
        gEventState->unk_54 = gBtlWork->y;
        gEventState->unk_68 = 0;
        gEventState->unk_6A = 0;
        p->unk_02C = p->keyframes->unk_08;
        p->unk_030 = p->keyframes->unk_0C;
        p->unk_034 = p->keyframes->unk_10;
        SetBattleBounds(0, 256, 328, 424);
        TaskCreate(&p->tasks, &gTaskDescBosDsd, p->unk_028);
        break;
    case 98:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->tasks, &gTaskDescBosBoogie, NULL);
        gBtlWork->fadeAmount = 5;
        break;
    case 99:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->tasks, &gTaskDescBosUrsula, NULL);
        gBtlWork->fadeAmount = 5;
        break;
    case 104:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->flags = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->tasks, &gTaskDescBosGa, (void*)1);
        gBtlWork->fadeAmount = 5;
        break;
    default:
        if ((p->keyframes->unk_18 & 0x2000) == 0) {
            CreateEvtObjTask(&p->tasks, p->unk_028, p->unk_026, p->keyframes->unk_00, p->keyframes->unk_08, p->keyframes->unk_0C, p->keyframes->unk_10);
            p->unk_1B4 = 1;
        } else {
            p->unk_1B4 = 0;
        }

        func_08072C34(p);
        break;
    }

    if (p->unk_1B4 != 0) {
        func_0806F94C(p);
    }
}
u8 event_chara_1(EventCharaWork* p, void* a) {
    u8 t;
    s32 v0;
    s32 v1;

    t = func_0806E570(p);

    if (p->unk_1B4 != 0) {
        func_0806E7A8(p);
    }
    func_08070AD4(p);

    if (t != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
            ((void (*)(EventCharaWork*, void*))p->keyframes[p->unk_1A0].unk_1C)(p, a);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }

    if (p->keyframes[p->unk_1A0].unk_18 & 0x100) {
        p->unk_03C |= 4;
    } else {
        p->unk_03C &= ~4;
    }

    if (p->keyframes[p->unk_1A0].unk_18 & 0x200) {
        gEventState->flags |= 1;
        gEventState->flags |= 4;
        p->unk_19C = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080700D4);
    }
    TaskPoolUpdate(&p->tasks);

    if (p->unk_1B3 != 0) {
        switch (p->unk_026) {
        case 0x62:
            gEventState->x = gEventState->unk_48 = gBtlWork->x2;
            gEventState->y = gEventState->unk_4C = gBtlWork->y2;
            TaskPoolUpdate(&gBtlWork->taskPools[1]);
            break;
        case 0x63:
            gBtlWork->unk_004 = gBtlWork->y;
            gBtlWork->x2 = gEventState->unk_48;
            gBtlWork->y2 = gEventState->unk_4C;
            gEventState->x = gEventState->unk_48;
            gEventState->y = gEventState->unk_4C;
            TaskPoolUpdate(&gBtlWork->taskPools[0]);
            TaskPoolUpdate(&gBtlWork->taskPools[1]);
            break;
        case 0x65:
            gEventState->unk_48 = v0 = gBtlWork->unk_000;
            gEventState->unk_4C = v1 = gBtlWork->unk_004;
            gEventState->unk_50 = gBtlWork->x;
            gEventState->unk_54 = gBtlWork->y;
            gEventState->x = v0;
            gEventState->y = v1;
            break;
        case 0x61:
            gBtlWork->x2 = gEventState->unk_50;
            gBtlWork->y2 = gEventState->unk_54;
            break;
        case 0x67:
            break;
        }
    }

    if (p->unk_026 == 0) {
        if (gBtlWork != NULL) {
            gBtlWork->actor->x = p->unk_02C - 0x7800;
            gBtlWork->actor->y = p->unk_030 - 0x5000;
            gBtlWork->actor->z = 0;
        }
    }

    if (p->unk_1B5 != 0) {
        return 0;
    }

    if (p->keyframes[p->unk_1A0].unk_18 & 0x100000) {
        if (gFrameCounter % 6 == 0) {
            u16 v = GetRandom() % 7 + 4;

            (*(volatile u16*)&gBldAlpha) = ((16 - v) << 8) | v;
        }
    }
    return 1;
}
static inline s16 GetEventCharaScreenX(EventCharaWork* p) {
    return (p->unk_180 >> 8) - (gEventState->x >> 8);
}

void event_chara_2(EventCharaWork* p) {
    const EventCharaKeyframe* e;
    s32 save;
    s32 x;
    s32 y;
    u16 h;

    save = p->unk_034;
    e = &p->keyframes[p->unk_1A0];

    if (e->unk_18 & 0x80) {
        p->unk_034 = gSineTable[p->unk_1B0] * 2 + save;
    } else if (e->unk_18 & 0x40000) {
        p->unk_034 = gSineTable[p->unk_1B0] * 3 + save;
    }

    if (p->unk_1B6 != 0) {
        TaskPoolDraw(&p->tasks);
    }

    if (p->unk_026 == 99) {
        TaskPoolDraw(&gBtlWork->taskPools[0]);
    }

    if (p->tiles != NULL) {
        h = p->unk_03E;

        if (p->unk_1B1 == 0) {
            h &= 0xFFFE;
        } else {
            h |= 1;
        }
        x = GetEventCharaScreenX(p);
        y = (p->unk_184 >> 8) + gUnk_0903380C[p->unk_026].spriteYOffset - (gEventState->y >> 8);
        DrawSprite(x, y, p->gfx, p->tiles, p->palette, 0, h, 50);
    }
    p->unk_034 = save;
}
void event_chara_3(EventCharaWork* p) {
    TaskPoolDestroy(&p->tasks);

    if (p->unk_1B3 != 0) {
        TaskPoolDestroy(&gBtlWork->taskPools[0]);
        TaskPoolDestroy(&gBtlWork->taskPools[1]);
        EwramFree(gBtlWork);
    }
}
u8 func_0806E570(EventCharaWork* p) {
    const EventCharaKeyframe* e = &p->keyframes[p->unk_1A0];
    u16 v;

    if (p->keyframes[p->unk_1A0].unk_04 > gEventState->unk_6C) {
        return 0;
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x8000) != 0) {
        return 0;
    }

    p->unk_1A0++;
    p->unk_1A4 = p->keyframes[p->unk_1A0].unk_04 - gEventState->unk_6C;
    p->unk_17C = p->keyframes[p->unk_1A0].unk_00;

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x4000) != 0) {
        CreateEvtObjTask(&p->tasks, p->unk_028, p->unk_026, p->keyframes[p->unk_1A0].unk_00,
                      p->keyframes[p->unk_1A0].unk_08, p->keyframes[p->unk_1A0].unk_0C,
                      p->keyframes[p->unk_1A0].unk_10);
        p->unk_1B4 = 1;
        func_08072C34(p);
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x10000) != 0) {
        p->unk_1B5 = 1;
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x800) != 0) {
        LoadPalette(&gUnk_096148D8[0x100], (void*)(p->unk_044 * 32 + 0x05000200), 32);
    } else if ((p->keyframes[p->unk_1A0 - 1].unk_18 & 0x800) != 0) {
        LoadPalette(gUnk_0813B09C[p->unk_026].res.palette, (void*)(p->unk_044 * 32 + 0x05000200), 32);
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x100000) != 0) {
        gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
        v = p->unk_03E;
        func_0801CE00(p->unk_028, v | 4);
    } else {
        v = p->unk_03E;
        func_0801CE00(p->unk_028, p->unk_03E & 0xFFFB);
        p->unk_1B8 = 0;
    }

    if (p->unk_1B4 != 0) {
        if ((p->keyframes[p->unk_1A0].unk_18 & 15) == 2) {
            EvtObjSetPos(p->unk_028, p->keyframes[p->unk_1A0].unk_08, p->keyframes[p->unk_1A0].unk_0C, p->keyframes[p->unk_1A0].unk_10);
        }

        EvtObjSetAnim(p->unk_028, p->unk_17C);
        func_0806F94C(p);
        return 1;
    }

    if (p->keyframes[p->unk_1A0].unk_00 == 0x3AF) {
        func_0810B350(gEventState->unk_00[16]);
    }

    if (p->keyframes[p->unk_1A0].unk_00 == 0x3AB) {
        func_0810C2C4(gEventState->unk_00[16]);
    }

    return 0;
}
void func_0806E7A8(EventCharaWork* p) {
    const EventCharaKeyframe* e = &p->keyframes[p->unk_1A0];
    BtlObj* t;

    if (e->unk_00 == 0x3A7) {
        t = ListPoolFirst(&gBtlWork->pool);

        if (t != NULL) {
            t->flags |= 2;
        }
    }

    switch (e->unk_18 & 15) {
    case 2:
        EvtObjSetPos(p->unk_028, p->keyframes[p->unk_1A0].unk_08, p->keyframes[p->unk_1A0].unk_0C, p->keyframes[p->unk_1A0].unk_10);
        break;
    case 3:
        ApproachValue(&p->unk_02C, p->keyframes[p->unk_1A0].unk_08, p->unk_1A4);
        ApproachValue(&p->unk_030, p->keyframes[p->unk_1A0].unk_0C, p->unk_1A4);
        ApproachValue(&p->unk_034, p->keyframes[p->unk_1A0].unk_10, p->unk_1A4);
        p->unk_1A4--;

        if (p->unk_1A4 == 0) {
            if ((p->keyframes[p->unk_1A0].unk_18 & 0x1000) == 0) {
                func_0806E9BC(p);
            }
        }
        break;
    case 4:
        if ((e->unk_18 & 32) == 0) {
            p->unk_19C = gUnk_0903380C[p->unk_026].unk_02;
        } else {
            p->unk_19C = gUnk_0903380C[p->unk_026].unk_04;
        }

        if (e->unk_14 == 1) {
            p->unk_034 -= p->unk_19C;
        } else if (e->unk_14 == 2) {
            p->unk_034 += p->unk_19C;
        } else {
            p->unk_02C += (gSineTable[e->unk_14 & 0xFF] * p->unk_19C) >> 8;
            p->unk_030 += (-gSineTable[(e->unk_14 & 0xFF) + 64] * p->unk_19C) >> 8;
        }
        break;
    }

    if ((e->unk_18 & 0x80) != 0) {
        p->unk_1B0 += 4;
    } else if ((e->unk_18 & 0x40000) != 0) {
        p->unk_1B0 += 4;
    } else {
        p->unk_1B0 = 0;
    }

    if ((e->unk_18 & 0x80000) != 0) {
        p->unk_1B6 ^= 1;
    } else {
        p->unk_1B6 = 1;
    }
}

void func_0806E9BC(EventCharaWork* p) {
    const EventCharaKeyframe* e = &p->keyframes[p->unk_1A0];

    EvtObjSetAnim(p->unk_028, e->unk_14);
}

u8 _0806E9DC(EventCharaWork* p, void* a) {
    p->unk_188 = 0x800;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806EA28);
    return 1;
}
u8 func_0806EA28(EventCharaWork* p, void* a) {
    u16 x;
    u16 y;
    u8 t;

    x = (p->unk_02C >> 8) - (gEventState->x >> 8);
    y = (p->unk_030 >> 8) + (p->unk_034 >> 8) - (gEventState->y >> 8);
    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188 / 4;
        p->unk_188 -= p->unk_18C / 4;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
        if (p->unk_1A8 == 0) {
            if (p->unk_026 == 10) {
                m4aSongNumStart(0x144);
                func_08076110(0x144, x, y);
            }
        }
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0x800;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806EB94(EventCharaWork* p, void* a) {
    p->unk_188 = 0xC00;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806EBE0);
    return 1;
}
u8 func_0806EBE0(EventCharaWork* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188 / 4;
        p->unk_188 -= p->unk_18C / 4;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806ECE0(EventCharaWork* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806ED2C);
    return 1;
}
u8 func_0806ED2C(EventCharaWork* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_08070AD4(p);
    func_0806E7A8(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188;
        p->unk_188 -= p->unk_18C;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0x800;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806EE20(EventCharaWork* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806EE6C);
    return 1;
}
u8 func_0806EE6C(EventCharaWork* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188;
        p->unk_188 -= p->unk_18C;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > 0) {
        p->unk_034 = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806EF40(void* work, void* a) {
    EventCharaWork* p = work;
    const EventCharaKeyframe* e;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F02C);

    if (p->unk_026 == 3) {
        e = &p->keyframes[p->unk_1A0];
        if ((e->unk_18 & 0x80000) == 0) {
            m4aSongNumStart(SONG_EV_WARPIN);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F02C(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = ((16 - p->unk_1A9) << 8) | p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
        {
            u16 z = p->unk_03E;

            z &= 0xFFFB;
            func_0801CE00(p->unk_028, z);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F114(void* work, void* a) {
    EventCharaWork* p = work;
    const EventCharaKeyframe* e;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = 0x1000;
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F204);

    if (p->unk_026 == 3) {
        e = &p->keyframes[p->unk_1A0];
        if ((e->unk_18 & 0x80000) == 0) {
            m4aSongNumStart(SONG_EV_WARPOUT);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F204(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 <= 15) {
            p->unk_1A9++;
        }
    }
    (*(volatile u16*)&gBldAlpha) = ((16 - p->unk_1A9) << 8) | p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
        {
            u16 z = p->unk_03E;

            z &= 0xFFFB;
            func_0801CE00(p->unk_028, z);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F2EC(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F3A8);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F3A8(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 <= 15) {
            p->unk_1A9++;
        }
    }
    (*(volatile u16*)&gBldAlpha) = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F47C(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = 0x1010;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F53C);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F53C(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F610(EventCharaWork* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F64C);
    return 1;
}
u8 func_0806F64C(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_02C += gSineTable[(u8)p->unk_18C] * (p->unk_198 >> 8);
    p->unk_030 += -gSineTable[(u8)p->unk_18C + 64] * (p->unk_198 >> 9);
    p->unk_18C += 2;

    if (p->unk_198 < 0x200) {
        p->unk_198 += 25;
    }

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F734(EventCharaWork* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F770);
    return 1;
}
u8 func_0806F770(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_02C += gSineTable[(u8)p->unk_18C] * (p->unk_198 >> 8);
    p->unk_030 += -gSineTable[(u8)p->unk_18C + 64] * (p->unk_198 >> 9);
    p->unk_18C += 6;

    if (p->unk_198 < 0x200) {
        p->unk_198 += 25;
    }

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F858(EventCharaWork* p, void* a) {
    p->unk_18C = 1;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806F898);
    return 1;
}
u8 func_0806F898(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_198 == 2) {
        p->unk_034 += p->unk_18C << 10;
        p->unk_18C = -p->unk_18C;
        p->unk_198 = 0;
    } else {
        p->unk_198++;
    }

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
void func_0806F94C(EventCharaWork* p) {
    u16 z;

    z = p->unk_03E;

    if (p->keyframes[p->unk_1A0].unk_18 & 0x40) {
        if (p->keyframes[p->unk_1A0].unk_18 & 0x10) {
            z |= 0x401;
            z &= 0xF7FF;
            func_0801CE00(p->unk_028, z);
        } else {
            z |= 0x801;
            z &= 0xFBFF;
            func_0801CE00(p->unk_028, z);

            if ((p->keyframes[p->unk_1A0].unk_18 & 0x400) == 0) {
                z |= 0x801;
                func_0801CE00(p->unk_028, z);
            } else {
                z |= 1;
                z &= 0xF7FF;
                func_0801CE00(p->unk_028, z);
            }
        }
    } else {
        if (p->keyframes[p->unk_1A0].unk_18 & 0x10) {
            z |= 0x400;
            z &= 0xF7FF;
            z &= 0xFFFE;
            func_0801CE00(p->unk_028, z);
        } else {
            z |= 0x800;
            z &= 0xFBFF;
            z &= 0xFFFE;
            func_0801CE00(p->unk_028, z);

            if ((p->keyframes[p->unk_1A0].unk_18 & 0x400) == 0) {
                z |= 0x800;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            } else {
                z &= 0xF7FF;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            }
        }
    }
}
u8 func_0806FA84(EventCharaWork* p, void* a) {
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806FAB8);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FAB8(EventCharaWork* p, void* a) {
    u16 buf[2];

    memcpy(buf, gUnk_09033C8C, 4);
    EvtObjSetAnim(p->unk_028, buf[p->unk_1A9]);
    p->unk_1AA++;
    if (p->unk_1AA == 12) {
        p->unk_1AA = 0;
        p->unk_1A9 ^= 1;
    }

    if (func_0806E570(p) != 0) {
        if (p->tiles != NULL) {
            ReleaseObjTiles(p->tiles);
        }

        if (p->palette != NULL) {
            ReleaseObjPalette(p->palette);
        }
        p->tiles = NULL;
        p->palette = NULL;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FB6C(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806FC28);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FC28(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FCF4(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = 0;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0806FDB0);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FDB0(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = (16 - p->unk_1A9) | (p->unk_1A9 << 8);
    (*(volatile u16*)&gBldAlpha) = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
void func_0806FE90(EventCharaWork* p) {
    u16 keys = GetKeysHeld();

    switch (keys & DPAD_ANY) {
    case DPAD_UP:
        if (GetKeyReleaseTime(DPAD_LEFT) <= 4) {
            p->unk_1AB = 211;
        } else if (GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
            p->unk_1AB = 45;
        } else {
            p->unk_1AB = 0;
        }
        break;
    case DPAD_DOWN:
        if (GetKeyReleaseTime(DPAD_LEFT) <= 4) {
            p->unk_1AB = 173;
        } else if (GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
            p->unk_1AB = 83;
        } else {
            p->unk_1AB = 128;
        }
        break;
    case DPAD_LEFT:
        if (GetKeyReleaseTime(DPAD_UP) <= 4) {
            p->unk_1AB = 211;
        } else if (GetKeyReleaseTime(DPAD_DOWN) <= 4) {
            p->unk_1AB = 173;
        } else {
            p->unk_1AB = 192;
        }
        break;
    case DPAD_RIGHT:
        if (GetKeyReleaseTime(DPAD_UP) <= 4) {
            p->unk_1AB = 45;
        } else if (GetKeyReleaseTime(DPAD_DOWN) <= 4) {
            p->unk_1AB = 83;
        } else {
            p->unk_1AB = 64;
        }
        break;
    case (DPAD_RIGHT | DPAD_UP):
        p->unk_1AB = 45;
        break;
    case (DPAD_LEFT | DPAD_UP):
        p->unk_1AB = 211;
        break;
    case (DPAD_RIGHT | DPAD_DOWN):
        p->unk_1AB = 83;
        break;
    case (DPAD_LEFT | DPAD_DOWN):
        p->unk_1AB = 173;
        break;
    }
}

void func_08070008(EventCharaWork* p) {
    u8 old = p->unk_1AB;

    func_0806FE90(p);

    if (old != p->unk_1AB) {
        if (abs((s8)GetAngleDiff(old, p->unk_1AB)) > 100) {
            p->unk_19C = 0;
        } else {
            p->unk_19C >>= 1;
        }
    }
}

void func_08070058(EventCharaWork* p, s32 a) {
    u16 f;

    f = p->unk_03E;

    switch (p->unk_1AB) {
    case 0xD3:
        f &= 0xFFFE;
        break;
    case 0x2D:
    case 0x40:
    case 0x53:
        f |= 1;
        break;
    case 0x00:
    case 0x80:
    case 0xAD:
    case 0xC0:
        f &= 0xFFFE;
        break;
    }

    if (a != p->unk_17C) {
        EvtObjSetAnim(p->unk_028, a);
        p->unk_17C = a;
    }
    func_0801CE00(p->unk_028, f);
}
u8 func_080700D4(EventCharaWork* p, void* a) {
    u16 keys;
    s32 v;

    keys = GetKeysHeld();
    func_0806FE90(p);

    switch (p->unk_1AB) {
    case 0x00:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 5);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 10);
        }
        break;
    case 0x80:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 6);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 11);
        }
        break;
    case 0xC0:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 8);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 13);
        }
        break;
    case 0x40:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 8);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 13);
        }
        break;
    case 0xD3:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 9);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 14);
        }
        break;
    case 0x2D:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 9);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 14);
        }
        break;
    case 0xAD:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 7);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 12);
        }
        break;
    case 0x53:
        if ((keys & A_BUTTON) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 7);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 12);
        }
        break;
    }

    if ((keys & DPAD_ANY) != 0) {
        v = p->unk_19C + 51;
        p->unk_19C = v;

        switch (p->unk_1AD) {
        case 1:
            if (v > gUnk_0903380C[p->unk_026].unk_02) {
                p->unk_19C = gUnk_0903380C[p->unk_026].unk_02;
            }
            break;
        case 2:
            if (v > gUnk_0903380C[p->unk_026].unk_04) {
                p->unk_19C = gUnk_0903380C[p->unk_026].unk_04;
            }
            break;
        }
    } else {
        p->unk_19C -= 102;

        if (p->unk_19C < 0) {
            p->unk_19C = 0;
        }

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 0);
            break;
        case 0x80:
            func_08070058(p, 1);
            break;
        case 0xC0:
            func_08070058(p, 3);
            break;
        case 0x40:
            func_08070058(p, 3);
            break;
        case 0xAD:
            func_08070058(p, 2);
            break;
        case 0x53:
            func_08070058(p, 2);
            break;
        case 0xD3:
            func_08070058(p, 4);
            break;
        case 0x2D:
            func_08070058(p, 4);
            break;
        }
    }

    if ((GetKeysPressed() & B_BUTTON) != 0) {
        p->unk_1AF = 0;
        p->unk_1A8 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807048C);
    }

    v = p->unk_02C + (gSineTable[p->unk_1AB] * p->unk_19C >> 8);
    p->unk_02C = v;
    p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;

    if (p->unk_026 == 0) {
        if (gBtlWork != NULL) {
            gBtlWork->actor->x = v - 0x7800;
            gBtlWork->actor->y = p->unk_030 - 0x5000;
            gBtlWork->actor->z = 0;
        }
    }

    p->unk_1AC = p->unk_1AB;
    p->unk_1AE = p->unk_1AD;
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0807048C(EventCharaWork* p, void* a) {
    u16 keys = GetKeysHeld();

    if ((keys & DPAD_ANY) != 0) {
        p->unk_19C += 5;
    }

    switch (p->unk_1AF) {
    case 0:
        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 38);
            break;
        case 0x80:
            func_08070058(p, 44);
            break;
        case 0xC0:
            func_08070058(p, 56);
            break;
        case 0x40:
            func_08070058(p, 56);
            break;
        case 0xAD:
            func_08070058(p, 50);
            break;
        case 0x53:
            func_08070058(p, 50);
            break;
        case 0xD3:
            func_08070058(p, 62);
            break;
        case 0x2D:
            func_08070058(p, 62);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * (p->unk_19C >> 2) >> 8;
        p->unk_030 += -gSineTable[p->unk_1AB + 64] * (p->unk_19C >> 2) >> 8;

        if (p->unk_1A8 > 3) {
            p->unk_1AF = 1;
            p->unk_18C = -0x540;
            p->unk_198 = p->unk_034;
            p->unk_1A8 = 0;
        } else {
            p->unk_1A8++;
        }
        break;
    case 1:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 39);
            break;
        case 0x80:
            func_08070058(p, 45);
            break;
        case 0xC0:
            func_08070058(p, 57);
            break;
        case 0x40:
            func_08070058(p, 57);
            break;
        case 0xAD:
            func_08070058(p, 51);
            break;
        case 0x53:
            func_08070058(p, 51);
            break;
        case 0xD3:
            func_08070058(p, 63);
            break;
        case 0x2D:
            func_08070058(p, 63);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_18C += 51;
        p->unk_034 += p->unk_18C;

        if ((GetKeysHeld() & B_BUTTON) == 0) {
            p->unk_18C += 64;
        }

        if (p->unk_18C > -0x200) {
            p->unk_1AF = 2;
            p->unk_1A8 = 0;
        }
        break;
    case 2:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 40);
            break;
        case 0x80:
            func_08070058(p, 46);
            break;
        case 0xC0:
            func_08070058(p, 58);
            break;
        case 0x40:
            func_08070058(p, 58);
            break;
        case 0xAD:
            func_08070058(p, 52);
            break;
        case 0x53:
            func_08070058(p, 52);
            break;
        case 0xD3:
            func_08070058(p, 64);
            break;
        case 0x2D:
            func_08070058(p, 64);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_18C += 51;
        p->unk_034 += p->unk_18C;

        if ((GetKeysHeld() & B_BUTTON) == 0) {
            p->unk_18C += 64;
        }

        if (p->unk_18C > 0) {
            p->unk_1AF = 3;
            p->unk_1A8 = 0;
        }
        break;
    case 3:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 40);
            break;
        case 0x80:
            func_08070058(p, 46);
            break;
        case 0xC0:
            func_08070058(p, 58);
            break;
        case 0x40:
            func_08070058(p, 58);
            break;
        case 0xAD:
            func_08070058(p, 52);
            break;
        case 0x53:
            func_08070058(p, 52);
            break;
        case 0xD3:
            func_08070058(p, 64);
            break;
        case 0x2D:
            func_08070058(p, 64);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_034 += p->unk_18C;
        p->unk_18C += 51;

        if (p->unk_18C > 0x1FF) {
            p->unk_1AF = 4;
            p->unk_1A8 = 0;
        }
        break;
    case 4:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 41);
            break;
        case 0x80:
            func_08070058(p, 47);
            break;
        case 0xC0:
            func_08070058(p, 59);
            break;
        case 0x40:
            func_08070058(p, 59);
            break;
        case 0xAD:
            func_08070058(p, 53);
            break;
        case 0x53:
            func_08070058(p, 53);
            break;
        case 0xD3:
            func_08070058(p, 65);
            break;
        case 0x2D:
            func_08070058(p, 65);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_034 += p->unk_18C;
        p->unk_18C += 51;

        if (p->unk_034 > p->unk_198) {
            p->unk_034 = p->unk_198;
            p->unk_1AF = 5;
            p->unk_1A8 = 0;
        }
        break;
    case 5:
        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 42);
            break;
        case 0x80:
            func_08070058(p, 48);
            break;
        case 0xC0:
            func_08070058(p, 60);
            break;
        case 0x40:
            func_08070058(p, 60);
            break;
        case 0xAD:
            func_08070058(p, 54);
            break;
        case 0x53:
            func_08070058(p, 54);
            break;
        case 0xD3:
            func_08070058(p, 66);
            break;
        case 0x2D:
            func_08070058(p, 66);
            break;
        }

        p->unk_19C = 204 * p->unk_19C >> 8;

        if ((GetKeysPressed() & B_BUTTON) != 0) {
            p->unk_1AF = 1;
            p->unk_18C = -0x540;
        } else if (p->unk_1A8 > 10) {
            p->unk_1AC = 255;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080700D4);
        } else {
            p->unk_1A8++;
        }
        break;
    }

    TaskPoolUpdate(&p->tasks);
    return 1;
}
#ifdef VERSION_EU
#define MSG_SOUND_ID_9E 0x9C
#define MSG_SOUND_ID_B1 0xAF
#else
#define MSG_SOUND_ID_9E 0x9E
#define MSG_SOUND_ID_B1 0xB1
#endif

s32 func_08070AD4(EventCharaWork* p) {
    u16 x;
    u16 y;

    x = (p->unk_02C >> 8) - (gEventState->x >> 8);
    y = (p->unk_030 >> 8) + (p->unk_034 >> 8) - (gEventState->y >> 8);

    switch (p->keyframes[p->unk_1A0].unk_00) {
    case 0x2EB:
    case 0x2F1:
    case 0x2F2:
        if (p->unk_024 != MSG_SOUND_ID_9E) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 2) {
                    m4aSongNumStart(SONG_SND_958);
                    func_08076110(0x3BE, x, y);
                }
                if (p->anim->frame == 6) {
                    m4aSongNumStart(SONG_SND_959);
                    func_08076110(0x3BF, x, y);
                }
            }
        }
        break;
    case 0x2E6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN2_STONEL);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN2_STONER);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x375:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONEL);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONER);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x398:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_SND_373);
                func_08076110(0x175, x, y);
            }
        }
        break;
    case 0x399:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_SND_374);
                func_08076110(0x176, x, y);
            }
        }
        break;
    case 0x5E:
        if (p->anim->timer == 9) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_EV_EV01_01);
            }
        }
        break;
    case 0x1C2:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN2_STONEL);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_MAN2_STONER);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x1C0:
    case 0x1C1:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN2_STONEL);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_MAN2_STONER);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x34B:
    case 0x34C:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONEL);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONER);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x2B2:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONEL);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONER);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x204:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20A:
    case 0x20B:
    case 0x2C7:
    case 0x2C8:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(SONG_EV_SR_DIRTL);
                    func_08076110(0x384, x, y);
                } else {
                    m4aSongNumStart(SONG_EV_MAN_RMARBLEL);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->anim->frame == 7) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(SONG_EV_SR_DIRTR);
                    func_08076110(0x385, x, y);
                } else {
                    m4aSongNumStart(SONG_EV_MAN_RMARBLER);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0x2C5:
    case 0x2C6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(SONG_EV_SR_DIRTL);
                    func_08076110(0x384, x, y);
                } else {
                    m4aSongNumStart(SONG_EV_MAN_RMARBLEL);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->anim->frame == 5) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(SONG_EV_SR_DIRTR);
                    func_08076110(0x385, x, y);
                } else {
                    m4aSongNumStart(SONG_EV_MAN_RMARBLER);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0x371:
    case 0x372:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_EV_WOMAN_STONEL);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 7) {
                m4aSongNumStart(SONG_EV_WOMAN_STONER);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x1EE:
    case 0x1F6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN_STONEL);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_MAN_STONER);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x345:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x344:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x341:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 9) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x30C:
    case 0x30D:
    case 0x30E:
    case 0x30F:
    case 0x310:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 9) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x275:
    case 0x276:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_WOMAN_DIRT_L);
                func_08076110(0x3AE, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_WOMAN_DIRT_R);
                func_08076110(0x3AF, x, y);
            }
        }
        break;
    case 0x277:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_EV_WOMAN_DIRT_L);
                func_08076110(0x3AE, x, y);
            }
            if (p->anim->frame == 7) {
                m4aSongNumStart(SONG_EV_WOMAN_DIRT_R);
                func_08076110(0x3AF, x, y);
            }
        }
        break;
    case 0x2A5:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_EV_MAN2_DIRTL);
                func_08076110(0x3AA, x, y);
            }
            if (p->anim->frame == 7) {
                m4aSongNumStart(SONG_EV_MAN2_DIRTR);
                func_08076110(0x3AB, x, y);
            }
        }
        break;
    case 0x2A8:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN_DIRTL);
                func_08076110(0x3A0, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN_DIRTR);
                func_08076110(0x3A1, x, y);
            }
        }
        break;
    case 0x271:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN_STONEL);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_MAN_STONER);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x241:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN_MARBLEL);
                func_08076110(0x3A8, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_MAN_MARBLER);
                func_08076110(0x3A9, x, y);
            }
        }
        break;
    case 0x17A:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_STONEL);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_WOMAN_STONER);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x178:
    case 0x179:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_STONEL);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_WOMAN_STONER);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x19C:
    case 0x19D:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONEL);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONER);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x14A:
    case 0x14B:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_WOMAN2_DIRTL);
                func_08076110(0x3B6, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_WOMAN2_DIRTR);
                func_08076110(0x3B7, x, y);
            }
        }
        break;
    case 0x157:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_MAN_WOODL);
                func_08076110(0x3A6, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_MAN_WOODR);
                func_08076110(0x3A7, x, y);
            }
        }
        break;
    case 0x23E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN_RMARBLEL);
                func_08076110(0x3B2, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_MAN_RMARBLER);
                func_08076110(0x3B3, x, y);
            }
        }
        break;
    case 0x16C:
    case 0x16E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_MAN_DIRTL);
                func_08076110(0x3A0, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_MAN_DIRTR);
                func_08076110(0x3A1, x, y);
            }
        }
        break;
    case 0x122:
    case 0x123:
    case 0x128:
    case 0x129:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN_STONEL);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN_STONER);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0xDF:
    case 0xE0:
    case 0xE1:
    case 0xE2:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                if (p->unk_024 == 0x61) {
                    m4aSongNumStart(SONG_EV_WOMAN_DIRT_L);
                    func_08076110(0x3AE, x, y);
                } else {
                    m4aSongNumStart(SONG_EV_MAN_RMARBLEL);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->anim->frame == 5) {
                if (p->unk_024 == 0x61) {
                    m4aSongNumStart(SONG_EV_WOMAN_DIRT_R);
                    func_08076110(0x3AF, x, y);
                } else {
                    m4aSongNumStart(SONG_EV_MAN_RMARBLER);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0xD6:
    case 0xD9:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_WOMAN_STONEL);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_WOMAN_STONER);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0xCA:
    case 0xCB:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_SND_954);
                func_08076110(0x3BA, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_SND_955);
                func_08076110(0x3BB, x, y);
            }
        }
        break;
    case 0xD3:
    case 0xD4:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_SND_956);
                func_08076110(0x3BC, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_SND_957);
                func_08076110(0x3BD, x, y);
            }
        }
        break;
    case 0x10A:
    case 0x10B:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x83:
    case 0x88:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_EV_EV01_03);
                func_08076110(0x130, x, y);
            }
        }
        break;
    case 0x12:
    case 0x13:
    case 0x66:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_EV01_01);
                func_08076110(0x12E, x, y);
            }
        }
        break;
    case 0x5:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x9:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 1) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 5) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0x75:
    case 0x77:
    case 0x288:
    case 0x28C:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 2) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 6) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0x78:
    case 0x79:
    case 0x289:
    case 0x28D:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 3) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 7) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0x95:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x265:
    case 0x266:
    case 0x267:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 3) {
                    func_08072B4C((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 7) {
                    func_08072B4C((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 3) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 7) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0xB8:
    case 0xBA:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONEL);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONER);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0xBB:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_EV34_00);
                func_08076110(0x140, x, y);
            }
        }
        break;
    case 0xC1:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_CARDTHR);
                func_08076110(0x14E, x, y);
            }
        }
        break;
    case 0xE9:
    case 0xEA:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x144);
                func_08076110(0x144, x, y);
            }
        }
        break;
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF8:
    case 0xF9:
    case 0xFA:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_PI_FOOTR);
                func_08076110(0x39D, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_EV_PI_FOOTL);
                func_08076110(0x39C, x, y);
            }
        }
        break;
    case 0xF5:
    case 0xF6:
    case 0xF7:
    case 0xFB:
    case 0xFC:
    case 0xFD:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_PI_FOOTL);
                func_08076110(0x39C, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_EV_PI_FOOTR);
                func_08076110(0x39D, x, y);
            }
        }
        break;
    case 0x280:
    case 0x281:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 7) {
                m4aSongNumStart(SONG_EV_WOMAN_STONEL);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_STONER);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x18D:
    case 0x18E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN_STONEL);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN_STONER);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x18F:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 4) {
                m4aSongNumStart(SONG_BTL_GMIC_OK);
            }
        }
        break;
    case 0x159:
    case 0x15D:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_WOMAN_STONEL);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_STONER);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x15E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_CARDTHR);
                func_08076110(0x14E, x, y);
            }
        }
        break;
    case 0x185:
    case 0x186:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN_STONEL);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN_STONER);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x187:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 7) {
                m4aSongNumStart(SONG_EV_MAN_STONEL);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_EV_MAN_STONER);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x2E7:
    case 0x2E8:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_GE_ENTRY);
                func_08076110(0x155, x, y);
            }
        }
        break;
    case 0x2AE:
    case 0x2AF:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN2_STONEL);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN2_STONER);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x1C5:
    case 0x1C6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_MAN2_STONEL);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_MAN2_STONER);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x27A:
    case 0x27D:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONEL);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_EV_WOMAN_RSTONER);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x10F:
    case 0x11B:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x110:
    case 0x11C:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 5) {
                m4aSongNumStart(SONG_SYS_POO_FOOTL);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(SONG_SYS_POO_FOOTR);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x118:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_EV_AL_LAND);
                func_08076110(0x156, x, y);
            }
        }
        break;
    case 0x29E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(SONG_VO_GE_ATTACK02);
                func_08076110(0xC5, x, y);
            }
        }
        break;
    case 0x2A2:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(SONG_EV_GE_FOOTUP);
            }
        }
        break;
    case 0x1DE:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(SONG_BTL_DARKDEAD);
                func_08076110(0x227, x, y);
            }
        }
        break;
    }
}

void func_08072918(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gEventState->x >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gEventState->y >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(SONG_EV_SR_DIRTL);
            func_08076110(0x384, x, y);
        } else {
            m4aSongNumStart(SONG_EV_SR_DIRTR);
            func_08076110(0x385, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(SONG_EV_SR_STONER);
            func_08076110(0x389, x, y);
        } else {
            m4aSongNumStart(SONG_EV_SR_STONEL);
            func_08076110(0x388, x, y);
        }
        break;
    case 2:
        if ((a->unk_24 == 0x4B && gEventState->unk_6C > 0x2BC) || (a->unk_24 == 0x36 && gEventState->unk_6C <= 0x4F)) {
            if (flag != 0) {
                m4aSongNumStart(SONG_EV_SR_STONEL);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(SONG_EV_SR_STONER);
                func_08076110(0x389, x, y);
            }

            if (flag != 0) {
                m4aSongNumStart(SONG_EV_SR_STONEL);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(SONG_EV_SR_STONER);
                func_08076110(0x389, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(SONG_EV_SR_MUDL);
                func_08076110(0x38C, x, y);
            } else {
                m4aSongNumStart(SONG_EV_SR_MUDR);
                func_08076110(0x38D, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(SONG_EV_SR_STONEL);
            func_08076110(0x388, x, y);
        } else {
            m4aSongNumStart(SONG_EV_SR_STONER);
            func_08076110(0x389, x, y);
        }
        break;
    }
}

void func_08072A64(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gEventState->x >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gEventState->y >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(SONG_EV_DL_DIRTL);
            func_08076110(0x394, x, y);
        } else {
            m4aSongNumStart(SONG_EV_DL_DIRTR);
            func_08076110(0x395, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(SONG_EV_DL_STONE_R);
            func_08076110(0x391, x, y);
        } else {
            m4aSongNumStart(SONG_EV_DL_STONE_L);
            func_08076110(0x390, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gEventState->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(SONG_EV_DL_STONE_R);
                func_08076110(0x391, x, y);
            } else {
                m4aSongNumStart(SONG_EV_DL_STONE_L);
                func_08076110(0x390, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(SONG_EV_DL_MUDL);
                func_08076110(0x398, x, y);
            } else {
                m4aSongNumStart(SONG_EV_DL_MUDR);
                func_08076110(0x399, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(SONG_EV_DL_STONE_L);
            func_08076110(0x390, x, y);
        } else {
            m4aSongNumStart(SONG_EV_DL_STONE_R);
            func_08076110(0x391, x, y);
        }
        break;
    }
}

void func_08072B4C(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gEventState->x >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gEventState->y >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(SONG_EV_GF_DIRTL);
            func_08076110(0x396, x, y);
        } else {
            m4aSongNumStart(SONG_EV_GF_DIRTR);
            func_08076110(0x397, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(SONG_EV_GF_STONE_R);
            func_08076110(0x393, x, y);
        } else {
            m4aSongNumStart(SONG_EV_GF_STONE_L);
            func_08076110(0x392, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gEventState->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(SONG_EV_GF_STONE_R);
                func_08076110(0x393, x, y);
            } else {
                m4aSongNumStart(SONG_EV_GF_STONE_L);
                func_08076110(0x392, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(SONG_EV_GF_MUDL);
                func_08076110(0x39A, x, y);
            } else {
                m4aSongNumStart(SONG_EV_GF_MUDR);
                func_08076110(0x39B, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(SONG_EV_GF_STONE_L);
            func_08076110(0x392, x, y);
        } else {
            m4aSongNumStart(SONG_EV_GF_STONE_R);
            func_08076110(0x393, x, y);
        }
        break;
    }
}

void func_08072C34(EventCharaWork* p) {
    switch (p->unk_026) {
    case 6:
    case 16:
    case 20:
    case 21:
    case 22:
    case 32:
        p->unk_03C |= 8;
        break;
    case 37:
        CreateTinkerbellTask(p);
    case 8:
    case 10:
    case 33:
    case 38:
    case 39:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
        p->unk_03C |= 0x10;
        break;
    case 0:
        break;
    }
}
#ifdef VERSION_EU
#define MSG_WIN_ID_A 0x84
#define MSG_WIN_ID_B 0x9A
#else
#define MSG_WIN_ID_A 0x86
#define MSG_WIN_ID_B 0x9C
#endif

static void msgwin_0(MsgWinWork* p, u8* arg) {
    EventSequenceDef* t;

    p->unk_28 = arg[0];

    switch (p->unk_28) {
    case 11:
        p->unk_1C = func_08064D04(0);
        break;
    case 3:
    case MSG_WIN_ID_A:
    case MSG_WIN_ID_B:
        p->unk_1C = func_08064C34(0);
        break;
    default:
        p->unk_1C = func_08064B80(0);
        break;
    }

    if (gUnk_09EE3CA0[p->unk_28] != NULL) {
        p->bg = 0;
    } else {
        p->bg = 2;
    }
    LoadBgTiles(p->bg, gUnk_094233B8, 0x500);
    LoadBgPalette(p->bg, gUnk_096148D8, 32);
    LoadBgMap(p->bg, gUnk_08125E24, 0x800);
    SetBgPriority(p->bg, 0);
    t = gUnk_09EE3FB4[p->unk_28];
    p->palette = NULL;
    p->unk_1E = 0;
    p->unk_24 = 0;
    p->unk_25 = 0;
    p->unk_26 = 0;
    p->unk_27 = 0;
    p->unk_29 = 0;
    p->unk_2A = 0;
    p->script = t->script;
    p->unk_2B = 0;
    p->unk_18 = 0;
    p->unk_40 = 0;
    gEventState->unk_81 = 0;
    gEventState->unk_7D = 0;
    gEventState->unk_8B = 0;
    TaskPoolInit(p, 2);
    CreateMsgfaceTask(p, &p->face, p->script->portraitId, p->script->expressionId, p->script->positionIndex);
}

static u8 msgwin_1(MsgWinWork* p, void* a) {
    const MessageScriptEntry* e;

    if (p->unk_29 == 0) {
        if (gEventState->unk_80 == 0) {
            func_08073508(p);
        }
    } else {
        func_080736F8(p);
    }

    if (p->unk_2A != 0) {
        gEventState->unk_87 = p->unk_20;

        if (gEventState->unk_7C != 0) {
            if (gEventState->unk_89 != 0) {
                gEventState->unk_89--;
            } else {
                e = &p->script[p->unk_27];

                if (e->portraitId == 62) {
                    void* pal;

                    pal = (void*)0x050001E0;
                    LoadBgTiles(p->bg, gUnk_0950E2F8, 0x140);
                    LoadBgMap(p->bg, gUnk_096112B8, 0x800);
                    LoadPalette(gUnk_09611AB8, pal, 32);

                    if ((e->flags & 0x80) != 0) {
                        FadeSetPaletteExcluded(15, 1);
                    }
                    gEventState->unk_81 = 1;

                    switch (e->positionIndex) {
                    case 0:
                    case 2:
                        SetBgScroll(p->bg, (u16)-0x28, 0);
                        break;
                    case 1:
                    case 3:
                        SetBgScroll(p->bg, (u16)-0x28, (u16)-0x60);
                        break;
                    }

                    if (p->palette == NULL) {
                        p->palette = LoadObjPalette(gUnk_09614718, 32);

                        if ((e->flags & 0x80) != 0) {
                            FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
                        }
                    }
                    _08073E6C(&p->face);
                    SetTaskUpdate(a, (TaskUpdateFunc)func_08073294);
                    gEventState->unk_8B = 1;
                } else {
                    LoadBgTiles(p->bg, gUnk_094233B8, 0x500);
                    LoadBgPalette(p->bg, gUnk_096148D8, 32);
                    SetBgMapBlocks(p->bg, gUnk_09EE4724[p->unk_20], 2, 1);
                    RedrawBgMapAt(p->bg, p->unk_18, 0);
                    SetTaskUpdate(a, (TaskUpdateFunc)func_08073294);
                    _08073E6C(&p->face);
                    gEventState->unk_81 = 1;

                    if (p->palette != NULL) {
                        ReleaseObjPalette(p->palette);
                        p->palette = NULL;
                    }
                    gEventState->unk_8B = 0;
                }
            }
        } else {
        e = &p->script[p->unk_27];

        if (e->portraitId == 62) {
            void* pal;

            pal = (void*)0x050001E0;
            LoadBgTiles(p->bg, gUnk_0950E2F8, 0x140);
            LoadBgMap(p->bg, gUnk_096112B8, 0x800);
            LoadPalette(gUnk_09611AB8, pal, 32);

            if ((e->flags & 0x80) != 0) {
                FadeSetPaletteExcluded(15, 1);
            }
            gEventState->unk_81 = 1;

            switch (e->positionIndex) {
            case 0:
            case 2:
                SetBgScroll(p->bg, (u16)-0x18, 0);
                break;
            case 1:
            case 3:
                SetBgScroll(p->bg, (u16)-0x18, (u16)-0x60);
                break;
            }

            if (p->palette == NULL) {
                p->palette = LoadObjPalette(gUnk_09614718, 32);

                if ((e->flags & 0x80) != 0) {
                FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
                }
            }
            _08073E6C(&p->face);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08073294);
            gEventState->unk_8B = 1;
        } else {
            LoadBgTiles(p->bg, gUnk_094233B8, 0x500);
            LoadBgPalette(p->bg, gUnk_096148D8, 32);
            SetBgMapBlocks(p->bg, gUnk_09EE4724[p->unk_20], 2, 1);
            RedrawBgMapAt(p->bg, p->unk_18, 0);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08073294);
            _08073E6C(&p->face);
            gEventState->unk_81 = 1;

            if (p->palette != NULL) {
                ReleaseObjPalette(p->palette);
                p->palette = NULL;
            }
            gEventState->unk_8B = 0;
        }
        }
    }

    if (gEventState->unk_82 == 1) {
        FadeSetPaletteExcluded(p->unk_1C + 16, 0);
        FadeSetPaletteExcluded(14, 0);
    } else {
        FadeSetPaletteExcluded(p->unk_1C + 16, 1);
        FadeSetPaletteExcluded(14, 1);
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_08073170(MsgWinWork* p, void* a) {
    if (p->unk_29 == 0) {
        if (gEventState->unk_80 == 0) {
            func_08073508(p);
        }
    } else {
        func_080736F8(p);
    }

    if (p->unk_2A != 0) {
        gEventState->unk_87 = p->unk_20;

        if (gEventState->unk_7C != 0) {
            if (gEventState->unk_89 != 0) {
                gEventState->unk_89--;
            } else {
                SetTaskUpdate(a, (TaskUpdateFunc)func_08073294);
                _08073E6C(&p->face);
                gEventState->unk_81 = 1;
            }
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)func_08073294);
            _08073E6C(&p->face);
            gEventState->unk_81 = 1;
        }
    }

    if (gEventState->unk_82 == 1) {
        FadeSetPaletteExcluded(p->unk_1C + 16, 0);
        FadeSetPaletteExcluded(14, 0);
    } else {
        FadeSetPaletteExcluded(p->unk_1C + 16, 1);
        FadeSetPaletteExcluded(14, 1);
    }
    TaskPoolUpdate(p);
    return 1;
}
static void msgwin_2(MsgWinWork* p) {
    const MessageScriptEntry* e = &p->script[p->unk_27];

    if (e->portraitId != 62) {
        func_080658B8(p->unk_24);
    } else {
        _0806C3A0(p->unk_24, p->palette);
    }
    TaskPoolDraw(p);
}
static void msgwin_3(MsgWinWork* p) {
    if (p->palette != NULL) {
        ReleaseObjPalette(p->palette);
    }
    func_08065940();
    TaskPoolDestroy(p);
}
u8 func_08073294(MsgWinWork* p, void* a) {
    const MessageScriptEntry* e = &p->script[p->unk_27];

    ApproachValue(&p->unk_18, gUnk_09033CA0[p->unk_20], p->unk_1E);

    if (e->portraitId != 62) {
        ScrollBgMapTo(p->bg, p->unk_18, 0);
    }

    if (p->unk_1E != 0) {
        p->unk_1E--;
    } else {
        p->unk_1E = 0;

        if ((e->flags & 0xF) == 0) {
            gEventState->unk_7B = 1;
        }
        SetTaskUpdate(a, (TaskUpdateFunc)func_08073318);
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_08073318(MsgWinWork* p, void* a) {
    const MessageScriptEntry* e = &p->script[p->unk_27];

    func_0807361C(p);

    if (e->portraitId == 62) {
        p->unk_24 = p->unk_26;
    } else if (GetKeysPressed() & A_BUTTON) {
        if (p->unk_24 < p->unk_26) {
            p->unk_24 = p->unk_26;
        }
    }

    if (p->unk_2B == 1 && gEventState->unk_7D == 0) {
        s32 text = p->unk_40;
        if (text != 0) {
            p->unk_1E = 0;
            p->unk_29 = 0;
            p->unk_2A = 1;
            p->face.unk_08 = 1;
            SetTaskUpdate(a, (TaskUpdateFunc)func_08073170);
        } else {
            _08065994();

            if ((e->flags & 0x8000) == 0) {
                if (p->script[p->unk_27 + 1].positionIndex != 4) {
                    p->unk_1E = 8;
                    func_08073E74(&p->face);
                    SetTaskUpdate(a, (TaskUpdateFunc)func_0807344C);
                    gEventState->unk_81 = text;
                    p->face.unk_08 = text;
                } else {
                    p->unk_1E = text;
                    p->unk_29 = text;
                    p->unk_2A = text;
                    p->unk_27++;
                    gEventState->flags &= ~1;
                    p->face.unk_08 = 1;
                    SetTaskUpdate(a, (TaskUpdateFunc)msgwin_1);
                }
            } else {
                p->unk_1E = 8;
                func_08073E74(&p->face);
                SetTaskUpdate(a, (TaskUpdateFunc)func_0807344C);
                gEventState->unk_81 = text;
                p->face.unk_08 = text;
            }
        }
        p->unk_2B = 0;
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_0807344C(MsgWinWork* p, void* a) {
    const MessageScriptEntry* e = &p->script[p->unk_27];

    ApproachValue(&p->unk_18, gUnk_09033C98[p->unk_20], p->unk_1E);

    if (e->portraitId != 62) {
        ScrollBgMapTo(p->bg, p->unk_18, 0);
    } else {
        DisableBg(p->bg);
    }

    if (p->unk_1E != 0) {
        p->unk_1E--;
    } else {
        p->unk_1E = 0;

        if ((gEventState->flags & 4) == 0) {
            gEventState->flags &= ~1;
        }
        gEventState->unk_7C = 0;

        if ((e->flags & 0x8000) == 0) {
            p->unk_2A = 0;
            p->unk_29 = 0;
            p->unk_27++;
            SetTaskUpdate(a, (TaskUpdateFunc)msgwin_1);
        }
    }
    TaskPoolUpdate(p);
    return 1;
}
void func_08073508(MsgWinWork* p) {
    const MessageScriptEntry* e = &p->script[p->unk_27];
    s32 n;

    n = e->positionIndex;

    if (n != 4) {
        p->unk_20 = n;
        p->unk_18 = gUnk_09033C98[n];
    }

    if ((e->flags & 0x20) != 0) {
        p->face.unk_03 = 1;
    } else {
        p->face.unk_03 = 0;
    }
    func_08073E34(&p->face, e->portraitId, e->expressionId, p->unk_20);

#ifdef VERSION_JP
    if (e->portraitId == 62) {
        p->unk_26 = func_080653D4(0x2E00, gUnk_09033CB8[p->unk_20], (u8*)e->unk_10);
    } else {
        p->unk_26 = func_080653D4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20], (u8*)e->unk_10);
    }
#else
    if (e->portraitId == 62) {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, LANGSTR(e->unk_10), &p->unk_40);
        }
    } else {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, LANGSTR(e->unk_10), &p->unk_40);
        }
    }
#endif
    p->unk_25 = 0;
    p->unk_24 = 0;
    p->unk_29 = 1;
}

void func_0807361C(MsgWinWork* p) {
    const MessageScriptEntry* e = &p->script[p->unk_27];
    u8 v;

    if (p->unk_25 >= e->unk_0C) {
        if (p->unk_24 < p->unk_26) {
            p->unk_24++;
            m4aSongNumStart(SONG_SYS_MESSAGE);
        } else {
            gEventState->unk_7B = 0;

            if (p->unk_2B == 0) {
                if ((p->script[p->unk_27].flags & 0x8000) == 0) {
                    if ((p->script[p->unk_27].flags & 0x40) == 0) {
                        TaskCreate(p, &gTaskDescMsgface[1], &p->script[p->unk_27 + 1].positionIndex);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], &p->script[p->unk_27 + 1].positionIndex);
                    }
                } else {
                    v = 0;

                    if ((p->script[p->unk_27].flags & 0x40) == 0) {
                        TaskCreate(p, &gTaskDescMsgface[1], &v);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], &v);
                    }
                }
                p->unk_2B = 1;
            }
        }
        p->unk_25 = 0;
    } else {
        p->unk_25++;
    }
}
void func_080736F8(MsgWinWork* p) {
    const MessageScriptEntry* e = &p->script[p->unk_27];

    if (gEventState->unk_6C >= e->unk_16) {
        if (p->unk_2A == 0) {
            gEventState->flags |= 1;
            p->unk_2A = 1;
            p->unk_1E = 8;

            if ((e->flags & 0x10) != 0) {
                gEventState->unk_7C = 1;
                gEventState->unk_88 = e->portraitId;
                gEventState->unk_89 = 32;
            } else {
                gEventState->unk_7C = 0;
            }
        }
    }
}
void msgface_0(MsgFaceWork* p, MsgFaceControl* ctl) {
    const MsgFaceAnim* anim;
    u32 n;

    p->tiles = AllocObjTiles(0x12C0, 0);
    p->palette = AllocObjPalette(32);
    p->face = ctl;
    p->unk_30 = 0;
    p->x = gUnk_09033CD0[n = p->face->positionIndex];
    p->y = gUnk_09033CF0[n];
    p->scaleX = 0x100;
    p->unk_31 = 0;
    p->unk_32 = 0;
    p->unk_34 = 1;

    if (p->face->portraitId != 62) {
        anim = gMsgFaceAnims[p->face->portraitId];
    } else {
        anim = gMsgFaceAnims[0];
    }

    if (p->face->positionIndex <= 1) {
        p->unk_33 = 1;
    } else if (p->face->positionIndex <= 3) {
        p->unk_33 = 0;
    }

    if (p->face->portraitId != 62) {
        SetObjTileSource(p->tiles, anim[p->face->expressionId].tiles);
        UpdateAllocatedObjPalette(p->palette, anim[p->face->expressionId].palette);
        AnimInit(p->anim, anim[p->face->expressionId].anims, anim[p->face->expressionId].gfxTable);
        AnimStart(p->anim, 0, anim[p->face->expressionId].unk_11);
        p->gfx = AnimGetGfx(p->anim);
    } else {
        SetObjTileSource(p->tiles, anim->tiles);
        UpdateAllocatedObjPalette(p->palette, anim->palette);
        AnimInit(p->anim, anim->anims, anim->gfxTable);
        AnimStart(p->anim, 0, anim->unk_11);
        p->gfx = AnimGetGfx(p->anim);
    }
}
u8 msgface_1(MsgFaceWork* p, void* a) {
    const MsgFaceAnim* anim = NULL;
    u32 n;

    if (p->face->portraitId != 62) {
        anim = gMsgFaceAnims[p->face->portraitId];
        p->unk_34 = 1;
    } else {
        p->unk_34 = 0;
    }

    switch (p->face->command) {
    case 1:
        if (p->face->unk_08 == 0) {
            p->x = gUnk_09033CD0[n = p->face->positionIndex];
            p->y = gUnk_09033CF0[n];
        }
        p->unk_30 = 8;

        if (anim != NULL) {
            if (p->face->unk_03 == 1) {
                UpdateAllocatedObjPalette(p->palette, &gUnk_096148D8[0x100]);
            } else {
                UpdateAllocatedObjPalette(p->palette, anim[p->face->expressionId].palette);
            }
        }

        SetTaskUpdate(a, (TaskUpdateFunc)func_08073B04);
        break;
    case 2:
        p->unk_30 = 8;
        p->unk_31 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08073B54);
        break;
    case 4:
        p->unk_30 = 4;

        if (p->face->positionIndex <= 1) {
            p->scaleX = -255;
        } else if (p->face->positionIndex <= 3) {
            p->scaleX = 256;
        }

        p->y = gUnk_09033CF0[p->face->positionIndex];
        SetTaskUpdate(a, (TaskUpdateFunc)func_08073CA4);
        break;
    case 3:
        SetTaskUpdate(a, (TaskUpdateFunc)func_08073B9C);
        break;
    }

    if (gEventState->unk_7B == 1) {
        if (p->unk_32 == 0) {
            if (anim != NULL && anim[p->face->expressionId].unk_10 > 1) {
                AnimStart(p->anim, 1, anim[p->face->expressionId].unk_11);
            }

            p->unk_32 = 1;
        }
    } else {
        if (p->unk_32 == 1) {
            if (anim != NULL) {
                AnimStart(p->anim, 0, anim[p->face->expressionId].unk_11);
            }

            p->unk_32 = 0;
        }
    }

    if (gEventState->unk_82 == 1) {
        FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 0);
    } else {
        FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
    }

    p->gfx = AnimUpdate(p->anim);
    return 1;
}
void msgface_2(MsgFaceWork* p) {
    s32 t;
    u8 v;

    if (p->unk_34 != 0) {
        t = AllocObjAffine(0, p->scaleX, 256, 0);
        if (t != 0) {
            DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, t, 0, 50);
        } else {
            v = p->unk_33;
            if (v != 0) {
                DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, t, 1, 50);
            } else {
                DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, v, v, 50);
            }
        }
    }
}
void msgface_3(MsgFaceWork* p) {
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
u8 func_08073B04(MsgFaceWork* p, void* a) {
    ApproachValue(&p->x, gUnk_09033CE0[p->face->positionIndex], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->face->command = 0;
        p->unk_31 = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)msgface_1);
    }
    return 1;
}
u8 func_08073B54(MsgFaceWork* p, void* a) {
    ApproachValue(&p->x, gUnk_09033CD0[p->face->positionIndex], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->face->command = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)msgface_1);
    }
    return 1;
}
u8 func_08073B9C(MsgFaceWork* p, void* a) {
    const MsgFaceAnim* t;
    s32 n;

    t = NULL;

    if (p->face->portraitId != 62) {
        t = gMsgFaceAnims[p->face->portraitId];
        p->unk_34 = 1;
    } else {
        p->unk_34 = 0;
    }

    if (p->face->positionIndex <= 1) {
        p->unk_33 = 1;
    } else if (p->face->positionIndex <= 3) {
        p->unk_33 = 0;
    }

    if (t != NULL) {
        SetObjTileSource(p->tiles, t[p->face->expressionId].tiles);
        UpdateAllocatedObjPalette(p->palette, t[p->face->expressionId].palette);
        AnimInit(p->anim, t[p->face->expressionId].anims, t[p->face->expressionId].gfxTable);
        AnimStart(p->anim, 0, t[p->face->expressionId].unk_11);
        p->gfx = AnimGetGfx(p->anim);
        p->unk_31 = 0;
        p->unk_30 = 8;
        p->face->command = 0;
    }
    p->x = gUnk_09033CD0[n = p->face->positionIndex];
    p->y = gUnk_09033CF0[n];
    p->scaleX = 256;
    p->unk_30 = 8;
    SetTaskUpdate(a, (TaskUpdateFunc)msgface_1);
    return 1;
}

u8 func_08073CA4(MsgFaceWork* p, void* a) {
    const MsgFaceAnim* t;

    if (p->scaleX < 0) {
        ApproachValue(&p->scaleX, -2, p->unk_30);
    } else {
        ApproachValue(&p->scaleX, 2, p->unk_30);
    }
    p->unk_30--;

    if (p->unk_30 == 0) {
        t = NULL;

        if (p->face->portraitId != 62) {
            t = gMsgFaceAnims[p->face->portraitId];
        }

        if (p->face->positionIndex <= 1) {
            p->unk_33 = 1;
        } else if (p->face->positionIndex <= 3) {
            p->unk_33 = 0;
        }

        if (t != NULL) {
            SetObjTileSource(p->tiles, t[p->face->expressionId].tiles);
            UpdateAllocatedObjPalette(p->palette, t[p->face->expressionId].palette);
            AnimInit(p->anim, t[p->face->expressionId].anims, t[p->face->expressionId].gfxTable);
            AnimStart(p->anim, 0, t[p->face->expressionId].unk_11);
            p->gfx = AnimGetGfx(p->anim);
            p->unk_31 = 0;
            p->unk_30 = 8;
        }
        SetTaskUpdate(a, (TaskUpdateFunc)func_08073DA4);
    }
    return 1;
}

u8 func_08073DA4(MsgFaceWork* p, void* a) {
    if (p->scaleX < 0) {
        ApproachValue(&p->scaleX, -255, p->unk_30);
    } else {
        ApproachValue(&p->scaleX, 256, p->unk_30);
    }
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->unk_31 = 1;
        p->face->command = 0;
        p->scaleX = 256;
        SetTaskUpdate(a, (TaskUpdateFunc)msgface_1);
    }
    return 1;
}
void CreateMsgfaceTask(void* pool, MsgFaceControl* p, u8 a, u8 b, u8 c) {
    p->portraitId = a;
    p->expressionId = b;
    p->positionIndex = c;
    p->command = 0;
    p->unk_03 = 0;
    TaskCreate(pool, &gTaskDescMsgface[0], p);
}

void func_08073E34(MsgFaceControl* p, u8 a, u8 b, u8 c) {
    u8 v;

    if (p->portraitId != a) {
        v = 3;
    } else {
        if (p->expressionId == b && p->positionIndex == c) {
            return;
        }
        v = 4;
    }
    p->command = v;
    p->portraitId = a;
    p->expressionId = b;
    p->positionIndex = c;
}

void _08073E6C(MsgFaceControl* p) {
    p->command = 1;
}
void func_08073E74(MsgFaceControl* p) {
    p->command = 2;
}
void msgwait_0(MsgWaitWork* p, u8* arg) {
    p->unk_103 = arg[0];
    p->tiles = AllocObjTiles(64, 0);
    p->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(p->palette->index, gUnk_08F69BA4);
    FadeSetPaletteExcluded(p->palette->index + 16, 1);
    SetObjTileSource(p->tiles, gUnk_09320796);
    AnimInit(p->unk_DC, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(p->unk_DC, 2, 1);
    p->timer = 0;
    gEventState->unk_7D = 1;
}
u8 msgwait_1(MsgWaitWork* p, void* a) {
    p->gfx = AnimUpdate(p->unk_DC);

    if (GetKeysPressed() & A_BUTTON) {
        AnimStart(p->unk_DC, 3, 1);

        if (p->unk_103 == 4) {
            gEventState->unk_7D = 0;
            m4aSongNumStart(SONG_SYS_KETTEI);
            return 0;
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)func_08073F78);
            m4aSongNumStart(SONG_SYS_KETTEI);
        }
    }
    return 1;
}
u8 func_08073F78(MsgWaitWork* p) {
    u8 r;

    p->gfx = AnimUpdate(p->unk_DC);
    p->timer++;
    if (p->timer <= 15) {
        r = 1;
    } else {
        gEventState->unk_7D = 0;
        r = 0;
    }
    return r;
}
void msgwait_2(MsgWaitWork* p) {
    u8 v = gEventState->unk_8B;

    if (v != 0) {
        DrawSprite(120, gUnk_09033D08[gEventState->unk_87][1] >> 8, p->gfx,
                   p->tiles, p->palette, 0, 0, 0);
    } else {
        DrawSprite(gUnk_09033D08[gEventState->unk_87][0] >> 8,
                   gUnk_09033D08[gEventState->unk_87][1] >> 8, p->gfx, p->tiles,
                   p->palette, 0, 0, 0);
    }
}
void msgwait_3(MsgWaitWork* p) {
    FadeSetPaletteExcluded(p->palette->index + 16, 0);
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
void msgwait_yesno_0(MsgWaitYesNoWork* p, u8* a) {
    p->unk_103 = *a;
    p->tiles = AllocObjTiles(64, 0);
    p->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(((ObjPalette*)p->palette)->index, gUnk_08F69BA4);
    FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
    SetObjTileSource(p->tiles, gUnk_09320796);
    AnimInit((AnimState*)p->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart((AnimState*)p->anim, 2, 1);
    p->unk_102 = 0;
    p->tiles2 = AllocObjTiles(288, 0);
    p->palette2 = LoadObjPalette(gUnk_09614418, 32);
    LoadObjPaletteBank(((ObjPalette*)p->palette2)->index, gUnk_09614418);
    SetObjTileSource(p->tiles2, gUnk_090A4664);
    AnimInit((AnimState*)p->anim2, gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)p->anim2, 2, 1);
    p->gfx2 = AnimGetGfx((AnimState*)p->anim2);
    p->tiles3 = LoadObjTiles(gUnk_093F7C9C, 4032);
    p->palette3 = LoadObjPalette(gUnk_09611AB8, 32);
    LoadObjPaletteBank(((ObjPalette*)p->palette3)->index, gUnk_09611AB8);
    FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
    InitTextSlots(p->textSlots, 10);
    InitTextSlots(p->textSlots2, 10);
    p->palette4 = _08066468(1);
#ifdef VERSION_EU
    p->textSlotCount = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), p->textSlots);
    p->textSlotCount2 = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), p->textSlots2);
#else
    p->textSlotCount = LoadTextSlots(gUnk_08159E10, p->textSlots);
    p->textSlotCount2 = LoadTextSlots(gUnk_08159E18, p->textSlots2);
#endif
    p->x = 0x5800;
    p->unk_100 = 1;
    p->y = gUnk_09033D28[1];
    p->unk_102 = 0;
    gEventState->unk_7D = 1;
    gEventState->unk_85 = 1;
    gEventState->unk_84 = 0;
    p->unk_104 = 0;
}
u8 func_0807420C(MsgWaitYesNoWork* p, void* a) {
    switch (GetKeysPressed()) {
    case DPAD_UP:
        if (p->unk_100 != 0) {
            p->unk_100--;
            m4aSongNumStart(SONG_SYS_CLICK);
        }
        p->unk_102 = 1;
        break;
    case DPAD_DOWN:
        if (p->unk_100 == 0) {
            p->unk_100++;
            m4aSongNumStart(SONG_SYS_CLICK);
        }
        p->unk_102 = 1;
        break;
    case A_BUTTON:
    case START_BUTTON:
        if (p->unk_100 == 0) {
            gEventState->unk_84 = 1;
        } else {
            gEventState->unk_84 = 0;

            if (gEventState->unk_74 == 68) {
                gEventState->unk_83 = 1;
                gEventState->unk_8A = 255;
            }
        }
        m4aSongNumStart(SONG_SYS_KETTEI);
        gEventState->unk_7D = 0;
        return 0;
    case B_BUTTON:
        gEventState->unk_84 = 0;

        if (gEventState->unk_74 == 68) {
            gEventState->unk_83 = 1;
            gEventState->unk_8A = 255;
        }
        m4aSongNumStart(SONG_SYS_KETTEI);
        gEventState->unk_7D = 0;
        return 0;
    }

    if (p->unk_102 != 0) {
        ApproachValue(&p->y, gUnk_09033D28[p->unk_100], p->unk_102);
        p->unk_102--;
    }
    p->gfx = AnimUpdate(p->anim);
    return 1;
}
u8 msgwait_yesno_1(MsgWaitYesNoWork* p, void* a) {
    p->gfx = AnimUpdate(p->anim);

    if (GetKeysPressed() & A_BUTTON) {
        AnimStart(p->anim, 3, 1);
        p->unk_104 = 1;
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807420C);
    }
    return 1;
}
void msgwait_yesno_2(MsgWaitYesNoWork* p) {
    switch (p->unk_104) {
    case 0:
        if (gEventState->unk_8B != 0) {
            DrawSprite(120, gUnk_09033D08[gEventState->unk_87][1] >> 8, p->gfx, p->tiles, p->palette, 0, 0, 0);
        } else {
            DrawSprite(gUnk_09033D08[gEventState->unk_87][0] >> 8, gUnk_09033D08[gEventState->unk_87][1] >> 8, p->gfx, p->tiles, p->palette, 0, 0, 0);
        }
        break;
    case 1:
        DrawSprite(120, 80, gUnk_09EF126C[1], p->tiles3, p->palette3, 0, 0, 10);
        DrawSprite(p->x >> 8, p->y >> 8, p->gfx2, p->tiles2, p->palette2, 0, 1, 9);
        DrawTextSlots((240 - GetTextSlotsWidth(p->textSlots, p->textSlotCount)) >> 1, 67, p->textSlots, p->palette4, 0, p->textSlotCount);
        DrawTextSlots((240 - GetTextSlotsWidth(p->textSlots2, p->textSlotCount2)) >> 1, 82, p->textSlots2, p->palette4, 0, p->textSlotCount2);
        break;
    }
}
void msgwait_yesno_3(MsgWaitYesNoWork* p) {
    ReleaseObjTiles(p->tiles2);
    ReleaseObjTiles(p->tiles3);
    ReleaseObjPalette(p->palette3);
    ReleaseObjPalette(p->palette2);
    ReleaseObjPalette(p->palette4);
    FreeTextSlots(p->textSlots, 10);
    FreeTextSlots(p->textSlots2, 10);
}
void HBlankIntrEventScanlineScroll(void) {
    vu16 v;

    v = REG_VCOUNT;
    v = (v + 1) % 228;

    if (v < 160) {
        if (gEventScanlineScroll->enabled == 1) {
            REG_BG2HOFS = gEventScanlineScroll->scrollX[v];
            REG_BG3HOFS = gEventScanlineScroll->scrollX[v];
        }
    }
}
void func_08074564(void) {
    gIntrCheck |= 2;
    HBlankIntrEventScanlineScroll();
}
void view_0(EventCameraWork* p, u8* arg) {
    EventSequenceDef* t;
    EventBackgroundDef* u;
    const EventCameraKeyframe* q;
    u8 n;

    gEventScanlineScroll = (EventScanlineScroll*)p->unk_18;
    p->wavePhase = 0;
    p->waveEnabled = 0;
    p->unk_08 = arg[0];
    p->unk_09 = 0;
    p->unk_10 = 0;
    p->angle = 0;
    p->unk_14 = 0;
    p->unk_15 = 0;
    t = gUnk_09EE3FB4[p->unk_08];
    u = gUnk_09EE3CA0[p->unk_08];
    q = t->keyframes;
    p->keyframes = q;

    if (q->unk_10 != 255) {
        n = func_08074E40(p);
        q = (EventCameraKeyframe*)gEventState->unk_00[n];
        p->unk_00 = q->unk_04;
        p->unk_04 = q->unk_08;
    } else {
        p->unk_00 = q->unk_04;
        p->unk_04 = q->unk_08;
    }
    gEventState->unk_48 = p->unk_00 - 0x7800;
    gEventState->unk_4C = p->unk_04 - 0x5000;
    gEventState->unk_50 = p->unk_00;
    gEventState->unk_54 = p->unk_04;
    gEventState->unk_68 = 0;
    gEventState->unk_6A = 0;

    if (u != NULL) {
        if (u->unk_24 != 0) {
            SetBgAffine(2, 0, 0x100, 0x100, gEventState->unk_50, gEventState->unk_54);
        } else {
            if (p->unk_08 == 77) {
                ScrollBgMapTo(3, (gEventState->unk_48 >> 8) + 8 + gEventState->unk_68, (gEventState->unk_4C >> 8) + 40);
            } else {
                ScrollBgMapTo(3, (gEventState->unk_48 >> 8) + gEventState->unk_68, gEventState->unk_4C >> 8);
            }

            if (gEventState->unk_78 != 0) {
                ScrollBgMapTo(2, (gEventState->unk_48 >> 8) + gEventState->unk_68, gEventState->unk_4C >> 8);
            }

            if (gEventState->unk_79 != 0) {
                ScrollBgMapTo(1, (gEventState->unk_48 >> 8) + gEventState->unk_68, gEventState->unk_4C >> 8);
            }
        }
    }
}

void func_080746D8(void) {
    u8 i;

    for (i = 0; i < 16; i++) {
        FadeSetPaletteExcluded(i + 16, 0);
    }
}

#ifdef VERSION_EU
#define MSG_VIEW_ID_B4 0xB2
#else
#define MSG_VIEW_ID_B4 0xB4
#endif

u8 view_1(EventCameraWork* p, u8* task) {
    EventBackgroundDef* u = gUnk_09EE3CA0[p->unk_08];
    const EventCameraKeyframe* e;
    Ent08074EC8* q;
    u8 n;

    if (gEventState->unk_60 == 98) {
        return 1;
    }

    if (gEventState->unk_60 == 101) {
        return 1;
    }

    if (gEventState->unk_7C == 0) {
        e = &p->keyframes[p->unk_09];

        if (gEventState->unk_6C >= *(u16*)&e->unk_00 && !(e->unk_14 & 0x8000)) {
            p->unk_09++;
            e = &p->keyframes[p->unk_09];
            p->unk_15 = 0;

            if (e->unk_1C != NULL) {
                ((void (*)(EventCameraWork*))e->unk_1C)(p);
            }

            switch (e->unk_14 & 15) {
            case 0:
                p->unk_14 = 0;
                break;
            case 1:
                p->unk_14 = 1;
                p->unk_10 = e->unk_18;
                break;
            }
        }

        if ((e->unk_14 & 15) != 2) {
            if (e->unk_10 == 255) {
                p->unk_00 = e->unk_04;
                p->unk_04 = e->unk_08;
            } else {
                n = func_08074E40(p);
                q = gEventState->unk_00[n];
                p->unk_00 = q->unk_04;
                p->unk_04 = q->unk_08 + q->unk_0C + e->unk_0C;
            }
        }

        if (e->unk_14 & 0x10) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartIn(2, e->unk_18);

                if (!(e->unk_14 & 0x10000)) {
                    m4aSongNumStart(SONG_EV_FLASH01);
                }

                gEventState->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x20) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartOut(1, e->unk_18);
                gEventState->unk_7F = 1;
                p->unk_15 = 1;

                if (e->unk_14 & 0x8000) {
                    m4aSongNumStart(SONG_EV_WHITEOUT);
                }
            }
        }

        if (e->unk_14 & 0x40) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartOut(0, e->unk_18);
                gEventState->unk_7F = 1;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x80) {
            if (p->unk_15 == 0) {
                FadeStartIn(1, e->unk_18);
                gEventState->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x100) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartIn(0, e->unk_18);
                gEventState->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x200) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeFromAmount(2, 16, e->unk_18);

                if (!(e->unk_14 & 0x10000)) {
                    m4aSongNumStart(SONG_EV_FLASH00);
                }

                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x20000) {
            StartBgWave(func_08074564);
            p->waveEnabled = 1;
        }

        if (e->unk_14 & 0x40000) {
            p->waveEnabled = 0;
            ResetHBlankCallback();
            DisableHBlankIntr();
        }

        if (e->unk_14 & 0x4000) {
            if (p->unk_15 == 0) {
                FadeStartIn(7, e->unk_18);
            }

            p->unk_15 = 1;
        }

        if (e->unk_14 & 0x2000) {
            gEventState->unk_68 = GetRandom() % 4;
            gEventState->unk_6A = GetRandom() % 4;
        } else if (e->unk_14 & 0x400) {
            gEventState->unk_68 = GetRandom() % 8;
            gEventState->unk_6A = GetRandom() % 8;
        } else if (e->unk_14 & 0x800) {
            gEventState->unk_68 = GetRandom() % 16;
            gEventState->unk_6A = GetRandom() % 16;
        } else if (e->unk_14 & 0x1000) {
            gEventState->unk_68 = 0;
            gEventState->unk_6A = gSineTable[(p->angle >> 3) & 0xFF] >> 5;
            p->angle += 4;
        } else {
            gEventState->unk_68 = 0;
            gEventState->unk_6A = 0;
        }

        if (p->unk_14 != 0) {
            func_08074DC4(p);
        } else {
            func_08074D14(p);
        }

        if (u != NULL) {
            if (u->unk_24 != 0) {
                SetBgAffine(2, 0, 0x100, 0x100, gEventState->unk_50, gEventState->unk_54);
            } else {
                if (p->unk_08 == 77) {
                    ScrollBgMapTo(3, (gEventState->x >> 8) + 8, (gEventState->y >> 8) + 40);
                } else {
                    ScrollBgMapTo(3, gEventState->x >> 8, gEventState->y >> 8);
                }

                if (gEventState->unk_78 != 0) {
                    ScrollBgMapTo(2, gEventState->x >> 8, gEventState->y >> 8);
                }

                if (gEventState->unk_79 != 0) {
                    ScrollBgMapTo(1, gEventState->x >> 8, gEventState->y >> 8);
                }
            }
        } else {
            switch (p->unk_08) {
            case 77:
            case 78:
                gBtlWork->unk_000 = gEventState->x;
                gBtlWork->unk_004 = gEventState->y;
                gBtlWork->x = gEventState->x;
                gBtlWork->y = gEventState->y;
                gBtlWork->x2 = gEventState->x;
                gBtlWork->y2 = gEventState->y;
                ScrollBgMapTo(0, (gEventState->x >> 8) + 8, (gEventState->y >> 8) + 40);
                ScrollBgMapTo(1, gEventState->x >> 8, gEventState->y >> 8);
                break;
            case 105:
                gBtlWork->unk_000 = gEventState->x;
                gBtlWork->unk_004 = gEventState->y;
                gBtlWork->x = gEventState->x;
                gBtlWork->y = gEventState->y;
                gBtlWork->x2 = gEventState->x;
                gBtlWork->y2 = gEventState->y;
                ScrollBgMapTo(0, gEventState->x >> 8, gEventState->y >> 8);
                break;
            case MSG_VIEW_ID_B4:
                break;
            default:
                gBtlWork->unk_000 = gEventState->x;
                gBtlWork->unk_004 = gEventState->y;
                gBtlWork->x = gEventState->x;
                gBtlWork->y = gEventState->y;
                gBtlWork->x2 = gEventState->x;
                gBtlWork->y2 = gEventState->y;
                ScrollBgMapTo(0, gEventState->x >> 8, gEventState->y >> 8);
                ScrollBgMapTo(1, gEventState->x >> 8, gEventState->y >> 8);
                break;
            }
        }
    } else {
        n = func_08074E88(p, gEventState->unk_88);
        p->unk_00 = gEventState->unk_00[n]->unk_04;

        switch (gEventState->unk_87) {
        case 0:
        case 2:
            p->unk_04 = gEventState->unk_00[n]->unk_08 + gEventState->unk_00[n]->unk_0C + gUnk_09033758[n];
            break;
        case 1:
        case 3:
            p->unk_04 = gEventState->unk_00[n]->unk_08 + gEventState->unk_00[n]->unk_0C;
            break;
        }

        p->unk_10 = gEventState->unk_89;
        func_08074DC4(p);

        if (u != NULL) {
            if (u->unk_24 != 0) {
                SetBgAffine(2, 0, 0x100, 0x100, gEventState->unk_50, gEventState->unk_54);
            } else {
                if (p->unk_08 == 77) {
                    ScrollBgMapTo(3, (gEventState->x >> 8) + 8, (gEventState->y >> 8) + 40);
                } else {
                    ScrollBgMapTo(3, gEventState->x >> 8, gEventState->y >> 8);
                }

                if (gEventState->unk_78 != 0) {
                    ScrollBgMapTo(2, gEventState->x >> 8, gEventState->y >> 8);
                }

                if (gEventState->unk_79 != 0) {
                    ScrollBgMapTo(1, gEventState->x >> 8, gEventState->y >> 8);
                }
            }
        } else {
            gBtlWork->unk_000 = gEventState->x;
            gBtlWork->unk_004 = gEventState->y;
            ScrollBgMapTo(0, (gEventState->x >> 8) + 8, (gEventState->y >> 8) + 40);
            ScrollBgMapTo(1, gEventState->x >> 8, gEventState->y >> 8);
        }
    }

    if (gEventState->flags & 4) {
        SetTaskUpdate(task, (TaskUpdateFunc)_08074EC8);
    }

    if (u != NULL && (u->flags & 1)) {
        func_080CA368(3, gEventState->unk_48 >> 8, gEventState->unk_4C >> 8);
    }

    func_08075010(p);
    return 1;
}
void view_2(void) {
}
void view_3(void) {
}

void func_08074D00(EventCameraWork* p) {
    gEventState->unk_50 = p->unk_00;
    gEventState->unk_54 = p->unk_04;
}

void func_08074D14(EventCameraWork* a) {
    const EventCameraKeyframe* e;
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gEventState->unk_50 - 0x7800;
    y = gEventState->unk_54 - 0x5000;
    e = &a->keyframes[a->unk_09];
    if (e->unk_14 & 0x2C00) {
        gEventState->unk_48 = x;
        gEventState->unk_4C = y;
    } else {
        gEventState->unk_48 += (x - gEventState->unk_48) >> 3;
        gEventState->unk_4C += (y - gEventState->unk_4C) >> 3;
    }
    gEventState->x = gEventState->unk_48 + (gEventState->unk_68 << 8);
    gEventState->y = gEventState->unk_4C + (gEventState->unk_6A << 8);
}

void func_08074D98(EventCameraWork* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gEventState->unk_50 - 0x7800;
    y = gEventState->unk_54 - 0x5000;
    gEventState->unk_48 = x;
    gEventState->unk_4C = y;
}

void func_08074DC4(EventCameraWork* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gEventState->unk_50 - 0x7800;
    y = gEventState->unk_54 - 0x5000;

    if (a->unk_10 != 0) {
        ApproachValue(&gEventState->unk_48, x, a->unk_10);
        ApproachValue(&gEventState->unk_4C, y, a->unk_10);
        a->unk_10--;
    } else {
        gEventState->unk_48 = x;
        gEventState->unk_4C = y;
    }
    gEventState->x = gEventState->unk_48 + (gEventState->unk_68 << 8);
    gEventState->y = gEventState->unk_4C + (gEventState->unk_6A << 8);
}

u8 func_08074E40(EventCameraWork* p) {
    EventSequenceDef* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    const EventCharaTrack* q = t->charaTracks;
    const EventCameraKeyframe* e = &p->keyframes[p->unk_09];
    u8 i;

    for (i = 0; i < n; i++) {
        if (e->unk_10 == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 func_08074E88(EventCameraWork* p, u8 v) {
    EventSequenceDef* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    const EventCharaTrack* q = t->charaTracks;
    u8 i;

    for (i = 0; i < n; i++) {
        if (v == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 _08074EC8(EventCameraWork* p) {
    EventBackgroundDef* t;
    Ent08074EC8* q;
    u8 n;

    n = func_08074E88(p, 0);
    t = gUnk_09EE3CA0[p->unk_08];
    q = gEventState->unk_00[n];
    p->unk_00 = q->unk_04;
    p->unk_04 = q->unk_08 + q->unk_0C;

    if (t != NULL) {
        if (t->unk_24 != 0) {
            func_08074D98(p);
            SetBgAffine(2, 0, 0x100, 0x100, gEventState->unk_50, gEventState->unk_54);
        } else {
            func_08074D14(p);

            if (p->unk_08 == 77) {
                ScrollBgMapTo(3, (gEventState->unk_48 >> 8) + 8 + gEventState->unk_68, (gEventState->unk_4C >> 8) + 40);
            } else {
                ScrollBgMapTo(3, (gEventState->unk_48 >> 8) + gEventState->unk_68, gEventState->unk_4C >> 8);
            }

            if (gEventState->unk_78 != 0) {
                ScrollBgMapTo(2, gEventState->unk_48 >> 8, gEventState->unk_4C >> 8);
            }

            if (gEventState->unk_79 != 0) {
                ScrollBgMapTo(1, gEventState->unk_48 >> 8, gEventState->unk_4C >> 8);
            }
        }
    } else {
        func_08074D14(p);
        gBtlWork->unk_000 = gEventState->unk_48;
        gBtlWork->unk_004 = gEventState->unk_4C;
        ScrollBgMapTo(0, (gEventState->unk_48 >> 8) + 8, (gEventState->unk_4C >> 8) + 40);
        ScrollBgMapTo(1, gEventState->unk_48 >> 8, gEventState->unk_4C >> 8);
    }
    return 1;
}

void func_08075010(EventCameraWork* p) {
    u8 i;
    s32 v;

    if (p->waveEnabled == 1) {
        for (i = 0; i < 160; i++) {
            p->scanlineScrollX[i] = (gEventState->x >> 8) + (v = (u8)gSineTable[((i + p->wavePhase) * 2) & 0xFF]) / 32;
        }
        p->wavePhase++;
    }
}

TaskDesc gTaskDescEventSeq = {
    gTaskNameEventSeq,
    (TaskInitFunc)event_seq_0,
    (TaskUpdateFunc)event_seq_1,
    (TaskFunc)event_seq_2,
    (TaskFunc)event_seq_3,
#ifdef VERSION_EU
    0x40,
#else
    0x3C,
#endif
};

TaskDesc gTaskDescEventChara = {
    gTaskNameEventChara,
    (TaskInitFunc)event_chara_0,
    (TaskUpdateFunc)event_chara_1,
    (TaskFunc)event_chara_2,
    (TaskFunc)event_chara_3,
    0x1BC,
};

const u16* gUnk_09EE4704[4][2] = {
    {gUnk_08125E24, gUnk_0951D2B8},
    {gUnk_08125E24, gUnk_0951DAB8},
    {gUnk_0951E2B8, gUnk_08125E24},
    {gUnk_0951EAB8, gUnk_08125E24},
};

void* gUnk_09EE4724[4] = {
    gUnk_09EE4704[0],
    gUnk_09EE4704[1],
    gUnk_09EE4704[2],
    gUnk_09EE4704[3],
};

TaskDesc gTaskDescMsgwin = {
    gTaskNameMsgwin,
    (TaskInitFunc)msgwin_0,
    (TaskUpdateFunc)msgwin_1,
    (TaskFunc)msgwin_2,
    (TaskFunc)msgwin_3,
    0x44,
};

TaskDesc gTaskDescMsgface[3] = {
    {
        gTaskNameMsgface,
        (TaskInitFunc)msgface_0,
        (TaskUpdateFunc)msgface_1,
        (TaskFunc)msgface_2,
        (TaskFunc)msgface_3,
        0x3C,
    },
    {
        gTaskNameMsgwait,
        (TaskInitFunc)msgwait_0,
        (TaskUpdateFunc)msgwait_1,
        (TaskFunc)msgwait_2,
        (TaskFunc)msgwait_3,
        0x108,
    },
    {
        "msgwait_yesno",
        (TaskInitFunc)msgwait_yesno_0,
        (TaskUpdateFunc)msgwait_yesno_1,
        (TaskFunc)msgwait_yesno_2,
        (TaskFunc)msgwait_yesno_3,
        0x108,
    },
};

TaskDesc gTaskDescView = {
    "view",
    (TaskInitFunc)view_0,
    (TaskUpdateFunc)view_1,
    (TaskFunc)view_2,
    (TaskFunc)view_3,
    0x15C,
};
