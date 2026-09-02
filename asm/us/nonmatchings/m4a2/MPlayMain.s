.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global MPlayMain
	.thumb
	.thumb_func
	.type MPlayMain, %function
MPlayMain:
	ldr r2, lt2_ID_NUMBER
	ldr r3, [r0, o_MusicPlayerInfo_ident]
	cmp r2, r3
	beq MPlayMain_1
	bx lr
MPlayMain_1:
	adds r3, 0x1
	str r3, [r0, o_MusicPlayerInfo_ident]
	push {r0,lr}
	ldr r3, [r0, o_MusicPlayerInfo_MPlayMainNext]
	cmp r3, 0
	beq MPlayMain_2
	ldr r0, [r0, o_MusicPlayerInfo_musicPlayerNext]
	bl call_r3
MPlayMain_2:
	pop {r0}
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	adds r7, r0, 0
	ldr r0, [r7, o_MusicPlayerInfo_status]
	cmp r0, 0
	bge MPlayMain_3
	b MPlayMain_38
MPlayMain_3:
	ldr r0, lt2_SOUND_INFO_PTR
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, 0
	bl FadeOutBody
	ldr r0, [r7, o_MusicPlayerInfo_status]
	cmp r0, 0
	bge MPlayMain_4
	b MPlayMain_38
MPlayMain_4:
	ldrh r0, [r7, o_MusicPlayerInfo_tempoC]
	ldrh r1, [r7, o_MusicPlayerInfo_tempoI]
	adds r0, r1
	b MPlayMain_27
MPlayMain_5:
	ldrb r6, [r7, o_MusicPlayerInfo_trackCount]
	ldr r5, [r7, o_MusicPlayerInfo_tracks]
	movs r3, 0x1
	movs r4, 0
MPlayMain_6:
	ldrb r0, [r5]
	movs r1, 0x80
	tst r1, r0
	bne MPlayMain_7
	b MPlayMain_24
MPlayMain_7:
	mov r10, r3
	orrs r4, r3
	mov r11, r4
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq MPlayMain_11
MPlayMain_8:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq MPlayMain_9
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq MPlayMain_10
	subs r0, 0x1
	strb r0, [r4, 0x10]
	bne MPlayMain_10
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
	b MPlayMain_10
MPlayMain_9:
	adds r0, r4, 0
	bl ClearChain
MPlayMain_10:
	ldr r1, [r4, o_SoundChannel_nextChannelPointer]
	cmp r1, r4
	bne MPlayMain_ClearNext
	movs r1, 0
	str r1, [r4, o_SoundChannel_nextChannelPointer]
MPlayMain_ClearNext:
	adds r4, r1, 0
	cmp r4, 0
	bne MPlayMain_8
MPlayMain_11:
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x40
	tst r0, r3
	beq MPlayMain_17
	adds r0, r5, 0
	bl Clear64byte
	movs r0, 0x80
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, o_MusicPlayerTrack_bendRange]
	movs r0, 0x40
	strb r0, [r5, o_MusicPlayerTrack_volX]
	movs r0, 0x16
	strb r0, [r5, o_MusicPlayerTrack_lfoSpeed]
	movs r0, 0x1
	adds r1, r5, 0x6
	strb r0, [r1, o_MusicPlayerTrack_ToneData_type - 0x6]
	b MPlayMain_17
MPlayMain_12:
	ldr r2, [r5, o_MusicPlayerTrack_cmdPtr]
	ldrb r1, [r2]
	cmp r1, 0x80
	bhs MPlayMain_13
	ldrb r1, [r5, o_MusicPlayerTrack_runningStatus]
	b MPlayMain_14
MPlayMain_13:
	adds r2, 0x1
	str r2, [r5, o_MusicPlayerTrack_cmdPtr]
	cmp r1, 0xBD
	bcc MPlayMain_14
	strb r1, [r5, o_MusicPlayerTrack_runningStatus]
MPlayMain_14:
	cmp r1, 0xCF
	bcc MPlayMain_15
	mov r0, r8
	ldr r3, [r0, o_SoundInfo_plynote]
	adds r0, r1, 0
	subs r0, 0xCF
	adds r1, r7, 0
	adds r2, r5, 0
	bl call_r3
	b MPlayMain_17
MPlayMain_15:
	cmp r1, 0xB0
	bls MPlayMain_16
	adds r0, r1, 0
	subs r0, 0xB1
	strb r0, [r7, o_MusicPlayerInfo_cmd]
	mov r3, r8
	ldr r3, [r3, o_SoundInfo_MPlayJumpTable]
	lsls r0, 2
	ldr r3, [r3, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl call_r3
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	cmp r0, 0
	beq MPlayMain_23
	b MPlayMain_17
MPlayMain_16:
	ldr r0, lt_gClockTable
	subs r1, 0x80
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r5, o_MusicPlayerTrack_wait]
MPlayMain_17:
	ldrb r0, [r5, o_MusicPlayerTrack_wait]
	cmp r0, 0
	beq MPlayMain_12
	subs r0, 0x1
	strb r0, [r5, o_MusicPlayerTrack_wait]
	ldrb r1, [r5, o_MusicPlayerTrack_lfoSpeed]
	cmp r1, 0
	beq MPlayMain_23
	ldrb r0, [r5, o_MusicPlayerTrack_mod]
	cmp r0, 0
	beq MPlayMain_23
	ldrb r0, [r5, o_MusicPlayerTrack_lfoDelayC]
	cmp r0, 0
	beq MPlayMain_18
	subs r0, 0x1
	strb r0, [r5, o_MusicPlayerTrack_lfoDelayC]
	b MPlayMain_23
