.syntax unified
	.include "gba_constants.inc"
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
.syntax divided
