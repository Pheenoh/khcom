#include "sroll.h"

static s32 Square(s32 x) {
    return x * x;
}

void func_081149B0(SrollBCharWork* w, s32 v) {
    *(s32*)w->unk_04 = v;
}

void func_081149B8(SrollBCharWork* w) {
    SrollBCharDef* def;
    SrollBCharGfx* gfx;

    def = w->sub->def;
    gfx = def->gfx;
    AnimChangeWithTables(&w->anim, def->animId, def->unk_0E, gfx->anims, gfx->gfxTable);
    SetObjTileSource(w->tiles, gfx->tiles);
    w->sub->flags &= 0xFFFE;
}

void task_sroll_b_char_0(SrollBCharWork* w, SrollBCharArg* a) {
    SrollBCharSet* set;
    AnimState* anim;

    set = a->set;
    w->unk_00 = 0;
    w->unk_04 = 0;
    w->sub = a->sub;
    w->tiles = AllocObjTiles((u16)(set->unk_00 * 32), 0);
    w->palette = LoadObjPalette(set->unk_08, 32);
    anim = &w->anim;
    AnimInit(anim, 0, 0);
    w->sub->anim = anim;
    w->sub->unk_1C = w->palette->index;
    func_081149B8(w);
    TaskPoolInit(&w->tasks, 4);
}

s32 task_sroll_b_char_1(SrollBCharWork* w) {
    SrollBCrtnArg a;

    if (w->sub->flags & 1) {
        func_081149B8(w);
    }

    if ((w->sub->unk_16 & 4) == 0) {
        FadeSetPaletteExcluded((w->palette->index & 15) + 16, 0);
    } else {
        FadeSetPaletteExcluded((w->palette->index & 15) + 16, 1);
    }

    AnimUpdate(&w->anim);
    TaskPoolUpdate(&w->tasks);

    switch (w->unk_00) {
    case 1:
        w->sub->x -= 128;
        w->sub->y += 128;
        break;
    case 2:
        w->sub->unk_0C = gUnk_09A5430C[(w->unk_04 >> 2) & 15] << 8;
        w->unk_04++;
        break;
    case 3:
        if ((w->unk_04 & 3) == 0) {
            a.unk_00 = 2;
            a.x = w->sub->x;
            a.y = w->sub->y;
            TaskCreate(&w->tasks, &gTaskDescSrollBCrtn, &a);
        }

        w->sub->unk_0C = (gUnk_09A5430C[(w->unk_04 >> 2) & 15] << 8) >> 2;
        w->unk_04++;
        break;
    case 4:
        w->sub->x += 128;
        w->sub->y -= 128;
        break;
    case 5:
        w->sub->x += (gUnk_09A542CC[(w->unk_04 >> 2) & 15] << 8) >> 2;
        w->unk_04++;
        break;
    }

    return 1;
}

void task_sroll_b_char_2(SrollBCharWork* w) {
    SrollBCharSub* sub;
    void* gfx;
    u16 x;
    u16 y;

    sub = w->sub;

    if ((sub->flags & 2) == 0) {
        x = sub->x >> 8;
        y = (sub->y + sub->unk_0C) >> 8;
        gfx = AnimGetGfx(&w->anim);
        DrawSprite(x, y, gfx, w->tiles, w->palette,
                   AllocObjAffine(sub->angle, sub->scaleX, sub->scaleY, 1), sub->unk_16, 0xFF0);
        TaskPoolDraw(&w->tasks);
    }
}

void task_sroll_b_char_3(SrollBCharWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette);
    TaskPoolDestroy(&w->tasks);
}

const s32 gUnk_09A542CC[16] = { -1, -2, -3, -4, -3, -2, -1, 0, 1, 2, 3, 4, 3, 2, 1, 0 };

const s32 gUnk_09A5430C[16] = { -1, -2, -3, -4, -5, -6, -7, -8, -7, -6, -5, -4, -3, -2, -1, 0 };

TaskDesc gTaskDescSrollBChar = {
    "task_sroll_b_char",
    (TaskInitFunc)task_sroll_b_char_0,
    (TaskUpdateFunc)task_sroll_b_char_1,
    (TaskFunc)task_sroll_b_char_2,
    (TaskFunc)task_sroll_b_char_3,
    0x40,
};
