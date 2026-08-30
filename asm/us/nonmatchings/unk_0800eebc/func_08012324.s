.syntax unified
	.align 2, 0
	.global func_08012324
	.thumb
	.thumb_func
	.type func_08012324, %function
func_08012324: @ 08012324
	str r1, [r0, #0x04]
	lsls r2, r2, #0x01
	str r2, [r0, #0x08]
	str r3, [r0, #0x0C]
	bx lr
	.byte 0x00, 0x00
.syntax divided
