#include "macros.h"
#include "card_localized_data.h"
#include "card_label_sprite_data.h"
#include "card_reload_sprite_data.h"
#include "card_sprite_data.h"
#include "msg_localized_data.h"
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "mode_sio_api.h"
#include "card_battle.h"
#include "mode_test_api.h"
#include "player_progression.h"
#include "m4a_song.h"
#include "game_state.h"
#include <string.h>
#include "text.h"
#include "monsgage.h"
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "engine_math.h"
#include "listpool.h"
#include "anim.h"
#include "obj.h"
#include "text_types.h"
#include "taskpool.h"
#include "key.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "card.h"
#include "card_reload_assets.h"
#include "map_card_assets.h"
#include "card_localized_assets.h"
#include "card_help_assets.h"
#include "card_message_assets.h"
#include "card_description_assets.h"
#include <stddef.h>
#include "game.h"
#include "bos4_api.h"

u8 gUnk_02034B20[20];

void* gUnk_02034B34;
#ifdef VERSION_EU
TaskPool gUnkEu_02034B38;

u32 gUnkEu_02034B4C;
#endif

u8 gUnk_0203A9E0 EWRAM_COMMON(4);

u8 func_080ABEF8(u32* a, u8* b);
s32 func_080AC140(s32 a);
void CreateSysmsgwinTask(void* pool, u16 b);
u8 func_080A42C8(void);

void func_080AB96C(void* a) {
    FadeStartIn(0, 16);
    gUnk_02034B34 = a;
    TaskPoolInit(gUnk_02034B20, 1);
    gUnk_0203A9E0 = 0;
}
void Mode_riku_btlTutorial_1(void) {
    u16 t;

    t = gGameState.progression.unk_82 | 0x1000;
    gGameState.progression.unk_82 = t;
    ModeRequest(&gModeBattle, (s32)gUnk_02034B34);
    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}

void Mode_riku_deckTutorial_1(void) {
    if (!FadeIsActive()) {
        switch (gUnk_0203A9E0) {
        case 0:
            if (!func_080A42C8() && gUnk_0203A9E0 == 0) {
                CreateSysmsgwinTask(gUnk_02034B20, 0xB1);
                gUnk_0203A9E0 = 1;
            }
            break;
        case 1:
            if (!func_080A42C8()) {
                gGameState.progression.unk_82 |= 0x800;
                ModeRequest(&gUnk_09EE2704, (s32)gUnk_02034B34);
            }
            break;
        }
    }

    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}

void func_080ABA70(void) {
    TaskPoolDestroy(gUnk_02034B20);
}

s32 func_080ABA80(s32* out) {
    UnkStruct_080ABA80 arr;
    u8 buf[6];
    u8 flag;
    u8 i;
    s32 r;
    BtlWork* p;
#ifdef VERSION_EU
    u8 f;
    s32 j;
#endif

    arr = gUnk_09045188;
    flag = 0;
    memset(buf, 0, 6);
#ifdef VERSION_EU
    f = 0;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    out[4] = -1;
    out[5] = -1;
#endif

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        arr.unk_00[i] = gUnk_02039DD4->unk_000[i]->cardDef->unk_28;
#ifdef VERSION_EU
        out[i] = gUnk_02039DD4->unk_000[i]->cardDef->unk_24;
#else

        if (out != 0) {
            out[i] = gUnk_02039DD4->unk_000[i]->cardDef->unk_24;
        }
#endif
    }

