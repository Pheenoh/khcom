.syntax unified
	.align 2, 0
	.global func_08014780
	.thumb
	.thumb_func
	.type func_08014780, %function
func_08014780: @ 08014780
	ldr r3, _0801478C @ =0x02034928
	ldr r3, [r3, #0x00]
	str r0, [r3, #0x10]
	str r1, [r3, #0x14]
	str r2, [r3, #0x18]
	bx lr
_0801478C: .4byte 0x02034928
.syntax divided
