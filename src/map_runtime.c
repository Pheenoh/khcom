#include "map_index_assets.h"
#include "boss_map_block_assets.h"
#include "registration_data.h"
#include "map_api.h"
#include "msg_api.h"
#include "status_api.h"
#include "m4a_song.h"
#include "monsgage.h"
#include "bos4.h"
#include "bos4_api.h"
#include "map_runtime.h"
#include "map_text_data.h"

extern UnkStruct_0984C868 gUnk_0984C868[];
extern UnkStruct_0984C868 gUnk_0984CBD0[];
extern u8 gUnk_09EF69E0[];
extern u8 gUnk_09EF69EE[];
extern const MapNameText* gUnk_09EF69FC[];

u8 func_080DEBAC(u8 a) {
    switch (a) {
    case 0:
        a = 1;
        break;
    case 1:
        a = 0;
        break;
    case 2:
        a = 3;
        break;
    case 3:
        a = 2;
        break;
    }

    return a;
}

void func_080DEBD8(UnkStruct_080DEDD8* p) {
    UnkStruct_080DEE18* e;

    if (p->unk_00 == 1 || p->unk_00 == 4) {
        e = func_080DEE18(p->unk_02);
        e->unk_0A = 0;
        e->unk_08 = 26;
        e->unk_09 = 0;
        e->unk_00 |= 8;
    }
}

void func_080DEC00(void) {
    if (gGameState.flags & 8) {
        switch ((s8)gGameState.floor) {
        case 1:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            gUnk_0203C590.unk_07 = 5;
            break;
        }
    } else {
        if ((s8)gGameState.floor != 12) {
            gUnk_0203C590.unk_07 = 5;
        }
    }
}

void func_080DEC44(void) {
    u16 t;

    if ((s8)gGameState.floor != func_080DF750() || gUnk_0203C590.unk_06 == 0xFE
            || gUnk_0203C590.unk_06 == 0xFD) {
        if ((gGameState.flags & 0x80) == 0) {
            gGameState.flags |= 0x80;
            gGameState.progression.unk_86 = gGameState.progression.unk_84 & 0x7C;
        }

        if ((gGameState.flags & 8) != 0) {
            return;
        }

        t = gGameState.progression.unk_84 & 0xFF83;
        gGameState.progression.unk_84 = t;

        if (gUnk_0203C590.unk_06 >= 0xFD && gUnk_0203C590.unk_06 <= 0xFE) {
            return;
        }

        switch (gUnk_0203C590.unk_04) {
        case 1:
            t = 4 | gGameState.progression.unk_84;
            gGameState.progression.unk_84 = t;
            break;
        case 2:
            t = 8 | gGameState.progression.unk_84;
            gGameState.progression.unk_84 = t;
            break;
        case 6:
            t = 0x10 | gGameState.progression.unk_84;
            gGameState.progression.unk_84 = t;
            break;
        case 7:
            t = 0x20 | gGameState.progression.unk_84;
            gGameState.progression.unk_84 = t;
            break;
        case 8:
            t = 0x40 | gGameState.progression.unk_84;
            gGameState.progression.unk_84 = t;
            break;
        case 3:
        case 4:
        case 5:
        default:
            break;
        }
    } else {
        if ((gGameState.flags & 0x80) == 0) {
            return;
        }

        gGameState.flags &= ~0x80;
        t = (gGameState.progression.unk_84 & 0xFF83) | gGameState.progression.unk_86;
        gGameState.progression.unk_84 = t;
    }
}

UnkStruct_0984C868* func_080DED64(u8 a) {
    if (gGameState.flags & 8) {
        return &gUnk_0984CBD0[a];
    }

    return &gUnk_0984C868[a];
}

u8* func_080DED98(u8 a) {
    if (gGameState.flags & 8) {
        return gUnk_0984CBD0[(s8)gGameState.floor].unk_04 + a * 4;
    }

    return gUnk_0984C868[(s8)gGameState.floor].unk_04 + a * 4;
}

