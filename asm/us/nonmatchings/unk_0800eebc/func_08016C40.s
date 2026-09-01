.syntax unified
	.align 2, 0
	.global func_08016C40
	.thumb
	.thumb_func
	.type func_08016C40, %function
func_08016C40: @ 08016C40
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	mov r8, r2
	mov r10, r3
	ldr r0, [sp, #0x028]
	ldr r1, [sp, #0x02C]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	bne _08016CDE
	bl func_08012674
	ldr r1, _08016CF0 @ =0x02034928
	ldr r0, [r1, #0x00]
	str r7, [r0, #0x10]
	str r4, [r0, #0x14]
	mov r2, r8
	str r2, [r0, #0x18]
	strh r6, [r0, #0x0A]
	strh r5, [r0, #0x26]
	adds r0, #0x24
	mov r3, r9
	strb r3, [r0, #0x00]
	mov r5, sp
	adds r5, #0x06
	ldr r0, [r1, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	bl WorldToScreen
	ldr r0, _08016CF4 @ =0x09EDAB28
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	ldr r0, _08016CF0 @ =0x02034928
	ldr r1, [r0, #0x00]
	mov r2, r10
	str r2, [r1, #0x20]
	ldr r0, _08016CF8 @ =0x0801519D
	str r0, [r1, #0x04]
	movs r0, #0x00
	bl func_08006B34
	ldr r0, _08016CFC @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r3, _08016CF0 @ =0x02034928
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08016CDE:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08016CF0: .4byte 0x02034928
_08016CF4: .4byte 0x09EDAB28
_08016CF8: .4byte 0x0801519D
_08016CFC: .4byte 0x02039B84
.syntax divided
