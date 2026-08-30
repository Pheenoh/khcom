.syntax unified
	.align 2, 0
	.global func_08006CC8
	.thumb
	.thumb_func
	.type func_08006CC8, %function
func_08006CC8: @ 08006CC8
	ldr r1, _08006CD0 @ =0x03006C14
	ldr r1, [r1, #0x00]
	str r0, [r1, #0x00]
	bx lr
_08006CD0: .4byte 0x03006C14
.syntax divided
