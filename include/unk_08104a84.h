#ifndef GUARD_UNK_08104A84_H
#define GUARD_UNK_08104A84_H

#include "types.h"
#include "key.h"
#include "engine.h"

#define CARD_ID_MASK 0xFFF

typedef struct MsCardDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x2];
    u8 unk_20;
    u8 unk_21[0x7];
    u16 unk_28;
    u8 unk_2A;
    u8 unk_2B[0x9];
} MsCardDef;

typedef struct MsCardBack {
    void* unk_00;
    u8 unk_04[0x8];
    void* unk_0C;
    u8 unk_10[0x8];
} MsCardBack;

typedef struct MsCard {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    s16 unk_06[10][2];
    u8 unk_2E;
    u8 unk_2F[0x1];
    u32 unk_30;
} MsCard;

extern MsCard* gUnk_02035C10;
extern s16 gUnk_02035C14;
extern u16 gUnk_02035C16;
extern s16 gUnk_02035C18;
extern s16 gUnk_02035C20[];
extern s16 gUnk_02035C28[];
extern s16 gUnk_02035C30[];
extern s16 gUnk_02035C38;
extern u16 gUnk_02035C3A;
extern u16 gUnk_02035C3C;
extern void* gUnk_02035C40;
extern u16* gUnk_02035C44;
extern void* gUnk_02035C48;
extern AnimState gUnk_02035C50;
extern AnimState gUnk_02035C68;
extern void* gUnk_02035C80;
extern void* gUnk_02035C84;
extern AnimState gUnk_02035C88;
extern AnimState gUnk_02035CA0;
extern u8 gUnk_02035CB8;
extern s16 gUnk_02035CBA;
extern s16 gUnk_02035CBC;
extern void* gUnk_02035CC0;
extern void* gUnk_02035CC4;
extern AnimState gUnk_02035CC8;
extern s16 gUnk_02035CE0;
extern s16 gUnk_02035CE2;
extern s16 gUnk_02035CE4;
extern void* gUnk_02035CE8[4][3];
extern void* gUnk_02035D18[4][3];
extern void* gUnk_02035D48[4][3];
extern u8 gUnk_02035D78[4][3];
extern void* gUnk_02035D84;
extern void* gUnk_02035D88;
extern void* gUnk_02035D8C;
extern void* gUnk_02035D90;
extern void* gUnk_02035D94;
extern void* gUnk_02035D98;
extern void* gUnk_02035D9C;
extern AnimState gUnk_02035DA0;
extern void* gUnk_02035DB8;
extern AnimState gUnk_02035DC0;
extern u8 gUnk_02035DD8;
extern void* gUnk_02035DDC;
extern u8 gUnk_02035DE0;
extern void* gUnk_02035DE4;
extern u8 gUnk_02035DE8;
extern void* gUnk_02035DEC;
extern u8 gUnk_02035DF0;
extern void* gUnk_02035DF4;
extern u8 gUnk_02035DF8;
extern void* gUnk_02035DFC;
extern u8 gUnk_02035E00;
extern void* gUnk_02035E04;
extern u8 gUnk_02035E08;
extern s16 gUnk_02035E0C;
extern s16 gUnk_02035E0E;
extern s16 gUnk_02035E10;
extern u32 gUnk_02035E14;
extern s32 gUnk_02035E18;
extern s32 gUnk_02035E1C;
extern u8 gUnk_02035E20;
extern u16 gCardCollection[];
extern u16 gCardCount;
extern s16 gSineTable[];
extern MsCardBack gUnk_08F709B0[];
extern MsCardDef gCardDefs[];
extern u8 gUnk_099A7C64[];
extern u8 gUnk_09A1DB9C[];
extern u8 gUnk_09A1DCDC[];
extern u8 gUnk_09A1DE1C[];
extern u8 gUnk_09A1DE3C[];
extern u8 gUnk_09A1DF7C[];
extern u8 gUnk_09A1DF9C[];
extern u8 gUnk_09A3B75C[];
extern u8 gUnk_09A3B85C[];
extern u8 gUnk_09A3BD5C[];
extern u8 gUnk_09A3DD7C[];
extern u8 gUnk_09A3DD88[];
extern u8 gUnk_09A3DE08[];
extern u8 gUnk_09A3DE7C[];
extern void* gUnk_09EE8F48[];

void* memcpy(void* dst, const void* src, unsigned long n);
void func_0800448C(void* src, void* dst, u8 x, u8 y, u8 w, u8 h, u8 sw, u8 sh);
void func_08006184(s32 a, u16 b);
void* LoadObjPalette(void* a, s32 b);
void* LoadObjTiles(void* a, s32 b);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
u16 GetKeysRepeat(void);
void func_0805F1C0(s32* p, s32 v);
u16 func_08060A2C(u16 a);
s16 func_08065B08(void* a, u8 b);
u8 func_08065B6C(void* a, void* b);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
s16 func_08084BAC(void);
s16 func_08084BF0(void);
u32 func_08101518(void);
void func_08101588(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count);
void m4aSongNumStart(u16 song);

s16 func_08104A84(s16 a);
s16 func_08104AA4(s16 a);
s16 func_08104AEC(void);
MsCard* func_08104B2C(void);
void func_08104B48(void);
void func_08104BBC(void);
void func_08104D18(void);
s16 func_08104E9C(s16 a, s16 b);
s16 func_08104EB4(void);
u16 func_08104ED8(u16 index);
void func_08104F2C(void);
void func_08104FA4(void);
void func_08104FF8(void);
void func_08105090(void);
void func_081052C8(s16 a);
void func_08105334(void);
u8 func_08105404(MsCard* card);
u8 func_08105440(MsCard* card);
void func_08105464(MsCard* card);
void func_081054D0(MsCard* card);
s32 func_081055E8(u16 id, u8 flag, s16 count);
void func_0810563C(void);
s32 func_0810592C(void);
void func_0810594C(void);
void func_08105BD8(void);
s32 func_08105D24(MsCard* card, u16 col);
void func_08105DE0(void);
void func_0810601C(void);
void func_081061DC(void);
void func_08106234(void);

#endif /* GUARD_UNK_08104A84_H */