UnkStruct_080DEDD8* func_080DEDD8(u8 a) {
    if (gGameState.flags & 8) {
        return gUnk_0984CBD0[(s8)gGameState.floor].unk_08 + a;
    }

    return gUnk_0984C868[(s8)gGameState.floor].unk_08 + a;
}

UnkStruct_080DEE18* func_080DEE18(u8 index) {
    return &gUnk_0203C590.unk_1C[index];
}

u8 func_080DEE28(u8 a, u8 b) {
    return func_080DED98(a)[b];
}

u16 func_080DEE44(u8 a, u8 b) {
    UnkStruct_080DEE18* e;
    UnkStruct_080DEDD8* p;
    u16 r;
    u8 c;
    u8 d;

    c = func_080DEE28(a, b);

    if (c == 0xFF) {
        return 0;
    }

    if (c >= 0xFD && c <= 0xFE) {
        return 3;
    }

    e = func_080DEE18(c);
    r = 1;

    if ((e->unk_00 & 1) != 0) {
        r = 3;
    }

    if ((e->unk_00 & 8) != 0) {
        r |= 8;
    }

    if ((e->unk_00 & 4) != 0) {
        r |= 8;
    }

    d = func_080DF51C(c);

    if (d == 1 || d == 4 || d == 2) {
        r |= 0x10;
        p = func_080DEDD8(0);

        while (p->unk_00 != 5) {
            if (p->unk_02 == c) {
                if (p->unk_03 != b) {
                    r |= 8;
                }

                break;
            }

            p++;
        }
    }

    if ((gUnk_0203C590.unk_02 & 8) != 0) {
        p = func_080DEDD8(*func_080E54B8(gUnk_0203C590.unk_05));

        if (p->unk_02 == c && p->unk_03 == b) {
            r |= 2;
        }
    }

    return r;
}
void func_080DEF20(void) {
    u16 t;

    switch (gUnk_0203C590.unk_06) {
    case 0xFD:
    case 0xFE:
        gGameState.world = 0;
        gGameState.unk_00D = 12;
        break;
    case 0xFC:
        gGameState.world = 10;
        gGameState.unk_00D = 11;
        break;
    default:
        gGameState.world = gUnk_0203C590.unk_04;
        gGameState.unk_00D = gUnk_09EF69E0[gUnk_0203C590.unk_04];
        break;
    }

    if ((gGameState.flags & 8) != 0) {
        _08085D04(gGameState.world);

        if ((gGameState.flags & 8) != 0) {
            t = gGameState.progression.unk_84 & 0xFF80;
            gGameState.progression.unk_84 = t;
            return;
        }
    }

    switch (gGameState.world) {
    case 0:
        break;
    case 1:
        t = gGameState.progression.unk_84 & 0xFF07;
        gGameState.progression.unk_84 = t;
        break;
    case 2:
        t = gGameState.progression.unk_84 & 0xFF0B;
        gGameState.progression.unk_84 = t;
        break;
    case 6:
        t = gGameState.progression.unk_84 & 0xFF13;
        gGameState.progression.unk_84 = t;
        break;
    case 7:
        t = gGameState.progression.unk_84 & 0xFF23;
        gGameState.progression.unk_84 = t;
        break;
    case 8:
        t = gGameState.progression.unk_84 & 0xFF43;
        gGameState.progression.unk_84 = t;
        break;
    case 3:
    case 4:
    case 5:
    default:
        t = gGameState.progression.unk_84 & 0xFF03;
        gGameState.progression.unk_84 = t;
        break;
    }
}
void func_080DF048(void) {
    if ((gGameState.flags & 8) != 0) {
        switch (gGameState.world) {
        case 1:
            func_0800FDD0(57);
            break;
        case 2:
            func_0800FDD0(67);
            break;
        case 3:
            func_0800FDD0(50);
            break;
        case 6:
            func_0800FDD0(61);
            break;
        case 7:
            func_0800FDD0(72);
            break;
        case 8:
            func_0800FDD0(75);
            break;
        }
    } else {
        switch (gGameState.world) {
        case 10:
            func_0800FDD0(4);
            func_0800FDD0(28);
            func_0800FDD0(29);
            func_0800FDD0(30);
            func_0800FDD0(31);
            break;
        case 4:
            func_0800FDD0(5);
            func_0800FDD0(42);
            func_0800FDD0(43);
            func_0800FDD0(44);
            func_0800FDD0(45);
            func_0800FDD0(46);
            func_0800FDD0(47);
            break;
        case 3:
            func_0800FDD0(6);
            func_0800FDD0(32);
            func_0800FDD0(48);
            func_0800FDD0(49);
            func_0800FDD0(50);
            break;
        case 1:
            func_0800FDD0(7);
            func_0800FDD0(51);
            func_0800FDD0(52);
            func_0800FDD0(53);
            func_0800FDD0(54);
            func_0800FDD0(55);
            func_0800FDD0(56);
            func_0800FDD0(57);
            break;
        case 6:
            func_0800FDD0(8);
            func_0800FDD0(58);
            func_0800FDD0(59);
            func_0800FDD0(60);
            func_0800FDD0(61);
            break;
        case 5:
            func_0800FDD0(9);
            func_0800FDD0(62);
            func_0800FDD0(63);
            break;
        case 2:
            func_0800FDD0(10);
            func_0800FDD0(64);
            func_0800FDD0(65);
            func_0800FDD0(66);
            func_0800FDD0(67);
            func_0800FDD0(68);
            break;
        case 7:
            func_0800FDD0(11);
            func_0800FDD0(69);
            func_0800FDD0(70);
            func_0800FDD0(71);
            func_0800FDD0(72);
            break;
        case 8:
            func_0800FDD0(12);
            func_0800FDD0(73);
            func_0800FDD0(74);
            func_0800FDD0(75);
            func_0800FDD0(76);
            break;
        case 11:
            func_0800FDD0(14);
            break;
        case 9:
            func_0800FDD0(15);
            func_0800FDD0(33);
            func_0800FDD0(34);
            func_0800FDD0(35);
            break;
        }
    }
}
void func_080DF244(void) {
    if ((gGameState.flags & 8) != 0) {
        switch ((s8)gGameState.floor) {
        case 0:
            func_0800FDD0(1);
            break;
        case 2:
            func_0800FDD0(0x28);
            break;
        case 4:
            func_0800FDD0(2);
            func_0800FDD0(0xEE);
            break;
        case 8:
            func_0800FDD0(3);
            func_0800FDD0(0xF0);
            break;
        case 9:
            func_0800FDD0(0xEB);
            func_0800FDD0(0xF1);
            break;
        case 10:
            func_0800FDD0(0xEC);
            func_0800FDD0(0x24);
            func_0800FDD0(0x26);
            func_0800FDD0(0x29);
            func_0800FDD0(0x27);
            func_0800FDD0(0xF2);
            break;
        }
    } else {
        switch ((s8)gGameState.floor) {
        case 0:
            func_0800FDD0(0);
            func_0800FDD0(0x26);
            break;
        case 5:
            func_0800FDD0(1);
            func_0800FDD0(0x27);
            break;
        case 8:
            func_0800FDD0(2);
            break;
        case 9:
            func_0800FDD0(0x28);
            break;
        case 11:
            func_0800FDD0(3);
            func_0800FDD0(0x24);
            func_0800FDD0(0x25);
            break;
        }
    }
}
void func_080DF380(void) {
    u8* e = func_080E54B8(gUnk_0203C590.unk_05);
    UnkStruct_080DEDD8* p;
    UnkStruct_080DEE18* q;
    u16 t;
    u16 u;
    u16 v;

    if (gUnk_0203C590.unk_06 == 0xFE) {
        t = gUnk_0203C590.unk_02 | 2;
        gUnk_0203C590.unk_02 = t;

        if ((gGameState.flags & 8) != 0) {
            if ((s8)gGameState.floor == 0x0A) {
                gUnk_0203C590.unk_00++;
            }
        } else {
            if ((s8)gGameState.floor == 0) {
                gUnk_0203C590.unk_06 = 0xFC;
                gUnk_0203C590.unk_07 = 5;
                return;
            }

            if ((s8)gGameState.floor == 0x0C) {
                gUnk_0203C590.unk_00++;
            }
        }

        func_080DFA3C();
    } else if (gUnk_0203C590.unk_06 == 0xFD) {
        u = gUnk_0203C590.unk_02 | 1;
        gUnk_0203C590.unk_02 = u;
        func_080DF244();
        gUnk_0203C590.unk_00++;
        func_080DFAA8();
        func_080DF9A8();
        func_080DEC00();
    } else if (e[0] == 0xFF) {
        v = gUnk_0203C590.unk_02 | 4;
        gUnk_0203C590.unk_02 = v;
        gUnk_0203C590.unk_00++;
        func_080DF730(0xFD, 5);
    } else {
        t = gUnk_0203C590.unk_02 & ~8;
        gUnk_0203C590.unk_02 = t;
        p = func_080DEDD8(e[0]);
        func_080DEBD8(p);
        func_080DF640(p->unk_04, 0);
        func_080DF730(p->unk_04, p->unk_05);
        gUnk_0203C590.unk_05++;

        if (e[4] == 0xFF) {
            q = func_080DEE18(func_080DED64(gGameState.floor)->unk_01);
            t = q->unk_00 & ~4;
            q->unk_00 = t;
            gUnk_0203C590.unk_02 |= 0x20;
            func_080DF048();
        }
    }
}

