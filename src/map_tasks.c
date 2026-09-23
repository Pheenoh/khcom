#include "map_ui_data.h"
#include "map_text_assets.h"
#include "registration_data.h"
#include "map_menu_assets.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "status_api.h"
#include "task.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "display.h"
#include "text.h"
#include "monsgage.h"
#include "anim.h"
#include "map.h"
#include "map_spawn_data.h"
#include "map_resource_assets.h"
#include "map_text_data.h"

extern MapNameText* gUnk_09EF6FCC[13];
extern MapNameText* gUnk_09EF7000[12];
extern u8 gUnk_09EF6C38[2];

#ifdef VERSION_EU
#define LANGSEL(x) eu_0805E924(x)
#else
#define LANGSEL(x) (x)
#endif

#include "map_tasks.h"
#include "map_enemy_assets.h"
#include "sprites_btl.h"
#include "sprites_emy.h"
#include "sprites_evt.h"
#include "sprites_map.h"
#include "sprites_map_tasks.h"

const AnimDef gUnk_0984BB9C[10] = {
    { gUnk_09EDF914, gUnk_09EDF940, gUnk_0895EECC, 0, { 0, 0, 0 } },
    { gUnk_09EDF914, gUnk_09EDF940, gUnk_0895EECC, 0, { 0, 0, 0 } },
    { gUnk_09EDF860, gUnk_09EDF880, gUnk_08958AC8, 0, { 0, 0, 0 } },
    { gUnk_09EDF834, gUnk_09EDF85C, gUnk_08957290, 0, { 0, 0, 0 } },
    { gUnk_09EDF8A8, gUnk_09EDF8C8, gUnk_0895B2C0, 0, { 0, 0, 0 } },
    { gUnk_09EDF884, gUnk_09EDF8A4, gUnk_0895A12A, 0, { 0, 0, 0 } },
    { gUnk_09EDF97C, gUnk_09EDF9A4, gUnk_0896213C, 0, { 0, 0, 0 } },
    { gUnk_09EDF948, gUnk_09EDF974, gUnk_089605FC, 0, { 0, 0, 0 } },
    { gUnk_09EDF9A8, gUnk_09EDF9BC, gUnk_08963BAC, 0, { 0, 0, 0 } },
    { gUnk_09EDF9A8, gUnk_09EDF9BC, gUnk_08963BAC, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0984BC3C = {
    gUnk_09EF8D00, gUnk_09EF8D18, gUnk_098A5F22, 1, { 0, 0, 0 },
};

const AnimDef gUnk_0984BC4C = {
    gUnk_09EF8D00, gUnk_09EF8D18, gUnk_098A5F22, 1, { 0, 0, 0 },
};

const AnimDef gUnk_0984BC5C = {
    gUnk_09EF8D00, gUnk_09EF8D18, gUnk_098A5F22, 0, { 0, 0, 0 },
};

const AnimDef gUnk_0984BC6C = {
    gUnk_09EF8D00, gUnk_09EF8D18, gUnk_098A5F22, 0, { 0, 0, 0 },
};

const AnimDef gUnk_0984BC7C = {
    gUnk_09EF8D00, gUnk_09EF8D18, gUnk_098A5F22, 2, { 0, 0, 0 },
};

const AnimDef gUnk_0984BC8C = {
    gUnk_09EF8D00, gUnk_09EF8D18, gUnk_098A5F22, 2, { 0, 0, 0 },
};

const UnkStruct_0984BC9C gUnk_0984BC9C = {
    gUnk_0984BB9C, gUnk_08F697A4,
    32, 8, 16, 0,
    &gTaskDescMapEnm00, 1, 0,
};

const char gTaskNameMapEnm00[] = "Task_MapEnm00";

const AnimDef gUnk_0984BCC4[6] = {
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 0, { 0, 0, 0 } },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 0, { 0, 0, 0 } },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 2, { 0, 0, 0 } },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 2, { 0, 0, 0 } },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 3, { 0, 0, 0 } },
    { gUnk_09EDFB5C, gUnk_09EDFC3C, gUnk_08988980, 3, { 0, 0, 0 } },
};

const UnkStruct_0984BC9C gUnk_0984BD24 = {
    gUnk_0984BCC4, gUnk_08F69804,
    17, 16, 16, 0,
    &gTaskDescMapEnm01, 2, 0,
};

const char gTaskNameMapEnm01[] = "Task_MapEnm01";

