#include "macros.h"
#include "mode_eventselect.h"
#include "gba/keys.h"

void mode_eventselect_0(void) {
    func_08004DB0();
    func_08085FB0();
    func_08085C3C();
    func_08093BB4();
    SetupBg(0, 0, 30, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x8000, 0x800);
    func_0805FA60(0, gUnk_08F70990, 0x20, 0);
}

void mode_eventselect_1(void) {
    if (GetKeysRepeat() & DPAD_UP) {
        if (gUnk_02034A96 != 0) {
            gUnk_02034A96--;
        } else {
            gUnk_02034A96 = 1;
        }
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        if (gUnk_02034A96 == 0) {
            gUnk_02034A96++;
        } else {
            gUnk_02034A96 = 0;
        }
    }

    switch (gUnk_02034A96) {
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
        gUnk_02034A94++;
    }

    if (GetKeysRepeat() & DPAD_LEFT) {
        gUnk_02034A94--;
    }

    if (func_08075064(gUnk_02034A96) - 1 < gUnk_02034A94) {
        gUnk_02034A94 = 0;
    }

    if (gUnk_02034A94 < 0) {
        gUnk_02034A94 = func_08075064(gUnk_02034A96) - 1;
    }

    func_0805FCB0(10, 0, 2, gUnk_09033EE0);
    func_0805FCB0(10, 10, 2, gUnk_09033EF8);
    func_0805FCB0(20, 40, 2, gUnk_09033F10);
    func_0805FC04(100, 40, 2, gUnk_02034A94 + 1);

    switch (gUnk_02034A96) {
    case 0:
        func_0805FCB0(20, 80, 2, gUnk_09EE42C8[gUnk_09033D50[gUnk_02034A94]]);
        break;
    case 1:
        func_0805FCB0(20, 80, 2, gUnk_09EE42C8[gUnk_09033E76[gUnk_02034A94]]);
        break;
    }

    if (GetKeysPressed() & A_BUTTON) {
        switch (gUnk_02034A96) {
        case 0:
            func_0806180C(gUnk_09033D50[gUnk_02034A94]);
            break;
        case 1:
            func_0806180C(gUnk_09033E76[gUnk_02034A94]);
            break;
        }
    }

    if (GetKeysPressed() & B_BUTTON) {
        func_080010CC(&gUnk_09ECEB64, 0);
    }

    func_080605A4(0);
    func_08060598();
}

void mode_eventselect_2(void) {
    func_080609A0();
}

void func_08075360(EffectWork* w, void* arg) {
    s32 i;

    TaskPoolInit(&w->unk_4C, 16);

    for (i = 15; i >= 0; i--) {
        TaskCreate(&w->unk_4C, &gUnk_09EE47D4, arg);
    }
}

s32 func_0807538C(EffectWork* w) {
    TaskPoolUpdate(&w->unk_4C);

    return 1;
}

void func_0807539C(EffectWork* w) {
    TaskPoolDraw(&w->unk_4C);
}

void func_080753A8(EffectWork* w) {
    TaskPoolDestroy(&w->unk_4C);
}

void func_080753B4(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;
    w->unk_08 = LoadObjPalette(gUnk_08F6DC84, 32);
    w->unk_04 = LoadObjTiles(gUnk_08BCB3D8, 256);
    w->unk_2C = b->unk_04;
    w->unk_30 = b->unk_08;
    w->unk_34 = b->unk_0C - 0x3000;
    w->unk_3C = GetRandom() % 717 - 358;
    w->unk_40 = -(GetRandom() % 539 + 102);
    AnimInit(&w->unk_14, gUnk_09EE1CB4, gUnk_09EE1C94);
    AnimStart(&w->unk_14, GetRandom() & 1, 1);
    w->unk_49 = 0;
}

