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
#include "sprites_card_pictures.h"

s16 gUnk_02034AB4;

u8 gUnk_02034AB6[2];
#ifdef VERSION_EU
u8 gUnkEu_02034AD4[4];
#endif

u8 func_0807CE68(CardDisplayWork* p);
void func_0807C39C(CardDisplayWork* p);
void func_0807C33C(CardDisplayWork* p);
void func_0807CD48(CardDisplayWork* p);
u8 func_0807CF4C(u8* work, void* a);
u8 func_0809075C(CardDisplayWork* p, void* a);
u8 func_08090808(u8* work, void* a);
u8 func_08090940(CardDisplayWork* p);
u8 EnemyUsecard_1(CardDisplayWork* p, void* a);
u8 func_0807BA54(void);
void func_0807C33C(CardDisplayWork* p);
void func_0807C39C(CardDisplayWork* p);
void func_0807CD48(CardDisplayWork* p);
u8 func_0807CE68(CardDisplayWork* p);
u8 func_0807CF4C(u8* work, void* a);
u8 func_0807CFA8(CardDisplayWork* p, void* a);

const s32 gUnk_09035978[10] = {
    0x11000, 0xBC00, 0xDC00, 0x5800, 0xDC00, 0x4400, 0xDC00, 0x3000, 0x10400, 0xB800,
};

void func_080901E0(s32* a, u8* b, u8 c) {
    s32* t;
    s32 v;
    s32 id;

    t = (s32*)a[1];
    v = a[2];

    if (v != -1) {
        *(u16*)&b[0x14] = v;
    }

    if (t != 0) {
        id = *(s32*)((u8*)t + c * 12);

        if (id != 0xFFFF) {
            *(CardDef**)&b[0x00] = &gCardDefs[id];
        }
    }
}
void func_08090224(u8* p) {
    u8* q;

    q = &p[0x64];
    ListNodeInit(q, *(void**)&p[0x38], p);
    ListPoolAppend(q, *(void**)&p[0x38]);
}

void card_enemy_0(CardDisplayWork* p, CardDisplayArgs* a) {
    p->tiles = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->palette = 0;
    p->unk_A1 = 0;
    *(CardDisplayArgs*)&p->pool = *a;
    p->unk_78 = 0;
    p->unk_A0 = 0x50;
    p->unk_9C = 0;
    func_080901E0((s32*)&p->pool, (u8*)&p->cardDef, ((CardDisplayArgs*)&p->pool)->unk_0C);
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_8C = gUnk_09035978[0];
    p->unk_90 = gUnk_09035978[1];
    p->x = 0xDC00;
    p->y = 0x8400;
    p->unk_A5 = p->cardDef->unk_20;
    func_08090224((u8*)p);
}

u8 card_enemy_1(CardDisplayWork* p, void* a) {
    if (!(p->unk_78 & 0x800)) {
        if (p->unk_78 & 0x80) {
            func_0807C39C(p);
            p->unk_78 &= ~0x80;
            p->unk_78 |= 1;
        }
    }

    func_0807CD48(p);

    if (p->unk_78 & 0x10) {
        p->unk_9C = 8;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0809075C);
    } else if (!(p->unk_78 & 0x1000)) {
        func_08090864(p);
        p->unk_5F += 4;
        func_08090B50(p, a);

        if (!(p->unk_78 & 0x20)) {
            p->unk_78 &= ~0x40;
            SetTaskUpdate(a, (TaskUpdateFunc)func_08090808);
        }
    }

    return 1;
}

