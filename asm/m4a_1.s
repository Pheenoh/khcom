	.include "gba_constants.inc"

	.syntax unified
	.text

	.align 2, 0
	.global umul3232H32
	.thumb
	.thumb_func
	.type umul3232H32, %function
umul3232H32:
	adr r2, __umul3232H32
	bx r2
	.arm
__umul3232H32:
	umull r2, r3, r0, r1
	add r0, r3, 0
	bx lr

	.align 2, 0
	.global SoundMain
	.thumb
	.thumb_func
	.type SoundMain, %function
SoundMain:
	ldr r0, lt_SOUND_INFO_PTR
	ldr r0, [r0]
	ldr r2, lt_ID_NUMBER
	ldr r3, [r0, o_SoundInfo_ident]
	cmp r2, r3
	beq SoundMain_1
	bx lr
SoundMain_1:
	adds r3, 1
	str r3, [r0, o_SoundInfo_ident]
	push {r4-r7,lr}
	mov r1, r8
	mov r2, r9
	mov r3, r10
	mov r4, r11
	push {r0-r4}
	sub sp, 0x18
	ldrb r1, [r0, o_SoundInfo_maxLines]
	cmp r1, 0
	beq SoundMain_3
	ldr r2, lt_REG_VCOUNT
	ldrb r2, [r2]
	cmp r2, VCOUNT_VBLANK
	bhs SoundMain_2
	adds r2, TOTAL_SCANLINES
SoundMain_2:
	adds r1, r2
SoundMain_3:
	str r1, [sp, 0x14]
	ldr r3, [r0, o_SoundInfo_MPlayMainHead]
	cmp r3, 0
	beq SoundMain_4
	ldr r0, [r0, o_SoundInfo_musicPlayerHead]
	bl SoundMainRAM_CallR3
	ldr r0, [sp, 0x18]
SoundMain_4:
	ldr r3, [r0, o_SoundInfo_CgbSound]
	bl SoundMainRAM_CallR3
	ldr r0, [sp, 0x18]
	ldr r3, [r0, o_SoundInfo_pcmSamplesPerVBlank]
	mov r8, r3
	ldr r5, lt_o_SoundInfo_pcmBuffer
	adds r5, r0
	ldrb r4, [r0, o_SoundInfo_pcmDmaCounter]
	subs r7, r4, 1
	bls SoundMain_5
	ldrb r1, [r0, o_SoundInfo_pcmDmaPeriod]
	subs r1, r7
	mov r2, r8
	muls r2, r1
	adds r5, r2
SoundMain_5:
	str r5, [sp, 0x8]
	ldr r6, lt_PCM_DMA_BUF_SIZE
	ldr r3, lt_SoundMainRAM_Buffer
	bx r3

	.align 2, 0
lt_SOUND_INFO_PTR:        .word SOUND_INFO_PTR
lt_ID_NUMBER:             .word ID_NUMBER
lt_SoundMainRAM_Buffer:   .word SoundMainRAM_Buffer + 1
lt_REG_VCOUNT:            .word REG_VCOUNT
lt_o_SoundInfo_pcmBuffer: .word o_SoundInfo_pcmBuffer
lt_PCM_DMA_BUF_SIZE:      .word PCM_DMA_BUF_SIZE

	.align 2, 0
	.global SoundMainRAM
	.thumb
	.thumb_func
	.type SoundMainRAM, %function
SoundMainRAM:
	ldrb r3, [r0, o_SoundInfo_reverb]
	cmp r3, 0
	beq SoundMainRAM_NoReverb
	adr r1, SoundMainRAM_Reverb
	bx r1
	.arm
SoundMainRAM_Reverb:
	cmp r4, 0x2
	addeq r7, r0, o_SoundInfo_pcmBuffer
	addne r7, r5, r8
	mov r4, r8
SoundMainRAM_1:
	ldrsb r0, [r5, r6]
	ldrsb r1, [r5]
	add r0, r0, r1
	ldrsb r1, [r7, r6]
	add r0, r0, r1
	ldrsb r1, [r7], 0x1
	add r0, r0, r1
	mul r1, r0, r3
	mov r0, r1, asr 9
	tst r0, 0x80
	addne r0, r0, 0x1
	strb r0, [r5, r6]
	strb r0, [r5], 0x1
	subs r4, r4, 0x1
	bgt SoundMainRAM_1
	adr r0, SoundMainRAM_2 + 1
	bx r0
	.thumb
