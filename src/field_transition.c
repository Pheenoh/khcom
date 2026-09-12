#include "mode.h"
#include "obj_api.h"
#include "macros.h"
#include "battle.h"

void func_080100A0(void);

FieldTransitionWork* gUnk_020348C8;

void func_0801007C(void) {
    FieldTransitionWork* p;
    FieldTransitionWork** pp = &gUnk_020348C8;
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
        ReleaseObjTiles(gUnk_020348C8->tiles);
        ReleaseObjPalette(gUnk_020348C8->palette);
        EwramFree(gUnk_020348C8);
        func_08001080();
        return;
    }
    (*(vu16*)0x04000000) |= 0x1000;
    gSystemFlags |= 8;
    if (gUnk_020348C8->initialized == 0) {
        gUnk_020348C8->tiles = AllocObjTiles(0xA00, 0);
        if (gGameState.flags & 8) {
            gUnk_020348C8->palette = LoadObjPalette(gUnk_09618118, 0x20);
            AnimInit(&gUnk_020348C8->anim, 0, 0);
            switch (gGameState.unk_024) {
            case 0:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDF514, gUnk_09EDF4F4);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_08935BC2);
                break;
            case 45:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EEF938, gUnk_09EEF918);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_092F15E4);
                gUnk_020348C8->flipped = 1;
                break;
            case 64:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EEF914, gUnk_09EEF8F4);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_092EFAD4);
                gUnk_020348C8->flipped = 1;
                break;
            case 83:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EEF8F0, gUnk_09EEF8D0);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_092ED9F6);
                gUnk_020348C8->flipped = 1;
                break;
            case 128:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDF4F0, gUnk_09EDF4D0);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_0893416A);
                break;
            case 173:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EEF8F0, gUnk_09EEF8D0);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_092ED9F6);
                break;
            case 192:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EEF914, gUnk_09EEF8F4);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_092EFAD4);
                break;
            default:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EEF938, gUnk_09EEF918);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_092F15E4);
                break;
            }
        } else {
            gUnk_020348C8->palette = LoadObjPalette(gUnk_08F683A4, 0x20);
            AnimInit(&gUnk_020348C8->anim, 0, 0);
            switch (gGameState.unk_024) {
            case 0:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDED5C, gUnk_09EDED3C);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088DC192);
                break;
            case 45:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDEB88, gUnk_09EDEB68);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088CE0C2);
                gUnk_020348C8->flipped = 1;
                break;
            case 64:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDEA90, gUnk_09EDEA70);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088C5AAA);
                gUnk_020348C8->flipped = 1;
                break;
            case 83:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDEA0C, gUnk_09EDE9EC);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088C1388);
                gUnk_020348C8->flipped = 1;
                break;
            case 128:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDE940, gUnk_09EDE920);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088BAC36);
                break;
            case 173:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDEA0C, gUnk_09EDE9EC);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088C1388);
                break;
            case 192:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDEA90, gUnk_09EDEA70);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088C5AAA);
                break;
            default:
                AnimChangeWithTables(&gUnk_020348C8->anim, 0, 1, (s32)gUnk_09EDEB88, gUnk_09EDEB68);
                SetObjTileSource(gUnk_020348C8->tiles, gUnk_088CE0C2);
                break;
            }
        }
        gUnk_020348C8->initialized++;
    }
    gfx = AnimUpdate(&gUnk_020348C8->anim);
    if (gUnk_020348C8->flipped != 0) {
        DrawSprite(120, 96, gfx, gUnk_020348C8->tiles, gUnk_020348C8->palette, 0, 1, 0);
    } else {
        DrawSprite(120, 96, gfx, gUnk_020348C8->tiles, gUnk_020348C8->palette, 0, 0, 0);
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