#ifdef VERSION_EU
    if (gUnk_02039DD4->unk_0D0 == 1 && (f = gUnk_02039DD4->unk_0E1) == 0) {
#else
    if (gUnk_02039DD4->unk_0D0 == 1) {
#endif
        gUnk_02039DD4->unk_0DD = 1;

        if ((gGameState.flags & 8) && gBtlWork->unk_0A4 == 1 && !(gBtlWork->flags & 0x800000000000)) {
            if (gUnk_02039DD4->unk_0EE == 1 || gBtlWork->unk_1C8 > 29) {
                gUnk_02039DD4->unk_0EE = 0;
                return 46;
            }
        }

        return gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
#ifdef VERSION_EU
    } else if (gUnk_02039DD4->unk_0D0 == 1 && (p = gBtlWork)->unk_0A4 == 1) {
        if (p->unk_0F4 == 47) {
            out[0] = out[1] = gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
            gUnk_02039DD4->unk_0DD = 2;
            return 145;
        } else {
            return gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
        }
#endif
    } else if (gUnk_02039DD4->unk_0D0 == 0) {
        gUnk_02039DD4->unk_0DD = 0;
        return -1;
    } else {
        r = func_080AC5E8(gUnk_02039DD4, gUnk_02039DD4->unk_0D0, gUnk_02039DD4->unk_0C2, &arr, &flag);

        switch (r) {
        case 108:
            gUnk_02039DD4->unk_0DD = 1;
            return 46;
        default:
            p = gBtlWork;

            if (p->unk_0A4 == 1) {
                if (p->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            } else {
                if (gUnk_02039B9C->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            }
        case 106:
#ifndef VERSION_EU
            if (out != 0) {
#endif
                func_080ABEF8(&arr, buf);

                if (buf[0] == 1) {
                    out[0] = arr.unk_00[0];
#ifdef VERSION_EU
                    out[1] = 145;
#else
                    out[1] = -1;
#endif
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else if (buf[1] == 1) {
#ifdef VERSION_EU
                    out[1] = 145;
#else
                    out[1] = -1;
#endif
                    out[2] = arr.unk_00[1];
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else {
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
#ifdef VERSION_EU

                    for (j = 0; j < 5; j++) {
                        if (out[j] == -1) {
                            out[j] = out[j + 1];
                            out[j + 1] = -1;
                        }
                    }
#endif
                }

                if (gBtlWork->unk_0A4 == 1) {
                    if (gBtlWork->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                } else {
                    if (gUnk_02039B9C->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                }
#ifndef VERSION_EU
            }
#endif

            return 145;
        }
    }
}

s32 func_080ABCA4(s32* out, void* b) {
    UnkStruct_080ABA80 arr;
    u8 buf[6];
    u8 flag;
    u8 i;
    s32 r;
#ifdef VERSION_EU
    u8 f;
    s32 j;
    s32 t;
#endif

    memset(&arr, 0, 24);
    flag = 0;
    memset(buf, 0, 6);
#ifdef VERSION_EU
    f = 0;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    out[4] = -1;
    out[5] = -1;
#endif

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        arr.unk_00[i] = gUnk_02039DD4->unk_000[i]->cardDef->unk_28;
#ifdef VERSION_EU
        out[i] = gUnk_02039DD4->unk_000[i]->cardDef->unk_24;
#else

        if (out != 0) {
            out[i] = gUnk_02039DD4->unk_000[i]->cardDef->unk_24;
        }
#endif
    }

    if (gUnk_02039DD4->unk_0D0 == 1) {
#ifdef VERSION_EU
        switch ((s32)b) {
        case 0:
            f = gUnk_02039DD4->unk_0E1;
            break;
        case 1:
            f = gUnk_02039DD4->unk_0E2;
            break;
        }

        if (f == 0) {
#endif
        gUnk_02039DD4->unk_0DD = 1;

        if ((gGameState.flags & 8) && gBtlWork->unk_0A4 != 0 && !(gBtlWork->flags & 0x800000000000)) {
            if (gUnk_02039DD4->unk_0EE == 1 || gBtlWork->unk_1C8 > 29) {
                gUnk_02039DD4->unk_0EE = 0;
                return 46;
            }
        }

        return gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
#ifdef VERSION_EU
        } else {
            if (gBtlWork->unk_0A4 == 1) {
                if (gBtlWork->unk_0F4 == 47) {
                    out[0] = out[1] = gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
                }
            } else {
                if (gUnk_02039B9C->unk_0F4 == 47) {
                    out[0] = out[1] = gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return gUnk_02039DD4->unk_000[0]->cardDef->unk_24;
                }
            }
        }
#endif
    } else if (gUnk_02039DD4->unk_0D0 == 0) {
        gUnk_02039DD4->unk_0DD = 0;
        return -1;
    } else {
        r = func_080AD144(gUnk_02039DD4, gUnk_02039DD4->unk_0D0, gUnk_02039DD4->unk_0C2, &arr, &flag, b);

        switch (r) {
        case 108:
            gUnk_02039DD4->unk_0DD = 1;
            return 46;
        default:
            if (gBtlWork->unk_0A4 == 1) {
                if (gBtlWork->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            } else {
                if (gUnk_02039B9C->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            }
        case 106:
#ifndef VERSION_EU
            if (out != 0) {
#endif
                func_080ABEF8(&arr, buf);

                if (buf[0] == 1) {
                    out[0] = arr.unk_00[0];
#ifdef VERSION_EU
                    out[1] = 145;
#else
                    out[1] = -1;
#endif
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else if (buf[1] == 1) {
#ifdef VERSION_EU
                    out[1] = 145;
#else
                    out[1] = -1;
#endif
                    out[2] = arr.unk_00[1];
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else {
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
#ifdef VERSION_EU

                    for (j = 0; j < 5; j++) {
                        if (out[j] == -1) {
                            t = out[j];
                            out[j] = out[j + 1];
                            out[j + 1] = t;
                        }
                    }
#endif
                }

                if (gBtlWork->unk_0A4 == 1) {
                    if (gBtlWork->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                } else {
                    if (gUnk_02039B9C->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                }
#ifndef VERSION_EU
            }
#endif

            return 145;
        }
    }
}

u8 func_080ABED0(void) {
    if ((*(u32*)&gUnk_02039DD4->unk_0E0 & 0x00FFFF00) != 0) {
        return gUnk_02039DD4->unk_0DD;
    }

    return 0;
}

#define SIO_PAIR_CASE(v) \
    case v: \
        a[i] = key; \
        b[i] = 1; \
        break;

u8 func_080ABEF8(u32* a, u8* b) {
    u32 v[6];
    u32 key;
    s32 i = 0;

    if (gUnk_02039DD4->unk_0D0 <= 2) {
        return 0;
    }

    v[0] = a[0];
    v[1] = a[1];
    v[2] = a[2];
    key = (v[1] << 10) | v[0] | 0x80000000;

    switch (key) {
    SIO_PAIR_CASE(0x8002ACAB)
    SIO_PAIR_CASE(0x8002D4B5)
    SIO_PAIR_CASE(0x8002FCBF)
    SIO_PAIR_CASE(0x800324C9)
    SIO_PAIR_CASE(0x80034CD3)
    SIO_PAIR_CASE(0x800374DD)
    SIO_PAIR_CASE(0x80039CE7)
    SIO_PAIR_CASE(0x8003C4F1)
    SIO_PAIR_CASE(0x8003ECFB)
    SIO_PAIR_CASE(0x80041505)
    SIO_PAIR_CASE(0x80043D0F)
    SIO_PAIR_CASE(0x80046519)
    SIO_PAIR_CASE(0x80048D23)
    SIO_PAIR_CASE(0x8004B52D)
    SIO_PAIR_CASE(0x8004DD37)
    SIO_PAIR_CASE(0x80050541)
    SIO_PAIR_CASE(0x80052D4B)
    SIO_PAIR_CASE(0x80055555)
    SIO_PAIR_CASE(0x80057D5F)
    SIO_PAIR_CASE(0x8005A569)
    SIO_PAIR_CASE(0x8005CD73)
    SIO_PAIR_CASE(0x800A7E9F)
    }

    i++;
    key = v[1] | (v[2] << 10) | 0x80000000;

    switch (key) {
    SIO_PAIR_CASE(0x8002ACAB)
    SIO_PAIR_CASE(0x8002D4B5)
    SIO_PAIR_CASE(0x8002FCBF)
    SIO_PAIR_CASE(0x800324C9)
    SIO_PAIR_CASE(0x80034CD3)
    SIO_PAIR_CASE(0x800374DD)
    SIO_PAIR_CASE(0x80039CE7)
    SIO_PAIR_CASE(0x8003C4F1)
    SIO_PAIR_CASE(0x8003ECFB)
    SIO_PAIR_CASE(0x80041505)
    SIO_PAIR_CASE(0x80043D0F)
    SIO_PAIR_CASE(0x80046519)
    SIO_PAIR_CASE(0x80048D23)
    SIO_PAIR_CASE(0x8004B52D)
    SIO_PAIR_CASE(0x8004DD37)
    SIO_PAIR_CASE(0x80050541)
    SIO_PAIR_CASE(0x80052D4B)
    SIO_PAIR_CASE(0x80055555)
    SIO_PAIR_CASE(0x80057D5F)
    SIO_PAIR_CASE(0x8005A569)
    SIO_PAIR_CASE(0x8005CD73)
    SIO_PAIR_CASE(0x800A7E9F)
    }
}

s32 func_080AC140(s32 a) {
    switch (a) {
    case 0:
        return 0x8002ACAB;
    case 1:
        return 0x8002D4B5;
    case 2:
        return 0x8002FCBF;
    case 3:
        return 0x800324C9;
    case 11:
        return 0x80034CD3;
    case 4:
        return 0x800374DD;
    case 5:
        return 0xC0100401;
    case 6:
        return 0x64;
    case 7:
        return 0xCAB2ACAB;
    case 8:
        return 0xCB52D4B5;
    case 9:
        return 0xCBF2FCBF;
    case 10:
        return 0xCC9324C9;
    case 13:
        return 0xCDD374DD;
    case 12:
        return 0xCD334CD3;
    case 14:
        return 0xCFB3ECFB;
    case 15:
        return 0x8003ECFB;
    case 16:
        return 0xCF13C4F1;
    case 17:
        return 0x8003C4F1;
    case 18:
        return 0xD0541505;
    case 19:
        return 0x80041505;
    case 20:
        return 0xD0F43D0F;
    case 21:
        return 0x80043D0F;
    case 22:
        return 0xD1946519;
    case 23:
        return 0x80046519;
    case 24:
        return 0xD2348D23;
    case 25:
        return 0x80048D23;
    case 26:
        return 0xD2D4B52D;
    case 27:
        return 0x8004B52D;
    case 28:
        return 0xD374DD37;
    case 29:
        return 0x8004DD37;
    case 30:
        return 0xD4150541;
    case 31:
        return 0x80050541;
    case 32:
        return 0xD4B52D4B;
    case 33:
        return 0x80052D4B;
    case 34:
        return 0xD5555555;
    case 35:
        return 0x80055555;
    case 36:
        return 0xD5F57D5F;
    case 37:
        return 0x80057D5F;
    case 38:
        return 0xD695A569;
    case 39:
        return 0x8005A569;
    case 40:
        return 0xD735CD73;
    case 41:
        return 0x8005CD73;
    case 42:
        return 0xE9FA7E9F;
    case 43:
        return 0x800A7E9F;
    case 44:
        return 0x80039CE7;
    case 45:
        return 0xCE739CE7;
    case 46:
        return 0x65;
    case 47:
        return 0x66;
    case 48:
        return 0x67;
    case 49:
        return 0x68;
    case 50:
        return 0x69;
    case 51:
        return 0x6A;
    case 52:
        return 0x6B;
    case 53:
        return 0x6C;
    case 54:
        return 0x6D;
    case 55:
        return 0x6E;
    case 56:
        return 0x6F;
    case 57:
        return 0x70;
    case 58:
        return 0x71;
    case 59:
        return 0x72;
    case 60:
        return 0x73;
    case 61:
        return 0x74;
    case 62:
        return 0x75;
    case 63:
        return 0x76;
    case 64:
        return 0x77;
    case 65:
        return 0x78;
    case 66:
        return 0x79;
    case 67:
        return 0x7A;
    case 69:
        return 0x7C;
    case 70:
        return 0x7D;
    case 71:
        return 0x7E;
    case 72:
        return 0x7F;
    case 73:
        return 0x80;
    case 74:
        return 0x81;
    case 75:
        return 0x82;
    case 76:
        return 0x83;
    case 77:
        return 0x84;
    case 78:
        return 0x85;
    case 79:
        return 0x86;
    case 80:
        return 0x87;
    case 81:
        return 0x88;
    case 82:
        return 0x89;
    case 83:
        return 0x8A;
    case 84:
        return 0x8B;
    case 108:
        return 0x2E;
    case 85:
        return 0xF21C8721;
    case 86:
        return 0xEB3ACEB3;
    case 87:
        return 0xEB3AA6B3;
    case 88:
        return 0xEE5B96E5;
    case 89:
        return 0xEEFB96EF;
    case 90:
        return 0xF49D2735;
    case 91:
        return 0xED1AF6BD;
    case 92:
        return 0xED1B1EC7;
    case 93:
        return 0xF0DBE6F9;
    case 94:
        return 0xF53D7753;
    case 95:
        return 0xF53D4F5D;
    case 96:
        return 0xF5DD4F53;
    case 97:
        return 0xF17C0F03;
    case 98:
        return 0xF35CFF3F;
    case 99:
        return 0xF21CAF21;
    case 100:
        return 0xF71D9F71;
    case 101:
        return 0xF7BDC767;
    case 102:
        return 0xFADEB7A3;
    case 103:
        return 0xFA3EB7A3;
    case 104:
        return 0xF85E3F85;
    case 105:
        return 0xF53D4F53;
    }
}

u8 func_080AC5BC(CardDisplayWork** p, u8 a) {
    u8 x;
    u8 y;
    u8 z;

    if (a != 3) {
        return 0;
    }

    x = p[0]->unk_A5;
    y = p[1]->unk_A5;
    z = p[2]->unk_A5;

    if (x != y) {
        return 0;
    }

    if (x != z) {
        return 0;
    }

    return 1;
}

s32 func_080AC5E8(UnkStruct_02039DD4* g, u8 count, u8 kind, UnkStruct_080ABA80* arr, u8* flag) {
    s32 v[3];
    u32 key;
    u8 ret;
    u8 i;

    memset(v, 0, 12);
    ret = 0;

    for (i = 0; i < count; i++) {
        v[i] = (*(i + g->unk_000))->cardDef->unk_28;
    }

    if ((gGameState.flags & 8) && gBtlWork->unk_0A4 != 0 && !(gBtlWork->flags & 0x800000000000)) {
        if (gUnk_02039DD4->unk_0EE == 1 || (s16)gBtlWork->unk_1C8 > 29) {
            gUnk_02039DD4->unk_0EE = 0;
            return 108;
        }
    }

    key = v[0] | (v[1] << 10) | (v[2] << 20) | (count << 30);

    switch (key) {
    case 0x8002ACAB:
        return 0;
    case 0x8002FCBF:
        return 2;
    case 0x8002D4B5:
        return 1;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    case 0xC0100401:
    case 0xC0B02C0B:
    case 0xC1505415:
    case 0xC1F07C1F:
    case 0xC290A429:
    case 0xC330CC33:
    case 0xC3D0F43D:
    case 0xC4711C47:
    case 0xC5114451:
    case 0xC5B16C5B:
    case 0xC6519465:
    case 0xC6F1BC6F:
    case 0xC791E479:
    case 0xC8320C83:
    case 0xC8D2348D:
    case 0xC9725C97:
    case 0xCA1284A1:
        if ((u16)(kind - 10) <= 5 && (u8)func_0800FBCC(0) != 0) {
            arr->unk_00[0] = 50;
            return 50;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_0800FBCC(2) != 0) {
            arr->unk_00[0] = 51;
            return 51;
        }
        break;
    case 0xCAB2ACAB:
        return 7;
    case 0xCB52D4B5:
        return 8;
    case 0xCBF2FCBF:
        return 9;
    case 0xCC9324C9:
        return 10;
    case 0xCD334CD3:
        return 12;
    case 0xCDD374DD:
        return 13;
    case 0xCE739CE7:
        return 45;
    case 0xCFB3ECFB:
        return 14;
    case 0xCF13C4F1:
        return 16;
    case 0xD0541505:
        return 18;
    case 0xD0F43D0F:
        return 20;
    case 0xD1946519:
        return 22;
    case 0xD2348D23:
        return 24;
    case 0xD2D4B52D:
        return 26;
    case 0xD374DD37:
        return 28;
    case 0xD4150541:
        return 30;
    case 0xD4B52D4B:
        return 32;
    case 0xD5555555:
        return 34;
    case 0xD5F57D5F:
        return 36;
    case 0xD695A569:
        return 38;
    case 0xD735CD73:
        return 40;
    case 0xE9FA7E9F:
        return 42;
    case 0xCE739CDD:
        if ((u8)func_0800FBCC(39) != 0) {
            return 53;
        }
        break;
    case 0xCE734CDD:
        if ((u8)func_0800FBCC(38) != 0) {
            return 54;
        }
        break;
    case 0xCE72ACB5:
        if ((u8)func_0800FBCC(34) != 0) {
            return 65;
        }
        break;
    case 0xCAB2AD37:
        if ((u8)func_0800FBCC(32) != 0) {
            return 70;
        }
        break;
    case 0xCE734CC9:
        if ((u8)func_0800FBCC(43) != 0) {
            return 77;
        }
        break;
    case 0xE95A5695:
        if (gBtlWork->flags & 0x800000000000) {
            if ((u16)(kind - 5) <= 10) {
                return 82;
            }

            if ((u16)(kind - 16) <= 9) {
                return 83;
            }

            if (kind > 26) {
                return 84;
            }
        }
        break;
    case 0xF21C8721:
        return 85;
    case 0xEB3ACEB3:
        return 86;
    case 0xEB3AA6B3:
        return 87;
    case 0xEE5B96E5:
        return 88;
    case 0xEEFB96EF:
        return 89;
    case 0xF49D2735:
        return 90;
    case 0xED1AF6BD:
        return 91;
    case 0xED1B1EC7:
        return 92;
    case 0xF0DBE6F9:
        return 93;
    case 0xF53D7753:
        return 94;
    case 0xF53D4F5D:
        return 95;
    case 0xF5DD4F53:
        return 96;
    case 0xF17C0F03:
        return 97;
    case 0xF35CFF3F:
        return 98;
    case 0xF21CAF21:
        return 99;
    case 0xF71D9F71:
        return 100;
    case 0xF7BDC767:
        return 101;
    case 0xFADEB7A3:
        return 102;
    case 0xFA3EB7A3:
        return 103;
    case 0xF85E3F85:
        return 104;
    case 0xF53D4F53:
        return 105;
    }

    if ((u8)func_080ADF94(g, count, 43) != 0 || (u8)func_080ADFD4(g, count) != 0) {
        if ((u8)func_0800FBCC(42) != 0) {
            return 55;
        }
    }

    if ((u8)func_080AE080(g, count) != 0 && (u8)func_0800FBCC(41) != 0) {
        return 56;
    }

    if ((u8)func_080ADEAC(g, 23, count) != 0 && (u8)func_0800FBCC(27) != 0) {
        return 58;
    }

    if ((u8)func_080ADEAC(g, 24, count) != 0 && (u8)func_0800FBCC(28) != 0) {
        return 59;
    }

    if ((u8)func_080ADEAC(g, 31, count) != 0 && (u8)func_0800FBCC(29) != 0) {
        return 60;
    }

    if ((u8)func_080ADEAC(g, 18, count) != 0 && (u8)func_0800FBCC(23) != 0) {
        return 61;
    }

    if ((u8)func_080ADEAC(g, 19, count) != 0 && (u8)func_0800FBCC(24) != 0) {
        return 62;
    }

    if ((u8)func_080ADEAC(g, 20, count) != 0 && (u8)func_0800FBCC(25) != 0) {
        return 63;
    }

    if ((u8)func_080ADEAC(g, 22, count) != 0 && (u8)func_0800FBCC(26) != 0) {
        return 64;
    }

    if ((u8)func_080AE0B4(g, count) != 0 && (u8)func_0800FBCC(46) != 0) {
        return 66;
    }

    if ((u8)func_080AE0F4(g, count) != 0 && (u8)func_0800FBCC(58) != 0) {
        return 67;
    }

    if ((u8)func_080AE014(g, count) != 0 && (u8)func_0800FBCC(44) != 0) {
        return 69;
    }

    if ((u8)func_080ADF60(g, count) != 0 && (u8)func_0800FBCC(31) != 0) {
        return 71;
    }

    if ((u8)func_080ADEEC(g, 25, 0, count) != 0 && (u8)func_0800FBCC(35) != 0) {
        return 72;
    }

    if ((u8)func_080ADEEC(g, 27, 0, count) != 0 && (u8)func_0800FBCC(50) != 0) {
        return 73;
    }

    if ((u8)func_080AE134(g, count) != 0 && (u8)func_0800FBCC(56) != 0) {
        return 74;
    }

    if ((u8)func_080AE168(g, count) != 0 && (u8)func_0800FBCC(30) != 0) {
        return 75;
    }

    if ((u8)func_080AE1A8(g, count) != 0 && (u8)func_0800FBCC(33) != 0) {
        return 76;
    }

    if ((u8)func_080ADE2C(g, count, 22, 23, 1) != 0 && (u8)func_0800FBCC(40) != 0) {
        return 78;
    }

    if ((u8)func_080ADE78(g, count, 24, 22) != 0 && (u8)func_0800FBCC(36) != 0) {
        return 79;
    }

    if ((u8)func_080ADE2C(g, count, 22, 25, 1) != 0 && (u8)func_0800FBCC(37) != 0) {
        return 80;
    }

    if ((u8)func_080AE1E8(g, count) != 0 && (u8)func_0800FBCC(45) != 0) {
        return 81;
    }

    if ((u8)func_080ADD04(g, count) != 0) {
        if ((u16)(kind - 10) <= 5 && (u8)func_0800FBCC(1) != 0) {
            arr->unk_00[0] = 46;
            return 46;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_0800FBCC(5) != 0) {
            arr->unk_00[0] = 5;
            return 5;
        }
    }

    if ((u8)func_080ADD58(g, count) != 0) {
        if ((u16)(kind - 1) <= 5 && (u8)func_0800FBCC(6) != 0) {
            arr->unk_00[0] = 47;
            return 47;
        }

        if ((u16)(kind - 24) <= 2 && (u8)func_0800FBCC(4) != 0) {
            arr->unk_00[0] = 6;
            return 6;
        }

        if ((u16)(kind - 7) <= 2 && (u8)func_0800FBCC(7) != 0) {
            arr->unk_00[0] = 48;
            return 48;
        }

        if (kind == 0 || kind == 27) {
            if ((u8)func_0800FBCC(3) != 0) {
                arr->unk_00[0] = 52;
                return 52;
            }
        }
    }

    if ((u8)func_080ADDA8(g, count) != 0 && (u8)func_0800FBCC(8) != 0) {
        arr->unk_00[0] = 49;
        return 49;
    }

    *flag = ret;

    if (ret == 0) {
        return 106;
    }

    if (ret == 1) {
        return arr->unk_00[0];
    }

    return 107;
}

s32 func_080AD144(UnkStruct_02039DD4* g, u8 count, u8 kind, UnkStruct_080ABA80* arr, u8* flag, void* b) {
    s32 v[3];
    u32 key;
    u8 ret;
    u8 i;

    memset(v, 0, 12);
    ret = 0;

    for (i = 0; i < count; i++) {
        v[i] = (*(i + g->unk_000))->cardDef->unk_28;
    }

    if ((gGameState.flags & 8) && gBtlWork->unk_0A4 != 0 && !(gBtlWork->flags & 0x800000000000)) {
        if (gUnk_02039DD4->unk_0EE == 1 || (s16)gBtlWork->unk_1C8 > 29) {
            gUnk_02039DD4->unk_0EE = 0;
            return 108;
        }
    }

    key = v[0] | (v[1] << 10) | (v[2] << 20) | (count << 30);

    switch (key) {
    case 0x8002ACAB:
        return 0;
    case 0x8002FCBF:
        return 2;
    case 0x8002D4B5:
        return 1;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    case 0xC0100401:
    case 0xC0B02C0B:
    case 0xC1505415:
    case 0xC1F07C1F:
    case 0xC290A429:
    case 0xC330CC33:
    case 0xC3D0F43D:
    case 0xC4711C47:
    case 0xC5114451:
    case 0xC5B16C5B:
    case 0xC6519465:
    case 0xC6F1BC6F:
    case 0xC791E479:
    case 0xC8320C83:
    case 0xC8D2348D:
    case 0xC9725C97:
    case 0xCA1284A1:
        if ((u16)(kind - 10) <= 5 && (u8)func_080AE274(0, b) != 0) {
            arr->unk_00[0] = 50;
            return 50;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_080AE274(2, b) != 0) {
            arr->unk_00[0] = 51;
            return 51;
        }
        break;
    case 0xCAB2ACAB:
        return 7;
    case 0xCB52D4B5:
        return 8;
    case 0xCBF2FCBF:
        return 9;
    case 0xCC9324C9:
        return 10;
    case 0xCD334CD3:
        return 12;
    case 0xCDD374DD:
        return 13;
    case 0xCE739CE7:
        return 45;
    case 0xCFB3ECFB:
        return 14;
    case 0xCF13C4F1:
        return 16;
    case 0xD0541505:
        return 18;
    case 0xD0F43D0F:
        return 20;
    case 0xD1946519:
        return 22;
    case 0xD2348D23:
        return 24;
    case 0xD2D4B52D:
        return 26;
    case 0xD374DD37:
        return 28;
    case 0xD4150541:
        return 30;
    case 0xD4B52D4B:
        return 32;
    case 0xD5555555:
        return 34;
    case 0xD5F57D5F:
        return 36;
    case 0xD695A569:
        return 38;
    case 0xD735CD73:
        return 40;
    case 0xE9FA7E9F:
        return 42;
    case 0xCE739CDD:
        if ((u8)func_080AE274(39, b) != 0) {
            return 53;
        }
        break;
    case 0xCE734CDD:
        if ((u8)func_080AE274(38, b) != 0) {
            return 54;
        }
        break;
    case 0xCE72ACB5:
        if ((u8)func_080AE274(34, b) != 0) {
            return 65;
        }
        break;
    case 0xCAB2AD37:
        if ((u8)func_080AE274(32, b) != 0) {
            return 70;
        }
        break;
    case 0xCE734CC9:
        if ((u8)func_080AE274(43, b) != 0) {
            return 77;
        }
        break;
    case 0xE95A5695:
        if (gBtlWork->flags & 0x800000000000) {
            if ((u16)(kind - 5) <= 10) {
                return 82;
            }

            if ((u16)(kind - 16) <= 9) {
                return 83;
            }

            if (kind > 26) {
                return 84;
            }
        }
        break;
    case 0xF21C8721:
        return 85;
    case 0xEB3ACEB3:
        return 86;
    case 0xEB3AA6B3:
        return 87;
    case 0xEE5B96E5:
        return 88;
    case 0xEEFB96EF:
        return 89;
    case 0xF49D2735:
        return 90;
    case 0xED1AF6BD:
        return 91;
    case 0xED1B1EC7:
        return 92;
    case 0xF0DBE6F9:
        return 93;
    case 0xF53D7753:
        return 94;
    case 0xF53D4F5D:
        return 95;
    case 0xF5DD4F53:
        return 96;
    case 0xF17C0F03:
        return 97;
    case 0xF35CFF3F:
        return 98;
    case 0xF21CAF21:
        return 99;
    case 0xF71D9F71:
        return 100;
    case 0xF7BDC767:
        return 101;
    case 0xFADEB7A3:
        return 102;
    case 0xFA3EB7A3:
        return 103;
    case 0xF85E3F85:
        return 104;
    case 0xF53D4F53:
        return 105;
    }

    if ((u8)func_080ADF94(g, count, 43) != 0 || (u8)func_080ADFD4(g, count) != 0) {
        if ((u8)func_080AE274(42, b) != 0) {
            return 55;
        }
    }

    if ((u8)func_080AE080(g, count) != 0 && (u8)func_080AE274(41, b) != 0) {
        return 56;
    }

    if ((u8)func_080ADEAC(g, 23, count) != 0 && (u8)func_080AE274(27, b) != 0) {
        return 58;
    }

    if ((u8)func_080ADEAC(g, 24, count) != 0 && (u8)func_080AE274(28, b) != 0) {
        return 59;
    }

    if ((u8)func_080ADEAC(g, 31, count) != 0 && (u8)func_080AE274(29, b) != 0) {
        return 60;
    }

    if ((u8)func_080ADEAC(g, 18, count) != 0 && (u8)func_080AE274(23, b) != 0) {
        return 61;
    }

    if ((u8)func_080ADEAC(g, 19, count) != 0 && (u8)func_080AE274(24, b) != 0) {
        return 62;
    }

    if ((u8)func_080ADEAC(g, 20, count) != 0 && (u8)func_080AE274(25, b) != 0) {
        return 63;
    }

    if ((u8)func_080ADEAC(g, 22, count) != 0 && (u8)func_080AE274(26, b) != 0) {
        return 64;
    }

    if ((u8)func_080AE0B4(g, count) != 0 && (u8)func_080AE274(46, b) != 0) {
        return 66;
    }

    if ((u8)func_080AE0F4(g, count) != 0 && (u8)func_080AE274(58, b) != 0) {
        return 67;
    }

    if ((u8)func_080AE014(g, count) != 0 && (u8)func_080AE274(44, b) != 0) {
        return 69;
    }

    if ((u8)func_080ADF60(g, count) != 0 && (u8)func_080AE274(31, b) != 0) {
        return 71;
    }

    if ((u8)func_080ADEEC(g, 25, 0, count) != 0 && (u8)func_080AE274(35, b) != 0) {
        return 72;
    }

    if ((u8)func_080ADEEC(g, 27, 0, count) != 0 && (u8)func_080AE274(50, b) != 0) {
        return 73;
    }

    if ((u8)func_080AE134(g, count) != 0 && (u8)func_080AE274(56, b) != 0) {
        return 74;
    }

    if ((u8)func_080AE168(g, count) != 0 && (u8)func_080AE274(30, b) != 0) {
        return 75;
    }

    if ((u8)func_080AE1A8(g, count) != 0 && (u8)func_080AE274(33, b) != 0) {
        return 76;
    }

    if ((u8)func_080ADE2C(g, count, 22, 23, 1) != 0 && (u8)func_080AE274(40, b) != 0) {
        return 78;
    }

    if ((u8)func_080ADE78(g, count, 24, 22) != 0 && (u8)func_080AE274(36, b) != 0) {
        return 79;
    }

    if ((u8)func_080ADE2C(g, count, 22, 25, 1) != 0 && (u8)func_080AE274(37, b) != 0) {
        return 80;
    }

    if ((u8)func_080AE1E8(g, count) != 0 && (u8)func_080AE274(45, b) != 0) {
        return 81;
    }

    if ((u8)func_080ADD04(g, count) != 0) {
        if ((u16)(kind - 10) <= 5 && (u8)func_080AE274(1, b) != 0) {
            arr->unk_00[0] = 46;
            return 46;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_080AE274(5, b) != 0) {
            arr->unk_00[0] = 5;
            return 5;
        }
    }

    if ((u8)func_080ADD58(g, count) != 0) {
        if ((u16)(kind - 1) <= 5 && (u8)func_080AE274(6, b) != 0) {
            arr->unk_00[0] = 47;
            return 47;
        }

        if ((u16)(kind - 24) <= 2 && (u8)func_080AE274(4, b) != 0) {
            arr->unk_00[0] = 6;
            return 6;
        }

        if ((u16)(kind - 7) <= 2 && (u8)func_080AE274(7, b) != 0) {
            arr->unk_00[0] = 48;
            return 48;
        }

        if (kind == 0 || kind == 27) {
            if ((u8)func_080AE274(3, b) != 0) {
                arr->unk_00[0] = 52;
                return 52;
            }
        }
    }

    if ((u8)func_080ADDA8(g, count) != 0 && (u8)func_080AE274(8, b) != 0) {
        arr->unk_00[0] = 49;
        return 49;
    }

    *flag = ret;

    if (ret == 0) {
        return 106;
    }

    if (ret == 1) {
        return arr->unk_00[0];
    }

    return 107;
}

s32 func_080ADD04(CardDisplayWork** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        d0 = p[0]->cardDef;
        c0 = d0->unk_1C;
        d1 = p[1]->cardDef;
        c1 = d1->unk_1C;
        d2 = p[2]->cardDef;
        c2 = d2->unk_1C;

        if (d0->unk_2A == 0 && d1->unk_2A == 0 && d2->unk_2A == 0 &&
            c0 != c1 && c0 != c2 && c1 != c2) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADD58(CardDisplayWork** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;

    if (b == 3) {
        d0 = p[0]->cardDef;
        d1 = p[1]->cardDef;
        d2 = p[2]->cardDef;

        if (d0->unk_24 != 18 && d1->unk_24 != 18 && d2->unk_24 != 18 &&
            d0->unk_2A == 0 && d1->unk_2A == 0 && d2->unk_2A == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADDA8(CardDisplayWork** p, u8 b) {
    CardDef* d0;
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        d0 = p[0]->cardDef;
        c0 = d0->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        c2 = p[2]->cardDef->unk_1C;

        if (c0 != c1 && c1 != c2 && c2 != c0) {
            if (d0->unk_2A == 0) {
                if (c1 == 39 && c2 == 40) {
                    return 1;
                }

                if (c1 == 40 && c2 == 39) {
                    return 1;
                }
            }

            if (p[1]->cardDef->unk_2A == 0) {
                if (c0 == 39 && c2 == 40) {
                    return 1;
                }

                if (c0 == 40 && c2 == 39) {
                    return 1;
                }
            }

            if (p[2]->cardDef->unk_2A == 0) {
                if (c1 == 39 && c0 == 40) {
                    return 1;
                }

                if (c1 == 40 && c0 == 39) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

s32 func_080ADE2C(CardDisplayWork** p, u8 b, u16 c, u16 d, u8 e) {
    if (
#ifdef VERSION_EU
        b == 3 &&
#endif
        p[0]->cardDef->unk_1C == c && p[1]->cardDef->unk_1C == d &&
        p[2]->cardDef->unk_2A == e && !(p[2]->cardDef->flags & 4)) {
        return 1;
    }

    return 0;
}

s32 func_080ADE78(CardDisplayWork** p, u8 b, u16 c, u16 d) {
    if (
#ifdef VERSION_EU
        b == 3 &&
#endif
        p[0]->cardDef->unk_1C == c && p[1]->cardDef->unk_1C == d &&
        (p[2]->cardDef->flags & 4)) {
        return 1;
    }

    return 0;
}

s32 func_080ADEAC(CardDisplayWork** p, u16 c, u8 b) {
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        d1 = p[1]->cardDef;
        d2 = p[2]->cardDef;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (s1 == 0 && s2 == 0 && c0 == c) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADEEC(CardDisplayWork** p, u16 c, u8 e, u8 b) {
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        d1 = p[1]->cardDef;
        d2 = p[2]->cardDef;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (c0 == c && s1 == e && s2 == s1) {
            return 1;
        }
    }

    return 0;
}
#ifndef VERSION_EU
s32 func_080ADF30(CardDisplayWork** p, u8 b) {
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        c2 = p[2]->cardDef->unk_1C;

        if (c1 == c2 && c1 == 26 && c0 != 26) {
            return 1;
        }
    }

    return 0;
}
#endif
s32 func_080ADF60(CardDisplayWork** p, u8 b) {
    u16 c0;
    u16 c1;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;

        if (c0 == 18 && c1 == 30 && p[2]->cardDef->unk_2A == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADF94(CardDisplayWork** p, u8 b, u16 c) {
    u16 e0;
    u16 e1;

    if (b == 3) {
        e0 = p[0]->cardDef->flags;
        e1 = p[1]->cardDef->flags;

        if ((e0 & 4) && (e1 & 4) && p[2]->cardDef->unk_1C == c) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADFD4(CardDisplayWork** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;

        if (c0 == 25 && c1 == 30) {
            d2 = p[2]->cardDef;

            if (d2->unk_2A == 2 && !(d2->flags & 8)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 func_080AE014(CardDisplayWork** p, u8 b) {
    CardDef* d1;
    u16 e0;
    u16 e1;

    if (b == 3) {
        e0 = p[0]->cardDef->flags;
        d1 = p[1]->cardDef;
        e1 = d1->flags;

        if ((e0 & 4) && e1 == 0 && d1->unk_2A == 1 &&
            p[2]->cardDef->unk_1C == 43) {
            return 1;
        }

        if (p[0]->cardDef->unk_1C == 27 && p[1]->cardDef->unk_1C == 19 &&
            p[2]->cardDef->unk_2A == 2 && !(p[2]->cardDef->flags & 8)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE080(CardDisplayWork** p, u8 b) {
    u16 c0;
    u16 c1;
    u16 e2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        e2 = p[2]->cardDef->flags;

        if (c0 == 26 && c1 == 29 && (e2 & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE0B4(CardDisplayWork** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        d2 = p[2]->cardDef;
        s2 = d2->unk_2A;

        if (c0 == 36 && c1 == 38 && s2 == 2 && !(d2->flags & 8)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE0F4(CardDisplayWork** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        d2 = p[2]->cardDef;
        s2 = d2->unk_2A;

        if (c0 == 18 && c1 == 39 && s2 == 1 && !(d2->flags & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE134(CardDisplayWork** p, u8 b) {
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        s2 = p[2]->cardDef->unk_2A;

        if (c0 == 31 && c1 == 23 && s2 == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE168(CardDisplayWork** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        d2 = p[2]->cardDef;
        s2 = d2->unk_2A;

        if (c0 == 24 && c1 == 18 && s2 == 1 && !(d2->flags & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE1A8(CardDisplayWork** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->cardDef->unk_1C;
        c1 = p[1]->cardDef->unk_1C;
        d2 = p[2]->cardDef;
        s2 = d2->unk_2A;

        if (c0 == 24 && c1 == 19 && s2 == 1 && !(d2->flags & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE1E8(CardDisplayWork** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u16 c1;
    u16 c2;
    u8 s0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        d0 = p[0]->cardDef;
        c0 = d0->unk_1C;
        d1 = p[1]->cardDef;
        c1 = d1->unk_1C;
        d2 = p[2]->cardDef;
        c2 = d2->unk_1C;
        s0 = d0->unk_2A;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (s0 == 1 && !(d0->flags & 4) && s1 == 1 && !(d1->flags & 4) &&
            c2 == 44) {
            return 1;
        }

        if (c0 == 23 && c1 == 24 && s2 == 2 && !(p[2]->cardDef->flags & 8)) {
            return 1;
        }
    }

    return 0;
}

u8 func_080AE274(s32 a, s32 b) {
    u8 r;

    if (b != 0) {
        r = func_0800FCD8(a);
    } else {
        r = func_0800FC90(a);
    }

    return r;
}
s32 func_080AE28C(u32* p) {
    u32 v[6];

    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];

    switch ((v[1] << 10) | v[0] | 0x80000000) {
    case 0x8002ACAB:
        return 0;
    case 0x8002D4B5:
        return 1;
    case 0x8002FCBF:
        return 2;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    }

    switch (v[1] | (v[2] << 10) | 0x80000000) {
    case 0x8002ACAB:
        return 0;
    case 0x8002D4B5:
        return 1;
    case 0x8002FCBF:
        return 2;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    }

    return 106;
}

void CreateCardMessageTask(void* pool, u32 a, u16 b);
u8 func_080A42C8(void);
#ifdef VERSION_EU
void eu_080AB9FC(void) {
    gUnkEu_02034B4C = 0;
    SetBgMode0();
    SetupBg(0, 0, 28, 14);
    TaskPoolInit(&gUnkEu_02034B38, 1);
    CreateCardMessageTask(&gUnkEu_02034B38, 0, gUnkEu_02034B4C);
}
void eu_080ABA38(void) {
    if (func_080A42C8() == 0) {
        gUnkEu_02034B4C++;
        if (gUnkEu_02034B4C == 179) {
            gUnkEu_02034B4C = 0;
        }
        CreateCardMessageTask(&gUnkEu_02034B38, 0, gUnkEu_02034B4C);
    }
    TaskPoolUpdate(&gUnkEu_02034B38);
    TaskPoolDraw(&gUnkEu_02034B38);
}
void eu_080ABA7C(void) {
    TaskPoolDestroy(&gUnkEu_02034B38);
}
#endif

Mode gModeRikuBtlTutorial = {
    "Mode_riku_btlTutorial",
    (ModeInitFunc)func_080AB96C,
    Mode_riku_btlTutorial_1,
    func_080ABA70,
};

Mode gModeRikuDeckTutorial = {
    "Mode_riku_deckTutorial",
    (ModeInitFunc)func_080AB96C,
    Mode_riku_deckTutorial_1,
    func_080ABA70,
};

const UnkStruct_080ABA80 gUnk_09045188 = {
    { -1, -1, -1, -1, -1, -1 },
};
#ifdef VERSION_EU
Mode gUnkEu_09F74600 = {
    "Mode_textcheck",
    (ModeInitFunc)eu_080AB9FC,
    eu_080ABA38,
    eu_080ABA7C,
};
#endif
