#include "macros.h"
#include "mode_chkobj.h"

void mode_chkobj_0(void) {
    func_08004DB0();
    gUnk_0203489C = EwramAlloc(sizeof(ChkObjWork));
    TaskPoolInit(&gUnk_0203489C->pool, 1);
    TaskCreate(&gUnk_0203489C->pool, &gUnk_09EE9190, 0);
    gUnk_0203489C->unk_14 = 0;
    gUnk_0203489C->unk_16 = 0;
    gUnk_0203489C->unk_18 = 0;
    gUnk_0203489C->unk_1C = AllocObjTiles(0x2000, 0);
    gUnk_0203489C->unk_20 = LoadObjPalette(gUnk_08F683A4, 0x20);
    gUnk_0203489C->unk_3C = gUnk_088B629C;
    gUnk_0203489C->unk_40 = 0;
    gUnk_0203489C->unk_42 = 0x80A0;
    gUnk_0203489C->unk_44 = 0;
    gUnk_0203489C->unk_46 = 0;
    func_0800B30C(gUnk_0812E744[0].unk_00);
    SetupBg(1, 0, 15, 0);
    EnableBg(0);
    func_0805FA8C(1, 0x5400, 0x500);
    func_0805FA60(1, gUnk_08128304, 0x20, 0x0F);
    func_0805FCB0(166, 0, 2, gUnk_0812E744[0].unk_08);
}

