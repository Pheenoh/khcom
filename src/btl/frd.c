#include "task_descriptors.h"
#include "system_state.h"
#include "display.h"
#include "frd.h"
#include "task_animation_assets.h"
#include "sprites_evt.h"
#include "sprites_frd.h"
#include "world_types.h"

const AnimDef gFrdDonaldAnimDefs[6] = {
    { gUnk_09EDE548, gUnk_09EDE584, gUnk_088724E2, 0, { 0, 0, 0 } },
    { gUnk_09EDE548, gUnk_09EDE584, gUnk_088724E2, 1, { 0, 0, 0 } },
    { gUnk_09EDE548, gUnk_09EDE584, gUnk_088724E2, 2, { 0, 0, 0 } },
    { gUnk_09EDE548, gUnk_09EDE584, gUnk_088724E2, 3, { 0, 0, 0 } },
    { gUnk_09EEE03C, gUnk_09EEE0A8, gUnk_0919FDF8, 5, { 0, 0, 0 } },
    { gUnk_09EEE0C4, gUnk_09EEE170, gUnk_091A4386, 2, { 0, 0, 0 } },
};

TaskDesc gTaskDescFrdDonald = { "task_frd_donald", task_frd_donald_0, task_frd_donald_1, task_frd_donald_2, task_frd_donald_3, 0x164 };

const AnimDef gFrdGoofyAnimDefs[5] = {
    { gUnk_09EDE538, gUnk_09EDE540, gUnk_088717D8, 0, { 0, 0, 0 } },
    { gUnk_09EDE538, gUnk_09EDE540, gUnk_088717D8, 1, { 0, 0, 0 } },
    { gUnk_09EDE518, gUnk_09EDE534, gUnk_0886E396, 0, { 0, 0, 0 } },
    { gUnk_09EDE4F0, gUnk_09EDE50C, gUnk_0886ADEC, 1, { 0, 0, 0 } },
    { gUnk_09EDE4F0, gUnk_09EDE50C, gUnk_0886ADEC, 2, { 0, 0, 0 } },
};

TaskDesc gTaskDescFrdGoofy = { "task_frd_goofy", task_frd_goofy_0, task_frd_goofy_1, task_frd_goofy_2, task_frd_goofy_3, 0x164 };

const AnimDef gFrdArielAnimDefs[3] = {
    { gUnk_09EDE5C8, gUnk_09EDE5F0, gUnk_088777F6, 0, { 0, 0, 0 } },
    { gUnk_09EDE5C8, gUnk_09EDE5F0, gUnk_088777F6, 1, { 0, 0, 0 } },
    { gUnk_09EDE5C8, gUnk_09EDE5F0, gUnk_088777F6, 2, { 0, 0, 0 } },
};

TaskDesc gTaskDescFrdAriel = { "task_frd_ariel", task_frd_ariel_0, task_frd_ariel_1, task_frd_ariel_2, task_frd_ariel_3, 0x164 };

const AnimDef gFrdJackAnimDefs[5] = {
    { gUnk_09EDE594, gUnk_09EDE5B4, gUnk_08875122, 0, { 0, 0, 0 } },
    { gUnk_09EDE594, gUnk_09EDE5B4, gUnk_08875122, 1, { 0, 0, 0 } },
    { gUnk_09EDE594, gUnk_09EDE5B4, gUnk_08875122, 2, { 0, 0, 0 } },
    { gUnk_09EDE594, gUnk_09EDE5B4, gUnk_08875122, 3, { 0, 0, 0 } },
    { gUnk_09EDE594, gUnk_09EDE5B4, gUnk_08875122, 4, { 0, 0, 0 } },
};

TaskDesc gTaskDescFrdJack = { "task_frd_jack", task_frd_jack_0, task_frd_jack_1, task_frd_jack_2, task_frd_jack_3, 0x16C };

const AnimDef gFrdPanAnimDefs[4] = {
    { gUnk_09EDE63C, gUnk_09EDE654, gUnk_088801BE, 0, { 0, 0, 0 } },
    { gUnk_09EDE63C, gUnk_09EDE654, gUnk_088801BE, 1, { 0, 0, 0 } },
    { gUnk_09EDE63C, gUnk_09EDE654, gUnk_088801BE, 2, { 0, 0, 0 } },
    { gUnk_09EDE63C, gUnk_09EDE654, gUnk_088801BE, 3, { 0, 0, 0 } },
};

TaskDesc gTaskDescFrdPan = { "task_frd_pan", task_frd_pan_0, task_frd_pan_1, task_frd_pan_2, task_frd_pan_3, 0x170 };

const AnimDef gFrdAladdinAnimDefs[3] = {
    { gUnk_09EDE5FC, gUnk_09EDE630, gUnk_0887A400, 2, { 0, 0, 0 } },
    { gUnk_09EDE5FC, gUnk_09EDE630, gUnk_0887A400, 0, { 0, 0, 0 } },
    { gUnk_09EDE5FC, gUnk_09EDE630, gUnk_0887A400, 1, { 0, 0, 0 } },
};

TaskDesc gTaskDescFrdAladdin = { "task_frd_aladdin", task_frd_aladdin_0, task_frd_aladdin_1, task_frd_aladdin_2, task_frd_aladdin_3, 0x160 };

const AnimDef gFrdBeastAnimDefs[2] = {
    { gUnk_09EDE664, gUnk_09EDE680, gUnk_08881798, 0, { 0, 0, 0 } },
    { gUnk_09EDE664, gUnk_09EDE680, gUnk_08881798, 1, { 0, 0, 0 } },
};

