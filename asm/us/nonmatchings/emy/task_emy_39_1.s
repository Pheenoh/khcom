.syntax unified
	.align 2, 0
	.global task_emy_39_1
	.thumb
	.thumb_func
	.type task_emy_39_1, %function
task_emy_39_1: @ 0803D034
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r5, r6, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D078
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0803D064
	cmp r1, #0x01
	beq _0803D06E
	b _0803D078
_0803D064:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x12
	b _0803D076
_0803D06E:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x13
_0803D076:
	str r0, [r1, #0x00]
_0803D078:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803D08A
	cmp r0, #0x13
	beq _0803D148
	b _0803D284
_0803D08A:
	ldr r0, _0803D0E8 @ =0x0813E354
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x30
	bne _0803D120
	ldr r4, [r5, #0x08]
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _0803D0F8
	ldr r1, [r5, #0x04]
	ldr r3, _0803D0EC @ =0xFFFF9C00
	adds r0, r1, r3
	ldr r2, _0803D0F0 @ =0xFFFFC000
	adds r1, r1, r2
	ldr r3, [r5, #0x0C]
	ldr r5, _0803D0F4 @ =0xFFFFE000
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	movs r0, #0x00
	str r0, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xD6
	str r0, [sp, #0x010]
	movs r0, #0x00
	adds r2, r4, #0x0
	bl func_08012E44
	b _0803D120
_0803D0E8: .4byte 0x0813E354
_0803D0EC: .4byte 0xFFFF9C00
_0803D0F0: .4byte 0xFFFFC000
_0803D0F4: .4byte 0xFFFFE000
_0803D0F8:
	ldr r1, [r5, #0x04]
	movs r3, #0xC8
	lsls r3, r3, #0x07
	adds r0, r1, r3
	movs r3, #0x80
	lsls r3, r3, #0x07
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _0803D144 @ =0xFFFFE000
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xD6
	str r0, [sp, #0x010]
	movs r0, #0x00
	adds r2, r4, #0x0
	bl func_08012E44
_0803D120:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x30
	ble _0803D13A
	bl func_08006B74
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D13A
	b _0803D26C
_0803D13A:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r1, r6, r3
	b _0803D27E
	.byte 0x00, 0x00
_0803D144: .4byte 0xFFFFE000
_0803D148:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r2, #0x00
	ldsh r4, [r0, r2]
	cmp r4, #0x00
	bne _0803D170
	ldr r0, _0803D190 @ =0x0813E354
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r0, r7, r3
	str r4, [r0, #0x00]
_0803D170:
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r4
	cmp r0, #0x07
	bhi _0803D1FA
	lsls r0, r0, #0x02
	ldr r1, _0803D194 @ =0x0803D198
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_0803D190: .4byte 0x0813E354
_0803D194: .4byte 0x0803D198
	.byte 0xB8, 0xD1, 0x03, 0x08, 0xBE, 0xD1, 0x03, 0x08, 0xC6, 0xD1, 0x03, 0x08, 0xCE, 0xD1, 0x03, 0x08
	.byte 0xD6, 0xD1, 0x03, 0x08, 0xDA, 0xD1, 0x03, 0x08, 0xF4, 0xD1, 0x03, 0x08, 0xFA, 0xD1, 0x03, 0x08
	.byte 0x18, 0x20, 0x84, 0x46, 0x1F, 0xE0, 0x1E, 0x21, 0x8C, 0x46, 0x10, 0x24, 0x1C, 0xE0, 0x18, 0x22
	.byte 0x94, 0x46, 0x14, 0x24, 0x08, 0xE0, 0x18, 0x20, 0x84, 0x46, 0x10, 0x24, 0x14, 0xE0, 0x30, 0x21
	.byte 0x10, 0xE0, 0x1E, 0x22, 0x94, 0x46, 0x10, 0x24, 0x70, 0x8B, 0x00, 0x28, 0x0C, 0xD1, 0xC2, 0x23
	.byte 0x5B, 0x00, 0xF9, 0x18, 0x80, 0x20, 0x80, 0x00, 0x08, 0x60, 0x05, 0xE0, 0x30, 0x20, 0x84, 0x46
	.byte 0x01, 0xE0
_0803D1FA:
	movs r1, #0x18
	mov r12, r1
	movs r4, #0x14
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803D21E
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r1, [r5, #0x04]
	ldr r0, [r0, #0x00]
	subs r1, r1, r0
	b _0803D22A
_0803D21E:
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldr r1, [r5, #0x04]
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
_0803D22A:
	str r1, [r5, #0x04]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, [r1, #0x00]
	subs r0, #0x19
	str r0, [r1, #0x00]
	cmp r0, #0x00
	bge _0803D240
	movs r0, #0x00
	str r0, [r1, #0x00]
_0803D240:
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	mov r5, r12
	str r5, [sp, #0x000]
	str r4, [sp, #0x004]
	movs r0, #0x28
	str r0, [sp, #0x008]
	movs r0, #0xD7
	bl func_08011F78
	cmp r0, #0x00
	beq _0803D260
	ldr r0, _0803D274 @ =0x00000221
	bl m4aSongNumStart
_0803D260:
	mov r0, r8
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D278
_0803D26C:
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _0803D284
_0803D274: .4byte 0x00000221
_0803D278:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r6, r0
_0803D27E:
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0803D284:
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _0803D2D8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x04]
	mov r12, r0
	ldr r7, [r6, #0x40]
	cmp r12, r7
	bge _0803D2B6
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
	bne _0803D2CE
_0803D2B6:
	ldr r4, [r6, #0x70]
	ldr r5, [r6, #0x74]
	cmp r12, r7
	ble _0803D2E4
	movs r0, #0x04
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0803D2E4
_0803D2CE:
	ldr r2, _0803D2DC @ =0x00008000
	ldr r3, _0803D2E0 @ =0x00000000
	adds r0, r4, #0x0
	orrs r0, r2
	b _0803D2EA
_0803D2D8: .4byte 0x02039B84
_0803D2DC: .4byte 0x00008000
_0803D2E0: .4byte 0x00000000
_0803D2E4:
	ldr r2, _0803D300 @ =0xFFFF7FFF
	adds r0, r4, #0x0
	ands r0, r2
_0803D2EA:
	adds r1, r5, #0x0
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	mov r0, r8
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0803D300: .4byte 0xFFFF7FFF
.syntax divided