MPlayMain_18:
	ldrb r0, [r5, o_MusicPlayerTrack_lfoSpeedC]
	adds r0, r1
	strb r0, [r5, o_MusicPlayerTrack_lfoSpeedC]
	adds r1, r0, 0
	subs r0, 0x40
	lsls r0, 24
	bpl MPlayMain_19
	lsls r2, r1, 24
	asrs r2, 24
	b MPlayMain_20
MPlayMain_19:
	movs r0, 0x80
	subs r2, r0, r1
MPlayMain_20:
	ldrb r0, [r5, o_MusicPlayerTrack_mod]
	muls r0, r2
	asrs r2, r0, 6
	ldrb r0, [r5, o_MusicPlayerTrack_modM]
	eors r0, r2
	lsls r0, 24
	beq MPlayMain_23
	strb r2, [r5, o_MusicPlayerTrack_modM]
	ldrb r0, [r5]
	ldrb r1, [r5, o_MusicPlayerTrack_modT]
	cmp r1, 0
	bne MPlayMain_21
	movs r1, 0xC
	b MPlayMain_22
MPlayMain_21:
	movs r1, 0x3
MPlayMain_22:
	orrs r0, r1
	strb r0, [r5, o_MusicPlayerTrack_flags]
MPlayMain_23:
	mov r3, r10
	mov r4, r11
MPlayMain_24:
	subs r6, 0x1
	ble MPlayMain_25
	movs r0, 0x50
	adds r5, r0
	lsls r3, 1
	b MPlayMain_6
MPlayMain_25:
	ldr r0, [r7, o_MusicPlayerInfo_clock]
	adds r0, 0x1
	str r0, [r7, o_MusicPlayerInfo_clock]
	cmp r4, 0
	bne MPlayMain_26
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, o_MusicPlayerInfo_status]
	b MPlayMain_38
MPlayMain_26:
	str r4, [r7, o_MusicPlayerInfo_status]
	ldrh r0, [r7, o_MusicPlayerInfo_tempoC]
	subs r0, 0x96
MPlayMain_27:
	strh r0, [r7, o_MusicPlayerInfo_tempoC]
	cmp r0, 0x96
	bcc MPlayMain_28
	b MPlayMain_5
MPlayMain_28:
	ldrb r2, [r7, o_MusicPlayerInfo_trackCount]
	ldr r5, [r7, o_MusicPlayerInfo_tracks]
MPlayMain_29:
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	movs r1, 0x80
	tst r1, r0
	beq MPlayMain_37
	movs r1, 0xF
	tst r1, r0
	beq MPlayMain_37
	mov r9, r2
	adds r0, r7, 0
	adds r1, r5, 0
	bl TrkVolPitSet
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq MPlayMain_36
MPlayMain_30:
	ldrb r1, [r4, o_SoundChannel_statusFlags]
	movs r0, 0xC7
	tst r0, r1
	bne MPlayMain_31
	adds r0, r4, 0
	bl ClearChain
	b MPlayMain_35
MPlayMain_31:
	ldrb r0, [r4, o_SoundChannel_type]
	movs r6, 0x7
	ands r6, r0
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x3
	tst r0, r3
	beq MPlayMain_32
	bl ChnVolSetAsm
	cmp r6, 0
	beq MPlayMain_32
	ldrb r0, [r4, o_CgbChannel_modify]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, o_CgbChannel_modify]
MPlayMain_32:
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0xC
	tst r0, r3
	beq MPlayMain_35
	ldrb r1, [r4, o_SoundChannel_key]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl MPlayMain_33
	movs r2, 0
MPlayMain_33:
	cmp r6, 0
	beq MPlayMain_34
	mov r0, r8
	ldr r3, [r0, o_SoundInfo_MidiKeyToCgbFreq]
	adds r1, r2, 0
	ldrb r2, [r5, o_MusicPlayerTrack_pitM]
	adds r0, r6, 0
	bl call_r3
	str r0, [r4, o_CgbChannel_frequency]
	ldrb r0, [r4, o_CgbChannel_modify]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, o_CgbChannel_modify]
	b MPlayMain_35
MPlayMain_34:
	adds r1, r2, 0
	ldrb r2, [r5, o_MusicPlayerTrack_pitM]
	ldr r0, [r4, o_SoundChannel_wav]
	bl MidiKeyToFreq
	str r0, [r4, o_SoundChannel_frequency]
MPlayMain_35:
	ldr r1, [r4, o_SoundChannel_nextChannelPointer]
	cmp r1, r4
	bne MPlayMain_ChanNext
	movs r1, 0
	str r1, [r4, o_SoundChannel_nextChannelPointer]
MPlayMain_ChanNext:
	adds r4, r1, 0
	cmp r4, 0
	bne MPlayMain_30
MPlayMain_36:
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	movs r1, 0xF0
	ands r0, r1
	strb r0, [r5, o_MusicPlayerTrack_flags]
	mov r2, r9
MPlayMain_37:
	subs r2, 0x1
	ble MPlayMain_38
	movs r0, 0x50
	adds r5, r0
	bgt MPlayMain_29
MPlayMain_38:
	ldr r0, lt2_ID_NUMBER
	str r0, [r7, o_MusicPlayerInfo_ident]
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}

call_r3:
	bx r3

	.align 2, 0
lt_gClockTable:     .word gClockTable
lt2_SOUND_INFO_PTR: .word SOUND_INFO_PTR
lt2_ID_NUMBER:      .word ID_NUMBER
	.align 2, 0
.syntax divided
