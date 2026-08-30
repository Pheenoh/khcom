.syntax unified
	.align 2, 0
	.global func_080CA09C
	.thumb
	.thumb_func
	.type func_080CA09C, %function
func_080CA09C: @ 080CA09C
	ldr r1, _080CA0A4 @ =0x02034DE0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bx lr
_080CA0A4: .4byte 0x02034DE0
.syntax divided
