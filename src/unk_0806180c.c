#include "macros.h"
#include "unk_0806180c.h"

INCLUDE_ASM("unk_0806180c/func_0806180C.s");
INCLUDE_ASM("unk_0806180c/func_08061824.s");
INCLUDE_ASM("unk_0806180c/func_08061FC8.s");
INCLUDE_ASM("unk_0806180c/func_0806250C.s");
INCLUDE_ASM("unk_0806180c/func_0806297C.s");
INCLUDE_ASM("unk_0806180c/func_080629CC.s");
INCLUDE_ASM("unk_0806180c/func_080629F8.s");
INCLUDE_ASM("unk_0806180c/func_08062CE4.s");
INCLUDE_ASM("unk_0806180c/func_08062D20.s");
INCLUDE_ASM("unk_0806180c/func_08062D3C.s");
INCLUDE_ASM("unk_0806180c/func_08062D64.s");
INCLUDE_ASM("unk_0806180c/func_08062DC8.s");
INCLUDE_ASM("unk_0806180c/func_08062F18.s");
INCLUDE_ASM("unk_0806180c/func_08063034.s");
INCLUDE_ASM("unk_0806180c/func_080634C4.s");
INCLUDE_ASM("unk_0806180c/func_080635C4.s");
INCLUDE_ASM("unk_0806180c/func_08063658.s");
INCLUDE_ASM("unk_0806180c/func_08063678.s");
INCLUDE_ASM("unk_0806180c/func_08063744.s");
INCLUDE_ASM("unk_0806180c/func_08063EE4.s");
INCLUDE_ASM("unk_0806180c/func_08063F60.s");
INCLUDE_ASM("unk_0806180c/func_080640E0.s");
INCLUDE_ASM("unk_0806180c/func_080641CC.s");
INCLUDE_ASM("unk_0806180c/func_080641E8.s");
INCLUDE_ASM("unk_0806180c/func_0806420C.s");
INCLUDE_ASM("unk_0806180c/func_0806422C.s");
INCLUDE_ASM("unk_0806180c/func_080642A8.s");
INCLUDE_ASM("unk_0806180c/func_08064338.s");
INCLUDE_ASM("unk_0806180c/func_080643D4.s");
INCLUDE_ASM("unk_0806180c/func_08064624.s");
INCLUDE_ASM("unk_0806180c/func_08064B68.s");
INCLUDE_ASM("unk_0806180c/func_08064B80.s");
INCLUDE_ASM("unk_0806180c/func_08064C34.s");
INCLUDE_ASM("unk_0806180c/func_08064D04.s");
INCLUDE_ASM("unk_0806180c/func_08064DD4.s");
INCLUDE_ASM("unk_0806180c/func_08064EF4.s");
INCLUDE_ASM("unk_0806180c/func_08065170.s");
INCLUDE_ASM("unk_0806180c/func_080653D4.s");

void func_080658B8(u8 n) {
    u8 i;

    for (i = 0; i < n; i++) {
        Ent080658B8* b = gUnk_02034A84;

        if (b[i].unk_15 == 1) {
            s32 x = b[i].unk_00;
            s32 y = b[i].unk_04;

            if (b[i].unk_14 != 0) {
                if (b[i].unk_08 != NULL) {
                    func_08002488(x >> 8, y >> 8, gUnk_09EEB204, b[i].unk_08, b[i].unk_10, 0);
                }
            } else {
                if (b[i].unk_08 != NULL) {
                    func_08002488(x >> 8, y >> 8, gUnk_09EEB204, b[i].unk_08, b[i].unk_0C, 0);
                }
            }
        }
    }
}

