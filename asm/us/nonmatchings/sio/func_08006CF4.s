.syntax unified
	.align 2, 0
	.global func_08006CF4
	.thumb
	.thumb_func
	.type func_08006CF4, %function
func_08006CF4: @ 08006CF4
	ldr r0, _08006D00 @ =0x03006C60
	ldr r1, [r0, #0x00]
	ldr r0, _08006D04 @ =0x080005AD
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006D00: .4byte 0x03006C60
_08006D04: .4byte 0x080005AD
.syntax divided
