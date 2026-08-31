#ifndef GUARD_M4A_H
#define GUARD_M4A_H

#include "types.h"

#define ID_NUMBER 0x68736D53

#define SOUND_MODE_REVERB_VAL   0x0000007F
#define SOUND_MODE_REVERB_SET   0x00000080
#define SOUND_MODE_MAXCHN       0x00000F00
#define SOUND_MODE_MAXCHN_SHIFT 8
#define SOUND_MODE_MASVOL       0x0000F000
#define SOUND_MODE_MASVOL_SHIFT 12
#define SOUND_MODE_FREQ_13379   0x00040000
#define SOUND_MODE_FREQ_15768   0x00050000
#define SOUND_MODE_FREQ         0x000F0000
#define SOUND_MODE_FREQ_SHIFT   16
#define SOUND_MODE_DA_BIT_8     0x00900000
#define SOUND_MODE_DA_BIT       0x00B00000
#define SOUND_MODE_DA_BIT_SHIFT 20

#define SOUND_CHANNEL_SF_START       0x80
#define SOUND_CHANNEL_SF_STOP        0x40
#define SOUND_CHANNEL_SF_IEC         0x04
#define SOUND_CHANNEL_SF_ENV         0x03
#define SOUND_CHANNEL_SF_ENV_ATTACK  0x03
#define SOUND_CHANNEL_SF_ENV_DECAY   0x02
#define SOUND_CHANNEL_SF_ENV_SUSTAIN 0x01
#define SOUND_CHANNEL_SF_ENV_RELEASE 0x00
#define SOUND_CHANNEL_SF_ON (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_STOP | SOUND_CHANNEL_SF_IEC | SOUND_CHANNEL_SF_ENV)

#define CGB_CHANNEL_MO_PIT 0x02
#define CGB_CHANNEL_MO_VOL 0x01

#define CGB_NRx2_ENV_DIR_DEC 0x00
#define CGB_NRx2_ENV_DIR_INC 0x08

#define TONEDATA_TYPE_FIX 0x08

#define MPT_FLG_VOLSET 0x01
#define MPT_FLG_VOLCHG 0x03
#define MPT_FLG_PITSET 0x04
#define MPT_FLG_PITCHG 0x0C
#define MPT_FLG_START  0x40
#define MPT_FLG_EXIST  0x80

#define MUSICPLAYER_STATUS_TRACK 0x0000FFFF
#define MUSICPLAYER_STATUS_PAUSE 0x80000000

#define MAX_MUSICPLAYER_TRACKS 16
#define MAX_DIRECTSOUND_CHANNELS 12
#define PCM_DMA_BUF_SIZE 1584

#define TEMPORARY_FADE 0x0001
#define FADE_IN        0x0002
#define FADE_VOL_MAX   64
#define FADE_VOL_SHIFT 2

#define NUM_MUSIC_PLAYERS ((u16)gNumMusicPlayers)
#define MAX_LINES ((u32)gMaxLines)

