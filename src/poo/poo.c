#include "macros.h"
#include "localized_resource_assets.h"
#include "registration_data.h"
#include "system_state.h"
#include "obj_api.h"
#include "poo.h"
#include "poo_api.h"
#include "background_actor_assets.h"
#include "mode_chkobj_assets.h"
#include "anim.h"
#include "sprites_btl.h"
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_map.h"
#include "sprites_pooh.h"
#include "sprites_sora.h"

u8 gUnk_0203C3D8 EWRAM_COMMON(4);
s32 gUnk_0203C3DC EWRAM_COMMON(4);
u16 gUnk_0203C3E0 EWRAM_COMMON(4);
u16 gUnk_0203C3E4 EWRAM_COMMON(4);
s32 gUnk_0203C3E8 EWRAM_COMMON(4);
struct PooPos* gUnk_0203C3EC EWRAM_COMMON(4);
u32 gUnk_0203C3F0 EWRAM_COMMON(4);
u32 gUnk_0203C3F4 EWRAM_COMMON(4);
u16 gUnk_0203C3F8 EWRAM_COMMON(4);
s32 gUnk_0203C3FC EWRAM_COMMON(4);
s32 gUnk_0203C400 EWRAM_COMMON(4);
s32 gUnk_0203C404 EWRAM_COMMON(4);
s32 gUnk_0203C408 EWRAM_COMMON(4);
u16 gUnk_0203C40C EWRAM_COMMON(4);
struct PooNode* gUnk_0203C410 EWRAM_COMMON(4);
void* gUnk_0203C414 EWRAM_COMMON(4);
PooActor gPooActor EWRAM_COMMON(16);
u8* gStockMesDispWork EWRAM_COMMON(4);
PooState gPooState EWRAM_COMMON(16);
void* gUnk_0203C4B4 EWRAM_COMMON(4);

extern AnimDef gUnk_09EF4C88[5];

#ifdef VERSION_EU
extern u8* gUnkEu_09F800A4[5];
extern u8* gUnkEu_09F800B8[5];
#endif

PooWork* gPooWork;
u32 gUnk_02034DAC;
PooSpawnArgs gPooSpawnArgs;
u32 gUnk_02034DC4;
PooPos gUnk_02034DC8;
s32 gUnk_02034DD8;
s32 gUnk_02034DDC;
u8 gUnk_02034DE0;
u8 gUnk_02034DE1;
s32 gUnk_02034DE4;
PooSoraWork* gPooSoraWork;
u16 gUnk_02034DEC;
s32 gUnk_02034DF0;
s32 gUnk_02034DF4;
ListPool gUnk_02034DF8;
PooPos gUnk_02034E08;
u16 gUnk_02034E18;
u32 gUnk_02034E1C;
PooCamera* gPooCamera;
u16 gUnk_02034E24;
u16 gUnk_02034E26;
u16 gUnk_02034E28;
u32 gUnk_02034E2C;
PooBeeAfterEventWork* gPooBeeAfterEventWork;
u16 gUnk_02034E34;
u16 gUnk_02034E36;
u16 gUnk_02034E38;
u16 gUnk_02034E3A;

void task_poo_pooh_0(PooWork* w) {
    PooShadowArgs args;

    gPooWork = w;
    w->unk_CC = 0;
    func_080D2CD0(&gUnk_0203C3E4, &gUnk_0203C3E0);
    w->unk_D0 = 0;
    w->unk_D4 = 0;
    gUnk_0203C3F0 = 0;
    w->unk_DC = 0;
    w->unk_F8 = 0;
    w->angle = 45;
    w->unk_3A = 45;
    w->unk_3B = w->angle;
    func_080C7CC8(w);
    w->unk_3C = 0;
    w->unk_24 = 0;
    w->unk_26 = 0xFFFF;
    func_080D2CA8(&w->pos, &gUnk_02034DAC);
    w->pos.unk_0C = 0;
    w->unk_40 = w->pos.x;
    w->unk_44 = w->pos.y;
    gUnk_0203C3EC = &w->pos;
    w->tiles = AllocObjTiles((u16)(gUnk_096FC010.unk_04 * 32), 0);
    w->palette = LoadObjPalette(gUnk_096FC010.unk_00, 32);
    AnimInit(w->unk_0C, 0, 0);
    func_080C84E0(w, gUnk_02034DAC);
    w->unk_FA = 0;
    func_080C7FEC(w, gUnk_02034DAC);
    w->gfx = AnimGetGfx(w->unk_0C);
    ColliderInit(w->unk_4C, 9, gUnk_096FC010.unk_08, gUnk_096FC010.unk_06);
    ColliderSetPosition(w->unk_4C, w->pos.x, w->pos.y, w->pos.z);
    TaskPoolInit(&w->tasks, 10);
    args.pos = &w->pos;
    args.shadowInfo = (PooShadowInfo*)&w->unk_E0;
    TaskCreate(&w->tasks, &gTaskDescPooShadowdodai, &args);
    w->task = 0;
    w->unk_C8 = 0;
    w->unk_EC = func_080C8B38((PooAim*)w->unk_4C, &w->pos, &w->unk_E8);
}

u8 func_080C871C(PooWork* w) {
    if (gUnk_0203C3F0 == 1) {
        func_080C84E0(w, 16);
        w->pos.x = gUnk_0203C3DC;
        w->pos.y = gUnk_0203C3E8;
    } else if (gUnk_0203C3F0 == 2) {
        w->pos.x = gUnk_0203C3DC;
        w->pos.y = gUnk_0203C3E8;
        func_080C84E0(w, 38);
    } else if (gUnk_0203C3F0 == 7) {
        w->pos.x = gUnk_0203C3DC;
        w->pos.y = gUnk_0203C3E8;
        func_080C84E0(w, 39);
    } else if (gUnk_0203C3F0 == 8) {
        w->angle = GetAngle(w->pos.x, w->pos.y, gUnk_0203C3DC, gUnk_0203C3E8);
        w->unk_3A = w->angle;
        w->unk_3B = w->angle;
        func_080C84E0(w, 20);
    } else if (gUnk_0203C3F0 == 11) {
        w->angle = GetAngle(w->pos.x, w->pos.y, gUnk_0203C3DC, gUnk_0203C3E8);
        w->unk_3A = w->angle;
        w->unk_3B = w->angle;
        w->unk_F6 = 0;
        func_080C84E0(w, 21);
    } else if (gUnk_0203C3F0 == 3) {
        func_080C84E0(w, 32);
    } else if (gUnk_0203C3F0 == 4 || gUnk_0203C3F0 == 6) {
        func_080C84E0(w, 0);
    } else if (gUnk_0203C3F0 == 5) {
        func_080C84E0(w, 10);
    } else if (gUnk_0203C3F0 == 9) {
        func_080C84E0(w, 12);
    } else if (gUnk_0203C3F0 == 10) {
        func_080C84E0(w, 11);
    } else if (gUnk_0203C3F0 == 12) {
        gUnk_0203C3F0 = 0;
        return 0;
    } else {
        func_080C84E0(w, 10);
    }

    gUnk_0203C3F0 = 0;
    return 1;
}

u8 func_080C887C(PooWork* w, PooNode* n) {
    if (ColliderIsTouchingType(w->unk_4C, 1) != 0) {
        if (func_080CFF30() == 0) {
            func_080C84E0(w, 10);
            return 1;
        }
    }

    if (gUnk_0203C3F0 != 0) {
        return func_080C871C(w);
    }
    return 0;
}

void func_080C88C4(PooWork* w, PooNode* n) {
    if (n != 0) {
        if (func_080CBA4C() != 0) {
            if (w->unk_DC != 0 || w->unk_D0 == gUnk_0203C410) {
                w->unk_F8++;

                if (w->unk_F8 > 10) {
                    w->unk_DC = 0;
                    w->unk_F8 = 0;
                    func_080C84E0(w, 29);
                }
                return;
            }
            w->unk_DC = 90;
        }

        if (w->unk_DC != 0) {
            w->unk_DC--;
            n = gUnk_0203C410;
        }

        if (w->unk_D0 != n && w->unk_D4 <= 59) {
            w->unk_3A = w->angle;
            w->unk_3B = w->angle;
            w->unk_39 = GetAngle(w->pos.x, w->pos.y, ((PooPos*)n->unk_08)->x, ((PooPos*)n->unk_08)->y);
            w->unk_40 = w->pos.x;
            w->unk_44 = w->pos.y;
            func_080C84E0(w, 9);
        } else {
            w->unk_D0 = n;
            w->unk_D4 = 0;
            w->unk_40 = ((PooPos*)w->unk_D0->unk_08)->x;
            w->unk_44 = ((PooPos*)w->unk_D0->unk_08)->y;
            func_080C84E0(w, 3);
        }
    } else {
        w->unk_40 = w->pos.x;
        w->unk_44 = w->pos.y;
        func_080C84E0(w, 23);
    }
}

void func_080C89B4(PooWork* w, const PooSpot* b, u16 c) {
    u16 f;
    s32 v;
    s32 i;

    f = AnimGetFrame(w->unk_0C) + 1;

    if (w->unk_78 == 0) {
        i = w->unk_A8 * c + f;
        v = b[i].unk_00;

        if (w->unk_24 != 0) {
            v = -v;
        }
        w->pos.x += v;
        v = b[i].unk_04;
        w->pos.y += v;
    }
    w->pos.z += b[w->unk_A8 * c + f].unk_08;
}

void func_080C8A28(PooWork* w) {
    func_080C89B4(w, gUnk_096FC05C, 11);
}

void func_080C8A3C(PooWork* w) {
    func_080C89B4(w, gUnk_096FC2F0, 0x10);
}

s32 func_080C8A50(PooWork* w) {
    PooPoint t[4];
    u32 i;

    memcpy(t, gUnk_096FC6B0, sizeof(t));

    for (i = 0; i < 4; i++) {
        if (w->unk_90 == t[i].unk_00 && w->unk_94 == t[i].unk_04) {
            break;
        }
    }
    return i;
}

void func_080C8AB8(PooWork* w) {
    w->unk_F4 = 0;
    w->unk_F0 = func_080C8A50(w);
}

u32 func_080C8AD4(u32 a) {
    a++;
    if (a > 3) {
        a = 0;
    }
    return a;
}

void func_080C8AE0(PooWork* w) {
    s32 t;

    t = func_080C8A50(w);
    if (t == func_080C8AD4(w->unk_F0)) {
        w->unk_F0 = t;
        w->unk_F4++;
        if (w->unk_F4 > 3) {
            if (func_080D2D50(1) == 0) {
#ifdef VERSION_EU
                func_080C7B84(0x8B);
#else
                func_080C7B84(0x8D);
#endif
                func_080D2D3C(1);
                func_0800FDD0(0x52);
            }
        }
    } else {
        func_080C8AB8(w);
    }
}

s32 func_080C8B38(PooAim* w, PooPos* p, u8* c) {
    s32 v;

    if ((w->unk_2E & 1) != 0) {
        if (p->unk_0C < w->unk_40) {
            v = p->unk_0C;
        } else {
            v = w->unk_40;
        }
        *c = 1;
    } else {
        *c = 0;
        v = p->unk_0C;
    }
    return v;
}

void func_080C8B60(PooMover* w, s32 b, u8 c) {
    w->unk_3C += 6;
    if (w->unk_3C > b) {
        w->unk_3C = b;
    }

    if (c != 0) {
        w->unk_3A = w->angle = GetAngle(w->unk_28, w->unk_2C, w->unk_40, w->unk_44);
        w->unk_3B = w->angle;
    }
    w->unk_28 += gSineTable[w->angle] * w->unk_3C >> 8;
    w->unk_2C += -gSineTable[w->angle + 0x40] * w->unk_3C >> 8;
}

u8 func_080C8BD4(void) {
    s16 x;
    s16 y;

    x = (gUnk_0203C3EC->x >> 8) - gUnk_0203C40C;
    y = (gUnk_0203C3EC->y >> 8) + (gUnk_0203C3EC->z >> 8) - gUnk_0203C3F8;
    if (x < gUnk_096FC010.unk_08 * 2 || 240 - gUnk_096FC010.unk_08 * 2 < x || y < gUnk_096FC010.unk_06 * 2 || y > 152) {
        return 1;
    }
    return 0;
}

void func_080C8C40(PooWork* w, PooNode* n) {
    u16 a0;
    u16 a1;
    u16 a2;
    u16 v;
    u16 c;
    s32 b;

    switch (gUnk_02034DAC) {
    case 3:
        if (AnimGetGfxIndex((AnimState*)w->unk_0C) == 8 && gUnk_0203C3EC->y > 0x1BD00 && (GetKeysPressed() & 1) != 0) {
            v = 128;

            if (func_080D1738() != 0) {
                v = 2;
            }

            if (GetRandom() % v == 0) {
                func_080C84E0(w, 17);
            }
            break;
        }
        b = 0x4C;

        if (func_080CBA74() != 0 && w->unk_D0 == n && n == gUnk_0203C410) {
            b = 152;
            w->unk_3C = 152;
        } else if (w->unk_3C > 82) {
            b = w->unk_3C - 6;
        }
        func_080C8B60((PooMover*)w, b, 1);

        if (func_080C887C(w, n) != 0) {
            w->unk_3C = 0;
        } else {
            func_080C88C4(w, n);
        }
        break;
    case 10:
        if (w->unk_78 != 0) {
            if (ColliderIsTouchingType(w->unk_4C, 1) != 0) {
                break;
            }

            if (func_080CBA4C() == 0) {
                break;
            }
            w->pos.x += w->unk_84;
            w->pos.y += w->unk_88;
            w->unk_D0 = 0;
            func_080C88C4(w, n);
            break;
        }

        if (func_080C8404(&w->pos, &gPooActor) > 0x1B00) {
            func_080C84E0(w, 0);
        }
        break;
    case 12:
        a0 = w->unk_3A;
        w->unk_39 = GetAngle(w->pos.x, w->pos.y, 0x8DE00, 0x45C00);
        ApproachAngle(&a0, w->unk_39, 4);
        w->unk_3A = a0;
        w->unk_D4++;

        if (func_080D0E3C() == 0) {
            break;
        }
        func_080C84E0(w, 15);
        w->angle = 64;
        w->unk_3A = 64;
        w->unk_3B = w->angle;
        break;
    case 15:
        w->pos.z += w->unk_48;
        w->unk_48 += 71;

        if (w->pos.z < 0) {
            break;
        }
        w->pos.z = 0;
        func_080C84E0(w, 5);
        w->unk_3C = 228;
        break;
    case 5:
        w->unk_40 = 0x87F00;
        w->unk_44 = 0x4B700;
        func_080C8B60((PooMover*)w, 456, 1);

        if (func_080C83C4(w->unk_40 >> 8, w->unk_44 >> 8, w->pos.x >> 8, w->pos.y >> 8) == 0) {
            break;
        }
        func_080C84E0(w, 6);
        break;
    case 6:
        w->unk_40 = 0x75D00;
        w->unk_44 = 0x49E00;
        func_080C8B60((PooMover*)w, 456, 1);

        if (func_080C83C4(w->unk_40 >> 8, w->unk_44 >> 8, w->pos.x >> 8, w->pos.y >> 8) == 0) {
            break;
        }
        func_080C84E0(w, 14);
        func_0802F1E8();
        m4aSongNumStart(372);
        break;
    case 0:
        if (w->pos.z < 0) {
            func_080C84E0(w, 1);
            break;
        }
        func_080C88C4(w, n);

        if (gUnk_02034DAC != 0) {
            break;
        }

        if (w->unk_D0 == 0) {
            break;
        }
        c = func_080CCB80(&w->unk_D0->unk_00);

        if (c <= 1) {
            break;
        }
        c >>= 1;
        func_080CCB84(&w->unk_D0->unk_00, c);
        break;
    case 29:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 30);
        break;
    case 30:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (w->unk_DA <= 1) {
            w->unk_DA++;
            AnimReset((AnimState*)w->unk_0C);
            break;
        }

        if (AnimIsFrameEnding((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (AnimGetFrame((AnimState*)w->unk_0C) != 0) {
            break;
        }
        func_080C84E0(w, 31);
        break;
    case 31:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 9);
        break;
    case 9:
        if (w->unk_D4 <= 59) {
            a1 = w->unk_3A;
            w->unk_39 = GetAngle(w->pos.x, w->pos.y, ((s32*)n->unk_08)[0], ((s32*)n->unk_08)[1]);
            ApproachAngle(&a1, w->unk_39, 4);
            w->unk_3A = a1;
            w->unk_D4++;
        } else {
            func_080C88C4(w, n);
        }
        break;
    case 16:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (w->pos.x == 0x4A700 && w->pos.y == 0x28E00 && func_080D2D50(5) == 0) {
            func_080C84E0(w, 37);
            TaskCreate(&w->tasks, &gTaskDescPooRoo, &w->pos);
            break;
        }
        func_080C84E0(w, 36);
        break;
    case 37:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 38);
        w->pos.z -= 0x1700;
        func_080CA0B4();
        break;
    case 36:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 38);
        break;
    case 38:
        if (w->unk_AC <= 59) {
            w->pos.z -= 204;
        } else if (w->unk_AC <= 79) {
            w->pos.z -= 204;
        } else {
            w->pos.z += 204;
        }

        if (w->unk_AC > 60) {
            w->pos.x += 128;
            w->pos.y += 64;
        }
        w->unk_AC++;

        if (w->unk_AC > 80 && w->pos.z >= -0x800 && IsTaskActive(w->task) != 0) {
            func_08000DE8(&w->tasks, w->task);
            TaskCreate(&w->tasks, &gTaskDescPooFreeballoon, &w->pos);
            gUnk_0203C3F0 = 0;
        }

        if (w->pos.z < 0) {
            break;
        }
        w->pos.z = 0;

        if (ColliderIsTouchingType(w->unk_4C, 1) != 0) {
            func_080C84E0(w, 0);
            break;
        }

        if (gUnk_0203C3F0 == 0) {
            func_080C84E0(w, 0);
            break;
        }
        func_080C871C(w);
        break;
    case 39:
        w->pos.z -= 204;

        if (w->pos.z > -0xD500) {
            break;
        }

        if (IsTaskActive(w->task) != 0) {
            func_08000DE8(&w->tasks, w->task);
        }
        func_080C84E0(w, 22);
        break;
    case 22:
        if (w->pos.z < -0x1000) {
            w->pos.z += 204;
            break;
        }

        if (func_080D2D50(3) == 0) {
#ifdef VERSION_EU
            func_080C7B84(135);
#else
            func_080C7B84(137);
#endif
            func_080D2D3C(3);
            func_0800FDD0(79);
        } else {
#ifdef VERSION_EU
            func_080C7B84(136);
#else
            func_080C7B84(138);
#endif
        }
        break;
    case 17:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            if (w->unk_DA > 40) {
                func_080C84E0(w, 18);
                func_080C8A3C(w);
                w->pos.z = 0;
            }
            w->unk_DA++;
            break;
        }

        if (AnimIsFrameEnding((AnimState*)w->unk_0C) != 0) {
            func_080C8A28(w);
        }
        w->unk_DA = 0;
        break;
    case 18:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 0);
            break;
        }

        if (AnimIsFrameEnding((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C8A3C(w);
        break;
    case 21:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (w->unk_A8 == 0) {
            if (w->unk_24 != 0) {
                w->angle = 19;
            } else {
                w->angle = 224;
            }
        } else {
            if (w->unk_24 != 0) {
                w->angle = 83;
            } else {
                w->angle = 147;
            }
        }
        w->unk_3A = w->angle;
        w->unk_3B = w->angle;
        w->unk_FB = w->angle;
        func_080C84E0(w, 2);
        w->unk_48 = 0;
        w->pos.z = -0xD00;

        if (w->unk_24 == 0) {
            w->pos.x -= 0x900;
        } else {
            w->pos.x += 0x900;
        }

        if (w->unk_F6 == 0) {
            func_080D0084((u32*)&w->pos.x, (u32*)&w->pos.y, 1);
            break;
        }

        while ((u8)func_080CFEA0(&w->pos) != 0) {
            w->pos.x += gSineTable[w->angle] * 2;
            w->pos.y -= gSineTable[w->angle + 0x40] * 2;
        }
        break;
    case 2:
        w->pos.z += w->unk_48;
        w->unk_48 += 17;

        if (w->pos.z < 0) {
            break;
        }
        w->pos.z = 0;

        if (w->unk_F6 == 0) {
            func_080C84E0(w, 13);
            break;
        }
        func_080C84E0(w, 0);
        gUnk_0203C3F0 = 0;
        break;
    case 13:
        if (func_080CBA4C() == 0) {
            break;
        }

        if ((u8)func_080CFE34(&gPooActor.pos) != 0) {
            break;
        }
        w->angle = w->unk_FB + 128;
        w->unk_3A = w->angle;
        w->unk_3B = w->angle;
        func_080C84E0(w, 21);
        w->unk_F6 = 1;
        break;
    case 20:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 8);
        func_080C8AB8(w);
        w->pos.z -= 0xE00;
        w->unk_3A = w->angle;
        w->unk_3B = w->angle;

        if (w->unk_24 == 0) {
            w->pos.x -= 0x900;
        } else {
            w->pos.x += 0x900;
        }
        break;
    case 8:
        w->unk_E8 = 1;

        if (func_080CBA4C() == 0) {
            break;
        }

        if (func_080C8BD4() != 0) {
            break;
        }
        func_080C84E0(w, 7);
        break;
    case 11:
        if (w->unk_DA <= 179) {
            a2 = w->unk_3A;
            w->unk_39 = GetAngle(w->pos.x, w->pos.y, 0x8DE00, 0x45C00);
            ApproachAngle(&a2, w->unk_39, 4);
            w->unk_3A = a2;
            w->unk_DA++;
        } else {
            w->angle += 128;
            w->unk_3A = w->angle;
            w->unk_3B = w->angle;
            func_080C84E0(w, 4);
        }
        break;
    case 4:
        if (w->unk_DA > 119) {
            func_080C84E0(w, 0);
            break;
        }
        w->unk_DA++;
        func_080C8B60((PooMover*)w, 76, 0);
        break;
    case 7:
        if (w->unk_E8 != 0) {
            w->unk_40 = gPooActor.pos.x;
            w->unk_44 = gPooActor.pos.y;
            func_080C8B60((PooMover*)w, 76, 1);
            break;
        }
        w->unk_40 = gPooActor.pos.x;
        w->unk_44 = gPooActor.pos.y;
        w->angle = GetAngle(w->pos.x, w->pos.y, w->unk_40, w->unk_44);
        w->unk_48 = -0x130;
        w->unk_3C = 237;
        func_080C84E0(w, 19);
        break;
    case 19:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0 && w->unk_E8 != 0 && w->pos.z < -0x100) {
            func_080C84E0(w, 8);
            func_080C8AE0(w);
            break;
        }

        if (AnimGetFrame((AnimState*)w->unk_0C) == 2 && w->unk_16 == 0) {
            m4aSongNumStart(960);
        }

        if ((AnimGetFrame((AnimState*)w->unk_0C) > 1 && AnimGetFrame((AnimState*)w->unk_0C) <= 4) ||
            (AnimGetFrame((AnimState*)w->unk_0C) > 4 && w->unk_E8 == 0 && w->pos.z < w->unk_EC)) {
            w->pos.x += gSineTable[w->angle] * w->unk_3C >> 8;
            w->pos.y += -gSineTable[w->angle + 0x40] * w->unk_3C >> 8;
        }

        if (AnimGetFrame((AnimState*)w->unk_0C) <= 1) {
            break;
        }
    case 1:
        w->pos.z += w->unk_48;
        w->unk_48 += 17;

        if (w->pos.z >= w->unk_EC) {
            w->pos.z = w->unk_EC;
        }

        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 0);
        }
        break;
    case 23:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 24);
        break;
    case 24:
        if (w->unk_DA <= 119) {
            w->unk_DA++;

            if (func_080CBA4C() == 0) {
                break;
            }

            if (func_080C8BD4() != 0) {
                break;
            }

            if (gUnk_0203C3E4 != 0) {
                func_080C84E0(w, 28);
            }
        } else {
            func_080C84E0(w, 25);
        }
        break;
    case 25:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 26);
        w->unk_D8 = gUnk_0203C3E0 * 1800 / 1851;
        break;
    case 26:
        if (func_080CBA4C() != 0 && func_080C8BD4() == 0 && gUnk_0203C3E4 != 0) {
            func_080C84E0(w, 27);

            if (IsTaskActive((Task*)w->unk_C8) == 0) {
                break;
            }
            func_08000DE8(&w->tasks, (Task*)w->unk_C8);
            break;
        }

        if (IsTaskActive((Task*)w->unk_C8) == 0) {
            w->unk_C8 = (s32)TaskCreate(&w->tasks, &gTaskDescPooZzz, &w->unk_24);
        }

        if (gUnk_0203C3E4 == 0) {
            w->unk_D8++;

            if (w->unk_D8 > 1800) {
                gUnk_0203C3E4++;
                gUnk_0203C3E0 = 1851;
                w->unk_D8 = 0;
            }

            if (gUnk_0203C3E4 > 3) {
                gUnk_0203C3E4 = 3;
            }
        }
        break;
    case 27:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 28);
        }
        break;
    case 28:
        if (AnimIsFinished((AnimState*)w->unk_0C) != 0) {
            func_080C84E0(w, 0);
        }
        break;
    case 32:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }

        if (gUnk_0203C3E4 == 1) {
            func_080C84E0(w, 33);
        } else if (gUnk_0203C3E4 == 2) {
            func_080C84E0(w, 34);
        } else {
            func_080C84E0(w, 35);
        }
        break;
    case 33:
    case 34:
    case 35:
        if (AnimIsFinished((AnimState*)w->unk_0C) == 0) {
            break;
        }
        func_080C84E0(w, 28);
        w->pos.x -= 0x400;
        w->pos.y += 0x300;
        break;
    }
}

void func_080C98B8(PooWork* w) {
    if (gUnk_02034DAC == 3) {
        if (gUnk_0203C3E4 != 0) {
            gUnk_0203C3E0--;
        }

        if (gUnk_0203C3E0 == 0) {
            if (gUnk_0203C3E4 == 0) {
                func_080C84E0(w, 0x17);
            } else {
                gUnk_0203C3E4--;
                if (gUnk_0203C3E4 == 0) {
                    func_080C84E0(w, 0x17);
                } else {
                    gUnk_0203C3E0 = 0x73B;
                }
            }
        }
    }
}

u8 func_080C9910(void) {
    s32 x;
    s32 y;

    x = (gUnk_0203C3EC->x >> 8) - gUnk_0203C40C;
    y = (gUnk_0203C3EC->y >> 8) + (gUnk_0203C3EC->z >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, gUnk_096FC010.unk_06, 0, gUnk_096FC010.unk_08, gUnk_096FC010.unk_08) != 0) {
        return 1;
    }
    return 0;
}

u8 task_poo_pooh_1(PooWork* w) {
    PooNode* n;

    w->unk_EC = func_080C8B38((PooAim*)w->unk_4C, &w->pos, &w->unk_E8);

    if (func_080C8BD4() != 0) {
        n = 0;
    } else {
        n = func_080CCC98();
    }
    w->unk_FA = 0;
    func_080C8C40(w, n);
    func_080C98B8(w);
    func_080C7FEC(w, gUnk_02034DAC);
    w->gfx = AnimUpdate(w->unk_0C);

    if (gUnk_02034DAC == 3 || gUnk_02034DAC == 7) {
        if (w->unk_16 == 0) {
            switch (AnimGetFrame(w->unk_0C)) {
            case 9:
                m4aSongNumStart(0x39E);
                break;
            case 3:
                m4aSongNumStart(0x39F);
                break;
            }
        }
    }
    ColliderSetPosition(w->unk_4C, w->pos.x, w->pos.y, w->pos.z);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_pooh_2(PooWork* w) {
    s16 x;
    s16 y;
    s32 f;
    u16 p;

    x = (w->pos.x >> 8) - gUnk_0203C40C;
    y = (w->pos.y >> 8) + (w->pos.z >> 8) - gUnk_0203C3F8;
    if (w->unk_24 != 0) {
        f = 0x801;
    } else {
        f = 0x800;
    }

    if (gUnk_02034DAC == 20 && w->unk_A8 == 1) {
        if (AnimGetFrame(w->unk_0C) <= 4) {
            p = -0x1003 - ((gUnk_0203C3E8 - 0x500) >> 8) * 4;
            w->unk_E4 = 0;
        } else {
            p = -0x1005 - ((gUnk_0203C3E8 - 0x500) >> 8) * 4;
            w->unk_E0 = 0;
        }
    } else if (func_080C9DAC() != 0) {
        p = func_080D06C8() - 4;
        w->unk_E0 = p + 1;
        w->unk_E4 = 0;
    } else if ((u8)func_080D0210(gUnk_0203C3EC->x, gUnk_0203C3EC->y) != 0) {
        if (gUnk_02034DAC == 21 && w->unk_A8 == 1 && w->unk_F6 != 0) {
            p = func_080D06BC() - 3;
        } else if ((u8)func_080D0210(gUnk_0203C3EC->x, gUnk_0203C3EC->y) == 83 || (u8)func_080D0210(gUnk_0203C3EC->x, gUnk_0203C3EC->y) == 173) {
            if (gUnk_0203C3EC->y < gPooActor.pos.y) {
                p = func_080D06C8() + 5;
            } else {
                p = func_080D06C8() + 1;
            }
        } else {
            if (gUnk_0203C3EC->y < gPooActor.pos.y) {
                p = func_080D06BC() - 2;
            } else {
                p = func_080D06BC() - 6;
            }
        }
        w->unk_E0 = p + 1;
        w->unk_E4 = 0;
    } else if (w->unk_E8 != 0) {
        p = -0x1008 - (w->unk_94 >> 8) * 4;

        if (w->pos.y >= gPooActor.pos.y) {
            p -= 2;
        } else {
            p += 2;
        }

        if (w->unk_98 <= *(s32*)&w->unk_4C[0x10] || ((s32*)w->unk_9C)[4] == 0x400) {
            if (w->unk_8C != 0) {
                w->unk_E0 = 0;
            } else {
                w->unk_E0 = p + 1;
            }
            w->unk_E4 = 0;
        } else {
            w->unk_E4 = w->unk_8C;
            w->unk_E0 = p + 1;
        }
    } else {
        p = -0x1004 - (w->pos.y >> 8) * 4;
        w->unk_E4 = 0;

        if (w->unk_E4 != w->pos.unk_0C) {
            w->unk_E0 = 0;
        } else {
            w->unk_E0 = 0xFFF0;
        }
    }

    if (w->unk_FA != 0) {
        w->unk_E0 = 0;
    }
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, f, p);
    TaskPoolDraw(&w->tasks);
}

