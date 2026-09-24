#include "macros.h"
#include "card_localized_data.h"
#include "card_label_sprite_data.h"
#include "card_reload_sprite_data.h"
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
#include "sprites_card.h"
#include "sprites_card_pictures.h"

u32 gUnk_02034AA4;

u32 gUnk_02034AA8;

CardDisplayWork* gUnk_02034AAC;

const s32 gUnk_09033FF4[5][2] = {
    { -0x3A00, 0xD400 },
    { 0x4000, 0x1800 },
    { 0x3400, 0x1800 },
    { 0x2800, 0x1800 },
    { -0x1400, 0xB800 },
};

const s32 gUnk_0903401C[6][2] = {
    { 0x12A00, 0xD400 },
    { 0xB000, 0x1800 },
    { 0xBC00, 0x1800 },
    { 0xC800, 0x1800 },
    { 0x10400, 0xB800 },
    { 0xD800, 0x8000 },
};

const s32 gUnk_0903404C[2] = {
    0x7800, 0x8C00,
};

const s32 gUnk_09034054[3] = {
    0x5A00, 0, 0xAC00,
};

u8 func_0807CE68(CardDisplayWork* p);
void func_0807C39C(CardDisplayWork* p);
void func_0807C33C(CardDisplayWork* p);
u8 func_0807C934(CardDisplayWork* p, void* a);
u8 func_0807D810(u8* work);
void func_0807D4B8(CardDisplayWork* p);
void func_0807B458(UnkStruct_08080268* w, u16 value);
void func_0807B45C(UnkStruct_08080268* w);
void func_0807B478(CardDisplayWork* w);
u8 func_0807C5D8(CardDisplayWork* w, void* a);
void func_0807CC2C(CardDisplayWork* p);
u8 func_0807D194(CardDisplayWork* p, void* a);
u8 func_0807D584(CardDisplayWork* p, void* a);
void func_0807CD48(CardDisplayWork* p);
u8 func_0807D7B0(CardDisplayWork* p);
u8 func_0807CF4C(u8* work, void* a);
void func_0807DE10(CardDisplayWork* p);
void func_0807E184(void);
u8 func_0807CE04(CardDisplayWork* p);
void func_0807D0F4(CardDisplayWork* p);

u8 func_080782AC(CardDisplayWork** p, u8 n) {
    u8 count;
    u8 i;

    i = 0;
    count = 0;

    for (; i < n; i++) {
        if (p[i]->unk_78 & 0x40) {
            count++;
        }
    }

    if (n == count) {
        return 1;
    }

    return 0;
}

void func_080782EC(void) {
    gBtlWork->flags &= ~0x80;
    gBtlWork->flags &= ~0x100;
    gBtlWork->flags &= ~0x200;
    gBtlWork->flags &= ~0x400;
}

void func_08078330(CardSlot* slots, s32 deckIndex) {
    u16* buf;
    vu16 zero;
    u16 n;
    u16 i;

    n = func_080858B8(deckIndex);
    buf = EwramAlloc(n * 2);
    zero = 0;
    CpuSet((void*)&zero, buf, n | 0x1000000);
    func_08085A58(deckIndex, buf);

    for (i = 0; i < n; i++) {
        slots[i].unk_06 = 0;
        slots[i].unk_07 = 0;
        slots[i].unk_0A = 0;
        slots[i].cardId = buf[i];
        slots[i].unk_04 = i;
        slots[i].unk_09 = 0;
    }

    if (deckIndex == 0) {
        slots[n].unk_06 = 0;
        slots[n].unk_07 = 0;
        slots[n].unk_0A = 0;
        slots[n].cardId = 0xFFFE;
        slots[n].unk_04 = n;
        slots[n].unk_09 = 0;
    }

    EwramFree(buf);
}

void func_080783C0(CardSlot* slots) {
    u16 n;
    u16 i;

    n = gUnk_09041FA0.unk_DC;

    for (i = 0; i < n; i++) {
        slots[i].unk_06 = 0;
        slots[i].unk_07 = 0;
        slots[i].unk_0A = 0;
        slots[i].cardId = gUnk_09041F70[gUnk_09041FA0.cards[i]];
        slots[i].unk_04 = i;
        slots[i].unk_09 = 0;
    }

    slots[n].unk_06 = 0;
    slots[n].unk_07 = 0;
    slots[n].unk_0A = 0;
    slots[n].cardId = 0xFFFE;
    slots[n].unk_04 = n;
    slots[n].unk_09 = 0;
}

void sub_0807842C(CardSlot* slots, u8 n) {
    CardSlot a;
    CardSlot b;
    u8 i;
    u8 x;
    u8 y;

    for (i = 0; i < n; i++) {
        x = GetRandom() % n;
        y = GetRandom() % n;

        if (x != y) {
            a = slots[x];
            b = slots[y];
            slots[x] = b;
            slots[y] = a;
        }
    }
}

void func_080784BC(u8* w, s32 mode) {
    u16 n = gUnk_09041FA0.unk_DC;

    switch (mode) {
    case 0: {
        CardSlot* slots;
        vu32 zero;
        u16 i;

        slots = EwramAlloc((n + 15) * sizeof(CardSlot));
        *(CardSlot**)&w[0x44] = slots;
        zero = 0;
        CpuSet((void*)&zero, slots, ((n + 15) * 3) | 0x05000000);

        for (i = 0; i < n + 1; i++) {
            (*(CardSlot**)&w[0x44])[i].unk_06 = 0;
            (*(CardSlot**)&w[0x44])[i].unk_07 = 0;
            (*(CardSlot**)&w[0x44])[i].unk_0A = 0;
            (*(CardSlot**)&w[0x44])[i].unk_08 = 0;
        }

        for (i = n + 1; i < n + 15; i++) {
            (*(CardSlot**)&w[0x44])[i].unk_06 = 1;
            (*(CardSlot**)&w[0x44])[i].unk_07 = 1;
            (*(CardSlot**)&w[0x44])[i].unk_0A = 1;
            (*(CardSlot**)&w[0x44])[i].unk_08 = 1;
        }

        func_080783C0(*(CardSlot**)&w[0x44]);
        *(u16*)&w[0x94] = 0;
        break;
    }
    case 1: {
        CardSlot* slot;
        u16* q;
        s32 k;
        vu32 zero;

        slot = EwramAlloc(sizeof(CardSlot));
        *(CardSlot**)&w[0x50] = slot;
        zero = 0;
        CpuSet((void*)&zero, slot, 3 | 0x05000000);
        (*(CardSlot**)&w[0x50])->cardId = 0x30FF;
        q = (u16*)&w[0x9A];
        k = 0xFFFF;
        *q = k;
        break;
    }
    }
}

void func_080785B8(u8* w, s32 mode) {
    u16 n = func_080858B8(mode);

    switch (mode) {
    case 0:
        if (n != 0) {
            CardSlot* slots;
            vu32 zero;
            u8 i;

            slots = EwramAlloc((n + 15) * sizeof(CardSlot));
            *(CardSlot**)&w[0x44] = slots;
            zero = 0;
            CpuSet((void*)&zero, slots, ((n + 15) * 3) | 0x05000000);

            for (i = 0; i < n + 1; i++) {
                (*(CardSlot**)&w[0x44])[i].unk_06 = 0;
                (*(CardSlot**)&w[0x44])[i].cardId = 0xFFFF;
                (*(CardSlot**)&w[0x44])[i].unk_07 = 0;
                (*(CardSlot**)&w[0x44])[i].unk_0A = 0;
                (*(CardSlot**)&w[0x44])[i].unk_08 = 0;
            }

            for (i = n + 1; i < n + 15; i++) {
                (*(CardSlot**)&w[0x44])[i].unk_06 = 1;
                (*(CardSlot**)&w[0x44])[i].cardId = 0xFFFF;
                (*(CardSlot**)&w[0x44])[i].unk_07 = 1;
                (*(CardSlot**)&w[0x44])[i].unk_0A = 1;
                (*(CardSlot**)&w[0x44])[i].unk_08 = 1;
            }

            func_08078330(*(CardSlot**)&w[0x44], 0);
            *(u16*)&w[0x94] = 0;
        } else {
            CardSlot* slot;
            vu32 zero;
            u16* q;
            s32 k;

            slot = EwramAlloc(sizeof(CardSlot));
            *(CardSlot**)&w[0x44] = slot;
            zero = 0;
            CpuSet((void*)&zero, slot, 3 | 0x05000000);
            (*(CardSlot**)&w[0x44])->cardId = 0xFF;
            q = (u16*)&w[0x94];
            k = 0xFFFF;
            *q = k;
        }
        break;
    case 1:
        if (n != 0) {
            CardSlot* slots;
            u8 i;

            slots = EwramAlloc(n * sizeof(CardSlot));
            *(CardSlot**)&w[0x50] = slots;

            for (i = 0; i < n; i++) {
                (*(CardSlot**)&w[0x50])[i].unk_06 = 0;
                (*(CardSlot**)&w[0x50])[i].cardId = 0xFFFF;
                (*(CardSlot**)&w[0x50])[i].unk_07 = 0;
                (*(CardSlot**)&w[0x50])[i].unk_0A = 0;
                (*(CardSlot**)&w[0x50])[i].unk_08 = 0;
            }

            func_08078330(*(CardSlot**)&w[0x50], 1);
            *(u16*)&w[0x9A] = 0;
        } else {
            CardSlot* slot;
            vu32 zero;
            u16* q;
            s32 k;

            slot = EwramAlloc(sizeof(CardSlot));
            *(CardSlot**)&w[0x50] = slot;
            zero = 0;
            CpuSet((void*)&zero, slot, 3 | 0x05000000);
            (*(CardSlot**)&w[0x50])->cardId = 0x30FF;
            q = (u16*)&w[0x9A];
            k = 0xFFFF;
            *q = k;
        }
        break;
    }
}

u16 func_08078754(UnkStruct_08078754* w, u8 n) {
    u16 count;
    u16 i;
    u16 max;

    max = w->unk_A8[n];
    count = 0;

    for (i = 0; i < max; i++) {
        if (w->slots[n][i].unk_06 == 0 && w->slots[n][i].unk_07 == 0 && w->slots[n][i].unk_08 == 0 && w->slots[n][i].unk_0A == 0) {
            count++;
        }
    }

    return count;
}

u16 func_080787B8(UnkStruct_08078754* w, u8 n) {
    u16 count;
    u16 i;
    u16 max;

    max = w->unk_A8[n];
    count = 0;

    for (i = 0; i < max; i++) {
        if (w->slots[n][i].unk_06 == 0 && w->slots[n][i].unk_07 == 0 && w->slots[n][i].unk_08 == 0 && w->slots[n][i].unk_0A == 0 && w->slots[n][i].cardId != 0xFFFE) {
            count++;
        }
    }

    if (gUnk_02034A98->unk_78 & 0x100000) {
        if (w->unk_B0[w->unk_B8] == 1) {
            count = 0;
        }
    }

    return count;
}

u16 func_0807885C(UnkStruct_08078754* w, u8 b) {
    CardSlot* c;
    u16 count;
    u16 i;
    u16 n;

    n = w->unk_A8[b];
    count = 0;

    for (i = 0; i < n; i++) {
        c = w->slots[b];

        if (c[i].unk_0A == 0) {
            if (c[i].cardId != 0xFFFE) {
                if (gCardDefs[c[i].cardId & CARD_ID_MASK].unk_2A == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}

void func_080788CC(UnkStruct_08078754* w, u8 b) {
    u8 i;

    for (i = 0; i < w->unk_A8[b]; i++) {
        if (w->slots[b][i].unk_07 == 0) {
            w->slots[b][i].unk_08 = 0;
        }
    }
}

void func_08078914(UnkStruct_08078754* w, u8 n) {
    u8 i;

    if (gGameState.flags & 8) {
        for (i = 0; i < w->unk_A8[n]; i++) {
            if (w->slots[n][i].unk_07 == 0) {
                w->slots[n][i].unk_08 = 0;
                w->slots[n][i].unk_06 = 0;
            }

            if (!(gBtlWork->flags & 0x800000000000)) {
                if (w->slots[n][i].unk_09 == 1) {
                    w->slots[n][i].unk_0A = 0;
                    w->slots[n][i].unk_09 = 0;
                }
            }
        }
    } else {
        for (i = 0; i < w->unk_A8[n]; i++) {
            if (w->slots[n][i].unk_07 == 0) {
                w->slots[n][i].unk_08 = 0;
                w->slots[n][i].unk_06 = 0;
            }
        }
    }
}

void func_080789E4(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    CardDisplayWork* p;
    CardSlot* c;
    u16 n;
    s32 z;

    z = 0;
    w->unk_C4[2] = z;
    func_08078914((UnkStruct_08078754*)w, w->unk_B8);

    if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) != z) {
        n = w->unk_A8[w->unk_B8] - 1;
        c = func_08076750(w, w->unk_B8, &n);

        if (c != 0) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = n;
            args.unk_0E = w->unk_B8;
            args.slot = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->cardId == 0xFFFE) {
                p = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                p = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            p->unk_80 = p->unk_7C = gUnk_09033FA8[1];
            p->unk_98 = p->unk_94 = gUnk_09033FB8[0];
            p->unk_A4 = 1;
            p->unk_9C = 8;
            p->unk_A0 = 50;
            p->unk_78 |= 0x814;
            gUnk_02034A98 = p;
            w->unk_C4[2]++;
            w->unk_B0[w->unk_B8]++;
        }

        m4aSongNumStart(SONG_SYS_RELOAD);
    } else {
        args.unk_00 = &w->unk_54[w->unk_B8];
        args.unk_0C = 0xFFFF;
        args.slot = (CardSlot*)w->unk_44[w->unk_B8];
        args.unk_0E = w->unk_B8;
        p = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardNotHave, &args))[1];
        p->unk_80 = p->unk_7C = gUnk_09033FA8[1];
        p->unk_98 = p->unk_94 = gUnk_09033FB8[0];
        p->unk_A0 = 50;
        p->unk_78 |= 0x806;
        gUnk_02034A98 = p;
    }

    z = w->unk_B8;

    if (w->unk_B0[z] > 0) {
        if (w->unk_BC[z] == 0) {
            CreateREVCOUNTTask(w, &w->unk_B8, &w->unk_B0[z], &w->unk_BC[z], 1);
        }
    }

    func_0807BB04();
}

