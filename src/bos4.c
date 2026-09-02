#include "macros.h"
#include "bos4.h"

INCLUDE_ASM("bos4/task_bos_boogie_dice_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_dice_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_dice_2.s");

void task_bos_boogie_dice_3(BoogieDiceWork* work) {
    if (work->unk_168 == 0 && gUnk_0203C560 != 3 && work->unk_170 == 0 && work->unk_000 != 10) {
        gUnk_0203C564 = 1;
    }

    func_08012304(&work->unk_080);
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

INCLUDE_ASM("bos4/func_080DA42C.s");

u8 func_080DA4DC(u8* p) {
    u8* q = *(u8**)(p + 0x15C);

    if (*(u32*)(q + 0x15C) == 3 && func_08005B34(q + 20) <= 2) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/task_bos_boogie_explosiondice_0.s");

u8 task_bos_boogie_explosiondice_1(BoogieExplosiondiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    if (func_080DA4DC((u8*)work) != 0) {
        return 1;
    }

    switch (work->unk_000) {
    case 0:
        work->unk_150 += 51;
        p->unk_0C += work->unk_150;

        if (p->unk_0C > -0x2000) {
            func_08014020(p->unk_04, p->unk_08 + p->unk_0C, 0);
            return 0;
        }

        break;
    case 2:
        if (func_080128EC() == 0) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->unk_014);
    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}

INCLUDE_ASM("bos4/task_bos_boogie_explosiondice_2.s");

void task_bos_boogie_explosiondice_3(BoogieExplosiondiceWork* work) {
    func_08012304(&work->unk_080);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

u8 func_080DA73C(void) {
    if (*(s32*)((u8*)gUnk_02039B84->unk_07C + 8) <= 0x23EFF) {
        return 1;
    }

    return 0;
}

void task_bos_boogie_saku_0(BoogieSakuWork* work, void* arg) {
    work->unk_024 = (u32)arg;
    work->unk_000 = (u32)LoadObjTiles(gUnk_09799CBA, 0x2E0);
    work->unk_004 = (u32)LoadObjPalette(gUnk_0984AF78, 32);
    AnimInit(&work->unk_008, gUnk_09EF680C, gUnk_09EF67FC);
    AnimStart(&work->unk_008, 0, 0);
    work->unk_020 = 0;
    TaskPoolInit(&work->unk_028, 1);
    work->unk_03C = 0;
    work->unk_040 = 0;
}

INCLUDE_ASM("bos4/task_bos_boogie_saku_1.s");

void func_080DA954(BoogieSakuWork* work, s32 a, u16 b) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, a, 0x23F00, -0x2000);
    DrawSprite(x, y + 1, AnimGetGfx(&work->unk_008), (void*)work->unk_000, (void*)work->unk_004, 0, b, 0xE700);
    TaskPoolDraw(&work->unk_028);
}

void task_bos_boogie_saku_2(BoogieSakuWork* work) {
    u16 v = func_0801AF1C(0x23F00);

    func_080DA954(work, 0xA800, v);
    func_080DA954(work, 0xF800, v);
    func_080DA954(work, 0x14800, v);
}

void task_bos_boogie_saku_3(BoogieSakuWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
    TaskPoolDestroy(&work->unk_028);
}

void task_bos_boogie_map_0(void* work, UnkStruct_080DAA28* arg) {
    LoadBgTiles(0, arg->unk_00, arg->unk_04);
    LoadBgPalette(0, arg->unk_08, arg->unk_0C);
    func_0800516C(0, &arg->unk_10, 2, 2);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0xF800;
    gUnk_02039B84->unk_00C = 0x21000;
    gUnk_02039B84->unk_000 = 0xF800;
    gUnk_02039B84->unk_004 = 0x21000;
    gUnk_02039B84->unk_010 = 0xF800;
    gUnk_02039B84->unk_014 = 0x21000;
    gUnk_02039B84->unk_01C = 0xF800;
    gUnk_02039B84->unk_020 = 0x21000;
    gUnk_02039B84->unk_01A = 15;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
}

INCLUDE_ASM("bos4/task_bos_boogie_map_1.s");

void task_bos_boogie_mapanime_0(BoogieMapanimeWork* work) {
    func_080DDDDC(&work->unk_000[0], &gUnk_096FE034);
    func_080DDDDC(&work->unk_000[1], &gUnk_096FE04C);
    func_080DDDDC(&work->unk_000[2], &gUnk_096FE064);
}

u8 task_bos_boogie_mapanime_1(BoogieMapanimeWork* work) {
    u32 i;
    u8 r = 0;

    for (i = gUnk_0203C560; i <= 2; i++) {
        r = func_080DDDEC(&work->unk_000[i], work->unk_000[i].unk_08, r);
    }

    return 1;
}

void task_bos_boogie_mapanime_2(void) {
}

void task_bos_boogie_mapanime_3(void) {
}

u8 func_080DABFC(s32* x, s32* y, s16 w, s16 h) {
    u8 r = 0;

    if (*x < (0x80 - w) << 8) {
        *x = (0x80 - w) << 8;
        r = 1;
    }

    if (*x > (w + 0x170) << 8) {
        *x = (w + 0x170) << 8;
        r = 1;
    }

    if (*y < (0x240 - h) << 8) {
        *y = (0x240 - h) << 8;
        r = 1;
    }

    if (*y > (0x278 - h) << 8) {
        *y = (0x278 - h) << 8;
        r = 1;
    }

    return r;
}

INCLUDE_ASM("bos4/task_bos_boogie_disk_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_disk_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_disk_2.s");

void task_bos_boogie_disk_3(BoogieDiskWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

INCLUDE_ASM("bos4/func_080DB04C.s");
INCLUDE_ASM("bos4/task_bos_boogie_knife_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_knife_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_knife_2.s");

void task_bos_boogie_knife_3(BoogieKnifeWork* work) {
    func_08012304(&work->unk_06C);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
}

u8 func_080DB428(u8* p) {
    if (*(s32*)(p + 0x38) >= 0) {
        return 1;
    }

    return 0;
}

u8 func_080DB438(BoogieKnifeWork* work) {
    s32 i;

    for (i = 0; i <= 4; i++) {
        if (func_08000F48(work->unk_12C[i]) != 0) {
            return 1;
        }
    }

    return 0;
}

INCLUDE_ASM("bos4/func_080DB468.s");

void task_bos_boogie_knifereader_0(BoogieKnifereaderWork* work) {
    s32 i;

    work->unk_000 = 2;
    work->unk_004 = 0;
    gUnk_0203C574 = 0;
    TaskPoolInit(&work->unk_008, 5);

    for (i = 0; i < 5; i++) {
        work->unk_12C[i] = 0;
    }

    func_0801B37C(&work->unk_01C, gUnk_096FE0E8, 0xF800, 0x24000, 0);
    func_0801C2DC(&work->unk_01C, 1);
    func_0801BCD4(&work->unk_01C);
}

INCLUDE_ASM("bos4/task_bos_boogie_knifereader_1.s");

void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work) {
    TaskPoolDraw(&work->unk_008);
}

void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work) {
    func_0801B7D8(&work->unk_01C);
    TaskPoolDestroy(&work->unk_008);
}

