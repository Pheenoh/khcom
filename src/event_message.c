#include "registration_data.h"
#include "eventselect_api.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "intr.h"
#include "m4a_song.h"
#include "obj_api.h"
#include "pallet.h"
#include "display.h"
#include "text.h"
#include "monsgage.h"
#include "anim.h"
#include "msg.h"

extern const u16 gUnk_0951D2B8[1024];
extern const u16 gUnk_0951DAB8[1024];
extern const u16 gUnk_0951E2B8[1024];
extern const u16 gUnk_0951EAB8[1024];


#ifdef VERSION_EU
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];
extern u8 gUnkEu_0919B63A[];
#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif

const char gTaskNameEventSeq[] = "event_seq";

const char gTaskNameEventChara[] = "event_chara";

const u16 gUnk_09033C8C[2] = {
    145, 167,
};

const u16 gUnk_09033C90[4] = {
    2048, 2048, 2048, 2048,
};

const u16 gUnk_09033C98[4] = {
    0, 0, 255, 255,
};

const u16 gUnk_09033CA0[4] = {
    255, 255, 0, 0,
};

const s32 gUnk_09033CA8[4] = {
    4096, 4096, 18432, 18432,
};

const s32 gUnk_09033CB8[4] = {
    3584, 28160, 3584, 28160,
};

const char gTaskNameMsgwin[] = "msgwin";

const s32 gUnk_09033CD0[4] = {
    114944, 114944, -76544, -76544,
};

const s32 gUnk_09033CE0[4] = {
    52736, 52736, 9216, 9216,
};

const s32 gUnk_09033CF0[4] = {
    14336, 32768, 14336, 32768,
};

const char gTaskNameMsgface[] = "msgface";

const s32 gUnk_09033D08[4][2] = {
    {26112, 15872},
    {26112, 40448},
    {36864, 15872},
    {36864, 40448},
};

const s32 gUnk_09033D28[2] = {
    16128, 19968,
};

const char gTaskNameMsgwait[] = "msgwait";

const char gTaskNameMsgwaitYesno[] = "msgwait_yesno";

const char gTaskNameView[] = "view";

EventScanlineScroll* gUnk_02039DCC;


void event_seq_0(EventSeqWork* work, u8* a) {
#ifdef VERSION_EU
    EventBackgroundDef* u;
#endif

    gUnk_02039DD0 = NULL;
    gBtlWork = NULL;
    work->unk_28 = 0;
    work->unk_2C = a[0];
    work->unk_2E = a[1];
    work->seqDef = gUnk_09EE3FB4[work->unk_2C];
    work->unk_30 = 0;
    work->unk_31 = 0;
    gUnk_02039DC8->unk_8A = 0;
    work->unk_2F = 0;
    work->unk_32 = 0;
#ifdef VERSION_EU
    work->unk_3D = 0;
    work->unk_3A = 0;
    work->unk_3B = 0;
    work->unk_3C = 0;
#endif

    if (gUnk_02039DC8 != NULL) {
        gUnk_02039DC8->unk_7A = 1;
        gUnk_02039DC8->unk_7B = 0;
        gUnk_02039DC8->unk_78 = 0;
        gUnk_02039DC8->unk_79 = 0;
        gUnk_02039DC8->unk_7F = 0;
        gUnk_02039DC8->unk_68 = 0;
        gUnk_02039DC8->unk_6A = 0;
        gUnk_02039DC8->unk_80 = 0;
        gUnk_02039DC8->unk_82 = 0;
        gUnk_02039DC8->unk_84 = 0;
        gUnk_02039DC8->unk_85 = 0;
        gUnk_02039DC8->unk_83 = 0;
#ifndef VERSION_EU
        RequestDma3Clear(GetBgCharBase(1), 0x8000);
#endif

        if (work->seqDef->keyframes->unk_14 & 0x80) {
            SetBackdropColor(31, 31, 31);
            FadeStartIn(1, 0x40);
        }
#ifdef VERSION_EU
        u = gUnk_09EE3CA0[work->unk_2C];
        if (u != NULL) {
            if (u->tiles2 != NULL) {
                if ((u->unk_2D & 1) != 0) {
                    SetupBg(0, 3, 31, 14);
                    SetupBg(1, 0, 29, 0);
                    SetupBg(2, 2, 30, 0);
                    SetupBg(3, 0, 28, 0);
                } else {
                    SetupBg(0, 3, 31, 14);
                    SetupBg(1, 2, 30, 0);
                    SetupBg(2, 0, 22, 0);
                    SetupBg(3, 0, 23, 0);
                }
            }
            if (u->unk_24 != 0) {
                if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
                    eu_080059D4(2, u->tiles);
                } else {
                    LoadBgTiles(2, u->tiles, u->tilesSize);
                }
                LoadBgPalette(2, u->palette, u->paletteSize);
                SetBgColorMode(2, 128);
                SetBgSize(2, 0x8000);
                if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                    eu_080059F4(2, (void*)*u->maps);
                } else {
                    LoadBgMap(2, (void*)*u->maps, 0x1000);
                }
                SetBgAffine(2, 0, 256, 256, 0, 0);
            } else {
                eu_0806C734(work);
                eu_0806C7C8(work);
                eu_0806C848(work);
            }
        }
        if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0) {
            FadeStartIn(0, 64);
        } else if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0x80) {
            FadeStartIn(1, 120);
        }
        work->unk_38 = 0;
        eu_0806C974(work);
#endif
    }
}

