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
void func_08000C54(void* node, void* pool);
void CpuSet(void* src, void* dst, u32 ctrl);
ObjTiles* AllocObjTiles(u16 size, void* owner);
u16 func_08001DB0(u16 a, u16 b);
s32 func_08005824(s32 a, s32 b);
s32 func_0800585C(s32 a, s32 b);
void func_08005C60(u16 a);
void func_08000AE4(void* name);
void* IwramAlloc(u32 size);
void IwramFree(void* p);

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

void func_0800284C(u8* p) {
    if ((s16)*(u16*)(p + 4) > 0) {
        *(u16*)(p + 4) -= 1;
    } else {
        *(void**)(p + 0x2C) = 0;
        func_08000C54(p + 0x0C, gUnk_030074C8 + 0x1800);
    }
}

void func_08002880(u8* p) {
    *(void**)(p + 0x2C) = 0;
    func_08000C54(p + 0x0C, gUnk_030074C8 + 0x1800);
}

void func_080028A0(u8* p) {
    *(void**)(p + 0x2C) = 0;
    func_08000C54(p + 0x0C, gUnk_030074C8 + 0x1800);
}

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

void LoadObjPaletteBank(u16 bank, void* src) {
    LoadPalette(src, (void*)((bank << 5) + 0x05000200), 32);
}

void func_08002BCC(void* a) {
    u8* p = a;

    if ((s16)*(u16*)(p + 4) > 0) {
        *(u16*)(p + 4) -= 1;
    } else {
        *(u32*)(p + 0x24) = 0;
        func_08005C60(*(u16*)(p + 6) + 0x10);
        func_08000C54(p + 0x0C, gUnk_030074C8 + 0x1A94);
    }
}

void ReleaseObjPalette(u8* p) {
    if (p != 0 && *(u8**)(p + 36) == p) {
        func_08002BCC(p);
    }
}

INCLUDE_ASM("engine/func_08002C28.s");
INCLUDE_ASM("engine/AllocObjAffine.s");
INCLUDE_ASM("engine/func_08002F50.s");

void func_080034D8(u8 a) {
    gUnk_030074C8[0x2BAF] = a;
}

void func_080034EC(u8 a, u8 b) {
    a &= 0xF;
    b &= 0xF;
    gUnk_03007528 = (gUnk_03007528 & 0xFF) | (a << 8) | (b << 12);
}

void func_08003510(u8 a) {
    gUnk_030074C8[0x2BAE] = a;
}

INCLUDE_ASM("engine/func_08003524.s");

u16 func_08003598(u16* p) {
    u16 count = *p++;
    u16 total = 0;
    u16 i;

    for (i = 0; i < count; i++) {
        total += func_08001DB0(p[0], p[1]);
        p += 3;
    }
    return (u16)(total << 5);
}

INCLUDE_ASM("engine/func_080035CC.s");

void func_0800380C(ObjTiles* t, u16 slot, void* src, u16 size) {
    if (slot + (size >> 5) <= 0x400) {
        t->unk_28 = 0;
        t->unk_08 = size >> 5;
        t->unk_00 = src;
        t->unk_04 = 0;
        t->unk_20 = 0;
        t->unk_24 = 0;
        t->unk_06 = slot;
        RequestDma3Copy(src, (void*)((t->unk_06 << 5) + 0x06010000), size);
    }
}

void func_08003858(ObjTiles* t, u16 slot, u16 size, void* src) {
    if (slot + (size >> 5) <= 0x400) {
        t->unk_28 = 1;
        t->unk_08 = size >> 5;
        t->unk_00 = src;
        t->unk_04 = 0;
        t->unk_20 = 0;
        t->unk_24 = 1;
        t->unk_06 = slot;
    }
}

void func_0800388C(ObjTiles* t, u16 slot, void* src, u16 size) {
    if (slot + (size >> 5) <= 0x10) {
        t->unk_20 = 0;
        t->unk_08 = size >> 5;
        t->unk_00 = src;
        t->unk_04 = 0;
        t->unk_06 = slot;
        RequestDma3Copy(src, (void*)((t->unk_06 << 5) + 0x05000200), size);
    }
}

