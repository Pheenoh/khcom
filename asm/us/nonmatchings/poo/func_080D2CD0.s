.syntax unified
	.align 2, 0
	.global func_080D2CD0
	.thumb
	.thumb_func
	.type func_080D2CD0, %function
func_080D2CD0: @ 080D2CD0
	ldr r3, _080D2CDC @ =0x0203C470
	ldrh r2, [r3, #0x3C]
	strh r2, [r0, #0x00]
	ldrh r0, [r3, #0x3E]
	strh r0, [r1, #0x00]
	bx lr
_080D2CDC: .4byte 0x0203C470
.syntax divided
