#ifndef GUARD_MODE_CHKOBJ_H
#define GUARD_MODE_CHKOBJ_H

#include "types.h"
#include "taskpool.h"
#include "chkobj.h"
#include "main.h"
#include "engine.h"
#include "mode.h"

typedef struct ChkObjEntry {
    ObjDef* unk_00;
    u16 count;
    u16 unk_06;
    const char* name;
} ChkObjEntry;


void ModeRequest(Mode* mode, s32 arg);
u16 GetKeysRepeat(void);
void* AllocObjTiles(s32 a, void* b);
void* LoadObjPalette(void* a, s32 b);
u16 func_08003598(void* a);
void SetBgMode0(void);
void SetBackdropColor(u16 r, u16 g, u16 b);
s32 abs(s32 n);
void func_08005974(void* a, u16 b, s32 c, void* d, void* e);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
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

extern ChkObjWork* gChkObjWork;
extern s16 gSineTable[];
extern u8 gUnk_088B629C[];
extern const char gWhitePalette[];
extern const ChkObjEntry gChkObjEntries[];
extern ObjDef gUnk_09ECEB74[];
extern ObjDef gUnk_09ED82D4[];
extern ObjDef gUnk_09ECF354[];
extern ObjDef gUnk_09ED07B4[];
extern ObjDef gUnk_09ED09F4[];
extern ObjDef gUnk_09ED1774[];
extern ObjDef gUnk_09ED4834[];
extern ObjDef gUnk_09ED5D34[];
extern ObjDef gUnk_09ED76F4[];
extern ObjDef gUnk_09ED77D4[];
extern u8 gUnk_08F683A4[];
extern Mode gModeDebug;
extern TaskDesc gTaskDescPrint;

#endif /* GUARD_MODE_CHKOBJ_H */