void task_poo_pooh_3(PooWork* w) {
    if (gUnk_02034DAC == 22) {
        gUnk_02034DAC = 0;
        w->pos.z = 0;
        w->pos.y += 0x2000;
    } else if (gUnk_02034DAC == 14) {
        gUnk_02034DAC = 0;
        w->pos.x = 0x7F700;
        w->pos.y = 0x47E00;
        w->pos.z = 0;
    }
    func_080D2C8C(&w->pos, gUnk_02034DAC);
    func_080D2CC4(gUnk_0203C3E4, gUnk_0203C3E0);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_4C);
    TaskPoolDestroy(&w->tasks);
}

u8 func_080C9D48(void) {
    if (gUnk_02034DAC == 22) {
        return 1;
    }
    return 0;
}

u8 func_080C9D5C(void) {
    if (gUnk_02034DAC == 39) {
        return 1;
    }
    return 0;
}

u8 func_080C9D70(void) {
    if (gUnk_02034DAC == 3) {
        return 1;
    }
    return 0;
}

u8 func_080C9D84(void) {
    if (gUnk_02034DAC == 14) {
        return 1;
    }
    return 0;
}

u8 func_080C9D98(void) {
    if (gUnk_02034DAC == 13) {
        return 1;
    }
    return 0;
}

u8 func_080C9DAC(void) {
    PooWork* w;

    if (gUnk_02034DAC == 13) {
        return 1;
    }

    if (gUnk_02034DAC == 2) {
        if (gPooWork->unk_F6 != 0) {
            return 0;
        }
        return 1;
    }

    if (gUnk_02034DAC != 21) {
        return 0;
    }

    w = gPooWork;
    if (w->unk_F6 != 0) {
        if (w->unk_A8 != 1) {
            return 1;
        }

        if (AnimGetFrame(w->unk_0C) > 4) {
            return 0;
        }
        return 1;
    }

    if (w->unk_A8 == 0) {
        return 0;
    }

    if (AnimGetFrame(w->unk_0C) <= 4) {
        return 0;
    }
    return 1;
}

u8 func_080C9E28(void) {
    if (func_080CA67C(gUnk_0203C3EC) == 2) {
        return 1;
    }
    return 0;
}

u16 func_080C9E4C(void) {
    if (gUnk_02034DAC == 0x21) {
        return 0;
    }

    if (gUnk_02034DAC == 0x22) {
        return 1;
    }

    if (gUnk_02034DAC == 0x23) {
        return 2;
    }
    return 3;
}

u8 func_080C9E70(void) {
    if (gUnk_02034DAC == 12) {
        return 1;
    }
    return 0;
}

void func_080C9E84(void* pool) {
    u32 i;

    for (i = 0; i < 12; i++) {
        CreatePooPileTask(pool, gPooStumpDescs[i].unk_08, gPooStumpDescs[i].unk_00, gPooStumpDescs[i].unk_04);
    }
}

u16 func_080C9EAC(void* pool, u16 b) {
    u32 i;

    for (i = 0; i < 80; i++) {
        CreatePooMapobjhitTask(pool, gPooTileDescs[i].unk_08, gPooTileDescs[i].unk_00, gPooTileDescs[i].unk_04, b);
        b++;
    }
    return b;
}

u16 func_080C9EFC(void* pool, u16 b) {
    u32 i;

    for (i = 0; i < 85; i++) {
        gUnk_02034DC8.x = gPooSpawns[i].unk_00;
        gUnk_02034DC8.y = gPooSpawns[i].unk_04;
        gUnk_02034DC8.z = 0;

        if (gPooSpawns[i].desc == &gTaskDescPooTanpopo || gPooSpawns[i].desc == &gTaskDescPooLeaf) {
            gPooSpawnArgs.pos = gUnk_02034DC8;
            gPooSpawnArgs.unk_10 = b;
            TaskCreate(pool, gPooSpawns[i].desc, &gPooSpawnArgs);
            b++;
        } else {
            TaskCreate(pool, gPooSpawns[i].desc, &gUnk_02034DC8);
        }
    }
    return b;
}

void func_080C9FA8(s32 a, s32 b) {
    gUnk_0203C404 = a;
    gUnk_0203C400 = b;
}

void func_080C9FBC(void) {
    s32 y;

    if (gUnk_02034DE0 != 0) {
        return;
    }

    if (gUnk_02034DE1 != 0) {
        func_080C9FA8(gUnk_0203C3EC->x, gUnk_0203C3EC->y + gUnk_0203C3EC->z);
    }
    y = gUnk_0203C3EC->y + gUnk_0203C3EC->z;

    if ((gUnk_0203C404 - gUnk_0203C3EC->x >= 0 ? gUnk_0203C404 - gUnk_0203C3EC->x < 0xF000
                                                    : gUnk_0203C3EC->x - gUnk_0203C404 < 0xF000) &&
        (gUnk_0203C400 - y >= 0 ? gUnk_0203C400 - y < 0xA000 : y - gUnk_0203C400 < 0xA000)) {
        gUnk_0203C3FC = (gUnk_0203C404 + gUnk_0203C3EC->x) / 2;
        gUnk_0203C408 = (gUnk_0203C400 + y) / 2;
    } else {
        gUnk_0203C3FC = gUnk_0203C404;
        gUnk_0203C408 = gUnk_0203C400;
    }
}

void func_080CA09C(void) {
    gUnk_02034DE0 = 1;
}

void func_080CA0A8(void) {
    gUnk_02034DE0 = 0;
}

void func_080CA0B4(void) {
    gUnk_02034DE1 = 1;
}

void func_080CA0C0(void) {
    gUnk_02034DE1 = 0;
}

void task_poo_map_0(PooMapWork* w) {
    PooPos p;
    s32 n;

    func_080CA0A8();
    func_080CA0C0();
    func_080D2CA8(&p, &n);
    gUnk_0203C3EC = &p;
    func_080C9FBC();
    gUnk_02034DE4 = gUnk_0203C408;
    gUnk_0203C40C = (gUnk_0203C3FC >> 8) - 120;
    gUnk_0203C3F8 = (gUnk_0203C408 >> 8) - 80;
    gFieldState->x = gUnk_0203C40C << 8;
    gFieldState->y = gUnk_0203C3F8 << 8;
    w->unk_00 = gUnk_096FC6E0.mapWidth;
    w->unk_01 = gUnk_096FC6E0.mapHeight;
    TaskPoolInit(&w->tasks, 178);
    func_080C9EAC(&w->tasks, func_080C9EFC(&w->tasks, 0));
    func_080C9E84(&w->tasks);
    TaskCreate(&w->tasks, &gTaskDescPooMapanime, 0);
    LoadBgTiles(3, gUnk_096FC6E0.tiles, gUnk_096FC6E0.tilesSize);
    LoadBgTiles(2, gUnk_096FC6E0.tiles2, gUnk_096FC6E0.tilesSize2);
    LoadBgPalette(3, gUnk_096FC6E0.palette, gUnk_096FC6E0.paletteSize);
    SetBgMapBlocks(3, gUnk_09EF4208, w->unk_00, w->unk_01);
    RedrawBgMapAt(3, gUnk_0203C40C, gUnk_0203C3F8);
    func_080CA35C();
    SetBgMapBlocks(1, gUnk_09EF4448, w->unk_00, w->unk_01);
    RedrawBgMapAt(1, gUnk_0203C40C, gUnk_0203C3F8);
    SetBgMapBlocks(2, gUnk_09EF4688, w->unk_00, w->unk_01);
    RedrawBgMapAt(2, gUnk_0203C40C, gUnk_0203C3F8);
    func_0802F1C8();
}

u8 task_poo_map_1(PooMapWork* w) {
    func_080C9FBC();
    func_080CA270(w);
    ScrollBgMapTo(3, gUnk_0203C40C, gUnk_0203C3F8);
    ScrollBgMapTo(1, gUnk_0203C40C, gUnk_0203C3F8);
    ScrollBgMapTo(2, gUnk_0203C40C, gUnk_0203C3F8);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_map_2(PooMapWork* w) {
    TaskPoolDraw(&w->tasks);
}

void task_poo_map_3(PooMapWork* w) {
    TaskPoolDestroy(&w->tasks);
}

void func_080CA270(PooMapWork* w) {
    s32 tx;
    s32 ty;

    func_0802F208();
    tx = gUnk_0203C3FC - 0x7800;
    ty = gUnk_0203C408 - 0x5000;

    if (ty < 0) {
        ty = 0;
    }

    if (gUnk_0203C3FC + 0x7800 > 0xEDF00) {
        tx = 0xDEF00;
    }

    if (ty + 0xA000 > 0x83000) {
        ty = 0x79000;
    }
    tx = (tx - (gUnk_0203C40C << 8)) >> 3;
    ty = (ty - (gUnk_0203C3F8 << 8)) >> 3;

    if (tx > 0x300) {
        tx = 0x300;
    } else if (tx < -0x300) {
        tx = -0x300;
    }

    if (ty > 0x300) {
        ty = 0x300;
    } else if (ty < -0x300) {
        ty = -0x300;
    }

    if (abs(tx) <= 50) {
        tx = 0;
    }

    if (abs(ty) <= 50) {
        ty = 0;
    }
    gUnk_0203C40C += tx >> 8;
    gUnk_0203C3F8 += ty >> 8;
    gUnk_0203C3F8 += func_0802F268() >> 8;
    gFieldState->x = gUnk_0203C40C << 8;
    gFieldState->y = gUnk_0203C3F8 << 8;
}

void func_080CA35C(void) {
    gUnk_0203C3F4 = 0;
}

void func_080CA368(s32 a, u16 b, u16 c) {
}

u16 func_080CA36C(u16 x, u16 y) {
    const u16** t;
    u32 bx;
    u32 by;
    u32 tx;
    u32 ty;

    t = gUnk_09EF4208;
    bx = x >> 8;
    by = y >> 8;
    tx = (x >> 3) & 0x1F;
    ty = (y >> 3) & 0x1F;
    return t[by * 16 + bx][ty * 32 + tx];
}

u8 func_080CA3A0(PooPos* p) {
    u32 v;

    v = func_080CA36C(p->x >> 8, p->y >> 8) & 0x3FF;
    if ((u16)(v - 1) <= 8) {
        return 0;
    }

    if ((u16)(v - 0x20) <= 9) {
        return 0;
    }

    if ((u16)(v - 0x40) <= 9) {
        return 0;
    }

    if ((u16)(v - 0x1E0) > 0x5F) {
        return 1;
    }
    return 0;
}

u8 func_080CA3FC(PooActor* p, s32 x, s32 y, s32* ox, s32* oy) {
    PooPos t;
    s32 s;
    s32 c;
    s32 m;
    s32 v;
    u8 a;

    if (func_080CA3A0(&p->pos) != 0) {
        a = p->angle + 0x40;
        s = gSineTable[a];
        c = -gSineTable[a + 0x40];
        t.x = s * 4 + x;
        t.y = c * 4 + y;
        t.z = p->pos.z;
        t.unk_0C = p->pos.unk_0C;
        m = p->unk_10;

        if (m > 0x200) {
            m = 0x200;
        }

        if (func_080CA3A0(&t) == 0) {
            *ox = s * m >> 8;
            *oy = c * m >> 8;
            return 1;
        } else {
            a = p->angle - 0x40;
            s = gSineTable[a];
            c = -gSineTable[a + 0x40];
            t.x = s * 4 + x;
            t.y = c * 4 + y;

            if (func_080CA3A0(&t) == 0) {
                *ox = s * m >> 8;
                *oy = c * m >> 8;
                return 1;
            } else {
                v = 0;
                *ox = v;
                *oy = v;
                return 1;
            }
        }
    }
    return 0;
}

u8 func_080CA4E8(s16 x, s16 y, s16 h, s16 vy, s16 w, s16 vx, s32* ox, s32* oy) {
    s32 t;
    s32 r;

    r = 0;
    *oy = 0;
    *ox = 0;
    t = x + vx;
    if (t >= 0) {
        t = x - w;
        if (t > 0xF0) {
            t -= 0xF0;
            *ox = t << 8;
            r = 1;
        }
    } else {
        *ox = t << 8;
        r = 1;
    }
    t = y + vy;
    if (t >= 0) {
        t = y - h;
        if (t > 0xA0) {
            t -= 0xA0;
            *oy = t << 8;
            r = 1;
        }
    } else {
        *oy = t << 8;
        r = 1;
    }
    return r;
}

u8 func_080CA560(PooPos* p, s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080CA3FC((PooActor*)p, x, y, &gUnk_02034DD8, &gUnk_02034DDC) != 0) {
        p->x = x + gUnk_02034DD8;
        p->y = y + gUnk_02034DDC;
    }
    sx = (x >> 8) - gUnk_0203C40C;
    sy = (y >> 8) - gUnk_0203C3F8;

    if (func_080CA4E8(sx, sy, 48, 0, 18, 18, &gUnk_02034DD8, &gUnk_02034DDC) == 0) {
        sx = (p->x >> 8) - gUnk_0203C40C;
        sy = (p->y >> 8) - gUnk_0203C3F8;

        if (func_080CA4E8(sx, sy, 48, 0, 18, 18, &gUnk_02034DD8, &gUnk_02034DDC) != 0) {
            p->x -= gUnk_02034DD8;
            p->y -= gUnk_02034DDC;
        }
    } else {
        p->x = x;
        p->y = y;
    }
    return 1;
}

u8 func_080CA648(PooPos* p) {
    if ((func_080CA36C(p->x >> 8, p->y >> 8) & 0x3FF) > 0x3BA) {
        return 1;
    }
    return 0;
}

u16 func_080CA67C(PooPos* p) {
    if (func_080CA648(p) != 0) {
        if (p->y <= 0x1FFFF) {
            return 1;
        }
        return 2;
    }
    return 0;
}

void func_080CA6A8(s32 a, s32 b) {
    gUnk_0203C3FC += a;
    gUnk_0203C408 += b;
    if (gUnk_02034DE4 < gUnk_0203C408) {
        gUnk_0203C408 = gUnk_02034DE4;
    }
    gUnk_0203C40C = (gUnk_0203C3FC >> 8) - 120;
    gUnk_0203C3F8 = (gUnk_0203C408 >> 8) - 80;
    gFieldState->x = gUnk_0203C40C << 8;
    gFieldState->y = gUnk_0203C3F8 << 8;
    ScrollBgMapTo(3, gUnk_0203C40C, gUnk_0203C3F8);
    ScrollBgMapTo(1, gUnk_0203C40C, gUnk_0203C3F8);
    ScrollBgMapTo(2, gUnk_0203C40C, gUnk_0203C3F8);
}

void func_080CA724(PooSoraWork* w) {
    if ((GetKeysHeld() & 0x20) != 0 && (GetKeysHeld() & 0x80) != 0) {
        w->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x40) != 0 && (GetKeysHeld() & 0x20) != 0) {
        w->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x40) != 0 && (GetKeysHeld() & 0x10) != 0) {
        w->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x10) != 0 && (GetKeysHeld() & 0x80) != 0) {
        w->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x80) != 0 && GetKeyReleaseTime(0x20) <= 4) {
        w->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x80) != 0 && GetKeyReleaseTime(0x10) <= 4) {
        w->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x40) != 0 && GetKeyReleaseTime(0x20) <= 4) {
        w->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x40) != 0 && GetKeyReleaseTime(0x10) <= 4) {
        w->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x20) != 0 && GetKeyReleaseTime(0x40) <= 4) {
        w->unk_14 = 0xD3;
    } else if ((GetKeysHeld() & 0x20) != 0 && GetKeyReleaseTime(0x80) <= 4) {
        w->unk_14 = 0xAD;
    } else if ((GetKeysHeld() & 0x10) != 0 && GetKeyReleaseTime(0x40) <= 4) {
        w->unk_14 = 0x2D;
    } else if ((GetKeysHeld() & 0x10) != 0 && GetKeyReleaseTime(0x80) <= 4) {
        w->unk_14 = 0x53;
    } else if ((GetKeysHeld() & 0x80) != 0) {
        w->unk_14 = 0x80;
    } else if ((GetKeysHeld() & 0x40) != 0) {
        w->unk_14 = 0;
    } else if ((GetKeysHeld() & 0x20) != 0) {
        w->unk_14 = 0xC0;
    } else if ((GetKeysHeld() & 0x10) != 0) {
        w->unk_14 = 0x40;
    }
}

u8 func_080CA8D4(PooSoraWork* w, PooPos* p) {
    if (w->unk_64 != 0 && ColliderIsTouchingType(w->unk_38, 5) == 0 && ColliderIsTouchingType(w->unk_38, 3) == 0 && ColliderIsTouchingType(w->unk_38, 5) == 0 && ColliderIsTouchingType(w->unk_38, 11) == 0) {
        if (func_080CFF30() != 0) {
            p->x += w->unk_70;
            p->y += w->unk_74;
            func_080CFF58((u32*)&p->x, (u32*)&p->y, 1);
        } else {
            p->x += w->unk_70;
            p->y += w->unk_74;
        }
        return 1;
    }
    return 0;
}

u8 func_080CA960(PooPos* p) {
    u8 a;

    a = GetAngle(p->x, p->y, gUnk_0203C3EC->x, gUnk_0203C3EC->y);

    switch (((a + 16) & 0xFF) >> 5) {
    case 1:
        return 0x2D;
    case 2:
        return 0x40;
    case 3:
        return 0x53;
    case 4:
        return 0x80;
    case 5:
        return 0xAD;
    case 6:
        return 0xC0;
    case 7:
        return 0xD3;
    case 0:
    default:
        return 0;
    }
}

void func_080CA9DC(PooSoraWork* w) {
    u8 old;

    old = w->unk_14;
    func_080CA724(w);

    if (old != w->unk_14) {
        if (abs((s8)GetAngleDiff(old, w->unk_14)) > 100) {
            w->unk_10 = 0;
        } else {
            w->unk_10 >>= 1;
        }
    }
}

s32 func_080CAA14(PooSoraWork* w) {
    PooPos* p;
    s32 v;

    p = &gPooActor.pos;

    if ((w->unk_66 & 1) != 0) {
        if (p->unk_0C < w->unk_78) {
            v = p->unk_0C;
        } else {
            v = w->unk_78;
        }
        w->unk_AC = 1;
    } else {
        w->unk_AC = 0;
        v = p->unk_0C;
    }
    return v;
}

void func_080CAA50(PooSoraWork* w, s32 b, u16 c) {
    const PooAnimDesc* e;
    s32 d;

    switch (gPooActor.angle) {
    case 0x2D:
        d = 4;
        w->flags |= 2;
        break;
    case 0x40:
        d = 3;
        w->flags |= 2;
        break;
    case 0x53:
        d = 2;
        w->flags |= 2;
        break;
    case 0x80:
        d = 1;
        w->flags &= ~2;
        break;
    case 0xAD:
        d = 2;
        w->flags &= ~2;
        break;
    case 0xC0:
        d = 3;
        w->flags &= ~2;
        break;
    case 0xD3:
        d = 4;
        w->flags &= ~2;
        break;
    case 0x00:
    default:
        d = 0;
        w->flags &= ~2;
        break;
    }

    if (w->unk_A4 == b) {
        c |= 4;
    }
    w->unk_A4 = b;
    e = &gUnk_096FCF54[b][d];
    AnimChangeWithTables(w->unk_08, (u8)e->unk_0C, c, e->unk_04, e->unk_00);
    SetObjTileSource(w->tiles, e->unk_08);
}

void func_080CAB24(PooActor* p) {
    s32 x;
    s32 y;

    switch (p->angle) {
    case 0x2D:
    case 0xD3:
        x = p->pos.x + gSineTable[p->angle] * 12;
        y = p->pos.y + -gSineTable[p->angle + 0x40] * 12;
        break;
    case 0x40:
    case 0xC0:
        x = p->pos.x + gSineTable[p->angle] * 27;
        y = p->pos.y + -gSineTable[p->angle + 0x40] * 27;
        break;
    case 0x00:
    case 0x53:
    case 0x80:
    case 0xAD:
    default:
        x = p->pos.x + gSineTable[p->angle] * 20;
        y = p->pos.y + -gSineTable[p->angle + 0x40] * 20;
        break;
    }
    func_080C7684(x, y, p->pos.z - 0x800);
}

void task_poo_sora_0(PooSoraWork* w) {
    PooActor* a = &gPooActor;

    gUnk_0203C414 = w->unk_38;
    gUnk_0203C410 = &w->node;
    gPooSoraWork = w;
    w->tiles = AllocObjTiles(0xA00, 0);
    w->palette = LoadObjPalette(gUnk_08F683A4, 32);
    a->unk_1A = 16;
    w->unk_AC = 0;
    w->timer = 0;
    w->flags = 0;
    w->unk_A4 = 12;
    a->unk_32 = 0;
    a->unk_30 = 0;
    GetPooStatePos2(&a->pos);
    a->angle = 0xAD;
    a->pos.unk_0C = 0;
    a->unk_10 = 0;
    func_080C9FA8(a->pos.x, a->pos.y + a->pos.z);
    AnimInit((AnimState*)w->unk_08, 0, 0);
    func_080CAA50(w, 0, 1);
    w->gfx = AnimGetGfx((AnimState*)w->unk_08);
    w->animDesc = (const PooAnimDesc*)gUnk_096FD2C4;
    TaskPoolInit(&w->tasks, 2);
    gFieldState = EwramAlloc(0xE8);
    TaskCreate(&w->tasks, &gTaskDescFldShadow, a);
    func_080CCB90(&w->node, 1, a);
    ColliderInit(w->unk_38, 1, 18, 48);
    ColliderSetPosition(w->unk_38, a->pos.x, a->pos.y, a->pos.z);
}

u8 func_080CAD08(PooSoraWork* w, u8* t) {
    PooActor* a = &gPooActor;
    PooPos p;
    s32 z;
    s32 sx;
    s32 sy;
    u16 k;
    u16 v;

    z = func_080CAA14(w);
    sx = a->pos.x;
    sy = a->pos.y;
    func_080CA9DC((PooSoraWork*)a);

    switch (w->unk_94) {
    case 7:
        if (w->timer == 0) {
            func_080CAA50(w, 10, 0);
        }
        a->pos.x += gSineTable[a->angle] * a->unk_10 >> 8;
        a->pos.y += -gSineTable[a->angle + 0x40] * a->unk_10 >> 8;

        if (AnimGetFrame((AnimState*)w->unk_08) > 3) {
            a->pos.z += w->unk_9C;
            w->unk_9C += 66;

            if (a->pos.z > z) {
                a->pos.z = z;
                w->unk_9C = 0;
            }
        } else {
            w->unk_9C = 0;
        }
        a->unk_10 -= 38;

        if (a->unk_10 < 0) {
            a->unk_10 = 0;
        }

        switch (AnimGetFrame((AnimState*)w->unk_08)) {
        case 3:
        case 4:
            func_080CAB24(a);
            break;
        }

        if (AnimIsFinished((AnimState*)w->unk_08) != 0) {
            if (w->unk_9C < 0) {
                w->unk_94 = 3;
            } else {
                w->unk_94 = 4;
            }
        } else {
            w->timer++;
        }
        break;
    case 2:
        if (w->timer == 0) {
            func_080CAA50(w, 3, 0);
            a->unk_10 >>= 1;
        }
        a->pos.x += gSineTable[a->angle] * a->unk_10 >> 8;
        a->pos.y += -gSineTable[a->angle + 0x40] * a->unk_10 >> 8;

        if (w->timer > 3) {
            if (GetRandom() % 2 != 0) {
                m4aSongNumStart(0x71);
            } else {
                m4aSongNumStart(0x72);
            }
            w->unk_94 = 3;
            w->unk_9C = -0x533;
            a->unk_10 <<= 1;
            w->timer = 0;
        } else {
            w->timer++;
        }
        break;
    case 3:
        if ((GetKeysHeld() & 0xF0) != 0) {
            a->unk_10 += 17;

            if (a->unk_10 > 0x200) {
                a->unk_10 = 0x200;
            }
        } else {
            a->unk_10 -= 38;

            if (a->unk_10 < 0) {
                a->unk_10 = 0;
            }
        }

        if (w->unk_9C > -0x200) {
            func_080CAA50(w, 5, 0);
        } else {
            func_080CAA50(w, 4, 0);
        }
        a->pos.x += gSineTable[a->angle] * a->unk_10 >> 8;
        a->pos.y += -gSineTable[a->angle + 0x40] * a->unk_10 >> 8;
        a->pos.z += w->unk_9C;
        w->unk_9C += 66;

        if (w->unk_9C < 0) {
            if ((GetKeysHeld() & 2) == 0) {
                w->unk_9C += 64;
            }
        }

        if ((GetKeysPressed() & 1) != 0) {
            w->timer = 0;
            w->unk_94 = 7;
        } else if (w->unk_9C > 0) {
            w->timer = 0;
            w->unk_94 = 4;
        } else {
            w->timer++;
        }
        break;
    case 4:
        if ((GetKeysHeld() & 0xF0) != 0) {
            a->unk_10 += 17;

            if (a->unk_10 > 0x200) {
                a->unk_10 = 0x200;
            }
        } else {
            a->unk_10 -= 38;

            if (a->unk_10 < 0) {
                a->unk_10 = 0;
            }
        }

        if (w->unk_9C < 0x200) {
            func_080CAA50(w, 5, 0);
        } else {
            func_080CAA50(w, 6, 0);
        }
        a->pos.x += gSineTable[a->angle] * a->unk_10 >> 8;
        a->pos.y += -gSineTable[a->angle + 0x40] * a->unk_10 >> 8;
        a->pos.z += w->unk_9C;
        w->unk_9C += 66;

        if ((GetKeysPressed() & 1) != 0) {
            w->timer = 0;
            w->unk_94 = 7;
        } else if (a->pos.z > z) {
            a->pos.z = z;
            w->unk_9C = 0;

            if (w->unk_94 != 5) {
                w->unk_94 = 5;
                w->timer = 0;
            }
        }
        break;
    case 5:
        if (w->timer == 0) {
            func_080CAA50(w, 7, 0);
            m4aSongNumStart(((const u16*)w->animDesc)[3]);
        }
        a->unk_10 = 0;
        k = GetKeysPressed() & 2;

        if (k != 0) {
            w->timer = 0;
            w->unk_94 = 2;
        } else if (w->timer > 6) {
            w->unk_94 = 0;
            w->timer = 0;
            SetTaskUpdate(t, (u32)task_poo_sora_1);
        } else {
            w->timer++;
        }
        break;
    }

    if (func_080CA8D4(w, &a->pos) != 0) {
        a->unk_10 = a->unk_10 * 230 >> 8;
    }
    func_080CA560(&a->pos, sx, sy);

    if ((u8)func_080CFE34(&a->pos) != 0) {
        if (a->pos.z > -0xA00) {
            p.x = sx;
            p.y = sy;

            if ((u8)func_080CFE34(&p) == 0) {
                a->pos.x = sx;
                a->pos.y = sy;
                a->unk_10 = 0;
            } else if (w->unk_9C >= 0) {
                a->unk_10 = 0;
                v = (-a->pos.z >> 8) + 1;
                func_080CFF58((u32*)&a->pos, (u32*)&a->pos.y, v);
            }
        }
    }
    ColliderSetPosition(w->unk_38, a->pos.x, a->pos.y, a->pos.z);
    func_080C9FA8(a->pos.x, a->pos.y + a->pos.z);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_080CB1BC(PooSoraWork* w, u8* t) {
    PooActor* a = &gPooActor;
    s32 sx;
    s32 sy;

    sx = a->pos.x;
    sy = a->pos.y;

    if (w->unk_94 == 6) {
        if (w->timer == 0) {
            func_080CAA50(w, 9, 0);
            a->unk_10 = 0;
            m4aSongNumStart(0x73);
        }

        if (((AnimState*)w->unk_08)->timer == 0) {
            switch (a->angle) {
            case 0xAD:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x -= 0x500;
                    a->pos.y += 0x400;
                    break;
                case 1:
                    a->pos.x -= 0x200;
                    break;
                case 2:
                    a->pos.x -= 0x300;
                    break;
                }
                break;
            case 0x53:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x += 0x500;
                    a->pos.y += 0x400;
                    break;
                case 1:
                    a->pos.x += 0x200;
                    break;
                case 2:
                    a->pos.x += 0x300;
                    break;
                }
                break;
            case 0xD3:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x -= 0x500;
                    a->pos.y -= 0x200;
                    break;
                case 1:
                    a->pos.x -= 0x500;
                    break;
                case 2:
                    a->pos.x -= 0x200;
                    break;
                }
                break;
            case 0x2D:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x += 0x500;
                    a->pos.y -= 0x200;
                    break;
                case 1:
                    a->pos.x += 0x500;
                    break;
                case 2:
                    a->pos.x += 0x200;
                    break;
                }
                break;
            case 0x80:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x -= 0x300;
                    a->pos.y += 0x400;
                    break;
                case 1:
                    a->pos.x += 0x100;
                    a->pos.y += 0x100;
                    break;
                case 2:
                    a->pos.y += 0x200;
                    break;
                case 3:
                    a->pos.y += 0x100;
                    break;
                }
                break;
            case 0x40:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x += 0x700;
                    a->pos.y += 0x100;
                    break;
                case 1:
                    a->pos.x += 0x300;
                    break;
                case 2:
                    a->pos.x += 0x200;
                    break;
                }
                break;
            case 0xC0:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.x -= 0x700;
                    a->pos.y += 0x100;
                    break;
                case 1:
                    a->pos.x -= 0x300;
                    break;
                case 2:
                    a->pos.x -= 0x200;
                    break;
                }
                break;
            case 0:
                switch (AnimGetFrame((AnimState*)w->unk_08)) {
                case 0:
                    a->pos.y -= 0x400;
                    break;
                case 1:
                    a->pos.y -= 0x400;
                    break;
                case 2:
                    a->pos.x -= 0x100;
                    a->pos.y += 0x100;
                    break;
                case 3:
                    a->pos.y -= 0x100;
                    break;
                }
                break;
            }
        }

        if (w->timer > 14) {
            func_080CAB24(a);
        }

        if (AnimIsFinished((AnimState*)w->unk_08) != 0) {
            switch (a->angle) {
            case 0xAD:
                a->pos.x -= 0x200;
                a->pos.y += 0x200;
                break;
            case 0x53:
                a->pos.x += 0x200;
                a->pos.y += 0x200;
                break;
            case 0xD3:
            case 0x2D:
                a->pos.y -= 0x400;
                break;
            case 0x80:
                a->pos.y += 0x200;
                break;
            case 0:
                a->pos.y -= 0x200;
                break;
            }
            func_080CAA50(w, 0, 0);
            w->unk_94 = 0;
            SetTaskUpdate(t, (u32)task_poo_sora_1);
        } else {
            w->timer++;
        }
    }
    func_080CA8D4(w, &a->pos);
    func_080CA560(&a->pos, sx, sy);

    if ((u8)func_080CFE34(&a->pos) != 0) {
        a->pos.x = sx;
        a->pos.y = sy;
        a->unk_10 = 0;
    }
    ColliderSetPosition(w->unk_38, a->pos.x, a->pos.y, a->pos.z);
    func_080C9FA8(a->pos.x, a->pos.y + a->pos.z);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_080CB5A8(PooSoraWork* w, u8* t) {
    PooActor* a = &gPooActor;
    s32 x;
    s32 y;
    u16 keys;

    x = a->pos.x;
    y = a->pos.y;

    if (w->unk_94 == 8) {
        if (w->timer == 0) {
            func_080CAA50(w, 8, 1);
            a->unk_10 = 0;
        }

        if (w->timer > 29) {
            keys = GetKeysHeld() & 0x100;
            if (keys != 0) {
                w->timer = 0;
            } else {
                w->timer = 0;
                w->unk_94 = 0;
                SetTaskUpdate(t, (u32)task_poo_sora_1);
            }
        } else {
            w->timer++;
        }
    }
    func_080CA8D4(w, &a->pos);
    func_080CA560(&a->pos, x, y);

    if ((u8)func_080CFE34(&a->pos) != 0) {
        a->pos.x = x;
        a->pos.y = y;
        a->unk_10 = 0;
    }
    ColliderSetPosition(w->unk_38, a->pos.x, a->pos.y, a->pos.z);
    func_080C9FA8(a->pos.x, a->pos.y + a->pos.z);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 task_poo_sora_1(PooSoraWork* w, u8* t) {
    PooActor* a = &gPooActor;
    s32 z;
    s32 sx;
    s32 sy;
    u16 v;

    z = func_080CAA14(w);
    sx = a->pos.x;
    sy = a->pos.y;

    if (w->unk_94 <= 1) {
        func_080CA9DC((PooSoraWork*)a);

        if ((GetKeysHeld() & 0xF0) != 0) {
            a->unk_10 += 128;
            func_080CAA50(w, 2, 1);

            if (a->unk_10 > 0x266) {
                a->unk_10 = 0x266;
            }

            if (((AnimState*)w->unk_08)->timer == 0) {
                switch (((AnimState*)w->unk_08)->frame) {
                case 3:
                    m4aSongNumStart(((const u16*)w->animDesc)[0]);
                    break;
                case 7:
                    m4aSongNumStart(((const u16*)w->animDesc)[1]);
                    break;
                }
            }
        } else {
            func_080CAA50(w, 0, 1);
            a->unk_10 -= 128;

            if (a->unk_10 < 0) {
                a->unk_10 = 0;
            }
        }
        a->pos.x += gSineTable[a->angle] * a->unk_10 >> 8;
        a->pos.y += -gSineTable[a->angle + 0x40] * a->unk_10 >> 8;

        if ((GetKeysPressed() & 2) != 0) {
            w->timer = 0;
            w->unk_94 = 2;
            SetTaskUpdate(t, (u32)func_080CAD08);
            m4aSongNumStart(((const u16*)w->animDesc)[2]);
        } else if ((GetKeysPressed() & 1) != 0) {
            func_080CAB24(a);
            gUnk_0203C3D8 = 0;
            v = func_080D2EB8();

#ifdef VERSION_EU
            if (v != 179) {
#else
            if (v != 180) {
#endif
                func_080C7BCC(v);
            } else {
                w->timer = 0;
                w->unk_94 = 6;
                SetTaskUpdate(t, (u32)func_080CB1BC);
            }
        } else if ((GetKeysPressed() & 0x100) != 0) {
            w->timer = 0;
            w->unk_94 = 8;
            SetTaskUpdate(t, (u32)func_080CB5A8);
            a->angle = func_080CA960(&a->pos);
        }
    } else if (AnimIsFinished((AnimState*)w->unk_08) != 0) {
        w->unk_94 = 0;
    }

    if (func_080CBAB0(&a->pos) != 0) {
        a->unk_10 = 0;
    }

    if (func_080CA8D4(w, &a->pos) != 0) {
        a->unk_10 = a->unk_10 * 230 >> 8;
    }
    func_080CA560(&a->pos, sx, sy);

    if ((u8)func_080CFE34(&a->pos) != 0) {
        a->pos.x = sx;
        a->pos.y = sy;
        a->unk_10 = 0;
    }

    if (z != a->pos.z) {
        a->unk_10 >>= 2;
        w->unk_9C = 0;
        w->timer = 0;
        w->unk_94 = 4;
        SetTaskUpdate(t, (u32)func_080CAD08);
    }
    ColliderSetPosition(w->unk_38, a->pos.x, a->pos.y, a->pos.z);
    func_080C9FA8(a->pos.x, a->pos.y + a->pos.z);
    w->gfx = AnimUpdate((AnimState*)w->unk_08);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_sora_2(PooSoraWork* w) {
    PooActor* a = &gPooActor;
    s32 prio;
    s32 c;
    s32 ac;
    s16 x;
    s16 y;

    c = w->flags & 2;
    prio = 0x800;

    if (c != 0) {
        prio = 0x801;
    }

    ac = w->unk_AC;
    if (ac != 0) {
        gUnk_02034DEC = -0x1008 - (w->unk_80 >> 8) * 4;

        if (w->unk_84 <= w->unk_48 || w->unk_88[4] == 0x400) {
            if (w->unk_78 != 0) {
                a->unk_3A = 0;
            } else {
                a->unk_3A = gUnk_02034DEC + 1;
            }
            a->unk_3C = 0;
        } else {
            a->unk_3C = w->unk_78;
            a->unk_3A = gUnk_02034DEC + 1;
        }
    } else {
        gUnk_02034DEC = -0x1008 - (a->pos.y >> 8) * 4;
        a->unk_3C = 0;

        if (ac != a->pos.unk_0C) {
            a->unk_3A = 0;
        } else {
            a->unk_3A = gUnk_02034DEC + 1;
        }
    }
    x = (a->pos.x >> 8) - gUnk_0203C40C;
    y = (a->pos.y >> 8) + (a->pos.z >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, prio, gUnk_02034DEC - 1);
    TaskPoolDraw(&w->tasks);
}

void task_poo_sora_3(PooSoraWork* w) {
    SetPooStatePos2(&gPooActor.pos);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->unk_38);
    TaskPoolDestroy(&w->tasks);
    EwramFree(gFieldState);
    func_080CCBD4(&w->node);
}

u8 func_080CBA4C(void) {
    if (gPooSoraWork->unk_94 == 8 && gPooSoraWork->timer == 0) {
        return 1;
    }
    return 0;
}

u8 func_080CBA74(void) {
    if (gPooSoraWork->unk_94 == 8) {
        return 1;
    }
    return 0;
}

u8 func_080CBA8C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (func_080D2D50(i) == 0) {
            return 0;
        }
    }
    return 1;
}