void func_08078BB4(UnkStruct_08080268* w) {
    CardDisplayWork* node;
    CardSlot* c;
    s32 z;

    c = (CardSlot*)w->unk_44[0];

    if (gUnk_02039DD4->unk_0BC == 0x28F) {
        c[(s16)w->unk_A8[0] - 5].cardId = 0x28F;
        c[(s16)w->unk_A8[0] - 5].unk_04 = (s16)w->unk_A8[0] - 5;
        c[(s16)w->unk_A8[0] - 5].unk_06 = 0;
        c[(s16)w->unk_A8[0] - 5].unk_07 = 0;
        c[(s16)w->unk_A8[0] - 5].unk_0A = 0;
        c[(s16)w->unk_A8[0] - 5].unk_08 = 0;
        gUnk_02039DD4->unk_0BC = 0x3B6;
    } else {
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].cardId = gUnk_02039DD4->unk_0B8;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_04 = gUnk_02039DD4->unk_0DA[0] + ((s16)w->unk_A8[0] - 14);
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_06 = 0;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_07 = 0;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_0A = 0;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_08 = 0;
        gUnk_02039DD4->unk_0B8 = 0x3B6;
        gUnk_02039DD4->unk_0DA[0]++;
    }

    w->unk_B0[0]++;
    w->unk_94[0] = w->unk_A8[0] - 1;

    if (w->unk_B8 == 0) {
        w->unk_94[0] = gUnk_02034A98->unk_44;
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[0]);

        while (node != 0) {
            node->unk_A1 = 7;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }

        TaskPoolUpdate(w);
        func_0807682C(w, 0);
        z = w->unk_B8;

        if (w->unk_BC[z] == 0) {
            CreateREVCOUNTTask(w, &w->unk_B8, &w->unk_B0[z], &w->unk_BC[z], 1);
        }
    }
}

void func_08078D98(u8* work, u8 kind, u8 c) {
    CardDisplayWork* node;

    m4aSongNumStart(SONG_SYS_CLICKI04B);
    node = (CardDisplayWork*)ListPoolFirst(&work[kind * 16 + 0x54]);

    while (node != 0) {
        switch (node->unk_A4) {
        case 0:
            node->unk_A4++;
            break;
        case 1:
            node->unk_A4--;
            break;
        case 2:
            node->unk_A4--;
            break;
        }

        node->unk_80 = gUnk_09033FA8[node->unk_A4];
        node->unk_9C = c;
        node->unk_78 &= ~4;

        if (node->unk_A4 == 1) {
            gUnk_02034A98 = node;
            node->unk_78 |= 4;
        }

        node = (CardDisplayWork*)ListPoolNext(&node->node);
    }
}

void func_08078E34(UnkStruct_08080268* w, u8 b, u8 c) {
    UnkStruct_0807FD10_Args args;
    CardDisplayWork* p;
    CardDisplayWork* q;
    CardSlot* slot;
    s16 prev;
    s32 v;
    s32 cur;
    u16 n;

    m4aSongNumStart(SONG_SYS_CLICKI04B);
    gUnk_02034A98->unk_78 &= ~4;
    prev = gUnk_02034A98->unk_44;
    p = (CardDisplayWork*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        if (p->unk_A4 == 0) {
            gUnk_02034A98 = p;
            break;
        }

        p = (CardDisplayWork*)ListPoolNext(&p->node);
    }

    gUnk_02034A98->unk_78 |= 0x804;
    cur = (s16)gUnk_02034A98->unk_44;
    n = cur - 1;

    if ((s16)n < 0) {
        n = w->unk_A8[b] - 1;
    }

    slot = func_08076750(w, b, &n);

    if (slot != 0) {
        v = (s16)n;

        if (v != cur && v != prev) {
            args.unk_00 = &w->unk_54[b];
            args.unk_0C = n;
            args.unk_0E = b;
            args.slot = slot;
            args.unk_0F = w->unk_9C[b];

            if (slot->cardId == 0xFFFE) {
                q = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                q = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            q->unk_80 = q->unk_7C = gUnk_09033FA8[3];
            q->unk_98 = q->unk_94 = gUnk_09033FB8[0];
            q->unk_A4 = 3;
            q->unk_A0 = 60;
            q->unk_78 |= 0x800;
        }
    }

    p = (CardDisplayWork*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        p->unk_A4++;

        if (p->unk_A4 > 3) {
            p->unk_A4 = 0;
        }

        p->unk_A0 += 4;
        p->unk_80 = gUnk_09033FA8[p->unk_A4];
        p->unk_9C = c;
        p = (CardDisplayWork*)ListPoolNext(&p->node);
    }

    gUnk_02034A98->unk_A0 = 50;
}
void func_08078FFC(UnkStruct_08080268* w, u8 b) {
    UnkStruct_0807FD10_Args args;
    CardDisplayWork* p;
    CardDisplayWork* q;
    CardSlot* c;
    s16 prev;
    s32 v;
    s32 cur;
    u16 n;

    m4aSongNumStart(SONG_SYS_CLICKI04B);
    gUnk_02034A98->unk_78 &= ~4;
    prev = gUnk_02034A98->unk_44;
    p = (CardDisplayWork*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        if (p->unk_A4 == 2) {
            gUnk_02034A98 = p;
            break;
        }

        p = (CardDisplayWork*)ListPoolNext(&p->node);
    }

    gUnk_02034A98->unk_78 |= 0x804;
    cur = (s16)gUnk_02034A98->unk_44;
    n = cur + 1;

    if ((s16)n >= (s16)w->unk_A8[b]) {
        n = 0;
    }

    c = func_08076674(w, b, &n);

    if (c != 0) {
        v = (s16)n;

        if (v != cur && v != prev) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = n;
            args.unk_0E = b;
            args.slot = c;
            args.unk_0F = w->unk_9C[b];

            if (c->cardId == 0xFFFE) {
                q = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                q = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            q->unk_80 = q->unk_7C = gUnk_09033FA8[3];
            q->unk_98 = q->unk_94 = gUnk_09033FB8[0];
            q->unk_A4 = 3;
            q->unk_A0 = 60;
            q->unk_78 |= 0x800;
        }
    }

    p = (CardDisplayWork*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        p->unk_A4--;

        if (p->unk_A4 < 0) {
            p->unk_A4 = 3;
        }

        p->unk_A0 += 4;
        p->unk_80 = gUnk_09033FA8[p->unk_A4];
        p->unk_9C = 4;
        p = (CardDisplayWork*)ListPoolNext(&p->node);
    }

    gUnk_02034A98->unk_A0 = 50;
}

void func_080791C0(UnkStruct_08080268* w) {
    if (gBtlWork->flags & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 0x30) {
            if (gUnk_02034A98->unk_A5 != 0) {
                gUnk_02034A98->unk_A5 -= gUnk_02039DD4->unk_0C2;
            }

            gUnk_02039B9C->unk_0F8--;
        }
    }
}

void func_08079218(UnkStruct_08080268* w) {
    u8 dmg = gUnk_02039DD4->unk_0C2;
    u8 i;

    if (gBtlWork->flags & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 0x30) {
            if (w->unk_BA != 0) {
                for (i = 0; i < w->unk_B9; i++) {
                    CardDisplayWork* c = w->unk_28[i];
                    s32 t;

                    if (c->unk_A5 > dmg) {
                        c->unk_A5 -= dmg;
                        break;
                    }

                    t = dmg - c->unk_A5;
                    c->unk_A5 = 0;
                    dmg = t;
                }
            }

            gUnk_02039B9C->unk_0F8--;
        }
    }
}

u16 func_080792AC(void) {
    u16 i;

    i = GetRandom() % 47;

    return gUnk_09EE48F4[i];
}

u16 func_080792D0(u16* p) {
    u16 v;
    u16 i;

    i = *p;
    v = gUnk_09EE48F4[i];
    *p = i + 1;

    if (*p > 46) {
        *p = 0;
    }

    return v;
}

void func_080792F4(UnkStruct_08080268* w) {
    s8 n;
    u8 skip;
    u8 i;
#ifdef VERSION_EU
    s32 j;
    s32 k;
#endif

    if (gBtlWork->unk_0F4 == 1) {
        n = gUnk_02034A98->unk_A5 + 1;

        if (n > 9) {
            n = 9;
        }

        if (gUnk_02034A98->unk_A5 < 9) {
            TaskCreate(&gUnk_02039DD4->tasks, &gTaskDescNumberPlus, &gUnk_02034A98->cardDef);
        }

        gUnk_02034A98->unk_A5 = n;
        gUnk_02034A98->unk_A7 = 1;
    } else if (gBtlWork->unk_0F4 == 21) {
        if (gUnk_02034A98->unk_A5 != 0) {
            n = gUnk_02034A98->unk_A5 - 1;
            gUnk_02034A98->unk_A5--;
            gUnk_02034A98->unk_A7 = 1;
        } else {
            n = 0;
            gUnk_02034A98->unk_A7 = 1;
        }
    } else {
        n = gUnk_02034A98->unk_A5;
    }

    if ((s16)gUnk_02039DD4->unk_0C2 > n && n != 0) {
        return;
    }

    skip = 0;

    if (gBtlWork->flags & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 2 && gUnk_02039DD4->unk_000[0]->cardDef->unk_2A == 0 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

#ifdef VERSION_EU
        if (gUnk_02039B9C->unk_0F4 == 20) {
            for (j = 0; j < gUnk_02039DD4->unk_0D0; j++) {
                if (gUnk_02039DD4->unk_000[j]->cardDef->unk_24 == 22) {
                    skip = 1;
                }
            }
        }

        if (gUnk_02039B9C->unk_0F4 == 29) {
            for (k = 0; k < gUnk_02039DD4->unk_0D0; k++) {
                if (gUnk_02039DD4->unk_000[k]->cardDef->unk_2A == 2 &&
                    !(gUnk_02039DD4->unk_000[k]->cardDef->flags & 8)) {
                    skip = 1;
                }
            }
        }
#else
        if (gUnk_02039B9C->unk_0F4 == 20 && gUnk_02039DD4->unk_000[0]->cardDef->unk_24 == 22 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

        if (gUnk_02039B9C->unk_0F4 == 29 && gUnk_02039DD4->unk_000[0]->cardDef->unk_2A == 2 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }
#endif
    }

    if (skip != 0) {
        return;
    }

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
    }

    gBtlWork->flags |= 0x800000;

    if ((s16)gUnk_02039DD4->unk_0C2 != n) {
        if (n == 0) {
            if ((s16)gUnk_02039DD4->unk_0C2 > 9) {
                gBtlWork->unk_1CA = 9;
            } else {
                gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2;
            }
        } else if (n - (s16)gUnk_02039DD4->unk_0C2 > 9) {
            gBtlWork->unk_1CA = 9;
        } else {
            gBtlWork->unk_1CA = n - (s16)gUnk_02039DD4->unk_0C2;
        }

        m4aSongNumStart(SONG_BTL_GARD);
        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x80;
        gBtlWork->flags &= ~0x20;
        gUnk_02034A98->unk_78 |= 0x2000;
        func_080791C0(w);
        gUnk_02039DD4->unk_000[0] = gUnk_02034A98;
        gUnk_02039DD4->unk_0D0 = 1;
        gUnk_02039DD4->unk_0C2 = gUnk_02034A98->unk_A5;
        gBtlWork->unk_0A4 = 1;

        if (!(gGameState.flags & 0x100) && func_0807BA54() != 0 && !(gBtlWork->flags & 0x800000000000)) {
            gUnk_02039DD4->unk_0EE = 1;
        }
    } else {
        func_080791C0(w);
        gBtlWork->unk_1CA = 0;
        gBtlWork->flags &= ~0x80;
        gBtlWork->flags &= ~0x20;
        gBtlWork->flags &= ~0x400;
        m4aSongNumStart(SONG_SYS_DROW);
        gBtlWork->unk_0A4 = 1;
        gUnk_02039DD4->unk_000[0] = gUnk_02034A98;
        gUnk_02039DD4->unk_0D0 = 1;
        gUnk_02039DD4->unk_0C2 = gUnk_02034A98->unk_A5;
    }
}

extern BtlWork* gUnk_02039B84 __asm__("gBtlWork");