void func_08090374(CardDisplayWork* p) {
    void* gfx;
    s32 affine;
    u16 flags;

    gfx = p->cardDef->gfx;

    if (p->unk_78 & 0x800) {
        if (!(p->unk_78 & 1)) {
            if (p->unk_78 & 0x80) {
                if ((p->unk_78 & 8) == 0) {
                    affine = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 0);
                } else {
                    affine = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 1);
                }

                flags = 0x410;
                DrawSprite(p->x >> 8, (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
                           gUnk_08F70A28[0].gfx, ((struct UnkStruct_08090374*)gUnk_02039DD4)->tiles[p->cardDef->unk_2A],
                           gUnk_02039DD4->palette, affine, flags, (u16)(p->unk_A0 - 1));
                DrawSprite(p->x >> 8, (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
                           gfx, p->tiles, p->palette, affine, flags, p->unk_A0);

                if (p->unk_A7 != 0) {
                    DrawSprite(p->x >> 8, (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
                               gUnk_09EE981C[p->unk_A5], gUnk_02039DD4->tiles7,
                               gUnk_02039DD4->palette2, affine, flags, (u16)(p->unk_A0 - 2));
                } else {
                    DrawSprite(p->x >> 8, (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
                               gUnk_09EE981C[p->unk_A5], gUnk_02039DD4->tiles5,
                               gUnk_02039DD4->palette, affine, flags, (u16)(p->unk_A0 - 2));
                }
            }
        }
    }
}
void func_08090530(u8* work) {
    if (*(void**)&work[0x00] != 0) {
        func_0807C39C((CardDisplayWork*)work);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjPalette(*(void**)&work[0x18]);
    }
}

u8 func_08090550(CardDisplayWork* p, void* a) {
    if (gBtlWork->flags & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->flags &= ~0x20;
        gBtlWork->flags &= ~0x80;
        gBtlWork->flags &= ~0x10000000;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090940);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090DB0);
    }

    return 1;
}

u8 EnemyUsecard_1(CardDisplayWork* p, void* a) {
    p->unk_A0 = 80;
    ApproachValue(&p->x, 0x7800, p->unk_9C);
    ApproachValue(&p->y, 0x8400, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    }

    if (gBtlWork->flags & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (TaskUpdateFunc)func_08090550);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = (u16)(GetRandom() % 33) - 16;
            p->unk_9E = GetRandom() % 5 + 254;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080909A4);
            return 1;
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080909A4);
    }

    return 1;
}

u8 func_0809075C(CardDisplayWork* p, void* a) {
    ApproachValue(&p->x, gSineTable[((p->unk_7C >> 8) - 32) & 0xFF] * (p->unk_84 >> 8) + gUnk_09035978[0],
                  p->unk_9C);
    ApproachValue(&p->y, -gSineTable[(((p->unk_7C >> 8) - 32) & 0xFF) + 0x40] * (p->unk_84 >> 8) + gUnk_09035978[1],
                  p->unk_9C);
    p->unk_9C--;

    if ((s16)p->unk_9C <= 1) {
        p->unk_9C = 0;
        p->unk_78 &= ~0x10;
        SetTaskUpdate(a, (TaskUpdateFunc)card_enemy_1);
    }

    return 1;
}

u8 func_08090808(u8* work, void* a) {
    if (work[0xA1] == 7) {
        return 0;
    }

    *(s32*)&work[0x84] += -*(s32*)&work[0x84] >> 1;
    *(s32*)&work[0x4C] += (gUnk_09035978[8] - *(s32*)&work[0x4C]) >> 1;
    *(s32*)&work[0x50] += (gUnk_09035978[9] - *(s32*)&work[0x50]) >> 1;

    if (*(s32*)&work[0x78] & 0x20) {
        SetTaskUpdate(a, (TaskUpdateFunc)card_enemy_1);
    }

    return 1;
}

void func_08090864(CardDisplayWork* p) {
    s32 t;

    if (p->unk_80 - p->unk_7C > 0x7F00) {
        p->unk_7C += 0x10000;
    }

    t = p->unk_7C - 0x10000;

    if (p->unk_80 - t < p->unk_7C - p->unk_80) {
        p->unk_7C = t;
    }

    p->unk_94 += (p->unk_98 - p->unk_94) >> 2;
    p->unk_84 += (p->unk_88 - p->unk_84) >> 1;
    ApproachValue(&p->unk_7C, p->unk_80, p->unk_9C);
    p->unk_9C--;

    if ((s16)p->unk_9C <= 1) {
        p->unk_9C = 0;
        p->unk_78 |= 0x40;
    } else {
        p->unk_78 &= ~0x40;
    }

    p->x = gSineTable[((p->unk_7C >> 8) - 32) & 0xFF] * (p->unk_84 >> 8) + p->unk_8C;
    p->y = -gSineTable[(((p->unk_7C >> 8) - 32) & 0xFF) + 64] * (p->unk_84 >> 8) + p->unk_90;
}

