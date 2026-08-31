#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

#include "types.h"
#include "card.h"

#define SRAM_HEADER ((u8*)0x0E000010)
#define SRAM_SYSTEM ((u8*)0x0E000090)
#define SRAM_FILE_SMALL ((u8*)0x0E001EC0)
#define SRAM_FILE_LARGE ((u8*)0x0E002F20)

#define SAVE_HEADER_SIZE 0x40
#define SAVE_SYSTEM_SIZE 0xF14
#define SAVE_FILE_SMALL_SIZE 0x418
#define SAVE_FILE_LARGE_SIZE 0xF14

#define SAVE_SLOTS 2
#define SAVE_SIGNATURE_SIZE 0x18

#define SAVE_BAD_SIGNATURE 0
#define SAVE_BAD_CHECKSUM 1
#define SAVE_OK 2

#define ReadSramFast (*(void (**)(const u8* src, u8* dest, u32 size))0x0203C7BC)
#define gSaveSignature (*(u8**)0x09EDB7E8)

#define SAVE_FILES 4

typedef struct SaveFileSummary {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
} SaveFileSummary;

typedef struct SaveHeaderData {
    u16 flags;
    u16 unk_02;
    SaveFileSummary files[SAVE_FILES];
} SaveHeaderData;

typedef struct SaveCommon {
    u32 flags;
    u8 unk_04[0x88];
    u16 unk_8C;
    u16 unk_8E;
    u8 unk_90;
    u8 unk_91;
    u8 unk_92[2];
    u32 unk_94;
} SaveCommon;

typedef struct SaveSharedSlice {
    u8 unk_000;
    u8 unk_001;
    u8 unk_002[2];
    u8 unk_004[0x21C];
    u32 unk_220[13];
} SaveSharedSlice;

#define SAVE_CARDS 999
#define SAVE_DECKS 3

typedef struct SaveLargeSlice {
    u8 unk_000;
    u8 unk_001[0x10E];
    u8 unk_10F;
    u16 cards[SAVE_CARDS];
    u16 cardCount;
    Deck decks[SAVE_DECKS];
} SaveLargeSlice;

typedef struct SaveSmallSlice {
    u8 unk_000[0x10E];
    u8 unk_10E[2];
} SaveSmallSlice;

typedef struct SaveSliceE6C {
    u16 unk_00;
    u16 unk_02;
} SaveSliceE6C;

typedef struct SaveSliceEB4 {
    u16 unk_00[32];
    u16 unk_40[2];
} SaveSliceEB4;

typedef struct SaveFileLarge {
    SaveCommon common;
    SaveSharedSlice unk_098;
    SaveLargeSlice unk_2EC;
    SaveSliceE6C unk_E6C;
    u8 unk_E70[0x044];
    SaveSliceEB4 unk_EB4;
} SaveFileLarge;

typedef struct SaveFileSmall {
    SaveCommon common;
    SaveSharedSlice unk_098;
    SaveSmallSlice unk_2EC;
} SaveFileSmall;

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

void* EwramAlloc(u32 size);
void EwramFree(void* p);

void ZeroFill(void* dst, s16 size);
void CopyBytes(u8* src, u8* dst, s16 len);
u8 BytesEqual(u8* a, u8* b, s16 len);
u16 SaveChecksum(u16* data, int size);
int SaveVerifyBlock(u8* sram, u8* hdr, u8* buf, s16 size);
void SaveClearHeader(void);
int SaveCheckHeaderSlot(s16 slot);

void MakeSaveHeaderData(SaveHeaderData* data, s16 file);
void MakeSaveFileLarge(SaveFileLarge* data);
void MakeSaveFileSmall(SaveFileSmall* data);
void ApplySaveHeaderData(SaveHeaderData* data);
void MakeSaveSystem(SaveFileLarge* data);
void ApplySaveSystem(SaveFileLarge* data);
void ApplySaveFileLarge(SaveFileLarge* data);
void ApplySaveFileSmall(SaveFileSmall* data);

int SaveLoadHeader(void);
void SaveWriteHeader(s16 slot);
void SaveSetHeaderState(u16 slot, u16 state);
void SaveClearSystem(void);
int SaveCheckSystemSlot(s16 slot);
int SaveRepairSystem(void);
int SaveLoadSystem(void);
void SaveWriteSystem(void);
void SaveSetSystemState(u16 slot, u16 state);
void SaveClearFileLarge(u16 file);
int SaveCheckFileLargeSlot(s16 file, s16 slot);
int SaveRepairFileLarge(u16 file);
int SaveLoadFileLarge(u16 file);
void SaveWriteFileLarge(u16 file);
void SaveSetFileLargeState(u16 file, u16 slot, u16 state);
void SaveClearFileSmall(u16 file);
int SaveCheckFileSmallSlot(s16 file, s16 slot);
int SaveRepairFileSmall(u16 file);
int SaveLoadFileSmall(u16 file);
void SaveWriteFileSmall(u16 file);
void SaveSetFileSmallState(u16 file, u16 slot, u16 state);

void SetSramFastFunc(void);
u32 WriteAndVerifySramFast(const u8* src, u8* dest, u32 size);

#endif /* GUARD_SAVE_H */
