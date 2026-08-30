.syntax unified
	.align 2, 0
	.global task_emy_38_1
	.thumb
	.thumb_func
	.type task_emy_38_1, %function
task_emy_38_1: @ 0803CE70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x018
	adds r6, r0, #0x0
	adds r4, r6, #0x0
	adds r5, r6, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803CEB4
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0803CEA0
	cmp r1, #0x01
	beq _0803CEAA
	b _0803CEB4
_0803CEA0:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x12
	b _0803CEB2
_0803CEAA:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x13
_0803CEB2:
	str r0, [r1, #0x00]
_0803CEB4:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803CEC6
	cmp r0, #0x13
	beq _0803CF20
	b _0803CF86
_0803CEC6:
	ldr r0, _0803CF14 @ =0x0813E2CC
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r0, #0xD4
	str r0, [sp, #0x000]
	movs r0, #0x32
	str r0, [sp, #0x004]
	ldr r0, _0803CF18 @ =0x00000212
	str r0, [sp, #0x008]
	movs r0, #0x00
	str r0, [sp, #0x00C]
	str r0, [sp, #0x010]
	movs r0, #0x18
	str r0, [sp, #0x014]
	adds r0, r6, #0x0
	movs r1, #0x1E
	movs r2, #0x14
	movs r3, #0x2D
	bl func_0800C980
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x1E
	bne _0803CF86
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, _0803CF1C @ =0xFFFFFD00
	str r0, [r1, #0x00]
	b _0803CF86
_0803CF14: .4byte 0x0813E2CC
_0803CF18: .4byte 0x00000212
_0803CF1C: .4byte 0xFFFFFD00
_0803CF20:
	ldr r0, _0803CF7C @ =0x0813E2CC
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r4, r6, r1
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x3F
	bne _0803CF64
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x01
	str r0, [sp, #0x008]
	movs r0, #0xD5
	bl func_08011F78
	movs r0, #0x84
	lsls r0, r0, #0x02
	bl func_0811FE70
	bl func_0802F1E8
_0803CF64:
	adds r0, r6, #0x0
	adds r0, #0x10
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803CF80
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _0803CF86
	.byte 0x00, 0x00
_0803CF7C: .4byte 0x0813E2CC
_0803CF80:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
_0803CF86:
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _0803CFDC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x04]
	mov r12, r0
	ldr r7, [r6, #0x40]
	cmp r12, r7
	bge _0803CFB8
	ldr r3, [r6, #0x70]
	ldr r4, [r6, #0x74]
	movs r2, #0x04
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	adds r5, r4, #0x0
	adds r4, r3, #0x0
	cmp r0, #0x00
	bne _0803CFD0
_0803CFB8:
	ldr r4, [r6, #0x70]
	ldr r5, [r6, #0x74]
	cmp r12, r7
	ble _0803CFE8
	movs r0, #0x04
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0803CFE8
_0803CFD0:
	ldr r2, _0803CFE0 @ =0x00008000
	ldr r3, _0803CFE4 @ =0x00000000
	adds r0, r4, #0x0
	orrs r0, r2
	b _0803CFEE
	.byte 0x00, 0x00
_0803CFDC: .4byte 0x02039B84
_0803CFE0: .4byte 0x00008000
_0803CFE4: .4byte 0x00000000
_0803CFE8:
	ldr r2, _0803D004 @ =0xFFFF7FFF
	adds r0, r4, #0x0
	ands r0, r2
_0803CFEE:
	adds r1, r5, #0x0
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	mov r0, r8
	add sp, #0x018
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0803D004: .4byte 0xFFFF7FFF
.syntax divided
