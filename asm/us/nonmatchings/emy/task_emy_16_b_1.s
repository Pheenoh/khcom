.syntax unified
	.align 2, 0
	.global task_emy_16_b_1
	.thumb
	.thumb_func
	.type task_emy_16_b_1, %function
task_emy_16_b_1: @ 08038F04
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	ldr r1, [r5, #0x38]
	cmp r1, #0x01
	beq _08038F9A
	cmp r1, #0x01
	bcc _08038F20
	cmp r1, #0x02
	beq _08038FF0
	cmp r1, #0x03
	bne _08038F1E
	b _08039030
_08038F1E:
	b _08039082
_08038F20:
	adds r0, r5, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08038F32
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x34]
	subs r0, r0, r1
	b _08038F38
_08038F32:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x34]
	adds r0, r0, r1
_08038F38:
	str r0, [r5, #0x20]
	adds r0, r5, #0x0
	adds r0, #0x20
	adds r1, r5, #0x0
	adds r1, #0x24
	movs r2, #0x10
	negs r2, r2
	movs r3, #0x00
	bl func_0801A8A4
	cmp r0, #0x00
	beq _08038F56
	ldr r0, [r5, #0x34]
	negs r0, r0
	str r0, [r5, #0x34]
_08038F56:
	adds r4, r5, #0x0
	adds r4, #0x9D
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _08038F82
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	ldr r2, [r5, #0x28]
	movs r3, #0x04
	str r3, [sp, #0x000]
	str r3, [sp, #0x004]
	bl func_08011E3C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08038F82
	ldr r0, [r5, #0x34]
	asrs r0, r0, #0x01
	negs r0, r0
	str r0, [r5, #0x34]
	movs r0, #0x01
	strb r0, [r4, #0x00]
_08038F82:
	ldr r0, [r5, #0x28]
	adds r4, r5, #0x0
	adds r4, #0x40
	adds r6, r5, #0x0
	adds r6, #0x08
	cmp r0, #0x00
	blt _0803908A
	movs r0, #0x01
	str r0, [r5, #0x38]
	movs r0, #0x00
	strh r0, [r5, #0x3C]
	b _0803908A
_08038F9A:
	movs r1, #0x3C
	ldsh r0, [r5, r1]
	adds r4, r5, #0x0
	adds r4, #0x40
	adds r6, r5, #0x0
	adds r6, #0x08
	cmp r0, #0x00
	bne _08038FBC
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08012614
	adds r0, r6, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl func_080059A4
_08038FBC:
	adds r0, r5, #0x0
	adds r0, #0x6C
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _08038FD8
	movs r0, #0x00
	strh r0, [r5, #0x3C]
	movs r0, #0x02
	str r0, [r5, #0x38]
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	b _0803908A
_08038FD8:
	ldrh r2, [r5, #0x3C]
	movs r3, #0x3C
	ldsh r0, [r5, r3]
	cmp r0, #0x64
	ble _08038FEA
	strh r1, [r5, #0x3C]
	movs r0, #0x03
	str r0, [r5, #0x38]
	b _0803908A
_08038FEA:
	adds r0, r2, #0x1
	strh r0, [r5, #0x3C]
	b _0803908A
_08038FF0:
	movs r1, #0x3C
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	beq _0803900C
	ldr r0, [r5, #0x28]
	adds r6, r5, #0x0
	adds r6, #0x08
	cmp r0, #0x00
	blt _08039020
	movs r0, #0x00
	strh r0, [r5, #0x3C]
	movs r0, #0x03
	str r0, [r5, #0x38]
	b _08039026
_0803900C:
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _0803902C @ =0xFFFFFC34
	str r0, [r5, #0x30]
	adds r6, r4, #0x0
_08039020:
	ldrh r0, [r5, #0x3C]
	adds r0, #0x01
	strh r0, [r5, #0x3C]
_08039026:
	adds r4, r5, #0x0
	adds r4, #0x40
	b _0803908A
_0803902C: .4byte 0xFFFFFC34
_08039030:
	ldrh r0, [r5, #0x3C]
	ands r1, r0
	cmp r1, #0x00
	bne _08039048
	movs r2, #0x00
	adds r1, r5, #0x0
	adds r1, #0x9C
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08039046
	movs r2, #0x01
_08039046:
	strb r2, [r1, #0x00]
_08039048:
	adds r0, r5, #0x0
	adds r0, #0x6C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08039070
	movs r0, #0x00
	strh r0, [r5, #0x3C]
	movs r0, #0x02
	str r0, [r5, #0x38]
	adds r4, r5, #0x0
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	adds r1, r5, #0x0
	adds r1, #0x9C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08039086
_08039070:
	ldrh r1, [r5, #0x3C]
	movs r2, #0x3C
	ldsh r0, [r5, r2]
	cmp r0, #0x3C
	ble _0803907E
	movs r0, #0x00
	b _080390B4
_0803907E:
	adds r0, r1, #0x1
	strh r0, [r5, #0x3C]
_08039082:
	adds r4, r5, #0x0
	adds r4, #0x40
_08039086:
	adds r6, r5, #0x0
	adds r6, #0x08
_0803908A:
	ldr r1, [r5, #0x28]
	ldr r0, [r5, #0x30]
	adds r1, r1, r0
	str r1, [r5, #0x28]
	adds r0, #0x33
	str r0, [r5, #0x30]
	cmp r1, #0x00
	blt _080390A0
	movs r0, #0x00
	str r0, [r5, #0x30]
	str r0, [r5, #0x28]
_080390A0:
	ldr r1, [r5, #0x20]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r6, #0x0
	bl func_08005A64
	movs r0, #0x01
_080390B4:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
