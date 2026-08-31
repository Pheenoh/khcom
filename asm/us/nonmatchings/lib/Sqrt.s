.syntax unified
	.align 2, 0
	.global Sqrt
	.thumb
	.thumb_func
	.type Sqrt, %function
Sqrt: @ 08118008
	swi #8
	bx lr
	.byte 0x00, 0x22, 0x05, 0xDF, 0x70, 0x47, 0x00, 0x00
.syntax divided