ObjTiles* func_080038C8(u16 a) {
    ObjTiles* t = AllocObjTiles(a, 0);

    if (t != 0) {
        t->unk_28 = 2;
    }
    return t;
}

INCLUDE_ASM("engine/func_080038E4.s");
INCLUDE_ASM("engine/func_08003970.s");

void func_08003A70(ObjTiles* t, void* src) {
    if (t->unk_20 == 2) {
        LoadPalette(src, (void*)((t->unk_06 << 5) + 0x05000200), (u16)(t->unk_08 << 5));
    }
}

INCLUDE_ASM("engine/func_08003A98.s");
INCLUDE_ASM("engine/func_08003B24.s");

s32 func_08003C9C(s32 a) {
    s32 x;
    s32 prev;

    if (a > 0) {
        x = 0x100;
        if (a > 0x100) {
            x = a;
        }
        do {
            prev = x;
            x = ((a << 8) / prev + prev) / 2;
        } while (x < prev);
        return prev;
    }
    return 0;
}

INCLUDE_ASM("engine/func_08003CD4.s");
INCLUDE_ASM("engine/func_08003E2C.s");
INCLUDE_ASM("engine/func_08004034.s");
INCLUDE_ASM("engine/func_0800415C.s");

void func_08004314(void) {
    u32 zero;

    func_08000AE4(gUnk_08121680);
    gDma3Requests = IwramAlloc(0x10B0);
    zero = 0;
    CpuSet(&zero, gDma3Requests, 0x0500042C);
}

void func_08004350(void) {
    IwramFree(gDma3Requests);
}

void func_08004364(void) {
    Dma3Queue* q = (Dma3Queue*)gDma3Requests;

    q->unk_10A0 = 0;
    q->unk_10A2 = 0;
    q->unk_10A4 = 0;
    q->unk_10A6 = 0;
    q->count = 0;
    q->unk_10AC = 0;
}

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

u8 func_0800443C(void* a, u16 b) {
    Dma3Queue* q = (Dma3Queue*)gDma3Requests;

    if (q->count > 3) {
        return 0;
    }
    q->pending[q->count].unk_00 = a;
    q->pending[q->count].unk_04 = b;
    q->count = q->count + 1;

    return 1;
}
INCLUDE_ASM("engine/func_0800448C.s");
INCLUDE_ASM("engine/func_080045AC.s");
INCLUDE_ASM("engine/func_080046C8.s");
INCLUDE_ASM("engine/func_08004938.s");

void func_08004B8C(void) {
    BgEntry** p;
    u32 zero;

    func_08000AE4(gUnk_08121688);
    p = &gUnk_030074D4;
    *p = IwramAlloc(0x40);
    zero = 0;
    CpuSet(&zero, *p, 0x05000010);
}

void func_08004BC4(void) {
    IwramFree(gUnk_030074D4);
}

void* func_08004BD8(BgEntry* e, u16 x, u16 y) {
    u8 col = (x >> 8) % e->unk_08;
    u8 row = (y >> 8) % e->unk_09;

    return ((void**)e->unk_04)[e->unk_08 * row + col];
}

INCLUDE_ASM("engine/func_08004C20.s");

void func_08004D74(void) {
    gUnk_030074D8 = 0;
    func_0800501C(0);
    func_0800501C(1);
    func_0800501C(2);
    func_0800501C(3);
    func_080054C8(0, 0);
    gUnk_03007554 = 0;
}

INCLUDE_ASM("engine/func_08004DB0.s");
INCLUDE_ASM("engine/func_08004E64.s");
INCLUDE_ASM("engine/func_08004F08.s");

void func_08004FC8(s32 bg) {
    switch ((u32)bg) {
    case 0:
        gUnk_03007500 |= 0x100;
        break;
    case 1:
        gUnk_03007500 |= 0x200;
        break;
    case 2:
        gUnk_03007500 |= 0x400;
        break;
    case 3:
        gUnk_03007500 |= 0x800;
        break;
    }
}

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

