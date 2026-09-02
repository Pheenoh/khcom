.syntax unified
	.include "gba_constants.inc"
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
.syntax divided