const AnimDef gUnk_0984BD4C[2] = {
    { gUnk_09EDFA08, gUnk_09EDFA24, gUnk_08967A32, 0, { 0, 0, 0 } },
    { gUnk_09EDFA08, gUnk_09EDFA24, gUnk_08967A32, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0984BD6C = {
    gUnk_09EDFA28, gUnk_09EDFA48, gUnk_0896C03A, 0, { 0, 0, 0 },
};

const AnimDef gUnk_0984BD7C = {
    gUnk_09EDFA28, gUnk_09EDFA48, gUnk_0896C03A, 0, { 0, 0, 0 },
};

const UnkStruct_0984BC9C gUnk_0984BD8C = {
    gUnk_0984BD4C, gUnk_08F697C4,
    106, 48, 36, 0,
    &gTaskDescMapEnm02, 8, 0,
};

const char gTaskNameMapEnm02[] = "Task_MapEnm02";

const AnimDef gUnk_0984BDB4[4] = {
    { gUnk_09EE0780, gUnk_09EE07A0, gUnk_08A59DDC, 0, { 0, 0, 0 } },
    { gUnk_09EE0780, gUnk_09EE07A0, gUnk_08A59DDC, 0, { 0, 0, 0 } },
    { gUnk_09EE0780, gUnk_09EE07A0, gUnk_08A59DDC, 0, { 0, 0, 0 } },
    { gUnk_09EE0780, gUnk_09EE07A0, gUnk_08A59DDC, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0984BDF4 = {
    gUnk_09EE07A8, gUnk_09EE07B4, gUnk_08A5D6BA, 0, { 0, 0, 0 },
};

const AnimDef gUnk_0984BE04 = {
    gUnk_09EE07A8, gUnk_09EE07B4, gUnk_08A5D6BA, 0, { 0, 0, 0 },
};

const UnkStruct_0984BC9C gUnk_0984BE14 = {
    gUnk_0984BDB4, gUnk_08F69A64,
    73, 56, 36, 0,
    &gTaskDescMapEnm03, 10, 0,
};

const char gTaskNameMapEnm03[] = "Task_MapEnm03";

const AnimDef gUnk_0984BE3C[6] = {
    { gUnk_09EF8D24, gUnk_09EF8D44, gUnk_098A659A, 0, { 0, 0, 0 } },
    { gUnk_09EE00D0, gUnk_09EE00F0, gUnk_089D8148, 0, { 0, 0, 0 } },
    { gUnk_09EF8D24, gUnk_09EF8D44, gUnk_098A659A, 0, { 0, 0, 0 } },
    { gUnk_09EE00D0, gUnk_09EE00F0, gUnk_089D8148, 0, { 0, 0, 0 } },
    { gUnk_09EE00F4, gUnk_09EE0114, gUnk_089DA20E, 0, { 0, 0, 0 } },
    { gUnk_09EE00F4, gUnk_09EE0114, gUnk_089DA20E, 0, { 0, 0, 0 } },
};

const UnkStruct_0984BC9C gUnk_0984BE9C = {
    gUnk_0984BE3C, gUnk_08F69924,
    34, 16, 12, 0,
    &gTaskDescMapEnm04, 2, 0,
};

const char gTaskNameMapEnm04[] = "Task_MapEnm04";

const AnimDef gUnk_0984BEC4[8] = {
    { gUnk_09EDFDD8, gUnk_09EDFDFC, gUnk_089AF520, 0, { 0, 0, 0 } },
    { gUnk_09EDFDD8, gUnk_09EDFDFC, gUnk_089AF520, 0, { 0, 0, 0 } },
    { gUnk_09EDFDBC, gUnk_09EDFDD4, gUnk_089AE276, 0, { 0, 0, 0 } },
    { gUnk_09EDFDBC, gUnk_09EDFDD4, gUnk_089AE276, 0, { 0, 0, 0 } },
    { gUnk_09EDFE00, gUnk_09EDFE24, gUnk_089B0C42, 0, { 0, 0, 0 } },
    { gUnk_09EDFE00, gUnk_09EDFE24, gUnk_089B0C42, 0, { 0, 0, 0 } },
    { gUnk_09EDFE28, gUnk_09EDFE44, gUnk_089B225C, 0, { 0, 0, 0 } },
    { gUnk_09EDFE28, gUnk_09EDFE44, gUnk_089B225C, 0, { 0, 0, 0 } },
};

const UnkStruct_0984BC9C gUnk_0984BF44 = {
    gUnk_0984BEC4, gUnk_08F698A4,
    26, 16, 12, 0,
    &gTaskDescMapEnm05, 4, 0,
};

const char gTaskNameMapEnm05[] = "Task_MapEnm05";

const AnimDef gUnk_0984BF6C[8] = {
    { gUnk_09EDFDD8, gUnk_09EDFDFC, gUnk_089AF520, 0, { 0, 0, 0 } },
    { gUnk_09EDFDD8, gUnk_09EDFDFC, gUnk_089AF520, 0, { 0, 0, 0 } },
    { gUnk_09EDFDBC, gUnk_09EDFDD4, gUnk_089AE276, 0, { 0, 0, 0 } },
    { gUnk_09EDFDBC, gUnk_09EDFDD4, gUnk_089AE276, 0, { 0, 0, 0 } },
    { gUnk_09EDFE00, gUnk_09EDFE24, gUnk_089B0C42, 0, { 0, 0, 0 } },
    { gUnk_09EDFE00, gUnk_09EDFE24, gUnk_089B0C42, 0, { 0, 0, 0 } },
    { gUnk_09EDFE28, gUnk_09EDFE44, gUnk_089B225C, 0, { 0, 0, 0 } },
    { gUnk_09EDFE28, gUnk_09EDFE44, gUnk_089B225C, 0, { 0, 0, 0 } },
};

const UnkStruct_0984BC9C gUnk_0984BFEC = {
    gUnk_0984BF6C, gUnk_08F698E4,
    26, 16, 12, 0,
    &gTaskDescMapEnm06, 4, 0,
};

const char gTaskNameMapEnm06[] = "Task_MapEnm06";

const char gTaskNameMapDbg[] = "Task_MapDbg";

const char gTaskNameMapGmkJump[] = "Task_MapGmk_Jump";

const char gTaskNameMapGmkEnm[] = "Task_MapGmk_Enm";

const char gTaskNameMapGmkDmy[] = "Task_MapGmk_Dmy";

const char gTaskNameMapGmkTutorial[] = "Task_MapGmk_Tutorial";

const char gTaskNameMapGmkSpider[] = "Task_MapGmk_Spider";

const char gTaskNameMapGmkGP00[] = "Task_MapGmk_GP00";

const char gTaskNameMapGmkGP01[] = "Task_MapGmk_GP01";

const char gTaskNameMapGmkGP02[] = "Task_MapGmk_GP02";

const char gTaskNameMapGmkGP03[] = "Task_MapGmk_GP03";

const char gTaskNameMapGmkGP04[] = "Task_MapGmk_GP04";

const char gTaskNameMapGmkGP05[] = "Task_MapGmk_GP05";

const char gTaskNameMapGmkGP06[] = "Task_MapGmk_GP06";

const char gTaskNameMapGmkGP07[] = "Task_MapGmk_GP07";

const char gTaskNameMapGmkGP08[] = "Task_MapGmk_GP08";

const char gTaskNameMapGmkGP09[] = "Task_MapGmk_GP09";

const char gTaskNameMapGmk00[] = "Task_MapGmk00";

s32 func_080EF3A0(MapEnmWork* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (p->unk_08.unk_00 < gUnk_02039BA0->x - 0x1800 || p->unk_08.unk_00 > gUnk_02039BA0->x + 0x10800 ||
        q->x + q->y < gUnk_02039BA0->y - 0x800 || q->x + q->y > gUnk_02039BA0->y + 0xC000) {
        p->update = 0;
        ColliderSetDisabled(p->collider, 1);
        return 1;
    }
    return 0;
}

void func_080EF404(MapEnmWork* p, s32 b, s32 c) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;

    if (p->unk_04 & 0x10) {
        b /= 5;
        c /= 5;
    }
    p->unk_08.unk_00 += gSineTable[q->angle] * q->unk_10 >> 8;
    q->unk_04 += -gSineTable[q->angle + 64] * q->unk_10 >> 8;
    q->unk_10 += b;
    if (q->unk_10 > c) {
        q->unk_10 = c;
    }
}

void func_080EF478(MapEnmWork* p, s32 b, s32 c) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (func_080DFBDC(q) != 0 || func_080DFF1C(q) != q->y) {
        p->unk_08.unk_00 = b;
        q->x = c;
        p->update = func_080EF84C;
        ColliderSetDisabled(p->collider, 1);
    }
}

s32 func_080EF4BC(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    u8 ang;

    if (gUnk_02039BA0->actor.fieldPosition.unk_0C != q->unk_0C) {
        return 0;
    }
    ang = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    if (abs(GetAngleDiff(ang, q->angle)) > 0x18) {
        return 0;
    }
    q->angle = ang;
    return 1;
}

void func_080EF508(MapEnmWork* p) {
    s32 z;

    func_080E5D6C(p, 0, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        if (p->unk_04 & 8) {
            p->update = func_080EF7B8;
        } else {
            p->update = func_080EF58C;
        }
        *(u16*)&p->unk_D0 = z = 0;
        ColliderSetDisabled(p->collider, z);
    } else {
        func_080E5DEC(p);

        if (*(s16*)&p->unk_E0 > 0) {
            (*(s16*)&p->unk_E0)--;

            if (*(s16*)&p->unk_E0 <= 0) {
                ColliderSetDisabled(p->collider, 0);
            }
        }
    }
}

void func_080EF58C(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;
    s32 v;

    func_080E5D6C(p, 1, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = p->unk_08.unk_00;
    y = q->unk_04;

    if ((u8)func_080EF4BC(p) != 0) {
        p->unk_D0 = 0;
        p->update = func_080EF718;
    } else if (GetRandom() % 80 == 0) {
        switch (GetRandom() % 4) {
        case 0:
            v = 173;
            break;
        case 1:
            v = 83;
            break;
        case 2:
            v = 211;
            break;
        default:
            v = 45;
            break;
        }
        ((u8*)q)[0x14] = v;
        p->unk_D0 = 0;
        p->update = func_080EF664;
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EF88C;
    } else {
        func_080E5F50(p);

        if ((u8)func_080EF3A0(p) == 0) {
            func_080EF478(p, x, y);
        }
    }
}

void func_080EF664(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;

    func_080E5D6C(p, 2, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = p->unk_08.unk_00;
    y = q->unk_04;

    if ((u8)func_080EF4BC(p) != 0) {
        p->unk_D0 = 0;
        p->update = func_080EF718;
    } else if (GetRandom() % 80 == 0) {
        q->unk_10 = 0;
        p->update = func_080EF58C;
    } else {
        func_080EF404(p, 12, 0x80);
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EF88C;
    } else {
        func_080E5F50(p);

        if ((u8)func_080EF3A0(p) == 0) {
            func_080EF478(p, x, y);
        }
    }
}

void func_080EF718(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;

    func_080E5D6C(p, 2, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = q->unk_00;
    y = q->unk_04;

    if (p->unk_D0 % 8 == 0) {
        if ((u8)func_080EF4BC(p) == 0) {
            q->unk_10 = 0;
            p->update = func_080EF58C;
        }
    }
    func_080EF404(p, 12, 0x180);
    p->unk_D0++;

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EF88C;
    } else {
        func_080E5F50(p);

        if ((u8)func_080EF3A0(p) == 0) {
            func_080EF478(p, x, y);
        }
    }
}

void func_080EF7B8(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;

    func_080E5D6C(p, 2, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = q->unk_00;
    y = q->unk_04;

    if (p->unk_D0 % 8 == 0) {
        q->angle = GetAngle(x, y, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }
    func_080EF404(p, 25, 0x200);

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EF88C;
    } else {
        func_080E5F50(p);
        func_080EF478(p, x, y);
        p->unk_D0++;
    }
}

void func_080EF84C(MapEnmWork* p) {
    p->unk_04 |= 4;
    func_080E5D6C(p, 3, 0);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        p->update = 0;
    }
}

void func_080EF88C(MapEnmWork* p) {
    func_080E5D6C(p, 4, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080EF8CC(MapEnmWork* p) {
    func_080E5D6C(p, 1, 0);
    p->gfx = AnimGetGfx(p->anim);
    TaskPoolUpdate(p->unk_E4);

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EF88C;
    } else {
        func_080E5F50(p);
    }
}

void Task_MapEnm00_0(MapEnmWork* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);

    if (p->update == 0) {
        if (p->unk_04 & 0x20) {
            p->update = func_080EF8CC;
            func_080E5D6C(p, 1, 0);
            p->gfx = AnimGetGfx(p->anim);
            ColliderSetDisabled(p->collider, 0);
        } else {
            p->update = func_080EF508;
            func_080E5D6C(p, 0, 0);
            p->gfx = AnimGetGfx(p->anim);
            ColliderSetDisabled(p->collider, 1);
        }
    } else {
        ColliderSetDisabled(p->collider, 0);
    }
    *(u16*)&p->unk_D0 = 0;
}

s32 Task_MapEnm00_1(MapEnmWork* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->update != func_080EF88C) {
        return 1;
    }

    if (p->update != 0) {
        p->update(p);

        if (p->update != 0) {
            ColliderSetPosition(p->collider, q->unk_00, q->x, q->y);
            return 1;
        }
    }
    return 0;
}

void Task_MapEnm00_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm00_3(MapEnmWork* p) {
    func_080E657C(p);
}

void func_080EFA30(UnkStruct_080EFA30* p) {
    if (p->unk_08 < gUnk_02039BA0->x - 0x1800 || p->unk_08 > gUnk_02039BA0->x + 0x10800) {
        if (p->unk_F8 != 0) {
            p->unk_CC = 0;
        }
    } else if (p->unk_F8 == 0) {
        p->unk_F8 = 1;
    }
}

void func_080EFA7C(UnkStruct_080F023C* p, u8 a) {
    s32* q = &p->unk_08;
    s32 t = q[2];
    s32 v;

    switch (a) {
    case 1:
        v = p->unk_DC + gSineTable[gFrameCounter & 0xFF] * 10;
        break;
    case 0:
    default:
        v = p->unk_DC + gSineTable[gFrameCounter * 2 & 0xFF] * 12;
        break;
    }

    if (p->unk_04 & 16) {
        q[2] += (v - q[2]) / 80;
    } else {
        q[2] += (v - q[2]) >> 4;
    }
    if (q[3] < q[2]) {
        q[2] = t;
        p->unk_DC = t - 0x1C00;
    }
}

void func_080EFB24(UnkStruct_080F023C* w, u8 a) {
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;

    if (a != 0) {
        w->unk_D4 = gUnk_02039BA0->actor.fieldPosition.x;
        w->unk_D8 = gUnk_02039BA0->actor.fieldPosition.y;
        w->unk_DC = gUnk_02039BA0->actor.fieldPosition.z - 0x1000;
    } else {
        w->unk_D4 = gUnk_02039BA0->actor.fieldPosition.x;
        w->unk_D8 = gUnk_02039BA0->actor.fieldPosition.y;
        w->unk_DC = gUnk_02039BA0->actor.fieldPosition.z;

        if (GetRandom() % 2) {
            t1 = GetRandom() % 65 * 256;
            t1 += 0x2000;
            w->unk_D4 -= t1;
        } else {
            t2 = GetRandom() % 65 * 256;
            t2 += 0x2000;
            w->unk_D4 += t2;
        }

        t3 = GetRandom() % 121 * 256;
        t3 -= 0x3C00;
        w->unk_D8 += t3;
        t4 = GetRandom() % 49 * 256;
        t4 += 0x1000;
        w->unk_DC -= t4;
    }
}

void func_080EFC08(MapEnmWork* p) {
    MapEnmWork* w = p;
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;

    func_080E5D6C(p, 0, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    func_080EFA7C((UnkStruct_080F023C*)p, 0);

    if (GetRandom() % 20 == 0) {
        q->angle = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if (q->unk_08 < gUnk_02039BA0->actor.fieldPosition.z - 0x4000) {
        func_080EFB24((UnkStruct_080F023C*)p, 0);
        p->unk_D0 = 0;
        q->unk_10 = 0;
        p->update = func_080EFCF4;
    } else if (GetRandom() % 130 == 0) {
        if (GetRandom() % 2 != 0) {
            func_080EFB24((UnkStruct_080F023C*)p, 0);
        } else {
            func_080EFB24((UnkStruct_080F023C*)p, 1);
        }
        w->unk_D0 = 0;
        q->unk_10 = 0;
        w->update = func_080EFCF4;
    }

    if ((u8)func_080E5FB4(w) != 0) {
        w->update = func_080EFE54;
    } else {
        func_080E5F50(w);
        func_080EFA30((UnkStruct_080EFA30*)p);
    }
}

void func_080EFCF4(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    UnkStruct_080DFF1C t;
    s32 dx;
    s32 dy;
    s32 v;
    s32 r;
    u32 lim;

    func_080E5D6C(p, 1, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    func_080EFA7C((UnkStruct_080F023C*)p, 1);
    t = p->unk_08;

    if (GetRandom() % 20 != 0) {
        q->angle = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    dx = p->unk_D4;
    dy = p->unk_D8;

    if (p->unk_04 & 16) {
        lim = 0x140;
        q->unk_10 += 10;

        if (q->unk_10 > 76) {
            q->unk_10 = 76;
        }
    } else {
        lim = 64;
        q->unk_10 += 51;

        if (q->unk_10 > 0x180) {
            q->unk_10 = 0x180;
        }
    }

    v = (dx - q->unk_00) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_00 += v;
    v = (dy - q->unk_04) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_04 += v;

    if (p->unk_D0 > lim) {
        p->update = func_080EFC08;
    } else {
        p->unk_D0++;
    }

    r = func_080DFF1C((UnkStruct_080DFF1C*)q);

    if (r < q->unk_08) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 + 0x1000;
    } else if (r == 0x100000) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 - 0x1000;
    } else {
        q->unk_0C = r;
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EFE54;
    } else {
        func_080E5F50(p);
    }
}

void func_080EFE54(MapEnmWork* p) {
    func_080E5D6C(p, 2, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080EFE94(MapEnmWork* p) {
    func_080E5D6C(p, 0, 0);
    p->gfx = AnimGetGfx(p->anim);
    TaskPoolUpdate(p->unk_E4);

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080EFE54;
    } else {
        func_080E5F50(p);
    }
}

void Task_MapEnm01_0(MapEnmWork* p, UnkStruct_080E5B90* q) {
    UnkStruct_080EFA30* w = (UnkStruct_080EFA30*)p;

    func_080E6394(p, q);

    if (p->unk_04 & 0x20) {
        p->update = func_080EFE94;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        ColliderSetDisabled(p->collider, 0);
    } else {
        p->update = func_080EFC08;
        func_080E5D6C(p, 0, 1);
        p->gfx = AnimGetGfx(p->anim);
        ColliderSetDisabled(p->collider, 0);
    }
    w->unk_D0 = 0;
    ((UnkStruct_080EFA30*)p)->unk_F8 = 0;
}

s32 Task_MapEnm01_1(MapEnmWork* p) {
    MapEnmWork* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->update != func_080EFE54) {
        return 1;
    }

    if (p->update != 0) {
        ((void (*)(MapEnmWork*))p->update)(q);

        if (p->update != 0) {
            ColliderSetPosition(&p->collider, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void Task_MapEnm01_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm01_3(MapEnmWork* p) {
    func_080E657C(p);
}

void func_080EFFF8(MapEnmWork* p) {
    func_080E5D6C(p, 0, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (func_080E02E0(&p->unk_08, p->unk_C8, p->unk_CA)) {
        m4aSongNumStart(0x75);
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_0203C7AC->unk_00 |= 4;
        func_080E5EAC(p);
    }
    func_080E5F50(p);
}

void Task_MapEnm02_0(MapEnmWork* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);
    p->update = func_080EFFF8;
    func_080E5D6C(p, 0, 1);
    p->gfx = AnimGetGfx(p->anim);
    ColliderSetDisabled(p->collider, 0);
}

s32 Task_MapEnm02_1(MapEnmWork* p) {
    MapEnmWork* w = p;
    UnkStruct_080DFF1C* q = &w->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if (w->update != 0) {
        ((void (*)(MapEnmWork*))w->update)(w);

        if (w->update != 0) {
            ColliderSetPosition(w->collider, q->unk_00, q->x, q->y);
            return 1;
        }
    }
    return 0;
}

void Task_MapEnm02_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm02_3(MapEnmWork* p) {
    func_080E657C(p);
}

void func_080F0108(UnkStruct_080F023C* p, u8 a) {
    s32* q = &p->unk_08;
    s32 t = q[2];
    s32 v;

    switch (a) {
    case 1:
        v = p->unk_DC + gSineTable[gFrameCounter & 0xFF] * 10;
        break;
    case 0:
    default:
        v = p->unk_DC + gSineTable[gFrameCounter * 2 & 0xFF] * 12;
        break;
    }

    if (p->unk_04 & 16) {
        q[2] += (v - q[2]) / 80;
    } else {
        q[2] += (v - q[2]) >> 4;
    }
    if (q[3] < q[2]) {
        q[2] = t;
        p->unk_DC = t - 0x1C00;
    }
}

s32 func_080F01B0(UnkStruct_080F023C* p) {
    s32* q = &p->unk_08;
    s32 dx;
    s32 dy;
    s32 lim;

    q[4] += 0x100;
    if (q[4] > 0x500) {
        q[4] = 0x500;
    }

    dx = (p->unk_D4 - p->unk_08) / 32;
    lim = q[4];

    if (dx > lim) {
        dx = lim;
    } else if (dx < -lim) {
        dx = -lim;
    }
    q[0] += dx;

    dy = (p->unk_D8 - q[1]) / 32;

    if (dy > lim) {
        dy = lim;
    } else if (dy < -lim) {
        dy = -lim;
    }
    q[1] += dy;

    if (p->unk_D0 > 64) {
        return 1;
    }
    p->unk_D0++;
    return 0;
}

s32 func_080F023C(UnkStruct_080F023C* p, s32 lim) {
    s32 dx;
    s32 dy;

    dx = p->unk_F8 - gUnk_02039BA0->actor.fieldPosition.x;
    if (dx < 0) {
        dx = gUnk_02039BA0->actor.fieldPosition.x - p->unk_F8;
    }
    dy = p->unk_FC - gUnk_02039BA0->actor.fieldPosition.y;
    if (dy < 0) {
        dy = gUnk_02039BA0->actor.fieldPosition.y - p->unk_FC;
    }

    if (dx > 0x8000 || dy > 0x8000) {
        return 0;
    }
    return Sqrt8((dx * dx >> 8) + (dy * dy >> 8)) < lim ? 1 : 0;
}

void func_080F02A0(UnkStruct_080F023C* w) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&w->unk_08;

    func_080E5D6C((MapEnmWork*)w, 0, 3);
    func_080E5DEC((MapEnmWork*)w);
    TaskPoolUpdate(&w->tasks);
    func_080F0108(w, 0);

    if (GetRandom() % 20 == 0) {
        q->angle = GetAngle(w->unk_08, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if ((u8)func_080F023C(w, 0x6000) != 0 && q->unk_0C == gUnk_02039BA0->actor.fieldPosition.unk_0C) {
        w->unk_D4 = gUnk_02039BA0->actor.fieldPosition.x;
        w->unk_D8 = gUnk_02039BA0->actor.fieldPosition.y;
        w->unk_DC = gUnk_02039BA0->actor.fieldPosition.unk_0C - 0x1000;
        w->unk_D0 = 0;
        q->unk_10 = 0;
        w->update = func_080F0348;
    }
    func_080E5F50((MapEnmWork*)w);
}

void func_080F0348(UnkStruct_080F023C* w) {
    UnkStruct_080F023C* q = w;
    UnkStruct_080EF4BC* v = (UnkStruct_080EF4BC*)&w->unk_08;
    UnkStruct_080DFF1C tmp;
    s32 n;

    func_080E5D6C((MapEnmWork*)w, 1, 3);
    func_080E5DEC((MapEnmWork*)w);
    TaskPoolUpdate(&w->tasks);
    func_080F0108(w, 1);
    tmp = *(UnkStruct_080DFF1C*)v;

    if (GetRandom() % 20 != 0) {
        v->angle = GetAngle(w->unk_08, v->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if ((u8)func_080F023C(w, 0x6000) != 0 && v->unk_0C == gUnk_02039BA0->actor.fieldPosition.unk_0C) {
        w->unk_D4 = gUnk_02039BA0->actor.fieldPosition.x;
        w->unk_D8 = gUnk_02039BA0->actor.fieldPosition.y;
    }

    if ((u8)func_080F01B0(q) != 0) {
        w->unk_D4 = q->unk_F8;
        w->unk_D8 = q->unk_FC;
        w->unk_DC = q->unk_100;
        w->unk_D0 = 0;
        v->unk_10 = 0;
        w->update = func_080F0470;
    }

    n = func_080DFF1C((UnkStruct_080DFF1C*)v);

    if (n < v->unk_08) {
        *(UnkStruct_080DFF1C*)v = tmp;
        w->unk_D8 = v->unk_04 + 0x1000;
    } else if (n == 0x100000) {
        *(UnkStruct_080DFF1C*)v = tmp;
        w->unk_D8 = v->unk_04 - 0x1000;
    } else {
        v->unk_0C = n;
    }

    func_080E5F50((MapEnmWork*)w);
}

void func_080F0470(UnkStruct_080F023C* w) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&w->unk_08;
    UnkStruct_080DFF1C save;
    s32 r;

    func_080E5D6C((MapEnmWork*)w, 1, 3);
    func_080E5DEC((MapEnmWork*)w);
    TaskPoolUpdate(&w->tasks);
    func_080F0108(w, 1);
    save = *(UnkStruct_080DFF1C*)q;

    if (GetRandom() % 20 != 0) {
        q->angle = GetAngle(w->unk_08, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if ((u8)func_080F01B0(w) != 0) {
        w->unk_D0 = 0;
        q->unk_10 = 0;
        w->update = func_080F02A0;
    }

    r = func_080DFF1C((UnkStruct_080DFF1C*)q);

    if (r < q->unk_08) {
        *(UnkStruct_080DFF1C*)q = save;
        w->unk_D8 = q->unk_04 + 0x1000;
    } else if (r == 0x100000) {
        *(UnkStruct_080DFF1C*)q = save;
        w->unk_D8 = q->unk_04 - 0x1000;
    } else {
        q->unk_0C = r;
    }
    func_080E5F50((MapEnmWork*)w);
}

void Task_MapEnm03_0(UnkStruct_080F023C* w, UnkStruct_080E5B90* arg) {
    func_080E6394((MapEnmWork*)w, arg);
    w->update = func_080F02A0;
    func_080E5D6C((MapEnmWork*)w, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    ColliderSetDisabled(&w->collider, 0);
    w->unk_D0 = 0;
    *(UnkStruct_080DFF1C*)&w->unk_F8 = *(UnkStruct_080DFF1C*)&w->unk_08;
}

s32 Task_MapEnm03_1(MapEnmWork* p) {
    MapEnmWork* w = p;
    UnkStruct_080DFF1C* q = &w->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if (w->update != 0) {
        ((void (*)(MapEnmWork*))w->update)(w);

        if (w->update != 0) {
            ColliderSetPosition(w->collider, q->unk_00, q->x, q->y);
            return 1;
        }
    }
    return 0;
}

void Task_MapEnm03_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm03_3(MapEnmWork* p) {
    func_080E657C(p);
}

void func_080F0614(UnkStruct_080EFA30* p) {
    if (p->unk_08 < gUnk_02039BA0->x - 0x1800 || p->unk_08 > gUnk_02039BA0->x + 0x10800) {
        if (p->unk_F8 != 0) {
            p->unk_CC = 0;
        }
    } else if (p->unk_F8 == 0) {
        p->unk_F8 = 1;
    }
}

void func_080F0660(UnkStruct_080F023C* p, u8 a) {
    s32* q = &p->unk_08;
    s32 t = q[2];
    s32 v;

    switch (a) {
    case 1:
        v = p->unk_DC + gSineTable[gFrameCounter & 0xFF] * 10;
        break;
    case 0:
    default:
        v = p->unk_DC + gSineTable[gFrameCounter * 2 & 0xFF] * 12;
        break;
    }

    if (p->unk_04 & 16) {
        q[2] += (v - q[2]) / 80;
    } else {
        q[2] += (v - q[2]) >> 4;
    }
    if (q[3] < q[2]) {
        q[2] = t;
        p->unk_DC = t - 0x1C00;
    }
}

void func_080F0708(UnkStruct_080F023C* p, u8 flag) {
    if (flag) {
        p->unk_D4 = gUnk_02039BA0->actor.fieldPosition.x;
        p->unk_D8 = gUnk_02039BA0->actor.fieldPosition.y;
        p->unk_DC = gUnk_02039BA0->actor.fieldPosition.z - 0x1000;
    } else {
        p->unk_D4 = gUnk_02039BA0->actor.fieldPosition.x;
        p->unk_D8 = gUnk_02039BA0->actor.fieldPosition.y;
        p->unk_DC = gUnk_02039BA0->actor.fieldPosition.z;

        if (GetRandom() % 2) {
            s32 t = GetRandom() % 65 * 256 + 0x2000;

            p->unk_D4 -= t;
        } else {
            s32 t = GetRandom() % 65 * 256 + 0x2000;

            p->unk_D4 += t;
        }
        {
            s32 t = GetRandom() % 121 * 256 - 0x3C00;

            p->unk_D8 += t;
        }
        {
            s32 t = GetRandom() % 49 * 256 + 0x1000;

            p->unk_DC -= t;
        }
    }
}

void func_080F07EC(MapEnmWork* p) {
    MapEnmWork* r = p;
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    UnkStruct_080DFF1C tmp;

    func_080E5D6C(p, 0, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    tmp = p->unk_08;
    func_080F0660((UnkStruct_080F023C*)p, 0);

    if (GetRandom() % 20 == 0) {
        q->angle = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if (q->unk_08 < gUnk_02039BA0->actor.fieldPosition.z - 0x4000) {
        func_080F0708((UnkStruct_080F023C*)p, 0);
        p->unk_D0 = 0;
        q->unk_10 = 0;
        p->update = func_080F08E4;
    } else if (GetRandom() % 130 == 0) {
        if (GetRandom() % 2) {
            func_080F0708((UnkStruct_080F023C*)p, 0);
        } else {
            func_080F0708((UnkStruct_080F023C*)p, 1);
        }

        r->unk_D0 = 0;
        q->unk_10 = 0;
        r->update = func_080F08E4;
    }

    if ((u8)func_080E5FB4(r) != 0) {
        r->update = func_080F0A44;
    } else {
        func_080E5F50(r);
        func_080F0614((UnkStruct_080EFA30*)p);
    }
}

void func_080F08E4(MapEnmWork* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    UnkStruct_080DFF1C t;
    s32 dx;
    s32 dy;
    s32 v;
    s32 r;
    u32 lim;

    func_080E5D6C(p, 1, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    func_080F0660((UnkStruct_080F023C*)p, 1);
    t = p->unk_08;

    if (GetRandom() % 20 != 0) {
        q->angle = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    dx = p->unk_D4;
    dy = p->unk_D8;

    if (p->unk_04 & 16) {
        lim = 0x140;
        q->unk_10 += 10;

        if (q->unk_10 > 76) {
            q->unk_10 = 76;
        }
    } else {
        lim = 64;
        q->unk_10 += 51;

        if (q->unk_10 > 0x180) {
            q->unk_10 = 0x180;
        }
    }

    v = (dx - q->unk_00) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_00 += v;
    v = (dy - q->unk_04) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_04 += v;

    if (p->unk_D0 > lim) {
        p->update = func_080F07EC;
    } else {
        p->unk_D0++;
    }

    r = func_080DFF1C((UnkStruct_080DFF1C*)q);

    if (r < q->unk_08) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 + 0x1000;
    } else if (r == 0x100000) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 - 0x1000;
    } else {
        q->unk_0C = r;
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080F0A44;
    } else {
        func_080E5F50(p);
    }
}

void func_080F0A44(MapEnmWork* p) {
    func_080E5D6C(p, 2, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080F0A84(MapEnmWork* p) {
    func_080E5D6C(p, 0, 0);
    p->gfx = AnimGetGfx(p->anim);
    TaskPoolUpdate(p->unk_E4);

    if ((u8)func_080E5FB4(p)) {
        p->update = func_080F0A44;
    } else {
        func_080E5F50(p);
    }
}

void Task_MapEnm04_0(MapEnmWork* p, UnkStruct_080E5B90* q) {
    UnkStruct_080EFA30* w = (UnkStruct_080EFA30*)p;

    func_080E6394(p, q);

    if (p->unk_04 & 0x20) {
        p->update = func_080F0A84;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        ColliderSetDisabled(p->collider, 0);
    } else {
        p->update = func_080F07EC;
        func_080E5D6C(p, 0, 1);
        p->gfx = AnimGetGfx(p->anim);
        ColliderSetDisabled(p->collider, 0);
    }
    w->unk_D0 = 0;
    ((UnkStruct_080EFA30*)p)->unk_F8 = 0;
}

s32 Task_MapEnm04_1(MapEnmWork* p) {
    MapEnmWork* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->update != func_080F0A44) {
        return 1;
    }

    if (p->update != 0) {
        ((void (*)(MapEnmWork*))p->update)(q);

        if (p->update != 0) {
            ColliderSetPosition(&p->collider, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void Task_MapEnm04_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm04_3(MapEnmWork* p) {
    func_080E657C(p);
}

void func_080F0BE8(MapEnmWork* p) {
    MapEnmWork* q = p;

    func_080E5D6C(p, 0, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        ColliderSetDisabled(p->collider, 0);
        p->unk_D0 = GetRandom() % 121 + 60;
        p->update = func_080F0C68;
    } else {
        func_080E5DEC(q);
        if (q->unk_E0 > 0) {
            q->unk_E0--;

            if (q->unk_E0 <= 0) {
                ColliderSetDisabled(q->collider, 0);
            }
        }
    }
}

void func_080F0C68(MapEnmWork* p) {
    MapEnmWork* q = p;
    UnkStruct_080EF4BC* r = (UnkStruct_080EF4BC*)&p->unk_08;

    func_080E5D6C(p, 1, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (GetRandom() % 20 == 0) {
        r->angle = GetAngle(p->unk_08.unk_00, r->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080F0D40;
    } else {
        func_080E5F50(p);

        if (p->unk_D0 != 0) {
            p->unk_D0--;
        } else {
            ColliderSetDisabled(q->collider, 1);
            q->update = func_080F0D00;
        }
    }
}

void func_080F0D00(MapEnmWork* p) {
    p->unk_04 |= 4;
    func_080E5D6C(p, 2, 0);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->update = 0;
    }
}

void func_080F0D40(MapEnmWork* p) {
    func_080E5D6C(p, 3, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void Task_MapEnm05_0(MapEnmWork* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);

    if (p->update == 0) {
        p->update = func_080F0BE8;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        ColliderSetDisabled(p->collider, 1);
    } else {
        ColliderSetDisabled(p->collider, 0);
    }
    p->unk_D0 = 0;
}

s32 Task_MapEnm05_1(MapEnmWork* p) {
    MapEnmWork* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->update != func_080F0D40) {
        return 1;
    }

    if (p->update != 0) {
        ((void (*)(MapEnmWork*))p->update)(q);

        if (p->update != 0) {
            ColliderSetPosition(&p->collider, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void Task_MapEnm05_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm05_3(MapEnmWork* p) {
    func_080E657C(p);
}

void func_080F0E6C(MapEnmWork* p) {
    MapEnmWork* q = p;

    func_080E5D6C(p, 0, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        ColliderSetDisabled(p->collider, 0);
        p->unk_D0 = GetRandom() % 121 + 60;
        p->update = func_080F0EEC;
    } else {
        func_080E5DEC(q);
        if (q->unk_E0 > 0) {
            q->unk_E0--;

            if (q->unk_E0 <= 0) {
                ColliderSetDisabled(q->collider, 0);
            }
        }
    }
}

void func_080F0EEC(MapEnmWork* p) {
    MapEnmWork* q = p;
    UnkStruct_080EF4BC* r = (UnkStruct_080EF4BC*)&p->unk_08;

    func_080E5D6C(p, 1, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (GetRandom() % 20 == 0) {
        r->angle = GetAngle(p->unk_08.unk_00, r->unk_04, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->update = func_080F0FC4;
    } else {
        func_080E5F50(p);

        if (p->unk_D0 != 0) {
            p->unk_D0--;
        } else {
            ColliderSetDisabled(q->collider, 1);
            q->update = func_080F0F84;
        }
    }
}

void func_080F0F84(MapEnmWork* p) {
    p->unk_04 |= 4;
    func_080E5D6C(p, 2, 0);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->update = 0;
    }
}

void func_080F0FC4(MapEnmWork* p) {
    func_080E5D6C(p, 3, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void Task_MapEnm06_0(MapEnmWork* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);

    if (p->update == 0) {
        p->update = func_080F0E6C;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        ColliderSetDisabled(p->collider, 1);
    } else {
        ColliderSetDisabled(p->collider, 0);
    }
    p->unk_D0 = 0;
}

s32 Task_MapEnm06_1(MapEnmWork* p) {
    MapEnmWork* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->update != func_080F0FC4) {
        return 1;
    }

    if (p->update != 0) {
        ((void (*)(MapEnmWork*))p->update)(q);

        if (p->update != 0) {
            ColliderSetPosition(&p->collider, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void Task_MapEnm06_2(MapEnmWork* p) {
    func_080E64D4(p);
}

void Task_MapEnm06_3(MapEnmWork* p) {
    func_080E657C(p);
}

s32 func_080F10F0(u8* p) {
    return ((s8)gGameState.floor << 28) + (p[9] << 20) + (p[10] << 16) + (gUnk_0203C590.unk_06 << 8) + (gUnk_0203C590.unk_05 << 4) + gUnk_0203C590.unk_04;
}

void func_080F1124(MapDbgWork* w) {
    if ((GetKeysHeld() & 0x300) == 0x300) {
        if (GetKeysPressed() & 4) {
            *w->unk_04 = 1;
            func_0801CB0C();
            ModeRequest(&gModeDebflag, 1);
        }

#ifndef VERSION_EU
        if (GetKeysPressed() & 8) {
            w->unk_00 = 1;
            *w->unk_04 = 1;
            w->update = func_080F117C;
        }
#endif
    }
}

void func_080F117C(MapDbgWork* w) {
    UnkStruct_080DEE18* d;
    s32 step;
    s32 i;

    step = 1;

    for (i = w->unk_0C; i > 0; i--) {
        step <<= 4;
    }

    d = func_080DEE18(gUnk_0203C590.unk_06);

    if (GetKeysRepeat() & 0x40) {
        d->unk_04 += step;
    }

    if (GetKeysRepeat() & 0x80) {
        d->unk_04 -= step;
    }

    if (GetKeysPressed() & 0x20) {
        w->unk_0C = w->unk_0C == 7 ? 0 : w->unk_0C + 1;
    }

    if (GetKeysPressed() & 0x10) {
        w->unk_0C = w->unk_0C == 0 ? 7 : w->unk_0C - 1;
    }

    w->unk_2C = FormatSmallFontHex(d->unk_04, w->unk_18);

    if (GetKeysPressed() & 4) {
        if (++gUnk_0203C590.unk_04 > 12) {
            gUnk_0203C590.unk_04 = 0;
        }

        w->unk_42 = FormatSmallFontHex(func_080F10F0((u8*)d), w->unk_2E);
    }

    if (GetKeysPressed() & 0x300) {
        w->update = func_080F1274;
    } else if (GetKeysPressed() & 0xB) {
        *w->unk_04 = 0;
        w->update = func_080F1124;
    }
}

void func_080F1274(MapDbgWork* w) {
    UnkStruct_080DEE18* d = func_080DEE18(gUnk_0203C590.unk_06);

    if ((GetKeysRepeat() & 0x40) && w->unk_0D == 0) {
        gUnk_0203C590.unk_04 = gUnk_0203C590.unk_04 < 12 ? gUnk_0203C590.unk_04 + 1 : 0;
    }

    if ((GetKeysRepeat() & 0x80) && w->unk_0D == 0) {
        gUnk_0203C590.unk_04 = gUnk_0203C590.unk_04 != 0 ? gUnk_0203C590.unk_04 - 1 : 12;
    }

    w->unk_42 = FormatSmallFontHex(func_080F10F0((u8*)d), w->unk_2E);

    if (GetKeysPressed() & 0x300) {
        w->update = func_080F117C;
    }

    if (GetKeysPressed() & 0xB) {
        *w->unk_04 = 0;
        w->update = func_080F1124;
    }
}

void Task_MapDbg_0(MapDbgWork* w, u8* p) {
#ifndef VERSION_EU
    UnkStruct_080DEE18* d;
#endif

    w->unk_00 = 0;
    w->unk_04 = p;
    *p = 0;
    w->update = func_080F1124;
    w->unk_0C = 0;
    w->unk_0D = 0;
#ifdef VERSION_EU
    func_080DEE18(gUnk_0203C590.unk_06);
#else
    d = func_080DEE18(gUnk_0203C590.unk_06);
    w->tiles = LoadSmallFontTiles();
    w->palette = LoadSmallFontPalette();
    w->unk_2C = FormatSmallFontHex(d->unk_04, w->unk_18);
    w->unk_42 = FormatSmallFontHex(func_080F10F0((u8*)d), w->unk_2E);
    w->unk_46 = EncodeSmallFontString(gUnk_09EF6C38, &w->unk_44);
#endif
}

s32 Task_MapDbg_1(u8* work) {
    (*(void (**)(u8*))&work[8])(work);
    return 1;
}

void Task_MapDbg_2(MapDbgWork* w) {
#ifndef VERSION_EU
    if (w->unk_00 != 0) {
        DrawSmallFontString(240 - w->unk_2C * 8, 0x8E, w->unk_18, w->tiles, w->palette, 0, w->unk_2C);
        DrawSmallFontString(240 - w->unk_42 * 8, 0x96, w->unk_2E, w->tiles, w->palette, 0, w->unk_42);

        if (*w->unk_04 != 0) {
            if (w->update == func_080F117C) {
                DrawSmallFontString(240 - (w->unk_0C + 1) * 8, 0x90, &w->unk_44, w->tiles, w->palette, 0, w->unk_46);
            } else {
                DrawSmallFontString(240 - (w->unk_0D + 1) * 8, 0x98, &w->unk_44, w->tiles, w->palette, 0, w->unk_46);
            }
        }
    }
#endif
}

void Task_MapDbg_3(u8* work) {
#ifndef VERSION_EU
    FreeSmallFontResources(*(void**)&work[16], *(void**)&work[20]);
#endif
}

void func_080F1460(MapGmkJumpWork* w) {
    if (ColliderIsTouchingType(&w->unk_040, 1) && (w->unk_06E & 2)) {
        gUnk_0203C7AC->unk_1C = w->unk_0C4;
        gUnk_0203C7AC->unk_18 = w->unk_014;
        w->update = func_080F14C4;
        w->unk_0C0 = 1;
        AnimStart(&w->anim, 1, 1);
    } else {
        AnimUpdate(&w->anim);
    }
}

void func_080F14C4(MapGmkJumpWork* w) {
    if (ColliderIsTouchingType(&w->unk_040, 1)) {
        gUnk_0203C7AC->unk_1C = w->unk_0C4;
        gUnk_0203C7AC->unk_18 = w->unk_014;
    } else if (gUnk_02039BA0->actor.fieldPosition.z != gUnk_02039BA0->actor.fieldPosition.unk_0C) {
        w->update = func_080F1544;
        w->unk_0C0 = 2;
        AnimStart(&w->anim, 2, 1);
    } else {
        w->update = func_080F1460;
        w->unk_0C0 = 0;
        AnimStart(&w->anim, 0, 1);
    }
}

void func_080F1544(MapGmkJumpWork* w) {
    if (AnimIsFinished(&w->anim)) {
        w->update = func_080F1460;
        w->unk_0C0 = 0;
        AnimStart(&w->anim, 0, 1);
    } else {
        AnimUpdate(&w->anim);
    }
}

void Task_MapGmk_Jump_0(MapGmkJumpWork* w, UnkStruct_02034F20* arg) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    AnimState* a;
    s32 v;

    p->unk_00 = arg->unk_0A << 13;
    p->x = arg->unk_0C << 12;
    p->y = 0;
    p->y = w->unk_00C = func_080DFF30(p);
    p->x -= w->unk_00C;

    switch (arg->unk_0E) {
    case 3:
        v = 211;
        break;
    case 5:
        v = 45;
        break;
    case 0:
    default:
        v = 0;
        break;
    }
    ((u8*)p)[0x14] = v;
    w->unk_0C4 = arg->unk_14 - arg->unk_10;
    w->palette = LoadObjPalette(&gUnk_099910C4[0x240], 32);
    w->tiles = LoadObjTiles(gUnk_0985A3EA, 0x980);
    a = &w->anim;
    AnimInit(a, gUnk_09EF8488, gUnk_09EF8468);
    w->unk_0C0 = 0;
    AnimStart(a, 0, 1);
    w->update = func_080F1460;
    ColliderInit(&w->unk_040, 6, 16, 0);
    ColliderSetPosition(&w->unk_040, p->unk_00, p->x, p->y);
}

s32 Task_MapGmk_Jump_1(MapGmkJumpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)w)) {
        ColliderSetDisabled(&w->unk_040, 1);
    } else {
        ColliderSetDisabled(&w->unk_040, 0);
    }

    if (w->update != 0) {
        w->update(w);
    }
    return 1;
}

void Task_MapGmk_Jump_2(MapGmkJumpWork* w) {
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    x = (w->unk_000 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004 >> 8;
    y = k + (w->unk_008 >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_Jump_3(MapGmkJumpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(&w->unk_040);
}

s32 func_080F173C(MapGmkEnmWork* w) {
    if (w->unk_070 != 0) {
        w->gfx = AnimUpdate(&w->anim);
        ApproachValue(&w->unk_000.y, w->unk_06C, w->unk_070);
        w->unk_070--;
    } else {
        gUnk_0203C7AC->unk_00 |= 2;
        gUnk_02039BA0->unk_70 |= 0x80;
        gUnk_0203C7AC->unk_0E = func_080E5E44();
        w->unk_064 = 0;
    }

    return 1;
}

void Task_MapGmk_Enm_0(MapGmkEnmWork* w, UnkStruct_080DFF1C* arg) {
    UnkStruct_080DFF1C* e = &w->unk_000;
    AnimState* an;
    u8* anim;
    u8* frames;
    u8 f;

    w->unk_000 = *arg;
    w->unk_000.x += 0x800;
    w->unk_000.y -= 0x1000;
    w->unk_01A = 16;

    if (gUnk_0203C590.unk_04 != 2) {
        w->tiles = AllocObjTiles(0x220, gUnk_08988980);
        w->palette = LoadObjPalette(gUnk_08F69804, 32);
        an = &w->anim;
        anim = gUnk_09EDFC3C;
        frames = gUnk_09EDFB5C;
    } else {
        w->tiles = AllocObjTiles(0x440, gUnk_089D8148);
        w->palette = LoadObjPalette(gUnk_08F69924, 32);
        an = &w->anim;
        anim = gUnk_09EE00F0;
        frames = gUnk_09EE00D0;
    }

    do {
        AnimInit(an, anim, frames);
        AnimStart(an, 0, 1);
    } while (0);
    w->gfx = AnimGetGfx(an);
    w->unk_064 = func_080F173C;
    f = 0;

    if (gUnk_02039BA0->actor.fieldPosition.x >= e->unk_00) {
        f = 1;
    }
    w->unk_068 = f;
    w->unk_070 = 8;
    w->unk_06C = e->y - 0x1000;
}

u8 Task_MapGmk_Enm_1(u8* work) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (*(void**)&work[0x64] != 0) {
        return (*(u8 (**)(u8*))&work[0x64])(work);
    }
    return 1;
}

void Task_MapGmk_Enm_2(u8* work) {
    u16 flags;
    s32 k;
    s32 x;
    s32 y;
    s32 t;

    t = work[0x68];
    flags = 0x800;

    if (t) {
        flags = 0x801;
    }
    x = (*(s32*)&work[0] >> 8) - (gUnk_02039BA0->x >> 8);
    k = *(s32*)&work[4] >> 8;
    y = k + (*(s32*)&work[8] >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, *(void**)&work[0x60], *(void**)&work[0x58], *(void**)&work[0x5C], 0, flags, -0x1004 - k * 4);
}

void Task_MapGmk_Enm_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x58]);
    ReleaseObjPalette(*(u8**)&work[0x5C]);
}

void Task_MapGmk_Dmy_0(u8* work) {
    *(void**)work = AllocObjTiles(func_080E83C4() << 5, 0);
}

s32 Task_MapGmk_Dmy_1(void) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }
    return 1;
}

void Task_MapGmk_Dmy_2(u8* work) {
}

void Task_MapGmk_Dmy_3(u8* work) {
    if (*(void**)work != 0) {
        ReleaseObjTiles(*(void**)work);
    }
}

u8 func_080F1978(MapGmkTutorialWork* w) {
    if (func_080E02E0((UnkStruct_080DFF1C*)w, 0, 8) != 0) {
        if ((gUnk_02039BA0->unk_70 & 0x800000) == 0 && gUnk_02039BA0->actor.fieldPosition.z == gUnk_02039BA0->actor.fieldPosition.unk_0C) {
            TaskPool* pool = &w->tasks;

            TaskCreate(pool, &gTaskDescMapSpark, w);
            m4aSongNumStart(0xDC);
            gUnk_0203C7AC->unk_00 |= 0x80;
            gUnk_02039BA0->unk_68 = (s32)w;
            gUnk_0203C7AC->unk_14 = (s32)w;
            w->update = func_080F1A10;
            gUnk_0203C7AC->unk_0F = 0;
            gUnk_0203C7AC->unk_10 = 0;
            FadeSetPaletteExcluded(*(u16*)&w->palette[6] + 16, 1);
            TaskCreate(pool, &gTaskDescRoomcreate, 0);
        }
    }
    return 1;
}

u8 func_080F1A10(MapGmkTutorialWork* w) {
    void* p = func_08093BF8();

    if (p != 0) {
        func_080DF640(gUnk_0984C868[0], p);
        w->update = func_080F1A84;
    }

    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        FadeSetPaletteExcluded(*(u16*)&w->palette[6] + 16, 0);
        w->update = func_080F1978;
    }
    return 1;
}

u8 func_080F1A84(MapGmkTutorialWork* w) {
    if (gUnk_02039BA0->unk_70 & 0x200000) {
        UpdateSpriteFrameTiles(w->tiles, gUnk_098A94A0, gUnk_0994C364);
        w->unk_0A8 = 1;
        w->update = func_080F1ACC;
    }
    return 1;
}

u8 func_080F1ACC(MapGmkTutorialWork* w) {
    return 1;
}

void Task_MapGmk_Tutorial_0(MapGmkTutorialWork* w) {
    w->x = 0x19000;
    w->y = 0xAA00;
    w->z = 0;
    w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
    w->z = w->unk_00C;
    w->y -= w->unk_00C;
    w->unk_014 = 0xAD;
    w->unk_01A = 32;
    w->palette = LoadObjPalette(&gUnk_099910C4[0x140], 32);
    w->tiles = AllocSpriteFrameTiles(0x400);
    UpdateSpriteFrameTiles(w->tiles, gUnk_098A94A0, gUnk_0994BF64);
    ColliderInit(&w->collider, 6, 16, 0);
    ColliderSetPosition(&w->collider, w->x, w->y, w->z);
    w->unk_0A8 = 0;
    w->update = func_080F1978;
    TaskPoolInit(&w->tasks, 2);
}

s32 Task_MapGmk_Tutorial_1(MapGmkTutorialWork* w) {
    if (w->unk_0A8 != 0 && (w->unk_06E & 2) && w->unk_074 == 1) {
        gUnk_0203C7AC->unk_00 |= 0x200;
    }

    if (w->update != 0) {
        if (w->update(w) == 0) {
            return 0;
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

void Task_MapGmk_Tutorial_2(MapGmkTutorialWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->x >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->y >> 8;
    y = k + (w->z >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0xFE4 - k * 4;
    DrawSprite(x, y, 0, w->tiles, w->palette, 0, 0x800, v);
    TaskPoolDraw(&w->tasks);
}

void Task_MapGmk_Tutorial_3(MapGmkTutorialWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
    TaskPoolDestroy(&w->tasks);
}

u8 func_080F1C64(MapGmkSpiderWork* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        gUnk_0203C7AC->unk_00 |= 2;
        gUnk_02039BA0->unk_70 |= 0x80;
        gUnk_0203C7AC->unk_0E = GetRandom() % 3 + 125;
        w->update = 0;
    } else {
        w->gfx = AnimUpdate(a);
    }
    return 1;
}

void Task_MapGmk_Spider_0(MapGmkSpiderWork* w, UnkStruct_0203C7B8* arg) {
    u8 v;

    *(UnkStruct_080DFF1C*)w = arg->unk_04;
    w->unk_01A = 24;
    w->tiles = AllocObjTiles(0x720, gUnk_0899A8BE);
    w->palette = LoadObjPalette(&gUnk_08F691E4[0x6A0], 32);
    AnimInit(&w->anim, gUnk_09EDFCF4, gUnk_09EDFCBC);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    SetObjTileSource(w->tiles, gUnk_0899A8BE);
    w->update = func_080F1C64;
    v = 0;

    if (gUnk_02039BA0->actor.fieldPosition.x >= w->unk_000) {
        v = 1;
    }
    w->unk_0C4 = v;
}

u8 Task_MapGmk_Spider_1(MapGmkSpiderWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_Spider_2(MapGmkSpiderWork* w) {
    u16 flags;
    u16 v;
    s32 t;
    s32 k;
    s32 x;
    s32 y;

    t = w->unk_0C4;
    flags = 0x800;

    if (t) {
        flags = 0x801;
    }

    x = (w->unk_000 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004 >> 8;
    y = k + (w->unk_008 >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, flags, v);
}

void Task_MapGmk_Spider_3(MapGmkSpiderWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

s32 func_080F1E28(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;

    if (func_080E02E0(p, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);

        if (!(w->cell->unk_00 & 2)) {
            w->cell->unk_00 |= 2;
            func_080E84DC(p);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        w->unk_0C6 = 20;
        w->update = func_080F1EA0;
    }
    return 1;
}

s32 func_080F1EA0(MapGmkGpWork* w) {
    if (w->unk_0C6 != 0) {
        w->unk_0C6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->update = func_080F1E28;
    }
    return 1;
}

void Task_MapGmk_GP00_0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = LoadObjTiles(d->tiles, d->tilesSize);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C6 = 0;
    w->update = func_080F1E28;
}

u8 Task_MapGmk_GP00_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP00_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP00_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

u8 func_080F207C(MapGmkGp1Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;

    if (func_080E8374((UnkStruct_080E8374*)p) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (!func_080E02E0(p, 8, 8)) {
        w->gfx = AnimUpdate(&w->anim);
    } else {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);
        func_080E84DC(&w->unk_004);
        gUnk_0203C7AC->unk_00 |= 0x80;
        w->cell->unk_00 |= 1;
        ColliderSetDisabled(&w->collider, 1);
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F2130;
    }
    return 1;
}

s32 func_080F2130(MapGmkGp1Work* w) {
    AnimState* a = &w->anim;

    if (!AnimIsFinished(a)) {
        w->gfx = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C6 = 0;
        w->update = 0;
    }
    return 1;
}

void Task_MapGmk_GP01_0(MapGmkGp1Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->cell = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);
    AnimStart(a, 0, 1);
    w->gfx = AnimGetGfx(a);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C6 = 1;
    w->update = func_080F207C;
}

u8 Task_MapGmk_GP01_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP01_2(MapGmkGp1Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    if (w->unk_0C6 != 0) {
        x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = w->unk_004.x >> 8;
        y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
    }
}

void Task_MapGmk_GP01_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

u8 func_080F230C(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (func_080E02E0(q, 8, 8)) {
        MapCell* e;

        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        e = w->cell;

        if ((e->unk_00 & 2) == 0) {
            e->unk_00 |= 2;
            func_080E84DC(q);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F238C;
    }
    return 1;
}

u8 func_080F238C(MapGmkGpWork* w) {
    if (AnimIsFinished(&w->anim) == 0) {
        w->gfx = AnimUpdate(&w->anim);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        AnimStart(&w->anim, 0, 0);
        w->gfx = AnimGetGfx(&w->anim);
        w->update = func_080F230C;
    }

    return 1;
}

void Task_MapGmk_GP02_0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->cell = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);
    AnimStart(a, 0, 1);
    w->gfx = AnimGetGfx(a);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->update = func_080F230C;
}

u8 Task_MapGmk_GP02_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP02_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP02_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

u8 func_080F2594(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F25FC;
    }
    return 1;
}

s32 func_080F25FC(MapGmkGpWork* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        MapCell* e = w->cell;

        if ((e->unk_00 & 2) == 0) {
            e->unk_00 |= 2;
            func_080E84DC(&w->unk_004);
        }
        AnimStart(a, 2, 0);
        w->update = func_080F2654;
    } else {
        w->gfx = AnimUpdate(a);
    }
    return 1;
}

u8 func_080F2654(MapGmkGpWork* w) {
    if (AnimIsFinished(&w->anim) == 0) {
        w->gfx = AnimUpdate(&w->anim);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        AnimStart(&w->anim, 0, 0);
        w->gfx = AnimGetGfx(&w->anim);
        w->update = func_080F2594;
    }

    return 1;
}

void Task_MapGmk_GP03_0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->cell = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);
    AnimStart(a, 0, 1);
    w->gfx = AnimGetGfx(a);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->update = func_080F2594;
}

u8 Task_MapGmk_GP03_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP03_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP03_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

u8 func_080F285C(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    AnimState* a = &w->anim;

    w->gfx = AnimUpdate(a);

    if ((w->cell->unk_00 & 2) == 0 && func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        func_080E84DC(q);
        w->cell->unk_00 |= 2;
        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(a, 1, 1);
        w->unk_0C6 = 20;
        w->update = func_080F28F4;
    }
    return 1;
}

s32 func_080F28F4(MapGmkGpWork* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (w->unk_0C6 != 0) {
        w->unk_0C6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->update = 0;
    }
    return 1;
}

void Task_MapGmk_GP04_0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);

    if (w->cell->unk_00 & 2) {
        AnimStart(&w->anim, 1, 1);
    } else {
        AnimStart(&w->anim, 0, 1);
    }

    w->gfx = AnimGetGfx(&w->anim);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->update = func_080F285C;
}

u8 Task_MapGmk_GP04_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP04_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP04_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

s32 func_080F2AF4(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (!(w->cell->unk_00 & 2) && func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        func_080E84DC(q);
        w->cell->unk_00 |= 2;
        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F2B78;
    }
    return 1;
}

s32 func_080F2B78(MapGmkGpWork* w) {
    AnimState* a = &w->anim;

    if (!AnimIsFinished(a)) {
        w->gfx = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        AnimStart(a, 2, 0);
        w->gfx = AnimGetGfx(a);
        w->update = 0;
    }
    return 1;
}

void Task_MapGmk_GP05_0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);

    if (w->cell->unk_00 & 2) {
        AnimStart(&w->anim, 2, 1);
    } else {
        AnimStart(&w->anim, 0, 1);
    }

    w->gfx = AnimGetGfx(&w->anim);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->update = func_080F2AF4;
}

u8 Task_MapGmk_GP05_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP05_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP05_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

u8 func_080F2D90(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    AnimState* a = &w->anim;

    w->gfx = AnimUpdate(a);

    if (func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);

        if ((w->cell->unk_00 & 2) == 0) {
            w->cell->unk_00 |= 2;
            func_080E84DC(q);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;

        if (w->cell->unk_00 & 4) {
            w->cell->unk_00 &= ~4;
            AnimStart(a, 0, 1);
        } else {
            w->cell->unk_00 |= 4;
            AnimStart(a, 1, 1);
        }

        w->unk_0C6 = 20;
        w->update = func_080F2E4C;
    }
    return 1;
}

s32 func_080F2E4C(MapGmkGpWork* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (w->unk_0C6 != 0) {
        w->unk_0C6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->update = func_080F2D90;
    }
    return 1;
}

void Task_MapGmk_GP06_0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);

    if (w->cell->unk_00 & 4) {
        AnimStart(&w->anim, 1, 1);
    } else {
        AnimStart(&w->anim, 0, 1);
    }

    w->gfx = AnimGetGfx(&w->anim);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->update = func_080F2D90;
}

u8 Task_MapGmk_GP06_1(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_GP06_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP06_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

s32 func_080F3050(MapGmkGp8Work* w) {
    AnimState* a = &w->anim;

    w->gfx = AnimUpdate(a);

    if (ColliderIsTouchingType(w->collider, 1) != 0) {
        if (w->unk_072 & 2) {
            if (!(w->cell->unk_00 & 2)) {
                w->cell->unk_00 |= 2;
                func_080E84DC(&w->unk_004);
            }
            AnimStart(a, 1, 0);
            w->gfx = AnimGetGfx(a);
            w->unk_0C4 = func_080F30C4;
        }
    }
    return 1;
}

s32 func_080F30C4(MapGmkGp8Work* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (ColliderIsTouchingType(w->collider, 1) == 0) {
        AnimStart(&w->anim, 2, 0);
        w->unk_0C4 = func_080F3108;
    }
    return 1;
}

s32 func_080F3108(MapGmkGp8Work* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        AnimStart(a, 0, 1);
        w->gfx = AnimGetGfx(a);
        w->unk_0C4 = func_080F3050;
    } else {
        w->gfx = AnimUpdate(a);
    }
    return 1;
}

void Task_MapGmk_GP07_0(MapGmkGp8Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = func_080F3050;
}

u8 Task_MapGmk_GP07_1(MapGmkGp8Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004)) {
        ColliderSetDisabled(w->collider, 1);
    } else {
        ColliderSetDisabled(w->collider, 0);
    }

    if (w->unk_0C4 != 0) {
        return w->unk_0C4(w);
    }
    return 1;
}

void Task_MapGmk_GP07_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk_GP07_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

s32 func_080F32F4(MapGmkGp8Work* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    AnimState* a;

    if (func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(*(u16*)&w->unk_0C8);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);

        if (!(w->cell->unk_00 & 2)) {
            w->cell->unk_00 |= 2;
            func_080E84DC(q);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        a = &w->anim;
        AnimStart(a, 1, 0);
        w->unk_0C4 = AnimGetGfx(a);
        w->unk_0CA = 1;
        w->unk_0CC = func_080F3384;
    }
    return 1;
}

s32 func_080F3384(MapGmkGp8Work* w) {
    AnimState* a = &w->anim;

    if (!AnimIsFinished(a)) {
        w->unk_0C4 = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0CA = 0;
        w->unk_0CC = func_080F32F4;
    }
    return 1;
}

void Task_MapGmk_GP08_0(MapGmkGp08Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = LoadObjTiles(d->tiles, d->tilesSize);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C8 = d->unk_20;
    w->unk_0CA = 0;
    w->unk_0CC = func_080F32F4;
}

u8 Task_MapGmk_GP08_1(MapGmkGp8Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004)) {
        ColliderSetDisabled(w->collider, 1);
    } else {
        ColliderSetDisabled(w->collider, 0);
    }

    if (w->unk_0CC != 0) {
        return w->unk_0CC(w);
    }
    return 1;
}

void Task_MapGmk_GP08_2(MapGmkGp8Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);

    if (w->unk_0CA != 0) {
        DrawSprite(x, y, w->unk_0C4, w->tiles, w->palette, 0, 0x800, v - 1);
    }
}

void Task_MapGmk_GP08_3(MapGmkGp8Work* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

s32 func_080F35C0(MapGmkGp8Work* w) {
    AnimState* a = &w->anim;

    w->unk_0C4 = AnimUpdate(a);

    if (ColliderIsTouchingType(w->collider, 1) != 0) {
        if (w->unk_072 & 2) {
            if (!(w->cell->unk_00 & 2)) {
                w->cell->unk_00 |= 2;
                func_080E84DC(&w->unk_004);
            }
            AnimStart(a, 1, 0);
            w->unk_0C4 = AnimGetGfx(a);
            w->unk_0C8 = 1;
            w->unk_0CC = func_080F3638;
        }
    }
    return 1;
}

s32 func_080F3638(MapGmkGp8Work* w) {
    if (AnimIsFinished(&w->anim)) {
        w->unk_0C8 = 0;
        w->unk_0CC = func_080F3674;
    } else {
        w->unk_0C4 = AnimUpdate(&w->anim);
    }

    return 1;
}

s32 func_080F3674(MapGmkGp8Work* w) {
    if (ColliderIsTouchingType(w->collider, 1) == 0) {
        w->unk_0CC = func_080F35C0;
    }
    return 1;
}

void Task_MapGmk_GP09_0(MapGmkGp8Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->cell = (MapCell*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = LoadObjTiles(d->tiles, d->tilesSize);
    w->palette = LoadObjPalette(d->palette, 32);
    AnimInit(&w->anim, d->anims, d->gfxTable);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C8 = 0;
    w->unk_0CC = func_080F35C0;
}

u8 Task_MapGmk_GP09_1(MapGmkGp8Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004)) {
        ColliderSetDisabled(w->collider, 1);
    } else {
        ColliderSetDisabled(w->collider, 0);
    }

    if (w->unk_0CC != 0) {
        return w->unk_0CC(w);
    }
    return 1;
}

void Task_MapGmk_GP09_2(MapGmkGp8Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);

    if (w->unk_0C8 != 0) {
        DrawSprite(x, y, w->unk_0C4, w->tiles, w->palette, 0, 0x800, v - 1);
    }
}

void Task_MapGmk_GP09_3(MapGmkGp8Work* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

void Task_MapGmk00_0(MapGmk00Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = LoadObjTiles(d->tiles, d->tilesSize);
    w->palette = LoadObjPalette(d->palette, 32);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);
    AnimStart(a, 0, 1);
    w->gfx = AnimGetGfx(a);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);

    if (func_080E8374((UnkStruct_080E8374*)e) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    }
    w->unk_0C4 = d->unk_1C;
    w->unk_0C9 = 0;
    w->unk_0C8 = 1;
    w->unk_0C6 = 0;
}

u8 Task_MapGmk00_1(MapGmk00Work* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    u16 t;

    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)q) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }

    if (!(w->unk_000->unk_00 & 2)) {
        t = w->unk_072 & 2;

        if (t != 0) {
            if (w->unk_0C9 != 1) {
                w->unk_0C9 = 1;
                w->unk_000->unk_00 |= 2;
                func_080E84DC(q);
            }
        } else {
            w->unk_0C9 = 0;
        }
    }
    return 1;
}

void Task_MapGmk00_2(MapGmk00Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    if (w->unk_0C8 != 0) {
        x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = w->unk_004.x >> 8;
        y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
    }
}

void Task_MapGmk00_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

u8 func_080F3A74(MapGmk01Work* w) {
    if (func_080E02E0(&w->unk_004, 8, 8)) {
        AnimState* a;

        gUnk_0203C7AC->unk_00 |= 0x80;
        m4aSongNumStart(0xD0);
        a = &w->anim;
        AnimStart(a, 1, 1);
        w->gfx = AnimGetGfx(a);
        SetObjTileSource(w->tiles, gUnk_09858320);
        w->update = func_080F3ADC;
    }
    return 1;
}

u8 func_080F3ADC(MapGmk01Work* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (w->unk_000->unk_00 & 8) {
        gUnk_0203C7AC->unk_00 |= 4;
        w->unk_000->unk_00 |= 2;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmkEnm, q);
        w->update = 0;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x20;
        func_080E9078(gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y, gUnk_02039BA0->actor.fieldPosition.z);
        func_080DEE18(gUnk_0203C590.unk_06)->unk_00 |= 0x10;
        w->unk_000->unk_00 |= 2;
        w->unk_0C4 = 20;
        w->update = func_080F3B84;
    }

    return 1;
}

s32 func_080F3B84(MapGmk01Work* w) {
    if (w->unk_0C4 != 0) {
        if (func_080A42C8() == 0) {
            w->unk_0C4--;
        }
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->update = 0;
    }
    return 1;
}

void func_080F3BC4(MapGmk01Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(0x320, gUnk_09858320);
    w->palette = LoadObjPalette(d->palette, 32);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);

    if (w->unk_000->unk_00 & 2) {
        AnimStart(a, 1, 1);
        w->gfx = AnimGetGfx(a);
        w->update = 0;
    } else {
        gUnk_0203C7AC->unk_00 |= 0x20;
        AnimStart(a, 0, 1);
        w->gfx = AnimGetGfx(a);
        w->update = func_080F3A74;
    }
    SetObjTileSource(w->tiles, gUnk_09858320);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
}

u8 Task_MapGmk01_1(MapGmk01Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk01_2(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk01_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

void func_080F3D58(UnkStruct_080DFF1C* p) {
    u16 r;

    if (gGameState.flags & 8) {
        r = GetRandom() % 10000;
        if (r < 6000) {
            func_080E9034(0, 5, p->unk_00, p->x, p->y);
        } else if (r < 10000) {
            func_080E9034(1, 3, p->unk_00, p->x, p->y);
        }
    } else {
        r = GetRandom() % 10000;
        if (r < 3000) {
            func_080E9034(0, 5, p->unk_00, p->x, p->y);
        } else if (r < 5000) {
            func_080E9034(1, 3, p->unk_00, p->x, p->y);
        } else if (r < 8000) {
            func_080E9034(2, 5, p->unk_00, p->x, p->y);
        } else {
            func_080E9034(3, 5, p->unk_00, p->x, p->y);
        }
    }
}

u8 func_080F3E24(MapGmkBarrelWork* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 r;

    if (func_080E02E0(p, 8, 8) != 0) {
        r = GetRandom() % 10000;

        if (r <= 1499) {
            m4aSongNumStart(0x90);
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);
            gUnk_0203C7AC->unk_00 |= 0x80;
            gUnk_0203C7AC->unk_00 |= 4;
            w->unk_000->unk_00 |= 1;
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmkSpider, w->unk_000);
            return 0;
        }

        m4aSongNumStart(0x90);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);

        if (r <= 5999) {
            if ((u8)func_080E8FB8(0, p->unk_00, p->x, p->y) != 1) {
                func_080F3D58(p);
            }
        } else if (r <= 9999) {
            func_080F3D58(p);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        w->unk_000->unk_00 |= 1;
        ColliderSetDisabled(&w->collider, 1);
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F3F6C;
        return 1;
    }

    if ((u8)func_080E8374((UnkStruct_080E8374*)p) != 0) {
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetDisabled(&w->collider, 0);
    }
    return 1;
}

s32 func_080F3F6C(MapGmkBarrelWork* w) {
    AnimState* a = &w->anim;

    if (!AnimIsFinished(a)) {
        w->gfx = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C4 = 0;
        w->update = 0;
    }
    return 1;
}

void Task_MapGmk_Barrel_0(MapGmkBarrelWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    w->palette = LoadObjPalette(d->palette, 32);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);
    AnimStart(a, 0, 1);
    w->gfx = AnimGetGfx(a);
    SetObjTileSource(w->tiles, d->tiles);
    ColliderInit(&w->collider, 6, d->unk_1C, d->unk_1E);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = 1;
    w->update = func_080F3E24;
}

u8 Task_MapGmk_Barrel_1(MapGmkBarrelWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->update != 0) {
        return w->update(w);
    }
    return 1;
}

void Task_MapGmk_Barrel_2(MapGmkBarrelWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    if (w->unk_0C4 != 0) {
        x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = w->unk_004.x >> 8;
        y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
    }
}

void Task_MapGmk_Barrel_3(MapGmkGpWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

void func_080F4140(MapGmk04Work* w) {
    if ((gUnk_0203C7AC->unk_00 & 0x4000) == 0 && (u8)func_080E03C0((s32)&w->unk_004) != 0 && (GetKeysPressed() & 1)) {
        m4aSongNumStart(0x66);
        gUnk_02039BA0->unk_70 |= 0x1000;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSave, 0);
        w->update = 0;
    }
}

void func_080F41A4(MapGmk04Work* w) {
    u32 state = gUnk_0203C7AC->unk_00;

    if (state & 0x4000) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_080A411C(&w->tasks, 0, 0x69);
        w->update = func_080F4258;
    } else if (gUnk_02039BA0->unk_68 == (s32)&w->unk_004) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        gUnk_0203C7AC->unk_00 = state | 0x4000;
        func_080A411C(&w->tasks, 0, 0x67);
        w->update = func_080F4224;
    }
}

void func_080F4224(MapGmk04Work* w) {
    if (func_080A42C8() == 0) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSave, 0);
        w->update = 0;
    }
}

