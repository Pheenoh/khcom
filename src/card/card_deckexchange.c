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
#include "sprites_deck_menu.h"

#ifndef VERSION_EU
u16 gUnk_0203A9DC EWRAM_COMMON(4);
#endif

u16 func_080857D4(u8 slot);
u8 func_080A8C20(u8* work);
u8 func_080A86F4(UnkStruct_0808C940* w, void* a);
u8 func_080A7C80(u8* work, void* a);
u8 func_080A8BD8(u8* work, void* a);
void func_0808CC58(u16 a, u8 b);
u8 func_080A8430(UnkStruct_0808C940* w, void* a);
void func_08090170(DeckCard2Work* node);
void func_080A9968(u8* work);
void func_080AA6D4(u8 a);
void func_080AAEB0(u8* work, u16 index);
void func_080AAEEC(UnkStruct_0808C940* w, s16 n);
u8 func_080A7914(u8* work, void* a);
void func_0808DD20(u8 a, u16 b);
s32 func_080AAB08(UnkStruct_080AAB08* w);
void func_0808CBB4(u8 a, u8 b);
void func_080A9F08(u8 a);
void func_080AA1F8(void);
u8 func_080A82E0(UnkStruct_080A82E0* work, void* a);
u16 CountCollectionCards(void);
u16 CountCardsInDecks(void);
void func_08084D78(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p);
u16 func_08084E50(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p);
void func_0808500C(u8 mode, u16* out);
void ClearCardCollectionSlot(u16* p);
Deck* GetDeck(u8 index);
u16 GetDeckCpCost(u8 index);
u8* GetDeckName(u8 index);
u16 func_080857D4(u8 slot);
u16 GetDeckCardCount(u8 index);
u8 GetActiveDeckIndex(void);
void func_0808CBB4(u8 a, u8 b);
void func_0808CC58(u16 a, u8 b);
void func_0808DD20(u8 a, u16 b);
void func_08090170(DeckCard2Work* node);
#ifndef VERSION_EU
void deckexchange_0(u8* work, void* a) {
    s32 zero;
    u16 n;

    zero = 0;
    CpuSet((void*)&zero, work, 0x050001C6);
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0x10] = 0;
    *(s32*)&work[0x14] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x20] = 0;
    *(s32*)&work[0x24] = 0;
    *(s32*)&work[0x4A8] = 0;
    *(s32*)&work[0x4B4] = 0;
    *(s32*)&work[0x4B8] = 0;
    *(s32*)&work[0x4BC] = 0;
    *(s32*)&work[0x4C0] = 0;
    *(s32*)&work[0x4C4] = 0;
    *(s32*)&work[0x4CC] = 0;
    *(void**)&work[0x6FC] = a;
    SetBgMode0();
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 3, 31, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(3, 0, 30, 0);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    FadeStartIn(0, 16);
    ListPoolInit(&work[0x63C]);
    TaskPoolInit((TaskPool*)&work[0x614], 99);
    TaskPoolInit((TaskPool*)&work[0x628], 1);
    work[0x700] = GetActiveDeckIndex();
    func_080A968C(work, 0);
    *(void**)&work[0x00] = AllocObjTiles(0x120, 0);
    SetObjTileSource(*(void**)&work[0x00], gUnk_090A4664);
    AnimInit((AnimState*)&work[0x64C], gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)&work[0x64C], 0, 1);
    *(void**)&work[0x4E8] = AnimGetGfx((AnimState*)&work[0x64C]);
    *(s32*)&work[0x694] = gUnk_09041F04[0] << 8;
    *(s32*)&work[0x698] = gUnk_09041F0A[0] << 8;
    *(u16*)&work[0x6CE] = 0;
    *(void**)&work[0x08] = LoadObjTiles(gUnk_090A44C4, 32);
    *(void**)&work[0x0C] = LoadObjPalette(gUnk_09614418, 32);
    *(void**)&work[0x04] = AllocObjTiles(0x280, 0);
    func_080AAA8C(work, 0);
    *(void**)&work[0x4BC] = LoadObjPalette(gUnk_09614438, 32);
    work[0x715] = 0;
    *(u16*)&work[0x6D0] = 0;
    *(u16*)&work[0x6D2] = 0;
    work[0x6F2] = 0;
    work[0x6F3] = 0;
    work[0x6F6] = 4;
    work[0x707] = 0;
    work[0x706] = 0;
    work[0x6F0] = 0;
    work[0x6F7] = func_080857D4(0);
    work[0x6F8] = func_080857D4(1);
    work[0x6F9] = func_080857D4(2);
    work[0x6FA] = func_080857D4(3);
    work[0x701] = 0;
    *(u16*)&work[0x6E0] = 0;
    work[0x70D] = 0;
    work[0x710] = 0;
    work[0x711] = 16;
    work[0x712] = 16;
    *(s32*)&work[0x6A4] = 0;
    *(s32*)&work[0x6AC] = -0x800;
    *(s32*)&work[0x6A8] = 0;
    *(s32*)&work[0x6B0] = 0xA000;
    *(s32*)&work[0x6B4] = -0x8000;
    work[0x714] = 0;
    *(u16*)&work[0x708] = 8;
    *(u16*)&work[0x70A] = 113;
    work[0x70C] = 0;
    *(u16*)&work[0x6C4] = 79;
    n = gUnk_09041F3E[work[0x700]];
    *(u16*)&work[0x6C6] = n;
    *(u16*)&work[0x6C8] = 225;
    n = gUnk_09041F3E[work[0x700]];
    *(u16*)&work[0x6CA] = n;
    work[0x70F] = 0;
    work[0x713] = 0;
    work[0x702] = 0;
    work[0x703] = 0;
    work[0x704] = 0;
    work[0x705] = 0;
    InitTextSlots((TextSlot*)&work[0x28], 8);
    InitTextSlots((TextSlot*)&work[0x68], 8);
    InitTextSlots((TextSlot*)&work[0xA8], 8);
    InitTextSlots((TextSlot*)&work[0xE8], 30);
    InitTextSlots((TextSlot*)&work[0x1D8], 90);
}
u8 deckexchange_1(u8* work, void* a) {
    FadeStartIn(0, 16);

    switch (work[0x715]) {
    case 0:
        RequestDma3Clear(GetBgCharBase(0), 0x1000);
        break;
    case 1:
        RequestDma3Clear(GetBgCharBase(0) + 0x1000, 0x1000);
        break;
    case 2:
        RequestDma3Clear(GetBgCharBase(0) + 0x2000, 0x1000);
        break;
    case 3:
        RequestDma3Clear(GetBgCharBase(0) + 0x3000, 0x1000);
        break;
    case 4:
        RequestDma3Clear(GetBgCharBase(1), 0x1000);
        break;
    case 5:
        RequestDma3Clear(GetBgCharBase(1) + 0x1000, 0x1000);
        break;
    case 6:
        RequestDma3Clear(GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 7:
        RequestDma3Clear(GetBgCharBase(1) + 0x3000, 0x1000);
        break;
    case 8:
        RequestDma3Clear(GetBgCharBase(2), 0x1000);
        break;
    case 9:
        RequestDma3Clear(GetBgCharBase(2) + 0x1000, 0x1000);
        break;
    case 10:
        RequestDma3Clear(GetBgCharBase(2) + 0x2000, 0x1000);
        break;
    case 11:
        RequestDma3Clear(GetBgCharBase(2) + 0x3000, 0x1000);
        break;
    case 12:
        RequestDma3Clear(GetBgCharBase(3), 0x1000);
        break;
    case 13:
        RequestDma3Clear(GetBgCharBase(3) + 0x1000, 0x1000);
        break;
    case 14:
        RequestDma3Clear(GetBgCharBase(3) + 0x2000, 0x1000);
        break;
    case 15:
        RequestDma3Clear(GetBgCharBase(3) + 0x3000, 0x1000);
        work[0x715] = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A7914);
        return 1;
    }

    work[0x715]++;
}

