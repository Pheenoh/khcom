#include "macros.h"
#include "registration_data.h"
#include "msg_api.h"
#include "card_api.h"
#include <string.h>
#include "eventselect_api.h"
#include "m4a_song.h"
#include "fade.h"
#include "engine_math.h"
#include "listpool.h"
#include "mode_eventselect.h"
#include "gba/keys.h"
#include "sprites_evt.h"
#include "sprites_hum.h"
#include "sprites_level_up.h"
#include "sprites_smn.h"

const s16 gSoraEventIds[147] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
    36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84,
    85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
    109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126,
#ifdef VERSION_EU
    127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138,
    139, 140, 141, 142, 143, 144, 145, 146,
#else
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
    141, 142, 143, 144, 145, 146, 147, 148,
#endif
    -1,
};

const s16 gRikuEventIds[49] = {
#ifdef VERSION_EU
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158,
    159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
    171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182,
    183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
#else
    149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160,
    161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172,
    173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184,
    185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196,
#endif
    -1,
};

const char gUnk_09033ED8[] = "\x81\xa8";

const char gUnk_09033EDC[] = "\x81\x40";

const char gUnk_09033EE0[] = "\x82\x64\x82\x75\x82\x64\x82\x6d\x82\x73\x81\x40\x82\x72\x82\x6e\x82\x71\x82\x60";

const char gUnk_09033EF8[] = "\x82\x64\x82\x75\x82\x64\x82\x6d\x82\x73\x81\x40\x82\x71\x82\x68\x82\x6a\x82\x74";

const char gUnk_09033F10[] = "\x82\x6d\x82\x8f\x81\x40\x81\x81";

s16 gEventSelectIndex __attribute__((aligned(4)));
static u8 sEventSelectList;
UnkStruct_02039DD0* gUnk_02039DD0 EWRAM_COMMON(4);

s16 func_08075064(u8 a) {
    s16 n = 0;

    switch (a) {
    case 0:
        while (gSoraEventIds[n] != -1) {
            n++;
        }
        break;
    case 1:
        while (gRikuEventIds[n] != -1) {
            n++;
        }
        break;
    }
    return n;
}

void mode_eventselect_0(void) {
    SetBgMode0();
    func_08085FB0();
    func_08085C3C();
    InitMapCardInventory();
    SetupBg(0, 0, 30, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x8000, 0x800);
    func_0805FA60(0, gUnk_08F70990, 0x20, 0);
}

void mode_eventselect_1(void) {
    if (GetKeysRepeat() & DPAD_UP) {
        if (sEventSelectList != 0) {
            sEventSelectList--;
        } else {
            sEventSelectList = 1;
        }
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        if (sEventSelectList == 0) {
            sEventSelectList++;
        } else {
            sEventSelectList = 0;
        }
    }

    switch (sEventSelectList) {
    case 0:
        func_0805FCB0(0, 0, 2, gUnk_09033ED8);
        func_0805FCB0(0, 10, 2, gUnk_09033EDC);
        func_0805FCB0(0, 20, 2, gUnk_09033EDC);
        break;
    case 1:
        func_0805FCB0(0, 0, 2, gUnk_09033EDC);
        func_0805FCB0(0, 10, 2, gUnk_09033ED8);
        func_0805FCB0(0, 20, 2, gUnk_09033EDC);
        break;
    }

    if (GetKeysRepeat() & DPAD_RIGHT) {
        gEventSelectIndex++;
    }

    if (GetKeysRepeat() & DPAD_LEFT) {
        gEventSelectIndex--;
    }

    if (func_08075064(sEventSelectList) - 1 < gEventSelectIndex) {
        gEventSelectIndex = 0;
    }

    if (gEventSelectIndex < 0) {
        gEventSelectIndex = func_08075064(sEventSelectList) - 1;
    }

    func_0805FCB0(10, 0, 2, gUnk_09033EE0);
    func_0805FCB0(10, 10, 2, gUnk_09033EF8);
    func_0805FCB0(20, 40, 2, gUnk_09033F10);
    func_0805FC04(100, 40, 2, gEventSelectIndex + 1);

    switch (sEventSelectList) {
    case 0:
        func_0805FCB0(20, 80, 2, gEventNames[gSoraEventIds[gEventSelectIndex]]);
        break;
    case 1:
        func_0805FCB0(20, 80, 2, gEventNames[gRikuEventIds[gEventSelectIndex]]);
        break;
    }

    if (GetKeysPressed() & A_BUTTON) {
        switch (sEventSelectList) {
        case 0:
#ifdef VERSION_EU
            ModeRequest(&gUnkEu_09F5D6EC, gSoraEventIds[gEventSelectIndex] | 0x8000);
#else
            func_0806180C(gSoraEventIds[gEventSelectIndex]);
#endif
            break;
        case 1:
#ifdef VERSION_EU
            ModeRequest(&gUnkEu_09F5D6EC, gRikuEventIds[gEventSelectIndex] | 0x8000);
#else
            func_0806180C(gRikuEventIds[gEventSelectIndex]);
#endif
            break;
        }
    }

    if (GetKeysPressed() & B_BUTTON) {
        ModeRequest(&gModeDebug, 0);
    }

    func_080605A4(0);
    func_08060598();
}

