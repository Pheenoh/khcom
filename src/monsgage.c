#include "system_state.h"
#include "battle_localized_assets.h"
#include "monsgage.h"

#ifndef VERSION_EU
void task_monsgage_0(MonsgageWork* work) {
    work->tiles = AllocObjTiles(0x200, gUnk_08B255B4);
    work->tiles2 = AllocObjTiles(0x80, gUnk_08B255B4);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    work->unk_10 = 0;
    work->unk_0C = 0;
    work->gfx = gUnk_08B2556C;
    work->gfx2 = gUnk_08B2557C;
    work->unk_1C = 0;
    work->unk_20 = 0;
    work->unk_24 = 1;
}

s32 task_monsgage_1(MonsgageWork* work) {
    if (gBtlWork->unk_0A0 != 0) {
        if (gBtlWork->unk_0A0 == 4) {
            return 0;
        }

        switch (work->unk_20) {
        case 0:
            if (work->unk_1C == 0) {
                work->unk_24 = 1;
                work->gfx2 = gUnk_08B2557C;
            }

            if (work->unk_1C > 120) {
                work->unk_20 = 1;
                work->unk_1C = 0;
            } else {
                work->unk_1C++;
            }
            break;
        case 1:
            if (work->unk_1C == 0) {
                work->gfx2 = gUnk_08B25586;
            }

            if (work->unk_1C % 8 < 4) {
                work->unk_24 = 1;
            } else {
                work->unk_24 = 0;
            }

            if ((work->unk_1C % 4) == 0) {
                work->unk_0C--;
                if (work->unk_0C < 0) {
                    work->unk_0C = 0;
                }
            }

            if (gBtlWork->unk_068 & 0x10000) {
                gBtlWork->unk_068 &= ~0x10000;
                work->unk_1C = 0;
                work->unk_0C += 25;
                if (work->unk_0C <= 255) {
                    work->unk_20 = 0;
                } else {
                    work->unk_0C = 256;
                    work->unk_20 = 2;
                }
            } else {
                work->unk_1C++;
            }
            break;
        case 2:
            if (work->unk_1C == 0) {
                work->gfx2 = gUnk_08B25590;
                work->gfx = gUnk_08B2559A;
                gBtlWork->unk_068 |= 0x0100000000000000;
                gBtlWork->unk_068 |= 0x100000;
            }

            if (work->unk_1C % 8 < 4) {
                work->unk_24 = 1;
            } else {
                work->unk_24 = 0;
            }

            if (work->unk_1C > 99 && gBtlWork->unk_0EE == 0) {
                gBtlWork->unk_068 |= 0x200000000;
            }
            work->unk_1C++;
            break;
        }
        work->unk_10 += (work->unk_0C - work->unk_10) >> 2;
    }
    return 1;
}

void task_monsgage_2(MonsgageWork* work) {
    s32 affine;

    if (gBtlWork->unk_0A0 != 0) {
        DrawSprite(172, 12, work->gfx, work->tiles, work->palette, 0, 0x410, 3);

        if (work->unk_24 != 0) {
            if (work->unk_10 * 2 > 4) {
                if (work->unk_10 * 2 > 256) {
                    affine = AllocObjAffine(0, work->unk_10 * 2, 256, 1);
                } else {
                    affine = AllocObjAffine(0, work->unk_10 * 2, 256, 0);
                }
                DrawSprite(174, 16, work->gfx2, work->tiles2, work->palette, affine, 0x410, 2);
            }
        }
    }
}

void task_monsgage_3(MonsgageWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette);
}
#endif

#ifdef VERSION_EU
void* eu_0805E924(void* strings) {
    void** s = strings;

    switch (gLanguage) {
    case 3:
        return s[3];
    case 1:
        return s[1];
    case 4:
        return s[4];
    case 2:
        return s[2];
    case 0:
    default:
        return s[0];
    }
}

void* eu_0805E968(void* text) {
    void** s = text;

    switch (gLanguage) {
    case 3:
        return s[3];
    case 1:
        return s[1];
    case 4:
        return s[4];
    case 2:
        return s[2];
    case 0:
    default:
        return s[0];
    }
}

