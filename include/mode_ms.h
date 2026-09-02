#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "types.h"
#include "taskpool.h"
#include "fld_types.h"

typedef struct UnkStruct_020358C8 {
    FldRes* unk_00;
    void* unk_04;
    u8 unk_08[0x4];
    FldRes* unk_0C;
    void* unk_10;
    u8 unk_14[0x34];
} UnkStruct_020358C8;

typedef struct UnkStruct_099931E4_1C {
    u16* unk_00;
    s16 unk_04;
    s16 unk_06;
} UnkStruct_099931E4_1C;

typedef struct UnkStruct_099931E4 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    void* unk_0C;
    u16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    UnkStruct_099931E4_1C unk_1C[4];
} UnkStruct_099931E4;

void func_081025AC(void);
void func_081025D4(void* a);
void func_08102610(void* a);
void func_0810264C(u16 a, u16 b, u16 c);
void func_08102688(u16 a, u16 b, u16 c);
u8 func_081026C4(u16 a, u16 b, u16 c);
void func_08102704(u16 a);
void func_08102728(u16 a);
s32 func_0810274C(u16 a);
void func_08102774(void);
s32 func_081027B4(s16 a);
s32 func_08102A94(void);
u16 func_08103F3C(void);
void func_08102984(s16 a);
void func_08103CD8(s16 a);
void mode_ms_top_2(void);
void func_08102DC8(void);
void func_081041B4(void);
void mode_ms_shop_2(void);
void func_08103D54(s16 a);
void func_08103D7C(void);
void func_08103DE8(void);

u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
u16 GetRandom(void);
void* GetBgScreenBase(s32 bg);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void TaskPoolDestroy(TaskPool* pool);
void m4aSongNumStart(u16 n);
void DisableBg(s32 bg);
void func_08006238(s32 a, s32 b, s32 c);
u8 func_08101538(u32 a);
void func_08102AB4(s16 x, s16 y);
void func_08103F94(s16 a, s16 b);
void func_080062F4(u16 a, s32 b);
void func_08065AE0(void* a, s32 b);
void EwramFree(void* p);
void* GetBgCharBase(s32 bg);
void func_08101588(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);
void func_08006184(s32 a, u16 b);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_0800448C(void* src, void* dst, u8 x, u8 y, u8 w, u8 h, u8 sw, u8 sh);

extern u8 gUnk_0203C590[];
extern u16 gUnk_02035B68[];
extern u16 gUnk_02035BA8[];
extern s16 gUnk_02035B08[];
extern u16 gUnk_09993334[];
extern u8 gUnk_09A3ABDC[];
extern void* gUnk_020357C8;
extern void* gUnk_020357CC;
extern void* gUnk_020357D0;
extern void* gUnk_020357D4;
extern void* gUnk_020357F0;
extern void* gUnk_020357F4;
extern void* gUnk_02035810;
extern void* gUnk_02035814;
extern void* gUnk_02035818[];
extern void* gUnk_02035820[];
extern void* gUnk_02035858;
extern void* gUnk_0203585C;
extern TaskPool gUnk_020358A8;
extern UnkStruct_020358C8 gUnk_020358C8[];
extern FldRes* gUnk_02035A30;
extern void* gUnk_02035A34;
extern FldRes* gUnk_02035A38;
extern void* gUnk_02035A3C;
extern FldRes* gUnk_02035A40;
extern void* gUnk_02035A44;
extern void* gUnk_02035A4C;
extern void* gUnk_02035A54;
extern TaskPool gUnk_02035A70[];
extern void* gUnk_02035ADC;
extern void* gUnk_02035BAC;
extern void* gUnk_02035BB0;
extern void* gUnk_02035BD0[];
extern void* gUnk_02035BE0[];
extern FldRes* gUnk_02035AE0;
extern UnkStruct_099931E4 gUnk_099931E4[];
extern s16 gUnk_02035B18[][4][2];
extern s16 gUnk_099935C0[][4][4];
extern u16* gUnk_02035C00;
extern s16 gUnk_09993760[][4];
extern u8 gUnk_09A18EBC[];
extern s16 gUnk_02035B02;
extern s16 gUnk_02035B04;
extern s16 gUnk_02035B10;
extern u8 gUnk_02035C0C;

#endif /* GUARD_MODE_MS_H */