void func_08065940(void) {
    u8 i;

    for (i = 0; i < 128; i++) {
        if (gUnk_02034A84[i].unk_08 != NULL) {
            ReleaseObjTiles(gUnk_02034A84[i].unk_08);
        }

        if (gUnk_02034A84[i].unk_0C != NULL) {
            ReleaseObjPalette(gUnk_02034A84[i].unk_0C);
        }

        if (gUnk_02034A84[i].unk_10 != NULL) {
            ReleaseObjPalette(gUnk_02034A84[i].unk_10);
        }
    }
    EwramFree(gUnk_02034A84);
}

void _08065994(void) {
    u8 i;

    for (i = 0; i < 128; i++) {
        gUnk_02034A84[i].unk_15 = 0;
    }
}
u16 func_080659BC(u8 v, TextSlot* out) {
    u8 buf[8];
    u8 q;

    q = v / 10;
    if (q != 0) {
        buf[1] = v / 10;
        buf[3] = v - buf[1] * 10;
        buf[0] = 0x82;
        buf[1] += 0x4F;
        buf[2] = 0x82;
        buf[3] += 0x4F;
        buf[4] = 0;
    } else {
        buf[1] = v + 0x4F;
        buf[0] = 0x82;
        buf[2] = 0;
    }
    return func_080660C0(buf, out);
}
void func_08065A30(void** p, u8 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        *p++ = NULL;
    }
}
void func_08065A44(void** p, u8 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (*p != NULL) {
            ReleaseObjTiles(*p);
            *p = NULL;
        }
        p++;
    }
}
u16 func_08065A70(u8 v, TextSlot* out) {
    u16 buf[4];
    u16* p;
    u8 q;
    u16 c;
    u16 end;

    if (v > 9) {
        p = buf;
        q = v / 10;
        c = q + '0';
        end = 0;
        p[0] = c;
        buf[1] = v - q * 10 + '0';
        buf[2] = end;
    } else {
        buf[0] = v + '0';
        buf[1] = 0;
    }
    return func_08065B6C(buf, out);
}

void func_08065ACC(TextSlot* p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        p->unk_00 = NULL;
        p->unk_05 = 0;
        p++;
    }
}

void func_08065AE0(TextSlot* p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (p->unk_00 != NULL) {
            ReleaseObjTiles(p->unk_00);
            p->unk_00 = NULL;
        }
        p->unk_05 = 0;
        p++;
    }
}

#ifdef NON_MATCHING
s16 func_08065B08(TextSlot* p, u8 n) {
    s16 x;
    s32 i;

    x = 0;
    for (i = 0; i < n; i++) {
        if (p[i].unk_00 == NULL) {
            return x;
        }

        if (p[i].unk_05 == -1) {
            x += 3;
        } else {
            x += p[i].unk_05;
        }
    }
    return x;
}
#else
INCLUDE_ASM("unk_0806180c/func_08065B08.s");
#endif

#ifndef VERSION_JP
s32 func_08065B54(u16* s) {
    u16 n = 0;
    u16* p = s;

    while (*p != 0) {
        n++;
        p++;
    }
    return n;
}
#else
INCLUDE_ASM("unk_0806180c/func_08065B54.s");
#endif

#ifndef VERSION_JP
u16 func_08065B6C(u16* a, TextSlot* b) {
    return func_08065B7C(a, b);
}
#else
INCLUDE_ASM("unk_0806180c/func_08065B6C.s");
#endif

INCLUDE_ASM("unk_0806180c/func_08065B7C.s");
INCLUDE_ASM("unk_0806180c/func_08065D10.s");
INCLUDE_ASM("unk_0806180c/func_080660C0.s");
INCLUDE_ASM("unk_0806180c/_08066468.s");
INCLUDE_ASM("unk_0806180c/func_080664D8.s");
INCLUDE_ASM("unk_0806180c/func_08066588.s");
INCLUDE_ASM("unk_0806180c/func_0806662C.s");
INCLUDE_ASM("unk_0806180c/func_080666F0.s");
INCLUDE_ASM("unk_0806180c/func_080667D8.s");
INCLUDE_ASM("unk_0806180c/func_08066864.s");

