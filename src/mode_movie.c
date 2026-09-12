#include "macros.h"
#include "mode_movie.h"

#ifdef VERSION_EU
extern u32 gLanguage;
extern u32 gUnkEu_03006C10;
extern Mode gModeChkmov;
extern u8 gUnkEu_0883E040[];
extern u8 gUnkEu_0883E454[];
extern u8 gUnkEu_0883E8D4[];
extern u8 gUnkEu_0883ECE8[];
extern u8 gUnkEu_0883F0F8[];
extern u8 gUnkEu_0883E070[];
extern u8 gUnkEu_0883E494[];
extern u8 gUnkEu_0883E914[];
extern u8 gUnkEu_0883ED28[];
extern u8 gUnkEu_0883F138[];
extern u8 gUnkEu_0883E150[];
extern u8 gUnkEu_0883E574[];
extern u8 gUnkEu_0883E9F4[];
extern u8 gUnkEu_0883EE08[];
extern u8 gUnkEu_0883F218[];
void eu_0800115C(void);
#endif

vu16 gUnk_02034938;
s32 gUnk_0203493C;
u16 gUnk_02034940;
volatile s16 gUnk_02034942;
volatile s16 gUnk_02034944;
volatile u16 gUnk_02034946;
MovieSub* volatile gUnk_02034948;
MovieSub* volatile gUnk_0203494C;
void* gUnk_02034950;
volatile s16 gUnk_02034954;
volatile u16 gUnk_02034956;
volatile u16 gUnk_02034958;
volatile u16 gUnk_0203495A;
volatile s16 gUnk_0203495C;
volatile u16 gUnk_0203495E;
volatile u16 gUnk_02034960;

void mode_movie_0(s32 a) {
    gUnk_02034938 = 0;
    gUnk_0203493C = a;
    gUnk_02034940 = 0;
    gUnk_02034942 = 0;
    gUnk_02034944 = 0;
    gUnk_02034946 = 0;
    gUnk_02034950 = 0;
    gUnk_02034958 = 0;
    gUnk_02034954 = 0;
    gUnk_02034956 = 0;
    gUnk_0203495A = 0;
    gUnk_02034948 = 0;
    gUnk_0203495C = 0;
    gUnk_0203495E = 0;
    gUnk_02034960 = 0;
    gUnk_0203494C = 0;
}

