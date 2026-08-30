.syntax unified
	.align 2, 0
	.global func_0801AF08
	.thumb
	.thumb_func
	.type func_0801AF08, %function
func_0801AF08: @ 0801AF08
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x38]
	ldr r3, _0801AF18 @ =0xFFFFDD6F
	ands r1, r3
	str r1, [r0, #0x34]
	str r2, [r0, #0x38]
	bx lr
	.byte 0x00, 0x00
_0801AF18: .4byte 0xFFFFDD6F
.syntax divided