u16 func_080CBAB0(PooPos* p) {
    u16 r;

    r = func_080CA67C(p);
    func_080D2D80(3);

    if (r == 1) {
        func_080C7BCC(0xFFFE);
    } else if (r == 2) {
        func_0800FDD0(13);

        if (func_080C9910() == 0) {
            func_080D2D6C(3);

            if (func_080CBA8C() != 0) {
                if (func_080D2D94(1) != 0) {
#ifdef VERSION_EU
                    func_080C7B84(0x91);
#else
                    func_080C7B84(0x93);
#endif
                } else if (func_080D2D94(0) == 0) {
                    func_080D2D6C(0);
                    func_080D2D6C(1);
                    func_0800FDD0(77);
#ifdef VERSION_EU
                    func_080C7B84(0x8D);
#else
                    func_080C7B84(0x8F);
#endif
                } else {
                    func_080D2D6C(1);
                    func_0800FDD0(77);
#ifdef VERSION_EU
                    func_080C7B84(0x8F);
#else
                    func_080C7B84(0x91);
#endif
                }
            } else if (func_080D2D94(0) == 0) {
                func_080D2D6C(0);
                func_0800FDD0(77);
#ifdef VERSION_EU
                func_080C7B84(0x8E);
#else
                func_080C7B84(0x90);
#endif
            } else {
#ifdef VERSION_EU
                func_080C7B84(0x90);
#else
                func_080C7B84(0x92);
#endif
            }
        } else {
            func_080C7BCC(0xFFFD);
        }
    }
    return r;
}

u16 func_080CBB7C(void) {
    return gUnk_02034DEC - 1;
}

void task_poo_trap_0(PooTrapWork* w, PooPos* p) {
    w->x = p->x;
    w->y = p->y;
    w->z = 0;
    w->tiles = LoadObjTiles(gUnk_0972BD8C, 0x100);
    w->palette = LoadObjPalette(gUnk_09849AB8, 0x20);
    w->gfx = gUnk_0972BD78;
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    w->unk_8C = 0;
}

u8 task_poo_trap_1(PooTrapWork* w) {
    if (w->unk_8C != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3DC = w->x;
            gUnk_0203C3E8 = w->y;
            gUnk_0203C3F0 = 1;
        }
    }
    return 1;
}

void task_poo_trap_2(PooTrapWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (x < -16 || x > 256 || y < -16 || y > 176) {
        if (w->unk_8C != 0) {
            ColliderUnregister(w->collider);
            w->unk_8C = 0;
        }
    } else {
        if (w->unk_8C == 0) {
            ColliderInit(w->collider, 10, 8, 16);
            w->unk_8C = 1;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, 0xFFEF);
    }
}

void task_poo_trap_3(PooTrapWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);

    if (w->unk_8C != 0) {
        ColliderUnregister(w->collider);
    }
}

void task_poo_pitAndButterfly_0(PooTrapWork* w, PooPos* p) {
    task_poo_trap_0(w, p);
    TaskPoolInit(&w->tasks, 1);
    TaskCreate(&w->tasks, &gTaskDescPooButterfly, &w->x);
    func_080CCB90(&w->node, 0xE10, &w->x);
}

u8 task_poo_pitAndButterfly_1(PooTrapWork* w) {
    task_poo_trap_1(w);

    if (w->unk_8C != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            func_080CCB84(&w->node.unk_00, 0);
        }
    }
    return 1;
}

void task_poo_pitAndButterfly_2(PooTrapWork* w) {
    task_poo_trap_2(w);

    if (w->unk_8C != 0) {
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_pitAndButterfly_3(PooTrapWork* w) {
    task_poo_trap_3(w);
    TaskPoolDestroy(&w->tasks);
    func_080CCBD4(&w->node);
}

void task_poo_balloon_0(PooBalloonObjWork* w, PooPos* p) {
    w->pos = p;

    if (p->x == 0x3FD00 && p->y == 0x21B00) {
        w->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF5E38, 3), gUnk_0974B4D8);
        w->palette = LoadObjPalette(gUnk_09849C98, 0x20);
        AnimInit(w->anim, gUnk_09EF5E44, gUnk_09EF5E38);
        AnimStart(w->anim, 0, 1);
    } else {
        w->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF5AD0, 4), gUnk_09732FB6);
        w->palette = LoadObjPalette(gUnk_09849B78, 0x20);
        AnimInit(w->anim, gUnk_09EF5AE0, gUnk_09EF5AD0);
        AnimStart(w->anim, 0, 1);
    }
    w->gfx = AnimGetGfx(w->anim);
}

u8 task_poo_balloon_1(void* w) {
    return 1;
}

void task_poo_balloon_2(PooBalloonObjWork* w) {
    s16 x;
    s16 y;

    x = (w->pos->x >> 8) - gUnk_0203C40C;
    y = (w->pos->y >> 8) + (w->pos->z >> 8) - gUnk_0203C3F8;
    if (x >= -16 && x <= 256 && y >= -16 && y <= 176) {
        w->gfx = AnimUpdate(w->anim);
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->pos->y >> 8) * 4);
    }
}

void task_poo_balloon_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_shadow_0(TaskPool* w, void* arg) {
    PooBalloonArgs args;

    args.unk_00 = arg;
    args.unk_08 = 0xA6;
    TaskPoolInit(w, 1);
    TaskCreate(w, &gTaskDescPooShadowscale, &args);
}

u8 task_poo_shadow_1(TaskPool* w) {
    TaskPoolUpdate(w);
    return 1;
}

void task_poo_shadow_2(TaskPool* w) {
    TaskPoolDraw(w);
}

void task_poo_shadow_3(TaskPool* w) {
    TaskPoolDestroy(w);
}

void task_poo_shadowdodai_0(PooShadowWork* w, PooShadowArgs* a) {
    w->pos = a->pos;
    w->shadowInfo = a->shadowInfo;
    w->x = w->pos->x;
    w->y = w->pos->y;
    w->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->anim, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimUpdate(w->anim);
}

u8 task_poo_shadowdodai_1(PooShadowWork* w) {
    w->x = w->pos->x;
    w->y = w->pos->y;
    return 1;
}

void task_poo_shadowdodai_2(PooShadowWork* w) {
    s32 s;
    s32 aff;
    s32 h;
    s16 x;
    s16 y;

    if (w->shadowInfo->unk_00 != 0) {
        h = w->shadowInfo->unk_04;
        if (w->pos->z >= h) {
            s = 0xA6;
        } else {
            s = 0xA6 - (h - w->pos->z) / 128;
            if (s <= 0x18) {
                s = 0x19;
            }
        }
        aff = AllocObjAffine(0, s, s, 0);
        x = (w->x >> 8) - gUnk_0203C40C;
        y = (w->y >> 8) + (h >> 8) - gUnk_0203C3F8;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, aff, 0x800, w->shadowInfo->unk_00);
    }
}

void task_poo_shadowdodai_3(PooShadowWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_shadowscale_0(PooScaleWork* w, PooShadowArgs* a) {
    w->pos = a->pos;
    w->x = w->pos->x;
    w->y = w->pos->y;
    w->unk_2C = a->unk_08;
    w->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->anim, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimUpdate(w->anim);
}

u8 task_poo_shadowscale_1(PooScaleWork* w) {
    w->x = w->pos->x;
    w->y = w->pos->y;
    return 1;
}

void task_poo_shadowscale_2(PooScaleWork* w) {
    s32 s;
    s32 affine;
    u16 x;
    u16 y;

    if (w->pos->z >= 0) {
        s = w->unk_2C;
    } else {
        s = w->unk_2C + w->pos->z / 128;
        if (s <= 0x18) {
            s = 0x19;
        }
    }
    affine = AllocObjAffine(0, s, s, 0);
    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, affine, 0x800, 0xFFF0);
}

void task_poo_shadowscale_3(PooScaleWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void CreatePooShadowscaleTask(void* pool, void* a, s32 b) {
    PooBalloonArgs args;

    args.unk_00 = a;
    args.unk_08 = b;
    TaskCreate(pool, &gTaskDescPooShadowscale, &args);
}

void task_poo_freeballoon_0(PooFreeBalloonWork* w, PooPos* p) {
    w->pos2 = *p;
    w->pos4 = *p;
    w->pos3 = *p;
    w->pos5 = *p;
    w->pos = p;
    w->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF5AA0, 4), gUnk_09732272);
    w->palette = LoadObjPalette(gUnk_09849B38, 0x20);
    AnimInit(w->anim, gUnk_09EF5AB4, gUnk_09EF5AA0);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    w->tiles2 = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF5AB8, 4), gUnk_0973291E);
    w->palette2 = LoadObjPalette(gUnk_09849B58, 0x20);
    AnimInit(w->anim2, gUnk_09EF5ACC, gUnk_09EF5AB8);
    AnimStart(w->anim2, 0, 1);
    w->gfx2 = AnimGetGfx(w->anim2);
    w->unk_90 = 0;
}

u8 func_080CC284(s16 x, s16 y) {
    if (x < -64 || x > 304) {
        return 0;
    }

    if (y < -64) {
        return 0;
    }

    if (y <= 224) {
        return 1;
    }
    return 0;
}

u8 task_poo_freeballoon_1(PooFreeBalloonWork* w) {
    u16 t;

    w->unk_90++;

    if (w->unk_90 > 5) {
        t = w->unk_90 - 5;
        w->pos4.x = w->pos5.x - t * 256;
        w->pos4.y = w->pos5.y - ((t * t) << 8) / 32;
    } else {
        w->pos4 = *w->pos;
        w->pos5 = *w->pos;
    }
    w->pos2.x = w->pos3.x + w->unk_90 * 256;
    w->pos2.y = w->pos3.y - ((w->unk_90 * w->unk_90) << 8) / 32;
    w->x2 = (w->pos4.x >> 8) - gUnk_0203C40C;
    w->y2 = (w->pos4.y >> 8) + (w->pos4.z >> 8) - gUnk_0203C3F8;
    w->x = (w->pos2.x >> 8) - gUnk_0203C40C;
    w->y = (w->pos2.y >> 8) + (w->pos2.z >> 8) - gUnk_0203C3F8;

    if (func_080CC284(w->x2, w->y2) != 0) {
        w->gfx2 = AnimUpdate(w->anim2);
    } else {
        w->gfx2 = 0;
    }

    if (func_080CC284(w->x, w->y) != 0) {
        w->gfx = AnimUpdate(w->anim);
    } else {
        w->gfx = 0;
    }

    if (w->gfx == 0 && w->gfx2 == 0) {
        return 0;
    }
    return 1;
}

void task_poo_freeballoon_2(PooFreeBalloonWork* w) {
    if (w->gfx2 != 0) {
        DrawSprite(w->x2, w->y2, w->gfx2, w->tiles2, w->palette2, 0, 0x800, -0x1004 - (w->pos4.y >> 8) * 4);
    }

    if (w->gfx != 0) {
        DrawSprite(w->x, w->y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->pos2.y >> 8) * 4);
    }
}

void task_poo_freeballoon_3(PooFreeBalloonWork* w) {
    ReleaseObjTiles(w->tiles2);
    ReleaseObjPalette(w->palette2);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

s32 func_080CC488(u16 x) {
    s32 v;
    u32 a;
    u8 c;

    a = x;
    v = 3 - gUnk_0203C3E4;

    if (gUnk_0203C3E0 <= 0x1CD) {
        c = (a / 20) & 1;
        if (c != 0) {
            if (v <= 2) {
                v++;
            }
        }
    }
    return v;
}

void task_poo_gauge_0(PooGaugeWork* w) {
    w->unk_12 = 0;
    w->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF5B2C, 4), gUnk_097356F4);
    w->palette = LoadObjPalette(gUnk_09849B98, 0x20);
    w->unk_0C = gUnk_09849B98;
    w->gfx = gUnk_09EF5B2C[func_080CC488(w->unk_12)];
    w->unk_10 = 0;
}

u8 task_poo_gauge_1(PooGaugeWork* w) {
    w->unk_12++;
    w->gfx = gUnk_09EF5B2C[func_080CC488(w->unk_12)];

    if (gUnk_0203C3E4 <= 1 && gUnk_0203C3E0 <= 0x1CD) {
        w->unk_10 = 1;
    } else {
        w->unk_10 = 0;
    }

    if (w->unk_10 != 0) {
        if (w->unk_0C != gUnk_09849BB8) {
            LoadObjPaletteBank(w->palette->index, gUnk_09849BB8);
            w->unk_0C = gUnk_09849BB8;
        }
    }

    if (w->unk_10 == 0) {
        if (w->unk_0C != gUnk_09849B98) {
            LoadObjPaletteBank(w->palette->index, gUnk_09849B98);
            w->unk_0C = gUnk_09849B98;
        }
    }
    return 1;
}

void task_poo_gauge_2(PooObjWork3* w) {
    DrawSprite(0xDC, 0x18, w->gfx, w->tiles, w->palette, 0, 0x400, 0);
}

void task_poo_gauge_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_trapballoon_0(PooBalloonWork* w, PooPos* p) {
    w->pos = *p;
    w->pos.z = 0;
    w->pos.unk_0C = 0;
    w->unk_CC = GetMaxSpriteTileBytes(gUnk_09EF5AD0, 4);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF5AE0, gUnk_09EF5AD0);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 3);
    w->task = TaskCreate(&w->tasks, &gTaskDescPooShadow, &w->pos);
    w->unk_C8 = 0;
    w->angle = GetRandom();
    ColliderSetPosition(w->collider, w->pos.x, w->pos.y, w->pos.z);
}

u8 task_poo_trapballoon_1(PooBalloonWork* w) {
    PooPos t;

    if (w->palette == 0) {
        return 1;
    }

    if (IsTaskActive((Task*)w->unk_C8) != 0) {
        return 1;
    }

    if (IsTaskActive(w->task) == 0 && IsTaskActive((Task*)w->unk_C8) == 0) {
        return 0;
    }

    if (ColliderIsTouchingType(w->collider, 9) != 0 && func_080C9D70() != 0) {
        gUnk_0203C3DC = w->pos.x;
        gUnk_0203C3E8 = w->pos.y;
        gUnk_0203C3F0 = 2;
        func_080CCB84(&w->node, 0);
        return 0;
    }

    if (gUnk_0203C3D8 == 0) {
        if (ColliderIsTouchingType(w->collider, 9) == 0) {
            return 1;
        }

        if (func_080C9D70() != 0) {
            return 1;
        }
    }

    if (func_080C76B0(w->collider) == 0) {
        return 1;
    }
    t = w->pos;
    t.z -= 0x1000;
    TaskCreate(&w->tasks, &gTaskDescPooSpark, &t);
    func_080CCB84(&w->node, 0);
    ColliderSetDisabled(w->collider, 1);
    func_08000DE8(&w->tasks, w->task);
    w->pos.x -= 0x800;
    w->pos.y += 0x1000;
    w->unk_C8 = (s32)TaskCreate(&w->tasks, &gTaskDescPooFreeballoon, &w->pos);
    m4aSongNumStart(0x147);
    return 1;
}

void task_poo_trapballoon_2(PooBalloonWork* w) {
    s32 d;
    s16 x;
    s16 y;

    if (IsTaskActive((Task*)w->unk_C8) != 0) {
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    } else {
        w->gfx = AnimUpdate(w->anim);
        w->angle += 2;
        d = gSineTable[w->angle & 0xFF] * 2;
        x = ((w->pos.x - 0x800) >> 8) - gUnk_0203C40C;
        d += 0x1200;
        y = ((w->pos.y + d) >> 8) + (w->pos.z >> 8) - gUnk_0203C3F8;

        if (IsRectOutsideScreen(x, y, 64, 8, 24, 24) != 0) {
            if (w->palette != 0) {
                ReleaseObjTiles(w->tiles);
                ReleaseObjPalette(w->palette);
                w->palette = 0;
                ColliderUnregister(w->collider);
                func_080CCBD4(&w->node);
            }
        } else {
            if (w->palette == 0) {
                w->tiles = AllocObjTiles(w->unk_CC, gUnk_09732FB6);
                w->palette = LoadObjPalette(gUnk_09849B78, 0x20);
                ColliderInit(w->collider, 10, 8, 16);
                func_080CCB90(&w->node, 0x400, &w->pos);
            }
            DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->pos.y >> 8) * 4);
            TaskPoolUpdate(&w->tasks);
            TaskPoolDraw(&w->tasks);
        }
    }
}

void task_poo_trapballoon_3(PooBalloonWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
        func_080CCBD4(&w->node);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_owlballoon_0(PooOwlBalloonWork* w, PooPos* p) {
    w->pos = *p;
    w->pos.z = 0;
    w->pos.unk_0C = 0;
    w->unk_C8 = GetMaxSpriteTileBytes(gUnk_09EF5E38, 3);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF5E44, gUnk_09EF5E38);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 2);
    w->task = TaskCreate(&w->tasks, &gTaskDescPooShadow, &w->pos);
    ColliderSetPosition(w->collider, w->pos.x, w->pos.y, w->pos.z);
    func_080CCB90(&w->node, 0x240, &w->pos);
}

u8 task_poo_owlballoon_1(PooOwlBalloonWork* w) {
    if (w->palette != 0 && ColliderIsTouchingType(w->collider, 9) != 0 && func_080C9D70() != 0) {
        gUnk_0203C3DC = w->pos.x;
        gUnk_0203C3E8 = w->pos.y;
        gUnk_0203C3F0 = 7;
        func_080CCB84(&w->node.unk_00, 0);
        m4aSongNumStart(0x181);
        return 0;
    }
    return 1;
}

void task_poo_owlballoon_2(PooOwlBalloonWork* w) {
    s16 x;
    s16 y;

    w->gfx = AnimUpdate(w->anim);
    x = ((w->pos.x - 0x800) >> 8) - gUnk_0203C40C;
    y = ((w->pos.y + 0x1000) >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 64, 8, 24, 24) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->collider);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_C8, gUnk_0974B4D8);
            w->palette = LoadObjPalette(gUnk_09849C98, 0x20);
            ColliderInit(w->collider, 10, 8, 16);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1003 - (w->pos.y >> 8) * 4);
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_owlballoon_3(PooOwlBalloonWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
    TaskPoolDestroy(&w->tasks);
    func_080CCBD4(&w->node);
}

u16 func_080CCB80(u16* p) {
    return *p;
}

void func_080CCB84(u16* p, u16 v) {
    *p = v;
}

u16 func_080CCB88(u16* p) {
    return p[1];
}

void func_080CCB8C(u16* p, u16 v) {
    p[1] = v;
}

void func_080CCB90(PooNode* n, u16 v, void* p) {
    func_080CCB84(&n->unk_00, v);
    func_080CCB8C(&n->unk_00, v);
    n->unk_08 = p;
    n->unk_04 = 0;
    ListNodeInit(&n->node, &gUnk_02034DF8, n);
    ListPoolAppend(&n->node, &gUnk_02034DF8);
}

void func_080CCBD4(PooNode* p) {
    ListPoolRemove(&p->node, &gUnk_02034DF8);
}

void func_080CCBE8(void) {
    ListPoolInit(&gUnk_02034DF8);
}

s32 func_080CCBF8(PooNode* n) {
    PooPos* q;
    PooPos* p;
    u16 dx;
    u16 dy;
    u16 r;
    s32 d;

    q = gUnk_0203C3EC;
    p = n->unk_08;
    dx = (q->x - p->x) >> 8;
    dy = (q->y - p->y) >> 8;
    r = func_080CCB80(&n->unk_00);

    if ((s16)dx * (s16)dx > 0x3840 && (s16)dy * (s16)dy > 0x1900) {
        return 0;
    }

    d = (s16)dx * (s16)dx + (s16)dy * (s16)dy;
    if (d == 0) {
        return r << 8;
    }

    if (r != 0 && (r << 8) / (d << 8) == 0) {
        return 1;
    }
    return (r << 8) / (((s16)dx * (s16)dx + (s16)dy * (s16)dy) << 8);
}

PooNode* func_080CCC98(void) {
    PooNode* best;
    PooNode* n;

    best = (PooNode*)ListPoolFirst(&gUnk_02034DF8);
    n = best;
    gUnk_02034DF0 = 0;

    while (n != 0) {
        gUnk_02034DF4 = func_080CCBF8(n);
        if (gUnk_02034DF4 > gUnk_02034DF0) {
            gUnk_02034DF0 = gUnk_02034DF4;
            best = n;
        }
        n = (PooNode*)ListPoolNext(&n->node);
    }

    if (gUnk_02034DF0 == 0 && best == (PooNode*)ListPoolFirst(&gUnk_02034DF8)) {
        return 0;
    }
    return best;
}

void task_poo_honey_0(PooHoneyWork* w, PooPos* p) {
    w->pos.x = p->x;
    w->pos.y = p->y;
    w->pos.z = 0;
    w->palette = 0;
    w->unk_20 = GetMaxSpriteTileBytes(gUnk_09EF5AE4, 14);
    AnimInit(w->anim, gUnk_09EF5B1C, gUnk_09EF5AE4);
    AnimStart(w->anim, 3, 1);
    ColliderSetPosition(w->collider, w->pos.x, w->pos.y, w->pos.z);
    w->pos2 = w->pos;
    w->pos2.x += 0xB00;
    w->pos2.y -= 0xA00;
    w->minPos = w->pos2;
    w->minPos.x -= 0x100;
    w->minPos.y -= 0x100;
    w->maxPos = w->pos2;
    w->maxPos.x += 0x100;
    w->maxPos.y += 0x100;
    TaskPoolInit(&w->tasks, 1);
    CreatePooShadowscaleTask(&w->tasks, &w->pos, 0xCC);
    w->state = 0;
    w->timer = 0;
}

u8 task_poo_honey_1(PooHoneyWork* w) {
    switch (w->state) {
    case 0:
        if (w->minPos.x <= gUnk_0203C3EC->x && gUnk_0203C3EC->x <= w->maxPos.x && w->minPos.y <= gUnk_0203C3EC->y && gUnk_0203C3EC->y <= w->maxPos.y) {
            gUnk_0203C3F0 = 3;
            func_080CCB84(&w->node.unk_00, 0);
            w->state++;
        }
        break;
    case 1:
        if (func_080C9E4C() <= 2) {
            AnimStart(w->anim, func_080C9E4C(), 0);
            AnimUpdate(w->anim);
            w->state++;
        }
        break;
    case 2:
        AnimUpdate(w->anim);

        if (AnimIsFinished(w->anim) != 0) {
            return 0;
        }

        switch (AnimGetGfxIndex(w->anim)) {
        case 1:
            w->pos = *gUnk_0203C3EC;
            w->pos.x -= 0xB00;
            w->pos.y += 0xA00;
            w->pos.z = 0;
            w->pos3 = w->pos;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            w->pos.x = w->pos3.x + 0x200;
            w->pos.y = w->pos3.y;
            w->pos.z = w->pos3.z - 0x200;
            break;
        case 7:
            w->pos.x = w->pos3.x - 0x200;
            w->pos.y = w->pos3.y - 0x500;
            w->pos.z = w->pos3.z - 0xB00;
            break;
        case 8:
            gUnk_0203C3E4 = 3;
            gUnk_0203C3E0 = 0x73B;
            w->pos.x = w->pos3.x + 0xA00;
            w->pos.y = w->pos3.y - 0x900;
            w->pos.z = w->pos3.z - 0x1000;
            break;
        case 9:
            w->pos.x = w->pos3.x + 0x200;
            w->pos.y = w->pos3.y;
            w->pos.z = w->pos3.z - 0x300;
            break;
        case 10:
            w->pos.x = w->pos3.x + 0x200;
            w->pos.y = w->pos3.y;
            w->pos.z = w->pos3.z - 0x100;
            break;
        case 11:
        case 12:
        case 13:
            w->pos.x = w->pos3.x;
            w->pos.y = w->pos3.y;
            w->pos.z = w->pos3.z;
            w->timer++;
            break;
        case 0:
        default:
            break;
        }
        break;
    default:
        break;
    }
    return 1;
}

