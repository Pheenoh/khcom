#include "macros.h"
#include "unk_08104a84.h"
#include "gba/keys.h"

MsCard* gUnk_02035C10;
s16 gUnk_02035C14;
u16 gUnk_02035C16;
s16 gUnk_02035C18;
u8 gUnk_02035C1A[6];
s16 gUnk_02035C20[4];
s16 gUnk_02035C28[4];
s16 gUnk_02035C30[4];
s16 gUnk_02035C38;
u16 gUnk_02035C3A;
u16 gUnk_02035C3C;
void* gUnk_02035C40;
u16* gUnk_02035C44;
void* gUnk_02035C48;
u32 gUnk_02035C4C;
AnimState gUnk_02035C50;
AnimState gUnk_02035C68;
void* gUnk_02035C80;
void* gUnk_02035C84;
AnimState gUnk_02035C88;
AnimState gUnk_02035CA0;
u8 gUnk_02035CB8;
s16 gUnk_02035CBA;
s16 gUnk_02035CBC;
void* gUnk_02035CC0;
void* gUnk_02035CC4;
AnimState gUnk_02035CC8;
s16 gUnk_02035CE0;
s16 gUnk_02035CE2;
s16 gUnk_02035CE4;
void* gUnk_02035CE8[4][3];
void* gUnk_02035D18[4][3];
void* gUnk_02035D48[4][3];
u8 gUnk_02035D78[4][3];
void* gUnk_02035D84;
void* gUnk_02035D88;
void* gUnk_02035D8C;
void* gUnk_02035D90;
void* gUnk_02035D94;
void* gUnk_02035D98;
void* gUnk_02035D9C;
AnimState gUnk_02035DA0;
void* gUnk_02035DB8;
u32 gUnk_02035DBC;
AnimState gUnk_02035DC0;
u8 gUnk_02035DD8;
void* gUnk_02035DDC;
u8 gUnk_02035DE0;
void* gUnk_02035DE4;
u8 gUnk_02035DE8;
void* gUnk_02035DEC;
u8 gUnk_02035DF0;
u16 gUnk_02035DF2;
void* gUnk_02035DF4;
u8 gUnk_02035DF8;
u16 gUnk_02035DFA;
void* gUnk_02035DFC;
u8 gUnk_02035E00;
u16 gUnk_02035E02;
void* gUnk_02035E04;
u8 gUnk_02035E08;
u16 gUnk_02035E0A;
s16 gUnk_02035E0C;
s16 gUnk_02035E0E;
s16 gUnk_02035E10;
u32 gUnk_02035E14;
s32 gUnk_02035E18;
s32 gUnk_02035E1C;
u8 gUnk_02035E20;

s16 func_08104A84(s16 a) {
    s16 v;

    if (a <= 3) {
        v = gUnk_02035C20[a];
    } else {
        v = 0;
    }
    return v;
}

s16 func_08104AA4(s16 a) {
    s16 v;
    s16 i;

    if (a <= 3) {
        v = gUnk_02035C28[a];
    } else {
        v = 0;

        for (i = 0; i < 4; i++) {
            v += gUnk_02035C28[i];
        }
    }
    return v;
}

s16 func_08104AEC(void) {
    return func_08104A84(gUnk_02035C18) + (gUnk_02035CE4 + gUnk_02035CE2) * 3 + gUnk_02035CE0;
}

MsCard* func_08104B2C(void) {
    return gUnk_02035C10 + func_08104AEC();
}

void func_08104B48(void) {
    MsCard* card;
    s16 i;

    card = func_08104B2C();
    if (card->unk_00 != 0x8F) {
        for (i = 0; i < 10; i++) {
            if (card->unk_06[i][0] > 0) {
                break;
            }
        }
        gUnk_02035E0C = i / 5;
        gUnk_02035E0E = i % 5;
    } else {
        gUnk_02035E0C = 0;
        gUnk_02035E0E = 0;
    }
}

