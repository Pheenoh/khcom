#include "macros.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "card.h"
#include "game.h"

void* TaskCreate(void* a, void* desc, void* args);
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
u16 func_080858B8(s32 index);
void func_08085A58(s32 index, u16* dst);
u8 func_080A42C8(void);
s32 func_080A40EC(u64* src);
s32 func_080A4D7C(u64* src);
UnkStruct_080038C8* func_080038C8(s32 size);
void func_080038E4(UnkStruct_080038C8* a, void* b, void* c);
void m4aSongNumStart(u16 n);
void TaskPoolDestroy(void* pool);
u8 func_08006314(void);
void* AnimUpdate(void* a);
void AnimStart(void* a, s32 b, s32 c);
void func_08000D20(void* a, void* b, void* c);
void func_08000D28(void* a, void* b);
void ApproachValue(void* a, s32 b, s32 c);
void func_08006184(s32 a, s32 b);
void func_08000F8C(void* a, void* b);
u8 func_080A8C20(u8* work);
void AnimInit(void* a, void* b, void* c);
s32 func_0805F5A4(s32* a, s32* b);
void func_0809511C(void);
void func_080062F4(u16 a, s32 b);
void func_08012304(void* a);
void func_0808E364(u8* work, s32 b);
void func_08088F24(void);
void func_08002A10(void* a, void* b);
void func_0805F1C0(void* a, s32 b);
void func_0808D6C4(u8* work);
void func_0808CD48(u8* work);
void func_08086A14(void);
void LoadPalette(void* src, void* dst, s32 size);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgSize(s32 a, s32 b);
void LoadBgMap(s32 bg, void* src, u16 size);
void TaskPoolInit(void* pool, s32 n);
void func_08004F08(void);
void func_08005690(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
u8 func_0809217C(u8* work, void* a);
void func_0808E344(void** p);
void func_080889DC(void);
void EnableBg(s32 bg);
u8 func_080E8D00(void);
void* func_080E8D1C(s32 a);
void func_08093C44(u8 a, u8* work);
u8 func_0808B30C(u8* work, void* a);
void func_08092234(void);
void func_0808C90C(u8* work);
void func_0808C3DC(u8* work, u8 b);
void func_0808DB50(u8* work);
void func_0808A218(void);
void func_0808D828(u8* work);
void func_0808C940(UnkStruct_0808C940* w, s16 n);
void func_0808C974(UnkStruct_0808C940* w);
void func_08065AE0(void* a, s32 b);
void func_08096638(PrizeCardWork* w);
void func_080034EC(s32 a, s32 b);
void func_08006120(s32 a, s32 b);
void func_0800443C(u32 a, s32 b);
void func_080864A4(void);
s32 func_0805F588(s32 a, s32 b);
void func_08096F08(void* a, void* b);
u8 func_08096288(PrizeCardWork* w, void* a);
u16 func_08093384(u8* work);
void* AllocObjTiles(s32 a, s32 b);
void func_08092A34(void);
void func_0808CC58(u16 a, s32 b);
void func_080AAA8C(u8* work, s32 b);
void func_080A8430(void);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_08090170(UnkStruct_0808E890* node);
u8 func_08096390(PrizeCardWork* w);
void* AnimGetGfx(void* a);
u8 func_080A9968(u8* work);
void func_080010CC(Mode* mode, s32 arg);
void UpdatePlayTime(void);
void func_080B31A0(void);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void func_0806BA0C(s16 a, void* b);
void func_0809470C(void);
extern u16 gBldAlpha;
void func_0809ACDC(void);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void func_080061E8(s32 a, u16 b);
void func_080A1BB8(void* a, void* b);
void func_0809D124(u8* work);
u16 func_08096D48(s32 a, s32 b);
void func_0809D1B0(u8* work);
void func_08000D90(void* a, void* b);
void func_0809CAC8(void* work);
u8 func_0800FCD8(s32 a, s32 b);
u8 func_0800FC90(s32 a);
void* func_080668F0(void);
void* func_08066904(void);
u8 func_0806692C(void* a, void* b);
void func_08066DC0(s32 a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g);
void func_0809D160(u8* work);
u16 GetKeysPressed(void);
void func_080A25E0(void);

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
INCLUDE_ASM("card/func_08078FFC.s");

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
INCLUDE_ASM("card/func_08079600.s");
INCLUDE_ASM("card/func_08079B3C.s");
INCLUDE_ASM("card/func_08079ECC.s");
INCLUDE_ASM("card/func_0807A188.s");

INCLUDE_ASM("card/func_0807A620.s");
void func_0807A684(u8* work) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)func_08000C8C(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 == 0) {
                node->unk_A1 = 7;
            }

            node = (UnkStruct_02034AAC*)func_08000CD4(&node->unk_64);
        }
    }
}
INCLUDE_ASM("card/func_0807A6C8.s");

#ifdef NON_MATCHING
void func_0807A75C(u8* work) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < work[0xB9]; i++) {
        ((UnkStruct_02034AAC**)&work[0x28])[i]->unk_78 &= ~0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)func_08000C8C(&work[i * 16 + 0x54]);

        while (node != 0) {
            node->unk_78 &= ~0x20;
            node = (UnkStruct_02034AAC*)func_08000CD4(&node->unk_64);
        }
    }

    gUnk_02039DD4->unk_0CC = 0;
    gUnk_02039B84->unk_068 |= 0x20;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    work[0xC9] = 1;
}
#else
INCLUDE_ASM("card/func_0807A75C.s");
#endif

INCLUDE_ASM("card/func_0807A80C.s");

INCLUDE_ASM("card/func_0807ABC8.s");

INCLUDE_ASM("card/func_0807AE78.s");
u8 func_0807AEC4(u8* work, u8 n) {
    UnkStruct_02034AAC* node;
    u8 count;

    count = 0;
    node = (UnkStruct_02034AAC*)func_08000C8C(&work[n * 16 + 0x54]);

    while (node != 0) {
        count++;
        node = (UnkStruct_02034AAC*)func_08000CD4(&node->unk_64);
    }

    return count;
}
INCLUDE_ASM("card/func_0807AEF4.s");
INCLUDE_ASM("card/func_0807AF40.s");
INCLUDE_ASM("card/func_0807B16C.s");
INCLUDE_ASM("card/func_0807B378.s");
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
INCLUDE_ASM("card/func_0807B578.s");
INCLUDE_ASM("card/func_0807B60C.s");
INCLUDE_ASM("card/func_0807B668.s");
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
INCLUDE_ASM("card/func_0807B9EC.s");

INCLUDE_ASM("card/func_0807BA54.s");
INCLUDE_ASM("card/func_0807BB04.s");

void func_0807BC08(void) {
    if (gUnk_02039B84->unk_0F4 == 50) {
        gUnk_02039B84->unk_0F8--;
    }
}
INCLUDE_ASM("card/func_0807BC24.s");
INCLUDE_ASM("card/func_0807BD64.s");
INCLUDE_ASM("card/func_0807BE54.s");
INCLUDE_ASM("card/func_0807BEC0.s");
INCLUDE_ASM("card/func_0807C248.s");
void func_0807C2E0(UnkStruct_02034AAC* p) {
    func_0807C39C(p);
}

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

void func_0807C39C(UnkStruct_02034AAC* p) {
    if (p->unk_00 != 0) {
        ReleaseObjTiles(p->unk_00);
    }

    if (p->unk_14 != 0) {
        ReleaseObjPalette(p->unk_14);
    }

    if (p->unk_04 != 0) {
        ReleaseObjTiles(p->unk_04);
    }

    if (p->unk_08 != 0) {
        ReleaseObjTiles(p->unk_08);
    }

    if (p->unk_0C != 0) {
        ReleaseObjTiles(p->unk_0C);
    }

    p->unk_00 = 0;
    p->unk_14 = 0;
    p->unk_18 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
}
INCLUDE_ASM("card/func_0807C3E8.s");
INCLUDE_ASM("card/func_0807C4BC.s");
INCLUDE_ASM("card/func_0807C5D8.s");
INCLUDE_ASM("card/func_0807C75C.s");
INCLUDE_ASM("card/func_0807C934.s");
INCLUDE_ASM("card/func_0807CB24.s");
INCLUDE_ASM("card/func_0807CBC0.s");

INCLUDE_ASM("card/func_0807CC2C.s");

INCLUDE_ASM("card/func_0807CD48.s");
INCLUDE_ASM("card/func_0807CE04.s");

