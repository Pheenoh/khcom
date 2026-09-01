.syntax unified
	.align 2, 0
	.global func_0811589C
	.thumb
	.thumb_func
	.type func_0811589C, %function
func_0811589C: @ 0811589C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	ldr r1, [r7, #0x00]
	ldr r0, [r7, #0x04]
	adds r2, r1, r0
	mov r8, r2
	adds r6, r7, #0x0
	adds r6, #0x14
	ldr r5, [r7, #0x0C]
	lsls r2, r0, #0x01
	adds r2, r2, r0
	lsls r2, r2, #0x05
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldr r1, _081159A4 @ =0x09A54918
	adds r0, r0, r1
	adds r2, r2, r0
	ldr r1, [r2, #0x00]
	ldr r0, [r2, #0x08]
	orrs r1, r0
	ldr r0, [r5, #0x00]
	ands r0, r1
	str r0, [r7, #0x14]
	ldr r0, [r5, #0x04]
	ands r0, r1
	str r0, [r6, #0x04]
	ldr r0, [r5, #0x08]
	ands r0, r1
	str r0, [r6, #0x08]
	ldr r0, [r5, #0x0C]
	ands r0, r1
	str r0, [r6, #0x0C]
	ldr r0, [r5, #0x10]
	ands r0, r1
	str r0, [r6, #0x10]
	ldr r0, [r5, #0x14]
	ands r0, r1
	str r0, [r6, #0x14]
	ldr r0, [r5, #0x18]
	ands r0, r1
	str r0, [r6, #0x18]
	ldr r0, [r5, #0x1C]
	ands r0, r1
	str r0, [r6, #0x1C]
	mov r0, r8
	cmp r0, #0x08
	ble _08115932
	ldr r1, [r2, #0x04]
	ldr r0, [r5, #0x20]
	ands r0, r1
	str r0, [r6, #0x20]
	ldr r0, [r5, #0x24]
	ands r0, r1
	str r0, [r6, #0x24]
	ldr r0, [r5, #0x28]
	ands r0, r1
	str r0, [r6, #0x28]
	ldr r0, [r5, #0x2C]
	ands r0, r1
	str r0, [r6, #0x2C]
	ldr r0, [r5, #0x30]
	ands r0, r1
	str r0, [r6, #0x30]
	ldr r0, [r5, #0x34]
	ands r0, r1
	str r0, [r6, #0x34]
	ldr r0, [r5, #0x38]
	ands r0, r1
	str r0, [r6, #0x38]
	ldr r0, [r5, #0x3C]
	ands r0, r1
	str r0, [r6, #0x3C]
_08115932:
	ldr r1, _081159A8 @ =0x09A54CB8
	ldr r0, [r7, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r1, [r7, #0x08]
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x00]
	ldr r4, [r0, #0x00]
	adds r0, r6, #0x0
	bl _call_via_r4
	ldr r0, [r7, #0x14]
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x08]
	ldr r0, [r6, #0x0C]
	str r0, [r5, #0x0C]
	ldr r0, [r6, #0x10]
	str r0, [r5, #0x10]
	ldr r0, [r6, #0x14]
	str r0, [r5, #0x14]
	ldr r0, [r6, #0x18]
	str r0, [r5, #0x18]
	ldr r0, [r6, #0x1C]
	str r0, [r5, #0x1C]
	mov r1, r8
	cmp r1, #0x08
	ble _0811598E
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x24]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x28]
	str r0, [r5, #0x28]
	ldr r0, [r6, #0x2C]
	str r0, [r5, #0x2C]
	ldr r0, [r6, #0x30]
	str r0, [r5, #0x30]
	ldr r0, [r6, #0x34]
	str r0, [r5, #0x34]
	ldr r0, [r6, #0x38]
	str r0, [r5, #0x38]
	ldr r0, [r6, #0x3C]
	str r0, [r5, #0x3C]
_0811598E:
	movs r0, #0x01
	mov r2, r8
	cmp r2, #0x08
	ble _08115998
	movs r0, #0x02
_08115998:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_081159A4: .4byte 0x09A54918
_081159A8: .4byte 0x09A54CB8
.syntax divided
