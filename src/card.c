#include "macros.h"
#include "card.h"
#include "game.h"

void* TaskCreate(void* a, void* desc, void* args);
void EwramFree(void* p);
void func_08085290(u16 a);
void func_080938F8(u16 a);
u16 func_080857D4(u8 slot);
u8 func_08065B6C(void* a, void* b);
u16 GetRandom(void);
u16 func_08085770(u8 index);
void func_08085788(u8 index, u16* src);
void func_08085160(void);
void func_080AB228(void);
void func_080AB22C(u8 a);
void func_080AB334(u8 a);
void func_080AB4AC(u8 a);
void* EwramAlloc(s32 size);
void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void func_08084458(u16 a);
u16 func_08093B38(void);
u16 func_08093B08(u16 a);
u16 func_08096C38(u16* a, u16 b);
u16 func_08096CCC(void);
u8 func_0807CE68(UnkStruct_02034AAC* p);
void func_0807C39C(UnkStruct_02034AAC* p);
void func_0807C33C(UnkStruct_02034AAC* p);
UnkStruct_0808E890* func_08000C8C(void* node);
UnkStruct_0808E890* func_08000CD4(void* node);
void TaskPoolUpdate(void* pool);
void func_0808DE28(u8 a);
u8 func_080609AC(u16 a);
s32 func_0808C8D0(s32 a);
void func_08065ACC(void* a, s32 b);
void func_080AB1F8(u8 a, u16 b);
void func_080AB964(void);
void func_080AB968(void);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
u32 GetBgCharBase(s32 bg);
void* memcpy(void* dst, const void* src, unsigned long n);
void CpuSet(void* src, void* dst, u32 ctrl);
u16 func_080858B8(s32 index);
void func_08085A58(s32 index, u16* dst);
u8 func_080A42C8(void);
s32 func_080A40EC(u64* src);
s32 func_080A4D7C(u64* src);
UnkStruct_080038C8* func_080038C8(s32 size);
void func_080038E4(UnkStruct_080038C8* a, void* b, void* c);
void m4aSongNumStart(u16 n);

u8 func_080782AC(UnkStruct_02034AAC** p, u8 n) {
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
    gUnk_02039B84->unk_068 &= ~0x80;
    gUnk_02039B84->unk_068 &= ~0x100;
    gUnk_02039B84->unk_068 &= ~0x200;
    gUnk_02039B84->unk_068 &= ~0x400;
}

#ifdef NON_MATCHING
void func_08078330(CardSlot* slots, s32 deckIndex) {
    u16* buf;
    u16 zero[1];
    u16 n;
    u16 i;

    n = func_080858B8(deckIndex);
    buf = EwramAlloc(n * 2);
    zero[0] = 0;
    CpuSet(zero, buf, n | 0x1000000);
    func_08085A58(deckIndex, buf);

    for (i = 0; i < n; i++) {
        slots[i].unk_06 = 0;
        slots[i].unk_07 = 0;
        slots[i].unk_0A = 0;
        slots[i].unk_00 = buf[i];
        slots[i].unk_04 = i;
        slots[i].unk_09 = 0;
    }

    if (deckIndex == 0) {
        slots[n].unk_06 = 0;
        slots[n].unk_07 = 0;
        slots[n].unk_0A = 0;
        slots[n].unk_00 = 0xFFFE;
        slots[n].unk_04 = n;
        slots[n].unk_09 = 0;
    }

    EwramFree(buf);
}
#else
INCLUDE_ASM("card/func_08078330.s");
#endif

