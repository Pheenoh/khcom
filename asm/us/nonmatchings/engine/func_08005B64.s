.syntax unified
	.align 2, 0
	.global func_08005B64
	.thumb
	.thumb_func
	.type func_08005B64, %function
func_08005B64: @ 08005B64
	movs r1, #0x00
	strh r1, [r0, #0x0E]
	strh r1, [r0, #0x0A]
	ldrh r2, [r0, #0x08]
	ldr r1, _08005B74 @ =0x0000EFFF
	ands r1, r2
	strh r1, [r0, #0x08]
	bx lr
_08005B74: .4byte 0x0000EFFF
.syntax divided