void func_08104BBC(void) {
    s16 i;
    s16 k;
    s16 idx;
    s16 a;
    s16 limit;
    s32 defIdx;

    a = func_08104A84(gUnk_02035C18);
    limit = func_08104AA4(gUnk_02035C18);
    idx = gUnk_02035CE4 * 3;

    for (i = 0; i < 4; i++) {
        for (k = 0; k < 3; k++) {
            if (gUnk_02035CE8[i][k] != 0) {
                ReleaseObjPalette(gUnk_02035CE8[i][k]);
            }

            if (gUnk_02035D18[i][k] != 0) {
                ReleaseObjTiles(gUnk_02035D18[i][k]);
            }

            if (idx < limit) {
                defIdx = gUnk_02035C10[a + idx].unk_02;
                gUnk_02035CE8[i][k] = LoadObjPalette(gCardDefs[defIdx].unk_18, 0x20);
                gUnk_02035D18[i][k] = LoadObjTiles(gCardDefs[defIdx].unk_14, 0x100);
                gUnk_02035D48[i][k] = gCardDefs[defIdx].unk_10;
                gUnk_02035D78[i][k] = gUnk_02035C10[a + idx].unk_2E;
            } else {
                gUnk_02035CE8[i][k] = 0;
                gUnk_02035D18[i][k] = 0;
                gUnk_02035D48[i][k] = 0;
                gUnk_02035D78[i][k] = 0;
            }
            idx++;
        }
    }
}

void func_08104D18(void) {
    MsCard* card;
    u8* p;
    u8* q;
    s32 defIdx;

    card = func_08104B2C();

    if (gUnk_02035D84 != 0) {
        ReleaseObjPalette(gUnk_02035D84);
    }

    if (gUnk_02035D88 != 0) {
        ReleaseObjTiles(gUnk_02035D88);
    }

    if (gUnk_02035D94 != 0) {
        ReleaseObjTiles(gUnk_02035D94);
    }

    if (card->unk_00 != 0x8F && func_08104AA4(gUnk_02035C18) > 0) {
        defIdx = card->unk_02;
        gUnk_02035D84 = LoadObjPalette(gCardDefs[defIdx].unk_08, 0x20);
        gUnk_02035D88 = LoadObjTiles(gCardDefs[defIdx].unk_04, 0x200);
        gUnk_02035D8C = gCardDefs[defIdx].unk_00;
        gUnk_02035D94 = LoadObjTiles(gUnk_08F709B0[card->unk_04].unk_0C, 0x300);
        gUnk_02035D98 = gUnk_08F709B0[card->unk_04].unk_00;
        gUnk_02035DD8 = card->unk_2E;
        p = &gUnk_02035DE0;
        *p = func_08065B6C(gCardDefs[defIdx].unk_0C, gUnk_02035DDC);
        q = &gUnk_02035DE8;
        *q = func_08065B6C(gUnk_09EE8F48[card->unk_00], gUnk_02035DE4);
        LoadObjPaletteBank(gUnk_02035C44[3], gUnk_09A3DE7C + card->unk_04 * 0x20);
    } else {
        gUnk_02035D84 = 0;
        gUnk_02035D88 = 0;
        gUnk_02035D8C = 0;
        gUnk_02035D94 = 0;
        gUnk_02035D98 = 0;
        gUnk_02035DD8 = 0;
        gUnk_02035DE0 = 0;
        gUnk_02035DE8 = 0;
    }
}

s16 func_08104E9C(s16 a, s16 b) {
    return b + a * 5;
}

s16 func_08104EB4(void) {
    return func_08104E9C(gUnk_02035E0C, gUnk_02035E0E);
}

u16 func_08104ED8(u16 index) {
    MsCard* card;
    u16 id;

    card = &gUnk_02035C10[index];
    if (card->unk_00 != 0x8F) {
        id = card->unk_06[func_08104EB4()][1];
        return func_08060A2C(card->unk_2E != 0 ? id | 0x8000 : id);
    }
    return 0;
}

void func_08104F2C(void) {
    u32 v;

    v = GetMooglePoints();
    func_08101588(v, gUnk_09A1DB9C, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);

    if (gUnk_02035C16 >= 2 && gUnk_02035C16 <= 3) {
        v = func_08104ED8(func_08104AEC());
    } else {
        v = 0;
    }
    func_08101588(v, gUnk_09A1DCDC, (u8*)GetBgCharBase(0) + 0x180, 0x20, 2);
}

void func_08104FA4(void) {
    func_08101588(gUnk_02035C38, gUnk_09A1DB9C, (u8*)GetBgCharBase(0) + 0xC0, 0x20, 3);
    func_08101588(gUnk_02035C3C, gUnk_09A1DB9C, (u8*)GetBgCharBase(0) + 0x120, 0x20, 3);
}

