.syntax unified
	.align 2, 0
	.global func_080DFF4C
	.thumb
	.thumb_func
	.type func_080DFF4C, %function
func_080DFF4C: @ 080DFF4C
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080DFF30
	str r0, [r4, #0x0C]
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
