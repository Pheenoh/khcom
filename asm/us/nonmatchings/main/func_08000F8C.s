.syntax unified
	.align 2, 0
	.global func_08000F8C
	.thumb
	.thumb_func
	.type func_08000F8C, %function
func_08000F8C: @ 08000F8C
	str r1, [r0, #0x20]
	bx lr
	.byte 0x00, 0x20, 0x70, 0x47
.syntax divided