u8 func_0807CE68(UnkStruct_02034AAC* p) {
    if (p->unk_4C > 0x10000) {
        return 1;
    }

    if (p->unk_4C < -0x1000) {
        return 1;
    }

    if (p->unk_50 > 0xC000) {
        return 1;
    }

    if (p->unk_50 < -0x2000) {
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_0807CE9C.s");
INCLUDE_ASM("card/func_0807CF4C.s");
INCLUDE_ASM("card/func_0807CFA8.s");

INCLUDE_ASM("card/func_0807D0F4.s");
INCLUDE_ASM("card/func_0807D194.s");
INCLUDE_ASM("card/func_0807D318.s");

void func_0807D380(u8* p) {
    u8* q;

    q = &p[0x64];
    func_08000D20(q, *(void**)&p[0x38], p);
    func_08000D28(q, *(void**)&p[0x38]);
}
INCLUDE_ASM("card/func_0807D3A0.s");
void func_0807D490(UnkStruct_02034AAC* p) {
    void* tiles;
    void* pal;

    func_0807C39C(p);
    tiles = p->unk_48->unk_14;
    pal = p->unk_48->unk_18;
    p->unk_00 = LoadObjTiles(tiles, 256);
    p->unk_14 = LoadObjPalette(pal, 32);
}

void func_0807D4B8(UnkStruct_02034AAC* p) {
    if (p->unk_00 != 0) {
        ReleaseObjTiles(p->unk_00);
    }

    if (p->unk_14 != 0) {
        ReleaseObjPalette(p->unk_14);
    }

    p->unk_00 = 0;
    p->unk_14 = 0;
    func_0807C33C(p);
}
INCLUDE_ASM("card/func_0807D4E4.s");
INCLUDE_ASM("card/func_0807D584.s");
INCLUDE_ASM("card/func_0807D68C.s");
INCLUDE_ASM("card/func_0807D7B0.s");
INCLUDE_ASM("card/func_0807D810.s");
INCLUDE_ASM("card/func_0807D840.s");
INCLUDE_ASM("card/func_0807D930.s");
INCLUDE_ASM("card/func_0807D99C.s");
INCLUDE_ASM("card/func_0807DA54.s");
void func_0807DAA4(u8* p, u16 a) {
    void* gfx;

    if (a <= 18) {
        AnimStart(&p[0x10], a, 0);
        gfx = AnimGetGfx(&p[0x10]);
    } else {
        gfx = 0;
    }

    *(void**)&p[0x60] = gfx;
}
INCLUDE_ASM("card/func_0807DAD0.s");
INCLUDE_ASM("card/func_0807DBB8.s");
void func_0807DD30(UnkStruct_02034AAC* p) {
    func_0807C39C(p);
    EwramFree(p->unk_20);

    if (gUnk_02039B84->unk_068 & 0x1000000) {
        gUnk_02039B84->unk_068 &= ~0x1000000;
    }
}
void func_0807DD70(u8* p) {
    if (gUnk_02039DD4->unk_104 <= 7) {
        gUnk_02039DD4->unk_104++;
    }

    AnimStart(&p[0x40], (u16)gUnk_02039DD4->unk_104, 5);
}
void func_0807DDA8(u8* p) {
    gUnk_02039DD4->unk_104 = 2;
    AnimStart(&p[0x40], 2, 5);
}
void func_0807DDCC(u8* p) {
    *(void**)&p[0x58] = gUnk_09EEAF4C[3];
    *(void**)&p[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_100 + 2];
}
void func_0807DDF4(u8* p) {
    *(void**)&p[0x58] = AnimUpdate(&p[0x28]);
    *(void**)&p[0x5C] = AnimUpdate(&p[0x40]);
}
INCLUDE_ASM("card/func_0807DE10.s");

INCLUDE_ASM("card/func_0807E018.s");
void func_0807E158(void) {
    UnkStruct_02039B84* p;

    p = gUnk_02039B84;

    switch (p->unk_0F4) {
        case 15:
        case 28:
        case 47:
            p->unk_0F8--;
            break;
    }
}
void func_0807E184(void) {
    if (gUnk_02039B84->unk_0F4 == 2) {
        gUnk_02039B84->unk_0F8--;
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
INCLUDE_ASM("card/func_0807E8F4.s");
INCLUDE_ASM("card/func_0807EDEC.s");
INCLUDE_ASM("card/func_0807F99C.s");
void func_0807FA0C(u8* work) {
    UnkStruct_0807FA0C* w;
    u8 i;

    w = (UnkStruct_0807FA0C*)work;
    TaskPoolDestroy(w);

    for (i = 0; i <= 3; i++) {
        if (w->unk_44[i] != 0) {
            EwramFree(w->unk_44[i]);
        }
    }

    ReleaseObjTiles(w->unk_14);
    ReleaseObjPalette(w->unk_18);
}

INCLUDE_ASM("card/func_0807FA44.s");
INCLUDE_ASM("card/func_0807FAD8.s");
INCLUDE_ASM("card/func_0807FB5C.s");
INCLUDE_ASM("card/func_0807FD10.s");
INCLUDE_ASM("card/func_0807FE30.s");
INCLUDE_ASM("card/func_0807FF48.s");
INCLUDE_ASM("card/func_080800B4.s");

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
INCLUDE_ASM("card/func_08080594.s");

INCLUDE_ASM("card/func_08080994.s");
INCLUDE_ASM("card/func_08080B44.s");

INCLUDE_ASM("card/func_08080EB4.s");
INCLUDE_ASM("card/func_08081210.s");
INCLUDE_ASM("card/func_080814BC.s");
void func_08081740(void) {
}
void func_08081744(void) {
    gUnk_02039B9C->unk_0F4 = gUnk_02039DD4->unk_0CE;
}

INCLUDE_ASM("card/func_08081760.s");
u8 func_08081828(void) {
    return gUnk_02039DD4->unk_0ED;
}

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
INCLUDE_ASM("card/func_08082C98.s");
INCLUDE_ASM("card/func_08082DA4.s");
INCLUDE_ASM("card/func_08082E0C.s");
void func_08082EFC(UnkStruct_02034AAC* p) {
    void* tiles;
    void* pal;

    func_0807C39C(p);
    tiles = p->unk_48->unk_14;
    pal = p->unk_48->unk_18;
    p->unk_00 = LoadObjTiles(tiles, 256);
    p->unk_14 = LoadObjPalette(pal, 32);
}

void func_08082F24(UnkStruct_02034AAC* p) {
    if (p->unk_00 != 0) {
        ReleaseObjTiles(p->unk_00);
    }

    if (p->unk_14 != 0) {
        ReleaseObjPalette(p->unk_14);
    }

    p->unk_00 = 0;
    p->unk_14 = 0;
    func_0807C33C(p);
}
INCLUDE_ASM("card/func_08082F50.s");
INCLUDE_ASM("card/func_08082FF0.s");
INCLUDE_ASM("card/func_08083020.s");
INCLUDE_ASM("card/func_08083114.s");
void func_08083234(UnkStruct_02034AAC* p) {
    func_0807C39C(p);

    if (p->unk_20 != 0) {
        EwramFree(p->unk_20);
    }

    if (gUnk_02039B9C->unk_068 & 0x1000000) {
        gUnk_02039B9C->unk_068 &= ~0x1000000;
    }
}
void func_08083278(u8* p) {
    if (gUnk_02039DD4->unk_106 <= 7) {
        gUnk_02039DD4->unk_106++;
    }

    AnimStart(&p[0x40], (u16)gUnk_02039DD4->unk_106, 5);
}
void func_080832B0(u8* p) {
    gUnk_02039DD4->unk_106 = 2;
    AnimStart(&p[0x40], 2, 5);
}
void func_080832D0(u8* p) {
    *(void**)&p[0x58] = gUnk_09EEAF4C[3];
    *(void**)&p[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_102 + 2];
}
void func_080832F8(u8* p) {
    *(void**)&p[0x58] = AnimUpdate(&p[0x28]);
    *(void**)&p[0x5C] = AnimUpdate(&p[0x40]);
}
void func_08083314(u8* p, u16 a) {
    void* gfx;

    if (a <= 18) {
        AnimStart(&p[0x10], a, 0);
        gfx = AnimGetGfx(&p[0x10]);
    } else {
        gfx = 0;
    }

    *(void**)&p[0x60] = gfx;
}
INCLUDE_ASM("card/func_08083340.s");
INCLUDE_ASM("card/func_08083550.s");
INCLUDE_ASM("card/func_080836C4.s");
INCLUDE_ASM("card/func_08083714.s");
INCLUDE_ASM("card/func_080837FC.s");
void func_080838A0(void) {
    UnkStruct_02039B84* p;

    p = gUnk_02039B9C;

    switch (p->unk_0F4) {
        case 15:
        case 28:
        case 47:
            p->unk_0F8--;
            break;
    }
}
void func_080838CC(void) {
    if (gUnk_02039B9C->unk_0F4 == 2) {
        gUnk_02039B9C->unk_0F8--;
    }
}

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

u8 func_08083920(void) {
    return func_08091B44();
}
INCLUDE_ASM("card/func_08083930.s");
INCLUDE_ASM("card/func_080839FC.s");
s32 func_08083ADC(u8* work) {
    s32 v;

    if (work[0x31] != 0) {
        v = *(s16*)&work[0x28] << 8;
        ApproachValue(&v, 0x10000, work[0x31]);
        *(s16*)&work[0x28] = v >> 8;
        work[0x31]--;
    }

    return 1;
}
void func_08083B18(void) {
}
void func_08083B1C(void) {
}

INCLUDE_ASM("card/func_08083B20.s");
INCLUDE_ASM("card/func_08083B94.s");
INCLUDE_ASM("card/func_08083BE4.s");
void func_08083C8C(void) {
}
void func_08083C90(void) {
}

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
INCLUDE_ASM("card/func_08084AC8.s");

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
INCLUDE_ASM("card/func_08084C40.s");

INCLUDE_ASM("card/func_08084D78.s");

INCLUDE_ASM("card/func_08084E50.s");
void func_08084FA8(void) {
}

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

void func_080850B0(u16* p) {
    *p = CARD_ID_MASK;
}
void func_080850BC(u16 id) {
    s32 i;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK &&
            (gCardCollection[i] & 0x7000) == 0 &&
            (gCardCollection[i] & CARD_ID_MASK) == id) {
            gCardCollection[i] = CARD_ID_MASK;
            return;
        }
    }
}
INCLUDE_ASM("card/func_0808510C.s");

INCLUDE_ASM("card/func_08085160.s");
INCLUDE_ASM("card/func_080851E4.s");

INCLUDE_ASM("card/func_08085290.s");

INCLUDE_ASM("card/func_08085374.s");
INCLUDE_ASM("card/func_08085448.s");
INCLUDE_ASM("card/func_08085518.s");
INCLUDE_ASM("card/func_080855C8.s");
INCLUDE_ASM("card/func_08085658.s");

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

#ifdef NON_MATCHING
void func_08085788(u8 index, u16* src) {
    Deck* deck;
    u8* d;
    u8* s;

    if (*src == 0) {
        return;
    }

    deck = &gDecks[index];
    d = deck->unk_C6;
    s = (u8*)src;

    do {
        d[0] = s[0];
        d[1] = s[1];
        d += 2;
        s += 2;
    } while (*(u16*)s != 0);
}
#else
INCLUDE_ASM("card/func_08085788.s");
#endif

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

void func_08085FB0(void) {
}
INCLUDE_ASM("card/func_08085FB4.s");
u8 func_080863C0(u8* work, void* a) {
    func_08006120(0, 16);

    if (work[0x8D0] == 0) {
        func_0800443C(GetBgCharBase(0), 0x2000);
    }

    if (work[0x8D0] == 1) {
        func_0800443C(GetBgCharBase(0) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 2) {
        func_0800443C(GetBgCharBase(1), 0x2000);
    }

    if (work[0x8D0] == 3) {
        func_0800443C(GetBgCharBase(1) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 4) {
        func_0800443C(GetBgCharBase(2), 0x2000);
    }

    if (work[0x8D0] == 5) {
        func_0800443C(GetBgCharBase(2) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 6) {
        func_0800443C(GetBgCharBase(3), 0x2000);
    }

    if (work[0x8D0] == 7) {
        func_0800443C(GetBgCharBase(3) + 0x2000, 0x2000);
    }

    work[0x8D0]++;

    if (work[0x8D0] == 8) {
        work[0x8D0] = 0;
        func_08000F8C(a, (void*)func_080864A4);
    }

    return 1;
}
INCLUDE_ASM("card/func_080864A4.s");
INCLUDE_ASM("card/func_08086650.s");
INCLUDE_ASM("card/func_08086860.s");
INCLUDE_ASM("card/func_0808686C.s");
u8 func_08086984(u8* work, void* a) {
    func_0808D6C4(work);
    func_0805F1C0(&work[0x848], gUnk_09035950[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_09035956[*(s16*)&work[0x886]] << 8);
    work[0x8B7]--;

    if (work[0x8B7] == 0) {
        work[0x8B1] = 0;
        func_0808CD48(work);
        func_08000F8C(a, (void*)func_08086A14);
    }

    return 1;
}
INCLUDE_ASM("card/func_08086A14.s");
INCLUDE_ASM("card/func_080870FC.s");
INCLUDE_ASM("card/func_08087438.s");
INCLUDE_ASM("card/func_0808778C.s");

#ifdef NON_MATCHING
void func_08087B98(u8* work) {
    UnkStruct_0808E890* node;
    UnkStruct_0808E890* p;
    s32 i;

    node = func_08000C8C(&work[0x7F0]);
    i = 0;
    EwramFree((*(UnkStruct_0808E2F0**)&work[0x4D4])[*(u16*)&work[0x880]].unk_1C);
    (*(UnkStruct_0808E2F0**)&work[0x4D4])[*(u16*)&work[0x880]].unk_1C = 0;

    for (i = *(u16*)&work[0x880]; i < *(u16*)&work[0x898] - 1; i++) {
        (*(UnkStruct_0808E2F0**)&work[0x4D4])[i] =
            (*(UnkStruct_0808E2F0**)&work[0x4D4])[i + 1];
    }

    *(u16*)&work[0x898] -= 1;
    *(u16*)&work[0x8D4] -= 1;

    while (node != 0) {
        if (node->unk_22 == (s8)work[0x8B5] && node->unk_24 == (s8)work[0x8B6]) {
            break;
        }

        node = func_08000CD4(&node->unk_2C);
    }

    p = func_08000CD4(&node->unk_2C);

    while (p != 0) {
        p->unk_22--;

        if (p->unk_22 < 0) {
            p->unk_22 = 2;
            p->unk_24--;
        }

        p = func_08000CD4(&p->unk_2C);
    }

    node->unk_4A = 1;
    TaskPoolUpdate(&work[0x7C8]);
    func_0808D828(work);
    func_0808C940((UnkStruct_0808C940*)work, *(s16*)&work[0x898]);
    func_0808C974((UnkStruct_0808C940*)work);
}
#else
INCLUDE_ASM("card/func_08087B98.s");
#endif
INCLUDE_ASM("card/func_08087CD4.s");
INCLUDE_ASM("card/func_080882DC.s");
INCLUDE_ASM("card/func_08088768.s");
INCLUDE_ASM("card/func_080889DC.s");
#ifdef NON_MATCHING
u8 func_08088EB4(u8* work, void* a) {
    *(void**)&work[8] = LoadObjTiles(gUnk_090A261E, 0x1800);
    *(void**)&work[12] = LoadObjPalette(gUnk_096144D8, 32);
    func_0808E364(work, 1);
    work[0x8B1] = 3;
    work[0x8C8] = 0;
    func_08000F8C(a, (void*)func_08088F24);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08088EB4.s");
#endif
INCLUDE_ASM("card/func_08088F24.s");
u8 func_08089220(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x818]);
    func_0808E344((void**)work);
    func_0808E364(work, 0);

    switch (work[0x8C8]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        if (work[0x8B2] == 0) {
            work[0x8B1] = 0;
            func_0808CD48(work);
            work[0x8B7] = 4;
            func_08000F8C(a, (void*)func_08086A14);
        } else {
            work[0x8B1] = 1;
            work[0x8B7] = 4;
            func_08000F8C(a, (void*)func_080889DC);
        }
        break;
    }

    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
INCLUDE_ASM("card/func_080892E8.s");
INCLUDE_ASM("card/func_08089558.s");
INCLUDE_ASM("card/func_080897CC.s");
INCLUDE_ASM("card/func_08089D20.s");
INCLUDE_ASM("card/func_08089EC0.s");
#ifdef NON_MATCHING
u8 func_0808A114(u8* work, void* a) {
    *(u16*)&work[0x894] = 94;
    *(u16*)&work[0x896] = 130;
    work[0x8B1] = 7;
    func_0808E344((void**)work);
    func_0808E364(work, 0);
    func_0808CD48(work);
    LoadBgMap(3, gUnk_095132B8, 0x800);
    func_0808C90C(work);
    work[0x8C1] = 0;
    *(s16*)&work[0x884] = 0;
    *(s16*)&work[0x886] = 0;
    func_0808C3DC(work, work[0x8C1]);
    *(s32*)&work[0x848] = gUnk_09035950[*(s16*)&work[0x884]] << 8;
    *(s32*)&work[0x84C] = gUnk_09035956[*(s16*)&work[0x886]] << 8;
    func_0808DB50(work);
    work[0x8C7] = 1;
    func_08000F8C(a, (void*)func_0808A218);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808A114.s");
#endif
INCLUDE_ASM("card/func_0808A218.s");
INCLUDE_ASM("card/func_0808A650.s");
INCLUDE_ASM("card/func_0808A7E4.s");
INCLUDE_ASM("card/func_0808A910.s");
INCLUDE_ASM("card/func_0808AB48.s");
INCLUDE_ASM("card/func_0808B068.s");
u8 func_0808B208(u8* work) {
    if (func_08006314() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#ifndef VERSION_JP
u8 func_0808B238(u8* work, void* a) {
    *(void**)&work[0x4BC] = LoadObjTiles(gUnk_090A583E, 0x620);

    if (gUnk_02039BB0.unk_008 & 8) {
        *(void**)&work[0x18] = LoadObjTiles(gUnk_090A418E, 0x320);
    } else {
        *(void**)&work[0x18] = LoadObjTiles(gUnk_090A3E46, 0x320);
    }

    *(void**)&work[0x4C0] = LoadObjPalette(gUnk_096144F8, 32);
    LoadBgMap(3, gUnk_09516AB8, 0x800);
    *(s32*)&work[0x858] = 0x7800;
    *(s32*)&work[0x860] = 0;
    *(s32*)&work[0x85C] = 0xA400;
    *(s32*)&work[0x864] = 0x9800;
    *(s32*)&work[0x868] = 0;
    work[0x8CC] = 16;
    work[0x8CD] = 16;
    work[0x8B0] = 0;
    func_08000F8C(a, (void*)func_0808B30C);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808B238.s");
#endif

u8 func_0808B30C(u8* work, void* a) {
    if ((s8)work[0x8CD] > 0) {
        ApproachValue(&work[0x868], -0x8000, (u16)(s8)work[0x8CD]);
        work[0x8CD]--;
    } else if ((s8)work[0x8CC] > 0) {
        ApproachValue(&work[0x860], -0x800, (u16)(s8)work[0x8CC]);
        ApproachValue(&work[0x864], 0xA000, (u16)(s8)work[0x8CC]);
        work[0x8CC]--;
    } else {
        func_08006184(0, 4);
        func_08000F8C(a, (void*)func_0808B208);
    }

    return 1;
}
void func_0808B398(u8* work) {
    func_08066588(*(s16*)&work[0x894], *(s16*)&work[0x896], &work[0x1E8],
                  *(void**)&work[0x14], 20, work[0x8C6]);
}

INCLUDE_ASM("card/func_0808B3DC.s");
INCLUDE_ASM("card/func_0808B66C.s");
INCLUDE_ASM("card/func_0808C2F0.s");

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

void func_0808C9CC(u8* work) {
    UnkStruct_0808E890* node;

    node = func_08000C8C(&work[0x7F0]);

    if (*(s16*)&work[0x8AC] != *(s16*)&work[0x8AE]) {
        while (node != 0) {
            node->unk_24--;

            if (node->unk_24 < 0) {
                node->unk_44 = 0x20000;
                func_08090170(node);
            }

            node = func_08000CD4(&node->unk_2C);
        }

        m4aSongNumStart(121);
        *(u16*)&work[0x8AC] += 1;
        *(s32*)&work[0x854] += 0x300;

        if (*(s32*)&work[0x854] > 0x7C00) {
            *(s32*)&work[0x854] = 0x7C00;
        }

        if (work[0x8CF] != 0) {
            *(u16*)&work[0x876] -= 1;
        }

        func_0808C974((UnkStruct_0808C940*)work);
    }
}

INCLUDE_ASM("card/func_0808CA78.s");
INCLUDE_ASM("card/func_0808CB60.s");

INCLUDE_ASM("card/func_0808CBB4.s");

INCLUDE_ASM("card/func_0808CC58.s");
INCLUDE_ASM("card/func_0808CD48.s");

INCLUDE_ASM("card/func_0808CDE8.s");

INCLUDE_ASM("card/func_0808D0A4.s");

INCLUDE_ASM("card/func_0808D16C.s");

INCLUDE_ASM("card/func_0808D258.s");
INCLUDE_ASM("card/func_0808D438.s");
INCLUDE_ASM("card/func_0808D4E4.s");

INCLUDE_ASM("card/func_0808D594.s");

void func_0808D6C4(u8* work) {
    func_08065ACC(&work[0x38], 8);
    func_08065ACC(&work[0x78], 8);
    func_08065ACC(&work[0xB8], 8);
    work[0x8C2] = func_08065B6C(func_080857BC(0), &work[0x38]);
    work[0x8C3] = func_08065B6C(func_080857BC(1), &work[0x78]);
    work[0x8C4] = func_08065B6C(func_080857BC(2), &work[0xB8]);
}

void func_0808D73C(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
    work[0x8C5] = func_08065B6C(def->unk_0C, &work[0xF8]);

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    }
}

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

#ifdef NON_MATCHING
void func_0808DD20(u8 a, u16 b) {
    u8 v[2];
    u32 base;
    u8* dst;

    base = GetBgCharBase(3);

    if (a != 0) {
        v[0] = a / 10;
        v[1] = a - v[0] * 10;
        dst = (u8*)(base + b * 64 + 0xD20);
        RequestDma3Copy(&gUnk_0940FA98[(v[0] + 3) * 32], dst, 32);
        dst += 32;
        RequestDma3Copy(&gUnk_0940FA98[(v[1] + 3) * 32], dst, 32);
    } else {
        dst = (u8*)(base + b * 64 + 0xD20);
        RequestDma3Copy(gUnk_0940FAD8, dst, 32);
        dst += 32;
        RequestDma3Copy(gUnk_0940FAD8, dst, 32);
        LoadPalette(gUnk_09614406, (void*)(b * 2 + 0x0500016C), 2);
    }
}
#else
INCLUDE_ASM("card/func_0808DD20.s");
#endif

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
INCLUDE_ASM("card/func_0808E19C.s");

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
INCLUDE_ASM("card/func_0808E3E0.s");
INCLUDE_ASM("card/func_0808E474.s");
INCLUDE_ASM("card/func_0808E58C.s");

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

u8 func_0808E8E8(u8* work, u16 a, u16 b) {
    UnkStruct_0808E890* node;

    node = func_08000C8C(&work[0x7F0]);

    while (node != 0) {
        if (node->unk_22 == (s16)a && node->unk_24 == (s16)b) {
            return 1;
        }

        node = func_08000CD4(&node->unk_2C);
    }

    return 0;
}
INCLUDE_ASM("card/func_0808E934.s");

INCLUDE_ASM("card/func_0808EA0C.s");
INCLUDE_ASM("card/func_0808EC24.s");
INCLUDE_ASM("card/func_0808EDA4.s");

INCLUDE_ASM("card/func_0808EF80.s");

INCLUDE_ASM("card/func_0808F0C0.s");
void func_0808F258(u8 a) {
    u32 base;

    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_09417378[a * 64], (void*)(base + 32), 64);
}
void func_0808F284(u8* work) {
    u8* s;
    u8* d;
    s32 i;

    s = func_080857BC(work[0x8C0]);

    for (i = 0; i <= 19; i++) {
        d = &work[0x784];
        d[i] = s[i];
    }

    work[0x796] = 0;
    work[0x797] = 0;
}
void func_0808F2CC(u8* work) {
    u8* d;
    u8* s;
    s32 i;

    d = func_080857BC(work[0x8C0]);

    for (i = 0; i <= 19; i++) {
        s = &work[0x784];
        d[i] = s[i];
    }

    d[18] = 0;
    d[19] = 0;
}
INCLUDE_ASM("card/func_0808F304.s");
INCLUDE_ASM("card/func_0808F358.s");
INCLUDE_ASM("card/func_0808F3E8.s");
INCLUDE_ASM("card/func_0808F660.s");
INCLUDE_ASM("card/func_0808FA0C.s");

INCLUDE_ASM("card/func_0808FA8C.s");
INCLUDE_ASM("card/func_0808FE04.s");
INCLUDE_ASM("card/func_0808FF58.s");
INCLUDE_ASM("card/func_08090024.s");
void func_080900E8(u8* p) {
    func_08090170((UnkStruct_0808E890*)p);
    func_08000D90(&p[0x2C], *(void**)&p[0x1C]);
}
INCLUDE_ASM("card/func_08090100.s");

INCLUDE_ASM("card/func_08090170.s");
u8 func_080901B8(u8* p) {
    s16 a;
    s16 b;

    a = *(s32*)&p[0x40] >> 8;
    b = *(s32*)&p[0x44] >> 8;

    if (a < 0) {
        return 0;
    }

    if (a > 240) {
        return 0;
    }

    if (b < 0) {
        return 0;
    }

    if (b > 160) {
        return 0;
    }

    return 1;
}
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
    func_08000D20(q, *(void**)&p[0x38], p);
    func_08000D28(q, *(void**)&p[0x38]);
}
INCLUDE_ASM("card/func_08090244.s");
INCLUDE_ASM("card/func_080902D8.s");
INCLUDE_ASM("card/func_08090374.s");
void func_08090530(u8* work) {
    if (*(void**)&work[0x00] != 0) {
        func_0807C39C((UnkStruct_02034AAC*)work);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjPalette(*(void**)&work[0x18]);
    }
}
INCLUDE_ASM("card/func_08090550.s");
INCLUDE_ASM("card/func_08090630.s");
INCLUDE_ASM("card/func_0809075C.s");
INCLUDE_ASM("card/func_08090808.s");
INCLUDE_ASM("card/func_08090864.s");
INCLUDE_ASM("card/func_08090940.s");
INCLUDE_ASM("card/func_080909A4.s");
INCLUDE_ASM("card/func_08090A54.s");
INCLUDE_ASM("card/func_08090ACC.s");
INCLUDE_ASM("card/func_08090B50.s");
INCLUDE_ASM("card/func_08090C3C.s");
INCLUDE_ASM("card/func_08090DB0.s");
INCLUDE_ASM("card/func_08090EA0.s");
INCLUDE_ASM("card/func_08091048.s");
INCLUDE_ASM("card/func_08091138.s");

INCLUDE_ASM("card/func_08091234.s");
INCLUDE_ASM("card/func_080917C8.s");
INCLUDE_ASM("card/func_08091978.s");
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
void func_08091B68(void) {
    func_08004F08();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
    func_08005690(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AB8, 1);
    TaskCreate(gUnk_02034AB8, gUnk_09EE7804, 0);
}
void func_08091C00(void) {
    TaskPoolUpdate(gUnk_02034AB8);
    TaskPoolDraw(gUnk_02034AB8);
}
void func_08091C1C(void) {
    TaskPoolDestroy(gUnk_02034AB8);
}
INCLUDE_ASM("card/func_08091C2C.s");
u8 func_080920F0(u8* work, void* a) {
    *(void**)&work[0x38] = LoadObjTiles(gUnk_093F7172, 0x400);
    LoadBgTiles(1, gUnk_09508098, 0x2020);
    LoadPalette(gUnk_09618C58, (void*)0x05000180, 32);
    LoadPalette(&gUnk_09618C58[0x40], (void*)0x050001C0, 64);
    func_080062F4(12, 1);
    func_080062F4(14, 1);
    func_080062F4(15, 1);
    work[0x286]++;
    DisableBg(1);
    func_08000F8C(a, (void*)func_0809217C);
    return 1;
}
u8 func_0809217C(u8* work, void* a) {
    s32 n;

    func_0800516C(1, gUnk_09EE4BB0, 1, 2);
    *(s32*)&work[0x240] = 0;
    func_08005244(1, 0, 0);
    EnableBg(1);

    if (work[0x2BE] == 1) {
        work[0x2DA] = func_080E8D00();
        *(void**)&work[0x2DC] = func_080E8D1C(0);
        n = work[0x2DA];

        while (n != 0) {
            n--;
        }

        *(void**)&work[0x2C4] = *(void**)&work[0x48];
        *(s32*)&work[0x2CC] = 0;
        *(void**)&work[0x238] =
            ((void**)TaskCreate(work, gUnk_09EE7680, &work[0x2C4]))[1];
    }

    func_08093C44((*(u8**)&work[0x1EC])[32], work);
    func_08000F8C(a, (void*)func_08092234);
    return 1;
}
INCLUDE_ASM("card/func_08092234.s");
INCLUDE_ASM("card/func_080923E0.s");
INCLUDE_ASM("card/func_0809254C.s");
u8 func_080928E4(u8* work, void* a) {
    MapcardWork* node;

    if (func_08093384(work) == 0) {
        return 0;
    }

    if ((*(MapcardWork**)&work[0x1EC])->unk_6F == 0) {
        node = (MapcardWork*)func_08000C8C(&work[0x14]);

        while (node != 0) {
            if (*(MapcardWork**)&work[0x1EC] != node) {
                node->unk_6C |= 2;
            }

            node = (MapcardWork*)func_08000CD4(&node->unk_38);
        }

        func_08000F8C(a, (void*)func_08092A34);
        ReleaseObjTiles(*(void**)&work[0x3C]);
        *(void**)&work[0x3C] = AllocObjTiles(0x3C0, 0);
        func_08002A10(*(void**)&work[0x3C], gUnk_093F47E4);
        AnimInit(&work[0x1F8], gUnk_09EF1194, gUnk_09EF1180);
        AnimStart(&work[0x1F8], 0, 1);
        *(void**)&work[0x274] = AnimGetGfx(&work[0x1F8]);
        *(s32*)&work[0x258] = *(s16*)&work[0x280] << 8;
        *(s32*)&work[0x25C] = *(s16*)&work[0x282] << 8;
        *(s32*)&work[0x250] = ((MapcardWork*)*(s32*)&work[0x1EC])->unk_4C;
        *(s32*)&work[0x254] = ((MapcardWork*)*(s32*)&work[0x1EC])->unk_50;
        work[0x2C0] = 1;
    }

    func_080034EC(work[0x299], work[0x29A]);

    if (work[0x29B] == 2) {
        if (work[0x299] != 0) {
            work[0x299]--;
        }

        if (work[0x29A] != 0) {
            work[0x29A]--;
        }

        work[0x29B] = 0;
    }

    work[0x29B]++;
    TaskPoolUpdate(work);
    return 1;
}
INCLUDE_ASM("card/func_08092A34.s");
u8 func_08092E2C(u8* work) {
    ApproachValue(&work[0x240], 0, work[0x28F]);
    ApproachValue(&work[0x248], -0xA000, work[0x28F]);
    ApproachValue(&work[0x25C], 0x16400, work[0x28F]);
    ApproachValue(&work[0x254], 0x17A00, work[0x28F]);
    ApproachValue(&work[0x244], 0x19100, work[0x28F]);
    func_08005244(1, 0, *(u32*)&work[0x240] >> 8);
    work[0x2C0] = 0;

    if (work[0x299] <= 8) {
        work[0x299]++;
    }

    if (work[0x29A] <= 8) {
        work[0x29A]++;
    }

    func_080034EC(work[0x299], work[0x29A]);

    if (work[0x28F] != 0) {
        work[0x28F]--;
    } else if (work[0x290] != 0) {
        ApproachValue(&work[0x26C], -0x800, work[0x290]);
        ApproachValue(&work[0x270], 0xA000, work[0x290]);
        work[0x290]--;
    } else {
        if (work[0x2BF] != 0 ||
            ((*(MapcardWork**)&work[0x1EC])->unk_6C & 0x80)) {
            return 0;
        }
    }

    TaskPoolUpdate(work);
    return 1;
}
INCLUDE_ASM("card/func_08092F44.s");
void func_0809324C(u8* work) {
    TaskPoolDestroy(work);

    if (*(void**)&work[0x2E0] != 0) {
        EwramFree(*(void**)&work[0x2E0]);
    }

    func_080062F4((*(UnkStruct_080038C8**)&work[0x48])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x40])->unk_06 + 16, 0);
    func_080062F4(15, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x1CC])->unk_06 + 16, 0);
    ReleaseObjTiles(*(void**)&work[0x44]);
    ReleaseObjPalette(*(void**)&work[0x48]);
    ReleaseObjTiles(*(void**)&work[0x3C]);
    ReleaseObjPalette(*(void**)&work[0x40]);
    ReleaseObjTiles(*(void**)&work[0x38]);

    if (*(void**)&work[0x2C] != 0) {
        ReleaseObjTiles(*(void**)&work[0x2C]);
    }

    if (*(void**)&work[0x34] != 0) {
        ReleaseObjTiles(*(void**)&work[0x34]);
    }

    if (*(void**)&work[0x30] != 0) {
        ReleaseObjPalette(*(void**)&work[0x30]);
    }

    ReleaseObjTiles(*(void**)&work[0x1E8]);
    func_08065AE0(&work[0x4C], 48);
    ReleaseObjPalette(*(void**)&work[0x1CC]);
    **(u8**)&work[0x294] = 1;
    ReleaseObjTiles(*(void**)&work[0x1E0]);
    ReleaseObjTiles(gUnk_0203A890[0]);
    ReleaseObjTiles(gUnk_0203A890[1]);
}
void func_0809332C(u8* work) {
    MapcardArgs args;
    u16* q;
    u16 i;

    for (i = 0; i < *(u16*)&work[0x27C]; i++) {
        q = *(u16**)&work[0x2E0];
        args.unk_00 = q[i * 2];
        args.unk_01 = i;
        args.unk_02 = *(u16*)&work[0x27C];
        args.unk_03 = q[i * 2 + 1];
        args.unk_08 = &work[0x14];
        args.unk_04 = work;
        func_08094E78(&args, work);
    }
}

INCLUDE_ASM("card/func_08093384.s");
INCLUDE_ASM("card/func_080933D8.s");
INCLUDE_ASM("card/func_08093434.s");
INCLUDE_ASM("card/func_08093708.s");

INCLUDE_ASM("card/func_08093838.s");
u8 func_080938CC(void) {
    u8 sum;
    s32 i;

    sum = 0;

    for (i = 0; i <= 0x10D; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

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

s32 func_08093F1C(u8* work) {
    u8* p;
    s32 base;
    u8 i;

    i = 4;
    base = ((s8*)work)[0x29D] * 5;
    p = &work[0x2D0];

    do {
        if (p[i + base] == 0) {
            i--;
        } else {
            return (s8)i;
        }
    } while (i != 0);

    return -1;
}
INCLUDE_ASM("card/func_08093F5C.s");
INCLUDE_ASM("card/func_0809423C.s");
INCLUDE_ASM("card/func_0809438C.s");
INCLUDE_ASM("card/func_08094404.s");
INCLUDE_ASM("card/func_08094548.s");
INCLUDE_ASM("card/func_08094634.s");
INCLUDE_ASM("card/func_0809470C.s");
INCLUDE_ASM("card/func_080947B4.s");
INCLUDE_ASM("card/func_0809486C.s");
s32 func_080948F0(u8* work, void* a) {
    u8 t;

    t = func_08094E4C(work);
    func_08094DA8(work);
    func_08094CE4(work);

    if (t == 0) {
        *(u16*)&work[0x6C] &= 0xFFF3;
        func_08000F8C(a, func_0809470C);
    }

    return 1;
}
INCLUDE_ASM("card/func_08094934.s");
INCLUDE_ASM("card/func_080949A0.s");
INCLUDE_ASM("card/func_08094A18.s");
INCLUDE_ASM("card/func_08094B64.s");
void func_08094C80(u8* work) {
    if (*(u16*)&work[0x6C] & 1) {
        ReleaseObjTiles(*(void**)&work[0x08]);
        ReleaseObjPalette(*(void**)&work[0x0C]);
        ReleaseObjTiles(*(void**)&work[0x10]);
        ReleaseObjPalette(*(void**)&work[0x14]);
    }
}

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

void func_08094DA8(MapcardWork* w) {
    if (w->unk_6C & 2) {
        ApproachValue(&w->unk_50, 0x7900, w->unk_6F);
    } else {
        ApproachValue(&w->unk_50, 0x10500, w->unk_6F);
    }

    if (w->unk_6F != 0) {
        w->unk_6F--;
    }
}
void func_08094DEC(MapcardWork* w) {
    if ((w->unk_6C & 4) && w->unk_60 - w->unk_5C > 0x8000) {
        w->unk_5C += 0x10000;
    }

    if ((w->unk_6C & 8) && w->unk_60 < w->unk_5C) {
        w->unk_5C -= 0x10000;
    }

    ApproachValue(&w->unk_5C, w->unk_60, w->unk_6F);
    w->unk_6F--;
}
u8 func_08094E4C(MapcardWork* w) {
    ApproachValue(&w->unk_5C, w->unk_60, w->unk_6F);

    if (w->unk_6F != 0) {
        w->unk_6F--;
        return 1;
    }

    return 0;
}
void* func_08094E78(void* a, void* b) {
    return ((void**)TaskCreate(b, gUnk_09EE7548, a))[1];
}
void func_08094E90(MapcardWork* w) {
    func_08000D20(&w->unk_38, w->unk_28, w);
    func_08000D28(&w->unk_38, w->unk_28);
}
INCLUDE_ASM("card/func_08094EB0.s");
INCLUDE_ASM("card/func_0809511C.s");
u8 func_080954C4(ReloadGageWork* w, void* a) {
    if (w->unk_A1 == 7) {
        return 0;
    }

    w->unk_84 += -w->unk_84 >> 1;
    w->unk_4C += (gUnk_09033FF4[8] - w->unk_4C) >> 1;
    w->unk_50 += (gUnk_09033FF4[9] - w->unk_50) >> 1;

    if (w->unk_78 & 0x20) {
        func_08000F8C(a, (void*)func_0809511C);
    }

    return 1;
}
INCLUDE_ASM("card/func_08095520.s");
INCLUDE_ASM("card/func_080956AC.s");
INCLUDE_ASM("card/func_080958E0.s");
void func_08095A5C(UnkStruct_08095A5C* p) {
    p->unk_00 = gSineTable[(u8)p->unk_02] >> 8;
    p->unk_02 += 16;
}
void func_08095A78(UnkStruct_08095A5C* p, void* a, u8 b, u8 c) {
    AnimInit(&p->unk_10, gUnk_09EE7588[b], gUnk_09EE7598[b]);

    if ((s8)c >= 0) {
        AnimStart(&p->unk_10, (u16)(s8)c, 0);
    } else {
        AnimStart(&p->unk_10, 0, 0);
    }

    p->unk_60 = AnimGetGfx(&p->unk_10);
}
void func_08095AD8(UnkStruct_08095A5C* p, u16 a) {
    void* gfx;

    if (a <= 18) {
        AnimStart(&p->unk_10, a, 0);
        gfx = AnimGetGfx(&p->unk_10);
    } else {
        gfx = 0;
    }

    p->unk_60 = gfx;
}
#ifdef NON_MATCHING
void func_08095B04(u8* p, ReloadGageWork* w) {
    if (w->unk_9C > 0 && w->unk_A2 == 1) {
        switch (w->unk_40) {
        case 1:
            ApproachValue(&p[4], -0x3000, (u16)w->unk_9C);
            break;
        case 2:
            ApproachValue(&p[4], 0x12000, (u16)w->unk_9C);
            break;
        }
    } else {
        *(u32*)&p[4] = 0;
    }
}
#else
INCLUDE_ASM("card/func_08095B04.s");
#endif
void func_08095B50(UnkStruct_08095A5C* p, ReloadGageWork* w, u8 idx) {
    p->unk_0D = 2;
    AnimInit(&p->unk_28, gUnk_09EE75C8[idx], gUnk_09EE75B8[idx]);
    AnimStart(&p->unk_28, 1, 1);
    p->unk_58 = gUnk_09EE75B8[idx][3];
    AnimInit(&p->unk_40, gUnk_09EE75C8[idx], gUnk_09EE75B8[idx]);
    AnimStart(&p->unk_40, 2, 1);
    p->unk_5C = gUnk_09EE75B8[idx][6];
}
void func_08095BAC(UnkStruct_08095A5C* p) {
    p->unk_58 = AnimUpdate(&p->unk_28);
    p->unk_5C = AnimUpdate(&p->unk_40);
}
void func_08095BC8(UnkStruct_08095A5C* p, ReloadGageWork* w) {
    p->unk_58 = gUnk_09EE75B8[w->unk_46][3];
    p->unk_5C = gUnk_09EE75B8[w->unk_46][w->unk_A0 + 2];
}
void func_08095C00(UnkStruct_08095A5C* p) {
    if (p->unk_0D <= 3) {
        p->unk_0D++;
    }

    AnimStart(&p->unk_40, p->unk_0D, 5);
}
void func_08095C20(u8* p) {
    p[13] = 2;
}
void* func_08095C28(u8* w, u16 b, void* pool, u8 mode) {
    ReloadGageArgs args;

    args.unk_00 = &w[(s8)w[0xB8] * 16 + 0x54];
    args.unk_04 = 0;

    switch (mode) {
    case 1:
        if (gUnk_02039B84->unk_0F4 == 10) {
            args.unk_0C = b - 2;
        } else {
            args.unk_0C = b;
        }
        break;
    case 2:
        if (gUnk_02039B9C->unk_0F4 == 10) {
            args.unk_0C = b - 2;
        } else {
            args.unk_0C = b;
        }
        break;
    }

    args.unk_08 = mode;
    args.unk_0E = w[0xB8];
    return ((void**)TaskCreate(pool, gUnk_09EE7560, &args))[1];
}
INCLUDE_ASM("card/func_08095CA8.s");
INCLUDE_ASM("card/func_08095E68.s");
void func_080960D8(PrizeCardWork* w) {
    s32 cx = 0x7800;
    s32 cy = 0x5000;
    s32 v[2];

    v[0] = cx - w->unk_A8;
    v[1] = cy - w->unk_AC;
    w->unk_DC = func_0805F5A4(&v[0], &v[1]);
    w->unk_D4 = -v[0];
    w->unk_D8 = -v[1];
    w->unk_D0 = 0x300;
    w->unk_CC = 2;
}
u8 func_0809612C(PrizeCardWork* w, void* a) {
    s32 v[2];

    if (w->unk_D0 < 0) {
        v[0] = 0x7800 - w->unk_A8;
        v[1] = 0x5000 - w->unk_AC;
        func_0805F5A4(&v[0], &v[1]);
        w->unk_D4 = -v[0];
        w->unk_D8 = -v[1];

        if (w->unk_DC <= 0x7FF) {
            w->unk_FA = 0;
            w->unk_F6 = 0;
            func_08000F8C(a, (void*)func_08096288);
            func_08096F08(&w->unk_20, gCardDefs[w->unk_C8].unk_0C);
        }
    }

    w->unk_A8 += (w->unk_D4 * w->unk_D0) >> 8;
    w->unk_AC += (w->unk_D8 * w->unk_D0) >> 8;
    w->unk_F6 += 32;
    w->unk_F7 += (64 - w->unk_F7) >> 4;
    w->unk_F8 = 0;
    w->unk_DC = func_0805F588(0x7800 - w->unk_A8, 0x5000 - w->unk_AC);
    w->unk_D0 -= w->unk_CC;
    w->unk_CC += 2;

    if (w->unk_F2 <= 255) {
        w->unk_F2 += 3;
    }

    w->unk_E6 = w->unk_A8 >> 8;
    w->unk_E8 = w->unk_AC >> 8;
    func_08096638(w);

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        return 0;
    }

    return 1;
}
u8 func_08096288(PrizeCardWork* w, void* a) {
    s32 v;

    v = w->unk_F6 << 8;
    ApproachValue(&w->unk_F7, 0, w->unk_FA);
    ApproachValue(&v, 0, w->unk_FA);
    ApproachValue(&w->unk_A8, 0x7800, w->unk_FA);
    ApproachValue(&w->unk_AC, 0x5800, w->unk_FA);
    w->unk_F6 = v >> 8;

    if (w->unk_FA != 0) {
        w->unk_FA--;
    }

    if (w->unk_F2 <= 255) {
        w->unk_F2 += 2;
    } else {
        w->unk_F2 = 256;
    }

    w->unk_E6 = w->unk_A8 >> 8;
    w->unk_E8 = w->unk_AC >> 8;
    func_08096638(w);
    w->unk_FB++;

    if (w->unk_C8 > 0x1C2) {
        if (w->unk_FB == 120) {
            w->unk_FB = 0;
            func_08000F8C(a, (void*)func_08096390);
        }
    } else if (w->unk_FB == 30) {
        w->unk_FB = 0;
        func_08000F8C(a, (void*)func_08096390);
    }

    TaskPoolUpdate(&w->unk_20);

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        return 0;
    }

    return 1;
}
u8 func_08096390(PrizeCardWork* w) {
    w->unk_F6 += 32;
    w->unk_EA = (gUnk_02039BA0->unk_18 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    w->unk_EC = (gUnk_02039BA0->unk_1C >> 8) + (gUnk_02039BA0->unk_20 >> 8) -
                (gUnk_02039BA0->unk_04 >> 8);
    w->unk_E6 += (w->unk_EA - w->unk_E6) >> 3;
    w->unk_E8 += (w->unk_EC - w->unk_E8) >> 3;
    w->unk_E0 -= 10;
    w->unk_E2 -= 10;

    if (w->unk_E0 > 10 && !(gUnk_02039BA0->unk_70 & 0x40000)) {
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_08096428.s");
void func_080965CC(PrizeCardWork* w) {
    func_080062F4(w->unk_10->unk_06 + 16, 0);
    func_080062F4(w->unk_04->unk_06 + 16, 0);
    func_08012304(w->unk_4C);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjTiles(w->unk_0C);
    ReleaseObjTiles(w->unk_18);
    ReleaseObjPalette(w->unk_04);
    ReleaseObjPalette(w->unk_10);
    ReleaseObjPalette(w->unk_1C);
    TaskPoolDestroy(w->unk_20);
}

INCLUDE_ASM("card/func_08096638.s");
void func_080966B4(void* a, s32 b, s32 c, s32 d) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = func_08096D48(gUnk_02039BB0.unk_00C[0], 0);
    func_08096700(a, args);
}
void func_080966E4(void* a, s32 b, s32 c, s32 d, s32 e) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = e;
    func_08096700(a, args);
}

void func_08096700(void* a, void* b) {
    TaskCreate(a, gUnk_09EE75D8, b);
}
INCLUDE_ASM("card/func_08096714.s");
INCLUDE_ASM("card/func_08096738.s");
INCLUDE_ASM("card/func_08096994.s");
void func_08096C20(void* pool) {
    TaskPoolDraw(pool);
}
void func_08096C2C(void* pool) {
    TaskPoolDestroy(pool);
}

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
    if (gUnk_02039BB0.unk_008 & 8) {
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

void func_08096DC4(void* a, void* b) {
    TaskCreate(a, gUnk_09EE7608, b);
}
INCLUDE_ASM("card/func_08096DD8.s");
s32 func_08096E60(void) {
    return 1;
}
INCLUDE_ASM("card/func_08096E64.s");
void func_08096EC4(u8* work) {
    func_08065AE0(work, 32);
    ReleaseObjTiles(*(void**)&work[0x100]);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x104])->unk_06 + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x104]);
    ReleaseObjPalette(*(void**)&work[0x108]);
}

void func_08096F08(void* a, void* b) {
    TaskCreate(a, gUnk_09EE7620, b);
}
void func_08096F1C(u8* work) {
    *(void**)&work[0x00] = func_080668F0();
    *(void**)&work[0x04] = func_08066904();
    work[0x28] = func_0806692C(gUnk_081283C0, &work[0x08]);
}
s32 func_08096F44(void) {
    return 1;
}
void func_08096F48(u8* work) {
    func_08066DC0(0, 152, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}
void func_08096F70(s32* p) {
    func_08066918(p[0], p[1]);
}
s32 func_08096F80(void* a) {
    return (s32)TaskCreate(a, gUnk_09EE7638, 0);
}
INCLUDE_ASM("card/func_08096F94.s");
INCLUDE_ASM("card/func_08097138.s");
INCLUDE_ASM("card/func_08097390.s");
INCLUDE_ASM("card/func_08097404.s");
INCLUDE_ASM("card/func_0809753C.s");
INCLUDE_ASM("card/func_08097600.s");
INCLUDE_ASM("card/func_08097688.s");
INCLUDE_ASM("card/func_08097834.s");

INCLUDE_ASM("card/func_080978B0.s");
INCLUDE_ASM("card/func_0809792C.s");

void func_0809797C(void* a, void* b) {
    TaskCreate(a, gUnk_09EE7650, b);
}
INCLUDE_ASM("card/func_08097990.s");
INCLUDE_ASM("card/func_08097A14.s");
s32 func_08097A80(u8* work) {
    s32 v;

    ApproachValue(&work[0x08], 0, work[0x00]);

    if (work[0x00] != 0) {
        work[0x00]--;
    }

    v = ((*(s32*)&work[0x04] >> 8) << 8) | (*(s32*)&work[0x08] >> 8);
    *(u16*)&work[0x0C] = v;
    gBldAlpha = v;
    return 1;
}
void func_08097AB8(void) {
}
void func_08097ABC(void) {
    func_080062F4(13, 0);
}
INCLUDE_ASM("card/func_08097ACC.s");
INCLUDE_ASM("card/func_08097C84.s");
s32 func_08097DE4(u8* work) {
    u8* a;
    u8* b;

    a = &work[0x11E];

    if (*a <= 14) {
        (*a)++;
    }

    b = &work[0x11F];

    if (*b <= 14) {
        (*b)++;
    }

    func_080034EC(*a, *b);
    return 1;
}
INCLUDE_ASM("card/func_08097E18.s");
void func_08097FDC(u8* work) {
    s32 i;

    for (i = 0; i < work[0x121]; i++) {
        func_08098778((void**)&work[i * 52 + 8]);
    }

    ReleaseObjTiles(*(void**)&work[0x00]);
}

INCLUDE_ASM("card/func_08098014.s");
INCLUDE_ASM("card/func_080984E4.s");

void func_08098598(s32 a, s32 b, s32* c) {
    c[9] = a;
    c[10] = b;
}
INCLUDE_ASM("card/func_080985A0.s");

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
INCLUDE_ASM("card/func_080988C0.s");
INCLUDE_ASM("card/func_080989AC.s");
INCLUDE_ASM("card/func_08098AE4.s");
s32 func_08098BA4(u8* work) {
    ApproachValue(&work[0x20], 0, work[0x44]);
    ApproachValue(&work[0x24], 0, work[0x44]);
    ApproachValue(&work[0x28], 256, work[0x44]);

    if (work[0x44] != 0) {
        work[0x44]--;
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_08098BE8.s");
void func_08098CC4(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);

    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
    }
}
INCLUDE_ASM("card/func_08098CE4.s");
INCLUDE_ASM("card/func_08098E34.s");
INCLUDE_ASM("card/func_08098FDC.s");
INCLUDE_ASM("card/func_08099048.s");
INCLUDE_ASM("card/func_080990CC.s");
void func_08099180(u8* work) {
    DrawSprite(*(s32*)&work[0x3C] >> 8, *(s32*)&work[0x40] >> 8, 0,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 1024, 15);
}
void func_080991B4(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}

void func_080991CC(void* pool, u8* a, void* b, u8* c, u8 d) {
    UnkStruct_080991CC args;

    c[0] = 1;
    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_08 = c;
    args.unk_0C = a[0];
    args.unk_0D = d;
    TaskCreate(pool, gUnk_09EE76F0, &args);
}
INCLUDE_ASM("card/func_080991F8.s");
INCLUDE_ASM("card/func_080992A0.s");
INCLUDE_ASM("card/func_08099330.s");
void func_0809938C(u8* work) {
    DrawSprite(*(s32*)&work[0x24] >> 8, *(s32*)&work[0x28] >> 8,
               *(void**)&work[0x08], *(void**)&work[0x00], *(void**)&work[0x04], 0,
               0, 10);
}
void func_080993BC(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}
INCLUDE_ASM("card/func_080993D4.s");
INCLUDE_ASM("card/func_08099584.s");
INCLUDE_ASM("card/func_08099708.s");
INCLUDE_ASM("card/func_080998AC.s");

INCLUDE_ASM("card/func_08099928.s");
INCLUDE_ASM("card/func_080999A4.s");
INCLUDE_ASM("card/func_08099A18.s");
INCLUDE_ASM("card/func_08099B60.s");
INCLUDE_ASM("card/func_08099C4C.s");
INCLUDE_ASM("card/func_08099CDC.s");
INCLUDE_ASM("card/func_08099D88.s");
INCLUDE_ASM("card/func_08099E70.s");
INCLUDE_ASM("card/func_08099EE0.s");
void func_08099F20(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    (*(u8**)&work[0x48])[0]--;
}
INCLUDE_ASM("card/func_08099F40.s");
u8 func_08099F68(u8* p) {
    return p[22];
}
void func_08099F6C(void) {
}
void func_08099F70(void) {
}
void func_08099F74(u8* p) {
    if (p != 0) {
        p[22] = 0;
    }
}
void func_08099F80(u16* p) {
    if (p != 0) {
        if (p[9] != 0) {
            p[8]++;
            p[9]--;
        } else {
            p[9] = p[10] - 1;
            p[8] = 0;
        }
    }
}
void func_08099FA4(u16* p) {
    if (p != 0) {
        if (p[8] != 0) {
            p[8]--;
            p[9]++;
        } else {
            p[8] = p[10] - 1;
            p[9] = 0;
        }
    }
}
void func_08099FC8(u16* p) {
    if (p != 0) {
        p[10]--;
    }
}
void func_08099FD8(u16* p) {
    if (p != 0) {
        p[10]++;
    }
}
void func_08099FE8(u8* p, u16 b, u8 c) {
    if (p != 0) {
        *(u16*)&p[14] = b;
        p[23] = c;
    }
}
s32 func_08099FFC(void* pool, u16 a, u16 b, u16 c, u16 d, u16 e) {
    u16 args[5];

    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    args[4] = e;
    return (s32)((void**)TaskCreate(pool, gUnk_09EE7774, args))[1];
}
INCLUDE_ASM("card/func_0809A02C.s");
INCLUDE_ASM("card/func_0809A1B8.s");
INCLUDE_ASM("card/func_0809A368.s");

INCLUDE_ASM("card/func_0809A4E0.s");
INCLUDE_ASM("card/func_0809A54C.s");
INCLUDE_ASM("card/func_0809A840.s");
INCLUDE_ASM("card/func_0809AB2C.s");
INCLUDE_ASM("card/func_0809ACDC.s");
s32 func_0809AD60(u8* work, void* a) {
    *(u16*)&work[0x1C4] += 1;

    if (*(u16*)&work[0x1C4] == 60) {
        func_08000F8C(a, func_0809ACDC);
    }

    TaskPoolUpdate(&work[0x20]);
    return 1;
}
INCLUDE_ASM("card/func_0809AD98.s");
INCLUDE_ASM("card/func_0809AF84.s");
INCLUDE_ASM("card/func_0809B200.s");
INCLUDE_ASM("card/func_0809B3F4.s");
INCLUDE_ASM("card/func_0809B59C.s");
INCLUDE_ASM("card/func_0809B5F4.s");

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

void func_0809B6D0(void* pool, s16 a, s16 b, s16 c, u16 d) {
    s32 args[4];
    s32* t;

    t = gUnk_09EE275C[d];
    args[0] = a << 8;
    args[1] = b << 8;
    args[2] = c << 8;
    args[3] = t[0];
    TaskCreate(pool, gUnk_09EE77A4, args);
}
INCLUDE_ASM("card/func_0809B710.s");
INCLUDE_ASM("card/func_0809B76C.s");
INCLUDE_ASM("card/func_0809B840.s");
void func_0809B8F0(u8* work) {
    if (work[0x31] != 0) {
        DrawSprite(64, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0, 10);
    }
}
INCLUDE_ASM("card/func_0809B920.s");
INCLUDE_ASM("card/func_0809B9F4.s");
void func_0809BAA4(u8* work) {
    if (gUnk_02039B9C->unk_0F4 != 28 && work[0x31] != 0) {
        DrawSprite(120, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0,
                   10);
    }
}
void func_0809BAE4(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    gUnk_02039DD4->unk_0D9 = 0;
    work[0x31] = 0;
    gUnk_02039DD4->unk_0CA = 256;
}
void func_0809BB18(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    gUnk_02039DD4->unk_0D8 = 0;
    work[0x31] = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}
INCLUDE_ASM("card/func_0809BB4C.s");
INCLUDE_ASM("card/func_0809BE80.s");
INCLUDE_ASM("card/func_0809C078.s");
INCLUDE_ASM("card/func_0809C110.s");
INCLUDE_ASM("card/func_0809C1EC.s");
void func_0809C294(u8* work) {
    u8 i;

    for (i = 0; i < work[0x50]; i++) {
        (*(u8**)&work[0x24])[i * 12 + 6] = i;
        TaskCreate(&work[0x3C], gUnk_09EE781C, &(*(u8**)&work[0x24])[i * 12]);
    }
}
INCLUDE_ASM("card/func_0809C2D0.s");
INCLUDE_ASM("card/func_0809C448.s");
INCLUDE_ASM("card/func_0809C4B0.s");
INCLUDE_ASM("card/func_0809C534.s");
INCLUDE_ASM("card/func_0809C620.s");
INCLUDE_ASM("card/func_0809C710.s");
INCLUDE_ASM("card/func_0809C78C.s");
void func_0809C98C(void** work) {
    func_0809CAC8(work);

    if (work[6] != 0) {
        ReleaseObjTiles(work[6]);
    }
}

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

void func_0809CA1C(u8* work) {
    if (work[0x54] == 0) {
        *(void**)&work[0x0C] = LoadObjTiles(((void**)*(void**)&work[4])[3], 0x280);
        *(void**)&work[0x28] = LoadObjPalette(gUnk_09611AB8, 32);
        *(void**)&work[0x08] = LoadObjTiles(((void**)*(void**)&work[0])[1], 0x200);
        *(void**)&work[0x24] = LoadObjPalette(((void**)*(void**)&work[0])[2], 32);
        *(void**)&work[0x10] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
        *(void**)&work[0x1C] = LoadObjTiles(gUnk_0905ED36, 0x140);
        *(void**)&work[0x20] = LoadObjPalette(gUnk_08F69BA4, 32);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x20])->unk_06 + 16, 1);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x28])->unk_06 + 16, 1);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x24])->unk_06 + 16, 1);
        work[0x54] = 1;
    }
}

