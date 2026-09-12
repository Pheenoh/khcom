#ifndef GUARD_SAVE_TYPES_H
#define GUARD_SAVE_TYPES_H

#include "types.h"
#include "card_types.h"

#define SAVE_FILES 4
#define SAVE_CARDS 999
#define SAVE_DECKS 3

typedef struct SaveCommon {
    u32 flags;
    u8 unk_04[0x88];
    u16 unk_8C;
    u16 unk_8E;
    u8 unk_90;
    u8 unk_91;
    u8 unk_92[0x02];
    u32 unk_94;
} SaveCommon;

typedef struct SaveFileSummary {
    u8 floor;
    u8 world;
    u8 level;
    u8 unk_03;
    u32 playTime;
} SaveFileSummary;

typedef struct SaveHeaderData {
    u16 flags;
    u16 unk_02;
    SaveFileSummary files[SAVE_FILES];
} SaveHeaderData;

typedef struct SaveSharedSlice {
    u8 unk_000;
    u8 unk_001;
    u8 unk_002[2];
    u8 unk_004[0x21C];
    u32 unk_220[13];
} SaveSharedSlice;

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

#endif