SoundMainRAM_NoReverb:
	movs r0, 0
	mov r1, r8
	adds r6, r5
	lsrs r1, 3
	bcc SoundMainRAM_NoReverb_Ok
	stm r5!, {r0}
	stm r6!, {r0}
SoundMainRAM_NoReverb_Ok:
	lsrs r1, 1
	bcc SoundMainRAM_NoReverb_Loop
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
SoundMainRAM_NoReverb_Loop:
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	subs r1, 1
	bgt SoundMainRAM_NoReverb_Loop
SoundMainRAM_2:
	ldr r4, [sp, 0x18]
	ldr r0, [r4, o_SoundInfo_divFreq]
	mov r12, r0
	ldrb r0, [r4, o_SoundInfo_maxChans]
	adds r4, o_SoundInfo_chans

SoundMainRAM_ChanLoop:
	str r0, [sp, 0x4]
	ldr r3, [r4, o_SoundChannel_wav]
	ldr r0, [sp, 0x14]
	cmp r0, 0
	beq SoundMainRAM_4
	ldr r1, =REG_VCOUNT
	ldrb r1, [r1]
	cmp r1, VCOUNT_VBLANK
	bhs SoundMainRAM_3
	adds r1, TOTAL_SCANLINES
SoundMainRAM_3:
	cmp r1, r0
	blo SoundMainRAM_4
	b SoundMainRAM_36

	.pool

SoundMainRAM_4:
	ldrb r6, [r4, o_SoundChannel_statusFlags]
	movs r0, 0xC7
	tst r0, r6
	bne SoundMainRAM_5
	b SoundMainRAM_35
SoundMainRAM_5:
	movs r0, 0x80
	tst r0, r6
	beq SoundMainRAM_6
	movs r0, 0x40
	tst r0, r6
	bne SoundMainRAM_7
	movs r6, 0x3
	strb r6, [r4, o_SoundChannel_statusFlags]
	adds r0, r3, 0
	adds r0, 0x10
	str r0, [r4, o_SoundChannel_currentPointer]
	ldr r0, [r3, 0xC]
	str r0, [r4, o_SoundChannel_count]
	movs r5, 0
	strb r5, [r4, o_SoundChannel_envelopeVolume]
	str r5, [r4, o_SoundChannel_fw]
	ldrb r2, [r3, 0x3]
	movs r0, 0xC0
	tst r0, r2
	beq SoundMainRAM_12
	movs r0, 0x10
	orrs r6, r0
	strb r6, [r4, o_SoundChannel_statusFlags]
	b SoundMainRAM_12
SoundMainRAM_6:
	ldrb r5, [r4, o_SoundChannel_envelopeVolume]
	movs r0, 0x4
	tst r0, r6
	beq SoundMainRAM_8
	ldrb r0, [r4, o_SoundChannel_pseudoEchoLength]
	subs r0, 1
	strb r0, [r4, o_SoundChannel_pseudoEchoLength]
	bhi SoundMainRAM_13
SoundMainRAM_7:
	movs r0, 0
	strb r0, [r4, o_SoundChannel_statusFlags]
	b SoundMainRAM_35
SoundMainRAM_8:
	movs r0, 0x40
	tst r0, r6
	beq SoundMainRAM_10
	ldrb r0, [r4, o_SoundChannel_release]
	muls r5, r0
	lsrs r5, 8
	ldrb r0, [r4, o_SoundChannel_pseudoEchoVolume]
	cmp r5, r0
	bhi SoundMainRAM_13
SoundMainRAM_9:
	ldrb r5, [r4, o_SoundChannel_pseudoEchoVolume]
	cmp r5, 0
	beq SoundMainRAM_7
	movs r0, 0x4
	orrs r6, r0
	strb r6, [r4, o_SoundChannel_statusFlags]
	b SoundMainRAM_13
SoundMainRAM_10:
	movs r2, 0x3
	ands r2, r6
	cmp r2, 0x2
	bne SoundMainRAM_11
	ldrb r0, [r4, o_SoundChannel_decay]
	muls r5, r0
	lsrs r5, 8
	ldrb r0, [r4, o_SoundChannel_sustain]
	cmp r5, r0
	bhi SoundMainRAM_13
	adds r5, r0, 0
	beq SoundMainRAM_9
	subs r6, 0x1
	strb r6, [r4, o_SoundChannel_statusFlags]
	b SoundMainRAM_13
