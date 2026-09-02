#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "m4a.h"
#include "pallet.h"
#include "sprite.h"
#include "sroll.h"
#include "util.h"
#include "sio.h"
#include "engine.h"
#include "main.h"

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_VCOUNT (*(vu16*)0x04000006)
#define REG_IE (*(vu16*)0x04000200)
#define REG_IF (*(vu16*)0x04000202)
#define REG_WAITCNT (*(vu16*)0x04000204)
#define REG_IME (*(vu16*)0x04000208)
#define INTR_VECTOR (*(void**)0x03007FFC)

extern u8 sEwramHeapName[];
extern u8 sIwramHeapName[];

extern u8 gEwramHeapStart[];
extern u8 gIwramHeapStart[];
extern u8 gIntrHandler[];
extern u8 IrqHandler[];

extern u32 gFrameCounter;
extern u32 gUnk_03006C68;
extern u16 gUnk_03006C78;
extern u32 gUnk_03006C10;
extern u32 gUnk_02039828;
extern u32 gUnk_02039820;
extern vu16 gUnk_03006C00;
extern u16 gUnk_03006C02;
extern u16 gUnk_03007FF8;
extern IntrFunc gUnk_03007484;

extern IntrFunc* gIntrTableSerial;
extern IntrFunc* gIntrTableVCount;
extern IntrFunc* gIntrTableVBlank;
extern IntrFunc* gIntrTableTimer3;
extern IntrFunc gHBlankCallback;
extern IntrFunc gVCountCallback;
extern IntrFunc gVBlankCallback;
extern IntrFunc* gIntrTableHBlank;

extern IntrFunc gIntrTable[14];
extern const IntrFunc gIntrTableTemplate[14];

void func_080C55DC(void);
void func_08001010(void);
void func_08001100(void);
void func_08001254(void);
void func_080012A8(void);
void ResetKeyState(void);
void SaveInitSram(void);

void* GetEwramHeapStart(void) {
    return gEwramHeapStart;
}

u32 GetEwramHeapSize(void) {
    return 0x34000;
}

void* GetIwramHeapStart(void) {
    return gIwramHeapStart;
}

u32 GetIwramHeapSize(void) {
    return 0x6800;
}

void EnableVBlankIntr(void) {
    REG_IME = 0;
    REG_IE |= 1;
    REG_DISPSTAT |= 8;
    m4aSoundVSyncOn();
    REG_IME = 1;
}

void DisableVBlankIntr(void) {
    REG_IME = 0;
    REG_IE &= 0xFFFE;
    REG_DISPSTAT &= 0xFFF7;
    m4aSoundVSyncOff();
    REG_IME = 1;
}

void EnableHBlankIntr(void) {
    REG_IME = 0;
    REG_IE |= 2;
    REG_DISPSTAT |= 0x10;
    REG_IME = 1;
}

void DisableHBlankIntr(void) {
    REG_IME = 0;
    REG_IE &= 0xFFFD;
    REG_DISPSTAT &= 0xFFEF;
    REG_IME = 1;
}

void InitSystem(void) {
    vu32* dma;
    u32 zero;

    RegisterRamReset(0xFF);
    REG_WAITCNT = 0x45B6;
    zero = 0;
    dma = (vu32*)0x040000D4;
    dma[0] = (vu32)&zero;
    dma[1] = 0x02000000;
    dma[2] = 0x85010000;
    dma[2];
    zero = 0;
    dma[0] = (vu32)&zero;
    dma[1] = 0x03000000;
    dma[2] = 0x85001F80;
    dma[2];
    gUnk_03006C02 = 0;
    gUnk_03006C00 = 0;
    gUnk_03007484 = 0;
    REG_IME = 0;
    dma[0] = (vu32)IrqHandler;
    dma[1] = (vu32)gIntrHandler;
    dma[2] = 0x84000200;
    dma[2];
    INTR_VECTOR = gIntrHandler;
    REG_IE = 0x2000;
    REG_IF = 0x2000;
    REG_IME = 1;
    InitIntrTable();
    m4aSoundInit();
    m4aSoundVSyncOff();
    IwramHeapInit(GetIwramHeapStart(), GetIwramHeapSize());
    EwramHeapInit(GetEwramHeapStart(), GetEwramHeapSize());
    VTransInit();
    SpriteInit();
    BgInit();
    FadeInit();
    PalletInit();
    SioKeyInit();
    ResetPaletteEffect();
    ResetKeyState();
    SeedRandom(0x12D687);
    InitDisplayRegs();
    SaveInitSram();
    func_08116CEC();
    func_08001010();
}

