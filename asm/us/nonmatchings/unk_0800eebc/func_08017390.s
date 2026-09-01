.syntax unified
	.align 2, 0
	.global func_08017390
	.thumb
	.thumb_func
	.type func_08017390, %function
func_08017390: @ 08017390
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
	bne _080173F4
	bl func_08012674
	ldr r0, _08017400 @ =0x02034928
	mov r8, r0
	ldr r0, [r0, #0x00]
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
	ldr r0, _08017404 @ =0x09EDAB88
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, _08017408 @ =0x08012909
	str r0, [r1, #0x04]
	ldr r0, _0801740C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
_080173F4:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08017400: .4byte 0x02034928
_08017404: .4byte 0x09EDAB88
_08017408: .4byte func_08012908
_0801740C: .4byte 0x02039B84
.syntax divided
