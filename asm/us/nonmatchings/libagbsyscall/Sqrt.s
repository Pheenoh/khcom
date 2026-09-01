.syntax unified
	.align 2, 0
	.global Sqrt
	.thumb
	.thumb_func
	.type Sqrt, %function
Sqrt: @ 08118008
	swi #8
	bx lr
.syntax divided