void* func_080668F0(void) {
    return LoadObjTiles(gUnk_090D4180, 0x5A0);
}

void* func_08066904(void) {
    return LoadObjPalette(gUnk_08F69BE4, 0x20);
}

void func_08066918(void* a, void* b) {
    ReleaseObjTiles(a);
    ReleaseObjPalette(b);
}

u16 func_0806692C(u8* s, u16* out) {
    u16 g = 0;
    u8 n;
    u8 i;

    if (out == NULL) {
        return 0;
    }
    n = func_0809D280(s);
    for (i = 0; i < n; i++) {
        if ((u8)(s[i] - '0') <= 9) {
            g = s[i] - '0';
        }

        if ((u8)(s[i] - 'A') <= 25) {
            g = s[i] - 0x37;
        }

        if ((u8)(s[i] - 'a') <= 25) {
            g = s[i] - 0x57;
        }

        if (s[i] == '/') {
            g = 0x24;
        }

        if (s[i] == '-') {
            g = 0x25;
        }

        if (s[i] == '_') {
            g = 0x26;
        }

        if (s[i] == '.') {
            g = 0x27;
        }

        if (s[i] == '+') {
            g = 0x28;
        }

        if (s[i] == '!') {
            g = 0x29;
        }

        if (s[i] == '?') {
            g = 0x2A;
        }

        if (s[i] == '#') {
            g = 0x2B;
        }

        if (s[i] == '%') {
            g = 0x2C;
        }
        *out++ = g;
    }
    return n;
}

INCLUDE_ASM("unk_0806180c/_080669DC.s");

u16 func_08066AF8(s32 v, u16* out) {
    u8 buf[11];
    u8* p;
    s32 i;

    buf[0] = '0';
    buf[1] = 'x';
    buf[2] = (v & 0xF0000000) >> 28;
    buf[3] = (v & 0x0F000000) >> 24;
    buf[4] = (v & 0x00F00000) >> 20;
    buf[5] = (v & 0x000F0000) >> 16;
    buf[6] = (v & 0x0000F000) >> 12;
    buf[7] = (v & 0x00000F00) >> 8;
    buf[8] = (v & 0x000000F0) >> 4;
    buf[9] = v & 0xF;
    buf[10] = 0;
    p = &buf[2];
    for (i = 0; i < 8; i++) {
        if (*p <= 9) {
            *p += 0x30;
        } else {
            *p += 0x37;
        }
        p++;
    }
    return func_0806692C(buf, out);
}

INCLUDE_ASM("unk_0806180c/_08066B84.s");
INCLUDE_ASM("unk_0806180c/func_08066DC0.s");
INCLUDE_ASM("unk_0806180c/func_08066E40.s");

void func_0806BA0C(s16 v, u8* out) {
    s16 acc = 0;
    s16 div;
    s16 i;

    if (v >= 0) {
        div = 1000;
        for (i = 0; i < 4; i++) {
            u8* q = &out[i];
            *q = v / div - acc;
            acc = (acc + *q) * 10;
            div /= 10;
        }
    }
}

u16 func_0806BA74(s32 mode, s32 flag) {
    s32 i;

    gUnk_02034A88 = EwramAlloc(0xC00);
    for (i = 0; i < 128; i++) {
        gUnk_02034A88[i].unk_00 = 0;
        gUnk_02034A88[i].unk_04 = 0;
        gUnk_02034A88[i].unk_08 = NULL;
        gUnk_02034A88[i].unk_0C = NULL;
        gUnk_02034A88[i].unk_10 = NULL;
        gUnk_02034A88[i].unk_15 = 0;
        switch (mode) {
        case 0:
            gUnk_02034A88[i].unk_0C = LoadObjPalette(gUnk_09614758, 0x20);
            break;
        case 1:
            gUnk_02034A88[i].unk_0C = LoadObjPalette(gUnk_09614718, 0x20);
            break;
        case 2:
            gUnk_02034A88[i].unk_0C = LoadObjPalette(gUnk_09614738, 0x20);
            break;
        }

        if (flag == 0) {
            gUnk_02034A88[i].unk_10 = _08066468(3);
        } else {
            gUnk_02034A88[i].unk_10 = _08066468(5);
        }
        func_080062F4(gUnk_02034A88[i].unk_0C->unk_06 + 0x10, 1);
        func_080062F4(gUnk_02034A88[i].unk_10->unk_06 + 0x10, 1);
    }
    gUnk_02034A90 = 0;
    return gUnk_02034A88[0].unk_0C->unk_06;
}

