#include "macros.h"
#include "listpool.h"
#include "battle.h"


ListNode gUnk_020348E8;
ListNode gUnk_020348F8;
ListNode gUnk_02034908;
ListNode gUnk_02034918;

u8 func_08011270(BtlObj* p, s32 x, s32 y, s32 z, s16 a, s16 b, s16 c) {
    BtlObj* q = p->unk_0D8;
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

void func_08011364(BtlObj* a, BtlObj* b, const UnkStruct_0813400C* c) {
    gBtlWork->unk_076 = 8;
    a->unk_020 = -((b->unk_030 * c->unk_00) >> 8);
    a->unk_034 |= 0x20;
}

s32 func_08011398(BtlObj* hit, s32 index) {
    const UnkStruct_0813400C* attack = &gUnk_0813400C[index];
    s32 scale = gBtlWork->unk_124;
    BtlObj* target;
    BtlObj* source;
    if (hit->unk_0D8 != 0) {
        target = hit->unk_0D8;
    } else {
        target = hit;
    }
    target->unk_024 = attack->unk_14;
    target->unk_028 = index;
    if (attack->unk_14 & 0x40000) {
        if (hit->unk_034 & 0x8000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        if (attack->unk_14 & 0x80000) target->unk_0B4 = 0;
        target->unk_034 |= 0x40;
        return 0;
    }
    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) source = gBtlWork->unk_07C;
        else source = gUnk_02039B9C->unk_07C;
    } else if (gBtlWork->unk_068 & 0x800) {
        if (gBtlWork->unk_068 & 0x20000000) source = gBtlWork->unk_07C;
        else source = gBtlWork->unk_0A8;
    } else {
        if (gBtlWork->unk_068 & 0x20000000) source = gBtlWork->unk_07C;
        else source = gBtlWork->unk_0A8;
    }
    if (source->unk_0E4 != 0) {
        switch (source->unk_0E4->unk_0F4) {
        case 35:
            if ((attack->unk_14 & 0x01002000) != 0x2000) break;
            if (hit->unk_034 & 0x100000000ULL) break;
            if ((attack->unk_14 & 0x80000000) && (hit->unk_034 & 0x8000)) break;
            if ((attack->unk_14 & 0x08000000) && (hit->unk_034 & 0x0200000000000000ULL)) break;
            if ((attack->unk_14 & 0x10000000) && (hit->unk_034 & 0x4000000)) break;
            if ((attack->unk_14 & 0x20000000) && (hit->unk_034 & 0x8000000)) break;
            if ((attack->unk_14 & 0x40000000) && (hit->unk_034 & 0x10000000)) break;
            if (hit->unk_0E8 == 2) break;
            {
                s16 drain = target->unk_02C >> 3;
                if (drain <= 0) drain = 1;
                else if (drain > 20) drain = 20;
                source->unk_02C += drain;
                target->unk_02C -= drain;
                if (target->unk_02C <= 0) target->unk_02C = 1;
                if (source->unk_02C > source->unk_02E) source->unk_02C = source->unk_02E;
                func_08019190(source, 10);
                target->unk_0B4 -= target->unk_0B4 >> 2;
            }
            break;
        case 43:
            if ((attack->unk_14 & 0x01002000) == 0x2000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 8:
            if ((attack->unk_14 & 0x01002000) == 0x2000 && source->unk_02C < (source->unk_02E >> 2)) {
                scale = scale != 0 ? (scale * 512) >> 8 : 512;
            }
            break;
        case 4:
            if (attack->unk_14 & 0x10000000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 11:
            if (attack->unk_14 & 0x20000000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 12:
            if (attack->unk_14 & 0x40000000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 38:
            if (attack->unk_14 & 0x4000) {
                scale = scale != 0 ? (scale * 332) >> 8 : 332;
            }
            break;
        case 39:
            if (attack->unk_14 & 0x8000) {
                scale = scale != 0 ? (scale * 332) >> 8 : 332;
            }
            break;
        case 36:
            if ((attack->unk_14 & 0x01002000) == 0x2000) {
                if (source->unk_034 & 4) {
                    if ((hit->unk_034 & 4) && hit->unk_004 < source->unk_004) {
                        scale = scale != 0 ? (scale * 512) >> 8 : 512;
                    }
                } else if (!(hit->unk_034 & 4) && source->unk_004 < hit->unk_004) {
                    scale = scale != 0 ? (scale * 512) >> 8 : 512;
                }
            }
            break;
        }
    }
    if (target->unk_0E4 != 0) {
        switch (target->unk_0E4->unk_0F4) {
        case 14:
            if (attack->unk_14 & 0x80000000) {
                func_08019190(hit, 0);
                scale = scale != 0 ? (scale * 128) >> 8 : 128;
            }
            break;
        case 46:
            target->unk_0E4->unk_0F8--;
#ifdef VERSION_EU
            if (attack->unk_14 & 0x4000)
#endif
            {
                scale = scale != 0 ? (scale * 128) >> 8 : 128;
            }
            break;
        }
    }
    if (attack->unk_14 & 0x80000000) {
        if (hit->unk_034 & 0x8000) {
            switch ((u32)hit->unk_000) {
            case 7:
            case 28:
            case 50:
            case 52:
                m4aSongNumStart(0x213);
                break;
            default:
                m4aSongNumStart(0x220);
                break;
            }
            hit->unk_0E2 = 30;
            func_08019190(hit, 0);
            func_080139FC(gBtlWork->unk_0B8, gBtlWork->unk_0BC, hit->unk_00C - hit->unk_0A2 * 256);
            return 2;
        } else if (hit->unk_034 & 0x0020000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0002000000000000ULL) {
            if (target->unk_034 & 0x0440000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->unk_14 & 0x08000000) {
        if (hit->unk_034 & 0x0200000000000000ULL) {
            switch ((u32)hit->unk_000) {
            case 7:
            case 28:
            case 50:
                m4aSongNumStart(0x213);
                break;
            default:
                m4aSongNumStart(0x220);
                break;
            }
            hit->unk_0E2 = 30;
            func_08019190(hit, 0);
            func_080139FC(gBtlWork->unk_0B8, gBtlWork->unk_0BC, hit->unk_00C - hit->unk_0A2 * 256);
            return 2;
        } else if (hit->unk_034 & 0x0100000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0080000000000000ULL) {
            if (target->unk_034 & 0x0440000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->unk_14 & 0x10000000) {
        if (hit->unk_034 & 0x100000) {
            func_08011364(target, source, attack);
            return 1;
        }
        if (hit->unk_034 & 0x4000000) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        } else if (hit->unk_034 & 0x0004000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0000400000000000ULL) {
            if (target->unk_034 & 0x0040000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->unk_14 & 0x20000000) {
        if (hit->unk_034 & 0x200000) {
            func_08011364(target, source, attack);
            return 1;
        }
        if (hit->unk_034 & 0x8000000) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        } else if (hit->unk_034 & 0x0008000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0000800000000000ULL) {
            if (target->unk_034 & 0x0040000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->unk_14 & 0x40000000) {
        if (hit->unk_034 & 0x400000) {
            func_08011364(target, source, attack);
            return 1;
        }
        if (hit->unk_034 & 0x10000000) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        } else if (hit->unk_034 & 0x0010000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0001000000000000ULL) {
            if (target->unk_034 & 0x0040000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->unk_14 & 0x100) {
        if (hit->unk_034 & 0x80000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        hit->unk_034 |= 0x800;
        if (scale == 0) hit->unk_020 = ((u32)attack->unk_00 * 15) >> 6;
        else hit->unk_020 = (((attack->unk_00 * 60) >> 8) * scale) >> 8;
        gBtlWork->unk_076 = (u8)attack->unk_0C;
        hit->unk_0E2 = 30;
        return 1;
    }
    if (hit->unk_034 & 0x100000000ULL) {
        func_08019190(hit, 0);
        hit->unk_0E2 = 30;
        gBtlWork->unk_072 = (u8)attack->unk_0C;
        return 1;
    }
    if (attack->unk_14 & 0x200) {
        target->unk_034 |= 0x4000;
    } else if (attack->unk_14 & 0x100000) {
        if (hit->unk_034 & 0x4000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x2000000000ULL;
    } else if (attack->unk_14 & 0x200000) {
        if (hit->unk_034 & 0x20000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x10000000000ULL;
    } else if (attack->unk_14 & 0x400000) {
        if (hit->unk_034 & 0x80000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x40000000000ULL;
    }
    if (attack->unk_14 & 0x400) {
        if (hit->unk_034 & 0x200000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x40000;
        if (attack->unk_14 & 0x8000000) {
            if (scale == 0) target->unk_020 = (source->unk_030 * attack->unk_00) >> 8;
            else target->unk_020 = (((source->unk_030 * attack->unk_00) >> 8) * scale) >> 8;
        } else {
            if (scale == 0) target->unk_020 = (target->unk_02C * attack->unk_00) >> 8;
            else target->unk_020 = (((target->unk_02C * attack->unk_00) >> 8) * scale) >> 8;
            if (target->unk_034 & 0x0400000000000000ULL) {
                target->unk_020 = (target->unk_020 * 76) >> 8;
            }
        }
    } else {
        if (scale == 0) target->unk_020 = (source->unk_030 * attack->unk_00) >> 8;
        else target->unk_020 = (((source->unk_030 * attack->unk_00) >> 8) * scale) >> 8;
        if (target->unk_020 == 0 && attack->unk_00 > 0) target->unk_020 = 1;
    }
    if (target->unk_0E4 != 0 && target->unk_0E4->unk_0F4 == 26) {
        if (target->unk_02C > 1 && target->unk_02C - target->unk_020 <= 0) {
            target->unk_020 = target->unk_02C - 1;
            target->unk_0E2 = 60;
            func_08019190(target, 0);
            target->unk_0E4->unk_0F8--;
        }
    }
    target->unk_034 |= 2;
    gBtlWork->unk_076 = (u8)attack->unk_0C;
    target->unk_0A8 = attack->unk_04;
    target->unk_0AC = attack->unk_08;
    if (attack->unk_14 & 0x800000) {
        if (source->unk_034 & 4) target->unk_0B0 = 192;
        else target->unk_0B0 = 64;
    } else if (attack->unk_14 & 0x1000) {
        target->unk_0B0 = GetAngle(gBtlWork->unk_0B8, gBtlWork->unk_0BC, target->unk_004, target->unk_008);
    } else {
        target->unk_0B0 = GetAngle(source->unk_004, source->unk_008, target->unk_004, target->unk_008);
    }
    return 1;
}
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
            o = gUnk_02039B9C->unk_07C;
        } else {
            o = gBtlWork->unk_07C;
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
        o = gBtlWork->unk_07C;
    }

    if (func_08011270(o, x, y, z, a, b, c) == 0) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("btl_collision/func_08011E3C.s");
#endif

s32 func_08011F68(s32 a, s32 b) {
    return func_08011398((BtlObj*)b, a);
}

#ifdef NON_MATCHING
s32 func_08011F78(s32 a, s32 x, s32 y, s32 z, s16 p, s16 q, s16 r) {
    const UnkStruct_0813400C* t;
    BtlWork* w;
    BtlObj* o;
    s32 sx;
    s32 sy;
    s32 sz;
    s16 cnt;
    s32 flag;
    s32 n;
    s32 res;
    u64 f;
    s32 r2;

    t = &gUnk_0813400C[a];
    cnt = 0;
    flag = 0;
    gBtlWork->unk_0B4 = 1;
    w = gBtlWork;
    w->unk_0B8 = x;
    w->unk_0BC = y;
    w->unk_0C0 = z;
    w->unk_0C4 = p;
    w->unk_0C6 = q;
    w->unk_0C8 = r;
    f = w->unk_068;

    if ((f & 0x4000) && (f & 0x20000000)) {
        o = gUnk_02039B9C->unk_07C;
    } else if (f & 0x20000000) {
        o = ListPoolFirst(&w->unk_080);
        sz = 0;
        sy = 0;
        sx = 0;

        while (o != 0) {
            if (func_08011270(o, x, y, z, p, q, r)) {
                r2 = func_08011398(o, a);

                if (r2 == 1) {
                    sx += o->unk_004;
                    sy += o->unk_008;
                    sz += o->unk_00C;
                    cnt++;

                    if (t->unk_14 & 0x800) {
                        break;
                    }
                } else if (r2 == 2) {
                    flag = 1;
                }
            }
            o = ListPoolNext(&o->unk_0B8);
        }

        if (flag != 0) {
            return 2;
        }

        n = cnt;

        if (n > 0) {
            if (t->unk_10 != 0) {
                sx /= n;
                sy /= n;
                sz /= n;
                t->unk_10(sx, sy, sz);
            }
            return 1;
        }
        return 0;
    } else {
        o = w->unk_07C;
    }

    if (func_08011270(o, x, y, z, p, q, r)) {
        res = func_08011398(o, a);

        if (res == 1) {
            if (t->unk_10 != 0) {
                t->unk_10(o->unk_004, o->unk_008, o->unk_00C);
            }
        }
        return res;
    }
    return 0;
}
#else
INCLUDE_ASM("btl_collision/func_08011F78.s");
#endif

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
    ListNodeInit(&p->unk_1C, &gUnk_02039BA0->unk_58, p);
    ListPoolAppend(&p->unk_1C, &gUnk_02039BA0->unk_58);
}

void func_080121FC(FldObj* p) {
    ListPoolRemove(&p->unk_1C, &gUnk_02039BA0->unk_58);
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
    ListNodeInit(&p->unk_18, pool, p);
    ListPoolAppend(&p->unk_18, pool);
}

void func_08012304(Collider* p) {
    Collider* q = p->self;
    if (q == p) {
        ListPoolRemove(&q->unk_18, func_08012218(q->unk_00));
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

void func_0801235C(ListNode* a, ListNode* b) {
    Collider* p;
    Collider* q;
    s32 sum;
    s32 dx;
    s32 dy;
    s32 pen;
    s32 dz;
    s32 t;
    u8 angle;

    p = ListPoolFirst(a);

    while (p != 0) {
        q = ListPoolLast(b);

        while (q != 0 && p != q) {
            sum = p->radius + q->radius;
            dx = p->unk_04 - q->unk_04;

            if (dx < 0) {
                dx = q->unk_04 - p->unk_04;
            }

            dy = p->unk_08 - q->unk_08;

            if (dy < 0) {
                dy = q->unk_08 - p->unk_08;
            }

            if (dx < sum && dy < sum) {
                pen = sum - Sqrt8(((dx * dx) >> 8) + ((dy * dy) >> 8));

                if (pen > 0) {
                    dz = p->unk_0C - q->unk_0C;

                    if (dz < p->height && -dz < q->height) {
                        q->unk_2C = 1;
                        p->unk_2C = 1;
                        p->unk_34 = q->unk_00;
                        q->unk_34 = p->unk_00;
                        p->unk_58 |= 1 << q->unk_00;
                        q->unk_58 |= 1 << p->unk_00;
                        angle = GetAngle(p->unk_04, p->unk_08, q->unk_04, q->unk_08);
                        t = (pen * gSineTable[angle]) >> 8;
                        p->unk_38 = -t;
                        p->unk_3C = -((pen * -gSineTable[angle + 64]) >> 8);
                        p->unk_50 = q;
                        q->unk_38 = t;
                        q->unk_3C = -p->unk_3C;
                        q->unk_50 = p;

                        if (q->unk_30 & 1) {
                            p->unk_40 = q->unk_0C - q->height;
                            p->unk_4C = pen;
                            p->unk_48 = q->unk_08 >> 1;
                            p->unk_44 = q->unk_04;
                        }

                        if (p->unk_30 & 1) {
                            q->unk_40 = p->unk_0C - p->height;
                            q->unk_4C = pen;
                            q->unk_48 = p->unk_08 >> 1;
                            q->unk_44 = p->unk_04;
                        }
                    } else {
                        if (q->unk_30 & 1) {
                            if (q->unk_0C - q->height >= p->unk_0C) {
                                p->unk_2E |= 1;

                                if (q->unk_0C - q->height == p->unk_0C) {
                                    q->unk_2E |= 2;
                                    p->unk_58 |= 1 << q->unk_00;
                                    q->unk_58 |= 1 << p->unk_00;
                                }

                                p->unk_40 = q->unk_0C - q->height;
                                p->unk_4C = pen;
                                p->unk_48 = q->unk_08 >> 1;
                                p->unk_44 = q->unk_04;
                                p->unk_50 = q;
                                p->unk_34 = q->unk_00;
                                q->unk_34 = p->unk_00;
                            }
                        }

                        if (p->unk_30 & 1) {
                            if (p->unk_0C - p->height >= q->unk_0C) {
                                q->unk_2E |= 1;

                                if (p->unk_0C - p->height == q->unk_0C) {
                                    p->unk_2E |= 2;
                                    p->unk_58 |= 1 << q->unk_00;
                                    q->unk_58 |= 1 << p->unk_00;
                                }

                                q->unk_40 = p->unk_0C - p->height;
                                q->unk_4C = pen;
                                q->unk_48 = p->unk_08 >> 1;
                                q->unk_44 = p->unk_04;
                                q->unk_50 = p;
                                p->unk_34 = q->unk_00;
                                q->unk_34 = p->unk_00;
                            }
                        }
                    }
                }
            }

            q = ListPoolPrev(&q->unk_18);
        }

        p = ListPoolNext(&p->unk_18);
    }
}

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
