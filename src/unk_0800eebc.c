#include "macros.h"
#include "unk_0800eebc.h"

INCLUDE_ASM("unk_0800eebc/func_0800EEBC.s");
INCLUDE_ASM("unk_0800eebc/func_0800EFE8.s");
INCLUDE_ASM("unk_0800eebc/func_0800F230.s");

void func_0800F368(Actor* p, u16 n) {
    s32 v;
    func_0801C700(&p->unk_40, &v, 0, 0);
    if (GetRandom() % n == 0) {
        if (p->unk_44 > v) {
            p->unk_74 |= 4;
        } else {
            p->unk_74 &= ~4;
        }
    }
}

INCLUDE_ASM("unk_0800eebc/func_0800F3BC.s");
INCLUDE_ASM("unk_0800eebc/func_0800F440.s");

u8 func_0800F4C8(BtlObj* p, u16 b) {
    if (p->unk_040.unk_04 < (gUnk_02039B84->unk_0DA + b) << 8) {
        return 1;
    }
    if (p->unk_040.unk_04 > (gUnk_02039B84->unk_0DC - b) << 8) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_0800eebc/func_0800F504.s");
INCLUDE_ASM("unk_0800eebc/func_0800F5A4.s");
INCLUDE_ASM("unk_0800eebc/_0800F84C.s");

#ifdef NON_MATCHING
void func_0800F988(UnkStruct_02039CA8* p) {
    s32 n = p->unk_10 + 1;
    p->unk_0C += n * n * 3;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0800F988.s");
#endif

void func_0800F9A0(void) {
    gUnk_02039CA8.unk_00 = 0x50;
    gUnk_02039CA8.unk_02 = 0x113;
    gUnk_02039CA8.unk_04 = 8;
    gUnk_02039CA8.unk_06 = 10;
    gUnk_02039CA8.unk_08 = 0;
    gUnk_02039CA8.unk_10 = 1;
    gUnk_02039CA8.unk_14[0] = 0;
    gUnk_02039CA8.unk_14[1] = 0;
    gUnk_02039CA8.unk_14[2] = 0;
    gUnk_02039CA8.unk_14[3] = 0;
    gUnk_02039CA8.unk_14[4] = 0;
    gUnk_02039CA8.unk_14[5] = 0;
    gUnk_02039CA8.unk_14[6] = 0;
    gUnk_02039CA8.unk_14[7] = 0;
    gUnk_02039CA8.unk_14[8] = 0;
    gUnk_02039CA8.unk_14[9] = 0;
    gUnk_02039CA8.unk_14[10] = 0;
    gUnk_02039CA8.unk_14[11] = 0;
    gUnk_02039CA8.unk_14[12] = 0;
    gUnk_02039CA8.unk_7C = 0;
    gUnk_02039CA8.unk_80 = 0;
    gUnk_02039CA8.unk_82 = 0;
    gUnk_02039CA8.unk_84 = 0;
    gUnk_02039CA8.unk_0C = 0x19;
    func_080C6FF8();
    func_080DDEA4();
    func_08109620();
}

INCLUDE_ASM("unk_0800eebc/func_0800FA1C.s");

u8 func_0800FAFC(void) {
    if (gUnk_02039CA8.unk_08 >= gUnk_02039CA8.unk_0C) {
        return 1;
    }
    return 0;
}

const UnkStruct_08133E5C* func_0800FB14(u16 i) {
    if (i > 0x35) {
        return 0;
    }
    return &gUnk_08133E5C[i];
}

INCLUDE_ASM("unk_0800eebc/func_0800FB2C.s");

u8 func_0800FBCC(u32 a) {
    u64* p;
    u8* q;
    if (a <= 0x1E) {
        q = (u8*)&gUnk_02039BB0;
        q += 0x10C;
    } else {
        a -= 0x1F;
        q = (u8*)&gUnk_02039BB0;
        q += 0x114;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

void func_0800FC14(s32 a) {
    if (a == 0x3A) {
        gUnk_02039BB0.unk_12C = -1;
    } else {
        gUnk_02039BB0.unk_12C |= 1LL << a;
    }
}

u8 func_0800FC5C(s32 a) {
    if (gUnk_02039BB0.unk_12C & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FC90(u32 a) {
    u64* p;
    u8* q;
    if (a <= 0x1E) {
        q = (u8*)&gUnk_02039BB0;
        q += 0x1E8;
    } else {
        a -= 0x1F;
        q = (u8*)&gUnk_02039BB0;
        q += 0x1F0;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FCD8(u32 a) {
    u64* p;
    u8* q;
    if (a <= 0x1E) {
        q = (u8*)&gUnk_02039BB0;
        q += 0x200;
    } else {
        a -= 0x1F;
        q = (u8*)&gUnk_02039BB0;
        q += 0x208;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FD20(u32 a) {
    u64* p;
    u8* q;
    if (a <= 0x1E) {
        q = (u8*)&gUnk_02039BB0;
        q += 0x11C;
    } else {
        a -= 0x1F;
        q = (u8*)&gUnk_02039BB0;
        q += 0x124;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

void func_0800FD68(u32 a) {
    u64* p;
    u8* q;
    if (a == 0x48) {
        BtlSetup* s = &gUnk_02039BB0;
        s->unk_11C = 0;
        s->unk_124 = 0;
    } else {
        if (a <= 0x1E) {
            q = (u8*)&gUnk_02039BB0;
            q += 0x11C;
        } else {
            a -= 0x1F;
            q = (u8*)&gUnk_02039BB0;
            q += 0x124;
        }
        p = (u64*)q;
        *p &= ~(1LL << a);
    }
}

INCLUDE_ASM("unk_0800eebc/func_0800FDD0.s");

u8 func_0800FF00(u32 a) {
    u64* p;
    u8* q;
    if (a <= 0x3F) {
        q = (u8*)&gUnk_02039BB0;
        q += 0x134;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gUnk_02039BB0;
        q += 0x13C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gUnk_02039BB0;
        q += 0x144;
    } else {
        a -= 0xC0;
        q = (u8*)&gUnk_02039BB0;
        q += 0x14C;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_0800eebc/func_0800FF70.s");

void func_0801007C(void) {
    UnkStruct_020348C8* p;
    UnkStruct_020348C8** pp = &gUnk_020348C8;
    p = EwramAlloc(0x24);
    *pp = p;
    p->unk_20 = 0;
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_22 = 0;
}

INCLUDE_ASM("unk_0800eebc/func_080100A0.s");

u8 func_0801050C(s32 a, s32* b, s32* c, s32* d) {
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

INCLUDE_ASM("unk_0800eebc/func_08010548.s");
INCLUDE_ASM("unk_0800eebc/func_08010600.s");
INCLUDE_ASM("unk_0800eebc/func_0801071C.s");
INCLUDE_ASM("unk_0800eebc/func_080107D4.s");
INCLUDE_ASM("unk_0800eebc/func_08010A24.s");

void func_08010C70(void) {
    gUnk_02039B84->unk_0A0 = 1;
    if (!(gUnk_02039B84->unk_068 & 0x800000)) {
        gUnk_02039B84->unk_068 |= 0x20;
    }
    gUnk_02039B84->unk_068 &= ~0x40;
    gUnk_02039B84->unk_068 &= ~0x20000000;
}

INCLUDE_ASM("unk_0800eebc/func_08010CC8.s");
INCLUDE_ASM("unk_0800eebc/func_08011270.s");

void func_08011364(BtlObj* a, HitData* b, s32* c) {
    gUnk_02039B84->unk_076 = 8;
    a->unk_020 = -((b->unk_30 * *c) >> 8);
    a->unk_034 |= 0x20;
}

INCLUDE_ASM("unk_0800eebc/func_08011398.s");
INCLUDE_ASM("unk_0800eebc/func_08011E3C.s");

s32 func_08011F68(s32 a, s32 b) {
    return func_08011398(b, a);
}

INCLUDE_ASM("unk_0800eebc/func_08011F78.s");

s32 func_08012170(s32 a, s32 b, s32 c, s32 d) {
    return func_08011F78(a, b, c, d, 16, 16, 16);
}

INCLUDE_ASM("unk_0800eebc/func_08012188.s");

void func_080121D4(FldObj* p) {
    func_08000D20(&p->unk_1C, &gUnk_02039BA0->unk_58, p);
    func_08000D28(&p->unk_1C, &gUnk_02039BA0->unk_58);
}

void func_080121FC(FldObj* p) {
    func_08000D90(&p->unk_1C, &gUnk_02039BA0->unk_58);
}

void func_08012214(void) {
}

void* func_08012218(u32 type) {
    switch (type) {
    case 1:
    case 2:
    case 4:
    case 9:
        return &gUnk_020348E8;
    case 3:
        return &gUnk_020348F8;
    case 5:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:
        return &gUnk_02034908;
    }
    return &gUnk_02034918;
}

void func_0801227C(void) {
    func_08000BA4(&gUnk_020348E8);
    func_08000BA4(&gUnk_020348F8);
    func_08000BA4(&gUnk_02034908);
    func_08000BA4(&gUnk_02034918);
}

void func_080122AC(Collider* p, u32 type, u16 r, u16 h) {
    void* pool;
    p->unk_34 = 0;
    p->unk_2C = 0;
    p->unk_2E = 0;
    p->unk_30 = 0;
    p->unk_10 = r << 8;
    p->unk_14 = h << 8;
    p->unk_00 = type;
    p->unk_54 = p;
    p->unk_58 = 0;
    pool = func_08012218(type);
    switch (type) {
    case 6:
    case 7:
        p->unk_30 |= 1;
        break;
    }
    func_08000D20(&p->unk_18, pool, p);
    func_08000D28(&p->unk_18, pool);
}

void func_08012304(Collider* p) {
    Collider* q = p->unk_54;
    if (q == p) {
        func_08000D90(&q->unk_18, func_08012218(q->unk_00));
    }
}

void func_08012324(Collider* p, s32 a, s32 b, s32 c) {
    p->unk_04 = a;
    p->unk_08 = b * 2;
    p->unk_0C = c;
}

void func_08012330(ListNode* pool) {
    Collider* p = func_08000C8C(pool);
    while (p != 0) {
        p->unk_2C = 0;
        p->unk_58 = 0;
        p->unk_2E = 0;
        p = func_08000CD4(&p->unk_18);
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801235C.s");

void func_080125A4(void) {
    func_08012330(&gUnk_020348E8);
    func_08012330(&gUnk_020348F8);
    func_08012330(&gUnk_02034908);
    func_08012330(&gUnk_02034918);
    func_0801235C(&gUnk_020348E8, &gUnk_020348E8);
    func_0801235C(&gUnk_020348F8, &gUnk_020348E8);
    func_0801235C(&gUnk_02034908, &gUnk_020348E8);
    func_0801235C(&gUnk_020348F8, &gUnk_020348F8);
    func_0801235C(&gUnk_02034918, &gUnk_020348E8);
    func_0801235C(&gUnk_02034918, &gUnk_020348F8);
}

void func_08012614(Collider* p, u8 b) {
    if (b) {
        p->unk_18.unk_0C |= 2;
        p->unk_2C = 0;
        p->unk_2E = 0;
    } else {
        p->unk_18.unk_0C &= ~2;
    }
}

u8 func_08012648(Collider* p) {
    return p->unk_2C;
}

void func_08012650(Collider* p, u16 r) {
    p->unk_10 = r << 8;
}

void func_08012658(Collider* p, u16 h) {
    p->unk_14 = h << 8;
}

u8 func_08012660(Collider* p, s32 bit) {
    if (p->unk_58 & (1 << bit)) {
        return 1;
    }
    return 0;
}

void func_08012674(void) {
    if (gUnk_02039B84->unk_068 & 4) {
        SetBgPriority(gUnk_02034928->unk_00, 0);
    } else {
        SetBgPriority(gUnk_02034928->unk_00, 1);
    }
    SetBgBlend(gUnk_02034928->unk_00, 16, 16);
    gUnk_02034928->unk_1C = 0x100;
    gUnk_02034928->unk_20 = 0x100;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_04 = 0;
    gUnk_02034928->unk_08 = 0;
    gUnk_02034928->unk_18 = 0;
    gUnk_02034928->unk_34 = 2;
    gUnk_02034928->unk_4C = 0;
}

u8 func_080126E4(u8 a) {
    if (func_08006B74()) {
        gUnk_02034928->unk_38 = a;
        return 0;
    }
    if (gUnk_02034928->unk_38 < a) {
        return 1;
    }
    gUnk_02034928->unk_38 = a;
    return 0;
}

void func_08012728(u16 a) {
    u16 b;
    u16 c;
    func_08006B80(&b, &c);
    if (func_08006BA0(func_08006BA8()) - b * c <= (s16)a) {
        gUnk_02034928->unk_34 &= ~2;
        gUnk_02034928->unk_38 = 2;
        if (gUnk_02034928->unk_34 & 8) {
            gUnk_02034928->unk_34 &= ~8;
            func_080061E8(0, 8);
        }
    }
}

void func_08012798(u16 a, u16 bg) {
    s32 i;
    gUnk_02034928 = EwramAlloc(0x50);
    for (i = 10; i < 16; i++) {
        func_080062F4(i, 1);
    }
    if (a == 0) {
        func_080065FC(bg, 0xC000, 0);
    } else {
        func_080065FC(bg, 0x8000, 0x80);
    }
    SetBgBlend(bg, 16, 16);
    gUnk_02034928->unk_04 = 0;
    gUnk_02034928->unk_38 = 0xFF;
    gUnk_02034928->unk_00 = bg;
    func_08012674();
    gUnk_02034928->unk_34 = 0;
}

void func_08012810(void) {
    EwramFree(gUnk_02034928);
}

INCLUDE_ASM("unk_0800eebc/func_08012824.s");

u8 func_080128EC(void) {
    if (gUnk_02034928->unk_34 & 2) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_0800eebc/func_08012908.s");
INCLUDE_ASM("unk_0800eebc/func_08012AAC.s");

void func_08012BCC(void) {
    SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);
    if (gUnk_02034928->unk_08 > 15) {
        func_08006B4C();
    } else {
        gUnk_02034928->unk_08++;
    }
    func_08012908();
}

INCLUDE_ASM("unk_0800eebc/func_08012C08.s");
INCLUDE_ASM("unk_0800eebc/func_08012E44.s");
INCLUDE_ASM("unk_0800eebc/func_08012F74.s");
INCLUDE_ASM("unk_0800eebc/func_08013070.s");
INCLUDE_ASM("unk_0800eebc/func_08013308.s");

void func_08013420(void) {
    gUnk_02034928->unk_1C += gUnk_02034928->unk_28;
    gUnk_02034928->unk_20 += gUnk_02034928->unk_2C;
    gUnk_02034928->unk_24 += 3;
    func_08012908();
    if (gUnk_02034928->unk_08 > 5) {
        s16 t = gUnk_02034928->unk_08 - 5;
        SetBlendAlpha(16, 16 - t);
        if (t > 15) {
            func_08006B4C();
        }
    }
    gUnk_02034928->unk_08++;
}

INCLUDE_ASM("unk_0800eebc/func_08013480.s");
INCLUDE_ASM("unk_0800eebc/func_0801350C.s");

void func_08013748(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;
    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    if (f != 0) {
        gUnk_02034928->unk_1C = -0x100;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA648, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

INCLUDE_ASM("unk_0800eebc/func_080137C8.s");

void func_08013994(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;
    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA780, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_080139FC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;
    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA930, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

INCLUDE_ASM("unk_0800eebc/func_08013A68.s");
INCLUDE_ASM("unk_0800eebc/func_08013B00.s");
INCLUDE_ASM("unk_0800eebc/func_08013CB4.s");

void func_08013D60(void) {
    u16 a;
    func_08006B80(&a, 0);
    if (a > 3) {
        gUnk_02034928->unk_1C += 12;
        gUnk_02034928->unk_20 += 12;
        SetBlendAlpha(gUnk_02034928->unk_08, 16 - gUnk_02034928->unk_08);
        if (gUnk_02034928->unk_08 > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08 += 2;
        }
    }
    func_08012908();
}

INCLUDE_ASM("unk_0800eebc/func_08013DB8.s");

void func_08013EDC(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;
    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA9D8, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}

void func_08013F5C(s32 x, s32 y, s32 s, u16 b, u16 c) {
    s16 sx;
    s16 sy;
    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    SetBgBlend(gUnk_02034928->unk_00, b, c);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = -0x1000;
    WorldToScreen(&sx, &sy, x, y, -0x1000);
    func_08006778(gUnk_09EDA810, sx, sy);
    m4aSongNumStart(0x227);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}

void func_08014000(void) {
    gUnk_02034928->unk_1C += 12;
    gUnk_02034928->unk_20 += 12;
    func_08012908();
}

void func_08014020(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;
    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA600, sx, sy);
    gUnk_02034928->unk_04 = func_08014000;
    m4aSongNumStart(0x22C);
    gUnk_02034928->unk_34 |= 0x10;
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080140C0(s32* a, s32* b, s32* c) {
    *a = gUnk_02034928->unk_10;
    *b = gUnk_02034928->unk_14;
    *c = gUnk_02034928->unk_18;
}

void func_080140E0(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA8E8, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801416C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;
    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA888, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_080141D4(void) {
    BtlObj* p = gUnk_02034928->unk_44;
    gUnk_02034928->unk_10 = p->unk_004;
    gUnk_02034928->unk_14 = p->unk_008;
    gUnk_02034928->unk_18 = p->unk_00C - 0x800;
    func_08012908();
}

INCLUDE_ASM("unk_0800eebc/func_080141FC.s");
INCLUDE_ASM("unk_0800eebc/func_08014294.s");
INCLUDE_ASM("unk_0800eebc/func_0801440C.s");
INCLUDE_ASM("unk_0800eebc/func_08014588.s");
INCLUDE_ASM("unk_0800eebc/func_08014654.s");

void func_0801475C(s32 a, s32 b, s32 c) {
    gUnk_02034928->unk_10 += a;
    gUnk_02034928->unk_14 += b;
    gUnk_02034928->unk_18 += c;
}

void func_08014780(s32 a, s32 b, s32 c) {
    gUnk_02034928->unk_10 = a;
    gUnk_02034928->unk_14 = b;
    gUnk_02034928->unk_18 = c;
}

void func_08014790(u8 bit) {
    gUnk_02034928->unk_36 |= 1 << bit;
}

void func_080147A8(s32 a, s32 b, s32 c) {
    gUnk_02034928->unk_28 = a;
    gUnk_02034928->unk_2C = b;
    gUnk_02034928->unk_30 = c;
}

void func_080147B8(u8 a) {
    gUnk_02034928->unk_24 = a;
}

void func_080147C8(s32 a, s32 b) {
    gUnk_02034928->unk_1C = a;
    gUnk_02034928->unk_20 = b;
}

void func_080147D8(s32 x, s32 y) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBgBlend(gUnk_02034928->unk_00, 5, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA900, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014850(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 == 21) {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 48);
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 == 25) {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 24, 24, 48);
        }
        break;
    case 2:
        if (gUnk_02034928->unk_08 == 33) {
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 48);
        }
        break;
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

INCLUDE_ASM("unk_0800eebc/func_080148E0.s");

void func_080149BC(s32 x, s32 y) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA948, sx, sy);
    func_08006B34(8);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014A34(s32 x, s32 y) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA960, sx, sy);
    func_08006B34(7);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

void func_08014AAC(s32 x, s32 y) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    m4aSongNumStart(0x20E);
    func_08006778(gUnk_09EDAA50, sx, sy);
    func_08006B34(4);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}

INCLUDE_ASM("unk_0800eebc/func_08014B30.s");
INCLUDE_ASM("unk_0800eebc/func_08014BA8.s");

void func_08014D78(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(2, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_48 = w;
    if (f != 0) {
        gUnk_02034928->unk_1C = -gUnk_02034928->unk_1C;
        gUnk_02034928->unk_34 |= 1;
    }
    gUnk_02034928->unk_0A = 0;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA978, sx, sy);
    m4aSongNumStart(0x232);
    gUnk_02034928->unk_26 = a;
    gUnk_02034928->unk_04 = func_08014BA8;
}

void func_08014E38(void) {
    s16 t = gUnk_02034928->unk_08 % 8;
    if (t <= 3) {
        SetBlendAlpha(t, 16);
    } else {
        SetBlendAlpha(8 - t, 16);
    }
    if (gUnk_02034928->unk_08 == 0x23) {
        if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 40, 20, 256)) {
            m4aSongNumStart(0x234);
        }
    }
    func_08012908();
    gUnk_02034928->unk_08++;
}

void func_08014EC0(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(2, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_0A = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA990, sx, sy);
    m4aSongNumStart(0x233);
    gUnk_02034928->unk_04 = func_08014E38;
}

void func_08014F4C(void) {
    gUnk_02034928->unk_1C += 0x80;
    gUnk_02034928->unk_20 += 0x80;
    gUnk_02034928->unk_24 += 3;
    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_10 += -0x300;
    } else {
        gUnk_02034928->unk_10 += 0x300;
    }
    func_08012908();
    SetBlendAlpha(16, 8 - gUnk_02034928->unk_0A);
    if (gUnk_02034928->unk_0A > 7) {
        func_08006B4C();
    }
    if (gUnk_02034928->unk_08 % 5 == 0) {
        gUnk_02034928->unk_0A++;
    }
    gUnk_02034928->unk_08++;
}

INCLUDE_ASM("unk_0800eebc/func_08014FDC.s");

void func_0801508C(void) {
    if (gUnk_02034928->unk_08 > 19) {
        gUnk_02034928->unk_0A = (gUnk_02034928->unk_08 - 20) / 2;
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_0A);
        if (gUnk_02034928->unk_0A > 15) {
            func_08006B4C();
        }
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080150D8(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = 0x100;
    gUnk_02034928->unk_20 = 0x100;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA9C0, sx, sy);
    gUnk_02034928->unk_04 = func_0801508C;
    m4aSongNumStart(0x262);
    if (f == 0) {
        gUnk_02034928->unk_34 |= 1;
    }
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
    func_08006B34(3);
}

INCLUDE_ASM("unk_0800eebc/func_0801519C.s");

void func_08015228(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 30;
    func_08006778(gUnk_09EDA9F0, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_0801519C;
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

INCLUDE_ASM("unk_0800eebc/func_080152DC.s");

void func_0801536C(void) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 0x19;
    gUnk_02034928->unk_20 = 0x19;
    func_08006778(gUnk_09EDAA20, 0x78, 0x50);
    func_08006B34(0);
    m4aSongNumStart(0x27B);
    gUnk_02034928->unk_04 = func_080152DC;
    gUnk_02034928->unk_34 |= 0x10;
}

INCLUDE_ASM("unk_0800eebc/func_080153C8.s");
INCLUDE_ASM("unk_0800eebc/func_080155BC.s");
INCLUDE_ASM("unk_0800eebc/func_08015698.s");
INCLUDE_ASM("unk_0800eebc/func_08015834.s");
INCLUDE_ASM("unk_0800eebc/func_080158E8.s");
INCLUDE_ASM("unk_0800eebc/func_08015B50.s");
INCLUDE_ASM("unk_0800eebc/func_08015D04.s");
INCLUDE_ASM("unk_0800eebc/func_08015E3C.s");

void func_08015FF4(void) {
    if (gUnk_02034928->unk_08 > 0) {
        func_0800592C(&gUnk_02034928->unk_1C, 0x100, gUnk_02034928->unk_08);
        func_0800592C(&gUnk_02034928->unk_20, 0x100, gUnk_02034928->unk_08);
        gUnk_02034928->unk_08--;
    }
    func_08012908();
}

void func_08016038(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_1C = 0x19;
    gUnk_02034928->unk_20 = 0x19;
    m4aSongNumStart(0x27C);
    func_08006778(gUnk_09EDAAC8, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_08 = 0x23;
    gUnk_02034928->unk_04 = func_08015FF4;
}

INCLUDE_ASM("unk_0800eebc/func_080160C0.s");
INCLUDE_ASM("unk_0800eebc/func_080161F8.s");

Collider* func_08016320(void) {
    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (gUnk_02039B84->unk_068 & 0x20000000) {
            return gUnk_02039B84->unk_07C;
        }
        return gUnk_02039B9C->unk_07C;
    }
    if (gUnk_02039B84->unk_078 != 0) {
        return gUnk_02039B84->unk_078;
    }
    return func_08000C8C(&gUnk_02039B84->unk_080);
}

INCLUDE_ASM("unk_0800eebc/func_08016374.s");
INCLUDE_ASM("unk_0800eebc/func_08016468.s");
INCLUDE_ASM("unk_0800eebc/func_080165DC.s");

void func_080166F8(void) {
    gUnk_02034928->unk_1C += gUnk_02034928->unk_28;
    gUnk_02034928->unk_20 += gUnk_02034928->unk_2C;
    func_08012908();
    if (gUnk_02034928->unk_08 > 5) {
        s16 t = gUnk_02034928->unk_08 - 5;
        SetBlendAlpha(16, 16 - t);
        if (t > 15) {
            func_08006B4C();
        }
    }
    gUnk_02034928->unk_08++;
}

INCLUDE_ASM("unk_0800eebc/func_08016750.s");
INCLUDE_ASM("unk_0800eebc/func_080167F8.s");
INCLUDE_ASM("unk_0800eebc/func_080168B8.s");

void func_08016A64(void) {
    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_10 += 0x700;
    } else {
        gUnk_02034928->unk_10 += -0x700;
    }
    if (gUnk_02034928->unk_10 < (gUnk_02039B84->unk_0DA - 0x40) << 8 || gUnk_02034928->unk_10 > (gUnk_02039B84->unk_0DC + 0x40) << 8) {
        func_08006B4C();
    } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 48)) {
        m4aSongNumStart(0x27F);
    }
    func_08012908();
}

INCLUDE_ASM("unk_0800eebc/func_08016AF4.s");
INCLUDE_ASM("unk_0800eebc/func_08016C40.s");
INCLUDE_ASM("unk_0800eebc/func_08016D00.s");
INCLUDE_ASM("unk_0800eebc/func_08017008.s");
INCLUDE_ASM("unk_0800eebc/func_0801709C.s");
INCLUDE_ASM("unk_0800eebc/func_0801718C.s");

void func_08017260(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA5A0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006B34(0);
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

INCLUDE_ASM("unk_0800eebc/func_080172F8.s");
INCLUDE_ASM("unk_0800eebc/func_08017390.s");
INCLUDE_ASM("unk_0800eebc/func_08017410.s");
INCLUDE_ASM("unk_0800eebc/func_080175BC.s");
INCLUDE_ASM("unk_0800eebc/func_08017728.s");
INCLUDE_ASM("unk_0800eebc/func_080177EC.s");
INCLUDE_ASM("unk_0800eebc/func_080179F8.s");
INCLUDE_ASM("unk_0800eebc/func_08017AC0.s");
INCLUDE_ASM("unk_0800eebc/func_08017C54.s");
INCLUDE_ASM("unk_0800eebc/func_08017E18.s");

void func_08017EF4(void) {
    u16 k;
    u16 t;
    ApproachValue(&gUnk_02034928->unk_1C, 0x300, gUnk_02034928->unk_0A);
    gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
    gUnk_02034928->unk_0A--;
    func_08006B80(&k, 0);
    if (k <= 4) {
        t = (gUnk_02034928->unk_1C * 5) >> 5;
        if (func_08011F78(0x13D, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, (s16)t, (s16)t >> 1, 1)) {
            m4aSongNumStart(0x2AB);
        }
    }
    func_08012908();
}

void func_08017F70(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC78, sx, sy);
    gUnk_02034928->unk_1C = 0x80;
    gUnk_02034928->unk_20 = 0x80;
    gUnk_02034928->unk_0A = func_08006BA0(func_08006BA8());
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_08017EF4;
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801801C(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC90, sx, sy);
    gUnk_02034928->unk_1C = 0x80;
    gUnk_02034928->unk_20 = 0x80;
    gUnk_02034928->unk_0A = func_08006BA0(func_08006BA8());
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_08017EF4;
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

INCLUDE_ASM("unk_0800eebc/func_080180C8.s");
INCLUDE_ASM("unk_0800eebc/func_08018184.s");
INCLUDE_ASM("unk_0800eebc/func_08018240.s");
INCLUDE_ASM("unk_0800eebc/func_0801836C.s");

void func_0801848C(void) {
    s16 t = gUnk_02034928->unk_08 >> 1;
    SetBlendAlpha(16, 16 - t);
    if (t > 15) {
        func_08006B4C();
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

INCLUDE_ASM("unk_0800eebc/func_080184C4.s");
INCLUDE_ASM("unk_0800eebc/func_080185D0.s");
INCLUDE_ASM("unk_0800eebc/func_08018724.s");

void func_0801884C(void) {
    s16 t;
    switch (gUnk_02034928->unk_26) {
    case 0:
        gUnk_02034928->unk_1C += 2;
        gUnk_02034928->unk_20 += 2;
        break;
    case 1:
        gUnk_02034928->unk_1C += 5;
        gUnk_02034928->unk_20 += 5;
        break;
    case 2:
        gUnk_02034928->unk_1C += 10;
        gUnk_02034928->unk_20 += 10;
        break;
    }
    if (gUnk_02034928->unk_08 == 10) {
        t = (gUnk_02034928->unk_1C * 3) >> 4;
        if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, t, t, 100)) {
            m4aSongNumStart(0x2BB);
        }
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080188E4(u16 a, s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_26 = a;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD20, sx, sy);
    gUnk_02034928->unk_04 = func_0801884C;
    func_08006238(0, gUnk_02039B84->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

INCLUDE_ASM("unk_0800eebc/func_08018970.s");
INCLUDE_ASM("unk_0800eebc/func_08018B04.s");
INCLUDE_ASM("unk_0800eebc/func_08018B78.s");
INCLUDE_ASM("unk_0800eebc/func_08018CC4.s");
INCLUDE_ASM("unk_0800eebc/func_08018F28.s");

void func_08019050(u16 a, s32 b, s32 c, s32 d) {
    gUnk_02039B84->unk_028 = b;
    gUnk_02039B84->unk_01A = a;
    gUnk_02039B84->unk_01C = c;
    gUnk_02039B84->unk_020 = d;
}

void func_08019068(AnimDef* tbl, void* a, u16 i, u16 j, void* obj) {
    AnimDef* e = &tbl[i];
    func_08005974(a, e->unk_0C, j, e->unk_04, e->unk_00);
    func_08002A10(obj, e->unk_08);
}

INCLUDE_ASM("unk_0800eebc/WorldToScreen.s");
INCLUDE_ASM("unk_0800eebc/func_08019190.s");

void func_08019270(void) {
    s32 zero = 0;
    u8* d;
    u8* p;
    CpuSet(&zero, gUnk_02039B84, 0x05000074);
    gUnk_02039B84->unk_0A0 = 0;
    gUnk_02039B84->unk_0FC = 0xFFFF0000;
    gUnk_02039B84->unk_12C = 0x42;
    gUnk_02039B84->unk_0B3 = 10;
    d = gUnk_02039B84->unk_13C;
    p = (u8*)&gUnk_02039BB0;
    p += 0xF8;
    memcpy(d, p, 0x88);
    func_08000BA4(&gUnk_02039B84->unk_080);
    func_08000BA4(&gUnk_02039B84->unk_090);
}

INCLUDE_ASM("unk_0800eebc/func_080192E0.s");

INCLUDE_ASM("unk_0800eebc/func_08019350.s");
INCLUDE_ASM("unk_0800eebc/func_080197AC.s");
INCLUDE_ASM("unk_0800eebc/func_08019A30.s");
INCLUDE_ASM("unk_0800eebc/func_08019ACC.s");

void func_08019C5C(void) {
    gUnk_02039B84->unk_0A0 = 1;
    if (!(gUnk_02039B84->unk_068 & 0x800000)) {
        gUnk_02039B84->unk_068 |= 0x20;
    }
    gUnk_02039B84->unk_068 &= ~0x40;
    gUnk_02039B84->unk_068 &= ~0x20000000;
}

INCLUDE_ASM("unk_0800eebc/_08019CB4.s");

u8 func_0801A8A4(s32* px, s32* py, u16 rx, u16 ry) {
    u8 r = 0;
    if (*py < (gUnk_02039B84->unk_0DE - (s16)ry) << 8) {
        *py = (gUnk_02039B84->unk_0DE - (s16)ry) << 8;
        r = 3;
    }
    if (*py > (gUnk_02039B84->unk_0E0 + (s16)ry) << 8) {
        *py = (gUnk_02039B84->unk_0E0 + (s16)ry) << 8;
        r = 4;
    }
    if (*px < (gUnk_02039B84->unk_0DA - (s16)rx) << 8) {
        *px = (gUnk_02039B84->unk_0DA - (s16)rx) << 8;
        r = 1;
    }
    if (*px > (gUnk_02039B84->unk_0DC + (s16)rx) << 8) {
        *px = (gUnk_02039B84->unk_0DC + (s16)rx) << 8;
        r = 2;
    }
    return r;
}

void func_0801A920(u16 a, u16 b, u16 c, u16 d) {
    gUnk_02039B84->unk_0DA = a;
    gUnk_02039B84->unk_0DC = b;
    gUnk_02039B84->unk_0DE = c;
    gUnk_02039B84->unk_0E0 = d;
    func_0801C274(((s16)a + (s16)b) << 7, ((s16)c + (s16)d) << 7, -0x2000);
}

INCLUDE_ASM("unk_0800eebc/func_0801A978.s");

#ifdef NON_MATCHING
u8 func_0801AD68(BtlObj* p) {
    u64 f = p->unk_034;
    if (!((u32)f & 1)) {
        return 0;
    }
    f &= ~0x46023;
    f |= 0x90;
    p->unk_034 = f;
    p->unk_014 = p->unk_004;
    p->unk_018 = p->unk_008;
    p->unk_01C = p->unk_00C;
    return 1;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0801AD68.s");
#endif

INCLUDE_ASM("unk_0800eebc/func_0801ADAC.s");

void func_0801AF08(BtlObj* p) {
    p->unk_034 &= ~0x2290;
}

u16 func_0801AF1C(s32 a) {
    if (a < gUnk_02039B84->unk_0D0 + (gUnk_02039B84->unk_0D8 << 8)) {
        return 0x800;
    }
    return 0x400;
}

INCLUDE_ASM("unk_0800eebc/func_0801AF4C.s");

void func_0801B008(void) {
    gUnk_02039B84->unk_068 &= ~0x80000;
}

INCLUDE_ASM("unk_0800eebc/func_0801B024.s");
INCLUDE_ASM("unk_0800eebc/func_0801B37C.s");

void func_0801B7D8(BtlObj* obj) {
    BtlObj* p = obj->unk_0DC;
    if (p == obj) {
        func_08000D90(&p->unk_0B8, &gUnk_02039B84->unk_080);
        if (!(p->unk_03C & 1)) {
            func_08012304(&p->unk_040);
        }
        gUnk_02039B84->unk_0EE--;
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801B818.s");
INCLUDE_ASM("unk_0800eebc/func_0801B8A8.s");
INCLUDE_ASM("unk_0800eebc/func_0801B918.s");
INCLUDE_ASM("unk_0800eebc/func_0801B994.s");
INCLUDE_ASM("unk_0800eebc/func_0801BBF0.s");

void func_0801BCC0(s32 a, s32 b, s32 c) {
    gUnk_02039B84->unk_07C->unk_04 = a;
    gUnk_02039B84->unk_07C->unk_08 = b;
    gUnk_02039B84->unk_07C->unk_0C = c;
}

void func_0801BCD4(BtlObj* p) {
    if (!(p->unk_034 & 0x7202)) {
        gUnk_02039B84->unk_0AC = p;
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801BCF8.s");

void func_0801BDD4(BtlObj* p, s32 v) {
    p->unk_0D8 = v;
}

INCLUDE_ASM("unk_0800eebc/func_0801BDDC.s");
INCLUDE_ASM("unk_0800eebc/func_0801C068.s");
INCLUDE_ASM("unk_0800eebc/func_0801C104.s");

u8 func_0801C1C0(u8 a) {
    u8 m;
    if (a > 4) {
        return 0;
    }
    m = 1 << a;
    if (gUnk_02039B84->unk_0FB & m) {
        gUnk_02039B84->unk_0FB &= ~m;
        return 1;
    }
    return 0;
}

ALIGN_ZERO(2);

INCLUDE_ASM("unk_0800eebc/_0801C1F8.s");

void func_0801C274(s32 a, s32 b, s32 c) {
    gUnk_02039B84->unk_100 = a;
    gUnk_02039B84->unk_104 = b;
    gUnk_02039B84->unk_108 = c;
}

void func_0801C298(u8 a, u8 b) {
    if (a <= 0x1F) {
        if (b != 0) {
            gUnk_02039B84->unk_0FC |= 1 << a;
        } else {
            gUnk_02039B84->unk_0FC &= ~(1 << a);
        }
    }
}

void func_0801C2DC(BtlObj* p, u8 f) {
    if (f) {
        p->unk_034 |= 0x1000000;
    } else {
        p->unk_034 &= ~0x1000000;
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801C314.s");

#ifdef NON_MATCHING
u8 func_0801C6D4(s32 a) {
    if (gUnk_02039B84->unk_128 != 0) {
        return gUnk_02039B84->unk_128(a);
    }
    return 0;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0801C6D4.s");
#endif

INCLUDE_ASM("unk_0800eebc/func_0801C700.s");

void func_0801C7FC(HitData* a, u16 b, s32 c) {
    const UnkStruct_08133E5C* e = func_0800FB14(b);
    if (e != 0) {
        a->unk_2E = (e->unk_00 * c) >> 8;
        if (a->unk_2E <= 0) {
            a->unk_2E = 1;
        }
        a->unk_2C = a->unk_2E;
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801C830.s");

u8 func_0801CA00(BtlObj* p) {
    if (gUnk_02039B84->unk_070 == 1) {
        return 0;
    }
    if (!(p->unk_034 & 0x2000)) {
        return 0;
    }
    if (p->unk_106 > 0x17) {
        return 0;
    }
    p->unk_106++;
    if (p->unk_106 & 1) {
        return 1;
    }
    return 0;
}

u8 func_0801CA48(BtlObj* p) {
    if (gUnk_02039B84->unk_070 == 1) {
        return 0;
    }
    if (!(p->unk_034 & 0x2000)) {
        return 0;
    }
    if (p->unk_106 > 0x17) {
        return 0;
    }
    p->unk_106++;
    return 1;
}

void func_0801CA88(void) {
    s32 zero = 0;
    CpuSet(&zero, &gUnk_02039BB0, 0x05000084);
    if (gUnk_03006C10 & 0x800) {
        gUnk_02039BB0.unk_008 |= 8;
        gUnk_02039BB0.unk_008 |= 0x20;
    }
    gUnk_02039BB0.unk_00C = 4;
    gUnk_02039BB0.unk_00D = 1;
    func_0800F9A0();
    gUnk_02039BB0.unk_180 = 0xFFFF;
    func_080DFB2C();
    gUnk_02039BB0.unk_032 = gUnk_02039BB0.unk_0F8;
    gUnk_02039BB0.unk_024 = 0x2D;
    gUnk_02039BB0.unk_1B8 = 0;
}

void func_0801CB00(void) {
    gUnk_02039BB0.unk_000 = 0;
}

void func_0801CB0C(void) {
    gUnk_02039BB0.unk_000 = 1;
}

void func_0801CB18(void) {
    if (gUnk_02039BB0.unk_000 != 0) {
        SeedRandom(gUnk_02039BB0.unk_004);
    } else {
        gUnk_02039BB0.unk_004 = GetRandom();
        SeedRandom(gUnk_02039BB0.unk_004);
    }
}

void func_0801CB44(void) {
    SeedRandom(gUnk_03007480);
    func_0801CA88();
    func_0801CB00();
    func_0800ABD8();
    gUnk_02039DC0 = 0;
}

