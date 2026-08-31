.syntax unified
	.align 2, 0
	.global task_frd_beast_1
	.thumb
	.thumb_func
	.type task_frd_beast_1, %function
task_frd_beast_1: @ 08049A10
	push {r4, r5, r6, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x20
	ldr r0, _08049A34 @ =0x02039BB0
	ldrb r0, [r0, #0x0C]
	cmp r0, #0x08
	beq _08049A24
	b _08049BE4
_08049A24:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08049A3C
	ldr r0, _08049A38 @ =0x02039B84
	b _08049A3E
_08049A34: .4byte 0x02039BB0
_08049A38: .4byte 0x02039B84
_08049A3C:
	ldr r0, _08049B14 @ =0x02039B9C
_08049A3E:
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x17
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049A54
	b _08049BE4
_08049A54:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	bne _08049A62
	b _08049B88
_08049A62:
	cmp r0, #0x02
	beq _08049A68
	b _08049C52
_08049A68:
	movs r1, #0xA7
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	bne _08049A7C
	movs r0, #0xBD
	bl m4aSongNumStart
_08049A7C:
	movs r1, #0x9D
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08049AAC
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r0, r5, r2
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bne _08049AAC
	movs r1, #0xAC
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, _08049B18 @ =0xFFFFFC00
	str r1, [r0, #0x00]
	movs r0, #0x9C
	lsls r0, r0, #0x02
	bl m4aSongNumStart
_08049AAC:
	ldr r6, [r4, #0x0C]
	ldr r0, [r4, #0x10]
	adds r3, r6, #0x0
	cmp r3, r0
	bge _08049ADA
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	ldr r1, [r4, #0x04]
	subs r0, r0, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r4, #0x04]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r4, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r4, #0x08]
_08049ADA:
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	ble _08049B3E
	ldr r0, _08049B1C @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x86
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x99
	bne _08049B24
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r4, _08049B20 @ =0xFFFFE800
	adds r3, r3, r4
	movs r0, #0x28
	str r0, [sp, #0x000]
	movs r0, #0x14
	str r0, [sp, #0x004]
	movs r0, #0x10
	str r0, [sp, #0x008]
	movs r0, #0xA3
	bl func_08011F78
	b _08049B3E
	.byte 0x00, 0x00
_08049B14: .4byte 0x02039B9C
_08049B18: .4byte 0xFFFFFC00
_08049B1C: .4byte 0x02039B84
_08049B20: .4byte 0xFFFFE800
_08049B24:
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r0, _08049B7C @ =0xFFFFE800
	adds r3, r6, r0
	movs r0, #0x28
	str r0, [sp, #0x000]
	movs r0, #0x14
	str r0, [sp, #0x004]
	movs r0, #0x10
	str r0, [sp, #0x008]
	movs r0, #0xA2
	bl func_08011F78
_08049B3E:
	adds r0, r5, #0x0
	bl func_080497E8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08049B80
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r5, r1
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08049B80
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x01
	str r0, [r1, #0x00]
	movs r4, #0xAE
	lsls r4, r4, #0x01
	adds r1, r5, r4
	movs r0, #0xA1
	str r0, [r1, #0x00]
	adds r0, #0xAD
	adds r1, r5, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	bl func_0802F1E8
	b _08049C52
_08049B7C: .4byte 0xFFFFE800
_08049B80:
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r1, r5, r2
	b _08049C4C
_08049B88:
	movs r1, #0xA7
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	bne _08049BBA
	ldr r0, _08049BE8 @ =0x0813ED90
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r2, [r5, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x01
	bl func_08019068
	ldr r1, _08049BEC @ =0x0000014D
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _08049BBA
	movs r0, #0xBD
	bl m4aSongNumStart
_08049BBA:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049BF8
	ldr r1, [r4, #0x04]
	ldr r2, _08049BF0 @ =0xFFFFFC80
	adds r1, r1, r2
	str r1, [r4, #0x04]
	ldr r0, _08049BF4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x28
	lsls r0, r0, #0x08
	cmp r1, r0
	bge _08049C14
_08049BE4:
	movs r0, #0x00
	b _08049C64
_08049BE8: .4byte 0x0813ED90
_08049BEC: .4byte 0x0000014D
_08049BF0: .4byte 0xFFFFFC80
_08049BF4: .4byte 0x02039B84
_08049BF8:
	ldr r1, [r4, #0x04]
	movs r0, #0xE0
	lsls r0, r0, #0x02
	adds r1, r1, r0
	str r1, [r4, #0x04]
	ldr r0, _08049C6C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x28
	lsls r0, r0, #0x08
	cmp r1, r0
	bgt _08049BE4
_08049C14:
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	ldr r4, _08049C70 @ =0xFFFFE800
	adds r3, r3, r4
	movs r4, #0x28
	str r4, [sp, #0x000]
	movs r4, #0x14
	str r4, [sp, #0x004]
	movs r4, #0x10
	str r4, [sp, #0x008]
	bl func_08011F78
	cmp r0, #0x00
	beq _08049C40
	ldr r0, _08049C74 @ =0x0000026F
	bl m4aSongNumStart
_08049C40:
	adds r0, r5, #0x0
	bl func_080497E8
	movs r0, #0xA7
	lsls r0, r0, #0x01
	adds r1, r5, r0
_08049C4C:
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08049C52:
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r5, r1
	bl AnimUpdate
	adds r0, r5, #0x0
	bl TaskPoolUpdate
	movs r0, #0x01
_08049C64:
	add sp, #0x00C
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_08049C6C: .4byte 0x02039B84
_08049C70: .4byte 0xFFFFE800
_08049C74: .4byte 0x0000026F
.syntax divided