void func_080F4258(MapGmk04Work* w) {
    if (func_080A42C8() == 0) {
        gUnk_0203C7AC->unk_00 &= ~0x4000;
        gUnk_02039BA0->unk_70 &= ~0x1000;
        gGameState.progression.unk_82 |= 0x10;
        w->update = func_080F4140;
    }
}

void Task_MapGmk04_0(MapGmk04Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    e->unk_30 = 3;

    if (gGameState.progression.unk_82 & 0x10) {
        w->update = func_080F4140;
    } else {
        w->update = func_080F41A4;
    }

    w->palette = LoadObjPalette(d->palette, 32);
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    AnimInit(&w->anim, d->anims, d->gfxTable);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    ColliderInit(&w->collider, 4, 24, 24);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    TaskPoolInit(&w->tasks, 1);
    func_080121D4(e);
}

s32 Task_MapGmk04_1(MapGmk04Work* w) {
    TaskPoolUpdate(&w->tasks);

    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    w->gfx = AnimUpdate(&w->anim);

    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void Task_MapGmk04_2(MapGmk04Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    TaskPoolDraw(&w->tasks);
    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = p->x >> 8;
    y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk04_3(MapGmk04Work* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(&w->collider);
    TaskPoolDestroy(&w->tasks);
    func_080121FC(&w->unk_004);
}

void func_080F445C(MapGmk05Work* w) {
    if (w->unk_0C8 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_0801CB0C();
        FadeStartOut(0, 16);
        m4aSongNumStart(0xCF);
        w->update = func_080F44AC;
    }
}

void func_080F44AC(MapGmk04Work* w) {
    UnkStruct_080DEE18* e;

    if ((u8)FadeIsActive() != 0) {
        return;
    }
    e = func_080DEE18(gUnk_0203C590.unk_06);

    if (e->unk_00 & 0x20) {
        ModeRequest(&gModeMsTop, 0);
    } else {
        e->unk_00 |= 0x20;
        ModeRequest(&gModeMsTop, 1);
    }
    w->update = 0;
}

void Task_MapGmk05_0(MapGmk05Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    e->unk_30 = 2;
    w->update = func_080F445C;
    w->palette = LoadObjPalette(d->palette, 32);
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    a = &w->anim;
    AnimInit(a, d->anims, d->gfxTable);
    AnimStart(a, 0, 1);
    w->gfx = AnimGetGfx(a);
    ColliderInit(&w->collider, 4, 16, 24);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->tasks, 1);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, e);
    w->unk_0C8 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, e);
}

