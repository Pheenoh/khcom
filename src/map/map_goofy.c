#include "map_text_assets.h"
#include "monsgage.h"
#include "map_resource_assets.h"
#include "map_tasks.h"
#include "sprites_btl.h"
#include "sprites_emy.h"
#include "sprites_evt.h"
#include "sprites_map.h"
#include "sprites_map_tasks.h"
#include "battle_backgrounds.h"

extern MapNameText* gFloorNames[13];
extern MapNameText* gBasementFloorNames[12];

void func_080F5F88(MapGoofyWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= 0x1000;

        if ((s8)gGameState.floor == 12 && gUnk_0203C590.unk_06 == 0xFD) {
            CreateCardMessageTask(&w->tasks, 0, 49);
        } else {
            CreateCardMessageTask(&w->tasks, 0, gUnk_0984C310[gUnk_0203C590.unk_00]);
        }

        w->update = func_080F6004;
    }
}

void func_080F6004(MapGoofyWork* w) {
    if (func_080A42C8() == 0) {
        gFieldState->flags &= ~0x1000;
        w->update = func_080F5F88;
    }
}

void Task_MapGoofy_0(MapGoofyWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    if (gUnk_0203C590.unk_06 != 0xFE) {
        if ((s8)gGameState.floor == 12) {
            w->unk_000 = 0x25000;
            w->unk_004 = 0x10A00;
        } else {
            w->unk_000 = 0x20000;
            w->unk_004 = 0xB000;
        }
    } else {
        if ((s8)gGameState.floor != 0) {
            w->unk_000 = 0x1E800;
            w->unk_004 = 0xD000;
        } else {
            w->unk_000 = 0x2C000;
            w->unk_004 = 0xE000;
        }
    }

    e->unk_00.z = 0;
    e->unk_00.unk_0C = func_080DFF30(&e->unk_00);
    e->unk_00.z = e->unk_00.unk_0C;
    e->unk_00.y -= e->unk_00.unk_0C;
    e->unk_14 = 0x80;
    e->unk_1A = 0x30;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->update = func_080F5F88;
    w->tiles = AllocObjTiles(0x400, gUnk_091ABDB8);
    w->palette = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&w->anim, gUnk_09EEE1CC, gUnk_09EEE1C8);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(&w->collider, 4, 16, 48);
    ColliderSetPosition(&w->collider, e->unk_00.x, e->unk_00.y, e->unk_00.z);
    FldObjRegister(e);
    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapGoofy_1(MapGoofyWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapGoofy_2(MapGoofyWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->x >> 8) - (gFieldState->x >> 8);
        k = p->y >> 8;
        y = k + (p->z >> 8) - (gFieldState->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->unk_0C;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapGoofy_3(MapFrdWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_040);
    FldObjUnregister(w);
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F62B0(MapNamineWork* w) {
    if (w->unk_0C1 != 0 && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= 0x1000;

        if (gUnk_0203C590.unk_00 == 27) {
            CreateCardMessageTask(&w->tasks, 0, 0x33);
        } else {
            CreateCardMessageTask(&w->tasks, 0, 0x32);
        }
        w->update = func_080F6314;
    }
}

void func_080F6314(MapNamineWork* w) {
    if (func_080A42C8() == 0) {
        gFieldState->flags &= ~0x1000;
        w->update = func_080F62B0;
    }
}

void Task_MapNamine_0(MapNamineWork* w) {
    UnkStruct_080E6394* p = (UnkStruct_080E6394*)w;

    switch (gUnk_0203C590.unk_00) {
    case 27:
        w->unk_000 = 0x20D00;
        w->unk_004 = 0xD500;
        w->unk_0C4 = 0x800;
        break;
    case 23:
        w->unk_000 = 0x27C00;
        w->unk_004 = 0xD400;
        w->unk_0C4 = 0x800;
        break;
    case 24:
    case 25:
    case 26:
    default:
        p->unk_00.x = 0x15200;
        p->unk_00.y = 0xF800;
        w->unk_0C4 = 0x801;
        break;
    }

    p->unk_00.z = 0;
    p->unk_00.z = p->unk_00.unk_0C = func_080DFF30(&p->unk_00);
    p->unk_00.y -= p->unk_00.unk_0C;
    p->unk_14 = 173;
    p->unk_1A = 48;
    p->unk_30 = 2;
    w->unk_0C0 = gUnk_0203C590.unk_00 != 23;
    w->unk_0C2 = 1;
    w->update = func_080F62B0;
    w->tiles = AllocObjTiles(0x300, gUnk_093E1EE0);
    w->palette = LoadObjPalette(gUnk_096184D8, 32);
    AnimInit(&w->anim, gUnk_09EF0D64, gUnk_09EF0D48);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(w->collider, 4, 16, 48);
    ColliderSetPosition(w->collider, p->unk_00.x, p->unk_00.y, p->unk_00.z);

    if (w->unk_0C0 != 0) {
        FldObjRegister(p);
    }

    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C1 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapNamine_1(MapNamineWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C2 = 0;
    } else {
        w->unk_0C2 = 1;
        w->unk_0C1 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapNamine_2(MapNamineWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C2 != 0) {
        x = (p->x >> 8) - (gFieldState->x >> 8);
        k = p->y >> 8;
        y = k + (p->z >> 8) - (gFieldState->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, w->unk_0C4, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->unk_0C;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C1 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapNamine_3(MapNamineWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);

    if (w->unk_0C0 != 0) {
        FldObjUnregister(w);
    }

    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F65EC(MapNamineWork* w) {
    if (w->unk_0C1 != 0 && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= 0x1000;
        CreateCardMessageTask(&w->unk_0C4, 0, 0x34);
        w->update = func_080F6634;
    }
}

void func_080F6634(MapNamineWork* w) {
    if (func_080A42C8() == 0) {
        gFieldState->flags &= ~0x1000;
        w->update = func_080F65EC;
    }
}

void func_080F6668(MapNamineWork* w) {
    s32 dx;
    s32 dy;

    dx = w->unk_000 - gFieldState->actor.fieldPosition.x;

    if (dx < 0) {
        dx = gFieldState->actor.fieldPosition.x - w->unk_000;
    }

    dy = w->unk_004 - gFieldState->actor.fieldPosition.y;

    if (dy < 0) {
        dy = gFieldState->actor.fieldPosition.y - w->unk_004;
    }

    if (dx <= 0x8000 && dy <= 0x8000) {
        if (Sqrt8((dx * dx >> 8) + (dy * dy >> 8)) < 0x3000) {
            FadeStartOut(0, 16);
            gFieldState->flags |= 0x1000;
            w->update = func_080F66E0;
        }
    }
}

void func_080F66E0(MapNamineWork* w) {
    if (FadeIsActive() == 0) {
        func_0806180C(0x3B);
        w->update = 0;
    }
}

void Task_MapNiseriku_0(MapNiserikuWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;
    s32 c;

    switch (gUnk_0203C590.unk_00) {
    case 27:
        e->unk_00.x = 0x27C00;
        e->unk_00.y = 0x10700;
        break;
    case 23:
        e->unk_00.x = 0x24900;
        e->unk_00.y = 0xD500;
        break;
    case 24:
    case 25:
    case 26:
    default:
        e->unk_00.x = 0x17A00;
        e->unk_00.y = 0x11000;
        break;
    }

    e->unk_00.z = 0;
    e->unk_00.z = e->unk_00.unk_0C = func_080DFF30(&e->unk_00);
    e->unk_00.y -= e->unk_00.z;
    e->unk_14 = 173;
    e->unk_1A = 48;
    e->unk_30 = 2;

    c = 0;

    if (gUnk_0203C590.unk_00 == 27) {
        c = 1;
    }

    w->unk_0C0 = c;

    w->unk_0C2 = 1;
    w->unk_0C1 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
    TaskPoolInit(&w->tasks, 2);

    switch (gUnk_0203C590.unk_00) {
    case 27:
        w->update = func_080F65EC;
        w->tiles = AllocObjTiles(0x680, gUnk_0937E90A);
        w->palette = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->anim, gUnk_09EF04D8, gUnk_09EF04D4);
        AnimStart(&w->anim, 0, 1);
        ColliderInit(&w->collider, 4, 16, 48);
        ColliderSetPosition(&w->collider, e->unk_00.x, e->unk_00.y, e->unk_00.z);
        TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
        break;
    case 23:
        w->update = func_080F6668;
        w->tiles = AllocObjTiles(0x320, gUnk_0938044A);
        w->palette = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->anim, gUnk_09EF0510, gUnk_09EF04FC);
        AnimStart(&w->anim, 0, 1);
        ColliderInit(&w->collider, 4, 16, 48);
        ColliderSetPosition(&w->collider, e->unk_00.x, e->unk_00.y, e->unk_00.z);
        TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
        break;
    case 24:
    case 25:
    case 26:
    default:
        w->update = 0;
        w->tiles = AllocObjTiles(0x300, gUnk_0938D282);
        w->palette = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->anim, gUnk_09EF0628, gUnk_09EF060C);
        AnimStart(&w->anim, 1, 1);
        ColliderInit(&w->collider, 4, 36, 48);
        ColliderSetPosition(&w->collider, e->unk_00.x, e->unk_00.y, e->unk_00.z);
        break;
    }

    if (w->unk_0C0 != 0) {
        FldObjRegister(e);
    }
}

s32 Task_MapNiseriku_1(MapNiserikuWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C2 = 0;
    } else {
        w->unk_0C2 = 1;
        w->unk_0C1 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapNiseriku_2(MapNiserikuWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C2 != 0) {
        x = (p->x >> 8) - (gFieldState->x >> 8);
        k = p->y >> 8;
        y = k + (p->z >> 8) - (gFieldState->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->unk_0C;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C1 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapNiseriku_3(MapMickeyWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);

    if (w->unk_0C0 != 0) {
        FldObjUnregister(w);
    }

    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F6A60(MapMickeyWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & A_BUTTON)) {
        gFieldState->flags |= 0x1000;

        switch (gUnk_0203C590.unk_00) {
        case 20:
            CreateCardMessageTask(&w->tasks, 0, 0x3F);
            break;
        case 22:
            CreateCardMessageTask(&w->tasks, 0, 0x3D);
            break;
        case 23:
        default:
            CreateCardMessageTask(&w->tasks, 0, 0x3E);
            break;
        }

        w->update = func_080F6AD8;
    }
}

void func_080F6AD8(MapMickeyWork* w) {
    if (func_080A42C8() == 0) {
        gFieldState->flags &= ~0x1000;
        w->update = func_080F6A60;
    }
}

void Task_MapMickey_0(MapMickeyWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    e->unk_00.x = 0x1C800;
    e->unk_00.y = 0xE000;
    w->unk_0C2 = 0x801;
    e->unk_00.z = 0;
    e->unk_00.unk_0C = func_080DFF30(&e->unk_00);
    e->unk_00.z = e->unk_00.unk_0C;
    e->unk_00.y -= e->unk_00.unk_0C;
    e->unk_14 = 0xAD;
    e->unk_1A = 0x30;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->update = func_080F6A60;
    w->tiles = AllocObjTiles(0x300, gUnk_093A5E10);
    w->palette = LoadObjPalette(gUnk_096183F8, 32);
    AnimInit(&w->anim, gUnk_09EF0824, gUnk_09EF0820);
    AnimStart(&w->anim, 0, 1);
    ColliderInit(&w->collider, 4, 16, 48);
    ColliderSetPosition(&w->collider, e->unk_00.x, e->unk_00.y, e->unk_00.z);
    FldObjRegister(e);
    TaskPoolInit(&w->tasks, 2);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->tasks2, 1);
    TaskCreate(&w->tasks2, &gTaskDescMapTalk, w);
}

s32 Task_MapMickey_1(MapMickeyWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        AnimUpdate(&w->anim);

        if (w->update != 0) {
            w->update(w);
        }
    }

    return 1;
}

void Task_MapMickey_2(MapMickeyWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->x >> 8) - (gFieldState->x >> 8);
        k = p->y >> 8;
        y = k + (p->z >> 8) - (gFieldState->y >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, w->unk_0C2, v);
        ((UnkStruct_080E64D4*)p)->unk_3C = p->unk_0C;
        ((UnkStruct_080E64D4*)p)->unk_3A = v + 1;
        TaskPoolDraw(&w->tasks);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapMickey_3(MapFrdWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_040);
    FldObjUnregister(w);
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

void func_080F6D40(void) {
    gFieldState->flags |= 0x80;
    gUnk_0203C7AC->unk_0E = 10;
    gUnk_0203C7AC->flags &= ~0x4000;
    gUnk_0203C7AC->flags |= 2;
}

void func_080F6D70(MapTutorialWork* w) {
    u32 flags;

    if (gFieldState->unk_68 == 0) {
        flags = gFieldState->flags;

        if (!(flags & 0x2000) && !(gUnk_0203C7AC->flags & 0x2000) && (gGameState.progression.unk_82 & 0x10)) {
            gUnk_0203C7AC->flags |= 0x4000;
            gFieldState->flags = flags | 0x1000;
            CreateCardMessageTask(&w->tasks, 0, 0x6A);
            w->update = func_080F6DE8;
        }
    }
}

void func_080F6DE8(MapTutorialWork* w) {
    if (func_080A42C8() == 0) {
        AnimState* a;

        func_080E5354((UnkStruct_080DFF1C*)w, &w->y);
        w->z = 0;
        w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
        w->y -= w->unk_00C;
        w->z = w->unk_00C - 0xA000;
        *(u16*)&w->unk_014[6] = 24;
        w->vz = 2;
        w->tiles = AllocObjTiles(0x400, gUnk_09858B3C);
        w->palette = LoadObjPalette(&gUnk_099910C4[0x220], 32);
        a = &w->anim;
        AnimInit(a, gUnk_09EF8460, gUnk_09EF8424);
        AnimStart(a, 0, 1);
        w->gfx = AnimGetGfx(a);
        ColliderInit(w->unk_040, 6, 12, 24);
        ColliderSetPosition(w->unk_040, w->x, w->y, w->z);
        w->unk_0C1 = 1;
        TaskCreate(&w->tasks2, &gTaskDescFldShadow, w);
        w->unk_0C0 = 1;
        w->update = func_080F6EBC;
    }
}

void func_080F6EBC(MapTutorialWork* w) {
    MapTutorialWork* p = w;

    w->vz += 0x38;
    w->z += w->vz;

    if (w->z > w->unk_00C) {
        gFieldState->flags &= ~0x1000;
        m4aSongNumStart(SONG_SND_215);
        w->z = w->unk_00C;
        w->vz = 0;
        w->unk_0C1 = 0;
        w->update = func_080F6F1C;
    }
    ColliderSetPosition(p->unk_040, p->x, p->y, p->z);
}

void func_080F6F1C(MapTutorialWork* w) {
    if (func_080E02E0((UnkStruct_080DFF1C*)w, 8, 8)) {
        m4aSongNumStart(SONG_SYS_OBJ_BREAK);
        TaskCreate(gFieldState->tasks, &gTaskDescMapSpark, w);
        gUnk_0203C7AC->flags &= ~0x20;
        func_080E8FB8(0, w->x, w->y, w->z);
        AnimStart(&w->anim, 1, 0);
        w->update = func_080F6F90;
        ColliderUnregister(w->unk_040);
    }
}

void func_080F6F90(MapTutorialWork* w) {
    if (AnimIsFinished(&w->anim)) {
        w->update = func_080F6FC4;
    } else {
        w->gfx = AnimUpdate(&w->anim);
    }
}

void func_080F6FC4(MapTutorialWork* w) {
    if ((gUnk_0203C7AC->flags & 0x10) == 0) {
        gGameState.progression.unk_82 |= 0x2000;
        gFieldState->flags |= 0x1000;
        CreateCardMessageTask(&w->tasks, 0, 0x6B);
        w->update = func_080F7024;
    }
}

void func_080F7024(MapTutorialWork* w) {
    if (func_080A42C8() == 0) {
        AnimState* a;
        u8 v;

        func_080E5354((UnkStruct_080DFF1C*)w, &w->y);
        w->z = 0;
        w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
        w->y -= w->unk_00C;
        w->z = w->unk_00C;
        *(u16*)&w->unk_014[6] = 16;
        v = 0;

        if (gFieldState->actor.fieldPosition.x > w->x) {
            v = 1;
        }
        w->unk_0C2 = v;
        w->tiles = AllocObjTiles(0x400, gUnk_0895EECC);
        w->palette = LoadObjPalette(&gUnk_08F691E4[0x5C0], 32);
        a = &w->anim;
        AnimInit(a, gUnk_09EDF940, gUnk_09EDF914);
        AnimStart(a, 0, 1);
        w->gfx = AnimGetGfx(a);
        ColliderInit(w->unk_040, 3, 8, 16);
        ColliderSetPosition(w->unk_040, w->x, w->y, w->z);
        ColliderSetDisabled(w->unk_040, 1);
        w->update = func_080F70F4;
    }
}

void func_080F70F4(MapTutorialWork* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        AnimChangeWithTables(a, 0, 1, gUnk_09EDF85C, gUnk_09EDF834);
        SetObjTileSource(w->tiles, gUnk_08957290);
        CreateCardMessageTask(&w->tasks, 0, 0x6C);
        w->update = func_080F7160;
    } else {
        w->gfx = AnimUpdate(a);
    }
}

void func_080F7160(MapTutorialWork* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (func_080A42C8() == 0) {
        gFieldState->flags &= ~0x1000;
        ColliderSetDisabled(w->unk_040, 0);
        w->update = func_080F71AC;
    }
}

void func_080F71AC(MapTutorialWork* w) {
    AnimState* a = &w->anim;

    w->gfx = AnimUpdate(a);

    if (func_080E02E0((UnkStruct_080DFF1C*)w, 8, 16)) {
        gUnk_0203C7AC->flags |= 0x80;
        gUnk_0203C7AC->flags |= 4;
        TaskCreate(gFieldState->tasks, &gTaskDescMapSpark, w);
        m4aSongNumStart(SONG_SYS_FIELD_ATT00);
        AnimChangeWithTables(a, 0, 1, gUnk_09EDF9BC, gUnk_09EDF9A8);
        SetObjTileSource(w->tiles, gUnk_08963BAC);
        w->update = func_080F7284;
    } else if (w->unk_06C != 0) {
        if (!(gUnk_0203C7AC->flags & 4) && w->unk_074 == 1) {
            ColliderSetDisabled(w->unk_040, 1);
            func_080F6D40();
        } else {
            w->x += w->unk_078;
            w->y += w->unk_07C;
        }
    }
}

void func_080F7284(MapTutorialWork* w) {
    AnimState* a = &w->anim;

    if (AnimIsFinished(a)) {
        ColliderSetDisabled(w->unk_040, 1);
        gGameState.flags |= 4;
        func_080F6D40();
    } else {
        w->gfx = AnimUpdate(a);
    }
}

void Task_MapTutorial_0(MapTutorialWork* w) {
    u16 t;

    TaskPoolInit(&w->tasks, 1);
    TaskPoolInit(&w->tasks2, 1);
    gUnk_0203C7AC->flags |= 0x20;
    w->tiles = 0;
    w->palette = 0;
    w->unk_0C2 = 0;
    t = gGameState.progression.unk_82 & 0x2000;

    if (t == 0) {
        w->unk_0C1 = 0;
        w->unk_0C0 = 0;
        w->update = func_080F6D70;
    } else {
        gFieldState->flags |= 0x1000;
        TaskCreate(&w->tasks2, &gTaskDescFldShadow, w);
        w->unk_0C0 = 1;
        w->unk_0C1 = 1;
        w->update = func_080F7024;
    }
}

s32 Task_MapTutorial_1(MapTutorialWork* w) {
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);

    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void Task_MapTutorial_2(MapTutorialWork* w) {
    u16 flags;
    u16 v;
    s32 k;
    s32 t;
    s16 x;
    s16 y;

    TaskPoolDraw(&w->tasks);

    if (w->unk_0C0 != 0) {
        x = (w->x >> 8) - (gFieldState->x >> 8);
        k = w->y >> 8;
        y = k + (w->z >> 8) - (gFieldState->y >> 8);
        v = -0x1004 - k * 4;
        t = w->unk_0C2;
        flags = 0x800;

        if (t != 0) {
            flags = 0x801;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, flags, v);

        if (w->unk_0C1 != 0) {
            ((UnkStruct_080E64D4*)w)->unk_3C = w->unk_00C;
            ((UnkStruct_080E64D4*)w)->unk_3A = v + 1;
            TaskPoolDraw(&w->tasks2);
        }
    }
}

void Task_MapTutorial_3(MapTutorialWork* w) {
    if (w->tiles != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
    TaskPoolDestroy(&w->tasks);
    TaskPoolDestroy(&w->tasks2);
}

s32 func_080F7488(UnkStruct_080DFF1C* p, s32 lim) {
    s32 dx;
    s32 dy;

    dx = p->x - gFieldState->actor.fieldPosition.x;
    if (dx < 0) {
        dx = gFieldState->actor.fieldPosition.x - p->x;
    }
    dy = p->y - gFieldState->actor.fieldPosition.y;
    if (dy < 0) {
        dy = gFieldState->actor.fieldPosition.y - p->y;
    }

    if (dx > 0x8000 || dy > 0x8000) {
        return 0;
    }
    return Sqrt8((dx * dx >> 8) + (dy * dy >> 8)) < lim ? 1 : 0;
}

void func_080F74E8(UnkStruct_080DFF1C* p) {
    if ((u8)func_080F7488(p, 0x800) != 0) {
        if (gFieldState->actor.fieldPosition.z == gFieldState->actor.fieldPosition.unk_0C) {
            if (gUnk_0203C590.unk_06 == 0xFE) {
                gUnk_0203C7AC->flags |= 0x100;
            } else {
                gUnk_0203C7AC->flags |= 0x400;
            }
        }
    }
}

void func_080F753C(UnkStruct_080DFF1C* p) {
    s32 k = 0x800;

    if ((u8)func_080F7488(p, k) != 0) {
        if (gFieldState->actor.fieldPosition.z == gFieldState->actor.fieldPosition.unk_0C) {
            if (gUnk_0203C590.unk_06 == 0xFE) {
                gUnk_0203C7AC->flags |= k;
            } else {
                gUnk_0203C7AC->flags |= 0x200;
            }
        }
    }
}

void func_080F7594(MapStairWork* w) {
    if ((u8)func_080F7488((UnkStruct_080DFF1C*)w, 0x3000) != 0) {
        gFieldState->flags |= 0x1000;
        gUnk_0203C7AC->flags |= 0x4000;
        CreateCardMessageTask(&w->tasks, 0, 0xA7);
        w->update = func_080F75E4;
    }
}

void func_080F75E4(MapStairWork* w) {
    if (func_080A42C8() == 0) {
        gFieldState->flags &= ~0x1000;
        gUnk_0203C7AC->flags &= ~0x4000;
        gGameState.progression.unk_82 |= 0x400;
        w->update = func_080F74E8;
    }
}

void Task_MapStair_0(MapStairWork* w, UnkStruct_080EF4BC* arg) {
    s32 y;

    w->unk_14 = arg->angle;
    w->unk_00 = arg->unk_00;
    y = arg->unk_04;
    w->unk_0C = 0;
    w->unk_08 = 0;
    w->unk_04 = y;
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    w->tiles = LoadObjTiles(gUnk_08B1EA00, 0xE0);
    w->unk_48 = 0;

    switch (w->unk_14) {
    case 0x2D:
        if ((gGameState.progression.unk_82 & 0x400) == 0 && gUnk_0203C590.unk_06 == 0xFD) {
            w->update = func_080F7594;
        } else {
            w->update = (void (*)(struct MapStairWork*))func_080F74E8;
        }
        break;
    case 0xAD:
        w->update = (void (*)(struct MapStairWork*))func_080F753C;
        break;
    }
    TaskPoolInit(&w->tasks, 1);
}

s32 Task_MapStair_1(MapStairWork* w) {
    TaskPoolUpdate(&w->tasks);

    if (w->update != 0) {
        w->update(w);
    }
    return 1;
}

void Task_MapStair_2(MapStairWork* w) {
    s32 x;
    s32 y;

    TaskPoolDraw(&w->tasks);

    if (w->unk_48 == 1) {
        x = (w->unk_00 >> 8) - (gFieldState->x >> 8);
        y = (w->unk_04 >> 8) + (w->unk_08 >> 8) - (gFieldState->y >> 8);
        DrawSprite(x, y, gUnk_08B1E9A6, w->tiles, w->palette, 0, 0x800, 0x101);
    }
}

void Task_MapStair_3(MapStairWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    TaskPoolDestroy(&w->tasks);
}

void Task_MapFaint_0(MapFaintWork* w, void* a) {
    w->unk_00 = a;
    w->tiles = AllocObjTiles(0x80, gUnk_08B21ACE);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(&w->anim, gUnk_09EE12E4, gUnk_09EE12D4);
    AnimStart(&w->anim, 0, 1);
}

s32 Task_MapFaint_1(u8* work) {
    AnimUpdate((AnimState*)&work[4]);
    return 1;
}

void Task_MapFaint_2(MapFaintWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w->unk_00;
    u16 x;
    u16 y;

    x = (e->unk_00.x >> 8) - (gFieldState->x >> 8);
    y = (e->unk_00.y >> 8) + ((e->unk_00.z - ((s16)e->unk_1A + 8) * 0x100) >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 0x800, -0x1005 - (e->unk_00.y >> 8) * 4);
}

void Task_MapFaint_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(u8**)&work[0x20]);
}