u8 func_080A7914(u8* work, void* a) {
    FadeStartIn(0, 16);

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
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A7ABC);
        return 1;
    }

    work[0x715]++;
    SetBgScroll(0, (u16)-88, (u16)-16);
    SetBgScroll(1, (u16)-88, (u16)-64);
    SetBgScroll(2, (u16)-88, (u16)-112);
    return 1;
}
u8 func_080A7ABC(UnkStruct_0808C940* w, void* a) {
    s32 v;

    FadeStartIn(0, 16);

    switch (w->unk_715) {
    case 1:
        LoadBgMap(0, &gUnk_095192B8[0x800], 0x180);
        break;
    case 2:
        LoadBgMap(1, &gUnk_095192B8[0x1000], 0x180);
        break;
    case 3:
        LoadBgMap(2, &gUnk_095192B8[0x1800], 0x180);
        break;
    case 4:
        func_0808CBB4(w->unk_6F7, 0);
        break;
    case 5:
        func_0808CBB4(w->unk_6F8, 1);
        break;
    case 6:
        func_0808CBB4(w->unk_6F9, 2);
        break;
    case 7:
        func_0808CBB4(w->unk_6FA, 3);
        break;
    case 8:
        func_080A9B84(w, w->unk_700);
        break;
    case 9:
        func_080A9E40(0);
        func_080A9E40(1);
        func_080A9E40(2);
        break;
    case 10:
        func_080A9F08(GetActiveDeckIndex());
        func_080AA1F8();
        w->x = 0x4800;
        w->y = 0x2800;
        v = w->unk_700;
        w->unk_6D2 = v;
        ApproachValue(&w->x2, gUnk_09041F04[w->unk_6D0] << 8, w->unk_6F6);
        ApproachValue(&w->y2, gUnk_09041F0A[w->unk_6D2] << 8, w->unk_6F6);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A82E0);
        w->unk_6F0 = 1;
        func_080A9AE8((u8*)w);
        func_080AA328((u8*)w);
        break;
    }

    w->unk_715++;
    return 1;
}

