.syntax unified
	.align 2, 0
	.global func_08076360
	.thumb
	.thumb_func
	.type func_08076360, %function
func_08076360: @ 08076360
	push {lr}
	ldr r1, _08076370 @ =0x02034A9C
	movs r0, #0x06
	str r0, [r1, #0x00]
	bl func_0807E23C
	pop {r0}
	bx r0
_08076370: .4byte 0x02034A9C
.syntax divided
