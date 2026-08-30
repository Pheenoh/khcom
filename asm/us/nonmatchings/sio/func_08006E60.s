.syntax unified
	.align 2, 0
	.global func_08006E60
	.thumb
	.thumb_func
	.type func_08006E60, %function
func_08006E60: @ 08006E60
	push {lr}
	bl func_08006D08
	bl func_08006E74
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
.syntax divided
