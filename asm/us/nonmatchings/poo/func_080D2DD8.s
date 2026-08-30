.syntax unified
	.align 2, 0
	.global func_080D2DD8
	.thumb
	.thumb_func
	.type func_080D2DD8, %function
func_080D2DD8: @ 080D2DD8
	push {r4, r5, r6, lr}
	add sp, #-0x018
	mov r0, sp
	ldr r1, _080D2E18 @ =0x096FDA74
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	movs r0, #0x01
	bl func_080D2D94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D2E14
	movs r6, #0x00
	movs r5, #0x00
	mov r4, sp
_080D2DFA:
	ldr r0, [r4, #0x00]
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D2E08
	adds r6, #0x01
_080D2E08:
	adds r4, #0x04
	adds r5, #0x01
	cmp r5, #0x05
	bls _080D2DFA
	cmp r6, #0x04
	ble _080D2E1C
_080D2E14:
	movs r0, #0x01
	b _080D2E1E
_080D2E18: .4byte 0x096FDA74
_080D2E1C:
	movs r0, #0x00
_080D2E1E:
	add sp, #0x018
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
