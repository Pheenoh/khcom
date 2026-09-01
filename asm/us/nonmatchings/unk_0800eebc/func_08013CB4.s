.syntax unified
	.align 2, 0
	.global func_08013CB4
	.thumb
	.thumb_func
	.type func_08013CB4, %function
func_08013CB4: @ 08013CB4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r7, r1, #0x0
	adds r5, r2, #0x0
	adds r6, r3, #0x0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08013D40
	bl func_08012674
	ldr r0, _08013D50 @ =0x02034928
	mov r8, r0
	ldr r0, [r0, #0x00]
	str r7, [r0, #0x10]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
	ldr r1, [sp, #0x024]
	str r1, [r0, #0x30]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	adds r3, r5, #0x0
	bl WorldToScreen
	ldr r0, _08013D54 @ =0x09EDA768
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	movs r0, #0x80
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, [sp, #0x028]
	str r0, [r1, #0x48]
	ldr r0, _08013D58 @ =0x08013B01
	str r0, [r1, #0x04]
	mov r2, r9
	strh r2, [r1, #0x26]
	ldr r0, _08013D5C @ =0x02039B84
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
_08013D40:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08013D50: .4byte 0x02034928
_08013D54: .4byte 0x09EDA768
_08013D58: .4byte 0x08013B01
_08013D5C: .4byte 0x02039B84
.syntax divided
