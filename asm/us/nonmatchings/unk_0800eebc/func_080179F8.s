.syntax unified
	.align 2, 0
	.global func_080179F8
	.thumb
	.thumb_func
	.type func_080179F8, %function
func_080179F8: @ 080179F8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	mov r8, r0
	mov r9, r1
	adds r7, r2, #0x0
	adds r5, r3, #0x0
	ldr r0, [sp, #0x024]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	bne _08017AA0
	bl func_08012674
	ldr r0, _08017A50 @ =0x02034928
	ldr r2, [r0, #0x00]
	mov r0, r8
	str r0, [r2, #0x10]
	mov r3, r9
	str r3, [r2, #0x14]
	str r7, [r2, #0x18]
	movs r0, #0xDC
	strh r0, [r2, #0x0A]
	strh r4, [r2, #0x0C]
	strh r4, [r2, #0x26]
	str r5, [r2, #0x48]
	movs r0, #0x0A
	str r0, [r2, #0x20]
	cmp r6, #0x00
	beq _08017A54
	subs r0, #0x14
	str r0, [r2, #0x1C]
	ldrh r0, [r2, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
	b _08017A56
_08017A50: .4byte 0x02034928
_08017A54:
	str r0, [r2, #0x1C]
_08017A56:
	mov r4, sp
	adds r4, #0x06
	str r7, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	mov r2, r8
	mov r3, r9
	bl WorldToScreen
	ldr r0, _08017AB0 @ =0x09EDAC18
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r4, _08017AB4 @ =0x02034928
	ldr r1, [r4, #0x00]
	ldr r0, _08017AB8 @ =0x080177ED
	str r0, [r1, #0x04]
	movs r0, #0x00
	bl func_08006B34
	ldr r0, _08017ABC @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r4, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08017AA0:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08017AB0: .4byte 0x09EDAC18
_08017AB4: .4byte 0x02034928
_08017AB8: .4byte 0x080177ED
_08017ABC: .4byte 0x02039B84
.syntax divided
