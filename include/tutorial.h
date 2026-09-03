#ifndef GUARD_TUTORIAL_H
#define GUARD_TUTORIAL_H

#include "types.h"
#include "game.h"

typedef struct TutorialWork {
    u16 unk_000;
    u16 unk_002;
    u32 unk_004;
    u32 unk_008;
    s16 unk_00C;
    s16 unk_00E;
    s16 unk_010;
    u16 unk_012;
    u16 unk_014;
    u8 unk_016[0x2];
    void* tiles;
    void* palette;
    u8 unk_020[0x10];
    u16 unk_030;
    u8 unk_032[0x6];
} TutorialWork;

void task_tutorial_0(TutorialWork* work, s32 arg1);
s32 task_tutorial_1(TutorialWork* work);
void task_tutorial_2(TutorialWork* work);
void task_tutorial_3(TutorialWork* work);
s16 func_0805E848(u16* widths, u16 count);
u16 func_0805E89C(u16* str);

void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgScroll(s32 a, s32 b, s32 c);
void* AllocObjTiles(s32 a, void* b);
void AnimInit(void* a, void* b, void* c);
void AnimStart(void* a, s32 b, s32 c);
void SeedRandom(s32 a);
void* AnimUpdate(void* a);

extern u32 gFrameCounter;
extern s16 gSineTable[];
extern u16 gBg0Cnt;
extern u8 gUnk_08B263D2[];
extern u8 gUnk_09EE15F0[];
extern u8 gUnk_09EE15C0[];

void func_0805DA64(u16 a);
void func_0805DA98(u16 a);
void func_0805DAB4(void);
void func_0805DACC(TutorialWork* work, u16 a, u32 b);
void func_0805DADC(TutorialWork* work, u16 a, u32 b);
void func_0805DAEC(void);
void func_0805DAF8(TutorialWork* work, s16 a, u32 b);
void func_0805DB04(TutorialWork* work, u16 a, u16 b, u16 c);
void func_0805DB28(TutorialWork* work);
u8 func_080128EC(void);
u8 func_080A42C8(void);
void func_0809B644(void* a, s32 b, s32 c, s32 d, s32 e);
void func_08076324(void);
u8 func_080763D0(void);
u8 func_0807B3E0(void);

#endif /* GUARD_TUTORIAL_H */
