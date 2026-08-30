.syntax unified
	.align 2, 0
	.global func_080EA1E8
	.thumb
	.thumb_func
	.type func_080EA1E8, %function
func_080EA1E8: @ 080EA1E8
	ldr r1, _080EA1F0 @ =0x02034FD4
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080EA1F0: .4byte 0x02034FD4
.syntax divided