INCLUDE_ASM("bos4/task_bos_boogie_kaihuku_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_kaihuku_1.s");

void task_bos_boogie_kaihuku_2(BoogieKaihukuWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    void* d;
    u16 v;
    s16 x;
    s16 y;

    if (work->unk_000 != 2) {
        v = func_0801AF1C(p->unk_08);
        d = (void*)work->unk_00C;
        WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
        DrawSprite(x, y, AnimGetGfx(&work->unk_014), (void*)work->unk_008, d, 0, v, -0x1004 - (p->unk_08 >> 8) * 4);
    }
}

void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
}

INCLUDE_ASM("bos4/func_080DB978.s");

u8 func_080DBA14(UrsulaWork* work) {
    if (work->unk_142 == 0 && func_080DD1FC(*(void**)(work->unk_01C + 4)) == 0 && func_080DD1FC(*(void**)(work->unk_020 + 4)) == 0) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/task_bos_ursula_0.s");

void func_080DBC00(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    if ((s16)work->unk_140 == 0) {
        work->unk_140 = 32;

        if (work->unk_13C == 0) {
            work->unk_13C = -0x400;
        } else {
            work->unk_13C = 0;
        }
    }

    ApproachValue(&work->unk_138, work->unk_13C, work->unk_140);
    p->unk_0C = gUnk_0203C580 + work->unk_138;
    work->unk_140--;
}

u8 func_080DBC68(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    func_080DBC00(work);

    if (func_080DC510() != 0) {
        p->unk_04 -= 0x100;

        if (p->unk_04 <= -0x9800) {
            p->unk_04 = -0x9800;
            return 0;
        }
    } else {
        p->unk_04 += 0x100;

        if (p->unk_04 >= 0x28000) {
            p->unk_04 = 0x28000;
            return 0;
        }
    }

    return 1;
}

s32 func_080DBCC0(UrsulaWork* work) {
    s32* p = (s32*)gUnk_02039B84->unk_07C;

    if (p[1] < work->unk_028 - 0x5000 || work->unk_028 + 0x5000 < p[1]) {
        return 1;
    }

    return 3;
}

s32 func_080DBCEC(UrsulaWork* work) {
    if (work->unk_028 - 0x3800 < *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) && *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) < work->unk_028 + 0x3800) {
        return 3;
    }

    if (work->unk_028 - 0x6800 < *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) && *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) < work->unk_028 + 0x6800) {
        return 2;
    }

    return 1;
}

