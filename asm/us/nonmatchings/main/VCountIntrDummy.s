.syntax unified
	.align 2, 0
	.global VCountIntrDummy
	.thumb
	.thumb_func
	.type VCountIntrDummy, %function
VCountIntrDummy: @ 080005A8
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
