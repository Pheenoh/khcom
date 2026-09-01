.syntax unified
	.align 2, 0
	.global func_08014588
	.thumb
	.thumb_func
	.type func_08014588, %function
func_08014588: @ 08014588
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r5, r0, #0x0
	mov r8, r1
	adds r7, r2, #0x0
	adds r6, r3, #0x0
	ldr r0, [sp, #0x028]
	ldr r1, [sp, #0x02C]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r9, r1
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	bne _08014632
	bl func_08012674
	movs r0, #0x10
	movs r1, #0x00
	bl SetBlendAlpha
	ldr r1, _08014644 @ =0x02034928
	ldr r0, [r1, #0x00]
	str r5, [r0, #0x10]
	mov r2, r8
	str r2, [r0, #0x14]
	str r7, [r0, #0x18]
	strh r4, [r0, #0x26]
	str r6, [r0, #0x1C]
	str r6, [r0, #0x20]
	str r6, [r0, #0x28]
	str r4, [r0, #0x3C]
	strh r4, [r0, #0x36]
	mov r4, sp
	adds r4, #0x06
	str r7, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	mov r3, r8
	bl WorldToScreen
	ldr r0, _08014648 @ =0x09EDAA38
	add r1, sp, #0x004
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	movs r0, #0x00
	bl func_08006B34
	ldr r1, _08014644 @ =0x02034928
	ldr r0, [r1, #0x00]
	ldr r1, _0801464C @ =0x0801440D
	str r1, [r0, #0x04]
	mov r2, r10
	strh r2, [r0, #0x0A]
	mov r3, r9
	strh r3, [r0, #0x0C]
	ldr r0, _08014650 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r0, _08014644 @ =0x02034928
	ldr r2, [r0, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08014632:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08014644: .4byte 0x02034928
_08014648: .4byte 0x09EDAA38
_0801464C: .4byte 0x0801440D
_08014650: .4byte 0x02039B84
.syntax divided
