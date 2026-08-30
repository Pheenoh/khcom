.syntax unified
	.align 2, 0
	.global func_0801BCC0
	.thumb
	.thumb_func
	.type func_0801BCC0, %function
func_0801BCC0: @ 0801BCC0
	ldr r3, _0801BCD0 @ =0x02039B84
	ldr r3, [r3, #0x00]
	ldr r3, [r3, #0x7C]
	str r0, [r3, #0x04]
	str r1, [r3, #0x08]
	str r2, [r3, #0x0C]
	bx lr
	.byte 0x00, 0x00
_0801BCD0: .4byte 0x02039B84
.syntax divided
