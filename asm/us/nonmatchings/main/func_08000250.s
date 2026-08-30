.syntax unified
	.align 2, 0
	.global func_08000250
	.thumb
	.thumb_func
	.type func_08000250, %function
func_08000250: @ 08000250
	ldr r0, _08000254 @ =0x03000400
	bx lr
_08000254: .4byte 0x03000400
.syntax divided
