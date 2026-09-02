#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "types.h"

void func_081025AC(void);
void func_081025D4(void* a);
void func_08102610(void* a);
void func_0810264C(u16 a, u16 b, u16 c);
void func_08102688(u16 a, u16 b, u16 c);
s32 func_081026C4(u16 a, u16 b, u16 c);
void func_08102704(u16 a);
void func_08102728(u16 a);
s32 func_0810274C(u16 a);
void func_08102774(void);
s32 func_08102A94(void);
u16 func_08103F3C(void);
void func_08103CD8(s16 a);

u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
u16 GetRandom(void);
void* GetBgScreenBase(s32 bg);
void func_0800448C(void* src, void* dst, u8 x, u8 y, u8 w, u8 h, u8 sw, u8 sh);

extern u8 gUnk_0203C590[];
extern u16 gUnk_02035B68[];
extern u16 gUnk_02035BA8[];
extern s16 gUnk_02035B08[];
extern u16 gUnk_09993334[];
extern u8 gUnk_09A3ABDC[];

#endif /* GUARD_MODE_MS_H */
