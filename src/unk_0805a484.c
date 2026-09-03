#include "macros.h"
#include "hum.h"
#include "gba/keys.h"

void func_0805A484(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        gJiminyWork->unk_C68[i] = 0;
        func_08065AE0(&gJiminyWork->unk_060[i], 48);

        for (j = 0; j < 48; j++) {
            if (gJiminyWork->unk_060[i].unk_000[j].unk_00 != 0) {
                gJiminyWork->unk_060[i].unk_000[j].unk_00 = 0;
            }
        }
    }
}

void func_0805A4D8(s16 a, s16 b, s16 c) {
    gJiminyWork->unk_CC0 = 0;
    gJiminyWork->unk_058 = a << 8;
    gJiminyWork->unk_05C = (b + gJiminyWork->unk_C74 * c) << 8;
}

void func_0805A514(s16 a, s16 b, s16 c) {
    s32 v;

    v = (b + gJiminyWork->unk_C74 * c) << 8;
    func_0805F1C0(&gJiminyWork->unk_05C, v);

    if (gJiminyWork->unk_CC0 > 0) {
        gJiminyWork->unk_CC0--;
    }
}

#ifndef VERSION_JP
u16 func_0805A55C(u16* p) {
    s32 n;
    u16* q;

    n = 0;
    q = p;

    while (1) {
        if (*q == 0) {
            return n;
        }
        q++;
        n++;
    }
}
#else
INCLUDE_ASM("unk_0805a484/func_0805A55C.s");
#endif

s32 func_0805A574(s32 idx) {
    JiminyEntry* e;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 i;

    e = &gUnk_08155554[idx];
    if (e->unk_10 != 0) {
        a = 1;
        b = 1;

        for (i = 0; i < e->unk_08; i++) {
            if (func_0800FF70(e->unk_10[i])) {
                return 1;
            }

            if (func_0800FF00(e->unk_10[i]) == 0) {
                a = 0;
            } else {
                b = 0;
            }
        }

        if (a) {
            return 2;
        }

        if (b) {
            return 3;
        }
        return 0;
    }

    if (e->unk_0C == 0) {
        return 3;
    }
    c = 1;
    d = 1;

    for (i = 0; i < e->unk_08; i++) {
        switch (func_0805A574(e->unk_0C[i])) {
        case 1:
            return 1;
        case 0:
            c = 0;
            d = 0;
            break;
        case 2:
            d = 0;
            break;
        case 3:
            c = 0;
            break;
        }
    }

    if (c) {
        return 2;
    }

    if (d) {
        return 3;
    }
    return 0;
}

void func_0805A638(s32 a, u16** b) {
    s16 t;

    t = func_0805A55C(b[a]);
    t--;
    if (t < 0) {
        t = 0;
    }

    if (t > 12) {
        t = 12;
    }
    gJiminyWork->unk_C60[a] = func_08065B6C(gUnk_09EDE3FC[t], &gJiminyWork->unk_060[a]);
}