SoundMainRAM_11:
	cmp r2, 0x3
	bne SoundMainRAM_13
SoundMainRAM_12:
	ldrb r0, [r4, o_SoundChannel_attack]
	adds r5, r0
	cmp r5, 0xFF
	bcc SoundMainRAM_13
	movs r5, 0xFF
	subs r6, 0x1
	strb r6, [r4, o_SoundChannel_statusFlags]
SoundMainRAM_13:
	strb r5, [r4, o_SoundChannel_envelopeVolume]
	ldr r0, [sp, 0x18]
	ldrb r0, [r0, o_SoundChannel_release]
	adds r0, 0x1
	muls r0, r5
	lsrs r5, r0, 4
	ldrb r0, [r4, o_SoundChannel_rightVolume]
	muls r0, r5
	lsrs r0, 8
	strb r0, [r4, o_SoundChannel_envelopeVolumeRight]
	ldrb r0, [r4, o_SoundChannel_leftVolume]
	muls r0, r5
	lsrs r0, 8
	strb r0, [r4, o_SoundChannel_envelopeVolumeLeft]
	movs r0, 0x10
	ands r0, r6
	str r0, [sp, 0x10]
	beq SoundMainRAM_14
	adds r0, r3, 0
	adds r0, 0x10
	ldr r1, [r3, 0x8]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r3, 0xC]
	subs r0, r1
	str r0, [sp, 0x10]
SoundMainRAM_14:
	ldr r5, [sp, 0x8]
	ldr r2, [r4, o_SoundChannel_count]
	ldr r3, [r4, o_SoundChannel_currentPointer]
	adr r0, SoundMainRAM_15
	bx r0
	.arm
SoundMainRAM_15:
	str r8, [sp]
	ldrb r10, [r4, o_SoundChannel_envelopeVolumeRight]
	ldrb r11, [r4, o_SoundChannel_envelopeVolumeLeft]
	mov r10, r10, lsl 16
	mov r11, r11, lsl 16
	ldrb r0, [r4, o_SoundChannel_type]
	tst r0, 0x8
	beq SoundMainRAM_27
SoundMainRAM_16:
	cmp r2, 0x4
	ble SoundMainRAM_19
	subs r2, r2, r8
	movgt lr, 0
	bgt SoundMainRAM_17
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, 0x4
	sub lr, lr, r8
	ands r2, r2, 0x3
	moveq r2, 0x4
SoundMainRAM_17:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
SoundMainRAM_18:
	ldrsb r0, [r3], 0x1
	mul r1, r10, r0
	bic r1, r1, 0xFF0000
	add r6, r1, r6, ror 8
	mul r1, r11, r0
	bic r1, r1, 0xFF0000
	add r7, r1, r7, ror 8
	adds r5, r5, 0x40000000
	bcc SoundMainRAM_18
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt SoundMainRAM_17
	adds r8, r8, lr
	beq SoundMainRAM_33
SoundMainRAM_19:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
SoundMainRAM_20:
	ldrsb r0, [r3], 0x1
	mul r1, r10, r0
	bic r1, r1, 0xFF0000
	add r6, r1, r6, ror 8
	mul r1, r11, r0
	bic r1, r1, 0xFF0000
	add r7, r1, r7, ror 8
	subs r2, r2, 0x1
	beq SoundMainRAM_25
SoundMainRAM_21:
	adds r5, r5, 0x40000000
	bcc SoundMainRAM_20
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt SoundMainRAM_16
	b SoundMainRAM_33
SoundMainRAM_22:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	beq SoundMainRAM_24
	ldr r3, [sp, 0x14]
	rsb r9, r2, 0
SoundMainRAM_23:
	adds r2, r0, r2
	bgt SoundMainRAM_30
	sub r9, r9, r0
	b SoundMainRAM_23
SoundMainRAM_24:
	pop {r4,r12}
	mov r2, 0
	b SoundMainRAM_26
SoundMainRAM_25:
	ldr r2, [sp, 0x10]
	cmp r2, 0
	ldrne r3, [sp, 0xC]
	bne SoundMainRAM_21
SoundMainRAM_26:
	strb r2, [r4, o_SoundChannel_statusFlags]
	mov r0, r5, lsr 30
	bic r5, r5, 0xC0000000
	rsb r0, r0, 0x3
	mov r0, r0, lsl 3
	mov r6, r6, ror r0
	mov r7, r7, ror r0
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	b SoundMainRAM_34
SoundMainRAM_27:
	push {r4,r12}
	ldr lr, [r4, o_SoundChannel_fw]
	ldr r1, [r4, o_SoundChannel_frequency]
	mul r4, r12, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, 0x1]!
	sub r1, r1, r0