u8 func_080A7C80(u8* work, void* a) {
    u8 n;
    s32 m;

    if (work[0x70D] != 0) {
        TaskPoolUpdate((TaskPool*)&work[0x614]);
        TaskPoolUpdate((TaskPool*)&work[0x628]);

        if (GetKeysPressed() & START_BUTTON) {
            work[0x710] = 1;
        }

        return 1;
    }

    if (work[0x710] != 0) {
        if ((u8)func_080AAC40(work) != 0 && (u8)func_080AAC8C(work) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_080A8C20);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        work[0x710] = 0;
    }

    *(void**)&work[0x4E8] = AnimUpdate((AnimState*)&work[0x64C]);
    *(void**)&work[0x4EC] = AnimUpdate((AnimState*)&work[0x664]);

    switch (GetKeysRepeat()) {
    case DPAD_LEFT:
        if (*(s16*)&work[0x6D0] > 0) {
            (*(s16*)&work[0x6D0])--;
            work[0x6F6] = 4;

            if ((u8)func_080AA77C(work, 32) != 0) {
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        func_080AA680(work);
        break;
    case DPAD_RIGHT:
        if (*(s16*)&work[0x6D0] <= 0) {
            (*(s16*)&work[0x6D0])++;
            work[0x6F6] = 4;

            if ((u8)func_080AA77C(work, 16) != 0) {
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        func_080AA680(work);
        break;
    case DPAD_UP:
        n = work[0x6D2];

        if (*(s16*)&work[0x6D2] > 0) {
            (*(s16*)&work[0x6D2])--;
        }

        work[0x6F6] = 4;
        func_080AA77C(work, 64);

        if ((s8)n != *(s16*)&work[0x6D2]) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        func_080AA680(work);
        break;
    case DPAD_DOWN:
        n = work[0x6D2];

        if (*(s16*)&work[0x6D2] <= 3) {
            (*(s16*)&work[0x6D2])++;
        }

        work[0x6F6] = 4;
        func_080AA77C(work, 128);

        if ((s8)n != *(s16*)&work[0x6D2]) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        func_080AA680(work);
        break;
    }

    switch (GetKeysPressed()) {
    case B_BUTTON:
        func_080AAA8C(work, 0);
        m = (s8)work[0x6F4];
        *(s16*)&work[0x6D0] = m;
        m = (s8)work[0x6F5];
        *(s16*)&work[0x6D2] = m;
        *(s32*)&work[0x694] = gUnk_0903595E[*(s16*)&work[0x6D0]] << 8;
        *(s32*)&work[0x698] = gUnk_09035964[*(s16*)&work[0x6D2]] << 8;
        func_080AA450(work);
        work[0x6F0] = 9;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A86F4);
        return 1;
    case A_BUTTON:
        if ((u8)func_080AAB08((UnkStruct_080AAB08*)work) == 0) {
            return 1;
        }

        func_080AA1F8();
        func_0808500C(3, (u16*)&work[0x6E2]);
        func_0808CC58(*(u16*)&work[0x6E2], 0);
        func_0808CC58(*(u16*)&work[0x6E4], 1);
        func_0808CC58(*(u16*)&work[0x6E6], 2);
        func_0808CC58(*(u16*)&work[0x6E8], 3);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A8BD8);
        func_080AA680(work);
        work[0x6F6] = 4;
        break;
    case START_BUTTON:
        if ((u8)func_080AAC40(work) != 0 && (u8)func_080AAC8C(work) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_080A8C20);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
        }

        return 1;
    }

    if (work[0x6F6] != 0) {
        ApproachValue((s32*)&work[0x694], gUnk_09041F30[*(s16*)&work[0x6D0]] << 8, work[0x6F6]);
        ApproachValue((s32*)&work[0x698], (gUnk_09041F34[*(s16*)&work[0x6D2]] - 16) << 8, work[0x6F6]);
        work[0x6F6]--;
    }

    TaskPoolUpdate((TaskPool*)&work[0x614]);
    TaskPoolUpdate((TaskPool*)&work[0x628]);
    return 1;
}

u8 func_080A8020(UnkStruct_0808C940* w, void* a) {
    s32 i;

    w->gfx = AnimUpdate(&w->anim);
    switch (GetKeysRepeat()) {
    case DPAD_LEFT:
        if (w->unk_6D0 > 1) {
            w->unk_6D0--;
            w->unk_6F6 = 4;
            m4aSongNumStart(SONG_SYS_CLICK);
            w->unk_701 = w->unk_6D0;
            func_080AA148(w->unk_701, w->unk_706);
            func_080A9968((u8*)w);
            w->unk_716 = func_080A97D4(w, w->unk_701, 1);
        }
        for (i = 0; i < 10; i++) {
            func_0808DD20(0, i);
        }
        break;
    case DPAD_RIGHT:
        if (w->unk_6D0 < 5) {
            w->unk_6D0++;
            w->unk_6F6 = 4;
            m4aSongNumStart(SONG_SYS_CLICK);
            w->unk_701 = w->unk_6D0;
            func_080AA148(w->unk_701, w->unk_706);
            func_080A9968((u8*)w);
            w->unk_716 = func_080A97D4(w, w->unk_701, 1);
        }
        for (i = 0; i < 10; i++) {
            func_0808DD20(0, i);
        }
        break;
    case DPAD_DOWN:
        if (w->unk_716 != 0) {
            w->unk_6D0 = 0;
            w->unk_6D2 = 0;
            w->unk_6F6 = 4;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            func_080AA450((u8*)w);
            w->unk_6F0 = 9;
            SetTaskUpdate(a, func_080A86F4);
            w->x = 0xA000;
            w->y = 0x2800;
            w->unk_6EC = 4;
            return 1;
        }
        m4aSongNumStart(SONG_SYS_BEEP);
        break;
    case B_BUTTON:
        if (w->unk_716 != 0) {
            w->unk_6D0 = 0;
            w->unk_6D2 = 0;
            w->unk_6F6 = 4;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            func_080AA450((u8*)w);
            w->unk_6F0 = 9;
            SetTaskUpdate(a, func_080A86F4);
            w->x = 0xA000;
            w->y = 0x2800;
            w->unk_6EC = 4;
            return 1;
        }
        SetTaskUpdate(a, func_080A8BD8);
        m4aSongNumStart(SONG_SYS_CLOSE);
        return 1;
    case START_BUTTON:
        if ((u8)func_080AAC40((u8*)w) != 0 && (u8)func_080AAC8C((u8*)w) != 0) {
            SetTaskUpdate(a, func_080A8C20);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
        }
        return 1;
    }
    if (w->unk_6F6 != 0) {
        ApproachValue(&w->x2, gUnk_09041F1A[w->unk_6D0] << 8, w->unk_6F6);
        ApproachValue(&w->y2, 0x1E00, w->unk_6F6);
        w->unk_6F6--;
    }
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    return 1;
}
u8 func_080A82E0(UnkStruct_080A82E0* work, void* a) {
    FadeStartIn(0, 4);
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
    func_0808500C(3, work->unk_6E2);
    func_0808CC58(work->unk_6E2[0], 0);
    func_0808CC58(work->unk_6E2[1], 1);
    func_0808CC58(work->unk_6E2[2], 2);
    func_0808CC58(work->unk_6E2[3], 3);
    work->unk_6F0 = 9;
    func_080AAA8C((u8*)work, 0);
    func_080A9968((u8*)work);
    work->unk_715 = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_080A8430);
    work->unk_6C4 = 0xFFFE;
    work->unk_6C6 = 142;
    work->unk_6C8 = 142;
    work->unk_6CA = 142;
    TaskPoolUpdate(&work->tasks);
    TaskPoolUpdate(&work->tasks2);
    return 1;
}
u8 func_080A8430(UnkStruct_0808C940* w, void* a) {
    u32 zero;
    u16 i;
    u16 j;
    u16 n;

    FadeStartIn(0, 16);
    switch (w->unk_715) {
    case 0:
        w->unk_6E0 = 286;
        w->unk_4D0 = EwramAlloc(w->unk_6E0 * sizeof(UnkStruct_08084D78));
        zero = 0;
        CpuSet(&zero, w->unk_4D0, 0x05000000 | (w->unk_6E0 * 8));
        break;
    case 1:
        func_08084D78(w->unk_4D0, w->unk_700, 0, w->unk_6E0, w->unk_4F4);
        break;
    case 2:
        w->unk_6E0 = func_08084E50(w->unk_4D0, w->unk_700, 0, w->unk_6E0, w->unk_4F4);
        break;
    case 3:
        w->unk_4CC = EwramAlloc(w->unk_6E0 * sizeof(UnkStruct_08084D78));
        for (i = 0, n = 0; i < 286; i++) {
            if (w->unk_4D0[i].unk_16 != 0) {
                w->unk_4CC[n] = w->unk_4D0[i];
                w->unk_4CC[n].unk_1C = EwramAlloc(w->unk_4D0[i].unk_18 * 2);
                for (j = 0; j < w->unk_4D0[i].unk_18; j++) {
                    w->unk_4CC[n].unk_1C[j] = w->unk_4D0[i].unk_1C[j];
                }
                n++;
            }
        }
        break;
    case 4:
        for (i = 0; i < 286; i++) {
            if (w->unk_4D0[i].unk_16 != 0) {
                EwramFree(w->unk_4D0[i].unk_1C);
            }
        }
        EwramFree(w->unk_4D0);
        break;
    case 5:
        w->unk_701 = 5;
        w->unk_716 = func_080A97D4(w, 5, 1);
        func_080A9AE8((u8*)w);
        w->x2 = gUnk_0903595E[0] << 8;
        w->y2 = gUnk_09035964[0] << 8;
        w->unk_706 = 2;
        w->unk_6D0 = 0;
        w->unk_6D2 = 0;
        func_080AA450((u8*)w);
        if (w->unk_716 != 0) {
            SetTaskUpdate(a, func_080A86F4);
        } else {
            w->unk_6D0 = w->unk_701;
            w->unk_6F6 = 4;
            w->unk_6F0 = 10;
            SetTaskUpdate(a, func_080A8020);
        }
        break;
    }
    w->unk_715++;
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    return 1;
}
u8 func_080A86F4(UnkStruct_0808C940* w, void* a) {
    s32 i;

    w->gfx = AnimUpdate(&w->anim);
    w->gfx2 = AnimUpdate(&w->anim2);
    if (w->unk_70D != 0) {
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        if (GetKeysPressed() & START_BUTTON) {
            w->unk_710 = 1;
        }
        return 1;
    }
    if (w->unk_710 != 0) {
        if ((u8)func_080AAC40((u8*)w) != 0 && (u8)func_080AAC8C((u8*)w) != 0) {
            SetTaskUpdate(a, func_080A8C20);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }
        w->unk_710 = 0;
    }
    switch (GetKeysRepeat()) {
    case DPAD_UP:
        if (w->unk_6D2 > 0) {
            if ((u8)func_080AAD84(w, w->unk_6D0, (s16)(w->unk_6D2 - 1)) != 0) {
                w->unk_6D2--;
                w->unk_6F6 = 4;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
            }
        } else {
            if (func_080A9A38((u8*)w) == 0) {
                func_080AAF20(w);
                w->unk_6D0 = w->unk_701;
                w->unk_6F6 = 4;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
                w->unk_6F0 = 10;
                for (i = 0; i < 10; i++) {
                    func_0808DD20(0, i);
                }
                SetTaskUpdate(a, func_080A8020);
                return 1;
            }
            func_080AAF20(w);
        }
        func_080AA450((u8*)w);
        break;
    case DPAD_DOWN:
        if (w->unk_6D2 < 3) {
            if ((u8)func_080AAD84(w, w->unk_6D0, (s16)(w->unk_6D2 + 1)) != 0) {
                w->unk_6D2++;
                w->unk_6F6 = 4;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
            }
        } else if ((u8)func_080AAD84(w, w->unk_6D0, (s16)(w->unk_6D2 + 1)) != 0) {
            func_080A99A0(w);
            func_080AAF20(w);
        }
        func_080AA450((u8*)w);
        break;
    case DPAD_LEFT:
        if (w->unk_6D0 > 0 && (u8)func_080AAD84(w, (s16)(w->unk_6D0 - 1), w->unk_6D2) != 0) {
            w->unk_6D0--;
            w->unk_6F6 = 4;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }
        func_080AA450((u8*)w);
        break;
    case DPAD_RIGHT:
        if (w->unk_6D0 > 1) {
            w->unk_6F6 = 4;
            return 1;
        }
        if ((u8)func_080AAD84(w, (s16)(w->unk_6D0 + 1), w->unk_6D2) != 0) {
            w->unk_6D0++;
            w->unk_6F6 = 4;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }
        func_080AA450((u8*)w);
        break;
    }
    switch (GetKeysPressed()) {
    case A_BUTTON:
        if ((u8)func_080AAD2C(w) != 0) {
            w->unk_6F4 = w->unk_6D0;
            w->unk_6F5 = w->unk_6D2;
            w->unk_6D0 = 0;
            w->unk_6D2 = 0;
            func_080AAA8C((u8*)w, 1);
            w->unk_6F0 = 11;
            m4aSongNumStart(SONG_SYS_KETTEI);
            if ((u8)func_080AA77C(w, 0) != 0) {
                func_080AA680((u8*)w);
                w->x2 = gUnk_09041F30[w->unk_6D0] << 8;
                w->y2 = (gUnk_09041F34[w->unk_6D2] - 16) << 8;
                SetTaskUpdate(a, func_080A7C80);
                return 1;
            }
            w->unk_6D0 = (s8)w->unk_6F4;
            w->unk_6D2 = (s8)w->unk_6F5;
            func_080AAA8C((u8*)w, 0);
            w->unk_6F0 = 9;
            m4aSongNumStart(SONG_SYS_BEEP);
            return 1;
        }
        m4aSongNumStart(SONG_SYS_BEEP);
        return 1;
    case B_BUTTON:
        SetTaskUpdate(a, func_080A8BD8);
        m4aSongNumStart(SONG_SYS_CLOSE);
        return 1;
    case START_BUTTON:
        if ((u8)func_080AAC40((u8*)w) != 0 && (u8)func_080AAC8C((u8*)w) != 0) {
            SetTaskUpdate(a, func_080A8C20);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
        }
        return 1;
    }
    if (GetKeysPressed() & SELECT_BUTTON) {
        func_080AACC8(w);
        w->unk_6D0 = w->unk_701;
        w->unk_6F6 = 4;
        w->x = 0xA000;
        w->y = 0x2800;
        w->unk_6EC = 4;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        w->unk_6F0 = 10;
        SetTaskUpdate(a, func_080A8020);
        return 1;
    }
    if (w->unk_6F6 != 0) {
        ApproachValue(&w->x2, gUnk_0903595E[w->unk_6D0] << 8, w->unk_6F6);
        ApproachValue(&w->y2, gUnk_09035964[w->unk_6D2] << 8, w->unk_6F6);
        w->unk_6F6--;
    }
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    return 1;
}
u8 func_080A8BD8(u8* work, void* a) {
    FadeStartOut(0, 16);
    work[0x701] = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_080A8C20);
    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}
