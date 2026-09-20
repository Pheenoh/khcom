#include "registration_data.h"
#include "mode_test.h"
#include "mode_test_assets.h"
#include "gba/keys.h"

#ifndef VERSION_EU
static struct ObjTiles* gUnk_02034A08;
static struct ObjPalette* gUnk_02034A0C;
static s32 gUnk_02034A10;
#endif

#ifndef VERSION_EU
void mode_test_0(void) {
    gUnk_02034A10 = 0;
    gUnk_02034A08 = LoadObjTiles(gUnk_08B24DAA, 0x7C0);
    gUnk_02034A0C = LoadObjPalette(gUnk_08F69BA4, 0x20);
}
#endif

#ifndef VERSION_EU
void mode_test_1(void) {
    if (GetKeysRepeat() & DPAD_LEFT) {
        gUnk_02034A10--;
    } else if (GetKeysRepeat() & DPAD_RIGHT) {
        gUnk_02034A10++;
    }

    if (gUnk_02034A10 < 0) {
        gUnk_02034A10 = 0;
    }

    if (gUnk_02034A10 > 13) {
        gUnk_02034A10 = 13;
    }

    DrawSprite(120, 80, gUnk_09EE14D4[gUnk_02034A10], gUnk_02034A08, gUnk_02034A0C, 0, 0, 0);
}
#endif

#ifndef VERSION_EU
void mode_test_2(void) {
    ReleaseObjTiles(gUnk_02034A08);
    ReleaseObjPalette(gUnk_02034A0C);
}
#endif

void ApproachValueHalf(s32* p, s32 v) {
    *p += (v - *p) >> 1;
}

#ifdef VERSION_EU
u8 eu_08060C44(UnkModeTestWork* work) {
    UnkModeTestBody* body;

    body = &work->body;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->ground);
    body->z += work->velocity;
    work->velocity += 0x33;
    if (body->z > body->ground) {
        body->z = body->ground;
        work->velocity = 0;
        return 1;
    }
    return 0;
}

