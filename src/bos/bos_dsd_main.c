#include "bos2.h"
#include "boss_map_block_assets.h"
#include "sprites_bos2.h"
#include "sprites_btl.h"

extern const u16* gUnk_09EF2AA4[46][4];
extern void* gUnk_09EF2D94[37];
extern const u16* gUnk_09EF2E68[4];

void func_080C211C(u8 index) {
    SetBgMapBlocks(1, gUnk_09EF2AA4[index], 2, 2);
}

void func_080C213C(u8 index, u16 a) {
    SetBgMapBlocks(1, gUnk_09EF2AA4[index], 2, 2);
    LoadBgTiles(1, gUnk_09EF2D94[index], a * 32);
}

void task_bos_dsd_main_0(DsdMainWork* work, DsdWork* arg) {
    BtlObj* s = &work->body;

    work->dsd = arg;
    SetBgPriority(1, 1);
    SetBgPriority(0, 3);
    work->dsd->unk_334 = arg->unk_334;
    work->unk_008 = 0;
    work->unk_006 = 0;
    work->unk_004 = 0;
    work->unk_00A = 0;
    work->unk_054 = 1;
    work->unk_06C = 0;
    work->unk_070 = gBtlWork->unk_1CA;
    SetBgMapBlocks(1, gUnk_09EF2AA4, 2, 2);
    work->tiles = LoadObjTiles(gUnk_096983E4, 0x12A0);
    AnimInit(&work->anim, gUnk_09EF3C34, gUnk_09EF3C20);
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
    arg->body[0].y++;
    arg->body[0].y--;
    work->tiles2 = LoadObjTiles(gUnk_096983E4, 0x12A0);
    AnimInit(&work->anim2, gUnk_09EF3C4C, gUnk_09EF3C38);
    AnimStart(&work->anim2, 0, 1);
    work->gfx2 = AnimGetGfx(&work->anim2);
    work->palette = LoadObjPalette(gUnk_096FB8C4, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->dsd->tiles = AllocObjTiles(0x800, gUnk_096A2F04);
    work->dsd->palette = LoadObjPalette(gUnk_096FB8E4, 32);
    work->dsd->tiles2 = LoadObjTiles(gUnk_096869A4, 0x740);
    work->dsd->palette2 = LoadObjPalette(gUnk_096FB864, 32);
    work->dsd->palette3 = LoadObjPalette(gUnk_096FB884, 32);
    work->dsd->tiles3 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->dsd->palette4 = LoadObjPalette(gBStatesPalette, 32);
    s->x = 0xDC00;
    s->y = 0x16800;
    s->z = 0;
    ColliderInit(&s->collider, 8, 24, 100);
    ColliderSetPosition(&s->collider, s->x, s->y, s->z);
    ScrollBgMapTo(1, ((gBtlWork->unk_000 - arg->body[0].x) >> 8) + 100,
                  ((gBtlWork->unk_004 - (arg->body[0].y + arg->body[0].z)) >> 8) + 280);
    TaskPoolInit(&work->tasks, 10);
    func_080C2828(work);
}

u8 task_bos_dsd_main_1(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* p = &work->body;

    func_080C2734(work);

    switch (work->dsd->unk_334) {
    case 0:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2BB0(work);
        break;
    case 1:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2944(work);
        break;
    case 2:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2A2C(work);
        break;
    case 3:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2CC0(work);
        break;
    case 4:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2FD8(work);
        break;
    case 5:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C3188(work);
        break;
    case 6:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C3574(work);
        break;
    case 7:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C3754(work);
        break;
    case 8:
        func_080C386C(work);
        break;
    case 9:
        func_080C3C34(work);
        break;
    case 10:
        func_080C3868(work);
        break;
    case 11:
        func_080C3928(work);
        break;
    }

    ColliderSetPosition(&d->body[0].collider, d->body[0].x, d->body[0].y, d->body[0].z);
    ColliderSetPosition(&p->collider, p->x, p->y, p->z);
    TaskPoolUpdate(&work->tasks);
    work->unk_070 = gBtlWork->unk_1CA;

    return 1;
}

void task_bos_dsd_main_2(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    void* gfx;
    s16 x;
    s16 y;

    if (gBtlWork->unk_070 != 0) {
        LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
        gfx = work->palette;
    } else if (d->flags & 1) {
        if (gFrameCounter & 1) {
            LoadPaletteWithEffect(gUnk_08F69BC4, (void*)0x05000000, 32);
            gfx = work->palette2;
        } else {
            LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
            gfx = work->palette;
        }
    } else {
        gfx = work->palette;
    }

    ScrollBgMapTo(1, ((gBtlWork->unk_000 - d->body[0].x) >> 8) + 100,
                  ((gBtlWork->unk_004 - (d->body[0].y + d->body[0].z)) >> 8) + 280);

    if (work->unk_054 == 1) {
        GetBattleSpritePriorityFlags(d->body[0].y);
        WorldToScreen(&x, &y, d->body[0].x, d->body[0].y, -0x6400);
        DrawSprite(x - 96, y + 20, work->gfx, work->tiles, gfx, 0, 0x400,
                   (u16)(-4101 - (d->body[0].y >> 8) * 4));
        DrawSprite(x - 96, y + 20, work->gfx2, work->tiles2, gfx, 0, 0x800,
                   (u16)(-4099 - (d->body[0].y >> 8) * 4));
    }

    TaskPoolDraw(&work->tasks);
}

void task_bos_dsd_main_3(DsdMainWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    ReleaseObjTiles(work->dsd->tiles);
    ReleaseObjPalette(work->dsd->palette);
    ReleaseObjTiles(work->dsd->tiles2);
    ReleaseObjPalette(work->dsd->palette2);
    ReleaseObjPalette(work->dsd->palette3);
    ReleaseObjTiles(work->dsd->tiles3);
    ReleaseObjPalette(work->dsd->palette4);
    ColliderUnregister(&work->body.collider);
    TaskPoolDestroy(&work->tasks);
}

void func_080C2734(DsdMainWork* work) {
    BtlObj* q = &work->dsd->body[1];

    if (q->unk_02C > 0) {
        if (GetRandom() % 30 == 0) {
            TaskCreate(&work->tasks, &gTaskDescBosDsdRock, work->dsd);
        }

        if ((work->dsd->flags & 0x20) == 0) {
            gBtlWork->actor->x += work->dsd->unk_35C;
        }

        if (work->unk_070 != (s8)gBtlWork->unk_1CA) {
            if ((s8)gBtlWork->unk_1CA > 0) {
                work->dsd->flags |= 0x40;

                if ((s8)gBtlWork->unk_1CA > 14) {
                    work->dsd->unk_35C = 0x180;
                } else {
                    work->dsd->unk_35C = ((s8)gBtlWork->unk_1CA << 8) / 10;
                }
            } else if ((s8)gBtlWork->unk_1CA < 0) {
                work->dsd->flags |= 0x40;
                work->dsd->unk_35C = ((s8)gBtlWork->unk_1CA << 9) / 10;
            } else {
                work->dsd->flags &= ~0x40;
            }
        } else {
            work->dsd->flags &= ~0x40;
        }
    }
}

void func_080C2828(DsdMainWork* work) {
    DsdWork* p = work->dsd;
    BtlObj* q = &p->body[1];

    p->unk_354 = 0;
    work->unk_00A = 0;
    work->dsd->unk_356 = 0;
    func_080C213C(0, 0x60);
    work->unk_054 = 1;
    AnimStart(&work->anim, 0, 1);
    AnimStart(&work->anim2, 0, 1);
    p->body[0].z = -0x6400;
    q->z = -0x8C00;
}

void func_080C288C(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    if (d->unk_356 >= gUnk_0961A7D0[d->unk_354]) {
        d->unk_356 = 0;
        work->dsd->unk_354++;

        if (work->dsd->unk_354 > work->unk_00A + 7) {
            work->dsd->unk_354 = work->unk_00A;
        }

        func_080C213C(work->dsd->unk_354, 0x60);
        d->body[0].z += gUnk_0961A82E[work->dsd->unk_354] << 8;
        q->z += gUnk_0961A82E[work->dsd->unk_354] << 8;
    }

    work->dsd->unk_356++;
    work->gfx = AnimUpdate(&work->anim);
    work->gfx2 = AnimUpdate(&work->anim2);
}

void func_080C2944(DsdMainWork* work) {
    func_080C288C(work);

    if (gBtlWork->unk_0A0 != 0) {
        if (GetRandom() % 80 == 0) {
            func_080C3C40(work);
        }
    }
}

void func_080C297C(DsdMainWork* work, s32 x, s32 y, s32 z) {
    BtlObj* q = &work->dsd->body[1];

    FadeSetPaletteExcluded(0, 0);
    FadeSetPaletteExcluded(0x13, 0);
    FadeToAmount(0, 0x14, 8);
    func_08018B04(x - 0x1400, y, z - 0xA00, 0x100);
    m4aSongNumStart(SONG_SND_721);
    q->flags |= 0x01000000;
}

void func_080C29F4(DsdMainWork* work) {
    BtlObj* q = &work->dsd->body[1];

    FadeToOriginal(0, 8);
    FadeSetPaletteExcluded(0, 1);
    FadeSetPaletteExcluded(19, 1);
    q->flags &= ~0x1000000;
}

void func_080C2A2C(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];
    BtlObj* p = &work->body;

    switch (d->unk_350) {
    case 0:
        func_080C297C(work, d->body[0].x, d->body[0].y, d->body[0].z);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 1:
        work->unk_006++;

        if (work->unk_006 > 11) {
            DisableBg(1);
            work->unk_054 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 2:
        switch (d->unk_338) {
        case 4:
        case 5:
            CreateBgTileTransferTask(&work->tasks, 1, 0, 0x2C8, 8, (u32)gUnk_09699684);
            break;
        case 6:
            CreateBgTileTransferTask(&work->tasks, 1, 0, 0x280, 8, (u32)gUnk_096A3F44);
            break;
        case 7:
            CreateBgTileTransferTask(&work->tasks, 1, 0, 0x200, 8, (u32)gUnk_096A8BA4);
            break;
        }

        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 9) {
            work->unk_006 = 0;
            d->unk_350++;
        }
        break;
    default:
        work->dsd->unk_350 = 0;

        switch (work->dsd->unk_338) {
        case 4:
        case 5:
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = -0x4000;
            work->dsd->unk_334 = 3;
            break;
        case 6:
            p->x = 0xBC00;
            p->y = 0x16800;
            p->z = 0;
            work->dsd->unk_334 = 6;
            break;
        case 7:
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = 0;
            work->dsd->unk_334 = 7;
            break;
        }

        q->flags &= ~0x1000000;
        break;
    }
}