s32 Task_MapGmk05_1(MapGmk05Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    w->gfx = AnimUpdate(&w->anim);
    w->unk_0C8 = func_080E03C0((s32)&w->unk_004);

    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void Task_MapGmk05_2(MapGmk05Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    k = p->x >> 8;
    v = -0x1004 - k * 4;
    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
    ((UnkStruct_080E64D4*)p)->unk_3C = p->z;
    ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
    TaskPoolDraw(&w->tasks);

    if (w->unk_0C8 != 0) {
        TaskPoolDraw(&w->tasks2);
    }
}

void Task_MapGmk05_3(MapGmk05Work* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
    func_080121FC(&w->unk_004);
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F46FC(MapGmk06Work* w) {
    if (gUnk_02039BA0->unk_68 == (s32)&w->unk_004 && (gGameState.progression.unk_82 & 0x100) == 0) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        gUnk_0203C7AC->unk_00 |= 0x4000;
        func_080A411C(&w->tasks, 0, 0x84);
        gUnk_02039BA0->unk_6C = 30;
        w->update = func_080F47DC;
    } else if ((u8)func_080E03C0((s32)&w->unk_004) != 0 && (GetKeysPressed() & 1)) {
        m4aSongNumStart(0x66);
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_0801CB0C();
        FadeStartOut(0, 16);
        w->update = func_080F47B4;
    }
}

void func_080F47B4(MapGmk06Work* w) {
    if (FadeIsActive() == 0) {
        ModeRequest(&gModeWorldwarp, 0);
        w->update = 0;
    }
}

void func_080F47DC(MapGmk06Work* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        gUnk_0203C7AC->unk_00 &= ~0x4000;
        gGameState.progression.unk_82 |= 0x100;
        w->update = func_080F46FC;
    } else {
        gUnk_02039BA0->unk_6C = 30;
    }
}

