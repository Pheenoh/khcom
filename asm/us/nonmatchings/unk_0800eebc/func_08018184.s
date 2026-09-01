.syntax unified
	.align 2, 0
	.global func_08018184
	.thumb
	.thumb_func
	.type func_08018184, %function
func_08018184: @ 08018184
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	adds r4, r3, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x00
	bne _0801821E
	bl func_08012674
	ldr r0, _0801822C @ =0x02034928
	mov r9, r0
	ldr r0, [r0, #0x00]
	str r7, [r0, #0x10]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
	str r4, [r0, #0x48]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	adds r3, r5, #0x0
	bl WorldToScreen
	ldr r0, _08018230 @ =0x09EDACC0
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r9
	ldr r2, [r0, #0x00]
	mov r1, r8
	strh r1, [r2, #0x26]
	movs r0, #0x05
	str r0, [r2, #0x1C]
	str r0, [r2, #0x20]
	adds r0, #0xFB
	str r0, [r2, #0x28]
	ldrh r0, [r2, #0x34]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x34]
	ldr r0, _08018234 @ =0x000002AE
	bl m4aSongNumStart
	mov r2, r9
	ldr r1, [r2, #0x00]
	ldr r0, _08018238 @ =0x080180C9
	str r0, [r1, #0x04]
	ldr r0, _0801823C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	mov r3, r9
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_0801821E:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801822C: .4byte 0x02034928
_08018230: .4byte 0x09EDACC0
_08018234: .4byte 0x000002AE
_08018238: .4byte 0x080180C9
_0801823C: .4byte 0x02039B84
.syntax divided
