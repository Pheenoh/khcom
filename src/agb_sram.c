#include "types.h"

#define REG_WAITCNT (*(vu16*)0x4000204)

u16 verifySramFast_Work[80];
u16 readSramFast_Work[64];

extern void (*ReadSramFast)(const u8* src, u8* dest, u32 size);
extern u32 (*VerifySramFast)(const u8* src, u8* dest, u32 size);

void ReadSramFast_Core(const u8* src, u8* dest, u32 size) {
    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;

    while (--size != -1)
        *dest++ = *src++;
}

void WriteSramFast(const u8* src, u8* dest, u32 size) {
    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;

    while (--size != -1)
        *dest++ = *src++;
}

u32 VerifySramFast_Core(const u8* src, u8* dest, u32 size) {
    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;

    while (--size != -1) {
        if (*dest++ != *src++)
            return (u32)(dest - 1);
    }
    return 0;
}

void SetSramFastFunc(void) {
    u16* src;
    u16* dest;
    u16 size;

    src = (u16*)ReadSramFast_Core;
    src = (u16*)((u32)src & ~1);
    dest = readSramFast_Work;
    size = ((u32)WriteSramFast - (u32)ReadSramFast_Core) / 2;

    while (size != 0) {
        *dest++ = *src++;
        size--;
    }

    ReadSramFast = (void*)((u32)readSramFast_Work + 1);

    src = (u16*)VerifySramFast_Core;
    src = (u16*)((u32)src & ~1);
    dest = verifySramFast_Work;
    size = ((u32)SetSramFastFunc - (u32)VerifySramFast_Core) / 2;

    while (size != 0) {
        *dest++ = *src++;
        size--;
    }

    VerifySramFast = (void*)((u32)verifySramFast_Work + 1);

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
}

u32 WriteAndVerifySramFast(const u8* src, u8* dest, u32 size) {
    u8 i;
    u32 errorAddr;

    for (i = 0; i < 3; i++) {
        WriteSramFast(src, dest, size);
        errorAddr = VerifySramFast(src, dest, size);
        
        if (errorAddr == 0)
            break;
    }

    return errorAddr;
}