#define REG_VCOUNT      (*(vu8*)0x04000006)
#define REG_NR12        (*(vu8*)0x04000063)
#define REG_NR14        (*(vu8*)0x04000065)
#define REG_NR22        (*(vu8*)0x04000069)
#define REG_NR24        (*(vu8*)0x0400006D)
#define REG_NR30        (*(vu8*)0x04000070)
#define REG_NR42        (*(vu8*)0x04000079)
#define REG_NR44        (*(vu8*)0x0400007D)
#define REG_NR50        (*(vu8*)0x04000080)
#define REG_ADDR_NR10   0x04000060
#define REG_ADDR_NR11   0x04000062
#define REG_ADDR_NR12   0x04000063
#define REG_ADDR_NR13   0x04000064
#define REG_ADDR_NR14   0x04000065
#define REG_ADDR_NR21   0x04000068
#define REG_ADDR_NR22   0x04000069
#define REG_ADDR_NR23   0x0400006C
#define REG_ADDR_NR24   0x0400006D
#define REG_ADDR_NR30   0x04000070
#define REG_ADDR_NR31   0x04000072
#define REG_ADDR_NR32   0x04000073
#define REG_ADDR_NR33   0x04000074
#define REG_ADDR_NR34   0x04000075
#define REG_ADDR_NR41   0x04000078
#define REG_ADDR_NR42   0x04000079
#define REG_ADDR_NR43   0x0400007C
#define REG_ADDR_NR44   0x0400007D
#define REG_NR51        (*(vu8*)0x04000081)
#define REG_WAVE_RAM0   (*(vu32*)0x04000090)
#define REG_WAVE_RAM1   (*(vu32*)0x04000094)
#define REG_WAVE_RAM2   (*(vu32*)0x04000098)
#define REG_WAVE_RAM3   (*(vu32*)0x0400009C)
#define REG_SOUNDCNT_L  (*(vu16*)0x04000080)
#define REG_SOUNDCNT_H  (*(vu16*)0x04000082)
#define REG_SOUNDCNT_X  (*(vu16*)0x04000084)
#define REG_SOUNDBIAS_H (*(vu8*)0x04000089)
#define REG_FIFO_A      (*(vu32*)0x040000A0)
#define REG_FIFO_B      (*(vu32*)0x040000A4)
#define REG_DMA1SAD     (*(vu32*)0x040000BC)
#define REG_DMA1DAD     (*(vu32*)0x040000C0)
#define REG_DMA1CNT     (*(vu32*)0x040000C4)
#define REG_DMA1CNT_H   (*(vu16*)0x040000C6)
#define REG_DMA2SAD     (*(vu32*)0x040000C8)
#define REG_DMA2DAD     (*(vu32*)0x040000CC)
#define REG_DMA2CNT     (*(vu32*)0x040000D0)
#define REG_DMA2CNT_H   (*(vu16*)0x040000D2)
#define REG_TM0CNT_L    (*(vu16*)0x04000100)
#define REG_TM0CNT_H    (*(vu16*)0x04000102)

#define DMA_DEST_FIXED    0x0040
#define DMA_REPEAT        0x0200
#define DMA_32BIT         0x0400
#define DMA_START_SPECIAL 0x3000
#define DMA_ENABLE        0x8000

#define TIMER_ENABLE 0x0080

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

#define CpuCopy32(src, dest, size) CpuSet(src, dest, ((size) / 4) | CPU_SET_32BIT)
#define CpuFill32(value, dest, size)                                              \
{                                                                                 \
    vu32 tmp = (vu32)(value);                                                     \
    CpuSet((void*)&tmp, dest, CPU_SET_32BIT | CPU_SET_SRC_FIXED | ((size) / 4));  \
}

typedef struct WaveData {
    u16 type;
    u16 status;
    u32 freq;
    u32 loopStart;
    u32 size;
    s8 data[1];
} WaveData;

typedef struct ToneData {
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    WaveData* wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
} ToneData;

struct MusicPlayerTrack;

typedef struct CgbChannel {
    u8 statusFlags;
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelopeVolume;
    u8 envelopeGoal;
    u8 envelopeCounter;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    u8 dummy1;
    u8 dummy2;
    u8 gateTime;
    u8 midiKey;
    u8 velocity;
    u8 priority;
    u8 rhythmPan;
    u8 dummy3[3];
    u8 dummy5;
    u8 sustainGoal;
    u8 n4;
    u8 pan;
    u8 panMask;
    u8 modify;
    u8 length;
    u8 sweep;
    u32 frequency;
    u32* wavePointer;
    u32* currentPointer;
    struct MusicPlayerTrack* track;
    void* prevChannelPointer;
    void* nextChannelPointer;
    u8 dummy4[8];
} CgbChannel;

