.syntax unified
	.align 2, 0
	.global func_0808E344
	.thumb
	.thumb_func
	.type func_0808E344, %function
func_0808E344: @ 0808E344
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x08]
	cmp r0, #0x00
	beq _0808E35E
	bl func_080028C0
	ldr r0, [r4, #0x0C]
	bl func_08002C10
	movs r0, #0x00
	str r0, [r4, #0x08]
	str r0, [r4, #0x0C]
_0808E35E:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
