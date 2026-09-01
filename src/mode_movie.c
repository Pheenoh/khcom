#include "macros.h"
#include "mode_movie.h"

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

INCLUDE_ASM("mode_movie/func_0805E93C.s");
INCLUDE_ASM("mode_movie/func_0805EA90.s");

#ifdef VERSION_US
void mode_movie_1(void) {
    void* p;

    switch (gUnk_02034938) {
    case 0: {
        s32 fill;

        func_08004034();
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
        gUnk_03007484 = func_0805EA90;
        func_08000884(func_08000250(), func_08000258());
        func_08000860(func_08000240(), func_08000248());
        func_08000AD8(gUnk_0886AD10);
        func_08000AE4(gUnk_0886AD10);
        CpuSet(gUnk_08F69C04, (void*)0x05000200, 16);
        CpuSet(gUnk_09614718, (void*)0x05000220, 16);
        func_081181BC(IwramAlloc, EwramAlloc, IwramFree, EwramFree);

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
            gUnk_02034946 = 14;
            break;
        case 5:
            p = gUnk_086FBA14;
            gUnk_02034950 = gUnk_0886AC70;
            gUnk_02034946 = 10;
            break;
        default:
            p = gUnk_0855CCB4;
            gUnk_02034950 = gUnk_0886AB40;
            gUnk_02034946 = 3;
            break;
        }

        if (func_081181EC(p)) {
            gUnk_02034958 |= 8;
            func_08118344(func_0805E93C, 0);
            gUnk_02034958 &= 0xFFF7u;
        }

        func_08118538();
        func_08000884(func_08000250(), func_08000258());
        func_08000860(func_08000240(), func_08000248());
        func_08004314();
        func_08001D60();
        func_08004B8C();
        func_08005B78();
        func_08007E90();
        func_08008808();
        func_08004364();
        func_08004D74();
        func_08001F98();
        func_08005BC4();
        func_08006404();
        func_08004034();
        gUnk_03007484 = 0;
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
                func_080010CC(gUnk_09EFA9C4, 0);
                break;
            case 5:
                func_080010CC(gUnk_09EFA9C4, 0);
                break;
            default:
                func_080010CC(gUnk_09ECEB64, 0);
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
    gUnk_03007484 = 0;
}
