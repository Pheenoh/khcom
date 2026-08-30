.syntax unified
	.align 2, 0
	.global func_08093C04
	.thumb
	.thumb_func
	.type func_08093C04, %function
func_08093C04: @ 08093C04
	ldr r0, _08093C10 @ =0x02034AD0
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _08093C14 @ =0x02034ACC
	strb r1, [r0, #0x00]
	bx lr
_08093C10: .4byte 0x02034AD0
_08093C14: .4byte 0x02034ACC
.syntax divided