u8 func_08090940(CardDisplayWork* p) {
    ApproachValue(&p->y, 0x8200, p->unk_9C);
    *(u16*)&p->unk_9C =
        *(s16*)&p->unk_9C > 0 ? p->unk_9C - 1 : 0;

    if (*(s16*)&p->unk_9C == 0) {
        *(u16*)&p->unk_9C = 0;
        p->unk_5E += p->unk_9E;
        p->unk_9E++;

        if (p->unk_54 <= 25) {
            return 0;
        }

        p->unk_54 -= 25;
        p->unk_58 -= 25;
    }

    return 1;
}

u8 func_080909A4(CardDisplayWork* p) {
    p->unk_A1 = 0;
    p->y -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->x -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->flags &= ~0x10000000;
        return 0;
    }

    return 1;
}

void func_08090A54(CardDisplayWork* p, void* a) {
    p->x -= gSineTable[p->unk_9E] * 3;
    func_0807CD48(p);

    if (p->unk_9E != 0) {
        p->unk_9E -= 8;
    } else {
        p->unk_9E = 0;
        p->unk_78 &= ~0x800;
        SetTaskUpdate(a, (TaskUpdateFunc)card_enemy_1);
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090808);
    }
}

void func_08090ACC(CardDisplayWork* p, void* a) {
    p->x += gSineTable[p->unk_9E] * 3;
    func_0807CD48(p);

    if ((s8)p->unk_9E >= 0) {
        p->unk_9E += 8;
    } else {
        p->unk_9E = 0x80;
        p->unk_78 &= ~4;
        p->unk_A0 = 100;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090A54);
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090808);
    }
}

void func_08090B50(CardDisplayWork* p, void* a) {
    switch (p->unk_A1) {
    case 5:
        p->unk_9C = 16;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (TaskUpdateFunc)EnemyUsecard_1);
        break;
    case 6:
        p->unk_9C = 8;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090C3C);
        break;
    case 8:
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080909A4);
        break;
    case 7:
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080909A4);
        break;
    case 9:
        p->unk_9E = 0;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08090ACC);
        p->unk_A1 = 0;
        break;
    }
}

