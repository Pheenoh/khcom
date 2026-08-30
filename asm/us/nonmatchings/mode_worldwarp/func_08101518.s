.syntax unified
	.align 2, 0
	.global func_08101518
	.thumb
	.thumb_func
	.type func_08101518, %function
func_08101518: @ 08101518
	ldr r0, _08101524 @ =0x02039BB0
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bx lr
_08101524: .4byte 0x02039BB0
.syntax divided