#ifdef VERSION_EU
u8 eu_0806C734(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
            eu_080059D4(3, u->tiles);
        } else {
            LoadBgTiles(3, u->tiles, u->tilesSize);
        }
        LoadBgPalette(3, u->palette, u->paletteSize);
        if (u->maps != NULL) {
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3A = 1;
                eu_08005A1C(3, u->maps, u->mapWidth, u->mapHeight);
            } else {
                work->unk_3A = 0;
                SetBgMapBlocks(3, u->maps, u->mapWidth, u->mapHeight);
            }
            RedrawBgMapAt(3, 0, 0);
        }
    }
    return 1;
}
u8 eu_0806C7C8(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->maps2 != NULL) {
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3B = 1;
                eu_08005A1C(2, u->maps2, u->mapWidth, u->mapHeight);
            } else {
                work->unk_3B = 0;
                SetBgMapBlocks(2, u->maps2, u->mapWidth, u->mapHeight);
            }
            RedrawBgMapAt(2, 0, 0);
            gUnk_02039DC8->unk_78 = 1;
        } else {
            DisableBg(2);
        }
    }
    return 1;
}
u8 eu_0806C848(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->tiles2 != NULL) {
            if ((u->unk_2D & 1) != 0) {
                LoadBgTiles(2, u->tiles2, u->tilesSize2);
            } else if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
                eu_080059D4(1, u->tiles2);
            } else {
                LoadBgTiles(1, u->tiles2, u->tilesSize2);
            }
        }
        if (u->maps3 != NULL) {
            if ((u->unk_2D & 2) != 0) {
                gBldCnt = 0x1844;
                (*(volatile u16*)&gBldAlpha) = 0x050E;
                SetBgPriority(2, 1);
                gUnk_02039DC8->unk_6E = 0x1D42;
                gUnk_02039DC8->unk_70 = 0x050E;
            } else {
                gUnk_02039DC8->unk_6E = 0;
                gUnk_02039DC8->unk_70 = 0;
            }
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3C = 1;
                eu_08005A1C(1, u->maps3, u->mapWidth, u->mapHeight);
            } else {
                work->unk_3C = 0;
                SetBgMapBlocks(1, u->maps3, u->mapWidth, u->mapHeight);
            }
            RedrawBgMapAt(1, 0, 0);
            gUnk_02039DC8->unk_79 = 1;
        } else {
            DisableBg(1);
        }
    }
    return 1;
}
u8 eu_0806C974(EventSeqWork* work) {
    EventBackgroundDef* u = gUnk_09EE3CA0[work->unk_2C];
    EventCameraKeyframe* q = work->seqDef->keyframes;
    u16 i;
    gUnk_02039DC8->unk_50 = q->unk_04;
    gUnk_02039DC8->unk_54 = q->unk_08;
    gUnk_02039DC8->unk_48 = gUnk_02039DC8->unk_50 - 0x7800;
    gUnk_02039DC8->unk_4C = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_64 = 0;
    gUnk_02039DC8->unk_6C = 0;
    gUnk_02039DC8->unk_7C = 0;
    gUnk_02039DC8->unk_87 = 0;
    gUnk_02039DC8->unk_81 = 0;
    gUnk_02039DC8->unk_88 = 0;
    gUnk_02039DC8->unk_89 = 0;
    gUnk_02039DC8->unk_7D = 0;
    gUnk_02039DC8->unk_7E = 0;
    gUnk_02039DC8->unk_60 = 0;
    if (u->unk_20 != 5) {
        gUnk_02039DC8->unk_44 = u->unk_20;
        work->unk_3D = 1;
    } else {
        gUnk_02039DC8->unk_44 = u->unk_20;
    }
    for (i = 0; i < 16; i++) {
        gUnk_02039DC8->unk_00[i] = NULL;
    }
    return 1;
}
#endif
u8 event_seq_1(EventSeqWork* work, void* a) {
    EventSeqArg arg;
#ifndef VERSION_EU
    s32 flag;
#endif
    EventBackgroundDef* u;
    EventSequenceDef* t;
#ifndef VERSION_EU
    EventCameraKeyframe* q;
    u16 i;
#endif
    u8 j;

#ifndef VERSION_EU
    flag = 0;
#endif
    u = gUnk_09EE3CA0[work->unk_2C];
#ifndef VERSION_EU

    if (u != NULL) {
        if (u->tiles2 != NULL) {
            if ((u->unk_2D & 1) != 0) {
                SetupBg(0, 3, 31, 14);
                SetupBg(1, 0, 29, 0);
                SetupBg(2, 2, 30, 0);
                SetupBg(3, 0, 28, 0);
            } else {
                SetupBg(0, 3, 31, 14);
                SetupBg(1, 2, 30, 0);
                SetupBg(2, 0, 22, 0);
                SetupBg(3, 0, 23, 0);
            }
        }

        if (u->unk_24 != 0) {
            LoadBgTiles(2, u->tiles, u->tilesSize);
            LoadBgPalette(2, u->palette, u->paletteSize);
            SetBgColorMode(2, 128);
            SetBgSize(2, 0x8000);
            LoadBgMap(2, (void*)*u->maps, 0x1000);
            SetBgAffine(2, 0, 256, 256, 0, 0);
        } else {
            LoadBgTiles(3, u->tiles, u->tilesSize);
            LoadBgPalette(3, u->palette, u->paletteSize);

            if (u->tiles2 != NULL) {
                if ((u->unk_2D & 1) != 0) {
                    LoadBgTiles(2, u->tiles2, u->tilesSize2);
                } else {
                    LoadBgTiles(1, u->tiles2, u->tilesSize2);
                }
            }

            if (u->maps != NULL) {
                SetBgMapBlocks(3, u->maps, u->mapWidth, u->mapHeight);
                RedrawBgMapAt(3, 0, 0);
            }

            if (u->maps2 != NULL) {
                SetBgMapBlocks(2, u->maps2, u->mapWidth, u->mapHeight);
                RedrawBgMapAt(2, 0, 0);
                gUnk_02039DC8->unk_78 = 1;
            } else {
                DisableBg(2);
            }

            if (u->maps3 != NULL) {
                if ((u->unk_2D & 2) != 0) {
                    gBldCnt = 0x1844;
                    (*(volatile u16*)&gBldAlpha) = 0x050E;
                    SetBgPriority(2, 1);
                    gUnk_02039DC8->unk_6E = 0x1D42;
                    gUnk_02039DC8->unk_70 = 0x050E;
                } else {
                    gUnk_02039DC8->unk_6E = 0;
                    gUnk_02039DC8->unk_70 = 0;
                }

                SetBgMapBlocks(1, u->maps3, u->mapWidth, u->mapHeight);
                RedrawBgMapAt(1, 0, 0);
                gUnk_02039DC8->unk_79 = 1;
            } else {
                DisableBg(1);
            }
        }
    }

    q = work->seqDef->keyframes;
    gUnk_02039DC8->unk_50 = q->unk_04;
    gUnk_02039DC8->unk_54 = q->unk_08;
    gUnk_02039DC8->unk_48 = gUnk_02039DC8->unk_50 - 0x7800;
    gUnk_02039DC8->unk_4C = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_64 = 0;
    gUnk_02039DC8->unk_6C = 0;
    gUnk_02039DC8->unk_7C = 0;
    gUnk_02039DC8->unk_87 = 0;
    gUnk_02039DC8->unk_81 = 0;
    gUnk_02039DC8->unk_88 = 0;
    gUnk_02039DC8->unk_89 = 0;
    gUnk_02039DC8->unk_7D = 0;
    gUnk_02039DC8->unk_7E = 0;
    gUnk_02039DC8->unk_60 = 0;

    if (u->unk_20 != 5) {
        gUnk_02039DC8->unk_44 = u->unk_20;
        flag = 1;
    } else {
        gUnk_02039DC8->unk_44 = 5;
    }

    i = 0;
    t = work->seqDef;

    while (i < 16) {
        gUnk_02039DC8->unk_00[i] = NULL;
        i++;
    }

#else
    t = work->seqDef;
#endif

    TaskPoolInit(&work->tasks, t->unk_00 + 8);
    TaskPoolInit(&work->tasks2, 1);
    work->unk_28 = (u32)TaskCreate(&work->tasks2, &gTaskDescMsgwin, &work->unk_2C);

    for (j = 0; j < t->unk_00; j++) {
        arg.unk_00 = work->unk_2C;
        arg.unk_02 = t->charaTracks[j].unk_04;
        arg.unk_03 = j;

        if (arg.unk_02 > 94) {
            work->unk_32 = 1;
            gUnk_02039DC8->unk_60 = arg.unk_02;
        }

        TaskCreate(&work->tasks, &gTaskDescEventChara, &arg);
    }

    TaskCreate(&work->tasks, &gTaskDescView, &work->unk_2C);
    TaskCreate(&work->tasks, &gTaskDescEvSound, &work->unk_2C);
    TaskCreate(&work->tasks, &gTaskDescEVBGEFFECT, &work->unk_2C);

#ifdef VERSION_EU
    if (work->unk_3D != 0) {
#else
    if (flag != 0) {
#endif
        TaskCreate(&work->tasks, &gTaskDescMapAnim, NULL);
    }

#ifndef VERSION_EU
    if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0) {
        FadeStartIn(0, 64);
    } else if ((work->seqDef->keyframes->unk_14 & 0xFF0) == 0x80) {
        FadeStartIn(1, 120);
    }

    work->unk_38 = 0;
#endif

    if (u != NULL) {
        if (u->mapObjects != 0) {
            TaskCreate(&work->tasks, &gTaskDescEvMapObj, &work->unk_2C);
        }

        if ((u->unk_2D & 1) != 0) {
            func_080CA35C();
            TaskCreate(&work->tasks, &gTaskDescPooMapanime, NULL);
        }
    }

    SetTaskUpdate(a, (void*)func_0806D830);
    return 1;
}
u8 func_0806D808(void) {
    u8 r = FadeIsActive();
    u8 v;

    if (r != 0) {
        v = 1;
    } else {
        gUnk_02039DC8->unk_7A = 0;
        m4aMPlayAllStop();
        v = 0;
    }
    return v;
}
u8 func_0806D830(EventSeqWork* p, void* a) {
    EventSequenceDef* t;
    u8 i;

    if (gUnk_02039DC8 == NULL) {
        return 0;
    }

    if ((GetKeysHeld() & 8) != 0) {
        switch (p->unk_2C) {
        case 68:
        case 83:
        case 84:
            break;
        default:
            gUnk_02039DC8->unk_8A++;
            break;
        }
    } else {
        gUnk_02039DC8->unk_8A = 0;
    }

    if (gUnk_02039DC8->unk_8A > 64 || gUnk_02039DC8->unk_83 == 1) {
        gUnk_02039DC8->unk_8A = 64;
        p->unk_2F = 1;
        gUnk_02039DC8->unk_82 = 1;
        FadeStartOut(0, 64);
        SetTaskUpdate(a, (u32)func_0806D808);

        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 0);
        }
        return 1;
    }

    if (p->unk_38 == p->seqDef->unk_24) {
        gUnk_02039DC8->unk_64 |= 2;
    } else {
        s32 t = p->seqDef->keyframes->unk_14 & 0xFF0;

        if (t == 0) {
            FadeStartIn(0, 64);
        } else if (t == 128) {
            FadeStartIn(1, 120);
        }
        p->unk_38++;
    }
    TaskPoolUpdate(&p->tasks);
    TaskPoolUpdate(&p->tasks2);

    if (p->unk_32 != 0) {
        gBtlWork->unk_000 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_004 = gUnk_02039DC8->unk_4C;
    }

    if ((gUnk_02039DC8->unk_64 & 3) == 2) {
        gUnk_02039DC8->unk_6C++;
    }

    t = gUnk_09EE3FB4[p->unk_2C];

    if (gUnk_02039DC8->unk_6C >= t->unk_18 && p->unk_2F == 0 && FadeIsActive() == 0) {
        if (gUnk_02039DC8->unk_7F == 0) {
            FadeStartOut(0, 64);
        }
        p->unk_2F = 1;
        gUnk_02039DC8->unk_82 = 1;
    }

    if (p->unk_2F == 1) {
        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 0);
        }

        if (FadeIsActive() == 0) {
            gUnk_02039DC8->unk_7A = 0;
            return 0;
        }
    }
    return 1;
}
void event_seq_2(EventSeqWork* p) {
    TaskPoolDraw(&p->tasks2);

    if (p->unk_32 != 0) {
        TaskPoolDraw(&gBtlWork->taskPools[0]);
    }
    TaskPoolDraw(&p->tasks);
}
void event_seq_3(EventSeqWork* p) {
    TaskPoolDestroy(&p->tasks);

    if (p->unk_28 != 0) {
        TaskPoolDestroy(&p->tasks2);
    }
#ifdef VERSION_EU
    if (p->unk_3A != 0) {
        eu_08005ADC(3);
    }

    if (p->unk_3B != 0) {
        eu_08005ADC(2);
    }

    if (p->unk_3C != 0) {
        eu_08005ADC(1);
    }
#endif
}
void event_chara_0(EventCharaWork* p, u32* a) {
    s32 v0;
    s32 v1;

    TaskPoolInit(&p->tasks, 8);
    *(s32*)&p->unk_024 = *a;
    p->keyframes = gUnk_09EE3FB4[p->unk_024]->charaTracks[p->unk_027].keyframes;
    p->unk_1A0 = 0;
    p->unk_1A4 = p->keyframes->unk_04;
    p->unk_188 = 0;
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_1A9 = 0;
    p->unk_1AA = 0;
    p->unk_180 = 0;
    p->unk_184 = 0;
    p->tiles = NULL;
    p->palette = NULL;
    p->gfx = NULL;
    p->unk_1B1 = 0;
    p->unk_1B2 = 0;
    p->unk_1B3 = 0;
    p->unk_1B5 = 0;
    p->unk_1B0 = 0;
    p->unk_1B6 = 1;
    p->unk_1B8 = 0;
    gUnk_02039DC8->unk_00[p->unk_027] = (Ent08074EC8*)p->unk_028;

    switch (p->unk_026) {
    case 95:
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        gBtlWork->unk_068 = 0;
        p->unk_1B3 = 1;
        gBtlWork->unk_000 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_004 = gUnk_02039DC8->unk_4C;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        gBtlWork->unk_028 = 0x100;
        gBtlWork->x = gUnk_02039DC8->unk_48;
        gBtlWork->y = gUnk_02039DC8->unk_4C;
        gBtlWork->x2 = 0x10000;
        gBtlWork->y2 = 0x14000;
        gBtlWork->unk_01C = 0x10000;
        gBtlWork->unk_020 = 0x14000;
        gBtlWork->unk_01A = 15;
        p->unk_02C = p->keyframes->unk_08;
        p->unk_030 = p->keyframes->unk_0C;
        p->unk_034 = p->keyframes->unk_10;
        TaskCreate(&p->tasks, &gTaskDescBosTm, p->unk_028);
        break;
    case 96:
        gBtlWork = EwramAlloc(464);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        SetBattleBounds(128, 424, 294, 384);
        gUnk_02039DC8->unk_00[16] = TaskCreate(&p->tasks, &gTaskDescBosPc, NULL);
        break;
    case 97:
        gBtlWork = EwramAlloc(464);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        SetBattleBounds(128, 424, 294, 384);
        gUnk_02039DC8->unk_00[16] = TaskCreate(&p->tasks, &gTaskDescBosPc, &p->tasks);
        p->unk_1B4 = 0;
        gUnk_02039DC8->unk_48 = v0 = gBtlWork->unk_000;
        gUnk_02039DC8->unk_4C = v1 = gBtlWork->unk_004;
        gUnk_02039DC8->unk_50 = gBtlWork->x;
        gUnk_02039DC8->unk_54 = gBtlWork->y;
        gUnk_02039DC8->x = v0;
        gUnk_02039DC8->y = v1;
        break;
    case 100:
        SetBgSize(1, 0x4000);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        SetBattleBounds(128, 368, 480, 512);
        gUnk_02039DC8->unk_00[16] = TaskCreate(&p->tasks, &gTaskDescBosLst, &p->tasks);
        break;
    case 101:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->x = 0x26600;
        gBtlWork->y = 0x12800;
        gBtlWork->unk_000 = 0x26600;
        gBtlWork->unk_004 = 0x12800;
        gBtlWork->x2 = 0x26600;
        gBtlWork->y2 = 0x12800;
        p->unk_02C = 0x2A200;
        p->unk_030 = 0x15E00;
        p->unk_034 = -0x3800;
        SetBattleBounds(420, 612, 328, 384);
        TaskCreate(&p->tasks, &gTaskDescBosJf, p->unk_028);
        break;
    case 103:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        gBtlWork->unk_068 = 0;
        p->unk_1B3 = 1;
        gBtlWork->x = 0x12C00;
        gBtlWork->y = 0x16800;
        gBtlWork->unk_000 = 0x12C00;
        gBtlWork->unk_004 = 0x16800;
        gBtlWork->x2 = 0x12C00;
        gBtlWork->y2 = 0x16800;
        gUnk_02039DC8->unk_48 = gBtlWork->x - 0x7800;
        gUnk_02039DC8->unk_4C = gBtlWork->y - 0x5000;
        gUnk_02039DC8->unk_50 = gBtlWork->x;
        gUnk_02039DC8->unk_54 = gBtlWork->y;
        gUnk_02039DC8->unk_68 = 0;
        gUnk_02039DC8->unk_6A = 0;
        p->unk_02C = p->keyframes->unk_08;
        p->unk_030 = p->keyframes->unk_0C;
        p->unk_034 = p->keyframes->unk_10;
        SetBattleBounds(0, 256, 328, 424);
        TaskCreate(&p->tasks, &gTaskDescBosDsd, p->unk_028);
        break;
    case 98:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->tasks, &gTaskDescBosBoogie, NULL);
        gBtlWork->unk_0B3 = 5;
        break;
    case 99:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->tasks, &gTaskDescBosUrsula, NULL);
        gBtlWork->unk_0B3 = 5;
        break;
    case 104:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->actor = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->tasks, &gTaskDescBosGa, (void*)1);
        gBtlWork->unk_0B3 = 5;
        break;
    default:
        if ((p->keyframes->unk_18 & 0x2000) == 0) {
            func_0801CD98(&p->tasks, p->unk_028, p->unk_026, p->keyframes->unk_00, p->keyframes->unk_08, p->keyframes->unk_0C, p->keyframes->unk_10);
            p->unk_1B4 = 1;
        } else {
            p->unk_1B4 = 0;
        }

        func_08072C34(p);
        break;
    }

    if (p->unk_1B4 != 0) {
        func_0806F94C(p);
    }
}
u8 event_chara_1(EventCharaWork* p, void* a) {
    u8 t;
    s32 v0;
    s32 v1;

    t = func_0806E570(p);

    if (p->unk_1B4 != 0) {
        func_0806E7A8(p);
    }
    func_08070AD4(p);

    if (t != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
            ((void (*)(EventCharaWork*, void*))p->keyframes[p->unk_1A0].unk_1C)(p, a);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }

    if (p->keyframes[p->unk_1A0].unk_18 & 0x100) {
        p->unk_03C |= 4;
    } else {
        p->unk_03C &= ~4;
    }

    if (p->keyframes[p->unk_1A0].unk_18 & 0x200) {
        gUnk_02039DC8->unk_64 |= 1;
        gUnk_02039DC8->unk_64 |= 4;
        p->unk_19C = 0;
        SetTaskUpdate(a, (void*)func_080700D4);
    }
    TaskPoolUpdate(&p->tasks);

    if (p->unk_1B3 != 0) {
        switch (p->unk_026) {
        case 0x62:
            gUnk_02039DC8->x = gUnk_02039DC8->unk_48 = gBtlWork->x2;
            gUnk_02039DC8->y = gUnk_02039DC8->unk_4C = gBtlWork->y2;
            TaskPoolUpdate(&gBtlWork->taskPools[1]);
            break;
        case 0x63:
            gBtlWork->unk_004 = gBtlWork->y;
            gBtlWork->x2 = gUnk_02039DC8->unk_48;
            gBtlWork->y2 = gUnk_02039DC8->unk_4C;
            gUnk_02039DC8->x = gUnk_02039DC8->unk_48;
            gUnk_02039DC8->y = gUnk_02039DC8->unk_4C;
            TaskPoolUpdate(&gBtlWork->taskPools[0]);
            TaskPoolUpdate(&gBtlWork->taskPools[1]);
            break;
        case 0x65:
            gUnk_02039DC8->unk_48 = v0 = gBtlWork->unk_000;
            gUnk_02039DC8->unk_4C = v1 = gBtlWork->unk_004;
            gUnk_02039DC8->unk_50 = gBtlWork->x;
            gUnk_02039DC8->unk_54 = gBtlWork->y;
            gUnk_02039DC8->x = v0;
            gUnk_02039DC8->y = v1;
            break;
        case 0x61:
            gBtlWork->x2 = gUnk_02039DC8->unk_50;
            gBtlWork->y2 = gUnk_02039DC8->unk_54;
            break;
        case 0x67:
            break;
        }
    }

    if (p->unk_026 == 0) {
        if (gBtlWork != NULL) {
            gBtlWork->actor->x = p->unk_02C - 0x7800;
            gBtlWork->actor->y = p->unk_030 - 0x5000;
            gBtlWork->actor->z = 0;
        }
    }

    if (p->unk_1B5 != 0) {
        return 0;
    }

    if (p->keyframes[p->unk_1A0].unk_18 & 0x100000) {
        if (gFrameCounter % 6 == 0) {
            u16 v = GetRandom() % 7 + 4;

            (*(volatile u16*)&gBldAlpha) = ((16 - v) << 8) | v;
        }
    }
    return 1;
}
static inline s16 GetEventCharaScreenX(EventCharaWork* p) {
    return (p->unk_180 >> 8) - (gUnk_02039DC8->x >> 8);
}