#ifdef NON_MATCHING
s32 func_0805E93C(void) {
    MovieSub* e;
    s32 i;
    u16 keys;

    keys = ~*(vu16*)0x04000130;

    if ((keys & 0xF) == 0xF) {
        gUnk_02034958 |= 4;
        return 1;
    }

    if (gUnk_02034950 != 0) {
        for (i = 1; i >= 0; i--) {
            if (((MovieSub*)gUnk_02034950)[gUnk_02034944].unk_00 == gUnk_02034942) {
                if (((MovieSub*)gUnk_02034950)[gUnk_02034944].unk_08 == 0) {
                    e = &((MovieSub*)gUnk_02034950)[gUnk_02034944];
                    gUnk_02034948 = e;
                    gUnk_02034958 |= 1;
                    gUnk_02034954 = e->unk_0A;

                    if (gUnk_02034944 < gUnk_02034946 - 1) {
                        gUnk_02034944++;
                    }

                    gUnk_02034956 = func_0805E89C(gUnk_02034948->unk_04);

                    if (gUnk_02034956 > 40) {
                        gUnk_02034956 = 40;
                    }
                } else {
                    e = &((MovieSub*)gUnk_02034950)[gUnk_02034944];
                    gUnk_0203494C = e;
                    gUnk_02034958 |= 2;
                    gUnk_0203495C = e->unk_0A;

                    if (gUnk_02034944 < gUnk_02034946 - 1) {
                        gUnk_02034944++;
                    }

                    gUnk_0203495E = func_0805E89C(e->unk_04);

                    if (gUnk_0203495E > 40) {
                        gUnk_0203495E = 40;
                    }
                }
            }
        }

        if (gUnk_02034954 > 0) {
            gUnk_02034954--;
        }

        if (gUnk_0203495C > 0) {
            gUnk_0203495C--;
        }
    }
    gUnk_02034942++;
    return 0;
}
#else
INCLUDE_ASM("mode_movie/func_0805E93C.s");
#endif
#ifdef NON_MATCHING
void func_0805EA90(void) {
    u16* oam;
    s16 x;
    s16 y;
    u16 i;
    u16 tile;
    u16 palette;
    u32 attr0;
    u32 attr1;

    if (gUnk_02034958 & 8) {
        *(vu16*)0x04000000 = 0xF43;
        MovieUpdate();
        if (gUnk_02034950 != 0) {
            if (gUnk_02034958 & 1) {
                gUnk_02034958 &= ~1;
                gUnk_0203495A = 0;
#ifdef VERSION_JP
                func_0806C490(gUnk_02034948->unk_04);
#else
                func_0806CBAC(gUnk_02034948->unk_04, gUnk_02034968, 0);
#endif
            }
            if (gUnk_02034958 & 2) {
                gUnk_02034958 &= ~2;
                gUnk_02034960 = 0;
#ifdef VERSION_JP
                func_0806C81C(gUnk_0203494C->unk_04, 0x100);
#else
                func_0806CBAC(gUnk_0203494C->unk_04, gUnk_020349B8, 0x100);
#endif
            }
            if (gUnk_02034954 > 0 || gUnk_0203495A != 0 ||
                gUnk_0203495C > 0 || gUnk_02034960 != 0) {
                *(vu16*)0x04000000 |= 0x1000;
                *(vu16*)0x04000050 = 0xF10;
                if (gUnk_0203495A < 16) {
                    if (gUnk_0203495A == 0) {
                        attr0 = 0x200;
                    } else {
                        *(vu16*)0x04000052 = ((16 - gUnk_0203495A) << 8) | gUnk_0203495A;
                        attr0 = 0x400;
                    }
                } else {
                    attr0 = 0;
                }
                if (gUnk_02034960 < 16) {
                    if (gUnk_02034960 == 0) {
                        attr1 = 0x200;
                    } else {
                        *(vu16*)0x04000052 = ((16 - gUnk_02034960) << 8) | gUnk_02034960;
                        attr1 = 0x400;
                    }
                } else {
                    attr1 = 0;
                }
                oam = (u16*)0x07000000;
#ifndef VERSION_JP
                x = 0;
                y = 0;
                if (gUnk_02034956 != 0) {
                    x = gUnk_02034948->unk_02;
                    x += func_0805E848(gUnk_02034968, gUnk_02034956);
                    y = 0x74;
                }
#endif
                for (i = 0; i < gUnk_02034956; i++) {
                    tile = i * 4;
                    palette = (gUnk_02034948->unk_0C & 15) << 12;
#ifdef VERSION_JP
                    oam[0] = attr0 | 0x74;
                    oam[1] = (gUnk_02034948->unk_02 + i * 10) | 0x4000;
#else
                    oam[0] = attr0 | y;
                    oam[1] = x | 0x4000;
#endif
                    oam[2] = palette | (tile + 0x200);
                    oam += 4;
#ifndef VERSION_JP
                    x += gUnk_02034968[i];
#endif
                }
#ifndef VERSION_JP
                if (gUnk_0203495E != 0) {
                    x = gUnk_0203494C->unk_02;
                    x += func_0805E848(gUnk_020349B8, gUnk_0203495E);
                    y = 0x84;
                }
#endif
                for (i = 0; i < gUnk_0203495E; i++) {
                    tile = i * 4;
                    palette = (gUnk_0203494C->unk_0C & 15) << 12;
#ifdef VERSION_JP
                    oam[0] = attr1 | 0x84;
                    oam[1] = (gUnk_0203494C->unk_02 + i * 10) | 0x4000;
#else
                    oam[0] = attr1 | y;
                    oam[1] = x | 0x4000;
#endif
                    oam[2] = palette | (tile + 0x300);
                    oam += 4;
#ifndef VERSION_JP
                    x += gUnk_020349B8[i];
#endif
                }
                for (i = gUnk_02034956 + gUnk_0203495E;
#ifdef VERSION_JP
                     i < 48;
#else
                     i < 80;
#endif
                     i++) {
                    oam[0] = 0x200;
                    oam += 4;
                }
                if (gUnk_02034954 > 0) {
                    if (gUnk_0203495A < 16) {
                        gUnk_0203495A += 4;
                    }
                } else if (gUnk_0203495A != 0) {
                    gUnk_0203495A -= 4;
                    if (gUnk_0203495A == 0) {
                        gUnk_02034956 = 0;
                    }
                }
                if (gUnk_0203495C > 0) {
                    if (gUnk_02034960 < 16) {
                        gUnk_02034960 += 4;
                    }
                } else if (gUnk_02034960 != 0) {
                    gUnk_02034960 -= 4;
                    if (gUnk_02034960 == 0) {
                        gUnk_0203495E = 0;
                    }
                }
            } else {
                *(vu16*)0x04000000 &= ~0x1000;
            }
        }
    }
    *(vu16*)0x03007FF8 |= 1;
}
#else
INCLUDE_ASM("mode_movie/func_0805EA90.s");
#endif

