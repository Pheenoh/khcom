#include "macros.h"
#include "anim.h"
#include "text_types.h"
#include "taskpool.h"
#include "key.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "card.h"

u8 func_080892E8(u8* work, void* a);

#ifdef VERSION_EU
extern void* eu_0805E924(void* strings);
extern u32 gLanguage;
extern void** gUnkEu_09F72CC4[];
extern void* gUnkEu_09F72CB0[];
extern u16* gUnkEu_09F65FDC[];
extern u16* gUnkEu_09F65FF0[];
extern u16* gUnkEu_09F66004[];
extern void* gUnkEu_09F6FDB4[];
extern u16 gUnkEu_090CE9EA[];
extern void* gUnkEu_09F6FDDC[];
extern u16 gUnkEu_090CE9F4[];
extern void** gUnkEu_09F72BFC[];
extern void** gUnkEu_09F74360[];
extern void* gUnkEu_09F7434C[];
extern u16 gUnkEu_090D1DF4[];
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];
extern void* gUnkEu_08890EC0[];
extern void* gUnkEu_08895E94[];
extern u8 gUnkEu_08CB0D3C[];
extern u8 gUnkEu_08F7ADFC[];
extern u8 gUnkEu_09F72C10[];
extern u8 gUnkEu_09F72D80[];
extern void** gUnkEu_09F72E10[];
extern u8 gUnkEu_0916F992[];
extern u8 gUnkEu_0917063A[];
extern u8 gUnkEu_09170202[];
extern u8 gUnkEu_0916FDCA[];
extern u8 gUnkEu_094DCCE4[];
extern u8 gUnkEu_094E20E4[];
extern u8 gUnkEu_094E74E4[];
extern u8 gUnkEu_094E58E4[];
extern u8 gUnkEu_094E3CE4[];
extern u8* gUnkEu_09F74374[];
extern u8 gUnkEu_09529A04[];
extern u8 gUnkEu_0952DDE4[];
extern u8 gUnkEu_0952E0E4[];
extern u8 gUnkEu_0952DFE4[];
extern u8 gUnkEu_0952DEE4[];
extern u8 gUnkEu_09543324[];
extern u8 gUnkEu_09534324[];
extern s16 gUnkEu_090D1DFE[];
extern s16 gUnkEu_090D1E04[];
extern void* gUnkEu_08895AF4[];
extern void* gUnkEu_08895C30[];
extern void* gUnkEu_08895CF8[];
extern void* gUnkEu_08895DBC[];
#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif

extern UnkStruct_02034AAC* gUnk_02034A98;

u32 gUnk_02034AA4;
u32 gUnk_02034AA8;
UnkStruct_02034AAC* gUnk_02034AAC;
u8 gActiveDeck;
u8 gUnk_02034AB1[3];
s16 gUnk_02034AB4;
u8 gUnk_02034AB6[2];
#ifdef VERSION_EU
u8 gUnkEu_02034AD4[4];
#endif
u8 gUnk_02034AB8[20];
u8 gUnk_02034ACC;
u32 gUnk_02034AD0;
void* gUnk_02034AD4;
u8 gUnk_02034AD8;
u8 gUnk_02034AD9;
u8 gUnk_02034ADA[6];
u8 gUnk_02034AE0[20];
#ifndef VERSION_EU
u8 gUnk_02034AF4[4];
#endif
u8 gUnk_02034AF8;
UnkStruct_02034AFC* gUnk_02034AFC;
UnkStruct_02034AFC* gUnk_02034B00;
#ifndef VERSION_EU
u8 gUnk_02034B04[4];
u8 gUnk_02034B08[20];
u8 gUnk_02034B1C;
u8 gUnk_02034B1D[3];
#endif
u8 gUnk_02034B20[20];
void* gUnk_02034B34;
#ifdef VERSION_EU
u8 gUnk_02034B04[4];
u8 gUnk_02034B08[20];
u8 gUnk_02034B1C;
u8 gUnk_02034B1D[3];
#endif
#include "game.h"

void LoadBgTiles(s32 bg, void* src, u16 size);
extern u8 gUnk_0950E2F8[];
extern u8 gUnk_096112B8[];
u8 func_080A470C(u8* work, void* a);
u8 func_080A4CC8(UnkStruct_080A3F5C* w, void* a);
void func_0808DB04(void** p);
void func_0808CDE8(u8* work, u8 b);
u16 func_0806BA74(s32 mode, s32 flag);
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_08098670(UnkStruct_08098670* p, u16 a);
void func_080DFF4C(void* p);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void* TaskCreate(void* a, void* desc, void* args);
u8 func_08085290(u16 a);
s32 func_080938F8(u16 a);
u16 func_080857D4(u8 slot);
u16 func_08065B6C(u16* a, TextSlot* b);
s16 func_08065B08(TextSlot* p, u8 n);
#ifdef VERSION_EU
s16 eu_0806629C(TextSlot* p, u8 n);
#endif
u16 GetRandom(void);
u16 func_08085770(u8 index);
void func_08085788(u8 index, u16* src);
void func_08085160(void);
void func_080AB228(void);
void func_080AB22C(u8 a);
void func_080AB334(u8 a);
void func_080AB4AC(u8 a);
void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
u16 func_08084458(u16 a);
u16 func_08093B38(void);
u16 func_08093B08(u16 a);
u16 func_08096C38(UnkStruct_08096C38* tbl, u16 n);
u16 func_08096CCC(void);
u8 func_0807CE68(UnkStruct_02034AAC* p);
void func_0807C39C(UnkStruct_02034AAC* p);
void func_0807C33C(UnkStruct_02034AAC* p);
UnkStruct_0808E890* ListPoolFirst(void* node);
UnkStruct_0808E890* ListPoolNext(void* node);
void TaskPoolUpdate(TaskPool* a);
void func_0808DE28(u8 a);
s32 func_080609AC(u16 a);
s32 func_0808C8D0(s32 a);
void func_08065ACC(TextSlot* p, s32 n);
void func_080AB1F8(u8 a, u16 b);
void func_080AB964(void);
void func_080AB968(void);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
u32 GetBgCharBase(s32 bg);
void* memcpy(void* dst, const void* src, unsigned long n);
s16 func_080858B8(s32 index);
void func_08085A58(s32 index, u16* dst);
u8 func_080A42C8(void);
s32 func_080A40EC(u64* src);
s32 func_080A4D7C(u64* src);
UnkStruct_080038C8* func_080038C8(s32 size);
void func_080038E4(UnkStruct_080038C8* a, void* b, void* c);
void m4aSongNumStart(u16 n);
void m4aSongNumStop(u16 n);
s32 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
s32 func_0801A8A4(void* a, void* b, s32 c, s32 d);
void ColliderSetRadius(void* a, u16 b);
u8 func_0801C6D4(s32* a, s32* b, s32* c, s32* d);
void func_08012614(void* a, s32 b);
u16 func_08006390(void);
void func_08006290(s32 a, u16 b, u16 c);
u8 func_0807EDEC(UnkStruct_08080268* w, void* a);
u8 func_0807FB5C(UnkStruct_08080268* w, void* a);
void func_0807FD10(UnkStruct_08080268* w, u8 n);
void func_0807FE30(UnkStruct_08080268* w, u8 n);
void sub_0807E4C8(UnkStruct_08080268* w, CardSlot* slots, s8 kind, s32 n);
u16 sub_0807E66C(CardSlot* out, u16* ids, u16 n, u8 kind);
Deck* sub_08083EFC(void);
void func_080A6F60(void** p);
void func_080A7180(u8 a);
void func_080A6EB4(u8* work, s32 id);
void func_080A5C60(u8* work, u16 card);
u8 func_0807C934(UnkStruct_02034AAC* p, void* a);
u8 func_0807D810(u8* work);
void func_0807D4B8(UnkStruct_02034AAC* p);
void func_08000D6C(void* a, void* b, void* c);
void func_08000D48(void* a, void* b, void* c);
u8 func_0808EC24(u8* work);
void TaskPoolDestroy(TaskPool* a);
u8 func_08006314(void);
void* AnimUpdate(AnimState* a);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void func_08000D20(void* a, void* b, void* c);
void func_08000D28(void* a, void* b);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_08006184(s32 a, s32 b);
void SetTaskUpdate(u8* p, u32 v);
u8 func_080A8C20(u8* work);
u8 func_080A86F4(u8* work, void* a);
u8 func_080A8BD8(u8* work, void* a);
void AnimInit(AnimState* a, s32 b, s32 c);
s32 func_0805F5A4(s32* a, s32* b);
s32* func_080E04E0(void);
u8 func_0809511C(ReloadGageWork* w, void* a);
u8 func_080954C4(ReloadGageWork* w, void* a);
u8 func_08089558(u8* work, void* a);
s32 func_0809AD98(UnkStruct_0809A02C* w, void* a);
void func_080062F4(u16 a, s32 b);
void func_08012304(void* a);
void func_0808E364(u8* work, u8 b);
void func_08088F24(void);
void func_08002A10(void* a, void* b);
void func_0805F1C0(s32* p, s32 v);
void func_0808D6C4(u8* work);
void func_0808CD48(u8* work);
u8 func_0800FF00(u16 n);
void func_08086A14(void);
void LoadPalette(void* src, void* dst, s32 size);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgSize(s32 a, s32 b);
void LoadBgMap(s32 bg, void* src, u16 size);
void eu_080059F4(s32 bg, void* map);
void TaskPoolInit(TaskPool* a, s32 count);
void SetBgMode2(void);
void SetBgAffine(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
u8 func_0809217C(UnkStruct_08093838* w, void* a);
void func_0808E344(void** p);
void func_080889DC(void);
u8 func_080897CC(u8* work, void* a);
void func_08081740(UnkStruct_08080268* w, u16 n);
void func_08081744(UnkStruct_08080268* w);
void func_08085DA0(u8 a);
void func_08080228(UnkStruct_08080268* w);
u8 func_0800FC5C(s32 a);
u8 func_080882DC(u8* work, void* a);
void EnableBg(s32 bg);
u8 func_080E8D00(void);
void* func_080E8D1C(s32 a);
void func_08093C44(u16 a, UnkStruct_08093838* w);
s32 func_08093E34(u16 a, UnkStruct_08093838* w);
u8 func_0808B30C(u8* work, void* a);
u8 func_08092234(UnkStruct_08093838* w, void* a);
void func_0808C90C(u8* work);
void func_0808C3DC(u8* work, u8 b);
void func_0808DB50(UnkStruct_0808DB04* w);
u8 func_0808A218(u8* work, void* a);
u8 func_0808A650(u8* work, void* a);
u8 func_08089D20(u8* work, void* a);
u8 func_0808B068(u8* work, void* a);
u8 func_08089EC0(u8* work, void* a);
u8 func_080870FC(u8* work, void* a);
void func_0808E7D8(u8* work);
s32 func_0808D828(u8* work);
u8 func_0809AB2C(UnkStruct_0809A02C* w);
extern u8 gUnk_09614318[];
extern s16 gUnk_09EE4BB8[];
extern s16 gUnk_09EE4BC2[];
void func_0808C940(UnkStruct_0808C940* w, s16 n);
void func_0808C974(UnkStruct_0808C940* w);
void func_08065AE0(TextSlot* p, s32 n);
void func_08096638(PrizeCardWork* w);
void SetObjMosaicSize(s32 a, s32 b);
void func_08006120(s32 a, s32 b);
void func_0800443C(u32 a, s32 b);
u8 func_080864A4(u8* work, void* a);
s32 func_0805F588(s32 a, s32 b);
void func_08096F08(void* a, void* b);
u8 func_08096288(PrizeCardWork* w, void* a);
u16 func_08093384(u8* work);
void* AllocObjTiles(s32 a, s32 b);
void func_08092A34(void);
void func_0808CC58(u16 a, u8 b);
void func_080AAA8C(u8* work, u8 b);
void func_080A8430(void);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_08090170(UnkStruct_0808E890* node);
u8 func_08096390(PrizeCardWork* w);
void* AnimGetGfx(AnimState* a);
void func_080A9968(u8* work);
void UpdatePlayTime(void);
void func_080B31A0(void);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void func_0806BA0C(s16 v, u8* out);
u8 Mapcard_1(MapcardWork* w, void* a);
extern u16 gBldAlpha;
extern u8* gUnk_02039DC8;
extern u8 gUnk_0908B1B4[];
extern u8 gUnk_09EEA164[];
extern u8 gUnk_09EEA148[];
void func_08006238(s32 a, u16 b, u16 c);
void func_080AA6D4(u8 a);
u8 func_0808A114(u8* work, void* a);
u8 func_0809FE14(void);
s32 func_080AC5E8(UnkStruct_02039DD4* g, u8 count, u8 kind, UnkStruct_080ABA80* arr, u8* flag);
u8 func_080ABEF8(u32* a, u8* b);
s32 func_080AD144(UnkStruct_02039DD4* g, u8 count, u8 kind, UnkStruct_080ABA80* arr, u8* flag, void* b);
s32 func_080AC140(s32 a);
void func_080AAEB0(u8* work, u16 index);
u8 func_080A207C(UnkStruct_080A1DAC* w);
u8 func_0807C5D8(UnkStruct_02034AAC* w, void* a);
u8 card_enemy_1(UnkStruct_02034AAC* p, void* a);
extern s32 gUnk_09034054[];
extern void* gUnk_09EF126C[];
void func_080063A8(void);
void func_0801C1A0(s32 a);
extern s32 gUnk_09035978[];
u8 EV_BG_EFFECT_1(UnkStruct_080A1DAC* w, void* a);
s32 func_0809CBD0(u8* work);
u8 func_0809ACDC(UnkStruct_0809A02C* w);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void func_080061E8(s32 a, u16 b);
void func_080A1BB8(UnkStruct_080A1C48* w, void** t);
void func_0809D124(UnkStruct_0809CE88* w);
u16 func_08096D0C(u16 a, s32 b);
u8 func_080DFBDC(FldPos* p);
s32 func_080DFF1C(FldPos* p);
u8 func_0809612C(PrizeCardWork* w, void* a);
u16 func_08096D48(u16 a, s32 b);
u8 func_080E924C(void);
void func_0809D1B0(UnkStruct_0809CE88* w);
MapcardWork* func_08000D90(void* a, void* b);
void func_0809CAC8(void* work);
u8 func_0800FCD8(s32 a, s32 b);
u8 func_0800FC90(s32 a);
void* func_080668F0(void);
void* func_08066904(void);
u16 func_0806692C(u8* s, u16* out);
void func_08066DC0(s32 a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g);
void func_0809D160(UnkStruct_0809CE88* w);
u8 func_080A25E0(u8* work, void* a);
void func_08006954(void);
u8 func_0809C4B0(u8* work, void* a);
void func_0807CC2C(UnkStruct_02034AAC* p);
u8 func_0807D194(UnkStruct_02034AAC* p, void* a);
u8 func_0807D584(UnkStruct_02034AAC* p, void* a);
u8 func_0807CBC0(UnkStruct_02034AAC* p, void* a);
u8 func_0807BD64(UnkStruct_02034AAC* p, void* a);
u8 card_reload_1(UnkStruct_02034AAC* p, void* a);
void func_080949A0(MapcardWork* w);
u8 func_08094A18(MapcardWork* w, void* a);
void func_08094CE4(MapcardWork* w);
extern u16 gBldCnt;
s32 func_08097A80(u8* work);
u8 AnimIsFinished(AnimState* a);
void SetBackdropColor(u16 r, u16 g, u16 b);
u8 func_080A36B0(UnkStruct_080A3F5C* w, void* a);
s32 func_080A22A4(u8* work);
void func_0807CD48(UnkStruct_02034AAC* p);
s32 func_08093AC8(u16 a);
u8 func_0809254C(UnkStruct_08093838* w, void* a);
u8 func_080A11CC(u8* work, void* a);
u8 func_0809F730(u8* work, void* a);
u8 func_0808B208(u8* work);
u8 func_0808AB48(u8* work, void* a);
u8 func_08087438(u8* work, void* a);
u8 func_080A0A44(u8* work, void* a);
u8 func_080928E4(UnkStruct_08093838* w, void* a);
u8 func_08092E2C(UnkStruct_08093838* w);
u8 func_0809438C(UnkStruct_08093838* w, void* a);
void func_0809C9A4(UnkStruct_0809C9A4* p);
void func_0809CA1C(u8* work);
u8 func_0809C620(u8* work, void* a);
u8 func_0809C9F4(UnkStruct_0809C9A4* p);
u8 func_080A2024(u8* work, void* a);
u8 func_08082224(UnkStruct_02034AAC* p, void* a);
u8 func_080827E0(UnkStruct_02034AAC* p, void* a);
void func_0800FB2C(s32 a);
CardSlot* func_08076674(UnkStruct_08080268* w, u8 slot, u16* n);
CardSlot* func_08076750(UnkStruct_08080268* w, u8 slot, u16* n);
void func_08083340(UnkStruct_02034AAC* p);
u16 func_08084FAC(u8 slot);
void LoadObjPaletteBank(u16 bank, void* src);
void* _08066468(s32 a);
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a);
u8 func_080A5034(UnkStruct_080A3F5C* w, void* a);
u8 func_0808A910(u8* work, void* a);
u8 func_0807D7B0(UnkStruct_02034AAC* p);
void func_0806C2C0(u8 a);
UnkStruct_080038C8* AllocObjPalette(s32 a);
void func_08003A70(void* a, void* b);
MapcardWork* ListPoolPrev(void* node);
s32 func_08093838(UnkStruct_08093838* w);
s32 func_080A5150(UnkStruct_080A3F5C* w);
s32 func_08098BA4(UnkStruct_08098BE8* w);
u8 func_08082348(UnkStruct_02034AAC* p, void* a);
u8 HCEffectName_1(UnkStruct_0809DF7C* w, void* a);
void func_080AAEEC(UnkStruct_0808C940* w, s16 n);
u8 func_0807CF4C(u8* work, void* a);
u8 func_080A3BB0(UnkStruct_080A3F5C* w, void* a);
void func_080A1E4C(u8* work);
u8 REV_COUNT_1(UnkStruct_08098CE4* w, void* a);
void func_0809D2B0(u8 a, u8 b, u8 c, u8* s);
void func_080A6BB4(u8* work);
void func_080A6FAC(UnkStruct_080A6FAC* w);
u8 func_080A5FF4(u8* work, void* a);
s32 func_080A6388(u8* work);
u8 func_080A63B8(u8* work, void* a);
u8 func_080A7300(u8* work);
u8 func_080A734C(u8* work);
u8 func_080A6A38(u8* work);
void func_080A69A0(u8* work);
UnkStruct_0808E890* func_080A6AE8(u8* work);
u8 func_08099330(u8* work);
void func_08078E34(UnkStruct_08080268* w, u8 b, u8 c);
void func_08078D98(u8* work, u8 b, u8 c);
u8 func_08076F80(u8* work, void* a);
u8 func_08082A64(UnkStruct_02034AAC* p, void* a);
u8 Reload_Card_1(UnkStruct_02034AAC* p, void* a);
u8 func_08081B70(UnkStruct_02034AAC* p, void* a);
void func_0806C34C(void);
u8 func_0809BE80(u8* work, void* a);
u8 func_0809075C(UnkStruct_02034AAC* p, void* a);
u8 func_08090808(u8* work, void* a);
void func_08090864(UnkStruct_02034AAC* p);
void func_08090B50(UnkStruct_02034AAC* p, void* a);
void SetBgBlend(s32 a, s32 b, s32 c);
u8 func_080A5D3C(UnkStruct_080A5D3C* w, void* a);
void func_08094DEC(MapcardWork* w);
void func_0800FDD0(s32 a);
u32 GetBgScreenBase(s32 bg);
void func_0807DAD0(UnkStruct_02034AAC* p);
void func_0807DE10(UnkStruct_02034AAC* p);
u8 func_080A6474(u8* work, void* a);
u8 RELOAD_CHILDREN_1(UnkStruct_08098BE8* w, void* a);
u8 func_080901B8(u8* p);
void func_080A6968(u8* work);
void func_080A7264(void** p);
void func_080A7210(u8* work);
void func_080838CC(void);
u8 func_08082AE4(UnkStruct_02034AAC* p);
u8 func_08082E0C(UnkStruct_02034AAC* p, void* a);
void func_0807E184(void);
u8 func_0807CE04(UnkStruct_02034AAC* p);
u8 func_0807D3A0(UnkStruct_02034AAC* p, void* a);
void func_08094E90(MapcardWork* w);
u8 func_0809CB78(u8* work, void* a);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
u8 func_08090940(UnkStruct_02034AAC* p);
u8 func_08090DB0(UnkStruct_02034AAC* p, void* a);
void func_0800FC14(s32 a);
void func_0808E2F0(UnkStruct_0808DB04* w);
u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a);
u8 func_080A3F5C(UnkStruct_080A3F5C* w, void* a);
u8 EnemyUsecard_1(UnkStruct_02034AAC* p, void* a);
u8 func_080A7914(u8* work, void* a);
void func_0808DD20(u8 a, u16 b);
s32 func_080AAB08(UnkStruct_080AAB08* w);
u8 func_08082FF0(u8* work);
void func_08082F24(UnkStruct_02034AAC* p);
void func_0808CBB4(u8 a, u8 b);
void func_080A9B84(UnkStruct_0808C940* w, u8 b);
void func_080A9F08(u8 a);
void func_080AA1F8(void);
u8 func_080A82E0(u8* work, void* a);
s32 func_08097DE4(u8* work);
u8 func_0809DE30(UnkStruct_0809DF7C* w, void* a);
u8 func_08090C3C(UnkStruct_02034AAC* p, void* a);
s32 func_08083ADC(u8* work);
void func_080836C4(UnkStruct_08095A5C* p, void* a, u8 b, s8 c);
void func_080A27EC(u8* work);
void func_08085658(u16 index);
void func_0807D0F4(UnkStruct_02034AAC* p);
void func_08082BF8(UnkStruct_02034AAC* p);
u8 func_0806BB44(s32 x, s32 y, s32 s, s32* d);
#ifdef VERSION_JP
u8 func_0806BDB8(s32 x, s32 y, s32 s, s32* d);
#endif
extern s32 gUnk_09033CA8[];
extern s32 gUnk_09033CB8[];
u8 func_080A4010(UnkStruct_080A3F5C* w, void* a);
u32 Sqrt(u32 a);

u8 func_080782AC(UnkStruct_02034AAC** p, u8 n) {
    u8 count;
    u8 i;

    i = 0;
    count = 0;

    for (; i < n; i++) {
        if (p[i]->unk_78 & 0x40) {
            count++;
        }
    }

    if (n == count) {
        return 1;
    }

    return 0;
}

void func_080782EC(void) {
    gBtlWork->unk_068 &= ~0x80;
    gBtlWork->unk_068 &= ~0x100;
    gBtlWork->unk_068 &= ~0x200;
    gBtlWork->unk_068 &= ~0x400;
}

void func_08078330(CardSlot* slots, s32 deckIndex) {
    u16* buf;
    vu16 zero;
    u16 n;
    u16 i;

    n = func_080858B8(deckIndex);
    buf = EwramAlloc(n * 2);
    zero = 0;
    CpuSet((void*)&zero, buf, n | 0x1000000);
    func_08085A58(deckIndex, buf);

    for (i = 0; i < n; i++) {
        slots[i].unk_06 = 0;
        slots[i].unk_07 = 0;
        slots[i].unk_0A = 0;
        slots[i].unk_00 = buf[i];
        slots[i].unk_04 = i;
        slots[i].unk_09 = 0;
    }

    if (deckIndex == 0) {
        slots[n].unk_06 = 0;
        slots[n].unk_07 = 0;
        slots[n].unk_0A = 0;
        slots[n].unk_00 = 0xFFFE;
        slots[n].unk_04 = n;
        slots[n].unk_09 = 0;
    }

    EwramFree(buf);
}

void func_080783C0(CardSlot* slots) {
    u16 n;
    u16 i;

    n = gUnk_09041FA0.unk_DC;

    for (i = 0; i < n; i++) {
        slots[i].unk_06 = 0;
        slots[i].unk_07 = 0;
        slots[i].unk_0A = 0;
        slots[i].unk_00 = gUnk_09041F70[gUnk_09041FA0.cards[i]];
        slots[i].unk_04 = i;
        slots[i].unk_09 = 0;
    }

    slots[n].unk_06 = 0;
    slots[n].unk_07 = 0;
    slots[n].unk_0A = 0;
    slots[n].unk_00 = 0xFFFE;
    slots[n].unk_04 = n;
    slots[n].unk_09 = 0;
}

void sub_0807842C(CardSlot* slots, u8 n) {
    CardSlot a;
    CardSlot b;
    u8 i;
    u8 x;
    u8 y;

    for (i = 0; i < n; i++) {
        x = GetRandom() % n;
        y = GetRandom() % n;

        if (x != y) {
            a = slots[x];
            b = slots[y];
            slots[x] = b;
            slots[y] = a;
        }
    }
}

void func_080784BC(u8* w, s32 mode) {
    u16 n = gUnk_09041FA0.unk_DC;

    switch (mode) {
    case 0: {
        CardSlot* slots;
        vu32 zero;
        u16 i;

        slots = EwramAlloc((n + 15) * sizeof(CardSlot));
        *(CardSlot**)&w[0x44] = slots;
        zero = 0;
        CpuSet((void*)&zero, slots, ((n + 15) * 3) | 0x05000000);

        for (i = 0; i < n + 1; i++) {
            (*(CardSlot**)&w[0x44])[i].unk_06 = 0;
            (*(CardSlot**)&w[0x44])[i].unk_07 = 0;
            (*(CardSlot**)&w[0x44])[i].unk_0A = 0;
            (*(CardSlot**)&w[0x44])[i].unk_08 = 0;
        }

        for (i = n + 1; i < n + 15; i++) {
            (*(CardSlot**)&w[0x44])[i].unk_06 = 1;
            (*(CardSlot**)&w[0x44])[i].unk_07 = 1;
            (*(CardSlot**)&w[0x44])[i].unk_0A = 1;
            (*(CardSlot**)&w[0x44])[i].unk_08 = 1;
        }

        func_080783C0(*(CardSlot**)&w[0x44]);
        *(u16*)&w[0x94] = 0;
        break;
    }
    case 1: {
        CardSlot* slot;
        u16* q;
        s32 k;
        vu32 zero;

        slot = EwramAlloc(sizeof(CardSlot));
        *(CardSlot**)&w[0x50] = slot;
        zero = 0;
        CpuSet((void*)&zero, slot, 3 | 0x05000000);
        (*(CardSlot**)&w[0x50])->unk_00 = 0x30FF;
        q = (u16*)&w[0x9A];
        k = 0xFFFF;
        *q = k;
        break;
    }
    }
}

void func_080785B8(u8* w, s32 mode) {
    u16 n = func_080858B8(mode);

    switch (mode) {
    case 0:
        if (n != 0) {
            CardSlot* slots;
            vu32 zero;
            u8 i;

            slots = EwramAlloc((n + 15) * sizeof(CardSlot));
            *(CardSlot**)&w[0x44] = slots;
            zero = 0;
            CpuSet((void*)&zero, slots, ((n + 15) * 3) | 0x05000000);

            for (i = 0; i < n + 1; i++) {
                (*(CardSlot**)&w[0x44])[i].unk_06 = 0;
                (*(CardSlot**)&w[0x44])[i].unk_00 = 0xFFFF;
                (*(CardSlot**)&w[0x44])[i].unk_07 = 0;
                (*(CardSlot**)&w[0x44])[i].unk_0A = 0;
                (*(CardSlot**)&w[0x44])[i].unk_08 = 0;
            }

            for (i = n + 1; i < n + 15; i++) {
                (*(CardSlot**)&w[0x44])[i].unk_06 = 1;
                (*(CardSlot**)&w[0x44])[i].unk_00 = 0xFFFF;
                (*(CardSlot**)&w[0x44])[i].unk_07 = 1;
                (*(CardSlot**)&w[0x44])[i].unk_0A = 1;
                (*(CardSlot**)&w[0x44])[i].unk_08 = 1;
            }

            func_08078330(*(CardSlot**)&w[0x44], 0);
            *(u16*)&w[0x94] = 0;
        } else {
            CardSlot* slot;
            vu32 zero;
            u16* q;
            s32 k;

            slot = EwramAlloc(sizeof(CardSlot));
            *(CardSlot**)&w[0x44] = slot;
            zero = 0;
            CpuSet((void*)&zero, slot, 3 | 0x05000000);
            (*(CardSlot**)&w[0x44])->unk_00 = 0xFF;
            q = (u16*)&w[0x94];
            k = 0xFFFF;
            *q = k;
        }
        break;
    case 1:
        if (n != 0) {
            CardSlot* slots;
            u8 i;

            slots = EwramAlloc(n * sizeof(CardSlot));
            *(CardSlot**)&w[0x50] = slots;

            for (i = 0; i < n; i++) {
                (*(CardSlot**)&w[0x50])[i].unk_06 = 0;
                (*(CardSlot**)&w[0x50])[i].unk_00 = 0xFFFF;
                (*(CardSlot**)&w[0x50])[i].unk_07 = 0;
                (*(CardSlot**)&w[0x50])[i].unk_0A = 0;
                (*(CardSlot**)&w[0x50])[i].unk_08 = 0;
            }

            func_08078330(*(CardSlot**)&w[0x50], 1);
            *(u16*)&w[0x9A] = 0;
        } else {
            CardSlot* slot;
            vu32 zero;
            u16* q;
            s32 k;

            slot = EwramAlloc(sizeof(CardSlot));
            *(CardSlot**)&w[0x50] = slot;
            zero = 0;
            CpuSet((void*)&zero, slot, 3 | 0x05000000);
            (*(CardSlot**)&w[0x50])->unk_00 = 0x30FF;
            q = (u16*)&w[0x9A];
            k = 0xFFFF;
            *q = k;
        }
        break;
    }
}


u16 func_08078754(UnkStruct_08078754* w, u8 n) {
    u16 count;
    u16 i;
    u16 max;

    max = w->unk_A8[n];
    count = 0;

    for (i = 0; i < max; i++) {
        if (w->unk_44[n][i].unk_06 == 0 && w->unk_44[n][i].unk_07 == 0 && w->unk_44[n][i].unk_08 == 0 && w->unk_44[n][i].unk_0A == 0) {
            count++;
        }
    }

    return count;
}

u16 func_080787B8(UnkStruct_08078754* w, u8 n) {
    u16 count;
    u16 i;
    u16 max;

    max = w->unk_A8[n];
    count = 0;

    for (i = 0; i < max; i++) {
        if (w->unk_44[n][i].unk_06 == 0 && w->unk_44[n][i].unk_07 == 0 && w->unk_44[n][i].unk_08 == 0 && w->unk_44[n][i].unk_0A == 0 && w->unk_44[n][i].unk_00 != 0xFFFE) {
            count++;
        }
    }

    if (gUnk_02034A98->unk_78 & 0x100000) {
        if (w->unk_B0[w->unk_B8] == 1) {
            count = 0;
        }
    }

    return count;
}

u16 func_0807885C(UnkStruct_08078754* w, u8 b) {
    CardSlot* c;
    u16 count;
    u16 i;
    u16 n;

    n = w->unk_A8[b];
    count = 0;

    for (i = 0; i < n; i++) {
        c = w->unk_44[b];

        if (c[i].unk_0A == 0) {
            if (c[i].unk_00 != 0xFFFE) {
                if (gCardDefs[c[i].unk_00 & CARD_ID_MASK].unk_2A == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}

void func_080788CC(UnkStruct_08078754* w, u8 b) {
    u8 i;

    for (i = 0; i < w->unk_A8[b]; i++) {
        if (w->unk_44[b][i].unk_07 == 0) {
            w->unk_44[b][i].unk_08 = 0;
        }
    }
}

void func_08078914(UnkStruct_08078754* w, u8 n) {
    u8 i;

    if (gGameState.flags & 8) {
        for (i = 0; i < w->unk_A8[n]; i++) {
            if (w->unk_44[n][i].unk_07 == 0) {
                w->unk_44[n][i].unk_08 = 0;
                w->unk_44[n][i].unk_06 = 0;
            }

            if (!(gBtlWork->unk_068 & 0x800000000000)) {
                if (w->unk_44[n][i].unk_09 == 1) {
                    w->unk_44[n][i].unk_0A = 0;
                    w->unk_44[n][i].unk_09 = 0;
                }
            }
        }
    } else {
        for (i = 0; i < w->unk_A8[n]; i++) {
            if (w->unk_44[n][i].unk_07 == 0) {
                w->unk_44[n][i].unk_08 = 0;
                w->unk_44[n][i].unk_06 = 0;
            }
        }
    }
}

void func_080789E4(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    CardSlot* c;
    u16 n;
    s32 z;

    z = 0;
    w->unk_C4[2] = z;
    func_08078914((UnkStruct_08078754*)w, w->unk_B8);

    if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) != z) {
        n = w->unk_A8[w->unk_B8] - 1;
        c = func_08076750(w, w->unk_B8, &n);

        if (c != 0) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = n;
            args.unk_0E = w->unk_B8;
            args.unk_04 = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->unk_00 == 0xFFFE) {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE499C, &args))[1];
            } else {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE496C, &args))[1];
            }

            p->unk_80 = p->unk_7C = gUnk_09033FA8[1];
            p->unk_98 = p->unk_94 = gUnk_09033FB8[0];
            p->unk_A4 = 1;
            p->unk_9C = 8;
            p->unk_A0 = 50;
            p->unk_78 |= 0x814;
            gUnk_02034A98 = p;
            w->unk_C4[2]++;
            w->unk_B0[w->unk_B8]++;
        }

        m4aSongNumStart(0x91);
    } else {
        args.unk_00 = &w->unk_54[w->unk_B8];
        args.unk_0C = 0xFFFF;
        args.unk_04 = (CardSlot*)w->unk_44[w->unk_B8];
        args.unk_0E = w->unk_B8;
        p = ((UnkStruct_02034AAC**)TaskCreate(w, &gUnk_09EE496C[0x18], &args))[1];
        p->unk_80 = p->unk_7C = gUnk_09033FA8[1];
        p->unk_98 = p->unk_94 = gUnk_09033FB8[0];
        p->unk_A0 = 50;
        p->unk_78 |= 0x806;
        gUnk_02034A98 = p;
    }

    z = w->unk_B8;

    if (w->unk_B0[z] > 0) {
        if (w->unk_BC[z] == 0) {
            func_080991CC(w, &w->unk_B8, &w->unk_B0[z], &w->unk_BC[z], 1);
        }
    }

    func_0807BB04();
}

void func_08078BB4(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node;
    CardSlot* c;
    s32 z;

    c = (CardSlot*)w->unk_44[0];

    if (gUnk_02039DD4->unk_0BC == 0x28F) {
        c[(s16)w->unk_A8[0] - 5].unk_00 = 0x28F;
        c[(s16)w->unk_A8[0] - 5].unk_04 = (s16)w->unk_A8[0] - 5;
        c[(s16)w->unk_A8[0] - 5].unk_06 = 0;
        c[(s16)w->unk_A8[0] - 5].unk_07 = 0;
        c[(s16)w->unk_A8[0] - 5].unk_0A = 0;
        c[(s16)w->unk_A8[0] - 5].unk_08 = 0;
        gUnk_02039DD4->unk_0BC = 0x3B6;
    } else {
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_00 = gUnk_02039DD4->unk_0B8;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_04 = gUnk_02039DD4->unk_0DA[0] + ((s16)w->unk_A8[0] - 14);
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_06 = 0;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_07 = 0;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_0A = 0;
        c[(s16)w->unk_A8[0] - 14 + gUnk_02039DD4->unk_0DA[0]].unk_08 = 0;
        gUnk_02039DD4->unk_0B8 = 0x3B6;
        gUnk_02039DD4->unk_0DA[0]++;
    }

    w->unk_B0[0]++;
    w->unk_94[0] = w->unk_A8[0] - 1;

    if (w->unk_B8 == 0) {
        w->unk_94[0] = *(u16*)&gUnk_02034A98->unk_3C[8];
        node = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[0]);

        while (node != 0) {
            node->unk_A1 = 7;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }

        TaskPoolUpdate(w);
        func_0807682C(w, 0);
        z = w->unk_B8;

        if (w->unk_BC[z] == 0) {
            func_080991CC(w, &w->unk_B8, &w->unk_B0[z], &w->unk_BC[z], 1);
        }
    }
}

void func_08078D98(u8* work, u8 kind, u8 c) {
    UnkStruct_02034AAC* node;

    m4aSongNumStart(0x79);
    node = (UnkStruct_02034AAC*)ListPoolFirst(&work[kind * 16 + 0x54]);

    while (node != 0) {
        switch (node->unk_A4) {
        case 0:
            node->unk_A4++;
            break;
        case 1:
            node->unk_A4--;
            break;
        case 2:
            node->unk_A4--;
            break;
        }

        node->unk_80 = gUnk_09033FA8[node->unk_A4];
        node->unk_9C = c;
        node->unk_78 &= ~4;

        if (node->unk_A4 == 1) {
            gUnk_02034A98 = node;
            node->unk_78 |= 4;
        }

        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
    }
}

void func_08078E34(UnkStruct_08080268* w, u8 b, u8 c) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    UnkStruct_02034AAC* q;
    CardSlot* slot;
    s16 prev;
    s32 v;
    s32 cur;
    u16 n;

    m4aSongNumStart(0x79);
    gUnk_02034A98->unk_78 &= ~4;
    prev = *(u16*)&gUnk_02034A98->unk_3C[8];
    p = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        if (p->unk_A4 == 0) {
            gUnk_02034A98 = p;
            break;
        }

        p = (UnkStruct_02034AAC*)ListPoolNext(&p->unk_64);
    }

    gUnk_02034A98->unk_78 |= 0x804;
    cur = *(s16*)&gUnk_02034A98->unk_3C[8];
    n = cur - 1;

    if ((s16)n < 0) {
        n = w->unk_A8[b] - 1;
    }

    slot = func_08076750(w, b, &n);

    if (slot != 0) {
        v = (s16)n;

        if (v != cur && v != prev) {
            args.unk_00 = &w->unk_54[b];
            args.unk_0C = n;
            args.unk_0E = b;
            args.unk_04 = slot;
            args.unk_0F = w->unk_9C[b];

            if (slot->unk_00 == 0xFFFE) {
                q = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE499C, &args))[1];
            } else {
                q = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE496C, &args))[1];
            }

            q->unk_80 = q->unk_7C = gUnk_09033FA8[3];
            q->unk_98 = q->unk_94 = gUnk_09033FB8[0];
            q->unk_A4 = 3;
            q->unk_A0 = 60;
            q->unk_78 |= 0x800;
        }
    }

    p = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        p->unk_A4++;

        if (p->unk_A4 > 3) {
            p->unk_A4 = 0;
        }

        p->unk_A0 += 4;
        p->unk_80 = gUnk_09033FA8[p->unk_A4];
        p->unk_9C = c;
        p = (UnkStruct_02034AAC*)ListPoolNext(&p->unk_64);
    }

    gUnk_02034A98->unk_A0 = 50;
}
void func_08078FFC(UnkStruct_08080268* w, u8 b) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    UnkStruct_02034AAC* q;
    CardSlot* c;
    s16 prev;
    s32 v;
    s32 cur;
    u16 n;

    m4aSongNumStart(0x79);
    gUnk_02034A98->unk_78 &= ~4;
    prev = *(u16*)&gUnk_02034A98->unk_3C[8];
    p = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        if (p->unk_A4 == 2) {
            gUnk_02034A98 = p;
            break;
        }

        p = (UnkStruct_02034AAC*)ListPoolNext(&p->unk_64);
    }

    gUnk_02034A98->unk_78 |= 0x804;
    cur = *(s16*)&gUnk_02034A98->unk_3C[8];
    n = cur + 1;

    if ((s16)n >= (s16)w->unk_A8[b]) {
        n = 0;
    }

    c = func_08076674(w, b, &n);

    if (c != 0) {
        v = (s16)n;

        if (v != cur && v != prev) {
            args.unk_00 = &w->unk_54[w->unk_B8];
            args.unk_0C = n;
            args.unk_0E = b;
            args.unk_04 = c;
            args.unk_0F = w->unk_9C[b];

            if (c->unk_00 == 0xFFFE) {
                q = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE499C, &args))[1];
            } else {
                q = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE496C, &args))[1];
            }

            q->unk_80 = q->unk_7C = gUnk_09033FA8[3];
            q->unk_98 = q->unk_94 = gUnk_09033FB8[0];
            q->unk_A4 = 3;
            q->unk_A0 = 60;
            q->unk_78 |= 0x800;
        }
    }

    p = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[b]);

    while (p != 0) {
        p->unk_A4--;

        if (p->unk_A4 < 0) {
            p->unk_A4 = 3;
        }

        p->unk_A0 += 4;
        p->unk_80 = gUnk_09033FA8[p->unk_A4];
        p->unk_9C = 4;
        p = (UnkStruct_02034AAC*)ListPoolNext(&p->unk_64);
    }

    gUnk_02034A98->unk_A0 = 50;
}

void func_080791C0(void) {
    if (gBtlWork->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 0x30) {
            if (gUnk_02034A98->unk_A5 != 0) {
                gUnk_02034A98->unk_A5 -= gUnk_02039DD4->unk_0C2;
            }

            gUnk_02039B9C->unk_0F8--;
        }
    }
}

void func_08079218(UnkStruct_08080268* w) {
    u8 dmg = gUnk_02039DD4->unk_0C2;
    u8 i;

    if (gBtlWork->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 0x30) {
            if (w->unk_BA != 0) {
                for (i = 0; i < w->unk_B9; i++) {
                    UnkStruct_02034AAC* c = w->unk_28[i];
                    s32 t;

                    if (c->unk_A5 > dmg) {
                        c->unk_A5 -= dmg;
                        break;
                    }

                    t = dmg - c->unk_A5;
                    c->unk_A5 = 0;
                    dmg = t;
                }
            }

            gUnk_02039B9C->unk_0F8--;
        }
    }
}

u16 func_080792AC(void) {
    u16 i;

    i = GetRandom() % 47;

    return gUnk_09EE48F4[i];
}

u16 func_080792D0(u16* p) {
    u16 v;
    u16 i;

    i = *p;
    v = gUnk_09EE48F4[i];
    *p = i + 1;

    if (*p > 46) {
        *p = 0;
    }

    return v;
}

INCLUDE_ASM("card/func_080792F4.s");
INCLUDE_ASM("card/func_08079600.s");
INCLUDE_ASM("card/func_08079B3C.s");
s32 func_08079ECC(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    u16 id;
    UnkStruct_02034AAC* e;
    CardSlot* c;
    u8 found;
    u32 prev;
    u32 other;

    if (gUnk_02034A98->unk_78 & 2) {
        return 1;
    }

    gBtlWork->unk_068 |= 0x20000000000000;
    m4aSongNumStart(120);
    (*(CardSlot**)gUnk_02034A98->unk_3C)->unk_0A = 1;
    gUnk_02034A98->unk_A1 = 11;
    (*(CardSlot**)gUnk_02034A98->unk_3C)->unk_08 = 1;
    gUnk_02034A98->unk_A0 = 50;
    gUnk_02034A98->unk_78 &= ~0x40;
    w->unk_B0[w->unk_B8]--;
    other = 0xFF;
    id = other;
    found = 0;
    gUnk_02034A98 = 0;

    e = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]);

    while (e != 0) {
        if (e->unk_A4 == 2) {
            e->unk_A4--;
            e->unk_9C = 4;
            e->unk_80 = gUnk_09033FA8[e->unk_A4];
            e->unk_A0 = 50;
            gUnk_02034A98 = e;
            found = 1;
            break;
        }

        e = (UnkStruct_02034AAC*)ListPoolNext(&e->unk_64);
    }

    if (gUnk_02034A98 == 0) {
        e = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (e != 0) {
            if (e->unk_A4 == 0) {
                e->unk_A4++;
                e->unk_9C = 4;
                e->unk_80 = gUnk_09033FA8[e->unk_A4];
                e->unk_A0 = 50;
                gUnk_02034A98 = e;
                break;
            }

            e = (UnkStruct_02034AAC*)ListPoolNext(&e->unk_64);
        }
    }

    if (found) {
        prev = *(u16*)&gUnk_02034A98->unk_3C[8];
        id = prev + 1;

        if (id >= (s16)w->unk_A8[w->unk_B8]) {
            id = 0;
        }

        for (e = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]); e != 0; e = (UnkStruct_02034AAC*)ListPoolNext(&e->unk_64)) {
            if (e->unk_A4 == 0) {
                other = *(u16*)&e->unk_3C[8];
                break;
            }
        }

        c = func_08076674(w, w->unk_B8, &id);

        if (c != 0 && id != prev && id != other) {
            args.unk_00 = w->unk_54[w->unk_B8];
            args.unk_0C = id;
            args.unk_0E = w->unk_B8;
            args.unk_04 = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->unk_00 == 0xFFFE) {
                e = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE499C, &args))[1];
            } else {
                e = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE496C, &args))[1];
            }

            e->unk_7C = gUnk_09033FA8[3];
            e->unk_98 = e->unk_94 = gUnk_09033FB8[0];
            e->unk_A4 = 2;
            e->unk_80 = gUnk_09033FA8[2];
            e->unk_A0 = 60;
            e->unk_9C = 4;
            e->unk_78 |= 0x800;
        }
    }

    gUnk_02034A98->unk_78 |= 4;
    gUnk_02039DD4->unk_0DC--;
    return 1;
}
INCLUDE_ASM("card/func_0807A188.s");

void func_0807A620(u8* work) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 < 5 || node->unk_A1 > 6) {
                node->unk_A1 = 7;
            }

            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }

    if (gUnk_02034A98->unk_78 & 0x1000000) {
        gUnk_02034A98->unk_78 |= 0x4000;
    }
}

void func_0807A684(u8* work) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(&work[i * 16 + 0x54]);

        while (node != 0) {
            if (node->unk_A1 == 0) {
                node->unk_A1 = 7;
            }

            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }
}

void func_0807A6C8(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 |= 0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(w->unk_54[i]);

        while (node != 0) {
            node->unk_78 |= 0x20;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }

    gBtlWork->unk_068 &= ~0x20;
    gUnk_02039DD4->unk_0EA = 1;
    w->unk_C9 = 0;
}

void func_0807A75C(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node;
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 &= ~0x20;
    }

    for (i = 0; i < 4; i++) {
        node = (UnkStruct_02034AAC*)ListPoolFirst(w->unk_54[i]);

        while (node != 0) {
            node->unk_78 &= ~0x20;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    }

    gUnk_02039DD4->unk_0CC = 0;
    gBtlWork->unk_068 |= 0x20;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    w->unk_C9 = 1;
}

#ifdef NON_MATCHING
void func_0807A80C(UnkStruct_08080268* w) {
    UnkStruct_080ABA80 arr;
    u8 flag;
    u16 total;
    u8 i;
    u8 n;
    u8 skip;
    s32 r;

    n = w->unk_BA;
    total = 0;
    arr = gUnk_09033FD0;

    if ((s16)gUnk_02039DD4->unk_0C2 > n && n != 0) {
        return;
    }

    skip = 0;

    if (gBtlWork->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 == 2 && gUnk_02039DD4->unk_000[0]->unk_48->unk_2A == 0 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

        if (gUnk_02039B9C->unk_0F4 == 20 && gUnk_02039DD4->unk_000[0]->unk_48->unk_24 == 22 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

        if (gUnk_02039B9C->unk_0F4 == 29 && gUnk_02039DD4->unk_000[0]->unk_48->unk_2A == 2 &&
            gUnk_02039DD4->unk_0E2 == 0) {
            skip = 1;
        }

        if (skip != 0) {
            return;
        }
    }

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
    }

    gBtlWork->unk_068 |= 0x800000;

    if ((s16)gUnk_02039DD4->unk_0C2 != n) {
        if (n == 0) {
            if ((s16)gUnk_02039DD4->unk_0C2 > 9) {
                gBtlWork->unk_1CA = 9;
            } else {
                gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2;
            }
        } else {
            if (n - (s16)gUnk_02039DD4->unk_0C2 > 9) {
                gBtlWork->unk_1CA = 9;
            } else {
                gBtlWork->unk_1CA = n - *(u8*)&gUnk_02039DD4->unk_0C2;
            }
        }

        if (!(gGameState.flags & 0x100) && func_0807BA54() != 0 && !(gBtlWork->unk_068 & 0x800000000000)) {
            gUnk_02039DD4->unk_0EE = 1;
        }

        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x8000000;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 &= ~0x20;
        func_08079218(w);

        if (gBtlWork->unk_068 & 0x4000) {
            r = func_080AD144(&w->unk_28, w->unk_B9, w->unk_BA, &arr, &flag, 0);
        } else {
            r = func_080AC5E8(&w->unk_28, w->unk_B9, w->unk_BA, &arr, flag);
        }

        if ((u16)r == 52 && (gBtlWork->unk_068 & 0x4800)) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if ((*(CardSlot**)gUnk_02039DD4->unk_000[i]->unk_3C)->unk_08 == 1) {
                    (*(CardSlot**)gUnk_02039DD4->unk_000[i]->unk_3C)->unk_0A = 1;
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x80000000;
                }
            }
        }

        for (i = 0; i < w->unk_B9; i++) {
            total += w->unk_28[i]->unk_A5;
        }

        gUnk_02039DD4->unk_0C2 = total;
        gUnk_02039DD4->unk_0D0 = w->unk_B9;

        for (i = 0; i < w->unk_B9; i++) {
            gUnk_02039DD4->unk_000[i] = w->unk_28[i];
            w->unk_28[i]->unk_78 |= 0x2000;

            if (w->unk_28[i]->unk_48->unk_1E & 2) {
                (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 1;
            }
        }

        gBtlWork->unk_0A4 = 1;
        gUnk_02039DD4->unk_0E1 = 1;
        m4aSongNumStart(0x213);
        return;
    }

    gBtlWork->unk_1CA = 0;
    func_08079218(w);
    m4aSongNumStart(204);
    gBtlWork->unk_068 &= ~0x80;
    gBtlWork->unk_068 &= ~0x20;
    gBtlWork->unk_068 &= ~0x400;
    gUnk_02039DD4->unk_0E1 = 0;
    gBtlWork->unk_0A4 = 1;
}
#else
INCLUDE_ASM("card/func_0807A80C.s");
#endif

#ifdef NON_MATCHING
void func_0807ABC8(UnkStruct_08080268* w) {
    UnkStruct_02034AAC** q;
    UnkStruct_02034AAC* p;
    u64 flags;
    u8 i;
    u8 n;

    for (i = 0, n = 0; i < w->unk_B9; i++) {
        if (w->unk_28[i]->unk_78 & 0x40) {
            n++;
        }
    }

    if (n < w->unk_B9) {
        return;
    }

    gUnk_02039DD4->unk_0C0 = 0;
    gUnk_02039DD4->unk_0E3 = 0;
    w->unk_C4[1] = 0;
    flags = gBtlWork->unk_068;

    if ((flags & 0x80) == 0) {
        gUnk_02039DD4->unk_0D0 = w->unk_B9;

        for (i = 0; i < w->unk_B9; i++) {
            q = gUnk_02039DD4->unk_000;
            q += i;
            *q = w->unk_28[i];
            w->unk_28[i]->unk_A0 = i * 4 + 50;

            if (w->unk_28[i]->unk_48->unk_1E & 2) {
                (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 1;
            }

            w->unk_28[i]->unk_78 |= 0xA000;
        }

        gUnk_02039DD4->unk_0C2 = w->unk_BA;
        gBtlWork->unk_0A4 = 1;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x8000000;
        gUnk_02039DD4->unk_0E1 = 1;
    } else {
        if (gBtlWork->unk_0A4 == 1) {
            return;
        }

        if ((flags & 0x20) == 0) {
            func_0807A80C(w);
            gBtlWork->unk_068 |= 0x8000000;
        } else {
            func_0807A80C(w);
            gBtlWork->unk_068 |= 0x8000000;
        }
    }

    for (i = 0; i < w->unk_B9; i++) {
        (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_07 = 0;

        if (w->unk_28[i]->unk_48->unk_1E & 2) {
            (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 1;
        } else if (i == 0 && gBtlWork->unk_0F4 != 15) {
            (*(CardSlot**)w->unk_28[0]->unk_3C)->unk_0A = 1;
        }
    }

    if (func_0807885C((UnkStruct_08078754*)w, 0) == 0) {
        for (i = 0; i < w->unk_B9; i++) {
            if (w->unk_28[i]->unk_46 == 0) {
                (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 0;
                break;
            }
        }
    }

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_1C[i] = w->unk_28[i];
        w->unk_28[i]->unk_A1 = 5;
        w->unk_28[i] = 0;
    }

    func_0807BC08();
    w->unk_B9 = 0;
    gUnk_02039DD4->unk_0DE = 0;
    w->unk_BA = 0;
    func_0807AE78((UnkStruct_08078754*)w);
    w->unk_C4[1] = 0;
}

#else
INCLUDE_ASM("card/func_0807ABC8.s");
#endif

void func_0807AE78(UnkStruct_08078754* w) {
    CardSlot* c;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++) {
        c = w->unk_44[i];

        for (j = 0; j < w->unk_A8[j]; j++) {
            c[j].unk_07 = 0;
        }
    }
}

u8 func_0807AEC4(u8* work, u8 n) {
    UnkStruct_02034AAC* node;
    u8 count;

    count = 0;
    node = (UnkStruct_02034AAC*)ListPoolFirst(&work[n * 16 + 0x54]);

    while (node != 0) {
        count++;
        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
    }

    return count;
}

u8 func_0807AEF4(u8* work, u8 kind) {
    UnkStruct_02034AAC* node;
    u8 count;

    count = 0;
    node = (UnkStruct_02034AAC*)ListPoolFirst(&work[kind * 16 + 0x54]);

    while (node != 0) {
        if ((node->unk_78 & 0x1000002) == 0) {
            if (kind == 2) {
                count++;
            } else if (node->unk_48->unk_2A == kind) {
                count++;
            }
        }

        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
    }

    return count;
}

void func_0807AF40(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node = 0;

    if (!(gUnk_02034A98->unk_78 & 0x40)) {
        return;
    }

    m4aSongNumStart(103);

    if (gBtlWork->unk_068 & 0x1000000) {
        gBtlWork->unk_068 &= ~0x1000000;
    }

    w->unk_BC[w->unk_B8] = 0;

    if (w->unk_C0[w->unk_B8] == 0) {
        w->unk_94[w->unk_B8] = *(u16*)&gUnk_02034A98->unk_3C[8];
        node = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_A3 = 4;
            node->unk_98 = gUnk_09033FB8[3];
            node->unk_A1 = 7;
            node->unk_78 &= ~4;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    } else {
        w->unk_34[w->unk_B8] = gUnk_02034A98;
        gUnk_02034A98->unk_98 = gUnk_09033FB8[3];
        gUnk_02034A98->unk_A3 = 4;
        gUnk_02034A98->unk_78 &= ~4;
    }

    switch (w->unk_B8) {
    case 0:
        w->unk_B8 = 3;
        break;
    case 3:
        w->unk_B8 = 0;
        break;
    }

    if (w->unk_C0[w->unk_B8] == 0) {
        func_0807682C(w, (u8)w->unk_B8);
        node = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_98 = gUnk_09033FB8[0];
            node->unk_94 = gUnk_09033FB8[0];
            node->unk_A3 = 1;
            node->unk_9C = 1;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }

        if (w->unk_BC[w->unk_B8] == 0) {
            if (w->unk_B8 != 0) {
                if (w->unk_B0[w->unk_B8] > 0) {
                    func_080991CC(w, &w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
                }
            } else {
                if (w->unk_B0[w->unk_B8] > 1) {
                    func_080991CC(w, &w->unk_B8, &w->unk_B0[w->unk_B8], &w->unk_BC[w->unk_B8], 1);
                }
            }
        }
    } else {
        gUnk_02034A98 = w->unk_34[w->unk_B8];
        gUnk_02034A98->unk_98 = gUnk_09033FB8[0];
        gUnk_02034A98->unk_94 = gUnk_09033FB8[1];
        gUnk_02034A98->unk_A3 = 1;
        gUnk_02034A98->unk_9C = 1;
        gUnk_02034A98->unk_78 |= 4;
    }

    gUnk_02039DD4->unk_0D2 = w->unk_B8;
}

#ifdef NON_MATCHING
void func_0807B16C(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* node;
    s32 z;

    z = 0;
    m4aSongNumStart(103);

    if (gBtlWork->unk_068 & 0x1000000) {
        gBtlWork->unk_068 &= ~0x1000000;
    }

    w->unk_BC[w->unk_B8] = z;
    z = w->unk_B8;

    if (w->unk_C0[z] == 0) {
        w->unk_94[z] = *(u16*)&gUnk_02034A98->unk_3C[8];
        node = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_A3 = 12;
            node->unk_98 = gUnk_09033FB8[1];
            node->unk_A1 = 7;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }
    } else {
        w->unk_34[z] = gUnk_02034A98;
        gUnk_02034A98->unk_98 = gUnk_09033FB8[3];
        gUnk_02034A98->unk_A3 = 12;
        gUnk_02034A98->unk_78 &= ~4;
    }

    switch (w->unk_B8) {
    case 0:
        w->unk_B8 = 2;
        break;
    case 1:
        w->unk_B8 = 0;
        break;
    case 2:
        w->unk_B8 = 3;
        break;
    case 3:
        w->unk_B8 = 1;
        break;
    }

    if (w->unk_C0[w->unk_B8] == 0) {
        func_0807682C(w, (u8)w->unk_B8);
        node = (UnkStruct_02034AAC*)ListPoolFirst(&w->unk_54[w->unk_B8]);

        while (node != 0) {
            node->unk_A3 = 12;
            node->unk_98 = gUnk_09033FB8[0];
            node->unk_94 = gUnk_09033FB8[0];
            node->unk_9C = 12;
            node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_64);
        }

        z = w->unk_B8;

        if (w->unk_BC[z] == 0 && w->unk_B0[z] > 0) {
            func_080991CC(w, &w->unk_B8, &w->unk_B0[z], &w->unk_BC[z], 1);
        }
    } else {
        gUnk_02034A98 = w->unk_34[w->unk_B8];
        gUnk_02034A98->unk_98 = gUnk_09033FB8[0];
        gUnk_02034A98->unk_94 = gUnk_09033FB8[1];
        gUnk_02034A98->unk_A3 = 12;
        gUnk_02034A98->unk_9C = 12;
        gUnk_02034A98->unk_78 |= 4;
    }

    gUnk_02039DD4->unk_0D2 = w->unk_B8;
}
#else
INCLUDE_ASM("card/func_0807B16C.s");
#endif

void func_0807B378(u8* p) {
    s16* c;

    switch ((s8)p[0xB8]) {
    case 0:
        (*(s16*)&p[0x9C])++;
        break;
    case 1:
        (*(s16*)&p[0x9E])++;
        break;
    case 2:
        break;
    }

    c = (s16*)&p[0x9C];
    c += (s8)p[0xB8];

    if (*c > 2) {
        *c = 2;
    }
}

void func_0807B3C4(void) {
}

u8 func_0807B3C8(void) {
    u8 result;

    if (gUnk_02039DD4 == 0) {
        result = 0xFF;
    } else {
        result = gUnk_02039DD4->unk_0D2;
    }

    return result;
}

u8 func_0807B3E0(void) {
    u8 result;

    if (gUnk_02039DD4 == 0) {
        result = 0;
    } else {
        result = gUnk_02039DD4->unk_0D3;
    }

    return result;
}

u8 func_0807B3F8(void) {
    if (gUnk_02039DD4 != 0) {
        return gUnk_02039DD4->unk_0D5;
    }

    return 0;
}

void func_0807B410(void* pool) {
    UnkStruct_0807B410* t;
    u32 v;

    t = (UnkStruct_0807B410*)ListPoolFirst(&gBtlWork->unk_080);

    while (t != 0) {
        v = t->unk_00;

        switch (v) {
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
            TaskCreate(pool, gTaskDescBosscard, &v);
            return;
        }

        t = (UnkStruct_0807B410*)ListPoolNext(&t->unk_B8);
    }
}

void func_0807B458(void) {
}

void func_0807B45C(void) {
    gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
}

#ifndef VERSION_EU
void func_0807B478(UnkStruct_02034AAC* w) {
    u32* p;
    u16* c;
    u16* q;
    u16* q2;

    if (gBtlWork->unk_068 & 0x4800) {
        if (gUnk_02039B9C->unk_0F4 != 41) {
            gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
        } else {
            gBtlWork->unk_0F4 = 0;
            gUnk_02039DD4->unk_0CC = 0;
        }

        p = &gBtlWork->unk_0F4;

        if (*p == 41) {
            gUnk_02039DD4->unk_0CE = 0;
            gUnk_02039B9C->unk_0F4 = 0;
            gUnk_02039B9C->unk_0F8 = 0;
            gBtlWork->unk_0F4 = 0;
            gBtlWork->unk_0F8 = 0;
        }

        c = &gUnk_02039DD4->unk_0CC;

        if (*c == 45) {
            if (gUnk_02039B9C->unk_0F4 != 0) {
                gBtlWork->unk_0F4 = gUnk_02039B9C->unk_0F4;
                gUnk_02039DD4->unk_0CC = gUnk_02039DD4->unk_0CE;
            } else {
                gBtlWork->unk_0F4 = 0;
                gUnk_02039DD4->unk_0CE = 0;
            }
        }

        if (gBtlWork->unk_0F4 == 47) {
            q2 = &w->unk_9C;
            q = q2;
            *q++ = 2;
            *q = 2;
        }
    } else {
        if (gUnk_02039DD4->unk_0CC != 41 && gUnk_02039DD4->unk_0CC != 45) {
            gBtlWork->unk_0F4 = gUnk_02039DD4->unk_0CC;
        } else {
            gBtlWork->unk_0F4 = 0;
        }
    }
}
#else
INCLUDE_ASM("card/func_0807B478.s");
#endif

u8 func_0807B578(UnkStruct_08080268* w, void* a) {
    s16 v;

    v = w->unk_B0[w->unk_B8];

    if (v > 2) {
        if (gUnk_02034A98->unk_78 & 0x40) {
            func_08078E34(w, w->unk_B8, 2);
        }
    } else if (v > 1) {
        if (gUnk_02034A98->unk_78 & 0x40) {
            func_08078D98((u8*)w, w->unk_B8, 2);
        }
    }

    w->unk_A6--;

    if (w->unk_A6 <= 0) {
        SetTaskUpdate(a, (void*)func_08076F80);
    }

    TaskPoolUpdate(w);
    TaskPoolUpdate(&gUnk_02039DD4->unk_09C);
    return 1;
}

u8 func_0807B60C(void) {
    if (gBtlWork->unk_0F4 == 38) {
        if (gUnk_02034A98->unk_48->unk_2A != 1) {
            return 1;
        }

        if (!(gUnk_02034A98->unk_48->unk_1E & 4)) {
            return 1;
        }

        return 0;
    } else if (gBtlWork->unk_0F4 == 39) {
        if (gUnk_02034A98->unk_48->unk_2A != 1) {
            return 1;
        }

        if (gUnk_02034A98->unk_48->unk_1E & 4) {
            return 1;
        }

        return 0;
    }

    return 1;
}

void func_0807B668(UnkStruct_02039DD4* p) {
    p->unk_040 = AllocObjTiles(0x280, 0);
    func_08002A10(p->unk_040, gUnk_0908B1B4);
    AnimInit(&p->unk_064, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&p->unk_064, 0, 1);
    p->unk_094 = AnimGetGfx(&p->unk_064);
    p->unk_050 = AllocObjTiles(0x100, 0);
    func_08002A10(p->unk_050, gUnk_0908C3CE);
    AnimInit(&p->unk_07C, gUnk_09EEA198, gUnk_09EEA180);
    AnimStart(&p->unk_07C, 0, 1);
    p->unk_098 = AnimGetGfx(&p->unk_07C);
}

void func_0807B6F4(void) {
    UnkStruct_02039DD4* p;

    p = gUnk_02039DD4;
    p->unk_0F4 = 0;
    p->unk_0FC = 0;
    p->unk_100 = 4;
    p->unk_104 = 2;
    p->unk_108[0] = 0;
}

void func_0807B728(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 0) {
                    if (c[i].unk_0A == 0) {
                        c[i].unk_06 = 0;
                    }
                } else if (t == 1) {
                    if (c[i].unk_0A == 1 || c[i].unk_07 == 1 || c[i].unk_08 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B7A4(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 0) {
                    c[i].unk_0A = 0;
                    c[i].unk_06 = 0;
                } else if (t != 2) {
                    if (c[i].unk_08 == 1 || c[i].unk_0A == 1 || c[i].unk_07 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B81C(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 0) {
                    c[i].unk_06 = 0;
                    c[i].unk_0A = 0;
                } else if (t != 2) {
                    if (c[i].unk_08 == 1 || c[i].unk_0A == 1 || c[i].unk_07 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B894(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 1) {
                    if (c[i].unk_0A == 0) {
                        c[i].unk_06 = 0;
                    }
                } else if (t != 2) {
                    if (c[i].unk_0A == 1 || c[i].unk_07 == 1 || c[i].unk_08 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B910(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;
    u32 id;
    u8 t;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        id = c[i].unk_00;

        if (id != 0xFFFF) {
            if (id != 0xFFFE) {
                t = gCardDefs[id & CARD_ID_MASK].unk_2A;

                if (t == 1) {
                    c[i].unk_06 = 0;
                    c[i].unk_0A = 0;
                } else if (t != 2) {
                    if (c[i].unk_08 == 1 || c[i].unk_0A == 1 || c[i].unk_07 == 1) {
                        c[i].unk_06 = 1;
                    }
                }
            }
        }
    }
}

void func_0807B98C(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        if (c[i].unk_00 != 0xFFFF) {
            if (c[i].unk_00 != 0xFFFE) {
                if (gCardDefs[c[i].unk_00 & CARD_ID_MASK].unk_2A != 2) {
                    c[i].unk_06 = 0;
                    c[i].unk_0A = 0;
                }
            }
        }
    }
}

void func_0807B9EC(UnkStruct_08078754* w) {
    CardSlot* c;
    s32 i;

    c = w->unk_44[0];

    for (i = 0; i < w->unk_A8[0]; i++) {
        if (c[i].unk_00 != 0xFFFF) {
            if (c[i].unk_00 != 0xFFFE) {
                if (gCardDefs[c[i].unk_00 & CARD_ID_MASK].unk_1E & 2) {
                    if (c[i].unk_0A == 0) {
                        c[i].unk_09 = 1;
                    }

                    c[i].unk_0A = 1;
                }
            }
        }
    }
}

u8 func_0807BA54(void) {
    if (gGameState.flags & 8) {
        if (!(gBtlWork->unk_068 & 0x800000000000)) {
            gBtlWork->unk_1C8 += (s8)gBtlWork->unk_1CA;
        } else if ((s8)gBtlWork->unk_1CA < 0) {
            gBtlWork->unk_1C8 += (s8)gBtlWork->unk_1CA;
        }

        if (gBtlWork->unk_1C8 > 999) {
            gBtlWork->unk_1C8 = 999;
        } else if (gBtlWork->unk_1C8 < 0) {
            gBtlWork->unk_1C8 = 0;
        }
    }

    if (gBtlWork->unk_1C8 > 29 && !(gBtlWork->unk_068 & 0x800000000000)) {
        return 1;
    }

    return 0;
}

void func_0807BB04(void) {
    switch (gBtlWork->unk_0F4) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 30:
    case 31:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 42:
    case 51:
    case 53:
        gBtlWork->unk_0F8--;
        break;
    }
}

void func_0807BC08(void) {
    if (gBtlWork->unk_0F4 == 50) {
        gBtlWork->unk_0F8--;
    }
}
void func_0807BC24(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    u16 v;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(void**)p->unk_1C = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    v = *(u16*)&p->unk_3C[8];

    if ((s16)v != -1) {
        func_0807D318(&p->unk_38, &p->unk_48, (u8)v);

        if ((*(CardSlot**)p->unk_3C)->unk_00 == 0xFFFE) {
            p->unk_78 |= 0x100000;
        }
    } else {
        p->unk_78 = 2;
    }

    if ((*(CardSlot**)p->unk_3C)->unk_00 & 0x8000) {
        p->unk_A6 = 1;
    } else {
        p->unk_A6 = 0;
    }

    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_84 = 0;
    p->unk_88 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 60;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_09033FF4[0][0];
    p->unk_90 = gUnk_09033FF4[0][1];
    p->unk_4C = gUnk_09033FF4[4][0];
    p->unk_50 = gUnk_09033FF4[4][1];

    if (p->unk_48 != 0) {
        p->unk_A5 = p->unk_48->unk_20;
    } else {
        p->unk_A5 = 0;
    }

    p->unk_A7 = 0;
    p->unk_78 |= 0x20;
    p->unk_78 &= ~0x40;
    func_0807D380((u8*)p);
}
u8 func_0807BD64(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);

    if (p->unk_78 & 0x10) {
        if (!(p->unk_78 & 0x80)) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
        }

        if (p->unk_78 & 0x10) {
            p->unk_9C = 8;
            func_0807E018(p);
            SetTaskUpdate(a, func_0807CB24);
            return 1;
        }
    }

    if ((s16)p->unk_9C == 0) {
        if (func_0807CE68(p)) {
            func_08000D90(&p->unk_64, p->unk_38);
            return 0;
        }

        if (!(p->unk_78 & 0x80)) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
            fn = func_0807BE54;
            SetTaskUpdate(a, fn);
            return fn(p, a);
        }
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, func_0807CBC0);
    }

    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

u8 func_0807BE54(UnkStruct_02034AAC* p, void* a) {
    if (func_0807CE68(p)) {
        func_08000D90(&p->unk_64, p->unk_38);
        return 0;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_0807CBC0);
    }

    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

INCLUDE_ASM("card/func_0807BEC0.s");

void card_not_have_2(UnkStruct_02034AAC* p) {
    void* gfx;
    u16 y;

    gfx = gUnk_08F709B0[p->unk_46].unk_04;

    if (func_080A42C8() == 1) {
        y = p->unk_50 >> 8;
    } else {
        y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    if (p->unk_78 & 0x80) {
        DrawSprite(p->unk_4C >> 8, y, gfx, p->unk_04, gUnk_02039DD4->palette, 0, 0x410, (u16)(p->unk_A0 - 1));
    }
}

void func_0807C2E0(UnkStruct_02034AAC* p) {
    func_0807C39C(p);
}

void func_0807C2EC(UnkStruct_02034AAC* p) {
    if (p->unk_A1 != 6) {
        if (func_0807CE68(p) != 0) {
            if (p->unk_78 & 0x80) {
                func_0807C39C(p);
                p->unk_78 &= ~0x80;
            }
        } else {
            if (!(p->unk_78 & 0x80)) {
                func_0807C33C(p);
                p->unk_78 |= 0x80;
            }
        }
    }
}

void func_0807C33C(UnkStruct_02034AAC* p) {
    CardDef* d;
    void* tiles;
    void* pal;
    u32 f;

    f = p->unk_78 & 2;

    if (f != 0) {
        p->unk_00 = 0;
        p->palette = 0;
        p->unk_18 = 0;
        p->unk_04 = LoadObjTiles(gUnk_08F709B0[p->unk_46].unk_10, 640);
    } else {
        d = p->unk_48;
        tiles = d->unk_04;
        pal = d->unk_08;
        p->unk_00 = LoadObjTiles(tiles, 512);
        p->palette = LoadObjPalette(pal, 32);
        p->unk_04 = 0;
    }
}

void func_0807C39C(UnkStruct_02034AAC* p) {
    if (p->unk_00 != 0) {
        ReleaseObjTiles(p->unk_00);
    }

    if (p->palette != 0) {
        ReleaseObjPalette(p->palette);
    }

    if (p->unk_04 != 0) {
        ReleaseObjTiles(p->unk_04);
    }

    if (p->unk_08 != 0) {
        ReleaseObjTiles(p->unk_08);
    }

    if (p->unk_0C != 0) {
        ReleaseObjTiles(p->unk_0C);
    }

    p->unk_00 = 0;
    p->palette = 0;
    p->unk_18 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
}

u8 func_0807C3E8(UnkStruct_02034AAC* p, void* a) {
    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x8000000;

        if (p->unk_48->unk_2A == 0) {
            func_0807E184();
        }

        SetTaskUpdate(a, (void*)func_0807CE04);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        SetTaskUpdate(a, (void*)func_0807D3A0);
    }

    return 1;
}

u8 func_0807C4BC(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_4C, 0x7800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x8400, p->unk_9C);
    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C |= 0xFFFF;
    }

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_0807C3E8);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = -16;
            p->unk_9E = 0xFF;
            p->unk_78 |= 0x2000;
            SetTaskUpdate(a, (void*)func_0807CE9C);

            if (p->unk_48->unk_1E & 2) {
                (*(u8**)p->unk_3C)[6] = 0;
            }

            m4aSongNumStart(0xCC);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        SetTaskUpdate(a, (void*)func_0807CE9C);
    }

    return 1;
}
u8 func_0807C5D8(UnkStruct_02034AAC* w, void* a) {
    ApproachValue(&w->unk_8C, gUnk_0903404C[0], w->unk_9C);
    ApproachValue(&w->unk_90, gUnk_0903404C[1], w->unk_9C);
    ApproachValue(&w->unk_84, w->unk_88, w->unk_9C);
    ApproachValue(&w->unk_54, 0x100, w->unk_9C);
    ApproachValue(&w->unk_58, 0x100, w->unk_9C);
    if ((s16)w->unk_9C > 0) {
        w->unk_9C--;
    } else {
        w->unk_9C = 0;
    }
    func_0807D0F4(w);
    switch (w->unk_9F) {
    case 0:
        w->unk_A0 = 50;
        break;
    case 1:
        w->unk_A0 = 40;
        break;
    case 2:
        w->unk_A0 = 60;
        break;
    }
    if (w->unk_78 & 0x200000) {
        w->unk_A0 -= 4;
        w->unk_84 = 0x500;
        w->unk_9C = 0x100;
        w->unk_7C = -16;
        w->unk_9E = 0xFF;
        gUnk_02039DD4->unk_0E1 = 0;
        SetTaskUpdate(a, (void*)func_0807D3A0);
    }
    if (gBtlWork->unk_068 & 0x20) {
        w->unk_9C = 8;
        w->unk_9E = 8;
        gUnk_02039DD4->unk_0D0--;
        gUnk_02039DD4->unk_0C2 = 0;
        if (gUnk_02039DD4->unk_0D0 == 0) {
            gBtlWork->unk_068 &= ~0x20;
            gBtlWork->unk_068 &= ~0x80;
            func_0807E158();
        }
        gUnk_02039DD4->unk_0E1 = 0;
        gBtlWork->unk_068 &= ~0x8000000;
        SetTaskUpdate(a, (void*)func_0807CE04);
    }
    return 1;
}
u8 func_0807C75C(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);

    func_0807C2EC(p);

    if (!(p->unk_78 & 0x10000000)) {
        fn = func_0807C934;
        SetTaskUpdate(a, fn);
        return fn(p, a);
    }

    if (p->unk_78 & 0x40000000) {
        SetTaskUpdate(a, func_0807D810);
        return 1;
    }

    if (p->unk_A1 == 5) {
        if (p->unk_78 & 0x8000) {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            fn = func_0807C5D8;
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            p->unk_A0 += p->unk_9F * 3;
            fn = func_0807CFA8;
        }

        SetTaskUpdate(a, fn);
        p->unk_78 &= ~0x200;
        func_0807D4B8(p);
        return fn(p, a);
    }

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    if (p->unk_78 & 0x20) {
        switch (p->unk_A2) {
        case 0:
            p->unk_50 -= 0x80;

            if (p->unk_50 <= gUnk_09033FF4[3 - p->unk_9F][1] - 0x200) {
                p->unk_50 = gUnk_09033FF4[3 - p->unk_9F][1] - 0x200;
                p->unk_A2 = 1;
            }
            break;
        case 1:
            p->unk_50 += 0x200;

            if (p->unk_50 >= gUnk_09033FF4[3 - p->unk_9F][1]) {
                p->unk_50 = gUnk_09033FF4[3 - p->unk_9F][1];
                p->unk_A2 = 0;
                p->unk_9C = 16;
            }
            break;
        }
    } else {
        ApproachValue(&p->unk_4C, gUnk_09033FF4[4][0], p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_09033FF4[4][1], p->unk_9C);
    }

    p->unk_5F += 4;
    return 1;
}
u8 func_0807C934(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);
    u16 t;

    if (gBtlWork->unk_070 == 1) {
        return 1;
    }

    func_0807C2EC(p);

    if (p->unk_78 & 0x20) {
        ApproachValue(&p->unk_4C, gUnk_09033FF4[3 - p->unk_9F][0], p->unk_9C);
        ApproachValue(&p->unk_58, 179, p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_09033FF4[3 - p->unk_9F][1], p->unk_9C);
        ApproachValue(&p->unk_54, 179, p->unk_9C);
    } else {
        ApproachValue(&p->unk_4C, gUnk_09033FF4[4][0], p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_09033FF4[4][1], p->unk_9C);
    }

    t = p->unk_9C;

    if ((s16)t > 0) {
        p->unk_9C = t - 1;
        p->unk_78 &= ~0x40;
    } else {
        p->unk_9C = 0;
        p->unk_54 = 0x100;
        p->unk_58 = 0x100;
        p->unk_78 |= 0x40;

        if (p->unk_78 & 0x10000000) {
            p->unk_9C = p->unk_9F * 8;
            fn = func_0807C75C;
            SetTaskUpdate(a, fn);
            return fn(p, a);
        }
    }

    if (p->unk_78 & 0x40000000) {
        SetTaskUpdate(a, func_0807D810);
        return 1;
    }

    if (p->unk_A1 == 5) {
        if (p->unk_78 & 0x8000) {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            fn = func_0807C5D8;
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            fn = func_0807CFA8;
        }

        SetTaskUpdate(a, fn);
        p->unk_78 &= ~0x200;
        func_0807D4B8(p);
        return fn(p, a);
    }

    p->unk_5F += 4;
    return 1;
}

u8 func_0807CB24(UnkStruct_02034AAC* p, void* a) {
    if (!(p->unk_78 & 0x20)) {
        if (p->unk_78 & 0x100000) {
            SetTaskUpdate(a, (void*)func_0807D930);
            return func_0807D930(p, a);
        } else {
            SetTaskUpdate(a, (void*)func_0807CBC0);
            return func_0807CBC0(p, a);
        }
    }

    func_0807CC2C(p);
    p->unk_9C--;

    if (p->unk_9C == 0) {
        p->unk_78 &= ~0x10;

        if (p->unk_78 & 0x100000) {
            gUnk_02039DD4->unk_0E7 = 0;
            SetTaskUpdate(a, (void*)card_reload_1);
        } else {
            SetTaskUpdate(a, (void*)func_0807BD64);
        }
    }

    return 1;
}

u8 func_0807CBC0(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += (0 - p->unk_84) >> 1;
    p->unk_4C += (gUnk_09033FF4[4][0] - p->unk_4C) >> 1;
    p->unk_50 += (gUnk_09033FF4[4][1] - p->unk_50) >> 1;

    if (p->unk_78 & 0x20) {
        f = func_0807BD64;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    return 1;
}

void func_0807CC2C(UnkStruct_02034AAC* p) {
    s32 angle;

    ApproachValue(&p->unk_94, p->unk_98, p->unk_A3);

    if (p->unk_A3 != 0) {
        p->unk_A3--;
    }

    p->unk_84 += (p->unk_88 - p->unk_84) >> 1;

    if ((s16)p->unk_9C > 0) {
        ApproachValue(&p->unk_7C, p->unk_80, p->unk_9C);
        p->unk_9C--;
        p->unk_78 &= ~0x40;
        gUnk_02039DD4->unk_0E7 = 0;
    } else {
        p->unk_78 |= 0x40;
    }

    p->unk_8C = gSineTable[(p->unk_94 >> 8) & 0xFF] * 80 + gUnk_09033FF4[0][0];
    p->unk_90 = -gSineTable[((p->unk_94 >> 8) & 0xFF) + 0x40] * 80 + gUnk_09033FF4[0][1];
    angle = ((p->unk_7C >> 8) + 0x20) & 0xFF;
    p->unk_4C = gSineTable[angle] * (p->unk_84 >> 8) + p->unk_8C;
    p->unk_50 = -gSineTable[angle + 0x40] * (p->unk_84 >> 8) + p->unk_90;
}


void func_0807CD48(UnkStruct_02034AAC* p) {
    if (p->unk_78 & 0x800) {
        if (p->unk_78 & 4) {
            if (p->unk_78 & 1) {
                if (p->unk_54 > 2) {
                    p->unk_54 -= 64;

                    if (p->unk_54 <= 2) {
                        p->unk_54 = 2;
                    }
                } else {
                    p->unk_54 = 2;
                    p->unk_78 &= ~1;

                    if (!(p->unk_78 & 0x80)) {
                        func_0807C33C(p);
                        p->unk_78 |= 0x80;
                    }
                }
            } else {
                if (p->unk_54 <= 255) {
                    p->unk_54 += 64;

                    if (p->unk_54 > 256) {
                        p->unk_54 = 256;
                    }
                } else {
                    p->unk_54 = 256;
                }
            }
        } else {
            if (!(p->unk_78 & 1)) {
                if (p->unk_54 > 2) {
                    p->unk_54 -= 64;

                    if (p->unk_54 <= 2) {
                        p->unk_54 = 2;
                    }
                } else {
                    p->unk_54 = 2;
                    p->unk_78 |= 1;

                    if (p->unk_78 & 0x80) {
                        func_0807C39C(p);
                        p->unk_78 &= ~0x80;
                    }
                }
            } else {
                if (p->unk_54 <= 255) {
                    p->unk_54 += 64;

                    if (p->unk_54 > 256) {
                        p->unk_54 = 256;
                    }
                } else {
                    p->unk_54 = 256;
                }
            }
        }
    }
}

u8 func_0807CE04(UnkStruct_02034AAC* p) {
    ApproachValue(&p->unk_50, 0x8200, p->unk_9C);
    *(u16*)&p->unk_9C =
        *(s16*)&p->unk_9C > 0 ? p->unk_9C - 1 : 0;

    if (*(s16*)&p->unk_9C == 0) {
        *(u16*)&p->unk_9C = 0;
        p->unk_5E += p->unk_9E;
        p->unk_9E++;

        if (p->unk_54 <= 25) {
            return 0;
        }

        p->unk_54 -= 25;
        p->unk_58 -= 25;
    }

    return 1;
}

u8 func_0807CE68(UnkStruct_02034AAC* p) {
    if (p->unk_4C > 0x10000) {
        return 1;
    }

    if (p->unk_4C < -0x1000) {
        return 1;
    }

    if (p->unk_50 > 0xC000) {
        return 1;
    }

    if (p->unk_50 < -0x2000) {
        return 1;
    }

    return 0;
}

u8 func_0807CE9C(UnkStruct_02034AAC* p) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->unk_4C -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        gBtlWork->unk_068 &= ~0x8000000;
        p->unk_78 &= ~0x80;
        return 0;
    }

    return 1;
}

u8 func_0807CF4C(u8* work, void* a) {
    u16* p;
    s32 z;

    p = (u16*)&work[0x9C];
    z = 0;
    *p = 15;
    *(s32*)&work[0x88] = 0x800;
    *(s32*)&work[0x84] = z;
    *(s32*)&work[0x80] = gUnk_09034054[work[0x9F]] * 2;
    *(s32*)&work[0x7C] = z;
    *(s32*)&work[0x8C] = *(s32*)&work[0x4C];
    *(s32*)&work[0x90] = *(s32*)&work[0x50];
    SetTaskUpdate(a, (void*)func_0807C5D8);
    return 1;
}

u8 func_0807CFA8(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_8C, gUnk_0903404C[0], p->unk_9C);
    ApproachValue(&p->unk_90, gUnk_0903404C[1], p->unk_9C);
    ApproachValue(&p->unk_84, p->unk_88, p->unk_9C);
    ApproachValue(&p->unk_54, 0x100, p->unk_9C);
    ApproachValue(&p->unk_58, 0x100, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C = 0;
    }

    func_0807D0F4(p);

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_0807C5D8);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = -16;
            p->unk_9E = 0xFF;
            gUnk_02039DD4->unk_0C0 = 0;
            gUnk_02039DD4->unk_0E1 = 0;
            SetTaskUpdate(a, (void*)func_0807CE9C);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = -16;
        p->unk_9E = 0xFF;
        gUnk_02039DD4->unk_0E1 = 0;
        SetTaskUpdate(a, (void*)func_0807CE9C);
    }

    return 1;
}

void func_0807D0F4(UnkStruct_02034AAC* p) {
    s32 t;

    if (p->unk_80 - p->unk_7C > 0x7F00) {
        p->unk_7C += 0x10000;
    }

    if (p->unk_80 - p->unk_7C <= 255) {
        t = p->unk_7C - 0x10000;

        if (p->unk_80 - t < p->unk_7C - p->unk_80) {
            p->unk_7C = t;
        }
    }

    p->unk_7C += (p->unk_80 - p->unk_7C) >> 2;
    p->unk_4C = gSineTable[(p->unk_7C >> 8) & 0xFF] * (p->unk_84 >> 8) + p->unk_8C;
    p->unk_50 = -gSineTable[((p->unk_7C >> 8) & 0xFF) + 64] * (p->unk_84 >> 8) + p->unk_90;
}
u8 func_0807D194(UnkStruct_02034AAC* w, void* a) {
    switch (w->unk_A1) {
    case 5:
        if (!(w->unk_78 & 0x80)) {
            func_0807C33C(w);
            w->unk_78 |= 0x80;
        }
        func_0807CC2C(w);
        w->unk_9C = 10;
        w->unk_A0 -= 4;
        func_08000D90(w->unk_64, w->unk_38);
        SetTaskUpdate(a, (void*)func_0807C4BC);
        return 1;
    case 6:
        if (!(w->unk_78 & 0x80)) {
            func_0807C33C(w);
            w->unk_78 |= 0x80;
        }
        w->unk_9C = 8;
        w->unk_A0 -= 4;
        func_0807D490(w);
        w->unk_78 |= 0x200;
        w->unk_78 |= 0x80;
        func_08000D90(w->unk_64, w->unk_38);
        SetTaskUpdate(a, (void*)func_0807C934);
        return 1;
    case 8:
        w->unk_A0 -= 4;
        w->unk_84 = 0x500;
        w->unk_9C = 0x100;
        w->unk_7C = -16;
        w->unk_9E = 0xFF;
        SetTaskUpdate(a, (void*)func_0807CE9C);
        break;
    case 7:
        w->unk_84 = 0x500;
        w->unk_9C = 0x100;
        func_08000D90(w->unk_64, w->unk_38);
        return 0;
    case 10:
        w->unk_9C = 10;
        w->unk_A0 -= 4;
        func_08000D90(w->unk_64, w->unk_38);
        SetTaskUpdate(a, (void*)func_0807D4E4);
        return 1;
    case 11:
        w->unk_9C = 10;
        w->unk_A0 -= 4;
        func_08000D90(w->unk_64, w->unk_38);
        SetTaskUpdate(a, (void*)func_0807D584);
        return 1;
    }
    func_0807E018(w);
    return 1;
}

void func_0807D318(UnkStruct_02034AAC* p, CardDef** out) {
    u32* q;

    if (p->unk_04 != 0) {
        if (*(u32*)p->unk_04 != 0xFFFF) {
            if (*(u32*)p->unk_04 != 0xFFFE) {
                *out = &gCardDefs[*(u32*)p->unk_04 & CARD_ID_MASK];
            } else {
                *out = 0;
            }
        } else {
            *out = 0;
        }
    } else {
        q = &gUnk_02039DD4->unk_0B8;
        *out = &gCardDefs[*q & CARD_ID_MASK];
        *q = 0x3B6;
    }
}

void func_0807D380(u8* p) {
    u8* q;

    q = &p[0x64];
    func_08000D20(q, *(void**)&p[0x38], p);
    func_08000D28(q, *(void**)&p[0x38]);
}
u8 func_0807D3A0(UnkStruct_02034AAC* p, void* a) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->unk_4C -= 0x200;
    p->unk_5E += 16;

    if (!(p->unk_78 & 0x400000)) {
        p->unk_54 -= 10;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = -10;
        }

        if (p->unk_54 <= -0x100) {
            p->unk_54 = -0x100;
            p->unk_78 |= 0x400000;
        }
    } else {
        p->unk_54 -= 10;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = 10;
        }

        if (p->unk_54 >= 0x100) {
            p->unk_54 = 0x100;
            p->unk_78 &= ~0x400000;
        }
    }

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->unk_068 &= ~0x8000000;
        return 0;
    }

    return 1;
}
void func_0807D490(UnkStruct_02034AAC* p) {
    void* tiles;
    void* pal;

    func_0807C39C(p);
    tiles = p->unk_48->unk_14;
    pal = p->unk_48->unk_18;
    p->unk_00 = LoadObjTiles(tiles, 256);
    p->palette = LoadObjPalette(pal, 32);
}

void func_0807D4B8(UnkStruct_02034AAC* p) {
    if (p->unk_00 != 0) {
        ReleaseObjTiles(p->unk_00);
    }

    if (p->palette != 0) {
        ReleaseObjPalette(p->palette);
    }

    p->unk_00 = 0;
    p->palette = 0;
    func_0807C33C(p);
}

u8 func_0807D4E4(UnkStruct_02034AAC* p) {
    u8 arg;

    p->unk_A1 = 0;
    ApproachValue(&p->unk_4C, 0x1800, p->unk_9C);
    ApproachValue(&p->unk_58, 0x99, p->unk_9C);
    ApproachValue(&p->unk_50, 0x6400, p->unk_9C);
    ApproachValue(&p->unk_54, 0x99, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    arg = 1;
    gBtlWork->unk_0F8 = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E;
    TaskCreate(&gUnk_02039DD4->unk_09C, gTaskDescHCEffectName, &arg);
    return 0;
}

u8 func_0807D584(UnkStruct_02034AAC* p, void* a) {
    s16 sx;
    s16 sy;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    ApproachValue(&p->unk_4C, 0x1800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x6400, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        WorldToScreen(&sx, &sy, *(s32*)&gBtlWork->unk_100[0], *(s32*)&gBtlWork->unk_100[4], *(s32*)&gBtlWork->unk_100[8]);
        x = sx;
        y = sy;
        dx = (x << 8) - p->unk_4C;
        dy = (y << 8) - p->unk_50;
        p->unk_84 = func_0805F5A4(&dx, &dy);
        p->unk_8C = -dx;
        p->unk_90 = -dy;
        p->unk_88 = 0x300;
        p->unk_5E = 0;
        p->unk_80 = 25;
        gBtlWork->unk_072 = 10000;
        func_08006184(7, 1);
        m4aSongNumStart(0x26B);
        func_080063A8();
        gBtlWork->unk_068 |= 0x200000000000000;
        SetTaskUpdate(a, (void*)func_0807D68C);
    }

    return 1;
}

u8 func_0807D68C(UnkStruct_02034AAC* p, void* a) {
    s16 sx;
    s16 sy;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    WorldToScreen(&sx, &sy, *(s32*)&gBtlWork->unk_100[0], *(s32*)&gBtlWork->unk_100[4], *(s32*)&gBtlWork->unk_100[8]);
    x = sx;
    y = sy;

    if (p->unk_88 < 0) {
        dx = (x << 8) - p->unk_4C;
        dy = (y << 8) - p->unk_50;
        func_0805F5A4(&dx, &dy);
        p->unk_8C = -dx;
        p->unk_90 = -dy;
    }

    p->unk_5E += 24;

    if (p->unk_54 > 24) {
        p->unk_54 -= 12;
        p->unk_58 -= 12;
    } else {
        p->unk_54 = 25;
        p->unk_58 = 25;
    }

    p->unk_4C += (p->unk_8C * p->unk_88) >> 8;
    p->unk_50 += (p->unk_90 * p->unk_88) >> 8;
    p->unk_84 = func_0805F588((x << 8) - p->unk_4C, (y << 8) - p->unk_50);
    p->unk_88 -= p->unk_80;
    p->unk_80 += 2;

    if (p->unk_84 <= 0x800) {
        gBtlWork->unk_074 = 15;
        gBtlWork->unk_072 = 15;
        m4aSongNumStart(0x78);
        SetTaskUpdate(a, (void*)func_0807D7B0);
    }

    return 1;
}

u8 func_0807D7B0(UnkStruct_02034AAC* p) {
    if ((s16)gBtlWork->unk_072 == 0) {
        func_08006120(7, 8);
        func_080063A8();
        gBtlWork->unk_068 &= ~0x200000000000000;

        if (p->unk_48->unk_24 == 140) {
            func_0801C1A0(0);
        }

        gBtlWork->unk_068 &= ~0x20000000000000;
        return 0;
    }

    return 1;
}

u8 func_0807D810(u8* work) {
    s32 r;

    if (*(s32*)&work[0x54] <= 25) {
        (*(u8**)&work[0x3C])[7] = r = 0;
        return r;
    }

    *(s32*)&work[0x54] -= 12;
    *(s32*)&work[0x58] += 12;

    if (*(s32*)&work[0x58] > 0x1FF) {
        *(s32*)&work[0x58] = 0x200;
    }

    return 1;
}
void card_reload_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    vu32 zero2;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = EwramAlloc(0x68);
    zero2 = 0;
    CpuSet((void*)&zero2, p->unk_20, 0x0500001A);
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    ((u8*)p->unk_20)[0x65] = 0;
    p->unk_78 = 0x01100020;
    p->unk_48 = 0;
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_9F = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 60;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_09033FF4[0][0];
    p->unk_90 = gUnk_09033FF4[0][1];
    p->unk_4C = gUnk_09033FF4[4][0];
    p->unk_50 = gUnk_09033FF4[4][1];
    p->unk_78 &= ~0x40;
    gUnk_02039DD4->unk_0E7 = 0;
    func_0807D380(p);
}

u8 func_0807D930(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += (0 - p->unk_84) >> 1;
    p->unk_4C += (gUnk_09033FF4[4][0] - p->unk_4C) >> 1;
    p->unk_50 += (gUnk_09033FF4[4][1] - p->unk_50) >> 1;

    if (p->unk_78 & 0x20) {
        f = card_reload_1;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    return 1;
}

u8 card_reload_1(UnkStruct_02034AAC* p, void* a) {
    if (p->unk_78 & 0x10) {
        p->unk_9C = 8;
        SetTaskUpdate(a, (void*)func_0807CB24);
        return 1;
    }

    if ((s16)p->unk_9C == 0) {
        if (func_0807CE68(p)) {
            func_08000D90(&p->unk_64, p->unk_38);
            return 0;
        }

        if (!(p->unk_78 & 0x80)) {
            func_0807DAD0(p);
            p->unk_78 |= 0x80;
        }
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_0807D930);
    }

    func_0807DE10(p);
    func_0807CC2C(p);
    p->unk_5F += 4;
    return func_0807D194(p, a);
}

void func_0807DA54(UnkStruct_08095A5C* p, void* a, u8 b, s8 c) {
    AnimInit(&p->unk_10, gUnk_09EEA4E0, gUnk_09EEA494);

    if (c >= 0) {
        AnimStart(&p->unk_10, c, 0);
    } else {
        AnimStart(&p->unk_10, 0, 0);
    }

    p->unk_60 = AnimGetGfx(&p->unk_10);
}

void func_0807DAA4(u8* p, s32 a) {
    void* gfx;

    if ((u16)a <= 18) {
        AnimStart(&p[0x10], a, 0);
        gfx = AnimGetGfx(&p[0x10]);
    } else {
        gfx = 0;
    }

    *(void**)&p[0x60] = gfx;
}
void func_0807DAD0(UnkStruct_02034AAC* p) {
    u8* d;

    d = p->unk_20;
    p->unk_00 = AllocObjTiles(0x80, 0);
    func_08002A10(p->unk_00, gUnk_0909A4E0);
    func_0807DA54(p->unk_20, p->unk_00, p->unk_46, gUnk_02039DD4->unk_0FC);
    p->palette = 0;
    p->unk_04 = LoadObjTiles(gUnk_0909FDCA, 0x280);
    p->unk_18 = 0;
    p->unk_08 = AllocObjTiles(0x200, 0);
    func_08002A10(p->unk_08, gUnk_090A0C86);
    p->unk_0C = AllocObjTiles(0x80, 0);
    func_08002A10(p->unk_0C, gUnk_090A0C86);
    AnimInit(&d[0x28], gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(&d[0x28], 1, 1);
    *(void**)&d[0x58] = gUnk_09EEAF4C[3];
    AnimInit(&d[0x40], gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(&d[0x40], gUnk_02039DD4->unk_104, 1);
    *(void**)&d[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_100 + 2];
}
void card_reload_2(UnkStruct_02034AAC* p) {
    u8* w;
    s16 y;
    s32 affine;
    s32 attr;

    if (p->unk_78 & 0x80) {
        w = p->unk_20;

        if (func_080A42C8() == 1) {
            y = p->unk_50 >> 8;
        } else {
            y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
        }

        attr = 0x410;
        DrawSprite(p->unk_4C >> 8, y, gUnk_08F709B0[3].unk_04, p->unk_04,
                   gUnk_02039DD4->palette, 0, attr, p->unk_A0);

        if (!(gGameState.flags & 8) && *(void**)&w[0x60] != 0) {
            DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x60], p->unk_00,
                       gUnk_02039DD4->palette, 0, 0x410, (u16)(p->unk_A0 - 2));
        }

        if ((s32)gUnk_02039DD4->unk_0F4 > 0) {
            affine = AllocObjAffine(0, p->unk_54, gUnk_02039DD4->unk_0F4, 0);

            if (*(void**)&w[0x58] != 0) {
                DrawSprite(p->unk_4C >> 8, y + 17, *(void**)&w[0x58], p->unk_08,
                           gUnk_02039DD4->palette, affine, 0x400,
                           (u16)(p->unk_A0 - 1));
            }

            if (gUnk_02039DD4->unk_108[0] == 1 && *(void**)&w[0x5C] != 0) {
                DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x5C], p->unk_0C,
                           gUnk_02039DD4->palette, 0, 0x400,
                           (u16)(p->unk_A0 - 1));
            }
        }
    }
}
void card_reload_3(UnkStruct_02034AAC* p) {
    func_0807C39C(p);
    EwramFree(p->unk_20);

    if (gBtlWork->unk_068 & 0x1000000) {
        gBtlWork->unk_068 &= ~0x1000000;
    }
}
void func_0807DD70(u8* p, void* a) {
    if (gUnk_02039DD4->unk_104 <= 7) {
        gUnk_02039DD4->unk_104++;
    }

    AnimStart(&p[0x40], (u16)gUnk_02039DD4->unk_104, 5);
}
void func_0807DDA8(u8* p) {
    gUnk_02039DD4->unk_104 = 2;
    AnimStart(&p[0x40], 2, 5);
}
void func_0807DDCC(u8* p, void* a) {
    *(void**)&p[0x58] = gUnk_09EEAF4C[3];
    *(void**)&p[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_100 + 2];
}
void func_0807DDF4(u8* p, void* a) {
    *(void**)&p[0x58] = AnimUpdate(&p[0x28]);
    *(void**)&p[0x5C] = AnimUpdate(&p[0x40]);
}
void func_0807DE10(UnkStruct_02034AAC* p) {
    u8* w = p->unk_20;
    u8 v = 0;

    if ((p->unk_78 & 0x44) == 0x44) {
        v = gUnk_02039DD4->unk_0E7;
        gUnk_02039DD4->unk_0E7 = 0;
    } else {
        gUnk_02039DD4->unk_0E7 = 0;
    }

    if ((p->unk_78 & 0x44) == 0x44) {
        if (v == 1) {
            if (*(s8*)&w[0x65] == 2) {
                if (!(gBtlWork->unk_068 & 0x1000000)) {
                    m4aSongNumStart(200);
                    gBtlWork->unk_068 |= 0x1000000;
                }

                if (gUnk_02039DD4->unk_108[0] == 0) {
                    if (gBtlWork->unk_0F4 == 43) {
                        gUnk_02039DD4->unk_0F4 += 12;
                    } else {
                        gUnk_02039DD4->unk_0F4 += 25;
                    }

                    if ((s32)gUnk_02039DD4->unk_0F4 > 0x100) {
                        gUnk_02039DD4->unk_0F4 = 0x100;
                        gUnk_02039DD4->unk_108[0] = 1;
                    }
                } else {
                    gUnk_02039DD4->unk_100 += 3;
                    func_0807DD70(p->unk_20, p);

                    if (gUnk_02039DD4->unk_100 == 22) {
                        gUnk_02039DD4->unk_100 = 4;
                        gUnk_02039DD4->unk_0F4 = 0;
                        gUnk_02039DD4->unk_108[0] = 0;
                        gUnk_02039DD4->unk_0FC--;
                        p->unk_A2 = v;
                        func_0807DDA8(p->unk_20);
                        m4aSongNumStart(201);
                        func_0807DAA4(p->unk_20, (s16)gUnk_02039DD4->unk_0FC);
                    }
                }

                w[0x65] = 0;
            }

            func_0807DDF4(p->unk_20, p);
            w[0x65]++;
        } else {
            func_0807DDCC(p->unk_20, p);
            w[0x65] = 0;
            m4aSongNumStop(200);
            gBtlWork->unk_068 &= ~0x1000000;
        }
    } else {
        gBtlWork->unk_068 &= ~0x1000000;
    }

    if ((s16)gUnk_02039DD4->unk_0FC < 0) {
        gUnk_02039DD4->unk_0F4 = 0;
        gUnk_02039DD4->unk_100 = 4;
        gUnk_02039DD4->unk_104 = 2;
        gUnk_02039DD4->unk_108[0] = 0;

        if (!(p->unk_78 & 0x4000000)) {
            p->unk_78 |= 0x4000000;
            m4aSongNumStart(202);
        }

        if (func_08006390() == 0) {
            func_08006290(2, 16, 20);
        }

        gBtlWork->unk_068 &= ~0x1000000;
    }
}

void func_0807E018(UnkStruct_02034AAC* w) {
    if (gBtlWork->unk_0F4 == 16) {
        if (w->unk_78 & 4) {
            w->unk_A7 = 1;
            w->unk_A5 = GetRandom() % 10;
        } else {
            w->unk_A7 = 0;
            w->unk_A5 = w->unk_48->unk_20;
        }
    } else if (gBtlWork->unk_0F4 == 17) {
        w->unk_A7 = 1;
        w->unk_A5 = 0;
    } else if (gBtlWork->unk_0F4 == 31) {
        w->unk_A7 = 1;
        w->unk_A5 = 10 - w->unk_48->unk_20;
        if (w->unk_A5 == 10) {
            w->unk_A5 = 0;
        }
    } else {
        w->unk_A5 = w->unk_48->unk_20;
        switch (gGameState.unk_1B8) {
        case 7:
            if (w->unk_48->unk_2A == 1) {
                w->unk_A5 += 2;
                if (w->unk_A5 > 9) {
                    w->unk_A5 = 9;
                }
                w->unk_A7 = 1;
            }
            break;
        case 8:
            if (w->unk_48->unk_2A == 2 && (w->unk_48->unk_1E & 2)) {
                w->unk_A5 += 2;
                if (w->unk_A5 > 9) {
                    w->unk_A5 = 9;
                }
                w->unk_A7 = 1;
            }
            break;
        case 9:
            if (w->unk_48->unk_2A == 0) {
                w->unk_A5 += 2;
                if (w->unk_A5 > 9) {
                    w->unk_A5 = 9;
                }
                w->unk_A7 = 1;
            }
            break;
        default:
            w->unk_A7 = 0;
            w->unk_A5 = w->unk_48->unk_20;
            break;
        }
    }
}
void func_0807E158(void) {
    BtlWork* p;

    p = gBtlWork;

    switch (p->unk_0F4) {
    case 15:
    case 28:
    case 47:
        p->unk_0F8--;
        break;
    }
}
void func_0807E184(void) {
    if (gBtlWork->unk_0F4 == 2) {
        gBtlWork->unk_0F8--;
    }
}
void func_0807E1A0(void) {
    gUnk_02034AA8 = 17;
}
void func_0807E1AC(void) {
    gUnk_02034AA8 = 18;
}
void func_0807E1B8(void) {
    gUnk_02034AA8 = 19;
}
void func_0807E1C4(void) {
    gUnk_02034AA8 = 21;
}
void func_0807E1D0(void) {
    gUnk_02034AA8 = 22;
}
void func_0807E1DC(void) {
    gUnk_02034AA8 = 23;
}
void func_0807E1E8(void) {
    gUnk_02034AA8 = 24;
}

void func_0807E1F4(void) {
    gUnk_02034AA4 = 1;
}

void func_0807E200(void) {
    gUnk_02034AA4 = 2;
}

void func_0807E20C(void) {
    gUnk_02034AA4 = 3;
}

void func_0807E218(void) {
    gUnk_02034AA4 = 4;
}

void func_0807E224(void) {
    gUnk_02034AA4 = 5;
}

void func_0807E230(void) {
    gUnk_02034AA4 = 8;
}

void func_0807E23C(void) {
    gUnk_02034AA4 = 6;
}

void func_0807E248(void) {
    gUnk_02034AA4 = 7;
}

void func_0807E254(void) {
    gUnk_02034AA4 = 9;
}

void func_0807E260(void) {
    gUnk_02034AA4 = 10;
}

void func_0807E26C(void) {
    gUnk_02034AA4 = 11;
}

void func_0807E278(void) {
    gUnk_02034AA4 = 12;
}

void func_0807E284(void) {
    gUnk_02034AA4 = 13;
}

void func_0807E290(void) {
    gUnk_02034AA4 = 0;
}

u8 func_0807E29C(void) {
    if (gUnk_02034AAC != 0) {
        if (gUnk_02034AAC->unk_78 & 0x100000) {
            return 1;
        }
    }

    return 0;
}

s32 func_0807E2BC(void) {
    CardDef* d;

    if (gUnk_02034AAC != 0) {
        if (!(gUnk_02034AAC->unk_78 & 0x1100000)) {
            d = gUnk_02034AAC->unk_48;

            if (d->unk_2A == 3) {
                return d->unk_24 + 0xFFFF;
            }

            return d->unk_24;
        }
    }

    return 145;
}

void func_0807E2F4(void) {
    if (gUnk_02034AAC != 0) {
        if ((gUnk_02034AAC->unk_78 & 0x1000044) == 0x1000044) {
            gUnk_02039DD4->unk_0E8 = 1;
        } else {
            gUnk_02039DD4->unk_0E8 = 0;
        }
    } else {
        gUnk_02039DD4->unk_0E8 = 0;
    }
}

u8 func_0807E33C(void) {
    return gUnk_02039DD4->unk_0F0;
}

u8 func_0807E34C(void) {
    if (gUnk_02034AAC != 0) {
        return gUnk_02034AAC->unk_78 & 2;
    }

    return 0;
}

void func_0807E368(UnkStruct_08080268* w, u8 slot) {
    UnkStruct_0807FD10_Args args;
    u16 id;
    CardSlot* card;
    UnkStruct_02034AAC* node;
    s16 count;

    count = 0;
    if (w->unk_94[slot] != 0xFFFF && (s16)w->unk_A8[slot] > 0) {
        id = w->unk_94[slot];
        card = func_08076674(w, slot, &id);
        if (card != 0) {
            args.unk_00 = &w->unk_54[slot];
            args.unk_0C = id;
            args.unk_0E = slot;
            args.unk_04 = card;
            args.unk_0F = w->unk_9C[slot];
            if (card->unk_00 == 0xFFFE) {
                gUnk_02034AAC = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
            } else {
                gUnk_02034AAC = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
            }
            count++;
        }
    }

    switch (count) {
    case 0:
        args.unk_00 = &w->unk_54[slot];
        args.unk_0C = 0xFFFF;
        args.unk_04 = (CardSlot*)w->unk_44[slot];
        args.unk_0E = slot;
        node = ((UnkStruct_02034AAC**)TaskCreate(w, &gUnk_09EE49CC[0x18], &args))[1];
        node->unk_98 = node->unk_94 = gUnk_090352E4[0];
        node->unk_A4 = 0;
        node->unk_A0 = 50;
        node->unk_78 |= 0x802;
        gUnk_02034AAC = node;
        break;
    case 1:
        gUnk_02034AAC->unk_98 = gUnk_02034AAC->unk_94 = gUnk_090352E4[0];
        gUnk_02034AAC->unk_A0 = 50;
        gUnk_02034AAC->unk_78 |= 0x800;
        break;
    }
}

#ifdef NON_MATCHING
void sub_0807E4C8(UnkStruct_08080268* w, CardSlot* slots, s8 kind, s32 n) {
    Deck* deck;
    u16 count;

    switch (*(s32*)&gBtlWork->unk_100[0xC]) {
    case 157:
    case 179:
        deck = &gUnk_09034084[20];
        n = deck->unk_DC;
        break;
    case 158:
        deck = &gUnk_09034084[4];
        n = deck->unk_DC;
        break;
    case 159:
        deck = &gUnk_09034084[1];
        n = deck->unk_DC;
        break;
    case 160:
        deck = &gUnk_09034084[2];
        n = deck->unk_DC;
        break;
    case 161:
        deck = &gUnk_09034084[5];
        n = deck->unk_DC;
        break;
    case 162:
        deck = &gUnk_09034084[0];
        n = deck->unk_DC;
        break;
    case 163:
        deck = &gUnk_09034084[3];
        n = deck->unk_DC;
        break;
    case 164:
        deck = &gUnk_09034084[7];
        n = deck->unk_DC;
        break;
    case 165:
        deck = &gUnk_09034084[13];
        n = deck->unk_DC;
        break;
    case 166:
        deck = &gUnk_09034084[14];
        n = deck->unk_DC;
        break;
    case 177:
        deck = &gUnk_09034084[19];
        n = deck->unk_DC;
        break;
    case 167:
        deck = &gUnk_09034084[17];
        n = deck->unk_DC;
        break;
    case 168:
        deck = &gUnk_09034084[6];
        n = deck->unk_DC;
        break;
    case 169:
        deck = &gUnk_09034084[9];
        n = deck->unk_DC;
        break;
    case 170:
        deck = &gUnk_09034084[10];
        n = deck->unk_DC;
        break;
    case 171:
        deck = &gUnk_09034084[16];
        n = deck->unk_DC;
        break;
    case 172:
        deck = &gUnk_09034084[18];
        n = deck->unk_DC;
        break;
    case 173:
        deck = &gUnk_09034084[12];
        n = deck->unk_DC;
        break;
    case 174:
        deck = &gUnk_09034084[11];
        n = deck->unk_DC;
        break;
    case 175:
        deck = &gUnk_09034084[8];
        n = deck->unk_DC;
        break;
    case 176:
        deck = &gUnk_09034084[15];
        n = deck->unk_DC;
        break;
    default:
        deck = sub_08083EFC();
        n = 99;
        break;
    }

    count = sub_0807E66C(slots, deck->cards, n, (u8)kind);
    if (gBtlWork->unk_068 & 0x800) {
        sub_0807842C((CardSlot*)w->unk_44[kind], count);
    }
    if (kind == 0) {
        slots[count].unk_06 = 0;
        slots[count].unk_07 = 0;
        slots[count].unk_0A = 0;
        slots[count].unk_00 = 0xFFFE;
        slots[count].unk_04 = count;
    }
}

#else
INCLUDE_ASM("card/sub_0807E4C8.s");
#endif

u16 sub_0807E66C(CardSlot* out, u16* ids, u16 n, u8 kind) {
    u16 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (ids[i] != 0xFFFF) {
            switch (kind) {
            case 0:
                if ((u8)gCardDefs[ids[i] & CARD_ID_MASK].unk_2A <= 2) {
                    out[count].unk_06 = kind;
                    out[count].unk_07 = kind;
                    out[count].unk_0A = kind;
                    out[count].unk_00 = ids[i];
                    out[count].unk_04 = count;
                    count++;
                }
                break;
            case 3:
                if ((u8)gCardDefs[ids[i] & CARD_ID_MASK].unk_2A == 3) {
                    out[count].unk_06 = 0;
                    out[count].unk_07 = 0;
                    out[count].unk_0A = 0;
                    out[count].unk_00 = ids[i];
                    out[count].unk_04 = count;
                    count++;
                }
                break;
            }
        }
    }

    return count;
}

void func_0807E724(UnkStruct_08080268* w, s8 idx) {
    u16 n = w->unk_A8[idx];

    if (n != 0) {
        if (idx == 0) {
            CardSlot* slots;
            vu32 zero;
            u8 i;

            slots = EwramAlloc((n + 15) * sizeof(CardSlot));
            w->unk_44[idx] = (void*)slots;
            zero = 0;
            CpuSet((void*)&zero, slots, ((n + 15) * 3) | 0x05000000);

            for (i = 0; i < n; i++) {
                ((CardSlot*)w->unk_44[idx])[i].unk_06 = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_00 = 0xFFFF;
                ((CardSlot*)w->unk_44[idx])[i].unk_07 = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_0A = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_08 = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_09 = 0;
            }

            for (i = n; i < n + 15; i++) {
                ((CardSlot*)w->unk_44[idx])[i].unk_06 = 1;
                ((CardSlot*)w->unk_44[idx])[i].unk_00 = 0xFFFF;
                ((CardSlot*)w->unk_44[idx])[i].unk_07 = 1;
                ((CardSlot*)w->unk_44[idx])[i].unk_0A = 1;
                ((CardSlot*)w->unk_44[idx])[i].unk_08 = 1;
                ((CardSlot*)w->unk_44[idx])[i].unk_09 = 0;
            }
        } else {
            CardSlot* slots;
            vu32 zero;
            u8 i;

            slots = EwramAlloc(n * sizeof(CardSlot));
            w->unk_44[idx] = (void*)slots;
            zero = 0;
            CpuSet((void*)&zero, slots, (n * 3) | 0x05000000);

            for (i = 0; i < n; i++) {
                ((CardSlot*)w->unk_44[idx])[i].unk_06 = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_00 = 0xFFFF;
                ((CardSlot*)w->unk_44[idx])[i].unk_07 = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_0A = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_08 = 0;
                ((CardSlot*)w->unk_44[idx])[i].unk_09 = 0;
            }
        }

        sub_0807E4C8(w, (CardSlot*)w->unk_44[idx], idx, w->unk_A8[idx]);
        w->unk_94[idx] = 0;
    } else {
        CardSlot* slot;
        vu32 zero;
        u16* q;
        s32 k;

        slot = EwramAlloc(sizeof(CardSlot));
        w->unk_44[idx] = (void*)slot;
        zero = 0;
        CpuSet((void*)&zero, slot, 3 | 0x05000000);
        ((CardSlot*)w->unk_44[idx])->unk_00 = (idx << 12) | 0xFF;
        ((CardSlot*)w->unk_44[idx])->unk_09 = 0;
        q = w->unk_94;
        q += idx;
        k = 0xFFFF;
        *q = k;
    }
}
#ifdef NON_MATCHING
void func_0807E8F4(UnkStruct_08080268* w) {
    s32 zero;
    u8 i;

    zero = 0;
    CpuSet((void*)&zero, w, 0x05000033);
    gUnk_02039DD4->unk_060 = (u32)w;
    w->unk_14 = func_080038C8(0x80);
    w->unk_18 = LoadObjPalette(gUnk_08F69BA4, 32);
    func_080038E4((UnkStruct_080038C8*)w->unk_14, gUnk_09EF12E8[0], gUnk_093FBAB8);
    TaskPoolInit((TaskPool*)w, 30);
    w->unk_B9 = 0;
    w->unk_B8 = 0;
    w->unk_C0[0] = 0;
    w->unk_C0[1] = 0;
    w->unk_C0[2] = 0;
    w->unk_C0[3] = 0;
    w->unk_BC[0] = 1;
    w->unk_BC[1] = 0;
    w->unk_BC[2] = 0;
    w->unk_BC[3] = 0;
    w->unk_BA = 0;
    w->unk_C4[3] = 0;
    w->unk_A4 = *(u16*)&gUnk_090352E4[4];

    for (i = 0; i <= 2; i++) {
        w->unk_1C[i] = 0;
        w->unk_28[i] = 0;
    }

    for (i = 0; i <= 3; i++) {
        w->unk_34[i] = 0;
        w->unk_44[i] = 0;
    }

    w->unk_C4[1] = 0;
    ListPoolInit(&w->unk_54[0]);
    ListPoolInit(&w->unk_54[1]);
    ListPoolInit(&w->unk_54[2]);
    ListPoolInit(&w->unk_54[3]);

    switch (*(s32*)&gBtlWork->unk_100[0xC]) {
    case 162:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[0]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[0]);
        break;
    case 159:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[1]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[1]);
        break;
    case 160:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[2]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[2]);
        break;
    case 163:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[3]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[3]);
        break;
    case 158:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[4]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[4]);
        break;
    case 161:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[5]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[5]);
        break;
    case 168:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[6]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[6]);
        break;
    case 164:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[7]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[7]);
        break;
    case 175:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[8]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[8]);
        break;
    case 169:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[9]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[9]);
        break;
    case 170:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[10]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[10]);
        break;
    case 174:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[11]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[11]);
        break;
    case 173:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[12]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[12]);
        break;
    case 165:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[13]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[13]);
        break;
    case 166:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[14]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[14]);
        break;
    case 176:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[15]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[15]);
        break;
    case 171:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[16]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[16]);
        break;
    case 167:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[17]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[17]);
        break;
    case 172:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[18]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[18]);
        break;
    case 177:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[19]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[19]);
        break;
    case 157:
    case 179:
        w->unk_B0[0] = w->unk_A8[0] = func_080859A0(0, &gUnk_09034084[20]) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_080859A0(1, &gUnk_09034084[20]);
        break;
    default:
        w->unk_B0[0] = w->unk_A8[0] = func_08083E54(0) + 1;
        w->unk_B0[3] = w->unk_A8[3] = func_08083E54(3);
        break;
    }

    func_0807E724(w, 0);
    func_0807E724(w, 3);
    w->unk_94[0] = 0;
    w->unk_94[1] = 0;
    w->unk_94[2] = 0;
    w->unk_94[3] = 0;
    w->unk_9C[0] = 0;
    w->unk_9C[1] = 0;
    w->unk_9C[2] = 0;
    gUnk_02034AAC = 0;
    func_0807E368(w, w->unk_B8);
    gUnk_02034AA4 = 0;
    gUnk_02039DD4->unk_0D4 = w->unk_B8;
}
#else
INCLUDE_ASM("card/func_0807E8F4.s");
#endif
#ifdef NON_MATCHING
u8 func_0807EDEC(UnkStruct_08080268* w, void* a) {
    UnkStruct_080ABA80 arr;
    u8 flag[4];
    UnkStruct_080ABA80 arr2;
    u8 buf[6];
    s32 hold;
    s32 args[2];
    s32 done;
    s32 n;
    u32 kind;
    u32 flags;
    UnkStruct_02034AAC* p;
    u16 r;
    u8 i;

    if (gBtlWork->unk_0A0 == 4) {
        if (gUnk_02039B9C->unk_068 & 0x1000000) {
            gUnk_02039B9C->unk_068 &= ~0x1000000;
        }

        return 0;
    }

    if (w->unk_C4[3] != 0) {
        hold = w->unk_A4 << 8;
        n = w->unk_B9 - 1;
        ApproachValue(&hold, ((s16*)&gUnk_090352E4[4])[n] << 8, w->unk_C4[3]);
        w->unk_A4 = hold >> 8;
        w->unk_C4[3]--;
    }

    p = gUnk_02034AAC;
    flags = p->unk_78;

    if (flags & 0x1000000) {
      if (flags & 0x4000000) {
        if (gUnk_02039B9C->unk_0F4 == 9) {
            p->unk_78 = flags | 0x4000;
            p->unk_A1 = 7;

            if (gUnk_02039B9C->unk_0F4 != 25) {
                func_0807B378(w);

                if (gUnk_02039B9C->unk_0F4 == 10) {
                    w->unk_9C[w->unk_B8] -= 2;

                    if ((s16)w->unk_9C[w->unk_B8] < 0) {
                        w->unk_9C[w->unk_B8] = 0;
                    }
                }
            }

            gUnk_02039DD4->unk_0FE = w->unk_9C[w->unk_B8];
            gUnk_02039DD4->unk_0F8 = 0;
            gUnk_02039DD4->unk_102 = 4;
            TaskPoolUpdate(w);
            func_08078914(w, 0);
            w->unk_94[0] = 0;
            w->unk_B0[0] = func_08078754(w, 0);
            func_0807E368(w, 0);
            func_080818E4();
        } else {
            p->unk_A1 = 7;

            if (gUnk_02039B9C->unk_0F4 != 25) {
                func_0807B378(w);

                if (gUnk_02039B9C->unk_0F4 == 10) {
                    w->unk_9C[w->unk_B8] -= 2;

                    if ((s16)w->unk_9C[w->unk_B8] < 0) {
                        w->unk_9C[w->unk_B8] = 0;
                    }
                }
            }

            gUnk_02039DD4->unk_0FE = w->unk_9C[w->unk_B8];
            gUnk_02039DD4->unk_0F8 = 0;
            gUnk_02039DD4->unk_102 = 4;
            func_080788CC(w, 0);
            w->unk_94[w->unk_B8] = 0;
            w->unk_B0[w->unk_B8] = 0;
            w->unk_C0[w->unk_B8] = 1;
            gUnk_02034AAC = 0;
            gUnk_02034AA4 = 0;
            w->unk_BC[w->unk_B8] = 0;
        }
      }
    }

    switch (gUnk_02034AA4) {
    case 0:
        break;
    case 1:
        gUnk_02034AA4 = 0;

        if (gUnk_02034AAC->unk_78 & 0x40) {
            func_0807FD10(w, w->unk_B8);
        }
        break;
    case 2:
        gUnk_02034AA4 = 0;

        if (gUnk_02034AAC->unk_78 & 0x40) {
            func_0807FE30(w, w->unk_B8);
        }
        break;
    case 4:
        gUnk_02034AA4 = 0;
        p = gUnk_02034AAC;
        flags = p->unk_78;

        if (!(flags & 0x100000)) {
            if (w->unk_B9 == 3) {
                func_08081210(w);
            } else if (p->unk_48->unk_2A == 3) {
                m4aSongNumStart(105);
            } else if (w->unk_C0[w->unk_B8] == 0) {
                if (!(flags & 2)) {
                    if (func_08081888() != 0) {
                        if (w->unk_B9 <= 2 && gUnk_02039DD4->unk_0E2 == 0) {
                            func_08080B44(w);
                        }
                    } else if (gUnk_02034AAC->unk_78 & 0x20) {
                        m4aSongNumStart(105);
                    }
                } else if (flags & 0x20) {
                    m4aSongNumStart(105);
                }
            }
        } else if (w->unk_B9 != 0) {
            func_08081210(w);
        } else {
            m4aSongNumStart(105);
        }
        break;
    case 3:
        gUnk_02034AA4 = 0;
        p = gUnk_02034AAC;

        if (p->unk_48->unk_2A != 3) {
            flags = p->unk_78;

            if (!(flags & 0x100000) && w->unk_C0[w->unk_B8] == 0) {
                if (!(flags & 2)) {
                    if (func_08081888() != 0) {
                        func_08080594(w);
                    } else if (gUnk_02034AAC->unk_78 & 0x20) {
                        m4aSongNumStart(105);
                    }
                } else if (flags & 0x20) {
                    m4aSongNumStart(105);
                }
            }
        } else if (!(p->unk_78 & 0x100000)) {
            func_080814BC(w);
        }
        break;
    case 5:
        gUnk_02034AA4 = 0;

        if (w->unk_B9 != 0) {
            func_08081210(w);
        } else if (!(gBtlWork->unk_068 & 0x80)) {
            m4aSongNumStart(105);
        }
        break;
    case 6:
        gUnk_02034AA4 = 0;
        func_0807FAD8(w);
        break;
    case 7:
        w->unk_BC[w->unk_B8] = 0;
        w->unk_C4[0] = 0;
        func_0807FA44(w);
        break;
    case 8:
        gUnk_02034AA4 = 0;
        break;
    case 9:
        gUnk_02034AA4 = 0;
        func_080800B4(w);
        break;
    case 10:
        gUnk_02034AA4 = 0;
        func_0807FF48(w);
        break;
    default:
        gUnk_02034AA4 = 0;
        break;
    }

    switch (gUnk_02034AA8) {
    case 17:
        gUnk_02034AA8 = 0;
        func_0807B728(w);

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    case 18:
        gUnk_02034AA8 = 0;
        func_0807B7A4(w);

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    case 19:
        gUnk_02034AA8 = 0;
        func_0807B81C(w);
        func_08081A04(w);
        w->unk_9C[0] = 0;

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    case 21:
        gUnk_02034AA8 = 0;
        func_0807B894(w);

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    case 22:
        gUnk_02034AA8 = 0;
        func_0807B910(w);
        func_08081A04(w);
        w->unk_9C[0] = 0;

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    case 23:
        gUnk_02034AA8 = 0;
        func_0807B98C(w);

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    case 24:
        gUnk_02034AA8 = 0;
        func_0807B98C(w);
        func_08081A04(w);
        w->unk_9C[0] = 0;

        if (w->unk_B8 == 0) {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
        } else {
            if (gUnk_02034AAC->unk_78 & 0x1000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
            }

            gUnk_02034AAC->unk_A1 = 7;
            w->unk_B8 = 0;
        }

        TaskPoolUpdate(w);
        func_080788CC(w, 0);
        w->unk_94[0] = 0;
        w->unk_B0[0] = func_08078754(w, 0);
        func_0807E368(w, 0);
        func_080818E4();
        break;
    }

    if (w->unk_C0[w->unk_B8] != 0) {
        if (gUnk_02034AAC != 0) {
            if (gUnk_02034AAC->unk_78 & 0x4000000) {
                gUnk_02034AAC->unk_78 |= 0x4000;
                func_08080994(w);
                w->unk_C0[w->unk_B8] = 0;
                w->unk_C4[0] = 1;
                gUnk_02039B9C->unk_068 |= 0x80000000;
                SetTaskUpdate(a, func_0807FB5C);
                gUnk_02034AAC->unk_78 = (gUnk_02034AAC->unk_78 | 0x834) & ~0x1000;
                TaskPoolUpdate(w);
                m4aSongNumStart(145);
                args[0] = (u8)w->unk_B8 | (args[0] & ~0xFF);
                args[1] = (s32)&w->unk_C4[0];
                args[0] = (args[0] & ~0xFF00) | 0x200;
                TaskCreate(w, &gUnk_09EE7720[3], args);
                return 1;
            }
        } else {
            func_08080994(w);
            w->unk_C0[w->unk_B8] = 0;
            gUnk_02039B9C->unk_068 |= 0x80000000;
            SetTaskUpdate(a, func_0807FB5C);
            gUnk_02034AAC->unk_78 = (gUnk_02034AAC->unk_78 | 0x834) & ~0x1000;
            TaskPoolUpdate(w);
            m4aSongNumStart(145);
            return 1;
        }
    } else if (gUnk_02034AAC != 0 && (gUnk_02034AAC->unk_78 & 0x42) == 0x42 &&
               func_08078754(w, w->unk_B8) != 0) {
        w->unk_C0[w->unk_B8] = 1;
        w->unk_B0[0] = 0;
        gUnk_02034AAC->unk_A1 = 7;

        if (gUnk_02039B9C->unk_0F4 != 40) {
            if ((s16)((UnkStruct_08083930*)gUnk_02039B9C->unk_07C)->unk_2C > 3) {
                ((UnkStruct_08083930*)gUnk_02039B9C->unk_07C)->unk_2C -= 2;
            }

            w->unk_34[w->unk_B8] = 0;
            gUnk_02034AAC = 0;

            if (gUnk_02039B9C->unk_0F4 != 25) {
                func_0807B378(w);

                if (gUnk_02039B9C->unk_0F4 == 10) {
                    w->unk_9C[w->unk_B8] -= 2;

                    if ((s16)w->unk_9C[w->unk_B8] < 0) {
                        w->unk_9C[w->unk_B8] = 0;
                    }
                }
            }

            m4aSongNumStart(202);

            if (func_08006390() == 0) {
                func_08006290(2, 16, 20);
            }
        } else {
            w->unk_34[w->unk_B8] = 0;
            gUnk_02034AAC = 0;
            w->unk_C0[w->unk_B8] = 1;
            w->unk_B0[0] = 0;
        }
    }

    if (w->unk_C4[1] == 0 && (u8)func_080782AC(&w->unk_28, w->unk_B9) != 0) {
        arr = *(UnkStruct_080ABA80*)&gUnk_090352E4[6];

        if (!(gBtlWork->unk_068 & 0x4000)) {
            r = func_080AC5E8(&w->unk_28, w->unk_B9, w->unk_BA, &arr, &flag);
        } else {
            r = func_080AD144(&w->unk_28, w->unk_B9, w->unk_BA, &arr, flag, 1);
        }

        gUnk_02039DD4->unk_0C6 = r;

        if (r <= 105) {
            for (i = 0; i < w->unk_B9; i++) {
                w->unk_28[i]->unk_78 |= 0x10000000;
            }

            if (gUnk_02039DD4->unk_0E4 == 0) {
                TaskCreate(w, gUnk_09EE77BC, 0);
                gUnk_02039DD4->unk_0E4 = 1;
            }
        } else {
            if (w->unk_B9 == 3) {
                arr2 = *(UnkStruct_080ABA80*)&gUnk_090352E4[6];
                memset(buf, 0, 6);
                done = 0;

                for (i = 0; i < w->unk_B9; i++) {
                    arr2.unk_00[i] = w->unk_28[i]->unk_48->unk_28;
                }

                kind = func_080AE28C(&arr2, buf, w->unk_B9);

                switch (kind) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 11:
                case 15:
                case 17:
                case 19:
                case 21:
                case 23:
                case 25:
                case 27:
                case 29:
                case 31:
                case 33:
                case 35:
                case 37:
                case 39:
                case 41:
                case 43:
                case 44:
                    gUnk_02039DD4->unk_0C6 = kind;
                    done = 1;
                    break;
                }

                if (done == 0) {
                    for (i = 0; i < w->unk_B9; i++) {
                        w->unk_28[i]->unk_78 &= ~0x10000000;
                    }

                    if (gUnk_02039DD4->unk_0E4 != 0) {
                        gUnk_02039DD4->unk_0E4 = 0;
                    }
                } else {
                    for (i = 0; i < w->unk_B9; i++) {
                        w->unk_28[i]->unk_78 |= 0x10000000;
                    }

                    if (gUnk_02039DD4->unk_0E4 == 0) {
                        TaskCreate(w, gUnk_09EE77BC, 0);
                        gUnk_02039DD4->unk_0E4 = 1;
                    }
                }
            }
        }

        w->unk_C4[1] = 1;
    }

    gUnk_02039DD4->unk_0F0 = w->unk_B0[w->unk_B8];
    TaskPoolUpdate(w);
    gUnk_02039DD4->unk_0D5 = w->unk_B9;
    return 1;
}
#else
INCLUDE_ASM("card/func_0807EDEC.s");
#endif

void func_0807F99C(UnkStruct_08080268* w) {
    if (gUnk_02039DD4->unk_0EA != 0 && gUnk_02039B9C->unk_0F4 != 28 && w->unk_B9 != 0 && w->unk_BA != 0) {
        DrawSprite(w->unk_A4, 4, gUnk_09EF12E8[0], w->unk_14, w->unk_18, 0, 16, 12);
    }

    TaskPoolDraw(w);
}

void func_0807FA0C(u8* work) {
    UnkStruct_0807FA0C* w;
    u8 i;

    w = (UnkStruct_0807FA0C*)work;
    TaskPoolDestroy(w);

    for (i = 0; i <= 3; i++) {
        if (w->unk_44[i] != 0) {
            EwramFree(w->unk_44[i]);
        }
    }

    ReleaseObjTiles(w->unk_14);
    ReleaseObjPalette(w->unk_18);
}

void func_0807FA44(UnkStruct_08080268* w) {
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 &= ~0x20;
    }

    if (gUnk_02034AAC != 0) {
        gUnk_02034AAC->unk_78 &= ~0x20;
    }

    gUnk_02039DD4->unk_0CC = 0;
    gBtlWork->unk_068 |= 0x20;
    gUnk_02039DD4->unk_0EA = 0;
    gUnk_02039DD4->unk_0E4 = 0;
    w->unk_C9 = 1;
}

void func_0807FAD8(UnkStruct_08080268* w) {
    u8 i;

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_28[i]->unk_78 |= 0x20;
    }

    if (gUnk_02034AAC != 0) {
        gUnk_02034AAC->unk_78 |= 0x20;
    }

    gBtlWork->unk_068 &= ~0x20;
    gUnk_02039DD4->unk_0EA = 1;
    w->unk_C9 = 0;
}

u8 func_0807FB5C(UnkStruct_08080268* w, void* a) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    CardSlot* c;
    u16 v;

    if (gBtlWork->unk_0A0 == 4) {
        if (gUnk_02039B9C->unk_068 & 0x1000000) {
            gUnk_02039B9C->unk_068 &= ~0x1000000;
        }

        m4aSongNumStop(0x91);
        return 0;
    }

    if ((s16)gUnk_02034AAC->unk_9C == 0) {
        if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) > w->unk_C4[2]) {
            gUnk_02034AAC->unk_78 &= ~4;
            v = *(u16*)&gUnk_02034AAC->unk_3C[8] - 1;
            c = func_08076750(w, w->unk_B8, &v);

            if (c != 0) {
                args.unk_00 = &w->unk_54[w->unk_B8];
                args.unk_0C = v;
                args.unk_0E = w->unk_B8;
                args.unk_04 = c;
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
                p->unk_80 = p->unk_7C = 0;
                p->unk_A0 = 50;
                p->unk_9C = 8;
                p->unk_4C = p->unk_8C;
                p->unk_50 = p->unk_90;
                p->unk_78 |= 0x814;
                gUnk_02034AAC = p;
                w->unk_C4[2]++;
                w->unk_B0[w->unk_B8]++;
            }
        } else {
            gUnk_02039B9C->unk_068 &= ~0x80000000LL;
            gUnk_02039B9C->unk_068 &= ~0x100;
            w->unk_C4[0] = 0;
            m4aSongNumStop(0x91);
            gUnk_02034AA4 = 0;
            SetTaskUpdate(a, (void*)func_0807EDEC);
        }
    }

    if (gUnk_02034AA4 == 7) {
        w->unk_BC[w->unk_B8] = 0;
        w->unk_C4[0] = 0;
        func_0807FA44(w);
        m4aSongNumStop(0x91);
    }

    TaskPoolUpdate(w);
    return 1;
}
void func_0807FD10(UnkStruct_08080268* w, u8 n) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    CardSlot* c;
    u16 v;

    if (!(gUnk_02034AAC->unk_78 & 2)) {
        if (w->unk_B0[w->unk_B8] != 1) {
            gUnk_02034AAC->unk_78 &= ~4;
            gUnk_02034AAC->unk_9C = 4;
            v = *(u16*)&gUnk_02034AAC->unk_3C[8] + 1;

            if ((s16)v >= (s16)w->unk_A8[n]) {
                v = 0;
            }

            c = func_08076674(w, n, &v);

            if (c != 0) {
                args.unk_00 = &w->unk_54[n];
                args.unk_0C = v;
                args.unk_0E = n;
                args.unk_04 = c;
                args.unk_0F = w->unk_9C[n];

                if (c->unk_00 == 0xFFFE) {
                    p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
                } else {
                    p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
                }

                p->unk_98 = p->unk_94 = gUnk_090352E4[0];
                p->unk_A4 = 0;
                p->unk_A0 = 60;
                p->unk_9C = 4;
                p->unk_4C = p->unk_8C;
                p->unk_50 = p->unk_90;
                p->unk_78 |= 0x804;
                gUnk_02034AAC = p;
            }
        }
    }
}

void func_0807FE30(UnkStruct_08080268* w, u8 n) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    CardSlot* c;
    u16 v;

    if (!(gUnk_02034AAC->unk_78 & 2)) {
        if (w->unk_B0[w->unk_B8] != 1) {
            gUnk_02034AAC->unk_78 &= ~4;
            gUnk_02034AAC->unk_54 = 0;
            gUnk_02034AAC->unk_9C = 4;
            v = *(u16*)&gUnk_02034AAC->unk_3C[8] - 1;

            if ((s16)v < 0) {
                v = w->unk_A8[n] - 1;
            }

            c = func_08076750(w, n, &v);

            if (c != 0) {
                args.unk_00 = &w->unk_54[n];
                args.unk_0C = v;
                args.unk_0E = n;
                args.unk_04 = c;
                args.unk_0F = w->unk_9C[n];

                if (c->unk_00 == 0xFFFE) {
                    p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
                } else {
                    p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
                }

                p->unk_98 = p->unk_94 = gUnk_090352E4[0];
                p->unk_A4 = 0;
                p->unk_A0 = 60;
                p->unk_9C = 4;
                p->unk_4C = p->unk_8C;
                p->unk_50 = p->unk_90;
                p->unk_78 |= 0x804;
                gUnk_02034AAC = p;
            }
        }
    }
}

#ifndef VERSION_EU
void func_0807FF48(UnkStruct_08080268* w) {
    if ((gUnk_02034AAC->unk_78 & 0x40) != 0) {
        m4aSongNumStart(103);

        if (gUnk_02039B9C->unk_068 & 0x1000000) {
            gUnk_02039B9C->unk_068 &= ~0x1000000;
        }

        w->unk_BC[w->unk_B8] = 0;

        if (w->unk_C0[w->unk_B8] == 0) {
            w->unk_94[w->unk_B8] = *(u16*)&gUnk_02034AAC->unk_3C[8];
            gUnk_02034AAC->unk_8C = 0x10400;
            gUnk_02034AAC->unk_90 = 0x8C00;
            gUnk_02034AAC->unk_9C = 4;
            gUnk_02034AAC->unk_A1 = 7;
            gUnk_02034AAC->unk_78 &= ~4;
        } else {
            w->unk_34[w->unk_B8] = gUnk_02034AAC;
            gUnk_02034AAC->unk_98 = gUnk_090352E4[3];
            gUnk_02034AAC->unk_A3 = 4;
            gUnk_02034AAC->unk_78 &= ~4;
        }

        switch (w->unk_B8) {
        case 0:
            w->unk_B8 = 3;
            break;
        case 3:
            w->unk_B8 = 0;
            break;
        }

        if (w->unk_C0[w->unk_B8] == 0) {
            func_0807E368(w, (u8)w->unk_B8);
            gUnk_02034AAC->unk_4C = gUnk_0903401C[5][0];
            gUnk_02034AAC->unk_50 = gUnk_0903401C[5][1];
            gUnk_02034AAC->unk_A3 = 1;
            gUnk_02034AAC->unk_9C = 1;
        } else {
            gUnk_02034AAC = w->unk_34[w->unk_B8];
            gUnk_02034AAC->unk_98 = gUnk_090352E4[0];
            gUnk_02034AAC->unk_94 = gUnk_02034AAC->unk_98;
            gUnk_02034AAC->unk_A3 = 1;
            gUnk_02034AAC->unk_9C = 1;
            gUnk_02034AAC->unk_78 |= 4;
        }

        gUnk_02039DD4->unk_0D4 = w->unk_B8;
    }
}
#else
INCLUDE_ASM("card/func_0807FF48.s");
#endif
void func_080800B4(UnkStruct_08080268* w) {
#ifndef VERSION_EU
    m4aSongNumStart(103);
#endif

    if (gUnk_02039B9C->unk_068 & 0x1000000) {
        gUnk_02039B9C->unk_068 &= ~0x1000000;
    }

    w->unk_BC[w->unk_B8] = 0;

    if (w->unk_C0[w->unk_B8] == 0) {
        w->unk_94[w->unk_B8] = *(u16*)&gUnk_02034AAC->unk_3C[8];
        gUnk_02034AAC->unk_8C = 0xC800;
        gUnk_02034AAC->unk_90 = 0xB400;
        gUnk_02034AAC->unk_9C = 12;
        gUnk_02034AAC->unk_78 &= ~4;
    } else {
        w->unk_34[w->unk_B8] = gUnk_02034AAC;
        gUnk_02034AAC->unk_98 = gUnk_090352E4[3];
        gUnk_02034AAC->unk_A3 = 12;
        gUnk_02034AAC->unk_78 &= ~4;
    }

    switch (w->unk_B8) {
    case 0:
        w->unk_B8 = 3;
        break;
    case 1:
        w->unk_B8 = 0;
        break;
    case 2:
        w->unk_B8 = 3;
        break;
    case 3:
        w->unk_B8 = 0;
        break;
    }

    if (w->unk_C0[w->unk_B8] == 0) {
        func_0807E368(w, (u8)w->unk_B8);
        gUnk_02034AAC->unk_4C = 0x10400;
        gUnk_02034AAC->unk_50 = 0x8C00;
        gUnk_02034AAC->unk_9C = 12;
    } else {
        gUnk_02034AAC = w->unk_34[w->unk_B8];
        gUnk_02034AAC->unk_98 = gUnk_090352E4[0];
        gUnk_02034AAC->unk_94 = gUnk_090352E4[1];
        gUnk_02034AAC->unk_A3 = 12;
        gUnk_02034AAC->unk_9C = 12;
        gUnk_02034AAC->unk_78 |= 4;
    }

    gUnk_02039DD4->unk_0D4 = w->unk_B8;
}

void func_08080228(UnkStruct_08080268* w) {
    if (gBtlWork->unk_0F4 == 0x30) {
        if (gUnk_02034AAC->unk_A5 != 0) {
            gUnk_02034AAC->unk_A5 -= gUnk_02039DD4->unk_0C2;
        }

        gBtlWork->unk_0F8--;
    }
}

#ifdef NON_MATCHING
void func_08080268(UnkStruct_08080268* w) {
    UnkStruct_02034AAC* q;
    u8 d;
    u8 i;

    d = gUnk_02039DD4->unk_0C2;

    if (gBtlWork->unk_0F4 == 0x30) {
        if (w->unk_BA != 0) {
            for (i = 0; i < 3; i++) {
                q = w->unk_28[i];

                if (q->unk_A5 > d) {
                    q->unk_A5 -= d;
                    break;
                }

                d -= q->unk_A5;
                q->unk_A5 = 0;
            }
        }

        gBtlWork->unk_0F8--;
    }
}
#else
INCLUDE_ASM("card/func_08080268.s");
#endif

#ifdef NON_MATCHING
void func_080802D8(UnkStruct_08080268* w) {
    s32 f;
    s32 j;
    s32 t;
    u8 n;
    u8 flag;

    f = gUnk_02039B9C->unk_0F4;

    if (f == 1) {
        t = gUnk_02034AAC->unk_A5;
        n = t + 1;

        if (n > 9) {
            n = 9;
        }

        if (t <= 8) {
            TaskCreate(&gUnk_02039DD4->unk_09C, &gTaskDescHCEffectName[0x18], &gUnk_02034AAC->unk_48);
        }

        gUnk_02034AAC->unk_A5 = n;
        gUnk_02034AAC->unk_A7 = 1;
    } else if (f == 21) {
        if (gUnk_02034AAC->unk_A5 != 0) {
            n = --gUnk_02034AAC->unk_A5;
            gUnk_02034AAC->unk_A7 = 1;
        } else {
            n = 0;
            gUnk_02034AAC->unk_A7 = 1;
        }
    } else {
        n = gUnk_02034AAC->unk_A5;
    }

    if ((s16)gUnk_02039DD4->unk_0C2 > n && n != 0) {
        return;
    }

    flag = 0;

    if (gBtlWork->unk_0F4 == 2 && gUnk_02039DD4->unk_000[0]->unk_48->unk_2A == 0 && gUnk_02039DD4->unk_0E1 == 0) {
        flag = 1;
    }

    if (gBtlWork->unk_0F4 == 20 && gUnk_02039DD4->unk_000[0]->unk_48->unk_24 == 22 && gUnk_02039DD4->unk_0E1 == 0) {
        flag = 1;
    }

    if (gBtlWork->unk_0F4 == 29 && gUnk_02039DD4->unk_000[0]->unk_48->unk_2A == 2 && gUnk_02039DD4->unk_0E1 == 0) {
        flag = 1;
    }

    if (flag) {
        return;
    }

    for (j = 0; j < gUnk_02039DD4->unk_0D0; j++) {
        gUnk_02039DD4->unk_000[j]->unk_78 |= 0x200000;
    }

    gBtlWork->unk_068 |= 0x800000;

    if ((s16)gUnk_02039DD4->unk_0C2 != n) {
        if (n == 0) {
            if ((s16)gUnk_02039DD4->unk_0C2 > 9) {
                gBtlWork->unk_1CA = 9;
            } else {
                gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2;
            }
        } else {
            gBtlWork->unk_1CA = (u8)gUnk_02039DD4->unk_0C2 - n;

            if ((s8)gBtlWork->unk_1CA < -9) {
                gBtlWork->unk_1CA = -9;
            }
        }

        m4aSongNumStart(0x213);
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 &= ~0x20;
        gUnk_02034AAC->unk_78 |= 0x2000;
        func_08080228(w);
        gUnk_02039DD4->unk_000[0] = gUnk_02034AAC;
        gUnk_02039DD4->unk_0D0 = 1;
        gUnk_02039DD4->unk_0C2 = gUnk_02034AAC->unk_A5;
        gBtlWork->unk_0A4 = 0;
        func_0807BA54();
    } else {
        func_08080228(w);
        gBtlWork->unk_1CA = 0;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x400;
        m4aSongNumStart(0xCC);
        gBtlWork->unk_0A4 = 0;
        gUnk_02039DD4->unk_000[0] = gUnk_02034AAC;
        gUnk_02039DD4->unk_0D0 = 1;
        gUnk_02039DD4->unk_0C2 = gUnk_02034AAC->unk_A5;
    }
}
#else
INCLUDE_ASM("card/func_080802D8.s");
#endif

#ifdef NON_MATCHING
u8 func_08080594(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    CardSlot* c;
    u16 v;
    u16 t;

    if ((gBtlWork->unk_068 & 0x80) == 0) {
        gUnk_02039DD4->unk_000[0] = gUnk_02034AAC;

        if (gUnk_02039B9C->unk_0F4 == 1) {
            gUnk_02039DD4->unk_0C2 = gUnk_02034AAC->unk_A5 + 1;
            gUnk_02034AAC->unk_A5++;
            gUnk_02034AAC->unk_A7 = 1;

            if (gUnk_02034AAC->unk_A5 > 9) {
                gUnk_02034AAC->unk_A5 = 9;
            }

            if ((s16)gUnk_02039DD4->unk_0C2 > 9) {
                gUnk_02039DD4->unk_0C2 = 9;
            }

            TaskCreate(&gUnk_02039DD4->unk_09C, &gTaskDescHCEffectName[0x18], &gUnk_02034AAC->unk_48);
        } else if (gUnk_02039B9C->unk_0F4 == 21) {
            if (gUnk_02034AAC->unk_A5 != 0) {
                gUnk_02039DD4->unk_0C2 = gUnk_02034AAC->unk_A5 - 1;
                gUnk_02034AAC->unk_A5--;
                gUnk_02034AAC->unk_A7 = 1;
            } else {
                gUnk_02039DD4->unk_0C2 = 0;
                gUnk_02034AAC->unk_A7 = 1;
            }
        } else {
            gUnk_02039DD4->unk_0C2 = gUnk_02034AAC->unk_A5;
        }

        gUnk_02039DD4->unk_0D0 = 1;
        gUnk_02034AAC->unk_78 |= 0x2000;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 |= 0x10000000;
    } else {
        if (gBtlWork->unk_0A4 == 0) {
            gUnk_02034AAC->unk_A1 = 0;
            return 1;
        }

        if ((gBtlWork->unk_068 & 0x20) == 0) {
            func_080802D8(w);
        } else {
            func_080802D8(w);
        }

        gBtlWork->unk_068 |= 0x10000000;
    }

    w->unk_B0[w->unk_B8]--;

    if ((gUnk_02034AAC->unk_48->unk_1E & 2) && (gUnk_02034AAC->unk_78 & 0x2000)) {
        (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_0A = 1;
    }

    if (gUnk_02034AAC->unk_48->unk_1E & 8) {
        (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_0A = 1;
    }

    if (gUnk_02034AAC->unk_A6 == 1) {
        (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_0A = 1;

        if ((u16)func_0807885C(w, 0) == 0) {
            (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_0A = 0;
        }
    }

    w->unk_1C[0] = gUnk_02034AAC;
    gUnk_02034AAC->unk_A1 = 5;
    gUnk_02034AAC->unk_A0 = 50;
    (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_08 = 1;
    v = *(u16*)&gUnk_02034AAC->unk_3C[8] + 1;

    if ((s16)v >= (s16)w->unk_A8[w->unk_B8]) {
        v = 0;
    }

    func_080819E8();

    if (gUnk_02039B9C->unk_0F4 == 37) {
        t = func_080792AC();
        func_08081744(w);
        gUnk_02039DD4->unk_0CE = t;
        func_08081740(w, gUnk_02039DD4->unk_0CE);
        func_08081760(w);
        gUnk_02039B9C->unk_0F8 = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E;
    }

    gUnk_02034AAC->unk_78 &= ~0x40;
    gUnk_02034AAC = 0;
    c = func_08076674(w, w->unk_B8, &v);

    if (c != 0) {
        args.unk_00 = &w->unk_54[w->unk_B8];
        args.unk_0C = v;
        args.unk_0E = w->unk_B8;
        args.unk_04 = c;
        args.unk_0F = w->unk_9C[w->unk_B8];

        if (*(s32*)c == 0xFFFE) {
            p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
        } else {
            p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
        }

        p->unk_98 = p->unk_94 = gUnk_090352E4[0];
        p->unk_A4 = 0;
        p->unk_A0 = 60;
        p->unk_9C = 4;
        p->unk_4C = p->unk_8C;
        p->unk_50 = p->unk_90;
        p->unk_78 |= 0x804;
        gUnk_02034AAC = p;
    }

    if (gUnk_02039B9C->unk_0F4 == 40 && (gUnk_02034AAC->unk_78 & 0x100000) &&
        w->unk_B0[w->unk_B8] == 1) {
        w->unk_B0[w->unk_B8] = 0;
        gUnk_02034AAC->unk_A1 = 7;
        w->unk_34[w->unk_B8] = 0;
        gUnk_02034AAC = 0;
        w->unk_C0[0] = 1;
        m4aSongNumStart(202);

        if (func_08006390() == 0) {
            func_08006290(2, 16, 20);
        }
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_08080594.s");
#endif

#ifdef NON_MATCHING
void func_08080994(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    UnkStruct_02034AAC* q;
    CardSlot* c;
    u16 v;

    w->unk_C4[2] = 0;
    func_08078914((UnkStruct_08078754*)w, w->unk_B8);

    if (func_08078754((UnkStruct_08078754*)w, w->unk_B8) != 0) {
        v = w->unk_A8[w->unk_B8] - 1;
        c = func_08076750(w, w->unk_B8, &v);

        if (c != 0) {
            args.unk_00 = w->unk_54[w->unk_B8];
            args.unk_0C = v;
            args.unk_0E = w->unk_B8;
            args.unk_04 = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->unk_00 == 0xFFFE) {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
            } else {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
            }

            p->unk_80 = p->unk_7C = 0;
            p->unk_98 = p->unk_94 = gUnk_090352E4[0];
            p->unk_A4 = 0;
            p->unk_A0 = 50;
            p->unk_4C = p->unk_8C;
            p->unk_50 = p->unk_90;
            p->unk_9C = 8;
            p->unk_78 |= 0x814;
            gUnk_02034AAC = p;
            w->unk_C4[2]++;
            w->unk_B0[w->unk_B8]++;
        }
    } else {
        args.unk_00 = w->unk_54[w->unk_B8];
        args.unk_0C = 0xFFFF;
        args.unk_04 = (CardSlot*)w->unk_44[w->unk_B8];
        args.unk_0E = w->unk_B8;
        q = ((UnkStruct_02034AAC**)TaskCreate(w, &gUnk_09EE49CC[0x18], &args))[1];
        q->unk_80 = q->unk_7C = 0;
        q->unk_98 = q->unk_94 = gUnk_090352E4[0];
        q->unk_4C = q->unk_8C;
        q->unk_50 = q->unk_90;
        q->unk_A0 = 50;
        q->unk_78 |= 0x806;
        gUnk_02034AAC = q;
    }

    func_080818E4();
}
#else
INCLUDE_ASM("card/func_08080994.s");
#endif
#ifdef NON_MATCHING
u8 func_08080B44(UnkStruct_08080268* w, void* a) {
    UnkStruct_0807FD10_Args args;
    u16 t;
    u8 n;
    CardSlot* c;
    UnkStruct_02034AAC* p;
    u16 v;

    if (!(gUnk_02034AAC->unk_78 & 0x40)) {
        return 1;
    }

    if (gUnk_02034AAC->unk_78 & 2) {
        return 1;
    }

    if (gUnk_02039DD4->unk_0B0 == 112) {
        return 1;
    }

    if (gUnk_02039DD4->unk_0B0 == 109) {
        return 1;
    }

    w->unk_C4[1] = 0;
    gUnk_02039DD4->unk_0E4 = 0;
    m4aSongNumStart(140);
    gUnk_02034AAC->unk_78 = (gUnk_02034AAC->unk_78 & ~0x40) | 0x200;
    gUnk_02034AAC->unk_A1 = 6;
    gUnk_02034AAC->unk_9F = w->unk_B9;
    gUnk_02034AAC->unk_A0 = (3 - w->unk_B9) * 4 + 50;
    w->unk_28[w->unk_B9] = gUnk_02034AAC;
    ((UnkStruct_02034AAC**)&gUnk_02039DD4->unk_018[0x0C])[gUnk_02039DD4->unk_0DF] = gUnk_02034AAC;
    (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_07 = 1;

    if (gUnk_02039B9C->unk_0F4 == 1) {
        n = gUnk_02034AAC->unk_A5 + 1;

        if (n > 9) {
            n = 9;
        }

        gUnk_02034AAC->unk_A5 = n;
        gUnk_02034AAC->unk_A7 = 1;
        TaskCreate(&gUnk_02039DD4->unk_09C, &gTaskDescHCEffectName[0x18], &gUnk_02034AAC->unk_48);
    } else if (gUnk_02039B9C->unk_0F4 == 21) {
        if (gUnk_02034AAC->unk_A5 != 0) {
            n = gUnk_02034AAC->unk_A5 - 1;
            gUnk_02034AAC->unk_A5 = n;
        } else {
            n = 0;
        }

        gUnk_02034AAC->unk_A7 = 1;
    } else {
        n = gUnk_02034AAC->unk_A5;
    }

    w->unk_BA += n;
    w->unk_B9++;
    gUnk_02039DD4->unk_0DF++;

    if (w->unk_BA != 0) {
        func_080038E4((UnkStruct_080038C8*)w->unk_14, gUnk_09EF12E8[0], gUnk_093FBAB8[w->unk_BA - 1]);
        w->unk_C4[3] = 8;
    }

    w->unk_B0[w->unk_B8]--;

    if (gUnk_02034AAC->unk_48->unk_1E & 8) {
        (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_0A = 1;
    }

    (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_08 = 1;
    v = *(u16*)&gUnk_02034AAC->unk_3C[8] + 1;

    if ((s16)v >= (s16)w->unk_A8[w->unk_B8]) {
        v = 0;
    }

    gUnk_02034AAC->unk_78 &= ~0x40;
    gUnk_02034AAC = 0;

    if (gUnk_02039B9C->unk_0F4 == 37) {
        t = func_080792AC();
        func_08081744(w);
        gUnk_02039DD4->unk_0CE = t;
        func_08081740(w, gUnk_02039DD4->unk_0CE);
        func_08081760(w);
        gUnk_02039B9C->unk_0F8 = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E;
    }

    c = func_08076674(w, w->unk_B8, &v);

    if (c != 0) {
        args.unk_00 = &w->unk_54[w->unk_B8];
        args.unk_0C = v;
        args.unk_0E = w->unk_B8;
        args.unk_04 = c;
        args.unk_0F = w->unk_9C[w->unk_B8];

        if (*(s32*)c == 0xFFFE) {
            p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
        } else {
            p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
        }

        p->unk_94 = p->unk_98 = gUnk_090352E4[0];
        p->unk_A4 = 0;
        p->unk_A0 = 60;
        p->unk_9C = 4;
        p->unk_4C = p->unk_8C;
        p->unk_50 = p->unk_90;
        p->unk_78 |= 0x804;
        gUnk_02034AAC = p;
    }

    if (gUnk_02039B9C->unk_0F4 == 40 && (gUnk_02034AAC->unk_78 & 0x100000) &&
        w->unk_B0[w->unk_B8] == 1) {
        w->unk_B0[w->unk_B8] = 0;
        gUnk_02034AAC->unk_A1 = 7;
        w->unk_34[w->unk_B8] = 0;
        gUnk_02034AAC = 0;
        w->unk_C0[0] = 1;
        m4aSongNumStart(202);

        if (func_08006390() == 0) {
            func_08006290(2, 16, 20);
        }
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_08080B44.s");
#endif

INCLUDE_ASM("card/func_08080EB4.s");
#ifdef NON_MATCHING
void func_08081210(UnkStruct_08080268* w) {
    u8 i;
    u8 n;

    n = 0;

    for (i = 0; i < w->unk_B9; i++) {
        if (w->unk_28[i]->unk_78 & 0x40) {
            n++;
        }
    }

    if (n < w->unk_B9) {
        return;
    }

    gUnk_02039DD4->unk_0C0 = 0;
    gUnk_02039DD4->unk_0E4 = 0;
    w->unk_C4[1] = 0;

    if (!(gBtlWork->unk_068 & 0x80)) {
        gUnk_02039DD4->unk_0D0 = w->unk_B9;

        for (i = 0; i < w->unk_B9; i++) {
            gUnk_02039DD4->unk_000[i] = w->unk_28[i];
            w->unk_28[i]->unk_A0 = i * 4 + 50;

            if (w->unk_28[i]->unk_48->unk_1E & 2) {
                (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 1;
            }

            w->unk_28[i]->unk_78 |= 0xA000;
        }

        gUnk_02039DD4->unk_0C2 = w->unk_BA;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x10000000;
        gUnk_02039DD4->unk_0E2 = 1;
    } else {
        if (gBtlWork->unk_0A4 == 0) {
            return;
        }

        if (!(gBtlWork->unk_068 & 0x20)) {
            func_08080EB4(w);
            gBtlWork->unk_068 |= 0x10000000;
        } else {
            func_08080EB4(w);
            gBtlWork->unk_068 |= 0x10000000;
        }
    }

    for (i = 0; i < w->unk_B9; i++) {
        (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_07 = 0;

        if (w->unk_28[i]->unk_48->unk_1E & 2) {
            (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 1;
        } else if (i == 0 && gUnk_02039B9C->unk_0F4 != 15) {
            (*(CardSlot**)w->unk_28[0]->unk_3C)->unk_0A = 1;
        }
    }

    if (func_0807885C((UnkStruct_08078754*)w, 0) == 0) {
        for (i = 0; i < w->unk_B9; i++) {
            if (w->unk_28[i]->unk_46 == 0) {
                (*(CardSlot**)w->unk_28[i]->unk_3C)->unk_0A = 0;
                break;
            }
        }
    }

    for (i = 0; i < w->unk_B9; i++) {
        w->unk_1C[i] = w->unk_28[i];
        w->unk_28[i]->unk_A1 = 5;
        w->unk_28[i] = 0;
    }

    func_080819E8();
    w->unk_B9 = 0;
    gUnk_02039DD4->unk_0DF = 0;
    w->unk_BA = 0;
    func_0807AE78((UnkStruct_08078754*)w);
    w->unk_C4[1] = 0;
}
#else
INCLUDE_ASM("card/func_08081210.s");
#endif
#ifdef NON_MATCHING
u8 func_080814BC(UnkStruct_08080268* w) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    UnkStruct_02034AAC* q;
    CardSlot* c;
    u16 v;

    if ((gUnk_02034AAC->unk_78 & 2) == 0) {
        if (gUnk_02039DD4->unk_0CE == 0) {
            gUnk_02039DD4->unk_0CE = gUnk_02034AAC->unk_48->unk_24;
            func_08081740(w, gUnk_02039DD4->unk_0CE);
            func_08081760(w);
        } else {
            func_08081744(w);
            gUnk_02039DD4->unk_0CE = gUnk_02034AAC->unk_48->unk_24;
            func_08081740(w, gUnk_02039DD4->unk_0CE);
            func_08081760(w);
            gUnk_02039DD4->unk_0EC = 1;
        }

        (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_0A = 1;
        gUnk_02034AAC->unk_A1 = 10;
        gUnk_02034AAC->unk_A0 = 50;
        gUnk_02034AAC->unk_78 &= ~0x40;

        if (w->unk_BA > 1) {
            func_080038E4(w->unk_14, gUnk_09EF12E8[0], gUnk_093FBAB8[w->unk_BA - 1]);
            w->unk_C4[3] = 8;
        }

        (*(CardSlot**)gUnk_02034AAC->unk_3C)->unk_08 = 1;
        q = gUnk_02034AAC;
        v = *(u16*)&q->unk_3C[8] + 1;

        if ((s16)v >= (s16)w->unk_A8[w->unk_B8]) {
            v = 0;
        }

        q->unk_78 &= ~0x40;
        gUnk_02034AAC = 0;
        w->unk_B0[w->unk_B8]--;
        c = func_08076674(w, w->unk_B8, &v);

        if (c != 0) {
            args.unk_00 = w->unk_54[w->unk_B8];
            args.unk_0C = v;
            args.unk_0E = w->unk_B8;
            args.unk_04 = c;
            args.unk_0F = w->unk_9C[w->unk_B8];

            if (c->unk_00 == 0xFFFE) {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49FC, &args))[1];
            } else {
                p = ((UnkStruct_02034AAC**)TaskCreate(w, gUnk_09EE49CC, &args))[1];
            }

            p->unk_98 = p->unk_94 = gUnk_090352E4[0];
            p->unk_A4 = 0;
            p->unk_A0 = 60;
            p->unk_9C = 4;
            p->unk_4C = p->unk_8C;
            p->unk_50 = p->unk_90;
            p->unk_78 |= 0x844;
            gUnk_02034AAC = p;
        } else {
            args.unk_00 = w->unk_54[w->unk_B8];
            args.unk_0C = 0xFFFF;
            args.unk_04 = (CardSlot*)w->unk_44[w->unk_B8];
            args.unk_0E = w->unk_B8;
            p = ((UnkStruct_02034AAC**)TaskCreate(w, &gUnk_09EE49CC[0x18], &args))[1];
            p->unk_98 = p->unk_94 = gUnk_090352E4[0];
            p->unk_A4 = 0;
            p->unk_A0 = 50;
            p->unk_9C = 4;
            p->unk_78 |= 0x846;
            gUnk_02034AAC = p;
        }

        if (gUnk_02034AAC == 0) {
            w->unk_C0[w->unk_B8] = 1;
        }
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_080814BC.s");
#endif
void func_08081740(UnkStruct_08080268* w, u16 n) {
}
void func_08081744(UnkStruct_08080268* w) {
    gUnk_02039B9C->unk_0F4 = gUnk_02039DD4->unk_0CE;
}

#ifndef VERSION_EU
void func_08081760(UnkStruct_08080268* w) {
    if (gBtlWork->unk_0F4 != 41) {
        gUnk_02039B9C->unk_0F4 = gUnk_02039DD4->unk_0CE;
    } else {
        gUnk_02039B9C->unk_0F4 = 0;
        gUnk_02039DD4->unk_0CE = 0;
    }

    if (gUnk_02039DD4->unk_0CE == 45) {
        if (gBtlWork->unk_0F4 != 0) {
            gUnk_02039DD4->unk_0CE = gUnk_02039DD4->unk_0CC;
            gUnk_02039B9C->unk_0F4 = gBtlWork->unk_0F4;
        } else {
            gBtlWork->unk_0F4 = 0;
            gUnk_02039DD4->unk_0CE = 0;
        }
    }

    if (gUnk_02039B9C->unk_0F4 == 47) {
        w->unk_9C[0] = 2;
        w->unk_9C[1] = 2;
    }

    if (gUnk_02039B9C->unk_0F4 == 41) {
        gUnk_02039DD4->unk_0CC = 0;
        gBtlWork->unk_0F4 = 0;
        gBtlWork->unk_0F8 = 0;
        gUnk_02039B9C->unk_0F4 = 0;
        gUnk_02039B9C->unk_0F8 = 0;
    }
}
#else
INCLUDE_ASM("card/func_08081760.s");
#endif

u8 func_08081828(void) {
    return gUnk_02039DD4->unk_0ED;
}

u8 func_08081838(void) {
    return gUnk_02039DD4->unk_0D4;
}

u8 func_08081848(void) {
    return gUnk_02039DD4->unk_0C2;
}

s32 func_08081858(void) {
    if (gUnk_02034AAC != 0) {
        return gUnk_02034AAC->unk_48->unk_24;
    }

    return 145;
}

u8 func_08081870(void) {
    if (gUnk_02034AAC != 0) {
        return gUnk_02034AAC->unk_A5;
    }

    return 0xFF;
}

u8 func_08081888(void) {
    if (gUnk_02039B9C->unk_0F4 == 38) {
        if (gUnk_02034AAC->unk_48->unk_2A != 1) {
            return 1;
        }

        if (!(gUnk_02034AAC->unk_48->unk_1E & 4)) {
            return 1;
        }

        return 0;
    } else if (gUnk_02039B9C->unk_0F4 == 39) {
        if (gUnk_02034AAC->unk_48->unk_2A != 1) {
            return 1;
        }

        if (gUnk_02034AAC->unk_48->unk_1E & 4) {
            return 1;
        }

        return 0;
    }

    return 1;
}

void func_080818E4(void) {
    switch (gUnk_02039B9C->unk_0F4) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 30:
    case 31:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 42:
    case 51:
    case 53:
        gUnk_02039B9C->unk_0F8--;
        break;
    }
}

void func_080819E8(void) {
    if (gUnk_02039B9C->unk_0F4 == 50) {
        gUnk_02039B9C->unk_0F8--;
    }
}

void func_08081A04(void) {
    gUnk_02039DD4->unk_0F8 = 0;
    gUnk_02039DD4->unk_0FE = 0;
    gUnk_02039DD4->unk_102 = 4;
    gUnk_02039DD4->unk_106 = 2;
    gUnk_02039DD4->unk_108[1] = 0;
}

void func_08081A3C(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    u16 v;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    v = *(u16*)&p->unk_3C[8];

    if ((s16)v != -1) {
        func_08082DA4(&p->unk_38, &p->unk_48, (u8)v);

        if ((*(CardSlot**)p->unk_3C)->unk_00 == 0xFFFE) {
            p->unk_78 |= 0x100000;
        }
    } else {
        p->unk_78 = 2;
    }

    if ((*(CardSlot**)p->unk_3C)->unk_00 & 0x8000) {
        p->unk_A6 = 1;
    } else {
        p->unk_A6 = 0;
    }

    p->unk_54 = 0;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 80;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0x2400;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_0903401C[5][0];
    p->unk_90 = gUnk_0903401C[5][1];
    p->unk_4C = gUnk_0903401C[4][0];
    p->unk_50 = gUnk_0903401C[4][1];

    if (p->unk_48 != 0) {
        p->unk_A5 = p->unk_48->unk_20;
    } else {
        p->unk_A5 = 0;
    }

    p->unk_A7 = 0;
    p->unk_78 |= 0x24;
    p->unk_78 &= ~0x40;
}
u8 func_08081B70(UnkStruct_02034AAC* p, void* a) {
    if ((p->unk_78 & 0x84) == 4) {
        func_0807C33C(p);
        p->unk_78 |= 0x80;
    }

    if (p->unk_78 & 0x10) {
        p->unk_9C = 4;
        SetTaskUpdate(a, (void*)func_080829D0);
        return 1;
    }

    if (p->unk_78 & 4) {
        if ((s16)p->unk_9C > 0) {
            p->unk_78 &= ~0x40;
            ApproachValue(&p->unk_54, 0x100, p->unk_9C);
            p->unk_9C--;
        } else {
            p->unk_78 |= 0x40;
        }
    } else if ((s16)p->unk_9C > 0) {
        p->unk_78 &= ~0x40;
        ApproachValue(&p->unk_54, 0, p->unk_9C);

        if (p->unk_78 & 0x80) {
            func_0807C39C(p);
            p->unk_78 &= ~0x80;
        }

        p->unk_9C--;
    } else {
        return 0;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    ApproachValue(&p->unk_4C, p->unk_8C, p->unk_9C);
    ApproachValue(&p->unk_50, p->unk_90, p->unk_9C);
    p->unk_5F += 4;

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08082A64);
    }

    return func_08082C98(p, a);
}
#ifdef NON_MATCHING
void func_08081C98(UnkStruct_02034AAC* p) {
    void* gfx;
    s32 aff;
    u16 y;
    u8 j;

    gfx = p->unk_48->unk_00;

    if (func_080A42C8() == 1) {
        y = p->unk_50 >> 8;
    } else {
        y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    if (!(p->unk_78 & 0x20)) {
        return;
    }

    if (!(p->unk_78 & 0x80)) {
        return;
    }

    if (p->unk_54 == 0) {
        return;
    }

    if (!(p->unk_78 & 0x200)) {
        if (gUnk_02039B9C->unk_0F4 == 7) {
            return;
        }

        aff = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 0);
        DrawSprite(p->unk_4C >> 8, y, gUnk_08F709B0[p->unk_48->unk_2A].unk_00, (&gUnk_02039DD4->tiles)[p->unk_48->unk_2A], gUnk_02039DD4->palette, aff, 0x410, (u16)(p->unk_A0 - 1));
        DrawSprite(p->unk_4C >> 8, y, gfx, p->unk_00, p->palette, aff, 0x410, p->unk_A0);
        j = p->unk_A5;

        if (p->unk_48->unk_2A == 3) {
            return;
        }

        if (p->unk_A7 != 0) {
            DrawSprite(p->unk_4C >> 8, y, gUnk_09EE98C0[j], gUnk_02039DD4->tiles7, gUnk_02039DD4->palette2, aff, 0x410, (u16)(p->unk_A0 - 2));
        } else if (p->unk_A6 != 0) {
            DrawSprite(p->unk_4C >> 8, y, gUnk_09EE9894[j], gUnk_02039DD4->tiles6, gUnk_02039DD4->palette2, aff, 0x410, (u16)(p->unk_A0 - 2));
        } else {
            DrawSprite(p->unk_4C >> 8, y, gUnk_09EE981C[j], gUnk_02039DD4->tiles5, gUnk_02039DD4->palette, aff, 0x410, (u16)(p->unk_A0 - 2));
        }

        if (p->unk_A6 != 0) {
            DrawSprite(p->unk_4C >> 8, y, gUnk_02039DD4->unk_094, gUnk_02039DD4->unk_040, gUnk_02039DD4->palette, aff, 0x410, (u16)(p->unk_A0 - 3));
        }

        return;
    }

    if (gUnk_02039B9C->unk_0F4 == 28) {
        return;
    }

    aff = AllocObjAffine(0, p->unk_54, p->unk_58, 0);
    DrawSprite(p->unk_4C >> 8, y, p->unk_48->unk_10, p->unk_00, p->palette, aff, 0x410, p->unk_A0);
    j = p->unk_A5;

    if (p->unk_48->unk_2A == 3) {
        return;
    }

    if (p->unk_A7 != 0) {
        DrawSprite((p->unk_4C >> 8) - 3, y - 4, gUnk_09EE981C[j], gUnk_02039DD4->tiles7, gUnk_02039DD4->palette2, aff, 0x410, (u16)(p->unk_A0 - 10));

        if (p->unk_A6 == 0) {
            return;
        }
    } else if (p->unk_A6 != 0) {
        DrawSprite((p->unk_4C >> 8) - 3, y - 4, gUnk_09EE981C[j], gUnk_02039DD4->tiles6, gUnk_02039DD4->palette2, aff, 0x410, (u16)(p->unk_A0 - 10));
    } else {
        DrawSprite((p->unk_4C >> 8) - 3, y - 4, gUnk_09EE981C[j], gUnk_02039DD4->tiles5, gUnk_02039DD4->palette, aff, 0x410, (u16)(p->unk_A0 - 10));
        return;
    }

    DrawSprite(p->unk_4C >> 8, y, gUnk_02039DD4->unk_098, gUnk_02039DD4->unk_050, gUnk_02039DD4->palette, aff, 0x410, (u16)(p->unk_A0 - 11));
}
#else
INCLUDE_ASM("card/func_08081C98.s");
#endif

void NO_Card_2(UnkStruct_02034AAC* p) {
    void* gfx;
    u16 y;

    gfx = gUnk_08F709B0[0].unk_04;

    if (func_080A42C8() == 1) {
        y = p->unk_50 >> 8;
    } else {
        y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
    }

    if (p->unk_78 & 0x20) {
        if (p->unk_78 & 0x80) {
            if (p->unk_54 != 0) {
                if (gUnk_02039B9C->unk_0F4 != 7) {
                    DrawSprite(p->unk_4C >> 8, y, gfx, p->unk_04, gUnk_02039DD4->palette, 0, 0x410, (u16)(p->unk_A0 - 1));
                }
            }
        }
    }
}

void func_080820F4(UnkStruct_02034AAC* p) {
    func_0807C39C(p);

    if (p->unk_20 != 0) {
        EwramFree(p->unk_20);
    }
}

void func_0808210C(UnkStruct_02034AAC* p) {
    if (p->unk_A1 == 6) {
        return;
    }

    if (p->unk_54 == 0) {
        if (p->unk_78 & 0x80) {
            func_0807C39C(p);
            p->unk_78 &= ~0x80;
        }
    } else {
        if ((p->unk_78 & 0x80) == 0) {
            func_0807C33C(p);
            p->unk_78 |= 0x80;
        }
    }
}

u8 func_08082154(UnkStruct_02034AAC* p, void* a) {
    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x10000000;

        if (p->unk_48->unk_2A == 0) {
            func_080838CC();
        }

        SetTaskUpdate(a, (void*)func_08082AE4);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        SetTaskUpdate(a, (void*)func_08082E0C);
    }

    return 1;
}

u8 func_08082224(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_4C, 0x7800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x8400, p->unk_9C);
    p->unk_A0 = 80;

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C |= 0xFFFF;
    }

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_08082154);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = 16;
            p->unk_9E = 1;
            p->unk_78 |= 0x2000;
            SetTaskUpdate(a, (void*)func_08082B48);

            if (p->unk_48->unk_1E & 2) {
                (*(u8**)p->unk_3C)[6] = 0;
            }

            m4aSongNumStart(0xCC);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        SetTaskUpdate(a, (void*)func_08082B48);
    }

    return 1;
}
u8 func_08082348(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_8C, gUnk_0903404C[0], p->unk_9C);
    ApproachValue(&p->unk_90, gUnk_0903404C[1], p->unk_9C);
    ApproachValue(&p->unk_84, p->unk_88, p->unk_9C);
    ApproachValue(&p->unk_54, 0x100, p->unk_9C);
    ApproachValue(&p->unk_58, 0x100, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C = 0;
    }

    func_08082BF8(p);

    switch (p->unk_9F) {
    case 0:
        p->unk_A0 = 50;
        break;
    case 1:
        p->unk_A0 = 40;
        break;
    case 2:
        p->unk_A0 = 60;
        break;
    }

    if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        gUnk_02039DD4->unk_0E2 = 0;
        SetTaskUpdate(a, (void*)func_08082E0C);
    }

    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0--;
        gUnk_02039DD4->unk_0C2 = 0;

        if (gUnk_02039DD4->unk_0D0 == 0) {
            gBtlWork->unk_068 &= ~0x20;
            gBtlWork->unk_068 &= ~0x80;
            func_080838A0();
        }

        gUnk_02039DD4->unk_0E2 = 0;
        gBtlWork->unk_068 &= ~0x10000000;
        SetTaskUpdate(a, (void*)func_08082AE4);
    }

    return 1;
}
u8 func_080824C8(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_8C, gUnk_0903404C[0], p->unk_9C);
    ApproachValue(&p->unk_90, gUnk_0903404C[1], p->unk_9C);
    ApproachValue(&p->unk_84, p->unk_88, p->unk_9C);
    ApproachValue(&p->unk_54, 0x100, p->unk_9C);
    ApproachValue(&p->unk_58, 0x100, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    } else {
        p->unk_9C = 0;
    }

    func_08082BF8(p);

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_08082348);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = 16;
            p->unk_9E = 1;
            gUnk_02039DD4->unk_0C0 = 0;
            gUnk_02039DD4->unk_0E2 = 0;
            SetTaskUpdate(a, (void*)func_08082B48);
            m4aSongNumStart(0xCC);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        gUnk_02039DD4->unk_0E2 = 0;
        SetTaskUpdate(a, (void*)func_08082B48);
    }

    return 1;
}
u8 func_08082618(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);
    s32 v;

    func_0807C2EC(p);

    if (!(p->unk_78 & 0x10000000)) {
        f = func_080827E0;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    if (p->unk_78 & 0x40000000) {
        SetTaskUpdate(a, (void*)func_08082FF0);
        return 1;
    }

    if (p->unk_A1 == 5) {
        if (p->unk_78 & 0x8000) {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            f = func_08082348;
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            f = func_080824C8;
        }

        SetTaskUpdate(a, (void*)f);
        p->unk_78 &= ~0x200;
        func_08082F24(p);
        return f(p, a);
    }

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    if (p->unk_78 & 0x20) {
        switch (p->unk_A2) {
        case 0:
            p->unk_50 -= 0x80;
            v = gUnk_0903401C[3 - p->unk_9F][1] - 0x200;

            if (p->unk_50 <= v) {
                p->unk_50 = v;
                p->unk_A2 = 1;
            }
            break;
        case 1:
            p->unk_50 += 0x200;
            v = gUnk_0903401C[3 - p->unk_9F][1];

            if (p->unk_50 >= v) {
                p->unk_50 = v;
                p->unk_A2 = 0;
                p->unk_9C = 16;
            }
            break;
        }
    } else {
        ApproachValue(&p->unk_4C, gUnk_0903401C[4][0], p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_0903401C[4][1], p->unk_9C);
    }

    p->unk_5F += 4;
    return 1;
}
u8 func_080827E0(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);
    u16 t;

    if (gBtlWork->unk_070 == 1) {
        return 1;
    }

    func_0807C2EC(p);

    if (p->unk_78 & 0x20) {
        ApproachValue(&p->unk_4C, gUnk_0903401C[3 - p->unk_9F][0], p->unk_9C);
        ApproachValue(&p->unk_58, 179, p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_0903401C[3 - p->unk_9F][1], p->unk_9C);
        ApproachValue(&p->unk_54, 179, p->unk_9C);
    } else {
        ApproachValue(&p->unk_4C, gUnk_0903401C[4][0], p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_0903401C[4][1], p->unk_9C);
    }

    t = p->unk_9C;

    if ((s16)t > 0) {
        p->unk_9C = t - 1;
        p->unk_78 &= ~0x40;
    } else {
        p->unk_9C = 0;
        p->unk_54 = 0x100;
        p->unk_58 = 0x100;
        p->unk_78 |= 0x40;

        if (p->unk_78 & 0x10000000) {
            p->unk_9C = p->unk_9F * 8;
            fn = func_08082618;
            SetTaskUpdate(a, fn);
            return fn(p, a);
        }
    }

    if (p->unk_78 & 0x40000000) {
        SetTaskUpdate(a, func_08082FF0);
        return 1;
    }

    if (p->unk_A1 == 5) {
        if (p->unk_78 & 0x8000) {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            fn = func_08082348;
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            fn = func_080824C8;
        }

        SetTaskUpdate(a, fn);
        p->unk_78 &= ~0x200;
        func_08082F24(p);
        return fn(p, a);
    }

    p->unk_5F += 4;
    return 1;
}

u8 func_080829D0(UnkStruct_02034AAC* p, void* a) {
    u8 (*f)(UnkStruct_02034AAC*, void*);

    if (!(p->unk_78 & 0x20)) {
        f = func_08082A64;
        SetTaskUpdate(a, (void*)f);
        return f(p, a);
    }

    ApproachValue(&p->unk_54, 0x100, p->unk_9C);
    p->unk_9C--;

    if (p->unk_9C == 0) {
        p->unk_78 &= ~0x10;
        p->unk_54 = 0x100;

        if (p->unk_78 & 0x100000) {
            gUnk_02039DD4->unk_0E8 = 0;
            SetTaskUpdate(a, (void*)Reload_Card_1);
        } else {
            SetTaskUpdate(a, (void*)func_08081B70);
        }
    }

    return 1;
}

u8 func_08082A64(UnkStruct_02034AAC* p, void* a) {
    u8 (*fn)(UnkStruct_02034AAC*, void*);

    if (p->unk_A1 == 7) {
        return 0;
    }

    p->unk_84 += -p->unk_84 >> 1;
    p->unk_4C += (gUnk_0903401C[4][0] - p->unk_4C) >> 1;
    p->unk_50 += (gUnk_0903401C[4][1] - p->unk_50) >> 1;

    if (p->unk_78 & 0x20) {
        if (p->unk_78 & 0x100000) {
            fn = Reload_Card_1;
            SetTaskUpdate(a, fn);
            return fn(p, a);
        } else {
            do {
                fn = func_08081B70;
                SetTaskUpdate(a, fn);
            } while (0);

            return fn(p, a);
        }
    }

    return 1;
}

u8 func_08082AE4(UnkStruct_02034AAC* p) {
    ApproachValue(&p->unk_50, 0x8200, p->unk_9C);
    *(u16*)&p->unk_9C =
        *(s16*)&p->unk_9C > 0 ? p->unk_9C - 1 : 0;

    if (*(s16*)&p->unk_9C == 0) {
        *(u16*)&p->unk_9C = 0;
        p->unk_5E += p->unk_9E;
        p->unk_9E++;

        if (p->unk_54 <= 25) {
            return 0;
        }

        p->unk_54 -= 25;
        p->unk_58 -= 25;
    }

    return 1;
}

u8 func_08082B48(UnkStruct_02034AAC* p) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->unk_4C -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        gBtlWork->unk_068 &= ~0x10000000;
        p->unk_78 &= ~0x80;
        return 0;
    }

    return 1;
}

void func_08082BF8(UnkStruct_02034AAC* p) {
    s32 t;

    if (p->unk_80 - p->unk_7C > 0x7F00) {
        p->unk_7C += 0x10000;
    }

    if (p->unk_80 - p->unk_7C <= 255) {
        t = p->unk_7C - 0x10000;

        if (p->unk_80 - t < p->unk_7C - p->unk_80) {
            p->unk_7C = t;
        }
    }

    p->unk_7C += (p->unk_80 - p->unk_7C) >> 2;
    p->unk_4C = gSineTable[(p->unk_7C >> 8) & 0xFF] * (p->unk_84 >> 8) + p->unk_8C;
    p->unk_50 = -gSineTable[((p->unk_7C >> 8) & 0xFF) + 64] * (p->unk_84 >> 8) + p->unk_90;
}
u8 func_08082C98(UnkStruct_02034AAC* p, void* a) {
    switch (p->unk_A1) {
    case 5:
        p->unk_9C = 10;
        p->unk_A0 -= 4;
        p->unk_54 = 0x100;
        SetTaskUpdate(a, (void*)func_08082224);
        return 1;
    case 6:
        p->unk_9C = 8;
        p->unk_A0 -= 4;
        func_08082EFC(p);
        p->unk_78 |= 0x200;
        p->unk_78 |= 0x80;
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_080827E0);
        return 1;
    case 8:
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = 16;
        p->unk_9E = 1;
        SetTaskUpdate(a, (void*)func_08082B48);
        return 1;
    case 7:
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        return 0;
    case 10:
        p->unk_9C = 10;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)func_08082F50);
        return 1;
    case 9:
    default:
        func_080837FC(p);
        break;
    }

    return 1;
}

void func_08082DA4(UnkStruct_02034AAC* p, CardDef** out) {
    u32* q;

    if (p->unk_04 != 0) {
        if (*(u32*)p->unk_04 != 0xFFFF) {
            if (*(u32*)p->unk_04 != 0xFFFE) {
                *out = &gCardDefs[*(u32*)p->unk_04 & CARD_ID_MASK];
            } else {
                *out = 0;
            }
        } else {
            *out = 0;
        }
    } else {
        q = &gUnk_02039DD4->unk_0B8;
        *out = &gCardDefs[*q & CARD_ID_MASK];
        *q = 0x3B6;
    }
}

u8 func_08082E0C(UnkStruct_02034AAC* p, void* a) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->unk_4C -= 0x200;
    p->unk_5E += 16;

    if (!(p->unk_78 & 0x400000)) {
        p->unk_54 -= 10;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = -10;
        }

        if (p->unk_54 <= -0x100) {
            p->unk_54 = -0x100;
            p->unk_78 |= 0x400000;
        }
    } else {
        p->unk_54 -= 10;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = 10;
        }

        if (p->unk_54 >= 0x100) {
            p->unk_54 = 0x100;
            p->unk_78 &= ~0x400000;
        }
    }

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->unk_068 &= ~0x10000000;
        return 0;
    }

    return 1;
}
void func_08082EFC(UnkStruct_02034AAC* p) {
    void* tiles;
    void* pal;

    func_0807C39C(p);
    tiles = p->unk_48->unk_14;
    pal = p->unk_48->unk_18;
    p->unk_00 = LoadObjTiles(tiles, 256);
    p->palette = LoadObjPalette(pal, 32);
}

void func_08082F24(UnkStruct_02034AAC* p) {
    if (p->unk_00 != 0) {
        ReleaseObjTiles(p->unk_00);
    }

    if (p->palette != 0) {
        ReleaseObjPalette(p->palette);
    }

    p->unk_00 = 0;
    p->palette = 0;
    func_0807C33C(p);
}

u8 func_08082F50(UnkStruct_02034AAC* p) {
    u8 arg;

    p->unk_A1 = 0;
    ApproachValue(&p->unk_4C, 0xD800, p->unk_9C);
    ApproachValue(&p->unk_58, 0x99, p->unk_9C);
    ApproachValue(&p->unk_50, 0x6400, p->unk_9C);
    ApproachValue(&p->unk_54, 0x99, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        return 1;
    }

    arg = 2;
    gUnk_02039B9C->unk_0F8 = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E;
    TaskCreate(&gUnk_02039DD4->unk_09C, gTaskDescHCEffectName, &arg);
    return 0;
}

u8 func_08082FF0(u8* work) {
    s32 r;

    if (*(s32*)&work[0x54] <= 24) {
        (*(u8**)&work[0x3C])[7] = r = 0;
        return r;
    }

    *(s32*)&work[0x54] -= 12;
    *(s32*)&work[0x58] += 12;

    if (*(s32*)&work[0x58] > 0x1FF) {
        *(s32*)&work[0x58] = 0x200;
    }

    return 1;
}
void Reload_Card_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    vu32 zero;
    vu32 zero2;

    zero = 0;
    CpuSet((void*)&zero, p, 0x0500002A);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(void**)p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(void**)p->unk_1C = 0;
    p->unk_20 = EwramAlloc(0x68);
    zero2 = 0;
    CpuSet((void*)&zero2, p->unk_20, 0x0500001A);
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    ((u8*)p->unk_20)[0x65] = 0;
    p->unk_78 = 0x01100024;
    p->unk_48 = 0;
    p->unk_54 = 0;
    p->unk_58 = 0x100;
    p->unk_5F = 0;
    p->unk_5E = 0;
    p->unk_9F = 0;
    p->unk_7C = 0;
    p->unk_80 = 0;
    p->unk_94 = 0;
    p->unk_98 = 0;
    p->unk_A1 = 0;
    p->unk_A0 = 80;
    p->unk_9C = 4;
    p->unk_A2 = 0;
    p->unk_84 = 0x2400;
    p->unk_88 = 0x2400;
    p->unk_A3 = 0;
    p->unk_8C = gUnk_0903401C[5][0];
    p->unk_90 = gUnk_0903401C[5][1];
    p->unk_4C = gUnk_0903401C[4][0];
    p->unk_50 = gUnk_0903401C[4][1];
    p->unk_78 &= ~0x40;
    gUnk_02039DD4->unk_0E8 = 0;
    func_08083714((UnkStruct_08083B20*)p);
    p->unk_78 |= 0x80;
}
u8 Reload_Card_1(UnkStruct_02034AAC* p, void* a) {
    if (p->unk_78 & 0x10) {
        p->unk_9C = 4;
        SetTaskUpdate(a, (void*)func_080829D0);
        return 1;
    }

    func_08083340(p);

    if (p->unk_78 & 4) {
        if ((s16)p->unk_9C > 0) {
            p->unk_78 &= ~0x40;
            ApproachValue(&p->unk_54, 0x100, p->unk_9C);
            gUnk_02039DD4->unk_0E8 = 0;
            p->unk_9C--;
        } else {
            p->unk_78 |= 0x40;
        }
    } else {
        if ((s16)p->unk_9C <= 0) {
            return 0;
        }

        p->unk_78 &= ~0x40;
        ApproachValue(&p->unk_54, 0, p->unk_9C);
        gUnk_02039DD4->unk_0E8 = 0;
        p->unk_9C--;
    }

    if (p->unk_78 & 0x1000) {
        return 1;
    }

    ApproachValue(&p->unk_4C, p->unk_8C, p->unk_9C);
    ApproachValue(&p->unk_50, p->unk_90, p->unk_9C);
    p->unk_5F += 4;

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08082A64);
    }

    return func_08082C98(p, a);
}
void Reload_Card_3(UnkStruct_02034AAC* p) {
    func_0807C39C(p);

    if (p->unk_20 != 0) {
        EwramFree(p->unk_20);
    }

    if (gUnk_02039B9C->unk_068 & 0x1000000) {
        gUnk_02039B9C->unk_068 &= ~0x1000000;
    }
}
void func_08083278(u8* p) {
    if (gUnk_02039DD4->unk_106 <= 7) {
        gUnk_02039DD4->unk_106++;
    }

    AnimStart(&p[0x40], (u16)gUnk_02039DD4->unk_106, 5);
}
void func_080832B0(u8* p) {
    gUnk_02039DD4->unk_106 = 2;
    AnimStart(&p[0x40], 2, 5);
}
void func_080832D0(u8* p) {
    *(void**)&p[0x58] = gUnk_09EEAF4C[3];
    *(void**)&p[0x5C] = gUnk_09EEAF4C[gUnk_02039DD4->unk_102 + 2];
}
void func_080832F8(u8* p) {
    *(void**)&p[0x58] = AnimUpdate(&p[0x28]);
    *(void**)&p[0x5C] = AnimUpdate(&p[0x40]);
}
void func_08083314(u8* p, u16 a) {
    void* gfx;

    if (a <= 18) {
        AnimStart(&p[0x10], a, 0);
        gfx = AnimGetGfx(&p[0x10]);
    } else {
        gfx = 0;
    }

    *(void**)&p[0x60] = gfx;
}
INCLUDE_ASM("card/func_08083340.s");
void Reload_Card_2(UnkStruct_02034AAC* p) {
    s32 affine;
    s32 affine2;
    u8* w;
    s16 y;
    u16 attr;

    attr = 0x410;
    affine = AllocObjAffine(0, p->unk_54, 0x100, 0);

    if (p->unk_78 & 0x80) {
        w = p->unk_20;

        if (func_080A42C8() == 1) {
            y = p->unk_50 >> 8;
        } else {
            y = (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8);
        }

        if (p->unk_54 > 0) {
            DrawSprite(p->unk_4C >> 8, y, gUnk_08F709B0[3].unk_04, p->unk_04,
                       gUnk_02039DD4->palette, affine, attr, p->unk_A0);

            if (*(void**)&w[0x60] != 0) {
                DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x60], p->unk_00,
                           gUnk_02039DD4->palette, affine, attr,
                           (u16)(p->unk_A0 - 2));
            }

            if ((s32)gUnk_02039DD4->unk_0F8 > 0) {
                affine2 = AllocObjAffine(0, p->unk_54, gUnk_02039DD4->unk_0F8, 0);

                if (*(void**)&w[0x58] != 0) {
                    DrawSprite(p->unk_4C >> 8, y + 17, *(void**)&w[0x58],
                               p->unk_08, gUnk_02039DD4->palette, affine2, 0x400,
                               (u16)(p->unk_A0 - 1));
                }

                if (gUnk_02039DD4->unk_108[1] == 1 && *(void**)&w[0x5C] != 0) {
                    DrawSprite(p->unk_4C >> 8, y, *(void**)&w[0x5C], p->unk_0C,
                               gUnk_02039DD4->palette, affine, 0x400,
                               (u16)(p->unk_A0 - 1));
                }
            }
        }
    }
}

void func_080836C4(UnkStruct_08095A5C* p, void* a, u8 b, s8 c) {
    AnimInit(&p->unk_10, gUnk_09EEA4E0, gUnk_09EEA494);

    if (c >= 0) {
        AnimStart(&p->unk_10, c, 0);
    } else {
        AnimStart(&p->unk_10, 0, 0);
    }

    p->unk_60 = AnimGetGfx(&p->unk_10);
}

void func_08083714(UnkStruct_08083B20* w) {
    UnkStruct_08095A5C* q;

    q = w->unk_20;
    w->unk_00 = AllocObjTiles(128, 0);
    func_08002A10(w->unk_00, gUnk_0909A4E0);
    func_080836C4(w->unk_20, w->unk_00, w->unk_46, gUnk_02039DD4->unk_0FE);
    w->unk_14 = 0;
    w->unk_04 = LoadObjTiles(gUnk_0909FDCA, 0x280);
    w->unk_18 = 0;
    w->unk_08 = AllocObjTiles(0x200, 0);
    func_08002A10(w->unk_08, gUnk_090A0C86);
    w->unk_0C = AllocObjTiles(128, 0);
    func_08002A10(w->unk_0C, gUnk_090A0C86);
    AnimInit(q->unk_28, gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(q->unk_28, 1, 1);
    q->unk_58 = gUnk_09EEAF4C[3];
    AnimInit(q->unk_40, gUnk_09EEAFB0, gUnk_09EEAF4C);
    AnimStart(q->unk_40, gUnk_02039DD4->unk_106, 1);
    q->unk_5C = gUnk_09EEAF4C[gUnk_02039DD4->unk_102 + 2];
}

void func_080837FC(UnkStruct_02034AAC* p) {
    if (gUnk_02039B9C->unk_0F4 == 16) {
        if (p->unk_78 & 4) {
            p->unk_A7 = 1;
            p->unk_A5 = GetRandom() % 10;
        } else {
            p->unk_A7 = 0;
            p->unk_A5 = p->unk_48->unk_20;
        }
    } else if (gUnk_02039B9C->unk_0F4 == 31) {
        p->unk_A7 = 1;
        p->unk_A5 = 10 - p->unk_48->unk_20;

        if (p->unk_A5 == 10) {
            p->unk_A5 = 0;
        }
    } else if (gUnk_02039B9C->unk_0F4 == 17) {
        p->unk_A7 = 1;
        p->unk_A5 = 0;
    } else {
        p->unk_A5 = p->unk_48->unk_20;
        p->unk_A7 = 0;
    }
}

void func_080838A0(void) {
    BtlWork* p;

    p = gUnk_02039B9C;

    switch (p->unk_0F4) {
    case 15:
    case 28:
    case 47:
        p->unk_0F8--;
        break;
    }
}
void func_080838CC(void) {
    if (gUnk_02039B9C->unk_0F4 == 2) {
        gUnk_02039B9C->unk_0F8--;
    }
}

void func_080838E8(void) {
}

void func_080838EC(void) {
    gUnk_02039DDC = 7;
}

void func_080838F8(void) {
}

void func_080838FC(void) {
}

void func_08083900(u8 a) {
    gUnk_02039DDC = 1;
    gUnk_02039DD8 = a;
}

void func_08083914(void) {
    gUnk_02039DDC = 2;
}

u8 func_08083920(void) {
    return func_08091B44();
}

void Bosscard_0(UnkStruct_08083930* w, u32* a) {
    u8 m;

    w->unk_24 = a[0];
    gUnk_02039DDC = 2;
    gUnk_02039DD8 = GetRandom() % 9;
    w->unk_28 = 0x100;
    w->unk_2A = 0x84;
    w->unk_2C = 0x100;
    w->unk_2F = 1;
    w->unk_30 = 1;
    w->unk_2E = 0;
    w->unk_31 = 8;
    w->unk_32 = 1;
    w->unk_33 = 0;
    w->unk_34 = GetRandom() % 100;
    w->unk_08 = gUnk_09EE275C[w->unk_24];
    w->unk_00 = &gCardDefs[w->unk_08[0]];
    w->unk_04 = &gUnk_08F70A28[w->unk_00->unk_1C >> 12];
    m = gUnk_08F7DAC4[w->unk_24];
    gUnk_02039DD4->unk_0D7 = GetRandom() % m;
}

u8 Bosscard_1(u8* work, void* a) {
    s32 v;
    u8 z;
    s32 c;

    work[0x2E] += 4;

    if (gUnk_02039DD4->unk_0E0 == 1) {
        z = 0;
        c = 0x100;
        *(u16*)&work[0x28] = c;
        work[0x31] = 8;
        gUnk_02039DD4->unk_0E0 = z;
    }

    if (work[0x31] != 0) {
        v = *(s16*)&work[0x28] << 8;
        ApproachValue(&v, 0xDC00, work[0x31]);
        *(s16*)&work[0x28] = v >> 8;
        work[0x31]--;
    }

    if (gUnk_02039DDC == 7) {
        work[0x31] = 8;
        SetTaskUpdate(a, (void*)func_08083ADC);
    }

    if (gUnk_02039DDC == 1) {
        if (func_08083B20((UnkStruct_08083B20*)work, 1) != 0) {
            gUnk_02039DDC = 0;
        }
    }

    if (gUnk_02039DDC == 2) {
        if (work[0x33] == work[0x34]) {
            if (func_08083B20((UnkStruct_08083B20*)work, 0) != 0) {
                work[0x33] = 0;
                work[0x34] = GetRandom() % 100;
            }
        } else {
            work[0x33]++;
        }
    }

    return 1;
}

s32 func_08083ADC(u8* work) {
    s32 v;

    if (work[0x31] != 0) {
        v = *(s16*)&work[0x28] << 8;
        ApproachValue(&v, 0x10000, work[0x31]);
        *(s16*)&work[0x28] = v >> 8;
        work[0x31]--;
    }

    return 1;
}
void Bosscard_2(void) {
}
void Bosscard_3(void) {
}

u8 func_08083B20(UnkStruct_08083B20* w, u8 b) {
    if (w->unk_32 == 1) {
        w->unk_2C -= 51;

        if (w->unk_2C <= 2) {
            w->unk_2C = 2;
            w->unk_32 = 0;

            if (b == 0) {
                gUnk_02039DD8 = GetRandom() % 9 + 1;
            }

            func_08091B38(gUnk_02039DD8);
        }
    } else {
        w->unk_2C += 51;

        if (w->unk_2C > 255) {
            w->unk_2C = 256;
            w->unk_32 = 1;
            return 1;
        }
    }

    return 0;
}

void map_anim_0(UnkStruct_08083B94* p) {
    u8 i;

    p->unk_14 = gUnk_09EE4A2C[*(s32*)&gUnk_02039DC8[0x44]];

    if (p->unk_14 != 0) {
        for (i = 0; i < p->unk_14->unk_04; i++) {
            p->unk_01[i] = 0;
            p->unk_09[i] = 0;
        }
    }

    p->unk_00 = 0;
}

u8 map_anim_1(UnkStruct_08083B94* w) {
    UnkStruct_08083BE4_Anim* a;
    UnkStruct_08083BE4_Entry* e;
    UnkStruct_08083BE4_Frame* f;
    UnkStruct_08083BE4_Frame* f2;
    u8 i;
    u8* dst;

    a = w->unk_14;

    if (a == 0) {
        return 1;
    }

    for (i = w->unk_00; i < (a = w->unk_14)->unk_04; i++) {
        e = &a->unk_00[i];
        f = &e->unk_00[w->unk_09[i]];
        w->unk_01[i]++;

        if (w->unk_01[i] == f->unk_02) {
            w->unk_09[i]++;

            if (w->unk_09[i] == e->unk_08) {
                w->unk_09[i] = 0;
            }

            f2 = &e->unk_00[w->unk_09[i]];
            dst = (u8*)GetBgCharBase(3) + 0x7000;
            RequestDma3Copy(e->unk_04 + f2->unk_00, dst + e->unk_0A, e->unk_0C);
            w->unk_01[i] = 0;
        }
    }

    return 1;
}

void map_anim_2(void) {
}
void map_anim_3(void) {
}

Deck* func_08083C94(void) {
    Deck* active;
    void** p;
    s32 i;

    active = GetActiveDeck();
    p = &gUnk_0203A854;
    *p = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        ((Deck*)gUnk_0203A854)->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 99; i++) {
        if (active->cards[i] != 0xFFFF) {
            ((Deck*)gUnk_0203A854)->cards[i] = gCardCollection[active->cards[i]];
        } else {
            ((Deck*)gUnk_0203A854)->cards[i] |= 0xFFFF;
        }
    }

    for (i = 0; i < 20; i++) {
        ((Deck*)gUnk_0203A854)->unk_C6[i] = gDecks[GetActiveDeckIndex()].unk_C6[i];
    }

    ((Deck*)gUnk_0203A854)->unk_DA = func_08085770(GetActiveDeckIndex());
    ((Deck*)gUnk_0203A854)->unk_DC = func_08085B38(GetActiveDeckIndex());
    return gUnk_0203A854;
}

void func_08083D68(void) {
    EwramFree(gUnk_0203A854);
}

Deck* func_08083D7C(void) {
    s32 i;

    gUnk_0203A850 = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        gUnk_0203A850->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 20; i++) {
        gUnk_0203A850->unk_C6[i] = 0;
    }

    gUnk_0203A850->unk_DA = 0;
    gUnk_0203A850->unk_DC = 0;
    return gUnk_0203A850;
}

void func_08083DD4(void) {
    EwramFree(gUnk_0203A850);
}

u16 func_08083DE8(void) {
    return gUnk_0203A850->unk_DC;
}

u16 func_08083DF8(u8 slot) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

u16 func_08083E54(u8 mode) {
    u8 slot;
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    switch (mode) {
    case 0:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                slot = gCardDefs[cards[i] & CARD_ID_MASK].unk_2A;

                if (slot <= 2) {
                    count++;
                }
            }
        }
        break;
    case 3:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A == 3) {
                    count++;
                }
            }
        }
        break;
    }

    return count;
}

Deck* sub_08083EFC(void) {
    return gUnk_0203A850;
}

void func_08083F08(u8 kind, u16* out) {
    Deck* deck;
    u16 i;

    deck = sub_08083EFC();

    for (i = 0; i < 99; i++) {
        if (deck->cards[i] != 0xFFFF) {
            switch (kind) {
            case 0:
                if (gCardDefs[deck->cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                    *out++ = deck->cards[i];
                }
                break;
            case 3:
                if (gCardDefs[deck->cards[i] & CARD_ID_MASK].unk_2A == 3) {
                    *out++ = deck->cards[i];
                }
                break;
            }
        }
    }
}

void func_08083F84(u16 a) {
    s16 v;

    v = func_08084458(a);

    if (gCardDefs[a].unk_20 + func_08085770(GetActiveDeckIndex()) <=
            gGameState.cp &&
        v != -1) {
        func_08085290(v);
    }
}

void func_08083FE0(void) {
    u16 i;

    for (i = 0; i < 999; i++) {
        gCardCollection[i] = CARD_ID_MASK;
    }

    gCardCount = 911;
}

u16 CountCardsById(u16 cardId) {
    u16 i;
    u16 count;

    i = 0;
    count = 0;

    for (; i < gCardCount; i++) {
        if ((gCardCollection[i] & CARD_ID_MASK) == cardId) {
            count++;
        }
    }
    
    return count;
}

s16 func_08084068(u16 cardId) {
    u16 i;

    i = 0;

    if (CountCardsById(cardId) > 98) {
        return -1;
    }

    while (gCardCollection[i] != CARD_ID_MASK) {
        i++;

        if (i == gCardCount) {
            return -1;
        }
    }

    if (gCardDefs[cardId & CARD_ID_MASK].unk_1E & 8) {
        return -1;
    }

    gCardCollection[i] = cardId;

    return i;
}

s32 func_080840E4(void) {
    s32 count;
    s32 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            count++;
        }
    }

    if (count > 0) {
        return 0;
    }

    return 1;
}

void func_08084124(u16 cardId) {
    u16 v;
    u8 n;

    v = gCardDefs[cardId & CARD_ID_MASK].unk_1C;

    if (v > 0x61) {
        if (gCardCount > 999) {
            gCardCount = 999;
        }
        return;
    }

    switch (v) {
    case 0:
        n = 119;
        break;
    case 8:
        n = 127;
        break;
    case 1:
        n = 120;
        break;
    case 2:
        n = 121;
        break;
    case 3:
        n = 122;
        break;
    case 4:
        n = 123;
        break;
    case 5:
        n = 124;
        break;
    case 6:
        n = 125;
        break;
    case 7:
        n = 126;
        break;
    case 9:
        n = 128;
        break;
    case 10:
        n = 129;
        break;
    case 11:
        n = 130;
        break;
    case 12:
        n = 131;
        break;
    case 13:
        n = 132;
        break;
    case 16:
        n = 133;
        break;
    case 14:
        n = 134;
        break;
    case 15:
        n = 135;
        break;
    case 18:
        n = 136;
        break;
    case 19:
        n = 137;
        break;
    case 20:
        n = 138;
        break;
    case 21:
        n = 139;
        break;
    case 22:
        n = 140;
        break;
    case 23:
        n = 141;
        break;
    case 24:
        n = 142;
        break;
    case 25:
        n = 143;
        break;
    case 26:
        n = 144;
        break;
    case 27:
        n = 145;
        break;
    case 28:
        n = 146;
        break;
    case 29:
        n = 147;
        break;
    case 30:
        n = 148;
        break;
    case 31:
        n = 149;
        break;
    case 32:
        n = 150;
        break;
    case 33:
        n = 151;
        break;
    case 34:
        n = 152;
        break;
    case 35:
        n = 153;
        break;
    case 36:
        n = 154;
        break;
    case 37:
        n = 155;
        break;
    case 38:
        n = 156;
        break;
    case 47:
        n = 164;
        break;
    case 50:
        n = 165;
        break;
    case 51:
        n = 166;
        break;
    case 52:
        n = 167;
        break;
    case 53:
        n = 168;
        break;
    case 61:
        n = 169;
        break;
    case 73:
        n = 170;
        break;
    case 74:
        n = 171;
        break;
    case 48:
        n = 172;
        break;
    case 54:
        n = 173;
        break;
    case 55:
        n = 174;
        break;
    case 56:
        n = 175;
        break;
    case 57:
        n = 176;
        break;
    case 59:
        n = 177;
        break;
    case 60:
        n = 178;
        break;
    case 62:
        n = 179;
        break;
    case 64:
        n = 180;
        break;
    case 65:
        n = 181;
        break;
    case 66:
        n = 182;
        break;
    case 67:
        n = 183;
        break;
    case 68:
        n = 184;
        break;
    case 70:
        n = 185;
        break;
    case 71:
        n = 186;
        break;
    case 72:
        n = 187;
        break;
    case 49:
        n = 188;
        break;
    case 58:
        n = 189;
        break;
    case 63:
        n = 190;
        break;
    case 69:
        n = 191;
        break;
    case 76:
        n = 192;
        break;
    case 77:
        n = 193;
        break;
    case 75:
        n = 194;
        break;
    case 81:
        n = 204;
        break;
    case 78:
        n = 195;
        break;
    case 86:
        n = 200;
        break;
    case 80:
        n = 197;
        break;
    case 79:
        n = 201;
        break;
    case 85:
        n = 198;
        break;
    case 87:
        n = 199;
        break;
    case 89:
        n = 203;
        break;
    case 88:
        n = 202;
        break;
    case 84:
        n = 196;
        break;
    case 90:
        n = 247;
        break;
    case 91:
        n = 206;
        break;
    case 92:
        n = 205;
        break;
    case 93:
        n = 207;
        break;
    case 94:
        n = 208;
        break;
    case 82:
    case 83:
        n = 246;
        break;
    case 96:
        n = 248;
        break;
    case 97:
        n = 249;
        break;
    default:
        if (gCardCount > 999) {
            gCardCount = 999;
        }
        return;
    }

    if (func_0800FF00(n) == 0) {
        gCardCount++;
    }

    if (gCardCount > 999) {
        gCardCount = 999;
    }
}


INCLUDE_ASM("card/func_08084458.s");

void func_08084AC8(u16 a) {
    if (gGameState.flags & 8) {
        switch (a) {
        case 0x51:
            func_0800FC14(44);
            break;
        case 0x4E:
            func_0800FC14(38);
            break;
        case 0x56:
            func_0800FC14(45);
            break;
        case 0x50:
            func_0800FC14(40);
            break;
        case 0x4F:
            func_0800FC14(42);
            break;
        case 0x55:
            func_0800FC14(39);
            break;
        case 0x57:
            func_0800FC14(41);
            break;
        case 0x59:
            func_0800FC14(43);
            break;
        case 0x58:
            func_0800FC14(48);
            break;
        case 0x54:
            func_0800FC14(50);
            break;
        case 0x5A:
            func_0800FC14(51);
            break;
        case 0x5D:
            func_0800FC14(54);
            break;
        case 0x60:
            func_0800FC14(57);
            break;
        }
    }
}

u16 func_08084BAC(void) {
    u16 count;
    u16 i;

    count = i = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            count++;
        }
    }

    return count;
}

u16 func_08084BF0(void) {
    u16 count;
    u16 i;

    count = i = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK && (gCardCollection[i] & 0x7000)) {
            count++;
        }
    }

    return count;
}

u16 func_08084C40(u8 deck, u8 mode, u16* out) {
    u16 count;
    u16 total;
    u16 mask;
    u16* present;
    u16 i;
    u32 zero;

    mask = total = count = 0;
    present = EwramAlloc(0x23C);
    zero = 0;
    CpuSet(&zero, present, 0x0500008F);

    if (mode == 1) {
        switch (deck) {
        case 0:
            mask = 0x1000;
            break;
        case 1:
            mask = 0x2000;
            break;
        case 2:
            mask = 0x4000;
            break;
        }
    } else {
        mask = 0x7000;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }
        if (gCardCollection[i] & mask) {
            continue;
        }
        if (!(gCardCollection[i] & 0x8000)) {
            present[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C] = 1;
        } else {
            present[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C + 0x8F] = 1;
        }
    }

    for (i = 0; i < 0x11E; i++) {
        if (present[i] != 0) {
            total += present[i];
            out[count++] = i;
        }
    }

    EwramFree(present);
    return total;
}

void func_08084D78(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p) {
    u16 mask;
    u16 i;
    s32 x;

    mask = 0;

    if (mode == 1) {
        switch (deck) {
        case 0:
            mask = 0x1000;
            break;
        case 1:
            mask = 0x2000;
            break;
        case 2:
            mask = 0x4000;
            break;
        }
    } else {
        mask = 0x7000;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }

        if (gCardCollection[i] & mask) {
            continue;
        }

        if (!(gCardCollection[i] & 0x8000)) {
            x = gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C;
            out[x].unk_14 = x;
            out[x].unk_16++;
        } else {
            x = gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C;
            out[x + 0x8F].unk_14 = x + 0x8F;
            out[x + 0x8F].unk_16++;
        }
    }
}

u16 func_08084E50(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p) {
    u16 mask;
    u16 i;
    u16 count;
    u32 id;
    u16 x;

    mask = 0;

    if (mode == 1) {
        switch (deck) {
        case 0:
            mask = 0x1000;
            break;
        case 1:
            mask = 0x2000;
            break;
        case 2:
            mask = 0x4000;
            break;
        }
    } else {
        mask = 0x7000;
    }

    for (i = 0, count = 0; i < n; i++) {
        if (out[i].unk_16 != 0) {
            out[i].unk_1C = EwramAlloc(out[i].unk_16 * 2);
            count++;
        } else {
            out[i].unk_1C = 0;
        }

        out[i].unk_18 = 0;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }

        if (gCardCollection[i] & mask) {
            continue;
        }

        if (!(gCardCollection[i] & 0x8000)) {
            id = gCardCollection[i] & CARD_ID_MASK;
            x = gCardDefs[id].unk_1C;

            if (id > 0x1C1) {
                out[x].unk_00[0]++;
            } else {
                out[x].unk_00[gCardDefs[id].unk_20]++;
            }

            out[x].unk_1C[out[x].unk_18++] = i;
        } else {
            id = gCardCollection[i] & CARD_ID_MASK;
            x = gCardDefs[id].unk_1C + 0x8F;

            if (id > 0x1C1) {
                out[x].unk_00[0]++;
            } else {
                out[x].unk_00[gCardDefs[id].unk_20]++;
            }

            out[x].unk_1C[out[x].unk_18++] = i;
        }
    }

    return count;
}
void func_08084FA8(void) {
}

u16 func_08084FAC(u8 slot) {
    u16 count;
    u16 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            if (gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

void func_0808500C(u8 mode, u16* out) {
    u16 mask;
    u16 i;

    mask = 0;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;

    switch (mode) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    case 3:
        mask = 0x7000;
        break;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            if (!(gCardCollection[i] & mask)) {
                out[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_2A]++;
            }
        }
    }
}

void func_080850B0(u16* p) {
    *p = CARD_ID_MASK;
}
void func_080850BC(u16 id) {
    s32 i;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK &&
            (gCardCollection[i] & 0x7000) == 0 &&
            (gCardCollection[i] & CARD_ID_MASK) == id) {
            gCardCollection[i] = CARD_ID_MASK;
            return;
        }
    }
}

u8 func_0808510C(u16 id) {
    s32 i;

    if (gGameState.flags & 8) {
        return 0;
    }

    for (i = 0; i < gCardCount; i++) {
        if ((gCardCollection[i] & CARD_ID_MASK) == id) {
            return 1;
        }
    }

    return 0;
}

void func_08085160(void) {
    u16 i;
    u16 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 99; j++) {
            gDecks[i].cards[j] |= 0xFFFF;
        }

        for (j = 0; j < 20; j++) {
            gDecks[i].unk_C6[j] = 0;
        }

        gDecks[i].unk_DA = 0;
        gDecks[i].unk_DC = 0;
    }
}

void func_080851E4(u8 deck) {
    u16 mask;
    u16 i;

    mask = 0;

    switch (deck) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    }

    for (i = 0; i < 99; i++) {
        if (gDecks[deck].cards[i] != 0xFFFF) {
            gCardCollection[gDecks[deck].cards[i]] &= ~mask;
            gDecks[deck].cards[i] |= 0xFFFF;
        }
    }

    gDecks[deck].unk_DA = 0;
    gDecks[deck].unk_DC = 0;
}

u8 func_08085290(u16 card) {
    u16* cards;
    u16 i;
    u16 v;

    i = 0;
    cards = GetActiveDeck()->cards;

    while (cards[i] != 0xFFFF) {
        i++;

        if (i == 99) {
            return 0;
        }
    }

    cards[i] = card;

    switch (gActiveDeck) {
    case 0:
        gCardCollection[card] |= 0x1000;
        break;
    case 1:
        gCardCollection[card] |= 0x2000;
        break;
    case 2:
        gCardCollection[card] |= 0x4000;
        break;
    }

    v = func_080609AC(gCardCollection[card]);
    gDecks[gActiveDeck].unk_DA += v;
    gDecks[gActiveDeck].unk_DC++;
    return 1;
}

u8 func_08085374(u16 card, u8 deck) {
    u16* cards;
    u16 i;
    u16 v;

    cards = GetDeck(deck)->cards;

    for (i = 0; i < 99 && cards[i] != 0xFFFF; i++) {
    }

    if (i == 99) {
        return 0;
    }

    cards[i] = card;

    switch (deck) {
    case 0:
        gCardCollection[card] |= 0x1000;
        break;
    case 1:
        gCardCollection[card] |= 0x2000;
        break;
    case 2:
        gCardCollection[card] |= 0x4000;
        break;
    }

    v = func_080609AC(gCardCollection[card]);
    gDecks[deck].unk_DA += v;
    gDecks[deck].unk_DC++;
    return 1;
}

void func_08085448(u16 slot) {
    u16* cards;
    u16 v;

    cards = GetActiveDeck()->cards;

    if (cards[slot] != 0) {
        switch (gActiveDeck) {
        case 0:
            gCardCollection[cards[slot]] &= ~0x1000;
            break;
        case 1:
            gCardCollection[cards[slot]] &= ~0x2000;
            break;
        case 2:
            gCardCollection[cards[slot]] &= ~0x4000;
            break;
        }
    }

    v = func_080609AC(gCardCollection[cards[slot]]);
    gDecks[gActiveDeck].unk_DA -= v;
    gDecks[gActiveDeck].unk_DC--;
    cards[slot] = 0xFFFF;
}

void func_08085518(u16* p, u8 deck) {
    u16 v;

    switch (deck) {
    case 0:
        gCardCollection[*p] &= ~0x1000;
        break;
    case 1:
        gCardCollection[*p] &= ~0x2000;
        break;
    case 2:
        gCardCollection[*p] &= ~0x4000;
        break;
    }

    v = func_080609AC(gCardCollection[*p]);
    gDecks[deck].unk_DA -= v;
    gDecks[deck].unk_DC--;
    *p = 0xFFFF;
}

void func_080855C8(void) {
    u8 i;
    u16 total;
    s32 j;
    Deck* deck;

    for (i = 0; i < 3; i++) {
        if (i == gActiveDeck) {
            continue;
        }

        total = 0;
        deck = GetDeck(i);

        for (j = 0; j < 99; j++) {
            if (deck->cards[j] != 0xFFFF) {
                total += func_080609AC(gCardCollection[deck->cards[j]]);
            }
        }

        gDecks[i].unk_DA = total;
    }
}

void func_08085658(u16 index) {
    Deck* d;
    s32 v;

    d = GetActiveDeck();
    gDecks[gActiveDeck].unk_DA -= func_080609AC(gCardCollection[*(u16*)(index * 2 + (u32)d)]);
    gCardCollection[*(u16*)(index * 2 + (u32)d)] |= 0x8000;
    v = func_080609AC(gCardCollection[*(u16*)(index * 2 + (u32)d)]) + gDecks[gActiveDeck].unk_DA;
    gDecks[gActiveDeck].unk_DA = v;
    func_080855C8();
}

s32 func_080856DC(void) {
    Deck* deck;
    s32 count;
    s32 i;

    count = 0;
    deck = GetActiveDeck();

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (gCardCollection[deck->cards[i]] & 0x8000) {
                count++;
            }
        }
    }

    if (gDecks[gActiveDeck].unk_DC == count) {
        return 0;
    }

    return 1;
}

Deck* GetActiveDeck(void) {
    return &gDecks[gActiveDeck];
}

Deck* GetDeck(u8 index) {
    return &gDecks[index];
}

u16 func_08085770(u8 index) {
    return gDecks[index].unk_DA;
}

#ifdef NON_MATCHING
void func_08085788(u8 index, u16* src) {
    Deck* deck;
    u8* d;
    u8* s;

    if (*src == 0) {
        return;
    }

    deck = &gDecks[index];
    d = deck->unk_C6;
    s = (u8*)src;

    do {
        d[0] = s[0];
        d[1] = s[1];
        d += 2;
        s += 2;
    } while (*(u16*)s != 0);
}
#else
INCLUDE_ASM("card/func_08085788.s");
#endif

u8* func_080857BC(u8 index) {
    return gDecks[index].unk_C6;
}

u16 func_080857D4(u8 slot) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = GetActiveDeck()->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

u16 func_08085844(u8 slot, u8 deckIndex) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = GetDeck(deckIndex)->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

s16 func_080858B8(s32 index) {
    u16 count;
    s16 i;
    u16* cards;

    count = 0;
    cards = GetActiveDeck()->cards;

    switch (index) {
    case 0:
        for (i = 0; i <= 98; i++) {
            if (cards[i] != 0xFFFF) {
                if ((u8)gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A <= 2) {
                    count = ((count << 16) + 0x10000) >> 16;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i <= 98; i++) {
            if (cards[i] != 0xFFFF) {
                if ((u8)gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == 3) {
                    count = ((count << 16) + 0x10000) >> 16;
                }
            }
        }
        break;
    }

    return count;
}

s16 func_080859A0(s32 mode, Deck* d) {
    s16 count;
    s16 i;

    count = 0;

    switch (mode) {
    case 0:
        for (i = 0; i < d->unk_DC; i++) {
            if (gCardDefs[d->cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                count++;
            }
        }
        break;
    case 1:
        for (i = 0; i < d->unk_DC; i++) {
            if (gCardDefs[d->cards[i] & CARD_ID_MASK].unk_2A == 3) {
                count++;
            }
        }
        break;
    }

    return count;
}

void func_08085A58(s32 a, u16* out) {
    u16* cards;
    u16 i;

    cards = GetActiveDeck()->cards;

    switch (a) {
    case 0:
        for (i = 0; i < 99; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[gCardCollection[cards[i]] & 0xFFF].unk_2A <= 2) {
                    *out++ = gCardCollection[cards[i]] & 0x8FFF;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < 99; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[gCardCollection[cards[i]] & 0xFFF].unk_2A == 3) {
                    *out++ = gCardCollection[cards[i]] & 0x8FFF;
                }
            }
        }
        break;
    }
}

u16 func_08085B38(u8 index) {
    return gDecks[index].unk_DC;
}

void SetActiveDeckIndex(u8 index) {
    gActiveDeck = index;
}

u16 func_08085B5C(u16 index) {
    return gCardDefs[gCardCollection[index] & CARD_ID_MASK].unk_1C;
}

u8 func_08085B84(u16 index) {
    return gCardDefs[gCardCollection[index] & CARD_ID_MASK].unk_2A;
}

s32 func_08085BAC(void) {
    Deck* deck;
    s32 a;
    s32 b;
    s32 i;

    a = 0;
    b = 0;
    deck = GetActiveDeck();

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (func_08085B84(deck->cards[i]) != 2) {
                if (func_08085B84(deck->cards[i]) != 3) {
                    a++;
                }
            }
        }
    }

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (gCardCollection[deck->cards[i]] & 0x8000) {
                b++;
            }
        }
    }

    if (b == a) {
        return 1;
    }

    return 0;
}

void func_08085C3C(void) {
    gActiveDeck = 0;
    func_08083FE0();
    func_08085160();

    if (gUnk_03006C10 & 0x10) {
        func_080AB228();
        func_080AB22C(2);
        func_080AB334(1);
        func_080AB4AC(0);
    } else {
        func_080AB880();
        func_080AB8E4();
        func_080AB964();
        func_080AB968();
    }

#ifdef VERSION_EU
    func_08085788(0, gUnkEu_09F65FDC[gLanguage]);
    func_08085788(1, gUnkEu_09F65FF0[gLanguage]);
    func_08085788(2, gUnkEu_09F66004[gLanguage]);
#else
    func_08085788(0, gUnk_09EE4AC8);
    func_08085788(1, gUnk_09EE4AD6);
    func_08085788(2, gUnk_09EE4AE4);
#endif
}

void func_08085CB0(void) {
    gActiveDeck = 0;
    func_08083FE0();
    func_08085160();
    func_080AB228();
    func_080AB334(0);
    func_080AB22C(1);
    func_080AB4AC(2);
#ifdef VERSION_EU
    func_08085788(0, gUnkEu_09F65FDC[gLanguage]);
    func_08085788(1, gUnkEu_09F65FF0[gLanguage]);
    func_08085788(2, gUnkEu_09F66004[gLanguage]);
#else
    func_08085788(0, gUnk_09EE4AC8);
    func_08085788(1, gUnk_09EE4AD6);
    func_08085788(2, gUnk_09EE4AE4);
#endif
}

void _08085D04(u8 a) {
    u8 n = 0;

    func_08083FE0();
    func_08085160();
    SetActiveDeckIndex(0);

    switch (a) {
    case 2:
        n = 1;
        break;
    case 3:
        n = 2;
        break;
    case 4:
        n = 3;
        break;
    case 5:
        n = 4;
        break;
    case 6:
        n = 5;
        break;
    case 7:
        n = 6;
        break;
    case 8:
        n = 7;
        break;
    case 9:
        n = 8;
        break;
    case 10:
        n = 9;
        break;
    case 11:
        n = 10;
        break;
    case 0:
    case 12:
        n = 11;
        break;
    case 1:
    case 13:
        n = 0;
        break;
    }

    func_08085DA0(n);
}
void func_08085DA0(u8 a) {
    s32 i;
    s32 j;

    for (i = 0, j = 0; i < gUnk_090356BA[a]; i++, j++) {
        func_08084458(gUnk_09EE4A68[a][i]);
        func_08085290(i);
    }

    for (i = 0; i < gUnk_090356D2[a]; j++, i++) {
        func_08084458(gUnk_09EE4A98[a][i]);
        func_08085290(j);
    }

    gCardCollection[200] = 0x21D;
    gCardCollection[201] = 0x21E;
    gCardCollection[202] = 0x21F;
    gCardCollection[203] = 0x220;
    gCardCollection[204] = 0x227;
    gCardCollection[205] = 0x228;
    gCardCollection[206] = 0x229;
    gCardCollection[207] = 0x22A;
    gCardCollection[208] = 0x22B;
    gCardCollection[209] = 0x22C;
    gCardCollection[210] = 0x22D;
    gCardCollection[211] = 0x230;
    gCardCollection[212] = 0x233;
    gCardCollection[213] = 0x234;

    if (func_0800FC5C(38) != 0) {
        func_08085290(200);
    }

    if (func_0800FC5C(42) != 0) {
        func_08085290(201);
    }

    if (func_0800FC5C(40) != 0) {
        func_08085290(202);
    }

    if (func_0800FC5C(44) != 0) {
        func_08085290(203);
    }

    if (func_0800FC5C(50) != 0) {
        func_08085290(204);
    }

    if (func_0800FC5C(39) != 0) {
        func_08085290(205);
    }

    if (func_0800FC5C(45) != 0) {
        func_08085290(206);
    }

    if (func_0800FC5C(41) != 0) {
        func_08085290(207);
    }

    if (func_0800FC5C(48) != 0) {
        func_08085290(208);
    }

    if (func_0800FC5C(43) != 0) {
        func_08085290(209);
    }

    if (func_0800FC5C(51) != 0) {
        func_08085290(210);
    }

    if (func_0800FC5C(54) != 0) {
        func_08085290(211);
    }

    if (func_0800FC5C(57) != 0) {
        func_08085290(212);
    }

    if (func_0800FC5C(56) != 0) {
        func_08085290(213);
    }
}

u8 GetActiveDeckIndex(void) {
    return gActiveDeck;
}

void func_08085FB0(void) {
}
#ifdef NON_MATCHING
void func_08085FB4(u8* work, void* a) {
    *(void**)&work[0x8BC] = a;
    SetBgMode0();
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 3, 31, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(3, 0, 30, 0);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    func_08006120(0, 16);
    ListPoolInit(&work[0x7F0]);
    TaskPoolInit((TaskPool*)&work[0x7C8], 286);
    TaskPoolInit((TaskPool*)&work[0x7DC], 1);
    work[0x8C0] = GetActiveDeckIndex();
    func_0808C3DC(work, 0);
    *(void**)&work[0x00] = AllocObjTiles(0x120, 0);
    func_08002A10(*(void**)&work[0x00], gUnk_090A4664);
    AnimInit((AnimState*)&work[0x800], gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)&work[0x800], 0, 1);
    *(void**)&work[0x4F0] = AnimGetGfx((AnimState*)&work[0x800]);
    *(s32*)&work[0x848] = gUnk_090356EC[0] << 8;
    *(s32*)&work[0x84C] = gUnk_090356F2[0] << 8;
    *(u16*)&work[0x882] = 0;
    *(void**)&work[0x10] = LoadObjTiles(gUnk_090A44C4, 32);
    *(void**)&work[0x14] = LoadObjPalette(gUnk_09614418, 32);
    *(void**)&work[0x4B8] = LoadObjTiles(&gUnk_090A0C86[0x132C], 0x280);
    *(void**)&work[0x4E8] = *(void**)&gUnk_09EEAFB0[0x24];
    *(void**)&work[0x4EC] = *(void**)&gUnk_09EEAFB0[0x28];
    *(void**)&work[0x04] = AllocObjTiles(0x280, 0);
    func_0808E364(work, 0);
    *(void**)&work[0x4C4] = LoadObjPalette(gUnk_09614438, 32);
    gUnk_0203A860[0] = AllocObjTiles(0x100, 0);
    gUnk_0203A860[1] = LoadObjPalette(gUnk_09611AB8, 32);
    func_08002A10(gUnk_0203A860[0], gUnk_0908C3CE);
    AnimInit((AnimState*)&gUnk_0203A860[2], gUnk_09EEA198, gUnk_09EEA180);
    AnimStart((AnimState*)&gUnk_0203A860[2], 0, 1);
    gUnk_0203A860[8] = AnimUpdate((AnimState*)&gUnk_0203A860[2]);
    *(s32*)&work[0x28] = 0;
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0x20] = 0;
    *(s32*)&work[0x24] = 0;
    *(s32*)&work[0x30] = 0;
    *(s32*)&work[0x34] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x4BC] = 0;
    *(s32*)&work[0x4C0] = 0;
    *(u16*)&work[0x884] = 0;
    *(u16*)&work[0x886] = 0;
    work[0x8B3] = 0;
    work[0x8B4] = 0;
    work[0x8B7] = 16;
    work[0x8C8] = 0;
    *(s32*)&work[0x4C8] = 0;
    *(s32*)&work[0x4CC] = 0;
    work[0x8C7] = 0;
    work[0x8B1] = 0;
    *(u16*)&work[0x8A2] = func_080857D4(0);
    *(u16*)&work[0x8A4] = func_080857D4(1);
    *(u16*)&work[0x8A6] = func_080857D4(2);
    *(u16*)&work[0x8A8] = func_080857D4(3);
    work[0x8C1] = 0;
    *(u16*)&work[0x898] = 0;
    *(s32*)&work[0x4D4] = 0;
    work[0x8C9] = 0;
    work[0x8CB] = 0;
    work[0x8CC] = 16;
    work[0x8CD] = 16;
    *(s32*)&work[0x858] = 0x7800;
    *(s32*)&work[0x860] = -0x800;
    *(s32*)&work[0x85C] = 0xA400;
    *(s32*)&work[0x864] = 0xA000;
    *(s32*)&work[0x868] = -0x8000;
    work[0x8CF] = 0;
    work[0x8B0] = 0;
    *(u16*)&work[0x878] = 95;
    *(u16*)&work[0x87A] = 0xFFFE;
    *(u16*)&work[0x87C] = 135;
    *(u16*)&work[0x87E] = 0xFFFE;
    work[0x8CE] = 0;
    work[0x8C2] = 0;
    work[0x8C3] = 0;
    work[0x8C4] = 0;
    work[0x8C5] = 0;
    func_08065ACC((TextSlot*)&work[0x38], 8);
    func_08065ACC((TextSlot*)&work[0x78], 8);
    func_08065ACC((TextSlot*)&work[0xB8], 8);
    func_08065ACC((TextSlot*)&work[0xF8], 30);
    func_08065ACC((TextSlot*)&work[0x1E8], 90);
    work[0x8D0] = 0;
    work[0x8D2] = 0;
}
#else
INCLUDE_ASM("card/func_08085FB4.s");
#endif
u8 func_080863C0(u8* work, void* a) {
#ifdef VERSION_EU
    func_08006120(0, 16);

    if (work[0x8D4] == 0) {
        func_0800443C(GetBgCharBase(0), 0x2000);
    }

    if (work[0x8D4] == 1) {
        func_0800443C(GetBgCharBase(0) + 0x2000, 0x2000);
    }

    if (work[0x8D4] == 2) {
        func_0800443C(GetBgCharBase(1), 0x2000);
    }

    if (work[0x8D4] == 3) {
        func_0800443C(GetBgCharBase(1) + 0x2000, 0x2000);
    }

    if (work[0x8D4] == 4) {
        func_0800443C(GetBgCharBase(2), 0x2000);
    }

    if (work[0x8D4] == 5) {
        func_0800443C(GetBgCharBase(2) + 0x2000, 0x2000);
    }

    if (work[0x8D4] == 6) {
        func_0800443C(GetBgCharBase(3), 0x2000);
    }

    if (work[0x8D4] == 7) {
        func_0800443C(GetBgCharBase(3) + 0x2000, 0x2000);
    }

    work[0x8D4]++;

    if (work[0x8D4] == 8) {
        work[0x8D4] = 0;
        SetTaskUpdate(a, (void*)func_080864A4);
    }

    return 1;
#else
    func_08006120(0, 16);

    if (work[0x8D0] == 0) {
        func_0800443C(GetBgCharBase(0), 0x2000);
    }

    if (work[0x8D0] == 1) {
        func_0800443C(GetBgCharBase(0) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 2) {
        func_0800443C(GetBgCharBase(1), 0x2000);
    }

    if (work[0x8D0] == 3) {
        func_0800443C(GetBgCharBase(1) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 4) {
        func_0800443C(GetBgCharBase(2), 0x2000);
    }

    if (work[0x8D0] == 5) {
        func_0800443C(GetBgCharBase(2) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 6) {
        func_0800443C(GetBgCharBase(3), 0x2000);
    }

    if (work[0x8D0] == 7) {
        func_0800443C(GetBgCharBase(3) + 0x2000, 0x2000);
    }

    work[0x8D0]++;

    if (work[0x8D0] == 8) {
        work[0x8D0] = 0;
        SetTaskUpdate(a, (void*)func_080864A4);
    }

    return 1;
#endif
}
u8 func_08086650(u8* work, void* a);

#ifndef VERSION_EU
u8 func_080864A4(u8* work, void* a) {
    func_08006120(0, 16);

    switch (work[0x8D0]) {
    case 0:
        LoadBgTiles(3, gUnk_09402F78, 0x2000);
        LoadBgPalette(3, gUnk_09614118, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(&gUnk_09402F78[0x2000],
                        (u8*)GetBgCharBase(3) + 0x2000, 0x2000);
        break;
    case 2:
        LoadBgMap(3, gUnk_09516AB8, 0x800);
        break;
    case 3:
        LoadBgTiles(0, gUnk_09406F78, 0xC00);
        break;
    case 4:
        LoadBgMap(0, gUnk_08125E24, 0x800);
        break;
    case 5:
        LoadBgTiles(1, &gUnk_09406F78[0xC00], 0x2000);
        break;
    case 6:
        RequestDma3Copy(&gUnk_09406F78[0x2C00],
                        (u8*)GetBgCharBase(1) + 0x2000, 0x1E20);
        break;
    case 7:
        LoadBgMap(1, gUnk_08125E24, 0x800);
        break;
    case 8:
        LoadBgTiles(2, &gUnk_09406F78[0x4A20], 0x2000);
        break;
    case 9:
        RequestDma3Copy(&gUnk_09406F78[0x6A20],
                        (u8*)GetBgCharBase(2) + 0x2000, 0x1E20);
        break;
    case 10:
        LoadBgMap(2, gUnk_08125E24, 0x800);
        break;
    case 11:
        SetBgScroll(0, -88, -16);
        SetBgScroll(1, -88, -64);
        SetBgScroll(2, -88, -112);
        work[0x8D0] = 0;
        SetTaskUpdate(a, (void*)func_08086650);
        return 1;
    }

    work[0x8D0]++;
    return 1;
}
#else
INCLUDE_ASM("card/func_080864A4.s");
#endif
INCLUDE_ASM("card/func_08086650.s");
INCLUDE_ASM("card/func_08086860.s");
u8 func_0808686C(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate(&work[CARDWORK(0x800)]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[CARDWORK(0x818)]);

    if (!func_08006314()) {
        switch (work[CARDWORK(0x8D0)]) {
        case 0:
            ApproachValue(&work[CARDWORK(0x860)], 0, work[CARDWORK(0x8B7)]);
            ApproachValue(&work[CARDWORK(0x864)], 0x9800, work[CARDWORK(0x8B7)]);
            work[CARDWORK(0x8B7)]--;

            if (work[CARDWORK(0x8B7)] == 0) {
                work[CARDWORK(0x8B7)] = 16;
                work[CARDWORK(0x8D0)]++;
            }
            break;
        case 1:
            ApproachValue(&work[CARDWORK(0x868)], 0, work[CARDWORK(0x8B7)]);
            work[CARDWORK(0x8B7)]--;

            if (work[CARDWORK(0x8B7)] == 0) {
                ReleaseObjTiles(*(void**)&work[0x4BC]);
                ReleaseObjTiles(*(void**)&work[0x18]);
                ReleaseObjPalette(*(void**)&work[0x4C0]);
                *(void**)&work[0x4BC] = 0;
                *(void**)&work[0x18] = 0;
                *(void**)&work[0x4C0] = 0;
                work[CARDWORK(0x8B0)] = 1;
                LoadBgMap(3, gUnk_09512AB8, 0x800);
                SetTaskUpdate(a, (void*)func_080889DC);
            }
            break;
        }
    }

    return 1;
}
u8 func_08086984(u8* work, void* a) {
    func_0808D6C4(work);
#ifdef VERSION_EU
    func_0805F1C0(&work[0x84C], gUnk_09035950[*(s16*)&work[0x888]] << 8);
    func_0805F1C0(&work[0x850], gUnk_09035956[*(s16*)&work[0x88A]] << 8);
    work[0x8BB]--;

    if (work[0x8BB] == 0) {
        work[0x8B5] = 0;
        func_0808CD48(work);
        SetTaskUpdate(a, (void*)func_08086A14);
    }
#else
    func_0805F1C0(&work[0x848], gUnk_09035950[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_09035956[*(s16*)&work[0x886]] << 8);
    work[0x8B7]--;

    if (work[0x8B7] == 0) {
        work[0x8B1] = 0;
        func_0808CD48(work);
        SetTaskUpdate(a, (void*)func_08086A14);
    }
#endif

    return 1;
}
INCLUDE_ASM("card/func_08086A14.s");
INCLUDE_ASM("card/func_080870FC.s");
INCLUDE_ASM("card/func_08087438.s");
#ifdef NON_MATCHING
u8 func_0808778C(u8* work, void* a) {
    u8 n;

    if (work[0x8C9] != 0) {
        TaskPoolUpdate((TaskPool*)&work[0x7C8]);
        TaskPoolUpdate((TaskPool*)&work[0x7DC]);

        if (GetKeysPressed() & 8) {
            work[0x8D2] = 7;
            work[0x8CB] = 1;
        }

        work[0x8CE] = 8;
        return 1;
    }

    if (work[0x8CB] != 0) {
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (void*)func_0808B208);
            func_08006184(0, 4);
            m4aSongNumStart(103);
            return 1;
        }

        work[0x8CB] = 0;
    }

    *(void**)&work[0x4F0] = AnimUpdate((AnimState*)&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate((AnimState*)&work[0x818]);

    switch (GetKeysRepeat()) {
    case 32:
    case 96:
    case 160:
        if (*(s16*)&work[0x884] > 0) {
            (*(s16*)&work[0x884])--;
            work[0x8B7] = 1;

            if ((u8)func_0808DED0(work, 32) != 0) {
                m4aSongNumStart(101);
            }
        }

        func_0808DDD0(work);
        break;
    case 16:
    case 80:
    case 144:
        if (*(s16*)&work[0x884] <= 0) {
            (*(s16*)&work[0x884])++;
            work[0x8B7] = 1;

            if ((u8)func_0808DED0(work, 16) != 0) {
                m4aSongNumStart(101);
            }
        }

        func_0808DDD0(work);
        break;
    case 64:
        n = work[0x886];

        if (*(s16*)&work[0x886] > 0) {
            *(s16*)&work[0x886] = *(s16*)&work[0x886] - 1;
        } else {
            *(s16*)&work[0x886] = 4;
        }

        work[0x8B7] = 1;
        func_0808DED0(work, 64);

        if ((s8)n != *(s16*)&work[0x886]) {
            m4aSongNumStart(101);
        }

        func_0808DDD0(work);
        break;
    case 128:
        n = work[0x886];

        if (*(s16*)&work[0x886] <= 3) {
            *(s16*)&work[0x886] = *(s16*)&work[0x886] + 1;
        } else {
            *(s16*)&work[0x886] = 0;
        }

        work[0x8B7] = 1;
        func_0808DED0(work, 128);

        if ((s8)n != *(s16*)&work[0x886]) {
            m4aSongNumStart(101);
        }

        func_0808DDD0(work);
        break;
    }

    switch (GetKeysPressed()) {
    case 2:
        func_0808E364(work, 0);
        n = work[0x8B5];
        *(s16*)&work[0x884] = (s8)n;
        n = work[0x8B6];
        *(s16*)&work[0x886] = (s8)n;
        *(s32*)&work[0x848] = gUnk_0903595E[*(s16*)&work[0x884]] << 8;
        *(s32*)&work[0x84C] = gUnk_09035964[*(s16*)&work[0x886]] << 8;
        func_0808D828(work);
        work[0x8B1] = 9;
        m4aSongNumStart(104);
        SetTaskUpdate(a, (void*)func_0808AB48);
        return 1;
    case 1:
        if ((s8)work[0x8CE] > 0) {
            return 1;
        }

        if ((u8)func_0808E474(work) == 0) {
            return 1;
        }

        TaskCreate((TaskPool*)&work[0x7DC], &gUnk_09EE7D84[0x7D], &work[0x8C9]);
        work[0x8D1] = 1;
        SetTaskUpdate(a, (void*)func_08087438);
        work[0x8B7] = 1;
        work[0x8B1] = 12;
        m4aSongNumStart(104);
        func_0808CD48(work);
        return 1;
    case 8:
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (void*)func_0808B208);
            func_08006184(0, 4);
            m4aSongNumStart(104);
            work[0x8D2] = 7;
        }

        return 1;
    }

    func_0805F1C0((s32*)&work[0x848], gUnk_0903571A[*(s16*)&work[0x884]] << 8);
    func_0805F1C0((s32*)&work[0x84C], (gUnk_0903571E[*(s16*)&work[0x886]] - 16) << 8);

    if ((s8)work[0x8CE] > 0) {
        work[0x8CE]--;
    }

    TaskPoolUpdate((TaskPool*)&work[0x7C8]);
    TaskPoolUpdate((TaskPool*)&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808778C.s");
#endif

#ifdef NON_MATCHING
void func_08087B98(u8* work) {
    UnkStruct_0808E890* node;
    UnkStruct_0808E890* p;
    s32 i;

    node = ListPoolFirst(&work[0x7F0]);
    i = 0;
    EwramFree((*(UnkStruct_0808E2F0**)&work[0x4D4])[*(u16*)&work[0x880]].unk_1C);
    (*(UnkStruct_0808E2F0**)&work[0x4D4])[*(u16*)&work[0x880]].unk_1C = 0;

    for (i = *(u16*)&work[0x880]; i < *(u16*)&work[0x898] - 1; i++) {
        (*(UnkStruct_0808E2F0**)&work[0x4D4])[i] =
            (*(UnkStruct_0808E2F0**)&work[0x4D4])[i + 1];
    }

    *(u16*)&work[0x898] -= 1;
    *(u16*)&work[0x8D4] -= 1;

    while (node != 0) {
        if (node->unk_22 == (s8)work[0x8B5] && node->unk_24 == (s8)work[0x8B6]) {
            break;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    p = ListPoolNext(&node->unk_2C);

    while (p != 0) {
        p->unk_22--;

        if (p->unk_22 < 0) {
            p->unk_22 = 2;
            p->unk_24--;
        }

        p = ListPoolNext(&p->unk_2C);
    }

    node->unk_4A = 1;
    TaskPoolUpdate(&work[0x7C8]);
    func_0808D828(work);
    func_0808C940((UnkStruct_0808C940*)work, *(s16*)&work[0x898]);
    func_0808C974((UnkStruct_0808C940*)work);
}
#else
INCLUDE_ASM("card/func_08087B98.s");
#endif
INCLUDE_ASM("card/func_08087CD4.s");
#ifdef NON_MATCHING
u8 func_080882DC(u8* work, void* a) {
    u16 i;
    u16 n;

    *(void**)&work[0x4F0] = AnimUpdate((AnimState*)&work[0x800]);

    if (work[0x8C9] != 0) {
        func_0805F1C0((s32*)&work[0x848], gUnk_09035702[*(s16*)&work[0x884]] << 8);
        func_0805F1C0((s32*)&work[0x84C], 0x1E00);
        TaskPoolUpdate((TaskPool*)&work[0x7C8]);
        TaskPoolUpdate((TaskPool*)&work[0x7DC]);

        if (GetKeysPressed() & 8) {
            work[0x8D2] = 7;
            work[0x8CB] = 1;
        }

        return 1;
    }

    if (work[0x8CB] != 0) {
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (void*)func_0808B208);
            func_08006184(0, 4);
            m4aSongNumStart(103);
            return 1;
        }

        work[0x8CB] = 0;
    }

    switch (GetKeysRepeat()) {
    case 32:
        if (*(s16*)&work[0x884] > 1) {
            (*(s16*)&work[0x884])--;
            work[0x8B7] = 1;
            m4aSongNumStart(101);
            n = *(u16*)&work[0x884];
            work[0x8C1] = n;
            func_0808D4E4(work[0x8C1], work[0x8C7]);
            func_0808C90C(work);

            if (work[0x8B1] == 6) {
                *(u16*)&work[0x8D4] = func_0808C60C(work, work[0x8C1], 0);
            } else {
                *(u16*)&work[0x8D4] = func_0808C60C(work, work[0x8C1], 1);
            }
        }

        for (i = 0; i <= 9; i++) {
            func_0808DD20(0, i);
        }
        break;
    case 16:
        if (*(s16*)&work[0x884] <= 4) {
            (*(s16*)&work[0x884])++;
            work[0x8B7] = 1;
            m4aSongNumStart(101);
            n = *(u16*)&work[0x884];
            work[0x8C1] = n;
            func_0808D4E4(work[0x8C1], work[0x8C7]);
            func_0808C90C(work);

            if (work[0x8B1] == 6) {
                *(u16*)&work[0x8D4] = func_0808C60C(work, work[0x8C1], 0);
            } else {
                *(u16*)&work[0x8D4] = func_0808C60C(work, work[0x8C1], 1);
            }
        }

        for (i = 0; i <= 9; i++) {
            func_0808DD20(0, i);
        }
        break;
    case 128:
        if (*(u16*)&work[0x8D4] != 0) {
            *(s16*)&work[0x884] = 0;
            *(s16*)&work[0x886] = 0;
            work[0x8B7] = 1;
            m4aSongNumStart(121);
            func_0808D828(work);

            if (work[0x8B1] == 6) {
                work[0x8B1] = 4;
                SetTaskUpdate(a, (void*)func_080897CC);
            }

            if (work[0x8B1] == 10) {
                work[0x8B1] = 9;
                SetTaskUpdate(a, (void*)func_0808AB48);
            }
        } else {
            m4aSongNumStart(105);
        }

        *(s32*)&work[0x850] = 0xA000;
        *(s32*)&work[0x854] = 0x2800;
        *(u16*)&work[0x8AC] = 4;
        return 1;
    case 2:
        if (*(u16*)&work[0x8D4] != 0) {
            *(s16*)&work[0x884] = 0;
            *(s16*)&work[0x886] = 0;
            work[0x8B7] = 1;
            m4aSongNumStart(121);
            func_0808D828(work);

            if (work[0x8B1] == 6) {
                work[0x8B1] = 4;
                SetTaskUpdate(a, (void*)func_080897CC);
            }

            if (work[0x8B1] == 10) {
                work[0x8B1] = 9;
                SetTaskUpdate(a, (void*)func_0808AB48);
            }
        } else {
            m4aSongNumStart(103);

            if (work[0x8B1] == 6) {
                SetTaskUpdate(a, (void*)func_08089D20);
            }

            if (work[0x8B1] == 10) {
                SetTaskUpdate(a, (void*)func_0808B068);
            }
        }

        *(s32*)&work[0x850] = 0xA000;
        *(s32*)&work[0x854] = 0x2800;
        *(u16*)&work[0x8AC] = 4;
        return 1;
    case 512:
        if (work[0x8B1] == 6) {
            func_08006120(0, 1);
            func_0808E2F0((UnkStruct_0808DB04*)work);
            SetTaskUpdate(a, (void*)func_08089EC0);
            m4aSongNumStart(103);
            return 1;
        }
        break;
    case 8:
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (void*)func_0808B208);
            func_08006184(0, 4);
            m4aSongNumStart(104);
            work[0x8D2] = 7;
        }

        return 1;
    }

    func_0805F1C0((s32*)&work[0x848], gUnk_09035702[*(s16*)&work[0x884]] << 8);
    func_0805F1C0((s32*)&work[0x84C], 0x1E00);
    TaskPoolUpdate((TaskPool*)&work[0x7C8]);
    TaskPoolUpdate((TaskPool*)&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080882DC.s");
#endif
u8 func_08088768(u8* work, void* a) {
#ifdef VERSION_EU
    UnkStruct_09035730 tbl;

    tbl = gUnk_09035730;
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x804]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x81C]);

    if (GetKeysPressed() & 0x20) {
        if (work[0x8D5] != 0) {
            work[0x8D5]--;
        }

        work[0x8BB] = 1;
        m4aSongNumStart(0x65);
    }

    if (GetKeysPressed() & 0x10) {
        if (work[0x8D5] == 0) {
            work[0x8D5]++;
        }

        work[0x8BB] = 1;
        m4aSongNumStart(0x65);
    }

    if (GetKeysPressed() & 1) {
        if (work[0x8D5] == 1) {
            work[0x8BB] = 1;
            work[0x8B5] = 3;
            func_0808CD48(work);
            SetTaskUpdate(a, (void*)func_08088F24);
            TaskPoolUpdate(&work[0x7CC]);
            TaskPoolUpdate(&work[0x7E0]);
            m4aSongNumStart(0x67);
            return 1;
        }

        m4aSongNumStart(0x66);
        func_080851E4(work[0x8C4]);
        func_0808D0A4(work[0x8C4]);
        func_0808D258(work[0x8C4]);
        func_0808D594();
        *(u16*)&work[0x8A6] = func_08085844(0, work[0x8C4]);
        *(u16*)&work[0x8A8] = func_08085844(1, work[0x8C4]);
        *(u16*)&work[0x8AA] = func_08085844(2, work[0x8C4]);
        *(u16*)&work[0x8AC] = func_08085844(3, work[0x8C4]);
        func_0808CBB4(*(u16*)&work[0x8A6], 0);
        func_0808CBB4(*(u16*)&work[0x8A8], 1);
        func_0808CBB4(*(u16*)&work[0x8AA], 2);
        func_0808CBB4(*(u16*)&work[0x8AC], 3);
        func_0808C90C(work);
        TaskPoolUpdate(&work[0x7CC]);
        TaskPoolUpdate(&work[0x7E0]);
        work[0x8BB] = 1;
        work[0x8B5] = 3;
        func_0808CD48(work);
        SetTaskUpdate(a, (void*)func_08088F24);
    }

    if (GetKeysPressed() & 2) {
        work[0x8BB] = 1;
        work[0x8B5] = 3;
        func_0808CD48(work);
        m4aSongNumStart(0x67);
        SetTaskUpdate(a, (void*)func_08088F24);
        TaskPoolUpdate(&work[0x7CC]);
        TaskPoolUpdate(&work[0x7E0]);
        return 1;
    }

    func_0805F1C0((s32*)&work[0x84C], tbl.unk_00[work[0x8D5]] << 8);
    func_0805F1C0((s32*)&work[0x850], 0x7200);
    TaskPoolUpdate(&work[0x7CC]);
    TaskPoolUpdate(&work[0x7E0]);
    return 1;
#else
    UnkStruct_09035730 tbl;

    tbl = gUnk_09035730;
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x818]);

    if (GetKeysPressed() & 0x20) {
        if (work[0x8D1] != 0) {
            work[0x8D1]--;
        }

        work[0x8B7] = 1;
        m4aSongNumStart(0x65);
    }

    if (GetKeysPressed() & 0x10) {
        if (work[0x8D1] == 0) {
            work[0x8D1]++;
        }

        work[0x8B7] = 1;
        m4aSongNumStart(0x65);
    }

    if (GetKeysPressed() & 1) {
        if (work[0x8D1] == 1) {
            work[0x8B7] = 1;
            work[0x8B1] = 3;
            func_0808CD48(work);
            SetTaskUpdate(a, (void*)func_08088F24);
            TaskPoolUpdate(&work[0x7C8]);
            TaskPoolUpdate(&work[0x7DC]);
            m4aSongNumStart(0x67);
            return 1;
        }

        m4aSongNumStart(0x66);
        func_080851E4(work[0x8C0]);
        func_0808D0A4(work[0x8C0]);
        func_0808D258(work[0x8C0]);
        func_0808D594();
        *(u16*)&work[0x8A2] = func_08085844(0, work[0x8C0]);
        *(u16*)&work[0x8A4] = func_08085844(1, work[0x8C0]);
        *(u16*)&work[0x8A6] = func_08085844(2, work[0x8C0]);
        *(u16*)&work[0x8A8] = func_08085844(3, work[0x8C0]);
        func_0808CBB4(*(u16*)&work[0x8A2], 0);
        func_0808CBB4(*(u16*)&work[0x8A4], 1);
        func_0808CBB4(*(u16*)&work[0x8A6], 2);
        func_0808CBB4(*(u16*)&work[0x8A8], 3);
        func_0808C90C(work);
        TaskPoolUpdate(&work[0x7C8]);
        TaskPoolUpdate(&work[0x7DC]);
        work[0x8B7] = 1;
        work[0x8B1] = 3;
        func_0808CD48(work);
        SetTaskUpdate(a, (void*)func_08088F24);
    }

    if (GetKeysPressed() & 2) {
        work[0x8B7] = 1;
        work[0x8B1] = 3;
        func_0808CD48(work);
        m4aSongNumStart(0x67);
        SetTaskUpdate(a, (void*)func_08088F24);
        TaskPoolUpdate(&work[0x7C8]);
        TaskPoolUpdate(&work[0x7DC]);
        return 1;
    }

    func_0805F1C0((s32*)&work[0x848], tbl.unk_00[work[0x8D1]] << 8);
    func_0805F1C0((s32*)&work[0x84C], 0x7200);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
#endif
}
INCLUDE_ASM("card/func_080889DC.s");
u8 func_08088EB4(u8* work, void* a) {
    u8* p;
    u8 z;

#ifdef VERSION_EU
    *(void**)&work[8] = LoadObjTiles(gUnkEu_09F6FDB4[gLanguage], gUnkEu_090CE9EA[gLanguage]);
#else
    *(void**)&work[8] = LoadObjTiles(gUnk_090A261E, 0x1800);
#endif
    *(void**)&work[12] = LoadObjPalette(gUnk_096144D8, 32);
    func_0808E364(work, 1);
    p = &work[CARDWORK(0x8B1)];
    z = 0;
    *p = 3;
    work[CARDWORK(0x8C8)] = z;
    SetTaskUpdate(a, (void*)func_08088F24);
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}
INCLUDE_ASM("card/func_08088F24.s");
#ifndef VERSION_EU
u8 func_08089220(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x818]);
    func_0808E344((void**)work);
    func_0808E364(work, 0);

    switch (work[0x8C8]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        if (work[0x8B2] == 0) {
            work[0x8B1] = 0;
            func_0808CD48(work);
            work[0x8B7] = 4;
            SetTaskUpdate(a, (void*)func_08086A14);
        } else {
            work[0x8B1] = 1;
            work[0x8B7] = 4;
            SetTaskUpdate(a, (void*)func_080889DC);
        }
        break;
    }

    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08089220.s");
#endif
#ifndef VERSION_EU
u8 func_080892E8(u8* work, void* a) {
    func_08006120(0, 4);

    switch (work[0x8C0]) {
    case 0:
        SetupBg(0, 3, 31, 0);
        SetupBg(1, 0, 23, 0);
        SetupBg(2, 0, 15, 0);
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_095182B8, 0x800);
        LoadBgMap(2, gUnk_09514AB8, 0x800);
        SetBgScroll(0, 0, 0xFFF0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        *(u16*)&work[0x888] = 16;
        *(u16*)&work[0x88E] = 28;
        break;
    case 1:
        SetupBg(0, 0, 31, 0);
        SetupBg(1, 2, 23, 0);
        SetupBg(2, 0, 15, 0);
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095182B8, 0x800);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_09514AB8, 0x800);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0xFFF0);
        SetBgScroll(2, 0, 0);
        *(u16*)&work[0x88A] = 16;
        *(u16*)&work[0x890] = 28;
        break;
    case 2:
        SetupBg(0, 0, 31, 0);
        SetupBg(1, 0, 23, 0);
        SetupBg(2, 1, 15, 0);
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095182B8, 0x800);
        LoadBgMap(1, gUnk_09514AB8, 0x800);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0xFFF0);
        *(u16*)&work[0x88C] = 16;
        *(u16*)&work[0x892] = 28;
        break;
    }

    func_0808500C(work[0x8C0], (u16*)&work[0x89A]);
    func_0808CC58(*(u16*)&work[0x89A], 0);
    func_0808CC58(*(u16*)&work[0x89C], 1);
    func_0808CC58(*(u16*)&work[0x89E], 2);
    func_0808CC58(*(u16*)&work[0x8A0], 3);
    work[0x8D0] = 0;
    SetTaskUpdate(a, (void*)func_08089558);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080892E8.s");
#endif
#ifdef NON_MATCHING
u8 func_08089558(u8* work, void* a) {
    UnkStruct_08084D78* e;
    u16 i;
    u16 n;
    vu32 zero;

    func_08006120(0, 4);

    switch (work[0x8D0]) {
    case 0:
        work[0x8B1] = 4;
        *(u16*)&work[0x894] = 7;
        *(u16*)&work[0x896] = 130;
        func_0808E344((void**)work);
        func_0808E364(work, 0);
        func_0808C90C(work);
        LoadBgMap(3, gUnk_095132B8 + 0x1000, 0x800);
        n = 0x11E;
        *(u16*)&work[0x898] = n;
        *(void**)&work[0x4D8] = EwramAlloc(n * 32);
        zero = 0;
        CpuSet((void*)&zero, *(void**)&work[0x4D8], (*(u16*)&work[0x898] * 8) | 0x05000000);
        *(s32*)&work[0x4D4] = 0;
        break;
    case 1:
        func_08084D78(*(void**)&work[0x4D8], work[0x8C0], 1, *(u16*)&work[0x898], &work[0x4FC]);
        break;
    case 2:
        *(u16*)&work[0x898] = func_08084E50(*(void**)&work[0x4D8], work[0x8C0], 1, *(u16*)&work[0x898], &work[0x4FC]);
        break;
    case 3:
        if (*(u16*)&work[0x898] != 0) {
            func_0808FA8C(work);
        }
        break;
    case 4:
        for (i = 0; i < 0x11E; i++) {
            e = (UnkStruct_08084D78*)(*(u32*)&work[0x4D8] + i * 32);

            if (e->unk_16 != 0) {
                EwramFree(e->unk_1C);
            }
        }

        EwramFree(*(void**)&work[0x4D8]);
        break;
    case 5:
        work[0x8C1] = 5;
        *(u16*)&work[0x8D4] = func_0808C60C(work, 5, 0);
        func_0808CD48(work);
        *(s32*)&work[0x848] = gUnk_0903595E[0] << 8;
        *(s32*)&work[0x84C] = gUnk_09035964[0] << 8;
        work[0x8C7] = 2;
        *(u16*)&work[0x884] = 0;
        *(u16*)&work[0x886] = 0;
        func_0808D828(work);
        func_0808DE28(0);

        if (*(u16*)&work[0x8D4] != 0) {
            work[0x8D0] = 4;
            SetTaskUpdate(a, (void*)func_080897CC);
        } else {
            *(u16*)&work[0x884] = work[0x8C1];
            work[0x8B7] = 1;
            work[0x8B1] = 6;
            SetTaskUpdate(a, (void*)func_080882DC);
        }
        break;
    }

    work[0x8D0]++;
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08089558.s");
#endif
INCLUDE_ASM("card/func_080897CC.s");

#ifndef VERSION_EU
u8 func_08089D20(u8* work, void* a) {
    u8* q;

    func_08006120(0, 4);
    q = &work[0x8B1];
    *q = 4;
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[0x8C0]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[0x8C1] = 0;
    *(s16*)&work[0x884] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[0x8C0];
    func_0808C3DC(work, work[0x8C1]);
    work[0x8C7] = 0;
    *q = 1;
    func_0808CD48(work);
    func_0805F1C0(&work[0x848], gUnk_090356EC[*(s16*)&work[0x884]] << 8);
    func_0805F1C0(&work[0x84C], gUnk_090356F2[*(s16*)&work[0x886]] << 8);
    SetTaskUpdate(a, (void*)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
    TaskPoolUpdate(&work[0x7C8]);
    work += 0x7DC;
    TaskPoolUpdate(work);
    return 1;
}
#else
INCLUDE_ASM("card/func_08089D20.s");
#endif

#ifndef VERSION_EU
u8 func_08089EC0(u8* work, void* a) {
    func_08006120(0, 4);

    switch (work[0x8C0]) {
    case 0:
        SetupBg(0, 3, 31, 0);
        SetupBg(1, 0, 23, 0);
        SetupBg(2, 0, 15, 0);
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_095172B8, 0x800);
        LoadBgMap(2, gUnk_09517AB8, 0x800);
        SetBgScroll(0, -88, -16);
        SetBgScroll(1, -88, -112);
        SetBgScroll(2, -140, -96);
        *(u16*)&work[0x888] = 102;
        *(u16*)&work[0x88E] = 28;
        break;
    case 1:
        SetupBg(0, 0, 31, 0);
        SetupBg(1, 2, 23, 0);
        SetupBg(2, 0, 15, 0);
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095172B8, 0x800);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_09517AB8, 0x800);
        SetBgScroll(0, -88, -112);
        SetBgScroll(1, -88, -16);
        SetBgScroll(2, -140, -96);
        *(u16*)&work[0x88A] = 102;
        *(u16*)&work[0x890] = 28;
        break;
    case 2:
        SetupBg(0, 0, 31, 0);
        SetupBg(1, 0, 23, 0);
        SetupBg(2, 1, 15, 0);
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095172B8, 0x800);
        LoadBgMap(1, gUnk_09517AB8, 0x800);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, -88, -112);
        SetBgScroll(1, -140, -96);
        SetBgScroll(2, -88, -16);
        *(u16*)&work[0x88C] = 102;
        *(u16*)&work[0x892] = 28;
        break;
    }

    SetTaskUpdate(a, (void*)func_0808A114);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_08089EC0.s");
#endif
#ifdef NON_MATCHING
u8 func_0808A114(u8* work, void* a) {
    *(u16*)&work[0x894] = 94;
    *(u16*)&work[0x896] = 130;
    work[0x8B1] = 7;
    func_0808E344((void**)work);
    func_0808E364(work, 0);
    func_0808CD48(work);
    LoadBgMap(3, gUnk_095132B8, 0x800);
    func_0808C90C(work);
    work[0x8C1] = 0;
    *(s16*)&work[0x884] = 0;
    *(s16*)&work[0x886] = 0;
    func_0808C3DC(work, work[0x8C1]);
    *(s32*)&work[0x848] = gUnk_09035950[*(s16*)&work[0x884]] << 8;
    *(s32*)&work[0x84C] = gUnk_09035956[*(s16*)&work[0x886]] << 8;
    func_0808DB50((UnkStruct_0808DB04*)work);
    work[0x8C7] = 1;
    SetTaskUpdate(a, (void*)func_0808A218);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808A114.s");
#endif
#ifdef NON_MATCHING
u8 func_0808A218(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate((AnimState*)&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate((AnimState*)&work[0x818]);

    if (work[0x8C9] != 0) {
        TaskPoolUpdate((TaskPool*)&work[0x7C8]);
        TaskPoolUpdate((TaskPool*)&work[0x7DC]);

        if (GetKeysPressed() & 8) {
            work[0x8D2] = 7;
            work[0x8CB] = 1;
        }

        return 1;
    }

    if (work[0x8CB] != 0) {
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (void*)func_0808B208);
            func_08006184(0, 4);
            m4aSongNumStart(103);
            return 1;
        }

        work[0x8CB] = 0;
    }

    switch (GetKeysRepeat()) {
    case 32:
        if (*(s16*)&work[0x884] > 0) {
            (*(s16*)&work[0x884])--;
            work[0x8B7] = 1;
            m4aSongNumStart(121);
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    case 16:
        if (*(s16*)&work[0x884] <= 1) {
            (*(s16*)&work[0x884])++;
            work[0x8B7] = 1;
            m4aSongNumStart(121);
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    case 64:
        if (*(s16*)&work[0x886] > 0) {
            (*(s16*)&work[0x886])--;
            work[0x8B7] = 1;
            m4aSongNumStart(121);
        } else if ((u8)func_0808CA78(work, 1) == 0) {
            *(s16*)&work[0x884] = work[0x8C1];
            work[0x8B7] = 1;
            m4aSongNumStart(121);
            work[0x8B1] = 8;
            SetTaskUpdate(a, (void*)func_080870FC);
            func_0808DE28(0);
            return 1;
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    case 128:
        if (*(s16*)&work[0x886] <= 2) {
            (*(s16*)&work[0x886])++;
            work[0x8B7] = 1;
            m4aSongNumStart(121);
        } else {
            func_0808C9CC(work);
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    }

    switch (GetKeysPressed()) {
    case 1:
        func_0808E3E0(work);
        func_0808DB50((UnkStruct_0808DB04*)work);
        func_0808D0A4(work[0x8C0]);
        func_0808D258(work[0x8C0]);
        *(u16*)&work[0x8A2] = func_08085844(0, work[0x8C0]);
        *(u16*)&work[0x8A4] = func_08085844(1, work[0x8C0]);
        *(u16*)&work[0x8A6] = func_08085844(2, work[0x8C0]);
        *(u16*)&work[0x8A8] = func_08085844(3, work[0x8C0]);
        func_0808CBB4(work[0x8A2], 0);
        func_0808CBB4(work[0x8A4], 1);
        func_0808CBB4(work[0x8A6], 2);
        func_0808CBB4(work[0x8A8], 3);
        func_0808D594();
        break;
    case 2:
        work[0x8CA] = 0;
        func_08006120(0, 1);
        SetTaskUpdate(a, (void*)func_0808A650);
        m4aSongNumStart(103);
        return 1;
    case 256:
        work[0x8CA] = 1;
        func_0808E2F0((UnkStruct_0808DB04*)work);
        func_08006120(0, 1);
        SetTaskUpdate(a, (void*)func_080892E8);
        m4aSongNumStart(103);
        return 1;
    case 8:
        if ((u8)func_0808E750(work) == 0) {
            return 1;
        }

        if ((u8)func_0808E79C(work) == 0) {
            return 1;
        }

        SetTaskUpdate(a, (void*)func_0808B208);
        func_08006184(0, 4);
        m4aSongNumStart(104);
        work[0x8D2] = 7;
        return 1;
    }

    if ((GetKeysPressed() & 4) == 0) {
        func_0805F1C0((s32*)&work[0x848], gUnk_09035950[*(s16*)&work[0x884]] << 8);
        func_0805F1C0((s32*)&work[0x84C], gUnk_09035956[*(s16*)&work[0x886]] << 8);
        TaskPoolUpdate((TaskPool*)&work[0x7C8]);
        TaskPoolUpdate((TaskPool*)&work[0x7DC]);
        return 1;
    }

    *(s16*)&work[0x886] = 0;
    func_0808E7D8(work);
    *(s16*)&work[0x884] = work[0x8C1];
    work[0x8B7] = 1;
    *(s32*)&work[0x850] = 0x4800;
    *(s32*)&work[0x854] = 0x2800;
    *(u16*)&work[0x8AC] = 4;
    m4aSongNumStart(121);
    work[0x8B1] = 8;
    TaskPoolUpdate((TaskPool*)&work[0x7C8]);
    TaskPoolUpdate((TaskPool*)&work[0x7DC]);
    SetTaskUpdate(a, (void*)func_080870FC);
    func_0808DE28(0);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808A218.s");
#endif

u8 func_0808A650(u8* work, void* a) {
    func_08006120(0, 4);
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
#ifdef VERSION_EU
    SetupBg(2, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 31, 0);
#else
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
#endif
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[CARDWORK(0x8C0)]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[CARDWORK(0x8C1)] = 0;
    *(s16*)&work[CARDWORK(0x884)] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[CARDWORK(0x8C0)];
    func_0808C3DC(work, work[CARDWORK(0x8C1)]);
    work[CARDWORK(0x8C7)] = 0;
    work[CARDWORK(0x8B1)] = 1;
    func_0808CD48(work);
    func_0805F1C0(&work[CARDWORK(0x848)], gUnk_090356EC[*(s16*)&work[CARDWORK(0x884)]] << 8);
    func_0805F1C0(&work[CARDWORK(0x84C)], gUnk_090356F2[*(s16*)&work[CARDWORK(0x886)]] << 8);
    SetTaskUpdate(a, (void*)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}

u8 func_0808A7E4(u8* work, void* a) {
    u8 z;
    u8* q;

    func_08006120(0, 4);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 0, 15, 0);
    SetupBg(1, 0, 23, 0);
    SetupBg(0, 0, 31, 0);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    SetBgScroll(2, 0, 16);
    LoadBgMap(3, gUnk_095192B8, 0x800);
    LoadBgMap(2, gUnk_095182B8, 0x800);
    LoadBgMap(1, gUnk_09514AB8, 0x800);
    DisableBg(0);
    func_0808500C(3, (u16*)&work[CARDWORK(0x89A)]);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89A)], 0);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89C)], 1);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89E)], 2);
    func_0808CC58(*(u16*)&work[CARDWORK(0x8A0)], 3);
    q = &work[CARDWORK(0x8B1)];
    z = 0;
    *q = 9;
    func_0808E344((void**)work);
    func_0808E364(work, 0);
    func_0808C90C(work);
    work[CARDWORK(0x8D0)] = z;
    SetTaskUpdate(a, (void*)func_0808A910);
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}
INCLUDE_ASM("card/func_0808A910.s");
INCLUDE_ASM("card/func_0808AB48.s");

u8 func_0808B068(u8* work, void* a) {
    u8* q;

    func_08006120(0, 4);
    q = &work[CARDWORK(0x8B1)];
    *q = 9;
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
#ifdef VERSION_EU
    SetupBg(2, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 31, 0);
#else
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
#endif
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[CARDWORK(0x8C0)]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[CARDWORK(0x8C1)] = 0;
    *(s16*)&work[CARDWORK(0x884)] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[CARDWORK(0x8C0)];
    func_0808C3DC(work, work[CARDWORK(0x8C1)]);
    work[CARDWORK(0x8C7)] = 0;
    *q = 1;
    func_0808CD48(work);
    func_0805F1C0(&work[CARDWORK(0x848)], gUnk_090356EC[*(s16*)&work[CARDWORK(0x884)]] << 8);
    func_0805F1C0(&work[CARDWORK(0x84C)], gUnk_090356F2[*(s16*)&work[CARDWORK(0x886)]] << 8);
    SetTaskUpdate(a, (void*)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}

u8 func_0808B208(u8* work) {
    if (func_08006314() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}
u8 func_0808B238(u8* work, void* a) {
    *(void**)&work[0x4BC] = LoadObjTiles(gUnk_090A583E, 0x620);

#ifdef VERSION_EU
    *(void**)&work[0x18] = LoadObjTiles(gUnkEu_09F6FDDC[gLanguage], gUnkEu_090CE9F4[gLanguage]);
#elif defined(VERSION_US)
    if (gGameState.flags & 8) {
        *(void**)&work[0x18] = LoadObjTiles(gUnk_090A418E, 0x320);
    } else {
        *(void**)&work[0x18] = LoadObjTiles(gUnk_090A3E46, 0x320);
    }
#else
    *(void**)&work[0x18] = LoadObjTiles(gUnk_090A418E, 0x320);
#endif

    *(void**)&work[0x4C0] = LoadObjPalette(gUnk_096144F8, 32);
#ifdef VERSION_EU
    LoadBgMap(3, gUnk_095132B8, 0x800);
#else
    LoadBgMap(3, gUnk_09516AB8, 0x800);
#endif
    *(s32*)&work[CARDWORK(0x858)] = 0x7800;
    *(s32*)&work[CARDWORK(0x860)] = 0;
    *(s32*)&work[CARDWORK(0x85C)] = 0xA400;
    *(s32*)&work[CARDWORK(0x864)] = 0x9800;
    *(s32*)&work[CARDWORK(0x868)] = 0;
    work[CARDWORK(0x8CC)] = 16;
    work[CARDWORK(0x8CD)] = 16;
    work[CARDWORK(0x8B0)] = 0;
    SetTaskUpdate(a, (void*)func_0808B30C);
    return 1;
}

u8 func_0808B30C(u8* work, void* a) {
    if ((s8)work[CARDWORK(0x8CD)] > 0) {
        ApproachValue(&work[CARDWORK(0x868)], -0x8000, (u16)(s8)work[CARDWORK(0x8CD)]);
        work[CARDWORK(0x8CD)]--;
    } else if ((s8)work[CARDWORK(0x8CC)] > 0) {
        ApproachValue(&work[CARDWORK(0x860)], -0x800, (u16)(s8)work[CARDWORK(0x8CC)]);
        ApproachValue(&work[CARDWORK(0x864)], 0xA000, (u16)(s8)work[CARDWORK(0x8CC)]);
        work[CARDWORK(0x8CC)]--;
    } else {
        func_08006184(0, 4);
        SetTaskUpdate(a, (void*)func_0808B208);
    }

    return 1;
}

void func_0808B398(u8* work) {
    func_08066588(*(s16*)&work[CARDWORK(0x894)], *(s16*)&work[CARDWORK(0x896)], &work[0x1E8],
                  *(void**)&work[0x14], 20, work[CARDWORK(0x8C6)]);
}

void func_0808B3DC(u8* work, u8 flag) {
    if (flag == 0) {
        switch (work[CARDWORK(0x8C0)]) {
        case 0:
            func_080664D8(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x14], 20, work[CARDWORK(0x8C2)]);
            func_080664D8(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C3)]);
            func_080664D8(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C4)]);
            break;
        case 1:
            func_080664D8(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C2)]);
            func_080664D8(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x14], 20, work[CARDWORK(0x8C3)]);
            func_080664D8(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C4)]);
            break;
        case 2:
            func_080664D8(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C2)]);
            func_080664D8(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C3)]);
            func_080664D8(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x14], 20, work[CARDWORK(0x8C4)]);
            break;
        }
    } else {
        switch (work[CARDWORK(0x8C0)]) {
        case 0:
            func_080664D8(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x14], 20, work[CARDWORK(0x8C2)]);
            break;
        case 1:
            func_080664D8(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x14], 20, work[CARDWORK(0x8C3)]);
            break;
        case 2:
            func_080664D8(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x14], 20, work[CARDWORK(0x8C4)]);
            break;
        }
    }
}
INCLUDE_ASM("card/func_0808B66C.s");

void func_0808C2F0(u8* work) {
    func_0808C90C(work);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x14]);

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x4BC] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4BC]);
    }

    if (*(void**)&work[0x4C0] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4C0]);
    }

    func_0808E344((void**)work);
    func_08065AE0(&work[0x38], 8);
    func_08065AE0(&work[0x78], 8);
    func_08065AE0(&work[0xB8], 8);
    func_08065AE0(&work[0xF8], 30);
    func_08065AE0(&work[0x1E8], 90);
    ReleaseObjPalette(*(void**)&work[0x4C4]);
    TaskPoolDestroy(&work[CARDWORK(0x7C8)]);
    TaskPoolDestroy(&work[CARDWORK(0x7DC)]);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    **(u8**)&work[CARDWORK(0x8BC)] = work[CARDWORK(0x8D2)];
    ReleaseObjTiles(*(void**)&work[0x4B8]);
    ReleaseObjTiles(gUnk_0203A860[0]);
    ReleaseObjPalette(gUnk_0203A860[1]);
}

#ifdef NON_MATCHING
void func_0808C3DC(u8* work, u8 kind) {
    UnkStruct_080A97D4 args;
    Deck* deck;
    u8 i;
    s8 x;
    s8 y;
    u16* p;

    deck = GetDeck(work[0x8C0]);
    x = 0;
    y = 0;

    if (kind == 0) {
        for (i = 0; i < 99; i++) {
            p = &deck->cards[i];

            if (*p != 0xFFFF) {
                args.unk_00 = &work[0x7F0];
                args.unk_04 = gCardCollection[*p] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = p;
                TaskCreate(&work[0x7C8], gUnk_09EE4B28, &args);
            } else {
                args.unk_00 = &work[0x7F0];
                args.unk_04 |= *p;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = p;
                TaskCreate(&work[0x7C8], gUnk_09EE4B28, &args);
            }

            x++;

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    } else {
        for (i = 0; i < 99; i++) {
            p = &deck->cards[i];

            if (*p != 0xFFFF && gCardDefs[gCardCollection[*p] & 0xFFF].unk_2A == kind - 1) {
                args.unk_00 = &work[0x7F0];
                args.unk_04 = gCardCollection[*p] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = p;
                TaskCreate(&work[0x7C8], gUnk_09EE4B28, &args);
                x++;
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }

    *(s32*)&work[0x850] = 0x4800;
    *(s32*)&work[0x854] = 0x2800;
    *(u16*)&work[0x8AC] = 4;
    func_0808C940((UnkStruct_0808C940*)work, 99);
}
#else
INCLUDE_ASM("card/func_0808C3DC.s");
#endif

s32 func_0808C60C(u8* work, u8 kind, u8 c) {
    UnkStruct_080A97D4 args;
    u16 i;
    u16 count;
    s8 x;
    s8 y;

    x = 0;
    y = 0;
    count = 0;

    if (c == 0) {
        for (i = 0; i < *(u16*)&work[CARDWORK(0x898)]; i++) {
            if (kind == 5) {
                if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                    args.unk_00 = &work[CARDWORK(0x7F0)];
                    args.unk_04 = func_0808C8D0(
                        (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 1;
                    args.unk_0C = 0;
                    TaskCreate(&work[CARDWORK(0x7C8)], gUnk_09EE4B28, &args);
                    x++;
                    count++;
                }
            } else if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                args.unk_00 = &work[CARDWORK(0x7F0)];
                args.unk_04 = func_0808C8D0(
                    (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);

                if (gCardDefs[args.unk_04 & 0xFFF].unk_2A == kind - 1) {
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 1;
                    args.unk_0C = 0;
                    TaskCreate(&work[CARDWORK(0x7C8)], gUnk_09EE4B28, &args);
                    x++;
                    count++;
                }
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    } else {
        for (i = 0; i < *(u16*)&work[CARDWORK(0x898)]; i++) {
            if (kind == 5) {
                if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                    if ((u16)((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] - 78) >
                        64) {
                        args.unk_00 = &work[CARDWORK(0x7F0)];
                        args.unk_04 = func_0808C8D0(
                            (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);
                        args.unk_06 = x;
                        args.unk_08 = y;
                        args.unk_0A = 1;
                        args.unk_0C = 0;
                        TaskCreate(&work[CARDWORK(0x7C8)], gUnk_09EE4B28, &args);
                        x++;
                        count++;
                    }
                }
            } else if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                args.unk_00 = &work[CARDWORK(0x7F0)];
                args.unk_04 = func_0808C8D0(
                    (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);

                if (gCardDefs[args.unk_04 & 0xFFF].unk_2A == kind - 1) {
                    if ((u16)((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] - 78) >
                        64) {
                        args.unk_06 = x;
                        args.unk_08 = y;
                        args.unk_0A = 1;
                        args.unk_0C = 0;
                        TaskCreate(&work[CARDWORK(0x7C8)], gUnk_09EE4B28, &args);
                        x++;
                        count++;
                    }
                }
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }

    *(s32*)&work[CARDWORK(0x850)] = 0xA000;
    *(s32*)&work[CARDWORK(0x854)] = 0x2800;
    *(u16*)&work[CARDWORK(0x8AC)] = 4;
    func_0808C940((UnkStruct_0808C940*)work, y * 3 + x);

    return count;
}

s32 func_0808C8D0(s32 a) {
    u32 i;

    for (i = 0; i < 950; i++) {
        if (gCardDefs[i].unk_1C == a) {
            return i;
        }

        if (gCardDefs[i].unk_1C + 143 == a) {
            return i | 0x8000;
        }
    }
}

void func_0808C90C(u8* work) {
    UnkStruct_0808E890* t;

    t = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (t != 0) {
        t->unk_4A = 1;
        t = ListPoolNext(&t->unk_2C);
    }

    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
}

void func_0808C940(UnkStruct_0808C940* w, s16 n) {
    w->unk_8AE = n / 3;

    if (n % 3 != 0) {
        w->unk_8AE = n / 3 + 1;
    }
}

void func_0808C974(UnkStruct_0808C940* w) {
    s32 v;

    v = 0x5400 / (w->unk_8AE - 4);
    w->unk_854 = v * (w->unk_8AC - 4) + 0x2800;

    if (w->unk_854 > 0x7C00) {
        w->unk_854 = 0x7C00;
    }

    if (w->unk_854 <= 0x27FF) {
        w->unk_854 = 0x2800;
    }
}

void func_0808C9CC(u8* work) {
    UnkStruct_0808E890* node;

#ifdef VERSION_EU
    node = ListPoolFirst(&work[0x7F4]);

    if (*(s16*)&work[0x8B0] != *(s16*)&work[0x8B2]) {
        while (node != 0) {
            node->unk_24--;

            if (node->unk_24 < 0) {
                node->unk_44 = 0x20000;
                func_08090170(node);
            }

            node = ListPoolNext(&node->unk_2C);
        }

        m4aSongNumStart(121);
        *(u16*)&work[0x8B0] += 1;
        *(s32*)&work[0x858] += 0x300;

        if (*(s32*)&work[0x858] > 0x7C00) {
            *(s32*)&work[0x858] = 0x7C00;
        }

        if (work[0x8D3] != 0) {
            *(u16*)&work[0x87A] -= 1;
        }

        func_0808C974((UnkStruct_0808C940*)work);
    }
#else
    node = ListPoolFirst(&work[0x7F0]);

    if (*(s16*)&work[0x8AC] != *(s16*)&work[0x8AE]) {
        while (node != 0) {
            node->unk_24--;

            if (node->unk_24 < 0) {
                node->unk_44 = 0x20000;
                func_08090170(node);
            }

            node = ListPoolNext(&node->unk_2C);
        }

        m4aSongNumStart(121);
        *(u16*)&work[0x8AC] += 1;
        *(s32*)&work[0x854] += 0x300;

        if (*(s32*)&work[0x854] > 0x7C00) {
            *(s32*)&work[0x854] = 0x7C00;
        }

        if (work[0x8CF] != 0) {
            *(u16*)&work[0x876] -= 1;
        }

        func_0808C974((UnkStruct_0808C940*)work);
    }
#endif
}

u8 func_0808CA78(u8* work, u8 a) {
    UnkStruct_0808E890* n;
    u8 b;
    u16 t;

    b = a;
    n = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    if (*(s16*)&work[CARDWORK(0x8AC)] <= 4) {
        return 0;
    }

    if (n == 0) {
        *(s32*)&work[CARDWORK(0x854)] -= 0x300;

        t = *(u16*)&work[CARDWORK(0x8AC)];

        if ((s16)t > 4) {
            *(u16*)&work[CARDWORK(0x8AC)] = t - 1;
        }

        if (*(s32*)&work[CARDWORK(0x854)] < 0x2800) {
            *(s32*)&work[CARDWORK(0x854)] = 0x2800;
            return 0;
        }

        if (a != 0) {
            m4aSongNumStart(0x79);
        }
    } else {
        if (b != 0) {
            m4aSongNumStart(0x79);
        }

        do {
            n->unk_24++;

            if (n->unk_24 > 3) {
                n->unk_44 = 0x20000;
                func_08090170(n);
            }

            n = ListPoolNext(n->unk_2C);
        } while (n != 0);

        *(u16*)&work[CARDWORK(0x8AC)] = *(u16*)&work[CARDWORK(0x8AC)] - 1;
        *(s32*)&work[CARDWORK(0x854)] -= 0x300;

        if (*(s32*)&work[CARDWORK(0x854)] < 0x2800) {
            *(s32*)&work[CARDWORK(0x854)] = 0x2800;
        }
    }

    func_0808C974((UnkStruct_0808C940*)work);
    return 1;
}

UnkStruct_0808E890* func_0808CB60(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (node != 0) {
        if (*(s16*)&work[CARDWORK(0x884)] == node->unk_22 &&
            *(s16*)&work[CARDWORK(0x886)] == node->unk_24) {
            return node;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

void func_0808CBB4(u8 a, u8 b) {
    u8 d[2];
    u8* base;

    if (a == 0) {
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(gUnk_0940F918, base + (b * 64 + 0x360), 32);
        RequestDma3Copy(gUnk_0940F918, base + (b * 64 + 0x360) + 32, 32);
    } else {
        d[0] = a / 10;
        d[1] = a - (u8)(a / 10) * 10;
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(&gUnk_0940F7B8[(d[0] + 1) * 32], base + (b * 64 + 0x360), 32);
        RequestDma3Copy(&gUnk_0940F7B8[(d[1] + 1) * 32], base + (b * 64 + 0x360) + 32, 32);
    }
}

void func_0808CC58(u16 a, u8 b) {
    u8 d[3];
    u8* base;

    if (a == 0) {
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(gUnk_0940F918, base + (b * 96 + 0x120), 32);
        RequestDma3Copy(gUnk_0940F918, base + (b * 96 + 0x120) + 32, 32);
        RequestDma3Copy(gUnk_0940F918, base + (b * 96 + 0x120) + 64, 32);
    } else {
        d[0] = a / 100;
        d[1] = a / 10 - d[0] * 10;
        d[2] = a - d[0] * 100 - d[1] * 10;
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(&gUnk_0940F7B8[(d[0] + 1) * 32], base + (b * 96 + 0x120), 32);
        RequestDma3Copy(&gUnk_0940F7B8[(d[1] + 1) * 32], base + (b * 96 + 0x120) + 32, 32);
        RequestDma3Copy(&gUnk_0940F7B8[(d[2] + 1) * 32], base + (b * 96 + 0x120) + 64, 32);
    }
}

void func_0808CD48(u8* work) {
    u16 t;

    switch (work[CARDWORK(0x8B1)]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
        AnimStart(&work[CARDWORK(0x800)], 0, 1);
        *(u16*)&work[CARDWORK(0x882)] &= ~1;
        break;
    case 1:
    case 3:
    case 12:
        AnimStart(&work[CARDWORK(0x800)], 2, 1);
        t = *(u16*)&work[CARDWORK(0x882)] | 1;
        *(u16*)&work[CARDWORK(0x882)] = t;
        break;
    }
}

#ifdef NON_MATCHING
void func_0808CDE8(u8* work, u8 b) {
    switch (b) {
    case 0:
        LoadPalette(gUnk_096142F8, (void*)0x05000100, 32);
        LoadPalette(&gUnk_09614118[0x120], (void*)0x05000120, 32);
        LoadPalette(&gUnk_09614118[0x140], (void*)0x05000140, 32);
        LoadBgMap(0, &gUnk_09519AB8[0x180], 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, 0xFFB4, 0xFFF2);
        SetBgScroll(1, 0xFFA8, 0xFFC0);
        SetBgScroll(2, 0xFFA8, 0xFF90);
        *(u16*)&work[0x888] = 100;
        *(u16*)&work[0x88E] = 25;
        *(u16*)&work[0x88A] = 102;
        *(u16*)&work[0x890] = 75;
        *(u16*)&work[0x88C] = 102;
        *(u16*)&work[0x892] = 122;
        break;
    case 1:
        LoadPalette(gUnk_096142F8, (void*)0x05000120, 32);
        LoadPalette(&gUnk_09614118[0x100], (void*)0x05000100, 32);
        LoadPalette(&gUnk_09614118[0x140], (void*)0x05000140, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, &gUnk_0951A2B8[0x180], 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, 0xFFA8, 0xFFF0);
        SetBgScroll(1, 0xFFB4, 0xFFC2);
        SetBgScroll(2, 0xFFA8, 0xFF90);
        *(u16*)&work[0x888] = 102;
        *(u16*)&work[0x88E] = 27;
        *(u16*)&work[0x88A] = 100;
        *(u16*)&work[0x890] = 73;
        *(u16*)&work[0x88C] = 102;
        *(u16*)&work[0x892] = 122;
        break;
    case 2:
        LoadPalette(gUnk_096142F8, (void*)0x05000140, 32);
        LoadPalette(&gUnk_09614118[0x100], (void*)0x05000100, 32);
        LoadPalette(&gUnk_09614118[0x120], (void*)0x05000120, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, &gUnk_0951AAB8[0x180], 0x180);
        SetBgScroll(0, 0xFFA8, 0xFFF0);
        SetBgScroll(1, 0xFFA8, 0xFFC0);
        SetBgScroll(2, 0xFFB4, 0xFF92);
        *(u16*)&work[0x888] = 102;
        *(u16*)&work[0x88E] = 27;
        *(u16*)&work[0x88A] = 102;
        *(u16*)&work[0x890] = 75;
        *(u16*)&work[0x88C] = 100;
        *(u16*)&work[0x892] = 121;
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808CDE8.s");
#endif

void func_0808D0A4(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = func_08085B38(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
#ifdef VERSION_EU
        base = GetBgCharBase(0) + 0x2BE0;
#else
        base = GetBgCharBase(0);
#endif
        break;
    case 1:
#ifdef VERSION_EU
        base = GetBgCharBase(1) + 0x2F40;
#else
        base = GetBgCharBase(1);
#endif
        break;
    case 2:
#ifdef VERSION_EU
        base = GetBgCharBase(2) + 0x32A0;
#else
        base = GetBgCharBase(2);
#endif
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
}

#ifndef VERSION_EU
void func_0808D16C(u8 mode) {
    u32 bg0;
    u32 bg1;
    u32 bg2;

    bg0 = GetBgCharBase(0);
    bg1 = GetBgCharBase(1);
    bg2 = GetBgCharBase(2);

    switch (mode) {
    case 0:
        RequestDma3Copy(gUnk_0940FC58, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 2:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808D16C.s");
#endif

void func_0808D258(u8 mode) {
    u8 d1[4];
    u8 d2[4];
    u16 v;

    u32 base;

    base = 0;
    v = func_08085770(mode);

    d1[0] = v / 1000;
    d1[1] = v / 100 - d1[0] * 10;
    d1[2] = v / 10 - d1[0] * 100 - d1[1] * 10;
    d1[3] = v - d1[0] * 1000 - d1[1] * 100 - d1[2] * 10;
    d2[0] = gGameState.cp / 1000;
    d2[1] = gGameState.cp / 100 - d2[0] * 10;
    d2[2] = gGameState.cp / 10 - d2[0] * 100 - d2[1] * 10;
    d2[3] = gGameState.cp - d2[0] * 1000 - d2[1] * 100 - d2[2] * 10;

    switch (mode) {
    case 0:
#ifdef VERSION_EU
        base = GetBgCharBase(0) + 0x2BE0;
#else
        base = GetBgCharBase(0);
#endif
        break;
    case 1:
#ifdef VERSION_EU
        base = GetBgCharBase(1) + 0x2F40;
#else
        base = GetBgCharBase(1);
#endif
        break;
    case 2:
#ifdef VERSION_EU
        base = GetBgCharBase(2) + 0x32A0;
#else
        base = GetBgCharBase(2);
#endif
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0xA0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0xC0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0xE0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[3] + 1) * 32], (void*)(base + 0x100), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x120), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x140), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x160), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[3] + 1) * 32], (void*)(base + 0x180), 32);
}

#ifndef VERSION_EU
void func_0808D438(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0x80;

    switch (kind) {
    case 0:
        RequestDma3Copy(gUnk_095152B8 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_095152CC + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_095152E0 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_09515338 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_0951534C + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808D438.s");
#endif

#ifndef VERSION_EU
void func_0808D4E4(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0xA8;

    switch (kind) {
    case 5:
        RequestDma3Copy(gUnk_095152B8 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_095152CC + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_095152E0 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_09515338 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_0951534C + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    }
}
#else
INCLUDE_ASM("card/func_0808D4E4.s");
#endif

void func_0808D594(void) {
    u8 d1[3];
    u8 d2[3];
    u16 a;
    u16 b;

    u32 base;

    a = func_08084BF0();
    b = func_08084BAC();

    d1[0] = a / 100;
    d1[1] = a / 10 - d1[0] * 10;
    d1[2] = a - d1[0] * 100 - d1[1] * 10;
    d2[0] = b / 100;
    d2[1] = b / 10 - d2[0] * 10;
    d2[2] = b - d2[0] * 100 - d2[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_0808D6C4(u8* work) {
    func_08065ACC(&work[0x38], 8);
    func_08065ACC(&work[0x78], 8);
    func_08065ACC(&work[0xB8], 8);
#ifdef VERSION_EU
    work[0x8C6] = func_08065B6C(func_080857BC(0), &work[0x38]);
    work[0x8C7] = func_08065B6C(func_080857BC(1), &work[0x78]);
    work[0x8C8] = func_08065B6C(func_080857BC(2), &work[0xB8]);
#else
    work[0x8C2] = func_08065B6C(func_080857BC(0), &work[0x38]);
    work[0x8C3] = func_08065B6C(func_080857BC(1), &work[0x78]);
    work[0x8C4] = func_08065B6C(func_080857BC(2), &work[0xB8]);
#endif
}

void func_0808D73C(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
#ifdef VERSION_EU
    work[CARDWORK(0x8C5)] = func_08065B6C(eu_0805E924(def->unk_0C), &work[0xF8]);
#else
    work[0x8C5] = func_08065B6C(def->unk_0C, &work[0xF8]);
#endif

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->unk_08 << 5));
        break;
    }
}

void func_0808D7EC(u8* work, u16 index) {
    CardDef* d;
    void* s;

    d = &gCardDefs[index];
    s = gUnk_09EE8F48[d->unk_1C];
    work[CARDWORK(0x8C6)] = func_08065B6C(LANGSTR(s), &work[0x1E8]);
}

#ifdef NON_MATCHING
s32 func_0808D828(u8* work) {
    UnkStruct_0808E890* t;
    CardDef* def;
    u16 id;
    u16 flag;
    u16 v;
    u8 i;
    u8 j;
    u16 k;

    id = 0xFFFF;
    t = ListPoolFirst(&work[0x7F0]);

    while (t != 0) {
        if (t->unk_24 == *(s16*)&work[0x886] &&
            t->unk_22 == *(s16*)&work[0x884]) {
            id = t->unk_20;
            break;
        }

        t = ListPoolNext(&t->unk_2C);
    }

    func_0808DB04((void**)work);

    if (id != 0xFFFF) {
    flag = id & 0x8000;

    if (flag != 0) {
        *(void**)&work[0x28] = AllocObjTiles(0x280, 0);
        func_08002A10(*(void**)&work[0x28], gUnk_0908B1B4);
        AnimInit((AnimState*)&work[0x830], gUnk_09EEA164, gUnk_09EEA148);
        AnimStart((AnimState*)&work[0x830], 0, 1);
        *(void**)&work[0x4F8] = AnimGetGfx((AnimState*)&work[0x830]);
    }

    def = &gCardDefs[id & 0xFFF];
    *(void**)&work[0x1C] = LoadObjTiles(gUnk_08F709B0[def->unk_2A].unk_0C, 0x300);
    *(void**)&work[0x20] = LoadObjTiles(def->unk_04, 0x200);
    *(void**)&work[0x34] = LoadObjPalette(def->unk_08, 32);
    *(void**)&work[0x30] = LoadObjPalette(gUnk_09611AB8, 32);
    *(void**)&work[0x4DC] = gUnk_08F709B0[def->unk_2A].unk_00;
    *(void**)&work[0x4E0] = def->unk_00;

    for (i = 0; i < *(u16*)&work[0x898]; i++) {
        if (flag != 0) {
            if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] ==
                def->unk_1C + 143) {
                break;
            }
        } else {
            if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] ==
                def->unk_1C) {
                break;
            }
        }
    }

    *(u16*)&work[0x880] = i;
    LoadPalette(&gUnk_09614318[def->unk_2A * 32], gUnk_05000160, 32);

    for (j = 0; j <= 9; j++) {
        func_0808DD20((u8)(*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[j], j);
    }

    v = id & 0xFFF;
    func_0808D73C(work, v);
    func_0808D7EC(work, v);

    if (work[0x8B1] >= 9 && work[0x8B1] <= 12) {
        if (def->unk_1C > 46) {
            LoadBgMap(2, gUnk_09518AB8, 0x800);
            func_0808DE28((u8)func_080609AC(id));
            return id;
        }

        LoadBgMap(2, gUnk_095182B8, 0x800);
    } else if (def->unk_1C > 46) {
        switch (work[0x8C0]) {
        case 0:
            LoadBgMap(1, gUnk_09518AB8, 0x800);
            break;
        case 1:
        case 2:
            LoadBgMap(0, gUnk_09518AB8, 0x800);
            break;
        }
    } else {
        switch (work[0x8C0]) {
        case 0:
            LoadBgMap(1, gUnk_095182B8, 0x800);
            break;
        case 1:
        case 2:
            LoadBgMap(0, gUnk_095182B8, 0x800);
            break;
        }
    }

    func_0808DE28(0);
    } else {
        for (k = 0; k <= 9; k++) {
            func_0808DD20(0, k);
        }

        func_0808DE28(0);
    }

    return id;
}
#else
INCLUDE_ASM("card/func_0808D828.s");
#endif

void func_0808DB04(void** p) {
    if (p[10] != 0) {
        ReleaseObjTiles(p[10]);
        p[10] = 0;
    }

    if (p[7] != 0) {
        ReleaseObjTiles(p[7]);
        ReleaseObjPalette(p[12]);
        ReleaseObjTiles(p[8]);
        ReleaseObjPalette(p[13]);

        if (p[9] != 0) {
            ReleaseObjTiles(p[9]);
            p[9] = 0;
        }

        p[7] = 0;
        p[12] = 0;
        p[8] = 0;
        p[13] = 0;
    }
}

void func_0808DB50(UnkStruct_0808DB04* w) {
    UnkStruct_0808E890* node;
    CardDef* def;
    void* dst;
    u16 id;

    id = 0xFFFF;
    node = ListPoolFirst(w->unk_7F0);

    while (node != 0) {
        if (node->unk_24 == (s16)w->unk_886 && node->unk_22 == w->unk_884) {
            id = node->unk_20;
            break;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    func_0808DB04((void**)w);

    if (id != 0xFFFF) {
        if (id & 0x8000) {
            w->unk_028 = AllocObjTiles(0x280, 0);
            func_08002A10(w->unk_028, gUnk_0908B1B4);
            AnimInit(&w->anim, gUnk_09EEA164, gUnk_09EEA148);
            AnimStart(&w->anim, 0, 1);
            w->gfx = AnimGetGfx(&w->anim);
        }

        def = &gCardDefs[id & CARD_ID_MASK];
        w->unk_01C = LoadObjTiles(gUnk_08F709B0[def->unk_2A].unk_0C, 768);
        w->unk_020 = LoadObjTiles(def->unk_04, 512);
        w->unk_034 = LoadObjPalette(def->unk_08, 32);
        w->unk_030 = LoadObjPalette(gUnk_09611AB8, 32);
        w->unk_4DC = gUnk_08F709B0[def->unk_2A].unk_00;
        w->unk_4E0 = def->unk_00;

        if ((id & CARD_ID_MASK) <= 0x1C1) {
            w->unk_024 = LoadObjTiles(gUnk_0905EAE8, 480);
            w->unk_4E4 = gUnk_09EE981C[def->unk_20];
        }

        func_0808DE28(func_080609AC(id));
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614118[def->unk_2A * 32 + 0x200], dst, 32);
        func_0808D73C((u8*)w, id & CARD_ID_MASK);
        func_0808D7EC((u8*)w, id & CARD_ID_MASK);
    } else {
        func_0808DE28(0);
    }
}

#ifdef NON_MATCHING
void func_0808DD20(u8 a, u16 b) {
    u8 v[2];
    u32 base;
    u8* dst;

    base = GetBgCharBase(3);

    if (a != 0) {
        v[0] = a / 10;
        v[1] = a - v[0] * 10;
        dst = (u8*)(base + b * 64 + 0xD20);
        RequestDma3Copy(&gUnk_0940FA98[(v[0] + 3) * 32], dst, 32);
        dst += 32;
        RequestDma3Copy(&gUnk_0940FA98[(v[1] + 3) * 32], dst, 32);
    } else {
        dst = (u8*)(base + b * 64 + 0xD20);
        RequestDma3Copy(gUnk_0940FAD8, dst, 32);
        dst += 32;
        RequestDma3Copy(gUnk_0940FAD8, dst, 32);
        LoadPalette(gUnk_09614406, (void*)(b * 2 + 0x0500016C), 2);
    }
}
#else
INCLUDE_ASM("card/func_0808DD20.s");
#endif

void func_0808DDD0(u8* work) {
    u16 t;

    t = func_0808C8D0(*(u16*)(*(u16*)&work[CARDWORK(0x880)] * 32 +
                              (u32)*(void**)&work[0x4D4] + 20));
    func_0808DE28(func_080609AC(t + *(s16*)&work[CARDWORK(0x884)] * 5 +
                                *(u16*)&work[CARDWORK(0x886)]));
}

void func_0808DE28(u8 a) {
    u8 d[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        d[0] = a / 10;
        d[1] = a - d[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(d[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(d[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}

u32 func_0808DEB8(u16* data) {
    u32 sum;
    u16* p;
    s32 i;

    sum = 0;
    p = data;
    i = 9;

    do {
        sum += *p++;
    } while (--i >= 0);

    return sum;
}

#ifdef NON_MATCHING
s32 func_0808DED0(u8* work, u16 keys) {
    UnkStruct_0808E2F0* p;
    u8 y0;
    u8 x0;
    u8 idx;
    s8 v;
    s8 d;
    s32 i;
    s32 sum;
    u16 t;
    u16 t884;

    p = &(*(UnkStruct_0808E2F0**)&work[0x4D4])[*(u16*)&work[0x880]];
    t884 = *(u16*)&work[0x884];
    y0 = work[0x884];
    x0 = work[0x886];

    if (p->unk_00[(u8)(*(s16*)&work[0x884] * 5 + work[0x886])] != 0) {
        return 1;
    }

    switch (keys) {
    case 64:
        do {
            t = *(u16*)&work[0x886];
            *(u16*)&work[0x886] = (s16)t > 0 ? t - 1 : 4;
            idx = *(s16*)&work[0x884] * 5 + work[0x886];

            if (*(s16*)&work[0x884] == y0 && *(s16*)&work[0x886] == x0) {
                return 0;
            }
        } while (p->unk_00[idx] == 0);
        break;
    case 128:
        do {
            t = *(u16*)&work[0x886];
            *(u16*)&work[0x886] = (s16)t <= 3 ? t + 1 : 0;
            idx = *(s16*)&work[0x884] * 5 + work[0x886];

            if (*(s16*)&work[0x884] == y0 && *(s16*)&work[0x886] == x0) {
                return 0;
            }
        } while (p->unk_00[idx] == 0);
        break;
    case 32:
        if (p->unk_00[*(s16*)&work[0x886]] != 0) {
            if ((s16)t884 > 0) {
                *(u16*)&work[0x884] = t884 - 1;
            }

            break;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += p->unk_00[i];
        }

        if (sum == 0) {
            *(u16*)&work[0x884] = 1;
            return 0;
        }

        d = -1;
        v = d + work[0x886];

        while (1) {
            if (v < 0) {
                v = 0;
            }

            if (v > 4) {
                v = 4;
            }

            if (p->unk_00[v] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d = d + 1;
                d = -d;
            }

            v = d + work[0x886];
        }

        *(u16*)&work[0x886] = v;
        break;
    case 16:
        if (p->unk_00[*(s16*)&work[0x886] + 5] != 0) {
            if ((s16)t884 <= 0) {
                *(u16*)&work[0x884] = t884 + 1;
            }

            break;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += p->unk_00[i + 5];
        }

        if (sum == 0) {
            *(u16*)&work[0x884] = 0;
            return 0;
        }

        d = -1;
        v = d + work[0x886];

        while (1) {
            if (v < 0) {
                v = 0;
            }

            if (v > 4) {
                v = 4;
            }

            if (p->unk_00[v + 5] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d = d + 1;
                d = -d;
            }

            v = d + work[0x886];
        }

        *(u16*)&work[0x886] = v;
        break;
    case 0:
        do {
            t = *(u16*)&work[0x886];

            if ((s16)t <= 3) {
                *(u16*)&work[0x886] = t + 1;
            } else {
                *(u16*)&work[0x886] = 0;
            }

            if (*(s16*)&work[0x884] == y0 && *(s16*)&work[0x886] == x0) {
                t = *(u16*)&work[0x884];

                if ((s16)t <= 0) {
                    *(u16*)&work[0x884] = t + 1;
                } else {
                    *(u16*)&work[0x884] = 0;
                }

                *(u16*)&work[0x886] = 0;

                if (func_0808DEB8(p->unk_00) == 0) {
                    return 0;
                }
            }
        } while (p->unk_00[(u8)(*(s16*)&work[0x884] * 5 + work[0x886])] == 0);
        break;
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0808DED0.s");
#endif
s32 func_0808E19C(UnkStruct_0808DB04* w) {
    u16 mask;
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 card;
    u16 v;
    u32 id;
    CardDef* def;

    mask = 0;
    idx = w->unk_884 * 5 + w->unk_886;

    switch (w->unk_8C0) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    }

    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(0x69);
        return 0;
    }

    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];
        v = gCardCollection[card];

        if (!(mask & v)) {
            id = v & 0xFFF;
            def = &gCardDefs[id];

            if (id > 0x1C1) {
                if (idx == 0) {
                    func_08085374(card, w->unk_8C0);
                    e->unk_00[idx]--;
                    func_0808DD20(e->unk_00[idx], idx);
                    m4aSongNumStart(0x66);
                    return e->unk_00[idx];
                }
            } else if (def->unk_20 == idx) {
                func_08085374(card, w->unk_8C0);
                e->unk_00[idx]--;
                func_0808DD20(e->unk_00[idx], idx);
                m4aSongNumStart(0x66);
                return e->unk_00[idx];
            }
        }
    }

    m4aSongNumStart(0x69);
}

void func_0808E2F0(UnkStruct_0808DB04* w) {
    u16 i;

    if (w->unk_4D4 != 0) {
        for (i = 0; i < w->unk_898; i++) {
            EwramFree(w->unk_4D4[i].unk_1C);
        }

        EwramFree(w->unk_4D4);
        w->unk_4D4 = 0;
    }
}

void func_0808E344(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}

void func_0808E364(u8* work, u8 kind) {
    switch (kind) {
    case 0:
        func_08002A10(*(void**)&work[4], gUnk_090A4A0C);
#ifdef VERSION_EU
        AnimInit(&work[0x81C], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x81C], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x81C]);
#else
        AnimInit(&work[0x818], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x818], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x818]);
#endif
        break;
    case 1:
        func_08002A10(*(void**)&work[4], gUnk_090A51F6);
#ifdef VERSION_EU
        AnimInit(&work[0x81C], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x81C], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x81C]);
#else
        AnimInit(&work[0x818], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x818], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x818]);
#endif
        break;
    }
}

void func_0808E3E0(u8* work) {
    UnkStruct_0808E890* n;

    n = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (n != 0) {
        if (n->unk_24 == *(s16*)&work[CARDWORK(0x886)] && n->unk_22 == *(s16*)&work[CARDWORK(0x884)]) {
            if (n->unk_20 != 0xFFFF) {
                func_08085518(n->unk_28, work[CARDWORK(0x8C0)]);
                n->unk_4A = 1;
                ((UnkStruct_0808E3E0*)n)->unk_24 |= 0xFFFF;
                m4aSongNumStart(0x66);
            } else {
                m4aSongNumStart(0x69);
            }

            return;
        }

        n = ListPoolNext(&n->unk_2C);
    }

    m4aSongNumStart(0x69);
}
u8 func_0808E474(UnkStruct_0808DB04* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 id;
    u16 c;
    CardDef* def;

    idx = w->unk_884 * 5 + w->unk_886;
    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(0x69);
        return 1;
    }

    for (i = 0; i < e->unk_16; i++) {
        id = e->unk_1C[i];

        if (id == 0xFFFF) {
            continue;
        }

        c = gCardCollection[id] & CARD_ID_MASK;
        def = &gCardDefs[c];

        if (c > 0x1C2) {
            if (idx != 0) {
                continue;
            }

            if (def->unk_2A != 0) {
                return 1;
            }

            if (func_08084FAC(def->unk_2A) > 1) {
                return 1;
            }

            TaskCreate(&w->unk_7DC, gUnk_09EE7FD8, &w->unk_888[0x41]);
            m4aSongNumStart(0x69);
            return 0;
        } else {
            if (def->unk_20 != idx) {
                continue;
            }

            if (def->unk_2A != 0) {
                return 1;
            }

            if (func_08084FAC(def->unk_2A) > 1) {
                return 1;
            }

            TaskCreate(&w->unk_7DC, gUnk_09EE7FD8, &w->unk_888[0x41]);
            m4aSongNumStart(0x69);
            return 0;
        }
    }

    return 1;
}
#ifdef NON_MATCHING
u8 func_0808E58C(UnkStruct_0808DB04* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 card;
    u16 id;
    CardDef* def;

    idx = w->unk_884 * 5 + w->unk_886;
    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(0x69);
        return 1;
    }

    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];

        if (card != 0xFFFF) {
            id = gCardCollection[card] & CARD_ID_MASK;
            def = &gCardDefs[id];

            if (id >= 0x1C2) {
                if (idx == 0) {
                    if (def->unk_2A != 0) {
                        func_080850B0(&gCardCollection[card]);
                        e->unk_1C[i] = 0xFFFF;
                        e->unk_00[idx]--;
                        func_0808DD20(e->unk_00[idx], idx);
                        m4aSongNumStart(0x8A);
                        return 1;
                    }

                    if (func_08084FAC(def->unk_2A) > 1) {
                        func_080850B0(&gCardCollection[card]);
                        e->unk_1C[i] = 0xFFFF;
                        e->unk_00[idx]--;
                        func_0808DD20(e->unk_00[idx], idx);
                        m4aSongNumStart(0x8A);
                        return 1;
                    }

                    TaskCreate(&w->unk_7DC, gUnk_09EE7FD8, &w->unk_888[0x41]);
                    m4aSongNumStart(0x69);
                    return 0;
                }
            } else if (def->unk_20 == idx) {
                if (def->unk_2A != 0) {
                    func_080850B0(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[idx]--;
                    func_0808DD20(e->unk_00[idx], idx);
                    m4aSongNumStart(0x8A);
                    return 1;
                }

                if (func_08084FAC(def->unk_2A) > 1) {
                    func_080850B0(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[idx]--;
                    func_0808DD20(e->unk_00[idx], idx);
                    m4aSongNumStart(0x8A);
                    return 1;
                }

                TaskCreate(&w->unk_7DC, gUnk_09EE7FD8, &w->unk_888[0x41]);
                m4aSongNumStart(0x69);
                return 0;
            }
        }
    }

    m4aSongNumStart(0x69);
    return 1;
}
#else
INCLUDE_ASM("card/func_0808E58C.s");
#endif

s32 func_0808E750(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gGameState.cp) {
#ifdef VERSION_EU
        TaskCreate(&work[0x7E0], gUnk_09EE7FA8, &work[0x8CD]);
#else
        TaskCreate(&work[0x7DC], gUnk_09EE7FA8, &work[0x8C9]);
#endif
        m4aSongNumStart(105);

        return 0;
    }

    return 1;
}

s32 func_0808E79C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(105);
#ifdef VERSION_EU
        TaskCreate(&work[0x7E0], gUnk_09EE7FC0, &work[0x8CD]);
#else
        TaskCreate(&work[0x7DC], gUnk_09EE7FC0, &work[0x8C9]);
#endif

        return 0;
    }

    return 1;
}

void func_0808E7D8(u8* work) {
#ifdef VERSION_EU
    UnkStruct_0808E890* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x7F4]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (node->unk_48 & 1) {
            ReleaseObjPalette(node->unk_04);
            ReleaseObjTiles(node->unk_08);
            ReleaseObjPalette(node->unk_0C);
            ReleaseObjTiles(node->unk_10);
            node->unk_48 &= ~1;
            node->unk_08 = 0;
            node->unk_0C = 0;
            node->unk_10 = 0;
            node->unk_04 = 0;
        }

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    *(s32*)&work[0x858] = 0x2800;
    *(u16*)&work[0x8B0] = 4;
#else
    UnkStruct_0808E890* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x7F0]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (node->unk_48 & 1) {
            ReleaseObjPalette(node->unk_04);
            ReleaseObjTiles(node->unk_08);
            ReleaseObjPalette(node->unk_0C);
            ReleaseObjTiles(node->unk_10);
            node->unk_48 &= ~1;
            node->unk_08 = 0;
            node->unk_0C = 0;
            node->unk_10 = 0;
            node->unk_04 = 0;
        }

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    *(s32*)&work[0x854] = 0x2800;
    *(u16*)&work[0x8AC] = 4;
#endif
}

s32 func_0808E890(u8* work) {
    UnkStruct_0808E890* t;

    t = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (t != 0) {
        if (t->unk_22 == *(s16*)&work[CARDWORK(0x884)]) {
            if (t->unk_24 == *(s16*)&work[CARDWORK(0x886)]) {
                return 1;
            }
        }

        t = ListPoolNext(&t->unk_2C);
    }

    return 0;
}

u8 func_0808E8E8(u8* work, u16 a, u16 b) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (node != 0) {
        if (node->unk_22 == (s16)a && node->unk_24 == (s16)b) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

u8 func_0808E934(u8* work, s16 x, s16 y, u16 dir) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    switch (dir) {
    case 0x40:
        return func_0808E934(work, x, y - 1, 0x40);
    case 0x80:
        return func_0808E934(work, x, y + 1, 0x80);
    case 0x20:
        return func_0808E934(work, x - 1, y, 0x20);
    case 0x10:
        return func_0808E934(work, x + 1, y, 0x10);
    }

    return 0;
}

INCLUDE_ASM("card/func_0808EA0C.s");
INCLUDE_ASM("card/func_0808EC24.s");
u8 func_0808EDA4(UnkStruct_0808DB04* w) {
    UnkStruct_0808E890* p;
    UnkStruct_0808E890* q;
    UnkStruct_0808E890* n;
    UnkStruct_0808E890* prev;
    u16* a;
    u16* b;
    s16 x;
    s16 y;
    u16 u;
    u16 v;
    s32 pos;

    p = ListPoolFirst(w->unk_7F0);
    q = ListPoolFirst(w->unk_7F0);
    pos = *(s32*)&w->unk_884;

    if (pos == *(s32*)&w->unk_874) {
        return func_0808EC24((u8*)w);
    }

    while (p != 0) {
        if (w->unk_884 == p->unk_22 && (s16)w->unk_886 == p->unk_24) {
            break;
        }

        p = ListPoolNext(&p->unk_2C);
    }

    if (p == 0) {
        return 0;
    }

    while (q != 0) {
        if (w->unk_874 == q->unk_22 && w->unk_876 == q->unk_24) {
            break;
        }

        q = ListPoolNext(&q->unk_2C);
    }

    x = p->unk_22;
    y = p->unk_24;
    p->unk_22 = q->unk_22;
    p->unk_24 = q->unk_24;
    q->unk_22 = x;
    q->unk_24 = y;
    a = p->unk_28;
    u = *a;
    b = q->unk_28;
    v = *b;
    *a = v;
    *b = u;
    p->unk_28 = b;
    q->unk_28 = a;

    if (ListPoolPrev(&p->unk_2C) == (MapcardWork*)q) {
        func_08000D90(&p->unk_2C, w->unk_7F0);
        func_08000D6C(&p->unk_2C, w->unk_7F0, &q->unk_2C);

        for (n = ListPoolFirst(w->unk_7F0); n != 0; n = ListPoolNext(&n->unk_2C)) {
            if (n == ListPoolNext(&n->unk_2C)) {
                break;
            }
        }
    } else if (ListPoolNext(&p->unk_2C) == q) {
        func_08000D90(&p->unk_2C, w->unk_7F0);
        func_08000D48(&p->unk_2C, w->unk_7F0, &q->unk_2C);

        for (n = ListPoolFirst(w->unk_7F0); n != 0; n = ListPoolNext(&n->unk_2C)) {
            if (n == ListPoolNext(&n->unk_2C)) {
                break;
            }
        }
    } else {
        prev = (UnkStruct_0808E890*)func_08000D90(&p->unk_2C, w->unk_7F0);
        func_08000D6C(&p->unk_2C, w->unk_7F0, &q->unk_2C);
        func_08000D90(&q->unk_2C, w->unk_7F0);

        if (prev == 0) {
            func_08000D28(&q->unk_2C, w->unk_7F0);
        } else {
            func_08000D6C(&q->unk_2C, w->unk_7F0, &prev->unk_2C);
        }
    }

    return 1;
}

u8 func_0808EF80(u8* work, u16 dir) {
    u16 row;
    u16 row2;

    row = *(u16*)&work[0x7C2];

    if ((s16)row == 3 && *(u16*)&work[0x7C0] > 9) {
        switch (dir) {
        case 0x40:
            *(u16*)&work[0x7C2] = row - 1;
            break;
        case 0x80:
            *(u16*)&work[0x7C2] = row + 1;
            break;
        case 0x20:
            *(u16*)&work[0x7C0] = 9;
            break;
        case 0x10:
            *(u16*)&work[0x7C0] = 0;
            break;
        }
    }

    if (work[0x7C7] == 0) {
        row2 = *(u16*)&work[0x7C2];

        if ((s16)row2 == 5 && (u16)(*(u16*)&work[0x7C0] - 5) <= 4) {
            switch (dir) {
            case 0x40:
                *(u16*)&work[0x7C2] = row2 - 1;
                break;
            case 0x80:
                *(u16*)&work[0x7C2] = row2 + 1;
                break;
            case 0x20:
                *(u16*)&work[0x7C0] = 4;
                break;
            case 0x10:
                *(u16*)&work[0x7C0] = 10;
                break;
            }
        }
    }

    if (*(s16*)&work[0x7C2] > 6) {
        *(s16*)&work[0x7C2] = 0;
    }

    if (*(s16*)&work[0x7C2] < 0) {
        *(s16*)&work[0x7C2] = 6;
    }

    if (*(s16*)&work[0x7C0] > 14) {
        *(s16*)&work[0x7C0] = 0;
    }

    if (*(s16*)&work[0x7C0] < 0) {
        *(s16*)&work[0x7C0] = 14;
    }

    if (*(s16*)&work[0x7C2] == 6 && *(s16*)&work[0x7C0] > 11) {
        if (*(s16*)&work[0x7C0] == 13 && dir == 0x20) {
            *(s16*)&work[0x7C0] = 11;
            AnimStart(&work[0x798], 0, 1);
        } else {
            *(s16*)&work[0x7C0] = 14;
            AnimStart(&work[0x798], 1, 1);
        }

        return 0;
    }

    return 1;
}

INCLUDE_ASM("card/func_0808F0C0.s");
void func_0808F258(u8 a) {
    u32 base;

    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_09417378[a * 64], (void*)(base + 32), 64);
}
void func_0808F284(u8* work) {
    u8* s;
    u8* d;
    s32 i;

#ifdef VERSION_EU
    s = func_080857BC(work[0x8C4]);
#else
    s = func_080857BC(work[0x8C0]);
#endif

    for (i = 0; i <= 19; i++) {
        d = &work[0x784];
        d[i] = s[i];
    }

    work[0x796] = 0;
    work[0x797] = 0;
}
void func_0808F2CC(u8* work) {
    u8* d;
    u8* s;
    s32 i;

    d = func_080857BC(work[CARDWORK(0x8C0)]);

    for (i = 0; i <= 19; i++) {
        s = &work[0x784];
        d[i] = s[i];
    }

    d[18] = 0;
    d[19] = 0;
}

#ifndef VERSION_EU
void func_0808F304(u8* work) {
    u8* p;
    s32 t;
    u8 i;

    if (work[0x7C4] == 0) {
        m4aSongNumStart(105);
        return;
    }

    for (i = work[0x7C4] - 1; i <= 8; i++) {
        p = &work[0x784];
        t = i * 2;
        p[t] = 0;
        t++;
        p[t] = 0;
    }

    m4aSongNumStart(104);
}
#else
INCLUDE_ASM("card/func_0808F304.s");
#endif

#ifdef VERSION_US
s32 func_0808F358(UnkStruct_0808F358* work) {
    u8* src;
    u8* dst;
    s32 offset;
    s32 zero;
    s32 offset2;
    u8 value;
    u8* out;

    if (work->unk_7C4 <= 7) {
        m4aSongNumStart(102);
        src = gUnk_09EE4B0C[work->unk_7C2];
        offset = work->unk_7C4 * 2;
        dst = work->unk_784;
        out = &dst[offset];
        value = src[work->unk_7C0 * 2];
        zero = 0;
        *out = value;
        offset2 = work->unk_7C4 * 2;
        offset2++;
        dst[offset2] = src[work->unk_7C0 * 2 + 1];
        offset = (work->unk_7C4 + 1) * 2;
        dst[offset] = zero;
        offset = (work->unk_7C4 + 1) * 2;
        offset++;
        dst[offset] = zero;
        return 1;
    } else {
        m4aSongNumStart(105);
        return 0;
    }
}
#else
INCLUDE_ASM("card/func_0808F358.s");
#endif
INCLUDE_ASM("card/func_0808F3E8.s");
INCLUDE_ASM("card/func_0808F660.s");

u8 func_0808FA0C(u8* work, void* a) {
    func_08006120(0, 16);
    work[CARDWORK(0x8B1)] = 0;
    func_0808E364(work, 0);
    func_0808CD48(work);
    func_08065AE0(&work[0x744], 8);
    ReleaseObjTiles(*(void**)&work[0x738]);
    ReleaseObjTiles(*(void**)&work[0x73C]);
    ReleaseObjPalette(*(void**)&work[0x740]);
    work[CARDWORK(0x8D0)] = 0;
    SetTaskUpdate(a, (void*)func_080864A4);
    func_0808C3DC(work, 0);
#ifdef VERSION_EU
    {
        u8* p;
        u8 n;

        p = &work[CARDWORK(0x8B0)];
        n = 1;
        *p = n;
        return n;
    }
#else
    return 1;
#endif
}

INCLUDE_ASM("card/func_0808FA8C.s");
void DeckCard2_0(UnkStruct_0808E890* n, UnkStruct_080A6838_Args* a) {
    *(UnkStruct_080A6838_Args*)&n->unk_1C = *a;
    n->unk_08 = 0;
    n->unk_0C = 0;
    n->unk_10 = 0;
    n->unk_04 = 0;
    n->unk_48 = 0;

    switch (n->unk_26) {
    case 0:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = gUnk_09035956[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    case 1:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = gUnk_09035964[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    }

    if (n->unk_20 != 0xFFFF) {
        if (!(n->unk_20 & 0x8000)) {
            n->unk_4D = 0;
        } else {
            n->unk_4D = 1;
        }

        n->unk_14 = &gCardDefs[n->unk_20 & 0xFFF];

        if (n->unk_14->unk_1E & 0xC) {
            n->unk_18 = &gUnk_08F709B0[3];
        } else {
            n->unk_18 = &gUnk_08F709B0[n->unk_14->unk_2A];
        }
    }

    n->unk_4A = 0;
    func_08000D20(n->unk_2C, n->unk_1C, n);
    func_08000D28(n->unk_2C, n->unk_1C);
}

u8 DeckCard2_1(UnkStruct_0808E890* n) {
    if (n->unk_4A == 1) {
        return 0;
    }

    switch (n->unk_26) {
    case 0:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = gUnk_09035956[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_09035950[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    case 1:
        if ((u16)n->unk_24 <= 3) {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = gUnk_09035964[n->unk_24] << 8;
        } else {
            n->unk_40 = gUnk_0903595E[n->unk_22] << 8;
            n->unk_44 = 0x20000;
        }
        break;
    }

    if (func_080901B8((u8*)n)) {
        func_08090100(n);
    } else {
        func_08090170(n);
    }
}

void DeckCard2_2(UnkStruct_0808E890* n) {
    if (!(n->unk_48 & 1)) {
        return;
    }

    if (n->unk_08 != 0 && n->unk_0C != 0) {
        DrawSprite(n->unk_40 >> 8, n->unk_44 >> 8, n->unk_14->unk_10, n->unk_08, n->unk_0C, 0, 0, 0x33);

        if (n->unk_4D != 0) {
            DrawSprite(n->unk_40 >> 8, n->unk_44 >> 8, gUnk_0203A860[8], gUnk_0203A860[0], gUnk_0203A860[1], 0, 0, 0x28);
        }
    }

    if (n->unk_26 == 0 && n->unk_14->unk_2A != 3) {
        DrawSprite((n->unk_40 >> 8) - 3, (n->unk_44 >> 8) - 4, gUnk_09EE981C[n->unk_14->unk_20], n->unk_10, n->unk_04, 0, 0, 0x31);
    }
}

void DeckCard2_3(u8* p) {
    func_08090170((UnkStruct_0808E890*)p);
    func_08000D90(&p[0x2C], *(void**)&p[0x1C]);
}

void func_08090100(UnkStruct_0808E890* n) {
    if (n->unk_20 == 0xFFFF) {
        return;
    }

    if (n->unk_48 & 1) {
        return;
    }

    n->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    n->unk_08 = LoadObjTiles(n->unk_14->unk_14, 0x200);
    n->unk_0C = LoadObjPalette(n->unk_14->unk_18, 32);
    n->unk_10 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);

    if (n->unk_08 != 0 && n->unk_0C != 0) {
        n->unk_48 |= 1;
    }
}

void func_08090170(UnkStruct_0808E890* node) {
    if (node->unk_48 & 1) {
        ReleaseObjPalette(node->unk_04);
        ReleaseObjTiles(node->unk_08);
        ReleaseObjPalette(node->unk_0C);
        ReleaseObjTiles(node->unk_10);
        node->unk_48 &= 0xFFFE;
        node->unk_08 = 0;
        node->unk_0C = 0;
        node->unk_10 = 0;
        node->unk_04 = 0;
    }
}

u8 func_080901B8(u8* p) {
    s16 a;
    s16 b;

    a = *(s32*)&p[0x40] >> 8;
    b = *(s32*)&p[0x44] >> 8;

    if (a < 0) {
        return 0;
    }

    if (a > 240) {
        return 0;
    }

    if (b < 0) {
        return 0;
    }

    if (b > 160) {
        return 0;
    }

    return 1;
}
void func_080901E0(s32* a, u8* b, u8 c) {
    s32* t;
    s32 v;
    s32 id;

    t = (s32*)a[1];
    v = a[2];

    if (v != -1) {
        *(u16*)&b[0x14] = v;
    }

    if (t != 0) {
        id = *(s32*)((u8*)t + c * 12);

        if (id != 0xFFFF) {
            *(CardDef**)&b[0x00] = &gCardDefs[id];
        }
    }
}
void func_08090224(u8* p) {
    u8* q;

    q = &p[0x64];
    func_08000D20(q, *(void**)&p[0x38], p);
    func_08000D28(q, *(void**)&p[0x38]);
}

void card_enemy_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->palette = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 0x50;
    p->unk_9C = 0;
    func_080901E0((s32*)&p->unk_38, (u8*)&p->unk_48, ((UnkStruct_08090244*)&p->unk_38)->unk_0C);
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_8C = gUnk_09035978[0];
    p->unk_90 = gUnk_09035978[1];
    p->unk_4C = 0xDC00;
    p->unk_50 = 0x8400;
    p->unk_A5 = p->unk_48->unk_20;
    func_08090224((u8*)p);
}

u8 card_enemy_1(UnkStruct_02034AAC* p, void* a) {
    if (!(p->unk_78 & 0x800)) {
        if (p->unk_78 & 0x80) {
            func_0807C39C(p);
            p->unk_78 &= ~0x80;
            p->unk_78 |= 1;
        }
    }

    func_0807CD48(p);

    if (p->unk_78 & 0x10) {
        p->unk_9C = 8;
        SetTaskUpdate(a, (void*)func_0809075C);
    } else if (!(p->unk_78 & 0x1000)) {
        func_08090864(p);
        p->unk_5F += 4;
        func_08090B50(p, a);

        if (!(p->unk_78 & 0x20)) {
            p->unk_78 &= ~0x40;
            SetTaskUpdate(a, (void*)func_08090808);
        }
    }

    return 1;
}

#ifdef NON_MATCHING
void func_08090374(UnkStruct_02034AAC* p) {
    void* gfx;
    s32 affine;

    gfx = p->unk_48->unk_00;

    if (p->unk_78 & 0x800) {
        if (!(p->unk_78 & 1)) {
            if (p->unk_78 & 0x80) {
                if ((p->unk_78 & 8) == 0) {
                    affine = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 0);
                } else {
                    affine = AllocObjAffine(p->unk_5E, p->unk_54, p->unk_58, 1);
                }

                DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                           gUnk_08F70A28[0].unk_00, (&gUnk_02039DD4->tiles)[p->unk_48->unk_2A],
                           gUnk_02039DD4->palette, affine, 0x410, (u16)(p->unk_A0 - 1));
                DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                           gfx, p->unk_00, p->palette, affine, 0x410, p->unk_A0);

                if (p->unk_A7 != 0) {
                    DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                               gUnk_09EE981C[p->unk_A5], gUnk_02039DD4->tiles7,
                               gUnk_02039DD4->palette2, affine, 0x410, (u16)(p->unk_A0 - 2));
                } else {
                    DrawSprite(p->unk_4C >> 8, (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                               gUnk_09EE981C[p->unk_A5], gUnk_02039DD4->tiles5,
                               gUnk_02039DD4->palette, affine, 0x410, (u16)(p->unk_A0 - 2));
                }
            }
        }
    }
}
#else
INCLUDE_ASM("card/func_08090374.s");
#endif
void func_08090530(u8* work) {
    if (*(void**)&work[0x00] != 0) {
        func_0807C39C((UnkStruct_02034AAC*)work);
    }

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjPalette(*(void**)&work[0x18]);
    }
}

u8 func_08090550(UnkStruct_02034AAC* p, void* a) {
    if (gBtlWork->unk_068 & 0x20) {
        p->unk_9C = 8;
        p->unk_9E = 8;
        gUnk_02039DD4->unk_0D0 = 0;
        gUnk_02039DD4->unk_0C2 = 0;
        gBtlWork->unk_068 &= ~0x20;
        gBtlWork->unk_068 &= ~0x80;
        gBtlWork->unk_068 &= ~0x10000000;
        SetTaskUpdate(a, (void*)func_08090940);
    } else if (p->unk_78 & 0x200000) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_08090DB0);
    }

    return 1;
}

#ifdef NON_MATCHING
u8 EnemyUsecard_1(UnkStruct_02034AAC* p, void* a) {
    p->unk_A0 = 80;
    ApproachValue(&p->unk_4C, 0x7800, p->unk_9C);
    ApproachValue(&p->unk_50, 0x8400, p->unk_9C);

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
    }

    if (gBtlWork->unk_068 & 0x80) {
        if (p->unk_78 & 0x2000) {
            if ((s16)p->unk_9C == 0) {
                SetTaskUpdate(a, (void*)func_08090550);
            }
        } else if ((s16)p->unk_9C <= 2) {
            p->unk_A0 -= 4;
            p->unk_84 = 0x500;
            p->unk_9C = 0x100;
            p->unk_7C = (u16)(GetRandom() % 33) - 16;
            p->unk_9E = GetRandom() % 5 + 254;
            SetTaskUpdate(a, (void*)func_080909A4);
        }
    } else if ((s16)p->unk_9C <= 2) {
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_080909A4);
    }

    return 1;
}
#else
INCLUDE_ASM("card/EnemyUsecard_1.s");
#endif
u8 func_0809075C(UnkStruct_02034AAC* p, void* a) {
    ApproachValue(&p->unk_4C, gSineTable[((p->unk_7C >> 8) - 32) & 0xFF] * (p->unk_84 >> 8) + gUnk_09035978[0],
                  p->unk_9C);
    ApproachValue(&p->unk_50, -gSineTable[(((p->unk_7C >> 8) - 32) & 0xFF) + 0x40] * (p->unk_84 >> 8) + gUnk_09035978[1],
                  p->unk_9C);
    p->unk_9C--;

    if ((s16)p->unk_9C <= 1) {
        p->unk_9C = 0;
        p->unk_78 &= ~0x10;
        SetTaskUpdate(a, (void*)card_enemy_1);
    }

    return 1;
}

u8 func_08090808(u8* work, void* a) {
    if (work[0xA1] == 7) {
        return 0;
    }

    *(s32*)&work[0x84] += -*(s32*)&work[0x84] >> 1;
    *(s32*)&work[0x4C] += (gUnk_09035978[8] - *(s32*)&work[0x4C]) >> 1;
    *(s32*)&work[0x50] += (gUnk_09035978[9] - *(s32*)&work[0x50]) >> 1;

    if (*(s32*)&work[0x78] & 0x20) {
        SetTaskUpdate(a, (void*)card_enemy_1);
    }

    return 1;
}

void func_08090864(UnkStruct_02034AAC* p) {
    s32 t;

    if (p->unk_80 - p->unk_7C > 0x7F00) {
        p->unk_7C += 0x10000;
    }

    t = p->unk_7C - 0x10000;

    if (p->unk_80 - t < p->unk_7C - p->unk_80) {
        p->unk_7C = t;
    }

    p->unk_94 += (p->unk_98 - p->unk_94) >> 2;
    p->unk_84 += (p->unk_88 - p->unk_84) >> 1;
    ApproachValue(&p->unk_7C, p->unk_80, p->unk_9C);
    p->unk_9C--;

    if ((s16)p->unk_9C <= 1) {
        p->unk_9C = 0;
        p->unk_78 |= 0x40;
    } else {
        p->unk_78 &= ~0x40;
    }

    p->unk_4C = gSineTable[((p->unk_7C >> 8) - 32) & 0xFF] * (p->unk_84 >> 8) + p->unk_8C;
    p->unk_50 = -gSineTable[(((p->unk_7C >> 8) - 32) & 0xFF) + 64] * (p->unk_84 >> 8) + p->unk_90;
}

u8 func_08090940(UnkStruct_02034AAC* p) {
    ApproachValue(&p->unk_50, 0x8200, p->unk_9C);
    *(u16*)&p->unk_9C =
        *(s16*)&p->unk_9C > 0 ? p->unk_9C - 1 : 0;

    if (*(s16*)&p->unk_9C == 0) {
        *(u16*)&p->unk_9C = 0;
        p->unk_5E += p->unk_9E;
        p->unk_9E++;

        if (p->unk_54 <= 25) {
            return 0;
        }

        p->unk_54 -= 25;
        p->unk_58 -= 25;
    }

    return 1;
}

u8 func_080909A4(UnkStruct_02034AAC* p) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C;
    p->unk_9C++;
    p->unk_4C -= gSineTable[(p->unk_7C & 0xFF) + 0x40];
    p->unk_5E += p->unk_9E;
    p->unk_54 -= 5;
    p->unk_58 -= 5;

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->unk_068 &= ~0x10000000;
        return 0;
    }

    return 1;
}

void func_08090A54(UnkStruct_02034AAC* p, void* a) {
    p->unk_4C -= gSineTable[p->unk_9E] * 3;
    func_0807CD48(p);

    if (p->unk_9E != 0) {
        p->unk_9E -= 8;
    } else {
        p->unk_9E = 0;
        p->unk_78 &= ~0x800;
        SetTaskUpdate(a, (void*)card_enemy_1);
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08090808);
    }
}

void func_08090ACC(UnkStruct_02034AAC* p, void* a) {
    p->unk_4C += gSineTable[p->unk_9E] * 3;
    func_0807CD48(p);

    if ((s8)p->unk_9E >= 0) {
        p->unk_9E += 8;
    } else {
        p->unk_9E = 0x80;
        p->unk_78 &= ~4;
        p->unk_A0 = 100;
        SetTaskUpdate(a, (void*)func_08090A54);
    }

    if (!(p->unk_78 & 0x20)) {
        p->unk_78 &= ~0x40;
        SetTaskUpdate(a, (void*)func_08090808);
    }
}

void func_08090B50(UnkStruct_02034AAC* p, void* a) {
    switch (p->unk_A1) {
    case 5:
        p->unk_9C = 16;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)EnemyUsecard_1);
        break;
    case 6:
        p->unk_9C = 8;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)func_08090C3C);
        break;
    case 8:
        p->unk_A0 -= 4;
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_080909A4);
        break;
    case 7:
        p->unk_84 = 0x500;
        p->unk_9C = 0x100;
        p->unk_7C = (u16)(GetRandom() % 33) - 16;
        p->unk_9E = GetRandom() % 5 + 254;
        SetTaskUpdate(a, (void*)func_080909A4);
        break;
    case 9:
        p->unk_9E = 0;
        p->unk_A0 -= 4;
        SetTaskUpdate(a, (void*)func_08090ACC);
        p->unk_A1 = 0;
        break;
    }
}

u8 func_08090C3C(UnkStruct_02034AAC* p, void* a) {
    s32 (*tbl)[2]; s32* q;

    if (gBtlWork->unk_070 == 1) {
        return 1;
    }

    func_0807CD48(p);

    if (p->unk_78 & 0x20) {
        q = &p->unk_4C; tbl = (s32 (*)[2])gUnk_09035978; ApproachValue(q, tbl[3 - p->unk_9F][0], p->unk_9C); ApproachValue(&p->unk_50, ((s32 (*)[2])gUnk_09035978)[3 - p->unk_9F][1], p->unk_9C);
    } else {
        ApproachValue(&p->unk_4C, gUnk_09035978[8], p->unk_9C);
        ApproachValue(&p->unk_50, gUnk_09035978[9], p->unk_9C);
    }

    if ((s16)p->unk_9C > 0) {
        p->unk_9C--;
        p->unk_78 &= ~0x40;
    } else {
        p->unk_9C = 0;
        p->unk_78 |= 0x40;
    }

    if (p->unk_A1 == 5) {
        if (!(gBtlWork->unk_068 & 0x80) && p->unk_9F == 0) {
            gBtlWork->unk_068 |= 0x80;
        }

        if (p->unk_78 & 0x8000) {
            SetTaskUpdate(a, (void*)func_0807CF4C);
        } else {
            p->unk_9C = 15;
            p->unk_88 = 0x800;
            p->unk_84 = 0;
            p->unk_80 = gUnk_09034054[p->unk_9F] * 2;
            p->unk_7C = 0;
            p->unk_8C = p->unk_4C;
            p->unk_90 = p->unk_50;
            SetTaskUpdate(a, (void*)func_0807CFA8);
        }
    }

    p->unk_5F += 4;
    return 1;
}
u8 func_08090DB0(UnkStruct_02034AAC* p, void* a) {
    p->unk_A1 = 0;
    p->unk_50 -= p->unk_84;
    p->unk_84 -= (s16)p->unk_9C >> 1;
    p->unk_9C++;
    p->unk_4C += 0x200;
    p->unk_5E += 16;

    if (!(p->unk_78 & 0x400000)) {
        p->unk_54 -= 20;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = -20;
        }

        if (p->unk_54 <= -0x100) {
            p->unk_54 = -0x100;
            p->unk_78 |= 0x400000;
        }
    } else {
        p->unk_54 -= 20;

        if (p->unk_54 >= -2 && p->unk_54 <= 2) {
            p->unk_54 = 20;
        }

        if (p->unk_54 >= 0x100) {
            p->unk_54 = 0x100;
            p->unk_78 &= ~0x400000;
        }
    }

    if (func_0807CE68(p)) {
        p->unk_78 &= ~0x800;
        func_0807C39C(p);
        p->unk_78 &= ~0x80;
        gBtlWork->unk_068 &= ~0x10000000;
        return 0;
    }

    return 1;
}
#ifdef NON_MATCHING
void func_08090EA0(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    s32* tbl;
    u8 n;
    s32 id;
    u8* g;
    u8* q;

    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    *(s32*)&p->unk_10 = 0;
    p->unk_18 = 0;
    p->palette = 0;
    *(s32*)&p->unk_1C = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_3C[4]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_3C[4]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_3C[4];

    if (n == 1) {
        id = tbl[0];
    } else if (*(s16*)&p->unk_3C[8] != -1) {
        if (*(s16*)&p->unk_3C[8] > n) {
            id = tbl[GetRandom() % n];
        } else {
            id = tbl[*(s16*)&p->unk_3C[8] - 1];
        }
    } else {
        if (gUnk_02039DD4->unk_0D7 > n) {
            gUnk_02039DD4->unk_0D7 = n;
        }

        id = tbl[gUnk_02039DD4->unk_0D7];
        gUnk_02039DD4->unk_0D7 = GetRandom() % n;
    }

    p->unk_48 = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x804;
    p->unk_8C = 0xDC00;
    p->unk_90 = 0x8800;
    p->unk_4C = 0xDC00;
    p->unk_50 = 0x8800;
    p->unk_9C = 10;
    p->unk_A0 -= 4;
    func_0807C33C(p);
    q = &p->unk_A5;
    *q = p->unk_48->unk_20;
    g = (u8*)&gGameState;

    switch (*(s32*)(g + 0x1B8)) {
    case 1:
        *q += 2;

        if (*q > 9) {
            *q = 9;
        }

        p->unk_A7 = 1;
        break;
    case 2:
        *q = *q > 2 ? *q - 2 : 1;
        p->unk_A7 = 1;
        break;
    default:
        p->unk_A7 = 0;
        break;
    }

    p->unk_78 |= 0x80;
}
#else
INCLUDE_ASM("card/func_08090EA0.s");
#endif

void func_08091048(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    s32* tbl;
    u8 n;
    s32 id;

    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->palette = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_3C[4]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_3C[4]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_3C[4];

    if (n == 1) {
        id = tbl[0];
    } else if (*(s16*)&p->unk_3C[8] < n) {
        id = tbl[*(s16*)&p->unk_3C[8]];
    } else {
        id = tbl[GetRandom() % n];
    }

    p->unk_48 = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x801;
    p->unk_8C = 0x10000;
    p->unk_90 = 0x8800;
    p->unk_4C = 0x10000;
    p->unk_50 = 0x8800;
    p->unk_9C = 0x10;
    p->unk_A0 -= 4;
    p->unk_A5 = p->unk_48->unk_20;
}
void func_08091138(UnkStruct_02034AAC* p, UnkStruct_08090244* a) {
    s32* tbl;
    u8 n;
    s32 id;

    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->palette = 0;
    p->unk_A1 = 0;
    *(UnkStruct_08090244*)&p->unk_38 = *a;
    p->unk_78 = 0;
    p->unk_A0 = 50;
    p->unk_9C = 0;
    tbl = gUnk_09EE275C[*(s32*)&p->unk_3C[4]];
    n = gUnk_08F7DAC4[*(s32*)&p->unk_3C[4]];
    *(u16*)&p->unk_5C[0] = *(s32*)&p->unk_3C[4];

    if (n == 1) {
        id = tbl[0];
    } else if (*(s16*)&p->unk_3C[8] < n) {
        id = tbl[GetRandom() % *(s16*)&p->unk_3C[8]];
    } else {
        id = tbl[GetRandom() % n];
    }

    p->unk_48 = &gCardDefs[id];
    p->unk_54 = 0x100;
    p->unk_58 = 0x100;
    p->unk_5F = GetRandom();
    p->unk_5E = 0;
    p->unk_84 = 0;
    p->unk_88 = 0x2400;
    p->unk_78 |= 0x801;
    p->unk_8C = 0x10000;
    p->unk_90 = 0x8800;
    p->unk_4C = 0x10000;
    p->unk_50 = 0x8800;
    p->unk_9C = 0x10;
    p->unk_A0 -= 4;
    p->unk_A5 = p->unk_48->unk_20;
}

#ifdef NON_MATCHING
void func_08091234(u16 arg) {
    UnkStruct_0807FD10_Args args;
    UnkStruct_02034AAC* p;
    u8 i;
    u8 flag;

    args.unk_00 = 0;
    args.unk_04 = 0;
    *(u16*)&args.unk_08[0] = arg;
    args.unk_0C = gUnk_02034AB4;
    args.unk_0E = 0;
    p = ((UnkStruct_02034AAC**)TaskCreate(&gUnk_02039DD4->unk_09C, &gUnk_09EE4B28[0x30], &args))[1];
    gBtlWork->unk_068 |= 0x10000000;
    gUnk_02039DD4->unk_0E0 = 1;

    if ((gBtlWork->unk_068 & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->unk_A5;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
    } else if ((gBtlWork->unk_068 & 0x20) == 0) {
        if ((s16)gUnk_02039DD4->unk_0C2 > p->unk_A5) {
            p->unk_78 = (p->unk_78 | 4) & ~0x40;
            return;
        }

        flag = 0;

        if (gUnk_02039B9C->unk_0F4 == 2) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_2A == 0) {
                    flag = 1;
                    break;
                }
            }
        }

        if (gBtlWork->unk_0F4 == 20) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_24 == 22) {
                    flag = 1;
                    break;
                }
            }
        }

        if (gBtlWork->unk_0F4 == 29) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_2A == 2) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag != 0) {
            p->unk_78 = (p->unk_78 | 4) & ~0x40;
            return;
        }

        gBtlWork->unk_068 |= 0x800000;

        for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
            gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
        }

        if ((s16)gUnk_02039DD4->unk_0C2 == p->unk_A5) {
            m4aSongNumStart(204);
            gBtlWork->unk_068 &= ~0x80;
            gBtlWork->unk_068 &= ~0x20;
            gBtlWork->unk_068 &= ~0x400;
            gBtlWork->unk_0A4 = 0;
            p->unk_78 = (p->unk_78 | 4) & ~0x40;
            return;
        }

        if (p->unk_A5 == 0) {
            gBtlWork->unk_1CA = -(s8)gUnk_02039DD4->unk_0C2;
        } else {
            gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2 - p->unk_A5;
        }

        m4aSongNumStart(203);
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 &= ~0x20;
        gUnk_02039DD4->unk_000[0] = p;

        if (gBtlWork->unk_0F4 == 48) {
            if (p->unk_A5 != 0) {
                gUnk_02039DD4->unk_0C2 = p->unk_A5 - gUnk_02039DD4->unk_0C2;
                p->unk_A5 = gUnk_02039DD4->unk_0C2;
            } else {
                gUnk_02039DD4->unk_0C2 = p->unk_A5;
            }

            if ((s16)gUnk_02039DD4->unk_0C2 < 0) {
                gUnk_02039DD4->unk_0C2 = 0;
            }

            gBtlWork->unk_0F8--;
        } else {
            gUnk_02039DD4->unk_0C2 = p->unk_A5;
        }

        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        p->unk_78 |= 0x2000;
        func_0807BA54();
    } else {
        if ((s16)gUnk_02039DD4->unk_0C2 > p->unk_A5) {
            p->unk_78 = (p->unk_78 | 4) & ~0x40;
            return;
        }

        flag = 0;

        if (gUnk_02039B9C->unk_0F4 == 2) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_2A == 0) {
                    flag = 1;
                    break;
                }
            }
        }

        if (gBtlWork->unk_0F4 == 54) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_2A == 1) {
                    flag = 1;
                    break;
                }
            }
        }

        if (gBtlWork->unk_0F4 == 20) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_24 == 22) {
                    flag = 1;
                    break;
                }
            }
        }

        if (gBtlWork->unk_0F4 == 29) {
            for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                if (gUnk_02039DD4->unk_000[i]->unk_48->unk_2A == 2) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag != 0) {
            p->unk_78 = (p->unk_78 | 4) & ~0x40;
            return;
        }

        gBtlWork->unk_068 |= 0x800000;

        for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
            gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
        }

        if ((s16)gUnk_02039DD4->unk_0C2 == p->unk_A5) {
            m4aSongNumStart(204);
            gBtlWork->unk_068 &= ~0x80;
            gBtlWork->unk_068 &= ~0x20;
            gBtlWork->unk_068 &= ~0x400;
            gBtlWork->unk_0A4 = 0;
            p->unk_78 = (p->unk_78 | 4) & ~0x40;
            return;
        }

        if (p->unk_A5 == 0) {
            gBtlWork->unk_1CA = -(s8)gUnk_02039DD4->unk_0C2;
        } else {
            gBtlWork->unk_1CA = gUnk_02039DD4->unk_0C2 - p->unk_A5;
        }

        m4aSongNumStart(203);
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
        gBtlWork->unk_068 &= ~0x20;
        gUnk_02039DD4->unk_000[0] = p;

        if (gBtlWork->unk_0F4 == 48) {
            if (p->unk_A5 != 0) {
                gUnk_02039DD4->unk_0C2 = p->unk_A5 - gUnk_02039DD4->unk_0C2;
                p->unk_A5 = gUnk_02039DD4->unk_0C2;
            } else {
                gUnk_02039DD4->unk_0C2 = p->unk_A5;
            }

            if ((s16)gUnk_02039DD4->unk_0C2 < 0) {
                gUnk_02039DD4->unk_0C2 = 0;
            }

            gBtlWork->unk_0F8--;
        } else {
            gUnk_02039DD4->unk_0C2 = p->unk_A5;
        }

        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        p->unk_78 |= 0x2000;
        func_0807BA54();
    }

    p->unk_78 = (p->unk_78 | 4) & ~0x40;
}
#else
INCLUDE_ASM("card/func_08091234.s");
#endif
#ifdef NON_MATCHING
void func_080917C8(u16 a, u8 b) {
    UnkStruct_08090244 arg;
    UnkStruct_02034AAC* p;
    u8 i;

    arg.unk_00 = 0;
    arg.unk_04 = 0;
    arg.unk_08 = a;
    *(u16*)&arg.unk_0C = b;
    arg.unk_0E = 0;
    p = ((UnkStruct_02034AAC**)TaskCreate(&gUnk_02039DD4->unk_09C, &gUnk_09EE4B28[0x48], &arg))[1];
    gBtlWork->unk_068 |= 0x10000000;

    if ((gBtlWork->unk_068 & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
    } else if ((gBtlWork->unk_068 & 0x20) == 0) {
        if (gUnk_02039DD4->unk_0CC != 2) {
            if ((s16)gUnk_02039DD4->unk_0C2 < p->unk_48->unk_20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                m4aSongNumStart(0xCB);
                gBtlWork->unk_068 |= 0x800000;
                gBtlWork->unk_068 |= 0x400;
                gBtlWork->unk_068 |= 0x80;
                gUnk_02039DD4->unk_000[0] = p;
                gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
                gUnk_02039DD4->unk_0D0 = 1;
                gBtlWork->unk_0A4 = 0;
                p->unk_78 |= 0x2000;
            }
        }
    }

    p->unk_78 |= 4;
    p->unk_78 &= ~0x40;
}
#else
INCLUDE_ASM("card/func_080917C8.s");
#endif

#ifdef NON_MATCHING
void func_08091978(u16 a, u8 b) {
    UnkStruct_08090244 arg;
    UnkStruct_02034AAC* p;
    u8 i;

    arg.unk_00 = 0;
    arg.unk_04 = 0;
    arg.unk_08 = a;
    *(u16*)&arg.unk_0C = b;
    arg.unk_0E = 0;
    p = ((UnkStruct_02034AAC**)TaskCreate(&gUnk_02039DD4->unk_09C, &gUnk_09EE4B28[0x60], &arg))[1];
    gBtlWork->unk_068 |= 0x10000000;

    if ((gBtlWork->unk_068 & 0x80) == 0) {
        p->unk_78 |= 0x2000;
        gUnk_02039DD4->unk_000[0] = p;
        gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
        gUnk_02039DD4->unk_0D0 = 1;
        gBtlWork->unk_0A4 = 0;
        gBtlWork->unk_068 |= 0x400;
        gBtlWork->unk_068 |= 0x80;
    } else if (gBtlWork->unk_068 & 0x20) {
        if (gBtlWork->unk_0F4 == 2) {
            if ((s16)gUnk_02039DD4->unk_0C2 < p->unk_48->unk_20) {
                for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
                    gUnk_02039DD4->unk_000[i]->unk_78 |= 0x200000;
                }

                m4aSongNumStart(0xCB);
                gBtlWork->unk_068 |= 0x800000;
                gBtlWork->unk_068 |= 0x400;
                gBtlWork->unk_068 |= 0x80;
                gUnk_02039DD4->unk_000[0] = p;
                gUnk_02039DD4->unk_0C2 = p->unk_48->unk_20;
                gUnk_02039DD4->unk_0D0 = 1;
                gBtlWork->unk_0A4 = 0;
                p->unk_78 |= 0x2000;
            }
        }
    }

    p->unk_78 |= 4;
    p->unk_78 &= ~0x40;
}
#else
INCLUDE_ASM("card/func_08091978.s");
#endif
void func_08091B28(void) {
    gUnk_02034AB4 = -1;
}

void func_08091B38(u16 a) {
    gUnk_02034AB4 = a;
}
u16 func_08091B44(void) {
    if (gUnk_02034AB4 != -1) {
        return gUnk_02034AB4;
    }

    return gUnk_02039DD4->unk_0D7;
}
void WORLDSELECT_0(void) {
    SetBgMode2();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
#ifdef VERSION_EU
    LoadBgTiles(3, gUnkEu_08CB0D3C, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    eu_080059F4(3, gUnkEu_08F7ADFC);
#else
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
#endif
    SetBgAffine(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AB8, 1);
#ifdef VERSION_EU
    TaskCreate(gUnk_02034AB8, gUnkEu_09F72C10, 0);
#else
    TaskCreate(gUnk_02034AB8, gUnk_09EE7804, 0);
#endif
}
void WORLDSELECT_1(void) {
    TaskPoolUpdate(gUnk_02034AB8);
    TaskPoolDraw(gUnk_02034AB8);
}
void WORLDSELECT_2(void) {
    TaskPoolDestroy(gUnk_02034AB8);
}
INCLUDE_ASM("card/MapSelect_0.s");
#ifndef VERSION_EU
u8 MapSelect_1(UnkStruct_08093838* w, void* a) {
    *(void**)&w->unk_014[0x24] = LoadObjTiles(gUnk_093F7172, 0x400);
    LoadBgTiles(1, gUnk_09508098, 0x2020);
    LoadPalette(gUnk_09618C58, (void*)0x05000180, 32);
    LoadPalette(&gUnk_09618C58[0x40], (void*)0x050001C0, 64);
    func_080062F4(12, 1);
    func_080062F4(14, 1);
    func_080062F4(15, 1);
    w->unk_286++;
    DisableBg(1);
    SetTaskUpdate(a, (void*)func_0809217C);
    return 1;
}
#else
INCLUDE_ASM("card/MapSelect_1.s");
#endif
u8 func_0809217C(UnkStruct_08093838* w, void* a) {
    s32 n;

    func_0800516C(1, gUnk_09EE4BB0, 1, 2);
    w->unk_240 = 0;
    func_08005244(1, 0, 0);
    EnableBg(1);

    if (w->unk_2BE == 1) {
        w->unk_2DA = func_080E8D00();
        w->unk_2DC = func_080E8D1C(0);
        n = w->unk_2DA;

        while (n != 0) {
            n--;
        }

        w->unk_2C4 = *(void**)&w->unk_040[0x08];
        w->unk_2CC = 0;
        w->unk_238 =
            ((void**)TaskCreate(w, gTaskDescSELMAPEVKEY, &w->unk_2C4))[1];
    }

    func_08093C44(((u8*)w->unk_1EC)[32], w);
    SetTaskUpdate(a, (void*)func_08092234);
    return 1;
}
void func_080A42B4(void);
u8 func_08094404(UnkStruct_08093838* w, void* a);

#ifdef NON_MATCHING
u8 func_08092234(UnkStruct_08093838* w, void* a) {
    u8* n;

    if (w->unk_290 != 0) {
        ApproachValue(&w->unk_26C, 0, w->unk_290);
        ApproachValue(&w->unk_270, 0x9800, w->unk_290);
        w->unk_290--;
    } else {
        ApproachValue(&w->unk_240, 0x10000, w->unk_28F);
        ApproachValue(&w->unk_248, 0, w->unk_28F);
        func_08005244(1, 0, (u32)w->unk_240 >> 8);

        if (w->unk_28F != 0) {
            w->unk_28F--;
        } else {
            if ((gGameState.unk_17A & 8) == 0) {
                w->unk_2C1 = 1;
                func_080A42B4();
                w->unk_2C2 = 95;
                SetTaskUpdate(a, (void*)func_0809423C);
            } else if ((gGameState.unk_17A & 0x40) == 0 && w->unk_2BE == 1) {
                func_080A42B4();
                w->unk_2C2 = 109;
                SetTaskUpdate(a, (void*)func_08094404);
                gGameState.unk_17A |= 0x40;
            } else {
                n = (u8*)ListPoolFirst(w->unk_014);
                func_0800516C(1, gUnk_09EE4BB0, 1, 2);

                while (n != 0) {
                    *(u16*)&n[0x6C] |= 2;
                    n = (u8*)ListPoolNext(&n[0x38]);
                }

                if (w->unk_27C <= 6) {
                    w->unk_285 = 0;
                } else {
                    w->unk_285 = w->unk_27C / 6;
                }

                w->unk_25C = 0x6400;
                w->unk_254 = 0x7A00;
                w->unk_244 = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                w->unk_2C0 = 1;
            }
        }
    }

    TaskPoolUpdate(w);
    return 1;
}
#else
INCLUDE_ASM("card/func_08092234.s");
#endif

#ifndef VERSION_EU
u8 func_080923E0(UnkStruct_08093838* w, void* a) {
    s8 v;

    if (w->unk_1EC->unk_6F == 0) {
        LoadBgTiles(1, &gUnk_09508098[0x2020], 0x23C0);
        LoadBgMap(1, &gUnk_0960F2B8[0x1800], 0x800);
        func_08093D28(w->unk_1EC->unk_20, w);
        v = func_08093E34(w->unk_1EC->unk_20, w);
        SetTaskUpdate(a, (void*)func_0809254C);
        ReleaseObjTiles(w->tiles);
        w->tiles = AllocObjTiles(0x1E0, 0);
        func_08002A10(w->tiles, &gUnk_093F47E4[0xD88]);
        AnimInit(w->unk_1F8, &gUnk_09EF1194[0x38], &gUnk_09EF1180[0x38]);
        AnimStart(w->unk_1F8, 0, 1);
        w->gfx = AnimGetGfx(w->unk_1F8);
        w->unk_280 = w->unk_258 >> 8;
        w->unk_282 = w->unk_25C >> 8;

        if (v > 4) {
            w->unk_29C = v - 5;
            w->unk_29D = 1;
        } else {
            w->unk_29C = v;
            w->unk_29D = 0;
        }

        w->unk_28B = 4;
        w->unk_28C = 4;
        w->unk_2C0 = 0;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(w);
    return 1;
}
#else
INCLUDE_ASM("card/func_080923E0.s");
#endif
u8 func_0809254C(UnkStruct_08093838* w, void* a) {
    u16 keys;
    s16 sel;
    u8 n;

    keys = GetKeysPressed();
    sel = (s8)w->unk_29C + (s8)w->unk_29D * 5;

    if ((gGameState.unk_17A & 8) == 0) {
        if (w->unk_28B == 0) {
            SetTaskUpdate(a, (void*)func_0809438C);
            TaskPoolUpdate(w);
            return 1;
        }
        keys = 0;
    }

    switch (keys & 0x30F) {
    case 2:
#ifdef VERSION_EU
        LoadBgTiles(1, gUnkEu_09529A04, 0x2020);

        switch (gLanguage) {
        case 0:
            break;
        case 1:
            RequestDma3Copy(gUnkEu_0952DDE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_0952E0E4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_0952DFE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_0952DEE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        }

        LoadBgMap(1, gUnkEu_09543324, 0x800);
#else
        LoadBgTiles(1, gUnk_09508098, 0x2020);
        LoadBgMap(1, &gUnk_0960F2B8[0x1000], 0x800);
#endif
        w->unk_1EC->unk_6C &= 0xFDFF;
        SetTaskUpdate(a, (void*)func_080928E4);
        m4aSongNumStart(104);
        break;
    case 1:
        n = (u8)func_080E8D64((u32)&gUnk_09EE4C80[w->unk_1EC->unk_20 + (s16)sel] + 0x20);

        if (n == 1) {
            if (gUnk_0203A8C0[w->unk_1EC->unk_20 + (s16)sel] != 0) {
                if (w->unk_2BE == 1) {
                    m4aSongNumStart(140);

                    if (func_08093B08(w->unk_1EC->unk_20) == 0) {
                        w->unk_1EC->unk_74 = sel;
                        w->unk_1EC->unk_6C |= 0x40;
                    }

                    func_08093AC8(w->unk_1EC->unk_20 + sel);

                    if ((u8)func_080E8E24((u32)&gUnk_09EE4C80[w->unk_1EC->unk_20 + (s16)sel] + 0x20) == 1) {
                        w->unk_2DA = func_080E8D00();
                        ((u8*)w->unk_238)[0x122]++;
                        ((u8*)w->unk_238)[0x11A] = 8;

                        if (w->unk_2DA == 0) {
                            w->unk_1EC->unk_74 = sel;
                            w->unk_1EC->unk_6C |= 0x40;
                            *w->unk_294 = 2;
                            w->unk_28F = 16;
                            w->unk_290 = 16;
                            w->unk_285 = 0;
                            w->unk_284 = 0;
                            w->unk_2CC = n;
                            SetTaskUpdate(a, (void*)func_08092E2C);
                            return 1;
                        }
                    }

                    func_08093C44(w->unk_1EC->unk_20, w);
                    func_08093D28(w->unk_1EC->unk_20, w);

                    if ((s8)func_08093E34(w->unk_1EC->unk_20, w) == -1) {
#ifdef VERSION_EU
                        LoadBgTiles(1, gUnkEu_09529A04, 0x2020);

                        switch (gLanguage) {
                        case 0:
                            break;
                        case 1:
                            RequestDma3Copy(gUnkEu_0952DDE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        case 2:
                            RequestDma3Copy(gUnkEu_0952E0E4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        case 3:
                            RequestDma3Copy(gUnkEu_0952DFE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        case 4:
                            RequestDma3Copy(gUnkEu_0952DEE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        }

                        LoadBgMap(1, gUnkEu_09543324, 0x800);
#else
                        LoadBgTiles(1, gUnk_09508098, 0x2020);
                        LoadBgMap(1, &gUnk_0960F2B8[0x1000], 0x800);
#endif
                        w->unk_1EC->unk_6C &= 0xFDFF;
                        func_08094548(w);
                        SetTaskUpdate(a, (void*)func_080928E4);
                    }
                    break;
                }

                w->unk_1EC->unk_74 = sel;
                w->unk_1EC->unk_6C |= 0x40;
                func_08093AC8(w->unk_1EC->unk_20 + sel);
                *w->unk_294 = 2;
                w->unk_28F = 16;
                w->unk_290 = 16;
                SetTaskUpdate(a, (void*)func_08092E2C);
                m4aSongNumStart(140);
                w->unk_285 = 0;
                w->unk_284 = 0;
                w->unk_2CC = n;
                return 1;
            }
        }
        m4aSongNumStart(105);
        break;
    }

    *(void**)&w->unk_278 = AnimUpdate((AnimState*)&w->unk_1F8[0x18]);
    w->gfx = AnimUpdate((AnimState*)w->unk_1F8);
    gUnk_0203A890[4] = AnimUpdate((AnimState*)&gUnk_0203A890[6]);
    TaskPoolUpdate(w);
    func_08093F5C((u8*)w);
    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(w);
    return 1;
}
u8 func_080928E4(UnkStruct_08093838* w, void* a) {
    MapcardWork* node;

    if (func_08093384((u8*)w) == 0) {
        return 0;
    }

    if (w->unk_1EC->unk_6F == 0) {
        node = (MapcardWork*)ListPoolFirst(w->unk_014);

        while (node != 0) {
            if (w->unk_1EC != node) {
                node->unk_6C |= 2;
            }

            node = (MapcardWork*)ListPoolNext(&node->unk_38);
        }

        SetTaskUpdate(a, (void*)func_08092A34);
        ReleaseObjTiles(w->tiles);
        w->tiles = AllocObjTiles(0x3C0, 0);
        func_08002A10(w->tiles, gUnk_093F47E4);
        AnimInit(w->unk_1F8, gUnk_09EF1194, gUnk_09EF1180);
        AnimStart(w->unk_1F8, 0, 1);
        w->gfx = AnimGetGfx(w->unk_1F8);
        w->unk_258 = w->unk_280 << 8;
        w->unk_25C = w->unk_282 << 8;
        w->unk_250 = w->unk_1EC->unk_4C;
        w->unk_254 = w->unk_1EC->unk_50;
        w->unk_2C0 = 1;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(w);
    return 1;
}
INCLUDE_ASM("card/func_08092A34.s");
u8 func_08092E2C(UnkStruct_08093838* w) {
    ApproachValue(&w->unk_240, 0, w->unk_28F);
    ApproachValue(&w->unk_248, -0xA000, w->unk_28F);
    ApproachValue(&w->unk_25C, 0x16400, w->unk_28F);
    ApproachValue(&w->unk_254, 0x17A00, w->unk_28F);
    ApproachValue(&w->unk_244, 0x19100, w->unk_28F);
    func_08005244(1, 0, (u32)w->unk_240 >> 8);
    w->unk_2C0 = 0;

    if (w->unk_299 <= 8) {
        w->unk_299++;
    }

    if (w->unk_29A <= 8) {
        w->unk_29A++;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_28F != 0) {
        w->unk_28F--;
    } else if (w->unk_290 != 0) {
        ApproachValue(&w->unk_26C, -0x800, w->unk_290);
        ApproachValue(&w->unk_270, 0xA000, w->unk_290);
        w->unk_290--;
    } else {
        if (w->unk_2BF != 0 || (w->unk_1EC->unk_6C & 0x80)) {
            return 0;
        }
    }

    TaskPoolUpdate(w);
    return 1;
}
INCLUDE_ASM("card/MapSelect_2.s");
void MapSelect_3(UnkStruct_08093838* w) {
    TaskPoolDestroy(w);

    if (w->unk_2E0 != 0) {
        EwramFree(w->unk_2E0);
    }

    func_080062F4((*(UnkStruct_080038C8**)&w->unk_040[0x08])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&w->unk_040[0x00])->unk_06 + 16, 0);
    func_080062F4(15, 0);
    func_080062F4((*(UnkStruct_080038C8**)&w->unk_040[0x18C])->unk_06 + 16, 0);
    ReleaseObjTiles(*(void**)&w->unk_040[0x04]);
    ReleaseObjPalette(*(void**)&w->unk_040[0x08]);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(*(void**)&w->unk_040[0x00]);
    ReleaseObjTiles(*(void**)&w->unk_014[0x24]);

    if (*(void**)&w->unk_014[0x18] != 0) {
        ReleaseObjTiles(*(void**)&w->unk_014[0x18]);
    }

    if (*(void**)&w->unk_014[0x20] != 0) {
        ReleaseObjTiles(*(void**)&w->unk_014[0x20]);
    }

    if (*(void**)&w->unk_014[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&w->unk_014[0x1C]);
    }

    ReleaseObjTiles(*(void**)&w->unk_040[0x1A8]);
    func_08065AE0(&w->unk_040[0x0C], 48);
    ReleaseObjPalette(*(void**)&w->unk_040[0x18C]);
    *w->unk_294 = 1;
    ReleaseObjTiles(*(void**)&w->unk_040[0x1A0]);
    ReleaseObjTiles(gUnk_0203A890[0]);
    ReleaseObjTiles(gUnk_0203A890[1]);
}
void func_0809332C(UnkStruct_08093838* w) {
    MapcardArgs args;
    u16* q;
    u16 i;

    for (i = 0; i < w->unk_27C; i++) {
        q = (u16*)w->unk_2E0;
        args.unk_00 = q[i * 2];
        args.unk_01 = i;
        args.unk_02 = w->unk_27C;
        args.unk_03 = q[i * 2 + 1];
        args.unk_08 = w->unk_014;
        args.unk_04 = w;
        func_08094E78(&args, (u8*)w);
    }
}

u16 func_08093384(u8* work) {
    u16 count;
    u16 i;
    u16 j;

    count = 0;

    for (j = 0; j < 27; j++) {
        for (i = j * 10; i < j * 10 + 10; i++) {
            if (gUnk_0203A8C0[i] != 0) {
                count++;
                break;
            }
        }
    }

    return count;
}

void func_080933D8(UnkStruct_080933D8* p) {
    u16 i;
    u16 j;

    for (i = 0; i <= 26; i++) {
        j = i * 10;

        while (j < i * 10 + 10) {
            if (gUnk_0203A8C0[j] != 0) {
                p->unk_00 = i * 10;
                p->unk_02 = gUnk_0203A8C0[j];
                p++;
                break;
            }

            j++;
        }
    }
}

#ifdef NON_MATCHING
void func_08093434(u8* work) {
    MapcardWork* a;
    MapcardWork* b;
    MapcardWork* found;
    MapcardWork* p;
    s8 cnt;

    if (work[0x298] != 0) {
        return;
    }

    if (*(MapcardWork**)&work[0x1EC] == 0) {
        return;
    }

    switch (GetKeysRepeat() & 0xF0) {
    case 16:
        p = (MapcardWork*)ListPoolNext((*(MapcardWork**)&work[0x1EC])->unk_38);

        if (p != 0 && (p->unk_6C & 1)) {
            *(s32*)&work[0x264] = p->unk_4C;
            work[0x28C] = 4;
            (*(MapcardWork**)&work[0x1EC])->unk_6C &= 0xFEFF;
            *(MapcardWork**)&work[0x1EC] = (MapcardWork*)ListPoolNext(
                (*(MapcardWork**)&work[0x1EC])->unk_38);
            (*(MapcardWork**)&work[0x1EC])->unk_6C |= 0x100;
            m4aSongNumStart(121);
        }
        break;
    case 32:
        p = ListPoolPrev((*(MapcardWork**)&work[0x1EC])->unk_38);

        if (p != 0 && (p->unk_6C & 1)) {
            *(s32*)&work[0x264] = p->unk_4C;
            work[0x28C] = 4;
            (*(MapcardWork**)&work[0x1EC])->unk_6C &= 0xFEFF;
            *(MapcardWork**)&work[0x1EC] =
                ListPoolPrev((*(MapcardWork**)&work[0x1EC])->unk_38);
            (*(MapcardWork**)&work[0x1EC])->unk_6C |= 0x100;
            m4aSongNumStart(121);
        }
        break;
    case 128:
        a = (MapcardWork*)ListPoolFirst(&work[0x14]);
        b = 0;
        found = 0;
        cnt = 0;

        while (a != 0) {
            if (a->unk_6C & 1) {
                b = a;
                break;
            }

            a = (MapcardWork*)ListPoolNext(a->unk_38);
        }

        while (b != 0 && (b->unk_6C & 1)) {
            cnt++;
            b = (MapcardWork*)ListPoolNext(b->unk_38);
        }

        if (b != 0 && cnt == 6) {
            found = b;
        }

        if (found != 0) {
            *(MapcardWork**)&work[0x1F4] = found;
            work[0x298] = 1;

            if (a != 0) {
                do {
                    if (a->unk_6C & 1) {
                        a->unk_4C = -0x6400;
                        a->unk_6C &= 0xFEFF;
                        a = (MapcardWork*)ListPoolNext(a->unk_38);
                    } else {
                        break;
                    }
                } while (a != 0);
            }

            m4aSongNumStart(121);
        }

        b = (MapcardWork*)ListPoolFirst(&work[0x14]);

        while (b != 0) {
            if (b->unk_4C == -0x6400) {
                a->unk_6C &= 0xFEFF;
            }

            b = (MapcardWork*)ListPoolNext(b->unk_38);
        }
        break;
    case 64:
        a = (MapcardWork*)ListPoolFirst(&work[0x14]);
        b = 0;

        while (a != 0) {
            if (a->unk_6C & 1) {
                b = a;
                break;
            }

            a = (MapcardWork*)ListPoolNext(a->unk_38);
        }

        if (ListPoolPrev(a->unk_38) != 0) {
            *(MapcardWork**)&work[0x1F4] = ListPoolPrev(a->unk_38);
            work[0x298] = 2;

            if (b != 0) {
                do {
                    if ((b->unk_6C & 1) == 0) {
                        break;
                    }

                    b->unk_4C = -0x6400;
                    b = (MapcardWork*)ListPoolNext(b->unk_38);
                } while (b != 0);
            }

            m4aSongNumStart(121);
        }

        b = (MapcardWork*)ListPoolFirst(&work[0x14]);

        while (b != 0) {
            if (b->unk_4C == -0x6400) {
                a->unk_6C &= 0xFEFF;
            }

            b = (MapcardWork*)ListPoolNext(b->unk_38);
        }
        break;
    }

    ApproachValue((s32*)&work[0x258], *(s32*)&work[0x264], work[0x28C]);

    if (work[0x28C] != 0) {
        work[0x28C]--;
    }
}
#else
INCLUDE_ASM("card/func_08093434.s");
#endif
void func_08093708(UnkStruct_08093838* w) {
    MapcardWork* node;
    s8 i;

    switch (w->unk_298) {
    case 0:
        break;
    case 1:
        node = w->unk_1F4;
        i = 0;
        while (node != 0) {
            node->unk_4C = gUnk_09EE7520[i++] << 8;
            if (i == 6) {
                break;
            }
            node = ListPoolNext(node->unk_38);
        }
        w->unk_298 = 0;
        func_08093838(w);
        if (w->unk_1EC != 0) {
            w->unk_264 = w->unk_1EC->unk_4C;
            w->unk_28C = 4;
        }
        w->unk_284++;
        break;
    case 2:
        node = w->unk_1F4;
        i = 5;
        while (node != 0) {
            node->unk_4C = gUnk_09EE7520[i--] << 8;
            if (i < 0) {
                break;
            }
            node = ListPoolPrev(node->unk_38);
        }
        w->unk_298 = 0;
        func_08093838(w);
        if (w->unk_1EC != 0) {
            w->unk_264 = w->unk_1EC->unk_4C;
            w->unk_28C = 4;
        }
        w->unk_284--;
        break;
    }
}

s32 func_08093838(UnkStruct_08093838* w) {
    UnkStruct_02034AAC* node;
    s32 best;
    s32 d;
    u16 r;
    void* z;
    u8* q;

    node = (UnkStruct_02034AAC*)ListPoolFirst(w->unk_014);
    best = 0x100;
    z = 0;
    w->unk_1EC = z;

    while (node != 0) {
        if (node->unk_4C != -0x6400) {
            d = (node->unk_4C >> 8) - (w->unk_258 >> 8);
            r = Sqrt(d * d);

            if (best > r) {
                best = r;
                w->unk_1EC = (MapcardWork*)node;
            }
        }

        node = (UnkStruct_02034AAC*)ListPoolNext(&node->unk_38);
    }

    q = (u8*)w->unk_1EC;

    if (q != 0) {
        q += 0x6C;
        r = *(u16*)q | 0x100;
        *(u16*)q = r;

        return (((UnkStruct_02034AAC*)w->unk_1EC)->unk_4C - w->unk_258) >> 8;
    }

    return 0;
}
u16 func_080938CC(void) {
    u8 sum;
    s32 i;

    sum = 0;

    for (i = 0; i <= 0x10D; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

s32 func_080938F8(u16 a) {
    if (func_08093B38() <= 98) {
        if (gUnk_0203A8C0[a] <= 8) {
            gUnk_0203A8C0[a]++;

            switch (gUnk_09EE4C80[a].unk_20) {
            case 0:
                func_0800FDD0(209);
                break;
            case 1:
                func_0800FDD0(210);
                break;
            case 2:
                func_0800FDD0(211);
                break;
            case 3:
                func_0800FDD0(212);
                break;
            case 4:
                func_0800FDD0(213);
                break;
            case 5:
                func_0800FDD0(214);
                break;
            case 6:
                func_0800FDD0(215);
                break;
            case 7:
                func_0800FDD0(216);
                break;
            case 8:
                func_0800FDD0(217);
                break;
            case 9:
                func_0800FDD0(218);
                break;
            case 10:
                func_0800FDD0(219);
                break;
            case 11:
                func_0800FDD0(220);
                break;
            case 12:
                func_0800FDD0(221);
                break;
            case 13:
                func_0800FDD0(222);
                break;
            case 14:
                func_0800FDD0(223);
                break;
            case 15:
                func_0800FDD0(224);
                break;
            case 16:
                func_0800FDD0(225);
                break;
            case 17:
                func_0800FDD0(226);
                break;
            case 18:
                func_0800FDD0(227);
                break;
            case 19:
                func_0800FDD0(228);
                break;
            case 20:
                func_0800FDD0(229);
                break;
            case 21:
                func_0800FDD0(230);
                break;
            case 22:
                func_0800FDD0(231);
                break;
            case 23:
                func_0800FDD0(232);
                break;
            case 24:
                func_0800FDD0(233);
                break;
            case 25:
                func_0800FDD0(234);
                break;
            }

            return 1;
        }
    } else {
        if (gUnk_09EE4C80[a].unk_20 > 21) {
            gUnk_0203A8C0[a]++;

            switch (gUnk_09EE4C80[a].unk_20) {
            case 22:
                func_0800FDD0(231);
                break;
            case 23:
                func_0800FDD0(232);
                break;
            case 24:
                func_0800FDD0(233);
                break;
            case 25:
                func_0800FDD0(234);
                break;
            }

            return 1;
        }
    }

    return 0;
}

s32 func_08093AC8(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        gUnk_0203A8C0[a]--;
        return 1;
    }

    return 0;
}

s32 func_08093AE8(void) {
    func_080938F8(GetRandom() % 270);
}

u16 func_08093B08(u16 a) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = a; i < a + 10; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

u16 func_08093B38(void) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = 0; i < 220; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

u16 func_08093B58(void) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = 0; i < 27; i++) {
        sum += gUnk_0203A8C0[i * 10];
    }

    return sum;
}

void func_08093B78(void* a, void* b) {
    TaskCreate(a, gTaskDescMapSelect, b);
}

void func_08093B8C(void) {
    u16 i;

    for (i = 0; i < 270; i++) {
        gUnk_0203A8C0[i] = 0;
    }
}

void func_08093BB4(void) {
#ifdef VERSION_EU
    s32 i;
#endif

    func_08093B8C();

#ifdef VERSION_EU
    if (gUnk_03006C10 & 8) {
        func_080938F8(211);
        func_080938F8(191);

        for (i = 0; i <= 219; i += 10) {
            if (func_080938CC() <= 98) {
                func_080938F8(i);
            }
        }

        func_080938F8(221);
        func_080938F8(231);
        func_080938F8(241);
        func_080938F8(251);
    } else {
        func_080938F8(191);
    }
#else
    if (!(gUnk_03006C10 & 8)) {
        func_080938F8(191);
    }
#endif
}

u8 func_08093BD4(void) {
    return gUnk_02034ACC;
}

void func_08093BE0(void) {
    gUnk_02034ACC = 1;
}

void func_08093BEC(u32 a) {
    gUnk_02034AD0 = a;
}

u32 func_08093BF8(void) {
    return gUnk_02034AD0;
}

void func_08093C04(void) {
    gUnk_02034AD0 = 0;
    gUnk_02034ACC = 0;
}

void* func_08093C18(u16 a) {
#ifdef VERSION_EU
    return eu_0805E924(gUnk_09EF7048[a]);
#else
    return gUnk_09EF7048[a];
#endif
}

u8 func_08093C28(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        return 1;
    }

    return 0;
}

void func_08093C44(u16 a, UnkStruct_08093838* w) {
    u16 i;
    u16 j;
    u8* pal;
    s32 k;
    s32 k2;
    UnkStruct_09EE4C80* card;
    UnkStruct_09EE4C80* cards;

    for (i = 0; i < 22; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09619098[i + 32];
    }

    for (i = 22; i < 32; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09618C58[i + 64];
    }

    for (i = a, j = 2; i < a + 10; i++, j += 2) {
        cards = gUnk_09EE4C80;
        card = &cards[a];
        pal = w->unk_29E;

        if (gUnk_0203A8C0[i] != 0) {
            if (card->unk_1E != 4) {
                pal[j] = -1;
                k = j + 1;
                pal[k] = 0x7F;
            } else {
                pal[j] = gUnk_09618C58[j];
                k2 = j + 1;
                pal[k2] = gUnk_09618C58[k2];
            }
        }
    }

    LoadPalette(w->unk_29E, (void*)0x050001C0, 32);
}

void func_08093D28(u16 a, UnkStruct_08093838* w) {
    u16 i;
    u16 j;
    u8* pal;
    MapcardWork** mp;
    s32 k;

    for (i = 0; i < 22; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09619098[i + 32];
    }

    for (i = 22, j = 2; i < 26; i++, j++) {
        mp = &w->unk_1EC;
        pal = w->unk_29E;

        switch ((*mp)->unk_18->unk_1E) {
        case 1:
            pal[i] = gUnk_09619098[j + 0x60];
            break;
        case 2:
            pal[i] = gUnk_09619098[j + 0x40];
            break;
        case 3:
            pal[i] = gUnk_09619098[j + 0xA0];
            break;
        case 4:
            pal[i] = gUnk_09619098[j + 0x80];
            break;
        }
    }

    for (i = 26; i < 32; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09618C58[i];
    }

    for (i = a, j = 2; i < a + 10; i++, j += 2) {
        pal = w->unk_29E;

        if (gUnk_0203A8C0[i] != 0) {
            pal[j] = -1;
            k = j + 1;
            pal[k] = 0x7F;
        }
    }

    LoadPalette(w->unk_29E, (void*)0x05000180, 32);
}

s32 func_08093E34(u16 a, UnkStruct_08093838* w) {
    u16 i;
    u16 j;
    u8 count;
    u8* src;
    u32 base;

    for (i = a, j = 0; i < a + 10; i++, j++) {
        if (gUnk_0203A8C0[i] != 0) {
            count = gUnk_0203A8C0[i];

            if (count > 9) {
                count = 9;
                gUnk_0203A8C0[i] = count;
            }

            src = &gUnk_09507F38[(count + 1) * 32];
            base = GetBgCharBase(1);
            base += gUnk_09EE4BE0[i - a] * 32;
            RequestDma3Copy(src, (void*)base, 32);
            w->unk_2D0[j] = count;
        } else {
            base = GetBgCharBase(1);
            base += gUnk_09EE4BE0[i - a] * 32;
            RequestDma3Copy(gUnk_09507F58, (void*)base, 32);
            w->unk_2D0[j] = 0;
        }
    }

    for (i = 0; i < 10; i++) {
        if (w->unk_2D0[i] != 0) {
            return (s8)i;
        }
    }

    return -1;
}

s32 func_08093F1C(UnkStruct_08093838* w) {
    u8* p;
    s32 base;
    u8 i;

    i = 4;
    base = (s8)w->unk_29D * 5;
    p = w->unk_2D0;

    do {
        if (p[i + base] == 0) {
            i--;
        } else {
            return (s8)i;
        }
    } while (i != 0);

    return -1;
}
#ifdef NON_MATCHING
void func_08093F5C(u8* work) {
    s8 c0;
    s8 y0;
    s32 z;
    u8* p;

    c0 = work[0x29C];
    y0 = work[0x29D];
    z = 0;

    switch (GetKeysRepeat() & 0xF0) {
    case 16:
        p = &work[0x2D0];

        do {
            if (*(s8*)&work[0x29C] <= 3) {
                *(s8*)&work[0x29C] = *(s8*)&work[0x29C] + 1;
            } else {
                work[0x29C] = 0;
                work[0x29D] ^= 1;
            }
        } while (p[*(s8*)&work[0x29D] * 5 + *(s8*)&work[0x29C]] == 0);

        work[0x28C] = 4;
        break;
    case 32:
        p = &work[0x2D0];

        do {
            if (*(s8*)&work[0x29C] > 0) {
                *(s8*)&work[0x29C] = *(s8*)&work[0x29C] - 1;
            } else {
                work[0x29C] = 4;
                work[0x29D] ^= 1;
            }
        } while (p[*(s8*)&work[0x29D] * 5 + *(s8*)&work[0x29C]] == 0);

        work[0x28C] = 4;
        break;
    case 64:
        work[0x29D] ^= 1;
        c0 = work[0x29C];

        if ((&work[0x2D0])[*(s8*)&work[0x29D] * 5 + *(s8*)&work[0x29C]] == 0) {
            do {
                if (*(s8*)&work[0x29C] > 3) {
                    z = 1;
                    break;
                }

                *(s8*)&work[0x29C] = *(s8*)&work[0x29C] + 1;
                z = 0;
            } while ((&work[0x2D0])[*(s8*)&work[0x29D] * 5 + *(s8*)&work[0x29C]] == 0);
        }

        if (z == 1) {
            work[0x29C] = func_08093F1C((UnkStruct_08093838*)work);

            if (*(s8*)&work[0x29C] == -1) {
                work[0x29D] ^= 1;
                work[0x29C] = c0;
            }
        }

        work[0x28C] = 4;
        break;
    case 128:
        work[0x29D] ^= 1;
        c0 = work[0x29C];

        if ((&work[0x2D0])[*(s8*)&work[0x29D] * 5 + *(s8*)&work[0x29C]] == 0) {
            do {
                if (*(s8*)&work[0x29C] > 3) {
                    z = 1;
                    break;
                }

                *(s8*)&work[0x29C] = *(s8*)&work[0x29C] + 1;
                z = 0;
            } while ((&work[0x2D0])[*(s8*)&work[0x29D] * 5 + *(s8*)&work[0x29C]] == 0);
        }

        if (z == 1) {
            work[0x29C] = func_08093F1C((UnkStruct_08093838*)work);

            if (*(s8*)&work[0x29C] == -1) {
                work[0x29D] ^= 1;
                work[0x29C] = c0;
            }
        }

        work[0x28C] = 4;
        break;
    }

    if (c0 != *(s8*)&work[0x29C] || y0 != *(s8*)&work[0x29D]) {
        m4aSongNumStart(121);
    }

    ApproachValue((s32*)&work[0x258], gUnk_09EE4BB8[*(s8*)&work[0x29C]] << 8,
                  work[0x28C]);
    ApproachValue((s32*)&work[0x25C], gUnk_09EE4BC2[*(s8*)&work[0x29D]] << 8,
                  work[0x28C]);
    ApproachValue((s32*)&work[0x250], gUnk_09EE4BB8[*(s8*)&work[0x29C]] << 8,
                  work[0x28B]);
    ApproachValue((s32*)&work[0x254],
                  (gUnk_09EE4BC2[*(s8*)&work[0x29D]] + 34) << 8, work[0x28B]);

    if (work[0x28B] != 0) {
        work[0x28B]--;
    }

    if (work[0x28C] != 0) {
        work[0x28C]--;
    }
}
#else
INCLUDE_ASM("card/func_08093F5C.s");
#endif
u8 func_0809423C(UnkStruct_08093838* w, void* a) {
    MapcardWork* n;
    u8 v;

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;

    if (!func_080A42C8()) {
        if (w->unk_286 == 8) {
            w->unk_286 = 0;

            if (w->unk_2C2 <= 98) {
                func_080A4188((u8*)w, w->unk_2C2);
                w->unk_2C2++;
            } else {
                n = (MapcardWork*)ListPoolFirst(w->unk_014);
                func_0800516C(1, gUnk_09EE4BB0, 1, 2);

                while (n != 0) {
                    n->unk_6C |= 2;
                    n = (MapcardWork*)ListPoolNext(n->unk_38);
                }

                if (w->unk_27C <= 6) {
                    w->unk_285 = 0;
                } else {
                    v = w->unk_27C / 6;
                    w->unk_285 = v;
                }
                w->unk_25C = 0x6400;
                w->unk_254 = 0x7A00;
                w->unk_244 = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                w->unk_2C0 = 1;
                w->unk_2C2 = 99;
                return 1;
            }
        } else {
            w->unk_286++;
        }
    }

    TaskPoolUpdate(w);
    return 1;
}

u8 func_0809438C(UnkStruct_08093838* w, void* a) {
    u8 r;

    r = func_080A42C8();

    if (r == 0) {
        if (w->unk_286 == 8) {
            w->unk_286 = 0;

            if (w->unk_2C2 <= 0x66) {
                func_080A4188((u8*)w, w->unk_2C2);
                w->unk_2C2++;
            } else {
                gGameState.unk_17A |= 8;
                SetTaskUpdate(a, (void*)func_0809254C);
            }
        } else {
            w->unk_286++;
        }
    }

    TaskPoolUpdate(w);
    return 1;
}

u8 func_08094404(UnkStruct_08093838* w, void* a) {
    MapcardWork* node;
    u32 pages;

    SetObjMosaicSize(w->unk_299, w->unk_29A);
    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }
        if (w->unk_29A != 0) {
            w->unk_29A--;
        }
        w->unk_29B = 0;
    }
    w->unk_29B++;

    if (!func_080A42C8()) {
        if (w->unk_286 == 8) {
            w->unk_286 = 0;
            if (w->unk_2C2 <= 0x71) {
                func_080A4188((u8*)w, w->unk_2C2);
                w->unk_2C2++;
            } else {
                node = ListPoolFirst(w->unk_014);
                func_0800516C(1, gUnk_09EE4BB0, 1, 2);
                while (node != 0) {
                    node->unk_6C |= 2;
                    node = ListPoolNext(node->unk_38);
                }
                if (w->unk_27C <= 6) {
                    w->unk_285 = 0;
                } else {
                    pages = w->unk_27C / 6;
                    w->unk_285 = pages;
                }
                w->unk_25C = 0x6400;
                w->unk_254 = 0x7A00;
                w->unk_244 = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                w->unk_2C0 = 1;
                return 1;
            }
        } else {
            w->unk_286++;
        }
    }
    TaskPoolUpdate(w);
    return 1;
}

MapcardWork* ListPoolLast(void* a);

void func_08094548(UnkStruct_08093838* w) {
    MapcardWork* n;
    s32 v;
    s32 i;

    v = w->unk_23C >> 8;

    for (i = 0; i < 6; i++) {
        if (v == gUnk_09EE7520[i]) {
            break;
        }
    }

    n = func_08000D90(w->unk_1EC->unk_38, w->unk_014);
    w->unk_1EC->unk_6C |= 0x400;
    w->unk_1EC = n;

    while (n != 0) {
        n->unk_21--;

        if (i <= 5) {
            n->unk_4C = gUnk_09EE7520[i] << 8;
            i++;
        }

        n = (MapcardWork*)ListPoolNext(n->unk_38);
    }

    for (n = (MapcardWork*)ListPoolFirst(w->unk_014); n != 0; n = (MapcardWork*)ListPoolNext(n->unk_38)) {
        n->unk_6C |= 2;
    }

    if (w->unk_1EC == 0) {
        w->unk_1EC = ListPoolLast(w->unk_014);

        if (w->unk_1EC == 0) {
            w->unk_264 = 0x1600;
        } else {
            w->unk_264 = w->unk_1EC->unk_4C;
        }
    } else {
        w->unk_264 = w->unk_1EC->unk_4C;
    }
}

void Mapcard_0(MapcardWork* w, MapcardArgs* a) {
    w->unk_00 = 0;
    w->unk_04 = 0;
    w->unk_08 = 0;
    w->unk_0C = 0;
    *(MapcardArgs*)&w->unk_20 = *a;
    w->unk_4C = w->unk_21 <= 5 ? gUnk_09EE7520[w->unk_21] << 8 : -0x6400;
    w->unk_50 = 0x10500;
    w->unk_6A = 50;
    w->unk_5C = 0;
    w->unk_60 = 0;
    w->unk_64 = 0;
    w->unk_6C = 0;
    w->unk_6E = 0;
    w->unk_6F = 16;
    w->unk_70 = 0;
    w->unk_68 = 0x100;
    w->unk_71 = 0;
    w->unk_72 = 0;
    w->unk_74 = gUnk_09EE4C80[w->unk_20].unk_22;
    w->unk_18 = &gUnk_09EE4C80[w->unk_20];
    w->unk_1C = &gUnk_09EE4BF4[w->unk_18->unk_1E];
    func_08094E90(w);
    func_08094DA8(w);
    func_08094CE4(w);
}

u8 func_080947B4(MapcardWork* w, void* a);
s32 func_080948F0(MapcardWork* w, void* a);

u8 Mapcard_1(MapcardWork* w, void* a) {
    if (w->unk_6C & 0xC) {
        w->unk_6F = 12;
        func_08094DEC(w);
        SetTaskUpdate(a, (void*)func_080948F0);
    }

    if (w->unk_6C & 0x200) {
        w->unk_6E = 0;
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_080947B4);
    }

    if (w->unk_6C & 0x40) {
        w->unk_6E = 0;
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_08094934);
    }

    if (w->unk_6C & 0x400) {
        return 0;
    }

    w->unk_6E = 0;
    func_08094DA8(w);
    func_08094CE4(w);
    return 1;
}

u8 func_080947B4(MapcardWork* w, void* a) {
    ApproachValue(&w->unk_4C, gUnk_09EE7520[0] << 8, w->unk_6F);
    w->unk_6F--;

    if (!(w->unk_6C & 0x200)) {
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_0809486C);
    }

    if (w->unk_6C & 0x100) {
        w->unk_6E += 8;
    } else {
        w->unk_6E = 0;
    }

    if (w->unk_6C & 0x40) {
        w->unk_6E = 0;
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_08094934);
    }

    if (w->unk_6C & 0x400) {
        return 0;
    }

    func_08094DA8(w);
    func_08094CE4(w);
    return 1;
}

u8 func_0809486C(MapcardWork* w, void* a) {
    ApproachValue(&w->unk_4C, gUnk_09EE7520[w->unk_21 % 6] << 8, w->unk_6F);
    w->unk_6F--;

    if (w->unk_6F == 0) {
        SetTaskUpdate(a, Mapcard_1);
    }

    if (w->unk_6C & 0x100) {
        w->unk_6E += 8;
    } else {
        w->unk_6E = 0;
    }

    func_08094DA8(w);
    func_08094CE4(w);
    return 1;
}

s32 func_080948F0(MapcardWork* w, void* a) {
    u8 t;

    t = func_08094E4C(w);
    func_08094DA8(w);
    func_08094CE4(w);

    if (t == 0) {
        w->unk_6C &= 0xFFF3;
        SetTaskUpdate(a, Mapcard_1);
    }

    return 1;
}

u8 func_08094934(MapcardWork* w, void* a) {
    w->unk_6E = 0;
    ApproachValue(&w->unk_4C, 0x7800, w->unk_6F);
    ApproachValue(&w->unk_50, 0x3800, w->unk_6F);

    if (w->unk_6F != 0) {
        w->unk_6F--;
    } else {
        w->unk_70++;

        if (w->unk_70 > 15) {
            func_080949A0(w);
            SetTaskUpdate(a, (void*)func_08094A18);
        }
    }

    func_08094CE4(w);
    return 1;
}

void func_080949A0(MapcardWork* w) {
    s32 v[2];
    s32 dx;
    s32 dy;
    s32* p = func_080E04E0();

    dx = (p[0] >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    dy = (p[1] >> 8) + (p[2] >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 24;
    v[0] = dx * 256 - w->unk_4C;
    v[1] = dy * 256 - w->unk_50;
    w->unk_64 = func_0805F5A4(&v[0], &v[1]);
    w->unk_54 = -v[0];
    w->unk_58 = -v[1];
    w->unk_60 = 0x300;
    w->unk_5C = 25;
    w->unk_6E = 0;
    w->unk_68 = 0x100;
}

u8 func_08094A18(MapcardWork* w, void* a) {
    s32* p;
    s32 dx;
    s32 dy;
    s32 d;
    s32 x;
    s32 y;
    u16 t;
    u16 f;

    p = func_080E04E0();
    dx = (p[0] >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    dy = (p[1] >> 8) + (p[2] >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 24;

    if (w->unk_60 < 0) {
        x = (dx << 8) - w->unk_4C;
        y = (dy << 8) - w->unk_50;
        func_0805F5A4(&x, &y);
        w->unk_54 = -x;
        w->unk_58 = -y;
    }

    {
        u8* q = &w->unk_6E;
        *q += 24;
        t = *(u16*)(q - 6);
        *(u16*)(q - 6) = (s16)t > 25 ? t - 12 : 25;
    }
    w->unk_4C += (w->unk_54 * w->unk_60) >> 8;
    w->unk_50 += (w->unk_58 * w->unk_60) >> 8;
    d = func_0805F588((dx << 8) - w->unk_4C, (dy << 8) - w->unk_50);
    w->unk_64 = d;
    w->unk_60 -= w->unk_5C;
    w->unk_5C += 2;

    if ((*(u8**)((u8*)w + 0x24))[0x2BE] != 1) {
        if (d <= 0x7FF) {
            func_08093BE0();
            f = w->unk_6C | 0x80;
            w->unk_6C = f;
            func_08093BEC((u32)&gUnk_09EE4C80[w->unk_20 + w->unk_74] + 0x20);
        }
    } else {
        if (d <= 0x7FF && (*(u8**)((u8*)w + 0x24))[0x2DA] == 0) {
            func_08093BE0();
            f = w->unk_6C | 0x80;
            w->unk_6C = f;
            func_08093BEC((u32)&gUnk_09EE4C80[w->unk_20 + w->unk_74] + 0x20);
        }
    }

    return 1;
}

#ifdef NON_MATCHING
void Mapcard_2(MapcardWork* w) {
    s32 aff;
    u16 y;

    if (func_080A42C8() == 0) {
        y = (w->unk_50 >> 8) + (gSineTable[w->unk_6E] >> 8);

        if (w->unk_6C & 1) {
            if (w->unk_4C > 0 && w->unk_4C <= 0xEFFF) {
                aff = 0;

                if (w->unk_6C & 0x40) {
                    aff = AllocObjAffine(w->unk_6E, (s16)w->unk_68, (s16)w->unk_68, 1);
                }

                if (gUnk_09EE4C80[w->unk_20].unk_1E == 4) {
                    DrawSprite(w->unk_4C >> 8, y, gUnk_0203A890[4], gUnk_0203A890[0], *(void**)&w->unk_10[4], aff, 0,
                               (u16)(w->unk_6A - 2));
                }

                DrawSprite(w->unk_4C >> 8, y, *(void**)*(void**)&w->unk_1C->unk_00[8], *(void**)&w->unk_10[0],
                           *(void**)&w->unk_10[4], aff, 0, w->unk_6A);
                DrawSprite(w->unk_4C >> 8, y, *(void**)*(void**)&w->unk_18->unk_00[8], w->unk_08, w->unk_0C, aff, 0,
                           (u16)(w->unk_6A + 1));
            }
        }
    }
}
#else
INCLUDE_ASM("card/Mapcard_2.s");
#endif
void Mapcard_3(MapcardWork* w) {
    if (w->unk_6C & 1) {
        ReleaseObjTiles(w->unk_08);
        ReleaseObjPalette(w->unk_0C);
        ReleaseObjTiles(*(void**)&w->unk_10[0]);
        ReleaseObjPalette(*(void**)&w->unk_10[4]);
    }
}

u8 func_08094CB0(s32* p) {
    if (p[19] >= -4096) {
        if (p[19] <= 0x10000) {
            if (p[20] >= -5120) {
                if (p[20] <= 0xC000) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void func_08094CE4(MapcardWork* w) {
    UnkStruct_08094CE4_A* a;
    UnkStruct_08094CE4_B* b;
    u16 t;

    if (func_08094CB0((s32*)w)) {
        if (!(w->unk_6C & 1)) {
            a = (UnkStruct_08094CE4_A*)w->unk_18;
            b = (UnkStruct_08094CE4_B*)w->unk_1C;
            w->unk_08 = LoadObjTiles(a->unk_00, a->unk_18);
            w->unk_0C = LoadObjPalette(a->unk_04, 32);
            *(void**)&w->unk_10[0] = LoadObjTiles(b->unk_00, b->unk_14);
            *(void**)&w->unk_10[4] = LoadObjPalette(b->unk_04, 32);
            w->unk_00 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
            func_080062F4(((UnkStruct_080038C8*)w->unk_0C)->unk_06 + 16, 1);
            func_080062F4(((UnkStruct_080038C8*)*(void**)&w->unk_10[4])->unk_06 + 16, 1);
            t = w->unk_6C | 1;
            w->unk_6C = t;
        }
    } else if (w->unk_6C & 1) {
        ReleaseObjTiles(w->unk_00);
        ReleaseObjTiles(w->unk_08);
        ReleaseObjPalette(w->unk_0C);
        ReleaseObjTiles(*(void**)&w->unk_10[0]);
        ReleaseObjPalette(*(void**)&w->unk_10[4]);
        w->unk_6C &= ~1;
    }
}

void func_08094DA8(MapcardWork* w) {
    if (w->unk_6C & 2) {
        ApproachValue(&w->unk_50, 0x7900, w->unk_6F);
    } else {
        ApproachValue(&w->unk_50, 0x10500, w->unk_6F);
    }

    if (w->unk_6F != 0) {
        w->unk_6F--;
    }
}
void func_08094DEC(MapcardWork* w) {
    if ((w->unk_6C & 4) && w->unk_60 - w->unk_5C > 0x8000) {
        w->unk_5C += 0x10000;
    }

    if ((w->unk_6C & 8) && w->unk_60 < w->unk_5C) {
        w->unk_5C -= 0x10000;
    }

    ApproachValue(&w->unk_5C, w->unk_60, w->unk_6F);
    w->unk_6F--;
}
u8 func_08094E4C(MapcardWork* w) {
    ApproachValue(&w->unk_5C, w->unk_60, w->unk_6F);

    if (w->unk_6F != 0) {
        w->unk_6F--;
        return 1;
    }

    return 0;
}
void* func_08094E78(void* a, void* b) {
    return ((void**)TaskCreate(b, gTaskDescMapcard, a))[1];
}
void func_08094E90(MapcardWork* w) {
    func_08000D20(&w->unk_38, w->unk_28, w);
    func_08000D28(&w->unk_38, w->unk_28);
}
void func_08094EB0(ReloadGageWork* w, ReloadGageArgs* a) {
    UnkStruct_08095A5C* d;
    UnkStruct_080988C0_Args args;
    u16 v;
    s8 n;
    s8 i;

    w->unk_00 = 0;
    w->unk_04 = 0;
    w->unk_0C = 0;
    w->unk_08 = 0;
    w->unk_10 = 0;
    w->unk_14 = 0;
    w->unk_A1 = 0;
    *(ReloadGageArgs*)&w->unk_38 = *a;
    w->unk_78 = 0;
    w->unk_9C = 16;
    w->unk_84 = 0;
    w->unk_9F = 0;
    w->unk_A0 = 4;
    w->unk_88 = 0x2400;
    w->unk_80 = 0;
    w->unk_7C = 0;
    w->unk_20 = EwramAlloc(0x68);
    w->unk_A2 = 0;
    w->unk_A3 = 0;
    d = w->unk_20;
    v = a->unk_0C;

    if ((s16)v >= 0) {
        d->unk_64 = v;
    } else {
        d->unk_64 = -1;
    }

    if (d->unk_64 > 17) {
        d->unk_64 = 18;
    }

    d->unk_65 = 0;
    w->unk_1C = EwramAlloc(0x10);

    switch (w->unk_40) {
    case 1:
        w->unk_8C = gUnk_09033FF4[0][0];
        w->unk_90 = gUnk_09033FF4[0][1];
        w->unk_4C = gUnk_09033FF4[4][0];
        w->unk_50 = gUnk_09033FF4[4][1];
        w->unk_94 = w->unk_98 = 0x2000;
        w->unk_78 |= 0x8000000;
        break;
    case 2:
        w->unk_8C = gUnk_0903401C[0][0];
        w->unk_90 = gUnk_0903401C[0][1];
        w->unk_4C = gUnk_0903401C[4][0];
        w->unk_50 = gUnk_0903401C[4][1];
        w->unk_94 = w->unk_98 = -0x2000;
        break;
    }

    w->unk_54 = 0x100;
    w->unk_58 = 0;
    ListPoolInit(w->unk_1C);
    func_08000D20(&w->unk_64, w->unk_38, w);
    func_08000D28(&w->unk_64, w->unk_38);
    w->unk_04 = LoadObjTiles(gUnk_09EE75A8[w->unk_46], 0x280);
    w->unk_08 = AllocObjTiles(0x200, 0);
    func_08002A10(w->unk_08, gUnk_09EE75A8[1]);
    w->unk_0C = AllocObjTiles(0x80, 0);
    func_08002A10(w->unk_0C, gUnk_09EE75A8[1]);
    func_08095B50(w->unk_20, w, w->unk_46);
    w->unk_00 = LoadObjTiles(gUnk_0905F03C, 0x80);
    w->unk_14 = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_10 = AllocObjTiles(0x100, 0);
    func_08002A10(w->unk_10, gUnk_09EE7578[w->unk_46]);
    func_08095A78(w->unk_20, w->unk_10, w->unk_46, d->unk_64);
    w->unk_78 |= 0x1000026;

    if (d->unk_64 >= 0) {
        TaskPoolInit(&w->unk_24, d->unk_64 + 1);
        n = d->unk_64;

        if (d->unk_64 > 3) {
            n = 3;
        }

        for (i = 0; i < n; i++) {
            args.unk_00 = w->unk_1C;
            args.unk_0C = i;
            args.unk_04 = &w->unk_4C;
            args.unk_08 = &w->unk_50;
            *(u16*)args.unk_10 = 0;
            args.unk_0D = w->unk_46;
            args.unk_0E = w->unk_40;
            TaskCreate(&w->unk_24, gTaskDescReloadChildren, &args);
        }
    } else {
        TaskPoolInit(&w->unk_24, 1);
    }
}
#ifdef NON_MATCHING
u8 func_0809511C(ReloadGageWork* w, void* a) {
    UnkStruct_080988C0_Args args;
    UnkStruct_08095A5C* p;
    UnkStruct_08098BE8* node;
    u8 v;

    p = w->unk_20;
    v = 0;

    switch (w->unk_40) {
    case 1:
        if (gUnk_02039DD4->unk_0D2 == w->unk_46) {
            v = gUnk_02039DD4->unk_0E7;
            gUnk_02039DD4->unk_0E7 = 0;
        }
        break;
    case 2:
        if (gUnk_02039DD4->unk_0D4 == w->unk_46) {
            v = gUnk_02039DD4->unk_0E8;
            gUnk_02039DD4->unk_0E8 = 0;
        }
        break;
    }

    if ((w->unk_78 & 0x44) == 0x44) {
        if (v == 1) {
            if ((s8)p->unk_65 == 2) {
                switch (w->unk_40) {
                case 1:
                    if ((gBtlWork->unk_068 & 0x1000000) == 0) {
                        m4aSongNumStart(200);
                        gBtlWork->unk_068 |= 0x1000000;
                    }
                    break;
                case 2:
                    if ((gUnk_02039B9C->unk_068 & 0x1000000) == 0) {
                        m4aSongNumStart(200);
                        gUnk_02039B9C->unk_068 |= 0x1000000;
                    }
                    break;
                }

                node = (UnkStruct_08098BE8*)ListPoolFirst(w->unk_1C);

                while (node != 0) {
                    node->unk_1C &= 0xFFFD;
                    node = (UnkStruct_08098BE8*)ListPoolNext(node->unk_30);
                }

                if (w->unk_9F == 0) {
                    w->unk_58 += 25;

                    if (w->unk_58 > 0x100) {
                        w->unk_58 = 0x100;
                        w->unk_9F = 1;
                    }
                } else {
                    w->unk_A0 += 3;
                    func_08095C00(w->unk_20, w);

                    if (w->unk_A0 == 10) {
                        w->unk_A0 = 4;
                        w->unk_58 = 0;
                        w->unk_9F = 0;
                        node = (UnkStruct_08098BE8*)ListPoolFirst(w->unk_1C);

                        while (node != 0) {
                            node->unk_1C |= 1;
                            node->unk_18--;
                            node = (UnkStruct_08098BE8*)ListPoolNext(node->unk_30);
                        }

                        p->unk_64--;

                        if (p->unk_64 > 2) {
                            args.unk_00 = w->unk_1C;
                            args.unk_0C = 3;
                            args.unk_04 = &w->unk_4C;
                            args.unk_08 = &w->unk_50;
                            *(u16*)args.unk_10 = 0;
                            args.unk_0D = w->unk_46;
                            args.unk_0E = w->unk_40;
                            node = ((UnkStruct_08098BE8**)TaskCreate(&w->unk_24, gTaskDescReloadChildren, &args))[1];
                            node->unk_1C = (1 | node->unk_1C) & 0xFFFD;
                            node->unk_18--;
                        }

                        w->unk_9C = 8;
                        w->unk_A2 = 1;
                        func_08095C20(w->unk_20);
                        m4aSongNumStart(201);
                    }
                }

                switch (w->unk_40) {
                case 1:
                    switch (gBtlWork->unk_0F4) {
                    case 9:
                        p->unk_65 = 1;
                        break;
                    case 43:
                        p->unk_65 = 254;
                        break;
                    default:
                        p->unk_65 = 0;
                        break;
                    }
                    break;
                case 2:
                    switch (gUnk_02039B9C->unk_0F4) {
                    case 9:
                        p->unk_65 = 1;
                        break;
                    case 43:
                        p->unk_65 = 254;
                        break;
                    default:
                        p->unk_65 = 0;
                        break;
                    }
                    break;
                }
            }

            func_08095BAC(w->unk_20, w);
            p->unk_65++;
        } else {
            func_08095BC8(w->unk_20, w);
            p->unk_65 = 0;
            w->unk_78 |= 0x8000000;
            m4aSongNumStop(200);

            switch (w->unk_40) {
            case 1:
                gBtlWork->unk_068 &= ~0x1000000;
                break;
            case 2:
                gUnk_02039B9C->unk_068 &= ~0x1000000;
                break;
            }

            node = (UnkStruct_08098BE8*)ListPoolFirst(w->unk_1C);

            while (node != 0) {
                node->unk_1C |= 2;
                node = (UnkStruct_08098BE8*)ListPoolNext(node->unk_30);
            }
        }
    }

    if (p->unk_64 < 0) {
        if ((w->unk_78 & 0x4000000) == 0) {
            w->unk_78 |= 0x4000000;
            m4aSongNumStart(202);
        }

        if (func_08006390() == 0) {
            func_08006290(2, 16, 20);
        }

        return 0;
    }

    func_08095B04(w->unk_20, w);

    if (w->unk_A2 == 1 && w->unk_9C == 1) {
        func_08095AD8(w->unk_20, p->unk_64);
    }

    func_080958E0(w);

    if (w->unk_78 & 0x4000) {
        return 0;
    }

    func_08095A5C(w->unk_20);
    w->unk_5C[3] += 4;

    if ((w->unk_78 & 0x20) == 0) {
        SetTaskUpdate(a, (void*)func_080954C4);
        m4aSongNumStop(200);

        switch (w->unk_40) {
        case 1:
            gBtlWork->unk_068 &= ~0x1000000;
            break;
        case 2:
            gUnk_02039B9C->unk_068 &= ~0x1000000;
            break;
        }
    }

    TaskPoolUpdate(&w->unk_24);
    return 1;
}
#else
INCLUDE_ASM("card/func_0809511C.s");
#endif
u8 func_080954C4(ReloadGageWork* w, void* a) {
    if (w->unk_A1 == 7) {
        return 0;
    }

    w->unk_84 += -w->unk_84 >> 1;
    w->unk_4C += (gUnk_09033FF4[4][0] - w->unk_4C) >> 1;
    w->unk_50 += (gUnk_09033FF4[4][1] - w->unk_50) >> 1;

    if (w->unk_78 & 0x20) {
        SetTaskUpdate(a, (void*)func_0809511C);
    }

    return 1;
}
void func_08095520(UnkStruct_02034AAC* p) {
    u8* q;
    s32 affine;
    void* gfx;
    s32 t;

    q = p->unk_20;
    gfx = gUnk_08F709B0[p->unk_46].unk_04;
    DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
               (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
               gfx, p->unk_04,
               gUnk_02039DD4->palette, 0, 0x400, 50);

    if (p->unk_58 > 0) {
        affine = AllocObjAffine(0, 0x100, p->unk_58, 0);
        DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
                   (p->unk_50 >> 8) + (t = (gSineTable[p->unk_5F] >> 8) + 17),
                   *(void**)&q[0x58], p->unk_08, gUnk_02039DD4->palette, affine,
                   0x400, 49);

        if (p->unk_9F == 1) {
            DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
                       (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                       *(void**)&q[0x5C], p->unk_0C, gUnk_02039DD4->palette, 0,
                       0x400, 49);
        }
    }

    if (*(void**)&q[0x60] != 0) {
        DrawSprite((p->unk_4C >> 8) + (*(s32*)&q[4] >> 8),
                   (p->unk_50 >> 8) + (gSineTable[p->unk_5F] >> 8),
                   *(void**)&q[0x60], *(void**)&p->unk_10[0],
                   gUnk_02039DD4->palette, 0, 0x400, 48);
    }

    TaskPoolDraw(&p->unk_24[0]);
}
void func_080956AC(UnkStruct_02034AAC* p) {
    TaskPoolDestroy(&p->unk_24[0]);
    ReleaseObjPalette(p->palette);
    ReleaseObjTiles(p->unk_00);
    ReleaseObjTiles(p->unk_04);
    ReleaseObjTiles(p->unk_08);
    ReleaseObjTiles(p->unk_0C);
    ReleaseObjTiles(*(void**)&p->unk_10[0]);
    EwramFree(*(void**)&p->unk_1C[0]);
    EwramFree(p->unk_20);

    switch (*(s32*)&p->unk_3C[4]) {
    case 1:
        gBtlWork->unk_068 &= ~0x1000000;

        switch (gBtlWork->unk_0F4) {
        case 9:
        case 10:
        case 25:
        case 30:
        case 40:
        case 43:
        case 54:
            gBtlWork->unk_0F8--;
            break;
        }
        break;
    case 2:
        gUnk_02039B9C->unk_068 &= ~0x1000000;

        switch (gUnk_02039B9C->unk_0F4) {
        case 9:
        case 10:
        case 25:
        case 30:
        case 40:
        case 43:
        case 54:
            gUnk_02039B9C->unk_0F8--;
            break;
        }
        break;
    }

    func_08000D90(&p->unk_64[0], p->unk_38);
}
void func_080958E0(ReloadGageWork* w) {
    ApproachValue(&w->unk_94, w->unk_98, w->unk_A3);
    if (w->unk_A3 != 0) {
        w->unk_A3--;
    }
    w->unk_84 += (w->unk_88 - w->unk_84) >> 1;
    if (w->unk_9C > 0) {
        w->unk_9C--;
        w->unk_78 &= ~0x40;
    } else {
        w->unk_9C = 0;
        w->unk_78 |= 0x40;
    }

    switch (w->unk_40) {
    case 1:
        w->unk_8C = gSineTable[(w->unk_94 >> 8) & 0xFF] * 80 + gUnk_09033FF4[0][0];
        w->unk_90 = -gSineTable[((w->unk_94 >> 8) & 0xFF) + 0x40] * 80 + gUnk_09033FF4[0][1];
        w->unk_4C = gSineTable[0x20] * (w->unk_84 >> 8) + w->unk_8C;
        w->unk_50 = -gSineTable[0x60] * (w->unk_84 >> 8) + w->unk_90;
        break;
    case 2:
        w->unk_8C = gSineTable[(w->unk_94 >> 8) & 0xFF] * 80 + gUnk_0903401C[0][0];
        w->unk_90 = -gSineTable[((w->unk_94 >> 8) & 0xFF) + 0x40] * 80 + gUnk_0903401C[0][1];
        w->unk_4C = gSineTable[0xE0] * (w->unk_84 >> 8) + w->unk_8C;
        w->unk_50 = -gSineTable[0x120] * (w->unk_84 >> 8) + w->unk_90;
        break;
    }
}
void func_08095A5C(UnkStruct_08095A5C* p) {
    p->unk_00 = gSineTable[(u8)p->unk_02] >> 8;
    p->unk_02 += 16;
}
void func_08095A78(UnkStruct_08095A5C* p, void* a, u8 b, u8 c) {
    AnimInit(&p->unk_10, gUnk_09EE7588[b], gUnk_09EE7598[b]);

    if ((s8)c >= 0) {
        AnimStart(&p->unk_10, (u16)(s8)c, 0);
    } else {
        AnimStart(&p->unk_10, 0, 0);
    }

    p->unk_60 = AnimGetGfx(&p->unk_10);
}
void func_08095AD8(UnkStruct_08095A5C* p, u16 a) {
    void* gfx;

    if (a <= 18) {
        AnimStart(&p->unk_10, a, 0);
        gfx = AnimGetGfx(&p->unk_10);
    } else {
        gfx = 0;
    }

    p->unk_60 = gfx;
}
s32 func_08095B04(u8* p, ReloadGageWork* w) {
    if (w->unk_9C > 0 && w->unk_A2 == 1) {
        switch (w->unk_40) {
        case 1:
            ApproachValue(&p[4], -0x3000, (u16)w->unk_9C);
            break;
        case 2:
            ApproachValue(&p[4], 0x12000, (u16)w->unk_9C);
            break;
        }
    } else {
        *(u32*)&p[4] = 0;
    }
}
void func_08095B50(UnkStruct_08095A5C* p, ReloadGageWork* w, u8 idx) {
    p->unk_0D = 2;
    AnimInit(&p->unk_28, gUnk_09EE75C8[idx], gUnk_09EE75B8[idx]);
    AnimStart(&p->unk_28, 1, 1);
    p->unk_58 = gUnk_09EE75B8[idx][3];
    AnimInit(&p->unk_40, gUnk_09EE75C8[idx], gUnk_09EE75B8[idx]);
    AnimStart(&p->unk_40, 2, 1);
    p->unk_5C = gUnk_09EE75B8[idx][6];
}
void func_08095BAC(UnkStruct_08095A5C* p) {
    p->unk_58 = AnimUpdate(&p->unk_28);
    p->unk_5C = AnimUpdate(&p->unk_40);
}
void func_08095BC8(UnkStruct_08095A5C* p, ReloadGageWork* w) {
    p->unk_58 = gUnk_09EE75B8[w->unk_46][3];
    p->unk_5C = gUnk_09EE75B8[w->unk_46][w->unk_A0 + 2];
}
void func_08095C00(UnkStruct_08095A5C* p) {
    if (p->unk_0D <= 3) {
        p->unk_0D++;
    }

    AnimStart(&p->unk_40, p->unk_0D, 5);
}
void func_08095C20(u8* p) {
    p[13] = 2;
}
void* func_08095C28(u8* w, u16 b, void* pool, u8 mode) {
    ReloadGageArgs args;

    args.unk_00 = &w[(s8)w[0xB8] * 16 + 0x54];
    args.unk_04 = 0;

    switch (mode) {
    case 1:
        if (gBtlWork->unk_0F4 == 10) {
            args.unk_0C = b - 2;
        } else {
            args.unk_0C = b;
        }
        break;
    case 2:
        if (gUnk_02039B9C->unk_0F4 == 10) {
            args.unk_0C = b - 2;
        } else {
            args.unk_0C = b;
        }
        break;
    }

    args.unk_08 = mode;
    args.unk_0E = w[0xB8];
    return ((void**)TaskCreate(pool, gUnk_09EE7560, &args))[1];
}
void PrizeCard_0(PrizeCardWork* w, PrizeCardTaskArgs* p) {
    PrizeCardTaskArgs args;
    CardDef* def;
    CardBack* back;
    u8* q;

    args = *p;
    w->unk_C8 = args.unk_20;
    def = &gCardDefs[args.unk_20];
    w->unk_00 = LoadObjTiles(def->unk_04, 0x300);
    w->unk_04 = LoadObjPalette(def->unk_08, 32);
    *(UnkStruct_08099412*)&w->unk_20[0x14] = *(UnkStruct_08099412*)&def->unk_1C;

    if (gCardDefs[w->unk_C8].unk_1E & 12) {
        back = &gUnk_08F709B0[3];
    } else {
        back = &gUnk_08F709B0[w->unk_20[0x22]];
    }

    w->unk_08 = LoadObjTiles(back->unk_0C, 0x280);
    w->unk_0C = LoadObjTiles(*(void**)back->unk_14, 0x600);
    w->unk_10 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_14 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_18 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_1C = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_A8 = args.unk_00;
    w->unk_AC = args.unk_04;
    *(s32*)&w->unk_B0[0] = args.unk_08;
    *(s32*)&w->unk_B0[4] = 0;
    w->unk_F6 = 24;
    func_080DFF4C(&w->unk_A8);
    w->unk_CC = -(GetRandom() % 129 + 0x300);
    w->unk_D0 = GetRandom() % 129 + 0x80;
    w->unk_F4 = GetRandom() % 256;
    w->unk_E0 = 0x80;
    w->unk_E2 = 0x80;
    w->unk_F2 = 0x80;
    w->unk_F7 = 0;
    w->unk_F8 = 0;
    q = &w->unk_4C[0];
    func_080122AC(q, 5, 30, 10);
    func_08012614(q, 1);
    func_08012324(q, w->unk_A8, w->unk_AC, *(s32*)&w->unk_B0[0]);
    w->unk_F9 = 0;
    w->unk_FC[0] = 0;
    w->unk_FA = 0;
    w->unk_FB = 0;
    TaskPoolInit((TaskPool*)w->unk_20, 1);
}
u8 func_08095E68(PrizeCardWork* w, void* a) {
    s32 k = 112;
    s16 x;
    s16 y;

    *(FldPos*)&w->unk_B0[8] = *(FldPos*)&w->unk_A8;
    w->unk_CC += 0x38;
    *(s32*)&w->unk_B0[0] += w->unk_CC;
    w->unk_A8 += (gSineTable[(u8)w->unk_F4] * w->unk_D0) >> 8;
    w->unk_AC += (-gSineTable[(u8)w->unk_F4 + 0x40] * w->unk_D0) >> 8;

    if (func_080DFBDC((FldPos*)&w->unk_A8) != 0) {
        w->unk_F4 = w->unk_F4 + k + GetRandom() % 33;

        do {
            w->unk_A8 = *(s32*)&w->unk_B0[8];
            w->unk_AC = *(s32*)&w->unk_B0[0xC];
        } while (0);
    } else {
        *(s32*)&w->unk_B0[4] = func_080DFF1C((FldPos*)&w->unk_A8);
    }

    if (*(s32*)&w->unk_B0[0] - 0x800 > *(s32*)&w->unk_B0[4]) {
        *(s32*)&w->unk_B0[0] = *(s32*)&w->unk_B0[4] - 0x800;
        w->unk_CC = -((w->unk_CC * 217) >> 8);

        if (w->unk_CC > -0x200) {
            w->unk_CC = -0x200;
        }
    }

    if (w->unk_4C[0x2C] != 0) {
        w->unk_FC[0] = 1;
        m4aSongNumStart(0x6A);

        if (w->unk_C8 <= 0x1C1) {
            func_08084458(w->unk_C8);
        }

        SetTaskUpdate(a, (void*)func_0809612C);
        x = (w->unk_A8 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        y = (w->unk_AC >> 8) + (*(s32*)&w->unk_B0[0] >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        w->unk_A8 = x << 8;
        w->unk_AC = y << 8;
        func_08012614(&w->unk_4C[0], 1);
        w->unk_FA = 16;
        w->unk_E4 = 50;
        func_080960D8(w);
        return 1;
    }

    func_08012324(&w->unk_4C[0], w->unk_A8, w->unk_AC, *(s32*)&w->unk_B0[0]);
    w->unk_E6 = (w->unk_A8 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    w->unk_E8 = (w->unk_AC >> 8) + (*(s32*)&w->unk_B0[0] >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    w->unk_EE = (w->unk_A8 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    w->unk_F0 = (w->unk_AC >> 8) + (*(s32*)&w->unk_B0[4] >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    w->unk_E4 = -0x1004 - (w->unk_AC >> 8) * 4;
    func_08096638(w);
    w->unk_F8 += 2;

    if (w->unk_F9 == 20) {
        func_08012614(&w->unk_4C[0], 0);
    }

    if (w->unk_F9 <= 59) {
        w->unk_F9++;
    }

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        return 0;
    }

    return 1;
}
void func_080960D8(PrizeCardWork* w) {
    s32 cx = 0x7800;
    s32 cy = 0x5000;
    s32 v[2];

    v[0] = cx - w->unk_A8;
    v[1] = cy - w->unk_AC;
    w->unk_DC = func_0805F5A4(&v[0], &v[1]);
    w->unk_D4 = -v[0];
    w->unk_D8 = -v[1];
    w->unk_D0 = 0x300;
    w->unk_CC = 2;
}
u8 func_0809612C(PrizeCardWork* w, void* a) {
    s32 v[2];

    if (w->unk_D0 < 0) {
        v[0] = 0x7800 - w->unk_A8;
        v[1] = 0x5000 - w->unk_AC;
        func_0805F5A4(&v[0], &v[1]);
        w->unk_D4 = -v[0];
        w->unk_D8 = -v[1];

        if (w->unk_DC <= 0x7FF) {
            w->unk_FA = 0;
            w->unk_F6 = 0;
            SetTaskUpdate(a, (void*)func_08096288);
#ifdef VERSION_EU
            func_08096F08(&w->unk_20, eu_0805E924(gCardDefs[w->unk_C8].unk_0C));
#else
            func_08096F08(&w->unk_20, gCardDefs[w->unk_C8].unk_0C);
#endif
        }
    }

    w->unk_A8 += (w->unk_D4 * w->unk_D0) >> 8;
    w->unk_AC += (w->unk_D8 * w->unk_D0) >> 8;
    w->unk_F6 += 32;
    w->unk_F7 += (64 - w->unk_F7) >> 4;
    w->unk_F8 = 0;
    w->unk_DC = func_0805F588(0x7800 - w->unk_A8, 0x5000 - w->unk_AC);
    w->unk_D0 -= w->unk_CC;
    w->unk_CC += 2;

    if (w->unk_F2 <= 255) {
        w->unk_F2 += 3;
    }

    w->unk_E6 = w->unk_A8 >> 8;
    w->unk_E8 = w->unk_AC >> 8;
    func_08096638(w);

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        return 0;
    }

    return 1;
}
u8 func_08096288(PrizeCardWork* w, void* a) {
    s32 v;

    v = w->unk_F6 << 8;
    ApproachValue(&w->unk_F7, 0, w->unk_FA);
    ApproachValue(&v, 0, w->unk_FA);
    ApproachValue(&w->unk_A8, 0x7800, w->unk_FA);
    ApproachValue(&w->unk_AC, 0x5800, w->unk_FA);
    w->unk_F6 = v >> 8;

    if (w->unk_FA != 0) {
        w->unk_FA--;
    }

    if (w->unk_F2 <= 255) {
        w->unk_F2 += 2;
    } else {
        w->unk_F2 = 256;
    }

    w->unk_E6 = w->unk_A8 >> 8;
    w->unk_E8 = w->unk_AC >> 8;
    func_08096638(w);
    w->unk_FB++;

    if (w->unk_C8 > 0x1C2) {
        if (w->unk_FB == 120) {
            w->unk_FB = 0;
            SetTaskUpdate(a, (void*)func_08096390);
        }
    } else if (w->unk_FB == 30) {
        w->unk_FB = 0;
        SetTaskUpdate(a, (void*)func_08096390);
    }

    TaskPoolUpdate(&w->unk_20);

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        return 0;
    }

    return 1;
}
u8 func_08096390(PrizeCardWork* w) {
    w->unk_F6 += 32;
    w->unk_EA = (gUnk_02039BA0->unk_18 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    w->unk_EC = (gUnk_02039BA0->unk_1C >> 8) + (gUnk_02039BA0->unk_20 >> 8) -
                (gUnk_02039BA0->unk_04 >> 8);
    w->unk_E6 += (w->unk_EA - w->unk_E6) >> 3;
    w->unk_E8 += (w->unk_EC - w->unk_E8) >> 3;
    w->unk_E0 -= 10;
    w->unk_E2 -= 10;

    if (w->unk_E0 > 10 && !(gUnk_02039BA0->unk_70 & 0x40000)) {
        return 1;
    }

    return 0;
}
void func_08096428(PrizeCardWork* w) {
    u16 pal;
    s32 affine;
    void* gfx;
    CardBack* back;
    CardDef* def;
    s16 v;
    s32 t;

    t = w->unk_FC[0];
    pal = 0;

    if (t == 0) {
        pal = 0x800;
    }

    if (w->unk_E0 == 0x100 && w->unk_F6 == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_F6, w->unk_E0, w->unk_E2, 1);
    }

    def = &gCardDefs[w->unk_C8];
    DrawSprite(w->unk_E6, (u16)w->unk_E8 - 8, def->unk_00, w->unk_00, w->unk_04,
               affine, pal, (u16)(w->unk_E4 + 1));
    back = &gUnk_08F709B0[w->unk_20[0x22]];
    DrawSprite(w->unk_E6, (u16)w->unk_E8 - 8, back->unk_00, w->unk_08, w->unk_10,
               affine, pal, (u16)w->unk_E4);
    gfx = gUnk_09EE981C[w->unk_20[0x18]];
    DrawSprite(w->unk_E6, (u16)w->unk_E8 - 8, gfx, w->unk_14, w->unk_10, affine,
               pal, (u16)(w->unk_E4 - 1));

    if (w->unk_FC[0] == 0) {
        v = 204 - ((*(s32*)&w->unk_B0[4] - *(s32*)&w->unk_B0[0]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(w->unk_EE, w->unk_F0, gUnk_09EE1380[0],
                   w->unk_18, w->unk_1C, AllocObjAffine(0, v, v, 0), pal,
                   (u16)(w->unk_E4 + 2));
    }

    TaskPoolDraw(w->unk_20);
}

void func_080965CC(PrizeCardWork* w) {
    func_080062F4(w->unk_10->unk_06 + 16, 0);
    func_080062F4(w->unk_04->unk_06 + 16, 0);
    func_08012304(w->unk_4C);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjTiles(w->unk_0C);
    ReleaseObjTiles(w->unk_18);
    ReleaseObjPalette(w->unk_04);
    ReleaseObjPalette(w->unk_10);
    ReleaseObjPalette(w->unk_1C);
    TaskPoolDestroy(w->unk_20);
}

void func_08096638(PrizeCardWork* w) {
    w->unk_E0 = (-gSineTable[((w->unk_F8 + 0x80) & 0xFF) + 0x40] * w->unk_F2) >> 8;
    w->unk_E2 = (-gSineTable[((w->unk_F7 + 0x80) & 0xFF) + 0x40] * w->unk_F2) >> 8;

    if ((u16)(w->unk_E0 + 2) <= 4) {
        w->unk_E0 = 2;
    }

    if ((u16)(w->unk_E2 + 2) <= 4) {
        w->unk_E2 = 2;
    }
}

void func_080966B4(void* a, s32 b, s32 c, s32 d) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = func_08096D48(gGameState.unk_00C[0], 0);
    func_08096700(a, args);
}
void func_080966E4(void* a, s32 b, s32 c, s32 d, s32 e) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = e;
    func_08096700(a, args);
}

void func_08096700(void* a, void* b) {
    TaskCreate(a, gUnk_09EE75D8, b);
}

void func_08096714(PrizeCardInitWork* w, PrizeCardArgs* args) {
    w->unk_14 = 0;
    w->unk_18 = *args;
    TaskPoolInit(w, 1);
}

#ifndef VERSION_EU
s32 PrizeCardInit_1(PrizeCardInitWork* w) {
    s32 args[9];
    s32 v;

    if (w->unk_14 == 0) {
        if ((gGameState.unk_17A & 0x20) == 0) {
            *(PrizeCardArgs*)args = w->unk_18;
            args[8] = 2;
            func_0809797C(w, args);
            gGameState.unk_17A |= 0x20;
        } else if ((s8)gGameState.unk_00C[2] == 0) {
            if (func_08093B58() == 0) {
                *(PrizeCardArgs*)args = w->unk_18;
                args[8] = func_08096D0C(gGameState.unk_00C[0], 1);

                if (args[8] != 0xFFFF) {
                    func_0809797C(w, args);
                } else {
                    return 0;
                }
            } else {
                *(PrizeCardArgs*)args = w->unk_18;
                args[8] = func_08096D48(gGameState.unk_00C[0], 1);

                if (args[8] != 0xFFFF) {
                    func_0809797C(w, args);
                } else {
                    return 0;
                }
            }
        } else {
            v = *(s32*)&gBtlWork->unk_100[0xC];

            if (v >= 125 && v <= 127) {
                if ((gGameState.flags & 8) == 0) {
                    if (GetRandom() % 100 < 20) {
                        *(PrizeCardArgs*)args = w->unk_18;
                        args[8] = GetRandom() % 10 + 210;
                    } else {
                        *(PrizeCardArgs*)args = w->unk_18;
                        args[8] = func_08096D48(gGameState.unk_00C[0], 1);
                    }

                    if (args[8] != 0xFFFF) {
                        func_0809797C(w, args);
                    } else {
                        return 0;
                    }
                } else {
                    *(PrizeCardArgs*)args = w->unk_18;
                    args[8] = func_08096D48(gGameState.unk_00C[0], 1);

                    if (args[8] != 0xFFFF) {
                        func_0809797C(w, args);
                    } else {
                        return 0;
                    }
                }
            } else if (v >= 131 && v <= 133) {
                *(PrizeCardArgs*)args = w->unk_18;
                args[8] = GetRandom() % 10 + 160;
                func_0809797C(w, args);
            } else {
                *(PrizeCardArgs*)args = w->unk_18;

                if ((gGameState.flags & 8) == 0) {
                    if (func_08093C28(0xFB) == 0) {
                        if (func_080E924C() == 0) {
                            if (gUnk_0903612C[gGameState.unk_00C[0]] != 0) {
                                if (GetRandom() % 100 <= gUnk_0903612C[gGameState.unk_00C[0]]) {
                                    args[8] = 0xFB;
                                } else {
                                    args[8] = func_08096D48(gGameState.unk_00C[0], 1);
                                }
                            } else {
                                args[8] = func_08096D48(gGameState.unk_00C[0], 1);
                            }
                        } else {
                            args[8] = func_08096D48(gGameState.unk_00C[0], 1);
                        }
                    } else {
                        args[8] = func_08096D48(gGameState.unk_00C[0], 1);
                    }
                } else {
                    args[8] = func_08096D48(gGameState.unk_00C[0], 1);
                }

                if (args[8] != 0xFFFF) {
                    func_0809797C(w, args);
                } else {
                    return 0;
                }
            }
        }

        w->unk_14 = 1;
    }

    TaskPoolUpdate(w);
    return 1;
}
#else
INCLUDE_ASM("card/PrizeCardInit_1.s");
#endif

s32 PrizeCardInit_Boss_1(PrizeCardInitWork* w, void* a) {
    PrizeCardTaskArgs args;

    if (w->unk_14 == 0) {
        *(PrizeCardArgs*)&args = w->unk_18;

        switch (*(s32*)&gBtlWork->unk_100[0xC]) {
        case 148:
            args.unk_20 = 0x21D;
            break;
        case 149:
            args.unk_20 = 0x228;
            break;
        case 150:
            args.unk_20 = 0x21F;
            break;
        case 151:
            args.unk_20 = 0x22A;
            break;
        case 152:
            args.unk_20 = 0x21E;
            break;
        case 153:
            args.unk_20 = 0x22C;
            break;
        case 154:
            args.unk_20 = 0x220;
            break;
        case 155:
            args.unk_20 = 0x229;
            break;
        case 156:
            args.unk_20 = 0x232;
            break;
        case 120:
            args.unk_20 = 0x221;
            break;
        case 162:
            args.unk_20 = 0xAF;
            break;
        case 163:
            args.unk_20 = 0xC5;
            break;
        case 161:
            args.unk_20 = 0xEC;
            break;
        case 157:
        case 158:
            args.unk_20 = 0x22B;
            break;
        case 159:
            args.unk_20 = 0x189;
            break;
        case 160:
            args.unk_20 = 0x227;
            break;
        case 165:
            args.unk_20 = 0x231;
            break;
        case 164:
            args.unk_20 = 0x1A8;
            break;
        case 169:
            args.unk_20 = 0x192;
            break;
        case 170:
            args.unk_20 = 0x22D;
            break;
        case 173:
            args.unk_20 = 0x22E;
            break;
        case 174:
            args.unk_20 = 0x22F;
            break;
        case 175:
            args.unk_20 = 0x230;
            break;
        case 121:
            args.unk_20 = 0x125;
            break;
        case 124:
            args.unk_20 = 0x19D;
            break;
        case 167:
            args.unk_20 = 0x233;
            break;
        default:
            w->unk_14 = 1;
            return 1;
        }

        if (*(s32*)&gBtlWork->unk_100[0xC] != 121) {
            if (func_0808510C(args.unk_20) == 0) {
                TaskCreate(w, gTaskDescPrizeBoss, &args);
            }
        } else {
            TaskCreate(w, gTaskDescPrizeBoss, &args);
        }

        w->unk_14 = 1;
    }

    TaskPoolUpdate(w);
    return 1;
}

void func_08096C20(void* pool) {
    TaskPoolDraw(pool);
}
void func_08096C2C(void* pool) {
    TaskPoolDestroy(pool);
}

u16 func_08096C38(UnkStruct_08096C38* tbl, u16 n) {
    s32 i;
    UnkStruct_08096C38_Item* arr;
    u16 cnt;
    u16 v;
    u16 card;

    i = 0;

    if (func_08093B38() <= 98) {
        while (i < n) {
            arr = tbl[i].unk_00;
            cnt = tbl[i].unk_04;
            v = GetRandom() % 100;

            if (v <= tbl[i].unk_06) {
                card = arr[GetRandom() % cnt].unk_00;
                v = func_08093B08(card);

                if (v <= 89) {
                    return card;
                }
            }

            i++;

            if (i >= n) {
                i = 0;
            }
        }
    } else {
        return 0xFFFF;
    }
}

u16 func_08096CCC(void) {
    u16 i;

    do {
        i = GetRandom() % 10;
    } while (gUnk_090359FC[i] <= GetRandom() % 100);

    return i;
}

u16 func_08096D0C(u16 a, s32 b) {
    UnkStruct_08096C38* tiles;
    u16 n;

    if (gGameState.flags & 8) {
        tiles = gUnk_090360BC[a].unk_00;
        n = gUnk_090360BC[a].unk_04;
    } else {
        tiles = gUnk_09035DCC[a].unk_00;
        n = gUnk_09035DCC[a].unk_04;
    }

    return func_08096C38(tiles, n);
}

u16 func_08096D48(u16 a, s32 b) {
    UnkStruct_08096C38* tiles;
    u16 base;
    u16 off;

    off = 0;

    if (gGameState.flags & 8) {
        tiles = gUnk_090360BC[a].unk_00;
        base = func_08096C38(tiles, gUnk_090360BC[a].unk_04);
    } else {
        tiles = gUnk_09035DCC[a].unk_00;
        base = func_08096C38(tiles, gUnk_09035DCC[a].unk_04);
    }

    if (base != 0xFFFF) {
        do {
            off = func_08096CCC();
        } while (gUnk_0203A8C0[base + off] == 9);
    }

    return base + off;
}

void func_08096DB0(void* a, void* b) {
    TaskCreate(a, gTaskDescPrizeCardInit, b);
}

void func_08096DC4(void* a, void* b) {
    TaskCreate(a, gTaskDescPrizeCardInitBoss, b);
}
void DispCardname_0(u8* work, u16* a) {
    UnkStruct_080038C8* p;
    s32 v;

    func_08065ACC((TextSlot*)work, 32);
    p = _08066468(1);
    *(void**)&work[0x104] = p;
    func_080062F4(p->unk_06 + 16, 1);
    work[0x10E] = func_08065B6C(a, (TextSlot*)work);
    *(void**)&work[0x100] = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
    *(void**)&work[0x108] = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_JP
    v = (240 - work[0x10E] * 10) / 2;
#else
    v = (240 - func_08065B08((TextSlot*)work, work[0x10E])) / 2;
#endif
    *(s16*)&work[0x10C] = v;
}
s32 DispCardname_1(void) {
    return 1;
}

void DispCardname_2(u8* work) {
    func_080664D8(*(s16*)&work[0x10C], 120, work, *(void**)&work[0x104], 50,
                  work[0x10E]);
    DrawSprite(120, 125, gUnk_09EF126C[0], *(void**)&work[0x100],
               *(void**)&work[0x108], 0, 0, 55);
}

void DispCardname_3(u8* work) {
    func_08065AE0(work, 32);
    ReleaseObjTiles(*(void**)&work[0x100]);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x104])->unk_06 + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x104]);
    ReleaseObjPalette(*(void**)&work[0x108]);
}

void func_08096F08(void* a, void* b) {
    TaskCreate(a, gTaskDescDispCardname, b);
}
void Version_0(u8* work) {
    *(void**)&work[0x00] = func_080668F0();
    *(void**)&work[0x04] = func_08066904();
    work[0x28] = func_0806692C(gUnk_081283C0, &work[0x08]);
}
s32 Version_1(void) {
    return 1;
}
void Version_2(u8* work) {
    func_08066DC0(0, 152, &work[0x08], *(s32*)&work[0x00], *(s32*)&work[0x04], 0,
                  work[0x28]);
}
void Version_3(s32* p) {
    func_08066918(p[0], p[1]);
}
s32 func_08096F80(void* a) {
    return (s32)TaskCreate(a, gTaskDescVersion, 0);
}
void func_08096F94(UnkStruct_08096F94* w, s32* args) {
    u8* p;

    w->unk_B0 = args[8];
    w->unk_20 = &gUnk_09EE4C80[args[8]];
    w->unk_24 = &gUnk_09EE4BF4[w->unk_20->unk_1E];
    w->unk_00 = LoadObjTiles(w->unk_20->unk_00, 0x300);
    w->unk_04 = LoadObjPalette(w->unk_20->unk_04, 32);
    *(u64*)&w->unk_3C = *(u64*)&w->unk_20->unk_20;
    w->unk_08 = LoadObjTiles(w->unk_24->unk_00, w->unk_24->unk_14);
    w->unk_0C = LoadObjTiles(w->unk_24->unk_00, w->unk_24->unk_14);
    w->unk_10 = LoadObjPalette(w->unk_24->unk_04, w->unk_24->unk_16);
    w->unk_14 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_18 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_1C = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_A0 = args[0];
    w->unk_A4 = args[1];
    w->unk_A8 = 0;
    w->unk_AC = 0;
    w->unk_DE = 24;
    w->unk_B4 = -(GetRandom() % 129 + 0x300);
    w->unk_B8 = GetRandom() % 129 + 0x80;
    w->unk_DC = GetRandom() % 256;
    w->unk_C8 = 0x80;
    w->unk_CA = 0x80;
    w->unk_DA = 0x80;
    w->unk_DF = 0;
    w->unk_E0 = 0;
    p = w->unk_44;
    func_080122AC(p, 5, 8, 10);
    func_08012614(p, 1);
    func_08012324(p, w->unk_A0, w->unk_A4, w->unk_A8);
    w->unk_E6 = 0;
    w->unk_E7 = 0;
    w->unk_E8 = 0;
    w->unk_E1 = 0;
    w->unk_E5 = 0;
    w->unk_E2 = 0;
    w->unk_E3 = 0;
    TaskPoolInit(&w->unk_28, 1);
    gBtlWork->unk_0B0++;
}
#ifdef NON_MATCHING
u8 func_08097138(UnkStruct_08096F94* w, void* a) {
    s16 x;
    s16 y;

    w->unk_B4 += 56;
    w->unk_A8 += w->unk_B4;
    w->unk_A0 += (gSineTable[(u8)w->unk_DC] * w->unk_B8) >> 8;
    w->unk_A4 += (-gSineTable[(u8)w->unk_DC + 64] * w->unk_B8) >> 8;

    if (func_0801A8A4(&w->unk_A0, &w->unk_A4, -10, -10)) {
        w->unk_DC += GetRandom() % 57 + 100;
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_44, 50);
    } else {
        ColliderSetRadius(w->unk_44, 10);
    }

    if (w->unk_A8 - 8 > w->unk_AC) {
        w->unk_A8 = w->unk_AC - 8;
        w->unk_B4 = -((w->unk_B4 * 217) >> 8);
        w->unk_DC = (u8)GetAngle(w->unk_A0, w->unk_A4, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08);
        w->unk_DC = w->unk_DC - 32 + GetRandom() % 65;

        if (w->unk_B4 > -0x200) {
            w->unk_B4 = -0x200;
        }
    }

    if (w->unk_70 != 0) {
        w->unk_E5 = 1;
        m4aSongNumStart(106);
        func_080938F8(w->unk_B0);
        SetTaskUpdate(a, (void*)func_08097404);
        WorldToScreen(&x, &y, w->unk_A0, w->unk_A4, w->unk_A8);
        w->unk_A0 = x << 8;
        w->unk_A4 = y << 8;
        func_08012614(w->unk_44, 1);
        w->unk_CC = 50;
        func_08097390(w);
    } else {
        func_08012324(w->unk_44, w->unk_A0, w->unk_A4, w->unk_A8);
        WorldToScreen(&w->unk_CE, &w->unk_D0, w->unk_A0, w->unk_A4, w->unk_A8);
        WorldToScreen(&w->unk_D6, &w->unk_D8, w->unk_A0, w->unk_A4, w->unk_AC);
        w->unk_CC = -0x1004 - (w->unk_A4 >> 8) * 4;
        func_080978B0(w);
        w->unk_E0 += 2;

        if (w->unk_E1 == 20) {
            func_08012614(w->unk_44, 0);
        }

        if (w->unk_E1 <= 59) {
            w->unk_E1++;
        }
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_08097138.s");
#endif

void func_08097390(UnkStruct_08096F94* w) {
    s16 x;
    s16 y;
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    WorldToScreen(&x, &y, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    tx = 0x7800;
    ty = 0x5000;
    dx = tx - w->unk_A0;
    dy = ty - w->unk_A4;
    w->unk_C4 = func_0805F5A4(&dx, &dy);
    w->unk_BC = -dx;
    w->unk_C0 = -dy;
    w->unk_B8 = 0x300;
    w->unk_B4 = 2;
}

u8 func_08097404(UnkStruct_08096F94* w, void* a) {
    s32 dx;
    s32 dy;
    u8 z;
    u8 t;
    s32 x;
    s32 y;
    s16* q1;
    s16* q2;

    if (w->unk_B8 < 0) {
        dx = 0x7800 - w->unk_A0;
        dy = 0x5000 - w->unk_A4;
        func_0805F5A4(&dx, &dy);
        w->unk_BC = -dx;
        w->unk_C0 = -dy;

        if (w->unk_C4 <= 0x7FF) {
            w->unk_E2 = 0;
            w->unk_DE = 0;
            SetTaskUpdate(a, (void*)func_0809753C);
            func_08096F08(&w->unk_28, func_08093C18(w->unk_20->unk_20));
        }
    }

    w->unk_A0 += (w->unk_BC * w->unk_B8) >> 8;
    w->unk_A4 += (w->unk_C0 * w->unk_B8) >> 8;
    t = w->unk_DE + 32;
    z = 0;
    w->unk_DE = t;
    w->unk_DF += (64 - w->unk_DF) >> 4;
    w->unk_E0 = z;
    w->unk_C4 = func_0805F588(0x7800 - w->unk_A0, 0x5000 - w->unk_A4);
    w->unk_B8 -= w->unk_B4;
    w->unk_B4 += 2;

    if (w->unk_DA <= 0xFF) {
        w->unk_DA += 3;
    }

    x = w->unk_A0 >> 8;
    q1 = &w->unk_CE;
    *q1 = x;
    y = w->unk_A4 >> 8;
    q2 = &w->unk_D0;
    *q2 = y;
    func_080978B0(w);
    return 1;
}
u8 func_0809753C(UnkStruct_08096F94* w, void* a) {
    s32 v;
    s16 lim;
    s32 x;
    s16* q;

    v = w->unk_DE << 8;
    ApproachValue((s32*)&w->unk_DF, 0, w->unk_E2);
    ApproachValue(&v, 0, w->unk_E2);
    ApproachValue(&w->unk_A0, 0x7800, w->unk_E2);
    ApproachValue(&w->unk_A4, 0x5800, w->unk_E2);
    w->unk_DE = v >> 8;

    if (w->unk_E2 != 0) {
        w->unk_E2--;
    }

    lim = 0x100;

    if (w->unk_DA < 0x100) {
        w->unk_DA += 2;
    } else {
        w->unk_DA = lim;
    }

    x = w->unk_A0 >> 8;
    q = &w->unk_CE;
    *q = x;
    x = w->unk_A4 >> 8;
    q = &w->unk_D0;
    *q = x;
    func_080978B0(w);
    w->unk_E3++;

    if (w->unk_E3 == 30) {
        w->unk_E3 = 0;
        SetTaskUpdate(a, func_08097600);
    }

    TaskPoolUpdate(&w->unk_28);
    return 1;
}

u8 func_08097600(UnkStruct_08096F94* w) {
    w->unk_DE += 32;
    WorldToScreen(&w->unk_D2, &w->unk_D4, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    w->unk_CE += (w->unk_D2 - w->unk_CE) >> 3;
    w->unk_D0 += (w->unk_D4 - w->unk_D0) >> 3;
    w->unk_C8 -= 10;
    w->unk_CA -= 10;

    if (w->unk_C8 <= 10) {
        return 0;
    }

    return 1;
}

void func_08097688(UnkStruct_08096F94* w) {
    u16 pal;
    s32 affine;
    void* gfx;
    s16 v;

    pal = w->unk_E5 == 0 ? func_0801AF1C(w->unk_A4) : 0;

    if (w->unk_C8 == 0x100 && w->unk_DE == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_DE, w->unk_C8, w->unk_CA, 1);
    }

    DrawSprite(w->unk_CE, (u16)w->unk_D0 - 8,
               **(void***)(w->unk_20->unk_08),
               w->unk_00, w->unk_04, affine, pal,
               (u16)(w->unk_CC + 1));

    if (w->unk_20->unk_1E == 4) {
        gfx = (*(void***)(w->unk_24->unk_08))[w->unk_E8];
    } else {
        gfx = (*(void***)(w->unk_24->unk_08))[0];
    }

    DrawSprite(w->unk_CE, (u16)w->unk_D0 - 8, gfx,
               w->unk_08, w->unk_10, affine, pal,
               w->unk_CC);

    if (w->unk_20->unk_1E != 4) {
        gfx = gUnk_09EE981C[w->unk_3E];
        DrawSprite(w->unk_CE, (u16)w->unk_D0 - 8, gfx,
                   w->unk_14, w->unk_10, affine, pal,
                   (u16)(w->unk_CC - 1));
    }

    if (w->unk_E5 == 0) {
        v = 204 - ((w->unk_AC - w->unk_A8) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(w->unk_D6, w->unk_D8, gUnk_09EE1380[0],
                   w->unk_18, w->unk_1C,
                   AllocObjAffine(0, v, v, 0), pal,
                   (u16)(w->unk_CC + 2));
    }

    TaskPoolDraw(&w->unk_28);
}

void func_08097834(PrizeCardWork* w) {
    func_080062F4(w->unk_10->unk_06 + 16, 0);
    func_080062F4(w->unk_04->unk_06 + 16, 0);
    func_08012304(&w->unk_20[0x24]);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjTiles(w->unk_0C);
    ReleaseObjTiles(w->unk_18);
    ReleaseObjPalette(w->unk_04);
    ReleaseObjPalette(w->unk_10);
    ReleaseObjPalette(w->unk_1C);
    TaskPoolDestroy(&w->unk_20[8]);
    gBtlWork->unk_0B0--;
}

void func_080978B0(UnkStruct_08096F94* w) {
    w->unk_C8 = (-gSineTable[((w->unk_E0 + 0x80) & 0xFF) + 0x40] * w->unk_DA) >> 8;
    w->unk_CA = (-gSineTable[((w->unk_DF + 0x80) & 0xFF) + 0x40] * w->unk_DA) >> 8;

    if ((u16)(w->unk_C8 + 2) <= 4) {
        w->unk_C8 = 2;
    }

    if ((u16)(w->unk_CA + 2) <= 4) {
        w->unk_CA = 2;
    }
}

#ifndef VERSION_EU
void func_0809792C(UnkStruct_08096F94* w) {
    u8* p;
    u8* q;
    u8 k;
    u8 v;
    u8 z;

    v = gUnk_09EE752C[w->unk_E7].unk_00;
    q = &w->unk_E8;
    z = 0;
    *q = v;
    p = &w->unk_E6;
    k = w->unk_E7;

    if (*p == gUnk_09EE752C[k].unk_01) {
        w->unk_E7 = k + 1;

        if (w->unk_E7 == 7) {
            w->unk_E7 = z;
        }

        *p = z;
    }

    w->unk_E6++;
}
#endif

void func_0809797C(void* a, void* b) {
    TaskCreate(a, gUnk_09EE7650, b);
}

void SpotLight_0(UnkStruct_08097A14* w, u8* src) {
    if (src != 0) {
        w->unk_10 = src;
    } else {
        w->unk_10 = &w->unk_14;
        w->unk_14 = 0;
    }

    LoadBgTiles(0, gUnk_09501778, 0xCA0);
    LoadPalette(gUnk_09618C38, gUnk_050001A0, 32);
    func_080062F4(13, 1);
    LoadBgMap(0, gUnk_0960F2B8, 0x800);
    SetBgScroll(0, 0, 0);
    w->unk_00 = 30;
    w->unk_04 = 0x1000;
    w->unk_08 = 0;
    func_08006184(0, 30);
    gBldCnt = 0xE41;
}

u8 SpotLight_1(UnkStruct_08097A14* w, void* a) {
    ApproachValue(&w->unk_08, 0x1000, w->unk_00);

    if (w->unk_00 != 0) {
        w->unk_00--;
        w->unk_0C = ((w->unk_04 >> 8) << 8) | (w->unk_08 >> 8);
        gBldAlpha = w->unk_0C;
    }

    if (*w->unk_10 == 1) {
        func_08006120(0, 30);
        w->unk_00 = 30;
        gBldCnt = 0xE41;
        SetTaskUpdate(a, (void*)func_08097A80);
    }

    return 1;
}

s32 func_08097A80(u8* work) {
    s32 v;

    ApproachValue(&work[0x08], 0, work[0x00]);

    if (work[0x00] != 0) {
        work[0x00]--;
    }

    v = ((*(s32*)&work[0x04] >> 8) << 8) | (*(s32*)&work[0x08] >> 8);
    *(u16*)&work[0x0C] = v;
    gBldAlpha = v;
    return 1;
}
void SpotLight_2(void) {
}
void SpotLight_3(void) {
    func_080062F4(13, 0);
}
#ifdef NON_MATCHING
void SELMAP_EVKEY_0(u8* work, void* a) {
    s32 zero;
    s32 i;
    s32 ofs;
    u8* q1;
    u8* q2;
    u8* q3;

    zero = 0;
    CpuSet(&zero, work, 0x05000049);
    *(void**)&work[0xD8] = a;
    *(void**)&work[0xF8] = ((void**)a)[1];
    work[0x121] = func_080E8D00();

    for (i = 0; i < work[0x121]; i++) {
        ofs = i * 52;
        func_08098014(&work[ofs + 8], func_080E8D1C((u8)i));
        q1 = &work[0x14];

        if (*(u8**)&q1[ofs] != 0) {
            func_080062F4(*(u16*)&(*(u8**)&q1[ofs])[6] + 16, 1);
        }
        q2 = &work[0x18];

        if (*(u8**)&q2[ofs] != 0) {
            func_080062F4(*(u16*)&(*(u8**)&q2[ofs])[6] + 16, 1);
        }
        q3 = &work[0x1C];

        if (*(u8**)&q3[ofs] != 0) {
            func_080062F4(*(u16*)&(*(u8**)&q3[ofs])[6] + 16, 1);
        }
    }

    *(void**)&work[0] = AllocObjTiles(0x6C0, 0);
    func_08002A10(*(void**)&work[0], &gUnk_093F47E4[0x22E8]);
    AnimInit((AnimState*)&work[0xDC], (s32)gUnk_09EF1224, (s32)gUnk_09EF1220);
    AnimStart((AnimState*)&work[0xDC], 0, 1);
    *(void**)&work[0xF4] = AnimGetGfx((AnimState*)&work[0xDC]);
    *(void**)&work[4] = **(void***)&work[0xD8];
    work[0x11C] = 0;
    work[0x11D] = 0;
    work[0x11E] = 8;
    work[0x11F] = 8;
    work[0x120] = 0;
    work[0x123] = 0;
    SetObjMosaicSize(work[0x11E], work[0x11F]);
    *(s32*)&work[0xFC] = 0x7800;
    *(s32*)&work[0x100] = 0x4000;
    *(u16*)&work[0x114] = 0x100;
    *(u16*)&work[0x116] = 0x100;
    work[0x11B] = 0;
    work[0x122] = 0;
    work[0x11A] = 8;
    *(u16*)&work[0x118] = 0;
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[8]);
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[0x3C]);
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[0x70]);
    func_08098598(0x10000, *(s32*)&work[0x100], (s32*)&work[0xA4]);
}
#else
INCLUDE_ASM("card/SELMAP_EVKEY_0.s");
#endif
s32 SELMAP_EVKEY_1(u8* work, void* a) {
    s32 i;
    u8* q1;
    u8* q2;
    u8* q3;
    u8* r;
    u8 n;

    *(void**)&work[0xF4] = AnimUpdate(&work[0xDC]);
    *(s32*)&work[0x104] = ((240 - (work[0x121] - work[0x122]) * 32) << 7) + 0x1000;
    ApproachValue(&work[0xFC], *(s32*)&work[0x104], work[0x11A]);

    if (work[0x11A] != 0) {
        work[0x11A]--;
    }

    for (i = work[0x122]; i < work[0x121]; i++) {
        func_08098598(*(s32*)&work[0xFC] + ((i - work[0x122]) << 13), *(s32*)&work[0x100], (s32*)&work[i * 52 + 8]);
    }

    SetObjMosaicSize(work[0x11E], work[0x11F]);

    if (work[0x120] == 2) {
        if (work[0x11E] != 0) {
            work[0x11E]--;
        }

        if (work[0x11F] != 0) {
            work[0x11F]--;
        }

        work[0x120] = 0;
    }

    work[0x120]++;
    work[0x11D]++;

    if ((*(void***)&work[0xD8])[2] != 0) {
        SetTaskUpdate(a, (void*)func_08097DE4);
    }

    q1 = &work[work[0x122] * 52];

    if (*(u16*)&q1[0x36] != 0) {
        r = func_080E8D1C(0);
        q2 = &work[work[0x122] * 52];
        *(u16*)&q2[0x36] = r[3];
        n = work[0x122];
        q3 = &work[n * 52];

        if (*(u16*)&q3[0x38] != *(u16*)&q3[0x36]) {
            func_080984E4((UnkStruct_080984E4*)&work[n * 52 + 8]);
        }
    }

    *(u16*)&work[0x118] += 8;
    return 1;
}
s32 func_08097DE4(u8* work) {
    u8* a;
    u8* b;

    a = &work[0x11E];

    if (*a <= 14) {
        (*a)++;
    }

    b = &work[0x11F];

    if (*b <= 14) {
        (*b)++;
    }

    SetObjMosaicSize(*a, *b);
    return 1;
}
void SELMAP_EVKEY_2(u8* work) {
    s32 i;
    s32 ofs;
    u8* e;
    u8* q1;
    u8* q2;

    switch ((*(s32**)&work[0xD8])[2]) {
    case 0:
    case 2:
        if (work[0x11E] == 15) {
            return;
        }

        if (work[0x11F] == 15) {
            break;
        }

        for (i = work[0x122]; i < work[0x121]; i++) {
            if (i == work[0x122]) {
                func_080985A0((UnkStruct_08098670*)&work[i * 52 + 8], 0x808, 0,
                              (gSineTable[work[0x118]] >> 8) * 8 + 256);
                e = &work[i * 52];

                switch (e[58]) {
                case 2:
                    ofs = i * 52;
                    DrawSprite(*(s32*)&(q1 = &work[44])[ofs] >> 8, (*(s32*)&(q2 = &work[48])[ofs] >> 8) + 8,
                               ((void**)gUnk_0203A890[5])[4], gUnk_0203A890[1], gUnk_0203A890[3], 0, 8, 20);
                    break;
                case 3:
                    ofs = i * 52;
                    DrawSprite(*(s32*)&(q1 = &work[44])[ofs] >> 8, (*(s32*)&(q2 = &work[48])[ofs] >> 8) + 8,
                               ((void**)gUnk_0203A890[5])[8], gUnk_0203A890[1], gUnk_0203A890[3], 0, 8, 20);
                    break;
                case 1:
                    ofs = i * 52;
                    DrawSprite(*(s32*)&(q1 = &work[44])[ofs] >> 8, (*(s32*)&(q2 = &work[48])[ofs] >> 8) + 8,
                               ((void**)gUnk_0203A890[5])[6], gUnk_0203A890[1], gUnk_0203A890[3], 0, 8, 20);
                    break;
                case 0:
                case 4:
                default:
                    break;
                }
            } else {
                func_08098670((UnkStruct_08098670*)&work[i * 52 + 8], 0x808);
            }
        }
        break;
    }

    if (work[0x11E] == 15) {
        return;
    }

    if (work[0x11F] == 15) {
        return;
    }

    DrawSprite(120, 42, *(void**)&work[0xF4], *(void**)&work[0], *(void**)&work[4], 0, 8, 10);
}
void SELMAP_EVKEY_3(u8* work) {
    s32 i;

    for (i = 0; i < work[0x121]; i++) {
        func_08098778((void**)&work[i * 52 + 8]);
    }

    ReleaseObjTiles(*(void**)&work[0x00]);
}

#ifdef NON_MATCHING
void func_08098014(u8* work, u8* a) {
    s32 zero;
    UnkStruct_09EE4C80* c;
    UnkStruct_09EE4BF4* b;
    UnkStruct_080038C8* g;
    u8 n;

    zero = 0;
    CpuSet((void*)&zero, work, 0x0500000D);

    if (a[0] != 255) {
        c = &gUnk_09EE4C80[a[0] * 10];
        b = &gUnk_09EE4BF4[c->unk_1E];
        *(void**)&work[0x00] = LoadObjTiles(c->unk_00, *(u16*)&c->unk_08[0x10]);
        *(void**)&work[0x0C] = LoadObjPalette(c->unk_04, *(u16*)&c->unk_08[0x12]);
        *(void**)&work[0x18] = *(void**)&c->unk_08[0];
        *(void**)&work[0x04] = LoadObjTiles(b->unk_00, b->unk_14);
        *(void**)&work[0x10] = LoadObjPalette(b->unk_04, b->unk_16);
        *(void**)&work[0x1C] = *(void**)&b->unk_08[0];
        *(s32*)&work[0x08] = 0;
        *(s32*)&work[0x14] = 0;
        return;
    }

    *(s32*)&work[0x00] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x14] = 0;

    if (a[1] == 0) {
        *(s32*)&work[0x04] = 0;
        *(s32*)&work[0x10] = 0;
        *(s32*)&work[0x1C] = 0;
        n = a[1];
    } else {
        b = &gUnk_09EE4BF4[a[1]];
        *(void**)&work[0x04] = LoadObjTiles(*(void**)&b->unk_08[4], *(u16*)&b->unk_18[0]);
        *(void**)&work[0x10] = LoadObjPalette(b->unk_04, b->unk_16);
        *(void**)&work[0x1C] = *(void**)*(void**)&b->unk_08[8];
        *(s32*)&work[0x08] = 0;
        *(s32*)&work[0x00] = 0;
        *(s32*)&work[0x0C] = 0;
        *(s32*)&work[0x18] = 0;
        *(s32*)&work[0x14] = 0;

        switch (a[1]) {
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 3;
            break;
        default:
            n = a[1];
            break;
        }
    }

    work[0x32] = n;

    if (a[2] == 0) {
        return;
    }

    switch (a[2]) {
    case 1:
        if (a[3] <= 9) {
            g = func_080038C8(0x100);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + a[3] * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x500, &gUnk_06010000[g->unk_06 * 32], 128);
        } else {
            g = func_080038C8(0x180);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (u8)(a[3] / 10) * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[(g->unk_06 + 8) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x500, &gUnk_06010000[g->unk_06 * 32], 128);
        }
        break;
    case 2:
        if (a[3] <= 9) {
            g = func_080038C8(0x100);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + a[3] * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x580, &gUnk_06010000[g->unk_06 * 32], 128);
        } else {
            g = func_080038C8(0x180);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (u8)(a[3] / 10) * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[(g->unk_06 + 8) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x580, &gUnk_06010000[g->unk_06 * 32], 128);
        }
        break;
    case 3:
        if (a[3] <= 9) {
            g = func_080038C8(0x100);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + a[3] * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x600, &gUnk_06010000[g->unk_06 * 32], 128);
        } else {
            g = func_080038C8(0x180);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (u8)(a[3] / 10) * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[(g->unk_06 + 8) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x600, &gUnk_06010000[g->unk_06 * 32], 128);
        }
        break;
    case 4:
        if (a[3] <= 9) {
            g = func_080038C8(0x80);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[0], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + a[3] * 128, &gUnk_06010000[g->unk_06 * 32], 128);
        } else {
            g = func_080038C8(0x100);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[2], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (u8)(a[3] / 10) * 128, &gUnk_06010000[g->unk_06 * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (a[3] - (u8)(a[3] / 10) * 10) * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
        }

        *(u16*)&work[0x2E] = a[3];
        *(u16*)&work[0x30] = a[3];
        break;
    }

    *(s32*)&work[0x00] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x14] = 0;

    if (a[1] == 0) {
        *(s32*)&work[0x04] = 0;
        *(s32*)&work[0x10] = 0;
        *(s32*)&work[0x1C] = 0;
        n = a[1];
    } else {
        b = &gUnk_09EE4BF4[a[1]];
        *(void**)&work[0x04] = LoadObjTiles(*(void**)&b->unk_08[4], *(u16*)&b->unk_18[0]);
        *(void**)&work[0x10] = LoadObjPalette(b->unk_04, b->unk_16);
        *(void**)&work[0x1C] = *(void**)*(void**)&b->unk_08[8];
        *(s32*)&work[0x08] = 0;
        *(s32*)&work[0x00] = 0;
        *(s32*)&work[0x0C] = 0;
        *(s32*)&work[0x18] = 0;
        *(s32*)&work[0x14] = 0;

        switch (a[1]) {
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 3;
            break;
        default:
            n = a[1];
            break;
        }
    }

    work[0x32] = n;

    if (a[2] == 0) {
        return;
    }

    switch (a[2]) {
    case 1:
        if (a[3] <= 9) {
            g = func_080038C8(0x100);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[1], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + a[3] * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x500, &gUnk_06010000[g->unk_06 * 32], 128);
        } else {
            g = func_080038C8(0x180);
            *(void**)&work[0x08] = g;
            func_080038E4(g, gUnk_09EF1198[3], gUnk_0950C478);
            *(s32*)&work[0x20] = 0;
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (a[3] / 10) * 128, &gUnk_06010000[(g->unk_06 + 4) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + (a[3] - (a[3] / 10) * 10) * 128, &gUnk_06010000[(g->unk_06 + 8) * 32], 128);
            g = *(UnkStruct_080038C8**)&work[0x08];
            RequestDma3Copy((u8*)g->unk_00 + 0x500, &gUnk_06010000[g->unk_06 * 32], 128);
        }
        break;
    }

    *(s32*)&work[0x00] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(void**)&work[0x14] = LoadObjPalette(gUnk_09618D38, 32);

    if (*(void**)&work[0x04] == 0) {
        *(void**)&work[0x04] = LoadObjTiles(gUnk_08F709B0[4].unk_10, 0x300);
        *(void**)&work[0x10] = LoadObjPalette(gUnk_09618D38, 32);
        *(void**)&work[0x1C] = gUnk_08F709B0[4].unk_04;
    }
}
#else
INCLUDE_ASM("card/func_08098014.s");
#endif

void func_080984E4(UnkStruct_080984E4* w) {
    s32 z;

    if (w->unk_2E <= 9) {
        z = 0;
        func_080038E4(w->unk_08, gUnk_09EF1198[0], gUnk_0950C478);
        w->unk_20 = z;
        RequestDma3Copy(w->unk_08->unk_00 + w->unk_2E * 128, &gUnk_06010000[w->unk_08->unk_06 * 32], 128);
    } else {
        z = 0;
        func_080038E4(w->unk_08, gUnk_09EF1198[2], gUnk_0950C478);
        w->unk_20 = z;
        RequestDma3Copy(w->unk_08->unk_00 + (u16)(w->unk_2E / 10) * 128, &gUnk_06010000[w->unk_08->unk_06 * 32], 128);
        RequestDma3Copy(w->unk_08->unk_00 + (w->unk_2E - (u16)(w->unk_2E / 10) * 10) * 128, &gUnk_06010000[(w->unk_08->unk_06 + 4) * 32], 128);
    }

    w->unk_30 = w->unk_2E;
}

void func_08098598(s32 a, s32 b, s32* c) {
    c[9] = a;
    c[10] = b;
}

void func_080985A0(UnkStruct_08098670* w, u16 b, s16 c, s16 d) {
    s32 aff;

    aff = AllocObjAffine(0, d, d, 1);

    if (w->unk_00 != 0) {
        DrawSprite(w->unk_24 >> 8, c + (w->unk_28 >> 8), w->unk_18, w->unk_00, w->unk_0C, aff, b, 10);
    }

    if (w->unk_04 != 0) {
        DrawSprite(w->unk_24 >> 8, c + (w->unk_28 >> 8), w->unk_1C, w->unk_04, w->unk_10, aff, b, 9);
    }

    if (w->unk_08 != 0) {
        DrawSprite(w->unk_24 >> 8, c + (w->unk_28 >> 8), w->unk_20, w->unk_08, w->unk_14, aff, b, 8);
    }
}

void func_08098670(UnkStruct_08098670* p, u16 a) {
    if (p->unk_00 != 0) {
        DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_18, p->unk_00, p->unk_0C, 0, a, 10);
    }

    if (p->unk_04 != 0) {
        DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_1C, p->unk_04, p->unk_10, 0, a, 9);
    }

    if (p->unk_08 != 0) {
        DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_20, p->unk_08, p->unk_14, 0, a, 8);
    }
}

UnkStruct_080038C8* func_080986FC(u8 a) {
    UnkStruct_080038C8* obj;

    if (a != 0) {
        obj = func_080038C8(256);
        func_080038E4(obj, gUnk_09EF1198[1], gUnk_0950C478);
        RequestDma3Copy(&obj->unk_00[a * 128], (void*)(0x06010000 + (obj->unk_06 + 4) * 32), 128);
        RequestDma3Copy(&obj->unk_00[0x500], (void*)(0x06010000 + obj->unk_06 * 32), 128);
    } else {
        obj = func_080038C8(128);
        func_080038E4(obj, gUnk_09EF1198[0], gUnk_0950C478);
    }

    return obj;
}

void func_08098778(void** p) {
    if (p[0] != 0) {
        ReleaseObjTiles(p[0]);
    }

    if (p[1] != 0) {
        ReleaseObjTiles(p[1]);
    }

    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
    }

    if (p[3] != 0) {
        ReleaseObjPalette(p[3]);
    }

    if (p[4] != 0) {
        ReleaseObjPalette(p[4]);
    }

    if (p[5] != 0) {
        ReleaseObjPalette(p[5]);
    }
}

u8 func_080987C0(u16 n) {
    u8 idx;

    idx = 0;

    switch (n) {
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 170;
        break;
    case 3:
        idx = 50;
        break;
    case 4:
        idx = 40;
        break;
    case 5:
        idx = 190;
        break;
    case 6:
        idx = 20;
        break;
    case 7:
        idx = 30;
        break;
    case 8:
        idx = 160;
        break;
    case 9:
        idx = 180;
        break;
    case 10:
        idx = 210;
        break;
    case 11:
        idx = 100;
        break;
    case 12:
        idx = 90;
        break;
    case 13:
        idx = 110;
        break;
    case 14:
        idx = 120;
        break;
    case 15:
        idx = 200;
        break;
    case 16:
        idx = 140;
        break;
    case 17:
        idx = 150;
        break;
    case 18:
        idx = 130;
        break;
    case 19:
        idx = 60;
        break;
    case 20:
        idx = 70;
        break;
    case 21:
        idx = 80;
        break;
    case 22:
        idx = 220;
        break;
    case 23:
        idx = 230;
        break;
    case 24:
        idx = 240;
        break;
    case 0:
    case 26:
        idx = 10;
        break;
    case 25:
    case 27:
        idx = 250;
        break;
    }

    return gUnk_09EE4C80[idx].unk_1E;
}

void RELOAD_CHILDREN_0(UnkStruct_08098BE8* w, UnkStruct_080988C0_Args* a) {
    *(UnkStruct_080988C0_Args*)&w->unk_0C = *a;
    w->tiles = LoadObjTiles(gUnk_09EE7698[w->unk_19], 128);
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_08 = 0;

    switch (w->unk_1A) {
    case 1:
        if ((s8)w->unk_18 <= 3) {
            w->unk_20 = gUnk_090361B0[(s8)w->unk_18] << 8;
            w->unk_24 = gUnk_090361C0[(s8)w->unk_18] << 8;
        } else {
            w->unk_20 = gUnk_090361B0[3] << 8;
            w->unk_24 = gUnk_090361C0[3] << 8;
        }
        break;
    case 2:
        if ((s8)w->unk_18 <= 3) {
            w->unk_20 = gUnk_090361B8[(s8)w->unk_18] << 8;
            w->unk_24 = gUnk_090361C0[(s8)w->unk_18] << 8;
        } else {
            w->unk_20 = gUnk_090361B8[3] << 8;
            w->unk_24 = gUnk_090361C0[3] << 8;
        }
        break;
    }

    func_08000D20(w->unk_30, *(void**)w->unk_0C, w);
    func_08000D28(w->unk_30, *(void**)w->unk_0C);
    w->unk_46 = 0;
}

u8 RELOAD_CHILDREN_1(UnkStruct_08098BE8* w, void* a) {
    u8 (*fn)(UnkStruct_08098BE8*, void*);

    if (w->unk_1C & 2) {
        w->unk_46++;

        if (w->unk_46 == 30) {
            w->unk_44 = 8;
            fn = func_08098AE4;
            SetTaskUpdate(a, fn);
            return fn(w, a);
        }
    }

    if (w->unk_1C & 1) {
        w->unk_44 = 8;
        w->unk_1C &= ~1;
    }

    if (w->unk_18 <= 3) {
        switch (w->unk_1A) {
        case 1:
            ApproachValue(&w->unk_20, gUnk_090361B0[(s8)w->unk_18] << 8, w->unk_44);
            break;
        case 2:
            ApproachValue(&w->unk_20, gUnk_090361B8[(s8)w->unk_18] << 8, w->unk_44);
            break;
        }

        ApproachValue(&w->unk_24, gUnk_090361C0[(s8)w->unk_18] << 8, w->unk_44);
    } else if ((s8)w->unk_18 < 0) {
        func_08000D90(w->unk_30, *(void**)w->unk_0C);
        w->unk_08 = LoadObjTiles(gUnk_08F709B0[w->unk_19].unk_10, 0xD00);
        w->unk_44 = 8;
        w->unk_28 = 0x66;
        SetTaskUpdate(a, (void*)func_08098BA4);
        return 1;
    }

    if (w->unk_44 != 0) {
        w->unk_44--;
    }

    w->unk_45 += 8;
    return 1;
}

u8 func_08098AE4(UnkStruct_08098BE8* w, void* a) {
    u8 (*f)(UnkStruct_08098BE8*, void*);
    u16 v;

    v = w->unk_1C & 2;

    if (v == 0) {
        w->unk_44 = 8;
        f = RELOAD_CHILDREN_1;
        SetTaskUpdate(a, (void*)f);
        w->unk_46 = 0;
        return f(w, a);
    }

    switch (w->unk_1A) {
    case 1:
        ApproachValue(&w->unk_20, gUnk_090361B0[(s8)w->unk_18] << 8, w->unk_44);
        break;
    case 2:
        ApproachValue(&w->unk_20, gUnk_090361B8[(s8)w->unk_18] << 8, w->unk_44);
        break;
    }

    ApproachValue(&w->unk_24, gUnk_090361C0[3] << 8, w->unk_44);

    if (w->unk_44 != 0) {
        w->unk_44--;
    }

    return 1;
}

s32 func_08098BA4(UnkStruct_08098BE8* w) {
    ApproachValue(&w->unk_20, 0, w->unk_44);
    ApproachValue(&w->unk_24, 0, w->unk_44);
    ApproachValue(&w->unk_28, 256, w->unk_44);

    if (w->unk_44 != 0) {
        w->unk_44--;
        return 1;
    }

    return 0;
}

void RELOAD_CHILDREN_2(UnkStruct_08098BE8* w) {
    s16 x;
    s16 y;
    s32 aff;

    if (w->unk_18 <= 3) {
        x = (w->unk_20 + *w->unk_10) >> 8;
        y = (w->unk_24 + *w->unk_14) >> 8;
        DrawSprite(x, y + (gSineTable[w->unk_45] >> 8), gUnk_09EEA344[0], w->tiles, w->palette, 0, 0, 50);
    }

    if ((s8)w->unk_18 < 0) {
        x = (w->unk_20 + *w->unk_10) >> 8;
        y = (w->unk_24 + *w->unk_14) >> 8;
        aff = AllocObjAffine(0, w->unk_28, w->unk_28, 0);
        DrawSprite(x, y + (gSineTable[w->unk_45] >> 8), gUnk_08F709B0[w->unk_19].unk_04, w->unk_08, w->palette, aff, 0, 49);
    }
}

void RELOAD_CHILDREN_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);

    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
    }
}
void REV_COUNT_0(UnkStruct_08098CE4* w, UnkStruct_080991CC* a) {
    vu32 zero;
    s16* count;
    s16* count2;
    void** row;
    u8 idx;

    zero = 0;
    CpuSet((void*)&zero, w, 0x05000011);
    w->unk_2C = *a;
    idx = w->unk_2C.unk_0C;
    w->unk_24 = idx;
    w->unk_00 = func_080038C8(320);
    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);

    if (w->unk_24 == 0) {
        count = (s16*)w->unk_2C.unk_04;

        if (*count >= 2 && *count <= 100) {
            row = gUnk_09EE76D0[w->unk_24];
            func_080038E4(w->unk_00, row[*count - 2], gUnk_09EE76C0[w->unk_24]);
        } else if (*count > 100) {
            row = gUnk_09EE76D0[w->unk_24];
            func_080038E4(w->unk_00, row[98], gUnk_09EE76C0[w->unk_24]);
        } else {
            row = gUnk_09EE76D0[w->unk_24];
            func_080038E4(w->unk_00, row[0], gUnk_09EE76C0[w->unk_24]);
        }
    } else {
        count2 = (s16*)w->unk_2C.unk_04;

        if (*count2 >= 1 && *count2 <= 99) {
            row = gUnk_09EE76D0[w->unk_24];
            func_080038E4(w->unk_00, row[*count2 - 1], gUnk_09EE76C0[w->unk_24]);
        } else {
            row = gUnk_09EE76D0[w->unk_24];
            func_080038E4(w->unk_00, row[0], gUnk_09EE76C0[w->unk_24]);
        }
    }

    w->unk_08 = AnimGetGfx(&w->unk_0C);
    w->unk_26 = *(u16*)w->unk_2C.unk_04;

    switch (w->unk_2C.unk_0D) {
    case 1:
        w->unk_3C = -0x2000;
        w->unk_40 = 0x9800;
        break;
    case 2:
        w->unk_3C = 0x11000;
        w->unk_40 = 0x9800;
        break;
    }

    w->unk_28 = 8;
}
u8 func_08098FDC(UnkStruct_08098CE4* w);
u8 func_08099048(UnkStruct_08098CE4* w, void* a);
u8 func_080990CC(UnkStruct_08098CE4* w, void* a);

#ifdef NON_MATCHING
u8 REV_COUNT_1(UnkStruct_08098CE4* w, void* a) {
    u8 (*f)(UnkStruct_08098CE4*, void*);
    s16* count;
    void** row;

    count = (s16*)w->unk_2C.unk_04;

    if (*count != (s16)w->unk_26) {
        if (w->unk_24 == 0) {
            if (*count >= 2 && *count <= 100) {
                row = gUnk_09EE76D0[w->unk_24];
                func_080038E4(w->unk_00, row[*count - 2],
                              gUnk_09EE76C0[w->unk_24]);
            } else {
                w->unk_28 = 8;
                f = func_080990CC;
                SetTaskUpdate(a, (u32)f);
                w->unk_26 = *(u16*)w->unk_2C.unk_04;
                return f(w, a);
            }
        } else {
            if (*count >= 1 && *count <= 99) {
                row = gUnk_09EE76D0[w->unk_24];
                func_080038E4(w->unk_00, row[*count - 1],
                              gUnk_09EE76C0[w->unk_24]);
            } else {
                w->unk_28 = 8;
                f = func_080990CC;
                SetTaskUpdate(a, (u32)f);
                w->unk_26 = *(u16*)w->unk_2C.unk_04;
                return f(w, a);
            }
        }

        w->unk_26 = *(u16*)w->unk_2C.unk_04;
    } else if (*count <= 0) {
        w->unk_28 = 8;
        f = func_080990CC;
        SetTaskUpdate(a, (u32)f);
        w->unk_26 = *(u16*)w->unk_2C.unk_04;
        return f(w, a);
    }

    switch (w->unk_2C.unk_0D) {
    case 1:
        ApproachValue(&w->unk_3C, 0, w->unk_28);
        break;
    case 2:
        ApproachValue(&w->unk_3C, 0xD800, w->unk_28);
        break;
    }

    if (w->unk_28 != 0) {
        w->unk_28--;
    }

    if (w->unk_2C.unk_0C != *(u8*)w->unk_2C.unk_00) {
        f = (u8 (*)(UnkStruct_08098CE4*, void*))func_08098FDC;
        SetTaskUpdate(a, (u32)f);
        w->unk_28 = 8;
        return f(w, a);
    }

    if (gBtlWork->unk_0A0 == 4) {
        w->unk_28 = 8;
        SetTaskUpdate(a, (u32)func_08099048);
    }

    if (*(u8*)w->unk_2C.unk_08 == 0) {
        w->unk_28 = 8;
        SetTaskUpdate(a, (u32)func_08099048);
    }

    return 1;
}
#else
INCLUDE_ASM("card/REV_COUNT_1.s");
#endif

u8 func_08098FDC(UnkStruct_08098CE4* w) {
    switch (w->unk_2C.unk_0D) {
    case 1:
        ApproachValue(&w->unk_3C, -0x2000, w->unk_28);
        break;
    case 2:
        ApproachValue(&w->unk_3C, 0x11000, w->unk_28);
        break;
    }

    if (w->unk_28 != 0) {
        w->unk_28--;
    }

    if (w->unk_2C.unk_0C == *(u8*)w->unk_2C.unk_00 && *(s16*)w->unk_2C.unk_04 > 0) {
        return 0;
    }

    return 1;
}

u8 func_08099048(UnkStruct_08098CE4* w, void* a) {
    u8 (*f)(UnkStruct_08098CE4*, void*);

    switch (w->unk_2C.unk_0D) {
    case 1:
        ApproachValue(&w->unk_3C, -0x2000, w->unk_28);
        break;
    case 2:
        ApproachValue(&w->unk_3C, 0x11000, w->unk_28);
        break;
    }

    if (w->unk_28 == 0) {
        return 0;
    }

    w->unk_28--;

    if (*(u8*)w->unk_2C.unk_08 == 1) {
        w->unk_28 = 8;
        f = REV_COUNT_1;
        SetTaskUpdate(a, (void*)f);
        return f(w, a);
    }

    return 1;
}

u8 func_080990CC(UnkStruct_08098CE4* w, void* a) {
    u8 (*f)(UnkStruct_08098CE4*, void*);

    switch (w->unk_2C.unk_0D) {
    case 1:
        ApproachValue(&w->unk_3C, -0x2000, w->unk_28);
        break;
    case 2:
        ApproachValue(&w->unk_3C, 0x11000, w->unk_28);
        break;
    }

    if (w->unk_28 != 0) {
        w->unk_28--;
    }

    do {
        if (w->unk_24 == 0) {
            if (*(s16*)w->unk_2C.unk_04 > 1) {
                f = REV_COUNT_1;
                SetTaskUpdate(a, (void*)f);
                w->unk_28 = 8;
                return f(w, a);
            }
        } else {
            if (*(s16*)w->unk_2C.unk_04 > 0) {
                f = REV_COUNT_1;
                SetTaskUpdate(a, (void*)f);
                w->unk_28 = 8;
                return f(w, a);
            }
        }

        return 1;
    } while (0);
}
void REV_COUNT_2(UnkStruct_08098CE4* w) {
#ifdef VERSION_EU
    DrawSprite(w->unk_3C >> 8, w->unk_40 >> 8, 0,
               w->unk_00, w->unk_04, 0, 1040, 15);
#else
    DrawSprite(w->unk_3C >> 8, w->unk_40 >> 8, 0,
               w->unk_00, w->unk_04, 0, 1024, 15);
#endif
}
void REV_COUNT_3(UnkStruct_08098CE4* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
}

void func_080991CC(void* pool, u8* a, void* b, u8* c, u8 d) {
    UnkStruct_080991CC args;

    c[0] = 1;
    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_08 = c;
    args.unk_0C = a[0];
    args.unk_0D = d;
    TaskCreate(pool, gTaskDescREVCOUNT, &args);
}

void RELOAD_0(UnkStruct_080991F8* w, UnkStruct_080991F8_Args* a) {
    w->tiles = AllocObjTiles(0xA0, 0);
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
    *(UnkStruct_080991F8_Args*)&w->unk_2C = *a;
    func_08002A10(w->tiles, gUnk_09EE7708[w->unk_2C]);
    AnimInit(&w->anim, gUnk_09EE7714[w->unk_2C], gUnk_09EE7720[w->unk_2C]);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);

    switch (w->unk_2D) {
    case 1:
        w->unk_24 = -0x3000;
        w->unk_28 = 0x7E00;
        break;
    case 2:
        w->unk_24 = 0xB4800;
        w->unk_28 = 0x7E00;
        break;
    }

    w->unk_34 = 6;
}

u8 RELOAD_1(u8* work, void* a) {
    *(void**)&work[8] = AnimUpdate(&work[0x0C]);

    switch (work[0x2D]) {
    case 1:
        ApproachValue(&work[0x24], 0x1800, work[0x34]);
        break;
    case 2:
        ApproachValue(&work[0x24], 0xD800, work[0x34]);
        break;
    }

    if (work[0x34] != 0) {
        work[0x34]--;
    }

    if (**(u8**)&work[0x30] == 0) {
        work[0x34] = 8;
        SetTaskUpdate(a, (void*)func_08099330);
    }

    if (gBtlWork->unk_0A0 == 4) {
        work[0x34] = 8;
        SetTaskUpdate(a, (void*)func_08099330);
    }

    return 1;
}

u8 func_08099330(u8* work) {
    *(void**)&work[8] = AnimUpdate(&work[0x0C]);

    switch (work[0x2D]) {
    case 1:
        ApproachValue(&work[0x24], -0x3000, work[0x34]);
        break;
    case 2:
        ApproachValue(&work[0x24], 0x12000, work[0x34]);
        break;
    }

    if (work[0x34] != 0) {
        work[0x34]--;
        return 1;
    }

    return 0;
}

void RELOAD_2(u8* work) {
    DrawSprite(*(s32*)&work[0x24] >> 8, *(s32*)&work[0x28] >> 8,
               *(void**)&work[0x08], *(void**)&work[0x00], *(void**)&work[0x04], 0,
               0, 10);
}
void RELOAD_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}
void PrizeBoss_0(UnkStruct_08099928* w, s32* args) {
    CardDef* def;
    CardBack* back;
    u8* p;

    w->unk_B8 = args[8];
    def = &gCardDefs[args[8]];
    w->unk_00 = LoadObjTiles(def->unk_04, 0x300);
    w->unk_04 = LoadObjPalette(def->unk_08, 32);
    w->unk_34 = *(UnkStruct_08099412*)&def->unk_1C;
    back = &gUnk_08F709B0[def->unk_2A];
    w->unk_08 = LoadObjTiles(back->unk_0C, 0x280);
    w->unk_0C = LoadObjTiles(*(void**)back->unk_14, 0x600);
    w->unk_10 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_14 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_18 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_1C = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_A8 = args[0];
    w->unk_AC = args[1];
    w->unk_B0 = args[2];
    w->unk_B4 = 0;
    w->unk_E6 = 24;
    w->unk_BC = -(GetRandom() % 129 + 0x300);
    w->unk_C0 = GetRandom() % 129 + 0x80;
    w->unk_E4 = GetRandom() % 256;
    w->unk_D0 = 0x80;
    w->unk_D2 = 0x80;
    w->unk_E2 = 0x80;
    w->unk_E8 = 0;
    w->unk_E9 = 0;
    p = &w->unk_4C[0];
    func_080122AC(p, 5, 8, 10);
    func_08012614(p, 1);
    func_08012324(p, w->unk_A8, w->unk_AC, w->unk_B0);
    w->unk_EA = 0;
    w->unk_ED = 0;
    w->unk_EB = 0;
    w->unk_EC = 0;
    w->unk_EE = 0;
    w->unk_EF = 0;
    m4aSongNumStart(0x22B);
    TaskPoolInit(&w->unk_20, 10);
    gBtlWork->unk_0B0++;
}
u8 PrizeBoss_1(UnkStruct_08099928* w, void* a) {
    s16 x;
    s16 y;
    if (w->unk_B0 < 0) {
        w->unk_B0 += 51;
        func_08099CDC(w);
    }
    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(&w->unk_4C[0], 30);
    } else {
        ColliderSetRadius(&w->unk_4C[0], 10);
    }
    func_08012324(&w->unk_4C[0], w->unk_A8, w->unk_AC, w->unk_B0);
    WorldToScreen((s16*)&w->unk_D6, (s16*)&w->unk_D8, w->unk_A8, w->unk_AC, w->unk_B0);
    WorldToScreen(&w->unk_DE, &w->unk_E0, w->unk_A8, w->unk_AC, w->unk_B4);
    w->unk_D4 = -0x1004 - (w->unk_AC >> 8) * 4;
    func_08099928(w);
    w->unk_E9 += 2;
    if (w->unk_EA == 60) {
        func_08012614(&w->unk_4C[0], 0);
    }
    if (w->unk_EA <= 59) {
        w->unk_EA++;
    }
    if (w->unk_4C[0x2C] != 0) {
        w->unk_ED = 1;
        m4aSongNumStart(106);
        func_08084458(*(u16*)&w->unk_B8);
        if (gGameState.flags & 8) {
            _08085D04(gGameState.unk_00C[0]);
        }
        SetTaskUpdate(a, (void*)func_08099A18);
        WorldToScreen(&x, &y, w->unk_A8, w->unk_AC, w->unk_B0);
        w->unk_A8 = x << 8;
        w->unk_AC = y << 8;
        func_08012614(&w->unk_4C[0], 1);
        w->unk_EB = 16;
        w->unk_D4 = 50;
        func_080999A4(w);
    }
    TaskPoolUpdate(&w->unk_20);
    return 1;
}

void PrizeBoss_2(UnkStruct_08099928* w) {
    u8* work = (u8*)w;
    u16 pal;
    s32 affine;
    void* gfx;
    CardBack* back;
    CardDef* def;
    s16 v;

    pal = work[0xED] == 0 ? func_0801AF1C(*(s32*)&work[0xAC]) : 0;
    affine = AllocObjAffine(work[0xE6], *(s16*)&work[0xD0], *(s16*)&work[0xD2], 1);
    def = &gCardDefs[*(s32*)&work[0xB8]];
    DrawSprite(*(s16*)&work[0xD6], *(u16*)&work[0xD8] - 8, def->unk_00,
               *(void**)&work[0x00], *(void**)&work[0x04], affine, pal,
               (u16)(*(u16*)&work[0xD4] + 1));
    back = &gUnk_08F709B0[work[0x42]];
    DrawSprite(*(s16*)&work[0xD6], *(u16*)&work[0xD8] - 8,
               back->unk_00, *(void**)&work[0x08],
               *(void**)&work[0x10], affine, pal, *(u16*)&work[0xD4]);
    gfx = gUnk_09EE981C[work[0x38]];

    if (def->unk_2A != 3) {
        DrawSprite(*(s16*)&work[0xD6], *(u16*)&work[0xD8] - 8, gfx,
                   *(void**)&work[0x14], *(void**)&work[0x10], affine, pal,
                   (u16)(*(u16*)&work[0xD4] - 1));
    }

    if (work[0xED] == 0) {
        v = 204 - ((*(s32*)&work[0xB4] - *(s32*)&work[0xB0]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(*(s16*)&work[0xDE], *(s16*)&work[0xE0], gUnk_09EE1380[0],
                   *(void**)&work[0x18], *(void**)&work[0x1C],
                   AllocObjAffine(0, v, v, 0), pal,
                   (u16)(*(u16*)&work[0xD4] + 2));
    }

    TaskPoolDraw(&work[0x20]);
}

void PrizeBoss_3(UnkStruct_08099928* w) {
    func_080062F4(w->unk_10->unk_06 + 16, 0);
    func_080062F4(w->unk_04->unk_06 + 16, 0);
    func_08012304(&w->unk_4C[0]);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjTiles(w->unk_0C);
    ReleaseObjTiles(w->unk_18);
    ReleaseObjPalette(w->unk_04);
    ReleaseObjPalette(w->unk_10);
    ReleaseObjPalette(w->unk_1C);
    TaskPoolDestroy(&w->unk_20);
    gBtlWork->unk_0B0--;
}

void func_08099928(UnkStruct_08099928* w) {
    w->unk_D0 = (-gSineTable[((w->unk_E9 + 0x80) & 0xFF) + 0x40] * w->unk_E2) >> 8;
    w->unk_D2 = (-gSineTable[((w->unk_E8 + 0x80) & 0xFF) + 0x40] * w->unk_E2) >> 8;

    if ((u16)(w->unk_D0 + 2) <= 4) {
        w->unk_D0 = 2;
    }

    if ((u16)(w->unk_D2 + 2) <= 4) {
        w->unk_D2 = 2;
    }
}

void func_080999A4(UnkStruct_08099928* w) {
    s16 x;
    s16 y;
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    WorldToScreen(&x, &y, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    tx = 0x7800;
    ty = 0x5000;
    dx = tx - w->unk_A8;
    dy = ty - w->unk_AC;
    w->unk_CC = func_0805F5A4(&dx, &dy);
    w->unk_C4 = -dx;
    w->unk_C8 = -dy;
    w->unk_C0 = 0x300;
    w->unk_BC = 2;
}

u8 func_08099A18(UnkStruct_08099928* w, void* a) {
    s32 dx;
    s32 dy;
    u8 z;
    u8 t;
    s32 x;
    s32 y;
    s16* q1;
    s16* q2;

    if (w->unk_C0 < 0) {
        dx = 0x7800 - w->unk_A8;
        dy = 0x5000 - w->unk_AC;
        func_0805F5A4(&dx, &dy);
        w->unk_C4 = -dx;
        w->unk_C8 = -dy;

        if (w->unk_CC <= 0x7FF) {
            w->unk_EB = 0;
            w->unk_E6 = 0;
            SetTaskUpdate(a, (void*)func_08099B60);
#ifdef VERSION_EU
            func_08096F08(&w->unk_20, eu_0805E924(gCardDefs[w->unk_B8].unk_0C));
#else
            func_08096F08(&w->unk_20, gCardDefs[w->unk_B8].unk_0C);
#endif
        }
    }

    w->unk_A8 += (w->unk_C4 * w->unk_C0) >> 8;
    w->unk_AC += (w->unk_C8 * w->unk_C0) >> 8;
    t = w->unk_E6 + 32;
    z = 0;
    w->unk_E6 = t;
    w->unk_E8 += (64 - w->unk_E8) >> 4;
    w->unk_E9 = z;
    w->unk_CC = func_0805F588(0x7800 - w->unk_A8, 0x5000 - w->unk_AC);
    w->unk_C0 -= w->unk_BC;
    w->unk_BC += 2;

    if (w->unk_E2 <= 0xFF) {
        w->unk_E2 += 3;
    }

    x = w->unk_A8 >> 8;
    q1 = (s16*)&w->unk_D6;
    *q1 = x;
    y = w->unk_AC >> 8;
    q2 = (s16*)&w->unk_D8;
    *q2 = y;
    func_08099928(w);
    TaskPoolUpdate(&w->unk_20);
    return 1;
}

u8 func_08099B60(UnkStruct_08099928* w, void* a) {
    s32 v;
    u16 t;
    s32 c;

    v = w->unk_E6 << 8;
    ApproachValue((s32*)&w->unk_E8, 0, w->unk_EB);
    ApproachValue(&v, 0, w->unk_EB);
    ApproachValue(&w->unk_A8, 0x7800, w->unk_EB);
    ApproachValue(&w->unk_AC, 0x5800, w->unk_EB);
    w->unk_E6 = v >> 8;

    if (w->unk_EB != 0) {
        w->unk_EB--;
    }

    t = w->unk_E2;

    if ((s16)t <= 0xFF) {
        w->unk_E2 = t + 2;
    } else {
        c = 0x100;
        w->unk_E2 = c;
    }

    w->unk_D6 = w->unk_A8 >> 8;
    w->unk_D8 = w->unk_AC >> 8;
    func_08099928(w);
    w->unk_EC++;

    if ((u32)w->unk_B8 > 0x1C2) {
        if (w->unk_EC == 120) {
            w->unk_EC = 0;
            SetTaskUpdate(a, (void*)func_08099C4C);
        }
    } else {
        if (w->unk_EC == 30) {
            w->unk_EC = 0;
            SetTaskUpdate(a, (void*)func_08099C4C);
        }
    }

    TaskPoolUpdate(&w->unk_20);
    return 1;
}

u8 func_08099C4C(UnkStruct_08099928* w) {
    w->unk_E6 += 32;
    WorldToScreen(&w->unk_DA, &w->unk_DC, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    *(s16*)&w->unk_D6 += (w->unk_DA - *(s16*)&w->unk_D6) >> 3;
    *(s16*)&w->unk_D8 += (w->unk_DC - *(s16*)&w->unk_D8) >> 3;
    w->unk_D0 -= 10;
    w->unk_D2 -= 10;

    if (w->unk_D0 <= 10) {
        return 0;
    }

    TaskPoolUpdate(&w->unk_20);
    return 1;
}

void func_08099CDC(UnkStruct_08099928* w) {
    u8* work = (u8*)w;
    UnkStruct_08099CDC_Args args;

    if (work[0xED] == 0) {
        if (work[0xEF] == 8) {
            if (work[0xEE] <= 3) {
                args.unk_00 = *(s32*)&work[0xA8];
                args.unk_04 = *(s32*)&work[0xAC];
                args.unk_08 = *(s32*)&work[0xB0];
                args.unk_0C = work[0xED];
                args.unk_10 = &work[0xEE];
                TaskCreate(&work[0x20], gTaskDescCardEFFECT, &args);
            }

            work[0xEF] = 0;
        } else {
            work[0xEF]++;
        }
    } else {
        if (work[0xEF] == 8) {
            if (work[0xEE] <= 7) {
                args.unk_00 = *(s32*)&work[0xA8];
                args.unk_04 = *(s32*)&work[0xAC];
                args.unk_08 = *(s32*)&work[0xB0];
                args.unk_0C = work[0xED];
                args.unk_10 = &work[0xEE];
                TaskCreate(&work[0x20], gTaskDescCardEFFECT, &args);
            }

            work[0xEF] = 0;
        } else {
            work[0xEF]++;
        }
    }
}

void Card_EFFECT_0(UnkStruct_08099E70* w, UnkStruct_08099CDC_Args* a) {
    *(UnkStruct_08099CDC_Args*)&w->unk_38 = *a;

    if (w->unk_44 == 0) {
        w->unk_24 = a->unk_00 + ((GetRandom() % 9 - 4) << 8);
        w->unk_28 = a->unk_04;
        w->unk_2C = a->unk_08 - 0x800;
    } else {
        w->unk_24 = a->unk_00 + ((GetRandom() % 33 - 16) << 8);
        w->unk_28 = a->unk_04 - 0x1000;
        w->unk_2C = 0;
    }

    w->tiles = AllocObjTiles(0x80, 0);
    w->palette = LoadObjPalette(gUnk_09619158, 32);
    func_08002A10(w->tiles, gUnk_093F762E);
    AnimInit(&w->anim, gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&w->anim, GetRandom() % 3, 0);
    w->gfx = AnimGetGfx(&w->anim);
    (*w->unk_48)++;
}

u8 Card_EFFECT_1(UnkStruct_08099E70* w) {
    w->gfx = AnimUpdate(&w->anim);

    if (w->unk_44 == 0) {
        WorldToScreen(&w->unk_30, &w->unk_32, w->unk_24, w->unk_28, w->unk_2C);
        w->unk_2C -= 0x100;
    } else {
        w->unk_30 = w->unk_24 >> 8;
        w->unk_32 = w->unk_28 >> 8;
        w->unk_28 -= 0x100;
    }

    if (AnimIsFinished(&w->anim)) {
        return 0;
    }

    return 1;
}

void Card_EFFECT_2(u8* work) {
    s16 t;
    s32 z;

    t = -4100 - ((*(s16*)&work[0x32] >> 8) * 4);
    z = 0;
    *(u16*)&work[0x34] = t;
    DrawSprite(*(s16*)&work[0x30], *(s16*)&work[0x32], *(void**)&work[0x20],
               *(void**)&work[0x00], *(void**)&work[0x04], z, z,
               *(u16*)&work[0x34]);
}

void Card_EFFECT_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    (*(u8**)&work[0x48])[0]--;
}

void scrollbar_0(ScrollBarWork* w, u16* args) {
    w->unk_08 = args[0];
    w->unk_0A = args[1];
    w->unk_0C = args[2];
    w->unk_10 = args[3];
    w->unk_12 = args[4];
    w->unk_16 = 1;
    w->unk_0E = 0;
    w->unk_17 = 0;
}

u8 scrollbar_1(ScrollBarWork* w) {
    return w->unk_16;
}
void scrollbar_2(void) {
}
void scrollbar_3(void) {
}
void func_08099F74(ScrollBarWork* w) {
    if (w != 0) {
        w->unk_16 = 0;
    }
}
void func_08099F80(ScrollBarWork* w) {
    if (w != 0) {
        if (w->unk_12 != 0) {
            w->unk_10++;
            w->unk_12--;
        } else {
            w->unk_12 = w->unk_14 - 1;
            w->unk_10 = 0;
        }
    }
}
void func_08099FA4(ScrollBarWork* w) {
    if (w != 0) {
        if (w->unk_10 != 0) {
            w->unk_10--;
            w->unk_12++;
        } else {
            w->unk_10 = w->unk_14 - 1;
            w->unk_12 = 0;
        }
    }
}
void func_08099FC8(ScrollBarWork* w) {
    if (w != 0) {
        w->unk_14--;
    }
}
void func_08099FD8(ScrollBarWork* w) {
    if (w != 0) {
        w->unk_14++;
    }
}
void func_08099FE8(ScrollBarWork* w, u16 b, u8 c) {
    if (w != 0) {
        w->unk_0E = b;
        w->unk_17 = c;
    }
}
s32 func_08099FFC(void* pool, u16 a, u16 b, u16 c, u16 d, u16 e) {
    u16 args[5];

    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    args[4] = e;
    return (s32)((void**)TaskCreate(pool, gTaskDescScrollbar, args))[1];
}

void func_0809A02C(UnkStruct_0809A02C* w, s32* args) {
    u8* p;

    w->unk_1A0 = args[3];
    w->unk_38 = args[0];
    w->unk_3C = args[1];
    w->unk_40 = args[2];
    w->unk_44 = 0;
    w->unk_1C6 = GetRandom();
    w->unk_1A4 = -(GetRandom() % 129 + 0x300);
    w->unk_1A8 = GetRandom() % 129 + 0x80;
    w->unk_1C7 = 0;
    w->unk_1C8 = 0;
    w->unk_1C9 = 24;
    w->unk_1B8 = 0x80;
    w->unk_1BA = 0x80;
    w->unk_1BC = 0x80;
    w->unk_1CA = 0;
    w->unk_1CB = 0;
    w->unk_1CC = 0;
    w->unk_1C4 = 0;
    w->unk_1CD = 1;
    w->unk_1C = &gCardDefs[args[3]];

    if (w->unk_1C->unk_1E & 8) {
        w->unk_1CE = 3;
    } else {
        w->unk_1CE = w->unk_1C->unk_2A;
    }

    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_10 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_08 = LoadObjTiles(w->unk_1C->unk_04, 0x300);
    w->unk_0C = LoadObjPalette(w->unk_1C->unk_08, 32);
    w->unk_14 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_18 = LoadObjPalette(gUnk_08F69BA4, 32);
    p = w->unk_144;
    func_080122AC(p, 5, 8, 10);
    func_08012324(p, w->unk_38, w->unk_3C, w->unk_40);
    TaskPoolInit(&w->unk_20, 1);
    gBtlWork->unk_0B0++;
}

void func_0809A1B8(UnkStruct_0809A02C* w, s32* args) {
    u8* p;

    w->unk_1A0 = args[3];
    w->unk_38 = args[0];
    w->unk_3C = args[1];
    w->unk_40 = args[2];
    w->unk_44 = 0;
    w->unk_1C6 = GetRandom();
    w->unk_1A4 = -(GetRandom() % 129 + 0x300);
    w->unk_1A8 = GetRandom() % 129 + 0x80;
    w->unk_1C7 = 0;
    w->unk_1C8 = 0;
    w->unk_1C9 = 24;
    w->unk_1B8 = 0x80;
    w->unk_1BA = 0x80;
    w->unk_1BC = 0x80;
    w->unk_1CA = 0;
    w->unk_1CB = 0;
    w->unk_1CC = 0;
    w->unk_1C4 = 0;
    w->unk_1CD = 1;
    w->unk_1C = &gCardDefs[args[3]];

    if (w->unk_1C->unk_1E & 8) {
        w->unk_1CE = 3;
    } else {
        w->unk_1CE = w->unk_1C->unk_2A;
    }

    w->unk_00 = LoadObjTiles(gUnk_08F709B0[w->unk_1CE].unk_0C, 0x280);
    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_10 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_08 = LoadObjTiles(w->unk_1C->unk_04, 0x300);
    w->unk_0C = LoadObjPalette(w->unk_1C->unk_08, 32);
    w->unk_14 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_18 = LoadObjPalette(gUnk_08F69BA4, 32);
    p = w->unk_144;
    func_080122AC(p, 5, 8, 10);
    func_08012324(p, w->unk_38, w->unk_3C, w->unk_40);
    TaskPoolInit(&w->unk_20, 1);
    gBtlWork->unk_0B0++;
}


void func_0809A368(UnkStruct_0809A02C* w, UnkStruct_0809A368_Args* args) {
    u8* p;

    w->unk_1A0 = args->unk_0C;
    w->unk_38 = args->unk_00;
    w->unk_3C = args->unk_04;
    w->unk_40 = args->unk_08;
    w->unk_44 = 0;
    w->unk_1C6 = GetRandom();
    w->unk_1A4 = -((u16)(GetRandom() % 129) + 0x300);
    w->unk_1A8 = (u16)(GetRandom() % 129) + 0x80;
    w->unk_1C7 = 0;
    w->unk_1C8 = 0;
    w->unk_1C9 = 24;
    w->unk_1B8 = 0x80;
    w->unk_1BA = 0x80;
    w->unk_1BC = 0x80;
    w->unk_1CA = 0;
    w->unk_1CB = 0;
    w->unk_1CC = 0;
    w->unk_1C4 = 0;
    w->unk_1CD = 1;
    w->unk_1C = &gCardDefs[args->unk_0C];
    w->unk_1CE = w->unk_1C->unk_2A;
    w->unk_04 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_10 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_08 = LoadObjTiles(w->unk_1C->unk_04, 0x300);
    w->unk_0C = LoadObjPalette(w->unk_1C->unk_08, 32);
    w->unk_14 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_18 = LoadObjPalette(gUnk_08F69BA4, 32);
    p = w->unk_144;
    func_080122AC(p, 5, 8, 10);
    func_08012324(p, w->unk_38, w->unk_3C, w->unk_40);
    TaskPoolInit(&w->unk_20, 1);
    gBtlWork->unk_0B0++;
}

void func_0809A4E0(UnkStruct_0809A02C* w, u8 kind) {
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    if (kind == 1) {
        tx = 0x7800;
        ty = 0x5000;
    } else {
        tx = 0;
        ty = 0xA000;
    }

    dx = tx - w->unk_38;
    dy = ty - w->unk_3C;
    w->unk_1AC = func_0805F5A4(&dx, &dy);
    w->unk_1B0 = -dx;
    w->unk_1B4 = -dy;
    w->unk_1A8 = 0x300;
    w->unk_1A4 = 2;
}

#ifndef VERSION_EU
s32 func_0809A54C(UnkStruct_0809A02C* w, void* a) {
    s16 sx;
    s32 t;
    u16 n;
    s16 sy;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    w->unk_1A4 += *(s32*)&gBtlWork->unk_100[0x2C];
    w->unk_40 += w->unk_1A4;
    w->unk_38 += (gSineTable[w->unk_1C6] * w->unk_1A8) >> 8;
    w->unk_3C += (-gSineTable[w->unk_1C6 + 64] * w->unk_1A8) >> 8;

    if (func_0801A8A4(&w->unk_38, &w->unk_3C, -10, -10) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_40 - 0x800 > w->unk_44) {
        w->unk_40 = w->unk_44 - 0x800;
        w->unk_1A4 = -((204 * w->unk_1A4) >> 8);
        w->unk_1C6 = GetAngle(w->unk_38, w->unk_3C,
                               ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04,
                               ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08);
        w->unk_1C6 = (u8)(w->unk_1C6 + 224) + GetRandom() % 65;

        if (w->unk_1A4 > -0x200) {
            w->unk_1A4 = -0x200;
        }
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_144, 50);
    } else {
        ColliderSetRadius(w->unk_144, 10);
    }

    if ((u8)func_0801C6D4(&w->unk_38, &w->unk_3C, &w->unk_40,
                          &w->unk_44) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_170 != 0) {
        m4aSongNumStart(106);

        if (gUnk_02039DD4 != 0) {
            WorldToScreen(&sx, &sy, w->unk_38, w->unk_3C,
                          w->unk_40);
            w->unk_38 = sx << 8;
            w->unk_3C = sy << 8;
            w->unk_1CA = 1;
            func_08012614(w->unk_144, 1);
            func_0809A4E0(w, 0);
            SetTaskUpdate(a, (u32)func_0809AB2C);
        }

        return 1;
    }

    func_08012324(w->unk_144, w->unk_38, w->unk_3C,
                  w->unk_40);
    w->unk_1B8 =
        (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;
    w->unk_1BA =
        (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    w->unk_1C7 += 2;
    w->unk_1C2 = -0x1004 - (w->unk_3C >> 8) * 4;
    TaskPoolUpdate(&w->unk_20);

    if (gBtlWork->unk_068 & 0x800000000) {
        return 1;
    }

    n = w->unk_1C4;

    if (n > 359) {
        return 0;
    }

    t = n + 1;
    w->unk_1C4 = t;

    if (w->unk_1C4 > 279 && t % 4 == 0) {
        w->unk_1CD ^= 1;
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809A54C.s");
#endif
#ifndef VERSION_EU
s32 func_0809A840(UnkStruct_0809A02C* w, void* a) {
    s16 sx;
    s32 t;
    u16 n;
    s16 sy;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    w->unk_1A4 += 56;
    w->unk_40 += w->unk_1A4;
    w->unk_38 += (gSineTable[w->unk_1C6] * w->unk_1A8) >> 8;
    w->unk_3C += (-gSineTable[w->unk_1C6 + 64] * w->unk_1A8) >> 8;

    if (func_0801A8A4(&w->unk_38, &w->unk_3C, -10, -10) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_40 - 0x800 > w->unk_44) {
        w->unk_40 = w->unk_44 - 0x800;
        w->unk_1A4 = -((204 * w->unk_1A4) >> 8);
        w->unk_1C6 = GetAngle(w->unk_38, w->unk_3C,
                               ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04,
                               ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08);
        w->unk_1C6 = (u8)(w->unk_1C6 + 224) + GetRandom() % 65;

        if (w->unk_1A4 > -0x200) {
            w->unk_1A4 = -0x200;
        }
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_144, 50);
    } else {
        ColliderSetRadius(w->unk_144, 10);
    }

    if ((u8)func_0801C6D4(&w->unk_38, &w->unk_3C, &w->unk_40,
                          &w->unk_44) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_170 != 0) {
        m4aSongNumStart(106);

        if (gUnk_02039DD4 != 0) {
            WorldToScreen(&sx, &sy, w->unk_38, w->unk_3C,
                          w->unk_40);
            w->unk_38 = sx << 8;
            w->unk_3C = sy << 8;
            w->unk_1CA = 1;
            func_08012614(w->unk_144, 1);
            func_0809A4E0(w, 0);
            SetTaskUpdate(a, (u32)func_0809AB2C);
        }

        return 1;
    }

    func_08012324(w->unk_144, w->unk_38, w->unk_3C,
                  w->unk_40);
    w->unk_1B8 =
        (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;
    w->unk_1BA =
        (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    w->unk_1C7 += 2;
    w->unk_1C2 = -0x1004 - (w->unk_3C >> 8) * 4;
    TaskPoolUpdate(&w->unk_20);

    n = w->unk_1C4;

    if (n > 359) {
        *(u8*)&gUnk_02039DD4->unk_0DC -= 1;
        return 0;
    }

    t = n + 1;
    w->unk_1C4 = t;

    if (w->unk_1C4 > 279 && t % 4 == 0) {
        w->unk_1CD ^= 1;
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809A840.s");
#endif
u8 func_0809AB2C(UnkStruct_0809A02C* w) {
    s32 dx;
    s32 dy;
    u16 t;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    if (w->unk_1A8 < 0) {
        dx = -w->unk_38;
        dy = 0xA000 - w->unk_3C;
        func_0805F5A4(&dx, &dy);
        w->unk_1B0 = -dx;
        w->unk_1B4 = -dy;

        if (w->unk_1AC < 0x800) {
            if (w->unk_1A0 >= 655 && w->unk_1A0 <= 659) {
                gUnk_02039DD4->unk_0BC = w->unk_1A0;
            } else {
                gUnk_02039DD4->unk_0B8 = w->unk_1A0;
            }

            return 0;
        }
    }

    w->unk_38 += (w->unk_1B0 * w->unk_1A8) >> 8;
    w->unk_3C += (w->unk_1B4 * w->unk_1A8) >> 8;
    w->unk_1C9 += 32;
    w->unk_1C8 += (64 - w->unk_1C8) >> 4;
    w->unk_1C7 = 0;
    w->unk_1AC = func_0805F588(-w->unk_38, 0xA000 - w->unk_3C);
    w->unk_1A8 -= w->unk_1A4;
    w->unk_1A4 += 2;
    t = w->unk_1BC;

    if ((s16)t <= 255) {
        w->unk_1BC = t + 3;
    }

    w->unk_1B8 = (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;
    w->unk_1BA = (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    TaskPoolUpdate(&w->unk_20);
    return 1;
}

u8 func_0809ACDC(UnkStruct_0809A02C* w) {
    s16 x;
    s16 y;

    w->unk_1C9 += 32;
    WorldToScreen(&x, &y, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_0C);
    w->unk_38 += ((x << 8) - w->unk_38) >> 3;
    w->unk_3C += ((y << 8) - w->unk_3C) >> 3;
    w->unk_1B8 -= 10;
    w->unk_1BA -= 10;

    if (w->unk_1B8 <= 10) {
        return 0;
    }

    return 1;
}

s32 func_0809AD60(UnkStruct_0809A02C* w, void* a) {
    w->unk_1C4 += 1;

    if (w->unk_1C4 == 60) {
        SetTaskUpdate(a, func_0809ACDC);
    }

    TaskPoolUpdate(&w->unk_20);
    return 1;
}
#ifndef VERSION_EU
s32 func_0809AD98(UnkStruct_0809A02C* w, void* a) {
    s32 dx = 0;
    s32 dy = 0;
    s32 v;
    u16 t;

    if (w->unk_1A8 < 0) {
        dx = 0x7800 - w->unk_38;
        dy = 0x5000 - w->unk_3C;
        func_0805F5A4(&dx, &dy);
        w->unk_1B0 = -dx;
        w->unk_1B4 = -dy;

        if (w->unk_1AC < 0x800) {
            w->unk_1C8 = 0;
            w->unk_1C9 = 0;
            w->unk_1C7 = 0;
            w->unk_38 = 0x7800;
            w->unk_3C = 0x5000;
            *(u16*)&w->unk_1B8 = v = 0x100;
            *(u16*)&w->unk_1BA = v;
            func_08096F08(&w->unk_20, gCardDefs[w->unk_1A0].unk_0C);
            SetTaskUpdate(a, (void*)func_0809AD60);
            w->unk_1C4 = 0;
            w->unk_1C2 = 50;
            return 1;
        }
    }

    w->unk_38 += (w->unk_1B0 * w->unk_1A8) >> 8;
    w->unk_3C += (w->unk_1B4 * w->unk_1A8) >> 8;
    w->unk_1C9 += 32;
    w->unk_1C8 += (64 - w->unk_1C8) >> 4;
    w->unk_1C7 = 0;
    w->unk_1AC = func_0805F588(0x7800 - w->unk_38, 0x5000 - w->unk_3C);
    w->unk_1A8 -= w->unk_1A4;
    w->unk_1A4 += 2;
    t = w->unk_1BC;

    if ((s16)t <= 255) {
        w->unk_1BC = t + 3;
    }

    w->unk_1B8 = (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;
    w->unk_1BA = (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    TaskPoolUpdate(&w->unk_20);
    return 1;
}
#else
INCLUDE_ASM("card/func_0809AD98.s");
#endif
#ifndef VERSION_EU
s32 func_0809AF84(UnkStruct_0809A02C* w, void* a) {
    s16 x;
    s16 y;

    w->unk_1A4 += 0x38;
    w->unk_40 += w->unk_1A4;
    w->unk_38 += (gSineTable[w->unk_1C6] * w->unk_1A8) >> 8;
    w->unk_3C += (-gSineTable[w->unk_1C6 + 64] * w->unk_1A8) >> 8;

    if (func_0801A8A4(&w->unk_38, &w->unk_3C, -10, -10) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 0x70) + GetRandom() % 33;
    }

    if (w->unk_40 - 0x800 > w->unk_44) {
        w->unk_40 = w->unk_44 - 0x800;
        w->unk_1A4 = -((w->unk_1A4 * 204) >> 8);
        w->unk_1C6 = GetAngle(w->unk_38, w->unk_3C, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_04, ((UnkStruct_0809E0A4*)gBtlWork->unk_07C)->unk_08);
        w->unk_1C6 = (u8)(w->unk_1C6 + 0xE0) + GetRandom() % 65;

        if (w->unk_1A4 > -0x200) {
            w->unk_1A4 = -0x200;
        }
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_144, 50);
    } else {
        ColliderSetRadius(w->unk_144, 10);
    }

    if (func_0801C6D4(&w->unk_38, &w->unk_3C, &w->unk_40, &w->unk_44)) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 0x70) + GetRandom() % 33;
    }

    if (w->unk_170 != 0) {
        m4aSongNumStart(0x6A);
        func_08084458(w->unk_1A0);
        WorldToScreen(&x, &y, w->unk_38, w->unk_3C, w->unk_40);
        w->unk_38 = x << 8;
        w->unk_3C = y << 8;
        w->unk_1CA = 1;
        func_08012614(w->unk_144, 1);
        func_0809A4E0(w, 1);
        SetTaskUpdate(a, (void*)func_0809AD98);
        return 1;
    }

    func_08012324(w->unk_144, w->unk_38, w->unk_3C, w->unk_40);
    w->unk_1B8 = (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;
    w->unk_1BA = (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    w->unk_1C7 += 2;
    w->unk_1C2 = -0x1004 - ((w->unk_3C >> 8) << 2);
    TaskPoolUpdate(&w->unk_20);
    return 1;
}
#else
INCLUDE_ASM("card/func_0809AF84.s");
#endif
void func_0809B200(UnkStruct_0809A02C* w) {
    s16 x;
    s16 y;
    s32 affine;
    s16 v;
    u8 kind;

    if (w->unk_1CD != 0) {
        if (w->unk_1CA == 0) {
            w->unk_1D0 = func_0801AF1C(w->unk_3C);
            WorldToScreen(&x, &y, w->unk_38, w->unk_3C,
                          w->unk_40);
        } else {
            w->unk_1D0 = 0;
            x = w->unk_38 >> 8;
            y = w->unk_3C >> 8;
        }

        affine = AllocObjAffine(w->unk_1C9, w->unk_1B8,
                                w->unk_1BA, 0);
        DrawSprite(x, (u16)y - 8,
                   gUnk_08F709B0[w->unk_1C->unk_2A].unk_00,
                   ((UnkStruct_0809B200*)gUnk_02039DD4)->unk_030[w->unk_1C->unk_2A],
                   w->unk_04, affine,
                   w->unk_1D0, w->unk_1C2);
        DrawSprite(x, (u16)y - 8, w->unk_1C->unk_00,
                   w->unk_08, w->unk_0C, affine,
                   w->unk_1D0, (u16)(w->unk_1C2 + 1));
        kind = w->unk_1C->unk_20;
        DrawSprite(x, (u16)y - 8, gUnk_09EE981C[kind],
                   w->unk_10, w->unk_04, affine,
                   w->unk_1D0, (u16)(w->unk_1C2 - 2));
        v = 204 - ((w->unk_44 - w->unk_40) >> 7);

        if (v <= 2) {
            v = 2;
        }

        if (w->unk_1CA == 0) {
            WorldToScreen(&w->unk_1BE, &w->unk_1C0,
                          w->unk_38, w->unk_3C,
                          w->unk_44);
            DrawSprite(w->unk_1BE, w->unk_1C0,
                       gUnk_09EE1380[0], w->unk_14,
                       w->unk_18, AllocObjAffine(0, v, v, 0),
                       w->unk_1D0, (u16)(w->unk_1C2 + 2));
        }

        TaskPoolDraw(&w->unk_20);
    }
}
void func_0809B3F4(UnkStruct_0809A02C* w) {
    s16 x;
    s16 y;
    s32 affine;
    s16 v;

    if (w->unk_1CD != 0) {
        if (w->unk_1CA == 0) {
            w->unk_1D0 = func_0801AF1C(w->unk_3C);
            WorldToScreen(&x, &y, w->unk_38, w->unk_3C,
                          w->unk_40);
        } else {
            w->unk_1D0 = 0;
            x = w->unk_38 >> 8;
            y = w->unk_3C >> 8;
        }

        affine = AllocObjAffine(w->unk_1C9, w->unk_1B8,
                                w->unk_1BA, 0);
        DrawSprite(x, (u16)y - 8,
                   gUnk_08F709B0[w->unk_1C->unk_2A].unk_00,
                   w->unk_00, w->unk_04, affine,
                   w->unk_1D0, w->unk_1C2);
        DrawSprite(x, (u16)y - 8, w->unk_1C->unk_00,
                   w->unk_08, w->unk_0C, affine,
                   w->unk_1D0, (u16)(w->unk_1C2 + 1));
        v = 204 - ((w->unk_44 - w->unk_40) >> 7);

        if (v <= 2) {
            v = 2;
        }

        if (w->unk_1CA == 0) {
            WorldToScreen(&w->unk_1BE, &w->unk_1C0,
                          w->unk_38, w->unk_3C,
                          w->unk_44);
            DrawSprite(w->unk_1BE, w->unk_1C0,
                       gUnk_09EE1380[0], w->unk_14,
                       w->unk_18, AllocObjAffine(0, v, v, 0),
                       w->unk_1D0, (u16)(w->unk_1C2 + 2));
        }

        TaskPoolDraw(&w->unk_20);
    }
}

void func_0809B59C(UnkStruct_0809A02C* w) {
    ReleaseObjPalette(w->unk_04);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjPalette(w->unk_0C);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjPalette(w->unk_18);
    func_08012304(w->unk_144);
    TaskPoolDestroy(&w->unk_20);
    gUnk_02039DD4->unk_0D6 = 0;
    gBtlWork->unk_0B0--;
}

void func_0809B5F4(UnkStruct_0809A02C* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
    ReleaseObjTiles(w->unk_08);
    ReleaseObjPalette(w->unk_0C);
    ReleaseObjTiles(w->unk_14);
    ReleaseObjPalette(w->unk_18);
    func_08012304(w->unk_144);
    TaskPoolDestroy(&w->unk_20);
    gBtlWork->unk_0B0--;
}

void func_0809B644(void* pool, u16 x, u16 y, u16 z, u8 idx) {
    s32 args[4];

    if (gUnk_02039DD4 != 0) {
        if (gUnk_02039DD4->unk_0DA[0] <= 4) {
            if (gUnk_02039DD4->unk_0D6 == 0) {
                args[0] = (s16)x << 8;
                args[1] = (s16)y << 8;
                args[2] = (s16)z << 8;
                args[3] = gUnk_09036210[idx] + GetRandom() % 9;
                TaskCreate(pool, gUnk_09EE778C, args);
                gUnk_02039DD4->unk_0D6++;
            }
        }
    }
}

void func_0809B6D0(void* pool, s16 a, s16 b, s16 c, u16 d) {
    s32 args[4];
    s32* t;

    t = gUnk_09EE275C[d];
    args[0] = a << 8;
    args[1] = b << 8;
    args[2] = c << 8;
    args[3] = t[0];
    TaskCreate(pool, gUnk_09EE77A4, args);
}

void func_0809B710(void* pool, u16 a, u16 b, u16 c, u16 d) {
    s32 args[4];

    if (gUnk_02039DD4 != 0 && gUnk_02039DD4->unk_0DC == 0) {
        gUnk_02039DD4->unk_0DC++;
        args[0] = (s16)a << 8;
        args[1] = (s16)b << 8;
        args[2] = (s16)c << 8;
        args[3] = d;
        TaskCreate(pool, gUnk_09EE77BC, args);
    }
}

void func_0809B76C(u8* work, void** src) {
    u8 i;
    void** dst;
    void** q;
    void** s;
    s32 z;
    UnkStruct_080038C8* obj;

    if (src != 0) {
        s = src;

        for (i = 0; i < 6; i++) {
            dst = (void**)&work[0x18];
            q = &dst[i];
            *q = s[i];
        }

        work[0x30] = 1;
    } else {
        work[0x30] = 0;
    }

    z = 0;
    work[0x11] = z;
    *(u16*)&work[4] = z;
    obj = func_080038C8(0x3C0);
    *(UnkStruct_080038C8**)&work[8] = obj;

    if (work[0x30] == 0) {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_04);
        u = LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_00);
        func_080038E4(obj, t[gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_0A], u);
#else
        func_080038E4(obj, gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_04[gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_0A], gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].unk_00);
#endif
    } else {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].unk_04);
        u = LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].unk_00);
        func_080038E4(obj, t[gUnk_08F7CF18[*(u32*)&work[0x18]].unk_0A], u);
#else
        func_080038E4(obj, gUnk_08F7CF18[*(u32*)&work[0x18]].unk_04[gUnk_08F7CF18[*(u32*)&work[0x18]].unk_0A], gUnk_08F7CF18[*(u32*)&work[0x18]].unk_00);
#endif
    }

    *(void**)&work[0xC] = LoadObjPalette(gUnk_08F69BA4, 32);
    work[0x31] = 1;
    *(u32*)&work[0x14] = gUnk_02039DD4->unk_0C4;
}

#ifndef VERSION_EU
u8 func_0809B840(u8* work) {
    u8* tbl;
    s32 ofs;

    if (gUnk_02039DD4->unk_0E3 == 0 || gUnk_02039DD4->unk_0C4 != *(u32*)&work[0x14]) {
        return 0;
    }

    if ((gFrameCounter >> 5) & 1) {
        work[0x31] = 1;
    } else {
        work[0x31] = 0;
    }

    if (work[0x30] == 1 && work[0x31] != 0) {
        work[0x11]++;
        ofs = work[0x11] * 4;
        tbl = &work[0x18];

        if (*(s32*)(tbl + ofs) == -1) {
            work[0x11] = 0;
        }

        func_080038E4(*(UnkStruct_080038C8**)&work[8], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_04[gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_0A], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_00);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809B840.s");
#endif

void func_0809B8F0(u8* work) {
    if (work[0x31] != 0) {
        DrawSprite(64, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0,
#ifdef VERSION_EU
                   0x410,
#else
                   0,
#endif
                   10);
    }
}
void func_0809B920(u8* work, void** src) {
    u8 i;
    void** dst;
    void** q;
    void** s;
    s32 z;
    UnkStruct_080038C8* obj;

    if (src != 0) {
        s = src;

        for (i = 0; i < 6; i++) {
            dst = (void**)&work[0x18];
            q = &dst[i];
            *q = s[i];
        }

        work[0x30] = 1;
    } else {
        work[0x30] = 0;
    }

    z = 0;
    work[0x11] = z;
    *(u16*)&work[4] = z;
    obj = func_080038C8(0x3C0);
    *(UnkStruct_080038C8**)&work[8] = obj;

    if (work[0x30] == 0) {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_04);
        u = LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_00);
        func_080038E4(obj, t[gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_0A], u);
#else
        func_080038E4(obj, gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_04[gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_0A], gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].unk_00);
#endif
    } else {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].unk_04);
        u = LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].unk_00);
        func_080038E4(obj, t[gUnk_08F7CF18[*(u32*)&work[0x18]].unk_0A], u);
#else
        func_080038E4(obj, gUnk_08F7CF18[*(u32*)&work[0x18]].unk_04[gUnk_08F7CF18[*(u32*)&work[0x18]].unk_0A], gUnk_08F7CF18[*(u32*)&work[0x18]].unk_00);
#endif
    }

    *(void**)&work[0xC] = LoadObjPalette(gUnk_08F69BA4, 32);
    work[0x31] = 1;
    *(u32*)&work[0x14] = gUnk_02039DD4->unk_0C6;
}

#ifndef VERSION_EU
u8 func_0809B9F4(u8* work) {
    u8* tbl;
    s32 ofs;

    if (gUnk_02039DD4->unk_0E4 == 0 || gUnk_02039DD4->unk_0C6 != *(u32*)&work[0x14]) {
        return 0;
    }

    if ((gFrameCounter >> 5) & 1) {
        work[0x31] = 0;
    } else {
        work[0x31] = 1;
    }

    if (work[0x30] == 1 && work[0x31] != 0) {
        work[0x11]++;
        ofs = work[0x11] * 4;
        tbl = &work[0x18];

        if (*(s32*)(tbl + ofs) == -1) {
            work[0x11] = 0;
        }

        func_080038E4(*(UnkStruct_080038C8**)&work[8], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_04[gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_0A], gUnk_08F7CF18[*(s32*)(tbl + (work[0x11] << 2))].unk_00);
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_0809B9F4.s");
#endif

void func_0809BAA4(u8* work) {
    if (gUnk_02039B9C->unk_0F4 != 28 && work[0x31] != 0) {
        DrawSprite(120, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0,
                   10);
    }
}
void func_0809BAE4(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    gUnk_02039DD4->unk_0D9 = 0;
    work[0x31] = 0;
    gUnk_02039DD4->unk_0CA = 256;
}
void func_0809BB18(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    gUnk_02039DD4->unk_0D8 = 0;
    work[0x31] = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}
INCLUDE_ASM("card/func_0809BB4C.s");
u8 func_0809BE80(u8* work, void* a) {
    UnkStruct_0809C534* n;
    s32 t;
    s32 z;

    if (work[0x85] != 0) {
        if ((GetKeysPressed() & 1) && work[0x84] == 0) {
            work[0x84] = 1;
            m4aSongNumStart(106);
        }

        if ((GetKeysPressed() & 2) && work[0x84] != 1) {
            m4aSongNumStart(104);
            work[0x8B] = 16;
            work[0x8C] = 16;
            SetTaskUpdate(a, (void*)func_0809C4B0);
            n = (UnkStruct_0809C534*)ListPoolFirst(gUnk_0203A9D0);

            while (n != 0) {
                n->unk_55 |= 0xFF;
                work[0x86] = 0;
                n = (UnkStruct_0809C534*)ListPoolNext(n->unk_58);
            }

            TaskPoolUpdate(&work[0x3C]);
            TaskPoolUpdate(gUnk_0203A9D0 + 0x14);
            z = 0;
            work[0x87] = 1;
            work[0x85] = z;
            return 1;
        }
    }

    n = (UnkStruct_0809C534*)ListPoolFirst(gUnk_0203A9D0);

    if (work[0x84] == 0) {
        while (n != 0) {
            t = n->unk_53;

            if (t == 0) {
                m4aSongNumStart(101);

                if (n->unk_52 < work[0x50] - 1) {
                    n->unk_52++;
                } else {
                    n->unk_52 = t;
                }

                n->unk_53 = work[0x51];
                work[0x52] = 1;
            }

            n = (UnkStruct_0809C534*)ListPoolNext(n->unk_58);
        }
    } else {
        work[0x87] = 1;
        SetTaskUpdate(a, (void*)func_0809C2D0);
    }

    if (work[0x51] == 4 || work[0x51] == 10) {
        work[0x85] = 1;
    } else {
        work[0x85] = 0;
    }

    if (work[0x52] != 0) {
        if (work[0x51] > 4) {
            work[0x51]--;
        }

        work[0x52] = 0;
    }

    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);
    return 1;
}

u8 func_0809C078(u8* work, void* a) {
    s32 v;
    u8* p;
    u8* n;

    n = (u8*)ListPoolFirst(gUnk_0203A9D0);

    if (n != 0 && n[0x55] == 1) {
        SetTaskUpdate(a, (void*)func_0809BE80);
    }

    p = &work[0x8C];

    if (*p != 0) {
        ApproachValue(&work[0x34], 0, *p);
        ApproachValue(&work[0x38], 0x9800, *p);
    } else {
        v = *(s16*)&work[0x30] << 8;
        p = &work[0x8B];
        ApproachValue(&v, 0, *p);
        *(s16*)&work[0x30] = v >> 8;
    }

    (*p)--;
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);
    return 1;
}

void func_0809C110(u8* work) {
    if (work[0x87] == 0) {
        DrawSprite(62, 50, *(void**)&work[0x28], *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0, 0);
        DrawSprite(53, 64, *(void**)&work[0x2C], *(void**)&work[0x10], *(void**)&work[0x14], 0, 0, 0);
    }

    if (work[0x85] != 0) {
        DrawSprite(88, 70, gUnk_09EE98EC[0], *(void**)&work[0x18], *(void**)&work[0x1C], 0, 0, 0);
    }

#ifdef VERSION_EU
    DrawSprite(*(s16*)&work[0x30], 0, gUnkEu_09F72BFC[gLanguage][0], *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 0);
#else
    DrawSprite(*(s16*)&work[0x30], 0, gUnk_09EEA16C[0], *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 0);
#endif
    DrawSprite(120, *(s32*)&work[0x34] >> 8, gUnk_09EEA174[0], *(void**)&work[0x20], *(void**)&work[0x04], 0, 0, 60);
    DrawSprite(120, *(s32*)&work[0x38] >> 8, gUnk_09EEA174[1], *(void**)&work[0x20], *(void**)&work[0x04], 0, 0, 60);
    TaskPoolDraw(&work[0x3C]);
    TaskPoolDraw(gUnk_0203A9D0 + 0x14);
}

void func_0809C1EC(u8* work) {
    TaskPoolDestroy(gUnk_0203A9D0 + 0x14);
    EwramFree(*(void**)&work[0x24]);
    EwramFree(gUnk_0203A9D0);
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjTiles(*(void**)&work[0x18]);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x20]);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x04])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x14])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x0C])->unk_06 + 16, 0);
    func_080062F4((*(UnkStruct_080038C8**)&work[0x1C])->unk_06 + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x14]);
    ReleaseObjPalette(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    func_0800FDD0(0xF5);
    TaskPoolDestroy(&work[0x3C]);
}

void func_0809C294(u8* work) {
    u8 i;

    for (i = 0; i < work[0x50]; i++) {
        (*(u8**)&work[0x24])[i * 12 + 6] = i;
        TaskCreate(&work[0x3C], gUnk_09EE781C, &(*(u8**)&work[0x24])[i * 12]);
    }
}
u8 func_0809C2D0(u8* work, void* a) {
    u8* n;
    u8* pool;
    u8 z;
    u8 t;
    u8* q;

    n = (u8*)ListPoolFirst(gUnk_0203A9D0);
    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    work[0x51] = 0;
    work[0x8A]++;
    work[0x85] = 0;

    if (work[0x86] != 0) {
        while (n != 0) {
            if (n[0x53] == 0) {
                if ((s8)n[0x52] == 3) {
                    n[0x55] = 2;
                    func_08085658(*(u16*)&n[0x48]);
                } else {
                    n[0x55] = 3;
                }

                work[0x86] = 0;
            }

            n = (u8*)ListPoolNext(&n[0x58]);
        }
    }

    t = work[0x8A];
    pool = &work[0x3C];

    if (t == 30) {
        q = &work[0x87];
        z = 0;
        *q = 1;
        SetBgPriority(2, 0);
        func_080065FC(2, 0x8000, 0x80);
        func_08006778(gUnk_09EDA9A8, 120, 60);
        work[0x88] = func_08006BA0(gUnk_09EDA9A8);
        work[0x89] = z;
        gBldCnt = 0x1B44;
        gBldAlpha = 0x1010;
        func_08006954();
        func_080062F4(10, 1);
        func_080062F4(11, 1);
        func_080062F4(12, 1);
        func_080062F4(13, 1);
        func_080062F4(14, 1);
        func_080062F4(15, 1);
        TaskCreate(pool, gUnk_09EE7834, 0);
        SetTaskUpdate(a, (void*)func_0809C448);
    }

    TaskPoolUpdate(pool);
    TaskPoolUpdate(&gUnk_0203A9D0[0x14]);
    return 1;
}

u8 func_0809C448(u8* work, void* a) {
    ListPoolFirst(gUnk_0203A9D0);
    func_08006954();
    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);

    if ((GetKeysPressed() & 1)
#ifdef VERSION_EU
        && work[0x89] > 8
#endif
    ) {
        work[0x8B] = 16;
        work[0x8C] = 16;
        SetTaskUpdate(a, (void*)func_0809C4B0);
    }

#ifdef VERSION_EU
    if (work[0x89] <= 254) {
        work[0x89]++;
    }
#endif

    return 1;
}

u8 func_0809C4B0(u8* work, void* a) {
    s32 v;
    u8* p;

    p = &work[0x8B];

    if (*p != 0) {
        v = *(s16*)&work[0x30] << 8;
        ApproachValue(&v, -0x8000, *p);
        *(s16*)&work[0x30] = v >> 8;
    } else {
        p = &work[0x8C];

        if (*p == 0) {
            return 0;
        }

        ApproachValue(&work[0x34], -0x800, *p);
        ApproachValue(&work[0x38], 0xA000, *p);
    }

    (*p)--;
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(gUnk_0203A9D0 + 0x14);
    return 1;
}

void func_0809C534(UnkStruct_0809C534* w, UnkStruct_0809C534_Args* a) {
    CardDef* def;

    w->unk_54 = 0;
    w->unk_18 = 0;

    if (a->unk_06 <= 8) {
        w->unk_4E = gUnk_09036278[a->unk_06];
    } else {
        w->unk_4E = 0xFFE0;
    }

    w->unk_52 = a->unk_06;
    w->unk_48 = a->unk_04;
    def = &gCardDefs[a->unk_00];
    w->unk_00 = def;

    if (def->unk_1E & 0xC) {
        w->unk_04 = &gUnk_08F709B0[1];
    } else {
        w->unk_04 = &gUnk_08F709B0[def->unk_2A];
    }

    w->unk_50 = 0;
    func_0809C9A4((UnkStruct_0809C9A4*)w);
    func_08000D20(w->unk_58, gUnk_0203A9D0, w);
    func_08000D28(w->unk_58, gUnk_0203A9D0);
    w->unk_55 = 0;
    w->unk_6C = 0x100;
    w->unk_6E = 0x100;
    w->unk_70 = 0;
    w->unk_72 = 0;
    w->unk_53 = 32;
    w->unk_74 = 0;
}
u8 func_0809C620(u8* work, void* a) {
    s32 v;
    u8 (*fn)(u8*, void*);
    u16 lim;

    v = *(s16*)&work[0x4E] << 8;

    if (*(s8*)&work[0x52] <= 8) {
        ApproachValue(&v, gUnk_09036278[*(s8*)&work[0x52]] << 8, work[0x53]);
        *(s16*)&work[0x4E] = v >> 8;
    } else {
        lim = 0xFFE0;
        *(u16*)&work[0x4E] = lim;
    }

    if (work[0x53] != 0) {
        work[0x53]--;
    }

    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if (func_0809C9F4((UnkStruct_0809C9A4*)work)) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    if ((s8)work[0x52] == 3) {
        *(u8**)&gUnk_0203A9D0[0x10] = work;
    }

    switch (work[0x55]) {
    case 2:
        gUnk_0203A9D0[0x29] = 0;
        work[0x53] = 8;
        fn = func_0809CB0C;
        SetTaskUpdate(a, fn);
        return fn(work, a);
    case 3:
        work[0x53] = 10;
        SetTaskUpdate(a, func_0809CBF8);
        break;
    }

    return 1;
}

u8 func_0809C710(u8* work, void* a) {
    s32 v;

    v = *(s16*)&work[0x50] << 8;
    ApproachValue(&v, 0x6800, work[0x53]);
    *(s16*)&work[0x50] = v >> 8;
    work[0x53]--;
    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if ((s8)work[0x52] <= 8) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    if (work[0x53] == 0) {
        work[0x55] = 1;
        SetTaskUpdate(a, (void*)func_0809C620);
    }

    return 1;
}

void func_0809C78C(UnkStruct_0809C534* w) {
    s32 affine;

    if (w->unk_55 == 0xFF) {
        return;
    }

    if (w->unk_54 != 0) {
        affine = AllocObjAffine(0, w->unk_6C, w->unk_6E, 1);
        DrawSprite(w->unk_4A + w->unk_70, w->unk_4C + w->unk_72, w->unk_00->unk_00, w->unk_08, w->unk_24, affine, 0x400,
                   gUnk_0903628A[w->unk_52] + 70);
        DrawSprite(w->unk_4A + w->unk_70, w->unk_4C + w->unk_72, w->unk_04->unk_00, w->unk_0C, w->unk_28, affine, 0x400,
                   gUnk_0903628A[w->unk_52] + 69);

        if (w->unk_74 == 0) {
            DrawSprite(w->unk_4A + w->unk_70, w->unk_4C + w->unk_72, gUnk_09EE981C[w->unk_00->unk_20], w->unk_10, w->unk_28,
                       affine, 0x400, gUnk_0903628A[w->unk_52] + 68);
        } else {
            DrawSprite(w->unk_4A + w->unk_70, w->unk_4C + w->unk_72, gUnk_09EE9894[w->unk_00->unk_20], w->unk_1C, w->unk_20,
                       affine, 0x400, gUnk_0903628A[w->unk_52] + 68);
        }
    }

    if (w->unk_55 == 2 && w->unk_18 != 0) {
        DrawSprite(w->unk_4A + w->unk_70, w->unk_4C + w->unk_72, w->unk_44, w->unk_18, w->unk_28, 0, 0x400,
                   gUnk_0903628A[w->unk_52] + 67);
    }
}
void func_0809C98C(void** work) {
    func_0809CAC8(work);

    if (work[6] != 0) {
        ReleaseObjTiles(work[6]);
    }
}

void func_0809C9A4(UnkStruct_0809C9A4* p) {
    p->unk_4A = (gSineTable[p->unk_4E] * p->unk_50) >> 8;
    p->unk_4C = ((-gSineTable[p->unk_4E + 64] * p->unk_50) >> 8) + 160;
}

u8 func_0809C9F4(UnkStruct_0809C9A4* p) {
    if (p->unk_4A >= 0) {
        if (p->unk_4A <= 240) {
            if (p->unk_4C >= 0) {
                if (p->unk_4C <= 160) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void func_0809CA1C(u8* work) {
    if (work[0x54] == 0) {
        *(void**)&work[0x0C] = LoadObjTiles(((void**)*(void**)&work[4])[3], 0x280);
        *(void**)&work[0x28] = LoadObjPalette(gUnk_09611AB8, 32);
        *(void**)&work[0x08] = LoadObjTiles(((void**)*(void**)&work[0])[1], 0x200);
        *(void**)&work[0x24] = LoadObjPalette(((void**)*(void**)&work[0])[2], 32);
        *(void**)&work[0x10] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
        *(void**)&work[0x1C] = LoadObjTiles(gUnk_0905ED36, 0x140);
        *(void**)&work[0x20] = LoadObjPalette(gUnk_08F69BA4, 32);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x20])->unk_06 + 16, 1);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x28])->unk_06 + 16, 1);
        func_080062F4((*(UnkStruct_080038C8**)&work[0x24])->unk_06 + 16, 1);
        work[0x54] = 1;
    }
}

void func_0809CAC8(void* p) {
    u8* work;

    work = (u8*)p;

    if (work[0x54] != 0) {
        ReleaseObjTiles(*(void**)&work[0x0C]);
        ReleaseObjPalette(*(void**)&work[0x28]);
        ReleaseObjTiles(*(void**)&work[0x08]);
        ReleaseObjPalette(*(void**)&work[0x24]);
        ReleaseObjTiles(*(void**)&work[0x10]);
        ReleaseObjPalette(*(void**)&work[0x20]);
        ReleaseObjTiles(*(void**)&work[0x1C]);
        work[0x54] = 0;
    }
}

u8 func_0809CB0C(u8* work, void* a) {
    s32 x;
    s32 y;

    x = *(s16*)&work[0x4A] << 8;
    y = *(s16*)&work[0x4C] << 8;
    ApproachValue(&x, 0x7800, work[0x53]);
    ApproachValue(&y, 0x4600, work[0x53]);
    *(s16*)&work[0x4A] = x >> 8;
    *(s16*)&work[0x4C] = y >> 8;
    work[0x53]--;

    if (work[0x53] == 0) {
        SetTaskUpdate(a, (void*)func_0809CB78);
    }

    return 1;
}

u8 func_0809CB78(u8* work, void* a) {
    *(void**)&work[0x18] = AllocObjTiles(640, 0);
    func_08002A10(*(void**)&work[0x18], gUnk_0908B1B4);
    AnimInit(&work[0x2C], gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&work[0x2C], 0, 1);
    *(void**)&work[0x44] = AnimGetGfx(&work[0x2C]);
    SetTaskUpdate(a, (void*)func_0809CBD0);
    return 1;
}

s32 func_0809CBD0(u8* work) {
    *(void**)&work[0x44] = AnimUpdate(&work[0x2C]);

    if (*(u16*)&work[0x36] == 0 && *(u16*)&work[0x3A] == 4) {
        work[0x74] = 1;
    }

    return 1;
}

u8 func_0809CBF8(u8* work, void* a) {
    s32 v;

    v = *(s16*)&work[0x4E] << 8;

    if ((s8)work[0x52] <= 2) {
        ApproachValue(&v, -0x2000, work[0x53]);
    }

    if (work[0x52] >= 4 && work[0x52] <= 7) {
        ApproachValue(&v, 0x4400, work[0x53]);
    }

    *(s16*)&work[0x4E] = v >> 8;

    if (work[0x53] != 0) {
        work[0x53]--;
    }

    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if (func_0809C9F4((UnkStruct_0809C9A4*)work)) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    return 1;
}

#ifdef VERSION_US
void CardName_0(UnkStruct_0809CC80* w) {
    u8* q = *(u8**)&gUnk_0203A9D0[0x10];
    UnkStruct_080038C8* pal;
    s32 v;
    s16 t;

    func_08065ACC(w->unk_08, 32);
    func_08065ACC(w->unk_108, 32);
    func_08065ACC(w->unk_208, 2);
    w->unk_218 = _08066468(1);
    w->unk_226 = func_08065B6C(*(u16**)(*(u8**)q + 12), w->unk_08);
    w->unk_227 = func_08065B6C((u16*)&gUnk_09036278[22], w->unk_108);
    w->unk_21C = LoadObjPalette(gUnk_09614798, 32);
    v = (230 - func_08065B08(w->unk_08, w->unk_226)) / 2;
    w->unk_220 = v;
    t = (u16)w->unk_220 + func_08065B08(w->unk_08, w->unk_226);
    w->unk_224 = t;
    v = (240 - func_08065B08(w->unk_108, w->unk_227)) / 2;
    w->unk_222 = v;
    w->unk_00 = LoadObjTiles(&gUnk_093F8C8E[0xC1E], 0x1800);
    pal = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_04 = pal;
    func_080062F4(pal->unk_06 + 16, 1);
    func_080062F4(((UnkStruct_080038C8*)w->unk_218)->unk_06 + 16, 1);
}
#else
INCLUDE_ASM("card/CardName_0.s");
#endif
s32 CardName_1(void) {
    return 1;
}
#ifdef VERSION_US
void CardName_2(u8* work) {
    void** p = &gUnk_09EF1278[2];

    DrawSprite(120, 126, *p, *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    func_080664D8(*(s16*)&work[0x220], 115, &work[0x08], *(void**)&work[0x21C], 30, work[0x226]);
    func_080664D8(*(s16*)&work[0x222], 130, &work[0x108], *(void**)&work[0x218], 30, work[0x227]);
}
#else
INCLUDE_ASM("card/CardName_2.s");
#endif
#ifndef VERSION_JP
void CardName_3(u8* work) {
    func_08065AE0((TextSlot*)&work[0x08], 32);
    func_08065AE0((TextSlot*)&work[0x108], 32);
#ifdef VERSION_EU
    func_08065AE0((TextSlot*)&work[0x208], 32);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x308]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjPalette(*(void**)&work[0x30C]);
#else
    func_08065AE0((TextSlot*)&work[0x208], 2);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x218]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjPalette(*(void**)&work[0x21C]);
#endif
}
#else
INCLUDE_ASM("card/CardName_3.s");
#endif

void func_0809CE88(UnkStruct_0809CE88* w, s16* a) {
    w->unk_00 = AllocObjTiles(128, 0);
    w->unk_04 = LoadObjPalette(gUnk_09619158, 32);
    func_08002A10(w->unk_00, gUnk_093F762E);
    AnimInit(&w->unk_0C, gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&w->unk_0C, GetRandom() % 3, 1);
    w->unk_08 = AnimGetGfx(&w->unk_0C);
    w->unk_24 = a[1] << 8;
    w->unk_28 = a[2] << 8;
    w->unk_2C = 0;
    w->unk_40 = a[0] << 8;
    w->unk_3C = a[3];
    w->unk_4C = GetRandom() % 0x181 + 0x100;
    w->unk_30 = 0;
    w->unk_34 = 0;
    w->unk_38 = 0;
    w->unk_50 = -(GetRandom() % 0x81 + 0x200);
    gUnk_0203A9D0[0x28]++;
}

void func_0809CF64(UnkStruct_0809CE88* w, s16* a) {
    w->unk_00 = AllocObjTiles(128, 0);
    w->unk_04 = LoadObjPalette(gUnk_09619158, 32);
    func_08002A10(w->unk_00, gUnk_093F762E);
    AnimInit(&w->unk_0C, gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&w->unk_0C, GetRandom() % 3, 1);
    w->unk_08 = AnimGetGfx(&w->unk_0C);
    w->unk_24 = a[1] << 8;
    w->unk_28 = a[2] << 8;
    w->unk_2C = 0;
    w->unk_40 = a[0] << 8;
    w->unk_3C = a[3];
    w->unk_4C = GetRandom() % 0x81 + 0x200;
    w->unk_30 = 0;
    w->unk_34 = 0;
    w->unk_38 = 0;
    w->unk_50 = -(GetRandom() % 0x81 + 0x200);
    func_0809D124(w);
    gUnk_0203A9D0[0x28]++;
}

s32 func_0809D040(UnkStruct_0809CE88* w) {
    func_0809D124(w);
    w->unk_3C += 8;

    if (w->unk_40 > 0) {
        w->unk_40 += -0x180;
        w->unk_08 = AnimUpdate(&w->unk_0C);
        return 1;
    }

    return 0;
}
s32 Premire_EFFECT2_1(UnkStruct_0809CE88* w) {
    func_0809D160(w);
    w->unk_08 = AnimUpdate(&w->unk_0C);

    if (w->unk_34 > 0xB400) {
        return 0;
    }

    return 1;
}
s32 func_0809D09C(UnkStruct_0809CE88* w) {
    func_0809D1B0(w);
    w->unk_3C += 8;
    w->unk_08 = AnimUpdate(&w->unk_0C);

    if (w->unk_40 <= 0x800) {
        return 0;
    }

    return 1;
}
void func_0809D0CC(UnkStruct_0809CE88* w) {
    DrawSprite(w->unk_30 >> 8, w->unk_34 >> 8, w->unk_08, w->unk_00, w->unk_04, 0, 0, 0);
}
void func_0809D0FC(UnkStruct_0809CE88* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
    gUnk_0203A9D0[0x28]--;
}

void func_0809D124(UnkStruct_0809CE88* w) {
    w->unk_30 = gSineTable[w->unk_3C & 0xFF] * (w->unk_40 >> 8) + w->unk_24;
    w->unk_34 = -gSineTable[(w->unk_3C & 0xFF) + 64] * (w->unk_40 >> 8) + w->unk_28;
}

void func_0809D160(UnkStruct_0809CE88* w) {
    w->unk_50 += 30;
    w->unk_2C += w->unk_50;
    w->unk_24 += gSineTable[w->unk_3C & 0xFF] * (w->unk_4C >> 8);
    w->unk_28 += -gSineTable[(w->unk_3C & 0xFF) + 64] * (w->unk_4C >> 8);
    w->unk_30 = w->unk_24;
    w->unk_34 = w->unk_28 + w->unk_2C;
}

void func_0809D1B0(UnkStruct_0809CE88* w) {
    s32 v;
    s32 d;

    w->unk_44 = w->unk_24 - w->unk_30;
    w->unk_48 = w->unk_28 - w->unk_34;
    w->unk_40 = func_0805F5A4(&w->unk_44, &w->unk_48);
    v = w->unk_4C;
    d = v >> 8;
    w->unk_30 += w->unk_44 * d;
    w->unk_34 += w->unk_48 * d;

    if (w->unk_40 > 0) {
        w->unk_4C = v - 2;
    }
}

void func_0809D1FC(u8 bg) {
    void** p;

    SetBgScroll(bg, 0, 0);
    SetBackdropColor(0, 0, 0);
    LoadBgTiles(bg, gUnk_09036380, 0x1C00);
    LoadBgMap(bg, gUnk_08125E24, 0x800);
    LoadBgPalette(bg, gUnk_09036300, 0x80);
    EnableBg(bg);
    gUnk_02034AD9 = bg;
    p = &gUnk_02034AD4;
    *p = EwramAlloc(0x880);
}

void func_0809D26C(void) {
    EwramFree(gUnk_02034AD4);
}

u8 func_0809D280(u8* p) {
    u8 n;

    n = 0;

    if (p == 0) {
        return 0;
    }

    while (*p++ != 0) {
        if (*p != 0) {
            n++;
        }
    }

    return n + 1;
}

void func_0809D2B0(u8 a, u8 b, u8 c, u8* s) {
    u8 n;
    u8 i;

    if (gUnk_02034AD8 < 32) {
        n = func_0809D280(s);

        if (n > 32) {
            n = 32;
        }

        for (i = 0; i < n; i++) {
            ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04[i] = s[i];
            ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04[i] |= c << 12;
        }

        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_01 = a;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_02 = b;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_03 = c;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_00 = n;
        func_0800448C(((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04, (void*)GetBgScreenBase(gUnk_02034AD9), 0, 0,
                      ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_01,
                      ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_02,
                      (s8)((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_00, 1);
        gUnk_02034AD8++;
    }
}

void func_0809D3F0(void) {
    gUnk_02034AD8 = 0;
}

void func_0809D3FC(void) {
    s16 i;

    for (i = 0; i < gUnk_02034AD8; i++) {
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_00 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_01 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_02 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_03 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_04[0] = 0;
    }

    gUnk_02034AD8 = 0;
}

INCLUDE_ASM("card/func_0809D458.s");

void func_0809D87C(u16 a, u16 b, u16 c, u16 bits) {
    u16 v[16];
    u8 s[17];
    u16 i;
    u16 j;

    for (i = 0, j = 15; i < 16; i++, j--) {
        v[i] = bits & (1 << i);
        s[j] = (v[i] >> i) + '0';
    }

    s[16] = 0;
    func_0809D2B0(a, b, c, s);
}

void func_0809D900(u16 a, u16 b, u16 c, u32 v) {
    u8 s[11];
    s32 i;

    s[0] = '0';
    s[1] = 'x';
    s[2] = v >> 28;
    s[3] = (v & 0x0F000000) >> 24;
    s[4] = (v & 0x00F00000) >> 20;
    s[5] = (v & 0x000F0000) >> 16;
    s[6] = (v & 0x0000F000) >> 12;
    s[7] = (v & 0x00000F00) >> 8;
    s[8] = (v & 0x000000F0) >> 4;
    s[9] = v & 0x0000000F;

    for (i = 0; i < 8; i++) {
        s[i + 2] += s[i + 2] <= 9 ? '0' : '7';
    }

    s[10] = 0;
    func_0809D2B0(a, b, c, s);
}

void Mode_Premire_0(void) {
    func_08085FB0();
    func_08085C3C();
    SetBgMode2();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
#ifdef VERSION_EU
    LoadBgTiles(3, gUnkEu_08CB0D3C, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    eu_080059F4(3, gUnkEu_08F7ADFC);
#else
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
#endif
    SetBgAffine(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AE0, 1);
#ifdef VERSION_EU
    TaskCreate(gUnk_02034AE0, gUnkEu_09F72D80, 0);
#else
    TaskCreate(gUnk_02034AE0, gTaskDescLevelUp, 0);
#endif
}

void Mode_Premire_1(void) {
    TaskPoolUpdate(gUnk_02034AE0);
    TaskPoolDraw(gUnk_02034AE0);
}
void Mode_Premire_2(void) {
    TaskPoolDestroy(gUnk_02034AE0);
}
u8 func_0809DA64(s32 a, u16 n) {
    switch (n) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 30:
    case 31:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 42:
    case 51:
    case 53:
        return 6;
    case 41:
    case 45:
    case 50:
        return 2;
    case 18:
    case 46:
        return 3;
    case 15:
    case 28:
    case 47:
        return 5;
    case 23:
    case 26:
    case 27:
        return 4;
    case 48:
        return 1;
    }

    return 0;
}
#ifndef VERSION_EU
void HCEffectName_0(UnkStruct_0809DF7C* w, u8* a) {
    void** tiles;

    w->unk_19 = a[0];
    w->unk_1A = 0;
    w->unk_1C = 32;
    w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_08 = func_080038C8(0x3C0);
    w->unk_0C = func_080038C8(32);
    w->unk_20 = 0;
    w->unk_27 = 1;

    switch (w->unk_19) {
    case 1:
        w->unk_00 = 48;
        w->unk_1E = gUnk_02039DD4->unk_0CC;
        tiles = gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_08;
        func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_0C], gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_00);
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
        func_080038E4(w->unk_0C, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);

        if (gUnk_02039DD4->unk_0CC == 0) {
            w->unk_27 = 0;
        }
        break;
    case 2:
        w->unk_00 = 162;
        w->unk_1E = gUnk_02039DD4->unk_0CE;
        tiles = gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_08;
        func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_0C], gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_00);
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
        func_080038E4(w->unk_0C, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);

        if (gUnk_02039DD4->unk_0CE == 0) {
            w->unk_27 = 0;
        }
        break;
    }

    w->tiles = LoadObjTiles(gUnk_08B25ADE, 0x360);
    w->unk_22 = 0;
    w->unk_23 = 0;
    w->unk_24 = 0;
    w->unk_25 = 0;
}
#else
INCLUDE_ASM("card/HCEffectName_0.s");
#endif
#ifndef VERSION_EU
u8 HCEffectName_1(UnkStruct_0809DF7C* w, void* a) {
    u8 done;
    s32 div;
    UnkStruct_02039DD4* d;

    done = func_0809DE18((u8*)w);

    if (done != 0) {
        SetTaskUpdate(a, (void*)func_0809DE30);
        return 1;
    }

    switch (w->unk_19) {
    case 1:
        div = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E << 8;
        w->unk_1C = (u32)(((s16)gBtlWork->unk_0F8 << 16) / div) >> 3;
        d = gUnk_02039DD4;

        if (d->unk_0CC == 0) {
            d->unk_0EB = 0;
            return 0;
        }

        if (d->unk_0CC != w->unk_1E) {
            d->unk_0EB = 0;
            return 0;
        }

        if (d->unk_0EB == 1) {
            d->unk_0EB = 0;
            return 0;
        }

        if ((s16)gBtlWork->unk_0F8 <= 0) {
            d->unk_0CC = 0;
            gBtlWork->unk_0F4 = 0;
            d->unk_0EB = 0;
            return 0;
        }

        func_0806BA0C((s16)gBtlWork->unk_0F8, &w->unk_22);
        break;
    case 2:
        div = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E << 8;
        w->unk_1C = (u32)(((s16)gUnk_02039B9C->unk_0F8 << 16) / div) >> 3;
        d = gUnk_02039DD4;

        if (d->unk_0CE == 0) {
            d->unk_0EC = 0;
            return 0;
        }

        if (d->unk_0CE != w->unk_1E) {
            d->unk_0EC = 0;
            return 0;
        }

        if (d->unk_0EC == 1) {
            d->unk_0EC = 0;
            return 0;
        }

        if ((s16)gUnk_02039B9C->unk_0F8 <= 0) {
            d->unk_0CE = 0;
            gUnk_02039B9C->unk_0F4 = 0;
            d->unk_0EC = 0;
            return 0;
        }

        func_0806BA0C((s16)gUnk_02039B9C->unk_0F8, &w->unk_22);
        break;
    }

    w->unk_1A++;

    if ((s16)w->unk_1C <= 2) {
        w->unk_1C = 2;
    }

    if ((s16)w->unk_1A >= (s16)w->unk_1C) {
        w->unk_27 ^= 1;
        w->unk_1A = 0;
    }

    return 1;
}
#else
INCLUDE_ASM("card/HCEffectName_1.s");
#endif
u8 func_0809DE18(u8* p) {
    if (p[25] != 1) {
        if (p[25] != 2) {
            return 0;
        }
    }

    if (*(u16*)&p[30] != 37) {
        return 0;
    }

    return 1;
}
#ifdef NON_MATCHING
u8 func_0809DE30(UnkStruct_0809DF7C* w, void* a) {
    u16 id;
    void** tiles;

    switch (w->unk_19) {
    case 1:
        if (gUnk_02039DD4->unk_0CC != 37) {
            w->unk_1E = gUnk_02039DD4->unk_0CC;
            if (gUnk_02039DD4->unk_0CC == 0) {
                gUnk_02039DD4->unk_0EB = 0;
                return 0;
            }
#ifdef VERSION_EU
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
#endif
            tiles = LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_08);
            func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_00));
#ifdef VERSION_EU
            func_080038E4(w->unk_0C, gUnkEu_09F72CC4[gLanguage][w->unk_26],
                         gUnkEu_09F72CB0[gLanguage]);
#else
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
            func_080038E4(w->unk_0C, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);
#endif
            SetTaskUpdate(a, (void*)HCEffectName_1);
        } else {
            id = func_080792D0(&w->unk_20);
            w->unk_1E = id;
            tiles = LANGSTR(gUnk_08F7CBA8[id].unk_08);
            func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[id].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[id].unk_00));
        }
        break;
    case 2:
        if (gUnk_02039DD4->unk_0CE != 37) {
            w->unk_1E = gUnk_02039DD4->unk_0CE;
            if (gUnk_02039DD4->unk_0CE == 0) {
                gUnk_02039DD4->unk_0EB = 0;
                return 0;
            }
#ifdef VERSION_EU
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
#endif
            tiles = LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_08);
            func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_00));
#ifdef VERSION_EU
            func_080038E4(w->unk_0C, gUnkEu_09F72CC4[gLanguage][w->unk_26],
                         gUnkEu_09F72CB0[gLanguage]);
#else
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
            func_080038E4(w->unk_0C, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);
#endif
            SetTaskUpdate(a, (void*)HCEffectName_1);
        } else {
            id = func_080792D0(&w->unk_20);
            w->unk_1E = id;
            tiles = LANGSTR(gUnk_08F7CBA8[id].unk_08);
            func_080038E4(w->unk_08, tiles[gUnk_08F7CBA8[id].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[id].unk_00));
        }
        break;
    }
    return 1;
}

#else
INCLUDE_ASM("card/func_0809DE30.s");
#endif

void HCEffectName_2(UnkStruct_0809DF7C* w) {
#ifdef VERSION_EU
    s32 pri;

    if (w->unk_27 == 1) {
        pri = 0x410;
        DrawSprite(w->unk_00, 0x90, 0, w->unk_08, w->palette, 0, pri, 10);
        DrawSprite(w->unk_00, 0x8A, gUnk_09EE1538[15], w->tiles, w->palette, 0, pri, 10);
        DrawSprite(w->unk_00 + 8, 0x8A, gUnk_09EE1538[w->unk_24 + 4], w->tiles, w->palette, 0, pri, 10);
        DrawSprite(w->unk_00 + 16, 0x8A, gUnk_09EE1538[w->unk_25 + 4], w->tiles, w->palette, 0, pri, 10);
        DrawSprite(w->unk_00 + 24, 0x8A, 0, w->unk_0C, w->palette, 0, pri, 10);
        DrawSprite(w->unk_00 + 32, 0x8A, gUnk_09EE1538[14], w->tiles, w->palette, 0, pri, 10);
    }
#else
    if (w->unk_27 == 1) {
        DrawSprite(w->unk_00, 0x90, 0, w->unk_08, w->palette, 0, 0x400, 10);
        DrawSprite(w->unk_00, 0x8A, gUnk_09EE1538[15], w->tiles, w->palette, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 8, 0x8A, gUnk_09EE1538[w->unk_24 + 4], w->tiles, w->palette, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 16, 0x8A, gUnk_09EE1538[w->unk_25 + 4], w->tiles, w->palette, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 24, 0x8A, 0, w->unk_0C, w->palette, 0, 0x400, 10);
        DrawSprite(w->unk_00 + 32, 0x8A, gUnk_09EE1538[14], w->tiles, w->palette, 0, 0x400, 10);
    }
#endif
}

void HCEffectName_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjTiles(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x10]);
    gUnk_02039DD4->unk_0D8 = 0;
    gUnk_02039DD4->unk_0E5 = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}

void NumberPlus_0(UnkWork_0809E0A4* w, UnkStruct_0809E0A4* args) {
    w->unk_08 = *args;
    w->tiles = LoadObjTiles(gUnk_090451C0, 128);
    w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_24 = w->unk_08.unk_04 >> 8;
    w->unk_26 = (w->unk_08.unk_08 >> 8) - 20;
    w->unk_28 = 16;
    w->unk_29 = 0;
}

s32 NumberPlus_1(u8* work) {
    s32 v;

    v = *(s16*)&work[0x26] << 8;

    if (work[0x28] != 0) {
        ApproachValue(&v, *(s32*)&work[0x10] - 0x2800, work[0x28]);
        *(s16*)&work[0x26] = v >> 8;
        work[0x28]--;
        return 1;
    }

    return 0;
}
void NumberPlus_2(u8* work) {
    DrawSprite(*(s16*)&work[0x24], *(s16*)&work[0x26], gUnk_09EE91A8[0],
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 16, 0);
}
void NumberPlus_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}
INCLUDE_ASM("card/Level_Up_0.s");

#ifndef VERSION_EU
void func_0809E7A4(void) {
    u32 base;

    if (*(u32*)&gBtlWork->unk_100[0x0C] == 151) {
        base = GetBgCharBase(0);
        RequestDma3Copy(gUnk_093FEEB8, (void*)(base + 0x2480), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x400], (void*)(base + 0x25A0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x800], (void*)(base + 0x26C0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[288], (void*)(base + 0x27E0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x520], (void*)(base + 0x2900), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x920], (void*)(base + 0x2A20), 288);
        RequestDma3Copy(gUnk_093FD438, (void*)(base + 0x2C00), 0xA80);
    } else {
        base = GetBgCharBase(1);
        RequestDma3Copy(gUnk_093FEEB8, (void*)(base + 0x2480), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x400], (void*)(base + 0x25A0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x800], (void*)(base + 0x26C0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[288], (void*)(base + 0x27E0), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x520], (void*)(base + 0x2900), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x920], (void*)(base + 0x2A20), 288);
        RequestDma3Copy(gUnk_093FD438, (void*)(base + 0x2C00), 0xA80);
    }
}
#else
INCLUDE_ASM("card/func_0809E7A4.s");
#endif
INCLUDE_ASM("card/Level_Up_1.s");
#ifdef NON_MATCHING
u8 func_0809F390(u8* work, void* a) {
    s32 x;
    s8 i;
    u8* q;

    if (GetKeysRepeat() & 0x80) {
        i = work[0x7B0];
        q = &work[0x7C8];

        do {
            i++;

            if (i > 2) {
                i = 0;
            }
        } while (q[i] == 0);

        if (i != (s8)work[0x7B0]) {
            m4aSongNumStart(101);
        }

        work[0x7B0] = i;

        if (*(s32*)&gBtlWork->unk_100[0xC] == 151) {
            LoadBgMap(0, ((void**)&gTaskDescHCEffectName[0x70])[(s8)work[0x7B0]], 0x800);
        } else {
            LoadBgMap(1, ((void**)&gTaskDescHCEffectName[0x70])[(s8)work[0x7B0]], 0x800);
        }

        work[0x7B6] = 8;
    }

    if (GetKeysRepeat() & 0x40) {
        i = work[0x7B0];
        q = &work[0x7C8];

        do {
            i--;

            if (i < 0) {
                i = 2;
            }
        } while (q[i] == 0);

        if (i != (s8)work[0x7B0]) {
            m4aSongNumStart(101);
        }

        work[0x7B0] = i;

        if (*(s32*)&gBtlWork->unk_100[0xC] == 151) {
            LoadBgMap(0, ((void**)&gTaskDescHCEffectName[0x70])[(s8)work[0x7B0]], 0x800);
        } else {
            LoadBgMap(1, ((void**)&gTaskDescHCEffectName[0x70])[(s8)work[0x7B0]], 0x800);
        }

        work[0x7B6] = 8;
    }

    if (GetKeysRepeat() & 1) {
        work[0x7BD] = 2;

        if (*(s32*)&gBtlWork->unk_100[0xC] == 151) {
            LoadBgMap(0, &gUnk_0950E2F8[0x7C0], 0x800);
        } else {
            LoadBgMap(1, &gUnk_0950E2F8[0x7C0], 0x800);
        }

        work[0x7B2] = 16;
        work[0x7B3] = 16;
        work[0x7B4] = 16;
        m4aSongNumStart(102);
        ReleaseObjTiles(*(void**)&work[0x6E8]);
        ReleaseObjPalette(*(void**)&work[0x6EC]);
        *(void**)&work[0x6E8] = AllocObjTiles(128, 0);
        *(void**)&work[0x6EC] = LoadObjPalette(&gUnk_09611AB8[0x24A0], 32);
        func_080062F4(*(u16*)((u8*)*(void**)&work[0x6EC] + 6) + 16, 1);
        func_08002A10(*(void**)&work[0x6E8], &gUnk_0908C686[0x2B0A]);
        AnimInit((AnimState*)&work[0x710], &gUnk_09EEA19C[0x39], &gUnk_09EEA19C[0x34]);
        AnimStart((AnimState*)&work[0x710], 0, 1);
        *(void**)&work[0x74C] = AnimGetGfx((AnimState*)&work[0x710]);
        work[0x7B6] = 16;
        *(u16*)&work[0x774] = 136;

        if (gGameState.flags & 8) {
            func_08002A10(*(void**)&work[0x728], gUnk_092EB78A);
            AnimInit((AnimState*)&work[0x734], &gUnk_09EEF89C[0x24], gUnk_09EEF89C);
            AnimStart((AnimState*)&work[0x734], 1, 0);
        } else {
            func_08002A10(*(void**)&work[0x728], gUnk_088B6560);
            AnimInit((AnimState*)&work[0x734], &gUnk_09EDE8CC[0x4C], gUnk_09EDE8CC);
            AnimStart((AnimState*)&work[0x734], 1, 0);
        }

        SetTaskUpdate(a, (void*)func_0809F730);
        return 1;
    }

    x = *(s16*)&work[0x776] << 8;
    ApproachValue(&x, ((s16*)&gUnk_09036380[0x1C34])[(s8)work[0x7B0]] << 8, (s8)work[0x7B6]);
    work[0x7B6]--;
    *(s16*)&work[0x776] = x >> 8;
    *(void**)&work[0x74C] = AnimUpdate((AnimState*)&work[0x710]);
    work[0x7BE]++;

    if (work[0x7BE] == 32) {
        work[0x7BE] = 0;
        work[0x7C1] ^= 1;
    }

    *(void**)&work[0x730] = AnimUpdate((AnimState*)&work[0x734]);
    TaskPoolUpdate((TaskPool*)&work[0x6FC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0809F390.s");
#endif
INCLUDE_ASM("card/func_0809F730.s");
#ifdef NON_MATCHING
u8 func_0809FBCC(u8* work, void* a) {
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v0;
    u8 t;
    s8 n;
    u8* q;
    s32 ofs;
    u8* q1;
    u8* q2;

    ofs = (s8)work[0x7B0] * 2;
    q1 = &work[0x750];
    v1 = *(s16*)(q1 + ofs) << 8;
    ofs = (s8)work[0x7B0] * 2;
    q2 = &work[0x75C];
    v2 = *(s16*)(q2 + ofs) << 8;
    v3 = *(s16*)&work[0x77A] << 8;
    v4 = *(s16*)&work[0x77C] << 8;
    v0 = *(s16*)&work[0x778] << 8;
    ApproachValue(&v0, -0x8000, (s8)work[0x7B1]);
    q = &work[0x7B2];
    ApproachValue(&v1, -0x8000, (s8)*((s8)work[0x7B0] + q));
    ApproachValue(&v2, -0xF800, (s8)*((s8)work[0x7B0] + q));
    ofs = (s8)work[0x7B0] * 2;
    *(s16*)(q1 + ofs) = v1 >> 8;
    ofs = (s8)work[0x7B0] * 2;
    *(s16*)(q2 + ofs) = v2 >> 8;
    *(s16*)&work[0x778] = v0 >> 8;
    work[0x7B1]--;
    ofs = (s8)work[0x7B0];
    q += ofs;
    (*q)--;
    ApproachValue(&v3, 0, (s8)work[0x7B5]);
    ApproachValue(&v4, 0x10000, (s8)work[0x7B5]);
    ApproachValue(&work[0x7A8], 0x1BE00, (s8)work[0x7B5]);
    ApproachValue(&work[0x7AC], 0x4800, (s8)work[0x7B5]);

    if (*(u32*)&gBtlWork->unk_100[0x0C] == 151) {
        func_08005244(0, v3 >> 8, 0);
    } else {
        func_08005244(1, v3 >> 8, 0);
    }

    ((UnkStruct_0809FBCC*)work)->unk_77A = v3 >> 8;
    ((UnkStruct_0809FBCC*)work)->unk_77C = v4 >> 8;
    t = work[0x7B5];

    if ((s8)t > 0) {
        work[0x7B5] = t - 1;
    }

    n = work[0x7B5];

    if (n == 0) {
        if (work[0x7BF] != 0) {
            ApproachValue(&work[0x76C], -0x800, work[0x7BF]);
            ApproachValue(&work[0x770], 0xA000, work[0x7BF]);
            work[0x7BF]--;
        } else {
            SetTaskUpdate(a, (void*)func_0809FE14);
        }
    }

    *(void**)&work[0x730] = AnimUpdate(&work[0x734]);
    TaskPoolUpdate(&work[0x6FC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_0809FBCC.s");
#endif
u8 func_0809FE14(void) {
    if (func_08006314() == 0) {
        return 0;
    }
    return 1;
}
INCLUDE_ASM("card/Level_Up_2.s");
#ifndef VERSION_EU
void Level_Up_3(u8* work) {
    func_08065AE0(&work[0x20], 36);
    func_08065AE0(&work[0x140], 36);
    func_08065AE0(&work[0x260], 36);
    func_08065AE0(&work[0x380], 36);
    func_08065AE0(&work[0x4A0], 36);
    func_08065AE0(&work[0x5C0], 36);

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x1C]);
    }

    if (*(void**)&work[0x00] != 0) {
        ReleaseObjTiles(*(void**)&work[0x00]);
    }

    if (*(void**)&work[0x04] != 0) {
        ReleaseObjTiles(*(void**)&work[0x04]);
    }

    if (*(void**)&work[0x08] != 0) {
        ReleaseObjTiles(*(void**)&work[0x08]);
    }

    if (*(void**)&work[0x10] != 0) {
        ReleaseObjPalette(*(void**)&work[0x10]);
    }

    if (*(void**)&work[0x14] != 0) {
        ReleaseObjPalette(*(void**)&work[0x14]);
    }

    if (*(void**)&work[0x6E0] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6E0]);
    }

    if (*(void**)&work[0x6E4] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6E4]);
    }

    if (*(void**)&work[0x6E8] != 0) {
        ReleaseObjTiles(*(void**)&work[0x6E8]);
    }

    if (*(void**)&work[0x6EC] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6EC]);
    }

    if (*(void**)&work[0x6F0] != 0) {
        ReleaseObjTiles(*(void**)&work[0x6F0]);
    }

    if (*(void**)&work[0x6F4] != 0) {
        ReleaseObjTiles(*(void**)&work[0x6F4]);
    }

    if (*(void**)&work[0x6F8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x6F8]);
    }

    if (*(void**)&work[0x728] != 0) {
        ReleaseObjTiles(*(void**)&work[0x728]);
    }

    if (*(void**)&work[0x72C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x72C]);
    }

    TaskPoolDestroy(&work[0x6FC]);
}
#else
INCLUDE_ASM("card/Level_Up_3.s");
#endif
void func_080A0734(s16 x, s16 y, void* tiles, void* pal, void** gfx, u16* digits, u8 kind) {
    switch (kind) {
    case 0:
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    case 1:
        DrawSprite(x, y, gfx[digits[0]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    case 2:
        DrawSprite(x, y, gfx[digits[0]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 16, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        x += 24;
        DrawSprite(x, y, gfx[digits[3]], tiles, pal, 0, 0, 0);
        break;
    case 4:
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    case 3:
        DrawSprite(x, y, gfx[digits[0]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    }
}

void func_080A0944(u16 a, u16* p) {
    u16 q;
    u16 r;

    q = a / 10;
    r = a - q * 10;
    p[1] = q;
    p[2] = r;
}

void func_080A096C(u16 a, u16* p) {
    u16 h;
    u16 t;
    u16 o;

    h = a / 100;
    t = a / 10 - h * 10;
    o = a - h * 100 - t * 10;
    p[0] = h;
    p[1] = t;
    p[2] = o;
}

void func_080A09C0(u16 n, u16* out) {
    u16 d3;
    u16 d2;
    u16 d1;
    u16 d0;

    d3 = n / 1000;
    d2 = n / 100 - d3 * 10;
    d1 = n / 10 - d2 * 10 - d3 * 100;
    d0 = n - d3 * 1000 - d2 * 100 - d1 * 10;
    out[0] = d3;
    out[1] = d2;
    out[2] = d1;
    out[3] = d0;
}

INCLUDE_ASM("card/func_080A0A44.s");
#ifdef NON_MATCHING
u8 func_080A11CC(u8* work, void* a) {
    s32 x;
    s32 y;
    s16* px;
    s16* py;
    u8* pn;
    px = (s16*)&work[0x750];
    py = (s16*)&work[0x75C];
    pn = &work[0x7B2];
    x = px[(s8)work[0x7B0]] << 8;
    y = py[(s8)work[0x7B0]] << 8;
    ApproachValue(&x, -0x8000, (s8)pn[(s8)work[0x7B0]]);
    ApproachValue(&y, -0xF800, (s8)pn[(s8)work[0x7B0]]);
    px[(s8)work[0x7B0]] = x >> 8;
    py[(s8)work[0x7B0]] = y >> 8;
    pn[(s8)work[0x7B0]]--;

    if ((s8)work[0x7B5] > 0) {
        work[0x7B5]--;
    }

    if ((s8)work[0x7B5] == 0) {
        if (work[0x7BF] != 0) {
            ApproachValue((s32*)&work[0x76C], 0, work[0x7BF]);
            ApproachValue((s32*)&work[0x770], 0x9800, work[0x7BF]);
            work[0x7BF]--;
        } else {
            if (*(void**)&work[0x00] != 0) {
                ReleaseObjTiles(*(void**)&work[0x00]);
            }

            if (*(void**)&work[0x04] != 0) {
                ReleaseObjTiles(*(void**)&work[0x04]);
            }

            if (*(void**)&work[0x08] != 0) {
                ReleaseObjTiles(*(void**)&work[0x08]);
            }

            if (*(void**)&work[0x10] != 0) {
                ReleaseObjPalette(*(void**)&work[0x10]);
            }

            if (*(void**)&work[0x14] != 0) {
                ReleaseObjPalette(*(void**)&work[0x14]);
            }

            if (*(void**)&work[0x6E0] != 0) {
                ReleaseObjPalette(*(void**)&work[0x6E0]);
            }

            if (*(void**)&work[0x6E4] != 0) {
                ReleaseObjPalette(*(void**)&work[0x6E4]);
            }

            if (*(void**)&work[0x6E8] != 0) {
                ReleaseObjTiles(*(void**)&work[0x6E8]);
            }

            if (*(void**)&work[0x6EC] != 0) {
                ReleaseObjPalette(*(void**)&work[0x6EC]);
            }

            if (*(void**)&work[0x6F4] != 0) {
                ReleaseObjTiles(*(void**)&work[0x6F4]);
            }

            if (*(void**)&work[0x6F8] != 0) {
                ReleaseObjPalette(*(void**)&work[0x6F8]);
            }

            *(u16*)&work[0x750] = 0xFF80;
            *(u16*)&work[0x752] = 0xFF80;
            *(u16*)&work[0x754] = 0xFF80;
            *(u16*)&work[0x756] = 16;
            *(u16*)&work[0x758] = 64;
            *(u16*)&work[0x75A] = 112;
            work[0x7B5] = 24;
            work[0x7B1] = 16;
            work[0x7B2] = 16;
            work[0x7B3] = 16;
            work[0x7B4] = 16;
            *(u16*)&work[0x75C] = 8;
            *(u16*)&work[0x75E] = 8;
            *(u16*)&work[0x760] = 8;
            *(u16*)&work[0x762] = 31;
            *(u16*)&work[0x764] = 79;
            *(u16*)&work[0x766] = 127;
            *(u16*)&work[0x774] = 132;
            *(u16*)&work[0x776] = *(u16*)&gUnk_09036380[0x1C34];

            if (gGameState.flags & 8) {
                func_08002A10(*(void**)&work[0x728], gUnk_0891ED26);
                AnimInit((AnimState*)&work[0x734], gUnk_09EDF38C, gUnk_09EDF374);
                AnimStart((AnimState*)&work[0x734], 0, 1);
            } else {
                func_08002A10(*(void**)&work[0x728], gUnk_088E33C2);
                AnimInit((AnimState*)&work[0x734], gUnk_09EDEE14, gUnk_09EDEE08);
                AnimStart((AnimState*)&work[0x734], 0, 1);
            }

            work[0x7C2] = 0;
            work[0x7BD] = 0;
            work[0x7C5] = 0;
            *(u16*)&work[0x7A4] = 0;
            work[0x7C7] = 0;
            SetTaskUpdate(a, (void*)func_080A0A44);
        }
    }

    work[0x7C8] = 1;
    work[0x7C9] = 1;
    work[0x7CA] = 1;
    *(void**)&work[0x730] = AnimUpdate((AnimState*)&work[0x734]);
    TaskPoolUpdate((TaskPool*)&work[0x6FC]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A11CC.s");
#endif

s32 func_080A151C(void) {
    if (gGameState.level >= gUnk_09037FBA[gGameState.unk_178]) {
        return 1;
    }

    return 0;
}

void func_080A1554(u8* work) {
    s16 x;
    s16 y;
    s32* t;

    t = *(s32**)&work[0x0C];

    if (t != 0) {
        WorldToScreen(&x, &y, t[1], t[2], t[3]);
        *(s32*)&work[0x64] = x;
        *(s32*)&work[0x68] = y - 16;
    }
}
void LVUP_EFFECT_0(UnkStruct_080A18F4* w, UnkStruct_080A1A44_Args* a) {
    s32 i;
    UnkStruct_080A1A44_Args args;

    w->unk_0C = a->unk_0C;
    w->unk_64 = a->unk_00;
    w->unk_68 = a->unk_04;
    w->unk_30 = 30;
    w->unk_97 = a->unk_08;
    func_080A1554((u8*)w);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
        break;
    case 1:
        w->tiles = LoadObjTiles(gUnkEu_0916F992, 0x3E0);
        break;
    case 2:
        w->tiles = LoadObjTiles(gUnkEu_0917063A, 0x3E0);
        break;
    case 3:
        w->tiles = LoadObjTiles(gUnkEu_09170202, 0x3E0);
        break;
    case 4:
        w->tiles = LoadObjTiles(gUnkEu_0916FDCA, 0x3E0);
        break;
    default:
        w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
        break;
    }
#else
    w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
#endif
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);

    for (i = 0; i < 4; i++) {
        w->unk_10[i] = (w->unk_64 << 8) + gUnk_09037FFC[i];
        w->unk_20[i] = (w->unk_68 << 8) + gUnk_0903800C[i];
        w->unk_8C[i] = gUnk_0903801C[i];
        w->unk_34[i] = w->unk_30 * gSineTable[w->unk_8C[i] & 0xFF] + w->unk_10[i];
        w->unk_44[i] = -gSineTable[(w->unk_8C[i] & 0xFF) + 64] * w->unk_30 + w->unk_20[i];
        w->unk_54[i] = 0;
    }

    w->unk_94 = 0;
    w->unk_95 = 0;
    w->unk_96 = 24;
    TaskPoolInit(w->unk_98, 4);

    if (w->unk_0C != 0 && gUnk_02034AF8 == 0) {
        args.unk_00 = w->unk_34[0];
        args.unk_04 = w->unk_44[0];
        args.unk_0C = w->unk_0C;
        args.unk_10 = w->tiles;
        args.unk_14 = w->palette;
        TaskCreate(w->unk_98, gTaskDescLvupLogo, &args);
        gUnk_02034AF8 = 1;
    }
}
u8 LVUP_EFFECT_1(UnkStruct_080A18F4* w, void* a) {
    s32 i;

    func_080A1554((u8*)w);

    if ((s8)w->unk_96 > 0) {
        for (i = 0; i < 4; i++) {
            ApproachValue(&w->unk_10[i], w->unk_64 << 8, (s8)w->unk_96);
            ApproachValue(&w->unk_20[i], w->unk_68 << 8, (s8)w->unk_96);
        }

        w->unk_96--;
    } else {
        for (i = 0; i < 4; i++) {
            w->unk_8C[i] += 6;
            w->unk_10[i] = w->unk_64 << 8;
            w->unk_20[i] = w->unk_68 << 8;
        }

        if ((s16)w->unk_8C[0] > 0x100) {
            w->unk_30--;
        }
    }

    for (i = 0; i < 4; i++) {
        w->unk_34[i] = gSineTable[w->unk_8C[i] & 0xFF] * w->unk_30 + w->unk_10[i];
        w->unk_44[i] = -gSineTable[(w->unk_8C[i] & 0xFF) + 64] * w->unk_30 + w->unk_20[i];
    }

    w->unk_95++;
    TaskPoolUpdate(&w->unk_98);

    if (w->unk_30 == 0) {
        for (i = 0; i < 4; i++) {
            switch (i) {
            case 0:
                w->unk_7C[0] = 0x300;
                w->unk_6C[0] = -0x180;
                w->unk_8C[0] = 8;
                break;
            case 1:
                w->unk_7C[1] = 0x300;
                w->unk_6C[1] = -0x180;
                w->unk_8C[1] = -8;
                break;
            case 2:
                w->unk_7C[2] = 0x300;
                w->unk_6C[2] = -0x180;
                w->unk_8C[2] = 16;
                break;
            case 3:
                w->unk_7C[3] = 0x300;
                w->unk_6C[3] = -0x180;
                w->unk_8C[3] = -16;
                break;
            }
        }

        w->unk_94 = 1;
        SetTaskUpdate(a, (void*)func_080A18F4);
    }

    return 1;
}
u8 func_080A18F4(UnkStruct_080A18F4* w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        w->unk_6C[i] += 25;
        w->unk_44[i] += w->unk_6C[i];
        w->unk_34[i] += gSineTable[(u8)w->unk_8C[i]] * (w->unk_7C[i] >> 8);
    }

    w->unk_95++;

    if (w->unk_95 % 8 == 0 && (s8)w->unk_95 > 1) {
        w->unk_94++;
    }

    TaskPoolUpdate(&w->unk_98);

    if (w->unk_44[0] > 0xA000) {
        return 0;
    }

    return 1;
}

void LVUP_EFFECT_2(UnkStruct_080A18F4* w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (w->unk_94 <= 5) {
#ifdef VERSION_EU
            DrawSprite(w->unk_34[i] >> 8, w->unk_44[i] >> 8, gUnkEu_09F72E10[gLanguage][w->unk_94], w->tiles, w->palette, 0, 0, 20);
#else
            DrawSprite(w->unk_34[i] >> 8, w->unk_44[i] >> 8, gUnk_09EE7938[w->unk_94], w->tiles, w->palette, 0, 0, 20);
#endif
        }
    }

    TaskPoolDraw(w->unk_98);
}

void LVUP_EFFECT_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    TaskPoolDestroy(&work[0x98]);

    if (gBtlWork->unk_068 & 0x20000) {
        gBtlWork->unk_068 &= ~0x20000;
    }
}

#ifndef VERSION_EU
void Lvup_Logo_0(UnkStruct_080A18F4* w, UnkStruct_080A1A44_Args* a) {
    w->unk_34[0] = a->unk_00;
    w->unk_64 = a->unk_00;
    w->unk_44[0] = a->unk_04;
    w->unk_68 = a->unk_04;
    w->unk_0C = a->unk_0C;
    w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
    LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles = a->unk_10;
    w->palette = a->unk_14;
    func_080062F4(*(u16*)(a->unk_14 + 6) + 16, 1);
    w->unk_94 = 0;
    w->unk_95 = 0;
    w->unk_6C[0] = -0x280;
    m4aSongNumStart(0x23A);
}
#else
INCLUDE_ASM("card/Lvup_Logo_0.s");
#endif

s32 Lvup_Logo_1(u8* work) {
    *(s32*)&work[0x44] += *(s32*)&work[0x6C];
    *(s32*)&work[0x6C] += 25;
    func_080A1554(work);
    *(s32*)&work[0x34] = *(s32*)&work[0x64] << 8;
    ((s8*)work)[0x95]++;

    if (((s8*)work)[0x95] == 60) {
        return 0;
    }

    return 1;
}
void Lvup_Logo_2(u8* work) {
    DrawSprite(*(s32*)&work[0x34] >> 8, *(s32*)&work[0x44] >> 8,
               gUnk_09EEA19C[((s8*)work)[0x94]], *(void**)&work[0x00],
               *(void**)&work[0x04], 0, 0, 10);
}
void Lvup_Logo_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
    gUnk_02034AF8 = 0;
}

u8 func_080A1B4C(UnkStruct_080A1B4C* p, void* pool) {
    UnkStruct_080A1A44_Args args;

    gUnk_02034AF8 = 0;

    if (gBtlWork->unk_068 & 0x20000) {
        return 0;
    }

    args.unk_00 = p->unk_04;
    args.unk_04 = p->unk_08;
    args.unk_08 = 0;
    args.unk_0C = p;
    TaskCreate(pool, gTaskDescLVUPEFFECT, &args);
    gBtlWork->unk_068 |= 0x20000;
    return 1;
}

void func_080A1BB8(UnkStruct_080A1C48* w, void** t) {
    UnkStruct_080A1BB8* q;
    UnkStruct_080A1BB8_Entry* entries;
    u8 i;

    q = t[10];
    entries = q->unk_0C;

    for (i = 0; i < 10; i++) {
        w->unk_04[i] = 0;
        w->unk_2C[i] = 0;
    }

    for (i = 0; i < q->unk_10; i++) {
        if (w->unk_04[entries[i].unk_08] == 0) {
            w->unk_04[entries[i].unk_08] = LoadObjTiles(q->unk_00[entries[i].unk_08].unk_00, q->unk_00[entries[i].unk_08].unk_04);
            w->unk_2C[entries[i].unk_08] = LoadObjPalette(q->unk_04[entries[i].unk_08].unk_00, q->unk_04[entries[i].unk_08].unk_04);
        }
    }
}

void func_080A1C48(u8* work) {
    UnkStruct_080A1C48* w;
    u8 i;

    w = (UnkStruct_080A1C48*)work;

    for (i = 0; i <= 9; i++) {
        if (w->unk_04[i] != 0) {
            ReleaseObjTiles(w->unk_04[i]);
            ReleaseObjPalette(w->unk_2C[i]);
        }
    }
}
void Ev_mapObj_0(u8* work, u8* a) {
    void** t;

    work[0] = a[0];
    t = gUnk_09EE3CA0[work[0]];

    if (t[10] != 0) {
        func_080A1BB8(work, t);
        *(void**)&work[0x58] = t[10];
    }
}

u8 Ev_mapObj_1(u8* work) {
    UnkStruct_080A1C48* w;
    u8* p;
    u8* q;
    u8 i;

    w = (UnkStruct_080A1C48*)work;
    p = *(u8**)&work[0x58];
    q = *(u8**)&p[0x0C];

    for (i = 0; i < *(u16*)&p[0x10]; i++) {
        func_080062F4(*(u16*)((u8*)w->unk_2C[q[i * 12 + 8]] + 6) + 16, 0);
    }

    return 1;
}

void Ev_mapObj_2(UnkStruct_080A1C48* w) {
    UnkStruct_080A1BB8* q;
    UnkStruct_080A1BB8_Entry* entries;
    UnkStruct_080A1BB8_Entry* e;
    u8 i;

    q = w->unk_58;
    entries = q->unk_0C;

    for (i = 0; i < q->unk_10; i++) {
        e = &entries[i];
        DrawSprite(e->unk_00 - (*(s32*)&gUnk_02039DC8[0x58] >> 8), e->unk_04 - (*(s32*)&gUnk_02039DC8[0x5C] >> 8), q->unk_08[e->unk_08], w->unk_04[e->unk_08], w->unk_2C[e->unk_08], 0, 0x800, (u16)(-0x1004 - e->unk_04 * 4));
    }
}

void Ev_mapObj_3(u8* work) {
    func_080A1C48(work);
}

void func_080A1DAC(UnkStruct_080A1DAC* w) {
    UnkStruct_080A1DAC_Entry* e;
    UnkStruct_080A1DAC_Desc* d;

    e = &w->unk_00[w->unk_14];
    d = gUnk_09EE79B4[e->unk_02];
    w->unk_12 = e->unk_02;
    LoadBgTiles(0, d->unk_04, d->unk_0C);
    LoadBgPalette(0, d->unk_08, d->unk_0E);
    LoadBgMap(0, d->unk_00[0], 0x800);
    SetBgScroll(0, (*(s32*)&gUnk_02039DC8[0x58] >> 8) - (e->unk_04 >> 8), (*(s32*)&gUnk_02039DC8[0x5C] >> 8) - (e->unk_08 >> 8));

    if (d->unk_14 != 0) {
        w->unk_15 = 1;
    }

    SetBgBlend(0, 16, 16);
    gUnk_02039DC8[0x80] = 1;
    w->unk_0E = w->unk_0C = w->unk_16 = 0;
}

void func_080A1E4C(u8* work) {
    LoadBgTiles(0, gUnk_094233B8, 1280);
    LoadBgPalette(0, gUnk_096148D8, 32);
    LoadBgMap(0, gUnk_08125E24, 2048);
}

void func_080A1E80(u8* work) {
    u8* p;
    u16 v;
    u8 i;

    v = 16;
    p = *(u8**)&work[0] + work[0x14] * 16;

    for (i = 16; i <= 31; i++) {
        func_080062F4(i, 1);
    }

    func_080062F4(14, 1);

    if (*(s32*)&p[4] > 0) {
        v = *(s32*)&p[4];
    }

    if (*(u16*)&p[0xC] & 0x10) {
        func_08006184(0, v);
    } else {
        func_08006238(0, 16, v);
    }
}

void func_080A1ED8(u8* work) {
    u8* t;
    u16 v;

    v = 16;
    t = *(u8**)&work[0x00] + work[0x14] * 16;
    func_080062F4(14, 1);

    if (*(s32*)&t[4] > 0) {
        v = *(s32*)&t[4];
    }

    if (*(u16*)&t[12] & 0x10) {
        func_08006120(0, v);
    } else {
        func_080061E8(0, v);
    }
}
void EV_BG_EFFECT_0(u8* a, u8* b) {
    u8 t;
    u8 z;

    t = b[0];
    z = 0;
    a[19] = t;
    a[20] = z;
    a[21] = z;
    *(void**)&a[0] = gUnk_09EE3FB4[a[19]][5];
}
u8 EV_BG_EFFECT_1(UnkStruct_080A1DAC* w, void* a) {
    UnkStruct_080A1DAC_Entry* e;
    UnkStruct_080A1DAC_Entry* cur;
    u8 i;

    e = w->unk_00;

    if (e == 0) {
        return 0;
    }

    if (*(u16*)e[w->unk_14].unk_00 <= *(u16*)&gUnk_02039DC8[0x6C] && !(*(u16*)e[w->unk_14].unk_0C & 0x8000)) {
        w->unk_14++;
        cur = &e[w->unk_14];

        if (*(u16*)cur->unk_0C & 1) {
            func_080A1DAC(w);

            if (w->unk_15 != 0) {
                SetTaskUpdate(a, (void*)func_080A2024);
            }
        }

        if (*(u16*)cur->unk_0C & 4) {
            func_080A1E80((u8*)w);
        }

        if (*(u16*)cur->unk_0C & 8) {
            func_080A1ED8((u8*)w);
            w->unk_16 = 1;
        }

        if (*(u16*)cur->unk_0C & 2) {
            func_080A1E4C((u8*)w);
            gUnk_02039DC8[0x80] = 0;
            gBldCnt = *(u16*)&gUnk_02039DC8[0x6E];
            gBldAlpha = *(u16*)&gUnk_02039DC8[0x70];
        }
    }

    if (w->unk_16 == 1) {
        if (!func_08006314()) {
            w->unk_16 = 0;

            for (i = 16; i < 32; i++) {
                func_080062F4(i, 0);
            }
        }
    }

    return 1;
}

u8 func_080A2024(u8* work, void* a) {
    u8* p;

    p = *(u8**)&work[0] + work[0x14] * 16;
    SetBgScroll(0, (*(s32*)&gUnk_02039DC8[0x58] >> 8) - (*(s32*)&p[4] >> 8),
                (*(s32*)&gUnk_02039DC8[0x5C] >> 8) - (*(s32*)&p[8] >> 8));

    if (func_080A207C(work) == 0) {
        SetTaskUpdate(a, (void*)EV_BG_EFFECT_1);
    }

    return 1;
}

u8 func_080A207C(UnkStruct_080A1DAC* w) {
    UnkStruct_080A1DAC_Desc* d;
    UnkStruct_080A1DAC_Frame* tbl;

    if (w->unk_15 == 0) {
        return 0;
    }

    d = gUnk_09EE79B4[w->unk_12];
    tbl = d->unk_14;

    if (w->unk_0C < tbl[w->unk_0E].unk_00) {
        w->unk_0C++;
    } else {
        w->unk_0C = 0;

        if (w->unk_0E < d->unk_18 - 1) {
            w->unk_0E++;
            RequestDma3Copy(d->unk_04 + tbl[w->unk_0E].unk_02, (void*)GetBgCharBase(0), d->unk_0C);
        } else {
            if (d->unk_19 == -1) {
                w->unk_15 = 0;
                return 0;
            }

            w->unk_0E = d->unk_19;
            RequestDma3Copy(d->unk_04 + tbl[w->unk_0E].unk_02, (void*)GetBgCharBase(0), d->unk_0C);
        }
    }

    return 1;
}

void EV_BG_EFFECT_2(void) {
}
void EV_BG_EFFECT_3(void) {
}
void func_080A2124(u8* work) {
    TaskCreate(&work[0x10], gTaskDescEVBGEFFECT, work);
}
void StockInfo_0(u8* work, void* a) {
    u8 i;

    *(void**)&work[0x14] = a;
    TaskPoolInit(&work[0x18], 1);
    *(void**)&work[0] = LoadObjTiles(gUnk_0908FCEE, 0x12A0);
    *(void**)&work[4] = LoadObjPalette(gUnk_09613F78, 32);

    for (i = 16; i < 32; i++) {
        func_080062F4(i, 1);
    }

    *(s32*)&work[8] = 0x4C00;
    *(s32*)&work[0xC] = 0xBC00;
    work[0x10] = 16;

    switch (gGameState.unk_178) {
    case 0:
        func_0800FB2C(0);
        break;
    case 1:
        func_0800FB2C(2);
        break;
    case 2:
        func_0800FB2C(4);
        break;
    case 3:
        func_0800FB2C(1);
        break;
    case 4:
        func_0800FB2C(5);
        break;
    case 5:
        func_0800FB2C(3);
        break;
    case 6:
        func_0800FB2C(36);
        break;
    case 7:
        func_0800FB2C(6);
        break;
    case 8:
        func_0800FB2C(46);
        break;
    case 9:
        func_0800FB2C(7);
        break;
    case 10:
        func_0800FB2C(32);
        break;
    }
}

u8 StockInfo_1(u8* work, void* a) {
    if ((s8)work[0x10] > 0) {
        ApproachValue(&work[0x0C], 0x6C00, (u16)(s8)work[0x10]);
        work[0x10]--;
    } else {
        m4aSongNumStart(0xCA);
        func_080D8EB4(&work[0x18], gUnk_0903BFBC[gGameState.unk_178], 0, 0, 0x50);
        SetTaskUpdate(a, (void*)func_080A22A4);
    }

    return 1;
}

s32 func_080A22A4(u8* work) {
    if ((*(u8**)&work[0x14])[0] == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x18]);
    return 1;
}
void StockInfo_2(u8* work) {
    DrawSprite(*(s32*)&work[0x08] >> 8, *(s32*)&work[0x0C] >> 8, gUnk_09EEA28C,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    TaskPoolDraw(&work[0x18]);
}
void StockInfo_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    gGameState.unk_178++;
    TaskPoolDestroy(&work[0x18]);
}

void* func_080A2334(u16 a, u8 b) {
    if (b < gUnk_09EE7D84[a]->unk_04) {
        return LANGSTR(gUnk_09EE7D84[a]->unk_00[b]);
    }

    return 0;
}

u8 func_080A235C(u16 a) {
    return gUnk_09EE7D84[a]->unk_04;
}
u8 func_080A2370(void) {
    if (gGameState.level >= gUnk_0903BFD4[gGameState.unk_178]) {
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_080A23A0.s");

#ifndef VERSION_JP
s32 func_080A25B8(u8* work, void* a) {
    SetTaskUpdate(a, func_080A25E0);
    work[0x2B1]++;
    return 1;
}
#else
INCLUDE_ASM("card/func_080A25B8.s");
#endif
#ifdef VERSION_US
u8 func_080A25E0(u8* work, void* a) {
    s8* counter = (s8*)&work[0x2AC];

    if (*counter > 0) {
        ApproachValue((s32*)&work[0x290], 0x6C00, *counter);
        ApproachValue((s32*)&work[0x2A0], 0x6600, *counter);
        ApproachValue((s32*)&work[0x2A4], 0x6600, *counter);
        ApproachValue((s32*)&work[0x2A8], 0x6600, *counter);
        (*counter)--;
    } else if (*counter == 0) {
        m4aSongNumStart(202);
        work[0x2AC] = -1;
    }

    if (**(u8**)&work[0x2B4] == 0) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("card/func_080A25E0.s");
#endif
INCLUDE_ASM("card/func_080A2678.s");
#ifndef VERSION_JP
void func_080A27EC(u8* work) {
    func_08065AE0((TextSlot*)work, 20);
    func_08065AE0((TextSlot*)&work[0xA0], 20);
    func_08065AE0((TextSlot*)&work[0x140], 20);
    func_08065AE0((TextSlot*)&work[0x1E0], 20);
    ReleaseObjPalette(*(u8**)&work[0x280]);
    ReleaseObjTiles(*(void**)&work[0x284]);
    ReleaseObjPalette(*(u8**)&work[0x288]);
}
#else
INCLUDE_ASM("card/func_080A27EC.s");
#endif
INCLUDE_ASM("card/func_080A2844.s");
void func_080A2980(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    w->unk_78E = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = 0;
    w->unk_78D = func_08065B6C(&gUnk_0815C204[0x40], w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = func_08065B6C(eu_0805E924(gUnkEu_08895AF4), w->unk_280);
#else
    w->unk_78D = func_08065B6C(&gUnk_08159F38[0x2A], w->unk_280);
#endif
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_JP
    w->unk_794 = (207 - func_08065B08(w->unk_280, w->unk_78D)) / 2;
    w->unk_798 = 62;
#elif defined(VERSION_EU)
    w->unk_794 = (240 - eu_0806629C(w->unk_280, w->unk_78D)) / 2;
    w->unk_798 = 68;
#else
    w->unk_794 = (240 - func_08065B08(w->unk_280, w->unk_78D)) / 2;
    w->unk_798 = 68;
#endif
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

void func_080A2A80(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = 0;
    w->unk_78D = func_08065B6C(&gUnk_0815C204[0x80], w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = func_08065B6C(eu_0805E924(gUnkEu_08895C30), w->unk_280);
#else
    w->unk_78D = func_08065B6C(&gUnk_0815C204[0xEA], w->unk_280);
#endif
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (250 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_796 = 64;
#ifdef VERSION_JP
    w->unk_794 = (219 - func_08065B08(w->unk_280, w->unk_78D)) / 2;
#elif defined(VERSION_EU)
    w->unk_794 = (240 - eu_0806629C(w->unk_280, w->unk_78D)) / 2;
#else
    w->unk_794 = (240 - func_08065B08(w->unk_280, w->unk_78D)) / 2;
#endif
    w->unk_798 = 62;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

#ifdef VERSION_JP
extern u8 gUnk_0814FBB0[];
extern u8 gUnk_0814FBBC[];
extern u8 gUnk_0814FBD4[];
#endif
void func_080A2BA4(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = func_08065B6C(gUnk_0814FBB0, w);
    w->unk_78D = func_08065B6C(gUnk_0814FBBC, w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = func_08065B6C(eu_0805E924(gUnkEu_08895CF8), w->unk_280);
#else
    w->unk_78D = func_08065B6C(&gUnk_0815C204[0xA8], w->unk_280);
#endif
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (242 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_796 = 66;
    w->unk_794 = (242 - func_08065B08(w->unk_280, w->unk_78D)) / 2;
#ifdef VERSION_JP
    w->unk_798 = 82;
#else
    w->unk_798 = 68;
#endif
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

void func_080A2CC4(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = func_08065B6C(gUnk_0814FBB0, w);
    w->unk_78D = func_08065B6C(gUnk_0814FBD4, w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = func_08065B6C(eu_0805E924(gUnkEu_08895DBC), w->unk_280);
#else
    w->unk_78D = func_08065B6C(&gUnk_0815C204[0x6C], w->unk_280);
#endif
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (243 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_796 = 66;
    w->unk_794 = (243 - func_08065B08(w->unk_280, w->unk_78D)) / 2;
#ifdef VERSION_JP
    w->unk_798 = 82;
#else
    w->unk_798 = 68;
#endif
    w->unk_7A4 = 0;
    w->unk_790 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

s32 func_080A2DE4(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 8) ||
        (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}

void func_080A2E14(UnkStruct_080A2F54* w) {
    func_080664D8(w->unk_792, w->unk_796, w, w->unk_784, 1, w->unk_78C);
    func_080664D8(w->unk_794, w->unk_798, w->unk_280, w->unk_784, 1, w->unk_78D);
    func_080664D8(w->unk_79A, w->unk_79C, w->unk_500, w->unk_784, 1, w->unk_78E);
    DrawSprite(120, 80, gUnk_09EF1278[0], w->tiles, w->unk_788, 0, 0, 2);
}

void func_080A2EF8(UnkStruct_080A2F54* w) {
    func_08065AE0(w, 80);
    func_08065AE0(w->unk_280, 80);
    func_08065AE0(w->unk_500, 80);
    ReleaseObjPalette(w->unk_784);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->unk_788);
    w->unk_7A0[0] = 0;
}

#ifdef VERSION_JP
#define DECK_PROMPT_LEFT_DX 30
#define DECK_PROMPT_RIGHT_DX 35
#define DECK_CLEAR_TEXT_Y 66
#else
#define DECK_PROMPT_LEFT_DX 20
#define DECK_PROMPT_RIGHT_DX 20
#define DECK_CLEAR_TEXT_Y 61
#endif

void Deck_Yes_No_0(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
#ifdef VERSION_EU
    w->unk_78C = func_08065B6C(eu_0805E924(gUnkEu_08890EC0), w);
    w->unk_78D = func_08065B6C(eu_0805E924(gUnkEu_08890E1C), w->unk_280);
    w->unk_78E = func_08065B6C(eu_0805E924(gUnkEu_08890E44), w->unk_500);
#else
    w->unk_78C = func_08065B6C(gUnk_08159FBC, w);
    w->unk_78D = func_08065B6C(gUnk_08159E10, w->unk_280);
    w->unk_78E = func_08065B6C(gUnk_08159E18, w->unk_500);
#endif
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (240 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_796 = 66;
    w->unk_794 = (240 - func_08065B08(w->unk_280, w->unk_78D)) / 2 - DECK_PROMPT_LEFT_DX;
    w->unk_798 = 88;
    w->unk_79A = (240 - func_08065B08(w->unk_500, w->unk_78E)) / 2 + DECK_PROMPT_RIGHT_DX;
    w->unk_79C = 88;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}
s32 func_080A30C0(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}
void Deck_Clear_0(UnkStruct_080A2F54* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    func_08065ACC(w, 0x50);
    func_08065ACC(w->unk_280, 0x50);
    func_08065ACC(w->unk_500, 0x50);
#ifdef VERSION_EU
    w->unk_78C = func_08065B6C(eu_0805E924(gUnkEu_08895E94), w);
    w->unk_78D = func_08065B6C(eu_0805E924(gUnkEu_08890E1C), w->unk_280);
    w->unk_78E = func_08065B6C(eu_0805E924(gUnkEu_08890E44), w->unk_500);
#else
    w->unk_78C = func_08065B6C(gUnk_0815C1C2, w);
    w->unk_78D = func_08065B6C(gUnk_08159E10, w->unk_280);
    w->unk_78E = func_08065B6C(gUnk_08159E18, w->unk_500);
#endif
    w->unk_784 = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->unk_788 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_792 = (240 - func_08065B08(w, w->unk_78C)) / 2;
    w->unk_794 = (240 - func_08065B08(w->unk_280, w->unk_78D)) / 2 - DECK_PROMPT_LEFT_DX;
    w->unk_798 = 88;
    w->unk_79A = (240 - func_08065B08(w->unk_280, w->unk_78E)) / 2 + DECK_PROMPT_RIGHT_DX;
    w->unk_79C = 88;
    w->unk_796 = DECK_CLEAR_TEXT_Y;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

void func_080A324C(UnkStruct_080A324C* p) {
    s32 i;

    for (i = 0; i < 270; i++) {
        p->unk_001[i] = gUnk_0203A8C0[i];
    }

    for (i = 0; i < 999; i++) {
        p->unk_110[i] = gCardCollection[i];
    }

    for (i = 0; i < 3; i++) {
        memcpy(&p->unk_8E0[i], &gDecks[i], sizeof(Deck));
    }

    p->unk_8DE = gCardCount;
    p->unk_000 = GetActiveDeckIndex();
}

void func_080A32DC(u8* p) {
    u16 i;
    u8* src;
    u8* dst;
    u8* src2;
    u16* dst2;
    Deck* dst3;
    u8* src3;
    Deck* d;

    for (i = 0; i < 0x10E; i++) {
        dst = gUnk_0203A8C0;
        src = &p[1];
        dst[i] = src[i];
    }

    for (i = 0; i < 0x3E7; i++) {
        dst2 = gCardCollection;
        src2 = &p[0x110];
        dst2[i] = *(u16*)(src2 + (i << 1));
    }

    for (i = 0; i < 3; i++) {
        dst3 = gDecks;
        d = &dst3[i];
        src3 = &p[i * 0xE0];
        memcpy(d, &src3[0x8E0], 0xE0);
    }

    gCardCount = *(u16*)&p[0x8DE];
    SetActiveDeckIndex(p[0]);
}

void func_080A3370(u8* p) {
    s32 i;

    for (i = 0; i <= 0x10D; i++) {
        p[i] = gUnk_0203A8C0[i];
    }
}
void func_080A3398(u8* p) {
    u16 i;

    for (i = 0; i <= 0x10D; i++) {
        gUnk_0203A8C0[i] = p[i];
    }
}

void func_080A33C4(UnkStruct_080A3F5C* w, void* a) {
    vu32 zero;

    zero = 0;
    CpuSet((void*)&zero, w, 0x05000054);
    ((UnkStruct_02034AFC*)w)->unk_13C = func_0806BA74(0, 0);
    *(u64*)&w->unk_10C = *(u64*)a;
    w->unk_114 = (UnkStruct_080A3F5C_Sel*)&gUnk_09EE8008[*(u16*)&w->unk_110];
    w->unk_000 = 0;
    w->unk_004 = 0;
    w->unk_008 = 0;
    w->unk_00C = 0;
    w->unk_010 = 0;
    w->unk_014 = 0;
    w->unk_018 = 0;
    w->unk_01C = 0;
    w->unk_0C0 = 0;
    w->unk_118 = gUnk_09033C98[w->unk_114->unk_04];
    w->unk_11C = 0;
    w->unk_120 = 0;
    w->unk_124 = 0;
    w->unk_128 = 0;
    w->unk_12C = 0;
    w->unk_130 = 0;
    w->unk_134 = 0;
    *(s32*)&w->unk_138 = 0;
    ((UnkStruct_02034AFC*)w)->unk_13C = 0;
    w->unk_13E = 0;
    w->unk_140 = 8;
    w->unk_141 = 0;
    w->unk_142 = 0;
    w->unk_143 = 0;
    w->unk_144 = 0;
    w->unk_145 = 0;
    w->unk_146[0] = 0;
    w->unk_146[1] = 0;
    w->unk_148 = 1;
    w->unk_149 = 0;
    w->unk_14A[0] = 0;
    w->unk_14A[1] = 0;
    w->unk_14C = 0;
    w->unk_14D = 0;
    w->unk_14E = 0;
    w->unk_14F = 1;

    switch ((u32)w->unk_114->unk_04) {
    case 0:
    case 1:
        w->unk_14D = 1;
        break;
    case 2:
    case 3:
        w->unk_14D = 0;
        break;
    }

    gUnk_0203A9D4 = 1;
    gUnk_0203A9D8 = 0;
    SetBgScroll(w->unk_10C, 0, 0);

    switch (w->unk_113) {
    case 0:
    case 1:
        SetBgPriority(w->unk_10C, 0);
        break;
    case 2:
    case 3:
        break;
    }

    gUnk_02034AFC = (UnkStruct_02034AFC*)w;
}

u8 func_080A3558(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Entry* tbl;

    ApproachValue(&w->unk_118, gUnk_09033CA0[w->unk_114->unk_04], w->unk_140);
    ApproachValue(&w->unk_11C, gUnk_09033CE0[w->unk_114->unk_04], w->unk_140);
    func_08005244(w->unk_10C, w->unk_118, 0);
    w->unk_12C = AnimUpdate(w->unk_0C4);

    if (w->unk_140 != 0) {
        w->unk_140--;
    } else {
        tbl = gUnk_09EE45DC[w->unk_114->unk_00];

        if (tbl[w->unk_114->unk_08].unk_10 > 1) {
            AnimStart(w->unk_0C4, 1, tbl[w->unk_114->unk_08].unk_11);
        }

        switch (w->unk_113) {
        case 0:
            SetTaskUpdate(a, (void*)func_080A3A98);
            break;
        case 1:
            SetTaskUpdate(a, (void*)func_080A3F5C);
            break;
        }
    }

    return 1;
}

u8 func_080A3640(UnkStruct_080A3F5C* w, void* a) {
    LoadBgTiles(w->unk_10C, gUnk_094233B8, 1280);
    LoadBgPalette(w->unk_10C, gUnk_096148D8, 32);
    func_0800516C(w->unk_10C, gUnk_09EE4724[((UnkStruct_0809E0A4*)w->unk_114)->unk_04], 2, 1);
    func_08005244(w->unk_10C, *(u16*)&w->unk_118, 0);
    SetTaskUpdate(a, (void*)func_080A36B0);
    return 1;
}

u8 func_080A36B0(UnkStruct_080A3F5C* w, void* a) {
#ifdef VERSION_JP
    w->unk_143 = func_0806BDB8(gUnk_09033CA8[w->unk_114->unk_04],
                               gUnk_09033CB8[w->unk_114->unk_04],
                               *(s32*)((u8*)w->unk_114 + 0x0C),
                               (s32*)&w->unk_138);
#else
    s32* p;

    p = (s32*)&w->unk_138;

    if (*p != 0) {
        w->unk_143 = func_0806BB44(gUnk_09033CA8[w->unk_114->unk_04],
                                   gUnk_09033CB8[w->unk_114->unk_04] - 0x200,
                                   *p, p);
    } else {
        w->unk_143 = func_0806BB44(gUnk_09033CA8[w->unk_114->unk_04],
                                   gUnk_09033CB8[w->unk_114->unk_04] - 0x200,
                                   (s32)LANGSTR(*(void**)((u8*)w->unk_114 + 0x0C)), p);
    }
#endif

    func_08065ACC((TextSlot*)w->unk_020, 10);
    func_08065ACC((TextSlot*)w->unk_070, 10);
    SetTaskUpdate(a, (void*)func_080A3754);

    return 1;
}
u8 func_080A3754(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Sel* sel;
    UnkStruct_080A3F5C_Entry* e;

    w->unk_149 = 1;
    sel = w->unk_114;

    if (sel->unk_00 != 62) {
        e = gUnk_09EE45DC[sel->unk_00];
        w->unk_000 = AllocObjTiles(0xD80, 0);
        w->unk_004 = LoadObjPalette(e[w->unk_114->unk_08].unk_04, 32);
        func_08002A10(w->unk_000, e[w->unk_114->unk_08].unk_00);
        AnimInit(w->unk_0C4, e[w->unk_114->unk_08].unk_0C, e[w->unk_114->unk_08].unk_08);
        AnimStart(w->unk_0C4, 0, e[w->unk_114->unk_08].unk_11);
        w->unk_12C = AnimGetGfx(w->unk_0C4);
        w->unk_11C = gUnk_09033CD0[w->unk_114->unk_04];
        w->unk_120 = gUnk_09033CF0[w->unk_114->unk_04];
    } else {
        w->unk_000 = 0;
        w->unk_004 = 0;
    }

    SetTaskUpdate(a, (void*)func_080A3558);
    return 1;
}
void func_080A3848(UnkStruct_080A3F5C* w) {
    void** p;

    if (w->unk_149 != 0) {
        func_0806C2C0(w->unk_141);
    }

    if (w->unk_000 != 0) {
        if (w->unk_14D != 0) {
            DrawSprite(w->unk_11C >> 8, w->unk_120 >> 8, w->unk_12C, w->unk_000, w->unk_004, 0, 1, 0);
        } else {
            DrawSprite(w->unk_11C >> 8, w->unk_120 >> 8, w->unk_12C, w->unk_000, w->unk_004, 0, 0, 0);
        }

        if (w->unk_008 != 0 && w->unk_148 != 0) {
            DrawSprite(gUnk_09033D08[w->unk_114->unk_04][0] >> 8, gUnk_09033D08[w->unk_114->unk_04][1] >> 8,
                       w->unk_130, w->unk_008, w->unk_00C, 0, 0, 10);
        }
    }

    if (w->unk_010 != 0) {
        DrawSprite(w->unk_124 >> 8, w->unk_128 >> 8, w->unk_134, w->unk_010, w->unk_014, 0, 1, 9);
    }

    if (w->unk_018 != 0) {
        p = &gUnk_09EF126C;
        DrawSprite(120, 80, p[1], w->unk_018, w->unk_01C, 0, 0, 10);
        func_080664D8((240 - w->unk_146[0] * 10) >> 1, 67, w->unk_020, w->unk_0C0, 0, w->unk_146[0]);
        func_080664D8((240 - w->unk_146[1] * 10) >> 1, 82, w->unk_070, w->unk_0C0, 0, w->unk_146[1]);
    }
}

void func_080A3A04(UnkStruct_080A3F5C* w) {
    func_0806C34C();

    if (w->unk_000 != 0) {
        ReleaseObjTiles(w->unk_000);
    }

    if (w->unk_004 != 0) {
        ReleaseObjPalette(w->unk_004);
    }

    if (w->unk_008 != 0) {
        ReleaseObjTiles(w->unk_008);
    }

    if (w->unk_00C != 0) {
        ReleaseObjPalette(w->unk_00C);
    }

    if (w->unk_010 != 0) {
        ReleaseObjTiles(w->unk_010);
    }

    if (w->unk_014 != 0) {
        ReleaseObjPalette(w->unk_014);
    }

    if (w->unk_018 != 0) {
        ReleaseObjTiles(w->unk_018);
    }

    if (w->unk_01C != 0) {
        ReleaseObjPalette(w->unk_01C);
    }

    if (w->unk_0C0 != 0) {
        ReleaseObjPalette((u8*)w->unk_0C0);
    }

    func_08065AE0((TextSlot*)w->unk_020, 10);
    func_08065AE0((TextSlot*)w->unk_070, 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034AFC = 0;
}

u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Sel* sel;
    UnkStruct_080A3F5C_Entry* e;

    w->unk_12C = AnimUpdate(w->unk_0C4);

    if (GetKeysPressed() & 1) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;
    sel = w->unk_114;

    if (w->unk_142 >= sel->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(0x74);
        } else {
            e = gUnk_09EE45DC[sel->unk_00];
            AnimStart(w->unk_0C4, 0, e[sel->unk_08].unk_11);

            if (w->unk_008 == 0) {
                w->unk_008 = AllocObjTiles(0x40, 0);
                w->unk_00C = LoadObjPalette(gUnk_08F69BE4, 32);
                func_08002A10(w->unk_008, gUnk_09320796);
                AnimInit(w->unk_0DC, gUnk_09EEFD38, gUnk_09EEFCAC);
                AnimStart(w->unk_0DC, 2, 1);
                w->unk_130 = AnimGetGfx(w->unk_0DC);
            }

            w->unk_148 = 1;
            SetTaskUpdate(a, (void*)func_080A3BB0);
        }

        w->unk_142 = 0;
    }

    return 1;
}
INCLUDE_ASM("card/func_080A3BB0.s");

u8 func_080A3DD0(UnkStruct_080A3F5C* w) {
    if (w->unk_008 != 0) {
        w->unk_130 = AnimUpdate(w->unk_0DC);
    }

    w->unk_12C = AnimUpdate(w->unk_0C4);
    w->unk_13E++;

    if (w->unk_13E > 15) {
        w->unk_149 = 0;
        w->unk_148 = 0;
        ApproachValue(&w->unk_118, gUnk_09033C98[w->unk_114->unk_04], w->unk_140);
        ApproachValue(&w->unk_11C, gUnk_09033CD0[w->unk_114->unk_04], w->unk_140);
        func_08005244(w->unk_10C, w->unk_118, 0);

        if (w->unk_140 == 0) {
            return 0;
        }

        w->unk_140--;
    }

    return 1;
}

u8 func_080A3E8C(UnkStruct_080A3F5C* w, void* a) {
    w->unk_12C = AnimUpdate(w->unk_0C4);
    w->unk_134 = AnimUpdate(w->unk_0F4);

    switch (GetKeysRepeat()) {
    case 0x40:
    case 0x80:
        w->unk_144 ^= 1;
        w->unk_145 = 4;
        break;
    case 1:
    case 8:
        m4aSongNumStart(0x66);

        if (w->unk_144 == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        SetTaskUpdate(a, (void*)func_080A3DD0);
        break;
    }

    if (w->unk_145 != 0) {
        ApproachValue(&w->unk_128, gUnk_09033D28[w->unk_144], w->unk_145);
        w->unk_145--;
    }

    return 1;
}

u8 func_080A3F5C(UnkStruct_080A3F5C* w, void* a) {
    UnkStruct_080A3F5C_Entry* e;

    w->unk_12C = AnimUpdate(w->unk_0C4);

    if (GetKeysPressed() & 1) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;

    if (w->unk_142 >= w->unk_114->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(0x74);
        } else {
            e = gUnk_09EE45DC[w->unk_114->unk_00];
            AnimStart(w->unk_0C4, 0, e[w->unk_114->unk_08].unk_11);
            SetTaskUpdate(a, (void*)func_080A4010);
        }

        w->unk_142 = 0;
    }

    return 1;
}
u8 func_080A4010(UnkStruct_080A3F5C* w, void* a) {
#ifndef VERSION_JP
    s32* p;
#endif

    w->unk_12C = AnimUpdate(w->unk_0C4);

    if (w->unk_14F == 0) {
        SetTaskUpdate(a, (void*)func_080A3DD0);
    } else if (w->unk_14E == 1) {
        w->unk_14E = 0;
        w->unk_114 = (UnkStruct_080A3F5C_Sel*)&gUnk_09EE8008[*(u16*)&w->unk_110];
#ifdef VERSION_JP
        w->unk_143 = func_0806BDB8(gUnk_09033CA8[w->unk_114->unk_04],
                                   gUnk_09033CB8[w->unk_114->unk_04],
                                   *(s32*)((u8*)w->unk_114 + 0x0C), (s32*)&w->unk_138);
#else
        p = (s32*)&w->unk_138;

        if (*p != 0) {
            w->unk_143 = func_0806BB44(gUnk_09033CA8[w->unk_114->unk_04],
                                       gUnk_09033CB8[w->unk_114->unk_04] - 0x200, *p, p);
        } else {
            w->unk_143 = func_0806BB44(gUnk_09033CA8[w->unk_114->unk_04],
                                       gUnk_09033CB8[w->unk_114->unk_04] - 0x200,
                                       (s32)LANGSTR(*(void**)((u8*)w->unk_114 + 0x0C)), p);
        }
#endif

        w->unk_141 = w->unk_143;
    }

    return 1;
}

s32 func_080A40EC(u64* src) {
    if (gUnk_02034AFC != 0) {
        gUnk_02034AFC->unk_10C = *src;
        gUnk_02034AFC->unk_14E = 1;

        return 1;
    }

    return 0;
}

void func_080A411C(void* pool, u32 a, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_07 = 0;

    if (gUnk_09EE8008[b].unk_00 == 62) {
        if (gUnk_09EE8008[b].unk_10 & 2) {
            TaskCreate(pool, gUnk_09EE8E48, &args);
        } else {
            TaskCreate(pool, gUnk_09EE8E30, &args);
        }
    } else {
        TaskCreate(pool, gUnk_09EE8E18, &args);
    }
}

void func_080A4188(void* pool, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = 0;
    args.unk_04 = b;
    args.unk_07 = 2;

    if (gUnk_09EE8008[b].unk_10 & 2) {
        TaskCreate(pool, gUnk_09EE8E48, &args);
    } else {
        TaskCreate(pool, gUnk_09EE8E30, &args);
    }
}

void func_080A41F0(void* pool, u16 a) {
    UnkStruct_080A4188 args;

    func_080A42C8();
    args.unk_00 = 0;
    args.unk_04 = a;
    args.unk_07 = 3;
    TaskCreate(pool, gUnk_09EE8E30, &args);
}

void func_080A4234(void* pool, u32 a, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_07 = 1;

    if (func_080A42C8() != 0) {
        if ((u8)func_080A40EC((u64*)&args) == 0) {
            func_080A4D7C((u64*)&args);
        }
    } else if (gUnk_09EE8008[b].unk_00 == 62) {
        TaskCreate(pool, gUnk_09EE8E30, &args);
    } else {
        TaskCreate(pool, gUnk_09EE8E18, &args);
    }
}

void func_080A42B4(void) {
    gUnk_0203A9D4 = 0;
    gUnk_0203A9D8 = 0;
}

u8 func_080A42C8(void) {
    return gUnk_0203A9D4;
}

u8 func_080A42D4(void) {
    return gUnk_0203A9D8;
}

u8 func_080A42E0(void) {
    if (gUnk_02034AFC != 0) {
        gUnk_02034AFC->unk_14F = 0;
        return 1;
    }

    return func_080A4DAC();
}
INCLUDE_ASM("card/func_080A430C.s");

u8 func_080A4578(UnkStruct_080A3F5C* w, void* a) {
    void* pal;

    switch (w->unk_113) {
    case 0:
    case 1:
        pal = &gUnk_050001C0[0x20];
        LoadBgTiles(w->unk_10C, gUnk_0950E2F8, 0x140);
        LoadBgMap(w->unk_10C, gUnk_096112B8, 0x800);
        LoadPalette(gUnk_09611AB8, pal, 32);

        switch ((u32)w->unk_114->unk_04) {
        case 0:
        case 2:
            SetBgScroll(w->unk_10C, -24, 0);
            break;
        case 1:
        case 3:
            SetBgScroll(w->unk_10C, -24, -94);
            break;
        default:
            SetBgScroll(w->unk_10C, -24, -94);
            break;
        }
        break;
    case 2:
    case 3:
        switch ((u32)w->unk_114->unk_04) {
        case 0:
        case 2:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x2200;
            break;
        case 1:
        default:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x7E00;
            break;
        }

        w->unk_018 = LoadObjTiles(&gUnk_093F8C8E[0xC1E], 0x1800);

        if (w->unk_018 == 0) {
            w->unk_146[1] = 1;
            w->unk_018 = LoadObjTiles(&gUnk_0950E2F8[0x140], 0x680);
        } else {
            w->unk_146[1] = 0;
        }

        w->unk_01C = LoadObjPalette(gUnk_09611AB8, 32);
        func_080062F4(w->unk_01C->unk_06 + 16, 1);
        break;
    }

    switch (w->unk_113) {
    case 0:
    case 2:
        SetTaskUpdate(a, (void*)func_080A470C);
        break;
    case 1:
    case 3:
        SetTaskUpdate(a, (void*)func_080A4CC8);
        break;
    }

    return 1;
}

INCLUDE_ASM("card/func_080A470C.s");
s32 func_080A4910(UnkStruct_080A3F5C* w) {
    if (w->unk_000 != 0) {
        *(void**)&w->unk_128 = AnimUpdate(w->unk_0DC);
    }

    ((s16*)&w->unk_134)[1] += 1;

    if (((s16*)&w->unk_134)[1] > 15) {
        ((u8*)w)[0x141] = 0;
        return 0;
    }

    return 1;
}
u8 func_080A4958(UnkStruct_080A3F5C* w, void* a) {
    w->unk_12C = AnimUpdate(w->unk_0F4);

    switch (GetKeysPressed()) {
    case 0x40:
        if (w->unk_13D != 0) {
            w->unk_13D--;
            m4aSongNumStart(0x65);
        }

        ((u8*)&w->unk_13E)[0] = 4;
        break;
    case 0x80:
        if (w->unk_13D == 0) {
            w->unk_13D++;
            m4aSongNumStart(0x65);
        }

        ((u8*)&w->unk_13E)[0] = 4;
        break;
    case 1:
    case 8:
        m4aSongNumStart(0x66);

        if (w->unk_13D == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        w->unk_142 = 0;
        SetTaskUpdate(a, (void*)func_080A4910);
        break;
    }

    if (((u8*)&w->unk_13E)[0] != 0) {
        ApproachValue(&w->unk_11C, gUnk_09033D28[w->unk_13D] - 0x500, ((u8*)&w->unk_13E)[0]);
        ((u8*)&w->unk_13E)[0]--;
    }

    return 1;
}

void func_080A4A50(UnkStruct_080A3F5C* w) {
    func_0806C2C0(w->unk_138[1]);

    switch (w->unk_113) {
    case 2:
    case 3:
        if (w->unk_018 != 0) {
            if (w->unk_146[1] != 0) {
                DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, (&gUnk_09EF12E8[2])[0],
                           w->unk_018, w->unk_01C, 0, 0, 10);
            } else {
                DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, (&gUnk_09EF1278[2])[0],
                           w->unk_018, w->unk_01C, 0, 0, 10);
            }
        }
        break;
    }

    if (w->unk_000 != 0) {
        if (w->unk_141 != 0) {
            DrawSprite(120, gUnk_09033D08[w->unk_114->unk_04][1] >> 8, *(void**)&w->unk_128,
                       w->unk_000, w->unk_004, 0, 0, 5);
        }
    }

    if (w->unk_008 != 0) {
        DrawSprite(w->unk_118 >> 8, w->unk_11C >> 8, w->unk_12C,
                   w->unk_008, w->unk_00C, 0, 1, 5);
    }

    if (w->unk_144 != 0) {
        DrawSprite(120, 75, gUnk_09EF126C[1], w->unk_010, w->unk_014, 0, 0, 10);
        func_080664D8((240 - func_08065B08((TextSlot*)w->unk_020, ((u8*)&w->unk_13E)[1])) >> 1, 62, w->unk_020,
                      (void*)w->unk_0C0, 0, ((u8*)&w->unk_13E)[1]);
        func_080664D8((240 - func_08065B08((TextSlot*)w->unk_070, w->unk_140)) >> 1, 77, w->unk_070,
                      (void*)w->unk_0C0, 0, w->unk_140);
    }
}

void func_080A4C1C(UnkStruct_080A3F5C* w) {
    if (w->unk_113 <= 1) {
        DisableBg(w->unk_10C);
    }

    func_0806C34C();

    if (w->unk_000 != 0) {
        ReleaseObjTiles(w->unk_000);
    }

    if (w->unk_004 != 0) {
        ReleaseObjPalette(w->unk_004);
    }

    if (w->unk_008 != 0) {
        ReleaseObjTiles(w->unk_008);
    }

    if (w->unk_00C != 0) {
        ReleaseObjPalette(w->unk_00C);
    }

    if (w->unk_010 != 0) {
        ReleaseObjTiles(w->unk_010);
    }

    if (w->unk_018 != 0) {
        ReleaseObjTiles(w->unk_018);
    }

    if (w->unk_01C != 0) {
        ReleaseObjPalette(w->unk_01C);
    }

    if (w->unk_014 != 0) {
        ReleaseObjPalette(w->unk_014);
    }

    if (w->unk_0C0 != 0) {
        ReleaseObjPalette((u8*)w->unk_0C0);
    }

    func_08065AE0((TextSlot*)w->unk_020, 10);
    func_08065AE0((TextSlot*)w->unk_070, 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034B00 = 0;
}

#if !defined(VERSION_JP) && !defined(VERSION_EU)
u8 func_080A4CC8(UnkStruct_080A3F5C* w, void* a) {
    s32* p;
    u8 x;

    if (w->unk_146[0] == 0) {
        return 0;
    }

    if (w->unk_145 == 1) {
        w->unk_145 = 0;
        w->unk_114 = (UnkStruct_080A3F5C_Sel*)&gUnk_09EE8008[*(u16*)&w->unk_110];
        p = (s32*)&w->unk_130;

        if (*p != 0) {
            w->unk_138[3] = func_0806BB44(
                0x2E00,
                gUnk_09041E80[w->unk_114->unk_04] - 0x200,
                *p, p);
        } else {
            w->unk_138[3] = func_0806BB44(
                0x2E00,
                gUnk_09041E80[w->unk_114->unk_04] - 0x200,
                (s32)LANGSTR(*(void**)((u8*)w->unk_114 + 0x0C)),
                p);
        }

        x = w->unk_138[3];
        w->unk_138[1] = x;
    }

    return 1;
}
#elif defined(VERSION_JP)
u8 func_080A4CC8(UnkStruct_080A3F5C* w, void* a) {
    if (w->unk_146[0] == 0) {
        return 0;
    }

    if (w->unk_145 == 1) {
        w->unk_145 = 0;
        w->unk_114 = (UnkStruct_080A3F5C_Sel*)&gUnk_09EE8008[*(u16*)&w->unk_110];
        w->unk_138[3] = func_0806BDB8(
            0x2E00,
            gUnk_09033CB8[w->unk_114->unk_04],
            (s32)(*(void**)((u8*)w->unk_114 + 0x0C)),
            (s32*)&w->unk_130);
        w->unk_138[1] = w->unk_138[3];
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_080A4CC8.s");
#endif

s32 func_080A4D7C(u64* src) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_10C = *src;
        gUnk_02034B00->unk_145 = 1;

        return 1;
    }

    return 0;
}

s32 func_080A4DAC(void) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_146[0] = 0;
        return 1;
    }

    return 0;
}
INCLUDE_ASM("card/func_080A4DCC.s");

u8 func_080A4F14(UnkStruct_080A3F5C* w, void* a) {
    void* pal;
    switch (w->unk_113) {
    case 0:
    case 1:
        pal = (void*)0x050001E0;
        LoadBgTiles(w->unk_10C, gUnk_099597E4, 0x140);
        LoadBgMap(w->unk_10C, gUnk_09985F44, 0x800);
        LoadPalette(gUnk_09611AB8, pal, 32);
        switch ((u32)w->unk_114->unk_04) {
        case 0:
        case 2:
            SetBgScroll(w->unk_10C, 0, 0);
            break;
        case 1:
        case 3:
            SetBgScroll(w->unk_10C, 0, 0);
            break;
        default:
            SetBgScroll(w->unk_10C, 0, 0);
            break;
        }
        break;
    case 2:
    case 3:
        switch ((u32)w->unk_114->unk_04) {
        case 0:
        case 2:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x2000;
            break;
        case 1:
        default:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x8200;
            break;
        }
        w->unk_018 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
        w->unk_01C = (UnkStruct_080038C8*)LoadObjPalette(gUnk_09611AB8, 32);
        func_080062F4(w->unk_01C->unk_06 + 16, 1);
        break;
    }
    if (w->unk_113 == 0 || w->unk_113 == 2) {
        SetTaskUpdate(a, (void*)func_080A5034);
    }
    return 1;
}

u8 func_080A5034(UnkStruct_080A3F5C* w, void* a) {
    u8* pal;

    w->unk_008 = AllocObjTiles(0x120, 0);
    pal = gUnk_09614418;
    w->unk_00C = LoadObjPalette(pal, 32);
#ifdef VERSION_EU
    func_080062F4(((UnkStruct_080038C8*)w->unk_00C)->unk_06 + 16, 1);
#else
    func_080062F4(w->unk_01C->unk_06 + 16, 1);
#endif
    LoadObjPaletteBank(((UnkStruct_080038C8*)w->unk_00C)->unk_06, pal);
    func_08002A10(w->unk_008, gUnk_090A4664);
    AnimInit(w->unk_0F4, gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart(w->unk_0F4, 2, 1);
    w->unk_12C = AnimGetGfx(w->unk_0F4);
    w->unk_13D = 1;
    w->unk_118 = 0x8500;
    w->unk_11C = 0x5000;
#ifdef VERSION_EU
    ((u8*)&w->unk_13E)[1] = func_08065B6C(eu_0805E924(gUnkEu_08890E1C), w->unk_020);
    w->unk_140 = func_08065B6C(eu_0805E924(gUnkEu_08890E44), w->unk_070);
#else
    ((u8*)&w->unk_13E)[1] = func_08065B6C(gUnk_08159E10, w->unk_020);
    w->unk_140 = func_08065B6C(gUnk_08159E18, w->unk_070);
#endif
    w->unk_0C0 = (s32)_08066468(1);
    w->unk_144 = 1;
    w->unk_010 = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
    w->unk_014 = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_EU
    func_080062F4(((UnkStruct_080038C8*)w->unk_014)->unk_06 + 16, 1);
#else
    func_080062F4(w->unk_01C->unk_06 + 16, 1);
#endif
    SetTaskUpdate(a, (void*)func_080A5198);
    return 1;
}
s32 func_080A5150(UnkStruct_080A3F5C* w) {
    if (w->unk_000 != 0) {
        *(void**)&w->unk_128 = AnimUpdate(w->unk_0DC);
    }

    ((s16*)&w->unk_134)[1] += 1;

    if (((s16*)&w->unk_134)[1] > 15) {
        ((u8*)w)[0x141] = 0;
        return 0;
    }

    return 1;
}
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a) {
    s32 tbl[2];

    *(u64*)tbl = *(u64*)gUnk_09041E9C;
    w->unk_12C = AnimUpdate(w->unk_0F4);

    switch (GetKeysPressed()) {
    case 0x20:
        if (w->unk_13D != 0) {
            w->unk_13D--;
            m4aSongNumStart(0x65);
        }

        ((u8*)&w->unk_13E)[0] = 1;
        break;
    case 0x10:
        if (w->unk_13D == 0) {
            w->unk_13D++;
            m4aSongNumStart(0x65);
        }

        ((u8*)&w->unk_13E)[0] = 1;
        break;
    }

    switch (GetKeysPressed()) {
    case 1:
    case 8:
        m4aSongNumStart(0x66);

        if (w->unk_13D == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        w->unk_142 = 0;
        SetTaskUpdate(a, (void*)func_080A5150);
        break;
    case 2:
        m4aSongNumStart(0x68);
        gUnk_0203A9D8 = 0;
        w->unk_142 = 0;
        SetTaskUpdate(a, (void*)func_080A5150);
        break;
    }

    if (((u8*)&w->unk_13E)[0] != 0) {
        ApproachValue(&w->unk_118, tbl[w->unk_13D], ((u8*)&w->unk_13E)[0]);
        ((u8*)&w->unk_13E)[0]--;
    }

    return 1;
}
void func_080A52BC(UnkStruct_080A3F5C* w) {
    func_0806C2C0(w->unk_138[1]);

    switch (w->unk_113) {
    case 2:
    case 3:
        if (w->unk_018 != 0) {
            DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, gUnk_09EF1278[0], w->unk_018, w->unk_01C, 0, 0, 20);
        }
        break;
    }

    if (w->unk_000 != 0 && w->unk_141 != 0) {
        DrawSprite(120, gUnk_09033D08[w->unk_114->unk_04][1] >> 8, w->unk_128, w->unk_000, w->unk_004, 0, 0, 10);
    }

    if (w->unk_008 != 0) {
        DrawSprite(w->unk_118 >> 8, w->unk_11C >> 8, w->unk_12C, w->unk_008, w->unk_00C, 0, 1, 10);
    }

    func_080664D8(89, 86, w->unk_020, w->unk_0C0, 0, ((u8*)&w->unk_13E)[1]);
    func_080664D8(135, 86, w->unk_070, w->unk_0C0, 0, w->unk_140);
}

void func_080A53E4(UnkStruct_080A3F5C* w) {
    if (w->unk_113 <= 1) {
        DisableBg(w->unk_10C);
    }

    func_0806C34C();

    if (w->unk_000 != 0) {
        ReleaseObjTiles(w->unk_000);
    }

    if (w->unk_004 != 0) {
        ReleaseObjPalette(w->unk_004);
    }

    if (w->unk_008 != 0) {
        ReleaseObjTiles(w->unk_008);
    }

    if (w->unk_00C != 0) {
        ReleaseObjPalette(w->unk_00C);
    }

    if (w->unk_010 != 0) {
        ReleaseObjTiles(w->unk_010);
    }

    if (w->unk_018 != 0) {
        ReleaseObjTiles(w->unk_018);
    }

    if (w->unk_01C != 0) {
        ReleaseObjPalette(w->unk_01C);
    }

    if (w->unk_014 != 0) {
        ReleaseObjPalette(w->unk_014);
    }

    if (w->unk_0C0 != 0) {
        ReleaseObjPalette((u8*)w->unk_0C0);
    }

    func_08065AE0((TextSlot*)w->unk_020, 10);
    func_08065AE0((TextSlot*)w->unk_070, 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034B00 = 0;
}

void WorldSel_Before_0(WorldSelBeforeWork* w, UnkStruct_080A5490_Args* a) {
    u8 i;

    func_08006238(0, 16, 8);
    *(UnkStruct_080A5490_Args*)&w->unk_10 = *a;
    w->unk_00 = LoadObjTiles(gUnk_093FB0CC, 0xC0);
    w->palette = LoadObjPalette(gUnk_09619378, 32);
    w->unk_08 = LoadObjTiles(gUnk_093FB1AC, 0x4A0);
    w->unk_0C = AllocObjPalette(32);
    w->unk_A2 = 6;
    w->unk_1C = 0;
    w->unk_1D = 0;
    w->unk_A3 = 0;
    func_08003A70(w->unk_0C, &gUnk_09619178[gUnk_09EE8E60[w->unk_1C].unk_00 << 5]);
    func_080062F4(((UnkStruct_080038C8*)w->palette)->unk_06 + 16, 1);
    func_080062F4(w->unk_0C->unk_06 + 16, 1);

    for (i = 0; i < w->unk_A2; i++) {
        w->unk_98[i] = 0x80;
        w->unk_70[i] = 0;
        w->unk_20[i] = gSineTable[w->unk_98[i]] * 24 + w->unk_10;
        w->unk_48[i] = -gSineTable[w->unk_98[i] + 64] * 12 + w->unk_14;
    }

    m4aSongNumStart(0xD4);
}
s32 WorldSel_Before_1(WorldSelBeforeWork* w) {
    u8 i;

    if (w->unk_A3 < w->unk_A2) {
        w->unk_70[w->unk_A3] -= (s32)(24.0f / (256.0f / (float)w->unk_A2 * 0.25f) * 256.0f);

        if (w->unk_70[w->unk_A3] <= -6144) {
            w->unk_A3++;
        }
    }

    for (i = 0; i < w->unk_A3; i++) {
        w->unk_20[i] = gSineTable[w->unk_98[i]] * 24 + w->unk_10;
        w->unk_48[i] = -gSineTable[w->unk_98[i] + 64] * 12 + w->unk_14;
        w->unk_98[i] += 4;
    }

    if (++w->unk_1D == gUnk_09EE8E60[w->unk_1C].unk_01) {
        do {
            w->unk_1C = w->unk_1C > 28 ? 0 : w->unk_1C + 1;
        } while (0);

        w->unk_1D = 0;
        func_08003A70(w->unk_0C, &gUnk_09619178[gUnk_09EE8E60[w->unk_1C].unk_00 << 5]);
    }

    return 1;
}
void WorldSel_Before_2(WorldSelBeforeWork* w) {
    u8 i;

    for (i = 0; i < w->unk_A2; i++) {
        DrawSprite((w->unk_20[i] >> 8) - (gUnk_02039BA0->unk_00 >> 8),
                   (w->unk_48[i] >> 8) + ((w->unk_18 + w->unk_70[i]) >> 8) - (gUnk_02039BA0->unk_04 >> 8),
                   (&gUnk_09EF1278[4])[0], w->unk_00, w->palette, 0, 0x800,
                   (u16)(-0x1004 - (w->unk_48[i] >> 8) * 4));
    }

    DrawSprite((w->unk_10 >> 8) - (gUnk_02039BA0->unk_00 >> 8) - 32,
               (w->unk_14 >> 8) + (w->unk_18 >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 16,
               (&gUnk_09EF1278[6])[0], w->unk_08, w->unk_0C, 0, 0x800,
               (u16)(-0x1004 - ((w->unk_14 - 512) >> 8) * 4));
}

void WorldSel_Before_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjTiles(p[2]);
    ReleaseObjPalette(p[1]);
    ReleaseObjPalette(p[3]);
}
void func_080A581C(u8* work) {
    TaskCreate(&work[0x10], gTaskDescWorldSelBefore, work);
}

void func_080A5830(void* a, s32 b, s32 c, s32 d) {
    s32 args[3];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    TaskCreate(a, gTaskDescWorldSelBefore, args);
}
#ifdef NON_MATCHING
void func_080A584C(u8* work, void* a) {
    *(void**)&work[0x4F4] = a;
    SetBgMode0();
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 0, 31, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(3, 0, 30, 0);
    func_0800443C(GetBgCharBase(0), 0x4000);
    func_0800443C(GetBgCharBase(1), 0x4000);
    func_0800443C(GetBgCharBase(2), 0x4000);
    func_0800443C(GetBgCharBase(3), 0x4000);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    func_08006120(0, 16);
    ListPoolInit(&work[0x434]);
    TaskPoolInit((TaskPool*)&work[0x40C], 99);
    TaskPoolInit((TaskPool*)&work[0x420], 1);
    work[0x4F8] = GetActiveDeckIndex();
    func_080A6838(work, 0);
    *(void**)&work[0] = AllocObjTiles(0x120, 0);
    func_08002A10(*(void**)&work[0], gUnk_090A4664);
    AnimInit((AnimState*)&work[0x444], gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)&work[0x444], 0, 1);
    *(void**)&work[0x400] = AnimGetGfx((AnimState*)&work[0x444]);
    *(s32*)&work[0x48C] = gUnk_09041EB4[0] << 8;
    *(s32*)&work[0x490] = gUnk_09041EBA[0] << 8;
    *(u16*)&work[0x4C6] = 0;
    *(void**)&work[0x10] = LoadObjTiles(gUnk_090A44C4, 32);
    *(void**)&work[0x14] = LoadObjPalette(gUnk_09614418, 32);
    work[0x50A] = 0;
    *(void**)&work[0x04] = AllocObjTiles(0x280, 0);
    func_080A7284(work, 0);
    *(void**)&work[0x3D8] = LoadObjPalette(gUnk_09614438, 32);
    *(s32*)&work[0x24] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0x20] = 0;
    *(s32*)&work[0x28] = 0;
    *(s32*)&work[0x2C] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x0C] = 0;
    *(u16*)&work[0x4C8] = 0;
    *(u16*)&work[0x4CA] = 0;
    work[0x4E8] = 0;
    work[0x4E9] = 0;
    work[0x4EC] = 4;
    work[0x500] = 0;
    *(s32*)&work[0x3DC] = 0;
    *(s32*)&work[0x3E0] = 0;
    work[0x4FF] = 0;
    work[0x4E6] = 0;
    work[0x4EF] = func_080857D4(0);
    work[0x4F0] = func_080857D4(1);
    work[0x4F1] = func_080857D4(2);
    work[0x4F2] = func_080857D4(3);
    work[0x4F9] = 0;
    *(u16*)&work[0x4DC] = 0;
    *(s32*)&work[0x3E8] = 0;
    work[0x501] = 0;
    work[0x504] = 0;
    work[0x505] = 16;
    work[0x506] = 16;
    *(s32*)&work[0x49C] = 0x7800;
    *(s32*)&work[0x4A4] = -0x800;
    *(s32*)&work[0x4A0] = 0xA400;
    *(s32*)&work[0x4A8] = 0xA000;
    *(s32*)&work[0x4AC] = -0x8000;
    work[0x508] = 0;
    *(void**)&work[0x3CC] = LoadObjTiles(gUnk_090A418E, 0x320);
    *(void**)&work[0x3C4] = LoadObjTiles(gUnk_090A583E, 0x620);
    *(void**)&work[0x3C8] = LoadObjPalette(gUnk_096144F8, 32);
    *(u16*)&work[0x4BC] = 79;
    *(u16*)&work[0x4BE] = gUnk_09041EEE[work[0x4F8]];
    *(u16*)&work[0x4C0] = 225;
    *(u16*)&work[0x4C2] = gUnk_09041EEE[work[0x4F8]];
    work[0x503] = 0;
    work[0x507] = 0;
    work[0x4FA] = 0;
    work[0x4FB] = 0;
    work[0x4FC] = 0;
    work[0x4FD] = 0;
    work[0x50C] = 0;
    func_08065ACC(&work[0x30], 8);
    func_08065ACC(&work[0x70], 8);
    func_08065ACC(&work[0xB0], 8);
    func_08065ACC(&work[0xF0], 30);
    func_08065ACC(&work[0x1E0], 60);
    *(u16*)&work[0x4D8] = 94;
    *(u16*)&work[0x4DA] = 126;
    work[0x50B] = 0;
}
#else
INCLUDE_ASM("card/func_080A584C.s");
#endif
void func_080A5C20(u8* work) {
    func_080664D8(*(s16*)&work[0x4D8], *(s16*)&work[0x4DA], &work[0x1E0],
                  *(void**)&work[0x14], 20, work[0x4FE]);
}

void func_080A5C60(u8* work, u16 card) {
    CardDef* d;
    void* s;

    d = &gCardDefs[card];
    s = gUnk_09EE8F48[d->unk_1C];
    work[0x4FE] = func_08065B6C(LANGSTR(s), &work[0x1E0]);
}

u8 func_080A5C9C(u8* work, void* a) {
#ifdef VERSION_EU
    LoadBgTiles(3, gUnkEu_094DCCE4, 0x5400);

    switch (gLanguage) {
    case 1:
        RequestDma3Copy(gUnkEu_094E20E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    case 2:
        RequestDma3Copy(gUnkEu_094E74E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    case 3:
        RequestDma3Copy(gUnkEu_094E58E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    case 4:
        RequestDma3Copy(gUnkEu_094E3CE4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    }

    LoadBgPalette(3, gUnk_09614118, 0x1E0);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
#else
    LoadBgTiles(3, gUnk_09402F78, 0x4000);
    LoadBgPalette(3, gUnk_09614118, 0x1E0);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgTiles(1, gUnk_09406F78, 0xC00);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
#endif
    SetBgScroll(0, -88, -108);
    SetBgScroll(1, -88, -16);
    SetTaskUpdate(a, (void*)func_080A5D3C);
    return 1;
}

u8 func_080A5D3C(UnkStruct_080A5D3C* w, void* a) {
    u8* base;
    u16* pal;

    base = (u8*)GetBgCharBase(1);
    pal = (u16*)0x05000100;
    LoadPalette(gUnk_09614118 + 0x1E0, pal, 32);
#ifdef VERSION_EU
    RequestDma3Copy(gUnkEu_09F74374[gLanguage] + 0x20, base + 0x2D80, 0x1E0);
    LoadBgMap(0, gUnkEu_09534324, 0x800);
    LoadBgMap(1, gUnk_09516AB8, 0x800);
#else
    RequestDma3Copy(gUnk_0940FC58, base + 0x1A0, 0x1E0);
    LoadBgMap(0, gUnk_09516AB8 + 0x800, 0x800);
    LoadBgMap(1, gUnk_0951B2B8 + 0x800, 0x800);
#endif
    func_080A6B40(w->unk_4EF, 0);
    func_080A6B40(w->unk_4F0, 1);
    func_080A6B40(w->unk_4F1, 2);
    func_080A6B40(w->unk_4F2, 3);
    func_080A6C50(0);
    func_080A6D0C();
    w->unk_494 = 0x4800;
    w->unk_498 = 0x2800;
    w->unk_4C8[1] = w->unk_4F8;
#ifdef VERSION_EU
    ApproachValue(&w->unk_48C, gUnkEu_090D1DFE[w->unk_4C8[0]] << 8, w->unk_4EC);
    ApproachValue(&w->unk_490, gUnkEu_090D1E04[w->unk_4C8[1]] << 8, w->unk_4EC);
#else
    ApproachValue(&w->unk_48C, gUnk_09041EB4[w->unk_4C8[0]] << 8, w->unk_4EC);
    ApproachValue(&w->unk_490, gUnk_09041EBA[w->unk_4C8[1]] << 8, w->unk_4EC);
#endif
    w->unk_4E6 = 1;
    func_080A6BB4((u8*)w);
    func_080A6E3C((u8*)w);
    w->unk_509 = 0;
    w->unk_4EC = 16;
    SetTaskUpdate(a, func_080A5EA0);
    return 1;
}

u8 func_080A5EA0(UnkStruct_080A5D3C* w, void* a) {
    u8 n;

    if (func_08006314() == 0) {
        switch (w->unk_509) {
        case 0:
            ApproachValue(&w->unk_4A4, 0, w->unk_4EC);
            ApproachValue(&w->unk_4A8, 0x9800, w->unk_4EC);
            w->unk_4EC--;

            if (w->unk_4EC == 0) {
                w->unk_4EC = 16;
                w->unk_509++;
            }
            break;
        case 1:
            ApproachValue(&w->unk_4AC, 0, w->unk_4EC);
            n = --w->unk_4EC;

            if (n == 0) {
                LoadBgMap(3, gUnk_095162B8, 0x800);
                ReleaseObjTiles(w->unk_3CC);
                w->unk_3CC = 0;
                ReleaseObjTiles(w->unk_3C4);
                w->unk_3C4 = 0;
                ReleaseObjPalette(w->unk_3C8);
                w->unk_3C8 = 0;
                SetTaskUpdate(a, (void*)func_080A5F70);
            }
            break;
        }
    }

    return 1;
}

u8 func_080A5F70(u8* work, void* a) {
    *(s32*)&work[0x48C] = gUnk_09035950[*(s16*)&work[0x4C8]] << 8;
    *(s32*)&work[0x490] = gUnk_09035956[*(s16*)&work[0x4CA]] << 8;
    work[0x4E6] = 0;
    func_080A6BB4(work);
    func_080A6FAC((UnkStruct_080A6FAC*)work);
    work[0x50A] = 1;
    SetTaskUpdate(a, (void*)func_080A5FF4);
    return 1;
}

#ifdef NON_MATCHING
u8 func_080A5FF4(u8* work, void* a) {
    *(void**)&work[0x400] = AnimUpdate((AnimState*)&work[0x444]);
    *(void**)&work[0x404] = AnimUpdate((AnimState*)&work[0x45C]);

    if (func_08006314() != 0) {
        TaskPoolUpdate((TaskPool*)&work[0x40C]);
        return 1;
    }

    if (work[0x501] != 0) {
        ApproachValue((s32*)&work[0x48C], gUnk_09035950[*(s16*)&work[0x4C8]] << 8, work[0x4EC]);
        ApproachValue((s32*)&work[0x490], gUnk_09035956[*(s16*)&work[0x4CA]] << 8, work[0x4EC]);

        if (work[0x4EC] != 0) {
            work[0x4EC]--;
        }

        TaskPoolUpdate((TaskPool*)&work[0x40C]);
        TaskPoolUpdate((TaskPool*)&work[0x420]);

        if (GetKeysPressed() & 8) {
            work[0x504] = 1;
        }
        work[0x507] = 4;
        return 1;
    }

    if (*(s8*)&work[0x507] > 0) {
        TaskPoolUpdate((TaskPool*)&work[0x40C]);
        TaskPoolUpdate((TaskPool*)&work[0x420]);
        work[0x507]--;
        return 1;
    }

    if (work[0x504] != 0) {
        if (func_080A7300(work) != 0 && func_080A734C(work) != 0) {
            SetTaskUpdate(a, (void*)func_080A6388);
            func_08006184(0, 4);
            m4aSongNumStart(103);
            return 1;
        }
        work[0x504] = 0;
    }

    switch (GetKeysRepeat()) {
    case 64:
        if (*(s16*)&work[0x4CA] > 0) {
            (*(s16*)&work[0x4CA])--;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        } else {
            func_080A6A38(work);
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case 128:
        if (*(s16*)&work[0x4CA] <= 2) {
            (*(s16*)&work[0x4CA])++;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        } else {
            func_080A69A0(work);

            if (work[0x508] != 0) {
                if (*(u16*)&work[0x4BA] <= 3) {
                    *(s32*)&work[0x4B4] = gUnk_09035956[*(s16*)&work[0x4BA]] << 8;
                } else {
                    *(s32*)&work[0x4B4] = 0xFFFF0000;
                }
            }
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case 32:
        if (*(s16*)&work[0x4C8] > 0) {
            (*(s16*)&work[0x4C8])--;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case 16:
        if (*(s16*)&work[0x4C8] <= 1) {
            (*(s16*)&work[0x4C8])++;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case 8:
        work[0x50C] = 7;
        m4aSongNumStart(103);
        func_08006184(0, 4);
        SetTaskUpdate(a, (void*)func_080A6388);
        return 1;
    case 2:
        work[0x50C] = 8;
        m4aSongNumStart(103);
        SetTaskUpdate(a, (void*)func_080A63B8);
        return 1;
    }

    *(s32*)&work[0x3DC] = (s32)func_080A6AE8(work);
    ApproachValue((s32*)&work[0x48C], gUnk_09035950[*(s16*)&work[0x4C8]] << 8, work[0x4EC]);
    ApproachValue((s32*)&work[0x490], gUnk_09035956[*(s16*)&work[0x4CA]] << 8, work[0x4EC]);

    if (work[0x4EC] != 0) {
        work[0x4EC]--;
    }

    *(s32*)&work[0x3E0] = *(s32*)&work[0x3DC];
    work[0x4E8] = *(u16*)&work[0x4C8];
    work[0x4E9] = *(u16*)&work[0x4CA];
    TaskPoolUpdate((TaskPool*)&work[0x40C]);
    TaskPoolUpdate((TaskPool*)&work[0x420]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A5FF4.s");
#endif
s32 func_080A6388(u8* work) {
    if (func_08006314() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x40C]);
    TaskPoolUpdate(&work[0x420]);
    return 1;
}

u8 func_080A63B8(u8* work, void* a) {
#ifdef VERSION_EU
    *(void**)&work[0x3CC] = LoadObjTiles(gUnkEu_09F7434C[gLanguage], gUnkEu_090D1DF4[gLanguage]);
#else
    *(void**)&work[0x3CC] = LoadObjTiles(gUnk_090A418E, 0x320);
#endif
    *(void**)&work[0x3C4] = LoadObjTiles(gUnk_090A583E, 0x620);
    *(void**)&work[0x3C8] = LoadObjPalette(gUnk_096144F8, 32);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    *(s32*)&work[0x49C] = 0x7800;
    *(s32*)&work[0x4A4] = 0;
    *(s32*)&work[0x4A0] = 0xA400;
    *(s32*)&work[0x4A8] = 0x9800;
    *(s32*)&work[0x4AC] = 0;
    work[0x505] = 16;
    work[0x506] = 16;
    work[0x50A] = 0;
    SetTaskUpdate(a, (void*)func_080A6474);
    return 1;
}

u8 func_080A6474(u8* work, void* a) {
    u8* p;

    p = &work[0x506];

    if ((s8)*p > 0) {
        ApproachValue(&work[0x4AC], -0x8000, (u16)(s8)*p);
        (*p)--;
    } else {
        p = &work[0x505];

        if ((s8)*p > 0) {
            ApproachValue(&work[0x4A4], -0x800, (u16)(s8)*p);
            ApproachValue(&work[0x4A8], 0xA000, (u16)(s8)*p);
            (*p)--;
        } else {
            func_08006184(0, 4);
            SetTaskUpdate(a, (void*)func_080A6388);
        }
    }

    return 1;
}

void func_080A6500(u8* work) {
    if (*(void**)&work[0x3CC] != 0) {
#ifdef VERSION_EU
        DrawSprite(*(s32*)&work[0x4AC] >> 8, 0, gUnkEu_09F74360[gLanguage][0], *(void**)&work[0x3CC], *(void**)&work[0x3C8], 0, 0, 10);
#else
        DrawSprite(*(s32*)&work[0x4AC] >> 8, 0, gUnk_09EEAFF8, *(void**)&work[0x3CC], *(void**)&work[0x3C8], 0, 0, 10);
#endif
    }

    if (*(void**)&work[0x3C4] != 0) {
        DrawSprite(*(s32*)&work[0x49C] >> 8, *(s32*)&work[0x4A4] >> 8, gUnk_09EEB080[0], *(void**)&work[0x3C4],
                   *(void**)&work[0x3C8], 0, 0xC00, 10000);
        DrawSprite(*(s32*)&work[0x4A0] >> 8, *(s32*)&work[0x4A8] >> 8, gUnk_09EEB080[1], *(void**)&work[0x3C4],
                   *(void**)&work[0x3C8], 0, 0xC00, 10000);
    }

    if (work[0x50A] != 0) {
        DrawSprite((*(s32*)&work[0x48C] >> 8) - 16, (*(s32*)&work[0x490] >> 8) - 30, *(void**)&work[0x400],
                   *(void**)&work[0x0], *(void**)&work[0x14], 0, *(u16*)&work[0x4C6], 3);
        DrawSprite((*(s32*)&work[0x48C] >> 8) - 16, (*(s32*)&work[0x490] >> 8) - 20, *(void**)&work[0x404],
                   *(void**)&work[0x4], *(void**)&work[0x3D8], 0, 0, 8);
    }

    DrawSprite(*(s32*)&work[0x494] >> 8, *(s32*)&work[0x498] >> 8, gUnk_09EEB000, *(void**)&work[0x10],
               *(void**)&work[0x14], 0, 0x800, 10);

    if (*(void**)&work[0x18] != 0) {
        DrawSprite(168, 86, *(void**)&work[0x3EC], *(void**)&work[0x18], *(void**)&work[0x28], 0, 0, 20);
    }

    if (*(void**)&work[0x1C] != 0) {
        DrawSprite(168, 86, *(void**)&work[0x3F0], *(void**)&work[0x1C], *(void**)&work[0x2C], 0, 0, 21);
    }

    if (*(void**)&work[0x20] != 0) {
        DrawSprite(168, 86, *(void**)&work[0x3F4], *(void**)&work[0x20], *(void**)&work[0x28], 0, 0, 19);
    }

    if (work[0x50B] != 0) {
        if (work[0x4FD] != 0) {
            func_080664D8(100, 112, &work[0xF0], *(void**)&work[0x3D8], 20, work[0x4FD]);
        }

        func_080A5C20(work);
    }

    TaskPoolDraw(&work[0x40C]);
    TaskPoolDraw(&work[0x420]);
}

void func_080A676C(u8* work) {
    func_080A6968(work);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x14]);
    func_080A7264((void**)work);

    if (*(void**)&work[0x3CC] != 0) {
        ReleaseObjTiles(*(void**)&work[0x3CC]);
    }

    if (*(void**)&work[0x3C4] != 0) {
        ReleaseObjTiles(*(void**)&work[0x3C4]);
    }

    if (*(void**)&work[0x3C8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x3C8]);
    }

    func_08065AE0(&work[0x30], 8);
    func_08065AE0(&work[0x70], 8);
    func_08065AE0(&work[0xB0], 8);
    func_08065AE0(&work[0xF0], 30);
    func_08065AE0(&work[0x1E0], 60);
    ReleaseObjPalette(*(void**)&work[0x3D8]);
    TaskPoolDestroy(&work[0x40C]);
    TaskPoolDestroy(&work[0x420]);
    func_080A7210(work);
    **(u8**)&work[0x4F4] = work[0x50C];
}

void func_080A6838(UnkStruct_080A5D3C* w, u8 kind) {
    UnkStruct_080A6838_Args args;
    u16* cards;
    u8 i;
    s8 x;
    s8 y;

    cards = GetDeck(w->unk_4F8)->cards;
    x = 0;
    y = 0;
    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (kind == 0) {
                args.unk_00 = w->unk_434;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->unk_40C, gUnk_09EE4B28, &args);
                x++;
            } else if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == kind - 1) {
                args.unk_00 = w->unk_434;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->unk_40C, gUnk_09EE4B28, &args);
                x++;
            }
            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }
    w->unk_494 = 0x4800;
    w->unk_498 = 0x2800;
    w->unk_4ED[1] = 4;
}
void func_080A6968(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        node->unk_4A = 1;
        node = ListPoolNext(&node->unk_2C);
    }

    TaskPoolUpdate(&work[0x40C]);
}

void func_080A69A0(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    if ((s8)work[0x4EE] == 33) {
        return;
    }

    while (node != 0) {
        node->unk_24--;

        if (node->unk_24 < 0) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    }

    m4aSongNumStart(0x79);
    work[0x4EE]++;
    *(s32*)&work[0x498] += 0x300;

    if (*(s32*)&work[0x498] > 0x7C00) {
        *(s32*)&work[0x498] = 0x7C00;
    }

    if (work[0x508] != 0) {
        (*(u16*)&work[0x4BA])--;
    }
}

u8 func_080A6A38(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    if (node == 0) {
        *(s32*)&work[0x498] -= 0x300;

        if (*(s32*)&work[0x498] < 0x2800) {
            *(s32*)&work[0x498] = 0x2800;
            return 0;
        }

        return 1;
    }

    if (node->unk_24 == 0) {
        return 0;
    }

    do {
        node->unk_24++;

        if (node->unk_24 > 3) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    } while (node != 0);

    m4aSongNumStart(0x79);
    work[0x4EE]--;
    *(s32*)&work[0x498] -= 0x300;

    if (*(s32*)&work[0x498] < 0x2800) {
        *(s32*)&work[0x498] = 0x2800;
    }

    return 1;
}

UnkStruct_0808E890* func_080A6AE8(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        if (*(s16*)&work[0x4C8] == node->unk_22 &&
            *(s16*)&work[0x4CA] == node->unk_24) {
            return node;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

void func_080A6B40(u8 a, u8 b) {
    u8 d[2];
    u8* base;

    d[0] = a / 10;
    d[1] = a - (u8)(a / 10) * 10;
    base = (u8*)GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F7B8[(d[0] + 1) * 32], base + (b * 64 + 0x360), 32);
    RequestDma3Copy(&gUnk_0940F7B8[(d[1] + 1) * 32], base + (b * 64 + 0x360) + 32, 32);
}

void func_080A6BB4(u8* work) {
    u16 t;

    switch (work[0x4E6]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        AnimStart(&work[0x444], 0, 1);
        *(u16*)&work[0x4C6] &= ~1;
        break;
    case 1:
    case 3:
        AnimStart(&work[0x444], 2, 1);
        t = *(u16*)&work[0x4C6] | 1;
        *(u16*)&work[0x4C6] = t;
        break;
    }
}

void func_080A6C50(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = func_08085B38(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
        base = GetBgCharBase(1);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(1);
        break;
    }

#ifdef VERSION_EU
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x2C00, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x2C20, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x2C40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x2C60, 32);
#else
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
#endif
}

void func_080A6D0C(void) {
    u8 d[3];
    u8 e[3];
    u16 a;
    u16 b;
    u32 base;

    a = func_08084BF0();
    b = func_08084BAC();
    d[0] = a / 100;
    d[1] = a / 10 - d[0] * 10;
    d[2] = a - d[0] * 100 - d[1] * 10;
    e[0] = b / 100;
    e[1] = b / 10 - e[0] * 10;
    e[2] = b - e[0] * 100 - e[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_080A6E3C(u8* work) {
    func_08065AE0(&work[0x30], 8);
    func_08065AE0(&work[0x70], 8);
    func_08065AE0(&work[0xB0], 8);
    work[0x4FA] = func_08065B6C(func_080857BC(0), &work[0x30]);
    work[0x4FB] = func_08065B6C(func_080857BC(1), &work[0x70]);
    work[0x4FC] = func_08065B6C(func_080857BC(2), &work[0xB0]);
}

void func_080A6EB4(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
#ifdef VERSION_EU
    work[0x4FD] = func_08065B6C(eu_0805E924(def->unk_0C), &work[0xF0]);
#else
    work[0x4FD] = func_08065B6C(def->unk_0C, &work[0xF0]);
#endif

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->unk_08 << 5));
        break;
    }
}

void func_080A6F60(void** p) {
    if (p[9] != 0) {
        ReleaseObjTiles(p[9]);
        p[9] = 0;
    }

    if (p[6] != 0) {
        ReleaseObjTiles(p[6]);
        ReleaseObjPalette(p[10]);
        ReleaseObjTiles(p[7]);
        ReleaseObjPalette(p[11]);

        if (p[8] != 0) {
            ReleaseObjTiles(p[8]);
            p[8] = 0;
        }

        p[6] = 0;
        p[10] = 0;
        p[7] = 0;
        p[11] = 0;
    }
}

void func_080A6FAC(UnkStruct_080A6FAC* w) {
    UnkStruct_0808E890* node;
    CardDef* def;
    void* dst;
    u16 id;
    u32 t;

    id = 0xFFFF;
    node = ListPoolFirst(w->unk_434);

    while (node != 0) {
        if (node->unk_24 == w->unk_4CA && node->unk_22 == w->unk_4C8) {
            id = node->unk_20;
            break;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    func_080A6F60((void**)w);

    if (id != 0xFFFF) {
        if (id & 0x8000) {
            w->unk_024 = AllocObjTiles(0x280, 0);
            func_08002A10(w->unk_024, gUnk_0908B1B4);
            AnimInit(&w->anim, gUnk_09EEA164, gUnk_09EEA148);
            AnimStart(&w->anim, 0, 1);
            w->gfx = AnimGetGfx(&w->anim);
        }

        t = id & CARD_ID_MASK;
        def = &gCardDefs[t];
        w->unk_018 = LoadObjTiles(gUnk_08F709B0[def->unk_2A].unk_0C, 768);
        w->unk_01C = LoadObjTiles(def->unk_04, 512);
        w->unk_02C = LoadObjPalette(def->unk_08, 32);
        w->unk_028 = LoadObjPalette(gUnk_09611AB8, 32);
        w->unk_3EC = gUnk_08F709B0[def->unk_2A].unk_00;
        w->unk_3F0 = def->unk_00;

        if (def->unk_2A != 3) {
            w->unk_020 = LoadObjTiles(gUnk_0905EAE8, 480);
            w->unk_3F4 = gUnk_09EE981C[def->unk_20];
        }

        func_080A7180(def->unk_2C);
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614118[def->unk_2A * 32 + 0x200], dst, 32);
        func_080A6EB4((u8*)w, t);
        func_080A5C60((u8*)w, t);
        w->unk_50B = 1;
    } else {
        func_080A7180(0);
        w->unk_50B = 0;
    }
}

void func_080A7180(u8 a) {
    u8 v[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        v[0] = a / 10;
        v[1] = a - v[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(v[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(v[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}
void func_080A7210(u8* work) {
    void** p;
    u16 i;

    if (*(void**)&work[0x3E8] != 0) {
        for (i = 0; i < *(u16*)&work[0x4DC]; i++) {
            EwramFree(((UnkStruct_0808E2F0*)*(void**)&work[0x3E8])[i].unk_1C);
        }

        p = (void**)&work[0x3E8];
        EwramFree(*p);
        *p = 0;
    }
}
void func_080A7264(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}
void func_080A7284(u8* work, u8 mode) {
    switch (mode) {
    case 0:
        func_08002A10(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x45C], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x45C], 0, 1);
        *(void**)&work[0x404] = AnimGetGfx(&work[0x45C]);
        break;
    case 1:
        func_08002A10(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x45C], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x45C], 0, 1);
        *(void**)&work[0x404] = AnimGetGfx(&work[0x45C]);
        break;
    }
}
u8 func_080A7300(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gGameState.cp) {
        TaskCreate(&work[0x420], gUnk_09EE7FA8, &work[0x501]);
        m4aSongNumStart(0x69);
        return 0;
    }

    return 1;
}
u8 func_080A734C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(0x69);
        TaskCreate(&work[0x420], gUnk_09EE7FC0, &work[0x501]);
        return 0;
    }

    return 1;
}
u8 func_080A7388(u8* work, s16 x, s16 y, u16 dir) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    switch (dir) {
    case 64:
        return func_080A7388(work, x, y - 1, 64);
    case 128:
        return func_080A7388(work, x, y + 1, 128);
    case 32:
        return func_080A7388(work, x - 1, y, 32);
    case 16:
        return func_080A7388(work, x + 1, y, 16);
    }

    return 0;
}
#ifndef VERSION_EU
void deckexchange_0(u8* work, void* a) {
    s32 zero;
    u16 n;

    zero = 0;
    CpuSet((void*)&zero, work, 0x050001C6);
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0x10] = 0;
    *(s32*)&work[0x14] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x20] = 0;
    *(s32*)&work[0x24] = 0;
    *(s32*)&work[0x4A8] = 0;
    *(s32*)&work[0x4B4] = 0;
    *(s32*)&work[0x4B8] = 0;
    *(s32*)&work[0x4BC] = 0;
    *(s32*)&work[0x4C0] = 0;
    *(s32*)&work[0x4C4] = 0;
    *(s32*)&work[0x4CC] = 0;
    *(void**)&work[0x6FC] = a;
    SetBgMode0();
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 3, 31, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(3, 0, 30, 0);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    func_08006120(0, 16);
    ListPoolInit(&work[0x63C]);
    TaskPoolInit((TaskPool*)&work[0x614], 99);
    TaskPoolInit((TaskPool*)&work[0x628], 1);
    work[0x700] = GetActiveDeckIndex();
    func_080A968C(work, 0);
    *(void**)&work[0x00] = AllocObjTiles(0x120, 0);
    func_08002A10(*(void**)&work[0x00], gUnk_090A4664);
    AnimInit((AnimState*)&work[0x64C], gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)&work[0x64C], 0, 1);
    *(void**)&work[0x4E8] = AnimGetGfx((AnimState*)&work[0x64C]);
    *(s32*)&work[0x694] = gUnk_09041F04[0] << 8;
    *(s32*)&work[0x698] = gUnk_09041F0A[0] << 8;
    *(u16*)&work[0x6CE] = 0;
    *(void**)&work[0x08] = LoadObjTiles(gUnk_090A44C4, 32);
    *(void**)&work[0x0C] = LoadObjPalette(gUnk_09614418, 32);
    *(void**)&work[0x04] = AllocObjTiles(0x280, 0);
    func_080AAA8C(work, 0);
    *(void**)&work[0x4BC] = LoadObjPalette(gUnk_09614438, 32);
    work[0x715] = 0;
    *(u16*)&work[0x6D0] = 0;
    *(u16*)&work[0x6D2] = 0;
    work[0x6F2] = 0;
    work[0x6F3] = 0;
    work[0x6F6] = 4;
    work[0x707] = 0;
    work[0x706] = 0;
    work[0x6F0] = 0;
    work[0x6F7] = func_080857D4(0);
    work[0x6F8] = func_080857D4(1);
    work[0x6F9] = func_080857D4(2);
    work[0x6FA] = func_080857D4(3);
    work[0x701] = 0;
    *(u16*)&work[0x6E0] = 0;
    work[0x70D] = 0;
    work[0x710] = 0;
    work[0x711] = 16;
    work[0x712] = 16;
    *(s32*)&work[0x6A4] = 0;
    *(s32*)&work[0x6AC] = -0x800;
    *(s32*)&work[0x6A8] = 0;
    *(s32*)&work[0x6B0] = 0xA000;
    *(s32*)&work[0x6B4] = -0x8000;
    work[0x714] = 0;
    *(u16*)&work[0x708] = 8;
    *(u16*)&work[0x70A] = 113;
    work[0x70C] = 0;
    *(u16*)&work[0x6C4] = 79;
    n = gUnk_09041F3E[work[0x700]];
    *(u16*)&work[0x6C6] = n;
    *(u16*)&work[0x6C8] = 225;
    n = gUnk_09041F3E[work[0x700]];
    *(u16*)&work[0x6CA] = n;
    work[0x70F] = 0;
    work[0x713] = 0;
    work[0x702] = 0;
    work[0x703] = 0;
    work[0x704] = 0;
    work[0x705] = 0;
    func_08065ACC((TextSlot*)&work[0x28], 8);
    func_08065ACC((TextSlot*)&work[0x68], 8);
    func_08065ACC((TextSlot*)&work[0xA8], 8);
    func_08065ACC((TextSlot*)&work[0xE8], 30);
    func_08065ACC((TextSlot*)&work[0x1D8], 90);
}
u8 deckexchange_1(u8* work, void* a) {
    func_08006120(0, 16);

    switch (work[0x715]) {
    case 0:
        func_0800443C(GetBgCharBase(0), 0x1000);
        break;
    case 1:
        func_0800443C(GetBgCharBase(0) + 0x1000, 0x1000);
        break;
    case 2:
        func_0800443C(GetBgCharBase(0) + 0x2000, 0x1000);
        break;
    case 3:
        func_0800443C(GetBgCharBase(0) + 0x3000, 0x1000);
        break;
    case 4:
        func_0800443C(GetBgCharBase(1), 0x1000);
        break;
    case 5:
        func_0800443C(GetBgCharBase(1) + 0x1000, 0x1000);
        break;
    case 6:
        func_0800443C(GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 7:
        func_0800443C(GetBgCharBase(1) + 0x3000, 0x1000);
        break;
    case 8:
        func_0800443C(GetBgCharBase(2), 0x1000);
        break;
    case 9:
        func_0800443C(GetBgCharBase(2) + 0x1000, 0x1000);
        break;
    case 10:
        func_0800443C(GetBgCharBase(2) + 0x2000, 0x1000);
        break;
    case 11:
        func_0800443C(GetBgCharBase(2) + 0x3000, 0x1000);
        break;
    case 12:
        func_0800443C(GetBgCharBase(3), 0x1000);
        break;
    case 13:
        func_0800443C(GetBgCharBase(3) + 0x1000, 0x1000);
        break;
    case 14:
        func_0800443C(GetBgCharBase(3) + 0x2000, 0x1000);
        break;
    case 15:
        func_0800443C(GetBgCharBase(3) + 0x3000, 0x1000);
        work[0x715] = 0;
        SetTaskUpdate(a, (void*)func_080A7914);
        return 1;
    }

    work[0x715]++;
}
u8 func_080A7ABC(UnkStruct_0808C940* w, void* a);

u8 func_080A7914(u8* work, void* a) {
    func_08006120(0, 16);

    switch (work[0x715]) {
    case 0:
        LoadBgTiles(3, gUnk_09402F78, 0x2000);
        break;
    case 1:
        RequestDma3Copy(&gUnk_09402F78[0x2000],
                        (u8*)GetBgCharBase(3) + 0x2000, 0x2000);
        break;
    case 2:
        LoadBgPalette(3, gUnk_09614118, 0x1E0);
        break;
    case 3:
        LoadBgTiles(0, gUnk_09406F78, 0xC00);
        break;
    case 4:
        LoadBgMap(0, gUnk_08125E24, 0x800);
        break;
    case 5:
        LoadBgTiles(1, &gUnk_09406F78[0xC00], 0x2000);
        break;
    case 6:
        RequestDma3Copy(&gUnk_09406F78[0x2C00],
                        (u8*)GetBgCharBase(1) + 0x2000, 0x1E20);
        break;
    case 7:
        LoadBgMap(1, gUnk_08125E24, 0x800);
        break;
    case 8:
        LoadBgTiles(2, &gUnk_09406F78[0x4A20], 0x2000);
        break;
    case 9:
        RequestDma3Copy(&gUnk_09406F78[0x6A20],
                        (u8*)GetBgCharBase(2) + 0x2000, 0x1E20);
        break;
    case 10:
        LoadBgMap(2, gUnk_08125E24, 0x800);
        break;
    case 12:
        work[0x715] = 0;
        SetTaskUpdate(a, (void*)func_080A7ABC);
        return 1;
    }

    work[0x715]++;
    SetBgScroll(0, -88, -16);
    SetBgScroll(1, -88, -64);
    SetBgScroll(2, -88, -112);
    return 1;
}
u8 func_080A7ABC(UnkStruct_0808C940* w, void* a) {
    s32 v;

    func_08006120(0, 16);

    switch (w->unk_715) {
    case 1:
        LoadBgMap(0, &gUnk_095192B8[0x800], 0x180);
        break;
    case 2:
        LoadBgMap(1, &gUnk_095192B8[0x1000], 0x180);
        break;
    case 3:
        LoadBgMap(2, &gUnk_095192B8[0x1800], 0x180);
        break;
    case 4:
        func_0808CBB4(w->unk_6F7, 0);
        break;
    case 5:
        func_0808CBB4(w->unk_6F8, 1);
        break;
    case 6:
        func_0808CBB4(w->unk_6F9, 2);
        break;
    case 7:
        func_0808CBB4(w->unk_6FA, 3);
        break;
    case 8:
        func_080A9B84(w, w->unk_700);
        break;
    case 9:
        func_080A9E40(0);
        func_080A9E40(1);
        func_080A9E40(2);
        break;
    case 10:
        func_080A9F08(GetActiveDeckIndex());
        func_080AA1F8();
        w->unk_69C = 0x4800;
        w->unk_6A0 = 0x2800;
        v = w->unk_700;
        w->unk_6D2 = v;
        ApproachValue(&w->unk_694, gUnk_09041F04[w->unk_6D0] << 8, w->unk_6F6);
        ApproachValue(&w->unk_698, gUnk_09041F0A[w->unk_6D2] << 8, w->unk_6F6);
        SetTaskUpdate(a, (void*)func_080A82E0);
        w->unk_6F0 = 1;
        func_080A9AE8((u8*)w);
        func_080AA328((u8*)w);
        break;
    }

    w->unk_715++;
    return 1;
}
#ifdef NON_MATCHING
u8 func_080A7C80(u8* work, void* a) {
    u8 n;

    if (work[0x70D] != 0) {
        TaskPoolUpdate((TaskPool*)&work[0x614]);
        TaskPoolUpdate((TaskPool*)&work[0x628]);

        if (GetKeysPressed() & 8) {
            work[0x710] = 1;
        }

        return 1;
    }

    if (work[0x710] != 0) {
        if ((u8)func_080AAC40(work) != 0 && (u8)func_080AAC8C(work) != 0) {
            SetTaskUpdate(a, (void*)func_080A8C20);
            func_08006184(0, 4);
            m4aSongNumStart(103);
            return 1;
        }

        work[0x710] = 0;
    }

    *(void**)&work[0x4E8] = AnimUpdate((AnimState*)&work[0x64C]);
    *(void**)&work[0x4EC] = AnimUpdate((AnimState*)&work[0x664]);

    switch (GetKeysRepeat()) {
    case 32:
        if (*(s16*)&work[0x6D0] > 0) {
            (*(s16*)&work[0x6D0])--;
            work[0x6F6] = 4;

            if ((u8)func_080AA77C(work, 32) != 0) {
                m4aSongNumStart(101);
            }
        }

        func_080AA680(work);
        break;
    case 16:
        if (*(s16*)&work[0x6D0] <= 0) {
            (*(s16*)&work[0x6D0])++;
            work[0x6F6] = 4;

            if ((u8)func_080AA77C(work, 16) != 0) {
                m4aSongNumStart(101);
            }
        }

        func_080AA680(work);
        break;
    case 64:
        n = work[0x6D2];

        if (*(s16*)&work[0x6D2] > 0) {
            (*(s16*)&work[0x6D2])--;
        }

        work[0x6F6] = 4;
        func_080AA77C(work, 64);

        if ((s8)n != *(s16*)&work[0x6D2]) {
            m4aSongNumStart(101);
        }

        func_080AA680(work);
        break;
    case 128:
        n = work[0x6D2];

        if (*(s16*)&work[0x6D2] <= 3) {
            (*(s16*)&work[0x6D2])++;
        }

        work[0x6F6] = 4;
        func_080AA77C(work, 128);

        if ((s8)n != *(s16*)&work[0x6D2]) {
            m4aSongNumStart(101);
        }

        func_080AA680(work);
        break;
    }

    switch (GetKeysPressed()) {
    case 2:
        func_080AAA8C(work, 0);
        n = work[0x6F4];
        *(s16*)&work[0x6D0] = (s8)n;
        n = work[0x6F5];
        *(s16*)&work[0x6D2] = (s8)n;
        *(s32*)&work[0x694] = gUnk_0903595E[*(s16*)&work[0x6D0]] << 8;
        *(s32*)&work[0x698] = gUnk_09035964[*(s16*)&work[0x6D2]] << 8;
        func_080AA450(work);
        work[0x6F0] = 9;
        SetTaskUpdate(a, (void*)func_080A86F4);
        return 1;
    case 1:
        if ((u8)func_080AAB08((UnkStruct_080AAB08*)work) == 0) {
            return 1;
        }

        func_080AA1F8();
        func_0808500C(3, (u16*)&work[0x6E2]);
        func_0808CC58(*(u16*)&work[0x6E2], 0);
        func_0808CC58(*(u16*)&work[0x6E4], 1);
        func_0808CC58(*(u16*)&work[0x6E6], 2);
        func_0808CC58(*(u16*)&work[0x6E8], 3);
        SetTaskUpdate(a, (void*)func_080A8BD8);
        func_080AA680(work);
        work[0x6F6] = 4;
        break;
    case 8:
        if ((u8)func_080AAC40(work) != 0 && (u8)func_080AAC8C(work) != 0) {
            SetTaskUpdate(a, (void*)func_080A8C20);
            func_08006184(0, 4);
            m4aSongNumStart(103);
        }

        return 1;
    }

    if (work[0x6F6] != 0) {
        ApproachValue((s32*)&work[0x694], gUnk_09041F30[*(s16*)&work[0x6D0]] << 8, work[0x6F6]);
        ApproachValue((s32*)&work[0x698], (gUnk_09041F34[*(s16*)&work[0x6D2]] - 16) << 8, work[0x6F6]);
        work[0x6F6]--;
    }

    TaskPoolUpdate((TaskPool*)&work[0x614]);
    TaskPoolUpdate((TaskPool*)&work[0x628]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A7C80.s");
#endif
INCLUDE_ASM("card/func_080A8020.s");
#ifdef NON_MATCHING
u8 func_080A82E0(u8* work, void* a) {
    func_08006120(0, 4);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 0, 15, 0);
    SetupBg(1, 0, 23, 0);
    SetupBg(0, 0, 31, 0);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    SetBgScroll(2, 0, 16);
    LoadBgMap(3, gUnk_09515AB8, 0x800);
    LoadBgMap(2, gUnk_095182B8, 0x800);
    LoadBgMap(1, gUnk_09514AB8, 0x800);
    DisableBg(0);
    func_0808500C(3, (u16*)&work[0x6E2]);
    func_0808CC58(*(u16*)&work[0x6E2], 0);
    func_0808CC58(*(u16*)&work[0x6E4], 1);
    func_0808CC58(*(u16*)&work[0x6E6], 2);
    func_0808CC58(*(u16*)&work[0x6E8], 3);
    work[0x6F0] = 9;
    func_080AAA8C(work, 0);
    func_080A9968(work);
    work[0x715] = 0;
    SetTaskUpdate(a, (void*)func_080A8430);
    *(u16*)&work[0x6C4] = 0xFFFE;
    *(u16*)&work[0x6C6] = 142;
    *(u16*)&work[0x6C8] = 142;
    *(u16*)&work[0x6CA] = 142;
    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}
#else
INCLUDE_ASM("card/func_080A82E0.s");
#endif
INCLUDE_ASM("card/func_080A8430.s");
INCLUDE_ASM("card/func_080A86F4.s");
u8 func_080A8BD8(u8* work, void* a) {
    func_08006184(0, 16);
    work[0x701] = 0;
    SetTaskUpdate(a, (void*)func_080A8C20);
    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}
u8 func_080A8C20(u8* work) {
    if (func_08006314() == 0) {
        func_080A9968(work);
        return 0;
    }

    TaskPoolUpdate(&work[0x614]);
    TaskPoolUpdate(&work[0x628]);
    return 1;
}

void func_080A8C58(UnkStruct_0808C940* w, u8 b) {
    if (b == 0) {
        switch (w->unk_700) {
        case 0:
            func_080664D8(w->unk_6D4, w->unk_6DA, w->unk_28, w->unk_0C, 20, w->unk_702);
            func_080664D8(w->unk_6D6, w->unk_6DC, w->unk_68, w->unk_4BC, 20, w->unk_703);
            func_080664D8(w->unk_6D8, w->unk_6DE, w->unk_A8, w->unk_4BC, 20, w->unk_704);
            break;
        case 1:
            func_080664D8(w->unk_6D4, w->unk_6DA, w->unk_28, w->unk_4BC, 20, w->unk_702);
            func_080664D8(w->unk_6D6, w->unk_6DC, w->unk_68, w->unk_0C, 20, w->unk_703);
            func_080664D8(w->unk_6D8, w->unk_6DE, w->unk_A8, w->unk_4BC, 20, w->unk_704);
            break;
        case 2:
            func_080664D8(w->unk_6D4, w->unk_6DA, w->unk_28, w->unk_4BC, 20, w->unk_702);
            func_080664D8(w->unk_6D6, w->unk_6DC, w->unk_68, w->unk_4BC, 20, w->unk_703);
            func_080664D8(w->unk_6D8, w->unk_6DE, w->unk_A8, w->unk_0C, 20, w->unk_704);
            break;
        }
    } else {
        switch (w->unk_700) {
        case 0:
            func_080664D8(w->unk_6D4, w->unk_6DA, w->unk_28, w->unk_0C, 20, w->unk_702);
            break;
        case 1:
            func_080664D8(w->unk_6D6, w->unk_6DC, w->unk_68, w->unk_0C, 20, w->unk_703);
            break;
        case 2:
            func_080664D8(w->unk_6D8, w->unk_6DE, w->unk_A8, w->unk_0C, 20, w->unk_704);
            break;
        }
    }
}

void func_080A8EE4(u8* work) {
    func_080664D8(*(s16*)&work[0x708], *(s16*)&work[0x70A], &work[0x1D8],
                  *(void**)&work[0x0C], 20, work[0x70C]);
}
INCLUDE_ASM("card/deckexchange_2.s");
void deckexchange_3(u8* work) {
    void** p;

    if (*(void**)&work[0x4A8] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4A8]);
    }

    if (*(void**)&work[0x4AC] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4AC]);
    }

    if (*(void**)&work[0x4B0] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4B0]);
    }

    if (*(void**)&work[0x4B4] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4B4]);
    }

    if (*(void**)&work[0x4B8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4B8]);
    }

    p = (void**)&work[0x4BC];

    if (*p != 0) {
        ReleaseObjPalette(*p);
    }

    func_080AA634((void**)work);
    ReleaseObjTiles(*(void**)&work[0]);
    ReleaseObjTiles(*(void**)&work[4]);
    ReleaseObjTiles(*(void**)&work[8]);
    ReleaseObjPalette(*(void**)&work[0xC]);
    func_08065AE0(&work[0x28], 8);
    func_08065AE0(&work[0x68], 8);
    func_08065AE0(&work[0xA8], 8);
    func_08065AE0(&work[0xE8], 30);
    func_08065AE0(&work[0x1D8], 90);
    ReleaseObjPalette(*p);
    TaskPoolDestroy(&work[0x614]);
    TaskPoolDestroy(&work[0x628]);
    func_080AAA38(work);
    **(u8**)&work[0x6FC] = 6;
}
void func_080A968C(UnkStruct_0808C940* w, u8 kind) {
    UnkStruct_080A6838_Args args;
    u16* cards;
    u8 i;
    s8 x;
    s8 y;

    cards = GetDeck(w->unk_700)->cards;
    x = 0;
    y = 0;
    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (kind == 0) {
                args.unk_00 = w->unk_63C;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->unk_614, gUnk_09EE4B28, &args);
                x++;
            } else if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == kind - 1) {
                args.unk_00 = w->unk_63C;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->unk_614, gUnk_09EE4B28, &args);
                x++;
            }
            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }
    w->unk_69C = 0x4800;
    w->unk_6A0 = 0x2800;
    w->unk_6EC = 4;
    func_080AAEEC(w, y * 3 + x);
}

s32 func_080A97D4(u8* work, u8 kind) {
    UnkStruct_080A97D4 args;
    u16 i;
    s8 x;
    s8 y;

    x = 0;
    y = 0;

    for (i = 0; i < *(u16*)&work[0x6E0]; i++) {
        if (kind == 5) {
            if (*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) <= 77) {
                args.unk_00 = &work[0x63C];
                args.unk_04 =
                    func_080A993C(*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20));
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 1;
                args.unk_0C = 0;
                TaskCreate(&work[0x614], gUnk_09EE4B28, &args);
                x++;
            }
        } else {
            args.unk_00 = &work[0x63C];
            args.unk_04 =
                func_080A993C(*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20));

            if (gCardDefs[args.unk_04].unk_2A == kind - 1 &&
                *(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) <= 77) {
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 1;
                args.unk_0C = 0;
                TaskCreate(&work[0x614], gUnk_09EE4B28, &args);
                x++;
            }
        }

        if (x > 2) {
            x = 0;
            y++;
        }
    }

    *(s32*)&work[0x69C] = 0xA000;
    *(s32*)&work[0x6A0] = 0x2800;
    *(s16*)&work[0x6EC] = 4;
    func_080AAEEC((UnkStruct_0808C940*)work, y * 3 + x);
}

s32 func_080A993C(s32 a) {
    u32 i;

    for (i = 0; i < 950; i++) {
        if (gCardDefs[i].unk_1C == a) {
            return i;
        }
    }
}

void func_080A9968(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        node->unk_4A = 1;
        node = ListPoolNext(&node->unk_2C);
    }

    TaskPoolUpdate(&work[0x614]);
}

void func_080A99A0(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    if (*(s16*)&work[0x6EC] == 33) {
        return;
    }

    while (node != 0) {
        node->unk_24--;

        if (node->unk_24 < 0) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    }

    m4aSongNumStart(0x79);
    (*(u16*)&work[0x6EC])++;
    *(s32*)&work[0x6A0] += 0x300;

    if (*(s32*)&work[0x6A0] > 0x7C00) {
        *(s32*)&work[0x6A0] = 0x7C00;
    }

    if (work[0x714] != 0) {
        (*(u16*)&work[0x6C2])--;
    }
}

u8 func_080A9A38(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    if (node == 0) {
        *(s32*)&work[0x6A0] -= 0x300;

        if (*(s32*)&work[0x6A0] < 0x2800) {
            *(s32*)&work[0x6A0] = 0x2800;
            return 0;
        }

        return 1;
    }

    if (node->unk_24 == 0) {
        return 0;
    }

    do {
        node->unk_24++;

        if (node->unk_24 > 3) {
            node->unk_44 = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->unk_2C);
    } while (node != 0);

    m4aSongNumStart(0x79);
    (*(u16*)&work[0x6EC])--;
    *(s32*)&work[0x6A0] -= 0x300;

    if (*(s32*)&work[0x6A0] < 0x2800) {
        *(s32*)&work[0x6A0] = 0x2800;
    }

    return 1;
}

void func_080A9AE8(u8* work) {
    u16 t;

    switch (work[0x6F0]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        AnimStart(&work[0x64C], 0, 1);
        *(u16*)&work[0x6CE] &= ~1;
        break;
    case 1:
    case 3:
        AnimStart(&work[0x64C], 2, 1);
        t = *(u16*)&work[0x6CE] | 1;
        *(u16*)&work[0x6CE] = t;
        break;
    }
}

void func_080A9B84(UnkStruct_0808C940* w, u8 b) {
    u16* pal;

    switch (b) {
    case 0:
        pal = (u16*)0x05000100;
        LoadPalette(gUnk_096142F8, pal, 32);
        pal = (u16*)0x05000120;
        LoadPalette(gUnk_09614118 + 0x120, pal, 32);
        pal = (u16*)0x05000140;
        LoadPalette(gUnk_09614118 + 0x140, pal, 32);
        LoadBgMap(0, gUnk_09519AB8 + 0x180, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, -76, -14);
        SetBgScroll(1, -88, -64);
        SetBgScroll(2, -88, -112);
        w->unk_6D4 = 100;
        w->unk_6DA = 25;
        w->unk_6D6 = 102;
        w->unk_6DC = 75;
        w->unk_6D8 = 102;
        w->unk_6DE = 122;
        break;
    case 1:
        pal = (u16*)0x05000120;
        LoadPalette(gUnk_096142F8, pal, 32);
        pal = (u16*)0x05000100;
        LoadPalette(gUnk_09614118 + 0x100, pal, 32);
        pal = (u16*)0x05000140;
        LoadPalette(gUnk_09614118 + 0x140, pal, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8 + 0x180, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, -88, -16);
        SetBgScroll(1, -76, -62);
        SetBgScroll(2, -88, -112);
        w->unk_6D4 = 102;
        w->unk_6DA = 27;
        w->unk_6D6 = 100;
        w->unk_6DC = 73;
        w->unk_6D8 = 102;
        w->unk_6DE = 122;
        break;
    case 2:
        pal = (u16*)0x05000140;
        LoadPalette(gUnk_096142F8, pal, 32);
        pal = (u16*)0x05000100;
        LoadPalette(gUnk_09614118 + 0x100, pal, 32);
        pal = (u16*)0x05000120;
        LoadPalette(gUnk_09614118 + 0x120, pal, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8 + 0x180, 0x180);
        SetBgScroll(0, -88, -16);
        SetBgScroll(1, -88, -64);
        SetBgScroll(2, -76, -110);
        w->unk_6D4 = 102;
        w->unk_6DA = 27;
        w->unk_6D6 = 102;
        w->unk_6DC = 75;
        w->unk_6D8 = 100;
        w->unk_6DE = 121;
        break;
    }
}

void func_080A9E40(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = func_08085B38(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
        base = GetBgCharBase(0);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(2);
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
}

void func_080A9F08(u8 mode) {
    u32 bg0;
    u32 bg1;
    u32 bg2;

    bg0 = GetBgCharBase(0);
    bg1 = GetBgCharBase(1);
    bg2 = GetBgCharBase(2);

    switch (mode) {
    case 0:
        RequestDma3Copy(gUnk_0940FC58, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 2:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    }
}
void func_080A9FF4(u8 kind) {
    u8 d[3];
    u8 e[3];
    u32 base;
    u16 n;
    u8* p;
    u8* ep;

    base = 0;
    n = func_08085770(kind);
    d[0] = n / 100;
    d[1] = n / 10 - d[0] * 10;
    d[2] = n - d[0] * 100 - d[1] * 10;
    ep = e;
    p = (u8*)&gGameState;
    ep[0] = *(s16*)(p + 0xFA) / 100;
    ep[1] = *(s16*)(p + 0xFA) / 10 - ep[0] * 10;
    ep[2] = *(s16*)(p + 0xFA) - ep[0] * 100 - ep[1] * 10;

    switch (kind) {
    case 0:
        base = GetBgCharBase(0);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(2);
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0xA0, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0xC0, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[2] + 1) * 32], (u8*)base + 0xE0, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x100, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x120, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[2] + 1) * 32], (u8*)base + 0x140, 32);
}

void func_080AA148(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0xA8;

    switch (kind) {
    case 5:
        RequestDma3Copy(gUnk_095152B8 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_095152CC + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_095152E0 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_09515338 + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_0951534C + slot * 256, dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + slot * 256, dst + 0x40, 20);
        break;
    }
}

void func_080AA1F8(void) {
    u8 d1[3];
    u8 d2[3];
    u16 a;
    u16 b;

    u32 base;

    a = func_08084BF0();
    b = func_08084BAC();

    d1[0] = a / 100;
    d1[1] = a / 10 - d1[0] * 10;
    d1[2] = a - d1[0] * 100 - d1[1] * 10;
    d2[0] = b / 100;
    d2[1] = b / 10 - d2[0] * 10;
    d2[2] = b - d2[0] * 100 - d2[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_080AA328(u8* work) {
    func_08065ACC(&work[0x28], 8);
    func_08065ACC(&work[0x68], 8);
    func_08065ACC(&work[0xA8], 8);
    work[0x702] = func_08065B6C(func_080857BC(0), &work[0x28]);
    work[0x703] = func_08065B6C(func_080857BC(1), &work[0x68]);
    work[0x704] = func_08065B6C(func_080857BC(2), &work[0xA8]);
}

void func_080AA3A0(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
    work[0x705] = func_08065B6C(def->unk_0C, &work[0xE8]);

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_06 * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4BC])->unk_08 << 5));
        break;
    }
}

void func_080AA450(u8* work) {
    UnkStruct_0808E890* node;
    CardDef* def;
    s32 id;
    u8 i;
    u8 j;
    void* dst;

    id = 0xFFFF;
    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_24 == *(s16*)&work[0x6D2] && node->unk_22 == *(s16*)&work[0x6D0]) {
            id = node->unk_20;
            break;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    func_080AA634((void**)work);

    if (id != 0xFFFF) {
        def = &gCardDefs[id & CARD_ID_MASK];
        *(void**)&work[0x10] = LoadObjTiles(gUnk_08F709B0[def->unk_2A].unk_0C, 0x300);
        *(void**)&work[0x14] = LoadObjTiles(def->unk_04, 0x200);
        *(void**)&work[0x24] = LoadObjPalette(def->unk_08, 32);
        *(void**)&work[0x20] = LoadObjPalette(gUnk_09611AB8, 32);
        *(void**)&work[0x4D4] = gUnk_08F709B0[def->unk_2A].unk_00;
        *(void**)&work[0x4D8] = def->unk_00;

        for (i = 0; i < *(u16*)&work[0x6E0]; i++) {
            if (*(u16*)(i * 32 + (u32)*(void**)&work[0x4CC] + 20) == def->unk_1C) {
                break;
            }
        }

        *(u16*)&work[0x6CC] = i;
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614118[def->unk_2A * 32 + 0x200], dst, 32);

        for (j = 0; j < 10; j++) {
            func_0808DD20((*(UnkStruct_0808E2F0**)&work[0x4CC])[i].unk_00[j], j);
        }

        func_080AA3A0(work, id);
        func_080AAEB0(work, id);

        if (def->unk_1C > 46) {
            LoadBgMap(2, gUnk_09518AB8, 0x800);
            func_080AA6D4(0);
        } else {
            LoadBgMap(2, gUnk_095182B8, 0x800);
            func_080AA6D4(0);
        }
    } else {
        for (j = 0; j < 10; j++) {
            func_0808DD20(0, j);
        }

        func_080AA6D4(0);
    }
}

void func_080AA634(void** p) {
    if (p[7] != 0) {
        ReleaseObjTiles(p[7]);
        p[7] = 0;
    }

    if (p[4] != 0) {
        ReleaseObjTiles(p[4]);
        ReleaseObjPalette(p[8]);
        ReleaseObjTiles(p[5]);
        ReleaseObjPalette(p[9]);

        if (p[6] != 0) {
            ReleaseObjTiles(p[6]);
            p[6] = 0;
        }

        p[4] = 0;
        p[8] = 0;
        p[5] = 0;
        p[9] = 0;
    }
}

void func_080AA680(u8* work) {
    func_080AA6D4(func_080609AC(
        func_080A993C(*(u16*)(*(u16*)&work[0x6CC] * 32 +
                              (u32)*(void**)&work[0x4CC] + 20)) +
        *(s16*)&work[0x6D0] * 5 + *(u16*)&work[0x6D2]));
}

void func_080AA6D4(u8 a) {
    u8 d[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        d[0] = a / 10;
        d[1] = a - d[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(d[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(d[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}

u32 func_080AA764(u16* data) {
    u32 sum;
    u16* p;
    s32 i;

    sum = 0;
    p = data;
    i = 9;

    do {
        sum += *p++;
    } while (--i >= 0);

    return sum;
}

#ifdef NON_MATCHING
s32 func_080AA77C(u8* work, u16 key) {
    u8* tbl;
    u8 idx;
    u8 r0;
    u8 c0;
    u16 row0;
    s32 sum;
    s32 i;
    s8 d;
    s8 n;
    s32 ofs;

    tbl = *(u8**)&work[0x4CC] + *(u16*)&work[0x6CC] * 32;
    idx = *(s16*)&work[0x6D0] * 5 + (u8)*(s16*)&work[0x6D2];
    row0 = *(s16*)&work[0x6D0];
    r0 = *(s16*)&work[0x6D0];
    c0 = *(s16*)&work[0x6D2];

    if (*(u16*)&tbl[idx * 2] != 0) {
        return 1;
    }

    switch (key) {
    case 0x40:
        do {
            *(s16*)&work[0x6D2] = (*(s16*)&work[0x6D2] > 0) ? *(s16*)&work[0x6D2] - 1 : 4;
            idx = *(s16*)&work[0x6D0] * 5 + (u8)*(s16*)&work[0x6D2];

            if (*(s16*)&work[0x6D0] == r0 && *(s16*)&work[0x6D2] == c0) {
                return 0;
            }
        } while (*(u16*)&tbl[ofs = idx * 2] == 0);
        break;
    case 0x80:
        do {
            *(s16*)&work[0x6D2] = (*(s16*)&work[0x6D2] > 3) ? 0 : *(s16*)&work[0x6D2] + 1;
            idx = *(s16*)&work[0x6D0] * 5 + (u8)*(s16*)&work[0x6D2];

            if (*(s16*)&work[0x6D0] == r0 && *(s16*)&work[0x6D2] == c0) {
                return 0;
            }
        } while (*(u16*)&tbl[ofs = idx * 2] == 0);
        break;
    case 0x20:
        if (*(u16*)&tbl[*(s16*)&work[0x6D2] * 2] != 0) {
            if ((s16)row0 > 0) {
                *(s16*)&work[0x6D0] = row0 - 1;
            }

            return 1;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += *(u16*)&tbl[i * 2];
        }

        if (sum == 0) {
            *(s16*)&work[0x6D0] = 1;
            return 0;
        }

        d = -1;
        n = (u8)*(s16*)&work[0x6D2] - 1;
        for (;;) {
            if (n < 0) {
                n = 0;
            }

            if (n > 4) {
                n = 4;
            }

            if (*(u16*)&tbl[n * 2] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d++;
                d = -d;
            }

            n = (u8)*(s16*)&work[0x6D2] + d;
        }

        *(s16*)&work[0x6D2] = n;
        break;
    case 0x10:
        if (*(u16*)&tbl[(*(s16*)&work[0x6D2] + 5) * 2] != 0) {
            if ((s16)row0 <= 0) {
                *(s16*)&work[0x6D0] = row0 + 1;
            }

            return 1;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += *(u16*)&tbl[(i + 5) * 2];
        }

        if (sum == 0) {
            *(s16*)&work[0x6D0] = 0;
            return 0;
        }

        d = -1;
        n = (u8)*(s16*)&work[0x6D2] - 1;
        for (;;) {
            if (n < 0) {
                n = 0;
            }

            if (n > 4) {
                n = 4;
            }

            if (*(u16*)&tbl[(n + 5) * 2] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d++;
                d = -d;
            }

            n = (u8)*(s16*)&work[0x6D2] + d;
        }

        *(s16*)&work[0x6D2] = n;
        break;
    case 0:
        do {
            if (*(s16*)&work[0x6D2] > 3) {
                *(s16*)&work[0x6D2] = 0;
            } else {
                *(s16*)&work[0x6D2] = *(s16*)&work[0x6D2] + 1;
            }

            idx = *(s16*)&work[0x6D0] * 5 + (u8)*(s16*)&work[0x6D2];

            if (*(s16*)&work[0x6D0] == r0 && *(s16*)&work[0x6D2] == c0) {
                if (*(s16*)&work[0x6D0] > 0) {
                    *(s16*)&work[0x6D0] = 0;
                } else {
                    *(s16*)&work[0x6D0] = *(s16*)&work[0x6D0] + 1;
                }

                if (func_080AA764((u16*)tbl) == 0) {
                    return 0;
                }
            }
        } while (*(u16*)&tbl[ofs = idx * 2] == 0);
        break;
    }

    return 1;
}
#else
INCLUDE_ASM("card/func_080AA77C.s");
#endif

void func_080AAA38(u8* work) {
    u16 i;

    if (*(void**)&work[0x4CC] != 0) {
        for (i = 0; i < *(u16*)&work[0x6E0]; i++) {
            EwramFree(*(void**)(*(u8**)&work[0x4CC] + i * 32 + 28));
        }

        EwramFree(*(void**)&work[0x4CC]);
        *(void**)&work[0x4CC] = 0;
    }
}

void func_080AAA8C(u8* work, u8 kind) {
    switch (kind) {
    case 0:
        func_08002A10(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x664], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x664], 0, 1);
        *(void**)&work[0x4EC] = AnimGetGfx(&work[0x664]);
        break;
    case 1:
        func_08002A10(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x664], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x664], 0, 1);
        *(void**)&work[0x4EC] = AnimGetGfx(&work[0x664]);
        break;
    }
}

s32 func_080AAB08(UnkStruct_080AAB08* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    s32 card;
    u16 id;
    CardDef* def;
    u16 kind;

    idx = w->unk_6D0 * 5 + w->unk_6D2;
    e = &w->unk_4CC[w->unk_6CC];
    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(0x69);
        return 1;
    }
    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];
        if (card != 0xFFFF) {
            id = gCardCollection[card] & CARD_ID_MASK;
            def = &gCardDefs[id];
            if (id > 0x1C1) {
                if (idx == 0) {
                    gUnk_0203A9DC = gCardCollection[card] & CARD_ID_MASK;
                    func_080850B0(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[0]--;
                    func_0808DD20(e->unk_00[0], 0);
                    m4aSongNumStart(0x66);
                    return 1;
                }
            } else {
                kind = def->unk_20;
                if (kind == idx) {
                    gUnk_0203A9DC = gCardCollection[card] & CARD_ID_MASK;
                    func_080850B0(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[kind]--;
                    func_0808DD20(e->unk_00[kind], kind);
                    m4aSongNumStart(0x66);
                    return 1;
                }
            }
        }
    }
    m4aSongNumStart(0x69);
    return 1;
}

s32 func_080AAC40(u8* work) {
    if (func_08085770(GetActiveDeckIndex()) > gGameState.cp) {
        TaskCreate(&work[0x628], gUnk_09EE7FA8, &work[0x70D]);
        m4aSongNumStart(105);

        return 0;
    }

    return 1;
}

u8 func_080AAC8C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(105);
        TaskCreate(&work[0x628], gUnk_09EE7FC0, &work[0x70D]);
        return 0;
    }

    return 1;
}

void func_080AACC8(u8* work) {
    UnkStruct_0808E890* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x63C]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    *(s32*)&work[0x6A0] = 0x2800;
    *(s16*)&work[0x6EC] = 4;
}

u8 func_080AAD2C(u8* work) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_22 == *(s16*)&work[0x6D0] &&
            node->unk_24 == *(s16*)&work[0x6D2]) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

u8 func_080AAD84(u8* work, u16 x, u16 y) {
    UnkStruct_0808E890* node;

    node = ListPoolFirst(&work[0x63C]);

    while (node != 0) {
        if (node->unk_22 == (s16)x && node->unk_24 == (s16)y) {
            return 1;
        }

        node = ListPoolNext(&node->unk_2C);
    }

    return 0;
}

u8 func_080AADD4(u8* work, s16 x, s16 y, u16 dir) {
    UnkStruct_0808E890* n;

    for (n = ListPoolFirst(&work[0x63C]); n != 0; n = ListPoolNext(n->unk_2C)) {
        if (n->unk_22 == x && n->unk_24 == y) {
            return 1;
        }
    }

    switch (dir) {
    case 0x40:
        return func_080AADD4(work, x, y - 1, 0x40);
    case 0x80:
        return func_080AADD4(work, x, y + 1, 0x80);
    case 0x20:
        return func_080AADD4(work, x - 1, y, 0x20);
    case 0x10:
        return func_080AADD4(work, x + 1, y, 0x10);
    }

    return 0;
}

void func_080AAEB0(u8* work, u16 index) {
    CardDef* d;

    d = &gCardDefs[index];
    work[0x70C] = func_08065B6C(gUnk_09EE8F48[d->unk_1C], &work[0x1D8]);
}

void func_080AAEEC(UnkStruct_0808C940* w, s16 n) {
    w->unk_6EE = n / 3;

    if (n % 3 != 0) {
        w->unk_6EE = n / 3 + 1;
    }
}

void func_080AAF20(u8* work) {
    s32 t;

    t = 0x5400 / (*(s16*)&work[0x6EE] - 4);
    *(s32*)&work[0x6A0] = t * (*(s16*)&work[0x6EC] - 4) + 0x2800;

    if (*(s32*)&work[0x6A0] > 0x7C00) {
        *(s32*)&work[0x6A0] = 0x7C00;
    }

    if (*(s32*)&work[0x6A0] < 0x2800) {
        *(s32*)&work[0x6A0] = 0x2800;
    }
}

void func_080AAF78(void) {
    gUnk_02034B1C = 0;
    gUnk_0203A9DC = 2048;
    TaskPoolInit(gUnk_02034B08, 1);
    TaskCreate(gUnk_02034B08, gTaskDescDeckexchange, &gUnk_02034B1C);
}
void func_080AAFB4(void) {
    if (gSystemFlags & 1) {
        func_080B31A0();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(gUnk_02034B08);
    TaskPoolDraw(gUnk_02034B08);

    if (gUnk_02034B1C == 6) {
        ModeRequest(&gModeSioChgCard, gUnk_0203A9DC);
    }
}
void func_080AB008(void) {
    TaskPoolDestroy(gUnk_02034B08);
}
#endif
void DarkPoint_0(UnkStruct_080AB018* w) {
    w->unk_00 = LoadObjTiles(gUnk_093FB6C4, 576);
    w->unk_0A = 8;
    w->unk_04 = -0x2000;
    func_0806BA0C(gBtlWork->unk_1C8, &w->unk_0B);
}
s32 DarkPoint_1(UnkStruct_080AB018* w) {
    func_0806BA0C(gBtlWork->unk_1C8, &w->unk_0B);

    if (w->unk_0A > 0) {
        ApproachValue(&w->unk_04, 0, (u16)w->unk_0A);
        w->unk_0A--;
    }

    return 1;
}
void DarkPoint_2(UnkStruct_080AB018* w) {
    DrawSprite(w->unk_04 >> 8, 27, gUnk_09EF1298[0], w->unk_00, gUnk_02039DD4->palette, 0, 0, 30);

    if (w->unk_0C != 0) {
        DrawSprite((w->unk_04 >> 8) + 11, 30, gUnk_09EF1298[w->unk_0C + 1], w->unk_00, gUnk_02039DD4->palette, 0, 0, 29);
        DrawSprite((w->unk_04 >> 8) + 17, 30, gUnk_09EF1298[w->unk_0D + 1], w->unk_00, gUnk_02039DD4->palette, 0, 0, 29);
        DrawSprite((w->unk_04 >> 8) + 23, 30, gUnk_09EF1298[w->unk_0E + 1], w->unk_00, gUnk_02039DD4->palette, 0, 0, 29);
    } else if (w->unk_0D != 0) {
        DrawSprite((w->unk_04 >> 8) + 15, 30, gUnk_09EF1298[w->unk_0D + 1], w->unk_00, gUnk_02039DD4->palette, 0, 0, 29);
        DrawSprite((w->unk_04 >> 8) + 21, 30, gUnk_09EF1298[w->unk_0E + 1], w->unk_00, gUnk_02039DD4->palette, 0, 0, 29);
    } else {
        DrawSprite((w->unk_04 >> 8) + 17, 30, gUnk_09EF1298[w->unk_0E + 1], w->unk_00, gUnk_02039DD4->palette, 0, 0, 29);
    }
}
void DarkPoint_3(void** p) {
    ReleaseObjTiles(p[0]);
}

void func_080AB1F8(u8 a, u16 b) {
    u8 saved;

    saved = GetActiveDeckIndex();
    SetActiveDeckIndex(a);
    func_08085290(b);
    SetActiveDeckIndex(saved);
}

#ifndef VERSION_EU
void func_080AB228(void) {
}
#else
INCLUDE_ASM("card/func_080AB228.s");
#endif

void func_080AB22C(u8 a) {
    func_080AB1F8(a, 0);
    func_080AB1F8(a, 1);
    func_080AB1F8(a, 2);
    func_080AB1F8(a, 3);
    func_080AB1F8(a, 4);
    func_080AB1F8(a, 5);
    func_080AB1F8(a, 6);
    func_080AB1F8(a, 7);
    func_080AB1F8(a, 8);
    func_080AB1F8(a, 9);
    func_080AB1F8(a, 73);
    func_080AB1F8(a, 74);
    func_080AB1F8(a, 75);
    func_080AB1F8(a, 76);
    func_080AB1F8(a, 77);
    func_080AB1F8(a, 78);
    func_080AB1F8(a, 79);
    func_080AB1F8(a, 80);
    func_080AB1F8(a, 81);
    func_080AB1F8(a, 82);
    func_080AB1F8(a, 83);
    func_080AB1F8(a, 84);
    func_080AB1F8(a, 85);
    func_080AB1F8(a, 86);
    func_080AB1F8(a, 87);
    func_080AB1F8(a, 88);
    func_080AB1F8(a, 89);
    func_080AB1F8(a, 90);
    func_080AB1F8(a, 91);
    func_080AB1F8(a, 92);
    func_080AB1F8(a, 93);
}

void func_080AB334(u8 a) {
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(7));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(3));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(6));
    func_080AB1F8(a, func_08084458(7));
    func_080AB1F8(a, func_08084458(6));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(3));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(186));
    func_080AB1F8(a, func_08084458(185));
    func_080AB1F8(a, func_08084458(207));
    func_080AB1F8(a, func_08084458(205));
}

void func_080AB4AC(u8 a) {
    func_080AB1F8(a, 0);
    func_080AB1F8(a, 1);
    func_080AB1F8(a, 2);
    func_080AB1F8(a, 3);
    func_080AB1F8(a, 4);
    func_080AB1F8(a, 5);
    func_080AB1F8(a, 6);
    func_080AB1F8(a, 7);
    func_080AB1F8(a, 8);
    func_080AB1F8(a, 9);
    func_080AB1F8(a, 173);
    func_080AB1F8(a, 176);
    func_080AB1F8(a, 178);
    func_080AB1F8(a, 181);
    func_080AB1F8(a, 184);
    func_080AB1F8(a, 189);
    func_080AB1F8(a, 192);
    func_080AB1F8(a, 195);
    func_080AB1F8(a, 197);
    func_080AB1F8(a, 202);
    func_080AB1F8(a, 204);
    func_080AB1F8(a, 207);
    func_080AB1F8(a, 213);
    func_080AB1F8(a, 216);
    func_080AB1F8(a, 219);
    func_080AB1F8(a, 224);
    func_080AB1F8(a, 225);
    func_080AB1F8(a, 228);
    func_080AB1F8(a, 234);
    func_080AB1F8(a, 235);
    func_080AB1F8(a, 238);
    func_080AB1F8(a, 255);
    func_080AB1F8(a, 257);
    func_080AB1F8(a, 258);
    func_080AB1F8(a, 245);
    func_080AB1F8(a, 247);
    func_080AB1F8(a, 248);
    func_080AB1F8(a, 265);
    func_080AB1F8(a, 267);
    func_080AB1F8(a, 268);
    func_080AB1F8(a, 275);
    func_080AB1F8(a, 277);
    func_080AB1F8(a, 278);
    func_080AB1F8(a, 285);
    func_080AB1F8(a, 287);
    func_080AB1F8(a, 288);
    func_080AB1F8(a, 295);
    func_080AB1F8(a, 297);
    func_080AB1F8(a, 298);
    func_080AB1F8(a, 305);
    func_080AB1F8(a, 307);
    func_080AB1F8(a, 308);
    func_080AB1F8(a, 315);
    func_080AB1F8(a, 317);
    func_080AB1F8(a, 318);
    func_080AB1F8(a, 325);
    func_080AB1F8(a, 327);
    func_080AB1F8(a, 328);
    func_080AB1F8(a, 335);
    func_080AB1F8(a, 337);
    func_080AB1F8(a, 338);
    func_080AB1F8(a, 345);
    func_080AB1F8(a, 347);
    func_080AB1F8(a, 348);
    func_080AB1F8(a, 355);
    func_080AB1F8(a, 357);
    func_080AB1F8(a, 358);
    func_080AB1F8(a, 365);
    func_080AB1F8(a, 367);
    func_080AB1F8(a, 368);
    func_080AB1F8(a, 375);
    func_080AB1F8(a, 377);
    func_080AB1F8(a, 378);
    func_080AB1F8(a, 450);
    func_080AB1F8(a, 459);
    func_080AB1F8(a, 462);
    func_080AB1F8(a, 465);
    func_080AB1F8(a, 468);
    func_080AB1F8(a, 492);
    func_080AB1F8(a, 528);
    func_080AB1F8(a, 529);
    func_080AB1F8(a, 453);
    func_080AB1F8(a, 471);
    func_080AB1F8(a, 474);
    func_080AB1F8(a, 477);
    func_080AB1F8(a, 480);
    func_080AB1F8(a, 486);
    func_080AB1F8(a, 489);
    func_080AB1F8(a, 495);
    func_080AB1F8(a, 501);
    func_080AB1F8(a, 504);
    func_080AB1F8(a, 507);
    func_080AB1F8(a, 510);
    func_080AB1F8(a, 513);
    func_080AB1F8(a, 519);
    func_080AB1F8(a, 522);
}

void func_080AB880(void) {
    func_08084458(7);
    func_08084458(6);
    func_08084458(5);
    func_08084458(5);
    func_08084458(4);
    func_08084458(3);
    func_08084458(4);
    func_08084458(3);
    func_08084458(2);
    func_08084458(2);
    func_08084458(1);
    func_08084458(0);
    func_08084458(185);
    func_08084458(386);
    func_08084458(207);
}

void func_080AB8E4(void) {
    func_080AB1F8(0, 0);
    func_080AB1F8(0, 1);
    func_080AB1F8(0, 2);
    func_080AB1F8(0, 3);
    func_080AB1F8(0, 4);
    func_080AB1F8(0, 5);
    func_080AB1F8(0, 6);
    func_080AB1F8(0, 7);
    func_080AB1F8(0, 8);
    func_080AB1F8(0, 9);
    func_080AB1F8(0, 10);
    func_080AB1F8(0, 11);
    func_080AB1F8(0, 12);
    func_080AB1F8(0, 13);
    func_080AB1F8(0, 14);
}

void func_080AB964(void) {
}

void func_080AB968(void) {
}
void func_080AB96C(void* a) {
    func_08006120(0, 16);
    gUnk_02034B34 = a;
    TaskPoolInit(gUnk_02034B20, 1);
    gUnk_0203A9E0 = 0;
}
void Mode_riku_btlTutorial_1(void) {
    u16 t;

    t = gGameState.unk_17A | 0x1000;
    gGameState.unk_17A = t;
    ModeRequest(&gModeBattle, (s32)gUnk_02034B34);
    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}

void Mode_riku_deckTutorial_1(void) {
    if (!func_08006314()) {
        switch (gUnk_0203A9E0) {
        case 0:
            if (!func_080A42C8() && gUnk_0203A9E0 == 0) {
                func_080A4188(gUnk_02034B20, 0xB1);
                gUnk_0203A9E0 = 1;
            }
            break;
        case 1:
            if (!func_080A42C8()) {
                gGameState.unk_17A |= 0x800;
                ModeRequest(&gUnk_09EE2704, (s32)gUnk_02034B34);
            }
            break;
        }
    }

    TaskPoolUpdate(gUnk_02034B20);
    TaskPoolDraw(gUnk_02034B20);
}

void func_080ABA70(void) {
    TaskPoolDestroy(gUnk_02034B20);
}

#ifndef VERSION_EU
s32 func_080ABA80(s32* out) {
    UnkStruct_080ABA80 arr;
    u8 buf[6];
    u8 flag;
    u8 i;
    s32 r;

    arr = gUnk_09045188;
    flag = 0;
    memset(buf, 0, 6);

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        arr.unk_00[i] = gUnk_02039DD4->unk_000[i]->unk_48->unk_28;

        if (out != 0) {
            out[i] = gUnk_02039DD4->unk_000[i]->unk_48->unk_24;
        }
    }

    if (gUnk_02039DD4->unk_0D0 == 1) {
        gUnk_02039DD4->unk_0DD = 1;

        if ((gGameState.flags & 8) && gBtlWork->unk_0A4 == 1 && !(gBtlWork->unk_068 & 0x800000000000)) {
            if (gUnk_02039DD4->unk_0EE == 1 || gBtlWork->unk_1C8 > 29) {
                gUnk_02039DD4->unk_0EE = 0;
                return 46;
            }
        }

        return gUnk_02039DD4->unk_000[0]->unk_48->unk_24;
    } else if (gUnk_02039DD4->unk_0D0 == 0) {
        gUnk_02039DD4->unk_0DD = 0;
        return -1;
    } else {
        r = func_080AC5E8(gUnk_02039DD4, gUnk_02039DD4->unk_0D0, gUnk_02039DD4->unk_0C2, &arr, &flag);

        switch (r) {
        case 108:
            gUnk_02039DD4->unk_0DD = 1;
            return 46;
        default:
            if (gBtlWork->unk_0A4 == 1) {
                if (gBtlWork->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            } else {
                if (gUnk_02039B9C->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            }
        case 106:
            if (out != 0) {
                func_080ABEF8(&arr, buf);

                if (buf[0] == 1) {
                    out[0] = arr.unk_00[0];
                    out[1] = -1;
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else if (buf[1] == 1) {
                    out[1] = -1;
                    out[2] = arr.unk_00[1];
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else {
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                }

                if (gBtlWork->unk_0A4 == 1) {
                    if (gBtlWork->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                } else {
                    if (gUnk_02039B9C->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                }
            }

            return 145;
        }
    }
}
#else
INCLUDE_ASM("card/func_080ABA80.s");
#endif

#ifndef VERSION_EU
s32 func_080ABCA4(s32* out, void* b) {
    UnkStruct_080ABA80 arr;
    u8 buf[6];
    u8 flag;
    u8 i;
    s32 r;

    memset(&arr, 0, 24);
    flag = 0;
    memset(buf, 0, 6);

    for (i = 0; i < gUnk_02039DD4->unk_0D0; i++) {
        arr.unk_00[i] = gUnk_02039DD4->unk_000[i]->unk_48->unk_28;

        if (out != 0) {
            out[i] = gUnk_02039DD4->unk_000[i]->unk_48->unk_24;
        }
    }

    if (gUnk_02039DD4->unk_0D0 == 1) {
        gUnk_02039DD4->unk_0DD = 1;

        if ((gGameState.flags & 8) && gBtlWork->unk_0A4 != 0 && !(gBtlWork->unk_068 & 0x800000000000)) {
            if (gUnk_02039DD4->unk_0EE == 1 || gBtlWork->unk_1C8 > 29) {
                gUnk_02039DD4->unk_0EE = 0;
                return 46;
            }
        }

        return gUnk_02039DD4->unk_000[0]->unk_48->unk_24;
    } else if (gUnk_02039DD4->unk_0D0 == 0) {
        gUnk_02039DD4->unk_0DD = 0;
        return -1;
    } else {
        r = func_080AD144(gUnk_02039DD4, gUnk_02039DD4->unk_0D0, gUnk_02039DD4->unk_0C2, &arr, &flag, b);

        switch (r) {
        case 108:
            gUnk_02039DD4->unk_0DD = 1;
            return 46;
        default:
            if (gBtlWork->unk_0A4 == 1) {
                if (gBtlWork->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            } else {
                if (gUnk_02039B9C->unk_0F4 == 47) {
                    out[0] = out[1] = func_080AC140(r);
                    gUnk_02039DD4->unk_0DD = 2;
                    return 145;
                } else {
                    return func_080AC140(r);
                }
            }
        case 106:
            if (out != 0) {
                func_080ABEF8(&arr, buf);

                if (buf[0] == 1) {
                    out[0] = arr.unk_00[0];
                    out[1] = -1;
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else if (buf[1] == 1) {
                    out[1] = -1;
                    out[2] = arr.unk_00[1];
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                } else {
                    out[3] = out[0];
                    out[4] = out[1];
                    out[5] = out[2];
                }

                if (gBtlWork->unk_0A4 == 1) {
                    if (gBtlWork->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                } else {
                    if (gUnk_02039B9C->unk_0F4 == 47) {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0 * 2;
                    } else {
                        gUnk_02039DD4->unk_0DD = gUnk_02039DD4->unk_0D0;
                    }
                }
            }

            return 145;
        }
    }
}
#else
INCLUDE_ASM("card/func_080ABCA4.s");
#endif

u8 func_080ABED0(void) {
    if ((*(u32*)&gUnk_02039DD4->unk_0E0 & 0x00FFFF00) != 0) {
        return gUnk_02039DD4->unk_0DD;
    }

    return 0;
}

#define SIO_PAIR_CASE(v) \
    case v: \
        a[i] = key; \
        b[i] = 1; \
        break;

u8 func_080ABEF8(u32* a, u8* b) {
    u32 v[6];
    u32 key;
    s32 i = 0;

    if (gUnk_02039DD4->unk_0D0 <= 2) {
        return 0;
    }

    v[0] = a[0];
    v[1] = a[1];
    v[2] = a[2];
    key = (v[1] << 10) | v[0] | 0x80000000;

    switch (key) {
    SIO_PAIR_CASE(0x8002ACAB)
    SIO_PAIR_CASE(0x8002D4B5)
    SIO_PAIR_CASE(0x8002FCBF)
    SIO_PAIR_CASE(0x800324C9)
    SIO_PAIR_CASE(0x80034CD3)
    SIO_PAIR_CASE(0x800374DD)
    SIO_PAIR_CASE(0x80039CE7)
    SIO_PAIR_CASE(0x8003C4F1)
    SIO_PAIR_CASE(0x8003ECFB)
    SIO_PAIR_CASE(0x80041505)
    SIO_PAIR_CASE(0x80043D0F)
    SIO_PAIR_CASE(0x80046519)
    SIO_PAIR_CASE(0x80048D23)
    SIO_PAIR_CASE(0x8004B52D)
    SIO_PAIR_CASE(0x8004DD37)
    SIO_PAIR_CASE(0x80050541)
    SIO_PAIR_CASE(0x80052D4B)
    SIO_PAIR_CASE(0x80055555)
    SIO_PAIR_CASE(0x80057D5F)
    SIO_PAIR_CASE(0x8005A569)
    SIO_PAIR_CASE(0x8005CD73)
    SIO_PAIR_CASE(0x800A7E9F)
    }

    i++;
    key = v[1] | (v[2] << 10) | 0x80000000;

    switch (key) {
    SIO_PAIR_CASE(0x8002ACAB)
    SIO_PAIR_CASE(0x8002D4B5)
    SIO_PAIR_CASE(0x8002FCBF)
    SIO_PAIR_CASE(0x800324C9)
    SIO_PAIR_CASE(0x80034CD3)
    SIO_PAIR_CASE(0x800374DD)
    SIO_PAIR_CASE(0x80039CE7)
    SIO_PAIR_CASE(0x8003C4F1)
    SIO_PAIR_CASE(0x8003ECFB)
    SIO_PAIR_CASE(0x80041505)
    SIO_PAIR_CASE(0x80043D0F)
    SIO_PAIR_CASE(0x80046519)
    SIO_PAIR_CASE(0x80048D23)
    SIO_PAIR_CASE(0x8004B52D)
    SIO_PAIR_CASE(0x8004DD37)
    SIO_PAIR_CASE(0x80050541)
    SIO_PAIR_CASE(0x80052D4B)
    SIO_PAIR_CASE(0x80055555)
    SIO_PAIR_CASE(0x80057D5F)
    SIO_PAIR_CASE(0x8005A569)
    SIO_PAIR_CASE(0x8005CD73)
    SIO_PAIR_CASE(0x800A7E9F)
    }
}
#ifdef NON_MATCHING
s32 func_080AC140(s32 a) {
    switch (a) {
    case 0:
        return 0x8002ACAB;
    case 1:
        return 0x8002D4B5;
    case 2:
        return 0x8002FCBF;
    case 3:
        return 0x800324C9;
    case 11:
        return 0x80034CD3;
    case 4:
        return 0x800374DD;
    case 5:
        return 0xC0100401;
    case 6:
        return 0x64;
    case 7:
        return 0xCAB2ACAB;
    case 8:
        return 0xCB52D4B5;
    case 9:
        return 0xCBF2FCBF;
    case 10:
        return 0xCC9324C9;
    case 13:
        return 0xCDD374DD;
    case 12:
        return 0xCD334CD3;
    case 14:
        return 0xCFB3ECFB;
    case 15:
        return 0x8003ECFB;
    case 16:
        return 0xCF13C4F1;
    case 17:
        return 0x8003C4F1;
    case 18:
        return 0xD0541505;
    case 19:
        return 0x80041505;
    case 20:
        return 0xD0F43D0F;
    case 21:
        return 0x80043D0F;
    case 22:
        return 0xD1946519;
    case 23:
        return 0x80046519;
    case 24:
        return 0xD2348D23;
    case 25:
        return 0x80048D23;
    case 26:
        return 0xD2D4B52D;
    case 27:
        return 0x8004B52D;
    case 28:
        return 0xD374DD37;
    case 29:
        return 0x8004DD37;
    case 30:
        return 0xD4150541;
    case 31:
        return 0x80050541;
    case 32:
        return 0xD4B52D4B;
    case 33:
        return 0x80052D4B;
    case 34:
        return 0xD5555555;
    case 35:
        return 0x80055555;
    case 36:
        return 0xD5F57D5F;
    case 37:
        return 0x80057D5F;
    case 38:
        return 0xD695A569;
    case 39:
        return 0x8005A569;
    case 40:
        return 0xD735CD73;
    case 41:
        return 0x8005CD73;
    case 42:
        return 0xE9FA7E9F;
    case 43:
        return 0x800A7E9F;
    case 44:
        return 0x80039CE7;
    case 45:
        return 0xCE739CE7;
    case 46:
        return 0x65;
    case 47:
        return 0x66;
    case 48:
        return 0x67;
    case 49:
        return 0x68;
    case 50:
        return 0x69;
    case 51:
        return 0x6A;
    case 52:
        return 0x6B;
    case 53:
        return 0x6C;
    case 54:
        return 0x6D;
    case 55:
        return 0x6E;
    case 56:
        return 0x6F;
    case 57:
        return 0x70;
    case 58:
        return 0x71;
    case 59:
        return 0x72;
    case 60:
        return 0x73;
    case 61:
        return 0x74;
    case 62:
        return 0x75;
    case 63:
        return 0x76;
    case 64:
        return 0x77;
    case 65:
        return 0x78;
    case 66:
        return 0x79;
    case 67:
        return 0x7A;
    case 69:
        return 0x7C;
    case 70:
        return 0x7D;
    case 71:
        return 0x7E;
    case 72:
        return 0x7F;
    case 73:
        return 0x80;
    case 74:
        return 0x81;
    case 75:
        return 0x82;
    case 76:
        return 0x83;
    case 77:
        return 0x84;
    case 78:
        return 0x85;
    case 79:
        return 0x86;
    case 80:
        return 0x87;
    case 81:
        return 0x88;
    case 82:
        return 0x89;
    case 83:
        return 0x8A;
    case 84:
        return 0x8B;
    case 108:
        return 0x2E;
    case 85:
        return 0xF21C8721;
    case 86:
        return 0xEB3ACEB3;
    case 87:
        return 0xEB3AA6B3;
    case 88:
        return 0xEE5B96E5;
    case 89:
        return 0xEEFB96EF;
    case 90:
        return 0xF49D2735;
    case 91:
        return 0xED1AF6BD;
    case 92:
        return 0xED1B1EC7;
    case 93:
        return 0xF0DBE6F9;
    case 94:
        return 0xF53D7753;
    case 95:
        return 0xF53D4F5D;
    case 96:
        return 0xF5DD4F53;
    case 97:
        return 0xF17C0F03;
    case 98:
        return 0xF35CFF3F;
    case 99:
        return 0xF21CAF21;
    case 100:
        return 0xF71D9F71;
    case 101:
        return 0xF7BDC767;
    case 102:
        return 0xFADEB7A3;
    case 103:
        return 0xFA3EB7A3;
    case 104:
        return 0xF85E3F85;
    case 105:
        return 0xF53D4F53;
    }

    return a;
}
#else
INCLUDE_ASM("card/func_080AC140.s");
#endif
u8 func_080AC5BC(UnkStruct_02034AAC** p, u8 a) {
    u8 x;
    u8 y;
    u8 z;

    if (a != 3) {
        return 0;
    }

    x = p[0]->unk_A5;
    y = p[1]->unk_A5;
    z = p[2]->unk_A5;

    if (x != y) {
        return 0;
    }

    if (x != z) {
        return 0;
    }

    return 1;
}

s32 func_080AC5E8(UnkStruct_02039DD4* g, u8 count, u8 kind, UnkStruct_080ABA80* arr, u8* flag) {
    s32 v[3];
    u32 key;
    u8 ret;
    u8 i;

    memset(v, 0, 12);
    ret = 0;

    for (i = 0; i < count; i++) {
        v[i] = (*(i + g->unk_000))->unk_48->unk_28;
    }

    if ((gGameState.flags & 8) && gBtlWork->unk_0A4 != 0 && !(gBtlWork->unk_068 & 0x800000000000)) {
        if (gUnk_02039DD4->unk_0EE == 1 || (s16)gBtlWork->unk_1C8 > 29) {
            gUnk_02039DD4->unk_0EE = 0;
            return 108;
        }
    }

    key = v[0] | (v[1] << 10) | (v[2] << 20) | (count << 30);

    switch (key) {
    case 0x8002ACAB:
        return 0;
    case 0x8002FCBF:
        return 2;
    case 0x8002D4B5:
        return 1;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    case 0xC0100401:
    case 0xC0B02C0B:
    case 0xC1505415:
    case 0xC1F07C1F:
    case 0xC290A429:
    case 0xC330CC33:
    case 0xC3D0F43D:
    case 0xC4711C47:
    case 0xC5114451:
    case 0xC5B16C5B:
    case 0xC6519465:
    case 0xC6F1BC6F:
    case 0xC791E479:
    case 0xC8320C83:
    case 0xC8D2348D:
    case 0xC9725C97:
    case 0xCA1284A1:
        if ((u16)(kind - 10) <= 5 && (u8)func_0800FBCC(0) != 0) {
            arr->unk_00[0] = 50;
            return 50;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_0800FBCC(2) != 0) {
            arr->unk_00[0] = 51;
            return 51;
        }
        break;
    case 0xCAB2ACAB:
        return 7;
    case 0xCB52D4B5:
        return 8;
    case 0xCBF2FCBF:
        return 9;
    case 0xCC9324C9:
        return 10;
    case 0xCD334CD3:
        return 12;
    case 0xCDD374DD:
        return 13;
    case 0xCE739CE7:
        return 45;
    case 0xCFB3ECFB:
        return 14;
    case 0xCF13C4F1:
        return 16;
    case 0xD0541505:
        return 18;
    case 0xD0F43D0F:
        return 20;
    case 0xD1946519:
        return 22;
    case 0xD2348D23:
        return 24;
    case 0xD2D4B52D:
        return 26;
    case 0xD374DD37:
        return 28;
    case 0xD4150541:
        return 30;
    case 0xD4B52D4B:
        return 32;
    case 0xD5555555:
        return 34;
    case 0xD5F57D5F:
        return 36;
    case 0xD695A569:
        return 38;
    case 0xD735CD73:
        return 40;
    case 0xE9FA7E9F:
        return 42;
    case 0xCE739CDD:
        if ((u8)func_0800FBCC(39) != 0) {
            return 53;
        }
        break;
    case 0xCE734CDD:
        if ((u8)func_0800FBCC(38) != 0) {
            return 54;
        }
        break;
    case 0xCE72ACB5:
        if ((u8)func_0800FBCC(34) != 0) {
            return 65;
        }
        break;
    case 0xCAB2AD37:
        if ((u8)func_0800FBCC(32) != 0) {
            return 70;
        }
        break;
    case 0xCE734CC9:
        if ((u8)func_0800FBCC(43) != 0) {
            return 77;
        }
        break;
    case 0xE95A5695:
        if (gBtlWork->unk_068 & 0x800000000000) {
            if ((u16)(kind - 5) <= 10) {
                return 82;
            }

            if ((u16)(kind - 16) <= 9) {
                return 83;
            }

            if (kind > 26) {
                return 84;
            }
        }
        break;
    case 0xF21C8721:
        return 85;
    case 0xEB3ACEB3:
        return 86;
    case 0xEB3AA6B3:
        return 87;
    case 0xEE5B96E5:
        return 88;
    case 0xEEFB96EF:
        return 89;
    case 0xF49D2735:
        return 90;
    case 0xED1AF6BD:
        return 91;
    case 0xED1B1EC7:
        return 92;
    case 0xF0DBE6F9:
        return 93;
    case 0xF53D7753:
        return 94;
    case 0xF53D4F5D:
        return 95;
    case 0xF5DD4F53:
        return 96;
    case 0xF17C0F03:
        return 97;
    case 0xF35CFF3F:
        return 98;
    case 0xF21CAF21:
        return 99;
    case 0xF71D9F71:
        return 100;
    case 0xF7BDC767:
        return 101;
    case 0xFADEB7A3:
        return 102;
    case 0xFA3EB7A3:
        return 103;
    case 0xF85E3F85:
        return 104;
    case 0xF53D4F53:
        return 105;
    }

    if ((u8)func_080ADF94(g, count, 43) != 0 || (u8)func_080ADFD4(g, count) != 0) {
        if ((u8)func_0800FBCC(42) != 0) {
            return 55;
        }
    }

    if ((u8)func_080AE080(g, count) != 0 && (u8)func_0800FBCC(41) != 0) {
        return 56;
    }

    if ((u8)func_080ADEAC(g, 23, count) != 0 && (u8)func_0800FBCC(27) != 0) {
        return 58;
    }

    if ((u8)func_080ADEAC(g, 24, count) != 0 && (u8)func_0800FBCC(28) != 0) {
        return 59;
    }

    if ((u8)func_080ADEAC(g, 31, count) != 0 && (u8)func_0800FBCC(29) != 0) {
        return 60;
    }

    if ((u8)func_080ADEAC(g, 18, count) != 0 && (u8)func_0800FBCC(23) != 0) {
        return 61;
    }

    if ((u8)func_080ADEAC(g, 19, count) != 0 && (u8)func_0800FBCC(24) != 0) {
        return 62;
    }

    if ((u8)func_080ADEAC(g, 20, count) != 0 && (u8)func_0800FBCC(25) != 0) {
        return 63;
    }

    if ((u8)func_080ADEAC(g, 22, count) != 0 && (u8)func_0800FBCC(26) != 0) {
        return 64;
    }

    if ((u8)func_080AE0B4(g, count) != 0 && (u8)func_0800FBCC(46) != 0) {
        return 66;
    }

    if ((u8)func_080AE0F4(g, count) != 0 && (u8)func_0800FBCC(58) != 0) {
        return 67;
    }

    if ((u8)func_080AE014(g, count) != 0 && (u8)func_0800FBCC(44) != 0) {
        return 69;
    }

    if ((u8)func_080ADF60(g, count) != 0 && (u8)func_0800FBCC(31) != 0) {
        return 71;
    }

    if ((u8)func_080ADEEC(g, 25, 0, count) != 0 && (u8)func_0800FBCC(35) != 0) {
        return 72;
    }

    if ((u8)func_080ADEEC(g, 27, 0, count) != 0 && (u8)func_0800FBCC(50) != 0) {
        return 73;
    }

    if ((u8)func_080AE134(g, count) != 0 && (u8)func_0800FBCC(56) != 0) {
        return 74;
    }

    if ((u8)func_080AE168(g, count) != 0 && (u8)func_0800FBCC(30) != 0) {
        return 75;
    }

    if ((u8)func_080AE1A8(g, count) != 0 && (u8)func_0800FBCC(33) != 0) {
        return 76;
    }

    if ((u8)func_080ADE2C(g, count, 22, 23, 1) != 0 && (u8)func_0800FBCC(40) != 0) {
        return 78;
    }

    if ((u8)func_080ADE78(g, count, 24, 22) != 0 && (u8)func_0800FBCC(36) != 0) {
        return 79;
    }

    if ((u8)func_080ADE2C(g, count, 22, 25, 1) != 0 && (u8)func_0800FBCC(37) != 0) {
        return 80;
    }

    if ((u8)func_080AE1E8(g, count) != 0 && (u8)func_0800FBCC(45) != 0) {
        return 81;
    }

    if ((u8)func_080ADD04(g, count) != 0) {
        if ((u16)(kind - 10) <= 5 && (u8)func_0800FBCC(1) != 0) {
            arr->unk_00[0] = 46;
            return 46;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_0800FBCC(5) != 0) {
            arr->unk_00[0] = 5;
            return 5;
        }
    }

    if ((u8)func_080ADD58(g, count) != 0) {
        if ((u16)(kind - 1) <= 5 && (u8)func_0800FBCC(6) != 0) {
            arr->unk_00[0] = 47;
            return 47;
        }

        if ((u16)(kind - 24) <= 2 && (u8)func_0800FBCC(4) != 0) {
            arr->unk_00[0] = 6;
            return 6;
        }

        if ((u16)(kind - 7) <= 2 && (u8)func_0800FBCC(7) != 0) {
            arr->unk_00[0] = 48;
            return 48;
        }

        if (kind == 0 || kind == 27) {
            if ((u8)func_0800FBCC(3) != 0) {
                arr->unk_00[0] = 52;
                return 52;
            }
        }
    }

    if ((u8)func_080ADDA8(g, count) != 0 && (u8)func_0800FBCC(8) != 0) {
        arr->unk_00[0] = 49;
        return 49;
    }

    *flag = ret;

    if (ret == 0) {
        return 106;
    }

    if (ret == 1) {
        return arr->unk_00[0];
    }

    return 107;
}

s32 func_080AD144(UnkStruct_02039DD4* g, u8 count, u8 kind, UnkStruct_080ABA80* arr, u8* flag, void* b) {
    s32 v[3];
    u32 key;
    u8 ret;
    u8 i;

    memset(v, 0, 12);
    ret = 0;

    for (i = 0; i < count; i++) {
        v[i] = (*(i + g->unk_000))->unk_48->unk_28;
    }

    if ((gGameState.flags & 8) && gBtlWork->unk_0A4 != 0 && !(gBtlWork->unk_068 & 0x800000000000)) {
        if (gUnk_02039DD4->unk_0EE == 1 || (s16)gBtlWork->unk_1C8 > 29) {
            gUnk_02039DD4->unk_0EE = 0;
            return 108;
        }
    }

    key = v[0] | (v[1] << 10) | (v[2] << 20) | (count << 30);

    switch (key) {
    case 0x8002ACAB:
        return 0;
    case 0x8002FCBF:
        return 2;
    case 0x8002D4B5:
        return 1;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    case 0xC0100401:
    case 0xC0B02C0B:
    case 0xC1505415:
    case 0xC1F07C1F:
    case 0xC290A429:
    case 0xC330CC33:
    case 0xC3D0F43D:
    case 0xC4711C47:
    case 0xC5114451:
    case 0xC5B16C5B:
    case 0xC6519465:
    case 0xC6F1BC6F:
    case 0xC791E479:
    case 0xC8320C83:
    case 0xC8D2348D:
    case 0xC9725C97:
    case 0xCA1284A1:
        if ((u16)(kind - 10) <= 5 && (u8)func_080AE274(0, b) != 0) {
            arr->unk_00[0] = 50;
            return 50;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_080AE274(2, b) != 0) {
            arr->unk_00[0] = 51;
            return 51;
        }
        break;
    case 0xCAB2ACAB:
        return 7;
    case 0xCB52D4B5:
        return 8;
    case 0xCBF2FCBF:
        return 9;
    case 0xCC9324C9:
        return 10;
    case 0xCD334CD3:
        return 12;
    case 0xCDD374DD:
        return 13;
    case 0xCE739CE7:
        return 45;
    case 0xCFB3ECFB:
        return 14;
    case 0xCF13C4F1:
        return 16;
    case 0xD0541505:
        return 18;
    case 0xD0F43D0F:
        return 20;
    case 0xD1946519:
        return 22;
    case 0xD2348D23:
        return 24;
    case 0xD2D4B52D:
        return 26;
    case 0xD374DD37:
        return 28;
    case 0xD4150541:
        return 30;
    case 0xD4B52D4B:
        return 32;
    case 0xD5555555:
        return 34;
    case 0xD5F57D5F:
        return 36;
    case 0xD695A569:
        return 38;
    case 0xD735CD73:
        return 40;
    case 0xE9FA7E9F:
        return 42;
    case 0xCE739CDD:
        if ((u8)func_080AE274(39, b) != 0) {
            return 53;
        }
        break;
    case 0xCE734CDD:
        if ((u8)func_080AE274(38, b) != 0) {
            return 54;
        }
        break;
    case 0xCE72ACB5:
        if ((u8)func_080AE274(34, b) != 0) {
            return 65;
        }
        break;
    case 0xCAB2AD37:
        if ((u8)func_080AE274(32, b) != 0) {
            return 70;
        }
        break;
    case 0xCE734CC9:
        if ((u8)func_080AE274(43, b) != 0) {
            return 77;
        }
        break;
    case 0xE95A5695:
        if (gBtlWork->unk_068 & 0x800000000000) {
            if ((u16)(kind - 5) <= 10) {
                return 82;
            }

            if ((u16)(kind - 16) <= 9) {
                return 83;
            }

            if (kind > 26) {
                return 84;
            }
        }
        break;
    case 0xF21C8721:
        return 85;
    case 0xEB3ACEB3:
        return 86;
    case 0xEB3AA6B3:
        return 87;
    case 0xEE5B96E5:
        return 88;
    case 0xEEFB96EF:
        return 89;
    case 0xF49D2735:
        return 90;
    case 0xED1AF6BD:
        return 91;
    case 0xED1B1EC7:
        return 92;
    case 0xF0DBE6F9:
        return 93;
    case 0xF53D7753:
        return 94;
    case 0xF53D4F5D:
        return 95;
    case 0xF5DD4F53:
        return 96;
    case 0xF17C0F03:
        return 97;
    case 0xF35CFF3F:
        return 98;
    case 0xF21CAF21:
        return 99;
    case 0xF71D9F71:
        return 100;
    case 0xF7BDC767:
        return 101;
    case 0xFADEB7A3:
        return 102;
    case 0xFA3EB7A3:
        return 103;
    case 0xF85E3F85:
        return 104;
    case 0xF53D4F53:
        return 105;
    }

    if ((u8)func_080ADF94(g, count, 43) != 0 || (u8)func_080ADFD4(g, count) != 0) {
        if ((u8)func_080AE274(42, b) != 0) {
            return 55;
        }
    }

    if ((u8)func_080AE080(g, count) != 0 && (u8)func_080AE274(41, b) != 0) {
        return 56;
    }

    if ((u8)func_080ADEAC(g, 23, count) != 0 && (u8)func_080AE274(27, b) != 0) {
        return 58;
    }

    if ((u8)func_080ADEAC(g, 24, count) != 0 && (u8)func_080AE274(28, b) != 0) {
        return 59;
    }

    if ((u8)func_080ADEAC(g, 31, count) != 0 && (u8)func_080AE274(29, b) != 0) {
        return 60;
    }

    if ((u8)func_080ADEAC(g, 18, count) != 0 && (u8)func_080AE274(23, b) != 0) {
        return 61;
    }

    if ((u8)func_080ADEAC(g, 19, count) != 0 && (u8)func_080AE274(24, b) != 0) {
        return 62;
    }

    if ((u8)func_080ADEAC(g, 20, count) != 0 && (u8)func_080AE274(25, b) != 0) {
        return 63;
    }

    if ((u8)func_080ADEAC(g, 22, count) != 0 && (u8)func_080AE274(26, b) != 0) {
        return 64;
    }

    if ((u8)func_080AE0B4(g, count) != 0 && (u8)func_080AE274(46, b) != 0) {
        return 66;
    }

    if ((u8)func_080AE0F4(g, count) != 0 && (u8)func_080AE274(58, b) != 0) {
        return 67;
    }

    if ((u8)func_080AE014(g, count) != 0 && (u8)func_080AE274(44, b) != 0) {
        return 69;
    }

    if ((u8)func_080ADF60(g, count) != 0 && (u8)func_080AE274(31, b) != 0) {
        return 71;
    }

    if ((u8)func_080ADEEC(g, 25, 0, count) != 0 && (u8)func_080AE274(35, b) != 0) {
        return 72;
    }

    if ((u8)func_080ADEEC(g, 27, 0, count) != 0 && (u8)func_080AE274(50, b) != 0) {
        return 73;
    }

    if ((u8)func_080AE134(g, count) != 0 && (u8)func_080AE274(56, b) != 0) {
        return 74;
    }

    if ((u8)func_080AE168(g, count) != 0 && (u8)func_080AE274(30, b) != 0) {
        return 75;
    }

    if ((u8)func_080AE1A8(g, count) != 0 && (u8)func_080AE274(33, b) != 0) {
        return 76;
    }

    if ((u8)func_080ADE2C(g, count, 22, 23, 1) != 0 && (u8)func_080AE274(40, b) != 0) {
        return 78;
    }

    if ((u8)func_080ADE78(g, count, 24, 22) != 0 && (u8)func_080AE274(36, b) != 0) {
        return 79;
    }

    if ((u8)func_080ADE2C(g, count, 22, 25, 1) != 0 && (u8)func_080AE274(37, b) != 0) {
        return 80;
    }

    if ((u8)func_080AE1E8(g, count) != 0 && (u8)func_080AE274(45, b) != 0) {
        return 81;
    }

    if ((u8)func_080ADD04(g, count) != 0) {
        if ((u16)(kind - 10) <= 5 && (u8)func_080AE274(1, b) != 0) {
            arr->unk_00[0] = 46;
            return 46;
        }

        if ((u16)(kind - 20) <= 3 && (u8)func_080AE274(5, b) != 0) {
            arr->unk_00[0] = 5;
            return 5;
        }
    }

    if ((u8)func_080ADD58(g, count) != 0) {
        if ((u16)(kind - 1) <= 5 && (u8)func_080AE274(6, b) != 0) {
            arr->unk_00[0] = 47;
            return 47;
        }

        if ((u16)(kind - 24) <= 2 && (u8)func_080AE274(4, b) != 0) {
            arr->unk_00[0] = 6;
            return 6;
        }

        if ((u16)(kind - 7) <= 2 && (u8)func_080AE274(7, b) != 0) {
            arr->unk_00[0] = 48;
            return 48;
        }

        if (kind == 0 || kind == 27) {
            if ((u8)func_080AE274(3, b) != 0) {
                arr->unk_00[0] = 52;
                return 52;
            }
        }
    }

    if ((u8)func_080ADDA8(g, count) != 0 && (u8)func_080AE274(8, b) != 0) {
        arr->unk_00[0] = 49;
        return 49;
    }

    *flag = ret;

    if (ret == 0) {
        return 106;
    }

    if (ret == 1) {
        return arr->unk_00[0];
    }

    return 107;
}

s32 func_080ADD04(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        c0 = d0->unk_1C;
        d1 = p[1]->unk_48;
        c1 = d1->unk_1C;
        d2 = p[2]->unk_48;
        c2 = d2->unk_1C;

        if (d0->unk_2A == 0 && d1->unk_2A == 0 && d2->unk_2A == 0 &&
            c0 != c1 && c0 != c2 && c1 != c2) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADD58(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        d1 = p[1]->unk_48;
        d2 = p[2]->unk_48;

        if (d0->unk_24 != 18 && d1->unk_24 != 18 && d2->unk_24 != 18 &&
            d0->unk_2A == 0 && d1->unk_2A == 0 && d2->unk_2A == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADDA8(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        c0 = d0->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        c2 = p[2]->unk_48->unk_1C;

        if (c0 != c1 && c1 != c2 && c2 != c0) {
            if (d0->unk_2A == 0) {
                if (c1 == 39 && c2 == 40) {
                    return 1;
                }

                if (c1 == 40 && c2 == 39) {
                    return 1;
                }
            }

            if (p[1]->unk_48->unk_2A == 0) {
                if (c0 == 39 && c2 == 40) {
                    return 1;
                }

                if (c0 == 40 && c2 == 39) {
                    return 1;
                }
            }

            if (p[2]->unk_48->unk_2A == 0) {
                if (c1 == 39 && c0 == 40) {
                    return 1;
                }

                if (c1 == 40 && c0 == 39) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

s32 func_080ADE2C(UnkStruct_02034AAC** p, u8 b, u16 c, u16 d, u8 e) {
    if (
#ifdef VERSION_EU
        b == 3 &&
#endif
        p[0]->unk_48->unk_1C == c && p[1]->unk_48->unk_1C == d &&
        p[2]->unk_48->unk_2A == e && !(p[2]->unk_48->unk_1E & 4)) {
        return 1;
    }

    return 0;
}

s32 func_080ADE78(UnkStruct_02034AAC** p, u8 b, u16 c, u16 d) {
    if (
#ifdef VERSION_EU
        b == 3 &&
#endif
        p[0]->unk_48->unk_1C == c && p[1]->unk_48->unk_1C == d &&
        (p[2]->unk_48->unk_1E & 4)) {
        return 1;
    }

    return 0;
}

s32 func_080ADEAC(UnkStruct_02034AAC** p, u16 c, u8 b) {
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        d1 = p[1]->unk_48;
        d2 = p[2]->unk_48;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (s1 == 0 && s2 == 0 && c0 == c) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADEEC(UnkStruct_02034AAC** p, u16 c, u8 e, u8 b) {
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        d1 = p[1]->unk_48;
        d2 = p[2]->unk_48;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (c0 == c && s1 == e && s2 == s1) {
            return 1;
        }
    }

    return 0;
}

#ifndef VERSION_EU
s32 func_080ADF30(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;
    u16 c2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        c2 = p[2]->unk_48->unk_1C;

        if (c1 == c2 && c1 == 26 && c0 != 26) {
            return 1;
        }
    }

    return 0;
}
#endif

s32 func_080ADF60(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;

        if (c0 == 18 && c1 == 30 && p[2]->unk_48->unk_2A == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADF94(UnkStruct_02034AAC** p, u8 b, u16 c) {
    u16 e0;
    u16 e1;

    if (b == 3) {
        e0 = p[0]->unk_48->unk_1E;
        e1 = p[1]->unk_48->unk_1E;

        if ((e0 & 4) && (e1 & 4) && p[2]->unk_48->unk_1C == c) {
            return 1;
        }
    }

    return 0;
}

s32 func_080ADFD4(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;

        if (c0 == 25 && c1 == 30) {
            d2 = p[2]->unk_48;

            if (d2->unk_2A == 2 && !(d2->unk_1E & 8)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 func_080AE014(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d1;
    u16 e0;
    u16 e1;

    if (b == 3) {
        e0 = p[0]->unk_48->unk_1E;
        d1 = p[1]->unk_48;
        e1 = d1->unk_1E;

        if ((e0 & 4) && e1 == 0 && d1->unk_2A == 1 &&
            p[2]->unk_48->unk_1C == 43) {
            return 1;
        }

        if (p[0]->unk_48->unk_1C == 27 && p[1]->unk_48->unk_1C == 19 &&
            p[2]->unk_48->unk_2A == 2 && !(p[2]->unk_48->unk_1E & 8)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE080(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;
    u16 e2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        e2 = p[2]->unk_48->unk_1E;

        if (c0 == 26 && c1 == 29 && (e2 & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE0B4(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 36 && c1 == 38 && s2 == 2 && !(d2->unk_1E & 8)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE0F4(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 18 && c1 == 39 && s2 == 1 && !(d2->unk_1E & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE134(UnkStruct_02034AAC** p, u8 b) {
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        s2 = p[2]->unk_48->unk_2A;

        if (c0 == 31 && c1 == 23 && s2 == 0) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE168(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 24 && c1 == 18 && s2 == 1 && !(d2->unk_1E & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE1A8(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d2;
    u16 c0;
    u16 c1;
    u8 s2;

    if (b == 3) {
        c0 = p[0]->unk_48->unk_1C;
        c1 = p[1]->unk_48->unk_1C;
        d2 = p[2]->unk_48;
        s2 = d2->unk_2A;

        if (c0 == 24 && c1 == 19 && s2 == 1 && !(d2->unk_1E & 4)) {
            return 1;
        }
    }

    return 0;
}

s32 func_080AE1E8(UnkStruct_02034AAC** p, u8 b) {
    CardDef* d0;
    CardDef* d1;
    CardDef* d2;
    u16 c0;
    u16 c1;
    u16 c2;
    u8 s0;
    u8 s1;
    u8 s2;

    if (b == 3) {
        d0 = p[0]->unk_48;
        c0 = d0->unk_1C;
        d1 = p[1]->unk_48;
        c1 = d1->unk_1C;
        d2 = p[2]->unk_48;
        c2 = d2->unk_1C;
        s0 = d0->unk_2A;
        s1 = d1->unk_2A;
        s2 = d2->unk_2A;

        if (s0 == 1 && !(d0->unk_1E & 4) && s1 == 1 && !(d1->unk_1E & 4) &&
            c2 == 44) {
            return 1;
        }

        if (c0 == 23 && c1 == 24 && s2 == 2 && !(p[2]->unk_48->unk_1E & 8)) {
            return 1;
        }
    }

    return 0;
}

u8 func_080AE274(s32 a, s32 b) {
    u8 r;

    if (b != 0) {
        r = func_0800FCD8(a, b);
    } else {
        r = func_0800FC90(a);
    }

    return r;
}
s32 func_080AE28C(u32* p) {
    u32 v[6];

    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];

    switch ((v[1] << 10) | v[0] | 0x80000000) {
    case 0x8002ACAB:
        return 0;
    case 0x8002D4B5:
        return 1;
    case 0x8002FCBF:
        return 2;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    }

    switch (v[1] | (v[2] << 10) | 0x80000000) {
    case 0x8002ACAB:
        return 0;
    case 0x8002D4B5:
        return 1;
    case 0x8002FCBF:
        return 2;
    case 0x800324C9:
        return 3;
    case 0x80034CD3:
        return 11;
    case 0x800374DD:
        return 4;
    case 0x80039CE7:
        return 44;
    case 0x8003ECFB:
        return 15;
    case 0x8003C4F1:
        return 17;
    case 0x80041505:
        return 19;
    case 0x80043D0F:
        return 21;
    case 0x80046519:
        return 23;
    case 0x80048D23:
        return 25;
    case 0x8004B52D:
        return 27;
    case 0x8004DD37:
        return 29;
    case 0x80050541:
        return 31;
    case 0x80052D4B:
        return 33;
    case 0x80055555:
        return 35;
    case 0x80057D5F:
        return 37;
    case 0x8005A569:
        return 39;
    case 0x8005CD73:
        return 41;
    case 0x800A7E9F:
        return 43;
    }

    return 106;
}
#ifdef VERSION_EU
INCLUDE_ASM("card/eu_080AB9FC.s");
#endif
void task_print_0(void) {
    func_0809D1FC(0);
}
s32 task_print_1(void) {
    return 1;
}
void task_print_2(void) {
    func_0809D3F0();
}
void task_print_3(void) {
    func_0809D26C();
}
#ifndef VERSION_EU
void mode_sio_battle_0(s32 a) {
    UnkStruct_02034B38* w;
    void* gfx;
    s32 i;

    gUnk_02034B38 = EwramAlloc(sizeof(UnkStruct_02034B38));
    func_08006120(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 7, 0);
    SetupBg(1, 0, 31, 0);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 64);
    LoadBgMap(1, gUnk_096F5464, 0x800);
    EnableBg(1);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 0;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 0;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_08 = -0x8000;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_0C = -0x800;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_10 = 0xA000;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_14 = LoadObjTiles(gUnk_0962AD62, 0x240);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_18 = LoadObjPalette(gUnk_096FBA44, 32);

    for (i = 0; i < 3; i++) {
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_1C[i] = gUnk_09EF3884[i];
    }

    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_28 = LoadObjTiles(gUnk_0962B286, 0x600);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_2C = LoadObjPalette(gUnk_096FBA64, 32);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_34 = LoadObjTiles(gUnk_0962B8BE, 0x600);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_38 = LoadObjPalette(gUnk_096FBA84, 32);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_40 = LoadObjTiles(gUnk_0962B090, 0x1C0);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_44 = LoadObjPalette(gUnk_096FBAA4, 32);
    AnimInit(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_4C, (s32)gUnk_09EF38B4, (s32)gUnk_09EF3894);
    AnimStart(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_4C, 1, 1);
    gfx = AnimGetGfx(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_4C);
    w = (UnkStruct_02034B38*)gUnk_02034B38;
    w->unk_48 = gfx;
    w->unk_68 = a;

    switch (w->unk_68) {
    case 0:
    case 1:
        if (w->unk_68 == 0) {
            if (gUnk_0203A9E8 != 1) {
                gUnk_0203A9E8 = 0;
                w->unk_00 = 1;
            } else {
                gUnk_0203A9E8 = 1;
                w->unk_00 = 0;
            }
        } else {
            gUnk_0203A9E8 = 1;
            w->unk_00 = 0;
        }

        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_30 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_3C = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        break;
    case 2:
        w->unk_00 = 0;
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_30 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_3C = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        gUnk_0203A9E8 = 1;
        break;
    case 3:
        w->unk_00 = 0;
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_30 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_3C = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        gUnk_0203A9E8 = 1;
        break;
    case 0xFFFF:
        break;
    }

    gUnk_0203C374 = 0;
    gUnk_0203A9E4 = 0;
}
#else
INCLUDE_ASM("card/mode_sio_battle_0.s");
#endif
#ifdef NON_MATCHING
void mode_sio_battle_1(void) {
    switch ((s8)((UnkStruct_02034B38*)gUnk_02034B38)->unk_01) {
    case 0:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_0C, 0, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_10, 0x9800, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 1;
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
        }
        break;
    case 1:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_08, 0, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 5;
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
        }
        break;
    case 5:
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 6;
        break;
    case 6:
        if (gUnk_0203A9E8 == 1) {
            if (GetKeysPressed() & 0x40) {
                m4aSongNumStart(101);
                ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00--;

                if (((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 < 0) {
                    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 = 1;
                }
            }

            if (GetKeysPressed() & 0x80) {
                m4aSongNumStart(101);
                ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00++;

                if (((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 > 1) {
                    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 = 0;
                }
            }
        } else {
            if (GetKeysPressed() & 0xC0) {
                m4aSongNumStart(105);
            }
        }

        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_30 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_3C = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];

        if (GetKeysPressed() & 9) {
            m4aSongNumStart(102);

            switch (((UnkStruct_02034B38*)gUnk_02034B38)->unk_00) {
            case 0:
                ModeRequest(&gModeSioBtlConnect, 0);
                break;
            case 1:
                ModeRequest(&gModeMenuLoad, 1);
                break;
            }
        }

        if (GetKeysPressed() & 2) {
            m4aSongNumStart(104);
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 2;
        }
        break;
    case 2:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_08, -0x8000, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 3;
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
        }
        break;
    case 3:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_0C, -0x800, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_10, 0xA000, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ModeRequest(&gModeTitle, 0);
            return;
        }
        break;
    }

    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_48 = AnimUpdate(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_4C);
    DrawSprite(((UnkStruct_02034B38*)gUnk_02034B38)->unk_08 >> 8, 0, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_1C[0], ((UnkStruct_02034B38*)gUnk_02034B38)->unk_14, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_18, 0, 0x400, -16);
    DrawSprite(128, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_0C >> 8, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_28, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_14, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_18, 0, 0x400, -1);
    DrawSprite(128, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_10 >> 8, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_2C, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_14, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_18, 0, 0x400, -1);
    DrawSprite(72, 48, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_30, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_1C[1], ((UnkStruct_02034B38*)gUnk_02034B38)->unk_1C[2], 0, 0x400, -32);
    DrawSprite(72, 48, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_3C, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_34, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_38, 0, 0x400, -32);
    func_0805F1C0(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_64, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 7 * 1024 + 0x3300);
    DrawSprite(64, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 >> 8, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_48, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_40, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_44, 0, 0x400, -48);
}
#else
INCLUDE_ASM("card/mode_sio_battle_1.s");
#endif

void mode_sio_battle_2(void) {
    ReleaseObjTiles(gUnk_02034B38[5]);
    ReleaseObjPalette(gUnk_02034B38[6]);
    ReleaseObjTiles(gUnk_02034B38[10]);
    ReleaseObjPalette(gUnk_02034B38[11]);
    ReleaseObjTiles(gUnk_02034B38[13]);
    ReleaseObjPalette(gUnk_02034B38[14]);
    ReleaseObjTiles(gUnk_02034B38[16]);
    ReleaseObjPalette(gUnk_02034B38[17]);
    EwramFree(gUnk_02034B38);
}

void func_080AEB94(void) {
    gUnk_0203A9E8 = 0;
}
