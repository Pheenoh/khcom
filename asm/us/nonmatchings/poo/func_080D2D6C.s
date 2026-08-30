.syntax unified
	.align 2, 0
	.global func_080D2D6C
	.thumb
	.thumb_func
	.type func_080D2D6C, %function
func_080D2D6C: @ 080D2D6C
	ldr r2, _080D2D7C @ =0x0203C470
	movs r1, #0x01
	lsls r1, r0
	ldr r0, [r2, #0x24]
	orrs r0, r1
	str r0, [r2, #0x24]
	bx lr
	.byte 0x00, 0x00
_080D2D7C: .4byte 0x0203C470
.syntax divided
