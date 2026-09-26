#include "mode_pooh.h"
#include "sprites_pooh.h"
#include "world_types.h"

Mode gModePooh = {
    "mode_pooh",
    mode_pooh_0,
    mode_pooh_1,
    mode_pooh_2,
};

const PoohHit gUnk_096FC010 = { gPoohPalette, 36, 16, 6, 0 };

const s8 gUnk_096FC01C[8][8] = {
    { 0, 1, 2, 2, 3, -2, -2, -1 },
    { -1, 0, 1, 2, 2, 3, -2, -2 },
    { -2, -1, 0, 1, 2, 2, 3, -2 },
    { -2, -2, -1, 0, 1, 2, 2, 3 },
    { 3, -2, -2, -1, 0, 1, 2, 2 },
    { -2, 3, 2, 2, 1, 0, -1, -2 },
    { -2, -2, 3, 2, 2, 1, 0, -1 },
    { -1, -2, -2, 3, 2, 2, 1, 0 },
};

AnimDef gUnk_09EF3C98[5] = {
    { gPoohBb00Frames, gPoohBb00Anims, gPoohBb00Tiles, 0, { 0, 0, 0 } },
    { gPoohFf00Frames, gPoohFf00Anims, gPoohFf00Tiles, 0, { 0, 0, 0 } },
    { gPoohFr00Frames, gPoohFr00Anims, gPoohFr00Tiles, 0, { 0, 0, 0 } },
    { gPoohRr00Frames, gPoohRr00Anims, gPoohRr00Tiles, 0, { 0, 0, 0 } },
    { gPoohBr00Frames, gPoohBr00Anims, gPoohBr00Tiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3CE8[5] = {
    { gPoohBb04Frames, gPoohBb04Anims, gPoohBb04Tiles, 0, { 0, 0, 0 } },
    { gPoohFf04Frames, gPoohFf04Anims, gPoohFf04Tiles, 0, { 0, 0, 0 } },
    { gPoohFl04Frames, gPoohFl04Anims, gPoohFl04Tiles, 0, { 0, 0, 0 } },
    { gPoohLl04Frames, gPoohLl04Anims, gPoohLl04Tiles, 0, { 0, 0, 0 } },
    { gPoohBl04Frames, gPoohBl04Anims, gPoohBl04Tiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3D38[5] = {
    { gPoohBb04aFrames, gPoohBb04aAnims, gPoohBb04aTiles, 0, { 0, 0, 0 } },
    { gPoohFf04aFrames, gPoohFf04aAnims, gPoohFf04aTiles, 0, { 0, 0, 0 } },
    { gPoohFl04aFrames, gPoohFl04aAnims, gPoohFl04aTiles, 0, { 0, 0, 0 } },
    { gPoohLl04aFrames, gPoohLl04aAnims, gPoohLl04aTiles, 0, { 0, 0, 0 } },
    { gPoohBl04aFrames, gPoohBl04aAnims, gPoohBl04aTiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3D88[8] = {
    { gPoohBb01Frames, gPoohBb01Anims, gPoohBb01Tiles, 0, { 0, 0, 0 } },
    { gPoohFf01Frames, gPoohFf01Anims, gPoohFf01Tiles, 0, { 0, 0, 0 } },
    { gPoohFr01Frames, gPoohFr01Anims, gPoohFr01Tiles, 0, { 0, 0, 0 } },
    { gPoohRr01Frames, gPoohRr01Anims, gPoohRr01Tiles, 0, { 0, 0, 0 } },
    { gPoohBr01Frames, gPoohBr01Anims, gPoohBr01Tiles, 0, { 0, 0, 0 } },
    { gPoohFl01Frames, gPoohFl01Anims, gPoohFl01Tiles, 0, { 0, 0, 0 } },
    { gPoohLl01Frames, gPoohLl01Anims, gPoohLl01Tiles, 0, { 0, 0, 0 } },
    { gPoohBl01Frames, gPoohBl01Anims, gPoohBl01Tiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3E08[8] = {
    { gTrap0001bbFrames, gTrap0001bbAnims, gTrap0001bbTiles, 0, { 0, 0, 0 } },
    { gTrap0001ffFrames, gTrap0001ffAnims, gTrap0001ffTiles, 0, { 0, 0, 0 } },
    { gTrap0001frFrames, gTrap0001frAnims, gTrap0001frTiles, 0, { 0, 0, 0 } },
    { gTrap0001rrFrames, gTrap0001rrAnims, gTrap0001rrTiles, 0, { 0, 0, 0 } },
    { gTrap0001brFrames, gTrap0001brAnims, gTrap0001brTiles, 0, { 0, 0, 0 } },
    { gTrap0001flFrames, gTrap0001flAnims, gTrap0001flTiles, 0, { 0, 0, 0 } },
    { gTrap0001llFrames, gTrap0001llAnims, gTrap0001llTiles, 0, { 0, 0, 0 } },
    { gTrap0001blFrames, gTrap0001blAnims, gTrap0001blTiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3E88 = { gTrap0002Frames, gTrap0002Anims, gTrap0002Tiles, 0, { 0, 0, 0 } };

AnimDef gUnk_09EF3E98 = { gTrap0002Frames, gTrap0002Anims, gTrap0002Tiles, 1, { 0, 0, 0 } };

AnimDef gUnk_09EF3EA8 = { gTrap0003Frames, gTrap0003Anims, gTrap0003Tiles, 0, { 0, 0, 0 } };

AnimDef gUnk_09EF3EB8 = { gUnk_09EF5824, gUnk_09EF583C, gUnk_09724C1C, 1, { 0, 0, 0 } };

AnimDef gUnk_09EF3EC8[2] = {
    { gPoohBl03Frames, gPoohBl03Anims, gPoohBl03Tiles, 0, { 0, 0, 0 } },
    { gPoohFl03Frames, gPoohFl03Anims, gPoohFl03Tiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3EE8[2] = {
    { gPoohBl07Frames, gPoohBl07Anims, gPoohBl07Tiles, 0, { 0, 0, 0 } },
    { gPoohFl07Frames, gPoohFl07Anims, gPoohFl07Tiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3F08[2] = {
    { gPoohBl07Frames, gPoohBl07Anims, gPoohBl07Tiles, 1, { 0, 0, 0 } },
    { gPoohFl07Frames, gPoohFl07Anims, gPoohFl07Tiles, 1, { 0, 0, 0 } },
};

AnimDef gUnk_09EF3F28 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 0, { 0, 0, 0 } };

AnimDef gUnk_09EF3F38 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 1, { 0, 0, 0 } };

AnimDef gUnk_09EF3F48 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 2, { 0, 0, 0 } };

AnimDef gUnk_09EF3F58 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 3, { 0, 0, 0 } };

AnimDef gUnk_09EF3F68 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 4, { 0, 0, 0 } };

AnimDef gUnk_09EF3F78 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 5, { 0, 0, 0 } };

AnimDef gUnk_09EF3F88 = { gPoohFl05Frames, gPoohFl05Anims, gPoohFl05Tiles, 9, { 0, 0, 0 } };

AnimDef gUnk_09EF3F98 = { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 1, { 0, 0, 0 } };

AnimDef gUnk_09EF3FA8 = { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 2, { 0, 0, 0 } };

AnimDef gUnk_09EF3FB8 = { gPoohFl06Frames, gPoohFl06Anims, gPoohFl06Tiles, 3, { 0, 0, 0 } };

AnimDef gUnk_09EF3FC8 = { gPoohFl09Frames, gPoohFl09Anims, gPoohFl09Tiles, 0, { 0, 0, 0 } };

AnimDef gUnk_09EF3FD8 = { gPoohFl09Frames, gPoohFl09Anims, gPoohFl09Tiles, 1, { 0, 0, 0 } };

AnimDef gUnk_09EF3FE8 = { gPoohFl09Frames, gPoohFl09Anims, gPoohFl09Tiles, 2, { 0, 0, 0 } };

AnimDef gUnk_09EF3FF8[4] = {
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0, { 0, 0, 0 } },
    { gPoohFf10Frames, gPoohFf10Anims, gPoohFf10Tiles, 0, { 0, 0, 0 } },
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0, { 0, 0, 0 } },
    { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0, { 0, 0, 0 } },
};

AnimDef gUnk_09EF4038 = { gPoohLl10Frames, gPoohLl10Anims, gPoohLl10Tiles, 0, { 0, 0, 0 } };

AnimDef gUnk_09EF4048[5][5] = {
    {
        { gPoohBb00LlFrames, gPoohBb00LlAnims, gPoohBb00LlTiles, 0, { 0, 0, 0 } },
        { gPoohBb00BlFrames, gPoohBb00BlAnims, gPoohBb00BlTiles, 0, { 0, 0, 0 } },
        { gPoohBb00Frames, gPoohBb00Anims, gPoohBb00Tiles, 0, { 0, 0, 0 } },
        { gPoohBb00BrFrames, gPoohBb00BrAnims, gPoohBb00BrTiles, 0, { 0, 0, 0 } },
        { gPoohBb00RrFrames, gPoohBb00RrAnims, gPoohBb00RrTiles, 0, { 0, 0, 0 } },
    },
    {
        { gPoohFf00RrFrames, gPoohFf00RrAnims, gPoohFf00RrTiles, 0, { 0, 0, 0 } },
        { gPoohFf00FrFrames, gPoohFf00FrAnims, gPoohFf00FrTiles, 0, { 0, 0, 0 } },
        { gPoohFf00Frames, gPoohFf00Anims, gPoohFf00Tiles, 0, { 0, 0, 0 } },
        { gPoohFf00FlFrames, gPoohFf00FlAnims, gPoohFf00FlTiles, 0, { 0, 0, 0 } },
        { gPoohFf00LlFrames, gPoohFf00LlAnims, gPoohFf00LlTiles, 0, { 0, 0, 0 } },
    },
    {
        { gPoohFr00BrFrames, gPoohFr00BrAnims, gPoohFr00BrTiles, 0, { 0, 0, 0 } },
        { gPoohFr00RrFrames, gPoohFr00RrAnims, gPoohFr00RrTiles, 0, { 0, 0, 0 } },
        { gPoohFr00Frames, gPoohFr00Anims, gPoohFr00Tiles, 0, { 0, 0, 0 } },
        { gPoohFr00FfFrames, gPoohFr00FfAnims, gPoohFr00FfTiles, 0, { 0, 0, 0 } },
        { gPoohFr00FlFrames, gPoohFr00FlAnims, gPoohFr00FlTiles, 0, { 0, 0, 0 } },
    },
    {
        { gPoohRr00BbFrames, gPoohRr00BbAnims, gPoohRr00BbTiles, 0, { 0, 0, 0 } },
        { gPoohRr00BrFrames, gPoohRr00BrAnims, gPoohRr00BrTiles, 0, { 0, 0, 0 } },
        { gPoohRr00Frames, gPoohRr00Anims, gPoohRr00Tiles, 0, { 0, 0, 0 } },
        { gPoohRr00FrFrames, gPoohRr00FrAnims, gPoohRr00FrTiles, 0, { 0, 0, 0 } },
        { gPoohRr00FfFrames, gPoohRr00FfAnims, gPoohRr00FfTiles, 0, { 0, 0, 0 } },
    },
    {
        { gPoohBr00BlFrames, gPoohBr00BlAnims, gPoohBr00BlTiles, 0, { 0, 0, 0 } },
        { gPoohBr00BbFrames, gPoohBr00BbAnims, gPoohBr00BbTiles, 0, { 0, 0, 0 } },
        { gPoohBr00Frames, gPoohBr00Anims, gPoohBr00Tiles, 0, { 0, 0, 0 } },
        { gPoohBr00RrFrames, gPoohBr00RrAnims, gPoohBr00RrTiles, 0, { 0, 0, 0 } },
        { gPoohBr00FrFrames, gPoohBr00FrAnims, gPoohBr00FrTiles, 0, { 0, 0, 0 } },
    },
};

static u16 gUnk_02034CF8;
static u32 gUnk_02034CFC;
static u32 gUnk_02034D00;
static u32 gUnk_02034D04;
static u16 gUnk_02034D08;
static u32 gUnk_02034D0C;
static u8 gUnk_02034D10;
static TaskPool gUnk_02034D18;
static TaskPool gUnk_02034D30;
static u8 gUnk_02034D44;
static u32 gUnk_02034D48;
static u16 gUnk_02034D4C;
static Task* gUnk_02034D50[12];
static TaskPool gUnk_02034D80;
static Task* gWLogoTask;
static u8 gUnk_02034D98;
static s32 gUnk_02034D9C;
static s32 gUnk_02034DA0;
static s32 gUnk_02034DA4;

void func_080C736C(void) {
    gUnk_02034CFC = 0;
    gUnk_02034D00 = 0;
    gUnk_02034D04 = 0;
    gUnk_02034D08 = 0;
    gUnk_02034D0C = 0;
    gUnk_02034D10 = 0;
}

void func_080C73A4(u16 r, u16 g, u16 b) {
    SetBackdropColor(r, g, b);
    gUnk_02034CF8 = (b << 10) | (g << 5) | r;
}

void func_080C73D8(void) {
    u16 amt;
    u16 r;
    u16 g;
    u16 b;

    if (gUnk_02034CFC != gUnk_02034D04) {
        amt = gUnk_02034CFC >> 8;
        r = gUnk_02034CF8 & 31;
        g = (gUnk_02034CF8 >> 5) & 31;
        b = (gUnk_02034CF8 >> 10) & 31;

        switch (gUnk_02034D0C) {
        case 0:
            r -= amt;
            g -= amt;
            b -= amt;

            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b < 0) {
                b = 0;
            }
            break;
        case 1:
            if ((s16)r < amt) {
                r = amt;
            }

            if ((s16)g < amt) {
                g = amt;
            }

            if ((s16)b < amt) {
                b = amt;
            }
            break;
        case 3:
            r = amt + r;
            g -= amt;
            b -= amt;

            if ((s16)r > 31) {
                r = 31;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b < 0) {
                b = 0;
            }
            break;
        case 5:
            r -= amt;
            g = amt + g;
            b -= amt;

            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g > 31) {
                g = 31;
            }

            if ((s16)b < 0) {
                b = 0;
            }
            break;
        case 4:
            r -= amt;
            g -= amt;
            b = amt + b;

            if ((s16)r < 0) {
                r = 0;
            }

            if ((s16)g < 0) {
                g = 0;
            }

            if ((s16)b > 31) {
                b = 31;
            }
            break;
        default:
            r = amt + r;
            g = amt + g;
            b = amt + b;

            if ((s16)r > 31) {
                r = 31;
            }

            if ((s16)g > 31) {
                g = 31;
            }

            if ((s16)b > 31) {
                b = 31;
            }
            break;
        }
        SetBackdropColor(r, g, b);
    }

    if (gUnk_02034D08 != 0) {
        gUnk_02034D04 = gUnk_02034CFC;
        ApproachValue(&gUnk_02034CFC, gUnk_02034D00, gUnk_02034D08);
        gUnk_02034D08--;
    } else {
        gUnk_02034D10 = 0;
    }
}

void func_080C7568(u32 a, u16 b) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = b;
    gUnk_02034CFC = 0x1F00;
    gUnk_02034D00 = 0;
    gUnk_02034D04 = 0;
    gUnk_02034D0C = a;
}

void func_080C75A4(u32 a, u16 b) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = b;
    gUnk_02034CFC = 0;
    gUnk_02034D00 = 0x1F00;
    gUnk_02034D04 = 0;
    gUnk_02034D0C = a;
}

void func_080C75E0(u32 a, u16 b) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = b;
    gUnk_02034D00 = 0;
    gUnk_02034D0C = a;
}

void func_080C7608(u32 a, u16 b, u16 c) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = c;
    gUnk_02034D00 = b << 8;
    gUnk_02034D0C = a;
}