void func_080C2BB0(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];
    BtlObj* p = &work->body;

    switch (d->unk_350) {
    case 0:
        func_080C297C(work, d->body[0].x, d->body[0].y, d->body[0].z);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 1:
        work->unk_006++;

        if (work->unk_006 > 4) {
            DisableBg(1);
            work->dsd->unk_350++;
        }
        break;
    case 2:
        CreateBgTileTransferTask(&work->tasks, 1, 0, 0x120, 3, (u32)gUnk_096874E4);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            func_080C2828(work);
            d->body[0].x = 0xDC00;
            q->x = 0xDC00;
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = 0;
            work->dsd->unk_350++;
        }
        break;
    case 4:
        if (func_080128EC() == 0) {
            func_080C29F4(work);
            work->dsd->unk_350++;
        }
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 1;
        break;
    }
}

void func_080C2CC0(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 8;
        work->unk_00A = 8;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        work->unk_004 = 30;
        func_080C213C(8, 0x80);
        EnableBg(1);
        d->body[0].x = 0x13C00;
        d->body[0].y = 0x16800;
        d->body[0].z = -0xAC00;
        q->x = 0x13C00;
        q->y = 0x16800;
        q->z = -0xD400;
        work->dsd->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->dsd->unk_350++;
        break;
    case 2:
        if ((s16)work->unk_004 > 0) {
            ApproachValue(&d->body[0].x, 0xDC00, work->unk_004);
            ApproachValue(&d->body[0].z, -0x9400, work->unk_004);
            ApproachValue(&q->x, 0xDC00, work->unk_004);
            ApproachValue(&q->z, -0xBC00, work->unk_004);
            func_0802F274(d->body[0].x, d->body[0].y + d->body[0].z);
            work->unk_004--;
        } else {
            work->unk_006 = 0;
            work->dsd->unk_354 = 9;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xEC00;
            q->z = -0x9400;
            work->dsd->unk_350++;
        }
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->dsd->unk_354 = 10;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xFC00;
            q->z = -0x9400;
            work->dsd->unk_350++;
        }
        break;
    case 4:
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += 0x100;
            d->body[0].z += -0x100;
            work->dsd->unk_350++;
        }
        break;
    case 5:
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += -0x100;
            d->body[0].z += 0x100;
            work->dsd->unk_350++;
        }
        break;
    case 6:
        work->unk_006++;

        if (work->unk_006 > 25) {
            work->unk_006 = 0;
            work->dsd->unk_354 = 11;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xEC00;
            q->z = -0x9400;
            work->dsd->unk_350++;
        }
        break;
    case 7:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->dsd->unk_354 = 12;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xB400;
            q->z = -0x8400;
            work->dsd->unk_350++;
        }
        break;
    case 8:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->dsd->unk_350++;
        }
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = work->dsd->unk_338;
        break;
    }
}