INCLUDE_ASM("bos4/func_080DBD44.s");

s32 func_080DBDC0(UrsulaWork* work) {
    switch (func_080DC5E8()) {
    case 0:
        return func_080DBCC0(work);
    case 1:
        return func_080DBCEC(work);
    case 2:
    default:
        return func_080DBD44(work);
    }
}

void func_080DBDEC(UrsulaWork* work) {
    if (work->unk_160 != 0) {
        func_080DD210(*(void**)(work->unk_01C + 4));
        func_080DD210(*(void**)(work->unk_020 + 4));
        work->unk_160 = 0;
    }
}

void func_080DBE18(UrsulaWork* work) {
    if (work->unk_142 == 0 && func_080DD230(*(void**)(work->unk_01C + 4)) == 0 && func_080DD230(*(void**)(work->unk_020 + 4)) == 0) {
        func_080DBDEC(work);
        work->unk_160 = 1;
    } else {
        work->unk_160 = 0;
    }
}

u8 func_080DBE64(void) {
    switch (func_080DC5E8()) {
    case 0:
        return 150;
    case 1:
        return 120;
    case 2:
    default:
        return 100;
    }
}

INCLUDE_ASM("bos4/task_bos_ursula_1.s");
INCLUDE_ASM("bos4/task_bos_ursula_2.s");

void task_bos_ursula_3(UrsulaWork* work) {
    func_0801B7D8(&work->unk_024);
    TaskPoolDestroy(&work->unk_008);
    gDispCnt &= 0xDFFF;
}

u8 func_080DC510(void) {
    return *(u64*)((u8*)gUnk_02034F0C + 0x58) & 4;
}

u8 func_080DC528(void) {
    if (*(u16*)((u8*)gUnk_02034F0C + 0x142) == 0) {
        return 0;
    }

    return 1;
}

u8 func_080DC544(void) {
    UnkStruct_02039B84* p;
    u8 r = 1;

    for (p = func_08000C8C(gUnk_02039B84->unk_080); p != 0; p = func_08000CD4((u8*)p + 0xB8)) {
        if (p->unk_000 == 0x23) {
            r = 0;
            break;
        }
    }

    return r;
}

u8 func_080DC578(void) {
    if (func_080DC544() != 0 || func_080DC528() == 0 || *(u16*)((u8*)gUnk_02034F0C + 0x15E) == 0) {
        return 0;
    }

    return 1;
}

u8 func_080DC5B0(void) {
    if (func_080DC528() != 0 && (*(u32*)((u8*)gUnk_02034F0C + 0x158) != 0 || *(u16*)((u8*)gUnk_02034F0C + 0x15C) != 0)) {
        return 1;
    }

    return 0;
}

u32 func_080DC5E8(void) {
    s16* p = (s16*)((u8*)gUnk_02034F0C + 0x50);

    if (*p > (s16)(*(s16*)((u8*)gUnk_02034F0C + 0x52) / 3) * 2) {
        return 0;
    }

    if (*p > (s16)(*(s16*)((u8*)gUnk_02034F0C + 0x52) / 3)) {
        return 1;
    }

    return 2;
}

