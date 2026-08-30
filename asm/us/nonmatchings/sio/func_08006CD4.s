.syntax unified
	.align 2, 0
	.global func_08006CD4
	.thumb
	.thumb_func
	.type func_08006CD4, %function
func_08006CD4: @ 08006CD4
	ldr r0, _08006CE0 @ =0x03006C14
	ldr r1, [r0, #0x00]
	ldr r0, _08006CE4 @ =0x080005AD
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006CE0: .4byte 0x03006C14
_08006CE4: .4byte 0x080005AD
.syntax divided