#ifdef NON_MATCHING
void AgbMain(void) {
    s32 bit;

    gFrameCounter = 0;
    gUnk_03006C68 = 0;
    gUnk_03006C78 = 0;
    gUnk_03006C10 = 0;
    gUnk_02039828 = 0;
    gUnk_02039820 = 0;
    InitSystem();
    EnableVBlankIntr();
    bit = 4;
    for (;;) {
        UpdateKeyState();
        if (gUnk_03006C78 & 1) {
            func_080C55DC();
            if (gUnk_02039820 & 0x100) {
                goto next;
            }
        }

        if ((gUnk_03006C00 & bit) == 0) {
            func_08001100();
            gUnk_03006C00 |= 4;
        }
    next:
        ApplyIntrCallbacks();
        VBlankIntrWait();
        gFrameCounter++;
    }
}
#else
INCLUDE_ASM("main/AgbMain.s");
#endif

void VBlankIntr(void) {
    if (gUnk_03007484 != 0) {
        gUnk_03007484();
        return;
    }

    if (gUnk_03006C00 & 2) {
        gUnk_03006C00 |= 8;
        return;
    }
    gUnk_03006C00 |= 2;
    if (!(gUnk_03006C00 & 1)) {
        m4aSoundVSync();
    }
    gUnk_03007FF8 |= 1;
    if (gUnk_03006C00 & 4) {
        func_08001254();
    }
    func_080012A8();
    func_08116D28();
    gUnk_03006C02 = REG_VCOUNT;
    gUnk_03006C00 &= 0xFFFB;
    if (!(gUnk_03006C00 & 1)) {
        gUnk_03006C00 |= 1;
        m4aSoundMain();
        gUnk_03006C00 &= 0xFFFE;
    }
    gUnk_03006C00 &= 0xFFFD;
    gUnk_03006C68++;
}

void HBlankIntrDummy(void) {
}

void VCountIntrDummy(void) {
}

void SerialIntrDummy(void) {
}

#ifdef NON_MATCHING
void InitIntrTable(void) {
    s32 i;

    for (i = 0; i < 14; i++) {
        gIntrTable[i] = gIntrTableTemplate[i];
    }
    gIntrTableVBlank = &gIntrTable[1];
    gIntrTableVCount = &gIntrTable[3];
    gIntrTableHBlank = &gIntrTable[2];
    gIntrTableSerial = &gIntrTable[0];
    gIntrTableTimer3 = &gIntrTable[7];
    ResetVBlankCallback();
    ResetVCountCallback();
    ResetHBlankCallback();
    ResetSerialCallback();
    ResetTimer3Callback();
}
#else
INCLUDE_ASM("main/InitIntrTable.s");
#endif

void ApplyIntrCallbacks(void) {
    *gIntrTableVBlank = gVBlankCallback;
    *gIntrTableVCount = gVCountCallback;
    *gIntrTableHBlank = gHBlankCallback;
}

void VBlankIntrSio(void) {
    if (gUnk_03006C00 & 2) {
        gUnk_03006C00 |= 8;
        return;
    }
    gUnk_03006C00 |= 2;
    func_08007318();
    if (!(gUnk_03006C00 & 1)) {
        m4aSoundVSync();
    }
    gUnk_03007FF8 |= 1;
    if (gUnk_03006C00 & 4) {
        func_08001254();
    }
    func_080012A8();
    gUnk_03006C02 = REG_VCOUNT;
    gUnk_03006C00 &= 0xFFFB;
    if (!(gUnk_03006C00 & 1)) {
        gUnk_03006C00 |= 1;
        m4aSoundMain();
        gUnk_03006C00 &= 0xFFFE;
    }
    gUnk_03006C00 &= 0xFFFD;
    gUnk_03006C68++;
}

void func_08000714(void) {
    if (gUnk_03006C00 & 2) {
        gUnk_03006C00 |= 8;
        return;
    }
    gUnk_03006C00 |= 2;
    REG_IME = 0;
    func_08116EF0();
    REG_IME = 1;
    gUnk_03007FF8 |= 1;
    if (gUnk_03006C00 & 4) {
        func_08001254();
    }
    func_080012A8();
    func_08116D28();
    gUnk_03006C02 = REG_VCOUNT;
    gUnk_03006C00 &= 0xFFFB;
    gUnk_03006C00 &= 0xFFFD;
    gUnk_03006C68++;
}