s32 func_08079600(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    u16 id;
    CardDisplayWork* e;
    CardSlot* c;
    u8 found;
    u32 prev;
    u32 other;
    BtlWork* b;
    u64 flags;

    b = gUnk_02039B84;
    flags = b->flags;
    if ((flags & 0x80) == 0) {
        gUnk_02039DD4->unk_000[0] = gUnk_02034A98;
        if (b->unk_0F4 == 1) {
            gUnk_02039DD4->unk_0C2 = gUnk_02034A98->unk_A5 + 1;
            if (gUnk_02034A98->unk_A5 < 9) {
                TaskCreate(&gUnk_02039DD4->tasks, &gTaskDescNumberPlus, &gUnk_02034A98->cardDef);
            }
            gUnk_02034A98->unk_A5++;
            if (gUnk_02034A98->unk_A5 > 9) {
                gUnk_02034A98->unk_A5 = 9;
            }
            if ((s16)gUnk_02039DD4->unk_0C2 > 9) {
                gUnk_02039DD4->unk_0C2 = 9;
            }
            gUnk_02034A98->unk_A7 = 1;
        } else if (b->unk_0F4 == 21) {
            if (gUnk_02034A98->unk_A5 != 0) {
                gUnk_02034A98->unk_A5--;
                gUnk_02034A98->unk_A7 = 1;
                gUnk_02039DD4->unk_0C2 = gUnk_02034A98->unk_A5;
            } else {
                gUnk_02034A98->unk_A7 = 1;
                gUnk_02039DD4->unk_0C2 = 0;
            }
        } else {
            gUnk_02039DD4->unk_0C2 = gUnk_02034A98->unk_A5;
        }
        gUnk_02039DD4->unk_0D0 = 1;
        gUnk_02034A98->unk_78 |= 0x2000;
        gBtlWork->unk_0A4 = 1;
        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x80;
        gBtlWork->flags |= 0x8000000;
    } else {
        if (b->unk_0A4 == 1) {
            return 1;
        }
        if ((flags & 0x20) == 0) {
            func_080792F4(w);
        } else {
            func_080792F4(w);
        }
        gBtlWork->flags |= 0x8000000;
    }
    w->unk_B0[w->unk_B8]--;
    if (w->unk_B0[w->unk_B8] == 1) {
        gUnk_02034A98->slot->unk_0B = 1;
    }
    if ((gUnk_02034A98->cardDef->flags & 2) && (gUnk_02034A98->unk_78 & 0x2000)) {
        gUnk_02034A98->slot->unk_0A = 1;
    }
    if (gUnk_02034A98->cardDef->flags & 8) {
        gUnk_02034A98->slot->unk_0A = 1;
    }
    if (gUnk_02034A98->unk_A6 == 1) {
        gUnk_02034A98->slot->unk_0A = 1;
        if ((u16)func_0807885C((UnkStruct_08078754*)w, 0) == 0) {
            gUnk_02034A98->slot->unk_0A = 0;
        }
    }
    w->unk_1C[0] = gUnk_02034A98;
    gUnk_02034A98->unk_A1 = 5;
    gUnk_02034A98->unk_A0 = 50;
    gUnk_02034A98->slot->unk_08 = 1;
    gUnk_02034A98->unk_78 &= ~0x40;
    func_0807BC08();
    if (gBtlWork->unk_0F4 == 37) {
        u16 v = func_080792AC();
        func_0807B45C(w);
        gUnk_02039DD4->unk_0CC = v;
        func_0807B458(w, gUnk_02039DD4->unk_0CC);
        func_0807B478(w);
        gBtlWork->unk_0F8 = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E;
    }
    other = 0xFF;
    id = other;
    found = 0;
    gUnk_02034A98 = 0;

    e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

    while (e != 0) {
        if (e->unk_A4 == 2) {
            e->unk_A4--;
            e->unk_9C = 4;
            e->unk_80 = gUnk_09033FA8[e->unk_A4];
            e->unk_A0 = 50;
            gUnk_02034A98 = e;
            found = 1;
            break;
        }

        e = (CardDisplayWork*)ListPoolNext(&e->node);
    }

    if (gUnk_02034A98 == 0) {
        e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (e != 0) {
            if (e->unk_A4 == 0) {
                e->unk_A4++;
                e->unk_9C = 4;
                e->unk_80 = gUnk_09033FA8[e->unk_A4];
                e->unk_A0 = 50;
                gUnk_02034A98 = e;
                break;
            }

            e = (CardDisplayWork*)ListPoolNext(&e->node);
        }
    }

    if (found) {
        prev = gUnk_02034A98->unk_44;
        id = prev + 1;

        if (id >= (s16)w->unk_A8[w->unk_B8]) {
            id = 0;
        }

        for (e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]); e != 0; e = (CardDisplayWork*)ListPoolNext(&e->node)) {
            if (e->unk_A4 == 0) {
                other = e->unk_44;
                break;
            }
        }

        c = func_08076674(w, w->unk_B8, &id);

        if (c != 0 && id != prev && id != other) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = id;
            args.unk_0E = w->unk_B8;
            args.slot = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->cardId == 0xFFFE) {
                e = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                e = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            e->unk_7C = gUnk_09033FA8[3];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 2;
            e->unk_80 = gUnk_09033FA8[2];
            e->unk_A0 = 60;
            e->unk_9C = 4;
            e->unk_78 |= 0x800;
        }
    }

    gUnk_02034A98->unk_78 |= 4;
    if (gBtlWork->unk_0F4 == 40 && (gUnk_02034A98->unk_78 & 0x100000) && w->unk_B0[w->unk_B8] == 1) {
        func_0807A620(w);
        gUnk_02034A98 = 0;
        gBtlWork->flags |= 0x80000000;
        w->unk_B0[0] = 0;
        w->unk_C0[0] = 1;
        m4aSongNumStart(SONG_SYS_CHAGEF2);
        if ((u16)FadeGetAmount() == 0) {
            FadeFromAmount(2, 16, 20);
        }
    }
    return 1;
}

s32 func_08079B3C(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    u16 id;
    CardDisplayWork* e;
    CardSlot* c;
    u8 found;
    u32 prev;
    u32 other;

    if (gUnk_02034A98->unk_78 & 2) {
        return 1;
    }

    m4aSongNumStart(SONG_SYS_CLICKI04);

    if (gUnk_02039DD4->unk_0CC == 0) {
        gUnk_02039DD4->unk_0CC = gUnk_02034A98->cardDef->unk_24;
        func_0807B458(w, gUnk_02039DD4->unk_0CC);
        func_0807B478((void*)w);
    } else {
        func_0807B45C(w);
        gUnk_02039DD4->unk_0CC = gUnk_02034A98->cardDef->unk_24;
        func_0807B458(w, gUnk_02039DD4->unk_0CC);
        func_0807B478((void*)w);
        gUnk_02039DD4->unk_0EB = 1;
    }
    gUnk_02034A98->slot->unk_0A = 1;
    gUnk_02034A98->unk_A1 = 10;
    gUnk_02034A98->slot->unk_08 = 1;
    gUnk_02034A98->unk_A0 = 50;
    gUnk_02034A98->unk_78 &= ~0x40;
    if (w->unk_BA != 0) {
        UpdateSpriteFrameTiles(w->tiles, gUnk_09EF12E8[0], (void*)((u32)gUnk_093FBAB8 + ((w->unk_BA - 1) << 7)));
        w->unk_C4[3] = 8;
    }

    w->unk_B0[w->unk_B8]--;
    other = 0xFF;
    id = other;
    found = 0;
    gUnk_02034A98 = 0;

    e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

    while (e != 0) {
        if (e->unk_A4 == 2) {
            e->unk_A4--;
            e->unk_9C = 4;
            e->unk_80 = gUnk_09033FA8[e->unk_A4];
            e->unk_A0 = 50;
            gUnk_02034A98 = e;
            found = 1;
            break;
        }

        e = (CardDisplayWork*)ListPoolNext(&e->node);
    }

    if (gUnk_02034A98 == 0) {
        e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (e != 0) {
            if (e->unk_A4 == 0) {
                e->unk_A4++;
                e->unk_9C = 4;
                e->unk_80 = gUnk_09033FA8[e->unk_A4];
                e->unk_A0 = 50;
                gUnk_02034A98 = e;
                break;
            }

            e = (CardDisplayWork*)ListPoolNext(&e->node);
        }
    }

    if (gUnk_02034A98 == 0) {
        args.unk_00 = &w->unk_54[w->unk_B8];
        args.unk_0C = 0xFFFF;
        args.slot = (CardSlot*)w->unk_44[w->unk_B8];
        args.unk_0E = w->unk_B8;
        e = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardNotHave, &args))[1];
        e->unk_80 = e->unk_7C = gUnk_09033FA8[1];
        e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
        e->unk_A0 = 50;
        e->unk_78 |= 0x806;
        gUnk_02034A98 = e;
        return 0;
    }

    if (found) {
        prev = gUnk_02034A98->unk_44;
        id = prev + 1;

        if (id >= (s16)w->unk_A8[w->unk_B8]) {
            id = 0;
        }

        for (e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]); e != 0; e = (CardDisplayWork*)ListPoolNext(&e->node)) {
            if (e->unk_A4 == 0) {
                other = e->unk_44;
                break;
            }
        }

        c = func_08076674(w, w->unk_B8, &id);

        if (c != 0 && id != prev && id != other) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = id;
            args.unk_0E = w->unk_B8;
            args.slot = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->cardId == 0xFFFE) {
                e = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                e = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            e->unk_7C = gUnk_09033FA8[3];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 2;
            e->unk_80 = gUnk_09033FA8[2];
            e->unk_A0 = 60;
            e->unk_9C = 4;
            e->unk_78 |= 0x800;
        }
    }

    gUnk_02034A98->unk_78 |= 4;
    return 1;
}
s32 func_08079ECC(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    u16 id;
    CardDisplayWork* e;
    CardSlot* c;
    u8 found;
    u32 prev;
    u32 other;

    if (gUnk_02034A98->unk_78 & 2) {
        return 1;
    }

    gBtlWork->flags |= 0x20000000000000;
    m4aSongNumStart(SONG_SYS_CLICKI04);
    gUnk_02034A98->slot->unk_0A = 1;
    gUnk_02034A98->unk_A1 = 11;
    gUnk_02034A98->slot->unk_08 = 1;
    gUnk_02034A98->unk_A0 = 50;
    gUnk_02034A98->unk_78 &= ~0x40;
    w->unk_B0[w->unk_B8]--;
    other = 0xFF;
    id = other;
    found = 0;
    gUnk_02034A98 = 0;

    e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

    while (e != 0) {
        if (e->unk_A4 == 2) {
            e->unk_A4--;
            e->unk_9C = 4;
            e->unk_80 = gUnk_09033FA8[e->unk_A4];
            e->unk_A0 = 50;
            gUnk_02034A98 = e;
            found = 1;
            break;
        }

        e = (CardDisplayWork*)ListPoolNext(&e->node);
    }

    if (gUnk_02034A98 == 0) {
        e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (e != 0) {
            if (e->unk_A4 == 0) {
                e->unk_A4++;
                e->unk_9C = 4;
                e->unk_80 = gUnk_09033FA8[e->unk_A4];
                e->unk_A0 = 50;
                gUnk_02034A98 = e;
                break;
            }

            e = (CardDisplayWork*)ListPoolNext(&e->node);
        }
    }

    if (found) {
        prev = gUnk_02034A98->unk_44;
        id = prev + 1;

        if (id >= (s16)w->unk_A8[w->unk_B8]) {
            id = 0;
        }

        for (e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]); e != 0; e = (CardDisplayWork*)ListPoolNext(&e->node)) {
            if (e->unk_A4 == 0) {
                other = e->unk_44;
                break;
            }
        }

        c = func_08076674(w, w->unk_B8, &id);

        if (c != 0 && id != prev && id != other) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = id;
            args.unk_0E = w->unk_B8;
            args.slot = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->cardId == 0xFFFE) {
                e = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                e = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            e->unk_7C = gUnk_09033FA8[3];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 2;
            e->unk_80 = gUnk_09033FA8[2];
            e->unk_A0 = 60;
            e->unk_9C = 4;
            e->unk_78 |= 0x800;
        }
    }

    gUnk_02034A98->unk_78 |= 4;
    gUnk_02039DD4->unk_0DC--;
    return 1;
}
s32 func_0807A188(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    u16 id;
    CardDisplayWork* e;
    CardSlot* c;
    u8 found;
    u32 prev;
    u32 other;
    u8 n;
    u32 active;

    if (!(gUnk_02034A98->unk_78 & 0x40)) {
        return 1;
    }
    if ((u16)(gUnk_02034A98->cardDef->flags & 0x10)) {
        m4aSongNumStart(SONG_SYS_BEEP);
        return 1;
    }
    if (gUnk_02039DD4->unk_0B4 == 112 || gUnk_02039DD4->unk_0B4 == 109) {
        return 1;
    }
    w->unk_C4[1] = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    m4aSongNumStart(SONG_SYS_KETEI2);
    gUnk_02034A98->unk_78 &= ~0x40;
    gUnk_02034A98->unk_78 |= 0x200;
    gUnk_02034A98->unk_A1 = 6;
    gUnk_02034A98->unk_9F = w->unk_B9;
    gUnk_02034A98->unk_A0 = 50 - (3 - w->unk_B9) * 4;
    w->unk_28[w->unk_B9] = gUnk_02034A98;
    gUnk_02039DD4->unk_018[gUnk_02039DD4->unk_0DE] = gUnk_02034A98;
    gUnk_02034A98->slot->unk_07 = active = 1;
    gUnk_02034A98->slot->unk_08 = active;
    if (gBtlWork->unk_0F4 == 1) {
        n = gUnk_02034A98->unk_A5 + 1;
        if (n > 9) {
            n = 9;
        }
        gUnk_02034A98->unk_A7 = active;
        gUnk_02034A98->unk_A5 = n;
        if (gUnk_02034A98->unk_A5 < 9) {
            TaskCreate(&gUnk_02039DD4->tasks, &gTaskDescNumberPlus, &gUnk_02034A98->cardDef);
        }
    } else if (gBtlWork->unk_0F4 == 21) {
        if (gUnk_02034A98->unk_A5 != 0) {
            n = gUnk_02034A98->unk_A5 - 1;
            gUnk_02034A98->unk_A5--;
            gUnk_02034A98->unk_A7 = active;
        } else {
            n = 0;
            gUnk_02034A98->unk_A7 = active;
        }
    } else {
        n = gUnk_02034A98->unk_A5;
    }
    w->unk_BA += n;
    w->unk_B9++;
    gUnk_02039DD4->unk_0DE++;
    if (w->unk_BA != 0) {
        UpdateSpriteFrameTiles(w->tiles, gUnk_09EF12E8[0], (void*)((u32)gUnk_093FBAB8 + ((w->unk_BA - 1) << 7)));
        w->unk_C4[3] = 8;
    }
    w->unk_B0[w->unk_B8]--;
    if (gUnk_02034A98->cardDef->flags & 8) {
        gUnk_02034A98->slot->unk_0A = 1;
    }
    if (gBtlWork->unk_0F4 == 37) {
        u16 v = func_080792AC();
        func_0807B45C(w);
        gUnk_02039DD4->unk_0CC = v;
        func_0807B458(w, gUnk_02039DD4->unk_0CC);
        func_0807B478(w);
        gBtlWork->unk_0F8 = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E;
    }
    other = 0xFF;
    id = other;
    found = 0;
    gUnk_02034A98 = 0;

    e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

    while (e != 0) {
        if (e->unk_A4 == 2) {
            e->unk_A4--;
            e->unk_9C = 4;
            e->unk_80 = gUnk_09033FA8[e->unk_A4];
            e->unk_A0 = 50;
            gUnk_02034A98 = e;
            found = 1;
            break;
        }

        e = (CardDisplayWork*)ListPoolNext(&e->node);
    }

    if (gUnk_02034A98 == 0) {
        e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (e != 0) {
            if (e->unk_A4 == 0) {
                e->unk_A4++;
                e->unk_9C = 4;
                e->unk_80 = gUnk_09033FA8[e->unk_A4];
                e->unk_A0 = 50;
                gUnk_02034A98 = e;
                break;
            }

            e = (CardDisplayWork*)ListPoolNext(&e->node);
        }
    }

    if (found) {
        prev = gUnk_02034A98->unk_44;
        id = prev + 1;

        if (id >= (s16)w->unk_A8[w->unk_B8]) {
            id = 0;
        }

        for (e = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]); e != 0; e = (CardDisplayWork*)ListPoolNext(&e->node)) {
            if (e->unk_A4 == 0) {
                other = e->unk_44;
                break;
            }
        }

        c = func_08076674(w, w->unk_B8, &id);

        if (c != 0 && id != prev && id != other) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = id;
            args.unk_0E = w->unk_B8;
            args.slot = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->cardId == 0xFFFE) {
                e = ((CardDisplayWork**)TaskCreate(w, &gTaskDescCardReload, &args))[1];
            } else {
                e = ((CardDisplayWork**)TaskCreate(w, &gUnk_09EE496C, &args))[1];
            }

            e->unk_7C = gUnk_09033FA8[3];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 2;
            e->unk_80 = gUnk_09033FA8[2];
            e->unk_A0 = 60;
            e->unk_9C = 4;
            e->unk_78 |= 0x800;
        }
    }

    gUnk_02034A98->unk_78 |= 4;
    if (gBtlWork->unk_0F4 == 40 && (gUnk_02034A98->unk_78 & 0x100000) && w->unk_B0[w->unk_B8] == 1) {
        func_0807A620(w);
        gUnk_02034A98 = 0;
        w->unk_B0[0] = 0;
        w->unk_C0[0] = 1;
        m4aSongNumStart(SONG_SYS_CHAGEF2);
        if ((u16)FadeGetAmount() == 0) {
            FadeFromAmount(2, 16, 20);
        }
    }
    return 1;
}

