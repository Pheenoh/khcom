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
    if (p->unk_040.unk_04 < (gBtlWork->unk_0DA + b) << 8) {
        return 1;
    }

    if (p->unk_040.unk_04 > (gBtlWork->unk_0DC - b) << 8) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_0800eebc/func_0800F504.s");
INCLUDE_ASM("unk_0800eebc/func_0800F5A4.s");
INCLUDE_ASM("unk_0800eebc/_0800F84C.s");

#ifdef NON_MATCHING
void func_0800F988(UnkStruct_02039CA8* p) {
    s32 n = p->level + 1;
    p->nextExp += n * n * 3;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0800F988.s");
#endif

void func_0800F9A0(void) {
    gUnk_02039CA8.maxHp = 0x50;
    gUnk_02039CA8.cp = 0x113;
    gUnk_02039CA8.dp = 8;
    gUnk_02039CA8.ap = 10;
    gUnk_02039CA8.exp = 0;
    gUnk_02039CA8.level = 1;
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
    gUnk_02039CA8.nextExp = 0x19;
    func_080C6FF8();
    func_080DDEA4();
    func_08109620();
}

u8 LevelUp(void) {
    if (gUnk_02039CA8.level + gBtlWork->unk_0FA + 1 <= 99) {
        gBtlWork->unk_0FA++;
        gUnk_02039CA8.level++;
        func_0800F988(&gUnk_02039CA8);
        return 1;
    } else {
        return 0;
    }
}
s32 func_0800FA58(void) {
    gGameState.maxHp += 15;
    if (gGameState.maxHp > 560) {
        gGameState.maxHp = 560;
    }
    return 15;
}
s32 func_0800FA7C(void) {
    gGameState.cp += 25;
    if (gGameState.cp > 9999) {
        gGameState.cp = 9999;
    }
    return 25;
}
s32 func_0800FAA0(void) {
    gGameState.dp += 2;
    if (gGameState.dp > 999) {
        gGameState.dp = 999;
    }
    return 2;
}
s32 func_0800FAC4(void) {
    gGameState.ap += 1;
    if (gGameState.ap > 999) {
        gGameState.ap = 999;
    }
    return 1;
}
void AddExp(u16 a) {
    gUnk_02039CA8.exp += a;
}

u8 CanLevelUp(void) {
    if (gUnk_02039CA8.exp >= gUnk_02039CA8.nextExp) {
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
        q = (u8*)&gGameState;
        q += 0x10C;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
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
        gGameState.unk_12C = -1;
    } else {
        gGameState.unk_12C |= 1LL << a;
    }
}

u8 func_0800FC5C(s32 a) {
    if (gGameState.unk_12C & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FC90(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        q += 0x1E8;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
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
        q = (u8*)&gGameState;
        q += 0x200;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
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
        q = (u8*)&gGameState;
        q += 0x11C;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
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
        GameState* s = &gGameState;
        s->unk_11C = 0;
        s->unk_124 = 0;
    } else {
        if (a <= 0x1E) {
            q = (u8*)&gGameState;
            q += 0x11C;
        } else {
            a -= 0x1F;
            q = (u8*)&gGameState;
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
        q = (u8*)&gGameState;
        q += 0x134;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gGameState;
        q += 0x13C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gGameState;
        q += 0x144;
    } else {
        a -= 0xC0;
        q = (u8*)&gGameState;
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
        q = (u8*)&gGameState;
        q += 0x154;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gGameState;
        q += 0x15C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gGameState;
        q += 0x164;
    } else {
        a -= 0xC0;
        q = (u8*)&gGameState;
        q += 0x16C;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}
INCLUDE_ASM("unk_0800eebc/func_0800FFE0.s");
