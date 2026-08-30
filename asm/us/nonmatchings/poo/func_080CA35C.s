.syntax unified
	.align 2, 0
	.global func_080CA35C
	.thumb
	.thumb_func
	.type func_080CA35C, %function
func_080CA35C: @ 080CA35C
	ldr r1, _080CA364 @ =0x0203C3F4
	movs r0, #0x00
	str r0, [r1, #0x00]
	bx lr
_080CA364: .4byte 0x0203C3F4
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
