.syntax unified
	.align 2, 0
	.global task_emy_83_b_1
	.thumb
	.thumb_func
	.type task_emy_83_b_1, %function
task_emy_83_b_1: @ 0803E994
	push {r4, r5, lr}
	add sp, #-0x00C
	adds r4, r0, #0x0
	ldr r0, _0803E9CC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803EA62
	ldr r0, [r4, #0x2C]
	cmp r0, #0x01
	beq _0803E9DA
	cmp r0, #0x01
	bcs _0803EA40
	ldrh r1, [r4, #0x30]
	movs r2, #0x30
	ldsh r0, [r4, r2]
	cmp r0, #0x0F
	ble _0803E9D0
	movs r0, #0x01
	str r0, [r4, #0x2C]
	movs r0, #0x00
	b _0803E9D2
	.byte 0x00, 0x00
_0803E9CC: .4byte 0x02039B84
_0803E9D0:
	adds r0, r1, #0x1
_0803E9D2:
	strh r0, [r4, #0x30]
	adds r5, r4, #0x0
	adds r5, #0x08
	b _0803EA6C
_0803E9DA:
	movs r1, #0x30
	ldsh r0, [r4, r1]
	adds r5, r4, #0x0
	adds r5, #0x08
	cmp r0, #0x00
	bne _0803E9F0
	adds r0, r5, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
_0803E9F0:
	adds r0, r5, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bne _0803EA24
	ldrh r0, [r4, #0x12]
	cmp r0, #0x00
	bne _0803EA24
	ldr r1, [r4, #0x20]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	movs r0, #0x04
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x10
	str r0, [sp, #0x008]
	movs r0, #0xE0
	bl func_08011F78
	cmp r0, #0x00
	beq _0803EA24
	ldr r0, _0803EA38 @ =0x00000242
	bl func_0811FE70
_0803EA24:
	ldrh r1, [r4, #0x30]
	movs r2, #0x30
	ldsh r0, [r4, r2]
	cmp r0, #0x1D
	ble _0803EA3C
	movs r0, #0x02
	str r0, [r4, #0x2C]
	movs r0, #0x00
	b _0803EA6A
	.byte 0x00, 0x00
_0803EA38: .4byte 0x00000242
_0803EA3C:
	adds r0, r1, #0x1
	b _0803EA6A
_0803EA40:
	movs r1, #0x30
	ldsh r0, [r4, r1]
	adds r5, r4, #0x0
	adds r5, #0x08
	cmp r0, #0x00
	bne _0803EA56
	adds r0, r5, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl func_080059A4
_0803EA56:
	adds r0, r5, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803EA66
_0803EA62:
	movs r0, #0x00
	b _0803EA82
_0803EA66:
	ldrh r0, [r4, #0x30]
	adds r0, #0x01
_0803EA6A:
	strh r0, [r4, #0x30]
_0803EA6C:
	adds r0, r4, #0x0
	adds r0, #0x34
	ldr r1, [r4, #0x20]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	bl func_08012324
	adds r0, r5, #0x0
	bl func_08005A64
	movs r0, #0x01
_0803EA82:
	add sp, #0x00C
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
