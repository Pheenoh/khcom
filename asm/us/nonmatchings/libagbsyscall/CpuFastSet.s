.syntax unified
	.align 2, 0
	.global CpuFastSet
	.thumb
	.thumb_func
	.type CpuFastSet, %function
CpuFastSet: @ 08117FE4
	swi #12
	bx lr
.syntax divided
