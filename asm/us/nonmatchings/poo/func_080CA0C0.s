.syntax unified
	.align 2, 0
	.global func_080CA0C0
	.thumb
	.thumb_func
	.type func_080CA0C0, %function
func_080CA0C0: @ 080CA0C0
	ldr r1, _080CA0C8 @ =0x02034DE1
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bx lr
_080CA0C8: .4byte 0x02034DE1
.syntax divided
