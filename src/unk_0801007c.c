#include "macros.h"
#include "unk_0800eebc.h"

void func_080100A0(void);
void func_08001058(void (*a)(void), void (*b)(void));

UnkStruct_020348C8* gUnk_020348C8;
u16 gUnk_020348CC[2];
u16 gUnk_020348D0[2];
u16 gUnk_020348D4[2];
u16 gUnk_020348D8[2];
u16 gUnk_020348DC[2];
u16 gUnk_020348E0;
u16 gUnk_020348E2;
#ifndef VERSION_EU
u8 gUnk_020348E4[4];
#endif
ListNode gUnk_020348E8;
ListNode gUnk_020348F8;
ListNode gUnk_02034908;
ListNode gUnk_02034918;
BgFx* gUnk_02034928;

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
void func_080104F4(void) {
    func_08001058(func_0801007C, func_080100A0);
}

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

void func_08010548(u16 keys, s32 i) {
    if (keys & 0x200) {
        gUnk_020348CC[i]++;
        gUnk_020348D4[i] = 0;

        if (gUnk_020348CC[i] > 32) {
            gUnk_020348CC[i] = 29;
        }
    } else {
        gUnk_020348CC[i] = 0;

        if (gUnk_020348D4[i] < 255) {
            gUnk_020348D4[i]++;
        }
    }

    if (keys & 0x100) {
        gUnk_020348D0[i]++;
        gUnk_020348D8[i] = 0;

        if (gUnk_020348D0[i] > 32) {
            gUnk_020348D0[i] = 29;
        }
    } else {
        gUnk_020348D0[i] = 0;

        if (gUnk_020348D8[i] < 255) {
            gUnk_020348D8[i]++;
        }
    }
}
s32 func_08010600(u16 a, u16 b, s32 i) {
    s32 ret = 0;

    func_08010548(a, i);

    if (gUnk_020348D4[i] == 2) {
        gUnk_020348DC[i] &= 0xFDFF;
    }
    if (gUnk_020348D8[i] == 2) {
        gUnk_020348DC[i] &= 0xFEFF;
    }

    if (((b & 0x200) && (a & 0x100)) || ((b & 0x100) && (a & 0x200))) {
        gUnk_020348DC[i] |= 0x300;
        ret = 0x300;
    }

    if (!(gUnk_020348DC[i] & 0x200)) {
        if (gUnk_020348CC[i] == 5 || gUnk_020348D4[i] == 1) {
            gUnk_020348DC[i] |= 0x200;
            ret = 0x200;
        }
    }

    if (!(gUnk_020348DC[i] & 0x100)) {
        if (gUnk_020348D0[i] == 5 || gUnk_020348D8[i] == 1) {
            gUnk_020348DC[i] |= 0x100;
            ret = 0x100;
        }
    }
    return ret;
}
void func_0801071C(void) {
    s32 a;
    s32 b;

    a = 0;
    CpuSet(&a, gBtlWork, 0x05000074);
    b = 0;
    CpuSet(&b, gUnk_02039B9C, 0x05000074);
    gBtlWork->unk_0A0 = 0;
    gBtlWork->unk_0FC = -0x10000;
    gBtlWork->unk_12C = 66;
    gBtlWork->unk_0B3 = 10;
    gBtlWork->unk_068 |= 0x4000;
    gUnk_020348CC[0] = 0;
    gUnk_020348D0[0] = 0;
    gUnk_020348D4[0] = 0;
    gUnk_020348D8[0] = 0;
    gUnk_020348CC[1] = 0;
    gUnk_020348D0[1] = 0;
    gUnk_020348D4[1] = 0;
    gUnk_020348D8[1] = 0;
    gUnk_020348DC[0] = 0;
    gUnk_020348DC[1] = 0;
    gUnk_020348E0 = 0;
    gUnk_020348E2 = 0;
}
INCLUDE_ASM("unk_0800eebc/func_080107D4.s");
INCLUDE_ASM("unk_0800eebc/func_08010A24.s");

void func_08010C70(void) {
    gBtlWork->unk_0A0 = 1;

    if (!(gBtlWork->unk_068 & 0x800000)) {
        gBtlWork->unk_068 |= 0x20;
    }
    gBtlWork->unk_068 &= ~0x40;
    gBtlWork->unk_068 &= ~0x20000000;
}

INCLUDE_ASM("unk_0800eebc/func_08010CC8.s");

u8 func_08011270(BtlObj* p, s32 x, s32 y, s32 z, s16 a, s16 b, s16 c) {
    BtlObj* q = (BtlObj*)p->unk_0D8;
    u64 f;

    if (q != 0) {
        f = q->unk_034 | p->unk_034;
    } else {
        f = p->unk_034;
        q = p;
    }

    if (f & 0x01000180) {
        return 0;
    }
    if (x - (a << 8) > p->unk_004 + (p->unk_09E << 8)) {
        return 0;
    }
    if (x + (a << 8) < p->unk_004 - (p->unk_09E << 8)) {
        return 0;
    }
    if (y - (b << 8) > p->unk_008 + (p->unk_0A0 << 8)) {
        return 0;
    }
    if (y + (b << 8) < p->unk_008 - (p->unk_0A0 << 8)) {
        return 0;
    }
    if (z - (c << 8) > p->unk_00C) {
        return 0;
    }
    if (z + (c << 8) < p->unk_00C - (p->unk_09C << 8)) {
        return 0;
    }
    if (q->unk_0E2 > 0) {
        return 0;
    }
    return 1;
}

void func_08011364(BtlObj* a, HitData* b, s32* c) {
    gBtlWork->unk_076 = 8;
    a->unk_020 = -((b->unk_30 * *c) >> 8);
    a->unk_034 |= 0x20;
}

INCLUDE_ASM("unk_0800eebc/func_08011398.s");
#ifdef NON_MATCHING
u8 func_08011E3C(s32 x, s32 y, s32 z, s16 a, s16 b, s16 c) {
    BtlObj* o;

    gBtlWork->unk_0B4 = 1;
    gBtlWork->unk_0B8 = x;
    gBtlWork->unk_0BC = y;
    gBtlWork->unk_0C0 = z;
    gBtlWork->unk_0C4 = a;
    gBtlWork->unk_0C6 = b;
    gBtlWork->unk_0C8 = c;

    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            o = (BtlObj*)gUnk_02039B9C->unk_07C;
        } else {
            o = (BtlObj*)gBtlWork->unk_07C;
        }
    } else if (gBtlWork->unk_068 & 0x20000000) {
        o = ListPoolFirst(&gBtlWork->unk_080);

        while (o != 0) {
            if (func_08011270(o, x, y, z, a, b, c)) {
                return 1;
            }
            o = ListPoolNext(&o->unk_0B8);
        }
        return 0;
    } else {
        o = (BtlObj*)gBtlWork->unk_07C;
    }

    if (func_08011270(o, x, y, z, a, b, c) == 0) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("unk_0800eebc/func_08011E3C.s");