void mode_eventselect_2(void) {
    func_080609A0();
}

void Hanabira_0(EffectWork* w, void* arg) {
    s32 i;

    TaskPoolInit(&w->tasks, 16);

    for (i = 15; i >= 0; i--) {
        TaskCreate(&w->tasks, &gTaskDescHanabiraC, arg);
    }
}

s32 Hanabira_1(EffectWork* w) {
    TaskPoolUpdate(&w->tasks);

    return 1;
}

void Hanabira_2(EffectWork* w) {
    TaskPoolDraw(&w->tasks);
}

void Hanabira_3(EffectWork* w) {
    TaskPoolDestroy(&w->tasks);
}

void Hanabira_c_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;
    w->palette = LoadObjPalette(gUnk_08F6DC84, 32);
    w->tiles = LoadObjTiles(gUnk_08BCB3D8, 256);
    w->x = b->x;
    w->y = b->y;
    w->z = b->z - 0x3000;
    w->vx = GetRandom() % 717 - 358;
    w->vz = -(GetRandom() % 539 + 102);
    AnimInit(&w->anim, gUnk_09EE1CB4, gUnk_09EE1C94);
    AnimStart(&w->anim, GetRandom() & 1, 1);
    w->state = 0;
}

s32 Hanabira_c_1(EffectWork* w) {
    s32 v;
    s32 r;

    switch (w->state) {
    case 0:
        w->x += w->vx;
        w->z += w->vz;
        w->vz += 17;

        if (w->vz > 256) {
            w->state = 1;
        }
        break;
    case 1:
        w->x += w->vx;
        w->z += w->vz;
        w->vz = (v = w->vz - 12) - (r = GetRandom()) % 9;

        if (w->vz < 0) {
            w->vz = GetRandom() % 181 + 204;

            if (w->vx > 0) {
                w->vx = -(GetRandom() % 257 + 128);
            } else {
                w->vx = GetRandom() % 257 + 128;
            }
        }

        if (w->z >= 0) {
            return 0;
        }
        break;
    }

    w->gfx = AnimUpdate(&w->anim);

    return 1;
}

void Hanabira_c_2(EffectWork* w) {
    s32 x;
    s32 y;
    s32 t;

    x = (w->x >> 8) - (gEventState->x >> 8);
    t = w->y >> 8;
    y = t + (w->z >> 8) - (gEventState->y >> 8);
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, (u16)(-0x1004 - t * 4));
}