SoundMainRAM_28:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
SoundMainRAM_29:
	mul r9, lr, r1
	add r9, r0, r9, asr 23
	mul r12, r10, r9
	bic r12, r12, 0xFF0000
	add r6, r12, r6, ror 8
	mul r12, r11, r9
	bic r12, r12, 0xFF0000
	add r7, r12, r7, ror 8
	add lr, lr, r4
	movs r9, lr, lsr 23
	beq SoundMainRAM_31
	bic lr, lr, 0x3F800000
	subs r2, r2, r9
	ble SoundMainRAM_22
	subs r9, r9, 0x1
	addeq r0, r0, r1
SoundMainRAM_30:
	ldrsbne r0, [r3, r9]!
	ldrsb r1, [r3, 0x1]!
	sub r1, r1, r0
SoundMainRAM_31:
	adds r5, r5, 0x40000000
	bcc SoundMainRAM_29
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt SoundMainRAM_28
	sub r3, r3, 0x1
	pop {r4,r12}
SoundMainRAM_32:
	str lr, [r4, o_SoundChannel_fw]
SoundMainRAM_33:
	str r2, [r4, o_SoundChannel_count]
	str r3, [r4, o_SoundChannel_currentPointer]
SoundMainRAM_34:
	ldr r8, [sp]
	add r0, pc, 0x1
	bx r0
	.thumb
SoundMainRAM_35:
	ldr r0, [sp, 0x4]
	subs r0, 1
	ble SoundMainRAM_36
	adds r4, SoundChannel_size
	b SoundMainRAM_ChanLoop
SoundMainRAM_36:
	ldr r0, [sp, 0x18]
	ldr r3, =ID_NUMBER
	str r3, [r0]
	add sp, 0x1C
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
SoundMainRAM_CallR3:
	bx r3
	.pool

	.align 2, 0
	.global SoundMainBTM
	.thumb
	.thumb_func
	.type SoundMainBTM, %function
SoundMainBTM:
	mov r12, r4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	movs r4, 0
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	mov r4, r12
	bx lr

	.align 2, 0
	.global RealClearChain
	.thumb
	.thumb_func
	.type RealClearChain, %function
RealClearChain:
	ldr r3, [r0, 0x2C]
	cmp r3, 0
	beq RealClearChain_4
	ldr r1, [r0, 0x34]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq RealClearChain_1
	str r1, [r2, 0x34]
	b RealClearChain_2
RealClearChain_1:
	str r1, [r3, 0x20]
RealClearChain_2:
	cmp r1, 0
	beq RealClearChain_3
	str r2, [r1, 0x30]
RealClearChain_3:
	movs r1, 0
	str r1, [r0, 0x2C]
RealClearChain_4:
	bx lr

	.align 2, 0
	.global ply_fine
	.thumb
	.thumb_func
	.type ply_fine, %function
ply_fine:
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq ply_fine_done
ply_fine_loop:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq ply_fine_ok
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
ply_fine_ok:
	adds r0, r4, 0
	bl RealClearChain
	ldr r1, [r4, o_SoundChannel_nextChannelPointer]
	cmp r1, r4
	bne ply_fine_next
	movs r1, 0
	str r1, [r4, o_SoundChannel_nextChannelPointer]
ply_fine_next:
	adds r4, r1, 0
	cmp r4, 0
	bne ply_fine_loop
ply_fine_done:
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0

	.align 2, 0
	.global MPlayJumpTableCopy
	.thumb
	.thumb_func
	.type MPlayJumpTableCopy, %function
MPlayJumpTableCopy:
	mov r12, lr
	movs r1, 0x24
	ldr r2, lt_MPlayJumpTableTemplate
MPlayJumpTableCopy_Loop:
	ldr r3, [r2]
	bl chk_adr_r2
	stm r0!, {r3}
	adds r2, 0x4
	subs r1, 0x1
	bgt MPlayJumpTableCopy_Loop
	bx r12

	.align 2, 0
	.thumb_func
ldrb_r3_r2:
	ldrb r3, [r2]

	.thumb_func