void func_080C2F68(DsdMainWork* work) {
    if (work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
        work->dsd->unk_356 = 0;
        work->dsd->unk_354++;

        if (work->dsd->unk_354 > work->unk_00A + 7) {
            work->dsd->unk_354 = work->unk_00A;
        }

        func_080C213C(work->dsd->unk_354, 0x80);
    }

    work->dsd->unk_356++;
}

void func_080C2FD8(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 13;
        work->unk_00A = 13;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        func_080C213C(13, 0x80);
        b->x = 0x7600;
        b->y = 0x16800;
        b->z = 0;
        b->flags &= ~0x1000000;
        func_0802F1E8();
        m4aSongNumStart(SONG_EF_AIRO);
        func_0801801C(0x7800, 0x16800, 0, 0x100);
        ColliderSetDisabled(&b->collider, 0);
        work->dsd->unk_350++;
        break;
    case 1:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += -0x100;
            d->body[0].z += 0x100;
            work->dsd->unk_350++;
        }
        break;
    case 2:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += 0x100;
            d->body[0].z += -0x100;
            work->dsd->unk_350++;
        }
        break;
    case 3:
        func_080C2F68(work);

        if (func_080128EC() == 0) {
            func_0801AF08(a);
            work->unk_006 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 4:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 179) {
            work->unk_006 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 5:
        func_080C213C(8, 0x80);
        b->flags |= 0x1000000;
        ColliderSetDisabled(&b->collider, 1);
        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3188(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];
    BtlObj* e;

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 21;
        work->unk_00A = 21;
        work->dsd->unk_356 = 0;
        func_080C213C(work->dsd->unk_354, 0x80);
        TaskCreate(&work->tasks, &gTaskDescBosDsdCircle, work->dsd);
        func_080147D8(0x8000, 0x15400);
        func_08011F78(0x101, 0x8000, 0x16800, -0x1400, 16, 16, 16);
        m4aSongNumStart(SONG_EF_DS_BEEM);
        work->dsd->unk_350++;
        break;
    case 1:
        if (++work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
            work->dsd->unk_356 = 0;
            work->dsd->unk_354++;
            a->z += 0x600;

            if (work->dsd->unk_354 > work->unk_00A + 6) {
                work->dsd->unk_354 = work->unk_00A + 6;
                work->dsd->unk_350++;
            }

            func_080C213C(work->dsd->unk_354, 0x80);
        }
        break;
    case 2:
        work->dsd->unk_354 = 28;
        work->unk_00A = 28;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        func_0801AF08(a);
        b->x = 0x9000;
        b->y = 0x16800;
        b->z = 0;
        b->flags &= ~0x1000000;
        work->dsd->unk_350++;
        break;
    case 3:
        if (++work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
            work->dsd->unk_356 = 0;
            work->dsd->unk_354++;

            if (work->dsd->unk_354 > work->unk_00A + 6) {
                work->dsd->unk_354 = work->unk_00A;
            }

            func_080C213C(work->dsd->unk_354, 0x80);
        }

        work->unk_006++;

        if (work->unk_006 > 299) {
            work->dsd->unk_350++;
        }
        break;
    case 4:
        work->dsd->unk_354 = 27;
        work->unk_00A = 27;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        b->flags |= 0x1000000;
        work->dsd->unk_350++;
        break;
    case 5:
        if (++work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
            work->dsd->unk_356 = 0;
            work->dsd->unk_354--;
            a->z -= 0x600;

            if (work->dsd->unk_354 < work->unk_00A - 6) {
                work->dsd->unk_354 = work->unk_00A - 6;

                if (gBtlWork->unk_0EC <= 0 && (work->dsd->flags & 8) == 0) {
                    _0801C1F8(0, d->body[0].x, d->body[0].y, d->body[0].z);
                }

                work->dsd->unk_350++;
            }

            func_080C213C(work->dsd->unk_354, 0x80);
        }
        break;
    case 6:
        work->unk_006 = 0;
        func_080C213C(8, 0x80);
        e = ListPoolFirst(&gBtlWork->pool);

        while (e != 0) {
            if (e->unk_000 == 0) {
                e->flags |= 0x40;
                m4aSongNumStart(SONG_BTL_DARKDEAD);
            }

            e = ListPoolNext(&e->node);
        }

        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3504(DsdMainWork* work) {
    if (work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
        work->dsd->unk_356 = 0;
        work->dsd->unk_354++;

        if (work->dsd->unk_354 > work->unk_00A + 4) {
            work->dsd->unk_354 = work->unk_00A;
        }

        func_080C211C(work->dsd->unk_354);
    }

    work->dsd->unk_356++;
}

void func_080C3574(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 36;
        work->unk_00A = 36;
        work->dsd->unk_356 = 0;
        work->unk_004 = 30;
        work->unk_054 = 0;
        func_080C211C(work->dsd->unk_354);
        q->x = 0xDC00;
        q->z = -0x6000;
        work->dsd->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_006 = 0;
        work->unk_004 = 0;
        work->dsd->unk_350++;
        break;
    case 2:
        func_080C3504(work);
        work->unk_184 = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy1, work->dsd);
        work->dsd->unk_350++;
        break;
    case 3:
        func_080C3504(work);

        if (IsTaskActive(work->unk_184) != 0) {
            break;
        }

        if (work->dsd->unk_35A == 0) {
            work->dsd->unk_350 = 6;
            break;
        }

        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            work->unk_188 = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy1, work->dsd);
            work->dsd->unk_350++;
        }
        break;
    case 4:
        func_080C3504(work);

        if (IsTaskActive(work->unk_188) != 0) {
            break;
        }

        if (work->dsd->unk_35A == 1) {
            work->dsd->unk_350 = 6;
            break;
        }

        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            work->unk_18C = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy1, work->dsd);
            work->dsd->unk_350++;
        }
        break;
    case 5:
        func_080C3504(work);

        if (IsTaskActive(work->unk_18C) != 0) {
            break;
        }

        work->dsd->unk_350++;
        break;
    case 6:
        func_080C3504(work);
        func_0801AF08(q);
        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3754(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 41;
        work->unk_00A = 41;
        work->dsd->unk_356 = 0;
        work->unk_004 = 30;
        work->unk_054 = 0;
        func_080C211C(work->dsd->unk_354);
        work->unk_006 = 0;
        q->x = 0xE400;
        q->z = -0x5C00;
        work->dsd->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_004 = 0;
        work->dsd->unk_350++;
        break;
    case 2:
        func_080C3504(work);
        LoadPalette(gUnk_096FB744, (void*)0x05000000, 32);
        work->unk_06C = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy2, work->dsd);
        work->dsd->unk_350++;
        break;
    case 3:
        func_080C3504(work);

        if (IsTaskActive(work->unk_06C) != 0) {
            break;
        }

        work->dsd->unk_350++;
        break;
    case 4:
        func_080C3504(work);
        func_0801AF08(q);
        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3868(DsdMainWork* work) {
}

