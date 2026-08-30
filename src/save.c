#include "macros.h"
#include "save.h"

void func_080089E0(void* dst, s16 size) {
    u16 zero;
    u16* p;
    vu32* dma;

    if (size & 1) {
        ((u8*)dst)[size - 1] = 0;
    }

    p = &zero;
    *p = 0;
    dma = (vu32*)0x40000D4;
    dma[0] = (u32)p;
    dma[1] = (u32)dst;
    dma[2] = 0x81000000 | (size / 2);
    dma[2];
}

void func_08008A24(u8* src, u8* dst, s16 len) {
    s16 i;

    for (i = 0; i < len; i++) {
        dst[i] = src[i];
    }
}

u8 func_08008A54(u8* a, u8* b, s16 len) {
    s16 i;

    for (i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

u16 func_08008A8C(u16* data, int size) {
    u32 sum;
    s16 len;

    len = size;
    sum = 0;
    while (len > 1) {
        sum += *data++;
        len -= 2;
    }
    if (len > 0) {
        sum += *(u8*)data;
    }
    sum = (sum & 0xFFFF) + (sum >> 16);
    return ~(sum + (sum >> 16));
}

int func_08008AD8(u8* sram, u8* hdr, u8* buf, s16 size) {
    int ret;

    func_080089E0(buf, size);
    ReadSramFast(sram, buf, size);
    
    if (func_08008A54(hdr, gSaveSignature, SAVE_SIGNATURE_SIZE)) {
        ret = (func_08008A8C((u16*)buf, size) == 0) ? SAVE_OK : SAVE_BAD_CHECKSUM;
    } else {
        ret = SAVE_BAD_SIGNATURE;
    }

    return ret;
}

void func_08008B34(void) {
    SetSramFastFunc();
}

void func_08008B40(void) {
    u8* buf;
    s16 i;

    buf = func_08000918(SAVE_HEADER_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        func_080089E0(buf, SAVE_HEADER_SIZE);
        WriteAndVerifySramFast(buf, SRAM_HEADER + i * SAVE_HEADER_SIZE, SAVE_HEADER_SIZE);
    }

    func_080009C4(buf);
}

int func_08008B84(s16 slot) {
    u8* buf;
    int ret;

    buf = func_08000918(SAVE_HEADER_SIZE);
    ret = func_08008AD8(SRAM_HEADER + (s16)(u16)slot * SAVE_HEADER_SIZE, buf, buf,
                        SAVE_HEADER_SIZE);
    func_080009C4(buf);
    return ret;
}

INCLUDE_ASM("save/func_08008BBC.s");

int func_08008C58(void) {
    u8* buf;
    int ret;
    s16 i;

    ret = 0;
    buf = func_08000918(SAVE_HEADER_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = func_08008AD8(SRAM_HEADER + i * SAVE_HEADER_SIZE, buf, buf, SAVE_HEADER_SIZE);
        if (ret == SAVE_OK) {
            func_0805A104(&((SaveHeader*)buf)->data);
            break;
        }
    }

    func_080009C4(buf);
    return ret;
}

void func_08008CA8(s16 slot) {
    SaveHeader* hdr;
    s16 i;

    hdr = func_08000918(SAVE_HEADER_SIZE);
    func_080089E0(hdr, SAVE_HEADER_SIZE);
    func_08059DDC(&hdr->data, (s16)(u16)slot);
    func_08008A24(gSaveSignature, (u8*)hdr, SAVE_SIGNATURE_SIZE);
    hdr->checksum = 0;
    hdr->checksum = func_08008A8C((u16*)hdr, SAVE_HEADER_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        WriteAndVerifySramFast((u8*)hdr, SRAM_HEADER + i * SAVE_HEADER_SIZE, SAVE_HEADER_SIZE);
    }

    func_080009C4(hdr);
}

INCLUDE_ASM("save/func_08008D1C.s");

void func_08008DCC(void) {
    u8* buf;
    s16 i;

    buf = func_08000918(SAVE_SYSTEM_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        func_080089E0(buf, SAVE_SYSTEM_SIZE);
        WriteAndVerifySramFast(buf, SRAM_SYSTEM + i * SAVE_SYSTEM_SIZE, SAVE_SYSTEM_SIZE);
    }

    func_080009C4(buf);
}

int func_08008E18(s16 slot) {
    u8* buf;
    int ret;

    buf = func_08000918(SAVE_SYSTEM_SIZE);
    ret = func_08008AD8(SRAM_SYSTEM + (s16)(u16)slot * SAVE_SYSTEM_SIZE, buf, buf,
                        SAVE_SYSTEM_SIZE);
    func_080009C4(buf);
    return ret;
}

int func_08008E58(void) {
    int results[2];
    int good;
    int bad;
    s16 i;
    int ret;
    u8* buf;

    good = -1;
    bad = -1;

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = results[i] = func_08008E18(i);

        if (ret == SAVE_OK) {
            if (good < 0) {
                good = i;
            }
        } else {
            bad = i;
        }
    }

    if (good >= 0 && bad >= 0) {
        buf = func_08000918(SAVE_SYSTEM_SIZE);
        func_08008AD8(SRAM_SYSTEM + good * SAVE_SYSTEM_SIZE, buf, buf, SAVE_SYSTEM_SIZE);

        for (i = 0; i < SAVE_SLOTS; i++) {
            if (results[i] != SAVE_OK) {
                WriteAndVerifySramFast(buf, SRAM_SYSTEM + i * SAVE_SYSTEM_SIZE,
                                       SAVE_SYSTEM_SIZE);
            }
        }

        func_080009C4(buf);
        ret = SAVE_OK;
    }
    
    return ret;
}

INCLUDE_ASM("save/func_08008F00.s");
void func_08009088(u16 file) {
    u8* buf;
    u8* dst;
    s16 i;
    s32 off;

    buf = func_08000918(SAVE_FILE_LARGE_SIZE);
    i = 0;
    off = (s16)file * (SAVE_FILE_LARGE_SIZE * 2);
    for (; i < SAVE_SLOTS; i++) {
        func_080089E0(buf, SAVE_FILE_LARGE_SIZE);
        dst = SRAM_FILE_LARGE + i * SAVE_FILE_LARGE_SIZE;
        WriteAndVerifySramFast(buf, dst + off, SAVE_FILE_LARGE_SIZE);
    }
    func_080009C4(buf);
}

int func_080090F4(s16 file, s16 slot) {
    u8* buf;
    int ret;

    buf = func_08000918(SAVE_FILE_LARGE_SIZE);
    ret = func_08008AD8(SRAM_FILE_LARGE + (s16)(u16)file * (SAVE_FILE_LARGE_SIZE * 2)
                            + (s16)(u16)slot * SAVE_FILE_LARGE_SIZE,
                        buf, buf, SAVE_FILE_LARGE_SIZE);
    func_080009C4(buf);
    return ret;
}

INCLUDE_ASM("save/func_08009150.s");
INCLUDE_ASM("save/func_08009298.s");
INCLUDE_ASM("save/func_08009330.s");
void func_08009418(u16 file) {
    u8* buf;
    u8* dst;
    s16 i;
    s32 off;

    buf = func_08000918(SAVE_FILE_SMALL_SIZE);
    i = 0;
    off = (s16)file * (SAVE_FILE_SMALL_SIZE * 2);
    for (; i < SAVE_SLOTS; i++) {
        func_080089E0(buf, SAVE_FILE_SMALL_SIZE);
        dst = SRAM_FILE_SMALL + i * SAVE_FILE_SMALL_SIZE;
        WriteAndVerifySramFast(buf, dst + off, SAVE_FILE_SMALL_SIZE);
    }
    func_080009C4(buf);
}

int func_08009488(s16 file, s16 slot) {
    u8* buf;
    int ret;

    buf = func_08000918(SAVE_FILE_SMALL_SIZE);
    ret = func_08008AD8(SRAM_FILE_SMALL + (s16)(u16)file * (SAVE_FILE_SMALL_SIZE * 2)
                            + (s16)(u16)slot * SAVE_FILE_SMALL_SIZE,
                        buf, buf, SAVE_FILE_SMALL_SIZE);
    func_080009C4(buf);
    return ret;
}

INCLUDE_ASM("save/func_080094EC.s");
INCLUDE_ASM("save/func_0800963C.s");
INCLUDE_ASM("save/func_080096D4.s");
