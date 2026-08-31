#ifndef GUARD_MODE_CHKEFF_H
#define GUARD_MODE_CHKEFF_H

#include "types.h"

typedef struct ChkEffWork {
    u8 unk_00[0x14];
    s16 unk_14;
    u8 unk_16;
    u8 unk_17;
    u16 unk_18;
    u16 unk_1A;
    u8 unk_1C;
    u8 unk_1D[0x03];
    s32 unk_20;
    u16 unk_24;
    u16 unk_26;
} ChkEffWork;

void* EwramAlloc(u32 size);
void EwramFree(void* p);
void func_080010CC(void* a, s32 b);
void TaskCreate(void* pool, void* desc, void* arg);
void TaskPoolInit(void* pool, s32 count);
void TaskPoolUpdate(void* pool);
void TaskPoolDraw(void* pool);
void TaskPoolDestroy(void* pool);
u16 GetKeysHeld(void);
u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
void func_08004E64(void);
void SetupBg(s32 a, s32 b, s32 c, s32 d);
void LoadBgTiles(s32 a, void* b, u16 c);
void LoadBgPalette(s32 a, void* b, u16 c);
void LoadBgMap(s32 a, void* b, u16 c);
void SetBgScroll(s32 a, u16 b, u16 c);
void SetBgPriority(s32 a, s32 b);
void func_080057A0(s32 a, s32 b, s32 c);
void func_08005810(u16 a, u16 b);
void func_080062F4(s32 a, s32 b);
void func_080065FC(s32 a, s32 b, s32 c);
void func_0800675C(u8 a, s32 b, s32 c);
void func_08006778(void* a, s32 x, s32 y);
void func_08006954(void);
u8 func_08006B74(void);
void func_08006B80(u16* a, u16* b);
void func_0809D2B0(s32 a, s32 b, s32 c, const char* s);
void func_0809D458(s32 a, s32 b, s32 c, s32 v);

void mode_chkeff_0(void);
void mode_chkeff_1(void);
void mode_chkeff_2(void);

extern ChkEffWork* gUnk_020348B8;
extern u32 gFrameCounter;
extern u8 gUnk_08C6B0C4[];
extern u8 gUnk_08EEE384[];
extern u8 gUnk_08F683C4[];
extern u8 gUnk_09ECEB64[];
extern void* gUnk_09ED9A1C[];
extern u8 gUnk_09EE9190[];
extern const char gUnk_081309E0[];
extern const char gUnk_081309E8[];
extern const char gUnk_081309F0[];
extern const char gUnk_08130A18[];
extern const char gUnk_08130A20[];
extern const char gUnk_08130A28[];
extern const char gUnk_08130A30[];
extern const char gUnk_08130A34[];
extern const char gUnk_08130A38[];

#endif /* GUARD_MODE_CHKEFF_H */