void func_080C386C(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];

    if (d->unk_330 == 2 || d->unk_330 == 3) {
        func_0801AF08(a);
        b->flags |= 0x1000000;
        ColliderSetDisabled(&b->collider, 1);
        work->dsd->unk_350 = 0;
        work->dsd->unk_334 = 0;
    } else if (d->unk_350 > 60) {
        func_0801AF08(a);
        b->flags |= 0x1000000;
        ColliderSetDisabled(&b->collider, 1);
        work->dsd->unk_350 = 0;
        work->dsd->unk_334 = 0;
    } else {
        d->unk_350++;
    }
}

void func_080C3928(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];
    BtlObj* c = &work->body;
    BtlObj* e;
    CharaObjParam param;

    switch (d->unk_350) {
    case 0:
        e = ListPoolFirst(&gBtlWork->pool);

        while (e != 0) {
            if (e->unk_000 == 0) {
                e->flags |= 0x40;
                m4aSongNumStart(SONG_BTL_DARKDEAD);
            }

            e = ListPoolNext(&e->node);
        }

        work->dsd->unk_350++;
        break;
    case 1:
        func_0801AF4C(a);
        ColliderSetDisabled(&a->collider, 1);
        ColliderSetDisabled(&b->collider, 1);
        ColliderSetDisabled(&c->collider, 1);
        FadeSetPaletteExcluded(0, 0);
        FadeSetPaletteExcluded(19, 0);
        FadeToAmount(0, 20, 8);
        func_08018B04(a->x - 0x1400, a->y, a->z - 0xA00, 0x100);
        m4aSongNumStart(SONG_SND_721);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        break;
    case 2:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        work->unk_006++;

        if (work->unk_006 > 11) {
            DisableBg(1);
            work->unk_054 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 3:
        func_080C213C(36, 0xE0);
        EnableBg(1);
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        work->dsd->unk_350++;
        break;
    case 4:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);

        if (func_080128EC() != 0) {
            break;
        }

        FadeToOriginal(0, 8);
        FadeSetPaletteExcluded(0, 1);
        FadeSetPaletteExcluded(19, 1);
        work->dsd->unk_350++;
        break;
    case 5:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        work->dsd->unk_350++;
        break;
    case 6:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        param.unk_00 = 0;
        param.unk_04 = 0;
        param.unk_08 = 0;
        param.unk_0C = 0;
        param.unk_10 = 0;
        param.unk_14 = 0;
        param.unk_18 = 0;
        param.unk_1C = 0;
        param.unk_20 = 0x6000000;
        param.unk_24 = 0xE0;
        param.unk_28 = 0x5000000;
        param.unk_2C = 32;
        param.unk_30 = d->body[0].x - 0x1400;
        param.unk_34 = d->body[0].y;
        param.unk_38 = d->body[0].z + 0x3000;
        param.unk_3C = 0;
        param.unk_40 = (u32)a;
        param.unk_44 = 1;
        func_080C6894(&param);
        work->dsd->unk_350++;
        break;
    case 7:
        if (func_080C69B4() == 0) {
            d->body[0].x = 300;
            d->body[0].y = 0;
            d->body[0].z = 0;
            ScrollBgMapTo(1, ((gBtlWork->unk_000 - 300) >> 8) + 100, (gBtlWork->unk_004 >> 8) + 280);
            func_0801B008();
            work->dsd->unk_350++;
        } else {
            func_0802F274(d->body[0].x - 0x1800, d->body[0].y + d->body[0].z + 0x3000);
        }
        break;
    default:
        d->flags |= 2;
        break;
    }
}