void func_08104FF8(void) {
    s16 i;
    s32 v;

    for (i = 0; i < 4; i++) {
        v = gUnk_02035C30[i];
        if (v != 0) {
            func_08101588(v, gUnk_09A1DE3C, (u8*)GetBgCharBase(0) + (i * 3 * 0x20 + 0x1C0), 0x20, 3);
        } else {
            func_08101588(0, gUnk_09A1DE1C, (u8*)GetBgCharBase(0) + (i * 3 * 0x20 + 0x1C0), 0x20, 3);
        }
    }
}

void func_08105090(void) {
    MsCard* card;
    s16 i;
    s32 v;

    card = func_08104B2C();

    if (func_08104AA4(gUnk_02035C18) > 0) {
        LoadPalette(gUnk_09A3DD7C + card->unk_04 * 0x20, (void*)0x050000E0, 0x0C);
    }

    if ((s16)gUnk_02035C16 == 1) {
        for (i = 0; i < 10; i++) {
            func_08101588(0, gUnk_09A1DF7C, (u8*)GetBgCharBase(0) + (i * 0x40 + 0x340), 0x20, 2);
            LoadPalette(gUnk_09A3DE08, (void*)(0x050000EC + i * 2), 2);
        }
    } else if (card->unk_04 == 3) {
        if (func_08104AA4(gUnk_02035C18) > 0) {
            LoadBgMap(1, gUnk_09A3BD5C, 0x500);
        }

        for (i = 0; i < 10; i++) {
            v = card->unk_06[i][0];
            if (v != 0 && func_08104AA4(gUnk_02035C18) > 0) {
                func_08101588(v, gUnk_09A1DF9C, (u8*)GetBgCharBase(0) + 0x340, 0x20, 2);
                LoadPalette(gUnk_09A3DD88, (void*)0x050000EC, 2);
                break;
            }
        }

        if (i > 9) {
            func_08101588(0, gUnk_09A1DF7C, (u8*)GetBgCharBase(0) + 0x340, 0x20, 2);
            LoadPalette(gUnk_09A3DE08, (void*)0x050000EC, 2);
        }
    } else {
        if (func_08104AA4(gUnk_02035C18) > 0) {
            LoadBgMap(1, gUnk_09A3B85C, 0x500);
        }

        for (i = 0; i < 10; i++) {
            v = card->unk_06[i][0];
            if (v != 0 && func_08104AA4(gUnk_02035C18) > 0) {
                func_08101588(v, gUnk_09A1DF9C, (u8*)GetBgCharBase(0) + (i * 0x40 + 0x340), 0x20, 2);
                LoadPalette(gUnk_09A3DD88, (void*)(0x050000EC + i * 2), 2);
            } else {
                func_08101588(0, gUnk_09A1DF7C, (u8*)GetBgCharBase(0) + (i * 0x40 + 0x340), 0x20, 2);
                LoadPalette(gUnk_09A3DE08, (void*)(0x050000EC + i * 2), 2);
            }
        }
    }
}

void func_081052C8(s16 a) {
    s16 t;
    void* base;

    t = 4 - a;
    base = GetBgScreenBase(0);
    func_0800448C(gUnk_09A3B75C, base, t % 3 * 10, t / 3 * 2, 20, 2, 10, 2);
}

void func_08105334(void) {
    MsCard* card;
    u16 id;
    s16 i;

    card = func_08104B2C();

    if (card->unk_06[func_08104EB4()][0] > 0) {
        id = card->unk_06[func_08104EB4()][1];

        if (card->unk_2E != 0) {
            id |= 0x8000;
        }

        for (i = 0; i < gCardCount; i++) {
            if (gCardCollection[i] == id) {
                func_0810155C(func_08104ED8(func_08104AEC()));
                gUnk_02035C30[card->unk_04]--;
                gUnk_02035C3A--;
                gUnk_02035C3C--;
                card->unk_06[func_08104EB4()][0]--;
                func_080850B0(&gCardCollection[i]);
                break;
            }
        }
    }
}

u8 func_08105404(MsCard* card) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (card->unk_06[i][0] > 0) {
            break;
        }
    }

    if (i > 9) {
        return 1;
    }
    return 0;
}

u8 func_08105440(MsCard* card) {
    if (card->unk_06[func_08104EB4()][0] == 0) {
        return 1;
    }
    return 0;
}

void func_08105464(MsCard* card) {
    s16 k;
    s16 n;

    k = func_08104EB4();

    for (n = 0; n < 10; n++) {
        if (card->unk_06[k][0] > 0) {
            break;
        }
        k++;
        if (k > 9) {
            k = 0;
        }
    }
    gUnk_02035E0C = k / 5;
    gUnk_02035E0E = k % 5;
}

