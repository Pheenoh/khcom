.syntax unified
	.align 2, 0
	.global func_08116E80
	.thumb
	.thumb_func
	.type func_08116E80, %function
func_08116E80: @ 08116E80
	ldr r1, _08116E88 @ =0x02036028
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bx lr
_08116E88: .4byte 0x02036028
.syntax divided