void func_0809CAC8(void* p) {
    u8* work;

    work = (u8*)p;

    if (work[0x54] != 0) {
        ReleaseObjTiles(*(void**)&work[0x0C]);
        ReleaseObjPalette(*(void**)&work[0x28]);
        ReleaseObjTiles(*(void**)&work[0x08]);
        ReleaseObjPalette(*(void**)&work[0x24]);
        ReleaseObjTiles(*(void**)&work[0x10]);
        ReleaseObjPalette(*(void**)&work[0x20]);
        ReleaseObjTiles(*(void**)&work[0x1C]);
        work[0x54] = 0;
    }
}
INCLUDE_ASM("card/func_0809CB0C.s");
INCLUDE_ASM("card/func_0809CB78.s");
s32 func_0809CBD0(u8* work) {
    *(void**)&work[0x44] = AnimUpdate(&work[0x2C]);

    if (*(u16*)&work[0x36] == 0 && *(u16*)&work[0x3A] == 4) {
        work[0x74] = 1;
    }

    return 1;
}
INCLUDE_ASM("card/func_0809CBF8.s");
INCLUDE_ASM("card/func_0809CC80.s");
s32 func_0809CDAC(void) {
    return 1;
}
INCLUDE_ASM("card/func_0809CDB0.s");
INCLUDE_ASM("card/func_0809CE38.s");
INCLUDE_ASM("card/func_0809CE88.s");
INCLUDE_ASM("card/func_0809CF64.s");
s32 func_0809D040(u8* work) {
    func_0809D124(work);
    *(s32*)&work[0x3C] += 8;

    if (*(s32*)&work[0x40] > 0) {
        *(s32*)&work[0x40] += -0x180;
        *(void**)&work[0x08] = AnimUpdate(&work[0x0C]);
        return 1;
    }

    return 0;
}
s32 func_0809D074(u8* work) {
    func_0809D160(work);
    *(void**)&work[0x08] = AnimUpdate(&work[0x0C]);

    if (*(s32*)&work[0x34] > 0xB400) {
        return 0;
    }

    return 1;
}
s32 func_0809D09C(u8* work) {
    func_0809D1B0(work);
    *(s32*)&work[0x3C] += 8;
    *(void**)&work[0x08] = AnimUpdate(&work[0x0C]);

    if (*(s32*)&work[0x40] <= 0x800) {
        return 0;
    }

    return 1;
}
void func_0809D0CC(u8* work) {
    DrawSprite(*(s32*)&work[0x30] >> 8, *(s32*)&work[0x34] >> 8,
               *(void**)&work[0x08], *(void**)&work[0x00], *(void**)&work[0x04], 0,
               0, 0);
}
void func_0809D0FC(void** work) {
    ReleaseObjTiles(work[0]);
    ReleaseObjPalette(work[1]);
    gUnk_0203A9D0[0x28]--;
}

