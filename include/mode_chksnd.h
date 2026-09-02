#ifndef GUARD_MODE_CHKSND_H
#define GUARD_MODE_CHKSND_H

#include "types.h"
#include "main.h"
#include "mode.h"
typedef struct ChkSndEntry {
    const char* name;
    u16 unk_04;
} ChkSndEntry;

extern TaskPool gUnk_020348A0;
extern s16 gUnk_020348B4;
extern ChkSndEntry gUnk_09ED8644[];
extern Mode gUnk_09ECEB64;
extern TaskDesc gUnk_09EE9190;
extern const char gUnk_081309B0[];
extern const char gUnk_081309D0[];

void func_080010CC(Mode* mode, s32 b);
u16 GetKeysRepeat(void);
void func_08004DB0(void);
void func_0809D2B0(u8 x, u8 y, u8 c, const char* s);
void func_0809D458(u16 x, u16 y, u16 c, s32 v);
void m4aSongNumStart(u16 id);
void m4aMPlayAllStop(void);

void mode_chksnd_0(void);
void mode_chksnd_1(void);
void mode_chksnd_2(void);

#endif /* GUARD_MODE_CHKSND_H */