void func_080783C0(CardSlot* slots) {
    u16 n;
    u16 i;

    n = gUnk_09041FA0.unk_DC;

    for (i = 0; i < n; i++) {
        slots[i].unk_06 = 0;
        slots[i].unk_07 = 0;
        slots[i].unk_0A = 0;
        slots[i].unk_00 = gUnk_09041F70[gUnk_09041FA0.cards[i]];
        slots[i].unk_04 = i;
        slots[i].unk_09 = 0;
    }

    slots[n].unk_06 = 0;
    slots[n].unk_07 = 0;
    slots[n].unk_0A = 0;
    slots[n].unk_00 = 0xFFFE;
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

INCLUDE_ASM("card/func_080784BC.s");

INCLUDE_ASM("card/func_080785B8.s");

INCLUDE_ASM("card/func_08078754.s");

INCLUDE_ASM("card/func_080787B8.s");

u16 func_0807885C(UnkStruct_08078754* w, u8 b) {
    CardSlot* c;
    u16 count;
    u16 i;
    u16 n;

    n = w->unk_A8[b];
    count = 0;

    for (i = 0; i < n; i++) {
        c = w->unk_44[b];

        if (c[i].unk_0A == 0) {
            if (c[i].unk_00 != 0xFFFE) {
                if (gCardDefs[c[i].unk_00 & CARD_ID_MASK].unk_2A == 0) {
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
        if (w->unk_44[b][i].unk_07 == 0) {
            w->unk_44[b][i].unk_08 = 0;
        }
    }
}

INCLUDE_ASM("card/func_08078914.s");

INCLUDE_ASM("card/func_080789E4.s");

INCLUDE_ASM("card/func_08078BB4.s");

INCLUDE_ASM("card/func_08078D98.s");

INCLUDE_ASM("card/func_08078E34.s");

void func_080791C0(void) {
    if (gUnk_02039B84->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 0x30) {
            if (gUnk_02034A98->unk_A5 != 0) {
                gUnk_02034A98->unk_A5 -= gUnk_02039DD4->unk_0C2;
            }

            gUnk_02039B9C->unk_0F8--;
        }
    }
}

INCLUDE_ASM("card/func_08079218.s");

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

INCLUDE_ASM("card/func_080792F4.s");

INCLUDE_ASM("card/func_0807A620.s");

INCLUDE_ASM("card/func_0807A75C.s");

INCLUDE_ASM("card/func_0807A80C.s");

INCLUDE_ASM("card/func_0807ABC8.s");

INCLUDE_ASM("card/func_0807AE78.s");

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

#ifdef NON_MATCHING
void func_0807B410(void* pool) {
    UnkStruct_0807B410* t;
    u32 v;

    t = (UnkStruct_0807B410*)func_08000C8C(&gUnk_02039B84->unk_080);

    while (t != 0) {
        v = t->unk_00;

        if (v <= 40) {
            if (v >= 32) {
                TaskCreate(pool, gUnk_09EE4A14, &v);
                break;
            }
        }

        t = (UnkStruct_0807B410*)func_08000CD4(&t->unk_B8);
    }
}
#else
INCLUDE_ASM("card/func_0807B410.s");
#endif

void func_0807B458(void) {
}

void func_0807B45C(void) {
    gUnk_02039B84->unk_0F4 = gUnk_02039DD4->unk_0CC;
}

INCLUDE_ASM("card/func_0807B478.s");

void func_0807B728(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

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

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

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

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

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

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

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

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

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

INCLUDE_ASM("card/func_0807B98C.s");

INCLUDE_ASM("card/func_0807BA54.s");

INCLUDE_ASM("card/func_0807BC08.s");

void func_0807C2EC(UnkStruct_02034AAC* p) {
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

void func_0807C33C(UnkStruct_02034AAC* p) {
    CardDef* d;
    void* tiles;
    void* pal;
    u32 f;

    f = p->unk_78 & 2;

    if (f != 0) {
        p->unk_00 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_04 = LoadObjTiles(gUnk_08F709B0[p->unk_46].unk_10, 640);
    } else {
        d = p->unk_48;
        tiles = d->unk_04;
        pal = d->unk_08;
        p->unk_00 = LoadObjTiles(tiles, 512);
        p->unk_14 = LoadObjPalette(pal, 32);
        p->unk_04 = 0;
    }
}

INCLUDE_ASM("card/func_0807C39C.s");

INCLUDE_ASM("card/func_0807CC2C.s");

INCLUDE_ASM("card/func_0807CD48.s");

INCLUDE_ASM("card/func_0807CE68.s");

INCLUDE_ASM("card/func_0807D0F4.s");

INCLUDE_ASM("card/func_0807D380.s");

INCLUDE_ASM("card/func_0807D4B8.s");

INCLUDE_ASM("card/func_0807E018.s");

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
            d = gUnk_02034AAC->unk_48;

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

INCLUDE_ASM("card/func_0807E368.s");

INCLUDE_ASM("card/sub_0807E4C8.s");

INCLUDE_ASM("card/sub_0807E66C.s");

INCLUDE_ASM("card/func_0807E724.s");

INCLUDE_ASM("card/func_0807FA44.s");

void func_08080228(void) {
    if (gUnk_02039B84->unk_0F4 == 0x30) {
        if (gUnk_02034AAC->unk_A5 != 0) {
            gUnk_02034AAC->unk_A5 -= gUnk_02039DD4->unk_0C2;
        }

        gUnk_02039B84->unk_0F8--;
    }
}

#ifdef NON_MATCHING
void func_08080268(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* q;
    u8 d;
    u8 i;

    d = gUnk_02039DD4->unk_0C2;

    if (gUnk_02039B84->unk_0F4 == 0x30) {
        if (w->unk_BA != 0) {
            for (i = 0; i < 3; i++) {
                q = w->unk_28[i];

                if (q->unk_A5 > d) {
                    q->unk_A5 -= d;
                    break;
                }

                d -= q->unk_A5;
                q->unk_A5 = 0;
            }
        }

        gUnk_02039B84->unk_0F8--;
    }
}
#else
INCLUDE_ASM("card/func_08080268.s");
#endif

INCLUDE_ASM("card/func_080802D8.s");

INCLUDE_ASM("card/func_08080994.s");

INCLUDE_ASM("card/func_08080EB4.s");

INCLUDE_ASM("card/func_08081760.s");

u8 func_08081838(void) {
    return gUnk_02039DD4->unk_0D4;
}

u8 func_08081848(void) {
    return gUnk_02039DD4->unk_0C2;
}

s32 func_08081858(void) {
    if (gUnk_02034AAC != 0) {
        return gUnk_02034AAC->unk_48->unk_24;
    }

    return 145;
}

INCLUDE_ASM("card/func_08081870.s");

INCLUDE_ASM("card/func_08082BF8.s");

INCLUDE_ASM("card/func_08082F24.s");

void func_080838E8(void) {
}

void func_080838EC(void) {
    gUnk_02039DDC = 7;
}

void func_080838F8(void) {
}

void func_080838FC(void) {
}

void func_08083900(u8 a) {
    gUnk_02039DDC = 1;
    gUnk_02039DD8 = a;
}

void func_08083914(void) {
    gUnk_02039DDC = 2;
}

INCLUDE_ASM("card/func_08083920.s");

INCLUDE_ASM("card/func_08083B20.s");

INCLUDE_ASM("card/func_08083C94.s");

void func_08083D68(void) {
    EwramFree(gUnk_0203A854);
}

#ifdef NON_MATCHING
void func_08083D7C(void) {
    s32 i;
    u16* p;

    gUnk_0203A850 = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        gUnk_0203A850->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 20; i++) {
        gUnk_0203A850->unk_C6[i] = 0;
    }

    p = &gUnk_0203A850->unk_DA;
    *p++ = 0;
    *p = 0;
}
#else
INCLUDE_ASM("card/func_08083D7C.s");
#endif

void func_08083DD4(void) {
    EwramFree(gUnk_0203A850);
}

u16 func_08083DE8(void) {
    return gUnk_0203A850->unk_DC;
}

u16 func_08083DF8(u8 slot) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

#ifdef NON_MATCHING
u16 func_08083E54(u8 mode) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    switch (mode) {
    case 0:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                    count++;
                }
            }
        }
        break;
    case 3:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A == 3) {
                    count++;
                }
            }
        }
        break;
    }

    return count;
}
#else
INCLUDE_ASM("card/func_08083E54.s");
#endif

