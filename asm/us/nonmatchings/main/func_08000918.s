.syntax unified
	.align 2, 0
	.global func_08000918
	.thumb
	.thumb_func
	.type func_08000918, %function
func_08000918: @ 08000918
	push {lr}
	ldr r1, _08000924 @ =0x030074A8
	bl func_080008A8
	pop {r1}
	bx r1
_08000924: .4byte 0x030074A8
.syntax divided
