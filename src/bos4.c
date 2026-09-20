#include "map_index_assets.h"
#include "boss_map_block_assets.h"
#include "registration_data.h"
#include "map_api.h"
#include "msg_api.h"
#include "m4a_song.h"
#include "monsgage.h"
#include "bos4.h"
#include "bos4_api.h"

void task_bos_boogie_saku_2(BoogieSakuWork* work);
u8 task_bos_ursula_1(UrsulaWork* work);

const char gTaskNameBosBoogieDice[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieDice"), aligned(1))) = "task_bos_boogie_dice";

TaskDesc gTaskDescBosBoogieDice = {
    gTaskNameBosBoogieDice,
    (void (*)(void*, void*))task_bos_boogie_dice_0,
    task_bos_boogie_dice_1,
    (void (*)(void*))task_bos_boogie_dice_2,
    (void (*)(void*))task_bos_boogie_dice_3,
    0x174,
};

const char gTaskNameBosBoogieExplosiondice[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieExplosiondice"), aligned(1))) = "task_bos_boogie_explosiondice";

TaskDesc gTaskDescBosBoogieExplosiondice = {
    gTaskNameBosBoogieExplosiondice,
    (void (*)(void*, void*))task_bos_boogie_explosiondice_0,
    task_bos_boogie_explosiondice_1,
    (void (*)(void*))task_bos_boogie_explosiondice_2,
    (void (*)(void*))task_bos_boogie_explosiondice_3,
    0x160,
};

const char gTaskNameBosBoogieSaku[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieSaku"), aligned(1))) = "task_bos_boogie_saku";

TaskDesc gTaskDescBosBoogieSaku = {
    gTaskNameBosBoogieSaku,
    (void (*)(void*, void*))task_bos_boogie_saku_0,
    task_bos_boogie_saku_1,
    (void (*)(void*))task_bos_boogie_saku_2,
    (void (*)(void*))task_bos_boogie_saku_3,
    0x44,
};

const char gTaskNameBosBoogieMap[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieMap"), aligned(1))) = "task_bos_boogie_map";

TaskDesc gTaskDescBosBoogieMap = {
    gTaskNameBosBoogieMap,
    (void (*)(void*, void*))task_bos_boogie_map_0,
    task_bos_boogie_map_1,
    0,
    0,
    0x4,
};

const char gTaskNameBosBoogieMapanime[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieMapanime"), aligned(1))) = "task_bos_boogie_mapanime";

TaskDesc gTaskDescBosBoogieMapanime = {
    gTaskNameBosBoogieMapanime,
    (void (*)(void*, void*))task_bos_boogie_mapanime_0,
    task_bos_boogie_mapanime_1,
    (void (*)(void*))task_bos_boogie_mapanime_2,
    (void (*)(void*))task_bos_boogie_mapanime_3,
    0x24,
};

const char gTaskNameBosBoogieDisk[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieDisk"), aligned(1))) = "task_bos_boogie_disk";

TaskDesc gTaskDescBosBoogieDisk = {
    gTaskNameBosBoogieDisk,
    (void (*)(void*, void*))task_bos_boogie_disk_0,
    task_bos_boogie_disk_1,
    (void (*)(void*))task_bos_boogie_disk_2,
    (void (*)(void*))task_bos_boogie_disk_3,
    0x160,
};

const char gTaskNameBosBoogieKnife[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieKnife"), aligned(1))) = "task_bos_boogie_knife";

TaskDesc gTaskDescBosBoogieKnife = {
    gTaskNameBosBoogieKnife,
    (void (*)(void*, void*))task_bos_boogie_knife_0,
    task_bos_boogie_knife_1,
    (void (*)(void*))task_bos_boogie_knife_2,
    (void (*)(void*))task_bos_boogie_knife_3,
    0x158,
};

const char gTaskNameBosBoogieKnifereader[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieKnifereader"), aligned(1))) = "task_bos_boogie_knifereader";

TaskDesc gTaskDescBosBoogieKnifereader = {
    gTaskNameBosBoogieKnifereader,
    (void (*)(void*, void*))task_bos_boogie_knifereader_0,
    task_bos_boogie_knifereader_1,
    (void (*)(void*))task_bos_boogie_knifereader_2,
    (void (*)(void*))task_bos_boogie_knifereader_3,
    0x140,
};

const char gTaskNameBosBoogieKaihuku[] __attribute__((section(".rodata_registration_name_gTaskDescBosBoogieKaihuku"), aligned(1))) = "task_bos_boogie_kaihuku";

TaskDesc gTaskDescBosBoogieKaihuku = {
    gTaskNameBosBoogieKaihuku,
    (void (*)(void*, void*))task_bos_boogie_kaihuku_0,
    task_bos_boogie_kaihuku_1,
    (void (*)(void*))task_bos_boogie_kaihuku_2,
    (void (*)(void*))task_bos_boogie_kaihuku_3,
    0x158,
};

const u16* gUnk_09EF5100[12] = {
#if defined(VERSION_US)
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_09845798,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
#elif defined(VERSION_JP)
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_097FAC6C,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
#elif defined(VERSION_EU)
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_09819E40,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
#endif
};

const u16* gUnk_09EF5130[12] = {
#if defined(VERSION_US)
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_09845F98,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
#elif defined(VERSION_JP)
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_097FB46C,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
#elif defined(VERSION_EU)
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_0981A640,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
#endif
};

const u16* gUnk_09EF5160[12] = {
#if defined(VERSION_US)
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_09846798,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
#elif defined(VERSION_JP)
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_097FBC6C,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
#elif defined(VERSION_EU)
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_0981AE40,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
#endif
};

const u16* gUnk_09EF5190[12] = {
#if defined(VERSION_US)
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_09846F98,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_08125E24,
#elif defined(VERSION_JP)
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_097FC46C,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_08125EA0,
#elif defined(VERSION_EU)
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_0981B640,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_08124944,
#endif
};

const char gTaskNameBosUrsula[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsula"), aligned(1))) = "task_bos_ursula";

TaskDesc gTaskDescBosUrsula = {
    gTaskNameBosUrsula,
    (void (*)(void*, void*))task_bos_ursula_0,
    task_bos_ursula_1,
    (void (*)(void*))task_bos_ursula_2,
    (void (*)(void*))task_bos_ursula_3,
    0x164,
};

const char gTaskNameBosUrsulaMap[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaMap"), aligned(1))) = "task_bos_ursula_map";

TaskDesc gTaskDescBosUrsulaMap = {
    gTaskNameBosUrsulaMap,
    (void (*)(void*, void*))task_bos_ursula_map_0,
    task_bos_ursula_map_1,
    0,
    (void (*)(void*))task_bos_ursula_map_3,
    0xC,
};

const char gTaskNameBosUrsulaBorder[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaBorder"), aligned(1))) = "task_bos_ursula_border";

TaskDesc gTaskDescBosUrsulaBorder = {
    gTaskNameBosUrsulaBorder,
    (void (*)(void*, void*))task_bos_ursula_border_0,
    task_bos_ursula_border_1,
    (void (*)(void*))task_bos_ursula_border_2,
    (void (*)(void*))task_bos_ursula_border_3,
    0x8,
};

const char gTaskNameBosUrsulaTako[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaTako"), aligned(1))) = "task_bos_ursula_tako";

TaskDesc gTaskDescBosUrsulaTako = {
    gTaskNameBosUrsulaTako,
    (void (*)(void*, void*))task_bos_ursula_tako_0,
    task_bos_ursula_tako_1,
    (void (*)(void*))task_bos_ursula_tako_2,
    (void (*)(void*))task_bos_ursula_tako_3,
    0x204,
};

const char gTaskNameBosUrsulaBacktako[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaBacktako"), aligned(1))) = "task_bos_ursula_backtako";

TaskDesc gTaskDescBosUrsulaBacktako = {
    gTaskNameBosUrsulaBacktako,
    (void (*)(void*, void*))task_bos_ursula_backtako_0,
    task_bos_ursula_backtako_1,
    (void (*)(void*))task_bos_ursula_backtako_2,
    (void (*)(void*))task_bos_ursula_backtako_3,
    0x44,
};

const char gTaskNameBosUrsulaMapanime[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaMapanime"), aligned(1))) = "task_bos_ursula_mapanime";

TaskDesc gTaskDescBosUrsulaMapanime = {
    gTaskNameBosUrsulaMapanime,
    (void (*)(void*, void*))task_bos_ursula_mapanime_0,
    task_bos_ursula_mapanime_1,
    (void (*)(void*))task_bos_ursula_mapanime_2,
    (void (*)(void*))task_bos_ursula_mapanime_3,
    0x2C,
};

const char gTaskNameBosUrsulaBubble[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaBubble"), aligned(1))) = "task_bos_ursula_bubble";

TaskDesc gTaskDescBosUrsulaBubble = {
    gTaskNameBosUrsulaBubble,
    (void (*)(void*, void*))task_bos_ursula_bubble_0,
    task_bos_ursula_bubble_1,
    (void (*)(void*))task_bos_ursula_bubble_2,
    (void (*)(void*))task_bos_ursula_bubble_3,
#ifdef VERSION_EU
    0x5C,
#else
    0x44,
#endif
};

const char gTaskNameBosUrsulaBubbleSingle[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaBubbleSingle"), aligned(1))) = "task_bos_ursula_bubble_single";

TaskDesc gTaskDescBosUrsulaBubbleSingle = {
    gTaskNameBosUrsulaBubbleSingle,
    (void (*)(void*, void*))task_bos_ursula_bubble_single_0,
    task_bos_ursula_bubble_single_1,
    (void (*)(void*))task_bos_ursula_bubble_single_2,
    (void (*)(void*))task_bos_ursula_bubble_single_3,
#ifdef VERSION_EU
    0x130,
#else
    0x148,
#endif
};

const char gTaskNameBosUrsulaThunder[] __attribute__((section(".rodata_registration_name_gTaskDescBosUrsulaThunder"), aligned(1))) = "task_bos_ursula_thunder";

TaskDesc gTaskDescBosUrsulaThunder = {
    gTaskNameBosUrsulaThunder,
    (void (*)(void*, void*))task_bos_ursula_thunder_0,
    task_bos_ursula_thunder_1,
    (void (*)(void*))task_bos_ursula_thunder_2,
    (void (*)(void*))task_bos_ursula_thunder_3,
    0x10,
};

void* gUrsulaWork;
#ifdef VERSION_EU
extern u16 eu_080DA830(void);
extern void eu_080DA80C(u16 a, u16 b);
extern u8 eu_080DA848(void);
extern void* eu_080DA860(void);
#endif

UrsulaMapanimeWork* gUrsulaMapanimeWork;
#ifdef VERSION_EU
u32 gUnkEu_02035104;
#endif

u8 func_080D9AC4(s32* a, s32* b, s16 c, u16 d) {
    u8 r;

    r = 0;

    if (*a < (128 - c) << 8) {
        *a = (128 - c) << 8;
        r = 1;
    }

    if (*a > (c + 368) << 8) {
        *a = (c + 368) << 8;
        r = 1;
    }

    if (*b < (576 - (s16)d) << 8) {
        *b = (576 - (s16)d) << 8;
        r = 1;
    }

    if (*b > ((s16)d + 632) << 8) {
        *b = ((s16)d + 632) << 8;
        r = 1;
    }
    return r;
}

u8 func_080D9B28(BoogieDiceWork* work) {
    if (work->unk_000 == 3) {
        if (work->unk_16C->unk_000 == 9) {
            if (AnimGetFrame(&work->unk_16C->anim) <= 2) {
                if (!AnimIsFinished(&work->unk_16C->anim)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void func_080D9B6C(BoogieDiceWork* work) {
    if (work->unk_160 <= 255) {
        work->unk_160 += 8;
    }

    if (work->unk_15C <= 255) {
        work->unk_15C += 8;
    }
}

void task_bos_boogie_dice_0(BoogieDiceWork* work, u8* arg) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)(arg + 0x40);
    s32 c;
    s32 d;
    s32 e;
    u16 r;

    work->unk_170 = arg[0x175];
    work->unk_16C = (BoogieWork*)arg;
    work->unk_000 = 10;
    work->unk_004 = 0;
    work->unk_150 = -0x4CC;
    work->unk_154 = GetRandom() % 437 + 0x4C;
    work->unk_158 = GetRandom() % 0x78 + 0x44;
    work->unk_160 = 0x33;
    work->unk_15C = 0x33;
    work->y = 0;
    work->unk_168 = 0;
    gUnk_0203C564 = 0;
    c = p->x;
    d = 0x24000;
    e = p->z - 0x3800;
    func_0801B37C(&work->unk_040, &gUnk_096FDF54, c, d, e);
    ColliderInit(&work->unk_080, 3, gUnk_096FDF54.unk_08, gUnk_096FDF54.unk_06);
    work->unk_074 |= 0x400;
#ifdef VERSION_EU
    work->unk_074 |= 0x100;
#else
    work->unk_074 |= 0x80;
#endif
    work->tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF6788, 4), gUnk_09796EAA);
    work->palette = (u32)LoadObjPalette(gUnk_0984AF98, 32);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->anim, gUnk_09EF6798, gUnk_09EF6788);
    AnimStart(&work->anim, 0, 1);
    r = GetRandom();
    AnimSetFrame(&work->anim, r & 3);
    TaskPoolInit(&work->unk_02C, 1);
    TaskCreate(&work->unk_02C, &gTaskDescBosShadow, &work->unk_040);

    if (work->unk_170 == 0) {
        func_0801BCD4(&work->unk_040);
    }
}
u8 task_bos_boogie_dice_1(BoogieDiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    if (work->unk_170 == 0) {
        switch (func_0801ADAC(p)) {
        case 5:
            work->unk_000 = 3;
            work->unk_004 = 0;
            break;
        case 4:
            work->unk_000 = 0;
            work->unk_004 = 0;
            gUnk_0203C554 += 180;
            break;
        case 2:
        default:
            if (func_0801C1C0(0) != 0) {
                func_080D9A58();

                if (work->unk_000 == 3) {
                    work->unk_000 = 0;
                    work->unk_004 = 0;
                }
            }

            break;
        case 1:
        case 3:
        case 6:
        case 7:
        case 8:
            work->unk_000 = 2;
            work->unk_004 = 0;
            break;
        }
    } else {
        switch (func_080D9A90()) {
        case 3:
            if (work->unk_000 != 3) {
                work->unk_000 = 3;
                work->unk_004 = 0;
            }

            break;
        case 0:
            if (work->unk_000 != 0) {
                work->unk_000 = 0;
                work->unk_004 = 0;
            }

            break;
        case 1:
            if (work->unk_000 == 3) {
                work->unk_000 = 0;
                work->unk_004 = 0;
            }

            break;
        }

        switch ((u32)func_0801ADAC(p)) {
        case 1:
        case 3:
        case 6:
        case 7:
        case 8:
            work->unk_000 = 2;
            work->unk_004 = 0;
            break;
        }
    }

    switch (work->unk_000) {
    case 3:
        if (func_080D9B28(work) != 0) {
            return 1;
        }

#ifdef VERSION_EU
        ((BtlObj*)p)->unk_034 &= ~0x100;
#else
        ((BtlObj*)p)->unk_034 &= ~0x80;
#endif
        func_080D9B6C(work);
        work->unk_150 += 51;
        p->z += work->unk_150;
        p->x += gSineTable[work->unk_158] * work->unk_154 >> 8;
        p->y += -gSineTable[work->unk_158 + 0x40] * work->unk_154 >> 8;

        if (*((u8*)p + 0x6C) != 0 && work->unk_160 > 255 && work->unk_15C > 255) {
            work->unk_154 = work->unk_154 * 230 >> 8;
            p->x += *(s32*)((u8*)p + 0x78);
            p->y += *(s32*)((u8*)p + 0x7C);
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (func_080D9AC4(&p->x, &p->y, 0, 0) != 0) {
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (p->z > 0) {
            p->z = 0;
            work->unk_150 = -(work->unk_150 * 179 >> 8);
            work->unk_154 = work->unk_154 * 212 >> 8;

            if (work->unk_150 >= -25) {
                func_080DA42C(work);
                work->unk_000 = 4;
                ((BtlObj*)p)->unk_034 |= 0x100;

                if (work->unk_170 == 0) {
                    func_0801AF08(p);
                }
            }
        }

        break;
    case 0:
#ifdef VERSION_EU
        ((BtlObj*)p)->unk_034 &= ~0x100;
#else
        ((BtlObj*)p)->unk_034 &= ~0x80;
#endif

        if ((s16)work->unk_004 == 0 && work->unk_170 == 0) {
            func_0801AF08(p);
            gUnk_0203C560++;
            work->unk_168 = 1;
        }

        work->unk_004++;
        func_080D9B6C(work);

        if (*((u8*)p + 0x6C) != 0 && work->unk_160 > 255 && work->unk_15C > 255) {
            work->unk_154 = work->unk_154 * 230 >> 8;
            p->x += *(s32*)((u8*)p + 0x78);
            p->y += *(s32*)((u8*)p + 0x7C);
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        work->unk_150 += 51;
        p->z += work->unk_150;

        if (p->z > 0) {
            p->z = 0;
            work->unk_150 = -(work->unk_150 * 128 >> 8);
            work->unk_004 = 0;
            work->unk_000 = 1;
        }

        break;
    case 1:
        if ((s16)work->unk_004 > 59) {
            work->unk_000 = 6;
            break;
        }

        work->unk_004++;
        work->unk_150 += 51;
        p->x += gSineTable[work->unk_158] * work->unk_154 >> 8;
        p->y += -gSineTable[work->unk_158 + 0x40] * work->unk_154 >> 8;

        if (*((u8*)p + 0x6C) != 0 && work->unk_160 > 255 && work->unk_15C > 255) {
            work->unk_154 = work->unk_154 * 230 >> 8;
            p->x += *(s32*)((u8*)p + 0x78);
            p->y += *(s32*)((u8*)p + 0x7C);
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (func_080D9AC4(&p->x, &p->y, 0, 0) != 0) {
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (p->z > 0) {
            p->z = 0;
            work->unk_150 = -(work->unk_150 * 179 >> 8);
        }

        break;
    case 2:
        if (work->unk_170 == 0 && gUnk_0203C568 == 0 && GetRandom() % 16 <= 7) {
            gUnk_0203C568 = 1;
            _0801C1F8(0, p->x, p->y, p->z);
        }

        func_0801C2DC(p, 1);

        return 0;
    case 4:
        if (AnimIsFinished(&work->anim) != 0) {
            work->unk_000 = 5;
            work->unk_004 = 0;
        }

        break;
    case 5:
        if ((s16)work->unk_004 > 20) {
            work->unk_000 = 6;
            break;
        }

        work->unk_004++;
        break;
    case 6:
        func_0801C2DC(p, 1);
        work->unk_160 -= 12;
        work->y += 96;

        if (work->unk_160 <= 127) {
            work->unk_000 = 7;
            work->unk_150 = -0x4CC;
            work->unk_004 = 0;
        }

        break;
    case 7:
        if ((s16)work->unk_004 > 10) {
            work->unk_000 = 8;
            work->unk_004 = 0;
            break;
        }

        work->unk_004++;
        break;
    case 8:
        work->unk_150 += 51;
        p->z += work->unk_150;
        work->unk_160 += 25;
        work->y -= 200;

        if (work->unk_160 > 255) {
            work->unk_000 = 9;
            work->unk_004 = 0;
        } else if (work->unk_160 <= 178) {
            break;
        }
    case 9:
        work->unk_15C -= 38;

        if (work->unk_15C <= 24) {
            func_08013F5C(p->x, p->y + p->z, 0x100, 8, 16);

            return 0;
        }

        break;
    case 10:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    }

    AnimUpdate(&work->anim);

    if (work->unk_000 == 1) {
        AnimUpdate(&work->anim);
    }

    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}

void task_bos_boogie_dice_2(BoogieDiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    s16 x;
    s16 y;
    u16 c;
    void* pal;
    s32 aff;
    s32 a;
    s32 b;

    if (func_080D9B28(work) != 0) {
        return;
    }

    c = GetBattleSpritePriorityFlags(p->y);

    if (func_0801CA00(p) != 0) {
        pal = (void*)work->palette2;
    } else {
        pal = (void*)work->palette;
    }

    a = work->unk_15C;

    if (a > 0x100) {
        a = 0x100;
    }

    b = work->unk_160;

    if (b > 0x100) {
        b = 0x100;
    }

    aff = AllocObjAffine(0, a, b, 0);
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    DrawSprite(x, (work->y >> 8) + y, AnimGetGfx(&work->anim), (void*)work->tiles, pal,
        aff, c, -0x1004 - (p->y >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_dice_3(BoogieDiceWork* work) {
    if (work->unk_168 == 0 && gUnk_0203C560 != 3 && work->unk_170 == 0 && work->unk_000 != 10) {
        gUnk_0203C564 = 1;
    }

    ColliderUnregister(&work->unk_080);
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(&work->unk_02C);
}

void func_080DA42C(BoogieDiceWork* work) {
    void* tbl[6][3];
    u8 n;

    memcpy(tbl, gUnk_096FDF7C, 72);

    switch (GetRandom() % 4) {
    case 0:
        n = 5;
        break;
    case 1:
        n = 3;
        break;
    case 2:
        n = 0;
        break;
    default:
        switch (GetRandom() % 3) {
        case 0:
            n = 1;
            break;
        case 1:
            n = 2;
            break;
        default:
            n = 4;
            break;
        }
        break;
    }

    if (work->unk_170 == 0) {
        gUnk_0203C558 = n;
    }

    AnimChangeWithTables(&work->anim, 0, 0, tbl[n][0], tbl[n][1]);
    SetObjTileSource((void*)work->tiles, tbl[n][2]);
}

u8 func_080DA4DC(u8* p) {
    u8* q = *(u8**)(p + 0x15C);

    if (*(u32*)(q + 0x15C) == 3 && AnimGetFrame(q + 20) <= 2) {
        return 1;
    }

    return 0;
}

void task_bos_boogie_explosiondice_0(BoogieExplosiondiceWork* work, void* arg) {
    u8* p;

    work->unk_15C = (u32)arg;
    work->unk_000 = 0;
    work->unk_004 = 0;
    work->unk_150 = 0;
    work->unk_154 = GetRandom() % 437 + 76;
    work->unk_158 = GetRandom() % 128 + 0x40;
    p = (u8*)gBtlWork->actor;
    work->unk_044 = ((BtlObj*)p)->x;
    work->unk_048 = ((BtlObj*)p)->y;
    work->unk_04C = -0xA000;
    ColliderInit(&work->unk_080, 8, gUnk_096FDFC4.unk_08, gUnk_096FDFC4.unk_06);
    work->tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF6774, 4), gUnk_0979666A);
    work->palette = (u32)LoadObjPalette(gUnk_0984AF98, 32);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->anim, gUnk_09EF6784, gUnk_09EF6774);
    AnimStart(&work->anim, 0, 1);
    TaskPoolInit(&work->unk_02C, 1);
    TaskCreate(&work->unk_02C, &gTaskDescBosShadow, &work->unk_040);
}

u8 task_bos_boogie_explosiondice_1(BoogieExplosiondiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    if (func_080DA4DC((u8*)work) != 0) {
        return 1;
    }

    switch (work->unk_000) {
    case 0:
        work->unk_150 += 51;
        p->z += work->unk_150;

        if (p->z > -0x2000) {
            func_08014020(p->x, p->y + p->z, 0);
            return 0;
        }

        break;
    case 2:
        if (func_080128EC() == 0) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}

void task_bos_boogie_explosiondice_2(BoogieExplosiondiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    u8 f = func_080DA4DC((u8*)work);
    s16 x;
    s16 y;
    u16 c;
    void* pal;

    if (f != 0 || work->unk_000 == 1) {
        return;
    }

    c = GetBattleSpritePriorityFlags(p->y);
    pal = (void*)work->palette;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), (void*)work->tiles, pal, f, c,
        -0x1004 - (p->y >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_explosiondice_3(BoogieExplosiondiceWork* work) {
    ColliderUnregister(&work->unk_080);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(&work->unk_02C);
}

u8 func_080DA73C(void) {
    if (gBtlWork->actor->y <= 0x23EFF) {
        return 1;
    }

    return 0;
}

void task_bos_boogie_saku_0(BoogieSakuWork* work, void* arg) {
    work->unk_024 = (u32)arg;
    work->tiles = (u32)LoadObjTiles(gUnk_09799CBA, 0x2E0);
    work->palette = (u32)LoadObjPalette(gUnk_0984AF78, 32);
    AnimInit(&work->anim, gUnk_09EF680C, gUnk_09EF67FC);
    AnimStart(&work->anim, 0, 0);
    work->unk_020 = 0;
    TaskPoolInit(&work->unk_028, 1);
    work->unk_03C = 0;
    work->unk_040 = 0;
}

u8 task_bos_boogie_saku_1(BoogieSakuWork* work) {
    u8 f;

    if (gUnk_0203C560 > 2 && AnimIsFinished(&work->anim) != 0) {
        if (work->unk_020 < gUnk_0203C554) {
            if (work->unk_020 == 0) {
                func_0802F1E8();
            }

            work->unk_020++;
            SetBattleBounds(0x80, 0x170, 0x228, 0x278);

            if (func_080DA73C() != 0) {
                func_0801C2DC((u8*)work->unk_024 + 0x40, 0);
            } else {
                func_0801C2DC((u8*)work->unk_024 + 0x40, 1);
            }
        } else if (*(u32*)work->unk_024 != 4) {
            work->unk_040 = 1;
            gUnk_0203C560 = 0;
            work->unk_020 = 0;
            gUnk_0203C554 = 0;
            func_0801C2DC((u8*)work->unk_024 + 0x40, 1);

            if (func_080DA73C() != 0) {
                work->unk_03C = (u32)TaskCreate(&work->unk_028, &gTaskDescBosBoogieExplosiondice, (void*)work->unk_024);
            }
        }
    }

    if (gUnk_0203C560 <= 2 && IsTaskActive((void*)work->unk_03C) == 0) {
        SetBattleBounds(0x80, 0x170, 0x240, 0x278);

        if (gUnk_0203C560 != 0) {
            AnimChange(&work->anim, gUnk_0203C560, 0);
        } else if (work->unk_040 != 0) {
            AnimChange(&work->anim, 3, 0);
            work->unk_040 = 0;
        }
    }

    f = AnimIsFinished(&work->anim);

    if (gUnk_0203C560 > 2
            || (gUnk_0203C560 == 0 && AnimGetId(&work->anim) == 3
                && IsTaskActive((void*)work->unk_03C) == 0)) {
        AnimUpdate(&work->anim);
    }

    if (f == 0 && AnimIsFinished(&work->anim) != 0) {
        m4aSongNumStart(0x255);

        if (AnimGetId(&work->anim) == 3) {
            AnimChange(&work->anim, 0, 0);
        }
    }

    TaskPoolUpdate(&work->unk_028);

    return 1;
}

void func_080DA954(BoogieSakuWork* work, s32 a, u16 b) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, a, 0x23F00, -0x2000);
    DrawSprite(x, y + 1, AnimGetGfx(&work->anim), (void*)work->tiles, (void*)work->palette, 0, b, 0xE700);
    TaskPoolDraw(&work->unk_028);
}

void task_bos_boogie_saku_2(BoogieSakuWork* work) {
    u16 v = GetBattleSpritePriorityFlags(0x23F00);

    func_080DA954(work, 0xA800, v);
    func_080DA954(work, 0xF800, v);
    func_080DA954(work, 0x14800, v);
}

void task_bos_boogie_saku_3(BoogieSakuWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    TaskPoolDestroy(&work->unk_028);
}

void task_bos_boogie_map_0(void* work, BattleBackgroundDef* arg) {
    LoadBgTiles(0, arg->tiles, arg->tilesSize);
    LoadBgPalette(0, arg->palette, arg->paletteSize);
    SetBgMapBlocks(0, &arg->map, 2, 2);
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0xF800;
    gBtlWork->y = 0x21000;
    gBtlWork->unk_000 = 0xF800;
    gBtlWork->unk_004 = 0x21000;
    gBtlWork->x2 = 0xF800;
    gBtlWork->y2 = 0x21000;
    gBtlWork->unk_01C = 0xF800;
    gBtlWork->unk_020 = 0x21000;
    gBtlWork->unk_01A = 15;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    ScrollBgMapTo(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}

u8 task_bos_boogie_map_1(void) {
    s32 a;
    s32 b;

    func_0802F208();
    a = (gBtlWork->x2 - gBtlWork->x) >> 3;
    b = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (a > 0x500) {
        a = 0x500;
    } else if (a < -0x500) {
        a = -0x500;
    }

    gBtlWork->x += a;
    gBtlWork->y += b;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gBtlWork->unk_000 - 0x7800 < gBtlWork->unk_0DA * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x78) << 8;
    } else if (gBtlWork->unk_000 + 0x7800 > gBtlWork->unk_0DC * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x78) << 8;
    }

    if (gBtlWork->unk_004 - 0x5000 < 0x18C00) {
        gBtlWork->unk_004 = 0x1DC00;
    } else if (gBtlWork->unk_004 + 0x5000 > 0x27800) {
        gBtlWork->unk_004 = 0x22800;
    }

    gBtlWork->unk_004 += func_0802F268();
    ScrollBgMapTo(0, (gBtlWork->unk_000 >> 8) + 8, (gBtlWork->unk_004 >> 8) - 0x108);

    return 1;
}

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

u8 func_080DABFC(s32* x, s32* y, s16 w, s16 h, s32 z) {
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

UnkStruct_0203C590 gUnk_0203C590 __attribute__((common));

void task_bos_boogie_disk_0(BoogieDiskWork* work, BtlObj* arg) {
    s32 x;
    s32 v;
    s32 d;
    s32 e;

    work->unk_000 = 2;
    work->unk_004 = 0;
    work->unk_15C = 0;
    work->unk_150 = -0x200;

    if (gBtlWork->actor->x < 0xF800) {
        x = gBtlWork->actor->x + 0xF000;
        work->unk_154 = -0x266;
    } else {
        x = gBtlWork->actor->x - 0xF000;
        work->unk_154 = 0x266;
    }

    work->unk_158 = 0x133;
    v = arg->unk_02E;

    if (arg->unk_02C < (s16)(v / 3)) {
        work->unk_154 *= 3;
        work->unk_158 *= 3;
    } else if (arg->unk_02C < v * 2 / 3) {
        work->unk_154 *= 2;
        work->unk_158 *= 2;
    }

    d = gBtlWork->actor->y;
    e = -0x1000;
    func_0801B37C(&work->unk_040, gUnk_096FE098, x, d, e);
    work->unk_074 |= 0x400;
    work->tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF6824, 8), gUnk_0979A426);
    work->palette = (u32)LoadObjPalette(gUnk_0984AFB8, 32);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->anim, gUnk_09EF6844, gUnk_09EF6824);
    AnimStart(&work->anim, 0, 1);
    TaskPoolInit(&work->unk_02C, 1);
    TaskCreate(&work->unk_02C, &gTaskDescBosShadow, &work->unk_040);
    func_0801BCD4(&work->unk_040);
    m4aSongNumStart(0x253);
}
u8 task_bos_boogie_disk_1(BoogieDiskWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    switch (func_0801ADAC(p)) {
    case 5:
        work->unk_000 = 0;
        work->unk_004 = 0;
        break;
    case 2:
    default:
        if (func_0801C1C0(0) == 0) {
            break;
        }

        func_080D9A58();
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        if (work->unk_000 != 1) {
            work->unk_000 = 1;
            work->unk_004 = 0;
        }

        break;
    }

    switch (work->unk_000) {
    case 0:
        p->y += work->unk_158;

        if (func_080DABFC(&p->x, &p->y, 0x20, -0x10, p->z) != 0) {
            work->unk_158 = -work->unk_158;
        }

        p->x += work->unk_154;

        if ((work->unk_154 > 0 && p->x > 0x19000)
                || (work->unk_154 <= 0 && p->x < 0x6000)) {
            func_0801AF08(p);

            return 0;
        }

        if (func_08011F78(0x105, p->x, p->y, p->z, 0x20, 0x10, 1) == 1) {
            gUnk_0203C56C = 1;
            m4aSongNumStart(0x22F);
        }

        break;
    case 1:
        if (p->z >= 0) {
            gUnk_0203C570 = 1;
            func_0801AF08(p);

            return 0;
        }

        work->unk_004++;
        p->x -= work->unk_154;
        work->unk_15C += 0x19;
        p->z += work->unk_150;
        work->unk_150 += 0x42;

        if (p->z > 0) {
            p->z = 0;
        }

        break;
    case 2:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}
void task_bos_boogie_disk_2(BoogieDiskWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    s16 x;
    s16 y;
    u16 c = GetBattleSpritePriorityFlags(p->y);
    void* pal = (void*)work->palette;
    u8* obj = AllocObjAffineAngle(work->unk_15C, 1);

    WorldToScreen(&x, &y, p->x, p->y, p->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), (void*)work->tiles, pal, (s32)obj, c,
        -0x1004 - (p->y >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_disk_3(BoogieDiskWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(&work->unk_02C);
}

void func_080DB04C(BoogieKnifeWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_02C;
    s32 dy;

    if (gUnk_0203C578 != 0) {
        work->unk_148 = 0x100;
        work->unk_14C = 0;
        dy = 0x2000;
    } else {
        work->unk_148 = -0x100;
        work->unk_14C = 0;
        dy = -0x2000;
    }

    if (func_08011F78(0x106, p->x - dy, p->y, p->z - 0x1000, 4, 0x1C, 0x10) == 1) {
        gUnk_0203C56C = 1;
        m4aSongNumStart(0x226);
    }
}
void task_bos_boogie_knife_0(BoogieKnifeWork* work, u32* arg) {
    BtlObj* p;
    s32 v;

    work->unk_000 = 0;
    work->unk_004 = 0;

    if (gUnk_0203C578 != 0) {
        work->unk_140 = 0x133;
    } else {
        work->unk_140 = -0x133;
    }

    work->unk_13C = 0;
    work->unk_150 = 0x42;
    work->unk_154 = -0x500;
    p = gUnk_0203C55C;
    v = p->unk_02E;

    if (p->unk_02C < (s16)(v / 3)) {
        work->unk_150 = (work->unk_150 * 0x300) >> 8;
        work->unk_154 = -0xA00;
    } else if (p->unk_02C < v * 2 / 3) {
        work->unk_150 = (work->unk_150 * 0x200) >> 8;
        work->unk_154 = -0x780;
    }

    work->unk_034 = 0x25C00;
    work->unk_038 = -0xC000;
    work->unk_030 = *arg;
    ColliderInit(&work->unk_06C, 8, gUnk_096FE0C0.unk_08, gUnk_096FE0C0.unk_06);
    work->tiles = (u32)LoadObjTiles(gUnk_0979C44E, 0xC40);
    work->palette = (u32)LoadObjPalette(gUnk_0984AFD8, 32);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->anim, gUnk_09EF684C, gUnk_09EF6848);
    AnimStart(&work->anim, 0, 1);
}
u8 task_bos_boogie_knife_1(BoogieKnifeWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_02C;

    if (gUnk_0203C574 != 0) {
        work->unk_000 = 2;
    }

    switch (work->unk_000) {
    case 0:
        p->z += work->unk_13C;
        work->unk_13C += work->unk_150;

        if (p->z < 0) {
            func_080DB04C(work);
        } else {
            p->z = 0;
            work->unk_000 = 1;
            work->unk_13C = work->unk_154;
        }

        break;
    case 1:
        p->x += work->unk_140;
        p->z += work->unk_13C;
        work->unk_13C += work->unk_150;
        work->unk_004++;

        if (p->z < 0) {
            func_080DB04C(work);
        } else {
            p->z = 0;
            work->unk_13C = work->unk_154;

            if ((s16)work->unk_004 > 199.99999f) {
                work->unk_000 = 2;
            } else {
                func_080DB04C(work);
            }
        }

        break;
    case 2:
        p->z -= 0x800;

        if (p->z < -0xC000) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);

    return 1;
}
void task_bos_boogie_knife_2(BoogieKnifeWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_02C;
    s16 x;
    s16 y;
    u16 c;
    void* pal;
    s32 aff;

    WorldToScreen(&x, &y, p->x + work->unk_14C, p->y - 0x2400, p->z);

    if ((u16)(x + 0x20) > 0x130) {
        return;
    }

    c = GetBattleSpritePriorityFlags(p->y);

    if (gUnk_0203C574 != 0 && (gFrameCounter & 1) != 0 && gBtlWork->unk_070 == 0) {
        pal = (void*)work->palette2;
    } else {
        pal = (void*)work->palette;
    }

    aff = AllocObjAffine(0, work->unk_148, 0x100, 0);
    DrawSprite(x, y, AnimGetGfx(&work->anim), (void*)work->tiles, pal, aff, c,
        -0x1004 - (p->y >> 8) * 4);
}

void task_bos_boogie_knife_3(BoogieKnifeWork* work) {
    ColliderUnregister(&work->unk_06C);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
}

u8 func_080DB428(u8* p) {
    if ((s32)((BoogieKnifeWork*)p)->unk_038 >= 0) {
        return 1;
    }

    return 0;
}

u8 func_080DB438(BoogieKnifereaderWork* work) {
    s32 i;

    for (i = 0; i <= 4; i++) {
        if (IsTaskActive(work->unk_12C[i]) != 0) {
            return 1;
        }
    }

    return 0;
}

void func_080DB468(BoogieKnifereaderWork* work) {
    s32 i;
    s32 v;

    if (GetRandom() % 16 > 7) {
        gUnk_0203C578 = 1;
        v = -0x4000;

        for (i = 0; i <= 4; i++) {
            work->unk_12C[i] = TaskCreate(&work->unk_008, &gTaskDescBosBoogieKnife, &v);
            v += 0x6800;
        }
    } else {
        gUnk_0203C578 = 0;
        v = 0x23000;

        for (i = 0; i <= 4; i++) {
            work->unk_12C[i] = TaskCreate(&work->unk_008, &gTaskDescBosBoogieKnife, &v);
            v += -0x6800;
        }
    }
}

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

u8 task_bos_boogie_knifereader_1(BoogieKnifereaderWork* work) {
    s32 i;
    void* e = &work->unk_01C;
    void* pool;
    s32 checkKnives;

    switch (func_0801ADAC(e)) {
    case 5:
        work->unk_000 = 0;
        work->unk_004 = 0;
        break;
    case 2:
    default:
        if (func_0801C1C0(0) == 0) {
            break;
        }

        func_080D9A58();
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        if (work->unk_000 != 1) {
            work->unk_000 = 1;
            work->unk_004 = 0;
        }

        break;
    }

    switch (work->unk_000) {
    case 2:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        checkKnives = 0;
        break;
    case 1:
        gUnk_0203C574 = 1;
        checkKnives = 1;
        break;
    case 0:
        if ((s16)work->unk_004 == 0) {
            work->unk_004++;
            func_080DB468(work);
            checkKnives = 0;
            break;
        }
    default:
        checkKnives = 1;
        break;
    }

    if (checkKnives == 0) {
        pool = &work->unk_008;
        TaskPoolUpdate(pool);
        return 1;
    }

    if (func_080DB438(work) == 0) {
        func_0801AF08(e);

        return 0;
    }

    for (i = 0; i <= 4; i++) {
        pool = &work->unk_008;

        if (IsTaskActive(work->unk_12C[i]) != 0) {
            if (func_080DB428(((u8**)work->unk_12C[i])[1]) != 0) {
                m4aSongNumStart(0x254);
            }

            break;
        }
    }

    TaskPoolUpdate(pool);

    return 1;
}

void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work) {
    TaskPoolDraw(&work->unk_008);
}

void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work) {
    func_0801B7D8(&work->unk_01C);
    TaskPoolDestroy(&work->unk_008);
}

void task_bos_boogie_kaihuku_0(BoogieKaihukuWork* work, BoogieDiceWork* arg) {
    s32 c;
    s32 d;
    s32 e;

    work->unk_000 = 2;
    work->unk_004 = 0;
    work->unk_154 = (u32)arg;
    work->unk_150 = 0;
    c = arg->unk_044;
    d = arg->unk_048 + 0x100;
    e = arg->unk_04C - 0x7C00;
    func_0801B37C(&work->unk_040, gUnk_096FE114, c, d, e);
    work->unk_074 |= 0x400;
    work->tiles = (u32)LoadObjTiles(gUnk_09799FB0, 0x400);
    work->palette = (u32)LoadObjPalette(gUnk_0984AFB8, 32);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->anim, gUnk_09EF6820, gUnk_09EF681C);
    AnimStart(&work->anim, 0, 1);
    func_0801BCD4(&work->unk_040);
}
u8 task_bos_boogie_kaihuku_1(BoogieKaihukuWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    BoogieDiceWork* arg = (BoogieDiceWork*)work->unk_154;
    void* q = &arg->unk_040;

    switch (func_0801ADAC(p)) {
    case 5:
        work->unk_000 = 0;
        work->unk_004 = 0;
        break;
    case 2:
    default:
        if (func_0801C1C0(0) == 0) {
            break;
        }

        func_080D9A58();
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        if (work->unk_000 != 1) {
            work->unk_000 = 1;
            work->unk_004 = 0;
        }

        break;
    }

    switch (work->unk_000) {
    case 0:
        func_0802F274(p->x, p->y + p->z);

        if ((s16)work->unk_004 == 0) {
            func_08015228(p->x, p->y, p->z + 0x2800, 0x199);
            m4aSongNumStart(0x256);
            work->unk_004++;
            break;
        }

        if (func_080128EC() != 0) {
            break;
        }

        func_08019190(q, 10);
        arg = (BoogieDiceWork*)work->unk_154;
        arg->unk_06C += arg->unk_06E / 16;
        arg = (BoogieDiceWork*)work->unk_154;

        if ((s16)arg->unk_06C > arg->unk_06E) {
            arg->unk_06C = arg->unk_06E;
        }

        return 0;
    case 1:
        if (p->z >= 0) {
            gUnk_0203C570 = 1;
            func_0801AF08(p);

            return 0;
        }

        work->unk_004++;
        p->z += work->unk_150;
        work->unk_150 += 0x42;

        if (p->z < -0x2000) {
            p->z = 0;
        }

        break;
    case 2:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    }

    AnimUpdate(&work->anim);
    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);

    return 1;
}

void task_bos_boogie_kaihuku_2(BoogieKaihukuWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    void* d;
    u16 v;
    s16 x;
    s16 y;

    if (work->unk_000 != 2) {
        v = GetBattleSpritePriorityFlags(p->y);
        d = (void*)work->palette;
        WorldToScreen(&x, &y, p->x, p->y, p->z);
        DrawSprite(x, y, AnimGetGfx(&work->anim), (void*)work->tiles, d, 0, v, -0x1004 - (p->y >> 8) * 4);
    }
}

void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
}

void func_080DB978(UrsulaWork* work) {
    if (work->unk_000 >= 3 && work->unk_000 <= 4) {
        if (work->unk_028 > gBtlWork->actor->x) {
            if (work->unk_134 != (u32)gUnk_09EF5130) {
                work->unk_134 = (u32)gUnk_09EF5130;
                SetBgMapBlocks(0, gUnk_09EF5130, 4, 3);
            } else {
                func_080DD69C(0);
            }
        } else {
            if (work->unk_134 != (u32)gUnk_09EF5190) {
                work->unk_134 = (u32)gUnk_09EF5190;
                SetBgMapBlocks(0, gUnk_09EF5190, 4, 3);
            } else {
                func_080DD69C(0);
            }
        }
    } else if (func_080DC510() != 0) {
        if (work->unk_134 != (u32)gUnk_09EF5100) {
            work->unk_134 = (u32)gUnk_09EF5100;
            SetBgMapBlocks(0, gUnk_09EF5100, 4, 3);
        }
    } else {
        if (work->unk_134 != (u32)gUnk_09EF5160) {
            work->unk_134 = (u32)gUnk_09EF5160;
            SetBgMapBlocks(0, gUnk_09EF5160, 4, 3);
        }
    }
}

u8 func_080DBA14(UrsulaWork* work) {
    if (work->unk_142 == 0 && func_080DD1FC(*(void**)(work->unk_01C + 4)) == 0 && func_080DD1FC(*(void**)(work->unk_020 + 4)) == 0) {
        return 1;
    }

    return 0;
}

void task_bos_ursula_0(UrsulaWork* work) {
    u8 v;

    gUrsulaWork = work;
    gUnk_0203C57C = 1;
    TaskCreate((u8*)gBtlWork + 0x40, &gTaskDescBosUrsulaMap, gUnk_096FE14C);
    TaskCreate((u8*)gBtlWork + 0x2C, &gTaskDescBosUrsulaBorder, 0);
    work->unk_000 = 0;
    work->unk_004 = 0;
    work->unk_134 = 0;
    work->unk_160 = 0;
    work->unk_140 = 0;
    work->unk_13C = 0;
    work->unk_138 = 0;
    work->unk_142 = 0;
    SetBattleBounds(0, 0x200, 0x1A8, 0x1E0);
    func_0801BCC0(0x10000, 0x1A800, 0);
    gBtlWork->unk_0D8 = 0xFF00;
    gUnk_0203C580 = -0x5000;
    func_0801B37C(&work->unk_024, gUnk_096FE13C, 0x10000, 0x19800, -0x5000);
    work->unk_034 = 0;
    work->unk_058 |= 4;
    func_0801C2DC(&work->unk_024, 1);
    func_080DB978(work);
    RedrawBgMapAt(0, (gBtlWork->unk_000 - (work->unk_028 - 0x12000)) >> 8,
        (gBtlWork->unk_004 - (work->unk_02C + work->unk_030 - 0x12000)) >> 8);
    func_0801C298(0, 1);
    func_0801C298(1, 1);
    gBtlWork->unk_0CC = work->unk_028;
    gBtlWork->unk_0D0 = work->unk_02C;
    gBtlWork->unk_0D4 = work->unk_030;
    TaskPoolInit(&work->unk_008, 5);
    v = 1;
    work->unk_01C = (u32)TaskCreate(&work->unk_008, &gTaskDescBosUrsulaTako, &v);
    v = 0;
    work->unk_020 = (u32)TaskCreate(&work->unk_008, &gTaskDescBosUrsulaTako, &v);
    TaskCreate(&work->unk_008, &gTaskDescBosUrsulaMapanime, 0);
    v = 1;
    TaskCreate(&work->unk_008, &gTaskDescBosUrsulaBacktako, &v);
    work->unk_15E = 0;
}

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
    p->z = gUnk_0203C580 + work->unk_138;
    work->unk_140--;
}

u8 func_080DBC68(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    func_080DBC00(work);

    if (func_080DC510() != 0) {
        p->x -= 0x100;

        if (p->x <= -0x9800) {
            p->x = -0x9800;
            return 0;
        }
    } else {
        p->x += 0x100;

        if (p->x >= 0x28000) {
            p->x = 0x28000;
            return 0;
        }
    }

    return 1;
}

s32 func_080DBCC0(UrsulaWork* work) {
    BtlObj* p = gBtlWork->actor;

    if (p->x < work->unk_028 - 0x5000 || work->unk_028 + 0x5000 < p->x) {
        return 1;
    }

    return 3;
}

s32 func_080DBCEC(UrsulaWork* work) {
    if (work->unk_028 - 0x3800 < gBtlWork->actor->x && gBtlWork->actor->x < work->unk_028 + 0x3800) {
        return 3;
    }

    if (work->unk_028 - 0x6800 < gBtlWork->actor->x && gBtlWork->actor->x < work->unk_028 + 0x6800) {
        return 2;
    }

    return 1;
}

s32 func_080DBD44(UrsulaWork* work) {
    if (gBtlWork->actor->z <= -0x5000) {
        return 3;
    } else {
        if (work->unk_028 - 0x3800 < gBtlWork->actor->x && gBtlWork->actor->x < work->unk_028 + 0x3800) {
            if ((u16)(GetRandom() % 100) < 50) {
                return 3;
            }
            return 1;
        }
    }
    if (work->unk_028 - 0x8000 < gBtlWork->actor->x && gBtlWork->actor->x < work->unk_028 + 0x8000) {
        return 2;
    }
    return 1;
}

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

u16 func_080DBE64(void) {
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

u8 task_bos_ursula_1(UrsulaWork* work) {
    BtlObj* p = (BtlObj*)&work->unk_024;
    UrsulaPrizeArg pos;
    s32 x;
    u16 chance;

    switch (func_0801ADAC(p)) {
    case 5:
        work->unk_000 = 1;
        work->unk_004 = 0;
        break;
    case 1:
    case 6:
    case 7:
        func_080DBE18(work);
        work->unk_000 = 3;
        work->unk_004 = 0;
        break;
    case 3:
    case 8:
        work->unk_000 = 4;
        work->unk_004 = 0;
        break;
    case 4:
        work->unk_000 = 2;
        break;
    }

    if (func_0801C1C0(0)) {
        if (work->unk_142 == 0) {
            work->unk_148 = gBtlWork->unk_000;
            work->unk_14C = gBtlWork->unk_004;
            work->unk_154 = gBtlWork->unk_004;
            work->unk_158 = 40;
            work->unk_15A = 40;
            work->unk_15C = 20;
            work->unk_150 = 0;
            work->unk_15E = 9;
        }
        work->unk_142 = 300;
        if (work->unk_000 == 1) {
            work->unk_000 = 2;
        }
    }

    if (work->unk_142 == 0) {
        gUnk_0203C580 = -0x5000;
    } else if (work->unk_15E == 0) {
        if (work->unk_158 != 0) {
            ApproachValue((s32*)&work->unk_150, 0x3800, work->unk_158);
            ApproachValue((s32*)&work->unk_154, work->unk_14C + 0x3800, work->unk_158 >> 1);
            func_0802F274(work->unk_148, work->unk_154);
            work->unk_158--;
        } else {
            if (work->unk_142 == 300) {
                func_0802F1E8();
            }
            work->unk_142--;
            if (work->unk_142 == 0 && work->unk_000 == 4) {
                work->unk_142 = 1;
            }
            if (work->unk_142 > 280) {
                func_0802F274(work->unk_148, work->unk_154);
            }
        }
        if (work->unk_142 == 0 && work->unk_15A != 0) {
            work->unk_142++;
            ApproachValue((s32*)&work->unk_150, 0, work->unk_15A);
            work->unk_15A--;
        }
        gUnk_0203C580 = work->unk_150 - 0x5000;
    } else {
        work->unk_15E--;
    }

    if (func_080DBA14(work)) {
        func_0801C2DC(&work->unk_024, 1);
    } else {
        func_0801C2DC(&work->unk_024, 0);
    }

    switch (work->unk_000) {
    case 1:
        if ((s16)work->unk_004 == 0) {
            func_080DD69C(func_080DBDC0(work));
            work->unk_004 = 1;
        } else {
            if (func_080DD794()) {
                func_080DBC68(work);
            }
            if (!func_080DD754()) {
                func_0801AF08(p);
                work->unk_000 = 0;
            }
        }
        break;
    case 2:
        func_0801AF08(p);
        work->unk_000 = 0;
        func_080DD69C(0);
        break;
    case 3:
        if ((s16)work->unk_004 > 20) {
            func_0801AF08(p);
            if (func_080DC5E8() == 1 && !func_080DC528()) {
                work->unk_000 = 5;
            } else {
                work->unk_000 = 0;
            }
            work->unk_004 = 0;
        } else {
            work->unk_004++;
        }
        break;
    case 4:
        if ((s16)work->unk_004 == 0) {
            func_0801AF4C(p);
            func_080DB978(work);
            work->unk_004++;
        } else if ((s16)work->unk_004 == 1) {
            work->unk_004++;
        } else if ((s16)work->unk_004 == 2) {
            if (func_080DC510()) {
                x = p->x + 0x1400;
            } else {
                x = p->x - 0x1C00;
            }
            func_08014AAC(x, p->y + p->z + 0x1C00);
            FadeToAmount(0, gBtlWork->unk_0B3, 8);
            work->unk_004++;
        } else if ((s16)work->unk_004 == 3) {
            if (!FadeIsActive()) {
                work->unk_004++;
            }
        } else if ((s16)work->unk_004 < 124) {
            work->unk_004++;
            if ((s16)work->unk_004 == 124) {
                func_0801536C();
            }
        } else if (!func_080128EC()) {
            pos.x = p->x;
            if (pos.x < 0x2000) {
                pos.x = 0x2000;
            }
            if (pos.x > 0x1E000) {
                pos.x = 0x1E000;
            }
            pos.y = 0x1A800;
            pos.z = p->z;
            CreateBossPrizeCardTask(&gBtlWork->taskPools[0], &pos);
            func_0801B008();
            func_0801B918(p);
            DisableBg(0);
            gUnk_0203C57C = 0;
            return 0;
        }
        break;
    case 0:
        if (work->unk_028 > gBtlWork->actor->x) {
            p->unk_034 |= 4;
        } else {
            p->unk_034 &= ~4ULL;
        }
        if (!func_080DC528()) {
            if (func_080DBA14(work)) {
                chance = func_080DBE64();
                if ((u16)(GetRandom() % chance) == 0) {
                    func_0801BCD4(&work->unk_024);
                }
            }
            if ((u32)p->x > 0x20000) {
                work->unk_000 = 5;
            }
            if (func_080DC5E8() == 2) {
                if (((p->x - gBtlWork->actor->x) >= 0 ? p->x - gBtlWork->actor->x : -(p->x - gBtlWork->actor->x)) > 0x6800) {
                    work->unk_000 = 5;
                }
            }
        }
        func_080DBC00(work);
        break;
    case 5:
        if (func_080DC528()) {
            func_080DBC00(work);
        } else {
            if (!func_080DBC68(work)) {
                p->unk_034 ^= 4;
            }
            if (func_080DC5E8() == 2 && p->x > 0x6800 && p->x < 0x19800) {
                if (((p->x - gBtlWork->actor->x) >= 0 ? p->x - gBtlWork->actor->x : -(p->x - gBtlWork->actor->x)) < 0x6800 && func_080DBA14(work)) {
                    func_0801BCD4(&work->unk_024);
                    work->unk_000 = 0;
                }
            }
            if ((!(p->unk_034 & 4) && p->x == 0x6800) || ((p->unk_034 & 4) && p->x == 0x19800)) {
                work->unk_000 = 0;
            }
        }
        break;
    }

    if (work->unk_000 != 4) {
        func_080DB978(work);
    }
    if (func_080DBA14(work)) {
        ColliderSetPosition(&p->collider, p->x, p->y, p->z);
    } else {
        ColliderSetPosition(&p->collider, p->x, p->y + 0x1000, p->z - 0x1000);
    }
    gBtlWork->unk_0CC = p->x;
    gBtlWork->unk_0D0 = p->y;
    gBtlWork->unk_0D4 = p->z;
    TaskPoolUpdate(&work->unk_008);
    return 1;
}
void task_bos_ursula_2(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;
    s32 d = 0;

    if (func_080DC510() != 0 && work->unk_134 == (u32)gUnk_09EF5190) {
        d = -0x1000;
    } else if (func_080DC510() == 0 && work->unk_134 == (u32)gUnk_09EF5130) {
        d = 0x1000;
    }

    ScrollBgMapTo(0, (gBtlWork->unk_000 - (p->x - 0x12000) + d) >> 8,
        (gBtlWork->unk_004 - (p->y + p->z - 0x12000)) >> 8);
    TaskPoolDraw(&work->unk_008);
}

void task_bos_ursula_3(UrsulaWork* work) {
    func_0801B7D8(&work->unk_024);
    TaskPoolDestroy(&work->unk_008);
    gDispCnt &= 0xDFFF;
}

u8 func_080DC510(void) {
    return ((UrsulaWork*)gUrsulaWork)->unk_058 & 4;
}

u8 func_080DC528(void) {
    if (((UrsulaWork*)gUrsulaWork)->unk_142 == 0) {
        return 0;
    }

    return 1;
}

u8 func_080DC544(void) {
    BtlObj* p;
    u8 r = 1;

    for (p = ListPoolFirst(&gBtlWork->pool); p != 0; p = ListPoolNext(&p->node)) {
        if (p->unk_000 == 0x23) {
            r = 0;
            break;
        }
    }

    return r;
}

u8 func_080DC578(void) {
    if (func_080DC544() != 0 || func_080DC528() == 0 || ((UrsulaWork*)gUrsulaWork)->unk_15E == 0) {
        return 0;
    }

    return 1;
}

u8 func_080DC5B0(void) {
    if (func_080DC528() != 0 && (*(u32*)&((UrsulaWork*)gUrsulaWork)->unk_158 != 0 || ((UrsulaWork*)gUrsulaWork)->unk_15C != 0)) {
        return 1;
    }

    return 0;
}

u32 func_080DC5E8(void) {
    UrsulaWork* work = (UrsulaWork*)gUrsulaWork;

    if (work->unk_050 > (s16)(work->unk_052 / 3) * 2) {
        return 0;
    }

    if (work->unk_050 > (s16)(work->unk_052 / 3)) {
        return 1;
    }

    return 2;
}

u8 func_080DC628(void) {
    if (((UrsulaWork*)gUrsulaWork)->unk_000 == 4) {
        return 1;
    }

    return 0;
}

void task_bos_ursula_map_0(UrsulaMapWork* work, BattleBackgroundDef* arg) {
    SetupBg(0, 0, 0x1A, 0);
    SetupBg(1, 0, 0x18, 0);
    SetBgPriority(1, 3);
    SetBgPriority(0, 2);
    LoadBgTiles(1, arg->tiles, arg->tilesSize);
    LoadBgPalette(1, arg->palette, arg->paletteSize);
    SetBgMapBlocks(1, arg->map, 2, 2);
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0x10000;
    gBtlWork->y = 0x17100;
    gBtlWork->unk_000 = 0x10000;
    gBtlWork->unk_004 = 0x17100;
    gBtlWork->x2 = 0x10000;
    gBtlWork->y2 = 0x17100;
    gBtlWork->unk_01C = 0x10000;
    gBtlWork->unk_020 = 0x17100;
    gBtlWork->unk_01A = 0x0F;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    ScrollBgMapTo(1, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
    gDispCnt |= 0x2000;
    gWin0H = 0xF0;
    gWin0V = 0x50A0;
    gWinIn = 0x3E;
    gWinOut = 0x3F;
    work->unk_00 = 0x1E000;
    work->unk_04 = 0x1E000;
    work->unk_08 = 0;
}
u8 task_bos_ursula_map_1(UrsulaMapWork* work) {
    s32 a;
    s32 b;
    u8 v;

    if (func_080DC578() != 0) {
        return 1;
    }

    func_0802F208();
    a = (gBtlWork->x2 - gBtlWork->x) >> 3;
    b = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (a > 0x500) {
        a = 0x500;
    } else if (a < -0x500) {
        a = -0x500;
    }

    if (b > 0x500) {
        b = 0x500;
    } else if (b < -0x500) {
        b = -0x500;
    }

    gBtlWork->x += a;
    gBtlWork->y += b;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gBtlWork->unk_000 - 0x7800 < gBtlWork->unk_0DA * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x78) << 8;
    } else if (gBtlWork->unk_000 + 0x7800 > gBtlWork->unk_0DC * 256) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x78) << 8;
    }

    if (func_080DC5B0() != 0 && work->unk_04 == 0x1E000) {
        work->unk_04 = 0x22000;
        work->unk_08 = 20;
    } else if (func_080DC5B0() == 0 && work->unk_04 == 0x22000) {
        work->unk_04 = 0x1E000;
        work->unk_08 = 20;
    }

    if (work->unk_08 != 0) {
        ApproachValue(&work->unk_00, work->unk_04, work->unk_08);
        work->unk_08--;
    }

    if (gBtlWork->unk_004 - 0x5000 < 0x8800) {
        gBtlWork->unk_004 = 0xD800;
    } else if (gBtlWork->unk_004 + 0x5000 > work->unk_00) {
        gBtlWork->unk_004 = work->unk_00 - 0x5000;
    }

    gBtlWork->unk_004 += func_0802F268();
    ScrollBgMapTo(1, (gBtlWork->unk_000 >> 8) - 0x78, (gBtlWork->unk_004 >> 8) - 0x50);
    v = -0x18 - (gBtlWork->unk_004 >> 8);

    if (v > 0xA0 || gUnk_0203C57C == 0) {
        gDispCnt &= 0xDFFF;
    } else {
        gDispCnt |= 0x2000;
        gWin0V = (v << 8) | 0xA0;
    }

    return 1;
}

void task_bos_ursula_map_3(void) {
}

void task_bos_ursula_border_0(UrsulaBorderWork* work) {
    work->tiles = LoadObjTiles(gUnk_0979D0B6, 0x800);
    work->palette = LoadObjPalette(gUnk_0984B0D8, 0x20);
    func_0801C298(((u8*)work->palette)[6] + 16, 0);
}

s32 task_bos_ursula_border_1(void) {
    return 1;
}

void task_bos_ursula_border_2(UrsulaBorderWork* work) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;

    GetBattleSpritePriorityFlags(0x19800);
    WorldToScreen(&a, &b, 0x8000, 0x19800, -0x800);
    WorldToScreen(&c, &d, 0x18000, 0x19800, -0x800);
    DrawSprite(a, b, gUnk_0979D090, work->tiles, work->palette, 0, 0x800, 0xFB00);
    DrawSprite(c, d, gUnk_0979D8B8, work->tiles, work->palette, 0, 0x800, 0xFB00);
}

void task_bos_ursula_border_3(UrsulaBorderWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080DC9DC(s32* a, s32* b, s32* c, UrsulaTakoWork* d) {
    s32* p;
    s32 t;

    *a = gBtlWork->unk_0CC + d->unk_1FC;

    if (d->unk_13E != 0) {
        if (func_080DC510() != 0) {
            *a += -0x2200;
        } else {
            *a += -0x3600;
        }
    } else {
        if (func_080DC510() != 0) {
            *a += 0x3600;
        } else {
            *a += 0x2200;
        }
    }

    *b = gBtlWork->unk_0D0;
    p = &gBtlWork->unk_0D4;
    t = d->unk_200 + 0x5000;
    *c = *p + t;
}

s32 func_080DCA78(u8 a) {
    if (a == func_080DC510()) {
        return 12;
    }

    return 6;
}

void task_bos_ursula_tako_0(UrsulaTakoWork* work, u8* arg) {
    s32 x;
    s32 y;
    s32 z;

    work->unk_13E = *arg;
    work->unk_1FC = 0;
    work->unk_200 = 0;
    func_080DC9DC(&x, &y, &z, work);
    func_0801B37C(&work->unk_028, gUnk_096FE1A8, x, y, z);
    ColliderInit(&work->unk_19C, 7, 0x28, 0x20);

    if (work->unk_13E != 0) {
        work->unk_024 = 0xFFFC;
        work->unk_05C |= 4;
        work->unk_1F8 = -0x2800;
    } else {
        work->unk_024 = 0;
        work->unk_1F8 = 0x2800;
    }

    work->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF6860, 6), gUnk_0979E344);
    work->palette = LoadObjPalette(gUnk_0984B0F8, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->anim, gUnk_09EF68A0, gUnk_09EF6860);
    AnimStart(&work->anim, (u16)(work->unk_024 + 4), 1);
    work->unk_138 = 0;
    ColliderInit(&work->unk_140, 7, (u16)func_080DCA78(work->unk_13E), 1);
    ColliderSetPosition(&work->unk_140, work->unk_02C, work->unk_030 + 0x1000, -0x3800);
    func_0801C7FC(&work->unk_028, 35, 51);
}
u8 task_bos_ursula_tako_1(UrsulaTakoWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_028;
    s32 x;
    s32 y;
    s32 z;
    s32 dx;
    s32 dz;

    if (func_080DC528()) {
        func_0801C2DC(p, 1);
    } else if (work->unk_138 <= 1) {
        func_0801C2DC(p, 0);
    }

    if (func_080DC628()) {
        return 1;
    }

    switch (func_0801ADAC(p)) {
    case 5:
        work->unk_138 = 7;
        work->unk_13C = 0;
        func_08083914();
        break;
    case 1:
    case 6:
    case 7:
        work->unk_138 = 1;
        work->unk_13C = 0;
        break;
    case 3:
    case 8:
        work->unk_138 = 2;
        work->unk_13C = 0;
        break;
    case 4:
        func_0801AF08(p);
        work->unk_138 = 0;
        func_08083914();
        break;
    }

    switch (work->unk_138) {
    case 0:
        AnimChange((AnimState*)&work->anim, (u16)(work->unk_024 + 4), 1);
        break;
    case 1:
        if (work->unk_13C == 0) {
            AnimChange((AnimState*)&work->anim, (u16)(work->unk_024 + 7), 0);
        }
        work->unk_13C++;
        if (AnimIsFinished((AnimState*)&work->anim)) {
            func_0801AF08(p);
            work->unk_138 = 0;
            work->unk_13C = 0;
        }
        break;
    case 2:
        if (AnimGetId((AnimState*)&work->anim) == (s16)work->unk_024 + 4) {
            if (AnimGetFrame((AnimState*)&work->anim) == 0 && AnimIsFrameEnding((AnimState*)&work->anim)) {
                AnimStart((AnimState*)&work->anim, (u16)(work->unk_024 + 5), 1);
                func_0801C2DC(p, 1);
                if ((u16)(GetRandom() % 100) <= 19) {
                    _0801C1F8(0, p->x, p->y, p->z);
                }
            }
        } else if (AnimGetId((AnimState*)&work->anim) == (s16)work->unk_024 + 5) {
            if (AnimIsFinished((AnimState*)&work->anim)) {
                func_0801AF08(p);
                work->unk_138 = 3;
                work->unk_13C = 0;
            }
        } else {
            AnimStart((AnimState*)&work->anim, (u16)(work->unk_024 + 4), 1);
        }
        break;
    case 3:
        if (work->unk_13C > 180) {
            work->unk_138 = 4;
            work->unk_13C = 0;
        } else {
            work->unk_13C++;
        }
        break;
    case 4:
        if (work->unk_13C > 180) {
            AnimStart((AnimState*)&work->anim, (u16)(work->unk_024 + 6), 0);
            work->unk_138 = 5;
            work->unk_200 = 0x800;
            if (work->unk_13E) {
                work->unk_1FC = -0x2AA;
            } else {
                work->unk_1FC = 0x2AA;
            }
            work->unk_13C = 30;
        } else {
            work->unk_13C++;
        }
        break;
    case 5:
        AnimReset((AnimState*)&work->anim);
        if (work->unk_13C == 5) {
            func_0801B7D8(&work->unk_028);
            func_080DC9DC(&x, &y, &z, work);
            func_0801B37C(&work->unk_028, gUnk_096FE1A8, x, y, z);
            work->unk_05C |= 0x400;
            func_0801C7FC(&work->unk_028, 35, 25);
        }
        if (work->unk_13C == 0) {
            if (!func_080DC528()) {
                func_0801BCD4(&work->unk_028);
            }
            work->unk_138 = 6;
            work->unk_13C = 0;
        } else {
            ApproachValue(&work->unk_200, 0, work->unk_13C);
            ApproachValue(&work->unk_1FC, 0, work->unk_13C);
            work->unk_13C--;
        }
        break;
    case 6:
        if (work->unk_13C > 30) {
            work->unk_138 = 0;
        } else {
            work->unk_13C++;
        }
        break;
    case 7:
        AnimChange((AnimState*)&work->anim, (u16)(work->unk_024 + 6), 0);
        if (AnimIsFinished((AnimState*)&work->anim) || func_080DC528()) {
            work->unk_138 = 0;
            AnimStart((AnimState*)&work->anim, (u16)(work->unk_024 + 4), 1);
            func_0801AF08(p);
        } else {
            if (AnimGetFrame((AnimState*)&work->anim) == 1) {
                dx = 0x800;
                if (work->unk_13E) {
                    dx = -0x800;
                }
                dz = -0x6000;
            } else if (AnimGetFrame((AnimState*)&work->anim) == 0) {
                dx = -0x1800;
                if (work->unk_13E) {
                    dx = 0x1800;
                }
                dz = -0x3800;
            } else {
                dx = 0x1800;
                if (work->unk_13E) {
                    dx = -0x1800;
                }
                dz = -0x3800;
            }
            if (func_08011F78(241, p->x + dx, p->y + 0x1000, p->z + dz, 24, 16, 8) == 1) {
                m4aSongNumStart(578);
            }
        }
        break;
    }

    AnimUpdate((AnimState*)&work->anim);
    func_080DC9DC(&p->x, &p->y, &p->z, work);
    if (work->unk_138 - 3 <= 4 && gBtlWork->actor->z < -0x5000 && !func_080DC528()) {
        ColliderSetDisabled(&work->unk_140, 0);
        ColliderSetPosition(&work->unk_140, work->unk_02C, work->unk_030 + 0x1000, -0x5000);
    } else {
        ColliderSetDisabled(&work->unk_140, 1);
    }
    if (work->unk_138 == 3 && gBtlWork->actor->z <= -0x2000 && gBtlWork->actor->z > -0x3000) {
        ColliderSetDisabled(&work->unk_19C, 0);
        ColliderSetPosition(&work->unk_19C, work->unk_02C + work->unk_1F8, work->unk_030 + 0x1000, 0);
    } else {
        ColliderSetDisabled(&work->unk_19C, 1);
    }
    return 1;
}

void task_bos_ursula_tako_2(UrsulaTakoWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_028;
    void* pal;
    s16 x;
    s16 y;

    if (work->unk_138 != 4 && func_080DC528() == 0) {
        pal = func_0801CA00(p) != 0 ? work->palette2 : work->palette;
        WorldToScreen(&x, &y, p->x, p->y, p->z);
        DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, 0, 0x800, 0xFC00);
    }
}

void task_bos_ursula_tako_3(UrsulaTakoWork* work) {
    func_0801B7D8(&work->unk_028);
    ColliderUnregister(&work->unk_19C);
    ColliderUnregister(&work->unk_140);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
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

void func_080DD248(s32* a, s32* b, s32* c, UrsulaBacktakoWork* d) {
    s32* p;
    s32 t;

    *a = gBtlWork->unk_0CC + d->unk_024;

    if (d->unk_022 != 0) {
        if (func_080DC510() != 0) {
            *a += -0x4A00;
        } else {
            *a += -0x5E00;
        }
    } else {
        if (func_080DC510() != 0) {
            *a += 0x5E00;
        } else {
            *a += 0x4A00;
        }
    }

    *b = gBtlWork->unk_0D0 + 0x800;
    p = &gBtlWork->unk_0D4;
    t = d->unk_028 + 0x5000;
    *c = *p + t;
}
void task_bos_ursula_backtako_0(UrsulaBacktakoWork* work, u8* arg) {
    work->unk_022 = *arg;
    work->unk_024 = 0;
    work->unk_028 = 0;
    func_080DD248(&work->x, &work->y, &work->z, work);
    work->unk_022 = work->unk_022 == 0 ? 1 : 0;
    func_080DD248(&work->x2, &work->y2, &work->z2, work);
    work->unk_022 = work->unk_022 == 0 ? 1 : 0;
    if (work->unk_022 != 0) {
        work->unk_020 = 0xFFFC;
    } else {
        work->unk_020 = 0;
    }

    work->tiles = (u32)AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF6860, 8), gUnk_0979E344);
    work->palette = (u32)LoadObjPalette(gUnk_0984B0F8, 32);
    AnimInit(&work->anim, gUnk_09EF68A0, gUnk_09EF6860);
    AnimStart(&work->anim, (u16)(work->unk_020 + 4), 1);
    AnimSetFrame(&work->anim, GetRandom() % work->unk_014 + 1);
}

u8 task_bos_ursula_backtako_1(UrsulaBacktakoWork* work) {
    if (func_080DC628() == 0) {
        func_080DD248(&work->x, &work->y, &work->z, work);
        work->unk_022 = work->unk_022 == 0 ? 1 : 0;
        func_080DD248(&work->x2, &work->y2, &work->z2, work);
        work->unk_022 = work->unk_022 == 0 ? 1 : 0;
        AnimUpdate(&work->anim);
    }

    return 1;
}

void task_bos_ursula_backtako_2(UrsulaBacktakoWork* work) {
    s16 x;
    s16 y;
    u8 f = func_080DC528();

    if (f != 0) {
        return;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, AnimGetGfx(&work->anim), (void*)work->tiles, (void*)work->palette, f, 0xC00,
        0xFE00);
    WorldToScreen(&x, &y, work->x2, work->y2, work->z2);
    DrawSprite(x, y, AnimGetGfx(&work->anim), (void*)work->tiles, (void*)work->palette, f, 0xC01,
        0xFE00);
}

void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

void task_bos_ursula_mapanime_0(UrsulaMapanimeWork* work) {
    gUrsulaMapanimeWork = work;
    TaskPoolInit(&work->unk_010, 1);
    work->unk_024 = 0;
    work->unk_00C = 4;
    func_080DD69C(0);
}

u8 task_bos_ursula_mapanime_1(UrsulaMapanimeWork* work) {
    s32 d;

    func_080DDDEC(&work->unk_000, work->unk_000.unk_08, 0);

    if (func_080DDE74(&work->unk_000) != 0) {
        if (work->unk_000.unk_08 == &gUnk_096FE278) {
            if (work->unk_00C == 1) {
                func_080DDDDC(&work->unk_000, &gUnk_096FE290);
                work->unk_00C = 4;
            } else if (work->unk_00C == 2) {
                func_080DDDDC(&work->unk_000, &gUnk_096FE2A8);
                work->unk_00C = 4;
            }
        } else if (work->unk_000.unk_08 == &gUnk_096FE290
                || work->unk_000.unk_08 == &gUnk_096FE2A8) {
            func_080DDDDC(&work->unk_000, &gUnk_096FE2C0);
            work->unk_00C = 4;
        } else if (work->unk_000.unk_08 == &gUnk_096FE2C0) {
            func_080DDDDC(&work->unk_000, &gUnk_096FE260);
            work->unk_00C = 0;
        }
    }

    if (work->unk_000.unk_08 == &gUnk_096FE2A8 && func_080DDEA0(&work->unk_000) == 2) {
        if (work->unk_028 == 0) {
            work->unk_028 = 1;
            func_080168B8(gBtlWork->unk_0CC, gBtlWork->unk_0D0 + 0xC00,
                gBtlWork->unk_0D4, func_080DC510(), 0x266, 0x78);
        } else {
            func_08014780(gBtlWork->unk_0CC, gBtlWork->unk_0D0 + 0xC00,
                gBtlWork->unk_0D4);
        }

        d = func_080DC510() != 0 ? -0x5000 : 0x5000;
        func_08011F78(0xF3, gBtlWork->unk_0CC + d, 0x1C400, 0, 0x18, 0x38, 0x50);
    }

    if (work->unk_000.unk_08 == &gUnk_096FE290 && func_080DDEA0(&work->unk_000) == 2
            && work->unk_028 == 0) {
        work->unk_028 = 1;
        work->unk_024 = TaskCreate(&work->unk_010, &gTaskDescBosUrsulaBubble, 0);
    }

    TaskPoolUpdate(&work->unk_010);

    return 1;
}

void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work) {
    TaskPoolDraw(&work->unk_010);
}

void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work) {
    TaskPoolDestroy(&work->unk_010);
}

void func_080DD69C(s32 a) {
    if (IsTaskActive(gUrsulaMapanimeWork->unk_024) != 0) {
        if (strcmp(GetTaskName(gUrsulaMapanimeWork->unk_024), gUnk_096FE2F4) == 0) {
            func_080DD9B0(((UrsulaBubbleWork**)gUrsulaMapanimeWork->unk_024)[1]);
        } else {
            func_08000DE8(&gUrsulaMapanimeWork->unk_010, gUrsulaMapanimeWork->unk_024);
        }
    }

    if (a == 3) {
        gUrsulaMapanimeWork->unk_024 = TaskCreate(&gUrsulaMapanimeWork->unk_010, &gTaskDescBosUrsulaThunder, 0);
    } else if (gUrsulaMapanimeWork->unk_00C != a) {
        gUrsulaMapanimeWork->unk_00C = a;

        if (a == 0) {
            func_080DDDDC(&gUrsulaMapanimeWork->unk_000, &gUnk_096FE2C0);
            gUrsulaMapanimeWork->unk_028 = 1;
        } else {
            func_080DDDDC(&gUrsulaMapanimeWork->unk_000, &gUnk_096FE278);
            gUrsulaMapanimeWork->unk_028 = 0;
            m4aSongNumStart(0x111);
        }
    }
}

u8 func_080DD754(void) {
    if (gUrsulaMapanimeWork->unk_000.unk_08 == &gUnk_096FE290 || gUrsulaMapanimeWork->unk_000.unk_08 == &gUnk_096FE2A8 || gUrsulaMapanimeWork->unk_000.unk_08 == &gUnk_096FE278) {
        return 1;
    }

    return IsTaskActive((void*)gUrsulaMapanimeWork->unk_024);
}

u8 func_080DD794(void) {
    if (gUrsulaMapanimeWork->unk_000.unk_08 == &gUnk_096FE2A8 && func_080DDEA0(&gUrsulaMapanimeWork->unk_000) == 2) {
        return 1;
    }

    return 0;
}

u16 func_080DD7C4(UrsulaBubbleWork* work) {
    s8 v = 0x60;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[0] = TaskCreate(&work->unk_004, &gTaskDescBosUrsulaBubbleSingle, &v);
    v = 0x20;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[1] = TaskCreate(&work->unk_004, &gTaskDescBosUrsulaBubbleSingle, &v);
    v = 0x40;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[2] = TaskCreate(&work->unk_004, &gTaskDescBosUrsulaBubbleSingle, &v);

    return 3;
}

u16 func_080DD854(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 14;

    for (i = 0; i <= 5; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->unk_004, &gTaskDescBosUrsulaBubbleSingle, &v);
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

        work->unk_018[i] = TaskCreate(&work->unk_004, &gTaskDescBosUrsulaBubbleSingle, &v);
        a += 16;
    }

    return i;
}

void task_bos_ursula_bubble_0(UrsulaBubbleWork* work) {
#ifdef VERSION_EU
    gUnkEu_02035104 = (u32)work;
    AnimInit(&work->unkEu_044, gUnk_09EF68D8, gUnk_09EF68C0);
    AnimStart(&work->unkEu_044, 0, 1);
    *(void**)((u8*)gBtlWork + 0x118) =
        AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF68C0, 6), gUnk_097A0DE4);
#endif
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
#ifdef VERSION_EU
    AnimUpdate(&work->unkEu_044);
#endif

    for (i = 0; i < work->unk_040; i++) {
        if (IsTaskActive(work->unk_018[i]) != 0) {
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

void task_bos_ursula_bubble_3(UrsulaBubbleWork* work) {
    TaskPoolDestroy(&work->unk_004);
#ifdef VERSION_EU
    ReleaseObjTiles(*(void**)((u8*)gBtlWork + 0x118));
#endif
}

void func_080DD9B0(UrsulaBubbleWork* work) {
    s32 i;

    for (i = 0; i < work->unk_040; i++) {
        if (IsTaskActive(work->unk_018[i]) != 0) {
            func_080DDD30(*(void**)((u8*)work->unk_018[i] + 4));
        }
    }
}

#ifdef VERSION_EU
void eu_080DA80C(u16 a, u16 b) {
    AnimChange(&((UrsulaBubbleWork*)gUnkEu_02035104)->unkEu_044, a, b);
}

u16 eu_080DA830(void) {
    return AnimGetId(&((UrsulaBubbleWork*)gUnkEu_02035104)->unkEu_044);
}

u8 eu_080DA848(void) {
    return AnimIsFinished(&((UrsulaBubbleWork*)gUnkEu_02035104)->unkEu_044);
}

void* eu_080DA860(void) {
    return AnimGetGfx(&((UrsulaBubbleWork*)gUnkEu_02035104)->unkEu_044);
}
#endif

void task_bos_ursula_bubble_single_0(UrsulaBubbleSingleWork* work, u8* arg) {
    work->unk_13C = *arg;
    work->unk_140 = 0x333;
    func_0801B37C(&work->unk_024, gUnk_096FE324, gBtlWork->unk_0CC,
        gBtlWork->unk_0D0 + 0x1000, gBtlWork->unk_0D4);
    func_0801C2DC(&work->unk_024, 1);
#ifdef VERSION_EU
    work->tiles = *(void**)((u8*)gBtlWork + 0x118);
#else
    work->tiles = LoadObjTiles(gUnk_097A0DE4, 0xA80);
#endif
    work->palette = LoadObjPalette(gUnk_0984B0F8, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
#ifdef VERSION_EU
    eu_080DA80C(0, 1);
#else
    AnimInit(&work->anim, gUnk_09EF68D8, gUnk_09EF68C0);
    AnimStart(&work->anim, 0, 1);
#endif
    work->unk_138 = 0;
    work->unk_134 = 0x3C;
}
u8 task_bos_ursula_bubble_single_1(UrsulaBubbleSingleWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    work->unk_140 -= 12;

    if (work->unk_140 < 0x166) {
        work->unk_140 = 0x166;
    }

    if (work->unk_138 == 0) {
        p->x += gSineTable[(u8)work->unk_13C] * work->unk_140 >> 8;
        p->z += -gSineTable[(u8)work->unk_13C + 0x40] * work->unk_140 >> 8;
        work->unk_134--;

        if (p->z >= 0) {
            p->z = 0;
            work->unk_134 = 0;
        }

        if (work->unk_134 == 0) {
            work->unk_134 = 180;
            work->unk_138 = 1;
        }
    }

    if (work->unk_138 == 1 && work->unk_134 != 0) {
        work->unk_13E = (u8)GetAngle(p->x, p->z,
            gBtlWork->actor->x, gBtlWork->actor->z);
        ApproachAngle(&work->unk_13C, work->unk_13E, 4);
        p->x += gSineTable[(u8)work->unk_13C] * work->unk_140 >> 8;
        p->z += -gSineTable[(u8)work->unk_13C + 0x40] * work->unk_140 >> 8;

        if (work->unk_134 <= 169) {
            ApproachValue(&p->y, gBtlWork->actor->y, 30);
        }

        if ((u32)p->x > 0x20800 || p->y > 0x20800) {
            return 0;
        }

        work->unk_134--;

        if (work->unk_134 == 0) {
#ifdef VERSION_EU
            eu_080DA80C(1, 0);
#else
            AnimStart(&work->anim, 1, 0);
#endif
            func_0801C2DC(&work->unk_024, 1);
        }
    }

#ifdef VERSION_EU
    if (eu_080DA830() == 0
#else
    if (AnimGetId(&work->anim) == 0
#endif
            && func_08011F78(0xF2, p->x, p->y, p->z, 1, 1, 1) == 1) {
        m4aSongNumStart(0x281);

        return 0;
    }

#ifdef VERSION_EU
    if (eu_080DA830() == 1 && eu_080DA848() != 0) {
        return 0;
    }

#else
    if (AnimGetId(&work->anim) == 1 && AnimIsFinished(&work->anim) != 0) {
        return 0;
    }

    AnimUpdate(&work->anim);
#endif
    ColliderSetPosition((u8*)p + 0x40, p->x, p->y, p->z);

    return 1;
}

void task_bos_ursula_bubble_single_2(UrsulaBubbleSingleWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;
    void* pal;
    u16 v;
    s16 x;
    s16 y;

    v = GetBattleSpritePriorityFlags(p->y);
    pal = func_0801CA00(p) != 0 ? work->palette2 : work->palette;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
#ifdef VERSION_EU
    DrawSprite(x, y, eu_080DA860(), work->tiles, pal, 0, v, -0x1004 - (p->y >> 8) * 4);
#else
    DrawSprite(x, y, AnimGetGfx(&work->anim), work->tiles, pal, 0, v, -0x1004 - (p->y >> 8) * 4);
#endif
}

void task_bos_ursula_bubble_single_3(UrsulaBubbleSingleWork* work) {
    func_0801B7D8(&work->unk_024);
#ifndef VERSION_EU
    ReleaseObjTiles((void*)work->tiles);
#endif
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
}

void func_080DDD30(UrsulaBubbleSingleWork* work) {
#ifdef VERSION_EU
    if (eu_080DA830() == 0) {
#else
    if (AnimGetId(&work->anim) == 0) {
#endif
        work->unk_134 = 0;
#ifdef VERSION_EU
        eu_080DA80C(1, 0);
#else
        AnimStart(&work->anim, 1, 0);
#endif
        func_0801C2DC(&work->unk_024, 1);
        work->unk_138 = 2;
    }
}

void task_bos_ursula_thunder_0(UrsulaThunderWork* work) {
    BtlObj* p = gBtlWork->actor;

    work->unk_004 = p->x;
    work->unk_008 = p->y;
    work->unk_00C = p->z - 0x6000;
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

u8 func_080DDDEC(UnkStruct_080DDDDC* p, UnkStruct_096FE034* q, u8 a) {
    if (p->unk_04 == 0) {
        p->unk_00++;

        if (p->unk_00 > q->unk_00[p->unk_02].unk_00) {
            p->unk_00 = 0;
            p->unk_02++;

            if (p->unk_02 >= q->unk_04) {
                p->unk_02 = 0;
            }
        }
    }

    if (a == 0) {
        if (p->unk_00 == 0 || p->unk_04 != 0) {
            RequestDma3Copy((u8*)q->unk_08 + q->unk_10 * q->unk_00[p->unk_02].unk_02,
                (u8*)GetBgCharBase(q->unk_14) + q->unk_0C, q->unk_0E);
            p->unk_04 = 0;
        }
    } else if (p->unk_00 == 0) {
        p->unk_04 = 1;
    }

    return a;
}

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

void func_080DDEA4(void) {
    func_080D2C78();
}

void func_080DDEB0(s32 a) {
    func_080D2DB0(a);
}

void func_080DDEBC(s32 a) {
    func_080D2DC4(a);
}