void task_poo_honey_2(PooHoneyWork* w) {
    s16 x;
    s16 y;

    if (w->timer > 29 && (w->timer & 1) != 0) {
        return;
    }

    x = (w->pos.x >> 8) - gUnk_0203C40C;
    y = (w->pos.y >> 8) + (w->pos.z >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 24, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->collider);
            func_080CCBD4(&w->node);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_20, gUnk_097339E8);
            w->palette = LoadObjPalette(gUnk_09849B98, 0x20);
            ColliderInit(w->collider, 10, 8, 16);
            func_080CCB90(&w->node, 0x1FA4, &w->pos2);
        }
        DrawSprite(x, y, AnimGetGfx(w->anim), w->tiles, w->palette, 0, 0x800, -0x1004 - (w->pos.y >> 8) * 4);
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_honey_3(PooHoneyWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
        func_080CCBD4(&w->node);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_mapanime_0(PooMapAnimeWork* w) {
    func_080DDDDC(&w->unk_00[0], &gUnk_096FD3E8);
    func_080DDDDC(&w->unk_00[1], &gUnk_096FD400);
}

u8 task_poo_mapanime_1(PooMapAnimeWork* w) {
    u8 r;
    u32 i;

    r = 0;

    for (i = 0; i < 2; i++) {
        r = func_080DDDEC(&w->unk_00[i], w->unk_00[i].unk_08, r);
    }
    return 1;
}

void task_poo_mapanime_2(void* w) {
}

void task_poo_mapanime_3(void* w) {
}

s32 func_080CD198(void) {
    switch (GetRandom() % 40 / 10) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 4;
    }
    return 6;
}

s32 func_080CD1DC(u32 a) {
    if (a == 0) {
        return 1;
    }

    if (a <= 2) {
        return 3;
    }

    if (a <= 4) {
        return 5;
    }
    return 7;
}

s32 func_080CD1F8(u32 a) {
    if (a == 0) {
        return 32;
    }

    if (a <= 2) {
        return 24;
    }

    if (a <= 4) {
        return 16;
    }
    return 9;
}

void task_poo_pile_0(PooPileWork* w, PooPileArgs* a) {
    w->x = a->x;
    w->y = a->y;
    w->z = 0;
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF5C8C, gUnk_09EF5C6C);

    if (a->unk_10 == 8) {
        w->unk_B0 = func_080CD198();
    } else {
        w->unk_B0 = a->unk_10;
    }
    AnimStart(w->anim, w->unk_B0, 0);
    w->gfx = AnimGetGfx(w->anim);
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    w->unk_CC = 0;
    TaskPoolInit(&w->tasks, 1);
    w->task = 0;
}

u8 task_poo_pile_1(PooPileWork* w) {
    PooPos t;

    if (w->unk_B0 == 7) {
        return 1;
    }

    if (w->unk_CC == 0) {
        return 1;
    }

    if (ColliderIsTouchingType(w->collider, 9) != 0) {
        gUnk_0203C3F0 = 5;
    }

    if (gUnk_0203C3D8 == 0) {
        return 1;
    }

    if (func_080C76B0(w->collider) == 0) {
        return 1;
    }

    if (AnimIsFinished(w->anim) == 0) {
        return 1;
    }
    t = *(PooPos*)&w->x;
    t.z -= (u16)func_080CD1F8(w->unk_B0) * 256;

    if (IsTaskActive((Task*)w->task) != 0) {
        func_08000DE8(&w->tasks, (Task*)w->task);
    }
    w->task = (s32)TaskCreate(&w->tasks, &gTaskDescPooSpark, &t);
    w->unk_B0 = func_080CD1DC(w->unk_B0);
    AnimStart(w->anim, w->unk_B0, 0);
    m4aSongNumStart(0x146);

    if (w->unk_B0 == 7) {
        ColliderUnregister(w->collider);
        w->unk_CC = 0;
        func_080CCBD4(&w->node);
    } else {
        ColliderSetHeight(w->collider, (u16)func_080CD1F8(w->unk_B0));
    }
    return 1;
}

void task_poo_pile_2(PooPileWork* w) {
    u16 z;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (x < -16 || x > 256 || y < -36 || y > 196) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }

        if (w->unk_CC != 0) {
            ColliderUnregister(w->collider);
            func_080CCBD4(&w->node);
            w->unk_CC = 0;
        }
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    } else {
        w->gfx = AnimUpdate(w->anim);

        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_09742CC2, 0x300);
            w->palette = LoadObjPalette(gUnk_09849BF8, 0x20);
        }

        if (w->unk_B0 != 7) {
            z = -0x1004 - (w->y >> 8) * 4;

            if (w->unk_CC == 0) {
                ColliderInit(w->collider, 7, 4, (u16)func_080CD1F8(w->unk_B0));
                func_080CCB90(&w->node, 0x240, &w->x);
                w->unk_CC = 1;
            }
        } else {
            z = 0xFFF1;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, z);
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_pile_3(PooPileWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_CC != 0) {
        ColliderUnregister(w->collider);
        func_080CCBD4(&w->node);
    }
    TaskPoolDestroy(&w->tasks);
}

void CreatePooPileTask(void* pool, u16 b, void* c, void* d) {
    s32 t[6];
    PooStumpArgs args;

    memcpy(t, gUnk_096FD43C, sizeof(t));
    args.unk_00 = c;
    args.unk_04 = d;
    args.unk_10 = t[b];
    TaskCreate(pool, &gTaskDescPooPile, &args);
}

void task_poo_tigerstump_0(PooStumpWork* w, PooPos* p) {
    w->x = p->x;
    w->y = p->y + 0x800;
    w->unk_2C = 0;
    w->palette = 0;
    w->gfx = gUnk_097561D4;
    ColliderSetPosition(w->collider, w->x, w->y, 0);
}

u8 task_poo_tigerstump_1(PooStumpWork* w) {
    if (w->palette != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_tigerstump_2(PooStumpWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = ((w->y - 0x800) >> 8) - gUnk_0203C3F8;
    if (x < -96 || x > 336 || y < -64 || y > 224) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->collider);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_097561E8, 0x400);
            w->palette = LoadObjPalette(gUnk_09849D38, 0x20);
            ColliderInit(w->collider, 7, 15, 24);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - ((w->y - 0x700) >> 8) * 4);
    }
}

void task_poo_tigerstump_3(PooStumpWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
}

void task_poo_poohstump_0(PooStumpWork* w, PooPos* p) {
    w->x = p->x;
    w->y = p->y;
    w->unk_2C = 0;
    w->palette = 0;
    w->gfx = gUnk_09755F34;
    ColliderSetPosition(w->collider, w->x, w->y, 0);
}

u8 task_poo_poohstump_1(PooStumpWork* w) {
    if (w->palette != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3DC = w->x;
            gUnk_0203C3E8 = w->y;
            gUnk_0203C3F0 = 8;
        }
    }
    return 1;
}

void task_poo_poohstump_2(PooStumpWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (x < -80 || x > 320 || y < -24 || y > 184) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->collider);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_09755F54, 0x280);
            w->palette = LoadObjPalette(gUnk_09849D38, 0x20);
            ColliderInit(w->collider, 7, 7, 14);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - ((w->y - 0x500) >> 8) * 4);
    }
}

void task_poo_poohstump_3(PooStumpWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
}

void func_080CD854(PooAnimWork* w, s32 b, u16 c) {
    if (w->unk_26 != b) {
        w->unk_26 = b;
        AnimChangeWithTables(w->unk_0C, gUnk_096FD47C[b].unk_0C, c, gUnk_096FD47C[b].unk_00, gUnk_096FD47C[b].unk_04);
        SetObjTileSource(w->tiles, gUnk_096FD47C[b].unk_08);
    }
}

void task_poo_piglet_0(PooPigletWork* w) {
    u16 m;
    u16 n;
    u8 i;

    w->x = 0x2A500;
    w->y = 0x21100;
    w->z = 0;
    w->state = 0;
    w->timer = 0;
    w->palette = 0;
    m = 0;

    for (i = 0; i < 4; i++) {
        n = GetMaxSpriteTileBytes(gUnk_096FD4BC[i].unk_00, gUnk_096FD4BC[i].unk_04);

        if (m < n) {
            m = n;
        }
    }
    w->tiles = AllocObjTiles(m, 0);
    AnimInit(w->anim, 0, 0);
    w->unk_26 = 4;
    func_080CD854((PooAnimWork*)w, 0, 1);
    w->unk_24 = 0;
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    TaskCreate(&w->tasks, &gTaskDescPooShadow, &w->x);

    if (func_080D2D50(0) != 0) {
        w->unk_B4 = func_080D2E28(w->collider, 0x36);
        func_080D2E70(w->unk_B4, 0);
    }
}

u8 task_poo_piglet_1(PooPigletWork* w) {
    if (w->palette != 0 && w->collider[0x2C] != 0) {
        if (ColliderIsTouchingType(w->collider, 9) == 0) {
            return 1;
        }

        if (func_080D2D50(0) != 0) {
            return 1;
        }
        gUnk_0203C3DC = w->x;
        gUnk_0203C3E8 = w->y;
        gUnk_0203C3F0 = 4;
#ifdef VERSION_EU
        func_080C7B84(134);
#else
        func_080C7B84(136);
#endif
        func_080D2D3C(0);
        func_0800FDD0(78);
    }

    switch (w->state) {
    case 0:
        func_080CD854((PooAnimWork*)w, 0, 1);
        w->unk_24 = 0;

        if (w->timer > 209) {
            w->state = 1;
            w->unk_B0 = 0;
        } else {
            w->timer++;
        }
        break;
    case 1:
        func_080CD854((PooAnimWork*)w, 3, 1);
        w->unk_24 = 1;
        w->unk_B0 += 0x600;

        if (w->unk_B0 > 128) {
            w->unk_B0 = 128;
        }
        w->x += gSineTable[0x20] * w->unk_B0 >> 8;
        w->y += -gSineTable[0x60] * w->unk_B0 >> 8;

        if (w->x > 0x2C8FF) {
            w->state = 2;
            w->timer = 0;
        }
        break;
    case 2:
        func_080CD854((PooAnimWork*)w, 1, 1);
        w->unk_24 = 1;

        if (w->timer > 39) {
            w->state = 3;
            w->timer = 0;
        } else {
            w->timer++;
        }
        break;
    case 3:
        func_080CD854((PooAnimWork*)w, 0, 1);
        w->unk_24 = 1;

        if (w->timer > 29) {
            w->state = 4;
            w->timer = 0;
        } else {
            w->timer++;
        }
        break;
    case 4:
        func_080CD854((PooAnimWork*)w, 1, 1);
        w->unk_24 = 1;

        if (w->timer > 29) {
            w->state = 5;
            w->timer = 0;
        } else {
            w->timer++;
        }
        break;
    case 5:
        func_080CD854((PooAnimWork*)w, 0, 1);
        w->unk_24 = 1;

        if (w->timer <= 59) {
            w->timer++;
        } else {
            w->state = 6;
            w->unk_B0 = 0;
        }
        break;
    case 6:
        func_080CD854((PooAnimWork*)w, 2, 1);
        w->unk_24 = 0;
        w->unk_B0 += 0x600;

        if (w->unk_B0 > 128) {
            w->unk_B0 = 128;
        }
        w->x += gSineTable[0xA0] * w->unk_B0 >> 8;
        w->y += -gSineTable[0xE0] * w->unk_B0 >> 8;

        if (w->x <= 0x2A500) {
            w->x = 0x2A500;
            w->y = 0x21100;
            w->state = 0;
            w->timer = 0;
        }
        break;
    default:
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_piglet_2(PooPigletWork* w) {
    u16 pr;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 24, 8, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ColliderUnregister(w->collider);
            func_080D2E70(w->unk_B4, 0);
            w->palette = 0;
        }
    } else {
        TaskPoolUpdate(&w->tasks);
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849C18, 0x20);
            if (func_080D2D50(0) != 0) {
                ColliderInit(w->collider, 10, 4, 16);
            } else {
                ColliderInit(w->collider, 10, 16, 16);
            }
            func_080D2E70(w->unk_B4, 1);
        }
        ColliderSetPosition(w->collider, w->x, w->y, w->z);
        pr = w->unk_24 != 0 ? 0x801 : 0x800;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, -0x1004 - (w->y >> 8) * 4);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_piglet_3(PooPigletWork* w) {
    ReleaseObjTiles(w->tiles);

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_eeyore_0(PooEeyoreWork* w) {
    w->x = 0x82700;
    w->y = 0x47E00;
    w->z = 0;
    w->unk_30 = 0;
    w->unk_A8 = GetMaxSpriteTileBytes(gUnk_09EF5D68, 0x10);
    w->tiles = 0;
    w->palette = 0;

    if (func_080D2D50(2) != 0) {
        w->unk_A4 = 0;
    } else {
        w->unk_A4 = 4;
    }
    AnimInit(w->anim, gUnk_09EF5DA8, gUnk_09EF5D68);
    AnimStart(w->anim, w->unk_A4, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    TaskCreate(&w->tasks, &gTaskDescPooShadow, &w->x);
    ColliderInit(w->collider, 10, 16, 16);
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    w->unk_AC = 1;

    if (func_080D2D50(2) == 0) {
        w->unk_AE = func_080D2E28(w->collider, 0x38);
    } else {
        w->unk_AE = func_080D2E28(w->collider, 0x39);
    }
    func_080D2E70(w->unk_AE, 1);
    w->unk_AA = 0;
}

u8 task_poo_eeyore_1(PooEeyoreWork* w) {
    if (w->unk_AC != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }

    if (func_080CFA70() != 0 && w->unk_A4 == 4) {
        w->unk_A4 = 5;
        AnimStart(w->anim, 5, 1);
        w->unk_AA = 180;
    }

    if (w->unk_AA != 0) {
        ApproachValue((u32*)&w->x, 0x80B00, w->unk_AA);
        ApproachValue((u32*)&w->y, 0x48C00, w->unk_AA);
        func_080C9FA8(w->x, w->y + w->z);
        w->unk_AA--;
        if (w->unk_AA == 0) {
#ifdef VERSION_EU
            func_080C7B84(0x8A);
#else
            func_080C7B84(0x8C);
#endif
            func_080D2D3C(2);
            func_0800FDD0(0x51);
            w->unk_A4 = 1;
            AnimStart(w->anim, 1, 1);
        }
    }
    return 1;
}

void task_poo_eeyore_2(PooEeyoreWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 24, 10, 24, 24) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ReleaseObjTiles(w->tiles);
        }
        p = &w->unk_AC;
        if (*p != 0) {
            ColliderUnregister(w->collider);
            func_080D2E70(w->unk_AE, 0);
            *p = 0;
        }
    } else {
        p = &w->unk_AC;
        if (*p == 0) {
            ColliderInit(w->collider, 10, 16, 16);
            func_080D2E70(w->unk_AE, 1);
            *p = 1;
        }
        ColliderSetPosition(w->collider, w->x, w->y, w->z);
        w->gfx = AnimUpdate(w->anim);
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849C58, 0x20);
            w->tiles = AllocObjTiles(w->unk_A8, gUnk_097448BA);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->y >> 8) * 4);
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_eeyore_3(PooEeyoreWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_AC != 0) {
        ColliderUnregister(w->collider);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_owl_0(PooOwlWork* w) {
    w->pos.x = 0x41500;
    w->pos.y = 0x20700;
    w->pos.z = -0x3000;
    w->pos.unk_0C = 0;
    w->unk_4C = GetMaxSpriteTileBytes(gUnk_09EF5DC4, 18);
    w->palette = 0;
    w->gfx = gUnk_09746EDC;
    AnimInit(w->unk_0C, gUnk_09EF5E24, gUnk_09EF5DC4);
    w->unk_48 = 0;
    w->unk_49 = 0;
    gUnk_02034E08.x = 0x3FD00;
    gUnk_02034E08.y = 0x21B00;
    TaskPoolInit(&w->tasks, 1);
    TaskCreate(&w->tasks, &gTaskDescPooOwlballoon, &gUnk_02034E08);
}

u8 task_poo_owl_1(PooOwlWork* w) {
    if (func_080C9D5C() != 0) {
        func_080C9FA8(gUnk_0203C3EC->x, gUnk_0203C3EC->y + gUnk_0203C3EC->z);

        if (gUnk_0203C3EC->z <= -0x3800) {
            func_080CA09C();
        }

        if (func_080C9910() != 0) {
            if (w->unk_48 == 0) {
                w->unk_48 = 1;
                AnimStart(w->unk_0C, 1, 0);
                w->unk_4A = 60;
                m4aSongNumStart(0x15F);
            }

            if (AnimGetFrame(w->unk_0C) > 3) {
                if (w->unk_4A != 0) {
                    ApproachValueHalfSteps(&w->pos.z, -0x9000, w->unk_4A);
                    w->unk_4A--;
                    w->pos.x -= 204;
                } else {
                    w->pos.z -= 0x100;
                }
            }
            w->gfx = AnimUpdate(w->unk_0C);
        }
    }

    if (func_080C9D48() != 0) {
        if (w->unk_49 == 0) {
            w->unk_49 = 1;
            AnimStart(w->unk_0C, 4, 1);
        }

        if (AnimGetFrame(w->unk_0C) == 0 && w->unk_16 == 0) {
            m4aSongNumStart(0x158);
        }
        w->pos = *gUnk_0203C3EC;
        w->gfx = AnimUpdate(w->unk_0C);
    }
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_owl_2(PooOwlWork* w) {
    s16 x;
    s16 y;

    TaskPoolDraw(&w->tasks);
    x = (w->pos.x >> 8) - gUnk_0203C40C;
    y = (w->pos.y >> 8) + (w->pos.z >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 24, 8, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_4C, gUnk_097471E2);
            w->palette = LoadObjPalette(gUnk_09849C78, 0x20);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - ((w->pos.y + w->pos.z) >> 8) * 4);
    }
}

void task_poo_owl_3(PooOwlWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
    TaskPoolDestroy(&w->tasks);
}

void func_080CE2C4(PooRabbitWork* w, s32 b, u16 c) {
    if (w->unk_A8 != b) {
        w->unk_A8 = b;
        AnimChangeWithTables(w->anim, gUnk_096FD50C[b].unk_0C, c, gUnk_096FD50C[b].unk_00, gUnk_096FD50C[b].unk_04);
        SetObjTileSource(w->tiles, gUnk_096FD50C[b].unk_08);
    }
}

void task_poo_rabbit_0(PooRabbitWork* w) {
    u16 m;
    u16 n;
    u8 i;

    w->x = 0x1B700;
    w->y = 0x16E00;
    w->z = 0;
    w->unk_34 = 0;
    w->palette = 0;
    m = 0;

    for (i = 0; i < 2; i++) {
        n = GetMaxSpriteTileBytes(gUnk_096FD57C[i].unk_00, gUnk_096FD57C[i].unk_04);

        if (m < n) {
            m = n;
        }
    }
    w->tiles = AllocObjTiles(m, 0);
    AnimInit(w->anim, 0, 0);
    w->unk_A8 = 7;
    func_080CE2C4(w, 1, 0);
    w->unk_24 = 0;
    w->unk_AC = 0;
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    CreatePooShadowscaleTask(&w->tasks, &w->x, 0x100);
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    w->unk_AE = func_080D2E28(w->collider, 0x3B);
    func_080D2E70(w->unk_AE, 0);
}

u8 task_poo_rabbit_1(PooRabbitWork* w) {
    switch (w->unk_A8) {
    case 1:
        if (AnimIsFinished(w->anim) != 0) {
            w->unk_AC++;

            if (w->unk_AC <= 3) {
                AnimReset(w->anim);
            } else {
                func_080CE2C4(w, 4, 1);
                w->unk_24 = 1;
                w->unk_AC = 312;
            }
        }
        break;
    case 4:
        if (w->palette != 0 && w->collider[0x2C] != 0 && ColliderIsTouchingType(w->collider, 9) != 0) {
            func_080CE2C4(w, 6, 0);
            w->unk_B0 = 20;
        } else {
            ApproachValue(&w->x, 0x23000, w->unk_AC);
            ApproachValue(&w->y, 0x12400, w->unk_AC);
            w->unk_AC--;

            if (w->unk_AC == 0) {
                func_080CE2C4(w, 5, 0);
                w->unk_24 = 1;
            }
        }
        break;
    case 5:
        if (AnimIsFinished(w->anim) != 0) {
            func_080CE2C4(w, 2, 1);
            w->unk_24 = 0;
            w->unk_AC = 260;
        }
        break;
    case 2:
        if (w->palette != 0 && w->collider[0x2C] != 0 && ColliderIsTouchingType(w->collider, 9) != 0) {
            w->unk_B0 = 20;
            func_080CE2C4(w, 0, 0);
        } else {
            ApproachValue(&w->x, 0x1B700, w->unk_AC);
            ApproachValue(&w->y, 0x16E00, w->unk_AC);
            w->unk_AC--;

            if (w->unk_AC == 0) {
                func_080CE2C4(w, 1, 0);
                w->unk_24 = 0;
                w->unk_AC = 0;
            }
        }
        break;
    case 6:
        if (w->unk_B0 == 0) {
            if (w->palette != 0 && ColliderIsTouchingType(w->collider, 9) == 0) {
                func_080CE2C4(w, 4, 1);
            }
        } else {
            w->unk_B0--;
        }
        break;
    case 0:
        if (w->unk_B0 != 0) {
            w->unk_B0--;
        } else if (w->palette != 0 && ColliderIsTouchingType(w->collider, 9) == 0) {
            func_080CE2C4(w, 2, 1);
        }
        break;
    default:
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_rabbit_2(PooRabbitWork* w) {
    TaskPool* pool;
    s32 pr;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 48, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ColliderUnregister(w->collider);
            func_080D2E70(w->unk_AE, 0);
            w->palette = 0;
        }
    } else {
        pool = &w->tasks;
        TaskPoolUpdate(pool);
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849CB8, 0x40);
            ColliderInit(w->collider, 10, 4, 48);
            func_080D2E70(w->unk_AE, 1);
        }
        ColliderSetPosition(w->collider, w->x, w->y, w->z);
        pr = w->unk_24 != 0 ? 0x801 : 0x800;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, -0x1004 - (w->y >> 8) * 4);
        TaskPoolDraw(pool);
    }
}

void task_poo_rabbit_3(PooRabbitWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
    TaskPoolDestroy(&w->tasks);
}

void func_080CE710(PooTiggerWork* w, u16 b) {
    s32 a;

    AnimReset(w->anim);

    if (w->unk_C0 == 2) {
        switch (w->unk_B8) {
        case 0xAD:
            a = 2;
            w->unk_24 = 0;
            break;
        case 0x53:
            a = 2;
            w->unk_24 = 1;
            break;
        case 0xD3:
            a = 3;
            w->unk_24 = 0;
            break;
        case 0x00:
        default:
            a = 3;
            w->unk_24 = 1;
            break;
        }
    } else {
        a = 0;
    }

    if (w->unk_26 != a) {
        w->unk_26 = a;
        AnimStart(w->anim, a, b);
    }
}

void func_080CE77C(PooTiggerWork* w, u16 b) {
    u16 r;

    AnimReset(w->anim);

    if (w->unk_C0 == 0) {
        r = 0;
    } else if (w->unk_C0 == 1) {
        r = 1;
    } else if (w->unk_C0 == 2) {
        switch (w->unk_B8) {
        case 0xAD:
            r = 2;
            w->unk_24 = 0;
            break;
        case 0x53:
            r = 2;
            w->unk_24 = 1;
            break;
        case 0xD3:
            r = 3;
            w->unk_24 = 0;
            break;
        case 0x2D:
        default:
            r = 3;
            w->unk_24 = 1;
            break;
        }
    } else {
        r = 0;
    }

    if (w->unk_26 != r) {
        w->unk_26 = r;
        AnimChangeWithTables(w->anim, gUnk_096FD59C[r].unk_0C, b, gUnk_096FD59C[r].unk_00, gUnk_096FD59C[r].unk_04);
        SetObjTileSource(w->tiles, gUnk_096FD59C[r].unk_08);
    }
}

void func_080CE818(PooTiggerWork* w) {
    PooAnimData* d;
    s32 t[8];

    memcpy(t, gUnk_096FD61C, sizeof(t));
    d = ((PooAnimData**)gUnk_096FD59C[w->unk_26].unk_00)[gUnk_096FD59C[w->unk_26].unk_0C];
    w->unk_BC = (&d->unk_08[w->unk_BE])->unk_00;
    w->unk_B0 = t[w->unk_BE] - 0x1800;
    w->unk_BE++;
}

u16 func_080CE880(PooAnimWork* w) {
    PooAnimData* d;
    u16 t;
    s32 i;

    d = ((PooAnimData**)gUnk_096FD59C[w->unk_26].unk_00)[gUnk_096FD59C[w->unk_26].unk_0C];
    t = 0;

    for (i = 0; i < d->unk_04; i++) {
        t += d->unk_08[i].unk_00;
    }
    return t;
}

void func_080CE8B4(PooTiggerWork* w) {
    w->unk_BA = func_080CE880(w);

    if (w->unk_B8 == 0xAD) {
        w->x = gUnk_096FD5FC[0];
        w->y = gUnk_096FD5FC[1];
        w->unk_A8 = gUnk_096FD5FC[2];
        w->unk_AC = gUnk_096FD5FC[3];
    } else if (w->unk_B8 == 0x53) {
        w->x = gUnk_096FD5FC[2];
        w->y = gUnk_096FD5FC[3];
        w->unk_A8 = gUnk_096FD5FC[4];
        w->unk_AC = gUnk_096FD5FC[5];
    } else if (w->unk_B8 == 0x2D) {
        w->x = gUnk_096FD5FC[4];
        w->y = gUnk_096FD5FC[5];
        w->unk_A8 = gUnk_096FD5FC[6];
        w->unk_AC = gUnk_096FD5FC[7];
    } else {
        w->x = gUnk_096FD5FC[6];
        w->y = gUnk_096FD5FC[7];
        w->unk_A8 = gUnk_096FD5FC[0];
        w->unk_AC = gUnk_096FD5FC[1];
    }
    w->z = -0x1800;
    w->unk_BE = 0;
    func_080CE818(w);
}

void func_080CE960(s32 x, s32 y, s32 z, u8 c) {
    s16 sx;
    s16 sy;

    sx = (x >> 8) - gUnk_0203C40C;
    sy = (y >> 8) + (z >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(sx, sy, 120, 8, 24, 24) == 0) {
        if (c != 0) {
            m4aSongNumStart(0x3C1);
        } else {
            m4aSongNumStart(0x3B9);
        }
    }
}

void task_poo_tigger_0(PooTiggerWork* w) {
    PooTiggerArgs args;
    u16 m;
    u16 t;
    u8 i;

    w->unk_C0 = 2;
    w->unk_B8 = 0xAD;
    w->unk_D1 = 1;
    w->palette = 0;
    m = 0;

    for (i = 0; i < 4; i++) {
        t = GetMaxSpriteTileBytes(gUnk_096FD5DC[i].unk_00, gUnk_096FD5DC[i].unk_04);
        if (m < t) {
            m = t;
        }
    }
    w->tiles = AllocObjTiles(m, 0);
    AnimInit(w->anim, 0, 0);
    w->unk_26 = 4;
    func_080CE77C(w, 0);
    func_080CE8B4(w);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    args.unk_00 = &w->x;
    args.unk_04 = &w->unk_C8;
    TaskCreate(&w->tasks, &gTaskDescPooShadowdodai, &args);
    ColliderSetPosition(w->unk_38, w->x, w->y, w->z);
}

u8 task_poo_tiggerroo_1(PooTiggerWork* w) {
    func_080C8B38((PooAim*)w->unk_38, (PooPos*)&w->x, &w->unk_D0);

    if (w->unk_C0 == 2) {
        if (w->unk_BA > 0) {
            ApproachValueHalfSteps(&w->x, w->unk_A8, w->unk_BA);
            ApproachValueHalfSteps(&w->y, w->unk_AC, w->unk_BA);
            w->unk_BA--;
            ApproachValue((u32*)&w->z, w->unk_B0, w->unk_BC);
            w->unk_BC--;

            if (w->unk_BC == 0) {
                func_080CE818(w);
            }
        } else {
            switch (w->unk_B8) {
            case 0xAD:
                w->unk_B8 = 0x53;
                break;
            case 0x53:
                w->unk_B8 = 0x2D;
                break;
            case 0x2D:
                w->unk_B8 = 0xD3;
                break;
            case 0xD3:
                w->unk_B8 = 0xAD;
                break;
            }

            if (w->unk_D1 != 0) {
                func_080CE77C(w, 0);
            } else {
                func_080CE710(w, 0);
            }
            func_080CE8B4(w);
            func_080CE960(w->x, w->y, w->z, w->unk_D1);
        }
    }
    w->gfx = AnimUpdate(w->anim);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_tiggerroo_2(PooTiggerWork* w) {
    u16 z;
    s32 pr;
    s32 d;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) + (w->z >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 56, 8, 24, 24) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->unk_38);

            if (w->unk_D1 == 0) {
                if (w->tiles != 0) {
                    ReleaseObjTiles(w->tiles);
                    w->tiles = 0;
                }
            }
        }
    } else {
        if (w->palette == 0) {
            if (w->unk_D1 != 0) {
                w->palette = LoadObjPalette(gUnk_09849BD8, 0x20);
                ColliderInit(w->unk_38, 4, 8, 8);
            } else {
                w->palette = LoadObjPalette(gUnk_09849CF8, 0x20);
                w->tiles = AllocObjTiles(w->unk_D2, gUnk_09753154);
                ColliderInit(w->unk_38, 4, 8, 8);
            }
        }
        ColliderSetPosition(w->unk_38, w->x, w->y, w->z);
        pr = w->unk_24 != 0 ? 0x801 : 0x800;
        d = w->unk_D0;

        if (d != 0) {
            z = -0x1008 - (w->unk_80 >> 8) * 4;

            if (w->y >= gPooActor.pos.y) {
                z -= 2;
            } else {
                z += 2;
            }

            if (w->unk_84 <= w->unk_48) {
                w->unk_CC = 0;
                w->unk_C8 = 0;
            } else {
                w->unk_CC = w->unk_78;
                w->unk_C8 = z + 1;
            }
        } else {
            z = -0x1004 - (w->y >> 8) * 4;
            w->unk_CC = d;

            if (d != w->unk_34) {
                w->unk_C8 = 0;
            } else {
                w->unk_C8 = z + 1;
            }
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, z);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_tiggerroo_3(PooTiggerWork* w) {
    if (w->tiles != 0) {
        ReleaseObjTiles(w->tiles);
    }

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->unk_38);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_tiggerroo_0(PooTiggerWork* w) {
    PooTiggerArgs args;

    w->unk_C0 = 2;
    w->unk_B8 = 0x2D;
    w->unk_D1 = 0;
    w->palette = 0;
    w->tiles = 0;
    w->unk_D2 = GetMaxSpriteTileBytes(gUnk_09EF5EF8, 18);
    AnimInit(w->anim, gUnk_09EF5FA0, gUnk_09EF5EF8);
    w->unk_26 = 4;
    func_080CE710(w, 0);
    func_080CE8B4(w);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    args.unk_00 = &w->x;
    args.unk_04 = &w->unk_C8;
    TaskCreate(&w->tasks, &gTaskDescPooShadowdodai, &args);
    ColliderSetPosition(w->unk_38, w->x, w->y, w->z);
}

void task_poo_roo_0(PooRooWork* w, PooPos* p) {
    gStockMesDispWork = w;
    w->srcPos = p;
    w->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF5EF8, 8), gUnk_09753154);
    w->palette = LoadObjPalette(gUnk_09849CF8, 0x20);
    AnimInit(w->anim, gUnk_09EF5FA0, gUnk_09EF5EF8);

    if (func_080D2D50(5) != 0) {
        w->pos.x = 0x95F00;
        w->pos.y = 0x4EE00;
        w->pos.z = 0;
        AnimStart(w->anim, 0, 0);
        w->unk_24 = 0;
        w->state = 3;
    } else {
        w->pos = *w->srcPos;
        AnimStart(w->anim, 4, 0);
        w->unk_24 = 0;
        w->state = 0;
    }
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    TaskCreate(&w->tasks, &gTaskDescPooShadow, &w->pos);
    ColliderInit(w->collider, 10, 4, 32);
    ColliderSetPosition(w->collider, w->pos.x, w->pos.y, w->pos.z);

    if (func_080D2D50(5) != 0) {
        w->unk_B8 = func_080D2E28(w->collider, 58);
    }
}