void func_080DF480(void) {
    gUnk_0203C590.unk_00++;
    func_080DF730(0xFD, 5);
}

u8 func_080DF49C(void) {
    u8* e = func_080E54B8(gUnk_0203C590.unk_05);
    UnkStruct_02034F7C* t = &gUnk_0984CECC[func_080DEDD8(*e)->unk_01];
    UnkStruct_02034F80* q;

    t += *e;
    q = t->unk_04;

    while (q->unk_00 == 0xFF) {
        q++;
    }

    return q->unk_00;
}

u8 func_080DF4D8(void) {
    if (func_080E8C84(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10) != 0) {
        return func_080E8D1C(0)->unk_00;
    }

    return 0xFF;
}

u8 func_080DF500(void) {
    return func_080E8C84(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
}

u8 func_080DF51C(u8 a) {
    UnkStruct_080DEDD8* p = func_080DEDD8(0);

    while (p->unk_00 != 5) {
        if (p->unk_02 == a) {
            return p->unk_00;
        }

        p++;
    }

    return 0;
}

s32 func_080DF548(u8 a) {
    u8* p;
    u8* q;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }

    p = (u8*)&gUnk_0203C590;
    q = p + a * 0x10;

    return q[0x26];
}

void func_080DF570(u8 a) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    UnkStruct_080DEDD8* p = func_080DEDD8(0);

    while (p->unk_00 != 5) {
        if (p->unk_02 == a) {
            if (p->unk_00 == 2) {
                e->unk_0A = 0;
                e->unk_08 = 27;
                e->unk_09 = 22;
                return;
            }

            gUnk_0203C590.unk_02 |= 8;
            e->unk_0A = 0;
            e->unk_08 = 26;
            e->unk_09 = 0;
        }

        p++;
    }

    if (func_080DED64(gGameState.floor)->unk_01 != a) {
        e->unk_0A = 0;
        e->unk_08 = 26;
        e->unk_09 = 0;
        return;
    }

    e->unk_0A = 0;
    e->unk_08 = 5;
    e->unk_09 = 23;
}