void func_081054D0(MsCard* card) {
    vu32* dma;
    MsCard* last;
    u16* p;
    u16 zero;
    u8 slot;
    s16 j;

    slot = gCardDefs[card->unk_02].unk_2A;
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)(card + 1);
    dma[1] = (u32)card;
    dma[2] = ((285 - func_08104AEC()) * 26) | 0x80000000;
    dma[2];
    p = &zero;
    *p = 0;
    dma[0] = (u32)p;
    last = &gUnk_02035C10[285];
    dma[1] = (u32)last;
    dma[2] = 0x8100001A;
    dma[2];
    last->unk_00 = 0x8F;

    for (j = slot + 1; j <= 3; j++) {
        gUnk_02035C20[j]--;
    }
    gUnk_02035C28[slot]--;

    if (func_08104AEC() >= func_08104AA4(gUnk_02035C18)) {
        gUnk_02035CE0--;
        if (gUnk_02035CE0 < 0) {
            gUnk_02035CE0 = 2;
            gUnk_02035CE2--;
            if (gUnk_02035CE2 < 0) {
                gUnk_02035CE2 = 0;
                gUnk_02035CE4--;
                if (gUnk_02035CE4 < 0) {
                    gUnk_02035CE0 = 0;
                    gUnk_02035CE4 = 0;
                }
            }
        }
    }
    gUnk_02035E0C = 0;
    gUnk_02035E0E = 0;
}

s32 func_081055E8(u16 id, u8 flag, s16 count) {
    s16 i;

    for (i = 0; i < count; i++) {
        if (gUnk_02035C10[i].unk_00 == id && gUnk_02035C10[i].unk_2E == flag) {
            return i;
        }
    }
    return -1;
}

#ifdef NON_MATCHING
void func_0810563C(void) {
    MsCard tmp;
    vu32* dma;
    MsCardDef* def;
    MsCard* e;
    u16* p;
    s16* q;
    s16 a;
    u16 zero;
    s16 n;
    u16 id;
    s16 i;
    u16 raw;
    u16 kind;
    u16 flags;
    u32 sortKey;
    u8 slot;
    u8 k;
    u8 prem;
    s16 j;
    s16 idx;

    p = &zero;
    *p = 0;
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)p;
    dma[1] = (u32)gUnk_02035C10;
    dma[2] = 0x81001D0C;
    dma[2];

    for (n = 0; n <= 285; n++) {
        gUnk_02035C10[n].unk_00 = 0x8F;
        gUnk_02035C10[n].unk_02 = 0x3B6;
        gUnk_02035C10[n].unk_2E = 0;
    }
    a = func_08084BAC();
    gUnk_02035C3C = a;
    q = &gUnk_02035C38;
    *q = func_08084BF0();

    for (i = 0; i < 4; i++) {
        gUnk_02035C20[i] = 0;
        gUnk_02035C30[i] = 0;
        gUnk_02035C28[i] = 0;
    }
    gUnk_02035C3A = 0;
    n = 0;

    for (i = 0; i < gCardCount; i++) {
        raw = gCardCollection[i];
        id = raw & CARD_ID_MASK;
        if (raw != CARD_ID_MASK && (raw & 0x7000) == 0 && id <= 0x21C) {
            def = &gCardDefs[id];
            slot = def->unk_2A;
            kind = def->unk_1C;
            flags = raw & 0x8000;
            prem = flags != 0;
            gUnk_02035C30[slot]++;
            gUnk_02035C3A++;
            idx = func_081055E8(kind, prem, n);
            if (idx >= 0) {
                k = def->unk_20;
                gUnk_02035C10[idx].unk_06[k][0]++;
                gUnk_02035C10[idx].unk_06[k][1] = id;
            } else {
                gUnk_02035C10[n].unk_00 = kind;
                gUnk_02035C10[n].unk_02 = def->unk_28;
                gUnk_02035C10[n].unk_04 = slot;
                k = def->unk_20;
                gUnk_02035C10[n].unk_06[k][0]++;
                gUnk_02035C10[n].unk_06[k][1] = id;
                gUnk_02035C10[n].unk_2E = prem;
                sortKey = 0x00100000;

                if (prem != 0) {
                    sortKey = 0x03000000;
                }
                gUnk_02035C10[n].unk_30 = (sortKey << (gUnk_02035C10[n].unk_04 * 2)) | gUnk_02035C10[n].unk_02;
                gUnk_02035C28[slot]++;
                n++;
            }
        }
    }

    for (i = 1; i < 4; i++) {
        gUnk_02035C20[i] = gUnk_02035C28[i - 1] + gUnk_02035C20[i - 1];
    }

    for (i = 1; i < n; i++) {
        memcpy(&tmp, &gUnk_02035C10[i], sizeof(MsCard));

        for (j = i - 1; j >= 0; j--) {
            e = &gUnk_02035C10[j];
            if (e->unk_30 <= tmp.unk_30) {
                break;
            }
            memcpy(e + 1, e, sizeof(MsCard));
        }
        memcpy(&gUnk_02035C10[j + 1], &tmp, sizeof(MsCard));
    }
}
#else
INCLUDE_ASM("unk_08104a84/func_0810563C.s");
#endif