chk_adr_r2:
	push {r0}
	lsrs r0, r2, 25
	bne chk_adr_r2_done
	ldr r0, lt_MPlayJumpTableTemplate
	cmp r2, r0
	blo chk_adr_r2_reject
	lsrs r0, r2, 14
	beq chk_adr_r2_done
chk_adr_r2_reject:
	movs r3, 0
chk_adr_r2_done:
	pop {r0}
	bx lr

	.align 2, 0
lt_MPlayJumpTableTemplate: .word gMPlayJumpTableTemplate

	.align 2, 0
	.global ld_r3_tp_adr_i
	.thumb
	.thumb_func
	.type ld_r3_tp_adr_i, %function
ld_r3_tp_adr_i:
	ldr r2, [r1, 0x40]
ld_r3_tp_adr_i_r2:
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	b chk_adr_r2

	.align 2, 0
	.global ply_goto
	.thumb
	.thumb_func
	.type ply_goto, %function
ply_goto:
	push {lr}
ply_goto_1:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	ldrb r3, [r2, 0x2]
	orrs r0, r3
	lsls r0, 8
	ldrb r3, [r2, 0x1]
	orrs r0, r3
	lsls r0, 8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0

	.align 2, 0
	.global ply_patt
	.thumb
	.thumb_func
	.type ply_patt, %function
ply_patt:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 3
	bhs ply_patt_done
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r2, 0x4
	str r2, [r3, o_MusicPlayerTrack_patternStack]
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	adds r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	b ply_goto
ply_patt_done:
	b ply_fine

	.align 2, 0
	.global ply_pend
	.thumb
	.thumb_func
	.type ply_pend, %function
ply_pend:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 0
	beq ply_pend_done
	subs r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r3, o_MusicPlayerTrack_patternStack]
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
ply_pend_done:
	bx lr

	.align 2, 0
	.global ply_rept
	.thumb
	.thumb_func
	.type ply_rept, %function
ply_rept:
	push {lr}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0
	bne ply_rept_1
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b ply_goto_1
ply_rept_1:
	ldrb r3, [r1, o_MusicPlayerTrack_repN]
	adds r3, 1
	strb r3, [r1, o_MusicPlayerTrack_repN]
	mov r12, r3
	bl ld_r3_tp_adr_i
	cmp r12, r3
	bhs ply_rept_2
	b ply_goto_1
ply_rept_2:
	movs r3, 0
	strb r3, [r1, o_MusicPlayerTrack_repN]
	adds r2, 5
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0

	.align 2, 0
	.global ply_prio
	.thumb
	.thumb_func
	.type ply_prio, %function
ply_prio:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_priority]
	bx r12

	.align 2, 0
	.global ply_tempo
	.thumb
	.thumb_func
	.type ply_tempo, %function
ply_tempo:
	mov r12, lr
	bl ld_r3_tp_adr_i
	lsls r3, 1
	strh r3, [r0, o_MusicPlayerInfo_tempoD]
	ldrh r2, [r0, o_MusicPlayerInfo_tempoU]
	muls r3, r2
	lsrs r3, 8
	strh r3, [r0, o_MusicPlayerInfo_tempoI]
	bx r12

	.align 2, 0
	.global ply_keysh
	.thumb
	.thumb_func
	.type ply_keysh, %function
ply_keysh:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_keyShift]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12

	.align 2, 0
	.global ply_voice
	.thumb
	.thumb_func
	.type ply_voice, %function
ply_voice:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 2
	ldr r3, [r0, o_MusicPlayerInfo_tone]
	adds r2, r3
	ldr r3, [r2]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_type]
	ldr r3, [r2, 0x4]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_wav]
	ldr r3, [r2, 0x8]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_attack]
	bx r12

	.align 2, 0
	.global ply_vol
	.thumb
	.thumb_func
	.type ply_vol, %function
ply_vol:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_vol]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12

	.align 2, 0
	.global ply_pan
	.thumb
	.thumb_func
	.type ply_pan, %function
ply_pan:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_pan]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12

	.align 2, 0
	.global ply_bend
	.thumb
	.thumb_func
	.type ply_bend, %function
ply_bend:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_bend]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12

	.align 2, 0
	.global ply_bendr
	.thumb
	.thumb_func
	.type ply_bendr, %function
ply_bendr:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_bendRange]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12

	.align 2, 0
	.global ply_lfodl
	.thumb
	.thumb_func
	.type ply_lfodl, %function
