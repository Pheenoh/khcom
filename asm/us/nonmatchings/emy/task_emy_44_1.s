.syntax unified
	.align 2, 0
	.global task_emy_44_1
	.thumb
	.thumb_func
	.type task_emy_44_1, %function
task_emy_44_1: @ 0803D530
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
	beq _0803D58E
	adds r0, r5, #0x0
	add r1, sp, #0x014
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801C700
	ldr r0, [r5, #0x04]
	ldr r1, [sp, #0x014]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0803D56C
	ldr r0, _0803D568 @ =0x00004FFF
	cmp r2, r0
	ble _0803D574
	b _0803D584
_0803D568: .4byte 0x00004FFF
_0803D56C:
	subs r1, r1, r0
	ldr r0, _0803D580 @ =0x00004FFF
	cmp r1, r0
	bgt _0803D584
_0803D574:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x12
	b _0803D58C
	.byte 0x00, 0x00
_0803D580: .4byte 0x00004FFF
_0803D584:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x13
_0803D58C:
	str r0, [r1, #0x00]
_0803D58E:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803D5A0
	cmp r0, #0x13
	beq _0803D644
	b _0803D6F2
_0803D5A0:
	ldr r0, _0803D5FC @ =0x0813E464
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bgt _0803D62C
	cmp r0, #0x01
	blt _0803D62C
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803D604
	ldr r1, [r5, #0x04]
	ldr r2, _0803D600 @ =0xFFFFE000
	adds r1, r1, r2
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x20
	str r0, [sp, #0x000]
	movs r0, #0x10
	str r0, [sp, #0x004]
	movs r0, #0x28
	str r0, [sp, #0x008]
	movs r0, #0xDA
	bl func_08011F78
	cmp r0, #0x00
	bne _0803D626
	b _0803D62C
	.byte 0x00, 0x00
_0803D5FC: .4byte 0x0813E464
_0803D600: .4byte 0xFFFFE000
_0803D604:
	ldr r1, [r5, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x06
	adds r1, r1, r0
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x20
	str r0, [sp, #0x000]
	movs r0, #0x10
	str r0, [sp, #0x004]
	movs r0, #0x28
	str r0, [sp, #0x008]
	movs r0, #0xDA
	bl func_08011F78
	cmp r0, #0x00
	beq _0803D62C
_0803D626:
	ldr r0, _0803D640 @ =0x00000243
	bl func_0811FE70
_0803D62C:
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D6F2
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _0803D6F2
_0803D640: .4byte 0x00000243
_0803D644:
	ldr r0, _0803D6A8 @ =0x0813E464
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x07
	bne _0803D6E0
	ldrh r0, [r6, #0x1A]
	cmp r0, #0x00
	bne _0803D6E0
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r7, r1, #0x0
	orrs r7, r0
	cmp r7, #0x00
	beq _0803D6B8
	ldr r0, [r5, #0x04]
	ldr r2, _0803D6AC @ =0xFFFFC000
	adds r1, r0, r2
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	ldr r5, _0803D6B0 @ =0xFFFFFC00
	adds r3, r3, r5
	ldr r5, _0803D6B4 @ =0xFFFF4C00
	adds r0, r0, r5
	str r0, [sp, #0x000]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xDB
	str r0, [sp, #0x010]
	movs r0, #0x01
	bl func_08012E44
	b _0803D6E0
_0803D6A8: .4byte 0x0813E464
_0803D6AC: .4byte 0xFFFFC000
_0803D6B0: .4byte 0xFFFFFC00
_0803D6B4: .4byte 0xFFFF4C00
_0803D6B8:
	ldr r0, [r5, #0x04]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r1, r0, r2
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	ldr r5, _0803D748 @ =0xFFFFFC00
	adds r3, r3, r5
	movs r5, #0xB4
	lsls r5, r5, #0x08
	adds r0, r0, r5
	str r0, [sp, #0x000]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	str r7, [sp, #0x00C]
	movs r0, #0xDB
	str r0, [sp, #0x010]
	movs r0, #0x01
	bl func_08012E44
_0803D6E0:
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D6F2
	adds r0, r6, #0x0
	bl func_0800CB4C
_0803D6F2:
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _0803D74C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x04]
	mov r12, r0
	ldr r7, [r6, #0x40]
	cmp r12, r7
	bge _0803D724
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
	bne _0803D73C
_0803D724:
	ldr r4, [r6, #0x70]
	ldr r5, [r6, #0x74]
	cmp r12, r7
	ble _0803D758
	movs r0, #0x04
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0803D758
_0803D73C:
	ldr r2, _0803D750 @ =0x0C008000
	ldr r3, _0803D754 @ =0x00000000
	adds r0, r4, #0x0
	orrs r0, r2
	b _0803D75E
	.byte 0x00, 0x00
_0803D748: .4byte 0xFFFFFC00
_0803D74C: .4byte 0x02039B84
_0803D750: .4byte 0x0C008000
_0803D754: .4byte 0x00000000
_0803D758:
	ldr r2, _0803D774 @ =0xF3FF7FFF
	adds r0, r4, #0x0
	ands r0, r2
_0803D75E:
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
_0803D774: .4byte 0xF3FF7FFF
.syntax divided