void func_080C3C34(DsdMainWork* work) {
    func_080C288C(work);
}

void func_080C3C40(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];

    if (a->unk_02C < a->unk_02E / 3) {
        d->unk_35A = 2;

        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 49) {
            func_08083900(GetRandom() % 2 + 8);
        } else {
            func_08083900(GetRandom() % 3 + 5);
        }
    } else if (a->unk_02C < a->unk_02E / 3 * 2) {
        d->unk_35A = 1;

        if (GetRandom() % 100 <= 29) {
            func_08083900(GetRandom() % 2 + 8);
        } else {
            func_08083900(GetRandom() % 3 + 4);
        }
    } else {
        d->unk_35A = 0;

        if (GetRandom() % 100 <= 59) {
            func_08083900(GetRandom() % 3 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }
    }

    switch (work->dsd->unk_33C) {
    case 0:
        work->dsd->unk_338 = 5;
        break;
    case 1:
        work->dsd->unk_338 = 6;
        break;
    case 2:
        work->dsd->unk_338 = 4;
        break;
    case 3:
        work->dsd->unk_338 = 7;
        break;
    default:
        work->dsd->unk_338 = 0;
        break;
    }

    work->dsd->unk_33C++;

    if (work->dsd->unk_33C > 3) {
        work->dsd->unk_33C = 0;
    }

    func_0801BCD4(a);
}