INCLUDE_ASM("unk_0806180c/func_0806BB44.s");
INCLUDE_ASM("unk_0806180c/func_0806BDB8.s");

void func_0806C2C0(u8 n) {
    u8 i;

    for (i = 0; i < n; i++) {
        Ent080658B8* b = gUnk_02034A88;

        if (b[i].unk_15 == 1) {
            s32 x = b[i].unk_00;
            s32 y = b[i].unk_04;

            if (b[i].unk_08 != NULL) {
                if (b[i].unk_14 == 0) {
                    DrawSprite(x >> 8, y >> 8, gUnk_09EEB204, b[i].unk_08, b[i].unk_0C, 0, 0, 0);
                } else {
                    DrawSprite(x >> 8, y >> 8, gUnk_09EEB204, b[i].unk_08, b[i].unk_10, 0, 0, 0);
                }
            }
        }
    }
}

void func_0806C34C(void) {
    u8 i;

    for (i = 0; i < 128; i++) {
        if (gUnk_02034A88[i].unk_08 != NULL) {
            ReleaseObjTiles(gUnk_02034A88[i].unk_08);
        }

        if (gUnk_02034A88[i].unk_0C != NULL) {
            ReleaseObjPalette(gUnk_02034A88[i].unk_0C);
        }

        if (gUnk_02034A88[i].unk_10 != NULL) {
            ReleaseObjPalette(gUnk_02034A88[i].unk_10);
        }
    }
    EwramFree(gUnk_02034A88);
}

INCLUDE_ASM("unk_0806180c/_0806C3A0.s");
INCLUDE_ASM("unk_0806180c/func_0806C42C.s");
INCLUDE_ASM("unk_0806180c/func_0806C490.s");
INCLUDE_ASM("unk_0806180c/func_0806C81C.s");
INCLUDE_ASM("unk_0806180c/func_0806CBAC.s");
INCLUDE_ASM("unk_0806180c/func_0806CD30.s");
INCLUDE_ASM("unk_0806180c/func_0806CD60.s");
INCLUDE_ASM("unk_0806180c/func_0806CF04.s");
INCLUDE_ASM("unk_0806180c/func_0806D0A8.s");
INCLUDE_ASM("unk_0806180c/func_0806D288.s");
INCLUDE_ASM("unk_0806180c/func_0806D2D0.s");
INCLUDE_ASM("unk_0806180c/func_0806D334.s");
INCLUDE_ASM("unk_0806180c/func_0806D40C.s");
INCLUDE_ASM("unk_0806180c/func_0806D808.s");
INCLUDE_ASM("unk_0806180c/func_0806D830.s");
INCLUDE_ASM("unk_0806180c/func_0806D9E8.s");
INCLUDE_ASM("unk_0806180c/func_0806DA18.s");
INCLUDE_ASM("unk_0806180c/func_0806DA34.s");
INCLUDE_ASM("unk_0806180c/func_0806E184.s");
INCLUDE_ASM("unk_0806180c/func_0806E400.s");
INCLUDE_ASM("unk_0806180c/func_0806E534.s");
INCLUDE_ASM("unk_0806180c/func_0806E570.s");
INCLUDE_ASM("unk_0806180c/func_0806E7A8.s");

