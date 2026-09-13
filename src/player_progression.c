#include "ms_api.h"
#include "player_progression.h"
#include "macros.h"
#include "battle.h"

GameState gGameState;

void AdvanceLevelExpThreshold(PlayerProgression* p) {
    s32 n = p->level + 1;

    if (p->level) {
        p->nextExp = n * n * 3 + p->nextExp;
    } else {
        p->nextExp = n * n * 3 + p->nextExp;
    }
}

void InitPlayerProgression(void) {
    PlayerProgression* p = &gGameState.progression;

    p->maxHp = 0x50;
    p->cp = 0x113;
    p->dp = 8;
    p->ap = 10;
    p->exp = 0;
    p->level = 1;
    p->unk_14 = 0;
    p->unk_1C = 0;
    p->unk_24 = 0;
    p->unk_2C = 0;
    p->unk_34 = 0;
    p->unk_3C[0] = 0;
    p->unk_3C[1] = 0;
    p->unk_3C[2] = 0;
    p->unk_3C[3] = 0;
    p->unk_3C[4] = 0;
    p->unk_3C[5] = 0;
    p->unk_3C[6] = 0;
    p->unk_3C[7] = 0;
    p->mooglePoints = 0;
    p->unk_80 = 0;
    p->unk_82 = 0;
    p->unk_84 = 0;
    p->nextExp = 0x19;
    func_080C6FF8();
    func_080DDEA4();
    func_08109620();
}

u8 LevelUp(void) {
    PlayerProgression* p = &gGameState.progression;

    if (p->level + gBtlWork->unk_0FA + 1 <= 99) {
        gBtlWork->unk_0FA++;
        p->level++;
        AdvanceLevelExpThreshold(p);
        return 1;
    } else {
        return 0;
    }
}
s32 LevelUpMaxHp(void) {
    gGameState.progression.maxHp += 15;
    if (gGameState.progression.maxHp > 560) {
        gGameState.progression.maxHp = 560;
    }
    return 15;
}
s32 LevelUpCp(void) {
    gGameState.progression.cp += 25;
    if (gGameState.progression.cp > 9999) {
        gGameState.progression.cp = 9999;
    }
    return 25;
}
s32 LevelUpDp(void) {
    gGameState.progression.dp += 2;
    if (gGameState.progression.dp > 999) {
        gGameState.progression.dp = 999;
    }
    return 2;
}
s32 LevelUpAp(void) {
    gGameState.progression.ap += 1;
    if (gGameState.progression.ap > 999) {
        gGameState.progression.ap = 999;
    }
    return 1;
}
void AddExp(u16 a) {
    PlayerProgression* p = &gGameState.progression;

    p->exp += a;
}

u8 CanLevelUp(void) {
    PlayerProgression* p = &gGameState.progression;

    if (p->exp >= p->nextExp) {
        return 1;
    }
    return 0;
}

const EnemyBaseStats* func_0800FB14(u16 i) {
    if (i > 0x35) {
        return 0;
    }
    return &gUnk_08133E5C[i];
}

void func_0800FB2C(u32 a) {
    u8* q;
    u8* z;

    if (a == 72) {
        z = (u8*)&gGameState;
        *(u64*)(z + 0x10C) = -1;
        *(u64*)(z + 0x114) = -1;
        return;
    }

    if (func_0800FBCC(a)) {
        return;
    }

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        *(u64*)(q + 0x10C) |= 1LL << a;
        *(u64*)(q + 0x11C) |= 1LL << a;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
        *(u64*)(q + 0x114) |= 1LL << a;
        *(u64*)(q + 0x124) |= 1LL << a;
    }
}

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
        gGameState.progression.unk_34 = -1;
    } else {
        gGameState.progression.unk_34 |= 1LL << a;
    }
}

u8 func_0800FC5C(s32 a) {
    if (gGameState.progression.unk_34 & (1LL << a)) {
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
        s->progression.unk_24 = 0;
        s->progression.unk_2C = 0;
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

void func_0800FDD0(u32 a) {
    GameState* state;

    if (a == 250) {
        GameState* state = &gGameState;
        state->progression.unk_3C[0] = -1;
        state->progression.unk_3C[1] = -1;
        state->progression.unk_3C[2] = -1;
        state->progression.unk_3C[3] = -1;
        state->progression.unk_3C[4] = -1;
        state->progression.unk_3C[5] = -1;
        state->progression.unk_3C[6] = -1;
        state->progression.unk_3C[7] = -1;
        return;
    }
    if (func_0800FF00(a)) {
        return;
    }
    if (a <= 0x3F) {
        state = &gGameState;
        state->progression.unk_3C[0] |= 1ULL << a;
        state->progression.unk_3C[4] |= 1ULL << a;
    } else if (a <= 0x7F) {
        a -= 0x40;
        state = &gGameState;
        state->progression.unk_3C[1] |= 1ULL << a;
        state->progression.unk_3C[5] |= 1ULL << a;
    } else if (a <= 0xBF) {
        a -= 0x80;
        state = &gGameState;
        state->progression.unk_3C[2] |= 1ULL << a;
        state->progression.unk_3C[6] |= 1ULL << a;
    } else {
        a -= 0xC0;
        state = &gGameState;
        state->progression.unk_3C[3] |= 1ULL << a;
        state->progression.unk_3C[7] |= 1ULL << a;
    }
}

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

void func_0800FFE0(u32 a) {
    u64* p;
    u8* q;
    u8* z;

    if (a == 250) {
        z = (u8*)&gGameState;
        *(u64*)(z + 0x154) = 0;
        *(u64*)(z + 0x15C) = 0;
        *(u64*)(z + 0x164) = 0;
        *(u64*)(z + 0x16C) = 0;
        return;
    }

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
    *p &= ~(1LL << a);
}