s32 func_0810592C(void) {
    s32 keys;

    keys = GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    return keys | (GetKeysRepeat() & (DPAD_ANY | L_BUTTON | R_BUTTON));
}

void func_0810594C(void) {
    s16 oldCE0;
    s16 oldCE2;
    s16 oldCE4;
    u16 keys;

    oldCE0 = gUnk_02035CE0;
    oldCE2 = gUnk_02035CE2;
    oldCE4 = gUnk_02035CE4;
    keys = func_0810592C();
    if (keys & 1) {
        func_08104B48();
        m4aSongNumStart(0x66);
        AnimStart(&gUnk_02035C68, 0, 1);
        gUnk_02035CBA = 1;
        gUnk_02035C16 = 2;
        func_08104F2C();
    } else if (keys & 2) {
        m4aSongNumStart(0x68);
        gUnk_02035E20 = 1;
        func_08006184(0, 0x10);
        gUnk_02035C14 = 2;
    } else if (keys & 8) {
        m4aSongNumStart(0x68);
        gUnk_02035E20 = 0;
        func_08006184(0, 0x10);
        gUnk_02035C14 = 2;
    } else if (keys & 4) {
        gUnk_02035CE0 = 0;
        gUnk_02035CE2 = 0;
        gUnk_02035CE4 = 0;
        gUnk_02035CBA = 0;
        m4aSongNumStart(0x79);
        gUnk_02035C16 = 1;
        func_08105090();
    } else if (keys & 0x40) {
        if (gUnk_02035CE2 > 0) {
            gUnk_02035CE2--;
        } else if (gUnk_02035CE4 > 0) {
            gUnk_02035CE4--;
        } else {
            gUnk_02035CBA = 0;
            m4aSongNumStart(0x79);
            gUnk_02035C16 = 1;
            func_08105090();
        }
    } else if (keys & 0x80) {
        if ((gUnk_02035CE4 + gUnk_02035CE2 + 1) * 3 + gUnk_02035CE0 < func_08104AA4(gUnk_02035C18)) {
            if (gUnk_02035CE2 <= 2) {
                gUnk_02035CE2++;
            } else {
                gUnk_02035CE4++;
            }
        } else if (gUnk_02035CE2 == 3) {
            if ((gUnk_02035CE4 + gUnk_02035CE2 + 1) * 3 < func_08104AA4(gUnk_02035C18)) {
                gUnk_02035CE0 = (func_08104AA4(gUnk_02035C18) - 1) % 3;
                gUnk_02035CE4++;
            }
        }
    } else if (keys & 0x20) {
        if (gUnk_02035CE0 > 0) {
            gUnk_02035CE0--;
        }
    } else if (keys & 0x10) {
        if ((gUnk_02035CE4 + gUnk_02035CE2) * 3 + gUnk_02035CE0 + 1 < func_08104AA4(gUnk_02035C18)) {
            if (gUnk_02035CE0 <= 1) {
                gUnk_02035CE0++;
            }
        }
    }

    if (gUnk_02035CE0 != oldCE0 || gUnk_02035CE2 != oldCE2 || gUnk_02035CE4 != oldCE4) {
        func_08104B48();
        func_08105090();
        func_08104F2C();
        func_08104D18();
        m4aSongNumStart(0x79);

        if (gUnk_02035CE4 != oldCE4) {
            func_08104BBC();
        }
    }
}

