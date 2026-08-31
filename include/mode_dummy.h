#ifndef GUARD_MODE_DUMMY_H
#define GUARD_MODE_DUMMY_H

#include "types.h"

typedef struct Mode {
    const char* name;
    void (*unk_04)(s32 arg);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C[0x26];
    s16 unk_032;
    u8 unk_034[0xC4];
    s16 unk_0F8;
    s16 unk_0FA;
    s16 unk_0FC;
    s16 unk_0FE;
    s32 unk_100;
    s32 unk_104;
    u8 unk_108;
    u8 unk_109[0x6B];
    s32 unk_174;
    u8 unk_178[0x08];
    u16 unk_180;
} UnkStruct_02039BB0;

typedef struct DummyEntry {
    const char* name;
    const char* desc;
    u16 unk_08;
} DummyEntry;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern u16 gUnk_020348BC;
extern u32 gUnk_03007480;
extern DummyEntry gUnk_08130A4C[];
extern const char gUnk_08130BC8[];
extern u8 gUnk_08128304[];
extern u8 gUnk_08C6B0C4[];
extern u8 gUnk_08F683C4[];
extern u8 gUnk_08EEE384[];
extern Mode gUnk_09EDE4D0;
extern Mode gUnk_09EF8F9C;
extern Mode gUnk_09EF4EC0;

void func_08001248(void (*fn)(void));
u16 func_08001390(void);
void func_080010CC(Mode* mode, s32 arg);
void func_080010E0(Mode* mode, s32 arg);
void func_08004DB0(void);
void func_08004FC8(s32 a);
void func_08005074(s32 a, s32 b, s32 c, s32 d);
void func_080050B8(s32 a, void* b, u16 c);
void func_080050DC(s32 a, void* b, u16 c);
void func_0800510C(s32 a, void* b, u16 c);
void func_080054EC(s32 a, u16 b, u16 c);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_0801CC80(void);
void func_0805FA60(s32 a, void* b, s32 c, s32 d);
void func_0805FA8C(s32 a, u16 b, u16 c);
void func_0805FCB0(s32 a, s32 b, s32 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_080609A0(void);
void func_0806180C(u16 a);
void func_080DF380(void);
void func_080E04EC(void);

void mode_dummy_0(u32 arg);
void func_0800C064(void);
void mode_dummy_1(void);
void mode_dummy_2(void);

#endif /* GUARD_MODE_DUMMY_H */