void event_chara_2(EventCharaWork* p) {
    EventCharaKeyframe* e;
    s32 save;
    s32 x;
    s32 y;
    u16 h;

    save = p->unk_034;
    e = &p->keyframes[p->unk_1A0];

    if (e->unk_18 & 0x80) {
        p->unk_034 = gSineTable[p->unk_1B0] * 2 + save;
    } else if (e->unk_18 & 0x40000) {
        p->unk_034 = gSineTable[p->unk_1B0] * 3 + save;
    }

    if (p->unk_1B6 != 0) {
        TaskPoolDraw(&p->tasks);
    }

    if (p->unk_026 == 99) {
        TaskPoolDraw(&gBtlWork->taskPools[0]);
    }

    if (p->tiles != NULL) {
        h = p->unk_03E;

        if (p->unk_1B1 == 0) {
            h &= 0xFFFE;
        } else {
            h |= 1;
        }
        x = GetEventCharaScreenX(p);
        y = (p->unk_184 >> 8) + gUnk_0903380C[p->unk_026].spriteYOffset - (gUnk_02039DC8->y >> 8);
        DrawSprite(x, y, p->gfx, p->tiles, p->palette, 0, h, 50);
    }
    p->unk_034 = save;
}
void event_chara_3(EventCharaWork* p) {
    TaskPoolDestroy(&p->tasks);

    if (p->unk_1B3 != 0) {
        TaskPoolDestroy(&gBtlWork->taskPools[0]);
        TaskPoolDestroy(&gBtlWork->taskPools[1]);
        EwramFree(gBtlWork);
    }
}
u8 func_0806E570(EventCharaWork* p) {
    EventCharaKeyframe* e = &p->keyframes[p->unk_1A0];
    u16 v;

    if (p->keyframes[p->unk_1A0].unk_04 > gUnk_02039DC8->unk_6C) {
        return 0;
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x8000) != 0) {
        return 0;
    }

    p->unk_1A0++;
    p->unk_1A4 = p->keyframes[p->unk_1A0].unk_04 - gUnk_02039DC8->unk_6C;
    p->unk_17C = p->keyframes[p->unk_1A0].unk_00;

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x4000) != 0) {
        func_0801CD98(&p->tasks, p->unk_028, p->unk_026, p->keyframes[p->unk_1A0].unk_00,
                      p->keyframes[p->unk_1A0].unk_08, p->keyframes[p->unk_1A0].unk_0C,
                      p->keyframes[p->unk_1A0].unk_10);
        p->unk_1B4 = 1;
        func_08072C34(p);
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x10000) != 0) {
        p->unk_1B5 = 1;
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x800) != 0) {
        LoadPalette(&gUnk_096148D8[0x100], (void*)(p->unk_044 * 32 + 0x05000200), 32);
    } else if ((p->keyframes[p->unk_1A0 - 1].unk_18 & 0x800) != 0) {
        LoadPalette(gUnk_0813B09C[p->unk_026].res.palette, (void*)(p->unk_044 * 32 + 0x05000200), 32);
    }

    if ((p->keyframes[p->unk_1A0].unk_18 & 0x100000) != 0) {
        gBldCnt = 0xF40;
        v = p->unk_03E;
        func_0801CE00(p->unk_028, v | 4);
    } else {
        v = p->unk_03E;
        func_0801CE00(p->unk_028, p->unk_03E & 0xFFFB);
        p->unk_1B8 = 0;
    }

    if (p->unk_1B4 != 0) {
        if ((p->keyframes[p->unk_1A0].unk_18 & 15) == 2) {
            EvtObjSetPos(p->unk_028, p->keyframes[p->unk_1A0].unk_08, p->keyframes[p->unk_1A0].unk_0C, p->keyframes[p->unk_1A0].unk_10);
        }

        func_0801CD74(p->unk_028, p->unk_17C);
        func_0806F94C(p);
        return 1;
    }

    if (p->keyframes[p->unk_1A0].unk_00 == 0x3AF) {
        func_0810B350(gUnk_02039DC8->unk_00[16]);
    }

    if (p->keyframes[p->unk_1A0].unk_00 == 0x3AB) {
        func_0810C2C4(gUnk_02039DC8->unk_00[16]);
    }

    return 0;
}
void func_0806E7A8(EventCharaWork* p) {
    EventCharaKeyframe* e = &p->keyframes[p->unk_1A0];
    BtlObj* t;

    if (e->unk_00 == 0x3A7) {
        t = ListPoolFirst(&gBtlWork->pool);

        if (t != NULL) {
            t->unk_034 |= 2;
        }
    }

    switch (e->unk_18 & 15) {
    case 2:
        EvtObjSetPos(p->unk_028, p->keyframes[p->unk_1A0].unk_08, p->keyframes[p->unk_1A0].unk_0C, p->keyframes[p->unk_1A0].unk_10);
        break;
    case 3:
        ApproachValue(&p->unk_02C, p->keyframes[p->unk_1A0].unk_08, p->unk_1A4);
        ApproachValue(&p->unk_030, p->keyframes[p->unk_1A0].unk_0C, p->unk_1A4);
        ApproachValue(&p->unk_034, p->keyframes[p->unk_1A0].unk_10, p->unk_1A4);
        p->unk_1A4--;

        if (p->unk_1A4 == 0) {
            if ((p->keyframes[p->unk_1A0].unk_18 & 0x1000) == 0) {
                func_0806E9BC(p);
            }
        }
        break;
    case 4:
        if ((e->unk_18 & 32) == 0) {
            p->unk_19C = gUnk_0903380C[p->unk_026].unk_02;
        } else {
            p->unk_19C = gUnk_0903380C[p->unk_026].unk_04;
        }

        if (e->unk_14 == 1) {
            p->unk_034 -= p->unk_19C;
        } else if (e->unk_14 == 2) {
            p->unk_034 += p->unk_19C;
        } else {
            p->unk_02C += (gSineTable[e->unk_14 & 0xFF] * p->unk_19C) >> 8;
            p->unk_030 += (-gSineTable[(e->unk_14 & 0xFF) + 64] * p->unk_19C) >> 8;
        }
        break;
    }

    if ((e->unk_18 & 0x80) != 0) {
        p->unk_1B0 += 4;
    } else if ((e->unk_18 & 0x40000) != 0) {
        p->unk_1B0 += 4;
    } else {
        p->unk_1B0 = 0;
    }

    if ((e->unk_18 & 0x80000) != 0) {
        p->unk_1B6 ^= 1;
    } else {
        p->unk_1B6 = 1;
    }
}

void func_0806E9BC(EventCharaWork* p) {
    EventCharaKeyframe* e = &p->keyframes[p->unk_1A0];

    func_0801CD74(p->unk_028, e->unk_14);
}