void Task_MapDmg_0(u8* work) {
    s32 z = 0;

    work[8] = z;
    *(void**)&work[0] = LoadObjPalette(gUnk_08F69BE4, 32);
    *(void**)&work[4] = LoadObjTiles(gUnk_08B1EA00, 224);
    *(u16*)&work[10] = z;
    work[9] = 1;
}

s32 Task_MapDmg_1(u8* work) {
    if (work[9] == 0) {
        work[8] = 0;
    } else {
        if (gUnk_0203C7AC->unk_20 != 0 || (gUnk_0203C7AC->flags & 4)) {
            *(u16*)&work[0xA] = 20;
        }

        work[8] = *(u16*)&work[0xA] != 0;

        if (*(u16*)&work[0xA] != 0) {
            *(u16*)&work[0xA] -= 1;
        }
    }
    return 1;
}

void Task_MapDmg_2(u8* work) {
    s16 x;
    s16 y;

    if (work[8] == 0) {
        return;
    }

    x = ((gUnk_0203C7AC->unk_24 - 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 - 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gUnk_08B1E974, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 + 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 - 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gUnk_08B1E97E, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 - 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 + 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gUnk_08B1E992, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 + 0x1400) >> 8) - (gFieldState->x >> 8);
    y = ((gUnk_0203C7AC->unk_28 + 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gUnk_08B1E988, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24) >> 8) - (gFieldState->x >> 8);
    y = ((gUnk_0203C7AC->unk_28) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, gUnk_08B1E9A6, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);
}