void func_0807A620(u8* work) {
    CardDisplayWork* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (CardDisplayWork*)ListPoolFirst(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 < 5 || node->unk_A1 > 6) {
                node->unk_A1 = 7;
            }

            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }
    }

    if (gUnk_02034A98->unk_78 & 0x1000000) {
        gUnk_02034A98->unk_78 |= 0x4000;
    }
}

void func_0807A684(u8* work) {
    CardDisplayWork* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (CardDisplayWork*)ListPoolFirst(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 == 0) {
                node->unk_A1 = 7;
            }

            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }
    }
}

void func_0807A6C8(UnkStruct_08080268* w) {
    CardDisplayWork* node;
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 |= 0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[i]);

        while (node != 0) {
            node->unk_78 |= 0x20;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }
    }

    gBtlWork->flags &= ~0x20;
    gUnk_02039DD4->unk_0EA = 1;
    w->unk_C9 = 0;
}

void func_0807A75C(UnkStruct_08080268* w) {
    CardDisplayWork* node;
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 &= ~0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[i]);

        while (node != 0) {
            node->unk_78 &= ~0x20;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }
    }

    gUnk_02039DD4->unk_0CC = 0;
    gBtlWork->flags |= 0x20;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    w->unk_C9 = 1;
}

void func_0807A80C(UnkStruct_08080268* w) {
#ifdef VERSION_EU
    CardDisplayWork* previous[3];
#endif
    UnkStruct_080ABA80 arr;
    u8 flag;
    u16 total;
    u8 i;
    u8 n;
    u8 skip;
    s32 r;
    CardDisplayWork** q;
#ifdef VERSION_EU
    u8 previousCount;
    s32 j;
    s32 k;
#endif

    n = w->unk_BA;
    total = 0;
    arr = gUnk_09033FD0;

    if ((s16)gUnk_02039DD4->unk_0C2 > n && n != 0) {
        return;
    }

    skip = 0;

    if (gBtlWork->flags & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 2 && gUnk_02039DD4->unk_000[0]->cardDef->unk_2A == 0 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

#ifdef VERSION_EU
        if (gUnk_02039B9C->unk_0F4 == 20) {
            for (j = 0; j < gUnk_02039DD4->unk_0D0; j++) {
                if (gUnk_02039DD4->unk_000[j]->cardDef->unk_24 == 22) {
                    skip = 1;
                }
            }
        }

        if (gUnk_02039B9C->unk_0F4 == 29) {
            for (k = 0; k < gUnk_02039DD4->unk_0D0; k++) {
                if (gUnk_02039DD4->unk_000[k]->cardDef->unk_2A == 2 &&
                    !(gUnk_02039DD4->unk_000[k]->cardDef->flags & 8)) {
                    skip = 1;
                }
            }
        }
#else
        if (gUnk_02039B9C->unk_0F4 == 20 && gUnk_02039DD4->unk_000[0]->cardDef->unk_24 == 22 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

        if (gUnk_02039B9C->unk_0F4 == 29 && gUnk_02039DD4->unk_000[0]->cardDef->unk_2A == 2 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }
#endif
    }

    if (skip != 0) {
        return;
    }

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
    }

    gBtlWork->flags |= 0x800000;

    if ((s16)gUnk_02039DD4->unk_0C2 != n) {
        if (n == 0) {
            if ((s16)gUnk_02039DD4->unk_0C2 > 9) {
                gBtlWork->unk_1CA = 9;
            } else {
                gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2;
            }
        } else {
            if (n - (s16)gUnk_02039DD4->unk_0C2 > 9) {
                gBtlWork->unk_1CA = 9;
            } else {
                gBtlWork->unk_1CA = n - *(u8*)&gUnk_02039DD4->unk_0C2;
            }
        }

        if (!(gGameState.flags & 0x100) && func_0807BA54() != 0 && !(gBtlWork->flags & 0x800000000000)) {
            gUnk_02039DD4->unk_0EE = 1;
        }

        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x8000000;
        gBtlWork->flags |= 0x80;
        gBtlWork->flags &= ~0x20;
        func_08079218(w);

#ifndef VERSION_EU
        if (!(gBtlWork->flags & 0x4000)) {
            r = func_080AC5E8(&w->unk_28, w->unk_B9, w->unk_BA, &arr, &flag);
        } else {
            r = func_080AD144(&w->unk_28, w->unk_B9, w->unk_BA, &arr, &flag, 0);
        }

        if ((u16)r == 52 && (gBtlWork->flags & 0x4800)) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->slot->unk_08 == 1) {
                    gUnk_02039DD4->unk_000[i]->slot->unk_0A = 1;
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x80000000;
                }
            }
        }
#endif

        for (i = 0; i < w->unk_B9; i++) {
            total += w->unk_28[i]->unk_A5;
        }

        gUnk_02039DD4->unk_0C2 = total;
#ifdef VERSION_EU
        previousCount = gUnk_02039DD4->unk_0D0;
#endif
        gUnk_02039DD4->unk_0D0 = w->unk_B9;

        for (i = 0; i < w->unk_B9; i++) {
#ifdef VERSION_EU
            previous[i] = gUnk_02039DD4->unk_000[i];
#endif
            q = gUnk_02039DD4->unk_000;
            q += i;
            *q = w->unk_28[i];
            w->unk_28[i]->unk_78 |= 0x2000;

            if (w->unk_28[i]->cardDef->flags & 2) {
                w->unk_28[i]->slot->unk_0A = 1;
            }
        }

        gBtlWork->unk_0A4 = 1;
        gUnk_02039DD4->unk_0E1 = 1;
        m4aSongNumStart(SONG_BTL_GARD);

#ifdef VERSION_EU
        if (!(gBtlWork->flags & 0x4000)) {
            r = func_080AC5E8(&w->unk_28, w->unk_B9, w->unk_BA, &arr, &flag);
        } else {
            r = func_080AD144(&w->unk_28, w->unk_B9, w->unk_BA, &arr, &flag, 0);
        }

        if ((u16)r == 52 && (gBtlWork->flags & 0x4800)) {
            for (i = 0; i < previousCount; i++) {
                if (previous[i]->slot->unk_08 == 1) {
                    previous[i]->slot->unk_0A = 1;
                    previous[i]->unk_78 |= 0x80000000;
                }
            }
        }
#endif
        return;
    }

    gBtlWork->unk_1CA = 0;
    func_08079218(w);
    m4aSongNumStart(SONG_SYS_DROW);
    gBtlWork->flags &= ~0x80;
    gBtlWork->flags &= ~0x20;
    gBtlWork->flags &= ~0x400;
    gUnk_02039DD4->unk_0E1 = 0;
    gBtlWork->unk_0A4 = 1;
}

void func_0807ABC8(UnkStruct_08080268* w) {
    CardDisplayWork** q;
    CardDisplayWork* p;
    u64 flags;
    u8 i;
    u8 n;

    for (i = 0, n = 0; i < w->unk_B9; i++) {
        if (w->unk_28[i]->unk_78 & 0x40) {
            n++;
        }
    }

    if (n < w->unk_B9) {
        return;
    }

    gUnk_02039DD4->unk_0C0 = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    w->unk_C4[1] = 0;
    flags = gBtlWork->flags;

    if ((flags & 0x80) == 0) {
        gUnk_02039DD4->unk_0D0 = w->unk_B9;

        for (i = 0; i < w->unk_B9; i++) {
            q = gUnk_02039DD4->unk_000;
            q += i;
            *q = w->unk_28[i];
            w->unk_28[i]->unk_A0 = i * 4 + 50;

            if (w->unk_28[i]->cardDef->flags & 2) {
                w->unk_28[i]->slot->unk_0A = 1;
            }

            w->unk_28[i]->unk_78 |= 0xA000;
        }

        gUnk_02039DD4->unk_0C2 = w->unk_BA;
        gBtlWork->unk_0A4 = 1;
        gBtlWork->flags |= 0x80;
        gBtlWork->flags |= 0x400;
        gBtlWork->flags |= 0x8000000;
        gUnk_02039DD4->unk_0E1 = 1;
    } else {
        if (gBtlWork->unk_0A4 == 1) {
            return;
        }

        if ((flags & 0x20) == 0) {
            func_0807A80C(w);
            gBtlWork->flags |= 0x8000000;
        } else {
            func_0807A80C(w);
            gBtlWork->flags |= 0x8000000;
        }
    }

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->slot->unk_07 = 0;

        if (w->unk_28[i]->cardDef->flags & 2) {
            w->unk_28[i]->slot->unk_0A = 1;
        } else if (i == 0 && gBtlWork->unk_0F4 != 15) {
            w->unk_28[0]->slot->unk_0A = 1;
        }
    }

    if (func_0807885C((UnkStruct_08078754*)w, 0) == 0) {
        for (i = 0; i < w->unk_B9; i++) {
            if (w->unk_28[i]->unk_46 == 0) {
                w->unk_28[i]->slot->unk_0A = 0;
                break;
            }
        }
    }

    i = 0;

    if (i < w->unk_B9) {
        do {
            p = 0;
            n = i;
            w->unk_1C[n] = w->unk_28[n];
            w->unk_28[n]->unk_A1 = 5;
            w->unk_28[n] = p;
            i = ++n;
        } while (i < w->unk_B9);
    }

    func_0807BC08();
    w->unk_B9 = 0;
    gUnk_02039DD4->unk_0DE = 0;
    w->unk_BA = 0;
    func_0807AE78((UnkStruct_08078754*)w);
    w->unk_C4[1] = 0;
}

void func_0807AE78(UnkStruct_08078754* w) {
    CardSlot* c;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++) {
        c = w->slots[i];

        for (j = 0; j < w->unk_A8[j]; j++) {
            c[j].unk_07 = 0;
        }
    }
}

u8 func_0807AEC4(u8* work, u8 n) {
    CardDisplayWork* node;
    u8 count;

    count = 0;
    node = (CardDisplayWork*)ListPoolFirst(&work[n * 16 + 0x54]);

    while (node != 0) {
        count++;
        node = (CardDisplayWork*)ListPoolNext(&node->node);
    }

    return count;
}

u8 func_0807AEF4(u8* work, u8 kind) {
    CardDisplayWork* node;
    u8 count;

    count = 0;
    node = (CardDisplayWork*)ListPoolFirst(&work[kind * 16 + 0x54]);

    while (node != 0) {
        if ((node->unk_78 & 0x1000002) == 0) {
            if (kind == 2) {
                count++;
            } else if (node->cardDef->unk_2A == kind) {
                count++;
            }
        }

        node = (CardDisplayWork*)ListPoolNext(&node->node);
    }

    return count;
}

