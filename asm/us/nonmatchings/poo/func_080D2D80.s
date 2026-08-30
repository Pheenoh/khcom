.syntax unified
	.align 2, 0
	.global func_080D2D80
	.thumb
	.thumb_func
	.type func_080D2D80, %function
func_080D2D80: @ 080D2D80
	ldr r2, _080D2D90 @ =0x0203C470
	movs r1, #0x01
	lsls r1, r0
	ldr r0, [r2, #0x24]
	bics r0, r1
	str r0, [r2, #0x24]
	bx lr
	.byte 0x00, 0x00
_080D2D90: .4byte 0x0203C470
.syntax divided