void Task_MapDmg_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[4]);
    ReleaseObjPalette(*(u8**)&work[0]);
}

void* GetFloorName(void) {
#ifdef VERSION_EU
    if (gGameState.flags & 8) {
        return eu_0805E924(gBasementFloorNames[(s8)gGameState.floor]);
    }
    return eu_0805E924(gFloorNames[(s8)gGameState.floor]);
#else
    if (gGameState.flags & 8) {
        return gBasementFloorNames[(s8)gGameState.floor];
    }
    return gFloorNames[(s8)gGameState.floor];
#endif
}

void Task_MapFloor_0(MapFloorWork* w) {
    gFieldState->flags |= 0x1000;
    gFieldState->flags |= 0x80;
    w->tiles = LoadObjTiles(gUnk_0993AF64, 0x800);
    w->palette = LoadObjPalette(gUnk_099910C4, 32);
    w->gfx = gUnk_09EF8DA4[0];
    w->unk_0E = 120;
#ifdef VERSION_EU
    InitTextSlots(w->textSlots, 60);
#else
    InitTextSlots(w->textSlots, 40);
#endif
    w->palette2 = _08066468(1);
    w->textSlotCount = LoadTextSlots(GetFloorName(), w->textSlots);
    w->unk_0C = (240 - GetTextSlotsWidth(w->textSlots, w->textSlotCount)) / 2;
}