void* GetBgScreenBase(s32 bg) {
    return (void*)(((*gBgControl[bg] & 0x1F00) << 3) + 0x06000000);
}

#ifdef NON_MATCHING
void func_0800516C(s32 bg, void* src, u8 w, u8 h) {
    if (gUnk_03007500 & 7) {
        if (bg == 2 || bg == 3) {
            return;
        }
    }
    func_08004FC8(bg);
    gUnk_030074D4[bg].unk_04 = src;
    gUnk_030074D4[bg].unk_08 = w;
    gUnk_030074D4[bg].unk_09 = h;
    gUnk_030074D4[bg].unk_0A = 0;
    gUnk_030074D4[bg].unk_0C = 0;
    gUnk_030074D4[bg].unk_00 = 1;
}
#else
INCLUDE_ASM("engine/func_0800516C.s");
#endif
INCLUDE_ASM("engine/func_080051C4.s");
INCLUDE_ASM("engine/func_08005244.s");

void func_08005490(s32 bg, u8 on) {
    if (on) {
        *gBgControl[bg] |= 0x40;
    } else {
        *gBgControl[bg] &= 0xFFBF;
    }
}

void func_080054C8(u8 a, u8 b) {
    a &= 0xF;
    b &= 0xF;
    gUnk_03007528 = (gUnk_03007528 & 0xFF00) | a | (b << 4);
}

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

u8 func_08005550(u32 a) {
    u16 v;

    switch (a) {
    case 0:
        v = gUnk_03007544;
        break;
    case 1:
        v = gUnk_03007538;
        break;
    case 2:
        v = gUnk_03007520;
        break;
    case 3:
        v = gUnk_0300755C;
        break;
    default:
        return 0;
    }
    return v;
}

u8 func_0800558C(u32 a) {
    u16 v;

    switch (a) {
    case 0:
        v = gUnk_030074FC;
        break;
    case 1:
        v = gUnk_03007558;
        break;
    case 2:
        v = gUnk_03007534;
        break;
    case 3:
        v = gUnk_030074E4;
        break;
    default:
        return 0;
    }
    return v;
}

void SetBgPriority(s32 bg, u16 priority) {
    vu16* p = gBgControl[bg];

    *p &= 0xFFFC;
    *p |= priority;
}

void func_080055EC(s32 bg, u16 v) {
    vu16* p = gBgControl[bg];

    *p &= 0x3FFF;
    *p |= v;
}

void func_08005610(s32 bg, u16 v) {
    if (v == 0x80) {
        vu16* p = gBgControl[bg];

        *p &= 0xFFFF;
        *p |= 0x80;
    } else {
        vu16* p = gBgControl[bg];

        *p &= 0xFF7F;
        *p |= 0;
    }
}

void func_08005654(s32 bg, u8 on) {
    if (on) {
        *gBgControl[bg] |= 0x2000;
    } else {
        *gBgControl[bg] &= 0xDFFF;
    }
}

INCLUDE_ASM("engine/func_08005690.s");

void func_08005778(u8 r, u8 g, u8 b) {
    g &= 0x1F;
    b &= 0x1F;
    gUnk_030074CC = (b << 10) | (g << 5) | (r & 0x1F);
    gUnk_030074D8 = gUnk_030074CC;
}

void func_080057A0(s32 a, u16 b, u16 c) {
    switch ((u32)a) {
    case 0:
        gUnk_03007554 = 0x1E01;
        break;
    case 1:
        gUnk_03007554 = 0x1D02;
        break;
    case 2:
        gUnk_03007554 = 0x1B04;
        break;
    default:
        gUnk_03007554 = 0x1708;
        break;
    }
    gUnk_03007554 |= 0x40;
    gUnk_03007564 = (b << 8) | c;
}

void func_08005810(u16 a, u16 b) {
    gUnk_03007564 = (a << 8) | b;
}

