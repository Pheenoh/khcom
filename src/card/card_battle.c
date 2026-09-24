#include "macros.h"
#include "registration_data.h"
#include "msg_api.h"
#include "card_api.h"
#include <string.h>
#include "card_battle.h"
#include "m4a_song.h"
#include "fade.h"
#include "engine_math.h"
#include "listpool.h"
#include "card.h"
#include "game.h"
#include "mode_test_api.h"
#include "text.h"
#include "display.h"
#include "obj_api.h"
#include "key.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "m4a.h"
#include "mode.h"
#include "anim.h"
#include "gba/keys.h"
#include "sprites_card_pictures.h"
#include "sprites_card.h"

u16 func_080787B8(CardBattleWork* w, u8 n);
s32 func_08077F44(UnkStruct_08080268* w, u8* task);
s32 func_08076F4C(CardBattleWork* w);
void func_08077E10(CardBattleWork* w);
void func_08077E98(CardBattleWork* w);
u8 func_080762A8(void);
void func_08076354(void);
void func_08076388(void);
void func_080763A0(void);
void func_080763AC(void);
void func_080763B8(void);
void func_080763C4(void);
void func_08076438(void);
void func_08076458(void);

CardDisplayWork* gUnk_02034A98;
u32 gUnk_02034A9C;
u32 gUnk_02034AA0;
UnkStruct_02039DD4* gUnk_02039DD4 EWRAM_COMMON(4);

void func_08076284(void) {
    gUnk_02034AA0 = 14;
}

void func_08076290(void) {
    gUnk_02034AA0 = 15;
}

void func_0807629C(void) {
    gUnk_02034AA0 = 16;
}

u8 func_080762A8(void) {
    return gUnk_02039DD4->unk_0D2;
}

void func_080762B8(void) {
    gUnk_02034AA0 = 17;
}

void func_080762C4(void) {
    gUnk_02034AA0 = 18;
}

void func_080762D0(void) {
    gUnk_02034AA0 = 19;
}

void func_080762DC(void) {
    gUnk_02034AA0 = 21;
}

void func_080762E8(void) {
    gUnk_02034AA0 = 22;
}

void func_080762F4(void) {
    gUnk_02034AA0 = 23;
}

void func_08076300(void) {
    gUnk_02034AA0 = 24;
}

void func_0807630C(void) {
    gUnk_02034AA0 = 20;
}

void func_08076318(void) {
    gUnk_02034A9C = 1;
}

void func_08076324(void) {
    gUnk_02034A9C = 2;
}

void func_08076330(void) {
    gUnk_02034A9C = 3;
}

void func_0807633C(void) {
    gUnk_02034A9C = 4;
}

void func_08076348(void) {
    gUnk_02034A9C = 5;
}

void func_08076354(void) {
    gUnk_02034A9C = 8;
}

void func_08076360(void) {
    gUnk_02034A9C = 6;
    func_0807E23C();
}

void func_08076374(void) {
    gUnk_02034A9C = 7;
    func_0807E248();
}

void func_08076388(void) {
    gUnk_02034A9C = 9;
}

void func_08076394(void) {
    gUnk_02034A9C = 10;
}

void func_080763A0(void) {
    gUnk_02034A9C = 11;
}

void func_080763AC(void) {
    gUnk_02034A9C = 12;
}

void func_080763B8(void) {
    gUnk_02034A9C = 13;
}

void func_080763C4(void) {
    gUnk_02034A9C = 0;
}

u8 func_080763D0(void) {
    if (gUnk_02034A98 != 0 && (gUnk_02034A98->unk_78 & 0x100000)) {
        return 1;
    }

    return 0;
}

void func_080763F0(void) {
    if (gUnk_02034A98 != 0) {
        if ((gUnk_02034A98->unk_78 & 0x01000044) == 0x01000044) {
            gUnk_02039DD4->unk_0E7 = 1;
        } else {
            gUnk_02039DD4->unk_0E7 = 0;
        }
    } else {
        gUnk_02039DD4->unk_0E7 = 0;
    }
}

void func_08076438(void) {
}

u8 func_0807643C(void) {
    if (gUnk_02034A98 != 0) {
        return gUnk_02034A98->unk_78 & 2;
    }

    return 0;
}

