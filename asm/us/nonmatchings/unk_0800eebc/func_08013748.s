.syntax unified
	.align 2, 0
	.global func_08013748
	.thumb
	.thumb_func
	.type func_08013748, %function
func_08013748: @ 08013748
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	movs r0, #0x01
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080137AA
	bl func_08012674
	ldr r5, _080137B8 @ =0x02034928
	ldr r1, [r5, #0x00]
	str r6, [r1, #0x10]
	str r7, [r1, #0x14]
	mov r0, r8
	str r0, [r1, #0x18]
	cmp r4, #0x00
	beq _0801377E
	ldr r0, _080137BC @ =0xFFFFFF00
	str r0, [r1, #0x1C]
_0801377E:
	mov r4, sp
	adds r4, #0x06
	ldr r0, [r5, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl func_0801909C
	ldr r0, _080137C0 @ =0x09EDA648
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r1, [r5, #0x00]
	ldr r0, _080137C4 @ =0x08012909
	str r0, [r1, #0x04]
_080137AA:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080137B8: .4byte 0x02034928
_080137BC: .4byte 0xFFFFFF00
_080137C0: .4byte 0x09EDA648
_080137C4: .4byte func_08012908
.syntax divided
