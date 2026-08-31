.syntax unified
	.align 2, 0
	.global func_080139FC
	.thumb
	.thumb_func
	.type func_080139FC, %function
func_080139FC: @ 080139FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	movs r0, #0x02
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08013A50
	bl func_08012674
	ldr r0, _08013A5C @ =0x02034928
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
	ldr r0, _08013A60 @ =0x09EDA930
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, _08013A64 @ =0x08012909
	str r0, [r1, #0x04]
_08013A50:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08013A5C: .4byte 0x02034928
_08013A60: .4byte 0x09EDA930
_08013A64: .4byte func_08012908
.syntax divided