void func_08076458(void) {
    u32 zero;

    gUnk_02039DD4 = EwramAlloc(sizeof(UnkStruct_02039DD4));
    zero = 0;
    CpuSet(&zero, gUnk_02039DD4, 0x05000043);
    gUnk_02039DD4->unk_000[0] = 0;
    gUnk_02039DD4->unk_000[1] = 0;
    gUnk_02039DD4->unk_000[2] = 0;
    gUnk_02039DD4->unk_000[3] = 0;
    gUnk_02039DD4->unk_000[4] = 0;
    gUnk_02039DD4->unk_000[5] = 0;
    gUnk_02039DD4->unk_0B0 = 145;
    gUnk_02039DD4->unk_0B4 = 145;
    gUnk_02039DD4->unk_0B8 = 950;
    gUnk_02039DD4->unk_0BC = 950;
    gUnk_02039DD4->unk_0C0 = 0;
    gUnk_02039DD4->unk_0C2 = 0;
    gUnk_02039DD4->unk_0C4 = 106;
    gUnk_02039DD4->unk_0C6 = 106;
    gUnk_02039DD4->unk_0C8 = 256;
    gUnk_02039DD4->unk_0CA = 256;
    gUnk_02039DD4->unk_0CC = 0;
    gUnk_02039DD4->unk_0CE = 0;
    gUnk_02039DD4->unk_0D0 = 0;
    gUnk_02039DD4->unk_0D1 = 0;
    gUnk_02039DD4->unk_0D2 = 0;
    gUnk_02039DD4->unk_0D3 = 0;
    gUnk_02039DD4->unk_0D4 = 0;
    gUnk_02039DD4->unk_0D5 = 0;
    gUnk_02039DD4->unk_0D6 = 0;
    gUnk_02039DD4->unk_0D7 = 0;
    gUnk_02039DD4->unk_0D8 = 0;
    gUnk_02039DD4->unk_0D9 = 0;
    gUnk_02039DD4->unk_0DC = 0;
    gUnk_02039DD4->unk_0E0 = 0;
    gUnk_02039DD4->unk_0E1 = 0;
    gUnk_02039DD4->unk_0E2 = 0;
    gUnk_02039DD4->unk_0E0 = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    gUnk_02039DD4->unk_0E4 = 0;
    gUnk_02039DD4->unk_0E5 = 0;
    gUnk_02039DD4->unk_0E6 = 0;
    gUnk_02039DD4->unk_0E9 = 0;
    gUnk_02039DD4->unk_0DA[0] = 0;
    gUnk_02039DD4->unk_0DA[1] = 0;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0EB = 0;
    gUnk_02039DD4->unk_0EC = 0;
    gUnk_02039DD4->unk_0ED = 0;
    gUnk_02039DD4->unk_0DE = 0;
    gUnk_02039DD4->unk_0DF = 0;
    gUnk_02039DD4->unk_0EE = 0;
    gUnk_02039DD4->unk_0F0 = 0;
    gUnk_02039DD4->unk_0F4 = 0;
    gUnk_02039DD4->unk_0F8 = 0;
    gUnk_02039DD4->unk_0FC = 0;
    gUnk_02039DD4->unk_0FE = 0;
    gUnk_02039DD4->unk_100 = 4;
    gUnk_02039DD4->unk_102 = 4;
    gUnk_02039DD4->unk_104 = 2;
    gUnk_02039DD4->unk_106 = 2;
    gUnk_02039DD4->unk_108[0] = 0;
    gUnk_02039DD4->unk_108[1] = 0;
    TaskPoolInit(&gUnk_02039DD4->tasks, 6);
    gUnk_02039DD4->tiles = LoadObjTiles(gUnk_08F709B0[0].tiles, 640);
    gUnk_02039DD4->tiles2 = LoadObjTiles(gUnk_08F709B0[1].tiles, 640);
    gUnk_02039DD4->tiles3 = LoadObjTiles(gUnk_08F709B0[2].tiles, 640);
    gUnk_02039DD4->tiles4 = LoadObjTiles(gUnk_08F709B0[3].tiles, 640);
    gUnk_02039DD4->tiles5 = LoadObjTiles(gUnk_0905EAE8, 320);
    gUnk_02039DD4->tiles6 = LoadObjTiles(gUnk_0905ED36, 320);
    gUnk_02039DD4->tiles7 = LoadObjTiles(gUnk_0905EEE6, 320);
    gUnk_02039DD4->palette = LoadObjPalette(gUnk_09611AB8, 32);
    gUnk_02039DD4->palette2 = LoadObjPalette(gUnk_08F69BA4, 32);
    FadeSetPaletteExcluded(((UnkStruct_080038C8*)gUnk_02039DD4->palette)->index + 16, 1);
    func_0807B668(gUnk_02039DD4);
}

CardSlot* func_08076674(UnkStruct_08078754* w, u8 slot, u16* n) {
    CardSlot* e;
    s16 i;
    u16 cur;
    u16 next;

    i = *n;

    if (w->slots[slot][i].unk_06 == 0 && w->slots[slot][i].unk_07 == 0) {
        if (w->slots[slot][i].unk_08 == 0 && w->slots[slot][i].unk_0A == 0) {
            return &w->slots[slot][(s16)*n];
        }
    }

    cur = *n;
    next = cur + 1;

    if ((s16)next >= w->unk_A8[slot]) {
        next = 0;
    }

    while ((s16)next != (s16)cur) {
        i = next;

        if (w->slots[slot][i].unk_06 == 0 && w->slots[slot][i].unk_07 == 0) {
            if (w->slots[slot][i].unk_08 == 0 && w->slots[slot][i].unk_0A == 0) {
                e = &w->slots[slot][i];
                *n = next;
                return e;
            }
        }

        next = i + 1;

        if ((s16)next >= w->unk_A8[slot]) {
            next = 0;
        }
    }

    return 0;
}