#endif

s32 func_08011F68(s32 a, s32 b) {
    return func_08011398(b, a);
}

INCLUDE_ASM("unk_0800eebc/func_08011F78.s");

s32 func_08012170(s32 a, s32 b, s32 c, s32 d) {
    return func_08011F78(a, b, c, d, 16, 16, 16);
}

s32 func_08012188(BtlObj* p, s16 h, s32 c) {
    if (p->unk_034 & 4) {
        return func_08012170(p->unk_004 - (h << 8), p->unk_008, p->unk_00C - (p->unk_09C >> 1), c);
    } else {
        return func_08012170(p->unk_004 + (h << 8), p->unk_008, p->unk_00C - (p->unk_09C >> 1), c);
    }
}

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
    ListPoolInit(&gUnk_020348E8);
    ListPoolInit(&gUnk_020348F8);
    ListPoolInit(&gUnk_02034908);
    ListPoolInit(&gUnk_02034918);
}

void func_080122AC(Collider* p, u32 type, u16 r, u16 h) {
    void* pool;
    p->unk_34 = 0;
    p->unk_2C = 0;
    p->unk_2E = 0;
    p->unk_30 = 0;
    p->radius = r << 8;
    p->height = h << 8;
    p->unk_00 = type;
    p->self = p;
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
    Collider* q = p->self;
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
    Collider* p = ListPoolFirst(pool);
    while (p != 0) {
        p->unk_2C = 0;
        p->unk_58 = 0;
        p->unk_2E = 0;
        p = ListPoolNext(&p->unk_18);
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
        p->unk_18.flags |= 2;
        p->unk_2C = 0;
        p->unk_2E = 0;
    } else {
        p->unk_18.flags &= ~2;
    }
}

u8 func_08012648(Collider* p) {
    return p->unk_2C;
}

void ColliderSetRadius(Collider* p, u16 r) {
    p->radius = r << 8;
}

void ColliderSetHeight(Collider* p, u16 h) {
    p->height = h << 8;
}

u8 func_08012660(Collider* p, s32 bit) {
    if (p->unk_58 & (1 << bit)) {
        return 1;
    }
    return 0;
}

