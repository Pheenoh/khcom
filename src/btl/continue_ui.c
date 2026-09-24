#include "continue_ui.h"
#include "system_state.h"
#include "anim.h"
#include "types.h"
#include "bg_animation_data.h"
#include "card_label_sprite_data.h"
#include "card_reload_sprite_data.h"
#include "mode_battle_data.h"
#include "engine_math.h"
#include "display.h"
#include "fade.h"
#include "obj_api.h"
#include "pallet.h"
#include "key.h"
#include "m4a_song.h"
#include "sprites_continue.h"

extern u8 gUnk_08F683A4[];
extern u8 gUnk_090A6B26[];
extern u8 gUnk_090A7D9A[];
extern u8 gUnk_090A7F0A[];
extern u8 gUnk_090A8FC4[];
extern u8 gUnk_096145D8[];
extern u8 gUnk_09614618[];
extern u8 gUnk_09614658[];
extern u8 gUnk_096146F8[];
extern u8 gUnk_09618118[];

const s32 gUnk_08F7DAFC[2] = {
    0x4000, 0x5600,
};

#ifdef VERSION_EU
extern u8 gUnkEu_0954C7B4[];
extern u8 gUnkEu_0954D7A0[];
extern u8 gUnkEu_0954D238[];
extern u8 gUnkEu_0954CD1C[];

void* gUnkEu_09F5D7E4[5] = {
    gUnk_0941A418,
    gUnkEu_0954C7B4,
    gUnkEu_0954D7A0,
    gUnkEu_0954D238,
    gUnkEu_0954CD1C,
};
#endif

void func_0806CD30(s32 a) {
    switch (a) {
    case 0:
        LoadBgPalette(0, gUnk_096145D8, 0x40);
        break;
    case 1:
        LoadBgPalette(0, gUnk_09614618, 0x40);
        break;
    }
}
#ifdef VERSION_JP
#define MSG_CONT_BG_TILES 0x1A40
#define MSG_CONT_X 0xA400
#else
#define MSG_CONT_BG_TILES 0x1AA0
#define MSG_CONT_X 0xBC00
#endif

void func_0806CD60(ContinueWork* p) {
    u8 i;

    SetBgMode1();
    p->unk_60 = 0;
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 0, 31, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(2, 0);
    SetBgPriority(0, 1);
    SetBgPriority(1, 2);
#ifdef VERSION_EU
    eu_080059D4(0, gUnkEu_09F5D7E4[gLanguage]);
    eu_080059F4(0, gUnk_0951CAB8);
#else
    LoadBgTiles(0, gUnk_0941A418, MSG_CONT_BG_TILES);
    LoadBgMap(0, gUnk_0951CAB8, 0x800);
#endif
    BgAnimInit(2, 0x8000, 128);
    BgAnimStart(&gUnk_09EDA7E0, 120, 46);
    BgAnimSetLoopStartFrame(0);
    p->tiles3 = LoadObjTiles(gUnk_090A7D9A, 192);
    p->palette3 = LoadObjPalette(gUnk_096146F8, 32);
    func_0806CD30(p->unk_60);
    p->tiles = AllocObjTiles(512, 0);
    PushPaletteEffect(0);
    p->palette = LoadObjPalette(gUnk_09614658, 160);
    PopPaletteEffect();
    SetObjTileSource(p->tiles, gUnk_090A6B26);
    AnimInit(&p->anim, gUnk_09EEB108, gUnk_09EEB0C4);
    AnimStart(&p->anim, 0, 1);
    p->tiles2 = AllocObjTiles(1024, 0);
    p->palette2 = LoadObjPalette(gUnk_08F683A4, 32);
    SetObjTileSource(p->tiles2, gUnk_090A7F0A);
    AnimInit(&p->anim2, gUnk_09EEB14C, gUnk_09EEB11C);
    AnimStart(&p->anim2, 0, 1);
    p->unk_58 = -2048;
    p->unk_5C = 0xA000;
    p->unk_6B = 16;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
        p->x = 0xBC00;
        break;
    case 2:
    case 3:
        p->x = 0xC000;
        break;
    }
#else
    p->x = MSG_CONT_X;