void mode_movie_1(void) {
    void* p;

    switch (gUnk_02034938) {
    case 0: {
        s32 fill;

        InitDisplayRegs();
        gDispCnt &= 0xE0FF;
        fill = 0;
        CpuSet(&fill, (void*)0x06000000, 0x05006000);
        gUnk_02034938++;
        break;
    }
    case 1:
        gUnk_02034938++;
        break;
    case 2:
        m4aSoundVSyncOff();
        gVBlankHandlerOverride = func_0805EA90;
        IwramHeapInit(GetIwramHeapStart(), GetIwramHeapSize());
        EwramHeapInit(GetEwramHeapStart(), GetEwramHeapSize());
        SetEwramHeapName(sMovieHeapName);
        SetIwramHeapName(sMovieHeapName);
        CpuSet(gUnk_08F69C04, (void*)0x05000200, 16);
        CpuSet(gUnk_09614718, (void*)0x05000220, 16);
        MovieSetCallbacks(IwramAlloc, EwramAlloc, IwramFree, EwramFree);

        switch (gUnk_0203493C) {
        case 1:
            p = gUnk_0815C3EC;
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                gUnk_02034950 = gUnkEu_0883E040;
                gUnk_02034946 = 3;
                break;
            case 1:
                gUnk_02034950 = gUnkEu_0883E454;
                gUnk_02034946 = 4;
                break;
            case 2:
                gUnk_02034950 = gUnkEu_0883E8D4;
                gUnk_02034946 = 4;
                break;
            case 3:
                gUnk_02034950 = gUnkEu_0883ECE8;
                gUnk_02034946 = 4;
                break;
            case 4:
            default:
                gUnk_02034950 = gUnkEu_0883F0F8;
                gUnk_02034946 = 4;
                break;
            }
#else
            gUnk_02034950 = gUnk_0886AB40;
            gUnk_02034946 = 3;
#endif
            break;
        case 2:
            p = gUnk_084E0F34;
            gUnk_02034950 = 0;
            gUnk_02034946 = 0;
            break;
        case 3:
            p = gUnk_084F4660;
            gUnk_02034950 = 0;
            gUnk_02034946 = 0;
            break;
        case 4:
            p = gUnk_0855CCB4;
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                gUnk_02034950 = gUnkEu_0883E070;
                gUnk_02034946 = 14;
                break;
            case 1:
                gUnk_02034950 = gUnkEu_0883E494;
                gUnk_02034946 = 14;
                break;
            case 2:
                gUnk_02034950 = gUnkEu_0883E914;
                gUnk_02034946 = 14;
                break;
            case 3:
                gUnk_02034950 = gUnkEu_0883ED28;
                gUnk_02034946 = 14;
                break;
            case 4:
            default:
                gUnk_02034950 = gUnkEu_0883F138;
                gUnk_02034946 = 14;
                break;
            }
#else
            gUnk_02034950 = gUnk_0886AB90;
#ifdef VERSION_JP
            gUnk_02034946 = 12;
#else
            gUnk_02034946 = 14;
#endif
#endif
            break;
#ifdef VERSION_EU
        default:
#endif
        case 5:
            p = gUnk_086FBA14;
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                gUnk_02034950 = gUnkEu_0883E150;
                gUnk_02034946 = 10;
                break;
            case 1:
                gUnk_02034950 = gUnkEu_0883E574;
                gUnk_02034946 = 12;
                break;
            case 2:
                gUnk_02034950 = gUnkEu_0883E9F4;
                gUnk_02034946 = 11;
                break;
            case 3:
                gUnk_02034950 = gUnkEu_0883EE08;
                gUnk_02034946 = 10;
                break;
            case 4:
            default:
                gUnk_02034950 = gUnkEu_0883F218;
                gUnk_02034946 = 11;
                break;
            }
#else
            gUnk_02034950 = gUnk_0886AC70;
#ifdef VERSION_JP
            gUnk_02034946 = 8;
#else
            gUnk_02034946 = 10;
#endif
#endif
            break;
#ifndef VERSION_EU
        default:
            p = gUnk_0855CCB4;
            gUnk_02034950 = gUnk_0886AB40;
            gUnk_02034946 = 3;
            break;
#endif
        }

        if (MovieStart(p)) {
            gUnk_02034958 |= 8;
            MoviePlay(func_0805E93C, 0);
            gUnk_02034958 &= 0xFFF7u;
        }

        MovieClose();
        IwramHeapInit(GetIwramHeapStart(), GetIwramHeapSize());
        EwramHeapInit(GetEwramHeapStart(), GetEwramHeapSize());
        VTransInit();
        SpriteInit();
        BgInit();
        FadeInit();
        PalletInit();
        SioKeyInit();
        VTransReset();
        BgReset();
        SpriteReset();
        FadeReset();
        MosaicReset();
        InitDisplayRegs();
        gVBlankHandlerOverride = 0;
        m4aSoundInit();
        m4aSoundVSyncOn();
        gUnk_02034938++;
        break;
    case 3: {
        s32 fill;

        fill = 0;
        CpuSet(&fill, (void*)0x06000000, 0x05006000);

        if (gUnk_02034958 & 4) {
#ifdef VERSION_EU
            eu_0800115C();
#else
            SoftReset(0xFF);
#endif
#ifdef VERSION_EU
        } else if (gUnkEu_03006C10 & 0x8000) {
            ModeRequest(&gModeChkmov, 0);
#endif
        } else {
            switch (gUnk_0203493C) {
            case 1:
                func_0806180C(0);
                break;
            case 2:
                func_0806180C(26);
                break;
            case 3:
                func_0806180C(57);
                break;
            case 4:
                ModeRequest(gModeStaffRoll, 0);
                break;
            case 5:
                ModeRequest(gModeStaffRoll, 0);
                break;
            default:
                ModeRequest(&gModeDebug, 0);
                break;
            }
        }
        gUnk_02034938++;
        break;
    }
    }
}

void mode_movie_2(void) {
    gVBlankHandlerOverride = 0;
}