void func_08105BD8(void) {
    s16 old;
    u16 keys;

    old = gUnk_02035C18;
    keys = func_0810592C();
    if ((keys & 1) == 0) {
        if (keys & 8) {
            m4aSongNumStart(0x68);
            gUnk_02035E20 = 0;
            func_08006184(0, 0x10);
            gUnk_02035C14 = 2;
        } else if (keys & 0x82) {
            if (func_08104AA4(gUnk_02035C18) > 0) {
                gUnk_02035CE0 = 0;
                gUnk_02035CE2 = 0;
                gUnk_02035CE4 = 0;
                AnimStart(&gUnk_02035C68, 2, 1);
                gUnk_02035CBA = 0;
                m4aSongNumStart(0x79);
                gUnk_02035C16 = 0;
                func_08104B48();
                func_08105090();
                func_08104D18();
            } else if (keys & 2) {
                m4aSongNumStart(0x68);
                gUnk_02035E20 = 1;
                func_08006184(0, 0x10);
                gUnk_02035C14 = 2;
            } else if (keys & 0x80) {
                m4aSongNumStart(0x69);
            }
        } else if (keys & 0x20) {
            if (gUnk_02035C18 > 0) {
                gUnk_02035C18--;
            }
        } else if (keys & 0x10) {
            if (gUnk_02035C18 <= 3) {
                gUnk_02035C18++;
            }
        }
    }

    if (gUnk_02035C18 != old) {
        func_081052C8(gUnk_02035C18);
        func_08104BBC();
        m4aSongNumStart(0x65);
    }
}

s32 func_08105D24(MsCard* card, u16 col) {
    s16 base;
    s16 i;
    s32 r;
    s32 found;

    found = 0;
    base = gUnk_02035E0E;

    for (i = 0; i <= 4; i++) {
        r = base - i;
        if (r >= 0 && card->unk_06[func_08104E9C(col, r)][0] > 0) {
            gUnk_02035E0C = col;
            gUnk_02035E0E = r;
            found = 1;
            break;
        }
        r = base + i;
        if (r <= 4 && card->unk_06[func_08104E9C(col, r)][0] > 0) {
            gUnk_02035E0C = col;
            gUnk_02035E0E = r;
            found = 1;
            break;
        }
    }
    return found;
}

void func_08105DE0(void) {
    MsCard* card;
    s16 oldCol;
    s16 oldRow;
    u16 keys;
    s16 i;

    card = func_08104B2C();
    oldCol = gUnk_02035E0C;
    oldRow = gUnk_02035E0E;
    keys = func_0810592C();
    if (keys & 1) {
        if (GetMooglePoints() + func_08104ED8(func_08104AEC()) > 99999) {
            m4aSongNumStart(0x69);
        } else if (gUnk_02035C3C <= 1) {
            EnableBg(2);
            m4aSongNumStart(0x67);
            gUnk_02035C16 = 4;
        } else {
            gUnk_02035E10 = 0;
            gUnk_02035E14 = 0x4800;
            AnimStart(&gUnk_02035CC8, 0, 1);
            EnableBg(2);
            m4aSongNumStart(0x67);
            gUnk_02035C16 = 3;
        }
    } else if (keys & 2) {
        AnimStart(&gUnk_02035C68, 2, 1);
        gUnk_02035CBA = 0;
        m4aSongNumStart(0x68);
        gUnk_02035C16 = 0;
        func_08104F2C();
    } else if (keys & 8) {
        m4aSongNumStart(0x68);
        gUnk_02035E20 = 0;
        func_08006184(0, 0x10);
        gUnk_02035C14 = 2;
    } else if (keys & 0x20) {
        func_08105D24(card, 0);
    } else if (keys & 0x10) {
        func_08105D24(card, 1);
    } else if (keys & 0x40) {
        for (i = 0; i <= 4; i++) {
            gUnk_02035E0E--;
            if (gUnk_02035E0E < 0) {
                gUnk_02035E0E = 4;
            }

            if (card->unk_06[func_08104EB4()][0] > 0) {
                break;
            }
        }
    } else if (keys & 0x80) {
        for (i = 0; i <= 4; i++) {
            gUnk_02035E0E++;
            if (gUnk_02035E0E > 4) {
                gUnk_02035E0E = 0;
            }

            if (card->unk_06[func_08104EB4()][0] > 0) {
                break;
            }
        }
    }

    if (card->unk_04 == 3) {
        gUnk_02035E0C = oldCol;
        gUnk_02035E0E = oldRow;
    }

    if (gUnk_02035E0C != oldCol || gUnk_02035E0E != oldRow) {
        func_08104F2C();
        m4aSongNumStart(0x65);
    }
}