u8 func_08090C3C(CardDisplayWork* p, void* a) {
    s32 (*tbl)[2]; s32* q;

    if (gBtlWork->unk_070 == 1) {
        return 1;
    }

    func_0807CD48(p);

    if (p->unk_78 & 0x20) {
        q = &p->x; tbl = (s32 (*)[2])gUnk_09035978; ApproachValue(q, tbl[3 - p->unk_9F][0], p->unk_9C); ApproachValue(&p->y, ((s32 (*)[2])gUnk_09035978)[3 - p->unk_9F][1], p->unk_9C);
    } else {
        ApproachValue(&p->x, gUnk_09035978[8], p->unk_9C);
        ApproachValue(&p->y, gUnk_09035978[9], p->unk_9C);
    }

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        p->unk_78 &= ~0x40;
    } else {
        p->unk_9C = 0;
        p->unk_78 |= 0x40;
    }

    if (p->unk_A1 == 5) {
        if (!(gBtlWork->flags & 0x80) && p->unk_9F == 0) {
            gBtlWork->flags |= 0x80;
        }

        if (p->unk_78 & 0x8000) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807CF4C);
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->x;
            p->unk_90 = p->y;
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807CFA8);
        }
    }

    p->unk_5F += 4;
    return 1;
}
u8 func_08090DB0(CardDisplayWork* p, void* a) {
    p->unk_A1 = 0;
    p->y -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->x += 0x200;
    p->unk_5E += 16;

    if (!(p->unk_78 & 0x400000)) {
        p->unk_54 -= 20;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = -20;
        }

        if (p->unk_54 <= -0x100) {
            p->unk_54 = -0x100;
            p->unk_78 |= 0x400000;
        }
    } else {
        p->unk_54 -= 20;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = 20;
        }

        if (p->unk_54 >= 0x100) {
            p->unk_54 = 0x100;
            p->unk_78 &= ~0x400000;
        }
    }

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->flags &= ~0x10000000;
        return 0;
    }

    return 1;
}
void func_08090EA0(CardDisplayWork* p, CardDisplayArgs* a) {
    const s32* tbl;
    u8 n;
    s32 id;
    u8* g;

    p->tiles = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->tiles4 = 0;
    *(s32*)&p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(s32*)&p->unk_1C = 0;
    p->unk_A1 = 0;
    *(CardDisplayArgs*)&p->pool = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_40[0]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_40[0]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_40[0];

    if (n == 1) {
        id = tbl[0];
    } else if ((s16)p->unk_44 != -1) {
        if ((s16)p->unk_44 > n) {
            id = tbl[GetRandom() % n];
        } else {
            id = tbl[(s16)p->unk_44 - 1];
        }
    } else {
        if (gUnk_02039DD4->unk_0D7 > n) {
            gUnk_02039DD4->unk_0D7 = n;
        }

        id = tbl[gUnk_02039DD4->unk_0D7];
        gUnk_02039DD4->unk_0D7 = GetRandom() % n;
    }

    p->cardDef = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x804;
    p->unk_8C = 0xDC00;
    p->unk_90 = 0x8800;
    p->x = 0xDC00;
    p->y = 0x8800;
    p->unk_9C = 10;
    p->unk_A0 -= 4;
    func_0807C33C(p);
    p->unk_A5 = p->cardDef->unk_20;
    g = (u8*)&gGameState;

    switch (*(s32*)(g + 0x1B8)) {
    case 1:
        p->unk_A5 += 2;

        if (p->unk_A5 > 9) {
            p->unk_A5 = 9;
        }

        p->unk_A7 = 1;
        break;
    case 2:
        if (p->unk_A5 > 2) {
            p->unk_A5 -= 2;
        } else {
            p->unk_A5 = 1;
        }
        p->unk_A7 = 1;
        break;
    default:
        p->unk_A7 = 0;
        break;
    }

    p->unk_78 |= 0x80;
}

void func_08091048(CardDisplayWork* p, CardDisplayArgs* a) {
    const s32* tbl;
    u8 n;
    s32 id;

    p->tiles = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->palette = 0;
    p->unk_A1 = 0;
    *(CardDisplayArgs*)&p->pool = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_40[0]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_40[0]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_40[0];

    if (n == 1) {
        id = tbl[0];
    } else if ((s16)p->unk_44 < n) {
        id = tbl[(s16)p->unk_44];
    } else {
        id = tbl[GetRandom() % n];
    }

    p->cardDef = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x801;
    p->unk_8C = 0x10000;
    p->unk_90 = 0x8800;
    p->x = 0x10000;
    p->y = 0x8800;
    p->unk_9C = 0x10;
    p->unk_A0 -= 4;
    p->unk_A5 = p->cardDef->unk_20;
}
void func_08091138(CardDisplayWork* p, CardDisplayArgs* a) {
    const s32* tbl;
    u8 n;
    s32 id;

    p->tiles = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->palette = 0;
    p->unk_A1 = 0;
    *(CardDisplayArgs*)&p->pool = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_40[0]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_40[0]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_40[0];

    if (n == 1) {
        id = tbl[0];
    } else if ((s16)p->unk_44 < n) {
        id = tbl[GetRandom() % (s16)p->unk_44];
    } else {
        id = tbl[GetRandom() % n];
    }

    p->cardDef = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x801;
    p->unk_8C = 0x10000;
    p->unk_90 = 0x8800;
    p->x = 0x10000;
    p->y = 0x8800;
    p->unk_9C = 0x10;
    p->unk_A0 -= 4;
    p->unk_A5 = p->cardDef->unk_20;
}