void func_0809D124(u8* work) {
    *(s32*)&work[0x30] = gSineTable[*(s32*)&work[0x3C] & 0xFF] *
                             (*(s32*)&work[0x40] >> 8) +
                         *(s32*)&work[0x24];
    *(s32*)&work[0x34] = -gSineTable[(*(s32*)&work[0x3C] & 0xFF) + 64] *
                             (*(s32*)&work[0x40] >> 8) +
                         *(s32*)&work[0x28];
}
INCLUDE_ASM("card/func_0809D160.s");
void func_0809D1B0(u8* work) {
    s32 v;
    s32 d;

    *(s32*)&work[0x44] = *(s32*)&work[0x24] - *(s32*)&work[0x30];
    *(s32*)&work[0x48] = *(s32*)&work[0x28] - *(s32*)&work[0x34];
    *(s32*)&work[0x40] = func_0805F5A4((s32*)&work[0x44], (s32*)&work[0x48]);
    v = *(s32*)&work[0x4C];
    d = v >> 8;
    *(s32*)&work[0x30] += *(s32*)&work[0x44] * d;
    *(s32*)&work[0x34] += *(s32*)&work[0x48] * d;

    if (*(s32*)&work[0x40] > 0) {
        *(s32*)&work[0x4C] = v - 2;
    }
}
INCLUDE_ASM("card/func_0809D1FC.s");
void func_0809D26C(void) {
    EwramFree(gUnk_02034AD4);
}