void func_0810601C(void) {
    MsCard* card;
    s16 old;
    u16 keys;

    card = func_08104B2C();
    old = gUnk_02035E10;
    keys = func_0810592C();
    if (keys & 1) {
        DisableBg(2);

        if (gUnk_02035E10 == 0) {
            gUnk_02035CBC = 180;
            func_08105334();
            m4aSongNumStart(0xD2);

            if (func_08105404(card)) {
                func_081054D0(card);
                func_08104BBC();
                func_08104D18();

                if (func_08104AA4(gUnk_02035C18) > 0) {
                    AnimStart(&gUnk_02035C68, 2, 1);
                    gUnk_02035CBA = 0;
                    gUnk_02035C16 = 0;
                } else {
                    gUnk_02035CBA = 0;
                    gUnk_02035C16 = 1;
                }
            } else {
                if (func_08105440(card)) {
                    func_08105464(card);
                }
                AnimStart(&gUnk_02035C68, 0, 1);
                gUnk_02035CBA = 1;
                gUnk_02035C16 = 2;
            }
            func_08104F2C();
            func_08105090();
            func_08104FA4();
            func_08104FF8();
        } else {
            m4aSongNumStart(0x68);
            AnimStart(&gUnk_02035C68, 0, 1);
            gUnk_02035CBA = 1;
            gUnk_02035C16 = 2;
        }
    } else if (keys & 2) {
        DisableBg(2);
        m4aSongNumStart(0x68);
        AnimStart(&gUnk_02035C68, 0, 1);
        gUnk_02035CBA = 1;
        gUnk_02035C16 = 2;
    } else if (keys & 8) {
        m4aSongNumStart(0x68);
        gUnk_02035E20 = 0;
        func_08006184(0, 0x10);
        gUnk_02035C14 = 2;
    } else if (keys & 0x20) {
        gUnk_02035E10 = 0;
    } else if (keys & 0x10) {
        gUnk_02035E10 = 1;
    }

    if (gUnk_02035E10 != old) {
        m4aSongNumStart(0x65);
    }
}

void func_081061DC(void) {
    u16 keys;

    keys = func_0810592C();
    if (keys & 3) {
        DisableBg(2);
        m4aSongNumStart(0x68);
        gUnk_02035C16 = 2;
    } else if (keys & 8) {
        m4aSongNumStart(0x68);
        gUnk_02035E20 = 0;
        func_08006184(0, 0x10);
        gUnk_02035C14 = 2;
    }
}