void task_frd_donald_0(FrdDonaldWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->body;

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->unk_14D = args->unk_00;
    work->state = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->actor->flags & 4) {
        work->unk_158 = work->actor->x - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->actor->x + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->actor->y;
    body->z = -0x5000;
    body->unk_010 = 0;
    work->palette = LoadObjPalette(gUnk_09617C58, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 0, 0, work->tiles);

    switch (args->unk_00) {
    case 0:
        work->unk_160 = 1;
#ifdef VERSION_EU
        if (gLanguage == 3) {
            m4aSongNumStart(SONG_VO_SR_SUMMON00);
        } else {
            m4aSongNumStart(SONG_VO_SR_SUMMON04);
        }
#else
        m4aSongNumStart(SONG_VO_SR_SUMMON04);
#endif
        break;
    case 1:
        work->unk_160 = 1;
#ifdef VERSION_EU
        if (gLanguage == 3) {
            m4aSongNumStart(SONG_VO_SR_SUMMON00);
        } else {
            m4aSongNumStart(SONG_VO_SR_SUMMON04);
        }
#else
        m4aSongNumStart(SONG_VO_SR_SUMMON04);
#endif
        break;
    case 2:
        work->unk_160 = 1;
#ifdef VERSION_EU
        if (gLanguage == 3) {
            m4aSongNumStart(SONG_VO_SR_SUMMON00);
        } else {
            m4aSongNumStart(SONG_VO_SR_SUMMON04);
        }
#else
        m4aSongNumStart(SONG_VO_SR_SUMMON04);
#endif
        break;
    default:
        m4aSongNumStart(SONG_VO_DL_ATTACK00);
        func_08017260(0, 0, 0, 0x180);
        func_08045494(body, 0, 8, 8);
        break;
    }

    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 task_frd_donald_1(FrdDonaldWork* work) {
    BtlObj* body = &work->body;
    BtlWork* owner;
    BtlObj* target;
    s32 angle;
    if (work->unk_14C != 0) {
        owner = gBtlWork;
        target = owner->actor2;
    } else {
        owner = gUnk_02039B9C;
        target = owner->actor2;
    }
    if (owner->flags & 0x40000000) return 0;
    switch (work->state) {
    case 0:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 2, 0, work->tiles);
            work->unk_14E++;
        }
        body->x += (work->unk_158 - body->x) >> 4;
        ClampBattlePosition(&body->x, &body->y, -16, 0);
        if (work->unk_14D == 3) func_08045494(body, 0, 8, 8);
        if (func_0804544C(work)) {
            work->unk_14E = 0;
            if (work->unk_14D == 3) work->state = 8;
            else {
                work->state = 1;
                m4aSongNumStart(SONG_VO_DL_ATTACK00);
            }
        }
        break;
    case 1:
        if (work->unk_14E == 0) AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 3, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            func_0801D288();
            if (gBtlWork->flags & 0x800000000ULL) work->state = 4;
            else {
                u16 spell = GetRandom();
                spell &= 3;
                switch (spell) {
                case 0:
                    work->state = 4;
                    break;
                case 1:
                    work->state = 5;
                    break;
                case 2:
                    work->state = 6;
                    break;
                case 3:
                    work->state = 7;
                    break;
                }
            }
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 2:
        if (work->unk_160 > 0) {
            func_0801D288();
            if (gBtlWork->flags & 0x800000000ULL) work->state = 4;
            else {
                u16 spell = GetRandom();
                spell &= 3;
                switch (spell) {
                case 0:
                    work->state = 4;
                    break;
                case 1:
                    work->state = 5;
                    break;
                case 2:
                    work->state = 6;
                    break;
                case 3:
                    work->state = 7;
                    break;
                }
            }
            work->unk_14E = 0;
            work->unk_160--;
        } else {
            if (work->unk_14E == 0) AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 3, 0, work->tiles);
            if (AnimIsFinished(&work->anim)) {
                work->state = 3;
                work->unk_14E = 0;
            } else work->unk_14E++;
        }
        break;
    case 3:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 2, 0, work->tiles);
            if (!(body->flags & 4)) work->unk_158 = (gBtlWork->unk_0DA - 64) * 256;
            else work->unk_158 = (gBtlWork->unk_0DC + 64) * 256;
            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }
        ApproachValue(&body->x, work->unk_158, work->unk_150);
        if (work->unk_14D == 3) func_08045494(body, 0, 8, 8);
        func_0804544C(work);
        if (work->unk_150 <= 0) {
            if (work->unk_14D == 3) BgAnimStop();
            return 0;
        }
        work->unk_14E++;
        work->unk_150--;
        break;
    case 8:
        if (work->unk_14E == 0) {
            if (body->flags & 4) angle = GetRandom() % 2 ? 0xAD : 0xD3;
            else angle = GetRandom() % 2 ? 0x53 : 0x2D;
            work->unk_158 = gSineTable[angle] * 3;
            work->unk_15C = -gSineTable[angle + 64] * 3;
        }
        if (work->unk_15C > 0) AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 4, 1, work->tiles);
        else AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 5, 1, work->tiles);
        if (work->unk_158 < 0) body->flags |= 4;
        else body->flags &= ~4ULL;
        body->x += work->unk_158;
        body->y += work->unk_15C;
        func_0804544C(work);
        func_08045494(body, 1, 2, 8);
        switch (ClampBattlePosition(&body->x, &body->y, 0, 0)) {
        case 1:
        case 2:
            work->unk_158 = -work->unk_158;
            break;
        case 3:
        case 4:
            work->unk_15C = -work->unk_15C;
            break;
        }
        if (work->unk_14E > 179) {
            work->unk_14E = 0;
            work->state = 3;
        } else work->unk_14E++;
        break;
    case 4:
        {
            s32 x,y,z;
            if (work->unk_14E == 0) {
                AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                }
            }
            if (work->unk_14E == 40) {
                if (target != 0) {
                    x = target->x;
                    y = target->y;
                    z = target->z - target->unk_0A2 * 256;
                    if (x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                } else {
                    if (body->flags & 4) x = body->x - 0xC800;
                    else x = body->x + 0xC800;
                    y = body->y;
                    z = body->z - 0x800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->flags & 4) func_08012E44(0, body->x - 0x5000, body->y, body->z - 0x800, x, y, z, 1, 123);
                    else func_08012E44(0, body->x + 0x5000, body->y, body->z - 0x800, x, y, z, 0, 123);
                    break;
                case 1:
                    if (body->flags & 4) func_08012E44(1, body->x - 0x5000, body->y, body->z - 0x800, x, y, z, 1, 124);
                    else func_08012E44(1, body->x + 0x5000, body->y, body->z - 0x800, x, y, z, 0, 124);
                    break;
                case 2:
                default:
                    if (body->flags & 4) func_08012E44(2, body->x - 0x5000, body->y, body->z - 0x800, x, y, z, 1, 125);
                    else func_08012E44(2, body->x + 0x5000, body->y, body->z - 0x800, x, y, z, 0, 125);
                    break;
                }
            }
            if (work->unk_14E > 40) {
                if (!func_080128EC()) {
                    work->state = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->x, target->y, target->z - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 5:
        {
            s32 x,y,z;
            if (work->unk_14E == 0) {
                AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                }
            }
            if (work->unk_14E == 40) {
                if (target != 0) {
                    x = target->x;
                    y = target->y;
                    z = target->z - target->unk_0A2 * 256;
                    if (x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                } else {
                    if (body->flags & 4) x = body->x - 0x6400;
                    else x = body->x + 0x6400;
                    y = body->y;
                    z = body->z - 0x800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->flags & 4) func_08013308(0, body->x - 0x5000, body->y, body->z - 0x800, x, y, z, 1, 126);
                    else func_08013308(0, body->x + 0x5000, body->y, body->z - 0x800, x, y, z, 0, 126);
                    break;
                case 1:
                    if (body->flags & 4) func_08013308(1, body->x - 0x5000, body->y, body->z - 0x800, x, y, z, 1, 127);
                    else func_08013308(1, body->x + 0x5000, body->y, body->z - 0x800, x, y, z, 0, 127);
                    break;
                case 2:
                default:
                    if (body->flags & 4) func_08013308(2, body->x - 0x5000, body->y, body->z - 0x800, x, y, z, 1, 128);
                    else func_08013308(2, body->x + 0x5000, body->y, body->z - 0x800, x, y, z, 0, 128);
                    break;
                }
            }
            if (work->unk_14E > 40) {
                if (!func_080128EC()) {
                    work->state = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->x, target->y, target->z - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 6:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdDonaldAnimDefs, &work->anim, 1, 0, work->tiles);
            AnimReset(&work->anim);
            if (target != 0) {
                if (target->x < body->x) body->flags |= 4;
                else body->flags &= ~4ULL;
            }
        }
        if (work->unk_14E == 40) {
            switch (work->unk_14D) {
            case 0:
                {
                    s32 x,y,z;
                    if (target != 0) {
                        x=target->x;
                        y=target->y;
                        z=target->unk_010;
                    } else {
                        if (body->flags & 4) x=body->x-0x5000;
                        else x=body->x+0x5000;
                        y=body->y;
                        z=0;
                    }
                    func_08015834(0, body->x, body->y, body->z-0x4000, x,y,z,129);
                    break;
                }
            case 1:
                func_08013CB4(1,body->x,body->y,body->z-0x4000,body->unk_010,130);
                break;
            case 2:
            default:
                func_08013CB4(2,body->x,body->y,body->z-0x4000,body->unk_010,131);
                break;
            }
        }
        if (work->unk_14E == 60) func_08019050(15,148,0x10000,0x12C00);
        if (work->unk_14E > 40 && !func_080128EC()) {
            work->state=2;
            func_08019050(15,256,gBtlWork->x2,gBtlWork->y2);
            work->unk_14E=0;
        } else work->unk_14E++;
        break;
    case 7:
        {
            BtlObj* ally=work->unk_14C != 0 ? gBtlWork->actor : gUnk_02039B9C->actor;
            if (work->unk_14E == 0) {
                AnimChangeWithDef(gFrdDonaldAnimDefs,&work->anim,1,0,work->tiles);
                AnimReset(&work->anim);
                if (ally->x < body->x) body->flags |= 4;
                else body->flags &= ~4ULL;
            }
            if (work->unk_14E == 40) {
                switch (work->unk_14D) {
                case 0:
                    func_08012AAC(0,ally->x,ally->y,ally->z-0x2C00);
                    break;
                case 1:
                    func_08012AAC(1,ally->x,ally->y,ally->z-0x2C00);
                    break;
                case 2:
                    func_08012AAC(2,ally->x,ally->y,ally->z-0x2C00);
                    break;
                default:
                    func_08012AAC(0,ally->x,ally->y,ally->z-0x2C00);
                    break;
                }
            }
            if (work->unk_14E > 40) {
                if (func_080128EC()) {
                    BgFxSetPosition(ally->x,ally->y,ally->z-0x2C00);
                } else {
                    if (ally->btl->unk_0F4 == 13) {
                        switch (work->unk_14D) {
                        case 0:
                            ally->unk_02C+=75;
                            break;
                        case 1:
                            ally->unk_02C+=225;
                            break;
                        case 2:
                            ally->unk_02C+=450;
                            break;
                        }
                    } else {
                        switch (work->unk_14D) {
                        case 0:
                            ally->unk_02C+=50;
                            break;
                        case 1:
                            ally->unk_02C+=150;
                            break;
                        case 2:
                            ally->unk_02C+=300;
                            break;
                        }
                    }
                    if (ally->unk_02C > ally->unk_02E) ally->unk_02C=ally->unk_02E;
                    func_08019190(ally,10);
                    work->state=2;
                    func_08019050(15,256,gBtlWork->x2,gBtlWork->y2);
                    work->unk_14E=0;
                    break;
                }
            }
            work->unk_14E++;
            break;
        }
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_donald_2(FrdDonaldWork* work) {
    BtlObj* body;
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
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_donald_3(FrdDonaldWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

u8 func_080465F0(FrdGoofyWork* work) {
    BtlObj* body;

    body = &work->body;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_010);
    body->z += work->unk_154;
    work->unk_154 += 0x33;

    if (body->z > body->unk_010) {
        body->z = body->unk_010;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_goofy_0(FrdGoofyWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->body;
#ifdef VERSION_EU
    if (gLanguage == 1 || gLanguage == 3) {
        m4aSongNumStart(SONG_VO_SR_SUMMON00);
    } else {
        m4aSongNumStart(SONG_VO_SR_SUMMON03);
    }
#else
    m4aSongNumStart(SONG_VO_SR_SUMMON03);
#endif

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->unk_14D = args->unk_00;
    work->state = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->actor->flags & 4) {
        work->unk_158 = work->actor->x - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->actor->x + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->actor->y;
    body->z = -0x5000;
    body->unk_010 = 0;
    work->palette = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 0, 0, work->tiles);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 task_frd_goofy_1(FrdGoofyWork* work) {
    BtlObj* body;
    BtlWork* obj;
    s32 t;

    body = &work->body;
    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->flags & 0x40000000) {
        return 0;
    }

    switch (work->state) {
    case 0:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 0, 0, work->tiles);
            work->unk_14E++;
        }

        body->x += (work->unk_158 - body->x) >> 4;
        ClampBattlePosition(&body->x, &body->y, -16, 0);

        if (func_080465F0(work)) {
            work->state = 1;
            work->unk_14E = 0;
            m4aSongNumStart(SONG_VO_GF_ATTACK00);
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 1, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim)) {
            switch (work->unk_14D) {
            case 0:
            case 1:
                work->state = 4;
                break;
            case 2:
                work->state = 5;
                break;
            }

            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 1, 0, work->tiles);
        }

        if (AnimIsFinished(&work->anim)) {
            work->state = 3;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 3:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 0, 0, work->tiles);

            if (body->flags & 4) {
                work->unk_158 = (gBtlWork->unk_0DA - 0x40) << 8;
            } else {
                work->unk_158 = (gBtlWork->unk_0DC + 0x40) << 8;
            }

            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }

        ApproachValue(&body->x, work->unk_158, work->unk_150);
        func_080465F0(work);

        if (work->unk_150 <= 0) {
            return 0;
        }

        work->unk_14E++;
        work->unk_150--;
        break;
    case 4:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 2, 0, work->tiles);

            if (body->flags & 4) {
                work->unk_158 = body->x - 0x8500;
            } else {
                work->unk_158 = body->x + 0x8500;
            }
        }

        if (work->unk_14E == 40) {
            work->unk_15C = work->actor->y;
        }

        if (work->unk_14E > 39) {
            body->x += (work->unk_158 - body->x) >> 4;
            body->y += (work->unk_15C - body->y) >> 4;

            if (body->flags & 4
                    ? func_08011F78(work->unk_14D + 120, body->x - 0xF00, body->y, body->z, 0x1E, 0x0C, 0x30)
                    : func_08011F78(work->unk_14D + 120, body->x + 0xF00, body->y, body->z, 0x1E, 0x0C, 0x30)) {
                m4aSongNumStart(SONG_EF_GFHIT);
            }

            ClampBattlePosition(&body->x, &body->y, -16, 0);
        }

        func_080465F0(work);

        if (AnimIsFinished(&work->anim)) {
            work->state = 2;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 5:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 3, 0, work->tiles);
        }

        func_080465F0(work);

        if (AnimIsFinished(&work->anim)) {
            work->state = 6;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 6:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdGoofyAnimDefs, &work->anim, 4, 1, work->tiles);
            work->angle = GetRandom();
        }

        work->unk_158 = work->actor->x + (gSineTable[work->angle] << 6);
        work->unk_15C = work->actor->y - (gSineTable[work->angle + 0x40] << 5);
        body->x += (work->unk_158 - body->x) >> 3;
        body->y += (work->unk_15C - body->y) >> 3;
        ClampBattlePosition(&body->x, &body->y, -16, 0);
        work->angle += 4;

        if (func_08011F78(0x7A, body->x, body->y, body->z, 0x23, 0x1C, 0x30)) {
            m4aSongNumStart(SONG_EF_GFHIT);
        }

        func_080465F0(work);

        if (work->unk_14E > 179) {
            work->state = 2;
            work->unk_14E = 0;
        }

        work->unk_14E++;
        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_goofy_2(FrdGoofyWork* work) {
    BtlObj* body;
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
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_goofy_3(FrdGoofyWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

void task_frd_ariel_0(FrdArielWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->body;
    m4aSongNumStart(SONG_VO_SR_SUMMON10);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->unk_14D = args->unk_00;
    work->state = 0;
    work->unk_14E = 0;

    if (work->actor->flags & 4) {
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->actor->y;
    body->unk_010 = 0;
    work->unk_154 = -0x1000;
    body->z = -0x1000;
    work->palette = LoadObjPalette(gUnk_09617DF8, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdArielAnimDefs, &work->anim, 1, 0, work->tiles);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);

    switch (args->unk_00) {
    case 0:
        work->unk_15C = 0x500;
        work->unk_158 = 0;
        break;
    case 1:
        work->unk_15C = 0x800;
        work->unk_158 = 1;
        break;
    case 2:
    default:
        work->unk_15C = 0xC00;
        work->unk_158 = 4;
        break;
    }
}

u8 task_frd_ariel_1(FrdArielWork* work) {
    BtlObj* body;
    BtlWork* obj;
    s32 t;

    body = &work->body;

    if (gGameState.world != WORLD_ATLANTICA) {
        return 0;
    }

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->flags & 0x40000000) {
        return 0;
    }

    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_010);

    switch (work->state) {
    case 0:
        if (body->flags & 4) {
            t = gBtlWork->unk_0DC - 0x30;
        } else {
            t = gBtlWork->unk_0DA + 0x30;
        }

        body->x += ((t << 8) - body->x) >> 3;

        if (work->unk_14E > 20) {
            work->unk_14E = 0;
            work->state = 1;
        } else {
            work->unk_14E++;
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            work->unk_160 = 0;
            work->unk_150 = 12;
            AnimChangeWithDef(gFrdArielAnimDefs, &work->anim, 2, 0, work->tiles);
        }

        switch (AnimGetFrame(&work->anim)) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        default:
            if (work->unk_150 > 0) {
                ApproachValue(&work->unk_160, work->unk_15C, work->unk_150);
                work->unk_150--;
            }

            if (body->flags & 4) {
                body->x -= work->unk_160;
            } else {
                body->x += work->unk_160;
            }
            break;
        }

        if (work->unk_150 <= 0 && AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->state = 2;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        AnimChangeWithDef(gFrdArielAnimDefs, &work->anim, 0, 1, work->tiles);

        if (body->flags & 4
                ? func_08011F78(0x77, body->x, body->y, body->z, 0x10, 0x10, 0x10)
                : func_08011F78(0x77, body->x, body->y, body->z, 0x10, 0x10, 0x10)) {
            m4aSongNumStart(SONG_BTL_AR_PUNCHHIT);
        }

        if (body->flags & 4) {
            body->x -= work->unk_15C;

            if (body->x < (gBtlWork->unk_0DA - 0x30) << 8) {
                if (work->unk_158 == 0) {
                    return 0;
                }

                work->unk_158--;
                body->flags &= 0xFFFFFFFFFFFFFFFB;
                work->unk_14E = 0;
                body->y = work->actor->y;
                func_08019A30();
            }
        } else {
            body->x += work->unk_15C;

            if (body->x > (gBtlWork->unk_0DC + 0x30) << 8) {
                if (work->unk_158 == 0) {
                    return 0;
                }

                work->unk_158--;
                body->flags |= 4;
                work->unk_14E = 0;
                body->y = work->actor->y;
                func_08019A30();
            }
        }

        body->z = work->unk_154 + (gSineTable[((u16)work->unk_14E * 8) & 0xFF] << 3);
        body->y += (work->actor->y - body->y) >> 4;

        if (work->unk_14E == 20) {
            m4aSongNumStart(SONG_VO_AR_ATTACK00);
        }

        work->unk_14E++;
        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_ariel_2(FrdArielWork* work) {
    BtlObj* body;
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
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_ariel_3(FrdArielWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

u8 func_080474A8(FrdJackWork* work) {
    BtlObj* body;

    body = &work->body;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_010);
    body->z += work->unk_154;
    work->unk_154 += 0x33;

    if (body->z > body->unk_010) {
        body->z = body->unk_010;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_jack_0(FrdJackWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->body;
    m4aSongNumStart(SONG_VO_SR_SUMMON07);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->unk_14D = args->unk_00;
    work->state = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->actor->flags & 4) {
        work->unk_158 = work->actor->x - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->actor->x + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->actor->y;
    body->z = -0x5000;
    body->unk_010 = 0;
    work->unk_160 = 0;
    work->palette = LoadObjPalette(gUnk_09617DB8, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 0, 0, work->tiles);

    switch (args->unk_00) {
    case 0:
        work->unk_168 = 0;
        break;
    case 1:
        work->unk_168 = 1;
        break;
    case 2:
    default:
        work->unk_168 = 2;
        break;
    }

    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 task_frd_jack_1(FrdJackWork* work) {
    BtlObj* body = &work->body;
    BtlWork* owner;
    BtlObj* target;
    if (gGameState.world != WORLD_HALLOWEEN_TOWN) return 0;
    if (work->unk_14C != 0) {
        owner = gBtlWork;
        target = owner->actor2;
    } else {
        owner = gUnk_02039B9C;
        target = owner->actor2;
    }
    if (owner->flags & 0x40000000) return 0;
    switch (work->state) {
    case 0:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 1, 0, work->tiles);
            work->unk_14E++;
        }
        body->x += (work->unk_158 - body->x) >> 4;
        ClampBattlePosition(&body->x, &body->y, -16, 0);
        if (func_080474A8(work)) {
            work->state = 1;
            work->unk_14E = 0;
            m4aSongNumStart(SONG_VO_JC_ATTACK00);
        }
        break;
    case 1:
        if (work->unk_14E == 0) AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 2, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            u16 spell;
            func_0801D288();
            spell = GetRandom();
            spell &= 3;
            switch (spell) {
            case 0:
                work->state = 4;
                break;
            case 1:
                work->state = 5;
                break;
            case 2:
                work->state = 6;
                break;
            case 3:
                work->state = 7;
                break;
            }
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 2:
        if (work->unk_168 > 0) {
            work->state = 8;
            work->unk_14E = 0;
            work->unk_168--;
        } else {
            if (work->unk_14E == 0) AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 4, 0, work->tiles);
            if (AnimIsFinished(&work->anim)) {
                work->state = 3;
                work->unk_14E = 0;
            } else work->unk_14E++;
        }
        break;
    case 3:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 3, 0, work->tiles);
            if (!(body->flags & 4)) work->unk_158 = (gBtlWork->unk_0DA - 64) * 256;
            else work->unk_158 = (gBtlWork->unk_0DC + 64) * 256;
            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }
        ApproachValue(&body->x, work->unk_158, work->unk_150);
        func_080474A8(work);
        if (work->unk_150 <= 0) return 0;
        work->unk_14E++;
        work->unk_150--;
        break;
    case 8:
        if (work->unk_14E == 0) AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 4, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            work->state = 9;
            GetRandom();
            m4aSongNumStart(SONG_VO_JC_ATTACK00);
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 9:
        if (work->unk_14E == 0) {
            if (work->actor->flags & 4) work->unk_158 = work->actor->x - 0x2D00;
            else work->unk_158 = work->actor->x + 0x2D00;
            work->unk_15C = work->actor->y;
            work->unk_154 = -0x500;
            work->unk_150 = 45;
            if (work->unk_158 > body->x) {
                if (body->flags & 4) {
                    work->unk_164 = 256;
                } else {
                    work->unk_164 = -256;
                }
            } else {
                if (body->flags & 4) {
                    work->unk_164 = -256;
                } else {
                    work->unk_164 = 256;
                }
            }
            work->unk_14E++;
        }
        func_080474A8(work);
        if (work->unk_154 > 0) AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 1, 0, work->tiles);
        else AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 3, 0, work->tiles);
        if (work->unk_150 > 0) {
            ApproachValueHalfSteps(&body->x, work->unk_158, work->unk_150);
            ApproachValueHalfSteps(&body->y, work->unk_15C, work->unk_150);
            if (work->unk_150 <= 39) ApproachValueHalfSteps(&work->unk_160, work->unk_164, work->unk_150);
            work->unk_150--;
        }
        if (body->z >= body->unk_010 && work->unk_150 <= 0) {
            work->unk_14E = 0;
            work->unk_160 = 0;
            work->state = 10;
        }
        break;
    case 10:
        if (work->unk_14E == 0) AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 2, 0, work->tiles);
        if (AnimIsFinished(&work->anim)) {
            u16 spell;
            func_0801D288();
            spell = GetRandom();
            spell &= 3;
            switch (spell) {
            case 0:
                work->state = 4;
                break;
            case 1:
                work->state = 5;
                break;
            case 2:
                work->state = 6;
                break;
            case 3:
                work->state = 7;
                break;
            }
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    case 4:
        {
            s32 x, y, z;
            if (work->unk_14E == 0) {
                AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                }
            }
            if (work->unk_14E == 44) {
                if (target != 0) {
                    x = target->x;
                    y = target->y;
                    z = target->z - target->unk_0A2 * 256;
                    if (x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                } else {
                    if (body->flags & 4) x = body->x - 0xC800;
                    else x = body->x + 0xC800;
                    y = body->y;
                    z = body->z - 0x1800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->flags & 4) func_08012E44(0, body->x - 0x4A00, body->y, body->z - 0x1800, x, y, z, 1, 133);
                    else func_08012E44(0, body->x + 0x4A00, body->y, body->z - 0x1800, x, y, z, 0, 133);
                    break;
                case 1:
                    if (body->flags & 4) func_08012E44(1, body->x - 0x4A00, body->y, body->z - 0x1800, x, y, z, 1, 134);
                    else func_08012E44(1, body->x + 0x4A00, body->y, body->z - 0x1800, x, y, z, 0, 134);
                    break;
                case 2:
                default:
                    if (body->flags & 4) func_08012E44(2, body->x - 0x4A00, body->y, body->z - 0x1800, x, y, z, 1, 135);
                    else func_08012E44(2, body->x + 0x4A00, body->y, body->z - 0x1800, x, y, z, 0, 135);
                    break;
                }
            }
            if (work->unk_14E > 44) {
                if (!func_080128EC()) {
                    work->state = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->x, target->y, target->z - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 7:
        {
            s32 x, y, z;
            if (work->unk_14E == 0) {
                AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                }
                FadeToAmount(2, 13, 60);
            }
            if (work->unk_14E == 44) {
                if (target != 0) {
                    x = target->x;
                    y = target->y;
                    z = target->unk_010;
                    if (x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                } else {
                    if (body->flags & 4) x = body->x - 0x4000;
                    else x = body->x + 0x4000;
                    y = body->y;
                    z = body->unk_010;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->flags & 4) func_08014D78(0, body->x - 0x2800, body->y, body->z - 0x1800, x, y, z, 1, 142);
                    else func_08014D78(0, body->x + 0x2800, body->y, body->z - 0x1800, x, y, z, 0, 142);
                    break;
                case 1:
                    if (body->flags & 4) func_08014D78(1, body->x - 0x2800, body->y, body->z - 0x1800, x, y, z, 1, 143);
                    else func_08014D78(1, body->x + 0x2800, body->y, body->z - 0x1800, x, y, z, 0, 143);
                    break;
                case 2:
                default:
                    if (body->flags & 4) func_08014D78(2, body->x - 0x2800, body->y, body->z - 0x1800, x, y, z, 1, 144);
                    else func_08014D78(2, body->x + 0x2800, body->y, body->z - 0x1800, x, y, z, 0, 144);
                    break;
                }
            }
            if (work->unk_14E > 44 && !func_080128EC()) {
                FadeToOriginal(2, 20);
                work->state = 2;
                work->unk_14E = 0;
            } else work->unk_14E++;
            break;
        }
    case 5:
        {
            s32 x, y, z;
            if (work->unk_14E == 0) {
                AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 0, 0, work->tiles);
                AnimReset(&work->anim);
                if (target != 0) {
                    if (target->x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                }
            }
            if (work->unk_14E == 44) {
                if (target != 0) {
                    x = target->x;
                    y = target->y;
                    z = target->z - target->unk_0A2 * 256;
                    if (x < body->x) body->flags |= 4;
                    else body->flags &= ~4ULL;
                } else {
                    if (body->flags & 4) x = body->x - 0x6400;
                    else x = body->x + 0x6400;
                    y = body->y;
                    z = body->z - 0x1800;
                }
                switch (work->unk_14D) {
                case 0:
                    if (body->flags & 4) func_08013308(0, body->x - 0x4A00, body->y, body->z - 0x1800, x, y, z, 1, 136);
                    else func_08013308(0, body->x + 0x4A00, body->y, body->z - 0x1800, x, y, z, 0, 136);
                    break;
                case 1:
                    if (body->flags & 4) func_08013308(1, body->x - 0x4A00, body->y, body->z - 0x1800, x, y, z, 1, 137);
                    else func_08013308(1, body->x + 0x4A00, body->y, body->z - 0x1800, x, y, z, 0, 137);
                    break;
                case 2:
                default:
                    if (body->flags & 4) func_08013308(2, body->x - 0x4A00, body->y, body->z - 0x1800, x, y, z, 1, 138);
                    else func_08013308(2, body->x + 0x4A00, body->y, body->z - 0x1800, x, y, z, 0, 138);
                    break;
                }
            }
            if (work->unk_14E > 44) {
                if (!func_080128EC()) {
                    work->state = 2;
                    work->unk_14E = 0;
                    break;
                }
                if (target != 0) func_080147A8(target->x, target->y, target->z - target->unk_0A2 * 256);
            }
            work->unk_14E++;
            break;
        }
    case 6:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdJackAnimDefs, &work->anim, 0, 0, work->tiles);
            AnimReset(&work->anim);
            if (target != 0) {
                if (target->x < body->x) body->flags |= 4;
                else body->flags &= ~4ULL;
            }
        }
        if (work->unk_14E == 44) {
            switch (work->unk_14D) {
            case 0:
                {
                    s32 x, y, z;
                    if (target != 0) {
                        x = target->x;
                        y = target->y;
                        z = target->unk_010;
                    } else {
                        if (body->flags & 4) x = body->x - 0x5000;
                        else x = body->x + 0x5000;
                        y = body->y;
                        z = 0;
                    }
                    if (body->flags & 4) func_08015834(0, body->x - 0x2800, body->y, body->z - 0x1800, x, y, z, 139);
                    else func_08015834(0, body->x + 0x2800, body->y, body->z - 0x1800, x, y, z, 139);
                    break;
                }
            case 1:
                if (body->flags & 4) func_08013CB4(1, body->x - 0x2800, body->y, body->z - 0x1800, body->unk_010, 140);
                else func_08013CB4(1, body->x + 0x2800, body->y, body->z - 0x1800, body->unk_010, 140);
                break;
            case 2:
            default:
                if (body->flags & 4) func_08013CB4(2, body->x - 0x2800, body->y, body->z - 0x1800, body->unk_010, 141);
                else func_08013CB4(2, body->x + 0x2800, body->y, body->z - 0x1800, body->unk_010, 141);
                break;
            }
        }
        if (work->unk_14E == 64) func_08019050(15, 148, 0x10000, 0x12C00);
        if (work->unk_14E > 44 && !func_080128EC()) {
            work->state = 2;
            func_08019050(15, 256, gBtlWork->x2, gBtlWork->y2);
            work->unk_14E = 0;
        } else work->unk_14E++;
        break;
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_jack_2(FrdJackWork* work) {
    BtlObj* body;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;
    s32 affine;
    s32 sclX;
    s32 sclY;
    u8 angle;

    body = &work->body;
    gfx = AnimGetGfx(&work->anim);
    flags = GetBattleSpritePriorityFlags(body->y);
    angle = work->unk_160;

    if (body->flags & 4) {
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (angle == 0 && gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (angle != 0) {
        affine = AllocObjAffine(angle, sclX, sclY, 1);
    } else if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    if (body->flags & 4) {
        sx = sx + (gSineTable[(u16)(angle + 128) & 0xFF] * 5 >> 5);
    } else {
        sx = sx - (gSineTable[(u16)(angle + 128) & 0xFF] * 5 >> 5);
    }

    sy = sy + (-gSineTable[((u16)(angle + 128) & 0xFF) + 64] * 5 >> 5) - 40;
    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags, -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_jack_3(FrdJackWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

void task_frd_pan_0(FrdPanWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->body;
    m4aSongNumStart(SONG_VO_SR_SUMMON08);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->unk_14D = args->unk_00;
    work->state = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_158 = 0;

    if (work->actor->flags & 4) {
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 0x20004;
        work->unk_168 = -0x800;
        work->unk_16C = 0;
    } else {
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0x20000;
        work->unk_168 = 0x800;
        work->unk_16C = 1;
    }

    work->unk_15C = 0x10000;
    body->y = work->actor->y;
    body->unk_010 = 0;
    work->unk_164 = -0x2000;
    body->z = -0x2000;
    work->palette = LoadObjPalette(gUnk_09617DD8, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 0, 0, work->tiles);
    TaskPoolInit(&work->tasks, 15);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);

    switch (work->unk_14D) {
    case 0:
        work->unk_152 = 0x78;
        break;
    case 1:
        work->unk_152 = 0xF0;
        break;
    case 2:
    default:
        work->unk_152 = 0x1E0;
        break;
    }
}

void func_08048980(FrdPanWork* work) {
    BtlObj sub;

    if ((s16)work->unk_14E % 3 == 0) {
        sub.x = work->body.x;
        sub.y = work->body.y;
        sub.z = work->body.z;

        switch (AnimGetGfxIndex(&work->anim)) {
        case 1:
        case 2:
            sub.z -= 0x800;
            break;
        case 3:
        case 4:
            sub.z -= 0x1800;

            if (work->body.flags & 4) {
                sub.x += 0x2000;
            } else {
                sub.x -= 0x2000;
            }
            break;
        case 5:
        default:
            sub.z -= 0x1000;

            if (work->body.flags & 4) {
                sub.x += 0x1000;
            } else {
                sub.x -= 0x1000;
            }
            break;
        }

        TaskCreate(&work->tasks, &gTaskDescSmnTinkeff, &sub);
    }
}

void func_08048A68(FrdPanWork* work) {
    BtlObj* body;

    body = &work->body;
    body->z += ((work->unk_164 + (gSineTable[((u16)work->unk_14E * 2) & 0xFF] << 4)) - body->z) >> 2;
}

u8 task_frd_pan_1(FrdPanWork* work) {
    BtlObj* body = &work->body;
    BtlWork* owner;
    BtlObj* target;
    s32 ground;
    s32 y;
    s32 z;
    if (gGameState.world != WORLD_NEVER_LAND) {
        return 0;
    }
    owner = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    target = owner->actor2;
    if (owner->flags & 0x40000000) {
        return 0;
    }
    if (gBtlWork->boundsCallback != 0) {
        ground = body->unk_010;
        gBtlWork->boundsCallback(&body->x, &body->y, &body->z, &ground);
        if (ground != body->unk_010) {
            work->unk_164 = body->unk_010 - 0x1000;
            body->unk_010 = ground;
        }
    }
    switch (work->state) {
    case 0:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 0, 0, work->tiles);
            work->unk_150 = 30;
        }
        ApproachValueHalfSteps(&body->x, work->unk_15C, work->unk_150);
        func_08048A68(work);
        if (work->unk_150 <= 0) {
            work->state = 3;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
            work->unk_150--;
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 0, 0, work->tiles);
        }
        func_08048A68(work);
        if (AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->state = 2;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 0, 0, work->tiles);
            if (!(body->flags & 4)) {
                work->unk_15C = (gBtlWork->unk_0DA - 64) * 256;
            } else {
                work->unk_15C = (gBtlWork->unk_0DC + 64) * 256;
            }
            work->unk_150 = 30;
        }
        work->unk_164 -= 0x400;
        ApproachValue(&body->x, work->unk_15C, work->unk_150);
        func_08048A68(work);
        if (work->unk_150 <= 0) {
            return 0;
        }
        work->unk_14E++;
        work->unk_150--;
        break;
    case 3:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 1, 0, work->tiles);
        }
        func_08048A68(work);
        if (AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->state = 4;
            m4aSongNumStart(SONG_VO_PP_ATTACK00);
        } else {
            work->unk_14E++;
        }
        break;
    case 4:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 2, 1, work->tiles);
            work->unk_150 = 70;
            FadeToAmount(0, gBtlWork->fadeAmount, 8);
        }
        func_0801D288();
        if (gBtlWork->flags & 0x4000) {
            BtlObj* other = work->unk_14C != 0 ? gUnk_02039B9C->actor : gBtlWork->actor;
            y = other->y;
            z = other->z;
        } else if (target != 0) {
            y = target->y;
            z = target->z;
        } else {
            y = work->actor->y;
            z = work->actor->z;
        }
        body->y += (y - body->y) >> 5;
        work->unk_164 += (z - work->unk_164) >> 5;
        func_08048A68(work);
        if (work->unk_16C != 0) {
            ApproachValue(&work->unk_168, -0x800, work->unk_150);
        } else {
            ApproachValue(&work->unk_168, 0x800, work->unk_150);
        }
        body->x += work->unk_168;
        if (--work->unk_150 <= 0) {
            work->unk_150 = 70;
            work->unk_16C = !work->unk_16C;
        }
        if (work->unk_168 < 0) {
            body->flags |= 4;
        } else {
            body->flags &= ~4ULL;
        }
        if (body->flags & 4) {
            if (func_08011F78(150, body->x - 0x1C00, body->y, body->z - 0x1400, 20, 20, 20)) {
                m4aSongNumStart(SONG_BTL_PP_SWORDHIT);
            }
        } else {
            if (func_08011F78(150, body->x + 0x1C00, body->y, body->z - 0x1400, 20, 20, 20)) {
                m4aSongNumStart(SONG_BTL_PP_SWORDHIT);
            }
        }
        if (work->unk_14E > work->unk_152) {
            work->unk_14E = 0;
            work->state = 5;
        } else {
            work->unk_14E++;
        }
        break;
    case 5:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdPanAnimDefs, &work->anim, 3, 0, work->tiles);
        }
        func_08048A68(work);
        if (AnimIsFinished(&work->anim)) {
            work->unk_14E = 0;
            work->state = 1;
            FadeToOriginal(0, 8);
        } else {
            work->unk_14E++;
        }
        break;
    }
    func_08048980(work);
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_pan_2(FrdPanWork* work) {
    BtlObj* body;
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
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_pan_3(FrdPanWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

u8 func_080490FC(FrdAladdinWork* work) {
    BtlObj* body;

    body = &work->body;

    if (func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_010)) {
        body->z += work->unk_154;
        work->unk_154 = -0x200;
    } else {
        body->z += work->unk_154;
        work->unk_154 += 0x33;
    }

    if (body->z > body->unk_010) {
        body->z = body->unk_010;
        work->unk_154 = 0;
        return 1;
    }

    return 0;
}

void task_frd_aladdin_0(FrdAladdinWork* work, FrdArgs* args) {
    BtlObj* body;

    body = &work->body;
    m4aSongNumStart(SONG_VO_SR_SUMMON11);

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
    }

    work->unk_14D = args->unk_00;
    work->state = 0;
    work->unk_14E = 0;
    work->unk_150 = 0;
    work->unk_154 = 0;

    if (work->actor->flags & 4) {
        work->unk_158 = work->actor->x - 0x3000;
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 4;
    } else {
        work->unk_158 = work->actor->x + 0x3000;
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0;
    }

    body->y = work->actor->y;
    body->z = -0x5000;
    body->unk_010 = 0;
    work->palette = LoadObjPalette(gUnk_09617D98, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdAladdinAnimDefs, &work->anim, 0, 0, work->tiles);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);

    switch (work->unk_14D) {
    case 0:
        work->unk_152 = 0x78;
        break;
    case 1:
        work->unk_152 = 0xF0;
        break;
    case 2:
    default:
        work->unk_152 = 0x1E0;
        break;
    }
}

