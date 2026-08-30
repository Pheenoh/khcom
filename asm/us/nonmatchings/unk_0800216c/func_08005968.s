.syntax unified
	.align 2, 0
	.global func_08005968
	.thumb
	.thumb_func
	.type func_08005968, %function
func_08005968: @ 08005968
	str r2, [r0, #0x04]
	str r1, [r0, #0x00]
	movs r1, #0x00
	str r1, [r0, #0x14]
	bx lr
	.byte 0x00, 0x00
.syntax divided
