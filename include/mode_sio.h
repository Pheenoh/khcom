#ifndef GUARD_MODE_SIO_H
#define GUARD_MODE_SIO_H

#include "types.h"

typedef struct Mode {
    const char* name;
    void (*unk_04)(s32 arg);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

typedef struct TaskDesc {
    const char* name;
    void (*unk_04)(void* work, void* arg);
    void* unk_08;
    void (*unk_0C)(void* work);
    void* unk_10;
    s32 unk_14;
} TaskDesc;

typedef struct TextSlot {
    void* unk_00;
    u8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07;
} TextSlot;

typedef struct SioAnimDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
} SioAnimDef;

typedef struct SioBtlConnectWork {
    u16 unk_00;
    s16 unk_02;
    s8 unk_04;
    u8 unk_05;
    u8 unk_06[2];
    TextSlot unk_08[0x5A];
    void* unk_2D8;
} SioBtlConnectWork;

extern SioBtlConnectWork* gUnk_02034B3C;

extern u8 gUnk_02039B60;
extern u16 gUnk_0203A9EC;
extern u16 gUnk_0203A9F0;
extern u8 gUnk_0203AA00;
extern u8 gUnk_0203AA30[][20];
extern u8 gUnk_0203AA58[];
extern u8 gUnk_0203AA60[][20];
extern u8 gUnk_0203AA88;
extern u8 gUnk_0203AA8C;
extern u8 gUnk_0203AA90;
extern u8 gUnk_0203AAA0[];
extern u8 gUnk_0203AAE0[][20];
extern vu16 gUnk_03006C78;

extern u8 gUnk_08159E4A[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_096ACA44[];
extern u8 gUnk_096AD604[];
extern u8 gUnk_096F5C64[];
extern u8 gUnk_096F6464[];
extern u8 gUnk_096FBA04[];
extern u8 gUnk_096FBAA4[];
extern Mode gUnk_09EF12F8;
extern Mode gUnk_09EF14DC;

void* EwramAlloc(u32 size);
void EwramFree(void* p);
void func_080010CC(Mode* mode, s32 arg);
void func_08002A10(void* a, void* b);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjPalette(void* p);
void func_08004DB0(void);
void EnableBg(s32 bg);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_08005974(void* a, u8 b, u16 c, void* d, void* e);
void func_08006120(s32 a, u16 b);
void func_08006E60(void);
void func_08065ACC(TextSlot* p, s32 n);
void func_08065AE0(TextSlot* p, s32 n);
u8 func_08065B6C(void* a, TextSlot* b);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
u8 func_080C54B4(void);
void func_080C5A3C(void (*a)(void), void (*b)(void), u8 c);
void func_080C5D00(void);
s32 func_080C5D50(void);
s32 func_080C5D80(void);
void func_080C5DC0(s32 (*a)(void), s32 (*b)(void));
s32 func_080C6008(void);
s32 func_080C60D8(void);
void func_080C61D4(void);
void m4aSongNumStart(u16 id);

void mode_sio_btl_connect_0(s32 arg);
void mode_sio_btl_connect_1(void);
void mode_sio_btl_connect_2(void);
void func_080AEE50(void);
void func_080AEE6C(void);
void func_080AEE84(void);
void func_080AEED8(u16 a, s16 b, u16 c);

#endif /* GUARD_MODE_SIO_H */
