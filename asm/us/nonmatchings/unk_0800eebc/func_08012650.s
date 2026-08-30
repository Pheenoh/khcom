.syntax unified
	.align 2, 0
	.global func_08012650
	.thumb
	.thumb_func
	.type func_08012650, %function
func_08012650: @ 08012650
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x08
	str r1, [r0, #0x10]
	bx lr
.syntax divided
