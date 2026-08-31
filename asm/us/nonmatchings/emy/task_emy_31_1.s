.syntax unified
	.align 2, 0
	.global task_emy_31_1
	.thumb
	.thumb_func
	.type task_emy_31_1, %function
task_emy_31_1: @ 0803BFB4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r5, r6, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C01E
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _0803C000
	cmp r0, #0x01
	bgt _0803BFF0
	cmp r0, #0x00
	beq _0803BFF6
	b _0803C014
_0803BFF0:
	cmp r0, #0x02
	beq _0803C00A
	b _0803C014
_0803BFF6:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x12
	b _0803C012
_0803C000:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x13
	b _0803C012
_0803C00A:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r0, #0x14
_0803C012:
	str r0, [r1, #0x00]
_0803C014:
	movs r4, #0xC2
	lsls r4, r4, #0x01
	adds r1, r7, r4
	movs r0, #0x00
	str r0, [r1, #0x00]
_0803C01E:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x13
	bne _0803C02C
	b _0803C190
_0803C02C:
	cmp r0, #0x13
	bhi _0803C036
	cmp r0, #0x12
	beq _0803C03E
	b _0803C4B6
_0803C036:
	cmp r0, #0x14
	bne _0803C03C
	b _0803C2F6
_0803C03C:
	b _0803C4B6
_0803C03E:
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r0, r6, r2
	movs r3, #0x00
	mov r9, r3
	str r3, [r0, #0x00]
	movs r4, #0xC2
	lsls r4, r4, #0x01
	adds r4, r4, r7
	mov r8, r4
	ldr r4, [r4, #0x00]
	cmp r4, #0x01
	beq _0803C098
	cmp r4, #0x01
	bcc _0803C062
	cmp r4, #0x03
	beq _0803C13A
	b _0803C4B6
_0803C062:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _0803C082
	ldr r0, _0803C094 @ =0x0813E11C
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
_0803C082:
	adds r0, r6, #0x0
	adds r0, #0x10
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C092
	b _0803C1E4
_0803C092:
	b _0803C374
_0803C094: .4byte 0x0813E11C
_0803C098:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r3, #0x00
	ldsh r2, [r0, r3]
	mov r8, r2
	cmp r2, #0x00
	bne _0803C11E
	adds r0, r6, #0x0
	adds r0, #0x10
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	ldr r0, [r5, #0x08]
	mov r12, r0
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _0803C0F8
	ldr r1, [r5, #0x04]
	ldr r2, _0803C0F0 @ =0xFFFF3800
	adds r0, r1, r2
	ldr r3, _0803C0F4 @ =0xFFFFC000
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	str r0, [sp, #0x000]
	mov r0, r12
	str r0, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0xCF
	str r0, [sp, #0x010]
	movs r0, #0x01
	mov r2, r12
	bl func_08012E44
	b _0803C11E
_0803C0F0: .4byte 0xFFFF3800
_0803C0F4: .4byte 0xFFFFC000
_0803C0F8:
	ldr r1, [r5, #0x04]
	movs r3, #0xC8
	lsls r3, r3, #0x08
	adds r0, r1, r3
	movs r4, #0x80
	lsls r4, r4, #0x07
	adds r1, r1, r4
	ldr r3, [r5, #0x0C]
	str r0, [sp, #0x000]
	mov r0, r12
	str r0, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xCF
	str r0, [sp, #0x010]
	movs r0, #0x01
	mov r2, r12
	bl func_08012E44
_0803C11E:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r4, r6, r1
	ldrh r1, [r4, #0x00]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x1E
	bgt _0803C130
	b _0803C29A
_0803C130:
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r0, r7, r3
	movs r1, #0x03
	b _0803C292
_0803C13A:
	movs r4, #0xAA
	lsls r4, r4, #0x01
	adds r5, r6, r4
	movs r1, #0x00
	ldsh r0, [r5, r1]
	adds r4, r6, #0x0
	adds r4, #0x10
	cmp r0, #0x00
	bne _0803C156
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl AnimStart
_0803C156:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C17C
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
_0803C17C:
	bl func_080128EC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C18A
	b _0803C4B0
_0803C18A:
	mov r3, r8
	str r0, [r3, #0x00]
	b _0803C4A8
_0803C190:
	movs r4, #0xB4
	lsls r4, r4, #0x01
	adds r0, r6, r4
	movs r1, #0x00
	mov r9, r1
	str r1, [r0, #0x00]
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r2, r2, r7
	mov r8, r2
	ldr r4, [r2, #0x00]
	cmp r4, #0x01
	beq _0803C1F4
	cmp r4, #0x01
	bcc _0803C1B4
	cmp r4, #0x02
	beq _0803C2A0
	b _0803C4B6
_0803C1B4:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r4, r6, r3
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _0803C1D4
	ldr r0, _0803C1F0 @ =0x0813E11C
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
_0803C1D4:
	adds r0, r6, #0x0
	adds r0, #0x10
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0803C1E4
	b _0803C374
_0803C1E4:
	movs r0, #0x01
	mov r2, r8
	str r0, [r2, #0x00]
	mov r3, r9
	strh r3, [r4, #0x00]
	b _0803C4B6
_0803C1F0: .4byte 0x0813E11C
_0803C1F4:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r3, #0x00
	ldsh r2, [r0, r3]
	mov r8, r2
	cmp r2, #0x00
	bne _0803C27A
	adds r0, r6, #0x0
	adds r0, #0x10
	movs r1, #0x01
	movs r2, #0x01
	bl AnimStart
	ldr r0, [r5, #0x08]
	mov r12, r0
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _0803C254
	ldr r1, [r5, #0x04]
	ldr r2, _0803C24C @ =0xFFFF9C00
	adds r0, r1, r2
	ldr r3, _0803C250 @ =0xFFFFBA00
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	str r0, [sp, #0x000]
	mov r0, r12
	str r0, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0xD0
	str r0, [sp, #0x010]
	movs r0, #0x01
	mov r2, r12
	bl func_08013308
	b _0803C27A
_0803C24C: .4byte 0xFFFF9C00
_0803C250: .4byte 0xFFFFBA00
_0803C254:
	ldr r1, [r5, #0x04]
	movs r3, #0xC8
	lsls r3, r3, #0x07
	adds r0, r1, r3
	movs r4, #0x8C
	lsls r4, r4, #0x07
	adds r1, r1, r4
	ldr r3, [r5, #0x0C]
	str r0, [sp, #0x000]
	mov r0, r12
	str r0, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xD0
	str r0, [sp, #0x010]
	movs r0, #0x01
	mov r2, r12
	bl func_08013308
_0803C27A:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r4, r6, r1
	ldrh r1, [r4, #0x00]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x3C
	ble _0803C29A
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r0, r7, r3
	movs r1, #0x02
_0803C292:
	str r1, [r0, #0x00]
	movs r0, #0x00
	strh r0, [r4, #0x00]
	b _0803C4B6
_0803C29A:
	adds r0, r1, #0x1
	strh r0, [r4, #0x00]
	b _0803C4B6
_0803C2A0:
	movs r4, #0xAA
	lsls r4, r4, #0x01
	adds r5, r6, r4
	movs r1, #0x00
	ldsh r0, [r5, r1]
	adds r4, r6, #0x0
	adds r4, #0x10
	cmp r0, #0x00
	bne _0803C2BC
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl AnimStart
_0803C2BC:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C2E2
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
_0803C2E2:
	bl func_080128EC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C2F0
	b _0803C4B0
_0803C2F0:
	mov r3, r8
	str r0, [r3, #0x00]
	b _0803C4A8
_0803C2F6:
	movs r4, #0xB4
	lsls r4, r4, #0x01
	adds r0, r6, r4
	movs r1, #0x00
	mov r9, r1
	str r1, [r0, #0x00]
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r2, r2, r7
	mov r8, r2
	ldr r0, [r2, #0x00]
	cmp r0, #0x01
	beq _0803C37C
	cmp r0, #0x01
	bcc _0803C31C
	cmp r0, #0x02
	bne _0803C31A
	b _0803C47A
_0803C31A:
	b _0803C4B6
_0803C31C:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r4, r6, r3
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _0803C354
	ldr r0, _0803C370 @ =0x0813E11C
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x02
	movs r3, #0x00
	bl func_08019068
	movs r2, #0xC4
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r3, #0xC6
	lsls r3, r3, #0x01
	adds r2, r7, r3
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r3, r7, r0
	adds r0, r5, #0x0
	bl func_0801C700
_0803C354:
	adds r0, r6, #0x0
	adds r0, #0x10
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C374
	movs r0, #0x01
	mov r1, r8
	str r0, [r1, #0x00]
	mov r2, r9
	strh r2, [r4, #0x00]
	b _0803C4B6
	.byte 0x00, 0x00
_0803C370: .4byte 0x0813E11C
_0803C374:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	b _0803C4B6
_0803C37C:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r0, r6, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	adds r4, r6, #0x0
	adds r4, #0x10
	cmp r0, #0x00
	bne _0803C3A2
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	movs r1, #0xAB
	lsls r1, r1, #0x01
	adds r0, r6, r1
	mov r2, r9
	strh r2, [r0, #0x00]
_0803C3A2:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C46C
	movs r3, #0xAB
	lsls r3, r3, #0x01
	adds r0, r6, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r0, #0x00
	bne _0803C448
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803C408
	ldr r1, [r5, #0x04]
	ldr r0, _0803C400 @ =0xFFFFEA00
	adds r1, r1, r0
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	ldr r4, _0803C404 @ =0xFFFFC400
	adds r3, r3, r4
	movs r4, #0xC4
	lsls r4, r4, #0x01
	adds r0, r7, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r4, #0x04
	adds r0, r7, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r4, #0x04
	adds r0, r7, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	movs r0, #0xD1
	str r0, [sp, #0x00C]
	movs r0, #0x01
	bl func_08015834
	b _0803C43C
_0803C400: .4byte 0xFFFFEA00
_0803C404: .4byte 0xFFFFC400
_0803C408:
	ldr r1, [r5, #0x04]
	movs r0, #0xB0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	ldr r4, _0803C468 @ =0xFFFFC400
	adds r3, r3, r4
	movs r4, #0xC4
	lsls r4, r4, #0x01
	adds r0, r7, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r4, #0x04
	adds r0, r7, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r4, #0x04
	adds r0, r7, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	movs r0, #0xD1
	str r0, [sp, #0x00C]
	movs r0, #0x01
	bl func_08015834
_0803C43C:
	movs r0, #0xAB
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0803C448:
	bl func_080128EC
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	bne _0803C46C
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x02
	str r1, [r0, #0x00]
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r0, r6, r3
	strh r2, [r0, #0x00]
	b _0803C4B6
_0803C468: .4byte 0xFFFFC400
_0803C46C:
	movs r4, #0xAA
	lsls r4, r4, #0x01
	adds r1, r6, r4
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _0803C4B6
_0803C47A:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r5, r6, r0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	adds r4, r6, #0x0
	adds r4, #0x10
	cmp r0, #0x00
	bne _0803C496
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl AnimStart
_0803C496:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803C4B0
	mov r2, r9
	mov r3, r8
	str r2, [r3, #0x00]
_0803C4A8:
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _0803C4B6
_0803C4B0:
	ldrh r0, [r5, #0x00]
	adds r0, #0x01
	strh r0, [r5, #0x00]
_0803C4B6:
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