#ifdef NON_MATCHING
s32 func_08005824(s32 a, s32 b) {
    s32 x = a & 0xFF;
    s32 y = b & 0xFF;
    s32 d = x - y;

    if (d <= -0x80) {
        return d + 0x100;
    }
    if (d > 0x7F) {
        return (x - 0x100) - y;
    }
    return d;
}
#else
INCLUDE_ASM("engine/func_08005824.s");
#endif
INCLUDE_ASM("engine/func_0800585C.s");

void func_0800589C(u16* p, u16 target, u16 shift) {
    s16 d;
    u16 v;

    if (*p == target) {
        return;
    }
    d = func_08005824((s16)target, (s16)*p);
    if (d == 0) {
        return;
    }
    v = d >> shift;
    *p = v + *p;
}

void func_080058D4(u16* p, u16 target, u16 shift) {
    s32 d = func_0800585C(target, *p);

    if (d != 0) {
        *p = (d >> shift) + *p;
    }
}

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

s32 func_08005920(u16 a) {
    a >>= 1;
    if (a == 0) {
        a = 1;
    }
    return a;
}

void func_0800592C(s32* p, s32 target, u16 steps) {
    s32 d = target - *p;

    *p += d / func_08005920(steps);
}

s32 func_08005954(s32 a, s32 b, s32 t) {
    return (a * (0x100 - t) >> 8) + (b * t >> 8);
}

void AnimInit(AnimState* a, s32 b, s32 c) {
    a->unk_04 = (u32*)c;
    a->unk_00 = (AnimHeader**)b;
    a->unk_14 = 0;
}

void func_08005974(AnimState* a, u16 animId, u16 flags, s32 b, s32 c) {
    if (a->unk_04 != (u32*)c || a->unk_00 != (AnimHeader**)b || a->unk_10 != animId) {
        a->unk_04 = (u32*)c;
        a->unk_00 = (AnimHeader**)b;
        AnimStart(a, animId, flags);
    }
}

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

u8 func_08005AC4(AnimState* a) {
    if (a->unk_14 == 0) {
        return 0;
    }
    if (!(a->unk_08 & 1)) {
        if (a->unk_08 & 0x1000) {
            return 0;
        }
    }
    if (a->unk_0A + 1 >= a->unk_14[a->unk_0E].unk_02) {
        return 1;
    }

    return 0;
}

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

u16 func_08005B30(AnimState* a) {
    return a->unk_10;
}

u16 func_08005B34(AnimState* a) {
    return a->unk_0E;
}

u16 func_08005B38(AnimState* a) {
    return a->unk_14[a->unk_0E].unk_00;
}

void func_08005B44(AnimState* a, u16 frame) {
    if (frame < a->unk_0C) {
        a->unk_0E = frame;
        a->unk_0A = 0;
        a->unk_08 &= 0xEFFF;
    }
}

void func_08005B64(AnimState* a) {
    a->unk_0E = 0;
    a->unk_0A = 0;
    a->unk_08 &= 0xEFFF;
}

void func_08005B78(void) {
    u32 zero;

    func_08000AE4(gUnk_0812168C);
    gUnk_03007568 = IwramAlloc(0x598);
    zero = 0;
    CpuSet(&zero, gUnk_03007568, 0x05000166);
}

void func_08005BB0(void) {
    IwramFree(gUnk_03007568);
}

void func_08005BC4(void) {
    u32 zero = 0;

    CpuSet(&zero, gUnk_03007568, 0x05000166);
}

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

void func_08005C60(u16 a) {
    PaletteSlot* p = (PaletteSlot*)gUnk_03007568;

    p += a;
    p->unk_00 = 0;
}

INCLUDE_ASM("engine/func_08005C78.s");
#ifdef NON_MATCHING
void func_08006120(s32 a, u16 b) {
    u8* base = gUnk_03007568;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = b;
    *(u32*)(base + 0x580) = 0x1F00;
    *(u32*)(base + 0x584) = 0;
    *(u32*)(base + 0x588) = 0;
    *(u32*)(base + 0x590) = a;
}
#else
INCLUDE_ASM("engine/func_08006120.s");
#endif
INCLUDE_ASM("engine/func_08006184.s");
#ifdef NON_MATCHING
void func_080061E8(s32 a, u16 b) {
    u8* base = gUnk_03007568;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = b;
    *(u32*)(base + 0x584) = 0;
    *(u32*)(base + 0x590) = a;
}
#else
INCLUDE_ASM("engine/func_080061E8.s");
#endif