u8 func_080DF5F4(void) {
    if ((gGameState.flags & 8) == 0) {
        return GetRandom() % 21 + 1;
    }

    return gUnk_09EF69EE[GetRandom() % 13];
}

void func_080DF640(u8 a, UnkStruct_080DF640* p) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    const u8* row;
    const u8* anim;

    if (p == 0 && (e->unk_00 & 1) != 0) {
        return;
    }

    e->unk_00 &= ~0x10;
    e->unk_00 &= ~0x20;
    e->unk_00 |= 1;
    e->unk_04 = gFrameCounter * gFrameCounter;

    if (p != 0) {
        row = gUnk_0984D0CC[p->unk_00];
        e->unk_0A = p->unk_02;
        e->unk_08 = row[0];

        if (row[1] != 25) {
            e->unk_09 = row[1];
        } else {
            e->unk_09 = func_080DF5F4();
        }
    } else {
        func_080DF570(a);
    }

    anim = gUnk_0984D134[e->unk_09];
    e->unk_0B = anim[2];
    e->unk_0C = anim[6];
}

void func_080DF6D0(UnkStruct_0203C7AC* p, u8 a) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    const u8* row;
    u16 t;

    t = e->unk_00 | 2;
    e->unk_00 = t;
    SeedRandom(e->unk_04);
    gUnk_0203C7AC->unk_0C = e->unk_08;
    gUnk_0203C7AC->unk_0D = e->unk_09;

    if (gUnk_0203C584 == 0) {
        row = gUnk_0984D134[e->unk_09];
        gGameState.unk_1B8 = row[5];
        func_080E5510(row[0]);
    }
}

