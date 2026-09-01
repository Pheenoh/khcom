.syntax unified
	.align 2, 0
	.global SerialIntrDummy
	.thumb
	.thumb_func
	.type SerialIntrDummy, %function
SerialIntrDummy: @ 080005AC
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
