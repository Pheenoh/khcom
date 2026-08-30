.syntax unified
	.align 2, 0
	.global func_080838EC
	.thumb
	.thumb_func
	.type func_080838EC, %function
func_080838EC: @ 080838EC
	ldr r1, _080838F4 @ =0x02039DDC
	movs r0, #0x07
	strb r0, [r1, #0x00]
	bx lr
_080838F4: .4byte 0x02039DDC
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
.syntax divided
