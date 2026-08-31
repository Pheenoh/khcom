.syntax unified
	.align 2, 0
	.global task_emy_37_2
	.thumb
	.thumb_func
	.type task_emy_37_2, %function
task_emy_37_2: @ 0803CC74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0803CC8E
	b _0803CE3E
_0803CC8E:
	adds r7, r6, #0x0
	adds r7, #0x3C
	ldr r0, [r7, #0x08]
	bl func_0801AF1C
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	movs r3, #0xC0
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r3, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r3, r0
	bne _0803CD1E
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803CCEC
	ldr r0, _0803CCE8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _0803CD62
	.byte 0x00, 0x00
_0803CCE8: .4byte 0x02039B84
_0803CCEC:
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	ldr r1, _0803CD10 @ =0x02039B84
	cmp r0, #0x00
	bne _0803CD14
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x24]
	cmp r0, r3
	bne _0803CD14
	adds r2, r3, #0x0
	adds r1, r2, #0x0
	movs r0, #0x01
	mov r3, r8
	orrs r3, r0
	mov r8, r3
	b _0803CD62
_0803CD10: .4byte 0x02039B84
_0803CD14:
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x24]
	negs r1, r0
	adds r2, r0, #0x0
	b _0803CD62
_0803CD1E:
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803CD48
	ldr r0, _0803CD44 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r1, r0, #0x08
	b _0803CD5C
	.byte 0x00, 0x00
_0803CD44: .4byte 0x02039B84
_0803CD48:
	ldr r0, _0803CD80 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	negs r1, r0
_0803CD5C:
	adds r0, r2, #0x0
	muls r0, r3
	asrs r2, r0, #0x08
_0803CD62:
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	bne _0803CD90
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0803CD84
	cmp r1, r2
	bne _0803CD84
	movs r5, #0x00
	b _0803CD98
	.byte 0x00, 0x00
_0803CD80: .4byte 0x02039B84
_0803CD84:
	cmp r2, #0xFF
	bgt _0803CD8E
	movs r0, #0x00
	movs r3, #0x00
	b _0803CD92
_0803CD8E:
	movs r0, #0x00
_0803CD90:
	movs r3, #0x01
_0803CD92:
	bl AllocObjAffine
	adds r5, r0, #0x0
_0803CD98:
	adds r0, r7, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803CDD4
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x08]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r7, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _0803CDD0 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	b _0803CDFA
	.byte 0x00, 0x00
_0803CDD0: .4byte 0xFFFFEFFC
_0803CDD4:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _0803CE08
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r4, _0803CE04 @ =0x0000FFFF
_0803CDFA:
	str r4, [sp, #0x00C]
	bl DrawSprite
	b _0803CE36
	.byte 0x00, 0x00
_0803CE04: .4byte 0x0000FFFF
_0803CE08:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r7, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _0803CE4C @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
_0803CE36:
	adds r0, r6, #0x0
	adds r0, #0x28
	bl TaskPoolDraw
_0803CE3E:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803CE4C: .4byte 0xFFFFEFFC
.syntax divided
