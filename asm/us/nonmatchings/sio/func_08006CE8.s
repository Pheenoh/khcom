.syntax unified
	.align 2, 0
	.global func_08006CE8
	.thumb
	.thumb_func
	.type func_08006CE8, %function
func_08006CE8: @ 08006CE8
	ldr r1, _08006CF0 @ =0x03006C60
	ldr r1, [r1, #0x00]
	str r0, [r1, #0x00]
	bx lr
_08006CF0: .4byte 0x03006C60
.syntax divided
