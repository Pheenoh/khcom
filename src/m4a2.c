#include "m4a.h"
#include "macros.h"

INCLUDE_ASM("m4a2/func_0811F140.s");
INCLUDE_ASM("m4a2/SoundMain.s");
INCLUDE_ASM("m4a2/SoundMainRAM.s");
INCLUDE_ASM("m4a2/MPlayJumpTableCopy.s");
INCLUDE_ASM("m4a2/func_0811F602.s");
INCLUDE_ASM("m4a2/TrackStop.s");
INCLUDE_ASM("m4a2/ply_note.s");
INCLUDE_ASM("m4a2/ply_endtie.s");
INCLUDE_ASM("m4a2/ply_lfos.s");
INCLUDE_ASM("m4a2/ply_mod.s");
INCLUDE_ASM("m4a2/func_0811FD40.s");

#ifdef NON_MATCHING
void MPlayContinue(MusicPlayerInfo* mplayInfo) {
    if (mplayInfo->ident == ID_NUMBER) {
        mplayInfo->ident++;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ID_NUMBER;
    }
}
#else
INCLUDE_ASM("m4a2/MPlayContinue.s");
#endif

#ifdef NON_MATCHING
void MPlayFadeOut(MusicPlayerInfo* mplayInfo, u16 speed) {
    if (mplayInfo->ident == ID_NUMBER) {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = FADE_VOL_MAX << FADE_VOL_SHIFT;
        mplayInfo->ident = ID_NUMBER;
    }
}
#else
INCLUDE_ASM("m4a2/MPlayFadeOut.s");
#endif

void m4aSoundInit(void) {
    s32 i;

    CpuCopy32((void*)((s32)SoundMainRAM & ~1), SoundMainRAM_Buffer, sizeof(SoundMainRAM_Buffer));

    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(SOUND_MODE_DA_BIT_8
               | SOUND_MODE_FREQ_15768
               | (14 << SOUND_MODE_MASVOL_SHIFT)
               | (8 << SOUND_MODE_MAXCHN_SHIFT));

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++) {
        MusicPlayerInfo* mplayInfo = gMPlayTable[i].info;
        MPlayOpen(mplayInfo, gMPlayTable[i].track, gMPlayTable[i].numTracks);
        mplayInfo->unk_B = gMPlayTable[i].unk_A;
        mplayInfo->memAccArea = gMPlayMemAccArea;
    }
}

void m4aSoundMain(void) {
    SoundMain();
}

void m4aSongNumStart(u16 n) {
    const MusicPlayer* mplayTable = gMPlayTable;
    const Song* songTable = gSongTable;
    const Song* song = &songTable[n];
    const MusicPlayer* mplay = &mplayTable[song->ms];

    MPlayStart(mplay->info, song->header);
}

void m4aSongNumStartOrChange(u16 n) {
    const MusicPlayer* mplayTable = gMPlayTable;
    const Song* songTable = gSongTable;
    const Song* song = &songTable[n];
    const MusicPlayer* mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader != song->header) {
        MPlayStart(mplay->info, song->header);
    } else {
        if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0
         || (mplay->info->status & MUSICPLAYER_STATUS_PAUSE)) {
            MPlayStart(mplay->info, song->header);
        }
    }
}

void m4aSongNumStartOrContinue(u16 n) {
    const MusicPlayer* mplayTable = gMPlayTable;
    const Song* songTable = gSongTable;
    const Song* song = &songTable[n];
    const MusicPlayer* mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader != song->header)
        MPlayStart(mplay->info, song->header);
    else if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0)
        MPlayStart(mplay->info, song->header);
    else if (mplay->info->status & MUSICPLAYER_STATUS_PAUSE)
        MPlayContinue(mplay->info);
}

void m4aSongNumStop(u16 n) {
    const MusicPlayer* mplayTable = gMPlayTable;
    const Song* songTable = gSongTable;
    const Song* song = &songTable[n];
    const MusicPlayer* mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader == song->header)
        m4aMPlayStop(mplay->info);
}