s32 func_08075460(EffectWork* w) {
    s32 v;
    s32 r;

    switch (w->unk_49) {
    case 0:
        w->unk_2C += w->unk_3C;
        w->unk_34 += w->unk_40;
        w->unk_40 += 17;

        if (w->unk_40 > 256) {
            w->unk_49 = 1;
        }
        break;
    case 1:
        w->unk_2C += w->unk_3C;
        w->unk_34 += w->unk_40;
        w->unk_40 = (v = w->unk_40 - 12) - (r = GetRandom()) % 9;

        if (w->unk_40 < 0) {
            w->unk_40 = GetRandom() % 181 + 204;

            if (w->unk_3C > 0) {
                w->unk_3C = -(GetRandom() % 257 + 128);
            } else {
                w->unk_3C = GetRandom() % 257 + 128;
            }
        }

        if (w->unk_34 >= 0) {
            return 0;
        }
        break;
    }

    w->unk_0C = AnimUpdate(&w->unk_14);

    return 1;
}

void func_08075530(EffectWork* w) {
    s32 x;
    s32 y;
    s32 t;

    x = (w->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    t = w->unk_30 >> 8;
    y = t + (w->unk_34 >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    DrawSprite(x, y, w->unk_0C, w->unk_04, w->unk_08, 0, 0x800, (u16)(-0x1004 - t * 4));
}

void func_08075590(EffectWork* w) {
    ReleaseObjTiles(w->unk_04);
    ReleaseObjPalette(w->unk_08);
}

void func_080755A8(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;
    w->unk_2C = b->unk_04;
    w->unk_30 = b->unk_08 - 0x800;
    w->unk_04 = AllocObjTiles(128, 0);
    w->unk_08 = LoadObjPalette(gUnk_08F69BE4, 32);
    func_08002A10(w->unk_04, 0x093215CA);
    AnimInit(&w->unk_14, gUnk_09EEFD78, gUnk_09EEFD60);
    AnimStart(&w->unk_14, 0, 1);
    w->unk_0C = AnimGetGfx(&w->unk_14);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

void func_08075624(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;
    w->unk_2C = b->unk_04;
    w->unk_30 = b->unk_08;
    w->unk_04 = AllocObjTiles(128, 0);
    w->unk_08 = LoadObjPalette(gUnk_08F69BE4, 32);

    if (func_08006314() == 0) {
        func_080062F4(((UnkStruct_080038C8*)w->unk_08)->unk_06 + 16, 1);
    }

    func_08002A10(w->unk_04, 0x09320796);
    AnimInit(&w->unk_14, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(&w->unk_14, 0, 0);
    w->unk_0C = AnimGetGfx(&w->unk_14);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

void func_080756B0(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;
    w->unk_2C = b->unk_04;
    w->unk_30 = b->unk_08;
    w->unk_04 = AllocObjTiles(128, 0);
    w->unk_08 = LoadObjPalette(gUnk_08F69BE4, 32);
    func_08002A10(w->unk_04, 0x09320796);
    AnimInit(&w->unk_14, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(&w->unk_14, 1, 1);
    w->unk_0C = AnimGetGfx(&w->unk_14);
    w->unk_48 = 0;
    w->unk_46 = 0;
}

s32 func_08075720(EffectWork* w) {
    w->unk_0C = AnimUpdate(&w->unk_14);

    if (w->unk_00->unk_1B2 == 0) {
        return 0;
    }

    return 1;
}

s32 func_08075748(EffectWork* w) {
    w->unk_46++;
    w->unk_0C = AnimUpdate(&w->unk_14);

    if (w->unk_00->unk_1B2 == 0 || w->unk_46 == 50) {
        return 0;
    }

    return 1;
}

void func_08075780(EffectWork* w) {
    u16 pr;
    s32 y;

    pr = w->unk_00->unk_3E;

    if (w->unk_48 == 0) {
        pr &= 0xFFFE;
    }

    DrawSprite((w->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8),
               (y = (w->unk_30 >> 8) + gUnk_0903380C[w->unk_00->unk_26][0]) -
                   (gUnk_02039DC8->unk_5C >> 8),
               w->unk_0C, w->unk_04, w->unk_08, 0, pr, 50);
}

void func_080757F4(EffectWork* w) {
    ReleaseObjTiles(w->unk_04);
    ReleaseObjPalette(w->unk_08);
}

void func_0807580C(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;
    w->unk_2C = b->unk_04;
    w->unk_30 = b->unk_08;
    w->unk_04 = AllocObjTiles(128, 0);
    w->unk_08 = LoadObjPalette(gUnk_08F69BE4, 32);
    func_08002A10(w->unk_04, 0x09320796);
    AnimInit(&w->unk_14, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(&w->unk_14, 5, 0);
    w->unk_0C = AnimGetGfx(&w->unk_14);
    w->unk_48 = 0;
    w->unk_44 = 0;
    w->unk_46 = 0;
}

s32 func_08075880(EffectWork* w) {
    w->unk_0C = AnimUpdate(&w->unk_14);
    w->unk_44++;

    if (w->unk_44 == 12) {
        AnimStart(&w->unk_14, 6, 1);
    }

    if (w->unk_00->unk_1B2 == 0) {
        return 0;
    }

    w->unk_46 = 0;

    return 1;
}

INCLUDE_ASM("mode_eventselect/func_080758D0.s");

s32 func_080759B0(EffectWork* w) {
    w->unk_0C = AnimUpdate(&w->unk_14);
    w->unk_46++;
    w->unk_38 += 256;

    if (w->unk_38 > 0) {
        return 0;
    }

    return 1;
}

void func_080759E0(EffectWork* w) {
    u16 pr;

    pr = w->unk_00->unk_3E;

    if (w->unk_48 == 0) {
        pr &= 0xFFFE;
    }

    DrawSprite((w->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8),
               ((w->unk_30 + w->unk_38) >> 8) - (gUnk_02039DC8->unk_5C >> 8),
               w->unk_0C, w->unk_04, w->unk_08, 0, pr,
               (u16)(-0x1004 - (w->unk_30 >> 8) * 4));
}

void func_08075A54(EffectWork* w) {
    ReleaseObjTiles(w->unk_04);
    ReleaseObjPalette(w->unk_08);
    gUnk_02039DC8->unk_86--;
}

void func_08075A7C(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;
    w->unk_2C = b->unk_04 - 1536;
    w->unk_30 = b->unk_08 + 3072;
    w->unk_04 = AllocObjTiles(128, 0);
    w->unk_08 = LoadObjPalette(gUnk_08F69BE4, 32);
    func_08002A10(w->unk_04, 0x09321804);
    AnimInit(&w->unk_14, gUnk_09EEFD9C, gUnk_09EEFD7C);
    AnimStart(&w->unk_14, 0, 1);
    w->unk_0C = AnimGetGfx(&w->unk_14);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

s32 func_08075AFC(EffectWork* w) {
    w->unk_0C = AnimUpdate(&w->unk_14);
    w->unk_46++;

    if (w->unk_46 > 44) {
        return 0;
    }

    return 1;
}

void func_08075B24(EffectWork* w, EventActor* arg) {
    EventBody* b;

    w->unk_00 = arg;
    b = &arg->unk_28;

    switch (arg->unk_26) {
    case 3:
        w->unk_2C = b->unk_04 - 6144;
        w->unk_30 = b->unk_08 + 8192;
        break;
    case 43:
        w->unk_2C = b->unk_04 + 2048;
        w->unk_30 = b->unk_08 + 2048;
        break;
    }

    w->unk_04 = AllocObjTiles(128, 0);
    w->unk_08 = LoadObjPalette(gUnk_08F69BE4, 32);
    func_08002A10(w->unk_04, 0x09321804);
    AnimInit(&w->unk_14, gUnk_09EEFD9C, gUnk_09EEFD7C);
    AnimStart(&w->unk_14, 1, 1);
    w->unk_0C = AnimGetGfx(&w->unk_14);
    w->unk_48 = 1;
    w->unk_46 = 0;
}

s32 func_08075BC4(EffectWork* w) {
    w->unk_0C = AnimUpdate(&w->unk_14);
    w->unk_46++;

    if (w->unk_46 > 8) {
        return 0;
    }

    return 1;
}

void func_08075BEC(EffectWork* w, EventActor* arg) {
    EventBody* b;
    DownWork* s;
    u8 i;

    w->unk_00 = arg;
    b = &arg->unk_28;

    switch (arg->unk_26) {
    case 0:
        w->unk_2C = b->unk_04 + 4096;
        w->unk_30 = b->unk_08 - 6144;
        break;
    case 2:
        w->unk_2C = b->unk_04 - 2048;
        w->unk_30 = b->unk_08 - 6144;
        break;
    case 1:
        w->unk_2C = b->unk_04 + 3584;
        w->unk_30 = b->unk_08 - 1024;
        break;
    }

    w->unk_04 = func_080038C8(32);
    func_080038E4(w->unk_04, gUnk_09EEA19C[3], 0x0908C686);
    w->unk_08 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_10 = EwramAlloc(sizeof(DownWork));
    s = w->unk_10;

    for (i = 0; i < 8; i++) {
        s->unk_48[i] = i * 32;
        s->unk_40[i] = 0;
    }
}

s32 func_08075CAC(EffectWork* w) {
    DownWork* s;
    u8 i;

    s = w->unk_10;

    for (i = 0; i < 8; i++) {
        s->unk_00[i] = gSineTable[s->unk_48[i] & 0xFF] * 8 + w->unk_2C;
        s->unk_20[i] = -gSineTable[(s->unk_48[i] & 0xFF) + 64] * (s->unk_40[i] + 4) +
                       w->unk_30;
        s->unk_48[i] += 4;

        if (s->unk_40[i] == 0) {
            s->unk_40[i]++;
        } else {
            s->unk_40[i] = 0;
        }
    }

    if (w->unk_00->unk_1B2 == 0) {
        return 0;
    }

    return 1;
}

s32 func_08075D58(EffectWork* w) {
    DownWork* s;
    u16 pr;
    u8 i;

    pr = w->unk_00->unk_3E;
    s = w->unk_10;

    for (i = 0; i < 8; i++) {
        DrawSprite((s->unk_00[i] >> 8) - (gUnk_02039DC8->unk_58 >> 8),
                   (s->unk_20[i] >> 8) - (gUnk_02039DC8->unk_5C >> 8), 0,
                   w->unk_04, w->unk_08, 0, pr, 50);
    }
}

void func_08075DBC(EffectWork* w) {
    ReleaseObjTiles(w->unk_04);
    ReleaseObjPalette(w->unk_08);
    EwramFree(w->unk_10);
}

void func_08075DD8(EffectWork* w, void* arg) {
    w->unk_00 = arg;
    gUnk_02039DC8->unk_86 = 0;
    w->unk_44 = 0;
    TaskPoolInit(&w->unk_4C, 8);
}

s32 func_08075DFC(EffectWork* w) {
    w->unk_44++;

    if (w->unk_44 == 5) {
        if (gUnk_02039DC8->unk_86 <= 3) {
            TaskCreate(&w->unk_4C, &gUnk_09EE484C, w->unk_00);
        }

        w->unk_44 = 0;
    }

    TaskPoolUpdate(&w->unk_4C);

    return 1;
}

void func_08075E48(EffectWork* w) {
    TaskPoolDraw(&w->unk_4C);
}

void func_08075E54(EffectWork* w) {
    TaskPoolDestroy(&w->unk_4C);
}

void func_08075E60(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE48AC, h);
}

void func_08075E74(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE4894, h);
}

void func_08075E88(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE47EC, h);
}

void func_08075E9C(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE4804, h);
}

void func_08075EB0(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE481C, h);
}

void func_08075EC4(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE4834, h);
}

void func_08075ED8(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE4864, h);
}

void func_08075EEC(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE487C, h);
}