void mode_chkobj_1(void) {
    ObjDef* def;
    u16 keys;
    s16 v;

    if (GetKeysPressed() & 2) {
        func_080010CC(&gUnk_09ECEB64, 0);
    } else {
        if (GetKeysPressed() & 8) {
            gUnk_0203489C->unk_40 = !gUnk_0203489C->unk_40;
        }

        if (AnimIsFinished(&gUnk_0203489C->unk_24) && (GetKeysHeld() & 1)) {
            AnimStart(&gUnk_0203489C->unk_24, gUnk_0203489C->unk_16, 0);
        }

        if (GetKeysRepeat() & 0x30) {
            if (GetKeysRepeat() & 0x20) {
                gUnk_0203489C->unk_16--;
            }

            if (GetKeysRepeat() & 0x10) {
                gUnk_0203489C->unk_16++;
            }

            gUnk_0203489C->unk_46 = 0;
            gUnk_0203489C->unk_40 = 0;
            gUnk_0203489C->unk_44 = 0;
            def = &gUnk_0812E744[gUnk_0203489C->unk_18].unk_00[gUnk_0203489C->unk_14];

            if (gUnk_0203489C->unk_16 < 0) {
                gUnk_0203489C->unk_14--;

                if (gUnk_0203489C->unk_14 < 0) {
                    gUnk_0203489C->unk_18--;

                    if (gUnk_0203489C->unk_18 < 0) {
                        gUnk_0203489C->unk_18 = 9;
                    }

                    gUnk_0203489C->unk_14 = gUnk_0812E744[gUnk_0203489C->unk_18].unk_04 - 1;
                }

                def = &gUnk_0812E744[gUnk_0203489C->unk_18].unk_00[gUnk_0203489C->unk_14];
                gUnk_0203489C->unk_16 = def->unk_0C - 1;
                func_0800B30C(def);
            } else if (gUnk_0203489C->unk_16 >= def->unk_0C) {
                gUnk_0203489C->unk_14++;

                if (gUnk_0203489C->unk_14 >= gUnk_0812E744[gUnk_0203489C->unk_18].unk_04) {
                    gUnk_0203489C->unk_18++;

                    if ((u16)gUnk_0203489C->unk_18 > 9) {
                        gUnk_0203489C->unk_18 = 0;
                    }

                    gUnk_0203489C->unk_14 = 0;
                }

                def = &gUnk_0812E744[gUnk_0203489C->unk_18].unk_00[gUnk_0203489C->unk_14];
                gUnk_0203489C->unk_16 = 0;
                func_0800B30C(def);
            } else {
                AnimStart(&gUnk_0203489C->unk_24, gUnk_0203489C->unk_16, 0);
            }

            func_0805FCB0(166, 0, 2, gUnk_0812E744[gUnk_0203489C->unk_18].unk_08);
        }

        keys = GetKeysHeld() & 4;

        if (keys != 0) {
            if (GetKeysHeld() & 0x200) {
                gUnk_0203489C->unk_42--;
            }

            if (GetKeysHeld() & 0x100) {
                gUnk_0203489C->unk_42++;
            }
        } else if (GetKeysRepeat() & 0x300) {
            gUnk_0203489C->unk_46 = 0;
            gUnk_0203489C->unk_40 = 0;
            gUnk_0203489C->unk_44 = 0;

            if (GetKeysRepeat() & 0x200) {
                gUnk_0203489C->unk_18--;
            }

            if (GetKeysRepeat() & 0x100) {
                gUnk_0203489C->unk_18++;
            }

            if (gUnk_0203489C->unk_18 < 0) {
                gUnk_0203489C->unk_18 = 9;
            } else if ((u16)gUnk_0203489C->unk_18 > 9) {
                gUnk_0203489C->unk_18 = 0;
            }

            gUnk_0203489C->unk_16 = 0;
            gUnk_0203489C->unk_14 = 0;
            def = gUnk_0812E744[gUnk_0203489C->unk_18].unk_00;
            func_0800B30C(def);
            func_0805FCB0(166, 0, 2, gUnk_0812E744[gUnk_0203489C->unk_18].unk_08);
        }

        func_08005778(abs(gSineTable[gUnk_0203489C->unk_42 & 0xFF] * 5 >> 6),
                      abs(gSineTable[(gUnk_0203489C->unk_42 / 2) & 0xFF] * 5 >> 6),
                      abs(gSineTable[(gUnk_0203489C->unk_42 / 4) & 0xFF] * 5 >> 6));

        if (GetKeysHeld() & 0x40) {
            gUnk_0203489C->unk_46--;
        } else if (GetKeysHeld() & 0x80) {
            gUnk_0203489C->unk_46++;
        }

        TaskPoolUpdate(&gUnk_0203489C->pool);
        TaskPoolDraw(&gUnk_0203489C->pool);

        if (gUnk_0203489C->unk_40 == 0 || (GetKeysRepeat() & 1)) {
            AnimUpdate(&gUnk_0203489C->unk_24);
        }

        gUnk_0203489C->unk_3C = AnimGetGfx(&gUnk_0203489C->unk_24);

        if (gUnk_0203489C->unk_40 != 0) {
            func_0809D2B0(0, 1, 0, gUnk_0812E884);
        } else {
            func_0809D2B0(0, 1, 0, gUnk_0812E88C);
        }

        def = &gUnk_0812E744[gUnk_0203489C->unk_18].unk_00[gUnk_0203489C->unk_14];
        func_0809D2B0(0, 12, 0, gUnk_0812E894);
        func_0809D2B0(0, 13, 0, gUnk_0812E894);
        func_0809D2B0(0, 14, 0, gUnk_0812E894);
        func_0809D2B0(0, 15, 0, gUnk_0812E894);
        func_0809D2B0(0, 16, 0, gUnk_0812E894);
        func_0809D2B0(0, 17, 0, gUnk_0812E894);
        func_0809D2B0(0, 18, 0, gUnk_0812E894);
        func_0809D2B0(0, 19, 0, gUnk_0812E894);
        func_0809D2B0(0, 0, 0, gUnk_0812E8BC);
        func_0809D458(0, 0, 0, gUnk_0203489C->unk_14);
        func_0809D2B0(0, 12, 0, def->unk_14);
        func_0809D2B0(0, 13, 0, gUnk_0812E8C4);
        func_0809D458(6, 13, 0, func_08005B38(&gUnk_0203489C->unk_24));
        func_0809D2B0(0, 14, 0, def->unk_18);
        func_0809D2B0(0, 15, 0, gUnk_0812E8C8);
        func_0809D458(6, 15, 0, gUnk_0203489C->unk_16);
        func_0809D2B0(0, 16, 0, gUnk_0812E8D0);
        func_0809D458(6, 16, 0, gUnk_0203489C->unk_24.frame);
        func_0809D2B0(0, 17, 0, gUnk_0812E8D4);
        func_0809D458(6, 17, 0, gUnk_0203489C->unk_24.timer);
        v = func_08003598(gUnk_0203489C->unk_3C) >> 5;
        func_0809D2B0(0, 18, 0, gUnk_0812E8DC);
        func_0809D458(6, 18, 0, v);

        if (gUnk_0203489C->unk_44 < v) {
            gUnk_0203489C->unk_44 = v;
        }

        func_0809D2B0(0, 19, 0, gUnk_0812E8E4);
        func_0809D458(6, 19, 0, gUnk_0203489C->unk_44);
        DrawSprite(120, gUnk_0203489C->unk_46 + 96, gUnk_0203489C->unk_3C, gUnk_0203489C->unk_1C,
                   gUnk_0203489C->unk_20, 0, 0, 0);
        func_080605A4(1);
        func_08060598();
    }
}

void mode_chkobj_2(void) {
    TaskPoolDestroy(&gUnk_0203489C->pool);
    ReleaseObjTiles(gUnk_0203489C->unk_1C);
    ReleaseObjPalette(gUnk_0203489C->unk_20);
    EwramFree(gUnk_0203489C);
    func_080609A0();
}
