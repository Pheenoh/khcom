#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

#include "save_api.h"

#include "types.h"
#include "save_types.h"
#include "malloc.h"
#include "card.h"

extern u8 gSramFileLarge[];

#define SRAM_HEADER ((u8*)0x0E000010)
#define SRAM_SYSTEM ((u8*)0x0E000090)
#define SRAM_FILE_SMALL ((u8*)0x0E001EC0)

#define SAVE_HEADER_SIZE 0x40
#define SAVE_SYSTEM_SIZE 0xF14
#define SAVE_FILE_SMALL_SIZE 0x418
#define SAVE_FILE_LARGE_SIZE 0xF14

#define SAVE_SLOTS 2
#define SAVE_SIGNATURE_SIZE 0x18

extern const u8 gSaveSignatureText[SAVE_SIGNATURE_SIZE + 1];
extern const u8* gSaveSignature;

typedef struct SaveBlockLarge {
    u8 signature[SAVE_SIGNATURE_SIZE];
    u16 checksum;
    u16 unk_1A;
    SaveFileLarge data;
} SaveBlockLarge;

typedef struct SaveBlockSmall {
    u8 signature[SAVE_SIGNATURE_SIZE];
    u16 checksum;
    u16 unk_1A;
    SaveFileSmall data;
} SaveBlockSmall;

typedef struct SaveHeader {
    u8 signature[SAVE_SIGNATURE_SIZE];
    u16 checksum;
    u16 unk_1A;
    SaveHeaderData data;
} SaveHeader;

void ZeroFill(void* dst, s16 size);
void CopyBytes(const u8* src, u8* dst, s16 len);
u8 BytesEqual(const u8* a, const u8* b, s16 len);
u16 SaveChecksum(u16* data, int size);
int SaveVerifyBlock(u8* sram, u8* hdr, u8* buf, s16 size);

void MakeSaveHeaderData(SaveHeaderData* data, s16 file);
void MakeSaveFileLarge(SaveFileLarge* data);
void MakeSaveFileSmall(SaveFileSmall* data);
void ApplySaveHeaderData(SaveHeaderData* data);
void MakeSaveSystem(SaveFileLarge* data);
void ApplySaveSystem(SaveFileLarge* data);
void ApplySaveFileLarge(SaveFileLarge* data);
void ApplySaveFileSmall(SaveFileSmall* data);

void SaveWriteSystem(void);

void SaveWriteFileSmall(u16 file);

#endif /* GUARD_SAVE_H */