void Task_MapGmk06_0(MapGmk06Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    const UnkStruct_080E7D80* d = arg->unk_14;

    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    e->unk_30 = 3;
    w->update = func_080F46FC;
    w->palette = LoadObjPalette(d->palette, 32);
    w->tiles = AllocObjTiles(d->tilesSize, d->tiles);
    AnimInit(&w->anim, d->anims, d->gfxTable);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    ColliderInit(&w->collider, 4, 24, 24);
    ColliderSetPosition(&w->collider, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    TaskPoolInit(&w->tasks, 1);
    func_080121D4(e);
}

s32 Task_MapGmk06_1(MapGmk06Work* w) {
    TaskPoolUpdate(&w->tasks);

    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    w->gfx = AnimUpdate(&w->anim);

    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void Task_MapGmk06_2(MapGmk06Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    TaskPoolDraw(&w->tasks);
    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    k = p->x >> 8;
    y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, v);
}

void Task_MapGmk06_3(MapGmk06Work* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(&w->collider);
    TaskPoolDestroy(&w->tasks);
    func_080121FC(&w->unk_004);
}

void func_080F49D0(MapPrizeWork* w) {
    w->unk_84 += 0x38;
    w->z += w->unk_84;
    w->x += gSineTable[w->angle] * w->unk_88 >> 8;
    w->y += -gSineTable[w->angle + 64] * w->unk_88 >> 8;

    if (func_080DFBDC((UnkStruct_080DFF1C*)w) != 0) {
        w->angle = w->angle + (100 + GetRandom() % 57);
    } else {
        w->unk_0C = func_080DFF1C((UnkStruct_080DFF1C*)w);
    }

    if (w->z > w->unk_0C) {
        w->z = w->unk_0C;
        w->unk_84 = -(GetRandom() % 0x181 + 0x180);
    }

    if (w->collider[0x2C] != 0) {
        u16 t;

        switch (w->unk_80) {
        case 2:
        case 3:
            m4aSongNumStart(107);
            gGameState.progression.mooglePoints += w->unk_94;

            if (gGameState.progression.mooglePoints > 99999) {
                gGameState.progression.mooglePoints = 99999;
            }
            break;
        case 0:
        case 1:
        default:
            m4aSongNumStart(107);
            gGameState.hp += w->unk_94;
            t = gGameState.progression.maxHp;

            if ((s16)gGameState.hp > (s16)t) {
                gGameState.hp = t;
            }
            break;
        }

        w->update = func_080F4BA0;
        w->unk_82 = 0;
        w->angle = GetAngle(gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y, w->x, w->y);
        w->unk_97 = 1;
        w->unk_96 = 1;
        w->unk_8D = GetRandom() % 6 + 5;
        ColliderSetDisabled(&w->collider, 1);
    } else {
        ColliderSetPosition(&w->collider, w->x, w->y, w->z);

        if (w->unk_82 == 20) {
            ColliderSetDisabled(&w->collider, 0);
        }

        if (w->unk_82 > 420) {
                w->unk_96 = w->unk_96 == 0 ? 1 : 0;
        }

        if (w->unk_82++ > 480) {
            w->update = 0;
        }
    }
}

void func_080F4BA0(MapPrizeWork* w) {
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    FieldState* g = gUnk_02039BA0;

    s = gSineTable[w->angle] * 32;
    x = g->actor.fieldPosition.x + (s * w->unk_90 >> 8);
    s = -gSineTable[w->angle + 64] * 22;
    y = g->actor.fieldPosition.y + (s * w->unk_90 >> 8);
    z = g->actor.fieldPosition.z - (w->unk_82 / 2 << 8);
    w->angle += w->unk_8D;
    w->x += (x - w->x) >> 2;
    w->y += (y - w->y) >> 2;
    w->z += (z - w->z) >> 2;
    w->unk_0C = func_080DFE7C(w->x, w->y, w->z);
    w->unk_90 -= 2;

    if (w->unk_82 > 60) {
        w->update = 0;
    } else {
        w->unk_82++;
    }
}

void Task_MapPrize_0(MapPrizeWork* w, UnkStruct_080E8F50* arg) {
    w->x = arg->unk_04;
    w->y = arg->unk_08;
    w->z = arg->unk_0C;
    w->unk_0C = 0;
    func_080DFF4C((UnkStruct_080DFF1C*)w);
    w->unk_84 = -(GetRandom() % 0x301 + 0x200);
    w->unk_88 = GetRandom() % 155 + 153;
    w->angle = GetRandom();
    w->tiles = LoadObjTiles(gUnk_098A5CF4, 0x160);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_80 = arg->unk_14;

    switch (w->unk_80) {
    case 3:
        w->gfx = gUnk_098A5CAE;
        w->unk_94 = 10;
        break;
    case 2:
        w->gfx = gUnk_098A5CA4;
        w->unk_94 = 4;
        break;
    case 1:
        w->gfx = gUnk_098A5C9A;
        w->unk_94 = gGameState.progression.maxHp / 20;
        break;
    case 0:
    default:
        w->gfx = gUnk_098A5C90;
        w->unk_94 = gGameState.progression.maxHp * 3 / 100;
        break;
    }

    w->gfx2 = gUnk_098A5CB8;
    w->unk_97 = 0;
    w->unk_96 = 1;
    w->unk_82 = 0;
    w->update = func_080F49D0;
    w->unk_90 = 0x100;
    ColliderInit(&w->collider, 5, 16, 50);
    ColliderSetPosition(&w->collider, w->x, w->y, w->z);
    ColliderSetDisabled(&w->collider, 1);
}

s32 Task_MapPrize_1(MapPrizeWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->update == 0) {
        return 0;
    }
    w->update(w);

    if (w->update == 0) {
        return 0;
    }
    return 1;
}

void Task_MapPrize_2(MapPrizeWork* w) {
    s16 x;
    s16 y;
    s32 aff;

    if (w->unk_96 != 0) {
        x = (w->x >> 8) - (gUnk_02039BA0->x >> 8);
        y = (w->y >> 8) + (w->z >> 8) - (gUnk_02039BA0->y >> 8);

        if (w->unk_90 != 0x100) {
            aff = AllocObjAffine(0, w->unk_90, w->unk_90, 0);
        } else {
            aff = 0;
        }

        DrawSprite(x, y, w->gfx, w->tiles, w->palette, aff, 0x800, -0x1004 - (w->y >> 8) * 4);

        if (w->unk_97 == 0) {
            DrawSprite(x, (w->y >> 8) + (w->unk_0C >> 8) - (gUnk_02039BA0->y >> 8), w->gfx2, w->tiles, w->palette, aff, 0x800, 0xFFFF);
        }
    }
}

void Task_MapPrize_3(MapPrizeWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

void func_080F4EE4(MapPrzCardWork* work) {
    work->unk_0B4 = -gSineTable[((work->unk_0D0 + 0x80) & 0xFF) + 0x40] * work->unk_0CC >> 8;
    work->unk_0B6 = -gSineTable[((work->unk_0CF + 0x80) & 0xFF) + 0x40] * work->unk_0CC >> 8;

    if ((u16)(work->unk_0B4 + 2) <= 4) {
        work->unk_0B4 = 2;
    }
    if ((u16)(work->unk_0B6 + 2) <= 4) {
        work->unk_0B6 = 2;
    }
}

void func_080F4F60(MapPrzCardWork* w) {
    s32 dx;
    s32 dy;

    dx = 0x7800;
    dy = 0x5000;
    dx -= w->unk_000;
    dy -= w->unk_004;
    w->unk_0C8 = NormalizeVector2D8(&dx, &dy);
    w->unk_0C0 = -dx;
    w->unk_0C4 = -dy;
    w->unk_0B0 = 0x300;
    w->unk_0AC = 2;
}

void func_080F4FB0(MapPrzCardWork* w) {
    UnkStruct_080DFF1C v = *(UnkStruct_080DFF1C*)w;
    s32 nx;
    s32 ny;

    w->unk_0AC += 0x38;
    w->unk_008 += w->unk_0AC;
    w->unk_000 += gSineTable[w->unk_0B8] * w->unk_0B0 >> 8;
    w->unk_004 += -gSineTable[w->unk_0B8 + 64] * w->unk_0B0 >> 8;

    if (func_080DFBDC((UnkStruct_080DFF1C*)w) != 0) {
        w->unk_0B8 = w->unk_0B8 + (112 + GetRandom() % 33);
        w->unk_000 = v.unk_00;
        w->unk_004 = v.x;
    } else {
        w->unk_00C = func_080DFF1C((UnkStruct_080DFF1C*)w);
    }

    if (w->unk_008 - 0x800 > w->unk_00C) {
        w->unk_008 = w->unk_00C - 0x800;
        w->unk_0AC = -(w->unk_0AC * 217 >> 8);

        if (w->unk_0AC > -0x200) {
            w->unk_0AC = -0x200;
        }
    }

    if (w->collider[0x2C] != 0) {
        w->unk_0D2 = 1;
        m4aSongNumStart(106);
        func_08084458(w->unk_0A8);

        if (w->unk_0D1 == 0) {
            UnkStruct_080DEE18* e = func_080DEE18(gUnk_0203C590.unk_06);

            if (e->unk_0C != 0) {
                e->unk_0C--;
            }
        }

        nx = (w->unk_000 >> 8) - (gUnk_02039BA0->x >> 8);
        ny = (w->unk_004 >> 8) + (w->unk_008 >> 8) - (gUnk_02039BA0->y >> 8);
        w->unk_000 = (s16)nx << 8;
        w->unk_004 = (s16)ny << 8;
        ColliderSetDisabled(&w->collider, 1);
        w->unk_0BE = 50;
        func_080F4F60(w);
        w->unk_088 = 0;
        w->update = func_080F51A0;
    } else {
        w->x = (w->unk_000 >> 8) - (gUnk_02039BA0->x >> 8);
        w->y = (w->unk_004 >> 8) + (w->unk_008 >> 8) - (gUnk_02039BA0->y >> 8);
        w->unk_0BE = -0x1004 - (w->unk_004 >> 8) * 4;
        func_080F4EE4(w);
        w->unk_0D0 += 2;
        ColliderSetPosition(&w->collider, w->unk_000, w->unk_004, w->unk_008);

        if (w->unk_08A == 20) {
            ColliderSetDisabled(&w->collider, 0);
        }

        if (w->unk_08A <= 59) {
            w->unk_08A++;
        }
    }
}

void func_080F51A0(MapPrzCardWork* w) {
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    if (w->unk_0B0 < 0) {
        dx = 0x7800 - w->unk_000;
        dy = 0x5000 - w->unk_004;
        NormalizeVector2D8(&dx, &dy);
        w->unk_0C0 = -dx;
        w->unk_0C4 = -dy;

        if (w->unk_0C8 <= 0x7FF) {
            w->unk_0CE = 0;
            w->unk_08A = 0;
            w->update = func_080F52D4;
            TaskCreate(&w->tasks, &gTaskDescMapMsg, LANGSEL(gCardDefs[w->unk_0A8].name));
        }
    }

    w->unk_000 += w->unk_0C0 * w->unk_0B0 >> 8;
    w->unk_004 += w->unk_0C4 * w->unk_0B0 >> 8;
    w->unk_0CE += 32;
    w->unk_0CF += (64 - w->unk_0CF) >> 4;
    w->unk_0D0 = 0;
    w->unk_0C8 = VectorLength2D(0x7800 - w->unk_000, 0x5000 - w->unk_004);
    w->unk_0B0 -= w->unk_0AC;
    w->unk_0AC += 2;
    w->unk_0CC += 3;

    if (w->unk_0CC > 0x100) {
        w->unk_0CC = 0x100;
    }

    x = w->unk_000 >> 8;
    w->x = x;
    y = w->unk_004 >> 8;
    w->y = y;
    func_080F4EE4(w);
}

void func_080F52D4(MapPrzCardWork* w) {
    s32 x;
    s32 y;

    w->unk_000 = 0x7800;
    w->unk_004 = 0x5800;
    w->unk_0CE = 0;
    w->unk_0CF = 0;
    w->unk_0CC += 2;

    if (w->unk_0CC > 0x100) {
        w->unk_0CC = 0x100;
    }

    x = w->unk_000 >> 8;
    w->x = x;
    y = w->unk_004 >> 8;
    w->y = y;
    func_080F4EE4(w);
    w->unk_08A++;

    if (w->unk_08A == 30) {
        w->unk_08A = 0;
        w->update = func_080F534C;
    }

    TaskPoolUpdate(&w->tasks);
}

void func_080F534C(MapPrzCardWork* w) {
    s32 x;
    s32 y;

    w->unk_0CE += 32;
    x = (gUnk_02039BA0->actor.fieldPosition.x >> 8) - (gUnk_02039BA0->x >> 8);
    y = (gUnk_02039BA0->actor.fieldPosition.y >> 8) + (gUnk_02039BA0->actor.fieldPosition.z >> 8) - (gUnk_02039BA0->y >> 8);
    w->x += ((s16)x - w->x) >> 3;
    w->y += ((s16)y - w->y) >> 3;
    w->unk_0B4 -= 10;
    w->unk_0B6 -= 10;

    if (w->unk_0B4 <= 10) {
        w->update = 0;
    }
}

void Task_MapPrzCard_0(MapPrzCardWork* w, UnkStruct_080E8F50* p) {
    CardDef* d;
    CardBack* q;

    gUnk_0203C7AC->unk_00 |= 0x10;
    w->unk_0A8 = p->unk_14;
    d = &gCardDefs[w->unk_0A8];
    w->tiles = LoadObjTiles(d->tiles, 0x300);
    w->palette = LoadObjPalette(d->palette, 32);
    w->unk_090 = *(UnkStruct_08F70ACC*)&d->unk_1C;
    q = &gUnk_08F709B0[w->unk_090.unk_0E];
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles2 = LoadObjTiles(q->tiles, 0x280);
    w->tiles3 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->palette3 = LoadObjPalette(gUnk_08F69BE4, 32);
    w->tiles4 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_000 = p->unk_04;
    w->unk_004 = p->unk_08;
    w->unk_008 = p->unk_0C;
    w->unk_00C = 0;
    func_080DFF4C((UnkStruct_080DFF1C*)w);
    w->unk_0AC = -(GetRandom() % 129 + 0x300);
    w->unk_0B0 = GetRandom() % 129 + 128;
    w->unk_0B8 = GetRandom();
    w->unk_0B4 = 128;
    w->unk_0B6 = 128;
    w->unk_0CC = 128;
    w->unk_0CE = 24;
    w->unk_0CF = 0;
    w->unk_0D0 = 0;
    w->unk_0D1 = p->unk_00;
    ColliderInit(&w->collider, 5, 30, 10);
    ColliderSetPosition(&w->collider, w->unk_000, w->unk_004, w->unk_008);

    if (w->unk_0D1 != 0) {
        ColliderSetDisabled(&w->collider, 0);
    } else {
        ColliderSetDisabled(&w->collider, 1);
    }

    w->unk_088 = 0x800;
    w->unk_08A = 0;
    w->update = func_080F4FB0;
    w->unk_0D2 = 0;
    TaskPoolInit(&w->tasks, 1);
}

s32 Task_MapPrzCard_1(MapPrzCardWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->update == 0) {
        return 0;
    }
    w->update(w);

    if (w->update == 0) {
        return 0;
    }
    return 1;
}