void Hanabira_c_3(EffectWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void smoke_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;
    w->x = b->x;
    w->y = b->y - 0x800;
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    SetObjTileSource(w->tiles, gUnk_093215CA);
    AnimInit(&w->anim, gUnk_09EEFD78, gUnk_09EEFD60);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

void Exclamation_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;
    w->x = b->x;
    w->y = b->y;
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);

    if (FadeIsActive() == 0) {
        FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette)->index + 16, 1);
    }

    SetObjTileSource(w->tiles, gUnk_09320796);
    AnimInit(&w->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(&w->anim, 0, 0);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

void balloon_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;
    w->x = b->x;
    w->y = b->y;
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    SetObjTileSource(w->tiles, gUnk_09320796);
    AnimInit(&w->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(&w->anim, 1, 1);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 0;
    w->unk_46 = 0;
}

s32 func_08075720(EffectWork* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (w->actor->unk_1B2 == 0) {
        return 0;
    }

    return 1;
}

s32 Exclamation_1(EffectWork* w) {
    w->unk_46++;
    w->gfx = AnimUpdate(&w->anim);

    if (w->actor->unk_1B2 == 0 || w->unk_46 == 50) {
        return 0;
    }

    return 1;
}

void EffectDrawObj(EffectWork* w) {
    u16 pr;
    s32 y;

    pr = w->actor->unk_3E;

    if (w->unk_48 == 0) {
        pr &= 0xFFFE;
    }

    DrawSprite((w->x >> 8) - (gEventState->x >> 8),
               (y = (w->y >> 8) + gUnk_0903380C[w->actor->unk_26][0]) -
                   (gEventState->y >> 8),
               w->gfx, w->tiles, w->palette, 0, pr, 50);
}

void EffectReleaseObj(EffectWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void Question_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;
    w->x = b->x;
    w->y = b->y;
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    SetObjTileSource(w->tiles, gUnk_09320796);
    AnimInit(&w->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(&w->anim, 5, 0);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 0;
    w->unk_44 = 0;
    w->unk_46 = 0;
}

s32 Question_1(EffectWork* w) {
    w->gfx = AnimUpdate(&w->anim);
    w->unk_44++;

    if (w->unk_44 == 12) {
        AnimStart(&w->anim, 6, 1);
    }

    if (w->actor->unk_1B2 == 0) {
        return 0;
    }

    w->unk_46 = 0;

    return 1;
}

void func_080758D0(EffectWork* w, EventActor* arg) {
    EventBody* b;
    s32 d1;
    s32 d2;
    s32 k;

    w->actor = arg;
    b = &arg->body;
    k = 0x400;
    d1 = (GetRandom() % 9 << 8) - k;
    w->x = b->x + d1;
    d2 = (GetRandom() % 9 << 8) - k;
    w->y = b->y + d2;
    w->z2 = b->z;
    w->vx = GetRandom() % 232 + 76;
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    SetObjTileSource(w->tiles, gUnk_088A5D7A);
    AnimInit(&w->anim, gUnk_09EDE7E4, gUnk_09EDE7B4);
    AnimStart(&w->anim, GetRandom() % 3, 0);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 0;
    w->unk_46 = 0;
    gEventState->unk_86++;
}

s32 func_080759B0(EffectWork* w) {
    w->gfx = AnimUpdate(&w->anim);
    w->unk_46++;
    w->z2 += 256;

    if (w->z2 > 0) {
        return 0;
    }

    return 1;
}

void func_080759E0(EffectWork* w) {
    u16 pr;

    pr = w->actor->unk_3E;

    if (w->unk_48 == 0) {
        pr &= 0xFFFE;
    }

    DrawSprite((w->x >> 8) - (gEventState->x >> 8),
               ((w->y + w->z2) >> 8) - (gEventState->y >> 8),
               w->gfx, w->tiles, w->palette, 0, pr,
               (u16)(-0x1004 - (w->y >> 8) * 4));
}

void func_08075A54(EffectWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    gEventState->unk_86--;
}

void GlowNose_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;
    w->x = b->x - 1536;
    w->y = b->y + 3072;
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    SetObjTileSource(w->tiles, gUnk_09321804);
    AnimInit(&w->anim, gUnk_09EEFD9C, gUnk_09EEFD7C);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

s32 GlowNose_1(EffectWork* w) {
    w->gfx = AnimUpdate(&w->anim);
    w->unk_46++;

    if (w->unk_46 > 44) {
        return 0;
    }

    return 1;
}

void GlowNose2_0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->actor = arg;
    b = &arg->body;

    switch (arg->unk_26) {
    case 3:
        w->x = b->x - 6144;
        w->y = b->y + 8192;
        break;
    case 43:
        w->x = b->x + 2048;
        w->y = b->y + 2048;
        break;
    }

    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    SetObjTileSource(w->tiles, gUnk_09321804);
    AnimInit(&w->anim, gUnk_09EEFD9C, gUnk_09EEFD7C);
    AnimStart(&w->anim, 1, 1);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

s32 GlowNose2_1(EffectWork* w) {
    w->gfx = AnimUpdate(&w->anim);
    w->unk_46++;

    if (w->unk_46 > 8) {
        return 0;
    }

    return 1;
}

void down_0(EffectWork* w, EventActor* arg) {
    EventBody* b;
    DownWork* s;
    u8 i;

    w->actor = arg;
    b = &arg->body;

    switch (arg->unk_26) {
    case 0:
        w->x = b->x + 4096;
        w->y = b->y - 6144;
        break;
    case 2:
        w->x = b->x - 2048;
        w->y = b->y - 6144;
        break;
    case 1:
        w->x = b->x + 3584;
        w->y = b->y - 1024;
        break;
    }

    w->tiles = AllocSpriteFrameTiles(32);
    UpdateSpriteFrameTiles(w->tiles, gUnk_09EEA19C[3], gUnk_0908C686);
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
    w->down = EwramAlloc(sizeof(DownWork));
    s = w->down;

    for (i = 0; i < 8; i++) {
        s->angle[i] = i * 32;
        s->unk_40[i] = 0;
    }
}

s32 down_1(EffectWork* w) {
    DownWork* s;
    u8 i;

    s = w->down;

    for (i = 0; i < 8; i++) {
        s->unk_00[i] = gSineTable[s->angle[i] & 0xFF] * 8 + w->x;
        s->unk_20[i] = -gSineTable[(s->angle[i] & 0xFF) + 64] * (s->unk_40[i] + 4) +
                       w->y;
        s->angle[i] += 4;

        if (s->unk_40[i] == 0) {
            s->unk_40[i]++;
        } else {
            s->unk_40[i] = 0;
        }
    }

    if (w->actor->unk_1B2 == 0) {
        return 0;
    }

    return 1;
}

s32 down_2(EffectWork* w) {
    DownWork* s;
    u16 pr;
    u8 i;

    pr = w->actor->unk_3E;
    s = w->down;

    for (i = 0; i < 8; i++) {
        DrawSprite((s->unk_00[i] >> 8) - (gEventState->x >> 8),
                   (s->unk_20[i] >> 8) - (gEventState->y >> 8), 0,
                   w->tiles, w->palette, 0, pr, 50);
    }
}

void down_3(EffectWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    EwramFree(w->down);
}

void Tinkerbell_0(EffectWork* w, void* arg) {
    w->actor = arg;
    gEventState->unk_86 = 0;
    w->unk_44 = 0;
    TaskPoolInit(&w->tasks, 8);
}

s32 Tinkerbell_1(EffectWork* w) {
    w->unk_44++;

    if (w->unk_44 == 5) {
        if (gEventState->unk_86 <= 3) {
            TaskCreate(&w->tasks, &gUnk_09EE484C, w->actor);
        }

        w->unk_44 = 0;
    }

    TaskPoolUpdate(&w->tasks);

    return 1;
}

void Tinkerbell_2(EffectWork* w) {
    TaskPoolDraw(&w->tasks);
}

void Tinkerbell_3(EffectWork* w) {
    TaskPoolDestroy(&w->tasks);
}

void CreateTinkerbellTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescTinkerbell, h);
}

void CreateDownTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescDown, h);
}

void CreateSmokeTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescSmoke, h);
}

void CreateExclamationTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescExclamation, h);
}

void CreateBalloonTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescBalloon, h);
}

void CreateQuestionTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescQuestion, h);
}

void CreateGlowNoseTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescGlowNose, h);
}

void CreateGlowNose2Task(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescGlowNose2, h);
}

void CreateHanabiraTask(EventTaskHost* h) {
    TaskCreate(&h->tasks, &gTaskDescHanabira, h);
}

void EV_SOUND_0(EvSoundWork* w, u8* arg) {
    u8 i;

    w->unk_04 = arg[0];
    w->unk_05 = 0;
    w->unk_06 = 0;
    w->unk_07 = 0;
    w->unk_08 = 256;
    w->soundCues = gUnk_09EE3FB4[w->unk_04]->soundCues;
    gUnk_02039DD0 = EwramAlloc(256);

    for (i = 0; i < 64; i++) {
        gUnk_02039DD0[i].pan = 0;
        gUnk_02039DD0[i].volume = 256;
    }
}

s32 EV_SOUND_1(EvSoundWork* w) {
    const EvSoundCue* p;
    MusicPlayerInfo* mp;
    u8 idx;
    u8 n;
    u8 i;

    if (w->soundCues == 0) {
        return 0;
    }

    p = &w->soundCues[w->unk_05];

    if (gEventState->unk_6C == p->unk_02) {
        if (p->unk_00 != 0xFFFF) {
            if ((p->flags & 4) == 0) {
                m4aSongNumStartOrContinue(p->unk_00);
                idx = gSongTable[p->unk_00].ms;
                m4aMPlayImmInit(gMPlayTable[idx].info);
                gUnk_02039DD0[idx].pan = 0;
                gUnk_02039DD0[idx].volume = 256;
            } else {
                m4aSongNumStop(p->unk_00);
            }
        } else {
            m4aMPlayAllStop();
        }

        if (p->flags & 1) {
            m4aMPlayFadeOut(gMPlayTable[gSongTable[p->unk_00].ms].info, 5);
            w->unk_07 = 2;
        }

        if (p->flags & 2) {
            n = gSongTable[p->unk_00].ms;
            mp = gMPlayTable[n].info;
            w->unk_08 = 3;
            m4aMPlayVolumeControl(mp, 255, 3);
            w->unk_07 = 1;
        }

        if ((p->flags & 0x8000) == 0) {
            w->unk_05++;
        }
    }

    func_080760D8(w);

    for (i = 16; i <= 24; i++) {
        m4aMPlayPanpotControl(gMPlayTable[i].info, 255,
                              gUnk_02039DD0[i].pan);
        m4aMPlayVolumeControl(gMPlayTable[i].info, 255,
                              gUnk_02039DD0[i].volume);
    }

    return 1;
}