u8 func_080C7638(void) {
    return gUnk_02034D10;
}

void func_080C7644(u32 a, u16 b, u16 c) {
    gUnk_02034D10 = 1;
    gUnk_02034D08 = c;
    gUnk_02034CFC = b << 8;
    gUnk_02034D04 = 0;
    gUnk_02034D00 = 0;
    gUnk_02034D0C = a;
}

void func_080C7684(s32 a, s32 b, s32 c) {
    gUnk_0203C3D8 = 1;
    gUnk_02034D9C = a;
    gUnk_02034DA0 = b * 2;
    gUnk_02034DA4 = c;
}

u8 func_080C76B0(PoohNear* p) {
    s32 lim;
    s32 dx;
    s32 dy;
    s32 dz;

    lim = p->unk_10 + 0x1400;
    dx = gUnk_02034D9C - p->unk_04;
    if (dx < 0) {
        dx = p->unk_04 - gUnk_02034D9C;
    }
    dy = gUnk_02034DA0 - p->unk_08;
    if (dy < 0) {
        dy = p->unk_08 - gUnk_02034DA0;
    }
    dz = gUnk_02034DA4 - p->unk_0C;
    if (dx < lim && dy < lim && dz <= 0x1FFF && -dz < p->unk_14) {
        return 1;
    }
    return 0;
}

