.syntax unified
	.align 2, 0
	.global func_080CA0A8
	.thumb
	.thumb_func
	.type func_080CA0A8, %function
func_080CA0A8: @ 080CA0A8
	ldr r1, _080CA0B0 @ =0x02034DE0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bx lr
_080CA0B0: .4byte 0x02034DE0
	.byte 0x01, 0x49, 0x01, 0x20, 0x08, 0x70, 0x70, 0x47, 0xE1, 0x4D, 0x03, 0x02
.syntax divided