void EV_SOUND_2(void) {
}

void EV_SOUND_3(void) {
    EwramFree(gUnk_02039DD0);
}

void func_080760D8(EvSoundWork* w) {
    MusicPlayerInfo* mp;

    mp = gMPlayTable[0].info;

    if (w->unk_07 == 1) {
        w->unk_08 += 2;

        if (w->unk_08 > 255) {
            w->unk_08 = 256;
        }

        m4aMPlayImmInit(mp);
        m4aMPlayVolumeControl(mp, 255, w->unk_08);
    }
}

void func_08076110(u16 song, s16 x, s16 y) {
    u8 idx;
    s32 sx;
    s16 dx;
    s16 pan;
    s16 dist;
    s16 t;
    s16 v;
    u32 d;

    v = 0;

    if (gUnk_02039DD0 == 0) {
        return;
    }

    idx = gSongTable[song].ms;
    m4aMPlayImmInit(gMPlayTable[idx].info);

    if ((u16)x > 240) {
        gUnk_02039DD0[idx].pan = v;
        gUnk_02039DD0[idx].volume = v;
    }

    if ((u16)y > 160) {
        gUnk_02039DD0[idx].pan = v;
        gUnk_02039DD0[idx].volume = v;
    }

    sx = x;
    dx = sx;
    dx -= 120;
    pan = dx;

    if (pan > 127) {
        pan = 127;
    }

    if (pan < -128) {
        pan = -128;
    }

    gUnk_02039DD0[idx].pan = pan;

    if (120 - sx >= 0) {
        t = 120 - sx;
    } else {
        t = dx;
    }

    dist = t;

    if (80 - y * 2 < 0) {
        d = y * 2 - 80;
        t = d / 2;
    } else {
        d = 80 - y * 2;
        t = d / 2;
    }
    v = dist + t;

    if (v > 256) {
        v = 256;
    }

    gUnk_02039DD0[idx].volume = 256 - v;

    if (gUnk_02039DD0[idx].volume < 12) {
        gUnk_02039DD0[idx].volume = 12;
    }
}

void Event_Debug_0(u8* work) {
    *(void**)&work[0x00] = LoadSmallFontTiles();
    *(void**)&work[0x04] = LoadSmallFontPalette();
}

s32 Event_Debug_1(u8* work) {
    work[0x28] = FormatSmallFontDecimal(gEventState->unk_6C, &work[0x08]);
    return 1;
}

