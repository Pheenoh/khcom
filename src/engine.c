#include "macros.h"
#include "engine.h"
#include "types.h"

void* func_08000BC8(void* node, void* pool);
void func_08000BF4(void* node, void* pool, void* after);
void func_08000C24(void* node, void* pool, void* before);
void* func_08000C8C(void* pool);
void* func_08000CD4(void* node);
void* func_08000D0C(void* pool);
void* func_08007E00(void* src, void* dst, u16 size);

INCLUDE_ASM("engine/func_0800216C.s");
INCLUDE_ASM("engine/func_080022D4.s");
u8 DrawSprite(u16 x, u16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h) {
    if (*(u16*)(gUnk_030074C8 + 0x28A8) <= 127 && obj != 0) {
        switch (*(u32*)((u8*)obj + 0x28)) {
        case 0:
            return func_08002060((s16)x, (s16)y, c, obj, e, f, g, h);
        case 1:
            return func_0800216C((s16)x, (s16)y, c, obj, e, f, g, h);
        case 2:
            return func_080022D4((s16)x, (s16)y, obj, e, f, g, h);
        }
    }
    return 0;
}
INCLUDE_ASM("engine/func_08002488.s");
#ifdef NON_MATCHING
ObjTiles* LoadObjTiles(void* src, u16 size) {
    ObjTiles* node;
    ObjTiles* cur;
    ObjTiles* next;
    u16 end;

    if (size == 0) {
        return 0;
    }
    if (src == 0) {
        return 0;
    }
    cur = func_08000C8C(gUnk_030074C8 + 0x1800);
    while (cur != 0) {
        if (cur->unk_00 == src && cur->unk_24 != 0) {
            cur->unk_04++;
            return cur;
        }
        cur = func_08000CD4(cur->unk_0C);
    }
    node = func_08000D0C(gUnk_030074C8 + 0x1800);
    if (node == 0) {
        return 0;
    }
    node->unk_28 = 0;
    node->unk_08 = size / 32;
    node->unk_00 = src;
    node->unk_04 = 0;
    node->unk_20 = 0;
    node->unk_24 = 0;
    node->unk_2C = node;
    cur = func_08000C8C(gUnk_030074C8 + 0x1800);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gUnk_030074C8 + 0x1810);
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        func_08000BC8(node->unk_0C, gUnk_030074C8 + 0x1800);
        return node;
    }
    node->unk_06 = *(u16*)(gUnk_030074C8 + 0x1810);
    if (node->unk_08 <= (s16)(cur->unk_06 - *(u16*)(gUnk_030074C8 + 0x1810))) {
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        func_08000C24(node->unk_0C, gUnk_030074C8 + 0x1800, cur->unk_0C);
        return node;
    }
    while (cur != 0) {
        next = func_08000CD4(cur->unk_0C);
        node->unk_06 = cur->unk_08 + cur->unk_06;
        end = *(u16*)(gUnk_030074C8 + 0x1812);
        if (node->unk_06 + node->unk_08 > end) {
            return 0;
        }
        if (next != 0) {
            end = next->unk_06;
        }
        end -= node->unk_06;
        if (node->unk_08 <= (s16)end) {
            RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
            func_08000BF4(node->unk_0C, gUnk_030074C8 + 0x1800, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}
#else
INCLUDE_ASM("engine/LoadObjTiles.s");
#endif
INCLUDE_ASM("engine/func_0800284C.s");
INCLUDE_ASM("engine/func_08002880.s");
INCLUDE_ASM("engine/func_080028A0.s");
void ReleaseObjTiles(void* a) {
    u8* p = a;
    u8* q;

    if (p == 0) {
        return;
    }
    q = *(u8**)(p + 0x2C);
    if (q != p) {
        return;
    }
    switch (*(u32*)(q + 0x28)) {
    case 0:
        func_0800284C(q);
        break;
    case 1:
        func_08002880(q);
        break;
    case 2:
        func_080028A0(q);
        break;
    }
}
#ifdef NON_MATCHING
ObjTiles* AllocObjTiles(u16 size, void* owner) {
    ObjTiles* node;
    ObjTiles* cur;
    ObjTiles* next;
    u16 end;

    if (size == 0) {
        return 0;
    }
    node = func_08000D0C(gUnk_030074C8 + 0x1800);
    if (node == 0) {
        return 0;
    }
    node->unk_28 = 1;
    node->unk_08 = size / 32;
    node->unk_00 = owner;
    node->unk_04 = 0;
    node->unk_20 = 0;
    node->unk_24 = 1;
    node->unk_2C = node;
    cur = func_08000C8C(gUnk_030074C8 + 0x1800);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gUnk_030074C8 + 0x1810);
        func_08000BC8(node->unk_0C, gUnk_030074C8 + 0x1800);
        return node;
    }
    node->unk_06 = *(u16*)(gUnk_030074C8 + 0x1810);
    if (node->unk_08 <= (s16)(cur->unk_06 - *(u16*)(gUnk_030074C8 + 0x1810))) {
        func_08000C24(node->unk_0C, gUnk_030074C8 + 0x1800, cur->unk_0C);
        return node;
    }
    while (cur != 0) {
        next = func_08000CD4(cur->unk_0C);
        node->unk_06 = cur->unk_08 + cur->unk_06;
        end = *(u16*)(gUnk_030074C8 + 0x1812);
        if (node->unk_06 + node->unk_08 > end) {
            return 0;
        }
        if (next != 0) {
            end = next->unk_06;
        }
        end -= node->unk_06;
        if (node->unk_08 <= (s16)end) {
            func_08000BF4(node->unk_0C, gUnk_030074C8 + 0x1800, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}
#else
INCLUDE_ASM("engine/AllocObjTiles.s");
#endif
void func_08002A10(void* a, void* b) {
    *(void**)a = b;
}
INCLUDE_ASM("engine/LoadObjPalette.s");
INCLUDE_ASM("engine/LoadObjPaletteBank.s");
INCLUDE_ASM("engine/func_08002BCC.s");

void ReleaseObjPalette(u8* p) {
    if (p != 0 && *(u8**)(p + 36) == p) {
        func_08002BCC(p);
    }
}

INCLUDE_ASM("engine/func_08002C28.s");
INCLUDE_ASM("engine/AllocObjAffine.s");
INCLUDE_ASM("engine/func_08002F50.s");
INCLUDE_ASM("engine/func_080034D8.s");
INCLUDE_ASM("engine/func_080034EC.s");
INCLUDE_ASM("engine/func_08003524.s");
INCLUDE_ASM("engine/func_08003598.s");
INCLUDE_ASM("engine/func_080035CC.s");
INCLUDE_ASM("engine/func_0800380C.s");
INCLUDE_ASM("engine/func_0800388C.s");
INCLUDE_ASM("engine/func_080038C8.s");
INCLUDE_ASM("engine/func_080038E4.s");
INCLUDE_ASM("engine/func_08003970.s");
INCLUDE_ASM("engine/func_08003A70.s");
INCLUDE_ASM("engine/func_08003A98.s");
INCLUDE_ASM("engine/func_08003B24.s");
INCLUDE_ASM("engine/func_08003C9C.s");
INCLUDE_ASM("engine/func_08003CD4.s");
INCLUDE_ASM("engine/func_08003E2C.s");
INCLUDE_ASM("engine/func_08004034.s");
INCLUDE_ASM("engine/func_0800415C.s");
INCLUDE_ASM("engine/func_08004314.s");
INCLUDE_ASM("engine/func_08004364.s");
#ifdef NON_MATCHING
u8 RequestDma3Copy(void* src, void* dst, u16 size) {
    Dma3Request* q;
    vu16* count;
    vu32* dma;

    if (size == 0) {
        return 0;
    }
    q = gDma3Requests;
    count = (vu16*)((u8*)q + 0x10A0);
    if (*count > 255) {
        return 0;
    }
    if ((gUnk_0300786C & 8) == 0) {
        q[*count].src = src;
        q[*count].dst = dst;
        q[*count].size = size;
        *count = *count + 1;
    } else {
        dma = (vu32*)0x040000D4;
        dma[0] = (u32)src;
        dma[1] = (u32)dst;
        dma[2] = 0x80000000 | (size / 2);
        dma[2];
    }
    return 1;
}
#else
INCLUDE_ASM("engine/RequestDma3Copy.s");
#endif
INCLUDE_ASM("engine/func_0800443C.s");
INCLUDE_ASM("engine/func_0800448C.s");
INCLUDE_ASM("engine/func_080045AC.s");
INCLUDE_ASM("engine/func_080046C8.s");
INCLUDE_ASM("engine/func_08004938.s");
INCLUDE_ASM("engine/func_08004B8C.s");
INCLUDE_ASM("engine/func_08004BD8.s");
INCLUDE_ASM("engine/func_08004C20.s");
INCLUDE_ASM("engine/func_08004D74.s");
INCLUDE_ASM("engine/func_08004DB0.s");
INCLUDE_ASM("engine/func_08004E64.s");
INCLUDE_ASM("engine/func_08004F08.s");
INCLUDE_ASM("engine/func_08004FC8.s");
void func_0800501C(s32 bg) {
    switch ((u32)bg) {
    case 0:
        gUnk_03007500 &= 0xFEFF;
        break;
    case 1:
        gUnk_03007500 &= 0xFDFF;
        break;
    case 2:
        gUnk_03007500 &= 0xFBFF;
        break;
    case 3:
        gUnk_03007500 &= 0xF7FF;
        break;
    }
}
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette) {
    vu16* p = gBgControl[bg];

    *p = (*p & 0xFFF3) | (charBase << 2);
    *p = (*p & 0xE0FF) | (screenBase << 8);
    gBgPaletteBank[bg] = palette;
}
void LoadBgTiles(s32 bg, void* src, u16 size) {
    func_08004FC8(bg);
    RequestDma3Copy(src, GetBgCharBase(bg), size);
}
void LoadBgPalette(s32 bg, void* src, u16 size) {
    func_08004FC8(bg);
    LoadPalette(src, (void*)((gBgPaletteBank[bg] << 5) + 0x05000000), size);
}

void LoadBgMap(s32 bg, void* src, u16 size) {
    func_08004FC8(bg);
    RequestDma3Copy(src, GetBgScreenBase(bg), size);
}

void* GetBgCharBase(s32 bg) {
    return (void*)(((*gBgControl[bg] & 0x0C) << 12) + 0x06000000);
}
INCLUDE_ASM("engine/GetBgScreenBase.s");
INCLUDE_ASM("engine/func_0800516C.s");
INCLUDE_ASM("engine/func_080051C4.s");
INCLUDE_ASM("engine/func_08005244.s");
INCLUDE_ASM("engine/func_08005490.s");
INCLUDE_ASM("engine/func_080054C8.s");
void SetBgScroll(s32 bg, s32 x, s32 y) {
    x &= 0x1FF;
    y &= 0x1FF;
    switch ((u32)bg) {
    case 0:
        gUnk_03007544 = x;
        gUnk_030074FC = y;
        break;
    case 1:
        gUnk_03007538 = x;
        gUnk_03007558 = y;
        break;
    case 2:
        gUnk_03007520 = x;
        gUnk_03007534 = y;
        break;
    case 3:
        gUnk_0300755C = x;
        gUnk_030074E4 = y;
        break;
    }
}
INCLUDE_ASM("engine/func_08005550.s");
INCLUDE_ASM("engine/func_0800558C.s");
void SetBgPriority(s32 bg, u16 priority) {
    vu16* p = gBgControl[bg];

    *p &= 0xFFFC;
    *p |= priority;
}
INCLUDE_ASM("engine/func_080055EC.s");
INCLUDE_ASM("engine/func_08005610.s");
INCLUDE_ASM("engine/func_08005654.s");
INCLUDE_ASM("engine/func_08005690.s");
INCLUDE_ASM("engine/func_08005778.s");
INCLUDE_ASM("engine/func_080057A0.s");
INCLUDE_ASM("engine/func_08005810.s");
INCLUDE_ASM("engine/func_08005824.s");
INCLUDE_ASM("engine/func_0800589C.s");

void func_080058FC(s32* value, s32 target, u16 steps) {
    s32 cur;
    s32 delta;

    cur = *value;
    delta = target - cur;

    if (steps == 0) {
        steps = 1;
    }

    *value = cur + delta / steps;
}

INCLUDE_ASM("engine/func_08005920.s");
INCLUDE_ASM("engine/func_0800592C.s");

void AnimInit(AnimState* a, s32 b, s32 c) {
    a->unk_04 = (u32*)c;
    a->unk_00 = b;
    a->unk_14 = 0;
}

INCLUDE_ASM("engine/func_08005974.s");
void AnimStart(AnimState* a, u16 animId, u16 flags) {
    AnimHeader* h = a->unk_00[animId];

    a->unk_0C = h->unk_04;
    if (a->unk_0C == 0) {
        a->unk_14 = 0;
        return;
    }
    a->unk_14 = (AnimFrame*)&h->unk_06;
    if ((flags & 4) == 0) {
        a->unk_0A = 0;
        if (flags & 2) {
            a->unk_0E = GetRandom() % a->unk_0C;
        } else {
            a->unk_0E = 0;
        }
    }
    a->unk_08 = flags;
    a->unk_10 = animId;
}
INCLUDE_ASM("engine/AnimChange.s");
#ifdef NON_MATCHING
void* AnimUpdate(AnimState* a) {
    void* gfx = AnimGetGfx(a);
    AnimFrame* frames = a->unk_14;
    u16 index;

    if (frames == 0) {
        return 0;
    }
    a->unk_0A++;
    index = a->unk_0E;
    if (a->unk_0A < frames[index].unk_02) {
        return gfx;
    }
    a->unk_0E = index + 1;
    a->unk_0A = 0;
    if (a->unk_0E < a->unk_0C) {
        return gfx;
    }
    if (a->unk_08 & 1) {
        a->unk_0E = 0;
    } else {
        a->unk_0E = index;
    }
    a->unk_08 |= 0x1000;
    return gfx;
}
#else
INCLUDE_ASM("engine/AnimUpdate.s");
#endif
INCLUDE_ASM("engine/func_08005AC4.s");

void* AnimGetGfx(AnimState* a) {
    void* result;

    if (a->unk_14 != 0) {
        result = (void*)a->unk_04[a->unk_14[a->unk_0E].unk_00];
    } else {
        result = 0;
    }

    return result;
}

u8 AnimIsFinished(AnimState* a) {
    if (a->unk_08 & 0x1000) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("engine/func_08005B30.s");
u16 func_08005B34(AnimState* a) {
    return a->unk_0E;
}
INCLUDE_ASM("engine/func_08005B38.s");
INCLUDE_ASM("engine/func_08005B44.s");
INCLUDE_ASM("engine/func_08005B64.s");
INCLUDE_ASM("engine/func_08005B78.s");
INCLUDE_ASM("engine/func_08005BC4.s");
#ifdef NON_MATCHING
void LoadPalette(void* src, void* dst, s32 size) {
    u8* base;
    u8* flag;
    PaletteSlot* e;
    s32 idx;
    s32 count;
    void* p;

    base = gUnk_03007568;
    count = (u16)size / 32;
    idx = ((s32)dst - 0x05000000) / 32;
    p = func_08007E00(src, dst, size);
    if (count != 0) {
        e = (PaletteSlot*)(base + idx * 44);
        flag = base + idx * 44 + 0x29;
        do {
            e->unk_00 = p;
            e->unk_04 = dst;
            *flag = 1;
            flag += 44;
            dst = (u8*)dst + 32;
            e++;
            p = (u8*)p + 32;
            count--;
        } while (count != 0);
    }
}
#else
INCLUDE_ASM("engine/LoadPalette.s");
#endif
INCLUDE_ASM("engine/func_08005C60.s");
INCLUDE_ASM("engine/func_08006120.s");
INCLUDE_ASM("engine/func_08006184.s");
INCLUDE_ASM("engine/func_080061E8.s");
INCLUDE_ASM("engine/func_08006238.s");
INCLUDE_ASM("engine/func_08006290.s");
#ifdef NON_MATCHING
void func_080062F4(u16 index, u8 value) {
    if (index < 32) {
        *(gUnk_03007568 + index * 44 + 0x28) = value;
    }
}
#else
INCLUDE_ASM("engine/func_080062F4.s");
#endif
u8 func_08006314(void) {
    if (*(u16*)(gUnk_03007568 + 0x594) & 1) {
        return 1;
    }
    return 0;
}
INCLUDE_ASM("engine/_08006338.s");
INCLUDE_ASM("engine/func_08006390.s");
INCLUDE_ASM("engine/func_080063A8.s");
INCLUDE_ASM("engine/func_080063C4.s");
INCLUDE_ASM("engine/func_08006404.s");
INCLUDE_ASM("engine/func_08006494.s");
INCLUDE_ASM("engine/SeedRand.s");
INCLUDE_ASM("engine/Rand.s");
INCLUDE_ASM("engine/SeedRandom.s");
#ifdef NON_MATCHING
u16 GetRandom(void) {
    s32 a = gRandomState[1] * 2;
    u32 m = 0x80000000;

    if ((s32)gRandomState[0] < 0) {
        a++;
    }
    a *= 2;
    if (gRandomState[0] & 0x40000000) {
        a++;
    }
    gRandomState[3] *= 2;
    if (gRandomState[2] & m) {
        gRandomState[3]++;
    }
    a ^= gRandomState[3];
    gRandomState[3] = gRandomState[2];
    gRandomState[2] = gRandomState[1];
    gRandomState[1] = gRandomState[0];
    gRandomState[0] = a;
    return a & 0x7FFF;
}
#else
INCLUDE_ASM("engine/GetRandom.s");
#endif
INCLUDE_ASM("engine/func_080065FC.s");
INCLUDE_ASM("engine/func_080066F4.s");
INCLUDE_ASM("engine/func_0800675C.s");
INCLUDE_ASM("engine/func_08006778.s");
INCLUDE_ASM("engine/func_0800685C.s");
INCLUDE_ASM("engine/func_08006954.s");
INCLUDE_ASM("engine/func_08006B34.s");
INCLUDE_ASM("engine/func_08006B4C.s");