u8 _0806E9DC(EventCharaWork* p, void* a) {
    p->unk_188 = 0x800;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (void*)func_0806EA28);
    return 1;
}
u8 func_0806EA28(EventCharaWork* p, void* a) {
    u16 x;
    u16 y;
    u8 t;

    x = (p->unk_02C >> 8) - (gUnk_02039DC8->x >> 8);
    y = (p->unk_030 >> 8) + (p->unk_034 >> 8) - (gUnk_02039DC8->y >> 8);
    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188 / 4;
        p->unk_188 -= p->unk_18C / 4;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
        if (p->unk_1A8 == 0) {
            if (p->unk_026 == 10) {
                m4aSongNumStart(0x144);
                func_08076110(0x144, x, y);
            }
        }
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0x800;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806EB94(EventCharaWork* p, void* a) {
    p->unk_188 = 0xC00;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (void*)func_0806EBE0);
    return 1;
}
u8 func_0806EBE0(EventCharaWork* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188 / 4;
        p->unk_188 -= p->unk_18C / 4;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806ECE0(EventCharaWork* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (void*)func_0806ED2C);
    return 1;
}
u8 func_0806ED2C(EventCharaWork* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_08070AD4(p);
    func_0806E7A8(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188;
        p->unk_188 -= p->unk_18C;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0x800;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806EE20(EventCharaWork* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->tasks);
    SetTaskUpdate(a, (void*)func_0806EE6C);
    return 1;
}
u8 func_0806EE6C(EventCharaWork* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188;
        p->unk_188 -= p->unk_18C;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > 0) {
        p->unk_034 = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806EF40(void* work, void* a) {
    EventCharaWork* p = work;
    EventCharaKeyframe* e;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    (*(volatile u16*)&gBldAlpha) = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806F02C);

    if (p->unk_026 == 3) {
        e = &p->keyframes[p->unk_1A0];
        if ((e->unk_18 & 0x80000) == 0) {
            m4aSongNumStart(0x14A);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F02C(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = ((16 - p->unk_1A9) << 8) | p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
        {
            u16 z = p->unk_03E;

            z &= 0xFFFB;
            func_0801CE00(p->unk_028, z);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F114(void* work, void* a) {
    EventCharaWork* p = work;
    EventCharaKeyframe* e;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    (*(volatile u16*)&gBldAlpha) = 0x1000;
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (void*)func_0806F204);

    if (p->unk_026 == 3) {
        e = &p->keyframes[p->unk_1A0];
        if ((e->unk_18 & 0x80000) == 0) {
            m4aSongNumStart(0x14B);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F204(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 <= 15) {
            p->unk_1A9++;
        }
    }
    (*(volatile u16*)&gBldAlpha) = ((16 - p->unk_1A9) << 8) | p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
        {
            u16 z = p->unk_03E;

            z &= 0xFFFB;
            func_0801CE00(p->unk_028, z);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F2EC(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    (*(volatile u16*)&gBldAlpha) = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (void*)func_0806F3A8);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F3A8(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 <= 15) {
            p->unk_1A9++;
        }
    }
    (*(volatile u16*)&gBldAlpha) = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F47C(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    (*(volatile u16*)&gBldAlpha) = 0x1010;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806F53C);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F53C(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F610(EventCharaWork* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (void*)func_0806F64C);
    return 1;
}
u8 func_0806F64C(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_02C += gSineTable[(u8)p->unk_18C] * (p->unk_198 >> 8);
    p->unk_030 += -gSineTable[(u8)p->unk_18C + 64] * (p->unk_198 >> 9);
    p->unk_18C += 2;

    if (p->unk_198 < 0x200) {
        p->unk_198 += 25;
    }

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F734(EventCharaWork* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (void*)func_0806F770);
    return 1;
}
u8 func_0806F770(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_02C += gSineTable[(u8)p->unk_18C] * (p->unk_198 >> 8);
    p->unk_030 += -gSineTable[(u8)p->unk_18C + 64] * (p->unk_198 >> 9);
    p->unk_18C += 6;

    if (p->unk_198 < 0x200) {
        p->unk_198 += 25;
    }

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806F858(EventCharaWork* p, void* a) {
    p->unk_18C = 1;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (void*)func_0806F898);
    return 1;
}
u8 func_0806F898(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_198 == 2) {
        p->unk_034 += p->unk_18C << 10;
        p->unk_18C = -p->unk_18C;
        p->unk_198 = 0;
    } else {
        p->unk_198++;
    }

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
void func_0806F94C(EventCharaWork* p) {
    u16 z;

    z = p->unk_03E;

    if (p->keyframes[p->unk_1A0].unk_18 & 0x40) {
        if (p->keyframes[p->unk_1A0].unk_18 & 0x10) {
            z |= 0x401;
            z &= 0xF7FF;
            func_0801CE00(p->unk_028, z);
        } else {
            z |= 0x801;
            z &= 0xFBFF;
            func_0801CE00(p->unk_028, z);

            if ((p->keyframes[p->unk_1A0].unk_18 & 0x400) == 0) {
                z |= 0x801;
                func_0801CE00(p->unk_028, z);
            } else {
                z |= 1;
                z &= 0xF7FF;
                func_0801CE00(p->unk_028, z);
            }
        }
    } else {
        if (p->keyframes[p->unk_1A0].unk_18 & 0x10) {
            z |= 0x400;
            z &= 0xF7FF;
            z &= 0xFFFE;
            func_0801CE00(p->unk_028, z);
        } else {
            z |= 0x800;
            z &= 0xFBFF;
            z &= 0xFFFE;
            func_0801CE00(p->unk_028, z);

            if ((p->keyframes[p->unk_1A0].unk_18 & 0x400) == 0) {
                z |= 0x800;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            } else {
                z &= 0xF7FF;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            }
        }
    }
}
u8 func_0806FA84(EventCharaWork* p, void* a) {
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (void*)func_0806FAB8);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FAB8(EventCharaWork* p, void* a) {
    u16 buf[2];

    memcpy(buf, gUnk_09033C8C, 4);
    func_0801CD74(p->unk_028, buf[p->unk_1A9]);
    p->unk_1AA++;
    if (p->unk_1AA == 12) {
        p->unk_1AA = 0;
        p->unk_1A9 ^= 1;
    }

    if (func_0806E570(p) != 0) {
        if (p->tiles != NULL) {
            ReleaseObjTiles(p->tiles);
        }

        if (p->palette != NULL) {
            ReleaseObjPalette(p->palette);
        }
        p->tiles = NULL;
        p->palette = NULL;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FB6C(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    (*(volatile u16*)&gBldAlpha) = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806FC28);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FC28(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FCF4(void* work, void* a) {
    EventCharaWork* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    (*(volatile u16*)&gBldAlpha) = 0;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806FDB0);
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0806FDB0(EventCharaWork* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    (*(volatile u16*)&gBldAlpha) = (16 - p->unk_1A9) | (p->unk_1A9 << 8);
    (*(volatile u16*)&gBldAlpha) = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->keyframes[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->keyframes[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->keyframes[p->unk_1A0].unk_20 != NULL) {
            p->keyframes[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->tasks);
    return 1;
}
void func_0806FE90(EventCharaWork* p) {
    u16 keys = GetKeysHeld();

    switch (keys & 0xF0) {
    case 0x40:
        if (GetKeyReleaseTime(0x20) <= 4) {
            p->unk_1AB = 211;
        } else if (GetKeyReleaseTime(0x10) <= 4) {
            p->unk_1AB = 45;
        } else {
            p->unk_1AB = 0;
        }
        break;
    case 0x80:
        if (GetKeyReleaseTime(0x20) <= 4) {
            p->unk_1AB = 173;
        } else if (GetKeyReleaseTime(0x10) <= 4) {
            p->unk_1AB = 83;
        } else {
            p->unk_1AB = 128;
        }
        break;
    case 0x20:
        if (GetKeyReleaseTime(0x40) <= 4) {
            p->unk_1AB = 211;
        } else if (GetKeyReleaseTime(0x80) <= 4) {
            p->unk_1AB = 173;
        } else {
            p->unk_1AB = 192;
        }
        break;
    case 0x10:
        if (GetKeyReleaseTime(0x40) <= 4) {
            p->unk_1AB = 45;
        } else if (GetKeyReleaseTime(0x80) <= 4) {
            p->unk_1AB = 83;
        } else {
            p->unk_1AB = 64;
        }
        break;
    case 0x50:
        p->unk_1AB = 45;
        break;
    case 0x60:
        p->unk_1AB = 211;
        break;
    case 0x90:
        p->unk_1AB = 83;
        break;
    case 0xA0:
        p->unk_1AB = 173;
        break;
    }
}

void func_08070008(EventCharaWork* p) {
    u8 old = p->unk_1AB;

    func_0806FE90(p);

    if (old != p->unk_1AB) {
        if (abs((s8)GetAngleDiff(old, p->unk_1AB)) > 100) {
            p->unk_19C = 0;
        } else {
            p->unk_19C >>= 1;
        }
    }
}

void func_08070058(EventCharaWork* p, s32 a) {
    u16 f;

    f = p->unk_03E;

    switch (p->unk_1AB) {
    case 0xD3:
        f &= 0xFFFE;
        break;
    case 0x2D:
    case 0x40:
    case 0x53:
        f |= 1;
        break;
    case 0x00:
    case 0x80:
    case 0xAD:
    case 0xC0:
        f &= 0xFFFE;
        break;
    }

    if (a != p->unk_17C) {
        func_0801CD74(p->unk_028, a);
        p->unk_17C = a;
    }
    func_0801CE00(p->unk_028, f);
}
u8 func_080700D4(EventCharaWork* p, void* a) {
    u16 keys;
    s32 v;

    keys = GetKeysHeld();
    func_0806FE90(p);

    switch (p->unk_1AB) {
    case 0x00:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 5);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 10);
        }
        break;
    case 0x80:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 6);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 11);
        }
        break;
    case 0xC0:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 8);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 13);
        }
        break;
    case 0x40:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 8);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 13);
        }
        break;
    case 0xD3:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 9);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 14);
        }
        break;
    case 0x2D:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 9);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 14);
        }
        break;
    case 0xAD:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 7);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 12);
        }
        break;
    case 0x53:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 7);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 12);
        }
        break;
    }

    if ((keys & 0xF0) != 0) {
        v = p->unk_19C + 51;
        p->unk_19C = v;

        switch (p->unk_1AD) {
        case 1:
            if (v > gUnk_0903380C[p->unk_026].unk_02) {
                p->unk_19C = gUnk_0903380C[p->unk_026].unk_02;
            }
            break;
        case 2:
            if (v > gUnk_0903380C[p->unk_026].unk_04) {
                p->unk_19C = gUnk_0903380C[p->unk_026].unk_04;
            }
            break;
        }
    } else {
        p->unk_19C -= 102;

        if (p->unk_19C < 0) {
            p->unk_19C = 0;
        }

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 0);
            break;
        case 0x80:
            func_08070058(p, 1);
            break;
        case 0xC0:
            func_08070058(p, 3);
            break;
        case 0x40:
            func_08070058(p, 3);
            break;
        case 0xAD:
            func_08070058(p, 2);
            break;
        case 0x53:
            func_08070058(p, 2);
            break;
        case 0xD3:
            func_08070058(p, 4);
            break;
        case 0x2D:
            func_08070058(p, 4);
            break;
        }
    }

    if ((GetKeysPressed() & 2) != 0) {
        p->unk_1AF = 0;
        p->unk_1A8 = 0;
        SetTaskUpdate(a, (void*)func_0807048C);
    }

    v = p->unk_02C + (gSineTable[p->unk_1AB] * p->unk_19C >> 8);
    p->unk_02C = v;
    p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;

    if (p->unk_026 == 0) {
        if (gBtlWork != NULL) {
            gBtlWork->actor->x = v - 0x7800;
            gBtlWork->actor->y = p->unk_030 - 0x5000;
            gBtlWork->actor->z = 0;
        }
    }

    p->unk_1AC = p->unk_1AB;
    p->unk_1AE = p->unk_1AD;
    TaskPoolUpdate(&p->tasks);
    return 1;
}
u8 func_0807048C(EventCharaWork* p, void* a) {
    u16 keys = GetKeysHeld();

    if ((keys & 0xF0) != 0) {
        p->unk_19C += 5;
    }

    switch (p->unk_1AF) {
    case 0:
        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 38);
            break;
        case 0x80:
            func_08070058(p, 44);
            break;
        case 0xC0:
            func_08070058(p, 56);
            break;
        case 0x40:
            func_08070058(p, 56);
            break;
        case 0xAD:
            func_08070058(p, 50);
            break;
        case 0x53:
            func_08070058(p, 50);
            break;
        case 0xD3:
            func_08070058(p, 62);
            break;
        case 0x2D:
            func_08070058(p, 62);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * (p->unk_19C >> 2) >> 8;
        p->unk_030 += -gSineTable[p->unk_1AB + 64] * (p->unk_19C >> 2) >> 8;

        if (p->unk_1A8 > 3) {
            p->unk_1AF = 1;
            p->unk_18C = -0x540;
            p->unk_198 = p->unk_034;
            p->unk_1A8 = 0;
        } else {
            p->unk_1A8++;
        }
        break;
    case 1:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 39);
            break;
        case 0x80:
            func_08070058(p, 45);
            break;
        case 0xC0:
            func_08070058(p, 57);
            break;
        case 0x40:
            func_08070058(p, 57);
            break;
        case 0xAD:
            func_08070058(p, 51);
            break;
        case 0x53:
            func_08070058(p, 51);
            break;
        case 0xD3:
            func_08070058(p, 63);
            break;
        case 0x2D:
            func_08070058(p, 63);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_18C += 51;
        p->unk_034 += p->unk_18C;

        if ((GetKeysHeld() & 2) == 0) {
            p->unk_18C += 64;
        }

        if (p->unk_18C > -0x200) {
            p->unk_1AF = 2;
            p->unk_1A8 = 0;
        }
        break;
    case 2:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 40);
            break;
        case 0x80:
            func_08070058(p, 46);
            break;
        case 0xC0:
            func_08070058(p, 58);
            break;
        case 0x40:
            func_08070058(p, 58);
            break;
        case 0xAD:
            func_08070058(p, 52);
            break;
        case 0x53:
            func_08070058(p, 52);
            break;
        case 0xD3:
            func_08070058(p, 64);
            break;
        case 0x2D:
            func_08070058(p, 64);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_18C += 51;
        p->unk_034 += p->unk_18C;

        if ((GetKeysHeld() & 2) == 0) {
            p->unk_18C += 64;
        }

        if (p->unk_18C > 0) {
            p->unk_1AF = 3;
            p->unk_1A8 = 0;
        }
        break;
    case 3:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 40);
            break;
        case 0x80:
            func_08070058(p, 46);
            break;
        case 0xC0:
            func_08070058(p, 58);
            break;
        case 0x40:
            func_08070058(p, 58);
            break;
        case 0xAD:
            func_08070058(p, 52);
            break;
        case 0x53:
            func_08070058(p, 52);
            break;
        case 0xD3:
            func_08070058(p, 64);
            break;
        case 0x2D:
            func_08070058(p, 64);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_034 += p->unk_18C;
        p->unk_18C += 51;

        if (p->unk_18C > 0x1FF) {
            p->unk_1AF = 4;
            p->unk_1A8 = 0;
        }
        break;
    case 4:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 41);
            break;
        case 0x80:
            func_08070058(p, 47);
            break;
        case 0xC0:
            func_08070058(p, 59);
            break;
        case 0x40:
            func_08070058(p, 59);
            break;
        case 0xAD:
            func_08070058(p, 53);
            break;
        case 0x53:
            func_08070058(p, 53);
            break;
        case 0xD3:
            func_08070058(p, 65);
            break;
        case 0x2D:
            func_08070058(p, 65);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_034 += p->unk_18C;
        p->unk_18C += 51;

        if (p->unk_034 > p->unk_198) {
            p->unk_034 = p->unk_198;
            p->unk_1AF = 5;
            p->unk_1A8 = 0;
        }
        break;
    case 5:
        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 42);
            break;
        case 0x80:
            func_08070058(p, 48);
            break;
        case 0xC0:
            func_08070058(p, 60);
            break;
        case 0x40:
            func_08070058(p, 60);
            break;
        case 0xAD:
            func_08070058(p, 54);
            break;
        case 0x53:
            func_08070058(p, 54);
            break;
        case 0xD3:
            func_08070058(p, 66);
            break;
        case 0x2D:
            func_08070058(p, 66);
            break;
        }

        p->unk_19C = 204 * p->unk_19C >> 8;

        if ((GetKeysPressed() & 2) != 0) {
            p->unk_1AF = 1;
            p->unk_18C = -0x540;
        } else if (p->unk_1A8 > 10) {
            p->unk_1AC = 255;
            SetTaskUpdate(a, (void*)func_080700D4);
        } else {
            p->unk_1A8++;
        }
        break;
    }

    TaskPoolUpdate(&p->tasks);
    return 1;
}
#ifdef VERSION_EU
#define MSG_SOUND_ID_9E 0x9C
#define MSG_SOUND_ID_B1 0xAF
#else
#define MSG_SOUND_ID_9E 0x9E
#define MSG_SOUND_ID_B1 0xB1
#endif