typedef struct SoundChannel {
    u8 statusFlags;
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelopeVolume;
    u8 envelopeVolumeRight;
    u8 envelopeVolumeLeft;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    u8 dummy1;
    u8 dummy2;
    u8 gateTime;
    u8 midiKey;
    u8 velocity;
    u8 priority;
    u8 rhythmPan;
    u8 dummy3[3];
    u32 count;
    u32 fw;
    u32 frequency;
    WaveData* wav;
    s8* currentPointer;
    struct MusicPlayerTrack* track;
    void* prevChannelPointer;
    void* nextChannelPointer;
    u32 dummy4;
    u16 xpi;
    u16 xpc;
} SoundChannel;

struct MusicPlayerInfo;

typedef void (*MPlayFunc)();
typedef void (*PlyNoteFunc)(u32, struct MusicPlayerInfo*, struct MusicPlayerTrack*);
typedef void (*CgbSoundFunc)(void);
typedef void (*CgbOscOffFunc)(u8);
typedef u32 (*MidiKeyToCgbFreqFunc)(u8, u8, u8);
typedef void (*ExtVolPitFunc)(void);
typedef void (*MPlayMainFunc)(struct MusicPlayerInfo*);
typedef void (*XcmdFunc)(struct MusicPlayerInfo*, struct MusicPlayerTrack*);

typedef struct SoundInfo {
    u32 ident;
    vu8 pcmDmaCounter;
    u8 reverb;
    u8 maxChans;
    u8 masterVolume;
    u8 freq;
    u8 mode;
    u8 c15;
    u8 pcmDmaPeriod;
    u8 maxLines;
    u8 gap[3];
    s32 pcmSamplesPerVBlank;
    s32 pcmFreq;
    s32 divFreq;
    CgbChannel* cgbChans;
    MPlayMainFunc MPlayMainHead;
    struct MusicPlayerInfo* musicPlayerHead;
    CgbSoundFunc CgbSound;
    CgbOscOffFunc CgbOscOff;
    MidiKeyToCgbFreqFunc MidiKeyToCgbFreq;
    MPlayFunc* MPlayJumpTable;
    PlyNoteFunc plynote;
    ExtVolPitFunc ExtVolPit;
    u8 gap2[16];
    SoundChannel chans[MAX_DIRECTSOUND_CHANNELS];
    s8 pcmBuffer[PCM_DMA_BUF_SIZE * 2];
} SoundInfo;

typedef struct SongHeader {
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    ToneData* tone;
    u8* part[1];
} SongHeader;

typedef struct MusicPlayerTrack {
    u8 flags;
    u8 wait;
    u8 patternLevel;
    u8 repN;
    u8 gateTime;
    u8 key;
    u8 velocity;
    u8 runningStatus;
    u8 keyM;
    u8 pitM;
    s8 keyShift;
    s8 keyShiftX;
    s8 tune;
    u8 pitX;
    s8 bend;
    u8 bendRange;
    u8 volMR;
    u8 volML;
    u8 vol;
    u8 volX;
    s8 pan;
    s8 panX;
    s8 modM;
    u8 mod;
    u8 modT;
    u8 lfoSpeed;
    u8 lfoSpeedC;
    u8 lfoDelay;
    u8 lfoDelayC;
    u8 priority;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    SoundChannel* chan;
    ToneData tone;
    u8 gap[10];
    u16 timer;
    u32 unk_3C;
    u8* cmdPtr;
    u8* patternStack[3];
} MusicPlayerTrack;

typedef struct MusicPlayerInfo {
    SongHeader* songHeader;
    u32 status;
    u8 trackCount;
    u8 priority;
    u8 cmd;
    u8 unk_B;
    u32 clock;
    u8 gap[8];
    u8* memAccArea;
    u16 tempoD;
    u16 tempoU;
    u16 tempoI;
    u16 tempoC;
    u16 fadeOI;
    u16 fadeOC;
    u16 fadeOV;
    MusicPlayerTrack* tracks;
    ToneData* tone;
    u32 ident;
    MPlayMainFunc MPlayMainNext;
    struct MusicPlayerInfo* musicPlayerNext;
} MusicPlayerInfo;

typedef struct MusicPlayer {
    MusicPlayerInfo* info;
    MusicPlayerTrack* track;
    u8 numTracks;
    u16 unk_A;
} MusicPlayer;

