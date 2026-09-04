.syntax unified
	.align 2, 0
	.global func_080161F8
	.thumb
	.thumb_func
	.type func_080161F8, %function
func_080161F8: @ 080161F8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r5, r2, #0x0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r10, r3
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	bne _08016284
	bl func_08012674
	ldr r0, _08016294 @ =0x02034928
	mov r8, r0
	ldr r0, [r0, #0x00]
	str r6, [r0, #0x10]
	str r7, [r0, #0x14]
	str r5, [r0, #0x18]
	movs r1, #0x06
	add r1, sp
	mov r9, r1
	str r5, [sp, #0x000]
	add r0, sp, #0x004
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl WorldToScreen
	mov r3, r8
	ldr r2, [r3, #0x00]
	strh r4, [r2, #0x26]
	mov r0, r10
	cmp r0, #0x00
	beq _08016258
	ldrh r0, [r2, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
	ldr r0, _08016298 @ =0xFFFFFF00
	str r0, [r2, #0x1C]
_08016258:
	mov r1, r8
	ldr r0, [r1, #0x00]
	str r4, [r0, #0x3C]
	ldr r0, _0801629C @ =0x0000027D
	bl m4aSongNumStart
	ldr r0, _080162A0 @ =0x09EDAAF8
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	mov r3, r9
	movs r4, #0x00
	ldsh r2, [r3, r4]
	bl func_08006778
	movs r0, #0x06
	bl func_08006B34
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, _080162A4 @ =0x080160C1
	str r0, [r1, #0x04]
_08016284:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08016294: .4byte 0x02034928
_08016298: .4byte 0xFFFFFF00
_0801629C: .4byte 0x0000027D
_080162A0: .4byte 0x09EDAAF8
_080162A4: .4byte 0x080160C1
.syntax divided
