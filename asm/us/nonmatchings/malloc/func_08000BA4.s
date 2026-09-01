.syntax unified
	.align 2, 0
	.global func_08000BA4
	.thumb
	.thumb_func
	.type func_08000BA4, %function
func_08000BA4: @ 08000BA4
	movs r1, #0x00
	str r1, [r0, #0x00]
	str r1, [r0, #0x04]
	str r1, [r0, #0x08]
	str r1, [r0, #0x0C]
	bx lr
.syntax divided