#endif
    p->y = 0x4000;
    p->unk_64 = 0;
    p->unk_66 = 0;
    FadeStartIn(1, 24);

    for (i = 0; i < 5; i++) {
        FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + i, 0);
    }
    p->unk_66 = 0x1000;
    p->unk_6A = 0;
}
void func_0806CF04(ContinueWork* p) {
    u8 i;

    SetBgMode1();
    p->unk_60 = 0;
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 0, 31, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(2, 0);
    SetBgPriority(0, 1);
    SetBgPriority(1, 2);
#ifdef VERSION_EU
    eu_080059D4(0, gUnkEu_09F5D7E4[gLanguage]);
    eu_080059F4(0, gUnk_0951CAB8);
#else
    LoadBgTiles(0, gUnk_0941A418, MSG_CONT_BG_TILES);
    LoadBgMap(0, gUnk_0951CAB8, 0x800);
#endif
    BgAnimInit(2, 0x8000, 128);
    BgAnimStart(&gUnk_09EDA7E0, 120, 46);
    BgAnimSetLoopStartFrame(0);
    p->tiles3 = LoadObjTiles(gUnk_090A7D9A, 192);
    p->palette3 = LoadObjPalette(gUnk_096146F8, 32);
    func_0806CD30(p->unk_60);
    p->tiles = AllocObjTiles(512, 0);
    PushPaletteEffect(0);
    p->palette = LoadObjPalette(gUnk_09614658, 160);
    PopPaletteEffect();
    SetObjTileSource(p->tiles, gUnk_090A6B26);
    AnimInit(&p->anim, gUnk_09EEB108, gUnk_09EEB0C4);
    AnimStart(&p->anim, 0, 1);
    p->tiles2 = AllocObjTiles(1024, 0);
    p->palette2 = LoadObjPalette(gUnk_09618118, 32);
    SetObjTileSource(p->tiles2, gUnk_090A8FC4);
    AnimInit(&p->anim2, gUnk_09EEB180, gUnk_09EEB150);
    AnimStart(&p->anim2, 0, 1);
    p->unk_58 = -2048;
    p->unk_5C = 0xA000;
    p->unk_6B = 16;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
        p->x = 0xBC00;
        break;
    case 2:
    case 3:
        p->x = 0xC000;
        break;
    }
#else
    p->x = MSG_CONT_X;
#endif
    p->y = 0x4000;
    p->unk_64 = 0;
    p->unk_66 = 0;
    FadeStartIn(1, 24);

    for (i = 0; i < 5; i++) {
        FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + i, 0);
    }
    p->unk_66 = 0x1000;
    p->unk_6A = 0;
}
static s32 Continue_1(ContinueWork* p) {
    const s32* t;

    BgAnimUpdate();
    p->gfx = AnimUpdate(&p->anim);
    p->gfx2 = AnimUpdate(&p->anim2);
    gBldCnt = (BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG3);
    (*(volatile u16*)&gBldAlpha) = p->unk_66;

    if (p->unk_6A == 0) {
        if (FadeIsActive() == 0) {
            p->unk_6A = 1;
        }
    }

    if (p->unk_6A == 1) {
        if (p->unk_6B > 0) {
            ApproachValue(&p->unk_58, 0, p->unk_6B);
            ApproachValue(&p->unk_5C, 0x9800, p->unk_6B);
            p->unk_6B--;
        }

        if (p->unk_66 < 0x1010) {
            p->unk_66++;
        } else {
            p->unk_66 = 0x1010;
        }

        if ((GetKeysPressed() & DPAD_UP) != 0) {
            if (p->unk_60 == 1) {
                p->unk_60 = 0;
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        if ((GetKeysPressed() & DPAD_DOWN) != 0) {
            if (p->unk_60 == 0) {
                p->unk_60 = 1;
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        if ((GetKeysHeld() & A_BUTTON) != 0) {
            switch (p->unk_60) {
            case 0:
                FadeStartOut(0, 96);
                break;
            case 1:
                FadeStartOut(0, 96);
                break;
            }

            m4aSongNumStart(SONG_SYS_KETTEI);
            p->unk_6A = 2;
            p->unk_6B = 16;
        }
    }

    if (p->unk_6A == 2) {
        if (p->unk_6B > 0) {
            ApproachValue(&p->unk_58, -2048, p->unk_6B);
            ApproachValue(&p->unk_5C, 0xA000, p->unk_6B);
            p->unk_6B--;
        }

        if (p->unk_66 > 0x1000) {
            p->unk_66--;
        } else {
            p->unk_66 = 0x1000;
        }

        if (FadeIsActive() == 0) {
            DisableBg(0);
            DisableBg(2);
            LoadBgMap(0, gUnk_08125E24, 0x800);
            LoadBgMap(2, gUnk_08125E24, 0x800);
            p->unk_6A = 3;
        }
    }

    func_0806CD30(p->unk_60);
    t = gUnk_08F7DAFC;
    p->y += (t[p->unk_60] - p->y) >> 3;
    p->unk_64 += 4;
}
static void Continue_2(ContinueWork* p) {
    DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, 0, 4, 100);
    DrawSprite(120, 120, p->gfx2, p->tiles2, p->palette2, 0, 0, 100);
}
static void Continue_3(ContinueWork* p) {
    DisableBg(0);
    DisableBg(2);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    ReleaseObjTiles(p->tiles2);
    ReleaseObjPalette(p->palette2);
    ReleaseObjPalette(p->palette);
    ReleaseObjTiles(p->tiles);
    ReleaseObjTiles(p->tiles3);
    ReleaseObjPalette(p->palette3);
    gBldCnt = 0;
}
TaskDesc gUnk_09EE2834 = {
    "Continue",
    (TaskInitFunc)func_0806CD60,
    (TaskUpdateFunc)Continue_1,
    (TaskFunc)Continue_2,
    (TaskFunc)Continue_3,
    0x6C,
};

TaskDesc gUnk_09EE284C = {
    "Continue",
    (TaskInitFunc)func_0806CF04,
    (TaskUpdateFunc)Continue_1,
    (TaskFunc)Continue_2,
    (TaskFunc)Continue_3,
    0x6C,
};
