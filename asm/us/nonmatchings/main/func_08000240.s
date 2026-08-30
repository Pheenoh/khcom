.syntax unified
	.align 2, 0
	.global func_08000240
	.thumb
	.thumb_func
	.type func_08000240, %function
func_08000240: @ 08000240
	ldr r0, _08000244 @ =0x02000000
	bx lr
_08000244: .4byte 0x02000000
.syntax divided