u8 func_080DC628(void) {
    if (**(u32**)&gUnk_02034F0C == 4) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/task_bos_ursula_map_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_map_1.s");

void task_bos_ursula_map_3(void) {
}

void task_bos_ursula_border_0(UrsulaBorderWork* work) {
    work->unk_000 = LoadObjTiles(gUnk_0979D0B6, 0x800);
    work->unk_004 = LoadObjPalette(gUnk_0984B0D8, 0x20);
    func_0801C298(((u8*)work->unk_004)[6] + 16, 0);
}

s32 task_bos_ursula_border_1(void) {
    return 1;
}

INCLUDE_ASM("bos4/task_bos_ursula_border_2.s");

void task_bos_ursula_border_3(UrsulaBorderWork* work) {
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

INCLUDE_ASM("bos4/func_080DC9DC.s");

u8 func_080DCA78(u8 a) {
    if (a == func_080DC510()) {
        return 12;
    }

    return 6;
}

INCLUDE_ASM("bos4/task_bos_ursula_tako_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_tako_1.s");

void task_bos_ursula_tako_2(UrsulaTakoWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_028;
    void* pal;
    s16 x;
    s16 y;

    if (work->unk_138 != 4 && func_080DC528() == 0) {
        pal = func_0801CA00(p) != 0 ? work->unk_008 : work->unk_004;
        WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
        DrawSprite(x, y, AnimGetGfx(&work->unk_00C), work->unk_000, pal, 0, 0x800, 0xFC00);
    }
}

void task_bos_ursula_tako_3(UrsulaTakoWork* work) {
    func_0801B7D8(&work->unk_028);
    func_08012304(&work->unk_19C);
    func_08012304(&work->unk_140);
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
    ReleaseObjPalette(work->unk_008);
}

u8 func_080DD1FC(UrsulaTakoWork* work) {
    if (work->unk_138 <= 1) {
        return 0;
    }

    return 1;
}

void func_080DD210(UrsulaTakoWork* work) {
    if (work->unk_138 >= 3 && work->unk_138 <= 4) {
        work->unk_138 = 4;
        work->unk_13C = 180;
    }
}

u8 func_080DD230(UrsulaTakoWork* work) {
    if (work->unk_16E & 2) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/func_080DD248.s");
INCLUDE_ASM("bos4/task_bos_ursula_backtako_0.s");

u8 task_bos_ursula_backtako_1(UrsulaBacktakoWork* work) {
    if (func_080DC628() == 0) {
        func_080DD248(&work->unk_02C, &work->unk_030, &work->unk_034, work);
        work->unk_022 = work->unk_022 == 0 ? 1 : 0;
        func_080DD248(&work->unk_038, &work->unk_03C, &work->unk_040, work);
        work->unk_022 = work->unk_022 == 0 ? 1 : 0;
        AnimUpdate(&work->unk_008);
    }

    return 1;
}

INCLUDE_ASM("bos4/task_bos_ursula_backtako_2.s");

void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
}

void task_bos_ursula_mapanime_0(UrsulaMapanimeWork* work) {
    gUnk_02034F10 = work;
    TaskPoolInit(&work->unk_010, 1);
    work->unk_024 = 0;
    work->unk_00C = 4;
    func_080DD69C(0);
}

INCLUDE_ASM("bos4/task_bos_ursula_mapanime_1.s");

void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work) {
    TaskPoolDraw(&work->unk_010);
}

void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work) {
    TaskPoolDestroy(&work->unk_010);
}

INCLUDE_ASM("bos4/func_080DD69C.s");

u8 func_080DD754(void) {
    if (gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE290 || gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE2A8 || gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE278) {
        return 1;
    }

    return func_08000F48((void*)gUnk_02034F10->unk_024);
}

u8 func_080DD794(void) {
    if (gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE2A8 && func_080DDEA0(&gUnk_02034F10->unk_000) == 2) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/func_080DD7C4.s");

u16 func_080DD854(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 14;

    for (i = 0; i <= 5; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);
        a += 20;
    }

    return i;
}

u16 func_080DD8A8(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 240;

    for (i = 0; i <= 9; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);
        a += 16;
    }

    return i;
}