void func_080DF730(u8 a, u8 b) {
    gUnk_0203C590.unk_06 = a;
    gUnk_0203C590.unk_07 = func_080DEBAC(b);
    func_080DEC44();
}

u8 func_080DF750(void) {
    if ((gGameState.flags & 8) != 0) {
        if (gUnk_0203C590.unk_00 > 0x16) {
            return 11;
        }

        if (gUnk_0203C590.unk_00 > 0x13) {
            return 10;
        }

        if (gUnk_0203C590.unk_00 > 0x11) {
            return 9;
        }

        if (gUnk_0203C590.unk_00 > 0x0F) {
            return 8;
        }

        if (gUnk_0203C590.unk_00 > 0x0D) {
            return 7;
        }

        if (gUnk_0203C590.unk_00 > 0x0B) {
            return 6;
        }

        if (gUnk_0203C590.unk_00 > 0x09) {
            return 5;
        }

        if (gUnk_0203C590.unk_00 > 0x07) {
            return 4;
        }

        if (gUnk_0203C590.unk_00 > 0x05) {
            return 3;
        }

        if (gUnk_0203C590.unk_00 > 0x03) {
            return 2;
        }

        if (gUnk_0203C590.unk_00 <= 0x01) {
            return 0;
        }

        return 1;
    }

    if (gUnk_0203C590.unk_00 > 0x18) {
        return 12;
    }

    if (gUnk_0203C590.unk_00 > 0x15) {
        return 11;
    }

    if (gUnk_0203C590.unk_00 > 0x13) {
        return 10;
    }

    if (gUnk_0203C590.unk_00 > 0x11) {
        return 9;
    }

    if (gUnk_0203C590.unk_00 > 0x0F) {
        return 8;
    }

    if (gUnk_0203C590.unk_00 > 0x0D) {
        return 7;
    }

    if (gUnk_0203C590.unk_00 > 0x0B) {
        return 6;
    }

    if (gUnk_0203C590.unk_00 > 0x09) {
        return 5;
    }

    if (gUnk_0203C590.unk_00 > 0x07) {
        return 4;
    }

    if (gUnk_0203C590.unk_00 > 0x05) {
        return 3;
    }

    if (gUnk_0203C590.unk_00 > 0x03) {
        return 2;
    }

    if (gUnk_0203C590.unk_00 <= 0x01) {
        return 0;
    }

    return 1;
}

u32 func_080DF804(u8 index) {
#ifdef VERSION_EU
    return (u32)eu_0805E924(gUnk_09EF69FC[index]);
#else
    return (u32)gUnk_09EF69FC[index];
#endif
}

void func_080DF814(void) {
    func_080DF730(0xFE, 1);
    func_080E04EC();
}

