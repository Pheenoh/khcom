.syntax unified
	.align 2, 0
	.global func_08060598
	.thumb
	.thumb_func
	.type func_08060598, %function
func_08060598: @ 08060598
	ldr r1, _080605A0 @ =0x02034A20
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bx lr
_080605A0: .4byte 0x02034A20
.syntax divided
