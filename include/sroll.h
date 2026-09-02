#ifndef GUARD_SROLL_H
#define GUARD_SROLL_H

#include "engine.h"
#include "gba/syscall.h"
#include "main.h"
#include "types.h"

typedef struct DmaStream {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x2];
    void (*unk_04)(void);
    vu16* unk_08;
    s32 unk_0C;
    u8* unk_10[2];
    u8* unk_18;
    u32 unk_1C;
} DmaStream;

typedef struct SrollShift {
    u32 unk_00;
    u32 unk_04;
} SrollShift;

typedef struct SrollMask {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} SrollMask;

typedef struct SrollBlit {
    s32 unk_00;
    s32 unk_04;
    u8* unk_08;
    u32* unk_0C;
    u32* unk_10;
    u32 unk_14[32];
} SrollBlit;

typedef struct SrollPal {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} SrollPal;

typedef struct SrollANameWork {
    u16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    void* unk_18;
    SrollPal* unk_1C;
    AnimState unk_20;
} SrollANameWork;

typedef struct SrollBCharGfx {
    void* unk_00;
    void* unk_04;
    void* unk_08;
} SrollBCharGfx;

typedef struct SrollBCharDef {
    SrollBCharGfx* unk_00;
    u8 unk_04[0x8];
    u16 unk_0C;
    u16 unk_0E;
} SrollBCharDef;

typedef struct SrollBCharSub {
    SrollBCharDef* unk_00;
    u8 unk_04[0x10];
    u16 unk_14;
} SrollBCharSub;

typedef struct SrollBCharWork {
    s32 unk_00;
    s32* unk_04;
    SrollBCharSub* unk_08;
    void* unk_0C;
    SrollPal* unk_10;
    AnimState unk_14;
    TaskPool unk_2C;
} SrollBCharWork;

typedef struct SrollBLogoWork {
    s32 unk_00;
    s32 unk_04;
    s32* unk_08;
    s32 unk_0C;
    void* unk_10;
    SrollPal* unk_14;
    AnimState unk_18;
} SrollBLogoWork;

typedef struct SrollBSecnWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32* unk_0C;
    s32 unk_10;
    void* unk_14;
    SrollPal* unk_18;
    AnimState unk_1C;
    AnimState unk_34;
} SrollBSecnWork;

typedef struct SrollBCrtnWork {
    s32 unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
    SrollPal* unk_14;
    AnimState unk_18;
} SrollBCrtnWork;

typedef struct SrollCCharWork {
    s32 unk_00;
    u8 unk_04[0x14];
    void* unk_18;
    SrollPal* unk_1C;
    AnimState unk_20[5];
} SrollCCharWork;

typedef struct SrollBCrtnArg {
    u16 unk_00;
    u8 unk_02[0x2];
    s32 unk_04;
    s32 unk_08;
} SrollBCrtnArg;

typedef struct SrollTmrWork {
    u8 unk_00;
    u8 unk_01[0x3];
    s32 unk_04;
    void* unk_08;
    SrollPal* unk_0C;
} SrollTmrWork;

typedef struct SrollInit {
    u32 unk_00;
    u32 unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u8 unk_0E[0x2];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u16 unk_20;
    u16 unk_22;
    u16 unk_24;
    u16 unk_26;
    u32 unk_28;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
    u16 unk_3A;
} SrollInit;

typedef struct SrollFont {
    u16 unk_00;
    u16 unk_02;
    u8* unk_04;
    u8* unk_08;
    u8* unk_0C;
    u32 unk_10;
    u8 unk_14;
} SrollFont;

typedef struct SrollWork {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    u16 unk_22;
    u16 unk_24;
    u16 unk_26;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u8* unk_34;
    u8* unk_38;
    u8* unk_3C;
    u32 unk_40;
    u8 unk_44;
    u8 unk_45[0x3];
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u16 unk_58[0x100];
} SrollWork;

typedef struct SoundEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} SoundEntry;

