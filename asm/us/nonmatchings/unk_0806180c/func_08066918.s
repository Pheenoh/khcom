.syntax unified
	.align 2, 0
	.global func_08066918
	.thumb
	.thumb_func
	.type func_08066918, %function
func_08066918: @ 08066918
	push {r4, lr}
	adds r4, r1, #0x0
	bl func_080028C0
	adds r0, r4, #0x0
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