void func_08075F00(EventTaskHost* h) {
    TaskCreate(&h->unk_10, &gUnk_09EE47BC, h);
}

void func_08075F14(EvSoundWork* w, u8* arg) {
    u8 i;

    w->unk_04 = arg[0];
    w->unk_05 = 0;
    w->unk_06 = 0;
    w->unk_07 = 0;
    w->unk_08 = 256;
    w->unk_00 = gUnk_09EE3FB4[w->unk_04][4];
    gUnk_02039DD0 = EwramAlloc(256);

    for (i = 0; i < 64; i++) {
        gUnk_02039DD0[i].unk_00 = 0;
        gUnk_02039DD0[i].unk_02 = 256;
    }
}

s32 func_08075F68(EvSoundWork* w) {
    EvSoundCue* p;
    MusicPlayerInfo* mp;
    u8 idx;
    u8 n;
    u8 i;

    if (w->unk_00 == 0) {
        return 0;
    }

    p = &w->unk_00[w->unk_05];

    if (gUnk_02039DC8->unk_6C == p->unk_02) {
        if (p->unk_00 != 0xFFFF) {
            if ((p->unk_04 & 4) == 0) {
                m4aSongNumStartOrContinue(p->unk_00);
                idx = gSongTable[p->unk_00].ms;
                m4aMPlayImmInit(gMPlayTable[idx].info);
                gUnk_02039DD0[idx].unk_00 = 0;
                gUnk_02039DD0[idx].unk_02 = 256;
            } else {
                m4aSongNumStop(p->unk_00);
            }
        } else {
            m4aMPlayAllStop();
        }

        if (p->unk_04 & 1) {
            m4aMPlayFadeOut(gMPlayTable[gSongTable[p->unk_00].ms].info, 5);
            w->unk_07 = 2;
        }

        if (p->unk_04 & 2) {
            n = gSongTable[p->unk_00].ms;
            mp = gMPlayTable[n].info;
            w->unk_08 = 3;
            m4aMPlayVolumeControl(mp, 255, 3);
            w->unk_07 = 1;
        }

        if ((p->unk_04 & 0x8000) == 0) {
            w->unk_05++;
        }
    }

    func_080760D8(w);

    for (i = 16; i <= 24; i++) {
        m4aMPlayPanpotControl(gMPlayTable[i].info, 255,
                              gUnk_02039DD0[i].unk_00);
        m4aMPlayVolumeControl(gMPlayTable[i].info, 255,
                              gUnk_02039DD0[i].unk_02);
    }

    return 1;
}

