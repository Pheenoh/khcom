#ifndef GUARD_MODE_MS2_H
#define GUARD_MODE_MS2_H

#include "card_ui_types.h"

#include "card_api.h"

#include "map_api.h"
#include "ms_charge_api.h"
#include "mode_worldwarp_api.h"

#include "mode_ms2_api.h"

#include "engine_math.h"

#include "game_state.h"
#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "text_types.h"
#include "ms_types.h"
#include "key.h"
#include "malloc.h"
#include "anim.h"
#include "mode.h"
#include "m4a.h"


extern UnkStruct_09EF9618 gUnk_09EF9618[];
extern UnkStruct_09EE4C80 gUnk_09EE4C80[];
extern UnkStruct_09EE4BF4 gUnk_09EE4BF4[];
extern s16 gUnk_02035C14;
extern s16 gUnk_02035C16;
extern AnimState gUnk_02035CA0;
extern u8 gUnk_02035CB8;
extern s16 gUnk_02035CBA;
extern s16 gUnk_02035CBC;
extern void* gUnk_02035C10;
extern s16 gUnk_02035C3A;
extern AnimState gUnk_02035C50;
extern AnimState gUnk_02035C68;
extern AnimState gUnk_02035C88;
extern AnimState gUnk_02035CC8;
extern void* gUnk_02035CE8[4][3];
extern void* gUnk_02035D18[4][3];
extern void* gUnk_02035D48[4][3];
extern u8 gUnk_02035D78[4][3];
extern void* gUnk_02035D8C;
extern void* gUnk_02035D98;
extern AnimState gUnk_02035DA0;
extern AnimState gUnk_02035DC0;
extern u8 gUnk_02035DD8;
extern u8 gUnk_02035DF0;
extern u8 gUnk_02035DF8;
extern u8 gUnk_02035E00;
extern u8 gUnk_02035E08;
extern s32 gUnk_02035E18;
extern s32 gUnk_02035E1C;
extern struct ObjTiles* gUnk_02035C40;
extern struct ObjPaletteNode* gUnk_02035C44;
extern struct ObjTiles* gUnk_02035C48;
extern struct ObjPaletteNode* gUnk_02035C80;
extern struct ObjTiles* gUnk_02035C84;
extern struct ObjPaletteNode* gUnk_02035CC0;
extern struct ObjTiles* gUnk_02035CC4;
extern struct ObjPaletteNode* gUnk_02035D84;
extern struct ObjTiles* gUnk_02035D88;
extern struct ObjPaletteNode* gUnk_02035D90;
extern struct ObjTiles* gUnk_02035D94;
extern struct ObjTiles* gUnk_02035D9C;
extern struct ObjTiles* gUnk_02035DB8;
extern void* gUnk_02035DDC;
extern void* gUnk_02035DE4;
extern void* gUnk_02035DEC;
extern u16 gUnk_02035DF2;
extern void* gUnk_02035DF4;
extern u16 gUnk_02035DFA;
extern void* gUnk_02035DFC;
extern u16 gUnk_02035E02;
extern void* gUnk_02035E04;
extern u16 gUnk_02035E0A;
extern s32 gUnk_02035FD0[];
extern s32 gUnk_02035FD8;
extern u8 gUnk_02035E20;
extern Mode gModeMsTop;
extern s16 gUnk_02035FC4;
extern s16 gUnk_02035FC6;
extern s16 gUnk_02035FC8;
extern s16 gUnk_02035FCA;
extern s16 gUnk_02035FCC;
extern s32 gUnk_02035FDC;
extern s32 gUnk_02035FE0;
extern u8 gUnk_02035FE4;
extern const u16 gUnk_099937A0[];
extern u8 gUnk_0203C0A8[];
extern u8 gUnk_0908B1B4[];
extern u8 gUnk_0999D9C0[];
extern u8 gUnk_0999D9CA[];
extern u8 gUnk_0999D9E6[];
extern u8 gUnk_0999DA1A[];
extern u8 gUnk_0908C3CE[];
extern u8 gUnk_092028EC[];
extern u8 gUnk_08159E10[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_08159F38[];
extern u8 gUnk_0815C204[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_099A2194[];
extern u8 gUnk_099A6C82[];
extern u8 gUnk_099A7C78[];
extern u8 gUnk_09A1913C[];
extern u8 gUnk_09A3B25C[];
extern u8 gUnk_09A3B85C[];
extern u8 gUnk_09A3BD5C[];
extern u8 gUnk_09A3C25C[];
extern u8 gUnk_09A3DBDC[];
extern u8 gUnk_09A3DE7C[];
extern u8 gUnk_09EEA148[];
extern u8 gUnk_09EEA164[];
extern u8 gUnk_09EEA180[];
extern u8 gUnk_09EEA198[];
extern u8 gUnk_09EEEA98[];
extern u8 gUnk_09EEEAC8[];
extern u8 gUnk_09EF9928[];
extern u8 gUnk_09EF9978[];
extern u8 gUnk_09EF9A68[];
extern u8 gUnk_09EF9AA4[];
extern u8 gUnk_09A067DC[];
extern u8 gUnk_09A067FC[];
extern u8 gUnk_09A3439C[];
extern u8 gUnk_09A34D9C[];
extern u8 gUnk_09A3501C[];
extern u8 gUnk_09A3551C[];
extern u8 gUnk_09A3D248[];
extern u8 gUnk_09A3D2C8[];
extern u8 gUnk_09A3D2FC[];
extern void* gUnk_09EE90D0[];
extern u8 gUnk_09A0667C[];
extern u8 gUnk_09A0669C[];
extern u8 gUnk_09A0693C[];

s16 func_0810712C(s16 a);
s16 func_0810714C(void);
void func_081071AC(void);
s16 func_08107220(s16 a);
u8 func_08107268(void);
s16 func_081075C0(s16 a, s16 b);
s16 func_081075D8(void);
u16 func_08107D24(void);
void mode_ms_charge_1(void);
void mode_ms_charge_2(void);
void func_08108170(UnkStruct_0810718C* p, u16 row);
void func_08107938(void);
u8 func_081079A8(UnkStruct_0810718C* p);
u8 func_081079E4(UnkStruct_0810718C* p);
void func_08107A08(UnkStruct_0810718C* p);
void func_08107A74(UnkStruct_0810718C* p);
void mode_ms_charge_0(void);
extern s16 gUnk_02035C18;
extern s16 gUnk_02035CE0;
extern s16 gUnk_02035CE2;
extern s16 gUnk_02035CE4;
extern s16 gUnk_02035E0C;
extern s16 gUnk_02035E0E;

#endif /* GUARD_MODE_MS2_H */