void func_080C7714(void) {
    PoohPos p;

    p.x = 0x13000;
    p.y = 0xE800;
    p.z = 0;
    SetPooStatePos2(&p);
    p.x = 0x11000;
    p.y = 0xF800;
    p.z = 0;
    func_080D2C8C(&p, 0);
}

void func_080C774C(void) {
    PoohPos p;

    p.x = 0xB5400;
    p.y = 0x5DE00;
    p.z = 0;
    SetPooStatePos2(&p);

    if (func_080D2D94(3)) {
        p.x = 0xB3400;
        p.y = 0x5EE00;
        p.z = 0;
        func_080D2C8C(&p, 0);
    }
}

void mode_pooh_0(s32 arg) {
    s32 i;

    gGameState.world = WORLD_100_ACRE_WOOD;

    if (arg == 0) {
        func_080D2BE0();
        func_080C7714();
    } else if (arg == 2) {
        func_080D2BE0();
        func_080C774C();
    }

    m4aSongNumStart(SONG_BGM_POOHGAME);
    m4aSongNumStart(SONG_BG_POO);
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 2, 30, 0);
    SetupBg(0, 3, 31, 14);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    ColliderPoolsInit();
    func_080CCBE8();
    func_080D2E98();

    TaskPoolInit(&gUnk_02034D18, 32);

    for (i = 0; i < 12; i++) {
        gUnk_02034D50[i] = 0;
    }

    TaskCreate(&gUnk_02034D18, &gTaskDescPooSora, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooPiglet, 0);

    if (!func_080D2D50(2)) {
        TaskCreate(&gUnk_02034D18, &gTaskDescPooEeyoretail, 0);
        TaskCreate(&gUnk_02034D18, &gTaskDescPooBee, 0);
    } else {
        TaskCreate(&gUnk_02034D18, &gTaskDescPooBeeAfterEvent, 0);
    }

    TaskCreate(&gUnk_02034D18, &gTaskDescPooEeyore, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooHoneycomb, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooOwl, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooWagon, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooWagonwheel, 0);

    if (!func_080D2D50(4)) {
        TaskCreate(&gUnk_02034D18, &gTaskDescPooRabbit, 0);
        TaskCreate(&gUnk_02034D18, &gTaskDescPooCabbageborn, 0);
    } else {
        TaskCreate(&gUnk_02034D18, &gTaskDescPooRabbitAfterEvent, 0);
        TaskCreate(&gUnk_02034D18, &gTaskDescPooCabbageAfterEvent, 0);
    }

    TaskCreate(&gUnk_02034D18, &gTaskDescPooVegetable, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooTigger, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooRooFootmark, 0);

    if (func_080D2D50(5)) {
        if (!func_080D2D50(1)) {
            TaskCreate(&gUnk_02034D18, &gTaskDescPooRoo, 0);
        } else {
            TaskCreate(&gUnk_02034D18, &gTaskDescPooTiggerroo, 0);
        }
    }

    TaskCreate(&gUnk_02034D18, &gTaskDescPooMap, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooPooh, 0);
    TaskCreate(&gUnk_02034D18, &gTaskDescPooGauge, 0);

    TaskPoolInit(&gUnk_02034D80, 1);

    if (func_080D2D94(2)) {
        gWLogoTask = 0;
    } else {
        gWLogoTask = TaskCreate(&gUnk_02034D80, &gTaskDescWLogo, 0);
        func_080D2D6C(2);
    }

    TaskPoolInit(&gUnk_02034D30, 1);
    func_080C736C();
    func_080C73A4(6, 31, 31);
    FadeStartIn(0, 16);
    func_080C7568(0, 16);
    gUnk_02034D44 = 0;