void func_080760C0(void) {
}

void func_080760C4(void) {
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
        gUnk_02039DD0[idx].unk_00 = v;
        gUnk_02039DD0[idx].unk_02 = v;
    }

    if ((u16)y > 160) {
        gUnk_02039DD0[idx].unk_00 = v;
        gUnk_02039DD0[idx].unk_02 = v;
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

    gUnk_02039DD0[idx].unk_00 = pan;

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

    gUnk_02039DD0[idx].unk_02 = 256 - v;

    if (gUnk_02039DD0[idx].unk_02 < 12) {
        gUnk_02039DD0[idx].unk_02 = 12;
    }
}

void func_08076214(u8* work) {
    *(void**)&work[0x00] = func_080668F0();
    *(void**)&work[0x04] = func_08066904();
}

s32 func_0807622C(u8* work) {
    work[0x28] = _080669DC(gUnk_02039DC8->unk_6C, &work[0x08]);
    return 1;
}

void func_08076250(u8* work) {
    func_08066DC0(0, 0, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}

void func_08076274(s32* p) {
    func_08066918(p[0], p[1]);
}

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
    gUnk_02039DD4->unk_000 = 0;
    gUnk_02039DD4->unk_004 = 0;
    gUnk_02039DD4->unk_008 = 0;
    gUnk_02039DD4->unk_00C = 0;
    gUnk_02039DD4->unk_010 = 0;
    gUnk_02039DD4->unk_014 = 0;
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
    TaskPoolInit(&gUnk_02039DD4->unk_09C, 6);
    gUnk_02039DD4->unk_030 = LoadObjTiles(gUnk_08F709B0[0].unk_0C, 640);
    gUnk_02039DD4->unk_034 = LoadObjTiles(gUnk_08F709B0[1].unk_0C, 640);
    gUnk_02039DD4->unk_038 = LoadObjTiles(gUnk_08F709B0[2].unk_0C, 640);
    gUnk_02039DD4->unk_03C = LoadObjTiles(gUnk_08F709B0[3].unk_0C, 640);
    gUnk_02039DD4->unk_044 = LoadObjTiles(gUnk_0905EAE8, 320);
    gUnk_02039DD4->unk_048 = LoadObjTiles(gUnk_0905ED36, 320);
    gUnk_02039DD4->unk_04C = LoadObjTiles(gUnk_0905EEE6, 320);
    gUnk_02039DD4->unk_054 = LoadObjPalette(gUnk_09611AB8, 32);
    gUnk_02039DD4->unk_058 = LoadObjPalette(gUnk_08F69BA4, 32);
    func_080062F4(((UnkStruct_080038C8*)gUnk_02039DD4->unk_054)->unk_06 + 16, 1);
    func_0807B668(gUnk_02039DD4);
}

