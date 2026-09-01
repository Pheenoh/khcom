#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "main.h"

extern u8 gUnk_081213DC[];
extern u8 gUnk_081213E8[];

extern u32 gFrameCounter;
extern u32 gUnk_03006C68;
extern u16 gUnk_03006C78;
extern u32 gUnk_03006C10;
extern u32 gUnk_02039828;
extern u32 gUnk_02039820;
extern u16 gUnk_03006C00;

void InitSystem(void);
void func_080C55DC(void);
void func_08001100(void);


INCLUDE_ASM("main/func_08000240.s");
INCLUDE_ASM("main/func_08000248.s");
INCLUDE_ASM("main/func_08000250.s");
INCLUDE_ASM("main/func_08000258.s");
INCLUDE_ASM("main/EnableVBlankIntr.s");
INCLUDE_ASM("main/DisableVBlankIntr.s");
INCLUDE_ASM("main/EnableHBlankIntr.s");
INCLUDE_ASM("main/DisableHBlankIntr.s");
INCLUDE_ASM("main/InitSystem.s");
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
INCLUDE_ASM("main/VBlankIntr.s");
INCLUDE_ASM("main/HBlankIntrDummy.s");
INCLUDE_ASM("main/VCountIntrDummy.s");
INCLUDE_ASM("main/SerialIntrDummy.s");
INCLUDE_ASM("main/InitIntrTable.s");
INCLUDE_ASM("main/ApplyIntrCallbacks.s");
INCLUDE_ASM("main/VBlankIntrSio.s");
INCLUDE_ASM("main/func_08000714.s");