#ifdef VERSION_EU
    gUnk_02034D4C = 179;
#else
    gUnk_02034D4C = 180;
#endif
}

void mode_pooh_1(void) {
    UpdatePlayTime();
    func_080C7CB0(0);

    if (gUnk_02034D44 != 0 && !FadeIsActive()) {
#ifdef VERSION_EU
        if (gUnk_02034D48 == 195) {
#else
        if (gUnk_02034D48 == 197) {
#endif
            func_080DF814();
        } else {
            func_0806180C(gUnk_02034D48);
        }
        return;
    }

    if (FadeIsActive() == 0) {
        gUnk_0203C3D8 = 0;

        if (IsTaskActive(gWLogoTask)) {
            TaskPoolUpdate(&gUnk_02034D80);
        } else if (func_080A42C8() == 0) {
            if (gUnk_02034D4C == 0xFFFE) {
                if (func_080A42D4()) {
#ifdef VERSION_EU
                    func_080C7B84(195);
#else
                    func_080C7B84(197);
#endif
                } else {
#ifdef VERSION_EU
                    gUnk_02034D4C = 179;
#else
                    gUnk_02034D4C = 180;
#endif
                }
            } else if (gUnk_02034D4C == 0xFFFD) {
                if (func_080A42D4()) {
#ifdef VERSION_EU
                    func_080C7B84(146);
#else
                    func_080C7B84(148);
#endif
                } else {
#ifdef VERSION_EU
                    gUnk_02034D4C = 179;
#else
                    gUnk_02034D4C = 180;
#endif
                }
            } else {
                TaskPoolUpdate(&gUnk_02034D18);
            }
        } else {
            TaskPoolUpdate(&gUnk_02034D30);
        }
    }

    TaskPoolDraw(&gUnk_02034D80);
    TaskPoolDraw(&gUnk_02034D30);
    TaskPoolDraw(&gUnk_02034D18);
    ColliderUpdateAll();
    func_080C73D8();
}

void mode_pooh_2(void) {
    TaskPoolDestroy(&gUnk_02034D18);
    TaskPoolDestroy(&gUnk_02034D30);
    TaskPoolDestroy(&gUnk_02034D80);
    func_080D2E84();
    m4aSongNumStop(SONG_BG_POO);
}

void func_080C7B84(u32 a) {
    s32 i;

    if (gUnk_02034D44 == 0) {
        gUnk_02034D48 = a;

        for (i = 0; i <= 31; i++) {
            FadeSetPaletteExcluded(i, 0);
        }
        FadeStartOut(0, 16);
        func_080C75A4(0, 16);
        gUnk_02034D44 = 1;
    }
}

void func_080C7BCC(u16 a) {
    gUnk_02034D4C = a;

    if (a == 0xFFFD || a == 0xFFFE) {
        a = 0x45;
    }
    CreateCardMessageTask(&gUnk_02034D30, 0, a);
}

u16 func_080C7BF8(u8 kind, u8 count, s32 x, s32 y, s32 z) {
    PoohPrizeArgs args;
    u16 made;
    s32 i;
    s32 j;

    args.x = x;
    args.y = y;
    args.z = z;
    args.unk_14 = kind;
    made = 0;
    j = 0;

    for (i = 0; i < count; i++) {
        for (; j < 12; j++) {
            if (!IsTaskActive(gUnk_02034D50[j])) {
                gUnk_02034D50[j] = TaskCreate(&gUnk_02034D18, &gTaskDescPooPrize, &args);
                made++;
                break;
            }
        }
    }
    return made;
}

u16 func_080C7C80(void) {
    u16 n;
    s32 i;

    n = 0;

    for (i = 0; i < 12; i++) {
        if (IsTaskActive(gUnk_02034D50[i])) {
            n++;
        }
    }
    return n;
}

void func_080C7CB0(u8 a) {
    gUnk_02034D98 = a;
}

u8 func_080C7CBC(void) {
    return gUnk_02034D98;
}

void func_080C7CC8(PoohWork* w) {
    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 1:
        w->unk_A8 = 4;
        w->unk_24 = 0;
        break;
    case 2:
        w->unk_A8 = 3;
        w->unk_24 = 0;
        break;
    case 3:
        w->unk_A8 = 2;
        w->unk_24 = 0;
        break;
    case 4:
        w->unk_A8 = 1;
        w->unk_24 = 0;
        break;
    case 5:
        w->unk_A8 = 2;
        w->unk_24 = 1;
        break;
    case 6:
        w->unk_A8 = 3;
        w->unk_24 = 1;
        break;
    case 7:
        w->unk_A8 = 4;
        w->unk_24 = 1;
        break;
    case 0:
    default:
        w->unk_A8 = 0;
        w->unk_24 = 0;
        break;
    }
}

