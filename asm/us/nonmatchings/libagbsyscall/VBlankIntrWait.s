.syntax unified
	.align 2, 0
	.global VBlankIntrWait
	.thumb
	.thumb_func
	.type VBlankIntrWait, %function
VBlankIntrWait: @ 0811800C
	.byte 0x00, 0x22, 0x05, 0xDF, 0x70, 0x47, 0x00, 0x00
.syntax divided
