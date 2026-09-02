#include "macros.h"
#include "gba/syscall.h"
#include "save.h"

extern u16 gUnk_02034088;
extern u16 gUnk_0203408A;
extern u8 gUnk_02034090[];
extern u16 gUnk_03006C78;
extern u8 gUnk_08121724[];
extern u8 gUnk_08121924[];
extern u8 gUnk_08125924[];

void WaitSramErrorInput(void);
void ReadKeysRaw(void);

void ZeroFill(void* dst, s16 size) {
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

void CopyBytes(u8* src, u8* dst, s16 len) {
    s16 i;

    for (i = 0; i < len; i++) {
        dst[i] = src[i];
    }
}

u8 BytesEqual(u8* a, u8* b, s16 len) {
    s16 i;

    for (i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

u16 SaveChecksum(u16* data, int size) {
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

int SaveVerifyBlock(u8* sram, u8* hdr, u8* buf, s16 size) {
    int ret;

    ZeroFill(buf, size);
    ReadSramFast(sram, buf, size);
    
    if (BytesEqual(hdr, gSaveSignature, SAVE_SIGNATURE_SIZE)) {
        ret = (SaveChecksum((u16*)buf, size) == 0) ? SAVE_OK : SAVE_BAD_CHECKSUM;
    } else {
        ret = SAVE_BAD_SIGNATURE;
    }

    return ret;
}

void SaveInitSram(void) {
    SetSramFastFunc();
}

void SaveClearHeader(void) {
    u8* buf;
    s16 i;

    buf = EwramAlloc(SAVE_HEADER_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        ZeroFill(buf, SAVE_HEADER_SIZE);
        WriteAndVerifySramFast(buf, SRAM_HEADER + i * SAVE_HEADER_SIZE, SAVE_HEADER_SIZE);
    }

    EwramFree(buf);
}

int SaveCheckHeaderSlot(s16 slot) {
    u8* buf;
    int ret;

    buf = EwramAlloc(SAVE_HEADER_SIZE);
    ret = SaveVerifyBlock(SRAM_HEADER + (s16)(u16)slot * SAVE_HEADER_SIZE, buf, buf,
                        SAVE_HEADER_SIZE);
    EwramFree(buf);
    return ret;
}

int SaveRepairHeader(void) {
    int results[2];
    int good;
    int bad;
    s16 i;
    int ret;
    u8* buf;
    s64 off;

    good = -1;
    bad = -1;

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = results[i] = SaveCheckHeaderSlot(i);

        if (ret == SAVE_OK) {
            if (good < 0) {
                good = i;
            }
        } else {
            bad = i;
        }
    }

    if (good >= 0 && bad >= 0) {
        buf = EwramAlloc(SAVE_HEADER_SIZE);
        SaveVerifyBlock(SRAM_HEADER + good * SAVE_HEADER_SIZE, buf, buf, SAVE_HEADER_SIZE);

        for (i = 0; i < SAVE_SLOTS; i++) {
            if (results[i] != SAVE_OK) {
                off = i * SAVE_HEADER_SIZE;
                WriteAndVerifySramFast(buf, SRAM_HEADER + off, SAVE_HEADER_SIZE);
            }
        }

        EwramFree(buf);
        ret = SAVE_OK;
    }

    return ret;
}

int SaveLoadHeader(void) {
    u8* buf;
    int ret;
    s16 i;

    ret = 0;
    buf = EwramAlloc(SAVE_HEADER_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = SaveVerifyBlock(SRAM_HEADER + i * SAVE_HEADER_SIZE, buf, buf, SAVE_HEADER_SIZE);

        if (ret == SAVE_OK) {
            ApplySaveHeaderData(&((SaveHeader*)buf)->data);
            break;
        }
    }

    EwramFree(buf);
    return ret;
}

void SaveWriteHeader(s16 slot) {
    SaveHeader* hdr;
    s16 i;

    hdr = EwramAlloc(SAVE_HEADER_SIZE);
    ZeroFill(hdr, SAVE_HEADER_SIZE);
    MakeSaveHeaderData(&hdr->data, (s16)(u16)slot);
    CopyBytes(gSaveSignature, (u8*)hdr, SAVE_SIGNATURE_SIZE);
    hdr->checksum = 0;
    hdr->checksum = SaveChecksum((u16*)hdr, SAVE_HEADER_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        WriteAndVerifySramFast((u8*)hdr, SRAM_HEADER + i * SAVE_HEADER_SIZE, SAVE_HEADER_SIZE);
    }

    EwramFree(hdr);
}

void SaveSetHeaderState(u16 slot, u16 state) {
    SaveHeader* hdr;

    hdr = EwramAlloc(SAVE_HEADER_SIZE);
    ZeroFill(hdr, SAVE_HEADER_SIZE);
    SaveVerifyBlock(SRAM_HEADER + (s16)slot * SAVE_HEADER_SIZE, (u8*)hdr, (u8*)hdr,
                    SAVE_HEADER_SIZE);

    switch ((s16)state) {
    case SAVE_BAD_SIGNATURE:
        hdr->signature[0] = 0;
        break;
    case SAVE_BAD_CHECKSUM:
        CopyBytes(gSaveSignature, (u8*)hdr, SAVE_SIGNATURE_SIZE);
        hdr->checksum = 0;
        hdr->checksum = SaveChecksum((u16*)hdr, SAVE_HEADER_SIZE) + 1;
        break;
    case SAVE_OK:
        CopyBytes(gSaveSignature, (u8*)hdr, SAVE_SIGNATURE_SIZE);
        hdr->checksum = 0;
        hdr->checksum = SaveChecksum((u16*)hdr, SAVE_HEADER_SIZE);
        break;
    }

    WriteAndVerifySramFast((u8*)hdr, SRAM_HEADER + (s16)slot * SAVE_HEADER_SIZE,
                           SAVE_HEADER_SIZE);
    EwramFree(hdr);
}

void SaveClearSystem(void) {
    u8* buf;
    s16 i;

    buf = EwramAlloc(SAVE_SYSTEM_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        ZeroFill(buf, SAVE_SYSTEM_SIZE);
        WriteAndVerifySramFast(buf, SRAM_SYSTEM + i * SAVE_SYSTEM_SIZE, SAVE_SYSTEM_SIZE);
    }

    EwramFree(buf);
}

int SaveCheckSystemSlot(s16 slot) {
    u8* buf;
    int ret;

    buf = EwramAlloc(SAVE_SYSTEM_SIZE);
    ret = SaveVerifyBlock(SRAM_SYSTEM + (s16)(u16)slot * SAVE_SYSTEM_SIZE, buf, buf,
                        SAVE_SYSTEM_SIZE);
    EwramFree(buf);
    return ret;
}

int SaveRepairSystem(void) {
    int results[2];
    int good;
    int bad;
    s16 i;
    int ret;
    u8* buf;

    good = -1;
    bad = -1;

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = results[i] = SaveCheckSystemSlot(i);

        if (ret == SAVE_OK) {
            if (good < 0) {
                good = i;
            }
        } else {
            bad = i;
        }
    }

    if (good >= 0 && bad >= 0) {
        buf = EwramAlloc(SAVE_SYSTEM_SIZE);
        SaveVerifyBlock(SRAM_SYSTEM + good * SAVE_SYSTEM_SIZE, buf, buf, SAVE_SYSTEM_SIZE);

        for (i = 0; i < SAVE_SLOTS; i++) {
            if (results[i] != SAVE_OK) {
                WriteAndVerifySramFast(buf, SRAM_SYSTEM + i * SAVE_SYSTEM_SIZE,
                                       SAVE_SYSTEM_SIZE);
            }
        }

        EwramFree(buf);
        ret = SAVE_OK;
    }
    
    return ret;
}

int SaveLoadSystem(void) {
    u8* buf;
    int ret;
    s16 i;
    s16 slot;

    ret = 0;
    buf = EwramAlloc(SAVE_SYSTEM_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        slot = i;
        ret = SaveVerifyBlock(SRAM_SYSTEM + slot * SAVE_SYSTEM_SIZE, buf, buf, SAVE_SYSTEM_SIZE);

        if (ret == SAVE_OK) {
            ApplySaveSystem(&((SaveBlockLarge*)buf)->data);
            break;
        }
    }

    EwramFree(buf);
    return ret;
}

void SaveWriteSystem(void) {
    SaveBlockLarge* blk;
    s16 i;

    blk = EwramAlloc(SAVE_SYSTEM_SIZE);
    ZeroFill(blk, SAVE_SYSTEM_SIZE);
    MakeSaveSystem(&blk->data);
    CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
    blk->checksum = 0;
    blk->checksum = SaveChecksum((u16*)blk, SAVE_SYSTEM_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        WriteAndVerifySramFast((u8*)blk, SRAM_SYSTEM + i * SAVE_SYSTEM_SIZE, SAVE_SYSTEM_SIZE);
    }

    EwramFree(blk);
}

void SaveSetSystemState(u16 slot, u16 state) {
    SaveBlockLarge* blk;

    blk = EwramAlloc(SAVE_SYSTEM_SIZE);
    ZeroFill(blk, SAVE_SYSTEM_SIZE);
    SaveVerifyBlock(SRAM_SYSTEM + (s16)slot * SAVE_SYSTEM_SIZE, (u8*)blk, (u8*)blk,
                    SAVE_SYSTEM_SIZE);

    switch ((s16)state) {
    case SAVE_BAD_SIGNATURE:
        blk->signature[0] = 0;
        break;
    case SAVE_BAD_CHECKSUM:
        CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
        blk->checksum = 0;
        blk->checksum = SaveChecksum((u16*)blk, SAVE_SYSTEM_SIZE) + 1;
        break;
    case SAVE_OK:
        CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
        blk->checksum = 0;
        blk->checksum = SaveChecksum((u16*)blk, SAVE_SYSTEM_SIZE);
        break;
    }

    WriteAndVerifySramFast((u8*)blk, SRAM_SYSTEM + (s16)slot * SAVE_SYSTEM_SIZE,
                           SAVE_SYSTEM_SIZE);
    EwramFree(blk);
}

void SaveClearFileLarge(u16 file) {
    u8* buf;
    u8* dst;
    s16 i;
    s32 off;

    buf = EwramAlloc(SAVE_FILE_LARGE_SIZE);
    i = 0;
    off = (s16)file * (SAVE_FILE_LARGE_SIZE * 2);

    for (; i < SAVE_SLOTS; i++) {
        ZeroFill(buf, SAVE_FILE_LARGE_SIZE);
        dst = SRAM_FILE_LARGE + i * SAVE_FILE_LARGE_SIZE;
        WriteAndVerifySramFast(buf, dst + off, SAVE_FILE_LARGE_SIZE);
    }

    EwramFree(buf);
}

int SaveCheckFileLargeSlot(s16 file, s16 slot) {
    u8* buf;
    int ret;

    buf = EwramAlloc(SAVE_FILE_LARGE_SIZE);
    ret = SaveVerifyBlock(SRAM_FILE_LARGE + (s16)(u16)file * (SAVE_FILE_LARGE_SIZE * 2)
                            + (s16)(u16)slot * SAVE_FILE_LARGE_SIZE,
                        buf, buf, SAVE_FILE_LARGE_SIZE);
    EwramFree(buf);
    return ret;
}

#ifdef NON_MATCHING
int SaveRepairFileLarge(u16 file) {
    int results[2];
    int good;
    int bad;
    s16 i;
    int ret;
    u8* buf;
    u8* dst;
    s32 off;

    good = -1;
    bad = -1;

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = results[i] = SaveCheckFileLargeSlot((s16)file, i);

        if (ret == SAVE_OK) {
            if (good < 0) {
                good = i;
            }
        } else {
            bad = i;
        }
    }

    if (good >= 0 && bad >= 0) {
        buf = EwramAlloc(SAVE_FILE_LARGE_SIZE);
        off = (s16)file * (SAVE_FILE_LARGE_SIZE * 2);
        dst = SRAM_FILE_LARGE + good * SAVE_FILE_LARGE_SIZE;
        SaveVerifyBlock(off + dst, buf, buf, SAVE_FILE_LARGE_SIZE);

        for (i = 0; i < SAVE_SLOTS; i++) {
            if (results[i] != SAVE_OK) {
                dst = SRAM_FILE_LARGE + i * SAVE_FILE_LARGE_SIZE;
                WriteAndVerifySramFast(buf, off + dst, SAVE_FILE_LARGE_SIZE);
            }
        }

        EwramFree(buf);
        ret = SAVE_OK;
    }

    return ret;
}
#else
INCLUDE_ASM("save/SaveRepairFileLarge.s");
#endif

int SaveLoadFileLarge(u16 file) {
    u8* buf;
    u8* dst;
    int ret;
    s16 i;
    s32 off;

    ret = 0;
    buf = EwramAlloc(SAVE_FILE_LARGE_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        dst = SRAM_FILE_LARGE + i * SAVE_FILE_LARGE_SIZE;
        off = (s16)file * (SAVE_FILE_LARGE_SIZE * 2);
        ret = SaveVerifyBlock(off + dst, buf, buf, SAVE_FILE_LARGE_SIZE);

        if (ret == SAVE_OK) {
            ApplySaveFileLarge(&((SaveBlockLarge*)buf)->data);
            break;
        }
    }

    EwramFree(buf);
    return ret;
}

void SaveWriteFileLarge(u16 file) {
    SaveBlockLarge* blk;
    u8* dst;
    s16 i;
    s32 off;

    blk = EwramAlloc(SAVE_FILE_LARGE_SIZE);
    ZeroFill(blk, SAVE_FILE_LARGE_SIZE);
    MakeSaveFileLarge(&blk->data);
    CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
    blk->checksum = 0;
    blk->checksum = SaveChecksum((u16*)blk, SAVE_FILE_LARGE_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        off = (s16)file * (SAVE_FILE_LARGE_SIZE * 2);
        dst = SRAM_FILE_LARGE + i * SAVE_FILE_LARGE_SIZE;
        WriteAndVerifySramFast((u8*)blk, (u8*)(off + (u32)dst), SAVE_FILE_LARGE_SIZE);
    }

    EwramFree(blk);
    SaveWriteHeader((s16)file);
}

#ifdef NON_MATCHING
void SaveSetFileLargeState(u16 file, u16 slot, u16 state) {
    SaveBlockLarge* blk;

    blk = EwramAlloc(SAVE_FILE_LARGE_SIZE);
    ZeroFill(blk, SAVE_FILE_LARGE_SIZE);
    SaveVerifyBlock(SRAM_FILE_LARGE + (s16)file * (SAVE_FILE_LARGE_SIZE * 2)
                        + (s16)slot * SAVE_FILE_LARGE_SIZE,
                    (u8*)blk, (u8*)blk, SAVE_FILE_LARGE_SIZE);

    switch ((s16)state) {
    case SAVE_BAD_SIGNATURE:
        blk->signature[0] = 0;
        break;
    case SAVE_BAD_CHECKSUM:
        CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
        blk->checksum = 0;
        blk->checksum = SaveChecksum((u16*)blk, SAVE_FILE_LARGE_SIZE) + 1;
        break;
    case SAVE_OK:
        CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
        blk->checksum = 0;
        blk->checksum = SaveChecksum((u16*)blk, SAVE_FILE_LARGE_SIZE);
        break;
    }

    WriteAndVerifySramFast((u8*)blk, SRAM_FILE_LARGE + (s16)file * (SAVE_FILE_LARGE_SIZE * 2)
                               + (s16)slot * SAVE_FILE_LARGE_SIZE,
                           SAVE_FILE_LARGE_SIZE);
    EwramFree(blk);
}
#else
INCLUDE_ASM("save/SaveSetFileLargeState.s");
#endif

void SaveClearFileSmall(u16 file) {
    u8* buf;
    u8* dst;
    s16 i;
    s32 off;

    buf = EwramAlloc(SAVE_FILE_SMALL_SIZE);
    i = 0;
    off = (s16)file * (SAVE_FILE_SMALL_SIZE * 2);

    for (; i < SAVE_SLOTS; i++) {
        ZeroFill(buf, SAVE_FILE_SMALL_SIZE);
        dst = SRAM_FILE_SMALL + i * SAVE_FILE_SMALL_SIZE;
        WriteAndVerifySramFast(buf, dst + off, SAVE_FILE_SMALL_SIZE);
    }
    
    EwramFree(buf);
}

int SaveCheckFileSmallSlot(s16 file, s16 slot) {
    u8* buf;
    int ret;

    buf = EwramAlloc(SAVE_FILE_SMALL_SIZE);
    ret = SaveVerifyBlock(SRAM_FILE_SMALL + (s16)(u16)file * (SAVE_FILE_SMALL_SIZE * 2)
                            + (s16)(u16)slot * SAVE_FILE_SMALL_SIZE,
                        buf, buf, SAVE_FILE_SMALL_SIZE);
    EwramFree(buf);
    return ret;
}

#ifdef NON_MATCHING
int SaveRepairFileSmall(u16 file) {
    int results[2];
    int good;
    int bad;
    s16 i;
    int ret;
    u8* buf;
    u8* dst;
    s32 off;

    good = -1;
    bad = -1;

    for (i = 0; i < SAVE_SLOTS; i++) {
        ret = results[i] = SaveCheckFileSmallSlot((s16)file, i);

        if (ret == SAVE_OK) {
            if (good < 0) {
                good = i;
            }
        } else {
            bad = i;
        }
    }

    if (good >= 0 && bad >= 0) {
        buf = EwramAlloc(SAVE_FILE_SMALL_SIZE);
        off = (s16)file * (SAVE_FILE_SMALL_SIZE * 2);
        dst = SRAM_FILE_SMALL + good * SAVE_FILE_SMALL_SIZE;
        SaveVerifyBlock(off + dst, buf, buf, SAVE_FILE_SMALL_SIZE);

        for (i = 0; i < SAVE_SLOTS; i++) {
            if (results[i] != SAVE_OK) {
                dst = SRAM_FILE_SMALL + i * SAVE_FILE_SMALL_SIZE;
                WriteAndVerifySramFast(buf, off + dst, SAVE_FILE_SMALL_SIZE);
            }
        }

        EwramFree(buf);
        ret = SAVE_OK;
    }

    return ret;
}
#else
INCLUDE_ASM("save/SaveRepairFileSmall.s");
#endif

int SaveLoadFileSmall(u16 file) {
    u8* buf;
    u8* dst;
    int ret;
    s16 i;

    buf = EwramAlloc(SAVE_FILE_SMALL_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        dst = SRAM_FILE_SMALL + i * SAVE_FILE_SMALL_SIZE;
        ret = SaveVerifyBlock((u8*)((s16)file * (SAVE_FILE_SMALL_SIZE * 2) + (u32)dst), buf,
                              buf, SAVE_FILE_SMALL_SIZE);

        if (ret == SAVE_OK) {
            ApplySaveFileSmall(&((SaveBlockSmall*)buf)->data);
            break;
        }
    }

    EwramFree(buf);
    return ret;
}

void SaveWriteFileSmall(u16 file) {
    SaveBlockSmall* blk;
    u8* dst;
    s16 i;
    s32 off;
    s16 f;

    f = file;
    blk = EwramAlloc(SAVE_FILE_SMALL_SIZE);
    ZeroFill(blk, SAVE_FILE_SMALL_SIZE);
    MakeSaveFileSmall(&blk->data);
    CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
    blk->checksum = 0;
    blk->checksum = SaveChecksum((u16*)blk, SAVE_FILE_SMALL_SIZE);

    for (i = 0; i < SAVE_SLOTS; i++) {
        off = f * (SAVE_FILE_SMALL_SIZE * 2);
        dst = SRAM_FILE_SMALL + i * SAVE_FILE_SMALL_SIZE;
        WriteAndVerifySramFast((u8*)blk, (u8*)(off + (u32)dst), SAVE_FILE_SMALL_SIZE);
    }

    EwramFree(blk);
    SaveWriteHeader(f + 2);
}

void SaveSetFileSmallState(u16 file, u16 slot, u16 state) {
    SaveBlockSmall* blk;

    blk = EwramAlloc(SAVE_FILE_SMALL_SIZE);
    ZeroFill(blk, SAVE_FILE_SMALL_SIZE);
    SaveVerifyBlock(SRAM_FILE_SMALL + (s16)file * (SAVE_FILE_SMALL_SIZE * 2)
                        + (s16)slot * SAVE_FILE_SMALL_SIZE,
                    (u8*)blk, (u8*)blk, SAVE_FILE_SMALL_SIZE);

    switch ((s16)state) {
    case SAVE_BAD_SIGNATURE:
        blk->signature[0] = 0;
        break;
    case SAVE_BAD_CHECKSUM:
        CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
        blk->checksum = 0;
        blk->checksum = SaveChecksum((u16*)blk, SAVE_FILE_SMALL_SIZE) + 1;
        break;
    case SAVE_OK:
        CopyBytes(gSaveSignature, (u8*)blk, SAVE_SIGNATURE_SIZE);
        blk->checksum = 0;
        blk->checksum = SaveChecksum((u16*)blk, SAVE_FILE_SMALL_SIZE);
        break;
    }

    WriteAndVerifySramFast((u8*)blk, SRAM_FILE_SMALL + (s16)file * (SAVE_FILE_SMALL_SIZE * 2)
                               + (s16)slot * SAVE_FILE_SMALL_SIZE,
                           SAVE_FILE_SMALL_SIZE);
    EwramFree(blk);
}

void ShowSramErrorScreen(void) {
    vu16* ime;
    vu16* ie;
    vu16* dispstat;
    vu16* dispcnt;
    vu16* p;
    vu32* dma;

    ime = (vu16*)0x04000208;
    *ime = 0;
    ie = (vu16*)0x04000200;
    *ie |= 1;
    dispstat = (vu16*)0x04000004;
    *dispstat |= 8;
    *ime = 1;
    p = (vu16*)0x04000008;
    do {
        *p = 0x88;
    } while (0);
    p += 0x24;
    *p = 0x3FBF;
    p += 2;
    *p = 0x10;
    dispcnt = (vu16*)0x04000000;
    *dispcnt = 0x1100;
    VBlankIntrWait();
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)gUnk_08121924;
    dma[1] = 0x06008000;
    dma[2] = 0x80002000;
    dma[2];
    dma[0] = (u32)gUnk_08121724;
    dma[1] = 0x05000000;
    dma[2] = 0x80000100;
    dma[2];
    dma[0] = (u32)gUnk_08125924;
    dma[1] = (u32)gUnk_02034090;
    dma[2] = 0x80000280;
    dma[2];
    dma[0] = (u32)gUnk_02034090;
    dma[1] = 0x06000000;
    dma[2] = 0x80000400;
    dma[2];
    WaitSramErrorInput();
    *ime = 0;
    *ie &= 0xFFFE;
    *dispstat &= 0xFFF7;
    *ime = 1;
    *dispcnt = 0;
}