void func_0805A698(s16 a, s16 b, u16** d, u16* c, u16* e, s16 f, s16 g, s16 h) {
    s16 n;
    s32 i;

    n = a > b ? b : a;

    if (c == 0) {
        for (i = 0; i < n; i++) {
            if (e != 0) {
                gJiminyWork->unk_C68[i] = func_0805A574(e[i]);
                if (gJiminyWork->unk_C68[i] == 3) {
                    func_0805A638(i, d);
                } else {
                    gJiminyWork->unk_C60[i] =
                        func_08065B6C(d[i], &gJiminyWork->unk_060[i]);
                }
            } else {
                gJiminyWork->unk_C60[i] =
                    func_08065B6C(d[i], &gJiminyWork->unk_060[i]);
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (func_0800FF00(c[i])) {
                gJiminyWork->unk_C60[i] =
                    func_08065B6C(d[i], &gJiminyWork->unk_060[i]);

                if (func_0800FF70(c[i])) {
                    gJiminyWork->unk_C68[i] = 1;
                }
            } else {
                func_0805A638(i, d);
            }
        }
    }
}

void func_0805A7D0(void) {
    s16 t;

    t = gJiminyWork->unk_C72 - gJiminyWork->unk_C74;
    func_0805A484();

    if (gJiminyWork->unk_CB8 != 0) {
        func_0805A698(gJiminyWork->unk_C78, gJiminyWork->unk_C76,
            gJiminyWork->unk_CB4 + t, gJiminyWork->unk_CB8 + t, 0,
            gJiminyWork->unk_CAE, gJiminyWork->unk_CB0, gJiminyWork->unk_CB2);
    } else {
        func_0805A698(gJiminyWork->unk_C78, gJiminyWork->unk_C76,
            gJiminyWork->unk_CB4 + t, 0, gJiminyWork->unk_CBC + t,
            gJiminyWork->unk_CAE, gJiminyWork->unk_CB0, gJiminyWork->unk_CB2);
    }
}

void func_0805A8D0(void) {
    s16 t;

    t = gJiminyWork->unk_C72 - gJiminyWork->unk_C74;
    func_0805A484();
    func_0805A698(gJiminyWork->unk_C78, gJiminyWork->unk_C76,
        gJiminyWork->unk_CB4 + t, 0, 0,
        gJiminyWork->unk_CAE, gJiminyWork->unk_CB0, gJiminyWork->unk_CB2);
}

void func_0805A95C(s16 a, s16 b, u16** c, u16* d, u16* e, s16 f, s16 g, s16 h) {
    gJiminyWork->unk_CAE = f;
    gJiminyWork->unk_CB0 = g;
    gJiminyWork->unk_CB2 = h;
    gJiminyWork->unk_C76 = b;
    gJiminyWork->unk_C78 = a;
    gJiminyWork->unk_CB4 = c;
    gJiminyWork->unk_CB8 = d;
    gJiminyWork->unk_CBC = e;
    gJiminyWork->unk_CC2 = f + 56;
    gJiminyWork->unk_CC6 = f + 56;
    gJiminyWork->unk_CC4 = g - 10;
    gJiminyWork->unk_CC8 = g + h * (a - 1) + 12;
    gJiminyWork->unk_CAC = (gJiminyWork->unk_CAC & 0xFFE5) | 4;
    gJiminyWork->unk_C70 = 0;
    func_0805A4D8(gJiminyWork->unk_CAE - 24, gJiminyWork->unk_CB0 - 4,
        gJiminyWork->unk_CB2);
    func_0805A7D0();
    gJiminyWork->unk_D3E = 0;
}

u8 func_0805AA9C(void) {
    if (func_08006314()) {
        return 1;
    }

    if (gJiminyWork->unk_C70 < gJiminyWork->unk_C71) {
        AnimChange(&gJiminyWork->unk_C7C, 1, 1);

        if (!func_08006314()) {
            if (gJiminyWork->unk_048 % 5 == 0) {
                gJiminyWork->unk_C70++;
            }
        }
    } else {
        AnimChange(&gJiminyWork->unk_C7C, 0, 1);
    }

    if (gJiminyWork->unk_C74 < gJiminyWork->unk_C72) {
        gJiminyWork->unk_CAC |= 8;
    } else {
        gJiminyWork->unk_CAC &= 0xFFF7;
    }

    if (gJiminyWork->unk_C78 - gJiminyWork->unk_C74 <
        gJiminyWork->unk_C76 - gJiminyWork->unk_C72) {
        gJiminyWork->unk_CAC |= 0x10;
    } else {
        gJiminyWork->unk_CAC &= 0xFFEF;
    }

    if (gJiminyWork->unk_CC0 <= 0) {
        if (GetKeysRepeat() & DPAD_UP) {
            if (gJiminyWork->unk_C72 > 0) {
                gJiminyWork->unk_CC0 = 1;
                gJiminyWork->unk_C72--;
                m4aSongNumStart(101);

                if (gJiminyWork->unk_C74 > 0) {
                    gJiminyWork->unk_C74--;
                } else {
                    func_0805A7D0();
                }
            }
        } else if (GetKeysRepeat() & DPAD_DOWN) {
            if (gJiminyWork->unk_C72 < gJiminyWork->unk_C76 - 1) {
                gJiminyWork->unk_CC0 = 1;
                gJiminyWork->unk_C72++;
                m4aSongNumStart(101);

                if (gJiminyWork->unk_C74 < gJiminyWork->unk_C78 - 1) {
                    gJiminyWork->unk_C74++;
                } else {
                    func_0805A7D0();
                }
            }
        }
    }
    func_0805A514(gJiminyWork->unk_CAE - 24, gJiminyWork->unk_CB0 - 4,
        gJiminyWork->unk_CB2);

    if (GetKeysPressed() & 8) {
        gJiminyWork->unk_048 = 0;
        gJiminyWork->unk_000 = 5;
        m4aSongNumStart(104);
        return 1;
    }
    return 0;
}