void Task_MapPrzCard_2(MapPrzCardWork* w) {
    CardDef* d;
    CardBack* q;
    void* t;
    s32 affine;
    s16 x;
    s16 y;
    s16 s;

    if (*(s32*)&w->unk_0B4 == 0x01000100 && w->unk_0CE == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_0CE, w->unk_0B4, w->unk_0B6, 1);
    }

    d = &gCardDefs[w->unk_0A8];
    DrawSprite(w->x, *(u16*)&w->y - 8, d->gfx, w->tiles, w->palette,
        affine, w->unk_088, w->unk_0BE + 1);
    q = &gUnk_08F709B0[w->unk_090.unk_0E];
    DrawSprite(w->x, *(u16*)&w->y - 8, q->gfx, w->tiles2,
        w->palette2, affine, w->unk_088, w->unk_0BE);

    if (w->unk_090.unk_0E != 3) {
        t = gUnk_09EE981C[w->unk_090.unk_04];
        DrawSprite(w->x, *(u16*)&w->y - 8, t, w->tiles3,
            w->palette2, affine, w->unk_088, w->unk_0BE - 1);
    }

    if (w->unk_0D2 == 0) {
        x = (w->unk_000 >> 8) - (gUnk_02039BA0->x >> 8);
        y = (w->unk_004 >> 8) + (w->unk_00C >> 8) - (gUnk_02039BA0->y >> 8);
        s = 204 - ((w->unk_00C - w->unk_008) >> 7);

        if (s <= 2) {
            s = 2;
        }

        DrawSprite(x, y, gUnk_09EE1380[0], w->tiles4, w->palette3,
            AllocObjAffine(0, s, s, 0), 0x800, w->unk_0BE + 2);
    }

    TaskPoolDraw(&w->tasks);
}
void Task_MapPrzCard_3(MapPrzCardWork* w) {
    FadeSetPaletteExcluded(w->palette2->index + 0x10, 0);
    FadeSetPaletteExcluded(w->palette->index + 0x10, 0);
    ColliderUnregister(w->collider);
    ReleaseObjTiles(w->tiles);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjTiles(w->tiles3);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjPalette(w->palette);
    ReleaseObjPalette(w->palette2);
    ReleaseObjPalette(w->palette3);
    TaskPoolDestroy(&w->tasks);
    gUnk_0203C7AC->unk_00 &= ~0x10;
}

void func_080F5800(MapPrzStockWork* w) {
    func_080A411C(&w->tasks, 0, w->unk_00[1]);
    w->update = func_080F5820;
}

void func_080F5820(MapPrzStockWork* w) {
    if (func_080A42C8() == 0) {
        w->update = 0;
    }
}

void Task_MapPrzStock_0(MapPrzStockWork* w, u16* a) {
    w->unk_00 = a;
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    w->update = func_080F5800;
    TaskPoolInit(&w->tasks, 1);
}

s32 Task_MapPrzStock_1(MapPrzStockWork* w) {
    TaskPoolUpdate(&w->tasks);

    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void Task_MapPrzStock_2(MapPrzStockWork* w) {
    TaskPoolDraw(&w->tasks);
}

void Task_MapPrzStock_3(MapPrzStockWork* w) {
    TaskPoolDestroy(&w->tasks);
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
}

void func_080F58C4(MapMsgWork* w, void* text) {
    LoadBgTiles(0, &gUnk_099597E4[0x140], 0x140);
    LoadBgMap(0, &gUnk_09985F44[0x800], 0x800);
    SetBgScroll(0, 0, (u16)-46);
    LoadPalette(gUnk_09611AB8, &gUnk_050001C0[0x20], 32);
    InitTextSlots(w->unk_004, 48);
    w->unk_184 = LoadTextSlots(text, w->unk_004);
    w->palette = _08066468(1);
    FadeSetPaletteExcluded(w->palette->index + 16, 1);
    w->unk_186 = (240 - GetTextSlotsWidth(w->unk_004, w->unk_184)) / 2;
    w->unk_188 = 0;
}

s32 Task_MapMsg_1(MapMsgWork* w) {
    return 1;
}

void func_080F596C(MapMsgWork* w) {
    DrawTextSlots(w->unk_186, 120, &w->unk_004, w->palette, 50, w->unk_184);
}

void func_080F59A0(MapMsgWork* w) {
    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        DisableBg(0);
    }

    FadeSetPaletteExcluded(w->palette->index + 0x10, 0);
    ReleaseObjPalette((u8*)w->palette);
    FreeTextSlots(&w->unk_004, 0x30);
}

s32 Task_MapMsg2_1(MapMsgWork* w) {
    w->unk_188++;

    if (w->unk_188 == 120) {
        return 0;
    }
    return 1;
}

void func_080F5A00(MapSparkWork* w, void* arg) {
    AnimState* a;

    w->unk_00 = arg;
    w->tiles = AllocObjTiles(0x200, gUnk_098A4B68);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    a = &w->anim;
    AnimInit(a, gUnk_09EF8CC0, gUnk_09EF8CA0);

    if (gGameState.flags & 8) {
        AnimStart(a, 1, 1);
    } else {
        AnimStart(a, 0, 1);
    }
}

s32 Task_MapSpark_1(MapSparkWork* w) {
    AnimUpdate(&w->anim);

    if (AnimIsFinished(&w->anim) != 0) {
        return 0;
    }
    return 1;
}

void Task_MapSpark_2(MapSparkWork* w) {
    UnkStruct_080E8374* p = w->unk_00;
    s32 h;
    u16 x;
    u16 y;

    if (p->unk_1A <= 32) {
        h = p->unk_1A << 8;
    } else {
        h = 0x2000;
    }

    x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    y = (p->unk_04 >> 8) + ((p->unk_08 - h) >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x400, 0x50);
}

void Task_MapSpark_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(u8**)&work[0x20]);
}

void Task_MapTalk_0(MapTalkWork* w, s32* arg) {
    w->unk_00 = arg;
    w->tiles = AllocObjTiles(0x200, &gUnk_098A4B68[0x1028]);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(&w->anim, gUnk_09EF8CD0, gUnk_09EF8CC8);
    AnimStart(&w->anim, 0, 1);
    w->unk_28 = 0;
}

s32 func_080F5B68(MapTalkWork* w) {
    s32* p = w->unk_00;
    AnimState* anim = &w->anim;

    AnimUpdate(anim);

    if (gUnk_02039BA0->actor.fieldPosition.x < *p) {
        w->unk_28 = 0;
        AnimStart(anim, 0, 1);
    } else {
        w->unk_28 = 1;
        AnimStart(anim, 1, 1);
    }
    return 1;
}

void Task_MapTalk_2(MapTalkWork* w) {
    UnkStruct_080E8374* p = (UnkStruct_080E8374*)w->unk_00;
    u16 x;
    u16 y;

    if (w->unk_28 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8) - 16;
    } else {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8) + 16;
    }
    y = (p->unk_04 >> 8) + ((p->unk_08 - (p->unk_1A << 8)) >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x400, 0x50);
}

void Task_MapTalk_3(MapTalkWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void func_080F5C60(MapDonaldWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        if ((s8)gGameState.floor == 12 && gUnk_0203C590.unk_06 == 0xFD) {
            func_080A411C(&w->tasks, 0, 24);
        } else {
            func_080A411C(&w->tasks, 0, gUnk_0984C2E4[gUnk_0203C590.unk_00]);
        }

        w->update = func_080F5CDC;
    }
}

void func_080F5CDC(MapDonaldWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->update = func_080F5C60;
    }
}

void Task_MapDonald_0(MapDonaldWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    if (gUnk_0203C590.unk_06 != 0xFE) {
        if ((s8)gGameState.floor == 12) {
            w->unk_000 = 0x22300;
            w->unk_004 = 0xE600;
        } else {
            w->unk_000 = 0x28800;
            w->unk_004 = 0x10000;
        }
    } else {
        if ((s8)gGameState.floor != 0) {
            w->unk_000 = 0x25000;
            w->unk_004 = 0x11000;
        } else {
            w->unk_000 = 0x35000;
            w->unk_004 = 0x12000;
        }
    }

    e->unk_00.y = 0;
    e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.y = e->unk_00.z;
    e->unk_00.x -= e->unk_00.z;
    e->unk_14 = 0x80;
    e->unk_1A = 0x20;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->update = func_080F5C60;
    w->tiles = AllocObjTiles(0x400, gUnk_0919FDF8);
    w->palette = LoadObjPalette(gUnk_09617C58, 32);
    AnimInit(&w->anim, gUnk_09EEE0A8, gUnk_09EEE03C);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(&w->collider, 4, 16, 48);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapDonald_1(MapDonaldWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapDonald_2(MapDonaldWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->z;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapDonald_3(MapFrdWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_040);
    func_080121FC(w);
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F5F88(MapGoofyWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        if ((s8)gGameState.floor == 12 && gUnk_0203C590.unk_06 == 0xFD) {
            func_080A411C(&w->tasks, 0, 49);
        } else {
            func_080A411C(&w->tasks, 0, gUnk_0984C310[gUnk_0203C590.unk_00]);
        }

        w->update = func_080F6004;
    }
}

void func_080F6004(MapGoofyWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->update = func_080F5F88;
    }
}

void Task_MapGoofy_0(MapGoofyWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    if (gUnk_0203C590.unk_06 != 0xFE) {
        if ((s8)gGameState.floor == 12) {
            w->unk_000 = 0x25000;
            w->unk_004 = 0x10A00;
        } else {
            w->unk_000 = 0x20000;
            w->unk_004 = 0xB000;
        }
    } else {
        if ((s8)gGameState.floor != 0) {
            w->unk_000 = 0x1E800;
            w->unk_004 = 0xD000;
        } else {
            w->unk_000 = 0x2C000;
            w->unk_004 = 0xE000;
        }
    }

    e->unk_00.y = 0;
    e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.y = e->unk_00.z;
    e->unk_00.x -= e->unk_00.z;
    e->unk_14 = 0x80;
    e->unk_1A = 0x30;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->update = func_080F5F88;
    w->tiles = AllocObjTiles(0x400, gUnk_091ABDB8);
    w->palette = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&w->anim, gUnk_09EEE1CC, gUnk_09EEE1C8);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(&w->collider, 4, 16, 48);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapGoofy_1(MapGoofyWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapGoofy_2(MapGoofyWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->z;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapGoofy_3(MapFrdWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_040);
    func_080121FC(w);
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F62B0(MapNamineWork* w) {
    if (w->unk_0C1 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        if (gUnk_0203C590.unk_00 == 27) {
            func_080A411C(&w->tasks, 0, 0x33);
        } else {
            func_080A411C(&w->tasks, 0, 0x32);
        }
        w->update = func_080F6314;
    }
}

void func_080F6314(MapNamineWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->update = func_080F62B0;
    }
}

void Task_MapNamine_0(MapNamineWork* w) {
    UnkStruct_080E6394* p = (UnkStruct_080E6394*)w;

    switch (gUnk_0203C590.unk_00) {
    case 27:
        w->unk_000 = 0x20D00;
        w->unk_004 = 0xD500;
        w->unk_0C4 = 0x800;
        break;
    case 23:
        w->unk_000 = 0x27C00;
        w->unk_004 = 0xD400;
        w->unk_0C4 = 0x800;
        break;
    case 24:
    case 25:
    case 26:
    default:
        p->unk_00.unk_00 = 0x15200;
        p->unk_00.x = 0xF800;
        w->unk_0C4 = 0x801;
        break;
    }

    p->unk_00.y = 0;
    p->unk_00.y = p->unk_00.z = func_080DFF30(&p->unk_00);
    p->unk_00.x -= p->unk_00.z;
    p->unk_14 = 173;
    p->unk_1A = 48;
    p->unk_30 = 2;
    w->unk_0C0 = gUnk_0203C590.unk_00 != 23;
    w->unk_0C2 = 1;
    w->update = func_080F62B0;
    w->tiles = AllocObjTiles(0x300, gUnk_093E1EE0);
    w->palette = LoadObjPalette(gUnk_096184D8, 32);
    AnimInit(&w->anim, gUnk_09EF0D64, gUnk_09EF0D48);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(w->collider, 4, 16, 48);
    ColliderSetPosition(w->collider, p->unk_00.unk_00, p->unk_00.x, p->unk_00.y);

    if (w->unk_0C0 != 0) {
        func_080121D4(p);
    }

    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C1 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapNamine_1(MapNamineWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C2 = 0;
    } else {
        w->unk_0C2 = 1;
        w->unk_0C1 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapNamine_2(MapNamineWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C2 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, w->unk_0C4, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->z;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C1 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapNamine_3(MapNamineWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);

    if (w->unk_0C0 != 0) {
        func_080121FC(w);
    }

    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F65EC(MapNamineWork* w) {
    if (w->unk_0C1 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_080A411C(&w->unk_0C4, 0, 0x34);
        w->update = func_080F6634;
    }
}

void func_080F6634(MapNamineWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->update = func_080F65EC;
    }
}

void func_080F6668(MapNamineWork* w) {
    s32 dx;
    s32 dy;

    dx = w->unk_000 - gUnk_02039BA0->actor.fieldPosition.x;

    if (dx < 0) {
        dx = gUnk_02039BA0->actor.fieldPosition.x - w->unk_000;
    }

    dy = w->unk_004 - gUnk_02039BA0->actor.fieldPosition.y;

    if (dy < 0) {
        dy = gUnk_02039BA0->actor.fieldPosition.y - w->unk_004;
    }

    if (dx <= 0x8000 && dy <= 0x8000) {
        if (Sqrt8((dx * dx >> 8) + (dy * dy >> 8)) < 0x3000) {
            FadeStartOut(0, 16);
            gUnk_02039BA0->unk_70 |= 0x1000;
            w->update = func_080F66E0;
        }
    }
}

void func_080F66E0(MapNamineWork* w) {
    if (FadeIsActive() == 0) {
        func_0806180C(0x3B);
        w->update = 0;
    }
}

void Task_MapNiseriku_0(MapNiserikuWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;
    s32 c;

    switch (gUnk_0203C590.unk_00) {
    case 27:
        e->unk_00.unk_00 = 0x27C00;
        e->unk_00.x = 0x10700;
        break;
    case 23:
        e->unk_00.unk_00 = 0x24900;
        e->unk_00.x = 0xD500;
        break;
    case 24:
    case 25:
    case 26:
    default:
        e->unk_00.unk_00 = 0x17A00;
        e->unk_00.x = 0x11000;
        break;
    }

    e->unk_00.y = 0;
    e->unk_00.y = e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.x -= e->unk_00.y;
    e->unk_14 = 173;
    e->unk_1A = 48;
    e->unk_30 = 2;

    c = 0;

    if (gUnk_0203C590.unk_00 == 27) {
        c = 1;
    }

    w->unk_0C0 = c;

    w->unk_0C2 = 1;
    w->unk_0C1 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
    TaskPoolInit(&w->tasks, 2);

    switch (gUnk_0203C590.unk_00) {
    case 27:
        w->update = func_080F65EC;
        w->tiles = AllocObjTiles(0x680, gUnk_0937E90A);
        w->palette = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->anim, gUnk_09EF04D8, gUnk_09EF04D4);
        AnimStart(&w->anim, 0, 1);
        ColliderInit(&w->collider, 4, 16, 48);
        ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
        TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
        break;
    case 23:
        w->update = func_080F6668;
        w->tiles = AllocObjTiles(0x320, gUnk_0938044A);
        w->palette = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->anim, gUnk_09EF0510, gUnk_09EF04FC);
        AnimStart(&w->anim, 0, 1);
        ColliderInit(&w->collider, 4, 16, 48);
        ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
        TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
        break;
    case 24:
    case 25:
    case 26:
    default:
        w->update = 0;
        w->tiles = AllocObjTiles(0x300, gUnk_0938D282);
        w->palette = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->anim, gUnk_09EF0628, gUnk_09EF060C);
        AnimStart(&w->anim, 1, 1);
        ColliderInit(&w->collider, 4, 36, 48);
        ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
        break;
    }

    if (w->unk_0C0 != 0) {
        func_080121D4(e);
    }
}

s32 Task_MapNiseriku_1(MapNiserikuWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C2 = 0;
    } else {
        w->unk_0C2 = 1;
        w->unk_0C1 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapNiseriku_2(MapNiserikuWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C2 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->z;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C1 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapNiseriku_3(MapMickeyWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);

    if (w->unk_0C0 != 0) {
        func_080121FC(w);
    }

    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F6A60(MapMickeyWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        switch (gUnk_0203C590.unk_00) {
        case 20:
            func_080A411C(&w->tasks, 0, 0x3F);
            break;
        case 22:
            func_080A411C(&w->tasks, 0, 0x3D);
            break;
        case 23:
        default:
            func_080A411C(&w->tasks, 0, 0x3E);
            break;
        }

        w->update = func_080F6AD8;
    }
}

void func_080F6AD8(MapMickeyWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->update = func_080F6A60;
    }
}

void Task_MapMickey_0(MapMickeyWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    e->unk_00.unk_00 = 0x1C800;
    e->unk_00.x = 0xE000;
    w->unk_0C2 = 0x801;
    e->unk_00.y = 0;
    e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.y = e->unk_00.z;
    e->unk_00.x -= e->unk_00.z;
    e->unk_14 = 0xAD;
    e->unk_1A = 0x30;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->update = func_080F6A60;
    w->tiles = AllocObjTiles(0x300, gUnk_093A5E10);
    w->palette = LoadObjPalette(gUnk_096183F8, 32);
    AnimInit(&w->anim, gUnk_09EF0824, gUnk_09EF0820);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(&w->collider, 4, 16, 48);
    ColliderSetPosition(&w->collider, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapMickey_1(MapMickeyWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapMickey_2(MapMickeyWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, w->unk_0C2, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->z;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapMickey_3(MapFrdWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_040);
    func_080121FC(w);
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F6D40(void) {
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_0203C7AC->unk_0E = 10;
    gUnk_0203C7AC->unk_00 &= ~0x4000;
    gUnk_0203C7AC->unk_00 |= 2;
}

void func_080F6D70(MapTutorialWork* w) {
    u32 flags;

    if (gUnk_02039BA0->unk_68 == 0) {
        flags = gUnk_02039BA0->unk_70;

        if (!(flags & 0x2000) && !(gUnk_0203C7AC->unk_00 & 0x2000) && (gGameState.progression.unk_82 & 0x10)) {
            gUnk_0203C7AC->unk_00 |= 0x4000;
            gUnk_02039BA0->unk_70 = flags | 0x1000;
            func_080A411C(&w->tasks, 0, 0x6A);
            w->update = func_080F6DE8;
        }
    }
}

void func_080F6DE8(MapTutorialWork* w) {
    if (func_080A42C8() == 0) {
        AnimState* a;

        func_080E5354((UnkStruct_080DFF1C*)w, &w->y);
        w->z = 0;
        w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
        w->y -= w->unk_00C;
        w->z = w->unk_00C - 0xA000;
        *(u16*)&w->unk_014[6] = 24;
        w->unk_010 = 2;
        w->tiles = AllocObjTiles(0x400, gUnk_09858B3C);
        w->palette = LoadObjPalette(&gUnk_099910C4[0x220], 32);
        a = &w->anim;
        AnimInit(a, gUnk_09EF8460, gUnk_09EF8424);
        AnimStart(a, 0, 1);
        w->gfx = AnimGetGfx(a);
        ColliderInit(w->unk_040, 6, 12, 24);
        ColliderSetPosition(w->unk_040, w->x, w->y, w->z);
        w->unk_0C1 = 1;
        TaskCreate(&w->tasks2, &gTaskDescFldShadow, w);
        w->unk_0C0 = 1;
        w->update = func_080F6EBC;
    }
}

void func_080F6EBC(MapTutorialWork* w) {
    MapTutorialWork* p = w;

    w->unk_010 += 0x38;
    w->z += w->unk_010;

    if (w->z > w->unk_00C) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        m4aSongNumStart(0xD7);
        w->z = w->unk_00C;
        w->unk_010 = 0;
        w->unk_0C1 = 0;
        w->update = func_080F6F1C;
    }
    ColliderSetPosition(p->unk_040, p->x, p->y, p->z);
}

void func_080F6F1C(MapTutorialWork* w) {
    if (func_080E02E0((UnkStruct_080DFF1C*)w, 8, 8)) {
        m4aSongNumStart(0x90);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, w);
        gUnk_0203C7AC->unk_00 &= ~0x20;
        func_080E8FB8(0, w->x, w->y, w->z);
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F6F90;
        ColliderUnregister(w->unk_040);
    }
}

void func_080F6F90(MapTutorialWork* w) {
    if (AnimIsFinished(&w->anim)) {
        w->update = func_080F6FC4;
    } else {
        w->gfx = AnimUpdate(&w->anim);
    }
}

void func_080F6FC4(MapTutorialWork* w) {
    if ((gUnk_0203C7AC->unk_00 & 0x10) == 0) {
        gGameState.progression.unk_82 |= 0x2000;
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_080A411C(&w->tasks, 0, 0x6B);
        w->update = func_080F7024;
    }
}

void func_080F7024(MapTutorialWork* w) {
    if (func_080A42C8() == 0) {
        AnimState* a;
        u8 v;

        func_080E5354((UnkStruct_080DFF1C*)w, &w->y);
        w->z = 0;
        w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
        w->y -= w->unk_00C;
        w->z = w->unk_00C;
        *(u16*)&w->unk_014[6] = 16;
        v = 0;

        if (gUnk_02039BA0->actor.fieldPosition.x > w->x) {
            v = 1;
        }
        w->unk_0C2 = v;
        w->tiles = AllocObjTiles(0x400, gUnk_0895EECC);
        w->palette = LoadObjPalette(&gUnk_08F691E4[0x5C0], 32);
        a = &w->anim;
        AnimInit(a, gUnk_09EDF940, gUnk_09EDF914);
        AnimStart(a, 0, 1);
        w->gfx = AnimGetGfx(a);
        ColliderInit(w->unk_040, 3, 8, 16);
        ColliderSetPosition(w->unk_040, w->x, w->y, w->z);
        ColliderSetDisabled(w->unk_040, 1);
        w->update = func_080F70F4;
    }
}

void func_080F70F4(MapTutorialWork* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        AnimChangeWithTables(a, 0, 1, gUnk_09EDF85C, gUnk_09EDF834);
        SetObjTileSource(w->tiles, gUnk_08957290);
        func_080A411C(&w->tasks, 0, 0x6C);
        w->update = func_080F7160;
    } else {
        w->gfx = AnimUpdate(a);
    }
}

void func_080F7160(MapTutorialWork* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        ColliderSetDisabled(w->unk_040, 0);
        w->update = func_080F71AC;
    }
}

void func_080F71AC(MapTutorialWork* w) {
    AnimState* a = &w->anim;

    w->gfx = AnimUpdate(a);

    if (func_080E02E0((UnkStruct_080DFF1C*)w, 8, 16)) {
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_0203C7AC->unk_00 |= 4;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, w);
        m4aSongNumStart(0x75);
        AnimChangeWithTables(a, 0, 1, gUnk_09EDF9BC, gUnk_09EDF9A8);
        SetObjTileSource(w->tiles, gUnk_08963BAC);
        w->update = func_080F7284;
    } else if (w->unk_06C != 0) {
        if (!(gUnk_0203C7AC->unk_00 & 4) && w->unk_074 == 1) {
            ColliderSetDisabled(w->unk_040, 1);
            func_080F6D40();
        } else {
            w->x += w->unk_078;
            w->y += w->unk_07C;
        }
    }
}

