#include "macros.h"
#include "engine.h"
#include "types.h"

INCLUDE_ASM("engine/func_0800216C.s");
INCLUDE_ASM("engine/func_080022D4.s");
INCLUDE_ASM("engine/DrawSprite.s");
INCLUDE_ASM("engine/func_08002488.s");
INCLUDE_ASM("engine/LoadObjTiles.s");
INCLUDE_ASM("engine/func_0800284C.s");
INCLUDE_ASM("engine/func_08002880.s");
INCLUDE_ASM("engine/func_080028A0.s");
INCLUDE_ASM("engine/ReleaseObjTiles.s");
INCLUDE_ASM("engine/AllocObjTiles.s");
INCLUDE_ASM("engine/func_08002A10.s");
INCLUDE_ASM("engine/LoadObjPalette.s");
INCLUDE_ASM("engine/LoadObjPaletteBank.s");
INCLUDE_ASM("engine/func_08002BCC.s");

void ReleaseObjPalette(u8* p) {
    if (p != 0 && *(u8**)(p + 36) == p) {
        func_08002BCC(p);
    }
}

INCLUDE_ASM("engine/func_08002C28.s");
INCLUDE_ASM("engine/AllocObjAffine.s");
INCLUDE_ASM("engine/func_08002F50.s");
INCLUDE_ASM("engine/func_080034D8.s");
INCLUDE_ASM("engine/func_080034EC.s");
INCLUDE_ASM("engine/func_08003524.s");
INCLUDE_ASM("engine/func_08003598.s");
INCLUDE_ASM("engine/func_080035CC.s");
INCLUDE_ASM("engine/func_0800380C.s");
INCLUDE_ASM("engine/func_0800388C.s");
INCLUDE_ASM("engine/func_080038C8.s");
INCLUDE_ASM("engine/func_080038E4.s");
INCLUDE_ASM("engine/func_08003970.s");
INCLUDE_ASM("engine/func_08003A70.s");
INCLUDE_ASM("engine/func_08003A98.s");
INCLUDE_ASM("engine/func_08003B24.s");
INCLUDE_ASM("engine/func_08003C9C.s");
INCLUDE_ASM("engine/func_08003CD4.s");
INCLUDE_ASM("engine/func_08003E2C.s");
INCLUDE_ASM("engine/func_08004034.s");
INCLUDE_ASM("engine/func_0800415C.s");
INCLUDE_ASM("engine/func_08004314.s");
INCLUDE_ASM("engine/func_08004364.s");
INCLUDE_ASM("engine/RequestDma3Copy.s");
INCLUDE_ASM("engine/func_0800443C.s");
INCLUDE_ASM("engine/func_0800448C.s");
INCLUDE_ASM("engine/func_080045AC.s");
INCLUDE_ASM("engine/func_080046C8.s");
INCLUDE_ASM("engine/func_08004938.s");
INCLUDE_ASM("engine/func_08004B8C.s");
INCLUDE_ASM("engine/func_08004BD8.s");
INCLUDE_ASM("engine/func_08004C20.s");
INCLUDE_ASM("engine/func_08004D74.s");
INCLUDE_ASM("engine/func_08004DB0.s");
INCLUDE_ASM("engine/func_08004E64.s");
INCLUDE_ASM("engine/func_08004F08.s");
INCLUDE_ASM("engine/func_08004FC8.s");
INCLUDE_ASM("engine/func_0800501C.s");
INCLUDE_ASM("engine/SetupBg.s");
INCLUDE_ASM("engine/LoadBgTiles.s");
INCLUDE_ASM("engine/LoadBgPalette.s");

void LoadBgMap(s32 bg, void* src, u16 size) {
    func_08004FC8(bg);
    RequestDma3Copy(src, GetBgScreenBase(bg), size);
}