extern SrollShift gUnk_09A54C78[];
extern SrollMask gUnk_09A54918[][8];
extern void (*gUnk_09A54CB8[])(u32*, u8*, u32*, s32);
extern void (*gUnk_09A54CDC[])(u32*, u8*, u32*, s32);
extern DmaStream gUnk_02036028;
extern u8 gUnk_02036048;
extern s32 gUnk_02036050[];
extern u32* gUnk_02038090;
extern s32 gUnk_02038094;
extern s32 gUnk_02038098;
extern s32 gUnk_020380A0;
extern s32 gUnk_020380A4;
extern s8 gUnk_020380A8[];
extern s8 gUnk_02038368[];
extern const SoundEntry gUnk_09EFAA7C[];
extern u8 gUnk_088A5D7A[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09320796[];
extern u8 gUnk_09C5CC7C[];
extern u8 gUnk_09C8D47A[];
extern u8 gUnk_09C8F1FA[];
extern u8 gUnk_09C904B4[];
extern u8 gUnk_09D6BE34[];
extern u8 gUnk_09D6CF54[];
extern u8 gUnk_09D6D034[];
extern u8 gUnk_09D6D114[];
extern u8 gUnk_09EFAF60[];
extern u8 gUnk_09EFAF6C[];
extern u8 gUnk_09EFB840[];
extern u8 gUnk_09EFB9B8[];
extern u8 gUnk_09EFB9CC[];
extern u8 gUnk_09EFBAD4[];
extern u8 gUnk_09EDE7B4[];
extern u8 gUnk_09EDE7E4[];
extern u8 gUnk_09EEFCAC[];
extern u8 gUnk_09EEFD38[];
extern void* gUnk_09EFBAE8[];
extern const SrollFont gUnk_09A5B440[];
extern const u16 gUnk_09A5B470[];
extern u32 gUnk_09A5B674[];

void task_sroll_a_name_3(SrollANameWork* w);
void task_sroll_b_char_3(SrollBCharWork* w);
void task_sroll_b_crtn_3(SrollBCrtnWork* w);
void task_sroll_c_char_3(SrollCCharWork* w);
u8 task_sroll_a_name_1(SrollANameWork* w);
void task_sroll_b_crtn_0(SrollBCrtnWork* w, SrollBCrtnArg* a);
u8 task_sroll_b_crtn_1(SrollBCrtnWork* w);
void task_sroll_b_crtn_2(SrollBCrtnWork* w);
void task_sroll_b_logo_3(SrollBLogoWork* w);
void func_081149B0(SrollBCharWork* w, s32 v);
void func_081149B8(SrollBCharWork* w);
void task_sroll_c_char_0(SrollCCharWork* w, s32 kind);
void func_0811614C(SrollWork* w, SrollInit* a);
void func_081161C8(SrollWork* w);
void func_08116268(SrollWork* w, u16 a, u16 b, u16 c, u16 d);
void func_0811627C(SrollWork* w, u8 flush);
void func_08116698(SrollWork* w, u8 flush);
u8* func_081167F8(SrollWork* w, u8* s);
u8 sub_0811683C(SrollWork* w);
void func_08116AD8(SrollWork* w, u8 flush);
void func_08116B1C(SrollWork* w);
void func_08116B54(SrollWork* w, u8* s, u8 flush);
void func_08116B90(SrollWork* w, u16 x, u16 y, u8* s, u8 flush);
u32 sub_08116B10(SrollWork* w);
u8 task_sroll_b_logo_1(SrollBLogoWork* w);
void task_sroll_b_logo_2(SrollBLogoWork* w);
u8 task_sroll_b_secn_1(SrollBSecnWork* w);
void task_sroll_b_secn_2(SrollBSecnWork* w);
void task_sroll_b_secn_3(SrollBSecnWork* w);
u8 task_sroll_c_char_1(SrollCCharWork* w);
void task_sroll_c_char_2(SrollCCharWork* w);
void task_sroll_tmr_0(SrollTmrWork* w, void* arg);
u8 task_sroll_tmr_1(SrollTmrWork* w);
s32 abs(s32 x);
void func_08000714(void);
void func_08116E98(void);
void* AllocObjTiles(s32 size, void* b);
void func_08005974(void* a, u16 b, u16 c, void* d, void* e);
void* LoadObjTiles(void* src, s32 size);
SrollPal* LoadObjPalette(void* src, s32 size);
void func_080062F4(u16 a, s32 b);
void DrawSprite(s16 x, s16 y, void* a, void* b, void* c, s32 d, s32 e, u16 f);
void func_081154A0(u32* dst, u8* src, u32* pal, s32 x);
void func_081154EC(u32* dst, u8* src, u32* pal, s32 x);
void func_08115548(u32* dst, u8* src, u32* pal, s32 x);
void func_081155B0(u32* dst, u8* src, u32* pal, s32 x);
void func_08115628(u32* dst, u8* src, u32* pal, s32 x);
void func_081156AC(u32* dst, u8* src, u32* pal, s32 x);
void func_08115740(u32* dst, u8* src, u32* pal, s32 x);
void func_081159B0(u32* dst, u16* src, u32* pal, s32 x);
void func_081159FC(u32* dst, u16* src, u32* pal, s32 x);
void func_08115A5C(u32* dst, u16* src, u32* pal, s32 x);
u32 func_0811589C(SrollBlit* w);
u32 func_08115E24(SrollBlit* w);
void task_sroll_tmr_3(SrollTmrWork* w);
u16 func_081167D0(u16 c);
void func_08116A98(SrollWork* w, u8 flush);
void func_08116644(SrollWork* w);
u32 func_08116034(SrollWork* w, u32* dst, u8* src, s32 width);
void func_08116BEC(SrollWork* w, u16 x, u16 y, u8* s, u8 flush);
void func_081162E8(SrollWork* w);
u16 func_08115F34(u16 c, u8* font);
u8 func_08115F8C(u16 c, u8* font, u8* widths, u32 count);
s32 func_08115FBC(SrollWork* w, u8* s);
u32 func_08116008(u16 c, u8* font, u32 base, u16 a, u16 b);
void func_081160EC(SrollWork* w, u32 mode);
void func_081161D4(SrollWork* w);
u8 func_081161DC(SrollWork* w);
void func_081161EC(SrollWork* w, u16 c);
u16 sub_08116204(SrollWork* w);
void func_08116228(SrollWork* w, u16 x, u16 y);
void func_08116254(SrollWork* w, u16 x);
u16 func_08116CDC(u8 c);
void func_08116CEC(void);
void func_08116D28(void);
void func_08116DD0(void);
void func_08116DE8(void);
void func_08116E00(vu16* dst, u8* src, u32 cnt);
void func_08116E60(u8* src);
void func_08116E80(void);
void func_08116E8C(void);
void func_08116ECC(void);
void func_08116EF0(void);
void func_08116F08(void);
u16 func_08116F20(void);
u32* func_08116F28(void);
u8* func_08116F30(u32** p);
s32 func_08116F64(u32* src);
s32 func_08116FE4(void);
s32* func_08117044(void);
s32 func_0811704C(void);
void func_08117058(s32 pos);
u8 func_08117064(u32 id, u16* rate, u32* count);
u8 func_081170C0(u32 id);
void func_08117154(void);
void func_08117170(void);
void func_08117194(void);

#endif /* GUARD_SROLL_H */