s32 Task_MapFloor_1(u8* work) {
    u16* p = (u16*)&work[14];

    if (*p != 0) {
        (*p)--;
        return 1;
    }
    return 0;
}

void Task_MapFloor_2(MapFloorWork* w) {
    DrawSprite(120, 138, w->gfx, w->tiles, w->palette, 0, 0, 0x3C);
    DrawTextSlots(w->unk_0C, 0x85, w->textSlots, w->palette2, 50, w->textSlotCount);
}

void Task_MapFloor_3(MapFloorWork* w) {
    ReleaseObjPalette(w->palette);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette2);
#ifdef VERSION_EU
    FreeTextSlots(w->textSlots, 60);
#else
    FreeTextSlots(w->textSlots, 40);
#endif
    gFieldState->flags &= ~0x80;
    gFieldState->flags &= ~0x1000;
}

const u8 gUnk_0984C310[28] = {
    25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
    39, 40, 41, 42, 43, 44, 45, 46, 46, 46, 47, 47, 48, 48,
};

TaskDesc gTaskDescMapGoofy = {
    "Task_MapGoofy",
    (TaskInitFunc)Task_MapGoofy_0,
    (TaskUpdateFunc)Task_MapGoofy_1,
    (TaskFunc)Task_MapGoofy_2,
    (TaskFunc)Task_MapGoofy_3,
    0xEC,
};

