.syntax unified
	.align 2, 0
	.global func_08076318
	.thumb
	.thumb_func
	.type func_08076318, %function
func_08076318: @ 08076318
	ldr r1, _08076320 @ =0x02034A9C
	movs r0, #0x01
	str r0, [r1, #0x00]
	bx lr
_08076320: .4byte 0x02034A9C
.syntax divided