s32 func_08070AD4(EventCharaWork* p) {
    u16 x;
    u16 y;

    x = (p->unk_02C >> 8) - (gUnk_02039DC8->x >> 8);
    y = (p->unk_030 >> 8) + (p->unk_034 >> 8) - (gUnk_02039DC8->y >> 8);

    switch (p->keyframes[p->unk_1A0].unk_00) {
    case 0x2EB:
    case 0x2F1:
    case 0x2F2:
        if (p->unk_024 != MSG_SOUND_ID_9E) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 2) {
                    m4aSongNumStart(0x3BE);
                    func_08076110(0x3BE, x, y);
                }
                if (p->anim->frame == 6) {
                    m4aSongNumStart(0x3BF);
                    func_08076110(0x3BF, x, y);
                }
            }
        }
        break;
    case 0x2E6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x375:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x398:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x175);
                func_08076110(0x175, x, y);
            }
        }
        break;
    case 0x399:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x176);
                func_08076110(0x176, x, y);
            }
        }
        break;
    case 0x5E:
        if (p->anim->timer == 9) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x12E);
            }
        }
        break;
    case 0x1C2:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x1C0:
    case 0x1C1:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x34B:
    case 0x34C:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x2B2:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x204:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20A:
    case 0x20B:
    case 0x2C7:
    case 0x2C8:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x384);
                    func_08076110(0x384, x, y);
                } else {
                    m4aSongNumStart(0x3B2);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->anim->frame == 7) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x385);
                    func_08076110(0x385, x, y);
                } else {
                    m4aSongNumStart(0x3B3);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0x2C5:
    case 0x2C6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x384);
                    func_08076110(0x384, x, y);
                } else {
                    m4aSongNumStart(0x3B2);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->anim->frame == 5) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x385);
                    func_08076110(0x385, x, y);
                } else {
                    m4aSongNumStart(0x3B3);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0x371:
    case 0x372:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 7) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x1EE:
    case 0x1F6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x345:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x344:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x341:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 9) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x30C:
    case 0x30D:
    case 0x30E:
    case 0x30F:
    case 0x310:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 9) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x275:
    case 0x276:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3AE);
                func_08076110(0x3AE, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3AF);
                func_08076110(0x3AF, x, y);
            }
        }
        break;
    case 0x277:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x3AE);
                func_08076110(0x3AE, x, y);
            }
            if (p->anim->frame == 7) {
                m4aSongNumStart(0x3AF);
                func_08076110(0x3AF, x, y);
            }
        }
        break;
    case 0x2A5:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x3AA);
                func_08076110(0x3AA, x, y);
            }
            if (p->anim->frame == 7) {
                m4aSongNumStart(0x3AB);
                func_08076110(0x3AB, x, y);
            }
        }
        break;
    case 0x2A8:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3A0);
                func_08076110(0x3A0, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3A1);
                func_08076110(0x3A1, x, y);
            }
        }
        break;
    case 0x271:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x241:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3A8);
                func_08076110(0x3A8, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3A9);
                func_08076110(0x3A9, x, y);
            }
        }
        break;
    case 0x17A:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x178:
    case 0x179:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x19C:
    case 0x19D:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x14A:
    case 0x14B:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x3B6);
                func_08076110(0x3B6, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3B7);
                func_08076110(0x3B7, x, y);
            }
        }
        break;
    case 0x157:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x3A6);
                func_08076110(0x3A6, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3A7);
                func_08076110(0x3A7, x, y);
            }
        }
        break;
    case 0x23E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3B2);
                func_08076110(0x3B2, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3B3);
                func_08076110(0x3B3, x, y);
            }
        }
        break;
    case 0x16C:
    case 0x16E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3A0);
                func_08076110(0x3A0, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3A1);
                func_08076110(0x3A1, x, y);
            }
        }
        break;
    case 0x122:
    case 0x123:
    case 0x128:
    case 0x129:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0xDF:
    case 0xE0:
    case 0xE1:
    case 0xE2:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                if (p->unk_024 == 0x61) {
                    m4aSongNumStart(0x3AE);
                    func_08076110(0x3AE, x, y);
                } else {
                    m4aSongNumStart(0x3B2);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->anim->frame == 5) {
                if (p->unk_024 == 0x61) {
                    m4aSongNumStart(0x3AF);
                    func_08076110(0x3AF, x, y);
                } else {
                    m4aSongNumStart(0x3B3);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0xD6:
    case 0xD9:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0xCA:
    case 0xCB:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3BA);
                func_08076110(0x3BA, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3BB);
                func_08076110(0x3BB, x, y);
            }
        }
        break;
    case 0xD3:
    case 0xD4:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x3BC);
                func_08076110(0x3BC, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x3BD);
                func_08076110(0x3BD, x, y);
            }
        }
        break;
    case 0x10A:
    case 0x10B:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x83:
    case 0x88:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x130);
                func_08076110(0x130, x, y);
            }
        }
        break;
    case 0x12:
    case 0x13:
    case 0x66:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x12E);
                func_08076110(0x12E, x, y);
            }
        }
        break;
    case 0x5:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x9:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 1) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 5) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0x75:
    case 0x77:
    case 0x288:
    case 0x28C:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 2) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 6) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0x78:
    case 0x79:
    case 0x289:
    case 0x28D:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 3) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 7) {
                    func_08072A64((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0x95:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x265:
    case 0x266:
    case 0x267:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 3) {
                    func_08072B4C((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 7) {
                    func_08072B4C((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
        if (gUnk_09EE3CA0[p->unk_024] != 0) {
            if (p->anim->timer == 0) {
                if (p->anim->frame == 3) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 1);
                }
                if (p->anim->frame == 7) {
                    func_08072918((Actor0806180C*)p, gUnk_09EE3CA0[p->unk_024]->unk_2C, 0);
                }
            }
        }
        break;
    case 0xB8:
    case 0xBA:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0xBB:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x140);
                func_08076110(0x140, x, y);
            }
        }
        break;
    case 0xC1:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x14E);
                func_08076110(0x14E, x, y);
            }
        }
        break;
    case 0xE9:
    case 0xEA:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x144);
                func_08076110(0x144, x, y);
            }
        }
        break;
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF8:
    case 0xF9:
    case 0xFA:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x39D);
                func_08076110(0x39D, x, y);
            }
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x39C);
                func_08076110(0x39C, x, y);
            }
        }
        break;
    case 0xF5:
    case 0xF6:
    case 0xF7:
    case 0xFB:
    case 0xFC:
    case 0xFD:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x39C);
                func_08076110(0x39C, x, y);
            }
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x39D);
                func_08076110(0x39D, x, y);
            }
        }
        break;
    case 0x280:
    case 0x281:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 7) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x18D:
    case 0x18E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x18F:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 4) {
                m4aSongNumStart(0x26B);
            }
        }
        break;
    case 0x159:
    case 0x15D:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x15E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x14E);
                func_08076110(0x14E, x, y);
            }
        }
        break;
    case 0x185:
    case 0x186:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x187:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 7) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->anim->frame == 3) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x2E7:
    case 0x2E8:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x155);
                func_08076110(0x155, x, y);
            }
        }
        break;
    case 0x2AE:
    case 0x2AF:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x1C5:
    case 0x1C6:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x27A:
    case 0x27D:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x10F:
    case 0x11B:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 6) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x110:
    case 0x11C:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 5) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->anim->frame == 2) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x118:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x156);
                func_08076110(0x156, x, y);
            }
        }
        break;
    case 0x29E:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 3) {
                m4aSongNumStart(0xC5);
                func_08076110(0xC5, x, y);
            }
        }
        break;
    case 0x2A2:
        if (p->anim->timer == 0) {
            if (p->anim->frame == 1) {
                m4aSongNumStart(0x157);
            }
        }
        break;
    case 0x1DE:
        if (p->anim->timer == 1) {
            if (p->anim->frame == 0) {
                m4aSongNumStart(0x227);
                func_08076110(0x227, x, y);
            }
        }
        break;
    }
}

void func_08072918(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->x >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->y >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x384);
            func_08076110(0x384, x, y);
        } else {
            m4aSongNumStart(0x385);
            func_08076110(0x385, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x389);
            func_08076110(0x389, x, y);
        } else {
            m4aSongNumStart(0x388);
            func_08076110(0x388, x, y);
        }
        break;
    case 2:
        if ((a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) || (a->unk_24 == 0x36 && gUnk_02039DC8->unk_6C <= 0x4F)) {
            if (flag != 0) {
                m4aSongNumStart(0x388);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(0x389);
                func_08076110(0x389, x, y);
            }

            if (flag != 0) {
                m4aSongNumStart(0x388);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(0x389);
                func_08076110(0x389, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x38C);
                func_08076110(0x38C, x, y);
            } else {
                m4aSongNumStart(0x38D);
                func_08076110(0x38D, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x388);
            func_08076110(0x388, x, y);
        } else {
            m4aSongNumStart(0x389);
            func_08076110(0x389, x, y);
        }
        break;
    }
}

void func_08072A64(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->x >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->y >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x394);
            func_08076110(0x394, x, y);
        } else {
            m4aSongNumStart(0x395);
            func_08076110(0x395, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x391);
            func_08076110(0x391, x, y);
        } else {
            m4aSongNumStart(0x390);
            func_08076110(0x390, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(0x391);
                func_08076110(0x391, x, y);
            } else {
                m4aSongNumStart(0x390);
                func_08076110(0x390, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x398);
                func_08076110(0x398, x, y);
            } else {
                m4aSongNumStart(0x399);
                func_08076110(0x399, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x390);
            func_08076110(0x390, x, y);
        } else {
            m4aSongNumStart(0x391);
            func_08076110(0x391, x, y);
        }
        break;
    }
}

void func_08072B4C(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->x >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->y >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x396);
            func_08076110(0x396, x, y);
        } else {
            m4aSongNumStart(0x397);
            func_08076110(0x397, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x393);
            func_08076110(0x393, x, y);
        } else {
            m4aSongNumStart(0x392);
            func_08076110(0x392, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(0x393);
                func_08076110(0x393, x, y);
            } else {
                m4aSongNumStart(0x392);
                func_08076110(0x392, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x39A);
                func_08076110(0x39A, x, y);
            } else {
                m4aSongNumStart(0x39B);
                func_08076110(0x39B, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x392);
            func_08076110(0x392, x, y);
        } else {
            m4aSongNumStart(0x393);
            func_08076110(0x393, x, y);
        }
        break;
    }
}

void func_08072C34(EventCharaWork* p) {
    switch (p->unk_026) {
    case 6:
    case 16:
    case 20:
    case 21:
    case 22:
    case 32:
        p->unk_03C |= 8;
        break;
    case 37:
        func_08075E60(p);
    case 8:
    case 10:
    case 33:
    case 38:
    case 39:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
        p->unk_03C |= 0x10;
        break;
    case 0:
        break;
    }
}
#ifdef VERSION_EU
#define MSG_WIN_ID_A 0x84
#define MSG_WIN_ID_B 0x9A
#else
#define MSG_WIN_ID_A 0x86
#define MSG_WIN_ID_B 0x9C
#endif

void func_08072D98(MsgWinWork* p, u8* arg) {
    EventSequenceDef* t;

    p->unk_28 = arg[0];

    switch (p->unk_28) {
    case 11:
        p->unk_1C = func_08064D04(0);
        break;
    case 3:
    case MSG_WIN_ID_A:
    case MSG_WIN_ID_B:
        p->unk_1C = func_08064C34(0);
        break;
    default:
        p->unk_1C = func_08064B80(0);
        break;
    }

    if (gUnk_09EE3CA0[p->unk_28] != NULL) {
        p->unk_38 = 0;
    } else {
        p->unk_38 = 2;
    }
    LoadBgTiles(p->unk_38, gUnk_094233B8, 0x500);
    LoadBgPalette(p->unk_38, gUnk_096148D8, 32);
    LoadBgMap(p->unk_38, gUnk_08125E24, 0x800);
    SetBgPriority(p->unk_38, 0);
    t = gUnk_09EE3FB4[p->unk_28];
    p->palette = NULL;
    p->unk_1E = 0;
    p->unk_24 = 0;
    p->unk_25 = 0;
    p->unk_26 = 0;
    p->unk_27 = 0;
    p->unk_29 = 0;
    p->unk_2A = 0;
    p->script = t->script;
    p->unk_2B = 0;
    p->unk_18 = 0;
    p->unk_40 = 0;
    gUnk_02039DC8->unk_81 = 0;
    gUnk_02039DC8->unk_7D = 0;
    gUnk_02039DC8->unk_8B = 0;
    TaskPoolInit(p, 2);
    func_08073E0C(p, &p->face, p->script->unk_00, p->script->unk_04, p->script->unk_08);
}