void func_080C7D60(PoohWork* w) {
    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 1:
        w->unk_A8 = 4;
        w->unk_24 = 1;
        break;
    case 2:
        w->unk_A8 = 3;
        w->unk_24 = 1;
        break;
    case 3:
        w->unk_A8 = 2;
        w->unk_24 = 1;
        break;
    case 4:
        w->unk_A8 = 1;
        w->unk_24 = 0;
        break;
    case 5:
        w->unk_A8 = 2;
        w->unk_24 = 0;
        break;
    case 6:
        w->unk_A8 = 3;
        w->unk_24 = 0;
        break;
    case 7:
        w->unk_A8 = 4;
        w->unk_24 = 0;
        break;
    case 0:
    default:
        w->unk_A8 = 0;
        w->unk_24 = 0;
        break;
    }
}

void func_080C7DF8(PoohWork* w) {
    w->unk_24 = 0;

    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 0:
        w->unk_A8 = 0;
        break;
    case 1:
        w->unk_A8 = 4;
        break;
    case 2:
        w->unk_A8 = 3;
        break;
    case 3:
        w->unk_A8 = 2;
        break;
    case 4:
        w->unk_A8 = 1;
        break;
    case 5:
        w->unk_A8 = 5;
        break;
    case 6:
        w->unk_A8 = 6;
        break;
    case 7:
        w->unk_A8 = 7;
        break;
    default:
        w->unk_A8 = 0;
        break;
    }
}

