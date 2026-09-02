#ifndef GUARD_MODE_DEBUG_H
#define GUARD_MODE_DEBUG_H

#include "types.h"
#include "main.h"
#include "anim.h"
#include "mode.h"
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

typedef struct DebugWork {
    s8 unk_00;
    s8 unk_01;
    u8 unk_02[0x02];
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
} DebugWork;

void func_080010CC(Mode* mode, s32 arg);
void func_080010E0(Mode* mode, s32 arg);
u16 GetKeysRepeat(void);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void AnimInit(AnimState* a, void* b, void* c);
void* AnimUpdate(AnimState* a);
void* LoadObjTiles(void* a, s32 b);
void func_08002A10(void* a, void* b);
void* LoadObjPalette(void* a, s32 b);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void func_08004DB0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgSize(s32 a, s32 b);
void SetBgColorMode(s32 a, s32 b);
void func_08005778(u16 r, u16 g, u16 b);
void func_08005974(void* a, u16 b, s32 c, void* d, void* e);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void func_08006120(s32 a, s32 b);
s16 GetPaletteEffect(void);
void SetPaletteEffect(s16 a);
void SaveClearHeader(void);
void SaveLoadHeader(void);
void SaveClearSystem(void);
void SaveClearFileLarge(s32 a);
void SaveClearFileSmall(s32 a);
void func_0800FDD0(s32 a);
void func_0801CB44(void);
void func_0805FA60(s32 a, const char* b, s32 c, s32 d);
void func_0805FA8C(s32 a, s32 b, s32 c);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_080609A0(void);
void func_08085C3C(void);
void func_08085FB0(void);
void m4aSongNumStart(u16 id);
void m4aMPlayAllStop(void);

void mode_debug_0(void);
void mode_debug_1(void);
void mode_debug_2(void);
void func_0800B30C(ObjDef* def);

extern DebugWork* gUnk_02034898;
extern ChkObjWork* gUnk_0203489C;
extern const char gUnk_08128418[];
extern const char gUnk_0812842C[];
extern const char gUnk_08128440[];
extern const char gUnk_08128454[];
extern const char gUnk_08128468[];
extern const char gUnk_0812847C[];
extern const char gUnk_08128490[];
extern const char gUnk_081284A4[];
extern const char gUnk_081284B8[];
extern const char gUnk_081284CC[];
extern const char gUnk_081284E0[];
extern const char gUnk_081284F4[];
extern const char gUnk_08128508[];
extern const char gUnk_0812851C[];
extern const char gUnk_08128530[];
extern const char gUnk_08128544[];
extern const char gUnk_08128558[];
extern const char gUnk_0812856C[];
extern const char gUnk_081283CC[];
extern const char gUnk_081283E0[];
extern const char gUnk_081283F0[];
extern const char gUnk_08128400[];
extern const char gUnk_08F68604[];
extern u8 gUnk_08950902[];
extern u8 gUnk_08C72CE4[];
extern u8 gUnk_08EEEB84[];
extern u8 gUnk_08F683E4[];
extern u8 gUnk_08F685E4[];
extern u8 gUnk_09EDF764[];
extern u8 gUnk_09EDF774[];
extern Mode gUnk_09ECEB54;
extern Mode gUnk_09ECEB64;
extern Mode gUnk_09ED8634;
extern Mode gUnk_09ED9A0C;
extern Mode gUnk_09ED9B68;
extern Mode gUnk_09ED9B88;
extern Mode gUnk_09EDE4D0;
extern Mode gUnk_09EE47AC;
extern Mode gUnk_09EF12F8;
extern Mode gUnk_09EF160C;
extern Mode gUnk_09EF3C88;
extern Mode gUnk_09EF4EC0;
extern Mode gUnk_09EF69D0;
extern Mode gUnk_09EF9674;

#endif /* GUARD_MODE_DEBUG_H */
