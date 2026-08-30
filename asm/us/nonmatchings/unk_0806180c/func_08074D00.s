.syntax unified
	.align 2, 0
	.global func_08074D00
	.thumb
	.thumb_func
	.type func_08074D00, %function
func_08074D00: @ 08074D00
	ldr r1, _08074D10 @ =0x02039DC8
	ldr r2, [r1, #0x00]
	ldr r1, [r0, #0x00]
	str r1, [r2, #0x50]
	ldr r0, [r0, #0x04]
	str r0, [r2, #0x54]
	bx lr
	.byte 0x00, 0x00
_08074D10: .4byte 0x02039DC8
.syntax divided