u8 func_080A8C20(u8* work) {
    if (FadeIsActive() == 0) {
        func_080A9968(work);
        return 0;
    }

    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}

void func_080A8C58(UnkStruct_0808C940* w, u8 b) {
    if (b == 0) {
        switch (w->unk_700) {
        case 0:
            DrawTextSlots(w->x4, w->y4, w->unk_28, w->palette, 20, w->unk_702);
            DrawTextSlots(w->x5, w->y5, w->unk_68, w->palette4, 20, w->unk_703);
            DrawTextSlots(w->x6, w->y6, w->unk_A8, w->palette4, 20, w->unk_704);
            break;
        case 1:
            DrawTextSlots(w->x4, w->y4, w->unk_28, w->palette4, 20, w->unk_702);
            DrawTextSlots(w->x5, w->y5, w->unk_68, w->palette, 20, w->unk_703);
            DrawTextSlots(w->x6, w->y6, w->unk_A8, w->palette4, 20, w->unk_704);
            break;
        case 2:
            DrawTextSlots(w->x4, w->y4, w->unk_28, w->palette4, 20, w->unk_702);
            DrawTextSlots(w->x5, w->y5, w->unk_68, w->palette4, 20, w->unk_703);
            DrawTextSlots(w->x6, w->y6, w->unk_A8, w->palette, 20, w->unk_704);
            break;
        }
    } else {
        switch (w->unk_700) {
        case 0:
            DrawTextSlots(w->x4, w->y4, w->unk_28, w->palette, 20, w->unk_702);
            break;
        case 1:
            DrawTextSlots(w->x5, w->y5, w->unk_68, w->palette, 20, w->unk_703);
            break;
        case 2:
            DrawTextSlots(w->x6, w->y6, w->unk_A8, w->palette, 20, w->unk_704);
            break;
        }
    }
}