void func_08106234(void) {
    MsCard* card;
    void* anim;
    s32 sine;
    s16 t;
    s16 v;
    s16 col;
    s16 row;
    s32 i;
    s32 j;

    if ((s16)gUnk_02035C16 != 1) {
        DrawSprite(16, 60, AnimUpdate(&gUnk_02035C50), gUnk_02035C48, gUnk_02035C44, 0, 0x800, 0x7D0);
    }
    t = (func_08104AA4(gUnk_02035C18) + 2) / 3 - 4;
    if (gUnk_02035CE4 <= t) {
        v = 84 * gUnk_02035CE4 / t;
    } else {
        v = 0;
    }
    DrawSprite(160, v + 40, gUnk_099A7C64, gUnk_02035C40, gUnk_02035D90, 0, 0x800, 0x898);
    DrawSprite(24, 58, AnimUpdate(&gUnk_02035CA0), gUnk_02035C84, gUnk_02035C80, 0, 0x801, 0x834);

    if (gUnk_02035C14 == 1) {
        switch ((s16)gUnk_02035C16) {
        case 1:
            gUnk_02035E18 = gUnk_02035C18 * 3584 + 0xAC00;
            gUnk_02035E1C = 0x1000;
            DrawSprite(gUnk_02035E18 >> 8, (gUnk_02035E1C >> 8) + ((sine = gSineTable[gUnk_02035CB8]) >> 6), AnimUpdate(&gUnk_02035C88), gUnk_02035C84, gUnk_02035C80, 0, 0x801, 0x7D0);
            break;
        case 0:
            func_0805F1C0(&gUnk_02035E18, (gUnk_02035CE0 * 23 + 181) << 8);
            func_0805F1C0(&gUnk_02035E1C, (gUnk_02035CE2 * 26 + 40) << 8);
            DrawSprite(gUnk_02035E18 >> 8, (gUnk_02035E1C >> 8) + ((sine = gSineTable[gUnk_02035CB8]) >> 6), AnimUpdate(&gUnk_02035C88), gUnk_02035C84, gUnk_02035C80, 0, 0x801, 0x7D0);
            DrawSprite(gUnk_02035CE0 * 23 + 165, gUnk_02035CE2 * 26 + 27, AnimUpdate(&gUnk_02035C68), gUnk_02035C48, gUnk_02035C44, 0, 0x800, 0x7DA);
            break;
        case 2:
            card = func_08104B2C();
            if (card->unk_04 == 3) {
                col = 0;
                row = 0;
            } else {
                col = gUnk_02035E0C;
                row = gUnk_02035E0E;
            }
            func_0805F1C0(&gUnk_02035E18, (col * 48 + 64) << 8);
            func_0805F1C0(&gUnk_02035E1C, (row * 8 + 64) << 8);
            DrawSprite(gUnk_02035E18 >> 8, (gUnk_02035E1C >> 8) + ((sine = gSineTable[gUnk_02035CB8]) >> 6), AnimUpdate(&gUnk_02035C88), gUnk_02035C84, gUnk_02035C80, 0, 0x801, 0x7D0);
            DrawSprite(col * 48 + 53, row * 8 + 67, AnimUpdate(&gUnk_02035C68), gUnk_02035C48, gUnk_02035C44, 0, 0x800, 0x7DA);
            break;
        case 3:
            func_0805F1C0(&gUnk_02035E14, gUnk_02035E10 == 0 ? 0x4800 : 0x8800);
            DrawSprite(gUnk_02035E14 >> 8, 98, AnimUpdate(&gUnk_02035CC8), gUnk_02035CC4, gUnk_02035CC0, 0, 1, 0);

            if (gUnk_02035DF0 != 0) {
                func_080664D8(120 - func_08065B08(gUnk_02035DEC, gUnk_02035DF0) / 2, 60, gUnk_02035DEC, gUnk_02035C80, 1, gUnk_02035DF0);
            }

            if (gUnk_02035E00 != 0) {
                func_080664D8(80, 88, gUnk_02035DFC, gUnk_02035C80, 1, gUnk_02035E00);
            }

            if (gUnk_02035E08 != 0) {
                func_080664D8(144, 88, gUnk_02035E04, gUnk_02035C80, 1, gUnk_02035E08);
            }
            break;
        case 4:
            if (gUnk_02035DF8 != 0) {
                func_080664D8(120 - func_08065B08(gUnk_02035DF4, gUnk_02035DF8) / 2, 74, gUnk_02035DF4, gUnk_02035C80, 1, gUnk_02035DF8);
            }
            break;
        }
    }
    anim = AnimUpdate(&gUnk_02035DC0);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (gUnk_02035D48[i][j] != 0) {
                DrawSprite(j * 23 + 181, i * 26 + 47, gUnk_02035D48[i][j], gUnk_02035D18[i][j], gUnk_02035CE8[i][j], 0, 0x800, 0x83E);

                if (gUnk_02035D78[i][j] != 0) {
                    DrawSprite(j * 23 + 181, i * 26 + 47, anim, gUnk_02035DB8, gUnk_02035D90, 0, 0x800, 0x834);
                }
            }
        }
    }

    if ((s16)gUnk_02035C16 != 1) {
        if (gUnk_02035D8C != 0) {
            DrawSprite(24, 92, gUnk_02035D8C, gUnk_02035D88, gUnk_02035D84, 0, 0x800, 0x848);
        }

        if (gUnk_02035D98 != 0) {
            DrawSprite(24, 92, gUnk_02035D98, gUnk_02035D94, gUnk_02035D90, 0, 0x800, 0x83E);

            if (gUnk_02035DD8 != 0) {
                DrawSprite(24, 92, AnimUpdate(&gUnk_02035DA0), gUnk_02035D9C, gUnk_02035D90, 0, 0x800, 0x834);
            }
        }

        if (gUnk_02035DE0 != 0) {
            func_080664D8(12, 115, gUnk_02035DDC, gUnk_02035C44, 1, gUnk_02035DE0);
        }

        if (gUnk_02035DE8 != 0) {
            func_080664D8(6, 131, gUnk_02035DE4, gUnk_02035C80, 1, gUnk_02035DE8);
        }
    }
}
