#ifndef GUARD_PALLET_H
#define GUARD_PALLET_H

#include "types.h"

#define REG_VCOUNT (*(vu16*)0x04000006)
#define REG_BGHOFS(n) (*(vu16*)(0x04000010 + (n) * 4))

typedef struct PaletteBuffer {
    u16 colors[512];
    u16 banks[32];
} PaletteBuffer;

typedef struct PaletteWave {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
} PaletteWave;

extern PaletteBuffer* gUnk_0300756C;
extern s16 gUnk_03007570;
extern s16 gUnk_03007572;
extern PaletteWave gUnk_02039B70[];
extern s16 gSineTable[];
extern u32 gFrameCounter;
extern u8 gUnk_08121714[];
extern s32 gUnk_08121694[];

u16* func_080078FC(u16* src, u16* dst, u16 size, u16 amount);
u16* func_08007A10(u16* src, u16* dst, u16 size, u16 amount);
u16* func_08007B08(u16* src, u16* dst, u16 size, u16 amount);
u16* func_08007C50(u16* src, u16* dst, u16 size, u16 amount);
u16* func_08007D74(void* src, u16* dst, u16 size);
u16* func_08007DD8(u8 bank);
void func_08007DEC(void);
u16* func_08007E00(void* src, u16* dst, u16 size);
s16 func_08007E50(void);
void func_08007E5C(s16 a);
void func_08007E68(s32 a);
void func_08007E7C(void);
void func_08007E90(void);
void func_08007ECC(void);
void func_08007EE0(void);
void func_08007F20(u16 bank, u8 a);
u16* func_08007F3C(u16* src, u16 amount);
u16* func_0800805C(u16* src, u16 amount);
void func_080081B8(s32 a);
void func_080081E4(s32 a, u8 b, u8 c);
void func_080081F4(s32 a);
void func_08008204(s32 a);
void func_08008214(s32 a);
void func_08008280(s32 a);
void func_0800829C(void);
void func_08008318(void);

#endif /* GUARD_PALLET_H */
