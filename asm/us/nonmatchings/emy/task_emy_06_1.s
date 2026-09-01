.syntax unified
	.align 2, 0
	.global task_emy_06_1
	.thumb
	.thumb_func
	.type task_emy_06_1, %function
task_emy_06_1: @ 08037AE4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x018
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r5, r6, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08037B48
	adds r0, r5, #0x0
	movs r1, #0x00
	add r2, sp, #0x00C
	movs r3, #0x00
	bl func_0801C700
	ldr r0, [r5, #0x08]
	ldr r1, [sp, #0x00C]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08037B1C
	ldr r0, _08037B18 @ =0x00000FFF
	cmp r2, r0
	ble _08037B24
	b _08037B34
_08037B18: .4byte 0x00000FFF
_08037B1C:
	subs r1, r1, r0
	ldr r0, _08037B30 @ =0x00000FFF
	cmp r1, r0
	bgt _08037B34
_08037B24:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x13
	b _08037B3C
	.byte 0x00, 0x00
_08037B30: .4byte 0x00000FFF
_08037B34:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x12
_08037B3C:
	str r0, [r1, #0x00]
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r1, r7, r3
	movs r0, #0x00
	str r0, [r1, #0x00]
_08037B48:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _08037B5A
	cmp r0, #0x13
	beq _08037C4C
	b _08037D38
_08037B5A:
	ldr r0, _08037C34 @ =0x0813D644
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r0, _08037C38 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0x9C
	lsls r3, r3, #0x01
	adds r0, r0, r3
	ldr r1, [r5, #0x0C]
	movs r3, #0xC0
	lsls r3, r3, #0x04
	adds r2, r1, r3
	ldr r0, [r0, #0x00]
	subs r0, r0, r2
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r5, #0x0C]
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	ldr r1, _08037C3C @ =0xFFFB0000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0x0F
	bhi _08037C26
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldrh r0, [r0, #0x00]
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _08037BD8
	add r1, sp, #0x010
	add r2, sp, #0x014
	adds r0, r5, #0x0
	movs r3, #0x00
	bl func_0801C700
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [sp, #0x010]
	ldr r3, [sp, #0x014]
	bl GetAngle
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r1, r6, r3
	strb r0, [r1, #0x00]
_08037BD8:
	ldr r3, _08037C40 @ =0x08121400
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r2, r6, r0
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x01
	ldr r1, [r5, #0x04]
	adds r1, r1, r0
	str r1, [r5, #0x04]
	ldrb r0, [r2, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x01
	ldr r2, [r5, #0x08]
	subs r2, r2, r0
	str r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	ldr r0, _08037C44 @ =0xFFFFF800
	adds r3, r3, r0
	movs r0, #0x14
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x08
	str r0, [sp, #0x008]
	movs r0, #0xAF
	bl func_08011F78
	cmp r0, #0x00
	beq _08037C26
	ldr r0, _08037C48 @ =0x00000249
	bl m4aSongNumStart
_08037C26:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08037D18
	b _08037D2C
_08037C34: .4byte 0x0813D644
_08037C38: .4byte 0x02039B84
_08037C3C: .4byte 0xFFFB0000
_08037C40: .4byte 0x08121400
_08037C44: .4byte 0xFFFFF800
_08037C48: .4byte 0x00000249
_08037C4C:
	ldr r0, _08037CB4 @ =0x0813D644
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r3, #0xB4
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r0, _08037CB8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x9C
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r1, [r5, #0x0C]
	movs r3, #0xC0
	lsls r3, r3, #0x04
	adds r2, r1, r3
	ldr r0, [r0, #0x00]
	subs r0, r0, r2
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r5, #0x0C]
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	ldr r1, _08037CBC @ =0xFFFA0000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0x0A
	bhi _08037D0C
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08037CC0
	ldr r1, [r5, #0x04]
	movs r2, #0xF0
	lsls r2, r2, #0x07
	adds r1, r1, r2
	b _08037CC6
_08037CB4: .4byte 0x0813D644
_08037CB8: .4byte 0x02039B84
_08037CBC: .4byte 0xFFFA0000
_08037CC0:
	ldr r1, [r5, #0x04]
	ldr r3, _08037D20 @ =0xFFFF8800
	adds r1, r1, r3
_08037CC6:
	ldr r0, [r5, #0x14]
	subs r0, r0, r1
	asrs r3, r0, #0x03
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, [r1, #0x00]
	adds r0, #0x33
	str r0, [r1, #0x00]
	cmp r3, r0
	bgt _08037CE2
	negs r0, r0
	cmp r3, r0
	bge _08037CE4
_08037CE2:
	adds r3, r0, #0x0
_08037CE4:
	ldr r1, [r5, #0x04]
	adds r1, r1, r3
	str r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	ldr r0, _08037D24 @ =0xFFFFF800
	adds r3, r3, r0
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x08
	str r0, [sp, #0x008]
	movs r0, #0xB0
	bl func_08011F78
	cmp r0, #0x00
	beq _08037D0C
	ldr r0, _08037D28 @ =0x00000211
	bl m4aSongNumStart
_08037D0C:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08037D2C
_08037D18:
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _08037D38
_08037D20: .4byte 0xFFFF8800
_08037D24: .4byte 0xFFFFF800
_08037D28: .4byte 0x00000211
_08037D2C:
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08037D38:
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x018
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
