.syntax unified
	.align 2, 0
	.global func_08013994
	.thumb
	.thumb_func
	.type func_08013994, %function
func_08013994: @ 08013994
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r4, r2, #0x0
	movs r0, #0x02
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080139E4
	bl func_08012674
	ldr r5, _080139EC @ =0x02034928
	ldr r0, [r5, #0x00]
	str r6, [r0, #0x10]
	str r7, [r0, #0x14]
	ldr r2, _080139F0 @ =0xFFFFF000
	adds r1, r4, r2
	str r1, [r0, #0x18]
	mov r4, sp
	adds r4, #0x06
	str r1, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl func_0801909C
	ldr r0, _080139F4 @ =0x09EDA780
	add r1, sp, #0x004
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r1, [r5, #0x00]
	ldr r0, _080139F8 @ =0x08012909
	str r0, [r1, #0x04]
_080139E4:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080139EC: .4byte 0x02034928
_080139F0: .4byte 0xFFFFF000
_080139F4: .4byte 0x09EDA780
_080139F8: .4byte func_08012908
.syntax divided