CardSlot* func_08076750(UnkStruct_08078754* w, u8 slot, u16* n) {
    CardSlot* e;
    s16 i;
    u16 cur;
    u16 next;

    i = *n;

    if (w->slots[slot][i].unk_06 == 0 && w->slots[slot][i].unk_07 == 0) {
        if (w->slots[slot][i].unk_08 == 0 && w->slots[slot][i].unk_0A == 0) {
            return &w->slots[slot][(s16)*n];
        }
    }

    cur = *n;
    next = cur - 1;

    if ((s16)next < 0) {
        next = w->unk_A8[slot] - 1;
    }

    while ((s16)next != (s16)cur) {
        i = next;

        if (w->slots[slot][i].unk_06 == 0 && w->slots[slot][i].unk_07 == 0) {
            if (w->slots[slot][i].unk_08 == 0 && w->slots[slot][i].unk_0A == 0) {
                e = &w->slots[slot][i];
                *n = next;
                return e;
            }
        }

        next = i - 1;

        if ((s16)next < 0) {
            next = w->unk_A8[slot] - 1;
        }
    }

    return 0;
}
void func_0807682C(UnkStruct_08080268* w, u8 slot) {
    UnkStruct_0807FD10_Args arg;
    u16 n;
    s16 count = 0;
    u16 old;
    CardSlot* c;
    CardDisplayWork* e;
    EventCardLink* p;
    if (w->unk_94[slot] != 0xFFFF) {
        u32 index = w->unk_94[slot];
        n = index;
        old = index;
        c = func_08076674((UnkStruct_08078754*)w, slot, &n);
        if (c != 0) {
            arg.unk_00 = &w->unk_54[slot];
            arg.unk_0C = n;
            arg.unk_0E = slot;
            arg.slot = c;
            arg.unk_0F = w->unk_9C[slot];
            if (c->cardId == 0xFFFE) {
                TaskCreate((TaskPool*)w, &gTaskDescCardReload, &arg);
            } else {
                TaskCreate((TaskPool*)w, &gUnk_09EE496C, &arg);
            }
            c->unk_06 = 1;
            old = n;
            n = old + 1;
            count++;
        }
        if ((s16)n >= (s16)w->unk_A8[slot]) {
            n = 0;
        }
        c = func_08076674((UnkStruct_08078754*)w, slot, &n);
        if (c != 0 && (s16)n != w->unk_94[slot]) {
            arg.unk_00 = &w->unk_54[slot];
            arg.unk_0C = n;
            arg.unk_0E = slot;
            arg.slot = c;
            arg.unk_0F = w->unk_9C[slot];
            if (c->cardId == 0xFFFE) {
                TaskCreate((TaskPool*)w, &gTaskDescCardReload, &arg);
            } else {
                TaskCreate((TaskPool*)w, &gUnk_09EE496C, &arg);
            }
            c->unk_06 = 1;
            old = n;
            count++;
        }
        n = w->unk_94[slot] - 1;
        if ((s16)n < 0) {
            n = w->unk_A8[slot] - 1;
        }
        c = func_08076750((UnkStruct_08078754*)w, slot, &n);
        if (c != 0 && (s16)n != w->unk_94[slot] && (s16)n != (s16)old) {
            arg.unk_00 = &w->unk_54[slot];
            arg.unk_0C = n;
            arg.unk_0E = slot;
            arg.slot = c;
            arg.unk_0F = w->unk_9C[slot];
            if (c->cardId == 0xFFFE) {
                TaskCreate((TaskPool*)w, &gTaskDescCardReload, &arg);
            } else {
                TaskCreate((TaskPool*)w, &gUnk_09EE496C, &arg);
            }
            c->unk_06 = 1;
            count++;
        }
    }
    switch (count) {
        case 0:
            arg.unk_00 = &w->unk_54[slot];
            arg.unk_0C = 0xFFFF;
            arg.slot = (CardSlot*)w->unk_44[slot];
            arg.unk_0E = slot;
            TaskCreate((TaskPool*)w, &gTaskDescCardNotHave, &arg);
            e = ListPoolFirst(&w->unk_54[slot]);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[1];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 1;
            e->unk_A0 = 50;
            e->unk_78 |= 0x802;
            break;
        case 1:
            e = ListPoolFirst(&w->unk_54[slot]);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[1];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 1;
            e->unk_A0 = 50;
            e->unk_78 |= 0x800;
            break;
        case 2:
            e = ListPoolFirst(&w->unk_54[slot]);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[1];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A0 = 50;
            e->unk_A4 = 1;
            e->unk_78 |= 0x800;
            e = ListPoolNext(&e->node);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[0];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A0 = 60;
            e->unk_A4 = 0;
            e->unk_78 |= 0x800;
            break;
        case 3:
            e = ListPoolFirst(&w->unk_54[slot]);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[1];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A0 = 50;
            e->unk_A4 = 1;
            e->unk_78 |= 0x800;
            e = ListPoolNext(&e->node);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[2];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A0 = 60;
            e->unk_A4 = 2;
            e->unk_78 |= 0x800;
            e = ListPoolNext(&e->node);
            e->unk_80 = e->unk_7C = gUnk_09033FA8[0];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A0 = 60;
            e->unk_A4 = 0;
            e->unk_78 |= 0x800;
            break;
    }
    p = (EventCardLink*)ListPoolFirst(&w->unk_54[slot]);
    while (p != 0) {
        p->slot->unk_06 = 0;
        p = (EventCardLink*)ListPoolNext(&p->node);
    }
    w->unk_34[slot] = ListPoolFirst(&w->unk_54[slot]);
    {
        CardDisplayWork** active = &gUnk_02034A98;
        *active = ListPoolFirst(&w->unk_54[slot]);
    }
    gUnk_02034A98->unk_78 |= 0x804;
}

extern u16 gUnk_09033FC8[];
void func_08091B28(void);
void func_080782EC(void);
void func_080784BC(void* work, s32 mode);
void func_080785B8(void* work, s32 mode);

