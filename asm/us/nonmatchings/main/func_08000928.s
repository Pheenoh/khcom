.syntax unified
	.align 2, 0
	.global func_08000928
	.thumb
	.thumb_func
	.type func_08000928, %function
func_08000928: @ 08000928
	push {lr}
	ldr r1, _08000934 @ =0x030074B8
	bl func_080008A8
	pop {r1}
	bx r1
_08000934: .4byte 0x030074B8
.syntax divided
