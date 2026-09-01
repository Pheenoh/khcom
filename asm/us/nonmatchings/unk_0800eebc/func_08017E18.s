.syntax unified
	.align 2, 0
	.global func_08017E18
	.thumb
	.thumb_func
	.type func_08017E18, %function
func_08017E18: @ 08017E18
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	mov r9, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	bne _08017EDE
	bl func_08012674
	ldr r7, _08017E9C @ =0x02034928
	ldr r1, [r7, #0x00]
	strh r5, [r1, #0x26]
	str r6, [r1, #0x10]
	ldr r0, _08017EA0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xDE
	movs r4, #0x00
	ldsh r3, [r2, r4]
	adds r0, #0xE0
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r3, r3, r0
	lsls r3, r3, #0x07
	str r3, [r1, #0x14]
	str r5, [r1, #0x18]
	mov r4, r9
	str r4, [r1, #0x48]
	movs r0, #0x14
	strh r0, [r1, #0x0A]
	mov r4, sp
	adds r4, #0x06
	str r5, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r6, #0x0
	bl WorldToScreen
	ldr r0, _08017EA4 @ =0x09EDAC60
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r4, r8
	cmp r4, #0x00
	beq _08017EAC
	ldr r0, [r7, #0x00]
	movs r1, #0x0A
	str r1, [r0, #0x1C]
	ldr r2, _08017EA8 @ =0xFFFFC900
	adds r1, r6, r2
	str r1, [r0, #0x28]
	b _08017EC4
_08017E9C: .4byte 0x02034928
_08017EA0: .4byte 0x02039B84
_08017EA4: .4byte 0x09EDAC60
_08017EA8: .4byte 0xFFFFC900
_08017EAC:
	ldr r2, [r7, #0x00]
	movs r0, #0x0A
	negs r0, r0
	str r0, [r2, #0x1C]
	movs r3, #0xDC
	lsls r3, r3, #0x06
	adds r0, r6, r3
	str r0, [r2, #0x28]
	ldrh r0, [r2, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
_08017EC4:
	ldr r0, _08017EEC @ =0x02034928
	ldr r1, [r0, #0x00]
	movs r0, #0x0A
	str r0, [r1, #0x20]
	ldrh r2, [r1, #0x34]
	movs r0, #0x20
	orrs r0, r2
	strh r0, [r1, #0x34]
	ldr r0, _08017EF0 @ =0x08017C55
	str r0, [r1, #0x04]
	movs r0, #0x00
	bl func_08006B34
_08017EDE:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08017EEC: .4byte 0x02034928
_08017EF0: .4byte 0x08017C55
.syntax divided
