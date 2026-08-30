.syntax unified
	.align 2, 0
	.global func_080D4D44
	.thumb
	.thumb_func
	.type func_080D4D44, %function
func_080D4D44: @ 080D4D44
	ldr r1, _080D4D4C @ =0x0203C460
	movs r0, #0x00
	str r0, [r1, #0x00]
	bx lr
_080D4D4C: .4byte 0x0203C460
.syntax divided