s32 eu_0805E9AC(void* text) {
    u16* s = text;

    switch (gLanguage) {
    case 3:
        return s[13];
    case 1:
        return s[11];
    case 4:
        return s[14];
    case 2:
        return s[12];
    case 0:
    default:
        return s[10];
    }
}

void eu_0805E9F0(MonsgageWork* work) {
    work->tiles = AllocObjTiles(0x200, gUnkEu_08B4FBC0);
    work->tiles2 = AllocObjTiles(0x80, gUnkEu_08B4FBC0);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    work->unk_10 = 0;
    work->unk_0C = 0;
    work->gfx = gUnkEu_08B4FB78;
    work->gfx2 = gUnkEu_08B4FB88;
    work->unk_1C = 0;
    work->unk_20 = 0;
    work->unk_24 = 1;
}

s32 eu_0805EA44(MonsgageWork* work) {
    if (gBtlWork->unk_0A0 != 0) {
        if (gBtlWork->unk_0A0 == 4) {
            return 0;
        }

        switch (work->unk_20) {
        case 0:
            if (work->unk_1C == 0) {
                work->unk_24 = 1;
                work->gfx2 = gUnkEu_08B4FB88;
            }

            if (gBtlWork->unk_068 & 0x10000) {
                gBtlWork->unk_068 &= ~0x10000;
                work->unk_0C += 20;
                if (work->unk_0C > 255) {
                    work->unk_0C = 256;
                    work->unk_20 = 2;
                    work->unk_1C = 0;
                    break;
                }
            } else if (work->unk_1C > 120) {
                work->unk_20 = 1;
                work->unk_1C = 0;
                break;
            }
            work->unk_1C++;
            break;
        case 1:
            if (work->unk_1C == 0) {
                work->gfx2 = gUnkEu_08B4FB92;
            }

            if (work->unk_1C % 8 < 4) {
                work->unk_24 = 1;
            } else {
                work->unk_24 = 0;
            }

            if ((work->unk_1C % 4) == 0) {
                work->unk_0C--;
                if (work->unk_0C < 0) {
                    work->unk_0C = 0;
                }
            }

            if (gBtlWork->unk_068 & 0x10000) {
                gBtlWork->unk_068 &= ~0x10000;
                work->unk_1C = 0;
                work->unk_0C += 20;
                if (work->unk_0C <= 255) {
                    work->unk_20 = 0;
                } else {
                    work->unk_0C = 256;
                    work->unk_20 = 2;
                }
            } else {
                work->unk_1C++;
            }
            break;
        case 2:
            if (work->unk_1C == 0) {
                work->gfx2 = gUnkEu_08B4FB9C;
                work->gfx = gUnkEu_08B4FBA6;
                gBtlWork->unk_068 |= 0x0100000000000000;
                gBtlWork->unk_068 |= 0x100000;
            }

            if (work->unk_1C % 8 < 4) {
                work->unk_24 = 1;
            } else {
                work->unk_24 = 0;
            }

            if (work->unk_1C > 99 && gBtlWork->unk_0EE == 0) {
                gBtlWork->unk_068 |= 0x200000000;
            }
            work->unk_1C++;
            break;
        }
        work->unk_10 += (work->unk_0C - work->unk_10) >> 2;
    }
    return 1;
}

void eu_0805EC60(MonsgageWork* work) {
    s32 affine;

    if (gBtlWork->unk_0A0 != 0) {
        DrawSprite(172, 12, work->gfx, work->tiles, work->palette, 0, 0x410, 3);

        if (work->unk_24 != 0) {
            if (work->unk_10 * 2 > 4) {
                if (work->unk_10 * 2 > 256) {
                    affine = AllocObjAffine(0, work->unk_10 * 2, 256, 1);
                } else {
                    affine = AllocObjAffine(0, work->unk_10 * 2, 256, 0);
                }
                DrawSprite(174, 16, work->gfx2, work->tiles2, work->palette, affine, 0x410, 2);
            }
        }
    }
}

void eu_0805ECE4(MonsgageWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette);
}
#endif
