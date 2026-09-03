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

u8 func_0800FA1C(void) {
    if (gUnk_02039CA8.unk_10 + gUnk_02039B84->unk_0FA + 1 <= 99) {
        gUnk_02039B84->unk_0FA++;
        gUnk_02039CA8.unk_10++;
        func_0800F988(&gUnk_02039CA8);
        return 1;
    } else {
        return 0;
    }
}
s32 func_0800FA58(void) {
    gUnk_02039BB0.maxHp += 15;
    if (gUnk_02039BB0.maxHp > 560) {
        gUnk_02039BB0.maxHp = 560;
    }
    return 15;
}
s32 func_0800FA7C(void) {
    gUnk_02039BB0.cp += 25;
    if (gUnk_02039BB0.cp > 9999) {
        gUnk_02039BB0.cp = 9999;
    }
    return 25;
}
s32 func_0800FAA0(void) {
    gUnk_02039BB0.dp += 2;
    if (gUnk_02039BB0.dp > 999) {
        gUnk_02039BB0.dp = 999;
    }
    return 2;
}
s32 func_0800FAC4(void) {
    gUnk_02039BB0.ap += 1;
    if (gUnk_02039BB0.ap > 999) {
        gUnk_02039BB0.ap = 999;
    }
    return 1;
}
void func_0800FAE8(u16 a) {
    gUnk_02039CA8.unk_08 += a;
}

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

u8 func_0800FF70(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x3F) {
        q = (u8*)&gUnk_02039BB0;
        q += 0x154;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gUnk_02039BB0;
        q += 0x15C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gUnk_02039BB0;
        q += 0x164;
    } else {
        a -= 0xC0;
        q = (u8*)&gUnk_02039BB0;
        q += 0x16C;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}
INCLUDE_ASM("unk_0800eebc/func_0800FFE0.s");