INCLUDE_ASM("card/sub_08083EFC.s");

void func_08083FE0(void) {
    u16 i;

    for (i = 0; i < 999; i++) {
        gCardCollection[i] = CARD_ID_MASK;
    }

    gCardCount = 911;
}

u16 CountCardsById(u16 cardId) {
    u16 i;
    u16 count;

    i = 0;
    count = 0;

    for (; i < gCardCount; i++) {
        if ((gCardCollection[i] & CARD_ID_MASK) == cardId) {
            count++;
        }
    }
    
    return count;
}

s16 func_08084068(u16 cardId) {
    u16 i;

    i = 0;

    if (CountCardsById(cardId) > 98) {
        return -1;
    }

    while (gCardCollection[i] != CARD_ID_MASK) {
        i++;

        if (i == gCardCount) {
            return -1;
        }
    }

    if (gCardDefs[cardId & CARD_ID_MASK].unk_1E & 8) {
        return -1;
    }

    gCardCollection[i] = cardId;

    return i;
}

s32 func_080840E4(void) {
    s32 count;
    s32 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            count++;
        }
    }

    if (count > 0) {
        return 0;
    }

    return 1;
}

INCLUDE_ASM("card/func_08084124.s");

INCLUDE_ASM("card/func_08084458.s");

#ifdef NON_MATCHING
u16 func_08084BAC(void) {
    u16 count;
    u16 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            count++;
        }
    }

    return count;
}
#else
INCLUDE_ASM("card/func_08084BAC.s");
#endif

INCLUDE_ASM("card/func_08084BF0.s");

INCLUDE_ASM("card/func_08084D78.s");

INCLUDE_ASM("card/func_08084E50.s");

u16 func_08084FAC(u8 slot) {
    u16 count;
    u16 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            if (gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

void func_0808500C(u8 mode, u16* out) {
    u16 mask;
    u16 i;

    mask = 0;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;

    switch (mode) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    case 3:
        mask = 0x7000;
        break;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            if (!(gCardCollection[i] & mask)) {
                out[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_2A]++;
            }
        }
    }
}

INCLUDE_ASM("card/func_080850B0.s");

INCLUDE_ASM("card/func_08085160.s");

INCLUDE_ASM("card/func_08085290.s");

INCLUDE_ASM("card/func_08085374.s");

s32 func_080856DC(void) {
    Deck* deck;
    s32 count;
    s32 i;

    count = 0;
    deck = GetActiveDeck();

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (gCardCollection[deck->cards[i]] & 0x8000) {
                count++;
            }
        }
    }

    if (gDecks[gActiveDeck].unk_DC == count) {
        return 0;
    }

    return 1;
}

Deck* GetActiveDeck(void) {
    return &gDecks[gActiveDeck];
}

Deck* GetDeck(u8 index) {
    return &gDecks[index];
}

u16 func_08085770(u8 index) {
    return gDecks[index].unk_DA;
}

INCLUDE_ASM("card/func_08085788.s");

u8* func_080857BC(u8 index) {
    return gDecks[index].unk_C6;
}

u16 func_080857D4(u8 slot) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = GetActiveDeck()->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

u16 func_08085844(u8 slot, u8 deckIndex) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = GetDeck(deckIndex)->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

INCLUDE_ASM("card/func_080858B8.s");

INCLUDE_ASM("card/func_080859A0.s");

INCLUDE_ASM("card/func_08085A58.s");

u16 func_08085B38(u8 index) {
    return gDecks[index].unk_DC;
}

void SetActiveDeckIndex(u8 index) {
    gActiveDeck = index;
}

u16 func_08085B5C(u16 index) {
    return gCardDefs[gCardCollection[index] & CARD_ID_MASK].unk_1C;
}

u8 func_08085B84(u16 index) {
    return gCardDefs[gCardCollection[index] & CARD_ID_MASK].unk_2A;
}

s32 func_08085BAC(void) {
    Deck* deck;
    s32 a;
    s32 b;
    s32 i;

    a = 0;
    b = 0;
    deck = GetActiveDeck();

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (func_08085B84(deck->cards[i]) != 2) {
                if (func_08085B84(deck->cards[i]) != 3) {
                    a++;
                }
            }
        }
    }

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (gCardCollection[deck->cards[i]] & 0x8000) {
                b++;
            }
        }
    }

    if (b == a) {
        return 1;
    }

    return 0;
}

void func_08085C3C(void) {
    gActiveDeck = 0;
    func_08083FE0();
    func_08085160();

    if (gUnk_03006C10 & 0x10) {
        func_080AB228();
        func_080AB22C(2);
        func_080AB334(1);
        func_080AB4AC(0);
    } else {
        func_080AB880();
        func_080AB8E4();
        func_080AB964();
        func_080AB968();
    }

    func_08085788(0, gUnk_09EE4AC8);
    func_08085788(1, gUnk_09EE4AD6);
    func_08085788(2, gUnk_09EE4AE4);
}

void func_08085CB0(void) {
    gActiveDeck = 0;
    func_08083FE0();
    func_08085160();
    func_080AB228();
    func_080AB334(0);
    func_080AB22C(1);
    func_080AB4AC(2);
    func_08085788(0, gUnk_09EE4AC8);
    func_08085788(1, gUnk_09EE4AD6);
    func_08085788(2, gUnk_09EE4AE4);
}

INCLUDE_ASM("card/_08085D04.s");

u8 GetActiveDeckIndex(void) {
    return gActiveDeck;
}

INCLUDE_ASM("card/func_08085FB0.s");

INCLUDE_ASM("card/func_08087B98.s");

INCLUDE_ASM("card/func_0808B3DC.s");