ply_lfodl:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_lfoDelay]
	bx r12

	.align 2, 0
	.global ply_modt
	.thumb
	.thumb_func
	.type ply_modt, %function
ply_modt:
	mov r12, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, o_MusicPlayerTrack_modT]
	cmp r0, r3
	beq ply_modt_1
	strb r3, [r1, o_MusicPlayerTrack_modT]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xF
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
ply_modt_1:
	bx r12

	.align 2, 0
	.global ply_tune
	.thumb
	.thumb_func
	.type ply_tune, %function
ply_tune:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_tune]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12

	.align 2, 0
	.global ply_port
	.thumb
	.thumb_func
	.type ply_port, %function
ply_port:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	ldr r0, =REG_SOUND1CNT_L
	adds r0, r3
	bl ld_r3_tp_adr_i_r2
	strb r3, [r0]
	bx r12
	.pool

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
	.global TrackStop
	.thumb
	.thumb_func
	.type TrackStop, %function
TrackStop:
	push {r4-r6,lr}
	adds r5, r1, 0
	ldrb r1, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x80
	tst r0, r1
	beq TrackStop_Done
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq TrackStop_3
	movs r6, 0
TrackStop_Loop:
	ldrb r0, [r4, o_SoundChannel_statusFlags]
	cmp r0, 0
	beq TrackStop_2
	ldrb r0, [r4, o_SoundChannel_type]
	movs r3, 0x7
	ands r0, r3
	beq TrackStop_1
	ldr r3, =SOUND_INFO_PTR
	ldr r3, [r3]
	ldr r3, [r3, o_SoundInfo_CgbOscOff]
	bl call_r3
TrackStop_1:
	strb r6, [r4, o_SoundChannel_statusFlags]
TrackStop_2:
	str r6, [r4, o_SoundChannel_track]
	ldr r0, [r4, o_SoundChannel_nextChannelPointer]
	cmp r0, r4
	bne TrackStop_Next
	movs r0, 0
	str r0, [r4, o_SoundChannel_nextChannelPointer]
TrackStop_Next:
	adds r4, r0, 0
	cmp r4, 0
	bne TrackStop_Loop
TrackStop_3:
	str r4, [r5, o_MusicPlayerTrack_chan]
TrackStop_Done:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool

	.align 2, 0
	.global ChnVolSetAsm
	.thumb
	.thumb_func
	.type ChnVolSetAsm, %function
ChnVolSetAsm:
	ldrb r1, [r4, o_SoundChannel_velocity]
	movs r0, o_SoundChannel_rhythmPan
	ldrsb r2, [r4, r0]
	movs r3, 0x80
	adds r3, r2
	muls r3, r1
	ldrb r0, [r5, o_MusicPlayerTrack_volMR]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls ChnVolSetAsm_1
	movs r0, 0xFF
ChnVolSetAsm_1:
	strb r0, [r4, o_SoundChannel_rightVolume]
	movs r3, 0x7F
	subs r3, r2
	muls r3, r1
	ldrb r0, [r5, o_MusicPlayerTrack_volML]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls ChnVolSetAsm_2
	movs r0, 0xFF
ChnVolSetAsm_2:
	strb r0, [r4, o_SoundChannel_leftVolume]
	bx lr

	.align 2, 0
	.global ply_note
	.thumb
	.thumb_func
	.type ply_note, %function
ply_note:
	push {r4-r7,lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	sub sp, 0x18
	str r1, [sp]
	adds r5, r2, 0
	ldr r1, =SOUND_INFO_PTR
	ldr r1, [r1]
	str r1, [sp, 0x4]
	ldr r1, =gClockTable
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r5, o_MusicPlayerTrack_gateTime]
	ldr r3, [r5, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r3]
	cmp r0, 0x80
	bhs ply_note_2
	strb r0, [r5, o_MusicPlayerTrack_key]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bhs ply_note_1
	strb r0, [r5, o_MusicPlayerTrack_velocity]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bhs ply_note_1
	ldrb r1, [r5, o_MusicPlayerTrack_gateTime]
	adds r1, r0
	strb r1, [r5, o_MusicPlayerTrack_gateTime]
	adds r3, 0x1
ply_note_1:
	str r3, [r5, o_MusicPlayerTrack_cmdPtr]
