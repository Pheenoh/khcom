.syntax unified
	.align 2, 0
	.global func_080137C8
	.thumb
	.thumb_func
	.type func_080137C8, %function
func_080137C8: @ 080137C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	movs r0, #0x02
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08013832
	bl func_08012674
	ldr r5, _08013840 @ =0x02034928
	ldr r1, [r5, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x03
	adds r0, r4, r2
	str r0, [r1, #0x10]
	str r6, [r1, #0x14]
	ldr r0, _08013844 @ =0xFFFFF000
	add r0, r8
	str r0, [r1, #0x18]
	cmp r7, #0x00
	beq _08013806
	ldr r0, _08013848 @ =0xFFFFFF00
	str r0, [r1, #0x1C]
_08013806:
	mov r4, sp
	adds r4, #0x06
	ldr r0, [r5, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl WorldToScreen
	ldr r0, _0801384C @ =0x09EDA660
	add r1, sp, #0x004
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r1, [r5, #0x00]
	ldr r0, _08013850 @ =0x08012909
	str r0, [r1, #0x04]
_08013832:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08013840: .4byte 0x02034928
_08013844: .4byte 0xFFFFF000
_08013848: .4byte 0xFFFFFF00
_0801384C: .4byte 0x09EDA660
_08013850: .4byte func_08012908
.syntax divided