#ifdef NON_MATCHING
u8 func_0809D280(u8* p) {
    u8 n;
    u8 c;

    n = 0;

    if (p == 0) {
        return 0;
    }

    c = *p;
    p++;

    while (c != 0) {
        c = *p;

        if (c != 0) {
            n++;
        }

        p++;
    }

    return n + 1;
}
#else
INCLUDE_ASM("card/func_0809D280.s");
#endif

INCLUDE_ASM("card/func_0809D2B0.s");
void func_0809D3F0(void) {
    gUnk_02034AD8 = 0;
}
INCLUDE_ASM("card/func_0809D3FC.s");

INCLUDE_ASM("card/func_0809D458.s");
INCLUDE_ASM("card/func_0809D87C.s");
INCLUDE_ASM("card/func_0809D900.s");
INCLUDE_ASM("card/func_0809D998.s");
void func_0809DA38(void) {
    TaskPoolUpdate(gUnk_02034AE0);
    TaskPoolDraw(gUnk_02034AE0);
}
void func_0809DA54(void) {
    TaskPoolDestroy(gUnk_02034AE0);
}
INCLUDE_ASM("card/func_0809DA64.s");
INCLUDE_ASM("card/func_0809DB70.s");
INCLUDE_ASM("card/func_0809DCB8.s");
u8 func_0809DE18(u8* p) {
    if (p[25] != 1) {
        if (p[25] != 2) {
            return 0;
        }
    }

    if (*(u16*)&p[30] != 37) {
        return 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_0809DE30.s");
INCLUDE_ASM("card/func_0809DF7C.s");
void func_0809E064(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjTiles(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x10]);
    gUnk_02039DD4->unk_0D8 = 0;
    gUnk_02039DD4->unk_0E5 = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}
INCLUDE_ASM("card/func_0809E0A4.s");
s32 func_0809E0F8(u8* work) {
    s32 v;

    v = *(s16*)&work[0x26] << 8;

    if (work[0x28] != 0) {
        ApproachValue(&v, *(s32*)&work[0x10] - 0x2800, work[0x28]);
        *(s16*)&work[0x26] = v >> 8;
        work[0x28]--;
        return 1;
    }

    return 0;
}
void func_0809E13C(u8* work) {
    DrawSprite(*(s16*)&work[0x24], *(s16*)&work[0x26], gUnk_09EE91A8[0],
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 16, 0);
}
void func_0809E170(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}
INCLUDE_ASM("card/func_0809E188.s");

void func_0809E7A4(void) {
    u32 base;

    if (*(u32*)&gUnk_02039B84->unk_100[0x0C] == 151) {
        base = GetBgCharBase(0);
        RequestDma3Copy(gUnk_093FEEB8, (void*)(base + 0x2480), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x400], (void*)(base + 0x25A0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x800], (void*)(base + 0x26C0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[288], (void*)(base + 0x27E0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x520], (void*)(base + 0x2900), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x920], (void*)(base + 0x2A20), 288);
        RequestDma3Copy(gUnk_093FD438, (void*)(base + 0x2C00), 0xA80);
    } else {
        base = GetBgCharBase(1);
        RequestDma3Copy(gUnk_093FEEB8, (void*)(base + 0x2480), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x400], (void*)(base + 0x25A0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x800], (void*)(base + 0x26C0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[288], (void*)(base + 0x27E0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x520], (void*)(base + 0x2900), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x920], (void*)(base + 0x2A20), 288);
        RequestDma3Copy(gUnk_093FD438, (void*)(base + 0x2C00), 0xA80);
    }
}
INCLUDE_ASM("card/func_0809E8E8.s");
INCLUDE_ASM("card/func_0809F390.s");
INCLUDE_ASM("card/func_0809F730.s");
INCLUDE_ASM("card/func_0809FBCC.s");
u8 func_0809FE14(void) {
    if (func_08006314() == 0) {
        return 0;
    }
    return 1;
}
INCLUDE_ASM("card/func_0809FE2C.s");
void func_080A05FC(u8* work) {
    func_08065AE0(&work[0x20], 36);
    func_08065AE0(&work[0x140], 36);
    func_08065AE0(&work[0x260], 36);
    func_08065AE0(&work[0x380], 36);
    func_08065AE0(&work[0x4A0], 36);
    func_08065AE0(&work[0x5C0], 36);

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x1C]);
    }

    if (*(void**)&work[0x00] != 0) {
        ReleaseObjTiles(*(void**)&work[0x00]);
    }

    if (*(void**)&work[0x04] != 0) {
        ReleaseObjTiles(*(void**)&work[0x04]);
    }

    if (*(void**)&work[0x08] != 0) {
        ReleaseObjTiles(*(void**)&work[0x08]);
    }

    if (*(void**)&work[0x10] != 0) {
        ReleaseObjPalette(*(void**)&work[0x10]);
    }

    if (*(void**)&work[0x14] != 0) {
        ReleaseObjPalette(*(void**)&work[0x14]);
    }

    if (*(void**)&work[0x6E0] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6E0]);
    }

    if (*(void**)&work[0x6E4] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6E4]);
    }

    if (*(void**)&work[0x6E8] != 0) {
        ReleaseObjTiles(*(void**)&work[0x6E8]);
    }

    if (*(void**)&work[0x6EC] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6EC]);
    }

    if (*(void**)&work[0x6F0] != 0) {
        ReleaseObjTiles(*(void**)&work[0x6F0]);
    }

    if (*(void**)&work[0x6F4] != 0) {
        ReleaseObjTiles(*(void**)&work[0x6F4]);
    }

    if (*(void**)&work[0x6F8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6F8]);
    }

    if (*(void**)&work[0x728] != 0) {
        ReleaseObjTiles(*(void**)&work[0x728]);
    }

    if (*(void**)&work[0x72C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x72C]);
    }

    TaskPoolDestroy(&work[0x6FC]);
}
INCLUDE_ASM("card/func_080A0734.s");

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
INCLUDE_ASM("card/func_080A0A44.s");
INCLUDE_ASM("card/func_080A11CC.s");