void func_0807AF40(UnkStruct_08080268* w) {
    CardDisplayWork* node = 0;

    if (!(gUnk_02034A98->unk_78 & 0x40)) {
        return;
    }

    m4aSongNumStart(SONG_SYS_CANSEL);

    if (gBtlWork->flags & 0x1000000) {
        gBtlWork->flags &= ~0x1000000;
    }

    w->unk_BC[w->unk_B8] = 0;

    if (w->unk_C0[w->unk_B8] == 0) {
        w->unk_94[w->unk_B8] = gUnk_02034A98->unk_44;
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_A3 = 4;
            node->unk_98 = gUnk_09033FB8[3];
            node->unk_A1 = 7;
            node->unk_78 &= ~4;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }
    } else {
        w->unk_34[w->unk_B8] = gUnk_02034A98;
        gUnk_02034A98->unk_98 = gUnk_09033FB8[3];
        gUnk_02034A98->unk_A3 = 4;
        gUnk_02034A98->unk_78 &= ~4;
    }

    switch (w->unk_B8) {
    case 0:
        w->unk_B8 = 3;
        break;
    case 3:
        w->unk_B8 = 0;
        break;
    }

    if (w->unk_C0[w->unk_B8] == 0) {
        func_0807682C(w, (u8)w->unk_B8);
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_98 = gUnk_09033FB8[0];
            node->unk_94 = gUnk_09033FB8[0];
            node->unk_A3 = 1;
            node->unk_9C = 1;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }

        if (w->unk_BC[w->unk_B8] == 0) {
            if (w->unk_B8 != 0) {
                if (w->unk_B0[w->unk_B8] > 0) {
                    CreateREVCOUNTTask(w, &w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
                }
            } else {
                if (w->unk_B0[w->unk_B8] > 1) {
                    CreateREVCOUNTTask(w, &w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
                }
            }
        }
    } else {
        gUnk_02034A98 = w->unk_34[w->unk_B8];
        gUnk_02034A98->unk_98 = gUnk_09033FB8[0];
        gUnk_02034A98->unk_94 = gUnk_09033FB8[1];
        gUnk_02034A98->unk_A3 = 1;
        gUnk_02034A98->unk_9C = 1;
        gUnk_02034A98->unk_78 |= 4;
    }

    gUnk_02039DD4->unk_0D2 = w->unk_B8;
}

void func_0807B16C(UnkStruct_08080268* w) {
    CardDisplayWork* node = 0;

    m4aSongNumStart(SONG_SYS_CANSEL);

    if (gBtlWork->flags & 0x1000000) {
        gBtlWork->flags &= ~0x1000000;
    }

    w->unk_BC[w->unk_B8] = 0;

    if (w->unk_C0[w->unk_B8] == 0) {
        w->unk_94[w->unk_B8] = gUnk_02034A98->unk_44;
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_A3 = 12;
            node->unk_98 = gUnk_09033FB8[1];
            node->unk_A1 = 7;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }
    } else {
        w->unk_34[w->unk_B8] = gUnk_02034A98;
        gUnk_02034A98->unk_98 = gUnk_09033FB8[3];
        gUnk_02034A98->unk_A3 = 12;
        gUnk_02034A98->unk_78 &= ~4;
    }

    switch (w->unk_B8) {
    case 0:
        w->unk_B8 = 2;
        break;
    case 1:
        w->unk_B8 = 0;
        break;
    case 2:
        w->unk_B8 = 3;
        break;
    case 3:
        w->unk_B8 = 1;
        break;
    }

    if (w->unk_C0[w->unk_B8] == 0) {
        func_0807682C(w, (u8)w->unk_B8);
        node = (CardDisplayWork*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_A3 = 12;
            node->unk_98 = gUnk_09033FB8[0];
            node->unk_94 = gUnk_09033FB8[0];
            node->unk_9C = 12;
            node = (CardDisplayWork*)ListPoolNext(&node->node);
        }

        if (w->unk_BC[w->unk_B8] == 0 && w->unk_B0[w->unk_B8] > 0) {
            CreateREVCOUNTTask(w, &w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
        }
    } else {
        gUnk_02034A98 = w->unk_34[w->unk_B8];
        gUnk_02034A98->unk_98 = gUnk_09033FB8[0];
        gUnk_02034A98->unk_94 = gUnk_09033FB8[1];
        gUnk_02034A98->unk_A3 = 12;
        gUnk_02034A98->unk_9C = 12;
        gUnk_02034A98->unk_78 |= 4;
    }

    gUnk_02039DD4->unk_0D2 = w->unk_B8;
}

void func_0807B378(u8* p) {
    s16* c;

    switch ((s8)p[0xB8]) {
    case 0:
        (*(s16*)&p[0x9C])++;
        break;
    case 1:
        (*(s16*)&p[0x9E])++;
        break;
    case 2:
        break;
    }

    c = (s16*)&p[0x9C];
    c += (s8)p[0xB8];

    if (*c > 2) {
        *c = 2;
    }
}

void func_0807B3C4(void) {
}

u8 func_0807B3C8(void) {
    u8 result;

    if (gUnk_02039DD4 == 0) {
        result = 0xFF;
    } else {
        result = gUnk_02039DD4->unk_0D2;
    }

    return result;
}

u8 func_0807B3E0(void) {
    u8 result;

    if (gUnk_02039DD4 == 0) {
        result = 0;
    } else {
        result = gUnk_02039DD4->unk_0D3;
    }

    return result;
}

u8 func_0807B3F8(void) {
    if (gUnk_02039DD4 != 0) {
        return gUnk_02039DD4->unk_0D5;
    }

    return 0;
}

void func_0807B410(void* pool) {
    UnkStruct_0807B410* t;
    u32 v;

    t = (UnkStruct_0807B410*)ListPoolFirst(&gBtlWork->pool);

    while (t != 0) {
        v = t->unk_00;

        switch (v) {
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
            TaskCreate(pool, &gTaskDescBosscard, &v);
            return;
        }

        t = (UnkStruct_0807B410*)ListPoolNext(&t->unk_B8);
    }
}

void func_0807B458(UnkStruct_08080268* w, u16 value) {
}

void func_0807B45C(UnkStruct_08080268* w) {
    gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
}

void func_0807B478(CardDisplayWork* w) {
    u32* p;
    u16* c;
    u16* q;
    u16* q2;

    if (gBtlWork->flags & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 != 41) {
            gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
        } else {
            gBtlWork->unk_0F4 = 0;
            gUnk_02039DD4->unk_0CC = 0;
        }

        p = &gBtlWork->unk_0F4;

        if (*p == 41) {
#ifdef VERSION_EU
            if (gUnk_02039B9C->unk_0F4 == 47 && (gBtlWork->flags & 0x40)) {
                gUnk_02039B9C->flags &= ~2;
            }
#endif
            gUnk_02039DD4->unk_0CE = 0;
            gUnk_02039B9C->unk_0F4 = 0;
            gUnk_02039B9C->unk_0F8 = 0;
            gBtlWork->unk_0F4 = 0;
            gBtlWork->unk_0F8 = 0;
        }

        c = &gUnk_02039DD4->unk_0CC;

        if (*c == 45) {
            if (gUnk_02039B9C->unk_0F4 != 0) {
                gBtlWork->unk_0F4 = gUnk_02039B9C->unk_0F4;
                gUnk_02039DD4->unk_0CC = gUnk_02039DD4->unk_0CE;
            } else {
                gBtlWork->unk_0F4 = 0;
                gUnk_02039DD4->unk_0CE = 0;
            }
        }

        if (gBtlWork->unk_0F4 == 47) {
            q2 = &w->unk_9C;
            q = q2;
            *q++ = 2;
            *q = 2;
        }
    } else {
        if (gUnk_02039DD4->unk_0CC != 41 && gUnk_02039DD4->unk_0CC != 45) {
            gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
        } else {
            gBtlWork->unk_0F4 = 0;
        }
    }
}

u8 func_0807B578(UnkStruct_08080268* w, void* a) {
    s16 v;

    v = w->unk_B0[w->unk_B8];

    if (v > 2) {
        if (gUnk_02034A98->unk_78 & 0x40) {
            func_08078E34(w, w->unk_B8, 2);
        }
    } else if (v > 1) {
        if (gUnk_02034A98->unk_78 & 0x40) {
            func_08078D98((u8*)w, w->unk_B8, 2);
        }
    }

    w->unk_A6--;

    if (w->unk_A6 <= 0) {
        SetTaskUpdate(a, (TaskUpdateFunc)func_08076F80);
    }

    TaskPoolUpdate(w);
    TaskPoolUpdate(&gUnk_02039DD4->tasks);
    return 1;
}

u8 func_0807B60C(void) {
    if (gBtlWork->unk_0F4 == 38) {
        if (gUnk_02034A98->cardDef->unk_2A != 1) {
            return 1;
        }

        if (!(gUnk_02034A98->cardDef->flags & 4)) {
            return 1;
        }

        return 0;
    } else if (gBtlWork->unk_0F4 == 39) {
        if (gUnk_02034A98->cardDef->unk_2A != 1) {
            return 1;
        }

        if (gUnk_02034A98->cardDef->flags & 4) {
            return 1;
        }

        return 0;
    }

    return 1;
}

void func_0807B668(UnkStruct_02039DD4* p) {
    p->unk_040 = AllocObjTiles(0x280, 0);
    SetObjTileSource(p->unk_040, gUnk_0908B1B4);
    AnimInit(&p->anim, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&p->anim, 0, 1);
    p->gfx = AnimGetGfx(&p->anim);
    p->unk_050 = AllocObjTiles(0x100, 0);
    SetObjTileSource(p->unk_050, gUnk_0908C3CE);
    AnimInit(&p->anim2, gUnk_09EEA198, gUnk_09EEA180);
    AnimStart(&p->anim2, 0, 1);
    p->gfx2 = AnimGetGfx(&p->anim2);
}

void func_0807B6F4(void) {
    UnkStruct_02039DD4* p;

    p = gUnk_02039DD4;
    p->unk_0F4 = 0;
    p->unk_0FC = 0;
    p->unk_100 = 4;
    p->unk_104 = 2;
    p->unk_108[0] = 0;
}

