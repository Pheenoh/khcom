#include "macros.h"
#include "anim.h"
#include "text_types.h"
#include "taskpool.h"
#include "key.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "card.h"

extern UnkStruct_02034AAC* gUnk_02034A98;

u32 gUnk_02034AA4;
u32 gUnk_02034AA8;
UnkStruct_02034AAC* gUnk_02034AAC;
u8 gActiveDeck;
u8 gUnk_02034AB1[3];
s16 gUnk_02034AB4;
u8 gUnk_02034AB6[2];
#ifdef VERSION_EU
u8 gUnkEu_02034AD4[4];
#endif
u8 gUnk_02034AB8[20];
u8 gUnk_02034ACC;
u32 gUnk_02034AD0;
void* gUnk_02034AD4;
u8 gUnk_02034AD8;
u8 gUnk_02034AD9;
u8 gUnk_02034ADA[6];
u8 gUnk_02034AE0[20];
#ifndef VERSION_EU
u8 gUnk_02034AF4[4];
#endif
u8 gUnk_02034AF8;
UnkStruct_02034AFC* gUnk_02034AFC;
UnkStruct_02034AFC* gUnk_02034B00;
#ifndef VERSION_EU
u8 gUnk_02034B04[4];
u8 gUnk_02034B08[20];
u8 gUnk_02034B1C;
u8 gUnk_02034B1D[3];
#endif
u8 gUnk_02034B20[20];
void* gUnk_02034B34;
#ifdef VERSION_EU
u8 gUnk_02034B04[4];
u8 gUnk_02034B08[20];
u8 gUnk_02034B1C;
u8 gUnk_02034B1D[3];
#endif
#include "game.h"

void LoadBgTiles(s32 bg, void* src, u16 size);
extern u8 gUnk_0950E2F8[];
extern u8 gUnk_096112B8[];
u8 func_080A470C(u8* work, void* a);
u8 func_080A4CC8(u8* work, void* a);
void func_0808DB04(void** p);
void func_0808CDE8(u8* work, u8 b);
u16 func_0806BA74(s32 mode, s32 flag);
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_080DFF4C(void* p);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void* TaskCreate(void* a, void* desc, void* args);
u8 func_08085290(u16 a);
void func_080938F8(u16 a);
u16 func_080857D4(u8 slot);
u16 func_08065B6C(u16* a, TextSlot* b);
s16 func_08065B08(TextSlot* p, u8 n);
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
u16 func_08084458(u16 a);
u16 func_08093B38(void);
u16 func_08093B08(u16 a);
u16 func_08096C38(UnkStruct_08096C38* tbl, u16 n);
u16 func_08096CCC(void);
u8 func_0807CE68(UnkStruct_02034AAC* p);
void func_0807C39C(UnkStruct_02034AAC* p);
void func_0807C33C(UnkStruct_02034AAC* p);
UnkStruct_0808E890* ListPoolFirst(void* node);
UnkStruct_0808E890* ListPoolNext(void* node);
void TaskPoolUpdate(TaskPool* a);
void func_0808DE28(u8 a);
s32 func_080609AC(u16 a);
s32 func_0808C8D0(s32 a);
void func_08065ACC(TextSlot* p, s32 n);
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
void m4aSongNumStop(u16 n);
u8 func_0807EDEC(UnkStruct_08080268* w, void* a);
void TaskPoolDestroy(TaskPool* a);
u8 func_08006314(void);
void* AnimUpdate(AnimState* a);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void func_08000D20(void* a, void* b, void* c);
void func_08000D28(void* a, void* b);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_08006184(s32 a, s32 b);
void SetTaskUpdate(u8* p, u32 v);
u8 func_080A8C20(u8* work);
void AnimInit(AnimState* a, s32 b, s32 c);
s32 func_0805F5A4(s32* a, s32* b);
s32* func_080E04E0(void);
void func_0809511C(void);
void func_080062F4(u16 a, s32 b);
void func_08012304(void* a);
void func_0808E364(u8* work, u8 b);
void func_08088F24(void);
void func_08002A10(void* a, void* b);
void func_0805F1C0(s32* p, s32 v);
void func_0808D6C4(u8* work);
void func_0808CD48(u8* work);
void func_08086A14(void);
void LoadPalette(void* src, void* dst, s32 size);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgSize(s32 a, s32 b);
void LoadBgMap(s32 bg, void* src, u16 size);
void TaskPoolInit(TaskPool* a, s32 count);
void SetBgMode2(void);
void SetBgAffine(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
u8 func_0809217C(u8* work, void* a);
void func_0808E344(void** p);
void func_080889DC(void);
void EnableBg(s32 bg);
u8 func_080E8D00(void);
void* func_080E8D1C(s32 a);
void func_08093C44(u16 a, u8* work);
u8 func_0808B30C(u8* work, void* a);
u8 func_08092234(u8* work, void* a);
void func_0808C90C(u8* work);
void func_0808C3DC(u8* work, u8 b);
void func_0808DB50(u8* work);
void func_0808A218(void);
void func_0808D828(u8* work);
void func_0808C940(UnkStruct_0808C940* w, s16 n);
void func_0808C974(UnkStruct_0808C940* w);
void func_08065AE0(TextSlot* p, s32 n);
void func_08096638(PrizeCardWork* w);
void SetObjMosaicSize(s32 a, s32 b);
void func_08006120(s32 a, s32 b);
void func_0800443C(u32 a, s32 b);
u8 func_080864A4(u8* work, void* a);
s32 func_0805F588(s32 a, s32 b);
void func_08096F08(void* a, void* b);
u8 func_08096288(PrizeCardWork* w, void* a);
u16 func_08093384(u8* work);
void* AllocObjTiles(s32 a, s32 b);
void func_08092A34(void);
void func_0808CC58(u16 a, s32 b);
void func_080AAA8C(u8* work, u8 b);
void func_080A8430(void);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_08090170(UnkStruct_0808E890* node);
u8 func_08096390(PrizeCardWork* w);
void* AnimGetGfx(AnimState* a);
void func_080A9968(u8* work);
void ModeRequest(Mode* mode, s32 arg);
void UpdatePlayTime(void);
void func_080B31A0(void);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void func_0806BA0C(s16 v, u8* out);
u8 Mapcard_1(u8* work, void* a);
extern u16 gBldAlpha;
extern u8* gUnk_02039DC8;
extern u8 gUnk_0908B1B4[];
extern u8 gUnk_09EEA164[];
extern u8 gUnk_09EEA148[];
void func_08006238(s32 a, u16 b, u16 c);
void func_080AA6D4(u8 a);
u8 func_080A207C(UnkStruct_080A1DAC* w);
u8 func_0807C5D8(u8* work, void* a);
u8 card_enemy_1(UnkStruct_02034AAC* p, void* a);
extern s32 gUnk_09034054[];
extern void* gUnk_09EF126C;
void func_080063A8(void);
void func_0801C1A0(s32 a);
extern s32 gUnk_09035978[];
u8 EV_BG_EFFECT_1(UnkStruct_080A1DAC* w, void* a);
s32 func_0809CBD0(u8* work);
u8 func_0809ACDC(u8* work);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void func_080061E8(s32 a, u16 b);
void func_080A1BB8(UnkStruct_080A1C48* w, void** t);
void func_0809D124(u8* work);
u16 func_08096D48(u16 a, s32 b);
void func_0809D1B0(u8* work);
MapcardWork* func_08000D90(void* a, void* b);
void func_0809CAC8(void* work);
u8 func_0800FCD8(s32 a, s32 b);
u8 func_0800FC90(s32 a);
void* func_080668F0(void);
void* func_08066904(void);
u16 func_0806692C(u8* s, u16* out);
void func_08066DC0(s32 a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g);
void func_0809D160(u8* work);
void func_080A25E0(void);
void func_08006954(void);
u8 func_0809C4B0(u8* work, void* a);
void func_0807CC2C(UnkStruct_02034AAC* p);
u8 func_0807D194(UnkStruct_02034AAC* p, void* a);
u8 func_0807CBC0(UnkStruct_02034AAC* p, void* a);
u8 func_0807BD64(UnkStruct_02034AAC* p, void* a);
u8 card_reload_1(UnkStruct_02034AAC* p, void* a);
void func_080949A0(u8* work);
u8 func_08094A18(u8* work, void* a);
void func_08094CE4(u8* work);
extern u16 gBldCnt;
s32 func_08097A80(u8* work);
u8 AnimIsFinished(AnimState* a);
void SetBackdropColor(u16 r, u16 g, u16 b);
u8 func_080A36B0(u8* work, void* a);
s32 func_080A22A4(u8* work);
void func_0807CD48(UnkStruct_02034AAC* p);
u8 func_0809254C(u8* work, void* a);
void func_0809C9A4(UnkStruct_0809C9A4* p);
void func_0809CA1C(u8* work);
u8 func_0809C620(u8* work, void* a);
u8 func_0809C9F4(UnkStruct_0809C9A4* p);
u8 func_080A2024(u8* work, void* a);
u8 func_08082224(UnkStruct_02034AAC* p, void* a);
u8 func_080827E0(UnkStruct_02034AAC* p, void* a);
void func_0800FB2C(s32 a);
CardSlot* func_08076674(UnkStruct_08080268* w, u8 slot, u16* n);
CardSlot* func_08076750(UnkStruct_08080268* w, u8 slot, u16* n);
void func_08083340(UnkStruct_02034AAC* p);
u16 func_08084FAC(u8 slot);
void LoadObjPaletteBank(u16 bank, void* src);
void* _08066468(s32 a);
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a);
u8 func_080A5034(UnkStruct_080A3F5C* w, void* a);
u8 func_0808A910(u8* work, void* a);
u8 func_0807D7B0(UnkStruct_02034AAC* p);
void func_0806C2C0(u8 a);
UnkStruct_080038C8* AllocObjPalette(s32 a);
void func_08003A70(void* a, void* b);
MapcardWork* ListPoolPrev(void* node);
void func_08093838(u8* work);
s32 func_080A5150(u8* work);
s32 func_08098BA4(u8* work);
u8 func_08082348(UnkStruct_02034AAC* p, void* a);
u8 HCEffectName_1(UnkStruct_0809DF7C* w, void* a);
void func_080AAEEC(UnkStruct_0808C940* w, s16 n);
u8 func_0807CF4C(u8* work, void* a);
u8 func_080A3BB0(UnkStruct_080A3F5C* w, void* a);
void func_080A1E4C(u8* work);
u8 REV_COUNT_1(u8* work, void* a);
void func_0809D2B0(u8 a, u8 b, u8 c, u8* s);
void func_080A6BB4(u8* work);
void func_080A6FAC(u8* work);
u8 func_080A5FF4(u8* work, void* a);
u8 func_08099330(u8* work);
void func_08078E34(u8* work, u8 b, u8 c);
void func_08078D98(u8* work, u8 b, u8 c);
u8 func_08076F80(u8* work, void* a);
u8 func_08082A64(UnkStruct_02034AAC* p, void* a);
u8 Reload_Card_1(UnkStruct_02034AAC* p, void* a);
u8 func_08081B70(UnkStruct_02034AAC* p, void* a);
void func_0806C34C(void);
u8 func_0809BE80(u8* work, void* a);
u8 func_0809075C(UnkStruct_02034AAC* p, void* a);
u8 func_08090808(u8* work, void* a);
void func_08090864(UnkStruct_02034AAC* p);
void func_08090B50(UnkStruct_02034AAC* p, void* a);
void SetBgBlend(s32 a, s32 b, s32 c);
u8 func_080A5D3C(UnkStruct_080A5D3C* w, void* a);
void func_08094DEC(MapcardWork* w);
void func_0800FDD0(s32 a);
u32 GetBgScreenBase(s32 bg);
void func_0807DAD0(UnkStruct_02034AAC* p);
void func_0807DE10(UnkStruct_02034AAC* p);
u8 func_080A6474(u8* work, void* a);
u8 RELOAD_CHILDREN_1(u8* work, void* a);
u8 func_080901B8(u8* p);
void func_080A6968(u8* work);
void func_080A7264(void** p);
void func_080A7210(u8* work);
void func_080838CC(void);
u8 func_08082AE4(u8* work);
u8 func_08082E0C(UnkStruct_02034AAC* p, void* a);
void func_0807E184(void);
u8 func_0807CE04(u8* work);
u8 func_0807D3A0(UnkStruct_02034AAC* p, void* a);
void func_08094E90(MapcardWork* w);
u8 func_0809CB78(u8* work, void* a);
u16 GetKeysRepeat(void);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
u8 func_08090940(u8* work);
u8 func_08090DB0(UnkStruct_02034AAC* p, void* a);
void func_0800FC14(s32 a);
void func_0808E2F0(UnkStruct_0808DB04* w);
u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a);
u8 func_080A3F5C(UnkStruct_080A3F5C* w, void* a);
u8 EnemyUsecard_1(UnkStruct_02034AAC* p, void* a);
u8 func_080A7914(u8* work, void* a);
void func_0808DD20(u8 a, u16 b);
s32 func_08097DE4(u8* work);
u8 func_0809DE30(UnkStruct_0809DF7C* w, void* a);
u8 func_08090C3C(UnkStruct_02034AAC* p, void* a);
s32 func_08083ADC(u8* work);
void func_080836C4(UnkStruct_08095A5C* p, void* a, u8 b, s8 c);

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
    gBtlWork->unk_068 &= ~0x80;
    gBtlWork->unk_068 &= ~0x100;
    gBtlWork->unk_068 &= ~0x200;
    gBtlWork->unk_068 &= ~0x400;
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
        (*(CardSlot**)&w[0x50])->unk_00 = 0x30FF;
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
                (*(CardSlot**)&w[0x44])[i].unk_00 = 0xFFFF;
                (*(CardSlot**)&w[0x44])[i].unk_07 = 0;
                (*(CardSlot**)&w[0x44])[i].unk_0A = 0;
                (*(CardSlot**)&w[0x44])[i].unk_08 = 0;
            }

            for (i = n + 1; i < n + 15; i++) {
                (*(CardSlot**)&w[0x44])[i].unk_06 = 1;
                (*(CardSlot**)&w[0x44])[i].unk_00 = 0xFFFF;
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
            (*(CardSlot**)&w[0x44])->unk_00 = 0xFF;
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
                (*(CardSlot**)&w[0x50])[i].unk_00 = 0xFFFF;
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
            (*(CardSlot**)&w[0x50])->unk_00 = 0x30FF;
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
        if (w->unk_44[n][i].unk_06 == 0 && w->unk_44[n][i].unk_07 == 0 && w->unk_44[n][i].unk_08 == 0 && w->unk_44[n][i].unk_0A == 0) {
            count++;
        }
    }

    return count;
}

u16 func_080787B8(UnkStruct_08078754* w, u8 n) {
    u16 count;
    u16 i;
    u16 max;
    s32 ofs;
    u8* q;

    max = w->unk_A8[n];
    count = 0;

    for (i = 0; i < max; i++) {
        if (w->unk_44[n][i].unk_06 == 0 && w->unk_44[n][i].unk_07 == 0 && w->unk_44[n][i].unk_08 == 0 && w->unk_44[n][i].unk_0A == 0 && w->unk_44[n][i].unk_00 != 0xFFFE) {
            count++;
        }
    }

    if (gUnk_02034A98->unk_78 & 0x100000) {
        ofs = *(s8*)((u8*)w + 0xB8) * 2;
        q = (u8*)w + 0xB0;

        if (*(s16*)(q + ofs) == 1) {
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

void func_08078914(UnkStruct_08078754* w, u8 n) {
    u8 i;

    if (gGameState.flags & 8) {
        for (i = 0; i < w->unk_A8[n]; i++) {
            if (w->unk_44[n][i].unk_07 == 0) {
                w->unk_44[n][i].unk_08 = 0;
                w->unk_44[n][i].unk_06 = 0;
            }

            if (!(gBtlWork->unk_068 & 0x800000000000)) {
                if (w->unk_44[n][i].unk_09 == 1) {
                    w->unk_44[n][i].unk_0A = 0;
                    w->unk_44[n][i].unk_09 = 0;
                }
            }
        }
    } else {
        for (i = 0; i < w->unk_A8[n]; i++) {
            if (w->unk_44[n][i].unk_07 == 0) {
                w->unk_44[n][i].unk_08 = 0;
                w->unk_44[n][i].unk_06 = 0;
            }
        }
    }
}

INCLUDE_ASM("card/func_080789E4.s");

INCLUDE_ASM("card/func_08078BB4.s");

void func_08078D98(u8* work, u8 kind, u8 c) {
    UnkStruct_02034AAC* node;

    m4aSongNumStart(0x79);
    node = (UnkStruct_02034AAC*)ListPoolFirst(&work[kind * 16 + 0x54]);

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

        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
    }
}

INCLUDE_ASM("card/func_08078E34.s");
INCLUDE_ASM("card/func_08078FFC.s");

void func_080791C0(void) {
    if (gBtlWork->unk_068 & 0x4800) {
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

    if (gBtlWork->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 0x30) {
            if (w->unk_BA != 0) {
                for (i = 0; i < w->unk_B9; i++) {
                    UnkStruct_02034AAC* c = w->unk_28[i];
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

INCLUDE_ASM("card/func_080792F4.s");
INCLUDE_ASM("card/func_08079600.s");
INCLUDE_ASM("card/func_08079B3C.s");
INCLUDE_ASM("card/func_08079ECC.s");
INCLUDE_ASM("card/func_0807A188.s");

void func_0807A620(u8* work) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 < 5 || node->unk_A1 > 6) {
                node->unk_A1 = 7;
            }

            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }

    if (gUnk_02034A98->unk_78 & 0x1000000) {
        gUnk_02034A98->unk_78 |= 0x4000;
    }
}

void func_0807A684(u8* work) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 == 0) {
                node->unk_A1 = 7;
            }

            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }
}

void func_0807A6C8(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 |= 0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(w->unk_54[i]);

        while (node != 0) {
            node->unk_78 |= 0x20;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }

    gBtlWork->unk_068 &= ~0x20;
    gUnk_02039DD4->unk_0EA = 1;
    w->unk_C9 = 0;
}

void func_0807A75C(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 &= ~0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(w->unk_54[i]);

        while (node != 0) {
            node->unk_78 &= ~0x20;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }

    gUnk_02039DD4->unk_0CC = 0;
    gBtlWork->unk_068 |= 0x20;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    w->unk_C9 = 1;
}

INCLUDE_ASM("card/func_0807A80C.s");

INCLUDE_ASM("card/func_0807ABC8.s");

void func_0807AE78(UnkStruct_08078754* w) {
    CardSlot* c;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++) {
        c = w->unk_44[i];

        for (j = 0; j < w->unk_A8[j]; j++) {
            c[j].unk_07 = 0;
        }
    }
}

u8 func_0807AEC4(u8* work, u8 n) {
    UnkStruct_02034AAC* node;
    u8 count;

    count = 0;
    node = (UnkStruct_02034AAC*)ListPoolFirst(&work[n * 16 + 0x54]);

    while (node != 0) {
        count++;
        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
    }

    return count;
}

u8 func_0807AEF4(u8* work, u8 kind) {
    UnkStruct_02034AAC* node;
    u8 count;

    count = 0;
    node = (UnkStruct_02034AAC*)ListPoolFirst(&work[kind * 16 + 0x54]);

    while (node != 0) {
        if ((node->unk_78 & 0x1000002) == 0) {
            if (kind == 2) {
                count++;
            } else if (node->unk_48->unk_2A == kind) {
                count++;
            }
        }

        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
    }

    return count;
}

INCLUDE_ASM("card/func_0807AF40.s");
INCLUDE_ASM("card/func_0807B16C.s");

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

    t = (UnkStruct_0807B410*)ListPoolFirst(&gBtlWork->unk_080);

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
            TaskCreate(pool, gTaskDescBosscard, &v);
            return;
        }

        t = (UnkStruct_0807B410*)ListPoolNext(&t->unk_B8);
    }
}

void func_0807B458(void) {
}

void func_0807B45C(void) {
    gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
}

#ifndef VERSION_EU
void func_0807B478(UnkStruct_02034AAC* w) {
    u32* p;
    u16* c;
    u16* q;
    u16* q2;

    if (gBtlWork->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 != 41) {
            gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
        } else {
            gBtlWork->unk_0F4 = 0;
            gUnk_02039DD4->unk_0CC = 0;
        }

        p = &gBtlWork->unk_0F4;

        if (*p == 41) {
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
#else
INCLUDE_ASM("card/func_0807B478.s");
#endif

u8 func_0807B578(u8* work, void* a) {
    s16 v;
    s32 ofs;
    u8* q;

    ofs = (s8)work[0xB8] * 2;
    q = work + 0xB0;
    v = *(s16*)(q + ofs);

    if (v > 2) {
        if (gUnk_02034A98->unk_78 & 0x40) {
            func_08078E34(work, work[0xB8], 2);
        }
    } else if (v > 1) {
        if (gUnk_02034A98->unk_78 & 0x40) {
            func_08078D98(work, work[0xB8], 2);
        }
    }

    (*(s16*)&work[0xA6])--;

    if (*(s16*)&work[0xA6] <= 0) {
        SetTaskUpdate(a, (void*)func_08076F80);
    }

    TaskPoolUpdate(work);
    TaskPoolUpdate(&gUnk_02039DD4->unk_09C);
    return 1;
}

u8 func_0807B60C(void) {
    if (gBtlWork->unk_0F4 == 38) {
        if (gUnk_02034A98->unk_48->unk_2A != 1) {
            return 1;
        }

        if (!(gUnk_02034A98->unk_48->unk_1E & 4)) {
            return 1;
        }

        return 0;
    } else if (gBtlWork->unk_0F4 == 39) {
        if (gUnk_02034A98->unk_48->unk_2A != 1) {
            return 1;
        }

        if (gUnk_02034A98->unk_48->unk_1E & 4) {
            return 1;
        }

        return 0;
    }

    return 1;
}

void func_0807B668(UnkStruct_02039DD4* p) {
    p->unk_040 = AllocObjTiles(0x280, 0);
    func_08002A10(p->unk_040, gUnk_0908B1B4);
    AnimInit(&p->unk_064, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&p->unk_064, 0, 1);
    p->unk_094 = AnimGetGfx(&p->unk_064);
    p->unk_050 = AllocObjTiles(0x100, 0);
    func_08002A10(p->unk_050, gUnk_0908C3CE);
    AnimInit(&p->unk_07C, gUnk_09EEA198, gUnk_09EEA180);
    AnimStart(&p->unk_07C, 0, 1);
    p->unk_098 = AnimGetGfx(&p->unk_07C);
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

void func_0807B98C(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        if (c[i].unk_00 != 0xFFFF) {
            if (c[i].unk_00 != 0xFFFE) {
                if (gCardDefs[c[i].unk_00 & CARD_ID_MASK].unk_2A != 2) {
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

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        if (c[i].unk_00 != 0xFFFF) {
            if (c[i].unk_00 != 0xFFFE) {
                if (gCardDefs[c[i].unk_00 & CARD_ID_MASK].unk_1E & 2) {
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
        if (!(gBtlWork->unk_068 & 0x800000000000)) {
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

    if (gBtlWork->unk_1C8 > 29 && !(gBtlWork->unk_068 & 0x800000000000)) {
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
void func_0807BC24(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    u16 v;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_14 = 0;
    *(void**)p->unk_1C = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    v = *(u16*)&p->unk_3C[8];

    if ((s16)v != -1) {
        func_0807D318(&p->unk_38, &p->unk_48, (u8)v);

        if ((*(CardSlot**)p->unk_3C)->unk_00 == 0xFFFE) {
            p->unk_78 |= 0x100000;
        }
    } else {
        p->unk_78 = 2;
    }

    if ((*(CardSlot**)p->unk_3C)->unk_00 & 0x8000) {
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
    p->unk_8C = gUnk_09033FF4[0];
    p->unk_90 = gUnk_09033FF4[1];
    p->unk_4C = gUnk_09033FF4[8];
    p->unk_50 = gUnk_09033FF4[9];

    if (p->unk_48 != 0) {
        p->unk_A5 = p->unk_48->unk_20;
    } else {
        p->unk_A5 = 0;
    }

    p->unk_A7 = 0;
    p->unk_78 |= 0x20;
    p->unk_78 &= ~0x40;
    func_0807D380((u8*)p);
}
u8 func_0807BD64(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);

    if (p->unk_78 & 0x10) {
        if (!(p->unk_78 & 0x80)) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
        }

        if (p->unk_78 & 0x10) {
            p->unk_9C = 8;
            func_0807E018(p);
            SetTaskUpdate(a, func_0807CB24);
            return 1;
        }
    }

    if ((s16)p->unk_9C == 0) {
        if (func_0807CE68(p)) {
            func_08000D90(&p->unk_64, p->unk_38);
            return 0;
        }

        if (!(p->unk_78 & 0x80)) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
            fn = func_0807BE54;
            SetTaskUpdate(a, fn);
            return fn(p, a);
        }
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, func_0807CBC0);
    }

    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

u8 func_0807BE54(UnkStruct_02034AAC* p, void* a) {
    if (func_0807CE68(p)) {
        func_08000D90(&p->unk_64, p->unk_38);
        return 0;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_0807CBC0);
    }

    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

INCLUDE_ASM("card/func_0807BEC0.s");

void card_not_have_2(UnkStruct_02034AAC* p) {
    void* gfx;
    u16 y;

    gfx = gUnk_08F709B0[p->unk_46].unk_04;

    if (func_080A42C8() == 1) {
        y = p->unk_50 >> 8;
    } else {
        y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    if (p->unk_78 & 0x80) {
        DrawSprite(p->unk_4C >> 8, y, gfx, p->unk_04, gUnk_02039DD4->unk_054, 0, 0x410, (u16)(p->unk_A0 - 1));
    }
}

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

u8 func_0807C3E8(UnkStruct_02034AAC* p, void* a) {
    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x8000000;

        if (p->unk_48->unk_2A == 0) {
            func_0807E184();
        }

        SetTaskUpdate(a, (void*)func_0807CE04);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        SetTaskUpdate(a, (void*)func_0807D3A0);
    }

    return 1;
}

u8 func_0807C4BC(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_4C, 0x7800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x8400, p->unk_9C);
    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C |= 0xFFFF;
    }

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_0807C3E8);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = -16;
            p->unk_9E = 0xFF;
            p->unk_78 |= 0x2000;
            SetTaskUpdate(a, (void*)func_0807CE9C);

            if (p->unk_48->unk_1E & 2) {
                (*(u8**)p->unk_3C)[6] = 0;
            }

            m4aSongNumStart(0xCC);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        SetTaskUpdate(a, (void*)func_0807CE9C);
    }

    return 1;
}
INCLUDE_ASM("card/func_0807C5D8.s");
INCLUDE_ASM("card/func_0807C75C.s");
INCLUDE_ASM("card/func_0807C934.s");

u8 func_0807CB24(UnkStruct_02034AAC* p, void* a) {
    if (!(p->unk_78 & 0x20)) {
        if (p->unk_78 & 0x100000) {
            SetTaskUpdate(a, (void*)func_0807D930);
            return func_0807D930(p, a);
        } else {
            SetTaskUpdate(a, (void*)func_0807CBC0);
            return func_0807CBC0(p, a);
        }
    }

    func_0807CC2C(p);
    p->unk_9C--;

    if (p->unk_9C == 0) {
        p->unk_78 &= ~0x10;

        if (p->unk_78 & 0x100000) {
            gUnk_02039DD4->unk_0E7 = 0;
            SetTaskUpdate(a, (void*)card_reload_1);
        } else {
            SetTaskUpdate(a, (void*)func_0807BD64);
        }
    }

    return 1;
}

u8 func_0807CBC0(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += (0 - p->unk_84) >> 1;
    p->unk_4C += (gUnk_09033FF4[8] - p->unk_4C) >> 1;
    p->unk_50 += (gUnk_09033FF4[9] - p->unk_50) >> 1;

    if (p->unk_78 & 0x20) {
        f = func_0807BD64;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    return 1;
}

INCLUDE_ASM("card/func_0807CC2C.s");

INCLUDE_ASM("card/func_0807CD48.s");

u8 func_0807CE04(u8* work) {
    ApproachValue(&work[0x50], 0x8200, *(u16*)&work[0x9C]);
    *(u16*)&work[0x9C] =
        *(s16*)&work[0x9C] > 0 ? *(u16*)&work[0x9C] - 1 : 0;

    if (*(s16*)&work[0x9C] == 0) {
        *(u16*)&work[0x9C] = 0;
        work[0x5E] += work[0x9E];
        work[0x9E]++;

        if (*(s32*)&work[0x54] <= 25) {
            return 0;
        }

        *(s32*)&work[0x54] -= 25;
        *(s32*)&work[0x58] -= 25;
    }

    return 1;
}

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

u8 func_0807CE9C(UnkStruct_02034AAC* p) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->unk_4C -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        gBtlWork->unk_068 &= ~0x8000000;
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
    SetTaskUpdate(a, (void*)func_0807C5D8);
    return 1;
}

u8 func_0807CFA8(UnkStruct_02034AAC* p, void* a) {
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

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_0807C5D8);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = -16;
            p->unk_9E = 0xFF;
            gUnk_02039DD4->unk_0C0 = 0;
            gUnk_02039DD4->unk_0E1 = 0;
            SetTaskUpdate(a, (void*)func_0807CE9C);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        gUnk_02039DD4->unk_0E1 = 0;
        SetTaskUpdate(a, (void*)func_0807CE9C);
    }

    return 1;
}

INCLUDE_ASM("card/func_0807D0F4.s");
INCLUDE_ASM("card/func_0807D194.s");

void func_0807D318(UnkStruct_02034AAC* p, CardDef** out) {
    u32* q;

    if (p->unk_04 != 0) {
        if (*(u32*)p->unk_04 != 0xFFFF) {
            if (*(u32*)p->unk_04 != 0xFFFE) {
                *out = &gCardDefs[*(u32*)p->unk_04 & CARD_ID_MASK];
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
    func_08000D20(q, *(void**)&p[0x38], p);
    func_08000D28(q, *(void**)&p[0x38]);
}
u8 func_0807D3A0(UnkStruct_02034AAC* p, void* a) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->unk_4C -= 0x200;
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
        gBtlWork->unk_068 &= ~0x8000000;
        return 0;
    }

    return 1;
}
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

#ifndef VERSION_EU
u8 func_0807D4E4(UnkStruct_02034AAC* p) {
    u8 arg;

    p->unk_A1 = 0;
    ApproachValue(&p->unk_4C, 0x1800, p->unk_9C);
    ApproachValue(&p->unk_58, 0x99, p->unk_9C);
    ApproachValue(&p->unk_50, 0x6400, p->unk_9C);
    ApproachValue(&p->unk_54, 0x99, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    arg = 1;
    gBtlWork->unk_0F8 = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E;
    TaskCreate(&gUnk_02039DD4->unk_09C, gTaskDescHCEffectName, &arg);
    return 0;
}
#else
INCLUDE_ASM("card/func_0807D4E4.s");
#endif

INCLUDE_ASM("card/func_0807D584.s");
u8 func_0807D68C(UnkStruct_02034AAC* p, void* a) {
    s16 sx;
    s16 sy;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    WorldToScreen(&sx, &sy, *(s32*)&gBtlWork->unk_100[0], *(s32*)&gBtlWork->unk_100[4], *(s32*)&gBtlWork->unk_100[8]);
    x = sx;
    y = sy;

    if (p->unk_88 < 0) {
        dx = (x << 8) - p->unk_4C;
        dy = (y << 8) - p->unk_50;
        func_0805F5A4(&dx, &dy);
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

    p->unk_4C += (p->unk_8C * p->unk_88) >> 8;
    p->unk_50 += (p->unk_90 * p->unk_88) >> 8;
    p->unk_84 = func_0805F588((x << 8) - p->unk_4C, (y << 8) - p->unk_50);
    p->unk_88 -= p->unk_80;
    p->unk_80 += 2;

    if (p->unk_84 <= 0x800) {
        gBtlWork->unk_074 = 15;
        gBtlWork->unk_072 = 15;
        m4aSongNumStart(0x78);
        SetTaskUpdate(a, (void*)func_0807D7B0);
    }

    return 1;
}

u8 func_0807D7B0(UnkStruct_02034AAC* p) {
    if ((s16)gBtlWork->unk_072 == 0) {
        func_08006120(7, 8);
        func_080063A8();
        gBtlWork->unk_068 &= ~0x200000000000000;

        if (p->unk_48->unk_24 == 140) {
            func_0801C1A0(0);
        }

        gBtlWork->unk_068 &= ~0x20000000000000;
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
void card_reload_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    vu32 zero2;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_14 = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = EwramAlloc(0x68);
    zero2 = 0;
    CpuSet((void*)&zero2, p->unk_20, 0x0500001A);
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    ((u8*)p->unk_20)[0x65] = 0;
    p->unk_78 = 0x01100020;
    p->unk_48 = 0;
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
    p->unk_8C = gUnk_09033FF4[0];
    p->unk_90 = gUnk_09033FF4[1];
    p->unk_4C = gUnk_09033FF4[8];
    p->unk_50 = gUnk_09033FF4[9];
    p->unk_78 &= ~0x40;
    gUnk_02039DD4->unk_0E7 = 0;
    func_0807D380(p);
}

u8 func_0807D930(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += (0 - p->unk_84) >> 1;
    p->unk_4C += (gUnk_09033FF4[8] - p->unk_4C) >> 1;
    p->unk_50 += (gUnk_09033FF4[9] - p->unk_50) >> 1;

    if (p->unk_78 & 0x20) {
        f = card_reload_1;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    return 1;
}

u8 card_reload_1(UnkStruct_02034AAC* p, void* a) {
    if (p->unk_78 & 0x10) {
        p->unk_9C = 8;
        SetTaskUpdate(a, (void*)func_0807CB24);
        return 1;
    }

    if ((s16)p->unk_9C == 0) {
        if (func_0807CE68(p)) {
            func_08000D90(&p->unk_64, p->unk_38);
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
        SetTaskUpdate(a, (void*)func_0807D930);
    }

    func_0807DE10(p);
    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

void func_0807DA54(UnkStruct_08095A5C* p, void* a, u8 b, s8 c) {
    AnimInit(&p->unk_10, gUnk_09EEA4E0, gUnk_09EEA494);

    if (c >= 0) {
        AnimStart(&p->unk_10, c, 0);
    } else {
        AnimStart(&p->unk_10, 0, 0);
    }

    p->unk_60 = AnimGetGfx(&p->unk_10);
}

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
void func_0807DAD0(UnkStruct_02034AAC* p) {
    u8* d;

    d = p->unk_20;
    p->unk_00 = AllocObjTiles(0x80, 0);
    func_08002A10(p->unk_00, gUnk_0909A4E0);
    func_0807DA54(p->unk_20, p->unk_00, p->unk_46, gUnk_02039DD4->unk_0FC);
    p->unk_14 = 0;
    p->unk_04 = LoadObjTiles(gUnk_0909FDCA, 0x280);
    p->unk_18 = 0;
    p->unk_08 = AllocObjTiles(0x200, 0);
    func_08002A10(p->unk_08, gUnk_090A0C86);
    p->unk_0C = AllocObjTiles(0x80, 0);
    func_08002A10(p->unk_0C, gUnk_090A0C86);
    AnimInit(&d[0x28], gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(&d[0x28], 1, 1);
    *(void**)&d[0x58] = gUnk_09EEAF4C[3];
    AnimInit(&d[0x40], gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(&d[0x40], gUnk_02039DD4->unk_104, 1);
    *(void**)&d[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_100 + 2];
}
void card_reload_2(UnkStruct_02034AAC* p) {
    u8* w;
    s16 y;
    s32 affine;
    s32 attr;

    if (p->unk_78 & 0x80) {
        w = p->unk_20;

        if (func_080A42C8() == 1) {
            y = p->unk_50 >> 8;
        } else {
            y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
        }

        attr = 0x410;
        DrawSprite(p->unk_4C >> 8, y, gUnk_08F709B0[3].unk_04, p->unk_04,
                   gUnk_02039DD4->unk_054, 0, attr, p->unk_A0);

        if (!(gGameState.flags & 8) && *(void**)&w[0x60] != 0) {
            DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x60], p->unk_00,
                       gUnk_02039DD4->unk_054, 0, 0x410, (u16)(p->unk_A0 - 2));
        }

        if ((s32)gUnk_02039DD4->unk_0F4 > 0) {
            affine = AllocObjAffine(0, p->unk_54, gUnk_02039DD4->unk_0F4, 0);

            if (*(void**)&w[0x58] != 0) {
                DrawSprite(p->unk_4C >> 8, y + 17, *(void**)&w[0x58], p->unk_08,
                           gUnk_02039DD4->unk_054, affine, 0x400,
                           (u16)(p->unk_A0 - 1));
            }

            if (gUnk_02039DD4->unk_108[0] == 1 && *(void**)&w[0x5C] != 0) {
                DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x5C], p->unk_0C,
                           gUnk_02039DD4->unk_054, 0, 0x400,
                           (u16)(p->unk_A0 - 1));
            }
        }
    }
}
void card_reload_3(UnkStruct_02034AAC* p) {
    func_0807C39C(p);
    EwramFree(p->unk_20);

    if (gBtlWork->unk_068 & 0x1000000) {
        gBtlWork->unk_068 &= ~0x1000000;
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
    BtlWork* p;

    p = gBtlWork;

    switch (p->unk_0F4) {
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

u16 sub_0807E66C(CardSlot* out, u16* ids, u16 n, u8 kind) {
    u16 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (ids[i] != 0xFFFF) {
            switch (kind) {
            case 0:
                if ((u8)gCardDefs[ids[i] & CARD_ID_MASK].unk_2A <= 2) {
                    out[count].unk_06 = kind;
                    out[count].unk_07 = kind;
                    out[count].unk_0A = kind;
                    out[count].unk_00 = ids[i];
                    out[count].unk_04 = count;
                    count++;
                }
                break;
            case 3:
                if ((u8)gCardDefs[ids[i] & CARD_ID_MASK].unk_2A == 3) {
                    out[count].unk_06 = 0;
                    out[count].unk_07 = 0;
                    out[count].unk_0A = 0;
                    out[count].unk_00 = ids[i];
                    out[count].unk_04 = count;
                    count++;
                }
                break;
            }
        }
    }

    return count;
}

INCLUDE_ASM("card/func_0807E724.s");
INCLUDE_ASM("card/func_0807E8F4.s");
INCLUDE_ASM("card/func_0807EDEC.s");

void func_0807F99C(UnkStruct_08080268* w) {
    if (gUnk_02039DD4->unk_0EA != 0 && gUnk_02039B9C->unk_0F4 != 28 && w->unk_B9 != 0 && w->unk_BA != 0) {
        DrawSprite(w->unk_A4, 4, gUnk_09EF12E8[0], w->unk_14, w->unk_18, 0, 16, 12);
    }

    TaskPoolDraw(w);
}

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

void func_0807FA44(UnkStruct_08080268* w) {
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 &= ~0x20;
    }

    if (gUnk_02034AAC != 0) {
        gUnk_02034AAC->unk_78 &= ~0x20;
    }

    gUnk_02039DD4->unk_0CC = 0;
    gBtlWork->unk_068 |= 0x20;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0E4 = 0;
    w->unk_C9 = 1;
}

void func_0807FAD8(UnkStruct_08080268* w) {
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 |= 0x20;
    }

    if (gUnk_02034AAC != 0) {
        gUnk_02034AAC->unk_78 |= 0x20;
    }

    gBtlWork->unk_068 &= ~0x20;
    gUnk_02039DD4->unk_0EA = 1;
    w->unk_C9 = 0;
}

u8 func_0807FB5C(UnkStruct_08080268* w, void* a) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    CardSlot* c;
    u16 v;

    if (gBtlWork->unk_0A0 == 4) {
        if (gUnk_02039B9C->unk_068 & 0x1000000) {
            gUnk_02039B9C->unk_068 &= ~0x1000000;
        }

        m4aSongNumStop(0x91);
        return 0;
    }

    if ((s16)gUnk_02034AAC->unk_9C == 0) {
        if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) > w->unk_C4[2]) {
            gUnk_02034AAC->unk_78 &= ~4;
            v = *(u16*)&gUnk_02034AAC->unk_3C[8] - 1;
            c = func_08076750(w, w->unk_B8, &v);

            if (c != 0) {
                args.unk_00 = &w->unk_54[w->unk_B8];
                args.unk_0C = v;
                args.unk_0E = w->unk_B8;
                args.unk_04 = c;
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
                p->unk_80 = p->unk_7C = 0;
                p->unk_A0 = 50;
                p->unk_9C = 8;
                p->unk_4C = p->unk_8C;
                p->unk_50 = p->unk_90;
                p->unk_78 |= 0x814;
                gUnk_02034AAC = p;
                w->unk_C4[2]++;
                w->unk_B0[w->unk_B8]++;
            }
        } else {
            gUnk_02039B9C->unk_068 &= ~0x80000000LL;
            gUnk_02039B9C->unk_068 &= ~0x100;
            w->unk_C4[0] = 0;
            m4aSongNumStop(0x91);
            gUnk_02034AA4 = 0;
            SetTaskUpdate(a, (void*)func_0807EDEC);
        }
    }

    if (gUnk_02034AA4 == 7) {
        w->unk_BC[w->unk_B8] = 0;
        w->unk_C4[0] = 0;
        func_0807FA44(w);
        m4aSongNumStop(0x91);
    }

    TaskPoolUpdate(w);
    return 1;
}
INCLUDE_ASM("card/func_0807FD10.s");
INCLUDE_ASM("card/func_0807FE30.s");
#ifndef VERSION_EU
void func_0807FF48(UnkStruct_08080268* w) {
    if ((gUnk_02034AAC->unk_78 & 0x40) != 0) {
        m4aSongNumStart(103);

        if (gUnk_02039B9C->unk_068 & 0x1000000) {
            gUnk_02039B9C->unk_068 &= ~0x1000000;
        }

        w->unk_BC[w->unk_B8] = 0;

        if (w->unk_C0[w->unk_B8] == 0) {
            w->unk_94[w->unk_B8] = *(u16*)&gUnk_02034AAC->unk_3C[8];
            gUnk_02034AAC->unk_8C = 0x10400;
            gUnk_02034AAC->unk_90 = 0x8C00;
            gUnk_02034AAC->unk_9C = 4;
            gUnk_02034AAC->unk_A1 = 7;
            gUnk_02034AAC->unk_78 &= ~4;
        } else {
            w->unk_34[w->unk_B8] = gUnk_02034AAC;
            gUnk_02034AAC->unk_98 = gUnk_090352E4[3];
            gUnk_02034AAC->unk_A3 = 4;
            gUnk_02034AAC->unk_78 &= ~4;
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
            func_0807E368(w, (u8)w->unk_B8);
            gUnk_02034AAC->unk_4C = gUnk_0903401C[10];
            gUnk_02034AAC->unk_50 = gUnk_0903401C[11];
            gUnk_02034AAC->unk_A3 = 1;
            gUnk_02034AAC->unk_9C = 1;
        } else {
            gUnk_02034AAC = w->unk_34[w->unk_B8];
            gUnk_02034AAC->unk_98 = gUnk_090352E4[0];
            gUnk_02034AAC->unk_94 = gUnk_02034AAC->unk_98;
            gUnk_02034AAC->unk_A3 = 1;
            gUnk_02034AAC->unk_9C = 1;
            gUnk_02034AAC->unk_78 |= 4;
        }

        gUnk_02039DD4->unk_0D4 = w->unk_B8;
    }
}
#else
INCLUDE_ASM("card/func_0807FF48.s");
#endif
INCLUDE_ASM("card/func_080800B4.s");

void func_08080228(void) {
    if (gBtlWork->unk_0F4 == 0x30) {
        if (gUnk_02034AAC->unk_A5 != 0) {
            gUnk_02034AAC->unk_A5 -= gUnk_02039DD4->unk_0C2;
        }

        gBtlWork->unk_0F8--;
    }
}

#ifdef NON_MATCHING
void func_08080268(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* q;
    u8 d;
    u8 i;

    d = gUnk_02039DD4->unk_0C2;

    if (gBtlWork->unk_0F4 == 0x30) {
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

        gBtlWork->unk_0F8--;
    }
}
#else
INCLUDE_ASM("card/func_08080268.s");
#endif

INCLUDE_ASM("card/func_080802D8.s");
INCLUDE_ASM("card/func_08080594.s");

#ifdef NON_MATCHING
void func_08080994(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    UnkStruct_02034AAC* q;
    CardSlot* c;
    u16 v;

    w->unk_C4[2] = 0;
    func_08078914((UnkStruct_08078754*)w, w->unk_B8);

    if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) != 0) {
        v = w->unk_A8[w->unk_B8] - 1;
        c = func_08076750(w, w->unk_B8, &v);

        if (c != 0) {
            args.unk_00 = w->unk_54[w->unk_B8];
            args.unk_0C = v;
            args.unk_0E = w->unk_B8;
            args.unk_04 = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->unk_00 == 0xFFFE) {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
            } else {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
            }

            p->unk_80 = p->unk_7C = 0;
            p->unk_98 = p->unk_94 = gUnk_090352E4[0];
            p->unk_A4 = 0;
            p->unk_A0 = 50;
            p->unk_4C = p->unk_8C;
            p->unk_50 = p->unk_90;
            p->unk_9C = 8;
            p->unk_78 |= 0x814;
            gUnk_02034AAC = p;
            w->unk_C4[2]++;
            w->unk_B0[w->unk_B8]++;
        }
    } else {
        args.unk_00 = w->unk_54[w->unk_B8];
        args.unk_0C = 0xFFFF;
        args.unk_04 = (CardSlot*)w->unk_44[w->unk_B8];
        args.unk_0E = w->unk_B8;
        q = ((UnkStruct_02034AAC**)TaskCreate(w, &gUnk_09EE49CC[0x18], &args))[1];
        q->unk_80 = q->unk_7C = 0;
        q->unk_98 = q->unk_94 = gUnk_090352E4[0];
        q->unk_4C = q->unk_8C;
        q->unk_50 = q->unk_90;
        q->unk_A0 = 50;
        q->unk_78 |= 0x806;
        gUnk_02034AAC = q;
    }

    func_080818E4();
}
#else
INCLUDE_ASM("card/func_08080994.s");
#endif
INCLUDE_ASM("card/func_08080B44.s");

INCLUDE_ASM("card/func_08080EB4.s");
INCLUDE_ASM("card/func_08081210.s");
INCLUDE_ASM("card/func_080814BC.s");
void func_08081740(void) {
}
void func_08081744(void) {
    gUnk_02039B9C->unk_0F4 = gUnk_02039DD4->unk_0CE;
}

#ifndef VERSION_EU
void func_08081760(UnkStruct_02034AAC* p) {
    if (gBtlWork->unk_0F4 != 41) {
        gUnk_02039B9C->unk_0F4 = gUnk_02039DD4->unk_0CE;
    } else {
        gUnk_02039B9C->unk_0F4 = 0;
        gUnk_02039DD4->unk_0CE = 0;
    }

    if (gUnk_02039DD4->unk_0CE == 45) {
        if (gBtlWork->unk_0F4 != 0) {
            gUnk_02039DD4->unk_0CE = gUnk_02039DD4->unk_0CC;
            gUnk_02039B9C->unk_0F4 = gBtlWork->unk_0F4;
        } else {
            gBtlWork->unk_0F4 = 0;
            gUnk_02039DD4->unk_0CE = 0;
        }
    }

    if (gUnk_02039B9C->unk_0F4 == 47) {
        p->unk_9C = 2;
        *(u16*)&p->unk_9E = 2;
    }

    if (gUnk_02039B9C->unk_0F4 == 41) {
        gUnk_02039DD4->unk_0CC = 0;
        gBtlWork->unk_0F4 = 0;
        gBtlWork->unk_0F8 = 0;
        gUnk_02039B9C->unk_0F4 = 0;
        gUnk_02039B9C->unk_0F8 = 0;
    }
}
#else
INCLUDE_ASM("card/func_08081760.s");
#endif

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

u8 func_08081870(void) {
    if (gUnk_02034AAC != 0) {
        return gUnk_02034AAC->unk_A5;
    }

    return 0xFF;
}

u8 func_08081888(void) {
    if (gUnk_02039B9C->unk_0F4 == 38) {
        if (gUnk_02034AAC->unk_48->unk_2A != 1) {
            return 1;
        }

        if (!(gUnk_02034AAC->unk_48->unk_1E & 4)) {
            return 1;
        }

        return 0;
    } else if (gUnk_02039B9C->unk_0F4 == 39) {
        if (gUnk_02034AAC->unk_48->unk_2A != 1) {
            return 1;
        }

        if (gUnk_02034AAC->unk_48->unk_1E & 4) {
            return 1;
        }

        return 0;
    }

    return 1;
}

void func_080818E4(void) {
    switch (gUnk_02039B9C->unk_0F4) {
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
        gUnk_02039B9C->unk_0F8--;
        break;
    }
}

void func_080819E8(void) {
    if (gUnk_02039B9C->unk_0F4 == 50) {
        gUnk_02039B9C->unk_0F8--;
    }
}

void func_08081A04(void) {
    gUnk_02039DD4->unk_0F8 = 0;
    gUnk_02039DD4->unk_0FE = 0;
    gUnk_02039DD4->unk_102 = 4;
    gUnk_02039DD4->unk_106 = 2;
    gUnk_02039DD4->unk_108[1] = 0;
}

void func_08081A3C(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    u16 v;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_14 = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    v = *(u16*)&p->unk_3C[8];

    if ((s16)v != -1) {
        func_08082DA4(&p->unk_38, &p->unk_48, (u8)v);

        if ((*(CardSlot**)p->unk_3C)->unk_00 == 0xFFFE) {
            p->unk_78 |= 0x100000;
        }
    } else {
        p->unk_78 = 2;
    }

    if ((*(CardSlot**)p->unk_3C)->unk_00 & 0x8000) {
        p->unk_A6 = 1;
    } else {
        p->unk_A6 = 0;
    }

    p->unk_54 = 0;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 80;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0x2400;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_0903401C[10];
    p->unk_90 = gUnk_0903401C[11];
    p->unk_4C = gUnk_0903401C[8];
    p->unk_50 = gUnk_0903401C[9];

    if (p->unk_48 != 0) {
        p->unk_A5 = p->unk_48->unk_20;
    } else {
        p->unk_A5 = 0;
    }

    p->unk_A7 = 0;
    p->unk_78 |= 0x24;
    p->unk_78 &= ~0x40;
}
u8 func_08081B70(UnkStruct_02034AAC* p, void* a) {
    if ((p->unk_78 & 0x84) == 4) {
        func_0807C33C(p);
        p->unk_78 |= 0x80;
    }

    if (p->unk_78 & 0x10) {
        p->unk_9C = 4;
        SetTaskUpdate(a, (void*)func_080829D0);
        return 1;
    }

    if (p->unk_78 & 4) {
        if ((s16)p->unk_9C > 0) {
            p->unk_78 &= ~0x40;
            ApproachValue(&p->unk_54, 0x100, p->unk_9C);
            p->unk_9C--;
        } else {
            p->unk_78 |= 0x40;
        }
    } else if ((s16)p->unk_9C > 0) {
        p->unk_78 &= ~0x40;
        ApproachValue(&p->unk_54, 0, p->unk_9C);

        if (p->unk_78 & 0x80) {
            func_0807C39C(p);
            p->unk_78 &= ~0x80;
        }

        p->unk_9C--;
    } else {
        return 0;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    ApproachValue(&p->unk_4C, p->unk_8C, p->unk_9C);
    ApproachValue(&p->unk_50, p->unk_90, p->unk_9C);
    p->unk_5F += 4;

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08082A64);
    }

    return func_08082C98(p, a);
}
INCLUDE_ASM("card/func_08081C98.s");

void NO_Card_2(UnkStruct_02034AAC* p) {
    void* gfx;
    u16 y;

    gfx = gUnk_08F709B0[0].unk_04;

    if (func_080A42C8() == 1) {
        y = p->unk_50 >> 8;
    } else {
        y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    if (p->unk_78 & 0x20) {
        if (p->unk_78 & 0x80) {
            if (p->unk_54 != 0) {
                if (gUnk_02039B9C->unk_0F4 != 7) {
                    DrawSprite(p->unk_4C >> 8, y, gfx, p->unk_04, gUnk_02039DD4->unk_054, 0, 0x410, (u16)(p->unk_A0 - 1));
                }
            }
        }
    }
}

void func_080820F4(UnkStruct_02034AAC* p) {
    func_0807C39C(p);

    if (p->unk_20 != 0) {
        EwramFree(p->unk_20);
    }
}

void func_0808210C(UnkStruct_02034AAC* p) {
    if (p->unk_A1 == 6) {
        return;
    }

    if (p->unk_54 == 0) {
        if (p->unk_78 & 0x80) {
            func_0807C39C(p);
            p->unk_78 &= ~0x80;
        }
    } else {
        if ((p->unk_78 & 0x80) == 0) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
        }
    }
}

u8 func_08082154(UnkStruct_02034AAC* p, void* a) {
    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x10000000;

        if (p->unk_48->unk_2A == 0) {
            func_080838CC();
        }

        SetTaskUpdate(a, (void*)func_08082AE4);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        SetTaskUpdate(a, (void*)func_08082E0C);
    }

    return 1;
}

u8 func_08082224(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_4C, 0x7800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x8400, p->unk_9C);
    p->unk_A0 = 80;

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C |= 0xFFFF;
    }

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_08082154);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = 16;
            p->unk_9E = 1;
            p->unk_78 |= 0x2000;
            SetTaskUpdate(a, (void*)func_08082B48);

            if (p->unk_48->unk_1E & 2) {
                (*(u8**)p->unk_3C)[6] = 0;
            }

            m4aSongNumStart(0xCC);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        SetTaskUpdate(a, (void*)func_08082B48);
    }

    return 1;
}
u8 func_08082348(UnkStruct_02034AAC* p, void* a) {
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

    func_08082BF8(p);

    switch (p->unk_9F) {
    case 0:
        p->unk_A0 = 50;
        break;
    case 1:
        p->unk_A0 = 40;
        break;
    case 2:
        p->unk_A0 = 60;
        break;
    }

    if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        gUnk_02039DD4->unk_0E2 = 0;
        SetTaskUpdate(a, (void*)func_08082E0C);
    }

    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0--;
        gUnk_02039DD4->unk_0C2 = 0;

        if (gUnk_02039DD4->unk_0D0 == 0) {
            gBtlWork->unk_068 &= ~0x20;
            gBtlWork->unk_068 &= ~0x80;
            func_080838A0();
        }

        gUnk_02039DD4->unk_0E2 = 0;
        gBtlWork->unk_068 &= ~0x10000000;
        SetTaskUpdate(a, (void*)func_08082AE4);
    }

    return 1;
}
u8 func_080824C8(UnkStruct_02034AAC* p, void* a) {
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

    func_08082BF8(p);

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_08082348);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = 16;
            p->unk_9E = 1;
            gUnk_02039DD4->unk_0C0 = 0;
            gUnk_02039DD4->unk_0E2 = 0;
            SetTaskUpdate(a, (void*)func_08082B48);
            m4aSongNumStart(0xCC);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        gUnk_02039DD4->unk_0E2 = 0;
        SetTaskUpdate(a, (void*)func_08082B48);
    }

    return 1;
}
INCLUDE_ASM("card/func_08082618.s");
INCLUDE_ASM("card/func_080827E0.s");

u8 func_080829D0(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);

    if (!(p->unk_78 & 0x20)) {
        f = func_08082A64;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    ApproachValue(&p->unk_54, 0x100, p->unk_9C);
    p->unk_9C--;

    if (p->unk_9C == 0) {
        p->unk_78 &= ~0x10;
        p->unk_54 = 0x100;

        if (p->unk_78 & 0x100000) {
            gUnk_02039DD4->unk_0E8 = 0;
            SetTaskUpdate(a, (void*)Reload_Card_1);
        } else {
            SetTaskUpdate(a, (void*)func_08081B70);
        }
    }

    return 1;
}

u8 func_08082A64(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += -p->unk_84 >> 1;
    p->unk_4C += (gUnk_0903401C[8] - p->unk_4C) >> 1;
    p->unk_50 += (gUnk_0903401C[9] - p->unk_50) >> 1;

    if (p->unk_78 & 0x20) {
        if (p->unk_78 & 0x100000) {
            fn = Reload_Card_1;
            SetTaskUpdate(a, fn);
            return fn(p, a);
        } else {
            do {
                fn = func_08081B70;
                SetTaskUpdate(a, fn);
            } while (0);

            return fn(p, a);
        }
    }

    return 1;
}

u8 func_08082AE4(u8* work) {
    ApproachValue(&work[0x50], 0x8200, *(u16*)&work[0x9C]);
    *(u16*)&work[0x9C] =
        *(s16*)&work[0x9C] > 0 ? *(u16*)&work[0x9C] - 1 : 0;

    if (*(s16*)&work[0x9C] == 0) {
        *(u16*)&work[0x9C] = 0;
        work[0x5E] += work[0x9E];
        work[0x9E]++;

        if (*(s32*)&work[0x54] <= 25) {
            return 0;
        }

        *(s32*)&work[0x54] -= 25;
        *(s32*)&work[0x58] -= 25;
    }

    return 1;
}

u8 func_08082B48(UnkStruct_02034AAC* p) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->unk_4C -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        gBtlWork->unk_068 &= ~0x10000000;
        p->unk_78 &= ~0x80;
        return 0;
    }

    return 1;
}

INCLUDE_ASM("card/func_08082BF8.s");
u8 func_08082C98(UnkStruct_02034AAC* p, void* a) {
    switch (p->unk_A1) {
    case 5:
        p->unk_9C = 10;
        p->unk_A0 -= 4;
        p->unk_54 = 0x100;
        SetTaskUpdate(a, (void*)func_08082224);
        return 1;
    case 6:
        p->unk_9C = 8;
        p->unk_A0 -= 4;
        func_08082EFC(p);
        p->unk_78 |= 0x200;
        p->unk_78 |= 0x80;
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_080827E0);
        return 1;
    case 8:
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        SetTaskUpdate(a, (void*)func_08082B48);
        return 1;
    case 7:
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        return 0;
    case 10:
        p->unk_9C = 10;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)func_08082F50);
        return 1;
    case 9:
    default:
        func_080837FC(p);
        break;
    }

    return 1;
}

void func_08082DA4(UnkStruct_02034AAC* p, CardDef** out) {
    u32* q;

    if (p->unk_04 != 0) {
        if (*(u32*)p->unk_04 != 0xFFFF) {
            if (*(u32*)p->unk_04 != 0xFFFE) {
                *out = &gCardDefs[*(u32*)p->unk_04 & CARD_ID_MASK];
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

u8 func_08082E0C(UnkStruct_02034AAC* p, void* a) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->unk_4C -= 0x200;
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
        gBtlWork->unk_068 &= ~0x10000000;
        return 0;
    }

    return 1;
}
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

#ifndef VERSION_EU
u8 func_08082F50(UnkStruct_02034AAC* p) {
    u8 arg;

    p->unk_A1 = 0;
    ApproachValue(&p->unk_4C, 0xD800, p->unk_9C);
    ApproachValue(&p->unk_58, 0x99, p->unk_9C);
    ApproachValue(&p->unk_50, 0x6400, p->unk_9C);
    ApproachValue(&p->unk_54, 0x99, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    arg = 2;
    gUnk_02039B9C->unk_0F8 = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E;
    TaskCreate(&gUnk_02039DD4->unk_09C, gTaskDescHCEffectName, &arg);
    return 0;
}
#else
INCLUDE_ASM("card/func_08082F50.s");
#endif

u8 func_08082FF0(u8* work) {
    s32 r;

    if (*(s32*)&work[0x54] <= 24) {
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
void Reload_Card_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    vu32 zero2;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_14 = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = EwramAlloc(0x68);
    zero2 = 0;
    CpuSet((void*)&zero2, p->unk_20, 0x0500001A);
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    ((u8*)p->unk_20)[0x65] = 0;
    p->unk_78 = 0x01100024;
    p->unk_48 = 0;
    p->unk_54 = 0;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_9F = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 80;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0x2400;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_0903401C[10];
    p->unk_90 = gUnk_0903401C[11];
    p->unk_4C = gUnk_0903401C[8];
    p->unk_50 = gUnk_0903401C[9];
    p->unk_78 &= ~0x40;
    gUnk_02039DD4->unk_0E8 = 0;
    func_08083714((UnkStruct_08083B20*)p);
    p->unk_78 |= 0x80;
}
u8 Reload_Card_1(UnkStruct_02034AAC* p, void* a) {
    if (p->unk_78 & 0x10) {
        p->unk_9C = 4;
        SetTaskUpdate(a, (void*)func_080829D0);
        return 1;
    }

    func_08083340(p);

    if (p->unk_78 & 4) {
        if ((s16)p->unk_9C > 0) {
            p->unk_78 &= ~0x40;
            ApproachValue(&p->unk_54, 0x100, p->unk_9C);
            gUnk_02039DD4->unk_0E8 = 0;
            p->unk_9C--;
        } else {
            p->unk_78 |= 0x40;
        }
    } else {
        if ((s16)p->unk_9C <= 0) {
            return 0;
        }

        p->unk_78 &= ~0x40;
        ApproachValue(&p->unk_54, 0, p->unk_9C);
        gUnk_02039DD4->unk_0E8 = 0;
        p->unk_9C--;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    ApproachValue(&p->unk_4C, p->unk_8C, p->unk_9C);
    ApproachValue(&p->unk_50, p->unk_90, p->unk_9C);
    p->unk_5F += 4;

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08082A64);
    }

    return func_08082C98(p, a);
}
void Reload_Card_3(UnkStruct_02034AAC* p) {
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
void Reload_Card_2(UnkStruct_02034AAC* p) {
    s32 affine;
    s32 affine2;
    u8* w;
    s16 y;
    u16 attr;

    attr = 0x410;
    affine = AllocObjAffine(0, p->unk_54, 0x100, 0);

    if (p->unk_78 & 0x80) {
        w = p->unk_20;

        if (func_080A42C8() == 1) {
            y = p->unk_50 >> 8;
        } else {
            y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
        }

        if (p->unk_54 > 0) {
            DrawSprite(p->unk_4C >> 8, y, gUnk_08F709B0[3].unk_04, p->unk_04,
                       gUnk_02039DD4->unk_054, affine, attr, p->unk_A0);

            if (*(void**)&w[0x60] != 0) {
                DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x60], p->unk_00,
                           gUnk_02039DD4->unk_054, affine, attr,
                           (u16)(p->unk_A0 - 2));
            }

            if ((s32)gUnk_02039DD4->unk_0F8 > 0) {
                affine2 = AllocObjAffine(0, p->unk_54, gUnk_02039DD4->unk_0F8, 0);

                if (*(void**)&w[0x58] != 0) {
                    DrawSprite(p->unk_4C >> 8, y + 17, *(void**)&w[0x58],
                               p->unk_08, gUnk_02039DD4->unk_054, affine2, 0x400,
                               (u16)(p->unk_A0 - 1));
                }

                if (gUnk_02039DD4->unk_108[1] == 1 && *(void**)&w[0x5C] != 0) {
                    DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x5C], p->unk_0C,
                               gUnk_02039DD4->unk_054, affine, 0x400,
                               (u16)(p->unk_A0 - 1));
                }
            }
        }
    }
}

void func_080836C4(UnkStruct_08095A5C* p, void* a, u8 b, s8 c) {
    AnimInit(&p->unk_10, gUnk_09EEA4E0, gUnk_09EEA494);

    if (c >= 0) {
        AnimStart(&p->unk_10, c, 0);
    } else {
        AnimStart(&p->unk_10, 0, 0);
    }

    p->unk_60 = AnimGetGfx(&p->unk_10);
}

void func_08083714(UnkStruct_08083B20* w) {
    UnkStruct_08095A5C* q;

    q = w->unk_20;
    w->unk_00 = AllocObjTiles(128, 0);
    func_08002A10(w->unk_00, gUnk_0909A4E0);
    func_080836C4(w->unk_20, w->unk_00, w->unk_46, gUnk_02039DD4->unk_0FE);
    w->unk_14 = 0;
    w->unk_04 = LoadObjTiles(gUnk_0909FDCA, 0x280);
    w->unk_18 = 0;
    w->unk_08 = AllocObjTiles(0x200, 0);
    func_08002A10(w->unk_08, gUnk_090A0C86);
    w->unk_0C = AllocObjTiles(128, 0);
    func_08002A10(w->unk_0C, gUnk_090A0C86);
    AnimInit(q->unk_28, gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(q->unk_28, 1, 1);
    q->unk_58 = gUnk_09EEAF4C[3];
    AnimInit(q->unk_40, gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(q->unk_40, gUnk_02039DD4->unk_106, 1);
    q->unk_5C = gUnk_09EEAF4C[gUnk_02039DD4->unk_102 + 2];
}

void func_080837FC(UnkStruct_02034AAC* p) {
    if (gUnk_02039B9C->unk_0F4 == 16) {
        if (p->unk_78 & 4) {
            p->unk_A7 = 1;
            p->unk_A5 = GetRandom() % 10;
        } else {
            p->unk_A7 = 0;
            p->unk_A5 = p->unk_48->unk_20;
        }
    } else if (gUnk_02039B9C->unk_0F4 == 31) {
        p->unk_A7 = 1;
        p->unk_A5 = 10 - p->unk_48->unk_20;

        if (p->unk_A5 == 10) {
            p->unk_A5 = 0;
        }
    } else if (gUnk_02039B9C->unk_0F4 == 17) {
        p->unk_A7 = 1;
        p->unk_A5 = 0;
    } else {
        p->unk_A5 = p->unk_48->unk_20;
        p->unk_A7 = 0;
    }
}

void func_080838A0(void) {
    BtlWork* p;

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

void Bosscard_0(UnkStruct_08083930* w, u32* a) {
    u8 m;

    w->unk_24 = a[0];
    gUnk_02039DDC = 2;
    gUnk_02039DD8 = GetRandom() % 9;
    w->unk_28 = 0x100;
    w->unk_2A = 0x84;
    w->unk_2C = 0x100;
    w->unk_2F = 1;
    w->unk_30 = 1;
    w->unk_2E = 0;
    w->unk_31 = 8;
    w->unk_32 = 1;
    w->unk_33 = 0;
    w->unk_34 = GetRandom() % 100;
    w->unk_08 = gUnk_09EE275C[w->unk_24];
    w->unk_00 = &gCardDefs[w->unk_08[0]];
    w->unk_04 = &gUnk_08F70A28[w->unk_00->unk_1C >> 12];
    m = gUnk_08F7DAC4[w->unk_24];
    gUnk_02039DD4->unk_0D7 = GetRandom() % m;
}

u8 Bosscard_1(u8* work, void* a) {
    s32 v;
    u8 z;
    s32 c;

    work[0x2E] += 4;

    if (gUnk_02039DD4->unk_0E0 == 1) {
        z = 0;
        c = 0x100;
        *(u16*)&work[0x28] = c;
        work[0x31] = 8;
        gUnk_02039DD4->unk_0E0 = z;
    }

    if (work[0x31] != 0) {
        v = *(s16*)&work[0x28] << 8;
        ApproachValue(&v, 0xDC00, work[0x31]);
        *(s16*)&work[0x28] = v >> 8;
        work[0x31]--;
    }

    if (gUnk_02039DDC == 7) {
        work[0x31] = 8;
        SetTaskUpdate(a, (void*)func_08083ADC);
    }

    if (gUnk_02039DDC == 1) {
        if (func_08083B20((UnkStruct_08083B20*)work, 1) != 0) {
            gUnk_02039DDC = 0;
        }
    }

    if (gUnk_02039DDC == 2) {
        if (work[0x33] == work[0x34]) {
            if (func_08083B20((UnkStruct_08083B20*)work, 0) != 0) {
                work[0x33] = 0;
                work[0x34] = GetRandom() % 100;
            }
        } else {
            work[0x33]++;
        }
    }

    return 1;
}

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
void Bosscard_2(void) {
}
void Bosscard_3(void) {
}

u8 func_08083B20(UnkStruct_08083B20* w, u8 b) {
    if (w->unk_32 == 1) {
        w->unk_2C -= 51;

        if (w->unk_2C <= 2) {
            w->unk_2C = 2;
            w->unk_32 = 0;

            if (b == 0) {
                gUnk_02039DD8 = GetRandom() % 9 + 1;
            }

            func_08091B38(gUnk_02039DD8);
        }
    } else {
        w->unk_2C += 51;

        if (w->unk_2C > 255) {
            w->unk_2C = 256;
            w->unk_32 = 1;
            return 1;
        }
    }

    return 0;
}

void map_anim_0(UnkStruct_08083B94* p) {
    u8 i;

    p->unk_14 = gUnk_09EE4A2C[*(s32*)&gUnk_02039DC8[0x44]];

    if (p->unk_14 != 0) {
        for (i = 0; i < p->unk_14->unk_04; i++) {
            p->unk_01[i] = 0;
            p->unk_09[i] = 0;
        }
    }

    p->unk_00 = 0;
}

u8 map_anim_1(UnkStruct_08083B94* w) {
    UnkStruct_08083BE4_Anim* a;
    UnkStruct_08083BE4_Entry* e;
    UnkStruct_08083BE4_Frame* f;
    UnkStruct_08083BE4_Frame* f2;
    u8 i;
    u8* dst;

    a = w->unk_14;

    if (a == 0) {
        return 1;
    }

    for (i = w->unk_00; i < (a = w->unk_14)->unk_04; i++) {
        e = &a->unk_00[i];
        f = &e->unk_00[w->unk_09[i]];
        w->unk_01[i]++;

        if (w->unk_01[i] == f->unk_02) {
            w->unk_09[i]++;

            if (w->unk_09[i] == e->unk_08) {
                w->unk_09[i] = 0;
            }

            f2 = &e->unk_00[w->unk_09[i]];
            dst = (u8*)GetBgCharBase(3) + 0x7000;
            RequestDma3Copy(e->unk_04 + f2->unk_00, dst + e->unk_0A, e->unk_0C);
            w->unk_01[i] = 0;
        }
    }

    return 1;
}

void map_anim_2(void) {
}
void map_anim_3(void) {
}

Deck* func_08083C94(void) {
    Deck* active;
    void** p;
    s32 i;

    active = GetActiveDeck();
    p = &gUnk_0203A854;
    *p = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        ((Deck*)gUnk_0203A854)->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 99; i++) {
        if (active->cards[i] != 0xFFFF) {
            ((Deck*)gUnk_0203A854)->cards[i] = gCardCollection[active->cards[i]];
        } else {
            ((Deck*)gUnk_0203A854)->cards[i] |= 0xFFFF;
        }
    }

    for (i = 0; i < 20; i++) {
        ((Deck*)gUnk_0203A854)->unk_C6[i] = gDecks[GetActiveDeckIndex()].unk_C6[i];
    }

    ((Deck*)gUnk_0203A854)->unk_DA = func_08085770(GetActiveDeckIndex());
    ((Deck*)gUnk_0203A854)->unk_DC = func_08085B38(GetActiveDeckIndex());
    return gUnk_0203A854;
}

void func_08083D68(void) {
    EwramFree(gUnk_0203A854);
}

Deck* func_08083D7C(void) {
    s32 i;

    gUnk_0203A850 = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        gUnk_0203A850->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 20; i++) {
        gUnk_0203A850->unk_C6[i] = 0;
    }

    gUnk_0203A850->unk_DA = 0;
    gUnk_0203A850->unk_DC = 0;
    return gUnk_0203A850;
}

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

u16 func_08083E54(u8 mode) {
    u8 slot;
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    switch (mode) {
    case 0:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                slot = gCardDefs[cards[i] & CARD_ID_MASK].unk_2A;

                if (slot <= 2) {
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

Deck* sub_08083EFC(void) {
    return gUnk_0203A850;
}

void func_08083F08(u8 kind, u16* out) {
    Deck* deck;
    u16 i;

    deck = sub_08083EFC();

    for (i = 0; i < 99; i++) {
        if (deck->cards[i] != 0xFFFF) {
            switch (kind) {
            case 0:
                if (gCardDefs[deck->cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                    *out++ = deck->cards[i];
                }
                break;
            case 3:
                if (gCardDefs[deck->cards[i] & CARD_ID_MASK].unk_2A == 3) {
                    *out++ = deck->cards[i];
                }
                break;
            }
        }
    }
}

void func_08083F84(u16 a) {
    s16 v;

    v = func_08084458(a);

    if (gCardDefs[a].unk_20 + func_08085770(GetActiveDeckIndex()) <=
            gGameState.cp &&
        v != -1) {
        func_08085290(v);
    }
}

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

void func_08084AC8(u16 a) {
    if (gGameState.flags & 8) {
        switch (a) {
        case 0x51:
            func_0800FC14(44);
            break;
        case 0x4E:
            func_0800FC14(38);
            break;
        case 0x56:
            func_0800FC14(45);
            break;
        case 0x50:
            func_0800FC14(40);
            break;
        case 0x4F:
            func_0800FC14(42);
            break;
        case 0x55:
            func_0800FC14(39);
            break;
        case 0x57:
            func_0800FC14(41);
            break;
        case 0x59:
            func_0800FC14(43);
            break;
        case 0x58:
            func_0800FC14(48);
            break;
        case 0x54:
            func_0800FC14(50);
            break;
        case 0x5A:
            func_0800FC14(51);
            break;
        case 0x5D:
            func_0800FC14(54);
            break;
        case 0x60:
            func_0800FC14(57);
            break;
        }
    }
}

u16 func_08084BAC(void) {
    u16 count;
    u16 i;

    count = i = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            count++;
        }
    }

    return count;
}

u16 func_08084BF0(void) {
    u16 count;
    u16 i;

    count = i = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK && (gCardCollection[i] & 0x7000)) {
            count++;
        }
    }

    return count;
}

INCLUDE_ASM("card/func_08084C40.s");

void func_08084D78(UnkStruct_08084D78* out, u8 deck, u8 mode) {
    u16 mask;
    u16 i;
    s32 x;

    mask = 0;

    if (mode == 1) {
        switch (deck) {
        case 0:
            mask = 0x1000;
            break;
        case 1:
            mask = 0x2000;
            break;
        case 2:
            mask = 0x4000;
            break;
        }
    } else {
        mask = 0x7000;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }

        if (gCardCollection[i] & mask) {
            continue;
        }

        if (!(gCardCollection[i] & 0x8000)) {
            x = gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C;
            out[x].unk_14 = x;
            out[x].unk_16++;
        } else {
            x = gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C;
            out[x + 0x8F].unk_14 = x + 0x8F;
            out[x + 0x8F].unk_16++;
        }
    }
}

u16 func_08084E50(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n) {
    u16 mask;
    u16 i;
    u16 count;
    u32 id;
    u16 x;

    mask = 0;

    if (mode == 1) {
        switch (deck) {
        case 0:
            mask = 0x1000;
            break;
        case 1:
            mask = 0x2000;
            break;
        case 2:
            mask = 0x4000;
            break;
        }
    } else {
        mask = 0x7000;
    }

    for (i = 0, count = 0; i < n; i++) {
        if (out[i].unk_16 != 0) {
            out[i].unk_1C = EwramAlloc(out[i].unk_16 * 2);
            count++;
        } else {
            out[i].unk_1C = 0;
        }

        out[i].unk_18 = 0;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }

        if (gCardCollection[i] & mask) {
            continue;
        }

        if (!(gCardCollection[i] & 0x8000)) {
            id = gCardCollection[i] & CARD_ID_MASK;
            x = gCardDefs[id].unk_1C;

            if (id > 0x1C1) {
                out[x].unk_00[0]++;
            } else {
                out[x].unk_00[gCardDefs[id].unk_20]++;
            }

            out[x].unk_1C[out[x].unk_18++] = i;
        } else {
            id = gCardCollection[i] & CARD_ID_MASK;
            x = gCardDefs[id].unk_1C + 0x8F;

            if (id > 0x1C1) {
                out[x].unk_00[0]++;
            } else {
                out[x].unk_00[gCardDefs[id].unk_20]++;
            }

            out[x].unk_1C[out[x].unk_18++] = i;
        }
    }

    return count;
}
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

u8 func_0808510C(u16 id) {
    s32 i;

    if (gGameState.flags & 8) {
        return 0;
    }

    for (i = 0; i < gCardCount; i++) {
        if ((gCardCollection[i] & CARD_ID_MASK) == id) {
            return 1;
        }
    }

    return 0;
}

void func_08085160(void) {
    u16 i;
    u16 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 99; j++) {
            gDecks[i].cards[j] |= 0xFFFF;
        }

        for (j = 0; j < 20; j++) {
            gDecks[i].unk_C6[j] = 0;
        }

        gDecks[i].unk_DA = 0;
        gDecks[i].unk_DC = 0;
    }
}

void func_080851E4(u8 deck) {
    u16 mask;
    u16 i;

    mask = 0;

    switch (deck) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    }

    for (i = 0; i < 99; i++) {
        if (gDecks[deck].cards[i] != 0xFFFF) {
            gCardCollection[gDecks[deck].cards[i]] &= ~mask;
            gDecks[deck].cards[i] |= 0xFFFF;
        }
    }

    gDecks[deck].unk_DA = 0;
    gDecks[deck].unk_DC = 0;
}

u8 func_08085290(u16 card) {
    u16* cards;
    u16 i;
    u16 v;

    i = 0;
    cards = GetActiveDeck()->cards;

    while (cards[i] != 0xFFFF) {
        i++;

        if (i == 99) {
            return 0;
        }
    }

    cards[i] = card;

    switch (gActiveDeck) {
    case 0:
        gCardCollection[card] |= 0x1000;
        break;
    case 1:
        gCardCollection[card] |= 0x2000;
        break;
    case 2:
        gCardCollection[card] |= 0x4000;
        break;
    }

    v = func_080609AC(gCardCollection[card]);
    gDecks[gActiveDeck].unk_DA += v;
    gDecks[gActiveDeck].unk_DC++;
    return 1;
}

u8 func_08085374(u16 card, u8 deck) {
    u16* cards;
    u16 i;
    u16 v;

    cards = GetDeck(deck)->cards;

    for (i = 0; i < 99 && cards[i] != 0xFFFF; i++) {
    }

    if (i == 99) {
        return 0;
    }

    cards[i] = card;

    switch (deck) {
    case 0:
        gCardCollection[card] |= 0x1000;
        break;
    case 1:
        gCardCollection[card] |= 0x2000;
        break;
    case 2:
        gCardCollection[card] |= 0x4000;
        break;
    }

    v = func_080609AC(gCardCollection[card]);
    gDecks[deck].unk_DA += v;
    gDecks[deck].unk_DC++;
    return 1;
}

void func_08085448(u16 slot) {
    u16* cards;
    u16 v;

    cards = GetActiveDeck()->cards;

    if (cards[slot] != 0) {
        switch (gActiveDeck) {
        case 0:
            gCardCollection[cards[slot]] &= ~0x1000;
            break;
        case 1:
            gCardCollection[cards[slot]] &= ~0x2000;
            break;
        case 2:
            gCardCollection[cards[slot]] &= ~0x4000;
            break;
        }
    }

    v = func_080609AC(gCardCollection[cards[slot]]);
    gDecks[gActiveDeck].unk_DA -= v;
    gDecks[gActiveDeck].unk_DC--;
    cards[slot] = 0xFFFF;
}

void func_08085518(u16* p, u8 deck) {
    u16 v;

    switch (deck) {
    case 0:
        gCardCollection[*p] &= ~0x1000;
        break;
    case 1:
        gCardCollection[*p] &= ~0x2000;
        break;
    case 2:
        gCardCollection[*p] &= ~0x4000;
        break;
    }

    v = func_080609AC(gCardCollection[*p]);
    gDecks[deck].unk_DA -= v;
    gDecks[deck].unk_DC--;
    *p = 0xFFFF;
}

void func_080855C8(void) {
    u8 i;
    u16 total;
    s32 j;
    Deck* deck;

    for (i = 0; i < 3; i++) {
        if (i == gActiveDeck) {
            continue;
        }

        total = 0;
        deck = GetDeck(i);

        for (j = 0; j < 99; j++) {
            if (deck->cards[j] != 0xFFFF) {
                total += func_080609AC(gCardCollection[deck->cards[j]]);
            }
        }

        gDecks[i].unk_DA = total;
    }
}

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

s16 func_080859A0(s32 mode, Deck* d) {
    s16 count;
    s16 i;

    count = 0;

    switch (mode) {
    case 0:
        for (i = 0; i < d->unk_DC; i++) {
            if (gCardDefs[d->cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                count++;
            }
        }
        break;
    case 1:
        for (i = 0; i < d->unk_DC; i++) {
            if (gCardDefs[d->cards[i] & CARD_ID_MASK].unk_2A == 3) {
                count++;
            }
        }
        break;
    }

    return count;
}

void func_08085A58(s32 a, u16* out) {
    u16* cards;
    u16 i;

    cards = GetActiveDeck()->cards;

    switch (a) {
    case 0:
        for (i = 0; i < 99; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[gCardCollection[cards[i]] & 0xFFF].unk_2A <= 2) {
                    *out++ = gCardCollection[cards[i]] & 0x8FFF;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < 99; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[gCardCollection[cards[i]] & 0xFFF].unk_2A == 3) {
                    *out++ = gCardCollection[cards[i]] & 0x8FFF;
                }
            }
        }
        break;
    }
}

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

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_08085C3C.s");
#endif

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_08085CB0.s");
#endif

INCLUDE_ASM("card/_08085D04.s");

u8 GetActiveDeckIndex(void) {
    return gActiveDeck;
}

void func_08085FB0(void) {
}
INCLUDE_ASM("card/func_08085FB4.s");
#ifndef VERSION_EU
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
        SetTaskUpdate(a, (void*)func_080864A4);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_080863C0.s");
#endif
u8 func_08086650(u8* work, void* a);

#ifndef VERSION_EU
u8 func_080864A4(u8* work, void* a) {
    func_08006120(0, 16);

    switch (work[0x8D0]) {
    case 0:
        LoadBgTiles(3, gUnk_09402F78, 0x2000);
        LoadBgPalette(3, gUnk_09614118, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(&gUnk_09402F78[0x2000],
                        (u8*)GetBgCharBase(3) + 0x2000, 0x2000);
        break;
    case 2:
        LoadBgMap(3, gUnk_09516AB8, 0x800);
        break;
    case 3:
        LoadBgTiles(0, gUnk_09406F78, 0xC00);
        break;
    case 4:
        LoadBgMap(0, gUnk_08125E24, 0x800);
        break;
    case 5:
        LoadBgTiles(1, &gUnk_09406F78[0xC00], 0x2000);
        break;
    case 6:
        RequestDma3Copy(&gUnk_09406F78[0x2C00],
                        (u8*)GetBgCharBase(1) + 0x2000, 0x1E20);
        break;
    case 7:
        LoadBgMap(1, gUnk_08125E24, 0x800);
        break;
    case 8:
        LoadBgTiles(2, &gUnk_09406F78[0x4A20], 0x2000);
        break;
    case 9:
        RequestDma3Copy(&gUnk_09406F78[0x6A20],
                        (u8*)GetBgCharBase(2) + 0x2000, 0x1E20);
        break;
    case 10:
        LoadBgMap(2, gUnk_08125E24, 0x800);
        break;
    case 11:
        SetBgScroll(0, -88, -16);
        SetBgScroll(1, -88, -64);
        SetBgScroll(2, -88, -112);
        work[0x8D0] = 0;
        SetTaskUpdate(a, (void*)func_08086650);
        return 1;
    }

    work[0x8D0]++;
    return 1;
}
#else
INCLUDE_ASM("card/func_080864A4.s");
#endif
INCLUDE_ASM("card/func_08086650.s");
INCLUDE_ASM("card/func_08086860.s");
#ifndef VERSION_EU
u8 func_0808686C(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x818]);

    if (!func_08006314()) {
        switch (work[0x8D0]) {
        case 0:
            ApproachValue(&work[0x860], 0, work[0x8B7]);
            ApproachValue(&work[0x864], 0x9800, work[0x8B7]);
            work[0x8B7]--;

            if (work[0x8B7] == 0) {
                work[0x8B7] = 16;
                work[0x8D0]++;
            }
            break;
        case 1:
            ApproachValue(&work[0x868], 0, work[0x8B7]);
            work[0x8B7]--;

            if (work[0x8B7] == 0) {
                ReleaseObjTiles(*(void**)&work[0x4BC]);
                ReleaseObjTiles(*(void**)&work[0x18]);
                ReleaseObjPalette(*(void**)&work[0x4C0]);
                *(void**)&work[0x4BC] = 0;
                *(void**)&work[0x18] = 0;
                *(void**)&work[0x4C0] = 0;
                work[0x8B0] = 1;
                LoadBgMap(3, gUnk_09512AB8, 0x800);
                SetTaskUpdate(a, (void*)func_080889DC);
            }
            break;
        }
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0808686C.s");
#endif
#ifndef VERSION_EU
u8 func_08086984(u8* work, void* a) {
    func_0808D6C4(work);
    func_0805F1C0(&work[0x848], gUnk_09035950[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_09035956[*(s16*)&work[0x886]] << 8);
    work[0x8B7]--;

    if (work[0x8B7] == 0) {
        work[0x8B1] = 0;
        func_0808CD48(work);
        SetTaskUpdate(a, (void*)func_08086A14);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_08086984.s");
#endif
INCLUDE_ASM("card/func_08086A14.s");
INCLUDE_ASM("card/func_080870FC.s");
INCLUDE_ASM("card/func_08087438.s");
INCLUDE_ASM("card/func_0808778C.s");

#ifdef NON_MATCHING
void func_08087B98(u8* work) {
    UnkStruct_0808E890* node;
    UnkStruct_0808E890* p;
    s32 i;

    node = ListPoolFirst(&work[0x7F0]);
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

        node = ListPoolNext(&node->unk_2C);
    }

    p = ListPoolNext(&node->unk_2C);

    while (p != 0) {
        p->unk_22--;

        if (p->unk_22 < 0) {
            p->unk_22 = 2;
            p->unk_24--;
        }

        p = ListPoolNext(&p->unk_2C);
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
#ifndef VERSION_EU
u8 func_08088EB4(u8* work, void* a) {
    u8* p;
    u8 z;

    *(void**)&work[8] = LoadObjTiles(gUnk_090A261E, 0x1800);
    *(void**)&work[12] = LoadObjPalette(gUnk_096144D8, 32);
    func_0808E364(work, 1);
    p = &work[0x8B1];
    z = 0;
    *p = 3;
    work[0x8C8] = z;
    SetTaskUpdate(a, (void*)func_08088F24);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08088EB4.s");
#endif
INCLUDE_ASM("card/func_08088F24.s");
#ifndef VERSION_EU
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
            SetTaskUpdate(a, (void*)func_08086A14);
        } else {
            work[0x8B1] = 1;
            work[0x8B7] = 4;
            SetTaskUpdate(a, (void*)func_080889DC);
        }
        break;
    }

    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08089220.s");
#endif
INCLUDE_ASM("card/func_080892E8.s");
INCLUDE_ASM("card/func_08089558.s");
INCLUDE_ASM("card/func_080897CC.s");

#ifndef VERSION_EU
u8 func_08089D20(u8* work, void* a) {
    u8* q;

    func_08006120(0, 4);
    q = &work[0x8B1];
    *q = 4;
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[0x8C0]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[0x8C1] = 0;
    *(s16*)&work[0x884] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[0x8C0];
    func_0808C3DC(work, work[0x8C1]);
    work[0x8C7] = 0;
    *q = 1;
    func_0808CD48(work);
    func_0805F1C0(&work[0x848], gUnk_090356EC[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_090356F2[*(s16*)&work[0x886]] << 8);
    SetTaskUpdate(a, (void*)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
    TaskPoolUpdate(&work[0x7C8]);
    work += 0x7DC;
    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_08089D20.s");
#endif

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
    SetTaskUpdate(a, (void*)func_0808A218);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808A114.s");
#endif
INCLUDE_ASM("card/func_0808A218.s");

#ifndef VERSION_EU
u8 func_0808A650(u8* work, void* a) {
    func_08006120(0, 4);
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[0x8C0]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[0x8C1] = 0;
    *(s16*)&work[0x884] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[0x8C0];
    func_0808C3DC(work, work[0x8C1]);
    work[0x8C7] = 0;
    work[0x8B1] = 1;
    func_0808CD48(work);
    func_0805F1C0(&work[0x848], gUnk_090356EC[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_090356F2[*(s16*)&work[0x886]] << 8);
    SetTaskUpdate(a, (void*)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
    TaskPoolUpdate(&work[0x7C8]);
    work += 0x7DC;
    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808A650.s");
#endif

#ifndef VERSION_EU
u8 func_0808A7E4(u8* work, void* a) {
    u8 z;
    u8* q;

    func_08006120(0, 4);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 0, 15, 0);
    SetupBg(1, 0, 23, 0);
    SetupBg(0, 0, 31, 0);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    SetBgScroll(2, 0, 16);
    LoadBgMap(3, gUnk_095192B8, 0x800);
    LoadBgMap(2, gUnk_095182B8, 0x800);
    LoadBgMap(1, gUnk_09514AB8, 0x800);
    DisableBg(0);
    func_0808500C(3, (u16*)&work[0x89A]);
    func_0808CC58(*(u16*)&work[0x89A], 0);
    func_0808CC58(*(u16*)&work[0x89C], 1);
    func_0808CC58(*(u16*)&work[0x89E], 2);
    func_0808CC58(*(u16*)&work[0x8A0], 3);
    q = &work[0x8B1];
    z = 0;
    *q = 9;
    func_0808E344((void**)work);
    func_0808E364(work, 0);
    func_0808C90C(work);
    work[0x8D0] = z;
    SetTaskUpdate(a, (void*)func_0808A910);
    TaskPoolUpdate(&work[0x7C8]);
    work += 0x7DC;
    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808A7E4.s");
#endif
INCLUDE_ASM("card/func_0808A910.s");
INCLUDE_ASM("card/func_0808AB48.s");

#ifndef VERSION_EU
u8 func_0808B068(u8* work, void* a) {
    u8* q;

    func_08006120(0, 4);
    q = &work[0x8B1];
    *q = 9;
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[0x8C0]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[0x8C1] = 0;
    *(s16*)&work[0x884] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[0x8C0];
    func_0808C3DC(work, work[0x8C1]);
    work[0x8C7] = 0;
    *q = 1;
    func_0808CD48(work);
    func_0805F1C0(&work[0x848], gUnk_090356EC[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_090356F2[*(s16*)&work[0x886]] << 8);
    SetTaskUpdate(a, (void*)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
    TaskPoolUpdate(&work[0x7C8]);
    work += 0x7DC;
    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808B068.s");
#endif

#ifndef VERSION_EU
u8 func_0808B208(u8* work) {
    if (func_08006314() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808B208.s");
#endif
#ifdef VERSION_US
u8 func_0808B238(u8* work, void* a) {
    *(void**)&work[0x4BC] = LoadObjTiles(gUnk_090A583E, 0x620);

    if (gGameState.flags & 8) {
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
    SetTaskUpdate(a, (void*)func_0808B30C);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808B238.s");
#endif

#ifndef VERSION_EU
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
        SetTaskUpdate(a, (void*)func_0808B208);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0808B30C.s");
#endif

#ifndef VERSION_EU
void func_0808B398(u8* work) {
    func_08066588(*(s16*)&work[0x894], *(s16*)&work[0x896], &work[0x1E8],
                  *(void**)&work[0x14], 20, work[0x8C6]);
}
#else
INCLUDE_ASM("card/func_0808B398.s");
#endif

INCLUDE_ASM("card/func_0808B3DC.s");
INCLUDE_ASM("card/func_0808B66C.s");

#ifndef VERSION_EU
void func_0808C2F0(u8* work) {
    func_0808C90C(work);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x14]);

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x4BC] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4BC]);
    }

    if (*(void**)&work[0x4C0] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4C0]);
    }

    func_0808E344((void**)work);
    func_08065AE0(&work[0x38], 8);
    func_08065AE0(&work[0x78], 8);
    func_08065AE0(&work[0xB8], 8);
    func_08065AE0(&work[0xF8], 30);
    func_08065AE0(&work[0x1E8], 90);
    ReleaseObjPalette(*(void**)&work[0x4C4]);
    TaskPoolDestroy(&work[0x7C8]);
    TaskPoolDestroy(&work[0x7DC]);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    **(u8**)&work[0x8BC] = work[0x8D2];
    ReleaseObjTiles(*(void**)&work[0x4B8]);
    ReleaseObjTiles(gUnk_0203A860[0]);
    ReleaseObjPalette(gUnk_0203A860[1]);
}
#else
INCLUDE_ASM("card/func_0808C2F0.s");
#endif

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

#ifndef VERSION_EU
void func_0808C90C(u8* work) {
    UnkStruct_0808E890* t;

    t = ListPoolFirst(&work[0x7F0]);

    while (t != 0) {
        t->unk_4A = 1;
        t = ListPoolNext(&t->unk_2C);
    }

    TaskPoolUpdate(&work[0x7C8]);
}
#else
INCLUDE_ASM("card/func_0808C90C.s");
#endif

#ifndef VERSION_EU
void func_0808C940(UnkStruct_0808C940* w, s16 n) {
    w->unk_8AE = n / 3;

    if (n % 3 != 0) {
        w->unk_8AE = n / 3 + 1;
    }
}
#else
INCLUDE_ASM("card/func_0808C940.s");
#endif

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_0808C974.s");
#endif

#ifndef VERSION_EU
void func_0808C9CC(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x7F0]);

    if (*(s16*)&work[0x8AC] != *(s16*)&work[0x8AE]) {
        while (node != 0) {
            node->unk_24--;

            if (node->unk_24 < 0) {
                node->unk_44 = 0x20000;
                func_08090170(node);
            }

            node = ListPoolNext(&node->unk_2C);
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
#else
INCLUDE_ASM("card/func_0808C9CC.s");
#endif

#ifndef VERSION_EU
u8 func_0808CA78(u8* work, u8 a) {
    UnkStruct_0808E890* n;
    u8 b;
    u16 t;

    b = a;
    n = ListPoolFirst(&work[0x7F0]);

    if (*(s16*)&work[0x8AC] <= 4) {
        return 0;
    }

    if (n == 0) {
        *(s32*)&work[0x854] -= 0x300;

        t = *(u16*)&work[0x8AC];

        if ((s16)t > 4) {
            *(u16*)&work[0x8AC] = t - 1;
        }

        if (*(s32*)&work[0x854] < 0x2800) {
            *(s32*)&work[0x854] = 0x2800;
            return 0;
        }

        if (a != 0) {
            m4aSongNumStart(0x79);
        }
    } else {
        if (b != 0) {
            m4aSongNumStart(0x79);
        }

        do {
            n->unk_24++;

            if (n->unk_24 > 3) {
                n->unk_44 = 0x20000;
                func_08090170(n);
            }

            n = ListPoolNext(n->unk_2C);
        } while (n != 0);

        *(u16*)&work[0x8AC] = *(u16*)&work[0x8AC] - 1;
        *(s32*)&work[0x854] -= 0x300;

        if (*(s32*)&work[0x854] < 0x2800) {
            *(s32*)&work[0x854] = 0x2800;
        }
    }

    func_0808C974((UnkStruct_0808C940*)work);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808CA78.s");
#endif

#ifndef VERSION_EU
UnkStruct_0808E890* func_0808CB60(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x7F0]);

    while (node != 0) {
        if (*(s16*)&work[0x884] == node->unk_22 &&
            *(s16*)&work[0x886] == node->unk_24) {
            return node;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_0808CB60.s");
#endif

INCLUDE_ASM("card/func_0808CBB4.s");

INCLUDE_ASM("card/func_0808CC58.s");

#ifndef VERSION_EU
void func_0808CD48(u8* work) {
    u16 t;

    switch (work[0x8B1]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
        AnimStart(&work[0x800], 0, 1);
        *(u16*)&work[0x882] &= ~1;
        break;
    case 1:
    case 3:
    case 12:
        AnimStart(&work[0x800], 2, 1);
        t = *(u16*)&work[0x882] | 1;
        *(u16*)&work[0x882] = t;
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808CD48.s");
#endif

INCLUDE_ASM("card/func_0808CDE8.s");

#ifndef VERSION_EU
void func_0808D0A4(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = func_08085B38(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
        base = GetBgCharBase(0);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(2);
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
}
#else
INCLUDE_ASM("card/func_0808D0A4.s");
#endif

INCLUDE_ASM("card/func_0808D16C.s");

INCLUDE_ASM("card/func_0808D258.s");
#ifndef VERSION_EU
void func_0808D438(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0x80;

    switch (kind) {
    case 0:
        RequestDma3Copy(gUnk_095152B8 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_095152CC + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_095152E0 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_09515338 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_0951534C + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808D438.s");
#endif

#ifndef VERSION_EU
void func_0808D4E4(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0xA8;

    switch (kind) {
    case 5:
        RequestDma3Copy(gUnk_095152B8 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_095152CC + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_095152E0 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_09515338 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_0951534C + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808D4E4.s");
#endif

void func_0808D594(void) {
    u8 d1[3];
    u8 d2[3];
    u16 a;
    u16 b;

    u32 base;

    a = func_08084BF0();
    b = func_08084BAC();

    d1[0] = a / 100;
    d1[1] = a / 10 - d1[0] * 10;
    d1[2] = a - d1[0] * 100 - d1[1] * 10;
    d2[0] = b / 100;
    d2[1] = b / 10 - d2[0] * 10;
    d2[2] = b - d2[0] * 100 - d2[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x340), 32);
}

#ifndef VERSION_EU
void func_0808D6C4(u8* work) {
    func_08065ACC(&work[0x38], 8);
    func_08065ACC(&work[0x78], 8);
    func_08065ACC(&work[0xB8], 8);
    work[0x8C2] = func_08065B6C(func_080857BC(0), &work[0x38]);
    work[0x8C3] = func_08065B6C(func_080857BC(1), &work[0x78]);
    work[0x8C4] = func_08065B6C(func_080857BC(2), &work[0xB8]);
}
#else
INCLUDE_ASM("card/func_0808D6C4.s");
#endif

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_0808D73C.s");
#endif

#ifndef VERSION_EU
void func_0808D7EC(u8* work, u16 index) {
    CardDef* d;

    d = &gCardDefs[index];
    work[0x8C6] = func_08065B6C(gUnk_09EE8F48[d->unk_1C], &work[0x1E8]);
}
#else
INCLUDE_ASM("card/func_0808D7EC.s");
#endif

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

#ifndef VERSION_EU
void func_0808DDD0(u8* work) {
    u16 t;

    t = func_0808C8D0(*(u16*)(*(u16*)&work[0x880] * 32 +
                              (u32)*(void**)&work[0x4D4] + 20));
    func_0808DE28(func_080609AC(t + *(s16*)&work[0x884] * 5 +
                                *(u16*)&work[0x886]));
}
#else
INCLUDE_ASM("card/func_0808DDD0.s");
#endif

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
#ifndef VERSION_EU
s32 func_0808E19C(UnkStruct_0808DB04* w) {
    u16 mask;
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 card;
    u16 v;
    u32 id;
    CardDef* def;

    mask = 0;
    idx = w->unk_884 * 5 + w->unk_886;

    switch (w->unk_8C0) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    }

    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(0x69);
        return 0;
    }

    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];
        v = gCardCollection[card];

        if (!(mask & v)) {
            id = v & 0xFFF;
            def = &gCardDefs[id];

            if (id > 0x1C1) {
                if (idx == 0) {
                    func_08085374(card, w->unk_8C0);
                    e->unk_00[idx]--;
                    func_0808DD20(e->unk_00[idx], idx);
                    m4aSongNumStart(0x66);
                    return e->unk_00[idx];
                }
            } else if (def->unk_20 == idx) {
                func_08085374(card, w->unk_8C0);
                e->unk_00[idx]--;
                func_0808DD20(e->unk_00[idx], idx);
                m4aSongNumStart(0x66);
                return e->unk_00[idx];
            }
        }
    }

    m4aSongNumStart(0x69);
}
#else
INCLUDE_ASM("card/func_0808E19C.s");
#endif

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_0808E2F0.s");
#endif

void func_0808E344(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}

#ifndef VERSION_EU
void func_0808E364(u8* work, u8 kind) {
    switch (kind) {
    case 0:
        func_08002A10(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x818], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x818], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x818]);
        break;
    case 1:
        func_08002A10(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x818], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x818], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x818]);
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808E364.s");
#endif

#ifndef VERSION_EU
void func_0808E3E0(u8* work) {
    UnkStruct_0808E890* n;

    n = ListPoolFirst(&work[0x7F0]);

    while (n != 0) {
        if (n->unk_24 == *(s16*)&work[0x886] && n->unk_22 == *(s16*)&work[0x884]) {
            if (n->unk_20 != 0xFFFF) {
                func_08085518(n->unk_28, work[0x8C0]);
                n->unk_4A = 1;
                ((UnkStruct_0808E3E0*)n)->unk_24 |= 0xFFFF;
                m4aSongNumStart(0x66);
            } else {
                m4aSongNumStart(0x69);
            }

            return;
        }

        n = ListPoolNext(&n->unk_2C);
    }

    m4aSongNumStart(0x69);
}
#else
INCLUDE_ASM("card/func_0808E3E0.s");
#endif
#ifndef VERSION_EU
u8 func_0808E474(UnkStruct_0808DB04* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 id;
    u16 c;
    CardDef* def;

    idx = w->unk_884 * 5 + w->unk_886;
    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(0x69);
        return 1;
    }

    for (i = 0; i < e->unk_16; i++) {
        id = e->unk_1C[i];

        if (id == 0xFFFF) {
            continue;
        }

        c = gCardCollection[id] & CARD_ID_MASK;
        def = &gCardDefs[c];

        if (c > 0x1C2) {
            if (idx != 0) {
                continue;
            }

            if (def->unk_2A != 0) {
                return 1;
            }

            if (func_08084FAC(def->unk_2A) > 1) {
                return 1;
            }

            TaskCreate(&w->unk_4D8[0x304], gUnk_09EE7FD8, &w->unk_888[0x41]);
            m4aSongNumStart(0x69);
            return 0;
        } else {
            if (def->unk_20 != idx) {
                continue;
            }

            if (def->unk_2A != 0) {
                return 1;
            }

            if (func_08084FAC(def->unk_2A) > 1) {
                return 1;
            }

            TaskCreate(&w->unk_4D8[0x304], gUnk_09EE7FD8, &w->unk_888[0x41]);
            m4aSongNumStart(0x69);
            return 0;
        }
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0808E474.s");
#endif
INCLUDE_ASM("card/func_0808E58C.s");

#ifndef VERSION_EU
s32 func_0808E750(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gGameState.cp) {
        TaskCreate(&work[0x7DC], gUnk_09EE7FA8, &work[0x8C9]);
        m4aSongNumStart(105);

        return 0;
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0808E750.s");
#endif

#ifndef VERSION_EU
s32 func_0808E79C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(105);
        TaskCreate(&work[0x7DC], gUnk_09EE7FC0, &work[0x8C9]);

        return 0;
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0808E79C.s");
#endif

#ifndef VERSION_EU
void func_0808E7D8(u8* work) {
    UnkStruct_0808E890* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x7F0]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (node->unk_48 & 1) {
            ReleaseObjPalette(node->unk_04);
            ReleaseObjTiles(node->unk_08);
            ReleaseObjPalette(node->unk_0C);
            ReleaseObjTiles(node->unk_10);
            node->unk_48 &= ~1;
            node->unk_08 = 0;
            node->unk_0C = 0;
            node->unk_10 = 0;
            node->unk_04 = 0;
        }

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    *(s32*)&work[0x854] = 0x2800;
    *(u16*)&work[0x8AC] = 4;
}
#else
INCLUDE_ASM("card/func_0808E7D8.s");
#endif

#ifndef VERSION_EU
s32 func_0808E890(u8* work) {
    UnkStruct_0808E890* t;

    t = ListPoolFirst(&work[0x7F0]);

    while (t != 0) {
        if (t->unk_22 == *(s16*)&work[0x884]) {
            if (t->unk_24 == *(s16*)&work[0x886]) {
                return 1;
            }
        }

        t = ListPoolNext(&t->unk_2C);
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_0808E890.s");
#endif

#ifndef VERSION_EU
u8 func_0808E8E8(u8* work, u16 a, u16 b) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x7F0]);

    while (node != 0) {
        if (node->unk_22 == (s16)a && node->unk_24 == (s16)b) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_0808E8E8.s");
#endif

#ifndef VERSION_EU
u8 func_0808E934(u8* work, s16 x, s16 y, u16 dir) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x7F0]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    switch (dir) {
    case 0x40:
        return func_0808E934(work, x, y - 1, 0x40);
    case 0x80:
        return func_0808E934(work, x, y + 1, 0x80);
    case 0x20:
        return func_0808E934(work, x - 1, y, 0x20);
    case 0x10:
        return func_0808E934(work, x + 1, y, 0x10);
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_0808E934.s");
#endif

INCLUDE_ASM("card/func_0808EA0C.s");
INCLUDE_ASM("card/func_0808EC24.s");
INCLUDE_ASM("card/func_0808EDA4.s");

u8 func_0808EF80(u8* work, u16 dir) {
    u16 row;
    u16 row2;

    row = *(u16*)&work[0x7C2];

    if ((s16)row == 3 && *(u16*)&work[0x7C0] > 9) {
        switch (dir) {
        case 0x40:
            *(u16*)&work[0x7C2] = row - 1;
            break;
        case 0x80:
            *(u16*)&work[0x7C2] = row + 1;
            break;
        case 0x20:
            *(u16*)&work[0x7C0] = 9;
            break;
        case 0x10:
            *(u16*)&work[0x7C0] = 0;
            break;
        }
    }

    if (work[0x7C7] == 0) {
        row2 = *(u16*)&work[0x7C2];

        if ((s16)row2 == 5 && (u16)(*(u16*)&work[0x7C0] - 5) <= 4) {
            switch (dir) {
            case 0x40:
                *(u16*)&work[0x7C2] = row2 - 1;
                break;
            case 0x80:
                *(u16*)&work[0x7C2] = row2 + 1;
                break;
            case 0x20:
                *(u16*)&work[0x7C0] = 4;
                break;
            case 0x10:
                *(u16*)&work[0x7C0] = 10;
                break;
            }
        }
    }

    if (*(s16*)&work[0x7C2] > 6) {
        *(s16*)&work[0x7C2] = 0;
    }

    if (*(s16*)&work[0x7C2] < 0) {
        *(s16*)&work[0x7C2] = 6;
    }

    if (*(s16*)&work[0x7C0] > 14) {
        *(s16*)&work[0x7C0] = 0;
    }

    if (*(s16*)&work[0x7C0] < 0) {
        *(s16*)&work[0x7C0] = 14;
    }

    if (*(s16*)&work[0x7C2] == 6 && *(s16*)&work[0x7C0] > 11) {
        if (*(s16*)&work[0x7C0] == 13 && dir == 0x20) {
            *(s16*)&work[0x7C0] = 11;
            AnimStart(&work[0x798], 0, 1);
        } else {
            *(s16*)&work[0x7C0] = 14;
            AnimStart(&work[0x798], 1, 1);
        }

        return 0;
    }

    return 1;
}

INCLUDE_ASM("card/func_0808F0C0.s");
void func_0808F258(u8 a) {
    u32 base;

    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_09417378[a * 64], (void*)(base + 32), 64);
}
#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_0808F284.s");
#endif
#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_0808F2CC.s");
#endif

#ifndef VERSION_EU
void func_0808F304(u8* work) {
    u8* p;
    s32 t;
    u8 i;

    if (work[0x7C4] == 0) {
        m4aSongNumStart(105);
        return;
    }

    for (i = work[0x7C4] - 1; i <= 8; i++) {
        p = &work[0x784];
        t = i * 2;
        p[t] = 0;
        t++;
        p[t] = 0;
    }

    m4aSongNumStart(104);
}
#else
INCLUDE_ASM("card/func_0808F304.s");
#endif

INCLUDE_ASM("card/func_0808F358.s");
INCLUDE_ASM("card/func_0808F3E8.s");
INCLUDE_ASM("card/func_0808F660.s");

#ifndef VERSION_EU
u8 func_0808FA0C(u8* work, void* a) {
    func_08006120(0, 16);
    work[0x8B1] = 0;
    func_0808E364(work, 0);
    func_0808CD48(work);
    func_08065AE0(&work[0x744], 8);
    ReleaseObjTiles(*(void**)&work[0x738]);
    ReleaseObjTiles(*(void**)&work[0x73C]);
    ReleaseObjPalette(*(void**)&work[0x740]);
    work[0x8D0] = 0;
    SetTaskUpdate(a, (void*)func_080864A4);
    func_0808C3DC(work, 0);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808FA0C.s");
#endif

INCLUDE_ASM("card/func_0808FA8C.s");
void DeckCard2_0(UnkStruct_0808E890* n, UnkStruct_080A6838_Args* a) {
    *(UnkStruct_080A6838_Args*)&n->unk_1C = *a;
    n->unk_08 = 0;
    n->unk_0C = 0;
    n->unk_10 = 0;
    n->unk_04 = 0;
    n->unk_48 = 0;

    switch (n->unk_26) {
    case 0:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = gUnk_09035956[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    case 1:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = gUnk_09035964[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    }

    if (n->unk_20 != 0xFFFF) {
        if (!(n->unk_20 & 0x8000)) {
            n->unk_4D = 0;
        } else {
            n->unk_4D = 1;
        }

        n->unk_14 = &gCardDefs[n->unk_20 & 0xFFF];

        if (n->unk_14->unk_1E & 0xC) {
            n->unk_18 = &gUnk_08F709B0[3];
        } else {
            n->unk_18 = &gUnk_08F709B0[n->unk_14->unk_2A];
        }
    }

    n->unk_4A = 0;
    func_08000D20(n->unk_2C, n->unk_1C, n);
    func_08000D28(n->unk_2C, n->unk_1C);
}

u8 DeckCard2_1(UnkStruct_0808E890* n) {
    if (n->unk_4A == 1) {
        return 0;
    }

    switch (n->unk_26) {
    case 0:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = gUnk_09035956[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    case 1:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = gUnk_09035964[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    }

    if (func_080901B8((u8*)n)) {
        func_08090100(n);
    } else {
        func_08090170(n);
    }
}

void DeckCard2_2(UnkStruct_0808E890* n) {
    if (!(n->unk_48 & 1)) {
        return;
    }

    if (n->unk_08 != 0 && n->unk_0C != 0) {
        DrawSprite(n->unk_40 >> 8, n->unk_44 >> 8, n->unk_14->unk_10, n->unk_08, n->unk_0C, 0, 0, 0x33);

        if (n->unk_4D != 0) {
            DrawSprite(n->unk_40 >> 8, n->unk_44 >> 8, gUnk_0203A860[8], gUnk_0203A860[0], gUnk_0203A860[1], 0, 0, 0x28);
        }
    }

    if (n->unk_26 == 0 && n->unk_14->unk_2A != 3) {
        DrawSprite((n->unk_40 >> 8) - 3, (n->unk_44 >> 8) - 4, gUnk_09EE981C[n->unk_14->unk_20], n->unk_10, n->unk_04, 0, 0, 0x31);
    }
}

void DeckCard2_3(u8* p) {
    func_08090170((UnkStruct_0808E890*)p);
    func_08000D90(&p[0x2C], *(void**)&p[0x1C]);
}

void func_08090100(UnkStruct_0808E890* n) {
    if (n->unk_20 == 0xFFFF) {
        return;
    }

    if (n->unk_48 & 1) {
        return;
    }

    n->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    n->unk_08 = LoadObjTiles(n->unk_14->unk_14, 0x200);
    n->unk_0C = LoadObjPalette(n->unk_14->unk_18, 32);
    n->unk_10 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);

    if (n->unk_08 != 0 && n->unk_0C != 0) {
        n->unk_48 |= 1;
    }
}

void func_08090170(UnkStruct_0808E890* node) {
    if (node->unk_48 & 1) {
        ReleaseObjPalette(node->unk_04);
        ReleaseObjTiles(node->unk_08);
        ReleaseObjPalette(node->unk_0C);
        ReleaseObjTiles(node->unk_10);
        node->unk_48 &= 0xFFFE;
        node->unk_08 = 0;
        node->unk_0C = 0;
        node->unk_10 = 0;
        node->unk_04 = 0;
    }
}

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

void card_enemy_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_14 = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 0x50;
    p->unk_9C = 0;
    func_080901E0((s32*)&p->unk_38, (u8*)&p->unk_48, ((UnkStruct_08090244*)&p->unk_38)->unk_0C);
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_8C = gUnk_09035978[0];
    p->unk_90 = gUnk_09035978[1];
    p->unk_4C = 0xDC00;
    p->unk_50 = 0x8400;
    p->unk_A5 = p->unk_48->unk_20;
    func_08090224((u8*)p);
}

u8 card_enemy_1(UnkStruct_02034AAC* p, void* a) {
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
        SetTaskUpdate(a, (void*)func_0809075C);
    } else if (!(p->unk_78 & 0x1000)) {
        func_08090864(p);
        p->unk_5F += 4;
        func_08090B50(p, a);

        if (!(p->unk_78 & 0x20)) {
            p->unk_78 &= ~0x40;
            SetTaskUpdate(a, (void*)func_08090808);
        }
    }

    return 1;
}

#ifdef NON_MATCHING
void func_08090374(UnkStruct_02034AAC* p) {
    void* gfx;
    s32 affine;

    gfx = p->unk_48->unk_00;

    if (p->unk_78 & 0x800) {
        if (!(p->unk_78 & 1)) {
            if (p->unk_78 & 0x80) {
                if ((p->unk_78 & 8) == 0) {
                    affine = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 0);
                } else {
                    affine = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 1);
                }

                DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                           gUnk_08F70A28[0].unk_00, (&gUnk_02039DD4->unk_030)[p->unk_48->unk_2A],
                           gUnk_02039DD4->unk_054, affine, 0x410, (u16)(p->unk_A0 - 1));
                DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                           gfx, p->unk_00, p->unk_14, affine, 0x410, p->unk_A0);

                if (p->unk_A7 != 0) {
                    DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                               gUnk_09EE981C[p->unk_A5], gUnk_02039DD4->unk_04C,
                               gUnk_02039DD4->unk_058, affine, 0x410, (u16)(p->unk_A0 - 2));
                } else {
                    DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                               gUnk_09EE981C[p->unk_A5], gUnk_02039DD4->unk_044,
                               gUnk_02039DD4->unk_054, affine, 0x410, (u16)(p->unk_A0 - 2));
                }
            }
        }
    }
}
#else
INCLUDE_ASM("card/func_08090374.s");
#endif
void func_08090530(u8* work) {
    if (*(void**)&work[0x00] != 0) {
        func_0807C39C((UnkStruct_02034AAC*)work);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjPalette(*(void**)&work[0x18]);
    }
}

u8 func_08090550(UnkStruct_02034AAC* p, void* a) {
    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x10000000;
        SetTaskUpdate(a, (void*)func_08090940);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_08090DB0);
    }

    return 1;
}

#ifdef NON_MATCHING
u8 EnemyUsecard_1(UnkStruct_02034AAC* p, void* a) {
    p->unk_A0 = 80;
    ApproachValue(&p->unk_4C, 0x7800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x8400, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    }

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_08090550);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = (u16)(GetRandom() % 33) - 16;
            p->unk_9E = GetRandom() % 5 + 254;
            SetTaskUpdate(a, (void*)func_080909A4);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_080909A4);
    }

    return 1;
}
#else
INCLUDE_ASM("card/EnemyUsecard_1.s");
#endif
u8 func_0809075C(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_4C, gSineTable[((p->unk_7C >> 8) - 32) & 0xFF] * (p->unk_84 >> 8) + gUnk_09035978[0],
                  p->unk_9C);
    ApproachValue(&p->unk_50, -gSineTable[(((p->unk_7C >> 8) - 32) & 0xFF) + 0x40] * (p->unk_84 >> 8) + gUnk_09035978[1],
                  p->unk_9C);
    p->unk_9C--;

    if ((s16)p->unk_9C <= 1) {
        p->unk_9C = 0;
        p->unk_78 &= ~0x10;
        SetTaskUpdate(a, (void*)card_enemy_1);
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
        SetTaskUpdate(a, (void*)card_enemy_1);
    }

    return 1;
}

void func_08090864(UnkStruct_02034AAC* p) {
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

    p->unk_4C = gSineTable[((p->unk_7C >> 8) - 32) & 0xFF] * (p->unk_84 >> 8) + p->unk_8C;
    p->unk_50 = -gSineTable[(((p->unk_7C >> 8) - 32) & 0xFF) + 64] * (p->unk_84 >> 8) + p->unk_90;
}

u8 func_08090940(u8* work) {
    ApproachValue(&work[0x50], 0x8200, *(u16*)&work[0x9C]);
    *(u16*)&work[0x9C] =
        *(s16*)&work[0x9C] > 0 ? *(u16*)&work[0x9C] - 1 : 0;

    if (*(s16*)&work[0x9C] == 0) {
        *(u16*)&work[0x9C] = 0;
        work[0x5E] += work[0x9E];
        work[0x9E]++;

        if (*(s32*)&work[0x54] <= 25) {
            return 0;
        }

        *(s32*)&work[0x54] -= 25;
        *(s32*)&work[0x58] -= 25;
    }

    return 1;
}

u8 func_080909A4(UnkStruct_02034AAC* p) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->unk_4C -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->unk_068 &= ~0x10000000;
        return 0;
    }

    return 1;
}

void func_08090A54(UnkStruct_02034AAC* p, void* a) {
    p->unk_4C -= gSineTable[p->unk_9E] * 3;
    func_0807CD48(p);

    if (p->unk_9E != 0) {
        p->unk_9E -= 8;
    } else {
        p->unk_9E = 0;
        p->unk_78 &= ~0x800;
        SetTaskUpdate(a, (void*)card_enemy_1);
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08090808);
    }
}

void func_08090ACC(UnkStruct_02034AAC* p, void* a) {
    p->unk_4C += gSineTable[p->unk_9E] * 3;
    func_0807CD48(p);

    if ((s8)p->unk_9E >= 0) {
        p->unk_9E += 8;
    } else {
        p->unk_9E = 0x80;
        p->unk_78 &= ~4;
        p->unk_A0 = 100;
        SetTaskUpdate(a, (void*)func_08090A54);
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08090808);
    }
}

void func_08090B50(UnkStruct_02034AAC* p, void* a) {
    switch (p->unk_A1) {
    case 5:
        p->unk_9C = 16;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)EnemyUsecard_1);
        break;
    case 6:
        p->unk_9C = 8;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)func_08090C3C);
        break;
    case 8:
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_080909A4);
        break;
    case 7:
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_080909A4);
        break;
    case 9:
        p->unk_9E = 0;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)func_08090ACC);
        p->unk_A1 = 0;
        break;
    }
}

u8 func_08090C3C(UnkStruct_02034AAC* p, void* a) {
    s32 (*tbl)[2]; s32* q;

    if (gBtlWork->unk_070 == 1) {
        return 1;
    }

    func_0807CD48(p);

    if (p->unk_78 & 0x20) {
        q = &p->unk_4C; tbl = (s32 (*)[2])gUnk_09035978; ApproachValue(q, tbl[3 - p->unk_9F][0], p->unk_9C); ApproachValue(&p->unk_50, ((s32 (*)[2])gUnk_09035978)[3 - p->unk_9F][1], p->unk_9C);
    } else {
        ApproachValue(&p->unk_4C, gUnk_09035978[8], p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_09035978[9], p->unk_9C);
    }

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        p->unk_78 &= ~0x40;
    } else {
        p->unk_9C = 0;
        p->unk_78 |= 0x40;
    }

    if (p->unk_A1 == 5) {
        if (!(gBtlWork->unk_068 & 0x80) && p->unk_9F == 0) {
            gBtlWork->unk_068 |= 0x80;
        }

        if (p->unk_78 & 0x8000) {
            SetTaskUpdate(a, (void*)func_0807CF4C);
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            SetTaskUpdate(a, (void*)func_0807CFA8);
        }
    }

    p->unk_5F += 4;
    return 1;
}
u8 func_08090DB0(UnkStruct_02034AAC* p, void* a) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->unk_4C += 0x200;
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
        gBtlWork->unk_068 &= ~0x10000000;
        return 0;
    }

    return 1;
}
#ifdef NON_MATCHING
void func_08090EA0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    s32* tbl;
    u8 n;
    s32 id;
    u8* g;
    u8* q;

    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(s32*)&p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_14 = 0;
    *(s32*)&p->unk_1C = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_3C[4]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_3C[4]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_3C[4];

    if (n == 1) {
        id = tbl[0];
    } else if (*(s16*)&p->unk_3C[8] != -1) {
        if (*(s16*)&p->unk_3C[8] > n) {
            id = tbl[GetRandom() % n];
        } else {
            id = tbl[*(s16*)&p->unk_3C[8] - 1];
        }
    } else {
        if (gUnk_02039DD4->unk_0D7 > n) {
            gUnk_02039DD4->unk_0D7 = n;
        }

        id = tbl[gUnk_02039DD4->unk_0D7];
        gUnk_02039DD4->unk_0D7 = GetRandom() % n;
    }

    p->unk_48 = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x804;
    p->unk_8C = 0xDC00;
    p->unk_90 = 0x8800;
    p->unk_4C = 0xDC00;
    p->unk_50 = 0x8800;
    p->unk_9C = 10;
    p->unk_A0 -= 4;
    func_0807C33C(p);
    q = &p->unk_A5;
    *q = p->unk_48->unk_20;
    g = (u8*)&gGameState;

    switch (*(s32*)(g + 0x1B8)) {
    case 1:
        *q += 2;

        if (*q > 9) {
            *q = 9;
        }

        p->unk_A7 = 1;
        break;
    case 2:
        *q = *q > 2 ? *q - 2 : 1;
        p->unk_A7 = 1;
        break;
    default:
        p->unk_A7 = 0;
        break;
    }

    p->unk_78 |= 0x80;
}
#else
INCLUDE_ASM("card/func_08090EA0.s");
#endif

void func_08091048(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    s32* tbl;
    u8 n;
    s32 id;

    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_14 = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_3C[4]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_3C[4]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_3C[4];

    if (n == 1) {
        id = tbl[0];
    } else if (*(s16*)&p->unk_3C[8] < n) {
        id = tbl[*(s16*)&p->unk_3C[8]];
    } else {
        id = tbl[GetRandom() % n];
    }

    p->unk_48 = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x801;
    p->unk_8C = 0x10000;
    p->unk_90 = 0x8800;
    p->unk_4C = 0x10000;
    p->unk_50 = 0x8800;
    p->unk_9C = 0x10;
    p->unk_A0 -= 4;
    p->unk_A5 = p->unk_48->unk_20;
}
void func_08091138(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    s32* tbl;
    u8 n;
    s32 id;

    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_14 = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_3C[4]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_3C[4]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_3C[4];

    if (n == 1) {
        id = tbl[0];
    } else if (*(s16*)&p->unk_3C[8] < n) {
        id = tbl[GetRandom() % *(s16*)&p->unk_3C[8]];
    } else {
        id = tbl[GetRandom() % n];
    }

    p->unk_48 = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x801;
    p->unk_8C = 0x10000;
    p->unk_90 = 0x8800;
    p->unk_4C = 0x10000;
    p->unk_50 = 0x8800;
    p->unk_9C = 0x10;
    p->unk_A0 -= 4;
    p->unk_A5 = p->unk_48->unk_20;
}

INCLUDE_ASM("card/func_08091234.s");
#ifdef NON_MATCHING
void func_080917C8(u16 a, u8 b) {
    UnkStruct_08090244 arg;
    UnkStruct_02034AAC* p;
    u8 i;

    arg.unk_00 = 0;
    arg.unk_04 = 0;
    arg.unk_08 = a;
    *(u16*)&arg.unk_0C = b;
    arg.unk_0E = 0;
    p = ((UnkStruct_02034AAC**)TaskCreate(&gUnk_02039DD4->unk_09C, &gUnk_09EE4B28[0x48], &arg))[1];
    gBtlWork->unk_068 |= 0x10000000;

    if ((gBtlWork->unk_068 & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
    } else if ((gBtlWork->unk_068 & 0x20) == 0) {
        if (gUnk_02039DD4->unk_0CC != 2) {
            if ((s16)gUnk_02039DD4->unk_0C2 < p->unk_48->unk_20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                m4aSongNumStart(0xCB);
                gBtlWork->unk_068 |= 0x800000;
                gBtlWork->unk_068 |= 0x400;
                gBtlWork->unk_068 |= 0x80;
                gUnk_02039DD4->unk_000[0] = p;
                gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
                gUnk_02039DD4->unk_0D0 = 1;
                gBtlWork->unk_0A4 = 0;
                p->unk_78 |= 0x2000;
            }
        }
    }

    p->unk_78 |= 4;
    p->unk_78 &= ~0x40;
}
#else
INCLUDE_ASM("card/func_080917C8.s");
#endif

#ifdef NON_MATCHING
void func_08091978(u16 a, u8 b) {
    UnkStruct_08090244 arg;
    UnkStruct_02034AAC* p;
    u8 i;

    arg.unk_00 = 0;
    arg.unk_04 = 0;
    arg.unk_08 = a;
    *(u16*)&arg.unk_0C = b;
    arg.unk_0E = 0;
    p = ((UnkStruct_02034AAC**)TaskCreate(&gUnk_02039DD4->unk_09C, &gUnk_09EE4B28[0x60], &arg))[1];
    gBtlWork->unk_068 |= 0x10000000;

    if ((gBtlWork->unk_068 & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
    } else if (gBtlWork->unk_068 & 0x20) {
        if (gBtlWork->unk_0F4 == 2) {
            if ((s16)gUnk_02039DD4->unk_0C2 < p->unk_48->unk_20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                m4aSongNumStart(0xCB);
                gBtlWork->unk_068 |= 0x800000;
                gBtlWork->unk_068 |= 0x400;
                gBtlWork->unk_068 |= 0x80;
                gUnk_02039DD4->unk_000[0] = p;
                gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
                gUnk_02039DD4->unk_0D0 = 1;
                gBtlWork->unk_0A4 = 0;
                p->unk_78 |= 0x2000;
            }
        }
    }

    p->unk_78 |= 4;
    p->unk_78 &= ~0x40;
}
#else
INCLUDE_ASM("card/func_08091978.s");
#endif
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
#ifndef VERSION_EU
void WORLDSELECT_0(void) {
    SetBgMode2();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
    SetBgAffine(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AB8, 1);
    TaskCreate(gUnk_02034AB8, gUnk_09EE7804, 0);
}
#else
INCLUDE_ASM("card/WORLDSELECT_0.s");
#endif
void WORLDSELECT_1(void) {
    TaskPoolUpdate(gUnk_02034AB8);
    TaskPoolDraw(gUnk_02034AB8);
}
void WORLDSELECT_2(void) {
    TaskPoolDestroy(gUnk_02034AB8);
}
INCLUDE_ASM("card/MapSelect_0.s");
#ifndef VERSION_EU
u8 MapSelect_1(u8* work, void* a) {
    *(void**)&work[0x38] = LoadObjTiles(gUnk_093F7172, 0x400);
    LoadBgTiles(1, gUnk_09508098, 0x2020);
    LoadPalette(gUnk_09618C58, (void*)0x05000180, 32);
    LoadPalette(&gUnk_09618C58[0x40], (void*)0x050001C0, 64);
    func_080062F4(12, 1);
    func_080062F4(14, 1);
    func_080062F4(15, 1);
    work[0x286]++;
    DisableBg(1);
    SetTaskUpdate(a, (void*)func_0809217C);
    return 1;
}
#else
INCLUDE_ASM("card/MapSelect_1.s");
#endif
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
            ((void**)TaskCreate(work, gTaskDescSELMAPEVKEY, &work[0x2C4]))[1];
    }

    func_08093C44((*(u8**)&work[0x1EC])[32], work);
    SetTaskUpdate(a, (void*)func_08092234);
    return 1;
}
void func_080A42B4(void);
u8 func_08094404(u8* work, void* a);

#ifdef NON_MATCHING
u8 func_08092234(u8* work, void* a) {
    u8* n;

    if (work[0x290] != 0) {
        ApproachValue(&work[0x26C], 0, work[0x290]);
        ApproachValue(&work[0x270], 0x9800, work[0x290]);
        work[0x290]--;
    } else {
        ApproachValue(&work[0x240], 0x10000, work[0x28F]);
        ApproachValue(&work[0x248], 0, work[0x28F]);
        func_08005244(1, 0, *(u32*)&work[0x240] >> 8);

        if (work[0x28F] != 0) {
            work[0x28F]--;
        } else {
            if ((gGameState.unk_17A & 8) == 0) {
                work[0x2C1] = 1;
                func_080A42B4();
                work[0x2C2] = 95;
                SetTaskUpdate(a, (void*)func_0809423C);
            } else if ((gGameState.unk_17A & 0x40) == 0 &&
                       work[0x2BE] == 1) {
                func_080A42B4();
                work[0x2C2] = 109;
                SetTaskUpdate(a, (void*)func_08094404);
                gGameState.unk_17A |= 0x40;
            } else {
                n = (u8*)ListPoolFirst(&work[0x14]);
                func_0800516C(1, gUnk_09EE4BB0, 1, 2);

                while (n != 0) {
                    *(u16*)&n[0x6C] |= 2;
                    n = (u8*)ListPoolNext(&n[0x38]);
                }

                if (*(u16*)&work[0x27C] <= 6) {
                    work[0x285] = 0;
                } else {
                    work[0x285] = *(u16*)&work[0x27C] / 6;
                }

                *(s32*)&work[0x25C] = 0x6400;
                *(s32*)&work[0x254] = 0x7A00;
                *(s32*)&work[0x244] = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                work[0x2C0] = 1;
            }
        }
    }

    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_08092234.s");
#endif

#ifndef VERSION_EU
u8 func_080923E0(UnkStruct_08093838* w, void* a) {
    s8 v;

    if (w->unk_1EC->unk_6F == 0) {
        LoadBgTiles(1, &gUnk_09508098[0x2020], 0x23C0);
        LoadBgMap(1, &gUnk_0960F2B8[0x1800], 0x800);
        func_08093D28(w->unk_1EC->unk_20, (u8*)w);
        v = func_08093E34(w->unk_1EC->unk_20, (u8*)w);
        SetTaskUpdate(a, (void*)func_0809254C);
        ReleaseObjTiles(w->unk_03C);
        w->unk_03C = AllocObjTiles(0x1E0, 0);
        func_08002A10(w->unk_03C, &gUnk_093F47E4[0xD88]);
        AnimInit(w->unk_1F8, &gUnk_09EF1194[0x38], &gUnk_09EF1180[0x38]);
        AnimStart(w->unk_1F8, 0, 1);
        w->unk_274 = AnimGetGfx(w->unk_1F8);
        w->unk_280 = w->unk_258 >> 8;
        w->unk_282 = w->unk_25C >> 8;

        if (v > 4) {
            w->unk_29C = v - 5;
            w->unk_29D = 1;
        } else {
            w->unk_29C = v;
            w->unk_29D = 0;
        }

        w->unk_28B = 4;
        w->unk_28C = 4;
        w->unk_2C0 = 0;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(w);
    return 1;
}
#else
INCLUDE_ASM("card/func_080923E0.s");
#endif
INCLUDE_ASM("card/func_0809254C.s");
u8 func_080928E4(u8* work, void* a) {
    MapcardWork* node;

    if (func_08093384(work) == 0) {
        return 0;
    }

    if ((*(MapcardWork**)&work[0x1EC])->unk_6F == 0) {
        node = (MapcardWork*)ListPoolFirst(&work[0x14]);

        while (node != 0) {
            if (*(MapcardWork**)&work[0x1EC] != node) {
                node->unk_6C |= 2;
            }

            node = (MapcardWork*)ListPoolNext(&node->unk_38);
        }

        SetTaskUpdate(a, (void*)func_08092A34);
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

    SetObjMosaicSize(work[0x299], work[0x29A]);

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

    SetObjMosaicSize(work[0x299], work[0x29A]);

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
INCLUDE_ASM("card/MapSelect_2.s");
void MapSelect_3(u8* work) {
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

u16 func_08093384(u8* work) {
    u16 count;
    u16 i;
    u16 j;

    count = 0;

    for (j = 0; j < 27; j++) {
        for (i = j * 10; i < j * 10 + 10; i++) {
            if (gUnk_0203A8C0[i] != 0) {
                count++;
                break;
            }
        }
    }

    return count;
}

void func_080933D8(UnkStruct_080933D8* p) {
    u16 i;
    u16 j;

    for (i = 0; i <= 26; i++) {
        j = i * 10;

        while (j < i * 10 + 10) {
            if (gUnk_0203A8C0[j] != 0) {
                p->unk_00 = i * 10;
                p->unk_02 = gUnk_0203A8C0[j];
                p++;
                break;
            }

            j++;
        }
    }
}

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
    TaskCreate(a, gTaskDescMapSelect, b);
}

void func_08093B8C(void) {
    u16 i;

    for (i = 0; i < 270; i++) {
        gUnk_0203A8C0[i] = 0;
    }
}

#ifndef VERSION_EU
void func_08093BB4(void) {
    func_08093B8C();

    if (!(gUnk_03006C10 & 8)) {
        func_080938F8(191);
    }
}
#else
INCLUDE_ASM("card/func_08093BB4.s");
#endif

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

#ifndef VERSION_EU
void* func_08093C18(u16 a) {
    return gUnk_09EF7048[a];
}
#else
INCLUDE_ASM("card/func_08093C18.s");
#endif

u8 func_08093C28(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("card/func_08093C44.s");

void func_08093D28(u16 a, u8* work) {
    u16 i;
    u16 j;
    u8* pal;
    MapcardWork** mp;
    s32 k;

    for (i = 0; i < 22; i++) {
        pal = &work[0x29E];
        pal[i] = gUnk_09619098[i + 32];
    }

    for (i = 22, j = 2; i < 26; i++, j++) {
        mp = (MapcardWork**)&work[0x1EC];
        pal = &work[0x29E];

        switch ((*mp)->unk_18->unk_1E) {
        case 1:
            pal[i] = gUnk_09619098[j + 0x60];
            break;
        case 2:
            pal[i] = gUnk_09619098[j + 0x40];
            break;
        case 3:
            pal[i] = gUnk_09619098[j + 0xA0];
            break;
        case 4:
            pal[i] = gUnk_09619098[j + 0x80];
            break;
        }
    }

    for (i = 26; i < 32; i++) {
        pal = &work[0x29E];
        pal[i] = gUnk_09618C58[i];
    }

    for (i = a, j = 2; i < a + 10; i++, j += 2) {
        pal = &work[0x29E];

        if (gUnk_0203A8C0[i] != 0) {
            pal[j] = -1;
            k = j + 1;
            pal[k] = 0x7F;
        }
    }

    LoadPalette(&work[0x29E], (void*)0x05000180, 32);
}

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
u8 func_0809423C(u8* work, void* a) {
    MapcardWork* n;
    u8 v;

    SetObjMosaicSize(work[0x299], work[0x29A]);

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

    if (!func_080A42C8()) {
        if (work[0x286] == 8) {
            work[0x286] = 0;

            if (work[0x2C2] <= 98) {
                func_080A4188(work, work[0x2C2]);
                work[0x2C2]++;
            } else {
                n = (MapcardWork*)ListPoolFirst(&work[0x14]);
                func_0800516C(1, gUnk_09EE4BB0, 1, 2);

                while (n != 0) {
                    n->unk_6C |= 2;
                    n = (MapcardWork*)ListPoolNext(n->unk_38);
                }

                if (*(u16*)&work[0x27C] <= 6) {
                    work[0x285] = 0;
                } else {
                    v = *(u16*)&work[0x27C] / 6;
                    work[0x285] = v;
                }
                *(s32*)&work[0x25C] = 0x6400;
                *(s32*)&work[0x254] = 0x7A00;
                *(s32*)&work[0x244] = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                work[0x2C0] = 1;
                work[0x2C2] = 99;
                return 1;
            }
        } else {
            work[0x286]++;
        }
    }

    TaskPoolUpdate(work);
    return 1;
}

#ifndef VERSION_EU
u8 func_0809438C(u8* work, void* a) {
    u8 r;

    r = func_080A42C8();

    if (r == 0) {
        if (work[0x286] == 8) {
            work[0x286] = 0;

            if (work[0x2C2] <= 0x66) {
                func_080A4188(work, work[0x2C2]);
                work[0x2C2]++;
            } else {
                gGameState.unk_17A |= 8;
                SetTaskUpdate(a, (void*)func_0809254C);
            }
        } else {
            work[0x286]++;
        }
    }

    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_0809438C.s");
#endif

INCLUDE_ASM("card/func_08094404.s");

MapcardWork* ListPoolLast(void* a);

void func_08094548(u8* work) {
    MapcardWork* n;
    s32 v;
    s32 i;

    v = *(s32*)&work[0x23C] >> 8;

    for (i = 0; i < 6; i++) {
        if (v == gUnk_09EE7520[i]) {
            break;
        }
    }

    n = func_08000D90((*(MapcardWork**)&work[0x1EC])->unk_38, &work[0x14]);
    (*(MapcardWork**)&work[0x1EC])->unk_6C |= 0x400;
    *(MapcardWork**)&work[0x1EC] = n;

    while (n != 0) {
        n->unk_21--;

        if (i <= 5) {
            n->unk_4C = gUnk_09EE7520[i] << 8;
            i++;
        }

        n = (MapcardWork*)ListPoolNext(n->unk_38);
    }

    for (n = (MapcardWork*)ListPoolFirst(&work[0x14]); n != 0; n = (MapcardWork*)ListPoolNext(n->unk_38)) {
        n->unk_6C |= 2;
    }

    if (*(MapcardWork**)&work[0x1EC] == 0) {
        *(MapcardWork**)&work[0x1EC] = ListPoolLast(&work[0x14]);

        if (*(MapcardWork**)&work[0x1EC] == 0) {
            *(s32*)&work[0x264] = 0x1600;
        } else {
            *(s32*)&work[0x264] = (*(MapcardWork**)&work[0x1EC])->unk_4C;
        }
    } else {
        *(s32*)&work[0x264] = (*(MapcardWork**)&work[0x1EC])->unk_4C;
    }
}

void Mapcard_0(MapcardWork* w, MapcardArgs* a) {
    w->unk_00 = 0;
    w->unk_04 = 0;
    w->unk_08 = 0;
    w->unk_0C = 0;
    *(MapcardArgs*)&w->unk_20 = *a;
    w->unk_4C = w->unk_21 <= 5 ? gUnk_09EE7520[w->unk_21] << 8 : -0x6400;
    w->unk_50 = 0x10500;
    w->unk_6A = 50;
    w->unk_5C = 0;
    w->unk_60 = 0;
    w->unk_64 = 0;
    w->unk_6C = 0;
    w->unk_6E = 0;
    w->unk_6F = 16;
    w->unk_70 = 0;
    w->unk_68 = 0x100;
    w->unk_71 = 0;
    w->unk_72 = 0;
    w->unk_74 = gUnk_09EE4C80[w->unk_20].unk_22;
    w->unk_18 = &gUnk_09EE4C80[w->unk_20];
    w->unk_1C = &gUnk_09EE4BF4[w->unk_18->unk_1E];
    func_08094E90(w);
    func_08094DA8(w);
    func_08094CE4((u8*)w);
}

u8 func_080947B4(u8* work, void* a);
s32 func_080948F0(u8* work, void* a);

u8 Mapcard_1(u8* work, void* a) {
    if (*(u16*)&work[0x6C] & 0xC) {
        work[0x6F] = 12;
        func_08094DEC((MapcardWork*)work);
        SetTaskUpdate(a, (void*)func_080948F0);
    }

    if (*(u16*)&work[0x6C] & 0x200) {
        work[0x6E] = 0;
        work[0x6F] = 8;
        SetTaskUpdate(a, (void*)func_080947B4);
    }

    if (*(u16*)&work[0x6C] & 0x40) {
        work[0x6E] = 0;
        work[0x6F] = 8;
        SetTaskUpdate(a, (void*)func_08094934);
    }

    if (*(u16*)&work[0x6C] & 0x400) {
        return 0;
    }

    work[0x6E] = 0;
    func_08094DA8((MapcardWork*)work);
    func_08094CE4(work);
    return 1;
}

u8 func_080947B4(u8* work, void* a) {
    ApproachValue(&work[0x4C], gUnk_09EE7520[0] << 8, work[0x6F]);
    work[0x6F]--;

    if (!(*(u16*)&work[0x6C] & 0x200)) {
        work[0x6F] = 8;
        SetTaskUpdate(a, (void*)func_0809486C);
    }

    if (*(u16*)&work[0x6C] & 0x100) {
        work[0x6E] += 8;
    } else {
        work[0x6E] = 0;
    }

    if (*(u16*)&work[0x6C] & 0x40) {
        work[0x6E] = 0;
        work[0x6F] = 8;
        SetTaskUpdate(a, (void*)func_08094934);
    }

    if (*(u16*)&work[0x6C] & 0x400) {
        return 0;
    }

    func_08094DA8((MapcardWork*)work);
    func_08094CE4(work);
    return 1;
}

u8 func_0809486C(u8* work, void* a) {
    ApproachValue(&work[0x4C], gUnk_09EE7520[work[0x21] % 6] << 8, work[0x6F]);
    work[0x6F]--;

    if (work[0x6F] == 0) {
        SetTaskUpdate(a, Mapcard_1);
    }

    if (*(u16*)&work[0x6C] & 0x100) {
        work[0x6E] += 8;
    } else {
        work[0x6E] = 0;
    }

    func_08094DA8((MapcardWork*)work);
    func_08094CE4(work);
    return 1;
}

s32 func_080948F0(u8* work, void* a) {
    u8 t;

    t = func_08094E4C(work);
    func_08094DA8(work);
    func_08094CE4(work);

    if (t == 0) {
        *(u16*)&work[0x6C] &= 0xFFF3;
        SetTaskUpdate(a, Mapcard_1);
    }

    return 1;
}

u8 func_08094934(u8* work, void* a) {
    work[0x6E] = 0;
    ApproachValue(&work[0x4C], 0x7800, work[0x6F]);
    ApproachValue(&work[0x50], 0x3800, work[0x6F]);

    if (work[0x6F] != 0) {
        work[0x6F]--;
    } else {
        work[0x70]++;

        if (work[0x70] > 15) {
            func_080949A0(work);
            SetTaskUpdate(a, (void*)func_08094A18);
        }
    }

    func_08094CE4(work);
    return 1;
}

void func_080949A0(u8* work) {
    s32 v[2];
    s32 dx;
    s32 dy;
    s32 k;
    u16* q;
    s32* p = func_080E04E0();

    dx = (p[0] >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    dy = (p[1] >> 8) + (p[2] >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 24;
    v[0] = dx * 256 - *(s32*)&work[0x4C];
    v[1] = dy * 256 - *(s32*)&work[0x50];
    *(s32*)&work[0x64] = func_0805F5A4(&v[0], &v[1]);
    *(s32*)&work[0x54] = -v[0];
    *(s32*)&work[0x58] = -v[1];
    *(s32*)&work[0x60] = 0x300;
    *(s32*)&work[0x5C] = 25;
    work[0x6E] = 0;
    q = (u16*)&work[0x68];
    k = 0x100;
    *q = k;
}

u8 func_08094A18(u8* work, void* a) {
    s32* p;
    s32 dx;
    s32 dy;
    s32 d;
    s32 x;
    s32 y;
    u16 t;
    u16 f;

    p = func_080E04E0();
    dx = (p[0] >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    dy = (p[1] >> 8) + (p[2] >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 24;

    if (*(s32*)&work[0x60] < 0) {
        x = (dx << 8) - *(s32*)&work[0x4C];
        y = (dy << 8) - *(s32*)&work[0x50];
        func_0805F5A4(&x, &y);
        *(s32*)&work[0x54] = -x;
        *(s32*)&work[0x58] = -y;
    }

    work[0x6E] += 24;
    t = *(u16*)&work[0x68];
    *(u16*)&work[0x68] = (s16)t > 25 ? t - 12 : 25;
    *(s32*)&work[0x4C] += (*(s32*)&work[0x54] * *(s32*)&work[0x60]) >> 8;
    *(s32*)&work[0x50] += (*(s32*)&work[0x58] * *(s32*)&work[0x60]) >> 8;
    d = func_0805F588((dx << 8) - *(s32*)&work[0x4C], (dy << 8) - *(s32*)&work[0x50]);
    *(s32*)&work[0x64] = d;
    *(s32*)&work[0x60] -= *(s32*)&work[0x5C];
    *(s32*)&work[0x5C] += 2;

    if ((*(u8**)&work[0x24])[0x2BE] != 1) {
        if (d <= 0x7FF) {
            func_08093BE0();
            f = *(u16*)&work[0x6C] | 0x80;
            *(u16*)&work[0x6C] = f;
            func_08093BEC((u32)&gUnk_09EE4C80[work[0x20] + work[0x74]] + 0x20);
        }
    } else {
        if (d <= 0x7FF && (*(u8**)&work[0x24])[0x2DA] == 0) {
            func_08093BE0();
            f = *(u16*)&work[0x6C] | 0x80;
            *(u16*)&work[0x6C] = f;
            func_08093BEC((u32)&gUnk_09EE4C80[work[0x20] + work[0x74]] + 0x20);
        }
    }

    return 1;
}

#ifdef NON_MATCHING
void Mapcard_2(MapcardWork* w) {
    s32 aff;
    u16 y;

    if (func_080A42C8() == 0) {
        y = (w->unk_50 >> 8) + (gSineTable[w->unk_6E] >> 8);

        if (w->unk_6C & 1) {
            if (w->unk_4C > 0 && w->unk_4C <= 0xEFFF) {
                aff = 0;

                if (w->unk_6C & 0x40) {
                    aff = AllocObjAffine(w->unk_6E, (s16)w->unk_68, (s16)w->unk_68, 1);
                }

                if (gUnk_09EE4C80[w->unk_20].unk_1E == 4) {
                    DrawSprite(w->unk_4C >> 8, y, gUnk_0203A890[4], gUnk_0203A890[0], *(void**)&w->unk_10[4], aff, 0,
                               (u16)(w->unk_6A - 2));
                }

                DrawSprite(w->unk_4C >> 8, y, *(void**)*(void**)&w->unk_1C->unk_00[8], *(void**)&w->unk_10[0],
                           *(void**)&w->unk_10[4], aff, 0, w->unk_6A);
                DrawSprite(w->unk_4C >> 8, y, *(void**)*(void**)&w->unk_18->unk_00[8], w->unk_08, w->unk_0C, aff, 0,
                           (u16)(w->unk_6A + 1));
            }
        }
    }
}
#else
INCLUDE_ASM("card/Mapcard_2.s");
#endif
void Mapcard_3(u8* work) {
    if (*(u16*)&work[0x6C] & 1) {
        ReleaseObjTiles(*(void**)&work[0x08]);
        ReleaseObjPalette(*(void**)&work[0x0C]);
        ReleaseObjTiles(*(void**)&work[0x10]);
        ReleaseObjPalette(*(void**)&work[0x14]);
    }
}

u8 func_08094CB0(s32* p) {
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

void func_08094CE4(u8* work) {
    UnkStruct_08094CE4_A* a;
    UnkStruct_08094CE4_B* b;
    u16 t;

    if (func_08094CB0((s32*)work)) {
        if (!(*(u16*)&work[0x6C] & 1)) {
            a = *(UnkStruct_08094CE4_A**)&work[0x18];
            b = *(UnkStruct_08094CE4_B**)&work[0x1C];
            *(void**)&work[0x08] = LoadObjTiles(a->unk_00, a->unk_18);
            *(void**)&work[0x0C] = LoadObjPalette(a->unk_04, 32);
            *(void**)&work[0x10] = LoadObjTiles(b->unk_00, b->unk_14);
            *(void**)&work[0x14] = LoadObjPalette(b->unk_04, 32);
            *(void**)&work[0x00] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
            func_080062F4((*(UnkStruct_080038C8**)&work[0x0C])->unk_06 + 16, 1);
            func_080062F4((*(UnkStruct_080038C8**)&work[0x14])->unk_06 + 16, 1);
            t = *(u16*)&work[0x6C] | 1;
            *(u16*)&work[0x6C] = t;
        }
    } else if (*(u16*)&work[0x6C] & 1) {
        ReleaseObjTiles(*(void**)&work[0x00]);
        ReleaseObjTiles(*(void**)&work[0x08]);
        ReleaseObjPalette(*(void**)&work[0x0C]);
        ReleaseObjTiles(*(void**)&work[0x10]);
        ReleaseObjPalette(*(void**)&work[0x14]);
        *(u16*)&work[0x6C] &= ~1;
    }
}

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
    return ((void**)TaskCreate(b, gTaskDescMapcard, a))[1];
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
        SetTaskUpdate(a, (void*)func_0809511C);
    }

    return 1;
}
void func_08095520(UnkStruct_02034AAC* p) {
    u8* q;
    s32 affine;
    void* gfx;
    s32 t;

    q = p->unk_20;
    gfx = gUnk_08F709B0[p->unk_46].unk_04;
    DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
               (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
               gfx, p->unk_04,
               gUnk_02039DD4->unk_054, 0, 0x400, 50);

    if (p->unk_58 > 0) {
        affine = AllocObjAffine(0, 0x100, p->unk_58, 0);
        DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
                   (p->unk_50 >> 8) + (t = (gSineTable[p->unk_5F] >> 8) + 17),
                   *(void**)&q[0x58], p->unk_08, gUnk_02039DD4->unk_054, affine,
                   0x400, 49);

        if (p->unk_9F == 1) {
            DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
                       (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                       *(void**)&q[0x5C], p->unk_0C, gUnk_02039DD4->unk_054, 0,
                       0x400, 49);
        }
    }

    if (*(void**)&q[0x60] != 0) {
        DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
                   (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                   *(void**)&q[0x60], *(void**)&p->unk_10[0],
                   gUnk_02039DD4->unk_054, 0, 0x400, 48);
    }

    TaskPoolDraw(&p->unk_24[0]);
}
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
s32 func_08095B04(u8* p, ReloadGageWork* w) {
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
        if (gBtlWork->unk_0F4 == 10) {
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
void PrizeCard_0(PrizeCardWork* w, PrizeCardTaskArgs* p) {
    PrizeCardTaskArgs args;
    CardDef* def;
    CardBack* back;
    u8* q;

    args = *p;
    w->unk_C8 = args.unk_20;
    def = &gCardDefs[args.unk_20];
    w->unk_00 = LoadObjTiles(def->unk_04, 0x300);
    w->unk_04 = LoadObjPalette(def->unk_08, 32);
    *(UnkStruct_08099412*)&w->unk_20[0x14] = *(UnkStruct_08099412*)&def->unk_1C;

    if (gCardDefs[w->unk_C8].unk_1E & 12) {
        back = &gUnk_08F709B0[3];
    } else {
        back = &gUnk_08F709B0[w->unk_20[0x22]];
    }

    w->unk_08 = LoadObjTiles(back->unk_0C, 0x280);
    w->unk_0C = LoadObjTiles(*(void**)back->unk_14, 0x600);
    w->unk_10 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_14 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_18 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_1C = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_A8 = args.unk_00;
    w->unk_AC = args.unk_04;
    *(s32*)&w->unk_B0[0] = args.unk_08;
    *(s32*)&w->unk_B0[4] = 0;
    w->unk_F6 = 24;
    func_080DFF4C(&w->unk_A8);
    w->unk_CC = -(GetRandom() % 129 + 0x300);
    w->unk_D0 = GetRandom() % 129 + 0x80;
    w->unk_F4 = GetRandom() % 256;
    w->unk_E0 = 0x80;
    w->unk_E2 = 0x80;
    w->unk_F2 = 0x80;
    w->unk_F7 = 0;
    w->unk_F8 = 0;
    q = &w->unk_4C[0];
    func_080122AC(q, 5, 30, 10);
    func_08012614(q, 1);
    func_08012324(q, w->unk_A8, w->unk_AC, *(s32*)&w->unk_B0[0]);
    w->unk_F9 = 0;
    w->unk_FC[0] = 0;
    w->unk_FA = 0;
    w->unk_FB = 0;
    TaskPoolInit((TaskPool*)w->unk_20, 1);
}
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
#ifndef VERSION_EU
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
            SetTaskUpdate(a, (void*)func_08096288);
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
#else
INCLUDE_ASM("card/func_0809612C.s");
#endif
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
            SetTaskUpdate(a, (void*)func_08096390);
        }
    } else if (w->unk_FB == 30) {
        w->unk_FB = 0;
        SetTaskUpdate(a, (void*)func_08096390);
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
void func_08096428(PrizeCardWork* w) {
    u16 pal;
    s32 affine;
    void* gfx;
    CardBack* back;
    CardDef* def;
    s16 v;
    s32 t;

    t = w->unk_FC[0];
    pal = 0;

    if (t == 0) {
        pal = 0x800;
    }

    if (w->unk_E0 == 0x100 && w->unk_F6 == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_F6, w->unk_E0, w->unk_E2, 1);
    }

    def = &gCardDefs[w->unk_C8];
    DrawSprite(w->unk_E6, (u16)w->unk_E8 - 8, def->unk_00, w->unk_00, w->unk_04,
               affine, pal, (u16)(w->unk_E4 + 1));
    back = &gUnk_08F709B0[w->unk_20[0x22]];
    DrawSprite(w->unk_E6, (u16)w->unk_E8 - 8, back->unk_00, w->unk_08, w->unk_10,
               affine, pal, (u16)w->unk_E4);
    gfx = gUnk_09EE981C[w->unk_20[0x18]];
    DrawSprite(w->unk_E6, (u16)w->unk_E8 - 8, gfx, w->unk_14, w->unk_10, affine,
               pal, (u16)(w->unk_E4 - 1));

    if (w->unk_FC[0] == 0) {
        v = 204 - ((*(s32*)&w->unk_B0[4] - *(s32*)&w->unk_B0[0]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(*(s16*)&w->unk_EE[0], *(s16*)&w->unk_EE[2], gUnk_09EE1380[0],
                   w->unk_18, w->unk_1C, AllocObjAffine(0, v, v, 0), pal,
                   (u16)(w->unk_E4 + 2));
    }

    TaskPoolDraw(w->unk_20);
}

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

void func_08096638(PrizeCardWork* w) {
    w->unk_E0 = (-gSineTable[((w->unk_F8 + 0x80) & 0xFF) + 0x40] * w->unk_F2) >> 8;
    w->unk_E2 = (-gSineTable[((w->unk_F7 + 0x80) & 0xFF) + 0x40] * w->unk_F2) >> 8;

    if ((u16)(w->unk_E0 + 2) <= 4) {
        w->unk_E0 = 2;
    }

    if ((u16)(w->unk_E2 + 2) <= 4) {
        w->unk_E2 = 2;
    }
}

void func_080966B4(void* a, s32 b, s32 c, s32 d) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = func_08096D48(gGameState.unk_00C[0], 0);
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

void func_08096714(PrizeCardInitWork* w, PrizeCardArgs* args) {
    w->unk_14 = 0;
    w->unk_18 = *args;
    TaskPoolInit(w, 1);
}

INCLUDE_ASM("card/PrizeCardInit_1.s");
INCLUDE_ASM("card/PrizeCardInit_Boss_1.s");
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
    if (gGameState.flags & 8) {
        return func_08096C38(gUnk_090360BC[a].unk_00, gUnk_090360BC[a].unk_04);
    } else {
        return func_08096C38(gUnk_09035DCC[a].unk_00, gUnk_09035DCC[a].unk_04);
    }
}
#else
INCLUDE_ASM("card/func_08096D0C.s");
#endif

#ifdef NON_MATCHING
u16 func_08096D48(u16 a, s32 b) {
    u16 base;
    u16 off;

    off = 0;

    if (gGameState.flags & 8) {
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
    TaskCreate(a, gTaskDescPrizeCardInit, b);
}

void func_08096DC4(void* a, void* b) {
    TaskCreate(a, gTaskDescPrizeCardInitBoss, b);
}
#ifndef VERSION_JP
void DispCardname_0(u8* work, u16* a) {
    UnkStruct_080038C8* p;
    s32 v;

    func_08065ACC((TextSlot*)work, 32);
    p = _08066468(1);
    *(void**)&work[0x104] = p;
    func_080062F4(p->unk_06 + 16, 1);
    work[0x10E] = func_08065B6C(a, (TextSlot*)work);
    *(void**)&work[0x100] = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
    *(void**)&work[0x108] = LoadObjPalette(gUnk_09611AB8, 32);
    v = (240 - func_08065B08((TextSlot*)work, work[0x10E])) / 2;
    *(s16*)&work[0x10C] = v;
}
#else
INCLUDE_ASM("card/DispCardname_0.s");
#endif
s32 DispCardname_1(void) {
    return 1;
}

void DispCardname_2(u8* work) {
    func_080664D8(*(s16*)&work[0x10C], 120, work, *(void**)&work[0x104], 50,
                  work[0x10E]);
    DrawSprite(120, 125, gUnk_09EF126C, *(void**)&work[0x100],
               *(void**)&work[0x108], 0, 0, 55);
}

void DispCardname_3(u8* work) {
    func_08065AE0(work, 32);
    ReleaseObjTiles(*(void**)&work[0x100]);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x104])->unk_06 + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x104]);
    ReleaseObjPalette(*(void**)&work[0x108]);
}

void func_08096F08(void* a, void* b) {
    TaskCreate(a, gTaskDescDispCardname, b);
}
void Version_0(u8* work) {
    *(void**)&work[0x00] = func_080668F0();
    *(void**)&work[0x04] = func_08066904();
    work[0x28] = func_0806692C(gUnk_081283C0, &work[0x08]);
}
s32 Version_1(void) {
    return 1;
}
void Version_2(u8* work) {
    func_08066DC0(0, 152, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}
void Version_3(s32* p) {
    func_08066918(p[0], p[1]);
}
s32 func_08096F80(void* a) {
    return (s32)TaskCreate(a, gTaskDescVersion, 0);
}
void func_08096F94(u8* work, s32* args) {
    u8* p;

    *(s32*)&work[0xB0] = args[8];
    *(UnkStruct_09EE4C80**)&work[0x20] = &gUnk_09EE4C80[args[8]];
    *(UnkStruct_09EE4BF4**)&work[0x24] =
        &gUnk_09EE4BF4[(*(UnkStruct_09EE4C80**)&work[0x20])->unk_1E];
    *(void**)&work[0x00] =
        LoadObjTiles((*(UnkStruct_09EE4C80**)&work[0x20])->unk_00, 0x300);
    *(void**)&work[0x04] =
        LoadObjPalette((*(UnkStruct_09EE4C80**)&work[0x20])->unk_04, 32);
    *(u64*)&work[0x3C] = *(u64*)&(*(UnkStruct_09EE4C80**)&work[0x20])->unk_20;
    *(void**)&work[0x08] =
        LoadObjTiles((*(UnkStruct_09EE4BF4**)&work[0x24])->unk_00,
                     (*(UnkStruct_09EE4BF4**)&work[0x24])->unk_14);
    *(void**)&work[0x0C] =
        LoadObjTiles((*(UnkStruct_09EE4BF4**)&work[0x24])->unk_00,
                     (*(UnkStruct_09EE4BF4**)&work[0x24])->unk_14);
    *(void**)&work[0x10] =
        LoadObjPalette((*(UnkStruct_09EE4BF4**)&work[0x24])->unk_04,
                       (*(UnkStruct_09EE4BF4**)&work[0x24])->unk_16);
    *(void**)&work[0x14] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    *(void**)&work[0x18] = LoadObjTiles(gUnk_08B22BBC, 0x100);
    *(void**)&work[0x1C] = LoadObjPalette(gUnk_08F69BE4, 32);
    *(s32*)&work[0xA0] = args[0];
    *(s32*)&work[0xA4] = args[1];
    *(s32*)&work[0xA8] = 0;
    *(s32*)&work[0xAC] = 0;
    work[0xDE] = 24;
    *(s32*)&work[0xB4] = -(GetRandom() % 129 + 0x300);
    *(s32*)&work[0xB8] = GetRandom() % 129 + 0x80;
    ((UnkStruct_08096F94*)work)->unk_0DC = GetRandom() % 256;
    *(u16*)&work[0xC8] = 0x80;
    *(u16*)&work[0xCA] = 0x80;
    *(u16*)&work[0xDA] = 0x80;
    work[0xDF] = 0;
    work[0xE0] = 0;
    p = &work[0x44];
    func_080122AC(p, 5, 8, 10);
    func_08012614(p, 1);
    func_08012324(p, *(s32*)&work[0xA0], *(s32*)&work[0xA4],
                  *(s32*)&work[0xA8]);
    work[0xE6] = 0;
    work[0xE7] = 0;
    work[0xE8] = 0;
    work[0xE1] = 0;
    work[0xE5] = 0;
    work[0xE2] = 0;
    work[0xE3] = 0;
    TaskPoolInit(&work[0x28], 1);
    gBtlWork->unk_0B0++;
}
INCLUDE_ASM("card/func_08097138.s");

void func_08097390(u8* work) {
    s16 x;
    s16 y;
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    WorldToScreen(&x, &y, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    tx = 0x7800;
    ty = 0x5000;
    dx = tx - *(s32*)&work[0xA0];
    dy = ty - *(s32*)&work[0xA4];
    *(s32*)&work[0xC4] = func_0805F5A4(&dx, &dy);
    *(s32*)&work[0xBC] = -dx;
    *(s32*)&work[0xC0] = -dy;
    *(s32*)&work[0xB8] = 0x300;
    *(s32*)&work[0xB4] = 2;
}

u8 func_08097404(u8* work, void* a) {
    s32 dx;
    s32 dy;
    u8 z;
    u8 t;
    s32 x;
    s32 y;
    s16* q1;
    s16* q2;

    if (*(s32*)&work[0xB8] < 0) {
        dx = 0x7800 - *(s32*)&work[0xA0];
        dy = 0x5000 - *(s32*)&work[0xA4];
        func_0805F5A4(&dx, &dy);
        *(s32*)&work[0xBC] = -dx;
        *(s32*)&work[0xC0] = -dy;

        if (*(s32*)&work[0xC4] <= 0x7FF) {
            work[0xE2] = 0;
            work[0xDE] = 0;
            SetTaskUpdate(a, (void*)func_0809753C);
            func_08096F08(&work[0x28], func_08093C18(*(u16*)(*(u8**)&work[0x20] + 0x20)));
        }
    }

    *(s32*)&work[0xA0] += (*(s32*)&work[0xBC] * *(s32*)&work[0xB8]) >> 8;
    *(s32*)&work[0xA4] += (*(s32*)&work[0xC0] * *(s32*)&work[0xB8]) >> 8;
    t = work[0xDE] + 32;
    z = 0;
    work[0xDE] = t;
    work[0xDF] += (64 - work[0xDF]) >> 4;
    work[0xE0] = z;
    *(s32*)&work[0xC4] = func_0805F588(0x7800 - *(s32*)&work[0xA0], 0x5000 - *(s32*)&work[0xA4]);
    *(s32*)&work[0xB8] -= *(s32*)&work[0xB4];
    *(s32*)&work[0xB4] += 2;

    if (*(s16*)&work[0xDA] <= 0xFF) {
        *(s16*)&work[0xDA] += 3;
    }

    x = *(s32*)&work[0xA0] >> 8;
    q1 = (s16*)&work[0xCE];
    *q1 = x;
    y = *(s32*)&work[0xA4] >> 8;
    q2 = (s16*)&work[0xD0];
    *q2 = y;
    func_080978B0((UnkStruct_080978B0*)work);
    return 1;
}
u8 func_0809753C(u8* work, void* a) {
    s32 v;
    s16 lim;
    s32 x;
    s16* q;

    v = work[0xDE] << 8;
    ApproachValue(&work[0xDF], 0, work[0xE2]);
    ApproachValue(&v, 0, work[0xE2]);
    ApproachValue(&work[0xA0], 0x7800, work[0xE2]);
    ApproachValue(&work[0xA4], 0x5800, work[0xE2]);
    work[0xDE] = v >> 8;

    if (work[0xE2] != 0) {
        work[0xE2]--;
    }

    lim = 0x100;

    if (*(s16*)&work[0xDA] < 0x100) {
        *(s16*)&work[0xDA] += 2;
    } else {
        *(s16*)&work[0xDA] = lim;
    }

    x = *(s32*)&work[0xA0] >> 8;
    q = (s16*)&work[0xCE];
    *q = x;
    x = *(s32*)&work[0xA4] >> 8;
    q = (s16*)&work[0xD0];
    *q = x;
    func_080978B0((UnkStruct_080978B0*)work);
    work[0xE3]++;

    if (work[0xE3] == 30) {
        work[0xE3] = 0;
        SetTaskUpdate(a, func_08097600);
    }

    TaskPoolUpdate(&work[0x28]);
    return 1;
}

u8 func_08097600(u8* work) {
    work[0xDE] += 32;
    WorldToScreen((s16*)&work[0xD2], (s16*)&work[0xD4], ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    *(s16*)&work[0xCE] += (*(s16*)&work[0xD2] - *(s16*)&work[0xCE]) >> 3;
    *(s16*)&work[0xD0] += (*(s16*)&work[0xD4] - *(s16*)&work[0xD0]) >> 3;
    *(s16*)&work[0xC8] -= 10;
    *(s16*)&work[0xCA] -= 10;

    if (*(s16*)&work[0xC8] <= 10) {
        return 0;
    }

    return 1;
}

void func_08097688(u8* work) {
    u16 pal;
    s32 affine;
    void* gfx;
    s16 v;

    pal = work[0xE5] == 0 ? func_0801AF1C(*(s32*)&work[0xA4]) : 0;

    if (*(s16*)&work[0xC8] == 0x100 && work[0xDE] == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(work[0xDE], *(s16*)&work[0xC8], *(s16*)&work[0xCA], 1);
    }

    DrawSprite(*(s16*)&work[0xCE], *(u16*)&work[0xD0] - 8,
               **(void***)((*(UnkStruct_09EE4C80**)&work[0x20])->unk_08),
               *(void**)&work[0x00], *(void**)&work[0x04], affine, pal,
               (u16)(*(u16*)&work[0xCC] + 1));

    if ((*(UnkStruct_09EE4C80**)&work[0x20])->unk_1E == 4) {
        gfx = (*(void***)((*(UnkStruct_09EE4BF4**)&work[0x24])->unk_08))[work[0xE8]];
    } else {
        gfx = (*(void***)((*(UnkStruct_09EE4BF4**)&work[0x24])->unk_08))[0];
    }

    DrawSprite(*(s16*)&work[0xCE], *(u16*)&work[0xD0] - 8, gfx,
               *(void**)&work[0x08], *(void**)&work[0x10], affine, pal,
               *(u16*)&work[0xCC]);

    if ((*(UnkStruct_09EE4C80**)&work[0x20])->unk_1E != 4) {
        gfx = gUnk_09EE981C[*(u16*)&work[0x3E]];
        DrawSprite(*(s16*)&work[0xCE], *(u16*)&work[0xD0] - 8, gfx,
                   *(void**)&work[0x14], *(void**)&work[0x10], affine, pal,
                   (u16)(*(u16*)&work[0xCC] - 1));
    }

    if (work[0xE5] == 0) {
        v = 204 - ((*(s32*)&work[0xAC] - *(s32*)&work[0xA8]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(*(s16*)&work[0xD6], *(s16*)&work[0xD8], gUnk_09EE1380[0],
                   *(void**)&work[0x18], *(void**)&work[0x1C],
                   AllocObjAffine(0, v, v, 0), pal,
                   (u16)(*(u16*)&work[0xCC] + 2));
    }

    TaskPoolDraw(&work[0x28]);
}

void func_08097834(PrizeCardWork* w) {
    func_080062F4(w->unk_10->unk_06 + 16, 0);
    func_080062F4(w->unk_04->unk_06 + 16, 0);
    func_08012304(&w->unk_20[0x24]);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjTiles(w->unk_0C);
    ReleaseObjTiles(w->unk_18);
    ReleaseObjPalette(w->unk_04);
    ReleaseObjPalette(w->unk_10);
    ReleaseObjPalette(w->unk_1C);
    TaskPoolDestroy(&w->unk_20[8]);
    gBtlWork->unk_0B0--;
}

void func_080978B0(UnkStruct_080978B0* w) {
    w->unk_C8 = (-gSineTable[((w->unk_E0 + 0x80) & 0xFF) + 0x40] * w->unk_DA) >> 8;
    w->unk_CA = (-gSineTable[((w->unk_DF + 0x80) & 0xFF) + 0x40] * w->unk_DA) >> 8;

    if ((u16)(w->unk_C8 + 2) <= 4) {
        w->unk_C8 = 2;
    }

    if ((u16)(w->unk_CA + 2) <= 4) {
        w->unk_CA = 2;
    }
}

#ifndef VERSION_EU
void func_0809792C(u8* work) {
    u8* p;
    u8* q;
    u8 k;
    u8 v;
    u8 z;

    v = gUnk_09EE752C[work[0xE7]].unk_00;
    q = &work[0xE8];
    z = 0;
    *q = v;
    p = &work[0xE6];
    k = work[0xE7];

    if (*p == gUnk_09EE752C[k].unk_01) {
        work[0xE7] = k + 1;

        if (work[0xE7] == 7) {
            work[0xE7] = z;
        }

        *p = z;
    }

    work[0xE6]++;
}
#endif

void func_0809797C(void* a, void* b) {
    TaskCreate(a, gUnk_09EE7650, b);
}

void SpotLight_0(UnkStruct_08097A14* w, u8* src) {
    if (src != 0) {
        w->unk_10 = src;
    } else {
        w->unk_10 = &w->unk_14;
        w->unk_14 = 0;
    }

    LoadBgTiles(0, gUnk_09501778, 0xCA0);
    LoadPalette(gUnk_09618C38, gUnk_050001A0, 32);
    func_080062F4(13, 1);
    LoadBgMap(0, gUnk_0960F2B8, 0x800);
    SetBgScroll(0, 0, 0);
    w->unk_00 = 30;
    w->unk_04 = 0x1000;
    w->unk_08 = 0;
    func_08006184(0, 30);
    gBldCnt = 0xE41;
}

u8 SpotLight_1(UnkStruct_08097A14* w, void* a) {
    ApproachValue(&w->unk_08, 0x1000, w->unk_00);

    if (w->unk_00 != 0) {
        w->unk_00--;
        w->unk_0C = ((w->unk_04 >> 8) << 8) | (w->unk_08 >> 8);
        gBldAlpha = w->unk_0C;
    }

    if (*w->unk_10 == 1) {
        func_08006120(0, 30);
        w->unk_00 = 30;
        gBldCnt = 0xE41;
        SetTaskUpdate(a, (void*)func_08097A80);
    }

    return 1;
}

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
void SpotLight_2(void) {
}
void SpotLight_3(void) {
    func_080062F4(13, 0);
}
#ifdef NON_MATCHING
void SELMAP_EVKEY_0(u8* work, void* a) {
    s32 zero;
    s32 i;
    s32 ofs;
    u8* q1;
    u8* q2;
    u8* q3;

    zero = 0;
    CpuSet(&zero, work, 0x05000049);
    *(void**)&work[0xD8] = a;
    *(void**)&work[0xF8] = ((void**)a)[1];
    work[0x121] = func_080E8D00();

    for (i = 0; i < work[0x121]; i++) {
        ofs = i * 52;
        func_08098014(&work[ofs + 8], func_080E8D1C((u8)i));
        q1 = &work[0x14];

        if (*(u8**)&q1[ofs] != 0) {
            func_080062F4(*(u16*)&(*(u8**)&q1[ofs])[6] + 16, 1);
        }
        q2 = &work[0x18];

        if (*(u8**)&q2[ofs] != 0) {
            func_080062F4(*(u16*)&(*(u8**)&q2[ofs])[6] + 16, 1);
        }
        q3 = &work[0x1C];

        if (*(u8**)&q3[ofs] != 0) {
            func_080062F4(*(u16*)&(*(u8**)&q3[ofs])[6] + 16, 1);
        }
    }

    *(void**)&work[0] = AllocObjTiles(0x6C0, 0);
    func_08002A10(*(void**)&work[0], &gUnk_093F47E4[0x22E8]);
    AnimInit((AnimState*)&work[0xDC], (s32)gUnk_09EF1224, (s32)gUnk_09EF1220);
    AnimStart((AnimState*)&work[0xDC], 0, 1);
    *(void**)&work[0xF4] = AnimGetGfx((AnimState*)&work[0xDC]);
    *(void**)&work[4] = **(void***)&work[0xD8];
    work[0x11C] = 0;
    work[0x11D] = 0;
    work[0x11E] = 8;
    work[0x11F] = 8;
    work[0x120] = 0;
    work[0x123] = 0;
    SetObjMosaicSize(work[0x11E], work[0x11F]);
    *(s32*)&work[0xFC] = 0x7800;
    *(s32*)&work[0x100] = 0x4000;
    *(u16*)&work[0x114] = 0x100;
    *(u16*)&work[0x116] = 0x100;
    work[0x11B] = 0;
    work[0x122] = 0;
    work[0x11A] = 8;
    *(u16*)&work[0x118] = 0;
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[8]);
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[0x3C]);
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[0x70]);
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[0xA4]);
}
#else
INCLUDE_ASM("card/SELMAP_EVKEY_0.s");
#endif
s32 SELMAP_EVKEY_1(u8* work, void* a) {
    s32 i;
    u8* q1;
    u8* q2;
    u8* q3;
    u8* r;
    u8 n;

    *(void**)&work[0xF4] = AnimUpdate(&work[0xDC]);
    *(s32*)&work[0x104] = ((240 - (work[0x121] - work[0x122]) * 32) << 7) + 0x1000;
    ApproachValue(&work[0xFC], *(s32*)&work[0x104], work[0x11A]);

    if (work[0x11A] != 0) {
        work[0x11A]--;
    }

    for (i = work[0x122]; i < work[0x121]; i++) {
        func_08098598(*(s32*)&work[0xFC] + ((i - work[0x122]) << 13), *(s32*)&work[0x100], (s32*)&work[i * 52 + 8]);
    }

    SetObjMosaicSize(work[0x11E], work[0x11F]);

    if (work[0x120] == 2) {
        if (work[0x11E] != 0) {
            work[0x11E]--;
        }

        if (work[0x11F] != 0) {
            work[0x11F]--;
        }

        work[0x120] = 0;
    }

    work[0x120]++;
    work[0x11D]++;

    if ((*(void***)&work[0xD8])[2] != 0) {
        SetTaskUpdate(a, (void*)func_08097DE4);
    }

    q1 = &work[work[0x122] * 52];

    if (*(u16*)&q1[0x36] != 0) {
        r = func_080E8D1C(0);
        q2 = &work[work[0x122] * 52];
        *(u16*)&q2[0x36] = r[3];
        n = work[0x122];
        q3 = &work[n * 52];

        if (*(u16*)&q3[0x38] != *(u16*)&q3[0x36]) {
            func_080984E4((UnkStruct_080984E4*)&work[n * 52 + 8]);
        }
    }

    *(u16*)&work[0x118] += 8;
    return 1;
}
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

    SetObjMosaicSize(*a, *b);
    return 1;
}
INCLUDE_ASM("card/SELMAP_EVKEY_2.s");
void SELMAP_EVKEY_3(u8* work) {
    s32 i;

    for (i = 0; i < work[0x121]; i++) {
        func_08098778((void**)&work[i * 52 + 8]);
    }

    ReleaseObjTiles(*(void**)&work[0x00]);
}

INCLUDE_ASM("card/func_08098014.s");

void func_080984E4(UnkStruct_080984E4* w) {
    s32 z;

    if (w->unk_2E <= 9) {
        z = 0;
        func_080038E4(w->unk_08, gUnk_09EF1198[0], gUnk_0950C478);
        w->unk_20 = z;
        RequestDma3Copy(w->unk_08->unk_00 + w->unk_2E * 128, &gUnk_06010000[w->unk_08->unk_06 * 32], 128);
    } else {
        z = 0;
        func_080038E4(w->unk_08, gUnk_09EF1198[2], gUnk_0950C478);
        w->unk_20 = z;
        RequestDma3Copy(w->unk_08->unk_00 + (u16)(w->unk_2E / 10) * 128, &gUnk_06010000[w->unk_08->unk_06 * 32], 128);
        RequestDma3Copy(w->unk_08->unk_00 + (w->unk_2E - (u16)(w->unk_2E / 10) * 10) * 128, &gUnk_06010000[(w->unk_08->unk_06 + 4) * 32], 128);
    }

    w->unk_30 = w->unk_2E;
}

void func_08098598(s32 a, s32 b, s32* c) {
    c[9] = a;
    c[10] = b;
}

void func_080985A0(UnkStruct_08098670* w, u16 b, s16 c, s16 d) {
    s32 aff;

    aff = AllocObjAffine(0, d, d, 1);

    if (w->unk_00 != 0) {
        DrawSprite(w->unk_24 >> 8, c + (w->unk_28 >> 8), w->unk_18, w->unk_00, w->unk_0C, aff, b, 10);
    }

    if (w->unk_04 != 0) {
        DrawSprite(w->unk_24 >> 8, c + (w->unk_28 >> 8), w->unk_1C, w->unk_04, w->unk_10, aff, b, 9);
    }

    if (w->unk_08 != 0) {
        DrawSprite(w->unk_24 >> 8, c + (w->unk_28 >> 8), w->unk_20, w->unk_08, w->unk_14, aff, b, 8);
    }
}

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

u8 func_080987C0(u16 n) {
    u8 idx;

    idx = 0;

    switch (n) {
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 170;
        break;
    case 3:
        idx = 50;
        break;
    case 4:
        idx = 40;
        break;
    case 5:
        idx = 190;
        break;
    case 6:
        idx = 20;
        break;
    case 7:
        idx = 30;
        break;
    case 8:
        idx = 160;
        break;
    case 9:
        idx = 180;
        break;
    case 10:
        idx = 210;
        break;
    case 11:
        idx = 100;
        break;
    case 12:
        idx = 90;
        break;
    case 13:
        idx = 110;
        break;
    case 14:
        idx = 120;
        break;
    case 15:
        idx = 200;
        break;
    case 16:
        idx = 140;
        break;
    case 17:
        idx = 150;
        break;
    case 18:
        idx = 130;
        break;
    case 19:
        idx = 60;
        break;
    case 20:
        idx = 70;
        break;
    case 21:
        idx = 80;
        break;
    case 22:
        idx = 220;
        break;
    case 23:
        idx = 230;
        break;
    case 24:
        idx = 240;
        break;
    case 0:
    case 26:
        idx = 10;
        break;
    case 25:
    case 27:
        idx = 250;
        break;
    }

    return gUnk_09EE4C80[idx].unk_1E;
}

void RELOAD_CHILDREN_0(UnkStruct_08098BE8* w, UnkStruct_080988C0_Args* a) {
    *(UnkStruct_080988C0_Args*)&w->unk_0C = *a;
    w->unk_00 = LoadObjTiles(gUnk_09EE7698[w->unk_19], 128);
    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_08 = 0;

    switch (w->unk_1A[0]) {
    case 1:
        if ((s8)w->unk_18 <= 3) {
            w->unk_20 = gUnk_090361B0[(s8)w->unk_18] << 8;
            w->unk_24 = gUnk_090361C0[(s8)w->unk_18] << 8;
        } else {
            w->unk_20 = gUnk_090361B0[3] << 8;
            w->unk_24 = gUnk_090361C0[3] << 8;
        }
        break;
    case 2:
        if ((s8)w->unk_18 <= 3) {
            w->unk_20 = gUnk_090361B8[(s8)w->unk_18] << 8;
            w->unk_24 = gUnk_090361C0[(s8)w->unk_18] << 8;
        } else {
            w->unk_20 = gUnk_090361B8[3] << 8;
            w->unk_24 = gUnk_090361C0[3] << 8;
        }
        break;
    }

    func_08000D20(w->unk_30, *(void**)w->unk_0C, w);
    func_08000D28(w->unk_30, *(void**)w->unk_0C);
    w->unk_46 = 0;
}

u8 RELOAD_CHILDREN_1(u8* work, void* a) {
    u8 (*fn)(u8*, void*);

    if (*(u16*)&work[0x1C] & 2) {
        work[0x46]++;

        if (work[0x46] == 30) {
            work[0x44] = 8;
            fn = func_08098AE4;
            SetTaskUpdate(a, fn);
            return fn(work, a);
        }
    }

    if (*(u16*)&work[0x1C] & 1) {
        work[0x44] = 8;
        *(u16*)&work[0x1C] &= ~1;
    }

    if (work[0x18] <= 3) {
        switch (work[0x1A]) {
        case 1:
            ApproachValue(&work[0x20], gUnk_090361B0[*(s8*)&work[0x18]] << 8, work[0x44]);
            break;
        case 2:
            ApproachValue(&work[0x20], gUnk_090361B8[*(s8*)&work[0x18]] << 8, work[0x44]);
            break;
        }

        ApproachValue(&work[0x24], gUnk_090361C0[*(s8*)&work[0x18]] << 8, work[0x44]);
    } else if ((s8)work[0x18] < 0) {
        func_08000D90(&work[0x30], *(void**)&work[0xC]);
        *(void**)&work[8] = LoadObjTiles(gUnk_08F709B0[work[0x19]].unk_10, 0xD00);
        work[0x44] = 8;
        *(s32*)&work[0x28] = 0x66;
        SetTaskUpdate(a, (void*)func_08098BA4);
        return 1;
    }

    if (work[0x44] != 0) {
        work[0x44]--;
    }

    work[0x45] += 8;
    return 1;
}

u8 func_08098AE4(u8* work, void* a) {
    u8 (*f)(u8*, void*);
    u16 v;

    v = *(u16*)&work[0x1C] & 2;

    if (v == 0) {
        work[0x44] = 8;
        f = RELOAD_CHILDREN_1;
        SetTaskUpdate(a, (void*)f);
        work[0x46] = 0;
        return f(work, a);
    }

    switch (work[0x1A]) {
    case 1:
        ApproachValue(&work[0x20], gUnk_090361B0[(s8)work[0x18]] << 8, work[0x44]);
        break;
    case 2:
        ApproachValue(&work[0x20], gUnk_090361B8[(s8)work[0x18]] << 8, work[0x44]);
        break;
    }

    ApproachValue(&work[0x24], gUnk_090361C0[3] << 8, work[0x44]);

    if (work[0x44] != 0) {
        work[0x44]--;
    }

    return 1;
}

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

void RELOAD_CHILDREN_2(UnkStruct_08098BE8* w) {
    s16 x;
    s16 y;
    s32 aff;

    if (w->unk_18 <= 3) {
        x = (w->unk_20 + *w->unk_10) >> 8;
        y = (w->unk_24 + *w->unk_14) >> 8;
        DrawSprite(x, y + (gSineTable[w->unk_45] >> 8), gUnk_09EEA344[0], w->unk_00, w->unk_04, 0, 0, 50);
    }

    if ((s8)w->unk_18 < 0) {
        x = (w->unk_20 + *w->unk_10) >> 8;
        y = (w->unk_24 + *w->unk_14) >> 8;
        aff = AllocObjAffine(0, w->unk_28, w->unk_28, 0);
        DrawSprite(x, y + (gSineTable[w->unk_45] >> 8), gUnk_08F709B0[w->unk_19].unk_04, w->unk_08, w->unk_04, aff, 0, 49);
    }
}

void RELOAD_CHILDREN_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);

    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
    }
}
void REV_COUNT_0(u8* work, UnkStruct_080991CC* a) {
    vu32 zero;
    s16* count;
    s16* count2;
    void** row;
    u8 idx;

    zero = 0;
    CpuSet((void*)&zero, work, 0x05000011);
    *(UnkStruct_080991CC*)&work[0x2C] = *a;
    idx = work[0x38];
    work[0x24] = idx;
    *(void**)&work[0x00] = func_080038C8(320);
    *(void**)&work[0x04] = LoadObjPalette(gUnk_09611AB8, 32);

    if (work[0x24] == 0) {
        count = *(s16**)&work[0x30];

        if (*count >= 2 && *count <= 100) {
            row = gUnk_09EE76D0[work[0x24]];
            func_080038E4(*(void**)&work[0x00], row[*count - 2], gUnk_09EE76C0[work[0x24]]);
        } else if (*count > 100) {
            row = gUnk_09EE76D0[work[0x24]];
            func_080038E4(*(void**)&work[0x00], row[98], gUnk_09EE76C0[work[0x24]]);
        } else {
            row = gUnk_09EE76D0[work[0x24]];
            func_080038E4(*(void**)&work[0x00], row[0], gUnk_09EE76C0[work[0x24]]);
        }
    } else {
        count2 = *(s16**)&work[0x30];

        if (*count2 >= 1 && *count2 <= 99) {
            row = gUnk_09EE76D0[work[0x24]];
            func_080038E4(*(void**)&work[0x00], row[*count2 - 1], gUnk_09EE76C0[work[0x24]]);
        } else {
            row = gUnk_09EE76D0[work[0x24]];
            func_080038E4(*(void**)&work[0x00], row[0], gUnk_09EE76C0[work[0x24]]);
        }
    }

    *(void**)&work[0x08] = AnimGetGfx(&work[0x0C]);
    *(u16*)&work[0x26] = **(u16**)&work[0x30];

    switch (work[0x39]) {
    case 1:
        *(s32*)&work[0x3C] = -0x2000;
        *(s32*)&work[0x40] = 0x9800;
        break;
    case 2:
        *(s32*)&work[0x3C] = 0x11000;
        *(s32*)&work[0x40] = 0x9800;
        break;
    }

    work[0x28] = 8;
}
u8 func_08098FDC(u8* work);
u8 func_08099048(u8* work, void* a);
u8 func_080990CC(u8* work, void* a);

#ifdef NON_MATCHING
u8 REV_COUNT_1(u8* work, void* a) {
    u8 (*f)(u8*, void*);
    s16* count;
    void** row;

    count = *(s16**)&work[0x30];

    if (*count != *(s16*)&work[0x26]) {
        if (work[0x24] == 0) {
            if (*count >= 2 && *count <= 100) {
                row = gUnk_09EE76D0[work[0x24]];
                func_080038E4(*(void**)&work[0x00], row[*count - 2],
                              gUnk_09EE76C0[work[0x24]]);
            } else {
                work[0x28] = 8;
                f = func_080990CC;
                SetTaskUpdate(a, (u32)f);
                *(u16*)&work[0x26] = **(u16**)&work[0x30];
                return f(work, a);
            }
        } else {
            if (*count >= 1 && *count <= 99) {
                row = gUnk_09EE76D0[work[0x24]];
                func_080038E4(*(void**)&work[0x00], row[*count - 1],
                              gUnk_09EE76C0[work[0x24]]);
            } else {
                work[0x28] = 8;
                f = func_080990CC;
                SetTaskUpdate(a, (u32)f);
                *(u16*)&work[0x26] = **(u16**)&work[0x30];
                return f(work, a);
            }
        }

        *(u16*)&work[0x26] = **(u16**)&work[0x30];
    } else if (*count <= 0) {
        work[0x28] = 8;
        f = func_080990CC;
        SetTaskUpdate(a, (u32)f);
        *(u16*)&work[0x26] = **(u16**)&work[0x30];
        return f(work, a);
    }

    switch (work[0x39]) {
    case 1:
        ApproachValue(&work[0x3C], 0, work[0x28]);
        break;
    case 2:
        ApproachValue(&work[0x3C], 0xD800, work[0x28]);
        break;
    }

    if (work[0x28] != 0) {
        work[0x28]--;
    }

    if (work[0x38] != **(u8**)&work[0x2C]) {
        f = (u8 (*)(u8*, void*))func_08098FDC;
        SetTaskUpdate(a, (u32)f);
        work[0x28] = 8;
        return f(work, a);
    }

    if (gBtlWork->unk_0A0 == 4) {
        work[0x28] = 8;
        SetTaskUpdate(a, (u32)func_08099048);
    }

    if (**(u8**)&work[0x34] == 0) {
        work[0x28] = 8;
        SetTaskUpdate(a, (u32)func_08099048);
    }

    return 1;
}
#else
INCLUDE_ASM("card/REV_COUNT_1.s");
#endif

u8 func_08098FDC(u8* work) {
    switch (work[0x39]) {
    case 1:
        ApproachValue(&work[0x3C], -0x2000, work[0x28]);
        break;
    case 2:
        ApproachValue(&work[0x3C], 0x11000, work[0x28]);
        break;
    }

    if (work[0x28] != 0) {
        work[0x28]--;
    }

    if (work[0x38] == **(u8**)&work[0x2C] && **(s16**)&work[0x30] > 0) {
        return 0;
    }

    return 1;
}

u8 func_08099048(u8* work, void* a) {
    u8 (*f)(u8*, void*);

    switch (work[0x39]) {
    case 1:
        ApproachValue(&work[0x3C], -0x2000, work[0x28]);
        break;
    case 2:
        ApproachValue(&work[0x3C], 0x11000, work[0x28]);
        break;
    }

    if (work[0x28] == 0) {
        return 0;
    }

    work[0x28]--;

    if (**(u8**)&work[0x34] == 1) {
        work[0x28] = 8;
        f = REV_COUNT_1;
        SetTaskUpdate(a, (void*)f);
        return f(work, a);
    }

    return 1;
}

u8 func_080990CC(u8* work, void* a) {
    u8 (*f)(u8*, void*);

    switch (work[0x39]) {
    case 1:
        ApproachValue(&work[0x3C], -0x2000, work[0x28]);
        break;
    case 2:
        ApproachValue(&work[0x3C], 0x11000, work[0x28]);
        break;
    }

    if (work[0x28] != 0) {
        work[0x28]--;
    }

    do {
        if (work[0x24] == 0) {
            if (**(s16**)&work[0x30] > 1) {
                f = REV_COUNT_1;
                SetTaskUpdate(a, (void*)f);
                work[0x28] = 8;
                return f(work, a);
            }
        } else {
            if (**(s16**)&work[0x30] > 0) {
                f = REV_COUNT_1;
                SetTaskUpdate(a, (void*)f);
                work[0x28] = 8;
                return f(work, a);
            }
        }

        return 1;
    } while (0);
}
void REV_COUNT_2(u8* work) {
#ifdef VERSION_EU
    DrawSprite(*(s32*)&work[0x3C] >> 8, *(s32*)&work[0x40] >> 8, 0,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 1040, 15);
#else
    DrawSprite(*(s32*)&work[0x3C] >> 8, *(s32*)&work[0x40] >> 8, 0,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 1024, 15);
#endif
}
void REV_COUNT_3(void** p) {
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
    TaskCreate(pool, gTaskDescREVCOUNT, &args);
}

void RELOAD_0(UnkStruct_080991F8* w, UnkStruct_080991F8_Args* a) {
    w->unk_00 = AllocObjTiles(0xA0, 0);
    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    *(UnkStruct_080991F8_Args*)&w->unk_2C = *a;
    func_08002A10(w->unk_00, gUnk_09EE7708[w->unk_2C]);
    AnimInit(&w->unk_0C, gUnk_09EE7714[w->unk_2C], gUnk_09EE7720[w->unk_2C]);
    AnimStart(&w->unk_0C, 0, 1);
    w->unk_08 = AnimGetGfx(&w->unk_0C);

    switch (w->unk_2D) {
    case 1:
        w->unk_24 = -0x3000;
        w->unk_28 = 0x7E00;
        break;
    case 2:
        w->unk_24 = 0xB4800;
        w->unk_28 = 0x7E00;
        break;
    }

    w->unk_34 = 6;
}

u8 RELOAD_1(u8* work, void* a) {
    *(void**)&work[8] = AnimUpdate(&work[0x0C]);

    switch (work[0x2D]) {
    case 1:
        ApproachValue(&work[0x24], 0x1800, work[0x34]);
        break;
    case 2:
        ApproachValue(&work[0x24], 0xD800, work[0x34]);
        break;
    }

    if (work[0x34] != 0) {
        work[0x34]--;
    }

    if (**(u8**)&work[0x30] == 0) {
        work[0x34] = 8;
        SetTaskUpdate(a, (void*)func_08099330);
    }

    if (gBtlWork->unk_0A0 == 4) {
        work[0x34] = 8;
        SetTaskUpdate(a, (void*)func_08099330);
    }

    return 1;
}

u8 func_08099330(u8* work) {
    *(void**)&work[8] = AnimUpdate(&work[0x0C]);

    switch (work[0x2D]) {
    case 1:
        ApproachValue(&work[0x24], -0x3000, work[0x34]);
        break;
    case 2:
        ApproachValue(&work[0x24], 0x12000, work[0x34]);
        break;
    }

    if (work[0x34] != 0) {
        work[0x34]--;
        return 1;
    }

    return 0;
}

void RELOAD_2(u8* work) {
    DrawSprite(*(s32*)&work[0x24] >> 8, *(s32*)&work[0x28] >> 8,
               *(void**)&work[0x08], *(void**)&work[0x00], *(void**)&work[0x04], 0,
               0, 10);
}
void RELOAD_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}
void PrizeBoss_0(u8* work, s32* args) {
    CardDef* def;
    CardBack* back;
    u8* p;

    *(s32*)&work[0xB8] = args[8];
    def = &gCardDefs[args[8]];
    *(void**)&work[0x00] = LoadObjTiles(def->unk_04, 0x300);
    *(void**)&work[0x04] = LoadObjPalette(def->unk_08, 32);
    *(UnkStruct_08099412*)&work[0x34] = *(UnkStruct_08099412*)&def->unk_1C;
    back = &gUnk_08F709B0[def->unk_2A];
    *(void**)&work[0x08] = LoadObjTiles(back->unk_0C, 0x280);
    *(void**)&work[0x0C] = LoadObjTiles(*(void**)back->unk_14, 0x600);
    *(void**)&work[0x10] = LoadObjPalette(gUnk_09611AB8, 32);
    *(void**)&work[0x14] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    *(void**)&work[0x18] = LoadObjTiles(gUnk_08B22BBC, 0x100);
    *(void**)&work[0x1C] = LoadObjPalette(gUnk_08F69BA4, 32);
    *(s32*)&work[0xA8] = args[0];
    *(s32*)&work[0xAC] = args[1];
    *(s32*)&work[0xB0] = args[2];
    *(s32*)&work[0xB4] = 0;
    work[0xE6] = 24;
    *(s32*)&work[0xBC] = -(GetRandom() % 129 + 0x300);
    *(s32*)&work[0xC0] = GetRandom() % 129 + 0x80;
    ((UnkStruct_080993D4*)work)->unk_0E4 = GetRandom() % 256;
    *(u16*)&work[0xD0] = 0x80;
    *(u16*)&work[0xD2] = 0x80;
    *(u16*)&work[0xE2] = 0x80;
    work[0xE8] = 0;
    work[0xE9] = 0;
    p = &work[0x4C];
    func_080122AC(p, 5, 8, 10);
    func_08012614(p, 1);
    func_08012324(p, *(s32*)&work[0xA8], *(s32*)&work[0xAC], *(s32*)&work[0xB0]);
    work[0xEA] = 0;
    work[0xED] = 0;
    work[0xEB] = 0;
    work[0xEC] = 0;
    work[0xEE] = 0;
    work[0xEF] = 0;
    m4aSongNumStart(0x22B);
    TaskPoolInit((TaskPool*)&work[0x20], 10);
    gBtlWork->unk_0B0++;
}
u8 PrizeBoss_1(u8* work, void* a) {
    s16 x;
    s16 y;
    if (*(s32*)&work[0xB0] < 0) {
        *(s32*)&work[0xB0] += 51;
        func_08099CDC(work);
    }
    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(&work[0x4C], 30);
    } else {
        ColliderSetRadius(&work[0x4C], 10);
    }
    func_08012324(&work[0x4C], *(s32*)&work[0xA8], *(s32*)&work[0xAC],
                  *(s32*)&work[0xB0]);
    WorldToScreen((s16*)&work[0xD6], (s16*)&work[0xD8], *(s32*)&work[0xA8],
                  *(s32*)&work[0xAC], *(s32*)&work[0xB0]);
    WorldToScreen((s16*)&work[0xDE], (s16*)&work[0xE0], *(s32*)&work[0xA8],
                  *(s32*)&work[0xAC], *(s32*)&work[0xB4]);
    ((UnkStruct_08099928*)work)->unk_D4 = -0x1004 - (*(s32*)&work[0xAC] >> 8) * 4;
    func_08099928((UnkStruct_08099928*)work);
    work[0xE9] += 2;
    if (work[0xEA] == 60) {
        func_08012614(&work[0x4C], 0);
    }
    if (work[0xEA] <= 59) {
        work[0xEA]++;
    }
    if (work[0x78] != 0) {
        work[0xED] = 1;
        m4aSongNumStart(106);
        func_08084458(*(u16*)&work[0xB8]);
        if (gGameState.flags & 8) {
            _08085D04(gGameState.unk_00C[0]);
        }
        SetTaskUpdate(a, (void*)func_08099A18);
        WorldToScreen(&x, &y, *(s32*)&work[0xA8], *(s32*)&work[0xAC],
                      *(s32*)&work[0xB0]);
        *(s32*)&work[0xA8] = x << 8;
        *(s32*)&work[0xAC] = y << 8;
        func_08012614(&work[0x4C], 1);
        work[0xEB] = 16;
        ((UnkStruct_08099928*)work)->unk_D4 = 50;
        func_080999A4(work);
    }
    TaskPoolUpdate(&work[0x20]);
    return 1;
}

void PrizeBoss_2(u8* work) {
    u16 pal;
    s32 affine;
    void* gfx;
    CardBack* back;
    CardDef* def;
    s16 v;

    pal = work[0xED] == 0 ? func_0801AF1C(*(s32*)&work[0xAC]) : 0;
    affine = AllocObjAffine(work[0xE6], *(s16*)&work[0xD0], *(s16*)&work[0xD2], 1);
    def = &gCardDefs[*(s32*)&work[0xB8]];
    DrawSprite(*(s16*)&work[0xD6], *(u16*)&work[0xD8] - 8, def->unk_00,
               *(void**)&work[0x00], *(void**)&work[0x04], affine, pal,
               (u16)(*(u16*)&work[0xD4] + 1));
    back = &gUnk_08F709B0[work[0x42]];
    DrawSprite(*(s16*)&work[0xD6], *(u16*)&work[0xD8] - 8,
               back->unk_00, *(void**)&work[0x08],
               *(void**)&work[0x10], affine, pal, *(u16*)&work[0xD4]);
    gfx = gUnk_09EE981C[work[0x38]];

    if (def->unk_2A != 3) {
        DrawSprite(*(s16*)&work[0xD6], *(u16*)&work[0xD8] - 8, gfx,
                   *(void**)&work[0x14], *(void**)&work[0x10], affine, pal,
                   (u16)(*(u16*)&work[0xD4] - 1));
    }

    if (work[0xED] == 0) {
        v = 204 - ((*(s32*)&work[0xB4] - *(s32*)&work[0xB0]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(*(s16*)&work[0xDE], *(s16*)&work[0xE0], gUnk_09EE1380[0],
                   *(void**)&work[0x18], *(void**)&work[0x1C],
                   AllocObjAffine(0, v, v, 0), pal,
                   (u16)(*(u16*)&work[0xD4] + 2));
    }

    TaskPoolDraw(&work[0x20]);
}

void PrizeBoss_3(u8* work) {
    func_080062F4((*(UnkStruct_080038C8**)&work[0x10])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x04])->unk_06 + 16, 0);
    func_08012304(&work[0x4C]);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjTiles(*(void**)&work[0x0C]);
    ReleaseObjTiles(*(void**)&work[0x18]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjPalette(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x1C]);
    TaskPoolDestroy(&work[0x20]);
    gBtlWork->unk_0B0--;
}

void func_08099928(UnkStruct_08099928* w) {
    w->unk_D0 = (-gSineTable[((w->unk_E9 + 0x80) & 0xFF) + 0x40] * w->unk_E2) >> 8;
    w->unk_D2 = (-gSineTable[((w->unk_E8 + 0x80) & 0xFF) + 0x40] * w->unk_E2) >> 8;

    if ((u16)(w->unk_D0 + 2) <= 4) {
        w->unk_D0 = 2;
    }

    if ((u16)(w->unk_D2 + 2) <= 4) {
        w->unk_D2 = 2;
    }
}

void func_080999A4(u8* work) {
    s16 x;
    s16 y;
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    WorldToScreen(&x, &y, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    tx = 0x7800;
    ty = 0x5000;
    dx = tx - *(s32*)&work[0xA8];
    dy = ty - *(s32*)&work[0xAC];
    *(s32*)&work[0xCC] = func_0805F5A4(&dx, &dy);
    *(s32*)&work[0xC4] = -dx;
    *(s32*)&work[0xC8] = -dy;
    *(s32*)&work[0xC0] = 0x300;
    *(s32*)&work[0xBC] = 2;
}

#ifndef VERSION_EU
u8 func_08099A18(u8* work, void* a) {
    s32 dx;
    s32 dy;
    u8 z;
    u8 t;
    s32 x;
    s32 y;
    s16* q1;
    s16* q2;

    if (*(s32*)&work[0xC0] < 0) {
        dx = 0x7800 - *(s32*)&work[0xA8];
        dy = 0x5000 - *(s32*)&work[0xAC];
        func_0805F5A4(&dx, &dy);
        *(s32*)&work[0xC4] = -dx;
        *(s32*)&work[0xC8] = -dy;

        if (*(s32*)&work[0xCC] <= 0x7FF) {
            work[0xEB] = 0;
            work[0xE6] = 0;
            SetTaskUpdate(a, (void*)func_08099B60);
            func_08096F08(&work[0x20], gCardDefs[*(s32*)&work[0xB8]].unk_0C);
        }
    }

    *(s32*)&work[0xA8] += (*(s32*)&work[0xC4] * *(s32*)&work[0xC0]) >> 8;
    *(s32*)&work[0xAC] += (*(s32*)&work[0xC8] * *(s32*)&work[0xC0]) >> 8;
    t = work[0xE6] + 32;
    z = 0;
    work[0xE6] = t;
    work[0xE8] += (64 - work[0xE8]) >> 4;
    work[0xE9] = z;
    *(s32*)&work[0xCC] = func_0805F588(0x7800 - *(s32*)&work[0xA8], 0x5000 - *(s32*)&work[0xAC]);
    *(s32*)&work[0xC0] -= *(s32*)&work[0xBC];
    *(s32*)&work[0xBC] += 2;

    if (*(s16*)&work[0xE2] <= 0xFF) {
        *(s16*)&work[0xE2] += 3;
    }

    x = *(s32*)&work[0xA8] >> 8;
    q1 = (s16*)&work[0xD6];
    *q1 = x;
    y = *(s32*)&work[0xAC] >> 8;
    q2 = (s16*)&work[0xD8];
    *q2 = y;
    func_08099928((UnkStruct_08099928*)work);
    TaskPoolUpdate(&work[0x20]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08099A18.s");
#endif

u8 func_08099B60(u8* work, void* a) {
    s32 v;
    u16 t;
    s32 c;

    v = work[0xE6] << 8;
    ApproachValue(&work[0xE8], 0, work[0xEB]);
    ApproachValue(&v, 0, work[0xEB]);
    ApproachValue(&work[0xA8], 0x7800, work[0xEB]);
    ApproachValue(&work[0xAC], 0x5800, work[0xEB]);
    work[0xE6] = v >> 8;

    if (work[0xEB] != 0) {
        work[0xEB]--;
    }

    t = *(u16*)&work[0xE2];

    if ((s16)t <= 0xFF) {
        *(u16*)&work[0xE2] = t + 2;
    } else {
        c = 0x100;
        *(u16*)&work[0xE2] = c;
    }

    ((UnkStruct_08099928*)work)->unk_D6 = *(s32*)&work[0xA8] >> 8;
    ((UnkStruct_08099928*)work)->unk_D8 = *(s32*)&work[0xAC] >> 8;
    func_08099928((UnkStruct_08099928*)work);
    work[0xEC]++;

    if (*(u32*)&work[0xB8] > 0x1C2) {
        if (work[0xEC] == 120) {
            work[0xEC] = 0;
            SetTaskUpdate(a, (void*)func_08099C4C);
        }
    } else {
        if (work[0xEC] == 30) {
            work[0xEC] = 0;
            SetTaskUpdate(a, (void*)func_08099C4C);
        }
    }

    TaskPoolUpdate(&work[0x20]);
    return 1;
}

u8 func_08099C4C(u8* work) {
    work[0xE6] += 32;
    WorldToScreen((s16*)&work[0xDA], (s16*)&work[0xDC], ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    *(s16*)&work[0xD6] += (*(s16*)&work[0xDA] - *(s16*)&work[0xD6]) >> 3;
    *(s16*)&work[0xD8] += (*(s16*)&work[0xDC] - *(s16*)&work[0xD8]) >> 3;
    *(s16*)&work[0xD0] -= 10;
    *(s16*)&work[0xD2] -= 10;

    if (*(s16*)&work[0xD0] <= 10) {
        return 0;
    }

    TaskPoolUpdate(&work[0x20]);
    return 1;
}

void func_08099CDC(u8* work) {
    UnkStruct_08099CDC_Args args;

    if (work[0xED] == 0) {
        if (work[0xEF] == 8) {
            if (work[0xEE] <= 3) {
                args.unk_00 = *(s32*)&work[0xA8];
                args.unk_04 = *(s32*)&work[0xAC];
                args.unk_08 = *(s32*)&work[0xB0];
                args.unk_0C = work[0xED];
                args.unk_10 = &work[0xEE];
                TaskCreate(&work[0x20], gTaskDescCardEFFECT, &args);
            }

            work[0xEF] = 0;
        } else {
            work[0xEF]++;
        }
    } else {
        if (work[0xEF] == 8) {
            if (work[0xEE] <= 7) {
                args.unk_00 = *(s32*)&work[0xA8];
                args.unk_04 = *(s32*)&work[0xAC];
                args.unk_08 = *(s32*)&work[0xB0];
                args.unk_0C = work[0xED];
                args.unk_10 = &work[0xEE];
                TaskCreate(&work[0x20], gTaskDescCardEFFECT, &args);
            }

            work[0xEF] = 0;
        } else {
            work[0xEF]++;
        }
    }
}

void Card_EFFECT_0(UnkStruct_08099E70* w, UnkStruct_08099CDC_Args* a) {
    *(UnkStruct_08099CDC_Args*)&w->unk_38 = *a;

    if (w->unk_44 == 0) {
        w->unk_24 = a->unk_00 + ((GetRandom() % 9 - 4) << 8);
        w->unk_28 = a->unk_04;
        w->unk_2C = a->unk_08 - 0x800;
    } else {
        w->unk_24 = a->unk_00 + ((GetRandom() % 33 - 16) << 8);
        w->unk_28 = a->unk_04 - 0x1000;
        w->unk_2C = 0;
    }

    w->unk_00 = AllocObjTiles(0x80, 0);
    w->unk_04 = LoadObjPalette(gUnk_09619158, 32);
    func_08002A10(w->unk_00, gUnk_093F762E);
    AnimInit(&w->unk_08, gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&w->unk_08, GetRandom() % 3, 0);
    w->unk_20 = AnimGetGfx(&w->unk_08);
    (*w->unk_48)++;
}

u8 Card_EFFECT_1(UnkStruct_08099E70* w) {
    w->unk_20 = AnimUpdate(&w->unk_08);

    if (w->unk_44 == 0) {
        WorldToScreen(&w->unk_30, &w->unk_32, w->unk_24, w->unk_28, w->unk_2C);
        w->unk_2C -= 0x100;
    } else {
        w->unk_30 = w->unk_24 >> 8;
        w->unk_32 = w->unk_28 >> 8;
        w->unk_28 -= 0x100;
    }

    if (AnimIsFinished(&w->unk_08)) {
        return 0;
    }

    return 1;
}

void Card_EFFECT_2(u8* work) {
    s16 t;
    s32 z;

    t = -4100 - ((*(s16*)&work[0x32] >> 8) * 4);
    z = 0;
    *(u16*)&work[0x34] = t;
    DrawSprite(*(s16*)&work[0x30], *(s16*)&work[0x32], *(void**)&work[0x20],
               *(void**)&work[0x00], *(void**)&work[0x04], z, z,
               *(u16*)&work[0x34]);
}

void Card_EFFECT_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    (*(u8**)&work[0x48])[0]--;
}

void scrollbar_0(ScrollBarWork* w, u16* args) {
    w->unk_08 = args[0];
    w->unk_0A = args[1];
    w->unk_0C = args[2];
    w->unk_10 = args[3];
    w->unk_12 = args[4];
    w->unk_16 = 1;
    w->unk_0E = 0;
    w->unk_17 = 0;
}

u8 scrollbar_1(u8* p) {
    return p[22];
}
void scrollbar_2(void) {
}
void scrollbar_3(void) {
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
    return (s32)((void**)TaskCreate(pool, gTaskDescScrollbar, args))[1];
}

void func_0809A02C(u8* work, s32* args) {
    u8* p;

    *(s32*)&work[0x1A0] = args[3];
    *(s32*)&work[0x38] = args[0];
    *(s32*)&work[0x3C] = args[1];
    *(s32*)&work[0x40] = args[2];
    *(s32*)&work[0x44] = 0;
    work[0x1C6] = GetRandom();
    *(s32*)&work[0x1A4] = -(GetRandom() % 129 + 0x300);
    *(s32*)&work[0x1A8] = GetRandom() % 129 + 0x80;
    work[0x1C7] = 0;
    work[0x1C8] = 0;
    work[0x1C9] = 24;
    ((UnkStruct_0809A02C*)work)->unk_1B8 = 0x80;
    *(u16*)&work[0x1BA] = 0x80;
    *(u16*)&work[0x1BC] = 0x80;
    work[0x1CA] = 0;
    work[0x1CB] = 0;
    work[0x1CC] = 0;
    *(u16*)&work[0x1C4] = 0;
    work[0x1CD] = 1;
    *(CardDef**)&work[0x1C] = &gCardDefs[args[3]];

    if ((*(CardDef**)&work[0x1C])->unk_1E & 8) {
        ((UnkStruct_0809A02C*)work)->unk_1CE = 3;
    } else {
        ((UnkStruct_0809A02C*)work)->unk_1CE = (*(CardDef**)&work[0x1C])->unk_2A;
    }

    *(void**)&work[4] = LoadObjPalette(gUnk_09611AB8, 32);
    *(void**)&work[0x10] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    *(void**)&work[8] = LoadObjTiles((*(CardDef**)&work[0x1C])->unk_04, 0x300);
    *(void**)&work[0xC] = LoadObjPalette((*(CardDef**)&work[0x1C])->unk_08, 32);
    *(void**)&work[0x14] = LoadObjTiles(gUnk_08B22BBC, 0x100);
    *(void**)&work[0x18] = LoadObjPalette(gUnk_08F69BA4, 32);
    p = &work[0x144];
    func_080122AC(p, 5, 8, 10);
    func_08012324(p, *(s32*)&work[0x38], *(s32*)&work[0x3C], *(s32*)&work[0x40]);
    TaskPoolInit(&work[32], 1);
    gBtlWork->unk_0B0++;
}

void func_0809A1B8(u8* work, s32* args) {
    u8* p;

    *(s32*)&work[0x1A0] = args[3];
    *(s32*)&work[0x38] = args[0];
    *(s32*)&work[0x3C] = args[1];
    *(s32*)&work[0x40] = args[2];
    *(s32*)&work[0x44] = 0;
    work[0x1C6] = GetRandom();
    *(s32*)&work[0x1A4] = -(GetRandom() % 129 + 0x300);
    *(s32*)&work[0x1A8] = GetRandom() % 129 + 0x80;
    work[0x1C7] = 0;
    work[0x1C8] = 0;
    work[0x1C9] = 24;
    ((UnkStruct_0809A02C*)work)->unk_1B8 = 0x80;
    *(u16*)&work[0x1BA] = 0x80;
    *(u16*)&work[0x1BC] = 0x80;
    work[0x1CA] = 0;
    work[0x1CB] = 0;
    work[0x1CC] = 0;
    *(u16*)&work[0x1C4] = 0;
    work[0x1CD] = 1;
    *(CardDef**)&work[0x1C] = &gCardDefs[args[3]];

    if ((*(CardDef**)&work[0x1C])->unk_1E & 8) {
        ((UnkStruct_0809A02C*)work)->unk_1CE = 3;
    } else {
        ((UnkStruct_0809A02C*)work)->unk_1CE = (*(CardDef**)&work[0x1C])->unk_2A;
    }

    *(void**)&work[0] = LoadObjTiles(gUnk_08F709B0[((UnkStruct_0809A02C*)work)->unk_1CE].unk_0C, 0x280);
    *(void**)&work[4] = LoadObjPalette(gUnk_09611AB8, 32);
    *(void**)&work[0x10] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    *(void**)&work[8] = LoadObjTiles((*(CardDef**)&work[0x1C])->unk_04, 0x300);
    *(void**)&work[0xC] = LoadObjPalette((*(CardDef**)&work[0x1C])->unk_08, 32);
    *(void**)&work[0x14] = LoadObjTiles(gUnk_08B22BBC, 0x100);
    *(void**)&work[0x18] = LoadObjPalette(gUnk_08F69BA4, 32);
    p = &work[0x144];
    func_080122AC(p, 5, 8, 10);
    func_08012324(p, *(s32*)&work[0x38], *(s32*)&work[0x3C], *(s32*)&work[0x40]);
    TaskPoolInit(&work[32], 1);
    gBtlWork->unk_0B0++;
}


INCLUDE_ASM("card/func_0809A368.s");

void func_0809A4E0(u8* work, u8 kind) {
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    if (kind == 1) {
        tx = 0x7800;
        ty = 0x5000;
    } else {
        tx = 0;
        ty = 0xA000;
    }

    dx = tx - *(s32*)&work[0x38];
    dy = ty - *(s32*)&work[0x3C];
    *(s32*)&work[0x1AC] = func_0805F5A4(&dx, &dy);
    *(s32*)&work[0x1B0] = -dx;
    *(s32*)&work[0x1B4] = -dy;
    *(s32*)&work[0x1A8] = 0x300;
    *(s32*)&work[0x1A4] = 2;
}

INCLUDE_ASM("card/func_0809A54C.s");
INCLUDE_ASM("card/func_0809A840.s");
u8 func_0809AB2C(u8* work) {
    s32 dx;
    s32 dy;
    u16 t;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    if (*(s32*)&work[0x1A8] < 0) {
        dx = -*(s32*)&work[0x38];
        dy = 0xA000 - *(s32*)&work[0x3C];
        func_0805F5A4(&dx, &dy);
        *(s32*)&work[0x1B0] = -dx;
        *(s32*)&work[0x1B4] = -dy;

        if (*(s32*)&work[0x1AC] < 0x800) {
            if (*(s32*)&work[0x1A0] >= 655 && *(s32*)&work[0x1A0] <= 659) {
                gUnk_02039DD4->unk_0BC = *(s32*)&work[0x1A0];
            } else {
                gUnk_02039DD4->unk_0B8 = *(s32*)&work[0x1A0];
            }

            return 0;
        }
    }

    *(s32*)&work[0x38] += (*(s32*)&work[0x1B0] * *(s32*)&work[0x1A8]) >> 8;
    *(s32*)&work[0x3C] += (*(s32*)&work[0x1B4] * *(s32*)&work[0x1A8]) >> 8;
    ((UnkStruct_0809A02C*)work)->unk_1C9 += 32;
    ((UnkStruct_0809A02C*)work)->unk_1C8 += (64 - ((UnkStruct_0809A02C*)work)->unk_1C8) >> 4;
    ((UnkStruct_0809A02C*)work)->unk_1C7 = 0;
    *(s32*)&work[0x1AC] = func_0805F588(-*(s32*)&work[0x38], 0xA000 - *(s32*)&work[0x3C]);
    *(s32*)&work[0x1A8] -= *(s32*)&work[0x1A4];
    *(s32*)&work[0x1A4] += 2;
    t = ((UnkStruct_0809A02C*)work)->unk_1BC;

    if ((s16)t <= 255) {
        ((UnkStruct_0809A02C*)work)->unk_1BC = t + 3;
    }

    ((UnkStruct_0809A02C*)work)->unk_1B8 = (-gSineTable[((((UnkStruct_0809A02C*)work)->unk_1C7 + 128) & 0xFF) + 64] * ((UnkStruct_0809A02C*)work)->unk_1BC) >> 8;
    ((UnkStruct_0809A02C*)work)->unk_1BA = (-gSineTable[((((UnkStruct_0809A02C*)work)->unk_1C8 + 128) & 0xFF) + 64] * ((UnkStruct_0809A02C*)work)->unk_1BC) >> 8;

    if ((u16)(((UnkStruct_0809A02C*)work)->unk_1B8 + 2) <= 4) {
        ((UnkStruct_0809A02C*)work)->unk_1B8 = 2;
    }

    if ((u16)(((UnkStruct_0809A02C*)work)->unk_1BA + 2) <= 4) {
        ((UnkStruct_0809A02C*)work)->unk_1BA = 2;
    }

    TaskPoolUpdate((TaskPool*)&work[32]);
    return 1;
}

u8 func_0809ACDC(u8* work) {
    s16 x;
    s16 y;

    work[0x1C9] += 32;
    WorldToScreen(&x, &y, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    *(s32*)&work[0x38] += ((x << 8) - *(s32*)&work[0x38]) >> 3;
    *(s32*)&work[0x3C] += ((y << 8) - *(s32*)&work[0x3C]) >> 3;
    *(s16*)&work[0x1B8] -= 10;
    *(s16*)&work[0x1BA] -= 10;

    if (*(s16*)&work[0x1B8] <= 10) {
        return 0;
    }

    return 1;
}

s32 func_0809AD60(u8* work, void* a) {
    *(u16*)&work[0x1C4] += 1;

    if (*(u16*)&work[0x1C4] == 60) {
        SetTaskUpdate(a, func_0809ACDC);
    }

    TaskPoolUpdate(&work[0x20]);
    return 1;
}
INCLUDE_ASM("card/func_0809AD98.s");
INCLUDE_ASM("card/func_0809AF84.s");
INCLUDE_ASM("card/func_0809B200.s");
void func_0809B3F4(u8* work) {
    s16 x;
    s16 y;
    s32 affine;
    s16 v;

    if (work[0x1CD] != 0) {
        if (work[0x1CA] == 0) {
            *(u16*)&work[0x1D0] = func_0801AF1C(*(s32*)&work[0x3C]);
            WorldToScreen(&x, &y, *(s32*)&work[0x38], *(s32*)&work[0x3C],
                          *(s32*)&work[0x40]);
        } else {
            *(u16*)&work[0x1D0] = 0;
            x = *(s32*)&work[0x38] >> 8;
            y = *(s32*)&work[0x3C] >> 8;
        }

        affine = AllocObjAffine(work[0x1C9], *(s16*)&work[0x1B8],
                                *(s16*)&work[0x1BA], 0);
        DrawSprite(x, (u16)y - 8,
                   gUnk_08F709B0[(*(CardDef**)&work[0x1C])->unk_2A].unk_00,
                   *(void**)&work[0x00], *(void**)&work[0x04], affine,
                   *(u16*)&work[0x1D0], *(u16*)&work[0x1C2]);
        DrawSprite(x, (u16)y - 8, (*(CardDef**)&work[0x1C])->unk_00,
                   *(void**)&work[0x08], *(void**)&work[0x0C], affine,
                   *(u16*)&work[0x1D0], (u16)(*(u16*)&work[0x1C2] + 1));
        v = 204 - ((*(s32*)&work[0x44] - *(s32*)&work[0x40]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        if (work[0x1CA] == 0) {
            WorldToScreen((s16*)&work[0x1BE], (s16*)&work[0x1C0],
                          *(s32*)&work[0x38], *(s32*)&work[0x3C],
                          *(s32*)&work[0x44]);
            DrawSprite(*(s16*)&work[0x1BE], *(s16*)&work[0x1C0],
                       gUnk_09EE1380[0], *(void**)&work[0x14],
                       *(void**)&work[0x18], AllocObjAffine(0, v, v, 0),
                       *(u16*)&work[0x1D0], (u16)(*(u16*)&work[0x1C2] + 2));
        }

        TaskPoolDraw(&work[0x20]);
    }
}

void func_0809B59C(u8* work) {
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjPalette(*(void**)&work[0x18]);
    func_08012304(&work[0x144]);
    TaskPoolDestroy(&work[0x20]);
    gUnk_02039DD4->unk_0D6 = 0;
    gBtlWork->unk_0B0--;
}

void func_0809B5F4(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjPalette(*(void**)&work[0x18]);
    func_08012304(&work[0x144]);
    TaskPoolDestroy(&work[0x20]);
    gBtlWork->unk_0B0--;
}

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

void func_0809B710(void* pool, u16 a, u16 b, u16 c, u16 d) {
    s32 args[4];

    if (gUnk_02039DD4 != 0 && gUnk_02039DD4->unk_0DC == 0) {
        gUnk_02039DD4->unk_0DC++;
        args[0] = (s16)a << 8;
        args[1] = (s16)b << 8;
        args[2] = (s16)c << 8;
        args[3] = d;
        TaskCreate(pool, gUnk_09EE77BC, args);
    }
}

#ifndef VERSION_EU
void func_0809B76C(u8* work, void** src) {
    u8 i;
    void** dst;
    void** q;
    void** s;
    s32 z;
    UnkStruct_080038C8* obj;

    if (src != 0) {
        s = src;

        for (i = 0; i < 6; i++) {
            dst = (void**)&work[0x18];
            q = &dst[i];
            *q = s[i];
        }

        work[0x30] = 1;
    } else {
        work[0x30] = 0;
    }

    z = 0;
    work[0x11] = z;
    *(u16*)&work[4] = z;
    obj = func_080038C8(0x3C0);
    *(UnkStruct_080038C8**)&work[8] = obj;

    if (work[0x30] == 0) {
        func_080038E4(obj, gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_04[gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_0A], gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_00);
    } else {
        func_080038E4(obj, gUnk_08F7CF18[*(u32*)&work[0x18]].unk_04[gUnk_08F7CF18[*(u32*)&work[0x18]].unk_0A], gUnk_08F7CF18[*(u32*)&work[0x18]].unk_00);
    }

    *(void**)&work[0xC] = LoadObjPalette(gUnk_08F69BA4, 32);
    work[0x31] = 1;
    *(u32*)&work[0x14] = gUnk_02039DD4->unk_0C4;
}
#else
INCLUDE_ASM("card/func_0809B76C.s");
#endif

#ifndef VERSION_EU
u8 func_0809B840(u8* work) {
    u8* tbl;
    s32 ofs;

    if (gUnk_02039DD4->unk_0E3 == 0 || gUnk_02039DD4->unk_0C4 != *(u32*)&work[0x14]) {
        return 0;
    }

    if ((gFrameCounter >> 5) & 1) {
        work[0x31] = 1;
    } else {
        work[0x31] = 0;
    }

    if (work[0x30] == 1 && work[0x31] != 0) {
        work[0x11]++;
        ofs = work[0x11] * 4;
        tbl = &work[0x18];

        if (*(s32*)(tbl + ofs) == -1) {
            work[0x11] = 0;
        }

        func_080038E4(*(UnkStruct_080038C8**)&work[8], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_04[gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_0A], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_00);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809B840.s");
#endif

#ifndef VERSION_EU
void func_0809B8F0(u8* work) {
    if (work[0x31] != 0) {
        DrawSprite(64, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0, 10);
    }
}
#else
INCLUDE_ASM("card/func_0809B8F0.s");
#endif
#ifndef VERSION_EU
void func_0809B920(u8* work, void** src) {
    u8 i;
    void** dst;
    void** q;
    void** s;
    s32 z;
    UnkStruct_080038C8* obj;

    if (src != 0) {
        s = src;

        for (i = 0; i < 6; i++) {
            dst = (void**)&work[0x18];
            q = &dst[i];
            *q = s[i];
        }

        work[0x30] = 1;
    } else {
        work[0x30] = 0;
    }

    z = 0;
    work[0x11] = z;
    *(u16*)&work[4] = z;
    obj = func_080038C8(0x3C0);
    *(UnkStruct_080038C8**)&work[8] = obj;

    if (work[0x30] == 0) {
        func_080038E4(obj, gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_04[gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_0A], gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_00);
    } else {
        func_080038E4(obj, gUnk_08F7CF18[*(u32*)&work[0x18]].unk_04[gUnk_08F7CF18[*(u32*)&work[0x18]].unk_0A], gUnk_08F7CF18[*(u32*)&work[0x18]].unk_00);
    }

    *(void**)&work[0xC] = LoadObjPalette(gUnk_08F69BA4, 32);
    work[0x31] = 1;
    *(u32*)&work[0x14] = gUnk_02039DD4->unk_0C6;
}
#else
INCLUDE_ASM("card/func_0809B920.s");
#endif

#ifndef VERSION_EU
u8 func_0809B9F4(u8* work) {
    u8* tbl;
    s32 ofs;

    if (gUnk_02039DD4->unk_0E4 == 0 || gUnk_02039DD4->unk_0C6 != *(u32*)&work[0x14]) {
        return 0;
    }

    if ((gFrameCounter >> 5) & 1) {
        work[0x31] = 0;
    } else {
        work[0x31] = 1;
    }

    if (work[0x30] == 1 && work[0x31] != 0) {
        work[0x11]++;
        ofs = work[0x11] * 4;
        tbl = &work[0x18];

        if (*(s32*)(tbl + ofs) == -1) {
            work[0x11] = 0;
        }

        func_080038E4(*(UnkStruct_080038C8**)&work[8], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_04[gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_0A], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_00);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809B9F4.s");
#endif

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

u8 func_0809C078(u8* work, void* a) {
    s32 v;
    u8* p;
    u8* n;

    n = (u8*)ListPoolFirst(gUnk_0203A9D0);

    if (n != 0 && n[0x55] == 1) {
        SetTaskUpdate(a, (void*)func_0809BE80);
    }

    p = &work[0x8C];

    if (*p != 0) {
        ApproachValue(&work[0x34], 0, *p);
        ApproachValue(&work[0x38], 0x9800, *p);
    } else {
        v = *(s16*)&work[0x30] << 8;
        p = &work[0x8B];
        ApproachValue(&v, 0, *p);
        *(s16*)&work[0x30] = v >> 8;
    }

    (*p)--;
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);
    return 1;
}

#ifndef VERSION_EU
void func_0809C110(u8* work) {
    if (work[0x87] == 0) {
        DrawSprite(62, 50, *(void**)&work[0x28], *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0, 0);
        DrawSprite(53, 64, *(void**)&work[0x2C], *(void**)&work[0x10], *(void**)&work[0x14], 0, 0, 0);
    }

    if (work[0x85] != 0) {
        DrawSprite(88, 70, gUnk_09EE98EC[0], *(void**)&work[0x18], *(void**)&work[0x1C], 0, 0, 0);
    }

    DrawSprite(*(s16*)&work[0x30], 0, gUnk_09EEA16C[0], *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 0);
    DrawSprite(120, *(s32*)&work[0x34] >> 8, gUnk_09EEA174[0], *(void**)&work[0x20], *(void**)&work[0x04], 0, 0, 60);
    DrawSprite(120, *(s32*)&work[0x38] >> 8, gUnk_09EEA174[1], *(void**)&work[0x20], *(void**)&work[0x04], 0, 0, 60);
    TaskPoolDraw(&work[0x3C]);
    TaskPoolDraw(gUnk_0203A9D0 + 0x14);
}
#else
INCLUDE_ASM("card/func_0809C110.s");
#endif

void func_0809C1EC(u8* work) {
    TaskPoolDestroy(gUnk_0203A9D0 + 0x14);
    EwramFree(*(void**)&work[0x24]);
    EwramFree(gUnk_0203A9D0);
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjTiles(*(void**)&work[0x18]);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x20]);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x04])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x14])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x0C])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x1C])->unk_06 + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x14]);
    ReleaseObjPalette(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    func_0800FDD0(0xF5);
    TaskPoolDestroy(&work[0x3C]);
}

void func_0809C294(u8* work) {
    u8 i;

    for (i = 0; i < work[0x50]; i++) {
        (*(u8**)&work[0x24])[i * 12 + 6] = i;
        TaskCreate(&work[0x3C], gUnk_09EE781C, &(*(u8**)&work[0x24])[i * 12]);
    }
}
u8 func_0809C2D0(u8* work, void* a) {
    u8* n;
    u8* pool;
    u8 z;
    u8 t;
    u8* q;

    n = (u8*)ListPoolFirst(gUnk_0203A9D0);
    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    work[0x51] = 0;
    work[0x8A]++;
    work[0x85] = 0;

    if (work[0x86] != 0) {
        while (n != 0) {
            if (n[0x53] == 0) {
                if ((s8)n[0x52] == 3) {
                    n[0x55] = 2;
                    func_08085658(*(u16*)&n[0x48]);
                } else {
                    n[0x55] = 3;
                }

                work[0x86] = 0;
            }

            n = (u8*)ListPoolNext(&n[0x58]);
        }
    }

    t = work[0x8A];
    pool = &work[0x3C];

    if (t == 30) {
        q = &work[0x87];
        z = 0;
        *q = 1;
        SetBgPriority(2, 0);
        func_080065FC(2, 0x8000, 0x80);
        func_08006778(gUnk_09EDA9A8, 120, 60);
        work[0x88] = func_08006BA0(gUnk_09EDA9A8);
        work[0x89] = z;
        gBldCnt = 0x1B44;
        gBldAlpha = 0x1010;
        func_08006954();
        func_080062F4(10, 1);
        func_080062F4(11, 1);
        func_080062F4(12, 1);
        func_080062F4(13, 1);
        func_080062F4(14, 1);
        func_080062F4(15, 1);
        TaskCreate(pool, gUnk_09EE7834, 0);
        SetTaskUpdate(a, (void*)func_0809C448);
    }

    TaskPoolUpdate(pool);
    TaskPoolUpdate(&gUnk_0203A9D0[0x14]);
    return 1;
}

#ifndef VERSION_EU
u8 func_0809C448(u8* work, void* a) {
    ListPoolFirst(gUnk_0203A9D0);
    func_08006954();
    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);

    if (GetKeysPressed() & 1) {
        work[0x8B] = 16;
        work[0x8C] = 16;
        SetTaskUpdate(a, (void*)func_0809C4B0);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809C448.s");
#endif

u8 func_0809C4B0(u8* work, void* a) {
    s32 v;
    u8* p;

    p = &work[0x8B];

    if (*p != 0) {
        v = *(s16*)&work[0x30] << 8;
        ApproachValue(&v, -0x8000, *p);
        *(s16*)&work[0x30] = v >> 8;
    } else {
        p = &work[0x8C];

        if (*p == 0) {
            return 0;
        }

        ApproachValue(&work[0x34], -0x800, *p);
        ApproachValue(&work[0x38], 0xA000, *p);
    }

    (*p)--;
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);
    return 1;
}

void func_0809C534(UnkStruct_0809C534* w, UnkStruct_0809C534_Args* a) {
    CardDef* def;

    w->unk_54 = 0;
    w->unk_18 = 0;

    if (a->unk_06 <= 8) {
        w->unk_4E = gUnk_09036278[a->unk_06];
    } else {
        w->unk_4E = 0xFFE0;
    }

    w->unk_52 = a->unk_06;
    w->unk_48 = a->unk_04;
    def = &gCardDefs[a->unk_00];
    w->unk_00 = def;

    if (def->unk_1E & 0xC) {
        w->unk_04 = &gUnk_08F709B0[1];
    } else {
        w->unk_04 = &gUnk_08F709B0[def->unk_2A];
    }

    w->unk_50 = 0;
    func_0809C9A4((UnkStruct_0809C9A4*)w);
    func_08000D20(w->unk_58, gUnk_0203A9D0, w);
    func_08000D28(w->unk_58, gUnk_0203A9D0);
    w->unk_55 = 0;
    w->unk_6C = 0x100;
    w->unk_6E = 0x100;
    w->unk_70 = 0;
    w->unk_72 = 0;
    w->unk_53 = 32;
    w->unk_74 = 0;
}
u8 func_0809C620(u8* work, void* a) {
    s32 v;
    u8 (*fn)(u8*, void*);
    u16 lim;

    v = *(s16*)&work[0x4E] << 8;

    if (*(s8*)&work[0x52] <= 8) {
        ApproachValue(&v, gUnk_09036278[*(s8*)&work[0x52]] << 8, work[0x53]);
        *(s16*)&work[0x4E] = v >> 8;
    } else {
        lim = 0xFFE0;
        *(u16*)&work[0x4E] = lim;
    }

    if (work[0x53] != 0) {
        work[0x53]--;
    }

    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if (func_0809C9F4((UnkStruct_0809C9A4*)work)) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    if ((s8)work[0x52] == 3) {
        *(u8**)&gUnk_0203A9D0[0x10] = work;
    }

    switch (work[0x55]) {
    case 2:
        gUnk_0203A9D0[0x29] = 0;
        work[0x53] = 8;
        fn = func_0809CB0C;
        SetTaskUpdate(a, fn);
        return fn(work, a);
    case 3:
        work[0x53] = 10;
        SetTaskUpdate(a, func_0809CBF8);
        break;
    }

    return 1;
}

u8 func_0809C710(u8* work, void* a) {
    s32 v;

    v = *(s16*)&work[0x50] << 8;
    ApproachValue(&v, 0x6800, work[0x53]);
    *(s16*)&work[0x50] = v >> 8;
    work[0x53]--;
    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if ((s8)work[0x52] <= 8) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    if (work[0x53] == 0) {
        work[0x55] = 1;
        SetTaskUpdate(a, (void*)func_0809C620);
    }

    return 1;
}

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

u8 func_0809C9F4(UnkStruct_0809C9A4* p) {
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

u8 func_0809CB0C(u8* work, void* a) {
    s32 x;
    s32 y;

    x = *(s16*)&work[0x4A] << 8;
    y = *(s16*)&work[0x4C] << 8;
    ApproachValue(&x, 0x7800, work[0x53]);
    ApproachValue(&y, 0x4600, work[0x53]);
    *(s16*)&work[0x4A] = x >> 8;
    *(s16*)&work[0x4C] = y >> 8;
    work[0x53]--;

    if (work[0x53] == 0) {
        SetTaskUpdate(a, (void*)func_0809CB78);
    }

    return 1;
}

u8 func_0809CB78(u8* work, void* a) {
    *(void**)&work[0x18] = AllocObjTiles(640, 0);
    func_08002A10(*(void**)&work[0x18], gUnk_0908B1B4);
    AnimInit(&work[0x2C], gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&work[0x2C], 0, 1);
    *(void**)&work[0x44] = AnimGetGfx(&work[0x2C]);
    SetTaskUpdate(a, (void*)func_0809CBD0);
    return 1;
}

s32 func_0809CBD0(u8* work) {
    *(void**)&work[0x44] = AnimUpdate(&work[0x2C]);

    if (*(u16*)&work[0x36] == 0 && *(u16*)&work[0x3A] == 4) {
        work[0x74] = 1;
    }

    return 1;
}

u8 func_0809CBF8(u8* work, void* a) {
    s32 v;

    v = *(s16*)&work[0x4E] << 8;

    if ((s8)work[0x52] <= 2) {
        ApproachValue(&v, -0x2000, work[0x53]);
    }

    if (work[0x52] >= 4 && work[0x52] <= 7) {
        ApproachValue(&v, 0x4400, work[0x53]);
    }

    *(s16*)&work[0x4E] = v >> 8;

    if (work[0x53] != 0) {
        work[0x53]--;
    }

    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if (func_0809C9F4((UnkStruct_0809C9A4*)work)) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    return 1;
}

#ifdef VERSION_US
void CardName_0(u8* work) {
    u8* q = *(u8**)&gUnk_0203A9D0[0x10];
    UnkStruct_080038C8* pal;
    s32 v;
    s16 t;

    func_08065ACC((TextSlot*)&work[0x08], 32);
    func_08065ACC((TextSlot*)&work[0x108], 32);
    func_08065ACC((TextSlot*)&work[0x208], 2);
    *(void**)&work[0x218] = _08066468(1);
    work[0x226] = func_08065B6C(*(u16**)(*(u8**)q + 12), (TextSlot*)&work[0x08]);
    work[0x227] = func_08065B6C((u16*)&gUnk_09036278[22], (TextSlot*)&work[0x108]);
    *(void**)&work[0x21C] = LoadObjPalette(gUnk_09614798, 32);
    v = (230 - func_08065B08((TextSlot*)&work[0x08], work[0x226])) / 2;
    *(s16*)&work[0x220] = v;
    t = *(u16*)&work[0x220] + func_08065B08((TextSlot*)&work[0x08], work[0x226]);
    *(s16*)&work[0x224] = t;
    v = (240 - func_08065B08((TextSlot*)&work[0x108], work[0x227])) / 2;
    *(s16*)&work[0x222] = v;
    *(void**)&work[0x00] = LoadObjTiles(&gUnk_093F8C8E[0xC1E], 0x1800);
    pal = LoadObjPalette(gUnk_09611AB8, 32);
    *(void**)&work[0x04] = pal;
    func_080062F4(pal->unk_06 + 16, 1);
    func_080062F4(((UnkStruct_080038C8*)*(void**)&work[0x218])->unk_06 + 16, 1);
}
#else
INCLUDE_ASM("card/CardName_0.s");
#endif
s32 CardName_1(void) {
    return 1;
}
#ifdef VERSION_US
void CardName_2(u8* work) {
    void** p = &gUnk_09EF1278[2];

    DrawSprite(120, 126, *p, *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    func_080664D8(*(s16*)&work[0x220], 115, &work[0x08], *(void**)&work[0x21C], 30, work[0x226]);
    func_080664D8(*(s16*)&work[0x222], 130, &work[0x108], *(void**)&work[0x218], 30, work[0x227]);
}
#else
INCLUDE_ASM("card/CardName_2.s");
#endif
#ifdef VERSION_US
void CardName_3(u8* work) {
    func_08065AE0((TextSlot*)&work[0x08], 32);
    func_08065AE0((TextSlot*)&work[0x108], 32);
    func_08065AE0((TextSlot*)&work[0x208], 2);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x218]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjPalette(*(void**)&work[0x21C]);
}
#else
INCLUDE_ASM("card/CardName_3.s");
#endif

void func_0809CE88(u8* work, s16* a) {
    *(void**)&work[0x00] = AllocObjTiles(128, 0);
    *(void**)&work[0x04] = LoadObjPalette(gUnk_09619158, 32);
    func_08002A10(*(void**)&work[0x00], gUnk_093F762E);
    AnimInit(&work[0x0C], gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&work[0x0C], GetRandom() % 3, 1);
    *(void**)&work[0x08] = AnimGetGfx(&work[0x0C]);
    *(s32*)&work[0x24] = a[1] << 8;
    *(s32*)&work[0x28] = a[2] << 8;
    *(s32*)&work[0x2C] = 0;
    *(s32*)&work[0x40] = a[0] << 8;
    *(s32*)&work[0x3C] = a[3];
    *(s32*)&work[0x4C] = GetRandom() % 0x181 + 0x100;
    *(s32*)&work[0x30] = 0;
    *(s32*)&work[0x34] = 0;
    *(s32*)&work[0x38] = 0;
    *(s32*)&work[0x50] = -(GetRandom() % 0x81 + 0x200);
    gUnk_0203A9D0[0x28]++;
}

void func_0809CF64(u8* work, s16* a) {
    *(void**)&work[0x00] = AllocObjTiles(128, 0);
    *(void**)&work[0x04] = LoadObjPalette(gUnk_09619158, 32);
    func_08002A10(*(void**)&work[0x00], gUnk_093F762E);
    AnimInit(&work[0x0C], gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&work[0x0C], GetRandom() % 3, 1);
    *(void**)&work[0x08] = AnimGetGfx(&work[0x0C]);
    *(s32*)&work[0x24] = a[1] << 8;
    *(s32*)&work[0x28] = a[2] << 8;
    *(s32*)&work[0x2C] = 0;
    *(s32*)&work[0x40] = a[0] << 8;
    *(s32*)&work[0x3C] = a[3];
    *(s32*)&work[0x4C] = GetRandom() % 0x81 + 0x200;
    *(s32*)&work[0x30] = 0;
    *(s32*)&work[0x34] = 0;
    *(s32*)&work[0x38] = 0;
    *(s32*)&work[0x50] = -(GetRandom() % 0x81 + 0x200);
    func_0809D124(work);
    gUnk_0203A9D0[0x28]++;
}

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
s32 Premire_EFFECT2_1(u8* work) {
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

void func_0809D160(u8* work) {
    *(s32*)&work[0x50] += 30;
    *(s32*)&work[0x2C] += *(s32*)&work[0x50];
    *(s32*)&work[0x24] += gSineTable[*(s32*)&work[0x3C] & 0xFF] *
                          (*(s32*)&work[0x4C] >> 8);
    *(s32*)&work[0x28] += -gSineTable[(*(s32*)&work[0x3C] & 0xFF) + 64] *
                          (*(s32*)&work[0x4C] >> 8);
    *(s32*)&work[0x30] = *(s32*)&work[0x24];
    *(s32*)&work[0x34] = *(s32*)&work[0x28] + *(s32*)&work[0x2C];
}

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

void func_0809D1FC(u8 bg) {
    void** p;

    SetBgScroll(bg, 0, 0);
    SetBackdropColor(0, 0, 0);
    LoadBgTiles(bg, gUnk_09036380, 0x1C00);
    LoadBgMap(bg, gUnk_08125E24, 0x800);
    LoadBgPalette(bg, gUnk_09036300, 0x80);
    EnableBg(bg);
    gUnk_02034AD9 = bg;
    p = &gUnk_02034AD4;
    *p = EwramAlloc(0x880);
}

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

void func_0809D2B0(u8 a, u8 b, u8 c, u8* s) {
    u8 n;
    u8 i;

    if (gUnk_02034AD8 < 32) {
        n = func_0809D280(s);

        if (n > 32) {
            n = 32;
        }

        for (i = 0; i < n; i++) {
            ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04[i] = s[i];
            ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04[i] |= c << 12;
        }

        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_01 = a;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_02 = b;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_03 = c;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_00 = n;
        func_0800448C(((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04, (void*)GetBgScreenBase(gUnk_02034AD9), 0, 0,
                      ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_01,
                      ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_02,
                      (s8)((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_00, 1);
        gUnk_02034AD8++;
    }
}

void func_0809D3F0(void) {
    gUnk_02034AD8 = 0;
}

void func_0809D3FC(void) {
    s16 i;

    for (i = 0; i < gUnk_02034AD8; i++) {
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_00 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_01 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_02 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_03 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_04[0] = 0;
    }

    gUnk_02034AD8 = 0;
}

INCLUDE_ASM("card/func_0809D458.s");

void func_0809D87C(u16 a, u16 b, u16 c, u16 bits) {
    u16 v[16];
    u8 s[17];
    u16 i;
    u16 j;

    for (i = 0, j = 15; i < 16; i++, j--) {
        v[i] = bits & (1 << i);
        s[j] = (v[i] >> i) + '0';
    }

    s[16] = 0;
    func_0809D2B0(a, b, c, s);
}

void func_0809D900(u16 a, u16 b, u16 c, u32 v) {
    u8 s[11];
    s32 i;

    s[0] = '0';
    s[1] = 'x';
    s[2] = v >> 28;
    s[3] = (v & 0x0F000000) >> 24;
    s[4] = (v & 0x00F00000) >> 20;
    s[5] = (v & 0x000F0000) >> 16;
    s[6] = (v & 0x0000F000) >> 12;
    s[7] = (v & 0x00000F00) >> 8;
    s[8] = (v & 0x000000F0) >> 4;
    s[9] = v & 0x0000000F;

    for (i = 0; i < 8; i++) {
        s[i + 2] += s[i + 2] <= 9 ? '0' : '7';
    }

    s[10] = 0;
    func_0809D2B0(a, b, c, s);
}

#ifndef VERSION_EU
void Mode_Premire_0(void) {
    func_08085FB0();
    func_08085C3C();
    SetBgMode2();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
    SetBgAffine(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AE0, 1);
    TaskCreate(gUnk_02034AE0, gTaskDescLevelUp, 0);
}
#else
INCLUDE_ASM("card/Mode_Premire_0.s");
#endif

void Mode_Premire_1(void) {
    TaskPoolUpdate(gUnk_02034AE0);
    TaskPoolDraw(gUnk_02034AE0);
}
void Mode_Premire_2(void) {
    TaskPoolDestroy(gUnk_02034AE0);
}
u8 func_0809DA64(s32 a, u16 n) {
    switch (n) {
    case 0:
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
        return 6;
    case 41:
    case 45:
    case 50:
        return 2;
    case 18:
    case 46:
        return 3;
    case 15:
    case 28:
    case 47:
        return 5;
    case 23:
    case 26:
    case 27:
        return 4;
    case 48:
        return 1;
    }

    return 0;
}
#ifndef VERSION_EU
void HCEffectName_0(UnkStruct_0809DF7C* w, u8* a) {
    void** tiles;

    w->unk_19 = a[0];
    w->unk_1A = 0;
    w->unk_1C = 32;
    w->unk_10 = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_08 = func_080038C8(0x3C0);
    w->unk_0C = func_080038C8(32);
    w->unk_20 = 0;
    w->unk_27 = 1;

    switch (w->unk_19) {
    case 1:
        w->unk_00 = 48;
        w->unk_1E = gUnk_02039DD4->unk_0CC;
        tiles = gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_08;
        func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_0C], gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_00);
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
        func_080038E4(w->unk_0C, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);

        if (gUnk_02039DD4->unk_0CC == 0) {
            w->unk_27 = 0;
        }
        break;
    case 2:
        w->unk_00 = 162;
        w->unk_1E = gUnk_02039DD4->unk_0CE;
        tiles = gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_08;
        func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_0C], gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_00);
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
        func_080038E4(w->unk_0C, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);

        if (gUnk_02039DD4->unk_0CE == 0) {
            w->unk_27 = 0;
        }
        break;
    }

    w->unk_14 = LoadObjTiles(gUnk_08B25ADE, 0x360);
    w->unk_22 = 0;
    w->unk_23 = 0;
    w->unk_24 = 0;
    w->unk_25 = 0;
}
#else
INCLUDE_ASM("card/HCEffectName_0.s");
#endif
#ifndef VERSION_EU
u8 HCEffectName_1(UnkStruct_0809DF7C* w, void* a) {
    u8 done;
    s32 div;
    UnkStruct_02039DD4* d;

    done = func_0809DE18((u8*)w);

    if (done != 0) {
        SetTaskUpdate(a, (void*)func_0809DE30);
        return 1;
    }

    switch (w->unk_19) {
    case 1:
        div = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E << 8;
        w->unk_1C = (u32)(((s16)gBtlWork->unk_0F8 << 16) / div) >> 3;
        d = gUnk_02039DD4;

        if (d->unk_0CC == 0) {
            d->unk_0EB = 0;
            return 0;
        }

        if (d->unk_0CC != w->unk_1E) {
            d->unk_0EB = 0;
            return 0;
        }

        if (d->unk_0EB == 1) {
            d->unk_0EB = 0;
            return 0;
        }

        if ((s16)gBtlWork->unk_0F8 <= 0) {
            d->unk_0CC = 0;
            gBtlWork->unk_0F4 = 0;
            d->unk_0EB = 0;
            return 0;
        }

        func_0806BA0C((s16)gBtlWork->unk_0F8, &w->unk_22);
        break;
    case 2:
        div = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E << 8;
        w->unk_1C = (u32)(((s16)gUnk_02039B9C->unk_0F8 << 16) / div) >> 3;
        d = gUnk_02039DD4;

        if (d->unk_0CE == 0) {
            d->unk_0EC = 0;
            return 0;
        }

        if (d->unk_0CE != w->unk_1E) {
            d->unk_0EC = 0;
            return 0;
        }

        if (d->unk_0EC == 1) {
            d->unk_0EC = 0;
            return 0;
        }

        if ((s16)gUnk_02039B9C->unk_0F8 <= 0) {
            d->unk_0CE = 0;
            gUnk_02039B9C->unk_0F4 = 0;
            d->unk_0EC = 0;
            return 0;
        }

        func_0806BA0C((s16)gUnk_02039B9C->unk_0F8, &w->unk_22);
        break;
    }

    w->unk_1A++;

    if ((s16)w->unk_1C <= 2) {
        w->unk_1C = 2;
    }

    if ((s16)w->unk_1A >= (s16)w->unk_1C) {
        w->unk_27 ^= 1;
        w->unk_1A = 0;
    }

    return 1;
}
#else
INCLUDE_ASM("card/HCEffectName_1.s");
#endif
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

#ifndef VERSION_EU
void HCEffectName_2(UnkStruct_0809DF7C* w) {
    if (w->unk_27 == 1) {
        DrawSprite(w->unk_00, 0x90, 0, w->unk_08, w->unk_10, 0, 0x400, 10);
        DrawSprite(w->unk_00, 0x8A, gUnk_09EE1538[15], w->unk_14, w->unk_10, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 8, 0x8A, gUnk_09EE1538[w->unk_24 + 4], w->unk_14, w->unk_10, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 16, 0x8A, gUnk_09EE1538[w->unk_25 + 4], w->unk_14, w->unk_10, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 24, 0x8A, 0, w->unk_0C, w->unk_10, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 32, 0x8A, gUnk_09EE1538[14], w->unk_14, w->unk_10, 0, 0x400, 10);
    }
}
#else
INCLUDE_ASM("card/HCEffectName_2.s");
#endif

void HCEffectName_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjTiles(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x10]);
    gUnk_02039DD4->unk_0D8 = 0;
    gUnk_02039DD4->unk_0E5 = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}

void NumberPlus_0(UnkWork_0809E0A4* w, UnkStruct_0809E0A4* args) {
    w->unk_08 = *args;
    w->unk_00 = LoadObjTiles(gUnk_090451C0, 128);
    w->unk_04 = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_24 = w->unk_08.unk_04 >> 8;
    w->unk_26 = (w->unk_08.unk_08 >> 8) - 20;
    w->unk_28 = 16;
    w->unk_29 = 0;
}

s32 NumberPlus_1(u8* work) {
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
void NumberPlus_2(u8* work) {
    DrawSprite(*(s16*)&work[0x24], *(s16*)&work[0x26], gUnk_09EE91A8[0],
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 16, 0);
}
void NumberPlus_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}
INCLUDE_ASM("card/Level_Up_0.s");

#ifndef VERSION_EU
void func_0809E7A4(void) {
    u32 base;

    if (*(u32*)&gBtlWork->unk_100[0x0C] == 151) {
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
#else
INCLUDE_ASM("card/func_0809E7A4.s");
#endif
INCLUDE_ASM("card/Level_Up_1.s");
INCLUDE_ASM("card/func_0809F390.s");
INCLUDE_ASM("card/func_0809F730.s");
INCLUDE_ASM("card/func_0809FBCC.s");
u8 func_0809FE14(void) {
    if (func_08006314() == 0) {
        return 0;
    }
    return 1;
}
INCLUDE_ASM("card/Level_Up_2.s");
#ifndef VERSION_EU
void Level_Up_3(u8* work) {
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
#else
INCLUDE_ASM("card/Level_Up_3.s");
#endif
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

void func_080A09C0(u16 n, u16* out) {
    u16 d3;
    u16 d2;
    u16 d1;
    u16 d0;

    d3 = n / 1000;
    d2 = n / 100 - d3 * 10;
    d1 = n / 10 - d2 * 10 - d3 * 100;
    d0 = n - d3 * 1000 - d2 * 100 - d1 * 10;
    out[0] = d3;
    out[1] = d2;
    out[2] = d1;
    out[3] = d0;
}

INCLUDE_ASM("card/func_080A0A44.s");
INCLUDE_ASM("card/func_080A11CC.s");

s32 func_080A151C(void) {
    if (gGameState.level >= gUnk_09037FBA[gGameState.unk_178]) {
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
#ifndef VERSION_EU
void LVUP_EFFECT_0(UnkStruct_080A18F4* w, UnkStruct_080A1A44_Args* a) {
    s32 i;
    UnkStruct_080A1A44_Args args;

    w->unk_0C = a->unk_0C;
    w->unk_64 = a->unk_00;
    w->unk_68 = a->unk_04;
    w->unk_30 = 30;
    w->unk_97 = a->unk_08;
    func_080A1554((u8*)w);
    w->unk_00 = LoadObjTiles(gUnk_0908C686, 0x3E0);
    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);

    for (i = 0; i < 4; i++) {
        w->unk_10[i] = (w->unk_64 << 8) + gUnk_09037FFC[i];
        w->unk_20[i] = (w->unk_68 << 8) + gUnk_0903800C[i];
        w->unk_8C[i] = gUnk_0903801C[i];
        w->unk_34[i] = w->unk_30 * gSineTable[w->unk_8C[i] & 0xFF] + w->unk_10[i];
        w->unk_44[i] = -gSineTable[(w->unk_8C[i] & 0xFF) + 64] * w->unk_30 + w->unk_20[i];
        w->unk_54[i] = 0;
    }

    w->unk_94 = 0;
    w->unk_95 = 0;
    w->unk_96 = 24;
    TaskPoolInit(w->unk_98, 4);

    if (w->unk_0C != 0 && gUnk_02034AF8 == 0) {
        args.unk_00 = w->unk_34[0];
        args.unk_04 = w->unk_44[0];
        args.unk_0C = w->unk_0C;
        args.unk_10 = w->unk_00;
        args.unk_14 = w->unk_04;
        TaskCreate(w->unk_98, gTaskDescLvupLogo, &args);
        gUnk_02034AF8 = 1;
    }
}
#else
INCLUDE_ASM("card/LVUP_EFFECT_0.s");
#endif
INCLUDE_ASM("card/LVUP_EFFECT_1.s");
u8 func_080A18F4(UnkStruct_080A18F4* w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        w->unk_6C[i] += 25;
        w->unk_44[i] += w->unk_6C[i];
        w->unk_34[i] += gSineTable[(u8)w->unk_8C[i]] * (w->unk_7C[i] >> 8);
    }

    w->unk_95++;

    if (w->unk_95 % 8 == 0 && (s8)w->unk_95 > 1) {
        w->unk_94++;
    }

    TaskPoolUpdate(&w->unk_98);

    if (w->unk_44[0] > 0xA000) {
        return 0;
    }

    return 1;
}

#ifndef VERSION_EU
void LVUP_EFFECT_2(UnkStruct_080A18F4* w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (w->unk_94 <= 5) {
            DrawSprite(w->unk_34[i] >> 8, w->unk_44[i] >> 8, gUnk_09EE7938[w->unk_94], w->unk_00, w->unk_04, 0, 0, 20);
        }
    }

    TaskPoolDraw(w->unk_98);
}
#else
INCLUDE_ASM("card/LVUP_EFFECT_2.s");
#endif

void LVUP_EFFECT_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    TaskPoolDestroy(&work[0x98]);

    if (gBtlWork->unk_068 & 0x20000) {
        gBtlWork->unk_068 &= ~0x20000;
    }
}

#ifndef VERSION_EU
void Lvup_Logo_0(UnkStruct_080A18F4* w, UnkStruct_080A1A44_Args* a) {
    w->unk_34[0] = a->unk_00;
    w->unk_64 = a->unk_00;
    w->unk_44[0] = a->unk_04;
    w->unk_68 = a->unk_04;
    w->unk_0C = a->unk_0C;
    w->unk_00 = LoadObjTiles(gUnk_0908C686, 0x3E0);
    LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_00 = a->unk_10;
    w->unk_04 = a->unk_14;
    func_080062F4(*(u16*)(a->unk_14 + 6) + 16, 1);
    w->unk_94 = 0;
    w->unk_95 = 0;
    w->unk_6C[0] = -0x280;
    m4aSongNumStart(0x23A);
}
#else
INCLUDE_ASM("card/Lvup_Logo_0.s");
#endif

s32 Lvup_Logo_1(u8* work) {
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
void Lvup_Logo_2(u8* work) {
    DrawSprite(*(s32*)&work[0x34] >> 8, *(s32*)&work[0x44] >> 8,
               gUnk_09EEA19C[((s8*)work)[0x94]], *(void**)&work[0x00],
               *(void**)&work[0x04], 0, 0, 10);
}
void Lvup_Logo_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
    gUnk_02034AF8 = 0;
}

u8 func_080A1B4C(UnkStruct_080A1B4C* p, void* pool) {
    UnkStruct_080A1A44_Args args;

    gUnk_02034AF8 = 0;

    if (gBtlWork->unk_068 & 0x20000) {
        return 0;
    }

    args.unk_00 = p->unk_04;
    args.unk_04 = p->unk_08;
    args.unk_08 = 0;
    args.unk_0C = p;
    TaskCreate(pool, gTaskDescLVUPEFFECT, &args);
    gBtlWork->unk_068 |= 0x20000;
    return 1;
}

void func_080A1BB8(UnkStruct_080A1C48* w, void** t) {
    UnkStruct_080A1BB8* q;
    UnkStruct_080A1BB8_Entry* entries;
    u8 i;

    q = t[10];
    entries = q->unk_0C;

    for (i = 0; i < 10; i++) {
        w->unk_04[i] = 0;
        w->unk_2C[i] = 0;
    }

    for (i = 0; i < q->unk_10; i++) {
        if (w->unk_04[entries[i].unk_08] == 0) {
            w->unk_04[entries[i].unk_08] = LoadObjTiles(q->unk_00[entries[i].unk_08].unk_00, q->unk_00[entries[i].unk_08].unk_04);
            w->unk_2C[entries[i].unk_08] = LoadObjPalette(q->unk_04[entries[i].unk_08].unk_00, q->unk_04[entries[i].unk_08].unk_04);
        }
    }
}

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
void Ev_mapObj_0(u8* work, u8* a) {
    void** t;

    work[0] = a[0];
    t = gUnk_09EE3CA0[work[0]];

    if (t[10] != 0) {
        func_080A1BB8(work, t);
        *(void**)&work[0x58] = t[10];
    }
}

u8 Ev_mapObj_1(u8* work) {
    UnkStruct_080A1C48* w;
    u8* p;
    u8* q;
    u8 i;

    w = (UnkStruct_080A1C48*)work;
    p = *(u8**)&work[0x58];
    q = *(u8**)&p[0x0C];

    for (i = 0; i < *(u16*)&p[0x10]; i++) {
        func_080062F4(*(u16*)((u8*)w->unk_2C[q[i * 12 + 8]] + 6) + 16, 0);
    }

    return 1;
}

void Ev_mapObj_2(UnkStruct_080A1C48* w) {
    UnkStruct_080A1BB8* q;
    UnkStruct_080A1BB8_Entry* entries;
    UnkStruct_080A1BB8_Entry* e;
    u8 i;

    q = w->unk_58;
    entries = q->unk_0C;

    for (i = 0; i < q->unk_10; i++) {
        e = &entries[i];
        DrawSprite(e->unk_00 - (*(s32*)&gUnk_02039DC8[0x58] >> 8), e->unk_04 - (*(s32*)&gUnk_02039DC8[0x5C] >> 8), q->unk_08[e->unk_08], w->unk_04[e->unk_08], w->unk_2C[e->unk_08], 0, 0x800, (u16)(-0x1004 - e->unk_04 * 4));
    }
}

void Ev_mapObj_3(u8* work) {
    func_080A1C48(work);
}

void func_080A1DAC(UnkStruct_080A1DAC* w) {
    UnkStruct_080A1DAC_Entry* e;
    UnkStruct_080A1DAC_Desc* d;

    e = &w->unk_00[w->unk_14];
    d = gUnk_09EE79B4[e->unk_02];
    w->unk_12 = e->unk_02;
    LoadBgTiles(0, d->unk_04, d->unk_0C);
    LoadBgPalette(0, d->unk_08, d->unk_0E);
    LoadBgMap(0, d->unk_00[0], 0x800);
    SetBgScroll(0, (*(s32*)&gUnk_02039DC8[0x58] >> 8) - (e->unk_04 >> 8), (*(s32*)&gUnk_02039DC8[0x5C] >> 8) - (e->unk_08 >> 8));

    if (d->unk_14 != 0) {
        w->unk_15 = 1;
    }

    SetBgBlend(0, 16, 16);
    gUnk_02039DC8[0x80] = 1;
    w->unk_0E = w->unk_0C = w->unk_16 = 0;
}

void func_080A1E4C(u8* work) {
    LoadBgTiles(0, gUnk_094233B8, 1280);
    LoadBgPalette(0, gUnk_096148D8, 32);
    LoadBgMap(0, gUnk_08125E24, 2048);
}

void func_080A1E80(u8* work) {
    u8* p;
    u16 v;
    u8 i;

    v = 16;
    p = *(u8**)&work[0] + work[0x14] * 16;

    for (i = 16; i <= 31; i++) {
        func_080062F4(i, 1);
    }

    func_080062F4(14, 1);

    if (*(s32*)&p[4] > 0) {
        v = *(s32*)&p[4];
    }

    if (*(u16*)&p[0xC] & 0x10) {
        func_08006184(0, v);
    } else {
        func_08006238(0, 16, v);
    }
}

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
void EV_BG_EFFECT_0(u8* a, u8* b) {
    u8 t;
    u8 z;

    t = b[0];
    z = 0;
    a[19] = t;
    a[20] = z;
    a[21] = z;
    *(void**)&a[0] = gUnk_09EE3FB4[a[19]][5];
}
u8 EV_BG_EFFECT_1(UnkStruct_080A1DAC* w, void* a) {
    UnkStruct_080A1DAC_Entry* e;
    UnkStruct_080A1DAC_Entry* cur;
    u8 i;

    e = w->unk_00;

    if (e == 0) {
        return 0;
    }

    if (*(u16*)e[w->unk_14].unk_00 <= *(u16*)&gUnk_02039DC8[0x6C] && !(*(u16*)e[w->unk_14].unk_0C & 0x8000)) {
        w->unk_14++;
        cur = &e[w->unk_14];

        if (*(u16*)cur->unk_0C & 1) {
            func_080A1DAC(w);

            if (w->unk_15 != 0) {
                SetTaskUpdate(a, (void*)func_080A2024);
            }
        }

        if (*(u16*)cur->unk_0C & 4) {
            func_080A1E80((u8*)w);
        }

        if (*(u16*)cur->unk_0C & 8) {
            func_080A1ED8((u8*)w);
            w->unk_16 = 1;
        }

        if (*(u16*)cur->unk_0C & 2) {
            func_080A1E4C((u8*)w);
            gUnk_02039DC8[0x80] = 0;
            gBldCnt = *(u16*)&gUnk_02039DC8[0x6E];
            gBldAlpha = *(u16*)&gUnk_02039DC8[0x70];
        }
    }

    if (w->unk_16 == 1) {
        if (!func_08006314()) {
            w->unk_16 = 0;

            for (i = 16; i < 32; i++) {
                func_080062F4(i, 0);
            }
        }
    }

    return 1;
}

u8 func_080A2024(u8* work, void* a) {
    u8* p;

    p = *(u8**)&work[0] + work[0x14] * 16;
    SetBgScroll(0, (*(s32*)&gUnk_02039DC8[0x58] >> 8) - (*(s32*)&p[4] >> 8),
                (*(s32*)&gUnk_02039DC8[0x5C] >> 8) - (*(s32*)&p[8] >> 8));

    if (func_080A207C(work) == 0) {
        SetTaskUpdate(a, (void*)EV_BG_EFFECT_1);
    }

    return 1;
}

u8 func_080A207C(UnkStruct_080A1DAC* w) {
    UnkStruct_080A1DAC_Desc* d;
    UnkStruct_080A1DAC_Frame* tbl;

    if (w->unk_15 == 0) {
        return 0;
    }

    d = gUnk_09EE79B4[w->unk_12];
    tbl = d->unk_14;

    if (w->unk_0C < tbl[w->unk_0E].unk_00) {
        w->unk_0C++;
    } else {
        w->unk_0C = 0;

        if (w->unk_0E < d->unk_18 - 1) {
            w->unk_0E++;
            RequestDma3Copy(d->unk_04 + tbl[w->unk_0E].unk_02, (void*)GetBgCharBase(0), d->unk_0C);
        } else {
            if (d->unk_19 == -1) {
                w->unk_15 = 0;
                return 0;
            }

            w->unk_0E = d->unk_19;
            RequestDma3Copy(d->unk_04 + tbl[w->unk_0E].unk_02, (void*)GetBgCharBase(0), d->unk_0C);
        }
    }

    return 1;
}

void EV_BG_EFFECT_2(void) {
}
void EV_BG_EFFECT_3(void) {
}
void func_080A2124(u8* work) {
    TaskCreate(&work[0x10], gTaskDescEVBGEFFECT, work);
}
void StockInfo_0(u8* work, void* a) {
    u8 i;

    *(void**)&work[0x14] = a;
    TaskPoolInit(&work[0x18], 1);
    *(void**)&work[0] = LoadObjTiles(gUnk_0908FCEE, 0x12A0);
    *(void**)&work[4] = LoadObjPalette(gUnk_09613F78, 32);

    for (i = 16; i < 32; i++) {
        func_080062F4(i, 1);
    }

    *(s32*)&work[8] = 0x4C00;
    *(s32*)&work[0xC] = 0xBC00;
    work[0x10] = 16;

    switch (gGameState.unk_178) {
    case 0:
        func_0800FB2C(0);
        break;
    case 1:
        func_0800FB2C(2);
        break;
    case 2:
        func_0800FB2C(4);
        break;
    case 3:
        func_0800FB2C(1);
        break;
    case 4:
        func_0800FB2C(5);
        break;
    case 5:
        func_0800FB2C(3);
        break;
    case 6:
        func_0800FB2C(36);
        break;
    case 7:
        func_0800FB2C(6);
        break;
    case 8:
        func_0800FB2C(46);
        break;
    case 9:
        func_0800FB2C(7);
        break;
    case 10:
        func_0800FB2C(32);
        break;
    }
}

u8 StockInfo_1(u8* work, void* a) {
    if ((s8)work[0x10] > 0) {
        ApproachValue(&work[0x0C], 0x6C00, (u16)(s8)work[0x10]);
        work[0x10]--;
    } else {
        m4aSongNumStart(0xCA);
        func_080D8EB4(&work[0x18], gUnk_0903BFBC[gGameState.unk_178], 0, 0, 0x50);
        SetTaskUpdate(a, (void*)func_080A22A4);
    }

    return 1;
}

s32 func_080A22A4(u8* work) {
    if ((*(u8**)&work[0x14])[0] == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x18]);
    return 1;
}
void StockInfo_2(u8* work) {
    DrawSprite(*(s32*)&work[0x08] >> 8, *(s32*)&work[0x0C] >> 8, gUnk_09EEA28C,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    TaskPoolDraw(&work[0x18]);
}
void StockInfo_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    gGameState.unk_178++;
    TaskPoolDestroy(&work[0x18]);
}

#ifndef VERSION_EU
void* func_080A2334(u16 a, u8 b) {
    if (b < gUnk_09EE7D84[a]->unk_04) {
        return gUnk_09EE7D84[a]->unk_00[b];
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_080A2334.s");
#endif

u8 func_080A235C(u16 a) {
    return gUnk_09EE7D84[a]->unk_04;
}
u8 func_080A2370(void) {
    if (gGameState.level >= gUnk_0903BFD4[gGameState.unk_178]) {
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_080A23A0.s");

#ifndef VERSION_JP
s32 func_080A25B8(u8* work, void* a) {
    SetTaskUpdate(a, func_080A25E0);
    work[0x2B1]++;
    return 1;
}
#else
INCLUDE_ASM("card/func_080A25B8.s");
#endif
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

void func_080A2E14(u8* work) {
    func_080664D8(*(s16*)&work[0x792], *(s16*)&work[0x796], work, *(void**)&work[0x784], 1, work[0x78C]);
    func_080664D8(*(s16*)&work[0x794], *(s16*)&work[0x798], &work[0x280], *(void**)&work[0x784], 1, work[0x78D]);
    func_080664D8(*(s16*)&work[0x79A], *(s16*)&work[0x79C], &work[0x500], *(void**)&work[0x784], 1, work[0x78E]);
    DrawSprite(120, 80, gUnk_09EF1278[0], *(void**)&work[0x780], *(void**)&work[0x788], 0, 0, 2);
}

void func_080A2EF8(u8* work) {
    func_08065AE0(work, 80);
    func_08065AE0(&work[0x280], 80);
    func_08065AE0(&work[0x500], 80);
    ReleaseObjPalette(*(void**)&work[0x784]);
    ReleaseObjTiles(*(void**)&work[0x780]);
    ReleaseObjPalette(*(void**)&work[0x788]);
    (*(u8**)&work[0x7A0])[0] = 0;
}

#ifdef VERSION_JP
#define DECK_PROMPT_LEFT_DX 30
#define DECK_PROMPT_RIGHT_DX 35
#define DECK_CLEAR_TEXT_Y 66
#else
#define DECK_PROMPT_LEFT_DX 20
#define DECK_PROMPT_RIGHT_DX 20
#define DECK_CLEAR_TEXT_Y 61
#endif

#ifndef VERSION_EU
void Deck_Yes_No_0(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
    w->unk_78C = func_08065B6C(gUnk_08159FBC, w);
    w->unk_78D = func_08065B6C(gUnk_08159E10, w->unk_280);
    w->unk_78E = func_08065B6C(gUnk_08159E18, w->unk_500);
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->unk_780 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (240 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_796 = 66;
    w->unk_794 = (240 - func_08065B08(w->unk_280, w->unk_78D)) / 2 - DECK_PROMPT_LEFT_DX;
    w->unk_798 = 88;
    w->unk_79A = (240 - func_08065B08(w->unk_500, w->unk_78E)) / 2 + DECK_PROMPT_RIGHT_DX;
    w->unk_79C = 88;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}
#else
INCLUDE_ASM("card/Deck_Yes_No_0.s");
#endif
s32 func_080A30C0(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}
#ifndef VERSION_EU
void Deck_Clear_0(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
    w->unk_78C = func_08065B6C(gUnk_0815C1C2, w);
    w->unk_78D = func_08065B6C(gUnk_08159E10, w->unk_280);
    w->unk_78E = func_08065B6C(gUnk_08159E18, w->unk_500);
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->unk_780 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (240 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_794 = (240 - func_08065B08(w->unk_280, w->unk_78D)) / 2 - DECK_PROMPT_LEFT_DX;
    w->unk_798 = 88;
    w->unk_79A = (240 - func_08065B08(w->unk_280, w->unk_78E)) / 2 + DECK_PROMPT_RIGHT_DX;
    w->unk_79C = 88;
    w->unk_796 = DECK_CLEAR_TEXT_Y;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}
#else
INCLUDE_ASM("card/Deck_Clear_0.s");
#endif

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

void func_080A32DC(u8* p) {
    u16 i;
    u8* src;
    u8* dst;
    u8* src2;
    u16* dst2;
    Deck* dst3;
    u8* src3;
    Deck* d;

    for (i = 0; i < 0x10E; i++) {
        dst = gUnk_0203A8C0;
        src = &p[1];
        dst[i] = src[i];
    }

    for (i = 0; i < 0x3E7; i++) {
        dst2 = gCardCollection;
        src2 = &p[0x110];
        dst2[i] = *(u16*)(src2 + (i << 1));
    }

    for (i = 0; i < 3; i++) {
        dst3 = gDecks;
        d = &dst3[i];
        src3 = &p[i * 0xE0];
        memcpy(d, &src3[0x8E0], 0xE0);
    }

    gCardCount = *(u16*)&p[0x8DE];
    SetActiveDeckIndex(p[0]);
}

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

void func_080A33C4(u8* work, void* a) {
    vu32 zero;

    zero = 0;
    CpuSet((void*)&zero, work, 0x05000054);
    ((UnkStruct_02034AFC*)work)->unk_13C = func_0806BA74(0, 0);
    *(u64*)&work[0x10C] = *(u64*)a;
    *(UnkStruct_080A3F5C_Sel**)&work[0x114] =
        (UnkStruct_080A3F5C_Sel*)&gUnk_09EE8008[*(u16*)&work[0x110]];
    *(s32*)&work[0x00] = 0;
    *(s32*)&work[0x04] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x10] = 0;
    *(s32*)&work[0x14] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0xC0] = 0;
    *(s32*)&work[0x118] =
        gUnk_09033C98[(*(UnkStruct_080A3F5C_Sel**)&work[0x114])->unk_04];
    *(s32*)&work[0x11C] = 0;
    *(s32*)&work[0x120] = 0;
    *(s32*)&work[0x124] = 0;
    *(s32*)&work[0x128] = 0;
    *(s32*)&work[0x12C] = 0;
    *(s32*)&work[0x130] = 0;
    *(s32*)&work[0x134] = 0;
    *(s32*)&work[0x138] = 0;
    *(u16*)&work[0x13C] = 0;
    *(u16*)&work[0x13E] = 0;
    work[0x140] = 8;
    work[0x141] = 0;
    work[0x142] = 0;
    work[0x143] = 0;
    work[0x144] = 0;
    work[0x145] = 0;
    work[0x146] = 0;
    work[0x147] = 0;
    work[0x148] = 1;
    work[0x149] = 0;
    work[0x14A] = 0;
    work[0x14B] = 0;
    work[0x14C] = 0;
    work[0x14D] = 0;
    work[0x14E] = 0;
    work[0x14F] = 1;

    switch ((u32)(*(UnkStruct_080A3F5C_Sel**)&work[0x114])->unk_04) {
    case 0:
    case 1:
        work[0x14D] = 1;
        break;
    case 2:
    case 3:
        work[0x14D] = 0;
        break;
    }

    gUnk_0203A9D4 = 1;
    gUnk_0203A9D8 = 0;
    SetBgScroll(*(s32*)&work[0x10C], 0, 0);

    switch (work[0x113]) {
    case 0:
    case 1:
        SetBgPriority(*(s32*)&work[0x10C], 0);
        break;
    case 2:
    case 3:
        break;
    }

    gUnk_02034AFC = (UnkStruct_02034AFC*)work;
}

u8 func_080A3558(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Entry* tbl;

    ApproachValue(&w->unk_118, gUnk_09033CA0[w->unk_114->unk_04], w->unk_140);
    ApproachValue(&w->unk_11C, gUnk_09033CE0[w->unk_114->unk_04], w->unk_140);
    func_08005244(w->unk_10C, w->unk_118, 0);
    w->unk_12C = AnimUpdate(w->unk_0C4);

    if (w->unk_140 != 0) {
        w->unk_140--;
    } else {
        tbl = gUnk_09EE45DC[w->unk_114->unk_00];

        if (tbl[w->unk_114->unk_08].unk_10 > 1) {
            AnimStart(w->unk_0C4, 1, tbl[w->unk_114->unk_08].unk_11);
        }

        switch (w->unk_113) {
        case 0:
            SetTaskUpdate(a, (void*)func_080A3A98);
            break;
        case 1:
            SetTaskUpdate(a, (void*)func_080A3F5C);
            break;
        }
    }

    return 1;
}

u8 func_080A3640(u8* work, void* a) {
    LoadBgTiles(*(s32*)&work[0x10C], gUnk_094233B8, 1280);
    LoadBgPalette(*(s32*)&work[0x10C], gUnk_096148D8, 32);
    func_0800516C(*(s32*)&work[0x10C], gUnk_09EE4724[(*(UnkStruct_0809E0A4**)&work[0x114])->unk_04], 2, 1);
    func_08005244(*(s32*)&work[0x10C], *(u16*)&work[0x118], 0);
    SetTaskUpdate(a, (void*)func_080A36B0);
    return 1;
}

INCLUDE_ASM("card/func_080A36B0.s");
u8 func_080A3754(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Sel* sel;
    UnkStruct_080A3F5C_Entry* e;

    w->unk_149 = 1;
    sel = w->unk_114;

    if (sel->unk_00 != 62) {
        e = gUnk_09EE45DC[sel->unk_00];
        w->unk_000 = AllocObjTiles(0xD80, 0);
        w->unk_004 = LoadObjPalette(e[w->unk_114->unk_08].unk_04, 32);
        func_08002A10(w->unk_000, e[w->unk_114->unk_08].unk_00);
        AnimInit(w->unk_0C4, e[w->unk_114->unk_08].unk_0C, e[w->unk_114->unk_08].unk_08);
        AnimStart(w->unk_0C4, 0, e[w->unk_114->unk_08].unk_11);
        w->unk_12C = AnimGetGfx(w->unk_0C4);
        w->unk_11C = gUnk_09033CD0[w->unk_114->unk_04];
        w->unk_120 = gUnk_09033CF0[w->unk_114->unk_04];
    } else {
        w->unk_000 = 0;
        w->unk_004 = 0;
    }

    SetTaskUpdate(a, (void*)func_080A3558);
    return 1;
}
void func_080A3848(UnkStruct_080A3F5C* w) {
    void** p;

    if (w->unk_149 != 0) {
        func_0806C2C0(w->unk_141);
    }

    if (w->unk_000 != 0) {
        if (w->unk_14D != 0) {
            DrawSprite(w->unk_11C >> 8, w->unk_120 >> 8, w->unk_12C, w->unk_000, w->unk_004, 0, 1, 0);
        } else {
            DrawSprite(w->unk_11C >> 8, w->unk_120 >> 8, w->unk_12C, w->unk_000, w->unk_004, 0, 0, 0);
        }

        if (w->unk_008 != 0 && w->unk_148 != 0) {
            DrawSprite(gUnk_09033D08[w->unk_114->unk_04][0] >> 8, gUnk_09033D08[w->unk_114->unk_04][1] >> 8,
                       w->unk_130, w->unk_008, w->unk_00C, 0, 0, 10);
        }
    }

    if (w->unk_010 != 0) {
        DrawSprite(w->unk_124 >> 8, w->unk_128 >> 8, w->unk_134, w->unk_010, w->unk_014, 0, 1, 9);
    }

    if (w->unk_018 != 0) {
        p = &gUnk_09EF126C;
        DrawSprite(120, 80, p[1], w->unk_018, w->unk_01C, 0, 0, 10);
        func_080664D8((240 - w->unk_146[0] * 10) >> 1, 67, w->unk_020, w->unk_0C0, 0, w->unk_146[0]);
        func_080664D8((240 - w->unk_146[1] * 10) >> 1, 82, w->unk_070, w->unk_0C0, 0, w->unk_146[1]);
    }
}

void func_080A3A04(u8* work) {
    func_0806C34C();

    if (*(void**)&work[0x00] != 0) {
        ReleaseObjTiles(*(void**)&work[0x00]);
    }

    if (*(void**)&work[0x04] != 0) {
        ReleaseObjPalette(*(void**)&work[0x04]);
    }

    if (*(void**)&work[0x08] != 0) {
        ReleaseObjTiles(*(void**)&work[0x08]);
    }

    if (*(void**)&work[0x0C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x0C]);
    }

    if (*(void**)&work[0x10] != 0) {
        ReleaseObjTiles(*(void**)&work[0x10]);
    }

    if (*(void**)&work[0x14] != 0) {
        ReleaseObjPalette(*(void**)&work[0x14]);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x1C]);
    }

    if (*(void**)&work[0xC0] != 0) {
        ReleaseObjPalette(*(void**)&work[0xC0]);
    }

    func_08065AE0(&work[0x20], 10);
    func_08065AE0(&work[0x70], 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034AFC = 0;
}

u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Sel* sel;
    UnkStruct_080A3F5C_Entry* e;

    w->unk_12C = AnimUpdate(w->unk_0C4);

    if (GetKeysPressed() & 1) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;
    sel = w->unk_114;

    if (w->unk_142 >= sel->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(0x74);
        } else {
            e = gUnk_09EE45DC[sel->unk_00];
            AnimStart(w->unk_0C4, 0, e[sel->unk_08].unk_11);

            if (w->unk_008 == 0) {
                w->unk_008 = AllocObjTiles(0x40, 0);
                w->unk_00C = LoadObjPalette(gUnk_08F69BE4, 32);
                func_08002A10(w->unk_008, gUnk_09320796);
                AnimInit(w->unk_0DC, gUnk_09EEFD38, gUnk_09EEFCAC);
                AnimStart(w->unk_0DC, 2, 1);
                w->unk_130 = AnimGetGfx(w->unk_0DC);
            }

            w->unk_148 = 1;
            SetTaskUpdate(a, (void*)func_080A3BB0);
        }

        w->unk_142 = 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080A3BB0.s");

u8 func_080A3DD0(UnkStruct_080A3F5C* w) {
    if (w->unk_008 != 0) {
        w->unk_130 = AnimUpdate(w->unk_0DC);
    }

    w->unk_12C = AnimUpdate(w->unk_0C4);
    w->unk_13E++;

    if (w->unk_13E > 15) {
        w->unk_149 = 0;
        w->unk_148 = 0;
        ApproachValue(&w->unk_118, gUnk_09033C98[w->unk_114->unk_04], w->unk_140);
        ApproachValue(&w->unk_11C, gUnk_09033CD0[w->unk_114->unk_04], w->unk_140);
        func_08005244(w->unk_10C, w->unk_118, 0);

        if (w->unk_140 == 0) {
            return 0;
        }

        w->unk_140--;
    }

    return 1;
}

u8 func_080A3E8C(UnkStruct_080A3F5C* w, void* a) {
    w->unk_12C = AnimUpdate(w->unk_0C4);
    w->unk_134 = AnimUpdate(w->unk_0F4);

    switch (GetKeysRepeat()) {
    case 0x40:
    case 0x80:
        w->unk_144 ^= 1;
        w->unk_145 = 4;
        break;
    case 1:
    case 8:
        m4aSongNumStart(0x66);

        if (w->unk_144 == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        SetTaskUpdate(a, (void*)func_080A3DD0);
        break;
    }

    if (w->unk_145 != 0) {
        ApproachValue(&w->unk_128, gUnk_09033D28[w->unk_144], w->unk_145);
        w->unk_145--;
    }

    return 1;
}

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

u8 func_080A4578(u8* work, void* a) {
    void* pal;

    switch (work[0x113]) {
    case 0:
    case 1:
        pal = &gUnk_050001C0[0x20];
        LoadBgTiles(*(s32*)&work[0x10C], gUnk_0950E2F8, 0x140);
        LoadBgMap(*(s32*)&work[0x10C], gUnk_096112B8, 0x800);
        LoadPalette(gUnk_09611AB8, pal, 32);

        switch ((u32)(*(UnkStruct_080A3F5C_Sel**)&work[0x114])->unk_04) {
        case 0:
        case 2:
            SetBgScroll(*(s32*)&work[0x10C], -24, 0);
            break;
        case 1:
        case 3:
            SetBgScroll(*(s32*)&work[0x10C], -24, -94);
            break;
        default:
            SetBgScroll(*(s32*)&work[0x10C], -24, -94);
            break;
        }
        break;
    case 2:
    case 3:
        switch ((u32)(*(UnkStruct_080A3F5C_Sel**)&work[0x114])->unk_04) {
        case 0:
        case 2:
            *(s32*)&work[0x120] = 0x7800;
            *(s32*)&work[0x124] = 0x2200;
            break;
        case 1:
        default:
            *(s32*)&work[0x120] = 0x7800;
            *(s32*)&work[0x124] = 0x7E00;
            break;
        }

        *(void**)&work[0x18] = LoadObjTiles(&gUnk_093F8C8E[0xC1E], 0x1800);

        if (*(void**)&work[0x18] == 0) {
            work[0x147] = 1;
            *(void**)&work[0x18] = LoadObjTiles(&gUnk_0950E2F8[0x140], 0x680);
        } else {
            work[0x147] = 0;
        }

        *(void**)&work[0x1C] = LoadObjPalette(gUnk_09611AB8, 32);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x1C])->unk_06 + 16, 1);
        break;
    }

    switch (work[0x113]) {
    case 0:
    case 2:
        SetTaskUpdate(a, (void*)func_080A470C);
        break;
    case 1:
    case 3:
        SetTaskUpdate(a, (void*)func_080A4CC8);
        break;
    }

    return 1;
}

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

void func_080A4C1C(u8* work) {
    if (work[0x113] <= 1) {
        DisableBg(*(s32*)&work[0x10C]);
    }

    func_0806C34C();

    if (*(void**)&work[0x00] != 0) {
        ReleaseObjTiles(*(void**)&work[0x00]);
    }

    if (*(void**)&work[0x04] != 0) {
        ReleaseObjPalette(*(void**)&work[0x04]);
    }

    if (*(void**)&work[0x08] != 0) {
        ReleaseObjTiles(*(void**)&work[0x08]);
    }

    if (*(void**)&work[0x0C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x0C]);
    }

    if (*(void**)&work[0x10] != 0) {
        ReleaseObjTiles(*(void**)&work[0x10]);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x1C]);
    }

    if (*(void**)&work[0x14] != 0) {
        ReleaseObjPalette(*(void**)&work[0x14]);
    }

    if (*(void**)&work[0xC0] != 0) {
        ReleaseObjPalette(*(void**)&work[0xC0]);
    }

    func_08065AE0(&work[0x20], 10);
    func_08065AE0(&work[0x70], 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034B00 = 0;
}

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
#ifndef VERSION_EU
u8 func_080A5034(UnkStruct_080A3F5C* w, void* a) {
    u8* pal;

    w->unk_008 = AllocObjTiles(0x120, 0);
    pal = gUnk_09614418;
    w->unk_00C = LoadObjPalette(pal, 32);
    func_080062F4(w->unk_01C->unk_06 + 16, 1);
    LoadObjPaletteBank(((UnkStruct_080038C8*)w->unk_00C)->unk_06, pal);
    func_08002A10(w->unk_008, gUnk_090A4664);
    AnimInit(w->unk_0F4, gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart(w->unk_0F4, 2, 1);
    w->unk_12C = AnimGetGfx(w->unk_0F4);
    w->unk_13D = 1;
    w->unk_118 = 0x8500;
    w->unk_11C = 0x5000;
    ((u8*)&w->unk_13E)[1] = func_08065B6C(gUnk_08159E10, w->unk_020);
    w->unk_140 = func_08065B6C(gUnk_08159E18, w->unk_070);
    w->unk_0C0 = (s32)_08066468(1);
    w->unk_144 = 1;
    w->unk_010 = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
    w->unk_014 = LoadObjPalette(gUnk_09611AB8, 32);
    func_080062F4(w->unk_01C->unk_06 + 16, 1);
    SetTaskUpdate(a, (void*)func_080A5198);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A5034.s");
#endif
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
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a) {
    s32 tbl[2];

    *(u64*)tbl = *(u64*)gUnk_09041E9C;
    w->unk_12C = AnimUpdate(w->unk_0F4);

    switch (GetKeysPressed()) {
    case 0x20:
        if (w->unk_13D != 0) {
            w->unk_13D--;
            m4aSongNumStart(0x65);
        }

        ((u8*)&w->unk_13E)[0] = 1;
        break;
    case 0x10:
        if (w->unk_13D == 0) {
            w->unk_13D++;
            m4aSongNumStart(0x65);
        }

        ((u8*)&w->unk_13E)[0] = 1;
        break;
    }

    switch (GetKeysPressed()) {
    case 1:
    case 8:
        m4aSongNumStart(0x66);

        if (w->unk_13D == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        w->unk_142 = 0;
        SetTaskUpdate(a, (void*)func_080A5150);
        break;
    case 2:
        m4aSongNumStart(0x68);
        gUnk_0203A9D8 = 0;
        w->unk_142 = 0;
        SetTaskUpdate(a, (void*)func_080A5150);
        break;
    }

    if (((u8*)&w->unk_13E)[0] != 0) {
        ApproachValue(&w->unk_118, tbl[w->unk_13D], ((u8*)&w->unk_13E)[0]);
        ((u8*)&w->unk_13E)[0]--;
    }

    return 1;
}
void func_080A52BC(UnkStruct_080A3F5C* w) {
    func_0806C2C0(w->unk_138[1]);

    switch (w->unk_113) {
    case 2:
    case 3:
        if (w->unk_018 != 0) {
            DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, gUnk_09EF1278[0], w->unk_018, w->unk_01C, 0, 0, 20);
        }
        break;
    }

    if (w->unk_000 != 0 && w->unk_141 != 0) {
        DrawSprite(120, gUnk_09033D08[w->unk_114->unk_04][1] >> 8, w->unk_128, w->unk_000, w->unk_004, 0, 0, 10);
    }

    if (w->unk_008 != 0) {
        DrawSprite(w->unk_118 >> 8, w->unk_11C >> 8, w->unk_12C, w->unk_008, w->unk_00C, 0, 1, 10);
    }

    func_080664D8(89, 86, w->unk_020, w->unk_0C0, 0, ((u8*)&w->unk_13E)[1]);
    func_080664D8(135, 86, w->unk_070, w->unk_0C0, 0, w->unk_140);
}

void func_080A53E4(u8* work) {
    if (work[0x113] <= 1) {
        DisableBg(*(s32*)&work[0x10C]);
    }

    func_0806C34C();

    if (*(void**)&work[0x00] != 0) {
        ReleaseObjTiles(*(void**)&work[0x00]);
    }

    if (*(void**)&work[0x04] != 0) {
        ReleaseObjPalette(*(void**)&work[0x04]);
    }

    if (*(void**)&work[0x08] != 0) {
        ReleaseObjTiles(*(void**)&work[0x08]);
    }

    if (*(void**)&work[0x0C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x0C]);
    }

    if (*(void**)&work[0x10] != 0) {
        ReleaseObjTiles(*(void**)&work[0x10]);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x1C]);
    }

    if (*(void**)&work[0x14] != 0) {
        ReleaseObjPalette(*(void**)&work[0x14]);
    }

    if (*(void**)&work[0xC0] != 0) {
        ReleaseObjPalette(*(void**)&work[0xC0]);
    }

    func_08065AE0(&work[0x20], 10);
    func_08065AE0(&work[0x70], 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034B00 = 0;
}

void func_080A5490(UnkStruct_080A5490* w, UnkStruct_080A5490_Args* a) {
    u8 i;

    func_08006238(0, 16, 8);
    *(UnkStruct_080A5490_Args*)&w->unk_10 = *a;
    w->unk_00 = LoadObjTiles(gUnk_093FB0CC, 0xC0);
    w->unk_04 = LoadObjPalette(gUnk_09619378, 32);
    w->unk_08 = LoadObjTiles(gUnk_093FB1AC, 0x4A0);
    w->unk_0C = AllocObjPalette(32);
    w->unk_A2 = 6;
    w->unk_1C = 0;
    w->unk_1D = 0;
    w->unk_A3 = 0;
    func_08003A70(w->unk_0C, &gUnk_09619178[gUnk_09EE8E60[w->unk_1C * 4] << 5]);
    func_080062F4(((UnkStruct_080038C8*)w->unk_04)->unk_06 + 16, 1);
    func_080062F4(w->unk_0C->unk_06 + 16, 1);

    for (i = 0; i < w->unk_A2; i++) {
        w->unk_98[i] = 0x80;
        w->unk_70[i] = 0;
        w->unk_20[i] = gSineTable[w->unk_98[i]] * 24 + w->unk_10;
        w->unk_48[i] = -gSineTable[w->unk_98[i] + 64] * 12 + w->unk_14;
    }

    m4aSongNumStart(0xD4);
}
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

#ifndef VERSION_EU
void func_080A5C60(u8* work, u16 card) {
    CardDef* d;

    d = &gCardDefs[card];
    work[0x4FE] = func_08065B6C(gUnk_09EE8F48[d->unk_1C], &work[0x1E0]);
}
#else
INCLUDE_ASM("card/func_080A5C60.s");
#endif

#ifndef VERSION_EU
u8 func_080A5C9C(u8* work, void* a) {
    LoadBgTiles(3, gUnk_09402F78, 0x4000);
    LoadBgPalette(3, gUnk_09614118, 0x1E0);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgTiles(1, gUnk_09406F78, 0xC00);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    SetBgScroll(0, -88, -108);
    SetBgScroll(1, -88, -16);
    SetTaskUpdate(a, (void*)func_080A5D3C);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A5C9C.s");
#endif

#ifndef VERSION_EU
u8 func_080A5D3C(UnkStruct_080A5D3C* w, void* a) {
    u8* base;
    u16* pal;

    base = (u8*)GetBgCharBase(1);
    pal = (u16*)0x05000100;
    LoadPalette(gUnk_09614118 + 0x1E0, pal, 32);
    RequestDma3Copy(gUnk_0940FC58, base + 0x1A0, 0x1E0);
    LoadBgMap(0, gUnk_09516AB8 + 0x800, 0x800);
    LoadBgMap(1, gUnk_0951B2B8 + 0x800, 0x800);
    func_080A6B40(w->unk_4EF, 0);
    func_080A6B40(w->unk_4F0, 1);
    func_080A6B40(w->unk_4F1, 2);
    func_080A6B40(w->unk_4F2, 3);
    func_080A6C50(0);
    func_080A6D0C();
    w->unk_494 = 0x4800;
    w->unk_498 = 0x2800;
    w->unk_4C8[1] = w->unk_4F8;
    ApproachValue(&w->unk_48C, gUnk_09041EB4[w->unk_4C8[0]] << 8, w->unk_4EC);
    ApproachValue(&w->unk_490, gUnk_09041EBA[w->unk_4C8[1]] << 8, w->unk_4EC);
    w->unk_4E6 = 1;
    func_080A6BB4((u8*)w);
    func_080A6E3C((u8*)w);
    w->unk_509 = 0;
    w->unk_4EC = 16;
    SetTaskUpdate(a, func_080A5EA0);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A5D3C.s");
#endif

u8 func_080A5EA0(u8* work, void* a) {
    u8 n;

    if (func_08006314() == 0) {
        switch (work[0x509]) {
        case 0:
            ApproachValue(&work[0x4A4], 0, work[0x4EC]);
            ApproachValue(&work[0x4A8], 0x9800, work[0x4EC]);
            work[0x4EC]--;

            if (work[0x4EC] == 0) {
                work[0x4EC] = 16;
                work[0x509]++;
            }
            break;
        case 1:
            ApproachValue(&work[0x4AC], 0, work[0x4EC]);
            n = --work[0x4EC];

            if (n == 0) {
                LoadBgMap(3, gUnk_095162B8, 0x800);
                ReleaseObjTiles(*(void**)&work[0x3CC]);
                *(void**)&work[0x3CC] = 0;
                ReleaseObjTiles(*(void**)&work[0x3C4]);
                *(void**)&work[0x3C4] = 0;
                ReleaseObjPalette(*(void**)&work[0x3C8]);
                *(void**)&work[0x3C8] = 0;
                SetTaskUpdate(a, (void*)func_080A5F70);
            }
            break;
        }
    }

    return 1;
}

u8 func_080A5F70(u8* work, void* a) {
    *(s32*)&work[0x48C] = gUnk_09035950[*(s16*)&work[0x4C8]] << 8;
    *(s32*)&work[0x490] = gUnk_09035956[*(s16*)&work[0x4CA]] << 8;
    work[0x4E6] = 0;
    func_080A6BB4(work);
    func_080A6FAC(work);
    work[0x50A] = 1;
    SetTaskUpdate(a, (void*)func_080A5FF4);
    return 1;
}

INCLUDE_ASM("card/func_080A5FF4.s");
s32 func_080A6388(u8* work) {
    if (func_08006314() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x40C]);
    TaskPoolUpdate(&work[0x420]);
    return 1;
}

#ifndef VERSION_EU
u8 func_080A63B8(u8* work, void* a) {
    *(void**)&work[0x3CC] = LoadObjTiles(gUnk_090A418E, 0x320);
    *(void**)&work[0x3C4] = LoadObjTiles(gUnk_090A583E, 0x620);
    *(void**)&work[0x3C8] = LoadObjPalette(gUnk_096144F8, 32);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    *(s32*)&work[0x49C] = 0x7800;
    *(s32*)&work[0x4A4] = 0;
    *(s32*)&work[0x4A0] = 0xA400;
    *(s32*)&work[0x4A8] = 0x9800;
    *(s32*)&work[0x4AC] = 0;
    work[0x505] = 16;
    work[0x506] = 16;
    work[0x50A] = 0;
    SetTaskUpdate(a, (void*)func_080A6474);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A63B8.s");
#endif

u8 func_080A6474(u8* work, void* a) {
    u8* p;

    p = &work[0x506];

    if ((s8)*p > 0) {
        ApproachValue(&work[0x4AC], -0x8000, (u16)(s8)*p);
        (*p)--;
    } else {
        p = &work[0x505];

        if ((s8)*p > 0) {
            ApproachValue(&work[0x4A4], -0x800, (u16)(s8)*p);
            ApproachValue(&work[0x4A8], 0xA000, (u16)(s8)*p);
            (*p)--;
        } else {
            func_08006184(0, 4);
            SetTaskUpdate(a, (void*)func_080A6388);
        }
    }

    return 1;
}

INCLUDE_ASM("card/func_080A6500.s");

void func_080A676C(u8* work) {
    func_080A6968(work);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x14]);
    func_080A7264((void**)work);

    if (*(void**)&work[0x3CC] != 0) {
        ReleaseObjTiles(*(void**)&work[0x3CC]);
    }

    if (*(void**)&work[0x3C4] != 0) {
        ReleaseObjTiles(*(void**)&work[0x3C4]);
    }

    if (*(void**)&work[0x3C8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x3C8]);
    }

    func_08065AE0(&work[0x30], 8);
    func_08065AE0(&work[0x70], 8);
    func_08065AE0(&work[0xB0], 8);
    func_08065AE0(&work[0xF0], 30);
    func_08065AE0(&work[0x1E0], 60);
    ReleaseObjPalette(*(void**)&work[0x3D8]);
    TaskPoolDestroy(&work[0x40C]);
    TaskPoolDestroy(&work[0x420]);
    func_080A7210(work);
    **(u8**)&work[0x4F4] = work[0x50C];
}

INCLUDE_ASM("card/func_080A6838.s");
void func_080A6968(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        node->unk_4A = 1;
        node = ListPoolNext(&node->unk_2C);
    }

    TaskPoolUpdate(&work[0x40C]);
}

void func_080A69A0(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    if ((s8)work[0x4EE] == 33) {
        return;
    }

    while (node != 0) {
        node->unk_24--;

        if (node->unk_24 < 0) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    }

    m4aSongNumStart(0x79);
    work[0x4EE]++;
    *(s32*)&work[0x498] += 0x300;

    if (*(s32*)&work[0x498] > 0x7C00) {
        *(s32*)&work[0x498] = 0x7C00;
    }

    if (work[0x508] != 0) {
        (*(u16*)&work[0x4BA])--;
    }
}

u8 func_080A6A38(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    if (node == 0) {
        *(s32*)&work[0x498] -= 0x300;

        if (*(s32*)&work[0x498] < 0x2800) {
            *(s32*)&work[0x498] = 0x2800;
            return 0;
        }

        return 1;
    }

    if (node->unk_24 == 0) {
        return 0;
    }

    do {
        node->unk_24++;

        if (node->unk_24 > 3) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    } while (node != 0);

    m4aSongNumStart(0x79);
    work[0x4EE]--;
    *(s32*)&work[0x498] -= 0x300;

    if (*(s32*)&work[0x498] < 0x2800) {
        *(s32*)&work[0x498] = 0x2800;
    }

    return 1;
}

UnkStruct_0808E890* func_080A6AE8(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        if (*(s16*)&work[0x4C8] == node->unk_22 &&
            *(s16*)&work[0x4CA] == node->unk_24) {
            return node;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

INCLUDE_ASM("card/func_080A6B40.s");

void func_080A6BB4(u8* work) {
    u16 t;

    switch (work[0x4E6]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        AnimStart(&work[0x444], 0, 1);
        *(u16*)&work[0x4C6] &= ~1;
        break;
    case 1:
    case 3:
        AnimStart(&work[0x444], 2, 1);
        t = *(u16*)&work[0x4C6] | 1;
        *(u16*)&work[0x4C6] = t;
        break;
    }
}

#ifndef VERSION_EU
void func_080A6C50(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = func_08085B38(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
        base = GetBgCharBase(1);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(1);
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
}
#else
INCLUDE_ASM("card/func_080A6C50.s");
#endif

void func_080A6D0C(void) {
    u8 d[3];
    u8 e[3];
    u16 a;
    u16 b;
    u32 base;

    a = func_08084BF0();
    b = func_08084BAC();
    d[0] = a / 100;
    d[1] = a / 10 - d[0] * 10;
    d[2] = a - d[0] * 100 - d[1] * 10;
    e[0] = b / 100;
    e[1] = b / 10 - e[0] * 10;
    e[2] = b - e[0] * 100 - e[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_080A6E3C(u8* work) {
    func_08065AE0(&work[0x30], 8);
    func_08065AE0(&work[0x70], 8);
    func_08065AE0(&work[0xB0], 8);
    work[0x4FA] = func_08065B6C(func_080857BC(0), &work[0x30]);
    work[0x4FB] = func_08065B6C(func_080857BC(1), &work[0x70]);
    work[0x4FC] = func_08065B6C(func_080857BC(2), &work[0xB0]);
}

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("card/func_080A6EB4.s");
#endif

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
    if (func_08085770(GetActiveDeckIndex()) > gGameState.cp) {
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

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
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
#ifndef VERSION_EU
INCLUDE_ASM("card/deckexchange_0.s");
u8 deckexchange_1(u8* work, void* a) {
    func_08006120(0, 16);

    switch (work[0x715]) {
    case 0:
        func_0800443C(GetBgCharBase(0), 0x1000);
        break;
    case 1:
        func_0800443C(GetBgCharBase(0) + 0x1000, 0x1000);
        break;
    case 2:
        func_0800443C(GetBgCharBase(0) + 0x2000, 0x1000);
        break;
    case 3:
        func_0800443C(GetBgCharBase(0) + 0x3000, 0x1000);
        break;
    case 4:
        func_0800443C(GetBgCharBase(1), 0x1000);
        break;
    case 5:
        func_0800443C(GetBgCharBase(1) + 0x1000, 0x1000);
        break;
    case 6:
        func_0800443C(GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 7:
        func_0800443C(GetBgCharBase(1) + 0x3000, 0x1000);
        break;
    case 8:
        func_0800443C(GetBgCharBase(2), 0x1000);
        break;
    case 9:
        func_0800443C(GetBgCharBase(2) + 0x1000, 0x1000);
        break;
    case 10:
        func_0800443C(GetBgCharBase(2) + 0x2000, 0x1000);
        break;
    case 11:
        func_0800443C(GetBgCharBase(2) + 0x3000, 0x1000);
        break;
    case 12:
        func_0800443C(GetBgCharBase(3), 0x1000);
        break;
    case 13:
        func_0800443C(GetBgCharBase(3) + 0x1000, 0x1000);
        break;
    case 14:
        func_0800443C(GetBgCharBase(3) + 0x2000, 0x1000);
        break;
    case 15:
        func_0800443C(GetBgCharBase(3) + 0x3000, 0x1000);
        work[0x715] = 0;
        SetTaskUpdate(a, (void*)func_080A7914);
        return 1;
    }

    work[0x715]++;
}
u8 func_080A7ABC(u8* work, void* a);

u8 func_080A7914(u8* work, void* a) {
    func_08006120(0, 16);

    switch (work[0x715]) {
    case 0:
        LoadBgTiles(3, gUnk_09402F78, 0x2000);
        break;
    case 1:
        RequestDma3Copy(&gUnk_09402F78[0x2000],
                        (u8*)GetBgCharBase(3) + 0x2000, 0x2000);
        break;
    case 2:
        LoadBgPalette(3, gUnk_09614118, 0x1E0);
        break;
    case 3:
        LoadBgTiles(0, gUnk_09406F78, 0xC00);
        break;
    case 4:
        LoadBgMap(0, gUnk_08125E24, 0x800);
        break;
    case 5:
        LoadBgTiles(1, &gUnk_09406F78[0xC00], 0x2000);
        break;
    case 6:
        RequestDma3Copy(&gUnk_09406F78[0x2C00],
                        (u8*)GetBgCharBase(1) + 0x2000, 0x1E20);
        break;
    case 7:
        LoadBgMap(1, gUnk_08125E24, 0x800);
        break;
    case 8:
        LoadBgTiles(2, &gUnk_09406F78[0x4A20], 0x2000);
        break;
    case 9:
        RequestDma3Copy(&gUnk_09406F78[0x6A20],
                        (u8*)GetBgCharBase(2) + 0x2000, 0x1E20);
        break;
    case 10:
        LoadBgMap(2, gUnk_08125E24, 0x800);
        break;
    case 12:
        work[0x715] = 0;
        SetTaskUpdate(a, (void*)func_080A7ABC);
        return 1;
    }

    work[0x715]++;
    SetBgScroll(0, -88, -16);
    SetBgScroll(1, -88, -64);
    SetBgScroll(2, -88, -112);
    return 1;
}
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
    SetTaskUpdate(a, (void*)func_080A8430);
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
    SetTaskUpdate(a, (void*)func_080A8C20);
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
INCLUDE_ASM("card/deckexchange_2.s");
void deckexchange_3(u8* work) {
    void** p;

    if (*(void**)&work[0x4A8] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4A8]);
    }

    if (*(void**)&work[0x4AC] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4AC]);
    }

    if (*(void**)&work[0x4B0] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4B0]);
    }

    if (*(void**)&work[0x4B4] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4B4]);
    }

    if (*(void**)&work[0x4B8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4B8]);
    }

    p = (void**)&work[0x4BC];

    if (*p != 0) {
        ReleaseObjPalette(*p);
    }

    func_080AA634((void**)work);
    ReleaseObjTiles(*(void**)&work[0]);
    ReleaseObjTiles(*(void**)&work[4]);
    ReleaseObjTiles(*(void**)&work[8]);
    ReleaseObjPalette(*(void**)&work[0xC]);
    func_08065AE0(&work[0x28], 8);
    func_08065AE0(&work[0x68], 8);
    func_08065AE0(&work[0xA8], 8);
    func_08065AE0(&work[0xE8], 30);
    func_08065AE0(&work[0x1D8], 90);
    ReleaseObjPalette(*p);
    TaskPoolDestroy(&work[0x614]);
    TaskPoolDestroy(&work[0x628]);
    func_080AAA38(work);
    **(u8**)&work[0x6FC] = 6;
}
INCLUDE_ASM("card/func_080A968C.s");

s32 func_080A97D4(u8* work, u8 kind) {
    UnkStruct_080A97D4 args;
    u16 i;
    s8 x;
    s8 y;

    x = 0;
    y = 0;

    for (i = 0; i < *(u16*)&work[0x6E0]; i++) {
        if (kind == 5) {
            if (*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) <= 77) {
                args.unk_00 = &work[0x63C];
                args.unk_04 =
                    func_080A993C(*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20));
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 1;
                args.unk_0C = 0;
                TaskCreate(&work[0x614], gUnk_09EE4B28, &args);
                x++;
            }
        } else {
            args.unk_00 = &work[0x63C];
            args.unk_04 =
                func_080A993C(*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20));

            if (gCardDefs[args.unk_04].unk_2A == kind - 1 &&
                *(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) <= 77) {
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 1;
                args.unk_0C = 0;
                TaskCreate(&work[0x614], gUnk_09EE4B28, &args);
                x++;
            }
        }

        if (x > 2) {
            x = 0;
            y++;
        }
    }

    *(s32*)&work[0x69C] = 0xA000;
    *(s32*)&work[0x6A0] = 0x2800;
    *(s16*)&work[0x6EC] = 4;
    func_080AAEEC((UnkStruct_0808C940*)work, y * 3 + x);
}

s32 func_080A993C(s32 a) {
    u32 i;

    for (i = 0; i < 950; i++) {
        if (gCardDefs[i].unk_1C == a) {
            return i;
        }
    }
}

void func_080A9968(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        node->unk_4A = 1;
        node = ListPoolNext(&node->unk_2C);
    }

    TaskPoolUpdate(&work[0x614]);
}

void func_080A99A0(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    if (*(s16*)&work[0x6EC] == 33) {
        return;
    }

    while (node != 0) {
        node->unk_24--;

        if (node->unk_24 < 0) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    }

    m4aSongNumStart(0x79);
    (*(u16*)&work[0x6EC])++;
    *(s32*)&work[0x6A0] += 0x300;

    if (*(s32*)&work[0x6A0] > 0x7C00) {
        *(s32*)&work[0x6A0] = 0x7C00;
    }

    if (work[0x714] != 0) {
        (*(u16*)&work[0x6C2])--;
    }
}

u8 func_080A9A38(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    if (node == 0) {
        *(s32*)&work[0x6A0] -= 0x300;

        if (*(s32*)&work[0x6A0] < 0x2800) {
            *(s32*)&work[0x6A0] = 0x2800;
            return 0;
        }

        return 1;
    }

    if (node->unk_24 == 0) {
        return 0;
    }

    do {
        node->unk_24++;

        if (node->unk_24 > 3) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    } while (node != 0);

    m4aSongNumStart(0x79);
    (*(u16*)&work[0x6EC])--;
    *(s32*)&work[0x6A0] -= 0x300;

    if (*(s32*)&work[0x6A0] < 0x2800) {
        *(s32*)&work[0x6A0] = 0x2800;
    }

    return 1;
}

void func_080A9AE8(u8* work) {
    u16 t;

    switch (work[0x6F0]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        AnimStart(&work[0x64C], 0, 1);
        *(u16*)&work[0x6CE] &= ~1;
        break;
    case 1:
    case 3:
        AnimStart(&work[0x64C], 2, 1);
        t = *(u16*)&work[0x6CE] | 1;
        *(u16*)&work[0x6CE] = t;
        break;
    }
}

INCLUDE_ASM("card/func_080A9B84.s");

void func_080A9E40(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = func_08085B38(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
        base = GetBgCharBase(0);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(2);
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
}

INCLUDE_ASM("card/func_080A9F08.s");
void func_080A9FF4(u8 kind) {
    u8 d[3];
    u8 e[3];
    u32 base;
    u16 n;
    u8* p;
    u8* ep;

    base = 0;
    n = func_08085770(kind);
    d[0] = n / 100;
    d[1] = n / 10 - d[0] * 10;
    d[2] = n - d[0] * 100 - d[1] * 10;
    ep = e;
    p = (u8*)&gGameState;
    ep[0] = *(s16*)(p + 0xFA) / 100;
    ep[1] = *(s16*)(p + 0xFA) / 10 - ep[0] * 10;
    ep[2] = *(s16*)(p + 0xFA) - ep[0] * 100 - ep[1] * 10;

    switch (kind) {
    case 0:
        base = GetBgCharBase(0);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(2);
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0xA0, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0xC0, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[2] + 1) * 32], (u8*)base + 0xE0, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x100, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x120, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[2] + 1) * 32], (u8*)base + 0x140, 32);
}

void func_080AA148(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0xA8;

    switch (kind) {
    case 5:
        RequestDma3Copy(gUnk_095152B8 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_095152CC + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_095152E0 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_09515338 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_0951534C + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    }
}

void func_080AA1F8(void) {
    u8 d1[3];
    u8 d2[3];
    u16 a;
    u16 b;

    u32 base;

    a = func_08084BF0();
    b = func_08084BAC();

    d1[0] = a / 100;
    d1[1] = a / 10 - d1[0] * 10;
    d1[2] = a - d1[0] * 100 - d1[1] * 10;
    d2[0] = b / 100;
    d2[1] = b / 10 - d2[0] * 10;
    d2[2] = b - d2[0] * 100 - d2[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_080AA328(u8* work) {
    func_08065ACC(&work[0x28], 8);
    func_08065ACC(&work[0x68], 8);
    func_08065ACC(&work[0xA8], 8);
    work[0x702] = func_08065B6C(func_080857BC(0), &work[0x28]);
    work[0x703] = func_08065B6C(func_080857BC(1), &work[0x68]);
    work[0x704] = func_08065B6C(func_080857BC(2), &work[0xA8]);
}

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

void func_080AA680(u8* work) {
    func_080AA6D4(func_080609AC(
        func_080A993C(*(u16*)(*(u16*)&work[0x6CC] * 32 +
                              (u32)*(void**)&work[0x4CC] + 20)) +
        *(s16*)&work[0x6D0] * 5 + *(u16*)&work[0x6D2]));
}

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

void func_080AAA38(u8* work) {
    u16 i;

    if (*(void**)&work[0x4CC] != 0) {
        for (i = 0; i < *(u16*)&work[0x6E0]; i++) {
            EwramFree(*(void**)(*(u8**)&work[0x4CC] + i * 32 + 28));
        }

        EwramFree(*(void**)&work[0x4CC]);
        *(void**)&work[0x4CC] = 0;
    }
}

void func_080AAA8C(u8* work, u8 kind) {
    switch (kind) {
    case 0:
        func_08002A10(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x664], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x664], 0, 1);
        *(void**)&work[0x4EC] = AnimGetGfx(&work[0x664]);
        break;
    case 1:
        func_08002A10(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x664], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x664], 0, 1);
        *(void**)&work[0x4EC] = AnimGetGfx(&work[0x664]);
        break;
    }
}

INCLUDE_ASM("card/func_080AAB08.s");

s32 func_080AAC40(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gGameState.cp) {
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

void func_080AACC8(u8* work) {
    UnkStruct_0808E890* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x63C]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    *(s32*)&work[0x6A0] = 0x2800;
    *(s16*)&work[0x6EC] = 4;
}

u8 func_080AAD2C(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_22 == *(s16*)&work[0x6D0] &&
            node->unk_24 == *(s16*)&work[0x6D2]) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

u8 func_080AAD84(u8* work, u16 x, u16 y) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_22 == (s16)x && node->unk_24 == (s16)y) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

u8 func_080AADD4(u8* work, s16 x, s16 y, u16 dir) {
    UnkStruct_0808E890* n;

    for (n = ListPoolFirst(&work[0x63C]); n != 0; n = ListPoolNext(n->unk_2C)) {
        if (n->unk_22 == x && n->unk_24 == y) {
            return 1;
        }
    }

    switch (dir) {
    case 0x40:
        return func_080AADD4(work, x, y - 1, 0x40);
    case 0x80:
        return func_080AADD4(work, x, y + 1, 0x80);
    case 0x20:
        return func_080AADD4(work, x - 1, y, 0x20);
    case 0x10:
        return func_080AADD4(work, x + 1, y, 0x10);
    }

    return 0;
}

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

void func_080AAF20(u8* work) {
    s32 t;

    t = 0x5400 / (*(s16*)&work[0x6EE] - 4);
    *(s32*)&work[0x6A0] = t * (*(s16*)&work[0x6EC] - 4) + 0x2800;

    if (*(s32*)&work[0x6A0] > 0x7C00) {
        *(s32*)&work[0x6A0] = 0x7C00;
    }

    if (*(s32*)&work[0x6A0] < 0x2800) {
        *(s32*)&work[0x6A0] = 0x2800;
    }
}

void func_080AAF78(void) {
    gUnk_02034B1C = 0;
    gUnk_0203A9DC = 2048;
    TaskPoolInit(gUnk_02034B08, 1);
    TaskCreate(gUnk_02034B08, gTaskDescDeckexchange, &gUnk_02034B1C);
}
void func_080AAFB4(void) {
    if (gSystemFlags & 1) {
        func_080B31A0();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(gUnk_02034B08);
    TaskPoolDraw(gUnk_02034B08);

    if (gUnk_02034B1C == 6) {
        ModeRequest(&gModeSioChgCard, gUnk_0203A9DC);
    }
}
void func_080AB008(void) {
    TaskPoolDestroy(gUnk_02034B08);
}
#endif
void DarkPoint_0(u8* work) {
    *(void**)&work[0x00] = LoadObjTiles(gUnk_093FB6C4, 576);
    work[0x0A] = 8;
    *(s32*)&work[0x04] = -0x2000;
    func_0806BA0C(gBtlWork->unk_1C8, &work[0x0B]);
}
s32 DarkPoint_1(u8* work) {
    func_0806BA0C(gBtlWork->unk_1C8, &work[0x0B]);

    if (((s8*)work)[0x0A] > 0) {
        ApproachValue(&work[0x04], 0, (u16)((s8*)work)[0x0A]);
        work[0x0A]--;
    }

    return 1;
}
void DarkPoint_2(u8* work) {
    DrawSprite(*(s32*)&work[0x04] >> 8, 27, gUnk_09EF1298[0], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 30);

    if (work[0x0C] != 0) {
        DrawSprite((*(s32*)&work[0x04] >> 8) + 11, 30, gUnk_09EF1298[work[0x0C] + 1], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 29);
        DrawSprite((*(s32*)&work[0x04] >> 8) + 17, 30, gUnk_09EF1298[work[0x0D] + 1], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 29);
        DrawSprite((*(s32*)&work[0x04] >> 8) + 23, 30, gUnk_09EF1298[work[0x0E] + 1], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 29);
    } else if (work[0x0D] != 0) {
        DrawSprite((*(s32*)&work[0x04] >> 8) + 15, 30, gUnk_09EF1298[work[0x0D] + 1], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 29);
        DrawSprite((*(s32*)&work[0x04] >> 8) + 21, 30, gUnk_09EF1298[work[0x0E] + 1], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 29);
    } else {
        DrawSprite((*(s32*)&work[0x04] >> 8) + 17, 30, gUnk_09EF1298[work[0x0E] + 1], *(void**)&work[0x00], gUnk_02039DD4->unk_054, 0, 0, 29);
    }
}
void DarkPoint_3(void** p) {
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

void func_080AB22C(u8 a) {
    func_080AB1F8(a, 0);
    func_080AB1F8(a, 1);
    func_080AB1F8(a, 2);
    func_080AB1F8(a, 3);
    func_080AB1F8(a, 4);
    func_080AB1F8(a, 5);
    func_080AB1F8(a, 6);
    func_080AB1F8(a, 7);
    func_080AB1F8(a, 8);
    func_080AB1F8(a, 9);
    func_080AB1F8(a, 73);
    func_080AB1F8(a, 74);
    func_080AB1F8(a, 75);
    func_080AB1F8(a, 76);
    func_080AB1F8(a, 77);
    func_080AB1F8(a, 78);
    func_080AB1F8(a, 79);
    func_080AB1F8(a, 80);
    func_080AB1F8(a, 81);
    func_080AB1F8(a, 82);
    func_080AB1F8(a, 83);
    func_080AB1F8(a, 84);
    func_080AB1F8(a, 85);
    func_080AB1F8(a, 86);
    func_080AB1F8(a, 87);
    func_080AB1F8(a, 88);
    func_080AB1F8(a, 89);
    func_080AB1F8(a, 90);
    func_080AB1F8(a, 91);
    func_080AB1F8(a, 92);
    func_080AB1F8(a, 93);
}

void func_080AB334(u8 a) {
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(7));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(3));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(6));
    func_080AB1F8(a, func_08084458(7));
    func_080AB1F8(a, func_08084458(6));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(3));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(186));
    func_080AB1F8(a, func_08084458(185));
    func_080AB1F8(a, func_08084458(207));
    func_080AB1F8(a, func_08084458(205));
}

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
void Mode_riku_btlTutorial_1(void) {
    u16 t;

    t = gGameState.unk_17A | 0x1000;
    gGameState.unk_17A = t;
    ModeRequest(&gModeBattle, (s32)gUnk_02034B34);
    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}

void Mode_riku_deckTutorial_1(void) {
    if (!func_08006314()) {
        switch (gUnk_0203A9E0) {
        case 0:
            if (!func_080A42C8() && gUnk_0203A9E0 == 0) {
                func_080A4188(gUnk_02034B20, 0xB1);
                gUnk_0203A9E0 = 1;
            }
            break;
        case 1:
            if (!func_080A42C8()) {
                gGameState.unk_17A |= 0x800;
                ModeRequest(&gUnk_09EE2704, (s32)gUnk_02034B34);
            }
            break;
        }
    }

    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}

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

#ifndef VERSION_EU
s32 func_080ADE2C(UnkStruct_02034AAC** p, u8 b, u16 c, u16 d, u8 e) {
    if (p[0]->unk_48->unk_1C == c && p[1]->unk_48->unk_1C == d &&
        p[2]->unk_48->unk_2A == e && !(p[2]->unk_48->unk_1E & 4)) {
        return 1;
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_080ADE2C.s");
#endif

#ifndef VERSION_EU
s32 func_080ADE78(UnkStruct_02034AAC** p, u8 b, u16 c, u16 d) {
    if (p[0]->unk_48->unk_1C == c && p[1]->unk_48->unk_1C == d &&
        (p[2]->unk_48->unk_1E & 4)) {
        return 1;
    }

    return 0;
}
#else
INCLUDE_ASM("card/func_080ADE78.s");
#endif

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

#ifndef VERSION_EU
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
#endif

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
INCLUDE_ASM("card/mode_sio_battle_0.s");
INCLUDE_ASM("card/mode_sio_battle_1.s");

void mode_sio_battle_2(void) {
    ReleaseObjTiles(gUnk_02034B38[5]);
    ReleaseObjPalette(gUnk_02034B38[6]);
    ReleaseObjTiles(gUnk_02034B38[10]);
    ReleaseObjPalette(gUnk_02034B38[11]);
    ReleaseObjTiles(gUnk_02034B38[13]);
    ReleaseObjPalette(gUnk_02034B38[14]);
    ReleaseObjTiles(gUnk_02034B38[16]);
    ReleaseObjPalette(gUnk_02034B38[17]);
    EwramFree(gUnk_02034B38);
}

void func_080AEB94(void) {
    gUnk_0203A9E8 = 0;
}
