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

void* func_08000918(u32 size);
void func_080009C4(void* p);

void func_080089E0(void* dst, s16 size);
void func_08008A24(u8* src, u8* dst, s16 len);
u8 func_08008A54(u8* a, u8* b, s16 len);
u16 func_08008A8C(u16* data, int size);
int func_08008AD8(u8* sram, u8* hdr, u8* buf, s16 size);
void func_08008B40(void);
int func_08008B84(s16 slot);

void func_08059DDC(SaveHeaderData* data, s16 file);
void func_08059F68(SaveFileLarge* data);
void func_0805A048(SaveFileSmall* data);
void func_0805A104(SaveHeaderData* data);

int func_08008C58(void);
void func_08008CA8(s16 slot);
void func_08008DCC(void);
int func_08008E18(s16 slot);
int func_080090F4(s16 file, s16 slot);
int func_08009488(s16 file, s16 slot);

void SetSramFastFunc(void);
u32 WriteAndVerifySramFast(const u8* src, u8* dest, u32 size);

#endif /* GUARD_SAVE_H */