void func_0807B728(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].cardId;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 0) {
                    if (c[i].unk_0A == 0) {
                        c[i].unk_06 = 0;
                    }
                } else if (t == 1) {
                    if (c[i].unk_0A == 1 || c[i].unk_07 == 1 || c[i].unk_08 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B7A4(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].cardId;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 0) {
                    c[i].unk_0A = 0;
                    c[i].unk_06 = 0;
                } else if (t != 2) {
                    if (c[i].unk_08 == 1 || c[i].unk_0A == 1 || c[i].unk_07 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B81C(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].cardId;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 0) {
                    c[i].unk_06 = 0;
                    c[i].unk_0A = 0;
                } else if (t != 2) {
                    if (c[i].unk_08 == 1 || c[i].unk_0A == 1 || c[i].unk_07 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B894(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].cardId;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 1) {
                    if (c[i].unk_0A == 0) {
                        c[i].unk_06 = 0;
                    }
                } else if (t != 2) {
                    if (c[i].unk_0A == 1 || c[i].unk_07 == 1 || c[i].unk_08 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B910(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].cardId;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 1) {
                    c[i].unk_06 = 0;
                    c[i].unk_0A = 0;
                } else if (t != 2) {
                    if (c[i].unk_08 == 1 || c[i].unk_0A == 1 || c[i].unk_07 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B98C(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        if (c[i].cardId != 0xFFFF) {
            if (c[i].cardId != 0xFFFE) {
                if (gCardDefs[c[i].cardId & CARD_ID_MASK].unk_2A != 2) {
                    c[i].unk_06 = 0;
                    c[i].unk_0A = 0;
                }
            }
        }
    }
}

void func_0807B9EC(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;

    c = w->slots[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        if (c[i].cardId != 0xFFFF) {
            if (c[i].cardId != 0xFFFE) {
                if (gCardDefs[c[i].cardId & CARD_ID_MASK].flags & 2) {
                    if (c[i].unk_0A == 0) {
                        c[i].unk_09 = 1;
                    }

                    c[i].unk_0A = 1;
                }
            }
        }
    }
}

u8 func_0807BA54(void) {
    if (gGameState.flags & 8) {
        if (!(gBtlWork->flags & 0x800000000000)) {
            gBtlWork->unk_1C8 += (s8)gBtlWork->unk_1CA;
        } else if ((s8)gBtlWork->unk_1CA < 0) {
            gBtlWork->unk_1C8 += (s8)gBtlWork->unk_1CA;
        }

        if (gBtlWork->unk_1C8 > 999) {
            gBtlWork->unk_1C8 = 999;
        } else if (gBtlWork->unk_1C8 < 0) {
            gBtlWork->unk_1C8 = 0;
        }
    }

    if (gBtlWork->unk_1C8 > 29 && !(gBtlWork->flags & 0x800000000000)) {
        return 1;
    }

    return 0;
}

void func_0807BB04(void) {
    switch (gBtlWork->unk_0F4) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 30:
    case 31:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 42:
    case 51:
    case 53:
        gBtlWork->unk_0F8--;
        break;
    }
}

void func_0807BC08(void) {
    if (gBtlWork->unk_0F4 == 50) {
        gBtlWork->unk_0F8--;
    }
}
void func_0807BC24(CardDisplayWork* p, CardDisplayArgs* a) {
    vu32 zero;
    u16 v;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->tiles = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->tiles4 = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(void**)p->unk_1C = 0;
    *(CardDisplayArgs*)&p->pool = *a;
    p->unk_78 = 0;
    v = p->unk_44;

    if ((s16)v != -1) {
        func_0807D318(&p->pool, &p->cardDef, (u8)v);

        if (p->slot->cardId == 0xFFFE) {
            p->unk_78 |= 0x100000;
        }
    } else {
        p->unk_78 = 2;
    }

    if (p->slot->cardId & 0x8000) {
        p->unk_A6 = 1;
    } else {
        p->unk_A6 = 0;
    }

    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_84 = 0;
    p->unk_88 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 60;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_09033FF4[0][0];
    p->unk_90 = gUnk_09033FF4[0][1];
    p->x = gUnk_09033FF4[4][0];
    p->y = gUnk_09033FF4[4][1];

    if (p->cardDef != 0) {
        p->unk_A5 = p->cardDef->unk_20;
    } else {
        p->unk_A5 = 0;
    }

    p->unk_A7 = 0;
    p->unk_78 |= 0x20;
    p->unk_78 &= ~0x40;
    func_0807D380((u8*)p);
}
u8 func_0807BD64(CardDisplayWork* p, void* a) {
    u8 (*fn)(CardDisplayWork*, void*);

    if (p->unk_78 & 0x10) {
        if (!(p->unk_78 & 0x80)) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
        }

        if (p->unk_78 & 0x10) {
            p->unk_9C = 8;
            func_0807E018(p);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807CB24);
            return 1;
        }
    }

    if ((s16)p->unk_9C == 0) {
        if (func_0807CE68(p)) {
            ListPoolRemove(&p->node, p->pool);
            return 0;
        }

        if (!(p->unk_78 & 0x80)) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
            fn = func_0807BE54;
            SetTaskUpdate(a, (TaskUpdateFunc)fn);
            return fn(p, a);
        }
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CBC0);
    }

    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

u8 func_0807BE54(CardDisplayWork* p, void* a) {
    if (func_0807CE68(p)) {
        ListPoolRemove(&p->node, p->pool);
        return 0;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CBC0);
    }

    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

static void card_2(CardDisplayWork* p) {
    s16 y;
    void* gfx;
    s32 aff;
    u8 j;
    u8 k;
    u16 attr;

    attr = 0x410;

    if (func_080A42C8() == 1) {
        y = p->y >> 8;
    } else {
        y = (p->y >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    gfx = p->cardDef->gfx;

    if (!(p->unk_78 & 0x800)) {
        return;
    }

    if (!(p->unk_78 & 0x80)) {
        return;
    }

    if (!(p->unk_78 & 0x200)) {
        aff = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 0);
        DrawSprite(p->x >> 8, y, gUnk_08F709B0[p->cardDef->unk_2A].gfx, ((struct UnkStruct_0807BEC0*)gUnk_02039DD4)->tiles[p->cardDef->unk_2A], gUnk_02039DD4->palette, aff, attr, (u16)(p->unk_A0 - 1));
        DrawSprite(p->x >> 8, y, gfx, p->tiles, p->palette, aff, attr, p->unk_A0);
        j = p->unk_A5;

        if (p->cardDef->unk_2A == 3) {
            return;
        }

        if (p->unk_A7 != 0) {
            DrawSprite(p->x >> 8, y, gUnk_09EE98C0[j], gUnk_02039DD4->tiles7, gUnk_02039DD4->palette2, aff, attr, (u16)(p->unk_A0 - 2));
        } else if (p->unk_A6 != 0) {
            DrawSprite(p->x >> 8, y, gUnk_09EE9894[j], gUnk_02039DD4->tiles6, gUnk_02039DD4->palette2, aff, attr, (u16)(p->unk_A0 - 2));
        } else {
            DrawSprite(p->x >> 8, y, gUnk_09EE981C[j], gUnk_02039DD4->tiles5, gUnk_02039DD4->palette, aff, attr, (u16)(p->unk_A0 - 2));
        }

        if (p->unk_A6 != 0) {
            DrawSprite(p->x >> 8, y, gUnk_02039DD4->gfx, gUnk_02039DD4->unk_040, gUnk_02039DD4->palette, aff, attr, (u16)(p->unk_A0 - 3));
        }

        return;
    }

    aff = AllocObjAffine(0, p->unk_54, p->unk_58, 0);
    DrawSprite(p->x >> 8, y, p->cardDef->gfx2, p->tiles, p->palette, aff, attr, p->unk_A0);
    k = p->unk_A5;

    if (p->cardDef->unk_2A == 3) {
        return;
    }

    if (p->unk_A7 != 0) {
        DrawSprite((p->x >> 8) - 3, y - 4, gUnk_09EE981C[k], gUnk_02039DD4->tiles7, gUnk_02039DD4->palette2, aff, attr, (u16)(p->unk_A0 - 10));

        if (p->unk_A6 != 0) {
            DrawSprite(p->x >> 8, y, gUnk_02039DD4->gfx2, gUnk_02039DD4->unk_050, gUnk_02039DD4->palette, aff, attr, (u16)(p->unk_A0 - 11));
        }
    } else if (p->unk_A6 != 0) {
        DrawSprite((p->x >> 8) - 3, y - 4, gUnk_09EE981C[k], gUnk_02039DD4->tiles6, gUnk_02039DD4->palette2, aff, attr, (u16)(p->unk_A0 - 10));
        DrawSprite(p->x >> 8, y, gUnk_02039DD4->gfx2, gUnk_02039DD4->unk_050, gUnk_02039DD4->palette, aff, attr, (u16)(p->unk_A0 - 11));
    } else {
        DrawSprite((p->x >> 8) - 3, y - 4, gUnk_09EE981C[k], gUnk_02039DD4->tiles5, gUnk_02039DD4->palette, aff, attr, (u16)(p->unk_A0 - 10));
    }
}

void card_not_have_2(CardDisplayWork* p) {
    void* gfx;
    u16 y;

    gfx = gUnk_08F709B0[p->unk_46].gfx2;

    if (func_080A42C8() == 1) {
        y = p->y >> 8;
    } else {
        y = (p->y >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    if (p->unk_78 & 0x80) {
        DrawSprite(p->x >> 8, y, gfx, p->tiles2, gUnk_02039DD4->palette, 0, 0x410, (u16)(p->unk_A0 - 1));
    }
}

void func_0807C2E0(CardDisplayWork* p) {
    func_0807C39C(p);
}

void func_0807C2EC(CardDisplayWork* p) {
    if (p->unk_A1 != 6) {
        if (func_0807CE68(p) != 0) {
            if (p->unk_78 & 0x80) {
                func_0807C39C(p);
                p->unk_78 &= ~0x80;
            }
        } else {
            if (!(p->unk_78 & 0x80)) {
                func_0807C33C(p);
                p->unk_78 |= 0x80;
            }
        }
    }
}

void func_0807C33C(CardDisplayWork* p) {
    CardDef* d;
    void* tiles;
    void* pal;
    u32 f;

    f = p->unk_78 & 2;

    if (f != 0) {
        p->tiles = 0;
        p->palette = 0;
        p->unk_18 = 0;
        p->tiles2 = LoadObjTiles(gUnk_08F709B0[p->unk_46].tiles2, 640);
    } else {
        d = p->cardDef;
        tiles = d->tiles;
        pal = d->palette;
        p->tiles = LoadObjTiles(tiles, 512);
        p->palette = LoadObjPalette(pal, 32);
        p->tiles2 = 0;
    }
}

void func_0807C39C(CardDisplayWork* p) {
    if (p->tiles != 0) {
        ReleaseObjTiles(p->tiles);
    }

    if (p->palette != 0) {
        ReleaseObjPalette(p->palette);
    }

    if (p->tiles2 != 0) {
        ReleaseObjTiles(p->tiles2);
    }

    if (p->tiles3 != 0) {
        ReleaseObjTiles(p->tiles3);
    }

    if (p->tiles4 != 0) {
        ReleaseObjTiles(p->tiles4);
    }

    p->tiles = 0;
    p->palette = 0;
    p->unk_18 = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->tiles4 = 0;
}

u8 func_0807C3E8(CardDisplayWork* p, void* a) {
    if (gBtlWork->flags & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->flags &= ~0x80;
        gBtlWork->flags &= ~0x20;
        gBtlWork->flags &= ~0x8000000;

        if (p->cardDef->unk_2A == 0) {
            func_0807E184();
        }

        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE04);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D3A0);
    }

    return 1;
}

u8 func_0807C4BC(CardDisplayWork* p, void* a) {
    ApproachValue(&p->x, 0x7800, p->unk_9C);
    ApproachValue(&p->y, 0x8400, p->unk_9C);
    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C |= 0xFFFF;
    }

    if (gBtlWork->flags & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (TaskUpdateFunc)func_0807C3E8);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = -16;
            p->unk_9E = 0xFF;
            p->unk_78 |= 0x2000;
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE9C);

            if (p->cardDef->flags & 2) {
                p->slot->unk_06 = 0;
            }

            m4aSongNumStart(SONG_SYS_DROW);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE9C);
    }

    return 1;
}
u8 func_0807C5D8(CardDisplayWork* w, void* a) {
    ApproachValue(&w->unk_8C, gUnk_0903404C[0], w->unk_9C);
    ApproachValue(&w->unk_90, gUnk_0903404C[1], w->unk_9C);
    ApproachValue(&w->unk_84, w->unk_88, w->unk_9C);
    ApproachValue(&w->unk_54, 0x100, w->unk_9C);
    ApproachValue(&w->unk_58, 0x100, w->unk_9C);
    if ((s16)w->unk_9C > 0) {
        w->unk_9C--;
    } else {
        w->unk_9C = 0;
    }
    func_0807D0F4(w);
    switch (w->unk_9F) {
    case 0:
        w->unk_A0 = 50;
        break;
    case 1:
        w->unk_A0 = 40;
        break;
    case 2:
        w->unk_A0 = 60;
        break;
    }
    if (w->unk_78 & 0x200000) {
        w->unk_A0 -= 4;
        w->unk_84 = 0x500;
        w->unk_9C = 0x100;
        w->unk_7C = -16;
        w->unk_9E = 0xFF;
        gUnk_02039DD4->unk_0E1 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D3A0);
    }
    if (gBtlWork->flags & 0x20) {
        w->unk_9C = 8;
        w->unk_9E = 8;
        gUnk_02039DD4->unk_0D0--;
        gUnk_02039DD4->unk_0C2 = 0;
        if (gUnk_02039DD4->unk_0D0 == 0) {
            gBtlWork->flags &= ~0x20;
            gBtlWork->flags &= ~0x80;
            func_0807E158();
        }
        gUnk_02039DD4->unk_0E1 = 0;
        gBtlWork->flags &= ~0x8000000;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE04);
    }
    return 1;
}
u8 func_0807C75C(CardDisplayWork* p, void* a) {
    u8 (*fn)(CardDisplayWork*, void*);

    func_0807C2EC(p);

    if (!(p->unk_78 & 0x10000000)) {
        fn = func_0807C934;
        SetTaskUpdate(a, (TaskUpdateFunc)fn);
        return fn(p, a);
    }

    if (p->unk_78 & 0x40000000) {
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D810);
        return 1;
    }

    if (p->unk_A1 == 5) {
        if (p->unk_78 & 0x8000) {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->x;
            p->unk_90 = p->y;
            fn = func_0807C5D8;
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->x;
            p->unk_90 = p->y;
            p->unk_A0 += p->unk_9F * 3;
            fn = func_0807CFA8;
        }

        SetTaskUpdate(a, (TaskUpdateFunc)fn);
        p->unk_78 &= ~0x200;
        func_0807D4B8(p);
        return fn(p, a);
    }

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    if (p->unk_78 & 0x20) {
        switch (p->unk_A2) {
        case 0:
            p->y -= 0x80;

            if (p->y <= gUnk_09033FF4[3 - p->unk_9F][1] - 0x200) {
                p->y = gUnk_09033FF4[3 - p->unk_9F][1] - 0x200;
                p->unk_A2 = 1;
            }
            break;
        case 1:
            p->y += 0x200;

            if (p->y >= gUnk_09033FF4[3 - p->unk_9F][1]) {
                p->y = gUnk_09033FF4[3 - p->unk_9F][1];
                p->unk_A2 = 0;
                p->unk_9C = 16;
            }
            break;
        }
    } else {
        ApproachValue(&p->x, gUnk_09033FF4[4][0], p->unk_9C);
        ApproachValue(&p->y, gUnk_09033FF4[4][1], p->unk_9C);
    }

    p->unk_5F += 4;
    return 1;
}
u8 func_0807C934(CardDisplayWork* p, void* a) {
    u8 (*fn)(CardDisplayWork*, void*);
    u16 t;

    if (gBtlWork->unk_070 == 1) {
        return 1;
    }

    func_0807C2EC(p);

    if (p->unk_78 & 0x20) {
        ApproachValue(&p->x, gUnk_09033FF4[3 - p->unk_9F][0], p->unk_9C);
        ApproachValue(&p->unk_58, 179, p->unk_9C);
        ApproachValue(&p->y, gUnk_09033FF4[3 - p->unk_9F][1], p->unk_9C);
        ApproachValue(&p->unk_54, 179, p->unk_9C);
    } else {
        ApproachValue(&p->x, gUnk_09033FF4[4][0], p->unk_9C);
        ApproachValue(&p->y, gUnk_09033FF4[4][1], p->unk_9C);
    }

    t = p->unk_9C;

    if ((s16)t > 0) {
        p->unk_9C = t - 1;
        p->unk_78 &= ~0x40;
    } else {
        p->unk_9C = 0;
        p->unk_54 = 0x100;
        p->unk_58 = 0x100;
        p->unk_78 |= 0x40;

        if (p->unk_78 & 0x10000000) {
            p->unk_9C = p->unk_9F * 8;
            fn = func_0807C75C;
            SetTaskUpdate(a, (TaskUpdateFunc)fn);
            return fn(p, a);
        }
    }

    if (p->unk_78 & 0x40000000) {
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D810);
        return 1;
    }

    if (p->unk_A1 == 5) {
        if (p->unk_78 & 0x8000) {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->x;
            p->unk_90 = p->y;
            fn = func_0807C5D8;
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->x;
            p->unk_90 = p->y;
            fn = func_0807CFA8;
        }

        SetTaskUpdate(a, (TaskUpdateFunc)fn);
        p->unk_78 &= ~0x200;
        func_0807D4B8(p);
        return fn(p, a);
    }

    p->unk_5F += 4;
    return 1;
}

u8 func_0807CB24(CardDisplayWork* p, void* a) {
    if (!(p->unk_78 & 0x20)) {
        if (p->unk_78 & 0x100000) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807D930);
            return func_0807D930(p, a);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807CBC0);
            return func_0807CBC0(p, a);
        }
    }

    func_0807CC2C(p);
    p->unk_9C--;

    if (p->unk_9C == 0) {
        p->unk_78 &= ~0x10;

        if (p->unk_78 & 0x100000) {
            gUnk_02039DD4->unk_0E7 = 0;
            SetTaskUpdate(a, (TaskUpdateFunc)card_reload_1);
        } else {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807BD64);
        }
    }

    return 1;
}

