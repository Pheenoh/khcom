.syntax unified
	.align 2, 0
	.global func_080DDDDC
	.thumb
	.thumb_func
	.type func_080DDDDC, %function
func_080DDDDC: @ 080DDDDC
	movs r2, #0x00
	strh r2, [r0, #0x00]
	strh r2, [r0, #0x02]
	movs r2, #0x01
	strb r2, [r0, #0x04]
	str r1, [r0, #0x08]
	bx lr
	.byte 0x00, 0x00
.syntax divided
