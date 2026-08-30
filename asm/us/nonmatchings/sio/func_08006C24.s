.syntax unified
	.align 2, 0
	.global func_08006C24
	.thumb
	.thumb_func
	.type func_08006C24, %function
func_08006C24: @ 08006C24
	ldr r0, _08006C34 @ =0x03006C5C
	ldr r0, [r0, #0x00]
	ldr r1, _08006C38 @ =0x080004DD
	str r1, [r0, #0x00]
	ldr r0, _08006C3C @ =0x03006C70
	str r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006C34: .4byte 0x03006C5C
_08006C38: .4byte 0x080004DD
_08006C3C: .4byte 0x03006C70
.syntax divided