u8 func_0807CBC0(CardDisplayWork* p, void* a) {
    u8 (*f)(CardDisplayWork*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += (0 - p->unk_84) >> 1;
    p->x += (gUnk_09033FF4[4][0] - p->x) >> 1;
    p->y += (gUnk_09033FF4[4][1] - p->y) >> 1;

    if (p->unk_78 & 0x20) {
        f = func_0807BD64;
        SetTaskUpdate(a, (TaskUpdateFunc)f);
        return f(p, a);
    }

    return 1;
}

void func_0807CC2C(CardDisplayWork* p) {
    s32 angle;

    ApproachValue(&p->unk_94, p->unk_98, p->unk_A3);

    if (p->unk_A3 != 0) {
        p->unk_A3--;
    }

    p->unk_84 += (p->unk_88 - p->unk_84) >> 1;

    if ((s16)p->unk_9C > 0) {
        ApproachValue(&p->unk_7C, p->unk_80, p->unk_9C);
        p->unk_9C--;
        p->unk_78 &= ~0x40;
        gUnk_02039DD4->unk_0E7 = 0;
    } else {
        p->unk_78 |= 0x40;
    }

    p->unk_8C = gSineTable[(p->unk_94 >> 8) & 0xFF] * 80 + gUnk_09033FF4[0][0];
    p->unk_90 = -gSineTable[((p->unk_94 >> 8) & 0xFF) + 0x40] * 80 + gUnk_09033FF4[0][1];
    angle = ((p->unk_7C >> 8) + 0x20) & 0xFF;
    p->x = gSineTable[angle] * (p->unk_84 >> 8) + p->unk_8C;
    p->y = -gSineTable[angle + 0x40] * (p->unk_84 >> 8) + p->unk_90;
}

void func_0807CD48(CardDisplayWork* p) {
    if (p->unk_78 & 0x800) {
        if (p->unk_78 & 4) {
            if (p->unk_78 & 1) {
                if (p->unk_54 > 2) {
                    p->unk_54 -= 64;

                    if (p->unk_54 <= 2) {
                        p->unk_54 = 2;
                    }
                } else {
                    p->unk_54 = 2;
                    p->unk_78 &= ~1;

                    if (!(p->unk_78 & 0x80)) {
                        func_0807C33C(p);
                        p->unk_78 |= 0x80;
                    }
                }
            } else {
                if (p->unk_54 <= 255) {
                    p->unk_54 += 64;

                    if (p->unk_54 > 256) {
                        p->unk_54 = 256;
                    }
                } else {
                    p->unk_54 = 256;
                }
            }
        } else {
            if (!(p->unk_78 & 1)) {
                if (p->unk_54 > 2) {
                    p->unk_54 -= 64;

                    if (p->unk_54 <= 2) {
                        p->unk_54 = 2;
                    }
                } else {
                    p->unk_54 = 2;
                    p->unk_78 |= 1;

                    if (p->unk_78 & 0x80) {
                        func_0807C39C(p);
                        p->unk_78 &= ~0x80;
                    }
                }
            } else {
                if (p->unk_54 <= 255) {
                    p->unk_54 += 64;

                    if (p->unk_54 > 256) {
                        p->unk_54 = 256;
                    }
                } else {
                    p->unk_54 = 256;
                }
            }
        }
    }
}

u8 func_0807CE04(CardDisplayWork* p) {
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

u8 func_0807CE68(CardDisplayWork* p) {
    if (p->x > 0x10000) {
        return 1;
    }

    if (p->x < -0x1000) {
        return 1;
    }

    if (p->y > 0xC000) {
        return 1;
    }

    if (p->y < -0x2000) {
        return 1;
    }

    return 0;
}

u8 func_0807CE9C(CardDisplayWork* p) {
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
        gBtlWork->flags &= ~0x8000000;
        p->unk_78 &= ~0x80;
        return 0;
    }

    return 1;
}

u8 func_0807CF4C(u8* work, void* a) {
    u16* p;
    s32 z;

    p = (u16*)&work[0x9C];
    z = 0;
    *p = 15;
    *(s32*)&work[0x88] = 0x800;
    *(s32*)&work[0x84] = z;
    *(s32*)&work[0x80] = gUnk_09034054[work[0x9F]] * 2;
    *(s32*)&work[0x7C] = z;
    *(s32*)&work[0x8C] = *(s32*)&work[0x4C];
    *(s32*)&work[0x90] = *(s32*)&work[0x50];
    SetTaskUpdate(a, (TaskUpdateFunc)func_0807C5D8);
    return 1;
}

u8 func_0807CFA8(CardDisplayWork* p, void* a) {
    ApproachValue(&p->unk_8C, gUnk_0903404C[0], p->unk_9C);
    ApproachValue(&p->unk_90, gUnk_0903404C[1], p->unk_9C);
    ApproachValue(&p->unk_84, p->unk_88, p->unk_9C);
    ApproachValue(&p->unk_54, 0x100, p->unk_9C);
    ApproachValue(&p->unk_58, 0x100, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C = 0;
    }

    func_0807D0F4(p);

    if (gBtlWork->flags & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (TaskUpdateFunc)func_0807C5D8);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = -16;
            p->unk_9E = 0xFF;
            gUnk_02039DD4->unk_0C0 = 0;
            gUnk_02039DD4->unk_0E1 = 0;
            SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE9C);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        gUnk_02039DD4->unk_0E1 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE9C);
    }

    return 1;
}

void func_0807D0F4(CardDisplayWork* p) {
    s32 t;

    if (p->unk_80 - p->unk_7C > 0x7F00) {
        p->unk_7C += 0x10000;
    }

    if (p->unk_80 - p->unk_7C <= 255) {
        t = p->unk_7C - 0x10000;

        if (p->unk_80 - t < p->unk_7C - p->unk_80) {
            p->unk_7C = t;
        }
    }

    p->unk_7C += (p->unk_80 - p->unk_7C) >> 2;
    p->x = gSineTable[(p->unk_7C >> 8) & 0xFF] * (p->unk_84 >> 8) + p->unk_8C;
    p->y = -gSineTable[((p->unk_7C >> 8) & 0xFF) + 64] * (p->unk_84 >> 8) + p->unk_90;
}
u8 func_0807D194(CardDisplayWork* w, void* a) {
    switch (w->unk_A1) {
    case 5:
        if (!(w->unk_78 & 0x80)) {
            func_0807C33C(w);
            w->unk_78 |= 0x80;
        }
        func_0807CC2C(w);
        w->unk_9C = 10;
        w->unk_A0 -= 4;
        ListPoolRemove(&w->node, w->pool);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807C4BC);
        return 1;
    case 6:
        if (!(w->unk_78 & 0x80)) {
            func_0807C33C(w);
            w->unk_78 |= 0x80;
        }
        w->unk_9C = 8;
        w->unk_A0 -= 4;
        func_0807D490(w);
        w->unk_78 |= 0x200;
        w->unk_78 |= 0x80;
        ListPoolRemove(&w->node, w->pool);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807C934);
        return 1;
    case 8:
        w->unk_A0 -= 4;
        w->unk_84 = 0x500;
        w->unk_9C = 0x100;
        w->unk_7C = -16;
        w->unk_9E = 0xFF;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CE9C);
        break;
    case 7:
        w->unk_84 = 0x500;
        w->unk_9C = 0x100;
        ListPoolRemove(&w->node, w->pool);
        return 0;
    case 10:
        w->unk_9C = 10;
        w->unk_A0 -= 4;
        ListPoolRemove(&w->node, w->pool);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D4E4);
        return 1;
    case 11:
        w->unk_9C = 10;
        w->unk_A0 -= 4;
        ListPoolRemove(&w->node, w->pool);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D584);
        return 1;
    }
    func_0807E018(w);
    return 1;
}

void func_0807D318(CardDisplayWork* p, CardDef** out) {
    u32* q;

    if (p->tiles2 != 0) {
        if (*(u32*)p->tiles2 != 0xFFFF) {
            if (*(u32*)p->tiles2 != 0xFFFE) {
                *out = &gCardDefs[*(u32*)p->tiles2 & CARD_ID_MASK];
            } else {
                *out = 0;
            }
        } else {
            *out = 0;
        }
    } else {
        q = &gUnk_02039DD4->unk_0B8;
        *out = &gCardDefs[*q & CARD_ID_MASK];
        *q = 0x3B6;
    }
}

void func_0807D380(u8* p) {
    u8* q;

    q = &p[0x64];
    ListNodeInit(q, *(void**)&p[0x38], p);
    ListPoolAppend(q, *(void**)&p[0x38]);
}
u8 func_0807D3A0(CardDisplayWork* p, void* a) {
    p->unk_A1 = 0;
    p->y -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->x -= 0x200;
    p->unk_5E += 16;

    if (!(p->unk_78 & 0x400000)) {
        p->unk_54 -= 10;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = -10;
        }

        if (p->unk_54 <= -0x100) {
            p->unk_54 = -0x100;
            p->unk_78 |= 0x400000;
        }
    } else {
        p->unk_54 -= 10;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = 10;
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
        gBtlWork->flags &= ~0x8000000;
        return 0;
    }

    return 1;
}
void func_0807D490(CardDisplayWork* p) {
    void* tiles;
    void* pal;

    func_0807C39C(p);
    tiles = p->cardDef->tiles2;
    pal = p->cardDef->palette2;
    p->tiles = LoadObjTiles(tiles, 256);
    p->palette = LoadObjPalette(pal, 32);
}

void func_0807D4B8(CardDisplayWork* p) {
    if (p->tiles != 0) {
        ReleaseObjTiles(p->tiles);
    }

    if (p->palette != 0) {
        ReleaseObjPalette(p->palette);
    }

    p->tiles = 0;
    p->palette = 0;
    func_0807C33C(p);
}

u8 func_0807D4E4(CardDisplayWork* p) {
    u8 arg;

    p->unk_A1 = 0;
    ApproachValue(&p->x, 0x1800, p->unk_9C);
    ApproachValue(&p->unk_58, 0x99, p->unk_9C);
    ApproachValue(&p->y, 0x6400, p->unk_9C);
    ApproachValue(&p->unk_54, 0x99, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    arg = 1;
    gBtlWork->unk_0F8 = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E;
    TaskCreate(&gUnk_02039DD4->tasks, &gTaskDescHCEffectName, &arg);
    return 0;
}

u8 func_0807D584(CardDisplayWork* p, void* a) {
    s16 sx;
    s16 sy;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    ApproachValue(&p->x, 0x1800, p->unk_9C);
    ApproachValue(&p->y, 0x6400, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        WorldToScreen(&sx, &sy, gBtlWork->unk_100, gBtlWork->unk_104, gBtlWork->unk_108);
        x = sx;
        y = sy;
        dx = (x << 8) - p->x;
        dy = (y << 8) - p->y;
        p->unk_84 = NormalizeVector2D8(&dx, &dy);
        p->unk_8C = -dx;
        p->unk_90 = -dy;
        p->unk_88 = 0x300;
        p->unk_5E = 0;
        p->unk_80 = 25;
        gBtlWork->unk_072 = 10000;
        FadeStartOut(7, 1);
        m4aSongNumStart(SONG_BTL_GMIC_OK);
        FadeLock();
        gBtlWork->flags |= 0x200000000000000;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D68C);
    }

    return 1;
}

u8 func_0807D68C(CardDisplayWork* p, void* a) {
    s16 sx;
    s16 sy;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    WorldToScreen(&sx, &sy, gBtlWork->unk_100, gBtlWork->unk_104, gBtlWork->unk_108);
    x = sx;
    y = sy;

    if (p->unk_88 < 0) {
        dx = (x << 8) - p->x;
        dy = (y << 8) - p->y;
        NormalizeVector2D8(&dx, &dy);
        p->unk_8C = -dx;
        p->unk_90 = -dy;
    }

    p->unk_5E += 24;

    if (p->unk_54 > 24) {
        p->unk_54 -= 12;
        p->unk_58 -= 12;
    } else {
        p->unk_54 = 25;
        p->unk_58 = 25;
    }

    p->x += (p->unk_8C * p->unk_88) >> 8;
    p->y += (p->unk_90 * p->unk_88) >> 8;
    p->unk_84 = VectorLength2D((x << 8) - p->x, (y << 8) - p->y);
    p->unk_88 -= p->unk_80;
    p->unk_80 += 2;

    if (p->unk_84 <= 0x800) {
        gBtlWork->unk_074 = 15;
        gBtlWork->unk_072 = 15;
        m4aSongNumStart(SONG_SYS_CLICKI04);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D7B0);
    }

    return 1;
}

u8 func_0807D7B0(CardDisplayWork* p) {
    if ((s16)gBtlWork->unk_072 == 0) {
        FadeStartIn(7, 8);
        FadeLock();
        gBtlWork->flags &= ~0x200000000000000;

        if (p->cardDef->unk_24 == 140) {
            func_0801C1A0(0);
        }

        gBtlWork->flags &= ~0x20000000000000;
        return 0;
    }

    return 1;
}

u8 func_0807D810(u8* work) {
    s32 r;

    if (*(s32*)&work[0x54] <= 25) {
        (*(u8**)&work[0x3C])[7] = r = 0;
        return r;
    }

    *(s32*)&work[0x54] -= 12;
    *(s32*)&work[0x58] += 12;

    if (*(s32*)&work[0x58] > 0x1FF) {
        *(s32*)&work[0x58] = 0x200;
    }

    return 1;
}
void card_reload_0(CardDisplayWork* p, CardDisplayArgs* a) {
    vu32 zero;
    vu32 zero2;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->tiles = 0;
    p->tiles2 = 0;
    p->tiles3 = 0;
    p->tiles4 = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = EwramAlloc(0x68);
    zero2 = 0;
    CpuSet((void*)&zero2, p->unk_20, 0x0500001A);
    *(CardDisplayArgs*)&p->pool = *a;
    ((u8*)p->unk_20)[0x65] = 0;
    p->unk_78 = 0x01100020;
    p->cardDef = 0;
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_9F = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 60;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_09033FF4[0][0];
    p->unk_90 = gUnk_09033FF4[0][1];
    p->x = gUnk_09033FF4[4][0];
    p->y = gUnk_09033FF4[4][1];
    p->unk_78 &= ~0x40;
    gUnk_02039DD4->unk_0E7 = 0;
    func_0807D380(p);
}

