.syntax unified
	.align 2, 0
	.global func_08076348
	.thumb
	.thumb_func
	.type func_08076348, %function
func_08076348: @ 08076348
	ldr r1, _08076350 @ =0x02034A9C
	movs r0, #0x05
	str r0, [r1, #0x00]
	bx lr
_08076350: .4byte 0x02034A9C
	.byte 0x01, 0x49, 0x08, 0x20, 0x08, 0x60, 0x70, 0x47, 0x9C, 0x4A, 0x03, 0x02
.syntax divided
