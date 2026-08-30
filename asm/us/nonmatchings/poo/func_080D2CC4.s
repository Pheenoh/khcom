.syntax unified
	.align 2, 0
	.global func_080D2CC4
	.thumb
	.thumb_func
	.type func_080D2CC4, %function
func_080D2CC4: @ 080D2CC4
	ldr r2, _080D2CCC @ =0x0203C470
	strh r0, [r2, #0x3C]
	strh r1, [r2, #0x3E]
	bx lr
_080D2CCC: .4byte 0x0203C470
.syntax divided