u8 func_0807D930(CardDisplayWork* p, void* a) {
    u8 (*f)(CardDisplayWork*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += (0 - p->unk_84) >> 1;
    p->x += (gUnk_09033FF4[4][0] - p->x) >> 1;
    p->y += (gUnk_09033FF4[4][1] - p->y) >> 1;

    if (p->unk_78 & 0x20) {
        f = card_reload_1;
        SetTaskUpdate(a, (TaskUpdateFunc)f);
        return f(p, a);
    }

    return 1;
}

u8 card_reload_1(CardDisplayWork* p, void* a) {
    if (p->unk_78 & 0x10) {
        p->unk_9C = 8;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807CB24);
        return 1;
    }

    if ((s16)p->unk_9C == 0) {
        if (func_0807CE68(p)) {
            ListPoolRemove(&p->node, p->pool);
            return 0;
        }

        if (!(p->unk_78 & 0x80)) {
            func_0807DAD0(p);
            p->unk_78 |= 0x80;
        }
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0807D930);
    }

    func_0807DE10(p);
    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

void func_0807DA54(UnkStruct_08095A5C* p, void* a, u8 b, s8 c) {
    AnimInit(&p->anim, gUnk_09EEA4E0, gUnk_09EEA494);

    if (c >= 0) {
        AnimStart(&p->anim, c, 0);
    } else {
        AnimStart(&p->anim, 0, 0);
    }

    p->gfx3 = AnimGetGfx(&p->anim);
}

void func_0807DAA4(u8* p, s32 a) {
    void* gfx;

    if ((u16)a <= 18) {
        AnimStart(&p[0x10], a, 0);
        gfx = AnimGetGfx(&p[0x10]);
    } else {
        gfx = 0;
    }

    *(void**)&p[0x60] = gfx;
}
void func_0807DAD0(CardDisplayWork* p) {
    u8* d;

    d = p->unk_20;
    p->tiles = AllocObjTiles(0x80, 0);
    SetObjTileSource(p->tiles, gUnk_0909A4E0);
    func_0807DA54(p->unk_20, p->tiles, p->unk_46, gUnk_02039DD4->unk_0FC);
    p->palette = 0;
    p->tiles2 = LoadObjTiles(gUnk_0909FDCA, 0x280);
    p->unk_18 = 0;
    p->tiles3 = AllocObjTiles(0x200, 0);
    SetObjTileSource(p->tiles3, gUnk_090A0C86);
    p->tiles4 = AllocObjTiles(0x80, 0);
    SetObjTileSource(p->tiles4, gUnk_090A0C86);
    AnimInit(&d[0x28], gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(&d[0x28], 1, 1);
    *(void**)&d[0x58] = gUnk_09EEAF4C[3];
    AnimInit(&d[0x40], gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(&d[0x40], gUnk_02039DD4->unk_104, 1);
    *(void**)&d[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_100 + 2];
}
void card_reload_2(CardDisplayWork* p) {
    u8* w;
    s16 y;
    s32 affine;
    s32 attr;

    if (p->unk_78 & 0x80) {
        w = p->unk_20;

        if (func_080A42C8() == 1) {
            y = p->y >> 8;
        } else {
            y = (p->y >> 8) + (gSineTable[p->unk_5F] >> 8);
        }

        attr = 0x410;
        DrawSprite(p->x >> 8, y, gUnk_08F709B0[3].gfx2, p->tiles2,
                   gUnk_02039DD4->palette, 0, attr, p->unk_A0);

        if (!(gGameState.flags & 8) && *(void**)&w[0x60] != 0) {
            DrawSprite(p->x >> 8, y, *(void**)&w[0x60], p->tiles,
                       gUnk_02039DD4->palette, 0, 0x410, (u16)(p->unk_A0 - 2));
        }

        if ((s32)gUnk_02039DD4->unk_0F4 > 0) {
            affine = AllocObjAffine(0, p->unk_54, gUnk_02039DD4->unk_0F4, 0);

            if (*(void**)&w[0x58] != 0) {
                DrawSprite(p->x >> 8, y + 17, *(void**)&w[0x58], p->tiles3,
                           gUnk_02039DD4->palette, affine, 0x400,
                           (u16)(p->unk_A0 - 1));
            }

            if (gUnk_02039DD4->unk_108[0] == 1 && *(void**)&w[0x5C] != 0) {
                DrawSprite(p->x >> 8, y, *(void**)&w[0x5C], p->tiles4,
                           gUnk_02039DD4->palette, 0, 0x400,
                           (u16)(p->unk_A0 - 1));
            }
        }
    }
}
void card_reload_3(CardDisplayWork* p) {
    func_0807C39C(p);
    EwramFree(p->unk_20);

    if (gBtlWork->flags & 0x1000000) {
        gBtlWork->flags &= ~0x1000000;
    }
}
void func_0807DD70(u8* p, void* a) {
    if (gUnk_02039DD4->unk_104 <= 7) {
        gUnk_02039DD4->unk_104++;
    }

    AnimStart(&p[0x40], (u16)gUnk_02039DD4->unk_104, 5);
}
void func_0807DDA8(u8* p) {
    gUnk_02039DD4->unk_104 = 2;
    AnimStart(&p[0x40], 2, 5);
}
void func_0807DDCC(u8* p, void* a) {
    *(void**)&p[0x58] = gUnk_09EEAF4C[3];
    *(void**)&p[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_100 + 2];
}
void func_0807DDF4(u8* p, void* a) {
    *(void**)&p[0x58] = AnimUpdate(&p[0x28]);
    *(void**)&p[0x5C] = AnimUpdate(&p[0x40]);
}
void func_0807DE10(CardDisplayWork* p) {
    u8* w = p->unk_20;
    u8 v = 0;

    if ((p->unk_78 & 0x44) == 0x44) {
        v = gUnk_02039DD4->unk_0E7;
        gUnk_02039DD4->unk_0E7 = 0;
    } else {
        gUnk_02039DD4->unk_0E7 = 0;
    }

    if ((p->unk_78 & 0x44) == 0x44) {
        if (v == 1) {
            if (*(s8*)&w[0x65] == 2) {
                if (!(gBtlWork->flags & 0x1000000)) {
                    m4aSongNumStart(SONG_SYS_CHAGE);
                    gBtlWork->flags |= 0x1000000;
                }

                if (gUnk_02039DD4->unk_108[0] == 0) {
                    if (gBtlWork->unk_0F4 == 43) {
                        gUnk_02039DD4->unk_0F4 += 12;
                    } else {
                        gUnk_02039DD4->unk_0F4 += 25;
                    }

                    if ((s32)gUnk_02039DD4->unk_0F4 > 0x100) {
                        gUnk_02039DD4->unk_0F4 = 0x100;
                        gUnk_02039DD4->unk_108[0] = 1;
                    }
                } else {
                    gUnk_02039DD4->unk_100 += 3;
                    func_0807DD70(p->unk_20, p);

                    if (gUnk_02039DD4->unk_100 == 22) {
                        gUnk_02039DD4->unk_100 = 4;
                        gUnk_02039DD4->unk_0F4 = 0;
                        gUnk_02039DD4->unk_108[0] = 0;
                        gUnk_02039DD4->unk_0FC--;
                        p->unk_A2 = v;
                        func_0807DDA8(p->unk_20);
                        m4aSongNumStart(SONG_SYS_CHAGEF1);
                        func_0807DAA4(p->unk_20, (s16)gUnk_02039DD4->unk_0FC);
                    }
                }

                w[0x65] = 0;
            }

            func_0807DDF4(p->unk_20, p);
            w[0x65]++;
        } else {
            func_0807DDCC(p->unk_20, p);
            w[0x65] = 0;
            m4aSongNumStop(SONG_SYS_CHAGE);
            gBtlWork->flags &= ~0x1000000;
        }
    } else {
        gBtlWork->flags &= ~0x1000000;
    }

    if ((s16)gUnk_02039DD4->unk_0FC < 0) {
        gUnk_02039DD4->unk_0F4 = 0;
        gUnk_02039DD4->unk_100 = 4;
        gUnk_02039DD4->unk_104 = 2;
        gUnk_02039DD4->unk_108[0] = 0;

        if (!(p->unk_78 & 0x4000000)) {
            p->unk_78 |= 0x4000000;
            m4aSongNumStart(SONG_SYS_CHAGEF2);
        }

        if (FadeGetAmount() == 0) {
            FadeFromAmount(2, 16, 20);
        }

        gBtlWork->flags &= ~0x1000000;
    }
}

void func_0807E018(CardDisplayWork* w) {
    if (gBtlWork->unk_0F4 == 16) {
        if (w->unk_78 & 4) {
            w->unk_A7 = 1;
            w->unk_A5 = GetRandom() % 10;
        } else {
            w->unk_A7 = 0;
            w->unk_A5 = w->cardDef->unk_20;
        }
    } else if (gBtlWork->unk_0F4 == 17) {
        w->unk_A7 = 1;
        w->unk_A5 = 0;
    } else if (gBtlWork->unk_0F4 == 31) {
        w->unk_A7 = 1;
        w->unk_A5 = 10 - w->cardDef->unk_20;
        if (w->unk_A5 == 10) {
            w->unk_A5 = 0;
        }
    } else {
        w->unk_A5 = w->cardDef->unk_20;
        switch (gGameState.unk_1B8) {
        case 7:
            if (w->cardDef->unk_2A == 1) {
                w->unk_A5 += 2;
                if (w->unk_A5 > 9) {
                    w->unk_A5 = 9;
                }
                w->unk_A7 = 1;
            }
            break;
        case 8:
            if (w->cardDef->unk_2A == 2 && (w->cardDef->flags & 2)) {
                w->unk_A5 += 2;
                if (w->unk_A5 > 9) {
                    w->unk_A5 = 9;
                }
                w->unk_A7 = 1;
            }
            break;
        case 9:
            if (w->cardDef->unk_2A == 0) {
                w->unk_A5 += 2;
                if (w->unk_A5 > 9) {
                    w->unk_A5 = 9;
                }
                w->unk_A7 = 1;
            }
            break;
        default:
            w->unk_A7 = 0;
            w->unk_A5 = w->cardDef->unk_20;
            break;
        }
    }
}
void func_0807E158(void) {
    BtlWork* p;

    p = gBtlWork;

    switch ((u32)p->unk_0F4) {
    case 15:
    case 28:
    case 47:
        p->unk_0F8--;
        break;
    }
}
void func_0807E184(void) {
    if (gBtlWork->unk_0F4 == 2) {
        gBtlWork->unk_0F8--;
    }
}
void func_0807E1A0(void) {
    gUnk_02034AA8 = 17;
}
void func_0807E1AC(void) {
    gUnk_02034AA8 = 18;
}
void func_0807E1B8(void) {
    gUnk_02034AA8 = 19;
}
void func_0807E1C4(void) {
    gUnk_02034AA8 = 21;
}
void func_0807E1D0(void) {
    gUnk_02034AA8 = 22;
}
void func_0807E1DC(void) {
    gUnk_02034AA8 = 23;
}
void func_0807E1E8(void) {
    gUnk_02034AA8 = 24;
}

void func_0807E1F4(void) {
    gUnk_02034AA4 = 1;
}

void func_0807E200(void) {
    gUnk_02034AA4 = 2;
}

void func_0807E20C(void) {
    gUnk_02034AA4 = 3;
}

void func_0807E218(void) {
    gUnk_02034AA4 = 4;
}

void func_0807E224(void) {
    gUnk_02034AA4 = 5;
}

void func_0807E230(void) {
    gUnk_02034AA4 = 8;
}

void func_0807E23C(void) {
    gUnk_02034AA4 = 6;
}

void func_0807E248(void) {
    gUnk_02034AA4 = 7;
}

void func_0807E254(void) {
    gUnk_02034AA4 = 9;
}

void func_0807E260(void) {
    gUnk_02034AA4 = 10;
}

void func_0807E26C(void) {
    gUnk_02034AA4 = 11;
}

void func_0807E278(void) {
    gUnk_02034AA4 = 12;
}

void func_0807E284(void) {
    gUnk_02034AA4 = 13;
}

void func_0807E290(void) {
    gUnk_02034AA4 = 0;
}

u8 func_0807E29C(void) {
    if (gUnk_02034AAC != 0) {
        if (gUnk_02034AAC->unk_78 & 0x100000) {
            return 1;
        }
    }

    return 0;
}

s32 func_0807E2BC(void) {
    CardDef* d;

    if (gUnk_02034AAC != 0) {
        if (!(gUnk_02034AAC->unk_78 & 0x1100000)) {
            d = gUnk_02034AAC->cardDef;

            if (d->unk_2A == 3) {
                return d->unk_24 + 0xFFFF;
            }

            return d->unk_24;
        }
    }

    return 145;
}

void func_0807E2F4(void) {
    if (gUnk_02034AAC != 0) {
        if ((gUnk_02034AAC->unk_78 & 0x1000044) == 0x1000044) {
            gUnk_02039DD4->unk_0E8 = 1;
        } else {
            gUnk_02039DD4->unk_0E8 = 0;
        }
    } else {
        gUnk_02039DD4->unk_0E8 = 0;
    }
}

u8 func_0807E33C(void) {
    return gUnk_02039DD4->unk_0F0;
}

u8 func_0807E34C(void) {
    if (gUnk_02034AAC != 0) {
        return gUnk_02034AAC->unk_78 & 2;
    }

    return 0;
}

static void card_2(CardDisplayWork* p);

TaskDesc gUnk_09EE496C = {
    "card",
    (TaskInitFunc)func_0807BC24,
    (TaskUpdateFunc)func_0807BD64,
    (TaskFunc)card_2,
    (TaskFunc)func_0807C2E0,
    0xA8,
};

TaskDesc gTaskDescCardNotHave = {
    "card_not_have",
    (TaskInitFunc)func_0807BC24,
    (TaskUpdateFunc)func_0807BD64,
    (TaskFunc)card_not_have_2,
    (TaskFunc)func_0807C2E0,
    0xA8,
};

TaskDesc gTaskDescCardReload = {
    "card_reload",
    (TaskInitFunc)card_reload_0,
    (TaskUpdateFunc)card_reload_1,
    (TaskFunc)card_reload_2,
    (TaskFunc)card_reload_3,
    0xA8,
};