void func_08091234(u16 arg) {
    UnkStruct_0807FD10_Args args;
    CardDisplayWork* p;
    u8 i;
    u8 flag;
    u8 found;
#ifdef VERSION_EU
    s32 j;
    s32 k;
#endif

    args.unk_00 = 0;
    args.slot = 0;
    *(u32*)&args.unk_08 = arg;
    args.unk_0C = gUnk_02034AB4;
    args.unk_0E = 0;
    p = ((CardDisplayWork**)TaskCreate(&gUnk_02039DD4->tasks, &gUnk_09EE4B58, &args))[1];
    gBtlWork->flags |= 0x10000000;
    gUnk_02039DD4->unk_0E0 = 1;

    if ((gBtlWork->flags & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->unk_A5;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x80;
    } else if ((gBtlWork->flags & 0x20) == 0) {
#ifdef VERSION_EU
        if ((s16)gUnk_02039DD4->unk_0C2 <= p->unk_A5 || p->unk_A5 == 0) {
#else
        if ((s16)gUnk_02039DD4->unk_0C2 <= p->unk_A5) {
#endif
            found = 0;

            if (gBtlWork->unk_0F4 == 2) {
#ifdef VERSION_EU
                if (gUnk_02039DD4->unk_000[0]->cardDef->unk_2A == 0 && gUnk_02039DD4->unk_0E1 == 0) {
                    found = 1;
                }
#else
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_2A == 0) {
                        found = 1;
                        break;
                    }
                }
#endif
            }

            if (gBtlWork->unk_0F4 == 20) {
#ifdef VERSION_EU
                for (j = 0; j < gUnk_02039DD4->unk_0D0; j++) {
                    if (gUnk_02039DD4->unk_000[j]->cardDef->unk_24 == 22) {
                        found = 1;
                    }
                }
#else
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_24 == 22) {
                        found = 1;
                        break;
                    }
                }
#endif
            }

            if (gBtlWork->unk_0F4 == 29) {
#ifdef VERSION_EU
                for (k = 0; k < gUnk_02039DD4->unk_0D0; k++) {
                    if (gUnk_02039DD4->unk_000[k]->cardDef->unk_2A == 2 && !(gUnk_02039DD4->unk_000[k]->cardDef->flags & 8)) {
                        found = 1;
                    }
                }
#else
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_2A == 2) {
                        found = 1;
                        break;
                    }
                }
#endif
            }

            if (found == 0) {
                gBtlWork->flags |= 0x800000;

                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                if ((s16)gUnk_02039DD4->unk_0C2 != p->unk_A5) {
                    if (p->unk_A5 == 0) {
                        gBtlWork->unk_1CA = -(s8)gUnk_02039DD4->unk_0C2;
                    } else {
                        gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2 - p->unk_A5;
                    }

                    m4aSongNumStart(SONG_SYS_CARDLOSE);
                    gBtlWork->flags |= 0x400;
                    gBtlWork->flags |= 0x80;
                    gBtlWork->flags &= ~0x20;
                    gUnk_02039DD4->unk_000[0] = p;

                    if (gBtlWork->unk_0F4 == 48) {
                        if (p->unk_A5 != 0) {
                            gUnk_02039DD4->unk_0C2 = p->unk_A5 - gUnk_02039DD4->unk_0C2;
                            p->unk_A5 = gUnk_02039DD4->unk_0C2;
                        } else {
                            gUnk_02039DD4->unk_0C2 = 0;
                        }

                        if ((s16)gUnk_02039DD4->unk_0C2 < 0) {
                            gUnk_02039DD4->unk_0C2 = 0;
                        }

                        gBtlWork->unk_0F8--;
                    } else {
                        gUnk_02039DD4->unk_0C2 = p->unk_A5;
                    }

                    gUnk_02039DD4->unk_0D0 = 1;
                    gBtlWork->unk_0A4 = 0;
                    p->unk_78 |= 0x2000;
                    func_0807BA54();
                } else {
                    m4aSongNumStart(SONG_SYS_DROW);
                    gBtlWork->flags &= ~0x80;
                    gBtlWork->flags &= ~0x20;
                    gBtlWork->flags &= ~0x400;
                    gBtlWork->unk_0A4 = 0;
                }
            }
        }
    } else {
#ifdef VERSION_EU
        if ((s16)gUnk_02039DD4->unk_0C2 <= p->unk_A5 || p->unk_A5 == 0) {
#else
        if ((s16)gUnk_02039DD4->unk_0C2 <= p->unk_A5) {
#endif
            flag = 0;

            if (gBtlWork->unk_0F4 == 2) {
#ifdef VERSION_EU
                if (gUnk_02039DD4->unk_000[0]->cardDef->unk_2A == 0 && gUnk_02039DD4->unk_0E1 == 0) {
                    flag = 1;
                }
#else
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_2A == 0) {
                        flag = 1;
                        break;
                    }
                }
#endif
            }

#ifndef VERSION_EU
            if (gBtlWork->unk_0F4 == 54) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_2A == 1) {
                        flag = 1;
                        break;
                    }
                }
            }