void func_080F7284(MapTutorialWork* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        ColliderSetDisabled(w->unk_040, 1);
        gGameState.flags |= 4;
        func_080F6D40();
    } else {
        w->gfx = AnimUpdate(a);
    }
}

void Task_MapTutorial_0(MapTutorialWork* w) {
    u16 t;

    TaskPoolInit(&w->tasks, 1);
    TaskPoolInit(&w->tasks2, 1);
    gUnk_0203C7AC->unk_00 |= 0x20;
    w->tiles = 0;
    w->palette = 0;
    w->unk_0C2 = 0;
    t = gGameState.progression.unk_82 & 0x2000;

    if (t == 0) {
        w->unk_0C1 = 0;
        w->unk_0C0 = 0;
        w->update = func_080F6D70;
    } else {
        gUnk_02039BA0->unk_70 |= 0x1000;
        TaskCreate(&w->tasks2, &gTaskDescFldShadow, w);
        w->unk_0C0 = 1;
        w->unk_0C1 = 1;
        w->update = func_080F7024;
    }
}

s32 Task_MapTutorial_1(MapTutorialWork* w) {
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);

    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void Task_MapTutorial_2(MapTutorialWork* w) {
    u16 flags;
    u16 v;
    s32 k;
    s32 t;
    s16 x;
    s16 y;

    TaskPoolDraw(&w->tasks);

    if (w->unk_0C0 != 0) {
        x = (w->x >> 8) - (gUnk_02039BA0->x >> 8);
        k = w->y >> 8;
        y = k + (w->z >> 8) - (gUnk_02039BA0->y >> 8);
        v = -0x1004 - k * 4;
        t = w->unk_0C2;
        flags = 0x800;

        if (t != 0) {
            flags = 0x801;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, flags, v);

        if (w->unk_0C1 != 0) {
            ((UnkStruct_080E64D4*)w)->unk_3C = w->unk_00C;
            ((UnkStruct_080E64D4*)w)->unk_3A = v + 1;
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapTutorial_3(MapTutorialWork* w) {
    if (w->tiles != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

s32 func_080F7488(UnkStruct_080DFF1C* p, s32 lim) {
    s32 dx;
    s32 dy;

    dx = p->unk_00 - gUnk_02039BA0->actor.fieldPosition.x;
    if (dx < 0) {
        dx = gUnk_02039BA0->actor.fieldPosition.x - p->unk_00;
    }
    dy = p->x - gUnk_02039BA0->actor.fieldPosition.y;
    if (dy < 0) {
        dy = gUnk_02039BA0->actor.fieldPosition.y - p->x;
    }

    if (dx > 0x8000 || dy > 0x8000) {
        return 0;
    }
    return Sqrt8((dx * dx >> 8) + (dy * dy >> 8)) < lim ? 1 : 0;
}

void func_080F74E8(UnkStruct_080DFF1C* p) {
    if ((u8)func_080F7488(p, 0x800) != 0) {
        if (gUnk_02039BA0->actor.fieldPosition.z == gUnk_02039BA0->actor.fieldPosition.unk_0C) {
            if (gUnk_0203C590.unk_06 == 0xFE) {
                gUnk_0203C7AC->unk_00 |= 0x100;
            } else {
                gUnk_0203C7AC->unk_00 |= 0x400;
            }
        }
    }
}

void func_080F753C(UnkStruct_080DFF1C* p) {
    s32 k = 0x800;

    if ((u8)func_080F7488(p, k) != 0) {
        if (gUnk_02039BA0->actor.fieldPosition.z == gUnk_02039BA0->actor.fieldPosition.unk_0C) {
            if (gUnk_0203C590.unk_06 == 0xFE) {
                gUnk_0203C7AC->unk_00 |= k;
            } else {
                gUnk_0203C7AC->unk_00 |= 0x200;
            }
        }
    }
}

void func_080F7594(MapStairWork* w) {
    if ((u8)func_080F7488((UnkStruct_080DFF1C*)w, 0x3000) != 0) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        gUnk_0203C7AC->unk_00 |= 0x4000;
        func_080A411C(&w->tasks, 0, 0xA7);
        w->update = func_080F75E4;
    }
}

void func_080F75E4(MapStairWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        gUnk_0203C7AC->unk_00 &= ~0x4000;
        gGameState.progression.unk_82 |= 0x400;
        w->update = func_080F74E8;
    }
}

void Task_MapStair_0(MapStairWork* w, UnkStruct_080EF4BC* arg) {
    s32 y;

    w->unk_14 = arg->angle;
    w->unk_00 = arg->unk_00;
    y = arg->unk_04;
    w->unk_0C = 0;
    w->unk_08 = 0;
    w->unk_04 = y;
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    w->tiles = LoadObjTiles(gUnk_08B1EA00, 0xE0);
    w->unk_48 = 0;

    switch (w->unk_14) {
    case 0x2D:
        if ((gGameState.progression.unk_82 & 0x400) == 0 && gUnk_0203C590.unk_06 == 0xFD) {
            w->update = func_080F7594;
        } else {
            w->update = (void (*)(struct MapStairWork*))func_080F74E8;
        }
        break;
    case 0xAD:
        w->update = (void (*)(struct MapStairWork*))func_080F753C;
        break;
    }
    TaskPoolInit(&w->tasks, 1);
}

s32 Task_MapStair_1(MapStairWork* w) {
    TaskPoolUpdate(&w->tasks);

    if (w->update != 0) {
        w->update(w);
    }
    return 1;
}

void Task_MapStair_2(MapStairWork* w) {
    s32 x;
    s32 y;

    TaskPoolDraw(&w->tasks);

    if (w->unk_48 == 1) {
        x = (w->unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
        y = (w->unk_04 >> 8) + (w->unk_08 >> 8) - (gUnk_02039BA0->y >> 8);
        DrawSprite(x, y, gUnk_08B1E9A6, w->tiles, w->palette, 0, 0x800, 0x101);
    }
}

void Task_MapStair_3(MapStairWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    TaskPoolDestroy(&w->tasks);
}

void Task_MapFaint_0(MapFaintWork* w, void* a) {
    w->unk_00 = a;
    w->tiles = AllocObjTiles(0x80, gUnk_08B21ACE);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(&w->anim, gUnk_09EE12E4, gUnk_09EE12D4);
    AnimStart(&w->anim, 0, 1);
}

s32 Task_MapFaint_1(u8* work) {
    AnimUpdate((AnimState*)&work[4]);
    return 1;
}

void Task_MapFaint_2(MapFaintWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w->unk_00;
    u16 x;
    u16 y;

    x = (e->unk_00.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    y = (e->unk_00.x >> 8) + ((e->unk_00.y - ((s16)e->unk_1A + 8) * 0x100) >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, -0x1005 - (e->unk_00.x >> 8) * 4);
}

void Task_MapFaint_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(u8**)&work[0x20]);
}

void Task_MapDmg_0(u8* work) {
    s32 z = 0;

    work[8] = z;
    *(void**)&work[0] = LoadObjPalette(gUnk_08F69BE4, 32);
    *(void**)&work[4] = LoadObjTiles(gUnk_08B1EA00, 224);
    *(u16*)&work[10] = z;
    work[9] = 1;
}

s32 Task_MapDmg_1(u8* work) {
    if (work[9] == 0) {
        work[8] = 0;
    } else {
        if (gUnk_0203C7AC->unk_20 != 0 || (gUnk_0203C7AC->unk_00 & 4)) {
            *(u16*)&work[0xA] = 20;
        }

        work[8] = *(u16*)&work[0xA] != 0;

        if (*(u16*)&work[0xA] != 0) {
            *(u16*)&work[0xA] -= 1;
        }
    }
    return 1;
}

void Task_MapDmg_2(u8* work) {
    s16 x;
    s16 y;

    if (work[8] == 0) {
        return;
    }

    x = ((gUnk_0203C7AC->unk_24 - 0x1400) >> 8) - (gUnk_02039BA0->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 - 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, gUnk_08B1E974, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 + 0x1400) >> 8) - (gUnk_02039BA0->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 - 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, gUnk_08B1E97E, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 - 0x1400) >> 8) - (gUnk_02039BA0->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 + 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, gUnk_08B1E992, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 + 0x1400) >> 8) - (gUnk_02039BA0->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 + 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, gUnk_08B1E988, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24) >> 8) - (gUnk_02039BA0->x >> 8);
    y = ((gUnk_0203C7AC->unk_28) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, gUnk_08B1E9A6, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);
}

void Task_MapDmg_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[4]);
    ReleaseObjPalette(*(u8**)&work[0]);
}

void* func_080F7AB4(void) {
#ifdef VERSION_EU
    if (gGameState.flags & 8) {
        return eu_0805E924(gUnk_09EF7000[(s8)gGameState.floor]);
    }
    return eu_0805E924(gUnk_09EF6FCC[(s8)gGameState.floor]);
#else
    if (gGameState.flags & 8) {
        return gUnk_09EF7000[(s8)gGameState.floor];
    }
    return gUnk_09EF6FCC[(s8)gGameState.floor];
#endif
}

void Task_MapFloor_0(MapFloorWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    w->tiles = LoadObjTiles(gUnk_0993AF64, 0x800);
    w->palette = LoadObjPalette(gUnk_099910C4, 32);
    w->gfx = gUnk_09EF8DA4[0];
    w->unk_0E = 120;
#ifdef VERSION_EU
    InitTextSlots(w->unk_18, 60);
#else
    InitTextSlots(w->unk_18, 40);
#endif
    w->palette2 = _08066468(1);
    w->unk_10 = LoadTextSlots(func_080F7AB4(), w->unk_18);
    w->unk_0C = (240 - GetTextSlotsWidth(w->unk_18, w->unk_10)) / 2;
}

s32 Task_MapFloor_1(u8* work) {
    u16* p = (u16*)&work[14];

    if (*p != 0) {
        (*p)--;
        return 1;
    }
    return 0;
}

void Task_MapFloor_2(MapFloorWork* w) {
    DrawSprite(120, 138, w->gfx, w->tiles, w->palette, 0, 0, 0x3C);
    DrawTextSlots(w->unk_0C, 0x85, w->unk_18, w->palette2, 50, w->unk_10);
}

void Task_MapFloor_3(MapFloorWork* w) {
    ReleaseObjPalette(w->palette);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette2);
#ifdef VERSION_EU
    FreeTextSlots(w->unk_18, 60);
#else
    FreeTextSlots(w->unk_18, 40);
#endif
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x1000;
}

const UnkStruct_080E7D80 gUnk_0984C158 = {
    gUnk_099912C4, gUnk_09858320, 0x200, 0, 0, gUnk_09EF8414, gUnk_09EF841C,
    1, 13, 0, 0, 0, 16, 16, 208, 0, &gTaskDescMapGmk01,
};

const char gTaskNameMapGmk01[] = "Task_MapGmk01";

const UnkStruct_080E7D80 gUnk_0984C190 = {
    gUnk_099912E4, gUnk_09858B3C, 0x400, 0, 0, gUnk_09EF8424, gUnk_09EF8460,
    1, 0, 0, 0, 0, 12, 24, 144, 0, &gTaskDescMapGmkBarrel,
};

const char gTaskNameMapGmkBarrel[] = "Task_MapGmk_Barrel";

const UnkStruct_080E7D80 gUnk_0984C1CC = {
    gUnk_09991324, gUnk_0985ADAA, 0x400, 0, 0, &gUnk_09EF8494, &gUnk_09EF84A4,
    1, 13, 0, 0, 0, 24, 62, 102, 0, &gTaskDescMapGmk04,
};

const char gTaskNameMapGmk04[] = "Task_MapGmk04";

const UnkStruct_080E7D80 gUnk_0984C204 = {
    gUnk_09617D58, gUnk_092028EC, 0x100, 0, 0, gUnk_09EEEA98, gUnk_09EEEAC8,
    1, 13, 0, 0, 0, 16, 24, 207, 0, &gTaskDescMapGmk05,
};

const char gTaskNameMapGmk05[] = "Task_MapGmk05";

const UnkStruct_080E7D80 gUnk_0984C23C = {
    gUnk_09991344, gUnk_0985BDEA, 0x400, 0, 0, &gUnk_09EF84A8, &gUnk_09EF84B8,
    1, 13, 0, 0, 0, 24, 54, 102, 0, &gTaskDescMapGmk06,
};

const char gTaskNameMapGmk06[] = "Task_MapGmk06";

const char gTaskNameMapPrize[] = "Task_MapPrize";

const char gTaskNameMapPrzCard[] = "Task_MapPrzCard";

const char gTaskNameMapPrzStock[] = "Task_MapPrzStock";

const char gTaskNameMapMsg[] = "Task_MapMsg";

const char gTaskNameMapMsg2[] = "Task_MapMsg2";

const char gTaskNameMapSpark[] = "Task_MapSpark";

const char gTaskNameMapTalk[] = "Task_MapTalk";

const u8 gUnk_0984C2E4[28] __attribute__((aligned(4))) = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 21, 21, 22, 22, 23, 23,
};

const char gTaskNameMapDonald[] = "Task_MapDonald";

