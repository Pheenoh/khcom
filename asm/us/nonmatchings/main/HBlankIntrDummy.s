.syntax unified
	.align 2, 0
	.global HBlankIntrDummy
	.thumb
	.thumb_func
	.type HBlankIntrDummy, %function
HBlankIntrDummy: @ 080005A4
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