void func_080DF828(void) {
    u8 v;
    u16 f;

    if ((gUnk_0203C590.unk_02 & 4) != 0) {
        v = 0xFF;
    } else {
        if ((gGameState.flags & 8) != 0) {
            v = gUnk_0984B851[(s8)gGameState.floor];
        } else {
            v = gUnk_0984B844[(s8)gGameState.floor];
        }
    }

    if (v != 0xFF) {
        gGameState.world = 0;
        gGameState.unk_00D = 12;
        gGameState.unk_1B8 = 0;

        if ((gGameState.flags & 8) != 0) {
            _08085D04(0);
        }

        func_0806180C(v);
    } else {
        if ((gUnk_0203C590.unk_02 & 4) == 0) {
            f = gUnk_0203C590.unk_02 | 4;
            gUnk_0203C590.unk_02 = f;
            gUnk_0203C590.unk_00++;
        }

        func_080DF730(0xFD, 0);
        func_080E04EC();
    }
}
void func_080DF8C0(u8 a, u8 b) {
    s32 i;
    u16 t;

    gUnk_0203C590.unk_02 = gGameState.floors[(s8)gGameState.floor].unk_00;
    gUnk_0203C590.unk_04 = gGameState.floors[(s8)gGameState.floor].world;
    gUnk_0203C590.unk_05 = gGameState.floors[(s8)gGameState.floor].unk_03;
    gUnk_0203C590.unk_06 = a;
    gUnk_0203C590.unk_07 = b;

    for (i = 0; i <= 3; i++) {
        gUnk_0203C590.unk_18[i] = 0;
        gUnk_0203C590.unk_08[i][0] = 0;
        gUnk_0203C590.unk_08[i][1] = 0;
    }

    for (i = 0; i < 32; i++) {
        gUnk_0203C590.unk_1C[i].unk_00 = 0;
        gUnk_0203C590.unk_1C[i].unk_04 = 0;
        gUnk_0203C590.unk_1C[i].unk_08 = 0;
        gUnk_0203C590.unk_1C[i].unk_0A = 0;
        gUnk_0203C590.unk_1C[i].unk_09 = 0;
    }

    gGameState.unk_00F = 0xFF;
    t = gUnk_0203C590.unk_02 | 0x100;
    gUnk_0203C590.unk_02 = t;
}

void func_080DF964(void) {
    s32 i;

    for (i = 0; i < gUnk_0203C590.unk_05; i++) {
        func_080DEBD8(func_080DEDD8(*func_080E54B8(i)));
    }
}

void func_080DF990(u8 a) {
    gGameState.floor = a;
    func_080DF8C0(0xFE, 0);
}

void func_080DF9A8(void) {
    gGameState.floor++;
    func_080DF8C0(0xFE, 1);
}

void func_080DF9C4(void) {
    gGameState.floor--;
    func_080DF8C0(0xFD, 0);
}

void func_080DF9E0(u8 a) {
    u16 t;

    func_0801CB00();
    func_080DFAA8();
    func_080DF990(a);
    gUnk_0203C590.unk_06 = 0xFE;
    gUnk_0203C590.unk_07 = 5;
    t = gUnk_0203C590.unk_02 | 0x80;
    gUnk_0203C590.unk_02 = t;
    func_080E04EC();
}

void func_080DFA18(u8 a) {
    gUnk_0203C590.unk_04 = a;
    gGameState.floors[(s8)gGameState.floor].world = a;
}

void func_080DFA3C(void) {
    UnkStruct_0984C868* e = func_080DED64(gGameState.floor);
    UnkStruct_080DEE18* p;
    u16 t;

    if ((s8)gGameState.floor == 13) {
        gGameState.floor = 0;
    }

    if (gUnk_0203C590.unk_06 == 0xFD) {
        func_080DF730(e->unk_01, 1);
    } else {
        func_080DF730(e->unk_00, 0);
    }

    func_080DF964();

    if ((gUnk_0203C590.unk_02 & 0x20) == 0) {
        p = func_080DEE18(e->unk_01);
        t = p->unk_00 | 4;
        p->unk_00 = t;
    }

    func_080DF640(gUnk_0203C590.unk_06, 0);
}