u8 task_frd_aladdin_1(FrdAladdinWork* work) {
    BtlObj* body;
    s32 x;
    s32 y;
    s32 delta;

    body = &work->body;
    if (gGameState.world != WORLD_AGRABAH) {
        return 0;
    }
    if ((work->unk_14C ? gBtlWork->flags : gUnk_02039B9C->flags) & 0x40000000) return 0;
    switch (work->state) {
    case 0:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdAladdinAnimDefs, &work->anim, 0, 0, work->tiles);
            work->unk_14E++;
        }
        body->x += (work->unk_158 - body->x) >> 4;
        ClampBattlePosition(&body->x, &body->y, -16, 0);
        if (func_080490FC(work)) {
            work->state = 1;
            work->unk_14E = 0;
            m4aSongNumStart(SONG_VO_AD_ATTACK00);
        }
        break;
    case 1:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdAladdinAnimDefs, &work->anim, 1, 0, work->tiles);
        }
        if (AnimIsFinished(&work->anim)) {
            work->state = 3;
            work->unk_14E = 0;
        } else {
            work->unk_14E++;
        }
        break;
    case 2:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdAladdinAnimDefs, &work->anim, 0, 0, work->tiles);
            if (!(body->flags & 4)) {
                work->unk_158 = (gBtlWork->unk_0DA - 64) << 8;
            } else {
                work->unk_158 = (gBtlWork->unk_0DC + 64) << 8;
            }
            work->unk_154 = -0x500;
            work->unk_150 = 30;
        }
        ApproachValue(&body->x, work->unk_158, work->unk_150);
        func_080490FC(work);
        if (work->unk_150 <= 0) {
            return 0;
        }
        work->unk_14E++;
        work->unk_150--;
        break;
    case 3:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdAladdinAnimDefs, &work->anim, 2, 1, work->tiles);
        }
        func_0801D288();
        if (work->actor->flags & 4) {
            body->flags |= 4;
            x = work->actor->x - 0x2800;
        } else {
            body->flags &= ~4ULL;
            x = work->actor->x + 0x2800;
        }
        y = work->actor->y;
        delta = (x - body->x) >> 3;
        if (delta < -0x400) {
            delta = -0x400;
        } else if (delta > 0x400) {
            delta = 0x400;
        }
        body->x += delta;
        delta = (y - body->y) >> 5;
        if (delta < -0x200) {
            delta = -0x200;
        } else if (delta > 0x200) {
            delta = 0x200;
        }
        body->y += delta;
        if (work->anim.timer == 0) {
            switch (AnimGetFrame(&work->anim)) {
            case 0:
            case 1:
            case 5:
            case 6:
                if ((body->flags & 4) ? func_08011F78(0x95, body->x - 0x1E00, body->y, body->z, 20, 20, 50) : func_08011F78(0x95, body->x + 0x1E00, body->y, body->z, 20, 20, 50)) {
                    m4aSongNumStart(SONG_BTL_AD_SWORDHIT);
                }
                break;
            }
        }
        func_080490FC(work);
        ClampBattlePosition(&body->x, &body->y, -16, 0);
        if (work->unk_14E > work->unk_152) {
            work->unk_14E = 0;
            work->state = 2;
        } else {
            work->unk_14E++;
        }
        break;
    }
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_aladdin_2(FrdAladdinWork* work) {
    BtlObj* body;
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
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_aladdin_3(FrdAladdinWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

u8 func_080497E8(FrdBeastWork* work) {
    BtlObj* body;

    body = &work->body;
    func_0801C6D4(&body->x, &body->y, &body->z, &body->unk_010);
    body->z += work->unk_158;
    work->unk_158 += 0x33;

    if (body->z > body->unk_010) {
        body->z = body->unk_010;
        work->unk_158 = 0;
        return 1;
    }

    return 0;
}

void task_frd_beast_0(FrdBeastWork* work, FrdArgs* args) {
    BtlObj* body;
    BtlObj* obj;

    body = &work->body;
#ifdef VERSION_EU
    if (gLanguage == 0) {
        m4aSongNumStart(SONG_VO_SR_SUMMON09);
    } else {
        m4aSongNumStart(SONG_VO_SR_SUMMON00);
    }
#else
    m4aSongNumStart(SONG_VO_SR_SUMMON09);
#endif

    if (args->unk_02 != 0) {
        work->unk_14C = 1;
        gBtlWork->flags |= 0x200000;
        work->actor = gBtlWork->actor;
        work->tiles = gBtlWork->tiles2;
        obj = gBtlWork->actor2;
    } else {
        work->unk_14C = args->unk_02;
        gUnk_02039B9C->flags |= 0x200000;
        work->actor = gUnk_02039B9C->actor;
        work->tiles = gBtlWork->tiles2;
        obj = gUnk_02039B9C->actor2;
    }

    work->unk_14D = args->unk_00;
    work->unk_14E = 0;
    work->unk_158 = 0;

    if (obj != 0) {
        work->unk_150 = obj->x;
        work->unk_154 = obj->y;
    } else {
        work->unk_150 = 0x10000;
        work->unk_154 = work->actor->y;
    }

    if (work->actor->flags & 4) {
        body->x = (gBtlWork->unk_0DC + 0x30) << 8;
        body->flags = 0x20004;
    } else {
        body->x = (gBtlWork->unk_0DA - 0x30) << 8;
        body->flags = 0x20000;
    }

    body->y = work->unk_154;
    body->z = 0;
    body->unk_010 = 0;

    switch (work->unk_14D) {
    case 0:
        work->state = 1;
        work->unk_15C = 0xA0;
        break;
    case 1:
        work->state = 1;
        work->unk_15C = 0xA1;
        break;
    case 2:
    default:
        work->state = 2;
        work->unk_15C = 0xA1;
        break;
    }

    work->palette = LoadObjPalette(gUnk_09617E18, 32);
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(gFrdBeastAnimDefs, &work->anim, 0, 0, work->tiles);
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, body);
}

u8 task_frd_beast_1(FrdBeastWork* work) {
    BtlObj* body;
    BtlWork* obj;

    body = &work->body;

    if (gGameState.world != WORLD_HOLLOW_BASTION) {
        return 0;
    }

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;

    if (obj->flags & 0x40000000) {
        return 0;
    }

    switch (work->state) {
    case 2:
        if (work->unk_14E == 0) {
            m4aSongNumStart(SONG_VO_BE_ATTACK00);
        }

        if (work->anim.timer == 0 && AnimGetFrame(&work->anim) == 2) {
            work->unk_158 = -0x400;
            m4aSongNumStart(SONG_BTL_BE_ATT02);
        }

        if (body->z < body->unk_010) {
            body->x += (work->unk_150 - body->x) >> 4;
            body->y += (work->unk_154 - body->y) >> 4;
        }

        if (work->unk_158 > 0) {
            if (gBtlWork->unk_10C == 0x99) {
                func_08011F78(0xA3, body->x, body->y, body->z - 0x1800, 0x28, 0x14, 0x10);
            } else {
                func_08011F78(0xA2, body->x, body->y, body->z - 0x1800, 0x28, 0x14, 0x10);
            }
        }

        if (func_080497E8(work) && AnimIsFinished(&work->anim)) {
            work->state = 1;
            work->unk_15C = 0xA1;
            work->unk_14E = 0;
            func_0802F1E8();
            break;
        }

        work->unk_14E++;
        break;
    case 1:
        if (work->unk_14E == 0) {
            AnimChangeWithDef(gFrdBeastAnimDefs, &work->anim, 1, 1, work->tiles);

            if (work->unk_14D != 2) {
                m4aSongNumStart(SONG_VO_BE_ATTACK00);
            }
        }

        if (body->flags & 4) {
            body->x -= 0x380;

            if (body->x < (gBtlWork->unk_0DA - 0x28) << 8) {
                return 0;
            }
        } else {
            body->x += 0x380;

            if (body->x > (gBtlWork->unk_0DC + 0x28) << 8) {
                return 0;
            }
        }

        if (func_08011F78(work->unk_15C, body->x, body->y, body->z - 0x1800, 0x28, 0x14, 0x10)) {
            m4aSongNumStart(SONG_BTL_BE_ATT01);
        }

        func_080497E8(work);
        work->unk_14E++;
        break;
    }

    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_frd_beast_2(FrdBeastWork* work) {
    BtlObj* body;
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
        sclY = gBtlWork->scale;
        sclX = sclY;
    } else if (gBtlWork->scale == 256) {
        sclY = gBtlWork->scale;
        sclX = sclY;
        flags |= 1;
    } else {
        sclX = -gBtlWork->scale;
        sclY = gBtlWork->scale;
    }

    WorldToScreen(&sx, &sy, body->x, body->y, body->z);

    if (gBtlWork->scale == 256) {
        affine = 0;
    } else if (gBtlWork->scale <= 255) {
        affine = AllocObjAffine(0, sclX, sclY, 0);
    } else {
        affine = AllocObjAffine(0, sclX, sclY, 1);
    }

    DrawSprite(sx, sy, gfx, work->tiles, work->palette, affine, flags,
               -4100 - ((body->y >> 8) * 4));
    body->unk_0CC = (-4100 - ((body->y >> 8) * 4)) | 2;
    TaskPoolDraw(&work->tasks);
}

void task_frd_beast_3(FrdBeastWork* work) {
    BtlWork* obj;

    obj = work->unk_14C != 0 ? gBtlWork : gUnk_02039B9C;
    obj->flags &= 0xFFFFFFFFFFDFFFFF;
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->tasks);
}

TaskDesc gTaskDescFrdBeast = { "task_frd_beast", task_frd_beast_0, task_frd_beast_1, task_frd_beast_2, task_frd_beast_3, 0x160 };