void task_bos_ursula_bubble_0(UrsulaBubbleWork* work) {
    TaskPoolInit(&work->unk_004, 10);
    work->unk_040 = 0;

    switch (func_080DC5E8()) {
    case 2:
        work->unk_040 = func_080DD8A8(work);
        break;
    case 1:
        work->unk_040 += func_080DD854(work);
        break;
    case 0:
    default:
        work->unk_040 += func_080DD7C4(work);
        break;
    }

    m4aSongNumStart(640);
}

u8 task_bos_ursula_bubble_1(UrsulaBubbleWork* work) {
    s32 i;

    TaskPoolUpdate(&work->unk_004);

    for (i = 0; i < work->unk_040; i++) {
        if (func_08000F48(work->unk_018[i]) != 0) {
            break;
        }
    }

    if (i == work->unk_040) {
        return 0;
    }

    return 1;
}

void task_bos_ursula_bubble_2(UrsulaBubbleWork* work) {
    TaskPoolDraw(&work->unk_004);
}

#ifndef VERSION_EU
void task_bos_ursula_bubble_3(UrsulaBubbleWork* work) {
    TaskPoolDestroy(&work->unk_004);
}
#else
INCLUDE_ASM("bos4/task_bos_ursula_bubble_3.s");
#endif

void func_080DD9B0(UrsulaBubbleWork* work) {
    s32 i;

    for (i = 0; i < work->unk_040; i++) {
        if (func_08000F48(work->unk_018[i]) != 0) {
            func_080DDD30(*(void**)((u8*)work->unk_018[i] + 4));
        }
    }
}

INCLUDE_ASM("bos4/task_bos_ursula_bubble_single_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_single_1.s");

void task_bos_ursula_bubble_single_2(UrsulaBubbleSingleWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;
    void* pal;
    u16 v;
    s16 x;
    s16 y;

    v = func_0801AF1C(p->unk_08);
    pal = func_0801CA00(p) != 0 ? work->unk_008 : work->unk_004;
    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
    DrawSprite(x, y, AnimGetGfx(&work->unk_00C), work->unk_000, pal, 0, v, -0x1004 - (p->unk_08 >> 8) * 4);
}

void task_bos_ursula_bubble_single_3(UrsulaBubbleSingleWork* work) {
    func_0801B7D8(&work->unk_024);
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
    ReleaseObjPalette((void*)work->unk_008);
}

void func_080DDD30(UrsulaBubbleSingleWork* work) {
    if (func_08005B30(&work->unk_00C) == 0) {
        work->unk_134 = 0;
        AnimStart(&work->unk_00C, 1, 0);
        func_0801C2DC(&work->unk_024, 1);
        work->unk_138 = 2;
    }
}

void task_bos_ursula_thunder_0(UrsulaThunderWork* work) {
    u8* p = (u8*)gUnk_02039B84->unk_07C;

    work->unk_004 = *(s32*)(p + 4);
    work->unk_008 = *(s32*)(p + 8);
    work->unk_00C = *(s32*)(p + 12) - 0x6000;
    func_08017390(work->unk_004, work->unk_008, work->unk_00C);
    work->unk_000 = 0;
}

u8 task_bos_ursula_thunder_1(UrsulaThunderWork* work) {
    if (func_080128EC() == 0) {
        if (work->unk_000 != 0) {
            return 0;
        }

        func_080155BC(work->unk_004, work->unk_008, 0, 244);
        work->unk_000 = 1;
    }

    return 1;
}

void task_bos_ursula_thunder_2(void) {
}

void task_bos_ursula_thunder_3(void) {
}

void func_080DDDDC(UnkStruct_080DDDDC* p, UnkStruct_096FE034* q) {
    p->unk_00 = 0;
    p->unk_02 = 0;
    p->unk_04 = 1;
    p->unk_08 = q;
}

INCLUDE_ASM("bos4/func_080DDDEC.s");

u8 func_080DDE74(UnkStruct_080DDDDC* p) {
    UnkStruct_096FE034* q = p->unk_08;

    if (p->unk_00 + 1 > q->unk_00[p->unk_02].unk_00 && p->unk_02 + 1 >= q->unk_04) {
        return 1;
    }

    return 0;
}

u16 func_080DDEA0(UnkStruct_080DDDDC* p) {
    return p->unk_02;
}

void func_080DDEA4(s32 a) {
    func_080D2C78(a);
}

void func_080DDEB0(s32 a) {
    func_080D2DB0(a);
}