void func_080DFAA8(void) {
    gGameState.floors[(s8)gGameState.floor].unk_00 = gUnk_0203C590.unk_02;
    gGameState.floors[(s8)gGameState.floor].world = gUnk_0203C590.unk_04;
    gGameState.floors[(s8)gGameState.floor].unk_03 = gUnk_0203C590.unk_05;
}

void func_080DFAF4(u8 a, u8 b) {
    func_080DF990(a);
    func_080DFA18(b);

    if (a == 0) {
        gUnk_0203C590.unk_00 = 0;
        gUnk_0203C590.unk_02 &= 0xFEFF;
    }
}

void func_080DFB2C(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        gGameState.floors[i].unk_00 = 0;
        gGameState.floors[i].world = 0;
        gGameState.floors[i].unk_03 = 0;
    }

    gUnk_0203C590.unk_00 = 0;

    if ((gGameState.flags & 8) == 0) {
        func_08085C3C();
    }

    func_080DF990(0);
}

struct UnkStruct_02034F24* func_080DFB7C(u8 a) {
    return func_080E5590(a);
}

MapCell* func_080DFB8C(s32 x, s32 y) {
    s16 a = x / 0x2000;
    s16 b = y / 0x1000;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        return func_080E58F8(a, b);
    }

    return func_080E548C(a, b);
}

u8 func_080DFBDC(UnkStruct_080DFF1C* p) {
    s32 y = p->x + p->z;
    MapCell* q = func_080DFB8C(p->unk_00, y);

    if (q == 0) {
        return 1;
    }

    if (q->unk_08 >= p->y && q->unk_0C != 0x100000) {
        return 0;
    }

    return func_080E86C8(q, p->unk_00, y);
}

u8 func_080DFC24(void) {
    if (gUnk_0203C7AC->unk_00 & 0x100) {
        if (gUnk_0203C590.unk_04 != 0) {
            return 2;
        }

        if ((gGameState.flags & 8) == 0 && (s8)gGameState.floor == 12) {
            func_080DFA18(12);
            return 2;
        }

        return 1;
    }

    return 0;
}

void func_080DFC7C(void) {
    gUnk_0203C7AC->unk_00 &= ~0x100;
}

u8 func_080DFC94(UnkStruct_080DFF1C* p, s32 x, s32 y) {
    s32 old;

    if (func_080DFBDC(p) != 0) {
        p->unk_00 = x;
        p->x = y;
        return 1;
    }

    old = p->z;
    p->z = func_080DFF1C(p);

    if (old != p->z) {
        if (func_080DFBDC(p) != 0) {
            p->unk_00 = x;
            p->x = y;
            p->z = old;
            return 1;
        }
    }

    return 0;
}

u8 func_080DFCDC(UnkStruct_080DFF1C* p) {
    s32 i;
    u16 a;
    u16 b;
    UnkStruct_080DFB7C* e;
    u8 r = 0;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }

    if ((gGameState.progression.unk_82 & 0x200) == 0) {
        return 0;
    }

    if (p->y != p->z) {
        return 0;
    }

    a = (p->unk_00 >> 8) / 32;
    b = ((p->x + p->y) >> 8) / 16;

    for (i = 0; i <= 3; i++) {
        e = (UnkStruct_080DFB7C*)func_080DFB7C(i);

        if ((e->unk_00 & 1) != 0 && (e->unk_00 & 0xA) == 2 && e->unk_02 == a && e->unk_04 == b) {
            gUnk_0203C7AC->unk_0F = e->unk_07;
            gUnk_0203C7AC->unk_10 = e->unk_06;
            r = 1;
            break;
        }
    }

    return r;
}
u8 func_080DFD84(UnkStruct_080DFF1C* p) {
    s32 i;
    u16 a;
    u16 b;
    UnkStruct_080DFB7C* e;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        return (u32)gUnk_0203C7AC->unk_00 >> 9 & 1;
    }

    if (p->y != p->z) {
        return 0;
    }

    a = (p->unk_00 >> 8) / 32;
    b = ((p->x + p->y) >> 8) / 16;

    for (i = 0; i <= 3; i++) {
        e = (UnkStruct_080DFB7C*)func_080DFB7C(i);

        if ((e->unk_00 & 1) != 0 && (e->unk_00 & 0xA) == 2 && e->unk_02 == a && e->unk_04 == b
                && e->unk_07 == gUnk_0203C7AC->unk_0F && e->unk_06 == gUnk_0203C7AC->unk_10) {
            return 1;
        }
    }

    return 0;
}

