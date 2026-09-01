.syntax unified
	.align 2, 0
	.global func_08017008
	.thumb
	.thumb_func
	.type func_08017008, %function
func_08017008: @ 08017008
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08017080
	bl func_08012674
	ldr r0, _0801708C @ =0x02034928
	mov r8, r0
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x01
	str r1, [r0, #0x1C]
	str r1, [r0, #0x20]
	str r7, [r0, #0x10]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	adds r3, r5, #0x0
	bl WorldToScreen
	ldr r0, _08017090 @ =0x09EDA858
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, _08017094 @ =0x08012909
	str r0, [r1, #0x04]
	ldr r0, _08017098 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	mov r1, r8
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08017080:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801708C: .4byte 0x02034928
_08017090: .4byte 0x09EDA858
_08017094: .4byte func_08012908
_08017098: .4byte 0x02039B84
.syntax divided
