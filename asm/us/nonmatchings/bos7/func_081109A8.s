.syntax unified
	.align 2, 0
	.global func_081109A8
	.thumb
	.thumb_func
	.type func_081109A8, %function
func_081109A8: @ 081109A8
	ldr r1, [r0, #0x04]
	movs r2, #0x00
	movs r0, #0x05
	strh r0, [r1, #0x02]
	strh r2, [r1, #0x04]
	strh r2, [r1, #0x06]
	strh r2, [r1, #0x08]
	bx lr
.syntax divided