TaskDesc gTaskDescMapNamine = {
    "Task_MapNamine",
    (TaskInitFunc)Task_MapNamine_0,
    (TaskUpdateFunc)Task_MapNamine_1,
    (TaskFunc)Task_MapNamine_2,
    (TaskFunc)Task_MapNamine_3,
    0xF0,
};

TaskDesc gTaskDescMapNiseriku = {
    "Task_MapNiseriku",
    (TaskInitFunc)Task_MapNiseriku_0,
    (TaskUpdateFunc)Task_MapNiseriku_1,
    (TaskFunc)Task_MapNiseriku_2,
    (TaskFunc)Task_MapNiseriku_3,
    0xEC,
};

TaskDesc gTaskDescMapMickey = {
    "Task_MapMickey",
    (TaskInitFunc)Task_MapMickey_0,
    (TaskUpdateFunc)Task_MapMickey_1,
    (TaskFunc)Task_MapMickey_2,
    (TaskFunc)Task_MapMickey_3,
    0xEC,
};

TaskDesc gTaskDescMapTutorial = {
    "Task_MapTutorial",
    (TaskInitFunc)Task_MapTutorial_0,
    (TaskUpdateFunc)Task_MapTutorial_1,
    (TaskFunc)Task_MapTutorial_2,
    (TaskFunc)Task_MapTutorial_3,
    0xF0,
};

