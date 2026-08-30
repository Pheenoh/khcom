.syntax unified
	.align 2, 0
	.global func_0801CD8C
	.thumb
	.thumb_func
	.type func_0801CD8C, %function
func_0801CD8C: @ 0801CD8C
	str r1, [r0, #0x04]
	str r2, [r0, #0x08]
	str r3, [r0, #0x0C]
	bx lr
	.byte 0x01, 0x61, 0x70, 0x47
.syntax divided