void m4aSongNumContinue(u16 n) {
    const MusicPlayer* mplayTable = gMPlayTable;
    const Song* songTable = gSongTable;
    const Song* song = &songTable[n];
    const MusicPlayer* mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader == song->header)
        MPlayContinue(mplay->info);
}

void m4aMPlayAllStop(void) {
    s32 i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        m4aMPlayStop(gMPlayTable[i].info);
}

void m4aMPlayContinue(MusicPlayerInfo* mplayInfo) {
    MPlayContinue(mplayInfo);
}

void m4aMPlayAllContinue(void) {
    s32 i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        MPlayContinue(gMPlayTable[i].info);
}

void m4aMPlayFadeOut(MusicPlayerInfo* mplayInfo, u16 speed) {
    MPlayFadeOut(mplayInfo, speed);
}

#ifdef NON_MATCHING
void m4aMPlayFadeOutTemporarily(MusicPlayerInfo* mplayInfo, u16 speed) {
    if (mplayInfo->ident == ID_NUMBER) {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (FADE_VOL_MAX << FADE_VOL_SHIFT) | TEMPORARY_FADE;
        mplayInfo->ident = ID_NUMBER;
    }
}
#else
INCLUDE_ASM("m4a2/m4aMPlayFadeOutTemporarily.s");
#endif

#ifdef NON_MATCHING
void m4aMPlayFadeIn(MusicPlayerInfo* mplayInfo, u16 speed) {
    if (mplayInfo->ident == ID_NUMBER) {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (0 << FADE_VOL_SHIFT) | FADE_IN;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ID_NUMBER;
    }
}
#else
INCLUDE_ASM("m4a2/m4aMPlayFadeIn.s");
#endif

void m4aMPlayImmInit(MusicPlayerInfo* mplayInfo) {
    s32 trackCount;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    trackCount = mplayInfo->trackCount;
    track = mplayInfo->tracks;

    while (trackCount > 0) {
        if (track->flags & MPT_FLG_EXIST) {
            if (track->flags & MPT_FLG_START) {
                Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 64;
                track->lfoSpeed = 22;
                track->tone.type = 1;
            }
        }

        trackCount--;
        track++;
    }

    mplayInfo->ident = ID_NUMBER;
}

void MPlayExtender(CgbChannel* cgbChans) {
    SoundInfo* soundInfo;
    u32 ident;

    REG_SOUNDCNT_X = 0x8F;
    REG_SOUNDCNT_L = 0;
    REG_NR12 = 0x8;
    REG_NR22 = 0x8;
    REG_NR42 = 0x8;
    REG_NR14 = 0x80;
    REG_NR24 = 0x80;
    REG_NR44 = 0x80;
    REG_NR30 = 0;
    REG_NR50 = 0x77;

    soundInfo = gSoundInfoPtr;

    ident = soundInfo->ident;

    if (ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    gMPlayJumpTable[8] = ply_memacc;
    gMPlayJumpTable[17] = ply_lfos;
    gMPlayJumpTable[19] = ply_mod;
    gMPlayJumpTable[28] = ply_xcmd;
    gMPlayJumpTable[29] = ply_endtie;
    gMPlayJumpTable[30] = SampleFreqSet;
    gMPlayJumpTable[31] = TrackStop;
    gMPlayJumpTable[32] = FadeOutBody;
    gMPlayJumpTable[33] = TrkVolPitSet;

    soundInfo->cgbChans = cgbChans;
    soundInfo->CgbSound = CgbSound;
    soundInfo->CgbOscOff = CgbOscOff;
    soundInfo->MidiKeyToCgbFreq = MidiKeyToCgbFreq;
    soundInfo->maxLines = MAX_LINES;

    CpuFill32(0, cgbChans, sizeof(CgbChannel) * 4);

    cgbChans[0].type = 1;
    cgbChans[0].panMask = 0x11;
    cgbChans[1].type = 2;
    cgbChans[1].panMask = 0x22;
    cgbChans[2].type = 3;
    cgbChans[2].panMask = 0x44;
    cgbChans[3].type = 4;
    cgbChans[3].panMask = 0x88;

    soundInfo->ident = ident;
}

static void MusicPlayerJumpTableCopy(void) {
    asm("swi 0x2A");
}

void ClearChain(void* x) {
    void (*func)(void*) = *(&gMPlayJumpTable[34]);
    func(x);
}

void Clear64byte(void* x) {
    void (*func)(void*) = *(&gMPlayJumpTable[35]);
    func(x);
}

void SoundInit(SoundInfo* soundInfo) {
    soundInfo->ident = 0;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;

    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;

    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = 0x8F;
    REG_SOUNDCNT_H = 0xA90E;
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;

    REG_DMA1SAD = (s32)soundInfo->pcmBuffer;
    REG_DMA1DAD = (s32)&REG_FIFO_A;
    REG_DMA2SAD = (s32)soundInfo->pcmBuffer + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = (s32)&REG_FIFO_B;

    gSoundInfoPtr = soundInfo;
    CpuFill32(0, soundInfo, sizeof(SoundInfo));

    soundInfo->maxChans = 8;
    soundInfo->masterVolume = 15;
    soundInfo->plynote = ply_note;
    soundInfo->CgbSound = DummyFunc;
    soundInfo->CgbOscOff = (CgbOscOffFunc)DummyFunc;
    soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)DummyFunc;
    soundInfo->ExtVolPit = (ExtVolPitFunc)DummyFunc;

    MPlayJumpTableCopy(gMPlayJumpTable);

    soundInfo->MPlayJumpTable = gMPlayJumpTable;

    SampleFreqSet(SOUND_MODE_FREQ_13379);

    soundInfo->ident = ID_NUMBER;
}

