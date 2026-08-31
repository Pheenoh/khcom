#ifndef GUARD_MODE_CHKOBJ_H
#define GUARD_MODE_CHKOBJ_H

#include "types.h"
#include "main.h"
#include "engine.h"

typedef struct Mode {
    const char* name;
    void (*unk_04)(void);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

typedef struct ObjDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    void* unk_10;
    const char* unk_14;
    const char* unk_18;
    u16 unk_1C;
    u16 unk_1E;
} ObjDef;

typedef struct ChkObjEntry {
    ObjDef* unk_00;
    u16 unk_04;
    u16 unk_06;
    const char* unk_08;
} ChkObjEntry;

typedef struct ChkObjWork {
    TaskPool pool;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x02];
    void* unk_1C;
    void* unk_20;
    AnimState unk_24;
    void* unk_3C;
    u8 unk_40;
    u8 unk_41;
    u16 unk_42;
    s16 unk_44;
    s16 unk_46;
} ChkObjWork;

void func_080010CC(Mode* mode, s32 arg);
u16 GetKeysHeld(void);
u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
void* AllocObjTiles(s32 a, void* b);
void ReleaseObjTiles(void* a);
void* LoadObjPalette(void* a, s32 b);
void func_08002A10(void* a, void* b);
u16 func_08003598(void* a);
void func_08004DB0(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void func_08005778(u16 r, u16 g, u16 b);
s32 abs(s32 n);
void func_08005974(void* a, u16 b, s32 c, void* d, void* e);
void AnimStart(AnimState* a, u16 b, s32 c);
u16 func_08005B38(AnimState* a);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void func_0805FA60(s32 a, const char* b, s32 c, s32 d);
void func_0805FA8C(s32 a, s32 b, s32 c);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_080609A0(void);
void func_0809D2B0(s32 a, s32 b, s32 c, const char* s);
void func_0809D458(s32 a, s32 b, s32 c, s32 v);

void func_0800B30C(ObjDef* def);
void mode_chkobj_0(void);
void mode_chkobj_1(void);
void mode_chkobj_2(void);

extern ChkObjWork* gUnk_0203489C;
extern s16 gSineTable[];
extern u8 gUnk_088B629C[];
extern const char gUnk_08128304[];
extern ChkObjEntry gUnk_0812E744[];
extern const char gUnk_0812E884[];
extern const char gUnk_0812E88C[];
extern const char gUnk_0812E894[];
extern const char gUnk_0812E8BC[];
extern const char gUnk_0812E8C4[];
extern const char gUnk_0812E8C8[];
extern const char gUnk_0812E8D0[];
extern const char gUnk_0812E8D4[];
extern const char gUnk_0812E8DC[];
extern const char gUnk_0812E8E4[];
extern u8 gUnk_08F683A4[];
extern Mode gUnk_09ECEB64;
extern TaskDesc gUnk_09EE9190;

#endif /* GUARD_MODE_CHKOBJ_H */
