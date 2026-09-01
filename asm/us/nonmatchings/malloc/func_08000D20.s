.syntax unified
	.align 2, 0
	.global func_08000D20
	.thumb
	.thumb_func
	.type func_08000D20, %function
func_08000D20: @ 08000D20
	str r2, [r0, #0x00]
	movs r1, #0x00
	strh r1, [r0, #0x0C]
	bx lr
.syntax divided
