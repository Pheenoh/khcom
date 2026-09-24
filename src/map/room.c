#include "registration_data.h"
#include "chara_api.h"
#include "text.h"
#include "monsgage.h"
#include "room.h"
#include "sprites_room.h"
#include "sprites_map_tasks.h"
#include "map_text_data.h"
#include "map_text_assets.h"
#include "jiminy_data.h"

MapNameText* gUnk_09EF7048[28] = {
#if defined(VERSION_US)
    gUnk_0815ADD2,
    gUnk_0815ADF4,
    gUnk_0815AE18,
    gUnk_0815AE34,
    gUnk_0815AE56,
    gUnk_0815AE7A,
    gUnk_0815AE9E,
    gUnk_0815AEBE,
    gUnk_0815AEE2,
    gUnk_0815AEFA,
    gUnk_0815AFD4,
    gUnk_0815AFEC,
    gUnk_0815B02E,
    gUnk_0815B00E,
    gUnk_0815AF70,
    gUnk_0815B04C,
    gUnk_0815AF14,
    gUnk_0815AF38,
    gUnk_0815AF52,
    gUnk_0815AF8E,
    gUnk_0815AFA8,
    gUnk_0815AFBE,
    gUnk_0815B06C,
    gUnk_0815B090,
    gUnk_0815B0B0,
    gUnk_0815B0CA,
    gMapNameTextUs_0815ADB6,
    gMapNameTextUs_0815B5C4,
#elif defined(VERSION_JP)
    gUnkJp_0814F358,
    gUnkJp_0814F364,
    gUnkJp_0814F374,
    gUnkJp_0814F380,
    gUnkJp_0814F390,
    gUnkJp_0814F39C,
    gUnkJp_0814F3A8,
    gUnkJp_0814F3B8,
    gUnkJp_0814F3C8,
    gUnkJp_0814F3D8,
    gUnkJp_0814F3E8,
    gUnkJp_0814F3F8,
    gUnkJp_0814F408,
    gUnkJp_0814F418,
    gUnkJp_0814F428,
    gUnkJp_0814F438,
    gUnkJp_0814F448,
    gUnkJp_0814F460,
    gUnkJp_0814F474,
    gUnkJp_0814F484,
    gUnkJp_0814F494,
    gUnkJp_0814F4A4,
    gUnkJp_0814F4B4,
    gUnkJp_0814F4CC,
    gUnkJp_0814F4E4,
    gUnkJp_0814F4F8,
    gMapNameTextJp_0814F510,
    gMapNameTextJp_0814F520,
#elif defined(VERSION_EU)
    &gUnkEu_0889294C,
    &gUnkEu_088929B0,
    &gUnkEu_08892A14,
    &gUnkEu_08892A78,
    &gUnkEu_08892AE0,
    &gUnkEu_08892B48,
    &gUnkEu_08892BB0,
    &gUnkEu_08892C18,
    &gUnkEu_08892C74,
    &gUnkEu_08892CD0,
    &gUnkEu_08892D20,
    &gUnkEu_08892D88,
    &gUnkEu_08892DEC,
    &gUnkEu_08892E54,
    &gUnkEu_08892EC0,
    &gUnkEu_08892F24,
    &gUnkEu_08892F94,
    &gUnkEu_08892FF4,
    &gUnkEu_08893058,
    &gUnkEu_088930B0,
    &gUnkEu_08893108,
    &gUnkEu_0889315C,
    &gUnkEu_088931D0,
    &gUnkEu_08893238,
    &gUnkEu_088932A4,
    &gUnkEu_08893310,
    &gMapNameEu_08893370,
    &gMapNameEu_088933D4,
#endif
};

void task_room_name_0(RoomNameWork* work, s32 arg) {
    work->tiles = LoadObjTiles(gUnk_0993AF64, 0x800);
    work->palette = LoadObjPalette(gUnk_099910C4, 0x20);
    work->gfx = gUnk_09EF8DA4[0];
    work->unk_30 = arg;
    work->x2 = 0x5C00;
    work->y2 = 0x8A00;
    work->x = 0x7800;
    work->y = 0x8A00;
    work->unk_20 = 0x400;
    work->unk_24 = 0x19;
    work->timer = 0;
    work->unk_2C = 0;
    work->state = 0;
    work->unk_1C = 0x19;
    InitTextSlots(work->unk_3C, 0x24);
    work->palette2 = _08066468(1);
#ifdef VERSION_EU
    work->unk_34 = LoadTextSlots(eu_0805E924(gUnk_09EF7048[work->unk_30]), work->unk_3C);
#else
    work->unk_34 = LoadTextSlots(gUnk_09EF7048[work->unk_30], work->unk_3C);
#endif
}

u8 task_room_name_1(RoomNameWork* work) {
    if (gFieldState->flags & 0x42000) {
        return 0;
    }

    switch (work->state) {
    case 0:
        work->timer++;
        if (work->timer > 0x27) {
            work->timer = 0;
            work->state++;
        }
        break;
    case 1:
        work->timer++;
        if (work->timer > 1) {
            work->timer = 0;
            work->y2 -= 0x99;
            work->unk_1C += 0x19;
            if (work->unk_1C > 0xFF) {
                work->unk_1C = 0x100;
                work->state++;
            }
        }
        break;
    case 2:
        work->timer++;
        if (work->timer > 0xB3) {
            work->timer = 0;
            work->state++;
        }
        break;
    case 3:
        work->timer++;
        if (work->timer > 1) {
            work->timer = 0;
            work->y2 += 0x99;
            work->unk_1C -= 0x19;
            if (work->unk_1C <= 0x19) {
                work->unk_1C = 0x19;
                return 0;
            }
        }
        break;
    }
    return 1;
}

void task_room_name_2(RoomNameWork* work) {
    s32 affine;

    if (work->state != 0) {
        affine = AllocObjAffine(0, 0x100, work->unk_1C, 0);
        DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, affine, 0, 0x3C);
        DrawTextSlots(work->x2 >> 8, work->y2 >> 8, work->unk_3C, work->palette2, 0x32, work->unk_34);
    }
}

void task_room_name_3(RoomNameWork* work) {
    ReleaseObjTiles(work->tiles);
    FreeTextSlots(work->unk_3C, 0x24);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}

const char gTaskNameRoomName[] = "task_room_name";

TaskDesc gTaskDescRoomName = {
    gTaskNameRoomName,
    (void (*)(void*, void*))task_room_name_0,
    task_room_name_1,
    (void (*)(void*))task_room_name_2,
    (void (*)(void*))task_room_name_3,
    0x15C,
};