#endif
            if (gBtlWork->unk_0F4 == 20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_24 == 22) {
                        flag = 1;
                        break;
                    }
                }
            }

            if (gBtlWork->unk_0F4 == 29) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
#ifdef VERSION_EU
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_2A == 2 && !(gUnk_02039DD4->unk_000[i]->cardDef->flags & 8)) {
#else
                    if (gUnk_02039DD4->unk_000[i]->cardDef->unk_2A == 2) {
#endif
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag == 0) {
                gBtlWork->flags |= 0x800000;

                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                if ((s16)gUnk_02039DD4->unk_0C2 != p->unk_A5) {
                    if (p->unk_A5 == 0) {
                        gBtlWork->unk_1CA = -(s8)gUnk_02039DD4->unk_0C2;
                    } else {
                        gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2 - p->unk_A5;
                    }

                    m4aSongNumStart(SONG_SYS_CARDLOSE);
                    gBtlWork->flags |= 0x400;
                    gBtlWork->flags |= 0x80;
                    gBtlWork->flags &= ~0x20;
                    gUnk_02039DD4->unk_000[0] = p;
#ifdef VERSION_EU

                    if (gBtlWork->unk_0F4 == 48) {
                        if (p->unk_A5 != 0) {
                            gUnk_02039DD4->unk_0C2 = p->unk_A5 - gUnk_02039DD4->unk_0C2;
                            p->unk_A5 = gUnk_02039DD4->unk_0C2;
                        } else {
                            gUnk_02039DD4->unk_0C2 = 0;
                        }

                        if ((s16)gUnk_02039DD4->unk_0C2 < 0) {
                            gUnk_02039DD4->unk_0C2 = 0;
                        }

                        gBtlWork->unk_0F8--;
                    } else {
                        gUnk_02039DD4->unk_0C2 = p->unk_A5;
                    }

#else
                    gUnk_02039DD4->unk_0C2 = p->unk_A5;
#endif
                    gUnk_02039DD4->unk_0D0 = 1;
                    gBtlWork->unk_0A4 = 0;
                    p->unk_78 |= 0x2000;
                    func_0807BA54();
                } else {
                    m4aSongNumStart(SONG_SYS_DROW);
                    gBtlWork->flags &= ~0x80;
                    gBtlWork->flags &= ~0x20;
                    gBtlWork->flags &= ~0x400;
                    gBtlWork->unk_0A4 = 0;
                }
            }
        }
    }

    p->unk_78 = (p->unk_78 | 4) & ~0x40;
}