void task_bos_dsd_map_0(void) {
    LoadBgTiles(0, gUnk_096874E4, 0x8000);
    LoadBgPalette(0, gUnk_096FB744, 0x120);
    SetBgMapBlocks(0, gUnk_09EF2E68, 2, 2);
    gBtlWork->scale = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0xA000;
    gBtlWork->y = 0x13600;
    gBtlWork->unk_000 = 0xA000;
    gBtlWork->unk_004 = 0x13600;
    gBtlWork->x2 = 0xA000;
    gBtlWork->y2 = 0x13600;
    gBtlWork->unk_01C = 0xA000;
    gBtlWork->unk_020 = 0x13600;
    gBtlWork->unk_01A = 0xF;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    ScrollBgMapTo(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}

u8 task_bos_dsd_map_1(void) {
    s32 dx;
    s32 dy;

    func_0802F208();
    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gBtlWork->unk_000 < (gBtlWork->unk_0DA + 0x78) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x78) << 8;
    } else if (gBtlWork->unk_000 > (gBtlWork->unk_0DC - 0x78) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x78) << 8;
    }

    if (gBtlWork->unk_004 < 0x5000) {
        gBtlWork->unk_004 = 0x5000;
    } else if (gBtlWork->unk_004 > (gBtlWork->unk_0E0 - 0x50) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 0x50) << 8;
    }

    gBtlWork->unk_004 += func_0802F268();
    ScrollBgMapTo(0, (gBtlWork->unk_000 >> 8) - 0x78, (gBtlWork->unk_004 >> 8) - 0x28);

    return 1;
}

