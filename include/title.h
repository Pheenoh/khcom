#ifndef GUARD_TITLE_H
#define GUARD_TITLE_H

#include "types.h"
#include "taskpool.h"
#include "title_types.h"
#include "main.h"
#include "anim.h"
typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
} GameState;

typedef struct TitlePal {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} TitlePal;

typedef struct TitleObjSprite {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s16 unk_0C;
    s32 unk_10;
    s32 unk_14;
} TitleObjSprite;

typedef struct TitleObjWork {
    TitleObjSprite unk_00[3];
    AnimState anim;
    u16 unk_60;
    u16 unk_62;
} TitleObjWork;

typedef struct TitleMenuWork {
    void* tiles;
    TitlePal* palette;
    void* unk_08[3];
    TitlePal* unk_14[3];
    void* unk_20[3];
    AnimState anim;
    s16* unk_44;
    TaskPool unk_48;
    s32 unk_5C;
    s16 unk_60;
    u16 unk_62;
} TitleMenuWork;

typedef struct TitleLumiChangeWork {
    void* tiles;
    void* palette;
    void* unk_08;
} TitleLumiChangeWork;

extern GameState gGameState;
extern u8 gUnk_02034ECC;

extern u8 gUnk_09771060[];
extern u8 gUnk_0977143A[];
extern u8 gUnk_09771666[];
extern u8 gUnk_09771DC0[];
extern u8 gUnk_097720F2[];
extern u8 gUnk_09772CC6[];
extern u8 gUnk_09773426[];
extern u8 gUnk_09773E1A[];
extern u8 gUnk_0977548C[];
extern u8 gUnk_0984A718[];
extern u8 gUnk_0984A778[];
extern u8 gUnk_0984A7B8[];
extern u8 gUnk_0984A7D8[];
extern u8 gUnk_0984A7F8[];
extern s32 gUnk_096FDCC8[];
extern s16 gUnk_096FDCE8[];
extern TaskDesc gTaskDescTitleLumichange;
extern void* gUnk_09EF65E0[];
extern void* gUnk_09EF65E8[];
extern u8 gUnk_09EF65F0[];
extern u8 gUnk_09EF6604[];
extern u8 gUnk_09EF6608[];
extern u8 gUnk_09EF661C[];
extern void* gUnk_09EF6620[];
extern void* gUnk_09EF663C[];
extern void* gUnk_09EF6658[];
extern void* gUnk_09EF6668[];
extern void* gUnk_09EF6684[];

void* memcpy(void* dst, const void* src, unsigned long n);
void m4aSongNumStart(u16 id);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(u8* p);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* AnimGetGfx(AnimState* a);
void* AnimUpdate(AnimState* a);
void ApproachValue(s32* value, s32 target, u16 steps);
s16 GetPaletteEffect(void);
void SetPaletteEffect(s16 a);
void func_080D5978(u16 a, void* b, u16 c);
void func_080D5998(void);
u8 func_080D6280(void);
u8 func_080D6294(void);
void func_080D62A8(TitleLogoWork* work);

void task_title_logo_0(TitleLogoWork* work);
u8 task_title_logo_1(TitleLogoWork* work);
void task_title_logo_2(TitleLogoWork* work);
void task_title_logo_3(TitleLogoWork* work);
void func_080D6548(u8* src, u16* dst, u16 size);
u8 func_080D6574(void);
void task_title_obj_0(TitleObjWork* work);
u8 task_title_obj_1(TitleObjWork* work);
void task_title_obj_2(TitleObjWork* work);
void task_title_obj_3(TitleObjWork* work);
u8 func_080D6790(void);
void task_title_menu_0(TitleMenuWork* work, s16* arg);
s16 func_080D6908(s16 a);
void func_080D6944(s16* p);
void func_080D69AC(s16* p, s16 count);
u8 task_title_menu_1(TitleMenuWork* work);
void func_080D6A64(TitleMenuWork* work);
void func_080D6B7C(TitleMenuWork* work);
void func_080D6C54(TitleMenuWork* work);
void func_080D6D2C(TitleMenuWork* work);
void task_title_menu_2(TitleMenuWork* work);
void task_title_menu_3(TitleMenuWork* work);
void task_title_lumichange_0(TitleLumiChangeWork* work);
u8 task_title_lumichange_1(TitleLumiChangeWork* work);
void task_title_lumichange_2(TitleLumiChangeWork* work);
void task_title_lumichange_3(TitleLumiChangeWork* work);

#endif /* GUARD_TITLE_H */