s32 func_080A151C(void) {
    if (gUnk_02039BB0.unk_108 >= gUnk_09037FBA[gUnk_02039BB0.unk_178]) {
        return 1;
    }

    return 0;
}

void func_080A1554(u8* work) {
    s16 x;
    s16 y;
    s32* t;

    t = *(s32**)&work[0x0C];

    if (t != 0) {
        WorldToScreen(&x, &y, t[1], t[2], t[3]);
        *(s32*)&work[0x64] = x;
        *(s32*)&work[0x68] = y - 16;
    }
}
INCLUDE_ASM("card/func_080A158C.s");
INCLUDE_ASM("card/func_080A16F0.s");
INCLUDE_ASM("card/func_080A18F4.s");
INCLUDE_ASM("card/func_080A1990.s");
void func_080A19F8(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    TaskPoolDestroy(&work[0x98]);

    if (gUnk_02039B84->unk_068 & 0x20000) {
        gUnk_02039B84->unk_068 &= ~0x20000;
    }
}
INCLUDE_ASM("card/func_080A1A44.s");
s32 func_080A1AB0(u8* work) {
    *(s32*)&work[0x44] += *(s32*)&work[0x6C];
    *(s32*)&work[0x6C] += 25;
    func_080A1554(work);
    *(s32*)&work[0x34] = *(s32*)&work[0x64] << 8;
    ((s8*)work)[0x95]++;

    if (((s8*)work)[0x95] == 60) {
        return 0;
    }

    return 1;
}
void func_080A1AE8(u8* work) {
    DrawSprite(*(s32*)&work[0x34] >> 8, *(s32*)&work[0x44] >> 8,
               gUnk_09EEA19C[((s8*)work)[0x94]], *(void**)&work[0x00],
               *(void**)&work[0x04], 0, 0, 10);
}
void func_080A1B2C(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
    gUnk_02034AF8 = 0;
}

