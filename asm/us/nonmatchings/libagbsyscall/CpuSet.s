.syntax unified
	.align 2, 0
	.global CpuSet
	.thumb
	.thumb_func
	.type CpuSet, %function
CpuSet: @ 08117FE8
	swi #11
	bx lr
.syntax divided