ply_note_2:
	movs r0, 0
	str r0, [sp, 0x14]
	adds r4, r5, 0
	adds r4, o_MusicPlayerTrack_ToneData_type
	ldrb r2, [r4]
	movs r0, TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL
	tst r0, r2
	beq ply_note_7
	ldrb r3, [r5, o_MusicPlayerTrack_key]
	movs r0, TONEDATA_TYPE_SPL
	tst r0, r2
	beq ply_note_3
	ldr r1, [r5, o_MusicPlayerTrack_ToneData_keySplitTable]
	adds r1, r3
	ldrb r0, [r1]
	b ply_note_4
ply_note_3:
	adds r0, r3, 0
ply_note_4:
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, [r5, o_MusicPlayerTrack_ToneData_wav]
	adds r1, r0
	mov r9, r1
	mov r6, r9
	ldrb r1, [r6]
	movs r0, 0xC0
	tst r0, r1
	beq ply_note_5
	b ply_note_28
ply_note_5:
	movs r0, 0x80
	tst r0, r2
	beq ply_note_8
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	beq ply_note_6
	subs r1, 0xC0
	lsls r1, 1
	str r1, [sp, 0x14]
ply_note_6:
	ldrb r3, [r6, 0x1]
	b ply_note_8
ply_note_7:
	mov r9, r4
	ldrb r3, [r5, 0x5]
ply_note_8:
	str r3, [sp, 0x8]
	ldr r6, [sp]
	ldrb r1, [r6, 0x9]
	ldrb r0, [r5, 0x1D]
	adds r0, r1
	cmp r0, 0xFF
	bls ply_note_9
	movs r0, 0xFF
ply_note_9:
	str r0, [sp, 0x10]
	mov r6, r9
	ldrb r0, [r6]
	movs r6, 0x7
	ands r6, r0
	str r6, [sp, 0xC]
	beq ply_note_12
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
	cmp r4, 0
	bne ply_note_10
	b ply_note_28
ply_note_10:
	subs r6, 0x1
	lsls r0, r6, 6
	adds r4, r0
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq ply_note_20
	movs r0, 0x40
	tst r0, r1
	bne ply_note_20
	ldrb r1, [r4, 0x13]
	ldr r0, [sp, 0x10]
	cmp r1, r0
	bcc ply_note_20
	beq ply_note_11
	b ply_note_28
ply_note_11:
	ldr r0, [r4, 0x2C]
	cmp r0, r5
	bcs ply_note_20
	b ply_note_28
ply_note_12:
	ldr r6, [sp, 0x10]
	adds r7, r5, 0
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x4]
	ldrb r3, [r4, 0x6]
	adds r4, 0x50
ply_note_13:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq ply_note_20
	movs r0, 0x40
	tst r0, r1
	beq ply_note_14
	cmp r2, 0
	bne ply_note_15
	adds r2, 0x1
	ldrb r6, [r4, 0x13]
	ldr r7, [r4, 0x2C]
	b ply_note_18
ply_note_14:
	cmp r2, 0
	bne ply_note_19
ply_note_15:
	ldrb r0, [r4, 0x13]
	cmp r0, r6
	bcs ply_note_16
	adds r6, r0, 0
	ldr r7, [r4, 0x2C]
	b ply_note_18
ply_note_16:
	bhi ply_note_19
	ldr r0, [r4, 0x2C]
	cmp r0, r7
	bls ply_note_17
	adds r7, r0, 0
	b ply_note_18
ply_note_17:
	bcc ply_note_19
ply_note_18:
	mov r8, r4
ply_note_19:
	adds r4, 0x40
	subs r3, 0x1
	bgt ply_note_13
	mov r4, r8
	cmp r4, 0
	beq ply_note_28
ply_note_20:
	adds r0, r4, 0
	bl ClearChain
	movs r1, 0
	str r1, [r4, 0x30]
	ldr r3, [r5, 0x20]
	str r3, [r4, 0x34]
	cmp r3, 0
	beq ply_note_21
	str r4, [r3, 0x30]
ply_note_21:
	str r4, [r5, 0x20]
	str r5, [r4, 0x2C]
	ldrb r0, [r5, 0x1B]
	strb r0, [r5, 0x1C]
	cmp r0, r1
	beq ply_note_22
	adds r1, r5, 0
	bl clear_modM
