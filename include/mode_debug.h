#ifndef GUARD_MODE_DEBUG_H
#define GUARD_MODE_DEBUG_H

#include "types.h"
#include "chkobj.h"
#include "main.h"
#include "anim.h"
#include "mode.h"
typedef struct DebugWork {
    s8 unk_00;
    s8 unk_01;
    u8 unk_02[0x02];
    void* tiles;
    void* palette;
    AnimState anim;
} DebugWork;

void ModeRequest(Mode* mode, s32 arg);
void ModeRequestHeapReset(Mode* mode, s32 arg);
u16 GetKeysRepeat(void);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(u8* p);
void AnimInit(AnimState* a, void* b, void* c);
void* AnimUpdate(AnimState* a);
void* LoadObjTiles(void* a, s32 b);
void func_08002A10(void* a, void* b);
void* LoadObjPalette(void* a, s32 b);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void SetBgMode0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgSize(s32 a, s32 b);
void SetBgColorMode(s32 a, s32 b);
void SetBackdropColor(u16 r, u16 g, u16 b);
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
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
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
extern const char gUnk_08F68604[];
extern u8 gUnk_08950902[];
extern u8 gUnk_08C72CE4[];
extern u8 gUnk_08EEEB84[];
extern u8 gUnk_08F683E4[];
extern u8 gUnk_08F685E4[];
extern u8 gUnk_09EDF764[];
extern u8 gUnk_09EDF774[];
extern Mode gModeChkbtl;
extern Mode gModeDebug;
extern Mode gModeChkobj;
extern Mode gModeChksnd;
extern Mode gModeChkeff;
extern Mode gModeDebflag;
extern Mode gModeMovie;
extern Mode gModeEventselect;
extern Mode gModeSioBattle;
extern Mode gModeWLogo;
extern Mode gModePooh;
extern Mode gModeCopyright1;
extern Mode gModeMapChk;
extern Mode gModeBackupstat;

#endif /* GUARD_MODE_DEBUG_H */