void WaitSramErrorInput(void) {
    vu16* bldy;
    vu16* bldy2;
    vu32* dma;
    s32 i;
    u32 j;
    s32 prev;
    s32 cur;
    s32 ok;

    i = 0;
    ok = 0;
    cur = 0;
    prev = 0;
    j = 0;
    bldy = (vu16*)0x04000054;
    do {
        VBlankIntrWait();
        *bldy = 16 - j;
        j++;
    } while (j <= 16);

    if (i <= 19) {
        dma = (vu32*)0x040000D4;
        do {
            ReadKeysRaw();

            if ((((gUnk_0203408A ^ gUnk_02034088) & gUnk_02034088) & 0xF0) == 0xF0) {
                prev = cur;
                cur = i;
            }

            if (prev != 0 && cur - prev <= 3) {
                ok = 1;
            }
            i++;
            VBlankIntrWait();
            dma[0] = (u32)gUnk_02034090;
            dma[1] = 0x06000000;
            dma[2] = 0x84000200;
            dma[2];
        } while (i <= 19);
    }

    j = 0;
    bldy2 = (vu16*)0x04000054;
    do {
        VBlankIntrWait();
        *bldy2 = j;
        j++;
    } while (j <= 16);

    if (ok) {
        gUnk_03006C78 |= 4;
    } else {
        gUnk_03006C78 &= 0xFFFB;
    }
}

void ReadKeysRaw(void) {
    u16 keys = 0x3FF ^ *(vu16*)0x04000130;

    gUnk_0203408A = gUnk_02034088;
    gUnk_02034088 = keys;
}