ply_note_22:
	ldr r0, [sp]
	adds r1, r5, 0
	bl TrkVolPitSet
	ldr r0, [r5, 0x4]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	strb r0, [r4, 0x13]
	ldr r0, [sp, 0x8]
	strb r0, [r4, 0x8]
	ldr r0, [sp, 0x14]
	strb r0, [r4, 0x14]
	mov r6, r9
	ldrb r0, [r6]
	strb r0, [r4, 0x1]
	ldr r7, [r6, 0x4]
	str r7, [r4, 0x24]
	ldr r0, [r6, 0x8]
	str r0, [r4, 0x4]
	ldrh r0, [r5, 0x1E]
	strh r0, [r4, 0xC]
	bl ChnVolSetAsm
	ldrb r1, [r4, 0x8]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl ply_note_23
	movs r3, 0
ply_note_23:
	ldr r6, [sp, 0xC]
	cmp r6, 0
	beq ply_note_26
	mov r6, r9
	ldrb r0, [r6, 0x2]
	strb r0, [r4, 0x1E]
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	bne ply_note_24
	movs r0, 0x70
	tst r0, r1
	bne ply_note_25
ply_note_24:
	movs r1, 0x8
ply_note_25:
	strb r1, [r4, 0x1F]
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	ldr r0, [sp, 0xC]
	ldr r3, [sp, 0x4]
	ldr r3, [r3, 0x30]
	bl call_r3
	b ply_note_27
ply_note_26:
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	adds r0, r7, 0
	bl MidiKeyToFreq
ply_note_27:
	str r0, [r4, 0x20]
	movs r0, 0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, 0xF0
	ands r0, r1
	strb r0, [r5]
ply_note_28:
	add sp, 0x18
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r0}
	bx r0
	.pool

	.align 2, 0
	.global ply_endtie
	.thumb
	.thumb_func
	.type ply_endtie, %function
ply_endtie:
	push {r4,r5}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0x80
	bhs ply_endtie_1
	strb r3, [r1, o_MusicPlayerTrack_key]
	adds r2, 0x1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b ply_endtie_2
ply_endtie_1:
	ldrb r3, [r1, o_MusicPlayerTrack_key]
ply_endtie_2:
	ldr r1, [r1, o_MusicPlayerTrack_chan]
	cmp r1, 0
	beq ply_endtie_5
	movs r4, 0x83
	movs r5, 0x40
ply_endtie_3:
	ldrb r2, [r1, o_SoundChannel_statusFlags]
	tst r2, r4
	beq ply_endtie_4
	tst r2, r5
	bne ply_endtie_4
	ldrb r0, [r1, o_SoundChannel_midiKey]
	cmp r0, r3
	bne ply_endtie_4
	movs r0, 0x40
	orrs r2, r0
	strb r2, [r1, o_SoundChannel_statusFlags]
	b ply_endtie_5
ply_endtie_4:
	ldr r2, [r1, o_SoundChannel_nextChannelPointer]
	cmp r2, r1
	bne ply_endtie_next
	movs r2, 0
	str r2, [r1, o_SoundChannel_nextChannelPointer]
ply_endtie_next:
	adds r1, r2, 0
	cmp r1, 0
	bne ply_endtie_3
ply_endtie_5:
	pop {r4,r5}
	bx lr

	.align 2, 0
	.global clear_modM
	.thumb
	.thumb_func
	.type clear_modM, %function
clear_modM:
	movs r2, 0
	strb r2, [r1, o_MusicPlayerTrack_modM]
	strb r2, [r1, o_MusicPlayerTrack_lfoSpeedC]
	ldrb r2, [r1, o_MusicPlayerTrack_modT]
	cmp r2, 0
	bne clear_modM_1
	movs r2, 0xC
	b clear_modM_2
clear_modM_1:
	movs r2, 0x3
clear_modM_2:
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx lr

	.align 2, 0
	.global ld_r3_tp_adr_i_unchecked
	.thumb
	.thumb_func
	.type ld_r3_tp_adr_i_unchecked, %function
ld_r3_tp_adr_i_unchecked:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r3, r2, 1
	str r3, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	bx lr

	.align 2, 0
	.global ply_lfos
	.thumb
	.thumb_func
	.type ply_lfos, %function
ply_lfos:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_lfoSpeed]
	cmp r3, 0
	bne ply_lfos_1
	bl clear_modM
ply_lfos_1:
	bx r12

	.align 2, 0
	.global ply_mod
	.thumb
	.thumb_func
	.type ply_mod, %function
ply_mod:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_mod]
	cmp r3, 0
	bne ply_mod_1
	bl clear_modM
ply_mod_1:
	bx r12
	.align 2, 0