INCLUDE_ASM("engine/GetBgCharBase.s");
INCLUDE_ASM("engine/GetBgScreenBase.s");
INCLUDE_ASM("engine/func_0800516C.s");
INCLUDE_ASM("engine/func_080051C4.s");
INCLUDE_ASM("engine/func_08005244.s");
INCLUDE_ASM("engine/func_08005490.s");
INCLUDE_ASM("engine/func_080054C8.s");
INCLUDE_ASM("engine/SetBgScroll.s");
INCLUDE_ASM("engine/func_08005550.s");
INCLUDE_ASM("engine/func_0800558C.s");
INCLUDE_ASM("engine/SetBgPriority.s");
INCLUDE_ASM("engine/func_080055EC.s");
INCLUDE_ASM("engine/func_08005610.s");
INCLUDE_ASM("engine/func_08005654.s");
INCLUDE_ASM("engine/func_08005690.s");
INCLUDE_ASM("engine/func_08005778.s");
INCLUDE_ASM("engine/func_080057A0.s");
INCLUDE_ASM("engine/func_08005810.s");
INCLUDE_ASM("engine/func_08005824.s");
INCLUDE_ASM("engine/func_0800589C.s");

void func_080058FC(s32* value, s32 target, u16 steps) {
    s32 cur;
    s32 delta;

    cur = *value;
    delta = target - cur;

    if (steps == 0) {
        steps = 1;
    }

    *value = cur + delta / steps;
}

INCLUDE_ASM("engine/func_08005920.s");
INCLUDE_ASM("engine/func_0800592C.s");

void AnimInit(AnimState* a, s32 b, s32 c) {
    a->unk_04 = (u32*)c;
    a->unk_00 = b;
    a->unk_14 = 0;
}

INCLUDE_ASM("engine/func_08005974.s");
INCLUDE_ASM("engine/AnimStart.s");
INCLUDE_ASM("engine/AnimChange.s");
INCLUDE_ASM("engine/AnimUpdate.s");
INCLUDE_ASM("engine/func_08005AC4.s");

void* AnimGetGfx(AnimState* a) {
    void* result;

    if (a->unk_14 != 0) {
        result = (void*)a->unk_04[a->unk_14[a->unk_0E].unk_00];
    } else {
        result = 0;
    }

    return result;
}

u8 AnimIsFinished(AnimState* a) {
    if (a->unk_08 & 0x1000) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("engine/func_08005B30.s");
INCLUDE_ASM("engine/func_08005B34.s");
INCLUDE_ASM("engine/func_08005B38.s");
INCLUDE_ASM("engine/func_08005B44.s");
INCLUDE_ASM("engine/func_08005B64.s");
INCLUDE_ASM("engine/func_08005B78.s");
INCLUDE_ASM("engine/func_08005BC4.s");
INCLUDE_ASM("engine/LoadPalette.s");
INCLUDE_ASM("engine/func_08005C60.s");
INCLUDE_ASM("engine/func_08006120.s");
INCLUDE_ASM("engine/func_08006184.s");
INCLUDE_ASM("engine/func_080061E8.s");
INCLUDE_ASM("engine/func_08006238.s");
INCLUDE_ASM("engine/func_08006290.s");
INCLUDE_ASM("engine/func_080062F4.s");
INCLUDE_ASM("engine/func_08006314.s");
INCLUDE_ASM("engine/_08006338.s");
INCLUDE_ASM("engine/func_08006390.s");
INCLUDE_ASM("engine/func_080063A8.s");
INCLUDE_ASM("engine/func_080063C4.s");
INCLUDE_ASM("engine/func_08006404.s");
INCLUDE_ASM("engine/func_08006494.s");
INCLUDE_ASM("engine/SeedRand.s");
INCLUDE_ASM("engine/Rand.s");
INCLUDE_ASM("engine/SeedRandom.s");
INCLUDE_ASM("engine/GetRandom.s");
INCLUDE_ASM("engine/func_080065FC.s");
INCLUDE_ASM("engine/func_080066F4.s");
INCLUDE_ASM("engine/func_0800675C.s");
INCLUDE_ASM("engine/func_08006778.s");
INCLUDE_ASM("engine/func_0800685C.s");
INCLUDE_ASM("engine/func_08006954.s");
INCLUDE_ASM("engine/func_08006B34.s");
INCLUDE_ASM("engine/func_08006B4C.s");
