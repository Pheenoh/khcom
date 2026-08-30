.syntax unified
	.align 2, 0
	.global func_08000AD8
	.thumb
	.thumb_func
	.type func_08000AD8, %function
func_08000AD8: @ 08000AD8
	ldr r1, _08000AE0 @ =0x030074A8
	str r0, [r1, #0x0C]
	bx lr
	.byte 0x00, 0x00
_08000AE0: .4byte 0x030074A8
.syntax divided
