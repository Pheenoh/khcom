#ifndef GUARD_MODE_SIO2_H
#define GUARD_MODE_SIO2_H

#include "types.h"
#include "main.h"
#include "mode.h"
#include "obj.h"

typedef struct PoohAnim {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
} PoohAnim;

typedef struct PoohPrizeArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
} PoohPrizeArgs;
typedef struct PoohSetup {
    u8 unk_00[0x0C];
    u8 unk_0C;
} PoohSetup;

typedef struct CharaLinkData {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} CharaLinkData;

typedef struct PoohPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} PoohPos;

typedef struct PoohNear {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} PoohNear;

typedef struct PoohHit {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} PoohHit;

typedef struct PoohWork {
    void* unk_00;
    PaletteSlot* unk_04;
    u8 unk_08[0x04];
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    u8 unk_28[0x10];
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C[0x0C];
    s32 unk_48;
    u8 unk_4C[0x5C];
    s32 unk_A8;
    u16 unk_AC;
    u8 unk_AE[0x02];
    TaskPool unk_B0;
    Task* unk_C4;
    u8 unk_C8[0x0E];
    u8 unk_D6;
    u8 unk_D7[0x03];
    u16 unk_DA;
    u8 unk_DC[0x1A];
    u8 unk_F6;
    u8 unk_F7[0x03];
    u8 unk_FA;
} PoohWork;

extern s8 gUnk_02034CF4;
extern s8 gUnk_02034CF5;
extern u16 gUnk_02034CF8;
extern u32 gUnk_02034CFC;
extern u32 gUnk_02034D00;
extern u32 gUnk_02034D04;
extern u16 gUnk_02034D08;
extern u32 gUnk_02034D0C;
extern u8 gUnk_02034D10;
extern TaskPool gUnk_02034D18;
extern TaskPool gUnk_02034D30;
extern u8 gUnk_02034D44;
extern u32 gUnk_02034D48;
extern u16 gUnk_02034D4C;
extern Task* gUnk_02034D50[];
extern TaskPool gUnk_02034D80;
extern Task* gUnk_02034D94;
extern u8 gUnk_02034D98;
extern s32 gUnk_02034D9C;
extern s32 gUnk_02034DA0;
extern s32 gUnk_02034DA4;
extern u32 gUnk_02034DAC;
extern PoohSetup gUnk_02039BB0;
extern u8 gUnk_0203A9E4;
extern CharaLinkData gUnk_0203AAC0;
extern s8 gUnk_0203C3C4;
extern u16 gUnk_0203C3C8;
extern u16 gUnk_0203C3CC;
extern u16 gUnk_0203C3D0;
extern s8 gUnk_0203C3D4;
extern u8 gUnk_0203C3D8;
extern u32 gUnk_0203C3F0;

extern u8 gUnk_08128304[];
extern const char gUnk_0961A9C8[];
extern const char gUnk_0961A9CC[];
extern const char gUnk_0961A9E8[];
extern u8 gUnk_09849A98[];
extern u8 gUnk_09849AD8[];
extern u8 gUnk_09849AF8[];
extern u8 gUnk_09849B18[];
extern const PoohHit gUnk_096FC010;
extern const u8 gUnk_096FC01C[];
extern PoohAnim gUnk_09EF3C98[];
extern PoohAnim gUnk_09EF3CE8[];
extern PoohAnim gUnk_09EF3D38[];
extern PoohAnim gUnk_09EF3D88[];
extern PoohAnim gUnk_09EF3E08[];
extern PoohAnim gUnk_09EF3E88[];
extern PoohAnim gUnk_09EF3E98[];
extern PoohAnim gUnk_09EF3EA8[];
extern PoohAnim gUnk_09EF3EB8[];
extern PoohAnim gUnk_09EF3EC8[];
extern PoohAnim gUnk_09EF3EE8[];
extern PoohAnim gUnk_09EF3F08[];
extern PoohAnim gUnk_09EF3F28[];
extern PoohAnim gUnk_09EF3F38[];
extern PoohAnim gUnk_09EF3F48[];
extern PoohAnim gUnk_09EF3F58[];
extern PoohAnim gUnk_09EF3F68[];
extern PoohAnim gUnk_09EF3F78[];
extern PoohAnim gUnk_09EF3F88[];
extern PoohAnim gUnk_09EF3F98[];
extern PoohAnim gUnk_09EF3FA8[];
extern PoohAnim gUnk_09EF3FB8[];
extern PoohAnim gUnk_09EF3FC8[];
extern PoohAnim gUnk_09EF3FD8[];
extern PoohAnim gUnk_09EF3FE8[];
extern PoohAnim gUnk_09EF3FF8[];
extern PoohAnim gUnk_09EF4048[][5];
extern Mode gUnk_09EF1308;
extern const char* const gUnk_09EF34F0[];
extern const char* const gUnk_09EF3504[];
extern TaskDesc gUnk_09EF161C;
extern TaskDesc gUnk_09EF41D8;
extern TaskDesc gUnk_09EF41F0;
extern TaskDesc gUnk_09EF48C8;
extern TaskDesc gUnk_09EF4988;
extern TaskDesc gUnk_09EF4A48;
extern TaskDesc gUnk_09EF4A60;
extern TaskDesc gUnk_09EF4A90;
extern TaskDesc gUnk_09EF4AA8;
extern TaskDesc gUnk_09EF4AC0;
extern TaskDesc gUnk_09EF4AD8;
extern TaskDesc gUnk_09EF4A78;
extern TaskDesc gUnk_09EF4AF0;
extern TaskDesc gUnk_09EF4B50;
extern TaskDesc gUnk_09EF4B68;
extern TaskDesc gUnk_09EF4B80;
extern TaskDesc gUnk_09EF4B98;
extern TaskDesc gUnk_09EF4BB0;
extern TaskDesc gUnk_09EF4BE0;
extern TaskDesc gUnk_09EF4BF8;
extern TaskDesc gUnk_09EF4C28;
extern TaskDesc gUnk_09EF4910;
extern TaskDesc gUnk_09EF4C58;
extern TaskDesc gUnk_09EF4D80;
extern TaskDesc gUnk_09EF4D98;