void Event_Debug_2(u8* work) {
    DrawSmallFontString(0, 0, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}

void Event_Debug_3(s32* p) {
    FreeSmallFontResources(p[0], p[1]);
}

Mode gModeEventselect = {
    "mode_eventselect",
    (ModeInitFunc)mode_eventselect_0,
    mode_eventselect_1,
    mode_eventselect_2,
};

TaskDesc gTaskDescHanabira = {
    "Hanabira",
    (TaskInitFunc)Hanabira_0,
    (TaskUpdateFunc)Hanabira_1,
    (TaskFunc)Hanabira_2,
    (TaskFunc)Hanabira_3,
    0x60,
};

TaskDesc gTaskDescHanabiraC = {
    "Hanabira_c",
    (TaskInitFunc)Hanabira_c_0,
    (TaskUpdateFunc)Hanabira_c_1,
    (TaskFunc)Hanabira_c_2,
    (TaskFunc)Hanabira_c_3,
    0x60,
};

TaskDesc gTaskDescSmoke = {
    "smoke",
    (TaskInitFunc)smoke_0,
    (TaskUpdateFunc)func_08075720,
    (TaskFunc)EffectDrawObj,
    (TaskFunc)EffectReleaseObj,
    0x60,
};

TaskDesc gTaskDescExclamation = {
    "Exclamation",
    (TaskInitFunc)Exclamation_0,
    (TaskUpdateFunc)Exclamation_1,
    (TaskFunc)EffectDrawObj,
    (TaskFunc)EffectReleaseObj,
    0x60,
};

TaskDesc gTaskDescBalloon = {
    "balloon",
    (TaskInitFunc)balloon_0,
    (TaskUpdateFunc)func_08075720,
    (TaskFunc)EffectDrawObj,
    (TaskFunc)EffectReleaseObj,
    0x60,
};

TaskDesc gTaskDescQuestion = {
    "Question",
    (TaskInitFunc)Question_0,
    (TaskUpdateFunc)Question_1,
    (TaskFunc)EffectDrawObj,
    (TaskFunc)EffectReleaseObj,
    0x60,
};

TaskDesc gUnk_09EE484C = {
    "GlowNose",
    (TaskInitFunc)func_080758D0,
    (TaskUpdateFunc)func_080759B0,
    (TaskFunc)func_080759E0,
    (TaskFunc)func_08075A54,
    0x60,
};

TaskDesc gTaskDescGlowNose = {
    "GlowNose",
    (TaskInitFunc)GlowNose_0,
    (TaskUpdateFunc)GlowNose_1,
    (TaskFunc)EffectDrawObj,
    (TaskFunc)EffectReleaseObj,
    0x60,
};

TaskDesc gTaskDescGlowNose2 = {
    "GlowNose",
    (TaskInitFunc)GlowNose2_0,
    (TaskUpdateFunc)GlowNose2_1,
    (TaskFunc)EffectDrawObj,
    (TaskFunc)EffectReleaseObj,
    0x60,
};

TaskDesc gTaskDescDown = {
    "down",
    (TaskInitFunc)down_0,
    (TaskUpdateFunc)down_1,
    (TaskFunc)down_2,
    (TaskFunc)down_3,
    0x60,
};

TaskDesc gTaskDescTinkerbell = {
    "Tinkerbell",
    (TaskInitFunc)Tinkerbell_0,
    (TaskUpdateFunc)Tinkerbell_1,
    (TaskFunc)Tinkerbell_2,
    (TaskFunc)Tinkerbell_3,
    0x60,
};

TaskDesc gTaskDescEvSound = {
    "EV_SOUND",
    (TaskInitFunc)EV_SOUND_0,
    (TaskUpdateFunc)EV_SOUND_1,
    (TaskFunc)EV_SOUND_2,
    (TaskFunc)EV_SOUND_3,
    0xC,
};

TaskDesc gTaskDescEventDebug = {
    "Event_Debug",
    (TaskInitFunc)Event_Debug_0,
    (TaskUpdateFunc)Event_Debug_1,
    (TaskFunc)Event_Debug_2,
    (TaskFunc)Event_Debug_3,
    0x2C,
};