void func_080DDEBC(s32 a) {
    func_080D2DC4(a);
}

void func_080DDEC8(u8* p, u8 a) {
    if (p[5] != a) {
        p[5] = a;

        if (a != 0) {
            func_0805FCB0(80, 68, 2, gUnk_0984B74C);
        } else {
            func_0805FCB0(80, 68, 2, gUnk_0984B754);
        }
    }
}

INCLUDE_ASM("bos4/func_080DDF04.s");
INCLUDE_ASM("bos4/func_080DE910.s");

void func_080DEB94(void) {
    func_080609A0();
    EwramFree(gUnk_02034F14);
}

u8 func_080DEBAC(u8 a) {
    switch (a) {
    case 0:
        a = 1;
        break;
    case 1:
        a = 0;
        break;
    case 2:
        a = 3;
        break;
    case 3:
        a = 2;
        break;
    }

    return a;
}

void func_080DEBD8(UnkStruct_080DEDD8* p) {
    UnkStruct_080DEE18* e;

    if (p->unk_00 == 1 || p->unk_00 == 4) {
        e = func_080DEE18(p->unk_02);
        e->unk_0A = 0;
        e->unk_08 = 26;
        e->unk_09 = 0;
        e->unk_00 |= 8;
    }
}

void func_080DEC00(void) {
    if (gUnk_02039BB0.unk_008 & 8) {
        switch ((s8)gUnk_02039BB0.unk_00E) {
        case 1:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            gUnk_0203C590.unk_07 = 5;
            break;
        }
    } else {
        if ((s8)gUnk_02039BB0.unk_00E != 12) {
            gUnk_0203C590.unk_07 = 5;
        }
    }
}

INCLUDE_ASM("bos4/func_080DEC44.s");

UnkStruct_0984C868* func_080DED64(u8 a) {
    if (gUnk_02039BB0.unk_008 & 8) {
        return &gUnk_0984CBD0[a];
    }

    return &gUnk_0984C868[a];
}

u8* func_080DED98(u8 a) {
    if (gUnk_02039BB0.unk_008 & 8) {
        return gUnk_0984CBD0[(s8)gUnk_02039BB0.unk_00E].unk_04 + a * 4;
    }

    return gUnk_0984C868[(s8)gUnk_02039BB0.unk_00E].unk_04 + a * 4;
}

UnkStruct_080DEDD8* func_080DEDD8(u8 a) {
    if (gUnk_02039BB0.unk_008 & 8) {
        return gUnk_0984CBD0[(s8)gUnk_02039BB0.unk_00E].unk_08 + a;
    }

    return gUnk_0984C868[(s8)gUnk_02039BB0.unk_00E].unk_08 + a;
}

UnkStruct_080DEE18* func_080DEE18(u8 index) {
    return &gUnk_0203C5AC[index];
}

u8 func_080DEE28(u8 a, u8 b) {
    return func_080DED98(a)[b];
}

INCLUDE_ASM("bos4/func_080DEE44.s");
INCLUDE_ASM("bos4/func_080DEF20.s");
INCLUDE_ASM("bos4/func_080DF048.s");
INCLUDE_ASM("bos4/func_080DF244.s");
INCLUDE_ASM("bos4/func_080DF380.s");

void func_080DF480(void) {
    gUnk_0203C590.unk_00++;
    func_080DF730(0xFD, 5);
}

u8 func_080DF49C(void) {
    u8* e = func_080E54B8(gUnk_0203C590.unk_05);
    UnkStruct_02034F7C* t = &gUnk_0984CECC[func_080DEDD8(*e)->unk_01];
    UnkStruct_02034F80* q;

    t += *e;
    q = t->unk_04;

    while (q->unk_00 == 0xFF) {
        q++;
    }

    return q->unk_00;
}

u8 func_080DF4D8(void) {
    if (func_080E8C84(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10) != 0) {
        return *func_080E8D1C(0);
    }

    return 0xFF;
}