void func_08006238(s32 a, u16 b, u16 c) {
    u8* base = gUnk_03007568;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = c;
    *(u32*)(base + 0x584) = b << 8;
    *(u32*)(base + 0x590) = a;
}

INCLUDE_ASM("engine/func_08006290.s");

void func_080062F4(u16 slot, u8 value) {
    PaletteSlot* p;

    if (slot > 0x1F) {
        return;
    }
    p = (PaletteSlot*)gUnk_03007568;
    p += slot;
    p->unk_28 = value;
}

u8 func_08006314(void) {
    if (*(u16*)(gUnk_03007568 + 0x594) & 1) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("engine/_08006338.s");

u16 func_08006390(void) {
    return *(u32*)(gUnk_03007568 + 0x580) >> 8;
}

void func_080063A8(void) {
    u16 v = *(u16*)(gUnk_03007568 + 0x594) | 2;

    *(u16*)(gUnk_03007568 + 0x594) = v;
}

void func_080063C4(u8 on) {
    if (on) {
        u16 v = *(u16*)(gUnk_03007568 + 0x594) | 4;

        *(u16*)(gUnk_03007568 + 0x594) = v;
    } else {
        *(u16*)(gUnk_03007568 + 0x594) &= 0xFFFB;
    }
}

void func_08006404(void) {
    gUnk_0203401C = 0;
    gUnk_02034020 = 0;
    gUnk_02034024 = 0;
    gUnk_02034026 = 0;
}

INCLUDE_ASM("engine/func_0800642C.s");

void func_08006494(u16 a, u16 b) {
    gUnk_02034024 = a;
    gUnk_0203401C = b << 8;
    gUnk_02034020 = 0;
    gUnk_02034026 = 1;
    func_08005490(0, 1);
    func_08005490(1, 1);
    func_08005490(2, 1);
    func_08005490(3, 1);
    func_080034D8(1);
}

void func_080064E8(u16 a, u16 b) {
    gUnk_02034024 = a;
    gUnk_0203401C = 0;
    gUnk_02034020 = b << 8;
    gUnk_02034026 = 1;
    func_08005490(0, 1);
    func_08005490(1, 1);
    func_08005490(2, 1);
    func_08005490(3, 1);
    func_080034D8(1);
}

u8 func_0800653C(void) {
    return gUnk_02034026;
}

void SeedRand(u32 seed) {
    gRandSeed = seed;
}

u32 Rand(void) {
    gRandSeed = (gRandSeed * 0x41C64E6D + 12345) & 0x7FFF;
    return gRandSeed;
}

void SeedRandom(u32 seed) {
    SeedRand(seed);
    gRandomState[0] = Rand();
    gRandomState[1] = Rand();
    gRandomState[2] = Rand();
    gRandomState[3] = Rand();
}

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
void func_080066F4(s16 x, s16 y) {
    if (gUnk_02034058 != 0) {
        gUnk_02034050 = -x;
        gUnk_02034052 = -y;
    } else {
        gUnk_02034050 = (*(u16*)(gUnk_02034040 + 0x10) << 2) - x;
        gUnk_02034052 = (*(u16*)(gUnk_02034040 + 0x12) << 2) - y;
    }
}

void func_0800675C(u8 a, s32 b, s32 c) {
    gUnk_02034064 = a;
    gUnk_0203405C = b;
    gUnk_02034060 = c;
}

INCLUDE_ASM("engine/func_08006778.s");
INCLUDE_ASM("engine/func_0800685C.s");
INCLUDE_ASM("engine/func_08006954.s");

void func_08006B34(u16 a) {
    gUnk_02034066 = a;
}

void func_08006B40(u16 a) {
    gUnk_02034068 = a;
}

void func_08006B4C(void) {
    gUnk_02034040 = 0;
    gUnk_02034054 = 1;
    func_0800501C(gUnk_02034048);
}