void func_080917C8(u16 a, u8 b) {
    UnkStruct_080917C8_Args arg;
    CardDisplayWork* p;
    u8 i;

    arg.unk_00 = 0;
    arg.unk_04 = 0;
    arg.unk_08 = a;
    arg.unk_0C = b;
    arg.unk_0E = 0;
    p = ((CardDisplayWork**)TaskCreate(&gUnk_02039DD4->tasks, &gUnk_09EE4B70, &arg))[1];
    gBtlWork->flags |= 0x10000000;

    if ((gBtlWork->flags & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->cardDef->unk_20;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x80;
    } else if ((gBtlWork->flags & 0x20) == 0) {
        if (gUnk_02039DD4->unk_0CC != 2) {
            if ((s16)gUnk_02039DD4->unk_0C2 < p->cardDef->unk_20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                m4aSongNumStart(SONG_SYS_CARDLOSE);
                gBtlWork->flags |= 0x800000;
                gBtlWork->flags |= 0x400;
                gBtlWork->flags |= 0x80;
                gUnk_02039DD4->unk_000[0] = p;
                gUnk_02039DD4->unk_0C2 = p->cardDef->unk_20;
                gUnk_02039DD4->unk_0D0 = 1;
                gBtlWork->unk_0A4 = 0;
                p->unk_78 |= 0x2000;
            }
        }
    }

    p->unk_78 |= 4;
    p->unk_78 &= ~0x40;
}

void func_08091978(u16 a, u8 b) {
    UnkStruct_08091978_Args arg;
    CardDisplayWork* p;
    u8 i;

    arg.unk_00 = 0;
    arg.unk_04 = 0;
    arg.unk_08 = a;
    arg.unk_0C = b;
    arg.unk_0E = 0;
    p = ((CardDisplayWork**)TaskCreate(&gUnk_02039DD4->tasks, &gUnk_09EE4B88, &arg))[1];
    gBtlWork->flags |= 0x10000000;

    if ((gBtlWork->flags & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->cardDef->unk_20;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x80;
    } else if (gBtlWork->flags & 0x20) {
        if (gBtlWork->unk_0F4 == 2) {
            if ((s16)gUnk_02039DD4->unk_0C2 < p->cardDef->unk_20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                m4aSongNumStart(SONG_SYS_CARDLOSE);
                gBtlWork->flags |= 0x800000;
                gBtlWork->flags |= 0x400;
                gBtlWork->flags |= 0x80;
                gUnk_02039DD4->unk_000[0] = p;
                gUnk_02039DD4->unk_0C2 = p->cardDef->unk_20;
                gUnk_02039DD4->unk_0D0 = 1;
                gBtlWork->unk_0A4 = 0;
                p->unk_78 |= 0x2000;
            }
        }
    }

    p->unk_78 |= 4;
    p->unk_78 &= ~0x40;
}
void func_08091B28(void) {
    gUnk_02034AB4 = -1;
}

void func_08091B38(u16 a) {
    gUnk_02034AB4 = a;
}
u16 func_08091B44(void) {
    if (gUnk_02034AB4 != -1) {
        return gUnk_02034AB4;
    }

    return gUnk_02039DD4->unk_0D7;
}

TaskDesc gTaskDescCardEnemy = {
    "card_enemy",
    (TaskInitFunc)card_enemy_0,
    (TaskUpdateFunc)card_enemy_1,
    (TaskFunc)func_08090374,
    (TaskFunc)func_08090530,
    0xA8,
};

TaskDesc gUnk_09EE4B58 = {
    "EnemyUsecard",
    (TaskInitFunc)func_08090EA0,
    (TaskUpdateFunc)EnemyUsecard_1,
    (TaskFunc)func_08090374,
    (TaskFunc)func_08090530,
    0xA8,
};

TaskDesc gUnk_09EE4B70 = {
    "EnemyUsecard",
    (TaskInitFunc)func_08091048,
    (TaskUpdateFunc)EnemyUsecard_1,
    (TaskFunc)func_08090374,
    (TaskFunc)func_08090530,
    0xA8,
};

TaskDesc gUnk_09EE4B88 = {
    "EnemyUsecard",
    (TaskInitFunc)func_08091138,
    (TaskUpdateFunc)EnemyUsecard_1,
    (TaskFunc)func_08090374,
    (TaskFunc)func_08090530,
    0xA8,
};