INCLUDE_ASM("card/func_0808C3DC.s");

INCLUDE_ASM("card/func_0808C60C.s");

s32 func_0808C8D0(s32 a) {
    u32 i;

    for (i = 0; i < 950; i++) {
        if (gCardDefs[i].unk_1C == a) {
            return i;
        }

        if (gCardDefs[i].unk_1C + 143 == a) {
            return i | 0x8000;
        }
    }
}

void func_0808C90C(u8* work) {
    UnkStruct_0808E890* t;

    t = func_08000C8C(&work[0x7F0]);

    while (t != 0) {
        t->unk_4A = 1;
        t = func_08000CD4(&t->unk_2C);
    }

    TaskPoolUpdate(&work[0x7C8]);
}

void func_0808C940(UnkStruct_0808C940* w, s16 n) {
    w->unk_8AE = n / 3;

    if (n % 3 != 0) {
        w->unk_8AE = n / 3 + 1;
    }
}

void func_0808C974(UnkStruct_0808C940* w) {
    s32 v;

    v = 0x5400 / (w->unk_8AE - 4);
    w->unk_854 = v * (w->unk_8AC - 4) + 0x2800;

    if (w->unk_854 > 0x7C00) {
        w->unk_854 = 0x7C00;
    }

    if (w->unk_854 <= 0x27FF) {
        w->unk_854 = 0x2800;
    }
}

INCLUDE_ASM("card/func_0808C9CC.s");

INCLUDE_ASM("card/func_0808CA78.s");

INCLUDE_ASM("card/func_0808CBB4.s");

INCLUDE_ASM("card/func_0808CC58.s");

INCLUDE_ASM("card/func_0808CDE8.s");

INCLUDE_ASM("card/func_0808D0A4.s");

INCLUDE_ASM("card/func_0808D16C.s");

INCLUDE_ASM("card/func_0808D258.s");

INCLUDE_ASM("card/func_0808D594.s");

void func_0808D6C4(u8* work) {
    func_08065ACC(&work[0x38], 8);
    func_08065ACC(&work[0x78], 8);
    func_08065ACC(&work[0xB8], 8);
    work[0x8C2] = func_08065B6C(func_080857BC(0), &work[0x38]);
    work[0x8C3] = func_08065B6C(func_080857BC(1), &work[0x78]);
    work[0x8C4] = func_08065B6C(func_080857BC(2), &work[0xB8]);
}

INCLUDE_ASM("card/func_0808D73C.s");

void func_0808D7EC(u8* work, u16 index) {
    CardDef* d;

    d = &gCardDefs[index];
    work[0x8C6] = func_08065B6C(gUnk_09EE8F48[d->unk_1C], &work[0x1E8]);
}

INCLUDE_ASM("card/func_0808D828.s");

void func_0808DB04(void** p) {
    if (p[10] != 0) {
        ReleaseObjTiles(p[10]);
        p[10] = 0;
    }

    if (p[7] != 0) {
        ReleaseObjTiles(p[7]);
        ReleaseObjPalette(p[12]);
        ReleaseObjTiles(p[8]);
        ReleaseObjPalette(p[13]);

        if (p[9] != 0) {
            ReleaseObjTiles(p[9]);
            p[9] = 0;
        }

        p[7] = 0;
        p[12] = 0;
        p[8] = 0;
        p[13] = 0;
    }
}

INCLUDE_ASM("card/func_0808DB50.s");

INCLUDE_ASM("card/func_0808DD20.s");

INCLUDE_ASM("card/func_0808DDD0.s");

void func_0808DE28(u8 a) {
    u8 d[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        d[0] = a / 10;
        d[1] = a - d[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(d[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(d[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}

u32 func_0808DEB8(u16* data) {
    u32 sum;
    u16* p;
    s32 i;

    sum = 0;
    p = data;
    i = 9;

    do {
        sum += *p++;
    } while (--i >= 0);

    return sum;
}

INCLUDE_ASM("card/func_0808DED0.s");

void func_0808E2F0(UnkStruct_0808DB04* w) {
    u16 i;

    if (w->unk_4D4 != 0) {
        for (i = 0; i < w->unk_898; i++) {
            EwramFree(w->unk_4D4[i].unk_1C);
        }

        EwramFree(w->unk_4D4);
        w->unk_4D4 = 0;
    }
}

void func_0808E344(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}

INCLUDE_ASM("card/func_0808E364.s");

s32 func_0808E750(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gUnk_02039BB0.unk_0FA) {
        TaskCreate(&work[0x7DC], gUnk_09EE7FA8, &work[0x8C9]);
        m4aSongNumStart(105);

        return 0;
    }

    return 1;
}

s32 func_0808E79C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(105);
        TaskCreate(&work[0x7DC], gUnk_09EE7FC0, &work[0x8C9]);

        return 0;
    }

    return 1;
}

INCLUDE_ASM("card/func_0808E7D8.s");

s32 func_0808E890(u8* work) {
    UnkStruct_0808E890* t;

    t = func_08000C8C(&work[0x7F0]);

    while (t != 0) {
        if (t->unk_22 == *(s16*)&work[0x884]) {
            if (t->unk_24 == *(s16*)&work[0x886]) {
                return 1;
            }
        }

        t = func_08000CD4(&t->unk_2C);
    }

    return 0;
}

INCLUDE_ASM("card/func_0808E8E8.s");

INCLUDE_ASM("card/func_0808EA0C.s");

INCLUDE_ASM("card/func_0808EF80.s");

INCLUDE_ASM("card/func_0808F0C0.s");

INCLUDE_ASM("card/func_0808FA8C.s");

INCLUDE_ASM("card/func_08090170.s");

INCLUDE_ASM("card/func_08091234.s");

INCLUDE_ASM("card/func_08091B38.s");

INCLUDE_ASM("card/func_08093384.s");

INCLUDE_ASM("card/func_08093838.s");

INCLUDE_ASM("card/func_080938F8.s");

s32 func_08093AC8(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        gUnk_0203A8C0[a]--;
        return 1;
    }

    return 0;
}

s32 func_08093AE8(void) {
    func_080938F8(GetRandom() % 270);
}

u16 func_08093B08(u16 a) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = a; i < a + 10; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

u16 func_08093B38(void) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = 0; i < 220; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

u16 func_08093B58(void) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = 0; i < 27; i++) {
        sum += gUnk_0203A8C0[i * 10];
    }

    return sum;
}