void func_080010CC(Mode* mode, s32 arg);
u8 func_08000F48(Task* t);
u16 GetKeysRepeat(void);
void func_08002A10(void* a, void* b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(void* a);
void func_08004DB0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void func_08005778(u16 r, u16 g, u16 b);
void func_08005974(void* a, u8 b, s32 c, void* d, void* e);
void ApproachValue(u32* value, u32 target, u16 steps);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
void func_080062F4(u16 a, s32 b);
u8 func_08006314(void);
void func_0801227C(void);
void func_080125A4(void);
void func_08012650(void* a, u16 b);
void UpdatePlayTime(void);
void func_0805FA60(s32 a, void* b, s32 c, s32 d);
void func_0805FA8C(s32 a, u16 b, u16 c);
void func_0805FC04(u8 x, u8 y, u8 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_080609A0(void);
void func_0806180C(u16 a);
void func_08085CB0(void);
u8 func_080A411C(TaskPool* a, s32 b, u16 c);
u8 func_080A42C8(void);
u8 func_080A42D4(void);
void func_080CCBE8(void);
void func_080D2BE0(void);
void func_080D2E84(void);
void func_080D2E98(void);
void func_080D2C8C(PoohPos* p, s32 b);
void func_080D2D0C(PoohPos* p);
u8 func_080D2D50(s32 a);
void func_080D2D6C(s32 a);
u8 func_080D2D94(s32 a);


void func_080DF814(void);
void m4aSongNumStart(u16 n);
void m4aSongNumStop(u16 n);
void* memcpy(void* dst, const void* src, unsigned long n);

void mode_sio_dbg_flg_0(s32 arg);
void mode_sio_dbg_flg_1(void);
void mode_sio_dbg_flg_2(void);
void func_080C7350(void);
void func_080C736C(void);
void func_080C73A4(u16 r, u16 g, u16 b);
void func_080C73D8(void);
void func_080C7568(u32 a, u16 b);
void func_080C75A4(u32 a, u16 b);
void func_080C75E0(u32 a, u16 b);
void func_080C7608(u32 a, u16 b, u16 c);
u8 func_080C7638(void);
void func_080C7644(u32 a, u16 b, u16 c);
void func_080C7684(s32 a, s32 b, s32 c);
u8 func_080C76B0(PoohNear* p);
void func_080C7714(void);
void func_080C774C(void);
void mode_pooh_0(s32 arg);
void mode_pooh_1(void);
void mode_pooh_2(void);
void func_080C7B84(u32 a);
void func_080C7BCC(u16 a);
u16 func_080C7BF8(u8 kind, u8 count, s32 x, s32 y, s32 z);
u16 func_080C7C80(void);
void func_080C7CB0(u8 a);
u8 func_080C7CBC(void);
void func_080C7CC8(PoohWork* w);
void func_080C7D60(PoohWork* w);
void func_080C7DF8(PoohWork* w);
void func_080C7E98(PoohWork* w);
void func_080C7F18(PoohWork* w);
u8 func_080C7F4C(u8 a);
u8 func_080C7F94(PoohWork* w);
void func_080C7FEC(PoohWork* w, u32 anim);
u8 func_080C83C4(u16 x, u16 y, u16 px, u16 py);
s32 func_080C8404(PoohPos* a, PoohPos* b);
void func_080C8428(PoohWork* w, u32 b);
void func_080C84E0(PoohWork* w, u32 b);

#endif /* GUARD_MODE_SIO2_H */