TaskDesc gTaskDescMapStair = {
    "Task_MapStair",
    (TaskInitFunc)Task_MapStair_0,
    (TaskUpdateFunc)Task_MapStair_1,
    (TaskFunc)Task_MapStair_2,
    (TaskFunc)Task_MapStair_3,
    0x64,
};

TaskDesc gTaskDescMapFaint = {
    "Task_MapFaint",
    (TaskInitFunc)Task_MapFaint_0,
    (TaskUpdateFunc)Task_MapFaint_1,
    (TaskFunc)Task_MapFaint_2,
    (TaskFunc)Task_MapFaint_3,
    0x28,
};

TaskDesc gTaskDescMapDmg = {
    "Task_MapDmg",
    (TaskInitFunc)Task_MapDmg_0,
    (TaskUpdateFunc)Task_MapDmg_1,
    (TaskFunc)Task_MapDmg_2,
    (TaskFunc)Task_MapDmg_3,
    0xC,
};

MapNameText* gFloorNames[13] = {
#if defined(VERSION_US)
    gMapNameTextUs_0815B5F6,
    gMapNameTextUs_0815B630,
    gMapNameTextUs_0815B66C,
    gMapNameTextUs_0815B6A6,
    gMapNameTextUs_0815B6E2,
    gMapNameTextUs_0815B71C,
    gMapNameTextUs_0815B756,
    gMapNameTextUs_0815B794,
    gMapNameTextUs_0815B7D0,
    gMapNameTextUs_0815B80A,
    gMapNameTextUs_0815B844,
    gMapNameTextUs_0815B884,
    gMapNameTextUs_0815B8C2,
#elif defined(VERSION_JP)
    gMapNameTextJp_0814F52C,
    gMapNameTextJp_0814F53C,
    gMapNameTextJp_0814F54C,
    gMapNameTextJp_0814F55C,
    gMapNameTextJp_0814F56C,
    gMapNameTextJp_0814F57C,
    gMapNameTextJp_0814F58C,
    gMapNameTextJp_0814F59C,
    gMapNameTextJp_0814F5AC,
    gMapNameTextJp_0814F5BC,
    gMapNameTextJp_0814F5D0,
    gMapNameTextJp_0814F5E4,
    gMapNameTextJp_0814F5F8,
#elif defined(VERSION_EU)
    &gMapNameEu_08893480,
    &gMapNameEu_0889352C,
    &gMapNameEu_088935D8,
    &gMapNameEu_08893684,
    &gMapNameEu_08893730,
    &gMapNameEu_088937DC,
    &gMapNameEu_0889388C,
    &gMapNameEu_08893938,
    &gMapNameEu_088939E4,
    &gMapNameEu_08893A94,
    &gMapNameEu_08893B48,
    &gMapNameEu_08893BFC,
    &gMapNameEu_08893CB8,
#endif
};