const u8 gUnk_0984C310[28] __attribute__((aligned(4))) = {
    25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
    39, 40, 41, 42, 43, 44, 45, 46, 46, 46, 47, 47, 48, 48,
};

const char gTaskNameMapGoofy[] = "Task_MapGoofy";

const char gTaskNameMapNamine[] = "Task_MapNamine";

const char gTaskNameMapNiseriku[] = "Task_MapNiseriku";

const char gTaskNameMapMickey[] = "Task_MapMickey";

const char gTaskNameMapTutorial[] = "Task_MapTutorial";

const char gTaskNameMapStair[] = "Task_MapStair";

const char gTaskNameMapFaint[] = "Task_MapFaint";

const char gTaskNameMapDmg[] = "Task_MapDmg";

const char gTaskNameMapFloor[] = "Task_MapFloor";
TaskDesc gTaskDescMapEnm00 = {
    gTaskNameMapEnm00,
    (void (*)(void*, void*))Task_MapEnm00_0,
    Task_MapEnm00_1,
    (void (*)(void*))Task_MapEnm00_2,
    (void (*)(void*))Task_MapEnm00_3,
    0xF8,
};

TaskDesc gTaskDescMapEnm01 = {
    gTaskNameMapEnm01,
    (void (*)(void*, void*))Task_MapEnm01_0,
    Task_MapEnm01_1,
    (void (*)(void*))Task_MapEnm01_2,
    (void (*)(void*))Task_MapEnm01_3,
    0xFC,
};

TaskDesc gTaskDescMapEnm02 = {
    gTaskNameMapEnm02,
    (void (*)(void*, void*))Task_MapEnm02_0,
    Task_MapEnm02_1,
    (void (*)(void*))Task_MapEnm02_2,
    (void (*)(void*))Task_MapEnm02_3,
    0xF8,
};

TaskDesc gTaskDescMapEnm03 = {
    gTaskNameMapEnm03,
    (void (*)(void*, void*))Task_MapEnm03_0,
    Task_MapEnm03_1,
    (void (*)(void*))Task_MapEnm03_2,
    (void (*)(void*))Task_MapEnm03_3,
    0x108,
};

TaskDesc gTaskDescMapEnm04 = {
    gTaskNameMapEnm04,
    (void (*)(void*, void*))Task_MapEnm04_0,
    Task_MapEnm04_1,
    (void (*)(void*))Task_MapEnm04_2,
    (void (*)(void*))Task_MapEnm04_3,
    0xFC,
};

TaskDesc gTaskDescMapEnm05 = {
    gTaskNameMapEnm05,
    (void (*)(void*, void*))Task_MapEnm05_0,
    Task_MapEnm05_1,
    (void (*)(void*))Task_MapEnm05_2,
    (void (*)(void*))Task_MapEnm05_3,
    0xF8,
};

TaskDesc gTaskDescMapEnm06 = {
    gTaskNameMapEnm06,
    (void (*)(void*, void*))Task_MapEnm06_0,
    Task_MapEnm06_1,
    (void (*)(void*))Task_MapEnm06_2,
    (void (*)(void*))Task_MapEnm06_3,
    0xF8,
};

u8 gUnk_09EF6C38[] = "_";

TaskDesc gTaskDescMapDbg = {
    gTaskNameMapDbg,
    (void (*)(void*, void*))Task_MapDbg_0,
    Task_MapDbg_1,
    (void (*)(void*))Task_MapDbg_2,
    (void (*)(void*))Task_MapDbg_3,
    0x48,
};

TaskDesc gTaskDescMapGmkJump = {
    gTaskNameMapGmkJump,
    (void (*)(void*, void*))Task_MapGmk_Jump_0,
    Task_MapGmk_Jump_1,
    (void (*)(void*))Task_MapGmk_Jump_2,
    (void (*)(void*))Task_MapGmk_Jump_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkEnm = {
    gTaskNameMapGmkEnm,
    (void (*)(void*, void*))Task_MapGmk_Enm_0,
    Task_MapGmk_Enm_1,
    (void (*)(void*))Task_MapGmk_Enm_2,
    (void (*)(void*))Task_MapGmk_Enm_3,
    0x74,
};

TaskDesc gTaskDescMapGmkDmy = {
    gTaskNameMapGmkDmy,
    (void (*)(void*, void*))Task_MapGmk_Dmy_0,
    Task_MapGmk_Dmy_1,
    (void (*)(void*))Task_MapGmk_Dmy_2,
    (void (*)(void*))Task_MapGmk_Dmy_3,
    0x4,
};

TaskDesc gTaskDescMapGmkTutorial = {
    gTaskNameMapGmkTutorial,
    (void (*)(void*, void*))Task_MapGmk_Tutorial_0,
    Task_MapGmk_Tutorial_1,
    (void (*)(void*))Task_MapGmk_Tutorial_2,
    (void (*)(void*))Task_MapGmk_Tutorial_3,
    0xC4,
};

TaskDesc gTaskDescMapGmkSpider = {
    gTaskNameMapGmkSpider,
    (void (*)(void*, void*))Task_MapGmk_Spider_0,
    Task_MapGmk_Spider_1,
    (void (*)(void*))Task_MapGmk_Spider_2,
    (void (*)(void*))Task_MapGmk_Spider_3,
    0xC8,
};

TaskDesc gTaskDescMapGmkGP00 = {
    gTaskNameMapGmkGP00,
    (void (*)(void*, void*))Task_MapGmk_GP00_0,
    Task_MapGmk_GP00_1,
    (void (*)(void*))Task_MapGmk_GP00_2,
    (void (*)(void*))Task_MapGmk_GP00_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP01 = {
    gTaskNameMapGmkGP01,
    (void (*)(void*, void*))Task_MapGmk_GP01_0,
    Task_MapGmk_GP01_1,
    (void (*)(void*))Task_MapGmk_GP01_2,
    (void (*)(void*))Task_MapGmk_GP01_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP02 = {
    gTaskNameMapGmkGP02,
    (void (*)(void*, void*))Task_MapGmk_GP02_0,
    Task_MapGmk_GP02_1,
    (void (*)(void*))Task_MapGmk_GP02_2,
    (void (*)(void*))Task_MapGmk_GP02_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP03 = {
    gTaskNameMapGmkGP03,
    (void (*)(void*, void*))Task_MapGmk_GP03_0,
    Task_MapGmk_GP03_1,
    (void (*)(void*))Task_MapGmk_GP03_2,
    (void (*)(void*))Task_MapGmk_GP03_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP04 = {
    gTaskNameMapGmkGP04,
    (void (*)(void*, void*))Task_MapGmk_GP04_0,
    Task_MapGmk_GP04_1,
    (void (*)(void*))Task_MapGmk_GP04_2,
    (void (*)(void*))Task_MapGmk_GP04_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP05 = {
    gTaskNameMapGmkGP05,
    (void (*)(void*, void*))Task_MapGmk_GP05_0,
    Task_MapGmk_GP05_1,
    (void (*)(void*))Task_MapGmk_GP05_2,
    (void (*)(void*))Task_MapGmk_GP05_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP06 = {
    gTaskNameMapGmkGP06,
    (void (*)(void*, void*))Task_MapGmk_GP06_0,
    Task_MapGmk_GP06_1,
    (void (*)(void*))Task_MapGmk_GP06_2,
    (void (*)(void*))Task_MapGmk_GP06_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkGP07 = {
    gTaskNameMapGmkGP07,
    (void (*)(void*, void*))Task_MapGmk_GP07_0,
    Task_MapGmk_GP07_1,
    (void (*)(void*))Task_MapGmk_GP07_2,
    (void (*)(void*))Task_MapGmk_GP07_3,
    0xC8,
};

TaskDesc gTaskDescMapGmkGP08 = {
    gTaskNameMapGmkGP08,
    (void (*)(void*, void*))Task_MapGmk_GP08_0,
    Task_MapGmk_GP08_1,
    (void (*)(void*))Task_MapGmk_GP08_2,
    (void (*)(void*))Task_MapGmk_GP08_3,
    0xD0,
};

TaskDesc gTaskDescMapGmkGP09 = {
    gTaskNameMapGmkGP09,
    (void (*)(void*, void*))Task_MapGmk_GP09_0,
    Task_MapGmk_GP09_1,
    (void (*)(void*))Task_MapGmk_GP09_2,
    (void (*)(void*))Task_MapGmk_GP09_3,
    0xD0,
};

TaskDesc gTaskDescMapGmk00 = {
    gTaskNameMapGmk00,
    (void (*)(void*, void*))Task_MapGmk00_0,
    Task_MapGmk00_1,
    (void (*)(void*))Task_MapGmk00_2,
    (void (*)(void*))Task_MapGmk00_3,
    0xCC,
};

TaskDesc gTaskDescMapGmk01 = {
    gTaskNameMapGmk01,
    (void (*)(void*, void*))func_080F3BC4,
    Task_MapGmk01_1,
    (void (*)(void*))Task_MapGmk01_2,
    (void (*)(void*))Task_MapGmk01_3,
    0xCC,
};

TaskDesc gTaskDescMapGmkBarrel = {
    gTaskNameMapGmkBarrel,
    (void (*)(void*, void*))Task_MapGmk_Barrel_0,
    Task_MapGmk_Barrel_1,
    (void (*)(void*))Task_MapGmk_Barrel_2,
    (void (*)(void*))Task_MapGmk_Barrel_3,
    0xCC,
};

TaskDesc gTaskDescMapGmk04 = {
    gTaskNameMapGmk04,
    (void (*)(void*, void*))Task_MapGmk04_0,
    Task_MapGmk04_1,
    (void (*)(void*))Task_MapGmk04_2,
    (void (*)(void*))Task_MapGmk04_3,
    0xDC,
};

TaskDesc gTaskDescMapGmk05 = {
    gTaskNameMapGmk05,
    (void (*)(void*, void*))Task_MapGmk05_0,
    Task_MapGmk05_1,
    (void (*)(void*))Task_MapGmk05_2,
    (void (*)(void*))Task_MapGmk05_3,
    0xF4,
};

TaskDesc gTaskDescMapGmk06 = {
    gTaskNameMapGmk06,
    (void (*)(void*, void*))Task_MapGmk06_0,
    Task_MapGmk06_1,
    (void (*)(void*))Task_MapGmk06_2,
    (void (*)(void*))Task_MapGmk06_3,
    0xDC,
};

TaskDesc gTaskDescMapPrize = {
    gTaskNameMapPrize,
    (void (*)(void*, void*))Task_MapPrize_0,
    Task_MapPrize_1,
    (void (*)(void*))Task_MapPrize_2,
    (void (*)(void*))Task_MapPrize_3,
    0x98,
};

TaskDesc gTaskDescMapPrzCard = {
    gTaskNameMapPrzCard,
    (void (*)(void*, void*))Task_MapPrzCard_0,
    Task_MapPrzCard_1,
    (void (*)(void*))Task_MapPrzCard_2,
    (void (*)(void*))Task_MapPrzCard_3,
    0xE8,
};

TaskDesc gTaskDescMapPrzStock = {
    gTaskNameMapPrzStock,
    (void (*)(void*, void*))Task_MapPrzStock_0,
    Task_MapPrzStock_1,
    (void (*)(void*))Task_MapPrzStock_2,
    (void (*)(void*))Task_MapPrzStock_3,
    0x1C,
};

TaskDesc gTaskDescMapMsg = {
    gTaskNameMapMsg,
    (void (*)(void*, void*))func_080F58C4,
    Task_MapMsg_1,
    (void (*)(void*))func_080F596C,
    (void (*)(void*))func_080F59A0,
    0x18C,
};

TaskDesc gTaskDescMapMsg2 = {
    gTaskNameMapMsg2,
    (void (*)(void*, void*))func_080F58C4,
    Task_MapMsg2_1,
    (void (*)(void*))func_080F596C,
    (void (*)(void*))func_080F59A0,
    0x18C,
};

TaskDesc gTaskDescMapSpark = {
    gTaskNameMapSpark,
    (void (*)(void*, void*))func_080F5A00,
    Task_MapSpark_1,
    (void (*)(void*))Task_MapSpark_2,
    (void (*)(void*))Task_MapSpark_3,
    0x28,
};

TaskDesc gTaskDescMapTalk = {
    gTaskNameMapTalk,
    (void (*)(void*, void*))Task_MapTalk_0,
    func_080F5B68,
    (void (*)(void*))Task_MapTalk_2,
    (void (*)(void*))Task_MapTalk_3,
    0x2C,
};

TaskDesc gTaskDescMapDonald = {
    gTaskNameMapDonald,
    (void (*)(void*, void*))Task_MapDonald_0,
    Task_MapDonald_1,
    (void (*)(void*))Task_MapDonald_2,
    (void (*)(void*))Task_MapDonald_3,
    0xEC,
};

TaskDesc gTaskDescMapGoofy = {
    gTaskNameMapGoofy,
    (void (*)(void*, void*))Task_MapGoofy_0,
    Task_MapGoofy_1,
    (void (*)(void*))Task_MapGoofy_2,
    (void (*)(void*))Task_MapGoofy_3,
    0xEC,
};

TaskDesc gTaskDescMapNamine = {
    gTaskNameMapNamine,
    (void (*)(void*, void*))Task_MapNamine_0,
    Task_MapNamine_1,
    (void (*)(void*))Task_MapNamine_2,
    (void (*)(void*))Task_MapNamine_3,
    0xF0,
};

TaskDesc gTaskDescMapNiseriku = {
    gTaskNameMapNiseriku,
    (void (*)(void*, void*))Task_MapNiseriku_0,
    Task_MapNiseriku_1,
    (void (*)(void*))Task_MapNiseriku_2,
    (void (*)(void*))Task_MapNiseriku_3,
    0xEC,
};

TaskDesc gTaskDescMapMickey = {
    gTaskNameMapMickey,
    (void (*)(void*, void*))Task_MapMickey_0,
    Task_MapMickey_1,
    (void (*)(void*))Task_MapMickey_2,
    (void (*)(void*))Task_MapMickey_3,
    0xEC,
};

TaskDesc gTaskDescMapTutorial = {
    gTaskNameMapTutorial,
    (void (*)(void*, void*))Task_MapTutorial_0,
    Task_MapTutorial_1,
    (void (*)(void*))Task_MapTutorial_2,
    (void (*)(void*))Task_MapTutorial_3,
    0xF0,
};

TaskDesc gTaskDescMapStair = {
    gTaskNameMapStair,
    (void (*)(void*, void*))Task_MapStair_0,
    Task_MapStair_1,
    (void (*)(void*))Task_MapStair_2,
    (void (*)(void*))Task_MapStair_3,
    0x64,
};

TaskDesc gTaskDescMapFaint = {
    gTaskNameMapFaint,
    (void (*)(void*, void*))Task_MapFaint_0,
    Task_MapFaint_1,
    (void (*)(void*))Task_MapFaint_2,
    (void (*)(void*))Task_MapFaint_3,
    0x28,
};

TaskDesc gTaskDescMapDmg = {
    gTaskNameMapDmg,
    (void (*)(void*, void*))Task_MapDmg_0,
    Task_MapDmg_1,
    (void (*)(void*))Task_MapDmg_2,
    (void (*)(void*))Task_MapDmg_3,
    0xC,
};

MapNameText* gUnk_09EF6FCC[13] = {
#if defined(VERSION_US)
    gMapNameTextUs_0815B5F6,
    gMapNameTextUs_0815B630,
    gMapNameTextUs_0815B66C,
    gMapNameTextUs_0815B6A6,
    gMapNameTextUs_0815B6E2,
    gMapNameTextUs_0815B71C,
    gMapNameTextUs_0815B756,
    gMapNameTextUs_0815B794,
    gMapNameTextUs_0815B7D0,
    gMapNameTextUs_0815B80A,
    gMapNameTextUs_0815B844,
    gMapNameTextUs_0815B884,
    gMapNameTextUs_0815B8C2,
#elif defined(VERSION_JP)
    gMapNameTextJp_0814F52C,
    gMapNameTextJp_0814F53C,
    gMapNameTextJp_0814F54C,
    gMapNameTextJp_0814F55C,
    gMapNameTextJp_0814F56C,
    gMapNameTextJp_0814F57C,
    gMapNameTextJp_0814F58C,
    gMapNameTextJp_0814F59C,
    gMapNameTextJp_0814F5AC,
    gMapNameTextJp_0814F5BC,
    gMapNameTextJp_0814F5D0,
    gMapNameTextJp_0814F5E4,
    gMapNameTextJp_0814F5F8,
#elif defined(VERSION_EU)
    &gMapNameEu_08893480,
    &gMapNameEu_0889352C,
    &gMapNameEu_088935D8,
    &gMapNameEu_08893684,
    &gMapNameEu_08893730,
    &gMapNameEu_088937DC,
    &gMapNameEu_0889388C,
    &gMapNameEu_08893938,
    &gMapNameEu_088939E4,
    &gMapNameEu_08893A94,
    &gMapNameEu_08893B48,
    &gMapNameEu_08893BFC,
    &gMapNameEu_08893CB8,
#endif
};

MapNameText* gUnk_09EF7000[12] = {
#if defined(VERSION_US)
    gMapNameTextUs_0815B906,
    gMapNameTextUs_0815B948,
    gMapNameTextUs_0815B98A,
    gMapNameTextUs_0815B9C6,
    gMapNameTextUs_0815BA04,
    gMapNameTextUs_0815BA44,
    gMapNameTextUs_0815BA84,
    gMapNameTextUs_0815BAC0,
    gMapNameTextUs_0815BAFE,
    gMapNameTextUs_0815BB3C,
    gMapNameTextUs_0815BB7C,
    gMapNameTextUs_0815BBB8,
#elif defined(VERSION_JP)
    gMapNameTextJp_0814F60C,
    gMapNameTextJp_0814F624,
    gMapNameTextJp_0814F63C,
    gMapNameTextJp_0814F654,
    gMapNameTextJp_0814F668,
    gMapNameTextJp_0814F67C,
    gMapNameTextJp_0814F690,
    gMapNameTextJp_0814F6A4,
    gMapNameTextJp_0814F6B8,
    gMapNameTextJp_0814F6CC,
    gMapNameTextJp_0814F6E0,
    gMapNameTextJp_0814F6F4,
#elif defined(VERSION_EU)
    &gMapNameEu_08893D78,
    &gMapNameEu_08893E38,
    &gMapNameEu_08893EF4,
    &gMapNameEu_08893FAC,
    &gMapNameEu_08894068,
    &gMapNameEu_08894124,
    &gMapNameEu_088941DC,
    &gMapNameEu_08894294,
    &gMapNameEu_0889434C,
    &gMapNameEu_08894408,
    &gMapNameEu_088944C0,
    &gMapNameEu_08894578,
#endif
};

TaskDesc gTaskDescMapFloor = {
    gTaskNameMapFloor,
    (void (*)(void*, void*))Task_MapFloor_0,
    Task_MapFloor_1,
    (void (*)(void*))Task_MapFloor_2,
    (void (*)(void*))Task_MapFloor_3,
#ifdef VERSION_EU
    0x1F8,
#else
    0x158,
#endif
};