INCLUDE_ASM("mode_eventselect/func_08076674.s");
INCLUDE_ASM("mode_eventselect/func_08076750.s");
INCLUDE_ASM("mode_eventselect/func_0807682C.s");

void func_08077E10(CardBattleWork* w) {
    gUnk_02039DD4->unk_094 = AnimUpdate(&gUnk_02039DD4->unk_064);
    gUnk_02039DD4->unk_098 = AnimUpdate(&gUnk_02039DD4->unk_07C);

    if (gUnk_02039DD4->unk_0EA != 0 && w->unk_B9 != 0 && w->unk_BA != 0) {
        DrawSprite(w->unk_A4, 4, gUnk_09EF12E8[0], w->unk_14, w->unk_18, 0, 16,
                   12);
    }

    TaskPoolDraw(w);
    TaskPoolDraw(&gUnk_02039DD4->unk_09C);
}

void func_08077E98(CardBattleWork* w) {
    u8 i;

    TaskPoolDestroy(w);
    TaskPoolDestroy(&gUnk_02039DD4->unk_09C);

    for (i = 0; i < 4; i++) {
        if (w->unk_44[i] != 0) {
            EwramFree(w->unk_44[i]);
        }
    }

    ReleaseObjTiles(gUnk_02039DD4->unk_04C);
    ReleaseObjTiles(gUnk_02039DD4->unk_048);
    ReleaseObjTiles(gUnk_02039DD4->unk_044);
    ReleaseObjPalette(gUnk_02039DD4->unk_054);
    ReleaseObjPalette(gUnk_02039DD4->unk_058);
    ReleaseObjTiles(gUnk_02039DD4->unk_040);
    ReleaseObjTiles(gUnk_02039DD4->unk_050);
    ReleaseObjTiles(gUnk_02039DD4->unk_030);
    ReleaseObjTiles(gUnk_02039DD4->unk_034);
    ReleaseObjTiles(gUnk_02039DD4->unk_038);
    ReleaseObjTiles(gUnk_02039DD4->unk_03C);
    EwramFree(gUnk_02039DD4);
    gUnk_02039DD4 = 0;
    ReleaseObjTiles(w->unk_14);
    ReleaseObjPalette(w->unk_18);
}

INCLUDE_ASM("mode_eventselect/func_08077F44.s");