u8 task_poo_roo_1(PooRooWork* w) {
    s32 t;

    switch (w->state) {
    case 0:
        if (AnimIsFinished(w->anim) != 0) {
            AnimStart(w->anim, 5, 0);
            w->state = 1;
            w->pos = *w->srcPos;
            w->pos.x -= 0x600;
            w->pos.z += 0x1F00;
        }
        break;
    case 1:
        w->unk_B0 = w->pos.z;
        w->pos = *w->srcPos;
        w->pos.x -= 0x600;
        t = w->pos.z + 0x1F00;
        w->pos.z = t;

        if (w->unk_B0 - t < 0 && t >= -0x2100) {
            AnimStart(w->anim, 6, 0);
            w->state = 2;
            w->unk_AC = 0;
        }
        break;
    case 2:
        w->pos.z += w->unk_AC;
        w->unk_AC += 7;

        if (w->pos.z >= 0) {
            w->pos.z = 0;
        } else {
            w->pos.x -= 0x40;
            w->pos.y += 0x40;
        }

        if (w->srcPos->z >= 0) {
#ifdef VERSION_EU
            func_080C7B84(0x89);
#else
            func_080C7B84(0x8B);
#endif
            func_080D2D3C(5);
            func_0800FDD0(80);
        }
        break;
    case 3:
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    ColliderSetPosition(w->collider, w->pos.x, w->pos.y, w->pos.z);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_roo_2(PooRooWork* w) {
    s16 x;
    s16 y;
    s32 pr;
    s32 t;

    x = (w->pos.x >> 8) - gUnk_0203C40C;
    t = w->pos.y >> 8;
    y = t + (w->pos.z >> 8) - gUnk_0203C3F8;
    pr = w->unk_24 != 0 ? 0x801 : 0x800;
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, -0x1006 - t * 4);

    if (w->state != 0) {
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_roo_3(PooRooWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
    TaskPoolDestroy(&w->tasks);
}

u8 func_080CF114(void) {
    return AnimIsFrameEnding((u8*)gStockMesDispWork + 0x0C);
}

u8 func_080CF12C(void) {
    return AnimIsFinished((u8*)gStockMesDispWork + 0x0C);
}

void task_poo_roo_footmark_0(PooFootmarkWork* w) {
    w->unk_0C = 0x4A700;
    w->unk_10 = 0x28E00;
    w->unk_14 = 0;
    w->tiles = LoadObjTiles(gUnk_09755A34, 0x500);
    w->palette = 0;

    if (func_080D2D50(5) == 0) {
        w->gfx = gUnk_097559F4;
    } else {
        w->gfx = gUnk_09755A04;
    }
}

u8 task_poo_roo_footmark_1(void* w) {
    return 1;
}

void task_poo_roo_footmark_2(PooFootmarkWork* w) {
    PooNode* n;
    s16 x;
    s16 y;

    x = (w->unk_0C >> 8) - gUnk_0203C40C;
    y = (w->unk_10 >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 0, 48, 0, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            func_080CCBD4(&w->node);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D18, 0x20);
            n = &w->node;
            func_080CCB90(n, 0x240, &w->unk_0C);
            if (func_080D2D50(5) != 0) {
                func_080CCB84(&n->unk_00, 0);
            }
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, 0xFFF1);
    }
}

void task_poo_roo_footmark_3(PooFootmarkWork* w) {
    ReleaseObjTiles(w->tiles);

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        func_080CCBD4(&w->node);
    }
}

void task_poo_leaf_0(PooLeafWork* w, PooLeafArgs* a) {
    w->x = a->unk_00;
    w->y = a->unk_04;
    w->z = 0;
    w->unk_94 = a->unk_10;
    w->unk_92 = GetMaxSpriteTileBytes(gUnk_09EF610C, 5);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF612C, gUnk_09EF610C);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    ColliderSetPosition(w->unk_34, w->x + 0x1C00, w->y + 0x1000, w->z);
    w->unk_90 = 0;
}

u8 task_poo_leaf_1(PooLeafWork* w) {
    if (w->palette != 0 && (w->flags & 2) != 0 && w->unk_90 == 0) {
        w->unk_90 = 1;
        AnimReset(w->anim);
        m4aSongNumStart(0xE0);

        if (func_080D2C1C(w->unk_94) == 0) {
            if (func_080C7BF8(2, 3, w->x + 0x1C00, w->y + 0x2000, w->z) != 0) {
                func_080D2BF8(w->unk_94);
            }
        }
    }
    return 1;
}

void task_poo_leaf_2(PooLeafWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 0, 32, 0, 56) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->unk_34);
            w->unk_90 = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_92, gUnk_0975C3E2);
            w->palette = LoadObjPalette(gUnk_09849DF8, 0x20);
            ColliderInit(w->unk_34, 6, 28, 0);
        }
        p = &w->unk_90;
        if (*p != 0) {
            w->gfx = AnimUpdate(w->anim);

            if (AnimIsFinished(w->anim) == 0) {
                DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, 0xFFF1);
            } else if ((w->flags & 2) == 0) {
                *p = 0;
            }
        }
    }
}

void task_poo_leaf_3(PooLeafWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->unk_34);
    }
}

void task_poo_tanpopo_0(PooTanpopoWork* w, PooLeafArgs* a) {
    w->x = a->unk_00;
    w->y = a->unk_04;
    w->z = 0;
    w->unk_B6 = a->unk_10;
    w->unk_B2 = GetMaxSpriteTileBytes(gUnk_09EF6130, 2);
    w->unk_B4 = GetMaxSpriteTileBytes(gUnk_09EF613C, 6);
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF6138, gUnk_09EF6130);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    AnimInit(w->anim2, gUnk_09EF6154, gUnk_09EF613C);
    AnimStart(w->anim2, 0, 0);
    w->gfx2 = AnimGetGfx(w->anim2);
    ColliderSetPosition(w->unk_54, w->x + 0x1800, w->y + 0x1000, w->z);
    w->unk_B0 = 0;
}

u8 task_poo_tanpopo_1(PooTanpopoWork* w) {
    if (w->palette != 0 && (w->flags & 2) != 0 && w->unk_B0 == 0) {
        w->unk_B0 = 1;
        AnimReset(w->anim);
        AnimReset(w->anim2);

        if (func_080D2C1C(w->unk_B6) == 0) {
            if (func_080C7BF8(2, 1, w->x + 0x1800, w->y + 0x2000, w->z) != 0) {
                func_080D2BF8(w->unk_B6);
            }
        }
    }
    return 1;
}

void task_poo_tanpopo_2(PooTanpopoWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 0, 32, 0, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjTiles(w->tiles2);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->unk_54);
            w->unk_B0 = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_0975E40E, 0x800);
            w->tiles2 = LoadObjTiles(gUnk_0975EC8E, 0x1800);
            w->palette = LoadObjPalette(gUnk_09849E18, 0x20);
            ColliderInit(w->unk_54, 6, 24, 0);
        }
        p = &w->unk_B0;
        if (*p != 0) {
            w->gfx = AnimUpdate(w->anim);
            w->gfx2 = AnimUpdate(w->anim2);
            DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, 0xFFF1);

            if (AnimIsFinished(w->anim2) == 0) {
                DrawSprite(x, y, w->gfx2, w->tiles2, w->palette, 0, 0x800, 100);
            } else if ((w->flags & 2) == 0) {
                *p = 0;
            }
        }
    }
}

void task_poo_tanpopo_3(PooTanpopoWork* w) {
    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ReleaseObjTiles(w->tiles);
        ReleaseObjTiles(w->tiles2);
        ColliderUnregister(w->unk_54);
    }
}

void task_poo_ti_board_0(PooBoardWork* w, PooPos* p) {
    w->x = p->x;
    w->y = p->y;
    w->z = 0;
    w->tiles = LoadObjTiles(gUnk_097565FC, 0x200);
    w->palette = 0;
    w->gfx = gUnk_097565E8;
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
}

u8 task_poo_ti_board_1(PooBoardWork* w) {
    if (w->palette != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_ti_board_2(PooBoardWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 16, 1, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->collider);
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D58, 0x20);
            ColliderInit(w->collider, 7, 8, 16);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->y >> 8) * 4);
    }
}

void task_poo_ti_board_3(PooBoardWork* w) {
    ReleaseObjTiles(w->tiles);

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
}

void task_poo_eeyoretail_0(PooEeyoreTailWork* w) {
    w->unk_0C = 0x7CD00;
    w->unk_10 = 0x49E00;
    w->unk_14 = -0x2000;
    w->unk_18 = 0;
    w->unk_1C = GetMaxSpriteTileBytes(gUnk_09EF5D68, 0x10);
    w->palette = 0;
    w->gfx = gUnk_09744842;
    TaskPoolInit(&w->tasks, 1);
    CreatePooShadowscaleTask(&w->tasks, &w->unk_0C, 0x66);
    gUnk_02034E18 = 0x1E;
    w->unk_20 = -w->unk_14;
}

u8 task_poo_eeyoretail_1(PooEeyoreTailWork* w) {
    if (func_080C9D84() != 0) {
        if (gUnk_02034E18 != 0) {
            ApproachValue(&w->unk_0C, 0x7FD00, gUnk_02034E18);
            ApproachValue(&w->unk_10, 0x49300, gUnk_02034E18);
            ApproachValue(&w->unk_20, 0, gUnk_02034E18);
            w->unk_14 = -w->unk_20;
            gUnk_02034E18--;
            func_080C9FA8(w->unk_0C, w->unk_10 + w->unk_14);
        }
        TaskPoolUpdate(&w->tasks);
    }
    return 1;
}

void task_poo_eeyoretail_2(PooEeyoreTailWork* w) {
    s16 x;
    s16 y;
    u16 pr;
    s32 z;

    x = ((s32)w->unk_0C >> 8) - gUnk_0203C40C;
    y = ((s32)w->unk_10 >> 8) + (w->unk_14 >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 8, 8, 8, 8) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_1C, gUnk_097448BA);
            w->palette = LoadObjPalette(gUnk_09849C58, 0x20);
        }
        if (func_080CFA70() != 0) {
            pr = 0x800;
            z = 0xFFEF;
        } else {
            pr = 0x400;
            z = 10;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, z);
        if (func_080C9D84() != 0) {
            TaskPoolDraw(&w->tasks);
        }
    }
}

void task_poo_eeyoretail_3(PooEeyoreTailWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
    TaskPoolDestroy(&w->tasks);
}

u8 func_080CFA70(void) {
    if (gUnk_02034E18 == 0) {
        return 1;
    }
    return 0;
}

void task_poo_honeycomb_0(PooHoneycombWork* w) {
    w->x = 0x8DE00;
    w->y = 0x46600;
    w->unk_2C = -0xA00;
    w->unk_30 = 0;
    w->unk_34 = GetMaxSpriteTileBytes(gUnk_09EF5FF0, 1);
    w->palette = 0;
    w->gfx = gUnk_097567FC;
    ColliderSetPosition(w->collider, w->x, w->y, 0);
    w->unk_9C = 0;
    gUnk_02034E1C = 0;
    w->unk_98 = 0;
    w->angle = 0;
}

u8 task_poo_honeycomb_1(PooHoneycombWork* w) {
    u8 c;

    if (w->unk_9C != 0) {
        switch (gUnk_02034E1C) {
        case 2:
            break;
        case 0:
            if (ColliderIsTouchingType(w->collider, 9) != 0) {
                c = func_080D2D50(2);
                if (c == 0) {
                    gUnk_0203C3F0 = 9;

                    if (func_080C9E70() != 0) {
                        gUnk_02034E1C = 1;
                        w->unk_94 = c;
                    }
                } else {
                    gUnk_0203C3F0 = 10;
                }
            }
            break;
        case 1:
            w->unk_98 = gSineTable[(u8)w->angle];
            w->angle += 16;
            w->unk_94++;
            if (w->unk_94 > 60) {
                w->unk_98 = 0;
                gUnk_02034E1C = 2;
                m4aSongNumStart(0x173);
            }
            break;
        }
    }
    return 1;
}

void task_poo_honeycomb_2(PooHoneycombWork* w) {
    u8* p;
    s16 x;
    s16 y;

    x = ((w->x + w->unk_98) >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 16, 16, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ReleaseObjTiles(w->tiles);
            w->palette = 0;
        }
        p = &w->unk_9C;
        if (*p != 0) {
            ColliderUnregister(w->collider);
            *p = 0;
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D78, 0x20);
            w->tiles = AllocObjTiles(w->unk_34, gUnk_09756810);
        }
        p = &w->unk_9C;
        if (*p == 0) {
            ColliderInit(w->collider, 6, 64, 0);
            *p = 1;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0xC00, 0xFFF0);
    }
}

void task_poo_honeycomb_3(PooHoneycombWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_9C != 0) {
        ColliderUnregister(w->collider);
    }
}

u8 func_080CFCC0(void) {
    if (gUnk_02034E1C == 2) {
        return 1;
    }
    return 0;
}

void task_poo_vegetable_0(PooVegetableWork* w) {
    w->x = 0x1AC00;
    w->y = 0x18000;
    w->z = 0;
    w->unk_30 = 0;
    w->unk_34 = GetMaxSpriteTileBytes(gUnk_09EF602C, 1);
    w->palette = 0;
    w->gfx = gUnk_09756C50;
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
}

u8 task_poo_vegetable_1(PooVegetableWork* w) {
    if (w->palette != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_vegetable_2(PooVegetableWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 32, 40, 48, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
            ColliderUnregister(w->collider);
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_34, gUnk_09756E28);
            w->palette = LoadObjPalette(gUnk_09849DB8, 0x20);
            ColliderInit(w->collider, 7, 0x26, 12);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->y >> 8) * 4);
    }
}

void task_poo_vegetable_3(PooVegetableWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
}

s32 func_080CFE34(PooPos* p) {
    s32 k;
    s32 x;
    s32 y;

    k = 0x2500;

    if (func_080D2D50(6) != 0) {
        k = 0x2100;
    }
    x = p->x - gPooCamera->pos.x;
    y = p->y - gPooCamera->pos.y;
    if (y + x < -0x1A00) {
        return 0;
    }

    if (y - x / 2 > k - 0xB80) {
        return 0;
    }

    if (y + x > k + 0x1700) {
        return 0;
    }

    if (y - x / 2 < -0x1180) {
        return 0;
    }
    return 1;
}

s32 func_080CFEA0(PooPos* p) {
    s32 k;
    s32 x;
    s32 y;

    k = 0x2500;

    if (func_080D2D50(6) != 0) {
        k = 0x2100;
    }
    x = p->x - gPooCamera->pos.x;
    y = p->y - gPooCamera->pos.y;
    if (y + x < -0x1A00) {
        return 0;
    }

    if (y - x / 2 > k - 0xB80) {
        return 0;
    }

    if (y + x > 0x3100) {
        return 0;
    }

    if (y - x / 2 < -0x1180) {
        return 0;
    }
    return 1;
}

u8 func_080CFF0C(void) {
    if (gPooActor.pos.z < 0) {
        return 0;
    }
    return func_080CFE34(&gPooActor.pos);
}

u8 func_080CFF30(void) {
    if (gPooActor.pos.z < -0x2000) {
        return 0;
    }
    return func_080CFE34(&gPooActor.pos);
}

void func_080CFF58(u32* a, u32* b, u16 c) {
    s32 d;
    s32 e;

    d = *a - gPooCamera->pos.x;
    if (d < -0x600) {
        d = -0x600;
    } else if (d > 0xA00) {
        d = 0xA00;
    }
    e = d / 2 - 0x300;
    ApproachValue(a, d + gPooCamera->pos.x, c);
    ApproachValue(b, e + gPooCamera->pos.y, c);
}

void func_080CFFC0(s32* a, s32* b) {
    s32 t;
    s32 y;

    t = *a;
    y = *b;
    t -= 0x4600;
    *a = (t - y * 2) / 5;
    *b = -0x2300 - *a * 2;
}

void func_080CFFF0(s32* a, s32* b) {
    s32 t;
    s32 y;

    t = *a;
    y = *b;
    t += 0x5000;
    *a = (t - y * 2) / 5;
    *b = 0x2800 - *a * 2;
}

void func_080D001C(s32* a, s32* b) {
    s32 t;
    s32 y;

    t = *a;
    y = *b;
    *a = (y * 2 + t * 4 + 0xF00) / 5;
    *b = *a / 2 - 0x800;
}

void func_080D0050(s32* a, s32* b) {
    s32 x;
    s32 y;

    x = *a;
    y = *b;
    *a = (y * 2 + x * 4 - 1280) / 5;
    *b = *a / 2 + 768;
}

void func_080D0084(u32* a, u32* b, u16 c) {
    s32 x;
    s32 y;

    x = *a - gPooCamera->pos.x;
    y = *b - gPooCamera->pos.y;

    if (x < -0xB00 && y < -0xD00) {
        func_080CFFC0(&x, &y);

        if (y < -0xD00) {
            func_080D001C(&x, &y);
        } else if (y > -0xD00) {
            func_080D0050(&x, &y);
        }
    } else if (x > 0xF00 && y > 0x600) {
        func_080CFFF0(&x, &y);

        if (y < 0x600) {
            func_080D001C(&x, &y);
        } else if (y > 0xA00) {
            func_080D0050(&x, &y);
        }
    } else if (-x / 2 + y > 0) {
        func_080D0050(&x, &y);

        if (x < -0x1700) {
            func_080CFFC0(&x, &y);
        } else if (x > 0xF00) {
            func_080CFFF0(&x, &y);
        }
    } else {
        func_080D001C(&x, &y);

        if (x < -0xB00) {
            func_080CFFC0(&x, &y);
        } else if (x > 0x1800) {
            func_080CFFF0(&x, &y);
        }
    }
    ApproachValue(a, x + gPooCamera->pos.x, c);
    ApproachValue(b, y + gPooCamera->pos.y, c);
}

s32 func_080D01BC(s32 x, s32 y) {
    s32 dx;
    s32 dy;

    dx = x - gPooCamera->pos.x;
    dy = y - gPooCamera->pos.y;
    if (dx < -0xB00 && dy < -0xD00) {
        return 0x53;
    }

    if (dx > 0xF00 && dy > 0x600) {
        return 0xD3;
    }

    if (-dx / 2 + dy > 0) {
        return 0x2D;
    }
    return 0xAD;
}

s32 func_080D0210(s32 a, s32 b) {
    s32 x;
    s32 y;

    x = a - gPooCamera->pos.x;
    y = b - gPooCamera->pos.y;
    if (x < -0x3D00 || x > 0x4300 || y < -0x1F00 || y > 0x3800) {
        return 0;
    }

    if (x < -0x1100 && y <= 0x2FF) {
        return 0x53;
    }

    if (x > 0x1700 && y > 0x500) {
        return 0xD3;
    }

    if (-x / 2 + y > 0) {
        return 0x2D;
    }
    return 0xAD;
}

void task_poo_wagon_0(PooCamera* w) {
    gPooCamera = w;
    w->pos.x = 0x2AE00;
    w->pos.y = 0x17700;
    w->pos.z = 0;
    w->pos.unk_0C = 0;
    w->pos2 = w->pos;

    if (func_080D2D50(6) != 0) {
        w->pos.y += 0xC00;
    }
    w->palette = 0;
    w->gfx = gUnk_09758C04;
    w->gfx2 = gUnk_09758B70;
    w->gfx3 = gUnk_09758C20;
    w->unk_3C = 0;
    w->timer = 0;
    w->angle = 0;
}

u8 task_poo_wagon_1(PooCamera* w) {
    u8 c;
    s32 t;
    s32 d;

    if (func_080CFF0C() != 0) {
        if (w->pos.y == w->pos2.y) {
            w->pos.y += 0x100;
            gPooActor.pos.y += 0x100;

            if (w->unk_3C != 0) {
                gUnk_0203C3EC->y += 0x100;
            }
        }
    } else if (func_080D2D50(6) == 0) {
        if (w->pos.y != w->pos2.y) {
            w->pos.y -= 0x100;
            gPooActor.pos.y -= 0x100;

            if (w->unk_3C != 0) {
                gUnk_0203C3EC->y -= 0x100;
            }
        }
    }

    c = func_080CFEA0(gUnk_0203C3EC);

    if (c != 0) {
        if (w->unk_3C == 0) {
            gUnk_0203C3DC = w->pos.x;
            gUnk_0203C3E8 = w->pos.y;
            gUnk_0203C3F0 = 11;
            w->unk_3C = 1;
        }
    } else {
        w->unk_3C = 0;
    }

    if (func_080CFF0C() != 0 && func_080C9D98() != 0 && func_080D2D50(6) == 0) {
        w->timer++;

        if (w->timer > 100) {
            if (w->pos.y != w->pos2.y + 0xC00) {
                t = w->pos.y - 0xC00;
                d = w->pos2.y - t;
                w->pos.y += d;
                gPooActor.pos.y += d;
                gUnk_0203C3EC->y += d;
                func_080D2D3C(6);
                m4aSongNumStart(0x90);
                w->timer = 0;
            }
        }
    } else {
        w->timer = 0;
    }
    return 1;
}

void task_poo_wagon_2(PooCamera* w) {
    s32 t;
    s16 x;
    s16 y;
    u16 n;
    u16 p;
    s32 d;
    s32 k;

    d = 0;

    if (w->timer != 0) {
        t = gSineTable[(u8)w->angle];
        w->angle += 16;
    } else {
        t = 0;
    }
    x = ((w->pos.x + t) >> 8) - gUnk_0203C40C;
    y = (w->pos.y >> 8) + (w->pos.z >> 8) - gUnk_0203C3F8;

    if (IsRectOutsideScreen(x, y, 32, 40, 48, 48) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjTiles(w->tiles2);
            ReleaseObjTiles(w->tiles3);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
        return;
    }

    if (w->palette == 0) {
        w->tiles = AllocObjTiles(0x560, gUnk_09758C94);
        w->tiles2 = AllocObjTiles(0x4C0, gUnk_09758C94);
        w->tiles3 = AllocObjTiles(160, gUnk_09758C94);
        w->palette = LoadObjPalette(gUnk_09849DD8, 32);
    }
    n = func_080CBB7C();

    if (func_080CFF30() != 0) {
        gUnk_02034E26 = n + 3;
        gUnk_02034E24 = n - 1;

        if (func_080C9DAC() != 0) {
            if (gPooActor.pos.y >= gUnk_0203C3EC->y) {
                gUnk_02034E26 += 6;
            } else {
                gUnk_02034E24 += 0xFFFC;
            }
        }
    } else {
        d = (u8)func_080D0210(gPooActor.pos.x, gPooActor.pos.y);

        if (d == 0) {
            k = w->pos.y + 0x300;
            gUnk_02034E26 = -0x1004 - (k >> 8) * 4;
            gUnk_02034E24 = -0x1009 - (k >> 8) * 4;
        } else if (d == 83 || d == 173) {
            gUnk_02034E26 = n - 3;
            gUnk_02034E24 = n - 8;
        } else {
            gUnk_02034E24 = n + 4;
            gUnk_02034E26 = n + 9;
        }
    }
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, gUnk_02034E26);
    DrawSprite(x, y, w->gfx2, w->tiles2, w->palette, 0, 0x800, gUnk_02034E24);
    p = -0x1002 - ((w->pos.y - 0xE00) >> 8) * 4;

    if (func_080CFF30() == 0 && n > p && (d == 83 || d == 173)) {
        p = n - 1;
    }
    DrawSprite(x, y, w->gfx3, w->tiles3, w->palette, 0, 0x800, p);
}

void task_poo_wagon_3(PooWagonWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjTiles(w->tiles2);
        ReleaseObjTiles(w->tiles3);
        ReleaseObjPalette(w->palette);
    }
}

u16 func_080D06BC(void) {
    return gUnk_02034E24;
}

u16 func_080D06C8(void) {
    return gUnk_02034E26;
}

void task_poo_wagonwheel_0(PooWheelWork* w) {
    s16 x;
    s16 y;

    if (func_080D2D50(6) == 0) {
        w->unk_24 = 0x2A800;
        w->unk_28 = 0x18D00;
        w->unk_36 = 2;
        w->gfx = gUnk_09758B9C;
    } else {
        func_080D2CF4(&x, &y);
        w->unk_24 = x << 8;
        w->unk_28 = y << 8;
        w->unk_36 = 4;
        w->gfx = gUnk_09758BF4;
    }
    w->unk_3C = w->unk_24;
    w->unk_2C = 0;
    w->unk_30 = 0;
    w->unk_34 = 0x180;
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF60AC, gUnk_09EF6078);
    AnimStart(w->anim, w->unk_36, 1);
    w->unk_38 = 0;
    w->unk_40 = 0;
}

u8 task_poo_wagonwheel_1(PooWheelWork* w) {
    if (w->unk_36 == 2 && func_080D2D50(6) != 0) {
        w->unk_36 = 3;
        AnimStart(w->anim, 3, 1);
    }

    if (w->unk_36 == 3) {
        w->gfx = AnimUpdate(w->anim);

        if (w->unk_38 <= 0x4FF) {
            w->unk_38 += 6;
        }
        w->unk_28 += w->unk_38;
        w->unk_24 += w->unk_38;
        if (w->unk_24 > w->unk_3C + 0x4800) {
            w->unk_24 = w->unk_3C + 0x4800;
        }
    }

    if (w->unk_40 != 0 && w->palette == 0) {
        return 0;
    }
    return 1;
}

void task_poo_wagonwheel_2(PooWheelWork* w) {
    u16* p;
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 32, 0, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;

            if (w->unk_36 == 3) {
                w->unk_36 = 4;
                w->gfx = gUnk_09758BF4;
            }
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_34, gUnk_09758C94);
            w->palette = LoadObjPalette(gUnk_09849DD8, 0x20);
        }

        if (func_080D2D50(6) == 0) {
            p = &gUnk_02034E28;
            *p = func_080D06BC() - 1;
        } else {
            gUnk_02034E28 = -0x1004 - (w->unk_28 >> 8) * 4;
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, gUnk_02034E28);
    }
}

void task_poo_wagonwheel_3(PooWheelWork* w) {
    if (func_080D2D50(6) != 0) {
        func_080D2CE0(w->unk_24 >> 8, w->unk_28 >> 8);
    }

    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
}

void task_poo_spark_0(PooSparkWork* w, PooPos* p) {
    w->pos = *p;
    w->tiles = AllocObjTiles(0x200, gUnk_098A4B68);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    AnimInit(w->anim, gUnk_09EF8CC0, gUnk_09EF8CA0);
    AnimStart(w->anim, 0, 1);
}

u8 task_poo_spark_1(PooSparkWork* w) {
    AnimUpdate(w->anim);

    if (AnimIsFinished(w->anim) != 0) {
        return 0;
    }
    return 1;
}

void task_poo_spark_2(PooSparkWork* w) {
    u16 x;
    u16 y;

    x = (w->pos.x >> 8) - gUnk_0203C40C;
    y = (w->pos.y >> 8) + (w->pos.z >> 8) - gUnk_0203C3F8;
    DrawSprite(x, y, AnimGetGfx(w->anim), w->tiles, w->palette, 0, 0x400, 0x50);
}

