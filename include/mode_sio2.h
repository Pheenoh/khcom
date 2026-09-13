#ifndef GUARD_MODE_SIO2_H
#define GUARD_MODE_SIO2_H

#include "sio_debug_state.h"

#include "pooh_state.h"

#include "chara_types.h"

#include "prize_types.h"

#include "card_api.h"
#include "card_ui_state.h"

#include "msg_api.h"
#include "mode_sio2_api.h"

#include "mode_test_api.h"

#include "anim.h"
#include <string.h>
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "taskpool.h"
#include "main.h"
#include "mode.h"
#include "obj.h"
#include "key.h"
#include "m4a.h"
#include "bos4_api.h"
#include "poo_api.h"

typedef struct PoohAnim {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
} PoohAnim;

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
    PaletteSlot* palette;
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

extern u32 gUnk_02034DAC;
extern CharaLinkData gUnk_0203AAC0;

extern u8 gWhitePalette[];
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
extern Mode gModeSioBtlConnect;
extern const char* const gUnk_09EF34F0[];
extern const char* const gUnk_09EF3504[];
extern TaskDesc gTaskDescWLogo;
extern TaskDesc gTaskDescPooPooh;
extern TaskDesc gTaskDescPooMap;
extern TaskDesc gTaskDescPooSora;
extern TaskDesc gTaskDescPooGauge;
extern TaskDesc gTaskDescPooPiglet;
extern TaskDesc gTaskDescPooEeyore;
extern TaskDesc gTaskDescPooRabbit;
extern TaskDesc gTaskDescPooTigger;
extern TaskDesc gTaskDescPooTiggerroo;
extern TaskDesc gTaskDescPooRoo;
extern TaskDesc gTaskDescPooOwl;
extern TaskDesc gTaskDescPooRooFootmark;
extern TaskDesc gTaskDescPooEeyoretail;
extern TaskDesc gTaskDescPooHoneycomb;
extern TaskDesc gTaskDescPooVegetable;
extern TaskDesc gTaskDescPooWagon;
extern TaskDesc gTaskDescPooWagonwheel;
extern TaskDesc gTaskDescPooBee;
extern TaskDesc gTaskDescPooBeeAfterEvent;
extern TaskDesc gTaskDescPooCabbageborn;
extern TaskDesc gTaskDescPooBalloon;
extern TaskDesc gTaskDescPooPrize;
extern TaskDesc gTaskDescPooRabbitAfterEvent;
extern TaskDesc gTaskDescPooCabbageAfterEvent;

void mode_sio_dbg_flg_0(s32 arg);
void mode_sio_dbg_flg_1(void);
void mode_sio_dbg_flg_2(void);
void func_080C75E0(u32 a, u16 b);
void func_080C7608(u32 a, u16 b, u16 c);
u8 func_080C7638(void);
void func_080C7644(u32 a, u16 b, u16 c);
void func_080C7714(void);
void func_080C774C(void);
void mode_pooh_0(s32 arg);
void mode_pooh_1(void);
void mode_pooh_2(void);
u16 func_080C7C80(void);
void func_080C7D60(PoohWork* w);
void func_080C7DF8(PoohWork* w);
void func_080C7E98(PoohWork* w);
void func_080C7F18(PoohWork* w);
u8 func_080C7F4C(u8 a);
u8 func_080C7F94(PoohWork* w);
void func_080C8428(PoohWork* w, u32 b);

#endif /* GUARD_MODE_SIO2_H */