u8 func_08072EAC(MsgWinWork* p, void* a) {
    MessageScriptEntry* e;

    if (p->unk_29 == 0) {
        if (gUnk_02039DC8->unk_80 == 0) {
            func_08073508(p);
        }
    } else {
        func_080736F8(p);
    }

    if (p->unk_2A != 0) {
        gUnk_02039DC8->unk_87 = p->unk_20;

        if (gUnk_02039DC8->unk_7C != 0) {
            if (gUnk_02039DC8->unk_89 != 0) {
                gUnk_02039DC8->unk_89--;
            } else {
                e = &p->script[p->unk_27];

                if (e->unk_00 == 62) {
                    void* pal;

                    pal = (void*)0x050001E0;
                    LoadBgTiles(p->unk_38, gUnk_0950E2F8, 0x140);
                    LoadBgMap(p->unk_38, gUnk_096112B8, 0x800);
                    LoadPalette(gUnk_09611AB8, pal, 32);

                    if ((e->unk_14 & 0x80) != 0) {
                        FadeSetPaletteExcluded(15, 1);
                    }
                    gUnk_02039DC8->unk_81 = 1;

                    switch (e->unk_08) {
                    case 0:
                    case 2:
                        SetBgScroll(p->unk_38, (u16)-0x28, 0);
                        break;
                    case 1:
                    case 3:
                        SetBgScroll(p->unk_38, (u16)-0x28, (u16)-0x60);
                        break;
                    }

                    if (p->palette == NULL) {
                        p->palette = LoadObjPalette(gUnk_09614718, 32);

                        if ((e->unk_14 & 0x80) != 0) {
                            FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
                        }
                    }
                    _08073E6C(&p->face);
                    SetTaskUpdate(a, (void*)func_08073294);
                    gUnk_02039DC8->unk_8B = 1;
                } else {
                    LoadBgTiles(p->unk_38, gUnk_094233B8, 0x500);
                    LoadBgPalette(p->unk_38, gUnk_096148D8, 32);
                    SetBgMapBlocks(p->unk_38, gUnk_09EE4724[p->unk_20], 2, 1);
                    RedrawBgMapAt(p->unk_38, p->unk_18, 0);
                    SetTaskUpdate(a, (void*)func_08073294);
                    _08073E6C(&p->face);
                    gUnk_02039DC8->unk_81 = 1;

                    if (p->palette != NULL) {
                        ReleaseObjPalette(p->palette);
                        p->palette = NULL;
                    }
                    gUnk_02039DC8->unk_8B = 0;
                }
            }
        } else {
        e = &p->script[p->unk_27];

        if (e->unk_00 == 62) {
            void* pal;

            pal = (void*)0x050001E0;
            LoadBgTiles(p->unk_38, gUnk_0950E2F8, 0x140);
            LoadBgMap(p->unk_38, gUnk_096112B8, 0x800);
            LoadPalette(gUnk_09611AB8, pal, 32);

            if ((e->unk_14 & 0x80) != 0) {
                FadeSetPaletteExcluded(15, 1);
            }
            gUnk_02039DC8->unk_81 = 1;

            switch (e->unk_08) {
            case 0:
            case 2:
                SetBgScroll(p->unk_38, (u16)-0x18, 0);
                break;
            case 1:
            case 3:
                SetBgScroll(p->unk_38, (u16)-0x18, (u16)-0x60);
                break;
            }

            if (p->palette == NULL) {
                p->palette = LoadObjPalette(gUnk_09614718, 32);

                if ((e->unk_14 & 0x80) != 0) {
                FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
                }
            }
            _08073E6C(&p->face);
            SetTaskUpdate(a, (void*)func_08073294);
            gUnk_02039DC8->unk_8B = 1;
        } else {
            LoadBgTiles(p->unk_38, gUnk_094233B8, 0x500);
            LoadBgPalette(p->unk_38, gUnk_096148D8, 32);
            SetBgMapBlocks(p->unk_38, gUnk_09EE4724[p->unk_20], 2, 1);
            RedrawBgMapAt(p->unk_38, p->unk_18, 0);
            SetTaskUpdate(a, (void*)func_08073294);
            _08073E6C(&p->face);
            gUnk_02039DC8->unk_81 = 1;

            if (p->palette != NULL) {
                ReleaseObjPalette(p->palette);
                p->palette = NULL;
            }
            gUnk_02039DC8->unk_8B = 0;
        }
        }
    }

    if (gUnk_02039DC8->unk_82 == 1) {
        FadeSetPaletteExcluded(p->unk_1C + 16, 0);
        FadeSetPaletteExcluded(14, 0);
    } else {
        FadeSetPaletteExcluded(p->unk_1C + 16, 1);
        FadeSetPaletteExcluded(14, 1);
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_08073170(MsgWinWork* p, void* a) {
    if (p->unk_29 == 0) {
        if (gUnk_02039DC8->unk_80 == 0) {
            func_08073508(p);
        }
    } else {
        func_080736F8(p);
    }

    if (p->unk_2A != 0) {
        gUnk_02039DC8->unk_87 = p->unk_20;

        if (gUnk_02039DC8->unk_7C != 0) {
            if (gUnk_02039DC8->unk_89 != 0) {
                gUnk_02039DC8->unk_89--;
            } else {
                SetTaskUpdate(a, (void*)func_08073294);
                _08073E6C(&p->face);
                gUnk_02039DC8->unk_81 = 1;
            }
        } else {
            SetTaskUpdate(a, (void*)func_08073294);
            _08073E6C(&p->face);
            gUnk_02039DC8->unk_81 = 1;
        }
    }

    if (gUnk_02039DC8->unk_82 == 1) {
        FadeSetPaletteExcluded(p->unk_1C + 16, 0);
        FadeSetPaletteExcluded(14, 0);
    } else {
        FadeSetPaletteExcluded(p->unk_1C + 16, 1);
        FadeSetPaletteExcluded(14, 1);
    }
    TaskPoolUpdate(p);
    return 1;
}
void func_08073238(MsgWinWork* p) {
    MessageScriptEntry* e = &p->script[p->unk_27];

    if (e->unk_00 != 62) {
        func_080658B8(p->unk_24);
    } else {
        _0806C3A0(p->unk_24, p->palette);
    }
    TaskPoolDraw(p);
}
void func_08073274(MsgWinWork* p) {
    if (p->palette != NULL) {
        ReleaseObjPalette(p->palette);
    }
    func_08065940();
    TaskPoolDestroy(p);
}
u8 func_08073294(MsgWinWork* p, void* a) {
    MessageScriptEntry* e = &p->script[p->unk_27];

    ApproachValue(&p->unk_18, gUnk_09033CA0[p->unk_20], p->unk_1E);

    if (e->unk_00 != 62) {
        ScrollBgMapTo(p->unk_38, p->unk_18, 0);
    }

    if (p->unk_1E != 0) {
        p->unk_1E--;
    } else {
        p->unk_1E = 0;

        if ((e->unk_14 & 0xF) == 0) {
            gUnk_02039DC8->unk_7B = 1;
        }
        SetTaskUpdate(a, (void*)func_08073318);
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_08073318(MsgWinWork* p, void* a) {
    MessageScriptEntry* e = &p->script[p->unk_27];

    func_0807361C(p);

    if (e->unk_00 == 62) {
        p->unk_24 = p->unk_26;
    } else if (GetKeysPressed() & 1) {
        if (p->unk_24 < p->unk_26) {
            p->unk_24 = p->unk_26;
        }
    }

    if (p->unk_2B == 1 && gUnk_02039DC8->unk_7D == 0) {
        s32 text = p->unk_40;
        if (text != 0) {
            p->unk_1E = 0;
            p->unk_29 = 0;
            p->unk_2A = 1;
            p->face.unk_08 = 1;
            SetTaskUpdate(a, (void*)func_08073170);
        } else {
            _08065994();

            if ((e->unk_14 & 0x8000) == 0) {
                if (p->script[p->unk_27 + 1].unk_08 != 4) {
                    p->unk_1E = 8;
                    func_08073E74(&p->face);
                    SetTaskUpdate(a, (void*)func_0807344C);
                    gUnk_02039DC8->unk_81 = text;
                    p->face.unk_08 = text;
                } else {
                    p->unk_1E = text;
                    p->unk_29 = text;
                    p->unk_2A = text;
                    p->unk_27++;
                    gUnk_02039DC8->unk_64 &= ~1;
                    p->face.unk_08 = 1;
                    SetTaskUpdate(a, (void*)func_08072EAC);
                }
            } else {
                p->unk_1E = 8;
                func_08073E74(&p->face);
                SetTaskUpdate(a, (void*)func_0807344C);
                gUnk_02039DC8->unk_81 = text;
                p->face.unk_08 = text;
            }
        }
        p->unk_2B = 0;
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_0807344C(MsgWinWork* p, void* a) {
    MessageScriptEntry* e = &p->script[p->unk_27];

    ApproachValue(&p->unk_18, gUnk_09033C98[p->unk_20], p->unk_1E);

    if (e->unk_00 != 62) {
        ScrollBgMapTo(p->unk_38, p->unk_18, 0);
    } else {
        DisableBg(p->unk_38);
    }

    if (p->unk_1E != 0) {
        p->unk_1E--;
    } else {
        p->unk_1E = 0;

        if ((gUnk_02039DC8->unk_64 & 4) == 0) {
            gUnk_02039DC8->unk_64 &= ~1;
        }
        gUnk_02039DC8->unk_7C = 0;

        if ((e->unk_14 & 0x8000) == 0) {
            p->unk_2A = 0;
            p->unk_29 = 0;
            p->unk_27++;
            SetTaskUpdate(a, (void*)func_08072EAC);
        }
    }
    TaskPoolUpdate(p);
    return 1;
}
void func_08073508(MsgWinWork* p) {
    MessageScriptEntry* e = &p->script[p->unk_27];
    s32 n;

    n = e->unk_08;

    if (n != 4) {
        p->unk_20 = n;
        p->unk_18 = gUnk_09033C98[n];
    }

    if ((e->unk_14 & 0x20) != 0) {
        p->face.unk_03 = 1;
    } else {
        p->face.unk_03 = 0;
    }
    func_08073E34(&p->face, e->unk_00, e->unk_04, p->unk_20);

#ifdef VERSION_JP
    if (e->unk_00 == 62) {
        p->unk_26 = func_080653D4(0x2E00, gUnk_09033CB8[p->unk_20], (u8*)e->unk_10);
    } else {
        p->unk_26 = func_080653D4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20], (u8*)e->unk_10);
    }
#else
    if (e->unk_00 == 62) {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, LANGSTR(e->unk_10), &p->unk_40);
        }
    } else {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, LANGSTR(e->unk_10), &p->unk_40);
        }
    }
#endif
    p->unk_25 = 0;
    p->unk_24 = 0;
    p->unk_29 = 1;
}

