.syntax unified
	.align 2, 0
	.global func_08006BA8
	.thumb
	.thumb_func
	.type func_08006BA8, %function
func_08006BA8: @ 08006BA8
	ldr r0, _08006BB0 @ =0x02034040
	ldr r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006BB0: .4byte 0x02034040
.syntax divided