u8 func_080DF500(void) {
    return func_080E8C84(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
}

u8 func_080DF51C(u8 a) {
    UnkStruct_080DEDD8* p = func_080DEDD8(0);

    while (p->unk_00 != 5) {
        if (p->unk_02 == a) {
            return p->unk_00;
        }

        p++;
    }

    return 0;
}

u8 func_080DF548(u8 a) {
    u8* p;
    u8* q;

    if (gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }

    p = (u8*)&gUnk_0203C590;
    q = p + a * 0x10;

    return q[0x26];
}

void func_080DF570(u8 a) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    UnkStruct_080DEDD8* p = func_080DEDD8(0);

    while (p->unk_00 != 5) {
        if (p->unk_02 == a) {
            if (p->unk_00 == 2) {
                e->unk_0A = 0;
                e->unk_08 = 27;
                e->unk_09 = 22;
                return;
            }

            gUnk_0203C590.unk_02 |= 8;
            e->unk_0A = 0;
            e->unk_08 = 26;
            e->unk_09 = 0;
        }

        p++;
    }

    if (func_080DED64(gUnk_02039BB0.unk_00E)->unk_01 != a) {
        e->unk_0A = 0;
        e->unk_08 = 26;
        e->unk_09 = 0;
        return;
    }

    e->unk_0A = 0;
    e->unk_08 = 5;
    e->unk_09 = 23;
}

u8 func_080DF5F4(void) {
    if ((gUnk_02039BB0.unk_008 & 8) == 0) {
        return GetRandom() % 21 + 1;
    }

    return gUnk_09EF69EE[GetRandom() % 13];
}

INCLUDE_ASM("bos4/func_080DF640.s");

void func_080DF6D0(UnkStruct_0203C7AC* p, u8 a) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    const u8* row;
    u16 t;

    t = e->unk_00 | 2;
    e->unk_00 = t;
    SeedRandom(e->unk_04);
    gUnk_0203C7AC->unk_0C = e->unk_08;
    gUnk_0203C7AC->unk_0D = e->unk_09;

    if (gUnk_0203C584 == 0) {
        row = gUnk_0984D134[e->unk_09];
        gUnk_02039BB0.unk_1B8 = row[5];
        func_080E5510(row[0]);
    }
}

void func_080DF730(u8 a, u8 b) {
    gUnk_0203C590.unk_06 = a;
    gUnk_0203C590.unk_07 = func_080DEBAC(b);
    func_080DEC44();
}

INCLUDE_ASM("bos4/func_080DF750.s");

#ifndef VERSION_EU
u32 func_080DF804(u8 index) {
    return gUnk_09EF69FC[index];
}
#else
INCLUDE_ASM("bos4/func_080DF804.s");
#endif

void func_080DF814(void) {
    func_080DF730(0xFE, 1);
    func_080E04EC();
}

INCLUDE_ASM("bos4/func_080DF828.s");
INCLUDE_ASM("bos4/func_080DF8C0.s");

void func_080DF964(void) {
    s32 i;

    for (i = 0; i < gUnk_0203C590.unk_05; i++) {
        func_080DEBD8(func_080DEDD8(*func_080E54B8(i)));
    }
}

void func_080DF990(u8 a) {
    gUnk_02039BB0.unk_00E = a;
    func_080DF8C0(0xFE, 0);
}

void func_080DF9A8(void) {
    gUnk_02039BB0.unk_00E++;
    func_080DF8C0(0xFE, 1);
}

void func_080DF9C4(void) {
    gUnk_02039BB0.unk_00E--;
    func_080DF8C0(0xFD, 0);
}

void func_080DF9E0(u8 a) {
    u16 t;

    func_0801CB00();
    func_080DFAA8();
    func_080DF990(a);
    gUnk_0203C590.unk_06 = 0xFE;
    gUnk_0203C590.unk_07 = 5;
    t = gUnk_0203C590.unk_02 | 0x80;
    gUnk_0203C590.unk_02 = t;
    func_080E04EC();
}

void func_080DFA18(u8 a) {
    gUnk_0203C590.unk_04 = a;
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.unk_00E].unk_02 = a;
}

void func_080DFA3C(void) {
    UnkStruct_0984C868* e = func_080DED64(gUnk_02039BB0.unk_00E);
    UnkStruct_080DEE18* p;
    u16 t;

    if ((s8)gUnk_02039BB0.unk_00E == 13) {
        gUnk_02039BB0.unk_00E = 0;
    }

    if (gUnk_0203C590.unk_06 == 0xFD) {
        func_080DF730(e->unk_01, 1);
    } else {
        func_080DF730(e->unk_00, 0);
    }

    func_080DF964();

    if ((gUnk_0203C590.unk_02 & 0x20) == 0) {
        p = func_080DEE18(e->unk_01);
        t = p->unk_00 | 4;
        p->unk_00 = t;
    }

    func_080DF640(gUnk_0203C590.unk_06, 0);
}

