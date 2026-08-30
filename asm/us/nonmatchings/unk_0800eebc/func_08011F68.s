.syntax unified
	.align 2, 0
	.global func_08011F68
	.thumb
	.thumb_func
	.type func_08011F68, %function
func_08011F68: @ 08011F68
	push {lr}
	adds r2, r0, #0x0
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl func_08011398
	pop {r1}
	bx r1
.syntax divided