void func_0807361C(MsgWinWork* p) {
    MessageScriptEntry* e = &p->script[p->unk_27];
    u8 v;

    if (p->unk_25 >= e->unk_0C) {
        if (p->unk_24 < p->unk_26) {
            p->unk_24++;
            m4aSongNumStart(0x74);
        } else {
            gUnk_02039DC8->unk_7B = 0;

            if (p->unk_2B == 0) {
                if ((p->script[p->unk_27].unk_14 & 0x8000) == 0) {
                    if ((p->script[p->unk_27].unk_14 & 0x40) == 0) {
                        TaskCreate(p, &gTaskDescMsgface[1], &p->script[p->unk_27 + 1].unk_08);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], &p->script[p->unk_27 + 1].unk_08);
                    }
                } else {
                    v = 0;

                    if ((p->script[p->unk_27].unk_14 & 0x40) == 0) {
                        TaskCreate(p, &gTaskDescMsgface[1], &v);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], &v);
                    }
                }
                p->unk_2B = 1;
            }
        }
        p->unk_25 = 0;
    } else {
        p->unk_25++;
    }
}
void func_080736F8(MsgWinWork* p) {
    MessageScriptEntry* e = &p->script[p->unk_27];

    if (gUnk_02039DC8->unk_6C >= e->unk_16) {
        if (p->unk_2A == 0) {
            gUnk_02039DC8->unk_64 |= 1;
            p->unk_2A = 1;
            p->unk_1E = 8;

            if ((e->unk_14 & 0x10) != 0) {
                gUnk_02039DC8->unk_7C = 1;
                gUnk_02039DC8->unk_88 = e->unk_00;
                gUnk_02039DC8->unk_89 = 32;
            } else {
                gUnk_02039DC8->unk_7C = 0;
            }
        }
    }
}
void msgface_0(MsgFaceWork* p, MsgFaceControl* ctl) {
    const MsgFaceAnim* anim;
    u32 n;

    p->tiles = AllocObjTiles(0x12C0, 0);
    p->palette = AllocObjPalette(32);
    p->face = ctl;
    p->unk_30 = 0;
    p->x = gUnk_09033CD0[n = p->face->positionIndex];
    p->y = gUnk_09033CF0[n];
    p->unk_2C = 0x100;
    p->unk_31 = 0;
    p->unk_32 = 0;
    p->unk_34 = 1;

    if (p->face->portraitId != 62) {
        anim = gUnk_09EE45DC[p->face->portraitId];
    } else {
        anim = gUnk_09EE45DC[0];
    }

    if (p->face->positionIndex <= 1) {
        p->unk_33 = 1;
    } else if (p->face->positionIndex <= 3) {
        p->unk_33 = 0;
    }

    if (p->face->portraitId != 62) {
        SetObjTileSource(p->tiles, anim[p->face->expressionId].tiles);
        UpdateAllocatedObjPalette(p->palette, anim[p->face->expressionId].palette);
        AnimInit(p->anim, anim[p->face->expressionId].anims, anim[p->face->expressionId].gfxTable);
        AnimStart(p->anim, 0, anim[p->face->expressionId].unk_11);
        p->gfx = AnimGetGfx(p->anim);
    } else {
        SetObjTileSource(p->tiles, anim->tiles);
        UpdateAllocatedObjPalette(p->palette, anim->palette);
        AnimInit(p->anim, anim->anims, anim->gfxTable);
        AnimStart(p->anim, 0, anim->unk_11);
        p->gfx = AnimGetGfx(p->anim);
    }
}
u8 msgface_1(MsgFaceWork* p, void* a) {
    const MsgFaceAnim* anim = NULL;
    u32 n;

    if (p->face->portraitId != 62) {
        anim = gUnk_09EE45DC[p->face->portraitId];
        p->unk_34 = 1;
    } else {
        p->unk_34 = 0;
    }

    switch (p->face->command) {
    case 1:
        if (p->face->unk_08 == 0) {
            p->x = gUnk_09033CD0[n = p->face->positionIndex];
            p->y = gUnk_09033CF0[n];
        }
        p->unk_30 = 8;

        if (anim != NULL) {
            if (p->face->unk_03 == 1) {
                UpdateAllocatedObjPalette(p->palette, &gUnk_096148D8[0x100]);
            } else {
                UpdateAllocatedObjPalette(p->palette, anim[p->face->expressionId].palette);
            }
        }

        SetTaskUpdate(a, (void*)func_08073B04);
        break;
    case 2:
        p->unk_30 = 8;
        p->unk_31 = 0;
        SetTaskUpdate(a, (void*)func_08073B54);
        break;
    case 4:
        p->unk_30 = 4;

        if (p->face->positionIndex <= 1) {
            p->unk_2C = -255;
        } else if (p->face->positionIndex <= 3) {
            p->unk_2C = 256;
        }

        p->y = gUnk_09033CF0[p->face->positionIndex];
        SetTaskUpdate(a, (void*)func_08073CA4);
        break;
    case 3:
        SetTaskUpdate(a, (void*)func_08073B9C);
        break;
    }

    if (gUnk_02039DC8->unk_7B == 1) {
        if (p->unk_32 == 0) {
            if (anim != NULL && anim[p->face->expressionId].unk_10 > 1) {
                AnimStart(p->anim, 1, anim[p->face->expressionId].unk_11);
            }

            p->unk_32 = 1;
        }
    } else {
        if (p->unk_32 == 1) {
            if (anim != NULL) {
                AnimStart(p->anim, 0, anim[p->face->expressionId].unk_11);
            }

            p->unk_32 = 0;
        }
    }

    if (gUnk_02039DC8->unk_82 == 1) {
        FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 0);
    } else {
        FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
    }

    p->gfx = AnimUpdate(p->anim);
    return 1;
}
void msgface_2(MsgFaceWork* p) {
    s32 t;
    u8 v;

    if (p->unk_34 != 0) {
        t = AllocObjAffine(0, p->unk_2C, 256, 0);
        if (t != 0) {
            DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, t, 0, 50);
        } else {
            v = p->unk_33;
            if (v != 0) {
                DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, t, 1, 50);
            } else {
                DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, v, v, 50);
            }
        }
    }
}
void msgface_3(MsgFaceWork* p) {
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
u8 func_08073B04(MsgFaceWork* p, void* a) {
    ApproachValue(&p->x, gUnk_09033CE0[p->face->positionIndex], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->face->command = 0;
        p->unk_31 = 1;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
u8 func_08073B54(MsgFaceWork* p, void* a) {
    ApproachValue(&p->x, gUnk_09033CD0[p->face->positionIndex], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->face->command = 0;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
u8 func_08073B9C(MsgFaceWork* p, void* a) {
    const MsgFaceAnim* t;
    s32 n;

    t = NULL;

    if (p->face->portraitId != 62) {
        t = gUnk_09EE45DC[p->face->portraitId];
        p->unk_34 = 1;
    } else {
        p->unk_34 = 0;
    }

    if (p->face->positionIndex <= 1) {
        p->unk_33 = 1;
    } else if (p->face->positionIndex <= 3) {
        p->unk_33 = 0;
    }

    if (t != NULL) {
        SetObjTileSource(p->tiles, t[p->face->expressionId].tiles);
        UpdateAllocatedObjPalette(p->palette, t[p->face->expressionId].palette);
        AnimInit(p->anim, t[p->face->expressionId].anims, t[p->face->expressionId].gfxTable);
        AnimStart(p->anim, 0, t[p->face->expressionId].unk_11);
        p->gfx = AnimGetGfx(p->anim);
        p->unk_31 = 0;
        p->unk_30 = 8;
        p->face->command = 0;
    }
    p->x = gUnk_09033CD0[n = p->face->positionIndex];
    p->y = gUnk_09033CF0[n];
    p->unk_2C = 256;
    p->unk_30 = 8;
    SetTaskUpdate(a, (void*)msgface_1);
    return 1;
}

u8 func_08073CA4(MsgFaceWork* p, void* a) {
    const MsgFaceAnim* t;

    if (p->unk_2C < 0) {
        ApproachValue(&p->unk_2C, -2, p->unk_30);
    } else {
        ApproachValue(&p->unk_2C, 2, p->unk_30);
    }
    p->unk_30--;

    if (p->unk_30 == 0) {
        t = NULL;

        if (p->face->portraitId != 62) {
            t = gUnk_09EE45DC[p->face->portraitId];
        }

        if (p->face->positionIndex <= 1) {
            p->unk_33 = 1;
        } else if (p->face->positionIndex <= 3) {
            p->unk_33 = 0;
        }

        if (t != NULL) {
            SetObjTileSource(p->tiles, t[p->face->expressionId].tiles);
            UpdateAllocatedObjPalette(p->palette, t[p->face->expressionId].palette);
            AnimInit(p->anim, t[p->face->expressionId].anims, t[p->face->expressionId].gfxTable);
            AnimStart(p->anim, 0, t[p->face->expressionId].unk_11);
            p->gfx = AnimGetGfx(p->anim);
            p->unk_31 = 0;
            p->unk_30 = 8;
        }
        SetTaskUpdate(a, (void*)func_08073DA4);
    }
    return 1;
}

u8 func_08073DA4(MsgFaceWork* p, void* a) {
    if (p->unk_2C < 0) {
        ApproachValue(&p->unk_2C, -255, p->unk_30);
    } else {
        ApproachValue(&p->unk_2C, 256, p->unk_30);
    }
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->unk_31 = 1;
        p->face->command = 0;
        p->unk_2C = 256;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
void func_08073E0C(void* pool, MsgFaceControl* p, u8 a, u8 b, u8 c) {
    p->portraitId = a;
    p->expressionId = b;
    p->positionIndex = c;
    p->command = 0;
    p->unk_03 = 0;
    TaskCreate(pool, &gTaskDescMsgface[0], p);
}

void func_08073E34(MsgFaceControl* p, u8 a, u8 b, u8 c) {
    u8 v;

    if (p->portraitId != a) {
        v = 3;
    } else {
        if (p->expressionId == b && p->positionIndex == c) {
            return;
        }
        v = 4;
    }
    p->command = v;
    p->portraitId = a;
    p->expressionId = b;
    p->positionIndex = c;
}

void _08073E6C(MsgFaceControl* p) {
    p->command = 1;
}
void func_08073E74(MsgFaceControl* p) {
    p->command = 2;
}
void msgwait_0(MsgWaitWork* p, u8* arg) {
    p->unk_103 = arg[0];
    p->tiles = AllocObjTiles(64, 0);
    p->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(p->palette->index, gUnk_08F69BA4);
    FadeSetPaletteExcluded(p->palette->index + 16, 1);
    SetObjTileSource(p->tiles, gUnk_09320796);
    AnimInit(p->unk_DC, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(p->unk_DC, 2, 1);
    p->unk_102 = 0;
    gUnk_02039DC8->unk_7D = 1;
}
u8 msgwait_1(MsgWaitWork* p, void* a) {
    p->gfx = AnimUpdate(p->unk_DC);

    if (GetKeysPressed() & 1) {
        AnimStart(p->unk_DC, 3, 1);

        if (p->unk_103 == 4) {
            gUnk_02039DC8->unk_7D = 0;
            m4aSongNumStart(0x66);
            return 0;
        } else {
            SetTaskUpdate(a, (void*)func_08073F78);
            m4aSongNumStart(0x66);
        }
    }
    return 1;
}
u8 func_08073F78(MsgWaitWork* p) {
    u8 r;

    p->gfx = AnimUpdate(p->unk_DC);
    p->unk_102++;
    if (p->unk_102 <= 15) {
        r = 1;
    } else {
        gUnk_02039DC8->unk_7D = 0;
        r = 0;
    }
    return r;
}
void msgwait_2(MsgWaitWork* p) {
    u8 v = gUnk_02039DC8->unk_8B;

    if (v != 0) {
        DrawSprite(120, gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx,
                   p->tiles, p->palette, 0, 0, 0);
    } else {
        DrawSprite(gUnk_09033D08[gUnk_02039DC8->unk_87][0] >> 8,
                   gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->tiles,
                   p->palette, 0, 0, 0);
    }
}
void msgwait_3(MsgWaitWork* p) {
    FadeSetPaletteExcluded(p->palette->index + 16, 0);
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
void msgwait_yesno_0(MsgWaitYesNoWork* p, u8* a) {
    p->unk_103 = *a;
    p->tiles = AllocObjTiles(64, 0);
    p->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(((ObjPalette*)p->palette)->index, gUnk_08F69BA4);
    FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
    SetObjTileSource(p->tiles, gUnk_09320796);
    AnimInit((AnimState*)p->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart((AnimState*)p->anim, 2, 1);
    p->unk_102 = 0;
    p->tiles2 = AllocObjTiles(288, 0);
    p->palette2 = LoadObjPalette(gUnk_09614418, 32);
    LoadObjPaletteBank(((ObjPalette*)p->palette2)->index, gUnk_09614418);
    SetObjTileSource(p->tiles2, gUnk_090A4664);
    AnimInit((AnimState*)p->anim2, gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)p->anim2, 2, 1);
    p->gfx2 = AnimGetGfx((AnimState*)p->anim2);
    p->tiles3 = LoadObjTiles(gUnk_093F7C9C, 4032);
    p->palette3 = LoadObjPalette(gUnk_09611AB8, 32);
    LoadObjPaletteBank(((ObjPalette*)p->palette3)->index, gUnk_09611AB8);
    FadeSetPaletteExcluded(((ObjPalette*)p->palette)->index + 16, 1);
    InitTextSlots(p->unk_1C, 10);
    InitTextSlots(p->unk_6C, 10);
    p->palette4 = _08066468(1);
#ifdef VERSION_EU
    p->unk_F4 = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), p->unk_1C);
    p->unk_F5 = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), p->unk_6C);
#else
    p->unk_F4 = LoadTextSlots(gUnk_08159E10, p->unk_1C);
    p->unk_F5 = LoadTextSlots(gUnk_08159E18, p->unk_6C);
#endif
    p->x = 0x5800;
    p->unk_100 = 1;
    p->y = gUnk_09033D28[1];
    p->unk_102 = 0;
    gUnk_02039DC8->unk_7D = 1;
    gUnk_02039DC8->unk_85 = 1;
    gUnk_02039DC8->unk_84 = 0;
    p->unk_104 = 0;
}
u8 func_0807420C(MsgWaitYesNoWork* p, void* a) {
    switch (GetKeysPressed()) {
    case 64:
        if (p->unk_100 != 0) {
            p->unk_100--;
            m4aSongNumStart(101);
        }
        p->unk_102 = 1;
        break;
    case 128:
        if (p->unk_100 == 0) {
            p->unk_100++;
            m4aSongNumStart(101);
        }
        p->unk_102 = 1;
        break;
    case 1:
    case 8:
        if (p->unk_100 == 0) {
            gUnk_02039DC8->unk_84 = 1;
        } else {
            gUnk_02039DC8->unk_84 = 0;

            if (gUnk_02039DC8->unk_74 == 68) {
                gUnk_02039DC8->unk_83 = 1;
                gUnk_02039DC8->unk_8A = 255;
            }
        }
        m4aSongNumStart(102);
        gUnk_02039DC8->unk_7D = 0;
        return 0;
    case 2:
        gUnk_02039DC8->unk_84 = 0;

        if (gUnk_02039DC8->unk_74 == 68) {
            gUnk_02039DC8->unk_83 = 1;
            gUnk_02039DC8->unk_8A = 255;
        }
        m4aSongNumStart(102);
        gUnk_02039DC8->unk_7D = 0;
        return 0;
    }

    if (p->unk_102 != 0) {
        ApproachValue(&p->y, gUnk_09033D28[p->unk_100], p->unk_102);
        p->unk_102--;
    }
    p->gfx = AnimUpdate(p->anim);
    return 1;
}
u8 msgwait_yesno_1(MsgWaitYesNoWork* p, void* a) {
    p->gfx = AnimUpdate(p->anim);

    if (GetKeysPressed() & 1) {
        AnimStart(p->anim, 3, 1);
        p->unk_104 = 1;
        m4aSongNumStart(0x67);
        SetTaskUpdate(a, (void*)func_0807420C);
    }
    return 1;
}
void msgwait_yesno_2(MsgWaitYesNoWork* p) {
    switch (p->unk_104) {
    case 0:
        if (gUnk_02039DC8->unk_8B != 0) {
            DrawSprite(120, gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->tiles, p->palette, 0, 0, 0);
        } else {
            DrawSprite(gUnk_09033D08[gUnk_02039DC8->unk_87][0] >> 8, gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->tiles, p->palette, 0, 0, 0);
        }
        break;
    case 1:
        DrawSprite(120, 80, gUnk_09EF126C[1], p->tiles3, p->palette3, 0, 0, 10);
        DrawSprite(p->x >> 8, p->y >> 8, p->gfx2, p->tiles2, p->palette2, 0, 1, 9);
        DrawTextSlots((240 - GetTextSlotsWidth(p->unk_1C, p->unk_F4)) >> 1, 67, p->unk_1C, p->palette4, 0, p->unk_F4);
        DrawTextSlots((240 - GetTextSlotsWidth(p->unk_6C, p->unk_F5)) >> 1, 82, p->unk_6C, p->palette4, 0, p->unk_F5);
        break;
    }
}
void msgwait_yesno_3(MsgWaitYesNoWork* p) {
    ReleaseObjTiles(p->tiles2);
    ReleaseObjTiles(p->tiles3);
    ReleaseObjPalette(p->palette3);
    ReleaseObjPalette(p->palette2);
    ReleaseObjPalette(p->palette4);
    FreeTextSlots(p->unk_1C, 10);
    FreeTextSlots(p->unk_6C, 10);
}
void func_08074504(void) {
    vu16 v;

    v = *(vu16*)0x04000006;
    v = (v + 1) % 228;

    if (v < 160) {
        if (gUnk_02039DCC->enabled == 1) {
            *(vu16*)0x04000018 = gUnk_02039DCC->scrollX[v];
            *(vu16*)0x0400001C = gUnk_02039DCC->scrollX[v];
        }
    }
}
void func_08074564(void) {
    gIntrCheck |= 2;
    func_08074504();
}
void view_0(EventCameraWork* p, u8* arg) {
    EventSequenceDef* t;
    EventBackgroundDef* u;
    EventCameraKeyframe* q;
    u8 n;

    gUnk_02039DCC = (EventScanlineScroll*)p->unk_18;
    p->wavePhase = 0;
    p->waveEnabled = 0;
    p->unk_08 = arg[0];
    p->unk_09 = 0;
    p->unk_10 = 0;
    p->unk_12 = 0;
    p->unk_14 = 0;
    p->unk_15 = 0;
    t = gUnk_09EE3FB4[p->unk_08];
    u = gUnk_09EE3CA0[p->unk_08];
    q = t->keyframes;
    p->keyframes = q;

    if (q->unk_10 != 255) {
        n = func_08074E40(p);
        q = (EventCameraKeyframe*)gUnk_02039DC8->unk_00[n];
        p->unk_00 = q->unk_04;
        p->unk_04 = q->unk_08;
    } else {
        p->unk_00 = q->unk_04;
        p->unk_04 = q->unk_08;
    }
    gUnk_02039DC8->unk_48 = p->unk_00 - 0x7800;
    gUnk_02039DC8->unk_4C = p->unk_04 - 0x5000;
    gUnk_02039DC8->unk_50 = p->unk_00;
    gUnk_02039DC8->unk_54 = p->unk_04;
    gUnk_02039DC8->unk_68 = 0;
    gUnk_02039DC8->unk_6A = 0;

    if (u != NULL) {
        if (u->unk_24 != 0) {
            SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
        } else {
            if (p->unk_08 == 77) {
                ScrollBgMapTo(3, (gUnk_02039DC8->unk_48 >> 8) + 8 + gUnk_02039DC8->unk_68, (gUnk_02039DC8->unk_4C >> 8) + 40);
            } else {
                ScrollBgMapTo(3, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_78 != 0) {
                ScrollBgMapTo(2, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_79 != 0) {
                ScrollBgMapTo(1, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }
        }
    }
}

void func_080746D8(void) {
    u8 i;

    for (i = 0; i < 16; i++) {
        FadeSetPaletteExcluded(i + 16, 0);
    }
}

#ifdef VERSION_EU
#define MSG_VIEW_ID_B4 0xB2
#else
#define MSG_VIEW_ID_B4 0xB4
#endif

u8 view_1(EventCameraWork* p, u8* task) {
    EventBackgroundDef* u = gUnk_09EE3CA0[p->unk_08];
    EventCameraKeyframe* e;
    Ent08074EC8* q;
    u8 n;

    if (gUnk_02039DC8->unk_60 == 98) {
        return 1;
    }

    if (gUnk_02039DC8->unk_60 == 101) {
        return 1;
    }

    if (gUnk_02039DC8->unk_7C == 0) {
        e = &p->keyframes[p->unk_09];

        if (gUnk_02039DC8->unk_6C >= *(u16*)&e->unk_00 && !(e->unk_14 & 0x8000)) {
            p->unk_09++;
            e = &p->keyframes[p->unk_09];
            p->unk_15 = 0;

            if (e->unk_1C != NULL) {
                ((void (*)(EventCameraWork*))e->unk_1C)(p);
            }

            switch (e->unk_14 & 15) {
            case 0:
                p->unk_14 = 0;
                break;
            case 1:
                p->unk_14 = 1;
                p->unk_10 = e->unk_18;
                break;
            }
        }

        if ((e->unk_14 & 15) != 2) {
            if (e->unk_10 == 255) {
                p->unk_00 = e->unk_04;
                p->unk_04 = e->unk_08;
            } else {
                n = func_08074E40(p);
                q = gUnk_02039DC8->unk_00[n];
                p->unk_00 = q->unk_04;
                p->unk_04 = q->unk_08 + q->unk_0C + e->unk_0C;
            }
        }

        if (e->unk_14 & 0x10) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartIn(2, e->unk_18);

                if (!(e->unk_14 & 0x10000)) {
                    m4aSongNumStart(0x14F);
                }

                gUnk_02039DC8->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x20) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartOut(1, e->unk_18);
                gUnk_02039DC8->unk_7F = 1;
                p->unk_15 = 1;

                if (e->unk_14 & 0x8000) {
                    m4aSongNumStart(0x159);
                }
            }
        }

        if (e->unk_14 & 0x40) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartOut(0, e->unk_18);
                gUnk_02039DC8->unk_7F = 1;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x80) {
            if (p->unk_15 == 0) {
                FadeStartIn(1, e->unk_18);
                gUnk_02039DC8->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x100) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeStartIn(0, e->unk_18);
                gUnk_02039DC8->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x200) {
            if (p->unk_15 == 0) {
                func_080746D8();
                FadeFromAmount(2, 16, e->unk_18);

                if (!(e->unk_14 & 0x10000)) {
                    m4aSongNumStart(332);
                }

                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x20000) {
            StartBgWave(func_08074564);
            p->waveEnabled = 1;
        }

        if (e->unk_14 & 0x40000) {
            p->waveEnabled = 0;
            ResetHBlankCallback();
            DisableHBlankIntr();
        }

        if (e->unk_14 & 0x4000) {
            if (p->unk_15 == 0) {
                FadeStartIn(7, e->unk_18);
            }

            p->unk_15 = 1;
        }

        if (e->unk_14 & 0x2000) {
            gUnk_02039DC8->unk_68 = GetRandom() % 4;
            gUnk_02039DC8->unk_6A = GetRandom() % 4;
        } else if (e->unk_14 & 0x400) {
            gUnk_02039DC8->unk_68 = GetRandom() % 8;
            gUnk_02039DC8->unk_6A = GetRandom() % 8;
        } else if (e->unk_14 & 0x800) {
            gUnk_02039DC8->unk_68 = GetRandom() % 16;
            gUnk_02039DC8->unk_6A = GetRandom() % 16;
        } else if (e->unk_14 & 0x1000) {
            gUnk_02039DC8->unk_68 = 0;
            gUnk_02039DC8->unk_6A = gSineTable[(p->unk_12 >> 3) & 0xFF] >> 5;
            p->unk_12 += 4;
        } else {
            gUnk_02039DC8->unk_68 = 0;
            gUnk_02039DC8->unk_6A = 0;
        }

        if (p->unk_14 != 0) {
            func_08074DC4(p);
        } else {
            func_08074D14(p);
        }

        if (u != NULL) {
            if (u->unk_24 != 0) {
                SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
            } else {
                if (p->unk_08 == 77) {
                    ScrollBgMapTo(3, (gUnk_02039DC8->x >> 8) + 8, (gUnk_02039DC8->y >> 8) + 40);
                } else {
                    ScrollBgMapTo(3, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                }

                if (gUnk_02039DC8->unk_78 != 0) {
                    ScrollBgMapTo(2, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                }

                if (gUnk_02039DC8->unk_79 != 0) {
                    ScrollBgMapTo(1, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                }
            }
        } else {
            switch (p->unk_08) {
            case 77:
            case 78:
                gBtlWork->unk_000 = gUnk_02039DC8->x;
                gBtlWork->unk_004 = gUnk_02039DC8->y;
                gBtlWork->x = gUnk_02039DC8->x;
                gBtlWork->y = gUnk_02039DC8->y;
                gBtlWork->x2 = gUnk_02039DC8->x;
                gBtlWork->y2 = gUnk_02039DC8->y;
                ScrollBgMapTo(0, (gUnk_02039DC8->x >> 8) + 8, (gUnk_02039DC8->y >> 8) + 40);
                ScrollBgMapTo(1, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                break;
            case 105:
                gBtlWork->unk_000 = gUnk_02039DC8->x;
                gBtlWork->unk_004 = gUnk_02039DC8->y;
                gBtlWork->x = gUnk_02039DC8->x;
                gBtlWork->y = gUnk_02039DC8->y;
                gBtlWork->x2 = gUnk_02039DC8->x;
                gBtlWork->y2 = gUnk_02039DC8->y;
                ScrollBgMapTo(0, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                break;
            case MSG_VIEW_ID_B4:
                break;
            default:
                gBtlWork->unk_000 = gUnk_02039DC8->x;
                gBtlWork->unk_004 = gUnk_02039DC8->y;
                gBtlWork->x = gUnk_02039DC8->x;
                gBtlWork->y = gUnk_02039DC8->y;
                gBtlWork->x2 = gUnk_02039DC8->x;
                gBtlWork->y2 = gUnk_02039DC8->y;
                ScrollBgMapTo(0, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                ScrollBgMapTo(1, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                break;
            }
        }
    } else {
        n = func_08074E88(p, gUnk_02039DC8->unk_88);
        p->unk_00 = gUnk_02039DC8->unk_00[n]->unk_04;

        switch (gUnk_02039DC8->unk_87) {
        case 0:
        case 2:
            p->unk_04 = gUnk_02039DC8->unk_00[n]->unk_08 + gUnk_02039DC8->unk_00[n]->unk_0C + gUnk_09033758[n];
            break;
        case 1:
        case 3:
            p->unk_04 = gUnk_02039DC8->unk_00[n]->unk_08 + gUnk_02039DC8->unk_00[n]->unk_0C;
            break;
        }

        p->unk_10 = gUnk_02039DC8->unk_89;
        func_08074DC4(p);

        if (u != NULL) {
            if (u->unk_24 != 0) {
                SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
            } else {
                if (p->unk_08 == 77) {
                    ScrollBgMapTo(3, (gUnk_02039DC8->x >> 8) + 8, (gUnk_02039DC8->y >> 8) + 40);
                } else {
                    ScrollBgMapTo(3, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                }

                if (gUnk_02039DC8->unk_78 != 0) {
                    ScrollBgMapTo(2, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                }

                if (gUnk_02039DC8->unk_79 != 0) {
                    ScrollBgMapTo(1, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
                }
            }
        } else {
            gBtlWork->unk_000 = gUnk_02039DC8->x;
            gBtlWork->unk_004 = gUnk_02039DC8->y;
            ScrollBgMapTo(0, (gUnk_02039DC8->x >> 8) + 8, (gUnk_02039DC8->y >> 8) + 40);
            ScrollBgMapTo(1, gUnk_02039DC8->x >> 8, gUnk_02039DC8->y >> 8);
        }
    }

    if (gUnk_02039DC8->unk_64 & 4) {
        SetTaskUpdate(task, (u32)_08074EC8);
    }

    if (u != NULL && (u->unk_2D & 1)) {
        func_080CA368(3, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
    }

    func_08075010(p);
    return 1;
}
void view_2(void) {
}
void view_3(void) {
}

void func_08074D00(EventCameraWork* p) {
    gUnk_02039DC8->unk_50 = p->unk_00;
    gUnk_02039DC8->unk_54 = p->unk_04;
}

void func_08074D14(EventCameraWork* a) {
    EventCameraKeyframe* e;
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    e = &a->keyframes[a->unk_09];
    if (e->unk_14 & 0x2C00) {
        gUnk_02039DC8->unk_48 = x;
        gUnk_02039DC8->unk_4C = y;
    } else {
        gUnk_02039DC8->unk_48 += (x - gUnk_02039DC8->unk_48) >> 3;
        gUnk_02039DC8->unk_4C += (y - gUnk_02039DC8->unk_4C) >> 3;
    }
    gUnk_02039DC8->x = gUnk_02039DC8->unk_48 + (gUnk_02039DC8->unk_68 << 8);
    gUnk_02039DC8->y = gUnk_02039DC8->unk_4C + (gUnk_02039DC8->unk_6A << 8);
}

void func_08074D98(EventCameraWork* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_48 = x;
    gUnk_02039DC8->unk_4C = y;
}

void func_08074DC4(EventCameraWork* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;

    if (a->unk_10 != 0) {
        ApproachValue(&gUnk_02039DC8->unk_48, x, a->unk_10);
        ApproachValue(&gUnk_02039DC8->unk_4C, y, a->unk_10);
        a->unk_10--;
    } else {
        gUnk_02039DC8->unk_48 = x;
        gUnk_02039DC8->unk_4C = y;
    }
    gUnk_02039DC8->x = gUnk_02039DC8->unk_48 + (gUnk_02039DC8->unk_68 << 8);
    gUnk_02039DC8->y = gUnk_02039DC8->unk_4C + (gUnk_02039DC8->unk_6A << 8);
}

u8 func_08074E40(EventCameraWork* p) {
    EventSequenceDef* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    EventCharaTrack* q = t->charaTracks;
    EventCameraKeyframe* e = &p->keyframes[p->unk_09];
    u8 i;

    for (i = 0; i < n; i++) {
        if (e->unk_10 == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 func_08074E88(EventCameraWork* p, u8 v) {
    EventSequenceDef* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    EventCharaTrack* q = t->charaTracks;
    u8 i;

    for (i = 0; i < n; i++) {
        if (v == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 _08074EC8(EventCameraWork* p) {
    EventBackgroundDef* t;
    Ent08074EC8* q;
    u8 n;

    n = func_08074E88(p, 0);
    t = gUnk_09EE3CA0[p->unk_08];
    q = gUnk_02039DC8->unk_00[n];
    p->unk_00 = q->unk_04;
    p->unk_04 = q->unk_08 + q->unk_0C;

    if (t != NULL) {
        if (t->unk_24 != 0) {
            func_08074D98(p);
            SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
        } else {
            func_08074D14(p);

            if (p->unk_08 == 77) {
                ScrollBgMapTo(3, (gUnk_02039DC8->unk_48 >> 8) + 8 + gUnk_02039DC8->unk_68, (gUnk_02039DC8->unk_4C >> 8) + 40);
            } else {
                ScrollBgMapTo(3, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_78 != 0) {
                ScrollBgMapTo(2, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_79 != 0) {
                ScrollBgMapTo(1, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
            }
        }
    } else {
        func_08074D14(p);
        gBtlWork->unk_000 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_004 = gUnk_02039DC8->unk_4C;
        ScrollBgMapTo(0, (gUnk_02039DC8->unk_48 >> 8) + 8, (gUnk_02039DC8->unk_4C >> 8) + 40);
        ScrollBgMapTo(1, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
    }
    return 1;
}

void func_08075010(EventCameraWork* p) {
    u8 i;
    s32 v;

    if (p->waveEnabled == 1) {
        for (i = 0; i < 160; i++) {
            p->scanlineScrollX[i] = (gUnk_02039DC8->x >> 8) + (v = (u8)gSineTable[((i + p->wavePhase) * 2) & 0xFF]) / 32;
        }
        p->wavePhase++;
    }
}



TaskDesc gTaskDescEventSeq = {
    gTaskNameEventSeq,
    (void (*)(void*, void*))event_seq_0,
    event_seq_1,
    (void (*)(void*))event_seq_2,
    (void (*)(void*))event_seq_3,
#ifdef VERSION_EU
    0x40,
#else
    0x3C,
#endif
};


TaskDesc gTaskDescEventChara = {
    gTaskNameEventChara,
    (void (*)(void*, void*))event_chara_0,
    event_chara_1,
    (void (*)(void*))event_chara_2,
    (void (*)(void*))event_chara_3,
    0x1BC,
};

const u16* gUnk_09EE4704[4][2] = {
    {gUnk_08125E24, gUnk_0951D2B8},
    {gUnk_08125E24, gUnk_0951DAB8},
    {gUnk_0951E2B8, gUnk_08125E24},
    {gUnk_0951EAB8, gUnk_08125E24},
};

void* gUnk_09EE4724[4] = {
    gUnk_09EE4704[0],
    gUnk_09EE4704[1],
    gUnk_09EE4704[2],
    gUnk_09EE4704[3],
};


TaskDesc gTaskDescMsgwin = {
    gTaskNameMsgwin,
    (void (*)(void*, void*))func_08072D98,
    func_08072EAC,
    (void (*)(void*))func_08073238,
    (void (*)(void*))func_08073274,
    0x44,
};



TaskDesc gTaskDescMsgface[3] = {
    {
        gTaskNameMsgface,
        (void (*)(void*, void*))msgface_0,
        msgface_1,
        (void (*)(void*))msgface_2,
        (void (*)(void*))msgface_3,
        0x3C,
    },
    {
        gTaskNameMsgwait,
        (void (*)(void*, void*))msgwait_0,
        msgwait_1,
        (void (*)(void*))msgwait_2,
        (void (*)(void*))msgwait_3,
        0x108,
    },
    {
        gTaskNameMsgwaitYesno,
        (void (*)(void*, void*))msgwait_yesno_0,
        msgwait_yesno_1,
        (void (*)(void*))msgwait_yesno_2,
        (void (*)(void*))msgwait_yesno_3,
        0x108,
    },
};


TaskDesc gTaskDescView = {
    gTaskNameView,
    (void (*)(void*, void*))view_0,
    view_1,
    (void (*)(void*))view_2,
    (void (*)(void*))view_3,
    0x15C,
};
