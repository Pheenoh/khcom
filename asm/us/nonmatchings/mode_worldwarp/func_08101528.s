.syntax unified
	.align 2, 0
	.global func_08101528
	.thumb
	.thumb_func
	.type func_08101528, %function
func_08101528: @ 08101528
	ldr r1, _08101534 @ =0x02039BB0
	movs r2, #0xBA
	lsls r2, r2, #0x01
	adds r1, r1, r2
	str r0, [r1, #0x00]
	bx lr
_08101534: .4byte 0x02039BB0
.syntax divided
