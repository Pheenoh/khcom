	.set PSR_IRQ_MODE, 0x12
	.set PSR_SYS_MODE, 0x1F
	.set PSR_MODE_MASK, 0xDF
	.set PSR_I_BIT, 0x80

	.set REG_BASE, 0x04000000
	.set OFFSET_REG_SOUNDCNT_X, 0x84
	.set OFFSET_REG_IE, 0x200
	.set OFFSET_REG_IF, 0x202
	.set OFFSET_REG_IME, 0x208

	.set IWRAM_END, 0x03008000
	.set INTR_VECTOR, 0x03007FFC
	.set INTR_TABLE, 0x03006C20

	.set INTR_FLAG_VBLANK, 1 << 0
	.set INTR_FLAG_HBLANK, 1 << 1
	.set INTR_FLAG_VCOUNT, 1 << 2
	.set INTR_FLAG_TIMER0, 1 << 3
	.set INTR_FLAG_TIMER1, 1 << 4
	.set INTR_FLAG_TIMER2, 1 << 5
	.set INTR_FLAG_TIMER3, 1 << 6
	.set INTR_FLAG_SERIAL, 1 << 7
	.set INTR_FLAG_DMA0, 1 << 8
	.set INTR_FLAG_DMA1, 1 << 9
	.set INTR_FLAG_DMA2, 1 << 10
	.set INTR_FLAG_DMA3, 1 << 11
	.set INTR_FLAG_KEYPAD, 1 << 12
	.set INTR_FLAG_GAMEPAK, 1 << 13

	.set ID_NUMBER, 0x68736D53
	.set SOUND_INFO_PTR, 0x03007FF0
	.set PCM_DMA_BUF_SIZE, 1584
	.set TOTAL_SCANLINES, 228
	.set VCOUNT_VBLANK, 160

	.set OFFSET_REG_VCOUNT, 0x006
	.set OFFSET_REG_SOUND1CNT_L, 0x060
	.set OFFSET_REG_DMA1, 0x0BC
	.set REG_VCOUNT, REG_BASE + OFFSET_REG_VCOUNT
	.set REG_SOUND1CNT_L, REG_BASE + OFFSET_REG_SOUND1CNT_L
	.set REG_DMA1, REG_BASE + OFFSET_REG_DMA1

	.set DMA_SRC_INC, 0x0000
	.set DMA_DEST_FIXED, 0x0040
	.set DMA_REPEAT, 0x0200
	.set DMA_32BIT, 0x0400
	.set DMA_START_NOW, 0x0000
	.set DMA_START_SPECIAL, 0x3000
	.set DMA_ENABLE, 0x8000

	.set TONEDATA_TYPE_SPL, 0x40
	.set TONEDATA_TYPE_RHY, 0x80

	.set o_SoundInfo_ident, 0
	.set o_SoundInfo_pcmDmaCounter, 4
	.set o_SoundInfo_reverb, 5
	.set o_SoundInfo_maxChans, 6
	.set o_SoundInfo_masterVolume, 7
	.set o_SoundInfo_freq, 8
	.set o_SoundInfo_mode, 9
	.set o_SoundInfo_c15, 10
	.set o_SoundInfo_pcmDmaPeriod, 11
	.set o_SoundInfo_maxLines, 12
	.set o_SoundInfo_pcmSamplesPerVBlank, 16
	.set o_SoundInfo_pcmFreq, 20
	.set o_SoundInfo_divFreq, 24
	.set o_SoundInfo_cgbChans, 28
	.set o_SoundInfo_MPlayMainHead, 32
	.set o_SoundInfo_musicPlayerHead, 36
	.set o_SoundInfo_CgbSound, 40
	.set o_SoundInfo_CgbOscOff, 44
	.set o_SoundInfo_MidiKeyToCgbFreq, 48
	.set o_SoundInfo_MPlayJumpTable, 52
	.set o_SoundInfo_plynote, 56
	.set o_SoundInfo_ExtVolPit, 60
	.set o_SoundInfo_chans, 80
	.set o_SoundInfo_pcmBuffer, 848

	.set o_SoundChannel_statusFlags, 0
	.set o_SoundChannel_type, 1
	.set o_SoundChannel_rightVolume, 2
	.set o_SoundChannel_leftVolume, 3
	.set o_SoundChannel_attack, 4
	.set o_SoundChannel_decay, 5
	.set o_SoundChannel_sustain, 6
	.set o_SoundChannel_release, 7
	.set o_SoundChannel_key, 8
	.set o_SoundChannel_envelopeVolume, 9
	.set o_SoundChannel_envelopeVolumeRight, 10
	.set o_SoundChannel_envelopeVolumeLeft, 11
	.set o_SoundChannel_pseudoEchoVolume, 12
	.set o_SoundChannel_pseudoEchoLength, 13
	.set o_SoundChannel_gateTime, 16
	.set o_SoundChannel_midiKey, 17
	.set o_SoundChannel_velocity, 18
	.set o_SoundChannel_priority, 19
	.set o_SoundChannel_rhythmPan, 20
	.set o_SoundChannel_count, 24
	.set o_SoundChannel_fw, 28
	.set o_SoundChannel_frequency, 32
	.set o_SoundChannel_wav, 36
	.set o_SoundChannel_currentPointer, 40
	.set o_SoundChannel_track, 44
	.set o_SoundChannel_prevChannelPointer, 48
	.set o_SoundChannel_nextChannelPointer, 52
	.set SoundChannel_size, 64

	.set o_CgbChannel_frequency, 32
	.set o_CgbChannel_modify, 29

	.set o_MusicPlayerTrack_flags, 0
	.set o_MusicPlayerTrack_wait, 1
	.set o_MusicPlayerTrack_patternLevel, 2
	.set o_MusicPlayerTrack_repN, 3
	.set o_MusicPlayerTrack_gateTime, 4
	.set o_MusicPlayerTrack_key, 5
	.set o_MusicPlayerTrack_velocity, 6
	.set o_MusicPlayerTrack_runningStatus, 7
	.set o_MusicPlayerTrack_keyM, 8
	.set o_MusicPlayerTrack_pitM, 9
	.set o_MusicPlayerTrack_keyShift, 10
	.set o_MusicPlayerTrack_keyShiftX, 11
	.set o_MusicPlayerTrack_tune, 12
	.set o_MusicPlayerTrack_pitX, 13
	.set o_MusicPlayerTrack_bend, 14
	.set o_MusicPlayerTrack_bendRange, 15
	.set o_MusicPlayerTrack_volMR, 16
	.set o_MusicPlayerTrack_volML, 17
	.set o_MusicPlayerTrack_vol, 18
	.set o_MusicPlayerTrack_volX, 19
	.set o_MusicPlayerTrack_pan, 20
	.set o_MusicPlayerTrack_panX, 21
	.set o_MusicPlayerTrack_modM, 22
	.set o_MusicPlayerTrack_mod, 23
	.set o_MusicPlayerTrack_modT, 24
	.set o_MusicPlayerTrack_lfoSpeed, 25
	.set o_MusicPlayerTrack_lfoSpeedC, 26
	.set o_MusicPlayerTrack_lfoDelay, 27
	.set o_MusicPlayerTrack_lfoDelayC, 28
	.set o_MusicPlayerTrack_priority, 29
	.set o_MusicPlayerTrack_pseudoEchoVolume, 30
	.set o_MusicPlayerTrack_pseudoEchoLength, 31
	.set o_MusicPlayerTrack_chan, 32
	.set o_MusicPlayerTrack_ToneData_type, 36
	.set o_MusicPlayerTrack_ToneData_key, 37
	.set o_MusicPlayerTrack_ToneData_length, 38
	.set o_MusicPlayerTrack_ToneData_pan_sweep, 39
	.set o_MusicPlayerTrack_ToneData_wav, 40
	.set o_MusicPlayerTrack_ToneData_attack, 44
	.set o_MusicPlayerTrack_ToneData_keySplitTable, 44
	.set o_MusicPlayerTrack_timer, 58
	.set o_MusicPlayerTrack_cmdPtr, 64
	.set o_MusicPlayerTrack_patternStack, 68

	.set o_MusicPlayerInfo_songHeader, 0
	.set o_MusicPlayerInfo_status, 4
	.set o_MusicPlayerInfo_trackCount, 8
	.set o_MusicPlayerInfo_priority, 9
	.set o_MusicPlayerInfo_cmd, 10
	.set o_MusicPlayerInfo_clock, 12
	.set o_MusicPlayerInfo_memAccArea, 24
	.set o_MusicPlayerInfo_tempoD, 28
	.set o_MusicPlayerInfo_tempoU, 30
	.set o_MusicPlayerInfo_tempoI, 32
	.set o_MusicPlayerInfo_tempoC, 34
	.set o_MusicPlayerInfo_fadeOI, 36
	.set o_MusicPlayerInfo_fadeOC, 38
	.set o_MusicPlayerInfo_fadeOV, 40
	.set o_MusicPlayerInfo_tracks, 44
	.set o_MusicPlayerInfo_tone, 48
	.set o_MusicPlayerInfo_ident, 52
	.set o_MusicPlayerInfo_MPlayMainNext, 56
	.set o_MusicPlayerInfo_musicPlayerNext, 60
