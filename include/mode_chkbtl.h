#ifndef GUARD_MODE_CHKBTL_H
#define GUARD_MODE_CHKBTL_H

#include "types.h"
#include "main.h"

typedef struct ChkBtlWork {
    s8 unk_00;
    s8 unk_01;
    s16 unk_02;
    s8 unk_04;
    u8 unk_05;
    s16 unk_06;
} ChkBtlWork;

typedef struct ChkBtlEntry {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    TaskDesc* unk_0C;
    const char* unk_10;
} ChkBtlEntry;

typedef struct ChkBtlActor {
    u8 unk_00[0x2C];
    TaskPool unk_2C;
} ChkBtlActor;

typedef struct ChkBtlPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} ChkBtlPos;

typedef struct ChkBtlWorld {
    u8 unk_00;
    u8 unk_01[0x03];
    const char* unk_04;
} ChkBtlWorld;

typedef struct ChkBtlSetup {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F[0x23];
    u16 unk_32;
    u8 unk_34[0xC4];
    u16 unk_F8;
    u16 unk_FA;
    u8 unk_FC[0x80];
    u16 unk_17C;
} ChkBtlSetup;

typedef struct Mode {
    const char* name;
    void (*unk_04)(void);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

void func_080010CC(Mode* mode, s32 arg);
u16 GetKeysHeld(void);
u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
void func_08004DB0(void);
void func_08004FC8(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void func_08006120(s32 a, s32 b);
void SeedRandom(u32 a);
void func_0805FA60(s32 a, const char* b, s32 c, s32 d);
void func_0805FA8C(s32 a, s32 b, s32 c);
void func_0805FC04(u8 x, u8 y, u8 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080609A0(void);
void func_080605A4(s32 a);
void func_08085CB0(void);
void _08085D04(u8 a);
void func_08085FB0(void);

void func_0800AB8C(void);
void func_0800ABD8(void);
void mode_chkbtl_0(void);
void mode_chkbtl_1(void);
void mode_chkbtl_2(void);

extern ChkBtlActor* gUnk_02039B84;
extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern ChkBtlSetup gUnk_02039BB0;
extern u32 gUnk_03006C10;
extern u32 gFrameCounter;
extern ChkBtlEntry gUnk_08126630[];
extern ChkBtlWorld gUnk_08128234[];
extern ChkBtlWork* gUnk_09ECEB50;
extern Mode gUnk_09ECEB40;
extern Mode gUnk_09ECEB64;
extern Mode gUnk_09EE2704;
extern const char gUnk_08128304[];
extern const char gUnk_08128324[];
extern const char gUnk_0812834C[];
extern const char gUnk_08128358[];
extern const char gUnk_08128364[];
extern const char gUnk_08128370[];
extern const char gUnk_0812837C[];
extern const char gUnk_08128384[];
extern const char gUnk_08128388[];
extern const char gUnk_0812838C[];

#endif /* GUARD_MODE_CHKBTL_H */
