.syntax unified
	.align 2, 0
	.global func_08014020
	.thumb
	.thumb_func
	.type func_08014020, %function
func_08014020: @ 08014020
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	movs r0, #0x01
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080140A4
	bl func_08012674
	ldr r0, _080140B0 @ =0x02034928
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
	ldr r0, _080140B4 @ =0x09EDA600
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, _080140B8 @ =0x08014001
	str r0, [r1, #0x04]
	movs r0, #0x8B
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	mov r1, r8
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2, #0x34]
	ldr r0, _080140BC @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	mov r3, r8
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_080140A4:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080140B0: .4byte 0x02034928
_080140B4: .4byte 0x09EDA600
_080140B8: .4byte 0x08014001
_080140BC: .4byte 0x02039B84
.syntax divided
