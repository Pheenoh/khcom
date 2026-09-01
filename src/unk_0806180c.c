#include "macros.h"
#include "unk_0806180c.h"

INCLUDE_ASM("unk_0806180c/func_0806180C.s");
INCLUDE_ASM("unk_0806180c/func_08062DC8.s");
INCLUDE_ASM("unk_0806180c/func_08064B80.s");
INCLUDE_ASM("unk_0806180c/func_08064DD4.s");
INCLUDE_ASM("unk_0806180c/func_08064EF4.s");
INCLUDE_ASM("unk_0806180c/func_08065170.s");
INCLUDE_ASM("unk_0806180c/func_080658B8.s");
INCLUDE_ASM("unk_0806180c/func_08065940.s");
void func_08065ACC(TextSlot* p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        p->unk_00 = NULL;
        p->unk_05 = 0;
        p++;
    }
}
void func_08065AE0(TextSlot* p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (p->unk_00 != NULL) {
            ReleaseObjTiles(p->unk_00);
            p->unk_00 = NULL;
        }
        p->unk_05 = 0;
        p++;
    }
}
INCLUDE_ASM("unk_0806180c/func_08065B08.s");
INCLUDE_ASM("unk_0806180c/func_08065B54.s");
INCLUDE_ASM("unk_0806180c/func_08065B6C.s");
INCLUDE_ASM("unk_0806180c/func_08065B7C.s");
INCLUDE_ASM("unk_0806180c/_08066468.s");
INCLUDE_ASM("unk_0806180c/func_080664D8.s");
void* func_080668F0(void) {
    return LoadObjTiles(gUnk_090D4180, 0x5A0);
}
void* func_08066904(void) {
    return LoadObjPalette(gUnk_08F69BE4, 0x20);
}
void func_08066918(void* a, void* b) {
    ReleaseObjTiles(a);
    ReleaseObjPalette(b);
}
INCLUDE_ASM("unk_0806180c/func_0806692C.s");
INCLUDE_ASM("unk_0806180c/func_08066AF8.s");
INCLUDE_ASM("unk_0806180c/func_08066DC0.s");
INCLUDE_ASM("unk_0806180c/func_0806BA0C.s");
INCLUDE_ASM("unk_0806180c/func_0806BA74.s");
INCLUDE_ASM("unk_0806180c/func_0806BB44.s");
INCLUDE_ASM("unk_0806180c/func_0806C2C0.s");
INCLUDE_ASM("unk_0806180c/func_0806C34C.s");
INCLUDE_ASM("unk_0806180c/func_0806CBAC.s");
INCLUDE_ASM("unk_0806180c/func_0806CD30.s");
INCLUDE_ASM("unk_0806180c/func_0806E570.s");
INCLUDE_ASM("unk_0806180c/func_0806E7A8.s");
INCLUDE_ASM("unk_0806180c/func_0806E9BC.s");
INCLUDE_ASM("unk_0806180c/func_0806F94C.s");
INCLUDE_ASM("unk_0806180c/func_0806FE90.s");
INCLUDE_ASM("unk_0806180c/func_08070008.s");
INCLUDE_ASM("unk_0806180c/func_08070058.s");
INCLUDE_ASM("unk_0806180c/func_08072918.s");
INCLUDE_ASM("unk_0806180c/func_08072A64.s");
INCLUDE_ASM("unk_0806180c/func_08072B4C.s");
INCLUDE_ASM("unk_0806180c/func_08073508.s");
INCLUDE_ASM("unk_0806180c/func_080736F8.s");
INCLUDE_ASM("unk_0806180c/func_08073E34.s");
INCLUDE_ASM("unk_0806180c/func_080746D8.s");
void func_08074D00(s32* p) {
    gUnk_02039DC8->unk_50 = p[0];
    gUnk_02039DC8->unk_54 = p[1];
}
INCLUDE_ASM("unk_0806180c/func_08074D14.s");
INCLUDE_ASM("unk_0806180c/func_08074DC4.s");
INCLUDE_ASM("unk_0806180c/func_08074E40.s");
INCLUDE_ASM("unk_0806180c/func_08074E88.s");
INCLUDE_ASM("unk_0806180c/func_08075064.s");
