.syntax unified
	.align 2, 0
	.global func_0805F7B0
	.thumb
	.thumb_func
	.type func_0805F7B0, %function
func_0805F7B0: @ 0805F7B0
	ldr r1, _0805F7B8 @ =0x02034A24
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_0805F7B8: .4byte 0x02034A24
.syntax divided