u8 _080DFE1C(UnkStruct_080DFF1C* p) {
    MapCell* q = func_080DFB8C(p->unk_00, p->x + p->z);

    if (q->unk_00 & 0x20) {
        switch (q->unk_02) {
        case 3:
        case 4:
        case 8:
            return 2;
        case 5:
        case 6:
        case 9:
            return 1;
        case 7:
            return 0;
        }
    }

    return 0;
}

s32 func_080DFE7C(s32 x, s32 y, s32 z) {
    MapCell* p;
    s32 r;

    y += z;
    p = func_080DFB8C(x, y);

    if (p == 0) {
        return 0;
    }

    if (p->unk_02 == 4 || p->unk_02 == 6) {
        if (func_080E86C8(p, x, y) != 0) {
            r = p->unk_0C;
        } else {
            r = p->unk_08;
        }
    } else {
        r = p->unk_0C;
    }

    return r;
}

#ifdef VERSION_EU
const LocalizedText gMapWorldNameEu_088926FC = {{gMapWorldNameTextEu_08892680, gMapWorldNameTextEu_08892696, gMapWorldNameTextEu_088926AC, gMapWorldNameTextEu_088926C9, gMapWorldNameTextEu_088926E0}};
#endif

u8 gUnk_09EF69E0[14] = {
    12,
    3,
    4,
    6,
    1,
    5,
    7,
    8,
    10,
    9,
    11,
    13,
    12,
};

u8 gUnk_09EF69EE[14] = {
    1,
    2,
    4,
    5,
    6,
    7,
    8,
    13,
    14,
    15,
    16,
    17,
    18,
};

const MapNameText* gUnk_09EF69FC[14] = {
#if defined(VERSION_US)
    gMapWorldNameTextUs_0815B57A,
    gUnk_0815A56C,
    gUnk_0815A5AA,
    gUnk_0815A54A,
    gUnk_0815A534,
    gUnk_0815A59A,
    gUnk_0815A57C,
    gUnk_0815A5BE,
    gUnk_0815A5D4,
    gUnk_0815A62A,
    gUnk_0815A518,
    gUnk_0815A60E,
    gUnk_0815A64A,
    gUnk_0815A5F2,
#elif defined(VERSION_JP)
    gMapWorldNameTextJp_0814F2E0,
    gUnkJp_0814E590,
    gUnkJp_0814E5E4,
    gUnkJp_0814E5CC,
    gUnkJp_0814E59C,
    gUnkJp_0814E5AC,
    gUnkJp_0814E5B8,
    gUnkJp_0814E5F4,
    gUnkJp_0814E618,
    gUnkJp_0814E62C,
    gUnkJp_0814E57C,
    gUnkJp_0814E644,
    gUnkJp_0814E658,
    gUnkJp_0814E604,
#elif defined(VERSION_EU)
    &gMapWorldNameEu_088926FC,
    &gUnkEu_0888E3A0,
    &gUnkEu_0888E578,
    &gUnkEu_0888E530,
    &gUnkEu_0888E410,
    &gUnkEu_0888E450,
    &gUnkEu_0888E4C0,
    &gUnkEu_0888E5DC,
    &gUnkEu_0888E6BC,
    &gUnkEu_0888E72C,
    &gUnkEu_0888E364,
    &gUnkEu_0888E78C,
    &gUnkEu_0888E804,
    &gUnkEu_0888E654,
#endif
};