MapNameText* gBasementFloorNames[12] = {
#if defined(VERSION_US)
    gMapNameTextUs_0815B906,
    gMapNameTextUs_0815B948,
    gMapNameTextUs_0815B98A,
    gMapNameTextUs_0815B9C6,
    gMapNameTextUs_0815BA04,
    gMapNameTextUs_0815BA44,
    gMapNameTextUs_0815BA84,
    gMapNameTextUs_0815BAC0,
    gMapNameTextUs_0815BAFE,
    gMapNameTextUs_0815BB3C,
    gMapNameTextUs_0815BB7C,
    gMapNameTextUs_0815BBB8,
#elif defined(VERSION_JP)
    gMapNameTextJp_0814F60C,
    gMapNameTextJp_0814F624,
    gMapNameTextJp_0814F63C,
    gMapNameTextJp_0814F654,
    gMapNameTextJp_0814F668,
    gMapNameTextJp_0814F67C,
    gMapNameTextJp_0814F690,
    gMapNameTextJp_0814F6A4,
    gMapNameTextJp_0814F6B8,
    gMapNameTextJp_0814F6CC,
    gMapNameTextJp_0814F6E0,
    gMapNameTextJp_0814F6F4,
#elif defined(VERSION_EU)
    &gMapNameEu_08893D78,
    &gMapNameEu_08893E38,
    &gMapNameEu_08893EF4,
    &gMapNameEu_08893FAC,
    &gMapNameEu_08894068,
    &gMapNameEu_08894124,
    &gMapNameEu_088941DC,
    &gMapNameEu_08894294,
    &gMapNameEu_0889434C,
    &gMapNameEu_08894408,
    &gMapNameEu_088944C0,
    &gMapNameEu_08894578,
#endif
};

TaskDesc gTaskDescMapFloor = {
    "Task_MapFloor",
    (TaskInitFunc)Task_MapFloor_0,
    (TaskUpdateFunc)Task_MapFloor_1,
    (TaskFunc)Task_MapFloor_2,
    (TaskFunc)Task_MapFloor_3,
#ifdef VERSION_EU
    0x1F8,
#else
    0x158,
#endif
};
