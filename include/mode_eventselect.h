#ifndef GUARD_MODE_EVENTSELECT_H
#define GUARD_MODE_EVENTSELECT_H

#include "types.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "m4a.h"
#include "evt_types.h"
#include "game.h"
#include "card.h"
#include "mode.h"

typedef struct UnkStruct_02039DD0 {
    s16 unk_00;
    u16 unk_02;
} UnkStruct_02039DD0;

extern UnkStruct_02039DD0* gUnk_02039DD0;
extern UnkStruct_02039DC8* gUnk_02039DC8;
extern s16 gUnk_02034A94;
extern u8 gUnk_02034A96;
extern u32 gUnk_02034A9C;
extern u32 gUnk_02034AA0;
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_0905EEE6[];
extern u8 gUnk_09611AB8[];
extern const char gUnk_08F70990[];
extern const char gUnk_09033ED8[];
extern const char gUnk_09033EDC[];
extern const char gUnk_09033EE0[];
extern const char gUnk_09033EF8[];
extern const char gUnk_09033F10[];
extern s16 gUnk_09033D50[];
extern s16 gUnk_09033E76[];
extern const char* gUnk_09EE42C8[];
extern Mode gUnk_09ECEB64;

void func_080010CC(Mode* mode, s32 arg);
u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
void func_08004DB0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void func_0805FA60(s32 a, const char* b, s32 c, s32 d);
void func_0805FA8C(s32 a, s32 b, s32 c);
void func_0805FC04(u8 x, u8 y, u8 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_0806180C(u16 a);
s16 func_08075064(u8 a);
void func_08085C3C(void);
void func_08085FB0(void);
void func_08093BB4(void);
void* func_080668F0(void);
void* func_08066904(void);
void func_08066918(void* a, void* b);
u8 _080669DC(s32 a, void* b);
void func_08066DC0(s32 a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g);
void func_080062F4(u16 a, s32 b);
void TaskPoolInit(TaskPool* pool, s32 count);
void func_0807B668(UnkStruct_02039DD4* p);
void func_0807E23C(void);
void func_0807E248(void);

void mode_eventselect_0(void);
void mode_eventselect_1(void);
void mode_eventselect_2(void);
void func_08076110(u16 song, s16 x, s16 y);
void func_08076214(u8* work);
s32 func_0807622C(u8* work);
void func_08076250(u8* work);
void func_08076274(s32* p);
void func_08076284(void);
void func_08076290(void);
void func_0807629C(void);
u8 func_080762A8(void);
void func_080762B8(void);
void func_080762C4(void);
void func_080762D0(void);
void func_080762DC(void);
void func_080762E8(void);
void func_080762F4(void);
void func_08076300(void);
void func_0807630C(void);
void func_08076318(void);
void func_08076324(void);
void func_08076330(void);
void func_0807633C(void);
void func_08076348(void);
void func_08076354(void);
void func_08076360(void);
void func_08076374(void);
void func_08076388(void);
void func_08076394(void);
void func_080763A0(void);
void func_080763AC(void);
void func_080763B8(void);
void func_080763C4(void);
u8 func_080763D0(void);
void func_080763F0(void);
void func_08076438(void);
u8 func_0807643C(void);
void func_08076458(void);

#endif