void func_0806E9BC(Work0806180C* p) {
    Ent0806E9BC* e = &p->unk_000[p->unk_1A0];

    func_0801CD74(p->unk_028, e->unk_14);
}

u8 _0806E9DC(Work0806180C* p, void* a) {
    p->unk_188 = 0x800;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    func_08000F8C(a, (void*)func_0806EA28);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806EA28.s");
u8 func_0806EB94(Work0806180C* p, void* a) {
    p->unk_188 = 0xC00;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    func_08000F8C(a, (void*)func_0806EBE0);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806EBE0.s");
u8 func_0806ECE0(Work0806180C* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    func_08000F8C(a, (void*)func_0806ED2C);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806ED2C.s");
u8 func_0806EE20(Work0806180C* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    func_08000F8C(a, (void*)func_0806EE6C);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806EE6C.s");
INCLUDE_ASM("unk_0806180c/func_0806EF40.s");
INCLUDE_ASM("unk_0806180c/func_0806F02C.s");
INCLUDE_ASM("unk_0806180c/func_0806F114.s");
INCLUDE_ASM("unk_0806180c/func_0806F204.s");
INCLUDE_ASM("unk_0806180c/func_0806F2EC.s");
INCLUDE_ASM("unk_0806180c/func_0806F3A8.s");
INCLUDE_ASM("unk_0806180c/func_0806F47C.s");
INCLUDE_ASM("unk_0806180c/func_0806F53C.s");
u8 func_0806F610(Work0806180C* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    func_08000F8C(a, (void*)func_0806F64C);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806F64C.s");
u8 func_0806F734(Work0806180C* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    func_08000F8C(a, (void*)func_0806F770);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806F770.s");
u8 func_0806F858(Work0806180C* p, void* a) {
    p->unk_18C = 1;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    func_08000F8C(a, (void*)func_0806F898);
    return 1;
}
INCLUDE_ASM("unk_0806180c/func_0806F898.s");
INCLUDE_ASM("unk_0806180c/func_0806F94C.s");
INCLUDE_ASM("unk_0806180c/func_0806FA84.s");
INCLUDE_ASM("unk_0806180c/func_0806FAB8.s");
INCLUDE_ASM("unk_0806180c/func_0806FB6C.s");
INCLUDE_ASM("unk_0806180c/func_0806FC28.s");
INCLUDE_ASM("unk_0806180c/func_0806FCF4.s");
INCLUDE_ASM("unk_0806180c/func_0806FDB0.s");
INCLUDE_ASM("unk_0806180c/func_0806FE90.s");

void func_08070008(Work0806180C* p) {
    u8 old = p->unk_1AB;

    func_0806FE90(p);
    if (old != p->unk_1AB) {
        if (abs(GetAngleDiff(old, p->unk_1AB)) > 100) {
            p->unk_19C = 0;
        } else {
            p->unk_19C >>= 1;
        }
    }
}

INCLUDE_ASM("unk_0806180c/func_08070058.s");
INCLUDE_ASM("unk_0806180c/func_080700D4.s");
INCLUDE_ASM("unk_0806180c/func_0807048C.s");
INCLUDE_ASM("unk_0806180c/func_08070AD4.s");
INCLUDE_ASM("unk_0806180c/func_08072914.s");

void func_08072918(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x384);
            func_08076110(0x384, x, y);
        } else {
            m4aSongNumStart(0x385);
            func_08076110(0x385, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x389);
            func_08076110(0x389, x, y);
        } else {
            m4aSongNumStart(0x388);
            func_08076110(0x388, x, y);
        }
        break;
    case 2:
        if ((a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) || (a->unk_24 == 0x36 && gUnk_02039DC8->unk_6C <= 0x4F)) {
            if (flag != 0) {
                m4aSongNumStart(0x388);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(0x389);
                func_08076110(0x389, x, y);
            }

            if (flag != 0) {
                m4aSongNumStart(0x388);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(0x389);
                func_08076110(0x389, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x38C);
                func_08076110(0x38C, x, y);
            } else {
                m4aSongNumStart(0x38D);
                func_08076110(0x38D, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x388);
            func_08076110(0x388, x, y);
        } else {
            m4aSongNumStart(0x389);
            func_08076110(0x389, x, y);
        }
        break;
    }
}

void func_08072A64(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x394);
            func_08076110(0x394, x, y);
        } else {
            m4aSongNumStart(0x395);
            func_08076110(0x395, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x391);
            func_08076110(0x391, x, y);
        } else {
            m4aSongNumStart(0x390);
            func_08076110(0x390, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(0x391);
                func_08076110(0x391, x, y);
            } else {
                m4aSongNumStart(0x390);
                func_08076110(0x390, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x398);
                func_08076110(0x398, x, y);
            } else {
                m4aSongNumStart(0x399);
                func_08076110(0x399, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x390);
            func_08076110(0x390, x, y);
        } else {
            m4aSongNumStart(0x391);
            func_08076110(0x391, x, y);
        }
        break;
    }
}

INCLUDE_ASM("unk_0806180c/func_08072B4C.s");
INCLUDE_ASM("unk_0806180c/func_08072C34.s");
INCLUDE_ASM("unk_0806180c/func_08072D98.s");
INCLUDE_ASM("unk_0806180c/func_08072EAC.s");
INCLUDE_ASM("unk_0806180c/func_08073170.s");
INCLUDE_ASM("unk_0806180c/func_08073238.s");
INCLUDE_ASM("unk_0806180c/func_08073274.s");
INCLUDE_ASM("unk_0806180c/func_08073294.s");
INCLUDE_ASM("unk_0806180c/func_08073318.s");
INCLUDE_ASM("unk_0806180c/func_0807344C.s");
INCLUDE_ASM("unk_0806180c/func_08073508.s");
INCLUDE_ASM("unk_0806180c/func_0807361C.s");
INCLUDE_ASM("unk_0806180c/func_080736F8.s");
INCLUDE_ASM("unk_0806180c/func_08073768.s");
INCLUDE_ASM("unk_0806180c/func_0807388C.s");
INCLUDE_ASM("unk_0806180c/func_08073A58.s");
INCLUDE_ASM("unk_0806180c/func_08073AEC.s");
INCLUDE_ASM("unk_0806180c/func_08073B04.s");
INCLUDE_ASM("unk_0806180c/func_08073B54.s");
INCLUDE_ASM("unk_0806180c/func_08073B9C.s");
INCLUDE_ASM("unk_0806180c/func_08073CA4.s");
INCLUDE_ASM("unk_0806180c/func_08073DA4.s");
INCLUDE_ASM("unk_0806180c/func_08073E0C.s");

void func_08073E34(Work08073E34* p, u8 a, u8 b, u8 c) {
    u8 v;

    if (p->unk_00 != a) {
        v = 3;
    } else {
        if (p->unk_01 == b && p->unk_04 == c) {
            return;
        }
        v = 4;
    }
    p->unk_02 = v;
    p->unk_00 = a;
    p->unk_01 = b;
    p->unk_04 = c;
}

void _08073E6C(Work08073E34* p) {
    p->unk_02 = 1;
}
void func_08073E74(Work08073E34* p) {
    p->unk_02 = 2;
}
INCLUDE_ASM("unk_0806180c/func_08073E7C.s");
INCLUDE_ASM("unk_0806180c/func_08073F08.s");
INCLUDE_ASM("unk_0806180c/func_08073F78.s");
INCLUDE_ASM("unk_0806180c/func_08073FB8.s");
INCLUDE_ASM("unk_0806180c/func_08074040.s");
INCLUDE_ASM("unk_0806180c/func_08074068.s");
INCLUDE_ASM("unk_0806180c/func_0807420C.s");
INCLUDE_ASM("unk_0806180c/func_08074330.s");
INCLUDE_ASM("unk_0806180c/func_08074380.s");
INCLUDE_ASM("unk_0806180c/func_080744C8.s");
INCLUDE_ASM("unk_0806180c/func_08074504.s");
INCLUDE_ASM("unk_0806180c/func_08074564.s");
INCLUDE_ASM("unk_0806180c/func_0807457C.s");

void func_080746D8(void) {
    u8 i;

    for (i = 0; i < 16; i++) {
        func_080062F4(i + 16, 0);
    }
}

INCLUDE_ASM("unk_0806180c/_080746F8.s");
void func_08074CF8(void) {
}
void func_08074CFC(void) {
}

void func_08074D00(Work08074DC4* p) {
    gUnk_02039DC8->unk_50 = p->unk_00;
    gUnk_02039DC8->unk_54 = p->unk_04;
}

void func_08074D14(Work08074DC4* a) {
    Obj0806180C* e;
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    e = &a->unk_0C[a->unk_09];
    if (e->unk_14 & 0x2C00) {
        gUnk_02039DC8->unk_48 = x;
        gUnk_02039DC8->unk_4C = y;
    } else {
        gUnk_02039DC8->unk_48 += (x - gUnk_02039DC8->unk_48) >> 3;
        gUnk_02039DC8->unk_4C += (y - gUnk_02039DC8->unk_4C) >> 3;
    }
    gUnk_02039DC8->unk_58 = gUnk_02039DC8->unk_48 + (gUnk_02039DC8->unk_68 << 8);
    gUnk_02039DC8->unk_5C = gUnk_02039DC8->unk_4C + (gUnk_02039DC8->unk_6A << 8);
}

void func_08074D98(Work08074DC4* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_48 = x;
    gUnk_02039DC8->unk_4C = y;
}

void func_08074DC4(Work08074DC4* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    if (a->unk_10 != 0) {
        ApproachValue(&gUnk_02039DC8->unk_48, x, a->unk_10);
        ApproachValue(&gUnk_02039DC8->unk_4C, y, a->unk_10);
        a->unk_10--;
    } else {
        gUnk_02039DC8->unk_48 = x;
        gUnk_02039DC8->unk_4C = y;
    }
    gUnk_02039DC8->unk_58 = gUnk_02039DC8->unk_48 + (gUnk_02039DC8->unk_68 << 8);
    gUnk_02039DC8->unk_5C = gUnk_02039DC8->unk_4C + (gUnk_02039DC8->unk_6A << 8);
}

u8 func_08074E40(Work08074DC4* p) {
    AnimSet0806180C* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    AnimEntry0806180C* q = t->unk_04;
    Obj0806180C* e = &p->unk_0C[p->unk_09];
    u8 i;

    for (i = 0; i < n; i++) {
        if (e->unk_10 == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 func_08074E88(Work08074DC4* p, u8 v) {
    AnimSet0806180C* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    AnimEntry0806180C* q = t->unk_04;
    u8 i;

    for (i = 0; i < n; i++) {
        if (v == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

INCLUDE_ASM("unk_0806180c/_08074EC8.s");

void func_08075010(Work08075010* p) {
    u8 i;
    s32 v;

    if (p->unk_1A == 1) {
        for (i = 0; i < 160; i++) {
            p->unk_1C[i] = (gUnk_02039DC8->unk_58 >> 8) + (v = (u8)gSineTable[((i + p->unk_16) * 2) & 0xFF]) / 32;
        }
        p->unk_16++;
    }
}

s16 func_08075064(u8 a) {
    s16 n = 0;

    switch (a) {
    case 0:
        while (gUnk_09033D50[n] != -1) {
            n++;
        }
        break;
    case 1:
        while (gUnk_09033E76[n] != -1) {
            n++;
        }
        break;
    }
    return n;
}