void func_08076CB4(UnkStruct_08080268* w) {
    u32 zero = 0;
    u8 i;

    CpuSet(&zero, w, 0x05000033);
    gUnk_02039DD4->unk_05C = (u32)w;
    gBtlWork->unk_0F4 = 0;
    func_08091B28();
    func_080782EC();
    w->tiles = AllocSpriteFrameTiles(128);
    w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    UpdateSpriteFrameTiles(w->tiles, gUnk_09EF12E8[0], (u32)gUnk_093FBAB8);
    TaskPoolInit((TaskPool*)w, 30);
    w->unk_B9 = 0;
    w->unk_B8 = 0;
    w->unk_C0[0] = 0;
    w->unk_C0[1] = 0;
    w->unk_C0[2] = 0;
    w->unk_C0[3] = 0;
    w->unk_BC[0] = 1;
    w->unk_BC[1] = 0;
    w->unk_BC[2] = 0;
    w->unk_BC[3] = 0;
    w->unk_BA = 0;
    w->unk_C4[3] = 0;
    w->x = gUnk_09033FC8[0];
    w->unk_C9 = 0;
    for (i = 0; i < 3; i++) {
        w->unk_1C[i] = 0;
        w->unk_28[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        w->unk_34[i] = 0;
        w->unk_44[i] = 0;
    }
    w->unk_C4[1] = 0;
    if (gBtlWork->flags & 0x800000000LL) {
        w->unk_A8[0] = gUnk_09041FA0.unk_DC + 15;
        w->unk_B0[0] = gUnk_09041FA0.unk_DC + 1;
        w->unk_A8[3] = w->unk_B0[3] = 0;
        w->unk_A8[2] = w->unk_B0[2] = 0;
        w->unk_A8[1] = w->unk_B0[1] = 0;
        func_080784BC(w, 0);
        func_080784BC(w, 1);
    } else {
        w->unk_A8[0] = func_080858B8(0) + 15;
        w->unk_B0[0] = func_080858B8(0) + 1;
        w->unk_A8[3] = w->unk_B0[3] = func_080858B8(1);
        w->unk_A8[2] = w->unk_B0[2] = 0;
        w->unk_A8[1] = w->unk_B0[1] = 0;
        func_080785B8(w, 0);
        func_080785B8(w, 1);
    }
    w->unk_9C[2] = w->unk_9C[1] = w->unk_9C[0] = 0;
    func_08076458();
    CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
    ListPoolInit(&w->unk_54[0]);
    ListPoolInit(&w->unk_54[1]);
    ListPoolInit(&w->unk_54[2]);
    ListPoolInit(&w->unk_54[3]);
    func_0807682C(w, w->unk_B8);
    gUnk_02034A9C = 0;
    gUnk_02034AA0 = 0;
    func_0807B410(w);
    w->unk_C4[4] = 0;
    if (gGameState.flags & 0x100) {
        return;
    }
    if (gGameState.flags & 8) {
        TaskCreate((TaskPool*)w, &gTaskDescDarkPoint, 0);
    }
}

s32 func_08076F4C(CardBattleWork* w) {
    if (func_080787B8(w, 0) == 0 && w->unk_B0 <= 1 && w->unk_B9 != 0) {
        return 1;
    }

    return 0;
}

extern u16 gUnk_09033FC8[];
void func_0807A620(void* work);
void func_0807B378(void* work);
void func_080788CC(void* work, u8 slot);
void func_08078FFC(void* work, u8 slot);
s32 func_08079600(void* work);
s32 func_08079B3C(void* work);
s32 func_08079ECC(void* work);
s32 func_0807A188(void* work);
void func_0807ABC8(void* work);
void func_0807B16C(void* work);
void func_0807AF40(void* work);
void func_0807B728(void* work);
void func_0807B7A4(void* work);
void func_0807B81C(void* work);
void func_0807B894(void* work);
void func_0807B910(void* work);
void func_0807B98C(void* work);
void func_0807B9EC(void* work);
void func_0807B6F4(void* work);
void func_080789E4(void* work);
void func_08078BB4(void* work);
u8 func_080782AC(CardDisplayWork** cards, u8 count);
s32 func_080AE28C(void* cards, void* output, u8 count);

s32 func_08076F80(UnkStruct_08080268* w, u8* task) {
    UnkStruct_080ABA80 data;
    u8 flag[4];
    UnkStruct_080ABA80 cards;
    u16 output[3];
    u8 i;
    u8 found;
    s32 position;
    u16 result;
    s32 kind;
    EventReloadArgs args;
    BtlObj* actor;

    if (gBtlWork->unk_0A0 == 4) {
        if (gBtlWork->flags & 0x1000000) {
            gBtlWork->flags &= ~0x1000000;
        }
        return 0;
    }
    if (w->unk_C4[3] != 0) {
        position = w->x * 256;
        ApproachValue(&position, (s16)gUnk_09033FC8[w->unk_B9 - 1] * 256, w->unk_C4[3]);
        w->x = position >> 8;
        w->unk_C4[3]--;
    }
    if (w->unk_C9 == 0) {
        if (gUnk_02034A98->unk_78 & 0x1000000) {
            if (gUnk_02034A98->unk_78 & 0x4000000) {
            if (gBtlWork->unk_0F4 == 9) {
                func_0807A620(w);
                TaskPoolUpdate((TaskPool*)w);
                if (gBtlWork->unk_0F4 != 25) {
                    func_0807B378(w);
                    if (gBtlWork->unk_0F4 == 10) {
                        w->unk_9C[w->unk_B8] -= 2;
                        if ((s16)w->unk_9C[w->unk_B8] < 0) {
                            w->unk_9C[w->unk_B8] = 0;
                        }
                    }
                }
                gUnk_02039DD4->unk_0FC = w->unk_9C[w->unk_B8];
                gUnk_02039DD4->unk_0F4 = 0;
                gUnk_02039DD4->unk_100 = 4;
                func_08078914((UnkStruct_08078754*)w, 0);
                w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
                w->unk_94[0] = 0;
                func_0807682C(w, 0);
                func_0807BB04();
            } else {
                gBtlWork->flags |= 0x80000000LL;
                func_0807A620(w);
                if (gBtlWork->unk_0F4 != 25) {
                    func_0807B378(w);
                    if (gBtlWork->unk_0F4 == 10) {
                        w->unk_9C[w->unk_B8] -= 2;
                        if ((s16)w->unk_9C[w->unk_B8] < 0) {
                            w->unk_9C[w->unk_B8] = 0;
                        }
                    }
                }
                gUnk_02039DD4->unk_0FC = w->unk_9C[w->unk_B8];
                gUnk_02039DD4->unk_0F4 = 0;
                gUnk_02039DD4->unk_100 = 4;
                func_080788CC(w, 0);
                w->unk_94[w->unk_B8] = 0;
                w->unk_B0[w->unk_B8] = 0;
                w->unk_C0[w->unk_B8] = 1;
                gUnk_02034A98 = 0;
                gUnk_02034A9C = 0;
            }
            }
        }
        switch (gUnk_02034A9C) {
        case 0:
            break;
        case 1:
            gUnk_02034A9C = 0;
            if (w->unk_B0[w->unk_B8] > 2) {
                if (gUnk_02034A98->unk_78 & 0x40) {
                    func_08078FFC(w, w->unk_B8);
                }
            } else if (w->unk_B0[w->unk_B8] > 1 && (gUnk_02034A98->unk_78 & 0x40)) {
                func_08078D98((u8*)w, w->unk_B8, 4);
            }
            break;
        case 2:
            gUnk_02034A9C = 0;
            if (w->unk_B0[w->unk_B8] > 2) {
                if (gUnk_02034A98->unk_78 & 0x40) {
                    func_08078E34(w, w->unk_B8, 4);
                }
            } else if (w->unk_B0[w->unk_B8] > 1 && (gUnk_02034A98->unk_78 & 0x40)) {
                func_08078D98((u8*)w, w->unk_B8, 4);
            }
            break;
        case 4:
            gUnk_02034A9C = 0;
            if (!(gUnk_02034A98->unk_78 & 0x100000)) {
                if (w->unk_B9 == 3) {
                    func_0807ABC8(w);
                } else if (gUnk_02034A98->cardDef->unk_2A == 3) {
                    m4aSongNumStart(SONG_SYS_BEEP);
                } else if (w->unk_C0[w->unk_B8] == 0) {
                    if (!(gUnk_02034A98->unk_78 & 2)) {
                        if (func_0807B60C() != 0) {
                            if (w->unk_B0[w->unk_B8] > 0 && w->unk_B9 <= 2 && gUnk_02039DD4->unk_0E1 == 0) {
                                func_0807A188(w);
                            }
                        } else if (gUnk_02034A98->unk_78 & 0x20) {
                            m4aSongNumStart(SONG_SYS_BEEP);
                        }
                    } else if (gUnk_02034A98->unk_78 & 0x20) {
                        m4aSongNumStart(SONG_SYS_BEEP);
                    }
                }
            } else if (w->unk_B9 != 0) {
                func_0807ABC8(w);
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
            w->unk_C4[4] = 1;
            break;
        case 3:
            gUnk_02034A9C = 0;
            if (gUnk_02034A98->cardDef->unk_2A != 3) {
                if (!(gUnk_02034A98->unk_78 & 0x100000)) {
                    if (w->unk_C0[w->unk_B8] == 0) {
                        if (gUnk_02034A98->cardDef->flags & 0x10) {
                            func_08079ECC(w);
                        } else if (!(gUnk_02034A98->unk_78 & 2)) {
                            if (func_0807B60C() != 0) {
                                func_08079600(w);
                            } else if (gUnk_02034A98->unk_78 & 0x20) {
                                m4aSongNumStart(SONG_SYS_BEEP);
                            }
                        } else if (gUnk_02034A98->unk_78 & 0x20) {
                            m4aSongNumStart(SONG_SYS_BEEP);
                        }
                    }
                } else {
                    goto locked;
                }
            } else if (!(gUnk_02034A98->unk_78 & 0x100000)) {
                func_08079B3C(w);
            } else {
            locked:
                if (gGameState.flags & 8) {
                    func_0807A620(w);
                    gUnk_02034A98 = 0;
                    gBtlWork->flags |= 0x80000000LL;
                    w->unk_B0[w->unk_B8] = 0;
                    w->unk_C0[w->unk_B8] = 1;
                }
            }
            w->unk_C4[4] = 1;
            break;
        case 5:
            gUnk_02034A9C = 0;
            if (w->unk_B9 != 0) {
                func_0807ABC8(w);
            } else if (!(gBtlWork->flags & 0x80)) {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
            w->unk_C4[4] = 1;
            break;
        case 6:
            gUnk_02034A9C = 0;
            func_0807A6C8(w);
            break;
        case 7:
            w->unk_BC[w->unk_B8] = 0;
            w->unk_C4[0] = 0;
            func_0807A75C(w);
            break;
        case 8:
            gUnk_02034A9C = 0;
            break;
        case 9:
            gUnk_02034A9C = 0;
            func_0807B16C(w);
            w->unk_C4[4] = 1;
            break;
        case 10:
            gUnk_02034A9C = 0;
            func_0807AF40(w);
            w->unk_C4[4] = 1;
            break;
        case 11:
            w->unk_A6 = 60;
            gUnk_02034A9C = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)func_0807B578);
            break;
        case 12:
            w->unk_A6 = 180;
            gUnk_02034A9C = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)func_0807B578);
            break;
        case 13:
            w->unk_A6 = 300;
            gUnk_02034A9C = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)func_0807B578);
            break;
        default:
            gUnk_02034A9C = 0;
            break;
        }
        switch (gUnk_02034AA0) {
        case 14:
            gUnk_02034AA0 = 0;
            if (w->unk_B8 == 0) {
                func_0807A620(w);
                gUnk_02034A98 = 0;
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
                gUnk_02034A98 = 0;
            }
            gBtlWork->flags |= 0x80000000LL;
            w->unk_B0[0] = 0;
            w->unk_C0[0] = 1;
            m4aSongNumStart(SONG_SYS_CHAGEF2);
            if (FadeGetAmount() == 0) {
                FadeFromAmount(2, 16, 20);
            }
            break;
        case 15:
            gUnk_02034AA0 = 0;
            if (w->unk_B8 == 0) {
                func_0807A620(w);
                gUnk_02034A98 = 0;
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
                gUnk_02034A98 = 0;
            }
            m4aSongNumStart(SONG_SYS_CHAGEF2);
            if (FadeGetAmount() == 0) {
                FadeFromAmount(2, 16, 20);
            }
            gBtlWork->flags |= 0x80000000LL;
            w->unk_B0[0] = 0;
            w->unk_C0[0] = 1;
            break;
        case 16:
            gUnk_02034AA0 = 0;
            if (w->unk_B8 == 0) {
                func_0807A620(w);
                gUnk_02034A98 = 0;
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
                gUnk_02034A98 = 0;
            }
            m4aSongNumStart(SONG_SYS_CHAGEF2);
            if (FadeGetAmount() == 0) {
                FadeFromAmount(2, 16, 20);
            }
            gBtlWork->flags |= 0x80000000LL;
            w->unk_B0[0] = 0;
            w->unk_C0[0] = 1;
            break;
        case 17:
            gUnk_02034AA0 = 0;
            func_0807B728(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            w->unk_94[0] = 0;
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 18:
            gUnk_02034AA0 = 0;
            func_0807B7A4(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            w->unk_94[0] = 0;
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 19:
            gUnk_02034AA0 = 0;
            func_0807B81C(w);
            w->unk_9C[0] = 0;
            func_0807B6F4(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_94[0] = 0;
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 21:
            gUnk_02034AA0 = 0;
            func_0807B894(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            w->unk_94[0] = 0;
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 22:
            gUnk_02034AA0 = 0;
            func_0807B910(w);
            w->unk_9C[0] = 0;
            func_0807B6F4(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_94[0] = 0;
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 23:
            gUnk_02034AA0 = 0;
            func_0807B98C(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_94[0] = 0;
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 24:
            gUnk_02034AA0 = 0;
            func_0807B98C(w);
            w->unk_9C[0] = 0;
            func_0807B6F4(w);
            if (w->unk_B8 == 0) {
                func_0807A620(w);
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
            }
            TaskPoolUpdate((TaskPool*)w);
            func_080788CC(w, 0);
            w->unk_94[0] = 0;
            w->unk_B0[0] = func_08078754((UnkStruct_08078754*)w, 0);
            func_0807682C(w, 0);
#ifdef VERSION_EU
            if (w->unk_BC[w->unk_B8] == 0) {
                CreateREVCOUNTTask(w, (u8*)&w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
            }
#endif
            func_0807BB04();
            break;
        case 20:
            gUnk_02034AA0 = 0;
            func_0807B9EC(w);
            if (w->unk_B8 == 0) {
                w->unk_9C[0] = 0;
                func_0807A620(w);
                gUnk_02034A98 = 0;
            } else {
                func_0807A620(w);
                w->unk_B8 = 0;
#ifdef VERSION_EU
                gUnk_02039DD4->unk_0D2 = 0;
#endif
                gUnk_02034A98 = 0;
            }
            m4aSongNumStart(SONG_SYS_CHAGEF2);
            if (FadeGetAmount() == 0) {
                FadeFromAmount(2, 16, 20);
            }
            gBtlWork->flags |= 0x80000000LL;
            w->unk_B0[0] = 0;
            w->unk_C0[0] = 1;
            break;
        default:
            gUnk_02034AA0 = 0;
            break;
        }
        if (gUnk_02039DD4->unk_0B8 != 950 && w->unk_C4[4] == 0 && w->unk_C0[w->unk_B8] == 0) {
            gBtlWork->flags |= 0x20000000000LL;
            func_08078BB4(w);
        }
        if (gUnk_02039DD4->unk_0BC != 950 && w->unk_C4[4] == 0 && w->unk_C0[w->unk_B8] == 0) {
            func_08078BB4(w);
        }
        if (w->unk_C0[w->unk_B8] != 0) {
            if (gUnk_02034A98 != 0) {
                if (gUnk_02034A98->unk_78 & 0x4000000) {
                    gUnk_02034A98->unk_78 |= 0x4000;
                    func_080789E4(w);
                    w->unk_C0[w->unk_B8] = 0;
                    w->unk_C4[0] = 1;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_08077F44);
                    TaskPoolUpdate((TaskPool*)w);
                    TaskPoolUpdate(&gUnk_02039DD4->tasks);
                    args.slot = w->unk_B8;
                    args.state = &w->unk_C4[0];
                    args.mode = 1;
                    TaskCreate((TaskPool*)w, &gTaskDescRELOAD, &args);
                    return 1;
                }
            } else {
                func_080789E4(w);
                w->unk_C0[w->unk_B8] = 0;
                SetTaskUpdate(task, (TaskUpdateFunc)func_08077F44);
                TaskPoolUpdate((TaskPool*)w);
                TaskPoolUpdate(&gUnk_02039DD4->tasks);
                return 1;
            }
        } else if (gUnk_02034A98 != 0 && (gUnk_02034A98->unk_78 & 0x42) == 0x42 && func_080787B8((CardBattleWork*)w, w->unk_B8) != 0) {
            w->unk_C0[w->unk_B8] = 1;
            gUnk_02034A98->unk_A1 = 7;
            actor = gBtlWork->actor;
            if (actor->unk_02C > 3) {
                actor->unk_02C -= 2;
            }
            gBtlWork->flags |= 0x80000000LL;
            if (gBtlWork->unk_0F4 != 25) {
                func_0807B378(w);
                if (gBtlWork->unk_0F4 == 10) {
                    w->unk_9C[w->unk_B8] -= 2;
                    if ((s16)w->unk_9C[w->unk_B8] < 0) {
                        w->unk_9C[w->unk_B8] = 0;
                    }
                }
            }
        }
        if (w->unk_C4[1] == 0 && func_080782AC(w->unk_28, w->unk_B9) != 0) {
            data = gUnk_09033FD0;
            if (!(gBtlWork->flags & 0x4000)) {
                result = func_080AC5E8(w->unk_28, w->unk_B9, w->unk_BA, &data, flag);
            } else {
                result = func_080AD144(w->unk_28, w->unk_B9, w->unk_BA, &data, flag, 0);
            }
            if (result != 108) {
                gUnk_02039DD4->unk_0C4 = result;
                if (result <= 105) {
                    if (result != 107) {
                        for (i = 0; i < w->unk_B9; i++) {
                            w->unk_28[i]->unk_78 |= 0x10000000;
                        }
                        if (gUnk_02039DD4->unk_0E3 == 0) {
                            TaskCreate((TaskPool*)w, &gUnk_09EE77D4, 0);
                            gUnk_02039DD4->unk_0E3 = 1;
                        }
                    } else {
                        for (i = 0; i < w->unk_B9; i++) {
                            w->unk_28[i]->unk_78 |= 0x10000000;
                        }
                        if (gUnk_02039DD4->unk_0E3 == 0) {
                            TaskCreate((TaskPool*)w, &gUnk_09EE77D4, &data);
                            gUnk_02039DD4->unk_0E3 = 1;
                        }
                    }
                } else if (w->unk_B9 == 3) {
                    cards = gUnk_09033FD0;
                    memset(output, 0, sizeof(output));
                    found = 0;
                    for (i = 0; i < w->unk_B9; i++) {
                        cards.unk_00[i] = w->unk_28[i]->cardDef->unk_28;
                    }
                    kind = func_080AE28C(&cards, output, w->unk_B9);
                    switch (kind) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 11:
                    case 15:
                    case 17:
                    case 19:
                    case 21:
                    case 23:
                    case 25:
                    case 27:
                    case 29:
                    case 31:
                    case 33:
                    case 35:
                    case 37:
                    case 39:
                    case 41:
                    case 43:
                    case 44:
                        gUnk_02039DD4->unk_0C4 = kind;
                        found = 1;
                        break;
                    }
                    if (found == 0) {
                        for (i = 0; i < w->unk_B9; i++) {
                            w->unk_28[i]->unk_78 &= ~0x10000000;
                        }
                        if (gUnk_02039DD4->unk_0E3 != 0) {
                            gUnk_02039DD4->unk_0E3 = 0;
                        }
                    } else {
                        for (i = 0; i < w->unk_B9; i++) {
                            w->unk_28[i]->unk_78 |= 0x10000000;
                        }
                        if (gUnk_02039DD4->unk_0E3 == 0) {
                            TaskCreate((TaskPool*)w, &gUnk_09EE77D4, 0);
                            gUnk_02039DD4->unk_0E3 = 1;
                        }
                    }
                }
            }
            w->unk_C4[1] = 1;
        }
    }
    TaskPoolUpdate((TaskPool*)w);
    TaskPoolUpdate(&gUnk_02039DD4->tasks);
    gUnk_02039DD4->unk_0D3 = w->unk_B9;
    w->unk_C4[4] = 0;
    if (gBtlWork->flags & 0x80000000000000LL) {
        gBtlWork->flags &= ~0x80000000000000LL;
        w->unk_C4[1] = 0;
    }
    return 1;
}

void func_08077E10(CardBattleWork* w) {
    gUnk_02039DD4->gfx = AnimUpdate(&gUnk_02039DD4->anim);
    gUnk_02039DD4->gfx2 = AnimUpdate(&gUnk_02039DD4->anim2);

    if (gUnk_02039DD4->unk_0EA != 0 && w->unk_B9 != 0 && w->unk_BA != 0) {
        DrawSprite(w->x, 4, gUnk_09EF12E8[0], w->tiles, w->palette, 0, 16,
                   12);
    }

    TaskPoolDraw(w);
    TaskPoolDraw(&gUnk_02039DD4->tasks);
}

void func_08077E98(CardBattleWork* w) {
    u8 i;

    TaskPoolDestroy(w);
    TaskPoolDestroy(&gUnk_02039DD4->tasks);

    for (i = 0; i < 4; i++) {
        if (w->unk_44[i] != 0) {
            EwramFree(w->unk_44[i]);
        }
    }

    ReleaseObjTiles(gUnk_02039DD4->tiles7);
    ReleaseObjTiles(gUnk_02039DD4->tiles6);
    ReleaseObjTiles(gUnk_02039DD4->tiles5);
    ReleaseObjPalette(gUnk_02039DD4->palette);
    ReleaseObjPalette(gUnk_02039DD4->palette2);
    ReleaseObjTiles(gUnk_02039DD4->unk_040);
    ReleaseObjTiles(gUnk_02039DD4->unk_050);
    ReleaseObjTiles(gUnk_02039DD4->tiles);
    ReleaseObjTiles(gUnk_02039DD4->tiles2);
    ReleaseObjTiles(gUnk_02039DD4->tiles3);
    ReleaseObjTiles(gUnk_02039DD4->tiles4);
    EwramFree(gUnk_02039DD4);
    gUnk_02039DD4 = 0;
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

s32 func_08077F44(UnkStruct_08080268* w, u8* task) {
    UnkStruct_0807FD10_Args arg;
    CardDisplayWork* e;
    CardSlot* c;
    u16 n;
    s16 a;
    s16 b;
    s8 k;

    a = 255;
    b = 255;

    if (gBtlWork->unk_0A0 == 4) {
        if (gUnk_02039B9C->flags & 0x1000000) {
            gUnk_02039B9C->flags &= ~0x1000000;
        }

        m4aSongNumStop(SONG_SYS_RELOAD);

        return 0;
    }

    if (*(s16*)&gUnk_02034A98->unk_9C == 0) {
        if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) > w->unk_C4[2]) {
            gUnk_02034A98->unk_78 &= ~4;
            e = ListPoolFirst(&w->unk_54[w->unk_B8]);

            while (e != 0) {
                e->unk_A4++;
                e->unk_80 = gUnk_09033FA8[e->unk_A4];
                e->unk_9C = 4;
                e->unk_A0 += 4;
                e = ListPoolNext(&e->node);
            }

            n = gUnk_02034A98->unk_44 - 1;
            c = func_08076750((UnkStruct_08078754*)w, w->unk_B8, &n);

            if (c != 0) {
                arg.unk_00 = &w->unk_54[w->unk_B8];
                arg.unk_0C = n;
                arg.unk_0E = w->unk_B8;
                arg.slot = c;
                arg.unk_0F = w->unk_9C[w->unk_B8];

                if (c->cardId == 0xFFFE) {
                    e = ((Task*)TaskCreate((TaskPool*)w, &gTaskDescCardReload, &arg))->work;
                } else {
                    e = ((Task*)TaskCreate((TaskPool*)w, &gUnk_09EE496C, &arg))->work;
                }

                e->unk_80 = e->unk_7C = gUnk_09033FA8[1];
                e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
                e->unk_A4 = 1;
                e->unk_9C = 8;
                e->unk_A0 = 50;
                e->unk_78 |= 0x814;
                gUnk_02034A98 = e;
                w->unk_C4[2]++;
                w->unk_B0[w->unk_B8]++;
            }
        } else {
            e = ListPoolFirst(&w->unk_54[w->unk_B8]);

            while (e != 0) {
                k = e->unk_A4;

                if (k == 1) {
                    a = *(u16*)((u8*)e + 0x44);
                }

                if (k == 2) {
                    b = *(u16*)((u8*)e + 0x44);
                }

                e = ListPoolNext(&e->node);
            }

            n = w->unk_A8[w->unk_B8] - 1;
            c = func_08076750((UnkStruct_08078754*)w, w->unk_B8, &n);

            if (c != 0 && (s16)n != a && (s16)n != b) {
                arg.unk_00 = &w->unk_54[w->unk_B8];
                arg.unk_0C = n;
                arg.unk_0E = w->unk_B8;
                arg.slot = c;
                arg.unk_0F = w->unk_9C[w->unk_B8];

                if (c->cardId == 0xFFFE) {
                    e = ((Task*)TaskCreate((TaskPool*)w, &gTaskDescCardReload, &arg))->work;
                } else {
                    e = ((Task*)TaskCreate((TaskPool*)w, &gUnk_09EE496C, &arg))->work;
                }

                e->unk_7C = gUnk_09033FA8[3];
                e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
                e->unk_A4 = 0;
                e->unk_80 = gUnk_09033FA8[0];
                e->unk_A0 = 60;
                e->unk_78 |= 0x800;
            }

            gBtlWork->flags &= ~0x80000000LL;
            gBtlWork->flags &= ~0x100;
            w->unk_C4[0] = 0;
            m4aSongNumStop(SONG_SYS_RELOAD);
            gUnk_02034A9C = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08076F80);
        }
    }

    if (gUnk_02034A9C == 7) {
        w->unk_BC[w->unk_B8] = 0;
        w->unk_C4[0] = 0;
        func_0807A75C(w);
        m4aSongNumStop(SONG_SYS_RELOAD);
    }

    TaskPoolUpdate((TaskPool*)w);
    TaskPoolUpdate(&gUnk_02039DD4->tasks);

    return 1;
}

u16 gUnk_09EE48F4[47] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 34, 35, 36, 38, 39, 40, 41, 42, 43, 44, 46, 47, 48, 49, 50, 51, 53,
};

const char gTaskNameCardBattleSora[] = "cardbattle";

TaskDesc gTaskDescCardBattleSora = {
    gTaskNameCardBattleSora,
    (TaskInitFunc)func_08076CB4,
    (TaskUpdateFunc)func_08076F80,
    (TaskFunc)func_08077E10,
    (TaskFunc)func_08077E98,
    0xCC,
};