typedef struct Song {
    SongHeader* header;
    u16 ms;
    u16 me;
} Song;

extern const MusicPlayer gMPlayTable[];
extern const Song gSongTable[];
extern MPlayFunc gMPlayJumpTable[];
extern const XcmdFunc gXcmdTable[];
extern CgbChannel gCgbChans[];
extern SoundInfo gSoundInfo;
extern u8 gMPlayMemAccArea[];
extern const u16 gPcmSamplesPerVBlankTable[];
extern const u8 gCgbScaleTable[];
extern const s16 gCgbFreqTable[];
extern const u8 gNoiseTable[];
extern const u8 gCgb3Vol[];
extern char SoundMainRAM[];
extern char SoundMainRAM_Buffer[0x400];
extern char gNumMusicPlayers[];
extern char gMaxLines[];
extern SoundInfo* gSoundInfoPtr;

void CpuSet(void* src, void* dst, u32 ctrl);

void SoundMain(void);
void MPlayMain(MusicPlayerInfo* mplayInfo);
void MPlayJumpTableCopy(MPlayFunc* mplayJumpTable);
void TrackStop(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_note(u32 noteCmd, MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_endtie(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_lfos(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_mod(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_memacc(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xcmd(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void DummyFunc(void);

void MPlayContinue(MusicPlayerInfo* mplayInfo);
void MPlayFadeOut(MusicPlayerInfo* mplayInfo, u16 speed);
void m4aSoundInit(void);
void m4aSoundMain(void);
void m4aSongNumStart(u16 n);
void m4aSongNumStartOrChange(u16 n);
void m4aSongNumStartOrContinue(u16 n);
void m4aSongNumStop(u16 n);
void m4aSongNumContinue(u16 n);
void m4aMPlayAllStop(void);
void m4aMPlayContinue(MusicPlayerInfo* mplayInfo);
void m4aMPlayAllContinue(void);
void m4aMPlayFadeOut(MusicPlayerInfo* mplayInfo, u16 speed);
void m4aMPlayFadeOutTemporarily(MusicPlayerInfo* mplayInfo, u16 speed);
void m4aMPlayFadeIn(MusicPlayerInfo* mplayInfo, u16 speed);
void m4aMPlayImmInit(MusicPlayerInfo* mplayInfo);
void MPlayExtender(CgbChannel* cgbChans);
void ClearChain(void* x);
void Clear64byte(void* x);
void SoundInit(SoundInfo* soundInfo);
void SampleFreqSet(u32 freq);
void m4aSoundMode(u32 mode);
void SoundClear(void);
void m4aSoundVSyncOff(void);
void m4aSoundVSyncOn(void);
void m4aSoundVSync(void);
void MPlayOpen(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* tracks, u8 trackCount);
void MPlayStart(MusicPlayerInfo* mplayInfo, SongHeader* songHeader);
void m4aMPlayStop(MusicPlayerInfo* mplayInfo);
void FadeOutBody(MusicPlayerInfo* mplayInfo);
void TrkVolPitSet(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
u32 MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust);
void CgbOscOff(u8 chanNum);
void CgbModVol(CgbChannel* chan);
void CgbSound(void);
void m4aMPlayTempoControl(MusicPlayerInfo* mplayInfo, u16 tempo);
void m4aMPlayVolumeControl(MusicPlayerInfo* mplayInfo, u16 trackBits, u16 volume);
void m4aMPlayPitchControl(MusicPlayerInfo* mplayInfo, u16 trackBits, s16 pitch);
void m4aMPlayPanpotControl(MusicPlayerInfo* mplayInfo, u16 trackBits, s8 pan);
void ClearModM(MusicPlayerTrack* track);
void m4aMPlayModDepthSet(MusicPlayerInfo* mplayInfo, u16 trackBits, u8 modDepth);
void m4aMPlayLFOSpeedSet(MusicPlayerInfo* mplayInfo, u16 trackBits, u8 lfoSpeed);

#endif /* GUARD_M4A_H */