void task_poo_spark_3(PooSparkWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_bee_0(PooBeeWork* w) {
    void* a;
    void* b;
    s32 i;

    w->unk_A4 = 0x8DE00;
    w->unk_A8 = 0x46600;
    w->unk_AC = -0xA00;
    w->unk_B0 = 0;
    i = 0;
    a = gUnk_09EF6024;
    b = gUnk_09EF5FF8;

    for (; i < 4; i++) {
        w->sub[i].unk_00 = -0x500;
        w->sub[i].unk_04 = 0x500;
        w->sub[i].unk_10 = gUnk_096FD730[i].unk_00;
        w->sub[i].unk_14 = gUnk_096FD730[i].unk_04;
    }
    AnimInit(w->anim, a, b);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    w->palette = 0;
    gUnk_02034E2C = 0;
    w->unk_C6 = 8;
    w->unk_C8 = 1;
}

u8 task_poo_bee_1(PooBeeWork* w) {
    s32 i;

    if (func_080CFCC0() != 0) {
        if (w->unk_C8 != 0) {
            w->unk_C8 = 0;

            for (i = 0; i < 4; i++) {
                w->sub[i].unk_00 = w->unk_A4 - 0x500;
                w->sub[i].unk_04 = w->unk_A8 + 0x500;
                w->sub[i].unk_08 = w->unk_AC;
                w->sub[i].unk_10 = 0x2000 + gUnk_0203C3EC->x + gUnk_096FD730[i].unk_00;
                w->sub[i].unk_14 = -0x2000 + gUnk_0203C3EC->y + gUnk_096FD730[i].unk_04;
            }
        }

        if (gUnk_02034E2C <= 3) {
            ApproachValue(&w->sub[gUnk_02034E2C].unk_00, w->sub[gUnk_02034E2C].unk_10, w->unk_C6);
            ApproachValue(&w->sub[gUnk_02034E2C].unk_04, w->sub[gUnk_02034E2C].unk_14, w->unk_C6);
            w->unk_C6--;

            if (w->unk_C6 == 0) {
                w->unk_C6 = 8;
                gUnk_02034E2C++;

                if (gUnk_02034E2C > 3) {
                    w->unk_A4 = gUnk_0203C3EC->x + 0x2000;
                    w->unk_A8 = gUnk_0203C3EC->y - 0x2000;
                    w->unk_B4 = w->unk_B8 = 0;
                }
            }
            func_080C9FA8(w->unk_A4, w->unk_A8 + w->unk_AC);
        } else {
            w->unk_B4 = w->unk_A4 - (gUnk_0203C3EC->x + 0x2000);
            w->unk_B8 = w->unk_A8 - (gUnk_0203C3EC->y - 0x2000);
            w->unk_A4 -= w->unk_B4;
            w->unk_A8 -= w->unk_B8;

            for (i = 0; i < 4; i++) {
                w->sub[i].unk_00 -= w->unk_B4;
                w->sub[i].unk_04 -= w->unk_B8;
            }

            if (func_080C9D84() == 0) {
                func_080C9FA8(w->unk_A4, w->unk_A8 + w->unk_AC);
            }
        }
        w->gfx = AnimUpdate(w->anim);
    }
    return 1;
}

void task_poo_bee_2(PooBeeWork* w) {
    s32 x;
    s32 y;
    s32 u;
    s32 v;
    s32 i;

    if (func_080CFCC0() == 0) {
        return;
    }
    x = (w->unk_A4 >> 8) - gUnk_0203C40C;
    y = (w->unk_A8 >> 8) + (w->unk_AC >> 8) - gUnk_0203C3F8;

    if (IsRectOutsideScreen(x, y, 19, 17, 46, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ReleaseObjTiles(w->tiles);
            w->palette = 0;
        }
        return;
    }

    if (w->palette == 0) {
        w->palette = LoadObjPalette(gUnk_09849D98, 32);
        w->tiles = LoadObjTiles(gUnk_09756ACE, 0x180);
    }

    for (i = 0; i < gUnk_02034E2C + 1 && i <= 3; i++) {
        u = (w->sub[i].unk_00 >> 8) - gUnk_0203C40C;
        v = (w->sub[i].unk_04 >> 8) + (w->sub[i].unk_08 >> 8) - gUnk_0203C3F8;
        DrawSprite(u, v, w->gfx, w->tiles, w->palette, 0, 0x800, i - ((w->unk_A8 >> 8) * 4 + 0x1003));
    }
}

void task_poo_bee_3(PooObjWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
}

u8 func_080D0E3C(void) {
    if (gUnk_02034E2C <= 3) {
        return 0;
    }
    return 1;
}

void task_poo_beeAfterEvent_0(PooBeeAfterEventWork* w) {
    gPooBeeAfterEventWork = w;
    w->unk_44 = 0x8DE00;
    w->unk_48 = 0x46600;
    w->unk_4C = -0xA00;
    w->unk_50 = 0;
    AnimInit(w->anim, gUnk_09EF6024, gUnk_09EF5FF8);
    AnimStart(w->anim, 1, 1);
    w->gfx = AnimGetGfx(w->anim);
    AnimInit(w->anim2, gUnk_09EF6024, gUnk_09EF5FF8);
    AnimStart(w->anim2, 0, 1);
    w->gfx2 = AnimGetGfx(w->anim2);
    w->palette = 0;
}

u8 task_poo_beeAfterEvent_1(PooBeeAfterEventWork* w) {
    w->gfx = AnimUpdate(w->anim);
    w->gfx2 = AnimUpdate(w->anim2);
    return 1;
}

void task_poo_beeAfterEvent_2(PooBeeAfterEventWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_44 >> 8) - gUnk_0203C40C;
    y = (w->unk_48 >> 8) + (w->unk_4C >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 19, 17, 46, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjPalette(w->palette);
            ReleaseObjTiles(w->tiles);
            ReleaseObjTiles(w->tiles2);
            w->palette = 0;

            if (func_080C7CBC() == 0) {
                m4aSongNumStop(0x182);
            }
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849D98, 0x20);
            w->tiles = LoadObjTiles(gUnk_09756ACE, 0x180);
            w->tiles2 = LoadObjTiles(gUnk_09756ACE, 0x180);
            m4aSongNumStart(0x182);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1002 - (w->unk_48 >> 8) * 4);
        DrawSprite(x - 5, y + 5, w->gfx2, w->tiles2, w->palette, 0, 0x800, -0x1003 - (w->unk_48 >> 8) * 4);
    }
}

void task_poo_beeAfterEvent_3(PooBeeAfterEventWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjTiles(w->tiles2);
        ReleaseObjPalette(w->palette);
    }
}

u8 func_080D1050(void) {
    if (func_080D2D50(2) != 0) {
        if (gPooBeeAfterEventWork->palette != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080D1078(PooSpot* p) {
    PooSpot t[18];
    u16 i;

    memcpy(t, gUnk_096FD778, sizeof(t));
    i = func_080D1710();
    if (i > 13) {
        i += GetRandom() % 4;
    }
    p->unk_00 = t[i].unk_00 + 0xAB300;
    p->unk_04 = t[i].unk_04 + 0x57100;
    p->unk_08 = t[i].unk_08;
}

void task_poo_cabbage_0(PooCabbageWork* w) {
    u16 r;

    w->x = 0x98300;
    w->y = 0x4D100;
    w->z = 0;
    w->vz = 0x4CC;
    r = GetRandom();
    w->angle = (r & 15) + 88;
    w->unk_C0 = 0x1CC;
    w->palette = 0;
    AnimInit(w->anim, gUnk_09EF6060, gUnk_09EF602C);
    w->state = 2;
    AnimStart(w->anim, 2, 1);
    w->gfx = AnimGetGfx(w->anim);
    ColliderInit(w->collider, 10, 8, 16);
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    w->unk_D0 = 1;
    TaskPoolInit(&w->tasks, 2);
    CreatePooShadowscaleTask(&w->tasks, &w->x, 0x80);
    w->task = 0;
    w->unk_CE = 0;
    w->unk_D1 = 0;
    w->unk_D2 = 1;
}

u8 task_poo_cabbage_1(PooCabbageWork* w) {
    u16 t[15];
    u16 sx;
    s16 sy;
    s32 v;

    memcpy(t, gUnk_096FD850, 30);
    w->unk_CE++;

    switch (w->state) {
    case 2:
        if (gUnk_0203C3D8 != 0 && func_080C76B0(w->collider) != 0) {
            if (IsTaskActive(w->task) != 0) {
                func_08000DE8(&w->tasks, w->task);
            }
            w->task = TaskCreate(&w->tasks, &gTaskDescPooSpark, &w->x);
            w->state = 3;
            AnimStart(w->anim, 3, 0);
            m4aSongNumStart(222);
            w->unk_CA = 30;
            w->unk_CC = 20;
            w->unk_A0 = -0x2000;
            func_080D1078((PooSpot*)&w->unk_34);
            w->unk_D4 = func_080D1710();
            func_080D16FC();

            if (w->unk_D0 != 0) {
                ColliderUnregister(w->collider);
                w->unk_D0 = 0;
            }
        } else {
            w->x += gSineTable[w->angle] * w->unk_C0 >> 8;
            w->y += -gSineTable[w->angle + 0x40] * w->unk_C0 >> 8;
            w->vz += 51;
            w->z += w->vz;

            if (w->z > 0) {
                w->z = 0;
                w->vz = -(w->vz * 179 >> 8);
            }

            if (w->unk_D1 != 0) {
                v = (w->x >> 8) - gUnk_0203C40C;
                sy = (w->y >> 8) + (w->z >> 8) - gUnk_0203C3F8;
                sx = v;

                if ((u16)(sx + 16) > 272 || sy < -36 || sy > 196) {
                    return 0;
                }
            }
        }
        break;
    case 3:
        if (w->unk_CC != 0) {
            ApproachValue(&w->z, w->unk_3C + w->unk_A0, w->unk_CC);
            w->unk_CC--;

            if (w->unk_CC == 0 && w->unk_A0 < 0) {
                w->unk_CC = 10;
                w->unk_A0 = 0;
            }
        }
        ApproachValue(&w->x, w->unk_34, w->unk_CA);
        ApproachValue(&w->y, w->unk_38, w->unk_CA);
        w->unk_CA--;

        if (w->unk_CA == 0) {
            w->state = 4;
            AnimStart(w->anim, 4, 0);
        }
        break;
    case 4:
        if (func_080D2D50(4) == 0 && w->unk_D4 == 13) {
#ifdef VERSION_EU
            func_080C7B84(140);
#else
            func_080C7B84(142);
#endif
            func_080D2D3C(4);
            func_0800FDD0(83);
        }

        if (AnimIsFinished(w->anim) != 0) {
            w->state = 1;
            AnimStart(w->anim, 1, 0);
            func_080D171C();
            w->unk_D2 = 0;

            if (w->unk_D4 == 5) {
                w->x = 0xAB300;
                w->y = 0x57100;
                w->z = 0;
                w->gfx = gUnk_09756D86;
            } else if (w->unk_D4 == 8) {
                w->x = 0xAB300;
                w->y = 0x57100;
                w->z = 0;
                w->gfx = gUnk_09756D90;
            } else {
                w->gfx = gUnk_09756C78;
            }
        }
        break;
    case 1:
        if (t[w->unk_D4] < func_080D172C()) {
            return 0;
        }
        break;
    }
    return 1;
}

void task_poo_cabbage_2(PooCabbageWork* w) {
    u16 t[5];
    u16 z;
    s16 x;
    s16 y;

    memcpy(t, gUnk_096FD86E, sizeof(t));
    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) + (w->z >> 8) - gUnk_0203C3F8;

    if (x < -16 || x > 256 || y < -36 || y > 196) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = LoadObjTiles(gUnk_09756E28, 0x1D20);
            w->palette = LoadObjPalette(gUnk_09849DB8, 32);
        }

        if (w->unk_D2 != 0) {
            w->gfx = AnimUpdate(w->anim);
        }
        w->unk_D1 = 1;

        if (w->unk_D0 != 0) {
            ColliderSetPosition(w->collider, w->x, w->y, w->z);
        }

        if (w->unk_D4 < 9 || w->unk_D4 > 13) {
            z = -0x1004 - (w->y >> 8) * 4;
        } else {
            z = 0xDA38 - t[w->unk_D4 - 9];
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, z);

        if (w->state != 4 && w->state != 1) {
            TaskPoolUpdate(&w->tasks);
            TaskPoolDraw(&w->tasks);
        }
    }
}

void task_poo_cabbage_3(PooCabbageWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }

    if (w->unk_D0 != 0) {
        ColliderUnregister(w->collider);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_cabbageborn_0(PooCabbageBornWork* w) {
    TaskPoolInit(&w->tasks, 0x20);
    w->unk_14 = 0;
    w->timer = 0;
    gUnk_02034E34 = 0;
    gUnk_02034E36 = 0;
}

u8 func_080D1650(void) {
    if (func_080D2D50(6) != 0 && func_080C9910() == 0 && gUnk_0203C40C > 0x9EB && gUnk_0203C40C <= 0xA8A && gUnk_0203C3F8 <= 0x548 && gUnk_0203C3F8 > 0x4F9) {
        return 1;
    }
    return 0;
}

u8 task_poo_cabbageborn_1(PooCabbageBornWork* w) {
    if (func_080D1650() != 0 && w->timer == 0) {
        TaskCreate(&w->tasks, &gTaskDescPooCabbage, 0);
        w->timer = 40;
    }

    if (w->timer != 0) {
        w->timer--;
    }
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void task_poo_cabbageborn_2(TaskPool* w) {
    TaskPoolDraw(w);
}

void task_poo_cabbageborn_3(TaskPool* w) {
    TaskPoolDestroy(w);
}

void func_080D16FC(void) {
    if (gUnk_02034E34 <= 13) {
        gUnk_02034E34++;
    }
}

u16 func_080D1710(void) {
    return gUnk_02034E34;
}

void func_080D171C(void) {
    gUnk_02034E36++;
}

u16 func_080D172C(void) {
    return gUnk_02034E36;
}

u8 func_080D1738(void) {
    if (func_080D2D50(4) == 0) {
        if (func_080D2D50(6) != 0) {
            if (gUnk_0203C3F8 > 0x4F9) {
                return 1;
            }
        }
    }
    return 0;
}

void task_poo_mapobjhit_0(PooMapObjHitWork* w, PooMapObjHitArgs* a) {
    w->x = a->x;
    w->y = a->y;
    w->z = 0;
    w->unk_98 = a->unk_14;
    w->unk_9C = a->unk_18;
    w->desc = a->desc;
    w->unk_3A = GetMaxSpriteTileBytes(w->desc->unk_0C, w->desc->unk_04);
    w->palette = 0;
    AnimInit(w->anim, w->desc->unk_08, w->desc->unk_0C);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    w->unk_4C = 0x1000;
    w->unk_50 = 0x1800;
    ColliderSetPosition(w->unk_3C, w->x + 0x1000, w->y + 0xC00, w->z);
    w->unk_38 = 0;
}

u8 task_poo_mapobjhit_1(PooMapObjHitWork* w) {
    func_080D2F10(0);

    if (gUnk_0203C3D8 != 0) {
        if (func_080C76B0(w->unk_3C) != 0) {
            if (w->unk_38 == 0) {
                w->unk_38 = 1;
                AnimReset(w->anim);

                if (func_080D2C1C(w->unk_9C) == 0) {
                    if (func_080C7BF8(2, 1, w->x + 0x1000, w->y + 0x1800, w->z) != 0) {
                        func_080D2BF8(w->unk_9C);
                    }
                }

                if (w->unk_98 == 4) {
                    m4aSongNumStart(0x146);
                } else {
                    m4aSongNumStart(0xE0);
                }
            }
        }
    }

    if (w->unk_38 != 0) {
        w->gfx = AnimUpdate(w->anim);

        if (AnimIsFinished(w->anim) != 0) {
            w->unk_38 = 0;
        }
    }
    return 1;
}

void task_poo_mapobjhit_2(PooMapObjHitWork* w) {
    s16 x;
    s16 y;
    s32 pr;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (w->unk_38 == 0 || IsRectOutsideScreen(x, y, 0, 24, 0, 32) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->tiles = AllocObjTiles(w->unk_3A, w->desc->unk_00);
            w->palette = LoadObjPalette(w->desc->unk_10, 0x20);
        }
        pr = 0x800;
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, pr, 0xFFF1);
        func_080D2F10(1);
    }
}

void task_poo_mapobjhit_3(PooObjWork* w) {
    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
        ReleaseObjTiles(w->tiles);
    }
}

void CreatePooMapobjhitTask(void* pool, u32 a, s32 x, s32 y, u16 e) {
    PooMapObjHitArgs args;

    args.x = x;
    args.y = y;
    args.desc = &gPooMapObjHitDescs[a];
    args.unk_14 = a;
    args.unk_18 = e;
    TaskCreate(pool, &gTaskDescPooMapobjhit, &args);
}

void func_080D19C4(PooPrizeWork* w) {
    u8 v;

    w->vz += 56;
    w->z += w->vz;
    w->x += gSineTable[w->angle] * w->unk_88 >> 8;
    w->y += -gSineTable[w->angle + 0x40] * w->unk_88 >> 8;

    if (func_080CA3A0((PooPos*)w) != 0) {
        w->angle = (u8)(w->angle + 100) + GetRandom() % 57;
    } else {
        w->unk_0C = 0;
    }

    if (w->z > w->unk_0C) {
        w->z = w->unk_0C;
        w->vz = -(w->vz * 179 >> 8);
        w->unk_88 = w->unk_88 * 212 >> 8;
    }

    if (w->collider[0x2C] != 0 && ColliderIsTouchingType(w->collider, 1) != 0) {
        switch (w->unk_80) {
        case 2:
        case 3:
            m4aSongNumStart(107);
            gGameState.progression.mooglePoints += w->unk_94;

            if (gGameState.progression.mooglePoints > 99999) {
                gGameState.progression.mooglePoints = 99999;
            }
            break;
        case 0:
        case 1:
        default:
            m4aSongNumStart(107);
            gGameState.hp += w->unk_94;

            if (gGameState.hp > (s16)gGameState.progression.maxHp) {
                gGameState.hp = gGameState.progression.maxHp;
            }
            break;
        }

        w->update = func_080D1B94;
        w->unk_82 = 0;
        w->angle = GetAngle(gPooActor.pos.x, gPooActor.pos.y, w->x, w->y);
        w->unk_97 = 1;
        w->unk_96 = 1;
        w->unk_8D = GetRandom() % 6 + 5;
        ColliderSetDisabled(w->collider, 1);
    } else {
        ColliderSetPosition(w->collider, w->x, w->y, w->z);

        if (w->unk_82 == 20) {
            ColliderSetDisabled(w->collider, 0);
        }

        if (w->unk_82 > 420) {
            v = 0;

            if (w->unk_96 == 0) {
                v = 1;
            }
            w->unk_96 = v;
        }

        if (w->unk_82++ > 480) {
            w->update = 0;
        }
    }
}

void func_080D1B94(PooPrizeWork* w) {
    PooPos* g;
    const s16* t;
    s32 tx;
    s32 ty;
    s32 tz;
    s32 s;
    u8 a;

    g = &gPooActor.pos;
    t = gSineTable;
    a = w->angle;
    tx = g->x + ((t[a] << 5) * w->unk_90 >> 8);
    s = -gSineTable[a + 0x40] * 22;
    ty = g->y + (s * w->unk_90 >> 8);
    tz = g->z - ((w->unk_82 >> 1) << 8);
    w->angle = a + w->unk_8D;
    w->x += (tx - w->x) >> 2;
    w->y += (ty - w->y) >> 2;
    w->z += (tz - w->z) >> 2;
    w->unk_0C = 0;
    w->unk_90 -= 2;

    if (w->unk_82 > 60) {
        w->update = 0;
    } else {
        w->unk_82++;
    }
}

void task_poo_prize_0(PooPrizeWork* w, PoohPrizeArgs* a) {
    w->x = a->x;
    w->y = a->y;
    w->z = a->z;
    w->unk_0C = 0;
    w->vz = -(GetRandom() % 0x301 + 0x200);
    w->unk_88 = GetRandom() % 155 + 153;
    w->angle = GetRandom();
    w->tiles = LoadObjTiles(gUnk_098A5CF4, 0x160);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_80 = a->unk_14;

    switch (w->unk_80) {
    case 3:
        w->gfx = gUnk_098A5CAE;
        w->unk_94 = 10;
        break;
    case 2:
        w->gfx = gUnk_098A5CA4;
        w->unk_94 = 4;
        break;
    case 1:
        w->gfx = gUnk_098A5C9A;
        w->unk_94 = 10;
        break;
    case 0:
    default:
        w->gfx = gUnk_098A5C90;
        w->unk_94 = 3;
        break;
    }
    w->gfx2 = gUnk_098A5CB8;
    w->unk_97 = 0;
    w->unk_96 = 1;
    w->unk_82 = 0;
    w->update = func_080D19C4;
    w->unk_90 = 0x100;
    ColliderInit(w->collider, 5, 16, 50);
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    ColliderSetDisabled(w->collider, 1);
}

u8 task_poo_prize_1(PooPrizeWork* w) {
    if (w->update != 0) {
        w->update(w);

        if (w->update != 0) {
            return 1;
        }
    }
    return 0;
}

void task_poo_prize_2(PooPrizeWork* w) {
    s32 aff;
    s32 s;
    s16 x;
    s16 y;

    if (w->unk_96 == 0) {
        return;
    }

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) + (w->z >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 8, 8, 8, 8) != 0) {
        return;
    }

    s = w->unk_90;
    if (s != 256) {
        aff = AllocObjAffine(0, s, s, 0);
    } else {
        aff = 0;
    }
    DrawSprite(x, y, w->gfx, w->tiles, w->palette, aff, 0x800, -0x1004 - (w->y >> 8) * 4);

    if (w->unk_97 == 0) {
        y = (w->y >> 8) + (w->unk_0C >> 8) - gUnk_0203C3F8;
        DrawSprite(x, y, w->gfx2, w->tiles, w->palette, aff, 0x800, 0xFFF0);
    }
}

void task_poo_prize_3(PooPrizeWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ColliderUnregister(w->collider);
}

void task_poo_zzz_0(PooZzzWork* w, u8* arg) {
    w->unk_24 = gUnk_0203C3EC;
    w->tiles = AllocObjTiles(0x100, gUnk_097257D8);
    w->palette = LoadObjPalette(gUnk_09849A98, 0x20);
    AnimInit(w->anim, gUnk_09EF5904, gUnk_09EF5844);

    if (*arg != 0) {
        AnimStart(w->anim, 8, 1);
    } else {
        AnimStart(w->anim, 7, 1);
    }
    w->gfx = AnimGetGfx(w->anim);
}

u8 task_poo_zzz_1(void* w) {
    return 1;
}

void task_poo_zzz_2(PooZzzWork* w) {
    PooPos* p;
    s16 x;
    s16 y;
    void* g;

    p = w->unk_24;
    x = (p->x >> 8) - gUnk_0203C40C;
    y = (p->y >> 8) + (p->z >> 8) - gUnk_0203C3F8;
    if (x >= -0x20 && x <= 0x110 && y >= -0x20 && y <= 0xC0) {
        g = AnimUpdate(w->anim);
        w->gfx = g;
        DrawSprite(x, y, g, w->tiles, w->palette, 0, 0x400, 0x0B);
    }
}

void task_poo_zzz_3(PooZzzWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void func_080D1FB8(PooBflyPart* p) {
    switch (((p->unk_48 + 16) & 0xFF) >> 5) {
    case 1:
        p->unk_4C = 4;
        p->unk_50 = 1;
        break;
    case 2:
        p->unk_4C = 3;
        p->unk_50 = 1;
        break;
    case 3:
        p->unk_4C = 2;
        p->unk_50 = 1;
        break;
    case 4:
        p->unk_4C = 1;
        p->unk_50 = 0;
        break;
    case 5:
        p->unk_4C = 2;
        p->unk_50 = 0;
        break;
    case 6:
        p->unk_4C = 3;
        p->unk_50 = 0;
        break;
    case 7:
        p->unk_4C = 4;
        p->unk_50 = 0;
        break;
    case 0:
    default:
        p->unk_4C = 0;
        p->unk_50 = 0;
        break;
    }
}

void func_080D2034(PooBflyPart* p) {
    const AnimDef* d;

    func_080D1FB8(p);
    d = &gUnk_09EF4C88[p->unk_4C];
    AnimChangeWithTables(p->anim, d->animId, 1, d->anims, d->gfxTable);
    SetObjTileSource(p->tiles, d->tiles);
}

void func_080D206C(PooBflyPart* p) {
    if ((s8)p->unk_48 >= 0) {
        p->unk_40 = p->unk_38;
        p->unk_44 = p->unk_3C;
    } else {
        p->unk_40 = p->unk_30;
        p->unk_44 = p->unk_34;
    }
    p->tiles = AllocObjTiles(0x40, 0);
    AnimInit(p->anim, 0, 0);
    func_080D2034(p);
    p->gfx = AnimGetGfx(p->anim);
}

void task_poo_butterfly_0(PooButterflyWork* w, PooPos* p) {
    w->unk_D4 = p->x;
    w->unk_D8 = p->y;
    w->unk_DC = p->z - 0xE00;
    w->palette = LoadObjPalette(gUnk_09849C38, 0x20);
    w->unk_00[0].unk_20 = w->unk_D4 - 0x1000;
    w->unk_00[0].unk_24 = w->unk_D8;
    w->unk_00[0].unk_28 = w->unk_DC;
    w->unk_00[0].unk_30 = w->unk_D4 - 0x1000;
    w->unk_00[0].unk_34 = w->unk_D8;
    w->unk_00[0].unk_38 = w->unk_D4 + 0x600;
    w->unk_00[0].unk_3C = w->unk_D8 + 0x700;
    w->unk_00[0].unk_48 = 0x60;
    w->unk_00[0].unk_52 = 0x60;
    w->unk_00[1].unk_20 = w->unk_D4 + 0x1200;
    w->unk_00[1].unk_24 = w->unk_D8;
    w->unk_00[1].unk_28 = w->unk_DC;
    w->unk_00[1].unk_38 = w->unk_D4 + 0x1200;
    w->unk_00[1].unk_3C = w->unk_D8;
    w->unk_00[1].unk_30 = w->unk_D4 - 0x100;
    w->unk_00[1].unk_34 = w->unk_D8 - 0x700;
    w->unk_00[1].unk_48 = 0xE0;
    w->unk_00[1].unk_52 = 0x60;
    func_080D206C(&w->unk_00[0]);
    func_080D206C(&w->unk_00[1]);
}

void func_080D2190(PooBflyPart* p) {
    if (p->unk_52 != 0) {
        ApproachValue(&p->unk_20, p->unk_40, p->unk_52);
        ApproachValue(&p->unk_24, p->unk_44, p->unk_52);
        p->unk_52--;
    } else {
        p->unk_52 = 0x60;
        p->unk_48 += 0x80;
        if ((s8)p->unk_48 >= 0) {
            p->unk_40 = p->unk_38;
            p->unk_44 = p->unk_3C;
        } else {
            p->unk_40 = p->unk_30;
            p->unk_44 = p->unk_34;
        }
    }
    p->gfx = AnimUpdate(p->anim);
}

u8 task_poo_butterfly_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[0]);
    func_080D2190(&w->unk_00[1]);
    return 1;
}

u8 func_080D220C(PooBflyPart* p, void* pal) {
    s16 x;
    s16 y;
    s32 pr;

    x = (p->unk_20 >> 8) - gUnk_0203C40C;
    y = (p->unk_24 >> 8) + (p->unk_28 >> 8) - gUnk_0203C3F8;
    if (x < -8 || x > 248 || y < -8 || y > 168) {
        return 0;
    }
    pr = p->unk_50 != 0 ? 0x801 : 0x800;
    func_080D2034(p);
    DrawSprite(x, y, p->gfx, p->tiles, pal, 0, pr, -0x1004 - (p->unk_24 >> 8) * 4);
    return 1;
}

void task_poo_butterfly_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[0], w->palette);
    func_080D220C(&w->unk_00[1], w->palette);
}

void task_poo_butterfly_3(PooButterflyWork* w) {
    ReleaseObjTiles(w->unk_00[0].tiles);
    ReleaseObjTiles(w->unk_00[1].tiles);
    ReleaseObjPalette(w->palette);
}

u8 task_poo_butterflyRight_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[1]);
    return 1;
}

void task_poo_butterflyRight_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[1], w->palette);
}

u8 task_poo_butterflyLeft_1(PooButterflyWork* w) {
    func_080D2190(&w->unk_00[0]);
    return 1;
}

void task_poo_butterflyLeft_2(PooButterflyWork* w) {
    func_080D220C(&w->unk_00[0], w->palette);
}

void task_poo_mapbee_0(PooMapBeeWork* w, PooPos* p) {
    w->unk_24 = p->x;
    w->unk_28 = p->y;
    w->unk_2C = 0;
    w->tiles = AllocObjTiles(GetMaxSpriteTileBytes(gUnk_09EF6158, 1), gUnk_097606E8);
    w->palette = LoadObjPalette(gUnk_09849E38, 0x20);
    AnimInit(w->anim, gUnk_09EF6200, gUnk_09EF6158);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    w->unk_34 = 1;
    w->state = 0;
    m4aSongNumStart(0x182);
}

u8 task_poo_mapbee_1(PooMapBeeWork* w) {
    if (w->unk_34 == 0) {
        return 0;
    }

    switch (w->state) {
    case 0:
        if (AnimIsFinished(w->anim) != 0) {
            AnimStart(w->anim, 1, 1);
            w->state = 1;
        }
        break;
    case 1:
        w->unk_2C -= 0xCC;
        break;
    }
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_mapbee_2(PooMapBeeWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 8, 8, 8, 8) != 0) {
        w->unk_34 = 0;
    } else {
        func_080C7CB0(1);
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_28 >> 8) * 4);
    }
}

void task_poo_mapbee_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);

    if (func_080D1050() == 0) {
        m4aSongNumStop(0x182);
    }
}

void task_poo_mapbeeborn_0(PooMapBornWork* w, PooPos* p) {
    w->pos = *p;
    w->pos.z = 0;
    w->x = p->x + 0x400;
    w->y = p->y + 0x1800;
    w->unk_08 = 0;
    ColliderSetPosition(w->unk_20, w->x, w->y, 0);
    w->unk_98 = 0;
    w->unk_7C = 0;
    w->unk_99 = 0;
    TaskPoolInit(&w->tasks, 1);
    w->task = 0;
}

u8 task_poo_mapbeeborn_1(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        if ((w->flags & 2) != 0) {
            if (IsTaskActive(w->task) == 0 && w->unk_99 != 0) {
                w->unk_99 = 0;
                w->task = TaskCreate(&w->tasks, &gTaskDescPooMapbee, &w->pos);
            }
        } else {
            w->unk_99 = 1;
        }
    }
    return 1;
}

void task_poo_mapbeeborn_2(PooMapBornWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 0, 24, 0, 32) != 0) {
        if (w->unk_98 != 0) {
            w->unk_98 = 0;
            ColliderUnregister(w->unk_20);
            w->unk_99 = 0;
#ifdef VERSION_EU
            if (IsTaskActive(w->task)) {
                func_08000DE8(&w->tasks, w->task);
            }
#endif
        }
    } else {
        if (w->unk_98 == 0) {
            ColliderInit(w->unk_20, 6, 28, 0);
            w->unk_98 = 1;
            w->unk_99 = 1;
        }
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_mapbeeborn_3(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        ColliderUnregister(w->unk_20);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_mapbutterfly_0(PooMapButterflyWork* w, PooPos* p) {
    w->unk_24 = p->x;
    w->unk_28 = p->y;
    w->unk_2C = 0;
    w->tiles = AllocObjTiles(0x40, gUnk_09760986);
    w->palette = LoadObjPalette(gUnk_09849E58, 0x20);
    AnimInit(w->anim, gUnk_09EF6298, gUnk_09EF6208);
    AnimStart(w->anim, 0, 0);
    w->gfx = AnimGetGfx(w->anim);
    w->unk_34 = 1;
}

u8 task_poo_mapbutterfly_1(PooMapButterflyWork* w) {
    if (w->unk_34 == 0) {
        return 0;
    }
    w->unk_2C -= 0x80;
    w->gfx = AnimUpdate(w->anim);
    return 1;
}

void task_poo_mapbutterfly_2(PooMapButterflyWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_24 >> 8) - gUnk_0203C40C;
    y = (w->unk_28 >> 8) + (w->unk_2C >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 8, 8, 8, 8) != 0) {
        w->unk_34 = 0;
    } else {
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_28 >> 8) * 4);
    }
}

