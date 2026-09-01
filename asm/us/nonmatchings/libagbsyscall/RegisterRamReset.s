.syntax unified
	.align 2, 0
	.global RegisterRamReset
	.thumb
	.thumb_func
	.type RegisterRamReset, %function
RegisterRamReset:
	swi #1
	bx lr
.syntax divided
