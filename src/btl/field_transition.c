#include "mode.h"
#include "obj_api.h"
#include "battle.h"
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_riku.h"
#include "sprites_sora.h"

void func_080100A0(void);

FieldTransitionWork* gFieldTransitionWork;

void func_0801007C(void) {
    FieldTransitionWork* p;
    FieldTransitionWork** pp = &gFieldTransitionWork;
    p = EwramAlloc(0x24);
    *pp = p;
    p->initialized = 0;
    p->tiles = 0;
    p->palette = 0;
    p->flipped = 0;
}

void func_080100A0(void) {
    void* gfx;
    if (IsModeStarted()) {
        ReleaseObjTiles(gFieldTransitionWork->tiles);
        ReleaseObjPalette(gFieldTransitionWork->palette);
        EwramFree(gFieldTransitionWork);
        func_08001080();
        return;
    }
    REG_DISPCNT |= DISPCNT_OBJ_ON;
    gSystemFlags |= 8;
    if (gFieldTransitionWork->initialized == 0) {
        gFieldTransitionWork->tiles = AllocObjTiles(0xA00, 0);
        if (gGameState.flags & 8) {
            gFieldTransitionWork->palette = LoadObjPalette(gRikuPalette, 0x20);
            AnimInit(&gFieldTransitionWork->anim, 0, 0);
            switch (gGameState.unk_024) {
            case 0:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gUnk_09EDF514, gUnk_09EDF4F4);
                SetObjTileSource(gFieldTransitionWork->tiles, gUnk_08935BC2);
                break;
            case 45:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gRik1bl01Anims, gRik1bl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gRik1bl01Tiles);
                gFieldTransitionWork->flipped = 1;
                break;
            case 64:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gRik1ll01Anims, gRik1ll01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gRik1ll01Tiles);
                gFieldTransitionWork->flipped = 1;
                break;
            case 83:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gRik1fl01Anims, gRik1fl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gRik1fl01Tiles);
                gFieldTransitionWork->flipped = 1;
                break;
            case 128:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gUnk_09EDF4F0, gUnk_09EDF4D0);
                SetObjTileSource(gFieldTransitionWork->tiles, gUnk_0893416A);
                break;
            case 173:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gRik1fl01Anims, gRik1fl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gRik1fl01Tiles);
                break;
            case 192:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gRik1ll01Anims, gRik1ll01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gRik1ll01Tiles);
                break;
            default:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gRik1bl01Anims, gRik1bl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gRik1bl01Tiles);
                break;
            }
        } else {
            gFieldTransitionWork->palette = LoadObjPalette(gSoraPalette, 0x20);
            AnimInit(&gFieldTransitionWork->anim, 0, 0);
            switch (gGameState.unk_024) {
            case 0:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1bb01Anims, gSor1bb01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1bb01Tiles);
                break;
            case 45:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1bl01Anims, gSor1bl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1bl01Tiles);
                gFieldTransitionWork->flipped = 1;
                break;
            case 64:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1ll01Anims, gSor1ll01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1ll01Tiles);
                gFieldTransitionWork->flipped = 1;
                break;
            case 83:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1fl01Anims, gSor1fl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1fl01Tiles);
                gFieldTransitionWork->flipped = 1;
                break;
            case 128:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1ff01Anims, gSor1ff01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1ff01Tiles);
                break;
            case 173:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1fl01Anims, gSor1fl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1fl01Tiles);
                break;
            case 192:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1ll01Anims, gSor1ll01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1ll01Tiles);
                break;
            default:
                AnimChangeWithTables(&gFieldTransitionWork->anim, 0, 1, (s32)gSor1bl01Anims, gSor1bl01Frames);
                SetObjTileSource(gFieldTransitionWork->tiles, gSor1bl01Tiles);
                break;
            }
        }
        gFieldTransitionWork->initialized++;
    }
    gfx = AnimUpdate(&gFieldTransitionWork->anim);
    if (gFieldTransitionWork->flipped != 0) {
        DrawSprite(120, 96, gfx, gFieldTransitionWork->tiles, gFieldTransitionWork->palette, 0, 1, 0);
    } else {
        DrawSprite(120, 96, gfx, gFieldTransitionWork->tiles, gFieldTransitionWork->palette, 0, 0, 0);
    }
    gSystemFlags &= ~8;
    func_08002F50();
}
void func_080104F4(void) {
    func_08001058(func_0801007C, func_080100A0);
}

u8 func_0801050C(s32* a, s32* b, s32* c, s32* d) {
    if (*b < 0x24000) {
        if (*c > -0x2000) {
            *d = 0;
            *b = 0x24000;
            return 1;
        }
        *d = -0x2000;
    } else {
        *d = 0;
    }
    return 0;
}