void task_poo_mapbutterfly_3(PooObjWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
}

void task_poo_mapbutterflyborn_0(PooMapBornWork* w, PooPos* p) {
    w->pos = *p;
    w->pos.z = 0;
    w->x = p->x + 0x1000;
    w->y = p->y + 0x1800;
    w->unk_08 = 0;
    ColliderSetPosition(w->unk_20, w->x, w->y, 0);
    w->unk_98 = 0;
    w->unk_7C = 0;
    w->unk_99 = 0;
    TaskPoolInit(&w->tasks, 1);
    w->task = 0;
}

u8 task_poo_mapbutterflyborn_1(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        if ((w->flags & 2) != 0) {
            if (IsTaskActive(w->task) == 0 && w->unk_99 != 0) {
                w->unk_99 = 0;
                w->task = TaskCreate(&w->tasks, &gTaskDescPooMapbutterfly, &w->pos);
            }
        } else {
            w->unk_99 = 1;
        }
    }
    return 1;
}

void task_poo_mapbutterflyborn_2(PooMapBornWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 0, 24, 0, 32) != 0) {
        if (w->unk_98 != 0) {
            w->unk_98 = 0;
            ColliderUnregister(w->unk_20);
            w->unk_99 = 0;
        }
    } else {
        if (w->unk_98 == 0) {
            ColliderInit(w->unk_20, 6, 40, 0);
            w->unk_98 = 1;
            w->unk_99 = 1;
        }
        TaskPoolUpdate(&w->tasks);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_mapbutterflyborn_3(PooMapBornWork* w) {
    if (w->unk_98 != 0) {
        ColliderUnregister(w->unk_20);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_rabbitAfterEvent_0(PooRabbitAfterEventWork* w) {
    w->x = 0xA9B00;
    w->y = 0x57200;
    w->z = 0;
    w->unk_30 = 0;
    w->palette = 0;
    w->unk_A4 = GetMaxSpriteTileBytes(gUnk_09EF5EA8, 15);
    AnimInit(w->anim, gUnk_09EF5EE4, gUnk_09EF5EA8);
    AnimStart(w->anim, 0, 1);
    w->gfx = AnimGetGfx(w->anim);
    TaskPoolInit(&w->tasks, 1);
    CreatePooShadowscaleTask(&w->tasks, &w->x, 0x100);
    ColliderSetPosition(w->collider, w->x, w->y, w->z);
    w->unk_A6 = func_080D2E28(w->collider, 60);
    func_080D2E70(w->unk_A6, 0);
}

u8 task_poo_rabbitAfterEvent_1(PooRabbitAfterEventWork* w) {
    if (w->palette != 0) {
        if (ColliderIsTouchingType(w->collider, 9) != 0) {
            gUnk_0203C3F0 = 5;
        }
    }
    return 1;
}

void task_poo_rabbitAfterEvent_2(PooRabbitAfterEventWork* w) {
    s16 x;
    s16 y;

    x = (w->x >> 8) - gUnk_0203C40C;
    y = (w->y >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 48, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            ColliderUnregister(w->collider);
            func_080D2E70(w->unk_A6, 0);
            w->palette = 0;
        }
    } else {
        w->gfx = AnimUpdate(w->anim);
        TaskPoolUpdate(&w->tasks);

        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849CB8, 0x40);
            w->tiles = AllocObjTiles(w->unk_A4, gUnk_0974FB26);
            ColliderInit(w->collider, 10, 4, 48);
            func_080D2E70(w->unk_A6, 1);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x801, -0x1004 - (w->y >> 8) * 4);
        TaskPoolDraw(&w->tasks);
    }
}

void task_poo_rabbitAfterEvent_3(PooRabbitAfterEventWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
        ColliderUnregister(w->collider);
    }
    TaskPoolDestroy(&w->tasks);
}

void task_poo_cabbageAfterEvent_0(PooCabbageAfterEventWork* w) {
    w->unk_0C = 0xAB300;
    w->unk_10 = 0x57100;
    w->unk_14 = 0;
    w->unk_18 = 0;
    w->palette = 0;
    w->unk_1C = GetMaxSpriteTileBytes(gUnk_09EF602C, 13);
    w->gfx = gUnk_09756D16;
}

u8 task_poo_cabbageAfterEvent_1(PooCabbageAfterEventWork* w) {
    *(vu32*)&w->palette;
    return 1;
}

void task_poo_cabbageAfterEvent_2(PooCabbageAfterEventWork* w) {
    s16 x;
    s16 y;

    x = (w->unk_0C >> 8) - gUnk_0203C40C;
    y = (w->unk_10 >> 8) - gUnk_0203C3F8;
    if (IsRectOutsideScreen(x, y, 48, 8, 16, 16) != 0) {
        if (w->palette != 0) {
            ReleaseObjTiles(w->tiles);
            ReleaseObjPalette(w->palette);
            w->palette = 0;
        }
    } else {
        if (w->palette == 0) {
            w->palette = LoadObjPalette(gUnk_09849DB8, 0x20);
            w->tiles = AllocObjTiles(w->unk_1C, gUnk_09756E28);
        }
        DrawSprite(x, y, w->gfx, w->tiles, w->palette, 0, 0x800, -0x1004 - (w->unk_10 >> 8) * 4);
    }
}

void task_poo_cabbageAfterEvent_3(PooObjWork* w) {
    if (w->palette != 0) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette);
    }
}

void func_080D2BE0(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPooState.unk_2C[i] = 0;
    }
}

void func_080D2BF8(u16 a) {
    u32 i;
    u32 s;

    i = a / 32;
    s = a % 32;
    gPooState.unk_2C[i] |= 1 << s;
}

u8 func_080D2C1C(u16 a) {
    u32 i;
    u32 s;

    i = a / 32;
    s = a % 32;
    if ((gPooState.unk_2C[i] & (1 << s)) != 0) {
        return 1;
    }
    return 0;
}

void func_080D2C48(void) {
    func_080D2BE0();
    gPooState.unk_28 = 0;
    gPooState.unk_3C = 3;
    gPooState.unk_3E = 0x73B;
    gUnk_0203C3E4 = 3;
    gUnk_0203C3E0 = 0x73B;
}

void func_080D2C78(void) {
    gPooState.unk_24 = 0;
    func_080D2C48();
}

void func_080D2C8C(PooPos* p, s32 b) {
    gPooState.pos = *p;
    gPooState.unk_20 = b;
}

void func_080D2CA8(PooPos* p, s32* b) {
    *p = gPooState.pos;
    *b = gPooState.unk_20;
}

void func_080D2CC4(u16 a, u16 b) {
    gPooState.unk_3C = a;
    gPooState.unk_3E = b;
}

void func_080D2CD0(u16* a, u16* b) {
    *a = gPooState.unk_3C;
    *b = gPooState.unk_3E;
}

void func_080D2CE0(s16 a, s16 b) {
    gPooState.unk_40 = a;
    gPooState.unk_42 = b;
}

void func_080D2CF4(u16* a, u16* b) {
    *a = gPooState.unk_40;
    *b = gPooState.unk_42;
}

void SetPooStatePos2(PooPos* p) {
    gPooState.pos2 = *p;
}

void GetPooStatePos2(PooPos* p) {
    *p = gPooState.pos2;
}

void func_080D2D3C(s32 a) {
    gPooState.unk_28 |= 1 << a;
}

u8 func_080D2D50(s32 a) {
    if (((gPooState.unk_28 >> a) & 1) != 0) {
        return 1;
    }
    return 0;
}

void func_080D2D6C(s32 a) {
    gPooState.unk_24 |= 1 << a;
}

void func_080D2D80(s32 a) {
    gPooState.unk_24 &= ~(1 << a);
}

u8 func_080D2D94(s32 a) {
    if ((gPooState.unk_24 & (1 << a)) != 0) {
        return 1;
    }
    return 0;
}

void GetPooState(void* p) {
    memcpy(p, &gPooState, sizeof(gPooState));
}

void SetPooState(const void* p) {
    memcpy(&gPooState, p, sizeof(gPooState));
}

u8 func_080D2DD8(void) {
    s32 v[6];
    u32 i;
    s32 n;

    memcpy(v, gUnk_096FDA74, sizeof(v));

    if (func_080D2D94(1) != 0) {
        return 1;
    }
    n = 0;

    for (i = 0; i < 6; i++) {
        if (func_080D2D50(v[i]) != 0) {
            n++;
        }
    }

    if (n <= 4) {
        return 0;
    }
    return 1;
}

u16 func_080D2E28(void* a, u16 b) {
    if (((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_30 > 5) {
        return 0xFFFF;
    }
    ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_30].unk_00 = a;
    ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_30].unk_04 = b;
    ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_30].unk_06 = 1;
    return ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_30++;
}

void func_080D2E70(u16 a, u8 b) {
    ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[a].unk_06 = b;
}

void func_080D2E84(void) {
    EwramFree(gUnk_0203C4B4);
}

void func_080D2E98(void) {
    void** state = &gUnk_0203C4B4;

    *state = EwramAlloc(0x34);
    ((PoohInteractionRegistry*)*state)->unk_30 = 0;
    func_080D2F10(0);
}

