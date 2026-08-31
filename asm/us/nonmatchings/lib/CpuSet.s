.syntax unified
	.align 2, 0
	.global CpuSet
	.thumb
	.thumb_func
	.type CpuSet, %function
CpuSet: @ 08117FE8
	swi #11
	bx lr
	.byte 0x01, 0xDF, 0x70, 0x47
.syntax divided
