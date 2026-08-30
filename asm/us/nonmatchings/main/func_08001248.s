.syntax unified
	.align 2, 0
	.global func_08001248
	.thumb
	.thumb_func
	.type func_08001248, %function
func_08001248: @ 08001248
	ldr r1, _08001250 @ =0x0300748C
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08001250: .4byte 0x0300748C
.syntax divided
