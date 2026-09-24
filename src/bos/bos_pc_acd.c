#include "bos6.h"
#include "sprites_bos6.h"

TaskDesc gTaskDescBosPcAcd = {
    "task_bos_pc_acd",
    (TaskInitFunc)task_bos_pc_acd_0,
    (TaskUpdateFunc)task_bos_pc_acd_1,
    (TaskFunc)task_bos_pc_acd_2,
    (TaskFunc)task_bos_pc_acd_3,
    0x38,
};

s32 func_0810BF14(s32 x) {
    return x * x;
}

s32 func_0810BF1C(s32 x) {
    return x * x;
}

void func_0810BF24(u8** p, u8 v) {
    p[1][24] = v;
}

void task_bos_pc_acd_0(PcAcdWork* work, void* arg) {
    AnimState* anim;

    work->unk_000 = 0;
    work->tiles = (u32)AllocObjTiles(0x300, gUnk_09C489E4);
    work->palette = (u32)LoadObjPalette(gUnk_09D693D4, 0x60);
    work->x = -1;
    work->y = -1;
    work->unk_014 = -1;
    work->flt = arg;
    anim = &work->anim;
    AnimInit(anim, gUnk_09EFABA4, gUnk_09EFAB68);
    if (work->flt->unk_005 == 1) {
        work->unk_018 = 1;
        AnimStart(anim, 1, 0);
    } else {
        work->unk_018 = 0;
        AnimStart(anim, 0, 0);
    }
}

u8 task_bos_pc_acd_1(PcAcdWork* work) {
    AnimState* anim;
    s32 v;

    FadeSetPaletteExcluded(((UnkStruct_080038C8*)work->palette)->index + 17, 0);
    FadeSetPaletteExcluded(((UnkStruct_080038C8*)work->palette)->index + 18, 0);
    anim = &work->anim;
    AnimUpdate(anim);
    if (gBtlWork->actor->z >= 0) {
        if ((gBtlWork->flags & 0x20000000) == 0 ||
            (gBtlWork->flags & 0x200000) == 0) {
            if (work->x < 0 || AnimIsFinished(anim) == 1) {
                v = 0;
                if (work->unk_018 == 1) {
                    v = 1;
                }
                AnimReset(anim);
                AnimStart(anim, v, 0);
            }
        }
    }
    return 1;
}

void task_bos_pc_acd_2(PcAcdWork* work) {
    s16 sx;
    s16 sy;
    BtlWork** gp;
    BtlObj* pos;
    PcFltWork* flt;
    AnimState* anim;
    u8* tbl;
    s32 ofs;
    void* gfx;
    s32 ox;
    s32 oy;

    gp = &gBtlWork;
    pos = (*gp)->actor;
    pos->flags &= ~0x2000000;
    ox = 0;
    oy = 0;
    flt = work->flt;
    if (flt->unk_005 == 1) {
        ox = gEventState->unk_68 << 8;
        oy = gEventState->unk_6A << 8;
    }
    work->x = pos->x;
    work->y = pos->y - 0x400;
    work->unk_014 = 0;
    if (flt->unk_004 == 1) {
        tbl = (u8*)gUnk_09EFAB68;
        ofs = (AnimGetGfxIndex(&work->anim) + 5) * 4;
        gfx = *(void**)((u32)tbl + ofs);
        if ((*gp)->actor->flags & 4) {
            WorldToScreen(&sx, &sy, work->x - ox + 0x600, work->y - oy, 0);
        } else {
            WorldToScreen(&sx, &sy, work->x - ox + 0x200, work->y - oy, 0);
        }
        DrawSprite(sx, sy, gfx, (void*)work->tiles, (void*)work->palette, 0, GetBattleSpritePriorityFlags(work->y),
                   (u16)((-0x1004 - ((work->y >> 8) << 2)) | 3));
    } else if (pos->z >= 0) {
        if (((*gp)->flags & 0x20000000) && ((*gp)->flags & 0x200000)) {
            return;
        }
        anim = &work->anim;
        if (AnimGetId(anim) == 1) {
            (*gp)->actor->flags |= 0x2000000;
            if ((*gp)->actor->flags & 0x80) {
                return;
            }
            tbl = (u8*)gUnk_09EFAB68;
            ofs = (AnimGetGfxIndex(anim) + 5) * 4;
            gfx = *(void**)((u32)tbl + ofs);
            if ((*gp)->actor->flags & 4) {
                WorldToScreen(&sx, &sy, work->x - ox + 0x600, work->y - oy, 0);
            } else {
                WorldToScreen(&sx, &sy, work->x - ox + 0x200, work->y - oy, 0);
            }
            DrawSprite(sx, sy, gfx, (void*)work->tiles, (void*)work->palette, 0, GetBattleSpritePriorityFlags(work->y),
                       (u16)((-0x1004 - ((work->y >> 8) << 2)) | 3));
        } else {
            WorldToScreen(&sx, &sy, work->x - ox, work->y - oy, 0);
            DrawSprite(sx, sy, AnimGetGfx(anim), (void*)work->tiles, (void*)work->palette, 0, GetBattleSpritePriorityFlags((*gp)->actor->y),
                       (u16)(-0x1004 - (((*gp)->actor->y >> 8) << 2)));
        }
    }
}

void task_bos_pc_acd_3(PcAcdWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}