void func_080A8EE4(u8* work) {
    DrawTextSlots(*(s16*)&work[0x708], *(s16*)&work[0x70A], &work[0x1D8],
                  *(void**)&work[0x0C], 20, work[0x70C]);
}
void deckexchange_2(UnkStruct_0808C940* w) {
    if (w->unk_70D == 0) {
        DrawSprite((w->x2 >> 8) - 16, (w->y2 >> 8) - 30, w->gfx, w->tiles, w->palette, 0, w->unk_6CE, 3);
    }
    DrawSprite(w->x >> 8, w->y >> 8, gUnk_09EEB000, w->tiles3, w->palette, 0, 0x800, 10);
    switch (w->unk_6F0) {
    case 0:
        if (w->unk_714 != 0) {
            DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        }
        DrawSprite((w->x2 >> 8) - 16, (w->y2 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
    case 1:
    case 2:
    case 3:
        func_080A8C58(w, 0);
        break;
    case 4:
        func_080A8C58(w, 1);
        DrawSprite((w->x2 >> 8) - 16, (w->y2 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        if (w->tiles4 != 0) {
            if (w->unk_70D == 0) {
                DrawSprite((w->x2 >> 8) - 16, (w->y2 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
            }
            DrawSprite(24, 82, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(24, 82, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            DrawTextSlots(10, 116, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    case 7:
        func_080A8C58(w, 1);
        DrawSprite((w->x2 >> 8) - 16, (w->y2 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        if (w->tiles4 != 0) {
            DrawSprite(164, 82, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(164, 82, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            if (w->tiles6 != 0) {
                DrawSprite(164, 82, w->gfx5, w->tiles6, w->palette2, 0, 0, 19);
            }
            DrawTextSlots(100, 116, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    case 5:
        DrawSprite((w->x2 >> 8) - 26, (w->y2 >> 8) - 13, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        func_080A8C58(w, 1);
        if (w->tiles4 != 0) {
            DrawSprite(24, 82, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(24, 82, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            DrawTextSlots(10, 116, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    case 6:
        func_080A8C58(w, 1);
        if (w->tiles4 != 0) {
            DrawSprite(24, 82, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(24, 82, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            DrawTextSlots(10, 116, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    case 8:
        func_080A8C58(w, 1);
        if (w->tiles4 != 0) {
            DrawSprite(164, 82, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(164, 82, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            if (w->tiles6 != 0) {
                DrawSprite(164, 82, w->gfx5, w->tiles6, w->palette2, 0, 0, 19);
            }
            DrawTextSlots(100, 116, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    case 9:
        DrawSprite((w->x2 >> 8) - 16, (w->y2 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        func_080A8EE4((u8*)w);
        if (w->tiles4 != 0) {
            DrawSprite(24, 66, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(24, 66, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            DrawTextSlots(10, 100, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    case 11:
        DrawSprite((w->x2 >> 8) - 26, (w->y2 >> 8) - 13, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        func_080A8EE4((u8*)w);
        if (w->tiles4 != 0) {
            DrawSprite(24, 66, w->gfx3, w->tiles4, w->palette2, 0, 0, 20);
            DrawSprite(24, 66, w->gfx4, w->tiles5, w->palette3, 0, 0, 21);
            DrawTextSlots(10, 100, w->unk_E8, w->palette4, 20, w->unk_705);
        }
        break;
    }
    TaskPoolDraw(&w->tasks);
    TaskPoolDraw(&w->tasks2);
}
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
    FreeTextSlots(&work[0x28], 8);
    FreeTextSlots(&work[0x68], 8);
    FreeTextSlots(&work[0xA8], 8);
    FreeTextSlots(&work[0xE8], 30);
    FreeTextSlots(&work[0x1D8], 90);
    ReleaseObjPalette(*p);
    TaskPoolDestroy(&work[0x614]);
    TaskPoolDestroy(&work[0x628]);
    func_080AAA38(work);
    **(u8**)&work[0x6FC] = 6;
}
void func_080A968C(UnkStruct_0808C940* w, u8 kind) {
    DeckCard2Args args;
    u16* cards;
    u8 i;
    s8 x;
    s8 y;

    cards = GetDeck(w->unk_700)->cards;
    x = 0;
    y = 0;
    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (kind == 0) {
                args.unk_00 = &w->unk_63C;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                x++;
            } else if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == kind - 1) {
                args.unk_00 = &w->unk_63C;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                x++;
            }
            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }
    w->x = 0x4800;
    w->y = 0x2800;
    w->unk_6EC = 4;
    func_080AAEEC(w, y * 3 + x);
}

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
                args.cardId =
                    func_080A993C(*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20));
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 1;
                args.unk_0C = 0;
                TaskCreate(&work[0x614], &gTaskDescDeckCard2, &args);
                x++;
            }
        } else {
            args.unk_00 = &work[0x63C];
            args.cardId =
                func_080A993C(*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20));

            if (gCardDefs[args.cardId].unk_2A == kind - 1 &&
                *(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) <= 77) {
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 1;
                args.unk_0C = 0;
                TaskCreate(&work[0x614], &gTaskDescDeckCard2, &args);
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
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        node->unk_4A = 1;
        node = ListPoolNext(&node->node);
    }

    TaskPoolUpdate(&work[0x614]);
}

void func_080A99A0(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x63C]);

    if (*(s16*)&work[0x6EC] == 33) {
        return;
    }

    while (node != 0) {
        node->unk_24--;

        if (node->unk_24 < 0) {
            node->y = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->node);
    }

    m4aSongNumStart(SONG_SYS_CLICKI04B);
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
    DeckCard2Work* node;

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
            node->y = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->node);
    } while (node != 0);

    m4aSongNumStart(SONG_SYS_CLICKI04B);
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

void func_080A9B84(UnkStruct_0808C940* w, u8 b) {
    u16* pal;

    switch (b) {
    case 0:
        pal = (u16*)0x05000100;
        LoadPalette(gUnk_096142F8, pal, 32);
        pal = (u16*)0x05000120;
        LoadPalette(gUnk_09614118 + 0x120, pal, 32);
        pal = (u16*)0x05000140;
        LoadPalette(gUnk_09614118 + 0x140, pal, 32);
        LoadBgMap(0, gUnk_09519AB8 + 0x180, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, (u16)-76, (u16)-14);
        SetBgScroll(1, (u16)-88, (u16)-64);
        SetBgScroll(2, (u16)-88, (u16)-112);
        w->x4 = 100;
        w->y4 = 25;
        w->x5 = 102;
        w->y5 = 75;
        w->x6 = 102;
        w->y6 = 122;
        break;
    case 1:
        pal = (u16*)0x05000120;
        LoadPalette(gUnk_096142F8, pal, 32);
        pal = (u16*)0x05000100;
        LoadPalette(gUnk_09614118 + 0x100, pal, 32);
        pal = (u16*)0x05000140;
        LoadPalette(gUnk_09614118 + 0x140, pal, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8 + 0x180, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, (u16)-88, (u16)-16);
        SetBgScroll(1, (u16)-76, (u16)-62);
        SetBgScroll(2, (u16)-88, (u16)-112);
        w->x4 = 102;
        w->y4 = 27;
        w->x5 = 100;
        w->y5 = 73;
        w->x6 = 102;
        w->y6 = 122;
        break;
    case 2:
        pal = (u16*)0x05000140;
        LoadPalette(gUnk_096142F8, pal, 32);
        pal = (u16*)0x05000100;
        LoadPalette(gUnk_09614118 + 0x100, pal, 32);
        pal = (u16*)0x05000120;
        LoadPalette(gUnk_09614118 + 0x120, pal, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8 + 0x180, 0x180);
        SetBgScroll(0, (u16)-88, (u16)-16);
        SetBgScroll(1, (u16)-88, (u16)-64);
        SetBgScroll(2, (u16)-76, (u16)-110);
        w->x4 = 102;
        w->y4 = 27;
        w->x5 = 102;
        w->y5 = 75;
        w->x6 = 100;
        w->y6 = 121;
        break;
    }
}

void func_080A9E40(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = GetDeckCardCount(deck);
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

void func_080A9F08(u8 mode) {
    u32 bg0;
    u32 bg1;
    u32 bg2;

    bg0 = GetBgCharBase(0);
    bg1 = GetBgCharBase(1);
    bg2 = GetBgCharBase(2);

    switch (mode) {
    case 0:
        RequestDma3Copy(gUnk_0940FC58, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 2:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    }
}
void func_080A9FF4(u8 kind) {
    u8 d[3];
    u8 e[3];
    u32 base;
    u16 n;
    u8* p;
    u8* ep;

    base = 0;
    n = GetDeckCpCost(kind);
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

    a = CountCardsInDecks();
    b = CountCollectionCards();

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
    InitTextSlots(&work[0x28], 8);
    InitTextSlots(&work[0x68], 8);
    InitTextSlots(&work[0xA8], 8);
    work[0x702] = LoadTextSlots(GetDeckName(0), &work[0x28]);
    work[0x703] = LoadTextSlots(GetDeckName(1), &work[0x68]);
    work[0x704] = LoadTextSlots(GetDeckName(2), &work[0xA8]);
}

void func_080AA3A0(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
    work[0x705] = LoadTextSlots(def->name, &work[0xE8]);

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->count << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->count << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->count << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->count << 5));
        break;
    }
}

void func_080AA450(u8* work) {
    DeckCard2Work* node;
    CardDef* def;
    s32 id;
    u8 i;
    u8 j;
    void* dst;

    id = 0xFFFF;
    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_24 == *(s16*)&work[0x6D2] && node->unk_22 == *(s16*)&work[0x6D0]) {
            id = node->cardId;
            break;
        }

        node = ListPoolNext(&node->node);
    }

    func_080AA634((void**)work);

    if (id != 0xFFFF) {
        def = &gCardDefs[id & CARD_ID_MASK];
        *(void**)&work[0x10] = LoadObjTiles(gUnk_08F709B0[def->unk_2A].tiles, 0x300);
        *(void**)&work[0x14] = LoadObjTiles(def->tiles, 0x200);
        *(void**)&work[0x24] = LoadObjPalette(def->palette, 32);
        *(void**)&work[0x20] = LoadObjPalette(gUnk_09611AB8, 32);
        *(void**)&work[0x4D4] = gUnk_08F709B0[def->unk_2A].gfx;
        *(void**)&work[0x4D8] = def->gfx;

        for (i = 0; i < *(u16*)&work[0x6E0]; i++) {
            if (*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) == def->unk_1C) {
                break;
            }
        }

        *(u16*)&work[0x6CC] = i;
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614118[def->unk_2A * 32 + 0x200], dst, 32);

        for (j = 0; j < 10; j++) {
            func_0808DD20((*(UnkStruct_0808E2F0**)&work[0x4CC])[i].unk_00[j], j);
        }

        func_080AA3A0(work, id);
        func_080AAEB0(work, id);

        if (def->unk_1C > 46) {
            LoadBgMap(2, gUnk_09518AB8, 0x800);
            func_080AA6D4(0);
        } else {
            LoadBgMap(2, gUnk_095182B8, 0x800);
            func_080AA6D4(0);
        }
    } else {
        for (j = 0; j < 10; j++) {
            func_0808DD20(0, j);
        }

        func_080AA6D4(0);
    }
}

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
    func_080AA6D4(GetCardCpCost(
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

s32 func_080AA77C(UnkStruct_0808C940* w, u16 key) {
    u8* tbl;
    u8 idx;
    u8 r0;
    u8 c0;
    u16 row0;
    s32 sum;
    s32 i;
    s8 d;
    s8 n;
    s32 ofs;
    s32 k;
    u8* p;

    idx = w->unk_6D0 * 5 + (u8)w->unk_6D2;
    tbl = (u8*)&w->unk_4CC[w->unk_6CC];
    row0 = w->unk_6D0;
    r0 = w->unk_6D0;
    c0 = w->unk_6D2;

    if (*(u16*)&tbl[idx << 1] != 0) {
        return 1;
    }

    switch (key) {
    case 0x40:
        do {
            if (w->unk_6D2 > 0) {
                w->unk_6D2 = w->unk_6D2 - 1;
            } else {
                w->unk_6D2 = 4;
            }

            idx = w->unk_6D0 * 5 + (u8)w->unk_6D2;

            if (w->unk_6D0 == r0 && w->unk_6D2 == c0) {
                return 0;
            }
        } while (*(u16*)&tbl[idx << 1] == 0);
        break;
    case 0x80:
        do {
            if (w->unk_6D2 <= 3) {
                w->unk_6D2 = w->unk_6D2 + 1;
            } else {
                w->unk_6D2 = 0;
            }

            idx = w->unk_6D0 * 5 + (u8)w->unk_6D2;

            if (w->unk_6D0 == r0 && w->unk_6D2 == c0) {
                return 0;
            }
        } while (*(u16*)&tbl[idx << 1] == 0);
        break;
    case 0x20:
        if (*(u16*)&tbl[w->unk_6D2 << 1] != 0) {
            if ((s16)row0 > 0) {
                w->unk_6D0 = row0 - 1;
            }

            return 1;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += *(u16*)&tbl[i * 2];
        }

        if (sum == 0) {
            w->unk_6D0 = 1;
            return 0;
        }

        p = (u8*)&w->unk_6D2;
        d = -1;
        k = *p + d;

        for (;;) {
            n = k;

            if (n < 0) {
                n = 0;
            }

            if (n > 4) {
                n = 4;
            }

            ofs = n;

            if (*(u16*)&tbl[ofs *= 2] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d++;
                d = -d;
            }

            k = *p + d;
        }

        w->unk_6D2 = n;
        break;
    case 0x10:
        if (*(u16*)&tbl[(w->unk_6D2 + 5) << 1] != 0) {
            if ((s16)row0 <= 0) {
                w->unk_6D0 = row0 + 1;
            }

            return 1;
        }

        sum = 0;

        for (i = 5; i < 10; i++) {
            sum += *(u16*)&tbl[i * 2];
        }

        if (sum == 0) {
            w->unk_6D0 = 0;
            return 0;
        }

        p = (u8*)&w->unk_6D2;
        d = -1;
        k = *p + d;

        for (;;) {
            n = k;

            if (n < 0) {
                n = 0;
            }

            if (n > 4) {
                n = 4;
            }

            ofs = n;
            ofs *= 2;

            if (*(u16*)&tbl[ofs += 10] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d++;
                d = -d;
            }

            k = *p + d;
        }

        w->unk_6D2 = n;
        break;
    case 0:
        do {
            if (w->unk_6D2 <= 3) {
                w->unk_6D2 = w->unk_6D2 + 1;
            } else {
                w->unk_6D2 = 0;
            }

            idx = w->unk_6D0 * 5 + (u8)w->unk_6D2;

            if (w->unk_6D0 == r0 && w->unk_6D2 == c0) {
                if (w->unk_6D0 <= 0) {
                    w->unk_6D0 = w->unk_6D0 + 1;
                } else {
                    w->unk_6D0 = 0;
                }

                if (func_080AA764((u16*)tbl) == 0) {
                    return 0;
                }
            }
        } while (*(u16*)&tbl[idx << 1] == 0);
        break;
    }

    return 1;
}

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
        SetObjTileSource(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x664], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x664], 0, 1);
        *(void**)&work[0x4EC] = AnimGetGfx(&work[0x664]);
        break;
    case 1:
        SetObjTileSource(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x664], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x664], 0, 1);
        *(void**)&work[0x4EC] = AnimGetGfx(&work[0x664]);
        break;
    }
}

s32 func_080AAB08(UnkStruct_080AAB08* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    s32 card;
    u16 id;
    CardDef* def;
    u16 kind;

    idx = w->unk_6D0 * 5 + w->unk_6D2;
    e = &w->unk_4CC[w->unk_6CC];
    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
        return 1;
    }
    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];
        if (card != 0xFFFF) {
            id = gCardCollection[card] & CARD_ID_MASK;
            def = &gCardDefs[id];
            if (id > 0x1C1) {
                if (idx == 0) {
                    gUnk_0203A9DC = gCardCollection[card] & CARD_ID_MASK;
                    ClearCardCollectionSlot(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[0]--;
                    func_0808DD20(e->unk_00[0], 0);
                    m4aSongNumStart(SONG_SYS_KETTEI);
                    return 1;
                }
            } else {
                kind = def->unk_20;
                if (kind == idx) {
                    gUnk_0203A9DC = gCardCollection[card] & CARD_ID_MASK;
                    ClearCardCollectionSlot(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[kind]--;
                    func_0808DD20(e->unk_00[kind], kind);
                    m4aSongNumStart(SONG_SYS_KETTEI);
                    return 1;
                }
            }
        }
    }
    m4aSongNumStart(SONG_SYS_BEEP);
    return 1;
}

s32 func_080AAC40(u8* work) {
    if (GetDeckCpCost(GetActiveDeckIndex()) > gGameState.progression.cp) {
        TaskCreate(&work[0x628], &gUnk_09EE7FA8, &work[0x70D]);
        m4aSongNumStart(SONG_SYS_BEEP);

        return 0;
    }

    return 1;
}

u8 func_080AAC8C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
        TaskCreate(&work[0x628], &gUnk_09EE7FC0, &work[0x70D]);
        return 0;
    }

    return 1;
}

void func_080AACC8(u8* work) {
    DeckCard2Work* node;
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

        node = ListPoolNext(&node->node);
    }

    *(s32*)&work[0x6A0] = 0x2800;
    *(s16*)&work[0x6EC] = 4;
}

u8 func_080AAD2C(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_22 == *(s16*)&work[0x6D0] &&
            node->unk_24 == *(s16*)&work[0x6D2]) {
            return 1;
        }

        node = ListPoolNext(&node->node);
    }

    return 0;
}

u8 func_080AAD84(u8* work, u16 x, u16 y) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_22 == (s16)x && node->unk_24 == (s16)y) {
            return 1;
        }

        node = ListPoolNext(&node->node);
    }

    return 0;
}

u8 func_080AADD4(u8* work, s16 x, s16 y, u16 dir) {
    DeckCard2Work* n;

    for (n = ListPoolFirst(&work[0x63C]); n != 0; n = ListPoolNext(&n->node)) {
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
    work[0x70C] = LoadTextSlots((void*)gUnk_09EE8F48[d->unk_1C], &work[0x1D8]);
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
#endif

#ifndef VERSION_EU
const char gTaskNameDeckexchange[] = "deckexchange";

TaskDesc gTaskDescDeckexchange = {
    gTaskNameDeckexchange,
    (TaskInitFunc)deckexchange_0,
    deckexchange_1,
    (TaskFunc)deckexchange_2,
    (TaskFunc)deckexchange_3,
    0x718,
};
#endif