INCLUDE_ASM("card/func_080A1B4C.s");
INCLUDE_ASM("card/func_080A1BB8.s");
void func_080A1C48(u8* work) {
    UnkStruct_080A1C48* w;
    u8 i;

    w = (UnkStruct_080A1C48*)work;

    for (i = 0; i <= 9; i++) {
        if (w->unk_04[i] != 0) {
            ReleaseObjTiles(w->unk_04[i]);
            ReleaseObjPalette(w->unk_2C[i]);
        }
    }
}
void func_080A1C7C(u8* work, u8* a) {
    void** t;

    work[0] = a[0];
    t = gUnk_09EE3CA0[work[0]];

    if (t[10] != 0) {
        func_080A1BB8(work, t);
        *(void**)&work[0x58] = t[10];
    }
}
INCLUDE_ASM("card/func_080A1CAC.s");
INCLUDE_ASM("card/func_080A1CF0.s");
void func_080A1DA0(u8* work) {
    func_080A1C48(work);
}
INCLUDE_ASM("card/func_080A1DAC.s");
void func_080A1E4C(void) {
    LoadBgTiles(0, gUnk_094233B8, 1280);
    LoadBgPalette(0, gUnk_096148D8, 32);
    LoadBgMap(0, gUnk_08125E24, 2048);
}
INCLUDE_ASM("card/func_080A1E80.s");
void func_080A1ED8(u8* work) {
    u8* t;
    u16 v;

    v = 16;
    t = *(u8**)&work[0x00] + work[0x14] * 16;
    func_080062F4(14, 1);

    if (*(s32*)&t[4] > 0) {
        v = *(s32*)&t[4];
    }

    if (*(u16*)&t[12] & 0x10) {
        func_08006120(0, v);
    } else {
        func_080061E8(0, v);
    }
}
void func_080A1F18(u8* a, u8* b) {
    u8 t;
    u8 z;

    t = b[0];
    z = 0;
    a[19] = t;
    a[20] = z;
    a[21] = z;
    *(void**)&a[0] = gUnk_09EE3FB4[a[19]][5];
}
INCLUDE_ASM("card/func_080A1F38.s");
INCLUDE_ASM("card/func_080A2024.s");
INCLUDE_ASM("card/func_080A207C.s");
void func_080A211C(void) {
}
void func_080A2120(void) {
}
void func_080A2124(u8* work) {
    TaskCreate(&work[0x10], gUnk_09EE79D4, work);
}
INCLUDE_ASM("card/func_080A2138.s");
INCLUDE_ASM("card/func_080A2230.s");
s32 func_080A22A4(u8* work) {
    if ((*(u8**)&work[0x14])[0] == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x18]);
    return 1;
}
void func_080A22C4(u8* work) {
    DrawSprite(*(s32*)&work[0x08] >> 8, *(s32*)&work[0x0C] >> 8, gUnk_09EEA28C,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    TaskPoolDraw(&work[0x18]);
}
void func_080A2304(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    gUnk_02039BB0.unk_178++;
    TaskPoolDestroy(&work[0x18]);
}

void* func_080A2334(u16 a, u8 b) {
    if (b < gUnk_09EE7D84[a]->unk_04) {
        return gUnk_09EE7D84[a]->unk_00[b];
    }

    return 0;
}

u8 func_080A235C(u16 a) {
    return gUnk_09EE7D84[a]->unk_04;
}
u8 func_080A2370(void) {
    if (gUnk_02039BB0.unk_108 >= gUnk_0903BFD4[gUnk_02039BB0.unk_178]) {
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_080A23A0.s");
s32 func_080A25B8(u8* work, void* a) {
    func_08000F8C(a, func_080A25E0);
    work[0x2B1]++;
    return 1;
}
INCLUDE_ASM("card/func_080A25E0.s");
INCLUDE_ASM("card/func_080A2678.s");
INCLUDE_ASM("card/func_080A27EC.s");
INCLUDE_ASM("card/func_080A2844.s");
INCLUDE_ASM("card/func_080A2980.s");
INCLUDE_ASM("card/func_080A2A80.s");
INCLUDE_ASM("card/func_080A2BA4.s");
INCLUDE_ASM("card/func_080A2CC4.s");
s32 func_080A2DE4(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 8) ||
        (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080A2E14.s");
INCLUDE_ASM("card/func_080A2EF8.s");
INCLUDE_ASM("card/func_080A2F54.s");
s32 func_080A30C0(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080A30E4.s");

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

void func_080A3370(u8* p) {
    s32 i;

    for (i = 0; i <= 0x10D; i++) {
        p[i] = gUnk_0203A8C0[i];
    }
}
void func_080A3398(u8* p) {
    u16 i;

    for (i = 0; i <= 0x10D; i++) {
        gUnk_0203A8C0[i] = p[i];
    }
}
INCLUDE_ASM("card/func_080A33C4.s");
INCLUDE_ASM("card/func_080A3558.s");
INCLUDE_ASM("card/func_080A3640.s");
INCLUDE_ASM("card/func_080A36B0.s");
INCLUDE_ASM("card/func_080A3754.s");
INCLUDE_ASM("card/func_080A3848.s");
INCLUDE_ASM("card/func_080A3A04.s");
INCLUDE_ASM("card/func_080A3A98.s");
INCLUDE_ASM("card/func_080A3BB0.s");
INCLUDE_ASM("card/func_080A3DD0.s");
INCLUDE_ASM("card/func_080A3E8C.s");
INCLUDE_ASM("card/func_080A3F5C.s");
INCLUDE_ASM("card/func_080A4010.s");

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

void func_080A41F0(void* pool, u16 a) {
    UnkStruct_080A4188 args;

    func_080A42C8();
    args.unk_00 = 0;
    args.unk_04 = a;
    args.unk_07 = 3;
    TaskCreate(pool, gUnk_09EE8E30, &args);
}

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

u8 func_080A42E0(void) {
    if (gUnk_02034AFC != 0) {
        gUnk_02034AFC->unk_14F = 0;
        return 1;
    }

    return func_080A4DAC();
}
INCLUDE_ASM("card/func_080A430C.s");
INCLUDE_ASM("card/func_080A4578.s");
INCLUDE_ASM("card/func_080A470C.s");
s32 func_080A4910(u8* work) {
    if (*(void**)&work[0x00] != 0) {
        *(void**)&work[0x128] = AnimUpdate(&work[0xDC]);
    }

    *(s16*)&work[0x136] += 1;

    if (*(s16*)&work[0x136] > 15) {
        work[0x141] = 0;
        return 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080A4958.s");
INCLUDE_ASM("card/func_080A4A50.s");
INCLUDE_ASM("card/func_080A4C1C.s");
INCLUDE_ASM("card/func_080A4CC8.s");

s32 func_080A4D7C(u64* src) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_10C = *src;
        gUnk_02034B00->unk_145 = 1;

        return 1;
    }

    return 0;
}

s32 func_080A4DAC(void) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_146[0] = 0;
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_080A4DCC.s");
INCLUDE_ASM("card/func_080A4F14.s");
INCLUDE_ASM("card/func_080A5034.s");
s32 func_080A5150(u8* work) {
    if (*(void**)&work[0x00] != 0) {
        *(void**)&work[0x128] = AnimUpdate(&work[0xDC]);
    }

    *(s16*)&work[0x136] += 1;

    if (*(s16*)&work[0x136] > 15) {
        work[0x141] = 0;
        return 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080A5198.s");
INCLUDE_ASM("card/func_080A52BC.s");
INCLUDE_ASM("card/func_080A53E4.s");
INCLUDE_ASM("card/func_080A5490.s");
INCLUDE_ASM("card/func_080A55B8.s");
INCLUDE_ASM("card/func_080A5704.s");
void func_080A57F8(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjTiles(p[2]);
    ReleaseObjPalette(p[1]);
    ReleaseObjPalette(p[3]);
}
void func_080A581C(u8* work) {
    TaskCreate(&work[0x10], gUnk_09EE8ED8, work);
}

void func_080A5830(void* a, s32 b, s32 c, s32 d) {
    s32 args[3];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    TaskCreate(a, gUnk_09EE8ED8, args);
}
INCLUDE_ASM("card/func_080A584C.s");
void func_080A5C20(u8* work) {
    func_080664D8(*(s16*)&work[0x4D8], *(s16*)&work[0x4DA], &work[0x1E0],
                  *(void**)&work[0x14], 20, work[0x4FE]);
}

void func_080A5C60(u8* work, u16 card) {
    CardDef* d;

    d = &gCardDefs[card];
    work[0x4FE] = func_08065B6C(gUnk_09EE8F48[d->unk_1C], &work[0x1E0]);
}
INCLUDE_ASM("card/func_080A5C9C.s");
INCLUDE_ASM("card/func_080A5D3C.s");
INCLUDE_ASM("card/func_080A5EA0.s");
INCLUDE_ASM("card/func_080A5F70.s");
INCLUDE_ASM("card/func_080A5FF4.s");
s32 func_080A6388(u8* work) {
    if (func_08006314() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x40C]);
    TaskPoolUpdate(&work[0x420]);
    return 1;
}
INCLUDE_ASM("card/func_080A63B8.s");
INCLUDE_ASM("card/func_080A6474.s");
INCLUDE_ASM("card/func_080A6500.s");
INCLUDE_ASM("card/func_080A676C.s");
INCLUDE_ASM("card/func_080A6838.s");
void func_080A6968(u8* work) {
    UnkStruct_0808E890* node;

    node = func_08000C8C(&work[0x434]);

    while (node != 0) {
        node->unk_4A = 1;
        node = func_08000CD4(&node->unk_2C);
    }

    TaskPoolUpdate(&work[0x40C]);
}
INCLUDE_ASM("card/func_080A69A0.s");
INCLUDE_ASM("card/func_080A6A38.s");
INCLUDE_ASM("card/func_080A6AE8.s");

INCLUDE_ASM("card/func_080A6B40.s");
INCLUDE_ASM("card/func_080A6BB4.s");
INCLUDE_ASM("card/func_080A6C50.s");
INCLUDE_ASM("card/func_080A6D0C.s");
INCLUDE_ASM("card/func_080A6E3C.s");

void func_080A6EB4(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
    work[0x4FD] = func_08065B6C(def->unk_0C, &work[0xF0]);

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    }
}

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

void func_080A7180(u8 a) {
    u8 v[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        v[0] = a / 10;
        v[1] = a - v[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(v[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(v[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}
void func_080A7210(u8* work) {
    void** p;
    u16 i;

    if (*(void**)&work[0x3E8] != 0) {
        for (i = 0; i < *(u16*)&work[0x4DC]; i++) {
            EwramFree(((UnkStruct_0808E2F0*)*(void**)&work[0x3E8])[i].unk_1C);
        }

        p = (void**)&work[0x3E8];
        EwramFree(*p);
        *p = 0;
    }
}
void func_080A7264(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}
void func_080A7284(u8* work, u8 mode) {
    switch (mode) {
    case 0:
        func_08002A10(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x45C], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x45C], 0, 1);
        *(void**)&work[0x404] = AnimGetGfx(&work[0x45C]);
        break;
    case 1:
        func_08002A10(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x45C], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x45C], 0, 1);
        *(void**)&work[0x404] = AnimGetGfx(&work[0x45C]);
        break;
    }
}
u8 func_080A7300(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gUnk_02039BB0.unk_0FA) {
        TaskCreate(&work[0x420], gUnk_09EE7FA8, &work[0x501]);
        m4aSongNumStart(0x69);
        return 0;
    }

    return 1;
}
u8 func_080A734C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(0x69);
        TaskCreate(&work[0x420], gUnk_09EE7FC0, &work[0x501]);
        return 0;
    }

    return 1;
}
u8 func_080A7388(u8* work, s16 x, s16 y, u16 dir) {
    UnkStruct_0808E890* node;

    node = func_08000C8C(&work[0x434]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = func_08000CD4(&node->unk_2C);
    }

    switch (dir) {
    case 64:
        return func_080A7388(work, x, y - 1, 64);
    case 128:
        return func_080A7388(work, x, y + 1, 128);
    case 32:
        return func_080A7388(work, x - 1, y, 32);
    case 16:
        return func_080A7388(work, x + 1, y, 16);
    }

    return 0;
}
INCLUDE_ASM("card/func_080A7464.s");
INCLUDE_ASM("card/func_080A77D8.s");
INCLUDE_ASM("card/func_080A7914.s");
INCLUDE_ASM("card/func_080A7ABC.s");
INCLUDE_ASM("card/func_080A7C80.s");
INCLUDE_ASM("card/func_080A8020.s");
#ifdef NON_MATCHING
u8 func_080A82E0(u8* work, void* a) {
    func_08006120(0, 4);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 0, 15, 0);
    SetupBg(1, 0, 23, 0);
    SetupBg(0, 0, 31, 0);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    SetBgScroll(2, 0, 16);
    LoadBgMap(3, gUnk_09515AB8, 0x800);
    LoadBgMap(2, gUnk_095182B8, 0x800);
    LoadBgMap(1, gUnk_09514AB8, 0x800);
    DisableBg(0);
    func_0808500C(3, (u16*)&work[0x6E2]);
    func_0808CC58(*(u16*)&work[0x6E2], 0);
    func_0808CC58(*(u16*)&work[0x6E4], 1);
    func_0808CC58(*(u16*)&work[0x6E6], 2);
    func_0808CC58(*(u16*)&work[0x6E8], 3);
    work[0x6F0] = 9;
    func_080AAA8C(work, 0);
    func_080A9968(work);
    work[0x715] = 0;
    func_08000F8C(a, (void*)func_080A8430);
    *(u16*)&work[0x6C4] = 0xFFFE;
    *(u16*)&work[0x6C6] = 142;
    *(u16*)&work[0x6C8] = 142;
    *(u16*)&work[0x6CA] = 142;
    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A82E0.s");
#endif
INCLUDE_ASM("card/func_080A8430.s");
INCLUDE_ASM("card/func_080A86F4.s");
u8 func_080A8BD8(u8* work, void* a) {
    func_08006184(0, 16);
    work[0x701] = 0;
    func_08000F8C(a, (void*)func_080A8C20);
    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}
u8 func_080A8C20(u8* work) {
    if (func_08006314() == 0) {
        func_080A9968(work);
        return 0;
    }

    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}

INCLUDE_ASM("card/func_080A8C58.s");

void func_080A8EE4(u8* work) {
    func_080664D8(*(s16*)&work[0x708], *(s16*)&work[0x70A], &work[0x1D8],
                  *(void**)&work[0x0C], 20, work[0x70C]);
}
INCLUDE_ASM("card/func_080A8F24.s");
INCLUDE_ASM("card/func_080A9598.s");
INCLUDE_ASM("card/func_080A968C.s");

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
INCLUDE_ASM("card/func_080A99A0.s");
INCLUDE_ASM("card/func_080A9A38.s");
INCLUDE_ASM("card/func_080A9AE8.s");
INCLUDE_ASM("card/func_080A9B84.s");

INCLUDE_ASM("card/func_080A9E40.s");
INCLUDE_ASM("card/func_080A9F08.s");
INCLUDE_ASM("card/func_080A9FF4.s");
INCLUDE_ASM("card/func_080AA148.s");

INCLUDE_ASM("card/func_080AA1F8.s");
INCLUDE_ASM("card/func_080AA328.s");

void func_080AA3A0(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
    work[0x705] = func_08065B6C(def->unk_0C, &work[0xE8]);

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    }
}

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
INCLUDE_ASM("card/func_080AAA38.s");

INCLUDE_ASM("card/func_080AAA8C.s");
INCLUDE_ASM("card/func_080AAB08.s");

s32 func_080AAC40(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gUnk_02039BB0.unk_0FA) {
        TaskCreate(&work[0x628], gUnk_09EE7FA8, &work[0x70D]);
        m4aSongNumStart(105);

        return 0;
    }

    return 1;
}

u8 func_080AAC8C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(105);
        TaskCreate(&work[0x628], gUnk_09EE7FC0, &work[0x70D]);
        return 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080AACC8.s");
INCLUDE_ASM("card/func_080AAD2C.s");

INCLUDE_ASM("card/func_080AAD84.s");
INCLUDE_ASM("card/func_080AADD4.s");

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
void func_080AAF78(void) {
    gUnk_02034B1C = 0;
    gUnk_0203A9DC = 2048;
    TaskPoolInit(gUnk_02034B08, 1);
    TaskCreate(gUnk_02034B08, gUnk_09EE8F08, &gUnk_02034B1C);
}
void func_080AAFB4(void) {
    if (gUnk_03006C78 & 1) {
        func_080B31A0();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(gUnk_02034B08);
    TaskPoolDraw(gUnk_02034B08);

    if (gUnk_02034B1C == 6) {
        func_080010CC(&gUnk_09EF15A8, gUnk_0203A9DC);
    }
}
void func_080AB008(void) {
    TaskPoolDestroy(gUnk_02034B08);
}
void func_080AB018(u8* work) {
    *(void**)&work[0x00] = LoadObjTiles(gUnk_093FB6C4, 576);
    work[0x0A] = 8;
    *(s32*)&work[0x04] = -0x2000;
    func_0806BA0C(gUnk_02039B84->unk_1C8, &work[0x0B]);
}
s32 func_080AB058(u8* work) {
    func_0806BA0C(gUnk_02039B84->unk_1C8, &work[0x0B]);

    if (((s8*)work)[0x0A] > 0) {
        ApproachValue(&work[0x04], 0, (u16)((s8*)work)[0x0A]);
        work[0x0A]--;
    }

    return 1;
}
INCLUDE_ASM("card/func_080AB09C.s");
void func_080AB1EC(void** p) {
    ReleaseObjTiles(p[0]);
}

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

void func_080AB968(void) {
}
void func_080AB96C(void* a) {
    func_08006120(0, 16);
    gUnk_02034B34 = a;
    TaskPoolInit(gUnk_02034B20, 1);
    gUnk_0203A9E0 = 0;
}
void func_080AB99C(void) {
    u16 t;

    t = gUnk_02039BB0.unk_17A | 0x1000;
    gUnk_02039BB0.unk_17A = t;
    func_080010CC(&gUnk_09ECEB40, (s32)gUnk_02034B34);
    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}
INCLUDE_ASM("card/func_080AB9E0.s");
void func_080ABA70(void) {
    TaskPoolDestroy(gUnk_02034B20);
}

INCLUDE_ASM("card/func_080ABA80.s");

INCLUDE_ASM("card/func_080ABCA4.s");

u8 func_080ABED0(void) {
    if ((*(u32*)&gUnk_02039DD4->unk_0E0 & 0x00FFFF00) != 0) {
        return gUnk_02039DD4->unk_0DD;
    }

    return 0;
}

INCLUDE_ASM("card/func_080ABEF8.s");
INCLUDE_ASM("card/func_080AC140.s");
u8 func_080AC5BC(UnkStruct_02034AAC** p, u8 a) {
    u8 x;
    u8 y;
    u8 z;

    if (a != 3) {
        return 0;
    }

    x = p[0]->unk_A5;
    y = p[1]->unk_A5;
    z = p[2]->unk_A5;

    if (x != y) {
        return 0;
    }

    if (x != z) {
        return 0;
    }

    return 1;
}

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

u8 func_080AE274(s32 a, s32 b) {
    u8 r;

    if (b != 0) {
        r = func_0800FCD8(a, b);
    } else {
        r = func_0800FC90(a);
    }

    return r;
}
INCLUDE_ASM("card/func_080AE28C.s");
void task_print_0(void) {
    func_0809D1FC(0);
}
s32 task_print_1(void) {
    return 1;
}
void task_print_2(void) {
    func_0809D3F0();
}
void task_print_3(void) {
    func_0809D26C();
}
INCLUDE_ASM("card/func_080AE594.s");
INCLUDE_ASM("card/func_080AE7CC.s");
INCLUDE_ASM("card/func_080AEB40.s");

void func_080AEB94(void) {
    gUnk_0203A9E8 = 0;
}