void func_08012674(void) {
    if (gBtlWork->unk_068 & 4) {
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

void func_08012824(void) {
    if (gBtlWork->unk_068 & 0x400000) {
        gBtlWork->unk_068 &= ~0x400000;
        gUnk_02034928->unk_34 &= 0xFFFD;
        gUnk_02034928->unk_04 = 0;
        func_08006B4C();
        SetBgBlend(gUnk_02034928->unk_00, 16, 16);
    }

    if (gUnk_02034928->unk_04 != 0) {
        gUnk_02034928->unk_04();

        if (!(gBtlWork->unk_068 & 4)) {
            gBtlWork->unk_0D0 = gUnk_02034928->unk_14;

            if (gUnk_02034928->unk_34 & 0x10) {
                SetBgPriority(gUnk_02034928->unk_00, 0);
            } else if (gUnk_02034928->unk_34 & 0x20) {
                SetBgPriority(gUnk_02034928->unk_00, 1);
                gBtlWork->unk_0D8 = 0xFF00;
            } else {
                gBtlWork->unk_0D8 = 8;
            }
        }
    }
    func_08006954();
}

u8 func_080128EC(void) {
    if (gUnk_02034928->unk_34 & 2) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_0800eebc/func_08012908.s");
void func_08012AAC(u16 a, s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_4C = 20;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;

    switch (a) {
    case 0:
        gUnk_02034928->unk_18 = z - 0x1400;
        break;
    case 1:
        gUnk_02034928->unk_18 = z;
        break;
    case 2:
        gUnk_02034928->unk_18 = z - 0x1000;
        break;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);

    switch (a) {
    case 0:
        func_08006778(gUnk_09EDA558, sx, sy);
        m4aSongNumStart(0x204);
        break;
    case 1:
        func_08006778(gUnk_09EDA840, sx, sy);
        m4aSongNumStart(0x205);
        break;
    case 2:
        func_08006778(gUnk_09EDA828, sx, sy);
        m4aSongNumStart(0x206);
        break;
    }
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
    gUnk_02034928->unk_04 = func_08012908;
}

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
void func_08012E44(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
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

    if (a == 3) {
        func_08006778(gUnk_09EDA570 + 0x18, sx, sy);
    } else {
        func_08006778(gUnk_09EDA570, sx, sy);
    }

    if ((gBtlWork->unk_068 & 0x4000) == 0 && (gBtlWork->unk_068 & 0x40)) {
        m4aSongNumStart(0x23D);
    } else {
        m4aSongNumStart(0x1F8);
    }
    func_08006B34(8);
    gUnk_02034928->unk_04 = func_08012C08;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_08 = 15;
    gUnk_02034928->unk_26 = a;
    gUnk_02034928->unk_48 = w;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
    }
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08012F74(s32 x, s32 y, s32 z, u8 f, s32 unused, s32 w, u16 a) {
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
    func_08006778(gUnk_09EDA570, sx, sy);
    m4aSongNumStart(0x23D);
    func_08006B34(8);
    gUnk_02034928->unk_04 = func_08012C08;
    gUnk_02034928->unk_28 = gBtlWork->unk_07C->unk_04;
    gUnk_02034928->unk_2C = gBtlWork->unk_07C->unk_08;
    gUnk_02034928->unk_30 = gBtlWork->unk_07C->unk_0C;
    gUnk_02034928->unk_08 = a;
    gUnk_02034928->unk_26 = 1;
    gUnk_02034928->unk_48 = w;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x180;
    } else {
        gUnk_02034928->unk_1C = 0x180;
    }
    gUnk_02034928->unk_20 = 0x180;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_08013070.s");
void func_08013308(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
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
    func_08006778(gUnk_09EDA6D8, sx, sy);

    if ((gBtlWork->unk_068 & 0x4000) == 0 && (gBtlWork->unk_068 & 0x40)) {
        m4aSongNumStart(0x23E);
    } else {
        m4aSongNumStart(0x1FC);
    }
    func_08006B34(8);
    gUnk_02034928->unk_04 = func_08013070;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_08 = 15;
    gUnk_02034928->unk_26 = a;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_0A = 0;

    if (f) {
        gUnk_02034928->unk_1C = -0x100;
        gUnk_02034928->unk_34 |= 1;
    }
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

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

void func_08013480(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gUnk_02034928->unk_1C = 76;
    gUnk_02034928->unk_20 = 76;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_28 = 25;
    gUnk_02034928->unk_2C = 25;
    func_08006778(gUnk_09EDA618, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08013420;
    gUnk_02034928->unk_08 = 0;
}
void func_0801350C(void) {
    s16 t = gUnk_02034928->unk_08;

    gUnk_02034928->unk_24 += 4;
    gUnk_02034928->unk_1C += gUnk_02034928->unk_28;
    gUnk_02034928->unk_20 += gUnk_02034928->unk_2C;
    SetBlendAlpha(16, 16 - t);

    if (t > 15) {
        func_08006B4C();
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}
void func_08013560(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gUnk_02034928->unk_1C = 256;
    gUnk_02034928->unk_20 = 256;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_28 = 76;
    gUnk_02034928->unk_2C = 76;
    func_08006778(gUnk_09EDA618, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_0801350C;
    gUnk_02034928->unk_08 = 0;
}
void func_080135EC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    gUnk_02034928->unk_1C = 128;
    gUnk_02034928->unk_20 = 128;
    gUnk_02034928->unk_24 = 0;
    func_08006778(gUnk_09EDA618, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08013420;
    gUnk_02034928->unk_08 = 0;
}
void func_08013678(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA630, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_080136E0(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDAD38, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

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

void func_080137C8(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x + 0x400;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;

    if (f != 0) {
        gUnk_02034928->unk_1C = -0x100;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA648 + 0x18, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_08013854(s32 x, s32 y, s32 z) {
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
    func_08006778(gUnk_09EDA678, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_080138BC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    gUnk_02034928->unk_20 = 0x200;
    WorldToScreen(&sx, &sy, x, y, z - 0x1000);
    func_08006778(gUnk_09EDA5D0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_0801392C(s32 x, s32 y, s32 z) {
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
    func_08006778(gUnk_09EDA720, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

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

void func_08013A68(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_4C = 20;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x3000;
    WorldToScreen(&sx, &sy, x, y, z - 0x3000);
    func_08006778(gUnk_09EDA6C0, sx, sy);
    m4aSongNumStart(0x207);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_08013B00.s");
void func_08013CB4(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_30 = p;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA768, sx, sy);
    m4aSongNumStart(0x200);
    gUnk_02034928->unk_48 = q;
    gUnk_02034928->unk_04 = func_08013B00;
    gUnk_02034928->unk_26 = a;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

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

void func_08013DB8(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    SetBgBlend(gUnk_02034928->unk_00, 0, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA7F8, sx, sy);
    func_08006B34(4);
    m4aSongNumStart(0x209);
    gUnk_02034928->unk_04 = func_08013D60;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}
void func_08013E4C(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    SetBgBlend(gUnk_02034928->unk_00, 0, 16);
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA810, sx, sy);
    m4aSongNumStart(0x227);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_2C = 0;
    gUnk_02034928->unk_08 = 0;
}

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
    func_08006238(0, gBtlWork->unk_0B3, 8);
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
    func_08006238(0, gBtlWork->unk_0B3, 8);
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

void func_080141FC(BtlObj* p) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_44 = p;
    gUnk_02034928->unk_10 = p->unk_004;
    gUnk_02034928->unk_14 = p->unk_008;
    gUnk_02034928->unk_18 = p->unk_00C - 0x800;
    gUnk_02034928->unk_1C = 0x133;
    gUnk_02034928->unk_20 = 0x133;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDA768, sx, sy);
    func_08006B34(4);
    gUnk_02034928->unk_04 = func_080141D4;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_08014294.s");
INCLUDE_ASM("unk_0800eebc/func_0801440C.s");
void func_08014588(s32 x, s32 y, s32 z, s32 w, u16 a, u16 b) {
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
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = w;
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_28 = w;
    gUnk_02034928->unk_3C = 0;
    gUnk_02034928->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA38, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_0801440C;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_0C = b;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08014654(void) {
    u16 t;
    s16 u;
    gUnk_02034928->unk_1C += 25;
    gUnk_02034928->unk_20 += 25;
    func_08012908();
    t = gUnk_02034928->unk_08;

    if (gUnk_02034928->unk_08 > 3) {
        u = t - 3;
        SetBlendAlpha(16, 16 - u);

        if (u > 15) {
            func_08006B4C();
        }
    }
    gUnk_02034928->unk_08++;
}
void func_080146A8(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z - 0x1000;
    WorldToScreen(&sx, &sy, x, y, 0);
    gUnk_02034928->unk_1C = 512;
    gUnk_02034928->unk_20 = 768;
    gUnk_02034928->unk_24 = 0;
    func_08006778(gUnk_09EDA618, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08014654;
    gUnk_02034928->unk_08 = 0;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

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
#ifdef VERSION_EU
        if (gUnk_02034928->unk_08 == 20) {
#else
        if (gUnk_02034928->unk_08 == 21) {
#endif
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 48);
        }
        break;
    case 1:
#ifdef VERSION_EU
        if (gUnk_02034928->unk_08 == 20) {
#else
        if (gUnk_02034928->unk_08 == 25) {
#endif
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

void func_080148E0(u16 a, s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_4C = 20;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_26 = a;
    WorldToScreen(&sx, &sy, x, y, 0);

    switch (a) {
    case 0:
        func_08006778(gUnk_09EDA8A0, sx, sy);
        m4aSongNumStart(0x25C);
        break;
    case 1:
        func_08006778(gUnk_09EDA8B8, sx, sy);
        m4aSongNumStart(0x25D);
        break;
    case 2:
    default:
        func_08006778(gUnk_09EDA8D0, sx, sy);
        m4aSongNumStart(0x25E);
        break;
    }
    gUnk_02034928->unk_04 = func_08014850;
}

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

void func_08014B30(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA7E0, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08012908;
    gUnk_02034928->unk_34 |= 0x10;
}
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

void func_08014FDC(s32 x, s32 y, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y - 0x1000;
    SetBlendAlpha(16, 8);

    if (f) {
        gUnk_02034928->unk_34 |= 1;
    }
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, 0);
    gUnk_02034928->unk_1C = 128;
    gUnk_02034928->unk_20 = 128;
    gUnk_02034928->unk_24 = 0;
    gUnk_02034928->unk_0A = 0;
    func_08006778(gUnk_09EDA618, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08014F4C;
    gUnk_02034928->unk_08 = 0;
    gUnk_02034928->unk_34 |= 0x10;
}

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
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
    func_08006B34(3);
}

void func_0801519C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}

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
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080152DC(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 > 30) {
            func_08006184(2, 60);
            func_080063A8();
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (func_08006314() == 0) {
            func_08006B4C();
            func_08006120(2, 120);
            func_080063A8();
            gUnk_02034928->unk_04 = 0;
            gUnk_02034928->unk_34 &= ~2;
        }
        break;
    }
    func_0800675C(0, gUnk_02034928->unk_1C, gUnk_02034928->unk_20);
    gUnk_02034928->unk_1C += 20;
    gUnk_02034928->unk_20 += 20;
}

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

void func_080153C8(void) {
    s16 t;
    s16 u;

    switch (gUnk_02034928->unk_26) {
    case 0:
        t = gUnk_02034928->unk_08;
        SetBlendAlpha(16, t);
        func_0800592C(&gUnk_02034928->unk_1C, 0x100, 17 - t);
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;

        if (t > 15) {
            gUnk_02034928->unk_08 = gUnk_02034928->unk_0A;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        ApproachValue(&gUnk_02034928->unk_10, gUnk_02034928->unk_28, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_14, gUnk_02034928->unk_2C, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_18, gUnk_02034928->unk_30, gUnk_02034928->unk_08);
        ApproachValue(&gUnk_02034928->unk_1C, gUnk_02034928->unk_3C, gUnk_02034928->unk_08);
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
        u = (gUnk_02034928->unk_1C * 3) >> 6;

        if (gUnk_02034928->unk_08 <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, u, u, u)) {
            m4aSongNumStart(0x27F);
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08--;
        }
        break;
    case 2:
        t = gUnk_02034928->unk_08;
        SetBlendAlpha(16, 16 - t);

        if (t > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_1C += 7;
            gUnk_02034928->unk_20 += 7;
            gUnk_02034928->unk_18 -= gUnk_02034928->unk_1C;
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_080154F4(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s, u16 a, s32 t) {
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
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_0A = a;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA08, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_1C = 25;
    gUnk_02034928->unk_20 = 25;
    gUnk_02034928->unk_04 = func_080153C8;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_48 = s;
    gUnk_02034928->unk_3C = t;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080155BC(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;
    s32 t;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    t = sy << 8;
    gUnk_02034928->unk_1C = 384;
    gUnk_02034928->unk_20 = t / 40;
    if (gUnk_02034928->unk_20 < 384) {
        gUnk_02034928->unk_20 = 384;
    }
    func_08006778(gUnk_09EDA798, sx, sy);
    m4aSongNumStart(0x201);
    func_08011F78(w, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 256);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_08015698.s");
void func_08015834(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA768, sx, sy);
    m4aSongNumStart(0x200);
    gUnk_02034928->unk_48 = s;
    gUnk_02034928->unk_04 = func_08015698;
    gUnk_02034928->unk_26 = a;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_080158E8.s");
INCLUDE_ASM("unk_0800eebc/func_08015B50.s");
void func_08015D04(void) {
    if (gUnk_02034928->unk_08 <= 16) {
        SetBlendAlpha(16, gUnk_02034928->unk_08);
        gUnk_02034928->unk_08++;
    }
    func_08012908();
}
void func_08015D30(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = 0x100;
    gUnk_02034928->unk_20 = 0x100;
    WorldToScreen(&sx, &sy, x, y, z);
    gUnk_02034928->unk_34 |= 0x20;
    SetBlendAlpha(16, 0);
    gUnk_02034928->unk_26 = 0;
    func_08006778(gUnk_09EDAA80, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08015D04;
}
void func_08015DC8(s32 x, s32 y, s32 z) {
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
    gUnk_02034928->unk_1C = 0x200;
    gUnk_02034928->unk_20 = 0x200;
    func_08006B34(7);
    func_08006778(gUnk_09EDAA98, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}

void func_08015E3C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0: {
        u16 t = gUnk_02034928->unk_08;

        if ((s16)t <= 64) {
            SetBlendAlpha(16, (s16)t >> 2);
            gUnk_02034928->unk_08++;
        } else {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26++;
        }
        gUnk_02034928->unk_1C += 25;
        gUnk_02034928->unk_20 += 25;
        break;
    }
    case 1: {
        u16 t;

        gUnk_02034928->unk_1C += 0x100;
        gUnk_02034928->unk_20 += 0x100;
        t = gUnk_02034928->unk_08;

        if ((s16)t > 32) {
            func_08011F78(87, gUnk_02034928->unk_10, gUnk_02034928->unk_14, 0, 0x100, 0x100, 0x100);
            func_08019050(1, 0x100, gBtlWork->unk_010, gBtlWork->unk_014);
            func_08006120(2, 60);
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26++;
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    case 2: {
        u16 t = gUnk_02034928->unk_08;

        if ((s16)t <= 15) {
            SetBlendAlpha(16, 16 - t);
            gUnk_02034928->unk_08++;
        } else {
            func_08006B4C();
        }
        break;
    }
    }
    gUnk_02034928->unk_24++;
    func_08012908();
}
void func_08015F3C(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    SetBlendAlpha(16, 0);
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    gUnk_02034928->unk_1C = 0x300;
    gUnk_02034928->unk_20 = 0x300;
    func_08006778(gUnk_09EDAAB0, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_08 = 8;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_34 |= 0x10;
    gUnk_02034928->unk_04 = func_08015E3C;
    func_08006184(2, 40);
    func_08019050(80, 204, x, y + z + 0x2000);
}

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

void func_080160C0(void) {
    u16 k;
    u16 v;
    s16 t;

    func_08006B80(&k, &v);

    switch (k) {
    case 4:
        func_08011F78(91, gUnk_02034928->unk_10 + gUnk_02034928->unk_1C * 40, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 50);
        break;
    case 5:
        if (v == 0) {
            gUnk_02034928->unk_26 = 1;
        }
        break;
    case 6:
        if (v == 0) {
            gUnk_02034928->unk_26 = 2;
        }
        break;
    }

    switch (gUnk_02034928->unk_26) {
    case 1:
        gUnk_02034928->unk_3C += 51;

        if (gUnk_02034928->unk_34 & 1) {
            gUnk_02034928->unk_10 -= gUnk_02034928->unk_3C;
        } else {
            gUnk_02034928->unk_10 += gUnk_02034928->unk_3C;
        }
        break;
    case 2:
        gUnk_02034928->unk_3C += 51;

        if (gUnk_02034928->unk_34 & 1) {
            gUnk_02034928->unk_10 -= gUnk_02034928->unk_3C;
            gUnk_02034928->unk_1C -= 51;
        } else {
            gUnk_02034928->unk_10 += gUnk_02034928->unk_3C;
            gUnk_02034928->unk_1C += 51;
        }
        func_08011F78(91, gUnk_02034928->unk_10 + gUnk_02034928->unk_1C * 40, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 32, 50);

        if (gUnk_02034928->unk_08 > 20) {
            t = 36 - gUnk_02034928->unk_08;
            SetBlendAlpha(16, t);

            if (t <= 0) {
                func_08006B4C();
            }
        }
        gUnk_02034928->unk_08++;
        break;
    }
    func_08012908();
}
void func_080161F8(s32 x, s32 y, s32 z, u8 f) {
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
    gUnk_02034928->unk_26 = 0;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
    }
    gUnk_02034928->unk_3C = 0;
    m4aSongNumStart(0x27D);
    func_08006778(&gUnk_09EDAAC8[0x30], sx, sy);
    func_08006B34(6);
    gUnk_02034928->unk_04 = func_080160C0;
}

void func_080162A8(s32 x, s32 y, s32 z, s32 w) {
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
    func_08006778(gUnk_09EDAA20, sx, sy);
    gUnk_02034928->unk_1C = w;
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_04 = func_08012BCC;
}

Collider* func_08016320(void) {
    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            return gBtlWork->unk_07C;
        }
        return gUnk_02039B9C->unk_07C;
    }

    if (gBtlWork->unk_078 != 0) {
        return gBtlWork->unk_078;
    }
    return ListPoolFirst(&gBtlWork->unk_080);
}

void func_08016374(s16 a) {
    BtlObj* o;

    if (gBtlWork->unk_068 & 0x4000) {
        if (GetRandom() % 5) {
            if (gBtlWork->unk_068 & 0x20000000) {
                func_08019190((BtlObj*)gBtlWork->unk_07C, 2);
            } else {
                func_08019190((BtlObj*)gUnk_02039B9C->unk_07C, 2);
            }
        } else {
            o = (BtlObj*)gUnk_02039B9C->unk_07C;
            o->unk_02C = a;

            if (a > o->unk_02E) {
                o->unk_02C = o->unk_02E;
            }
            o = (BtlObj*)gBtlWork->unk_07C;
            o->unk_02C = a;

            if (a > o->unk_02E) {
                o->unk_02C = o->unk_02E;
            }
        }
    } else {
        o = ListPoolFirst(&gBtlWork->unk_080);

        while (o != 0) {
            if (o->unk_034 & 0x40000000) {
                func_08019190(o, 0);
            } else {
                o->unk_02C = a;

                if (a > o->unk_02E) {
                    o->unk_02C = o->unk_02E;
                }
            }
            o = ListPoolNext(&o->unk_0B8);
        }
    }
}
void func_08016468(void) {
    BtlObj* o;

    switch (gUnk_02034928->unk_26) {
    case 0:
        gUnk_02034928->unk_1C = (gSineTable[((u16)gUnk_02034928->unk_08 * 4) & 0xFF] >> 3) + 89;

        if (gUnk_02034928->unk_0A > 0) {
            func_0800592C(&gUnk_02034928->unk_18, gUnk_02034928->unk_30 - 0x2000, gUnk_02034928->unk_0A);
            gUnk_02034928->unk_0A--;
        } else {
            gUnk_02034928->unk_26 = 1;
            gUnk_02034928->unk_0A = 60;
        }
        break;
    case 1:
        gUnk_02034928->unk_1C = (gSineTable[((u16)gUnk_02034928->unk_08 * 4) & 0xFF] >> 3) + 89;
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_26 = 2;
            gUnk_02034928->unk_0A = 50;
        }
        break;
    case 2:
        gUnk_02034928->unk_1C = (gSineTable[((u16)gUnk_02034928->unk_08 * 4) & 0xFF] >> 3) + 89;
        o = (BtlObj*)func_08016320();

        if (o != 0) {
            func_0800592C(&gUnk_02034928->unk_10, o->unk_004, gUnk_02034928->unk_0A);
            func_0800592C(&gUnk_02034928->unk_14, o->unk_008, gUnk_02034928->unk_0A);
            func_0800592C(&gUnk_02034928->unk_18, o->unk_00C - (o->unk_0A2 << 8), gUnk_02034928->unk_0A);
        }
        gUnk_02034928->unk_0A--;

        if (o != 0) {
            if (gUnk_02034928->unk_0A > 0) {
                break;
            }
            func_08016374(o->unk_02C);
        }
        gUnk_02034928->unk_26 = 3;
        m4aSongNumStart(0x298);
        gUnk_02034928->unk_0A = 16;
        break;
    case 3:
        gUnk_02034928->unk_1C += 166;
        gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
        SetBlendAlpha(16, gUnk_02034928->unk_0A);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            func_08006B4C();
        }
        break;
    }
    gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
    gUnk_02034928->unk_08++;
    func_08012908();
}
void func_080165DC(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_30 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 50;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA20, sx, sy);
    gUnk_02034928->unk_1C = 89;
    gUnk_02034928->unk_20 = 89;
    gUnk_02034928->unk_04 = func_08016468;
    m4aSongNumStart(0x297);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08016684(s32 x, s32 y, s32 z) {
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
    func_08006778(gUnk_09EDAB70, sx, sy);
    gUnk_02034928->unk_1C = 0x200;
    gUnk_02034928->unk_20 = 0x200;
    gUnk_02034928->unk_04 = func_08012908;
}

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

void func_08016750(s32 x, s32 y, s32 z, u8 f) {
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
    func_08006778(gUnk_09EDAA20, sx, sy);
    gUnk_02034928->unk_1C = 38;
    gUnk_02034928->unk_20 = 256;
    gUnk_02034928->unk_28 = 7;
    gUnk_02034928->unk_2C = 153;

    if (f) {
        gUnk_02034928->unk_24 += 40;
    } else {
        gUnk_02034928->unk_24 -= 40;
    }
    gUnk_02034928->unk_04 = func_080166F8;
}
void func_080167F8(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, (gUnk_02034928->unk_08 >> 1) + 8);
        func_0800592C(&gUnk_02034928->unk_1C, gUnk_02034928->unk_28, 17 - gUnk_02034928->unk_08);
        func_0800592C(&gUnk_02034928->unk_20, gUnk_02034928->unk_2C, 17 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_080168B8(s32 x, s32 y, s32 z, u8 f, s32 w, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_26 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB10, sx, sy);

    if (f) {
        gUnk_02034928->unk_28 = w;
        gUnk_02034928->unk_1C = 76;
    } else {
        gUnk_02034928->unk_28 = -w;
        gUnk_02034928->unk_1C = -76;
    }
    gUnk_02034928->unk_2C = w;
    gUnk_02034928->unk_20 = 76;
    m4aSongNumStart(0x282);
    gUnk_02034928->unk_04 = func_080167F8;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080169A0(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 45;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAB40, sx, sy);

    if (f) {
        gUnk_02034928->unk_1C = -0x100;
    } else {
        gUnk_02034928->unk_1C = 0x100;
    }
    gUnk_02034928->unk_20 = 0x100;
    gUnk_02034928->unk_04 = func_0801519C;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_08016A64(void) {
    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_10 += 0x700;
    } else {
        gUnk_02034928->unk_10 += -0x700;
    }

    if (gUnk_02034928->unk_10 < (gBtlWork->unk_0DA - 0x40) << 8 || gUnk_02034928->unk_10 > (gBtlWork->unk_0DC + 0x40) << 8) {
        func_08006B4C();
    } else if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 16, 16, 48)) {
        m4aSongNumStart(0x27F);
    }
    func_08012908();
}

void func_08016AF4(s32 x, s32 y, s32 z, u8 f, s32 w) {
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
    func_08006778(gUnk_09EDAB40 + 0x18, sx, sy);

    if (f) {
        gUnk_02034928->unk_1C = 0x100;
    } else {
        gUnk_02034928->unk_1C = -0x100;
        gUnk_02034928->unk_34 |= 1;
    }
    gUnk_02034928->unk_20 = 0x100;
    m4aSongNumStart(0x27E);
    gUnk_02034928->unk_04 = func_08016A64;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08016BCC(s32 x, s32 y) {
    s16 sx;
    s16 sy;

    if (func_080126E4(2)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    WorldToScreen(&sx, &sy, x, y, 0);
    func_08006778(gUnk_09EDA888, sx, sy);
    gUnk_02034928->unk_1C = 0x900;
    gUnk_02034928->unk_20 = 0x900;
    gUnk_02034928->unk_04 = func_08012908;
}
void func_08016C40(s32 x, s32 y, s32 z, s32 w, u8 f, u16 a) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_24 = f;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDAB28, sx, sy);
    gUnk_02034928->unk_20 = w;
    gUnk_02034928->unk_04 = func_0801519C;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_08016D00.s");
void func_08016F2C(s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w) {
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
    func_08006778(gUnk_09EDA570, sx, sy);
    m4aSongNumStart(0x29D);
    func_08006B34(8);
    gUnk_02034928->unk_04 = func_08016D00;
    gUnk_02034928->unk_28 = p;
    gUnk_02034928->unk_2C = q;
    gUnk_02034928->unk_30 = r;
    gUnk_02034928->unk_08 = 15;
    gUnk_02034928->unk_26 = 3;
    gUnk_02034928->unk_48 = w;

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
    }
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017008(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_1C = 0x180;
    gUnk_02034928->unk_20 = 0x180;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDA858, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_0801709C(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            func_08006B4C();
            gUnk_02034928->unk_04 = 0;
            gUnk_02034928->unk_34 &= ~2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
}
void func_08017138(u16 a) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_26 = 0;
    func_08006778(gUnk_09EDABD0, 120, 80);
    gUnk_02034928->unk_04 = func_0801709C;
    func_08006B34(0);
    gUnk_02034928->unk_34 |= 0x10;
}
void func_0801718C(void) {
    u16 t;
    s32 w;
    t = (gSineTable[(gUnk_02034928->unk_0C / 3) & 0xFF] * 10240) >> 16;
    w = ((abs(gSineTable[(u8)gUnk_02034928->unk_0C]) >> 1) + 0x100) * 0x133 >> 8;
    func_0800675C(t + 15, 0x133, w);
    func_0801709C();
    gUnk_02034928->unk_0C++;
}
void func_080171FC(u16 a) {
    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_0A = a;
    gUnk_02034928->unk_0C = 0;
    gUnk_02034928->unk_26 = 0;
    func_08006778(gUnk_09EDABE8, 120, 80);
    func_0800675C(10, 0x133, 0x133);
    gUnk_02034928->unk_04 = func_0801718C;
    func_08006B34(0);
    gUnk_02034928->unk_34 |= 0x10;
}

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
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080172F8(s32 x, s32 y, s32 z, s32 s) {
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
    func_08006778(gUnk_09EDA6F0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017390(s32 x, s32 y, s32 z) {
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
    func_08006778(gUnk_09EDAB88, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
}
void func_08017410(void) {
    if (gUnk_02034928->unk_0C > 0) {
        func_0800592C(&gUnk_02034928->unk_1C, 0x200, gUnk_02034928->unk_0C);
        gUnk_02034928->unk_0C--;
    }

    if (gUnk_02034928->unk_0E > 0) {
        ApproachValue(&gUnk_02034928->unk_20, 0x180, gUnk_02034928->unk_0E);
        gUnk_02034928->unk_0E--;
    }

    switch (gUnk_02034928->unk_26) {
    case 0: {
        u16 t;

        SetBlendAlpha(16, gUnk_02034928->unk_08);
        t = gUnk_02034928->unk_08;

        if ((s16)t > 15) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    case 1: {
        u16 t;

        func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 32, 16, 256);
        t = gUnk_02034928->unk_08;

        if ((s16)t > gUnk_02034928->unk_0A) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    case 2: {
        u16 a = gUnk_02034928->unk_08;
        u16 t;

        SetBlendAlpha(16, 16 - ((s16)a >> 1));
        ApproachValue(&gUnk_02034928->unk_1C, 10, 33 - gUnk_02034928->unk_08);
        t = gUnk_02034928->unk_08;

        if ((s16)t > 31) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08 = t + 1;
        }
        break;
    }
    }
    func_08012908();
}
void func_08017514(s32 x, s32 y, s32 z, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = 120;
    gUnk_02034928->unk_0C = 60;
    gUnk_02034928->unk_0E = 20;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_1C = 10;
    gUnk_02034928->unk_20 = 10;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC00, sx, sy);
    gUnk_02034928->unk_04 = func_08017410;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080175BC(Collider* a, BtlObj* b, u8 c, u8 d) {
    s32 h;
    s32 dx;
    s32 dy;
    s32 t;
    s32 nx;
    s32 ny;

    if (d) {
        b->unk_0B0 = GetAngle(a->unk_04, a->unk_08, b->unk_004, b->unk_008);
        b->unk_0A8 = 0;
    }
    dx = b->unk_004 - gUnk_02034928->unk_10;

    if (dx >= 0 ? dx <= 0x4FFF : gUnk_02034928->unk_10 - b->unk_004 <= 0x4FFF) {
        dy = b->unk_008 - gUnk_02034928->unk_14;

        if (dy >= 0 ? dy <= 0x27FF : gUnk_02034928->unk_14 - b->unk_008 <= 0x27FF) {
            if (gUnk_02034928->unk_34 & 1) {
                h = b->unk_0A8 - ((gUnk_02034928->unk_10 - b->unk_004) >> 1);
            } else {
                h = b->unk_0A8 + ((gUnk_02034928->unk_10 - b->unk_004) >> 1);
            }

            if (h > 0) {
                h = 0;
            }
            t = -(h >> 9);
            nx = gUnk_02034928->unk_10 + gSineTable[(b->unk_0B0 + c) & 0xFF] * (s16)t;
            ny = gUnk_02034928->unk_14 + -gSineTable[((b->unk_0B0 + c) & 0xFF) + 64] * ((s16)t >> 1);

            if (b->unk_004 < nx) {
                b->unk_034 &= ~4;
            } else {
                b->unk_034 |= 4;
            }
            b->unk_004 += (nx - b->unk_004) >> 3;
            b->unk_008 += (ny - b->unk_008) >> 3;
            b->unk_00C += (h - b->unk_00C) >> 2;
            b->unk_0A8 -= 110;
        }
    }
}

void func_08017728(u8 a, u8 b) {
    Collider* p;
    BtlObj* o;

    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            p = gBtlWork->unk_07C;
            o = (BtlObj*)gUnk_02039B9C->unk_07C;
        } else {
            p = gUnk_02039B9C->unk_07C;
            o = (BtlObj*)gBtlWork->unk_07C;
        }

        func_080175BC(p, o, a, b);
    } else {
        p = gBtlWork->unk_07C;
        o = ListPoolFirst(&gBtlWork->unk_080);

        while (o != 0) {
            if (!(o->unk_034 & 0x40000000) && o->unk_000 != 31) {
                func_080175BC(p, o, a, b);
            }

            o = ListPoolNext(&o->unk_0B8);
        }
    }
}
INCLUDE_ASM("unk_0800eebc/func_080177EC.s");
void func_080179F8(s32 x, s32 y, s32 z, s32 w, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_0A = 220;
    gUnk_02034928->unk_0C = 0;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_20 = 10;

    if (f) {
        gUnk_02034928->unk_1C = -10;
        gUnk_02034928->unk_34 |= 1;
    } else {
        gUnk_02034928->unk_1C = 10;
    }
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAC18, sx, sy);
    gUnk_02034928->unk_04 = func_080177EC;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08017AC0(void) {
    s16 v;
    s16 w;

    switch (gUnk_02034928->unk_26) {
    case 0:
        gUnk_02034928->unk_1C += 0x80;

        if (gUnk_02034928->unk_08 > 60) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        v = gUnk_02034928->unk_08;
        SetBlendAlpha(16, v + 8);

        if (v > 7) {
#ifdef VERSION_EU
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14 + 0x1000, 0, 0x100, 0x100, 0x100);
#else
            func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14 + 0x1000, 0, 0x100, 0x100, 8);
#endif
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        w = gUnk_02034928->unk_08 >> 2;
        SetBlendAlpha(16, 16 - w);

        if (w > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_08017B74(s32 x, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = gBtlWork->unk_0DE << 8;
    gUnk_02034928->unk_18 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_1C = 10;
    gUnk_02034928->unk_20 = -((gBtlWork->unk_0E0 - gBtlWork->unk_0DE) << 8) / 96;
    WorldToScreen(&sx, &sy, x, gUnk_02034928->unk_14, 0);
    func_08006778(gUnk_09EDAC00, sx, sy);
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_26 = 0;
    SetBlendAlpha(16, 8);
    gUnk_02034928->unk_04 = func_08017AC0;
    func_08006B34(0);
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
INCLUDE_ASM("unk_0800eebc/func_08017C54.s");
void func_08017E18(s32 x, u8 f, s32 w) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
    gUnk_02034928->unk_18 = 0;
    gUnk_02034928->unk_48 = w;
    gUnk_02034928->unk_0A = 20;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, 0);
    func_08006778(gUnk_09EDAC60, sx, sy);

    if (f) {
        gUnk_02034928->unk_1C = 10;
        gUnk_02034928->unk_28 = x - 0x3700;
    } else {
        gUnk_02034928->unk_1C = -10;
        gUnk_02034928->unk_28 = x + 0x3700;
        gUnk_02034928->unk_34 |= 1;
    }
    gUnk_02034928->unk_20 = 10;
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_08017C54;
    func_08006B34(0);
}

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
    func_08006238(0, gBtlWork->unk_0B3, 8);
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
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_080180C8(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_08 > 50) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        gUnk_02034928->unk_08 = 0;
        gUnk_02034928->unk_26 = 2;

        if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 0x100, 0x100, 0x100)) {
            m4aSongNumStart(0x2AF);
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    gUnk_02034928->unk_28 += 30;
    gUnk_02034928->unk_24 += gUnk_02034928->unk_28 >> 8;
    gUnk_02034928->unk_1C += 10;
    gUnk_02034928->unk_20 = gUnk_02034928->unk_1C;
    func_08012908();
}
void func_08018184(s32 x, s32 y, s32 z, s32 w) {
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
    func_08006778(gUnk_09EDACC0, sx, sy);
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 5;
    gUnk_02034928->unk_20 = 5;
    gUnk_02034928->unk_28 = 256;
    gUnk_02034928->unk_34 |= 0x10;
    m4aSongNumStart(0x2AE);
    gUnk_02034928->unk_04 = func_080180C8;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08018240(void) {
    if ((s16)gBtlWork->unk_072 != 0) {
        func_08012908();
        return;
    }

    if (gUnk_02034928->unk_34 & 1) {
        gUnk_02034928->unk_24 += 3;
    } else {
        gUnk_02034928->unk_24 -= 3;
    }
    gUnk_02034928->unk_10 = gUnk_02034928->unk_28 + ((gSineTable[gUnk_02034928->unk_24] * gUnk_02034928->unk_3C) >> 8);
    gUnk_02034928->unk_18 = gUnk_02034928->unk_30 + ((-gSineTable[gUnk_02034928->unk_24 + 64] * gUnk_02034928->unk_3C) >> 8);

    if (func_08011F78(gUnk_02034928->unk_48, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18, 10, 5, 72)) {
        m4aSongNumStart(0x2AD);
    }

    switch (gUnk_02034928->unk_26) {
    case 0:
        SetBlendAlpha(16, (u16)gUnk_02034928->unk_08 * 2);

        if (gUnk_02034928->unk_08 > 7) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        if (gUnk_02034928->unk_08 > 30) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 2;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 2:
        SetBlendAlpha(16, 16 - (u16)gUnk_02034928->unk_08 * 2);

        if (gUnk_02034928->unk_08 > 7) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    func_08012908();
}
void func_0801836C(s32 x, s32 y, s32 z, s32 w, s32 v) {
    s16 sx;
    s16 sy;
    s32 d;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_48 = v;

    if (w > 0) {
        gUnk_02034928->unk_1C = -0x180;
        gUnk_02034928->unk_34 |= 1;
        x -= 0x4000;
        w += 0x4000;
    } else {
        gUnk_02034928->unk_1C = 0x180;
        x += 0x4000;
        w -= 0x4000;
    }
    gUnk_02034928->unk_28 = x;
    gUnk_02034928->unk_30 = z;
    d = abs(w);
    gUnk_02034928->unk_3C = d;
    gUnk_02034928->unk_10 = x + ((gSineTable[0] * d) >> 8);
    gUnk_02034928->unk_18 = z + ((-gSineTable[64] * d) >> 8);
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_20 = 0x180;
    SetBlendAlpha(16, 0);
    m4aSongNumStart(0x2AC);
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(&gUnk_09EDACC0[0x18], sx, sy);
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_04 = func_08018240;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_0801848C(void) {
    s16 t = gUnk_02034928->unk_08 >> 1;
    SetBlendAlpha(16, 16 - t);

    if (t > 15) {
        func_08006B4C();
    }
    gUnk_02034928->unk_08++;
    func_08012908();
}

void func_080184C4(s32 x, s32 y, s32 z, u8 f) {
    s16 sx;
    s16 sy;

    if (func_080126E4(3)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_24 = f;
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    func_08006778(gUnk_09EDACA8, sx, sy);
    gUnk_02034928->unk_34 |= 0x20;
    gUnk_02034928->unk_04 = func_0801848C;
}
void func_0801853C(s32 x, s32 y, s32 z, s32 s) {
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
    func_08006778(gUnk_09EDACF0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_080185D0(void) {
    s32 x;
    s32 y;
    s32 z;
    s16 r;
    u8 ang;
    BtlObj* o;

    switch (gUnk_02034928->unk_26) {
    case 0:
        if (gUnk_02034928->unk_34 & 1) {
            func_0800592C(&gUnk_02034928->unk_1C, -204, gUnk_02034928->unk_0A);
        } else {
            func_0800592C(&gUnk_02034928->unk_1C, 204, gUnk_02034928->unk_0A);
        }
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    case 1:
        SetBlendAlpha(16, 16 - gUnk_02034928->unk_08);

        if (gUnk_02034928->unk_08 > 15) {
            func_08006B4C();
        } else {
            gUnk_02034928->unk_08++;
        }
        break;
    }
    r = (abs(gUnk_02034928->unk_1C) * 5) >> 4;

    if (gUnk_02034928->unk_34 & 1) {
        ang = gUnk_02034928->unk_24 + 192;
    } else {
        ang = gUnk_02034928->unk_24 + 64;
    }
    x = gUnk_02034928->unk_10 + gSineTable[ang] * r;
    z = gUnk_02034928->unk_18 + -gSineTable[ang + 64] * r;
    y = gUnk_02034928->unk_14;
    func_08011F78(gUnk_02034928->unk_48, x, y, z, 32, 16, 16);
    o = (BtlObj*)gBtlWork->unk_07C;

    if (o->unk_034 & 0x2000) {
        o->unk_004 += (x - o->unk_004) >> 2;
        o->unk_008 += (y - o->unk_008) >> 2;
        o->unk_00C += (z - o->unk_00C) >> 1;
    }
    func_08012908();
}
void func_08018724(s32 x, s32 y, s32 z, u8 f, s32 v) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_0A = 80;
    gUnk_02034928->unk_48 = v;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(&gUnk_09EDACF0[0x18], sx, sy);

    if (f) {
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_24 = 248;
    } else {
        gUnk_02034928->unk_24 = 8;
    }

    if (gUnk_02034928->unk_34 & 1) {
        if (gUnk_02034928->unk_10 < gBtlWork->unk_07C->unk_04) {
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_1C = -(((gUnk_02034928->unk_10 - gBtlWork->unk_07C->unk_04) << 8) / 19200);
        }
    } else {
        if (gUnk_02034928->unk_10 > gBtlWork->unk_07C->unk_04) {
            gUnk_02034928->unk_26 = 1;
        } else {
            gUnk_02034928->unk_1C = ((gBtlWork->unk_07C->unk_04 - gUnk_02034928->unk_10) << 8) / 19200;
        }
    }
    func_08006B34(3);
    gUnk_02034928->unk_04 = func_080185D0;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

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
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}

void func_08018970(s32 x, s32 y, s32 z) {
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
    func_08006778(gUnk_09EDAD50, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_080189DC(s32 x, s32 y, s32 z, s32 s) {
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
    func_08006778(gUnk_09EDAD68, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08018A70(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = -s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD68, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
    func_08006238(0, gBtlWork->unk_0B3, 8);
    gUnk_02034928->unk_34 |= 8;
}
void func_08018B04(s32 x, s32 y, s32 z, s32 s) {
    s16 sx;
    s16 sy;

    if (func_080126E4(1)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    gUnk_02034928->unk_1C = s;
    gUnk_02034928->unk_20 = s;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAD80, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
void func_08018B78(void) {
    switch (gUnk_02034928->unk_26) {
    case 0:
        ApproachValue(&gUnk_02034928->unk_3C, 0xA00, gUnk_02034928->unk_0A);
        func_0800592C(&gUnk_02034928->unk_1C, 460, gUnk_02034928->unk_0A);
        func_0800592C(&gUnk_02034928->unk_20, 512, gUnk_02034928->unk_0A);
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 1;
        }
        break;
    case 1:
        gUnk_02034928->unk_26 = 2;
        gUnk_02034928->unk_08 = 0;
        gUnk_02034928->unk_0A = 25;
        break;
    case 2:
        ApproachValue(&gUnk_02034928->unk_3C, 0, gUnk_02034928->unk_0A);
        SetBlendAlpha(16, gUnk_02034928->unk_3C >> 8);
        gUnk_02034928->unk_0A--;

        if (gUnk_02034928->unk_0A <= 0) {
            gUnk_02034928->unk_08 = 0;
            gUnk_02034928->unk_26 = 3;
            func_08006B4C();
        }
        break;
    }
    func_08012908();
}
void func_08018C38(s32 x, s32 y, s32 z) {
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
    gUnk_02034928->unk_26 = 0;
    gUnk_02034928->unk_1C = 10;
    gUnk_02034928->unk_20 = 10;
    gUnk_02034928->unk_3C = 0;
    gUnk_02034928->unk_36 = 0;
    WorldToScreen(&sx, &sy, x, y, z);
    func_08006778(gUnk_09EDAA38, sx, sy);
    func_08006B34(0);
    gUnk_02034928->unk_04 = func_08018B78;
    gUnk_02034928->unk_0A = 43;
}
INCLUDE_ASM("unk_0800eebc/func_08018CC4.s");
void func_08018F28(s32 x, s32 y, s32 z) {
    s16 sx;
    s16 sy;

    if (func_080126E4(0)) {
        return;
    }
    func_08012674();
    gUnk_02034928->unk_10 = x;
    gUnk_02034928->unk_14 = y;
    gUnk_02034928->unk_18 = z;
    m4aSongNumStart(0x2C1);
    WorldToScreen(&sx, &sy, gUnk_02034928->unk_10, gUnk_02034928->unk_14, gUnk_02034928->unk_18);
    gUnk_02034928->unk_26 = GetRandom() % 2;
    switch (gUnk_02034928->unk_26) {
    case 0:
        func_08006778(gUnk_09EDAD98, sx, sy);
        break;
    case 1:
        func_08006778(gUnk_09EDAD98, sx, sy);
        gUnk_02034928->unk_34 |= 1;
        gUnk_02034928->unk_1C = -0x100;
        break;
    }
    gUnk_02034928->unk_04 = func_08018CC4;
}
void func_08018FE4(s32 x, s32 y, s32 z) {
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
    func_08006778(gUnk_09EDADB0, sx, sy);
    gUnk_02034928->unk_04 = func_08012908;
}
