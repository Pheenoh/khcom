.syntax unified
	.align 2, 0
	.global func_080007A8
	.thumb
	.thumb_func
	.type func_080007A8, %function
func_080007A8: @ 080007A8
	ldr r2, [r0, #0x04]
	ldr r1, [r0, #0x08]
	str r1, [r2, #0x08]
	ldr r1, [r0, #0x08]
	ldr r0, [r0, #0x04]
	str r0, [r1, #0x04]
	bx lr
	.byte 0x00, 0x00
.syntax divided