void func_080C7E98(PoohWork* w) {
    switch (((w->unk_38 + 16) & 0xFF) >> 5) {
    case 0:
    case 1:
        w->unk_A8 = 0;
        w->unk_24 = 1;
        break;
    case 2:
        w->unk_A8 = 1;
        w->unk_24 = 1;
        break;
    case 3:
        w->unk_A8 = 1;
        w->unk_24 = 1;
        break;
    case 4:
    case 5:
    case 6:
        w->unk_A8 = 1;
        w->unk_24 = 0;
        break;
    case 7:
    default:
        w->unk_A8 = 0;
        w->unk_24 = 0;
        break;
    }
}

void func_080C7F18(PoohWork* w) {
    if (w->unk_38 <= 99) {
        w->unk_A8 = 3;
        w->unk_24 = 1;
    } else if (w->unk_38 <= 156) {
        w->unk_A8 = 1;
        w->unk_24 = 0;
    } else {
        w->unk_A8 = 3;
        w->unk_24 = 0;
    }
}

u8 func_080C7F4C(u8 a) {
    switch (((a + 16) & 0xFF) >> 5) {
    case 1:
    case 2:
    case 3:
        return 1;
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
        return 0;
    }
    return 0;
}

u8 func_080C7F94(PoohWork* w) {
    u8 tbl[8][8];
    u32 row;
    u32 col;

    memcpy(tbl, gUnk_096FC01C, sizeof(tbl));
    row = (u32)((w->unk_38 + 16) & 0xFF) >> 5;
    col = (u32)((w->unk_3A + 16) & 0xFF) >> 5;
    if ((s8)tbl[row][col] == 3) {
        return w->unk_3B;
    }
    return tbl[row][col] + 2;
}

