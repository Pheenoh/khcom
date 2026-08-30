.syntax unified
	.align 2, 0
	.global task_emy_04_1
	.thumb
	.thumb_func
	.type task_emy_04_1, %function
task_emy_04_1: @ 08037950
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	adds r4, r0, #0x0
	mov r8, r4
	movs r0, #0x3C
	adds r0, r0, r4
	mov r9, r0
	adds r0, r4, #0x0
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803797A
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r0, #0x12
	str r0, [r1, #0x00]
_0803797A:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _08037988
	b _08037A94
_08037988:
	ldr r0, _080379BC @ =0x0813D5CC
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r7, #0xB4
	lsls r7, r7, #0x01
	adds r1, r4, r7
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r1, #0xC3
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x02
	ble _080379C0
	mov r0, r9
	movs r1, #0x02
	bl func_08019190
	b _08037A82
_080379BC: .4byte 0x0813D5CC
_080379C0:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r0, r4, r3
	movs r7, #0x00
	ldsh r0, [r0, r7]
	cmp r0, #0x03
	bne _08037A68
	movs r5, #0x00
	movs r6, #0x00
	ldr r0, _080379E0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x80
	bl func_08000C8C
	b _08037A1C
	.byte 0x00, 0x00
_080379E0: .4byte 0x02039B84
_080379E4:
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x01
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08037A14
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r7, #0x2E
	ldsh r1, [r3, r7]
	movs r7, #0x2C
	ldsh r2, [r3, r7]
	subs r1, r1, r2
	cmp r0, r1
	bge _08037A14
	ldrh r0, [r3, #0x2E]
	ldrh r1, [r3, #0x2C]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, r3, #0x0
_08037A14:
	adds r0, r3, #0x0
	adds r0, #0xB8
	bl func_08000CD4
_08037A1C:
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _080379E4
	cmp r5, #0x00
	bne _08037A28
	mov r5, r9
_08037A28:
	movs r0, #0x2C
	ldsh r1, [r5, r0]
	movs r2, #0x2E
	ldsh r0, [r5, r2]
	cmp r1, r0
	bne _08037A3E
	mov r0, r9
	movs r1, #0x02
	bl func_08019190
	b _08037A82
_08037A3E:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x20
	movs r3, #0x00
	orrs r0, r2
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	ldr r0, _08037A8C @ =0x0000FFE2
	strh r0, [r5, #0x20]
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x00
	bl func_08012AAC
	movs r1, #0xC3
	lsls r1, r1, #0x01
	add r1, r8
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08037A68:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldrh r2, [r1, #0x00]
	movs r7, #0x00
	ldsh r0, [r1, r7]
	cmp r0, #0x0D
	ble _08037A90
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08037A94
_08037A82:
	adds r0, r4, #0x0
	bl func_0800CB4C
	b _08037A94
	.byte 0x00, 0x00
_08037A8C: .4byte 0x0000FFE2
_08037A90:
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
_08037A94:
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