u16 func_080D2EB8(void) {
    s32 i;

    for (i = 0; i < ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_30; i++) {
        if (((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[i].unk_04 == 0x3B && ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_32 != 0) {
            continue;
        }

        if (((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[i].unk_06 == 0) {
            continue;
        }

        if (func_080C76B0(((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[i].unk_00) == 0) {
            continue;
        }
        return ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_00[i].unk_04;
    }
#ifdef VERSION_EU
    return 0xB3;
#else
    return 0xB4;
#endif
}

void func_080D2F10(u8 a) {
    ((PoohInteractionRegistry*)gUnk_0203C4B4)->unk_32 = a;
}

void func_080D2F20(void) {
    while ((REG_DISPSTAT & 2) == 0) {
    }
    REG_BG3CNT &= 0xFFFC;
    REG_BG3CNT |= 2;
    REG_BG1HOFS = 0;
}

void func_080D2F64(void) {
    u32 i;
    u16 j;
    u16 k;

    gUnk_0203C530 = EwramAlloc(0x4000);
    gUnk_0203C504 = EwramAlloc(0x4000);

    for (i = 0; i < 0x2000; i++) {
        gUnk_0203C530[i] = 0;
        gUnk_0203C504[i] = 0;
    }

    for (j = 0; j < 4; j++) {
        for (k = 0; k < 2; k++) {
            gUnk_0203C4C0[j * 2 + k] = gUnk_0203C530 + (j * 2 + k) * 0x400;
            gUnk_0203C510[j * 2 + k] = gUnk_0203C504 + (j * 2 + k) * 0x400;
        }
    }
}

void func_080D3008(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        FadeSetPaletteExcluded(i, 1);
    }
    FadeSetPaletteExcluded(10, 0);
    FadeToAmount(0, 16, 16);
}

void func_080D3034(s16 a) {
    SetBlendAlpha(a, 16 - a);
}

void func_080D3050(void) {
    PooPalStep t[9];

    memcpy(t, gUnk_096FDB40, sizeof(t));
    gUnk_02034E38++;
    if (gUnk_02034E38 < t[gUnk_02034E3A].unk_02) {
        return;
    }
    gUnk_02034E38 = 0;
    gUnk_02034E3A++;
    if (t[gUnk_02034E3A].unk_00 == 0xFF) {
        gUnk_02034E3A = 0;
    }
    LoadPalette(&gUnk_0984A138[t[gUnk_02034E3A].unk_00 * 0x20], (void*)0x05000040, 0x20);
}

void func_080D30C8(void) {
    RequestDma3Copy(gUnk_096FDA8C[gGameState.world].map, (u8*)GetBgScreenBase(2) + 0x200, 0x300);
    RequestDma3Copy(gUnk_096FDA8C[gGameState.world].tiles, (u8*)GetBgCharBase(2) + 0x2000, 0x2000);
    LoadPalette(gUnk_096FDA8C[gGameState.world].palette, (void*)0x05000140, 0x20);
}

void func_080D313C(void) {
    u8* src;
    void* dst;

    dst = (u8*)GetBgCharBase(2) + 0x20;

    if ((gGameState.flags & 8) != 0) {
#ifdef VERSION_EU
        src = gUnkEu_09F800B8[gLanguage] + gGameState.floor * 0x140;
#else
        src = &gUnk_097B8258[gGameState.floor * 0x140];
#endif
    } else {
#ifdef VERSION_EU
        src = gUnkEu_09F800A4[gLanguage] + gGameState.floor * 0x140;
#else
        src = &gUnk_097B7218[gGameState.floor * 0x140];
#endif
    }
    RequestDma3Copy(src, dst, 0x140);
    dst = (u8*)GetBgScreenBase(2) + 0x480;
    src = gUnk_0983BC18;
    RequestDma3Copy(src, dst, 10);
    dst = (u8*)GetBgScreenBase(2) + 0x4C0;
    src += 0x40;
    RequestDma3Copy(src, dst, 10);
}

const char gTaskNamePooPooh[] = "task_poo_pooh";

const PooMapBgDesc gUnk_096FC6E0 = {
    gUnk_097A2ED8, 32768, 0, gUnk_09849898, 512, 0, gUnk_097AAED8, 16032, 16, 9
};

const PooSpawn gPooSpawns[85] = {
    { 130816, 99328, &gTaskDescPooHoney },
    { 223232, 130304, &gTaskDescPooTrapballoon },
    { 229888, 153088, &gTaskDescPooTrapballoon },
    { 251392, 143104, &gTaskDescPooPitAndButterfly },
    { 242688, 159488, &gTaskDescPooTrap },
    { 263936, 162816, &gTaskDescPooHoney },
    { 279040, 175104, &gTaskDescPooTrap },
    { 304896, 167424, &gTaskDescPooTrap },
    { 301824, 182784, &gTaskDescPooTrapballoon },
    { 444672, 238848, &gTaskDescPooTigerstump },
    { 411904, 238848, &gTaskDescPooTigerstump },
    { 428288, 247040, &gTaskDescPooTigerstump },
    { 428288, 230656, &gTaskDescPooTigerstump },
    { 440576, 231680, &gTaskDescPooTiBoard },
    { 407040, 218624, &gTaskDescPooHoney },
    { 463104, 266496, &gTaskDescPooTrap },
    { 476672, 251136, &gTaskDescPooPitAndButterfly },
    { 502272, 262912, &gTaskDescPooTrap },
    { 489216, 277504, &gTaskDescPooPitAndButterfly },
    { 484096, 265472, &gTaskDescPooTrapballoon },
    { 518400, 271616, &gTaskDescPooHoney },
    { 648960, 335616, &gTaskDescPooHoney },
    { 602624, 320256, &gTaskDescPooPoohstump },
    { 584192, 320256, &gTaskDescPooPoohstump },
    { 593408, 315648, &gTaskDescPooPoohstump },
    { 593408, 324864, &gTaskDescPooPoohstump },
    { 602624, 315136, &gTaskDescPooTiBoard },
    { 585984, 305920, &gTaskDescPooPoohstump },
    { 573440, 329472, &gTaskDescPooPoohstump },
    { 566016, 325376, &gTaskDescPooPoohstump },
    { 617728, 319488, &gTaskDescPooPoohstump },
    { 282624, 150272, &gTaskDescPooLeaf },
    { 512000, 285440, &gTaskDescPooLeaf },
    { 159744, 102400, &gTaskDescPooTanpopo },
    { 194560, 114688, &gTaskDescPooTanpopo },
    { 200704, 118784, &gTaskDescPooButterfly },
    { 167936, 120832, &gTaskDescPooTanpopo },
    { 174080, 124928, &gTaskDescPooButterflyRight },
    { 198656, 133120, &gTaskDescPooTanpopo },
    { 323584, 167936, &gTaskDescPooTanpopo },
    { 313344, 180224, &gTaskDescPooTanpopo },
    { 323584, 192512, &gTaskDescPooTanpopo },
    { 333824, 182272, &gTaskDescPooTanpopo },
    { 339968, 186368, &gTaskDescPooButterflyRight },
    { 350208, 182272, &gTaskDescPooTanpopo },
    { 337920, 190464, &gTaskDescPooTanpopo },
    { 358400, 190464, &gTaskDescPooTanpopo },
    { 301056, 196608, &gTaskDescPooTanpopo },
    { 325632, 212992, &gTaskDescPooTanpopo },
    { 350208, 198656, &gTaskDescPooTanpopo },
    { 374784, 200704, &gTaskDescPooTanpopo },
    { 362496, 204800, &gTaskDescPooTanpopo },
    { 382976, 210944, &gTaskDescPooTanpopo },
    { 370688, 212992, &gTaskDescPooTanpopo },
    { 391168, 219136, &gTaskDescPooTanpopo },
    { 374784, 221184, &gTaskDescPooTanpopo },
    { 358400, 225280, &gTaskDescPooTanpopo },
    { 387072, 229376, &gTaskDescPooTanpopo },
    { 374784, 233472, &gTaskDescPooTanpopo },
    { 391168, 241664, &gTaskDescPooTanpopo },
    { 395264, 204800, &gTaskDescPooTanpopo },
    { 405504, 221184, &gTaskDescPooTanpopo },
    { 403456, 247808, &gTaskDescPooTanpopo },
    { 313344, 200704, &gTaskDescPooTanpopo },
    { 325632, 202752, &gTaskDescPooTanpopo },
    { 337920, 198656, &gTaskDescPooTanpopo },
    { 344064, 206848, &gTaskDescPooTanpopo },
    { 350208, 210944, &gTaskDescPooButterflyLeft },
    { 356352, 212992, &gTaskDescPooTanpopo },
    { 342016, 215040, &gTaskDescPooTanpopo },
    { 79872, 38912, &gTaskDescPooMapbeeborn },
    { 153600, 75776, &gTaskDescPooMapbeeborn },
    { 559104, 278528, &gTaskDescPooMapbeeborn },
    { 632832, 315392, &gTaskDescPooMapbeeborn },
    { 706560, 352256, &gTaskDescPooMapbeeborn },
    { 780288, 389120, &gTaskDescPooMapbeeborn },
    { 131072, 63488, &gTaskDescPooMapbutterflyborn },
    { 278528, 137216, &gTaskDescPooMapbutterflyborn },
    { 352256, 174080, &gTaskDescPooMapbutterflyborn },
    { 536576, 266240, &gTaskDescPooMapbutterflyborn },
    { 610304, 303104, &gTaskDescPooMapbutterflyborn },
    { 684032, 339968, &gTaskDescPooMapbutterflyborn },
    { 757760, 376832, &gTaskDescPooMapbutterflyborn },
    { 794624, 395264, &gTaskDescPooMapbutterflyborn },
    { 831488, 413696, &gTaskDescPooMapbutterflyborn },
};

const PooStumpDesc gPooStumpDescs[12] = {
    { 611584, 339200, 4, 0 },
    { 619264, 343296, 3, 0 },
    { 626944, 347392, 2, 0 },
    { 634624, 351488, 1, 0 },
    { 642304, 355584, 2, 0 },
    { 649984, 359680, 3, 0 },
    { 657664, 363776, 4, 0 },
    { 763904, 389632, 0, 0 },
    { 759552, 398336, 0, 0 },
    { 754688, 405760, 0, 0 },
    { 747264, 411904, 0, 0 },
    { 739072, 416768, 0, 0 },
};

const PooTileDesc gPooTileDescs[80] = {
    { 106496, 49152, 0x3 },
    { 180224, 86016, 0x3 },
    { 327680, 159744, 0x3 },
    { 512000, 251904, 0x3 },
    { 585728, 288768, 0x3 },
    { 659456, 325632, 0x3 },
    { 770048, 380928, 0x3 },
    { 217088, 104448, 0x5 },
    { 253952, 122880, 0x5 },
    { 290816, 141312, 0x5 },
    { 364544, 178176, 0x5 },
    { 401408, 196608, 0x5 },
    { 438272, 215040, 0x5 },
    { 475136, 233472, 0x5 },
    { 548864, 270336, 0x5 },
    { 622592, 307200, 0x5 },
    { 696320, 344064, 0x5 },
    { 806912, 399360, 0x5 },
    { 131072, 63488, 0x8 },
    { 204800, 100352, 0x8 },
    { 278528, 137216, 0x8 },
    { 389120, 192512, 0x8 },
    { 352256, 174080, 0x8 },
    { 462848, 229376, 0x8 },
    { 536576, 266240, 0x8 },
    { 610304, 303104, 0x8 },
    { 684032, 339968, 0x8 },
    { 757760, 376832, 0x8 },
    { 794624, 395264, 0x8 },
    { 831488, 413696, 0x9 },
    { 94208, 45056, 0x4 },
    { 167936, 81920, 0x4 },
    { 241664, 118784, 0x4 },
    { 315392, 155648, 0x4 },
    { 425984, 210944, 0x4 },
    { 499712, 247808, 0x4 },
    { 647168, 321536, 0x4 },
    { 720896, 358400, 0x4 },
    { 116736, 57344, 0x1 },
    { 227328, 112640, 0x1 },
    { 301056, 149504, 0x1 },
    { 337920, 167936, 0x1 },
    { 374784, 186368, 0x1 },
    { 485376, 241664, 0x1 },
    { 522240, 260096, 0x1 },
    { 595968, 296960, 0x1 },
    { 669696, 333824, 0x1 },
    { 743424, 370688, 0x1 },
    { 817152, 407552, 0x1 },
    { 120832, 63488, 0x0 },
    { 194560, 100352, 0x0 },
    { 305152, 155648, 0x0 },
    { 342016, 174080, 0x0 },
    { 378880, 192512, 0x0 },
    { 526336, 266240, 0x0 },
    { 600064, 303104, 0x0 },
    { 673792, 339968, 0x0 },
    { 747520, 376832, 0x0 },
    { 153600, 75776, 0x6 },
    { 190464, 94208, 0x6 },
    { 264192, 131072, 0x6 },
    { 411648, 204800, 0x6 },
    { 448512, 223232, 0x6 },
    { 559104, 278528, 0x6 },
    { 632832, 315392, 0x6 },
    { 706560, 352256, 0x6 },
    { 780288, 389120, 0x6 },
    { 79872, 38912, 0x7 },
    { 83968, 45056, 0x2 },
    { 157696, 81920, 0x2 },
    { 231424, 118784, 0x2 },
    { 268288, 137216, 0x2 },
    { 415744, 210944, 0x2 },
    { 452608, 229376, 0x2 },
    { 489472, 247808, 0x2 },
    { 563200, 284672, 0x2 },
    { 636928, 321536, 0x2 },
    { 710656, 358400, 0x2 },
    { 784384, 395264, 0x2 },
    { 821248, 413696, 0x2 },
};

TaskDesc gTaskDescPooPooh = {
    gTaskNamePooPooh,
    (void (*)(void*, void*))task_poo_pooh_0,
    task_poo_pooh_1,
    (void (*)(void*))task_poo_pooh_2,
    (void (*)(void*))task_poo_pooh_3,
    0xFC,
};

const char gTaskNamePooMap[] = "task_poo_map";

const PooAnimDesc gUnk_096FCF54[11][5] = {
    {
        { gUnk_09EDED34, gUnk_09EDED38, gUnk_088DBD58, 0, 0 },
        { gUnk_09EDE8CC, gUnk_09EDE918, gUnk_088B6560, 0, 0 },
        { gUnk_09EDE99C, gUnk_09EDE9CC, gUnk_088BF162, 0, 0 },
        { gUnk_09EDEA68, gUnk_09EDEA6C, gUnk_088C56C6, 0, 0 },
        { gUnk_09EDEB0C, gUnk_09EDEB40, gUnk_088CBAA2, 0, 0 },
    },
    {
        { gUnk_09EDED3C, gUnk_09EDED5C, gUnk_088DC192, 0, 0 },
        { gUnk_09EDE920, gUnk_09EDE940, gUnk_088BAC36, 0, 0 },
        { gUnk_09EDE9EC, gUnk_09EDEA0C, gUnk_088C1388, 0, 0 },
        { gUnk_09EDEA70, gUnk_09EDEA90, gUnk_088C5AAA, 0, 0 },
        { gUnk_09EDEB68, gUnk_09EDEB88, gUnk_088CE0C2, 0, 0 },
    },
    {
        { gUnk_09EDED60, gUnk_09EDED80, gUnk_088DDAF6, 0, 0 },
        { gUnk_09EDE944, gUnk_09EDE964, gUnk_088BC6DE, 0, 0 },
        { gUnk_09EDEA10, gUnk_09EDEA30, gUnk_088C2D72, 0, 0 },
        { gUnk_09EDEA94, gUnk_09EDEAB4, gUnk_088C75A0, 0, 0 },
        { gUnk_09EDEB8C, gUnk_09EDEBAC, gUnk_088CF9CE, 0, 0 },
    },
    {
        { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 0, 0 },
        { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 0, 0 },
        { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 0, 0 },
        { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 0, 0 },
        { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 0, 0 },
    },
    {
        { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 1, 0 },
        { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 1, 0 },
        { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 1, 0 },
        { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 1, 0 },
        { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 1, 0 },
    },
    {
        { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 2, 0 },
        { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 2, 0 },
        { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 2, 0 },
        { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 2, 0 },
        { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 2, 0 },
    },
    {
        { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 3, 0 },
        { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 3, 0 },
        { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 3, 0 },
        { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 3, 0 },
        { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 3, 0 },
    },
    {
        { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 4, 0 },
        { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 4, 0 },
        { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 4, 0 },
        { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 4, 0 },
        { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 4, 0 },
    },
    {
        { gUnk_09EDEC38, gUnk_09EDEC44, gUnk_088D5AB0, 2, 0 },
        { gUnk_09EDECA8, gUnk_09EDECB4, gUnk_088D7CCE, 2, 0 },
        { gUnk_09EDEC88, gUnk_09EDEC9C, gUnk_088D702C, 2, 0 },
        { gUnk_09EDEC50, gUnk_09EDEC5C, gUnk_088D5E98, 2, 0 },
        { gUnk_09EDEC68, gUnk_09EDEC7C, gUnk_088D6282, 2, 0 },
    },
    {
        { gUnk_09EDF360, gUnk_09EDF370, gUnk_0891DFC4, 0, 0 },
        { gUnk_09EDF34C, gUnk_09EDF35C, gUnk_0891D344, 0, 0 },
        { gUnk_09EDF308, gUnk_09EDF31C, gUnk_0891A166, 0, 0 },
        { gUnk_09EDF338, gUnk_09EDF348, gUnk_0891C1E8, 0, 0 },
        { gUnk_09EDF320, gUnk_09EDF334, gUnk_0891B26C, 0, 0 },
    },
    {
        { gUnk_09EDF090, gUnk_09EDF0A8, gUnk_088FB5F2, 0, 0 },
        { gUnk_09EDF004, gUnk_09EDF01C, gUnk_088F5298, 0, 0 },
        { gUnk_09EDF020, gUnk_09EDF03C, gUnk_088F695C, 0, 0 },
        { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 0, 0 },
        { gUnk_09EDF074, gUnk_09EDF08C, gUnk_088FA0DA, 0, 0 },
    },
};

const u16 gUnk_096FD2C4[8] = { 109, 110, 111, 112, 133, 133, 134, 0 };

TaskDesc gTaskDescPooMap = {
    gTaskNamePooMap,
    (void (*)(void*, void*))task_poo_map_0,
    task_poo_map_1,
    (void (*)(void*))task_poo_map_2,
    (void (*)(void*))task_poo_map_3,
    0x18,
};

const u16* gUnk_09EF4208[144] = {
    gUnk_09806D98,
    gUnk_09807598,
    gUnk_09808D98,
    gUnk_09809598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09807D98,
    gUnk_09808598,
    gUnk_09809D98,
    gUnk_0980A598,
    gUnk_0980BD98,
    gUnk_0980C598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0980AD98,
    gUnk_0980B598,
    gUnk_0980CD98,
    gUnk_0980D598,
    gUnk_0980ED98,
    gUnk_0980F598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0980DD98,
    gUnk_0980E598,
    gUnk_0980FD98,
    gUnk_09810598,
    gUnk_09811D98,
    gUnk_09812598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09810D98,
    gUnk_09811598,
    gUnk_09812D98,
    gUnk_09813598,
    gUnk_09814D98,
    gUnk_09815598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09813D98,
    gUnk_09814598,
    gUnk_09815D98,
    gUnk_09816598,
    gUnk_09817D98,
    gUnk_09818598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09816D98,
    gUnk_09817598,
    gUnk_09818D98,
    gUnk_09819598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09819D98,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
};

const u16* gUnk_09EF4448[144] = {
    gUnk_0981A598,
    gUnk_0981AD98,
    gUnk_0981CD98,
    gUnk_0981D598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981B598,
    gUnk_0981BD98,
    gUnk_0981DD98,
    gUnk_0981E598,
    gUnk_0981FD98,
    gUnk_09820598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_0981ED98,
    gUnk_0981F598,
    gUnk_09820D98,
    gUnk_09821598,
    gUnk_09822D98,
    gUnk_09823598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_09821D98,
    gUnk_09822598,
    gUnk_09823D98,
    gUnk_09824598,
    gUnk_09825D98,
    gUnk_09826598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_09824D98,
    gUnk_09825598,
    gUnk_09826D98,
    gUnk_09827598,
    gUnk_09828D98,
    gUnk_09829598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_09827D98,
    gUnk_09828598,
    gUnk_09829D98,
    gUnk_0982A598,
    gUnk_0982BD98,
    gUnk_0982C598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_0982AD98,
    gUnk_0982B598,
    gUnk_0982CD98,
    gUnk_0982D598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_0982DD98,
    gUnk_0982E598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_0981C598,
    gUnk_0981C598,
    gUnk_08125E24,
    gUnk_08125E24,
};

const u16* gUnk_09EF4688[144] = {
    gUnk_08125E24,
    gUnk_0982ED98,
    gUnk_0982F598,
    gUnk_0982FD98,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09830598,
    gUnk_09830D98,
    gUnk_09831598,
    gUnk_09831D98,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09832598,
    gUnk_09832D98,
    gUnk_09833598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09833D98,
    gUnk_09834598,
    gUnk_09834D98,
    gUnk_09835598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09835D98,
    gUnk_09836598,
    gUnk_09836D98,
    gUnk_09837598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09837D98,
    gUnk_09838598,
    gUnk_09838D98,
    gUnk_09839598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_09839D98,
    gUnk_0983A598,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
    gUnk_08125E24,
};

const char gTaskNamePooSora[] = "task_poo_sora";

TaskDesc gTaskDescPooSora = {
    gTaskNamePooSora,
    (void (*)(void*, void*))task_poo_sora_0,
    task_poo_sora_1,
    (void (*)(void*))task_poo_sora_2,
    (void (*)(void*))task_poo_sora_3,
    0xD0,
};

const char gTaskNamePooTrap[] = "task_poo_trap";

TaskDesc gTaskDescPooTrap = {
    gTaskNamePooTrap,
    (void (*)(void*, void*))task_poo_trap_0,
    task_poo_trap_1,
    (void (*)(void*))task_poo_trap_2,
    (void (*)(void*))task_poo_trap_3,
    0xB0,
};

const char gTaskNamePooPitAndButterfly[] = "task_poo_pitAndButterfly";

TaskDesc gTaskDescPooPitAndButterfly = {
    gTaskNamePooPitAndButterfly,
    (void (*)(void*, void*))task_poo_pitAndButterfly_0,
    task_poo_pitAndButterfly_1,
    (void (*)(void*))task_poo_pitAndButterfly_2,
    (void (*)(void*))task_poo_pitAndButterfly_3,
    0xB0,
};

const char gTaskNamePooBalloon[] = "task_poo_balloon";

TaskDesc gTaskDescPooBalloon = {
    gTaskNamePooBalloon,
    (void (*)(void*, void*))task_poo_balloon_0,
    task_poo_balloon_1,
    (void (*)(void*))task_poo_balloon_2,
    (void (*)(void*))task_poo_balloon_3,
    0x28,
};

const char gTaskNamePooShadow[] = "task_poo_shadow";

TaskDesc gTaskDescPooShadow = {
    gTaskNamePooShadow,
    (void (*)(void*, void*))task_poo_shadow_0,
    task_poo_shadow_1,
    (void (*)(void*))task_poo_shadow_2,
    (void (*)(void*))task_poo_shadow_3,
    0x14,
};

const char gTaskNamePooShadowdodai[] = "task_poo_shadowdodai";

TaskDesc gTaskDescPooShadowdodai = {
    gTaskNamePooShadowdodai,
    (void (*)(void*, void*))task_poo_shadowdodai_0,
    task_poo_shadowdodai_1,
    (void (*)(void*))task_poo_shadowdodai_2,
    (void (*)(void*))task_poo_shadowdodai_3,
    0x34,
};

const char gTaskNamePooShadowscale[] = "task_poo_shadowscale";

TaskDesc gTaskDescPooShadowscale = {
    gTaskNamePooShadowscale,
    (void (*)(void*, void*))task_poo_shadowscale_0,
    task_poo_shadowscale_1,
    (void (*)(void*))task_poo_shadowscale_2,
    (void (*)(void*))task_poo_shadowscale_3,
    0x34,
};

const char gTaskNamePooFreeballoon[] = "task_poo_freeballoon";

TaskDesc gTaskDescPooFreeballoon = {
    gTaskNamePooFreeballoon,
    (void (*)(void*, void*))task_poo_freeballoon_0,
    task_poo_freeballoon_1,
    (void (*)(void*))task_poo_freeballoon_2,
    (void (*)(void*))task_poo_freeballoon_3,
    0x98,
};

const char gTaskNamePooGauge[] = "task_poo_gauge";

TaskDesc gTaskDescPooGauge = {
    gTaskNamePooGauge,
    (void (*)(void*, void*))task_poo_gauge_0,
    task_poo_gauge_1,
    (void (*)(void*))task_poo_gauge_2,
    (void (*)(void*))task_poo_gauge_3,
    0x14,
};

const char gTaskNamePooTrapballoon[] = "task_poo_trapballoon";

TaskDesc gTaskDescPooTrapballoon = {
    gTaskNamePooTrapballoon,
    (void (*)(void*, void*))task_poo_trapballoon_0,
    task_poo_trapballoon_1,
    (void (*)(void*))task_poo_trapballoon_2,
    (void (*)(void*))task_poo_trapballoon_3,
    0xD0,
};

const char gTaskNamePooOwlballoon[] = "task_poo_owlballoon";

TaskDesc gTaskDescPooOwlballoon = {
    gTaskNamePooOwlballoon,
    (void (*)(void*, void*))task_poo_owlballoon_0,
    task_poo_owlballoon_1,
    (void (*)(void*))task_poo_owlballoon_2,
    (void (*)(void*))task_poo_owlballoon_3,
    0xCC,
};

const char gTaskNamePooHoney[] = "task_poo_honey";

const UnkStruct_096FE034Entry gUnk_096FD3C8[4] = { { 18, 0 }, { 18, 1 }, { 18, 2 }, { 18, 3 } };

const UnkStruct_096FE034Entry gUnk_096FD3D8[4] = { { 18, 0 }, { 18, 1 }, { 18, 2 }, { 18, 3 } };

const UnkStruct_096FE034 gUnk_096FD3E8 = { gUnk_096FD3C8, 4, 0, gUnk_097B4578, 0X2080, 0X0240, 0X0400, 0, 3 };

const UnkStruct_096FE034 gUnk_096FD400 = { gUnk_096FD3D8, 4, 0, gUnk_097B5418, 0X3880, 0X0240, 0X0400, 0, 3 };

TaskDesc gTaskDescPooHoney = {
    gTaskNamePooHoney,
    (void (*)(void*, void*))task_poo_honey_0,
    task_poo_honey_1,
    (void (*)(void*))task_poo_honey_2,
    (void (*)(void*))task_poo_honey_3,
    0x10C,
};

const char gTaskNamePooMapanime[] = "task_poo_mapanime";

TaskDesc gTaskDescPooMapanime = {
    gTaskNamePooMapanime,
    (void (*)(void*, void*))task_poo_mapanime_0,
    task_poo_mapanime_1,
    (void (*)(void*))task_poo_mapanime_2,
    (void (*)(void*))task_poo_mapanime_3,
    0x18,
};

const char gTaskNamePooPile[] = "task_poo_pile";

const s32 gUnk_096FD43C[6] = { 8, 0, 2, 4, 6, 7 };

TaskDesc gTaskDescPooPile = {
    gTaskNamePooPile,
    (void (*)(void*, void*))task_poo_pile_0,
    task_poo_pile_1,
    (void (*)(void*))task_poo_pile_2,
    (void (*)(void*))task_poo_pile_3,
    0xD0,
};

const char gTaskNamePooTigerstump[] = "task_poo_tigerstump";

TaskDesc gTaskDescPooTigerstump = {
    gTaskNamePooTigerstump,
    (void (*)(void*, void*))task_poo_tigerstump_0,
    task_poo_tigerstump_1,
    (void (*)(void*))task_poo_tigerstump_2,
    (void (*)(void*))task_poo_tigerstump_3,
    0x90,
};

const char gTaskNamePooPoohstump[] = "task_poo_poohstump";

const PooAnimDesc gUnk_096FD47C[4] = {
    { gUnk_09EF5CB0, gUnk_09EF5CAC, gUnk_09742FD8, 0, 0 },
    { gUnk_09EF5CB8, gUnk_09EF5CB4, gUnk_097430EC, 0, 0 },
    { gUnk_09EF5CDC, gUnk_09EF5CBC, gUnk_09743262, 0, 0 },
    { gUnk_09EF5D00, gUnk_09EF5CE0, gUnk_09743ADA, 0, 0 },
};

const PooGfxDesc gUnk_096FD4BC[4] = {
    { gUnk_09EF5CAC, 1, 0 },
    { gUnk_09EF5CB4, 1, 0 },
    { gUnk_09EF5CBC, 8, 0 },
    { gUnk_09EF5CE0, 8, 0 },
};

TaskDesc gTaskDescPooPoohstump = {
    gTaskNamePooPoohstump,
    (void (*)(void*, void*))task_poo_poohstump_0,
    task_poo_poohstump_1,
    (void (*)(void*))task_poo_poohstump_2,
    (void (*)(void*))task_poo_poohstump_3,
    0x90,
};

const char gTaskNamePooPiglet[] = "task_poo_piglet";

TaskDesc gTaskDescPooPiglet = {
    gTaskNamePooPiglet,
    (void (*)(void*, void*))task_poo_piglet_0,
    task_poo_piglet_1,
    (void (*)(void*))task_poo_piglet_2,
    (void (*)(void*))task_poo_piglet_3,
    0xB8,
};

const char gTaskNamePooEeyore[] = "task_poo_eeyore";

TaskDesc gTaskDescPooEeyore = {
    gTaskNamePooEeyore,
    (void (*)(void*, void*))task_poo_eeyore_0,
    task_poo_eeyore_1,
    (void (*)(void*))task_poo_eeyore_2,
    (void (*)(void*))task_poo_eeyore_3,
    0xB0,
};

const char gTaskNamePooOwl[] = "task_poo_owl";

const PooAnimDesc gUnk_096FD50C[7] = {
    { gUnk_09EF5E98, gUnk_09EF5E48, gUnk_0974C196, 0, 0 },
    { gUnk_09EF5E98, gUnk_09EF5E48, gUnk_0974C196, 1, 0 },
    { gUnk_09EF5E98, gUnk_09EF5E48, gUnk_0974C196, 2, 0 },
    { gUnk_09EF5EE4, gUnk_09EF5EA8, gUnk_0974FB26, 0, 0 },
    { gUnk_09EF5EE4, gUnk_09EF5EA8, gUnk_0974FB26, 2, 0 },
    { gUnk_09EF5EE4, gUnk_09EF5EA8, gUnk_0974FB26, 3, 0 },
    { gUnk_09EF5EE4, gUnk_09EF5EA8, gUnk_0974FB26, 4, 0 },
};

const PooGfxDesc gUnk_096FD57C[2] = {
    { gUnk_09EF5E48, 14, 0 },
    { gUnk_09EF5EA8, 15, 0 },
};

TaskDesc gTaskDescPooOwl = {
    gTaskNamePooOwl,
    (void (*)(void*, void*))task_poo_owl_0,
    task_poo_owl_1,
    (void (*)(void*))task_poo_owl_2,
    (void (*)(void*))task_poo_owl_3,
    0x50,
};

const char gTaskNamePooRabbit[] = "task_poo_rabbit";

const PooAnimDesc gUnk_096FD59C[4] = {
    { gUnk_09EF5B58, gUnk_09EF5B54, gUnk_0973700E, 0, 0 },
    { gUnk_09EF5B80, gUnk_09EF5B5C, gUnk_097373D6, 0, 0 },
    { gUnk_09EF5BA4, gUnk_09EF5B84, gUnk_0973900E, 0, 0 },
    { gUnk_09EF5BCC, gUnk_09EF5BAC, gUnk_0973AC64, 0, 0 },
};

const PooGfxDesc gUnk_096FD5DC[4] = {
    { gUnk_09EF5B54, 1, 0 },
    { gUnk_09EF5B5C, 9, 0 },
    { gUnk_09EF5B84, 8, 0 },
    { gUnk_09EF5BAC, 8, 0 },
};

const s32 gUnk_096FD5FC[8] = { 428288, 232704, 411904, 240896, 428288, 249088, 444672, 240896 };

const s32 gUnk_096FD61C[8] = { -512, -2560, -4096, -5120, -5120, -4096, -2560, -512 };

TaskDesc gTaskDescPooRabbit = {
    gTaskNamePooRabbit,
    (void (*)(void*, void*))task_poo_rabbit_0,
    task_poo_rabbit_1,
    (void (*)(void*))task_poo_rabbit_2,
    (void (*)(void*))task_poo_rabbit_3,
    0xB4,
};

const char gTaskNamePooTigger[] = "task_poo_tigger";

TaskDesc gTaskDescPooTigger = {
    gTaskNamePooTigger,
    (void (*)(void*, void*))task_poo_tigger_0,
    task_poo_tiggerroo_1,
    (void (*)(void*))task_poo_tiggerroo_2,
    (void (*)(void*))task_poo_tiggerroo_3,
    0xD4,
};

const char gTaskNamePooTiggerroo[] = "task_poo_tiggerroo";

TaskDesc gTaskDescPooTiggerroo = {
    gTaskNamePooTiggerroo,
    (void (*)(void*, void*))task_poo_tiggerroo_0,
    task_poo_tiggerroo_1,
    (void (*)(void*))task_poo_tiggerroo_2,
    (void (*)(void*))task_poo_tiggerroo_3,
    0xD4,
};

const char gTaskNamePooRoo[] = "task_poo_roo";

TaskDesc gTaskDescPooRoo = {
    gTaskNamePooRoo,
    (void (*)(void*, void*))task_poo_roo_0,
    task_poo_roo_1,
    (void (*)(void*))task_poo_roo_2,
    (void (*)(void*))task_poo_roo_3,
    0xBC,
};

const char gTaskNamePooRooFootmark[] = "task_poo_roo_footmark";

TaskDesc gTaskDescPooRooFootmark = {
    gTaskNamePooRooFootmark,
    (void (*)(void*, void*))task_poo_roo_footmark_0,
    task_poo_roo_footmark_1,
    (void (*)(void*))task_poo_roo_footmark_2,
    (void (*)(void*))task_poo_roo_footmark_3,
    0x3C,
};

const char gTaskNamePooLeaf[] = "task_poo_leaf";

TaskDesc gTaskDescPooLeaf = {
    gTaskNamePooLeaf,
    (void (*)(void*, void*))task_poo_leaf_0,
    task_poo_leaf_1,
    (void (*)(void*))task_poo_leaf_2,
    (void (*)(void*))task_poo_leaf_3,
    0x98,
};

const char gTaskNamePooTanpopo[] = "task_poo_tanpopo";

TaskDesc gTaskDescPooTanpopo = {
    gTaskNamePooTanpopo,
    (void (*)(void*, void*))task_poo_tanpopo_0,
    task_poo_tanpopo_1,
    (void (*)(void*))task_poo_tanpopo_2,
    (void (*)(void*))task_poo_tanpopo_3,
    0xB8,
};

const char gTaskNamePooTiBoard[] = "task_poo_ti_board";

TaskDesc gTaskDescPooTiBoard = {
    gTaskNamePooTiBoard,
    (void (*)(void*, void*))task_poo_ti_board_0,
    task_poo_ti_board_1,
    (void (*)(void*))task_poo_ti_board_2,
    (void (*)(void*))task_poo_ti_board_3,
    0x78,
};

const char gTaskNamePooEeyoretail[] = "task_poo_eeyoretail";

TaskDesc gTaskDescPooEeyoretail = {
    gTaskNamePooEeyoretail,
    (void (*)(void*, void*))task_poo_eeyoretail_0,
    task_poo_eeyoretail_1,
    (void (*)(void*))task_poo_eeyoretail_2,
    (void (*)(void*))task_poo_eeyoretail_3,
    0x38,
};

const char gTaskNamePooHoneycomb[] = "task_poo_honeycomb";

TaskDesc gTaskDescPooHoneycomb = {
    gTaskNamePooHoneycomb,
    (void (*)(void*, void*))task_poo_honeycomb_0,
    task_poo_honeycomb_1,
    (void (*)(void*))task_poo_honeycomb_2,
    (void (*)(void*))task_poo_honeycomb_3,
    0xA0,
};

const char gTaskNamePooVegetable[] = "task_poo_vegetable";

TaskDesc gTaskDescPooVegetable = {
    gTaskNamePooVegetable,
    (void (*)(void*, void*))task_poo_vegetable_0,
    task_poo_vegetable_1,
    (void (*)(void*))task_poo_vegetable_2,
    (void (*)(void*))task_poo_vegetable_3,
    0x94,
};

const char gTaskNamePooWagon[] = "task_poo_wagon";

TaskDesc gTaskDescPooWagon = {
    gTaskNamePooWagon,
    (void (*)(void*, void*))task_poo_wagon_0,
    task_poo_wagon_1,
    (void (*)(void*))task_poo_wagon_2,
    (void (*)(void*))task_poo_wagon_3,
    0x44,
};

const char gTaskNamePooWagonwheel[] = "task_poo_wagonwheel";

TaskDesc gTaskDescPooWagonwheel = {
    gTaskNamePooWagonwheel,
    (void (*)(void*, void*))task_poo_wagonwheel_0,
    task_poo_wagonwheel_1,
    (void (*)(void*))task_poo_wagonwheel_2,
    (void (*)(void*))task_poo_wagonwheel_3,
    0x44,
};

const char gTaskNamePooSpark[] = "task_poo_spark";

const PooPoint gUnk_096FD730[4] = { { -512, -1792 }, { -2304, 512 }, { 2304, -768 }, { 768, 1792 } };

TaskDesc gTaskDescPooSpark = {
    gTaskNamePooSpark,
    (void (*)(void*, void*))task_poo_spark_0,
    task_poo_spark_1,
    (void (*)(void*))task_poo_spark_2,
    (void (*)(void*))task_poo_spark_3,
    0x34,
};

const char gTaskNamePooBee[] = "task_poo_bee";

TaskDesc gTaskDescPooBee = {
    gTaskNamePooBee,
    (void (*)(void*, void*))task_poo_bee_0,
    task_poo_bee_1,
    (void (*)(void*))task_poo_bee_2,
    (void (*)(void*))task_poo_bee_3,
    0xCC,
};

const char gTaskNamePooBeeAfterEvent[] = "task_poo_beeAfterEvent";

const PooSpot gUnk_096FD778[18] = {
    { 0, 0, 0 },
    { -2560, -1280, 0 },
    { -5120, -2560, 0 },
    { -2560, -3840, 0 },
    { 0, -2560, 0 },
    { 2560, -1280, 0 },
    { 5120, -2560, 0 },
    { 2560, -3840, 0 },
    { 0, -5120, 0 },
    { 0, -640, -3200 },
    { -2560, -1920, -3200 },
    { 0, -3200, -3200 },
    { 2560, -1920, -3200 },
    { 0, -1280, -5888 },
    { 61440, 40960, 0 },
    { 0, 40960, 0 },
    { 61440, 0, 0 },
    { 0, 0, 0 },
};

const u16 gUnk_096FD850[15] = { 6, 6, 6, 6, 6, 9, 9, 9, 65535, 65535, 65535, 65535, 65535, 65535, 65535 };

const u16 gUnk_096FD86E[5] = { 3, 2, 1, 2, 4 };

TaskDesc gTaskDescPooBeeAfterEvent = {
    gTaskNamePooBeeAfterEvent,
    (void (*)(void*, void*))task_poo_beeAfterEvent_0,
    task_poo_beeAfterEvent_1,
    (void (*)(void*))task_poo_beeAfterEvent_2,
    (void (*)(void*))task_poo_beeAfterEvent_3,
    0x54,
};

const char gTaskNamePooCabbage[] = "task_poo_cabbage";

TaskDesc gTaskDescPooCabbage = {
    gTaskNamePooCabbage,
    (void (*)(void*, void*))task_poo_cabbage_0,
    task_poo_cabbage_1,
    (void (*)(void*))task_poo_cabbage_2,
    (void (*)(void*))task_poo_cabbage_3,
    0xD8,
};

const char gTaskNamePooCabbageborn[] = "task_poo_cabbageborn";

const PooMapObjHitDesc gPooMapObjHitDescs[10] = {
#if defined(VERSION_US)
    { gUnk_09760D00, 5, 0, gUnkUs_09EF62B4, gUnkUs_09EF629C, gUnk_09849E78 },
    { gUnk_09761824, 11, 0, gUnkUs_09EF62E4, gUnkUs_09EF62B8, gUnk_09849E98 },
    { gUnk_09762542, 24, 0, gUnkUs_09EF6348, gUnkUs_09EF62E8, gUnk_09849EB8 },
    { gUnk_097634D0, 3, 0, gUnkUs_09EF6358, gUnkUs_09EF634C, gUnk_09849ED8 },
    { gUnk_09763B54, 9, 0, gUnkUs_09EF6380, gUnkUs_09EF635C, gUnk_09849EF8 },
    { gUnk_09764BB8, 2, 0, gUnkUs_09EF638C, gUnkUs_09EF6384, gUnk_09849F18 },
    { gUnk_09765012, 6, 0, gUnkUs_09EF63AC, gUnkUs_09EF6394, gUnk_09849F38 },
    { gUnk_0976626E, 6, 0, gUnkUs_09EF63C8, gUnkUs_09EF63B0, gUnk_09849F38 },
    { gUnk_09767562, 10, 0, gUnkUs_09EF63F4, gUnkUs_09EF63CC, gUnk_09849F58 },
    { gUnk_09769416, 10, 0, gUnkUs_09EF6420, gUnkUs_09EF63F8, gUnk_09849F58 },
#elif defined(VERSION_JP)
    { gUnk_09760D00, 5, 0, gUnkJp_09ECD6A0, gUnkJp_09ECD688, gUnk_09849E78 },
    { gUnk_09761824, 11, 0, gUnkJp_09ECD6D0, gUnkJp_09ECD6A4, gUnk_09849E98 },
    { gUnk_09762542, 24, 0, gUnkJp_09ECD734, gUnkJp_09ECD6D4, gUnk_09849EB8 },
    { gUnk_097634D0, 3, 0, gUnkJp_09ECD744, gUnkJp_09ECD738, gUnk_09849ED8 },
    { gUnk_09763B54, 9, 0, gUnkJp_09ECD76C, gUnkJp_09ECD748, gUnk_09849EF8 },
    { gUnk_09764BB8, 2, 0, gUnkJp_09ECD778, gUnkJp_09ECD770, gUnk_09849F18 },
    { gUnk_09765012, 6, 0, gUnkJp_09ECD798, gUnkJp_09ECD780, gUnk_09849F38 },
    { gUnk_0976626E, 6, 0, gUnkJp_09ECD7B4, gUnkJp_09ECD79C, gUnk_09849F38 },
    { gUnk_09767562, 10, 0, gUnkJp_09ECD7E0, gUnkJp_09ECD7B8, gUnk_09849F58 },
    { gUnk_09769416, 10, 0, gUnkJp_09ECD80C, gUnkJp_09ECD7E4, gUnk_09849F58 },
#else
    { gUnk_09760D00, 5, 0, gUnkEu_09F816AC, gUnkEu_09F81694, gUnk_09849E78 },
    { gUnk_09761824, 11, 0, gUnkEu_09F816DC, gUnkEu_09F816B0, gUnk_09849E98 },
    { gUnk_09762542, 24, 0, gUnkEu_09F81740, gUnkEu_09F816E0, gUnk_09849EB8 },
    { gUnk_097634D0, 3, 0, gUnkEu_09F81750, gUnkEu_09F81744, gUnk_09849ED8 },
    { gUnk_09763B54, 9, 0, gUnkEu_09F81778, gUnkEu_09F81754, gUnk_09849EF8 },
    { gUnk_09764BB8, 2, 0, gUnkEu_09F81784, gUnkEu_09F8177C, gUnk_09849F18 },
    { gUnk_09765012, 6, 0, gUnkEu_09F817A4, gUnkEu_09F8178C, gUnk_09849F38 },
    { gUnk_0976626E, 6, 0, gUnkEu_09F817C0, gUnkEu_09F817A8, gUnk_09849F38 },
    { gUnk_09767562, 10, 0, gUnkEu_09F817EC, gUnkEu_09F817C4, gUnk_09849F58 },
    { gUnk_09769416, 10, 0, gUnkEu_09F81818, gUnkEu_09F817F0, gUnk_09849F58 },
#endif
};

TaskDesc gTaskDescPooCabbageborn = {
    gTaskNamePooCabbageborn,
    (void (*)(void*, void*))task_poo_cabbageborn_0,
    task_poo_cabbageborn_1,
    (void (*)(void*))task_poo_cabbageborn_2,
    (void (*)(void*))task_poo_cabbageborn_3,
    0x18,
};

const char gTaskNamePooMapobjhit[] = "task_poo_mapobjhit";

TaskDesc gTaskDescPooMapobjhit = {
    gTaskNamePooMapobjhit,
    (void (*)(void*, void*))task_poo_mapobjhit_0,
    task_poo_mapobjhit_1,
    (void (*)(void*))task_poo_mapobjhit_2,
    (void (*)(void*))task_poo_mapobjhit_3,
    0xA0,
};

const char gTaskNamePooPrize[] = "task_poo_prize";

TaskDesc gTaskDescPooPrize = {
    gTaskNamePooPrize,
    (void (*)(void*, void*))task_poo_prize_0,
    task_poo_prize_1,
    (void (*)(void*))task_poo_prize_2,
    (void (*)(void*))task_poo_prize_3,
    0x98,
};

const char gTaskNamePooZzz[] = "task_poo_zzz";

TaskDesc gTaskDescPooZzz = {
    gTaskNamePooZzz,
    (void (*)(void*, void*))task_poo_zzz_0,
    task_poo_zzz_1,
    (void (*)(void*))task_poo_zzz_2,
    (void (*)(void*))task_poo_zzz_3,
    0x28,
};

AnimDef gUnk_09EF4C88[5] = {
    { gUnk_09EF5D54, gUnk_09EF5D64, gUnk_0974465A, 0, { 0, 0, 0 } },
    { gUnk_09EF5D04, gUnk_09EF5D14, gUnk_0974431A, 0, { 0, 0, 0 } },
    { gUnk_09EF5D18, gUnk_09EF5D28, gUnk_0974441A, 0, { 0, 0, 0 } },
    { gUnk_09EF5D2C, gUnk_09EF5D3C, gUnk_097444DA, 0, { 0, 0, 0 } },
    { gUnk_09EF5D40, gUnk_09EF5D50, gUnk_0974459A, 0, { 0, 0, 0 } },
};

const char gTaskNamePooButterfly[] = "task_poo_butterfly";

TaskDesc gTaskDescPooButterfly = {
    gTaskNamePooButterfly,
    (void (*)(void*, void*))task_poo_butterfly_0,
    task_poo_butterfly_1,
    (void (*)(void*))task_poo_butterfly_2,
    (void (*)(void*))task_poo_butterfly_3,
    0xE4,
};

const char gTaskNamePooButterflyRight[] = "task_poo_butterflyRight";

TaskDesc gTaskDescPooButterflyRight = {
    gTaskNamePooButterflyRight,
    (void (*)(void*, void*))task_poo_butterfly_0,
    task_poo_butterflyRight_1,
    (void (*)(void*))task_poo_butterflyRight_2,
    (void (*)(void*))task_poo_butterfly_3,
    0xE4,
};

const char gTaskNamePooButterflyLeft[] = "task_poo_butterflyLeft";

TaskDesc gTaskDescPooButterflyLeft = {
    gTaskNamePooButterflyLeft,
    (void (*)(void*, void*))task_poo_butterfly_0,
    task_poo_butterflyLeft_1,
    (void (*)(void*))task_poo_butterflyLeft_2,
    (void (*)(void*))task_poo_butterfly_3,
    0xE4,
};

const char gTaskNamePooMapbee[] = "task_poo_mapbee";

TaskDesc gTaskDescPooMapbee = {
    gTaskNamePooMapbee,
    (void (*)(void*, void*))task_poo_mapbee_0,
    task_poo_mapbee_1,
    (void (*)(void*))task_poo_mapbee_2,
    (void (*)(void*))task_poo_mapbee_3,
    0x38,
};

const char gTaskNamePooMapbeeborn[] = "task_poo_mapbeeborn";

TaskDesc gTaskDescPooMapbeeborn = {
    gTaskNamePooMapbeeborn,
    (void (*)(void*, void*))task_poo_mapbeeborn_0,
    task_poo_mapbeeborn_1,
    (void (*)(void*))task_poo_mapbeeborn_2,
    (void (*)(void*))task_poo_mapbeeborn_3,
    0x9C,
};

const char gTaskNamePooMapbutterfly[] = "task_poo_mapbutterfly";

TaskDesc gTaskDescPooMapbutterfly = {
    gTaskNamePooMapbutterfly,
    (void (*)(void*, void*))task_poo_mapbutterfly_0,
    task_poo_mapbutterfly_1,
    (void (*)(void*))task_poo_mapbutterfly_2,
    (void (*)(void*))task_poo_mapbutterfly_3,
    0x38,
};

const char gTaskNamePooMapbutterflyborn[] = "task_poo_mapbutterflyborn";

TaskDesc gTaskDescPooMapbutterflyborn = {
    gTaskNamePooMapbutterflyborn,
    (void (*)(void*, void*))task_poo_mapbutterflyborn_0,
    task_poo_mapbutterflyborn_1,
    (void (*)(void*))task_poo_mapbutterflyborn_2,
    (void (*)(void*))task_poo_mapbutterflyborn_3,
    0x9C,
};

const char gTaskNamePooRabbitAfterEvent[] = "task_poo_rabbitAfterEvent";

TaskDesc gTaskDescPooRabbitAfterEvent = {
    gTaskNamePooRabbitAfterEvent,
    (void (*)(void*, void*))task_poo_rabbitAfterEvent_0,
    task_poo_rabbitAfterEvent_1,
    (void (*)(void*))task_poo_rabbitAfterEvent_2,
    (void (*)(void*))task_poo_rabbitAfterEvent_3,
    0xA8,
};

const char gTaskNamePooCabbageAfterEvent[] = "task_poo_cabbageAfterEvent";

TaskDesc gTaskDescPooCabbageAfterEvent = {
    gTaskNamePooCabbageAfterEvent,
    (void (*)(void*, void*))task_poo_cabbageAfterEvent_0,
    task_poo_cabbageAfterEvent_1,
    (void (*)(void*))task_poo_cabbageAfterEvent_2,
    (void (*)(void*))task_poo_cabbageAfterEvent_3,
    0x20,
};

#ifdef VERSION_EU
u8* gUnkEu_09F800A4[5] = {
    gUnk_097B7218,
    gUnkEu_097966A0,
    gUnkEu_09799760,
    gUnkEu_09798720,
    gUnkEu_097976E0,
};

u8* gUnkEu_09F800B8[5] = {
    gUnkEu_0979A7A0,
    gUnkEu_0979B7E0,
    gUnkEu_0979E8A0,
    gUnkEu_0979D860,
    gUnkEu_0979C820,
};
#endif