void func_080C7FEC(PoohWork* w, u32 anim) {
    AnimDef* e;
    u16 flags;

    flags = 0;
    ColliderSetRadius(w->collider, gUnk_096FC010.unk_08);

    if (w->unk_26 == anim) {
        flags = 4;
    }
    w->unk_26 = anim;

    switch (anim) {
    case 3:
    case 4:
    case 7:
        flags |= 1;
        func_080C7DF8(w);
        e = &gUnk_09EF3D88[w->unk_A8];
        break;
    case 5:
    case 6:
        flags |= 1;
        func_080C7F18(w);
        e = &gUnk_09EF3FF8[w->unk_A8];
        break;
    case 16:
        func_080C7DF8(w);
        e = &gUnk_09EF3E08[w->unk_A8];
        break;
    case 17:
        func_080C7D60(w);
        e = &gUnk_09EF3CE8[w->unk_A8];
        break;
    case 18:
        func_080C7D60(w);
        e = &gUnk_09EF3D38[w->unk_A8];
        break;
    case 19:
        func_080C7E98(w);
        e = &gUnk_09EF3EC8[w->unk_A8];
        break;
    case 20:
        w->unk_FA = 1;
        func_080C7E98(w);
        e = &gUnk_09EF3EE8[w->unk_A8];
        break;
    case 21:
        w->unk_FA = 1;
        func_080C7E98(w);

        if (func_080D2D50(6) != 0 || w->unk_F6 != 0 || (w->unk_A8 == 5 && w->unk_24 == 0)) {
            e = &gUnk_09EF3EE8[w->unk_A8];
        } else {
            e = &gUnk_09EF3F08[w->unk_A8];
        }
        break;
    case 36:
        w->unk_24 = 0;
        e = &gUnk_09EF3E88;
        break;
    case 37:
        w->unk_24 = 0;
        e = &gUnk_09EF3E98;
        break;
    case 23:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F28;
        w->unk_FA = 1;
        break;
    case 32:
        w->unk_24 = 0;
        e = &gUnk_09EF3F88;
        w->unk_FA = 1;
        break;
    case 33:
        w->unk_24 = 0;
        e = &gUnk_09EF3FC8;
        break;
    case 34:
        w->unk_24 = 0;
        e = &gUnk_09EF3FD8;
        break;
    case 35:
        w->unk_24 = 0;
        e = &gUnk_09EF3FE8;
        break;
    case 24:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F38;
        w->unk_FA = 1;
        break;
    case 25:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F48;
        w->unk_FA = 1;
        break;
    case 26:
        ColliderSetRadius(w->collider, 14);
        flags |= 1;
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F58;
        w->unk_FA = 1;
        break;
    case 27:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F68;
        w->unk_FA = 1;
        break;
    case 28:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F78;
        w->unk_FA = 1;
        break;
    case 29:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3F98;
        break;
    case 30:
        flags |= 1;
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3FA8;
        break;
    case 31:
        w->unk_24 = func_080C7F4C(w->unk_38);
        e = &gUnk_09EF3FB8;
        break;
    case 38:
    case 39:
        flags |= 1;
        w->unk_24 = 0;
        e = &gUnk_09EF3EA8;
        break;
    case 22:
        flags |= 1;
        w->unk_24 = 0;
        e = &gUnk_09EF3EB8;
        break;
    case 0:
    case 1:
    case 2:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        flags |= 1;
        func_080C7CC8(w);
        w->unk_3B = func_080C7F94(w);
        e = &gUnk_09EF4048[w->unk_A8][func_080C7F94(w)];
        break;
    default:
        flags |= 1;
        func_080C7CC8(w);
        e = &gUnk_09EF3C98[w->unk_A8];
        break;
    }

    AnimChangeWithTables(&w->anim, e->animId, flags, e->anims, e->gfxTable);
    SetObjTileSource(w->tiles, e->tiles);
}

u8 func_080C83C4(u16 x, u16 y, u16 px, u16 py) {
    if (x - gUnk_096FC010.unk_08 < px && px < x + gUnk_096FC010.unk_08 &&
        y - gUnk_096FC010.unk_08 < py && py < y + gUnk_096FC010.unk_08) {
        return 1;
    }
    return 0;
}

s32 func_080C8404(PoohPos* a, PoohPos* b) {
    s32 dx;
    s32 dy;

    dx = a->x - b->x;
    if (dx < 0) {
        dx = b->x - a->x;
    }
    dy = a->y - b->y;
    if (dy < 0) {
        dy = b->y - a->y;
    }
    return dx + dy;
}

void func_080C8428(PoohWork* w, u32 b) {
    u8* pal;

    switch (b) {
    case 16:
        pal = gTrap0001Palette;
        break;
    case 36:
    case 37:
        pal = gTrap0002Palette;
        break;
    case 38:
    case 39:
        pal = gTrap0003Palette;
        break;
    default:
        pal = gPoohPalette;
        break;
    }

    if (w->palette->src != pal) {
        ReleaseObjPalette(w->palette);
        w->palette = LoadObjPalette(pal, 32);
    }
}
