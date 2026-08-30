.syntax unified
	.align 2, 0
	.global func_08006C68
	.thumb
	.thumb_func
	.type func_08006C68, %function
func_08006C68: @ 08006C68
	ldr r0, _08006C78 @ =0x03006C58
	ldr r0, [r0, #0x00]
	ldr r1, _08006C7C @ =0x080005A9
	str r1, [r0, #0x00]
	ldr r0, _08006C80 @ =0x03006C6C
	str r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006C78: .4byte 0x03006C58
_08006C7C: .4byte 0x080005A9
_08006C80: .4byte 0x03006C6C
.syntax divided
