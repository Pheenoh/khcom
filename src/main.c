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

vu16 gFrameSyncFlags;
u16 gVBlankEndVCount;
u32 gUnk_03006C04[3];
u32 gUnk_03006C10;
IntrFunc* gIntrTableSerial;
u32 gUnk_03006C18[2];
IntrFunc gIntrTable[14];
IntrFunc* gIntrTableVCount;
IntrFunc* gIntrTableVBlank;
IntrFunc* gIntrTableTimer3;
IntrFunc gHBlankCallback;
u32 gVBlankCounter;
IntrFunc gVCountCallback;
IntrFunc gVBlankCallback;
IntrFunc* gIntrTableHBlank;
u16 gSystemFlags;
u8 gUnk_03006C7A[6];
u8 gIntrHandler[0x800];
u32 gFrameCounter;
#ifdef VERSION_EU
u32 gUnkEu_03007484;
#endif
IntrFunc gVBlankHandlerOverride;

extern u8 sEwramHeapName[];
extern u8 sIwramHeapName[];

extern u8 gEwramHeapStart[];
extern u8 gIwramHeapStart[];
extern u8 IrqHandler[];

extern u32 gSioPlayerId;
extern u32 gSioStatus;
extern u16 gIntrCheck;


extern const IntrFunc gIntrTableTemplate[14];

void func_080C55DC(void);
void ModeInit(void);
void ModeUpdate(void);
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
    gVBlankEndVCount = 0;
    gFrameSyncFlags = 0;
    gVBlankHandlerOverride = 0;
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
    ModeInit();
}

#ifdef NON_MATCHING
void AgbMain(void) {
    s32 bit;

    gFrameCounter = 0;
    gVBlankCounter = 0;
    gSystemFlags = 0;
    gUnk_03006C10 = 0;
    gSioPlayerId = 0;
    gSioStatus = 0;
    InitSystem();
    EnableVBlankIntr();
    bit = 4;

    for (;;) {
        UpdateKeyState();

        if (gSystemFlags & 1) {
            func_080C55DC();

            if (gSioStatus & 0x100) {
                goto next;
            }
        }

        if ((gFrameSyncFlags & bit) == 0) {
            ModeUpdate();
            gFrameSyncFlags |= 4;
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
    if (gVBlankHandlerOverride != 0) {
        gVBlankHandlerOverride();
        return;
    }

    if (gFrameSyncFlags & 2) {
        gFrameSyncFlags |= 8;
        return;
    }
    gFrameSyncFlags |= 2;
    if (!(gFrameSyncFlags & 1)) {
        m4aSoundVSync();
    }
    gIntrCheck |= 1;

    if (gFrameSyncFlags & 4) {
        func_08001254();
    }
    func_080012A8();
    func_08116D28();
    gVBlankEndVCount = REG_VCOUNT;
    gFrameSyncFlags &= 0xFFFB;
    if (!(gFrameSyncFlags & 1)) {
        gFrameSyncFlags |= 1;
        m4aSoundMain();
        gFrameSyncFlags &= 0xFFFE;
    }
    gFrameSyncFlags &= 0xFFFD;
    gVBlankCounter++;
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
    if (gFrameSyncFlags & 2) {
        gFrameSyncFlags |= 8;
        return;
    }
    gFrameSyncFlags |= 2;
    func_08007318();

    if (!(gFrameSyncFlags & 1)) {
        m4aSoundVSync();
    }
    gIntrCheck |= 1;

    if (gFrameSyncFlags & 4) {
        func_08001254();
    }
    func_080012A8();
    gVBlankEndVCount = REG_VCOUNT;
    gFrameSyncFlags &= 0xFFFB;
    if (!(gFrameSyncFlags & 1)) {
        gFrameSyncFlags |= 1;
        m4aSoundMain();
        gFrameSyncFlags &= 0xFFFE;
    }
    gFrameSyncFlags &= 0xFFFD;
    gVBlankCounter++;
}

void func_08000714(void) {
    if (gFrameSyncFlags & 2) {
        gFrameSyncFlags |= 8;
        return;
    }
    gFrameSyncFlags |= 2;
    REG_IME = 0;
    func_08116EF0();
    REG_IME = 1;
    gIntrCheck |= 1;

    if (gFrameSyncFlags & 4) {
        func_08001254();
    }
    func_080012A8();
    func_08116D28();
    gVBlankEndVCount = REG_VCOUNT;
    gFrameSyncFlags &= 0xFFFB;
    gFrameSyncFlags &= 0xFFFD;
    gVBlankCounter++;
}