void SampleFreqSet(u32 freq) {
    SoundInfo* soundInfo;

    m4aSoundVSyncOff();

    soundInfo = gSoundInfoPtr;
    freq = (freq & SOUND_MODE_FREQ) >> SOUND_MODE_FREQ_SHIFT;
    soundInfo->freq = freq;
    soundInfo->pcmSamplesPerVBlank = gPcmSamplesPerVBlankTable[freq - 1];
    soundInfo->pcmDmaPeriod = PCM_DMA_BUF_SIZE / soundInfo->pcmSamplesPerVBlank;
    soundInfo->pcmFreq = (597275 * soundInfo->pcmSamplesPerVBlank + 5000) / 10000;
    soundInfo->divFreq = (16777216 / soundInfo->pcmFreq + 1) >> 1;

    m4aSoundVSyncOn();
}

void m4aSoundMode(u32 mode) {
    SoundInfo* soundInfo = gSoundInfoPtr;
    u32 temp;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    temp = mode & (SOUND_MODE_REVERB_SET | SOUND_MODE_REVERB_VAL);

    if (temp)
        soundInfo->reverb = temp & SOUND_MODE_REVERB_VAL;

    temp = mode & SOUND_MODE_MAXCHN;

    if (temp) {
        SoundChannel* chan;

        soundInfo->maxChans = temp >> SOUND_MODE_MAXCHN_SHIFT;

        temp = MAX_DIRECTSOUND_CHANNELS;
        chan = &soundInfo->chans[0];

        while (temp != 0) {
            chan->statusFlags = 0;
            temp--;
            chan++;
        }
    }

    temp = mode & SOUND_MODE_MASVOL;

    if (temp)
        soundInfo->masterVolume = temp >> SOUND_MODE_MASVOL_SHIFT;

    temp = mode & SOUND_MODE_DA_BIT;

    if (temp) {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }

    temp = mode & SOUND_MODE_FREQ;

    if (temp)
        SampleFreqSet(temp);

    soundInfo->ident = ID_NUMBER;
}