const s16 gUnk_0961A7D0[47] = {
    10, 10, 10, 10, 10, 10, 10, 10, 4, 2, 2, 10, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 4, 4, 4, 4, 4, 4, 4, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0,
};

const s8 gUnk_0961A82E[10] = { -1, 1, 1, 1, 1, -1, -1, -1, 0, 0 };

const char gTaskNameBosDsdMain[] = "task_bos_dsd_main";

const char gTaskNameBosDsdMap[] = "task_bos_dsd_map";

const u16* gUnk_09EF2AA4[46][4] = {
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E3C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E5464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E5C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E5464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E7464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E6C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E6464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E6C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E7464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E7C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E9464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E9C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E9464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EA464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EAC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EB464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EBC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EC464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096ECC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096ED464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EDC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EE464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EEC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EF464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EFC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EF464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EEC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EE464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F0464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F0C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F1464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F1C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F2464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F2C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F3464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F3C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F4464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F4C64, gUnk_08125E24 },
};

const u16* gUnk_09EF2D84 = gUnk_08125E24;

const u16* gUnk_09EF2D88 = gUnk_08125E24;

const u16* gUnk_09EF2D8C = gUnk_08125E24;

const u16* gUnk_09EF2D90 = gUnk_08125E24;

void* gUnk_09EF2D94[37] = {
    gUnk_096874E4,
    gUnk_0968F4E4,
    gUnk_096918A4,
    gUnk_09693C64,
    gUnk_09696024,
    gUnk_09693C64,
    gUnk_096918A4,
    gUnk_0968F4E4,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_0969EF04,
    gUnk_0969FF04,
    gUnk_096A0F04,
    gUnk_096A1F04,
    gUnk_096A0F04,
    gUnk_0969FF04,
    gUnk_0969EF04,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_0969EF04,
    gUnk_0969FF04,
    gUnk_096A0F04,
    gUnk_096A1F04,
    gUnk_096A0F04,
    gUnk_0969FF04,
    gUnk_0969EF04,
    gUnk_096A3F44,
};

