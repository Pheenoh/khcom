#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "main.h"
#include "sprite.h"

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


INCLUDE_ASM("sprite/SpriteInit.s");
INCLUDE_ASM("sprite/SpriteFree.s");
INCLUDE_ASM("sprite/func_08001DB0.s");
INCLUDE_ASM("sprite/func_08001E64.s");
INCLUDE_ASM("sprite/func_08001EF8.s");
INCLUDE_ASM("sprite/func_08001F20.s");
INCLUDE_ASM("sprite/func_08001F5C.s");
INCLUDE_ASM("sprite/func_08001F98.s");
INCLUDE_ASM("sprite/func_08002060.s");
