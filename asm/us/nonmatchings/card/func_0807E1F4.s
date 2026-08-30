.syntax unified
	.align 2, 0
	.global func_0807E1F4
	.thumb
	.thumb_func
	.type func_0807E1F4, %function
func_0807E1F4: @ 0807E1F4
	ldr r1, _0807E1FC @ =0x02034AA4
	movs r0, #0x01
	str r0, [r1, #0x00]
	bx lr
_0807E1FC: .4byte 0x02034AA4
.syntax divided
