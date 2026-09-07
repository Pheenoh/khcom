#include "macros.h"
#include "mode_movie.h"

vu16 gUnk_02034938;
s32 gUnk_0203493C;
u16 gUnk_02034940;
volatile s16 gUnk_02034942;
volatile s16 gUnk_02034944;
volatile u16 gUnk_02034946;
MovieSub* volatile gUnk_02034948;
MovieSub* gUnk_0203494C;
void* gUnk_02034950;
volatile s16 gUnk_02034954;
volatile u16 gUnk_02034956;
u16 gUnk_02034958;
u16 gUnk_0203495A;
volatile s16 gUnk_0203495C;
volatile u16 gUnk_0203495E;
u16 gUnk_02034960;

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
INCLUDE_ASM("mode_movie/func_0805EA90.s");

#ifndef VERSION_EU
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
            gUnk_02034950 = gUnk_0886AB40;
            gUnk_02034946 = 3;
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
            gUnk_02034950 = gUnk_0886AB90;
#ifdef VERSION_JP
            gUnk_02034946 = 12;
#else
            gUnk_02034946 = 14;
#endif
            break;
        case 5:
            p = gUnk_086FBA14;
            gUnk_02034950 = gUnk_0886AC70;
#ifdef VERSION_JP
            gUnk_02034946 = 8;
#else
            gUnk_02034946 = 10;
#endif
            break;
        default:
            p = gUnk_0855CCB4;
            gUnk_02034950 = gUnk_0886AB40;
            gUnk_02034946 = 3;
            break;
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
            SoftReset(0xFF);
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
#else
INCLUDE_ASM("mode_movie/mode_movie_1.s");
#endif

void mode_movie_2(void) {
    gVBlankHandlerOverride = 0;
}
