.syntax unified
	.align 2, 0
	.global func_08016750
	.thumb
	.thumb_func
	.type func_08016750, %function
func_08016750: @ 08016750
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r9, r3
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080167E0
	bl func_08012674
	ldr r0, _080167C8 @ =0x02034928
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
	ldr r0, _080167CC @ =0x09EDAA20
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r8
	ldr r1, [r0, #0x00]
	movs r0, #0x26
	str r0, [r1, #0x1C]
	adds r0, #0xDA
	str r0, [r1, #0x20]
	movs r0, #0x07
	str r0, [r1, #0x28]
	movs r0, #0x99
	str r0, [r1, #0x2C]
	mov r2, r9
	cmp r2, #0x00
	beq _080167D0
	adds r1, #0x24
	ldrb r0, [r1, #0x00]
	adds r0, #0x28
	b _080167D6
	.byte 0x00, 0x00
_080167C8: .4byte 0x02034928
_080167CC: .4byte 0x09EDAA20
_080167D0:
	adds r1, #0x24
	ldrb r0, [r1, #0x00]
	subs r0, #0x28
_080167D6:
	strb r0, [r1, #0x00]
	ldr r0, _080167F0 @ =0x02034928
	ldr r1, [r0, #0x00]
	ldr r0, _080167F4 @ =0x080166F9
	str r0, [r1, #0x04]
_080167E0:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080167F0: .4byte 0x02034928
_080167F4: .4byte 0x080166F9
.syntax divided
