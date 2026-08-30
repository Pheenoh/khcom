.syntax unified
	.align 2, 0
	.global func_08076330
	.thumb
	.thumb_func
	.type func_08076330, %function
func_08076330: @ 08076330
	ldr r1, _08076338 @ =0x02034A9C
	movs r0, #0x03
	str r0, [r1, #0x00]
	bx lr
_08076338: .4byte 0x02034A9C
.syntax divided
