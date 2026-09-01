#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "main.h"
#include "key.h"

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


u16 GetKeysHeld(void) {
    return gKeysHeld;
}

u16 GetKeysPressed(void) {
    return gKeysPressed;
}

INCLUDE_ASM("key/GetKeysRepeat.s");
INCLUDE_ASM("key/func_08001470.s");
INCLUDE_ASM("key/func_08001534.s");
INCLUDE_ASM("key/func_080015F8.s");
INCLUDE_ASM("key/UpdateKeyState.s");