void SoundClear(void) {
    SoundInfo* soundInfo = gSoundInfoPtr;
    s32 i;
    void* chan;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    i = MAX_DIRECTSOUND_CHANNELS;
    chan = &soundInfo->chans[0];

    while (i > 0) {
        ((SoundChannel*)chan)->statusFlags = 0;
        i--;
        chan = (void*)((s32)chan + sizeof(SoundChannel));
    }

    chan = soundInfo->cgbChans;

    if (chan) {
        i = 1;

        while (i <= 4) {
            soundInfo->CgbOscOff(i);
            ((CgbChannel*)chan)->statusFlags = 0;
            i++;
            chan = (void*)((s32)chan + sizeof(CgbChannel));
        }
    }

    soundInfo->ident = ID_NUMBER;
}

void m4aSoundVSyncOff(void) {
    SoundInfo* soundInfo = gSoundInfoPtr;

    if (soundInfo->ident >= ID_NUMBER && soundInfo->ident <= ID_NUMBER + 1) {
        soundInfo->ident += 10;

        REG_TM0CNT_H = 0;

        if (REG_DMA1CNT & (DMA_REPEAT << 16))
            REG_DMA1CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;

        if (REG_DMA2CNT & (DMA_REPEAT << 16))
            REG_DMA2CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;

        REG_DMA1CNT_H = DMA_32BIT;
        REG_DMA2CNT_H = DMA_32BIT;

        CpuFill32(0, soundInfo->pcmBuffer, sizeof(soundInfo->pcmBuffer));
    }
}

void m4aSoundVSyncOn(void) {
    SoundInfo* soundInfo = gSoundInfoPtr;
    u32 ident = soundInfo->ident;

    if (ident == ID_NUMBER)
        return;

    REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
    REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;

    soundInfo->pcmDmaCounter = 0;
    soundInfo->ident = ident - 10;

    while (REG_VCOUNT == 159)
        ;

    while (REG_VCOUNT != 159)
        ;

    REG_TM0CNT_L = -(280896 / soundInfo->pcmSamplesPerVBlank);
    REG_TM0CNT_H = TIMER_ENABLE;
}

#ifdef NON_MATCHING
void m4aSoundVSync(void) {
    SoundInfo* soundInfo = gSoundInfoPtr;

    if (soundInfo->ident < ID_NUMBER || soundInfo->ident > ID_NUMBER + 1)
        return;

    soundInfo->pcmDmaCounter--;

    if ((s8)soundInfo->pcmDmaCounter > 0)
        return;

    soundInfo->pcmDmaCounter = soundInfo->pcmDmaPeriod;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;

    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;

    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
    REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
}
#else
INCLUDE_ASM("m4a2/m4aSoundVSync.s");
#endif

void MPlayOpen(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* tracks, u8 trackCount) {
    SoundInfo* soundInfo;

    if (trackCount == 0)
        return;

    if (trackCount > MAX_MUSICPLAYER_TRACKS)
        trackCount = MAX_MUSICPLAYER_TRACKS;

    soundInfo = gSoundInfoPtr;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    Clear64byte(mplayInfo);

    mplayInfo->tracks = tracks;
    mplayInfo->trackCount = trackCount;
    mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;

    while (trackCount != 0) {
        tracks->flags = 0;
        trackCount--;
        tracks++;
    }

    if (soundInfo->MPlayMainHead != 0) {
        mplayInfo->MPlayMainNext = soundInfo->MPlayMainHead;
        mplayInfo->musicPlayerNext = soundInfo->musicPlayerHead;
        soundInfo->MPlayMainHead = 0;
    }

    soundInfo->musicPlayerHead = mplayInfo;
    soundInfo->MPlayMainHead = MPlayMain;
    soundInfo->ident = ID_NUMBER;
    mplayInfo->ident = ID_NUMBER;
}