void eu_08060C8C(UnkModeTestWork* work, UnkModeTestArgs* args) {
    UnkModeTestBody* body;

    body = &work->body;
    if (args->side != 0) {
        work->side = 1;
        gBtlWork->unk_068 |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->side = args->side;
        gUnk_02039B9C->unk_068 |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }
    work->card = args->card;
    work->counter = 0;
    work->velocity = 0;
    if (work->actor->unk_034 & 4) {
        body->x = (gBtlWork->unk_0DC + 48) * 256;
        body->flags = 4;
    } else {
        body->x = (gBtlWork->unk_0DA - 48) * 256;
        body->flags = 0;
    }
    body->y = work->actor->y;
    body->z = 0;
    body->ground = 0;
    work->state = 0;
    work->targetX = work->actor->x;
    work->targetY = work->actor->y;
    work->palette = LoadObjPalette(gUnk_09849A98, 32);
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnkEu_08896524, &work->anim, 0, 0, work->tiles);
    ColliderInit(body->particles, 3, 10, 32);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 eu_08060DF8(UnkModeTestWork* work) {
    UnkModeTestBody* body;
    BtlWork* battle;

    body = &work->body;
    battle = work->side != 0 ? gBtlWork : gUnk_02039B9C;
    if (battle->unk_068 & 0x40000000) {
        return 0;
    }
    func_0802F284(body->x, body->y, body->z);
    switch (work->state) {
    case 0: {
        s32 flip = 0;
        u8 angle = GetAngle(body->x, body->y, work->targetX, work->targetY);
        switch (((angle + 16) & 255) >> 5) {
        case 0:
            func_08019068(gUnkEu_08896524, &work->anim, 4, 1, work->tiles);
            flip = 1;
            break;
        case 1:
            func_08019068(gUnkEu_08896524, &work->anim, 3, 1, work->tiles);
            flip = 1;
            break;
        case 2:
            func_08019068(gUnkEu_08896524, &work->anim, 2, 1, work->tiles);
            flip = 1;
            break;
        case 3:
            func_08019068(gUnkEu_08896524, &work->anim, 1, 1, work->tiles);
            flip = 1;
            break;
        case 4:
            func_08019068(gUnkEu_08896524, &work->anim, 0, 1, work->tiles);
            flip = 0;
            break;
        case 5:
            func_08019068(gUnkEu_08896524, &work->anim, 1, 1, work->tiles);
            flip = 0;
            break;
        case 6:
            func_08019068(gUnkEu_08896524, &work->anim, 2, 1, work->tiles);
            flip = 0;
            break;
        case 7:
            func_08019068(gUnkEu_08896524, &work->anim, 3, 1, work->tiles);
            flip = 0;
            break;
        }
        if (flip) body->flags |= 4;
        else body->flags &= ~4ULL;
        body->x += gSineTable[angle] * 128 >> 8;
        body->y += -gSineTable[angle + 64] * 128 >> 8;
        func_08011F78(110, body->x, body->y, body->z, 20, 10, 64);
        if ((body->x - work->targetX >= 0 ? body->x - work->targetX : work->targetX - body->x) < 0x800 &&
            (body->y - work->targetY >= 0 ? body->y - work->targetY : work->targetY - body->y) < 0x800) {
            work->targetX = (gBtlWork->unk_0DA + GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA + 1)) * 256;
            work->targetY = (gBtlWork->unk_0DE + GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE + 1)) * 256;
        }
        if ((u16)(GetRandom() % 300u) == 0) work->state = 1;
        break;
    }
    case 1: {
        u8 angle;
        work->targetX = work->actor->x;
        work->targetY = work->actor->y;
        func_08019068(gUnkEu_08896524, &work->anim, 5, 1, work->tiles);
        angle = GetAngle(body->x, body->y, work->targetX, work->targetY);
        if (work->targetX < body->x) body->flags |= 4;
        else body->flags &= ~4ULL;
        body->x += gSineTable[angle] * 0x133 >> 8;
        body->y += -gSineTable[angle + 64] * 0x133 >> 8;
        func_08011F78(110, body->x, body->y, body->z, 20, 10, 64);
        if (ColliderIsTouchingType(body->particles, 1)) {
            work->state = 2;
            ColliderSetDisabled(body->particles, 1);
            work->bob = 0;
        }
        break;
    }
    case 2:
        func_08019068(gUnkEu_08896524, &work->anim, 6, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            if (work->actor->unk_034 & 4) body->flags |= 4;
            else body->flags &= ~4ULL;
            if ((u16)(GetRandom() % 200u) == 0) work->state = 5;
        }
        if (body->flags & 4) body->x = work->actor->x + 0xA00;
        else body->x = work->actor->x - 0xA00;
        body->y = work->actor->y + 0x800;
        body->z = work->actor->z + work->bob;
        work->bob += (-0x1C00 - work->bob) >> 3;
        break;
    case 5:
        func_08019068(gUnkEu_08896524, &work->anim, 9, 0, work->tiles);
        if (work->actor->unk_034 & 4) body->flags |= 4;
        else body->flags &= ~4ULL;
        body->x = work->actor->x;
        body->y = work->actor->y + 0x800;
        body->z = work->actor->z + work->bob - 0xC00;
        if (work->counter > 180) {
            work->state = 6;
            work->counter = 120;
            work->animcounter = 0;
            work->scale = 0;
            func_08016C40(body->x, body->y, body->z - 0x1A00, 0x180, 0x80, 80);
        } else work->counter++;
        break;
    case 6: {
        s32 frame;
        if (work->actor->unk_034 & 4) body->flags |= 4;
        else body->flags &= ~4ULL;
        body->x = work->actor->x;
        body->y = work->actor->y + 0x800;
        body->z = work->actor->z + work->bob - 0xC00;
        frame = (work->animcounter >> 8) & 7;
        func_08019068(gUnkEu_08896524, &work->anim, frame + 10, 0, work->tiles);
        ApproachValue(&work->animcounter, 0x800, work->counter);
        ApproachValue(&work->scale, 0x10000, work->counter);
        func_080147B8(-(work->scale >> 8) - 128);
        func_08014780(body->x, body->y, body->z - 0x1A00);
        if (--work->counter <= 0) {
            work->state = 3;
            work->counter = 0;
            work->velocity = -0x380;
            work->speed = 0x500;
            work->bounce = 0;
        }
        break;
    }
    case 3:
        func_08019068(gUnkEu_08896524, &work->anim, 7, 0, work->tiles);
        if (body->flags & 4) body->x -= work->speed;
        else body->x += work->speed;
        work->speed -= 0x33;
        if (work->speed <= 0) {
            work->speed = 0;
            if (AnimIsFinished(&work->anim)) {
                work->state = 4;
                ColliderSetDisabled(body->particles, 0);
            }
        }
        if (eu_08060C44(work) && !work->bounce) {
            work->bounce = 1;
            func_0802F1E8();
        }
        func_08011F78(162, body->x, body->y, body->z, 30, 25, 10);
        break;
    case 4:
        func_08019068(gUnkEu_08896524, &work->anim, 8, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) work->state = 0;
        break;
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    ColliderSetPosition(body->particles, body->x, body->y, body->z);
    return 1;
}

void eu_08061588(UnkModeTestWork* work) {
    UnkModeTestBody* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;

    body = &work->body;
    gfx = AnimGetGfx(&work->anim);
    flags = GetBattleSpritePriorityFlags(body->y);

    if (body->flags & 4) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
    } else if (gBtlWork->unk_024 == 256) {
        sclY = gBtlWork->unk_024;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->unk_024;
        sclY = gBtlWork->unk_024;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->unk_024 == 256) {
        affine = 0;
    } else if (gBtlWork->unk_024 <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               (u16)(-4100 - ((body->y >> 8) * 4)));
    body->depth = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}


void eu_08061698(UnkModeTestWork* work) {
    BtlWork* battle;

    ColliderUnregister(work->body.particles);
    battle = work->side != 0 ? gBtlWork : gUnk_02039B9C;
    battle->unk_068 &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}
#endif

#ifndef VERSION_EU
const char gModeNameTest[] = "mode_test";

Mode gUnk_09EDE4E0 = { gModeNameTest, (void (*)(s32))mode_test_0, mode_test_1, mode_test_2 };
#endif

#ifdef VERSION_EU
const char gTaskNameFrdPoohEu[] = "task_frd_pooh";

TaskDesc gTaskDescFrdPoohEu = {
    gTaskNameFrdPoohEu,
    (void (*)(void*, void*))eu_08060C8C,
    (u8 (*)(void*))eu_08060DF8,
    (void (*)(void*))eu_08061588,
    (void (*)(void*))eu_08061698,
    sizeof(UnkModeTestWork),
};
#endif
