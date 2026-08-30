.syntax unified
	.align 2, 0
	.global func_080F80C0
	.thumb
	.thumb_func
	.type func_080F80C0, %function
func_080F80C0: @ 080F80C0
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r2, #0x00
	ldr r0, _080F80F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xCC
	ldr r0, [r0, #0x7C]
	ldr r1, [r1, #0x00]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	bgt _080F80DA
	movs r2, #0x01
_080F80DA:
	ldr r0, [r5, #0x18]
	cmp r0, r2
	beq _080F80F2
	str r2, [r5, #0x18]
	movs r4, #0x00
_080F80E4:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080F800C
	adds r4, #0x01
	cmp r4, #0x05
	bls _080F80E4
_080F80F2:
	pop {r4, r5}
	pop {r0}
	bx r0
_080F80F8: .4byte 0x02039B84
.syntax divided