void MPlayStart(MusicPlayerInfo* mplayInfo, SongHeader* songHeader) {
    s32 i;
    u8 unk_B;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    unk_B = mplayInfo->unk_B;

    if (!unk_B
        || ((!mplayInfo->songHeader || !(mplayInfo->tracks[0].flags & MPT_FLG_START))
            && ((mplayInfo->status & MUSICPLAYER_STATUS_TRACK) == 0
                || (mplayInfo->status & MUSICPLAYER_STATUS_PAUSE)))
        || (mplayInfo->priority <= songHeader->priority)) {
        mplayInfo->status = 0;
        mplayInfo->songHeader = songHeader;
        mplayInfo->tone = songHeader->tone;
        mplayInfo->priority = songHeader->priority;
        mplayInfo->clock = 0;
        mplayInfo->tempoD = 150;
        mplayInfo->tempoI = 150;
        mplayInfo->tempoU = 0x100;
        mplayInfo->tempoC = 0;
        mplayInfo->fadeOI = 0;

        i = 0;
        track = mplayInfo->tracks;

        while (i < songHeader->trackCount && i < mplayInfo->trackCount) {
            TrackStop(mplayInfo, track);
            track->flags = MPT_FLG_EXIST | MPT_FLG_START;
            track->chan = 0;
            track->cmdPtr = songHeader->part[i];
            i++;
            track++;
        }

        while (i < mplayInfo->trackCount) {
            TrackStop(mplayInfo, track);
            track->flags = 0;
            i++;
            track++;
        }

        if (songHeader->reverb & SOUND_MODE_REVERB_SET)
            m4aSoundMode(songHeader->reverb);
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayStop(MusicPlayerInfo* mplayInfo) {
    s32 i;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;

    while (i > 0) {
        TrackStop(mplayInfo, track);
        i--;
        track++;
    }

    mplayInfo->ident = ID_NUMBER;
}

void FadeOutBody(MusicPlayerInfo* mplayInfo) {
    s32 i;
    MusicPlayerTrack* track;
    u16 fadeOV;

    if (mplayInfo->fadeOI == 0)
        return;
    if (--mplayInfo->fadeOC != 0)
        return;

    mplayInfo->fadeOC = mplayInfo->fadeOI;

    if (mplayInfo->fadeOV & FADE_IN) {
        if ((u16)(mplayInfo->fadeOV += (4 << FADE_VOL_SHIFT)) >= (64 << FADE_VOL_SHIFT)) {
            mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
            mplayInfo->fadeOI = 0;
        }
    } else {
        if ((s16)(mplayInfo->fadeOV -= (4 << FADE_VOL_SHIFT)) <= 0) {
            i = mplayInfo->trackCount;
            track = mplayInfo->tracks;

            while (i > 0) {
                u32 val;

                TrackStop(mplayInfo, track);

                fadeOV = mplayInfo->fadeOV;
                val = TEMPORARY_FADE;
                val &= fadeOV;

                if (!val)
                    track->flags = 0;

                i--;
                track++;
            }

            if (mplayInfo->fadeOV & TEMPORARY_FADE)
                mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;
            else
                mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;

            mplayInfo->fadeOI = 0;
            return;
        }
    }

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;

    while (i > 0) {
        if (track->flags & MPT_FLG_EXIST) {
            fadeOV = mplayInfo->fadeOV;

            track->volX = (fadeOV >> FADE_VOL_SHIFT);
            track->flags |= MPT_FLG_VOLCHG;
        }

        i--;
        track++;
    }
}

void TrkVolPitSet(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    if (track->flags & MPT_FLG_VOLSET) {
        s32 x;
        s32 y;

        x = (u32)(track->vol * track->volX) >> 5;

        if (track->modT == 1)
            x = (u32)(x * (track->modM + 128)) >> 7;

        y = 2 * track->pan + track->panX;

        if (track->modT == 2)
            y += track->modM;

        if (y < -128)
            y = -128;
        else if (y > 127)
            y = 127;

        track->volMR = (u32)((y + 128) * x) >> 8;
        track->volML = (u32)((127 - y) * x) >> 8;
    }

    if (track->flags & MPT_FLG_PITSET) {
        s32 bend = track->bend * track->bendRange;
        s32 x = (track->tune + bend)
              * 4
              + (track->keyShift << 8)
              + (track->keyShiftX << 8)
              + track->pitX;

        if (track->modT == 0)
            x += 16 * track->modM;

        track->keyM = x >> 8;
        track->pitM = x;
    }

    track->flags &= ~(MPT_FLG_PITSET | MPT_FLG_VOLSET);
}

u32 MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust) {
    if (chanNum == 4) {
        if (key <= 20) {
            key = 0;
        } else {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return gNoiseTable[key];
    } else {
        s32 val1;
        s32 val2;

        if (key <= 35) {
            fineAdjust = 0;
            key = 0;
        } else {
            key -= 36;
            if (key > 130) {
                key = 130;
                fineAdjust = 255;
            }
        }

        val1 = gCgbScaleTable[key];
        val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);

        val2 = gCgbScaleTable[key + 1];
        val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
    }
}

#ifdef NON_MATCHING
void CgbOscOff(u8 chanNum) {
    switch (chanNum) {
    case 1:
        REG_NR12 = 8;
        REG_NR14 = 0x80;
        break;
    case 2:
        REG_NR22 = 8;
        REG_NR24 = 0x80;
        break;
    case 3:
        REG_NR30 = 0;
        break;
    default:
        REG_NR42 = 8;
        REG_NR44 = 0x80;
    }
}
#else
INCLUDE_ASM("m4a2/CgbOscOff.s");
#endif

static inline int CgbPan(CgbChannel* chan) {
    u32 rightVolume = chan->rightVolume;
    u32 leftVolume = chan->leftVolume;

    if ((u8)rightVolume >= (leftVolume = (u8)leftVolume)) {
        if ((u8)rightVolume / 2 >= leftVolume) {
            chan->pan = 0x0F;
            return 1;
        }
    } else {
        if (leftVolume / 2 >= (u8)rightVolume) {
            chan->pan = 0xF0;
            return 1;
        }
    }

    return 0;

}

void CgbModVol(CgbChannel* chan) {
    if (!CgbPan(chan)) {
        chan->pan = 0xFF;
        chan->envelopeGoal = (u32)(chan->rightVolume + chan->leftVolume) / 16;
    } else {
        u32 goal = (u32)(chan->rightVolume + chan->leftVolume) / 16;
        chan->envelopeGoal = goal;
        if (goal > 15)
            chan->envelopeGoal = 15;
    }

    chan->sustainGoal = (chan->envelopeGoal * chan->sustain + 15) >> 4;
    chan->pan &= chan->panMask;
}

INCLUDE_ASM("m4a2/CgbSound.s");

#ifdef NON_MATCHING
void m4aMPlayTempoControl(MusicPlayerInfo* mplayInfo, u16 tempo) {
    if (mplayInfo->ident == ID_NUMBER) {
        mplayInfo->ident++;
        mplayInfo->tempoU = tempo;
        mplayInfo->tempoI = (mplayInfo->tempoD * mplayInfo->tempoU) >> 8;
        mplayInfo->ident = ID_NUMBER;
    }
}
#else
INCLUDE_ASM("m4a2/m4aMPlayTempoControl.s");
#endif

void m4aMPlayVolumeControl(MusicPlayerInfo* mplayInfo, u16 trackBits, u16 volume) {
    s32 i;
    u32 bit;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0) {
        if (trackBits & bit) {
            if (track->flags & MPT_FLG_EXIST) {
                track->volX = volume / 4;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayPitchControl(MusicPlayerInfo* mplayInfo, u16 trackBits, s16 pitch) {
    s32 i;
    u32 bit;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0) {
        if (trackBits & bit) {
            if (track->flags & MPT_FLG_EXIST) {
                track->keyShiftX = pitch >> 8;
                track->pitX = pitch;
                track->flags |= MPT_FLG_PITCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayPanpotControl(MusicPlayerInfo* mplayInfo, u16 trackBits, s8 pan) {
    s32 i;
    u32 bit;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0) {
        if (trackBits & bit) {
            if (track->flags & MPT_FLG_EXIST) {
                track->panX = pan;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

#ifdef NON_MATCHING
void ClearModM(MusicPlayerTrack* track) {
    track->lfoSpeedC = 0;
    track->modM = 0;

    if (track->modT == 0)
        track->flags |= MPT_FLG_PITCHG;
    else
        track->flags |= MPT_FLG_VOLCHG;
}
#else
INCLUDE_ASM("m4a2/ClearModM.s");
#endif

void m4aMPlayModDepthSet(MusicPlayerInfo* mplayInfo, u16 trackBits, u8 modDepth) {
    s32 i;
    u32 bit;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0) {
        if (trackBits & bit) {
            if (track->flags & MPT_FLG_EXIST) {
                track->mod = modDepth;

                if (!track->mod)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayLFOSpeedSet(MusicPlayerInfo* mplayInfo, u16 trackBits, u8 lfoSpeed) {
    s32 i;
    u32 bit;
    MusicPlayerTrack* track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0) {
        if (trackBits & bit) {
            if (track->flags & MPT_FLG_EXIST) {
                track->lfoSpeed = lfoSpeed;

                if (!track->lfoSpeed)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

#define MEMACC_COND_JUMP(cond) \
if (cond)                      \
    goto cond_true;            \
else                           \
    goto cond_false;           \

void ply_memacc(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u32 op;
    u8* addr;
    u8 data;

    op = *track->cmdPtr;
    track->cmdPtr++;

    addr = mplayInfo->memAccArea + *track->cmdPtr;
    track->cmdPtr++;

    data = *track->cmdPtr;
    track->cmdPtr++;

    switch (op) {
    case 0:
        *addr = data;
        return;
    case 1:
        *addr += data;
        return;
    case 2:
        *addr -= data;
        return;
    case 3:
        *addr = mplayInfo->memAccArea[data];
        return;
    case 4:
        *addr += mplayInfo->memAccArea[data];
        return;
    case 5:
        *addr -= mplayInfo->memAccArea[data];
        return;
    case 6:
        MEMACC_COND_JUMP(*addr == data)
        return;
    case 7:
        MEMACC_COND_JUMP(*addr != data)
        return;
    case 8:
        MEMACC_COND_JUMP(*addr > data)
        return;
    case 9:
        MEMACC_COND_JUMP(*addr >= data)
        return;
    case 10:
        MEMACC_COND_JUMP(*addr <= data)
        return;
    case 11:
        MEMACC_COND_JUMP(*addr < data)
        return;
    case 12:
        MEMACC_COND_JUMP(*addr == mplayInfo->memAccArea[data])
        return;
    case 13:
        MEMACC_COND_JUMP(*addr != mplayInfo->memAccArea[data])
        return;
    case 14:
        MEMACC_COND_JUMP(*addr > mplayInfo->memAccArea[data])
        return;
    case 15:
        MEMACC_COND_JUMP(*addr >= mplayInfo->memAccArea[data])
        return;
    case 16:
        MEMACC_COND_JUMP(*addr <= mplayInfo->memAccArea[data])
        return;
    case 17:
        MEMACC_COND_JUMP(*addr < mplayInfo->memAccArea[data])
        return;
    default:
        return;
    }

cond_true:
    {
        (*&gMPlayJumpTable[1])(mplayInfo, track);
        return;
    }

cond_false:
    track->cmdPtr += 4;
}

void ply_xcmd(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u32 n = *track->cmdPtr;
    track->cmdPtr++;
    gXcmdTable[n](mplayInfo, track);
}

void ply_xxx(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    void (*func)(MusicPlayerInfo*, MusicPlayerTrack*) = *(&gMPlayJumpTable[0]);
    func(mplayInfo, track);
}

#define READ_XCMD_BYTE(var, n)      \
{                                   \
    u32 byte = track->cmdPtr[(n)];  \
    byte <<= n * 8;                 \
    (var) &= ~(0xFF << (n * 8));    \
    (var) |= byte;                  \
}

void ply_xwave(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    u32 wav;

    READ_XCMD_BYTE(wav, 0)
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (WaveData*)wav;
    track->cmdPtr += 4;
}

void ply_xtype(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track) {
    track->tone.type = *track->cmdPtr;
    track->cmdPtr++;
}

ALIGN_ZERO(2);
