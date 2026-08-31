.syntax unified
	.align 2, 0
	.global func_080010CC
	.thumb
	.thumb_func
	.type func_080010CC, %function
func_080010CC: @ 080010CC
	ldr r2, _080010D8 @ =0x03007494
	str r0, [r2, #0x00]
	ldr r0, _080010DC @ =0x03007498
	str r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_080010D8: .4byte 0x03007494
_080010DC: .4byte 0x03007498
.syntax divided