void* gUnk_09EF2E28 = gUnk_096A3F44;

void* gUnk_09EF2E2C = gUnk_096A3F44;

void* gUnk_09EF2E30 = gUnk_096A3F44;

void* gUnk_09EF2E34 = gUnk_096A3F44;

void* gUnk_09EF2E38 = gUnk_096A8BA4;

void* gUnk_09EF2E3C = gUnk_096A8BA4;

void* gUnk_09EF2E40 = gUnk_096A8BA4;

void* gUnk_09EF2E44 = gUnk_096A8BA4;

void* gUnk_09EF2E48 = gUnk_096A8BA4;

void* gUnk_09EF2E4C = 0;

TaskDesc gTaskDescBosDsdMain = {
    gTaskNameBosDsdMain,
    (TaskInitFunc)task_bos_dsd_main_0,
    (TaskUpdateFunc)task_bos_dsd_main_1,
    (TaskFunc)task_bos_dsd_main_2,
    (TaskFunc)task_bos_dsd_main_3,
    0x190,
};

const u16* gUnk_09EF2E68[4] = {
#if defined(VERSION_US)
    gBossMapBlockUs_096E2C64,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_096E3464,
    gBossMapBlockUs_08125E24,
#elif defined(VERSION_JP)
    gBossMapBlockJp_0969B440,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_0969BC40,
    gBossMapBlockJp_08125EA0,
#elif defined(VERSION_EU)
    gBossMapBlockEu_096AA98C,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_096AB18C,
    gBossMapBlockEu_08124944,
#endif
};

TaskDesc gTaskDescBosDsdMap = {
    gTaskNameBosDsdMap,
    (TaskInitFunc)task_bos_dsd_map_0,
    (TaskUpdateFunc)task_bos_dsd_map_1,
    0,
    0,
    0x4,
};