void func_080DFAA8(void) {
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.unk_00E].unk_00 = gUnk_0203C590.unk_02;
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.unk_00E].unk_02 = gUnk_0203C590.unk_04;
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.unk_00E].unk_03 = gUnk_0203C590.unk_05;
}

void func_080DFAF4(u8 a, u8 b) {
    func_080DF990(a);
    func_080DFA18(b);

    if (a == 0) {
        gUnk_0203C590.unk_00 = 0;
        gUnk_0203C590.unk_02 &= 0xFEFF;
    }
}

void func_080DFB2C(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        gUnk_02039BB0.unk_184[i].unk_00 = 0;
        gUnk_02039BB0.unk_184[i].unk_02 = 0;
        gUnk_02039BB0.unk_184[i].unk_03 = 0;
    }

    gUnk_0203C590.unk_00 = 0;

    if ((gUnk_02039BB0.unk_008 & 8) == 0) {
        func_08085C3C();
    }

    func_080DF990(0);
}

s32 func_080DFB7C(u8 a) {
    return func_080E5590(a);
}

UnkStruct_080DFB8C* func_080DFB8C(s32 x, s32 y) {
    s16 a = x / 0x2000;
    s16 b = y / 0x1000;

    if (gUnk_0203C7AC->unk_00 < 0) {
        return func_080E58F8(a, b);
    }

    return func_080E548C(a, b);
}

u8 func_080DFBDC(UnkStruct_080DFF1C* p) {
    s32 y = p->unk_04 + p->unk_0C;
    UnkStruct_080DFB8C* q = func_080DFB8C(p->unk_00, y);

    if (q == 0) {
        return 1;
    }

    if (q->unk_08 >= p->unk_08 && q->unk_0C != 0x100000) {
        return 0;
    }

    return func_080E86C8(q, p->unk_00, y);
}

u8 func_080DFC24(void) {
    if (gUnk_0203C7AC->unk_00 & 0x100) {
        if (gUnk_0203C590.unk_04 != 0) {
            return 2;
        }

        if ((gUnk_02039BB0.unk_008 & 8) == 0 && (s8)gUnk_02039BB0.unk_00E == 12) {
            func_080DFA18(12);
            return 2;
        }

        return 1;
    }

    return 0;
}

void func_080DFC7C(void) {
    gUnk_0203C7AC->unk_00 &= ~0x100;
}

u8 func_080DFC94(UnkStruct_080DFF1C* p, s32 x, s32 y) {
    s32 old;

    if (func_080DFBDC(p) != 0) {
        p->unk_00 = x;
        p->unk_04 = y;
        return 1;
    }

    old = p->unk_0C;
    p->unk_0C = func_080DFF1C(p);

    if (old != p->unk_0C) {
        if (func_080DFBDC(p) != 0) {
            p->unk_00 = x;
            p->unk_04 = y;
            p->unk_0C = old;
            return 1;
        }
    }

    return 0;
}

INCLUDE_ASM("bos4/func_080DFCDC.s");
INCLUDE_ASM("bos4/func_080DFD84.s");

u8 _080DFE1C(UnkStruct_080DFF1C* p) {
    UnkStruct_080DFB8C* q = func_080DFB8C(p->unk_00, p->unk_04 + p->unk_0C);

    if (q->unk_00 & 0x20) {
        switch (q->unk_02) {
        case 3:
        case 4:
        case 8:
            return 2;
        case 5:
        case 6:
        case 9:
            return 1;
        case 7:
            return 0;
        }
    }

    return 0;
}

s32 func_080DFE7C(s32 x, s32 y, s32 z) {
    UnkStruct_080DFB8C* p;
    s32 r;

    y += z;
    p = func_080DFB8C(x, y);

    if (p == 0) {
        return 0;
    }

    if (p->unk_02 == 4 || p->unk_02 == 6) {
        if (func_080E86C8(p, x, y) != 0) {
            r = p->unk_0C;
        } else {
            r = p->unk_08;
        }
    } else {
        r = p->unk_0C;
    }

    return r;
}