void func_08093B78(void* a, void* b) {
    TaskCreate(a, gUnk_09EE4BC8, b);
}

void func_08093B8C(void) {
    u16 i;

    for (i = 0; i < 270; i++) {
        gUnk_0203A8C0[i] = 0;
    }
}

void func_08093BB4(void) {
    func_08093B8C();

    if (!(gUnk_03006C10 & 8)) {
        func_080938F8(191);
    }
}

u8 func_08093BD4(void) {
    return gUnk_02034ACC;
}

void func_08093BE0(void) {
    gUnk_02034ACC = 1;
}

void func_08093BEC(u32 a) {
    gUnk_02034AD0 = a;
}

u32 func_08093BF8(void) {
    return gUnk_02034AD0;
}

void func_08093C04(void) {
    gUnk_02034AD0 = 0;
    gUnk_02034ACC = 0;
}

void* func_08093C18(u16 a) {
    return gUnk_09EF7048[a];
}

u8 func_08093C28(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("card/func_08093C44.s");

INCLUDE_ASM("card/func_08093D28.s");

INCLUDE_ASM("card/func_08093E34.s");

INCLUDE_ASM("card/func_08093F1C.s");

s32 func_08094CB0(s32* p) {
    if (p[19] >= -4096) {
        if (p[19] <= 0x10000) {
            if (p[20] >= -5120) {
                if (p[20] <= 0xC000) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

INCLUDE_ASM("card/func_08094CE4.s");

INCLUDE_ASM("card/func_08094DA8.s");

INCLUDE_ASM("card/func_08096638.s");

INCLUDE_ASM("card/func_08096700.s");

INCLUDE_ASM("card/func_08096C38.s");

u16 func_08096CCC(void) {
    u16 i;

    do {
        i = GetRandom() % 10;
    } while (gUnk_090359FC[i] <= GetRandom() % 100);

    return i;
}

#ifdef NON_MATCHING
u16 func_08096D0C(u16 a) {
    u32 f;

    f = gUnk_02039BB0.unk_008 & 8;

    if (f) {
        return func_08096C38(gUnk_090360BC[a].unk_00, gUnk_090360BC[a].unk_04);
    } else {
        return func_08096C38(gUnk_09035DCC[a].unk_00, gUnk_09035DCC[a].unk_04);
    }
}
#else
INCLUDE_ASM("card/func_08096D0C.s");
#endif

#ifdef NON_MATCHING
u16 func_08096D48(u16 a) {
    u16 base;
    u16 off;

    off = 0;

    if (gUnk_02039BB0.unk_008 & 8) {
        base = func_08096C38(gUnk_090360BC[a].unk_00, gUnk_090360BC[a].unk_04);
    } else {
        base = func_08096C38(gUnk_09035DCC[a].unk_00, gUnk_09035DCC[a].unk_04);
    }

    if (base != 0xFFFF) {
        do {
            off = func_08096CCC();
        } while (gUnk_0203A8C0[base + off] == 9);
    }

    return base + off;
}
#else
INCLUDE_ASM("card/func_08096D48.s");
#endif

void func_08096DB0(void* a, void* b) {
    TaskCreate(a, gUnk_09EE75F0, b);
}

INCLUDE_ASM("card/func_08096DC4.s");

INCLUDE_ASM("card/func_08096F08.s");

INCLUDE_ASM("card/func_080978B0.s");

INCLUDE_ASM("card/func_0809797C.s");

INCLUDE_ASM("card/func_08098014.s");

INCLUDE_ASM("card/func_08098598.s");

void func_08098670(UnkStruct_08098670* p, u16 a) {
    if (p->unk_00 != 0) {
        DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_18, p->unk_00, p->unk_0C, 0, a, 10);
    }

    if (p->unk_04 != 0) {
        DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_1C, p->unk_04, p->unk_10, 0, a, 9);
    }

    if (p->unk_08 != 0) {
        DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_20, p->unk_08, p->unk_14, 0, a, 8);
    }
}

UnkStruct_080038C8* func_080986FC(u8 a) {
    UnkStruct_080038C8* obj;

    if (a != 0) {
        obj = func_080038C8(256);
        func_080038E4(obj, gUnk_09EF1198[1], gUnk_0950C478);
        RequestDma3Copy(&obj->unk_00[a * 128], (void*)(0x06010000 + (obj->unk_06 + 4) * 32), 128);
        RequestDma3Copy(&obj->unk_00[0x500], (void*)(0x06010000 + obj->unk_06 * 32), 128);
    } else {
        obj = func_080038C8(128);
        func_080038E4(obj, gUnk_09EF1198[0], gUnk_0950C478);
    }

    return obj;
}

void func_08098778(void** p) {
    if (p[0] != 0) {
        ReleaseObjTiles(p[0]);
    }

    if (p[1] != 0) {
        ReleaseObjTiles(p[1]);
    }

    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
    }

    if (p[3] != 0) {
        ReleaseObjPalette(p[3]);
    }

    if (p[4] != 0) {
        ReleaseObjPalette(p[4]);
    }

    if (p[5] != 0) {
        ReleaseObjPalette(p[5]);
    }
}

INCLUDE_ASM("card/func_080987C0.s");

INCLUDE_ASM("card/func_080991CC.s");

INCLUDE_ASM("card/func_08099928.s");

INCLUDE_ASM("card/func_0809A4E0.s");

void func_0809B644(void* pool, u16 x, u16 y, u16 z, u8 idx) {
    s32 args[4];

    if (gUnk_02039DD4 != 0) {
        if (gUnk_02039DD4->unk_0DA[0] <= 4) {
            if (gUnk_02039DD4->unk_0D6 == 0) {
                args[0] = (s16)x << 8;
                args[1] = (s16)y << 8;
                args[2] = (s16)z << 8;
                args[3] = gUnk_09036210[idx] + GetRandom() % 9;
                TaskCreate(pool, gUnk_09EE778C, args);
                gUnk_02039DD4->unk_0D6++;
            }
        }
    }
}

INCLUDE_ASM("card/func_0809B6D0.s");

void func_0809C9A4(UnkStruct_0809C9A4* p) {
    p->unk_4A = (gSineTable[p->unk_4E] * p->unk_50) >> 8;
    p->unk_4C = ((-gSineTable[p->unk_4E + 64] * p->unk_50) >> 8) + 160;
}

s32 func_0809C9F4(UnkStruct_0809C9A4* p) {
    if (p->unk_4A >= 0) {
        if (p->unk_4A <= 240) {
            if (p->unk_4C >= 0) {
                if (p->unk_4C <= 160) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

INCLUDE_ASM("card/func_0809CA1C.s");

INCLUDE_ASM("card/func_0809CAC8.s");

INCLUDE_ASM("card/func_0809D124.s");

#ifdef NON_MATCHING
u8 func_0809D280(u8* s) {
    u8 n;
    u8 c;

    n = 0;

    if (s == 0) {
        return 0;
    }

    c = *s;
    s++;

    if (c != 0) {
        do {
            c = *s;

            if (c != 0) {
                n++;
            }

            s++;
        } while (c != 0);
    }

    return n + 1;
}
#else
INCLUDE_ASM("card/func_0809D280.s");
#endif

INCLUDE_ASM("card/func_0809D2B0.s");

INCLUDE_ASM("card/func_0809D458.s");

INCLUDE_ASM("card/func_0809E7A4.s");

void func_080A0944(u16 a, u16* p) {
    u16 q;
    u16 r;

    q = a / 10;
    r = a - q * 10;
    p[1] = q;
    p[2] = r;
}

void func_080A096C(u16 a, u16* p) {
    u16 h;
    u16 t;
    u16 o;

    h = a / 100;
    t = a / 10 - h * 10;
    o = a - h * 100 - t * 10;
    p[0] = h;
    p[1] = t;
    p[2] = o;
}

INCLUDE_ASM("card/func_080A09C0.s");

s32 func_080A151C(void) {
    if (gUnk_02039BB0.unk_108 >= gUnk_09037FBA[gUnk_02039BB0.unk_178]) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("card/func_080A1554.s");

INCLUDE_ASM("card/func_080A1B4C.s");

void* func_080A2334(u16 a, u8 b) {
    if (b < gUnk_09EE7D84[a]->unk_04) {
        return gUnk_09EE7D84[a]->unk_00[b];
    }

    return 0;
}

INCLUDE_ASM("card/func_080A235C.s");

void func_080A324C(UnkStruct_080A324C* p) {
    s32 i;

    for (i = 0; i < 270; i++) {
        p->unk_001[i] = gUnk_0203A8C0[i];
    }

    for (i = 0; i < 999; i++) {
        p->unk_110[i] = gCardCollection[i];
    }

    for (i = 0; i < 3; i++) {
        memcpy(&p->unk_8E0[i], &gDecks[i], sizeof(Deck));
    }

    p->unk_8DE = gCardCount;
    p->unk_000 = GetActiveDeckIndex();
}

#ifdef NON_MATCHING
void func_080A32DC(UnkStruct_080A324C* p) {
    u16 i;

    for (i = 0; i < 270; i++) {
        gUnk_0203A8C0[i] = p->unk_001[i];
    }

    for (i = 0; i < 999; i++) {
        gCardCollection[i] = p->unk_110[i];
    }

    for (i = 0; i < 3; i++) {
        memcpy(&gDecks[i], &p->unk_8E0[i], sizeof(Deck));
    }

    gCardCount = p->unk_8DE;
    SetActiveDeckIndex(p->unk_000);
}
#else
INCLUDE_ASM("card/func_080A32DC.s");
#endif

INCLUDE_ASM("card/func_080A3370.s");

s32 func_080A40EC(u64* src) {
    if (gUnk_02034AFC != 0) {
        gUnk_02034AFC->unk_10C = *src;
        gUnk_02034AFC->unk_14E = 1;

        return 1;
    }

    return 0;
}

void func_080A411C(void* pool, u32 a, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_07 = 0;

    if (gUnk_09EE8008[b].unk_00 == 62) {
        if (gUnk_09EE8008[b].unk_10 & 2) {
            TaskCreate(pool, gUnk_09EE8E48, &args);
        } else {
            TaskCreate(pool, gUnk_09EE8E30, &args);
        }
    } else {
        TaskCreate(pool, gUnk_09EE8E18, &args);
    }
}

void func_080A4188(void* pool, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = 0;
    args.unk_04 = b;
    args.unk_07 = 2;

    if (gUnk_09EE8008[b].unk_10 & 2) {
        TaskCreate(pool, gUnk_09EE8E48, &args);
    } else {
        TaskCreate(pool, gUnk_09EE8E30, &args);
    }
}

INCLUDE_ASM("card/func_080A41F0.s");

void func_080A4234(void* pool, u32 a, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_07 = 1;

    if (func_080A42C8() != 0) {
        if ((u8)func_080A40EC((u64*)&args) == 0) {
            func_080A4D7C((u64*)&args);
        }
    } else if (gUnk_09EE8008[b].unk_00 == 62) {
        TaskCreate(pool, gUnk_09EE8E30, &args);
    } else {
        TaskCreate(pool, gUnk_09EE8E18, &args);
    }
}

void func_080A42B4(void) {
    gUnk_0203A9D4 = 0;
    gUnk_0203A9D8 = 0;
}

u8 func_080A42C8(void) {
    return gUnk_0203A9D4;
}

u8 func_080A42D4(void) {
    return gUnk_0203A9D8;
}

INCLUDE_ASM("card/func_080A42E0.s");

s32 func_080A4D7C(u64* src) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_10C = *src;
        gUnk_02034B00->unk_145 = 1;

        return 1;
    }

    return 0;
}

INCLUDE_ASM("card/func_080A4DAC.s");

INCLUDE_ASM("card/func_080A5830.s");

INCLUDE_ASM("card/func_080A5C60.s");

INCLUDE_ASM("card/func_080A6B40.s");

INCLUDE_ASM("card/func_080A6EB4.s");

void func_080A6F60(void** p) {
    if (p[9] != 0) {
        ReleaseObjTiles(p[9]);
        p[9] = 0;
    }

    if (p[6] != 0) {
        ReleaseObjTiles(p[6]);
        ReleaseObjPalette(p[10]);
        ReleaseObjTiles(p[7]);
        ReleaseObjPalette(p[11]);

        if (p[8] != 0) {
            ReleaseObjTiles(p[8]);
            p[8] = 0;
        }

        p[6] = 0;
        p[10] = 0;
        p[7] = 0;
        p[11] = 0;
    }
}

INCLUDE_ASM("card/func_080A6FAC.s");

INCLUDE_ASM("card/func_080A7180.s");

INCLUDE_ASM("card/func_080A8C58.s");

INCLUDE_ASM("card/func_080A8EE4.s");

INCLUDE_ASM("card/func_080A97D4.s");

s32 func_080A993C(s32 a) {
    u32 i;

    for (i = 0; i < 950; i++) {
        if (gCardDefs[i].unk_1C == a) {
            return i;
        }
    }
}

INCLUDE_ASM("card/func_080A9968.s");

INCLUDE_ASM("card/func_080A9E40.s");

INCLUDE_ASM("card/func_080AA1F8.s");

INCLUDE_ASM("card/func_080AA3A0.s");

INCLUDE_ASM("card/func_080AA450.s");

void func_080AA634(void** p) {
    if (p[7] != 0) {
        ReleaseObjTiles(p[7]);
        p[7] = 0;
    }

    if (p[4] != 0) {
        ReleaseObjTiles(p[4]);
        ReleaseObjPalette(p[8]);
        ReleaseObjTiles(p[5]);
        ReleaseObjPalette(p[9]);

        if (p[6] != 0) {
            ReleaseObjTiles(p[6]);
            p[6] = 0;
        }

        p[4] = 0;
        p[8] = 0;
        p[5] = 0;
        p[9] = 0;
    }
}

INCLUDE_ASM("card/func_080AA680.s");

void func_080AA6D4(u8 a) {
    u8 d[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        d[0] = a / 10;
        d[1] = a - d[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(d[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(d[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}

u32 func_080AA764(u16* data) {
    u32 sum;
    u16* p;
    s32 i;

    sum = 0;
    p = data;
    i = 9;

    do {
        sum += *p++;
    } while (--i >= 0);

    return sum;
}

INCLUDE_ASM("card/func_080AA77C.s");

INCLUDE_ASM("card/func_080AAA8C.s");

s32 func_080AAC40(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gUnk_02039BB0.unk_0FA) {
        TaskCreate(&work[0x628], gUnk_09EE7FA8, &work[0x70D]);
        m4aSongNumStart(105);

        return 0;
    }

    return 1;
}

INCLUDE_ASM("card/func_080AAC8C.s");

INCLUDE_ASM("card/func_080AAD84.s");

void func_080AAEB0(u8* work, u16 index) {
    CardDef* d;

    d = &gCardDefs[index];
    work[0x70C] = func_08065B6C(gUnk_09EE8F48[d->unk_1C], &work[0x1D8]);
}

void func_080AAEEC(UnkStruct_0808C940* w, s16 n) {
    w->unk_6EE = n / 3;

    if (n % 3 != 0) {
        w->unk_6EE = n / 3 + 1;
    }
}

INCLUDE_ASM("card/func_080AAF20.s");

void func_080AB1F8(u8 a, u16 b) {
    u8 saved;

    saved = GetActiveDeckIndex();
    SetActiveDeckIndex(a);
    func_08085290(b);
    SetActiveDeckIndex(saved);
}

#ifndef VERSION_EU
void func_080AB228(void) {
}
#else
INCLUDE_ASM("card/func_080AB228.s");
#endif

INCLUDE_ASM("card/func_080AB22C.s");

INCLUDE_ASM("card/func_080AB334.s");

INCLUDE_ASM("card/func_080AB4AC.s");

void func_080AB880(void) {
    func_08084458(7);
    func_08084458(6);
    func_08084458(5);
    func_08084458(5);
    func_08084458(4);
    func_08084458(3);
    func_08084458(4);
    func_08084458(3);
    func_08084458(2);
    func_08084458(2);
    func_08084458(1);
    func_08084458(0);
    func_08084458(185);
    func_08084458(386);
    func_08084458(207);
}

void func_080AB8E4(void) {
    func_080AB1F8(0, 0);
    func_080AB1F8(0, 1);
    func_080AB1F8(0, 2);
    func_080AB1F8(0, 3);
    func_080AB1F8(0, 4);
    func_080AB1F8(0, 5);
    func_080AB1F8(0, 6);
    func_080AB1F8(0, 7);
    func_080AB1F8(0, 8);
    func_080AB1F8(0, 9);
    func_080AB1F8(0, 10);
    func_080AB1F8(0, 11);
    func_080AB1F8(0, 12);
    func_080AB1F8(0, 13);
    func_080AB1F8(0, 14);
}

void func_080AB964(void) {
}

INCLUDE_ASM("card/func_080AB968.s");

INCLUDE_ASM("card/func_080ABA80.s");

INCLUDE_ASM("card/func_080ABCA4.s");

INCLUDE_ASM("card/func_080ABED0.s");

INCLUDE_ASM("card/func_080ABEF8.s");

INCLUDE_ASM("card/func_080AC5E8.s");

INCLUDE_ASM("card/func_080AD144.s");

s32 func_080ADD04(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        c0 = d0->unk_1C;
        d1 = p[1]->unk_48;
        c1 = d1->unk_1C;
        d2 = p[2]->unk_48;
        c2 = d2->unk_1C;

        if (d0->unk_2A == 0 && d1->unk_2A == 0 && d2->unk_2A == 0 &&
            c0 != c1 && c0 != c2 && c1 != c2) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADD58(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        d1 = p[1]->unk_48;
        d2 = p[2]->unk_48;

        if (d0->unk_24 != 18 && d1->unk_24 != 18 && d2->unk_24 != 18 &&
            d0->unk_2A == 0 && d1->unk_2A == 0 && d2->unk_2A == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADDA8(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        c0 = d0->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        c2 = p[2]->unk_48->unk_1C;

        if (c0 != c1 && c1 != c2 && c2 != c0) {
            if (d0->unk_2A == 0) {
                if (c1 == 39 && c2 == 40) {
                    return 1;
                }

                if (c1 == 40 && c2 == 39) {
                    return 1;
                }
            }

            if (p[1]->unk_48->unk_2A == 0) {
                if (c0 == 39 && c2 == 40) {
                    return 1;
                }

                if (c0 == 40 && c2 == 39) {
                    return 1;
                }
            }

            if (p[2]->unk_48->unk_2A == 0) {
                if (c1 == 39 && c0 == 40) {
                    return 1;
                }

                if (c1 == 40 && c0 == 39) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

s32 func_080ADE2C(UnkStruct_02034AAC** p, u8 b, u16 c, u16 d, u8 e) {
    if (p[0]->unk_48->unk_1C == c && p[1]->unk_48->unk_1C == d &&
        p[2]->unk_48->unk_2A == e && !(p[2]->unk_48->unk_1E & 4)) {
        return 1;
    }

    return 0;
}

s32 func_080ADE78(UnkStruct_02034AAC** p, u8 b, u16 c, u16 d) {
    if (p[0]->unk_48->unk_1C == c && p[1]->unk_48->unk_1C == d &&
        (p[2]->unk_48->unk_1E & 4)) {
        return 1;
    }

    return 0;
}

s32 func_080ADEAC(UnkStruct_02034AAC** p, u16 c, u8 b) {
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        d1 = p[1]->unk_48;
        d2 = p[2]->unk_48;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (s1 == 0 && s2 == 0 && c0 == c) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADEEC(UnkStruct_02034AAC** p, u16 c, u8 e, u8 b) {
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        d1 = p[1]->unk_48;
        d2 = p[2]->unk_48;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (c0 == c && s1 == e && s2 == s1) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADF30(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        c2 = p[2]->unk_48->unk_1C;

        if (c1 == c2 && c1 == 26 && c0 != 26) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADF60(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;

        if (c0 == 18 && c1 == 30 && p[2]->unk_48->unk_2A == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADF94(UnkStruct_02034AAC** p, u8 b, u16 c) {
    u16 e0;
    u16 e1;

    if (b == 3) {
        e0 = p[0]->unk_48->unk_1E;
        e1 = p[1]->unk_48->unk_1E;

        if ((e0 & 4) && (e1 & 4) && p[2]->unk_48->unk_1C == c) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADFD4(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;

        if (c0 == 25 && c1 == 30) {
            d2 = p[2]->unk_48;

            if (d2->unk_2A == 2 && !(d2->unk_1E & 8)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 func_080AE014(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d1;
    u16 e0;
    u16 e1;

    if (b == 3) {
        e0 = p[0]->unk_48->unk_1E;
        d1 = p[1]->unk_48;
        e1 = d1->unk_1E;

        if ((e0 & 4) && e1 == 0 && d1->unk_2A == 1 &&
            p[2]->unk_48->unk_1C == 43) {
            return 1;
        }

        if (p[0]->unk_48->unk_1C == 27 && p[1]->unk_48->unk_1C == 19 &&
            p[2]->unk_48->unk_2A == 2 && !(p[2]->unk_48->unk_1E & 8)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE080(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;
    u16 e2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        e2 = p[2]->unk_48->unk_1E;

        if (c0 == 26 && c1 == 29 && (e2 & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE0B4(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 36 && c1 == 38 && s2 == 2 && !(d2->unk_1E & 8)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE0F4(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 18 && c1 == 39 && s2 == 1 && !(d2->unk_1E & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE134(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        s2 = p[2]->unk_48->unk_2A;

        if (c0 == 31 && c1 == 23 && s2 == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE168(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 24 && c1 == 18 && s2 == 1 && !(d2->unk_1E & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE1A8(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 24 && c1 == 19 && s2 == 1 && !(d2->unk_1E & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE1E8(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u16 c1;
    u16 c2;
    u8 s0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        c0 = d0->unk_1C;
        d1 = p[1]->unk_48;
        c1 = d1->unk_1C;
        d2 = p[2]->unk_48;
        c2 = d2->unk_1C;
        s0 = d0->unk_2A;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (s0 == 1 && !(d0->unk_1E & 4) && s1 == 1 && !(d1->unk_1E & 4) &&
            c2 == 44) {
            return 1;
        }

        if (c0 == 23 && c1 == 24 && s2 == 2 && !(p[2]->unk_48->unk_1E & 8)) {
            return 1;
        }
    }

    return 0;
}

INCLUDE_ASM("card/func_080AE274.s");

void func_080AEB94(void) {
    gUnk_0203A9E8 = 0;
}
